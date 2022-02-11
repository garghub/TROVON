int F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
int F_3 ( void )
{
int V_2 ;
int V_3 = 0 ;
F_4 (cpu)
V_3 += F_5 ( V_4 , V_2 ) ;
return V_3 ;
}
static struct V_5 * F_6 ( struct V_6 * V_7 ,
int V_8 )
{
#ifdef F_7
T_1 V_9 = V_10 | V_11 ;
#else
T_1 V_9 = V_10 ;
#endif
struct V_12 * V_12 = F_8 ( V_8 , V_9 , V_13 ) ;
return V_12 ? F_9 ( V_12 ) : NULL ;
}
static inline void F_10 ( struct V_5 * V_14 )
{
F_11 ( ( unsigned long ) V_14 , V_13 ) ;
}
static void F_12 ( struct V_5 * V_14 , int V_15 )
{
struct V_16 * V_16 = F_13 ( F_14 ( V_14 ) ) ;
F_15 ( V_16 , V_17 , V_15 ) ;
}
void F_16 ( struct V_6 * V_7 )
{
F_17 ( & V_7 -> V_18 ) ;
F_12 ( V_7 -> V_19 , - 1 ) ;
F_10 ( V_7 -> V_19 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
F_20 ( V_7 ) ;
}
static inline void F_21 ( struct V_20 * V_21 )
{
F_22 ( V_21 ) ;
F_23 ( V_21 ) ;
F_24 ( V_22 , V_21 ) ;
}
static inline void F_25 ( struct V_20 * V_21 )
{
if ( F_26 ( & V_21 -> V_23 ) )
F_21 ( V_21 ) ;
}
void F_27 ( struct V_6 * V_7 )
{
F_28 ( ! V_7 -> V_24 ) ;
F_28 ( F_29 ( & V_7 -> V_25 ) ) ;
F_28 ( V_7 == V_26 ) ;
F_30 ( V_7 ) ;
F_31 ( V_7 ) ;
F_25 ( V_7 -> signal ) ;
if ( ! F_32 ( V_7 ) )
F_16 ( V_7 ) ;
}
void T_2 F_33 ( unsigned long V_27 )
{
#ifndef F_34
#ifndef F_35
#define F_35 L1_CACHE_BYTES
#endif
V_28 =
F_36 ( L_1 , sizeof( struct V_6 ) ,
F_35 , V_29 | V_30 , NULL ) ;
#endif
F_37 () ;
V_31 = V_27 / ( 8 * V_32 / V_33 ) ;
if ( V_31 < 20 )
V_31 = 20 ;
V_34 . signal -> V_35 [ V_36 ] . V_37 = V_31 / 2 ;
V_34 . signal -> V_35 [ V_36 ] . V_38 = V_31 / 2 ;
V_34 . signal -> V_35 [ V_39 ] =
V_34 . signal -> V_35 [ V_36 ] ;
}
static struct V_6 * F_38 ( struct V_6 * V_40 )
{
struct V_6 * V_7 ;
struct V_5 * V_14 ;
unsigned long * V_41 ;
int V_8 = F_39 ( V_40 ) ;
int V_42 ;
F_40 ( V_40 ) ;
V_7 = F_41 ( V_8 ) ;
if ( ! V_7 )
return NULL ;
V_14 = F_6 ( V_7 , V_8 ) ;
if ( ! V_14 ) {
F_20 ( V_7 ) ;
return NULL ;
}
V_42 = F_42 ( V_7 , V_40 ) ;
if ( V_42 )
goto V_43;
V_7 -> V_19 = V_14 ;
V_42 = F_43 ( & V_7 -> V_18 ) ;
if ( V_42 )
goto V_43;
F_44 ( V_7 , V_40 ) ;
F_45 ( V_7 ) ;
F_46 ( V_7 ) ;
V_41 = F_47 ( V_7 ) ;
* V_41 = V_44 ;
#ifdef F_48
V_7 -> V_45 = F_49 () ;
#endif
F_50 ( & V_7 -> V_25 , 2 ) ;
#ifdef F_51
V_7 -> V_46 = 0 ;
#endif
V_7 -> V_47 = NULL ;
F_12 ( V_14 , 1 ) ;
return V_7 ;
V_43:
F_10 ( V_14 ) ;
F_20 ( V_7 ) ;
return NULL ;
}
static int F_52 ( struct V_48 * V_49 , struct V_48 * V_50 )
{
struct V_51 * V_52 , * V_53 , * V_54 , * * V_55 ;
struct V_56 * * V_57 , * V_58 ;
int V_59 ;
unsigned long V_60 ;
struct V_61 * V_62 ;
F_53 ( & V_50 -> V_63 ) ;
F_54 ( V_50 ) ;
F_55 ( & V_49 -> V_63 , V_64 ) ;
V_49 -> V_65 = 0 ;
V_49 -> V_66 = NULL ;
V_49 -> V_67 = NULL ;
V_49 -> V_68 = V_50 -> V_69 ;
V_49 -> V_70 = ~ 0UL ;
V_49 -> V_71 = 0 ;
F_56 ( F_57 ( V_49 ) ) ;
V_49 -> V_72 = V_73 ;
V_57 = & V_49 -> V_72 . V_56 ;
V_58 = NULL ;
V_55 = & V_49 -> V_66 ;
V_59 = F_58 ( V_49 , V_50 ) ;
if ( V_59 )
goto V_43;
V_59 = F_59 ( V_49 , V_50 ) ;
if ( V_59 )
goto V_43;
V_54 = NULL ;
for ( V_52 = V_50 -> V_66 ; V_52 ; V_52 = V_52 -> V_74 ) {
struct V_75 * V_75 ;
if ( V_52 -> V_76 & V_77 ) {
long V_78 = F_60 ( V_52 ) ;
V_49 -> V_79 -= V_78 ;
F_61 ( V_49 , V_52 -> V_76 , V_52 -> V_80 ,
- V_78 ) ;
continue;
}
V_60 = 0 ;
if ( V_52 -> V_76 & V_81 ) {
unsigned int V_82 = ( V_52 -> V_83 - V_52 -> V_84 ) >> V_85 ;
if ( F_62 ( V_82 ) )
goto V_86;
V_60 = V_82 ;
}
V_53 = F_63 ( V_87 , V_10 ) ;
if ( ! V_53 )
goto V_86;
* V_53 = * V_52 ;
F_64 ( & V_53 -> V_88 ) ;
V_62 = F_65 ( F_66 ( V_52 ) ) ;
V_59 = F_67 ( V_62 ) ;
if ( F_68 ( V_62 ) )
goto V_89;
F_69 ( V_53 , V_62 ) ;
V_53 -> V_90 = V_49 ;
if ( F_70 ( V_53 , V_52 ) )
goto V_91;
V_53 -> V_76 &= ~ V_92 ;
V_53 -> V_74 = V_53 -> V_93 = NULL ;
V_75 = V_53 -> V_80 ;
if ( V_75 ) {
struct V_94 * V_94 = V_75 -> V_95 . V_96 -> V_97 ;
struct V_98 * V_99 = V_75 -> V_100 ;
F_71 ( V_75 ) ;
if ( V_53 -> V_76 & V_101 )
F_72 ( & V_94 -> V_102 ) ;
F_73 ( & V_99 -> V_103 ) ;
if ( V_53 -> V_76 & V_104 )
V_99 -> V_105 ++ ;
F_74 ( V_99 ) ;
F_75 ( V_53 , V_52 ) ;
F_76 ( V_99 ) ;
F_77 ( & V_99 -> V_103 ) ;
}
if ( F_78 ( V_53 ) )
F_79 ( V_53 ) ;
* V_55 = V_53 ;
V_55 = & V_53 -> V_74 ;
V_53 -> V_93 = V_54 ;
V_54 = V_53 ;
F_80 ( V_49 , V_53 , V_57 , V_58 ) ;
V_57 = & V_53 -> V_106 . V_107 ;
V_58 = & V_53 -> V_106 ;
V_49 -> V_71 ++ ;
V_59 = F_81 ( V_49 , V_50 , V_52 ) ;
if ( V_53 -> V_108 && V_53 -> V_108 -> V_109 )
V_53 -> V_108 -> V_109 ( V_53 ) ;
if ( V_59 )
goto V_43;
}
F_82 ( V_50 , V_49 ) ;
V_59 = 0 ;
V_43:
F_83 ( & V_49 -> V_63 ) ;
F_84 ( V_50 ) ;
F_83 ( & V_50 -> V_63 ) ;
return V_59 ;
V_91:
F_85 ( V_62 ) ;
V_89:
F_24 ( V_87 , V_53 ) ;
V_86:
V_59 = - V_110 ;
F_86 ( V_60 ) ;
goto V_43;
}
static inline int F_87 ( struct V_48 * V_49 )
{
V_49 -> V_111 = F_88 ( V_49 ) ;
if ( F_89 ( ! V_49 -> V_111 ) )
return - V_110 ;
return 0 ;
}
static inline void F_90 ( struct V_48 * V_49 )
{
F_91 ( V_49 , V_49 -> V_111 ) ;
}
static int T_2 F_92 ( char * V_112 )
{
V_113 =
( F_93 ( V_112 , NULL , 0 ) << V_114 ) &
V_115 ;
return 1 ;
}
static void F_94 ( struct V_48 * V_49 )
{
#ifdef F_95
F_96 ( & V_49 -> V_116 ) ;
F_97 ( & V_49 -> V_117 ) ;
#endif
}
static struct V_48 * F_98 ( struct V_48 * V_49 , struct V_6 * V_118 )
{
F_50 ( & V_49 -> V_119 , 1 ) ;
F_50 ( & V_49 -> V_120 , 1 ) ;
F_99 ( & V_49 -> V_63 ) ;
F_64 ( & V_49 -> V_121 ) ;
V_49 -> V_122 = ( V_26 -> V_49 ) ?
( V_26 -> V_49 -> V_122 & V_123 ) : V_113 ;
V_49 -> V_124 = NULL ;
V_49 -> V_125 = 0 ;
memset ( & V_49 -> V_126 , 0 , sizeof( V_49 -> V_126 ) ) ;
F_96 ( & V_49 -> V_127 ) ;
V_49 -> V_68 = V_128 ;
V_49 -> V_70 = ~ 0UL ;
F_94 ( V_49 ) ;
F_100 ( V_49 , V_118 ) ;
F_50 ( & V_49 -> V_129 , 0 ) ;
if ( F_101 ( ! F_87 ( V_49 ) ) ) {
V_49 -> V_130 = 0 ;
F_102 ( V_49 ) ;
return V_49 ;
}
F_103 ( V_49 ) ;
return NULL ;
}
struct V_48 * F_104 ( void )
{
struct V_48 * V_49 ;
V_49 = F_105 () ;
if ( ! V_49 )
return NULL ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_106 ( V_49 ) ;
return F_98 ( V_49 , V_26 ) ;
}
void F_107 ( struct V_48 * V_49 )
{
F_108 ( V_49 == & V_131 ) ;
F_90 ( V_49 ) ;
F_109 ( V_49 ) ;
F_110 ( V_49 ) ;
#ifdef F_111
F_112 ( V_49 -> V_132 ) ;
#endif
F_103 ( V_49 ) ;
}
void F_113 ( struct V_48 * V_49 )
{
F_114 () ;
if ( F_26 ( & V_49 -> V_119 ) ) {
F_115 ( V_49 ) ;
F_116 ( V_49 ) ;
F_117 ( V_49 ) ;
F_118 ( V_49 ) ;
F_119 ( V_49 , NULL ) ;
if ( ! F_120 ( & V_49 -> V_121 ) ) {
F_121 ( & V_133 ) ;
F_122 ( & V_49 -> V_121 ) ;
F_123 ( & V_133 ) ;
}
F_124 ( V_49 ) ;
if ( V_49 -> V_134 )
F_125 ( V_49 -> V_134 -> V_135 ) ;
F_126 ( V_49 ) ;
}
}
void F_127 ( struct V_48 * V_49 )
{
V_49 -> V_136 ++ ;
}
void F_128 ( struct V_48 * V_49 )
{
V_49 -> V_136 -- ;
if ( ( V_49 -> V_136 == 0 ) && V_49 -> V_137 ) {
F_129 ( V_49 -> V_137 ) ;
V_49 -> V_137 = NULL ;
}
}
void F_119 ( struct V_48 * V_49 , struct V_75 * V_138 )
{
if ( V_138 )
F_71 ( V_138 ) ;
if ( V_49 -> V_137 )
F_129 ( V_49 -> V_137 ) ;
V_49 -> V_137 = V_138 ;
V_49 -> V_136 = 0 ;
}
struct V_75 * F_130 ( struct V_48 * V_49 )
{
struct V_75 * V_137 ;
F_131 ( & V_49 -> V_63 ) ;
V_137 = V_49 -> V_137 ;
if ( V_137 )
F_71 ( V_137 ) ;
F_132 ( & V_49 -> V_63 ) ;
return V_137 ;
}
static void F_133 ( struct V_48 * V_50 , struct V_48 * V_139 )
{
V_139 -> V_137 = F_130 ( V_50 ) ;
}
struct V_48 * F_134 ( struct V_6 * V_140 )
{
struct V_48 * V_49 ;
F_135 ( V_140 ) ;
V_49 = V_140 -> V_49 ;
if ( V_49 ) {
if ( V_140 -> V_122 & V_141 )
V_49 = NULL ;
else
F_136 ( & V_49 -> V_119 ) ;
}
F_137 ( V_140 ) ;
return V_49 ;
}
void F_138 ( struct V_6 * V_7 , struct V_48 * V_49 )
{
struct V_142 * V_143 = V_7 -> V_143 ;
#ifdef F_139
if ( F_89 ( V_7 -> V_144 ) ) {
F_140 ( V_7 ) ;
V_7 -> V_144 = NULL ;
}
#ifdef F_141
if ( F_89 ( V_7 -> V_145 ) ) {
F_142 ( V_7 ) ;
V_7 -> V_145 = NULL ;
}
#endif
if ( F_89 ( ! F_120 ( & V_7 -> V_146 ) ) )
F_143 ( V_7 ) ;
#endif
F_144 ( V_7 , V_49 ) ;
if ( V_143 ) {
V_7 -> V_143 = NULL ;
F_145 ( V_143 ) ;
}
if ( V_7 -> V_147 ) {
if ( ! ( V_7 -> V_122 & V_148 ) &&
F_29 ( & V_49 -> V_119 ) > 1 ) {
F_146 ( 0 , V_7 -> V_147 ) ;
F_147 ( V_7 -> V_147 , V_149 ,
1 , NULL , NULL , 0 ) ;
}
V_7 -> V_147 = NULL ;
}
}
struct V_48 * F_148 ( struct V_6 * V_7 )
{
struct V_48 * V_49 , * V_50 = V_26 -> V_49 ;
int V_42 ;
if ( ! V_50 )
return NULL ;
V_49 = F_105 () ;
if ( ! V_49 )
goto V_86;
memcpy ( V_49 , V_50 , sizeof( * V_49 ) ) ;
F_106 ( V_49 ) ;
V_49 -> V_150 = 0 ;
V_49 -> V_151 = 0 ;
#ifdef F_111
V_49 -> V_132 = NULL ;
#endif
if ( ! F_98 ( V_49 , V_7 ) )
goto V_86;
if ( F_149 ( V_7 , V_49 ) )
goto V_152;
F_133 ( V_50 , V_49 ) ;
V_42 = F_52 ( V_49 , V_50 ) ;
if ( V_42 )
goto V_153;
V_49 -> V_154 = F_150 ( V_49 ) ;
V_49 -> V_155 = V_49 -> V_79 ;
if ( V_49 -> V_134 && ! F_151 ( V_49 -> V_134 -> V_135 ) )
goto V_153;
return V_49 ;
V_153:
V_49 -> V_134 = NULL ;
F_113 ( V_49 ) ;
V_86:
return NULL ;
V_152:
F_90 ( V_49 ) ;
F_103 ( V_49 ) ;
return NULL ;
}
static int F_152 ( unsigned long V_156 , struct V_6 * V_7 )
{
struct V_48 * V_49 , * V_50 ;
int V_59 ;
V_7 -> V_157 = V_7 -> V_158 = 0 ;
V_7 -> V_159 = V_7 -> V_160 = 0 ;
#ifdef F_153
V_7 -> V_161 = V_7 -> V_159 + V_7 -> V_160 ;
#endif
V_7 -> V_49 = NULL ;
V_7 -> V_162 = NULL ;
V_50 = V_26 -> V_49 ;
if ( ! V_50 )
return 0 ;
if ( V_156 & V_163 ) {
F_136 ( & V_50 -> V_119 ) ;
V_49 = V_50 ;
goto V_164;
}
V_59 = - V_110 ;
V_49 = F_148 ( V_7 ) ;
if ( ! V_49 )
goto V_86;
V_164:
V_49 -> V_150 = 0 ;
V_49 -> V_151 = 0 ;
if ( V_7 -> signal -> V_165 == V_166 )
F_136 ( & V_49 -> V_129 ) ;
V_7 -> V_49 = V_49 ;
V_7 -> V_162 = V_49 ;
return 0 ;
V_86:
return V_59 ;
}
static int F_154 ( unsigned long V_156 , struct V_6 * V_7 )
{
struct V_167 * V_168 = V_26 -> V_168 ;
if ( V_156 & V_169 ) {
F_121 ( & V_168 -> V_170 ) ;
if ( V_168 -> V_171 ) {
F_123 ( & V_168 -> V_170 ) ;
return - V_172 ;
}
V_168 -> V_173 ++ ;
F_123 ( & V_168 -> V_170 ) ;
return 0 ;
}
V_7 -> V_168 = F_155 ( V_168 ) ;
if ( ! V_7 -> V_168 )
return - V_110 ;
return 0 ;
}
static int F_156 ( unsigned long V_156 , struct V_6 * V_7 )
{
struct V_174 * V_175 , * V_176 ;
int error = 0 ;
V_175 = V_26 -> V_177 ;
if ( ! V_175 )
goto V_43;
if ( V_156 & V_178 ) {
F_136 ( & V_175 -> V_179 ) ;
goto V_43;
}
V_176 = F_157 ( V_175 , & error ) ;
if ( ! V_176 )
goto V_43;
V_7 -> V_177 = V_176 ;
error = 0 ;
V_43:
return error ;
}
static int F_158 ( unsigned long V_156 , struct V_6 * V_7 )
{
#ifdef F_159
struct V_180 * V_181 = V_26 -> V_180 ;
if ( ! V_181 )
return 0 ;
if ( V_156 & V_182 ) {
V_7 -> V_180 = F_160 ( V_181 ) ;
if ( F_89 ( ! V_7 -> V_180 ) )
return - V_110 ;
} else if ( F_161 ( V_181 -> V_183 ) ) {
V_7 -> V_180 = F_162 ( V_10 , - 1 ) ;
if ( F_89 ( ! V_7 -> V_180 ) )
return - V_110 ;
V_7 -> V_180 -> V_183 = V_181 -> V_183 ;
}
#endif
return 0 ;
}
static int F_163 ( unsigned long V_156 , struct V_6 * V_7 )
{
struct V_184 * V_21 ;
if ( V_156 & V_185 ) {
F_136 ( & V_26 -> V_186 -> V_179 ) ;
return 0 ;
}
V_21 = F_63 ( V_187 , V_10 ) ;
F_164 ( V_7 -> V_186 , V_21 ) ;
if ( ! V_21 )
return - V_110 ;
F_50 ( & V_21 -> V_179 , 1 ) ;
memcpy ( V_21 -> V_188 , V_26 -> V_186 -> V_188 , sizeof( V_21 -> V_188 ) ) ;
return 0 ;
}
void F_165 ( struct V_184 * V_186 )
{
if ( F_26 ( & V_186 -> V_179 ) )
F_24 ( V_187 , V_186 ) ;
}
static void F_166 ( struct V_20 * V_21 )
{
unsigned long V_189 ;
F_167 ( V_21 ) ;
V_189 = F_168 ( V_21 -> V_35 [ V_190 ] . V_37 ) ;
if ( V_189 != V_191 ) {
V_21 -> V_192 . V_193 = F_169 ( V_189 ) ;
V_21 -> V_194 . V_195 = 1 ;
}
F_64 ( & V_21 -> V_196 [ 0 ] ) ;
F_64 ( & V_21 -> V_196 [ 1 ] ) ;
F_64 ( & V_21 -> V_196 [ 2 ] ) ;
}
static int F_170 ( unsigned long V_156 , struct V_6 * V_7 )
{
struct V_20 * V_21 ;
if ( V_156 & V_197 )
return 0 ;
V_21 = F_171 ( V_22 , V_10 ) ;
V_7 -> signal = V_21 ;
if ( ! V_21 )
return - V_110 ;
V_21 -> V_198 = 1 ;
F_50 ( & V_21 -> V_199 , 1 ) ;
F_50 ( & V_21 -> V_23 , 1 ) ;
F_172 ( & V_21 -> V_200 ) ;
if ( V_156 & V_201 )
V_21 -> V_122 |= V_202 ;
V_21 -> V_203 = V_7 ;
F_173 ( & V_21 -> V_204 ) ;
F_64 ( & V_21 -> V_205 ) ;
F_174 ( & V_21 -> V_206 , V_207 , V_208 ) ;
V_21 -> V_206 . V_209 = V_210 ;
F_135 ( V_26 -> V_211 ) ;
memcpy ( V_21 -> V_35 , V_26 -> signal -> V_35 , sizeof V_21 -> V_35 ) ;
F_137 ( V_26 -> V_211 ) ;
F_166 ( V_21 ) ;
F_175 ( V_21 ) ;
F_176 ( V_21 ) ;
#ifdef F_177
F_99 ( & V_21 -> V_212 ) ;
#endif
V_21 -> V_213 = V_26 -> signal -> V_213 ;
V_21 -> V_165 = V_26 -> signal -> V_165 ;
V_21 -> V_214 = V_26 -> signal -> V_214 ;
F_178 ( & V_21 -> V_215 ) ;
return 0 ;
}
static void F_179 ( unsigned long V_156 , struct V_6 * V_118 )
{
unsigned long V_216 = V_118 -> V_122 ;
V_216 &= ~ ( V_217 | V_218 ) ;
V_216 |= V_219 ;
V_216 |= V_220 ;
V_118 -> V_122 = V_216 ;
F_180 ( V_118 ) ;
}
static void F_181 ( struct V_6 * V_118 )
{
F_182 ( & V_118 -> V_221 ) ;
#ifdef F_183
F_184 ( & V_118 -> V_222 ) ;
V_118 -> V_223 = NULL ;
#endif
}
void F_100 ( struct V_48 * V_49 , struct V_6 * V_118 )
{
V_49 -> V_224 = V_118 ;
}
static void F_185 ( struct V_6 * V_7 )
{
V_7 -> V_192 . V_193 = V_225 ;
V_7 -> V_192 . V_226 = V_225 ;
V_7 -> V_192 . V_227 = 0 ;
F_64 ( & V_7 -> V_196 [ 0 ] ) ;
F_64 ( & V_7 -> V_196 [ 1 ] ) ;
F_64 ( & V_7 -> V_196 [ 2 ] ) ;
}
static struct V_6 * F_186 ( unsigned long V_156 ,
unsigned long V_228 ,
struct V_229 * V_230 ,
unsigned long V_231 ,
int T_3 * V_232 ,
struct V_233 * V_233 ,
int V_234 )
{
int V_59 ;
struct V_6 * V_118 ;
int V_235 = 0 ;
if ( ( V_156 & ( V_236 | V_169 ) ) == ( V_236 | V_169 ) )
return F_187 ( - V_237 ) ;
if ( ( V_156 & V_197 ) && ! ( V_156 & V_185 ) )
return F_187 ( - V_237 ) ;
if ( ( V_156 & V_185 ) && ! ( V_156 & V_163 ) )
return F_187 ( - V_237 ) ;
if ( ( V_156 & V_238 ) &&
V_26 -> signal -> V_122 & V_202 )
return F_187 ( - V_237 ) ;
V_59 = F_188 ( V_156 ) ;
if ( V_59 )
goto V_239;
V_59 = - V_110 ;
V_118 = F_38 ( V_26 ) ;
if ( ! V_118 )
goto V_239;
F_189 ( V_118 ) ;
F_181 ( V_118 ) ;
#ifdef F_190
F_191 ( ! V_118 -> V_240 ) ;
F_191 ( ! V_118 -> V_241 ) ;
#endif
V_59 = - V_172 ;
if ( F_29 ( & V_118 -> V_242 -> V_243 -> V_244 ) >=
F_192 ( V_118 , V_36 ) ) {
if ( ! F_193 ( V_245 ) && ! F_193 ( V_246 ) &&
V_118 -> V_242 -> V_243 != V_247 )
goto V_248;
}
V_26 -> V_122 &= ~ V_249 ;
V_59 = F_194 ( V_118 , V_156 ) ;
if ( V_59 < 0 )
goto V_248;
V_59 = - V_172 ;
if ( V_198 >= V_31 )
goto V_250;
if ( ! F_151 ( F_195 ( V_118 ) -> V_251 -> V_135 ) )
goto V_250;
V_118 -> V_252 = 0 ;
F_196 ( V_118 ) ;
F_179 ( V_156 , V_118 ) ;
F_64 ( & V_118 -> V_253 ) ;
F_64 ( & V_118 -> V_254 ) ;
F_197 ( V_118 ) ;
V_118 -> V_143 = NULL ;
F_96 ( & V_118 -> V_255 ) ;
F_173 ( & V_118 -> V_256 ) ;
V_118 -> V_257 = V_225 ;
V_118 -> V_258 = V_225 ;
V_118 -> V_259 = V_225 ;
V_118 -> V_260 = V_225 ;
V_118 -> V_261 = V_225 ;
#ifndef F_198
V_118 -> V_262 = V_225 ;
V_118 -> V_263 = V_225 ;
#endif
#if F_199 ( V_264 )
memset ( & V_118 -> V_126 , 0 , sizeof( V_118 -> V_126 ) ) ;
#endif
V_118 -> V_265 = V_26 -> V_266 ;
F_200 ( & V_118 -> V_267 ) ;
F_201 ( V_118 ) ;
F_185 ( V_118 ) ;
F_202 ( & V_118 -> V_268 ) ;
V_118 -> V_269 = V_118 -> V_268 ;
F_203 ( & V_118 -> V_269 ) ;
V_118 -> V_180 = NULL ;
V_118 -> V_270 = NULL ;
if ( V_156 & V_197 )
F_204 ( V_26 ) ;
F_205 ( V_118 ) ;
#ifdef F_206
V_118 -> V_61 = F_65 ( V_118 -> V_61 ) ;
if ( F_68 ( V_118 -> V_61 ) ) {
V_59 = F_67 ( V_118 -> V_61 ) ;
V_118 -> V_61 = NULL ;
goto V_271;
}
F_207 ( V_118 ) ;
#endif
#ifdef F_208
V_118 -> V_272 = V_273 ;
V_118 -> V_274 = V_273 ;
#endif
#ifdef F_209
V_118 -> V_275 = 0 ;
#ifdef F_210
V_118 -> V_240 = 1 ;
#else
V_118 -> V_240 = 0 ;
#endif
V_118 -> V_276 = 0 ;
V_118 -> V_277 = 0 ;
V_118 -> V_278 = V_279 ;
V_118 -> V_280 = 0 ;
V_118 -> V_241 = 1 ;
V_118 -> V_281 = V_279 ;
V_118 -> V_282 = 0 ;
V_118 -> V_283 = 0 ;
V_118 -> V_284 = 0 ;
V_118 -> V_285 = 0 ;
V_118 -> V_286 = 0 ;
#endif
#ifdef F_211
V_118 -> V_287 = 0 ;
V_118 -> V_288 = 0 ;
V_118 -> V_289 = 0 ;
#endif
#ifdef F_212
V_118 -> V_290 = NULL ;
#endif
#ifdef F_213
V_118 -> V_291 . V_292 = 0 ;
V_118 -> V_291 . V_293 = NULL ;
#endif
F_214 ( V_118 ) ;
V_59 = F_215 ( V_118 ) ;
if ( V_59 )
goto V_294;
V_59 = F_216 ( V_118 ) ;
if ( V_59 )
goto V_294;
V_59 = F_217 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_295;
V_59 = F_156 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_296;
V_59 = F_154 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_297;
V_59 = F_163 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_298;
V_59 = F_170 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_299;
V_59 = F_152 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_300;
V_59 = F_218 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_301;
V_59 = F_158 ( V_156 , V_118 ) ;
if ( V_59 )
goto V_302;
V_59 = F_219 ( V_156 , V_228 , V_231 , V_118 , V_230 ) ;
if ( V_59 )
goto V_303;
if ( V_233 != & V_304 ) {
V_59 = - V_110 ;
V_233 = F_220 ( V_118 -> V_305 -> V_306 ) ;
if ( ! V_233 )
goto V_303;
}
V_118 -> V_233 = F_221 ( V_233 ) ;
V_118 -> V_307 = V_118 -> V_233 ;
if ( V_156 & V_197 )
V_118 -> V_307 = V_26 -> V_307 ;
V_118 -> V_308 = ( V_156 & V_309 ) ? V_232 : NULL ;
V_118 -> V_147 = ( V_156 & V_310 ) ? V_232 : NULL ;
#ifdef F_159
V_118 -> V_311 = NULL ;
#endif
#ifdef F_139
V_118 -> V_144 = NULL ;
#ifdef F_141
V_118 -> V_145 = NULL ;
#endif
F_64 ( & V_118 -> V_146 ) ;
V_118 -> V_312 = NULL ;
#endif
if ( ( V_156 & ( V_163 | V_313 ) ) == V_163 )
V_118 -> V_314 = V_118 -> V_315 = 0 ;
F_222 ( V_118 ) ;
F_223 ( V_118 , V_316 ) ;
#ifdef F_224
F_223 ( V_118 , F_224 ) ;
#endif
F_225 ( V_118 ) ;
V_118 -> V_317 = ( V_156 & V_197 ) ? - 1 : ( V_156 & V_318 ) ;
V_118 -> V_319 = 0 ;
V_118 -> V_24 = 0 ;
V_118 -> V_211 = V_118 ;
F_64 ( & V_118 -> V_320 ) ;
F_226 ( V_118 ) ;
V_235 = 1 ;
F_227 ( & V_1 ) ;
if ( V_156 & ( V_238 | V_197 ) ) {
V_118 -> V_321 = V_26 -> V_321 ;
V_118 -> V_322 = V_26 -> V_322 ;
} else {
V_118 -> V_321 = V_26 ;
V_118 -> V_322 = V_26 -> V_323 ;
}
F_121 ( & V_26 -> V_186 -> V_324 ) ;
F_228 () ;
if ( F_229 ( V_26 ) ) {
F_123 ( & V_26 -> V_186 -> V_324 ) ;
F_230 ( & V_1 ) ;
V_59 = - V_325 ;
goto V_326;
}
if ( V_156 & V_197 ) {
V_26 -> signal -> V_198 ++ ;
F_136 ( & V_26 -> signal -> V_199 ) ;
F_136 ( & V_26 -> signal -> V_23 ) ;
V_118 -> V_211 = V_26 -> V_211 ;
F_231 ( & V_118 -> V_320 , & V_118 -> V_211 -> V_320 ) ;
}
if ( F_101 ( V_118 -> V_233 ) ) {
F_232 ( V_118 , ( V_156 & V_327 ) || V_234 ) ;
if ( F_233 ( V_118 ) ) {
if ( F_234 ( V_233 ) )
V_118 -> V_305 -> V_306 -> V_328 = V_118 ;
V_118 -> signal -> V_329 = V_233 ;
V_118 -> signal -> V_330 = F_235 ( V_26 -> signal -> V_330 ) ;
F_236 ( V_118 , V_331 , F_237 ( V_26 ) ) ;
F_236 ( V_118 , V_332 , F_238 ( V_26 ) ) ;
F_239 ( & V_118 -> V_254 , & V_118 -> V_321 -> V_253 ) ;
F_231 ( & V_118 -> V_333 , & V_34 . V_333 ) ;
F_240 ( V_4 ) ;
}
F_236 ( V_118 , V_334 , V_233 ) ;
V_198 ++ ;
}
V_335 ++ ;
F_123 ( & V_26 -> V_186 -> V_324 ) ;
F_230 ( & V_1 ) ;
F_241 ( V_118 ) ;
F_242 ( V_118 ) ;
if ( V_156 & V_197 )
F_243 ( V_26 ) ;
F_244 ( V_118 ) ;
return V_118 ;
V_326:
if ( V_233 != & V_304 )
F_245 ( V_233 ) ;
V_303:
if ( V_118 -> V_180 )
F_246 ( V_118 ) ;
V_302:
F_247 ( V_118 ) ;
V_301:
if ( V_118 -> V_49 ) {
F_135 ( V_118 ) ;
if ( V_118 -> signal -> V_165 == V_166 )
F_72 ( & V_118 -> V_49 -> V_129 ) ;
F_137 ( V_118 ) ;
F_113 ( V_118 -> V_49 ) ;
}
V_300:
if ( ! ( V_156 & V_197 ) )
F_21 ( V_118 -> signal ) ;
V_299:
F_165 ( V_118 -> V_186 ) ;
V_298:
F_248 ( V_118 ) ;
V_297:
F_249 ( V_118 ) ;
V_296:
F_250 ( V_118 ) ;
V_295:
F_251 ( V_118 ) ;
V_294:
F_252 ( V_118 ) ;
#ifdef F_206
F_85 ( V_118 -> V_61 ) ;
V_271:
#endif
if ( V_156 & V_197 )
F_243 ( V_26 ) ;
F_253 ( V_118 , V_235 ) ;
F_31 ( V_118 ) ;
F_125 ( F_195 ( V_118 ) -> V_251 -> V_135 ) ;
V_250:
F_72 ( & V_118 -> V_336 -> V_243 -> V_244 ) ;
F_30 ( V_118 ) ;
V_248:
F_16 ( V_118 ) ;
V_239:
return F_187 ( V_59 ) ;
}
static inline void F_254 ( struct V_337 * V_338 )
{
enum V_339 type ;
for ( type = V_334 ; type < V_340 ; ++ type ) {
F_255 ( & V_338 [ type ] . V_8 ) ;
V_338 [ type ] . V_233 = & V_304 ;
}
}
struct V_6 * T_4 F_256 ( int V_2 )
{
struct V_6 * V_140 ;
struct V_229 V_230 ;
V_140 = F_186 ( V_163 , 0 , F_257 ( & V_230 ) , 0 , NULL ,
& V_304 , 0 ) ;
if ( ! F_68 ( V_140 ) ) {
F_254 ( V_140 -> V_341 ) ;
F_258 ( V_140 , V_2 ) ;
}
return V_140 ;
}
long F_259 ( unsigned long V_156 ,
unsigned long V_228 ,
struct V_229 * V_230 ,
unsigned long V_231 ,
int T_3 * V_342 ,
int T_3 * V_232 )
{
struct V_6 * V_118 ;
int V_234 = 0 ;
long V_343 ;
if ( V_156 & V_344 ) {
if ( V_156 & V_197 )
return - V_237 ;
if ( ! F_193 ( V_245 ) || ! F_193 ( V_345 ) ||
! F_193 ( V_346 ) )
return - V_347 ;
}
if ( F_101 ( F_260 ( V_230 ) ) && ! ( V_156 & V_348 ) ) {
if ( V_156 & V_313 )
V_234 = V_349 ;
else if ( ( V_156 & V_318 ) != V_350 )
V_234 = V_351 ;
else
V_234 = V_352 ;
if ( F_101 ( ! F_261 ( V_26 , V_234 ) ) )
V_234 = 0 ;
}
V_118 = F_186 ( V_156 , V_228 , V_230 , V_231 ,
V_232 , NULL , V_234 ) ;
if ( ! F_68 ( V_118 ) ) {
struct V_142 V_353 ;
F_262 ( V_26 , V_118 ) ;
V_343 = F_263 ( V_118 ) ;
if ( V_156 & V_354 )
F_146 ( V_343 , V_342 ) ;
if ( V_156 & V_313 ) {
V_118 -> V_143 = & V_353 ;
F_264 ( & V_353 ) ;
}
F_265 ( V_118 ) ;
V_118 -> V_122 &= ~ V_220 ;
F_266 ( V_118 ) ;
if ( F_89 ( V_234 ) )
F_267 ( V_234 , V_343 ) ;
if ( V_156 & V_313 ) {
F_268 () ;
F_269 ( & V_353 ) ;
F_270 () ;
F_267 ( V_355 , V_343 ) ;
}
} else {
V_343 = F_67 ( V_118 ) ;
}
return V_343 ;
}
static void F_271 ( void * V_356 )
{
struct V_184 * V_186 = V_356 ;
F_96 ( & V_186 -> V_324 ) ;
F_172 ( & V_186 -> V_357 ) ;
}
void T_2 F_272 ( void )
{
V_187 = F_36 ( L_2 ,
sizeof( struct V_184 ) , 0 ,
V_358 | V_29 | V_359 |
V_30 , F_271 ) ;
V_22 = F_36 ( L_3 ,
sizeof( struct V_20 ) , 0 ,
V_358 | V_29 | V_30 , NULL ) ;
V_360 = F_36 ( L_4 ,
sizeof( struct V_174 ) , 0 ,
V_358 | V_29 | V_30 , NULL ) ;
V_361 = F_36 ( L_5 ,
sizeof( struct V_167 ) , 0 ,
V_358 | V_29 | V_30 , NULL ) ;
V_362 = F_36 ( L_6 ,
sizeof( struct V_48 ) , V_363 ,
V_358 | V_29 | V_30 , NULL ) ;
V_87 = F_273 ( V_51 , V_29 ) ;
F_274 () ;
F_275 () ;
}
static int F_276 ( unsigned long V_364 )
{
if ( V_364 & ~ ( V_197 | V_169 | V_236 | V_185 |
V_163 | V_178 | V_365 |
V_366 | V_367 | V_368 ) )
return - V_237 ;
if ( V_364 & ( V_197 | V_185 | V_163 ) ) {
if ( F_29 ( & V_26 -> V_49 -> V_119 ) > 1 )
return - V_237 ;
}
return 0 ;
}
static int F_277 ( unsigned long V_364 , struct V_167 * * V_369 )
{
struct V_167 * V_168 = V_26 -> V_168 ;
if ( ! ( V_364 & V_169 ) || ! V_168 )
return 0 ;
if ( V_168 -> V_173 == 1 )
return 0 ;
* V_369 = F_155 ( V_168 ) ;
if ( ! * V_369 )
return - V_110 ;
return 0 ;
}
static int F_278 ( unsigned long V_364 , struct V_174 * * V_370 )
{
struct V_174 * V_371 = V_26 -> V_177 ;
int error = 0 ;
if ( ( V_364 & V_178 ) &&
( V_371 && F_29 ( & V_371 -> V_179 ) > 1 ) ) {
* V_370 = F_157 ( V_371 , & error ) ;
if ( ! * V_370 )
return error ;
}
return 0 ;
}
int F_279 ( struct V_174 * * V_372 )
{
struct V_6 * V_140 = V_26 ;
struct V_174 * V_373 = NULL ;
int error ;
error = F_278 ( V_178 , & V_373 ) ;
if ( error || ! V_373 ) {
* V_372 = NULL ;
return error ;
}
* V_372 = V_140 -> V_177 ;
F_135 ( V_140 ) ;
V_140 -> V_177 = V_373 ;
F_137 ( V_140 ) ;
return 0 ;
}
