long
F_1 ( const char * V_1 , ... )
{
static char V_2 [ 1024 ] ;
T_1 args ;
long V_3 , V_4 ;
char * V_5 , * V_6 ;
va_start ( args , V_1 ) ;
V_3 = vsprintf ( V_2 , V_1 , args ) ;
va_end ( args ) ;
V_4 = 0 ;
for ( V_5 = V_2 ; * V_5 ; ++ V_5 ) {
if ( * V_5 == '\n' ) {
++ V_4 ;
}
}
if ( V_4 ) {
for ( V_6 = V_5 + V_4 ; V_5 >= V_2 ; ) {
if ( * V_5 == '\n' ) {
* V_6 -- = '\r' ;
}
* V_6 -- = * V_5 -- ;
}
}
F_2 ( V_2 , V_4 + V_3 ) ;
return V_3 ;
}
