void F_1 ( const char * V_1 , T_1 V_2 )
{
if ( V_3 )
perror ( L_1 ) ;
V_3 = 0 ;
fprintf ( V_4 , L_2 ) ;
vfprintf ( V_4 , V_1 , V_2 ) ;
fprintf ( V_4 , L_3 ) ;
}
void F_2 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_1 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void __weak F_3 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_1 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void F_4 ( const char * V_1 , T_1 V_2 )
{
vprintf ( V_1 , V_2 ) ;
printf ( L_3 ) ;
}
void F_5 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_4 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void __weak F_6 ( const char * V_1 , T_1 V_2 )
{
F_4 ( V_1 , V_2 ) ;
}
void __weak F_7 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_4 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
