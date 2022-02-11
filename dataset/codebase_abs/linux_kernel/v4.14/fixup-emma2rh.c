static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 ) == V_4 )
F_3 ( V_2 , 0xe4 , 1 << 5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_5 ;
if ( F_2 ( V_2 -> V_3 ) == V_6 ) {
V_2 -> V_7 &= 0xff ;
V_2 -> V_7 |= V_8 << 8 ;
for ( V_5 = 0 ; V_5 < V_9 ; V_5 ++ ) {
V_2 -> V_10 [ V_5 ] . V_11 = 0 ;
V_2 -> V_10 [ V_5 ] . V_12 = 0 ;
V_2 -> V_10 [ V_5 ] . V_13 = 0 ;
}
}
}
int F_5 ( const struct V_1 * V_2 , T_1 V_14 , T_1 V_15 )
{
return V_16 [ V_14 ] [ V_15 ] ;
}
int F_6 ( struct V_1 * V_2 )
{
return 0 ;
}
