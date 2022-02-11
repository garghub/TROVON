static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + ( V_3 << V_2 -> V_4 . V_6 ) ) ;
}
static void F_3 ( struct V_7 * V_4 , unsigned int V_8 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_2 -> V_4 . V_11 ;
T_2 V_12 ;
F_5 ( V_4 , V_8 ) ;
V_12 = F_6 ( V_2 , V_13 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
if ( ( V_8 & V_15 ) && ( V_4 -> V_16 & V_17 ) )
V_10 -> V_18 |= V_19 ;
else
V_10 -> V_18 &= ~ V_19 ;
F_7 ( V_2 , V_20 , V_10 -> V_18 ) ;
F_7 ( V_2 , V_13 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_2 V_21 = 255 ;
T_2 V_22 ;
V_22 = F_6 ( V_2 , V_23 ) ;
if ( V_22 == V_10 -> V_24 )
return;
F_7 ( V_2 , V_23 , V_10 -> V_24 ) ;
F_9 ( 2 ) ;
F_7 ( V_2 , V_25 , V_2 -> V_26 | V_27 |
V_28 ) ;
while ( V_29 != ( F_6 ( V_2 , V_30 ) &
( V_29 | V_31 ) ) ) {
V_21 -- ;
if ( ! V_21 ) {
F_10 ( V_2 -> V_4 . V_32 , L_1 ,
F_6 ( V_2 , V_30 ) ) ;
break;
}
F_9 ( 1 ) ;
}
}
static void F_11 ( struct V_7 * V_4 , unsigned int V_33 ,
struct V_9 * V_10 )
{
unsigned int V_34 = V_4 -> V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_37 , V_38 ;
if ( V_33 == 38400 && ( V_4 -> V_39 & V_40 ) == V_41 ) {
V_10 -> V_42 = V_4 -> V_43 & 0xffff ;
if ( V_4 -> V_43 & ( 1 << 16 ) )
V_10 -> V_24 = V_44 ;
else
V_10 -> V_24 = V_45 ;
return;
}
V_35 = F_12 ( V_34 , 13 * V_33 ) ;
V_36 = F_12 ( V_34 , 16 * V_33 ) ;
if ( ! V_35 )
V_35 = 1 ;
if ( ! V_36 )
V_36 = 1 ;
V_37 = abs ( V_33 - V_34 / 13 / V_35 ) ;
V_38 = abs ( V_33 - V_34 / 16 / V_36 ) ;
if ( V_37 >= V_38 ) {
V_10 -> V_24 = V_45 ;
V_10 -> V_42 = V_36 ;
} else {
V_10 -> V_24 = V_44 ;
V_10 -> V_42 = V_35 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_2 V_46 ;
V_46 = F_6 ( V_2 , V_47 ) ;
if ( V_46 == V_10 -> V_48 )
return;
if ( V_10 -> V_48 & V_49 )
F_7 ( V_2 , V_47 ,
V_10 -> V_48 & ~ V_49 ) ;
F_7 ( V_2 , V_47 , V_10 -> V_48 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_50 & V_51 )
F_8 ( V_2 , V_10 ) ;
else
F_7 ( V_2 , V_23 , V_10 -> V_24 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_4 . V_11 ;
struct V_52 * V_53 = V_2 -> V_53 ;
if ( V_53 && V_53 -> V_54 ) {
V_10 -> V_55 = 1 ;
return;
}
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_20 , V_56 ) ;
F_7 ( V_2 , V_13 , V_57 ) ;
F_7 ( V_2 , V_58 , V_59 ) ;
F_7 ( V_2 , V_25 , V_2 -> V_26 ) ;
F_13 ( V_2 , V_10 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_60 , F_16 ( 16 ) |
F_17 ( 52 ) ) ;
F_7 ( V_2 , V_61 ,
F_18 ( V_62 ) << V_63 |
F_18 ( V_64 ) << V_65 ) ;
F_7 ( V_2 , V_13 , 0 ) ;
F_7 ( V_2 , V_58 , V_2 -> V_66 ) ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_19 ( V_2 , V_10 -> V_42 ) ;
F_7 ( V_2 , V_20 , V_10 -> V_18 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_69 , V_10 -> V_70 ) ;
F_7 ( V_2 , V_71 , V_10 -> V_72 ) ;
F_7 ( V_2 , V_13 , V_2 -> V_12 ) ;
F_14 ( V_2 , V_10 ) ;
V_2 -> V_4 . V_73 -> V_74 ( & V_2 -> V_4 , V_2 -> V_4 . V_8 ) ;
}
static void F_20 ( struct V_7 * V_4 ,
struct V_75 * V_76 ,
struct V_75 * V_77 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_2 -> V_4 . V_11 ;
unsigned char V_78 = 0 ;
unsigned int V_33 ;
switch ( V_76 -> V_79 & V_80 ) {
case V_81 :
V_78 = V_82 ;
break;
case V_83 :
V_78 = V_84 ;
break;
case V_85 :
V_78 = V_86 ;
break;
default:
case V_87 :
V_78 = V_88 ;
break;
}
if ( V_76 -> V_79 & V_89 )
V_78 |= V_90 ;
if ( V_76 -> V_79 & V_91 )
V_78 |= V_92 ;
if ( ! ( V_76 -> V_79 & V_93 ) )
V_78 |= V_94 ;
if ( V_76 -> V_79 & V_95 )
V_78 |= V_96 ;
V_33 = F_21 ( V_4 , V_76 , V_77 ,
V_4 -> V_34 / 16 / 0xffff ,
V_4 -> V_34 / 13 ) ;
F_11 ( V_4 , V_33 , V_10 ) ;
F_22 ( V_4 -> V_32 ) ;
F_23 ( & V_4 -> V_97 ) ;
F_24 ( V_4 , V_76 -> V_79 , V_33 ) ;
V_2 -> V_4 . V_98 = V_99 | V_29 | V_31 ;
if ( V_76 -> V_100 & V_101 )
V_2 -> V_4 . V_98 |= V_102 | V_103 ;
if ( V_76 -> V_100 & ( V_104 | V_105 ) )
V_2 -> V_4 . V_98 |= V_106 ;
V_2 -> V_4 . V_107 = 0 ;
if ( V_76 -> V_100 & V_108 )
V_2 -> V_4 . V_107 |= V_103 | V_102 ;
if ( V_76 -> V_100 & V_104 ) {
V_2 -> V_4 . V_107 |= V_106 ;
if ( V_76 -> V_100 & V_108 )
V_2 -> V_4 . V_107 |= V_99 ;
}
if ( ( V_76 -> V_79 & V_109 ) == 0 )
V_2 -> V_4 . V_107 |= V_31 ;
V_2 -> V_68 &= ~ V_110 ;
if ( F_25 ( & V_2 -> V_4 , V_76 -> V_79 ) )
V_2 -> V_68 |= V_110 ;
V_2 -> V_12 = V_78 ;
V_2 -> V_26 = V_111 ;
V_2 -> V_26 |= F_26 ( V_62 ) << V_112 ;
V_2 -> V_26 |= F_26 ( V_64 ) << V_113 ;
V_10 -> V_48 = V_114 | V_115 |
V_116 ;
if ( V_2 -> V_53 )
V_10 -> V_48 |= V_117 |
V_118 ;
V_10 -> V_70 = V_76 -> V_119 [ V_120 ] ;
V_10 -> V_72 = V_76 -> V_119 [ V_121 ] ;
V_10 -> V_18 = 0 ;
V_2 -> V_4 . V_16 &= ~ ( V_122 | V_17 | V_123 ) ;
if ( V_76 -> V_79 & V_124 && V_2 -> V_4 . V_39 & V_125 ) {
V_2 -> V_4 . V_16 |= V_122 | V_17 ;
V_10 -> V_18 |= V_126 ;
} else if ( V_2 -> V_4 . V_39 & V_127 ) {
if ( V_76 -> V_100 & V_128 ) {
V_2 -> V_4 . V_16 |= V_123 ;
V_10 -> V_18 |= V_129 ;
}
}
F_15 ( V_2 ) ;
F_27 ( & V_2 -> V_4 . V_97 ) ;
F_28 ( V_4 -> V_32 ) ;
F_29 ( V_4 -> V_32 ) ;
V_10 -> V_130 = V_131 * 64 * 8 / V_33 ;
V_10 -> V_132 = V_10 -> V_130 ;
F_30 ( & V_10 -> V_133 ) ;
if ( F_31 ( V_76 ) )
F_32 ( V_76 , V_33 , V_33 ) ;
}
static void F_33 ( struct V_7 * V_4 , unsigned int V_134 ,
unsigned int V_135 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
T_2 V_18 ;
F_22 ( V_4 -> V_32 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
V_18 = F_6 ( V_2 , V_20 ) ;
F_7 ( V_2 , V_20 , V_18 | V_56 ) ;
F_7 ( V_2 , V_13 , 0 ) ;
F_7 ( V_2 , V_67 , ( V_134 != 0 ) ? V_136 : 0 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_20 , V_18 ) ;
F_7 ( V_2 , V_13 , 0 ) ;
F_28 ( V_4 -> V_32 ) ;
F_29 ( V_4 -> V_32 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
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
F_35 ( V_2 -> V_4 . V_32 ,
L_2 ) ;
V_140 = 0xff ;
V_141 = 0xff ;
}
V_139 = F_36 ( V_140 , V_141 ) ;
switch ( V_139 ) {
case V_150 :
V_10 -> V_50 |= V_51 ;
break;
case V_151 :
V_10 -> V_50 |= V_51 |
V_152 ;
break;
case V_153 :
V_10 -> V_50 |= V_51 |
V_152 ;
break;
default:
break;
}
}
static void F_37 ( struct V_154 * V_155 )
{
struct V_9 * V_10 ;
V_10 = F_38 ( V_155 , struct V_9 , V_133 ) ;
F_39 ( & V_10 -> V_156 , V_10 -> V_132 ) ;
}
static T_4 F_40 ( int V_157 , void * V_158 )
{
struct V_7 * V_4 = V_158 ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned int V_159 ;
int V_160 ;
#ifdef F_41
if ( V_2 -> V_53 ) {
V_160 = F_42 ( V_4 ) ;
return F_43 ( V_160 ) ;
}
#endif
F_44 ( V_2 ) ;
V_159 = F_45 ( V_4 , V_161 ) ;
V_160 = F_46 ( V_4 , V_159 ) ;
F_47 ( V_2 ) ;
return F_43 ( V_160 ) ;
}
static int F_48 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_4 -> V_11 ;
int V_160 ;
if ( V_10 -> V_162 ) {
V_160 = F_49 ( V_4 -> V_32 , V_10 -> V_162 ) ;
if ( V_160 )
return V_160 ;
}
F_22 ( V_4 -> V_32 ) ;
V_2 -> V_66 = 0 ;
F_7 ( V_2 , V_25 , V_28 | V_27 ) ;
F_7 ( V_2 , V_13 , V_88 ) ;
V_2 -> V_163 = 0 ;
V_2 -> V_164 = 0 ;
if ( V_2 -> V_53 ) {
V_160 = F_50 ( V_2 ) ;
if ( V_160 ) {
F_51 ( V_4 -> V_32 ,
L_3 ) ;
V_2 -> V_53 = NULL ;
}
}
V_160 = F_52 ( V_4 -> V_157 , F_40 , V_165 ,
F_53 ( V_4 -> V_32 ) , V_4 ) ;
if ( V_160 < 0 )
goto V_166;
V_2 -> V_68 = V_167 | V_168 ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
#ifdef F_54
V_2 -> V_169 |= V_170 ;
#endif
V_10 -> V_171 = V_172 ;
if ( V_10 -> V_50 & V_152 )
V_10 -> V_171 |= V_173 ;
F_7 ( V_2 , V_174 , V_10 -> V_171 ) ;
if ( V_2 -> V_53 )
V_2 -> V_53 -> V_175 ( V_2 , 0 ) ;
F_28 ( V_4 -> V_32 ) ;
F_29 ( V_4 -> V_32 ) ;
return 0 ;
V_166:
F_28 ( V_4 -> V_32 ) ;
F_29 ( V_4 -> V_32 ) ;
F_55 ( V_4 -> V_32 ) ;
return V_160 ;
}
static void F_56 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_4 -> V_11 ;
F_57 ( & V_10 -> V_133 ) ;
if ( V_2 -> V_53 )
V_2 -> V_53 -> V_175 ( V_2 , V_176 ) ;
F_22 ( V_4 -> V_32 ) ;
F_7 ( V_2 , V_174 , 0 ) ;
V_2 -> V_68 = 0 ;
F_7 ( V_2 , V_67 , 0 ) ;
if ( V_2 -> V_53 )
F_58 ( V_2 ) ;
if ( V_2 -> V_12 & V_177 )
F_7 ( V_2 , V_13 , V_2 -> V_12 & ~ V_177 ) ;
F_7 ( V_2 , V_25 , V_28 | V_27 ) ;
F_28 ( V_4 -> V_32 ) ;
F_29 ( V_4 -> V_32 ) ;
F_59 ( V_4 -> V_157 , V_4 ) ;
F_55 ( V_4 -> V_32 ) ;
}
static void F_60 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned long V_39 ;
F_22 ( V_4 -> V_32 ) ;
F_61 ( & V_4 -> V_97 , V_39 ) ;
V_2 -> V_68 &= ~ ( V_167 | V_168 ) ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
F_62 ( & V_4 -> V_97 , V_39 ) ;
F_28 ( V_4 -> V_32 ) ;
F_29 ( V_4 -> V_32 ) ;
}
static int F_63 ( struct V_7 * V_4 ,
struct V_178 * V_179 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
V_179 -> V_180 = F_64 ( V_179 -> V_180 , 100U ) ;
V_179 -> V_181 = F_64 ( V_179 -> V_181 , 100U ) ;
V_4 -> V_179 = * V_179 ;
if ( V_179 -> V_39 & V_182 ) {
int V_160 = F_65 ( V_2 ) ;
if ( V_160 ) {
V_179 -> V_39 &= ~ V_182 ;
V_4 -> V_179 . V_39 &= ~ V_182 ;
}
return V_160 ;
}
F_66 ( V_2 ) ;
return 0 ;
}
static void F_67 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned long V_39 ;
F_22 ( V_4 -> V_32 ) ;
F_61 ( & V_4 -> V_97 , V_39 ) ;
V_2 -> V_68 |= V_167 | V_168 ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
F_62 ( & V_4 -> V_97 , V_39 ) ;
F_28 ( V_4 -> V_32 ) ;
F_29 ( V_4 -> V_32 ) ;
}
static void F_68 ( struct V_1 * V_183 , bool error )
{
struct V_9 * V_10 = V_183 -> V_4 . V_11 ;
struct V_52 * V_53 = V_183 -> V_53 ;
struct V_184 * V_184 = & V_183 -> V_4 . V_134 -> V_4 ;
struct V_185 V_134 ;
int V_186 ;
unsigned long V_39 ;
int V_160 ;
F_69 ( V_53 -> V_187 -> V_188 -> V_32 , V_53 -> V_189 ,
V_53 -> V_190 , V_191 ) ;
F_61 ( & V_10 -> V_192 , V_39 ) ;
if ( ! V_53 -> V_193 )
goto V_194;
V_53 -> V_193 = 0 ;
F_70 ( V_53 -> V_187 , V_53 -> V_195 , & V_134 ) ;
F_71 ( V_53 -> V_187 ) ;
V_186 = V_53 -> V_190 - V_134 . V_196 ;
V_160 = F_72 ( V_184 , V_53 -> V_197 , V_186 ) ;
V_183 -> V_4 . V_198 . V_199 += V_160 ;
V_183 -> V_4 . V_198 . V_200 += V_186 - V_160 ;
V_194:
F_62 ( & V_10 -> V_192 , V_39 ) ;
if ( ! error )
F_73 ( V_183 , 0 ) ;
F_74 ( V_184 ) ;
}
static void F_75 ( void * V_201 )
{
F_68 ( V_201 , false ) ;
}
static void F_76 ( struct V_1 * V_183 )
{
struct V_9 * V_10 = V_183 -> V_4 . V_11 ;
struct V_52 * V_53 = V_183 -> V_53 ;
unsigned long V_39 ;
int V_160 ;
F_61 ( & V_10 -> V_192 , V_39 ) ;
if ( ! V_53 -> V_193 ) {
F_62 ( & V_10 -> V_192 , V_39 ) ;
return;
}
V_160 = F_77 ( V_53 -> V_187 ) ;
if ( F_78 ( V_160 ) )
V_10 -> V_202 = true ;
F_62 ( & V_10 -> V_192 , V_39 ) ;
F_68 ( V_183 , true ) ;
}
static int F_73 ( struct V_1 * V_183 , unsigned int V_159 )
{
struct V_9 * V_10 = V_183 -> V_4 . V_11 ;
struct V_52 * V_53 = V_183 -> V_53 ;
int V_166 = 0 ;
struct V_203 * V_204 ;
unsigned long V_39 ;
switch ( V_159 & 0x3f ) {
case V_205 :
F_76 ( V_183 ) ;
return - V_206 ;
case V_176 :
F_76 ( V_183 ) ;
return - V_207 ;
case V_208 :
F_76 ( V_183 ) ;
return - V_207 ;
default:
break;
}
if ( V_10 -> V_202 )
return - V_209 ;
F_61 ( & V_10 -> V_192 , V_39 ) ;
if ( V_53 -> V_193 )
goto V_210;
V_204 = F_79 ( V_53 -> V_187 , V_53 -> V_189 ,
V_53 -> V_190 , V_211 ,
V_212 | V_213 ) ;
if ( ! V_204 ) {
V_166 = - V_214 ;
goto V_210;
}
V_53 -> V_193 = 1 ;
V_204 -> V_215 = F_75 ;
V_204 -> V_216 = V_183 ;
V_53 -> V_195 = F_80 ( V_204 ) ;
F_81 ( V_53 -> V_187 -> V_188 -> V_32 , V_53 -> V_189 ,
V_53 -> V_190 , V_191 ) ;
F_82 ( V_53 -> V_187 ) ;
V_210:
F_62 ( & V_10 -> V_192 , V_39 ) ;
return V_166 ;
}
static void F_83 ( void * V_201 )
{
struct V_1 * V_183 = V_201 ;
struct V_52 * V_53 = V_183 -> V_53 ;
struct V_217 * V_218 = & V_183 -> V_4 . V_134 -> V_218 ;
unsigned long V_39 ;
bool V_219 = false ;
struct V_9 * V_10 = V_183 -> V_4 . V_11 ;
F_69 ( V_53 -> V_220 -> V_188 -> V_32 , V_53 -> V_221 ,
V_222 , V_223 ) ;
F_61 ( & V_183 -> V_4 . V_97 , V_39 ) ;
V_53 -> V_54 = 0 ;
V_218 -> V_224 += V_53 -> V_225 ;
V_218 -> V_224 &= V_222 - 1 ;
V_183 -> V_4 . V_198 . V_226 += V_53 -> V_225 ;
if ( V_10 -> V_55 ) {
V_10 -> V_55 = 0 ;
F_15 ( V_183 ) ;
}
if ( F_84 ( V_218 ) < V_227 )
F_85 ( & V_183 -> V_4 ) ;
if ( ! F_86 ( V_218 ) && ! F_87 ( & V_183 -> V_4 ) ) {
int V_160 ;
V_160 = F_88 ( V_183 ) ;
if ( V_160 )
V_219 = true ;
} else if ( V_183 -> V_169 & V_170 ) {
V_219 = true ;
}
if ( V_219 ) {
V_53 -> V_228 = 1 ;
V_183 -> V_68 |= V_229 ;
F_89 ( & V_183 -> V_4 , V_67 , V_183 -> V_68 ) ;
}
F_62 ( & V_183 -> V_4 . V_97 , V_39 ) ;
}
static int F_88 ( struct V_1 * V_183 )
{
struct V_52 * V_53 = V_183 -> V_53 ;
struct V_9 * V_10 = V_183 -> V_4 . V_11 ;
struct V_217 * V_218 = & V_183 -> V_4 . V_134 -> V_218 ;
struct V_203 * V_204 ;
unsigned int V_230 = 0 ;
int V_160 ;
if ( V_53 -> V_54 )
return 0 ;
if ( F_87 ( & V_183 -> V_4 ) || F_86 ( V_218 ) ) {
if ( V_53 -> V_228 || V_183 -> V_169 & V_170 ) {
V_160 = - V_214 ;
goto V_166;
}
if ( V_183 -> V_68 & V_229 ) {
V_183 -> V_68 &= ~ V_229 ;
F_7 ( V_183 , V_67 , V_183 -> V_68 ) ;
}
return 0 ;
}
V_53 -> V_225 = F_90 ( V_218 -> V_231 , V_218 -> V_224 , V_222 ) ;
if ( V_10 -> V_50 & V_232 ) {
T_2 V_233 ;
V_233 = F_6 ( V_183 , V_234 ) ;
if ( V_233 == V_183 -> V_235 ) {
V_160 = - V_214 ;
goto V_166;
}
if ( V_53 -> V_225 < 4 ) {
V_160 = - V_209 ;
goto V_166;
}
V_230 = 1 ;
}
V_204 = F_79 ( V_53 -> V_220 ,
V_53 -> V_221 + V_218 -> V_224 + V_230 ,
V_53 -> V_225 - V_230 , V_236 ,
V_212 | V_213 ) ;
if ( ! V_204 ) {
V_160 = - V_214 ;
goto V_166;
}
V_53 -> V_54 = 1 ;
V_204 -> V_215 = F_83 ;
V_204 -> V_216 = V_183 ;
V_53 -> V_237 = F_80 ( V_204 ) ;
F_81 ( V_53 -> V_220 -> V_188 -> V_32 , V_53 -> V_221 ,
V_222 , V_223 ) ;
F_82 ( V_53 -> V_220 ) ;
if ( V_53 -> V_228 )
V_53 -> V_228 = 0 ;
if ( V_183 -> V_68 & V_229 ) {
V_183 -> V_68 &= ~ V_229 ;
F_7 ( V_183 , V_67 , V_183 -> V_68 ) ;
}
if ( V_230 )
F_7 ( V_183 , V_238 , V_218 -> V_239 [ V_218 -> V_224 ] ) ;
return 0 ;
V_166:
V_53 -> V_228 = 1 ;
return V_160 ;
}
static int F_42 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned char V_16 ;
unsigned long V_39 ;
T_2 V_159 ;
int V_240 = 0 ;
F_44 ( V_2 ) ;
V_159 = F_45 ( V_4 , V_161 ) ;
if ( V_159 & V_241 ) {
F_47 ( V_2 ) ;
return 0 ;
}
F_61 ( & V_4 -> V_97 , V_39 ) ;
V_16 = F_45 ( V_4 , V_30 ) ;
if ( V_16 & ( V_31 | V_106 ) ) {
V_240 = F_73 ( V_2 , V_159 ) ;
if ( V_240 ) {
V_16 = F_91 ( V_2 , V_16 ) ;
F_73 ( V_2 , 0 ) ;
}
}
F_92 ( V_2 ) ;
if ( V_16 & V_29 && V_2 -> V_53 -> V_228 ) {
if ( F_87 ( & V_2 -> V_4 ) ||
F_86 ( & V_2 -> V_4 . V_134 -> V_218 ) ) {
V_2 -> V_53 -> V_228 = 0 ;
F_93 ( V_2 ) ;
} else {
V_240 = F_88 ( V_2 ) ;
if ( V_240 )
F_93 ( V_2 ) ;
}
}
F_62 ( & V_4 -> V_97 , V_39 ) ;
F_47 ( V_2 ) ;
return 1 ;
}
static bool F_94 ( struct V_242 * V_243 , void * V_201 )
{
return false ;
}
static inline int F_73 ( struct V_1 * V_183 , unsigned int V_159 )
{
return - V_209 ;
}
static int F_95 ( struct V_7 * V_4 )
{
F_96 ( 1 , L_4 ) ;
return 0 ;
}
static int F_97 ( struct V_244 * V_245 )
{
struct V_246 * V_247 = F_98 ( V_245 , V_248 , 0 ) ;
struct V_246 * V_157 = F_98 ( V_245 , V_249 , 0 ) ;
struct V_9 * V_10 ;
struct V_1 V_2 ;
int V_160 ;
void T_5 * V_5 ;
if ( ! V_247 || ! V_157 ) {
F_99 ( & V_245 -> V_32 , L_5 ) ;
return - V_209 ;
}
V_10 = F_100 ( & V_245 -> V_32 , sizeof( * V_10 ) , V_250 ) ;
if ( ! V_10 )
return - V_251 ;
V_5 = F_101 ( & V_245 -> V_32 , V_247 -> V_252 ,
F_102 ( V_247 ) ) ;
if ( ! V_5 )
return - V_253 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_4 . V_32 = & V_245 -> V_32 ;
V_2 . V_4 . V_254 = V_247 -> V_252 ;
V_2 . V_4 . V_5 = V_5 ;
V_2 . V_4 . V_157 = V_157 -> V_252 ;
V_2 . V_4 . type = V_255 ;
V_2 . V_4 . V_256 = V_257 ;
V_2 . V_4 . V_39 = V_258 | V_259 | V_127 |
V_125 ;
V_2 . V_4 . V_11 = V_10 ;
V_2 . V_4 . V_6 = 2 ;
V_2 . V_4 . V_260 = 64 ;
V_2 . V_235 = 64 ;
V_2 . V_169 = V_261 ;
#ifdef F_54
V_2 . V_169 |= V_170 ;
#endif
V_2 . V_4 . V_262 = F_20 ;
V_2 . V_4 . V_74 = F_3 ;
V_2 . V_4 . V_263 = F_33 ;
V_2 . V_4 . V_264 = F_48 ;
V_2 . V_4 . V_265 = F_56 ;
V_2 . V_4 . V_266 = F_60 ;
V_2 . V_4 . V_267 = F_67 ;
V_2 . V_4 . V_268 = F_63 ;
if ( V_245 -> V_32 . V_269 ) {
const struct V_270 * V_271 ;
V_160 = F_103 ( V_245 -> V_32 . V_269 , L_6 ) ;
F_104 ( V_245 -> V_32 . V_269 , L_7 ,
& V_2 . V_4 . V_34 ) ;
V_10 -> V_162 = F_105 ( V_245 -> V_32 . V_269 , 1 ) ;
V_271 = F_106 ( F_107 ( V_272 ) , & V_245 -> V_32 ) ;
if ( V_271 && V_271 -> V_273 )
V_10 -> V_50 |= * ( T_2 * ) V_271 -> V_273 ;
} else {
V_160 = V_245 -> V_271 ;
}
if ( V_160 < 0 ) {
F_99 ( & V_245 -> V_32 , L_8 ) ;
return V_160 ;
}
V_2 . V_4 . line = V_160 ;
if ( ! V_2 . V_4 . V_34 ) {
V_2 . V_4 . V_34 = V_274 ;
F_35 ( & V_245 -> V_32 ,
L_9 ,
V_274 ) ;
}
V_10 -> V_132 = V_275 ;
V_10 -> V_130 = V_275 ;
F_108 ( & V_10 -> V_156 , V_276 ,
V_10 -> V_132 ) ;
F_109 ( & V_10 -> V_133 , F_37 ) ;
F_110 ( & V_10 -> V_192 ) ;
F_111 ( & V_245 -> V_32 , true ) ;
F_112 ( & V_245 -> V_32 ) ;
F_113 ( & V_245 -> V_32 , - 1 ) ;
F_114 ( & V_245 -> V_32 ) ;
F_115 ( & V_245 -> V_32 ) ;
F_22 ( & V_245 -> V_32 ) ;
F_34 ( & V_2 , V_10 ) ;
V_2 . V_4 . V_277 = F_95 ;
#ifdef F_41
if ( V_245 -> V_32 . V_269 ) {
V_160 = F_116 ( V_245 -> V_32 . V_269 , L_10 ) ;
if ( V_160 == 2 ) {
V_2 . V_53 = & V_10 -> V_278 ;
V_10 -> V_278 . V_279 = F_94 ;
V_10 -> V_278 . V_280 = F_88 ;
V_10 -> V_278 . V_175 = F_73 ;
V_10 -> V_278 . V_190 = V_64 ;
V_10 -> V_278 . V_281 . V_282 = V_64 ;
V_10 -> V_278 . V_283 . V_284 = V_62 ;
if ( F_117 ( L_11 ) )
V_10 -> V_50 |= V_232 ;
V_10 -> V_202 = true ;
}
}
#endif
V_160 = F_118 ( & V_2 ) ;
if ( V_160 < 0 ) {
F_99 ( & V_245 -> V_32 , L_12 ) ;
goto V_166;
}
V_10 -> line = V_160 ;
F_119 ( V_245 , V_10 ) ;
F_28 ( & V_245 -> V_32 ) ;
F_29 ( & V_245 -> V_32 ) ;
return 0 ;
V_166:
F_120 ( & V_245 -> V_32 ) ;
F_121 ( & V_245 -> V_32 ) ;
return V_160 ;
}
static int F_122 ( struct V_244 * V_245 )
{
struct V_9 * V_10 = F_123 ( V_245 ) ;
F_124 ( & V_245 -> V_32 ) ;
F_121 ( & V_245 -> V_32 ) ;
F_125 ( V_10 -> line ) ;
F_126 ( & V_10 -> V_156 ) ;
F_111 ( & V_245 -> V_32 , false ) ;
return 0 ;
}
static int F_127 ( struct V_188 * V_32 )
{
struct V_9 * V_10 = F_128 ( V_32 ) ;
if ( ! V_10 )
return 0 ;
V_10 -> V_285 = true ;
return 0 ;
}
static void F_129 ( struct V_188 * V_32 )
{
struct V_9 * V_10 = F_128 ( V_32 ) ;
if ( ! V_10 )
return;
V_10 -> V_285 = false ;
}
static int F_130 ( struct V_188 * V_32 )
{
struct V_9 * V_10 = F_128 ( V_32 ) ;
F_131 ( V_10 -> line ) ;
F_57 ( & V_10 -> V_133 ) ;
return 0 ;
}
static int F_132 ( struct V_188 * V_32 )
{
struct V_9 * V_10 = F_128 ( V_32 ) ;
F_133 ( V_10 -> line ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
T_1 V_286 ;
V_286 = F_6 ( V_2 , V_47 ) ;
if ( ! V_286 )
return 1 ;
return 0 ;
}
static int F_135 ( struct V_188 * V_32 )
{
struct V_9 * V_10 = F_128 ( V_32 ) ;
struct V_1 * V_2 = F_136 ( V_10 -> line ) ;
int V_21 = 100 ;
int V_287 ;
int V_288 ;
V_287 = F_6 ( V_2 , V_289 ) ;
V_287 |= V_290 ;
F_7 ( V_2 , V_289 , V_287 ) ;
do {
F_9 ( 1 ) ;
V_288 = F_6 ( V_2 , V_291 ) ;
} while ( -- V_21 && ! ( V_288 & V_292 ) );
if ( ! V_21 ) {
F_99 ( V_32 , L_13 ) ;
return - V_207 ;
}
return 0 ;
}
static int F_137 ( struct V_188 * V_32 )
{
struct V_9 * V_10 = F_128 ( V_32 ) ;
struct V_1 * V_2 ;
V_2 = F_136 ( V_10 -> line ) ;
if ( V_10 -> V_285 && ! V_293 ) {
if ( F_138 ( & V_2 -> V_4 ) )
return - V_214 ;
}
if ( V_10 -> V_50 & V_294 ) {
int V_160 ;
V_160 = F_135 ( V_32 ) ;
if ( V_160 )
return V_160 ;
F_14 ( V_2 , V_10 ) ;
}
if ( V_2 -> V_53 && V_2 -> V_53 -> V_187 )
F_73 ( V_2 , V_176 ) ;
V_10 -> V_132 = V_275 ;
F_30 ( & V_10 -> V_133 ) ;
return 0 ;
}
static int F_139 ( struct V_188 * V_32 )
{
struct V_9 * V_10 = F_128 ( V_32 ) ;
struct V_1 * V_2 ;
int V_295 ;
if ( ! V_10 )
return 0 ;
V_2 = F_136 ( V_10 -> line ) ;
V_295 = F_134 ( V_2 ) ;
if ( V_295 )
F_15 ( V_2 ) ;
if ( V_2 -> V_53 && V_2 -> V_53 -> V_187 )
F_73 ( V_2 , 0 ) ;
V_10 -> V_132 = V_10 -> V_130 ;
F_30 ( & V_10 -> V_133 ) ;
return 0 ;
}
static int T_6 F_140 ( void )
{
char * V_296 ;
char * V_297 ;
T_2 V_298 ;
if ( strstr ( V_299 , L_14 ) )
return 0 ;
V_296 = strstr ( V_299 , L_15 ) ;
if ( ! V_296 )
return 0 ;
V_296 += 12 ;
if ( '0' <= * V_296 && * V_296 <= '9' )
V_298 = * V_296 - '0' ;
else
return 0 ;
V_296 ++ ;
if ( V_296 [ 0 ] == ',' ) {
V_296 ++ ;
V_297 = V_296 ;
} else {
V_297 = NULL ;
}
F_141 ( L_16 , V_298 , V_297 ) ;
F_142 ( L_17 ,
V_298 , V_298 ) ;
F_142 ( L_18 ) ;
F_142 ( L_19 ) ;
return 0 ;
}
