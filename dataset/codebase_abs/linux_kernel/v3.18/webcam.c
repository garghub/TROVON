static int T_1
F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_4 = F_2 ( V_5 ) ;
if ( F_3 ( V_4 ) )
return F_4 ( V_4 ) ;
V_3 = F_5 ( V_2 , V_4 ) ;
if ( V_3 < 0 )
F_6 ( V_4 ) ;
return V_3 ;
}
static int
F_7 ( struct V_6 * V_7 )
{
if ( ! F_8 ( V_4 ) )
F_6 ( V_4 ) ;
if ( ! F_8 ( V_5 ) )
F_9 ( V_5 ) ;
return 0 ;
}
static int T_1
F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_5 = F_11 ( L_1 ) ;
if ( F_3 ( V_5 ) )
return F_4 ( V_5 ) ;
V_9 = F_12 ( V_5 , struct V_8 , V_11 ) ;
V_9 -> V_12 = V_12 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_14 = V_14 ;
F_13 ( V_15 ) ;
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 ;
V_9 -> V_20 = V_21 ;
V_9 -> V_22 = V_23 ;
V_9 -> V_24 = V_25 ;
V_10 = F_14 ( V_7 , V_26 ) ;
if ( V_10 < 0 )
goto error;
V_27 . V_28 =
V_26 [ V_29 ] . V_30 ;
V_27 . V_31 =
V_26 [ V_32 ] . V_30 ;
V_33 . V_34 =
V_26 [ V_35 ] . V_30 ;
if ( ( V_10 = F_15 ( V_7 , & V_33 ,
F_1 ) ) < 0 )
goto error;
F_16 ( V_7 , & V_36 ) ;
F_17 ( V_7 , L_2 ) ;
return 0 ;
error:
F_9 ( V_5 ) ;
return V_10 ;
}
