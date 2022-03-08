CC = gcc
CC_ARGS = -std=c99 -pedantic -W -Wall -Werror -c

ifdef DESTDIR
INSTALLDIR != mkdir -p $(DESTDIR); cd $(DESTDIR); pwd
endif

.PHONY: all install remove clean

all: build/coracoralinda

install: all fortunes/*/*
	@mkdir -p $(INSTALLDIR)/usr/bin
	@mkdir -p $(INSTALLDIR)/usr/share/coracoralinda
	@cp build/coracoralinda $(INSTALLDIR)/usr/bin
	@cp -r fortunes/* $(INSTALLDIR)/usr/share/coracoralinda

remove:
	@rm -rf $(INSTALLDIR)/usr/bin/coracoralinda
	@rm -rf $(INSTALLDIR)/usr/share/coracoralinda

build/coracoralinda: build/coracoralinda.o
	@$(CC) build/coracoralinda.o -o build/coracoralinda

build/coracoralinda.o: src/coracoralinda.c
	@$(CC) $(CC_ARGS) -DFORTUNE_PATH=\"$(INSTALLDIR)/usr/share/coracoralinda/en/fortunes.txt\" src/coracoralinda.c -o build/coracoralinda.o
