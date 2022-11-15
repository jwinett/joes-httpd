/*
joes-httpd Joe's HTTP Document Server Isn't Apache, Baby (JHSIAB)
Copyright (c)2022 Joe Winett @abighairyspider 

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
like spamtrap+JHTP32d23@abighairy.com
*/
#include <stdio.h>
#include <stdlib.h>

char *_pstrUsage = "\n"
    "Joe's HTTP Document Server Isn't Apache, Baby (JHSIAB)\n"
    "Copyright (c)2022 by Joe Winett @abighairyspider - GNU Affero General Public License\n"
    "\n"    
    "%s %s\n"
    "\n";

char *_pstrCommandPath = "joes-httpd";
char *_pstrVerb = "[help|run]";

void HelpUsageError( char *ErrorString ) {
    
    printf( _pstrUsage, _pstrCommandPath, _pstrVerb );    

    if( ErrorString && *ErrorString ) {
        printf( "** %s\n\n", ErrorString );                
    }
    

}

    

int main( int argc, char *argv[] ) {

    if( argc <= 0 ) {
        char achBuff[16];
        snprintf( achBuff, sizeof(achBuff), "bad argc is %d", argc );
        HelpUsageError(achBuff);
        return -1;
    }

    _pstrCommandPath = argv[0];

    if( argc == 1 ) {
        HelpUsageError("nothing to do (no command specified)");
        return -1;
    }

    _pstrVerb = argv[1];

    HelpUsageError("unknown command");


    
    

    return 0;
}

