static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_4 [ V_3 ] . V_5 )
return 1 ;
else
return 0 ;
}
static int F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_4 [ V_3 ] . V_6 )
return 1 ;
else
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 , V_7 , 0x6243 ) ;
}
static int F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 * V_12 = V_2 -> V_12 ;
int V_13 ;
V_13 = F_7 ( V_9 , V_11 ) ;
if ( V_13 == 0 )
return 0 ;
if ( F_8 ( V_2 , V_14 ) & V_15 )
return F_4 ( V_2 , V_16 ,
V_12 [ V_16 ] ) ;
if ( F_8 ( V_2 , V_14 ) & V_17 )
return F_4 ( V_2 , V_18 ,
V_12 [ V_18 ] ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
T_1 * V_12 = V_2 -> V_12 ;
int V_13 ;
V_13 = F_7 ( V_9 , V_11 ) ;
if ( V_13 == 0 )
return 0 ;
if ( V_12 [ V_14 ] & V_19 )
return F_4 ( V_2 , V_20 ,
V_12 [ V_20 ] ) ;
if ( V_12 [ V_14 ] & V_21 )
return F_4 ( V_2 , V_22 ,
V_12 [ V_22 ] ) ;
return 0 ;
}
static int F_10 ( struct V_23 * V_24 ,
struct V_8 * V_9 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_26 ;
int V_27 ;
V_26 = F_8 ( V_2 , V_28 ) & V_29 ;
switch ( V_26 ) {
case 0 :
V_27 = 0 ;
break;
case 0x200 :
V_27 = 1 ;
break;
default:
F_11 ( V_2 -> V_30 , L_1 , V_26 ) ;
return - V_31 ;
}
switch ( V_25 ) {
case V_32 :
if ( V_27 )
F_12 ( V_2 , V_33 ,
V_34 , V_34 ) ;
break;
case V_35 :
if ( V_27 )
F_12 ( V_2 , V_33 ,
V_34 , 0 ) ;
break;
default:
F_13 () ;
return - V_31 ;
}
return 0 ;
}
static int F_14 ( struct V_23 * V_24 ,
struct V_8 * V_9 , int V_25 )
{
switch ( V_25 ) {
case V_36 :
F_15 ( 5 ) ;
break;
default:
F_13 () ;
return - V_31 ;
}
return 0 ;
}
static int F_16 ( struct V_23 * V_24 ,
struct V_8 * V_9 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_37 ;
int V_3 ;
int V_38 = ( V_39 |
V_40 ) ;
switch ( V_25 ) {
case V_36 :
F_12 ( V_2 , V_41 ,
V_42 | V_43 ,
V_42 | V_43 ) ;
F_17 ( 20 ) ;
F_12 ( V_2 , V_41 ,
V_44 | V_45 ,
V_44 | V_45 ) ;
F_12 ( V_2 , V_46 ,
V_47 | V_48 |
V_49 |
V_50 ,
V_47 | V_48 |
V_49 |
V_50 ) ;
V_37 = 0 ;
do {
F_15 ( 1 ) ;
V_3 = F_8 ( V_2 , V_51 ) ;
if ( V_3 < 0 ) {
F_11 ( V_2 -> V_30 ,
L_2 ,
V_3 ) ;
continue;
}
F_18 ( V_2 -> V_30 , L_3 , V_3 ) ;
} while ( ++ V_37 < 200 && ( V_3 & V_38 ) != V_38 );
if ( ( V_3 & V_38 ) != V_38 )
F_11 ( V_2 -> V_30 , L_4 ) ;
else
F_18 ( V_2 -> V_30 , L_5 ,
V_37 ) ;
F_12 ( V_2 , V_41 ,
V_52 |
V_53 ,
V_52 |
V_53 ) ;
F_17 ( 20 ) ;
F_12 ( V_2 , V_41 ,
V_54 |
V_55 ,
V_54 |
V_55 ) ;
break;
case V_56 :
F_12 ( V_2 , V_41 ,
V_54 |
V_55 , 0 ) ;
F_17 ( 20 ) ;
F_12 ( V_2 , V_46 ,
V_47 | V_48 |
V_49 |
V_50 ,
0 ) ;
F_12 ( V_2 , V_41 ,
V_42 | V_43 |
V_44 | V_45 |
V_52 |
V_53 , 0 ) ;
break;
default:
F_13 () ;
return - V_31 ;
}
return 0 ;
}
static int F_19 ( struct V_23 * V_24 ,
struct V_8 * V_9 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_1 * V_12 = V_2 -> V_12 ;
int V_3 ;
switch ( V_24 -> V_57 ) {
case V_58 :
V_3 = V_18 ;
break;
case V_59 :
V_3 = V_16 ;
break;
case V_60 :
V_3 = V_22 ;
break;
case V_61 :
V_3 = V_20 ;
break;
default:
F_13 () ;
return - V_31 ;
}
switch ( V_25 ) {
case V_36 :
return F_4 ( V_2 , V_3 , V_12 [ V_3 ] ) ;
default:
F_13 () ;
return - V_31 ;
}
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_62 * V_63 = F_21 ( V_2 -> V_30 ) ;
struct V_64 * V_65 = & V_2 -> V_65 ;
F_22 ( V_2 , V_66 ,
F_23 ( V_66 ) ) ;
if ( V_63 && V_63 -> V_67 )
F_22 ( V_2 , V_68 ,
F_23 ( V_68 ) ) ;
else
F_22 ( V_2 , V_69 ,
F_23 ( V_69 ) ) ;
F_24 ( V_65 , V_70 ,
F_23 ( V_70 ) ) ;
if ( V_63 && V_63 -> V_67 )
F_24 ( V_65 , V_71 ,
F_23 ( V_71 ) ) ;
else
F_24 ( V_65 , V_72 ,
F_23 ( V_72 ) ) ;
F_25 ( V_65 , V_73 ,
F_23 ( V_73 ) ) ;
if ( V_63 && V_63 -> V_67 )
F_25 ( V_65 , V_74 ,
F_23 ( V_74 ) ) ;
else
F_25 ( V_65 , V_75 ,
F_23 ( V_75 ) ) ;
F_26 ( V_65 , L_6 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
T_1 * V_12 = V_2 -> V_12 ;
int V_76 ;
if ( ! V_2 -> V_77 )
return;
F_18 ( V_2 -> V_30 , L_7 ) ;
V_2 -> V_78 = 0 ;
for ( V_76 = 1 ; V_76 < V_2 -> V_79 -> V_80 ; V_76 ++ ) {
if ( V_76 == V_7 )
continue;
if ( V_12 [ V_76 ] == V_81 [ V_76 ] )
continue;
F_4 ( V_2 , V_76 , V_12 [ V_76 ] ) ;
}
V_2 -> V_77 = 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_84 , V_76 ;
int V_85 = 0 ;
int V_86 = 0 ;
if ( ! V_83 -> V_87 ) {
F_18 ( V_2 -> V_30 , L_8 ) ;
return;
}
V_84 = F_8 ( V_2 , V_88 ) ;
if ( V_84 < 0 ) {
F_11 ( V_2 -> V_30 , L_9 , V_84 ) ;
return;
}
V_84 = ( V_84 & V_89 ) >> V_90 ;
switch ( V_84 ) {
case 0 :
V_84 = V_83 -> V_91 ;
break;
case 1 :
V_84 = V_83 -> V_91 / 2 ;
break;
case 2 :
V_84 = V_83 -> V_91 / 4 ;
break;
default:
F_30 ( V_2 -> V_30 , L_10 ) ;
V_84 = V_83 -> V_92 ;
}
F_18 ( V_2 -> V_30 , L_11 , V_84 , V_83 -> V_87 ) ;
for ( V_76 = 0 ; V_76 < F_23 ( V_93 ) ; V_76 ++ ) {
if ( V_93 [ V_76 ] < 0 )
continue;
if ( V_84 / V_93 [ V_76 ] == V_83 -> V_87 ) {
F_18 ( V_2 -> V_30 , L_12 ,
V_93 [ V_76 ] , V_83 -> V_87 ) ;
V_85 |= V_76 ;
break;
}
}
if ( V_76 == F_23 ( V_93 ) ) {
F_11 ( V_2 -> V_30 , L_13 ,
V_84 / V_83 -> V_87 ) ;
return;
}
V_86 |= V_83 -> V_87 / V_83 -> V_94 ;
F_18 ( V_2 -> V_30 , L_14 ,
V_83 -> V_87 / V_83 -> V_94 , V_83 -> V_94 ) ;
F_12 ( V_2 , V_28 ,
V_95 , V_85 ) ;
F_12 ( V_2 , V_96 ,
V_97 , V_86 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
enum V_98 V_99 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_13 ;
if ( V_99 == V_2 -> V_65 . V_100 )
return 0 ;
switch ( V_99 ) {
case V_101 :
break;
case V_102 :
F_12 ( V_2 , V_103 ,
V_104 , 0x80 ) ;
break;
case V_105 :
if ( V_2 -> V_65 . V_100 == V_106 ) {
V_13 = F_32 ( F_23 ( V_83 -> V_107 ) ,
V_83 -> V_107 ) ;
if ( V_13 != 0 ) {
F_11 ( V_2 -> V_30 ,
L_15 ,
V_13 ) ;
return V_13 ;
}
F_27 ( V_2 ) ;
F_12 ( V_2 , V_108 ,
V_109 |
V_110 ,
V_109 |
V_110 ) ;
F_12 ( V_2 , V_103 ,
V_104 |
V_111 ,
V_111 | 0x180 ) ;
F_15 ( 5 ) ;
F_12 ( V_2 , V_28 ,
V_112 ,
V_112 ) ;
F_28 ( V_2 ) ;
}
F_12 ( V_2 , V_103 ,
V_104 , 0x100 ) ;
break;
case V_106 :
F_12 ( V_2 , V_103 ,
V_104 | V_111 , 0 ) ;
F_12 ( V_2 , V_108 ,
V_109 |
V_110 , 0 ) ;
F_33 ( F_23 ( V_83 -> V_107 ) ,
V_83 -> V_107 ) ;
break;
}
V_2 -> V_65 . V_100 = V_99 ;
return 0 ;
}
static int F_34 ( struct V_113 * V_114 ,
struct V_115 * V_116 ,
struct V_117 * V_118 )
{
struct V_119 * V_120 = V_114 -> V_121 ;
struct V_1 * V_2 = V_120 -> V_2 ;
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_122 = F_35 ( V_116 ) ;
int V_76 ;
int V_123 = 0 ;
int V_124 = 0 ;
int V_125 = 0 ;
V_83 -> V_87 = F_36 ( V_116 ) ;
V_83 -> V_94 = F_35 ( V_116 ) ;
for ( V_76 = 0 ; V_76 < F_23 ( V_126 ) ; V_76 ++ ) {
if ( V_126 [ V_76 ] . V_122 == V_122 ) {
V_124 |= V_126 [ V_76 ] . V_3 ;
break;
}
}
if ( V_76 == F_23 ( V_126 ) ) {
F_11 ( V_2 -> V_30 , L_16 , V_122 ) ;
return - V_31 ;
}
if ( V_122 % 8000 == 0 )
V_124 |= V_127 ;
for ( V_76 = 0 ; V_76 < F_23 ( V_128 ) ; V_76 ++ ) {
if ( V_128 [ V_76 ] == V_83 -> V_91 / V_122 ) {
V_125 |= V_76 << V_129 ;
break;
}
}
if ( V_76 == F_23 ( V_128 ) ) {
F_11 ( V_2 -> V_30 , L_17 ,
V_83 -> V_91 / V_122 ) ;
return - V_31 ;
}
switch ( F_37 ( V_116 ) ) {
case V_130 :
break;
case V_131 :
V_123 |= 0x40 ;
break;
case V_132 :
V_123 |= 0x80 ;
break;
case V_133 :
V_123 |= 0xc0 ;
break;
default:
return - V_31 ;
}
F_12 ( V_2 , V_134 ,
V_135 , V_123 ) ;
F_12 ( V_2 , V_136 ,
V_127 |
V_137 , V_124 ) ;
F_12 ( V_2 , V_138 ,
V_139 , V_125 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static int F_38 ( struct V_117 * V_118 , int V_140 ,
unsigned int V_141 , int V_142 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_26 ;
switch ( V_140 ) {
case V_143 :
V_83 -> V_92 = V_143 ;
V_26 = 0 ;
break;
case V_144 :
V_83 -> V_92 = V_144 ;
V_26 = 1 << V_145 ;
break;
default:
return - V_31 ;
}
F_12 ( V_2 , V_28 , V_29 ,
V_26 ) ;
V_83 -> V_91 = V_141 ;
return 0 ;
}
static int F_39 ( struct V_117 * V_118 , unsigned int V_146 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
int V_123 = 0 ;
switch ( V_146 & V_147 ) {
case V_148 :
V_123 |= V_149 ;
case V_150 :
V_123 |= 3 ;
switch ( V_146 & V_151 ) {
case V_152 :
case V_153 :
break;
default:
return - V_31 ;
}
break;
case V_154 :
break;
case V_155 :
V_123 |= 1 ;
break;
case V_156 :
V_123 |= 2 ;
break;
default:
return - V_31 ;
}
switch ( V_146 & V_151 ) {
case V_152 :
break;
case V_153 :
V_123 |= V_157 ;
break;
case V_158 :
V_123 |= V_149 ;
break;
case V_159 :
V_123 |= V_157 | V_149 ;
break;
default:
return - V_31 ;
}
switch ( V_146 & V_160 ) {
case V_161 :
V_123 |= V_162 ;
break;
case V_163 :
break;
default:
return - V_31 ;
}
F_12 ( V_2 , V_134 ,
V_164 | V_157 | V_162 |
V_149 , V_123 ) ;
return 0 ;
}
static int F_40 ( struct V_165 * V_166 , unsigned int V_167 ,
unsigned int V_168 )
{
unsigned int V_169 ;
unsigned int div ;
unsigned int V_170 , V_171 ;
int V_76 ;
div = 1 ;
V_166 -> V_172 = 0 ;
while ( ( V_167 / div ) > 13500000 ) {
div *= 2 ;
V_166 -> V_172 ++ ;
if ( div > 4 ) {
F_41 ( L_18 ,
V_167 ) ;
return - V_31 ;
}
}
F_42 ( L_19 , V_167 , V_168 ) ;
V_167 /= div ;
div = 2 ;
while ( V_168 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_41 ( L_20 ,
V_168 ) ;
return - V_31 ;
}
}
V_169 = V_168 * div ;
V_166 -> V_173 = div - 1 ;
F_42 ( L_21 , V_169 ) ;
for ( V_76 = 0 ; V_76 < F_23 ( V_174 ) ; V_76 ++ ) {
if ( V_174 [ V_76 ] . V_175 <= V_167 && V_167 <= V_174 [ V_76 ] . V_176 ) {
V_166 -> V_177 = V_174 [ V_76 ] . V_177 ;
V_170 = V_174 [ V_76 ] . V_178 ;
break;
}
}
if ( V_76 == F_23 ( V_174 ) ) {
F_41 ( L_22 , V_167 ) ;
return - V_31 ;
}
V_166 -> V_179 = V_169 / ( V_170 * V_167 ) ;
if ( V_169 % V_167 == 0 ) {
V_166 -> V_180 = 0 ;
V_166 -> V_181 = 0 ;
} else {
V_171 = F_43 ( V_169 , V_170 * V_167 ) ;
V_166 -> V_180 = ( V_169 - ( V_166 -> V_179 * V_170 * V_167 ) )
/ V_171 ;
V_166 -> V_181 = ( V_170 * V_167 ) / V_171 ;
}
F_42 ( L_23 ,
V_166 -> V_179 , V_166 -> V_180 , V_166 -> V_181 ) ;
F_42 ( L_24 ,
V_166 -> V_177 , V_166 -> V_173 ,
V_166 -> V_172 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 , int V_182 , int V_183 ,
unsigned int V_167 , unsigned int V_168 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
struct V_165 V_166 ;
unsigned long V_37 ;
int V_13 ;
int V_184 = F_8 ( V_2 , V_33 ) & V_34 ;
if ( V_183 == V_83 -> V_185 && V_167 == V_83 -> V_186 &&
V_168 == V_83 -> V_187 )
return 0 ;
if ( V_168 == 0 ) {
F_18 ( V_2 -> V_30 , L_25 ) ;
V_83 -> V_186 = 0 ;
V_83 -> V_187 = 0 ;
F_12 ( V_2 , V_33 ,
V_34 , 0 ) ;
return 0 ;
}
V_13 = F_40 ( & V_166 , V_167 , V_168 ) ;
if ( V_13 != 0 )
return V_13 ;
switch ( V_182 ) {
case V_188 :
case V_189 :
case V_190 :
V_184 |= ( V_182 - 1 ) << V_191 ;
break;
case V_192 :
F_12 ( V_2 , V_33 ,
V_193 , V_193 ) ;
F_12 ( V_2 , V_194 ,
V_195 , V_195 ) ;
break;
default:
F_11 ( V_2 -> V_30 , L_26 , V_13 ) ;
return - V_31 ;
}
if ( V_166 . V_180 || V_166 . V_181 )
V_184 |= V_196 ;
F_12 ( V_2 , V_33 , V_34 , 0 ) ;
F_12 ( V_2 , V_197 ,
V_198 |
V_199 ,
( V_166 . V_173 << V_200 ) |
( V_166 . V_172 ) ) ;
F_12 ( V_2 , V_201 ,
V_202 , V_166 . V_177 ) ;
F_4 ( V_2 , V_203 , V_166 . V_180 ) ;
F_4 ( V_2 , V_204 , V_166 . V_181 ) ;
F_4 ( V_2 , V_205 , V_166 . V_179 ) ;
F_12 ( V_2 , V_33 ,
V_196 | V_206 |
V_34 , V_184 ) ;
F_18 ( V_2 -> V_30 , L_27 , V_167 , V_168 ) ;
V_37 = F_45 ( 1 ) ;
F_46 ( & V_83 -> V_207 , V_37 ) ;
V_83 -> V_186 = V_167 ;
V_83 -> V_187 = V_168 ;
V_83 -> V_185 = V_183 ;
return 0 ;
}
static int F_47 ( struct V_117 * V_118 , int V_208 )
{
struct V_1 * V_2 = V_118 -> V_2 ;
int V_209 ;
if ( V_208 )
V_209 = V_210 ;
else
V_209 = 0 ;
return F_12 ( V_2 , V_211 ,
V_210 , V_209 ) ;
}
static void F_48 ( struct V_212 * V_213 )
{
struct V_82 * V_83 = F_49 ( V_213 ,
struct V_82 ,
V_214 . V_213 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
int V_215 = 0 ;
int V_216 = 0 ;
int V_3 ;
V_3 = F_8 ( V_2 , V_217 ) ;
if ( V_3 & V_218 ) {
V_215 |= V_219 ;
V_216 |= V_220 ;
}
if ( V_3 & V_221 ) {
V_215 |= V_222 ;
V_216 |= V_223 ;
}
F_50 ( V_83 -> V_224 , V_215 ,
V_219 | V_222 ) ;
F_12 ( V_2 , V_225 ,
V_223 |
V_220 , V_216 ) ;
}
static T_2 F_51 ( int V_226 , void * V_227 )
{
struct V_1 * V_2 = V_227 ;
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_228 ;
int V_229 ;
V_228 = F_8 ( V_2 , V_230 ) ;
V_229 = F_8 ( V_2 , V_231 ) ;
V_229 &= ~ V_228 ;
if ( V_229 & V_232 ) {
F_18 ( V_2 -> V_30 , L_28 ) ;
F_52 ( & V_83 -> V_207 ) ;
}
if ( V_229 & V_233 )
F_11 ( V_2 -> V_30 , L_29 ) ;
if ( V_229 & V_234 )
F_53 ( V_2 -> V_30 , L_30 ) ;
if ( V_229 & ( V_235 | V_236 ) ) {
F_18 ( V_2 -> V_30 , L_31 ) ;
#ifndef F_54
F_55 ( F_56 ( V_2 -> V_30 ) ) ;
#endif
F_57 ( V_2 -> V_30 , 300 ) ;
F_58 ( & V_83 -> V_214 ,
F_45 ( 250 ) ) ;
}
F_4 ( V_2 , V_231 , V_229 ) ;
return V_237 ;
}
int F_59 ( struct V_1 * V_2 , struct V_238 * V_224 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_239 , V_240 ;
V_83 -> V_224 = V_224 ;
if ( V_224 ) {
V_239 = 0 ;
V_240 = V_241 ;
} else {
V_239 = V_236 | V_235 ;
V_240 = 0 ;
}
F_12 ( V_2 , V_230 ,
V_236 | V_235 , V_239 ) ;
F_12 ( V_2 , V_217 ,
V_241 , V_240 ) ;
F_50 ( V_83 -> V_224 , 0 ,
V_219 | V_222 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 )
{
T_1 * V_12 = V_2 -> V_12 ;
int V_76 ;
for ( V_76 = 1 ; V_76 < V_2 -> V_79 -> V_80 ; V_76 ++ ) {
switch ( V_76 ) {
case V_7 :
continue;
default:
break;
}
if ( V_12 [ V_76 ] != V_81 [ V_76 ] )
F_4 ( V_2 , V_76 , V_12 [ V_76 ] ) ;
}
return 0 ;
}
static void F_61 ( struct V_212 * V_213 )
{
struct V_82 * V_83 =
F_49 ( V_213 , struct V_82 , V_242 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
struct V_64 * V_65 = & V_2 -> V_65 ;
int V_76 ;
int V_3 = 0 ;
int V_243 = 0 ;
if ( V_83 -> V_244 ) {
for ( V_76 = 0 ; V_76 < F_23 ( V_245 ) ; V_76 ++ ) {
if ( abs ( V_83 -> V_244 - V_245 [ V_76 ] ) <
abs ( V_83 -> V_244 - V_245 [ V_243 ] ) )
V_243 = V_76 ;
}
F_18 ( V_2 -> V_30 , L_32 ,
V_245 [ V_243 ] , V_83 -> V_244 ) ;
V_3 = V_246 | ( V_243 << V_247 ) ;
F_62 ( V_65 , L_6 ) ;
} else {
F_18 ( V_2 -> V_30 , L_33 ) ;
F_26 ( V_65 , L_6 ) ;
}
F_12 ( V_2 , V_248 ,
V_246 | V_249 , V_3 ) ;
F_63 ( V_65 ) ;
}
static int F_64 ( struct V_250 * V_30 , unsigned int type ,
unsigned int V_251 , int V_252 )
{
struct V_1 * V_2 = F_65 ( V_30 ) ;
struct V_82 * V_83 = F_29 ( V_2 ) ;
F_18 ( V_2 -> V_30 , L_34 , V_251 , V_252 ) ;
switch ( V_251 ) {
case V_253 :
if ( V_252 )
V_252 = 1000 ;
case V_254 :
break;
default:
return - 1 ;
}
V_83 -> V_244 = V_252 ;
F_66 ( & V_83 -> V_242 ) ;
return 0 ;
}
static T_3 F_67 ( struct V_255 * V_30 ,
struct V_256 * V_257 ,
const char * V_258 , T_4 V_259 )
{
struct V_82 * V_83 = F_68 ( V_30 ) ;
long int time ;
int V_13 ;
V_13 = F_69 ( V_258 , 10 , & time ) ;
if ( V_13 != 0 )
return V_13 ;
F_70 ( V_83 -> V_260 , V_261 , V_254 , time ) ;
return V_259 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_13 ;
V_83 -> V_260 = F_72 () ;
if ( ! V_83 -> V_260 ) {
F_11 ( V_2 -> V_30 , L_35 ) ;
return;
}
F_73 ( & V_83 -> V_242 , F_61 ) ;
V_83 -> V_244 = 0 ;
V_83 -> V_260 -> V_262 = L_36 ;
V_83 -> V_260 -> V_263 = F_56 ( V_2 -> V_30 ) ;
V_83 -> V_260 -> V_264 . V_265 = V_266 ;
V_83 -> V_260 -> V_267 [ 0 ] = F_74 ( V_261 ) ;
V_83 -> V_260 -> V_268 [ 0 ] = F_74 ( V_253 ) | F_74 ( V_254 ) ;
V_83 -> V_260 -> V_25 = F_64 ;
V_83 -> V_260 -> V_30 . V_269 = V_2 -> V_30 ;
F_75 ( V_83 -> V_260 , V_2 ) ;
V_13 = F_76 ( V_83 -> V_260 ) ;
if ( V_13 != 0 ) {
F_77 ( V_83 -> V_260 ) ;
V_83 -> V_260 = NULL ;
F_11 ( V_2 -> V_30 , L_37 ) ;
}
V_13 = F_78 ( V_2 -> V_30 , & V_270 ) ;
if ( V_13 != 0 ) {
F_11 ( V_2 -> V_30 , L_38 ,
V_13 ) ;
}
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
F_80 ( V_2 -> V_30 , & V_270 ) ;
F_81 ( V_83 -> V_260 ) ;
F_82 ( & V_83 -> V_242 ) ;
V_83 -> V_260 = NULL ;
F_12 ( V_2 , V_248 , V_246 , 0 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
}
static void F_79 ( struct V_1 * V_2 )
{
}
static void F_83 ( struct V_1 * V_2 , int V_271 )
{
int V_228 = 0 ;
int V_209 = 0 ;
switch ( V_271 ) {
case 2 :
V_228 = V_272 ;
V_209 = 1 << V_273 ;
break;
case 3 :
V_228 = V_274 ;
V_209 = 1 << V_275 ;
break;
default:
break;
}
if ( V_228 )
F_12 ( V_2 , V_276 ,
V_228 , V_209 ) ;
}
static inline struct V_82 * F_84 ( struct V_277 * V_278 )
{
return F_49 ( V_278 , struct V_82 , V_277 ) ;
}
static int F_85 ( struct V_277 * V_278 , unsigned V_279 )
{
struct V_82 * V_83 = F_84 ( V_278 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
switch ( V_279 + 1 ) {
case 2 :
case 3 :
case 5 :
case 6 :
break;
default:
return - V_31 ;
}
F_83 ( V_2 , V_279 + 1 ) ;
return 0 ;
}
static void F_86 ( struct V_277 * V_278 , unsigned V_279 , int V_280 )
{
struct V_82 * V_83 = F_84 ( V_278 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
F_12 ( V_2 , V_281 + V_279 ,
V_282 , ! ! V_280 << V_283 ) ;
}
static int F_87 ( struct V_277 * V_278 ,
unsigned V_279 , int V_280 )
{
struct V_82 * V_83 = F_84 ( V_278 ) ;
struct V_1 * V_2 = V_83 -> V_2 ;
int V_209 ;
V_209 = ( 1 << V_284 ) | ( V_280 << V_283 ) ;
return F_12 ( V_2 , V_281 + V_279 ,
V_285 | V_282 , V_209 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
struct V_62 * V_63 = F_21 ( V_2 -> V_30 ) ;
int V_13 ;
V_83 -> V_277 = V_286 ;
V_83 -> V_277 . V_287 = V_288 ;
V_83 -> V_277 . V_30 = V_2 -> V_30 ;
if ( V_63 && V_63 -> V_289 )
V_83 -> V_277 . V_290 = V_63 -> V_289 ;
else
V_83 -> V_277 . V_290 = - 1 ;
V_13 = F_89 ( & V_83 -> V_277 ) ;
if ( V_13 != 0 )
F_11 ( V_2 -> V_30 , L_39 , V_13 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
int V_13 ;
V_13 = F_91 ( & V_83 -> V_277 ) ;
if ( V_13 != 0 )
F_11 ( V_2 -> V_30 , L_40 , V_13 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
}
static void F_90 ( struct V_1 * V_2 )
{
}
static int F_92 ( struct V_1 * V_2 )
{
int V_13 ;
struct V_82 * V_83 = F_29 ( V_2 ) ;
struct V_62 * V_63 = F_21 ( V_2 -> V_30 ) ;
struct V_291 * V_292 = F_49 ( V_2 -> V_30 , struct V_291 ,
V_30 ) ;
T_1 * V_12 = V_2 -> V_12 ;
int V_76 , V_293 , V_216 ;
bool V_294 , V_295 ;
V_83 -> V_2 = V_2 ;
F_93 ( & V_83 -> V_214 , F_48 ) ;
F_94 ( & V_83 -> V_207 ) ;
V_2 -> V_77 = 1 ;
V_2 -> V_65 . V_296 = 1 ;
V_13 = F_95 ( V_2 , 16 , 16 , V_297 ) ;
if ( V_13 != 0 ) {
F_11 ( V_2 -> V_30 , L_41 , V_13 ) ;
goto V_298;
}
for ( V_76 = 0 ; V_76 < F_23 ( V_83 -> V_107 ) ; V_76 ++ )
V_83 -> V_107 [ V_76 ] . V_299 = V_300 [ V_76 ] ;
V_13 = F_96 ( V_2 -> V_30 , F_23 ( V_83 -> V_107 ) ,
V_83 -> V_107 ) ;
if ( V_13 != 0 ) {
F_11 ( V_2 -> V_30 , L_42 , V_13 ) ;
goto V_298;
}
V_83 -> V_301 [ 0 ] . V_302 = V_303 ;
V_83 -> V_301 [ 1 ] . V_302 = V_304 ;
V_83 -> V_301 [ 2 ] . V_302 = V_305 ;
V_83 -> V_301 [ 3 ] . V_302 = V_306 ;
V_83 -> V_301 [ 4 ] . V_302 = V_307 ;
V_83 -> V_301 [ 5 ] . V_302 = V_308 ;
V_83 -> V_301 [ 6 ] . V_302 = V_309 ;
V_83 -> V_301 [ 7 ] . V_302 = V_310 ;
for ( V_76 = 0 ; V_76 < F_23 ( V_83 -> V_107 ) ; V_76 ++ ) {
V_13 = F_97 ( V_83 -> V_107 [ V_76 ] . V_311 ,
& V_83 -> V_301 [ V_76 ] ) ;
if ( V_13 != 0 ) {
F_11 ( V_2 -> V_30 ,
L_43 ,
V_13 ) ;
}
}
V_13 = F_32 ( F_23 ( V_83 -> V_107 ) ,
V_83 -> V_107 ) ;
if ( V_13 != 0 ) {
F_11 ( V_2 -> V_30 , L_15 , V_13 ) ;
goto V_312;
}
V_13 = F_8 ( V_2 , V_7 ) ;
if ( V_13 < 0 ) {
F_11 ( V_2 -> V_30 , L_44 ) ;
goto V_313;
}
if ( V_13 != V_81 [ V_7 ] ) {
F_11 ( V_2 -> V_30 , L_45 ,
V_13 , V_81 [ V_7 ] ) ;
V_13 = - V_31 ;
goto V_313;
}
V_13 = F_8 ( V_2 , V_314 ) ;
if ( V_13 < 0 ) {
F_11 ( V_2 -> V_30 , L_46 ,
V_13 ) ;
goto V_313;
}
F_98 ( V_2 -> V_30 , L_47 ,
( V_13 & V_315 ) >> V_316 ,
( ( V_13 & V_317 ) >> V_318 )
+ 'A' ) ;
V_13 = F_3 ( V_2 ) ;
if ( V_13 < 0 ) {
F_11 ( V_2 -> V_30 , L_48 ) ;
goto V_313;
}
F_12 ( V_2 , V_28 , V_319 , 0 ) ;
F_33 ( F_23 ( V_83 -> V_107 ) , V_83 -> V_107 ) ;
if ( V_63 ) {
for ( V_76 = 0 ; V_76 < F_23 ( V_63 -> V_320 ) ; V_76 ++ )
if ( V_63 -> V_320 [ V_76 ] ) {
F_83 ( V_2 , V_76 + 1 ) ;
F_4 ( V_2 , 0x200 + V_76 ,
V_63 -> V_320 [ V_76 ] & 0xffff ) ;
}
if ( V_63 -> V_67 )
V_12 [ V_321 ]
|= V_322 ;
if ( V_63 -> V_323 )
F_12 ( V_2 , V_217 ,
V_241 |
V_324 |
V_325 |
V_326 ,
V_63 -> V_323 ) ;
}
F_12 ( V_2 , V_327 ,
V_328 , V_328 ) ;
F_12 ( V_2 , V_314 ,
V_328 , V_328 ) ;
F_12 ( V_2 , V_329 ,
V_330 , V_330 ) ;
F_12 ( V_2 , V_331 ,
V_330 , V_330 ) ;
F_12 ( V_2 , V_332 ,
V_333 , V_333 ) ;
F_12 ( V_2 , V_334 ,
V_333 , V_333 ) ;
F_12 ( V_2 , V_20 ,
V_335 , V_335 ) ;
F_12 ( V_2 , V_22 ,
V_335 , V_335 ) ;
F_12 ( V_2 , V_16 ,
V_336 , V_336 ) ;
F_12 ( V_2 , V_18 ,
V_336 , V_336 ) ;
F_20 ( V_2 ) ;
V_294 = false ;
V_295 = false ;
for ( V_76 = 0 ; V_76 < V_288 ; V_76 ++ ) {
switch ( F_8 ( V_2 , V_281 + V_76 )
& V_285 ) {
case V_337 :
V_294 = true ;
break;
case V_338 :
V_295 = true ;
break;
default:
break;
}
}
if ( ! V_294 || ! V_295 ) {
F_18 ( V_2 -> V_30 , L_49 ) ;
F_99 ( & V_2 -> V_65 , L_50 ) ;
}
if ( V_294 != V_295 )
F_30 ( V_2 -> V_30 , L_51 ) ;
F_71 ( V_2 ) ;
F_88 ( V_2 ) ;
if ( V_292 -> V_226 ) {
if ( V_63 && V_63 -> V_339 ) {
V_293 = V_340 ;
V_216 = V_341 ;
} else {
V_293 = V_342 ;
V_216 = 0 ;
}
F_12 ( V_2 , V_343 ,
V_341 , V_216 ) ;
V_13 = F_100 ( V_292 -> V_226 , NULL , F_51 ,
V_293 | V_344 ,
L_52 , V_2 ) ;
if ( V_13 != 0 ) {
F_11 ( V_2 -> V_30 , L_53 ,
V_292 -> V_226 , V_13 ) ;
} else {
F_12 ( V_2 ,
V_230 ,
V_232 |
V_234 |
V_233 , 0 ) ;
}
}
return 0 ;
V_313:
F_33 ( F_23 ( V_83 -> V_107 ) , V_83 -> V_107 ) ;
V_312:
F_101 ( F_23 ( V_83 -> V_107 ) , V_83 -> V_107 ) ;
V_298:
return V_13 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = F_29 ( V_2 ) ;
struct V_291 * V_292 = F_49 ( V_2 -> V_30 , struct V_291 ,
V_30 ) ;
int V_76 ;
if ( V_292 -> V_226 )
F_103 ( V_292 -> V_226 , V_2 ) ;
F_104 ( & V_83 -> V_214 ) ;
F_90 ( V_2 ) ;
F_79 ( V_2 ) ;
for ( V_76 = 0 ; V_76 < F_23 ( V_83 -> V_107 ) ; V_76 ++ )
F_105 ( V_83 -> V_107 [ V_76 ] . V_311 ,
& V_83 -> V_301 [ V_76 ] ) ;
F_101 ( F_23 ( V_83 -> V_107 ) , V_83 -> V_107 ) ;
return 0 ;
}
static T_5 int F_106 ( struct V_291 * V_292 ,
const struct V_345 * V_264 )
{
struct V_82 * V_83 ;
int V_13 ;
V_83 = F_107 ( sizeof( struct V_82 ) , V_346 ) ;
if ( V_83 == NULL )
return - V_347 ;
F_108 ( V_292 , V_83 ) ;
V_13 = F_109 ( & V_292 -> V_30 ,
& V_348 , & V_349 , 1 ) ;
if ( V_13 < 0 )
F_110 ( V_83 ) ;
return V_13 ;
}
static T_6 int F_111 ( struct V_291 * V_350 )
{
F_112 ( & V_350 -> V_30 ) ;
F_110 ( F_113 ( V_350 ) ) ;
return 0 ;
}
static int T_7 F_114 ( void )
{
int V_13 ;
#if F_115 ( V_351 ) || F_115 ( V_352 )
V_13 = F_116 ( & V_353 ) ;
if ( V_13 != 0 ) {
F_117 ( V_354 L_54 ,
V_13 ) ;
}
#endif
return 0 ;
}
static void T_8 F_118 ( void )
{
#if F_115 ( V_351 ) || F_115 ( V_352 )
F_119 ( & V_353 ) ;
#endif
}
