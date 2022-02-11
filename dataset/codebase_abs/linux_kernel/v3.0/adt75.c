static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 , V_8 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_9 , L_1 ) ;
return V_7 ;
}
if ( V_3 == V_10 || V_3 == V_11 )
V_8 = 1 ;
else
V_8 = 2 ;
V_7 = F_4 ( V_6 , V_4 , V_8 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_9 , L_2 ) ;
return V_7 ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
if ( V_3 == V_10 || V_3 == V_11 )
V_7 = F_6 ( V_6 , V_3 , V_4 ) ;
else
V_7 = F_7 ( V_6 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_9 , L_3 ) ;
return V_7 ;
}
static T_2 F_8 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
if ( V_2 -> V_19 & V_20 )
return sprintf ( V_15 , L_4 ) ;
else
return sprintf ( V_15 , L_5 ) ;
}
static T_2 F_10 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_3 V_8 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_7 ;
T_1 V_19 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
V_19 = V_2 -> V_19 & ~ V_20 ;
if ( ! strcmp ( V_15 , L_6 ) )
V_19 |= V_20 ;
V_7 = F_5 ( V_2 , V_10 , V_19 ) ;
if ( V_7 )
return - V_21 ;
V_2 -> V_19 = V_19 ;
return V_7 ;
}
static T_2 F_11 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_7 ) ;
}
static T_2 F_12 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
return sprintf ( V_15 , L_8 , ! ! ( V_2 -> V_19 & V_11 ) ) ;
}
static T_2 F_13 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_3 V_8 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned long V_4 = 0 ;
int V_7 ;
T_1 V_19 ;
V_7 = F_14 ( V_15 , 10 , & V_4 ) ;
if ( V_7 )
return - V_22 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
V_19 = V_2 -> V_19 & ~ V_11 ;
if ( V_4 )
V_19 |= V_11 ;
V_7 = F_5 ( V_2 , V_10 , V_19 ) ;
if ( V_7 )
return - V_21 ;
V_2 -> V_19 = V_19 ;
return V_7 ;
}
static T_2 F_15 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_4 V_4 ;
char V_23 = ' ' ;
int V_7 ;
if ( V_2 -> V_19 & V_20 ) {
F_3 ( V_9 , L_9 ) ;
return - V_21 ;
}
if ( V_2 -> V_19 & V_11 ) {
V_7 = F_2 ( V_2 -> V_6 , V_11 ) ;
if ( V_7 )
return - V_21 ;
}
V_7 = F_1 ( V_2 , V_24 , ( T_1 * ) & V_4 ) ;
if ( V_7 )
return - V_21 ;
V_4 = F_16 ( V_4 ) >> V_25 ;
if ( V_4 & V_26 ) {
V_4 = ( V_26 << 1 ) - V_4 ;
V_23 = '-' ;
}
return sprintf ( V_15 , L_10 , V_23 ,
( V_4 >> V_27 ) ,
( V_4 & V_28 ) * 625 ) ;
}
static T_5 F_17 ( int V_29 , void * V_30 )
{
F_18 ( V_30 , 0 ,
V_31 ,
F_19 () ) ;
return V_32 ;
}
static T_2 F_20 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
if ( V_2 -> V_19 & V_33 )
return sprintf ( V_15 , L_11 ) ;
else
return sprintf ( V_15 , L_12 ) ;
}
static T_2 F_21 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_3 V_8 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_7 ;
T_1 V_19 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
V_19 = V_2 -> V_19 & ~ V_33 ;
if ( strcmp ( V_15 , L_13 ) != 0 )
V_19 |= V_33 ;
V_7 = F_5 ( V_2 , V_10 , V_19 ) ;
if ( V_7 )
return - V_21 ;
V_2 -> V_19 = V_19 ;
return V_7 ;
}
static T_2 F_22 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
return sprintf ( V_15 , L_14 ) ;
}
static T_2 F_23 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
return sprintf ( V_15 , L_8 , ! ! ( V_2 -> V_19 & V_34 ) ) ;
}
static T_2 F_24 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_3 V_8 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned long V_4 = 0 ;
int V_7 ;
T_1 V_19 ;
V_7 = F_14 ( V_15 , 10 , & V_4 ) ;
if ( V_7 )
return - V_22 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
V_19 = V_2 -> V_19 & ~ V_34 ;
if ( V_4 )
V_19 |= V_34 ;
V_7 = F_5 ( V_2 , V_10 , V_19 ) ;
if ( V_7 )
return - V_21 ;
V_2 -> V_19 = V_19 ;
return V_7 ;
}
static T_2 F_25 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
return sprintf ( V_15 , L_8 , ( V_2 -> V_19 & V_35 ) >>
V_36 ) ;
}
static T_2 F_26 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_3 V_8 )
{
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
unsigned long V_4 ;
int V_7 ;
T_1 V_19 ;
V_7 = F_14 ( V_15 , 10 , & V_4 ) ;
if ( V_7 || V_4 > 3 )
return - V_22 ;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 )
return - V_21 ;
V_19 = V_2 -> V_19 & ~ V_35 ;
V_19 |= ( V_4 << V_36 ) ;
V_7 = F_5 ( V_2 , V_10 , V_19 ) ;
if ( V_7 )
return - V_21 ;
V_2 -> V_19 = V_19 ;
return V_7 ;
}
static inline T_2 F_27 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
char * V_15 )
{
struct V_37 * V_38 = F_28 ( V_14 ) ;
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
T_4 V_4 ;
char V_23 = ' ' ;
int V_7 ;
V_7 = F_1 ( V_2 , V_38 -> V_39 , ( T_1 * ) & V_4 ) ;
if ( V_7 )
return - V_21 ;
V_4 = F_16 ( V_4 ) >> V_25 ;
if ( V_4 & V_26 ) {
V_4 = ( V_26 << 1 ) - V_4 ;
V_23 = '-' ;
}
return sprintf ( V_15 , L_10 , V_23 ,
( V_4 >> V_27 ) ,
( V_4 & V_28 ) * 625 ) ;
}
static inline T_2 F_29 ( struct V_12 * V_9 ,
struct V_13 * V_14 ,
const char * V_15 ,
T_3 V_8 )
{
struct V_37 * V_38 = F_28 ( V_14 ) ;
struct V_16 * V_17 = F_9 ( V_9 ) ;
struct V_1 * V_2 = V_17 -> V_18 ;
long V_40 , V_41 ;
T_4 V_4 ;
char * V_42 ;
int V_7 ;
V_42 = strchr ( V_15 , '.' ) ;
V_7 = F_30 ( V_15 , 10 , & V_40 ) ;
if ( V_7 || V_40 > 127 || V_40 < - 128 )
return - V_22 ;
if ( V_42 ) {
V_8 = strlen ( V_42 ) ;
if ( V_8 > V_27 )
V_8 = V_27 ;
V_42 [ V_8 ] = 0 ;
V_7 = F_30 ( V_42 , 10 , & V_41 ) ;
if ( ! V_7 )
V_41 = ( V_41 / 625 ) * 625 ;
}
if ( V_40 < 0 )
V_4 = ( T_4 ) ( - V_40 ) ;
else
V_4 = ( T_4 ) V_40 ;
V_4 = ( V_4 << V_27 ) | ( V_41 & V_28 ) ;
if ( V_40 < 0 )
V_4 = ( V_26 << 1 ) - V_4 ;
V_4 <<= V_25 ;
V_4 = F_16 ( V_4 ) ;
V_7 = F_5 ( V_2 , V_38 -> V_39 , ( T_1 ) V_4 ) ;
if ( V_7 )
return - V_21 ;
return V_7 ;
}
static int T_6 F_31 ( struct V_5 * V_6 ,
const struct V_43 * V_44 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
V_2 = F_32 ( sizeof( struct V_1 ) , V_45 ) ;
if ( V_2 == NULL )
return - V_46 ;
F_33 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_47 = F_34 ( 0 ) ;
if ( V_2 -> V_47 == NULL ) {
V_7 = - V_46 ;
goto V_48;
}
V_2 -> V_47 -> V_49 = V_44 -> V_49 ;
V_2 -> V_47 -> V_9 . V_50 = & V_6 -> V_9 ;
V_2 -> V_47 -> V_51 = & V_52 ;
V_2 -> V_47 -> V_18 = ( void * ) V_2 ;
V_2 -> V_47 -> V_53 = V_54 ;
V_7 = F_35 ( V_2 -> V_47 ) ;
if ( V_7 )
goto V_55;
if ( V_6 -> V_29 > 0 ) {
V_7 = F_36 ( V_6 -> V_29 ,
NULL ,
& F_17 ,
V_56 ,
V_2 -> V_47 -> V_49 ,
V_2 -> V_47 ) ;
if ( V_7 )
goto V_57;
V_7 = F_1 ( V_2 , V_10 , & V_2 -> V_19 ) ;
if ( V_7 ) {
V_7 = - V_21 ;
goto V_58;
}
V_2 -> V_19 &= ~ V_59 ;
V_7 = F_5 ( V_2 , V_10 , V_2 -> V_19 ) ;
if ( V_7 ) {
V_7 = - V_21 ;
goto V_58;
}
}
V_17 ( & V_6 -> V_9 , L_15 ,
V_2 -> V_47 -> V_49 ) ;
return 0 ;
V_58:
F_37 ( V_6 -> V_29 , V_2 -> V_47 ) ;
V_57:
F_38 ( V_2 -> V_47 ) ;
V_55:
F_39 ( V_2 -> V_47 ) ;
V_48:
F_40 ( V_2 ) ;
return V_7 ;
}
static int T_7 F_41 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_42 ( V_6 ) ;
struct V_16 * V_47 = V_2 -> V_47 ;
if ( V_6 -> V_29 )
F_37 ( V_6 -> V_29 , V_2 -> V_47 ) ;
F_38 ( V_47 ) ;
F_39 ( V_2 -> V_47 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static T_8 int F_43 ( void )
{
return F_44 ( & V_60 ) ;
}
static T_9 void F_45 ( void )
{
F_46 ( & V_60 ) ;
}
