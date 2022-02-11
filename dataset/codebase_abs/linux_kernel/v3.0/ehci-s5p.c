static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
int V_13 ;
int V_14 ;
V_4 = V_2 -> V_15 . V_16 ;
if ( ! V_4 ) {
F_2 ( & V_2 -> V_15 , L_1 ) ;
return - V_17 ;
}
V_6 = F_3 ( sizeof( struct V_5 ) , V_18 ) ;
if ( ! V_6 )
return - V_19 ;
V_6 -> V_15 = & V_2 -> V_15 ;
V_8 = F_4 ( & V_20 , & V_2 -> V_15 ,
F_5 ( & V_2 -> V_15 ) ) ;
if ( ! V_8 ) {
F_2 ( & V_2 -> V_15 , L_2 ) ;
V_14 = - V_19 ;
goto V_21;
}
V_6 -> V_22 = F_6 ( & V_2 -> V_15 , L_3 ) ;
if ( F_7 ( V_6 -> V_22 ) ) {
F_2 ( & V_2 -> V_15 , L_4 ) ;
V_14 = F_8 ( V_6 -> V_22 ) ;
goto V_23;
}
V_14 = F_9 ( V_6 -> V_22 ) ;
if ( V_14 )
goto V_24;
V_12 = F_10 ( V_2 , V_25 , 0 ) ;
if ( ! V_12 ) {
F_2 ( & V_2 -> V_15 , L_5 ) ;
V_14 = - V_26 ;
goto V_27;
}
V_8 -> V_28 = V_12 -> V_29 ;
V_8 -> V_30 = F_11 ( V_12 ) ;
V_8 -> V_31 = F_12 ( V_12 -> V_29 , F_11 ( V_12 ) ) ;
if ( ! V_8 -> V_31 ) {
F_2 ( & V_2 -> V_15 , L_6 ) ;
V_14 = - V_19 ;
goto V_27;
}
V_13 = F_13 ( V_2 , 0 ) ;
if ( ! V_13 ) {
F_2 ( & V_2 -> V_15 , L_7 ) ;
V_14 = - V_32 ;
goto V_33;
}
if ( V_4 -> V_34 )
V_4 -> V_34 ( V_2 , V_35 ) ;
V_10 = F_14 ( V_8 ) ;
V_10 -> V_36 = V_8 -> V_31 ;
V_10 -> V_31 = V_8 -> V_31 +
F_15 ( V_10 , F_16 ( & V_10 -> V_36 -> V_37 ) ) ;
F_17 ( V_10 , L_8 ) ;
F_18 ( V_10 , L_8 ) ;
V_10 -> V_38 = F_16 ( & V_10 -> V_36 -> V_38 ) ;
V_14 = F_19 ( V_8 , V_13 , V_39 | V_40 ) ;
if ( V_14 ) {
F_2 ( & V_2 -> V_15 , L_9 ) ;
goto V_33;
}
F_20 ( V_2 , V_6 ) ;
return 0 ;
V_33:
F_21 ( V_8 -> V_31 ) ;
V_27:
F_22 ( V_6 -> V_22 ) ;
V_24:
F_23 ( V_6 -> V_22 ) ;
V_23:
F_24 ( V_8 ) ;
V_21:
F_25 ( V_6 ) ;
return V_14 ;
}
static int T_2 F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_15 . V_16 ;
struct V_5 * V_6 = F_27 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_28 ( V_8 ) ;
if ( V_4 && V_4 -> V_41 )
V_4 -> V_41 ( V_2 , V_35 ) ;
F_21 ( V_8 -> V_31 ) ;
F_22 ( V_6 -> V_22 ) ;
F_23 ( V_6 -> V_22 ) ;
F_24 ( V_8 ) ;
F_25 ( V_6 ) ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_27 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_42 -> V_43 )
V_8 -> V_42 -> V_43 ( V_8 ) ;
}
