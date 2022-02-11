static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
int V_4 ;
V_4 = F_2 ( V_2 -> V_5 , ( V_6 * ) & V_2 -> V_7 , sizeof( V_2 -> V_7 ) ) ;
if ( V_4 < 0 ) {
F_3 ( & V_2 -> V_5 -> V_8 , L_1 ) ;
return V_4 ;
}
* V_3 = F_4 ( V_2 -> V_7 ) ;
return V_4 ;
}
static T_2 F_5 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_1 * V_2 = F_6 ( V_8 ) ;
T_1 V_3 ;
int V_4 ;
V_4 = F_1 ( V_2 , & V_3 ) ;
if ( V_4 < 0 )
return V_4 ;
switch ( F_7 ( V_2 -> V_5 ) -> V_13 ) {
case V_14 :
V_3 = ( V_3 & V_15 ) >> V_16 ;
V_3 = ( V_3 << 6 ) >> 6 ;
return sprintf ( V_12 , L_2 , 250 * V_3 ) ;
case V_17 :
case V_18 :
V_3 &= V_19 ;
V_3 = ( V_3 << 2 ) >> 2 ;
return sprintf ( V_12 , L_2 ,
F_8 ( V_3 * 3125 , 100 ) ) ;
default:
return - V_20 ;
}
}
static int T_3 F_9 ( struct V_21 * V_5 )
{
int V_4 ;
struct V_1 * V_2 ;
V_2 = F_10 ( sizeof( * V_2 ) , V_22 ) ;
if ( V_2 == NULL ) {
V_4 = - V_23 ;
goto V_24;
}
F_11 ( & V_5 -> V_8 , V_2 ) ;
V_4 = F_12 ( & V_5 -> V_8 . V_25 , & V_26 ) ;
if ( V_4 < 0 )
goto V_27;
V_2 -> V_28 = F_13 ( & V_5 -> V_8 ) ;
if ( F_14 ( V_2 -> V_28 ) ) {
V_4 = F_15 ( V_2 -> V_28 ) ;
goto V_29;
}
return 0 ;
V_29:
F_16 ( & V_5 -> V_8 . V_25 , & V_26 ) ;
V_27:
F_17 ( V_2 ) ;
V_24:
return V_4 ;
}
static int T_4 F_18 ( struct V_21 * V_5 )
{
struct V_1 * V_2 = F_6 ( & V_5 -> V_8 ) ;
F_19 ( V_2 -> V_28 ) ;
F_16 ( & V_5 -> V_8 . V_25 , & V_26 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static T_5 int F_20 ( void )
{
return F_21 ( & V_30 ) ;
}
static T_6 void F_22 ( void )
{
F_23 ( & V_30 ) ;
}
