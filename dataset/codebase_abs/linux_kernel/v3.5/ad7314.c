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
V_12 = ( V_12 << 6 ) >> 6 ;
return sprintf ( V_11 , L_2 , 250 * V_12 ) ;
case V_17 :
case V_18 :
V_12 = V_3 & V_19 ;
V_12 = ( V_12 << 2 ) >> 2 ;
return sprintf ( V_11 , L_2 ,
F_8 ( V_12 * 3125 , 100 ) ) ;
default:
return - V_20 ;
}
}
static int T_3 F_9 ( struct V_21 * V_4 )
{
int V_3 ;
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_22 ) ;
if ( V_2 == NULL ) {
V_3 = - V_23 ;
goto V_24;
}
F_11 ( & V_4 -> V_7 , V_2 ) ;
V_3 = F_12 ( & V_4 -> V_7 . V_25 , & V_26 ) ;
if ( V_3 < 0 )
goto V_27;
V_2 -> V_28 = F_13 ( & V_4 -> V_7 ) ;
if ( F_14 ( V_2 -> V_28 ) ) {
V_3 = F_15 ( V_2 -> V_28 ) ;
goto V_29;
}
V_2 -> V_4 = V_4 ;
return 0 ;
V_29:
F_16 ( & V_4 -> V_7 . V_25 , & V_26 ) ;
V_27:
F_17 ( V_2 ) ;
V_24:
return V_3 ;
}
static int T_4 F_18 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_6 ( & V_4 -> V_7 ) ;
F_19 ( V_2 -> V_28 ) ;
F_16 ( & V_4 -> V_7 . V_25 , & V_26 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
