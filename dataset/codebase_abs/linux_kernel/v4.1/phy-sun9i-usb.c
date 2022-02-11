static void F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 , V_5 ;
V_4 = V_6 | V_7 |
V_8 | V_9 |
V_10 ;
if ( V_2 -> type == V_11 )
V_4 |= V_12 | V_13 |
V_14 | V_15 ;
V_5 = F_2 ( V_2 -> V_16 ) ;
if ( V_3 )
V_5 |= V_4 ;
else
V_5 &= ~ V_4 ;
F_3 ( V_5 , V_2 -> V_16 ) ;
}
static int F_4 ( struct V_2 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
int V_18 ;
V_18 = F_6 ( V_2 -> V_19 ) ;
if ( V_18 )
goto V_20;
V_18 = F_6 ( V_2 -> V_21 ) ;
if ( V_18 )
goto V_22;
V_18 = F_7 ( V_2 -> V_23 ) ;
if ( V_18 )
goto V_24;
F_1 ( V_2 , 1 ) ;
return 0 ;
V_24:
F_8 ( V_2 -> V_21 ) ;
V_22:
F_8 ( V_2 -> V_19 ) ;
V_20:
return V_18 ;
}
static int F_9 ( struct V_2 * V_17 )
{
struct V_1 * V_2 = F_5 ( V_17 ) ;
F_1 ( V_2 , 0 ) ;
F_10 ( V_2 -> V_23 ) ;
F_8 ( V_2 -> V_21 ) ;
F_8 ( V_2 -> V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_29 * V_30 = V_28 -> V_31 ;
struct V_32 * V_32 ;
struct V_33 * V_34 ;
V_2 = F_12 ( V_28 , sizeof( * V_2 ) , V_35 ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> type = F_13 ( V_30 ) ;
if ( V_2 -> type == V_11 ) {
V_2 -> V_19 = F_14 ( V_28 , L_1 ) ;
if ( F_15 ( V_2 -> V_19 ) ) {
F_16 ( V_28 , L_2 ) ;
return F_17 ( V_2 -> V_19 ) ;
}
V_2 -> V_21 = F_14 ( V_28 , L_3 ) ;
if ( F_15 ( V_2 -> V_19 ) ) {
F_16 ( V_28 , L_4 ) ;
return F_17 ( V_2 -> V_19 ) ;
}
V_2 -> V_23 = F_18 ( V_28 , L_5 ) ;
if ( F_15 ( V_2 -> V_23 ) ) {
F_16 ( V_28 , L_6 ) ;
return F_17 ( V_2 -> V_23 ) ;
}
} else {
V_2 -> V_19 = F_14 ( V_28 , L_7 ) ;
if ( F_15 ( V_2 -> V_19 ) ) {
F_16 ( V_28 , L_8 ) ;
return F_17 ( V_2 -> V_19 ) ;
}
V_2 -> V_23 = F_18 ( V_28 , L_7 ) ;
if ( F_15 ( V_2 -> V_23 ) ) {
F_16 ( V_28 , L_6 ) ;
return F_17 ( V_2 -> V_23 ) ;
}
}
V_34 = F_19 ( V_26 , V_37 , 0 ) ;
V_2 -> V_16 = F_20 ( V_28 , V_34 ) ;
if ( F_15 ( V_2 -> V_16 ) )
return F_17 ( V_2 -> V_16 ) ;
V_2 -> V_2 = F_21 ( V_28 , NULL , & V_38 ) ;
if ( F_15 ( V_2 -> V_2 ) ) {
F_16 ( V_28 , L_9 ) ;
return F_17 ( V_2 -> V_2 ) ;
}
F_22 ( V_2 -> V_2 , V_2 ) ;
V_32 = F_23 ( V_28 , V_39 ) ;
return F_24 ( V_32 ) ;
}
