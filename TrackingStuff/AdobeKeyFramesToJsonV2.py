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
        partitionLines(lines, point_one_lines, point_two_lines)

        point_keys = readInKeys(point_one_lines, point_two_lines)

        scale_x_keys = {"Name": "Scale X"}
        scale_y_keys = {"Name": "Scale Y"}
        position_x_keys = {"Name": "Position X"}
        position_y_keys = {"Name": "Position Y"}
        rotation_keys = {"Name": "Rotation"}
        initKeys(point_keys, position_x_keys, position_y_keys, scale_x_keys, scale_y_keys, rotation_keys)

        json_name = convertFileName(file_name)
        print("writing {} to {}".format(file_name, json_name))
        dumpJsonToFile(json_name, scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys)


def partitionLines(lines, out_point_one_lines, out_point_two_lines):
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


def readInKeys(point_one_lines, point_two_lines):
    keys = collections.defaultdict(dict)

    for line in point_one_lines:
        if len(line) > 0:
            entries = line.split()

            seconds = secondsFromFrame(int(entries[0]))
            x = float(entries[1])
            y = abs(float(entries[2]) - 960)

            keys[seconds]['x1'] = x
            keys[seconds]['y1'] = y

    for line in point_two_lines:
        if len(line) > 0:
            entries = line.split()

            seconds = secondsFromFrame(int(entries[0]))
            x = float(entries[1])
            y = abs(float(entries[2]) - 960)

            keys[seconds]['x2'] = x
            keys[seconds]['y2'] = y

    return keys


def initKeys(point_keys, out_position_x_keys, out_position_y_keys, out_scale_x_keys, out_scale_y_keys, out_rotation_keys):
    # todo init keys for seconds 0 and one frame before start of keys
    for seconds, coords in point_keys.items():
        px, py = positionFromPoints(coords)
        sx, sy = scaleFromPoints(coords)
        r = rotationFromPoints(coords)

        out_position_x_keys[seconds] = px
        out_position_y_keys[seconds] = py
        out_scale_x_keys[seconds] = sx
        out_scale_y_keys[seconds] = sy
        out_rotation_keys[seconds] = r



    ''' 
    # old position init
    line = lines[0]
    entries = line.split()
    initial_x = widthToDeg(float(entries[1]))
    initial_y = heightToDeg(float(entries[2]))
    out_x_keys[0] = initial_x
    out_y_keys[0] = initial_y
    '''
    ''' 
    # old scale init
    line = lines[0]
    entries = line.split()
    start_time = secondsFromFrame(int(entries[0]) - 1)
    out_x_keys[0] = 0
    out_y_keys[0] = 0
    out_x_keys[start_time] = 0
    out_y_keys[start_time] = 0
    '''
    '''
    # old rot init
    line = lines[0]
    entries = line.split()
    initial_rot = float(entries[1])
    out_keys[0] = initial_rot
    '''


def positionFromPoints(coords):
    x = (coords['x1'] + coords['x2']) / 2.0
    y = (coords['y1'] + coords['y2']) / 2.0
    x = widthToDeg(x)
    y = heightToDeg(y)
    return x, y


def scaleFromPoints(coords):
    # todo write scaleFromPoints
    # need to keep track of initial scale
    return 1, 1


def rotationFromPoints(coords):
    # todo write rotationFromPoints
    # need to keep track of initial rotation
    return 0


def convertScale(scale):
    """ convert from 0 - 100 to 0 - 1 """
    return scale / 100


def widthToDeg(width):
    """ divide by canvas width and multiply by 360 degrees and shift to -180 to 180 """
    return ((width / 1920.0) * 360.0) - 180


def heightToDeg(height):
    """ divide by canvas height and multiply by 180 degrees and shift to -90 to 90"""
    return ((height / 960) * 180) - 90


def secondsFromFrame(frame):
    """ divide by frame rate """
    return frame / 29.97


def convertFileName(file_name):
    """ changes '.txt' to '.json '"""
    return file_name[:-4] + '.json'


def dumpJsonToFile(file_name, scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys):
    data = [scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys]

    with open(file_name, 'w') as file:
        json.dump(data, file, indent=2)


if __name__ == "__main__":
    main(sys.argv[1:])
