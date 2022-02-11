static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 V_11 ;
unsigned int V_12 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
if ( V_9 -> V_13 ) {
V_11 . V_14 [ 0 ] . V_15 . V_16 =
* ( V_17 * ) & V_4 [ V_9 -> V_13 ] . V_4 [ 0 ] ;
V_11 . V_14 [ 0 ] . V_18 . V_16 =
* ( V_17 * ) & V_4 [ V_9 -> V_19 ] . V_4 [ 0 ] ;
V_11 . V_14 [ 0 ] . V_20 |= V_21 ;
}
V_11 . V_14 [ 0 ] . V_20 |= V_9 -> V_20 ;
V_12 = F_3 ( V_7 -> V_22 , & V_11 , V_7 -> V_23 -> V_24 ) ;
V_4 [ V_25 ] . V_12 = V_12 ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_26 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_26 ) ;
}
