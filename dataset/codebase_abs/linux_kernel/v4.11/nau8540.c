static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 ... V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_10 ... V_11 :
case V_12 ... V_13 :
case V_14 ... V_15 :
case V_16 :
case V_17 ... V_18 :
case V_19 ... V_20 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_21 ... V_5 :
case V_6 ... V_7 :
case V_8 ... V_9 :
case V_22 ... V_11 :
case V_12 ... V_13 :
case V_23 ... V_15 :
case V_24 :
case V_17 ... V_18 :
case V_19 ... V_20 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_21 :
case V_10 ... V_25 :
case V_14 ... V_26 :
case V_16 :
case V_24 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_27 * V_27 , int V_28 , int V_29 )
{
int V_30 ;
if ( V_29 >= F_5 ( V_31 ) )
return - V_32 ;
V_30 = V_31 [ V_29 ] . V_29 ;
if ( V_28 * V_29 > V_33 ) {
F_6 ( V_27 -> V_2 , L_1 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_7 ( struct V_34 * V_35 ,
struct V_36 * V_37 , struct V_38 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
struct V_27 * V_27 = F_8 ( V_41 ) ;
unsigned int V_42 = 0 , V_29 ;
F_9 ( V_27 -> V_43 , V_11 , & V_29 ) ;
V_29 &= V_44 ;
if ( F_4 ( V_27 , F_10 ( V_37 ) , V_29 ) )
return - V_32 ;
F_11 ( V_27 -> V_43 , V_45 ,
V_46 ,
V_31 [ V_29 ] . V_47 << V_48 ) ;
switch ( F_12 ( V_37 ) ) {
case 16 :
V_42 |= V_49 ;
break;
case 20 :
V_42 |= V_50 ;
break;
case 24 :
V_42 |= V_51 ;
break;
case 32 :
V_42 |= V_52 ;
break;
default:
return - V_32 ;
}
F_11 ( V_27 -> V_43 , V_6 ,
V_53 , V_42 ) ;
return 0 ;
}
static int F_13 ( struct V_38 * V_39 , unsigned int V_54 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
struct V_27 * V_27 = F_8 ( V_41 ) ;
unsigned int V_55 = 0 , V_56 = 0 ;
switch ( V_54 & V_57 ) {
case V_58 :
V_56 |= V_59 ;
break;
case V_60 :
break;
default:
return - V_32 ;
}
switch ( V_54 & V_61 ) {
case V_62 :
break;
case V_63 :
V_55 |= V_64 ;
break;
default:
return - V_32 ;
}
switch ( V_54 & V_65 ) {
case V_66 :
V_55 |= V_67 ;
break;
case V_68 :
V_55 |= V_69 ;
break;
case V_70 :
V_55 |= V_71 ;
break;
case V_72 :
V_55 |= V_73 ;
break;
case V_74 :
V_55 |= V_73 ;
V_55 |= V_75 ;
break;
default:
return - V_32 ;
}
F_11 ( V_27 -> V_43 , V_6 ,
V_53 | V_76 |
V_64 | V_75 , V_55 ) ;
F_11 ( V_27 -> V_43 , V_77 ,
V_78 | V_79 , V_56 ) ;
F_11 ( V_27 -> V_43 , V_80 ,
V_81 , 0 ) ;
return 0 ;
}
static int F_14 ( struct V_38 * V_39 ,
unsigned int V_82 , unsigned int V_83 , int V_84 , int V_85 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
struct V_27 * V_27 = F_8 ( V_41 ) ;
unsigned int V_56 = 0 , V_86 = 0 ;
if ( V_84 > 4 || ( ( V_82 & 0xf0 ) && ( V_82 & 0xf ) ) )
return - V_32 ;
V_86 |= ( V_87 | V_88 ) ;
if ( V_82 & 0xf0 ) {
V_56 = 4 * V_85 ;
V_86 |= ( V_82 >> 4 ) ;
} else {
V_86 |= V_82 ;
}
F_11 ( V_27 -> V_43 , V_7 ,
V_87 | V_88 |
V_89 , V_86 ) ;
F_11 ( V_27 -> V_43 , V_77 ,
V_79 , V_79 ) ;
F_11 ( V_27 -> V_43 , V_80 ,
V_81 | V_90 ,
V_81 | V_56 ) ;
return 0 ;
}
static int F_15 ( unsigned int V_91 ,
unsigned int V_92 , struct V_93 * V_94 )
{
T_1 V_95 , V_96 ;
unsigned int V_97 , V_98 , V_99 ;
for ( V_98 = 0 ; V_98 < F_5 ( V_100 ) ; V_98 ++ ) {
V_97 = V_91 / V_100 [ V_98 ] . V_101 ;
if ( V_97 <= V_102 )
break;
}
if ( V_98 == F_5 ( V_100 ) )
return - V_32 ;
V_94 -> V_103 = V_100 [ V_98 ] . V_104 ;
for ( V_98 = 0 ; V_98 < F_5 ( V_105 ) ; V_98 ++ ) {
if ( V_97 >= V_105 [ V_98 ] . V_101 )
break;
}
if ( V_98 == F_5 ( V_105 ) )
return - V_32 ;
V_94 -> V_106 = V_105 [ V_98 ] . V_104 ;
V_96 = 0 ;
V_99 = F_5 ( V_107 ) ;
for ( V_98 = 0 ; V_98 < F_5 ( V_107 ) ; V_98 ++ ) {
V_95 = 256 * V_92 * 2 * V_107 [ V_98 ] . V_101 ;
if ( V_95 > V_108 && V_95 < V_109 &&
V_96 < V_95 ) {
V_96 = V_95 ;
V_99 = V_98 ;
}
}
if ( F_5 ( V_107 ) == V_99 )
return - V_32 ;
V_94 -> V_110 = V_107 [ V_99 ] . V_104 ;
V_95 = F_16 ( V_96 << 16 , V_97 * V_94 -> V_106 ) ;
V_94 -> V_111 = ( V_95 >> 16 ) & 0x3FF ;
V_94 -> V_112 = V_95 & 0xFFFF ;
return 0 ;
}
static void F_17 ( struct V_43 * V_43 ,
struct V_93 * V_94 )
{
F_11 ( V_43 , V_45 ,
V_113 | V_114 ,
V_115 | V_94 -> V_110 ) ;
F_11 ( V_43 , V_116 ,
V_117 , V_94 -> V_106 ) ;
F_18 ( V_43 , V_118 , V_94 -> V_112 ) ;
F_11 ( V_43 , V_119 ,
V_120 , V_94 -> V_111 ) ;
F_11 ( V_43 , V_121 ,
V_122 ,
V_94 -> V_103 << V_123 ) ;
F_11 ( V_43 , V_124 ,
V_125 , V_126 ) ;
F_11 ( V_43 ,
V_127 , V_128 , 0 ) ;
if ( V_94 -> V_112 ) {
F_11 ( V_43 , V_124 ,
V_129 | V_130 |
V_131 ,
V_129 | V_130 |
V_132 ) ;
F_11 ( V_43 , V_127 ,
V_133 , V_133 ) ;
} else {
F_11 ( V_43 , V_124 ,
V_129 | V_130 |
V_131 , V_134 ) ;
F_11 ( V_43 ,
V_127 , V_133 , 0 ) ;
}
}
static int F_19 ( struct V_40 * V_41 , int V_135 , int V_136 ,
unsigned int V_137 , unsigned int V_138 )
{
struct V_27 * V_27 = F_8 ( V_41 ) ;
struct V_93 V_94 ;
int V_139 , V_92 ;
switch ( V_135 ) {
case V_140 :
F_11 ( V_27 -> V_43 , V_119 ,
V_141 , V_142 ) ;
break;
case V_143 :
F_11 ( V_27 -> V_43 , V_119 ,
V_141 , V_144 ) ;
break;
case V_145 :
F_11 ( V_27 -> V_43 , V_119 ,
V_141 , V_146 ) ;
break;
default:
F_6 ( V_27 -> V_2 , L_2 , V_135 ) ;
return - V_32 ;
}
F_20 ( V_27 -> V_2 , L_3 ,
V_138 , V_135 ) ;
V_92 = V_138 / 256 ;
V_139 = F_15 ( V_137 , V_92 , & V_94 ) ;
if ( V_139 < 0 ) {
F_6 ( V_27 -> V_2 , L_4 , V_137 ) ;
return V_139 ;
}
F_20 ( V_27 -> V_2 , L_5 ,
V_94 . V_110 , V_94 . V_106 , V_94 . V_112 ,
V_94 . V_111 , V_94 . V_103 ) ;
F_17 ( V_27 -> V_43 , & V_94 ) ;
F_21 ( 2 ) ;
F_11 ( V_27 -> V_43 , V_45 ,
V_113 , V_147 ) ;
return 0 ;
}
static int F_22 ( struct V_40 * V_41 ,
int V_148 , int V_136 , unsigned int V_149 , int V_150 )
{
struct V_27 * V_27 = F_8 ( V_41 ) ;
switch ( V_148 ) {
case V_151 :
case V_152 :
F_11 ( V_27 -> V_43 , V_45 ,
V_113 , V_115 ) ;
F_11 ( V_27 -> V_43 , V_127 ,
V_128 , 0 ) ;
break;
case V_153 :
F_11 ( V_27 -> V_43 , V_127 ,
V_128 , V_128 ) ;
F_11 ( V_27 -> V_43 , V_45 ,
V_113 , V_147 ) ;
break;
default:
F_6 ( V_27 -> V_2 , L_2 , V_148 ) ;
return - V_32 ;
}
F_20 ( V_27 -> V_2 , L_3 ,
V_149 , V_148 ) ;
return 0 ;
}
static void F_23 ( struct V_43 * V_43 )
{
F_18 ( V_43 , V_21 , 0x00 ) ;
F_18 ( V_43 , V_21 , 0x00 ) ;
}
static void F_24 ( struct V_27 * V_27 )
{
struct V_43 * V_43 = V_27 -> V_43 ;
F_11 ( V_43 , V_17 ,
V_154 | V_155 ,
V_154 | ( 0x2 << V_156 ) ) ;
F_11 ( V_43 , V_157 ,
V_158 | V_159 ,
V_158 | V_159 ) ;
F_21 ( 2 ) ;
F_11 ( V_43 , V_160 ,
V_161 , V_161 ) ;
F_11 ( V_43 , V_162 ,
V_163 | V_164 ,
V_163 | V_164 ) ;
F_11 ( V_43 , V_11 ,
V_44 , V_165 ) ;
}
static int T_2 F_25 ( struct V_40 * V_41 )
{
struct V_27 * V_27 = F_8 ( V_41 ) ;
F_26 ( V_27 -> V_43 , true ) ;
F_27 ( V_27 -> V_43 ) ;
return 0 ;
}
static int T_2 F_28 ( struct V_40 * V_41 )
{
struct V_27 * V_27 = F_8 ( V_41 ) ;
F_26 ( V_27 -> V_43 , false ) ;
F_29 ( V_27 -> V_43 ) ;
return 0 ;
}
static int F_30 ( struct V_166 * V_167 ,
const struct V_168 * V_169 )
{
struct V_1 * V_2 = & V_167 -> V_2 ;
struct V_27 * V_27 = F_31 ( V_2 ) ;
int V_139 , V_170 ;
if ( ! V_27 ) {
V_27 = F_32 ( V_2 , sizeof( * V_27 ) , V_171 ) ;
if ( ! V_27 )
return - V_172 ;
}
F_33 ( V_167 , V_27 ) ;
V_27 -> V_43 = F_34 ( V_167 , & V_173 ) ;
if ( F_35 ( V_27 -> V_43 ) )
return F_36 ( V_27 -> V_43 ) ;
V_139 = F_9 ( V_27 -> V_43 , V_16 , & V_170 ) ;
if ( V_139 < 0 ) {
F_6 ( V_2 , L_6 ,
V_139 ) ;
return V_139 ;
}
V_27 -> V_2 = V_2 ;
F_23 ( V_27 -> V_43 ) ;
F_24 ( V_27 ) ;
return F_37 ( V_2 ,
& V_174 , & V_175 , 1 ) ;
}
static int F_38 ( struct V_166 * V_176 )
{
F_39 ( & V_176 -> V_2 ) ;
return 0 ;
}
