static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
if ( V_3 < 0x80 ) {
V_4 = F_2 ( V_2 , V_3 ) & 0xff ;
} else {
V_4 = 0 ;
}
return V_4 ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , int V_5 )
{
int V_4 ;
if ( V_3 < 0x80 ) {
V_4 = F_4 ( V_2 , V_3 , V_5 ) ;
} else {
V_4 = 0 ;
}
return V_4 ;
}
static struct V_6 * F_5 ( struct V_7 * V_8 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_10 ;
long V_5 , V_11 , V_12 ;
F_7 ( & V_9 -> V_13 ) ;
if ( ! V_9 -> V_14
|| F_8 ( V_15 ,
V_9 -> V_16 + V_17 ) ) {
F_9 ( & V_2 -> V_8 , L_1 ) ;
for ( V_10 = 0 ; V_10 <= 16 ; ++ V_10 ) {
V_9 -> V_18 [ V_10 ] =
F_1 ( V_2 , V_19 [ V_10 ] ) ;
}
for ( V_10 = 0 ; V_10 <= 7 ; ++ V_10 ) {
V_9 -> V_20 [ V_10 ] =
F_1 ( V_2 , F_10 ( V_10 ) ) ;
}
for ( V_10 = 0 ; V_10 <= 2 ; ++ V_10 ) {
V_9 -> V_21 [ V_10 ] =
F_1 ( V_2 , V_22 [ V_10 ] ) ;
}
V_9 -> V_23 . V_24 = F_1 ( V_2 ,
V_25 ) ;
V_9 -> V_26 = F_1 ( V_2 ,
V_27 ) ;
V_11 = F_1 ( V_2 , V_28 ) ;
V_12 = V_11 & 0x80 ? 0x0100 : 0 ;
V_11 &= 0x7f ;
V_11 <<= 8 ;
V_11 |= F_1 ( V_2 , V_29 ) ;
V_11 <<= 8 ;
V_11 |= F_1 ( V_2 , V_30 ) ;
V_11 <<= 8 ;
V_11 |= F_1 ( V_2 , V_31 ) ;
V_9 -> V_11 = V_11 ;
V_12 |= F_1 ( V_2 ,
V_32 ) ;
V_12 <<= 8 ;
V_12 |= F_1 ( V_2 ,
V_33 ) ;
V_9 -> V_12 = V_12 ;
V_9 -> V_16 = V_15 ;
}
if ( ! V_9 -> V_14 ||
F_8 ( V_15 , V_9 -> V_34 + V_35 ) ) {
F_9 ( & V_2 -> V_8 , L_2 ) ;
for ( V_10 = 0 ; V_10 <= 16 ; ++ V_10 ) {
V_9 -> V_36 [ V_10 ] = F_1 ( V_2 ,
V_37 [ V_10 ] ) ;
V_9 -> V_38 [ V_10 ] = F_1 ( V_2 ,
V_39 [ V_10 ] ) ;
}
V_5 = F_1 ( V_2 , V_40 )
| ( F_1 ( V_2 , V_41 )
<< 8 ) ;
for ( V_10 = 0 ; V_10 <= 7 ; ++ V_10 ) {
V_9 -> V_42 [ V_10 ] = F_1 ( V_2 ,
F_11 ( V_10 ) ) ;
V_9 -> V_43 [ V_10 ] = F_12 ( V_5 & 0x03 ) ;
V_5 >>= 2 ;
}
for ( V_10 = 0 ; V_10 <= 2 ; ++ V_10 ) {
V_9 -> V_44 [ V_10 ] = F_1 ( V_2 ,
V_45 [ V_10 ] ) ;
V_9 -> V_46 [ V_10 ] = F_1 ( V_2 ,
V_47 [ V_10 ] ) ;
V_9 -> V_48 [ V_10 ] = F_1 ( V_2 ,
V_49 [ V_10 ] ) ;
V_9 -> V_50 [ V_10 ] = F_1 ( V_2 ,
V_51 [ V_10 ] ) ;
V_9 -> V_52 [ V_10 ] = F_1 ( V_2 ,
V_53 [ V_10 ] ) ;
}
V_11 = F_1 ( V_2 , V_54 ) ;
V_12 = V_11 & 0x80 ? 0x0100 : 0 ;
V_11 = ( V_11 & 0x7f ) << 8 ;
V_11 |= F_1 ( V_2 , V_55 ) ;
V_11 <<= 8 ;
V_11 |= F_1 ( V_2 , V_56 ) ;
V_11 <<= 8 ;
V_11 |= F_1 ( V_2 , V_57 ) ;
V_9 -> V_58 = V_11 ;
V_12 |= F_1 ( V_2 ,
V_59 ) ;
V_12 <<= 8 ;
V_12 |= F_1 ( V_2 , V_60 ) ;
V_9 -> V_61 = V_12 ;
V_9 -> V_62 = F_1 ( V_2 ,
V_63 ) ;
if ( V_9 -> V_62 & V_64 ) {
V_9 -> V_23 . V_65 = 2 ;
V_9 -> V_23 . V_66 =
F_13 ( V_9 -> V_23 . V_24 ) ;
}
V_9 -> V_67 = F_1 ( V_2 ,
V_68 ) ;
V_9 -> V_69 = F_1 ( V_2 ,
V_70 ) ;
V_9 -> V_71 [ 16 ] = ( V_9 -> V_69 >> 6 ) & 0x03 ;
V_5 = 0 ;
for ( V_10 = 0 ; V_10 <= 15 ; ++ V_10 ) {
if ( ( V_10 & 0x03 ) == 0 ) {
V_5 = F_1 ( V_2 ,
V_72 + V_10 / 4 ) ;
}
V_9 -> V_71 [ V_10 ] = V_5 & 0x03 ;
V_5 >>= 2 ;
}
V_9 -> V_34 = V_15 ;
}
V_9 -> V_14 = 1 ;
F_14 ( & V_9 -> V_13 ) ;
return V_9 ;
}
static T_2 F_15 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_17 ( V_78 , V_9 -> V_18 [ V_78 ] ) ) ;
}
static T_2 F_18 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_17 ( V_78 , V_9 -> V_36 [ V_78 ] ) ) ;
}
static T_2 F_19 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_36 [ V_78 ] = F_21 ( V_78 , V_81 ) ;
F_3 ( V_2 , V_37 [ V_78 ] , V_9 -> V_36 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_22 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_17 ( V_78 , V_9 -> V_38 [ V_78 ] ) ) ;
}
static T_2 F_23 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_38 [ V_78 ] = F_21 ( V_78 , V_81 ) ;
F_3 ( V_2 , V_39 [ V_78 ] , V_9 -> V_38 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_24 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_17 ( 16 , V_9 -> V_18 [ 16 ] ) -
V_83 ) ;
}
static T_2 F_25 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_17 ( 16 , V_9 -> V_36 [ 16 ] )
- V_83 ) ;
}
static T_2 F_26 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_36 [ 16 ] = F_21 ( 16 , V_81 + V_83 ) ;
F_3 ( V_2 , V_37 [ 16 ] , V_9 -> V_36 [ 16 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_27 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_17 ( 16 , V_9 -> V_38 [ 16 ] )
- V_83 ) ;
}
static T_2 F_28 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_38 [ 16 ] = F_21 ( 16 , V_81 + V_83 ) ;
F_3 ( V_2 , V_39 [ 16 ] , V_9 -> V_38 [ 16 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_29 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_30 ( V_9 -> V_20 [ V_78 ] ,
V_9 -> V_43 [ V_78 ] ) ) ;
}
static T_2 F_31 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_30 ( V_9 -> V_42 [ V_78 ] ,
V_9 -> V_43 [ V_78 ] ) ) ;
}
static T_2 F_32 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_42 [ V_78 ] = F_33 ( V_81 , V_9 -> V_43 [ V_78 ] ) ;
F_3 ( V_2 , F_11 ( V_78 ) ,
V_9 -> V_42 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static void F_34 ( struct V_7 * V_8 , int V_20 , int V_84 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_85 ;
int V_86 = V_9 -> V_43 [ V_20 ] ;
if ( V_9 -> V_42 [ V_20 ] == 0 || V_9 -> V_42 [ V_20 ] == 0xff )
return;
V_85 = V_9 -> V_42 [ V_20 ] * V_84 / V_86 ;
V_85 = F_35 ( V_85 , 1 , 254 ) ;
V_9 -> V_42 [ V_20 ] = V_85 ;
F_3 ( V_2 , F_11 ( V_20 ) , V_85 ) ;
}
static T_2 F_36 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , V_9 -> V_43 [ V_78 ] ) ;
}
static T_2 F_37 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_87 , V_86 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
V_86 = F_38 ( V_81 ) ;
F_7 ( & V_9 -> V_13 ) ;
V_87 = V_9 -> V_43 [ V_78 ] ;
V_9 -> V_43 [ V_78 ] = F_12 ( V_86 ) ;
if ( V_78 < 4 ) {
F_3 ( V_2 , V_40 ,
( F_38 ( V_9 -> V_43 [ 0 ] ) << 0 ) |
( F_38 ( V_9 -> V_43 [ 1 ] ) << 2 ) |
( F_38 ( V_9 -> V_43 [ 2 ] ) << 4 ) |
( F_38 ( V_9 -> V_43 [ 3 ] ) << 6 ) ) ;
} else {
F_3 ( V_2 , V_41 ,
( F_38 ( V_9 -> V_43 [ 4 ] ) << 0 ) |
( F_38 ( V_9 -> V_43 [ 5 ] ) << 2 ) |
( F_38 ( V_9 -> V_43 [ 6 ] ) << 4 ) |
( F_38 ( V_9 -> V_43 [ 7 ] ) << 6 ) ) ;
}
if ( V_9 -> V_43 [ V_78 ] != V_87 )
F_34 ( V_8 , V_78 , V_87 ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_39 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 ( V_9 -> V_21 [ V_78 ] ) ) ;
}
static T_2 F_41 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 ( V_9 -> V_44 [ V_78 ] ) ) ;
}
static T_2 F_42 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_44 [ V_78 ] = F_43 ( V_81 ) ;
F_3 ( V_2 , V_45 [ V_78 ] ,
V_9 -> V_44 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_44 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 ( V_9 -> V_46 [ V_78 ] ) ) ;
}
static T_2 F_45 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_46 [ V_78 ] = F_43 ( V_81 ) ;
F_3 ( V_2 , V_47 [ V_78 ] ,
V_9 -> V_46 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_46 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 ( V_9 -> V_52 [ V_78 ] ) ) ;
}
static T_2 F_47 ( struct V_7 * V_8 ,
struct V_73 * V_74 , const char * V_75 ,
T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_52 [ V_78 ] = F_43 ( V_81 ) ;
F_3 ( V_2 , V_53 [ V_78 ] ,
V_9 -> V_52 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_48 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 (
V_88 + V_9 -> V_48 [ V_78 ] ) ) ;
}
static T_2 F_49 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 ( V_9 -> V_48 [ V_78 ] +
V_89 ) ) ;
}
static T_2 F_50 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 ( V_9 -> V_48 [ V_78 ] ) ) ;
}
static T_2 F_51 ( struct V_7 * V_8 ,
struct V_73 * V_74 , const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_48 [ V_78 ] = F_43 ( V_81 ) ;
F_3 ( V_2 , V_49 [ V_78 ] ,
V_9 -> V_48 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_52 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , ( V_9 -> V_62 & V_90 ) >> 4 ) ;
}
static T_2 F_53 ( struct V_7 * V_8 ,
struct V_73 * V_74 , const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_81 ;
int V_82 ;
V_82 = F_54 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
if ( V_81 > 1 )
return - V_91 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_62 = ( V_9 -> V_62 & ~ V_90 ) | ( V_81 << 4 ) ;
F_3 ( V_2 , V_63 , V_9 -> V_62 ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_55 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_40 ( V_9 -> V_50 [ V_78 ] ) ) ;
}
static T_2 F_56 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_76 * V_77 = F_16 ( V_74 ) ;
int V_78 = V_77 -> V_79 ;
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_50 [ V_78 ] = F_43 ( V_81 ) ;
F_3 ( V_2 , V_51 [ V_78 ] ,
V_9 -> V_50 [ V_78 ] ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_57 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_58 ( V_9 -> V_26 ) ) ;
}
static T_2 F_59 ( struct V_7 * V_8 ,
struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_26 = F_60 ( V_81 ) ;
F_3 ( V_2 , V_27 , V_9 -> V_26 ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_61 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
int V_92 = ( V_9 -> V_12 >> 11 ) & 0x1f ;
F_9 ( V_8 , L_4 ) ;
return sprintf ( V_75 , L_3 , F_62 ( V_92 , V_9 -> V_93 ) ) ;
}
static T_2 F_63 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
return sprintf ( V_75 , L_3 , V_9 -> V_93 ) ;
}
static T_2 F_64 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
unsigned long V_81 ;
int V_82 ;
V_82 = F_54 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
if ( V_81 > 255 )
return - V_91 ;
V_9 -> V_93 = V_81 ;
return V_80 ;
}
static T_2 F_65 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_5 , V_9 -> V_11 ) ;
}
static T_2 F_66 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
int V_94 = F_16 ( V_74 ) -> V_79 ;
return sprintf ( V_75 , L_5 , ( V_9 -> V_11 >> V_94 ) & 1 ) ;
}
static T_2 F_67 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_5 , V_9 -> V_58 ) ;
}
static T_2 F_68 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_95 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_58 = V_81 & 0x7fffffff ;
V_95 = V_9 -> V_58
| ( V_9 -> V_61 & 0x10000 ? 0x80000000 : 0 ) ;
F_3 ( V_2 , V_57 ,
V_95 & 0xff ) ;
V_95 >>= 8 ;
F_3 ( V_2 , V_56 ,
V_95 & 0xff ) ;
V_95 >>= 8 ;
F_3 ( V_2 , V_55 ,
V_95 & 0xff ) ;
V_95 >>= 8 ;
F_3 ( V_2 , V_54 ,
V_95 & 0xff ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_69 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_5 , V_9 -> V_12 ) ;
}
static T_2 F_70 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_12 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_12 = V_81 & 0x1ffff ;
V_12 = V_9 -> V_12 ;
F_3 ( V_2 , V_33 , V_12 & 0xff ) ;
V_12 >>= 8 ;
F_3 ( V_2 , V_32 , V_12 & 0xff ) ;
V_12 = ( ( V_12 >> 1 ) & 0x80 ) | ( V_9 -> V_11 >> 24 & 0x7f ) ;
F_3 ( V_2 , V_28 , V_12 & 0xff ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_71 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_5 , V_9 -> V_61 ) ;
}
static T_2 F_72 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
long V_95 ;
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_61 = V_81 & 0x1ffff ;
V_95 = V_9 -> V_61 ;
F_3 ( V_2 , V_60 , V_95 & 0xff ) ;
V_95 >>= 8 ;
F_3 ( V_2 , V_59 , V_95 & 0xff ) ;
V_95 = ( ( V_95 >> 1 ) & 0x80 ) | ( V_9 -> V_58 >> 24 & 0x7f ) ;
F_3 ( V_2 , V_57 , V_95 & 0xff ) ;
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_73 ( struct V_7 * V_8 , struct V_73 * V_74 ,
char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , F_74 ( V_9 -> V_23 . V_24 ) ) ;
}
static T_2 F_75 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
if ( V_9 -> V_23 . V_65 == 1 ) {
long V_81 ;
int V_82 ;
V_82 = F_20 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_23 . V_24 = F_76 ( V_81 ) ;
F_3 ( V_2 , V_25 , V_9 -> V_23 . V_24 ) ;
F_14 ( & V_9 -> V_13 ) ;
}
return V_80 ;
}
static T_2 F_77 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , V_9 -> V_23 . V_66 ) ;
}
static T_2 F_78 ( struct V_7 * V_8 ,
struct V_73 * V_74 , const char * V_75 ,
T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
unsigned long V_81 ;
int V_82 ;
V_82 = F_54 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
F_7 ( & V_9 -> V_13 ) ;
V_9 -> V_23 . V_66 = F_35 ( V_81 , 0 , 255 ) ;
if ( V_9 -> V_23 . V_65 == 2 ) {
V_9 -> V_23 . V_24 = F_76 ( ( V_9 -> V_23 . V_24 & 0x0f ) |
F_79 ( V_9 -> V_23 . V_66 ) ) ;
F_3 ( V_2 , V_25 , V_9 -> V_23 . V_24 ) ;
}
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static T_2 F_80 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
return sprintf ( V_75 , L_3 , V_96 ) ;
}
static T_2 F_81 ( struct V_7 * V_8 ,
struct V_73 * V_74 , char * V_75 )
{
struct V_6 * V_9 = F_5 ( V_8 ) ;
return sprintf ( V_75 , L_3 , V_9 -> V_23 . V_65 ) ;
}
static T_2 F_82 ( struct V_7 * V_8 , struct V_73 * V_74 ,
const char * V_75 , T_3 V_80 )
{
struct V_6 * V_9 = F_6 ( V_8 ) ;
struct V_1 * V_2 = V_9 -> V_2 ;
int V_97 ;
unsigned long V_81 ;
int V_82 ;
V_82 = F_54 ( V_75 , 10 , & V_81 ) ;
if ( V_82 )
return V_82 ;
if ( V_81 >= 3 )
return - V_91 ;
F_7 ( & V_9 -> V_13 ) ;
V_97 = V_9 -> V_23 . V_65 ;
V_9 -> V_23 . V_65 = V_81 ;
V_9 -> V_62 = ( V_9 -> V_62 & ~ V_64 )
| ( ( V_81 == 2 ) ? V_64 : 0 ) ;
F_3 ( V_2 , V_63 , V_9 -> V_62 ) ;
if ( V_81 == 2 ) {
V_9 -> V_23 . V_24 = F_76 ( ( V_9 -> V_23 . V_24 & 0x0f ) |
F_79 ( V_9 -> V_23 . V_66 ) ) ;
F_3 ( V_2 , V_25 , V_9 -> V_23 . V_24 ) ;
} else if ( ! ( ( V_97 == 1 ) && ( V_81 == 1 ) ) ) {
V_9 -> V_23 . V_24 = 255 ;
F_3 ( V_2 , V_25 , V_9 -> V_23 . V_24 ) ;
}
F_14 ( & V_9 -> V_13 ) ;
return V_80 ;
}
static int F_83 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_100 * V_101 = V_2 -> V_101 ;
int V_102 = V_2 -> V_103 ;
int V_104 , V_105 ;
if ( ! F_84 ( V_101 , V_106 ) ) {
return - V_107 ;
}
V_104 = F_1 ( V_2 , V_108 ) ;
V_105 = F_1 ( V_2 , V_109 ) ;
F_9 ( & V_101 -> V_8 ,
L_6 ,
F_85 ( V_2 -> V_101 ) , V_2 -> V_103 ,
V_104 , V_105 ) ;
F_9 ( & V_101 -> V_8 , L_7 ,
F_85 ( V_101 ) , V_102 ) ;
if ( V_104 == V_110
&& V_105 == V_111 ) {
} else if ( V_104 == V_110
&& ( V_105 & 0xf0 ) == V_112 ) {
F_86 ( & V_101 -> V_8 ,
L_8 ,
V_105 ) ;
} else if ( ( V_105 & 0xf0 ) == V_112 ) {
F_86 ( & V_101 -> V_8 ,
L_9 ,
V_105 ) ;
} else {
F_9 ( & V_101 -> V_8 , L_10 ) ;
return - V_107 ;
}
F_87 ( V_99 -> type , L_11 , V_113 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_6 * V_9 = F_89 ( V_2 ) ;
int V_10 ;
F_9 ( & V_2 -> V_8 , L_12 ) ;
for ( V_10 = 0 ; V_10 <= 7 ; ++ V_10 ) {
if ( V_9 -> V_67 & ( 1 << V_10 ) ) {
F_9 ( & V_2 -> V_8 , L_13 ,
V_9 -> V_71 [ V_10 ] & 0x02 ? L_14 : L_15 ,
V_9 -> V_71 [ V_10 ] & 0x01 ? L_16 : L_17 ,
V_10 ) ;
} else {
F_9 ( & V_2 -> V_8 , L_18 , V_10 ) ;
}
}
for ( V_10 = 8 ; V_10 <= 15 ; ++ V_10 ) {
F_9 ( & V_2 -> V_8 , L_13 ,
V_9 -> V_71 [ V_10 ] & 0x02 ? L_14 : L_15 ,
V_9 -> V_71 [ V_10 ] & 0x01 ? L_16 : L_17 ,
V_10 ) ;
}
if ( V_9 -> V_69 & V_114 ) {
F_9 ( & V_2 -> V_8 , L_19 ,
V_9 -> V_71 [ 16 ] & 0x02 ? L_14 : L_15 ,
V_9 -> V_71 [ 16 ] & 0x01 ? L_16 : L_17 ) ;
} else {
F_9 ( & V_2 -> V_8 , L_20 ) ;
}
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_6 * V_9 = F_89 ( V_2 ) ;
int V_10 ;
int V_5 ;
for ( V_10 = 0 ; V_10 <= 16 ; ++ V_10 ) {
if ( V_115 [ V_10 ] >= 0 && V_115 [ V_10 ] <= 16 )
V_9 -> V_71 [ V_115 [ V_10 ] ] |= 0x01 ;
if ( V_115 [ V_10 ] >= 0 && V_115 [ V_10 ] <= 7 )
V_9 -> V_67 |= 1 << V_115 [ V_10 ] ;
}
for ( V_10 = 0 ; V_10 <= 16 ; ++ V_10 ) {
if ( V_116 [ V_10 ] >= 0 && V_116 [ V_10 ] <= 16 )
V_9 -> V_71 [ V_116 [ V_10 ] ] &= ~ 0x01 ;
if ( V_116 [ V_10 ] >= 0 && V_116 [ V_10 ] <= 7 )
V_9 -> V_67 |= 1 << V_116 [ V_10 ] ;
}
for ( V_10 = 0 ; V_10 <= 16 ; ++ V_10 ) {
if ( V_117 [ V_10 ] >= 0 && V_117 [ V_10 ] <= 16 )
V_9 -> V_71 [ V_117 [ V_10 ] ] &= ~ 0x02 ;
}
for ( V_10 = 0 ; V_10 <= 16 ; ++ V_10 ) {
if ( V_118 [ V_10 ] >= 0 && V_118 [ V_10 ] <= 16 )
V_9 -> V_71 [ V_118 [ V_10 ] ] |= 0x02 ;
}
for ( V_10 = 0 ; V_10 <= 7 ; ++ V_10 ) {
if ( V_119 [ V_10 ] >= 0 && V_119 [ V_10 ] <= 7 )
V_9 -> V_67 &= ~ ( 1 << V_119 [ V_10 ] ) ;
}
F_3 ( V_2 , V_68 , V_9 -> V_67 ) ;
V_9 -> V_69 = ( V_9 -> V_69 & 0x3f )
| ( ( V_9 -> V_71 [ 16 ] & 0x03 ) << 6 ) ;
F_3 ( V_2 , V_70 , V_9 -> V_69 ) ;
for ( V_10 = 15 , V_5 = 0 ; V_10 >= 0 ; -- V_10 ) {
V_5 <<= 2 ;
V_5 |= V_9 -> V_71 [ V_10 ] & 0x03 ;
if ( ( V_10 & 0x03 ) == 0 ) {
F_3 ( V_2 ,
V_72 + V_10 / 4 ,
V_5 ) ;
V_5 = 0 ;
}
}
F_88 ( V_2 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_5 , V_10 ;
struct V_6 * V_9 = F_89 ( V_2 ) ;
F_9 ( & V_2 -> V_8 , L_21 ) ;
V_9 -> V_62 = F_1 ( V_2 , V_63 ) ;
V_9 -> V_67 = F_1 ( V_2 , V_68 ) ;
V_9 -> V_69 = F_1 ( V_2 , V_70 ) ;
F_9 ( & V_2 -> V_8 , L_22 ,
V_9 -> V_62 ) ;
if ( ( V_9 -> V_62 & V_120 ) == 0 ) {
F_9 ( & V_2 -> V_8 ,
L_23 ) ;
}
if ( V_9 -> V_62 & V_121 ) {
F_9 ( & V_2 -> V_8 ,
L_24 ) ;
}
if ( V_9 -> V_62 & V_122 ) {
F_9 ( & V_2 -> V_8 ,
L_25 ) ;
} else {
F_9 ( & V_2 -> V_8 ,
L_26 ) ;
}
if ( V_9 -> V_62 & V_90 ) {
F_9 ( & V_2 -> V_8 ,
L_27 ) ;
}
if ( V_9 -> V_69 & V_114 ) {
F_9 ( & V_2 -> V_8 ,
L_28 ) ;
} else {
F_9 ( & V_2 -> V_8 ,
L_29 ) ;
}
if ( V_9 -> V_69 & V_123 )
F_9 ( & V_2 -> V_8 , L_30 ) ;
else
F_9 ( & V_2 -> V_8 , L_31 ) ;
V_5 = 0 ;
for ( V_10 = 0 ; V_10 <= 15 ; ++ V_10 ) {
if ( ( V_10 & 0x03 ) == 0 ) {
V_5 = F_1 ( V_2 ,
V_72 + V_10 / 4 ) ;
}
V_9 -> V_71 [ V_10 ] = V_5 & 0x03 ;
V_5 >>= 2 ;
}
V_9 -> V_71 [ 16 ] = ( V_9 -> V_69 >> 6 ) & 0x03 ;
F_88 ( V_2 ) ;
if ( V_116 [ 0 ] != - 1 || V_115 [ 0 ] != - 1
|| V_117 [ 0 ] != - 1 || V_118 [ 0 ] != - 1
|| V_119 [ 0 ] != - 1 ) {
F_90 ( V_2 ) ;
}
V_9 -> V_23 . V_66 = 255 ;
V_5 = F_1 ( V_2 , V_63 ) ;
V_5 = ( V_5 | V_120 ) & ( ~ V_124 & ~ V_125 ) ;
F_9 ( & V_2 -> V_8 , L_32 , V_5 ) ;
V_9 -> V_62 = V_5 ;
F_3 ( V_2 , V_63 , V_5 ) ;
V_5 = F_1 ( V_2 , V_40 ) |
( F_1 ( V_2 , V_41 ) << 8 ) ;
for ( V_10 = 0 ; V_10 <= 7 ; ++ V_10 ) {
V_9 -> V_43 [ V_10 ] = F_12 ( V_5 & 0x03 ) ;
V_5 >>= 2 ;
}
}
static int F_92 ( struct V_1 * V_2 ,
const struct V_126 * V_127 )
{
struct V_7 * V_8 = & V_2 -> V_8 ;
struct V_7 * V_128 ;
struct V_6 * V_9 ;
V_9 = F_93 ( V_8 , sizeof( struct V_6 ) , V_129 ) ;
if ( ! V_9 )
return - V_130 ;
F_94 ( V_2 , V_9 ) ;
V_9 -> V_2 = V_2 ;
F_95 ( & V_9 -> V_13 ) ;
V_9 -> V_93 = F_96 () ;
F_91 ( V_2 ) ;
V_9 -> V_131 [ 0 ] = & V_132 ;
if ( V_9 -> V_62 & V_122 )
V_9 -> V_131 [ 1 ] = & V_133 ;
else
V_9 -> V_131 [ 1 ] = & V_134 ;
V_128 = F_97 ( V_8 , V_2 -> V_135 ,
V_9 , V_9 -> V_131 ) ;
return F_98 ( V_128 ) ;
}
