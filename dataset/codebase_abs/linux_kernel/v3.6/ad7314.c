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
static T_1 F_9 ( struct V_8 * V_7 ,
struct V_9 * V_21 , char * V_11 )
{
return sprintf ( V_11 , L_3 , F_10 ( V_7 ) -> V_22 ) ;
}
static int T_3 F_11 ( struct V_23 * V_4 )
{
int V_3 ;
struct V_1 * V_2 ;
V_2 = F_12 ( sizeof( * V_2 ) , V_24 ) ;
if ( V_2 == NULL ) {
V_3 = - V_25 ;
goto V_26;
}
F_13 ( & V_4 -> V_7 , V_2 ) ;
V_3 = F_14 ( & V_4 -> V_7 . V_27 , & V_28 ) ;
if ( V_3 < 0 )
goto V_29;
V_2 -> V_30 = F_15 ( & V_4 -> V_7 ) ;
if ( F_16 ( V_2 -> V_30 ) ) {
V_3 = F_17 ( V_2 -> V_30 ) ;
goto V_31;
}
V_2 -> V_4 = V_4 ;
return 0 ;
V_31:
F_18 ( & V_4 -> V_7 . V_27 , & V_28 ) ;
V_29:
F_19 ( V_2 ) ;
V_26:
return V_3 ;
}
static int T_4 F_20 ( struct V_23 * V_4 )
{
struct V_1 * V_2 = F_6 ( & V_4 -> V_7 ) ;
F_21 ( V_2 -> V_30 ) ;
F_18 ( & V_4 -> V_7 . V_27 , & V_28 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
