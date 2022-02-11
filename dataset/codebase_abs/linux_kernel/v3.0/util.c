char * F_1 ( const char * V_1 )
{
int V_2 = strlen ( V_1 ) + 1 ;
char * V_3 = xmalloc ( V_2 ) ;
memcpy ( V_3 , V_1 , V_2 ) ;
return V_3 ;
}
char * F_2 ( const char * V_4 , const char * V_5 )
{
int V_6 = strlen ( V_4 ) ;
int V_7 = strlen ( V_5 ) ;
int V_2 ;
int V_8 = 1 ;
char * V_9 ;
V_2 = V_6 + V_7 + 2 ;
if ( ( V_6 > 0 ) && ( V_4 [ V_6 - 1 ] == '/' ) ) {
V_8 = 0 ;
V_2 -- ;
}
V_9 = xmalloc ( V_2 ) ;
memcpy ( V_9 , V_4 , V_6 ) ;
if ( V_8 ) {
V_9 [ V_6 ] = '/' ;
V_6 ++ ;
}
memcpy ( V_9 + V_6 , V_5 , V_7 + 1 ) ;
return V_9 ;
}
