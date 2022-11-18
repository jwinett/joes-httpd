/*
joes-httpd Joe's HTTP Document Server Isn't Apache, Baby
Cheater Cheater Edition (JHSIAB CCE) 

Copyright (c)2022 Joe Winett @abighairyspider of TeddyBear.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.

# Is this still a comment in c?

Pro-tip: Don't email me at these addresses or you're a spammer bot.

My honey trap email address is spamtrap+joeshttpd@abighairy.com

Use a unique ID on your spam traps for total identification domination,
like spamtrap+JHThsd23@abighairy.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Declare, Instantiate, and Initialize a pointer to a string
char *_pstrTitleHeader =     
    "Joe's HTTP Document Server Isn't Apache, Baby | Cheater Cheater Edition (JHSIAB CCE)\n" 
    "Copyright (c)2022 by Joe Winett @abighairyspider - GNU Affero General Public License\n"    
    ; 

    /*
    No need for an operator to stick the string together because
    c compilers continue adding string literals together until the
    end of statement character, which is a semicolon.

    So:

    char *Name = "Joe";  
    
    char *     a pointer (*) that points at a character (char)
    Name       a symbol called Name representing where to store the (char *) value
    =          the assignment operator
    "Joe"      a string literal
    ;          a semicolon is the end-of-statement marker

    Means in total:

    1. Save space in my program memory for a string containing 3 visible characters 'J', 'o', and 'e' 
    2. Put the location of the first byte of memory, where the 'J' is stored, into a variable called Name

    So, Name points at memory containing "Joe\0" (a zero byte will end up on the end, more later)

    char *Name = "Joe" "Winett";  

    Name is then "JoeWinett" because when a second string literal "Winett" is encountered before 
    the semicolon it is added to the string already started.  "Joe" and "Winett" are contatonated
    into one string of characters which is stored into memory, then the location of the first 
    character is stored into _Name_ -- then _Name_ is said to be a _character pointer_ that points
    at the _J_ in Joe Winett.    A string in the c language is stored with a _NULL byte_ at the end.

    A _NULL_ is the value 0.  In the case of a string of ASCII 1-byte characters, then the zero value
    is literally a byte of 8-bits that are all zero.  So, "Joe Winett" is actually stored as:

    'J', 'o', 'e', ' ', 'W', 'i', 'n', 'e', 't', 't', '\0'

    where I'm representing characters as character literals, in each enclosed in a pair of single quote marks.

    '\0' represents a _NULL_ character of value 0
    '\n' represents a _new line_ character value 10    
    '\\' represents a _backslash_ character value whatever

    If you want to include a backslash character, it must be "escaped" by itself, '\\'
    because the backslash itself marks the next character is being "escaped"

    Where were we?

    2022-11-16 Happy Birthday, Kristi Winett -- 55 now, eh?  Nice.
    */
   


char *_pstrCommandPath = "joes-httpd";

char *_apstrVerbs[] = {
    "help",
    "run"    
}; 

char *_pstrVerb = "";


/**
 * Display Title Header
*/
void PrintTitleHeader() {
    // build a string and print it to the file stream stdout:            
    printf( "\n%s\n", _pstrTitleHeader ); // new line, header text, new line
}

/** 
 * Display Usage and/or Error Message
*/
void HelpUsageError( char *ErrorString ) {
    
    PrintTitleHeader();

    // build a string and print it to the file stream stdout:            
    printf( "%s ", _pstrCommandPath ); // command path, space    
    
    // output list of available command verbs
    for( int i=0; i<sizeof(_apstrVerbs)/sizeof(char *); i=i+1 ) {  // loop through the list of commands (verbs)
        char sep = ( i == 0 ) ? '[' : '|';
        printf( "%c%s", sep, _apstrVerbs[i] ); // print separator character then the verb string
    }

    printf( "]\n\n"); // put (print) right square bracket, new line, new line (skips a line)


    if( ErrorString && *ErrorString ) {
        printf( "** %s\n\n", ErrorString );                
    }
    

}

bool IsValidCommand( char *pstrParameter ) {
    
    for( int i=0; i<sizeof(_apstrVerbs)/sizeof(char *); i=i+1 ) {        
        if( strcmp( _apstrVerbs[i], pstrParameter ) == 0 ) {
            return true;
        }
    }    
    return false;
}



int main( int argc, char *argv[] ) {

    if( argc <= 0 ) {
        char achBuff[16];
        snprintf( achBuff, sizeof(achBuff), "bad argc is %d", argc );
        HelpUsageError(achBuff);
        return -1;
    }

    _pstrCommandPath = argv[0];
    _pstrVerb = argv[1];

    if( IsValidCommand(_pstrVerb) == false ) {  
        char achBuff[128];
        snprintf( achBuff, sizeof(achBuff), "unknown command [%s]", _pstrVerb );
        HelpUsageError(achBuff);
        return -1; // exit with an error value -1
    }
    
    
    // TODO: Actually do something, but for now just
    // display the Usage, no error

    PrintTitleHeader();

    puts( "//cheater cheater mode activated\nsystem( python3 -m http.server 9000 );\n" );

    

    return system( "python3 -m http.server 9000" );

    /* 0 is SUCCESS or NO ERROR in UNIX, XENIX, Linux, (i.e., POSIX) command line terminal processing:
    Dr. Bourne's shell (/bin/sh) or GNU's Bourne Again shell (/bin/bash)
    */
    
}

