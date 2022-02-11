void F_1 ( void )
{
}
void F_2 ( const char * V_1 )
{
const T_1 V_2 = sizeof( V_3 ) ;
F_3 ( V_4 - 1 , 0 ) ;
F_4 ( 0 ) ;
F_5 ( ( char * ) V_1 , V_5 ) ;
F_6 () ;
strncpy ( V_3 , V_1 , V_2 ) [ V_2 - 1 ] = '\0' ;
}
void F_7 ( const char * V_6 , T_2 V_7 )
{
char * V_8 ;
if ( F_8 ( & V_8 , V_6 , V_7 ) < 0 )
vfprintf ( V_9 , V_6 , V_7 ) ;
else {
F_2 ( V_8 ) ;
free ( V_8 ) ;
}
}
void F_9 ( const char * V_6 , ... )
{
T_2 V_7 ;
va_start ( V_7 , V_6 ) ;
F_7 ( V_6 , V_7 ) ;
va_end ( V_7 ) ;
}
void F_10 ( const char * V_1 )
{
F_1 () ;
F_2 ( V_1 ) ;
}
void F_11 ( void )
{
F_10 ( L_1 ) ;
}
int F_12 ( const char * V_10 , T_2 V_7 )
{
int V_11 ;
static int V_12 ;
F_13 ( & V_13 ) ;
V_11 = vsnprintf ( V_14 + V_12 ,
sizeof( V_14 ) - V_12 , V_10 , V_7 ) ;
V_12 += V_11 ;
if ( V_14 [ V_12 - 1 ] == '\n' ) {
F_10 ( V_14 ) ;
F_6 () ;
V_12 = 0 ;
}
F_14 ( & V_13 ) ;
return V_11 ;
}
