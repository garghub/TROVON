void F_1 ()
{
int V_1 ;
for ( V_1 = 0 ; V_1 <= V_2 ; V_1 ++ )
if ( V_3 [ V_1 ] != NULL )
{
F_2 ( V_3 [ V_1 ] ) ;
V_3 [ V_1 ] = NULL ;
}
}
int F_3 ( T_1 * V_4 , int V_5 , long V_1 , void * V_6 , void (* F_4)( void ) )
{
int V_7 = V_5 - V_8 ;
int V_9 = 0 ;
if ( V_7 < 0 || V_7 > V_2 ) return - 1 ;
V_9 = F_5 ( V_7 , V_6 ) ;
return V_9 ;
}
const char * F_6 ( int V_7 )
{
char * V_10 ;
if ( V_7 < 0 || V_7 > V_2 ) return NULL ;
if ( V_3 [ V_7 ] != NULL )
{
return V_3 [ V_7 ] ;
}
V_10 = getenv ( V_11 [ V_7 ] ) ;
if ( V_10 )
{
if ( V_3 [ V_7 ] ) F_2 ( V_3 [ V_7 ] ) ;
V_3 [ V_7 ] = F_7 ( V_10 ) ;
return V_3 [ V_7 ] ;
}
return NULL ;
}
int F_5 ( int V_7 , const char * V_12 )
{
const char * V_10 ;
if ( V_7 < 0 || V_7 > V_2 ) return 0 ;
V_10 = getenv ( V_11 [ V_7 ] ) ;
if ( ! V_10 ) V_10 = V_12 ;
if ( V_3 [ V_7 ] ) F_2 ( V_3 [ V_7 ] ) ;
V_3 [ V_7 ] = F_7 ( V_10 ) ;
return 1 ;
}
