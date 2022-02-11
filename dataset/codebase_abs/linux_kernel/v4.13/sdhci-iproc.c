static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 + V_3 ) ;
F_3 ( L_1 ,
F_4 ( V_2 -> V_6 ) , V_3 , V_4 ) ;
return V_4 ;
}
static T_2 F_5 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_1 ( V_2 , ( V_3 & ~ 3 ) ) ;
T_2 V_7 = V_4 >> F_6 ( V_3 ) & 0xffff ;
return V_7 ;
}
static T_3 F_7 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 = F_1 ( V_2 , ( V_3 & ~ 3 ) ) ;
T_3 V_8 = V_4 >> F_6 ( V_3 ) & 0xff ;
return V_8 ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_4 , int V_3 )
{
F_3 ( L_2 ,
F_4 ( V_2 -> V_6 ) , V_3 , V_4 ) ;
F_9 ( V_4 , V_2 -> V_5 + V_3 ) ;
if ( V_2 -> clock <= 400000 ) {
if ( V_2 -> clock )
F_10 ( ( 4 * 1000000 + V_2 -> clock - 1 ) / V_2 -> clock ) ;
else
F_10 ( 10 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , T_2 V_4 , int V_3 )
{
struct V_9 * V_10 = F_12 ( V_2 ) ;
struct V_11 * V_12 = F_13 ( V_10 ) ;
T_1 V_13 = F_6 ( V_3 ) ;
T_1 V_14 = 0xffff << V_13 ;
T_1 V_15 , V_16 ;
if ( V_3 == V_17 ) {
if ( V_12 -> V_18 != 0 ) {
F_8 ( V_2 , V_12 -> V_18 ,
V_19 ) ;
V_12 -> V_18 = 0 ;
}
V_15 = V_12 -> V_20 ;
} else if ( V_3 == V_19 || V_3 == V_21 ) {
V_15 = V_12 -> V_18 ;
} else {
V_15 = F_1 ( V_2 , ( V_3 & ~ 3 ) ) ;
}
V_16 = ( V_15 & ~ V_14 ) | ( V_4 << V_13 ) ;
if ( V_3 == V_22 ) {
V_12 -> V_20 = V_16 ;
} else if ( V_3 == V_19 || V_3 == V_21 ) {
V_12 -> V_18 = V_16 ;
} else {
F_8 ( V_2 , V_16 , V_3 & ~ 3 ) ;
}
}
static void F_14 ( struct V_1 * V_2 , T_3 V_4 , int V_3 )
{
T_1 V_15 = F_1 ( V_2 , ( V_3 & ~ 3 ) ) ;
T_1 V_23 = F_6 ( V_3 ) ;
T_1 V_14 = 0xff << V_23 ;
T_1 V_16 = ( V_15 & ~ V_14 ) | ( V_4 << V_23 ) ;
F_8 ( V_2 , V_16 , V_3 & ~ 3 ) ;
}
static int F_15 ( struct V_24 * V_25 )
{
const struct V_26 * V_27 ;
const struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
int V_30 ;
V_27 = F_16 ( V_31 , & V_25 -> V_32 ) ;
if ( ! V_27 )
return - V_33 ;
V_29 = V_27 -> V_34 ;
V_2 = F_17 ( V_25 , V_29 -> V_35 , sizeof( * V_12 ) ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
V_10 = F_12 ( V_2 ) ;
V_12 = F_13 ( V_10 ) ;
V_12 -> V_34 = V_29 ;
F_20 ( V_2 -> V_6 ) ;
F_21 ( V_25 ) ;
V_2 -> V_6 -> V_36 |= V_12 -> V_34 -> V_37 ;
V_10 -> V_38 = F_22 ( & V_25 -> V_32 , NULL ) ;
if ( F_18 ( V_10 -> V_38 ) ) {
V_30 = F_19 ( V_10 -> V_38 ) ;
goto V_39;
}
V_30 = F_23 ( V_10 -> V_38 ) ;
if ( V_30 ) {
F_24 ( & V_25 -> V_32 , L_3 ) ;
goto V_39;
}
if ( V_12 -> V_34 -> V_35 -> V_40 & V_41 ) {
V_2 -> V_36 = V_12 -> V_34 -> V_36 ;
V_2 -> V_42 = V_12 -> V_34 -> V_42 ;
}
V_30 = F_25 ( V_2 ) ;
if ( V_30 )
goto V_43;
return 0 ;
V_43:
F_26 ( V_10 -> V_38 ) ;
V_39:
F_27 ( V_25 ) ;
return V_30 ;
}
