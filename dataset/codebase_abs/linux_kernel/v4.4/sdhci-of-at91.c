static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
const struct V_5 * V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
unsigned int V_13 , V_14 ;
unsigned int V_15 , V_16 ;
unsigned int V_17 , V_18 ;
int V_19 ;
V_4 = F_2 ( V_20 , & V_2 -> V_21 ) ;
if ( ! V_4 )
return - V_22 ;
V_6 = V_4 -> V_23 ;
V_12 = F_3 ( & V_2 -> V_21 , sizeof( * V_12 ) , V_24 ) ;
if ( ! V_12 ) {
F_4 ( & V_2 -> V_21 , L_1 ) ;
return - V_25 ;
}
V_12 -> V_26 = F_5 ( & V_2 -> V_21 , L_2 ) ;
if ( F_6 ( V_12 -> V_26 ) ) {
F_4 ( & V_2 -> V_21 , L_3 ) ;
return F_7 ( V_12 -> V_26 ) ;
}
V_12 -> V_27 = F_5 ( & V_2 -> V_21 , L_4 ) ;
if ( F_6 ( V_12 -> V_27 ) ) {
F_4 ( & V_2 -> V_21 , L_5 ) ;
return F_7 ( V_12 -> V_27 ) ;
}
V_12 -> V_28 = F_5 ( & V_2 -> V_21 , L_6 ) ;
if ( F_6 ( V_12 -> V_28 ) ) {
F_4 ( & V_2 -> V_21 , L_7 ) ;
return F_7 ( V_12 -> V_28 ) ;
}
V_8 = F_8 ( V_2 , V_6 , 0 ) ;
if ( F_6 ( V_8 ) )
return F_7 ( V_8 ) ;
F_9 ( V_12 -> V_27 ) ;
V_13 = F_10 ( V_8 -> V_29 + V_30 ) ;
V_14 = F_10 ( V_8 -> V_29 + V_31 ) ;
V_15 = ( V_13 & V_32 ) >> V_33 ;
V_16 = ( V_14 & V_34 ) >> V_35 ;
V_17 = V_15 * 1000000 * ( V_16 + 1 ) ;
V_19 = F_11 ( V_12 -> V_28 , V_17 ) ;
if ( V_19 < 0 ) {
F_4 ( & V_2 -> V_21 , L_8 ) ;
goto V_36;
}
V_18 = F_12 ( V_12 -> V_28 ) ;
if ( V_18 != V_17 ) {
V_16 = V_18 / ( V_15 * 1000000 ) - 1 ;
V_14 &= ( ~ V_34 ) ;
V_14 |= ( ( V_16 << V_35 ) & V_34 ) ;
F_13 ( V_37 | V_38 , V_8 -> V_29 + V_39 ) ;
F_13 ( V_14 , V_8 -> V_29 + V_31 ) ;
F_13 ( 0 , V_8 -> V_29 + V_39 ) ;
F_14 ( & V_2 -> V_21 , L_9 ,
V_16 , V_18 ) ;
}
F_9 ( V_12 -> V_26 ) ;
F_9 ( V_12 -> V_28 ) ;
V_10 = F_15 ( V_8 ) ;
V_10 -> V_12 = V_12 ;
V_19 = F_16 ( V_8 -> V_40 ) ;
if ( V_19 )
goto V_41;
F_17 ( V_2 ) ;
V_19 = F_18 ( V_8 ) ;
if ( V_19 )
goto V_41;
return 0 ;
V_41:
F_19 ( V_12 -> V_28 ) ;
F_19 ( V_12 -> V_26 ) ;
V_36:
F_19 ( V_12 -> V_27 ) ;
F_20 ( V_2 ) ;
return V_19 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_22 ( V_2 ) ;
struct V_9 * V_10 = F_15 ( V_8 ) ;
struct V_11 * V_12 = V_10 -> V_12 ;
F_23 ( V_2 ) ;
F_19 ( V_12 -> V_28 ) ;
F_19 ( V_12 -> V_27 ) ;
F_19 ( V_12 -> V_26 ) ;
return 0 ;
}
