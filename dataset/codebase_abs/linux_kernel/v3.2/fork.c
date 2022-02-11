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
F_12 ( V_7 -> V_18 , - 1 ) ;
F_10 ( V_7 -> V_18 ) ;
F_17 ( V_7 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 ) ;
}
static inline void F_20 ( struct V_19 * V_20 )
{
F_21 ( V_20 ) ;
F_22 ( V_20 ) ;
F_23 ( V_21 , V_20 ) ;
}
static inline void F_24 ( struct V_19 * V_20 )
{
if ( F_25 ( & V_20 -> V_22 ) )
F_20 ( V_20 ) ;
}
void F_26 ( struct V_6 * V_7 )
{
F_27 ( ! V_7 -> V_23 ) ;
F_27 ( F_28 ( & V_7 -> V_24 ) ) ;
F_27 ( V_7 == V_25 ) ;
F_29 ( V_7 ) ;
F_30 ( V_7 ) ;
F_24 ( V_7 -> signal ) ;
if ( ! F_31 ( V_7 ) )
F_16 ( V_7 ) ;
}
void T_2 F_32 ( unsigned long V_26 )
{
#ifndef F_33
#ifndef F_34
#define F_34 L1_CACHE_BYTES
#endif
V_27 =
F_35 ( L_1 , sizeof( struct V_6 ) ,
F_34 , V_28 | V_29 , NULL ) ;
#endif
F_36 () ;
V_30 = V_26 / ( 8 * V_31 / V_32 ) ;
if ( V_30 < 20 )
V_30 = 20 ;
V_33 . signal -> V_34 [ V_35 ] . V_36 = V_30 / 2 ;
V_33 . signal -> V_34 [ V_35 ] . V_37 = V_30 / 2 ;
V_33 . signal -> V_34 [ V_38 ] =
V_33 . signal -> V_34 [ V_35 ] ;
}
static struct V_6 * F_37 ( struct V_6 * V_39 )
{
struct V_6 * V_7 ;
struct V_5 * V_14 ;
unsigned long * V_40 ;
int V_8 = F_38 ( V_39 ) ;
int V_41 ;
F_39 ( V_39 ) ;
V_7 = F_40 ( V_8 ) ;
if ( ! V_7 )
return NULL ;
V_14 = F_6 ( V_7 , V_8 ) ;
if ( ! V_14 ) {
F_19 ( V_7 ) ;
return NULL ;
}
V_41 = F_41 ( V_7 , V_39 ) ;
if ( V_41 )
goto V_42;
V_7 -> V_18 = V_14 ;
F_42 ( V_7 , V_39 ) ;
F_43 ( V_7 ) ;
F_44 ( V_7 ) ;
V_40 = F_45 ( V_7 ) ;
* V_40 = V_43 ;
#ifdef F_46
V_7 -> V_44 = F_47 () ;
#endif
F_48 ( & V_7 -> V_24 , 2 ) ;
#ifdef F_49
V_7 -> V_45 = 0 ;
#endif
V_7 -> V_46 = NULL ;
F_12 ( V_14 , 1 ) ;
return V_7 ;
V_42:
F_10 ( V_14 ) ;
F_19 ( V_7 ) ;
return NULL ;
}
static int F_50 ( struct V_47 * V_48 , struct V_47 * V_49 )
{
struct V_50 * V_51 , * V_52 , * V_53 , * * V_54 ;
struct V_55 * * V_56 , * V_57 ;
int V_58 ;
unsigned long V_59 ;
struct V_60 * V_61 ;
F_51 ( & V_49 -> V_62 ) ;
F_52 ( V_49 ) ;
F_53 ( & V_48 -> V_62 , V_63 ) ;
V_48 -> V_64 = 0 ;
V_48 -> V_65 = NULL ;
V_48 -> V_66 = NULL ;
V_48 -> V_67 = V_49 -> V_68 ;
V_48 -> V_69 = ~ 0UL ;
V_48 -> V_70 = 0 ;
F_54 ( F_55 ( V_48 ) ) ;
V_48 -> V_71 = V_72 ;
V_56 = & V_48 -> V_71 . V_55 ;
V_57 = NULL ;
V_54 = & V_48 -> V_65 ;
V_58 = F_56 ( V_48 , V_49 ) ;
if ( V_58 )
goto V_42;
V_58 = F_57 ( V_48 , V_49 ) ;
if ( V_58 )
goto V_42;
V_53 = NULL ;
for ( V_51 = V_49 -> V_65 ; V_51 ; V_51 = V_51 -> V_73 ) {
struct V_74 * V_74 ;
if ( V_51 -> V_75 & V_76 ) {
long V_77 = F_58 ( V_51 ) ;
V_48 -> V_78 -= V_77 ;
F_59 ( V_48 , V_51 -> V_75 , V_51 -> V_79 ,
- V_77 ) ;
continue;
}
V_59 = 0 ;
if ( V_51 -> V_75 & V_80 ) {
unsigned int V_81 = ( V_51 -> V_82 - V_51 -> V_83 ) >> V_84 ;
if ( F_60 ( V_81 ) )
goto V_85;
V_59 = V_81 ;
}
V_52 = F_61 ( V_86 , V_10 ) ;
if ( ! V_52 )
goto V_85;
* V_52 = * V_51 ;
F_62 ( & V_52 -> V_87 ) ;
V_61 = F_63 ( F_64 ( V_51 ) ) ;
V_58 = F_65 ( V_61 ) ;
if ( F_66 ( V_61 ) )
goto V_88;
F_67 ( V_52 , V_61 ) ;
V_52 -> V_89 = V_48 ;
if ( F_68 ( V_52 , V_51 ) )
goto V_90;
V_52 -> V_75 &= ~ V_91 ;
V_52 -> V_73 = V_52 -> V_92 = NULL ;
V_74 = V_52 -> V_79 ;
if ( V_74 ) {
struct V_93 * V_93 = V_74 -> V_94 . V_95 -> V_96 ;
struct V_97 * V_98 = V_74 -> V_99 ;
F_69 ( V_74 ) ;
if ( V_52 -> V_75 & V_100 )
F_70 ( & V_93 -> V_101 ) ;
F_71 ( & V_98 -> V_102 ) ;
if ( V_52 -> V_75 & V_103 )
V_98 -> V_104 ++ ;
F_72 ( V_98 ) ;
F_73 ( V_52 , V_51 ) ;
F_74 ( V_98 ) ;
F_75 ( & V_98 -> V_102 ) ;
}
if ( F_76 ( V_52 ) )
F_77 ( V_52 ) ;
* V_54 = V_52 ;
V_54 = & V_52 -> V_73 ;
V_52 -> V_92 = V_53 ;
V_53 = V_52 ;
F_78 ( V_48 , V_52 , V_56 , V_57 ) ;
V_56 = & V_52 -> V_105 . V_106 ;
V_57 = & V_52 -> V_105 ;
V_48 -> V_70 ++ ;
V_58 = F_79 ( V_48 , V_49 , V_51 ) ;
if ( V_52 -> V_107 && V_52 -> V_107 -> V_108 )
V_52 -> V_107 -> V_108 ( V_52 ) ;
if ( V_58 )
goto V_42;
}
F_80 ( V_49 , V_48 ) ;
V_58 = 0 ;
V_42:
F_81 ( & V_48 -> V_62 ) ;
F_82 ( V_49 ) ;
F_81 ( & V_49 -> V_62 ) ;
return V_58 ;
V_90:
F_83 ( V_61 ) ;
V_88:
F_23 ( V_86 , V_52 ) ;
V_85:
V_58 = - V_109 ;
F_84 ( V_59 ) ;
goto V_42;
}
static inline int F_85 ( struct V_47 * V_48 )
{
V_48 -> V_110 = F_86 ( V_48 ) ;
if ( F_87 ( ! V_48 -> V_110 ) )
return - V_109 ;
return 0 ;
}
static inline void F_88 ( struct V_47 * V_48 )
{
F_89 ( V_48 , V_48 -> V_110 ) ;
}
static int T_2 F_90 ( char * V_111 )
{
V_112 =
( F_91 ( V_111 , NULL , 0 ) << V_113 ) &
V_114 ;
return 1 ;
}
static void F_92 ( struct V_47 * V_48 )
{
#ifdef F_93
F_94 ( & V_48 -> V_115 ) ;
F_95 ( & V_48 -> V_116 ) ;
#endif
}
static struct V_47 * F_96 ( struct V_47 * V_48 , struct V_6 * V_117 )
{
F_48 ( & V_48 -> V_118 , 1 ) ;
F_48 ( & V_48 -> V_119 , 1 ) ;
F_97 ( & V_48 -> V_62 ) ;
F_62 ( & V_48 -> V_120 ) ;
V_48 -> V_121 = ( V_25 -> V_48 ) ?
( V_25 -> V_48 -> V_121 & V_122 ) : V_112 ;
V_48 -> V_123 = NULL ;
V_48 -> V_124 = 0 ;
memset ( & V_48 -> V_125 , 0 , sizeof( V_48 -> V_125 ) ) ;
F_94 ( & V_48 -> V_126 ) ;
V_48 -> V_67 = V_127 ;
V_48 -> V_69 = ~ 0UL ;
F_92 ( V_48 ) ;
F_98 ( V_48 , V_117 ) ;
if ( F_99 ( ! F_85 ( V_48 ) ) ) {
V_48 -> V_128 = 0 ;
F_100 ( V_48 ) ;
return V_48 ;
}
F_101 ( V_48 ) ;
return NULL ;
}
struct V_47 * F_102 ( void )
{
struct V_47 * V_48 ;
V_48 = F_103 () ;
if ( ! V_48 )
return NULL ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
F_104 ( V_48 ) ;
return F_96 ( V_48 , V_25 ) ;
}
void F_105 ( struct V_47 * V_48 )
{
F_106 ( V_48 == & V_129 ) ;
F_88 ( V_48 ) ;
F_107 ( V_48 ) ;
F_108 ( V_48 ) ;
#ifdef F_109
F_110 ( V_48 -> V_130 ) ;
#endif
F_101 ( V_48 ) ;
}
void F_111 ( struct V_47 * V_48 )
{
F_112 () ;
if ( F_25 ( & V_48 -> V_118 ) ) {
F_113 ( V_48 ) ;
F_114 ( V_48 ) ;
F_115 ( V_48 ) ;
F_116 ( V_48 ) ;
F_117 ( V_48 , NULL ) ;
if ( ! F_118 ( & V_48 -> V_120 ) ) {
F_119 ( & V_131 ) ;
F_120 ( & V_48 -> V_120 ) ;
F_121 ( & V_131 ) ;
}
F_122 ( V_48 ) ;
if ( V_48 -> V_132 )
F_123 ( V_48 -> V_132 -> V_133 ) ;
F_124 ( V_48 ) ;
}
}
void F_125 ( struct V_47 * V_48 )
{
V_48 -> V_134 ++ ;
}
void F_126 ( struct V_47 * V_48 )
{
V_48 -> V_134 -- ;
if ( ( V_48 -> V_134 == 0 ) && V_48 -> V_135 ) {
F_127 ( V_48 -> V_135 ) ;
V_48 -> V_135 = NULL ;
}
}
void F_117 ( struct V_47 * V_48 , struct V_74 * V_136 )
{
if ( V_136 )
F_69 ( V_136 ) ;
if ( V_48 -> V_135 )
F_127 ( V_48 -> V_135 ) ;
V_48 -> V_135 = V_136 ;
V_48 -> V_134 = 0 ;
}
struct V_74 * F_128 ( struct V_47 * V_48 )
{
struct V_74 * V_135 ;
F_129 ( & V_48 -> V_62 ) ;
V_135 = V_48 -> V_135 ;
if ( V_135 )
F_69 ( V_135 ) ;
F_130 ( & V_48 -> V_62 ) ;
return V_135 ;
}
static void F_131 ( struct V_47 * V_49 , struct V_47 * V_137 )
{
V_137 -> V_135 = F_128 ( V_49 ) ;
}
struct V_47 * F_132 ( struct V_6 * V_138 )
{
struct V_47 * V_48 ;
F_133 ( V_138 ) ;
V_48 = V_138 -> V_48 ;
if ( V_48 ) {
if ( V_138 -> V_121 & V_139 )
V_48 = NULL ;
else
F_134 ( & V_48 -> V_118 ) ;
}
F_135 ( V_138 ) ;
return V_48 ;
}
void F_136 ( struct V_6 * V_7 , struct V_47 * V_48 )
{
struct V_140 * V_141 = V_7 -> V_141 ;
#ifdef F_137
if ( F_87 ( V_7 -> V_142 ) ) {
F_138 ( V_7 ) ;
V_7 -> V_142 = NULL ;
}
#ifdef F_139
if ( F_87 ( V_7 -> V_143 ) ) {
F_140 ( V_7 ) ;
V_7 -> V_143 = NULL ;
}
#endif
if ( F_87 ( ! F_118 ( & V_7 -> V_144 ) ) )
F_141 ( V_7 ) ;
#endif
F_142 ( V_7 , V_48 ) ;
if ( V_141 ) {
V_7 -> V_141 = NULL ;
F_143 ( V_141 ) ;
}
if ( V_7 -> V_145 ) {
if ( ! ( V_7 -> V_121 & V_146 ) &&
F_28 ( & V_48 -> V_118 ) > 1 ) {
F_144 ( 0 , V_7 -> V_145 ) ;
F_145 ( V_7 -> V_145 , V_147 ,
1 , NULL , NULL , 0 ) ;
}
V_7 -> V_145 = NULL ;
}
}
struct V_47 * F_146 ( struct V_6 * V_7 )
{
struct V_47 * V_48 , * V_49 = V_25 -> V_48 ;
int V_41 ;
if ( ! V_49 )
return NULL ;
V_48 = F_103 () ;
if ( ! V_48 )
goto V_85;
memcpy ( V_48 , V_49 , sizeof( * V_48 ) ) ;
F_104 ( V_48 ) ;
V_48 -> V_148 = 0 ;
V_48 -> V_149 = 0 ;
#ifdef F_109
V_48 -> V_130 = NULL ;
#endif
if ( ! F_96 ( V_48 , V_7 ) )
goto V_85;
if ( F_147 ( V_7 , V_48 ) )
goto V_150;
F_131 ( V_49 , V_48 ) ;
V_41 = F_50 ( V_48 , V_49 ) ;
if ( V_41 )
goto V_151;
V_48 -> V_152 = F_148 ( V_48 ) ;
V_48 -> V_153 = V_48 -> V_78 ;
if ( V_48 -> V_132 && ! F_149 ( V_48 -> V_132 -> V_133 ) )
goto V_151;
return V_48 ;
V_151:
V_48 -> V_132 = NULL ;
F_111 ( V_48 ) ;
V_85:
return NULL ;
V_150:
F_88 ( V_48 ) ;
F_101 ( V_48 ) ;
return NULL ;
}
static int F_150 ( unsigned long V_154 , struct V_6 * V_7 )
{
struct V_47 * V_48 , * V_49 ;
int V_58 ;
V_7 -> V_155 = V_7 -> V_156 = 0 ;
V_7 -> V_157 = V_7 -> V_158 = 0 ;
#ifdef F_151
V_7 -> V_159 = V_7 -> V_157 + V_7 -> V_158 ;
#endif
V_7 -> V_48 = NULL ;
V_7 -> V_160 = NULL ;
V_49 = V_25 -> V_48 ;
if ( ! V_49 )
return 0 ;
if ( V_154 & V_161 ) {
F_134 ( & V_49 -> V_118 ) ;
V_48 = V_49 ;
goto V_162;
}
V_58 = - V_109 ;
V_48 = F_146 ( V_7 ) ;
if ( ! V_48 )
goto V_85;
V_162:
V_48 -> V_148 = 0 ;
V_48 -> V_149 = 0 ;
V_7 -> V_48 = V_48 ;
V_7 -> V_160 = V_48 ;
return 0 ;
V_85:
return V_58 ;
}
static int F_152 ( unsigned long V_154 , struct V_6 * V_7 )
{
struct V_163 * V_164 = V_25 -> V_164 ;
if ( V_154 & V_165 ) {
F_119 ( & V_164 -> V_166 ) ;
if ( V_164 -> V_167 ) {
F_121 ( & V_164 -> V_166 ) ;
return - V_168 ;
}
V_164 -> V_169 ++ ;
F_121 ( & V_164 -> V_166 ) ;
return 0 ;
}
V_7 -> V_164 = F_153 ( V_164 ) ;
if ( ! V_7 -> V_164 )
return - V_109 ;
return 0 ;
}
static int F_154 ( unsigned long V_154 , struct V_6 * V_7 )
{
struct V_170 * V_171 , * V_172 ;
int error = 0 ;
V_171 = V_25 -> V_173 ;
if ( ! V_171 )
goto V_42;
if ( V_154 & V_174 ) {
F_134 ( & V_171 -> V_175 ) ;
goto V_42;
}
V_172 = F_155 ( V_171 , & error ) ;
if ( ! V_172 )
goto V_42;
V_7 -> V_173 = V_172 ;
error = 0 ;
V_42:
return error ;
}
static int F_156 ( unsigned long V_154 , struct V_6 * V_7 )
{
#ifdef F_157
struct V_176 * V_177 = V_25 -> V_176 ;
if ( ! V_177 )
return 0 ;
if ( V_154 & V_178 ) {
V_7 -> V_176 = F_158 ( V_177 ) ;
if ( F_87 ( ! V_7 -> V_176 ) )
return - V_109 ;
} else if ( F_159 ( V_177 -> V_179 ) ) {
V_7 -> V_176 = F_160 ( V_10 , - 1 ) ;
if ( F_87 ( ! V_7 -> V_176 ) )
return - V_109 ;
V_7 -> V_176 -> V_179 = V_177 -> V_179 ;
}
#endif
return 0 ;
}
static int F_161 ( unsigned long V_154 , struct V_6 * V_7 )
{
struct V_180 * V_20 ;
if ( V_154 & V_181 ) {
F_134 ( & V_25 -> V_182 -> V_175 ) ;
return 0 ;
}
V_20 = F_61 ( V_183 , V_10 ) ;
F_162 ( V_7 -> V_182 , V_20 ) ;
if ( ! V_20 )
return - V_109 ;
F_48 ( & V_20 -> V_175 , 1 ) ;
memcpy ( V_20 -> V_184 , V_25 -> V_182 -> V_184 , sizeof( V_20 -> V_184 ) ) ;
return 0 ;
}
void F_163 ( struct V_180 * V_182 )
{
if ( F_25 ( & V_182 -> V_175 ) )
F_23 ( V_183 , V_182 ) ;
}
static void F_164 ( struct V_19 * V_20 )
{
unsigned long V_185 ;
F_165 ( V_20 ) ;
V_185 = F_166 ( V_20 -> V_34 [ V_186 ] . V_36 ) ;
if ( V_185 != V_187 ) {
V_20 -> V_188 . V_189 = F_167 ( V_185 ) ;
V_20 -> V_190 . V_191 = 1 ;
}
F_62 ( & V_20 -> V_192 [ 0 ] ) ;
F_62 ( & V_20 -> V_192 [ 1 ] ) ;
F_62 ( & V_20 -> V_192 [ 2 ] ) ;
}
static int F_168 ( unsigned long V_154 , struct V_6 * V_7 )
{
struct V_19 * V_20 ;
if ( V_154 & V_193 )
return 0 ;
V_20 = F_169 ( V_21 , V_10 ) ;
V_7 -> signal = V_20 ;
if ( ! V_20 )
return - V_109 ;
V_20 -> V_194 = 1 ;
F_48 ( & V_20 -> V_195 , 1 ) ;
F_48 ( & V_20 -> V_22 , 1 ) ;
F_170 ( & V_20 -> V_196 ) ;
if ( V_154 & V_197 )
V_20 -> V_121 |= V_198 ;
V_20 -> V_199 = V_7 ;
F_171 ( & V_20 -> V_200 ) ;
F_62 ( & V_20 -> V_201 ) ;
F_172 ( & V_20 -> V_202 , V_203 , V_204 ) ;
V_20 -> V_202 . V_205 = V_206 ;
F_133 ( V_25 -> V_207 ) ;
memcpy ( V_20 -> V_34 , V_25 -> signal -> V_34 , sizeof V_20 -> V_34 ) ;
F_135 ( V_25 -> V_207 ) ;
F_164 ( V_20 ) ;
F_173 ( V_20 ) ;
F_174 ( V_20 ) ;
#ifdef F_175
F_97 ( & V_20 -> V_208 ) ;
#endif
V_20 -> V_209 = V_25 -> signal -> V_209 ;
V_20 -> V_210 = V_25 -> signal -> V_210 ;
V_20 -> V_211 = V_25 -> signal -> V_211 ;
F_176 ( & V_20 -> V_212 ) ;
return 0 ;
}
static void F_177 ( unsigned long V_154 , struct V_6 * V_117 )
{
unsigned long V_213 = V_117 -> V_121 ;
V_213 &= ~ ( V_214 | V_215 ) ;
V_213 |= V_216 ;
V_213 |= V_217 ;
V_117 -> V_121 = V_213 ;
F_178 ( V_117 ) ;
}
static void F_179 ( struct V_6 * V_117 )
{
F_180 ( & V_117 -> V_218 ) ;
#ifdef F_181
F_182 ( & V_117 -> V_219 ) ;
V_117 -> V_220 = NULL ;
#endif
}
void F_98 ( struct V_47 * V_48 , struct V_6 * V_117 )
{
V_48 -> V_221 = V_117 ;
}
static void F_183 ( struct V_6 * V_7 )
{
V_7 -> V_188 . V_189 = V_222 ;
V_7 -> V_188 . V_223 = V_222 ;
V_7 -> V_188 . V_224 = 0 ;
F_62 ( & V_7 -> V_192 [ 0 ] ) ;
F_62 ( & V_7 -> V_192 [ 1 ] ) ;
F_62 ( & V_7 -> V_192 [ 2 ] ) ;
}
static struct V_6 * F_184 ( unsigned long V_154 ,
unsigned long V_225 ,
struct V_226 * V_227 ,
unsigned long V_228 ,
int T_3 * V_229 ,
struct V_230 * V_230 ,
int V_231 )
{
int V_58 ;
struct V_6 * V_117 ;
int V_232 = 0 ;
if ( ( V_154 & ( V_233 | V_165 ) ) == ( V_233 | V_165 ) )
return F_185 ( - V_234 ) ;
if ( ( V_154 & V_193 ) && ! ( V_154 & V_181 ) )
return F_185 ( - V_234 ) ;
if ( ( V_154 & V_181 ) && ! ( V_154 & V_161 ) )
return F_185 ( - V_234 ) ;
if ( ( V_154 & V_235 ) &&
V_25 -> signal -> V_121 & V_198 )
return F_185 ( - V_234 ) ;
V_58 = F_186 ( V_154 ) ;
if ( V_58 )
goto V_236;
V_58 = - V_109 ;
V_117 = F_37 ( V_25 ) ;
if ( ! V_117 )
goto V_236;
F_187 ( V_117 ) ;
F_179 ( V_117 ) ;
#ifdef F_188
F_189 ( ! V_117 -> V_237 ) ;
F_189 ( ! V_117 -> V_238 ) ;
#endif
V_58 = - V_168 ;
if ( F_28 ( & V_117 -> V_239 -> V_240 -> V_241 ) >=
F_190 ( V_117 , V_35 ) ) {
if ( ! F_191 ( V_242 ) && ! F_191 ( V_243 ) &&
V_117 -> V_239 -> V_240 != V_244 )
goto V_245;
}
V_25 -> V_121 &= ~ V_246 ;
V_58 = F_192 ( V_117 , V_154 ) ;
if ( V_58 < 0 )
goto V_245;
V_58 = - V_168 ;
if ( V_194 >= V_30 )
goto V_247;
if ( ! F_149 ( F_193 ( V_117 ) -> V_248 -> V_133 ) )
goto V_247;
V_117 -> V_249 = 0 ;
F_194 ( V_117 ) ;
F_177 ( V_154 , V_117 ) ;
F_62 ( & V_117 -> V_250 ) ;
F_62 ( & V_117 -> V_251 ) ;
F_195 ( V_117 ) ;
V_117 -> V_141 = NULL ;
F_94 ( & V_117 -> V_252 ) ;
F_171 ( & V_117 -> V_253 ) ;
V_117 -> V_254 = V_222 ;
V_117 -> V_255 = V_222 ;
V_117 -> V_256 = V_222 ;
V_117 -> V_257 = V_222 ;
V_117 -> V_258 = V_222 ;
#ifndef F_196
V_117 -> V_259 = V_222 ;
V_117 -> V_260 = V_222 ;
#endif
#if F_197 ( V_261 )
memset ( & V_117 -> V_125 , 0 , sizeof( V_117 -> V_125 ) ) ;
#endif
V_117 -> V_262 = V_25 -> V_263 ;
F_198 ( & V_117 -> V_264 ) ;
F_199 ( V_117 ) ;
F_183 ( V_117 ) ;
F_200 ( & V_117 -> V_265 ) ;
V_117 -> V_266 = V_117 -> V_265 ;
F_201 ( & V_117 -> V_266 ) ;
V_117 -> V_176 = NULL ;
V_117 -> V_267 = NULL ;
if ( V_154 & V_193 )
F_202 ( V_25 ) ;
F_203 ( V_117 ) ;
#ifdef F_204
V_117 -> V_60 = F_63 ( V_117 -> V_60 ) ;
if ( F_66 ( V_117 -> V_60 ) ) {
V_58 = F_65 ( V_117 -> V_60 ) ;
V_117 -> V_60 = NULL ;
goto V_268;
}
F_205 ( V_117 ) ;
#endif
#ifdef F_206
V_117 -> V_269 = V_270 ;
V_117 -> V_271 = V_270 ;
#endif
#ifdef F_207
V_117 -> V_272 = 0 ;
#ifdef F_208
V_117 -> V_237 = 1 ;
#else
V_117 -> V_237 = 0 ;
#endif
V_117 -> V_273 = 0 ;
V_117 -> V_274 = 0 ;
V_117 -> V_275 = V_276 ;
V_117 -> V_277 = 0 ;
V_117 -> V_238 = 1 ;
V_117 -> V_278 = V_276 ;
V_117 -> V_279 = 0 ;
V_117 -> V_280 = 0 ;
V_117 -> V_281 = 0 ;
V_117 -> V_282 = 0 ;
V_117 -> V_283 = 0 ;
#endif
#ifdef F_209
V_117 -> V_284 = 0 ;
V_117 -> V_285 = 0 ;
V_117 -> V_286 = 0 ;
#endif
#ifdef F_210
V_117 -> V_287 = NULL ;
#endif
#ifdef F_211
V_117 -> V_288 . V_289 = 0 ;
V_117 -> V_288 . V_290 = NULL ;
#endif
F_212 ( V_117 ) ;
V_58 = F_213 ( V_117 ) ;
if ( V_58 )
goto V_291;
V_58 = F_214 ( V_117 ) ;
if ( V_58 )
goto V_291;
V_58 = F_215 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_292;
V_58 = F_154 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_293;
V_58 = F_152 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_294;
V_58 = F_161 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_295;
V_58 = F_168 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_296;
V_58 = F_150 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_297;
V_58 = F_216 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_298;
V_58 = F_156 ( V_154 , V_117 ) ;
if ( V_58 )
goto V_299;
V_58 = F_217 ( V_154 , V_225 , V_228 , V_117 , V_227 ) ;
if ( V_58 )
goto V_300;
if ( V_230 != & V_301 ) {
V_58 = - V_109 ;
V_230 = F_218 ( V_117 -> V_302 -> V_303 ) ;
if ( ! V_230 )
goto V_300;
}
V_117 -> V_230 = F_219 ( V_230 ) ;
V_117 -> V_304 = V_117 -> V_230 ;
if ( V_154 & V_193 )
V_117 -> V_304 = V_25 -> V_304 ;
V_117 -> V_305 = ( V_154 & V_306 ) ? V_229 : NULL ;
V_117 -> V_145 = ( V_154 & V_307 ) ? V_229 : NULL ;
#ifdef F_157
V_117 -> V_308 = NULL ;
#endif
#ifdef F_137
V_117 -> V_142 = NULL ;
#ifdef F_139
V_117 -> V_143 = NULL ;
#endif
F_62 ( & V_117 -> V_144 ) ;
V_117 -> V_309 = NULL ;
#endif
if ( ( V_154 & ( V_161 | V_310 ) ) == V_161 )
V_117 -> V_311 = V_117 -> V_312 = 0 ;
F_220 ( V_117 ) ;
F_221 ( V_117 , V_313 ) ;
#ifdef F_222
F_221 ( V_117 , F_222 ) ;
#endif
F_223 ( V_117 ) ;
V_117 -> V_314 = ( V_154 & V_193 ) ? - 1 : ( V_154 & V_315 ) ;
V_117 -> V_316 = 0 ;
V_117 -> V_23 = 0 ;
V_117 -> V_317 = 0 ;
V_117 -> V_318 = 128 >> ( V_84 - 10 ) ;
V_117 -> V_207 = V_117 ;
F_62 ( & V_117 -> V_319 ) ;
F_224 ( V_117 ) ;
V_232 = 1 ;
F_225 ( & V_1 ) ;
if ( V_154 & ( V_235 | V_193 ) ) {
V_117 -> V_320 = V_25 -> V_320 ;
V_117 -> V_321 = V_25 -> V_321 ;
} else {
V_117 -> V_320 = V_25 ;
V_117 -> V_321 = V_25 -> V_322 ;
}
F_119 ( & V_25 -> V_182 -> V_323 ) ;
F_226 () ;
if ( F_227 ( V_25 ) ) {
F_121 ( & V_25 -> V_182 -> V_323 ) ;
F_228 ( & V_1 ) ;
V_58 = - V_324 ;
goto V_325;
}
if ( V_154 & V_193 ) {
V_25 -> signal -> V_194 ++ ;
F_134 ( & V_25 -> signal -> V_195 ) ;
F_134 ( & V_25 -> signal -> V_22 ) ;
V_117 -> V_207 = V_25 -> V_207 ;
F_229 ( & V_117 -> V_319 , & V_117 -> V_207 -> V_319 ) ;
}
if ( F_99 ( V_117 -> V_230 ) ) {
F_230 ( V_117 , ( V_154 & V_326 ) || V_231 ) ;
if ( F_231 ( V_117 ) ) {
if ( F_232 ( V_230 ) )
V_117 -> V_302 -> V_303 -> V_327 = V_117 ;
V_117 -> signal -> V_328 = V_230 ;
V_117 -> signal -> V_329 = F_233 ( V_25 -> signal -> V_329 ) ;
F_234 ( V_117 , V_330 , F_235 ( V_25 ) ) ;
F_234 ( V_117 , V_331 , F_236 ( V_25 ) ) ;
F_237 ( & V_117 -> V_251 , & V_117 -> V_320 -> V_250 ) ;
F_229 ( & V_117 -> V_332 , & V_33 . V_332 ) ;
F_238 ( V_4 ) ;
}
F_234 ( V_117 , V_333 , V_230 ) ;
V_194 ++ ;
}
V_334 ++ ;
F_121 ( & V_25 -> V_182 -> V_323 ) ;
F_228 ( & V_1 ) ;
F_239 ( V_117 ) ;
F_240 ( V_117 ) ;
if ( V_154 & V_193 )
F_241 ( V_25 ) ;
F_242 ( V_117 ) ;
return V_117 ;
V_325:
if ( V_230 != & V_301 )
F_243 ( V_230 ) ;
V_300:
if ( V_117 -> V_176 )
F_244 ( V_117 ) ;
V_299:
F_245 ( V_117 ) ;
V_298:
if ( V_117 -> V_48 )
F_111 ( V_117 -> V_48 ) ;
V_297:
if ( ! ( V_154 & V_193 ) )
F_20 ( V_117 -> signal ) ;
V_296:
F_163 ( V_117 -> V_182 ) ;
V_295:
F_246 ( V_117 ) ;
V_294:
F_247 ( V_117 ) ;
V_293:
F_248 ( V_117 ) ;
V_292:
F_249 ( V_117 ) ;
V_291:
F_250 ( V_117 ) ;
#ifdef F_204
F_83 ( V_117 -> V_60 ) ;
V_268:
#endif
if ( V_154 & V_193 )
F_241 ( V_25 ) ;
F_251 ( V_117 , V_232 ) ;
F_30 ( V_117 ) ;
F_123 ( F_193 ( V_117 ) -> V_248 -> V_133 ) ;
V_247:
F_70 ( & V_117 -> V_335 -> V_240 -> V_241 ) ;
F_29 ( V_117 ) ;
V_245:
F_16 ( V_117 ) ;
V_236:
return F_185 ( V_58 ) ;
}
static inline void F_252 ( struct V_336 * V_337 )
{
enum V_338 type ;
for ( type = V_333 ; type < V_339 ; ++ type ) {
F_253 ( & V_337 [ type ] . V_8 ) ;
V_337 [ type ] . V_230 = & V_301 ;
}
}
struct V_6 * T_4 F_254 ( int V_2 )
{
struct V_6 * V_138 ;
struct V_226 V_227 ;
V_138 = F_184 ( V_161 , 0 , F_255 ( & V_227 ) , 0 , NULL ,
& V_301 , 0 ) ;
if ( ! F_66 ( V_138 ) ) {
F_252 ( V_138 -> V_340 ) ;
F_256 ( V_138 , V_2 ) ;
}
return V_138 ;
}
long F_257 ( unsigned long V_154 ,
unsigned long V_225 ,
struct V_226 * V_227 ,
unsigned long V_228 ,
int T_3 * V_341 ,
int T_3 * V_229 )
{
struct V_6 * V_117 ;
int V_231 = 0 ;
long V_342 ;
if ( V_154 & V_343 ) {
if ( V_154 & V_193 )
return - V_234 ;
if ( ! F_191 ( V_242 ) || ! F_191 ( V_344 ) ||
! F_191 ( V_345 ) )
return - V_346 ;
}
if ( F_99 ( F_258 ( V_227 ) ) && ! ( V_154 & V_347 ) ) {
if ( V_154 & V_310 )
V_231 = V_348 ;
else if ( ( V_154 & V_315 ) != V_349 )
V_231 = V_350 ;
else
V_231 = V_351 ;
if ( F_99 ( ! F_259 ( V_25 , V_231 ) ) )
V_231 = 0 ;
}
V_117 = F_184 ( V_154 , V_225 , V_227 , V_228 ,
V_229 , NULL , V_231 ) ;
if ( ! F_66 ( V_117 ) ) {
struct V_140 V_352 ;
F_260 ( V_25 , V_117 ) ;
V_342 = F_261 ( V_117 ) ;
if ( V_154 & V_353 )
F_144 ( V_342 , V_341 ) ;
if ( V_154 & V_310 ) {
V_117 -> V_141 = & V_352 ;
F_262 ( & V_352 ) ;
}
F_263 ( V_117 ) ;
V_117 -> V_121 &= ~ V_217 ;
F_264 ( V_117 ) ;
if ( F_87 ( V_231 ) )
F_265 ( V_231 , V_342 ) ;
if ( V_154 & V_310 ) {
F_266 () ;
F_267 ( & V_352 ) ;
F_268 () ;
F_265 ( V_354 , V_342 ) ;
}
} else {
V_342 = F_65 ( V_117 ) ;
}
return V_342 ;
}
static void F_269 ( void * V_355 )
{
struct V_180 * V_182 = V_355 ;
F_94 ( & V_182 -> V_323 ) ;
F_170 ( & V_182 -> V_356 ) ;
}
void T_2 F_270 ( void )
{
V_183 = F_35 ( L_2 ,
sizeof( struct V_180 ) , 0 ,
V_357 | V_28 | V_358 |
V_29 , F_269 ) ;
V_21 = F_35 ( L_3 ,
sizeof( struct V_19 ) , 0 ,
V_357 | V_28 | V_29 , NULL ) ;
V_359 = F_35 ( L_4 ,
sizeof( struct V_170 ) , 0 ,
V_357 | V_28 | V_29 , NULL ) ;
V_360 = F_35 ( L_5 ,
sizeof( struct V_163 ) , 0 ,
V_357 | V_28 | V_29 , NULL ) ;
V_361 = F_35 ( L_6 ,
sizeof( struct V_47 ) , V_362 ,
V_357 | V_28 | V_29 , NULL ) ;
V_86 = F_271 ( V_50 , V_28 ) ;
F_272 () ;
F_273 () ;
}
static int F_274 ( unsigned long V_363 )
{
if ( V_363 & ~ ( V_193 | V_165 | V_233 | V_181 |
V_161 | V_174 | V_364 |
V_365 | V_366 | V_367 ) )
return - V_234 ;
if ( V_363 & ( V_193 | V_181 | V_161 ) ) {
if ( F_28 ( & V_25 -> V_48 -> V_118 ) > 1 )
return - V_234 ;
}
return 0 ;
}
static int F_275 ( unsigned long V_363 , struct V_163 * * V_368 )
{
struct V_163 * V_164 = V_25 -> V_164 ;
if ( ! ( V_363 & V_165 ) || ! V_164 )
return 0 ;
if ( V_164 -> V_169 == 1 )
return 0 ;
* V_368 = F_153 ( V_164 ) ;
if ( ! * V_368 )
return - V_109 ;
return 0 ;
}
static int F_276 ( unsigned long V_363 , struct V_170 * * V_369 )
{
struct V_170 * V_370 = V_25 -> V_173 ;
int error = 0 ;
if ( ( V_363 & V_174 ) &&
( V_370 && F_28 ( & V_370 -> V_175 ) > 1 ) ) {
* V_369 = F_155 ( V_370 , & error ) ;
if ( ! * V_369 )
return error ;
}
return 0 ;
}
int F_277 ( struct V_170 * * V_371 )
{
struct V_6 * V_138 = V_25 ;
struct V_170 * V_372 = NULL ;
int error ;
error = F_276 ( V_174 , & V_372 ) ;
if ( error || ! V_372 ) {
* V_371 = NULL ;
return error ;
}
* V_371 = V_138 -> V_173 ;
F_133 ( V_138 ) ;
V_138 -> V_173 = V_372 ;
F_135 ( V_138 ) ;
return 0 ;
}
