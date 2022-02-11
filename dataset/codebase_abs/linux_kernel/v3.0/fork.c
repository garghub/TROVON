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
if( V_31 < 20 )
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
F_50 ( & V_7 -> V_46 , 0 ) ;
#ifdef F_51
V_7 -> V_47 = 0 ;
#endif
V_7 -> V_48 = NULL ;
F_12 ( V_14 , 1 ) ;
return V_7 ;
V_43:
F_10 ( V_14 ) ;
F_20 ( V_7 ) ;
return NULL ;
}
static int F_52 ( struct V_49 * V_50 , struct V_49 * V_51 )
{
struct V_52 * V_53 , * V_54 , * V_55 , * * V_56 ;
struct V_57 * * V_58 , * V_59 ;
int V_60 ;
unsigned long V_61 ;
struct V_62 * V_63 ;
F_53 ( & V_51 -> V_64 ) ;
F_54 ( V_51 ) ;
F_55 ( & V_50 -> V_64 , V_65 ) ;
V_50 -> V_66 = 0 ;
V_50 -> V_67 = NULL ;
V_50 -> V_68 = NULL ;
V_50 -> V_69 = V_51 -> V_70 ;
V_50 -> V_71 = ~ 0UL ;
V_50 -> V_72 = 0 ;
F_56 ( F_57 ( V_50 ) ) ;
V_50 -> V_73 = V_74 ;
V_58 = & V_50 -> V_73 . V_57 ;
V_59 = NULL ;
V_56 = & V_50 -> V_67 ;
V_60 = F_58 ( V_50 , V_51 ) ;
if ( V_60 )
goto V_43;
V_60 = F_59 ( V_50 , V_51 ) ;
if ( V_60 )
goto V_43;
V_55 = NULL ;
for ( V_53 = V_51 -> V_67 ; V_53 ; V_53 = V_53 -> V_75 ) {
struct V_76 * V_76 ;
if ( V_53 -> V_77 & V_78 ) {
long V_79 = F_60 ( V_53 ) ;
V_50 -> V_80 -= V_79 ;
F_61 ( V_50 , V_53 -> V_77 , V_53 -> V_81 ,
- V_79 ) ;
continue;
}
V_61 = 0 ;
if ( V_53 -> V_77 & V_82 ) {
unsigned int V_83 = ( V_53 -> V_84 - V_53 -> V_85 ) >> V_86 ;
if ( F_62 ( V_83 ) )
goto V_87;
V_61 = V_83 ;
}
V_54 = F_63 ( V_88 , V_10 ) ;
if ( ! V_54 )
goto V_87;
* V_54 = * V_53 ;
F_64 ( & V_54 -> V_89 ) ;
V_63 = F_65 ( F_66 ( V_53 ) ) ;
V_60 = F_67 ( V_63 ) ;
if ( F_68 ( V_63 ) )
goto V_90;
F_69 ( V_54 , V_63 ) ;
V_54 -> V_91 = V_50 ;
if ( F_70 ( V_54 , V_53 ) )
goto V_92;
V_54 -> V_77 &= ~ V_93 ;
V_54 -> V_75 = V_54 -> V_94 = NULL ;
V_76 = V_54 -> V_81 ;
if ( V_76 ) {
struct V_95 * V_95 = V_76 -> V_96 . V_97 -> V_98 ;
struct V_99 * V_100 = V_76 -> V_101 ;
F_71 ( V_76 ) ;
if ( V_54 -> V_77 & V_102 )
F_72 ( & V_95 -> V_103 ) ;
F_73 ( & V_100 -> V_104 ) ;
if ( V_54 -> V_77 & V_105 )
V_100 -> V_106 ++ ;
F_74 ( V_100 ) ;
F_75 ( V_54 , V_53 ) ;
F_76 ( V_100 ) ;
F_77 ( & V_100 -> V_104 ) ;
}
if ( F_78 ( V_54 ) )
F_79 ( V_54 ) ;
* V_56 = V_54 ;
V_56 = & V_54 -> V_75 ;
V_54 -> V_94 = V_55 ;
V_55 = V_54 ;
F_80 ( V_50 , V_54 , V_58 , V_59 ) ;
V_58 = & V_54 -> V_107 . V_108 ;
V_59 = & V_54 -> V_107 ;
V_50 -> V_72 ++ ;
V_60 = F_81 ( V_50 , V_51 , V_53 ) ;
if ( V_54 -> V_109 && V_54 -> V_109 -> V_110 )
V_54 -> V_109 -> V_110 ( V_54 ) ;
if ( V_60 )
goto V_43;
}
F_82 ( V_51 , V_50 ) ;
V_60 = 0 ;
V_43:
F_83 ( & V_50 -> V_64 ) ;
F_84 ( V_51 ) ;
F_83 ( & V_51 -> V_64 ) ;
return V_60 ;
V_92:
F_85 ( V_63 ) ;
V_90:
F_24 ( V_88 , V_54 ) ;
V_87:
V_60 = - V_111 ;
F_86 ( V_61 ) ;
goto V_43;
}
static inline int F_87 ( struct V_49 * V_50 )
{
V_50 -> V_112 = F_88 ( V_50 ) ;
if ( F_89 ( ! V_50 -> V_112 ) )
return - V_111 ;
return 0 ;
}
static inline void F_90 ( struct V_49 * V_50 )
{
F_91 ( V_50 , V_50 -> V_112 ) ;
}
static int T_2 F_92 ( char * V_113 )
{
V_114 =
( F_93 ( V_113 , NULL , 0 ) << V_115 ) &
V_116 ;
return 1 ;
}
static void F_94 ( struct V_49 * V_50 )
{
#ifdef F_95
F_96 ( & V_50 -> V_117 ) ;
F_97 ( & V_50 -> V_118 ) ;
#endif
}
static struct V_49 * F_98 ( struct V_49 * V_50 , struct V_6 * V_119 )
{
F_50 ( & V_50 -> V_120 , 1 ) ;
F_50 ( & V_50 -> V_121 , 1 ) ;
F_99 ( & V_50 -> V_64 ) ;
F_64 ( & V_50 -> V_122 ) ;
V_50 -> V_123 = ( V_26 -> V_50 ) ?
( V_26 -> V_50 -> V_123 & V_124 ) : V_114 ;
V_50 -> V_125 = NULL ;
V_50 -> V_126 = 0 ;
memset ( & V_50 -> V_127 , 0 , sizeof( V_50 -> V_127 ) ) ;
F_96 ( & V_50 -> V_128 ) ;
V_50 -> V_69 = V_129 ;
V_50 -> V_71 = ~ 0UL ;
F_94 ( V_50 ) ;
F_100 ( V_50 , V_119 ) ;
F_50 ( & V_50 -> V_130 , 0 ) ;
if ( F_101 ( ! F_87 ( V_50 ) ) ) {
V_50 -> V_131 = 0 ;
F_102 ( V_50 ) ;
return V_50 ;
}
F_103 ( V_50 ) ;
return NULL ;
}
struct V_49 * F_104 ( void )
{
struct V_49 * V_50 ;
V_50 = F_105 () ;
if ( ! V_50 )
return NULL ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_106 ( V_50 ) ;
return F_98 ( V_50 , V_26 ) ;
}
void F_107 ( struct V_49 * V_50 )
{
F_108 ( V_50 == & V_132 ) ;
F_90 ( V_50 ) ;
F_109 ( V_50 ) ;
F_110 ( V_50 ) ;
#ifdef F_111
F_112 ( V_50 -> V_133 ) ;
#endif
F_103 ( V_50 ) ;
}
void F_113 ( struct V_49 * V_50 )
{
F_114 () ;
if ( F_26 ( & V_50 -> V_120 ) ) {
F_115 ( V_50 ) ;
F_116 ( V_50 ) ;
F_117 ( V_50 ) ;
F_118 ( V_50 ) ;
F_119 ( V_50 , NULL ) ;
if ( ! F_120 ( & V_50 -> V_122 ) ) {
F_121 ( & V_134 ) ;
F_122 ( & V_50 -> V_122 ) ;
F_123 ( & V_134 ) ;
}
F_124 ( V_50 ) ;
if ( V_50 -> V_135 )
F_125 ( V_50 -> V_135 -> V_136 ) ;
F_126 ( V_50 ) ;
}
}
void F_127 ( struct V_49 * V_50 )
{
V_50 -> V_137 ++ ;
}
void F_128 ( struct V_49 * V_50 )
{
V_50 -> V_137 -- ;
if ( ( V_50 -> V_137 == 0 ) && V_50 -> V_138 ) {
F_129 ( V_50 -> V_138 ) ;
V_50 -> V_138 = NULL ;
}
}
void F_119 ( struct V_49 * V_50 , struct V_76 * V_139 )
{
if ( V_139 )
F_71 ( V_139 ) ;
if ( V_50 -> V_138 )
F_129 ( V_50 -> V_138 ) ;
V_50 -> V_138 = V_139 ;
V_50 -> V_137 = 0 ;
}
struct V_76 * F_130 ( struct V_49 * V_50 )
{
struct V_76 * V_138 ;
F_131 ( & V_50 -> V_64 ) ;
V_138 = V_50 -> V_138 ;
if ( V_138 )
F_71 ( V_138 ) ;
F_132 ( & V_50 -> V_64 ) ;
return V_138 ;
}
static void F_133 ( struct V_49 * V_51 , struct V_49 * V_140 )
{
V_140 -> V_138 = F_130 ( V_51 ) ;
}
struct V_49 * F_134 ( struct V_6 * V_141 )
{
struct V_49 * V_50 ;
F_135 ( V_141 ) ;
V_50 = V_141 -> V_50 ;
if ( V_50 ) {
if ( V_141 -> V_123 & V_142 )
V_50 = NULL ;
else
F_136 ( & V_50 -> V_120 ) ;
}
F_137 ( V_141 ) ;
return V_50 ;
}
void F_138 ( struct V_6 * V_7 , struct V_49 * V_50 )
{
struct V_143 * V_144 = V_7 -> V_144 ;
#ifdef F_139
if ( F_89 ( V_7 -> V_145 ) ) {
F_140 ( V_7 ) ;
V_7 -> V_145 = NULL ;
}
#ifdef F_141
if ( F_89 ( V_7 -> V_146 ) ) {
F_142 ( V_7 ) ;
V_7 -> V_146 = NULL ;
}
#endif
if ( F_89 ( ! F_120 ( & V_7 -> V_147 ) ) )
F_143 ( V_7 ) ;
#endif
F_144 ( V_7 , V_50 ) ;
if ( V_144 ) {
V_7 -> V_144 = NULL ;
F_145 ( V_144 ) ;
}
if ( V_7 -> V_148 ) {
if ( ! ( V_7 -> V_123 & V_149 ) &&
F_29 ( & V_50 -> V_120 ) > 1 ) {
F_146 ( 0 , V_7 -> V_148 ) ;
F_147 ( V_7 -> V_148 , V_150 ,
1 , NULL , NULL , 0 ) ;
}
V_7 -> V_148 = NULL ;
}
}
struct V_49 * F_148 ( struct V_6 * V_7 )
{
struct V_49 * V_50 , * V_51 = V_26 -> V_50 ;
int V_42 ;
if ( ! V_51 )
return NULL ;
V_50 = F_105 () ;
if ( ! V_50 )
goto V_87;
memcpy ( V_50 , V_51 , sizeof( * V_50 ) ) ;
F_106 ( V_50 ) ;
V_50 -> V_151 = 0 ;
V_50 -> V_152 = 0 ;
#ifdef F_111
V_50 -> V_133 = NULL ;
#endif
if ( ! F_98 ( V_50 , V_7 ) )
goto V_87;
if ( F_149 ( V_7 , V_50 ) )
goto V_153;
F_133 ( V_51 , V_50 ) ;
V_42 = F_52 ( V_50 , V_51 ) ;
if ( V_42 )
goto V_154;
V_50 -> V_155 = F_150 ( V_50 ) ;
V_50 -> V_156 = V_50 -> V_80 ;
if ( V_50 -> V_135 && ! F_151 ( V_50 -> V_135 -> V_136 ) )
goto V_154;
return V_50 ;
V_154:
V_50 -> V_135 = NULL ;
F_113 ( V_50 ) ;
V_87:
return NULL ;
V_153:
F_90 ( V_50 ) ;
F_103 ( V_50 ) ;
return NULL ;
}
static int F_152 ( unsigned long V_157 , struct V_6 * V_7 )
{
struct V_49 * V_50 , * V_51 ;
int V_60 ;
V_7 -> V_158 = V_7 -> V_159 = 0 ;
V_7 -> V_160 = V_7 -> V_161 = 0 ;
#ifdef F_153
V_7 -> V_162 = V_7 -> V_160 + V_7 -> V_161 ;
#endif
V_7 -> V_50 = NULL ;
V_7 -> V_163 = NULL ;
V_51 = V_26 -> V_50 ;
if ( ! V_51 )
return 0 ;
if ( V_157 & V_164 ) {
F_136 ( & V_51 -> V_120 ) ;
V_50 = V_51 ;
goto V_165;
}
V_60 = - V_111 ;
V_50 = F_148 ( V_7 ) ;
if ( ! V_50 )
goto V_87;
V_165:
V_50 -> V_151 = 0 ;
V_50 -> V_152 = 0 ;
if ( V_7 -> signal -> V_166 == V_167 )
F_136 ( & V_50 -> V_130 ) ;
V_7 -> V_50 = V_50 ;
V_7 -> V_163 = V_50 ;
return 0 ;
V_87:
return V_60 ;
}
static int F_154 ( unsigned long V_157 , struct V_6 * V_7 )
{
struct V_168 * V_169 = V_26 -> V_169 ;
if ( V_157 & V_170 ) {
F_121 ( & V_169 -> V_171 ) ;
if ( V_169 -> V_172 ) {
F_123 ( & V_169 -> V_171 ) ;
return - V_173 ;
}
V_169 -> V_174 ++ ;
F_123 ( & V_169 -> V_171 ) ;
return 0 ;
}
V_7 -> V_169 = F_155 ( V_169 ) ;
if ( ! V_7 -> V_169 )
return - V_111 ;
return 0 ;
}
static int F_156 ( unsigned long V_157 , struct V_6 * V_7 )
{
struct V_175 * V_176 , * V_177 ;
int error = 0 ;
V_176 = V_26 -> V_178 ;
if ( ! V_176 )
goto V_43;
if ( V_157 & V_179 ) {
F_136 ( & V_176 -> V_180 ) ;
goto V_43;
}
V_177 = F_157 ( V_176 , & error ) ;
if ( ! V_177 )
goto V_43;
V_7 -> V_178 = V_177 ;
error = 0 ;
V_43:
return error ;
}
static int F_158 ( unsigned long V_157 , struct V_6 * V_7 )
{
#ifdef F_159
struct V_181 * V_182 = V_26 -> V_181 ;
if ( ! V_182 )
return 0 ;
if ( V_157 & V_183 ) {
V_7 -> V_181 = F_160 ( V_182 ) ;
if ( F_89 ( ! V_7 -> V_181 ) )
return - V_111 ;
} else if ( F_161 ( V_182 -> V_184 ) ) {
V_7 -> V_181 = F_162 ( V_10 , - 1 ) ;
if ( F_89 ( ! V_7 -> V_181 ) )
return - V_111 ;
V_7 -> V_181 -> V_184 = V_182 -> V_184 ;
}
#endif
return 0 ;
}
static int F_163 ( unsigned long V_157 , struct V_6 * V_7 )
{
struct V_185 * V_21 ;
if ( V_157 & V_186 ) {
F_136 ( & V_26 -> V_187 -> V_180 ) ;
return 0 ;
}
V_21 = F_63 ( V_188 , V_10 ) ;
F_164 ( V_7 -> V_187 , V_21 ) ;
if ( ! V_21 )
return - V_111 ;
F_50 ( & V_21 -> V_180 , 1 ) ;
memcpy ( V_21 -> V_189 , V_26 -> V_187 -> V_189 , sizeof( V_21 -> V_189 ) ) ;
return 0 ;
}
void F_165 ( struct V_185 * V_187 )
{
if ( F_26 ( & V_187 -> V_180 ) )
F_24 ( V_188 , V_187 ) ;
}
static void F_166 ( struct V_20 * V_21 )
{
unsigned long V_190 ;
F_167 ( V_21 ) ;
V_190 = F_168 ( V_21 -> V_35 [ V_191 ] . V_37 ) ;
if ( V_190 != V_192 ) {
V_21 -> V_193 . V_194 = F_169 ( V_190 ) ;
V_21 -> V_195 . V_196 = 1 ;
}
F_64 ( & V_21 -> V_197 [ 0 ] ) ;
F_64 ( & V_21 -> V_197 [ 1 ] ) ;
F_64 ( & V_21 -> V_197 [ 2 ] ) ;
}
static int F_170 ( unsigned long V_157 , struct V_6 * V_7 )
{
struct V_20 * V_21 ;
if ( V_157 & V_198 )
return 0 ;
V_21 = F_171 ( V_22 , V_10 ) ;
V_7 -> signal = V_21 ;
if ( ! V_21 )
return - V_111 ;
V_21 -> V_199 = 1 ;
F_50 ( & V_21 -> V_200 , 1 ) ;
F_50 ( & V_21 -> V_23 , 1 ) ;
F_172 ( & V_21 -> V_201 ) ;
if ( V_157 & V_202 )
V_21 -> V_123 |= V_203 ;
V_21 -> V_204 = V_7 ;
F_173 ( & V_21 -> V_205 ) ;
F_64 ( & V_21 -> V_206 ) ;
F_174 ( & V_21 -> V_207 , V_208 , V_209 ) ;
V_21 -> V_207 . V_210 = V_211 ;
F_135 ( V_26 -> V_212 ) ;
memcpy ( V_21 -> V_35 , V_26 -> signal -> V_35 , sizeof V_21 -> V_35 ) ;
F_137 ( V_26 -> V_212 ) ;
F_166 ( V_21 ) ;
F_175 ( V_21 ) ;
F_176 ( V_21 ) ;
#ifdef F_177
F_99 ( & V_21 -> V_213 ) ;
#endif
V_21 -> V_214 = V_26 -> signal -> V_214 ;
V_21 -> V_166 = V_26 -> signal -> V_166 ;
V_21 -> V_215 = V_26 -> signal -> V_215 ;
F_178 ( & V_21 -> V_216 ) ;
return 0 ;
}
static void F_179 ( unsigned long V_157 , struct V_6 * V_119 )
{
unsigned long V_217 = V_119 -> V_123 ;
V_217 &= ~ ( V_218 | V_219 ) ;
V_217 |= V_220 ;
V_217 |= V_221 ;
V_119 -> V_123 = V_217 ;
F_180 ( V_119 ) ;
}
static void F_181 ( struct V_6 * V_119 )
{
F_182 ( & V_119 -> V_222 ) ;
#ifdef F_183
F_184 ( & V_119 -> V_223 , & V_119 -> V_222 ) ;
V_119 -> V_224 = NULL ;
#endif
}
void F_100 ( struct V_49 * V_50 , struct V_6 * V_119 )
{
V_50 -> V_225 = V_119 ;
}
static void F_185 ( struct V_6 * V_7 )
{
V_7 -> V_193 . V_194 = V_226 ;
V_7 -> V_193 . V_227 = V_226 ;
V_7 -> V_193 . V_228 = 0 ;
F_64 ( & V_7 -> V_197 [ 0 ] ) ;
F_64 ( & V_7 -> V_197 [ 1 ] ) ;
F_64 ( & V_7 -> V_197 [ 2 ] ) ;
}
static struct V_6 * F_186 ( unsigned long V_157 ,
unsigned long V_229 ,
struct V_230 * V_231 ,
unsigned long V_232 ,
int T_3 * V_233 ,
struct V_234 * V_234 ,
int V_235 )
{
int V_60 ;
struct V_6 * V_119 ;
int V_236 = 0 ;
if ( ( V_157 & ( V_237 | V_170 ) ) == ( V_237 | V_170 ) )
return F_187 ( - V_238 ) ;
if ( ( V_157 & V_198 ) && ! ( V_157 & V_186 ) )
return F_187 ( - V_238 ) ;
if ( ( V_157 & V_186 ) && ! ( V_157 & V_164 ) )
return F_187 ( - V_238 ) ;
if ( ( V_157 & V_239 ) &&
V_26 -> signal -> V_123 & V_203 )
return F_187 ( - V_238 ) ;
V_60 = F_188 ( V_157 ) ;
if ( V_60 )
goto V_240;
V_60 = - V_111 ;
V_119 = F_38 ( V_26 ) ;
if ( ! V_119 )
goto V_240;
F_189 ( V_119 ) ;
F_181 ( V_119 ) ;
#ifdef F_190
F_191 ( ! V_119 -> V_241 ) ;
F_191 ( ! V_119 -> V_242 ) ;
#endif
V_60 = - V_173 ;
if ( F_29 ( & V_119 -> V_243 -> V_244 -> V_245 ) >=
F_192 ( V_119 , V_36 ) ) {
if ( ! F_193 ( V_246 ) && ! F_193 ( V_247 ) &&
V_119 -> V_243 -> V_244 != V_248 )
goto V_249;
}
V_60 = F_194 ( V_119 , V_157 ) ;
if ( V_60 < 0 )
goto V_249;
V_60 = - V_173 ;
if ( V_199 >= V_31 )
goto V_250;
if ( ! F_151 ( F_195 ( V_119 ) -> V_251 -> V_136 ) )
goto V_250;
V_119 -> V_252 = 0 ;
F_196 ( V_119 ) ;
F_179 ( V_157 , V_119 ) ;
F_64 ( & V_119 -> V_253 ) ;
F_64 ( & V_119 -> V_254 ) ;
F_197 ( V_119 ) ;
V_119 -> V_144 = NULL ;
F_96 ( & V_119 -> V_255 ) ;
F_173 ( & V_119 -> V_256 ) ;
V_119 -> V_257 = V_226 ;
V_119 -> V_258 = V_226 ;
V_119 -> V_259 = V_226 ;
V_119 -> V_260 = V_226 ;
V_119 -> V_261 = V_226 ;
#ifndef F_198
V_119 -> V_262 = V_226 ;
V_119 -> V_263 = V_226 ;
#endif
#if F_199 ( V_264 )
memset ( & V_119 -> V_127 , 0 , sizeof( V_119 -> V_127 ) ) ;
#endif
V_119 -> V_265 = V_26 -> V_266 ;
F_200 ( & V_119 -> V_267 ) ;
F_201 ( V_119 ) ;
F_185 ( V_119 ) ;
F_202 ( & V_119 -> V_268 ) ;
V_119 -> V_269 = V_119 -> V_268 ;
F_203 ( & V_119 -> V_269 ) ;
V_119 -> V_181 = NULL ;
V_119 -> V_270 = NULL ;
if ( V_157 & V_198 )
F_204 ( V_26 ) ;
F_205 ( V_119 ) ;
#ifdef F_206
V_119 -> V_62 = F_65 ( V_119 -> V_62 ) ;
if ( F_68 ( V_119 -> V_62 ) ) {
V_60 = F_67 ( V_119 -> V_62 ) ;
V_119 -> V_62 = NULL ;
goto V_271;
}
F_207 ( V_119 ) ;
#endif
#ifdef F_208
V_119 -> V_272 = 0 ;
#ifdef F_209
V_119 -> V_241 = 1 ;
#else
V_119 -> V_241 = 0 ;
#endif
V_119 -> V_273 = 0 ;
V_119 -> V_274 = 0 ;
V_119 -> V_275 = V_276 ;
V_119 -> V_277 = 0 ;
V_119 -> V_242 = 1 ;
V_119 -> V_278 = V_276 ;
V_119 -> V_279 = 0 ;
V_119 -> V_280 = 0 ;
V_119 -> V_281 = 0 ;
V_119 -> V_282 = 0 ;
V_119 -> V_283 = 0 ;
#endif
#ifdef F_210
V_119 -> V_284 = 0 ;
V_119 -> V_285 = 0 ;
V_119 -> V_286 = 0 ;
#endif
#ifdef F_211
V_119 -> V_287 = NULL ;
#endif
#ifdef F_212
V_119 -> V_288 . V_289 = 0 ;
V_119 -> V_288 . V_290 = NULL ;
#endif
F_213 ( V_119 ) ;
V_60 = F_214 ( V_119 ) ;
if ( V_60 )
goto V_291;
if ( ( V_60 = F_215 ( V_119 ) ) )
goto V_291;
if ( ( V_60 = F_216 ( V_157 , V_119 ) ) )
goto V_292;
if ( ( V_60 = F_156 ( V_157 , V_119 ) ) )
goto V_293;
if ( ( V_60 = F_154 ( V_157 , V_119 ) ) )
goto V_294;
if ( ( V_60 = F_163 ( V_157 , V_119 ) ) )
goto V_295;
if ( ( V_60 = F_170 ( V_157 , V_119 ) ) )
goto V_296;
if ( ( V_60 = F_152 ( V_157 , V_119 ) ) )
goto V_297;
if ( ( V_60 = F_217 ( V_157 , V_119 ) ) )
goto V_298;
if ( ( V_60 = F_158 ( V_157 , V_119 ) ) )
goto V_299;
V_60 = F_218 ( V_157 , V_229 , V_232 , V_119 , V_231 ) ;
if ( V_60 )
goto V_300;
if ( V_234 != & V_301 ) {
V_60 = - V_111 ;
V_234 = F_219 ( V_119 -> V_302 -> V_303 ) ;
if ( ! V_234 )
goto V_300;
}
V_119 -> V_234 = F_220 ( V_234 ) ;
V_119 -> V_304 = V_119 -> V_234 ;
if ( V_157 & V_198 )
V_119 -> V_304 = V_26 -> V_304 ;
V_119 -> V_305 = ( V_157 & V_306 ) ? V_233 : NULL ;
V_119 -> V_148 = ( V_157 & V_307 ) ? V_233 : NULL ;
#ifdef F_159
V_119 -> V_308 = NULL ;
#endif
#ifdef F_139
V_119 -> V_145 = NULL ;
#ifdef F_141
V_119 -> V_146 = NULL ;
#endif
F_64 ( & V_119 -> V_147 ) ;
V_119 -> V_309 = NULL ;
#endif
if ( ( V_157 & ( V_164 | V_310 ) ) == V_164 )
V_119 -> V_311 = V_119 -> V_312 = 0 ;
F_221 ( V_119 ) ;
F_222 ( V_119 , V_313 ) ;
#ifdef F_223
F_222 ( V_119 , F_223 ) ;
#endif
F_224 ( V_119 ) ;
V_119 -> V_314 = ( V_157 & V_198 ) ? - 1 : ( V_157 & V_315 ) ;
V_119 -> V_316 = 0 ;
V_119 -> V_24 = 0 ;
V_119 -> V_212 = V_119 ;
F_64 ( & V_119 -> V_317 ) ;
F_225 ( V_119 ) ;
V_236 = 1 ;
F_226 ( & V_1 ) ;
if ( V_157 & ( V_239 | V_198 ) ) {
V_119 -> V_318 = V_26 -> V_318 ;
V_119 -> V_319 = V_26 -> V_319 ;
} else {
V_119 -> V_318 = V_26 ;
V_119 -> V_319 = V_26 -> V_320 ;
}
F_121 ( & V_26 -> V_187 -> V_321 ) ;
F_227 () ;
if ( F_228 ( V_26 ) ) {
F_123 ( & V_26 -> V_187 -> V_321 ) ;
F_229 ( & V_1 ) ;
V_60 = - V_322 ;
goto V_323;
}
if ( V_157 & V_198 ) {
V_26 -> signal -> V_199 ++ ;
F_136 ( & V_26 -> signal -> V_200 ) ;
F_136 ( & V_26 -> signal -> V_23 ) ;
V_119 -> V_212 = V_26 -> V_212 ;
F_230 ( & V_119 -> V_317 , & V_119 -> V_212 -> V_317 ) ;
}
if ( F_101 ( V_119 -> V_234 ) ) {
F_231 ( V_119 , V_157 , V_235 ) ;
if ( F_232 ( V_119 ) ) {
if ( F_233 ( V_234 ) )
V_119 -> V_302 -> V_303 -> V_324 = V_119 ;
V_119 -> signal -> V_325 = V_234 ;
V_119 -> signal -> V_326 = F_234 ( V_26 -> signal -> V_326 ) ;
F_235 ( V_119 , V_327 , F_236 ( V_26 ) ) ;
F_235 ( V_119 , V_328 , F_237 ( V_26 ) ) ;
F_238 ( & V_119 -> V_254 , & V_119 -> V_318 -> V_253 ) ;
F_230 ( & V_119 -> V_329 , & V_34 . V_329 ) ;
F_239 ( V_4 ) ;
}
F_235 ( V_119 , V_330 , V_234 ) ;
V_199 ++ ;
}
V_331 ++ ;
F_123 ( & V_26 -> V_187 -> V_321 ) ;
F_229 ( & V_1 ) ;
F_240 ( V_119 ) ;
F_241 ( V_119 ) ;
if ( V_157 & V_198 )
F_242 ( V_26 ) ;
F_243 ( V_119 ) ;
return V_119 ;
V_323:
if ( V_234 != & V_301 )
F_244 ( V_234 ) ;
V_300:
if ( V_119 -> V_181 )
F_245 ( V_119 ) ;
V_299:
F_246 ( V_119 ) ;
V_298:
if ( V_119 -> V_50 ) {
F_135 ( V_119 ) ;
if ( V_119 -> signal -> V_166 == V_167 )
F_72 ( & V_119 -> V_50 -> V_130 ) ;
F_137 ( V_119 ) ;
F_113 ( V_119 -> V_50 ) ;
}
V_297:
if ( ! ( V_157 & V_198 ) )
F_21 ( V_119 -> signal ) ;
V_296:
F_165 ( V_119 -> V_187 ) ;
V_295:
F_247 ( V_119 ) ;
V_294:
F_248 ( V_119 ) ;
V_293:
F_249 ( V_119 ) ;
V_292:
F_250 ( V_119 ) ;
V_291:
F_251 ( V_119 ) ;
#ifdef F_206
F_85 ( V_119 -> V_62 ) ;
V_271:
#endif
if ( V_157 & V_198 )
F_242 ( V_26 ) ;
F_252 ( V_119 , V_236 ) ;
F_31 ( V_119 ) ;
F_125 ( F_195 ( V_119 ) -> V_251 -> V_136 ) ;
V_250:
F_72 ( & V_119 -> V_332 -> V_244 -> V_245 ) ;
F_30 ( V_119 ) ;
V_249:
F_16 ( V_119 ) ;
V_240:
return F_187 ( V_60 ) ;
}
static inline void F_253 ( struct V_333 * V_334 )
{
enum V_335 type ;
for ( type = V_330 ; type < V_336 ; ++ type ) {
F_254 ( & V_334 [ type ] . V_8 ) ;
V_334 [ type ] . V_234 = & V_301 ;
}
}
struct V_6 * T_4 F_255 ( int V_2 )
{
struct V_6 * V_141 ;
struct V_230 V_231 ;
V_141 = F_186 ( V_164 , 0 , F_256 ( & V_231 ) , 0 , NULL ,
& V_301 , 0 ) ;
if ( ! F_68 ( V_141 ) ) {
F_253 ( V_141 -> V_337 ) ;
F_257 ( V_141 , V_2 ) ;
}
return V_141 ;
}
long F_258 ( unsigned long V_157 ,
unsigned long V_229 ,
struct V_230 * V_231 ,
unsigned long V_232 ,
int T_3 * V_338 ,
int T_3 * V_233 )
{
struct V_6 * V_119 ;
int V_235 = 0 ;
long V_339 ;
if ( V_157 & V_340 ) {
if ( V_157 & V_198 )
return - V_238 ;
if ( ! F_193 ( V_246 ) || ! F_193 ( V_341 ) ||
! F_193 ( V_342 ) )
return - V_343 ;
}
if ( F_101 ( F_259 ( V_231 ) ) )
V_235 = F_260 ( V_157 ) ;
V_119 = F_186 ( V_157 , V_229 , V_231 , V_232 ,
V_233 , NULL , V_235 ) ;
if ( ! F_68 ( V_119 ) ) {
struct V_143 V_344 ;
F_261 ( V_26 , V_119 ) ;
V_339 = F_262 ( V_119 ) ;
if ( V_157 & V_345 )
F_146 ( V_339 , V_338 ) ;
if ( V_157 & V_310 ) {
V_119 -> V_144 = & V_344 ;
F_263 ( & V_344 ) ;
}
F_264 ( V_119 ) ;
F_265 ( V_231 , V_157 , V_339 , V_119 ) ;
V_119 -> V_123 &= ~ V_221 ;
F_266 ( V_119 ) ;
F_267 ( V_235 , V_231 ,
V_157 , V_339 , V_119 ) ;
if ( V_157 & V_310 ) {
F_268 () ;
F_269 ( & V_344 ) ;
F_270 () ;
F_271 ( V_119 , V_339 ) ;
}
} else {
V_339 = F_67 ( V_119 ) ;
}
return V_339 ;
}
static void F_272 ( void * V_346 )
{
struct V_185 * V_187 = V_346 ;
F_96 ( & V_187 -> V_321 ) ;
F_172 ( & V_187 -> V_347 ) ;
}
void T_2 F_273 ( void )
{
V_188 = F_36 ( L_2 ,
sizeof( struct V_185 ) , 0 ,
V_348 | V_29 | V_349 |
V_30 , F_272 ) ;
V_22 = F_36 ( L_3 ,
sizeof( struct V_20 ) , 0 ,
V_348 | V_29 | V_30 , NULL ) ;
V_350 = F_36 ( L_4 ,
sizeof( struct V_175 ) , 0 ,
V_348 | V_29 | V_30 , NULL ) ;
V_351 = F_36 ( L_5 ,
sizeof( struct V_168 ) , 0 ,
V_348 | V_29 | V_30 , NULL ) ;
V_352 = F_36 ( L_6 ,
sizeof( struct V_49 ) , V_353 ,
V_348 | V_29 | V_30 , NULL ) ;
V_88 = F_274 ( V_52 , V_29 ) ;
F_275 () ;
}
static int F_276 ( unsigned long V_354 )
{
if ( V_354 & ~ ( V_198 | V_170 | V_237 | V_186 |
V_164 | V_179 | V_355 |
V_356 | V_357 | V_358 ) )
return - V_238 ;
if ( V_354 & ( V_198 | V_186 | V_164 ) ) {
if ( F_29 ( & V_26 -> V_50 -> V_120 ) > 1 )
return - V_238 ;
}
return 0 ;
}
static int F_277 ( unsigned long V_354 , struct V_168 * * V_359 )
{
struct V_168 * V_169 = V_26 -> V_169 ;
if ( ! ( V_354 & V_170 ) || ! V_169 )
return 0 ;
if ( V_169 -> V_174 == 1 )
return 0 ;
* V_359 = F_155 ( V_169 ) ;
if ( ! * V_359 )
return - V_111 ;
return 0 ;
}
static int F_278 ( unsigned long V_354 , struct V_175 * * V_360 )
{
struct V_175 * V_361 = V_26 -> V_178 ;
int error = 0 ;
if ( ( V_354 & V_179 ) &&
( V_361 && F_29 ( & V_361 -> V_180 ) > 1 ) ) {
* V_360 = F_157 ( V_361 , & error ) ;
if ( ! * V_360 )
return error ;
}
return 0 ;
}
int F_279 ( struct V_175 * * V_362 )
{
struct V_6 * V_141 = V_26 ;
struct V_175 * V_363 = NULL ;
int error ;
error = F_278 ( V_179 , & V_363 ) ;
if ( error || ! V_363 ) {
* V_362 = NULL ;
return error ;
}
* V_362 = V_141 -> V_178 ;
F_135 ( V_141 ) ;
V_141 -> V_178 = V_363 ;
F_137 ( V_141 ) ;
return 0 ;
}
