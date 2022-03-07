CC = cc

compile: src/main.c
	mkdir -p build
	$(CC) src/main.c -o coracoralinda
	mv coracoralinda build/

install: build/coracoralinda
	mkdir -p $(DESTDIR)/usr/share/coracoralinda
	cp src/phrases.txt $(DESTDIR)/usr/share/coracoralinda
	cp build/coracoralinda $(DESTDIR)/usr/bin

remove:
	rm -r $(DESTDIR)/usr/share/coracoralinda
	rm $(DESTDIR)/usr/bin/coracoralinda

clean:
	rm -r build
