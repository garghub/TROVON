static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
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
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
case V_58 :
return true ;
default:
return false ;
}
}
static int F_2 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_3 ( V_60 ) ;
unsigned int V_3 ;
V_3 = F_4 ( V_64 , V_21 ) ;
if ( V_3 & V_65 )
V_62 -> V_66 . integer . V_66 [ 0 ] = 1 ;
else
V_62 -> V_66 . integer . V_66 [ 0 ] = 0 ;
return 0 ;
}
static int F_5 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
struct V_63 * V_64 = F_3 ( V_60 ) ;
unsigned int V_67 , V_68 ;
unsigned int V_69 ;
if ( V_62 -> V_66 . integer . V_66 [ 0 ] != 0
&& V_62 -> V_66 . integer . V_66 [ 0 ] != 1 )
return - V_70 ;
V_69 = F_4 ( V_64 , V_21 ) ;
switch ( ( V_69 & V_65 ) >> V_71 ) {
case 0 :
if ( ! V_62 -> V_66 . integer . V_66 [ 0 ] )
return 0 ;
break;
case 1 :
if ( V_62 -> V_66 . integer . V_66 [ 0 ] )
return 0 ;
break;
}
V_67 = F_4 ( V_64 , V_6 ) ;
V_68 = F_4 ( V_64 , V_7 ) ;
F_6 ( V_64 , V_6 ,
V_72 | V_73 , 0 ) ;
F_6 ( V_64 , V_7 ,
V_74 | V_75 , 0 ) ;
F_6 ( V_64 , V_11 ,
V_76 , V_77 ) ;
F_6 ( V_64 , V_21 ,
V_78 ,
V_62 -> V_66 . integer . V_66 [ 0 ]
<< V_71 ) ;
F_7 ( V_64 , V_6 , V_67 ) ;
F_7 ( V_64 , V_7 , V_68 ) ;
return 0 ;
}
static int F_8 ( struct V_63 * V_64 )
{
return F_7 ( V_64 , V_4 , 0x0 ) ;
}
static int F_9 ( struct V_79 * V_80 , int V_81 )
{
struct V_63 * V_64 = V_80 -> V_64 ;
return F_6 ( V_64 , V_14 ,
V_82 ,
! ! V_81 << V_83 ) ;
}
static int F_10 ( struct V_79 * V_80 , unsigned int V_84 )
{
struct V_63 * V_64 ;
T_1 V_85 , V_86 , V_87 , V_88 ;
V_64 = V_80 -> V_64 ;
switch ( V_84 & V_89 ) {
case V_90 :
V_85 = 0x2 ;
break;
case V_91 :
V_85 = 0x0 ;
break;
case V_92 :
V_85 = 0x1 ;
break;
case V_93 :
case V_94 :
V_85 = 0x3 ;
break;
default:
F_11 ( V_80 -> V_2 , L_1 ) ;
return - V_70 ;
}
F_6 ( V_64 , V_8 ,
V_95 , V_85 << V_96 ) ;
switch ( V_84 & V_97 ) {
case V_98 :
V_86 = 1 ;
break;
case V_99 :
V_86 = 0 ;
break;
default:
F_11 ( V_80 -> V_2 , L_2 ) ;
return - V_70 ;
}
F_6 ( V_64 , V_10 ,
V_100 , V_86 << V_101 ) ;
switch ( V_84 & V_89 ) {
case V_93 :
case V_94 :
switch ( V_84 & V_102 ) {
case V_103 :
case V_104 :
return - V_70 ;
default:
break;
}
break;
default:
break;
}
V_87 = V_88 = 0 ;
switch ( V_84 & V_102 ) {
case V_105 :
break;
case V_103 :
V_87 = V_88 = 1 ;
break;
case V_106 :
V_87 = 1 ;
break;
case V_104 :
V_88 = 1 ;
break;
default:
F_11 ( V_80 -> V_2 , L_3 ) ;
return - V_70 ;
}
F_6 ( V_64 , V_8 ,
V_107 , V_88 << V_108 ) ;
F_6 ( V_64 , V_8 ,
V_109 , V_87 << V_110 ) ;
return 0 ;
}
static int F_12 ( struct V_111 * V_112 ,
struct V_113 * V_114 ,
struct V_79 * V_80 )
{
int V_115 ;
struct V_63 * V_64 ;
struct V_116 * V_117 ;
T_1 V_118 , V_119 ;
unsigned int V_120 ;
int V_121 ;
V_64 = V_80 -> V_64 ;
V_117 = F_13 ( V_64 ) ;
V_117 -> V_122 = F_14 ( V_114 ) ;
if ( ( int ) V_117 -> V_122 < 0 )
return V_117 -> V_122 ;
switch ( F_15 ( V_114 ) ) {
case V_123 :
V_118 = 0x0 ;
break;
case V_124 :
V_118 = 0x1 ;
break;
case V_125 :
V_118 = 0x2 ;
break;
case V_126 :
V_118 = 0x3 ;
break;
default:
F_11 ( V_80 -> V_2 , L_4 ,
F_15 ( V_114 ) ) ;
return - V_70 ;
}
F_6 ( V_64 , V_8 ,
V_127 , V_118 << V_128 ) ;
V_119 = 0 ;
V_121 = abs ( V_129 [ 0 ] - F_16 ( V_114 ) ) ;
for ( V_115 = 1 ; V_115 < F_17 ( V_129 ) ; ++ V_115 ) {
if ( abs ( V_129 [ V_115 ] - F_16 ( V_114 ) ) >= V_121 )
continue;
V_119 = V_115 ;
V_121 = abs ( V_129 [ V_115 ] - F_16 ( V_114 ) ) ;
}
F_18 ( V_80 -> V_2 , L_5 , V_129 [ V_119 ] ) ;
F_6 ( V_64 , V_11 ,
V_130 , V_119 << V_131 ) ;
F_18 ( V_80 -> V_2 , L_6 , V_117 -> V_122 ) ;
F_18 ( V_80 -> V_2 , L_7 , V_117 -> V_132 ) ;
for ( V_115 = 0 ; V_115 < F_17 ( V_133 ) ; ++ V_115 ) {
if ( V_117 -> V_132 / F_16 ( V_114 )
== V_133 [ V_115 ] . V_134 )
break;
}
if ( V_115 == F_17 ( V_133 ) ) {
F_11 ( V_80 -> V_2 , L_8 ,
V_117 -> V_132 , F_16 ( V_114 ) ) ;
return - V_70 ;
}
F_18 ( V_80 -> V_2 , L_9 , V_133 [ V_115 ] . V_134 ) ;
F_6 ( V_64 , V_10 ,
V_135 , V_115 << V_136 ) ;
V_120 = ( V_117 -> V_132 / V_133 [ V_115 ] . div ) * 10 ;
for ( V_115 = 0 ; V_115 < F_17 ( V_137 ) ; ++ V_115 ) {
if ( V_117 -> V_122 == V_120 / V_137 [ V_115 ] )
break;
}
if ( V_115 == F_17 ( V_137 ) ) {
F_11 ( V_80 -> V_2 , L_10 ) ;
return - V_70 ;
}
F_18 ( V_80 -> V_2 , L_11 , V_115 ) ;
F_6 ( V_64 , V_10 ,
V_138 , V_115 << V_139 ) ;
return 0 ;
}
static int F_19 ( struct V_140 * V_140 , unsigned int V_141 ,
unsigned int V_142 )
{
T_2 V_143 ;
unsigned long int V_144 , V_145 , V_146 ;
V_140 -> V_147 = 0 ;
V_145 = V_141 / V_142 ;
if ( V_145 < 6 ) {
V_142 >>= 1 ;
V_140 -> V_147 = 1 ;
V_145 = V_141 / V_142 ;
}
if ( V_145 < 6 || V_145 > 12 ) {
F_20 ( V_148 L_12
L_13 , V_149 , V_145 ) ;
return - V_70 ;
}
V_140 -> V_150 = V_145 ;
V_146 = V_141 % V_142 ;
V_143 = V_151 * ( T_2 ) V_146 ;
F_21 ( V_143 , V_142 ) ;
V_144 = V_143 & 0xffffffff ;
if ( ( V_144 % 10 ) >= 5 )
V_144 += 5 ;
V_144 /= 10 ;
V_140 -> V_152 = V_144 ;
return 0 ;
}
static int F_22 ( struct V_79 * V_80 , int V_153 ,
int V_142 , unsigned int V_154 ,
unsigned int V_155 )
{
int V_156 ;
struct V_63 * V_64 ;
struct V_140 V_140 ;
V_64 = V_80 -> V_64 ;
if ( V_154 && V_155 ) {
V_156 = F_19 ( & V_140 , V_155 * 4 * 2 , V_154 ) ;
if ( V_156 )
return V_156 ;
}
F_6 ( V_64 , V_5 ,
V_157 , 0 ) ;
if ( ! V_154 || ! V_155 )
return 0 ;
F_7 ( V_64 , V_36 ,
( V_140 . V_147 << V_158 )
| V_140 . V_150 ) ;
F_7 ( V_64 , V_39 , V_140 . V_152 & 0x1ff ) ;
F_7 ( V_64 , V_38 , ( V_140 . V_152 >> 9 ) & 0x1ff ) ;
F_7 ( V_64 , V_37 , ( V_140 . V_152 >> 18 ) ) ;
F_6 ( V_64 , V_10 ,
V_159 , V_160 ) ;
F_6 ( V_64 , V_5 ,
V_157 , V_161 ) ;
return 0 ;
}
static int F_23 ( struct V_79 * V_80 ,
int V_162 , unsigned int V_163 , int V_164 )
{
struct V_63 * V_64 ;
struct V_116 * V_117 ;
V_64 = V_80 -> V_64 ;
V_117 = F_13 ( V_64 ) ;
switch ( V_162 ) {
case V_165 :
F_6 ( V_64 , V_10 ,
V_159 , 0 ) ;
F_6 ( V_64 , V_5 ,
V_157 , 0 ) ;
break;
case V_166 :
F_6 ( V_64 , V_10 ,
V_159 , V_160 ) ;
break;
default:
F_11 ( V_80 -> V_2 , L_14 , V_162 ) ;
return - V_70 ;
}
V_117 -> V_132 = V_163 ;
return 0 ;
}
static int F_24 ( struct V_63 * V_64 ,
enum V_167 V_168 )
{
int V_156 ;
struct V_116 * V_117 ;
V_117 = F_13 ( V_64 ) ;
switch ( V_168 ) {
case V_169 :
case V_170 :
F_6 ( V_64 , V_5 ,
V_171 ,
1 << V_172 ) ;
break;
case V_173 :
if ( V_64 -> V_174 . V_175 == V_176 ) {
V_156 = F_25 ( F_17 ( V_117 -> V_177 ) ,
V_117 -> V_177 ) ;
if ( V_156 ) {
F_11 ( V_64 -> V_2 ,
L_15 ,
V_156 ) ;
return V_156 ;
}
F_26 ( V_117 -> V_178 ) ;
F_6 ( V_64 , V_41 ,
V_179 ,
V_180 ) ;
F_6 ( V_64 , V_48 ,
V_181 , V_182 ) ;
F_6 ( V_64 , V_48 ,
V_183 ,
V_184 ) ;
F_6 ( V_64 , V_5 ,
V_185 , V_186 ) ;
F_6 ( V_64 , V_5 ,
V_171 ,
1 << V_172 ) ;
F_27 ( 500 ) ;
F_6 ( V_64 , V_41 ,
V_179 , 0 ) ;
}
F_6 ( V_64 , V_5 ,
V_171 ,
2 << V_172 ) ;
break;
case V_176 :
F_6 ( V_64 , V_48 ,
V_183 , 0 ) ;
F_6 ( V_64 , V_48 ,
V_181 , 0 ) ;
F_6 ( V_64 , V_5 ,
V_171 | V_185 ,
0 ) ;
F_7 ( V_64 , V_5 , 0 ) ;
F_7 ( V_64 , V_6 , 0 ) ;
F_7 ( V_64 , V_7 , 0 ) ;
F_28 ( V_117 -> V_178 ) ;
F_29 ( F_17 ( V_117 -> V_177 ) ,
V_117 -> V_177 ) ;
break;
}
V_64 -> V_174 . V_175 = V_168 ;
return 0 ;
}
static int F_30 ( struct V_63 * V_64 )
{
F_24 ( V_64 , V_176 ) ;
return 0 ;
}
static int F_31 ( struct V_63 * V_64 )
{
F_24 ( V_64 , V_173 ) ;
return 0 ;
}
static int F_32 ( struct V_63 * V_64 )
{
struct V_116 * V_117 ;
V_117 = F_13 ( V_64 ) ;
F_24 ( V_64 , V_176 ) ;
F_33 ( F_17 ( V_117 -> V_177 ) , V_117 -> V_177 ) ;
return 0 ;
}
static int F_34 ( struct V_63 * V_64 )
{
T_3 V_115 ;
struct V_116 * V_117 ;
int V_156 ;
V_117 = F_13 ( V_64 ) ;
V_64 -> V_187 = V_117 -> V_178 ;
V_156 = F_35 ( V_64 , 7 , 9 , V_188 ) ;
if ( V_156 < 0 ) {
F_11 ( V_64 -> V_2 , L_16 , V_156 ) ;
return V_156 ;
}
for ( V_115 = 0 ; V_115 < F_17 ( V_117 -> V_177 ) ; V_115 ++ )
V_117 -> V_177 [ V_115 ] . V_189 = V_190 [ V_115 ] ;
V_156 = F_36 ( V_64 -> V_2 , F_17 ( V_117 -> V_177 ) ,
V_117 -> V_177 ) ;
if ( V_156 ) {
F_11 ( V_64 -> V_2 , L_17 , V_156 ) ;
return V_156 ;
}
V_156 = F_25 ( F_17 ( V_117 -> V_177 ) ,
V_117 -> V_177 ) ;
if ( V_156 ) {
F_11 ( V_64 -> V_2 , L_15 , V_156 ) ;
goto V_191;
}
V_156 = F_8 ( V_64 ) ;
if ( V_156 < 0 ) {
F_11 ( V_64 -> V_2 , L_18 , V_156 ) ;
goto V_192;
}
for ( V_115 = 0 ; V_115 < F_17 ( V_193 ) ; ++ V_115 )
F_6 ( V_64 , V_193 [ V_115 ] ,
0x100 , 0x100 ) ;
F_6 ( V_64 , V_58 , V_194 ,
V_194 ) ;
F_24 ( V_64 , V_173 ) ;
return 0 ;
V_192:
F_29 ( F_17 ( V_117 -> V_177 ) , V_117 -> V_177 ) ;
V_191:
F_33 ( F_17 ( V_117 -> V_177 ) , V_117 -> V_177 ) ;
return V_156 ;
}
static int T_4 F_37 ( struct V_195 * V_196 )
{
struct V_116 * V_117 ;
int V_156 ;
V_117 = F_38 ( & V_196 -> V_2 , sizeof *V_117 , V_197 ) ;
if ( ! V_117 )
return - V_198 ;
F_39 ( V_196 , V_117 ) ;
V_117 -> V_178 = F_40 ( V_196 , & V_199 ) ;
if ( F_41 ( V_117 -> V_178 ) ) {
V_156 = F_42 ( V_117 -> V_178 ) ;
F_11 ( & V_196 -> V_2 , L_19 ,
V_156 ) ;
goto V_200;
}
V_156 = F_43 ( & V_196 -> V_2 ,
& V_201 , & V_202 , 1 ) ;
if ( V_156 != 0 )
goto V_200;
return 0 ;
V_200:
F_44 ( V_117 -> V_178 ) ;
return V_156 ;
}
static int T_5 F_45 ( struct V_195 * V_196 )
{
struct V_116 * V_117 = F_46 ( V_196 ) ;
F_47 ( & V_196 -> V_2 ) ;
F_44 ( V_117 -> V_178 ) ;
return 0 ;
}
static T_4 int F_48 ( struct V_203 * V_204 ,
const struct V_205 * V_206 )
{
struct V_116 * V_117 ;
int V_156 ;
V_117 = F_38 ( & V_204 -> V_2 , sizeof *V_117 , V_197 ) ;
if ( ! V_117 )
return - V_198 ;
F_49 ( V_204 , V_117 ) ;
V_117 -> V_178 = F_50 ( V_204 , & V_199 ) ;
if ( F_41 ( V_117 -> V_178 ) ) {
V_156 = F_42 ( V_117 -> V_178 ) ;
F_11 ( & V_204 -> V_2 , L_19 ,
V_156 ) ;
goto V_200;
}
V_156 = F_43 ( & V_204 -> V_2 ,
& V_201 , & V_202 , 1 ) ;
if ( V_156 != 0 )
goto V_200;
return 0 ;
V_200:
F_44 ( V_117 -> V_178 ) ;
return V_156 ;
}
static T_5 int F_51 ( struct V_203 * V_204 )
{
struct V_116 * V_117 = F_52 ( V_204 ) ;
F_47 ( & V_204 -> V_2 ) ;
F_44 ( V_117 -> V_178 ) ;
return 0 ;
}
static int T_6 F_53 ( void )
{
int V_156 = 0 ;
#if F_54 ( V_207 ) || F_54 ( V_208 )
V_156 = F_55 ( & V_209 ) ;
if ( V_156 ) {
F_20 ( V_148 L_20 ,
V_156 ) ;
}
#endif
#if F_54 ( V_210 )
V_156 = F_56 ( & V_211 ) ;
if ( V_156 != 0 ) {
F_20 ( V_148 L_21 ,
V_156 ) ;
}
#endif
return V_156 ;
}
static void T_7 F_57 ( void )
{
#if F_54 ( V_207 ) || F_54 ( V_208 )
F_58 ( & V_209 ) ;
#endif
#if F_54 ( V_210 )
F_59 ( & V_211 ) ;
#endif
}
