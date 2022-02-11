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
F_15 ( V_56 -> V_70 , V_21 , 0x24 ) ;
F_16 ( 50 ) ;
F_12 ( V_56 -> V_70 ,
V_73 , 0xfcc0 , 0xd400 ) ;
F_16 ( 300 ) ;
F_11 ( V_56 -> V_70 , V_74 , & V_65 ) ;
if ( 0x0070 == ( V_65 & 0x0070 ) ) {
* V_62 = true ;
} else {
F_12 ( V_56 -> V_70 ,
V_73 , 0xfcc0 , 0xe400 ) ;
F_16 ( 300 ) ;
F_11 ( V_56 -> V_70 ,
V_74 , & V_65 ) ;
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
static void F_19 ( struct V_75 * V_76 )
{
struct V_55 * V_56 =
F_20 ( V_76 , struct V_55 , V_77 . V_76 ) ;
int V_78 = 0 ;
bool V_61 = false ;
bool V_62 = false ;
if ( F_9 ( V_56 , & V_61 , & V_62 ) < 0 )
return;
if ( V_61 == true )
V_78 |= V_79 ;
if ( V_62 == true )
V_78 |= V_80 ;
F_21 ( V_56 -> V_81 , V_78 ,
V_80 | V_79 ) ;
}
int F_22 ( struct V_53 * V_54 , struct V_82 * V_81 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
V_56 -> V_81 = V_81 ;
F_21 ( V_56 -> V_81 , 0 ,
V_80 | V_79 ) ;
return 0 ;
}
static int F_23 ( struct V_83 * V_84 ,
struct V_83 * V_85 )
{
struct V_53 * V_54 = F_24 ( V_84 -> V_64 ) ;
struct V_55 * V_56 = F_7 ( V_54 ) ;
if ( V_56 -> V_86 == V_87 )
return 1 ;
else
return 0 ;
}
static int F_25 ( struct V_83 * V_88 ,
struct V_89 * V_90 , int V_91 )
{
struct V_53 * V_54 = F_24 ( V_88 -> V_64 ) ;
switch ( V_91 ) {
case V_92 :
F_8 ( V_54 ,
V_25 , V_93 ) ;
break;
case V_94 :
F_8 ( V_54 ,
V_25 , V_95 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_26 ( struct V_83 * V_88 ,
struct V_89 * V_90 , int V_91 )
{
struct V_53 * V_54 = F_24 ( V_88 -> V_64 ) ;
switch ( V_91 ) {
case V_92 :
F_8 ( V_54 , V_24 , 0x20 ) ;
break;
case V_94 :
F_8 ( V_54 , V_24 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_83 * V_88 ,
struct V_89 * V_90 , int V_91 )
{
struct V_53 * V_54 = F_24 ( V_88 -> V_64 ) ;
unsigned int V_96 ;
V_96 = ( V_88 -> V_3 >> 20 ) & 0xff ;
switch ( V_91 ) {
case V_92 :
F_28 ( V_54 ,
F_3 ( V_97 , V_96 , 0 ) ,
0x7080 , 0x7000 ) ;
break;
case V_94 :
F_28 ( V_54 ,
F_3 ( V_97 , V_96 , 0 ) ,
0x7080 , 0x7080 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_29 ( struct V_83 * V_88 ,
struct V_89 * V_90 , int V_91 )
{
struct V_53 * V_54 = F_24 ( V_88 -> V_64 ) ;
switch ( V_91 ) {
case V_98 :
F_28 ( V_54 ,
V_99 , 0xc000 , 0x8000 ) ;
F_28 ( V_54 ,
V_100 , 0xc000 , 0x8000 ) ;
break;
case V_101 :
F_28 ( V_54 ,
V_99 , 0xc000 , 0x0000 ) ;
F_28 ( V_54 ,
V_100 , 0xc000 , 0x0000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_30 ( struct V_83 * V_88 ,
struct V_89 * V_90 , int V_91 )
{
struct V_53 * V_54 = F_24 ( V_88 -> V_64 ) ;
switch ( V_91 ) {
case V_98 :
F_28 ( V_54 ,
V_73 , 0x0400 , 0x0000 ) ;
F_31 ( 50 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_32 ( struct V_102 * V_103 ,
struct V_104 * V_105 ,
struct V_106 * V_107 )
{
struct V_53 * V_54 = V_107 -> V_54 ;
struct V_55 * V_56 = F_7 ( V_54 ) ;
unsigned int V_65 = 0 ;
int V_108 ;
switch ( F_33 ( V_105 ) ) {
case 44100 :
case 48000 :
break;
default:
F_34 ( V_54 -> V_2 , L_5 ,
F_33 ( V_105 ) ) ;
return - V_67 ;
}
switch ( V_56 -> V_109 ) {
case 12288000 :
case 24576000 :
if ( F_33 ( V_105 ) != 48000 ) {
F_34 ( V_54 -> V_2 , L_6 ,
F_33 ( V_105 ) , V_56 -> V_109 ) ;
return - V_67 ;
}
break;
case 11289600 :
case 22579200 :
if ( F_33 ( V_105 ) != 44100 ) {
F_34 ( V_54 -> V_2 , L_6 ,
F_33 ( V_105 ) , V_56 -> V_109 ) ;
return - V_67 ;
}
break;
}
if ( F_35 ( V_105 ) <= 16 ) {
V_65 |= ( F_35 ( V_105 ) - 1 ) ;
} else {
F_34 ( V_54 -> V_2 , L_7 ,
F_35 ( V_105 ) ) ;
return - V_67 ;
}
V_108 = 0 ;
switch ( F_36 ( V_105 ) ) {
case 16 :
V_108 = 0 ;
V_65 |= ( 0x1 << 4 ) ;
break;
case 32 :
V_108 = 2 ;
V_65 |= ( 0x4 << 4 ) ;
break;
case 20 :
V_108 = 1 ;
V_65 |= ( 0x2 << 4 ) ;
break;
case 24 :
V_108 = 2 ;
V_65 |= ( 0x3 << 4 ) ;
break;
case 8 :
V_108 = 3 ;
break;
default:
return - V_67 ;
}
F_28 ( V_54 ,
V_110 , 0x0018 , V_108 << 3 ) ;
F_37 ( V_54 -> V_2 , L_8 , V_65 ) ;
F_28 ( V_54 , V_43 , 0x407f , V_65 ) ;
F_28 ( V_54 , V_44 , 0x407f , V_65 ) ;
return 0 ;
}
static int F_38 ( struct V_106 * V_107 , unsigned int V_111 )
{
struct V_53 * V_54 = V_107 -> V_54 ;
switch ( V_111 & V_112 ) {
case V_113 :
F_28 ( V_54 ,
V_110 , 0x800 , 0x800 ) ;
break;
case V_114 :
F_28 ( V_54 ,
V_110 , 0x800 , 0x0 ) ;
break;
default:
return - V_67 ;
}
switch ( V_111 & V_115 ) {
case V_116 :
F_28 ( V_54 ,
V_110 , 0x300 , 0x0 ) ;
break;
case V_117 :
F_28 ( V_54 ,
V_110 , 0x300 , 0x1 << 8 ) ;
break;
case V_118 :
F_28 ( V_54 ,
V_110 , 0x300 , 0x2 << 8 ) ;
break;
case V_119 :
F_28 ( V_54 ,
V_110 , 0x300 , 0x3 << 8 ) ;
break;
default:
return - V_67 ;
}
F_28 ( V_54 , V_43 , 0x8000 , 0 ) ;
F_28 ( V_54 , V_44 , 0x8000 , 0 ) ;
return 0 ;
}
static int F_39 ( struct V_106 * V_107 ,
int V_86 , unsigned int V_120 , int V_121 )
{
struct V_53 * V_54 = V_107 -> V_54 ;
struct V_55 * V_56 = F_7 ( V_54 ) ;
F_37 ( V_54 -> V_2 , L_9 , V_122 , V_120 ) ;
if ( V_87 == V_86 ) {
F_28 ( V_54 ,
V_123 , 0x0100 , 0x0 ) ;
F_28 ( V_54 ,
V_124 , 0x20 , 0x20 ) ;
} else {
F_28 ( V_54 ,
V_123 , 0x0100 , 0x0100 ) ;
F_28 ( V_54 ,
V_124 , 0x20 , 0x0 ) ;
}
switch ( V_120 ) {
case 19200000 :
if ( V_87 == V_86 ) {
F_34 ( V_54 -> V_2 , L_10 ) ;
return - V_67 ;
}
F_28 ( V_54 ,
V_123 , 0x40 , 0x40 ) ;
break;
case 24000000 :
if ( V_87 == V_86 ) {
F_34 ( V_54 -> V_2 , L_10 ) ;
return - V_67 ;
}
F_28 ( V_54 ,
V_123 , 0x40 , 0x0 ) ;
break;
case 12288000 :
case 11289600 :
F_28 ( V_54 ,
V_123 , 0x8 , 0x0 ) ;
F_28 ( V_54 ,
V_125 , 0xfc1e , 0x0004 ) ;
break;
case 24576000 :
case 22579200 :
F_28 ( V_54 ,
V_123 , 0x8 , 0x8 ) ;
F_28 ( V_54 ,
V_125 , 0xfc1e , 0x5406 ) ;
break;
default:
F_34 ( V_54 -> V_2 , L_11 ) ;
return - V_67 ;
}
V_56 -> V_109 = V_120 ;
V_56 -> V_86 = V_86 ;
return 0 ;
}
static int F_40 ( struct V_106 * V_107 , unsigned int V_126 )
{
struct V_53 * V_54 = V_107 -> V_54 ;
F_37 ( V_54 -> V_2 , L_12 , V_122 , V_126 ) ;
if ( 50 == V_126 )
F_28 ( V_54 ,
V_110 , 0x1000 , 0x1000 ) ;
else
F_28 ( V_54 ,
V_110 , 0x1000 , 0x0 ) ;
return 0 ;
}
static int F_41 ( struct V_53 * V_54 ,
enum V_127 V_128 )
{
switch ( V_128 ) {
case V_129 :
if ( V_130 ==
F_42 ( V_54 ) ) {
F_8 ( V_54 ,
V_13 , V_131 ) ;
F_28 ( V_54 , 0x0d , 0x200 , 0x200 ) ;
F_28 ( V_54 , 0x52 , 0x80 , 0x0 ) ;
F_31 ( 20 ) ;
F_28 ( V_54 , 0x0d , 0x200 , 0x0 ) ;
F_28 ( V_54 , 0x52 , 0x80 , 0x80 ) ;
}
break;
case V_132 :
F_31 ( 30 ) ;
F_28 ( V_54 ,
V_73 , 0x0400 , 0x0400 ) ;
break;
case V_130 :
F_8 ( V_54 ,
V_13 , V_133 ) ;
F_28 ( V_54 ,
V_73 , 0x0400 , 0x0000 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_43 ( int V_134 , void * V_135 )
{
struct V_55 * V_56 = V_135 ;
bool V_61 = false ;
bool V_62 = false ;
int V_136 , V_78 = 0 ;
V_136 = F_9 ( V_56 , & V_61 , & V_62 ) ;
F_12 ( V_56 -> V_70 , V_137 , 0x1 , 0x1 ) ;
if ( V_136 == 0 ) {
if ( V_61 == true )
V_78 |= V_79 ;
if ( V_62 == true )
V_78 |= V_80 ;
F_21 ( V_56 -> V_81 , V_78 ,
V_80 | V_79 ) ;
F_44 ( & V_56 -> V_138 -> V_2 , 300 ) ;
}
return V_139 ;
}
static int F_45 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
V_56 -> V_54 = V_54 ;
if ( V_56 -> V_138 -> V_134 ) {
F_12 ( V_56 -> V_70 ,
V_137 , 0x2 , 0x2 ) ;
F_46 ( & V_56 -> V_77 ,
F_19 ) ;
F_47 ( & V_56 -> V_77 ,
F_48 ( 1250 ) ) ;
}
return 0 ;
}
static int F_49 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
F_50 ( & V_56 -> V_77 ) ;
return 0 ;
}
static int F_51 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
V_56 -> V_71 = - 1 ;
F_52 ( V_56 -> V_70 , true ) ;
F_53 ( V_56 -> V_70 ) ;
return 0 ;
}
static int F_54 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = F_7 ( V_54 ) ;
F_52 ( V_56 -> V_70 , false ) ;
F_6 ( V_54 ) ;
F_55 ( V_56 -> V_70 ) ;
return 0 ;
}
static int F_56 ( struct V_140 * V_138 ,
const struct V_141 * V_142 )
{
struct V_143 * V_68 = F_57 ( & V_138 -> V_2 ) ;
struct V_55 * V_56 ;
struct V_1 * V_2 = & V_138 -> V_2 ;
const struct V_144 * V_145 ;
int V_57 , V_136 ;
V_56 = F_58 ( & V_138 -> V_2 , sizeof( * V_56 ) ,
V_146 ) ;
if ( NULL == V_56 )
return - V_147 ;
V_56 -> V_70 = F_59 ( & V_138 -> V_2 , NULL , V_138 , & V_148 ) ;
if ( F_60 ( V_56 -> V_70 ) ) {
V_136 = F_61 ( V_56 -> V_70 ) ;
F_34 ( & V_138 -> V_2 , L_13 ,
V_136 ) ;
return V_136 ;
}
F_11 ( V_56 -> V_70 ,
F_2 ( V_4 , V_5 ) , & V_136 ) ;
if ( V_136 != V_149 ) {
F_34 ( & V_138 -> V_2 ,
L_14 , V_136 ) ;
return - V_150 ;
}
V_56 -> V_59 = F_62 ( & V_138 -> V_2 , V_151 ,
sizeof( V_151 ) , V_146 ) ;
if ( ! V_56 -> V_59 )
return - V_147 ;
V_56 -> V_152 = V_58 ;
V_56 -> V_138 = V_138 ;
F_63 ( V_138 , V_56 ) ;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ )
F_15 ( V_56 -> V_70 , V_56 -> V_59 [ V_57 ] . V_3 ,
V_56 -> V_59 [ V_57 ] . V_60 ) ;
for ( V_57 = 0 ; V_57 < F_64 ( V_153 ) ; V_57 ++ )
F_15 ( V_56 -> V_70 , V_153 [ V_57 ] . V_3 ,
V_153 [ V_57 ] . V_60 ) ;
if ( V_68 )
V_56 -> V_68 = * V_68 ;
V_145 = F_65 ( V_2 -> V_154 -> V_155 , V_2 ) ;
if ( V_145 ) {
V_56 -> V_68 = * (struct V_143 * )
V_145 -> V_156 ;
}
F_12 ( V_56 -> V_70 , 0x04 , 0x80 , 0x80 ) ;
F_12 ( V_56 -> V_70 , 0x1b , 0x860 , 0x860 ) ;
F_12 ( V_56 -> V_70 , 0x08 , 0x20 , 0x20 ) ;
F_15 ( V_56 -> V_70 , V_13 , V_133 ) ;
for ( V_57 = 0 ; V_57 < V_157 ; V_57 ++ )
F_15 ( V_56 -> V_70 ,
F_5 ( V_158 [ V_57 ] ) ,
V_159 ) ;
if ( ! V_56 -> V_68 . V_69 ) {
F_15 ( V_56 -> V_70 , V_74 , 0x0000 ) ;
F_15 ( V_56 -> V_70 , V_160 , 0x0816 ) ;
F_12 ( V_56 -> V_70 ,
V_73 , 0xf000 , 0xb000 ) ;
} else {
F_12 ( V_56 -> V_70 ,
V_73 , 0xf000 , 0x5000 ) ;
}
F_31 ( 10 ) ;
if ( ! V_56 -> V_68 . V_161 )
F_15 ( V_56 -> V_70 , V_27 , 0x40 ) ;
else
F_15 ( V_56 -> V_70 , V_27 , 0 ) ;
F_31 ( 10 ) ;
F_15 ( V_56 -> V_70 , V_162 , 0x0000 ) ;
F_12 ( V_56 -> V_70 ,
V_163 , 0x0082 , 0x0082 ) ;
F_12 ( V_56 -> V_70 , V_137 , 0x2 , 0x2 ) ;
V_56 -> V_71 = - 1 ;
if ( V_56 -> V_138 -> V_134 ) {
V_136 = F_66 ( V_56 -> V_138 -> V_134 , NULL , F_43 ,
V_164 | V_165 , L_15 , V_56 ) ;
if ( V_136 != 0 ) {
F_34 ( & V_138 -> V_2 ,
L_16 , V_136 ) ;
return V_136 ;
}
}
V_136 = F_67 ( & V_138 -> V_2 , & V_166 ,
V_167 , F_64 ( V_167 ) ) ;
return V_136 ;
}
static int F_68 ( struct V_140 * V_138 )
{
struct V_55 * V_56 = F_69 ( V_138 ) ;
if ( V_138 -> V_134 )
F_70 ( V_138 -> V_134 , V_56 ) ;
F_71 ( & V_138 -> V_2 ) ;
return 0 ;
}
