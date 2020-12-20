all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/dwa/A dane/dwa/b
	bin/gauss dane/piec/A dane/piec/b
testZera: all
	bin/gauss dane/testZero/A dane/testZero/b
testWymiary: all 
	bin/gauss dane/zleWymiary/A dane/zleWymiary/b
testFormat: all
	bin/gauss dane/zlyFormat/A dane/zlyFormat/b
