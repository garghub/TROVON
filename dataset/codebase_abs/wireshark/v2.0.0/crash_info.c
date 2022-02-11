void
F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
char * V_3 , * V_4 , * V_5 ;
va_start ( V_2 , V_1 ) ;
V_3 = F_2 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
if ( V_6 == NULL )
V_6 = V_3 ;
else {
V_4 = V_6 ;
V_5 = F_3 ( L_1 , V_4 , V_3 ) ;
F_4 ( V_3 ) ;
V_6 = V_5 ;
F_4 ( V_4 ) ;
}
}
void
F_1 ( const char * V_1 V_7 , ... )
{
}
