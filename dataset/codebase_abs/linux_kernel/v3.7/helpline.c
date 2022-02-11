static void F_1 ( void )
{
}
static void F_2 ( const char * T_1 V_1 )
{
}
void F_3 ( void )
{
V_2 -> V_3 () ;
}
void F_4 ( const char * T_1 )
{
V_2 -> V_4 ( T_1 ) ;
}
void F_5 ( const char * V_5 , T_2 V_6 )
{
char * V_7 ;
if ( F_6 ( & V_7 , V_5 , V_6 ) < 0 )
vfprintf ( V_8 , V_5 , V_6 ) ;
else {
F_4 ( V_7 ) ;
free ( V_7 ) ;
}
}
void F_7 ( const char * V_5 , ... )
{
T_2 V_6 ;
va_start ( V_6 , V_5 ) ;
F_5 ( V_5 , V_6 ) ;
va_end ( V_6 ) ;
}
void F_8 ( const char * T_1 )
{
F_3 () ;
F_4 ( T_1 ) ;
}
