import sys
import os
import json

def main(argv):

  if len(argv) < 1:
    print('please provide files to convert to json')
    sys.exit(1)

  for fileName in argv:

    if not os.path.isfile(fileName):
      print("File path {} does not exist.".format(fileName))
      continue


    # get lines from file
    lines = []
    gotLines = False
    with open(fileName) as file:

      lines = file.readlines()
      gotLines = True
    if not gotLines:
      print('could not get lines from {}'.format(fileName))
      continue


    # get beginning of each section
    startIndexes = []
    for i, line in enumerate(lines):
      if line.startswith("Transform"):
        startIndexes.append(i)
    # use beginnings to make bounds for each section's data
    partitions = []
    for i in range(len(startIndexes)):
      if i < len(startIndexes) - 1:   # this will ignore the opacity transform
        partitions.append((startIndexes[i] + 2, startIndexes[i+1] - 1))


    # split keys into groups using above partitions
    scaleXKeys = {"Name": "Scale X"}
    scaleYKeys = {"Name": "Scale Y"}
    scaleZKeys = {"Name": "Scale Z"}
    positionXKeys = {"Name": "Position X"}
    positionYKeys = {"Name": "Position Y"}
    positionZKeys = {"Name": "Position Z"}
    rotationKeys = {"Name": "Rotation"}

    initScaleKeys(lines[partitions[0][0]:partitions[0][1]], scaleXKeys, scaleYKeys, scaleZKeys)
    #initAnchorPointKeys(lines[partitions[1][0]:partitions[1][1]], keys)
    initPositionKeys(lines[partitions[2][0]:partitions[2][1]], positionXKeys, positionYKeys, positionZKeys)
    initRotationKeys(lines[partitions[3][0]:partitions[3][1]], rotationKeys)

    jsonName = fileName[:-4] + '.json'
    print("writing {} to {}".format(fileName, jsonName))
    writeToJson(jsonName, scaleXKeys, scaleYKeys, scaleZKeys, positionXKeys, positionYKeys, positionZKeys, rotationKeys)
    print("finished")


def initScaleKeys(lines, outXKeys, outYKeys, outZKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outXKeys[float(entries[0]) / 29.97] = (float(entries[1]) / 100.0)
      outYKeys[float(entries[0]) / 29.97] = (float(entries[2]) / 100.0)
      outZKeys[float(entries[0]) / 29.97] = (float(entries[3]) / 100.0)

def initAnchorPointKeys(lines, outKeys):
  #todo
  for line in lines:
    if len(line) > 0:
      entries = line.split()

def initPositionKeys(lines, outXKeys, outYKeys, outZKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outXKeys[float(entries[0]) / 29.97] = (float(entries[1]) / 1920.0 * 360.0) - 90.0
      outYKeys[float(entries[0]) / 29.97] = (float(entries[2]) / 960.0 * 180) - 90
      outZKeys[float(entries[0]) / 29.97] = float(entries[3])

def initRotationKeys(lines, outRotationKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outRotationKeys[float(entries[0]) / 29.97] = float(entries[1])


def writeToJson(jsonFileName, scaleXKeys, scaleYKeys, scaleZKeys, positionXKeys, positionYKeys, positionZKeys, rotationKeys):
  data = []
  data.append(scaleXKeys)
  data.append(scaleYKeys)
  data.append(scaleZKeys)
  data.append(positionXKeys)
  data.append(positionYKeys)
  #data.append(positionZKeys)
  data.append(rotationKeys)

  with open(jsonFileName, 'w') as file:
    json.dump(data, file, indent = 2)

if __name__ == "__main__":
  main(sys.argv[1:])
