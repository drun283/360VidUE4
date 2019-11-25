import sys
import os
import json


def main(argv):
    if len(argv) < 1:
        print('please provide files to clean up')
        sys.exit(1)

    for file_name in argv:

        if not os.path.isfile(file_name):
            print("File path {} does not exist.".format(file_name))
            continue

        # with open(file_name) as file:
            # lines = file.readlines()

    print("don't forget to write the clean up script")


def dumpJsonToFile(file_name, scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys):
    data = [scale_x_keys, scale_y_keys, position_x_keys, position_y_keys, rotation_keys]

    with open(file_name, 'w') as file:
        json.dump(data, file, indent=2)


if __name__ == "__main__":
    main(sys.argv[1:])
