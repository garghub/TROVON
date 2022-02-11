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
int V_12 ;
V_12 = F_5 ( V_11 , V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_14 . V_15 = V_13 [ V_16 ] . V_6 ;
V_14 . V_17 = V_13 [ V_18 ] . V_6 ;
V_19 . V_20 = V_13 [ V_21 ] . V_6 ;
V_12 = F_6 ( V_11 , & V_19 , F_2 ) ;
if ( V_12 < 0 )
return V_12 ;
F_7 ( V_11 , & V_22 ) ;
F_8 ( L_1 , V_23 ) ;
return 0 ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_24 ) ;
}
static void T_1 F_11 ( void )
{
F_12 ( & V_24 ) ;
}
