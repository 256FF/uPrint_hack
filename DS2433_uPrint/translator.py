import binascii
import argparse
parser = argparse.ArgumentParser(description='Translate .bin files into hex')

parser.add_argument("--inputfile", action="store")
parser.add_argument("-s", "--save", action="store_true")
parser.add_argument("--outputfile", action="store")

args = parser.parse_args()

filename = args.inputfile

with open(filename, 'rb') as f:
    content = f.read()
string = binascii.hexlify(content)

length = len (string)

i = 0
k = 0

while k < length:
    string = string[:(i*6)] + ", 0x" + string[(i*6):]
    i = i + 1
    k = i * 2
	
	
print length, "\n"
print string

if args.save:
    with open(args.outputfile, "w") as text_file:
        text_file.write(string)