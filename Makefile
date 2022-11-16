# Hi, this is my Makefile
# This sucker is public domain, no license required, no credit necessary 
# You're welcome
bin/joes-httpd: bin src/joes-httpd.c	
	gcc -o bin/joes-httpd src/joes-httpd.c	

bin:
	mkdir -p bin

run: bin/joes-httpd
	bin/joes-httpd run

help: bin/joes-httpd
	bin/joes-httpd help

fail: bin/joes-httpd
	bin/joes-httpd fail

