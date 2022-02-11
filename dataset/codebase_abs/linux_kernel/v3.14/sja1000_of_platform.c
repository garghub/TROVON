static T_1 F_1 ( const struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( const struct V_1 * V_2 ,
int V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_6 ( V_7 ) ;
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_10 * V_11 = V_7 -> V_9 . V_12 ;
struct V_13 V_14 ;
F_8 ( V_9 ) ;
F_9 ( V_9 ) ;
F_10 ( V_2 -> V_4 ) ;
F_11 ( V_9 -> V_15 ) ;
F_12 ( V_11 , 0 , & V_14 ) ;
F_13 ( V_14 . V_16 , F_14 ( & V_14 ) ) ;
return 0 ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_9 . V_12 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_13 V_14 ;
T_2 V_17 ;
int V_18 , V_15 , V_19 ;
void T_3 * V_20 ;
V_18 = F_12 ( V_11 , 0 , & V_14 ) ;
if ( V_18 ) {
F_16 ( & V_7 -> V_9 , L_1 ) ;
return V_18 ;
}
V_19 = F_14 ( & V_14 ) ;
if ( ! F_17 ( V_14 . V_16 , V_19 , V_21 ) ) {
F_16 ( & V_7 -> V_9 , L_2 , & V_14 ) ;
return - V_22 ;
}
V_20 = F_18 ( V_14 . V_16 , V_19 ) ;
if ( ! V_20 ) {
F_16 ( & V_7 -> V_9 , L_3 , & V_14 ) ;
V_18 = - V_23 ;
goto V_24;
}
V_15 = F_19 ( V_11 , 0 ) ;
if ( V_15 == 0 ) {
F_16 ( & V_7 -> V_9 , L_4 ) ;
V_18 = - V_25 ;
goto V_26;
}
V_9 = F_20 ( 0 ) ;
if ( ! V_9 ) {
V_18 = - V_23 ;
goto V_27;
}
V_2 = F_7 ( V_9 ) ;
V_2 -> V_28 = F_1 ;
V_2 -> V_29 = F_3 ;
V_18 = F_21 ( V_11 , L_5 , & V_17 ) ;
if ( ! V_18 )
V_2 -> V_30 . clock . V_31 = V_17 / 2 ;
else
V_2 -> V_30 . clock . V_31 = V_32 ;
V_18 = F_21 ( V_11 , L_6 , & V_17 ) ;
if ( ! V_18 )
V_2 -> V_33 |= V_17 & V_34 ;
else
V_2 -> V_33 |= V_35 ;
V_18 = F_21 ( V_11 , L_7 , & V_17 ) ;
if ( ! V_18 )
V_2 -> V_33 |= ( V_17 << V_36 ) & V_37 ;
else
V_2 -> V_33 |= V_38 ;
V_18 = F_21 ( V_11 , L_8 , & V_17 ) ;
if ( ! V_18 && V_17 ) {
T_2 V_39 = V_2 -> V_30 . clock . V_31 * 2 / V_17 ;
if ( V_39 > 1 )
V_2 -> V_40 |= V_39 / 2 - 1 ;
else
V_2 -> V_40 |= V_41 ;
} else {
V_2 -> V_40 |= V_42 ;
}
if ( ! F_22 ( V_11 , L_9 ) )
V_2 -> V_40 |= V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_4 = V_20 ;
V_9 -> V_15 = V_15 ;
F_23 ( & V_7 -> V_9 ,
L_10 ,
V_2 -> V_4 , V_9 -> V_15 , V_2 -> V_30 . clock . V_31 ,
V_2 -> V_33 , V_2 -> V_40 ) ;
F_24 ( V_7 , V_9 ) ;
F_25 ( V_9 , & V_7 -> V_9 ) ;
V_18 = F_26 ( V_9 ) ;
if ( V_18 ) {
F_16 ( & V_7 -> V_9 , L_11 ,
V_21 , V_18 ) ;
goto V_46;
}
return 0 ;
V_46:
F_9 ( V_9 ) ;
V_27:
F_11 ( V_15 ) ;
V_26:
F_10 ( V_20 ) ;
V_24:
F_13 ( V_14 . V_16 , V_19 ) ;
return V_18 ;
}
