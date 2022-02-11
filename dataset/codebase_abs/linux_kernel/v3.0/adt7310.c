static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 = ( V_3 << V_8 ) & V_9 ;
int V_10 = 0 ;
V_7 |= V_11 ;
V_10 = F_2 ( V_6 , & V_7 , sizeof( V_7 ) ) ;
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 , L_1 ) ;
return V_10 ;
}
V_10 = F_4 ( V_6 , ( T_1 * ) V_4 , sizeof( * V_4 ) ) ;
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 , L_2 ) ;
return V_10 ;
}
* V_4 = F_5 ( * V_4 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_13 [ 3 ] ;
int V_10 = 0 ;
V_13 [ 0 ] = ( V_3 << V_8 ) & V_9 ;
V_13 [ 1 ] = ( T_1 ) ( V_4 >> 8 ) ;
V_13 [ 2 ] = ( T_1 ) ( V_4 & 0xFF ) ;
V_10 = F_2 ( V_6 , V_13 , 3 ) ;
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 , L_3 ) ;
return V_10 ;
}
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 = ( V_3 << V_8 ) & V_9 ;
int V_10 = 0 ;
V_7 |= V_11 ;
V_10 = F_2 ( V_6 , & V_7 , sizeof( V_7 ) ) ;
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 , L_1 ) ;
return V_10 ;
}
V_10 = F_4 ( V_6 , V_4 , sizeof( * V_4 ) ) ;
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 , L_4 ) ;
return V_10 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_13 [ 2 ] ;
int V_10 = 0 ;
V_13 [ 0 ] = ( V_3 << V_8 ) & V_9 ;
V_13 [ 1 ] = V_4 ;
V_10 = F_2 ( V_6 , V_13 , 2 ) ;
if ( V_10 < 0 ) {
F_3 ( & V_6 -> V_12 , L_5 ) ;
return V_10 ;
}
return V_10 ;
}
static T_3 F_9 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_20 ;
V_20 = V_2 -> V_20 & V_21 ;
switch ( V_20 ) {
case V_22 :
return sprintf ( V_13 , L_6 ) ;
case V_23 :
return sprintf ( V_13 , L_7 ) ;
case V_24 :
return sprintf ( V_13 , L_8 ) ;
default:
return sprintf ( V_13 , L_9 ) ;
}
}
static T_3 F_11 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
T_2 V_20 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 )
return - V_27 ;
V_20 = V_2 -> V_20 & ( ~ V_21 ) ;
if ( strcmp ( V_13 , L_10 ) )
V_20 |= V_22 ;
else if ( strcmp ( V_13 , L_11 ) )
V_20 |= V_23 ;
else if ( strcmp ( V_13 , L_12 ) )
V_20 |= V_24 ;
V_10 = F_8 ( V_2 , V_26 , V_20 ) ;
if ( V_10 )
return - V_27 ;
V_2 -> V_20 = V_20 ;
return V_25 ;
}
static T_3 F_12 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return sprintf ( V_13 , L_13 ) ;
}
static T_3 F_13 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
int V_10 ;
int V_28 ;
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 )
return - V_27 ;
if ( V_2 -> V_20 & V_29 )
V_28 = 16 ;
else
V_28 = 13 ;
return sprintf ( V_13 , L_14 , V_28 ) ;
}
static T_3 F_14 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned long V_4 ;
T_2 V_20 ;
int V_10 ;
V_10 = F_15 ( V_13 , 10 , & V_4 ) ;
if ( V_10 )
return - V_30 ;
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 )
return - V_27 ;
V_20 = V_2 -> V_20 & ( ~ V_29 ) ;
if ( V_4 )
V_20 |= V_29 ;
V_10 = F_8 ( V_2 , V_26 , V_20 ) ;
if ( V_10 )
return - V_27 ;
V_2 -> V_20 = V_20 ;
return V_25 ;
}
static T_3 F_16 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_31 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_32 , & V_31 ) ;
if ( V_10 )
return - V_27 ;
return sprintf ( V_13 , L_15 ,
V_31 & V_33 ,
( V_31 & V_34 ) >> V_35 ) ;
}
static T_3 F_17 ( struct V_1 * V_2 ,
T_2 V_4 , char * V_13 )
{
char V_36 = ' ' ;
if ( V_2 -> V_20 & V_29 ) {
if ( V_4 & V_37 ) {
V_4 = ( T_2 ) ( ( V_37 << 1 ) - ( V_38 ) V_4 ) ;
V_36 = '-' ;
}
return sprintf ( V_13 , L_16 , V_36 ,
( V_4 >> V_39 ) ,
( V_4 & V_40 ) * 78125 ) ;
} else {
if ( V_4 & V_41 ) {
V_4 >>= V_42 ;
V_4 = ( V_41 << 1 ) - V_4 ;
V_36 = '-' ;
}
return sprintf ( V_13 , L_17 , V_36 ,
( V_4 >> V_43 ) ,
( V_4 & V_44 ) * 625 ) ;
}
}
static T_3 F_18 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
T_1 V_45 ;
T_2 V_4 ;
int V_10 , V_46 = 0 ;
do {
V_10 = F_7 ( V_2 , V_47 , & V_45 ) ;
if ( V_10 )
return - V_27 ;
V_46 ++ ;
if ( V_46 == 10000 )
return - V_27 ;
} while ( V_45 & V_48 );
V_10 = F_1 ( V_2 , V_49 , & V_4 ) ;
if ( V_10 )
return - V_27 ;
return F_17 ( V_2 , V_4 , V_13 ) ;
}
static T_5 F_19 ( int V_50 , void * V_51 )
{
struct V_17 * V_52 = V_51 ;
struct V_1 * V_2 = F_20 ( V_52 ) ;
T_6 V_53 = F_21 () ;
T_1 V_45 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_47 , & V_45 ) ;
if ( V_10 )
return V_10 ;
if ( V_45 & V_54 )
F_22 ( V_52 , 0 ,
F_23 ( V_55 , 0 ,
V_56 ,
V_57 ) ,
V_53 ) ;
if ( V_45 & V_58 )
F_22 ( V_52 , 0 ,
F_23 ( V_55 , 0 ,
V_56 ,
V_59 ) ,
V_53 ) ;
if ( V_45 & V_60 )
F_22 ( V_52 , 0 ,
F_23 ( V_55 , 0 ,
V_56 ,
V_57 ) ,
V_53 ) ;
return V_61 ;
}
static T_3 F_24 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 )
return - V_27 ;
if ( V_2 -> V_20 & V_62 )
return sprintf ( V_13 , L_18 ) ;
else
return sprintf ( V_13 , L_19 ) ;
}
static T_3 F_25 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
T_2 V_20 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 )
return - V_27 ;
V_20 = V_2 -> V_20 &= ~ V_62 ;
if ( strcmp ( V_13 , L_20 ) != 0 )
V_20 |= V_62 ;
V_10 = F_8 ( V_2 , V_26 , V_20 ) ;
if ( V_10 )
return - V_27 ;
V_2 -> V_20 = V_20 ;
return V_25 ;
}
static T_3 F_26 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return sprintf ( V_13 , L_21 ) ;
}
static T_3 F_27 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 )
return - V_27 ;
return sprintf ( V_13 , L_22 , V_2 -> V_20 & V_63 ) ;
}
static T_3 F_28 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned long V_4 ;
int V_10 ;
T_1 V_20 ;
V_10 = F_15 ( V_13 , 10 , & V_4 ) ;
if ( V_10 || V_4 > 3 )
return - V_30 ;
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 )
return - V_27 ;
V_20 = V_2 -> V_20 & ~ V_63 ;
V_20 |= V_4 ;
V_10 = F_8 ( V_2 , V_26 , V_20 ) ;
if ( V_10 )
return - V_27 ;
V_2 -> V_20 = V_20 ;
return V_25 ;
}
static inline T_3 F_29 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
T_1 V_64 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
T_2 V_4 ;
int V_10 ;
V_10 = F_1 ( V_2 , V_64 , & V_4 ) ;
if ( V_10 )
return - V_27 ;
return F_17 ( V_2 , V_4 , V_13 ) ;
}
static inline T_3 F_30 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
T_1 V_64 ,
const char * V_13 ,
T_4 V_25 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
long V_65 , V_66 ;
T_2 V_4 ;
char * V_67 ;
int V_10 ;
V_67 = strchr ( V_13 , '.' ) ;
V_10 = F_31 ( V_13 , 10 , & V_65 ) ;
if ( V_10 || V_65 > 127 || V_65 < - 128 )
return - V_30 ;
if ( V_67 ) {
V_25 = strlen ( V_67 ) ;
if ( V_2 -> V_20 & V_29 ) {
if ( V_25 > V_39 )
V_25 = V_39 ;
V_67 [ V_25 ] = 0 ;
V_10 = F_31 ( V_67 , 10 , & V_66 ) ;
if ( ! V_10 )
V_66 = ( V_66 / 78125 ) * 78125 ;
} else {
if ( V_25 > V_43 )
V_25 = V_43 ;
V_67 [ V_25 ] = 0 ;
V_10 = F_31 ( V_67 , 10 , & V_66 ) ;
if ( ! V_10 )
V_66 = ( V_66 / 625 ) * 625 ;
}
}
if ( V_65 < 0 )
V_4 = ( T_2 ) ( - V_65 ) ;
else
V_4 = ( T_2 ) V_65 ;
if ( V_2 -> V_20 & V_29 ) {
V_4 = ( V_4 << V_39 ) |
( V_66 & V_40 ) ;
if ( V_65 < 0 )
V_4 = ( T_2 ) ( ( V_37 << 1 ) - ( V_38 ) V_4 ) ;
} else {
V_4 = ( V_4 << V_43 ) |
( V_66 & V_44 ) ;
if ( V_65 < 0 )
V_4 = ( V_41 << 1 ) - V_4 ;
V_4 <<= V_42 ;
}
V_10 = F_6 ( V_2 , V_64 , V_4 ) ;
if ( V_10 )
return - V_27 ;
return V_25 ;
}
static T_3 F_32 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return F_29 ( V_12 , V_16 ,
V_68 , V_13 ) ;
}
static inline T_3 F_33 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
return F_30 ( V_12 , V_16 ,
V_68 , V_13 , V_25 ) ;
}
static T_3 F_34 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return F_29 ( V_12 , V_16 ,
V_69 , V_13 ) ;
}
static inline T_3 F_35 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
return F_30 ( V_12 , V_16 ,
V_69 , V_13 , V_25 ) ;
}
static T_3 F_36 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return F_29 ( V_12 , V_16 ,
V_70 , V_13 ) ;
}
static inline T_3 F_37 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
return F_30 ( V_12 , V_16 ,
V_70 , V_13 , V_25 ) ;
}
static T_3 F_38 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
int V_10 ;
T_1 V_71 ;
V_10 = F_7 ( V_2 , V_72 , & V_71 ) ;
if ( V_10 )
return - V_27 ;
return sprintf ( V_13 , L_22 , V_71 & V_73 ) ;
}
static inline T_3 F_39 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_25 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = V_18 -> V_19 ;
int V_10 ;
unsigned long V_4 ;
T_1 V_71 ;
V_10 = F_31 ( V_13 , 10 , & V_4 ) ;
if ( V_10 || V_4 > V_73 )
return - V_30 ;
V_71 = ( T_1 ) V_4 ;
V_10 = F_8 ( V_2 , V_72 , V_71 ) ;
if ( V_10 )
return - V_27 ;
return V_25 ;
}
static int T_7 F_40 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_10 = 0 ;
unsigned long * V_74 = V_6 -> V_12 . V_75 ;
unsigned long V_76 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_77 ) ;
if ( V_2 == NULL )
return - V_78 ;
F_42 ( & V_6 -> V_12 , V_2 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_52 = F_43 ( 0 ) ;
if ( V_2 -> V_52 == NULL ) {
V_10 = - V_78 ;
goto V_79;
}
V_2 -> V_52 -> V_12 . V_80 = & V_6 -> V_12 ;
V_2 -> V_52 -> V_81 = F_44 ( V_6 ) -> V_81 ;
V_2 -> V_52 -> V_82 = & V_83 ;
V_2 -> V_52 -> V_19 = ( void * ) V_2 ;
V_2 -> V_52 -> V_84 = V_85 ;
V_10 = F_45 ( V_2 -> V_52 ) ;
if ( V_10 )
goto V_86;
if ( V_6 -> V_50 ) {
if ( V_74 [ 2 ] )
V_76 = V_74 [ 2 ] ;
else
V_76 = V_87 ;
V_10 = F_46 ( V_6 -> V_50 ,
NULL ,
& F_19 ,
V_76 ,
V_2 -> V_52 -> V_81 ,
V_2 -> V_52 ) ;
if ( V_10 )
goto V_88;
}
if ( V_74 [ 0 ] ) {
V_10 = F_46 ( V_74 [ 0 ] ,
NULL ,
& F_19 ,
V_74 [ 1 ] ,
V_2 -> V_52 -> V_81 ,
V_2 -> V_52 ) ;
if ( V_10 )
goto V_89;
}
if ( V_6 -> V_50 && V_74 [ 0 ] ) {
V_10 = F_7 ( V_2 , V_26 , & V_2 -> V_20 ) ;
if ( V_10 ) {
V_10 = - V_27 ;
goto V_90;
}
V_2 -> V_20 &= ~ V_91 ;
if ( V_74 [ 1 ] & V_92 )
V_2 -> V_20 |= V_93 ;
else
V_2 -> V_20 &= ~ V_93 ;
V_10 = F_8 ( V_2 , V_26 , V_2 -> V_20 ) ;
if ( V_10 ) {
V_10 = - V_27 ;
goto V_90;
}
}
V_18 ( & V_6 -> V_12 , L_23 ,
V_2 -> V_52 -> V_81 ) ;
return 0 ;
V_90:
F_47 ( V_74 [ 0 ] , V_2 -> V_52 ) ;
V_89:
F_47 ( V_6 -> V_50 , V_2 -> V_52 ) ;
V_88:
F_48 ( V_2 -> V_52 ) ;
V_86:
F_49 ( V_2 -> V_52 ) ;
V_79:
F_50 ( V_2 ) ;
return V_10 ;
}
static int T_8 F_51 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_10 ( & V_6 -> V_12 ) ;
struct V_17 * V_52 = V_2 -> V_52 ;
unsigned long * V_74 = V_6 -> V_12 . V_75 ;
F_42 ( & V_6 -> V_12 , NULL ) ;
if ( V_74 [ 0 ] )
F_47 ( V_74 [ 0 ] , V_2 -> V_52 ) ;
if ( V_6 -> V_50 )
F_47 ( V_6 -> V_50 , V_2 -> V_52 ) ;
F_48 ( V_52 ) ;
F_49 ( V_2 -> V_52 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static T_9 int F_52 ( void )
{
return F_53 ( & V_94 ) ;
}
static T_10 void F_54 ( void )
{
F_55 ( & V_94 ) ;
}
