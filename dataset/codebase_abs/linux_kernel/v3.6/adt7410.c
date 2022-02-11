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
return V_20 ;
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
if ( ! ( V_2 -> V_15 & V_24 ) )
V_4 &= ~ 0x7 ;
if ( V_4 & V_32 ) {
V_4 = ( T_2 ) ( ( V_32 << 1 ) - ( V_33 ) V_4 ) ;
V_31 = '-' ;
}
return sprintf ( V_12 , L_13 , V_31 ,
( V_4 >> V_34 ) ,
( V_4 & V_35 ) * 78125 ) ;
}
static T_3 F_21 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_1 V_36 ;
T_2 V_4 ;
int V_7 , V_37 = 0 ;
do {
V_7 = F_7 ( V_2 , V_38 , & V_36 ) ;
if ( V_7 )
return - V_22 ;
V_37 ++ ;
if ( V_37 == 10000 )
return - V_22 ;
} while ( V_36 & V_39 );
V_7 = F_1 ( V_2 , V_40 , & V_4 ) ;
if ( V_7 )
return - V_22 ;
return F_20 ( V_2 , V_4 , V_12 ) ;
}
static T_5 F_22 ( int V_41 , void * V_42 )
{
struct V_13 * V_43 = V_42 ;
struct V_1 * V_2 = F_13 ( V_43 ) ;
T_6 V_44 = F_23 () ;
T_1 V_36 ;
if ( F_7 ( V_2 , V_38 , & V_36 ) )
return V_45 ;
if ( V_36 & V_46 )
F_24 ( V_43 ,
F_25 ( V_47 , 0 ,
V_48 ,
V_49 ) ,
V_44 ) ;
if ( V_36 & V_50 )
F_24 ( V_43 ,
F_25 ( V_47 , 0 ,
V_48 ,
V_51 ) ,
V_44 ) ;
if ( V_36 & V_52 )
F_24 ( V_43 ,
F_25 ( V_47 , 0 ,
V_48 ,
V_49 ) ,
V_44 ) ;
return V_45 ;
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
if ( V_2 -> V_15 & V_53 )
return sprintf ( V_12 , L_14 ) ;
else
return sprintf ( V_12 , L_15 ) ;
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
V_15 = V_2 -> V_15 &= ~ V_53 ;
if ( strcmp ( V_12 , L_16 ) != 0 )
V_15 |= V_53 ;
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
return sprintf ( V_12 , L_17 ) ;
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
return sprintf ( V_12 , L_18 , V_2 -> V_15 & V_54 ) ;
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
V_15 = V_2 -> V_15 & ~ V_54 ;
V_15 |= V_4 ;
V_7 = F_9 ( V_2 , V_21 , V_15 ) ;
if ( V_7 )
return - V_22 ;
V_2 -> V_15 = V_15 ;
return V_7 ;
}
static inline T_3 F_31 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
T_1 V_55 ,
char * V_12 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
T_2 V_4 ;
int V_7 ;
V_7 = F_1 ( V_2 , V_55 , & V_4 ) ;
if ( V_7 )
return - V_22 ;
return F_20 ( V_2 , V_4 , V_12 ) ;
}
static inline T_3 F_32 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
T_1 V_55 ,
const char * V_12 ,
T_4 V_20 )
{
struct V_13 * V_14 = F_12 ( V_8 ) ;
struct V_1 * V_2 = F_13 ( V_14 ) ;
long V_56 , V_57 ;
T_2 V_4 ;
char * V_58 ;
int V_7 ;
V_58 = strchr ( V_12 , '.' ) ;
V_7 = F_33 ( V_12 , 10 , & V_56 ) ;
if ( V_7 || V_56 > 127 || V_56 < - 128 )
return - V_25 ;
if ( V_58 ) {
V_20 = strlen ( V_58 ) ;
if ( V_2 -> V_15 & V_24 ) {
if ( V_20 > V_34 )
V_20 = V_34 ;
V_58 [ V_20 ] = 0 ;
V_7 = F_33 ( V_58 , 10 , & V_57 ) ;
if ( ! V_7 )
V_57 = ( V_57 / 78125 ) * 78125 ;
} else {
if ( V_20 > V_59 )
V_20 = V_59 ;
V_58 [ V_20 ] = 0 ;
V_7 = F_33 ( V_58 , 10 , & V_57 ) ;
if ( ! V_7 )
V_57 = ( V_57 / 625 ) * 625 ;
}
}
if ( V_56 < 0 )
V_4 = ( T_2 ) ( - V_56 ) ;
else
V_4 = ( T_2 ) V_56 ;
if ( V_2 -> V_15 & V_24 ) {
V_4 = ( V_4 << V_34 ) |
( V_57 & V_35 ) ;
if ( V_56 < 0 )
V_4 = ( T_2 ) ( ( V_32 << 1 ) - ( V_33 ) V_4 ) ;
} else {
V_4 = ( V_4 << V_59 ) |
( V_57 & V_60 ) ;
if ( V_56 < 0 )
V_4 = ( V_61 << 1 ) - V_4 ;
V_4 <<= V_62 ;
}
V_7 = F_5 ( V_2 , V_55 , V_4 ) ;
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
return sprintf ( V_12 , L_18 , V_66 & V_68 ) ;
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
struct V_13 * V_43 ;
int V_7 = 0 ;
unsigned long * V_70 = V_6 -> V_8 . V_71 ;
unsigned long V_72 [] = { 0 , 0 } ;
V_43 = F_43 ( sizeof( * V_2 ) ) ;
if ( V_43 == NULL ) {
V_7 = - V_73 ;
goto V_74;
}
V_2 = F_13 ( V_43 ) ;
F_44 ( V_6 , V_43 ) ;
V_2 -> V_6 = V_6 ;
V_43 -> V_75 = V_26 -> V_75 ;
V_43 -> V_8 . V_76 = & V_6 -> V_8 ;
V_43 -> V_77 = & V_78 ;
V_43 -> V_79 = V_80 ;
if ( ! V_70 )
V_70 = V_72 ;
if ( V_6 -> V_41 ) {
V_7 = F_45 ( V_6 -> V_41 ,
NULL ,
& F_22 ,
V_81 | V_82 ,
V_26 -> V_75 ,
V_43 ) ;
if ( V_7 )
goto V_83;
}
if ( V_70 [ 0 ] ) {
V_7 = F_45 ( V_70 [ 0 ] ,
NULL ,
& F_22 ,
V_70 [ 1 ] |
V_82 ,
V_26 -> V_75 ,
V_43 ) ;
if ( V_7 )
goto V_84;
}
V_7 = F_7 ( V_2 , V_21 , & V_2 -> V_15 ) ;
if ( V_7 ) {
V_7 = - V_22 ;
goto V_85;
}
V_2 -> V_15 |= V_24 ;
if ( V_6 -> V_41 && V_70 [ 0 ] ) {
V_2 -> V_15 &= ~ V_86 ;
if ( V_70 [ 1 ] & V_87 )
V_2 -> V_15 |= V_88 ;
else
V_2 -> V_15 &= ~ V_88 ;
}
V_7 = F_9 ( V_2 , V_21 , V_2 -> V_15 ) ;
if ( V_7 ) {
V_7 = - V_22 ;
goto V_85;
}
V_7 = F_46 ( V_43 ) ;
if ( V_7 )
goto V_85;
V_14 ( & V_6 -> V_8 , L_19 ,
V_26 -> V_75 ) ;
return 0 ;
V_85:
F_47 ( V_70 [ 0 ] , V_43 ) ;
V_84:
F_47 ( V_6 -> V_41 , V_43 ) ;
V_83:
F_48 ( V_43 ) ;
V_74:
return V_7 ;
}
static int T_8 F_49 ( struct V_5 * V_6 )
{
struct V_13 * V_43 = F_50 ( V_6 ) ;
unsigned long * V_70 = V_6 -> V_8 . V_71 ;
F_51 ( V_43 ) ;
if ( V_70 [ 0 ] )
F_47 ( V_70 [ 0 ] , V_43 ) ;
if ( V_6 -> V_41 )
F_47 ( V_6 -> V_41 , V_43 ) ;
F_48 ( V_43 ) ;
return 0 ;
}
