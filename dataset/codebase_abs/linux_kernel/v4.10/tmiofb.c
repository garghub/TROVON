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
struct V_16 * V_17 = F_9 ( & V_15 -> V_15 ) ;
struct V_3 * V_4 = F_10 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_3 ( 0 , V_6 -> V_18 + V_19 ) ;
F_3 ( 0 , V_6 -> V_8 + V_20 ) ;
V_17 -> V_21 ( V_15 , 0 ) ;
F_3 ( 0x0010 , V_6 -> V_8 + V_22 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 )
{
const struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_3 * V_4 = F_10 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
const struct V_25 * V_26 = & V_24 -> V_27 [ 0 ] ;
const struct V_25 * V_28 = & V_24 -> V_27 [ 2 ] ;
unsigned long V_29 ;
if ( V_26 == NULL || V_28 == NULL )
return - V_30 ;
V_29 = V_26 -> V_31 ;
F_3 ( 0x003a , V_6 -> V_18 + V_19 ) ;
F_3 ( 0x003a , V_6 -> V_18 + V_32 ) ;
F_3 ( 0x3f00 , V_6 -> V_18 + V_33 ) ;
F_13 ( 2 ) ;
F_3 ( 0x0000 , V_6 -> V_18 + V_33 ) ;
F_3 ( V_29 >> 16 , V_6 -> V_18 + V_34 ) ;
F_3 ( V_29 , V_6 -> V_18 + V_35 ) ;
F_3 ( 0x0002 , V_6 -> V_18 + V_36 ) ;
F_3 ( 0x40a8 , V_6 -> V_18 + V_37 ) ;
F_3 ( 0x0018 , V_6 -> V_18 + V_38 ) ;
F_3 ( 0x0002 , V_6 -> V_18 + V_39 ) ;
F_13 ( 2 ) ;
F_3 ( 0x000b , V_6 -> V_18 + V_39 ) ;
V_29 = V_28 -> V_31 + V_4 -> V_40 ;
F_3 ( V_29 >> 16 , V_6 -> V_8 + V_41 ) ;
F_3 ( V_29 , V_6 -> V_8 + V_42 ) ;
F_3 ( V_43 - 1 , V_6 -> V_8 + V_44 ) ;
F_3 ( 1 , V_6 -> V_8 + V_45 ) ;
F_3 ( 1 , V_6 -> V_8 + V_46 ) ;
F_3 ( 0 , V_6 -> V_8 + V_47 ) ;
return 0 ;
}
static void F_14 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_9 ( & V_15 -> V_15 ) ;
struct V_3 * V_4 = F_10 ( V_15 ) ;
struct V_48 * V_49 = V_4 -> V_49 ;
struct V_5 * V_6 = V_4 -> V_6 ;
unsigned int V_50 ;
F_3 ( 0 , V_6 -> V_8 + V_20 ) ;
V_17 -> V_21 ( V_15 , 0 ) ;
F_3 ( 0x0010 , V_6 -> V_8 + V_22 ) ;
V_17 -> V_51 ( V_15 , V_49 ) ;
V_17 -> V_21 ( V_15 , 1 ) ;
F_3 ( V_4 -> V_52 . V_53 , V_6 -> V_8 + V_54 ) ;
F_3 ( 0 , V_6 -> V_8 + V_55 ) ;
F_3 ( 0 , V_6 -> V_8 + V_56 ) ;
F_3 ( V_4 -> V_52 . V_53 >> 16 , V_6 -> V_8 + V_57 ) ;
F_3 ( V_4 -> V_52 . V_53 , V_6 -> V_8 + V_58 ) ;
F_3 ( V_50 = 0 , V_6 -> V_8 + V_59 ) ;
F_3 ( V_50 += V_49 -> V_60 , V_6 -> V_8 + V_61 ) ;
F_3 ( V_50 += V_49 -> V_62 , V_6 -> V_8 + V_63 ) ;
F_3 ( V_50 += V_49 -> V_64 + V_49 -> V_65 , V_6 -> V_8 + V_66 ) ;
F_3 ( V_49 -> V_64 , V_6 -> V_8 + V_67 ) ;
F_3 ( V_50 = 0 , V_6 -> V_8 + V_68 ) ;
F_3 ( V_50 += V_49 -> V_69 , V_6 -> V_8 + V_70 ) ;
F_3 ( V_50 += V_49 -> V_71 , V_6 -> V_8 + V_72 ) ;
F_3 ( V_50 += V_49 -> V_73 , V_6 -> V_8 + V_74 ) ;
F_3 ( V_50 += V_49 -> V_75 , V_6 -> V_8 + V_76 ) ;
F_3 ( 3 , V_6 -> V_8 + V_77 ) ;
F_3 ( 1 , V_6 -> V_8 + V_20 ) ;
F_3 ( 0x4007 , V_6 -> V_8 + V_78 ) ;
F_3 ( 3 , V_6 -> V_8 + V_79 ) ;
F_3 ( 0x0010 , V_6 -> V_8 + V_22 ) ;
F_13 ( 5 ) ;
F_3 ( 0x0014 , V_6 -> V_8 + V_22 ) ;
F_13 ( 5 ) ;
F_3 ( 0x0015 , V_6 -> V_8 + V_22 ) ;
F_3 ( 0xfffa , V_6 -> V_8 + V_80 ) ;
}
static int T_2
F_15 ( struct V_3 * V_4 , unsigned int V_81 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
if ( F_16 () || V_6 -> V_10 ) {
int V_50 = 0 ;
while ( F_2 ( V_6 -> V_8 + V_82 ) > V_81 ) {
F_17 ( 1 ) ;
V_50 ++ ;
if ( V_50 > 10000 ) {
F_18 ( L_2 ,
V_81 ) ;
return - V_83 ;
}
F_1 ( - 1 , V_4 ) ;
}
} else {
if ( ! F_19 ( V_6 -> V_12 ,
F_2 ( V_6 -> V_8 + V_82 ) <= V_81 ,
1000 ) ) {
F_18 ( L_2 , V_81 ) ;
return - V_83 ;
}
}
return 0 ;
}
static int
F_20 ( struct V_3 * V_4 , const T_3 * V_84 , unsigned int V_85 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
int V_86 ;
V_86 = F_15 ( V_4 , V_43 - V_85 ) ;
if ( V_86 )
return V_86 ;
for (; V_85 ; V_85 -- , V_84 ++ ) {
F_3 ( * V_84 >> 16 , V_6 -> V_8 + V_87 ) ;
F_3 ( * V_84 , V_6 -> V_8 + V_88 ) ;
}
return V_86 ;
}
static int F_21 ( struct V_3 * V_89 )
{
struct V_5 * V_6 = V_89 -> V_6 ;
int V_86 ;
int V_50 = 0 ;
V_86 = F_15 ( V_89 , 0 ) ;
while ( F_2 ( V_6 -> V_8 + V_90 ) & 2 ) {
F_17 ( 1 ) ;
V_50 ++ ;
if ( V_50 > 10000 ) {
F_6 ( V_91 L_3 ) ;
return - V_83 ;
}
}
return V_86 ;
}
static void
F_22 ( struct V_3 * V_89 , const struct V_92 * V_93 )
{
const T_3 V_84 [] = {
F_23 ( ( V_93 -> V_94 * V_89 -> V_49 -> V_64 + V_93 -> V_95 ) * 2 ) ,
F_24 ( V_93 -> V_96 - 1 ) ,
F_25 ( V_93 -> V_97 - 1 ) ,
F_26 ( V_93 -> V_98 ) ,
V_99 ,
} ;
if ( V_89 -> V_100 != V_101 ||
V_89 -> V_102 & V_103 ) {
F_27 ( V_89 , V_93 ) ;
return;
}
F_20 ( V_89 , V_84 , F_28 ( V_84 ) ) ;
}
static void
F_29 ( struct V_3 * V_89 , const struct V_104 * V_105 )
{
const T_3 V_84 [] = {
F_23 ( ( V_105 -> V_94 * V_89 -> V_49 -> V_64 + V_105 -> V_95 ) * 2 ) ,
F_24 ( V_105 -> V_96 - 1 ) ,
F_25 ( V_105 -> V_97 - 1 ) ,
F_30 ( ( V_105 -> V_106 * V_89 -> V_49 -> V_64 + V_105 -> V_107 ) * 2 ) ,
V_108 ,
} ;
if ( V_89 -> V_100 != V_101 ||
V_89 -> V_102 & V_103 ) {
F_31 ( V_89 , V_105 ) ;
return;
}
F_20 ( V_89 , V_84 , F_28 ( V_84 ) ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
const struct V_92 V_93 = {
. V_95 = 0 ,
. V_94 = 0 ,
. V_96 = V_4 -> V_49 -> V_64 ,
. V_97 = V_4 -> V_49 -> V_73 ,
. V_98 = 0 ,
. V_109 = V_110 ,
} ;
V_4 -> V_111 -> V_92 ( V_4 , & V_93 ) ;
}
static int F_33 ( struct V_3 * V_89 , struct V_112 * V_113 )
{
struct V_5 * V_6 = V_89 -> V_6 ;
struct V_48 * V_49 = V_89 -> V_49 ;
unsigned int V_114 = F_2 ( V_6 -> V_8 + V_115 ) ;
unsigned int V_116 = V_49 -> V_69 + V_49 -> V_71 ;
V_113 -> V_114 = V_114 ;
V_113 -> V_102 = V_117 | V_118
| V_119 ;
if ( V_114 < V_49 -> V_69 )
V_113 -> V_102 |= V_120 ;
if ( V_114 < V_116 || V_114 > V_116 + V_49 -> V_73 )
V_113 -> V_102 |= V_121 ;
return 0 ;
}
static int F_34 ( struct V_3 * V_89 ,
unsigned int V_84 , unsigned long V_122 )
{
switch ( V_84 ) {
case V_123 : {
struct V_112 V_113 = { 0 } ;
void T_4 * V_124 = ( void T_4 * ) V_122 ;
F_33 ( V_89 , & V_113 ) ;
if ( F_35 ( V_124 , & V_113 , sizeof V_113 ) )
return - V_125 ;
return 0 ;
}
#ifdef F_4
case V_126 :
F_21 ( V_89 ) ;
return 0 ;
case V_127 : {
T_3 T_4 * V_124 = ( void T_4 * ) V_122 ;
T_3 V_128 ;
T_3 V_129 [ 16 ] ;
if ( F_36 ( V_128 , V_124 ) )
return - V_125 ;
if ( V_128 > F_28 ( V_129 ) )
return - V_30 ;
if ( F_37 ( V_129 , V_124 + 1 , sizeof( T_3 ) * V_128 ) )
return - V_125 ;
return F_20 ( V_89 , V_129 , V_128 ) ;
}
#endif
}
return - V_130 ;
}
static struct V_48 *
F_38 ( struct V_3 * V_4 , struct V_131 * V_132 )
{
struct V_16 * V_17 = F_9 ( V_4 -> V_133 ) ;
struct V_48 * V_134 = NULL ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_17 -> V_135 ; V_50 ++ ) {
struct V_48 * V_49 = V_17 -> V_136 + V_50 ;
if ( V_49 -> V_64 >= V_132 -> V_64 && V_49 -> V_73 >= V_132 -> V_73
&& ( ! V_134 || ( V_49 -> V_64 < V_134 -> V_64
&& V_49 -> V_73 < V_134 -> V_73 ) ) )
V_134 = V_49 ;
}
return V_134 ;
}
static int F_39 ( struct V_131 * V_132 , struct V_3 * V_4 )
{
struct V_48 * V_49 ;
struct V_16 * V_17 = F_9 ( V_4 -> V_133 ) ;
V_49 = F_38 ( V_4 , V_132 ) ;
if ( ! V_49 || V_132 -> V_137 > 16 )
return - V_30 ;
F_40 ( V_132 , V_49 ) ;
V_132 -> V_138 = V_49 -> V_64 ;
V_132 -> V_139 = V_4 -> V_40 / ( V_49 -> V_64 * 2 ) ;
if ( V_132 -> V_139 < V_132 -> V_73 )
return - V_30 ;
V_132 -> V_140 = 0 ;
V_132 -> V_141 = 0 ;
V_132 -> V_137 = 16 ;
V_132 -> V_142 = 0 ;
V_132 -> V_143 . V_144 = 11 ;
V_132 -> V_143 . V_145 = 5 ;
V_132 -> V_146 . V_144 = 5 ;
V_132 -> V_146 . V_145 = 6 ;
V_132 -> V_147 . V_144 = 0 ;
V_132 -> V_147 . V_145 = 5 ;
V_132 -> V_148 . V_144 = 0 ;
V_132 -> V_148 . V_145 = 0 ;
V_132 -> V_149 = 0 ;
V_132 -> V_97 = V_17 -> V_97 ;
V_132 -> V_96 = V_17 -> V_96 ;
V_132 -> V_150 = 0 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 )
{
struct V_131 * V_132 = & V_4 -> V_132 ;
struct V_48 * V_49 ;
V_49 = F_38 ( V_4 , V_132 ) ;
if ( ! V_49 )
return - V_30 ;
V_4 -> V_49 = V_49 ;
V_4 -> V_52 . V_53 = V_4 -> V_49 -> V_64 *
V_132 -> V_137 / 8 ;
F_14 ( F_42 ( V_4 -> V_133 ) ) ;
F_32 ( V_4 ) ;
return 0 ;
}
static int F_43 ( unsigned V_151 , unsigned V_143 , unsigned V_146 ,
unsigned V_147 , unsigned V_148 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_151 < F_28 ( V_6 -> V_152 ) ) {
V_6 -> V_152 [ V_151 ] =
( ( V_143 & 0xf800 ) ) |
( ( V_146 & 0xfc00 ) >> 5 ) |
( ( V_147 & 0xf800 ) >> 11 ) ;
return 0 ;
}
return - V_30 ;
}
static int F_44 ( int V_153 , struct V_3 * V_4 )
{
return 0 ;
}
static int F_45 ( struct V_14 * V_15 )
{
const struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_16 * V_17 = F_9 ( & V_15 -> V_15 ) ;
struct V_25 * V_18 = F_46 ( V_15 , V_154 , 1 ) ;
struct V_25 * V_8 = F_46 ( V_15 , V_154 , 0 ) ;
struct V_25 * V_28 = F_46 ( V_15 , V_154 , 2 ) ;
int V_1 = F_47 ( V_15 , 0 ) ;
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_155 ;
if ( V_17 == NULL ) {
F_48 ( & V_15 -> V_15 , L_4 ) ;
return - V_30 ;
}
if ( V_18 == NULL || V_8 == NULL || V_28 == NULL || V_1 < 0 ) {
F_48 ( & V_15 -> V_15 , L_5 ) ;
return - V_30 ;
}
V_4 = F_49 ( sizeof( struct V_5 ) , & V_15 -> V_15 ) ;
if ( ! V_4 )
return - V_156 ;
V_6 = V_4 -> V_6 ;
#ifdef F_4
F_50 ( & V_6 -> V_12 ) ;
V_6 -> V_10 = true ;
V_4 -> V_102 = V_157 | V_158
| V_159 ;
#else
V_4 -> V_102 = V_157 ;
#endif
V_4 -> V_111 = & V_160 ;
strcpy ( V_4 -> V_52 . V_161 , L_6 ) ;
V_4 -> V_52 . V_162 = V_28 -> V_31 ;
V_4 -> V_52 . V_163 = F_51 ( V_28 ) ;
V_4 -> V_52 . type = V_164 ;
V_4 -> V_52 . V_165 = V_166 ;
V_4 -> V_52 . V_167 = V_8 -> V_31 ;
V_4 -> V_52 . V_168 = F_51 ( V_8 ) ;
V_4 -> V_52 . V_169 = V_170 ;
V_4 -> V_40 = V_4 -> V_52 . V_163 - ( 4 * V_43 ) ;
V_4 -> V_152 = V_6 -> V_152 ;
V_6 -> V_18 = F_52 ( V_18 -> V_31 , F_51 ( V_18 ) ) ;
if ( ! V_6 -> V_18 ) {
V_155 = - V_156 ;
goto V_171;
}
V_6 -> V_8 = F_52 ( V_4 -> V_52 . V_167 , V_4 -> V_52 . V_168 ) ;
if ( ! V_6 -> V_8 ) {
V_155 = - V_156 ;
goto V_172;
}
V_4 -> V_173 = F_52 ( V_4 -> V_52 . V_162 , V_4 -> V_52 . V_163 ) ;
if ( ! V_4 -> V_173 ) {
V_155 = - V_156 ;
goto V_174;
}
V_155 = F_53 ( V_1 , & F_1 , 0 ,
F_54 ( & V_15 -> V_15 ) , V_4 ) ;
if ( V_155 )
goto V_175;
F_55 ( V_15 , V_4 ) ;
V_155 = F_56 ( & V_4 -> V_132 , V_4 , V_176 ,
V_17 -> V_136 , V_17 -> V_135 ,
V_17 -> V_136 , 16 ) ;
if ( ! V_155 ) {
V_155 = - V_30 ;
goto V_177;
}
if ( V_24 -> V_178 ) {
V_155 = V_24 -> V_178 ( V_15 ) ;
if ( V_155 )
goto V_179;
}
V_155 = F_11 ( V_15 ) ;
if ( V_155 )
goto V_180;
F_57 ( V_17 -> V_136 , V_17 -> V_135 ,
& V_4 -> V_181 ) ;
V_155 = F_58 ( V_4 ) ;
if ( V_155 < 0 )
goto V_182;
V_3 ( V_4 , L_7 , V_4 -> V_52 . V_161 ) ;
return 0 ;
V_182:
F_8 ( V_15 ) ;
V_180:
if ( V_24 -> V_183 )
V_24 -> V_183 ( V_15 ) ;
V_179:
V_177:
F_59 ( V_1 , V_4 ) ;
V_175:
F_60 ( V_4 -> V_173 ) ;
V_174:
F_60 ( V_6 -> V_8 ) ;
V_172:
F_60 ( V_6 -> V_18 ) ;
V_171:
F_61 ( V_4 ) ;
return V_155 ;
}
static int F_62 ( struct V_14 * V_15 )
{
const struct V_23 * V_24 = F_12 ( V_15 ) ;
struct V_3 * V_4 = F_10 ( V_15 ) ;
int V_1 = F_47 ( V_15 , 0 ) ;
struct V_5 * V_6 ;
if ( V_4 ) {
V_6 = V_4 -> V_6 ;
F_63 ( V_4 ) ;
F_8 ( V_15 ) ;
if ( V_24 -> V_183 )
V_24 -> V_183 ( V_15 ) ;
F_59 ( V_1 , V_4 ) ;
F_60 ( V_4 -> V_173 ) ;
F_60 ( V_6 -> V_8 ) ;
F_60 ( V_6 -> V_18 ) ;
F_61 ( V_4 ) ;
}
return 0 ;
}
static void F_64 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_10 ( V_15 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
F_6 ( V_184 L_8 ) ;
#define F_65 ( T_5 ) printk(KERN_DEBUG "\t" #n " = \t%04x\n",\
tmio_ioread16(par->ccr + CCR_ ## n));
F_65 ( V_185 ) ;
F_65 ( V_186 ) ;
F_65 ( V_187 ) ;
F_65 ( V_188 ) ;
F_65 ( V_189 ) ;
F_65 ( V_190 ) ;
F_65 ( V_191 ) ;
F_65 ( V_192 ) ;
F_65 ( V_193 ) ;
F_65 ( V_194 ) ;
#undef F_65
F_6 ( V_184 L_9 ) ;
#define F_66 ( T_5 ) printk(KERN_DEBUG "\t" #n " = \t%04x\n",\
tmio_ioread16(par->lcr + LCR_ ## n));
F_66 ( V_195 ) ;
F_66 ( V_196 ) ;
F_66 ( V_197 ) ;
F_66 ( V_198 ) ;
F_66 ( V_199 ) ;
F_66 ( V_200 ) ;
F_66 ( V_201 ) ;
F_66 ( V_202 ) ;
F_66 ( V_203 ) ;
F_66 ( V_204 ) ;
F_66 ( V_205 ) ;
F_66 ( V_206 ) ;
F_66 ( V_207 ) ;
F_66 ( V_208 ) ;
F_66 ( V_209 ) ;
F_66 ( V_210 ) ;
F_66 ( V_211 ) ;
F_66 ( V_212 ) ;
F_66 ( V_213 ) ;
F_66 ( V_214 ) ;
F_66 ( V_215 ) ;
F_66 ( V_216 ) ;
F_66 ( V_217 ) ;
F_66 ( V_218 ) ;
F_66 ( V_219 ) ;
F_66 ( V_220 ) ;
F_66 ( V_221 ) ;
F_66 ( V_222 ) ;
F_66 ( V_223 ) ;
F_66 ( V_224 ) ;
F_66 ( V_225 ) ;
F_66 ( V_226 ) ;
F_66 ( V_227 ) ;
F_66 ( V_228 ) ;
F_66 ( V_229 ) ;
F_66 ( V_230 ) ;
F_66 ( V_231 ) ;
F_66 ( V_232 ) ;
F_66 ( V_233 ) ;
F_66 ( V_234 ) ;
F_66 ( V_235 ) ;
F_66 ( V_236 ) ;
F_66 ( V_237 ) ;
F_66 ( V_238 ) ;
F_66 ( V_239 ) ;
F_66 ( V_240 ) ;
F_66 ( V_241 ) ;
F_66 ( V_242 ) ;
F_66 ( V_243 ) ;
F_66 ( V_244 ) ;
F_66 ( V_245 ) ;
F_66 ( V_246 ) ;
F_66 ( V_247 ) ;
F_66 ( V_248 ) ;
F_66 ( V_249 ) ;
F_66 ( V_250 ) ;
F_66 ( V_251 ) ;
F_66 ( V_252 ) ;
F_66 ( V_253 ) ;
F_66 ( V_254 ) ;
F_66 ( V_255 ) ;
F_66 ( V_256 ) ;
F_66 ( V_257 ) ;
F_66 ( V_258 ) ;
F_66 ( V_259 ) ;
F_66 ( V_260 ) ;
F_66 ( V_261 ) ;
#undef F_66
}
static int F_67 ( struct V_14 * V_15 , T_6 V_100 )
{
struct V_3 * V_4 = F_10 ( V_15 ) ;
#ifdef F_4
struct V_5 * V_6 = V_4 -> V_6 ;
#endif
const struct V_23 * V_24 = F_12 ( V_15 ) ;
int V_155 = 0 ;
F_68 () ;
F_69 ( V_4 , 1 ) ;
if ( V_4 -> V_111 -> V_262 )
V_4 -> V_111 -> V_262 ( V_4 ) ;
#ifdef F_4
F_6 ( V_11 L_10 ) ;
V_6 -> V_10 = true ;
#endif
F_8 ( V_15 ) ;
if ( V_24 -> V_263 )
V_155 = V_24 -> V_263 ( V_15 ) ;
F_70 () ;
return V_155 ;
}
static int F_71 ( struct V_14 * V_15 )
{
struct V_3 * V_4 = F_10 ( V_15 ) ;
const struct V_23 * V_24 = F_12 ( V_15 ) ;
int V_155 = 0 ;
F_68 () ;
if ( V_24 -> V_264 ) {
V_155 = V_24 -> V_264 ( V_15 ) ;
if ( V_155 )
goto V_265;
}
F_1 ( - 1 , V_4 ) ;
F_11 ( V_15 ) ;
F_14 ( V_15 ) ;
F_69 ( V_4 , 0 ) ;
V_265:
F_70 () ;
return V_155 ;
}
static void T_7 F_72 ( char * V_266 )
{
char * V_267 ;
if ( ! V_266 || ! * V_266 )
return;
while ( ( V_267 = F_73 ( & V_266 , L_11 ) ) != NULL ) {
if ( ! * V_267 )
continue;
}
}
static int T_7 F_74 ( void )
{
#ifndef F_75
char * V_268 = NULL ;
if ( F_76 ( L_12 , & V_268 ) )
return - V_269 ;
F_72 ( V_268 ) ;
#endif
return F_77 ( & V_270 ) ;
}
static void T_8 F_78 ( void )
{
F_79 ( & V_270 ) ;
}
