void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
T_1 V_5 )
{
unsigned V_6 ;
( void ) V_5 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
unsigned V_8 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_2 -> V_10 [ V_6 ] [ V_8 ] = V_4 -> V_10 [ V_6 * V_9 + V_8 ] ;
}
}
}
void
F_2 (
const struct V_3 * V_11 ,
unsigned V_12 )
{
( void ) V_11 ;
( void ) V_12 ;
}
