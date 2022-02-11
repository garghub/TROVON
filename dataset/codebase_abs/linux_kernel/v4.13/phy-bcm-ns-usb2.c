static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
void T_1 * V_6 = V_3 -> V_6 ;
T_2 V_7 , V_8 , V_9 , V_10 ;
int V_11 = 0 ;
V_11 = F_3 ( V_3 -> V_12 ) ;
if ( V_11 < 0 ) {
F_4 ( V_5 , L_1 , V_11 ) ;
goto V_13;
}
V_7 = F_5 ( V_3 -> V_12 ) ;
if ( ! V_7 ) {
F_4 ( V_5 , L_2 ) ;
V_11 = - V_14 ;
goto V_15;
}
V_8 = F_6 ( V_6 + V_16 ) ;
if ( V_8 & V_17 ) {
V_10 = V_8 ;
V_10 &= V_17 ;
V_10 >>= V_18 ;
} else {
V_10 = 1 << 3 ;
}
V_9 = ( 1920000000 * V_10 ) / V_7 ;
F_7 ( 0x0000ea68 , V_6 + V_19 ) ;
V_8 &= ~ V_20 ;
V_8 |= V_9 << V_21 ;
F_7 ( V_8 , V_6 + V_16 ) ;
F_7 ( 0x00000000 , V_6 + V_19 ) ;
V_15:
F_8 ( V_3 -> V_12 ) ;
V_13:
return V_11 ;
}
static int F_9 ( struct V_22 * V_23 )
{
struct V_4 * V_5 = & V_23 -> V_5 ;
struct V_2 * V_3 ;
struct V_24 * V_25 ;
struct V_26 * V_26 ;
V_3 = F_10 ( & V_23 -> V_5 , sizeof( * V_3 ) , V_27 ) ;
if ( ! V_3 )
return - V_28 ;
V_3 -> V_5 = V_5 ;
V_25 = F_11 ( V_23 , V_29 , L_3 ) ;
V_3 -> V_6 = F_12 ( V_5 , V_25 ) ;
if ( F_13 ( V_3 -> V_6 ) ) {
F_4 ( V_5 , L_4 ) ;
return F_14 ( V_3 -> V_6 ) ;
}
V_3 -> V_12 = F_15 ( V_5 , L_5 ) ;
if ( F_13 ( V_3 -> V_12 ) ) {
F_4 ( V_5 , L_6 ) ;
return F_14 ( V_3 -> V_12 ) ;
}
V_3 -> V_1 = F_16 ( V_5 , NULL , & V_30 ) ;
if ( F_13 ( V_3 -> V_1 ) )
return F_14 ( V_3 -> V_1 ) ;
F_17 ( V_3 -> V_1 , V_3 ) ;
F_18 ( V_23 , V_3 ) ;
V_26 = F_19 ( V_5 , V_31 ) ;
return F_20 ( V_26 ) ;
}
