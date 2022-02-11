static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
F_3 ( V_6 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_3 = F_5 ( V_2 -> V_5 + V_4 ) ;
if ( V_4 == V_7 )
V_3 |= V_8 ;
return V_3 ;
}
static void F_6 ( struct V_1 * V_2 , T_2 V_3 , int V_4 )
{
struct V_9 * V_10 = F_7 ( V_2 ) ;
struct V_11 * V_12 = F_8 ( V_10 ) ;
T_1 V_13 = ( V_4 == V_14 ) ? V_12 -> V_15 :
F_4 ( V_2 , V_4 & ~ 3 ) ;
T_1 V_16 = ( V_4 >> 1 ) & 1 ;
T_1 V_17 = V_16 * 16 ;
T_1 V_18 = 0xffff << V_17 ;
T_1 V_19 = ( V_13 & ~ V_18 ) | ( V_3 << V_17 ) ;
if ( V_4 == V_20 )
V_12 -> V_15 = V_19 ;
else
F_1 ( V_2 , V_19 , V_4 & ~ 3 ) ;
}
static T_2 F_9 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_3 = F_4 ( V_2 , ( V_4 & ~ 3 ) ) ;
T_1 V_16 = ( V_4 >> 1 ) & 1 ;
T_1 V_17 = V_16 * 16 ;
T_1 V_21 = ( V_3 >> V_17 ) & 0xffff ;
return V_21 ;
}
static void F_10 ( struct V_1 * V_2 , T_3 V_3 , int V_4 )
{
T_1 V_13 = F_4 ( V_2 , V_4 & ~ 3 ) ;
T_1 V_22 = V_4 & 3 ;
T_1 V_23 = V_22 * 8 ;
T_1 V_18 = 0xff << V_23 ;
T_1 V_19 = ( V_13 & ~ V_18 ) | ( V_3 << V_23 ) ;
F_1 ( V_2 , V_19 , V_4 & ~ 3 ) ;
}
static T_3 F_11 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_3 = F_4 ( V_2 , ( V_4 & ~ 3 ) ) ;
T_1 V_22 = V_4 & 3 ;
T_1 V_23 = V_22 * 8 ;
T_1 V_24 = ( V_3 >> V_23 ) & 0xff ;
return V_24 ;
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
return V_25 ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
int V_28 ;
V_2 = F_14 ( V_27 , & V_29 ,
sizeof( * V_12 ) ) ;
if ( F_15 ( V_2 ) )
return F_16 ( V_2 ) ;
V_10 = F_7 ( V_2 ) ;
V_10 -> V_30 = F_17 ( & V_27 -> V_31 , NULL ) ;
if ( F_15 ( V_10 -> V_30 ) ) {
V_28 = F_16 ( V_10 -> V_30 ) ;
goto V_32;
}
V_28 = F_18 ( V_10 -> V_30 ) ;
if ( V_28 ) {
F_19 ( & V_27 -> V_31 , L_1 ) ;
goto V_32;
}
V_28 = F_20 ( V_2 ) ;
if ( V_28 )
goto V_33;
return 0 ;
V_33:
F_21 ( V_10 -> V_30 ) ;
V_32:
F_22 ( V_27 ) ;
return V_28 ;
}
