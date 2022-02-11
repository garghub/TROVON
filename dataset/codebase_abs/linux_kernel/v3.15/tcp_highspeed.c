static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_6 -> V_7 = 0 ;
V_4 -> V_8 = F_4 ( V_9 , V_4 -> V_8 , 0xffffffff / 128 ) ;
}
static void F_5 ( struct V_1 * V_2 , V_9 V_10 , V_9 V_11 , V_9 V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( ! F_6 ( V_2 , V_12 ) )
return;
if ( V_4 -> V_13 <= V_4 -> V_14 )
F_7 ( V_4 , V_11 ) ;
else {
if ( V_4 -> V_13 > V_15 [ V_6 -> V_7 ] . V_16 ) {
while ( V_4 -> V_13 > V_15 [ V_6 -> V_7 ] . V_16 &&
V_6 -> V_7 < V_17 - 1 )
V_6 -> V_7 ++ ;
} else if ( V_6 -> V_7 && V_4 -> V_13 <= V_15 [ V_6 -> V_7 - 1 ] . V_16 ) {
while ( V_6 -> V_7 && V_4 -> V_13 <= V_15 [ V_6 -> V_7 - 1 ] . V_16 )
V_6 -> V_7 -- ;
}
if ( V_4 -> V_13 < V_4 -> V_8 ) {
V_4 -> V_18 += V_6 -> V_7 + 1 ;
if ( V_4 -> V_18 >= V_4 -> V_13 ) {
V_4 -> V_18 -= V_4 -> V_13 ;
V_4 -> V_13 ++ ;
}
}
}
}
static V_9 F_8 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = F_3 ( V_2 ) ;
return F_9 ( V_4 -> V_13 - ( ( V_4 -> V_13 * V_15 [ V_6 -> V_7 ] . V_19 ) >> 8 ) , 2U ) ;
}
static int T_1 F_10 ( void )
{
F_11 ( sizeof( struct V_5 ) > V_20 ) ;
return F_12 ( & V_21 ) ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_21 ) ;
}
