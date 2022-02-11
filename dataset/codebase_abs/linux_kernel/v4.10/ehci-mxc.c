static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_10 , V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_5 = & V_2 -> V_5 ;
struct V_15 * V_16 ;
if ( ! V_4 ) {
F_3 ( V_5 , L_1 ) ;
return - V_17 ;
}
V_10 = F_4 ( V_2 , 0 ) ;
V_7 = F_5 ( & V_18 , V_5 , F_6 ( V_5 ) ) ;
if ( ! V_7 )
return - V_19 ;
V_9 = F_7 ( V_2 , V_20 , 0 ) ;
V_7 -> V_21 = F_8 ( & V_2 -> V_5 , V_9 ) ;
if ( F_9 ( V_7 -> V_21 ) ) {
V_11 = F_10 ( V_7 -> V_21 ) ;
goto V_22;
}
V_7 -> V_23 = V_9 -> V_24 ;
V_7 -> V_25 = F_11 ( V_9 ) ;
V_7 -> V_26 = 1 ;
V_16 = F_12 ( V_7 ) ;
V_13 = (struct V_12 * ) V_16 -> V_13 ;
V_13 -> V_27 = F_13 ( & V_2 -> V_5 , L_2 ) ;
if ( F_9 ( V_13 -> V_27 ) ) {
V_11 = F_10 ( V_13 -> V_27 ) ;
goto V_22;
}
F_14 ( V_13 -> V_27 ) ;
V_13 -> V_28 = F_13 ( & V_2 -> V_5 , L_3 ) ;
if ( F_9 ( V_13 -> V_28 ) ) {
V_11 = F_10 ( V_13 -> V_28 ) ;
goto V_29;
}
F_14 ( V_13 -> V_28 ) ;
V_13 -> V_30 = F_13 ( & V_2 -> V_5 , L_4 ) ;
if ( F_9 ( V_13 -> V_30 ) )
V_13 -> V_30 = NULL ;
if ( V_13 -> V_30 )
F_14 ( V_13 -> V_30 ) ;
if ( V_4 -> V_31 ) {
V_11 = V_4 -> V_31 ( V_2 ) ;
if ( V_11 ) {
F_3 ( V_5 , L_5 ) ;
goto V_32;
}
F_15 ( 10 ) ;
}
V_16 -> V_33 = V_7 -> V_21 + 0x100 ;
V_16 -> V_21 = V_7 -> V_21 + 0x100 +
F_16 ( V_16 , F_17 ( V_16 , & V_16 -> V_33 -> V_34 ) ) ;
F_18 ( V_16 , V_4 -> V_35 , & V_16 -> V_21 -> V_36 [ 0 ] ) ;
F_19 ( 10 ) ;
if ( V_4 -> V_37 ) {
V_4 -> V_37 -> V_38 = V_7 -> V_21 + V_39 ;
V_11 = F_20 ( V_4 -> V_37 ) ;
if ( V_11 ) {
F_3 ( V_5 , L_6 ) ;
V_11 = - V_40 ;
goto V_41;
}
V_11 = F_21 ( V_4 -> V_37 -> V_37 , 1 ) ;
if ( V_11 ) {
F_3 ( V_5 , L_7 ) ;
goto V_41;
}
}
F_22 ( V_2 , V_7 ) ;
V_11 = F_23 ( V_7 , V_10 , V_42 ) ;
if ( V_11 )
goto V_41;
F_24 ( V_7 -> V_43 . V_44 ) ;
return 0 ;
V_41:
if ( V_4 && V_4 -> exit )
V_4 -> exit ( V_2 ) ;
V_32:
if ( V_13 -> V_30 )
F_25 ( V_13 -> V_30 ) ;
F_25 ( V_13 -> V_28 ) ;
V_29:
F_25 ( V_13 -> V_27 ) ;
V_22:
F_26 ( V_7 ) ;
return V_11 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
struct V_6 * V_7 = F_28 ( V_2 ) ;
struct V_15 * V_16 = F_12 ( V_7 ) ;
struct V_12 * V_13 = (struct V_12 * ) V_16 -> V_13 ;
F_29 ( V_7 ) ;
if ( V_4 && V_4 -> exit )
V_4 -> exit ( V_2 ) ;
if ( V_4 && V_4 -> V_37 )
F_30 ( V_4 -> V_37 ) ;
F_25 ( V_13 -> V_27 ) ;
F_25 ( V_13 -> V_28 ) ;
if ( V_13 -> V_30 )
F_25 ( V_13 -> V_30 ) ;
F_26 ( V_7 ) ;
return 0 ;
}
static int T_1 F_31 ( void )
{
if ( F_32 () )
return - V_40 ;
F_33 ( L_8 V_45 L_9 , V_46 ) ;
F_34 ( & V_18 , & V_47 ) ;
return F_35 ( & V_48 ) ;
}
static void T_2 F_36 ( void )
{
F_37 ( & V_48 ) ;
}
