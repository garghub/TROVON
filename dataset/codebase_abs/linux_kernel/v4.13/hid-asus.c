static void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
int V_5 , V_6 ;
int V_7 = ( V_4 [ 0 ] & V_8 ) << 4 | V_4 [ 1 ] ;
int V_9 = V_10 - ( ( V_4 [ 0 ] & V_11 ) << 8 | V_4 [ 2 ] ) ;
if ( V_3 == V_12 ) {
V_5 = V_13 ;
V_6 = V_14 ;
} else {
V_5 = ( V_4 [ 3 ] >> 4 ) & V_15 ;
V_6 = V_4 [ 4 ] & V_16 ;
}
F_2 ( V_2 , V_17 , V_7 ) ;
F_2 ( V_2 , V_18 , V_9 ) ;
F_2 ( V_2 , V_19 , V_5 ) ;
F_2 ( V_2 , V_20 , V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_22 ;
struct V_23 * V_24 ;
int V_25 , V_26 , V_27 ;
V_24 = NULL ;
V_25 = V_22 -> V_28 ;
V_26 = 0 ;
for ( V_27 = 0 ; V_27 < V_22 -> V_29 ; ++ V_27 ) {
struct V_23 * V_30 = & V_22 -> V_31 [ V_27 ] ;
int V_32 = F_4 ( V_30 , V_33 ) ;
if ( V_32 < 0 )
continue;
if ( ( V_32 - V_25 ) & V_34 ) {
V_24 = V_30 ;
V_25 = V_32 ;
}
V_26 ++ ;
}
if ( V_24 ) {
F_2 ( V_2 , V_35 ,
F_4 ( V_24 , V_19 ) ) ;
}
}
static void F_5 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_27 ;
T_1 * V_36 = V_4 + 2 ;
for ( V_27 = 0 ; V_27 < V_37 ; V_27 ++ ) {
bool V_38 = ! ! ( V_4 [ 1 ] & F_6 ( V_27 + 3 ) ) ;
int V_3 = V_36 [ 3 ] & V_39 ?
V_12 : V_40 ;
V_23 ( V_2 , V_27 ) ;
F_7 ( V_2 , V_3 , V_38 ) ;
if ( V_38 ) {
F_1 ( V_2 , V_3 , V_36 ) ;
V_36 += V_41 ;
}
}
F_8 ( V_2 , V_42 , V_4 [ 1 ] & V_43 ) ;
F_3 ( V_2 ) ;
F_9 ( V_2 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_44 * V_45 ,
struct V_46 * V_47 , T_1 * V_4 , int V_48 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_52 &&
V_4 [ 0 ] == V_53 &&
V_48 == V_54 ) {
F_5 ( V_50 -> V_2 , V_4 ) ;
return 1 ;
}
return 0 ;
}
static int F_13 ( struct V_44 * V_45 , T_1 * V_55 , T_2 V_56 )
{
unsigned char * V_57 ;
int V_58 ;
V_57 = F_14 ( V_55 , V_56 , V_59 ) ;
if ( ! V_57 )
return - V_60 ;
V_58 = F_15 ( V_45 , V_61 , V_57 ,
V_56 , V_62 ,
V_63 ) ;
F_16 ( V_57 ) ;
return V_58 ;
}
static int F_17 ( struct V_44 * V_45 )
{
T_1 V_55 [] = { V_61 , 0x41 , 0x53 , 0x55 , 0x53 , 0x20 , 0x54 ,
0x65 , 0x63 , 0x68 , 0x2e , 0x49 , 0x6e , 0x63 , 0x2e , 0x00 } ;
int V_58 ;
V_58 = F_13 ( V_45 , V_55 , sizeof( V_55 ) ) ;
if ( V_58 < 0 )
F_18 ( V_45 , L_1 , V_58 ) ;
return V_58 ;
}
static int F_19 ( struct V_44 * V_45 ,
unsigned char * V_64 )
{
T_1 V_55 [] = { V_61 , 0x05 , 0x20 , 0x31 , 0x00 , 0x08 } ;
T_1 * V_65 ;
int V_58 ;
V_58 = F_13 ( V_45 , V_55 , sizeof( V_55 ) ) ;
if ( V_58 < 0 ) {
F_18 ( V_45 , L_2 , V_58 ) ;
return V_58 ;
}
V_65 = F_20 ( V_66 , V_59 ) ;
if ( ! V_65 )
return - V_60 ;
V_58 = F_15 ( V_45 , V_61 , V_65 ,
V_66 , V_62 ,
V_67 ) ;
if ( V_58 < 0 ) {
F_18 ( V_45 , L_3 , V_58 ) ;
F_16 ( V_65 ) ;
return V_58 ;
}
* V_64 = V_65 [ 6 ] ;
F_16 ( V_65 ) ;
return V_58 ;
}
static void F_21 ( struct V_68 * V_69 ,
enum V_70 V_71 )
{
struct V_72 * V_73 = F_22 ( V_69 , struct V_72 ,
V_74 ) ;
if ( V_73 -> V_71 == V_71 )
return;
V_73 -> V_71 = V_71 ;
F_23 ( & V_73 -> V_75 ) ;
}
static enum V_70 F_24 ( struct V_68 * V_69 )
{
struct V_72 * V_73 = F_22 ( V_69 , struct V_72 ,
V_74 ) ;
return V_73 -> V_71 ;
}
static void F_25 ( struct V_76 * V_75 )
{
struct V_72 * V_73 = F_22 ( V_75 , struct V_72 , V_75 ) ;
T_1 V_55 [] = { V_61 , 0xba , 0xc5 , 0xc4 , 0x00 } ;
int V_58 ;
if ( V_73 -> V_77 )
return;
V_55 [ 4 ] = V_73 -> V_71 ;
V_58 = F_13 ( V_73 -> V_45 , V_55 , sizeof( V_55 ) ) ;
if ( V_58 < 0 )
F_18 ( V_73 -> V_45 , L_4 , V_58 ) ;
}
static int F_26 ( struct V_44 * V_45 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
unsigned char V_64 ;
int V_58 ;
V_58 = F_17 ( V_45 ) ;
if ( V_58 < 0 )
return V_58 ;
V_58 = F_19 ( V_45 , & V_64 ) ;
if ( V_58 < 0 )
return V_58 ;
if ( ! ( V_64 & V_78 ) )
return - V_79 ;
V_50 -> V_80 = F_27 ( & V_45 -> V_81 ,
sizeof( struct V_72 ) ,
V_59 ) ;
if ( ! V_50 -> V_80 )
return - V_60 ;
V_50 -> V_80 -> V_77 = false ;
V_50 -> V_80 -> V_71 = 0 ;
V_50 -> V_80 -> V_45 = V_45 ;
V_50 -> V_80 -> V_74 . V_82 = L_5 ;
V_50 -> V_80 -> V_74 . V_83 = 3 ;
V_50 -> V_80 -> V_74 . V_84 = F_21 ;
V_50 -> V_80 -> V_74 . V_85 = F_24 ;
F_28 ( & V_50 -> V_80 -> V_75 , F_25 ) ;
V_58 = F_29 ( & V_45 -> V_81 , & V_50 -> V_80 -> V_74 ) ;
if ( V_58 < 0 ) {
F_30 ( & V_45 -> V_81 , V_50 -> V_80 ) ;
}
return V_58 ;
}
static int F_31 ( struct V_44 * V_45 , struct V_86 * V_87 )
{
struct V_1 * V_2 = V_87 -> V_2 ;
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_52 ) {
int V_58 ;
F_32 ( V_2 , V_17 , 0 , V_88 , 0 , 0 ) ;
F_32 ( V_2 , V_18 , 0 , V_10 , 0 , 0 ) ;
F_32 ( V_2 , V_35 , 0 , V_13 , 0 , 0 ) ;
F_32 ( V_2 , V_19 , 0 , V_13 , 0 , 0 ) ;
F_32 ( V_2 , V_20 , 0 , V_14 , 0 , 0 ) ;
F_33 ( V_42 , V_2 -> V_89 ) ;
F_33 ( V_90 , V_2 -> V_91 ) ;
V_58 = F_34 ( V_2 , V_37 , V_92 ) ;
if ( V_58 ) {
F_18 ( V_45 , L_6 , V_58 ) ;
return V_58 ;
}
}
V_50 -> V_2 = V_2 ;
if ( V_50 -> V_93 && F_26 ( V_45 ) )
F_35 ( V_45 , L_7 ) ;
return 0 ;
}
static int F_36 ( struct V_44 * V_45 ,
struct V_86 * V_87 , struct V_94 * V_95 ,
struct V_96 * V_97 , unsigned long * * V_98 ,
int * V_99 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_100 ) {
return - 1 ;
}
if ( ( V_97 -> V_101 & V_102 ) == 0xff310000 ) {
F_37 ( V_103 , V_87 -> V_2 -> V_104 ) ;
switch ( V_97 -> V_101 & V_105 ) {
case 0x10 : F_38 ( V_106 ) ; break;
case 0x20 : F_38 ( V_107 ) ; break;
case 0x35 : F_38 ( V_108 ) ; break;
case 0x6c : F_38 ( V_109 ) ; break;
case 0x82 : F_38 ( V_110 ) ; break;
case 0x88 : F_38 ( V_111 ) ; break;
case 0xb5 : F_38 ( V_112 ) ; break;
case 0xc4 : F_38 ( V_113 ) ; break;
case 0xc5 : F_38 ( V_114 ) ; break;
case 0x6b : F_38 ( V_115 ) ; break;
case 0x38 : F_38 ( V_116 ) ; break;
case 0xba : F_38 ( V_117 ) ; break;
case 0x5c : F_38 ( V_118 ) ; break;
default:
return - 1 ;
}
if ( V_50 -> V_51 & V_119 )
V_50 -> V_93 = true ;
return 1 ;
}
if ( ( V_97 -> V_101 & V_102 ) == V_120 ) {
F_37 ( V_103 , V_87 -> V_2 -> V_104 ) ;
switch ( V_97 -> V_101 & V_105 ) {
case 0xff01 : F_38 ( V_121 ) ; break;
case 0xff02 : F_38 ( V_122 ) ; break;
case 0xff03 : F_38 ( V_123 ) ; break;
case 0xff04 : F_38 ( V_124 ) ; break;
case 0xff05 : F_38 ( V_125 ) ; break;
case 0xff06 : F_38 ( V_126 ) ; break;
case 0xff07 : F_38 ( V_127 ) ; break;
case 0xff08 : F_38 ( V_128 ) ; break;
case 0xff09 : F_38 ( V_129 ) ; break;
case 0xff0a : F_38 ( V_130 ) ; break;
case 0xff0b : F_38 ( V_131 ) ; break;
case 0x00f1 : F_38 ( V_132 ) ; break;
case 0x00f2 : F_38 ( V_106 ) ; break;
case 0x00f3 : F_38 ( V_107 ) ; break;
case 0x00f4 : F_38 ( V_108 ) ; break;
case 0x00f7 : F_38 ( V_110 ) ; break;
case 0x00f8 : F_38 ( V_116 ) ; break;
default:
return 0 ;
}
return 1 ;
}
if ( V_50 -> V_51 & V_133 &&
( V_97 -> V_101 & V_102 ) == V_134 ) {
switch ( V_97 -> V_101 & V_105 ) {
case 0xe2 :
case 0xe9 :
case 0xea :
return 0 ;
default:
return - 1 ;
}
}
return 0 ;
}
static int F_39 ( struct V_44 * V_45 )
{
int V_58 ;
const unsigned char V_55 [] = { V_135 , 0x00 , 0x03 , 0x01 , 0x00 } ;
unsigned char * V_57 = F_14 ( V_55 , sizeof( V_55 ) , V_59 ) ;
if ( ! V_57 ) {
V_58 = - V_60 ;
F_18 ( V_45 , L_8 , V_58 ) ;
return V_58 ;
}
V_58 = F_15 ( V_45 , V_57 [ 0 ] , V_57 , sizeof( V_55 ) ,
V_62 , V_63 ) ;
F_16 ( V_57 ) ;
if ( V_58 != sizeof( V_55 ) ) {
F_18 ( V_45 , L_9 , V_58 ) ;
return V_58 ;
}
return 0 ;
}
static int T_3 F_40 ( struct V_44 * V_45 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_52 )
return F_39 ( V_45 ) ;
return 0 ;
}
static int F_41 ( struct V_44 * V_45 , const struct V_136 * V_32 )
{
int V_58 ;
struct V_49 * V_50 ;
V_50 = F_27 ( & V_45 -> V_81 , sizeof( * V_50 ) , V_59 ) ;
if ( V_50 == NULL ) {
F_18 ( V_45 , L_10 ) ;
return - V_60 ;
}
F_42 ( V_45 , V_50 ) ;
V_50 -> V_51 = V_32 -> V_137 ;
if ( V_50 -> V_51 & V_138 )
V_45 -> V_51 |= V_139 ;
V_58 = F_43 ( V_45 ) ;
if ( V_58 ) {
F_18 ( V_45 , L_11 , V_58 ) ;
return V_58 ;
}
V_58 = F_44 ( V_45 , V_140 ) ;
if ( V_58 ) {
F_18 ( V_45 , L_12 , V_58 ) ;
return V_58 ;
}
if ( ! V_50 -> V_2 ) {
F_18 ( V_45 , L_13 ) ;
V_58 = - V_60 ;
goto V_141;
}
if ( V_50 -> V_51 & V_52 ) {
V_50 -> V_2 -> V_82 = L_14 ;
} else {
V_50 -> V_2 -> V_82 = L_15 ;
}
if ( V_50 -> V_51 & V_52 ) {
V_58 = F_39 ( V_45 ) ;
if ( V_58 )
goto V_141;
}
return 0 ;
V_141:
F_45 ( V_45 ) ;
return V_58 ;
}
static void F_46 ( struct V_44 * V_45 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_80 ) {
V_50 -> V_80 -> V_77 = true ;
F_47 ( & V_50 -> V_80 -> V_75 ) ;
}
F_45 ( V_45 ) ;
}
static T_4 * F_48 ( struct V_44 * V_45 , T_4 * V_142 ,
unsigned int * V_143 )
{
struct V_49 * V_50 = F_12 ( V_45 ) ;
if ( V_50 -> V_51 & V_144 &&
* V_143 >= 56 && V_142 [ 54 ] == 0x25 && V_142 [ 55 ] == 0x65 ) {
F_49 ( V_45 , L_16 ) ;
V_142 [ 55 ] = 0xdd ;
}
if ( V_50 -> V_51 & V_145 &&
* V_143 == 76 && V_142 [ 73 ] == 0x81 && V_142 [ 74 ] == 0x01 ) {
F_49 ( V_45 , L_17 ) ;
V_142 [ 74 ] &= ~ V_146 ;
}
return V_142 ;
}
