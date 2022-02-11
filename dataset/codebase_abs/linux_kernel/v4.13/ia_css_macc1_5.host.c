void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned int V_5 )
{
( void ) V_5 ;
V_2 -> exp = V_4 -> exp ;
}
void
F_2 (
struct V_6 * V_7 ,
const struct V_8 * V_4 ,
unsigned int V_5 )
{
unsigned int V_9 , V_10 , V_11 , V_12 ;
unsigned int V_13 [] = {
0 , 1 , 3 , 2 , 6 , 7 , 5 , 4 , 12 , 13 , 15 , 14 , 10 , 11 , 9 , 8 } ;
( void ) V_5 ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 ++ )
for ( V_9 = 0 ; V_9 < V_14 ; V_9 ++ ) {
V_12 = V_13 [ V_9 ] + ( V_11 * V_14 ) ;
V_10 = 4 * V_9 ;
V_7 -> V_15 [ 0 ] [ ( V_12 ) ] = V_4 -> V_15 [ V_10 ] ;
V_7 -> V_15 [ 1 ] [ ( V_12 ) ] = V_4 -> V_15 [ V_10 + 1 ] ;
V_7 -> V_15 [ 2 ] [ ( V_12 ) ] = V_4 -> V_15 [ V_10 + 2 ] ;
V_7 -> V_15 [ 3 ] [ ( V_12 ) ] = V_4 -> V_15 [ V_10 + 3 ] ;
}
}
void
F_3 (
const struct V_3 * V_16 ,
unsigned int V_17 )
{
F_4 ( V_17 ,
L_1 ,
V_16 -> exp ) ;
}
