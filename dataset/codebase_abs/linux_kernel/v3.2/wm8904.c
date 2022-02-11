static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return V_4 [ V_3 ] . V_5 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_6 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
unsigned int V_9 , V_10 , V_11 ;
V_10 = F_6 ( V_2 , V_12 ) ;
F_7 ( V_2 , V_12 ,
V_13 , 0 ) ;
switch ( V_8 -> V_14 ) {
case V_15 :
F_8 ( V_2 -> V_16 , L_1 , V_8 -> V_17 ) ;
V_10 &= ~ V_13 ;
V_11 = V_8 -> V_17 ;
F_7 ( V_2 , V_18 ,
V_19 | V_20 , 0 ) ;
break;
case V_21 :
F_8 ( V_2 -> V_16 , L_2 ,
V_8 -> V_22 ) ;
V_10 |= V_13 ;
V_11 = V_8 -> V_22 ;
break;
default:
F_9 ( V_2 -> V_16 , L_3 ) ;
return - V_23 ;
}
if ( V_11 > 13500000 ) {
V_9 = V_24 ;
V_8 -> V_25 = V_11 / 2 ;
} else {
V_9 = 0 ;
V_8 -> V_25 = V_11 ;
}
F_7 ( V_2 , V_26 , V_24 ,
V_9 ) ;
F_7 ( V_2 , V_12 ,
V_27 | V_13 , V_10 ) ;
F_8 ( V_2 -> V_16 , L_4 , V_8 -> V_25 ) ;
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
int V_30 , V_31 ;
V_30 = F_6 ( V_2 , V_32 ) ;
for ( V_31 = 0 ; V_31 < V_33 ; V_31 ++ )
F_7 ( V_2 , V_32 + V_31 , 0xffff ,
V_29 -> V_34 [ V_8 -> V_35 ] . V_36 [ V_31 ] ) ;
F_7 ( V_2 , V_32 ,
V_37 | V_38 , V_30 ) ;
}
static int F_11 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_12 ( V_40 ) ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
int V_43 = V_42 -> V_43 . integer . V_43 [ 0 ] ;
if ( V_43 >= V_29 -> V_44 )
return - V_23 ;
V_8 -> V_35 = V_43 ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_13 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_12 ( V_40 ) ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
V_42 -> V_43 . V_45 . V_46 [ 0 ] = V_8 -> V_35 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
int V_47 , V_48 , V_30 , V_31 , V_49 ;
if ( ! V_29 || ! V_8 -> V_50 )
return;
V_49 = V_8 -> V_51 ;
V_47 = 0 ;
V_48 = V_52 ;
for ( V_31 = 0 ; V_31 < V_29 -> V_53 ; V_31 ++ ) {
if ( strcmp ( V_29 -> V_54 [ V_31 ] . V_55 ,
V_8 -> V_56 [ V_49 ] ) == 0 &&
abs ( V_29 -> V_54 [ V_31 ] . V_11
- V_8 -> V_57 ) < V_48 ) {
V_47 = V_31 ;
V_48 = abs ( V_29 -> V_54 [ V_31 ] . V_11
- V_8 -> V_57 ) ;
}
}
F_8 ( V_2 -> V_16 , L_5 ,
V_29 -> V_54 [ V_47 ] . V_55 ,
V_29 -> V_54 [ V_47 ] . V_11 ,
V_8 -> V_57 ) ;
V_30 = F_6 ( V_2 , V_58 ) ;
for ( V_31 = 0 ; V_31 < V_59 ; V_31 ++ )
F_7 ( V_2 , V_58 + V_31 , 0xffff ,
V_29 -> V_54 [ V_47 ] . V_36 [ V_31 ] ) ;
F_7 ( V_2 , V_58 , V_60 , V_30 ) ;
}
static int F_15 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_12 ( V_40 ) ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
int V_43 = V_42 -> V_43 . integer . V_43 [ 0 ] ;
if ( V_43 >= V_29 -> V_53 )
return - V_23 ;
V_8 -> V_51 = V_43 ;
F_14 ( V_2 ) ;
return 0 ;
}
static int F_16 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_12 ( V_40 ) ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
V_42 -> V_43 . V_45 . V_46 [ 0 ] = V_8 -> V_51 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_61 , V_31 , V_47 ;
if ( V_8 -> V_62 ) {
V_47 = 1 ;
for ( V_31 = 2 ; V_31 < F_18 ( V_63 ) ; V_31 ++ ) {
if ( abs ( V_63 [ V_31 ] - V_8 -> V_57 ) <
abs ( V_63 [ V_47 ] - V_8 -> V_57 ) )
V_47 = V_31 ;
}
V_61 = V_47 << V_64 ;
} else {
V_61 = 0 ;
}
F_8 ( V_2 -> V_16 , L_6 , V_61 ) ;
return F_7 ( V_2 , V_65 ,
V_66 , V_61 ) ;
}
static int F_19 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_12 ( V_40 ) ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
V_42 -> V_43 . V_45 . V_46 [ 0 ] = V_8 -> V_62 ;
return 0 ;
}
static int F_20 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_1 * V_2 = F_12 ( V_40 ) ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_62 = V_42 -> V_43 . V_45 . V_46 [ 0 ] ;
if ( V_62 > 1 )
return - V_23 ;
V_8 -> V_62 = V_62 ;
return F_17 ( V_2 ) ;
}
static int F_21 ( struct V_67 * V_68 ,
struct V_39 * V_40 , int V_69 )
{
F_22 ( V_69 != V_70 ) ;
F_23 ( 500 ) ;
return 0 ;
}
static int F_24 ( struct V_67 * V_68 ,
struct V_39 * V_40 , int V_69 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
switch ( V_69 ) {
case V_71 :
switch ( V_8 -> V_14 ) {
case V_21 :
F_7 ( V_2 , V_18 ,
V_19 ,
V_19 ) ;
F_7 ( V_2 , V_18 ,
V_20 ,
V_20 ) ;
break;
default:
break;
}
break;
case V_72 :
F_7 ( V_2 , V_18 ,
V_19 | V_20 , 0 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_67 * V_68 ,
struct V_39 * V_40 , int V_69 )
{
struct V_1 * V_2 = V_68 -> V_2 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_3 , V_61 ;
int V_73 ;
int V_74 , V_75 ;
int V_76 , V_77 ;
int V_78 ;
int V_79 ;
V_3 = V_68 -> V_80 ;
switch ( V_3 ) {
case V_81 :
V_79 = V_82 ;
V_73 = V_83 | V_84 ;
V_77 = V_85 ;
V_76 = V_86 ;
V_74 = 0 ;
V_75 = 1 ;
break;
case V_87 :
V_79 = V_88 ;
V_73 = V_89 | V_90 ;
V_77 = V_91 ;
V_76 = V_92 ;
V_74 = 2 ;
V_75 = 3 ;
break;
default:
F_26 () ;
return - V_23 ;
}
switch ( V_69 ) {
case V_71 :
F_7 ( V_2 , V_79 ,
V_93 | V_94 ,
V_93 | V_94 ) ;
F_7 ( V_2 , V_3 ,
V_95 | V_96 ,
V_95 | V_96 ) ;
F_7 ( V_2 , V_3 ,
V_97 | V_98 ,
V_97 | V_98 ) ;
F_7 ( V_2 , V_99 ,
V_73 , V_73 ) ;
if ( V_8 -> V_100 [ V_74 ] || V_8 -> V_100 [ V_75 ] ) {
F_8 ( V_2 -> V_16 , L_7 ) ;
F_3 ( V_2 , V_76 ,
V_8 -> V_100 [ V_74 ] ) ;
F_3 ( V_2 , V_77 ,
V_8 -> V_100 [ V_75 ] ) ;
F_3 ( V_2 , V_101 , V_73 ) ;
V_78 = 20 ;
} else {
F_8 ( V_2 -> V_16 , L_8 ) ;
F_3 ( V_2 , V_101 ,
V_73 << V_102 ) ;
V_78 = 500 ;
}
V_73 <<= V_103 ;
do {
V_61 = F_6 ( V_2 , V_104 ) ;
if ( ( V_61 & V_73 ) == V_73 )
break;
F_27 ( 1 ) ;
} while ( -- V_78 );
if ( ( V_61 & V_73 ) != V_73 )
F_28 ( V_2 -> V_16 , L_9 ) ;
else
F_8 ( V_2 -> V_16 , L_10 ) ;
F_7 ( V_2 , V_3 ,
V_105 | V_106 ,
V_105 | V_106 ) ;
break;
case V_70 :
F_7 ( V_2 , V_3 ,
V_107 |
V_108 ,
V_107 |
V_108 ) ;
break;
case V_109 :
F_7 ( V_2 , V_3 ,
V_107 |
V_108 , 0 ) ;
break;
case V_72 :
V_8 -> V_100 [ V_74 ] = F_6 ( V_2 , V_76 ) ;
V_8 -> V_100 [ V_75 ] = F_6 ( V_2 , V_77 ) ;
F_7 ( V_2 , V_99 ,
V_73 , 0 ) ;
F_7 ( V_2 , V_3 ,
V_95 | V_96 |
V_97 | V_98 |
V_105 | V_106 ,
0 ) ;
F_7 ( V_2 , V_79 ,
V_93 | V_94 ,
0 ) ;
break;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_110 * V_111 = & V_2 -> V_111 ;
F_30 ( V_111 , V_112 ,
F_18 ( V_112 ) ) ;
F_31 ( V_111 , V_113 ,
F_18 ( V_113 ) ) ;
switch ( V_8 -> V_114 ) {
case V_115 :
F_32 ( V_2 , V_116 ,
F_18 ( V_116 ) ) ;
F_32 ( V_2 , V_117 ,
F_18 ( V_117 ) ) ;
F_32 ( V_2 , V_118 ,
F_18 ( V_118 ) ) ;
F_30 ( V_111 , V_119 ,
F_18 ( V_119 ) ) ;
F_30 ( V_111 , V_120 ,
F_18 ( V_120 ) ) ;
F_30 ( V_111 , V_121 ,
F_18 ( V_121 ) ) ;
F_31 ( V_111 , V_113 ,
F_18 ( V_113 ) ) ;
F_31 ( V_111 , V_122 ,
F_18 ( V_122 ) ) ;
F_31 ( V_111 , V_123 ,
F_18 ( V_123 ) ) ;
F_31 ( V_111 , V_124 ,
F_18 ( V_124 ) ) ;
break;
case V_125 :
F_32 ( V_2 , V_117 ,
F_18 ( V_117 ) ) ;
F_30 ( V_111 , V_120 ,
F_18 ( V_120 ) ) ;
F_31 ( V_111 , V_123 ,
F_18 ( V_123 ) ) ;
F_31 ( V_111 , V_126 ,
F_18 ( V_126 ) ) ;
break;
}
F_33 ( V_111 ) ;
return 0 ;
}
static int F_34 ( struct V_127 * V_128 ,
struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_133 , V_31 , V_47 , V_48 , V_134 ;
unsigned int V_135 = 0 ;
unsigned int V_136 = 0 ;
unsigned int V_137 = 0 ;
unsigned int V_138 = 0 ;
unsigned int V_139 = 0 ;
V_8 -> V_57 = F_35 ( V_130 ) ;
if ( V_8 -> V_140 ) {
F_8 ( V_2 -> V_16 , L_11 ,
V_8 -> V_140 , V_8 -> V_141 ) ;
V_8 -> V_142 = F_36 ( V_8 -> V_57 ,
V_8 -> V_141 , 2 ,
V_8 -> V_140 ) ;
} else {
V_8 -> V_142 = F_37 ( V_130 ) ;
}
switch ( F_38 ( V_130 ) ) {
case V_143 :
break;
case V_144 :
V_135 |= 0x40 ;
break;
case V_145 :
V_135 |= 0x80 ;
break;
case V_146 :
V_135 |= 0xc0 ;
break;
default:
return - V_23 ;
}
F_8 ( V_2 -> V_16 , L_12 , V_8 -> V_142 ) ;
V_133 = F_4 ( V_2 ) ;
if ( V_133 != 0 )
return V_133 ;
V_47 = 0 ;
V_48 = abs ( ( V_8 -> V_25 / V_147 [ 0 ] . V_148 )
- V_8 -> V_57 ) ;
for ( V_31 = 1 ; V_31 < F_18 ( V_147 ) ; V_31 ++ ) {
V_134 = abs ( ( V_8 -> V_25 /
V_147 [ V_31 ] . V_148 ) - V_8 -> V_57 ) ;
if ( V_134 < V_48 ) {
V_47 = V_31 ;
V_48 = V_134 ;
}
}
F_8 ( V_2 -> V_16 , L_13 ,
V_147 [ V_47 ] . V_148 ) ;
V_138 |= ( V_147 [ V_47 ] . V_149
<< V_150 ) ;
V_47 = 0 ;
V_48 = abs ( V_8 -> V_57 - V_151 [ 0 ] . V_11 ) ;
for ( V_31 = 1 ; V_31 < F_18 ( V_151 ) ; V_31 ++ ) {
V_134 = abs ( V_8 -> V_57 - V_151 [ V_31 ] . V_11 ) ;
if ( V_134 < V_48 ) {
V_47 = V_31 ;
V_48 = V_134 ;
}
}
F_8 ( V_2 -> V_16 , L_14 ,
V_151 [ V_47 ] . V_11 ) ;
V_138 |= ( V_151 [ V_47 ] . V_152
<< V_153 ) ;
if ( V_8 -> V_57 <= 24000 )
V_139 |= V_154 ;
V_47 = 0 ;
V_48 = V_52 ;
for ( V_31 = 0 ; V_31 < F_18 ( V_155 ) ; V_31 ++ ) {
V_134 = ( ( V_8 -> V_25 * 10 ) / V_155 [ V_31 ] . div )
- V_8 -> V_142 ;
if ( V_134 < 0 )
break;
if ( V_134 < V_48 ) {
V_47 = V_31 ;
V_48 = V_134 ;
}
}
V_8 -> V_142 = ( V_8 -> V_25 * 10 ) / V_155 [ V_47 ] . div ;
F_8 ( V_2 -> V_16 , L_15 ,
V_155 [ V_47 ] . div , V_8 -> V_142 ) ;
V_136 |= V_155 [ V_47 ] . V_156 ;
F_8 ( V_2 -> V_16 , L_16 , V_8 -> V_142 / V_8 -> V_57 ) ;
V_137 |= V_8 -> V_142 / V_8 -> V_57 ;
F_7 ( V_2 , V_65 ,
V_154 , V_139 ) ;
F_7 ( V_2 , V_157 ,
V_158 , V_135 ) ;
F_7 ( V_2 , V_159 ,
V_160 , V_136 ) ;
F_7 ( V_2 , V_161 ,
V_162 , V_137 ) ;
F_7 ( V_2 , V_163 ,
V_164 |
V_165 , V_138 ) ;
F_14 ( V_2 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_131 * V_132 , int V_166 ,
unsigned int V_167 , int V_168 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_7 * V_169 = F_5 ( V_2 ) ;
switch ( V_166 ) {
case V_15 :
V_169 -> V_14 = V_166 ;
V_169 -> V_17 = V_167 ;
break;
case V_21 :
V_169 -> V_14 = V_166 ;
break;
default:
return - V_23 ;
}
F_8 ( V_132 -> V_16 , L_17 , V_166 , V_167 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_40 ( struct V_131 * V_132 , unsigned int V_170 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
unsigned int V_135 = 0 ;
unsigned int V_137 = 0 ;
switch ( V_170 & V_171 ) {
case V_172 :
break;
case V_173 :
V_137 |= V_174 ;
break;
case V_175 :
V_135 |= V_176 ;
break;
case V_177 :
V_135 |= V_176 ;
V_137 |= V_174 ;
break;
default:
return - V_23 ;
}
switch ( V_170 & V_178 ) {
case V_179 :
V_135 |= V_180 ;
case V_181 :
V_135 |= 0x3 ;
break;
case V_182 :
V_135 |= 0x2 ;
break;
case V_183 :
break;
case V_184 :
V_135 |= 0x1 ;
break;
default:
return - V_23 ;
}
switch ( V_170 & V_178 ) {
case V_181 :
case V_179 :
switch ( V_170 & V_185 ) {
case V_186 :
break;
case V_187 :
V_135 |= V_188 ;
break;
default:
return - V_23 ;
}
break;
case V_182 :
case V_183 :
case V_184 :
switch ( V_170 & V_185 ) {
case V_186 :
break;
case V_189 :
V_135 |= V_188 | V_180 ;
break;
case V_187 :
V_135 |= V_188 ;
break;
case V_190 :
V_135 |= V_180 ;
break;
default:
return - V_23 ;
}
break;
default:
return - V_23 ;
}
F_7 ( V_2 , V_157 ,
V_188 | V_180 |
V_191 | V_176 , V_135 ) ;
F_7 ( V_2 , V_161 ,
V_174 , V_137 ) ;
return 0 ;
}
static int F_41 ( struct V_131 * V_132 , unsigned int V_192 ,
unsigned int V_193 , int V_194 , int V_195 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_135 = 0 ;
if ( V_194 == 0 )
goto V_196;
V_135 |= V_197 | V_198 ;
switch ( V_193 ) {
case 3 :
break;
case 0xc :
V_135 |= V_199 ;
break;
default:
return - V_23 ;
}
switch ( V_192 ) {
case 3 :
break;
case 0xc :
V_135 |= V_200 ;
break;
default:
return - V_23 ;
}
V_196:
V_8 -> V_141 = V_195 ;
V_8 -> V_140 = V_194 / 2 ;
F_7 ( V_2 , V_157 ,
V_197 | V_199 |
V_198 | V_200 , V_135 ) ;
return 0 ;
}
static int F_42 ( struct V_201 * V_202 , unsigned int V_203 ,
unsigned int V_204 )
{
T_1 V_205 ;
unsigned int V_206 , V_207 , V_208 , V_209 ;
unsigned int div ;
int V_31 ;
div = 1 ;
V_202 -> V_210 = 0 ;
while ( ( V_203 / div ) > 13500000 ) {
div *= 2 ;
V_202 -> V_210 ++ ;
if ( div > 8 ) {
F_43 ( L_18 ,
V_203 ) ;
return - V_23 ;
}
}
F_44 ( L_19 , V_203 , V_204 ) ;
V_203 /= div ;
div = 4 ;
while ( V_204 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_43 ( L_20 ,
V_204 ) ;
return - V_23 ;
}
}
V_209 = V_204 * div ;
V_202 -> V_211 = div - 1 ;
F_44 ( L_21 , V_209 ) ;
for ( V_31 = 0 ; V_31 < F_18 ( V_212 ) ; V_31 ++ ) {
if ( V_212 [ V_31 ] . V_213 <= V_203 && V_203 <= V_212 [ V_31 ] . V_214 ) {
V_202 -> V_215 = V_212 [ V_31 ] . V_215 ;
V_209 /= V_212 [ V_31 ] . V_148 ;
break;
}
}
if ( V_31 == F_18 ( V_212 ) ) {
F_43 ( L_22 , V_203 ) ;
return - V_23 ;
}
V_207 = V_209 / V_203 ;
V_202 -> V_216 = V_207 ;
V_208 = V_209 % V_203 ;
F_44 ( L_23 , V_208 ) ;
V_205 = V_217 * ( long long ) V_208 ;
F_45 ( V_205 , V_203 ) ;
V_206 = V_205 & 0xFFFFFFFF ;
if ( ( V_206 % 10 ) >= 5 )
V_206 += 5 ;
V_202 -> V_218 = V_206 / 10 ;
F_44 ( L_24 ,
V_202 -> V_216 , V_202 -> V_218 ,
V_202 -> V_215 , V_202 -> V_211 ,
V_202 -> V_210 ) ;
return 0 ;
}
static int F_46 ( struct V_131 * V_132 , int V_219 , int V_220 ,
unsigned int V_203 , unsigned int V_204 )
{
struct V_1 * V_2 = V_132 -> V_2 ;
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_201 V_202 ;
int V_133 , V_61 ;
int V_10 , V_221 ;
if ( V_220 == V_8 -> V_222 && V_203 == V_8 -> V_223 &&
V_204 == V_8 -> V_22 )
return 0 ;
V_10 = F_6 ( V_2 , V_12 ) ;
if ( V_204 == 0 ) {
F_8 ( V_2 -> V_16 , L_25 ) ;
V_8 -> V_223 = 0 ;
V_8 -> V_22 = 0 ;
F_7 ( V_2 , V_12 ,
V_27 , 0 ) ;
F_7 ( V_2 , V_18 ,
V_19 | V_20 , 0 ) ;
goto V_196;
}
switch ( V_220 ) {
case V_224 :
case V_225 :
case V_226 :
V_133 = F_42 ( & V_202 , V_203 , V_204 ) ;
if ( V_133 != 0 )
return V_133 ;
break;
case V_227 :
F_8 ( V_2 -> V_16 , L_26 ) ;
V_204 = 12000000 ;
V_203 = 12000000 ;
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_211 = 3 ;
break;
default:
F_9 ( V_2 -> V_16 , L_27 , V_219 ) ;
return - V_23 ;
}
V_221 = F_6 ( V_2 , V_18 ) ;
F_7 ( V_2 , V_12 ,
V_27 , 0 ) ;
F_7 ( V_2 , V_18 ,
V_19 | V_20 , 0 ) ;
F_7 ( V_2 , V_228 ,
V_229 , V_229 ) ;
if ( V_219 == V_227 ) {
V_61 = V_230 ;
} else {
V_61 = 0 ;
}
F_7 ( V_2 , V_231 , V_230 ,
V_61 ) ;
F_7 ( V_2 , V_228 ,
V_229 , 0 ) ;
switch ( V_219 ) {
case V_224 :
F_7 ( V_2 , V_232 ,
V_233 , 0 ) ;
break;
case V_225 :
F_7 ( V_2 , V_232 ,
V_233 , 1 ) ;
break;
case V_226 :
F_7 ( V_2 , V_232 ,
V_233 , 2 ) ;
break;
}
if ( V_202 . V_218 )
V_61 = V_234 ;
else
V_61 = 0 ;
F_7 ( V_2 , V_18 ,
V_234 , V_61 ) ;
F_7 ( V_2 , V_235 ,
V_236 | V_237 ,
( V_202 . V_211 << V_238 ) |
( V_202 . V_215 << V_239 ) ) ;
F_3 ( V_2 , V_240 , V_202 . V_218 ) ;
F_7 ( V_2 , V_241 , V_242 ,
V_202 . V_216 << V_243 ) ;
F_7 ( V_2 , V_232 ,
V_244 ,
V_202 . V_210
<< V_245 ) ;
F_8 ( V_2 -> V_16 , L_28 , V_203 , V_204 ) ;
V_8 -> V_223 = V_203 ;
V_8 -> V_22 = V_204 ;
V_8 -> V_222 = V_220 ;
F_7 ( V_2 , V_18 ,
V_19 , V_221 ) ;
F_7 ( V_2 , V_18 ,
V_20 , V_221 ) ;
V_196:
F_7 ( V_2 , V_12 ,
V_27 , V_10 ) ;
return 0 ;
}
static int F_47 ( struct V_131 * V_246 , int V_247 )
{
struct V_1 * V_2 = V_246 -> V_2 ;
int V_61 ;
if ( V_247 )
V_61 = V_248 ;
else
V_61 = 0 ;
F_7 ( V_2 , V_65 , V_248 , V_61 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 )
{
T_2 * V_249 = V_2 -> V_249 ;
int V_31 ;
if ( ! V_2 -> V_250 )
return;
V_2 -> V_251 = 0 ;
for ( V_31 = 1 ; V_31 < V_2 -> V_252 -> V_253 ; V_31 ++ ) {
if ( ! V_4 [ V_31 ] . V_254 )
continue;
if ( V_249 [ V_31 ] == V_255 [ V_31 ] )
continue;
F_3 ( V_2 , V_31 , V_249 [ V_31 ] ) ;
}
V_2 -> V_250 = 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
enum V_256 V_257 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
int V_133 ;
switch ( V_257 ) {
case V_258 :
break;
case V_259 :
F_7 ( V_2 , V_260 ,
V_261 ,
0x1 << V_262 ) ;
F_7 ( V_2 , V_263 ,
V_264 , 2 << V_265 ) ;
break;
case V_266 :
if ( V_2 -> V_111 . V_267 == V_268 ) {
V_133 = F_50 ( F_18 ( V_8 -> V_269 ) ,
V_8 -> V_269 ) ;
if ( V_133 != 0 ) {
F_9 ( V_2 -> V_16 ,
L_29 ,
V_133 ) ;
return V_133 ;
}
F_48 ( V_2 ) ;
F_7 ( V_2 , V_263 ,
V_270 , V_270 ) ;
F_7 ( V_2 , V_260 ,
V_271 |
V_261 ,
V_271 |
0x3 << V_262 ) ;
F_27 ( 1 ) ;
}
F_7 ( V_2 , V_260 ,
V_261 ,
0x2 << V_262 ) ;
F_7 ( V_2 , V_263 ,
V_264 , 0 ) ;
break;
case V_268 :
F_7 ( V_2 , V_260 ,
V_261 | V_271 , 0 ) ;
F_7 ( V_2 , V_263 ,
V_270 , 0 ) ;
#ifdef F_51
V_2 -> V_250 = 1 ;
#endif
F_52 ( F_18 ( V_8 -> V_269 ) ,
V_8 -> V_269 ) ;
break;
}
V_2 -> V_111 . V_267 = V_257 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , T_3 V_272 )
{
F_49 ( V_2 , V_268 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
F_49 ( V_2 , V_266 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
struct V_273 V_274 =
F_56 ( L_30 ,
V_8 -> V_275 ,
F_16 ,
F_15 ) ;
int V_133 , V_31 , V_276 ;
const char * * V_277 ;
V_8 -> V_50 = 0 ;
V_8 -> V_56 = NULL ;
for ( V_31 = 0 ; V_31 < V_29 -> V_53 ; V_31 ++ ) {
for ( V_276 = 0 ; V_276 < V_8 -> V_50 ; V_276 ++ ) {
if ( strcmp ( V_29 -> V_54 [ V_31 ] . V_55 ,
V_8 -> V_56 [ V_276 ] ) == 0 )
break;
}
if ( V_276 != V_8 -> V_50 )
continue;
V_277 = F_57 ( V_8 -> V_56 ,
sizeof( char * ) *
( V_8 -> V_50 + 1 ) ,
V_278 ) ;
if ( V_277 == NULL )
continue;
V_277 [ V_8 -> V_50 ] =
V_29 -> V_54 [ V_31 ] . V_55 ;
V_8 -> V_50 ++ ;
V_8 -> V_56 = V_277 ;
}
F_8 ( V_2 -> V_16 , L_31 ,
V_8 -> V_50 ) ;
V_8 -> V_275 . V_214 = V_8 -> V_50 ;
V_8 -> V_275 . V_279 = V_8 -> V_56 ;
V_133 = F_32 ( V_2 , & V_274 , 1 ) ;
if ( V_133 != 0 )
F_9 ( V_2 -> V_16 ,
L_32 , V_133 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
int V_133 , V_31 ;
if ( ! V_29 ) {
F_32 ( V_2 , V_280 ,
F_18 ( V_280 ) ) ;
return;
}
F_8 ( V_2 -> V_16 , L_33 , V_29 -> V_44 ) ;
if ( V_29 -> V_44 ) {
struct V_273 V_274 =
F_56 ( L_34 , V_8 -> V_281 ,
F_13 , F_11 ) ;
V_8 -> V_282 = F_59 ( sizeof( char * )
* V_29 -> V_44 , V_278 ) ;
if ( ! V_8 -> V_282 ) {
F_9 ( V_2 -> V_16 ,
L_35 ,
V_29 -> V_44 ) ;
return;
}
for ( V_31 = 0 ; V_31 < V_29 -> V_44 ; V_31 ++ )
V_8 -> V_282 [ V_31 ] = V_29 -> V_34 [ V_31 ] . V_55 ;
V_8 -> V_281 . V_214 = V_29 -> V_44 ;
V_8 -> V_281 . V_279 = V_8 -> V_282 ;
V_133 = F_32 ( V_2 , & V_274 , 1 ) ;
if ( V_133 != 0 )
F_9 ( V_2 -> V_16 ,
L_36 , V_133 ) ;
F_10 ( V_2 ) ;
}
F_8 ( V_2 -> V_16 , L_37 ,
V_29 -> V_53 ) ;
if ( V_29 -> V_53 )
F_55 ( V_2 ) ;
else
F_32 ( V_2 , V_280 ,
F_18 ( V_280 ) ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
struct V_28 * V_29 = V_8 -> V_29 ;
T_2 * V_249 = V_2 -> V_249 ;
int V_133 , V_31 ;
V_2 -> V_250 = 1 ;
V_2 -> V_111 . V_283 = 1 ;
switch ( V_8 -> V_114 ) {
case V_115 :
break;
case V_125 :
memset ( & V_284 . V_285 , 0 , sizeof( V_284 . V_285 ) ) ;
break;
default:
F_9 ( V_2 -> V_16 , L_38 ,
V_8 -> V_114 ) ;
return - V_23 ;
}
V_133 = F_61 ( V_2 , 8 , 16 , V_286 ) ;
if ( V_133 != 0 ) {
F_9 ( V_2 -> V_16 , L_39 , V_133 ) ;
return V_133 ;
}
for ( V_31 = 0 ; V_31 < F_18 ( V_8 -> V_269 ) ; V_31 ++ )
V_8 -> V_269 [ V_31 ] . V_287 = V_288 [ V_31 ] ;
V_133 = F_62 ( V_2 -> V_16 , F_18 ( V_8 -> V_269 ) ,
V_8 -> V_269 ) ;
if ( V_133 != 0 ) {
F_9 ( V_2 -> V_16 , L_40 , V_133 ) ;
return V_133 ;
}
V_133 = F_50 ( F_18 ( V_8 -> V_269 ) ,
V_8 -> V_269 ) ;
if ( V_133 != 0 ) {
F_9 ( V_2 -> V_16 , L_29 , V_133 ) ;
goto V_289;
}
V_133 = F_6 ( V_2 , V_6 ) ;
if ( V_133 < 0 ) {
F_9 ( V_2 -> V_16 , L_41 ) ;
goto V_290;
}
if ( V_133 != V_255 [ V_6 ] ) {
F_9 ( V_2 -> V_16 , L_42 , V_133 ) ;
V_133 = - V_23 ;
goto V_290;
}
V_133 = F_6 ( V_2 , V_291 ) ;
if ( V_133 < 0 ) {
F_9 ( V_2 -> V_16 , L_43 ,
V_133 ) ;
goto V_290;
}
F_63 ( V_2 -> V_16 , L_44 , V_133 + 'A' ) ;
V_133 = F_2 ( V_2 ) ;
if ( V_133 < 0 ) {
F_9 ( V_2 -> V_16 , L_45 ) ;
goto V_290;
}
F_7 ( V_2 , V_292 ,
V_293 , V_293 ) ;
F_7 ( V_2 , V_294 ,
V_293 , V_293 ) ;
F_7 ( V_2 , V_295 ,
V_296 , V_296 ) ;
F_7 ( V_2 , V_297 ,
V_296 , V_296 ) ;
F_7 ( V_2 , V_298 ,
V_299 | V_300 ,
V_299 | V_300 ) ;
F_7 ( V_2 , V_301 ,
V_299 | V_302 ,
V_299 | V_302 ) ;
F_7 ( V_2 , V_303 ,
V_304 | V_305 ,
V_304 | V_305 ) ;
F_7 ( V_2 , V_306 ,
V_304 | V_307 ,
V_304 | V_307 ) ;
F_7 ( V_2 , V_26 ,
V_308 , 0 ) ;
if ( V_8 -> V_29 ) {
for ( V_31 = 0 ; V_31 < V_309 ; V_31 ++ ) {
if ( ! V_29 -> V_310 [ V_31 ] )
continue;
V_249 [ V_311 + V_31 ]
= V_29 -> V_310 [ V_31 ] & 0xffff ;
}
for ( V_31 = 0 ; V_31 < V_312 ; V_31 ++ )
V_249 [ V_313 + V_31 ]
= V_29 -> V_314 [ V_31 ] ;
}
F_7 ( V_2 , V_315 ,
V_316 , V_316 ) ;
F_7 ( V_2 , V_263 ,
V_317 , 0 ) ;
F_49 ( V_2 , V_266 ) ;
F_52 ( F_18 ( V_8 -> V_269 ) , V_8 -> V_269 ) ;
F_58 ( V_2 ) ;
F_29 ( V_2 ) ;
return 0 ;
V_290:
F_52 ( F_18 ( V_8 -> V_269 ) , V_8 -> V_269 ) ;
V_289:
F_64 ( F_18 ( V_8 -> V_269 ) , V_8 -> V_269 ) ;
return V_133 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_5 ( V_2 ) ;
F_49 ( V_2 , V_268 ) ;
F_64 ( F_18 ( V_8 -> V_269 ) , V_8 -> V_269 ) ;
F_66 ( V_8 -> V_56 ) ;
F_66 ( V_8 -> V_282 ) ;
return 0 ;
}
static T_4 int F_67 ( struct V_318 * V_319 ,
const struct V_320 * V_321 )
{
struct V_7 * V_8 ;
int V_133 ;
V_8 = F_68 ( sizeof( struct V_7 ) , V_278 ) ;
if ( V_8 == NULL )
return - V_322 ;
V_8 -> V_114 = V_321 -> V_323 ;
F_69 ( V_319 , V_8 ) ;
V_8 -> V_29 = V_319 -> V_16 . V_324 ;
V_133 = F_70 ( & V_319 -> V_16 ,
& V_325 , & V_284 , 1 ) ;
if ( V_133 < 0 )
F_66 ( V_8 ) ;
return V_133 ;
}
static T_5 int F_71 ( struct V_318 * V_326 )
{
F_72 ( & V_326 -> V_16 ) ;
F_66 ( F_73 ( V_326 ) ) ;
return 0 ;
}
static int T_6 F_74 ( void )
{
int V_133 = 0 ;
#if F_75 ( V_327 ) || F_75 ( V_328 )
V_133 = F_76 ( & V_329 ) ;
if ( V_133 != 0 ) {
F_77 ( V_330 L_46 ,
V_133 ) ;
}
#endif
return V_133 ;
}
static void T_7 F_78 ( void )
{
#if F_75 ( V_327 ) || F_75 ( V_328 )
F_79 ( & V_329 ) ;
#endif
}
