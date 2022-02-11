int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 ;
}
int F_3 ( struct V_1 * V_2 ,
T_1 V_3 ,
int V_7 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( F_4 ( V_3 ) ) {
case V_8 :
switch ( F_5 ( V_3 ) ) {
case V_9 :
if ( F_6 ( V_3 ) ==
V_10 )
V_5 -> V_6 = V_7 ;
else
return - V_11 ;
break;
default:
return - V_11 ;
}
default:
return - V_11 ;
}
return 0 ;
}
int F_7 ( struct V_1 * V_2 ,
T_1 V_3 ,
int * V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
* V_12 = V_5 -> V_13 ;
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
T_1 V_3 ,
int V_12 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_5 -> V_13 = V_12 ;
return 0 ;
}
static T_2 F_9 ( int V_14 , void * V_15 )
{
struct V_1 * V_2 = V_15 ;
F_10 ( V_2 ,
F_11 ( V_8 , 0 , 0 ,
V_10 ,
V_9 , 0 , 0 , 0 ) ,
F_12 () ) ;
return V_16 ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_17 ;
V_5 -> V_18 = F_14 () ;
if ( V_5 -> V_18 < 0 ) {
V_17 = V_5 -> V_18 ;
goto V_19;
}
V_17 = F_15 ( V_5 -> V_18 ,
NULL ,
& F_9 ,
V_20 ,
L_1 ,
V_2 ) ;
if ( V_17 < 0 )
goto V_21;
return 0 ;
V_21:
F_16 ( V_5 -> V_18 ) ;
V_19:
return V_17 ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_18 ( V_5 -> V_18 , V_2 ) ;
F_16 ( V_5 -> V_18 ) ;
return 0 ;
}
