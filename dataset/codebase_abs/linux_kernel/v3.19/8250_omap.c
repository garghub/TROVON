static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + ( V_3 << V_2 -> V_4 . V_6 ) ) ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_2 V_9 = 255 ;
T_2 V_10 ;
V_10 = F_4 ( V_2 , V_11 ) ;
if ( V_10 == V_8 -> V_12 )
return;
F_5 ( V_2 , V_11 , V_8 -> V_12 ) ;
F_6 ( 2 ) ;
F_5 ( V_2 , V_13 , V_2 -> V_14 | V_15 |
V_16 ) ;
while ( V_17 != ( F_4 ( V_2 , V_18 ) &
( V_17 | V_19 ) ) ) {
V_9 -- ;
if ( ! V_9 ) {
F_7 ( V_2 -> V_4 . V_20 , L_1 ,
F_4 ( V_2 , V_18 ) ) ;
break;
}
F_6 ( 1 ) ;
}
}
static void F_8 ( struct V_21 * V_4 , unsigned int V_22 ,
struct V_7 * V_8 )
{
unsigned int V_23 = V_4 -> V_23 ;
unsigned int V_24 , V_25 ;
unsigned int V_26 , V_27 ;
if ( V_22 == 38400 && ( V_4 -> V_28 & V_29 ) == V_30 ) {
V_8 -> V_31 = V_4 -> V_32 & 0xffff ;
if ( V_4 -> V_32 & ( 1 << 16 ) )
V_8 -> V_12 = V_33 ;
else
V_8 -> V_12 = V_34 ;
return;
}
V_24 = F_9 ( V_23 , 13 * V_22 ) ;
V_25 = F_9 ( V_23 , 16 * V_22 ) ;
if ( ! V_24 )
V_24 = 1 ;
if ( ! V_25 )
V_25 = 1 ;
V_26 = abs ( V_22 - V_23 / 13 / V_24 ) ;
V_27 = abs ( V_22 - V_23 / 16 / V_25 ) ;
if ( V_26 >= V_27 ) {
V_8 -> V_12 = V_34 ;
V_8 -> V_31 = V_25 ;
} else {
V_8 -> V_12 = V_33 ;
V_8 -> V_31 = V_24 ;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_2 V_35 ;
V_35 = F_4 ( V_2 , V_36 ) ;
if ( V_35 == V_8 -> V_37 )
return;
if ( V_8 -> V_37 & V_38 )
F_5 ( V_2 , V_36 ,
V_8 -> V_37 & ~ V_38 ) ;
F_5 ( V_2 , V_36 , V_8 -> V_37 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = V_2 -> V_4 . V_39 ;
struct V_40 * V_41 = V_2 -> V_41 ;
if ( V_41 && V_41 -> V_42 ) {
V_8 -> V_43 = 1 ;
return;
}
F_5 ( V_2 , V_44 , V_45 ) ;
F_5 ( V_2 , V_46 , V_47 ) ;
F_5 ( V_2 , V_44 , V_48 ) ;
F_5 ( V_2 , V_49 , V_50 ) ;
F_5 ( V_2 , V_13 , V_2 -> V_14 ) ;
F_10 ( V_2 , V_8 ) ;
F_5 ( V_2 , V_44 , V_45 ) ;
F_5 ( V_2 , V_51 , F_12 ( 16 ) |
F_13 ( 52 ) ) ;
F_5 ( V_2 , V_52 ,
F_14 ( V_53 ) << V_54 |
F_14 ( V_55 ) << V_56 ) ;
F_5 ( V_2 , V_44 , 0 ) ;
F_5 ( V_2 , V_49 , V_2 -> V_57 ) ;
F_5 ( V_2 , V_58 , V_2 -> V_59 ) ;
F_5 ( V_2 , V_44 , V_45 ) ;
F_15 ( V_2 , V_8 -> V_31 ) ;
F_5 ( V_2 , V_46 , V_8 -> V_60 ) ;
F_5 ( V_2 , V_44 , V_45 ) ;
F_5 ( V_2 , V_61 , V_8 -> V_62 ) ;
F_5 ( V_2 , V_63 , V_8 -> V_64 ) ;
F_5 ( V_2 , V_44 , V_2 -> V_65 ) ;
if ( V_8 -> V_66 & V_67 )
F_3 ( V_2 , V_8 ) ;
else
F_5 ( V_2 , V_11 , V_8 -> V_12 ) ;
V_2 -> V_4 . V_68 -> V_69 ( & V_2 -> V_4 , V_2 -> V_4 . V_70 ) ;
}
static void F_16 ( struct V_21 * V_4 ,
struct V_71 * V_72 ,
struct V_71 * V_73 )
{
struct V_1 * V_2 =
F_17 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = V_2 -> V_4 . V_39 ;
unsigned char V_74 = 0 ;
unsigned int V_22 ;
switch ( V_72 -> V_75 & V_76 ) {
case V_77 :
V_74 = V_78 ;
break;
case V_79 :
V_74 = V_80 ;
break;
case V_81 :
V_74 = V_82 ;
break;
default:
case V_83 :
V_74 = V_84 ;
break;
}
if ( V_72 -> V_75 & V_85 )
V_74 |= V_86 ;
if ( V_72 -> V_75 & V_87 )
V_74 |= V_88 ;
if ( ! ( V_72 -> V_75 & V_89 ) )
V_74 |= V_90 ;
if ( V_72 -> V_75 & V_91 )
V_74 |= V_92 ;
V_22 = F_18 ( V_4 , V_72 , V_73 ,
V_4 -> V_23 / 16 / 0xffff ,
V_4 -> V_23 / 13 ) ;
F_8 ( V_4 , V_22 , V_8 ) ;
F_19 ( V_4 -> V_20 ) ;
F_20 ( & V_4 -> V_93 ) ;
F_21 ( V_4 , V_72 -> V_75 , V_22 ) ;
V_2 -> V_4 . V_94 = V_95 | V_17 | V_19 ;
if ( V_72 -> V_96 & V_97 )
V_2 -> V_4 . V_94 |= V_98 | V_99 ;
if ( V_72 -> V_96 & ( V_100 | V_101 ) )
V_2 -> V_4 . V_94 |= V_102 ;
V_2 -> V_4 . V_103 = 0 ;
if ( V_72 -> V_96 & V_104 )
V_2 -> V_4 . V_103 |= V_99 | V_98 ;
if ( V_72 -> V_96 & V_100 ) {
V_2 -> V_4 . V_103 |= V_102 ;
if ( V_72 -> V_96 & V_104 )
V_2 -> V_4 . V_103 |= V_95 ;
}
if ( ( V_72 -> V_75 & V_105 ) == 0 )
V_2 -> V_4 . V_103 |= V_19 ;
V_2 -> V_59 &= ~ V_106 ;
if ( F_22 ( & V_2 -> V_4 , V_72 -> V_75 ) )
V_2 -> V_59 |= V_106 ;
V_2 -> V_65 = V_74 ;
V_2 -> V_14 = V_107 ;
V_2 -> V_14 |= F_23 ( V_53 ) << V_108 ;
V_2 -> V_14 |= F_23 ( V_55 ) << V_109 ;
V_8 -> V_37 = V_110 | V_111 |
V_112 ;
if ( V_2 -> V_41 )
V_8 -> V_37 |= V_113 |
V_114 ;
V_8 -> V_62 = V_72 -> V_115 [ V_116 ] ;
V_8 -> V_64 = V_72 -> V_115 [ V_117 ] ;
V_8 -> V_60 = 0 ;
V_2 -> V_57 &= ~ ( V_118 | V_119 ) ;
if ( V_72 -> V_75 & V_120 && V_2 -> V_4 . V_28 & V_121 ) {
V_8 -> V_60 |= V_122 | V_123 ;
V_2 -> V_57 |= V_118 ;
} else if ( V_2 -> V_4 . V_28 & V_124 ) {
if ( V_72 -> V_96 & V_125 )
V_8 -> V_60 |= V_126 ;
if ( V_72 -> V_96 & V_127 )
V_8 -> V_60 |= V_128 ;
if ( V_72 -> V_96 & V_129 )
V_2 -> V_57 |= V_119 ;
}
F_11 ( V_2 ) ;
F_24 ( & V_2 -> V_4 . V_93 ) ;
F_25 ( V_4 -> V_20 ) ;
F_26 ( V_4 -> V_20 ) ;
V_8 -> V_130 = V_131 * 64 * 8 / V_22 ;
V_8 -> V_132 = V_8 -> V_130 ;
F_27 ( & V_8 -> V_133 ) ;
if ( F_28 ( V_72 ) )
F_29 ( V_72 , V_22 , V_22 ) ;
}
static void F_30 ( struct V_21 * V_4 , unsigned int V_134 ,
unsigned int V_135 )
{
struct V_1 * V_2 =
F_17 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = V_2 -> V_4 . V_39 ;
F_19 ( V_4 -> V_20 ) ;
F_5 ( V_2 , V_44 , V_45 ) ;
F_5 ( V_2 , V_46 , V_8 -> V_60 | V_47 ) ;
F_5 ( V_2 , V_44 , 0 ) ;
F_5 ( V_2 , V_58 , ( V_134 != 0 ) ? V_136 : 0 ) ;
F_5 ( V_2 , V_44 , V_45 ) ;
F_5 ( V_2 , V_46 , V_8 -> V_60 ) ;
F_5 ( V_2 , V_44 , 0 ) ;
F_25 ( V_4 -> V_20 ) ;
F_26 ( V_4 -> V_20 ) ;
}
static void F_31 ( struct V_1 * V_2 ,
struct V_7 * V_8 )
{
T_1 V_137 , V_138 ;
T_3 V_139 , V_140 , V_141 ;
V_137 = F_1 ( V_2 , V_142 ) ;
V_138 = V_137 >> V_143 ;
switch ( V_138 ) {
case 0 :
V_140 = ( V_137 & V_144 ) >>
V_145 ;
V_141 = ( V_137 & V_146 ) ;
break;
case 1 :
V_140 = ( V_137 & V_147 ) >>
V_148 ;
V_141 = ( V_137 & V_149 ) ;
break;
default:
F_32 ( V_2 -> V_4 . V_20 ,
L_2 ) ;
V_140 = 0xff ;
V_141 = 0xff ;
}
V_139 = F_33 ( V_140 , V_141 ) ;
switch ( V_139 ) {
case V_150 :
V_8 -> V_66 = V_67 ;
break;
case V_151 :
V_8 -> V_66 = V_67 |
V_152 ;
break;
case V_153 :
V_8 -> V_66 = V_67 |
V_152 ;
break;
default:
break;
}
}
static void F_34 ( struct V_154 * V_155 )
{
struct V_7 * V_8 ;
V_8 = F_17 ( V_155 , struct V_7 , V_133 ) ;
F_35 ( & V_8 -> V_156 , V_8 -> V_132 ) ;
}
static T_4 F_36 ( int V_157 , void * V_158 )
{
struct V_21 * V_4 = V_158 ;
int V_159 ;
V_159 = V_4 -> V_160 ( V_4 ) ;
if ( V_159 )
return V_161 ;
return V_162 ;
}
static int F_37 ( struct V_21 * V_4 )
{
struct V_1 * V_2 =
F_17 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = V_4 -> V_39 ;
int V_159 ;
if ( V_8 -> V_163 ) {
V_159 = F_38 ( V_8 -> V_163 , F_36 ,
V_4 -> V_164 , L_3 , V_4 ) ;
if ( V_159 )
return V_159 ;
F_39 ( V_8 -> V_163 ) ;
}
F_19 ( V_4 -> V_20 ) ;
V_159 = F_40 ( V_4 ) ;
if ( V_159 )
goto V_165;
#ifdef F_41
V_2 -> V_166 |= V_167 ;
#endif
V_8 -> V_168 = V_169 ;
if ( V_8 -> V_66 & V_152 )
V_8 -> V_168 |= V_170 ;
F_5 ( V_2 , V_171 , V_8 -> V_168 ) ;
if ( V_2 -> V_41 )
V_2 -> V_41 -> V_172 ( V_2 , 0 ) ;
F_25 ( V_4 -> V_20 ) ;
F_26 ( V_4 -> V_20 ) ;
return 0 ;
V_165:
F_25 ( V_4 -> V_20 ) ;
F_26 ( V_4 -> V_20 ) ;
if ( V_8 -> V_163 )
F_42 ( V_8 -> V_163 , V_4 ) ;
return V_159 ;
}
static void F_43 ( struct V_21 * V_4 )
{
struct V_1 * V_2 =
F_17 ( V_4 , struct V_1 , V_4 ) ;
struct V_7 * V_8 = V_4 -> V_39 ;
F_44 ( & V_8 -> V_133 ) ;
if ( V_2 -> V_41 )
V_2 -> V_41 -> V_172 ( V_2 , V_173 ) ;
F_19 ( V_4 -> V_20 ) ;
F_5 ( V_2 , V_171 , 0 ) ;
F_45 ( V_4 ) ;
F_25 ( V_4 -> V_20 ) ;
F_26 ( V_4 -> V_20 ) ;
if ( V_8 -> V_163 )
F_42 ( V_8 -> V_163 , V_4 ) ;
}
static void F_46 ( struct V_21 * V_4 )
{
unsigned long V_28 ;
struct V_1 * V_2 =
F_17 ( V_4 , struct V_1 , V_4 ) ;
F_19 ( V_4 -> V_20 ) ;
F_47 ( & V_4 -> V_93 , V_28 ) ;
V_2 -> V_59 &= ~ ( V_174 | V_175 ) ;
F_5 ( V_2 , V_58 , V_2 -> V_59 ) ;
F_48 ( & V_4 -> V_93 , V_28 ) ;
F_25 ( V_4 -> V_20 ) ;
F_26 ( V_4 -> V_20 ) ;
}
static void F_49 ( struct V_21 * V_4 )
{
unsigned long V_28 ;
struct V_1 * V_2 =
F_17 ( V_4 , struct V_1 , V_4 ) ;
F_19 ( V_4 -> V_20 ) ;
F_47 ( & V_4 -> V_93 , V_28 ) ;
V_2 -> V_59 |= V_174 | V_175 ;
F_5 ( V_2 , V_58 , V_2 -> V_59 ) ;
F_48 ( & V_4 -> V_93 , V_28 ) ;
F_25 ( V_4 -> V_20 ) ;
F_26 ( V_4 -> V_20 ) ;
}
static void F_50 ( struct V_1 * V_176 , bool error )
{
struct V_40 * V_41 = V_176 -> V_41 ;
struct V_177 * V_177 = & V_176 -> V_4 . V_134 -> V_4 ;
struct V_178 V_134 ;
int V_179 ;
F_51 ( V_41 -> V_180 -> V_181 -> V_20 , V_41 -> V_182 ,
V_41 -> V_183 , V_184 ) ;
V_41 -> V_185 = 0 ;
F_52 ( V_41 -> V_180 , V_41 -> V_186 , & V_134 ) ;
F_53 ( V_41 -> V_180 ) ;
V_179 = V_41 -> V_183 - V_134 . V_187 ;
F_54 ( V_177 , V_41 -> V_188 , V_179 ) ;
V_176 -> V_4 . V_189 . V_190 += V_179 ;
if ( ! error )
F_55 ( V_176 , 0 ) ;
F_56 ( V_177 ) ;
}
static void F_57 ( void * V_191 )
{
F_50 ( V_191 , false ) ;
}
static int F_55 ( struct V_1 * V_176 , unsigned int V_192 )
{
struct V_40 * V_41 = V_176 -> V_41 ;
struct V_193 * V_194 ;
switch ( V_192 & 0x3f ) {
case V_195 :
if ( V_41 -> V_185 ) {
F_58 ( V_41 -> V_180 ) ;
F_50 ( V_176 , true ) ;
}
return - V_196 ;
case V_173 :
if ( V_41 -> V_185 ) {
F_58 ( V_41 -> V_180 ) ;
F_50 ( V_176 , true ) ;
}
return - V_197 ;
case V_198 :
if ( V_41 -> V_185 ) {
F_58 ( V_41 -> V_180 ) ;
F_50 ( V_176 , true ) ;
}
return - V_197 ;
default:
break;
}
if ( V_41 -> V_185 )
return 0 ;
V_194 = F_59 ( V_41 -> V_180 , V_41 -> V_182 ,
V_41 -> V_183 , V_199 ,
V_200 | V_201 ) ;
if ( ! V_194 )
return - V_202 ;
V_41 -> V_185 = 1 ;
V_194 -> V_203 = F_57 ;
V_194 -> V_204 = V_176 ;
V_41 -> V_186 = F_60 ( V_194 ) ;
F_61 ( V_41 -> V_180 -> V_181 -> V_20 , V_41 -> V_182 ,
V_41 -> V_183 , V_184 ) ;
F_62 ( V_41 -> V_180 ) ;
return 0 ;
}
static void F_63 ( void * V_191 )
{
struct V_1 * V_176 = V_191 ;
struct V_40 * V_41 = V_176 -> V_41 ;
struct V_205 * V_206 = & V_176 -> V_4 . V_134 -> V_206 ;
unsigned long V_28 ;
bool V_207 = false ;
struct V_7 * V_8 = V_176 -> V_4 . V_39 ;
F_51 ( V_41 -> V_208 -> V_181 -> V_20 , V_41 -> V_209 ,
V_210 , V_211 ) ;
F_47 ( & V_176 -> V_4 . V_93 , V_28 ) ;
V_41 -> V_42 = 0 ;
V_206 -> V_212 += V_41 -> V_213 ;
V_206 -> V_212 &= V_210 - 1 ;
V_176 -> V_4 . V_189 . V_214 += V_41 -> V_213 ;
if ( V_8 -> V_43 ) {
V_8 -> V_43 = 0 ;
F_11 ( V_176 ) ;
}
if ( F_64 ( V_206 ) < V_215 )
F_65 ( & V_176 -> V_4 ) ;
if ( ! F_66 ( V_206 ) && ! F_67 ( & V_176 -> V_4 ) ) {
int V_159 ;
V_159 = F_68 ( V_176 ) ;
if ( V_159 )
V_207 = true ;
} else if ( V_176 -> V_166 & V_167 ) {
V_207 = true ;
}
if ( V_207 ) {
V_41 -> V_216 = 1 ;
V_176 -> V_59 |= V_217 ;
F_69 ( & V_176 -> V_4 , V_58 , V_176 -> V_59 ) ;
}
F_48 ( & V_176 -> V_4 . V_93 , V_28 ) ;
}
static int F_68 ( struct V_1 * V_176 )
{
struct V_40 * V_41 = V_176 -> V_41 ;
struct V_7 * V_8 = V_176 -> V_4 . V_39 ;
struct V_205 * V_206 = & V_176 -> V_4 . V_134 -> V_206 ;
struct V_193 * V_194 ;
unsigned int V_218 = 0 ;
int V_159 ;
if ( V_41 -> V_42 )
return 0 ;
if ( F_67 ( & V_176 -> V_4 ) || F_66 ( V_206 ) ) {
if ( V_41 -> V_216 || V_176 -> V_166 & V_167 ) {
V_159 = - V_202 ;
goto V_165;
}
if ( V_176 -> V_59 & V_217 ) {
V_176 -> V_59 &= ~ V_217 ;
F_5 ( V_176 , V_58 , V_176 -> V_59 ) ;
}
return 0 ;
}
V_41 -> V_213 = F_70 ( V_206 -> V_219 , V_206 -> V_212 , V_210 ) ;
if ( V_8 -> V_66 & V_220 ) {
T_2 V_221 ;
V_221 = F_4 ( V_176 , V_222 ) ;
if ( V_221 == V_176 -> V_223 ) {
V_159 = - V_202 ;
goto V_165;
}
if ( V_41 -> V_213 < 4 ) {
V_159 = - V_224 ;
goto V_165;
}
V_218 = 1 ;
}
V_194 = F_59 ( V_41 -> V_208 ,
V_41 -> V_209 + V_206 -> V_212 + V_218 ,
V_41 -> V_213 - V_218 , V_225 ,
V_200 | V_201 ) ;
if ( ! V_194 ) {
V_159 = - V_202 ;
goto V_165;
}
V_41 -> V_42 = 1 ;
V_194 -> V_203 = F_63 ;
V_194 -> V_204 = V_176 ;
V_41 -> V_226 = F_60 ( V_194 ) ;
F_61 ( V_41 -> V_208 -> V_181 -> V_20 , V_41 -> V_209 ,
V_210 , V_211 ) ;
F_62 ( V_41 -> V_208 ) ;
if ( V_41 -> V_216 )
V_41 -> V_216 = 0 ;
if ( V_176 -> V_59 & V_217 ) {
V_176 -> V_59 &= ~ V_217 ;
F_5 ( V_176 , V_58 , V_176 -> V_59 ) ;
}
if ( V_218 )
F_5 ( V_176 , V_227 , V_206 -> V_228 [ V_206 -> V_212 ] ) ;
return 0 ;
V_165:
V_41 -> V_216 = 1 ;
return V_159 ;
}
static int F_71 ( struct V_21 * V_4 )
{
struct V_1 * V_2 = F_72 ( V_4 ) ;
unsigned char V_229 ;
unsigned long V_28 ;
T_2 V_192 ;
int V_230 = 0 ;
F_73 ( V_2 ) ;
V_192 = F_74 ( V_4 , V_231 ) ;
if ( V_192 & V_232 ) {
F_75 ( V_2 ) ;
return 0 ;
}
F_47 ( & V_4 -> V_93 , V_28 ) ;
V_229 = F_74 ( V_4 , V_18 ) ;
if ( V_229 & ( V_19 | V_102 ) ) {
V_230 = F_55 ( V_2 , V_192 ) ;
if ( V_230 ) {
V_229 = F_76 ( V_2 , V_229 ) ;
F_55 ( V_2 , 0 ) ;
}
}
F_77 ( V_2 ) ;
if ( V_229 & V_17 && V_2 -> V_41 -> V_216 ) {
if ( F_67 ( & V_2 -> V_4 ) ||
F_66 ( & V_2 -> V_4 . V_134 -> V_206 ) ) {
V_2 -> V_41 -> V_216 = 0 ;
F_78 ( V_2 ) ;
} else {
V_230 = F_68 ( V_2 ) ;
if ( V_230 )
F_78 ( V_2 ) ;
}
}
F_48 ( & V_4 -> V_93 , V_28 ) ;
F_75 ( V_2 ) ;
return 1 ;
}
static bool F_79 ( struct V_233 * V_234 , void * V_191 )
{
return false ;
}
static inline int F_55 ( struct V_1 * V_176 , unsigned int V_192 )
{
return - V_224 ;
}
static int F_80 ( struct V_235 * V_236 )
{
struct V_237 * V_238 = F_81 ( V_236 , V_239 , 0 ) ;
struct V_237 * V_157 = F_81 ( V_236 , V_240 , 0 ) ;
struct V_7 * V_8 ;
struct V_1 V_2 ;
int V_159 ;
void T_5 * V_5 ;
if ( ! V_238 || ! V_157 ) {
F_82 ( & V_236 -> V_20 , L_4 ) ;
return - V_224 ;
}
V_8 = F_83 ( & V_236 -> V_20 , sizeof( * V_8 ) , V_241 ) ;
if ( ! V_8 )
return - V_242 ;
V_5 = F_84 ( & V_236 -> V_20 , V_238 -> V_243 ,
F_85 ( V_238 ) ) ;
if ( ! V_5 )
return - V_244 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_4 . V_20 = & V_236 -> V_20 ;
V_2 . V_4 . V_245 = V_238 -> V_243 ;
V_2 . V_4 . V_5 = V_5 ;
V_2 . V_4 . V_157 = V_157 -> V_243 ;
V_2 . V_4 . type = V_246 ;
V_2 . V_4 . V_247 = V_248 ;
V_2 . V_4 . V_28 = V_249 | V_250 | V_124 |
V_121 ;
V_2 . V_4 . V_39 = V_8 ;
V_2 . V_4 . V_6 = 2 ;
V_2 . V_4 . V_251 = 64 ;
V_2 . V_223 = 64 ;
V_2 . V_166 = V_252 ;
#ifdef F_41
V_2 . V_166 |= V_167 ;
#endif
V_2 . V_4 . V_253 = F_16 ;
V_2 . V_4 . V_254 = F_30 ;
V_2 . V_4 . V_255 = F_37 ;
V_2 . V_4 . V_256 = F_43 ;
V_2 . V_4 . V_257 = F_46 ;
V_2 . V_4 . V_258 = F_49 ;
if ( V_236 -> V_20 . V_259 ) {
V_159 = F_86 ( V_236 -> V_20 . V_259 , L_5 ) ;
F_87 ( V_236 -> V_20 . V_259 , L_6 ,
& V_2 . V_4 . V_23 ) ;
V_8 -> V_163 = F_88 ( V_236 -> V_20 . V_259 , 1 ) ;
} else {
V_159 = V_236 -> V_260 ;
}
if ( V_159 < 0 ) {
F_82 ( & V_236 -> V_20 , L_7 ) ;
return V_159 ;
}
V_2 . V_4 . line = V_159 ;
if ( ! V_2 . V_4 . V_23 ) {
V_2 . V_4 . V_23 = V_261 ;
F_32 ( & V_236 -> V_20 ,
L_8 ,
V_261 ) ;
}
V_8 -> V_132 = V_262 ;
V_8 -> V_130 = V_262 ;
F_89 ( & V_8 -> V_156 , V_263 ,
V_8 -> V_132 ) ;
F_90 ( & V_8 -> V_133 , F_34 ) ;
F_91 ( & V_236 -> V_20 , true ) ;
F_92 ( & V_236 -> V_20 ) ;
F_93 ( & V_236 -> V_20 , - 1 ) ;
F_94 ( & V_236 -> V_20 ) ;
F_95 ( & V_236 -> V_20 ) ;
F_19 ( & V_236 -> V_20 ) ;
F_31 ( & V_2 , V_8 ) ;
#ifdef F_96
if ( V_236 -> V_20 . V_259 ) {
V_159 = F_97 ( V_236 -> V_20 . V_259 , L_9 ) ;
if ( V_159 == 2 ) {
V_2 . V_41 = & V_8 -> V_264 ;
V_2 . V_4 . V_160 = F_71 ;
V_8 -> V_264 . V_265 = F_79 ;
V_8 -> V_264 . V_266 = F_68 ;
V_8 -> V_264 . V_172 = F_55 ;
V_8 -> V_264 . V_183 = V_55 ;
V_8 -> V_264 . V_267 . V_268 = V_55 ;
V_8 -> V_264 . V_269 . V_270 = V_53 ;
if ( F_98 ( L_10 ) )
V_8 -> V_66 |= V_220 ;
}
}
#endif
V_159 = F_99 ( & V_2 ) ;
if ( V_159 < 0 ) {
F_82 ( & V_236 -> V_20 , L_11 ) ;
goto V_165;
}
V_8 -> line = V_159 ;
F_100 ( V_236 , V_8 ) ;
F_25 ( & V_236 -> V_20 ) ;
F_26 ( & V_236 -> V_20 ) ;
return 0 ;
V_165:
F_101 ( & V_236 -> V_20 ) ;
F_102 ( & V_236 -> V_20 ) ;
return V_159 ;
}
static int F_103 ( struct V_235 * V_236 )
{
struct V_7 * V_8 = F_104 ( V_236 ) ;
F_105 ( & V_236 -> V_20 ) ;
F_102 ( & V_236 -> V_20 ) ;
F_106 ( V_8 -> line ) ;
F_107 ( & V_8 -> V_156 ) ;
F_91 ( & V_236 -> V_20 , false ) ;
return 0 ;
}
static inline void F_108 ( struct V_7 * V_8 ,
bool V_271 )
{
if ( ! V_8 -> V_163 )
return;
if ( V_271 )
F_109 ( V_8 -> V_163 ) ;
else
F_110 ( V_8 -> V_163 ) ;
}
static void F_111 ( struct V_7 * V_8 ,
bool V_271 )
{
if ( V_271 == V_8 -> V_272 )
return;
F_108 ( V_8 , V_271 ) ;
V_8 -> V_272 = V_271 ;
}
static int F_112 ( struct V_181 * V_20 )
{
struct V_7 * V_8 = F_113 ( V_20 ) ;
if ( ! V_8 )
return 0 ;
V_8 -> V_273 = true ;
return 0 ;
}
static void F_114 ( struct V_181 * V_20 )
{
struct V_7 * V_8 = F_113 ( V_20 ) ;
if ( ! V_8 )
return;
V_8 -> V_273 = false ;
}
static int F_115 ( struct V_181 * V_20 )
{
struct V_7 * V_8 = F_113 ( V_20 ) ;
F_116 ( V_8 -> line ) ;
F_44 ( & V_8 -> V_133 ) ;
if ( F_117 ( V_20 ) )
F_111 ( V_8 , true ) ;
else
F_111 ( V_8 , false ) ;
return 0 ;
}
static int F_118 ( struct V_181 * V_20 )
{
struct V_7 * V_8 = F_113 ( V_20 ) ;
if ( F_117 ( V_20 ) )
F_111 ( V_8 , false ) ;
F_119 ( V_8 -> line ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 )
{
T_1 V_274 ;
V_274 = F_4 ( V_2 , V_11 ) ;
if ( V_274 == V_275 )
return 1 ;
return 0 ;
}
static int F_121 ( struct V_181 * V_20 )
{
struct V_7 * V_8 = F_113 ( V_20 ) ;
struct V_1 * V_2 ;
V_2 = F_122 ( V_8 -> line ) ;
if ( V_8 -> V_273 && ! V_276 ) {
if ( F_123 ( & V_2 -> V_4 ) )
return - V_202 ;
}
F_111 ( V_8 , true ) ;
if ( V_2 -> V_41 )
F_55 ( V_2 , V_173 ) ;
V_8 -> V_132 = V_262 ;
F_27 ( & V_8 -> V_133 ) ;
return 0 ;
}
static int F_124 ( struct V_181 * V_20 )
{
struct V_7 * V_8 = F_113 ( V_20 ) ;
struct V_1 * V_2 ;
int V_277 ;
if ( ! V_8 )
return 0 ;
V_2 = F_122 ( V_8 -> line ) ;
F_111 ( V_8 , false ) ;
V_277 = F_120 ( V_2 ) ;
if ( V_277 )
F_11 ( V_2 ) ;
if ( V_2 -> V_41 )
F_55 ( V_2 , 0 ) ;
V_8 -> V_132 = V_8 -> V_130 ;
F_27 ( & V_8 -> V_133 ) ;
return 0 ;
}
