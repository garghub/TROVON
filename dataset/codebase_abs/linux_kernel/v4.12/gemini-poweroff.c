static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
T_2 V_5 ;
V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_8 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
V_5 = F_2 ( V_4 -> V_6 + V_9 ) ;
V_5 &= 0x70U ;
switch ( V_5 ) {
case V_10 :
F_4 ( V_4 -> V_11 , L_1 ) ;
F_5 ( true ) ;
break;
case V_12 :
F_4 ( V_4 -> V_11 , L_2 ) ;
F_5 ( true ) ;
break;
case V_13 :
F_4 ( V_4 -> V_11 , L_3 ) ;
F_5 ( true ) ;
break;
default:
F_4 ( V_4 -> V_11 , L_4 ) ;
break;
}
return V_14 ;
}
static void F_6 ( void )
{
struct V_3 * V_4 = V_15 ;
T_2 V_5 ;
F_7 ( V_4 -> V_11 , L_5 ) ;
V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_16 | V_8 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
V_5 &= ~ V_16 ;
V_5 |= V_17 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
}
static int F_8 ( struct V_18 * V_19 )
{
struct V_20 * V_11 = & V_19 -> V_11 ;
struct V_21 * V_22 ;
struct V_3 * V_4 ;
T_2 V_5 ;
int V_1 ;
int V_23 ;
V_4 = F_9 ( V_11 , sizeof( * V_4 ) , V_24 ) ;
if ( ! V_4 )
return - V_25 ;
V_22 = F_10 ( V_19 , V_26 , 0 ) ;
V_4 -> V_6 = F_11 ( V_11 , V_22 ) ;
if ( F_12 ( V_4 -> V_6 ) )
return F_13 ( V_4 -> V_6 ) ;
V_1 = F_14 ( V_19 , 0 ) ;
if ( ! V_1 )
return - V_27 ;
V_4 -> V_11 = V_11 ;
V_5 = F_2 ( V_4 -> V_6 + V_28 ) ;
V_5 &= 0xFFFFFF00U ;
if ( V_5 != V_29 ) {
F_15 ( V_11 , L_6 ,
V_5 ) ;
return - V_30 ;
}
V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_8 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
V_23 = F_16 ( V_11 , V_1 , F_1 , 0 ,
L_7 , V_4 ) ;
if ( V_23 )
return V_23 ;
V_31 = F_6 ;
V_15 = V_4 ;
V_5 = F_2 ( V_4 -> V_6 + V_7 ) ;
V_5 |= V_16 ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_4 ( V_11 , L_8 ) ;
return 0 ;
}
