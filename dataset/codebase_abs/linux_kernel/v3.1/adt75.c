static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 , V_10 ;
V_9 = F_3 ( V_8 , V_3 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_11 , L_1 ) ;
return V_9 ;
}
if ( V_3 == V_12 || V_3 == V_13 )
V_10 = 1 ;
else
V_10 = 2 ;
V_9 = F_5 ( V_8 , V_4 , V_10 ) ;
if ( V_9 < 0 ) {
F_4 ( & V_8 -> V_11 , L_2 ) ;
return V_9 ;
}
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 = 0 ;
if ( V_3 == V_12 || V_3 == V_13 )
V_9 = F_7 ( V_8 , V_3 , V_4 ) ;
else
V_9 = F_8 ( V_8 , V_3 , V_4 ) ;
if ( V_9 < 0 )
F_4 ( & V_8 -> V_11 , L_3 ) ;
return V_9 ;
}
static T_2 F_9 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_5 * V_6 = F_2 ( F_10 ( V_11 ) ) ;
if ( V_6 -> V_18 & V_19 )
return sprintf ( V_17 , L_4 ) ;
else
return sprintf ( V_17 , L_5 ) ;
}
static T_2 F_11 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
const char * V_17 ,
T_3 V_10 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
T_1 V_18 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
V_18 = V_6 -> V_18 & ~ V_19 ;
if ( ! strcmp ( V_17 , L_6 ) )
V_18 |= V_19 ;
V_9 = F_6 ( V_2 , V_12 , V_18 ) ;
if ( V_9 )
return - V_20 ;
V_6 -> V_18 = V_18 ;
return V_9 ;
}
static T_2 F_12 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
return sprintf ( V_17 , L_7 ) ;
}
static T_2 F_13 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_5 * V_6 = F_2 ( F_10 ( V_11 ) ) ;
return sprintf ( V_17 , L_8 , ! ! ( V_6 -> V_18 & V_13 ) ) ;
}
static T_2 F_14 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
const char * V_17 ,
T_3 V_10 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_4 = 0 ;
int V_9 ;
T_1 V_18 ;
V_9 = F_15 ( V_17 , 10 , & V_4 ) ;
if ( V_9 )
return - V_21 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
V_18 = V_6 -> V_18 & ~ V_13 ;
if ( V_4 )
V_18 |= V_13 ;
V_9 = F_6 ( V_2 , V_12 , V_18 ) ;
if ( V_9 )
return - V_20 ;
V_6 -> V_18 = V_18 ;
return V_9 ;
}
static T_2 F_16 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_4 V_4 ;
char V_22 = ' ' ;
int V_9 ;
if ( V_6 -> V_18 & V_19 ) {
F_4 ( V_11 , L_9 ) ;
return - V_20 ;
}
if ( V_6 -> V_18 & V_13 ) {
V_9 = F_3 ( V_6 -> V_8 , V_13 ) ;
if ( V_9 )
return - V_20 ;
}
V_9 = F_1 ( V_2 , V_23 , ( T_1 * ) & V_4 ) ;
if ( V_9 )
return - V_20 ;
V_4 = F_17 ( V_4 ) >> V_24 ;
if ( V_4 & V_25 ) {
V_4 = ( V_25 << 1 ) - V_4 ;
V_22 = '-' ;
}
return sprintf ( V_17 , L_10 , V_22 ,
( V_4 >> V_26 ) ,
( V_4 & V_27 ) * 625 ) ;
}
static T_5 F_18 ( int V_28 , void * V_29 )
{
F_19 ( V_29 , 0 ,
V_30 ,
F_20 () ) ;
return V_31 ;
}
static T_2 F_21 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
if ( V_6 -> V_18 & V_32 )
return sprintf ( V_17 , L_11 ) ;
else
return sprintf ( V_17 , L_12 ) ;
}
static T_2 F_22 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
const char * V_17 ,
T_3 V_10 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
T_1 V_18 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
V_18 = V_6 -> V_18 & ~ V_32 ;
if ( strcmp ( V_17 , L_13 ) != 0 )
V_18 |= V_32 ;
V_9 = F_6 ( V_2 , V_12 , V_18 ) ;
if ( V_9 )
return - V_20 ;
V_6 -> V_18 = V_18 ;
return V_9 ;
}
static T_2 F_23 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
return sprintf ( V_17 , L_14 ) ;
}
static T_2 F_24 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
return sprintf ( V_17 , L_8 , ! ! ( V_6 -> V_18 & V_33 ) ) ;
}
static T_2 F_25 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
const char * V_17 ,
T_3 V_10 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_4 = 0 ;
int V_9 ;
T_1 V_18 ;
V_9 = F_15 ( V_17 , 10 , & V_4 ) ;
if ( V_9 )
return - V_21 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
V_18 = V_6 -> V_18 & ~ V_33 ;
if ( V_4 )
V_18 |= V_33 ;
V_9 = F_6 ( V_2 , V_12 , V_18 ) ;
if ( V_9 )
return - V_20 ;
V_6 -> V_18 = V_18 ;
return V_9 ;
}
static T_2 F_26 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
return sprintf ( V_17 , L_8 , ( V_6 -> V_18 & V_34 ) >>
V_35 ) ;
}
static T_2 F_27 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
const char * V_17 ,
T_3 V_10 )
{
struct V_1 * V_2 = F_10 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_4 ;
int V_9 ;
T_1 V_18 ;
V_9 = F_15 ( V_17 , 10 , & V_4 ) ;
if ( V_9 || V_4 > 3 )
return - V_21 ;
V_9 = F_1 ( V_2 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 )
return - V_20 ;
V_18 = V_6 -> V_18 & ~ V_34 ;
V_18 |= ( V_4 << V_35 ) ;
V_9 = F_6 ( V_2 , V_12 , V_18 ) ;
if ( V_9 )
return - V_20 ;
V_6 -> V_18 = V_18 ;
return V_9 ;
}
static inline T_2 F_28 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_36 * V_37 = F_29 ( V_16 ) ;
struct V_1 * V_2 = F_10 ( V_11 ) ;
T_4 V_4 ;
char V_22 = ' ' ;
int V_9 ;
V_9 = F_1 ( V_2 , V_37 -> V_38 , ( T_1 * ) & V_4 ) ;
if ( V_9 )
return - V_20 ;
V_4 = F_17 ( V_4 ) >> V_24 ;
if ( V_4 & V_25 ) {
V_4 = ( V_25 << 1 ) - V_4 ;
V_22 = '-' ;
}
return sprintf ( V_17 , L_10 , V_22 ,
( V_4 >> V_26 ) ,
( V_4 & V_27 ) * 625 ) ;
}
static inline T_2 F_30 ( struct V_14 * V_11 ,
struct V_15 * V_16 ,
const char * V_17 ,
T_3 V_10 )
{
struct V_36 * V_37 = F_29 ( V_16 ) ;
struct V_1 * V_2 = F_10 ( V_11 ) ;
long V_39 , V_40 ;
T_4 V_4 ;
char * V_41 ;
int V_9 ;
V_41 = strchr ( V_17 , '.' ) ;
V_9 = F_31 ( V_17 , 10 , & V_39 ) ;
if ( V_9 || V_39 > 127 || V_39 < - 128 )
return - V_21 ;
if ( V_41 ) {
V_10 = strlen ( V_41 ) ;
if ( V_10 > V_26 )
V_10 = V_26 ;
V_41 [ V_10 ] = 0 ;
V_9 = F_31 ( V_41 , 10 , & V_40 ) ;
if ( ! V_9 )
V_40 = ( V_40 / 625 ) * 625 ;
}
if ( V_39 < 0 )
V_4 = ( T_4 ) ( - V_39 ) ;
else
V_4 = ( T_4 ) V_39 ;
V_4 = ( V_4 << V_26 ) | ( V_40 & V_27 ) ;
if ( V_39 < 0 )
V_4 = ( V_25 << 1 ) - V_4 ;
V_4 <<= V_24 ;
V_4 = F_17 ( V_4 ) ;
V_9 = F_6 ( V_2 , V_37 -> V_38 , ( T_1 ) V_4 ) ;
if ( V_9 )
return - V_20 ;
return V_9 ;
}
static int T_6 F_32 ( struct V_7 * V_8 ,
const struct V_42 * V_43 )
{
struct V_5 * V_6 ;
struct V_1 * V_44 ;
int V_9 = 0 ;
V_44 = F_33 ( sizeof( * V_6 ) ) ;
if ( V_44 == NULL ) {
V_9 = - V_45 ;
goto V_46;
}
V_6 = F_2 ( V_44 ) ;
F_34 ( V_8 , V_44 ) ;
V_6 -> V_8 = V_8 ;
V_44 -> V_47 = V_43 -> V_47 ;
V_44 -> V_11 . V_48 = & V_8 -> V_11 ;
V_44 -> V_49 = & V_50 ;
V_44 -> V_51 = V_52 ;
V_9 = F_35 ( V_44 ) ;
if ( V_9 )
goto V_53;
if ( V_8 -> V_28 > 0 ) {
V_9 = F_36 ( V_8 -> V_28 ,
NULL ,
& F_18 ,
V_54 ,
V_44 -> V_47 ,
V_44 ) ;
if ( V_9 )
goto V_55;
V_9 = F_1 ( V_44 , V_12 , & V_6 -> V_18 ) ;
if ( V_9 ) {
V_9 = - V_20 ;
goto V_56;
}
V_6 -> V_18 &= ~ V_57 ;
V_9 = F_6 ( V_44 , V_12 , V_6 -> V_18 ) ;
if ( V_9 ) {
V_9 = - V_20 ;
goto V_56;
}
}
V_2 ( & V_8 -> V_11 , L_15 ,
V_44 -> V_47 ) ;
return 0 ;
V_56:
F_37 ( V_8 -> V_28 , V_44 ) ;
V_55:
F_38 ( V_44 ) ;
V_53:
F_39 ( V_44 ) ;
V_46:
return V_9 ;
}
static int T_7 F_40 ( struct V_7 * V_8 )
{
struct V_1 * V_44 = F_41 ( V_8 ) ;
if ( V_8 -> V_28 )
F_37 ( V_8 -> V_28 , V_44 ) ;
F_38 ( V_44 ) ;
F_39 ( V_44 ) ;
return 0 ;
}
static T_8 int F_42 ( void )
{
return F_43 ( & V_58 ) ;
}
static T_9 void F_44 ( void )
{
F_45 ( & V_58 ) ;
}
