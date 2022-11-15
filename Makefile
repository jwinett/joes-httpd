bin/joes-httpd: src/joes-httpd.c
	mkdir -p bin
	gcc -o bin/joes-httpd src/joes-httpd.c

run: bin/joes-httpd
	@bin/joes-httpd
