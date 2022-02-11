T_1 F_1 ( char * V_1 , T_2 V_2 , const char * V_3 , ... )
{
T_1 V_4 ;
T_3 args ;
va_start ( args , V_3 ) ;
V_4 = vsnprintf ( V_1 , V_2 , V_3 , args ) ;
va_end ( args ) ;
if ( V_1 && ( V_2 > 0 ) )
{
V_1 [ V_2 - 1 ] = '\0' ;
}
return V_4 ;
}
