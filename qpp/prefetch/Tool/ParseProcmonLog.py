# This script import csv generated by "sysinternals procmon"
# And parse every file ever appeared to regex for later use in prefetch.ini
# Tested on Python 3.9.10

# Command line arguments example:
#    `python ParseProcmonLog.py Logfile.CSV firefox.exe path.txt`

# The result shold look like: "firefox.exe$|\\.ja$|\\.db-wal$|\\.js$|\\.filter$|..."

import sys
import csv
import os

csvFilePath = None
exeName = None
saveTo = None

csvFilePath = "Logfile.CSV"
exeName = "firefox.exe"
saveTo = "path.txt"

# Read command line arguments
if (len(sys.argv) > 3):
    csvFilePath = sys.argv[1]
    exeName = sys.argv[2]
    saveTo = sys.argv[3]

# Create csv reader
csvFile = open(csvFilePath, 'rt', encoding='utf-8-sig')
csvReader = csv.reader(csvFile, delimiter=',')

# Get all column of path
csvPathColumnLines = []
for row in csvReader:
    csvPathColumnLines.append(row[4])
csvPathColumnLinesRemoveDuplicate = set(csvPathColumnLines)
csvPathColumnLinesRemoveDuplicate.remove('')

# Get all file name from path lines
fileNameLines = []
for line in csvPathColumnLinesRemoveDuplicate:
    # Save file extension
    fileNameLines.append(os.path.splitext(os.path.basename(line))[1])
fileNameLinesRemoveDuplicate = set(fileNameLines)
fileNameLinesRemoveDuplicate.remove('')

# Cache array length for later loop
fileNameLinesArrayLength = len(fileNameLinesRemoveDuplicate) - 1

# Open save to file
outputFile = open(saveTo, 'w', encoding='utf-8-sig')

# Save exe itself at the very beginning
outputFile.write(exeName + '$|')

# Write every extension found to output file
for index, line in enumerate(fileNameLinesRemoveDuplicate):
    if index < fileNameLinesArrayLength:
        outputFile.write('\\\\' + line + '$|')
    # The last one don't have pipe symbol
    else:
        outputFile.write('\\\\' + line + '$')
