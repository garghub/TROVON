void F_1 ( void )
{
F_2 () ;
}
void F_3 ( const char * V_1 )
{
F_4 ( V_1 ) ;
}
void F_5 ( const char * V_2 , T_1 V_3 )
{
char * V_4 ;
if ( F_6 ( & V_4 , V_2 , V_3 ) < 0 )
vfprintf ( V_5 , V_2 , V_3 ) ;
else {
F_3 ( V_4 ) ;
free ( V_4 ) ;
}
}
void F_7 ( const char * V_2 , ... )
{
T_1 V_3 ;
va_start ( V_3 , V_2 ) ;
F_5 ( V_2 , V_3 ) ;
va_end ( V_3 ) ;
}
void F_8 ( const char * V_1 )
{
F_1 () ;
F_3 ( V_1 ) ;
}
void F_9 ( void )
{
F_8 ( L_1 ) ;
}
int F_10 ( const char * V_6 , T_1 V_3 )
{
int V_7 ;
static int V_8 ;
F_11 ( & V_9 ) ;
V_7 = vsnprintf ( V_10 + V_8 ,
sizeof( V_10 ) - V_8 , V_6 , V_3 ) ;
V_8 += V_7 ;
if ( V_10 [ V_8 - 1 ] == '\n' ) {
F_8 ( V_10 ) ;
F_12 () ;
V_8 = 0 ;
}
F_13 ( & V_9 ) ;
return V_7 ;
}
