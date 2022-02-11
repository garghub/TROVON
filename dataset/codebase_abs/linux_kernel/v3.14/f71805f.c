static inline int
F_1 ( int V_1 , int V_2 )
{
F_2 ( V_2 , V_1 ) ;
return F_3 ( V_1 + 1 ) ;
}
static int
F_4 ( int V_1 , int V_2 )
{
int V_3 ;
F_2 ( V_2 ++ , V_1 ) ;
V_3 = F_3 ( V_1 + 1 ) << 8 ;
F_2 ( V_2 , V_1 ) ;
V_3 |= F_3 ( V_1 + 1 ) ;
return V_3 ;
}
static inline void
F_5 ( int V_1 , int V_4 )
{
F_2 ( V_5 , V_1 ) ;
F_2 ( V_4 , V_1 + 1 ) ;
}
static inline void
F_6 ( int V_1 )
{
F_2 ( 0x87 , V_1 ) ;
F_2 ( 0x87 , V_1 ) ;
}
static inline void
F_7 ( int V_1 )
{
F_2 ( 0xaa , V_1 ) ;
}
static inline long F_8 ( T_1 V_2 )
{
return V_2 * 8 ;
}
static inline T_1 F_9 ( long V_3 )
{
if ( V_3 <= 0 )
return 0 ;
if ( V_3 >= 2016 )
return 0xfc ;
return ( ( V_3 + 16 ) / 32 ) << 2 ;
}
static inline long F_10 ( T_1 V_2 )
{
return V_2 * 16 ;
}
static inline T_1 F_11 ( long V_3 )
{
if ( V_3 <= 0 )
return 0 ;
if ( V_3 >= 4032 )
return 0xfc ;
return ( ( V_3 + 32 ) / 64 ) << 2 ;
}
static inline long F_12 ( T_2 V_2 )
{
V_2 &= 0xfff ;
if ( ! V_2 || V_2 == 0xfff )
return 0 ;
return 1500000 / V_2 ;
}
static inline T_2 F_13 ( long V_6 )
{
if ( V_6 < 367 )
return 0xfff ;
return 1500000 / V_6 ;
}
static inline unsigned long F_14 ( T_1 V_2 )
{
unsigned long clock = ( V_2 & 0x80 ) ? 48000000UL : 1000000UL ;
V_2 &= 0x7f ;
if ( V_2 == 0 )
V_2 ++ ;
return clock / ( V_2 << 8 ) ;
}
static inline T_1 F_15 ( unsigned long V_3 )
{
if ( V_3 >= 187500 )
return 0x80 ;
if ( V_3 >= 1475 )
return 0x80 | ( 48000000UL / ( V_3 << 8 ) ) ;
if ( V_3 < 31 )
return 0x7f ;
else
return 1000000UL / ( V_3 << 8 ) ;
}
static inline int F_16 ( T_1 V_2 )
{
return ! ( V_2 & V_7 ) ;
}
static inline long F_17 ( T_1 V_2 )
{
return V_2 * 1000 ;
}
static inline T_1 F_18 ( long V_3 )
{
if ( V_3 <= 0 )
return 0 ;
if ( V_3 >= 1000 * 0xff )
return 0xff ;
return ( V_3 + 500 ) / 1000 ;
}
static T_1 F_19 ( struct V_8 * V_9 , T_1 V_2 )
{
F_2 ( V_2 , V_9 -> V_10 + V_11 ) ;
return F_3 ( V_9 -> V_10 + V_12 ) ;
}
static void F_20 ( struct V_8 * V_9 , T_1 V_2 , T_1 V_3 )
{
F_2 ( V_2 , V_9 -> V_10 + V_11 ) ;
F_2 ( V_3 , V_9 -> V_10 + V_12 ) ;
}
static T_2 F_21 ( struct V_8 * V_9 , T_1 V_2 )
{
T_2 V_3 ;
F_2 ( V_2 , V_9 -> V_10 + V_11 ) ;
V_3 = F_3 ( V_9 -> V_10 + V_12 ) << 8 ;
F_2 ( ++ V_2 , V_9 -> V_10 + V_11 ) ;
V_3 |= F_3 ( V_9 -> V_10 + V_12 ) ;
return V_3 ;
}
static void F_22 ( struct V_8 * V_9 , T_1 V_2 , T_2 V_3 )
{
F_2 ( V_2 , V_9 -> V_10 + V_11 ) ;
F_2 ( V_3 >> 8 , V_9 -> V_10 + V_12 ) ;
F_2 ( ++ V_2 , V_9 -> V_10 + V_11 ) ;
F_2 ( V_3 & 0xff , V_9 -> V_10 + V_12 ) ;
}
static struct V_8 * F_23 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
int V_15 , V_16 ;
F_25 ( & V_9 -> V_17 ) ;
if ( F_26 ( V_18 , V_9 -> V_19 + 60 * V_20 )
|| ! V_9 -> V_21 ) {
for ( V_15 = 0 ; V_15 < 11 ; V_15 ++ ) {
if ( ! ( V_9 -> V_22 & ( 1 << V_15 ) ) )
continue;
V_9 -> V_23 [ V_15 ] = F_19 ( V_9 ,
F_27 ( V_15 ) ) ;
V_9 -> V_24 [ V_15 ] = F_19 ( V_9 ,
F_28 ( V_15 ) ) ;
}
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
V_9 -> V_25 [ V_15 ] = F_21 ( V_9 ,
F_29 ( V_15 ) ) ;
V_9 -> V_26 [ V_15 ] = F_21 ( V_9 ,
F_30 ( V_15 ) ) ;
V_9 -> V_27 [ V_15 ] = F_19 ( V_9 ,
F_31 ( V_15 ) ) ;
}
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
V_9 -> V_28 [ V_15 ] = F_19 ( V_9 ,
F_32 ( V_15 ) ) ;
V_9 -> V_29 [ V_15 ] = F_19 ( V_9 ,
F_33 ( V_15 ) ) ;
}
V_9 -> V_30 = F_19 ( V_9 , V_31 ) ;
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
for ( V_16 = 0 ; V_16 < 3 ; V_16 ++ ) {
V_9 -> V_32 [ V_15 ] . V_33 [ V_16 ] =
F_19 ( V_9 ,
F_34 ( V_15 ,
V_16 ) ) ;
V_9 -> V_32 [ V_15 ] . V_34 [ V_16 ] =
F_21 ( V_9 ,
F_35 ( V_15 ,
V_16 ) ) ;
}
}
V_9 -> V_35 = V_18 ;
}
if ( F_26 ( V_18 , V_9 -> V_19 + V_20 )
|| ! V_9 -> V_21 ) {
for ( V_15 = 0 ; V_15 < 11 ; V_15 ++ ) {
if ( ! ( V_9 -> V_22 & ( 1 << V_15 ) ) )
continue;
V_9 -> V_36 [ V_15 ] = F_19 ( V_9 ,
F_36 ( V_15 ) ) ;
}
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
V_9 -> V_34 [ V_15 ] = F_21 ( V_9 ,
F_37 ( V_15 ) ) ;
V_9 -> V_37 [ V_15 ] = F_19 ( V_9 ,
F_38 ( V_15 ) ) ;
V_9 -> V_38 [ V_15 ] = F_19 ( V_9 ,
F_39 ( V_15 ) ) ;
}
for ( V_15 = 0 ; V_15 < 3 ; V_15 ++ ) {
V_9 -> V_33 [ V_15 ] = F_19 ( V_9 ,
F_40 ( V_15 ) ) ;
}
V_9 -> V_39 = F_19 ( V_9 , F_41 ( 0 ) )
+ ( F_19 ( V_9 , F_41 ( 1 ) ) << 8 )
+ ( F_19 ( V_9 , F_41 ( 2 ) ) << 16 ) ;
V_9 -> V_19 = V_18 ;
V_9 -> V_21 = 1 ;
}
F_42 ( & V_9 -> V_17 ) ;
return V_9 ;
}
static T_3 F_43 ( struct V_13 * V_14 , struct V_40 * V_41 ,
char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_10 ( V_9 -> V_36 [ V_15 ] ) ) ;
}
static T_3 F_45 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_10 ( V_9 -> V_23 [ V_15 ] ) ) ;
}
static T_3 F_46 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_10 ( V_9 -> V_24 [ V_15 ] ) ) ;
}
static T_3 F_47 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_23 [ V_15 ] = F_11 ( V_3 ) ;
F_20 ( V_9 , F_27 ( V_15 ) , V_9 -> V_23 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_49 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_24 [ V_15 ] = F_11 ( V_3 ) ;
F_20 ( V_9 , F_28 ( V_15 ) , V_9 -> V_24 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_50 ( struct V_13 * V_14 , struct V_40 * V_41 ,
char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_8 ( V_9 -> V_36 [ V_15 ] ) ) ;
}
static T_3 F_51 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_8 ( V_9 -> V_23 [ V_15 ] ) ) ;
}
static T_3 F_52 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_8 ( V_9 -> V_24 [ V_15 ] ) ) ;
}
static T_3 F_53 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_23 [ V_15 ] = F_9 ( V_3 ) ;
F_20 ( V_9 , F_27 ( V_15 ) , V_9 -> V_23 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_54 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_24 [ V_15 ] = F_9 ( V_3 ) ;
F_20 ( V_9 , F_28 ( V_15 ) , V_9 -> V_24 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_55 ( struct V_13 * V_14 , struct V_40 * V_41 ,
char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_12 ( V_9 -> V_34 [ V_15 ] ) ) ;
}
static T_3 F_56 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_12 ( V_9 -> V_25 [ V_15 ] ) ) ;
}
static T_3 F_57 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_12 ( V_9 -> V_26 [ V_15 ] ) ) ;
}
static T_3 F_58 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_25 [ V_15 ] = F_13 ( V_3 ) ;
F_22 ( V_9 , F_29 ( V_15 ) , V_9 -> V_25 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_59 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_26 [ V_15 ] = F_13 ( V_3 ) ;
F_22 ( V_9 , F_30 ( V_15 ) ,
V_9 -> V_26 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_60 ( struct V_13 * V_14 , struct V_40 * V_41 ,
char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_2 , ( int ) V_9 -> V_38 [ V_15 ] ) ;
}
static T_3 F_61 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
int V_48 ;
switch ( V_9 -> V_37 [ V_15 ] & V_49 ) {
case V_50 :
V_48 = 3 ;
break;
case V_51 :
V_48 = 2 ;
break;
default:
V_48 = 1 ;
}
return sprintf ( V_42 , L_2 , V_48 ) ;
}
static T_3 F_62 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_3 , F_14 ( V_9 -> V_27 [ V_15 ] ) ) ;
}
static T_3 F_63 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_2 , F_16 ( V_9 -> V_37 [ V_15 ] ) ) ;
}
static T_3 F_64 ( struct V_13 * V_14 , struct V_40 * V_41 ,
const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
unsigned long V_3 ;
int V_47 ;
V_47 = F_65 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
if ( V_3 > 255 )
return - V_52 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_38 [ V_15 ] = V_3 ;
F_20 ( V_9 , F_39 ( V_15 ) , V_9 -> V_38 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_66 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
T_1 V_2 ;
unsigned long V_3 ;
int V_47 ;
V_47 = F_65 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
if ( V_3 < 1 || V_3 > 3 )
return - V_52 ;
if ( V_3 > 1 ) {
if ( F_67 ( & V_14 -> V_53 , V_54 [ V_15 ] ,
V_55 ) )
F_68 ( V_14 , L_4 , V_15 + 1 ) ;
}
F_25 ( & V_9 -> V_17 ) ;
V_2 = F_19 ( V_9 , F_38 ( V_15 ) )
& ~ V_49 ;
switch ( V_3 ) {
case 1 :
V_2 |= V_56 ;
break;
case 2 :
V_2 |= V_51 ;
break;
case 3 :
V_2 |= V_50 ;
break;
}
V_9 -> V_37 [ V_15 ] = V_2 ;
F_20 ( V_9 , F_38 ( V_15 ) , V_2 ) ;
F_42 ( & V_9 -> V_17 ) ;
if ( V_3 == 1 ) {
if ( F_67 ( & V_14 -> V_53 , V_54 [ V_15 ] ,
V_55 | V_57 ) )
F_68 ( V_14 , L_5 , V_15 + 1 ) ;
}
return V_46 ;
}
static T_3 F_69 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
unsigned long V_3 ;
int V_47 ;
V_47 = F_65 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_27 [ V_15 ] = F_15 ( V_3 ) ;
F_20 ( V_9 , F_31 ( V_15 ) , V_9 -> V_27 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_70 ( struct V_13 * V_14 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_58 * V_44 = F_71 ( V_41 ) ;
int V_59 = V_44 -> V_15 ;
int V_16 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 ,
F_17 ( V_9 -> V_32 [ V_59 ] . V_33 [ V_16 ] ) ) ;
}
static T_3 F_72 ( struct V_13 * V_14 ,
struct V_40 * V_41 ,
const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_58 * V_44 = F_71 ( V_41 ) ;
int V_59 = V_44 -> V_15 ;
int V_16 = V_44 -> V_45 ;
unsigned long V_3 ;
int V_47 ;
V_47 = F_65 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_32 [ V_59 ] . V_33 [ V_16 ] = F_18 ( V_3 ) ;
F_20 ( V_9 , F_34 ( V_59 , V_16 ) ,
V_9 -> V_32 [ V_59 ] . V_33 [ V_16 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_73 ( struct V_13 * V_14 ,
struct V_40 * V_41 ,
char * V_42 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_58 * V_44 = F_71 ( V_41 ) ;
int V_59 = V_44 -> V_15 ;
int V_16 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 ,
F_12 ( V_9 -> V_32 [ V_59 ] . V_34 [ V_16 ] ) ) ;
}
static T_3 F_74 ( struct V_13 * V_14 ,
struct V_40 * V_41 ,
const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_58 * V_44 = F_71 ( V_41 ) ;
int V_59 = V_44 -> V_15 ;
int V_16 = V_44 -> V_45 ;
unsigned long V_3 ;
int V_47 ;
V_47 = F_65 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_32 [ V_59 ] . V_34 [ V_16 ] = F_13 ( V_3 ) ;
F_22 ( V_9 , F_35 ( V_59 , V_16 ) ,
V_9 -> V_32 [ V_59 ] . V_34 [ V_16 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_75 ( struct V_13 * V_14 , struct V_40 * V_41 ,
char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_17 ( V_9 -> V_33 [ V_15 ] ) ) ;
}
static T_3 F_76 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_17 ( V_9 -> V_28 [ V_15 ] ) ) ;
}
static T_3 F_77 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_1 , F_17 ( V_9 -> V_29 [ V_15 ] ) ) ;
}
static T_3 F_78 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
return sprintf ( V_42 , L_6 , ( V_9 -> V_30 & ( 1 << V_15 ) ) ? 3 : 4 ) ;
}
static T_3 F_79 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_28 [ V_15 ] = F_18 ( V_3 ) ;
F_20 ( V_9 , F_32 ( V_15 ) , V_9 -> V_28 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_80 ( struct V_13 * V_14 , struct V_40
* V_41 , const char * V_42 , T_4 V_46 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_15 = V_44 -> V_45 ;
long V_3 ;
int V_47 ;
V_47 = F_48 ( V_42 , 10 , & V_3 ) ;
if ( V_47 )
return V_47 ;
F_25 ( & V_9 -> V_17 ) ;
V_9 -> V_29 [ V_15 ] = F_18 ( V_3 ) ;
F_20 ( V_9 , F_33 ( V_15 ) , V_9 -> V_29 [ V_15 ] ) ;
F_42 ( & V_9 -> V_17 ) ;
return V_46 ;
}
static T_3 F_81 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
return sprintf ( V_42 , L_3 , V_9 -> V_39 & 0x7ff ) ;
}
static T_3 F_82 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
return sprintf ( V_42 , L_3 , ( V_9 -> V_39 >> 16 ) & 0x07 ) ;
}
static T_3 F_83 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
return sprintf ( V_42 , L_3 , ( V_9 -> V_39 >> 11 ) & 0x07 ) ;
}
static T_3 F_84 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_23 ( V_14 ) ;
struct V_43 * V_44 = F_44 ( V_41 ) ;
int V_60 = V_44 -> V_45 ;
return sprintf ( V_42 , L_3 , ( V_9 -> V_39 >> V_60 ) & 1 ) ;
}
static T_3 F_85 ( struct V_13 * V_14 , struct V_40
* V_41 , char * V_42 )
{
struct V_8 * V_9 = F_24 ( V_14 ) ;
return sprintf ( V_42 , L_7 , V_9 -> V_61 ) ;
}
static void F_86 ( struct V_8 * V_9 )
{
T_1 V_2 ;
int V_62 ;
V_2 = F_19 ( V_9 , V_63 ) ;
if ( ( V_2 & 0x41 ) != 0x01 ) {
F_87 ( L_8 ) ;
F_20 ( V_9 , V_63 , ( V_2 | 0x01 ) & ~ 0x40 ) ;
}
for ( V_62 = 0 ; V_62 < 3 ; V_62 ++ ) {
V_9 -> V_37 [ V_62 ] = F_19 ( V_9 ,
F_38 ( V_62 ) ) ;
if ( V_9 -> V_37 [ V_62 ] & V_64 ) {
V_9 -> V_37 [ V_62 ] &= ~ V_64 ;
F_20 ( V_9 , F_38 ( V_62 ) ,
V_9 -> V_37 [ V_62 ] ) ;
}
}
}
static int F_88 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = F_89 ( & V_66 -> V_14 ) ;
struct V_8 * V_9 ;
struct V_69 * V_70 ;
int V_62 , V_47 ;
static const char * const V_71 [] = {
L_9 ,
L_10 ,
} ;
V_9 = F_90 ( & V_66 -> V_14 , sizeof( struct V_8 ) ,
V_72 ) ;
if ( ! V_9 ) {
F_91 ( L_11 ) ;
return - V_73 ;
}
V_70 = F_92 ( V_66 , V_74 , 0 ) ;
if ( ! F_93 ( & V_66 -> V_14 , V_70 -> V_75 + V_11 , 2 ,
V_76 ) ) {
F_94 ( & V_66 -> V_14 , L_12 ,
( unsigned long ) ( V_70 -> V_75 + V_11 ) ,
( unsigned long ) ( V_70 -> V_75 + V_11 + 1 ) ) ;
return - V_77 ;
}
V_9 -> V_10 = V_70 -> V_75 ;
V_9 -> V_61 = V_71 [ V_68 -> V_78 ] ;
F_95 ( & V_9 -> V_17 ) ;
F_96 ( V_66 , V_9 ) ;
switch ( V_68 -> V_78 ) {
case V_79 :
V_9 -> V_22 = 0x1ff ;
break;
case V_80 :
V_9 -> V_22 = 0x6ef ;
if ( V_68 -> V_81 & 0x01 )
V_9 -> V_22 |= ( 1 << 4 ) ;
if ( V_68 -> V_81 & 0x02 )
V_9 -> V_22 |= ( 1 << 8 ) ;
break;
}
F_86 ( V_9 ) ;
V_47 = F_97 ( & V_66 -> V_14 . V_53 , & V_82 ) ;
if ( V_47 )
return V_47 ;
if ( V_9 -> V_22 & ( 1 << 4 ) ) {
V_47 = F_97 ( & V_66 -> V_14 . V_53 ,
& V_83 [ 0 ] ) ;
if ( V_47 )
goto V_84;
}
if ( V_9 -> V_22 & ( 1 << 8 ) ) {
V_47 = F_97 ( & V_66 -> V_14 . V_53 ,
& V_83 [ 1 ] ) ;
if ( V_47 )
goto V_84;
}
if ( V_9 -> V_22 & ( 1 << 9 ) ) {
V_47 = F_97 ( & V_66 -> V_14 . V_53 ,
& V_83 [ 2 ] ) ;
if ( V_47 )
goto V_84;
}
if ( V_9 -> V_22 & ( 1 << 10 ) ) {
V_47 = F_97 ( & V_66 -> V_14 . V_53 ,
& V_83 [ 3 ] ) ;
if ( V_47 )
goto V_84;
}
for ( V_62 = 0 ; V_62 < 3 ; V_62 ++ ) {
if ( ! ( V_9 -> V_37 [ V_62 ] & V_7 ) ) {
V_47 = F_98 ( & V_66 -> V_14 . V_53 ,
V_85 [ V_62 ] ) ;
if ( V_47 )
goto V_84;
}
if ( V_9 -> V_37 [ V_62 ] & V_56 ) {
V_47 = F_67 ( & V_66 -> V_14 . V_53 ,
V_54 [ V_62 ] ,
V_55 | V_57 ) ;
if ( V_47 ) {
F_94 ( & V_66 -> V_14 , L_5 ,
V_62 + 1 ) ;
goto V_84;
}
}
}
V_9 -> V_86 = F_99 ( & V_66 -> V_14 ) ;
if ( F_100 ( V_9 -> V_86 ) ) {
V_47 = F_101 ( V_9 -> V_86 ) ;
F_94 ( & V_66 -> V_14 , L_13 , V_47 ) ;
goto V_84;
}
return 0 ;
V_84:
F_102 ( & V_66 -> V_14 . V_53 , & V_82 ) ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
F_102 ( & V_66 -> V_14 . V_53 , & V_83 [ V_62 ] ) ;
F_102 ( & V_66 -> V_14 . V_53 , & V_87 ) ;
return V_47 ;
}
static int F_103 ( struct V_65 * V_66 )
{
struct V_8 * V_9 = F_104 ( V_66 ) ;
int V_62 ;
F_105 ( V_9 -> V_86 ) ;
F_102 ( & V_66 -> V_14 . V_53 , & V_82 ) ;
for ( V_62 = 0 ; V_62 < 4 ; V_62 ++ )
F_102 ( & V_66 -> V_14 . V_53 , & V_83 [ V_62 ] ) ;
F_102 ( & V_66 -> V_14 . V_53 , & V_87 ) ;
return 0 ;
}
static int T_5 F_106 ( unsigned short V_88 ,
const struct V_67 * V_68 )
{
struct V_69 V_70 = {
. V_75 = V_88 ,
. V_89 = V_88 + V_90 - 1 ,
. V_91 = V_74 ,
} ;
int V_47 ;
V_66 = F_107 ( V_76 , V_88 ) ;
if ( ! V_66 ) {
V_47 = - V_73 ;
F_91 ( L_14 ) ;
goto exit;
}
V_70 . V_61 = V_66 -> V_61 ;
V_47 = F_108 ( & V_70 ) ;
if ( V_47 )
goto V_92;
V_47 = F_109 ( V_66 , & V_70 , 1 ) ;
if ( V_47 ) {
F_91 ( L_15 , V_47 ) ;
goto V_92;
}
V_47 = F_110 ( V_66 , V_68 ,
sizeof( struct V_67 ) ) ;
if ( V_47 ) {
F_91 ( L_16 ) ;
goto V_92;
}
V_47 = F_111 ( V_66 ) ;
if ( V_47 ) {
F_91 ( L_17 , V_47 ) ;
goto V_92;
}
return 0 ;
V_92:
F_112 ( V_66 ) ;
exit:
return V_47 ;
}
static int T_5 F_113 ( int V_93 , unsigned short * V_88 ,
struct V_67 * V_68 )
{
int V_47 = - V_94 ;
T_2 V_95 ;
static const char * const V_71 [] = {
L_18 ,
L_19 ,
} ;
F_6 ( V_93 ) ;
V_95 = F_4 ( V_93 , V_96 ) ;
if ( V_95 != V_97 )
goto exit;
V_95 = V_98 ? V_98 : F_4 ( V_93 , V_99 ) ;
switch ( V_95 ) {
case V_100 :
V_68 -> V_78 = V_79 ;
break;
case V_101 :
V_68 -> V_78 = V_80 ;
V_68 -> V_81 = F_1 ( V_93 , V_102 ) ;
break;
default:
F_114 ( L_20 ) ;
goto exit;
}
F_5 ( V_93 , V_103 ) ;
if ( ! ( F_1 ( V_93 , V_104 ) & 0x01 ) ) {
F_115 ( L_21 ) ;
goto exit;
}
* V_88 = F_4 ( V_93 , V_105 ) ;
if ( * V_88 == 0 ) {
F_115 ( L_22 ) ;
goto exit;
}
* V_88 &= ~ ( V_90 - 1 ) ;
V_47 = 0 ;
F_114 ( L_23 ,
V_71 [ V_68 -> V_78 ] , * V_88 ,
F_1 ( V_93 , V_106 ) ) ;
exit:
F_7 ( V_93 ) ;
return V_47 ;
}
static int T_5 F_116 ( void )
{
int V_47 ;
unsigned short V_88 ;
struct V_67 V_68 ;
if ( F_113 ( 0x2e , & V_88 , & V_68 )
&& F_113 ( 0x4e , & V_88 , & V_68 ) )
return - V_94 ;
V_47 = F_117 ( & V_107 ) ;
if ( V_47 )
goto exit;
V_47 = F_106 ( V_88 , & V_68 ) ;
if ( V_47 )
goto V_108;
return 0 ;
V_108:
F_118 ( & V_107 ) ;
exit:
return V_47 ;
}
static void T_6 F_119 ( void )
{
F_120 ( V_66 ) ;
F_118 ( & V_107 ) ;
}
