static int F_1 ( void )
{
return ( F_2 ( V_1 ) & V_2 ) ? 0 : 1 ;
}
static int F_3 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_5 * V_7 ;
T_1 V_8 ;
T_1 V_9 ;
int V_10 ;
F_4 ( & V_11 ) ;
V_6 = F_5 ( & V_4 -> V_12 , L_1 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( & V_4 -> V_12 , L_2 ) ;
return F_8 ( V_6 ) ;
}
V_10 = F_9 ( V_6 ) ;
if ( V_10 ) {
F_10 ( V_6 ) ;
return V_10 ;
}
if ( F_1 () )
return 0 ;
F_11 ( F_2 ( V_13 ) | V_14 ,
V_13 ) ;
V_8 = F_2 ( V_15 ) & ~ V_16 ;
V_7 = F_5 ( & V_4 -> V_12 , L_3 ) ;
if ( V_7 && ! F_6 ( V_7 ) ) {
switch ( F_12 ( V_7 ) ) {
case 12 * V_17 :
V_8 |= V_18 ;
break;
case 24 * V_17 :
V_8 |= V_19 ;
break;
default:
case 48 * V_17 :
break;
}
F_10 ( V_7 ) ;
}
F_11 ( V_8 , V_15 ) ;
F_11 ( ( F_2 ( V_20 ) | V_21 ) , V_20 ) ;
F_11 ( ( F_2 ( V_1 ) & ~ V_22 ) ,
V_1 ) ;
F_11 ( ( F_2 ( V_1 ) & ~ V_23 ) , V_1 ) ;
V_9 = F_2 ( V_24 ) | V_25 |
V_26 ;
F_11 ( V_9 , V_24 ) ;
F_13 ( 10 ) ;
V_9 &= ~ ( V_25 | V_26 ) ;
F_11 ( V_9 , V_24 ) ;
F_13 ( 80 ) ;
F_14 ( V_6 ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_10 ;
if ( F_16 ( & V_11 ) > 0 )
return 0 ;
V_6 = F_5 ( & V_4 -> V_12 , L_1 ) ;
if ( F_6 ( V_6 ) ) {
F_7 ( & V_4 -> V_12 , L_2 ) ;
return F_8 ( V_6 ) ;
}
V_10 = F_9 ( V_6 ) ;
if ( V_10 ) {
F_10 ( V_6 ) ;
return V_10 ;
}
F_11 ( ( F_2 ( V_1 ) | V_2 ) ,
V_1 ) ;
F_11 ( F_2 ( V_13 ) & ~ V_14 ,
V_13 ) ;
F_14 ( V_6 ) ;
F_10 ( V_6 ) ;
return 0 ;
}
int F_17 ( struct V_3 * V_4 , int type )
{
if ( type == V_27 )
return F_3 ( V_4 ) ;
return - V_28 ;
}
int F_18 ( struct V_3 * V_4 , int type )
{
if ( type == V_27 )
return F_15 ( V_4 ) ;
return - V_28 ;
}
