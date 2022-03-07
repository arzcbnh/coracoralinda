CC = gcc
CC_ARGS = -std=c99 -pedantic -W -Wall -Werror

ifdef DESTDIR
INSTALLDIR != cd $(DESTDIR); pwd
endif

compile: src/main.c
	mkdir -p build
	$(CC) $(CC_ARGS) -DFORTUNE_PATH=\"$(INSTALLDIR)/usr/share/coracoralinda/en/fortunes.txt\" src/main.c -o build/coracoralinda
	chmod 755 build/coracoralinda

install: compile fortunes/*/*
	mkdir -p $(INSTALLDIR)/usr/bin
	mkdir -p $(INSTALLDIR)/usr/share/coracoralinda
	cp build/coracoralinda $(INSTALLDIR)/usr/bin
	cp -r fortunes/* $(INSTALLDIR)/usr/share/coracoralinda

remove:
	rm $(INSTALLDIR)/usr/bin/coracoralinda
	rm -r $(INSTALLDIR)/usr/share/coracoralinda

clean:
	rm -r build
