PREFIX = /usr/local
install:
	install -m 755 bin/client_dynamic $(PREFIX)/bin/client
	install -d $(PREFIX)/man/man3
	install -m 644 man/man3/*.1 $(PREFIX)/man/man3/