void
F_1 ( void (* F_2)( const char * , T_1 ) ,
void (* F_3)( const char * , T_1 ) )
{
V_1 = F_2 ;
V_2 = F_3 ;
}
void
F_4 ( const char * V_3 , ... )
{
T_1 V_4 ;
va_start ( V_4 , V_3 ) ;
V_1 ( V_3 , V_4 ) ;
va_end ( V_4 ) ;
}
void
F_5 ( const char * V_3 , ... )
{
T_1 V_4 ;
va_start ( V_4 , V_3 ) ;
V_2 ( V_3 , V_4 ) ;
va_end ( V_4 ) ;
}
