static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
V_2 -> V_6 = 1 ;
V_5 = F_3 ( V_2 ) ;
if ( V_5 )
return V_5 ;
F_4 ( V_4 , 0 ) ;
return 0 ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
int V_15 , V_16 ;
unsigned int V_17 ;
struct V_18 * V_19 ;
struct V_20 * V_11 = & V_8 -> V_11 ;
struct V_3 * V_4 ;
F_6 ( & V_8 -> V_11 , L_1 ) ;
if ( ! V_10 ) {
F_7 ( V_11 , L_2 ) ;
return - V_21 ;
}
V_15 = F_8 ( V_8 , 0 ) ;
V_2 = F_9 ( & V_22 , V_11 , F_10 ( V_11 ) ) ;
if ( ! V_2 )
return - V_23 ;
V_19 = F_11 ( & V_8 -> V_11 , sizeof( * V_19 ) , V_24 ) ;
if ( ! V_19 ) {
V_16 = - V_23 ;
goto V_25;
}
V_14 = F_12 ( V_8 , V_26 , 0 ) ;
if ( ! V_14 ) {
F_7 ( V_11 , L_3 ) ;
V_16 = - V_27 ;
goto V_25;
}
V_2 -> V_28 = V_14 -> V_29 ;
V_2 -> V_30 = F_13 ( V_14 ) ;
V_2 -> V_31 = F_14 ( & V_8 -> V_11 , V_14 ) ;
if ( ! V_2 -> V_31 ) {
F_7 ( V_11 , L_4 ) ;
V_16 = - V_32 ;
goto V_25;
}
V_19 -> V_33 = F_15 ( & V_8 -> V_11 , L_5 ) ;
if ( F_16 ( V_19 -> V_33 ) ) {
V_16 = F_17 ( V_19 -> V_33 ) ;
goto V_25;
}
F_18 ( V_19 -> V_33 ) ;
V_19 -> V_34 = F_15 ( & V_8 -> V_11 , L_6 ) ;
if ( F_16 ( V_19 -> V_34 ) ) {
V_16 = F_17 ( V_19 -> V_34 ) ;
goto V_35;
}
F_18 ( V_19 -> V_34 ) ;
V_19 -> V_36 = F_15 ( & V_8 -> V_11 , L_7 ) ;
if ( F_16 ( V_19 -> V_36 ) )
V_19 -> V_36 = NULL ;
if ( V_19 -> V_36 )
F_18 ( V_19 -> V_36 ) ;
if ( V_10 -> V_37 ) {
V_16 = V_10 -> V_37 ( V_8 ) ;
if ( V_16 ) {
F_7 ( V_11 , L_8 ) ;
goto V_38;
}
F_19 ( 10 ) ;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_39 = V_2 -> V_31 + 0x100 ;
V_4 -> V_31 = V_2 -> V_31 + 0x100 +
F_20 ( V_4 , F_21 ( V_4 , & V_4 -> V_39 -> V_40 ) ) ;
F_22 ( V_4 , V_10 -> V_41 , & V_4 -> V_31 -> V_42 [ 0 ] ) ;
F_23 ( 10 ) ;
if ( V_10 -> V_43 ) {
V_10 -> V_43 -> V_44 = V_2 -> V_31 + V_45 ;
V_16 = F_24 ( V_10 -> V_43 ) ;
if ( V_16 ) {
F_7 ( V_11 , L_9 ) ;
V_16 = - V_27 ;
goto V_46;
}
V_16 = F_25 ( V_10 -> V_43 -> V_43 , 1 ) ;
if ( V_16 ) {
F_7 ( V_11 , L_10 ) ;
goto V_46;
}
}
V_19 -> V_2 = V_2 ;
F_26 ( V_8 , V_19 ) ;
V_16 = F_27 ( V_2 , V_15 , V_47 ) ;
if ( V_16 )
goto V_46;
if ( V_10 -> V_43 ) {
if ( F_28 () || F_29 () ) {
V_17 = F_30 ( V_10 -> V_43 ,
V_48 ) ;
V_17 |= V_49 ;
V_16 = F_31 ( V_10 -> V_43 , V_17 ,
V_48 ) ;
if ( V_16 ) {
F_7 ( V_11 , L_11 ) ;
goto V_46;
}
}
}
return 0 ;
V_46:
if ( V_10 && V_10 -> exit )
V_10 -> exit ( V_8 ) ;
V_38:
if ( V_19 -> V_36 )
F_32 ( V_19 -> V_36 ) ;
F_32 ( V_19 -> V_34 ) ;
V_35:
F_32 ( V_19 -> V_33 ) ;
V_25:
F_33 ( V_2 ) ;
return V_16 ;
}
static int T_1 F_34 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 ;
struct V_18 * V_19 = F_35 ( V_8 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_10 && V_10 -> exit )
V_10 -> exit ( V_8 ) ;
if ( V_10 -> V_43 )
F_36 ( V_10 -> V_43 ) ;
F_37 ( V_2 ) ;
F_33 ( V_2 ) ;
F_26 ( V_8 , NULL ) ;
F_32 ( V_19 -> V_33 ) ;
F_32 ( V_19 -> V_34 ) ;
if ( V_19 -> V_36 )
F_32 ( V_19 -> V_36 ) ;
return 0 ;
}
static void F_38 ( struct V_7 * V_8 )
{
struct V_18 * V_19 = F_35 ( V_8 ) ;
struct V_1 * V_2 = V_19 -> V_2 ;
if ( V_2 -> V_50 -> V_51 )
V_2 -> V_50 -> V_51 ( V_2 ) ;
}
