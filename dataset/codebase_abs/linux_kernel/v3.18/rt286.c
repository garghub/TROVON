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
int V_58 ;
* V_77 = false ;
* V_78 = false ;
if ( V_55 -> V_80 . V_81 ) {
F_17 ( V_55 -> V_82 , V_6 , & V_68 ) ;
* V_77 = V_68 & 0x80000000 ;
if ( * V_77 ) {
F_18 ( V_55 -> V_82 ,
V_83 , 0x1001 , 0x0 ) ;
F_18 ( V_55 -> V_82 ,
V_84 , 0x4 , 0x4 ) ;
F_19 ( V_55 -> V_82 , V_17 , 0x24 ) ;
F_17 ( V_55 -> V_82 , V_85 , & V_79 ) ;
F_20 ( 200 ) ;
V_58 = 40 ;
while ( ( ( V_79 & 0x0800 ) == 0 ) && ( V_58 > 0 ) ) {
F_17 ( V_55 -> V_82 ,
V_85 , & V_79 ) ;
V_58 -- ;
F_20 ( 20 ) ;
}
if ( 0x0400 == ( V_79 & 0x0700 ) ) {
* V_78 = false ;
F_19 ( V_55 -> V_82 ,
V_17 , 0x20 ) ;
F_18 ( V_55 -> V_82 ,
V_83 , 0x1001 , 0x1001 ) ;
F_18 ( V_55 -> V_82 ,
V_86 , 0xc000 , 0x0000 ) ;
F_18 ( V_55 -> V_82 ,
V_87 , 0x0030 , 0x0000 ) ;
F_18 ( V_55 -> V_82 ,
V_88 , 0xc000 , 0x0000 ) ;
} else if ( ( 0x0200 == ( V_79 & 0x0700 ) ) ||
( 0x0100 == ( V_79 & 0x0700 ) ) ) {
* V_78 = true ;
F_18 ( V_55 -> V_82 ,
V_86 , 0xc000 , 0x8000 ) ;
F_18 ( V_55 -> V_82 ,
V_87 , 0x0030 , 0x0020 ) ;
F_18 ( V_55 -> V_82 ,
V_88 , 0xc000 , 0x8000 ) ;
} else {
* V_78 = false ;
}
F_18 ( V_55 -> V_82 ,
V_89 ,
0x0060 , 0x0000 ) ;
} else {
F_18 ( V_55 -> V_82 ,
V_89 ,
0x0060 , 0x0020 ) ;
F_18 ( V_55 -> V_82 ,
V_86 ,
0xc000 , 0x8000 ) ;
F_18 ( V_55 -> V_82 ,
V_87 ,
0x0030 , 0x0020 ) ;
F_18 ( V_55 -> V_82 ,
V_88 ,
0xc000 , 0x8000 ) ;
* V_78 = false ;
}
} else {
F_17 ( V_55 -> V_82 , V_6 , & V_68 ) ;
* V_77 = V_68 & 0x80000000 ;
F_17 ( V_55 -> V_82 , V_7 , & V_68 ) ;
* V_78 = V_68 & 0x80000000 ;
}
return 0 ;
}
static void F_21 ( struct V_90 * V_91 )
{
struct V_54 * V_55 =
F_22 ( V_91 , struct V_54 , V_92 . V_91 ) ;
int V_93 = 0 ;
bool V_77 = false ;
bool V_78 = false ;
F_16 ( V_55 , & V_77 , & V_78 ) ;
if ( V_77 == true )
V_93 |= V_94 ;
if ( V_78 == true )
V_93 |= V_95 ;
F_23 ( V_55 -> V_96 , V_93 ,
V_95 | V_94 ) ;
}
int F_24 ( struct V_75 * V_76 , struct V_97 * V_96 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
V_55 -> V_96 = V_96 ;
F_23 ( V_55 -> V_96 , 0 ,
V_95 | V_94 ) ;
return 0 ;
}
static int F_25 ( struct V_98 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_75 * V_76 = V_99 -> V_76 ;
switch ( V_102 ) {
case V_103 :
F_15 ( V_76 ,
V_21 , V_104 ) ;
break;
case V_105 :
F_15 ( V_76 ,
V_21 , V_106 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_26 ( struct V_98 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_75 * V_76 = V_99 -> V_76 ;
switch ( V_102 ) {
case V_103 :
F_15 ( V_76 , V_20 , 0x20 ) ;
break;
case V_105 :
F_15 ( V_76 , V_20 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_98 * V_99 ,
struct V_100 * V_101 , int V_102 )
{
struct V_75 * V_76 = V_99 -> V_76 ;
unsigned int V_107 ;
V_107 = ( V_99 -> V_3 >> 20 ) & 0xff ;
switch ( V_102 ) {
case V_103 :
F_28 ( V_76 ,
F_29 ( V_108 , V_107 , 0 ) ,
0x7080 , 0x7000 ) ;
break;
case V_105 :
F_28 ( V_76 ,
F_29 ( V_108 , V_107 , 0 ) ,
0x7080 , 0x7080 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_30 ( struct V_109 * V_110 ,
struct V_111 * V_112 ,
struct V_113 * V_114 )
{
struct V_75 * V_76 = V_114 -> V_76 ;
struct V_54 * V_55 = F_14 ( V_76 ) ;
unsigned int V_79 = 0 ;
int V_115 ;
switch ( F_31 ( V_112 ) ) {
case 44100 :
V_79 |= 0x4000 ;
break;
case 48000 :
break;
default:
F_32 ( V_76 -> V_2 , L_2 ,
F_31 ( V_112 ) ) ;
return - V_116 ;
}
switch ( V_55 -> V_117 ) {
case 12288000 :
case 24576000 :
if ( F_31 ( V_112 ) != 48000 ) {
F_32 ( V_76 -> V_2 , L_3 ,
F_31 ( V_112 ) , V_55 -> V_117 ) ;
return - V_116 ;
}
break;
case 11289600 :
case 22579200 :
if ( F_31 ( V_112 ) != 44100 ) {
F_32 ( V_76 -> V_2 , L_3 ,
F_31 ( V_112 ) , V_55 -> V_117 ) ;
return - V_116 ;
}
break;
}
if ( F_33 ( V_112 ) <= 16 ) {
V_79 |= ( F_33 ( V_112 ) - 1 ) ;
} else {
F_32 ( V_76 -> V_2 , L_4 ,
F_33 ( V_112 ) ) ;
return - V_116 ;
}
V_115 = 0 ;
switch ( F_34 ( V_112 ) ) {
case 16 :
V_115 = 0 ;
V_79 |= ( 0x1 << 4 ) ;
break;
case 32 :
V_115 = 2 ;
V_79 |= ( 0x4 << 4 ) ;
break;
case 20 :
V_115 = 1 ;
V_79 |= ( 0x2 << 4 ) ;
break;
case 24 :
V_115 = 2 ;
V_79 |= ( 0x3 << 4 ) ;
break;
case 8 :
V_115 = 3 ;
break;
default:
return - V_116 ;
}
F_28 ( V_76 ,
V_118 , 0x0018 , V_115 << 3 ) ;
F_35 ( V_76 -> V_2 , L_5 , V_79 ) ;
if ( V_110 -> V_119 == V_120 )
F_28 ( V_76 , V_39 , 0x407f , V_79 ) ;
else
F_28 ( V_76 , V_40 , 0x407f , V_79 ) ;
return 0 ;
}
static int F_36 ( struct V_113 * V_114 , unsigned int V_121 )
{
struct V_75 * V_76 = V_114 -> V_76 ;
switch ( V_121 & V_122 ) {
case V_123 :
F_28 ( V_76 ,
V_118 , 0x800 , 0x800 ) ;
break;
case V_124 :
F_28 ( V_76 ,
V_118 , 0x800 , 0x0 ) ;
break;
default:
return - V_116 ;
}
switch ( V_121 & V_125 ) {
case V_126 :
F_28 ( V_76 ,
V_118 , 0x300 , 0x0 ) ;
break;
case V_127 :
F_28 ( V_76 ,
V_118 , 0x300 , 0x1 << 8 ) ;
break;
case V_128 :
F_28 ( V_76 ,
V_118 , 0x300 , 0x2 << 8 ) ;
break;
case V_129 :
F_28 ( V_76 ,
V_118 , 0x300 , 0x3 << 8 ) ;
break;
default:
return - V_116 ;
}
F_28 ( V_76 , V_39 , 0x8000 , 0 ) ;
F_28 ( V_76 , V_40 , 0x8000 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_113 * V_114 ,
int V_130 , unsigned int V_131 , int V_132 )
{
struct V_75 * V_76 = V_114 -> V_76 ;
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_35 ( V_76 -> V_2 , L_6 , V_133 , V_131 ) ;
if ( V_134 == V_130 ) {
F_28 ( V_76 ,
V_135 , 0x0100 , 0x0 ) ;
F_28 ( V_76 ,
V_136 , 0x20 , 0x20 ) ;
} else {
F_28 ( V_76 ,
V_135 , 0x0100 , 0x0100 ) ;
F_28 ( V_76 ,
V_137 , 0x4 , 0x4 ) ;
F_28 ( V_76 ,
V_136 , 0x20 , 0x0 ) ;
}
switch ( V_131 ) {
case 19200000 :
if ( V_134 == V_130 ) {
F_32 ( V_76 -> V_2 , L_7 ) ;
return - V_116 ;
}
F_28 ( V_76 ,
V_135 , 0x40 , 0x40 ) ;
break;
case 24000000 :
if ( V_134 == V_130 ) {
F_32 ( V_76 -> V_2 , L_7 ) ;
return - V_116 ;
}
F_28 ( V_76 ,
V_135 , 0x40 , 0x0 ) ;
break;
case 12288000 :
case 11289600 :
F_28 ( V_76 ,
V_135 , 0x8 , 0x0 ) ;
F_28 ( V_76 ,
V_138 , 0xfc1e , 0x0004 ) ;
break;
case 24576000 :
case 22579200 :
F_28 ( V_76 ,
V_135 , 0x8 , 0x8 ) ;
F_28 ( V_76 ,
V_138 , 0xfc1e , 0x5406 ) ;
break;
default:
F_32 ( V_76 -> V_2 , L_8 ) ;
return - V_116 ;
}
V_55 -> V_117 = V_131 ;
return 0 ;
}
static int F_38 ( struct V_113 * V_114 , unsigned int V_139 )
{
struct V_75 * V_76 = V_114 -> V_76 ;
F_35 ( V_76 -> V_2 , L_9 , V_133 , V_139 ) ;
if ( 50 == V_139 )
F_28 ( V_76 ,
V_118 , 0x1000 , 0x1000 ) ;
else
F_28 ( V_76 ,
V_118 , 0x1000 , 0x0 ) ;
return 0 ;
}
static int F_39 ( struct V_75 * V_76 ,
enum V_140 V_141 )
{
switch ( V_141 ) {
case V_142 :
if ( V_143 == V_76 -> V_144 . V_145 ) {
F_15 ( V_76 ,
V_9 , V_146 ) ;
F_28 ( V_76 ,
V_147 , 0x200 , 0x200 ) ;
}
break;
case V_148 :
F_40 ( 10 ) ;
break;
case V_143 :
F_15 ( V_76 ,
V_9 , V_149 ) ;
F_28 ( V_76 ,
V_147 , 0x200 , 0x0 ) ;
break;
default:
break;
}
V_76 -> V_144 . V_145 = V_141 ;
return 0 ;
}
static T_3 F_41 ( int V_150 , void * V_56 )
{
struct V_54 * V_55 = V_56 ;
bool V_77 = false ;
bool V_78 = false ;
int V_93 = 0 ;
F_16 ( V_55 , & V_77 , & V_78 ) ;
F_18 ( V_55 -> V_82 , V_151 , 0x1 , 0x1 ) ;
if ( V_77 == true )
V_93 |= V_94 ;
if ( V_78 == true )
V_93 |= V_95 ;
F_23 ( V_55 -> V_96 , V_93 ,
V_95 | V_94 ) ;
F_42 ( & V_55 -> V_152 -> V_2 , 300 ) ;
return V_153 ;
}
static int F_43 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
V_76 -> V_144 . V_145 = V_154 ;
if ( V_55 -> V_152 -> V_150 ) {
F_18 ( V_55 -> V_82 ,
V_151 , 0x2 , 0x2 ) ;
F_44 ( & V_55 -> V_92 ,
F_21 ) ;
F_45 ( & V_55 -> V_92 ,
F_46 ( 1250 ) ) ;
}
return 0 ;
}
static int F_47 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_48 ( & V_55 -> V_92 ) ;
return 0 ;
}
static int F_49 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_50 ( V_55 -> V_82 , true ) ;
F_51 ( V_55 -> V_82 ) ;
return 0 ;
}
static int F_52 ( struct V_75 * V_76 )
{
struct V_54 * V_55 = F_14 ( V_76 ) ;
F_50 ( V_55 -> V_82 , false ) ;
F_13 ( V_76 ) ;
F_53 ( V_55 -> V_82 ) ;
return 0 ;
}
static int F_54 ( struct V_52 * V_152 ,
const struct V_155 * V_156 )
{
struct V_157 * V_80 = F_55 ( & V_152 -> V_2 ) ;
struct V_54 * V_55 ;
int V_58 , V_57 ;
V_55 = F_56 ( & V_152 -> V_2 , sizeof( * V_55 ) ,
V_158 ) ;
if ( NULL == V_55 )
return - V_159 ;
V_55 -> V_82 = F_57 ( & V_152 -> V_2 , NULL , V_152 , & V_160 ) ;
if ( F_58 ( V_55 -> V_82 ) ) {
V_57 = F_59 ( V_55 -> V_82 ) ;
F_32 ( & V_152 -> V_2 , L_10 ,
V_57 ) ;
return V_57 ;
}
F_17 ( V_55 -> V_82 ,
F_2 ( V_4 , V_5 ) , & V_57 ) ;
if ( V_57 != V_161 ) {
F_32 ( & V_152 -> V_2 ,
L_11 , V_57 ) ;
return - V_162 ;
}
V_55 -> V_60 = V_163 ;
V_55 -> V_152 = V_152 ;
F_60 ( V_152 , V_55 ) ;
if ( V_80 )
V_55 -> V_80 = * V_80 ;
F_19 ( V_55 -> V_82 , V_9 , V_149 ) ;
for ( V_58 = 0 ; V_58 < V_164 ; V_58 ++ )
F_19 ( V_55 -> V_82 ,
F_4 ( V_165 [ V_58 ] ) ,
V_166 ) ;
if ( ! V_55 -> V_80 . V_81 ) {
F_19 ( V_55 -> V_82 , V_85 , 0x0000 ) ;
F_19 ( V_55 -> V_82 , V_167 , 0x0816 ) ;
F_19 ( V_55 -> V_82 , V_89 , 0x0000 ) ;
F_18 ( V_55 -> V_82 ,
V_87 , 0xf000 , 0xb000 ) ;
} else {
F_18 ( V_55 -> V_82 ,
V_87 , 0xf000 , 0x5000 ) ;
}
F_40 ( 10 ) ;
if ( ! V_55 -> V_80 . V_168 )
F_19 ( V_55 -> V_82 , V_23 , 0x4000 ) ;
else
F_19 ( V_55 -> V_82 , V_23 , 0 ) ;
F_40 ( 10 ) ;
F_18 ( V_55 -> V_82 , V_84 , 0x8 , 0x0 ) ;
F_18 ( V_55 -> V_82 , V_169 , 0x403a , 0x401a ) ;
F_18 ( V_55 -> V_82 , V_170 , 0xf777 , 0x4737 ) ;
F_18 ( V_55 -> V_82 , V_171 , 0x00ff , 0x003f ) ;
if ( V_55 -> V_152 -> V_150 ) {
V_57 = F_61 ( V_55 -> V_152 -> V_150 , NULL , F_41 ,
V_172 | V_173 , L_12 , V_55 ) ;
if ( V_57 != 0 ) {
F_32 ( & V_152 -> V_2 ,
L_13 , V_57 ) ;
return V_57 ;
}
}
V_57 = F_62 ( & V_152 -> V_2 , & V_174 ,
V_175 , F_63 ( V_175 ) ) ;
return V_57 ;
}
static int F_64 ( struct V_52 * V_152 )
{
struct V_54 * V_55 = F_6 ( V_152 ) ;
if ( V_152 -> V_150 )
F_65 ( V_152 -> V_150 , V_55 ) ;
F_66 ( & V_152 -> V_2 ) ;
return 0 ;
}
