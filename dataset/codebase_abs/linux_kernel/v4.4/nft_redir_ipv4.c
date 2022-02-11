static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( V_8 -> V_11 ) {
V_10 . V_12 [ 0 ] . V_13 . V_14 =
* ( V_15 * ) & V_4 -> V_16 [ V_8 -> V_11 ] ;
V_10 . V_12 [ 0 ] . V_17 . V_14 =
* ( V_15 * ) & V_4 -> V_16 [ V_8 -> V_18 ] ;
V_10 . V_12 [ 0 ] . V_19 |= V_20 ;
}
V_10 . V_12 [ 0 ] . V_19 |= V_8 -> V_19 ;
V_4 -> V_21 . V_22 = F_3 ( V_6 -> V_23 , & V_10 ,
V_6 -> V_24 ) ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_25 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_25 ) ;
}
