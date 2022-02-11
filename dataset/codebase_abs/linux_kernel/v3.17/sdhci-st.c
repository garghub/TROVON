static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
switch ( V_3 ) {
case V_5 :
V_4 = F_2 ( V_2 -> V_6 + V_3 ) ;
V_4 &= ~ V_7 ;
break;
default:
V_4 = F_2 ( V_2 -> V_6 + V_3 ) ;
}
return V_4 ;
}
static int F_3 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
int V_4 = 0 ;
T_2 V_13 ;
V_12 = F_4 ( & V_9 -> V_14 , L_1 ) ;
if ( F_5 ( V_12 ) ) {
F_6 ( & V_9 -> V_14 , L_2 ) ;
return F_7 ( V_12 ) ;
}
V_2 = F_8 ( V_9 , & V_15 , 0 ) ;
if ( F_5 ( V_2 ) ) {
F_6 ( & V_9 -> V_14 , L_3 ) ;
return F_7 ( V_2 ) ;
}
V_4 = F_9 ( V_2 -> V_16 ) ;
if ( V_4 ) {
F_6 ( & V_9 -> V_14 , L_4 ) ;
return V_4 ;
}
F_10 ( V_12 ) ;
V_11 = F_11 ( V_2 ) ;
V_11 -> V_12 = V_12 ;
V_4 = F_12 ( V_2 ) ;
if ( V_4 ) {
F_6 ( & V_9 -> V_14 , L_5 ) ;
goto V_17;
}
F_13 ( V_9 , V_2 ) ;
V_13 = F_14 ( ( V_2 -> V_6 + V_18 ) ) ;
F_15 ( & V_9 -> V_14 , L_6 ,
( ( V_13 & V_19 ) >> V_20 ) ,
( ( V_13 & V_21 ) >>
V_22 ) ) ;
return 0 ;
V_17:
F_16 ( V_12 ) ;
F_17 ( V_9 ) ;
return V_4 ;
}
static int F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_19 ( V_9 ) ;
struct V_10 * V_11 = F_11 ( V_2 ) ;
F_16 ( V_11 -> V_12 ) ;
return F_20 ( V_9 ) ;
}
static int F_21 ( struct V_23 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ) ;
struct V_10 * V_11 = F_11 ( V_2 ) ;
int V_4 = F_23 ( V_2 ) ;
if ( V_4 )
goto V_24;
F_16 ( V_11 -> V_12 ) ;
V_24:
return V_4 ;
}
static int F_24 ( struct V_23 * V_14 )
{
struct V_1 * V_2 = F_22 ( V_14 ) ;
struct V_10 * V_11 = F_11 ( V_2 ) ;
F_10 ( V_11 -> V_12 ) ;
return F_25 ( V_2 ) ;
}
