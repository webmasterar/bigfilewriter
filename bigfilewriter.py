#license MIT Ahmad Retha 2016

import time
import sys

if len(sys.argv) != 3:
    print "Invalid arguments!\nUsage: python bigfilewriter.py file_name size_in_mb"
    sys.exit(1)

fsize = int(sys.argv[2])
fname = str(sys.argv[1])

start = time.clock()

oneMB = '1' * 1024 * 1024

try:
    f = open(fname, 'w')
    for i in xrange(fsize):
        f.write(oneMB)
        print "\rWrote %dMB to %s " % (i + 1, fname),
    f.close()
except Exception as e:
    print e
    sys.exit(1)

finish = time.clock()

print "\nFinished in %.2fs" % (finish - start)
