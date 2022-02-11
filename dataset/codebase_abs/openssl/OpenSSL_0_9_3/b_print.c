int F_1 ( T_1 * V_1 , ... )
{
T_2 args ;
char * V_2 ;
int V_3 ;
T_3 char V_4 [ 1024 * 2 ] ;
va_start ( args , V_1 ) ;
V_2 = va_arg ( args , char * ) ;
V_4 [ 0 ] = '\0' ;
vsprintf ( V_4 , V_2 , args ) ;
V_3 = F_2 ( V_1 , V_4 , strlen ( V_4 ) ) ;
va_end ( args ) ;
return ( V_3 ) ;
}
