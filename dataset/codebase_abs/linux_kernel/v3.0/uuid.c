void
F_1 ( T_1 * V_1 , int V_2 [ 2 ] )
{
T_2 * V_3 = ( T_2 * ) V_1 ;
V_2 [ 0 ] = ( F_2 ( V_3 -> V_4 ) << 16 ) |
F_2 ( V_3 -> V_5 ) ;
V_2 [ 1 ] = F_3 ( V_3 -> V_6 ) ;
}
int
F_4 ( T_1 * V_1 )
{
int V_7 ;
char * V_8 = ( char * ) V_1 ;
if ( V_1 == NULL )
return 0 ;
for ( V_7 = 0 ; V_7 < sizeof *V_1 ; V_7 ++ )
if ( * V_8 ++ ) return 0 ;
return 1 ;
}
int
F_5 ( T_1 * V_9 , T_1 * V_10 )
{
return memcmp ( V_9 , V_10 , sizeof( T_1 ) ) ? 0 : 1 ;
}
