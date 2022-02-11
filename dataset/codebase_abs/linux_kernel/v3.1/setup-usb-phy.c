static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_3 * V_5 ;
T_1 V_6 ;
T_1 V_7 ;
int V_8 ;
V_4 = F_2 ( & V_2 -> V_9 , L_1 ) ;
if ( F_3 ( V_4 ) ) {
F_4 ( & V_2 -> V_9 , L_2 ) ;
return F_5 ( V_4 ) ;
}
V_8 = F_6 ( V_4 ) ;
if ( V_8 ) {
F_7 ( V_4 ) ;
return V_8 ;
}
F_8 ( F_9 ( V_10 ) | V_11 ,
V_10 ) ;
V_6 = F_9 ( V_12 ) & ~ V_13 ;
V_5 = F_2 ( & V_2 -> V_9 , L_3 ) ;
if ( V_5 && ! F_3 ( V_5 ) ) {
switch ( F_10 ( V_5 ) ) {
case 12 * V_14 :
V_6 |= V_15 ;
break;
case 24 * V_14 :
V_6 |= V_16 ;
break;
default:
case 48 * V_14 :
break;
}
F_7 ( V_5 ) ;
}
F_8 ( V_6 , V_12 ) ;
F_8 ( ( F_9 ( V_17 ) | V_18 ) , V_17 ) ;
F_8 ( ( F_9 ( V_19 ) & ~ V_20 ) ,
V_19 ) ;
F_8 ( ( F_9 ( V_19 ) & ~ V_21 ) , V_19 ) ;
V_7 = F_9 ( V_22 ) | V_23 |
V_24 ;
F_8 ( V_7 , V_22 ) ;
F_11 ( 10 ) ;
V_7 &= ~ ( V_23 | V_24 ) ;
F_8 ( V_7 , V_22 ) ;
F_11 ( 80 ) ;
F_12 ( V_4 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_8 ;
V_4 = F_2 ( & V_2 -> V_9 , L_1 ) ;
if ( F_3 ( V_4 ) ) {
F_4 ( & V_2 -> V_9 , L_2 ) ;
return F_5 ( V_4 ) ;
}
V_8 = F_6 ( V_4 ) ;
if ( V_8 ) {
F_7 ( V_4 ) ;
return V_8 ;
}
F_8 ( ( F_9 ( V_19 ) | V_25 ) ,
V_19 ) ;
F_8 ( F_9 ( V_10 ) & ~ V_11 ,
V_10 ) ;
F_12 ( V_4 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , int type )
{
if ( type == V_26 )
return F_1 ( V_2 ) ;
return - V_27 ;
}
int F_15 ( struct V_1 * V_2 , int type )
{
if ( type == V_26 )
return F_13 ( V_2 ) ;
return - V_27 ;
}
