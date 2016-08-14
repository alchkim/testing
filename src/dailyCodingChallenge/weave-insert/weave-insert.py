from sys import argv
import re

#Takes in a file object, textIn. Reads all lines until a whitespace line and appends it to array1.
#Reads in remaining lines and appends to array2. Returns 2 lists, array1 and array2
def genArrays(textIn):
	array1 = []
	for line in textIn:
		if not re.match(r"\s", line):
			array1.append(line.strip())
		else:
			break

	array2 = []
	for line in textIn:
		array2.append(line.strip())

	return array1, array2

#Takes in a file object. Prints out the second array with elements from the first array weaved
#between each element in the second array. Returns a list with a single string containing the result.
def insWeave(textIn):
	array1, array2 = genArrays(textIn)
	result = []
	string1 = array1[0]
	if len(array2) == 1:
		array2 = list(array2)

	for x in range(len(array2)-1):
		print(array2[x])
		print(string1[x%len(string1)])
		result.append(array2[x])
		result.append(string1[x%len(string1)])
	print(array2[-1])
	result.append(array2[-1])

	return "".join(result)

#Takes in a file object. Prints out the second array with the elements from the first array wrapping
#each element in the second array. Returns a list with a single string containing the result.
def insBracket(textIn):
	array1, array2 = genArrays(textIn)
	result = []
	string2 = array2[0]
	if len(array1) == 1:
		array1 = list(array1[0])

	for x in range(len(array1) if len(array1) > len(string2)//2 else len(string2)//2):
		print(string2[(2*x)%len(string2)],end="")
		print(array1[x%len(array1)],end="")
		print(string2[(2*x+1)%len(string2)])
		result.append(string2[(2*x)%len(string2)])
		result.append(array1[x%len(array1)])
		result.append(string2[(2*x+1)%len(string2)])

	return "".join(result)

#Takes in a file name. Opens the file and performs either insBracket or insWeave based on the first
#line of the file. Prints 'Invalid Style' if first line is invalid.
def weave_insert(filename):
	textIn = open(filename)
	style = textIn.readline().strip()
	if style == 'Bracket':
		insBracket(textIn)
	elif style == 'Weave':
		insWeave(textIn)
	else:
		print('Inavlid style')

if __name__ == '__main__':
	script = argv[0]
	files = argv[1:]
	for txt in files:
		weave_insert(txt)