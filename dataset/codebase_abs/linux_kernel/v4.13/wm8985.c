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
static int F_2 ( struct V_59 * V_60 )
{
struct V_61 * V_62 = F_3 ( V_60 ) ;
struct V_63 * V_64 = F_4 ( V_60 ) ;
switch ( V_62 -> V_65 ) {
case V_66 :
F_5 ( V_64 , V_67 ,
F_6 ( V_67 ) ) ;
break;
case V_68 :
F_7 ( V_60 , V_69 ,
F_6 ( V_69 ) ) ;
F_5 ( V_64 , V_70 ,
F_6 ( V_70 ) ) ;
F_8 ( V_64 , V_71 ,
F_6 ( V_71 ) ) ;
break;
}
return 0 ;
}
static int F_9 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_59 * V_60 = F_10 ( V_73 ) ;
unsigned int V_3 ;
V_3 = F_11 ( V_60 , V_21 ) ;
if ( V_3 & V_76 )
V_75 -> V_77 . V_78 . V_79 [ 0 ] = 1 ;
else
V_75 -> V_77 . V_78 . V_79 [ 0 ] = 0 ;
return 0 ;
}
static int F_12 ( struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_59 * V_60 = F_10 ( V_73 ) ;
unsigned int V_80 , V_81 ;
unsigned int V_82 ;
if ( V_75 -> V_77 . V_78 . V_79 [ 0 ] != 0
&& V_75 -> V_77 . V_78 . V_79 [ 0 ] != 1 )
return - V_83 ;
V_82 = F_11 ( V_60 , V_21 ) ;
switch ( ( V_82 & V_76 ) >> V_84 ) {
case 0 :
if ( ! V_75 -> V_77 . V_78 . V_79 [ 0 ] )
return 0 ;
break;
case 1 :
if ( V_75 -> V_77 . V_78 . V_79 [ 0 ] )
return 0 ;
break;
}
V_80 = F_11 ( V_60 , V_6 ) ;
V_81 = F_11 ( V_60 , V_7 ) ;
F_13 ( V_60 , V_6 ,
V_85 | V_86 , 0 ) ;
F_13 ( V_60 , V_7 ,
V_87 | V_88 , 0 ) ;
F_13 ( V_60 , V_11 ,
V_89 , V_90 ) ;
F_13 ( V_60 , V_21 ,
V_91 ,
V_75 -> V_77 . V_78 . V_79 [ 0 ]
<< V_84 ) ;
F_14 ( V_60 , V_6 , V_80 ) ;
F_14 ( V_60 , V_7 , V_81 ) ;
return 0 ;
}
static int F_15 ( struct V_59 * V_60 )
{
return F_14 ( V_60 , V_4 , 0x0 ) ;
}
static int F_16 ( struct V_92 * V_93 , int V_94 )
{
struct V_59 * V_60 = V_93 -> V_60 ;
return F_13 ( V_60 , V_14 ,
V_95 ,
! ! V_94 << V_96 ) ;
}
static int F_17 ( struct V_92 * V_93 , unsigned int V_97 )
{
struct V_59 * V_60 ;
T_1 V_98 , V_99 , V_100 , V_101 ;
V_60 = V_93 -> V_60 ;
switch ( V_97 & V_102 ) {
case V_103 :
V_98 = 0x2 ;
break;
case V_104 :
V_98 = 0x0 ;
break;
case V_105 :
V_98 = 0x1 ;
break;
case V_106 :
case V_107 :
V_98 = 0x3 ;
break;
default:
F_18 ( V_93 -> V_2 , L_1 ) ;
return - V_83 ;
}
F_13 ( V_60 , V_8 ,
V_108 , V_98 << V_109 ) ;
switch ( V_97 & V_110 ) {
case V_111 :
V_99 = 1 ;
break;
case V_112 :
V_99 = 0 ;
break;
default:
F_18 ( V_93 -> V_2 , L_2 ) ;
return - V_83 ;
}
F_13 ( V_60 , V_10 ,
V_113 , V_99 << V_114 ) ;
switch ( V_97 & V_102 ) {
case V_106 :
case V_107 :
switch ( V_97 & V_115 ) {
case V_116 :
case V_117 :
return - V_83 ;
default:
break;
}
break;
default:
break;
}
V_100 = V_101 = 0 ;
switch ( V_97 & V_115 ) {
case V_118 :
break;
case V_116 :
V_100 = V_101 = 1 ;
break;
case V_119 :
V_100 = 1 ;
break;
case V_117 :
V_101 = 1 ;
break;
default:
F_18 ( V_93 -> V_2 , L_3 ) ;
return - V_83 ;
}
F_13 ( V_60 , V_8 ,
V_120 , V_101 << V_121 ) ;
F_13 ( V_60 , V_8 ,
V_122 , V_100 << V_123 ) ;
return 0 ;
}
static int F_19 ( struct V_124 * V_125 ,
struct V_126 * V_127 ,
struct V_92 * V_93 )
{
int V_128 ;
struct V_59 * V_60 ;
struct V_61 * V_62 ;
T_1 V_129 , V_130 ;
unsigned int V_131 ;
int V_132 ;
V_60 = V_93 -> V_60 ;
V_62 = F_3 ( V_60 ) ;
V_62 -> V_133 = F_20 ( V_127 ) ;
if ( ( int ) V_62 -> V_133 < 0 )
return V_62 -> V_133 ;
switch ( F_21 ( V_127 ) ) {
case 16 :
V_129 = 0x0 ;
break;
case 20 :
V_129 = 0x1 ;
break;
case 24 :
V_129 = 0x2 ;
break;
case 32 :
V_129 = 0x3 ;
break;
default:
F_18 ( V_93 -> V_2 , L_4 ,
F_21 ( V_127 ) ) ;
return - V_83 ;
}
F_13 ( V_60 , V_8 ,
V_134 , V_129 << V_135 ) ;
V_130 = 0 ;
V_132 = abs ( V_136 [ 0 ] - F_22 ( V_127 ) ) ;
for ( V_128 = 1 ; V_128 < F_6 ( V_136 ) ; ++ V_128 ) {
if ( abs ( V_136 [ V_128 ] - F_22 ( V_127 ) ) >= V_132 )
continue;
V_130 = V_128 ;
V_132 = abs ( V_136 [ V_128 ] - F_22 ( V_127 ) ) ;
}
F_23 ( V_93 -> V_2 , L_5 , V_136 [ V_130 ] ) ;
F_13 ( V_60 , V_11 ,
V_137 , V_130 << V_138 ) ;
F_23 ( V_93 -> V_2 , L_6 , V_62 -> V_133 ) ;
F_23 ( V_93 -> V_2 , L_7 , V_62 -> V_139 ) ;
for ( V_128 = 0 ; V_128 < F_6 ( V_140 ) ; ++ V_128 ) {
if ( V_62 -> V_139 / F_22 ( V_127 )
== V_140 [ V_128 ] . V_141 )
break;
}
if ( V_128 == F_6 ( V_140 ) ) {
F_18 ( V_93 -> V_2 , L_8 ,
V_62 -> V_139 , F_22 ( V_127 ) ) ;
return - V_83 ;
}
F_23 ( V_93 -> V_2 , L_9 , V_140 [ V_128 ] . V_141 ) ;
F_13 ( V_60 , V_10 ,
V_142 , V_128 << V_143 ) ;
V_131 = ( V_62 -> V_139 / V_140 [ V_128 ] . div ) * 10 ;
for ( V_128 = 0 ; V_128 < F_6 ( V_144 ) ; ++ V_128 ) {
if ( V_62 -> V_133 == V_131 / V_144 [ V_128 ] )
break;
}
if ( V_128 == F_6 ( V_144 ) ) {
F_18 ( V_93 -> V_2 , L_10 ) ;
return - V_83 ;
}
F_23 ( V_93 -> V_2 , L_11 , V_128 ) ;
F_13 ( V_60 , V_10 ,
V_145 , V_128 << V_146 ) ;
return 0 ;
}
static int F_24 ( struct V_147 * V_147 , unsigned int V_148 ,
unsigned int V_149 )
{
T_2 V_150 ;
unsigned long int V_151 , V_152 , V_153 ;
V_147 -> V_154 = 0 ;
V_152 = V_148 / V_149 ;
if ( V_152 < 6 ) {
V_149 >>= 1 ;
V_147 -> V_154 = 1 ;
V_152 = V_148 / V_149 ;
}
if ( V_152 < 6 || V_152 > 12 ) {
F_25 ( V_155 L_12
L_13 , V_156 , V_152 ) ;
return - V_83 ;
}
V_147 -> V_157 = V_152 ;
V_153 = V_148 % V_149 ;
V_150 = V_158 * ( T_2 ) V_153 ;
F_26 ( V_150 , V_149 ) ;
V_151 = V_150 & 0xffffffff ;
if ( ( V_151 % 10 ) >= 5 )
V_151 += 5 ;
V_151 /= 10 ;
V_147 -> V_159 = V_151 ;
return 0 ;
}
static int F_27 ( struct V_92 * V_93 , int V_160 ,
int V_149 , unsigned int V_161 ,
unsigned int V_162 )
{
int V_163 ;
struct V_59 * V_60 ;
struct V_147 V_147 ;
V_60 = V_93 -> V_60 ;
if ( ! V_161 || ! V_162 ) {
F_13 ( V_60 , V_5 ,
V_164 , 0 ) ;
} else {
V_163 = F_24 ( & V_147 , V_162 * 4 * 2 , V_161 ) ;
if ( V_163 )
return V_163 ;
F_14 ( V_60 , V_36 ,
( V_147 . V_154 << V_165 )
| V_147 . V_157 ) ;
F_14 ( V_60 , V_39 , V_147 . V_159 & 0x1ff ) ;
F_14 ( V_60 , V_38 , ( V_147 . V_159 >> 9 ) & 0x1ff ) ;
F_14 ( V_60 , V_37 , ( V_147 . V_159 >> 18 ) ) ;
F_13 ( V_60 , V_10 ,
V_166 , V_167 ) ;
F_13 ( V_60 , V_5 ,
V_164 , V_168 ) ;
}
return 0 ;
}
static int F_28 ( struct V_92 * V_93 ,
int V_169 , unsigned int V_170 , int V_171 )
{
struct V_59 * V_60 ;
struct V_61 * V_62 ;
V_60 = V_93 -> V_60 ;
V_62 = F_3 ( V_60 ) ;
switch ( V_169 ) {
case V_172 :
F_13 ( V_60 , V_10 ,
V_166 , 0 ) ;
F_13 ( V_60 , V_5 ,
V_164 , 0 ) ;
break;
case V_173 :
F_13 ( V_60 , V_10 ,
V_166 , V_167 ) ;
break;
default:
F_18 ( V_93 -> V_2 , L_14 , V_169 ) ;
return - V_83 ;
}
V_62 -> V_139 = V_170 ;
return 0 ;
}
static int F_29 ( struct V_59 * V_60 ,
enum V_174 V_175 )
{
int V_163 ;
struct V_61 * V_62 ;
V_62 = F_3 ( V_60 ) ;
switch ( V_175 ) {
case V_176 :
case V_177 :
F_13 ( V_60 , V_5 ,
V_178 ,
1 << V_179 ) ;
break;
case V_180 :
if ( F_30 ( V_60 ) == V_181 ) {
V_163 = F_31 ( F_6 ( V_62 -> V_182 ) ,
V_62 -> V_182 ) ;
if ( V_163 ) {
F_18 ( V_60 -> V_2 ,
L_15 ,
V_163 ) ;
return V_163 ;
}
F_32 ( V_62 -> V_183 ) ;
F_13 ( V_60 , V_41 ,
V_184 ,
V_185 ) ;
F_13 ( V_60 , V_48 ,
V_186 , V_187 ) ;
F_13 ( V_60 , V_48 ,
V_188 ,
V_189 ) ;
F_13 ( V_60 , V_5 ,
V_190 , V_191 ) ;
F_13 ( V_60 , V_5 ,
V_178 ,
1 << V_179 ) ;
F_33 ( 500 ) ;
F_13 ( V_60 , V_41 ,
V_184 , 0 ) ;
}
F_13 ( V_60 , V_5 ,
V_178 ,
2 << V_179 ) ;
break;
case V_181 :
F_13 ( V_60 , V_48 ,
V_188 , 0 ) ;
F_13 ( V_60 , V_48 ,
V_186 , 0 ) ;
F_13 ( V_60 , V_5 ,
V_178 | V_190 ,
0 ) ;
F_14 ( V_60 , V_5 , 0 ) ;
F_14 ( V_60 , V_6 , 0 ) ;
F_14 ( V_60 , V_7 , 0 ) ;
F_34 ( V_62 -> V_183 ) ;
F_35 ( F_6 ( V_62 -> V_182 ) ,
V_62 -> V_182 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_59 * V_60 )
{
T_3 V_128 ;
struct V_61 * V_62 ;
int V_163 ;
V_62 = F_3 ( V_60 ) ;
for ( V_128 = 0 ; V_128 < F_6 ( V_62 -> V_182 ) ; V_128 ++ )
V_62 -> V_182 [ V_128 ] . V_192 = V_193 [ V_128 ] ;
V_163 = F_37 ( V_60 -> V_2 , F_6 ( V_62 -> V_182 ) ,
V_62 -> V_182 ) ;
if ( V_163 ) {
F_18 ( V_60 -> V_2 , L_16 , V_163 ) ;
return V_163 ;
}
V_163 = F_31 ( F_6 ( V_62 -> V_182 ) ,
V_62 -> V_182 ) ;
if ( V_163 ) {
F_18 ( V_60 -> V_2 , L_15 , V_163 ) ;
return V_163 ;
}
V_163 = F_15 ( V_60 ) ;
if ( V_163 < 0 ) {
F_18 ( V_60 -> V_2 , L_17 , V_163 ) ;
goto V_194;
}
for ( V_128 = 0 ; V_128 < F_6 ( V_195 ) ; ++ V_128 )
F_13 ( V_60 , V_195 [ V_128 ] ,
0x100 , 0x100 ) ;
F_13 ( V_60 , V_58 , V_196 ,
V_196 ) ;
F_2 ( V_60 ) ;
return 0 ;
V_194:
F_35 ( F_6 ( V_62 -> V_182 ) , V_62 -> V_182 ) ;
return V_163 ;
}
static int F_38 ( struct V_197 * V_198 )
{
struct V_61 * V_62 ;
int V_163 ;
V_62 = F_39 ( & V_198 -> V_2 , sizeof *V_62 , V_199 ) ;
if ( ! V_62 )
return - V_200 ;
F_40 ( V_198 , V_62 ) ;
V_62 -> V_65 = V_68 ;
V_62 -> V_183 = F_41 ( V_198 , & V_201 ) ;
if ( F_42 ( V_62 -> V_183 ) ) {
V_163 = F_43 ( V_62 -> V_183 ) ;
F_18 ( & V_198 -> V_2 , L_18 ,
V_163 ) ;
return V_163 ;
}
V_163 = F_44 ( & V_198 -> V_2 ,
& V_202 , & V_203 , 1 ) ;
return V_163 ;
}
static int F_45 ( struct V_197 * V_198 )
{
F_46 ( & V_198 -> V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_204 * V_205 ,
const struct V_206 * V_207 )
{
struct V_61 * V_62 ;
int V_163 ;
V_62 = F_39 ( & V_205 -> V_2 , sizeof *V_62 , V_199 ) ;
if ( ! V_62 )
return - V_200 ;
F_48 ( V_205 , V_62 ) ;
V_62 -> V_65 = V_207 -> V_208 ;
V_62 -> V_183 = F_49 ( V_205 , & V_201 ) ;
if ( F_42 ( V_62 -> V_183 ) ) {
V_163 = F_43 ( V_62 -> V_183 ) ;
F_18 ( & V_205 -> V_2 , L_18 ,
V_163 ) ;
return V_163 ;
}
V_163 = F_44 ( & V_205 -> V_2 ,
& V_202 , & V_203 , 1 ) ;
return V_163 ;
}
static int F_50 ( struct V_204 * V_205 )
{
F_46 ( & V_205 -> V_2 ) ;
return 0 ;
}
static int T_4 F_51 ( void )
{
int V_163 = 0 ;
#if F_52 ( V_209 )
V_163 = F_53 ( & V_210 ) ;
if ( V_163 ) {
F_25 ( V_155 L_19 ,
V_163 ) ;
}
#endif
#if F_54 ( V_211 )
V_163 = F_55 ( & V_212 ) ;
if ( V_163 != 0 ) {
F_25 ( V_155 L_20 ,
V_163 ) ;
}
#endif
return V_163 ;
}
static void T_5 F_56 ( void )
{
#if F_52 ( V_209 )
F_57 ( & V_210 ) ;
#endif
#if F_54 ( V_211 )
F_58 ( & V_212 ) ;
#endif
}
