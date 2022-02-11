static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_7 = F_2 ( V_6 -> V_8 + V_9 ) ;
F_3 ( V_7 , V_6 -> V_8 + V_9 ) ;
#ifdef F_4
if ( F_5 ( V_6 -> V_10 && V_1 != - 1 ) ) {
F_6 ( V_11 L_1 ) ;
V_6 -> V_10 = false ;
}
if ( V_7 & 1 )
F_7 ( & V_6 -> V_12 ) ;
#endif
return V_13 ;
}
static int F_8 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_15 . V_18 ;
struct V_3 * V_4 = F_9 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( 0 , V_6 -> V_19 + V_20 ) ;
F_3 ( 0 , V_6 -> V_8 + V_21 ) ;
V_17 -> V_22 ( V_15 , 0 ) ;
F_3 ( 0x0010 , V_6 -> V_8 + V_23 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
const struct V_24 * V_25 = F_11 ( V_15 ) ;
struct V_3 * V_4 = F_9 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
const struct V_26 * V_27 = & V_25 -> V_28 [ 0 ] ;
const struct V_26 * V_29 = & V_25 -> V_28 [ 2 ] ;
unsigned long V_30 ;
if ( V_27 == NULL || V_29 == NULL )
return - V_31 ;
V_30 = V_27 -> V_32 ;
F_3 ( 0x003a , V_6 -> V_19 + V_20 ) ;
F_3 ( 0x003a , V_6 -> V_19 + V_33 ) ;
F_3 ( 0x3f00 , V_6 -> V_19 + V_34 ) ;
F_12 ( 2 ) ;
F_3 ( 0x0000 , V_6 -> V_19 + V_34 ) ;
F_3 ( V_30 >> 16 , V_6 -> V_19 + V_35 ) ;
F_3 ( V_30 , V_6 -> V_19 + V_36 ) ;
F_3 ( 0x0002 , V_6 -> V_19 + V_37 ) ;
F_3 ( 0x40a8 , V_6 -> V_19 + V_38 ) ;
F_3 ( 0x0018 , V_6 -> V_19 + V_39 ) ;
F_3 ( 0x0002 , V_6 -> V_19 + V_40 ) ;
F_12 ( 2 ) ;
F_3 ( 0x000b , V_6 -> V_19 + V_40 ) ;
V_30 = V_29 -> V_32 + V_4 -> V_41 ;
F_3 ( V_30 >> 16 , V_6 -> V_8 + V_42 ) ;
F_3 ( V_30 , V_6 -> V_8 + V_43 ) ;
F_3 ( V_44 - 1 , V_6 -> V_8 + V_45 ) ;
F_3 ( 1 , V_6 -> V_8 + V_46 ) ;
F_3 ( 1 , V_6 -> V_8 + V_47 ) ;
F_3 ( 0 , V_6 -> V_8 + V_48 ) ;
return 0 ;
}
static void F_13 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_15 . V_18 ;
struct V_3 * V_4 = F_9 ( V_15 ) ;
struct V_49 * V_50 = V_4 -> V_50 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_51 ;
F_3 ( 0 , V_6 -> V_8 + V_21 ) ;
V_17 -> V_22 ( V_15 , 0 ) ;
F_3 ( 0x0010 , V_6 -> V_8 + V_23 ) ;
V_17 -> V_52 ( V_15 , V_50 ) ;
V_17 -> V_22 ( V_15 , 1 ) ;
F_3 ( V_4 -> V_53 . V_54 , V_6 -> V_8 + V_55 ) ;
F_3 ( 0 , V_6 -> V_8 + V_56 ) ;
F_3 ( 0 , V_6 -> V_8 + V_57 ) ;
F_3 ( V_4 -> V_53 . V_54 >> 16 , V_6 -> V_8 + V_58 ) ;
F_3 ( V_4 -> V_53 . V_54 , V_6 -> V_8 + V_59 ) ;
F_3 ( V_51 = 0 , V_6 -> V_8 + V_60 ) ;
F_3 ( V_51 += V_50 -> V_61 , V_6 -> V_8 + V_62 ) ;
F_3 ( V_51 += V_50 -> V_63 , V_6 -> V_8 + V_64 ) ;
F_3 ( V_51 += V_50 -> V_65 + V_50 -> V_66 , V_6 -> V_8 + V_67 ) ;
F_3 ( V_50 -> V_65 , V_6 -> V_8 + V_68 ) ;
F_3 ( V_51 = 0 , V_6 -> V_8 + V_69 ) ;
F_3 ( V_51 += V_50 -> V_70 , V_6 -> V_8 + V_71 ) ;
F_3 ( V_51 += V_50 -> V_72 , V_6 -> V_8 + V_73 ) ;
F_3 ( V_51 += V_50 -> V_74 , V_6 -> V_8 + V_75 ) ;
F_3 ( V_51 += V_50 -> V_76 , V_6 -> V_8 + V_77 ) ;
F_3 ( 3 , V_6 -> V_8 + V_78 ) ;
F_3 ( 1 , V_6 -> V_8 + V_21 ) ;
F_3 ( 0x4007 , V_6 -> V_8 + V_79 ) ;
F_3 ( 3 , V_6 -> V_8 + V_80 ) ;
F_3 ( 0x0010 , V_6 -> V_8 + V_23 ) ;
F_12 ( 5 ) ;
F_3 ( 0x0014 , V_6 -> V_8 + V_23 ) ;
F_12 ( 5 ) ;
F_3 ( 0x0015 , V_6 -> V_8 + V_23 ) ;
F_3 ( 0xfffa , V_6 -> V_8 + V_81 ) ;
}
static int T_2
F_14 ( struct V_3 * V_4 , unsigned int V_82 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
if ( F_15 () || V_6 -> V_10 ) {
int V_51 = 0 ;
while ( F_2 ( V_6 -> V_8 + V_83 ) > V_82 ) {
F_16 ( 1 ) ;
V_51 ++ ;
if ( V_51 > 10000 ) {
F_17 ( L_2 ,
V_82 ) ;
return - V_84 ;
}
F_1 ( - 1 , V_4 ) ;
}
} else {
if ( ! F_18 ( V_6 -> V_12 ,
F_2 ( V_6 -> V_8 + V_83 ) <= V_82 ,
1000 ) ) {
F_17 ( L_2 , V_82 ) ;
return - V_84 ;
}
}
return 0 ;
}
static int
F_19 ( struct V_3 * V_4 , const T_3 * V_85 , unsigned int V_86 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_87 ;
V_87 = F_14 ( V_4 , V_44 - V_86 ) ;
if ( V_87 )
return V_87 ;
for (; V_86 ; V_86 -- , V_85 ++ ) {
F_3 ( * V_85 >> 16 , V_6 -> V_8 + V_88 ) ;
F_3 ( * V_85 , V_6 -> V_8 + V_89 ) ;
}
return V_87 ;
}
static int F_20 ( struct V_3 * V_90 )
{
struct V_5 * V_6 = V_90 -> V_6 ;
int V_87 ;
int V_51 = 0 ;
V_87 = F_14 ( V_90 , 0 ) ;
while ( F_2 ( V_6 -> V_8 + V_91 ) & 2 ) {
F_16 ( 1 ) ;
V_51 ++ ;
if ( V_51 > 10000 ) {
F_6 ( V_92 L_3 ) ;
return - V_84 ;
}
}
return V_87 ;
}
static void
F_21 ( struct V_3 * V_90 , const struct V_93 * V_94 )
{
const T_3 V_85 [] = {
F_22 ( ( V_94 -> V_95 * V_90 -> V_50 -> V_65 + V_94 -> V_96 ) * 2 ) ,
F_23 ( V_94 -> V_97 - 1 ) ,
F_24 ( V_94 -> V_98 - 1 ) ,
F_25 ( V_94 -> V_99 ) ,
V_100 ,
} ;
if ( V_90 -> V_101 != V_102 ||
V_90 -> V_103 & V_104 ) {
F_26 ( V_90 , V_94 ) ;
return;
}
F_19 ( V_90 , V_85 , F_27 ( V_85 ) ) ;
}
static void
F_28 ( struct V_3 * V_90 , const struct V_105 * V_106 )
{
const T_3 V_85 [] = {
F_22 ( ( V_106 -> V_95 * V_90 -> V_50 -> V_65 + V_106 -> V_96 ) * 2 ) ,
F_23 ( V_106 -> V_97 - 1 ) ,
F_24 ( V_106 -> V_98 - 1 ) ,
F_29 ( ( V_106 -> V_107 * V_90 -> V_50 -> V_65 + V_106 -> V_108 ) * 2 ) ,
V_109 ,
} ;
if ( V_90 -> V_101 != V_102 ||
V_90 -> V_103 & V_104 ) {
F_30 ( V_90 , V_106 ) ;
return;
}
F_19 ( V_90 , V_85 , F_27 ( V_85 ) ) ;
}
static void F_31 ( struct V_3 * V_4 )
{
const struct V_93 V_94 = {
. V_96 = 0 ,
. V_95 = 0 ,
. V_97 = V_4 -> V_50 -> V_65 ,
. V_98 = V_4 -> V_50 -> V_74 ,
. V_99 = 0 ,
. V_110 = V_111 ,
} ;
V_4 -> V_112 -> V_93 ( V_4 , & V_94 ) ;
}
static int F_32 ( struct V_3 * V_90 , struct V_113 * V_114 )
{
struct V_5 * V_6 = V_90 -> V_6 ;
struct V_49 * V_50 = V_90 -> V_50 ;
unsigned int V_115 = F_2 ( V_6 -> V_8 + V_116 ) ;
unsigned int V_117 = V_50 -> V_70 + V_50 -> V_72 ;
V_114 -> V_115 = V_115 ;
V_114 -> V_103 = V_118 | V_119
| V_120 ;
if ( V_115 < V_50 -> V_70 )
V_114 -> V_103 |= V_121 ;
if ( V_115 < V_117 || V_115 > V_117 + V_50 -> V_74 )
V_114 -> V_103 |= V_122 ;
return 0 ;
}
static int F_33 ( struct V_3 * V_90 ,
unsigned int V_85 , unsigned long V_123 )
{
switch ( V_85 ) {
case V_124 : {
struct V_113 V_114 = { 0 } ;
void T_4 * V_125 = ( void T_4 * ) V_123 ;
F_32 ( V_90 , & V_114 ) ;
if ( F_34 ( V_125 , & V_114 , sizeof V_114 ) )
return - V_126 ;
return 0 ;
}
#ifdef F_4
case V_127 :
F_20 ( V_90 ) ;
return 0 ;
case V_128 : {
T_3 T_4 * V_125 = ( void T_4 * ) V_123 ;
T_3 V_129 ;
T_3 V_130 [ 16 ] ;
if ( F_35 ( V_129 , V_125 ) )
return - V_126 ;
if ( V_129 > F_27 ( V_130 ) )
return - V_31 ;
if ( F_36 ( V_130 , V_125 + 1 , sizeof( T_3 ) * V_129 ) )
return - V_126 ;
return F_19 ( V_90 , V_130 , V_129 ) ;
}
#endif
}
return - V_131 ;
}
static struct V_49 *
F_37 ( struct V_3 * V_4 , struct V_132 * V_133 )
{
struct V_16 * V_17 = V_4 -> V_134 -> V_18 ;
struct V_49 * V_135 = NULL ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_17 -> V_136 ; V_51 ++ ) {
struct V_49 * V_50 = V_17 -> V_137 + V_51 ;
if ( V_50 -> V_65 >= V_133 -> V_65 && V_50 -> V_74 >= V_133 -> V_74
&& ( ! V_135 || ( V_50 -> V_65 < V_135 -> V_65
&& V_50 -> V_74 < V_135 -> V_74 ) ) )
V_135 = V_50 ;
}
return V_135 ;
}
static int F_38 ( struct V_132 * V_133 , struct V_3 * V_4 )
{
struct V_49 * V_50 ;
struct V_16 * V_17 = V_4 -> V_134 -> V_18 ;
V_50 = F_37 ( V_4 , V_133 ) ;
if ( ! V_50 || V_133 -> V_138 > 16 )
return - V_31 ;
F_39 ( V_133 , V_50 ) ;
V_133 -> V_139 = V_50 -> V_65 ;
V_133 -> V_140 = V_4 -> V_41 / ( V_50 -> V_65 * 2 ) ;
if ( V_133 -> V_140 < V_133 -> V_74 )
return - V_31 ;
V_133 -> V_141 = 0 ;
V_133 -> V_142 = 0 ;
V_133 -> V_138 = 16 ;
V_133 -> V_143 = 0 ;
V_133 -> V_144 . V_145 = 11 ;
V_133 -> V_144 . V_146 = 5 ;
V_133 -> V_147 . V_145 = 5 ;
V_133 -> V_147 . V_146 = 6 ;
V_133 -> V_148 . V_145 = 0 ;
V_133 -> V_148 . V_146 = 5 ;
V_133 -> V_149 . V_145 = 0 ;
V_133 -> V_149 . V_146 = 0 ;
V_133 -> V_150 = 0 ;
V_133 -> V_98 = V_17 -> V_98 ;
V_133 -> V_97 = V_17 -> V_97 ;
V_133 -> V_151 = 0 ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 )
{
struct V_132 * V_133 = & V_4 -> V_133 ;
struct V_49 * V_50 ;
V_50 = F_37 ( V_4 , V_133 ) ;
if ( ! V_50 )
return - V_31 ;
V_4 -> V_50 = V_50 ;
V_4 -> V_53 . V_54 = V_4 -> V_50 -> V_65 *
V_133 -> V_138 / 8 ;
F_13 ( F_41 ( V_4 -> V_134 ) ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static int F_42 ( unsigned V_152 , unsigned V_144 , unsigned V_147 ,
unsigned V_148 , unsigned V_149 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_152 < F_27 ( V_6 -> V_153 ) ) {
V_6 -> V_153 [ V_152 ] =
( ( V_144 & 0xf800 ) ) |
( ( V_147 & 0xfc00 ) >> 5 ) |
( ( V_148 & 0xf800 ) >> 11 ) ;
return 0 ;
}
return - V_31 ;
}
static int F_43 ( int V_154 , struct V_3 * V_4 )
{
return 0 ;
}
static int T_5 F_44 ( struct V_14 * V_15 )
{
const struct V_24 * V_25 = F_11 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_15 . V_18 ;
struct V_26 * V_19 = F_45 ( V_15 , V_155 , 1 ) ;
struct V_26 * V_8 = F_45 ( V_15 , V_155 , 0 ) ;
struct V_26 * V_29 = F_45 ( V_15 , V_155 , 2 ) ;
int V_1 = F_46 ( V_15 , 0 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_156 ;
if ( V_17 == NULL ) {
F_47 ( & V_15 -> V_15 , L_4 ) ;
return - V_31 ;
}
V_4 = F_48 ( sizeof( struct V_5 ) , & V_15 -> V_15 ) ;
if ( ! V_4 )
return - V_157 ;
V_6 = V_4 -> V_6 ;
#ifdef F_4
F_49 ( & V_6 -> V_12 ) ;
V_6 -> V_10 = true ;
V_4 -> V_103 = V_158 | V_159
| V_160 ;
#else
V_4 -> V_103 = V_158 ;
#endif
V_4 -> V_112 = & V_161 ;
strcpy ( V_4 -> V_53 . V_162 , L_5 ) ;
V_4 -> V_53 . V_163 = V_29 -> V_32 ;
V_4 -> V_53 . V_164 = F_50 ( V_29 ) ;
V_4 -> V_53 . type = V_165 ;
V_4 -> V_53 . V_166 = V_167 ;
V_4 -> V_53 . V_168 = V_8 -> V_32 ;
V_4 -> V_53 . V_169 = F_50 ( V_8 ) ;
V_4 -> V_53 . V_170 = V_171 ;
V_4 -> V_41 = V_4 -> V_53 . V_164 - ( 4 * V_44 ) ;
V_4 -> V_153 = V_6 -> V_153 ;
V_6 -> V_19 = F_51 ( V_19 -> V_32 , F_50 ( V_19 ) ) ;
if ( ! V_6 -> V_19 ) {
V_156 = - V_157 ;
goto V_172;
}
V_6 -> V_8 = F_51 ( V_4 -> V_53 . V_168 , V_4 -> V_53 . V_169 ) ;
if ( ! V_6 -> V_8 ) {
V_156 = - V_157 ;
goto V_173;
}
V_4 -> V_174 = F_51 ( V_4 -> V_53 . V_163 , V_4 -> V_53 . V_164 ) ;
if ( ! V_4 -> V_174 ) {
V_156 = - V_157 ;
goto V_175;
}
V_156 = F_52 ( V_1 , & F_1 , 0 ,
F_53 ( & V_15 -> V_15 ) , V_4 ) ;
if ( V_156 )
goto V_176;
F_54 ( V_15 , V_4 ) ;
V_156 = F_55 ( & V_4 -> V_133 , V_4 , V_177 ,
V_17 -> V_137 , V_17 -> V_136 ,
V_17 -> V_137 , 16 ) ;
if ( ! V_156 ) {
V_156 = - V_31 ;
goto V_178;
}
if ( V_25 -> V_179 ) {
V_156 = V_25 -> V_179 ( V_15 ) ;
if ( V_156 )
goto V_180;
}
V_156 = F_10 ( V_15 ) ;
if ( V_156 )
goto V_181;
F_56 ( V_17 -> V_137 , V_17 -> V_136 ,
& V_4 -> V_182 ) ;
V_156 = F_57 ( V_4 ) ;
if ( V_156 < 0 )
goto V_183;
F_6 ( V_11 L_6 ,
V_4 -> V_184 , V_4 -> V_53 . V_162 ) ;
return 0 ;
V_183:
F_8 ( V_15 ) ;
V_181:
if ( V_25 -> V_185 )
V_25 -> V_185 ( V_15 ) ;
V_180:
V_178:
F_54 ( V_15 , NULL ) ;
F_58 ( V_1 , V_4 ) ;
V_176:
F_59 ( V_4 -> V_174 ) ;
V_175:
F_59 ( V_6 -> V_8 ) ;
V_173:
F_59 ( V_6 -> V_19 ) ;
V_172:
F_60 ( V_4 ) ;
return V_156 ;
}
static int T_6 F_61 ( struct V_14 * V_15 )
{
const struct V_24 * V_25 = F_11 ( V_15 ) ;
struct V_3 * V_4 = F_9 ( V_15 ) ;
int V_1 = F_46 ( V_15 , 0 ) ;
struct V_5 * V_6 ;
if ( V_4 ) {
V_6 = V_4 -> V_6 ;
F_62 ( V_4 ) ;
F_8 ( V_15 ) ;
if ( V_25 -> V_185 )
V_25 -> V_185 ( V_15 ) ;
F_54 ( V_15 , NULL ) ;
F_58 ( V_1 , V_4 ) ;
F_59 ( V_4 -> V_174 ) ;
F_59 ( V_6 -> V_8 ) ;
F_59 ( V_6 -> V_19 ) ;
F_60 ( V_4 ) ;
}
return 0 ;
}
static void F_63 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_9 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_6 ( V_186 L_7 ) ;
#define F_64 ( T_7 ) printk(KERN_DEBUG "\t" #n " = \t%04x\n",\
tmio_ioread16(par->ccr + CCR_ ## n));
F_64 ( V_187 ) ;
F_64 ( V_188 ) ;
F_64 ( V_189 ) ;
F_64 ( V_190 ) ;
F_64 ( V_191 ) ;
F_64 ( V_192 ) ;
F_64 ( V_193 ) ;
F_64 ( V_194 ) ;
F_64 ( V_195 ) ;
F_64 ( V_196 ) ;
#undef F_64
F_6 ( V_186 L_8 ) ;
#define F_65 ( T_7 ) printk(KERN_DEBUG "\t" #n " = \t%04x\n",\
tmio_ioread16(par->lcr + LCR_ ## n));
F_65 ( V_197 ) ;
F_65 ( V_198 ) ;
F_65 ( V_199 ) ;
F_65 ( V_200 ) ;
F_65 ( V_201 ) ;
F_65 ( V_202 ) ;
F_65 ( V_203 ) ;
F_65 ( V_204 ) ;
F_65 ( V_205 ) ;
F_65 ( V_206 ) ;
F_65 ( V_207 ) ;
F_65 ( V_208 ) ;
F_65 ( V_209 ) ;
F_65 ( V_210 ) ;
F_65 ( V_211 ) ;
F_65 ( V_212 ) ;
F_65 ( V_213 ) ;
F_65 ( V_214 ) ;
F_65 ( V_215 ) ;
F_65 ( V_216 ) ;
F_65 ( V_217 ) ;
F_65 ( V_218 ) ;
F_65 ( V_219 ) ;
F_65 ( V_220 ) ;
F_65 ( V_221 ) ;
F_65 ( V_222 ) ;
F_65 ( V_223 ) ;
F_65 ( V_224 ) ;
F_65 ( V_225 ) ;
F_65 ( V_226 ) ;
F_65 ( V_227 ) ;
F_65 ( V_228 ) ;
F_65 ( V_229 ) ;
F_65 ( V_230 ) ;
F_65 ( V_231 ) ;
F_65 ( V_232 ) ;
F_65 ( V_233 ) ;
F_65 ( V_234 ) ;
F_65 ( V_235 ) ;
F_65 ( V_236 ) ;
F_65 ( V_237 ) ;
F_65 ( V_238 ) ;
F_65 ( V_239 ) ;
F_65 ( V_240 ) ;
F_65 ( V_241 ) ;
F_65 ( V_242 ) ;
F_65 ( V_243 ) ;
F_65 ( V_244 ) ;
F_65 ( V_245 ) ;
F_65 ( V_246 ) ;
F_65 ( V_247 ) ;
F_65 ( V_248 ) ;
F_65 ( V_249 ) ;
F_65 ( V_250 ) ;
F_65 ( V_251 ) ;
F_65 ( V_252 ) ;
F_65 ( V_253 ) ;
F_65 ( V_254 ) ;
F_65 ( V_255 ) ;
F_65 ( V_256 ) ;
F_65 ( V_257 ) ;
F_65 ( V_258 ) ;
F_65 ( V_259 ) ;
F_65 ( V_260 ) ;
F_65 ( V_261 ) ;
F_65 ( V_262 ) ;
F_65 ( V_263 ) ;
#undef F_65
}
static int F_66 ( struct V_14 * V_15 , T_8 V_101 )
{
struct V_3 * V_4 = F_9 ( V_15 ) ;
#ifdef F_4
struct V_5 * V_6 = V_4 -> V_6 ;
#endif
const struct V_24 * V_25 = F_11 ( V_15 ) ;
int V_156 = 0 ;
F_67 () ;
F_68 ( V_4 , 1 ) ;
if ( V_4 -> V_112 -> V_264 )
V_4 -> V_112 -> V_264 ( V_4 ) ;
#ifdef F_4
F_6 ( V_11 L_9 ) ;
V_6 -> V_10 = true ;
#endif
F_8 ( V_15 ) ;
if ( V_25 -> V_265 )
V_156 = V_25 -> V_265 ( V_15 ) ;
F_69 () ;
return V_156 ;
}
static int F_70 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_9 ( V_15 ) ;
const struct V_24 * V_25 = F_11 ( V_15 ) ;
int V_156 = 0 ;
F_67 () ;
if ( V_25 -> V_266 ) {
V_156 = V_25 -> V_266 ( V_15 ) ;
if ( V_156 )
goto V_267;
}
F_1 ( - 1 , V_4 ) ;
F_10 ( V_15 ) ;
F_13 ( V_15 ) ;
F_68 ( V_4 , 0 ) ;
V_267:
F_69 () ;
return V_156 ;
}
static void T_9 F_71 ( char * V_268 )
{
char * V_269 ;
if ( ! V_268 || ! * V_268 )
return;
while ( ( V_269 = F_72 ( & V_268 , L_10 ) ) != NULL ) {
if ( ! * V_269 )
continue;
}
}
static int T_9 F_73 ( void )
{
#ifndef F_74
char * V_270 = NULL ;
if ( F_75 ( L_11 , & V_270 ) )
return - V_271 ;
F_71 ( V_270 ) ;
#endif
return F_76 ( & V_272 ) ;
}
static void T_10 F_77 ( void )
{
F_78 ( & V_272 ) ;
}
