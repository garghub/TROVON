void F_1 ( void * V_1 , int V_2 )
{
T_1 * V_3 = V_1 ;
int V_4 ;
V_2 = V_2 / sizeof( T_1 ) ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ ) {
* V_3 = F_2 ( * V_3 ) ;
V_3 ++ ;
}
}
void F_3 ( void * V_1 , int V_2 )
{
T_1 * V_3 = V_1 ;
int V_4 ;
V_2 = V_2 / sizeof( T_1 ) ;
for ( V_4 = 0 ; V_4 < V_2 ; V_4 ++ ) {
* V_3 = F_4 ( * V_3 ) ;
V_3 ++ ;
}
}
void F_5 ( struct V_5 * V_6 , T_2 V_7 , int V_2 )
{
V_6 -> V_8 = F_6 ( V_7 ) ;
V_6 -> V_9 = F_7 ( V_7 ) ;
V_6 -> V_2 = V_2 ;
}
T_2 F_8 ( struct V_5 * V_6 )
{
return ( T_2 ) ( ( ( ( V_10 ) V_6 -> V_8 ) << 32 ) | V_6 -> V_9 ) ;
}
