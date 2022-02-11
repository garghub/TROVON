static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0 ... 0xff :
case F_2 ( V_4 , V_5 ) :
case V_6 :
case V_7 :
case V_8 :
case F_3 ( V_9 , V_10 , 0 ) :
case F_3 ( V_9 , V_11 , 0 ) :
case F_3 ( V_9 , V_12 , 0 ) :
return true ;
default:
return false ;
}
}
static bool F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case 0 ... 0xff :
case F_2 ( V_4 , V_5 ) :
case V_6 :
case V_7 :
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
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_8 :
case V_46 :
case V_47 :
case F_5 ( V_48 ) :
case F_5 ( V_49 ) :
case F_5 ( V_50 ) :
case F_5 ( V_51 ) :
case F_5 ( V_52 ) :
case F_5 ( V_10 ) :
case F_3 ( V_9 , V_10 , 0 ) :
case F_3 ( V_9 , V_11 , 0 ) :
case F_3 ( V_9 , V_12 , 0 ) :
return true ;
default:
return false ;
}
}
static void F_6 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
int V_57 ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
F_8 ( V_54 , V_56 -> V_59 [ V_57 ] . V_3 ,
V_56 -> V_59 [ V_57 ] . V_60 ) ;
}
}
static int F_9 ( struct V_55 * V_56 , bool * V_61 , bool * V_62 )
{
struct V_63 * V_64 ;
unsigned int V_65 , V_66 ;
* V_61 = false ;
* V_62 = false ;
if ( ! V_56 -> V_54 )
return - V_67 ;
V_64 = F_10 ( V_56 -> V_54 ) ;
if ( V_56 -> V_68 . V_69 ) {
F_11 ( V_56 -> V_70 , V_6 , & V_66 ) ;
* V_61 = V_66 & 0x80000000 ;
if ( * V_61 == V_56 -> V_71 )
return - 1 ;
V_56 -> V_71 = * V_61 ;
if ( * V_61 ) {
F_12 ( V_56 -> V_70 ,
V_72 , 0x200 , 0x200 ) ;
F_13 ( V_64 , L_1 ) ;
F_13 ( V_64 , L_2 ) ;
F_13 ( V_64 , L_3 ) ;
F_14 ( V_64 ) ;
F_12 ( V_56 -> V_70 ,
V_73 , 0x1001 , 0 ) ;
F_12 ( V_56 -> V_70 ,
V_74 , 0x4 , 0x4 ) ;
F_15 ( V_56 -> V_70 , V_21 , 0x24 ) ;
F_16 ( 50 ) ;
F_12 ( V_56 -> V_70 ,
V_75 , 0xfcc0 , 0xd400 ) ;
F_16 ( 300 ) ;
F_11 ( V_56 -> V_70 , V_76 , & V_65 ) ;
if ( 0x0070 == ( V_65 & 0x0070 ) ) {
* V_62 = true ;
} else {
F_12 ( V_56 -> V_70 ,
V_75 , 0xfcc0 , 0xe400 ) ;
F_16 ( 300 ) ;
F_11 ( V_56 -> V_70 ,
V_76 , & V_65 ) ;
if ( 0x0070 == ( V_65 & 0x0070 ) )
* V_62 = true ;
else
* V_62 = false ;
}
F_12 ( V_56 -> V_70 ,
V_72 , 0x200 , 0x0 ) ;
} else {
* V_62 = false ;
F_15 ( V_56 -> V_70 , V_21 , 0x20 ) ;
F_12 ( V_56 -> V_70 ,
V_75 , 0x0400 , 0x0000 ) ;
}
} else {
F_11 ( V_56 -> V_70 , V_6 , & V_66 ) ;
* V_61 = V_66 & 0x80000000 ;
F_11 ( V_56 -> V_70 , V_7 , & V_66 ) ;
* V_62 = V_66 & 0x80000000 ;
}
F_17 ( V_64 , L_1 ) ;
F_17 ( V_64 , L_2 ) ;
if ( ! * V_61 )
F_17 ( V_64 , L_3 ) ;
F_14 ( V_64 ) ;
F_18 ( L_4 , * V_61 , * V_62 ) ;
return 0 ;
}
static void F_19 ( struct V_77 * V_78 )
{
struct V_55 * V_56 =
F_20 ( V_78 , struct V_55 , V_79 . V_78 ) ;
int V_80 = 0 ;
bool V_61 = false ;
bool V_62 = false ;
if ( F_9 ( V_56 , & V_61 , & V_62 ) < 0 )
return;
if ( V_61 == true )
V_80 |= V_81 ;
if ( V_62 == true )
V_80 |= V_82 ;
F_21 ( V_56 -> V_83 , V_80 ,
V_82 | V_81 ) ;
}
int F_22 ( struct V_53 * V_54 , struct V_84 * V_83 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
struct V_63 * V_64 ;
bool V_61 = false ;
bool V_62 = false ;
int V_80 = 0 ;
if ( ! V_83 ) {
F_12 ( V_56 -> V_70 , V_85 , 0x2 , 0x0 ) ;
V_64 = F_10 ( V_54 ) ;
F_17 ( V_64 , L_3 ) ;
F_14 ( V_64 ) ;
return 0 ;
}
V_56 -> V_83 = V_83 ;
F_12 ( V_56 -> V_70 , V_85 , 0x2 , 0x2 ) ;
F_9 ( V_56 , & V_61 , & V_62 ) ;
if ( V_61 == true )
V_80 |= V_81 ;
if ( V_62 == true )
V_80 |= V_82 ;
F_21 ( V_56 -> V_83 , V_80 ,
V_82 | V_81 ) ;
return 0 ;
}
static int F_23 ( struct V_86 * V_87 ,
struct V_86 * V_88 )
{
struct V_53 * V_54 = F_24 ( V_87 -> V_64 ) ;
struct V_55 * V_56 = F_7 ( V_54 ) ;
if ( V_56 -> V_89 == V_90 )
return 1 ;
else
return 0 ;
}
static int F_25 ( struct V_86 * V_91 ,
struct V_92 * V_93 , int V_94 )
{
struct V_53 * V_54 = F_24 ( V_91 -> V_64 ) ;
switch ( V_94 ) {
case V_95 :
F_8 ( V_54 ,
V_25 , V_96 ) ;
break;
case V_97 :
F_8 ( V_54 ,
V_25 , V_98 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_26 ( struct V_86 * V_91 ,
struct V_92 * V_93 , int V_94 )
{
struct V_53 * V_54 = F_24 ( V_91 -> V_64 ) ;
switch ( V_94 ) {
case V_95 :
F_8 ( V_54 , V_24 , 0x20 ) ;
break;
case V_97 :
F_8 ( V_54 , V_24 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_86 * V_91 ,
struct V_92 * V_93 , int V_94 )
{
struct V_53 * V_54 = F_24 ( V_91 -> V_64 ) ;
unsigned int V_99 ;
V_99 = ( V_91 -> V_3 >> 20 ) & 0xff ;
switch ( V_94 ) {
case V_95 :
F_28 ( V_54 ,
F_3 ( V_100 , V_99 , 0 ) ,
0x7080 , 0x7000 ) ;
if ( ! ( F_29 ( V_54 , V_101 ) & 0x200 ) ) {
F_30 ( L_5 ) ;
switch ( V_99 ) {
case V_50 :
F_28 ( V_54 ,
V_102 , 0x2 , 0x2 ) ;
F_31 ( 10 ) ;
F_28 ( V_54 ,
V_102 , 0x2 , 0x0 ) ;
break;
case V_51 :
F_28 ( V_54 ,
V_102 , 0x4 , 0x4 ) ;
F_31 ( 10 ) ;
F_28 ( V_54 ,
V_102 , 0x4 , 0x0 ) ;
break;
}
}
break;
case V_97 :
F_28 ( V_54 ,
F_3 ( V_100 , V_99 , 0 ) ,
0x7080 , 0x7080 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_32 ( struct V_86 * V_91 ,
struct V_92 * V_93 , int V_94 )
{
struct V_53 * V_54 = F_24 ( V_91 -> V_64 ) ;
switch ( V_94 ) {
case V_103 :
F_28 ( V_54 ,
V_104 , 0xc000 , 0x8000 ) ;
F_28 ( V_54 ,
V_105 , 0xc000 , 0x8000 ) ;
break;
case V_106 :
F_28 ( V_54 ,
V_104 , 0xc000 , 0x0000 ) ;
F_28 ( V_54 ,
V_105 , 0xc000 , 0x0000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_33 ( struct V_107 * V_108 ,
struct V_109 * V_110 ,
struct V_111 * V_112 )
{
struct V_53 * V_54 = V_112 -> V_54 ;
struct V_55 * V_56 = F_7 ( V_54 ) ;
unsigned int V_65 = 0 ;
int V_113 ;
switch ( F_34 ( V_110 ) ) {
case 44100 :
case 48000 :
break;
default:
F_35 ( V_54 -> V_2 , L_6 ,
F_34 ( V_110 ) ) ;
return - V_67 ;
}
switch ( V_56 -> V_114 ) {
case 12288000 :
case 24576000 :
if ( F_34 ( V_110 ) != 48000 ) {
F_35 ( V_54 -> V_2 , L_7 ,
F_34 ( V_110 ) , V_56 -> V_114 ) ;
return - V_67 ;
}
break;
case 11289600 :
case 22579200 :
if ( F_34 ( V_110 ) != 44100 ) {
F_35 ( V_54 -> V_2 , L_7 ,
F_34 ( V_110 ) , V_56 -> V_114 ) ;
return - V_67 ;
}
break;
}
if ( F_36 ( V_110 ) <= 16 ) {
V_65 |= ( F_36 ( V_110 ) - 1 ) ;
} else {
F_35 ( V_54 -> V_2 , L_8 ,
F_36 ( V_110 ) ) ;
return - V_67 ;
}
V_113 = 0 ;
switch ( F_37 ( V_110 ) ) {
case 16 :
V_113 = 0 ;
V_65 |= ( 0x1 << 4 ) ;
break;
case 32 :
V_113 = 2 ;
V_65 |= ( 0x4 << 4 ) ;
break;
case 20 :
V_113 = 1 ;
V_65 |= ( 0x2 << 4 ) ;
break;
case 24 :
V_113 = 2 ;
V_65 |= ( 0x3 << 4 ) ;
break;
case 8 :
V_113 = 3 ;
break;
default:
return - V_67 ;
}
F_28 ( V_54 ,
V_115 , 0x0018 , V_113 << 3 ) ;
F_38 ( V_54 -> V_2 , L_9 , V_65 ) ;
F_28 ( V_54 , V_43 , 0x407f , V_65 ) ;
F_28 ( V_54 , V_44 , 0x407f , V_65 ) ;
return 0 ;
}
static int F_39 ( struct V_111 * V_112 , unsigned int V_116 )
{
struct V_53 * V_54 = V_112 -> V_54 ;
switch ( V_116 & V_117 ) {
case V_118 :
F_28 ( V_54 ,
V_115 , 0x800 , 0x800 ) ;
break;
case V_119 :
F_28 ( V_54 ,
V_115 , 0x800 , 0x0 ) ;
break;
default:
return - V_67 ;
}
switch ( V_116 & V_120 ) {
case V_121 :
F_28 ( V_54 ,
V_115 , 0x300 , 0x0 ) ;
break;
case V_122 :
F_28 ( V_54 ,
V_115 , 0x300 , 0x1 << 8 ) ;
break;
case V_123 :
F_28 ( V_54 ,
V_115 , 0x300 , 0x2 << 8 ) ;
break;
case V_124 :
F_28 ( V_54 ,
V_115 , 0x300 , 0x3 << 8 ) ;
break;
default:
return - V_67 ;
}
F_28 ( V_54 , V_43 , 0x8000 , 0 ) ;
F_28 ( V_54 , V_44 , 0x8000 , 0 ) ;
return 0 ;
}
static int F_40 ( struct V_111 * V_112 ,
int V_89 , unsigned int V_125 , int V_126 )
{
struct V_53 * V_54 = V_112 -> V_54 ;
struct V_55 * V_56 = F_7 ( V_54 ) ;
F_38 ( V_54 -> V_2 , L_10 , V_127 , V_125 ) ;
if ( V_90 == V_89 ) {
F_28 ( V_54 ,
V_128 , 0x0100 , 0x0 ) ;
F_28 ( V_54 ,
V_129 , 0x20 , 0x20 ) ;
} else {
F_28 ( V_54 ,
V_128 , 0x0100 , 0x0100 ) ;
F_28 ( V_54 ,
V_129 , 0x20 , 0x0 ) ;
}
switch ( V_125 ) {
case 19200000 :
if ( V_90 == V_89 ) {
F_35 ( V_54 -> V_2 , L_11 ) ;
return - V_67 ;
}
F_28 ( V_54 ,
V_128 , 0x40 , 0x40 ) ;
break;
case 24000000 :
if ( V_90 == V_89 ) {
F_35 ( V_54 -> V_2 , L_11 ) ;
return - V_67 ;
}
F_28 ( V_54 ,
V_128 , 0x40 , 0x0 ) ;
break;
case 12288000 :
case 11289600 :
F_28 ( V_54 ,
V_128 , 0x8 , 0x0 ) ;
F_28 ( V_54 ,
V_130 , 0xfc1e , 0x0004 ) ;
break;
case 24576000 :
case 22579200 :
F_28 ( V_54 ,
V_128 , 0x8 , 0x8 ) ;
F_28 ( V_54 ,
V_130 , 0xfc1e , 0x5406 ) ;
break;
default:
F_35 ( V_54 -> V_2 , L_12 ) ;
return - V_67 ;
}
V_56 -> V_114 = V_125 ;
V_56 -> V_89 = V_89 ;
return 0 ;
}
static int F_41 ( struct V_111 * V_112 , unsigned int V_131 )
{
struct V_53 * V_54 = V_112 -> V_54 ;
F_38 ( V_54 -> V_2 , L_13 , V_127 , V_131 ) ;
if ( 50 == V_131 )
F_28 ( V_54 ,
V_115 , 0x1000 , 0x1000 ) ;
else
F_28 ( V_54 ,
V_115 , 0x1000 , 0x0 ) ;
return 0 ;
}
static int F_42 ( struct V_53 * V_54 ,
enum V_132 V_133 )
{
switch ( V_133 ) {
case V_134 :
if ( V_135 ==
F_43 ( V_54 ) ) {
F_8 ( V_54 ,
V_13 , V_136 ) ;
F_28 ( V_54 , 0x0d , 0x200 , 0x200 ) ;
F_28 ( V_54 , 0x52 , 0x80 , 0x0 ) ;
F_31 ( 20 ) ;
F_28 ( V_54 , 0x0d , 0x200 , 0x0 ) ;
F_28 ( V_54 , 0x52 , 0x80 , 0x80 ) ;
}
break;
case V_135 :
F_8 ( V_54 ,
V_13 , V_137 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_44 ( int V_138 , void * V_139 )
{
struct V_55 * V_56 = V_139 ;
bool V_61 = false ;
bool V_62 = false ;
int V_140 , V_80 = 0 ;
V_140 = F_9 ( V_56 , & V_61 , & V_62 ) ;
F_12 ( V_56 -> V_70 , V_85 , 0x1 , 0x1 ) ;
if ( V_140 == 0 ) {
if ( V_61 == true )
V_80 |= V_81 ;
if ( V_62 == true )
V_80 |= V_82 ;
F_21 ( V_56 -> V_83 , V_80 ,
V_82 | V_81 ) ;
F_45 ( & V_56 -> V_141 -> V_2 , 300 ) ;
}
return V_142 ;
}
static int F_46 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
V_56 -> V_54 = V_54 ;
if ( V_56 -> V_141 -> V_138 ) {
F_12 ( V_56 -> V_70 ,
V_85 , 0x2 , 0x2 ) ;
F_47 ( & V_56 -> V_79 ,
F_19 ) ;
F_48 ( & V_56 -> V_79 ,
F_49 ( 1250 ) ) ;
}
return 0 ;
}
static int F_50 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
F_51 ( & V_56 -> V_79 ) ;
return 0 ;
}
static int F_52 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
V_56 -> V_71 = - 1 ;
F_53 ( V_56 -> V_70 , true ) ;
F_54 ( V_56 -> V_70 ) ;
return 0 ;
}
static int F_55 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
F_53 ( V_56 -> V_70 , false ) ;
F_6 ( V_54 ) ;
F_56 ( V_56 -> V_70 ) ;
return 0 ;
}
static int F_57 ( struct V_143 * V_141 ,
const struct V_144 * V_145 )
{
struct V_146 * V_68 = F_58 ( & V_141 -> V_2 ) ;
struct V_55 * V_56 ;
struct V_1 * V_2 = & V_141 -> V_2 ;
const struct V_147 * V_148 ;
int V_57 , V_140 ;
V_56 = F_59 ( & V_141 -> V_2 , sizeof( * V_56 ) ,
V_149 ) ;
if ( NULL == V_56 )
return - V_150 ;
V_56 -> V_70 = F_60 ( & V_141 -> V_2 , NULL , V_141 , & V_151 ) ;
if ( F_61 ( V_56 -> V_70 ) ) {
V_140 = F_62 ( V_56 -> V_70 ) ;
F_35 ( & V_141 -> V_2 , L_14 ,
V_140 ) ;
return V_140 ;
}
F_11 ( V_56 -> V_70 ,
F_2 ( V_4 , V_5 ) , & V_140 ) ;
if ( V_140 != V_152 ) {
F_35 ( & V_141 -> V_2 ,
L_15 , V_140 ) ;
return - V_153 ;
}
V_56 -> V_59 = F_63 ( & V_141 -> V_2 , V_154 ,
sizeof( V_154 ) , V_149 ) ;
if ( ! V_56 -> V_59 )
return - V_150 ;
V_56 -> V_155 = V_58 ;
V_56 -> V_141 = V_141 ;
F_64 ( V_141 , V_56 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
F_15 ( V_56 -> V_70 , V_56 -> V_59 [ V_57 ] . V_3 ,
V_56 -> V_59 [ V_57 ] . V_60 ) ;
for ( V_57 = 0 ; V_57 < F_65 ( V_156 ) ; V_57 ++ )
F_15 ( V_56 -> V_70 , V_156 [ V_57 ] . V_3 ,
V_156 [ V_57 ] . V_60 ) ;
if ( V_68 )
V_56 -> V_68 = * V_68 ;
V_148 = F_66 ( V_2 -> V_157 -> V_158 , V_2 ) ;
if ( V_148 && V_148 -> V_159 ) {
V_56 -> V_68 = * (struct V_146 * )
V_148 -> V_159 ;
}
if ( F_67 ( V_160 ) ) {
V_56 -> V_68 . V_69 = true ;
V_56 -> V_68 . V_161 = false ;
}
F_12 ( V_56 -> V_70 , 0x04 , 0x80 , 0x80 ) ;
F_12 ( V_56 -> V_70 , 0x1b , 0x860 , 0x860 ) ;
F_12 ( V_56 -> V_70 , 0x08 , 0x20 , 0x20 ) ;
F_15 ( V_56 -> V_70 , V_13 , V_137 ) ;
for ( V_57 = 0 ; V_57 < V_162 ; V_57 ++ )
F_15 ( V_56 -> V_70 ,
F_5 ( V_163 [ V_57 ] ) ,
V_164 ) ;
if ( ! V_56 -> V_68 . V_69 ) {
F_15 ( V_56 -> V_70 , V_76 , 0x0000 ) ;
F_15 ( V_56 -> V_70 , V_165 , 0x0816 ) ;
F_12 ( V_56 -> V_70 ,
V_75 , 0xf000 , 0xb000 ) ;
} else {
F_12 ( V_56 -> V_70 ,
V_75 , 0xf000 , 0x5000 ) ;
}
F_31 ( 10 ) ;
if ( ! V_56 -> V_68 . V_161 )
F_15 ( V_56 -> V_70 , V_27 , 0x40 ) ;
else
F_15 ( V_56 -> V_70 , V_27 , 0 ) ;
F_31 ( 10 ) ;
F_15 ( V_56 -> V_70 , V_166 , 0x0000 ) ;
F_12 ( V_56 -> V_70 ,
V_167 , 0x0082 , 0x0082 ) ;
F_15 ( V_56 -> V_70 , V_168 , 0x81 ) ;
F_15 ( V_56 -> V_70 , V_169 , 0x82 ) ;
F_15 ( V_56 -> V_70 , V_170 , 0x84 ) ;
F_12 ( V_56 -> V_70 , V_171 , 0x2 , 0x2 ) ;
V_56 -> V_71 = - 1 ;
if ( V_56 -> V_141 -> V_138 ) {
V_140 = F_68 ( V_56 -> V_141 -> V_138 , NULL , F_44 ,
V_172 | V_173 , L_16 , V_56 ) ;
if ( V_140 != 0 ) {
F_35 ( & V_141 -> V_2 ,
L_17 , V_140 ) ;
return V_140 ;
}
}
V_140 = F_69 ( & V_141 -> V_2 , & V_174 ,
V_175 , F_65 ( V_175 ) ) ;
return V_140 ;
}
static int F_70 ( struct V_143 * V_141 )
{
struct V_55 * V_56 = F_71 ( V_141 ) ;
if ( V_141 -> V_138 )
F_72 ( V_141 -> V_138 , V_56 ) ;
F_73 ( & V_141 -> V_2 ) ;
return 0 ;
}
