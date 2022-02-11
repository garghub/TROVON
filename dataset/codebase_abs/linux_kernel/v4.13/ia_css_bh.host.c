void
F_1 (
struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
if( ! V_4 )
return;
assert ( F_2 ( V_6 ) == sizeof( * V_4 ) ) ;
for ( V_5 = 0 ; V_5 < V_7 ; V_5 ++ ) {
V_2 [ V_5 ] . V_8 = V_4 -> V_9 [ V_10 ] [ V_5 ] ;
V_2 [ V_5 ] . V_11 = V_4 -> V_9 [ V_12 ] [ V_5 ] ;
V_2 [ V_5 ] . V_13 = V_4 -> V_9 [ V_14 ] [ V_5 ] ;
V_2 [ V_5 ] . V_15 = V_4 -> V_9 [ V_16 ] [ V_5 ] ;
}
}
void
F_3 (
struct V_17 * V_18 ,
const struct V_19 * V_20 ,
unsigned V_21 )
{
( void ) V_21 ;
V_18 -> V_22 =
F_4 ( V_20 -> V_23 , 16 , V_24 ) ;
V_18 -> V_25 =
F_4 ( V_20 -> V_26 , 16 , V_24 ) ;
V_18 -> V_27 =
F_4 ( V_20 -> V_28 , 16 , V_24 ) ;
}
