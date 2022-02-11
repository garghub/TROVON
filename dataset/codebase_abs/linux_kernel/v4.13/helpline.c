static void F_1 ( void )
{
}
static void F_2 ( const char * T_1 V_1 )
{
}
static int F_3 ( const char * T_2 V_1 ,
T_3 T_4 V_1 )
{
return 0 ;
}
void F_4 ( void )
{
V_2 -> V_3 () ;
}
void F_5 ( const char * T_1 )
{
V_2 -> V_4 ( T_1 ) ;
}
void F_6 ( const char * T_2 , T_3 T_4 )
{
char * V_5 ;
if ( F_7 ( & V_5 , T_2 , T_4 ) < 0 )
vfprintf ( V_6 , T_2 , T_4 ) ;
else {
F_5 ( V_5 ) ;
free ( V_5 ) ;
}
}
void F_8 ( const char * T_2 , ... )
{
T_3 T_4 ;
va_start ( T_4 , T_2 ) ;
F_6 ( T_2 , T_4 ) ;
va_end ( T_4 ) ;
}
void F_9 ( const char * T_1 )
{
F_4 () ;
F_5 ( T_1 ) ;
}
int F_10 ( const char * T_2 , T_3 T_4 )
{
return V_2 -> V_7 ( T_2 , T_4 ) ;
}
void F_11 ( const char * T_2 , ... )
{
T_3 T_4 ;
F_4 () ;
va_start ( T_4 , T_2 ) ;
F_6 ( T_2 , T_4 ) ;
va_end ( T_4 ) ;
}
