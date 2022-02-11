static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_2 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = F_4 ( ( T_2 ) V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_6 ( V_6 , V_3 , F_4 ( V_4 ) ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_8 ( V_6 , V_3 ) ;
if ( V_7 < 0 ) {
F_3 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
* V_4 = ( T_1 ) V_7 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 = 0 ;
V_7 = F_10 ( V_6 , V_3 , V_4 ) ;
if ( V_7 < 0 )
F_3 ( & V_6 -> V_8 , L_2 ) ;
return V_7 ;
}
static T_3 F_11 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_1 V_15 ;
V_15 = V_2 -> V_15 & V_16 ;
switch ( V_15 ) {
case V_17 :
return sprintf ( V_12 , L_3 ) ;
case V_18 :
return sprintf ( V_12 , L_4 ) ;
case V_19 :
return sprintf ( V_12 , L_5 ) ;
default:
return sprintf ( V_12 , L_6 ) ;
}
}
static T_3 F_14 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_2 V_15 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 )
return - V_22 ;
V_15 = V_2 -> V_15 & ( ~ V_16 ) ;
if ( strcmp ( V_12 , L_7 ) )
V_15 |= V_17 ;
else if ( strcmp ( V_12 , L_8 ) )
V_15 |= V_18 ;
else if ( strcmp ( V_12 , L_9 ) )
V_15 |= V_19 ;
V_7 = F_9 ( V_2 , V_21 , V_15 ) ;
if ( V_7 )
return - V_22 ;
V_2 -> V_15 = V_15 ;
return V_7 ;
}
static T_3 F_15 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return sprintf ( V_12 , L_10 ) ;
}
static T_3 F_16 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
int V_7 ;
int V_23 ;
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 )
return - V_22 ;
if ( V_2 -> V_15 & V_24 )
V_23 = 16 ;
else
V_23 = 13 ;
return sprintf ( V_12 , L_11 , V_23 ) ;
}
static T_3 F_17 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
unsigned long V_4 ;
T_2 V_15 ;
int V_7 ;
V_7 = F_18 ( V_12 , 10 , & V_4 ) ;
if ( V_7 )
return - V_25 ;
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 )
return - V_22 ;
V_15 = V_2 -> V_15 & ( ~ V_24 ) ;
if ( V_4 )
V_15 |= V_24 ;
V_7 = F_9 ( V_2 , V_21 , V_15 ) ;
if ( V_7 )
return - V_22 ;
V_2 -> V_15 = V_15 ;
return V_7 ;
}
static T_3 F_19 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_1 V_26 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_27 , & V_26 ) ;
if ( V_7 )
return - V_22 ;
return sprintf ( V_12 , L_12 ,
V_26 & V_28 ,
( V_26 & V_29 ) >> V_30 ) ;
}
static T_3 F_20 ( struct V_1 * V_2 ,
T_2 V_4 , char * V_12 )
{
char V_31 = ' ' ;
if ( V_2 -> V_15 & V_24 ) {
if ( V_4 & V_32 ) {
V_4 = ( T_2 ) ( ( V_32 << 1 ) - ( V_33 ) V_4 ) ;
V_31 = '-' ;
}
return sprintf ( V_12 , L_13 , V_31 ,
( V_4 >> V_34 ) ,
( V_4 & V_35 ) * 78125 ) ;
} else {
if ( V_4 & V_36 ) {
V_4 >>= V_37 ;
V_4 = ( V_36 << 1 ) - V_4 ;
V_31 = '-' ;
}
return sprintf ( V_12 , L_14 , V_31 ,
( V_4 >> V_38 ) ,
( V_4 & V_39 ) * 625 ) ;
}
}
static T_3 F_21 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_1 V_40 ;
T_2 V_4 ;
int V_7 , V_41 = 0 ;
do {
V_7 = F_7 ( V_2 , V_42 , & V_40 ) ;
if ( V_7 )
return - V_22 ;
V_41 ++ ;
if ( V_41 == 10000 )
return - V_22 ;
} while ( V_40 & V_43 );
V_7 = F_1 ( V_2 , V_44 , & V_4 ) ;
if ( V_7 )
return - V_22 ;
return F_20 ( V_2 , V_4 , V_12 ) ;
}
static T_5 F_22 ( int V_45 , void * V_46 )
{
struct V_13 * V_47 = V_46 ;
struct V_1 * V_2 = F_13 ( V_47 ) ;
T_6 V_48 = F_23 () ;
T_1 V_40 ;
if ( F_7 ( V_2 , V_42 , & V_40 ) )
return V_49 ;
if ( V_40 & V_50 )
F_24 ( V_47 ,
F_25 ( V_51 , 0 ,
V_52 ,
V_53 ) ,
V_48 ) ;
if ( V_40 & V_54 )
F_24 ( V_47 ,
F_25 ( V_51 , 0 ,
V_52 ,
V_55 ) ,
V_48 ) ;
if ( V_40 & V_56 )
F_24 ( V_47 ,
F_25 ( V_51 , 0 ,
V_52 ,
V_53 ) ,
V_48 ) ;
return V_49 ;
}
static T_3 F_26 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
int V_7 ;
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 )
return - V_22 ;
if ( V_2 -> V_15 & V_57 )
return sprintf ( V_12 , L_15 ) ;
else
return sprintf ( V_12 , L_16 ) ;
}
static T_3 F_27 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_2 V_15 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 )
return - V_22 ;
V_15 = V_2 -> V_15 &= ~ V_57 ;
if ( strcmp ( V_12 , L_17 ) != 0 )
V_15 |= V_57 ;
V_7 = F_9 ( V_2 , V_21 , V_15 ) ;
if ( V_7 )
return - V_22 ;
V_2 -> V_15 = V_15 ;
return V_7 ;
}
static T_3 F_28 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return sprintf ( V_12 , L_18 ) ;
}
static T_3 F_29 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
int V_7 ;
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 )
return - V_22 ;
return sprintf ( V_12 , L_19 , V_2 -> V_15 & V_58 ) ;
}
static T_3 F_30 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
unsigned long V_4 ;
int V_7 ;
T_1 V_15 ;
V_7 = F_18 ( V_12 , 10 , & V_4 ) ;
if ( V_7 || V_4 > 3 )
return - V_25 ;
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 )
return - V_22 ;
V_15 = V_2 -> V_15 & ~ V_58 ;
V_15 |= V_4 ;
V_7 = F_9 ( V_2 , V_21 , V_15 ) ;
if ( V_7 )
return - V_22 ;
V_2 -> V_15 = V_15 ;
return V_7 ;
}
static inline T_3 F_31 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
T_1 V_59 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_2 V_4 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_59 , & V_4 ) ;
if ( V_7 )
return - V_22 ;
return F_20 ( V_2 , V_4 , V_12 ) ;
}
static inline T_3 F_32 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
T_1 V_59 ,
const char * V_12 ,
T_4 V_20 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
long V_60 , V_61 ;
T_2 V_4 ;
char * V_62 ;
int V_7 ;
V_62 = strchr ( V_12 , '.' ) ;
V_7 = F_33 ( V_12 , 10 , & V_60 ) ;
if ( V_7 || V_60 > 127 || V_60 < - 128 )
return - V_25 ;
if ( V_62 ) {
V_20 = strlen ( V_62 ) ;
if ( V_2 -> V_15 & V_24 ) {
if ( V_20 > V_34 )
V_20 = V_34 ;
V_62 [ V_20 ] = 0 ;
V_7 = F_33 ( V_62 , 10 , & V_61 ) ;
if ( ! V_7 )
V_61 = ( V_61 / 78125 ) * 78125 ;
} else {
if ( V_20 > V_38 )
V_20 = V_38 ;
V_62 [ V_20 ] = 0 ;
V_7 = F_33 ( V_62 , 10 , & V_61 ) ;
if ( ! V_7 )
V_61 = ( V_61 / 625 ) * 625 ;
}
}
if ( V_60 < 0 )
V_4 = ( T_2 ) ( - V_60 ) ;
else
V_4 = ( T_2 ) V_60 ;
if ( V_2 -> V_15 & V_24 ) {
V_4 = ( V_4 << V_34 ) |
( V_61 & V_35 ) ;
if ( V_60 < 0 )
V_4 = ( T_2 ) ( ( V_32 << 1 ) - ( V_33 ) V_4 ) ;
} else {
V_4 = ( V_4 << V_38 ) |
( V_61 & V_39 ) ;
if ( V_60 < 0 )
V_4 = ( V_36 << 1 ) - V_4 ;
V_4 <<= V_37 ;
}
V_7 = F_5 ( V_2 , V_59 , V_4 ) ;
if ( V_7 )
return - V_22 ;
return V_7 ;
}
static T_3 F_34 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return F_31 ( V_8 , V_11 ,
V_63 , V_12 ) ;
}
static inline T_3 F_35 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
return F_32 ( V_8 , V_11 ,
V_63 , V_12 , V_20 ) ;
}
static T_3 F_36 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return F_31 ( V_8 , V_11 ,
V_64 , V_12 ) ;
}
static inline T_3 F_37 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
return F_32 ( V_8 , V_11 ,
V_64 , V_12 , V_20 ) ;
}
static T_3 F_38 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return F_31 ( V_8 , V_11 ,
V_65 , V_12 ) ;
}
static inline T_3 F_39 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
return F_32 ( V_8 , V_11 ,
V_65 , V_12 , V_20 ) ;
}
static T_3 F_40 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
int V_7 ;
T_1 V_66 ;
V_7 = F_7 ( V_2 , V_67 , & V_66 ) ;
if ( V_7 )
return - V_22 ;
return sprintf ( V_12 , L_19 , V_66 & V_68 ) ;
}
static inline T_3 F_41 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_20 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
int V_7 ;
unsigned long V_4 ;
T_1 V_66 ;
V_7 = F_33 ( V_12 , 10 , & V_4 ) ;
if ( V_7 || V_4 > V_68 )
return - V_25 ;
V_66 = ( T_1 ) V_4 ;
V_7 = F_9 ( V_2 , V_67 , V_66 ) ;
if ( V_7 )
return - V_22 ;
return V_7 ;
}
static int T_7 F_42 ( struct V_5 * V_6 ,
const struct V_69 * V_26 )
{
struct V_1 * V_2 ;
struct V_13 * V_47 ;
int V_7 = 0 ;
unsigned long * V_70 = V_6 -> V_8 . V_71 ;
V_47 = F_43 ( sizeof( * V_2 ) ) ;
if ( V_47 == NULL ) {
V_7 = - V_72 ;
goto V_73;
}
V_2 = F_13 ( V_47 ) ;
F_44 ( V_6 , V_47 ) ;
V_2 -> V_6 = V_6 ;
V_47 -> V_74 = V_26 -> V_74 ;
V_47 -> V_8 . V_75 = & V_6 -> V_8 ;
V_47 -> V_76 = & V_77 ;
V_47 -> V_78 = V_79 ;
if ( V_6 -> V_45 ) {
V_7 = F_45 ( V_6 -> V_45 ,
NULL ,
& F_22 ,
V_80 ,
V_26 -> V_74 ,
V_47 ) ;
if ( V_7 )
goto V_81;
}
if ( V_70 [ 0 ] ) {
V_7 = F_45 ( V_70 [ 0 ] ,
NULL ,
& F_22 ,
V_70 [ 1 ] ,
V_26 -> V_74 ,
V_47 ) ;
if ( V_7 )
goto V_82;
}
if ( V_6 -> V_45 && V_70 [ 0 ] ) {
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 ) {
V_7 = - V_22 ;
goto V_83;
}
V_2 -> V_15 &= ~ V_84 ;
if ( V_70 [ 1 ] & V_85 )
V_2 -> V_15 |= V_86 ;
else
V_2 -> V_15 &= ~ V_86 ;
V_7 = F_9 ( V_2 , V_21 , V_2 -> V_15 ) ;
if ( V_7 ) {
V_7 = - V_22 ;
goto V_83;
}
}
V_7 = F_46 ( V_47 ) ;
if ( V_7 )
goto V_83;
V_14 ( & V_6 -> V_8 , L_20 ,
V_26 -> V_74 ) ;
return 0 ;
V_83:
F_47 ( V_70 [ 0 ] , V_47 ) ;
V_82:
F_47 ( V_6 -> V_45 , V_47 ) ;
V_81:
F_48 ( V_47 ) ;
V_73:
return V_7 ;
}
static int T_8 F_49 ( struct V_5 * V_6 )
{
struct V_13 * V_47 = F_50 ( V_6 ) ;
unsigned long * V_70 = V_6 -> V_8 . V_71 ;
F_51 ( V_47 ) ;
if ( V_70 [ 0 ] )
F_47 ( V_70 [ 0 ] , V_47 ) ;
if ( V_6 -> V_45 )
F_47 ( V_6 -> V_45 , V_47 ) ;
F_48 ( V_47 ) ;
return 0 ;
}
static T_9 int F_52 ( void )
{
return F_53 ( & V_87 ) ;
}
static T_10 void F_54 ( void )
{
F_55 ( & V_87 ) ;
}
