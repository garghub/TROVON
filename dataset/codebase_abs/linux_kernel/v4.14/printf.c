void T_1 F_1 ( const char * V_1 , unsigned int V_2 )
{
unsigned int V_3 ;
unsigned long V_4 ;
char * V_5 ;
V_5 = V_6 ;
F_2 ( & V_7 , V_4 ) ;
V_3 = 0 ;
while ( V_2 -- != 0 ) {
char V_8 = * V_1 ++ ;
if ( V_8 == '\n' ) {
* V_5 ++ = '\r' ;
V_3 ++ ;
}
* V_5 ++ = V_8 ;
V_3 ++ ;
if ( V_3 >= V_9 - 1 ) {
F_3 ( V_6 , V_3 ) ;
V_5 = V_6 ;
V_3 = 0 ;
}
}
if ( V_3 )
F_3 ( V_6 , V_3 ) ;
F_4 ( & V_7 , V_4 ) ;
}
void T_1 F_5 ( const char * V_10 , ... )
{
T_2 args ;
int V_11 ;
va_start ( args , V_10 ) ;
V_11 = F_6 ( V_12 , sizeof( V_12 ) , V_10 , args ) ;
va_end ( args ) ;
F_1 ( V_12 , V_11 ) ;
}
