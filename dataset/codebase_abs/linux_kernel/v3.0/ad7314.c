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
struct V_1 * V_2 = V_15 -> V_16 ;
if ( V_2 -> V_17 )
return sprintf ( V_13 , L_3 ) ;
else
return sprintf ( V_13 , L_4 ) ;
}
static T_2 F_10 ( struct V_10 * V_9 ,
struct V_11 * V_12 ,
const char * V_13 ,
T_3 V_18 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_15 -> V_16 ;
T_1 V_17 = 0 ;
int V_6 ;
if ( ! strcmp ( V_13 , L_5 ) )
V_17 = V_19 ;
V_6 = F_5 ( V_2 , V_17 ) ;
if ( V_6 )
return - V_20 ;
V_2 -> V_17 = V_17 ;
return V_18 ;
}
static T_2 F_11 ( struct V_10 * V_9 ,
struct V_11 * V_12 ,
char * V_13 )
{
return sprintf ( V_13 , L_6 ) ;
}
static T_2 F_12 ( struct V_10 * V_9 ,
struct V_11 * V_12 ,
char * V_13 )
{
struct V_14 * V_15 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_15 -> V_16 ;
T_1 V_3 ;
char V_21 = ' ' ;
int V_6 ;
if ( V_2 -> V_17 ) {
V_6 = F_5 ( V_2 , 0 ) ;
if ( V_6 )
return - V_20 ;
}
V_6 = F_1 ( V_2 , & V_3 ) ;
if ( V_6 )
return - V_20 ;
if ( V_2 -> V_17 )
F_5 ( V_2 , V_2 -> V_17 ) ;
if ( strcmp ( V_15 -> V_22 , L_7 ) ) {
V_3 = ( V_3 & V_23 ) >>
V_24 ;
if ( V_3 & V_25 ) {
V_3 = ( V_25 << 1 ) - V_3 ;
V_21 = '-' ;
}
return sprintf ( V_13 , L_8 , V_21 ,
V_3 >> V_26 ,
( V_3 & V_27 ) * 25 ) ;
} else {
V_3 &= V_28 ;
if ( V_3 & V_29 ) {
V_3 = ( V_29 << 1 ) - V_3 ;
V_21 = '-' ;
}
return sprintf ( V_13 , L_9 , V_21 ,
V_3 >> V_30 ,
( V_3 & V_31 ) * 3125 ) ;
}
}
static int T_4 F_13 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_6 = 0 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_32 ) ;
if ( V_2 == NULL )
return - V_33 ;
F_15 ( & V_5 -> V_9 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_2 -> V_34 = F_16 ( 0 ) ;
if ( V_2 -> V_34 == NULL ) {
V_6 = - V_33 ;
goto V_35;
}
V_2 -> V_34 -> V_22 = F_17 ( V_5 ) -> V_22 ;
V_2 -> V_34 -> V_9 . V_36 = & V_5 -> V_9 ;
V_2 -> V_34 -> V_37 = & V_38 ;
V_2 -> V_34 -> V_16 = ( void * ) V_2 ;
V_6 = F_18 ( V_2 -> V_34 ) ;
if ( V_6 )
goto V_39;
V_15 ( & V_5 -> V_9 , L_10 ,
V_2 -> V_34 -> V_22 ) ;
return 0 ;
V_39:
F_19 ( V_2 -> V_34 ) ;
V_35:
F_20 ( V_2 ) ;
return V_6 ;
}
static int T_5 F_21 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_9 ( & V_5 -> V_9 ) ;
struct V_14 * V_34 = V_2 -> V_34 ;
F_15 ( & V_5 -> V_9 , NULL ) ;
F_22 ( V_34 ) ;
F_19 ( V_2 -> V_34 ) ;
F_20 ( V_2 ) ;
return 0 ;
}
static T_6 int F_23 ( void )
{
return F_24 ( & V_40 ) ;
}
static T_7 void F_25 ( void )
{
F_26 ( & V_40 ) ;
}
