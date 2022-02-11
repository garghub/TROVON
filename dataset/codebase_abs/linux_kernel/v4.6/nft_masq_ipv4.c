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
V_4 -> V_19 . V_20 = F_3 ( V_6 -> V_21 , V_6 -> V_22 ,
& V_10 , V_6 -> V_23 ) ;
}
static int T_1 F_4 ( void )
{
int V_24 ;
V_24 = F_5 ( & V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
F_6 () ;
return V_24 ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_25 ) ;
F_9 () ;
}
