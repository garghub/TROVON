static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( V_3 -> V_4 , 1 ) ;
F_3 ( V_3 -> V_5 , 1 ) ;
if ( V_3 -> V_6 )
F_4 ( V_3 -> V_7 , V_8 ,
V_3 -> V_6 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( V_3 -> V_4 , 0 ) ;
F_3 ( V_3 -> V_5 , 0 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 , enum V_9 V_10 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_11 ;
V_11 = F_7 ( V_3 -> V_7 , V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
switch ( V_10 ) {
case V_13 :
V_11 |= ( V_14
| V_15
| V_16
| V_17 ) ;
F_4 ( V_3 -> V_7 , V_12 , V_11 ) ;
V_11 |= V_18 ;
break;
case V_19 :
V_11 &= ~ ( V_18
| V_16
| V_17 ) ;
F_4 ( V_3 -> V_7 , V_12 , V_11 ) ;
V_11 &= ~ V_14 ;
break;
default:
return 0 ;
}
return F_4 ( V_3 -> V_7 , V_12 , V_11 ) ;
}
static int F_8 ( struct V_7 * V_7 )
{
struct V_2 * V_3 ;
T_1 V_20 , V_21 ;
V_3 = F_9 ( & V_7 -> V_22 , sizeof( * V_3 ) , V_23 ) ;
if ( ! V_3 )
return - V_24 ;
V_3 -> V_4 = F_10 ( & V_7 -> V_22 , L_1 ,
V_25 ) ;
if ( F_11 ( V_3 -> V_4 ) )
return F_12 ( V_3 -> V_4 ) ;
F_3 ( V_3 -> V_4 , 1 ) ;
V_3 -> V_5 = F_10 ( & V_7 -> V_22 , L_2 ,
V_25 ) ;
if ( F_11 ( V_3 -> V_5 ) )
return F_12 ( V_3 -> V_5 ) ;
F_3 ( V_3 -> V_5 , 1 ) ;
F_13 ( & V_7 -> V_22 , L_3 , & V_20 ) ;
V_21 = V_20 << V_26 ;
F_13 ( & V_7 -> V_22 , L_4 , & V_20 ) ;
V_21 |= V_20 << V_27 ;
F_13 ( & V_7 -> V_22 , L_5 , & V_20 ) ;
V_21 |= V_20 << V_28 ;
if ( V_21 ) {
F_4 ( V_7 , V_8 , V_21 ) ;
V_3 -> V_6 = V_21 ;
}
V_3 -> V_1 = F_14 ( V_7 , & V_29 ) ;
if ( F_11 ( V_3 -> V_1 ) )
return F_12 ( V_3 -> V_1 ) ;
V_3 -> V_7 = V_7 ;
F_15 ( V_3 -> V_1 , V_3 ) ;
F_16 ( V_7 , V_3 ) ;
return 0 ;
}
static void F_17 ( struct V_7 * V_7 )
{
struct V_2 * V_3 = F_18 ( V_7 ) ;
F_19 ( V_7 , V_3 -> V_1 ) ;
}
