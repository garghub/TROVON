static char * F_1 ( void )
{
static char V_1 [ 4 ] [ V_2 ] ;
static int V_3 ;
return V_1 [ 3 & ++ V_3 ] ;
}
static char * F_2 ( char * V_4 )
{
if ( ! memcmp ( V_4 , L_1 , 2 ) ) {
V_4 += 2 ;
while ( * V_4 == '/' )
V_4 ++ ;
}
return V_4 ;
}
char * F_3 ( const char * V_5 , ... )
{
T_1 args ;
unsigned V_6 ;
char * V_7 = F_1 () ;
va_start ( args , V_5 ) ;
V_6 = vsnprintf ( V_7 , V_2 , V_5 , args ) ;
va_end ( args ) ;
if ( V_6 >= V_2 )
return V_8 ;
return F_2 ( V_7 ) ;
}
int F_4 ( char * V_9 , T_2 V_10 , const char * V_11 , const char * V_12 )
{
return F_5 ( V_9 , V_10 , L_2 , V_11 , V_11 [ 0 ] ? L_3 : L_4 , V_12 ) ;
}
int F_6 ( char * V_9 , T_2 V_10 , const char * V_11 , const char * V_12 , const char * V_13 )
{
return F_5 ( V_9 , V_10 , L_5 , V_11 , V_11 [ 0 ] ? L_3 : L_4 ,
V_12 , V_12 [ 0 ] ? L_3 : L_4 , V_13 ) ;
}
bool F_7 ( const char * V_14 )
{
struct V_15 V_16 ;
if ( V_15 ( V_14 , & V_16 ) )
return false ;
return F_8 ( V_16 . V_17 ) ;
}
