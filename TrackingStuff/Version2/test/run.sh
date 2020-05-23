# convert all txt to json
for file in ./*.txt
do
  python AdobeKeyFramesToJsonV2.py "$file";
done
echo "done"
