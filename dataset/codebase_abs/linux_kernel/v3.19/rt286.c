static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0 ... 0xff :
case F_2 ( V_4 , V_5 ) :
case V_6 :
case V_7 :
case V_8 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0 ... 0xff :
case F_2 ( V_4 , V_5 ) :
case V_6 :
case V_7 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_8 :
case V_42 :
case V_43 :
case F_4 ( V_44 ) :
case F_4 ( V_45 ) :
case F_4 ( V_46 ) :
case F_4 ( V_47 ) :
case F_4 ( V_48 ) :
case F_4 ( V_49 ) :
return true ;
default:
return false ;
}
}
static int F_5 ( void * V_50 , unsigned int V_3 , unsigned int V_51 )
{
struct V_52 * V_53 = V_50 ;
struct V_54 * V_55 = F_6 ( V_53 ) ;
T_1 V_56 [ 4 ] ;
int V_57 , V_58 ;
if ( V_3 <= 0xff ) {
F_5 ( V_53 , V_41 , V_3 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
if ( V_3 == V_55 -> V_60 [ V_58 ] . V_3 ) {
V_55 -> V_60 [ V_58 ] . V_61 = V_51 ;
break;
}
}
V_3 = V_8 ;
}
V_56 [ 0 ] = ( V_3 >> 24 ) & 0xff ;
V_56 [ 1 ] = ( V_3 >> 16 ) & 0xff ;
V_56 [ 2 ] = ( ( V_3 >> 8 ) & 0xff ) | ( ( V_51 >> 8 ) & 0xff ) ;
V_56 [ 3 ] = V_51 & 0xff ;
V_57 = F_7 ( V_53 , V_56 , 4 ) ;
if ( V_57 == 4 )
return 0 ;
else
F_8 ( L_1 , V_57 ) ;
if ( V_57 < 0 )
return V_57 ;
else
return - V_62 ;
}
static int F_9 ( void * V_50 , unsigned int V_3 , unsigned int * V_51 )
{
struct V_52 * V_53 = V_50 ;
struct V_63 V_64 [ 2 ] ;
int V_57 ;
T_2 V_65 ;
unsigned int V_66 , V_67 , V_68 = 0x0 ;
if ( V_3 <= 0xff ) {
F_5 ( V_53 , V_41 , V_3 ) ;
V_3 = V_8 ;
}
V_3 = V_3 | 0x80000 ;
V_67 = ( V_3 >> 8 ) & 0xfff ;
if ( V_69 == ( V_67 & 0xf00 ) ) {
V_66 = ( V_3 >> 8 ) & 0xf ;
V_3 = ( V_3 & ~ 0xf0f ) | V_66 ;
}
V_65 = F_10 ( V_3 ) ;
V_64 [ 0 ] . V_70 = V_53 -> V_70 ;
V_64 [ 0 ] . V_71 = 0 ;
V_64 [ 0 ] . V_72 = 4 ;
V_64 [ 0 ] . V_68 = ( T_1 * ) & V_65 ;
V_64 [ 1 ] . V_70 = V_53 -> V_70 ;
V_64 [ 1 ] . V_71 = V_73 ;
V_64 [ 1 ] . V_72 = 4 ;
V_64 [ 1 ] . V_68 = ( T_1 * ) & V_68 ;
V_57 = F_11 ( V_53 -> V_74 , V_64 , 2 ) ;
if ( V_57 < 0 )
return V_57 ;
else if ( V_57 != 2 )
return - V_62 ;
* V_51 = F_12 ( V_68 ) ;
return 0 ;
}
static void F_13 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
int V_58 ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ ) {
F_15 ( V_76 , V_55 -> V_60 [ V_58 ] . V_3 ,
V_55 -> V_60 [ V_58 ] . V_61 ) ;
}
}
static int F_16 ( struct V_54 * V_55 , bool * V_77 , bool * V_78 )
{
unsigned int V_79 , V_68 ;
* V_77 = false ;
* V_78 = false ;
if ( V_55 -> V_80 . V_81 ) {
F_17 ( V_55 -> V_82 , V_6 , & V_68 ) ;
* V_77 = V_68 & 0x80000000 ;
if ( * V_77 ) {
F_18 ( V_55 -> V_82 ,
V_83 , 0x200 , 0x200 ) ;
F_19 ( & V_55 -> V_76 -> V_84 ,
L_2 ) ;
F_19 ( & V_55 -> V_76 -> V_84 ,
L_3 ) ;
F_19 ( & V_55 -> V_76 -> V_84 ,
L_4 ) ;
F_20 ( & V_55 -> V_76 -> V_84 ) ;
F_21 ( V_55 -> V_82 , V_17 , 0x24 ) ;
F_22 ( 50 ) ;
F_18 ( V_55 -> V_82 ,
V_85 , 0xfcc0 , 0xd400 ) ;
F_22 ( 300 ) ;
F_17 ( V_55 -> V_82 , V_86 , & V_79 ) ;
if ( 0x0070 == ( V_79 & 0x0070 ) ) {
* V_78 = true ;
} else {
F_18 ( V_55 -> V_82 ,
V_85 , 0xfcc0 , 0xe400 ) ;
F_22 ( 300 ) ;
F_17 ( V_55 -> V_82 ,
V_86 , & V_79 ) ;
if ( 0x0070 == ( V_79 & 0x0070 ) )
* V_78 = true ;
else
* V_78 = false ;
}
F_18 ( V_55 -> V_82 ,
V_83 , 0x200 , 0x0 ) ;
} else {
* V_78 = false ;
F_21 ( V_55 -> V_82 , V_17 , 0x20 ) ;
}
} else {
F_17 ( V_55 -> V_82 , V_6 , & V_68 ) ;
* V_77 = V_68 & 0x80000000 ;
F_17 ( V_55 -> V_82 , V_7 , & V_68 ) ;
* V_78 = V_68 & 0x80000000 ;
}
F_23 ( & V_55 -> V_76 -> V_84 , L_2 ) ;
F_23 ( & V_55 -> V_76 -> V_84 , L_3 ) ;
if ( ! * V_77 )
F_23 ( & V_55 -> V_76 -> V_84 , L_4 ) ;
F_20 ( & V_55 -> V_76 -> V_84 ) ;
return 0 ;
}
static void F_24 ( struct V_87 * V_88 )
{
struct V_54 * V_55 =
F_25 ( V_88 , struct V_54 , V_89 . V_88 ) ;
int V_90 = 0 ;
bool V_77 = false ;
bool V_78 = false ;
F_16 ( V_55 , & V_77 , & V_78 ) ;
if ( V_77 == true )
V_90 |= V_91 ;
if ( V_78 == true )
V_90 |= V_92 ;
F_26 ( V_55 -> V_93 , V_90 ,
V_92 | V_91 ) ;
}
int F_27 ( struct V_75 * V_76 , struct V_94 * V_93 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
V_55 -> V_93 = V_93 ;
F_26 ( V_55 -> V_93 , 0 ,
V_92 | V_91 ) ;
return 0 ;
}
static int F_28 ( struct V_95 * V_96 ,
struct V_95 * V_97 )
{
struct V_54 * V_55 = F_14 ( V_96 -> V_76 ) ;
if ( V_55 -> V_98 == V_99 )
return 1 ;
else
return 0 ;
}
static int F_29 ( struct V_95 * V_100 ,
struct V_101 * V_102 , int V_103 )
{
struct V_75 * V_76 = V_100 -> V_76 ;
switch ( V_103 ) {
case V_104 :
F_15 ( V_76 ,
V_21 , V_105 ) ;
break;
case V_106 :
F_15 ( V_76 ,
V_21 , V_107 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_30 ( struct V_95 * V_100 ,
struct V_101 * V_102 , int V_103 )
{
struct V_75 * V_76 = V_100 -> V_76 ;
switch ( V_103 ) {
case V_104 :
F_15 ( V_76 , V_20 , 0x20 ) ;
break;
case V_106 :
F_15 ( V_76 , V_20 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_31 ( struct V_95 * V_100 ,
struct V_101 * V_102 , int V_103 )
{
struct V_75 * V_76 = V_100 -> V_76 ;
unsigned int V_108 ;
V_108 = ( V_100 -> V_3 >> 20 ) & 0xff ;
switch ( V_103 ) {
case V_104 :
F_32 ( V_76 ,
F_33 ( V_109 , V_108 , 0 ) ,
0x7080 , 0x7000 ) ;
break;
case V_106 :
F_32 ( V_76 ,
F_33 ( V_109 , V_108 , 0 ) ,
0x7080 , 0x7080 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_34 ( struct V_95 * V_100 ,
struct V_101 * V_102 , int V_103 )
{
struct V_75 * V_76 = V_100 -> V_76 ;
switch ( V_103 ) {
case V_110 :
F_32 ( V_76 ,
V_85 , 0x0400 , 0x0000 ) ;
F_35 ( 50 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_36 ( struct V_95 * V_100 ,
struct V_101 * V_102 , int V_103 )
{
struct V_75 * V_76 = V_100 -> V_76 ;
switch ( V_103 ) {
case V_104 :
F_32 ( V_76 , V_111 , 0x38 , 0x08 ) ;
break;
case V_106 :
F_32 ( V_76 , V_111 , 0x38 , 0x30 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_37 ( struct V_95 * V_100 ,
struct V_101 * V_102 , int V_103 )
{
struct V_75 * V_76 = V_100 -> V_76 ;
switch ( V_103 ) {
case V_110 :
F_32 ( V_76 ,
V_112 , 0xc000 , 0x8000 ) ;
F_32 ( V_76 ,
V_113 , 0xc000 , 0x8000 ) ;
break;
case V_114 :
F_32 ( V_76 ,
V_112 , 0xc000 , 0x0000 ) ;
F_32 ( V_76 ,
V_113 , 0xc000 , 0x0000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_38 ( struct V_115 * V_116 ,
struct V_117 * V_118 ,
struct V_119 * V_120 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
struct V_54 * V_55 = F_14 ( V_76 ) ;
unsigned int V_79 = 0 ;
int V_121 ;
switch ( F_39 ( V_118 ) ) {
case 44100 :
V_79 |= 0x4000 ;
break;
case 48000 :
break;
default:
F_40 ( V_76 -> V_2 , L_5 ,
F_39 ( V_118 ) ) ;
return - V_122 ;
}
switch ( V_55 -> V_123 ) {
case 12288000 :
case 24576000 :
if ( F_39 ( V_118 ) != 48000 ) {
F_40 ( V_76 -> V_2 , L_6 ,
F_39 ( V_118 ) , V_55 -> V_123 ) ;
return - V_122 ;
}
break;
case 11289600 :
case 22579200 :
if ( F_39 ( V_118 ) != 44100 ) {
F_40 ( V_76 -> V_2 , L_6 ,
F_39 ( V_118 ) , V_55 -> V_123 ) ;
return - V_122 ;
}
break;
}
if ( F_41 ( V_118 ) <= 16 ) {
V_79 |= ( F_41 ( V_118 ) - 1 ) ;
} else {
F_40 ( V_76 -> V_2 , L_7 ,
F_41 ( V_118 ) ) ;
return - V_122 ;
}
V_121 = 0 ;
switch ( F_42 ( V_118 ) ) {
case 16 :
V_121 = 0 ;
V_79 |= ( 0x1 << 4 ) ;
break;
case 32 :
V_121 = 2 ;
V_79 |= ( 0x4 << 4 ) ;
break;
case 20 :
V_121 = 1 ;
V_79 |= ( 0x2 << 4 ) ;
break;
case 24 :
V_121 = 2 ;
V_79 |= ( 0x3 << 4 ) ;
break;
case 8 :
V_121 = 3 ;
break;
default:
return - V_122 ;
}
F_32 ( V_76 ,
V_124 , 0x0018 , V_121 << 3 ) ;
F_43 ( V_76 -> V_2 , L_8 , V_79 ) ;
F_32 ( V_76 , V_39 , 0x407f , V_79 ) ;
F_32 ( V_76 , V_40 , 0x407f , V_79 ) ;
return 0 ;
}
static int F_44 ( struct V_119 * V_120 , unsigned int V_125 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
switch ( V_125 & V_126 ) {
case V_127 :
F_32 ( V_76 ,
V_124 , 0x800 , 0x800 ) ;
break;
case V_128 :
F_32 ( V_76 ,
V_124 , 0x800 , 0x0 ) ;
break;
default:
return - V_122 ;
}
switch ( V_125 & V_129 ) {
case V_130 :
F_32 ( V_76 ,
V_124 , 0x300 , 0x0 ) ;
break;
case V_131 :
F_32 ( V_76 ,
V_124 , 0x300 , 0x1 << 8 ) ;
break;
case V_132 :
F_32 ( V_76 ,
V_124 , 0x300 , 0x2 << 8 ) ;
break;
case V_133 :
F_32 ( V_76 ,
V_124 , 0x300 , 0x3 << 8 ) ;
break;
default:
return - V_122 ;
}
F_32 ( V_76 , V_39 , 0x8000 , 0 ) ;
F_32 ( V_76 , V_40 , 0x8000 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_119 * V_120 ,
int V_98 , unsigned int V_134 , int V_135 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_43 ( V_76 -> V_2 , L_9 , V_136 , V_134 ) ;
if ( V_99 == V_98 ) {
F_32 ( V_76 ,
V_137 , 0x0100 , 0x0 ) ;
F_32 ( V_76 ,
V_138 , 0x20 , 0x20 ) ;
} else {
F_32 ( V_76 ,
V_137 , 0x0100 , 0x0100 ) ;
F_32 ( V_76 ,
V_139 , 0x4 , 0x4 ) ;
F_32 ( V_76 ,
V_138 , 0x20 , 0x0 ) ;
}
switch ( V_134 ) {
case 19200000 :
if ( V_99 == V_98 ) {
F_40 ( V_76 -> V_2 , L_10 ) ;
return - V_122 ;
}
F_32 ( V_76 ,
V_137 , 0x40 , 0x40 ) ;
break;
case 24000000 :
if ( V_99 == V_98 ) {
F_40 ( V_76 -> V_2 , L_10 ) ;
return - V_122 ;
}
F_32 ( V_76 ,
V_137 , 0x40 , 0x0 ) ;
break;
case 12288000 :
case 11289600 :
F_32 ( V_76 ,
V_137 , 0x8 , 0x0 ) ;
F_32 ( V_76 ,
V_140 , 0xfc1e , 0x0004 ) ;
break;
case 24576000 :
case 22579200 :
F_32 ( V_76 ,
V_137 , 0x8 , 0x8 ) ;
F_32 ( V_76 ,
V_140 , 0xfc1e , 0x5406 ) ;
break;
default:
F_40 ( V_76 -> V_2 , L_11 ) ;
return - V_122 ;
}
V_55 -> V_123 = V_134 ;
V_55 -> V_98 = V_98 ;
return 0 ;
}
static int F_46 ( struct V_119 * V_120 , unsigned int V_141 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
F_43 ( V_76 -> V_2 , L_12 , V_136 , V_141 ) ;
if ( 50 == V_141 )
F_32 ( V_76 ,
V_124 , 0x1000 , 0x1000 ) ;
else
F_32 ( V_76 ,
V_124 , 0x1000 , 0x0 ) ;
return 0 ;
}
static int F_47 ( struct V_75 * V_76 ,
enum V_142 V_143 )
{
switch ( V_143 ) {
case V_144 :
if ( V_145 == V_76 -> V_84 . V_146 ) {
F_15 ( V_76 ,
V_9 , V_147 ) ;
F_32 ( V_76 ,
V_83 , 0x200 , 0x200 ) ;
}
break;
case V_148 :
F_35 ( 10 ) ;
F_32 ( V_76 ,
V_85 , 0x0400 , 0x0400 ) ;
F_32 ( V_76 ,
V_83 , 0x200 , 0x0 ) ;
break;
case V_145 :
F_15 ( V_76 ,
V_9 , V_149 ) ;
F_32 ( V_76 ,
V_85 , 0x0400 , 0x0000 ) ;
break;
default:
break;
}
V_76 -> V_84 . V_146 = V_143 ;
return 0 ;
}
static T_3 F_48 ( int V_150 , void * V_56 )
{
struct V_54 * V_55 = V_56 ;
bool V_77 = false ;
bool V_78 = false ;
int V_90 = 0 ;
F_16 ( V_55 , & V_77 , & V_78 ) ;
F_18 ( V_55 -> V_82 , V_151 , 0x1 , 0x1 ) ;
if ( V_77 == true )
V_90 |= V_91 ;
if ( V_78 == true )
V_90 |= V_92 ;
F_26 ( V_55 -> V_93 , V_90 ,
V_92 | V_91 ) ;
F_49 ( & V_55 -> V_152 -> V_2 , 300 ) ;
return V_153 ;
}
static int F_50 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
V_55 -> V_76 = V_76 ;
V_76 -> V_84 . V_146 = V_154 ;
if ( V_55 -> V_152 -> V_150 ) {
F_18 ( V_55 -> V_82 ,
V_151 , 0x2 , 0x2 ) ;
F_51 ( & V_55 -> V_89 ,
F_24 ) ;
F_52 ( & V_55 -> V_89 ,
F_53 ( 1250 ) ) ;
}
return 0 ;
}
static int F_54 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_55 ( & V_55 -> V_89 ) ;
return 0 ;
}
static int F_56 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_57 ( V_55 -> V_82 , true ) ;
F_58 ( V_55 -> V_82 ) ;
return 0 ;
}
static int F_59 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_57 ( V_55 -> V_82 , false ) ;
F_13 ( V_76 ) ;
F_60 ( V_55 -> V_82 ) ;
return 0 ;
}
static int F_61 ( struct V_52 * V_152 ,
const struct V_155 * V_156 )
{
struct V_157 * V_80 = F_62 ( & V_152 -> V_2 ) ;
struct V_54 * V_55 ;
int V_58 , V_57 ;
V_55 = F_63 ( & V_152 -> V_2 , sizeof( * V_55 ) ,
V_158 ) ;
if ( NULL == V_55 )
return - V_159 ;
V_55 -> V_82 = F_64 ( & V_152 -> V_2 , NULL , V_152 , & V_160 ) ;
if ( F_65 ( V_55 -> V_82 ) ) {
V_57 = F_66 ( V_55 -> V_82 ) ;
F_40 ( & V_152 -> V_2 , L_13 ,
V_57 ) ;
return V_57 ;
}
F_17 ( V_55 -> V_82 ,
F_2 ( V_4 , V_5 ) , & V_57 ) ;
if ( V_57 != V_161 ) {
F_40 ( & V_152 -> V_2 ,
L_14 , V_57 ) ;
return - V_162 ;
}
V_55 -> V_60 = V_163 ;
V_55 -> V_152 = V_152 ;
F_67 ( V_152 , V_55 ) ;
if ( V_80 )
V_55 -> V_80 = * V_80 ;
if ( F_68 ( V_164 ) )
V_55 -> V_80 . V_81 = true ;
F_21 ( V_55 -> V_82 , V_9 , V_149 ) ;
for ( V_58 = 0 ; V_58 < V_165 ; V_58 ++ )
F_21 ( V_55 -> V_82 ,
F_4 ( V_166 [ V_58 ] ) ,
V_167 ) ;
if ( ! V_55 -> V_80 . V_81 ) {
F_21 ( V_55 -> V_82 , V_86 , 0x0000 ) ;
F_21 ( V_55 -> V_82 , V_168 , 0x0816 ) ;
F_18 ( V_55 -> V_82 ,
V_85 , 0xf000 , 0xb000 ) ;
} else {
F_18 ( V_55 -> V_82 ,
V_85 , 0xf000 , 0x5000 ) ;
}
F_35 ( 10 ) ;
if ( ! V_55 -> V_80 . V_169 )
F_21 ( V_55 -> V_82 , V_23 , 0x4000 ) ;
else
F_21 ( V_55 -> V_82 , V_23 , 0 ) ;
F_35 ( 10 ) ;
F_21 ( V_55 -> V_82 , V_170 , 0x0000 ) ;
F_18 ( V_55 -> V_82 , V_111 , 0xc , 0x0 ) ;
F_18 ( V_55 -> V_82 , V_171 , 0x1001 , 0x1001 ) ;
F_18 ( V_55 -> V_82 , V_172 , 0x403a , 0x401a ) ;
F_18 ( V_55 -> V_82 , V_173 , 0xf777 , 0x4737 ) ;
F_18 ( V_55 -> V_82 , V_174 , 0x00ff , 0x003f ) ;
if ( V_55 -> V_152 -> V_150 ) {
V_57 = F_69 ( V_55 -> V_152 -> V_150 , NULL , F_48 ,
V_175 | V_176 , L_15 , V_55 ) ;
if ( V_57 != 0 ) {
F_40 ( & V_152 -> V_2 ,
L_16 , V_57 ) ;
return V_57 ;
}
}
V_57 = F_70 ( & V_152 -> V_2 , & V_177 ,
V_178 , F_71 ( V_178 ) ) ;
return V_57 ;
}
static int F_72 ( struct V_52 * V_152 )
{
struct V_54 * V_55 = F_6 ( V_152 ) ;
if ( V_152 -> V_150 )
F_73 ( V_152 -> V_150 , V_55 ) ;
F_74 ( & V_152 -> V_2 ) ;
return 0 ;
}
