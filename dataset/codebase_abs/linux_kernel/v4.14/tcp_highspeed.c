static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_6 -> V_7 = 0 ;
V_4 -> V_8 = F_4 ( V_9 , V_4 -> V_8 , 0xffffffff / 128 ) ;
}
static void F_5 ( struct V_1 * V_2 , V_9 V_10 , V_9 V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
if ( ! F_6 ( V_2 ) )
return;
if ( F_7 ( V_4 ) )
F_8 ( V_4 , V_11 ) ;
else {
if ( V_4 -> V_12 > V_13 [ V_6 -> V_7 ] . V_14 ) {
while ( V_4 -> V_12 > V_13 [ V_6 -> V_7 ] . V_14 &&
V_6 -> V_7 < V_15 - 1 )
V_6 -> V_7 ++ ;
} else if ( V_6 -> V_7 && V_4 -> V_12 <= V_13 [ V_6 -> V_7 - 1 ] . V_14 ) {
while ( V_6 -> V_7 && V_4 -> V_12 <= V_13 [ V_6 -> V_7 - 1 ] . V_14 )
V_6 -> V_7 -- ;
}
if ( V_4 -> V_12 < V_4 -> V_8 ) {
V_4 -> V_16 += V_6 -> V_7 + 1 ;
if ( V_4 -> V_16 >= V_4 -> V_12 ) {
V_4 -> V_16 -= V_4 -> V_12 ;
V_4 -> V_12 ++ ;
}
}
}
}
static V_9 F_9 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
return F_10 ( V_4 -> V_12 - ( ( V_4 -> V_12 * V_13 [ V_6 -> V_7 ] . V_17 ) >> 8 ) , 2U ) ;
}
static int T_1 F_11 ( void )
{
F_12 ( sizeof( struct V_5 ) > V_18 ) ;
return F_13 ( & V_19 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_19 ) ;
}
