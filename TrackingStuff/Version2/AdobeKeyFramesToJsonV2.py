import collections
import sys
import os
import json


def main(argv):
    if len(argv) < 1:
        print('please provide files to convert to json')
        sys.exit(1)

    for file_name in argv:

        if not os.path.isfile(file_name):
            print("File path {} does not exist.".format(file_name))
            continue

        with open(file_name) as file:
            lines = file.readlines()

        point_one_lines = []
        point_two_lines = []
        partition_lines(lines, point_one_lines, point_two_lines)
        point_keys = read_in_keys(point_one_lines, point_two_lines)

        scale_x_keys = {"Name": "Scale X"}
        scale_y_keys = {"Name": "Scale Y"}
        position_x_keys = {"Name": "Position X"}
        position_y_keys = {"Name": "Position Y"}
        rotation_keys = {"Name": "Rotation"}
        init_keys(point_keys, position_x_keys, position_y_keys, scale_x_keys, scale_y_keys, rotation_keys)

		# clean_up_keys(position_x_keys, position_y_keys, scale_x_keys, scale_y_keys, rotation_keys)

        json_name = convert_filename(file_name)
        print("writing {} to {}".format(file_name, json_name))
        dump_json_to_file(json_name, scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys)


def partition_lines(lines, out_point_one_lines, out_point_two_lines):
    """ splits lines into partitions for scale, position, and rotation """
    # todo make this more efficient
    point_one_start = -1
    point_one_end = -1
    point_two_start = -1
    point_two_end = -1

    i = 0
    size = len(lines)
    while i < size:
        line = lines[i]
        if "Point #1" in line:
            point_one_start = i + 2
            while not lines[i].isspace():
                i += 1
            point_one_end = i
        elif "Point #2" in line:
            point_two_start = i + 2
            while not lines[i].isspace():
                i += 1
            point_two_end = i
        i += 1

    out_point_one_lines.extend(lines[point_one_start:point_one_end])
    out_point_two_lines.extend(lines[point_two_start:point_two_end])


def read_in_keys(point_one_lines, point_two_lines):
    keys = collections.defaultdict(dict)
    for line in point_one_lines:
        if len(line) > 0:
            entries = line.split()

            seconds = seconds_from_frame(int(entries[0]))
            x = float(entries[1])
            y = abs(float(entries[2]) - 960)

            keys[seconds]['x1'] = x
            keys[seconds]['y1'] = y

    for line in point_two_lines:
        if len(line) > 0:
            entries = line.split()

            seconds = seconds_from_frame(int(entries[0]))
            x = float(entries[1])
            y = abs(float(entries[2]) - 960)

            keys[seconds]['x2'] = x
            keys[seconds]['y2'] = y

    return keys


def init_keys(point_keys, out_position_x_keys, out_position_y_keys, out_scale_x_keys, out_scale_y_keys, out_rotation_keys):
    # todo init keys for seconds 0 and one frame before start of keys (see clean_keys for example)
    for seconds, coords in point_keys.items():
        px, py = position_from_points(coords)
        sx, sy = scale_from_points(coords)
        r = rotation_from_points(coords)

        out_position_x_keys[seconds] = px
        out_position_y_keys[seconds] = py
        out_scale_x_keys[seconds] = sx
        out_scale_y_keys[seconds] = sy
        out_rotation_keys[seconds] = r


def clean_up_keys(position_x_keys, position_y_keys, scale_x_keys, scale_y_keys, rotation_keys):
	position_tol = 0.01
	scale_tol = 0.01
	rotation_tol = 0.01

	clean_keys(position_x_keys, position_tol)
	clean_keys(position_y_keys, position_tol)
	clean_keys(scale_x_keys, scale_tol)
	clean_keys(scale_y_keys, scale_tol)
	clean_keys(rotation_keys, rotation_tol)


def clean_keys(keys, tol):
	# todo write clean_keys
	pass
	to_delete =  []
	prev = None

	items_iter = iter(keys.items())
	# todo this might not even "compile"
	first = items_iter.next()
	prev = first[1]

	for time, value in items_iter:
		if (value < prev + tol) and (value > prev - tol):
			to_delete.append(time)
		else:
			prev = value


	for time in to_delete:
		del keys[time]


def position_from_points(coords):
    x = (coords['x1'] + coords['x2']) / 2.0
    y = (coords['y1'] + coords['y2']) / 2.0
    x = deg_from_width(x)
    y = deg_from_height(y)
    return x, y


def scale_from_points(coords):
    # todo write scale_from_points
    # need to keep track of initial scale
    return 1, 1


def rotation_from_points(coords):
    # todo write rotation_from_points
    # need to keep track of initial rotation
    return 0


def convert_scale(scale):
    """ convert from 0 - 100 to 0 - 1 """
    return scale / 100


def deg_from_width(width):
    """ divide by canvas width and multiply by 360 degrees and shift to -180 to 180 """
    return ((width / 1920.0) * 360.0) - 180


def deg_from_height(height):
    """ divide by canvas height and multiply by 180 degrees and shift to -90 to 90"""
    return ((height / 960) * 180) - 90


def seconds_from_frame(frame):
    """ divide by frame rate """
    return frame / 29.97


def convert_filename(file_name):
    """ changes '.txt' to '.json '"""
    return file_name[:-4] + '.json'


def dump_json_to_file(file_name, scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys):
    data = [scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys]

    with open(file_name, 'w') as file:
        json.dump(data, file, indent=2)


if __name__ == "__main__":
    main(sys.argv[1:])
