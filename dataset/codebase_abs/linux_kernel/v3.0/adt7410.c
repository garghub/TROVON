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
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_16 ;
V_16 = V_2 -> V_16 & V_17 ;
switch ( V_16 ) {
case V_18 :
return sprintf ( V_12 , L_3 ) ;
case V_19 :
return sprintf ( V_12 , L_4 ) ;
case V_20 :
return sprintf ( V_12 , L_5 ) ;
default:
return sprintf ( V_12 , L_6 ) ;
}
}
static T_3 F_13 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
T_2 V_16 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 )
return - V_23 ;
V_16 = V_2 -> V_16 & ( ~ V_17 ) ;
if ( strcmp ( V_12 , L_7 ) )
V_16 |= V_18 ;
else if ( strcmp ( V_12 , L_8 ) )
V_16 |= V_19 ;
else if ( strcmp ( V_12 , L_9 ) )
V_16 |= V_20 ;
V_7 = F_9 ( V_2 , V_22 , V_16 ) ;
if ( V_7 )
return - V_23 ;
V_2 -> V_16 = V_16 ;
return V_7 ;
}
static T_3 F_14 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return sprintf ( V_12 , L_10 ) ;
}
static T_3 F_15 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
int V_7 ;
int V_24 ;
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 )
return - V_23 ;
if ( V_2 -> V_16 & V_25 )
V_24 = 16 ;
else
V_24 = 13 ;
return sprintf ( V_12 , L_11 , V_24 ) ;
}
static T_3 F_16 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_4 ;
T_2 V_16 ;
int V_7 ;
V_7 = F_17 ( V_12 , 10 , & V_4 ) ;
if ( V_7 )
return - V_26 ;
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 )
return - V_23 ;
V_16 = V_2 -> V_16 & ( ~ V_25 ) ;
if ( V_4 )
V_16 |= V_25 ;
V_7 = F_9 ( V_2 , V_22 , V_16 ) ;
if ( V_7 )
return - V_23 ;
V_2 -> V_16 = V_16 ;
return V_7 ;
}
static T_3 F_18 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_27 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_28 , & V_27 ) ;
if ( V_7 )
return - V_23 ;
return sprintf ( V_12 , L_12 ,
V_27 & V_29 ,
( V_27 & V_30 ) >> V_31 ) ;
}
static T_3 F_19 ( struct V_1 * V_2 ,
T_2 V_4 , char * V_12 )
{
char V_32 = ' ' ;
if ( V_2 -> V_16 & V_25 ) {
if ( V_4 & V_33 ) {
V_4 = ( T_2 ) ( ( V_33 << 1 ) - ( V_34 ) V_4 ) ;
V_32 = '-' ;
}
return sprintf ( V_12 , L_13 , V_32 ,
( V_4 >> V_35 ) ,
( V_4 & V_36 ) * 78125 ) ;
} else {
if ( V_4 & V_37 ) {
V_4 >>= V_38 ;
V_4 = ( V_37 << 1 ) - V_4 ;
V_32 = '-' ;
}
return sprintf ( V_12 , L_14 , V_32 ,
( V_4 >> V_39 ) ,
( V_4 & V_40 ) * 625 ) ;
}
}
static T_3 F_20 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
T_1 V_41 ;
T_2 V_4 ;
int V_7 , V_42 = 0 ;
do {
V_7 = F_7 ( V_2 , V_43 , & V_41 ) ;
if ( V_7 )
return - V_23 ;
V_42 ++ ;
if ( V_42 == 10000 )
return - V_23 ;
} while ( V_41 & V_44 );
V_7 = F_1 ( V_2 , V_45 , & V_4 ) ;
if ( V_7 )
return - V_23 ;
return F_19 ( V_2 , V_4 , V_12 ) ;
}
static T_5 F_21 ( int V_46 , void * V_47 )
{
struct V_13 * V_48 = V_47 ;
struct V_1 * V_2 = F_22 ( V_48 ) ;
T_6 V_49 = F_23 () ;
T_1 V_41 ;
if ( F_7 ( V_2 , V_43 , & V_41 ) )
return V_50 ;
if ( V_41 & V_51 )
F_24 ( V_48 , 0 ,
F_25 ( V_52 , 0 ,
V_53 ,
V_54 ) ,
V_49 ) ;
if ( V_41 & V_55 )
F_24 ( V_48 , 0 ,
F_25 ( V_52 , 0 ,
V_53 ,
V_56 ) ,
V_49 ) ;
if ( V_41 & V_57 )
F_24 ( V_48 , 0 ,
F_25 ( V_52 , 0 ,
V_53 ,
V_54 ) ,
V_49 ) ;
return V_50 ;
}
static T_3 F_26 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 )
return - V_23 ;
if ( V_2 -> V_16 & V_58 )
return sprintf ( V_12 , L_15 ) ;
else
return sprintf ( V_12 , L_16 ) ;
}
static T_3 F_27 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
T_2 V_16 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 )
return - V_23 ;
V_16 = V_2 -> V_16 &= ~ V_58 ;
if ( strcmp ( V_12 , L_17 ) != 0 )
V_16 |= V_58 ;
V_7 = F_9 ( V_2 , V_22 , V_16 ) ;
if ( V_7 )
return - V_23 ;
V_2 -> V_16 = V_16 ;
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
struct V_1 * V_2 = V_14 -> V_15 ;
int V_7 ;
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 )
return - V_23 ;
return sprintf ( V_12 , L_19 , V_2 -> V_16 & V_59 ) ;
}
static T_3 F_30 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
unsigned long V_4 ;
int V_7 ;
T_1 V_16 ;
V_7 = F_17 ( V_12 , 10 , & V_4 ) ;
if ( V_7 || V_4 > 3 )
return - V_26 ;
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 )
return - V_23 ;
V_16 = V_2 -> V_16 & ~ V_59 ;
V_16 |= V_4 ;
V_7 = F_9 ( V_2 , V_22 , V_16 ) ;
if ( V_7 )
return - V_23 ;
V_2 -> V_16 = V_16 ;
return V_7 ;
}
static inline T_3 F_31 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
T_1 V_60 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
T_2 V_4 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_60 , & V_4 ) ;
if ( V_7 )
return - V_23 ;
return F_19 ( V_2 , V_4 , V_12 ) ;
}
static inline T_3 F_32 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
T_1 V_60 ,
const char * V_12 ,
T_4 V_21 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
long V_61 , V_62 ;
T_2 V_4 ;
char * V_63 ;
int V_7 ;
V_63 = strchr ( V_12 , '.' ) ;
V_7 = F_33 ( V_12 , 10 , & V_61 ) ;
if ( V_7 || V_61 > 127 || V_61 < - 128 )
return - V_26 ;
if ( V_63 ) {
V_21 = strlen ( V_63 ) ;
if ( V_2 -> V_16 & V_25 ) {
if ( V_21 > V_35 )
V_21 = V_35 ;
V_63 [ V_21 ] = 0 ;
V_7 = F_33 ( V_63 , 10 , & V_62 ) ;
if ( ! V_7 )
V_62 = ( V_62 / 78125 ) * 78125 ;
} else {
if ( V_21 > V_39 )
V_21 = V_39 ;
V_63 [ V_21 ] = 0 ;
V_7 = F_33 ( V_63 , 10 , & V_62 ) ;
if ( ! V_7 )
V_62 = ( V_62 / 625 ) * 625 ;
}
}
if ( V_61 < 0 )
V_4 = ( T_2 ) ( - V_61 ) ;
else
V_4 = ( T_2 ) V_61 ;
if ( V_2 -> V_16 & V_25 ) {
V_4 = ( V_4 << V_35 ) |
( V_62 & V_36 ) ;
if ( V_61 < 0 )
V_4 = ( T_2 ) ( ( V_33 << 1 ) - ( V_34 ) V_4 ) ;
} else {
V_4 = ( V_4 << V_39 ) |
( V_62 & V_40 ) ;
if ( V_61 < 0 )
V_4 = ( V_37 << 1 ) - V_4 ;
V_4 <<= V_38 ;
}
V_7 = F_5 ( V_2 , V_60 , V_4 ) ;
if ( V_7 )
return - V_23 ;
return V_7 ;
}
static T_3 F_34 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return F_31 ( V_8 , V_11 ,
V_64 , V_12 ) ;
}
static inline T_3 F_35 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
return F_32 ( V_8 , V_11 ,
V_64 , V_12 , V_21 ) ;
}
static T_3 F_36 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return F_31 ( V_8 , V_11 ,
V_65 , V_12 ) ;
}
static inline T_3 F_37 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
return F_32 ( V_8 , V_11 ,
V_65 , V_12 , V_21 ) ;
}
static T_3 F_38 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
return F_31 ( V_8 , V_11 ,
V_66 , V_12 ) ;
}
static inline T_3 F_39 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
return F_32 ( V_8 , V_11 ,
V_66 , V_12 , V_21 ) ;
}
static T_3 F_40 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
int V_7 ;
T_1 V_67 ;
V_7 = F_7 ( V_2 , V_68 , & V_67 ) ;
if ( V_7 )
return - V_23 ;
return sprintf ( V_12 , L_19 , V_67 & V_69 ) ;
}
static inline T_3 F_41 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 ,
T_4 V_21 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = V_14 -> V_15 ;
int V_7 ;
unsigned long V_4 ;
T_1 V_67 ;
V_7 = F_33 ( V_12 , 10 , & V_4 ) ;
if ( V_7 || V_4 > V_69 )
return - V_26 ;
V_67 = ( T_1 ) V_4 ;
V_7 = F_9 ( V_2 , V_68 , V_67 ) ;
if ( V_7 )
return - V_23 ;
return V_7 ;
}
static int T_7 F_42 ( struct V_5 * V_6 ,
const struct V_70 * V_27 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
unsigned long * V_71 = V_6 -> V_8 . V_72 ;
V_2 = F_43 ( sizeof( struct V_1 ) , V_73 ) ;
if ( V_2 == NULL )
return - V_74 ;
F_44 ( V_6 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_48 = F_45 ( 0 ) ;
if ( V_2 -> V_48 == NULL ) {
V_7 = - V_74 ;
goto V_75;
}
V_2 -> V_48 -> V_76 = V_27 -> V_76 ;
V_2 -> V_48 -> V_8 . V_77 = & V_6 -> V_8 ;
V_2 -> V_48 -> V_78 = & V_79 ;
V_2 -> V_48 -> V_15 = ( void * ) V_2 ;
V_2 -> V_48 -> V_80 = V_81 ;
V_7 = F_46 ( V_2 -> V_48 ) ;
if ( V_7 )
goto V_82;
if ( V_6 -> V_46 ) {
V_7 = F_47 ( V_6 -> V_46 ,
NULL ,
& F_21 ,
V_83 ,
V_27 -> V_76 ,
V_2 -> V_48 ) ;
if ( V_7 )
goto V_84;
}
if ( V_71 [ 0 ] ) {
V_7 = F_47 ( V_71 [ 0 ] ,
NULL ,
& F_21 ,
V_71 [ 1 ] ,
V_27 -> V_76 ,
V_2 -> V_48 ) ;
if ( V_7 )
goto V_85;
}
if ( V_6 -> V_46 && V_71 [ 0 ] ) {
V_7 = F_7 ( V_2 , V_22 , & V_2 -> V_16 ) ;
if ( V_7 ) {
V_7 = - V_23 ;
goto V_86;
}
V_2 -> V_16 &= ~ V_87 ;
if ( V_71 [ 1 ] & V_88 )
V_2 -> V_16 |= V_89 ;
else
V_2 -> V_16 &= ~ V_89 ;
V_7 = F_9 ( V_2 , V_22 , V_2 -> V_16 ) ;
if ( V_7 ) {
V_7 = - V_23 ;
goto V_86;
}
}
V_14 ( & V_6 -> V_8 , L_20 ,
V_27 -> V_76 ) ;
return 0 ;
V_86:
F_48 ( V_71 [ 0 ] , V_2 -> V_48 ) ;
V_85:
F_48 ( V_6 -> V_46 , V_2 -> V_48 ) ;
V_84:
F_49 ( V_2 -> V_48 ) ;
V_82:
F_50 ( V_2 -> V_48 ) ;
V_75:
F_51 ( V_2 ) ;
return V_7 ;
}
static int T_8 F_52 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_53 ( V_6 ) ;
struct V_13 * V_48 = V_2 -> V_48 ;
unsigned long * V_71 = V_6 -> V_8 . V_72 ;
if ( V_71 [ 0 ] )
F_48 ( V_71 [ 0 ] , V_2 -> V_48 ) ;
if ( V_6 -> V_46 )
F_48 ( V_6 -> V_46 , V_2 -> V_48 ) ;
F_49 ( V_48 ) ;
F_50 ( V_2 -> V_48 ) ;
F_51 ( V_2 ) ;
return 0 ;
}
static T_9 int F_54 ( void )
{
return F_55 ( & V_90 ) ;
}
static T_10 void F_56 ( void )
{
F_57 ( & V_90 ) ;
}
