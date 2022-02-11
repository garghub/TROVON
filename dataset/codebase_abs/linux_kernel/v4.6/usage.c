static void F_1 ( const char * V_1 , const char * V_2 , T_1 V_3 )
{
char V_4 [ 1024 ] ;
vsnprintf ( V_4 , sizeof( V_4 ) , V_2 , V_3 ) ;
fprintf ( V_5 , L_1 , V_1 , V_4 ) ;
}
static NORETURN void F_2 ( const char * V_2 )
{
fprintf ( V_5 , L_2 , V_2 ) ;
exit ( 129 ) ;
}
static NORETURN void F_3 ( const char * V_2 , T_1 V_3 )
{
F_1 ( L_3 , V_2 , V_3 ) ;
exit ( 128 ) ;
}
static void F_4 ( const char * V_2 , T_1 V_3 )
{
F_1 ( L_4 , V_2 , V_3 ) ;
}
static void F_5 ( const char * V_6 , T_1 V_3 )
{
F_1 ( L_5 , V_6 , V_3 ) ;
}
void F_6 ( void (* F_7)( const char * V_2 , T_1 V_3 ) )
{
V_7 = F_7 ;
}
void F_8 ( const char * V_2 )
{
F_9 ( V_2 ) ;
}
void F_10 ( const char * V_2 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
F_3 ( V_2 , V_3 ) ;
va_end ( V_3 ) ;
}
int error ( const char * V_2 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
F_11 ( V_2 , V_3 ) ;
va_end ( V_3 ) ;
return - 1 ;
}
void F_12 ( const char * V_6 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_6 ) ;
V_7 ( V_6 , V_3 ) ;
va_end ( V_3 ) ;
}
