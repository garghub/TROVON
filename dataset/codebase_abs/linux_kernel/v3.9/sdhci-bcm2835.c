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
struct V_11 * V_12 = V_10 -> V_13 ;
T_1 V_14 = ( V_4 == V_15 ) ? V_12 -> V_16 :
F_4 ( V_2 , V_4 & ~ 3 ) ;
T_1 V_17 = ( V_4 >> 1 ) & 1 ;
T_1 V_18 = V_17 * 16 ;
T_1 V_19 = 0xffff << V_18 ;
T_1 V_20 = ( V_14 & ~ V_19 ) | ( V_3 << V_18 ) ;
if ( V_4 == V_21 )
V_12 -> V_16 = V_20 ;
else
F_1 ( V_2 , V_20 , V_4 & ~ 3 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_3 = F_4 ( V_2 , ( V_4 & ~ 3 ) ) ;
T_1 V_17 = ( V_4 >> 1 ) & 1 ;
T_1 V_18 = V_17 * 16 ;
T_1 V_22 = ( V_3 >> V_18 ) & 0xffff ;
return V_22 ;
}
static void F_9 ( struct V_1 * V_2 , T_3 V_3 , int V_4 )
{
T_1 V_14 = F_4 ( V_2 , V_4 & ~ 3 ) ;
T_1 V_23 = V_4 & 3 ;
T_1 V_24 = V_23 * 8 ;
T_1 V_19 = 0xff << V_24 ;
T_1 V_20 = ( V_14 & ~ V_19 ) | ( V_3 << V_24 ) ;
F_1 ( V_2 , V_20 , V_4 & ~ 3 ) ;
}
static T_3 F_10 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_3 = F_4 ( V_2 , ( V_4 & ~ 3 ) ) ;
T_1 V_23 = V_4 & 3 ;
T_1 V_24 = V_23 * 8 ;
T_1 V_25 = ( V_3 >> V_24 ) & 0xff ;
return V_25 ;
}
unsigned int F_11 ( struct V_1 * V_2 )
{
return V_26 ;
}
static int F_12 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
int V_29 ;
V_2 = F_13 ( V_28 , & V_30 ) ;
if ( F_14 ( V_2 ) )
return F_15 ( V_2 ) ;
V_12 = F_16 ( & V_28 -> V_31 , sizeof( * V_12 ) ,
V_32 ) ;
if ( ! V_12 ) {
F_17 ( F_18 ( V_2 -> V_33 ) ,
L_1 ) ;
return - V_34 ;
}
V_10 = F_7 ( V_2 ) ;
V_10 -> V_13 = V_12 ;
V_10 -> V_35 = F_19 ( & V_28 -> V_31 , NULL ) ;
if ( F_14 ( V_10 -> V_35 ) ) {
V_29 = F_15 ( V_10 -> V_35 ) ;
goto V_36;
}
return F_20 ( V_2 ) ;
V_36:
F_21 ( V_28 ) ;
return V_29 ;
}
static int F_22 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_23 ( V_28 ) ;
int V_37 = ( F_5 ( V_2 -> V_5 + V_38 ) == 0xffffffff ) ;
F_24 ( V_2 , V_37 ) ;
F_21 ( V_28 ) ;
return 0 ;
}
