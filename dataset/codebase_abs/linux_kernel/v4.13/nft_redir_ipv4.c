static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
if ( V_8 -> V_11 ) {
V_10 . V_12 [ 0 ] . V_13 . V_14 = ( V_15 V_16 ) F_3 (
& V_4 -> V_17 [ V_8 -> V_11 ] ) ;
V_10 . V_12 [ 0 ] . V_18 . V_14 = ( V_15 V_16 ) F_3 (
& V_4 -> V_17 [ V_8 -> V_19 ] ) ;
V_10 . V_12 [ 0 ] . V_20 |= V_21 ;
}
V_10 . V_12 [ 0 ] . V_20 |= V_8 -> V_20 ;
V_4 -> V_22 . V_23 = F_4 ( V_6 -> V_24 , & V_10 , F_5 ( V_6 ) ) ;
}
static void
F_6 ( const struct V_25 * V_26 , const struct V_1 * V_2 )
{
F_7 ( V_26 -> V_27 , V_28 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_29 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_29 ) ;
}
