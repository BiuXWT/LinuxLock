cd ./CCond

CCond.o:
	gcc CCond.cpp -lpthread -c

cd ../CMutex

CMutex:
	gcc CMutex.cpp -lpthread -c

cd ../CSem

CSem:
	gcc CSem.cpp -lpthread -c

cd ../CRWlock

CRWlock:
	gcc CRWlock.cpp -lpthread -c

cd ..

