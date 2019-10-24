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
    keys = {
      'scale' : {},
      'position': {},
      'rotation': {},
    }
    initScaleKeys(lines[partitions[0][0]:partitions[0][1]], keys)
    #initAnchorPointKeys(lines[partitions[1][0]:partitions[1][1]], keys)
    initPositionKeys(lines[partitions[2][0]:partitions[2][1]], keys)
    initRotationKeys(lines[partitions[3][0]:partitions[3][1]], keys)

    jsonName = fileName[:-4] + '.json'
    print("writing {} to {}".format(fileName, jsonName))
    writeToJson(jsonName, keys)
    print("finished")
    
      
def initScaleKeys(lines, outKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outKeys['scale'][entries[0]] = {'x': entries[1], 'y': entries[2], 'z': entries[3]}

def initAnchorPointKeys(lines, outKeys):
  #todo
  for line in lines:
    if len(line) > 0:
      entries = line.split() 
  
def initPositionKeys(lines, outKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outKeys['position'][entries[0]] = {'x': entries[1], 'y': entries[2], 'z': entries[3]}

def initRotationKeys(lines, outKeys):
  for line in lines:
    if len(line) > 0:
      entries = line.split()
      outKeys['rotation'][entries[0]] = {'deg': entries[1]}
  

def writeToJson(jsonFileName,keys):
  with open(jsonFileName, 'w') as jsonFile:
    json.dump(keys, jsonFile, indent = 2)


if __name__ == "__main__":
  main(sys.argv[1:])
