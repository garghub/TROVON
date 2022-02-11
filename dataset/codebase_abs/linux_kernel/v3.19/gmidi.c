static int T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
static int T_2 F_4 ( struct V_5 * V_6 )
{
int V_7 ;
V_3 = F_5 ( V_4 ) ;
if ( F_6 ( V_3 ) )
return F_7 ( V_3 ) ;
V_7 = F_8 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_2 ( V_3 ) ;
return V_7 ;
}
return 0 ;
}
static int T_2 F_9 ( struct V_1 * V_8 )
{
struct V_9 * V_10 ;
int V_7 ;
V_4 = F_10 ( L_1 ) ;
if ( F_6 ( V_4 ) )
return F_7 ( V_4 ) ;
V_10 = F_11 ( V_4 , struct V_9 , V_11 ) ;
V_10 -> V_12 = V_12 ;
V_10 -> V_13 = V_13 ;
V_10 -> V_14 = V_14 ;
V_10 -> V_15 = V_15 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_17 = V_17 ;
V_7 = F_12 ( V_8 , V_18 ) ;
if ( V_7 < 0 )
goto V_19;
V_20 . V_21 = V_18 [ V_22 ] . V_13 ;
V_20 . V_23 = V_18 [ V_24 ] . V_13 ;
V_25 . V_26 = V_18 [ V_27 ] . V_13 ;
V_7 = F_13 ( V_8 , & V_25 , F_4 ) ;
if ( V_7 < 0 )
goto V_19;
F_14 ( V_8 , & V_28 ) ;
F_15 ( L_2 , V_29 ) ;
return 0 ;
V_19:
F_3 ( V_4 ) ;
return V_7 ;
}
