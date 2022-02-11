static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
T_1 V_7 ;
V_6 = F_2 ( V_5 , ( V_8 * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 ) {
F_3 ( & V_5 -> V_9 , L_1 ) ;
return V_6 ;
}
* V_3 = F_4 ( ( T_1 ) V_7 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
T_1 V_7 = F_6 ( V_3 ) ;
V_6 = F_7 ( V_5 , ( V_8 * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_6 < 0 )
F_3 ( & V_5 -> V_9 , L_2 ) ;
return V_6 ;
}
static T_2 F_8 ( struct V_10 * V_9 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_15 ) ;
if ( V_2 -> V_16 )
return sprintf ( V_13 , L_3 ) ;
else
return sprintf ( V_13 , L_4 ) ;
}
static T_2 F_11 ( struct V_10 * V_9 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_3 V_17 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_15 ) ;
T_1 V_16 = 0 ;
int V_6 ;
if ( ! strcmp ( V_13 , L_5 ) )
V_16 = V_18 ;
V_6 = F_5 ( V_2 , V_16 ) ;
if ( V_6 )
return - V_19 ;
V_2 -> V_16 = V_16 ;
return V_17 ;
}
static T_2 F_12 ( struct V_10 * V_9 ,
struct V_11 * V_12 ,
char * V_13 )
{
return sprintf ( V_13 , L_6 ) ;
}
static T_2 F_13 ( struct V_10 * V_9 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_1 * V_2 = F_10 ( V_15 ) ;
T_1 V_3 ;
char V_20 = ' ' ;
int V_6 ;
if ( V_2 -> V_16 ) {
V_6 = F_5 ( V_2 , 0 ) ;
if ( V_6 )
return - V_19 ;
}
V_6 = F_1 ( V_2 , & V_3 ) ;
if ( V_6 )
return - V_19 ;
if ( V_2 -> V_16 )
F_5 ( V_2 , V_2 -> V_16 ) ;
if ( strcmp ( V_15 -> V_21 , L_7 ) ) {
V_3 = ( V_3 & V_22 ) >>
V_23 ;
if ( V_3 & V_24 ) {
V_3 = ( V_24 << 1 ) - V_3 ;
V_20 = '-' ;
}
return sprintf ( V_13 , L_8 , V_20 ,
V_3 >> V_25 ,
( V_3 & V_26 ) * 25 ) ;
} else {
V_3 &= V_27 ;
if ( V_3 & V_28 ) {
V_3 = ( V_28 << 1 ) - V_3 ;
V_20 = '-' ;
}
return sprintf ( V_13 , L_9 , V_20 ,
V_3 >> V_29 ,
( V_3 & V_30 ) * 3125 ) ;
}
}
static int T_4 F_14 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_14 * V_31 ;
int V_6 = 0 ;
V_31 = F_15 ( sizeof( * V_2 ) ) ;
if ( V_31 == NULL ) {
V_6 = - V_32 ;
goto V_33;
}
V_2 = F_10 ( V_31 ) ;
F_16 ( & V_5 -> V_9 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_31 -> V_21 = F_17 ( V_5 ) -> V_21 ;
V_31 -> V_9 . V_34 = & V_5 -> V_9 ;
V_31 -> V_35 = & V_36 ;
V_6 = F_18 ( V_31 ) ;
if ( V_6 )
goto V_37;
V_15 ( & V_5 -> V_9 , L_10 ,
V_31 -> V_21 ) ;
return 0 ;
V_37:
F_19 ( V_31 ) ;
V_33:
return V_6 ;
}
static int T_5 F_20 ( struct V_4 * V_5 )
{
struct V_14 * V_31 = F_9 ( & V_5 -> V_9 ) ;
F_16 ( & V_5 -> V_9 , NULL ) ;
F_21 ( V_31 ) ;
F_19 ( V_31 ) ;
return 0 ;
}
static T_6 int F_22 ( void )
{
return F_23 ( & V_38 ) ;
}
static T_7 void F_24 ( void )
{
F_25 ( & V_38 ) ;
}
