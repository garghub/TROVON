static int T_1 F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_2 F_2 ( struct V_3 * V_4 )
{
return F_3 ( V_4 , V_5 , V_6 ,
V_7 , V_8 ,
V_9 , V_10 ) ;
}
static int T_2 F_4 ( struct V_1 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
int V_14 , V_15 ;
V_15 = F_5 ( V_11 ) ;
if ( V_15 < 0 )
return V_15 ;
V_16 [ V_17 ] . V_6 = V_15 ;
V_18 . V_19 = V_15 ;
V_15 = F_5 ( V_11 ) ;
if ( V_15 < 0 )
return V_15 ;
V_16 [ V_20 ] . V_6 = V_15 ;
V_18 . V_21 = V_15 ;
V_15 = F_5 ( V_11 ) ;
if ( V_15 < 0 )
return V_15 ;
V_16 [ V_22 ] . V_6 = V_15 ;
V_23 . V_24 = V_15 ;
V_14 = F_6 ( V_13 ) ;
if ( V_14 < 0 ) {
F_7 ( L_1 ,
V_25 , V_13 -> V_26 ) ;
V_18 . V_27 = F_8 ( 0x9999 ) ;
} else {
V_18 . V_27 = F_8 ( 0x0200 + V_14 ) ;
}
V_15 = F_9 ( V_11 , & V_23 , F_2 ) ;
if ( V_15 < 0 )
return V_15 ;
F_10 ( L_2 , V_28 ) ;
return 0 ;
}
static int T_2 F_11 ( void )
{
return F_12 ( & V_29 , F_4 ) ;
}
static void T_1 F_13 ( void )
{
F_14 ( & V_29 ) ;
}
