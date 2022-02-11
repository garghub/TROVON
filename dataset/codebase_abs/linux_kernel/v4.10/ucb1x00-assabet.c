static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 V_8 ;
static struct V_9 V_10 [ 6 ] ;
unsigned V_11 ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
for ( V_11 = 0 ; V_11 < F_2 ( V_10 ) ; V_11 ++ ) {
V_10 [ V_11 ] . V_12 = V_13 + V_11 ;
V_10 [ V_11 ] . V_14 = V_4 -> V_14 . V_15 + V_11 ;
V_10 [ V_11 ] . type = V_16 ;
V_10 [ V_11 ] . V_17 = true ;
}
V_8 . V_10 = V_10 ;
V_8 . V_18 = F_2 ( V_10 ) ;
V_8 . V_19 = 50 ;
V_8 . V_20 = L_1 ;
V_6 = F_3 ( & V_4 -> V_2 , L_2 , - 1 ,
& V_8 , sizeof( V_8 ) ) ;
F_4 ( & V_4 -> V_2 , & V_21 ) ;
F_4 ( & V_4 -> V_2 , & V_22 ) ;
F_4 ( & V_4 -> V_2 , & V_23 ) ;
V_2 -> V_24 = V_6 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_24 ;
if ( ! F_6 ( V_6 ) )
F_7 ( V_6 ) ;
F_8 ( & V_2 -> V_4 -> V_2 , & V_23 ) ;
F_8 ( & V_2 -> V_4 -> V_2 , & V_22 ) ;
F_8 ( & V_2 -> V_4 -> V_2 , & V_21 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_25 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_25 ) ;
}
