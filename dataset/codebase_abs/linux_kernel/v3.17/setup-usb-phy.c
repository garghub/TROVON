static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
T_1 V_5 ;
F_2 ( F_3 ( V_6 ) | V_7 , V_6 ) ;
V_5 = F_3 ( V_8 ) & ~ V_9 ;
V_4 = F_4 ( & V_2 -> V_10 , L_1 ) ;
if ( V_4 && ! F_5 ( V_4 ) ) {
switch ( F_6 ( V_4 ) ) {
case 12 * V_11 :
V_5 |= V_12 ;
break;
case 24 * V_11 :
V_5 |= V_13 ;
break;
default:
case 48 * V_11 :
break;
}
F_7 ( V_4 ) ;
}
F_2 ( V_5 | V_14 , V_8 ) ;
F_2 ( ( F_3 ( V_15 ) & ~ V_16 ) , V_15 ) ;
F_8 ( 1 ) ;
F_2 ( V_17 | V_18 | V_19 ,
V_20 ) ;
F_9 ( 20 ) ;
F_2 ( 0 , V_20 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
F_2 ( ( F_3 ( V_15 ) | V_21 |
V_22 ) , V_15 ) ;
F_2 ( F_3 ( V_6 ) & ~ V_7 , V_6 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 , int type )
{
if ( type == V_23 )
return F_1 ( V_2 ) ;
return - V_24 ;
}
int F_12 ( struct V_1 * V_2 , int type )
{
if ( type == V_23 )
return F_10 ( V_2 ) ;
return - V_24 ;
}
