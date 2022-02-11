static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 ;
T_1 V_10 , V_11 ;
int V_12 ;
V_2 -> V_13 = F_2 ( V_6 ) ;
V_9 = F_3 ( V_6 , L_1 ) ;
if ( F_4 ( V_9 ) ) {
F_5 ( V_4 , L_2 ) ;
return F_6 ( V_9 ) ;
}
V_12 = F_7 ( V_6 , L_1 , 1 , & V_10 ) ;
if ( V_12 ) {
F_5 ( V_4 , L_3 ) ;
return - V_14 ;
}
V_12 = F_7 ( V_6 , L_1 , 2 , & V_11 ) ;
if ( V_12 ) {
F_5 ( V_4 , L_4 ) ;
return - V_14 ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_15 = V_2 -> V_13 ;
T_1 V_10 = V_2 -> V_10 ;
T_1 V_11 = V_2 -> V_11 ;
T_1 V_16 , V_17 ;
switch ( V_15 ) {
case V_18 :
V_17 = V_19 ;
break;
case V_20 :
case V_21 :
V_17 = V_22 ;
break;
default:
F_9 ( V_2 -> V_4 , L_5 , V_15 ) ;
return - V_14 ;
}
F_10 ( V_9 , V_10 , & V_16 ) ;
V_16 &= ~ ( V_23 << V_11 ) ;
V_16 |= V_17 << V_11 ;
F_11 ( V_9 , V_10 , V_16 ) ;
return 0 ;
}
static void * F_12 ( struct V_24 * V_25 )
{
struct V_3 * V_4 = & V_25 -> V_4 ;
int V_12 ;
struct V_1 * V_2 ;
V_2 = F_13 ( V_4 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return F_14 ( - V_27 ) ;
V_12 = F_1 ( V_2 , V_4 ) ;
if ( V_12 ) {
F_9 ( V_4 , L_6 ) ;
return F_14 ( V_12 ) ;
}
V_12 = F_8 ( V_2 ) ;
if ( V_12 ) {
F_9 ( V_4 , L_7 , V_12 ) ;
return F_14 ( V_12 ) ;
}
return V_2 ;
}
