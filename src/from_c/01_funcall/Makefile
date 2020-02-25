BASE_PATH := ../../..
MRUBY_CFLAGS := -std=gnu99 -g -O3 -Wall -Wundef -Wdeclaration-after-statement -Werror-implicit-function-declaration -Wwrite-strings -I$(BASE_PATH)/mruby/include
MRUBY_LDFLAGS :=  -L$(BASE_PATH)/mruby/build/host/lib
#MRUBY_LDFLAGS_BEFORE_LIBS := 
MRUBY_LIBS := -lmruby -lm -lreadline -lncurses
MRUBY_LIBMRUBY_PATH := $(BASE_PATH)/mruby/build/host/lib/libmruby.a

all: testapp

testapp: testapp_src.o $(MRUBY_LIBMRUBY_PATH)
	gcc -o testapp testapp_src.o $(MRUBY_LIBMRUBY_PATH) $(MRUBY_LDFLAGS) $(MRUBY_LIBS)

testapp_src.o: testapp_src.c
	gcc -c testapp_src.c $(MRUBY_CFLAGS)

.PHONY: mruby
mruby:
	cd $(BASE_PATH)/mruby && make MRUBY_CONFIG=../build_config.rb

.PHONY: clean
clean:
	rm *.o testapp
