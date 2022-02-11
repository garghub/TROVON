static int F_1 ( void )
{
if ( V_1 )
memcpy ( ( void * ) V_1 , ( void * ) V_2 , V_3 ) ;
return 0 ;
}
int F_2 ( void )
{
struct V_4 * V_5 , * V_6 ;
T_1 V_7 [ V_8 ] ;
struct V_9 V_10 ;
F_3 ( & V_10 ) ;
V_6 = & V_11 [ sizeof( V_11 ) / sizeof( V_11 [ 0 ] ) ] ;
for ( V_5 = V_11 ; V_5 < V_6 ; V_5 ++ )
F_4 ( & V_10 , ( V_12 * ) ( V_5 -> V_13 ) , V_5 -> V_14 ) ;
F_5 ( & V_10 , V_7 ) ;
if ( memcmp ( V_7 , V_15 , sizeof( V_7 ) ) )
return 1 ;
return 0 ;
}
void F_6 ( void )
{
int V_16 ;
V_16 = F_2 () ;
if ( V_16 ) {
for (; ; )
;
}
F_1 () ;
}
