static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_10 , V_11 ;
int V_12 ;
V_2 -> V_13 = F_2 ( V_4 ,
V_14 ) ;
if ( F_3 ( V_2 -> V_13 ) ) {
F_4 ( V_4 , L_1 ) ;
return - V_15 ;
}
V_2 -> V_16 = F_5 ( V_6 ) ;
V_9 = F_6 ( V_6 , L_2 ) ;
if ( F_3 ( V_9 ) ) {
F_4 ( V_4 , L_3 ) ;
return F_7 ( V_9 ) ;
}
V_12 = F_8 ( V_6 , L_2 , 1 , & V_10 ) ;
if ( V_12 ) {
F_4 ( V_4 , L_4 ) ;
return - V_15 ;
}
V_12 = F_8 ( V_6 , L_2 , 2 , & V_11 ) ;
if ( V_12 ) {
F_4 ( V_4 , L_5 ) ;
return - V_15 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_17 = V_2 -> V_16 ;
T_1 V_10 = V_2 -> V_10 ;
T_1 V_11 = V_2 -> V_11 ;
T_1 V_18 , V_19 ;
switch ( V_17 ) {
case V_20 :
V_19 = V_21 ;
break;
case V_22 :
case V_23 :
V_19 = V_24 ;
break;
default:
F_10 ( V_2 -> V_4 , L_6 , V_17 ) ;
return - V_15 ;
}
F_11 ( V_9 , V_10 , & V_18 ) ;
V_18 &= ~ ( V_25 << V_11 ) ;
V_18 |= V_19 << V_11 ;
F_12 ( V_9 , V_10 , V_18 ) ;
return 0 ;
}
static void * F_13 ( struct V_26 * V_27 )
{
struct V_3 * V_4 = & V_27 -> V_4 ;
int V_12 ;
struct V_1 * V_2 ;
V_2 = F_14 ( V_4 , sizeof( * V_2 ) , V_28 ) ;
if ( ! V_2 )
return F_15 ( - V_29 ) ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_10 ( V_4 , L_7 ) ;
return F_15 ( V_12 ) ;
}
V_12 = F_9 ( V_2 ) ;
if ( V_12 ) {
F_10 ( V_4 , L_8 , V_12 ) ;
return F_15 ( V_12 ) ;
}
return V_2 ;
}
static void F_16 ( struct V_26 * V_27 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
if ( V_2 -> V_13 )
F_17 ( V_2 -> V_13 ) ;
}
static int F_18 ( struct V_26 * V_27 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_31 * V_32 = F_19 ( V_27 ) ;
struct V_33 * V_34 = NULL ;
int V_12 = 0 ;
if ( V_32 )
V_34 = F_20 ( V_32 ) ;
if ( V_2 -> V_13 )
F_17 ( V_2 -> V_13 ) ;
V_12 = F_9 ( V_2 ) ;
if ( V_2 -> V_13 )
F_21 ( V_2 -> V_13 ) ;
if ( V_34 && V_34 -> V_35 )
F_22 ( V_34 -> V_35 ) ;
return V_12 ;
}
