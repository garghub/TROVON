static inline T_1 F_1 ( long V_1 , int div )
{
if ( V_1 == 0 )
return 0 ;
return F_2 ( 1310720 / ( V_1 * div ) , 1 , 255 ) ;
}
static inline int F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_4 ( V_3 -> V_5 + V_4 ) ;
}
static inline void F_5 ( struct V_2 * V_3 , T_1 V_4 ,
T_1 V_6 )
{
F_6 ( V_6 , V_3 -> V_5 + V_4 ) ;
}
static T_2 F_7 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ( ( V_3 -> V_16 [ V_14 ] - 3 ) * 10000 ) / 958 ) ;
}
static T_2 F_10 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ( ( V_3 -> V_17 [ V_14 ] - 3 ) * 10000 ) / 958 ) ;
}
static T_2 F_11 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , ( ( ( V_3 -> V_18 [ V_14 ] - 3 ) * 10000 ) / 958 ) ) ;
}
static T_2 F_12 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_13 ( V_8 ) ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_14 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_17 [ V_14 ] = F_2 ( ( ( V_20 * 958 ) / 10000 ) + 3 , 0 , 255 ) ;
F_5 ( V_3 , V_23 [ V_14 ] , V_3 -> V_17 [ V_14 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_17 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_13 ( V_8 ) ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_14 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_18 [ V_14 ] = F_2 ( ( ( V_20 * 958 ) / 10000 ) + 3 , 0 , 255 ) ;
F_5 ( V_3 , V_24 [ V_14 ] , V_3 -> V_18 [ V_14 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_18 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
( ( ( V_3 -> V_16 [ 5 ] - 3 ) * 10000 * 54 ) / ( 958 * 34 ) ) ) ;
}
static T_2 F_19 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
( ( ( V_3 -> V_17 [ 5 ] - 3 ) * 10000 * 54 ) / ( 958 * 34 ) ) ) ;
}
static T_2 F_20 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 ,
( ( ( V_3 -> V_18 [ 5 ] - 3 ) * 10000 * 54 ) / ( 958 * 34 ) ) ) ;
}
static T_2 F_21 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_2 * V_3 = F_13 ( V_8 ) ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_14 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_17 [ 5 ] = F_2 ( ( ( V_20 * 958 * 34 ) / ( 10000 * 54 ) ) + 3 ,
0 , 255 ) ;
F_5 ( V_3 , V_23 [ 5 ] , V_3 -> V_17 [ 5 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_22 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_2 * V_3 = F_13 ( V_8 ) ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_14 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_18 [ 5 ] = F_2 ( ( ( V_20 * 958 * 34 ) / ( 10000 * 54 ) ) + 3 ,
0 , 255 ) ;
F_5 ( V_3 , V_24 [ 5 ] , V_3 -> V_18 [ 5 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_23 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_3 -> V_25 [ 0 ] * 250 ) ;
}
static T_2 F_24 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_3 -> V_26 [ 0 ] * 1000 ) ;
}
static T_2 F_25 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_3 -> V_27 [ 0 ] * 1000 ) ;
}
static T_2 F_26 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_2 * V_3 = F_13 ( V_8 ) ;
long V_20 ;
int V_21 ;
V_21 = F_27 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_26 [ 0 ] = F_2 ( ( V_20 + 500 ) / 1000 , 0 , 255 ) ;
F_5 ( V_3 , V_28 [ 0 ] , V_3 -> V_26 [ 0 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_28 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_2 * V_3 = F_13 ( V_8 ) ;
long V_20 ;
int V_21 ;
V_21 = F_27 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_27 [ 0 ] = F_2 ( ( V_20 + 500 ) / 1000 , 0 , 255 ) ;
F_5 ( V_3 , V_29 [ 0 ] , V_3 -> V_27 [ 0 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_29 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , F_30 ( V_3 -> V_25 [ V_14 ] ) ) ;
}
static T_2 F_31 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , F_32 ( V_3 -> V_26 [ V_14 ] ) ) ;
}
static T_2 F_33 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , F_32 ( V_3 -> V_27 [ V_14 ] ) ) ;
}
static T_2 F_34 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_13 ( V_8 ) ;
long V_20 ;
int V_21 ;
V_21 = F_27 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_26 [ V_14 ] = F_2 ( F_35 ( V_20 ) , 0 , 255 ) ;
F_5 ( V_3 , V_28 [ V_14 ] , V_3 -> V_26 [ V_14 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_36 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_13 ( V_8 ) ;
long V_20 ;
int V_21 ;
V_21 = F_27 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_27 [ V_14 ] = F_2 ( F_35 ( V_20 ) , 0 , 255 ) ;
F_5 ( V_3 , V_29 [ V_14 ] , V_3 -> V_27 [ V_14 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_37 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , F_38 ( V_3 -> V_30 [ V_14 ] ,
F_39 ( V_3 -> V_31 [ V_14 ] ) ) ) ;
}
static T_2 F_40 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , F_38 ( V_3 -> V_32 [ V_14 ] ,
F_39 ( V_3 -> V_31 [ V_14 ] ) ) ) ;
}
static T_2 F_41 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , F_39 ( V_3 -> V_31 [ V_14 ] ) ) ;
}
static T_2 F_42 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_12 * V_13 = F_8 ( V_10 ) ;
int V_14 = V_13 -> V_15 ;
struct V_2 * V_3 = F_13 ( V_8 ) ;
unsigned long V_20 ;
int V_21 ;
V_21 = F_14 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
V_3 -> V_32 [ V_14 ] = F_1 ( V_20 , F_39 ( V_3 -> V_31 [ V_14 ] ) ) ;
F_5 ( V_3 , F_43 ( V_14 ) , V_3 -> V_32 [ V_14 ] ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_44 ( struct V_7 * V_8 , struct V_9 * V_10 ,
const char * V_11 , T_3 V_19 )
{
struct V_2 * V_3 = F_13 ( V_8 ) ;
struct V_12 * V_13 = F_8 ( V_10 ) ;
unsigned long V_20 ;
int V_14 = V_13 -> V_15 ;
int V_33 = F_3 ( V_3 , V_34 ) ;
long V_35 = F_38 ( V_3 -> V_32 [ V_14 ] ,
F_39 ( V_3 -> V_31 [ V_14 ] ) ) ;
int V_21 ;
V_21 = F_14 ( V_11 , 10 , & V_20 ) ;
if ( V_21 )
return V_21 ;
F_15 ( & V_3 -> V_22 ) ;
switch ( V_20 ) {
case 1 :
V_3 -> V_31 [ V_14 ] = 0 ;
break;
case 2 :
V_3 -> V_31 [ V_14 ] = 1 ;
break;
case 4 :
V_3 -> V_31 [ V_14 ] = 2 ;
break;
case 8 :
V_3 -> V_31 [ V_14 ] = 3 ;
break;
default:
F_45 ( V_8 , L_2
L_3 , V_20 ) ;
F_16 ( & V_3 -> V_22 ) ;
return - V_36 ;
}
V_3 -> V_32 [ V_14 ] = F_1 ( V_35 , F_39 ( V_3 -> V_31 [ V_14 ] ) ) ;
F_5 ( V_3 , F_43 ( V_14 ) , V_3 -> V_32 [ V_14 ] ) ;
V_33 = ( V_33 & 0x0f ) | ( V_3 -> V_31 [ 1 ] << 6 ) | ( V_3 -> V_31 [ 0 ] << 4 ) ;
F_5 ( V_3 , V_34 , V_33 ) ;
F_16 ( & V_3 -> V_22 ) ;
return V_19 ;
}
static T_2 F_46 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_1 , V_3 -> V_37 ) ;
}
static T_2 F_47 ( struct V_7 * V_8 , struct V_9 * V_10 ,
char * V_11 )
{
int V_38 = F_8 ( V_10 ) -> V_15 ;
struct V_2 * V_3 = F_9 ( V_8 ) ;
return sprintf ( V_11 , L_4 , ( V_3 -> V_37 >> V_38 ) & 1 ) ;
}
static T_2 F_48 ( struct V_7 * V_8 , struct V_9
* V_39 , char * V_11 )
{
struct V_2 * V_3 = F_13 ( V_8 ) ;
return sprintf ( V_11 , L_5 , V_3 -> V_40 ) ;
}
static int F_49 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
struct V_2 * V_3 ;
int V_21 = 0 , V_45 ;
V_44 = F_50 ( V_42 , V_46 , 0 ) ;
if ( ! F_51 ( & V_42 -> V_8 , V_44 -> V_47 , V_48 ,
V_49 . V_50 . V_40 ) ) {
F_45 ( & V_42 -> V_8 , L_6 ,
( unsigned long ) V_44 -> V_47 , ( unsigned long ) V_44 -> V_51 ) ;
return - V_52 ;
}
V_3 = F_52 ( & V_42 -> V_8 , sizeof( struct V_2 ) , V_53 ) ;
if ( ! V_3 )
return - V_54 ;
F_53 ( V_42 , V_3 ) ;
V_3 -> V_5 = V_44 -> V_47 ;
V_3 -> V_40 = L_7 ;
F_54 ( & V_3 -> V_22 ) ;
F_55 ( V_3 ) ;
V_21 = F_56 ( & V_42 -> V_8 . V_55 , & V_56 ) ;
if ( V_21 )
return V_21 ;
V_3 -> V_57 = F_3 ( V_3 , V_58 ) ;
for ( V_45 = 0 ; V_45 < F_57 ( V_59 ) ; V_45 ++ ) {
if ( F_58 ( V_45 , V_3 -> V_57 ) ) {
V_21 = F_56 ( & V_42 -> V_8 . V_55 ,
& V_59 [ V_45 ] ) ;
if ( V_21 )
goto V_60;
}
}
for ( V_45 = 0 ; V_45 < F_57 ( V_61 ) ; V_45 ++ ) {
if ( F_59 ( V_45 , V_3 -> V_57 ) ) {
V_21 = F_56 ( & V_42 -> V_8 . V_55 ,
& V_61 [ V_45 ] ) ;
if ( V_21 )
goto V_60;
}
}
V_3 -> V_62 = F_60 ( & V_42 -> V_8 ) ;
if ( F_61 ( V_3 -> V_62 ) ) {
V_21 = F_62 ( V_3 -> V_62 ) ;
goto V_60;
}
return 0 ;
V_60:
for ( V_45 = 0 ; V_45 < F_57 ( V_61 ) ; V_45 ++ )
F_63 ( & V_42 -> V_8 . V_55 , & V_61 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_57 ( V_59 ) ; V_45 ++ )
F_63 ( & V_42 -> V_8 . V_55 , & V_59 [ V_45 ] ) ;
F_63 ( & V_42 -> V_8 . V_55 , & V_56 ) ;
return V_21 ;
}
static int F_64 ( struct V_41 * V_42 )
{
struct V_2 * V_3 = F_65 ( V_42 ) ;
int V_45 ;
F_66 ( V_3 -> V_62 ) ;
for ( V_45 = 0 ; V_45 < F_57 ( V_61 ) ; V_45 ++ )
F_63 ( & V_42 -> V_8 . V_55 , & V_61 [ V_45 ] ) ;
for ( V_45 = 0 ; V_45 < F_57 ( V_59 ) ; V_45 ++ )
F_63 ( & V_42 -> V_8 . V_55 , & V_59 [ V_45 ] ) ;
F_63 ( & V_42 -> V_8 . V_55 , & V_56 ) ;
return 0 ;
}
static void F_55 ( struct V_2 * V_3 )
{
F_5 ( V_3 , V_63 , 0 ) ;
F_5 ( V_3 , V_64 , 0 ) ;
}
static struct V_2 * F_9 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_13 ( V_8 ) ;
int V_45 ;
T_4 V_65 ;
F_15 ( & V_3 -> V_22 ) ;
if ( F_67 ( V_66 , V_3 -> V_67 + V_68 + V_68 / 2 )
|| ! V_3 -> V_69 ) {
for ( V_45 = 0 ; V_45 < 6 ; V_45 ++ ) {
if ( F_59 ( V_45 , V_3 -> V_57 ) ) {
V_3 -> V_16 [ V_45 ] = F_3 ( V_3 ,
V_70 [ V_45 ] ) ;
V_3 -> V_17 [ V_45 ] = F_3 ( V_3 ,
V_23 [ V_45 ] ) ;
V_3 -> V_18 [ V_45 ] = F_3 ( V_3 ,
V_24 [ V_45 ] ) ;
}
}
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
V_3 -> V_30 [ V_45 ] = F_3 ( V_3 ,
F_68 ( V_45 ) ) ;
V_3 -> V_32 [ V_45 ] = F_3 ( V_3 ,
F_43 ( V_45 ) ) ;
}
V_65 = F_3 ( V_3 , V_71 ) ;
V_65 = ( V_65 >> 6 ) | ( ( V_65 & 0x30 ) >> 2 )
| ( F_3 ( V_3 , V_72 ) << 4 ) ;
for ( V_45 = 0 ; V_45 < 6 ; V_45 ++ ) {
if ( F_58 ( V_45 , V_3 -> V_57 ) ) {
V_3 -> V_25 [ V_45 ] = ( F_3 ( V_3 ,
V_73 [ V_45 ] ) << 2 )
| ( ( V_65 >> ( 2 * V_45 ) ) & 0x03 ) ;
V_3 -> V_26 [ V_45 ] = F_3 ( V_3 ,
V_28 [ V_45 ] ) ;
V_3 -> V_27 [ V_45 ] = F_3 ( V_3 ,
V_29 [ V_45 ] ) ;
}
}
V_45 = F_3 ( V_3 , V_34 ) ;
V_3 -> V_31 [ 0 ] = ( V_45 >> 4 ) & 0x03 ;
V_3 -> V_31 [ 1 ] = V_45 >> 6 ;
V_3 -> V_37 = F_3 ( V_3 , V_74 ) |
( F_3 ( V_3 , V_75 ) << 8 ) ;
if ( ! V_3 -> V_30 [ 0 ] && V_3 -> V_32 [ 0 ] )
V_3 -> V_37 |= 0x40 ;
else if ( V_3 -> V_30 [ 0 ] && ! V_3 -> V_32 [ 0 ] )
V_3 -> V_37 &= ~ 0x40 ;
if ( ! V_3 -> V_30 [ 1 ] && V_3 -> V_32 [ 1 ] )
V_3 -> V_37 |= 0x80 ;
else if ( V_3 -> V_30 [ 1 ] && ! V_3 -> V_32 [ 1 ] )
V_3 -> V_37 &= ~ 0x80 ;
V_3 -> V_67 = V_66 ;
V_3 -> V_69 = 1 ;
}
F_16 ( & V_3 -> V_22 ) ;
return V_3 ;
}
static int F_69 ( unsigned short V_76 )
{
struct V_43 V_44 = {
. V_47 = V_76 ,
. V_51 = V_76 + V_48 - 1 ,
. V_40 = L_7 ,
. V_77 = V_46 ,
} ;
int V_21 ;
V_21 = F_70 ( & V_44 ) ;
if ( V_21 )
goto exit;
V_42 = F_71 ( L_7 , V_76 ) ;
if ( ! V_42 ) {
V_21 = - V_54 ;
F_72 ( L_8 ) ;
goto exit;
}
V_21 = F_73 ( V_42 , & V_44 , 1 ) ;
if ( V_21 ) {
F_72 ( L_9 , V_21 ) ;
goto V_78;
}
V_21 = F_74 ( V_42 ) ;
if ( V_21 ) {
F_72 ( L_10 , V_21 ) ;
goto V_78;
}
return 0 ;
V_78:
F_75 ( V_42 ) ;
exit:
return V_21 ;
}
static int F_76 ( struct V_79 * V_8 ,
const struct V_80 * V_81 )
{
T_4 V_76 , V_20 ;
if ( V_82 ) {
V_76 = V_82 & 0xff00 ;
F_77 ( & V_8 -> V_8 , L_11 ,
V_76 ) ;
if ( V_83 !=
F_78 ( V_8 , V_84 , V_76 | 1 ) )
return - V_52 ;
}
if ( V_83 != F_79 ( V_8 , V_84 ,
& V_20 ) )
return - V_52 ;
V_76 = V_20 & ~ ( V_48 - 1 ) ;
if ( V_76 == 0 ) {
F_45 ( & V_8 -> V_8 , L_12 ) ;
return - V_52 ;
}
if ( V_83 != F_79 ( V_8 , V_85 ,
& V_20 ) )
return - V_52 ;
if ( ! ( V_20 & 0x0001 ) ) {
F_77 ( & V_8 -> V_8 , L_13 ) ;
if ( V_83 !=
F_78 ( V_8 , V_85 ,
V_20 | 0x0001 ) )
return - V_52 ;
}
if ( F_80 ( & V_49 ) )
goto exit;
if ( F_69 ( V_76 ) )
goto V_86;
V_87 = F_81 ( V_8 ) ;
return - V_52 ;
V_86:
F_82 ( & V_49 ) ;
exit:
return - V_52 ;
}
static int T_5 F_83 ( void )
{
return F_84 ( & V_88 ) ;
}
static void T_6 F_85 ( void )
{
F_86 ( & V_88 ) ;
if ( V_87 != NULL ) {
F_87 ( V_42 ) ;
F_82 ( & V_49 ) ;
F_88 ( V_87 ) ;
V_87 = NULL ;
}
}
