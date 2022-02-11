static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 -> V_4 , ( V_5 * ) & V_2 -> V_6 , sizeof( V_2 -> V_6 ) ) ;
if ( V_3 < 0 ) {
F_3 ( & V_2 -> V_4 -> V_7 , L_1 ) ;
return V_3 ;
}
return F_4 ( V_2 -> V_6 ) ;
}
static T_1 F_5 ( struct V_8 * V_7 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_2 V_12 ;
int V_3 ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
switch ( F_7 ( V_2 -> V_4 ) -> V_13 ) {
case V_14 :
V_12 = ( V_3 & V_15 ) >> V_16 ;
V_12 = F_8 ( V_12 , 9 ) ;
return sprintf ( V_11 , L_2 , 250 * V_12 ) ;
case V_17 :
case V_18 :
V_12 = V_3 & V_19 ;
V_12 = F_8 ( V_12 , 13 ) ;
return sprintf ( V_11 , L_2 ,
F_9 ( V_12 * 3125 , 100 ) ) ;
default:
return - V_20 ;
}
}
static int F_10 ( struct V_21 * V_4 )
{
struct V_1 * V_2 ;
struct V_8 * V_22 ;
V_2 = F_11 ( & V_4 -> V_7 , sizeof( * V_2 ) , V_23 ) ;
if ( V_2 == NULL )
return - V_24 ;
V_2 -> V_4 = V_4 ;
V_22 = F_12 ( & V_4 -> V_7 ,
V_4 -> V_25 ,
V_2 , V_26 ) ;
return F_13 ( V_22 ) ;
}
