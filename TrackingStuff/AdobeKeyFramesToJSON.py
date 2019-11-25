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

        scale_lines = []
        position_lines = []
        rotation_lines = []
        partitionLines(lines, scale_lines, position_lines, rotation_lines)

        scale_x_keys = {"Name": "Scale X"}
        scale_y_keys = {"Name": "Scale Y"}
        position_x_keys = {"Name": "Position X"}
        position_y_keys = {"Name": "Position Y"}
        rotation_keys = {"Name": "Rotation"}
        initScaleKeys(scale_lines, scale_x_keys, scale_y_keys)
        initPositionKeys(position_lines, position_x_keys, position_y_keys)
        initRotationKeys(rotation_lines, rotation_keys)

        json_name = convertFileName(file_name)
        print("writing {} to {}".format(file_name, json_name))
        dumpJsonToFile(json_name, scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys)



def partitionLines(lines, out_scale_lines, out_position_lines, out_rotation_lines):
    """ splits lines into partitions for scale, position, and rotation """
    # todo make this more efficient
    scale_start = -1
    scale_end = -1
    position_start = -1
    position_end = -1
    rotation_start = -1
    rotation_end = -1

    i = 0
    size = len(lines)
    while i < size:
        line = lines[i]
        if "Scale" in line:
            scale_start = i + 2
            while not lines[i].isspace():
                i += 1
            scale_end = i
        elif "Position" in line:
            position_start = i + 2
            while not lines[i].isspace():
                i += 1
            position_end = i
        elif "Rotation" in line:
            rotation_start = i + 2
            while not lines[i].isspace():
                i += 1
            rotation_end = i
        i += 1
    out_scale_lines.extend(lines[scale_start:scale_end])
    out_position_lines.extend(lines[position_start:position_end])
    out_rotation_lines.extend(lines[rotation_start:rotation_end])


def initScaleKeys(lines, out_x_keys, out_y_keys):

    line = lines[0]
    entries = line.split()
    start_time = secondsFromFrame(int(entries[0]) - 1)
    out_x_keys[0] = 0
    out_y_keys[0] = 0
    out_x_keys[start_time] = 0
    out_y_keys[start_time] = 0

    for line in lines:
        if len(line) > 0:
            entries = line.split()

            seconds = secondsFromFrame(int(entries[0]))
            x = convertScale(float(entries[1]))
            y = convertScale(float(entries[2]))

            out_x_keys[seconds] = x
            out_y_keys[seconds] = y


def initPositionKeys(lines, out_x_keys, out_y_keys):

    line = lines[0]
    entries = line.split()
    initial_x = widthToDeg(float(entries[1]))
    initial_y = heightToDeg(float(entries[2]))
    out_x_keys[0] = initial_x
    out_y_keys[0] = initial_y

    for line in lines:
        if len(line) > 0:
            entries = line.split()

            seconds = secondsFromFrame(int(entries[0]))
            x = widthToDeg(float(entries[1]))
            y = heightToDeg(float(entries[2]))

            out_x_keys[seconds] = x
            out_y_keys[seconds] = y


def initRotationKeys(lines, out_keys):

    line = lines[0]
    entries = line.split()
    initial_rot = float(entries[1])
    out_keys[0] = initial_rot

    for line in lines:
        if len(line) > 0:
            entries = line.split()

            seconds = secondsFromFrame(int(entries[0]))
            rot = float(entries[1])

            out_keys[seconds] = rot


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
