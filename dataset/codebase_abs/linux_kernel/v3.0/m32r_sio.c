static int puts ( const char * V_1 )
{
char V_2 ;
while ( ( V_2 = * V_1 ++ ) ) putc ( V_2 ) ;
return 0 ;
}
static void putc ( char V_2 )
{
while ( ( * V_3 & 0x3 ) != 0x3 )
F_1 () ;
if ( V_2 == '\n' ) {
* V_4 = '\r' ;
while ( ( * V_3 & 0x3 ) != 0x3 )
F_1 () ;
}
* V_4 = V_2 ;
}
static void putc ( char V_2 )
{
while ( ( * V_5 & 0x1 ) == 0 )
F_1 () ;
if ( V_2 == '\n' ) {
* V_6 = '\r' ;
while ( ( * V_5 & 0x1 ) == 0 )
F_1 () ;
}
* V_6 = V_2 ;
}
