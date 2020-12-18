# MergesortJuxtaposition
Determines commonly contained elements between two input files using a mergesort/juxtaposition algorithm.

PROJECT DETAILS:

The program should accept four command line arguments. Argument 1 is either “i” or “s”, arguments 2 and 3 are the names of the input files.

The program will read streams of data from the input files until end-of-file. If argument 1 is “i” then the data will be integer values, but if argument 1 is “s” the data will be strings of visible characters separated by white space (blanks, tabs, newlines).

Your program should sort the data from both files using an O(n lg n) sort function (mergesort or quicksort).

Your program will write to the standard out all the data (integers or strings) that appear in both of the input files. The data in each output stream should be sorted in ascending order, either numerically for integers or lexicographically for strings. Write one value per line, and discard any duplicate values.

There will be no more than 20,000 data items in each file.

Your program should behave as shown in the following two examples:

./p2 i in1.txt in2.txt

in1.txt	in2.txt	standard output
17 63
-25 409
63 -8 0
-321 17	330 -4 -8
96 25
25 17 -4	-8
17
./p2 s in3.txt in4.txt

in3.txt	in4.txt	standard output
zebra bird dog
moose fish
fish cat bird	cat pig
snake cow
bird
pig dog lion
horse cat	bird
cat
dog
Please carefully read and follow all the following requirements:

You must use C++ streams for all I/O.
Do not use vectors.
Format your output as described above.
