static T_1 F_1 ( struct V_1 * V_1 , T_2 V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
int V_5 ;
if ( V_1 -> V_6 < 0 )
return 0 ;
V_5 = F_2 ( V_4 , F_3 ( V_4 , 0 ) ,
0x00 ,
V_7 | V_8 | V_9 ,
0x00 ,
V_2 ,
V_1 -> V_10 , 1 ,
500 ) ;
F_4 ( V_11 , L_1 , V_2 , V_1 -> V_10 [ 0 ] ) ;
if ( V_5 < 0 ) {
F_5 ( L_2 , V_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
return 0 ;
}
return V_1 -> V_10 [ 0 ] ;
}
static void F_6 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_12 )
{
int V_5 ;
struct V_3 * V_4 = V_1 -> V_4 ;
if ( V_1 -> V_6 < 0 )
return;
V_5 = F_2 ( V_4 , F_7 ( V_4 , 0 ) ,
0x01 ,
V_13 | V_8 | V_9 ,
V_12 ,
V_2 ,
NULL ,
0 ,
500 ) ;
F_4 ( V_14 , L_3 , V_2 , V_12 ) ;
if ( V_5 < 0 ) {
F_5 ( L_4 , V_2 , V_5 ) ;
V_1 -> V_6 = V_5 ;
}
}
static void F_8 ( struct V_1 * V_1 , T_2 V_2 , T_1 V_12 , T_1 V_15 )
{
V_12 = ( F_1 ( V_1 , V_2 ) & ~ V_15 ) | ( V_12 & V_15 ) ;
F_6 ( V_1 , V_2 , V_12 ) ;
}
static int F_9 ( struct V_1 * V_1 ,
const struct V_16 * V_17 )
{
V_1 -> V_18 . V_19 = V_20 ;
V_1 -> V_18 . V_21 = F_10 ( V_20 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_1 )
{
int V_22 = 0 ;
T_1 V_12 ;
do {
V_12 = F_1 ( V_1 , V_23 + 1 ) ;
if ( V_22 ++ > 500 ) {
F_5 ( L_5 , V_12 ) ;
return - 1 ;
}
} while ( ( V_12 & 0x10 ) || ! ( V_12 & 0x05 ) );
return 0 ;
}
static T_1 F_12 ( struct V_1 * V_1 , T_1 V_24 )
{
F_6 ( V_1 , V_25 , V_24 ) ;
F_6 ( V_1 , V_23 , 0x20 ) ;
if ( F_11 ( V_1 ) ) {
F_5 ( L_6 ) ;
return 0 ;
}
return F_1 ( V_1 , V_25 + 1 ) ;
}
static T_2 F_13 ( struct V_1 * V_1 , T_1 V_24 )
{
return ( F_12 ( V_1 , V_24 ) << 8 ) |
F_12 ( V_1 , 0xf1 ) ;
}
static void F_14 ( struct V_1 * V_1 , T_1 V_24 , T_1 V_26 )
{
F_6 ( V_1 , V_27 , V_24 ) ;
F_6 ( V_1 , V_27 + 1 , V_26 ) ;
F_6 ( V_1 , V_23 , 0x01 ) ;
if ( F_11 ( V_1 ) ) {
F_5 ( L_7 ) ;
return;
}
}
static void F_15 ( struct V_1 * V_1 , T_1 V_24 , T_2 V_26 )
{
F_14 ( V_1 , V_24 , V_26 >> 8 ) ;
F_14 ( V_1 , 0xf1 , V_26 & 0xff ) ;
}
static void F_16 ( struct V_1 * V_1 , T_1 V_28 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
if ( V_28 != V_29 -> V_30 ) {
F_15 ( V_1 , 0xf0 , V_28 ) ;
V_29 -> V_30 = V_28 ;
}
}
static T_2 F_17 ( struct V_1 * V_1 , T_2 V_31 )
{
F_16 ( V_1 , V_31 >> 8 ) ;
return F_13 ( V_1 , V_31 & 0xff ) ;
}
static void F_18 ( struct V_1 * V_1 , T_2 V_31 , T_2 V_12 )
{
F_16 ( V_1 , V_31 >> 8 ) ;
F_15 ( V_1 , V_31 & 0xff , V_12 ) ;
}
static void F_19 ( struct V_1 * V_1 ,
T_2 V_31 , T_2 V_12 , T_2 V_15 )
{
V_12 = ( F_17 ( V_1 , V_31 ) & ~ V_15 ) | ( V_12 & V_15 ) ;
F_18 ( V_1 , V_31 , V_12 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
static const struct V_32 V_33 [] = {
{ 0x00d , 0x000b } , { 0x00d , 0x0008 } , { 0x035 , 0x0022 } ,
{ 0x106 , 0x700e } ,
{ 0x2dd , 0x18e0 } ,
{ 0x21f , 0x0180 } ,
{ 0x220 , 0xc814 } , { 0x221 , 0x8080 } ,
{ 0x222 , 0xa078 } , { 0x223 , 0xa078 } ,
{ 0x224 , 0x5f20 } , { 0x228 , 0xea02 } ,
{ 0x229 , 0x867a } ,
{ 0x25e , 0x594c } , { 0x25f , 0x4d51 } , { 0x260 , 0x0002 } ,
{ 0x2ef , 0x0008 } , { 0x2f2 , 0x0000 } ,
{ 0x202 , 0x00ee } , { 0x203 , 0x3923 } , { 0x204 , 0x0724 } ,
{ 0x209 , 0x00cd } , { 0x20a , 0x0093 } , { 0x20b , 0x0004 } ,
{ 0x20c , 0x005c } , { 0x20d , 0x00d9 } , { 0x20e , 0x0053 } ,
{ 0x20f , 0x0008 } , { 0x210 , 0x0091 } , { 0x211 , 0x00cf } ,
{ 0x215 , 0x0000 } ,
{ 0x216 , 0x0000 } , { 0x217 , 0x0000 } , { 0x218 , 0x0000 } ,
{ 0x219 , 0x0000 } , { 0x21a , 0x0000 } , { 0x21b , 0x0000 } ,
{ 0x21c , 0x0000 } , { 0x21d , 0x0000 } , { 0x21e , 0x0000 } ,
{ 0x106 , 0xf00e } , { 0x106 , 0x700e } ,
{ 0x180 , 0x0007 } ,
{ 0x181 , 0xde13 } , { 0x182 , 0xebe2 } , { 0x183 , 0x00f6 } ,
{ 0x184 , 0xe114 } , { 0x185 , 0xeadd } , { 0x186 , 0xfdf6 } ,
{ 0x187 , 0xe511 } , { 0x188 , 0xede6 } , { 0x189 , 0xfbf7 } ,
{ 0x18a , 0xd613 } , { 0x18b , 0xedec } ,
{ 0x18c , 0xf9f2 } , { 0x18d , 0x0000 } ,
{ 0x18e , 0xd815 } , { 0x18f , 0xe9ea } ,
{ 0x190 , 0xf9f1 } , { 0x191 , 0x0002 } ,
{ 0x192 , 0xde10 } , { 0x193 , 0xefef } ,
{ 0x194 , 0xfbf4 } , { 0x195 , 0x0002 } ,
{ 0x1b6 , 0x0e06 } , { 0x1b7 , 0x2713 } ,
{ 0x1b8 , 0x1106 } , { 0x1b9 , 0x2713 } ,
{ 0x1ba , 0x0c03 } , { 0x1bb , 0x2a0f } ,
{ 0x1bc , 0x1208 } , { 0x1bd , 0x1a16 } , { 0x1be , 0x0022 } ,
{ 0x1bf , 0x150a } , { 0x1c0 , 0x1c1a } , { 0x1c1 , 0x002d } ,
{ 0x1c2 , 0x1109 } , { 0x1c3 , 0x1414 } , { 0x1c4 , 0x002a } ,
{ 0x106 , 0x740e } ,
{ 0x153 , 0x0b03 } , { 0x154 , 0x4722 } , { 0x155 , 0xac82 } ,
{ 0x156 , 0xdac7 } , { 0x157 , 0xf5e9 } , { 0x158 , 0xff00 } ,
{ 0x1dc , 0x0b03 } , { 0x1dd , 0x4722 } , { 0x1de , 0xac82 } ,
{ 0x1df , 0xdac7 } , { 0x1e0 , 0xf5e9 } , { 0x1e1 , 0xff00 } ,
{ 0x13a , 0x4300 } , { 0x19b , 0x4300 } ,
{ 0x108 , 0x0180 } ,
{ 0x22f , 0xd100 } , { 0x29c , 0xd100 } ,
{ 0x2d2 , 0x0000 } , { 0x2cc , 0x0004 } , { 0x2cb , 0x0001 } ,
{ 0x22e , 0x0c3c } , { 0x267 , 0x1010 } ,
{ 0x065 , 0xa000 } ,
{ 0x066 , 0x2003 } , { 0x067 , 0x0501 } ,
{ 0x065 , 0x2000 } ,
{ 0x005 , 0x01b8 } , { 0x007 , 0x00d8 } ,
{ 0x239 , 0x06c0 } , { 0x23b , 0x040e } ,
{ 0x23a , 0x06c0 } , { 0x23c , 0x0564 } ,
{ 0x257 , 0x0208 } , { 0x258 , 0x0271 } ,
{ 0x259 , 0x0209 } , { 0x25a , 0x0271 } ,
{ 0x25c , 0x120d } , { 0x25d , 0x1712 } ,
{ 0x264 , 0x5e1c } ,
{ 0x25b , 0x0003 } , { 0x236 , 0x7810 } , { 0x237 , 0x8304 } ,
{ 0x008 , 0x0021 } ,
} ;
int V_22 ;
T_2 V_34 , V_35 ;
for ( V_22 = 0 ; V_22 < F_10 ( V_33 ) ; V_22 ++ )
F_18 ( V_1 , V_33 [ V_22 ] . V_31 , V_33 [ V_22 ] . V_12 ) ;
V_34 = V_1 -> V_36 . V_34 ;
V_35 = V_1 -> V_36 . V_35 ;
if ( V_34 <= 640 && V_35 <= 512 ) {
F_18 ( V_1 , 0x1a7 , V_34 ) ;
F_18 ( V_1 , 0x1aa , V_35 ) ;
F_18 ( V_1 , 0x0c8 , 0x0000 ) ;
F_18 ( V_1 , 0x2c8 , 0x0000 ) ;
} else {
F_18 ( V_1 , 0x1a1 , V_34 ) ;
F_18 ( V_1 , 0x1a4 , V_35 ) ;
F_18 ( V_1 , 0x0c8 , 0x0008 ) ;
F_18 ( V_1 , 0x2c8 , 0x040b ) ;
}
}
static void F_21 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_37 , 0x12 ) ;
F_6 ( V_1 , V_38 + 0 , 0x41 ) ;
F_6 ( V_1 , V_38 + 1 , 0x00 ) ;
F_6 ( V_1 , V_38 + 2 , 0x00 ) ;
F_6 ( V_1 , V_38 + 3 , 0x00 ) ;
F_6 ( V_1 , V_39 + 0 , 0x10 ) ;
F_6 ( V_1 , V_39 + 1 , 0x00 ) ;
F_6 ( V_1 , V_39 + 3 , 0x07 ) ;
F_6 ( V_1 , V_40 , 0x06 ) ;
F_6 ( V_1 , V_37 , 0x80 ) ;
F_6 ( V_1 , V_39 + 2 , 0x04 ) ;
F_6 ( V_1 , V_23 + 2 , 0x1f ) ;
F_22 ( 1000 ) ;
}
static void F_23 ( struct V_1 * V_1 )
{
F_6 ( V_1 , V_41 + 2 , 0x00 ) ;
F_6 ( V_1 , V_41 + 3 , 0x00 ) ;
F_8 ( V_1 , V_42 , 0x00 , 0x80 ) ;
F_19 ( V_1 , 0x00d , 0x0004 , 0x000c ) ;
F_8 ( V_1 , V_39 + 2 , 0x00 , 0x01 ) ;
F_6 ( V_1 , V_37 , 0x00 ) ;
F_6 ( V_1 , V_39 + 1 , 0x20 ) ;
F_6 ( V_1 , V_39 , 0x00 ) ;
F_6 ( V_1 , V_43 , 0x49 ) ;
}
static int F_24 ( struct V_1 * V_1 )
{
T_2 V_44 ;
char * V_45 ;
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
F_6 ( V_1 , V_43 + 2 , 0x78 ) ;
F_6 ( V_1 , V_43 , ( 1 << 5 ) ) ;
F_6 ( V_1 , V_43 + 3 , 0x80 ) ;
F_6 ( V_1 , V_46 + 1 , 0x00 ) ;
F_6 ( V_1 , V_46 + 3 , 0x03 ) ;
F_6 ( V_1 , V_47 + 1 , 0x00 ) ;
F_6 ( V_1 , V_47 + 3 , 0x02 ) ;
F_6 ( V_1 , V_23 , 0x80 ) ;
F_6 ( V_1 , V_23 , 0x00 ) ;
F_6 ( V_1 , V_23 + 3 , 0xba ) ;
F_6 ( V_1 , V_48 + 3 , 0x00 ) ;
F_21 ( V_1 ) ;
V_29 -> V_30 = 0xff ;
V_44 = F_17 ( V_1 , 0x000 ) ;
switch ( V_44 ) {
case 0x148c :
V_45 = L_8 ;
break;
default:
V_45 = L_9 ;
}
F_25 ( L_10 , V_45 , V_44 ) ;
F_23 ( V_1 ) ;
return V_1 -> V_6 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
T_2 V_34 , V_35 ;
F_6 ( V_1 , V_43 , ( 1 << 5 ) ) ;
F_21 ( V_1 ) ;
F_6 ( V_1 , V_49 + 0 , 0x00 ) ;
F_6 ( V_1 , V_49 + 1 , 0x00 ) ;
F_6 ( V_1 , V_49 + 2 , 0x00 ) ;
F_6 ( V_1 , V_49 + 3 , 0x00 ) ;
V_34 = V_1 -> V_36 . V_34 ;
V_35 = V_1 -> V_36 . V_35 ;
F_6 ( V_1 , V_41 + 0 , V_34 & 0xff ) ;
F_6 ( V_1 , V_41 + 1 , V_34 >> 8 ) ;
F_6 ( V_1 , V_41 + 2 , V_35 & 0xff ) ;
F_6 ( V_1 , V_41 + 3 , V_35 >> 8 ) ;
F_6 ( V_1 , V_42 , 0x20 ) ;
F_20 ( V_1 ) ;
F_8 ( V_1 , V_42 , 0x80 , 0x80 ) ;
if ( V_1 -> V_6 >= 0 )
F_4 ( V_50 , L_11 ,
V_1 -> V_51 ) ;
V_29 -> V_52 = 0 ;
return V_1 -> V_6 ;
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
F_28 ( V_4 , V_1 -> V_53 , 0 ) ;
F_23 ( V_1 ) ;
F_4 ( V_50 , L_12 ) ;
}
static void F_29 ( struct V_1 * V_1 ,
T_1 * V_26 ,
int V_54 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
int V_55 = sizeof( struct V_56 ) ;
bool V_57 ;
enum V_58 V_59 = V_60 ;
struct V_56 * V_61 = ( void * ) V_26 ;
T_1 V_62 ;
if ( V_54 < 4 ) {
F_4 ( V_63 , L_13 ) ;
return;
}
V_57 = ! ( F_30 ( V_61 -> V_64 ) & ( 1 << 8 ) ) ;
if ( V_29 -> V_65 != V_57 )
V_29 -> V_66 ++ ;
else
V_29 -> V_66 = 0 ;
if ( ! ( V_61 -> V_67 & V_68 ) ) {
V_62 = V_61 -> V_62 & V_69 ;
if ( V_62 != V_29 -> V_52 ) {
F_4 ( V_63 , L_14 ) ;
V_29 -> V_52 = V_62 ;
V_1 -> V_70 = V_71 ;
return;
}
}
V_29 -> V_52 ++ ;
if ( V_29 -> V_52 > V_69 )
V_29 -> V_52 = 0 ;
if ( V_54 == sizeof( struct V_56 ) )
return;
if ( V_61 -> V_67 & V_68 ) {
V_55 = 8 ;
F_31 ( V_1 , V_72 , V_26 , 0 ) ;
V_59 = V_73 ;
}
F_31 ( V_1 , V_59 , V_26 + V_55 , V_54 - V_55 ) ;
}
static void F_32 ( struct V_1 * V_1 , T_3 V_12 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
if ( V_29 -> V_65 )
V_12 = ! V_12 ;
F_19 ( V_1 , 0x020 , V_12 ? 0x0002 : 0x0000 , 0x0002 ) ;
}
static void F_33 ( struct V_1 * V_1 , T_3 V_12 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
if ( V_29 -> V_65 )
V_12 = ! V_12 ;
F_19 ( V_1 , 0x020 , V_12 ? 0x0001 : 0x0000 , 0x0001 ) ;
}
static void F_34 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
if ( V_29 -> V_66 > 100 ) {
V_29 -> V_65 = ! V_29 -> V_65 ;
F_32 ( V_1 , F_35 ( V_29 -> V_74 ) ) ;
F_33 ( V_1 , F_35 ( V_29 -> V_75 ) ) ;
}
}
static int F_36 ( struct V_76 * V_77 )
{
struct V_1 * V_1 =
F_37 ( V_77 -> V_78 , struct V_1 , V_79 ) ;
V_1 -> V_6 = 0 ;
if ( ! V_1 -> V_80 )
return 0 ;
switch ( V_77 -> V_17 ) {
case V_81 :
F_32 ( V_1 , V_77 -> V_12 ) ;
break;
case V_82 :
F_33 ( V_1 , V_77 -> V_12 ) ;
break;
}
return V_1 -> V_6 ;
}
static int F_38 ( struct V_1 * V_1 )
{
struct V_29 * V_29 = (struct V_29 * ) V_1 ;
struct V_83 * V_84 = & V_1 -> V_79 ;
V_1 -> V_85 . V_79 = V_84 ;
F_39 ( V_84 , 2 ) ;
V_29 -> V_74 = F_40 ( V_84 , & V_86 ,
V_81 , 0 , 1 , 1 , 0 ) ;
V_29 -> V_75 = F_40 ( V_84 , & V_86 ,
V_82 , 0 , 1 , 1 , 0 ) ;
if ( V_84 -> error ) {
F_5 ( L_15 ) ;
return V_84 -> error ;
}
return 0 ;
}
static void F_41 ( struct V_1 * V_1 , struct V_87 * V_88 )
{
V_88 -> V_88 . V_89 . V_34 = F_42 ( V_88 -> V_88 . V_89 . V_34 , 32U , 1280U ) ;
V_88 -> V_88 . V_89 . V_35 = F_42 ( V_88 -> V_88 . V_89 . V_35 , 32U , 1024U ) ;
V_88 -> V_88 . V_89 . V_34 += ( V_88 -> V_88 . V_89 . V_34 & 1 ) ;
V_88 -> V_88 . V_89 . V_35 += ( V_88 -> V_88 . V_89 . V_35 & 1 ) ;
V_88 -> V_88 . V_89 . V_90 = V_88 -> V_88 . V_89 . V_34 ;
V_88 -> V_88 . V_89 . V_91 = V_88 -> V_88 . V_89 . V_34 * V_88 -> V_88 . V_89 . V_35 ;
}
static int F_43 ( struct V_1 * V_1 ,
struct V_92 * V_93 )
{
if ( V_93 -> V_2 != 0 || V_93 -> V_94 != V_95 )
return - V_96 ;
V_93 -> type = V_97 ;
V_93 -> V_98 . V_99 = 32 ;
V_93 -> V_98 . V_100 = 32 ;
V_93 -> V_98 . V_101 = 1280 ;
V_93 -> V_98 . V_102 = 1024 ;
V_93 -> V_98 . V_103 = 2 ;
V_93 -> V_98 . V_104 = 2 ;
return 0 ;
}
static int F_44 ( struct V_105 * V_106 ,
const struct V_16 * V_17 )
{
return F_45 ( V_106 , V_17 , & V_107 , sizeof( struct V_29 ) ,
V_108 ) ;
}
