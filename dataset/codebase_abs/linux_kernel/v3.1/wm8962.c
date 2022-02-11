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
struct V_26 * V_27 = F_11 ( V_2 ) ;
unsigned long V_28 ;
int V_29 ;
int V_30 ;
V_29 = F_8 ( V_2 , V_31 ) & V_32 ;
switch ( V_29 ) {
case 0 :
V_30 = 0 ;
break;
case 0x200 :
V_30 = 1 ;
break;
default:
F_12 ( V_2 -> V_33 , L_1 , V_29 ) ;
return - V_34 ;
}
switch ( V_25 ) {
case V_35 :
if ( V_30 ) {
F_13 ( & V_27 -> V_36 ) ;
F_14 ( V_2 , V_37 ,
V_38 , V_38 ) ;
if ( V_27 -> V_39 ) {
V_28 = F_15 ( 5 ) ;
V_28 = F_16 ( & V_27 -> V_36 ,
V_28 ) ;
if ( V_28 == 0 )
F_12 ( V_2 -> V_33 ,
L_2 ) ;
}
}
break;
case V_40 :
if ( V_30 )
F_14 ( V_2 , V_37 ,
V_38 , 0 ) ;
break;
default:
F_17 () ;
return - V_34 ;
}
return 0 ;
}
static int F_18 ( struct V_23 * V_24 ,
struct V_8 * V_9 , int V_25 )
{
switch ( V_25 ) {
case V_41 :
F_19 ( 5 ) ;
break;
default:
F_17 () ;
return - V_34 ;
}
return 0 ;
}
static int F_20 ( struct V_23 * V_24 ,
struct V_8 * V_9 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
int V_28 ;
int V_3 ;
int V_42 = ( V_43 |
V_44 ) ;
switch ( V_25 ) {
case V_41 :
F_14 ( V_2 , V_45 ,
V_46 | V_47 ,
V_46 | V_47 ) ;
F_21 ( 20 ) ;
F_14 ( V_2 , V_45 ,
V_48 | V_49 ,
V_48 | V_49 ) ;
F_14 ( V_2 , V_50 ,
V_51 | V_52 |
V_53 |
V_54 ,
V_51 | V_52 |
V_53 |
V_54 ) ;
V_28 = 0 ;
do {
F_19 ( 1 ) ;
V_3 = F_8 ( V_2 , V_55 ) ;
if ( V_3 < 0 ) {
F_12 ( V_2 -> V_33 ,
L_3 ,
V_3 ) ;
continue;
}
F_22 ( V_2 -> V_33 , L_4 , V_3 ) ;
} while ( ++ V_28 < 200 && ( V_3 & V_42 ) != V_42 );
if ( ( V_3 & V_42 ) != V_42 )
F_12 ( V_2 -> V_33 , L_5 ) ;
else
F_22 ( V_2 -> V_33 , L_6 ,
V_28 ) ;
F_14 ( V_2 , V_45 ,
V_56 |
V_57 ,
V_56 |
V_57 ) ;
F_21 ( 20 ) ;
F_14 ( V_2 , V_45 ,
V_58 |
V_59 ,
V_58 |
V_59 ) ;
break;
case V_60 :
F_14 ( V_2 , V_45 ,
V_58 |
V_59 , 0 ) ;
F_21 ( 20 ) ;
F_14 ( V_2 , V_50 ,
V_51 | V_52 |
V_53 |
V_54 ,
0 ) ;
F_14 ( V_2 , V_45 ,
V_46 | V_47 |
V_48 | V_49 |
V_56 |
V_57 , 0 ) ;
break;
default:
F_17 () ;
return - V_34 ;
}
return 0 ;
}
static int F_23 ( struct V_23 * V_24 ,
struct V_8 * V_9 , int V_25 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
T_1 * V_12 = V_2 -> V_12 ;
int V_3 ;
switch ( V_24 -> V_61 ) {
case V_62 :
V_3 = V_18 ;
break;
case V_63 :
V_3 = V_16 ;
break;
case V_64 :
V_3 = V_22 ;
break;
case V_65 :
V_3 = V_20 ;
break;
default:
F_17 () ;
return - V_34 ;
}
switch ( V_25 ) {
case V_41 :
return F_4 ( V_2 , V_3 , V_12 [ V_3 ] ) ;
default:
F_17 () ;
return - V_34 ;
}
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_66 * V_67 = F_25 ( V_2 -> V_33 ) ;
struct V_68 * V_69 = & V_2 -> V_69 ;
F_26 ( V_2 , V_70 ,
F_27 ( V_70 ) ) ;
if ( V_67 && V_67 -> V_71 )
F_26 ( V_2 , V_72 ,
F_27 ( V_72 ) ) ;
else
F_26 ( V_2 , V_73 ,
F_27 ( V_73 ) ) ;
F_28 ( V_69 , V_74 ,
F_27 ( V_74 ) ) ;
if ( V_67 && V_67 -> V_71 )
F_28 ( V_69 , V_75 ,
F_27 ( V_75 ) ) ;
else
F_28 ( V_69 , V_76 ,
F_27 ( V_76 ) ) ;
F_29 ( V_69 , V_77 ,
F_27 ( V_77 ) ) ;
if ( V_67 && V_67 -> V_71 )
F_29 ( V_69 , V_78 ,
F_27 ( V_78 ) ) ;
else
F_29 ( V_69 , V_79 ,
F_27 ( V_79 ) ) ;
F_30 ( V_69 , L_7 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
T_1 * V_12 = V_2 -> V_12 ;
int V_80 ;
if ( ! V_2 -> V_81 )
return;
F_22 ( V_2 -> V_33 , L_8 ) ;
V_2 -> V_82 = 0 ;
for ( V_80 = 1 ; V_80 < V_2 -> V_83 -> V_84 ; V_80 ++ ) {
if ( V_80 == V_7 )
continue;
if ( V_12 [ V_80 ] == V_85 [ V_80 ] )
continue;
F_4 ( V_2 , V_80 , V_12 [ V_80 ] ) ;
}
V_2 -> V_81 = 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_86 , V_80 ;
int V_87 = 0 ;
int V_88 = 0 ;
int V_89 = 0 ;
if ( ! V_27 -> V_90 ) {
F_22 ( V_2 -> V_33 , L_9 ) ;
return;
}
if ( ! V_27 -> V_91 || ! V_27 -> V_92 ) {
F_22 ( V_2 -> V_33 , L_10 ) ;
return;
}
for ( V_80 = 0 ; V_80 < F_27 ( V_93 ) ; V_80 ++ ) {
if ( V_93 [ V_80 ] == V_27 -> V_90 / V_27 -> V_92 ) {
V_88 |= V_80 << V_94 ;
break;
}
}
if ( V_80 == F_27 ( V_93 ) ) {
F_12 ( V_2 -> V_33 , L_11 ,
V_27 -> V_90 / V_27 -> V_92 ) ;
return;
}
F_14 ( V_2 , V_95 ,
V_96 , V_88 ) ;
V_86 = F_8 ( V_2 , V_97 ) ;
if ( V_86 < 0 ) {
F_12 ( V_2 -> V_33 , L_12 , V_86 ) ;
return;
}
V_86 = ( V_86 & V_98 ) >> V_99 ;
switch ( V_86 ) {
case 0 :
V_86 = V_27 -> V_90 ;
break;
case 1 :
V_86 = V_27 -> V_90 / 2 ;
break;
case 2 :
V_86 = V_27 -> V_90 / 4 ;
break;
default:
F_33 ( V_2 -> V_33 , L_13 ) ;
V_86 = V_27 -> V_100 ;
}
F_22 ( V_2 -> V_33 , L_14 , V_86 , V_27 -> V_91 ) ;
for ( V_80 = 0 ; V_80 < F_27 ( V_101 ) ; V_80 ++ ) {
if ( V_101 [ V_80 ] < 0 )
continue;
if ( V_86 / V_101 [ V_80 ] == V_27 -> V_91 ) {
F_22 ( V_2 -> V_33 , L_15 ,
V_101 [ V_80 ] , V_27 -> V_91 ) ;
V_87 |= V_80 ;
break;
}
}
if ( V_80 == F_27 ( V_101 ) ) {
F_12 ( V_2 -> V_33 , L_16 ,
V_86 / V_27 -> V_91 ) ;
return;
}
V_89 |= V_27 -> V_91 / V_27 -> V_92 ;
F_22 ( V_2 -> V_33 , L_17 ,
V_27 -> V_91 / V_27 -> V_92 , V_27 -> V_92 ) ;
F_14 ( V_2 , V_31 ,
V_102 , V_87 ) ;
F_14 ( V_2 , V_103 ,
V_104 , V_89 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
enum V_105 V_106 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_13 ;
if ( V_106 == V_2 -> V_69 . V_107 )
return 0 ;
switch ( V_106 ) {
case V_108 :
break;
case V_109 :
F_14 ( V_2 , V_110 ,
V_111 , 0x80 ) ;
F_32 ( V_2 ) ;
break;
case V_112 :
if ( V_2 -> V_69 . V_107 == V_113 ) {
V_13 = F_35 ( F_27 ( V_27 -> V_114 ) ,
V_27 -> V_114 ) ;
if ( V_13 != 0 ) {
F_12 ( V_2 -> V_33 ,
L_18 ,
V_13 ) ;
return V_13 ;
}
F_31 ( V_2 ) ;
F_14 ( V_2 , V_115 ,
V_116 |
V_117 ,
V_116 |
V_117 ) ;
F_14 ( V_2 , V_110 ,
V_111 |
V_118 ,
V_118 | 0x180 ) ;
F_19 ( 5 ) ;
}
F_14 ( V_2 , V_110 ,
V_111 , 0x100 ) ;
break;
case V_113 :
F_14 ( V_2 , V_110 ,
V_111 | V_118 , 0 ) ;
F_14 ( V_2 , V_115 ,
V_116 |
V_117 , 0 ) ;
F_36 ( F_27 ( V_27 -> V_114 ) ,
V_27 -> V_114 ) ;
break;
}
V_2 -> V_69 . V_107 = V_106 ;
return 0 ;
}
static int F_37 ( struct V_119 * V_120 ,
struct V_121 * V_122 ,
struct V_123 * V_124 )
{
struct V_125 * V_126 = V_120 -> V_127 ;
struct V_1 * V_2 = V_126 -> V_2 ;
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_80 ;
int V_128 = 0 ;
int V_129 = 0 ;
V_27 -> V_91 = F_38 ( V_122 ) ;
V_27 -> V_92 = F_39 ( V_122 ) ;
for ( V_80 = 0 ; V_80 < F_27 ( V_130 ) ; V_80 ++ ) {
if ( V_130 [ V_80 ] . V_131 == V_27 -> V_92 ) {
V_129 |= V_130 [ V_80 ] . V_3 ;
break;
}
}
if ( V_80 == F_27 ( V_130 ) ) {
F_12 ( V_2 -> V_33 , L_19 , V_27 -> V_92 ) ;
return - V_34 ;
}
if ( V_27 -> V_92 % 8000 == 0 )
V_129 |= V_132 ;
switch ( F_40 ( V_122 ) ) {
case V_133 :
break;
case V_134 :
V_128 |= 0x40 ;
break;
case V_135 :
V_128 |= 0x80 ;
break;
case V_136 :
V_128 |= 0xc0 ;
break;
default:
return - V_34 ;
}
F_14 ( V_2 , V_137 ,
V_138 , V_128 ) ;
F_14 ( V_2 , V_139 ,
V_132 |
V_140 , V_129 ) ;
F_32 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_123 * V_124 , int V_141 ,
unsigned int V_142 , int V_143 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_29 ;
switch ( V_141 ) {
case V_144 :
V_27 -> V_100 = V_144 ;
V_29 = 0 ;
break;
case V_145 :
V_27 -> V_100 = V_145 ;
V_29 = 1 << V_146 ;
break;
default:
return - V_34 ;
}
F_14 ( V_2 , V_31 , V_32 ,
V_29 ) ;
V_27 -> V_90 = V_142 ;
return 0 ;
}
static int F_42 ( struct V_123 * V_124 , unsigned int V_147 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
int V_128 = 0 ;
switch ( V_147 & V_148 ) {
case V_149 :
V_128 |= V_150 ;
case V_151 :
V_128 |= 3 ;
switch ( V_147 & V_152 ) {
case V_153 :
case V_154 :
break;
default:
return - V_34 ;
}
break;
case V_155 :
break;
case V_156 :
V_128 |= 1 ;
break;
case V_157 :
V_128 |= 2 ;
break;
default:
return - V_34 ;
}
switch ( V_147 & V_152 ) {
case V_153 :
break;
case V_154 :
V_128 |= V_158 ;
break;
case V_159 :
V_128 |= V_150 ;
break;
case V_160 :
V_128 |= V_158 | V_150 ;
break;
default:
return - V_34 ;
}
switch ( V_147 & V_161 ) {
case V_162 :
V_128 |= V_163 ;
break;
case V_164 :
break;
default:
return - V_34 ;
}
F_14 ( V_2 , V_137 ,
V_165 | V_158 | V_163 |
V_150 , V_128 ) ;
return 0 ;
}
static int F_43 ( struct V_166 * V_167 , unsigned int V_168 ,
unsigned int V_169 )
{
unsigned int V_170 ;
unsigned int div ;
unsigned int V_171 , V_172 ;
int V_80 ;
div = 1 ;
V_167 -> V_173 = 0 ;
while ( ( V_168 / div ) > 13500000 ) {
div *= 2 ;
V_167 -> V_173 ++ ;
if ( div > 4 ) {
F_44 ( L_20 ,
V_168 ) ;
return - V_34 ;
}
}
F_45 ( L_21 , V_168 , V_169 ) ;
V_168 /= div ;
div = 2 ;
while ( V_169 * div < 90000000 ) {
div ++ ;
if ( div > 64 ) {
F_44 ( L_22 ,
V_169 ) ;
return - V_34 ;
}
}
V_170 = V_169 * div ;
V_167 -> V_174 = div - 1 ;
F_45 ( L_23 , V_170 ) ;
for ( V_80 = 0 ; V_80 < F_27 ( V_175 ) ; V_80 ++ ) {
if ( V_175 [ V_80 ] . V_176 <= V_168 && V_168 <= V_175 [ V_80 ] . V_177 ) {
V_167 -> V_178 = V_175 [ V_80 ] . V_178 ;
V_171 = V_175 [ V_80 ] . V_179 ;
break;
}
}
if ( V_80 == F_27 ( V_175 ) ) {
F_44 ( L_24 , V_168 ) ;
return - V_34 ;
}
V_167 -> V_180 = V_170 / ( V_171 * V_168 ) ;
if ( V_170 % V_168 == 0 ) {
V_167 -> V_181 = 0 ;
V_167 -> V_182 = 0 ;
} else {
V_172 = F_46 ( V_170 , V_171 * V_168 ) ;
V_167 -> V_181 = ( V_170 - ( V_167 -> V_180 * V_171 * V_168 ) )
/ V_172 ;
V_167 -> V_182 = ( V_171 * V_168 ) / V_172 ;
}
F_45 ( L_25 ,
V_167 -> V_180 , V_167 -> V_181 , V_167 -> V_182 ) ;
F_45 ( L_26 ,
V_167 -> V_178 , V_167 -> V_174 ,
V_167 -> V_173 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 , int V_183 , int V_184 ,
unsigned int V_168 , unsigned int V_169 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
struct V_166 V_167 ;
unsigned long V_28 ;
int V_13 ;
int V_185 = F_8 ( V_2 , V_37 ) & V_38 ;
if ( V_184 == V_27 -> V_186 && V_168 == V_27 -> V_187 &&
V_169 == V_27 -> V_188 )
return 0 ;
if ( V_169 == 0 ) {
F_22 ( V_2 -> V_33 , L_27 ) ;
V_27 -> V_187 = 0 ;
V_27 -> V_188 = 0 ;
F_14 ( V_2 , V_37 ,
V_38 , 0 ) ;
return 0 ;
}
V_13 = F_43 ( & V_167 , V_168 , V_169 ) ;
if ( V_13 != 0 )
return V_13 ;
switch ( V_183 ) {
case V_189 :
case V_190 :
case V_191 :
V_185 |= ( V_183 - 1 ) << V_192 ;
break;
case V_193 :
F_14 ( V_2 , V_37 ,
V_194 , V_194 ) ;
F_14 ( V_2 , V_195 ,
V_196 , V_196 ) ;
break;
default:
F_12 ( V_2 -> V_33 , L_28 , V_13 ) ;
return - V_34 ;
}
if ( V_167 . V_181 || V_167 . V_182 )
V_185 |= V_197 ;
F_14 ( V_2 , V_37 , V_38 , 0 ) ;
F_14 ( V_2 , V_198 ,
V_199 |
V_200 ,
( V_167 . V_174 << V_201 ) |
( V_167 . V_173 ) ) ;
F_14 ( V_2 , V_202 ,
V_203 , V_167 . V_178 ) ;
F_4 ( V_2 , V_204 , V_167 . V_181 ) ;
F_4 ( V_2 , V_205 , V_167 . V_182 ) ;
F_4 ( V_2 , V_206 , V_167 . V_180 ) ;
F_13 ( & V_27 -> V_36 ) ;
F_14 ( V_2 , V_37 ,
V_197 | V_207 |
V_38 , V_185 ) ;
F_22 ( V_2 -> V_33 , L_29 , V_168 , V_169 ) ;
V_13 = 0 ;
if ( V_185 & V_38 ) {
if ( V_27 -> V_39 )
V_28 = F_15 ( 5 ) ;
else
V_28 = F_15 ( 1 ) ;
V_28 = F_16 ( & V_27 -> V_36 ,
V_28 ) ;
if ( V_28 == 0 && V_27 -> V_39 ) {
F_12 ( V_2 -> V_33 , L_30 ) ;
V_13 = - V_208 ;
}
}
V_27 -> V_187 = V_168 ;
V_27 -> V_188 = V_169 ;
V_27 -> V_186 = V_184 ;
return V_13 ;
}
static int F_48 ( struct V_123 * V_124 , int V_209 )
{
struct V_1 * V_2 = V_124 -> V_2 ;
int V_210 ;
if ( V_209 )
V_210 = V_211 ;
else
V_210 = 0 ;
return F_14 ( V_2 , V_212 ,
V_211 , V_210 ) ;
}
static void F_49 ( struct V_213 * V_214 )
{
struct V_26 * V_27 = F_50 ( V_214 ,
struct V_26 ,
V_215 . V_214 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
int V_216 = 0 ;
int V_217 = 0 ;
int V_3 ;
V_3 = F_8 ( V_2 , V_218 ) ;
if ( V_3 & V_219 ) {
V_216 |= V_220 ;
V_217 |= V_221 ;
}
if ( V_3 & V_222 ) {
V_216 |= V_223 ;
V_217 |= V_224 ;
}
F_51 ( V_27 -> V_225 , V_216 ,
V_220 | V_223 ) ;
F_14 ( V_2 , V_226 ,
V_224 |
V_221 , V_217 ) ;
}
static T_2 F_52 ( int V_39 , void * V_227 )
{
struct V_1 * V_2 = V_227 ;
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_228 ;
int V_229 ;
V_228 = F_8 ( V_2 , V_230 ) ;
V_229 = F_8 ( V_2 , V_231 ) ;
V_229 &= ~ V_228 ;
F_4 ( V_2 , V_231 , V_229 ) ;
if ( V_229 & V_232 ) {
F_22 ( V_2 -> V_33 , L_31 ) ;
F_53 ( & V_27 -> V_36 ) ;
}
if ( V_229 & V_233 )
F_12 ( V_2 -> V_33 , L_32 ) ;
if ( V_229 & V_234 )
F_54 ( V_2 -> V_33 , L_33 ) ;
if ( V_229 & ( V_235 | V_236 ) ) {
F_22 ( V_2 -> V_33 , L_34 ) ;
#ifndef F_55
F_56 ( F_57 ( V_2 -> V_33 ) ) ;
#endif
F_58 ( V_2 -> V_33 , 300 ) ;
F_59 ( & V_27 -> V_215 ,
F_15 ( 250 ) ) ;
}
return V_237 ;
}
int F_60 ( struct V_1 * V_2 , struct V_238 * V_225 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_239 , V_240 ;
V_27 -> V_225 = V_225 ;
if ( V_225 ) {
V_239 = 0 ;
V_240 = V_241 ;
} else {
V_239 = V_236 | V_235 ;
V_240 = 0 ;
}
F_14 ( V_2 , V_230 ,
V_236 | V_235 , V_239 ) ;
F_14 ( V_2 , V_218 ,
V_241 , V_240 ) ;
F_51 ( V_27 -> V_225 , 0 ,
V_220 | V_223 ) ;
return 0 ;
}
static void F_61 ( struct V_213 * V_214 )
{
struct V_26 * V_27 =
F_50 ( V_214 , struct V_26 , V_242 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
struct V_68 * V_69 = & V_2 -> V_69 ;
int V_80 ;
int V_3 = 0 ;
int V_243 = 0 ;
if ( V_27 -> V_244 ) {
for ( V_80 = 0 ; V_80 < F_27 ( V_245 ) ; V_80 ++ ) {
if ( abs ( V_27 -> V_244 - V_245 [ V_80 ] ) <
abs ( V_27 -> V_244 - V_245 [ V_243 ] ) )
V_243 = V_80 ;
}
F_22 ( V_2 -> V_33 , L_35 ,
V_245 [ V_243 ] , V_27 -> V_244 ) ;
V_3 = V_246 | ( V_243 << V_247 ) ;
F_62 ( V_69 , L_7 ) ;
} else {
F_22 ( V_2 -> V_33 , L_36 ) ;
F_30 ( V_69 , L_7 ) ;
}
F_14 ( V_2 , V_248 ,
V_246 | V_249 , V_3 ) ;
F_63 ( V_69 ) ;
}
static int F_64 ( struct V_250 * V_33 , unsigned int type ,
unsigned int V_251 , int V_252 )
{
struct V_1 * V_2 = F_65 ( V_33 ) ;
struct V_26 * V_27 = F_11 ( V_2 ) ;
F_22 ( V_2 -> V_33 , L_37 , V_251 , V_252 ) ;
switch ( V_251 ) {
case V_253 :
if ( V_252 )
V_252 = 1000 ;
case V_254 :
break;
default:
return - 1 ;
}
V_27 -> V_244 = V_252 ;
F_66 ( & V_27 -> V_242 ) ;
return 0 ;
}
static T_3 F_67 ( struct V_255 * V_33 ,
struct V_256 * V_257 ,
const char * V_258 , T_4 V_259 )
{
struct V_26 * V_27 = F_68 ( V_33 ) ;
long int time ;
int V_13 ;
V_13 = F_69 ( V_258 , 10 , & time ) ;
if ( V_13 != 0 )
return V_13 ;
F_70 ( V_27 -> V_260 , V_261 , V_254 , time ) ;
return V_259 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_13 ;
V_27 -> V_260 = F_72 () ;
if ( ! V_27 -> V_260 ) {
F_12 ( V_2 -> V_33 , L_38 ) ;
return;
}
F_73 ( & V_27 -> V_242 , F_61 ) ;
V_27 -> V_244 = 0 ;
V_27 -> V_260 -> V_262 = L_39 ;
V_27 -> V_260 -> V_263 = F_57 ( V_2 -> V_33 ) ;
V_27 -> V_260 -> V_264 . V_265 = V_266 ;
V_27 -> V_260 -> V_267 [ 0 ] = F_74 ( V_261 ) ;
V_27 -> V_260 -> V_268 [ 0 ] = F_74 ( V_253 ) | F_74 ( V_254 ) ;
V_27 -> V_260 -> V_25 = F_64 ;
V_27 -> V_260 -> V_33 . V_269 = V_2 -> V_33 ;
F_75 ( V_27 -> V_260 , V_2 ) ;
V_13 = F_76 ( V_27 -> V_260 ) ;
if ( V_13 != 0 ) {
F_77 ( V_27 -> V_260 ) ;
V_27 -> V_260 = NULL ;
F_12 ( V_2 -> V_33 , L_40 ) ;
}
V_13 = F_78 ( V_2 -> V_33 , & V_270 ) ;
if ( V_13 != 0 ) {
F_12 ( V_2 -> V_33 , L_41 ,
V_13 ) ;
}
}
static void F_79 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
F_80 ( V_2 -> V_33 , & V_270 ) ;
F_81 ( V_27 -> V_260 ) ;
F_82 ( & V_27 -> V_242 ) ;
V_27 -> V_260 = NULL ;
F_14 ( V_2 , V_248 , V_246 , 0 ) ;
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
int V_210 = 0 ;
switch ( V_271 ) {
case 2 :
V_228 = V_272 ;
V_210 = 1 << V_273 ;
break;
case 3 :
V_228 = V_274 ;
V_210 = 1 << V_275 ;
break;
default:
break;
}
if ( V_228 )
F_14 ( V_2 , V_276 ,
V_228 , V_210 ) ;
}
static inline struct V_26 * F_84 ( struct V_277 * V_278 )
{
return F_50 ( V_278 , struct V_26 , V_277 ) ;
}
static int F_85 ( struct V_277 * V_278 , unsigned V_279 )
{
struct V_26 * V_27 = F_84 ( V_278 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
switch ( V_279 + 1 ) {
case 2 :
case 3 :
case 5 :
case 6 :
break;
default:
return - V_34 ;
}
F_83 ( V_2 , V_279 + 1 ) ;
return 0 ;
}
static void F_86 ( struct V_277 * V_278 , unsigned V_279 , int V_280 )
{
struct V_26 * V_27 = F_84 ( V_278 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
F_14 ( V_2 , V_281 + V_279 ,
V_282 , ! ! V_280 << V_283 ) ;
}
static int F_87 ( struct V_277 * V_278 ,
unsigned V_279 , int V_280 )
{
struct V_26 * V_27 = F_84 ( V_278 ) ;
struct V_1 * V_2 = V_27 -> V_2 ;
int V_210 ;
V_210 = ( 1 << V_284 ) | ( V_280 << V_283 ) ;
return F_14 ( V_2 , V_281 + V_279 ,
V_285 | V_282 , V_210 ) ;
}
static void F_88 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
struct V_66 * V_67 = F_25 ( V_2 -> V_33 ) ;
int V_13 ;
V_27 -> V_277 = V_286 ;
V_27 -> V_277 . V_287 = V_288 ;
V_27 -> V_277 . V_33 = V_2 -> V_33 ;
if ( V_67 && V_67 -> V_289 )
V_27 -> V_277 . V_290 = V_67 -> V_289 ;
else
V_27 -> V_277 . V_290 = - 1 ;
V_13 = F_89 ( & V_27 -> V_277 ) ;
if ( V_13 != 0 )
F_12 ( V_2 -> V_33 , L_42 , V_13 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_13 ;
V_13 = F_91 ( & V_27 -> V_277 ) ;
if ( V_13 != 0 )
F_12 ( V_2 -> V_33 , L_43 , V_13 ) ;
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
struct V_26 * V_27 = F_11 ( V_2 ) ;
struct V_66 * V_67 = F_25 ( V_2 -> V_33 ) ;
T_1 * V_12 = V_2 -> V_12 ;
int V_80 , V_291 , V_217 ;
bool V_292 , V_293 ;
V_27 -> V_2 = V_2 ;
F_93 ( & V_27 -> V_215 , F_49 ) ;
F_94 ( & V_27 -> V_36 ) ;
V_2 -> V_81 = 1 ;
V_2 -> V_69 . V_294 = 1 ;
V_13 = F_95 ( V_2 , 16 , 16 , V_295 ) ;
if ( V_13 != 0 ) {
F_12 ( V_2 -> V_33 , L_44 , V_13 ) ;
goto V_296;
}
for ( V_80 = 0 ; V_80 < F_27 ( V_27 -> V_114 ) ; V_80 ++ )
V_27 -> V_114 [ V_80 ] . V_297 = V_298 [ V_80 ] ;
V_13 = F_96 ( V_2 -> V_33 , F_27 ( V_27 -> V_114 ) ,
V_27 -> V_114 ) ;
if ( V_13 != 0 ) {
F_12 ( V_2 -> V_33 , L_45 , V_13 ) ;
goto V_296;
}
V_27 -> V_299 [ 0 ] . V_300 = V_301 ;
V_27 -> V_299 [ 1 ] . V_300 = V_302 ;
V_27 -> V_299 [ 2 ] . V_300 = V_303 ;
V_27 -> V_299 [ 3 ] . V_300 = V_304 ;
V_27 -> V_299 [ 4 ] . V_300 = V_305 ;
V_27 -> V_299 [ 5 ] . V_300 = V_306 ;
V_27 -> V_299 [ 6 ] . V_300 = V_307 ;
V_27 -> V_299 [ 7 ] . V_300 = V_308 ;
for ( V_80 = 0 ; V_80 < F_27 ( V_27 -> V_114 ) ; V_80 ++ ) {
V_13 = F_97 ( V_27 -> V_114 [ V_80 ] . V_309 ,
& V_27 -> V_299 [ V_80 ] ) ;
if ( V_13 != 0 ) {
F_12 ( V_2 -> V_33 ,
L_46 ,
V_13 ) ;
}
}
V_13 = F_35 ( F_27 ( V_27 -> V_114 ) ,
V_27 -> V_114 ) ;
if ( V_13 != 0 ) {
F_12 ( V_2 -> V_33 , L_18 , V_13 ) ;
goto V_310;
}
V_13 = F_8 ( V_2 , V_7 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 -> V_33 , L_47 ) ;
goto V_311;
}
if ( V_13 != V_85 [ V_7 ] ) {
F_12 ( V_2 -> V_33 , L_48 ,
V_13 , V_85 [ V_7 ] ) ;
V_13 = - V_34 ;
goto V_311;
}
V_13 = F_8 ( V_2 , V_312 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 -> V_33 , L_49 ,
V_13 ) ;
goto V_311;
}
F_98 ( V_2 -> V_33 , L_50 ,
( V_13 & V_313 ) >> V_314 ,
( ( V_13 & V_315 ) >> V_316 )
+ 'A' ) ;
V_13 = F_3 ( V_2 ) ;
if ( V_13 < 0 ) {
F_12 ( V_2 -> V_33 , L_51 ) ;
goto V_311;
}
F_14 ( V_2 , V_31 , V_317 , 0 ) ;
F_14 ( V_2 , V_31 ,
V_318 , V_318 ) ;
F_36 ( F_27 ( V_27 -> V_114 ) , V_27 -> V_114 ) ;
if ( V_67 ) {
for ( V_80 = 0 ; V_80 < F_27 ( V_67 -> V_319 ) ; V_80 ++ )
if ( V_67 -> V_319 [ V_80 ] ) {
F_83 ( V_2 , V_80 + 1 ) ;
F_4 ( V_2 , 0x200 + V_80 ,
V_67 -> V_319 [ V_80 ] & 0xffff ) ;
}
if ( V_67 -> V_71 )
V_12 [ V_320 ]
|= V_321 ;
if ( V_67 -> V_322 )
F_14 ( V_2 , V_218 ,
V_241 |
V_323 |
V_324 |
V_325 ,
V_67 -> V_322 ) ;
}
F_14 ( V_2 , V_326 ,
V_327 , V_327 ) ;
F_14 ( V_2 , V_312 ,
V_327 , V_327 ) ;
F_14 ( V_2 , V_328 ,
V_329 , V_329 ) ;
F_14 ( V_2 , V_330 ,
V_329 , V_329 ) ;
F_14 ( V_2 , V_331 ,
V_332 , V_332 ) ;
F_14 ( V_2 , V_333 ,
V_332 , V_332 ) ;
F_14 ( V_2 , V_20 ,
V_334 , V_334 ) ;
F_14 ( V_2 , V_22 ,
V_334 , V_334 ) ;
F_14 ( V_2 , V_16 ,
V_335 , V_335 ) ;
F_14 ( V_2 , V_18 ,
V_335 , V_335 ) ;
F_14 ( V_2 , V_336 , V_337 , 0 ) ;
F_24 ( V_2 ) ;
V_292 = false ;
V_293 = false ;
for ( V_80 = 0 ; V_80 < V_288 ; V_80 ++ ) {
switch ( F_8 ( V_2 , V_281 + V_80 )
& V_285 ) {
case V_338 :
V_292 = true ;
break;
case V_339 :
V_293 = true ;
break;
default:
break;
}
}
if ( ! V_292 || ! V_293 ) {
F_22 ( V_2 -> V_33 , L_52 ) ;
F_99 ( & V_2 -> V_69 , L_53 ) ;
}
if ( V_292 != V_293 )
F_33 ( V_2 -> V_33 , L_54 ) ;
F_71 ( V_2 ) ;
F_88 ( V_2 ) ;
if ( V_27 -> V_39 ) {
if ( V_67 && V_67 -> V_340 ) {
V_291 = V_341 ;
V_217 = V_342 ;
} else {
V_291 = V_343 ;
V_217 = 0 ;
}
F_14 ( V_2 , V_344 ,
V_342 , V_217 ) ;
V_13 = F_100 ( V_27 -> V_39 , NULL , F_52 ,
V_291 | V_345 ,
L_55 , V_2 ) ;
if ( V_13 != 0 ) {
F_12 ( V_2 -> V_33 , L_56 ,
V_27 -> V_39 , V_13 ) ;
V_27 -> V_39 = 0 ;
} else {
F_14 ( V_2 ,
V_230 ,
V_232 |
V_234 |
V_233 , 0 ) ;
}
}
return 0 ;
V_311:
F_36 ( F_27 ( V_27 -> V_114 ) , V_27 -> V_114 ) ;
V_310:
F_101 ( F_27 ( V_27 -> V_114 ) , V_27 -> V_114 ) ;
V_296:
return V_13 ;
}
static int F_102 ( struct V_1 * V_2 )
{
struct V_26 * V_27 = F_11 ( V_2 ) ;
int V_80 ;
if ( V_27 -> V_39 )
F_103 ( V_27 -> V_39 , V_2 ) ;
F_104 ( & V_27 -> V_215 ) ;
F_90 ( V_2 ) ;
F_79 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < F_27 ( V_27 -> V_114 ) ; V_80 ++ )
F_105 ( V_27 -> V_114 [ V_80 ] . V_309 ,
& V_27 -> V_299 [ V_80 ] ) ;
F_101 ( F_27 ( V_27 -> V_114 ) , V_27 -> V_114 ) ;
return 0 ;
}
static T_5 int F_106 ( struct V_346 * V_347 ,
const struct V_348 * V_264 )
{
struct V_26 * V_27 ;
int V_13 ;
V_27 = F_107 ( sizeof( struct V_26 ) , V_349 ) ;
if ( V_27 == NULL )
return - V_350 ;
F_108 ( V_347 , V_27 ) ;
V_27 -> V_39 = V_347 -> V_39 ;
V_13 = F_109 ( & V_347 -> V_33 ,
& V_351 , & V_352 , 1 ) ;
if ( V_13 < 0 )
F_110 ( V_27 ) ;
return V_13 ;
}
static T_6 int F_111 ( struct V_346 * V_353 )
{
F_112 ( & V_353 -> V_33 ) ;
F_110 ( F_113 ( V_353 ) ) ;
return 0 ;
}
static int T_7 F_114 ( void )
{
int V_13 ;
#if F_115 ( V_354 ) || F_115 ( V_355 )
V_13 = F_116 ( & V_356 ) ;
if ( V_13 != 0 ) {
F_117 ( V_357 L_57 ,
V_13 ) ;
}
#endif
return 0 ;
}
static void T_8 F_118 ( void )
{
#if F_115 ( V_354 ) || F_115 ( V_355 )
F_119 ( & V_356 ) ;
#endif
}
