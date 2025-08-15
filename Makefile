CC = gcc
CFLAGS = -Wall

# object files
OBJS = main.o product.o admin.o customer.o

# final executable
inventory: $(OBJS)
	$(CC) $(CFLAGS) -o inventory $(OBJS)

main.o: main.c product.h admin.h customer.h
product.o: product.c product.h
admin.o: admin.c admin.h product.h
customer.o: customer.c customer.h product.h

clean:
	rm -f *.o inventory