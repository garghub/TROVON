static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 ;
F_2 ( V_6 , L_1 , V_8 ) ;
V_7 = F_3 ( V_4 , V_9 ,
V_10 , V_11 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 , L_2 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_5 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_6 . V_16 ;
struct V_14 * V_17 , * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 ;
int V_7 ;
if ( ! V_15 ) {
F_4 ( & V_13 -> V_6 , L_3 ) ;
return - V_25 ;
}
V_20 = F_6 ( & V_13 -> V_6 , sizeof( * V_20 ) , V_26 ) ;
V_24 = F_6 ( & V_13 -> V_6 , sizeof( * V_24 ) , V_26 ) ;
V_22 = F_6 ( & V_13 -> V_6 , sizeof( * V_22 ) , V_26 ) ;
if ( ! V_22 || ! V_20 || ! V_24 ) {
V_7 = - V_27 ;
goto V_28;
}
V_20 -> V_6 = & V_13 -> V_6 ;
V_20 -> V_29 = V_30 ;
V_20 -> V_31 = V_22 ;
V_20 -> V_32 = 1 ;
V_20 -> V_33 = V_34 ;
V_20 -> V_35 = F_7 ( V_34 ) ;
V_22 -> V_36 = L_4 ;
V_22 -> V_37 = L_5 ;
V_22 -> V_38 = L_6 ;
V_22 -> V_39 = F_1 ;
V_22 -> V_40 = V_41 | V_42
| V_43 ;
V_7 = F_8 ( V_20 , L_7 ) ;
if ( V_7 ) {
F_4 ( & V_13 -> V_6 , L_8 ) ;
goto V_28;
}
V_7 = F_9 ( V_20 , L_9 ) ;
if ( V_7 ) {
F_4 ( & V_13 -> V_6 , L_10 ) ;
goto V_28;
}
V_17 = F_10 ( V_15 , L_11 , 0 ) ;
if ( ! V_17 ) {
F_4 ( & V_13 -> V_6 , L_12 ) ;
V_7 = - V_25 ;
goto V_28;
}
V_22 -> V_44 = V_17 ;
V_18 = F_10 ( V_15 , L_13 , 0 ) ;
if ( ! V_18 ) {
F_4 ( & V_13 -> V_6 , L_14 ) ;
V_7 = - V_25 ;
goto V_28;
}
V_22 -> V_45 = V_18 ;
V_22 -> V_46 = V_18 ;
V_24 -> V_47 = F_11 ( V_18 , L_15 ) ;
V_7 = F_12 ( V_24 -> V_47 ) ;
if ( V_7 != 0 ) {
F_4 ( & V_13 -> V_6 ,
L_16 ,
V_7 , V_24 -> V_47 ) ;
goto V_28;
}
F_13 ( V_17 ) ;
F_13 ( V_18 ) ;
F_14 ( V_13 , V_20 ) ;
V_7 = F_15 ( V_20 ) ;
if ( V_7 ) {
F_4 ( & V_13 -> V_6 ,
L_17 ) ;
goto V_48;
}
F_2 ( & V_13 -> V_6 , L_18 , V_8 ) ;
return V_7 ;
V_48:
F_16 ( V_24 -> V_47 ) ;
V_28:
return V_7 ;
}
static int F_17 ( struct V_12 * V_13 )
{
struct V_19 * V_20 = F_18 ( V_13 ) ;
struct V_23 * V_24 = V_20 -> V_49 ;
F_19 ( V_20 ) ;
F_16 ( V_24 -> V_47 ) ;
return 0 ;
}
