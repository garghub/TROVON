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
static void F_5 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_6 ( V_51 ) ;
int V_54 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
F_7 ( V_51 , V_53 -> V_56 [ V_54 ] . V_3 ,
V_53 -> V_56 [ V_54 ] . V_57 ) ;
}
}
static int F_8 ( struct V_52 * V_53 , bool * V_58 , bool * V_59 )
{
struct V_60 * V_61 ;
unsigned int V_62 , V_63 ;
* V_58 = false ;
* V_59 = false ;
if ( ! V_53 -> V_51 )
return - V_64 ;
V_61 = F_9 ( V_53 -> V_51 ) ;
if ( V_53 -> V_65 . V_66 ) {
F_10 ( V_53 -> V_67 , V_6 , & V_63 ) ;
* V_58 = V_63 & 0x80000000 ;
if ( * V_58 ) {
F_11 ( V_53 -> V_67 ,
V_68 , 0x200 , 0x200 ) ;
F_12 ( V_61 , L_1 ) ;
F_12 ( V_61 , L_2 ) ;
F_12 ( V_61 , L_3 ) ;
F_13 ( V_61 ) ;
F_14 ( V_53 -> V_67 , V_17 , 0x24 ) ;
F_15 ( 50 ) ;
F_11 ( V_53 -> V_67 ,
V_69 , 0xfcc0 , 0xd400 ) ;
F_15 ( 300 ) ;
F_10 ( V_53 -> V_67 , V_70 , & V_62 ) ;
if ( 0x0070 == ( V_62 & 0x0070 ) ) {
* V_59 = true ;
} else {
F_11 ( V_53 -> V_67 ,
V_69 , 0xfcc0 , 0xe400 ) ;
F_15 ( 300 ) ;
F_10 ( V_53 -> V_67 ,
V_70 , & V_62 ) ;
if ( 0x0070 == ( V_62 & 0x0070 ) )
* V_59 = true ;
else
* V_59 = false ;
}
F_11 ( V_53 -> V_67 ,
V_68 , 0x200 , 0x0 ) ;
} else {
* V_59 = false ;
F_14 ( V_53 -> V_67 , V_17 , 0x20 ) ;
F_11 ( V_53 -> V_67 ,
V_69 , 0x0400 , 0x0000 ) ;
}
} else {
F_10 ( V_53 -> V_67 , V_6 , & V_63 ) ;
* V_58 = V_63 & 0x80000000 ;
F_10 ( V_53 -> V_67 , V_7 , & V_63 ) ;
* V_59 = V_63 & 0x80000000 ;
}
F_16 ( V_61 , L_1 ) ;
F_16 ( V_61 , L_2 ) ;
if ( ! * V_58 )
F_16 ( V_61 , L_3 ) ;
F_13 ( V_61 ) ;
return 0 ;
}
static void F_17 ( struct V_71 * V_72 )
{
struct V_52 * V_53 =
F_18 ( V_72 , struct V_52 , V_73 . V_72 ) ;
int V_74 = 0 ;
bool V_58 = false ;
bool V_59 = false ;
F_8 ( V_53 , & V_58 , & V_59 ) ;
if ( V_58 == true )
V_74 |= V_75 ;
if ( V_59 == true )
V_74 |= V_76 ;
F_19 ( V_53 -> V_77 , V_74 ,
V_76 | V_75 ) ;
}
int F_20 ( struct V_50 * V_51 , struct V_78 * V_77 )
{
struct V_60 * V_61 = F_9 ( V_51 ) ;
struct V_52 * V_53 = F_6 ( V_51 ) ;
V_53 -> V_77 = V_77 ;
if ( V_77 ) {
if ( V_53 -> V_77 -> V_74 & V_75 )
F_12 ( V_61 , L_3 ) ;
F_11 ( V_53 -> V_67 , V_79 , 0x2 , 0x2 ) ;
F_19 ( V_53 -> V_77 , V_53 -> V_77 -> V_74 ,
V_76 | V_75 ) ;
} else {
F_11 ( V_53 -> V_67 , V_79 , 0x2 , 0x0 ) ;
F_16 ( V_61 , L_3 ) ;
}
F_13 ( V_61 ) ;
return 0 ;
}
static int F_21 ( struct V_80 * V_81 ,
struct V_80 * V_82 )
{
struct V_50 * V_51 = F_22 ( V_81 -> V_61 ) ;
struct V_52 * V_53 = F_6 ( V_51 ) ;
if ( V_53 -> V_83 == V_84 )
return 1 ;
else
return 0 ;
}
static int F_23 ( struct V_80 * V_85 ,
struct V_86 * V_87 , int V_88 )
{
struct V_50 * V_51 = F_22 ( V_85 -> V_61 ) ;
switch ( V_88 ) {
case V_89 :
F_7 ( V_51 ,
V_21 , V_90 ) ;
break;
case V_91 :
F_7 ( V_51 ,
V_21 , V_92 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_24 ( struct V_80 * V_85 ,
struct V_86 * V_87 , int V_88 )
{
struct V_50 * V_51 = F_22 ( V_85 -> V_61 ) ;
switch ( V_88 ) {
case V_89 :
F_7 ( V_51 , V_20 , 0x20 ) ;
break;
case V_91 :
F_7 ( V_51 , V_20 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_25 ( struct V_80 * V_85 ,
struct V_86 * V_87 , int V_88 )
{
struct V_50 * V_51 = F_22 ( V_85 -> V_61 ) ;
switch ( V_88 ) {
case V_89 :
F_26 ( V_51 , V_93 , 0x38 , 0x08 ) ;
break;
case V_91 :
F_26 ( V_51 , V_93 , 0x38 , 0x30 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_27 ( struct V_80 * V_85 ,
struct V_86 * V_87 , int V_88 )
{
struct V_50 * V_51 = F_22 ( V_85 -> V_61 ) ;
switch ( V_88 ) {
case V_94 :
F_26 ( V_51 ,
V_95 , 0xc000 , 0x8000 ) ;
F_26 ( V_51 ,
V_96 , 0xc000 , 0x8000 ) ;
break;
case V_97 :
F_26 ( V_51 ,
V_95 , 0xc000 , 0x0000 ) ;
F_26 ( V_51 ,
V_96 , 0xc000 , 0x0000 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static int F_28 ( struct V_98 * V_99 ,
struct V_100 * V_101 ,
struct V_102 * V_103 )
{
struct V_50 * V_51 = V_103 -> V_51 ;
struct V_52 * V_53 = F_6 ( V_51 ) ;
unsigned int V_62 = 0 ;
int V_104 ;
switch ( F_29 ( V_101 ) ) {
case 44100 :
V_62 |= 0x4000 ;
break;
case 48000 :
break;
default:
F_30 ( V_51 -> V_2 , L_4 ,
F_29 ( V_101 ) ) ;
return - V_64 ;
}
switch ( V_53 -> V_105 ) {
case 12288000 :
case 24576000 :
if ( F_29 ( V_101 ) != 48000 ) {
F_30 ( V_51 -> V_2 , L_5 ,
F_29 ( V_101 ) , V_53 -> V_105 ) ;
return - V_64 ;
}
break;
case 11289600 :
case 22579200 :
if ( F_29 ( V_101 ) != 44100 ) {
F_30 ( V_51 -> V_2 , L_5 ,
F_29 ( V_101 ) , V_53 -> V_105 ) ;
return - V_64 ;
}
break;
}
if ( F_31 ( V_101 ) <= 16 ) {
V_62 |= ( F_31 ( V_101 ) - 1 ) ;
} else {
F_30 ( V_51 -> V_2 , L_6 ,
F_31 ( V_101 ) ) ;
return - V_64 ;
}
V_104 = 0 ;
switch ( F_32 ( V_101 ) ) {
case 16 :
V_104 = 0 ;
V_62 |= ( 0x1 << 4 ) ;
break;
case 32 :
V_104 = 2 ;
V_62 |= ( 0x4 << 4 ) ;
break;
case 20 :
V_104 = 1 ;
V_62 |= ( 0x2 << 4 ) ;
break;
case 24 :
V_104 = 2 ;
V_62 |= ( 0x3 << 4 ) ;
break;
case 8 :
V_104 = 3 ;
break;
default:
return - V_64 ;
}
F_26 ( V_51 ,
V_106 , 0x0018 , V_104 << 3 ) ;
F_33 ( V_51 -> V_2 , L_7 , V_62 ) ;
F_26 ( V_51 , V_39 , 0x407f , V_62 ) ;
F_26 ( V_51 , V_40 , 0x407f , V_62 ) ;
return 0 ;
}
static int F_34 ( struct V_102 * V_103 , unsigned int V_107 )
{
struct V_50 * V_51 = V_103 -> V_51 ;
switch ( V_107 & V_108 ) {
case V_109 :
F_26 ( V_51 ,
V_106 , 0x800 , 0x800 ) ;
break;
case V_110 :
F_26 ( V_51 ,
V_106 , 0x800 , 0x0 ) ;
break;
default:
return - V_64 ;
}
switch ( V_107 & V_111 ) {
case V_112 :
F_26 ( V_51 ,
V_106 , 0x300 , 0x0 ) ;
break;
case V_113 :
F_26 ( V_51 ,
V_106 , 0x300 , 0x1 << 8 ) ;
break;
case V_114 :
F_26 ( V_51 ,
V_106 , 0x300 , 0x2 << 8 ) ;
break;
case V_115 :
F_26 ( V_51 ,
V_106 , 0x300 , 0x3 << 8 ) ;
break;
default:
return - V_64 ;
}
F_26 ( V_51 , V_39 , 0x8000 , 0 ) ;
F_26 ( V_51 , V_40 , 0x8000 , 0 ) ;
return 0 ;
}
static int F_35 ( struct V_102 * V_103 ,
int V_83 , unsigned int V_116 , int V_117 )
{
struct V_50 * V_51 = V_103 -> V_51 ;
struct V_52 * V_53 = F_6 ( V_51 ) ;
F_33 ( V_51 -> V_2 , L_8 , V_118 , V_116 ) ;
if ( V_84 == V_83 ) {
F_26 ( V_51 ,
V_119 , 0x0100 , 0x0 ) ;
F_26 ( V_51 ,
V_120 , 0x20 , 0x20 ) ;
} else {
F_26 ( V_51 ,
V_119 , 0x0100 , 0x0100 ) ;
F_26 ( V_51 ,
V_121 , 0x4 , 0x4 ) ;
F_26 ( V_51 ,
V_120 , 0x20 , 0x0 ) ;
}
switch ( V_116 ) {
case 19200000 :
if ( V_84 == V_83 ) {
F_30 ( V_51 -> V_2 , L_9 ) ;
return - V_64 ;
}
F_26 ( V_51 ,
V_119 , 0x40 , 0x40 ) ;
break;
case 24000000 :
if ( V_84 == V_83 ) {
F_30 ( V_51 -> V_2 , L_9 ) ;
return - V_64 ;
}
F_26 ( V_51 ,
V_119 , 0x40 , 0x0 ) ;
break;
case 12288000 :
case 11289600 :
F_26 ( V_51 ,
V_119 , 0x8 , 0x0 ) ;
F_26 ( V_51 ,
V_122 , 0xfc1e , 0x0004 ) ;
break;
case 24576000 :
case 22579200 :
F_26 ( V_51 ,
V_119 , 0x8 , 0x8 ) ;
F_26 ( V_51 ,
V_122 , 0xfc1e , 0x5406 ) ;
break;
default:
F_30 ( V_51 -> V_2 , L_10 ) ;
return - V_64 ;
}
V_53 -> V_105 = V_116 ;
V_53 -> V_83 = V_83 ;
return 0 ;
}
static int F_36 ( struct V_102 * V_103 , unsigned int V_123 )
{
struct V_50 * V_51 = V_103 -> V_51 ;
F_33 ( V_51 -> V_2 , L_11 , V_118 , V_123 ) ;
if ( 50 == V_123 )
F_26 ( V_51 ,
V_106 , 0x1000 , 0x1000 ) ;
else
F_26 ( V_51 ,
V_106 , 0x1000 , 0x0 ) ;
return 0 ;
}
static int F_37 ( struct V_50 * V_51 ,
enum V_124 V_125 )
{
switch ( V_125 ) {
case V_126 :
if ( V_127 == F_38 ( V_51 ) ) {
F_7 ( V_51 ,
V_9 , V_128 ) ;
F_26 ( V_51 ,
V_68 , 0x200 , 0x200 ) ;
}
break;
case V_129 :
F_39 ( 10 ) ;
F_26 ( V_51 ,
V_68 , 0x200 , 0x0 ) ;
break;
case V_127 :
F_7 ( V_51 ,
V_9 , V_130 ) ;
break;
default:
break;
}
return 0 ;
}
static T_1 F_40 ( int V_131 , void * V_132 )
{
struct V_52 * V_53 = V_132 ;
bool V_58 = false ;
bool V_59 = false ;
int V_74 = 0 ;
F_8 ( V_53 , & V_58 , & V_59 ) ;
F_11 ( V_53 -> V_67 , V_79 , 0x1 , 0x1 ) ;
if ( V_58 == true )
V_74 |= V_75 ;
if ( V_59 == true )
V_74 |= V_76 ;
F_19 ( V_53 -> V_77 , V_74 ,
V_76 | V_75 ) ;
F_41 ( & V_53 -> V_133 -> V_2 , 300 ) ;
return V_134 ;
}
static int F_42 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_6 ( V_51 ) ;
V_53 -> V_51 = V_51 ;
if ( V_53 -> V_133 -> V_131 ) {
F_11 ( V_53 -> V_67 ,
V_79 , 0x2 , 0x2 ) ;
F_43 ( & V_53 -> V_73 ,
F_17 ) ;
F_44 ( & V_53 -> V_73 ,
F_45 ( 1250 ) ) ;
}
return 0 ;
}
static int F_46 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_6 ( V_51 ) ;
F_47 ( & V_53 -> V_73 ) ;
return 0 ;
}
static int F_48 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_6 ( V_51 ) ;
F_49 ( V_53 -> V_67 , true ) ;
F_50 ( V_53 -> V_67 ) ;
return 0 ;
}
static int F_51 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = F_6 ( V_51 ) ;
F_49 ( V_53 -> V_67 , false ) ;
F_5 ( V_51 ) ;
F_52 ( V_53 -> V_67 ) ;
return 0 ;
}
static int F_53 ( struct V_135 * V_133 ,
const struct V_136 * V_137 )
{
struct V_138 * V_65 = F_54 ( & V_133 -> V_2 ) ;
struct V_52 * V_53 ;
int V_54 , V_139 , V_62 ;
V_53 = F_55 ( & V_133 -> V_2 , sizeof( * V_53 ) ,
V_140 ) ;
if ( NULL == V_53 )
return - V_141 ;
V_53 -> V_67 = F_56 ( & V_133 -> V_2 , NULL , V_133 , & V_142 ) ;
if ( F_57 ( V_53 -> V_67 ) ) {
V_139 = F_58 ( V_53 -> V_67 ) ;
F_30 ( & V_133 -> V_2 , L_12 ,
V_139 ) ;
return V_139 ;
}
V_139 = F_10 ( V_53 -> V_67 ,
F_2 ( V_4 , V_5 ) , & V_62 ) ;
if ( V_139 != 0 ) {
F_30 ( & V_133 -> V_2 , L_13 , V_139 ) ;
return V_139 ;
}
if ( V_62 != V_143 && V_62 != V_144 ) {
F_30 ( & V_133 -> V_2 ,
L_14 , V_62 ) ;
return - V_145 ;
}
V_53 -> V_56 = F_59 ( & V_133 -> V_2 , V_146 ,
sizeof( V_146 ) , V_140 ) ;
if ( ! V_53 -> V_56 )
return - V_141 ;
V_53 -> V_147 = V_55 ;
V_53 -> V_133 = V_133 ;
F_60 ( V_133 , V_53 ) ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ )
F_14 ( V_53 -> V_67 , V_53 -> V_56 [ V_54 ] . V_3 ,
V_53 -> V_56 [ V_54 ] . V_57 ) ;
for ( V_54 = 0 ; V_54 < F_61 ( V_148 ) ; V_54 ++ )
F_14 ( V_53 -> V_67 , V_148 [ V_54 ] . V_3 ,
V_148 [ V_54 ] . V_57 ) ;
if ( V_65 )
V_53 -> V_65 = * V_65 ;
if ( F_62 ( V_149 ) ||
F_62 ( V_150 ) )
V_53 -> V_65 . V_66 = true ;
F_14 ( V_53 -> V_67 , V_9 , V_130 ) ;
for ( V_54 = 0 ; V_54 < V_151 ; V_54 ++ )
F_14 ( V_53 -> V_67 ,
F_4 ( V_152 [ V_54 ] ) ,
V_153 ) ;
if ( ! V_53 -> V_65 . V_66 ) {
F_14 ( V_53 -> V_67 , V_70 , 0x0000 ) ;
F_14 ( V_53 -> V_67 , V_154 , 0x0816 ) ;
F_11 ( V_53 -> V_67 ,
V_69 , 0xf000 , 0xb000 ) ;
} else {
F_11 ( V_53 -> V_67 ,
V_69 , 0xf000 , 0x5000 ) ;
}
F_39 ( 10 ) ;
if ( ! V_53 -> V_65 . V_155 )
F_14 ( V_53 -> V_67 , V_23 , 0x4000 ) ;
else
F_14 ( V_53 -> V_67 , V_23 , 0 ) ;
F_39 ( 10 ) ;
F_14 ( V_53 -> V_67 , V_156 , 0x0000 ) ;
F_11 ( V_53 -> V_67 , V_93 , 0xc , 0x0 ) ;
F_11 ( V_53 -> V_67 , V_157 , 0x1001 , 0x1001 ) ;
F_11 ( V_53 -> V_67 , V_158 , 0x403a , 0x401a ) ;
F_11 ( V_53 -> V_67 , V_159 , 0xf777 , 0x4737 ) ;
F_11 ( V_53 -> V_67 , V_160 , 0x00ff , 0x003f ) ;
if ( F_62 ( V_150 ) ) {
F_11 ( V_53 -> V_67 ,
V_161 , 0x40 , 0x40 ) ;
F_11 ( V_53 -> V_67 ,
V_162 , 0x40 , 0x40 ) ;
F_11 ( V_53 -> V_67 ,
V_163 , 0x40 , 0x40 ) ;
F_11 ( V_53 -> V_67 ,
V_164 , 0xc , 0x8 ) ;
}
if ( V_53 -> V_133 -> V_131 ) {
V_139 = F_63 ( V_53 -> V_133 -> V_131 , NULL , F_40 ,
V_165 | V_166 , L_15 , V_53 ) ;
if ( V_139 != 0 ) {
F_30 ( & V_133 -> V_2 ,
L_16 , V_139 ) ;
return V_139 ;
}
}
V_139 = F_64 ( & V_133 -> V_2 , & V_167 ,
V_168 , F_61 ( V_168 ) ) ;
return V_139 ;
}
static int F_65 ( struct V_135 * V_133 )
{
struct V_52 * V_53 = F_66 ( V_133 ) ;
if ( V_133 -> V_131 )
F_67 ( V_133 -> V_131 , V_53 ) ;
F_68 ( & V_133 -> V_2 ) ;
return 0 ;
}
