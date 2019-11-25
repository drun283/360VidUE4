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

        with open(file_name) as file:
            data = json.load(file)

        for keys in data:
            print(keys)
            name = keys['Name']
            if 'Scale' in name:
                cleanScaleKeys(keys)
            elif 'Position' in name:
                cleanPositionKeys(keys)
            elif 'Rotation' in name:
                cleanRotationKeys(keys)

        dumpJsonToFile(file_name, data)


# TODO set tols
def cleanScaleKeys(keys):
    tol = 0
    cleanKeys(keys, tol)


def cleanPositionKeys(keys):
    tol = 0
    cleanKeys(keys, tol)


def cleanRotationKeys(keys):
    tol = 0
    cleanKeys(keys, tol)


def cleanKeys(keys, tol):
    itr = iter(keys)
    keys_to_remove = []
    while True:
        try:
            element = next(itr)
            # todo write function
            # check if next element is in tol
            # if yes, search for more and add all middle keys to remove list

        except StopIteration:
            break

    for key in keys_to_remove:
        if key in keys:
            del keys[key]


def dumpJsonToFile(file_name, data):
    with open(file_name, 'w') as file:
        json.dump(data, file, indent=2)


if __name__ == "__main__":
    main(sys.argv[1:])
