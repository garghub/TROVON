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
struct V_1 * V_2 = F_11 ( V_18 ) ;
T_1 V_19 ;
V_19 = V_2 -> V_19 & V_20 ;
switch ( V_19 ) {
case V_21 :
return sprintf ( V_13 , L_6 ) ;
case V_22 :
return sprintf ( V_13 , L_7 ) ;
case V_23 :
return sprintf ( V_13 , L_8 ) ;
default:
return sprintf ( V_13 , L_9 ) ;
}
}
static T_3 F_12 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
T_2 V_19 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 )
return - V_26 ;
V_19 = V_2 -> V_19 & ( ~ V_20 ) ;
if ( strcmp ( V_13 , L_10 ) )
V_19 |= V_21 ;
else if ( strcmp ( V_13 , L_11 ) )
V_19 |= V_22 ;
else if ( strcmp ( V_13 , L_12 ) )
V_19 |= V_23 ;
V_10 = F_8 ( V_2 , V_25 , V_19 ) ;
if ( V_10 )
return - V_26 ;
V_2 -> V_19 = V_19 ;
return V_24 ;
}
static T_3 F_13 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return sprintf ( V_13 , L_13 ) ;
}
static T_3 F_14 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
int V_10 ;
int V_27 ;
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 )
return - V_26 ;
if ( V_2 -> V_19 & V_28 )
V_27 = 16 ;
else
V_27 = 13 ;
return sprintf ( V_13 , L_14 , V_27 ) ;
}
static T_3 F_15 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
unsigned long V_4 ;
T_2 V_19 ;
int V_10 ;
V_10 = F_16 ( V_13 , 10 , & V_4 ) ;
if ( V_10 )
return - V_29 ;
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 )
return - V_26 ;
V_19 = V_2 -> V_19 & ( ~ V_28 ) ;
if ( V_4 )
V_19 |= V_28 ;
V_10 = F_8 ( V_2 , V_25 , V_19 ) ;
if ( V_10 )
return - V_26 ;
V_2 -> V_19 = V_19 ;
return V_24 ;
}
static T_3 F_17 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
T_1 V_30 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_31 , & V_30 ) ;
if ( V_10 )
return - V_26 ;
return sprintf ( V_13 , L_15 ,
V_30 & V_32 ,
( V_30 & V_33 ) >> V_34 ) ;
}
static T_3 F_18 ( struct V_1 * V_2 ,
T_2 V_4 , char * V_13 )
{
char V_35 = ' ' ;
if ( V_2 -> V_19 & V_28 ) {
if ( V_4 & V_36 ) {
V_4 = ( T_2 ) ( ( V_36 << 1 ) - ( V_37 ) V_4 ) ;
V_35 = '-' ;
}
return sprintf ( V_13 , L_16 , V_35 ,
( V_4 >> V_38 ) ,
( V_4 & V_39 ) * 78125 ) ;
} else {
if ( V_4 & V_40 ) {
V_4 >>= V_41 ;
V_4 = ( V_40 << 1 ) - V_4 ;
V_35 = '-' ;
}
return sprintf ( V_13 , L_17 , V_35 ,
( V_4 >> V_42 ) ,
( V_4 & V_43 ) * 625 ) ;
}
}
static T_3 F_19 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
T_1 V_44 ;
T_2 V_4 ;
int V_10 , V_45 = 0 ;
do {
V_10 = F_7 ( V_2 , V_46 , & V_44 ) ;
if ( V_10 )
return - V_26 ;
V_45 ++ ;
if ( V_45 == 10000 )
return - V_26 ;
} while ( V_44 & V_47 );
V_10 = F_1 ( V_2 , V_48 , & V_4 ) ;
if ( V_10 )
return - V_26 ;
return F_18 ( V_2 , V_4 , V_13 ) ;
}
static T_5 F_20 ( int V_49 , void * V_50 )
{
struct V_17 * V_51 = V_50 ;
struct V_1 * V_2 = F_11 ( V_51 ) ;
T_6 V_52 = F_21 () ;
T_1 V_44 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_46 , & V_44 ) ;
if ( V_10 )
return V_10 ;
if ( V_44 & V_53 )
F_22 ( V_51 ,
F_23 ( V_54 , 0 ,
V_55 ,
V_56 ) ,
V_52 ) ;
if ( V_44 & V_57 )
F_22 ( V_51 ,
F_23 ( V_54 , 0 ,
V_55 ,
V_58 ) ,
V_52 ) ;
if ( V_44 & V_59 )
F_22 ( V_51 ,
F_23 ( V_54 , 0 ,
V_55 ,
V_56 ) ,
V_52 ) ;
return V_60 ;
}
static T_3 F_24 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
int V_10 ;
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 )
return - V_26 ;
if ( V_2 -> V_19 & V_61 )
return sprintf ( V_13 , L_18 ) ;
else
return sprintf ( V_13 , L_19 ) ;
}
static T_3 F_25 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
T_2 V_19 ;
int V_10 ;
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 )
return - V_26 ;
V_19 = V_2 -> V_19 &= ~ V_61 ;
if ( strcmp ( V_13 , L_20 ) != 0 )
V_19 |= V_61 ;
V_10 = F_8 ( V_2 , V_25 , V_19 ) ;
if ( V_10 )
return - V_26 ;
V_2 -> V_19 = V_19 ;
return V_24 ;
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
struct V_1 * V_2 = F_11 ( V_18 ) ;
int V_10 ;
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 )
return - V_26 ;
return sprintf ( V_13 , L_22 , V_2 -> V_19 & V_62 ) ;
}
static T_3 F_28 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
unsigned long V_4 ;
int V_10 ;
T_1 V_19 ;
V_10 = F_16 ( V_13 , 10 , & V_4 ) ;
if ( V_10 || V_4 > 3 )
return - V_29 ;
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 )
return - V_26 ;
V_19 = V_2 -> V_19 & ~ V_62 ;
V_19 |= V_4 ;
V_10 = F_8 ( V_2 , V_25 , V_19 ) ;
if ( V_10 )
return - V_26 ;
V_2 -> V_19 = V_19 ;
return V_24 ;
}
static inline T_3 F_29 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
T_1 V_63 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
T_2 V_4 ;
int V_10 ;
V_10 = F_1 ( V_2 , V_63 , & V_4 ) ;
if ( V_10 )
return - V_26 ;
return F_18 ( V_2 , V_4 , V_13 ) ;
}
static inline T_3 F_30 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
T_1 V_63 ,
const char * V_13 ,
T_4 V_24 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
long V_64 , V_65 ;
T_2 V_4 ;
char * V_66 ;
int V_10 ;
V_66 = strchr ( V_13 , '.' ) ;
V_10 = F_31 ( V_13 , 10 , & V_64 ) ;
if ( V_10 || V_64 > 127 || V_64 < - 128 )
return - V_29 ;
if ( V_66 ) {
V_24 = strlen ( V_66 ) ;
if ( V_2 -> V_19 & V_28 ) {
if ( V_24 > V_38 )
V_24 = V_38 ;
V_66 [ V_24 ] = 0 ;
V_10 = F_31 ( V_66 , 10 , & V_65 ) ;
if ( ! V_10 )
V_65 = ( V_65 / 78125 ) * 78125 ;
} else {
if ( V_24 > V_42 )
V_24 = V_42 ;
V_66 [ V_24 ] = 0 ;
V_10 = F_31 ( V_66 , 10 , & V_65 ) ;
if ( ! V_10 )
V_65 = ( V_65 / 625 ) * 625 ;
}
}
if ( V_64 < 0 )
V_4 = ( T_2 ) ( - V_64 ) ;
else
V_4 = ( T_2 ) V_64 ;
if ( V_2 -> V_19 & V_28 ) {
V_4 = ( V_4 << V_38 ) |
( V_65 & V_39 ) ;
if ( V_64 < 0 )
V_4 = ( T_2 ) ( ( V_36 << 1 ) - ( V_37 ) V_4 ) ;
} else {
V_4 = ( V_4 << V_42 ) |
( V_65 & V_43 ) ;
if ( V_64 < 0 )
V_4 = ( V_40 << 1 ) - V_4 ;
V_4 <<= V_41 ;
}
V_10 = F_6 ( V_2 , V_63 , V_4 ) ;
if ( V_10 )
return - V_26 ;
return V_24 ;
}
static T_3 F_32 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return F_29 ( V_12 , V_16 ,
V_67 , V_13 ) ;
}
static inline T_3 F_33 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
return F_30 ( V_12 , V_16 ,
V_67 , V_13 , V_24 ) ;
}
static T_3 F_34 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return F_29 ( V_12 , V_16 ,
V_68 , V_13 ) ;
}
static inline T_3 F_35 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
return F_30 ( V_12 , V_16 ,
V_68 , V_13 , V_24 ) ;
}
static T_3 F_36 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
return F_29 ( V_12 , V_16 ,
V_69 , V_13 ) ;
}
static inline T_3 F_37 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
return F_30 ( V_12 , V_16 ,
V_69 , V_13 , V_24 ) ;
}
static T_3 F_38 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
char * V_13 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
int V_10 ;
T_1 V_70 ;
V_10 = F_7 ( V_2 , V_71 , & V_70 ) ;
if ( V_10 )
return - V_26 ;
return sprintf ( V_13 , L_22 , V_70 & V_72 ) ;
}
static inline T_3 F_39 ( struct V_14 * V_12 ,
struct V_15 * V_16 ,
const char * V_13 ,
T_4 V_24 )
{
struct V_17 * V_18 = F_10 ( V_12 ) ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
int V_10 ;
unsigned long V_4 ;
T_1 V_70 ;
V_10 = F_31 ( V_13 , 10 , & V_4 ) ;
if ( V_10 || V_4 > V_72 )
return - V_29 ;
V_70 = ( T_1 ) V_4 ;
V_10 = F_8 ( V_2 , V_71 , V_70 ) ;
if ( V_10 )
return - V_26 ;
return V_24 ;
}
static int T_7 F_40 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
struct V_17 * V_51 ;
int V_10 = 0 ;
unsigned long * V_73 = V_6 -> V_12 . V_74 ;
unsigned long V_75 ;
V_51 = F_41 ( sizeof( * V_2 ) ) ;
if ( V_51 == NULL ) {
V_10 = - V_76 ;
goto V_77;
}
V_2 = F_11 ( V_51 ) ;
F_42 ( & V_6 -> V_12 , V_51 ) ;
V_2 -> V_6 = V_6 ;
V_51 -> V_12 . V_78 = & V_6 -> V_12 ;
V_51 -> V_79 = F_43 ( V_6 ) -> V_79 ;
V_51 -> V_80 = & V_81 ;
V_51 -> V_82 = V_83 ;
if ( V_6 -> V_49 ) {
if ( V_73 [ 2 ] )
V_75 = V_73 [ 2 ] ;
else
V_75 = V_84 ;
V_10 = F_44 ( V_6 -> V_49 ,
NULL ,
& F_20 ,
V_75 ,
V_51 -> V_79 ,
V_51 ) ;
if ( V_10 )
goto V_85;
}
if ( V_73 [ 0 ] ) {
V_10 = F_44 ( V_73 [ 0 ] ,
NULL ,
& F_20 ,
V_73 [ 1 ] ,
V_51 -> V_79 ,
V_51 ) ;
if ( V_10 )
goto V_86;
}
if ( V_6 -> V_49 && V_73 [ 0 ] ) {
V_10 = F_7 ( V_2 , V_25 , & V_2 -> V_19 ) ;
if ( V_10 ) {
V_10 = - V_26 ;
goto V_87;
}
V_2 -> V_19 &= ~ V_88 ;
if ( V_73 [ 1 ] & V_89 )
V_2 -> V_19 |= V_90 ;
else
V_2 -> V_19 &= ~ V_90 ;
V_10 = F_8 ( V_2 , V_25 , V_2 -> V_19 ) ;
if ( V_10 ) {
V_10 = - V_26 ;
goto V_87;
}
}
V_10 = F_45 ( V_51 ) ;
if ( V_10 )
goto V_87;
V_18 ( & V_6 -> V_12 , L_23 ,
V_51 -> V_79 ) ;
return 0 ;
V_87:
F_46 ( V_73 [ 0 ] , V_51 ) ;
V_86:
F_46 ( V_6 -> V_49 , V_51 ) ;
V_85:
F_47 ( V_51 ) ;
V_77:
return V_10 ;
}
static int T_8 F_48 ( struct V_5 * V_6 )
{
struct V_17 * V_51 = F_10 ( & V_6 -> V_12 ) ;
unsigned long * V_73 = V_6 -> V_12 . V_74 ;
F_49 ( V_51 ) ;
F_42 ( & V_6 -> V_12 , NULL ) ;
if ( V_73 [ 0 ] )
F_46 ( V_73 [ 0 ] , V_51 ) ;
if ( V_6 -> V_49 )
F_46 ( V_6 -> V_49 , V_51 ) ;
F_47 ( V_51 ) ;
return 0 ;
}
static T_9 int F_50 ( void )
{
return F_51 ( & V_91 ) ;
}
static T_10 void F_52 ( void )
{
F_53 ( & V_91 ) ;
}
