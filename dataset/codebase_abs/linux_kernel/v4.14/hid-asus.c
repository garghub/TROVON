static void F_1 ( struct V_1 * V_2 ,
int V_3 , T_1 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
int V_7 , V_8 , V_9 , V_10 ;
V_9 = ( V_4 [ 0 ] & V_11 ) << 4 | V_4 [ 1 ] ;
V_10 = V_2 -> V_12 -> V_13 - ( ( V_4 [ 0 ] & V_14 ) << 8 | V_4 [ 2 ] ) ;
F_2 ( V_6 , V_15 , V_9 ) ;
F_2 ( V_6 , V_16 , V_10 ) ;
if ( V_2 -> V_12 -> V_17 < 5 )
return;
if ( V_3 == V_18 ) {
V_7 = V_19 ;
V_8 = V_20 ;
} else {
V_7 = ( V_4 [ 3 ] >> 4 ) & V_21 ;
V_8 = V_4 [ 4 ] & V_22 ;
}
F_2 ( V_6 , V_23 , V_7 ) ;
F_2 ( V_6 , V_24 , V_8 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_6 -> V_26 ;
struct V_27 * V_28 ;
int V_29 , V_30 , V_31 ;
if ( V_2 -> V_12 -> V_17 < 5 )
return;
V_28 = NULL ;
V_29 = V_26 -> V_32 ;
V_30 = 0 ;
for ( V_31 = 0 ; V_31 < V_26 -> V_33 ; ++ V_31 ) {
struct V_27 * V_34 = & V_26 -> V_35 [ V_31 ] ;
int V_36 = F_4 ( V_34 , V_37 ) ;
if ( V_36 < 0 )
continue;
if ( ( V_36 - V_29 ) & V_38 ) {
V_28 = V_34 ;
V_29 = V_36 ;
}
V_30 ++ ;
}
if ( V_28 ) {
F_2 ( V_2 -> V_6 , V_39 ,
F_4 ( V_28 , V_23 ) ) ;
}
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_4 , int V_40 )
{
int V_31 , V_3 = V_41 ;
T_1 * V_42 = V_4 + 2 ;
if ( V_40 != 3 + V_2 -> V_12 -> V_17 * V_2 -> V_12 -> V_43 )
return 0 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_12 -> V_43 ; V_31 ++ ) {
bool V_44 = ! ! ( V_4 [ 1 ] & F_6 ( V_31 + 3 ) ) ;
if ( V_2 -> V_12 -> V_17 >= 5 )
V_3 = V_42 [ 3 ] & V_45 ?
V_18 : V_41 ;
V_27 ( V_2 -> V_6 , V_31 ) ;
F_7 ( V_2 -> V_6 , V_3 , V_44 ) ;
if ( V_44 ) {
F_1 ( V_2 , V_3 , V_42 ) ;
V_42 += V_2 -> V_12 -> V_17 ;
}
}
F_8 ( V_2 -> V_6 , V_46 , V_4 [ 1 ] & V_47 ) ;
F_3 ( V_2 ) ;
F_9 ( V_2 -> V_6 ) ;
F_10 ( V_2 -> V_6 ) ;
return 1 ;
}
static int F_11 ( struct V_48 * V_49 ,
struct V_50 * V_51 , T_1 * V_4 , int V_40 )
{
struct V_1 * V_52 = F_12 ( V_49 ) ;
if ( V_52 -> V_12 && V_4 [ 0 ] == V_53 )
return F_5 ( V_52 , V_4 , V_40 ) ;
return 0 ;
}
static int F_13 ( struct V_48 * V_49 , T_1 * V_54 , T_2 V_55 )
{
unsigned char * V_56 ;
int V_57 ;
V_56 = F_14 ( V_54 , V_55 , V_58 ) ;
if ( ! V_56 )
return - V_59 ;
V_57 = F_15 ( V_49 , V_60 , V_56 ,
V_55 , V_61 ,
V_62 ) ;
F_16 ( V_56 ) ;
return V_57 ;
}
static int F_17 ( struct V_48 * V_49 )
{
T_1 V_54 [] = { V_60 , 0x41 , 0x53 , 0x55 , 0x53 , 0x20 , 0x54 ,
0x65 , 0x63 , 0x68 , 0x2e , 0x49 , 0x6e , 0x63 , 0x2e , 0x00 } ;
int V_57 ;
V_57 = F_13 ( V_49 , V_54 , sizeof( V_54 ) ) ;
if ( V_57 < 0 )
F_18 ( V_49 , L_1 , V_57 ) ;
return V_57 ;
}
static int F_19 ( struct V_48 * V_49 ,
unsigned char * V_63 )
{
T_1 V_54 [] = { V_60 , 0x05 , 0x20 , 0x31 , 0x00 , 0x08 } ;
T_1 * V_64 ;
int V_57 ;
V_57 = F_13 ( V_49 , V_54 , sizeof( V_54 ) ) ;
if ( V_57 < 0 ) {
F_18 ( V_49 , L_2 , V_57 ) ;
return V_57 ;
}
V_64 = F_20 ( V_65 , V_58 ) ;
if ( ! V_64 )
return - V_59 ;
V_57 = F_15 ( V_49 , V_60 , V_64 ,
V_65 , V_61 ,
V_66 ) ;
if ( V_57 < 0 ) {
F_18 ( V_49 , L_3 , V_57 ) ;
F_16 ( V_64 ) ;
return V_57 ;
}
* V_63 = V_64 [ 6 ] ;
F_16 ( V_64 ) ;
return V_57 ;
}
static void F_21 ( struct V_67 * V_68 ,
enum V_69 V_70 )
{
struct V_71 * V_72 = F_22 ( V_68 , struct V_71 ,
V_73 ) ;
if ( V_72 -> V_70 == V_70 )
return;
V_72 -> V_70 = V_70 ;
F_23 ( & V_72 -> V_74 ) ;
}
static enum V_69 F_24 ( struct V_67 * V_68 )
{
struct V_71 * V_72 = F_22 ( V_68 , struct V_71 ,
V_73 ) ;
return V_72 -> V_70 ;
}
static void F_25 ( struct V_75 * V_74 )
{
struct V_71 * V_72 = F_22 ( V_74 , struct V_71 , V_74 ) ;
T_1 V_54 [] = { V_60 , 0xba , 0xc5 , 0xc4 , 0x00 } ;
int V_57 ;
if ( V_72 -> V_76 )
return;
V_54 [ 4 ] = V_72 -> V_70 ;
V_57 = F_13 ( V_72 -> V_49 , V_54 , sizeof( V_54 ) ) ;
if ( V_57 < 0 )
F_18 ( V_72 -> V_49 , L_4 , V_57 ) ;
}
static int F_26 ( struct V_48 * V_49 )
{
struct V_1 * V_52 = F_12 ( V_49 ) ;
unsigned char V_63 ;
int V_57 ;
V_57 = F_17 ( V_49 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_19 ( V_49 , & V_63 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( ! ( V_63 & V_77 ) )
return - V_78 ;
V_52 -> V_79 = F_27 ( & V_49 -> V_80 ,
sizeof( struct V_71 ) ,
V_58 ) ;
if ( ! V_52 -> V_79 )
return - V_59 ;
V_52 -> V_79 -> V_76 = false ;
V_52 -> V_79 -> V_70 = 0 ;
V_52 -> V_79 -> V_49 = V_49 ;
V_52 -> V_79 -> V_73 . V_81 = L_5 ;
V_52 -> V_79 -> V_73 . V_82 = 3 ;
V_52 -> V_79 -> V_73 . V_83 = F_21 ;
V_52 -> V_79 -> V_73 . V_84 = F_24 ;
F_28 ( & V_52 -> V_79 -> V_74 , F_25 ) ;
V_57 = F_29 ( & V_49 -> V_80 , & V_52 -> V_79 -> V_73 ) ;
if ( V_57 < 0 ) {
F_30 ( & V_49 -> V_80 , V_52 -> V_79 ) ;
}
return V_57 ;
}
static int F_31 ( struct V_48 * V_49 , struct V_85 * V_86 )
{
struct V_5 * V_6 = V_86 -> V_6 ;
struct V_1 * V_52 = F_12 ( V_49 ) ;
if ( V_52 -> V_87 & V_88 &&
V_86 -> V_51 -> V_36 != V_89 )
return 0 ;
if ( V_52 -> V_12 ) {
int V_57 ;
F_32 ( V_6 , V_15 , 0 ,
V_52 -> V_12 -> V_90 , 0 , 0 ) ;
F_32 ( V_6 , V_16 , 0 ,
V_52 -> V_12 -> V_13 , 0 , 0 ) ;
F_33 ( V_6 , V_15 , V_52 -> V_12 -> V_91 ) ;
F_33 ( V_6 , V_16 , V_52 -> V_12 -> V_92 ) ;
if ( V_52 -> V_12 -> V_17 >= 5 ) {
F_32 ( V_6 , V_39 , 0 ,
V_19 , 0 , 0 ) ;
F_32 ( V_6 , V_23 , 0 ,
V_19 , 0 , 0 ) ;
F_32 ( V_6 , V_24 , 0 ,
V_20 , 0 , 0 ) ;
}
F_34 ( V_46 , V_6 -> V_93 ) ;
F_34 ( V_94 , V_6 -> V_95 ) ;
V_57 = F_35 ( V_6 , V_52 -> V_12 -> V_43 ,
V_96 ) ;
if ( V_57 ) {
F_18 ( V_49 , L_6 , V_57 ) ;
return V_57 ;
}
}
V_52 -> V_6 = V_6 ;
if ( V_52 -> V_97 && F_26 ( V_49 ) )
F_36 ( V_49 , L_7 ) ;
return 0 ;
}
static int F_37 ( struct V_48 * V_49 ,
struct V_85 * V_86 , struct V_98 * V_99 ,
struct V_100 * V_101 , unsigned long * * V_102 ,
int * V_103 )
{
struct V_1 * V_52 = F_12 ( V_49 ) ;
if ( V_52 -> V_87 & V_104 ) {
return - 1 ;
}
if ( V_52 -> V_87 & V_88 ) {
if ( V_99 -> V_105 == ( V_106 | 0x0080 ) ||
V_101 -> V_107 == ( V_108 | 0x0024 ) ||
V_101 -> V_107 == ( V_108 | 0x0025 ) ||
V_101 -> V_107 == ( V_108 | 0x0026 ) )
return - 1 ;
if ( V_99 -> V_105 == V_109 &&
V_101 -> V_107 != ( V_110 | 1 ) )
return - 1 ;
}
if ( ( V_101 -> V_107 & V_111 ) == 0xff310000 ) {
F_38 ( V_112 , V_86 -> V_6 -> V_113 ) ;
switch ( V_101 -> V_107 & V_114 ) {
case 0x10 : F_39 ( V_115 ) ; break;
case 0x20 : F_39 ( V_116 ) ; break;
case 0x35 : F_39 ( V_117 ) ; break;
case 0x6c : F_39 ( V_118 ) ; break;
case 0x82 : F_39 ( V_119 ) ; break;
case 0x88 : F_39 ( V_120 ) ; break;
case 0xb5 : F_39 ( V_121 ) ; break;
case 0xc4 : F_39 ( V_122 ) ; break;
case 0xc5 : F_39 ( V_123 ) ; break;
case 0x6b : F_39 ( V_124 ) ; break;
case 0x38 : F_39 ( V_125 ) ; break;
case 0xba : F_39 ( V_126 ) ; break;
case 0x5c : F_39 ( V_127 ) ; break;
default:
return - 1 ;
}
if ( V_52 -> V_87 & V_128 )
V_52 -> V_97 = true ;
return 1 ;
}
if ( ( V_101 -> V_107 & V_111 ) == V_129 ) {
F_38 ( V_112 , V_86 -> V_6 -> V_113 ) ;
switch ( V_101 -> V_107 & V_114 ) {
case 0xff01 : F_39 ( V_130 ) ; break;
case 0xff02 : F_39 ( V_131 ) ; break;
case 0xff03 : F_39 ( V_132 ) ; break;
case 0xff04 : F_39 ( V_133 ) ; break;
case 0xff05 : F_39 ( V_134 ) ; break;
case 0xff06 : F_39 ( V_135 ) ; break;
case 0xff07 : F_39 ( V_136 ) ; break;
case 0xff08 : F_39 ( V_137 ) ; break;
case 0xff09 : F_39 ( V_138 ) ; break;
case 0xff0a : F_39 ( V_139 ) ; break;
case 0xff0b : F_39 ( V_140 ) ; break;
case 0x00f1 : F_39 ( V_141 ) ; break;
case 0x00f2 : F_39 ( V_115 ) ; break;
case 0x00f3 : F_39 ( V_116 ) ; break;
case 0x00f4 : F_39 ( V_117 ) ; break;
case 0x00f7 : F_39 ( V_119 ) ; break;
case 0x00f8 : F_39 ( V_125 ) ; break;
default:
return 0 ;
}
return 1 ;
}
if ( V_52 -> V_87 & V_142 &&
( V_101 -> V_107 & V_111 ) == V_143 ) {
switch ( V_101 -> V_107 & V_114 ) {
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
static int F_40 ( struct V_48 * V_49 )
{
int V_57 ;
const unsigned char V_54 [] = { V_144 , 0x00 , 0x03 , 0x01 , 0x00 } ;
unsigned char * V_56 = F_14 ( V_54 , sizeof( V_54 ) , V_58 ) ;
if ( ! V_56 ) {
V_57 = - V_59 ;
F_18 ( V_49 , L_8 , V_57 ) ;
return V_57 ;
}
V_57 = F_15 ( V_49 , V_56 [ 0 ] , V_56 , sizeof( V_54 ) ,
V_61 , V_62 ) ;
F_16 ( V_56 ) ;
if ( V_57 != sizeof( V_54 ) ) {
F_18 ( V_49 , L_9 , V_57 ) ;
return V_57 ;
}
return 0 ;
}
static int T_3 F_41 ( struct V_48 * V_49 )
{
struct V_1 * V_52 = F_12 ( V_49 ) ;
if ( V_52 -> V_12 )
return F_40 ( V_49 ) ;
return 0 ;
}
static int F_42 ( struct V_48 * V_49 , const struct V_145 * V_36 )
{
int V_57 ;
struct V_1 * V_52 ;
V_52 = F_27 ( & V_49 -> V_80 , sizeof( * V_52 ) , V_58 ) ;
if ( V_52 == NULL ) {
F_18 ( V_49 , L_10 ) ;
return - V_59 ;
}
F_43 ( V_49 , V_52 ) ;
V_52 -> V_87 = V_36 -> V_146 ;
if ( V_52 -> V_87 & V_147 )
V_52 -> V_12 = & V_148 ;
if ( V_52 -> V_87 & V_149 ) {
struct V_150 * V_151 = F_44 ( V_49 -> V_80 . V_152 ) ;
if ( V_151 -> V_153 -> V_154 . V_155 == V_156 ) {
V_52 -> V_87 = V_104 ;
V_52 -> V_12 = & V_157 ;
}
}
if ( V_52 -> V_87 & V_88 ) {
V_49 -> V_87 |= V_158 |
V_159 ;
V_52 -> V_12 = & V_160 ;
}
if ( V_52 -> V_87 & V_161 )
V_49 -> V_87 |= V_162 ;
V_57 = F_45 ( V_49 ) ;
if ( V_57 ) {
F_18 ( V_49 , L_11 , V_57 ) ;
return V_57 ;
}
V_57 = F_46 ( V_49 , V_163 ) ;
if ( V_57 ) {
F_18 ( V_49 , L_12 , V_57 ) ;
return V_57 ;
}
if ( ! V_52 -> V_6 ) {
F_18 ( V_49 , L_13 ) ;
V_57 = - V_59 ;
goto V_164;
}
if ( V_52 -> V_12 ) {
V_52 -> V_6 -> V_81 = L_14 ;
} else {
V_52 -> V_6 -> V_81 = L_15 ;
}
if ( V_52 -> V_12 ) {
V_57 = F_40 ( V_49 ) ;
if ( V_57 )
goto V_164;
}
return 0 ;
V_164:
F_47 ( V_49 ) ;
return V_57 ;
}
static void F_48 ( struct V_48 * V_49 )
{
struct V_1 * V_52 = F_12 ( V_49 ) ;
if ( V_52 -> V_79 ) {
V_52 -> V_79 -> V_76 = true ;
F_49 ( & V_52 -> V_79 -> V_74 ) ;
}
F_47 ( V_49 ) ;
}
static T_4 * F_50 ( struct V_48 * V_49 , T_4 * V_165 ,
unsigned int * V_166 )
{
struct V_1 * V_52 = F_12 ( V_49 ) ;
if ( V_52 -> V_87 & V_167 &&
* V_166 >= 56 && V_165 [ 54 ] == 0x25 && V_165 [ 55 ] == 0x65 ) {
F_51 ( V_49 , L_16 ) ;
V_165 [ 55 ] = 0xdd ;
}
if ( V_52 -> V_87 & V_149 &&
* V_166 == 76 && V_165 [ 73 ] == 0x81 && V_165 [ 74 ] == 0x01 ) {
F_51 ( V_49 , L_17 ) ;
V_165 [ 74 ] &= ~ V_168 ;
}
if ( V_52 -> V_87 & V_88 &&
* V_166 == 403 && V_165 [ 388 ] == 0x09 && V_165 [ 389 ] == 0x76 ) {
* V_166 = 404 ;
V_165 = F_14 ( V_165 , * V_166 , V_58 ) ;
if ( ! V_165 )
return NULL ;
F_51 ( V_49 , L_18 ) ;
memmove ( V_165 + 392 , V_165 + 390 , 12 ) ;
V_165 [ 388 ] = 0x19 ;
V_165 [ 389 ] = 0x00 ;
V_165 [ 390 ] = 0x29 ;
V_165 [ 391 ] = 0xff ;
V_165 [ 402 ] = 0x00 ;
}
return V_165 ;
}
