static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_6 :
case V_7 :
case V_8 :
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
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_4 :
case V_5 :
return true ;
default:
return false ;
}
}
static bool F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
switch ( V_3 ) {
case V_50 | V_6 :
case V_50 | V_7 :
case V_50 | V_8 :
case V_50 | V_9 :
case V_50 | V_10 :
case V_50 | V_11 :
case V_50 | V_12 :
case V_50 | V_13 :
case V_50 | V_14 :
case V_50 | V_15 :
case V_50 | V_16 :
case V_50 | V_17 :
case V_50 | V_18 :
case V_50 | V_19 :
case V_50 | V_20 :
case V_50 | V_21 :
case V_50 | V_22 :
case V_50 | V_23 :
case V_50 | V_24 :
case V_50 | V_25 :
case V_50 | V_26 :
case V_50 | V_27 :
case V_50 | V_28 :
case V_50 | V_29 :
case V_50 | V_30 :
case V_50 | V_31 :
case V_50 | V_32 :
case V_50 | V_33 :
case V_50 | V_34 :
case V_50 | V_35 :
case V_50 | V_36 :
case V_50 | V_37 :
case V_50 | V_38 :
case V_50 | V_39 :
case V_50 | V_40 :
case V_50 | V_41 :
case V_50 | V_42 :
case V_50 | V_43 :
case V_50 | V_44 :
case V_50 | V_45 :
case V_50 | V_46 :
case V_50 | V_47 :
case V_50 | V_48 :
case V_50 | V_49 :
case V_50 | V_4 :
case V_50 | V_5 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_51 * V_52 , int V_53 )
{
int div [] = { 2 , 3 , 4 , 8 , 12 , 16 , 24 , 32 } ;
int V_54 ;
if ( V_53 < 1000000 * div [ 0 ] ) {
F_5 ( L_1 , V_53 ) ;
return - V_55 ;
}
for ( V_54 = 0 ; V_54 < F_6 ( div ) ; V_54 ++ ) {
if ( 3072000 * div [ V_54 ] >= V_53 )
return V_54 ;
}
F_7 ( V_52 -> V_2 , L_2 , V_53 ) ;
return - V_55 ;
}
static int F_8 ( struct V_56 * V_57 ,
struct V_58 * V_59 , int V_60 )
{
struct V_51 * V_52 = F_9 ( V_57 -> V_61 ) ;
struct V_62 * V_63 = F_10 ( V_52 ) ;
int V_64 ;
V_64 = F_4 ( V_52 , V_63 -> V_65 ) ;
if ( V_64 < 0 )
F_11 ( V_52 -> V_2 , L_3 ) ;
else
F_12 ( V_63 -> V_66 , V_20 ,
V_67 ,
V_64 << V_68 ) ;
return V_64 ;
}
static int F_13 ( struct V_56 * V_69 ,
struct V_56 * V_70 )
{
struct V_51 * V_52 = F_9 ( V_69 -> V_61 ) ;
struct V_62 * V_63 = F_10 ( V_52 ) ;
if ( V_63 -> V_71 == V_72 )
return 1 ;
else
return 0 ;
}
static int F_14 ( struct V_73 * V_74 ,
struct V_75 * V_76 , struct V_77 * V_78 )
{
struct V_51 * V_52 = V_78 -> V_52 ;
struct V_62 * V_63 = F_10 ( V_52 ) ;
int V_79 , V_80 , V_81 ;
unsigned int V_82 = 0 ;
V_63 -> V_83 = F_15 ( V_76 ) ;
V_79 = F_16 ( V_63 -> V_65 , V_63 -> V_83 ) ;
if ( V_79 < 0 ) {
F_11 ( V_52 -> V_2 , L_4 ) ;
return - V_55 ;
}
V_81 = F_17 ( V_76 ) ;
if ( V_81 < 0 ) {
F_11 ( V_52 -> V_2 , L_5 , V_81 ) ;
return - V_55 ;
}
V_80 = V_81 > 32 ;
V_63 -> V_84 = V_63 -> V_83 * ( 32 << V_80 ) ;
F_18 ( V_78 -> V_2 , L_6 ,
V_63 -> V_84 , V_63 -> V_83 ) ;
F_18 ( V_78 -> V_2 , L_7 ,
V_80 , V_79 , V_78 -> V_85 ) ;
switch ( F_19 ( V_76 ) ) {
case V_86 :
break;
case V_87 :
V_82 = V_88 ;
break;
case V_89 :
V_82 = V_90 ;
break;
case V_91 :
V_82 = V_92 ;
break;
default:
return - V_55 ;
}
F_12 ( V_63 -> V_66 , V_9 , V_93 ,
V_82 ) ;
F_12 ( V_63 -> V_66 , V_21 ,
V_94 | V_95 ,
V_79 << V_96 |
V_79 << V_97 ) ;
return 0 ;
}
static int F_20 ( struct V_77 * V_78 , unsigned int V_98 )
{
struct V_51 * V_52 = V_78 -> V_52 ;
struct V_62 * V_63 = F_10 ( V_52 ) ;
unsigned int V_99 = 0 ;
switch ( V_98 & V_100 ) {
case V_101 :
break;
case V_102 :
V_99 |= V_103 ;
break;
case V_104 :
V_99 |= V_105 ;
break;
case V_106 :
V_99 |= V_105 | V_103 ;
break;
default:
return - V_55 ;
}
switch ( V_98 & V_107 ) {
case V_108 :
break;
case V_109 :
V_99 |= V_110 ;
break;
case V_111 :
V_99 |= V_112 ;
break;
case V_113 :
V_99 |= V_114 ;
break;
default:
return - V_55 ;
}
F_12 ( V_63 -> V_66 , V_9 ,
V_115 | V_116 | V_117 ,
V_99 ) ;
return 0 ;
}
static int F_21 ( struct V_77 * V_78 ,
int V_118 , unsigned int V_119 , int V_120 )
{
struct V_51 * V_52 = V_78 -> V_52 ;
struct V_62 * V_63 = F_10 ( V_52 ) ;
unsigned int V_99 = 0 ;
if ( V_119 == V_63 -> V_65 && V_118 == V_63 -> V_71 )
return 0 ;
switch ( V_118 ) {
case V_121 :
V_99 |= V_122 ;
break;
case V_72 :
V_99 |= V_123 ;
break;
default:
F_11 ( V_52 -> V_2 , L_8 , V_118 ) ;
return - V_55 ;
}
F_12 ( V_63 -> V_66 , V_21 ,
V_124 , V_99 ) ;
V_63 -> V_65 = V_119 ;
V_63 -> V_71 = V_118 ;
F_18 ( V_78 -> V_2 , L_9 , V_119 , V_118 ) ;
return 0 ;
}
static int F_22 ( struct V_77 * V_78 , int V_125 , int V_69 ,
unsigned int V_126 , unsigned int V_127 )
{
struct V_51 * V_52 = V_78 -> V_52 ;
struct V_62 * V_63 = F_10 ( V_52 ) ;
struct V_128 V_129 ;
int V_130 ;
if ( ! V_126 || ! V_127 ) {
F_18 ( V_52 -> V_2 , L_10 ) ;
V_63 -> V_131 = 0 ;
V_63 -> V_132 = 0 ;
F_12 ( V_63 -> V_66 , V_21 ,
V_124 ,
V_122 ) ;
return 0 ;
}
if ( V_69 == V_63 -> V_133 && V_126 == V_63 -> V_131 &&
V_127 == V_63 -> V_132 )
return 0 ;
switch ( V_69 ) {
case V_134 :
F_12 ( V_63 -> V_66 , V_19 ,
V_135 , V_136 ) ;
break;
case V_137 :
F_12 ( V_63 -> V_66 , V_19 ,
V_135 , V_138 ) ;
break;
default:
F_11 ( V_52 -> V_2 , L_11 , V_69 ) ;
return - V_55 ;
}
V_130 = F_23 ( V_126 , V_127 , & V_129 ) ;
if ( V_130 < 0 ) {
F_11 ( V_52 -> V_2 , L_12 , V_126 ) ;
return V_130 ;
}
F_18 ( V_52 -> V_2 , L_13 ,
V_129 . V_139 , ( V_129 . V_139 ? 0 : V_129 . V_140 ) ,
V_129 . V_141 , V_129 . V_142 ) ;
F_24 ( V_63 -> V_66 , V_43 ,
V_129 . V_142 << V_143 |
V_129 . V_141 << V_144 |
( V_129 . V_139 ? 0 : V_129 . V_140 ) << V_145 ) ;
F_12 ( V_63 -> V_66 , V_44 ,
V_146 , V_129 . V_139 << V_147 ) ;
V_63 -> V_131 = V_126 ;
V_63 -> V_132 = V_127 ;
V_63 -> V_133 = V_69 ;
return 0 ;
}
static int F_25 ( struct V_77 * V_78 , unsigned int V_148 ,
unsigned int V_149 , int V_150 , int V_151 )
{
struct V_51 * V_52 = V_78 -> V_52 ;
struct V_62 * V_63 = F_10 ( V_52 ) ;
unsigned int V_152 = 0 ;
if ( V_149 || V_148 )
V_152 |= V_153 ;
if ( V_150 == 4 )
V_152 |= V_154 | V_155 ;
switch ( V_151 ) {
case 20 :
V_152 |= V_156 | V_157 ;
break;
case 24 :
V_152 |= V_158 | V_159 ;
break;
case 32 :
V_152 |= V_160 | V_161 ;
break;
case 16 :
default:
break;
}
F_12 ( V_63 -> V_66 , V_9 , V_153 |
V_162 | V_163 |
V_164 | V_165 , V_152 ) ;
return 0 ;
}
static int F_26 ( struct V_51 * V_52 )
{
struct V_62 * V_63 = F_10 ( V_52 ) ;
V_63 -> V_52 = V_52 ;
return 0 ;
}
static int F_27 ( void * V_166 , unsigned int V_3 , unsigned int * V_152 )
{
struct V_167 * V_168 = V_166 ;
struct V_62 * V_63 = F_28 ( V_168 ) ;
F_29 ( V_63 -> V_169 , V_3 | V_50 , V_152 ) ;
return 0 ;
}
static int F_30 ( void * V_166 , unsigned int V_3 , unsigned int V_152 )
{
struct V_167 * V_168 = V_166 ;
struct V_62 * V_63 = F_28 ( V_168 ) ;
F_24 ( V_63 -> V_169 , V_3 | V_50 , V_152 ) ;
return 0 ;
}
static int F_31 ( struct V_167 * V_170 ,
const struct V_171 * V_85 )
{
struct V_62 * V_63 ;
int V_130 ;
unsigned int V_152 ;
V_63 = F_32 ( & V_170 -> V_2 , sizeof( struct V_62 ) ,
V_172 ) ;
if ( V_63 == NULL )
return - V_173 ;
F_33 ( V_170 , V_63 ) ;
V_63 -> V_169 = F_34 ( V_170 , & V_174 ) ;
if ( F_35 ( V_63 -> V_169 ) ) {
V_130 = F_36 ( V_63 -> V_169 ) ;
F_11 ( & V_170 -> V_2 , L_14 ,
V_130 ) ;
return V_130 ;
}
V_63 -> V_66 = F_37 ( & V_170 -> V_2 , NULL , V_170 , & V_175 ) ;
if ( F_35 ( V_63 -> V_66 ) ) {
V_130 = F_36 ( V_63 -> V_66 ) ;
F_11 ( & V_170 -> V_2 , L_14 ,
V_130 ) ;
return V_130 ;
}
F_29 ( V_63 -> V_66 , V_5 , & V_152 ) ;
if ( V_152 != V_176 ) {
F_11 ( & V_170 -> V_2 ,
L_15 , V_152 ) ;
return - V_177 ;
}
V_130 = F_38 ( V_63 -> V_169 , V_178 ,
F_6 ( V_178 ) ) ;
if ( V_130 != 0 )
F_7 ( & V_170 -> V_2 , L_16 ,
V_130 ) ;
V_130 = F_38 ( V_63 -> V_66 , V_179 ,
F_6 ( V_179 ) ) ;
if ( V_130 != 0 )
F_7 ( & V_170 -> V_2 , L_17 , V_130 ) ;
return F_39 ( & V_170 -> V_2 , & V_180 ,
V_181 , F_6 ( V_181 ) ) ;
}
static int F_40 ( struct V_167 * V_170 )
{
F_41 ( & V_170 -> V_2 ) ;
return 0 ;
}
