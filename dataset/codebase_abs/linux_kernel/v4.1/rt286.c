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
if ( ! V_55 -> V_76 )
return - V_80 ;
if ( V_55 -> V_81 . V_82 ) {
F_17 ( V_55 -> V_83 , V_6 , & V_68 ) ;
* V_77 = V_68 & 0x80000000 ;
if ( * V_77 ) {
F_18 ( V_55 -> V_83 ,
V_84 , 0x200 , 0x200 ) ;
F_19 ( & V_55 -> V_76 -> V_85 ,
L_2 ) ;
F_19 ( & V_55 -> V_76 -> V_85 ,
L_3 ) ;
F_19 ( & V_55 -> V_76 -> V_85 ,
L_4 ) ;
F_20 ( & V_55 -> V_76 -> V_85 ) ;
F_21 ( V_55 -> V_83 , V_17 , 0x24 ) ;
F_22 ( 50 ) ;
F_18 ( V_55 -> V_83 ,
V_86 , 0xfcc0 , 0xd400 ) ;
F_22 ( 300 ) ;
F_17 ( V_55 -> V_83 , V_87 , & V_79 ) ;
if ( 0x0070 == ( V_79 & 0x0070 ) ) {
* V_78 = true ;
} else {
F_18 ( V_55 -> V_83 ,
V_86 , 0xfcc0 , 0xe400 ) ;
F_22 ( 300 ) ;
F_17 ( V_55 -> V_83 ,
V_87 , & V_79 ) ;
if ( 0x0070 == ( V_79 & 0x0070 ) )
* V_78 = true ;
else
* V_78 = false ;
}
F_18 ( V_55 -> V_83 ,
V_84 , 0x200 , 0x0 ) ;
} else {
* V_78 = false ;
F_21 ( V_55 -> V_83 , V_17 , 0x20 ) ;
}
} else {
F_17 ( V_55 -> V_83 , V_6 , & V_68 ) ;
* V_77 = V_68 & 0x80000000 ;
F_17 ( V_55 -> V_83 , V_7 , & V_68 ) ;
* V_78 = V_68 & 0x80000000 ;
}
F_23 ( & V_55 -> V_76 -> V_85 , L_2 ) ;
F_23 ( & V_55 -> V_76 -> V_85 , L_3 ) ;
if ( ! * V_77 )
F_23 ( & V_55 -> V_76 -> V_85 , L_4 ) ;
F_20 ( & V_55 -> V_76 -> V_85 ) ;
return 0 ;
}
static void F_24 ( struct V_88 * V_89 )
{
struct V_54 * V_55 =
F_25 ( V_89 , struct V_54 , V_90 . V_89 ) ;
int V_91 = 0 ;
bool V_77 = false ;
bool V_78 = false ;
F_16 ( V_55 , & V_77 , & V_78 ) ;
if ( V_77 == true )
V_91 |= V_92 ;
if ( V_78 == true )
V_91 |= V_93 ;
F_26 ( V_55 -> V_94 , V_91 ,
V_93 | V_92 ) ;
}
int F_27 ( struct V_75 * V_76 , struct V_95 * V_94 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
V_55 -> V_94 = V_94 ;
if ( V_94 ) {
if ( V_55 -> V_94 -> V_91 & V_92 )
F_19 ( & V_76 -> V_85 , L_4 ) ;
F_18 ( V_55 -> V_83 , V_96 , 0x2 , 0x2 ) ;
F_26 ( V_55 -> V_94 , V_55 -> V_94 -> V_91 ,
V_93 | V_92 ) ;
} else {
F_18 ( V_55 -> V_83 , V_96 , 0x2 , 0x0 ) ;
F_23 ( & V_76 -> V_85 , L_4 ) ;
}
F_20 ( & V_76 -> V_85 ) ;
return 0 ;
}
static int F_28 ( struct V_97 * V_98 ,
struct V_97 * V_99 )
{
struct V_75 * V_76 = F_29 ( V_98 -> V_85 ) ;
struct V_54 * V_55 = F_14 ( V_76 ) ;
if ( V_55 -> V_100 == V_101 )
return 1 ;
else
return 0 ;
}
static int F_30 ( struct V_97 * V_102 ,
struct V_103 * V_104 , int V_105 )
{
struct V_75 * V_76 = F_29 ( V_102 -> V_85 ) ;
switch ( V_105 ) {
case V_106 :
F_15 ( V_76 ,
V_21 , V_107 ) ;
break;
case V_108 :
F_15 ( V_76 ,
V_21 , V_109 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_31 ( struct V_97 * V_102 ,
struct V_103 * V_104 , int V_105 )
{
struct V_75 * V_76 = F_29 ( V_102 -> V_85 ) ;
switch ( V_105 ) {
case V_106 :
F_15 ( V_76 , V_20 , 0x20 ) ;
break;
case V_108 :
F_15 ( V_76 , V_20 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_32 ( struct V_97 * V_102 ,
struct V_103 * V_104 , int V_105 )
{
struct V_75 * V_76 = F_29 ( V_102 -> V_85 ) ;
switch ( V_105 ) {
case V_110 :
F_33 ( V_76 ,
V_86 , 0x0400 , 0x0000 ) ;
F_34 ( 50 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_35 ( struct V_97 * V_102 ,
struct V_103 * V_104 , int V_105 )
{
struct V_75 * V_76 = F_29 ( V_102 -> V_85 ) ;
switch ( V_105 ) {
case V_106 :
F_33 ( V_76 , V_111 , 0x38 , 0x08 ) ;
break;
case V_108 :
F_33 ( V_76 , V_111 , 0x38 , 0x30 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_36 ( struct V_97 * V_102 ,
struct V_103 * V_104 , int V_105 )
{
struct V_75 * V_76 = F_29 ( V_102 -> V_85 ) ;
switch ( V_105 ) {
case V_110 :
F_33 ( V_76 ,
V_112 , 0xc000 , 0x8000 ) ;
F_33 ( V_76 ,
V_113 , 0xc000 , 0x8000 ) ;
break;
case V_114 :
F_33 ( V_76 ,
V_112 , 0xc000 , 0x0000 ) ;
F_33 ( V_76 ,
V_113 , 0xc000 , 0x0000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_37 ( struct V_115 * V_116 ,
struct V_117 * V_118 ,
struct V_119 * V_120 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
struct V_54 * V_55 = F_14 ( V_76 ) ;
unsigned int V_79 = 0 ;
int V_121 ;
switch ( F_38 ( V_118 ) ) {
case 44100 :
V_79 |= 0x4000 ;
break;
case 48000 :
break;
default:
F_39 ( V_76 -> V_2 , L_5 ,
F_38 ( V_118 ) ) ;
return - V_80 ;
}
switch ( V_55 -> V_122 ) {
case 12288000 :
case 24576000 :
if ( F_38 ( V_118 ) != 48000 ) {
F_39 ( V_76 -> V_2 , L_6 ,
F_38 ( V_118 ) , V_55 -> V_122 ) ;
return - V_80 ;
}
break;
case 11289600 :
case 22579200 :
if ( F_38 ( V_118 ) != 44100 ) {
F_39 ( V_76 -> V_2 , L_6 ,
F_38 ( V_118 ) , V_55 -> V_122 ) ;
return - V_80 ;
}
break;
}
if ( F_40 ( V_118 ) <= 16 ) {
V_79 |= ( F_40 ( V_118 ) - 1 ) ;
} else {
F_39 ( V_76 -> V_2 , L_7 ,
F_40 ( V_118 ) ) ;
return - V_80 ;
}
V_121 = 0 ;
switch ( F_41 ( V_118 ) ) {
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
return - V_80 ;
}
F_33 ( V_76 ,
V_123 , 0x0018 , V_121 << 3 ) ;
F_42 ( V_76 -> V_2 , L_8 , V_79 ) ;
F_33 ( V_76 , V_39 , 0x407f , V_79 ) ;
F_33 ( V_76 , V_40 , 0x407f , V_79 ) ;
return 0 ;
}
static int F_43 ( struct V_119 * V_120 , unsigned int V_124 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
switch ( V_124 & V_125 ) {
case V_126 :
F_33 ( V_76 ,
V_123 , 0x800 , 0x800 ) ;
break;
case V_127 :
F_33 ( V_76 ,
V_123 , 0x800 , 0x0 ) ;
break;
default:
return - V_80 ;
}
switch ( V_124 & V_128 ) {
case V_129 :
F_33 ( V_76 ,
V_123 , 0x300 , 0x0 ) ;
break;
case V_130 :
F_33 ( V_76 ,
V_123 , 0x300 , 0x1 << 8 ) ;
break;
case V_131 :
F_33 ( V_76 ,
V_123 , 0x300 , 0x2 << 8 ) ;
break;
case V_132 :
F_33 ( V_76 ,
V_123 , 0x300 , 0x3 << 8 ) ;
break;
default:
return - V_80 ;
}
F_33 ( V_76 , V_39 , 0x8000 , 0 ) ;
F_33 ( V_76 , V_40 , 0x8000 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_119 * V_120 ,
int V_100 , unsigned int V_133 , int V_134 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_42 ( V_76 -> V_2 , L_9 , V_135 , V_133 ) ;
if ( V_101 == V_100 ) {
F_33 ( V_76 ,
V_136 , 0x0100 , 0x0 ) ;
F_33 ( V_76 ,
V_137 , 0x20 , 0x20 ) ;
} else {
F_33 ( V_76 ,
V_136 , 0x0100 , 0x0100 ) ;
F_33 ( V_76 ,
V_138 , 0x4 , 0x4 ) ;
F_33 ( V_76 ,
V_137 , 0x20 , 0x0 ) ;
}
switch ( V_133 ) {
case 19200000 :
if ( V_101 == V_100 ) {
F_39 ( V_76 -> V_2 , L_10 ) ;
return - V_80 ;
}
F_33 ( V_76 ,
V_136 , 0x40 , 0x40 ) ;
break;
case 24000000 :
if ( V_101 == V_100 ) {
F_39 ( V_76 -> V_2 , L_10 ) ;
return - V_80 ;
}
F_33 ( V_76 ,
V_136 , 0x40 , 0x0 ) ;
break;
case 12288000 :
case 11289600 :
F_33 ( V_76 ,
V_136 , 0x8 , 0x0 ) ;
F_33 ( V_76 ,
V_139 , 0xfc1e , 0x0004 ) ;
break;
case 24576000 :
case 22579200 :
F_33 ( V_76 ,
V_136 , 0x8 , 0x8 ) ;
F_33 ( V_76 ,
V_139 , 0xfc1e , 0x5406 ) ;
break;
default:
F_39 ( V_76 -> V_2 , L_11 ) ;
return - V_80 ;
}
V_55 -> V_122 = V_133 ;
V_55 -> V_100 = V_100 ;
return 0 ;
}
static int F_45 ( struct V_119 * V_120 , unsigned int V_140 )
{
struct V_75 * V_76 = V_120 -> V_76 ;
F_42 ( V_76 -> V_2 , L_12 , V_135 , V_140 ) ;
if ( 50 == V_140 )
F_33 ( V_76 ,
V_123 , 0x1000 , 0x1000 ) ;
else
F_33 ( V_76 ,
V_123 , 0x1000 , 0x0 ) ;
return 0 ;
}
static int F_46 ( struct V_75 * V_76 ,
enum V_141 V_142 )
{
switch ( V_142 ) {
case V_143 :
if ( V_144 == V_76 -> V_85 . V_145 ) {
F_15 ( V_76 ,
V_9 , V_146 ) ;
F_33 ( V_76 ,
V_84 , 0x200 , 0x200 ) ;
}
break;
case V_147 :
F_34 ( 10 ) ;
F_33 ( V_76 ,
V_86 , 0x0400 , 0x0400 ) ;
F_33 ( V_76 ,
V_84 , 0x200 , 0x0 ) ;
break;
case V_144 :
F_15 ( V_76 ,
V_9 , V_148 ) ;
F_33 ( V_76 ,
V_86 , 0x0400 , 0x0000 ) ;
break;
default:
break;
}
V_76 -> V_85 . V_145 = V_142 ;
return 0 ;
}
static T_3 F_47 ( int V_149 , void * V_56 )
{
struct V_54 * V_55 = V_56 ;
bool V_77 = false ;
bool V_78 = false ;
int V_91 = 0 ;
F_16 ( V_55 , & V_77 , & V_78 ) ;
F_18 ( V_55 -> V_83 , V_96 , 0x1 , 0x1 ) ;
if ( V_77 == true )
V_91 |= V_92 ;
if ( V_78 == true )
V_91 |= V_93 ;
F_26 ( V_55 -> V_94 , V_91 ,
V_93 | V_92 ) ;
F_48 ( & V_55 -> V_150 -> V_2 , 300 ) ;
return V_151 ;
}
static int F_49 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
V_55 -> V_76 = V_76 ;
if ( V_55 -> V_150 -> V_149 ) {
F_18 ( V_55 -> V_83 ,
V_96 , 0x2 , 0x2 ) ;
F_50 ( & V_55 -> V_90 ,
F_24 ) ;
F_51 ( & V_55 -> V_90 ,
F_52 ( 1250 ) ) ;
}
return 0 ;
}
static int F_53 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_54 ( & V_55 -> V_90 ) ;
return 0 ;
}
static int F_55 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_56 ( V_55 -> V_83 , true ) ;
F_57 ( V_55 -> V_83 ) ;
return 0 ;
}
static int F_58 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_56 ( V_55 -> V_83 , false ) ;
F_13 ( V_76 ) ;
F_59 ( V_55 -> V_83 ) ;
return 0 ;
}
static int F_60 ( struct V_52 * V_150 ,
const struct V_152 * V_153 )
{
struct V_154 * V_81 = F_61 ( & V_150 -> V_2 ) ;
struct V_54 * V_55 ;
int V_58 , V_57 , V_79 ;
V_55 = F_62 ( & V_150 -> V_2 , sizeof( * V_55 ) ,
V_155 ) ;
if ( NULL == V_55 )
return - V_156 ;
V_55 -> V_83 = F_63 ( & V_150 -> V_2 , NULL , V_150 , & V_157 ) ;
if ( F_64 ( V_55 -> V_83 ) ) {
V_57 = F_65 ( V_55 -> V_83 ) ;
F_39 ( & V_150 -> V_2 , L_13 ,
V_57 ) ;
return V_57 ;
}
V_57 = F_17 ( V_55 -> V_83 ,
F_2 ( V_4 , V_5 ) , & V_79 ) ;
if ( V_57 != 0 ) {
F_39 ( & V_150 -> V_2 , L_14 , V_57 ) ;
return V_57 ;
}
if ( V_79 != V_158 && V_79 != V_159 ) {
F_39 ( & V_150 -> V_2 ,
L_15 , V_79 ) ;
return - V_160 ;
}
V_55 -> V_60 = V_161 ;
V_55 -> V_150 = V_150 ;
F_66 ( V_150 , V_55 ) ;
for ( V_58 = 0 ; V_58 < V_59 ; V_58 ++ )
F_21 ( V_55 -> V_83 , V_55 -> V_60 [ V_58 ] . V_3 ,
V_55 -> V_60 [ V_58 ] . V_61 ) ;
for ( V_58 = 0 ; V_58 < F_67 ( V_162 ) ; V_58 ++ )
F_21 ( V_55 -> V_83 , V_162 [ V_58 ] . V_3 ,
V_162 [ V_58 ] . V_61 ) ;
if ( V_81 )
V_55 -> V_81 = * V_81 ;
if ( F_68 ( V_163 ) ||
F_68 ( V_164 ) )
V_55 -> V_81 . V_82 = true ;
F_21 ( V_55 -> V_83 , V_9 , V_148 ) ;
for ( V_58 = 0 ; V_58 < V_165 ; V_58 ++ )
F_21 ( V_55 -> V_83 ,
F_4 ( V_166 [ V_58 ] ) ,
V_167 ) ;
if ( ! V_55 -> V_81 . V_82 ) {
F_21 ( V_55 -> V_83 , V_87 , 0x0000 ) ;
F_21 ( V_55 -> V_83 , V_168 , 0x0816 ) ;
F_18 ( V_55 -> V_83 ,
V_86 , 0xf000 , 0xb000 ) ;
} else {
F_18 ( V_55 -> V_83 ,
V_86 , 0xf000 , 0x5000 ) ;
}
F_34 ( 10 ) ;
if ( ! V_55 -> V_81 . V_169 )
F_21 ( V_55 -> V_83 , V_23 , 0x4000 ) ;
else
F_21 ( V_55 -> V_83 , V_23 , 0 ) ;
F_34 ( 10 ) ;
F_21 ( V_55 -> V_83 , V_170 , 0x0000 ) ;
F_18 ( V_55 -> V_83 , V_111 , 0xc , 0x0 ) ;
F_18 ( V_55 -> V_83 , V_171 , 0x1001 , 0x1001 ) ;
F_18 ( V_55 -> V_83 , V_172 , 0x403a , 0x401a ) ;
F_18 ( V_55 -> V_83 , V_173 , 0xf777 , 0x4737 ) ;
F_18 ( V_55 -> V_83 , V_174 , 0x00ff , 0x003f ) ;
if ( F_68 ( V_164 ) ) {
F_18 ( V_55 -> V_83 ,
V_175 , 0x40 , 0x40 ) ;
F_18 ( V_55 -> V_83 ,
V_176 , 0x40 , 0x40 ) ;
F_18 ( V_55 -> V_83 ,
V_177 , 0x40 , 0x40 ) ;
F_18 ( V_55 -> V_83 ,
V_178 , 0xc , 0x8 ) ;
}
if ( V_55 -> V_150 -> V_149 ) {
V_57 = F_69 ( V_55 -> V_150 -> V_149 , NULL , F_47 ,
V_179 | V_180 , L_16 , V_55 ) ;
if ( V_57 != 0 ) {
F_39 ( & V_150 -> V_2 ,
L_17 , V_57 ) ;
return V_57 ;
}
}
V_57 = F_70 ( & V_150 -> V_2 , & V_181 ,
V_182 , F_67 ( V_182 ) ) ;
return V_57 ;
}
static int F_71 ( struct V_52 * V_150 )
{
struct V_54 * V_55 = F_6 ( V_150 ) ;
if ( V_150 -> V_149 )
F_72 ( V_150 -> V_149 , V_55 ) ;
F_73 ( & V_150 -> V_2 ) ;
return 0 ;
}
