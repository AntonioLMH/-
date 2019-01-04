test : listIteratorInt.o testListIteratorInt.o
	gcc -o murui_test.out listIteratorInt.o testListIteratorInt.o -lcheck

leak : listIteratorInt.o testListIteratorIntLeak.o
	gcc -o murui_leck.out listIteratorInt.o testListIteratorIntLeak.o

testListIteratorInt.o: testListIteratorInt.c

testListIteratorIntLeak.o: testListIteratorIntLeak.c

listIteratorInt.o : listIteratorInt.c  listIteratorInt.h

clean:
	rm *.o test