static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_9 * V_10 , unsigned int V_11 ,
unsigned int V_12 )
{
T_1 V_13 ;
unsigned int V_14 , V_15 , V_16 , V_17 ;
unsigned int div ;
int V_18 ;
div = 1 ;
V_10 -> V_19 = 0 ;
while ( ( V_11 / div ) > 13500000 ) {
div *= 2 ;
V_10 -> V_19 ++ ;
if ( div > 8 ) {
F_3 ( L_1 ,
V_11 ) ;
return - V_20 ;
}
}
F_4 ( L_2 , V_11 , V_12 ) ;
V_11 /= div ;
div = 0 ;
V_17 = V_12 * 2 ;
while ( V_17 < 90000000 ) {
div ++ ;
V_17 *= 2 ;
if ( div > 7 ) {
F_3 ( L_3 ,
V_12 ) ;
return - V_20 ;
}
}
V_10 -> V_21 = div ;
F_4 ( L_4 , V_17 ) ;
for ( V_18 = 0 ; V_18 < F_5 ( V_22 ) ; V_18 ++ ) {
if ( V_22 [ V_18 ] . V_23 <= V_11 && V_11 <= V_22 [ V_18 ] . V_24 ) {
V_10 -> V_25 = V_22 [ V_18 ] . V_25 ;
V_17 /= V_22 [ V_18 ] . V_26 ;
break;
}
}
if ( V_18 == F_5 ( V_22 ) ) {
F_3 ( L_5 , V_11 ) ;
return - V_20 ;
}
V_15 = V_17 / V_11 ;
V_10 -> V_27 = V_15 ;
V_16 = V_17 % V_11 ;
F_4 ( L_6 , V_16 ) ;
V_13 = V_28 * ( long long ) V_16 ;
F_6 ( V_13 , V_11 ) ;
V_14 = V_13 & 0xFFFFFFFF ;
if ( ( V_14 % 10 ) >= 5 )
V_14 += 5 ;
V_10 -> V_29 = V_14 / 10 ;
F_4 ( L_7 ,
V_10 -> V_27 , V_10 -> V_29 ,
V_10 -> V_25 , V_10 -> V_21 ,
V_10 -> V_19 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , int V_30 , int V_31 ,
unsigned int V_11 , unsigned int V_12 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
T_2 V_34 , V_35 , V_36 ;
struct V_9 V_10 ;
int V_37 ;
if ( V_11 == V_33 -> V_38 && V_12 == V_33 -> V_39 )
return 0 ;
if ( V_12 == 0 ) {
F_9 ( V_2 -> V_40 , L_8 ) ;
V_33 -> V_38 = 0 ;
V_33 -> V_39 = 0 ;
V_34 = F_10 ( V_2 , V_41 ) ;
V_34 &= ~ V_42 ;
F_11 ( V_2 , V_41 , V_34 ) ;
return 0 ;
}
V_37 = F_2 ( & V_10 , V_11 , V_12 ) ;
if ( V_37 != 0 )
return V_37 ;
V_36 = F_10 ( V_2 , V_43 ) ;
V_36 &= ~ V_44 ;
switch ( V_30 ) {
case V_45 :
break;
case V_46 :
V_36 |= 1 ;
break;
case V_47 :
V_36 |= 2 ;
break;
default:
F_12 ( V_2 -> V_40 , L_9 , V_30 ) ;
return - V_20 ;
}
V_34 = F_10 ( V_2 , V_41 ) ;
V_34 &= ~ V_42 ;
F_11 ( V_2 , V_41 , V_34 ) ;
if ( V_10 . V_29 )
V_34 |= V_48 ;
else
V_34 &= ~ V_48 ;
F_11 ( V_2 , V_41 , V_34 ) ;
F_11 ( V_2 , V_49 ,
( V_10 . V_21 << V_50 ) |
( V_10 . V_25 << V_51 ) ) ;
F_11 ( V_2 , V_52 , V_10 . V_29 ) ;
V_35 = F_10 ( V_2 , V_53 ) ;
V_35 &= ~ V_54 ;
V_35 |= V_10 . V_27 << V_55 ;
F_11 ( V_2 , V_53 , V_35 ) ;
V_36 &= ~ V_56 ;
V_36 |= V_10 . V_19 << V_57 ;
F_11 ( V_2 , V_43 , V_36 ) ;
F_11 ( V_2 , V_41 , V_34 | V_42 ) ;
if ( V_11 < 1000000 )
F_13 ( 3 ) ;
else
F_13 ( 1 ) ;
F_9 ( V_2 -> V_40 , L_10 , V_11 , V_12 ) ;
V_33 -> V_38 = V_11 ;
V_33 -> V_39 = V_12 ;
V_33 -> V_58 = V_31 ;
return 0 ;
}
static int F_14 ( struct V_59 * V_60 , int V_30 , int V_31 ,
unsigned int V_11 , unsigned int V_12 )
{
return F_7 ( V_60 -> V_2 , V_30 , V_31 , V_11 , V_12 ) ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
unsigned int V_3 ;
switch ( V_33 -> V_61 ) {
case V_62 :
F_9 ( V_2 -> V_40 , L_11 , V_33 -> V_63 ) ;
V_3 = F_10 ( V_2 , V_64 ) ;
V_3 &= ~ ( V_65 | V_66 ) ;
if ( V_33 -> V_63 > 13500000 ) {
V_3 |= V_65 ;
V_33 -> V_67 = V_33 -> V_63 / 2 ;
} else {
V_3 &= ~ V_65 ;
V_33 -> V_67 = V_33 -> V_63 ;
}
F_11 ( V_2 , V_64 , V_3 ) ;
break;
case V_68 :
F_9 ( V_2 -> V_40 , L_12 ,
V_33 -> V_39 ) ;
V_3 = F_10 ( V_2 , V_64 ) ;
V_3 |= V_66 ;
if ( V_33 -> V_39 > 13500000 ) {
V_3 |= V_65 ;
V_33 -> V_67 = V_33 -> V_39 / 2 ;
} else {
V_3 &= ~ V_65 ;
V_33 -> V_67 = V_33 -> V_39 ;
}
F_11 ( V_2 , V_64 , V_3 ) ;
break;
default:
F_12 ( V_2 -> V_40 , L_13 ) ;
return - V_20 ;
}
F_9 ( V_2 -> V_40 , L_14 , V_33 -> V_67 ) ;
return 0 ;
}
static int F_16 ( struct V_69 * V_70 ,
struct V_71 * V_72 , int V_73 )
{
struct V_1 * V_2 = V_70 -> V_2 ;
switch ( V_73 ) {
case V_74 :
return F_15 ( V_2 ) ;
case V_75 :
break;
}
return 0 ;
}
static int F_17 ( struct V_71 * V_72 ,
struct V_76 * V_77 )
{
struct V_78 * V_79 = F_18 ( V_72 ) ;
struct V_69 * V_80 = V_79 -> V_81 [ 0 ] ;
struct V_1 * V_2 = V_80 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 ;
if ( V_77 -> V_82 . integer . V_82 [ 0 ] == 0 ) {
if ( V_33 -> V_83 == 0 ) {
F_9 ( V_2 -> V_40 , L_15 ) ;
F_19 ( V_2 , V_84 ,
V_85 |
V_86 ,
0 ) ;
}
V_33 -> V_83 ++ ;
V_33 -> V_87 . V_88 = true ;
}
V_37 = F_20 ( V_72 , V_77 ) ;
if ( V_77 -> V_82 . integer . V_82 [ 0 ] == 1 ) {
if ( V_33 -> V_83 == 1 ) {
F_9 ( V_2 -> V_40 , L_16 ) ;
F_19 ( V_2 , V_84 ,
V_85 |
V_86 ,
V_85 |
V_86 ) ;
}
V_33 -> V_83 -- ;
V_33 -> V_87 . V_88 = false ;
}
F_9 ( V_2 -> V_40 , L_17 ,
V_33 -> V_83 ) ;
return V_37 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_89 V_90 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 ;
switch ( V_90 ) {
case V_91 :
case V_92 :
F_19 ( V_2 , V_93 ,
V_94 , 0x2 ) ;
F_19 ( V_2 , V_95 ,
V_96 , V_96 ) ;
break;
case V_97 :
if ( V_2 -> V_98 . V_99 == V_100 ) {
V_37 = F_22 ( F_5 ( V_33 -> V_101 ) ,
V_33 -> V_101 ) ;
if ( V_37 != 0 )
return V_37 ;
F_23 ( V_2 ) ;
F_11 ( V_2 , 0x44 , 3 ) ;
F_11 ( V_2 , 0x56 , 3 ) ;
F_11 ( V_2 , 0x44 , 0 ) ;
F_19 ( V_2 , V_102 ,
V_103 |
V_104 |
V_105 |
V_106 ,
V_103 |
V_104 |
V_105 |
V_106 ) ;
if ( ! V_33 -> V_107 . V_108 ||
! V_33 -> V_107 . V_109 )
F_19 ( V_2 , V_110 ,
V_111 ,
V_111 ) ;
F_19 ( V_2 , V_93 ,
V_94 |
V_112 ,
V_112 | 0x2 ) ;
F_13 ( 32 ) ;
F_19 ( V_2 , V_102 ,
V_106 |
V_103 , 0 ) ;
}
F_19 ( V_2 , V_93 ,
V_94 , 0x4 ) ;
F_19 ( V_2 , V_95 ,
V_96 , 0 ) ;
break;
case V_100 :
F_19 ( V_2 , V_110 ,
V_111 , 0 ) ;
F_19 ( V_2 , V_93 ,
V_94 | V_112 ,
0 ) ;
F_19 ( V_2 , V_102 ,
V_103 |
V_104 |
V_105 |
V_106 , 0 ) ;
#ifdef F_24
V_2 -> V_113 = 1 ;
#endif
F_25 ( F_5 ( V_33 -> V_101 ) ,
V_33 -> V_101 ) ;
break;
}
V_2 -> V_98 . V_99 = V_90 ;
return 0 ;
}
static int F_26 ( struct V_59 * V_114 ,
int V_115 , unsigned int V_116 , int V_117 )
{
struct V_1 * V_2 = V_114 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
switch ( V_115 ) {
case V_62 :
V_33 -> V_63 = V_116 ;
case V_68 :
V_33 -> V_61 = V_115 ;
break;
default:
return - V_20 ;
}
return 0 ;
}
static int F_27 ( struct V_59 * V_60 ,
unsigned int V_118 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
unsigned int V_119 = F_10 ( V_2 , V_120 ) ;
unsigned int V_121 = F_10 ( V_2 , V_122 ) ;
V_119 &= ~ ( V_123 | V_124 |
V_125 | V_126 ) ;
V_121 &= ~ V_127 ;
switch ( V_118 & V_128 ) {
case V_129 :
V_33 -> V_130 = 0 ;
break;
case V_131 :
V_121 |= V_127 ;
V_33 -> V_130 = 1 ;
break;
case V_132 :
V_119 |= V_123 ;
V_33 -> V_130 = 1 ;
break;
case V_133 :
V_119 |= V_123 ;
V_121 |= V_127 ;
V_33 -> V_130 = 1 ;
break;
default:
return - V_20 ;
}
switch ( V_118 & V_134 ) {
case V_135 :
V_119 |= V_125 ;
case V_136 :
V_119 |= 0x18 ;
break;
case V_137 :
V_119 |= 0x10 ;
break;
case V_138 :
break;
case V_139 :
V_119 |= 0x8 ;
break;
default:
return - V_20 ;
}
switch ( V_118 & V_134 ) {
case V_136 :
case V_135 :
switch ( V_118 & V_140 ) {
case V_141 :
break;
case V_142 :
V_119 |= V_124 ;
break;
default:
return - V_20 ;
}
break;
case V_137 :
case V_138 :
case V_139 :
switch ( V_118 & V_140 ) {
case V_141 :
break;
case V_143 :
V_119 |= V_124 | V_125 ;
break;
case V_142 :
V_119 |= V_124 ;
break;
case V_144 :
V_119 |= V_125 ;
break;
default:
return - V_20 ;
}
break;
default:
return - V_20 ;
}
F_11 ( V_2 , V_120 , V_119 ) ;
F_11 ( V_2 , V_122 , V_121 ) ;
return 0 ;
}
static int F_28 ( struct V_145 * V_146 ,
struct V_147 * V_148 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 , V_18 , V_149 , V_150 , V_151 ;
unsigned int V_152 , V_153 , V_119 , V_121 ;
V_152 = F_10 ( V_2 , V_154 ) ;
V_152 &= ~ V_155 ;
V_153 = F_10 ( V_2 , V_156 ) ;
V_153 &= ~ ( V_157 | V_158 ) ;
V_119 = F_10 ( V_2 , V_120 ) ;
V_119 &= ~ V_159 ;
V_121 = F_10 ( V_2 , V_122 ) ;
V_121 &= ~ V_160 ;
V_33 -> V_161 = F_29 ( V_148 ) ;
V_33 -> V_162 = 2 * V_33 -> V_161 ;
if ( V_33 -> V_163 ) {
F_9 ( V_2 -> V_40 , L_18 ,
V_33 -> V_163 , V_33 -> V_164 ) ;
V_33 -> V_162 *= V_33 -> V_164 * V_33 -> V_163 ;
} else {
switch ( F_30 ( V_148 ) ) {
case V_165 :
V_33 -> V_162 *= 16 ;
break;
case V_166 :
V_33 -> V_162 *= 20 ;
V_119 |= 0x8 ;
break;
case V_167 :
V_33 -> V_162 *= 24 ;
V_119 |= 0x10 ;
break;
case V_168 :
V_33 -> V_162 *= 32 ;
V_119 |= 0x18 ;
break;
default:
return - V_20 ;
}
}
F_9 ( V_2 -> V_40 , L_19 , V_33 -> V_162 ) ;
V_37 = F_15 ( V_2 ) ;
if ( V_37 != 0 )
return V_37 ;
V_149 = 0 ;
V_150 = abs ( ( V_33 -> V_67 / V_169 [ 0 ] . V_26 )
- V_33 -> V_161 ) ;
for ( V_18 = 1 ; V_18 < F_5 ( V_169 ) ; V_18 ++ ) {
V_151 = abs ( ( V_33 -> V_67 /
V_169 [ V_18 ] . V_26 ) - V_33 -> V_161 ) ;
if ( V_151 < V_150 ) {
V_149 = V_18 ;
V_150 = V_151 ;
}
}
F_9 ( V_2 -> V_40 , L_20 ,
V_169 [ V_149 ] . V_26 ) ;
V_153 |= ( V_169 [ V_149 ] . V_170
<< V_171 ) ;
V_149 = 0 ;
V_150 = abs ( V_33 -> V_161 - V_172 [ 0 ] . V_173 ) ;
for ( V_18 = 1 ; V_18 < F_5 ( V_172 ) ; V_18 ++ ) {
V_151 = abs ( V_33 -> V_161 - V_172 [ V_18 ] . V_173 ) ;
if ( V_151 < V_150 ) {
V_149 = V_18 ;
V_150 = V_151 ;
}
}
F_9 ( V_2 -> V_40 , L_21 ,
V_172 [ V_149 ] . V_173 ) ;
V_153 |= ( V_172 [ V_149 ] . V_174
<< V_175 ) ;
V_149 = 0 ;
V_150 = V_176 ;
for ( V_18 = 0 ; V_18 < F_5 ( V_177 ) ; V_18 ++ ) {
V_151 = ( ( V_33 -> V_67 * 10 ) / V_177 [ V_18 ] . div )
- V_33 -> V_162 ;
if ( V_151 < 0 )
break;
if ( V_151 < V_150 ) {
V_149 = V_18 ;
V_150 = V_151 ;
}
}
V_33 -> V_162 = ( V_33 -> V_67 * 10 ) / V_177 [ V_149 ] . div ;
F_9 ( V_2 -> V_40 , L_22 ,
V_177 [ V_149 ] . div , V_33 -> V_162 ) ;
V_152 |= V_177 [ V_149 ] . V_178 << V_179 ;
F_9 ( V_2 -> V_40 , L_23 , V_33 -> V_162 / V_33 -> V_161 ) ;
V_121 |= V_33 -> V_162 / V_33 -> V_161 ;
F_11 ( V_2 , V_154 , V_152 ) ;
F_11 ( V_2 , V_156 , V_153 ) ;
F_11 ( V_2 , V_120 , V_119 ) ;
F_11 ( V_2 , V_122 , V_121 ) ;
if ( V_33 -> V_107 . V_180 ) {
T_2 V_181 = F_10 ( V_2 , V_182 ) ;
struct V_183 * V_184 ;
V_149 = 0 ;
V_150 = abs ( V_33 -> V_107 . V_185 [ 0 ] . V_173
- V_33 -> V_161 ) ;
for ( V_18 = 0 ; V_18 < V_33 -> V_107 . V_180 ; V_18 ++ ) {
V_151 = abs ( V_33 -> V_107 . V_185 [ V_18 ] . V_173
- V_33 -> V_161 ) ;
if ( V_151 < V_150 ) {
V_150 = V_151 ;
V_149 = V_18 ;
}
}
V_184 = & V_33 -> V_107 . V_185 [ V_149 ] ;
F_9 ( V_2 -> V_40 , L_24 ,
V_184 -> V_186 , V_184 -> V_173 ) ;
F_19 ( V_2 , V_182 , V_187 , 0 ) ;
for ( V_18 = 1 ; V_18 < F_5 ( V_184 -> V_188 ) ; V_18 ++ )
F_11 ( V_2 , V_182 + V_18 , V_184 -> V_188 [ V_18 ] ) ;
F_19 ( V_2 , V_182 , V_187 , V_181 ) ;
}
return 0 ;
}
static int F_31 ( struct V_59 * V_114 , int V_189 )
{
struct V_1 * V_2 = V_114 -> V_2 ;
unsigned int V_3 ;
V_3 = F_10 ( V_2 , V_190 ) ;
if ( V_189 )
V_3 |= V_191 ;
else
V_3 &= ~ V_191 ;
F_11 ( V_2 , V_190 , V_3 ) ;
return 0 ;
}
static int F_32 ( struct V_59 * V_60 , unsigned int V_192 ,
unsigned int V_193 , int V_194 , int V_195 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_119 = 0 ;
int V_196 = 0 ;
if ( V_194 == 0 ) {
V_33 -> V_163 = 0 ;
goto V_197;
}
V_119 |= V_198 ;
V_196 |= V_199 ;
switch ( V_193 ) {
case 3 :
break;
case 0xc :
V_119 |= V_200 ;
break;
default:
return - V_20 ;
}
switch ( V_192 ) {
case 3 :
break;
case 0xc :
V_196 |= V_201 ;
break;
default:
return - V_20 ;
}
V_197:
V_33 -> V_164 = V_195 ;
V_33 -> V_163 = V_194 / 2 ;
F_19 ( V_2 , V_120 ,
V_198 | V_200 , V_119 ) ;
F_19 ( V_2 , V_202 ,
V_199 | V_201 , V_196 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
struct V_203 * V_98 = & V_2 -> V_98 ;
int V_37 , V_18 , V_204 ;
V_33 -> V_87 . V_205 = 1 ;
V_33 -> V_87 . V_206 = - 2 ;
V_33 -> V_87 . V_207 = - 2 ;
V_33 -> V_87 . V_208 = 1 ;
V_37 = F_34 ( V_2 , 8 , 16 , V_209 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_25 , V_37 ) ;
return V_37 ;
}
for ( V_18 = 0 ; V_18 < F_5 ( V_33 -> V_101 ) ; V_18 ++ )
V_33 -> V_101 [ V_18 ] . V_210 = V_211 [ V_18 ] ;
V_37 = F_35 ( V_2 -> V_40 , F_5 ( V_33 -> V_101 ) ,
V_33 -> V_101 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_26 , V_37 ) ;
return V_37 ;
}
V_37 = F_22 ( F_5 ( V_33 -> V_101 ) ,
V_33 -> V_101 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_27 , V_37 ) ;
goto V_212;
}
V_204 = F_10 ( V_2 , V_4 ) ;
if ( V_204 != V_213 [ V_4 ] ) {
F_12 ( V_2 -> V_40 , L_28 , V_204 ) ;
V_37 = - V_20 ;
goto V_214;
}
V_37 = F_11 ( V_2 , V_4 , 0xffff ) ;
if ( V_37 != 0 )
goto V_214;
V_2 -> V_215 = 1 ;
V_33 -> V_83 = 2 ;
F_19 ( V_2 , V_216 ,
V_217 , V_217 ) ;
F_19 ( V_2 , V_218 ,
V_219 , V_219 ) ;
F_19 ( V_2 , V_220 ,
V_221 , 0 ) ;
F_19 ( V_2 , V_222 , V_223 , 0 ) ;
F_36 ( V_2 , V_33 -> V_107 . V_108 ,
V_33 -> V_107 . V_109 ,
V_33 -> V_107 . V_224 ,
V_33 -> V_107 . V_225 ,
V_33 -> V_107 . V_226 ,
V_33 -> V_107 . V_227 ,
V_33 -> V_107 . V_228 ,
V_33 -> V_107 . V_229 ) ;
V_37 = F_21 ( V_2 , V_97 ) ;
if ( V_37 != 0 )
goto V_214;
F_37 ( V_2 , V_230 ,
F_5 ( V_230 ) ) ;
if ( V_33 -> V_107 . V_180 != 0 ) {
F_9 ( V_2 -> V_40 , L_29 ) ;
} else {
F_9 ( V_2 -> V_40 , L_30 ) ;
F_37 ( V_2 , V_231 ,
F_5 ( V_231 ) ) ;
}
F_38 ( V_98 , V_232 ,
F_5 ( V_232 ) ) ;
F_39 ( V_2 ) ;
F_40 ( V_98 , V_233 , F_5 ( V_233 ) ) ;
F_41 ( V_2 , V_33 -> V_107 . V_108 ,
V_33 -> V_107 . V_109 ) ;
return 0 ;
V_214:
F_25 ( F_5 ( V_33 -> V_101 ) , V_33 -> V_101 ) ;
V_212:
F_42 ( F_5 ( V_33 -> V_101 ) , V_33 -> V_101 ) ;
return V_37 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
F_21 ( V_2 , V_100 ) ;
F_42 ( F_5 ( V_33 -> V_101 ) , V_33 -> V_101 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_39 = V_33 -> V_39 ;
int V_38 = V_33 -> V_38 ;
int V_37 ;
V_37 = F_7 ( V_2 , 0 , 0 , 0 , 0 ) ;
if ( V_37 != 0 ) {
F_12 ( V_2 -> V_40 , L_31 ) ;
return V_37 ;
}
V_33 -> V_39 = V_39 ;
V_33 -> V_38 = V_38 ;
F_21 ( V_2 , V_100 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_32 * V_33 = F_8 ( V_2 ) ;
int V_37 ;
F_21 ( V_2 , V_97 ) ;
if ( V_33 -> V_39 ) {
int V_39 = V_33 -> V_39 ;
int V_38 = V_33 -> V_38 ;
V_33 -> V_38 = 0 ;
V_33 -> V_39 = 0 ;
V_37 = F_7 ( V_2 , 0 , V_33 -> V_58 ,
V_38 , V_39 ) ;
if ( V_37 != 0 )
F_12 ( V_2 -> V_40 , L_32 ) ;
}
return 0 ;
}
static T_3 int F_46 ( struct V_234 * V_235 ,
const struct V_236 * V_237 )
{
struct V_32 * V_33 ;
int V_37 ;
V_33 = F_47 ( & V_235 -> V_40 , sizeof( struct V_32 ) ,
V_238 ) ;
if ( V_33 == NULL )
return - V_239 ;
F_48 ( V_235 , V_33 ) ;
V_37 = F_49 ( & V_235 -> V_40 ,
& V_240 , & V_241 , 1 ) ;
return V_37 ;
}
static T_4 int F_50 ( struct V_234 * V_242 )
{
F_51 ( & V_242 -> V_40 ) ;
F_52 ( F_53 ( V_242 ) ) ;
return 0 ;
}
static int T_5 F_54 ( void )
{
int V_37 = 0 ;
#if F_55 ( V_243 ) || F_55 ( V_244 )
V_37 = F_56 ( & V_245 ) ;
if ( V_37 != 0 ) {
F_3 ( L_33 ,
V_37 ) ;
}
#endif
return V_37 ;
}
static void T_6 F_57 ( void )
{
#if F_55 ( V_243 ) || F_55 ( V_244 )
F_58 ( & V_245 ) ;
#endif
}
