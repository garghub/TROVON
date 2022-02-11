static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
if ( V_4 -> V_12 . V_13 < 1 ) {
F_2 ( & V_2 -> V_5 , L_1 ) ;
return - V_14 ;
}
V_10 = F_3 ( V_2 , V_15 , 0 ) ;
if ( ! V_10 )
return - V_16 ;
V_8 = F_4 ( sizeof( struct V_7 ) , V_17 ) ;
if ( ! V_8 ) {
F_2 ( & V_2 -> V_5 , L_2 ) ;
return - V_18 ;
}
if ( ! F_5 ( V_10 -> V_19 , F_6 ( V_10 ) ,
F_7 ( & V_2 -> V_5 ) ) ) {
F_2 ( & V_2 -> V_5 , L_3 ) ;
V_11 = - V_20 ;
goto V_21;
}
V_8 -> V_22 = F_8 ( V_10 -> V_19 , F_6 ( V_10 ) ) ;
if ( V_8 -> V_22 == NULL ) {
F_2 ( & V_2 -> V_5 , L_4 ) ;
V_11 = - V_23 ;
goto V_24;
}
V_8 -> V_12 . V_25 = & V_8 ;
V_8 -> V_26 . V_25 = & V_8 -> V_12 ;
V_8 -> V_26 . V_27 = V_28 ;
V_8 -> V_26 . V_29 = F_7 ( & V_2 -> V_5 ) ;
V_8 -> V_12 . V_30 = V_8 -> V_22 ;
V_8 -> V_12 . V_31 = V_8 -> V_22 ;
V_8 -> V_12 . V_32 = V_4 -> V_33 . V_32 ;
V_8 -> V_12 . V_34 = V_4 -> V_33 . V_34 ;
V_8 -> V_12 . V_35 = V_4 -> V_33 . V_35 ;
V_8 -> V_12 . V_36 = V_4 -> V_33 . V_36 ;
V_8 -> V_12 . V_37 = V_4 -> V_33 . V_37 ;
V_8 -> V_12 . V_38 = V_4 -> V_12 . V_38 ;
V_8 -> V_12 . V_39 |= V_4 -> V_12 . V_39 ;
V_8 -> V_12 . V_40 |= V_4 -> V_12 . V_40 ;
V_8 -> V_12 . V_41 . V_42 = V_4 -> V_33 . V_43 ;
V_8 -> V_12 . V_41 . V_44 = V_4 -> V_12 . V_45 ;
V_8 -> V_12 . V_41 . V_46 = V_47 ;
F_9 ( V_2 , V_8 ) ;
if ( V_4 -> V_33 . V_48 ) {
V_11 = V_4 -> V_33 . V_48 ( V_2 ) ;
if ( V_11 )
goto V_49;
}
if ( F_10 ( & V_8 -> V_26 , V_4 -> V_12 . V_13 ) ) {
V_11 = - V_16 ;
goto V_49;
}
V_11 = F_11 ( & V_8 -> V_26 ,
V_4 -> V_12 . V_50 , 0 ,
V_4 -> V_12 . V_51 , V_4 -> V_12 . V_52 ) ;
if ( ! V_11 )
return V_11 ;
F_12 ( & V_8 -> V_26 ) ;
V_49:
if ( V_4 -> V_33 . remove )
V_4 -> V_33 . remove ( V_2 ) ;
F_9 ( V_2 , NULL ) ;
F_13 ( V_8 -> V_22 ) ;
V_24:
F_14 ( V_10 -> V_19 , F_6 ( V_10 ) ) ;
V_21:
F_15 ( V_8 ) ;
return V_11 ;
}
static int T_2 F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_17 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 . V_6 ;
struct V_9 * V_10 ;
V_10 = F_3 ( V_2 , V_15 , 0 ) ;
F_12 ( & V_8 -> V_26 ) ;
if ( V_4 -> V_33 . remove )
V_4 -> V_33 . remove ( V_2 ) ;
F_13 ( V_8 -> V_22 ) ;
F_14 ( V_10 -> V_19 , F_6 ( V_10 ) ) ;
F_15 ( V_8 ) ;
return 0 ;
}
static int T_3 F_18 ( void )
{
return F_19 ( & V_53 ) ;
}
static void T_4 F_20 ( void )
{
F_21 ( & V_53 ) ;
}
