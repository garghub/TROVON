static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_11 = V_8 -> V_11 ;
if ( V_8 -> V_12 ) {
V_10 . V_13 . V_14 =
* ( V_15 * ) & V_4 -> V_16 [ V_8 -> V_12 ] ;
V_10 . V_17 . V_14 =
* ( V_15 * ) & V_4 -> V_16 [ V_8 -> V_18 ] ;
}
V_4 -> V_19 . V_20 = F_3 ( V_6 -> V_21 , F_4 ( V_6 ) ,
& V_10 , F_5 ( V_6 ) ) ;
}
static void
F_6 ( const struct V_22 * V_23 , const struct V_1 * V_2 )
{
F_7 ( V_23 -> V_24 , V_25 ) ;
}
static int T_1 F_8 ( void )
{
int V_26 ;
V_26 = F_9 ( & V_27 ) ;
if ( V_26 < 0 )
return V_26 ;
F_10 () ;
return V_26 ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_27 ) ;
F_13 () ;
}
