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
    scaleXKeys = {}
    scaleYKeys = {}
    scaleZKeys = {}
    positionXKeys = {}
    positionYKeys = {}
    positionZKeys = {}
    rotationKeys = {}

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
      outXKeys[entries[0]] = entries[1]
      outYKeys[entries[0]] = entries[2]
      outZKeys[entries[0]] = entries[3]

def initAnchorPointKeys(lines, outKeys):
  #todo
  for line in lines:
    if len(line) > 0:
      entries = line.split() 
  
def initPositionKeys(lines, outXKeys, outYKeys, outZKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outXKeys[entries[0]] = entries[1]
      outYKeys[entries[0]] = entries[2]
      outZKeys[entries[0]] = entries[3]

def initRotationKeys(lines, outRotationKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outRotationKeys[entries[0]] = entries[1]
  

def writeToJson(jsonFileName, scaleXKeys, scaleYKeys, scaleZKeys, positionXKeys, positionYKeys, positionZKeys, rotationKeys):

  name = jsonFileName[:-5] + "scaleX" + ".json"
  with open(name, 'w') as file:
    json.dump(scaleXKeys, file, indent = 2)

  name = jsonFileName[:-5] + "scaleY" + ".json"
  with open(name, 'w') as file:
    json.dump(scaleYKeys, file, indent = 2)

  name = jsonFileName[:-5] + "scaleZ" + ".json"
  with open(name, 'w') as file:
    json.dump(scaleZKeys, file, indent = 2)

  name = jsonFileName[:-5] + "positionX" + ".json"
  with open(name, 'w') as file:
    json.dump(positionXKeys, file, indent = 2)

  name = jsonFileName[:-5] + "positionY" + ".json"
  with open(name, 'w') as file:
    json.dump(positionYKeys, file, indent = 2)

  name = jsonFileName[:-5] + "positionZ" + ".json"
  with open(name, 'w') as file:
    json.dump(positionZKeys, file, indent = 2) 

  name = jsonFileName[:-5] + "rotation" + ".json"
  with open(name, 'w') as file:
    json.dump(rotationKeys, file, indent = 2)


if __name__ == "__main__":
  main(sys.argv[1:])
