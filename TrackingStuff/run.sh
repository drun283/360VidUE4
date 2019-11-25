# convert all txt to json
for file in ./*.txt
do
  python3 AdobeKeyFramesToJson.py "$file";
done
echo "done"
# clean up all json
for file in *.json
do
  python3 CleanKeyFrameJson.py "$file";
done
echo "done"
