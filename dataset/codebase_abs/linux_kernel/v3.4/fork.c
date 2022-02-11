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
F_31 ( V_7 ) ;
F_24 ( V_7 -> signal ) ;
if ( ! F_32 ( V_7 ) )
F_16 ( V_7 ) ;
}
void T_2 F_33 ( unsigned long V_26 )
{
#ifndef F_34
#ifndef F_35
#define F_35 L1_CACHE_BYTES
#endif
V_27 =
F_36 ( L_1 , sizeof( struct V_6 ) ,
F_35 , V_28 | V_29 , NULL ) ;
#endif
F_37 () ;
V_30 = V_26 / ( 8 * V_31 / V_32 ) ;
if ( V_30 < 20 )
V_30 = 20 ;
V_33 . signal -> V_34 [ V_35 ] . V_36 = V_30 / 2 ;
V_33 . signal -> V_34 [ V_35 ] . V_37 = V_30 / 2 ;
V_33 . signal -> V_34 [ V_38 ] =
V_33 . signal -> V_34 [ V_35 ] ;
}
static struct V_6 * F_38 ( struct V_6 * V_39 )
{
struct V_6 * V_7 ;
struct V_5 * V_14 ;
unsigned long * V_40 ;
int V_8 = F_39 ( V_39 ) ;
int V_41 ;
F_40 ( V_39 ) ;
V_7 = F_41 ( V_8 ) ;
if ( ! V_7 )
return NULL ;
V_14 = F_6 ( V_7 , V_8 ) ;
if ( ! V_14 ) {
F_19 ( V_7 ) ;
return NULL ;
}
V_41 = F_42 ( V_7 , V_39 ) ;
if ( V_41 )
goto V_42;
V_7 -> V_18 = V_14 ;
F_43 ( V_7 , V_39 ) ;
F_44 ( V_7 ) ;
F_45 ( V_7 ) ;
V_40 = F_46 ( V_7 ) ;
* V_40 = V_43 ;
#ifdef F_47
V_7 -> V_44 = F_48 () ;
#endif
F_49 ( & V_7 -> V_24 , 2 ) ;
#ifdef F_50
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
static int F_51 ( struct V_47 * V_48 , struct V_47 * V_49 )
{
struct V_50 * V_51 , * V_52 , * V_53 , * * V_54 ;
struct V_55 * * V_56 , * V_57 ;
int V_58 ;
unsigned long V_59 ;
struct V_60 * V_61 ;
F_52 ( & V_49 -> V_62 ) ;
F_53 ( V_49 ) ;
F_54 ( & V_48 -> V_62 , V_63 ) ;
V_48 -> V_64 = 0 ;
V_48 -> V_65 = NULL ;
V_48 -> V_66 = NULL ;
V_48 -> V_67 = V_49 -> V_68 ;
V_48 -> V_69 = ~ 0UL ;
V_48 -> V_70 = 0 ;
F_55 ( F_56 ( V_48 ) ) ;
V_48 -> V_71 = V_72 ;
V_56 = & V_48 -> V_71 . V_55 ;
V_57 = NULL ;
V_54 = & V_48 -> V_65 ;
V_58 = F_57 ( V_48 , V_49 ) ;
if ( V_58 )
goto V_42;
V_58 = F_58 ( V_48 , V_49 ) ;
if ( V_58 )
goto V_42;
V_53 = NULL ;
for ( V_51 = V_49 -> V_65 ; V_51 ; V_51 = V_51 -> V_73 ) {
struct V_74 * V_74 ;
if ( V_51 -> V_75 & V_76 ) {
long V_77 = F_59 ( V_51 ) ;
V_48 -> V_78 -= V_77 ;
F_60 ( V_48 , V_51 -> V_75 , V_51 -> V_79 ,
- V_77 ) ;
continue;
}
V_59 = 0 ;
if ( V_51 -> V_75 & V_80 ) {
unsigned int V_81 = ( V_51 -> V_82 - V_51 -> V_83 ) >> V_84 ;
if ( F_61 ( V_49 , V_81 ) )
goto V_85;
V_59 = V_81 ;
}
V_52 = F_62 ( V_86 , V_10 ) ;
if ( ! V_52 )
goto V_85;
* V_52 = * V_51 ;
F_63 ( & V_52 -> V_87 ) ;
V_61 = F_64 ( F_65 ( V_51 ) ) ;
V_58 = F_66 ( V_61 ) ;
if ( F_67 ( V_61 ) )
goto V_88;
F_68 ( V_52 , V_61 ) ;
V_52 -> V_89 = V_48 ;
if ( F_69 ( V_52 , V_51 ) )
goto V_90;
V_52 -> V_75 &= ~ V_91 ;
V_52 -> V_73 = V_52 -> V_92 = NULL ;
V_74 = V_52 -> V_79 ;
if ( V_74 ) {
struct V_93 * V_93 = V_74 -> V_94 . V_95 -> V_96 ;
struct V_97 * V_98 = V_74 -> V_99 ;
F_70 ( V_74 ) ;
if ( V_52 -> V_75 & V_100 )
F_71 ( & V_93 -> V_101 ) ;
F_72 ( & V_98 -> V_102 ) ;
if ( V_52 -> V_75 & V_103 )
V_98 -> V_104 ++ ;
F_73 ( V_98 ) ;
F_74 ( V_52 , V_51 ) ;
F_75 ( V_98 ) ;
F_76 ( & V_98 -> V_102 ) ;
}
if ( F_77 ( V_52 ) )
F_78 ( V_52 ) ;
* V_54 = V_52 ;
V_54 = & V_52 -> V_73 ;
V_52 -> V_92 = V_53 ;
V_53 = V_52 ;
F_79 ( V_48 , V_52 , V_56 , V_57 ) ;
V_56 = & V_52 -> V_105 . V_106 ;
V_57 = & V_52 -> V_105 ;
V_48 -> V_70 ++ ;
V_58 = F_80 ( V_48 , V_49 , V_51 ) ;
if ( V_52 -> V_107 && V_52 -> V_107 -> V_108 )
V_52 -> V_107 -> V_108 ( V_52 ) ;
if ( V_58 )
goto V_42;
}
F_81 ( V_49 , V_48 ) ;
V_58 = 0 ;
V_42:
F_82 ( & V_48 -> V_62 ) ;
F_83 ( V_49 ) ;
F_82 ( & V_49 -> V_62 ) ;
return V_58 ;
V_90:
F_84 ( V_61 ) ;
V_88:
F_23 ( V_86 , V_52 ) ;
V_85:
V_58 = - V_109 ;
F_85 ( V_59 ) ;
goto V_42;
}
static inline int F_86 ( struct V_47 * V_48 )
{
V_48 -> V_110 = F_87 ( V_48 ) ;
if ( F_88 ( ! V_48 -> V_110 ) )
return - V_109 ;
return 0 ;
}
static inline void F_89 ( struct V_47 * V_48 )
{
F_90 ( V_48 , V_48 -> V_110 ) ;
}
static int T_2 F_91 ( char * V_111 )
{
V_112 =
( F_92 ( V_111 , NULL , 0 ) << V_113 ) &
V_114 ;
return 1 ;
}
static void F_93 ( struct V_47 * V_48 )
{
#ifdef F_94
F_95 ( & V_48 -> V_115 ) ;
F_96 ( & V_48 -> V_116 ) ;
#endif
}
static struct V_47 * F_97 ( struct V_47 * V_48 , struct V_6 * V_117 )
{
F_49 ( & V_48 -> V_118 , 1 ) ;
F_49 ( & V_48 -> V_119 , 1 ) ;
F_98 ( & V_48 -> V_62 ) ;
F_63 ( & V_48 -> V_120 ) ;
V_48 -> V_121 = ( V_25 -> V_48 ) ?
( V_25 -> V_48 -> V_121 & V_122 ) : V_112 ;
V_48 -> V_123 = NULL ;
V_48 -> V_124 = 0 ;
memset ( & V_48 -> V_125 , 0 , sizeof( V_48 -> V_125 ) ) ;
F_95 ( & V_48 -> V_126 ) ;
V_48 -> V_67 = V_127 ;
V_48 -> V_69 = ~ 0UL ;
F_93 ( V_48 ) ;
F_99 ( V_48 , V_117 ) ;
if ( F_100 ( ! F_86 ( V_48 ) ) ) {
V_48 -> V_128 = 0 ;
F_101 ( V_48 ) ;
return V_48 ;
}
F_102 ( V_48 ) ;
return NULL ;
}
static void F_103 ( struct V_47 * V_48 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_130 ; V_129 ++ ) {
long V_131 = F_104 ( & V_48 -> V_125 . V_132 [ V_129 ] ) ;
if ( F_88 ( V_131 ) )
F_105 ( V_133 L_2
L_3 , V_48 , V_129 , V_131 ) ;
}
#ifdef F_106
F_107 ( V_48 -> V_134 ) ;
#endif
}
struct V_47 * F_108 ( void )
{
struct V_47 * V_48 ;
V_48 = F_109 () ;
if ( ! V_48 )
return NULL ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
F_110 ( V_48 ) ;
return F_97 ( V_48 , V_25 ) ;
}
void F_111 ( struct V_47 * V_48 )
{
F_112 ( V_48 == & V_135 ) ;
F_89 ( V_48 ) ;
F_113 ( V_48 ) ;
F_114 ( V_48 ) ;
F_103 ( V_48 ) ;
F_102 ( V_48 ) ;
}
void F_115 ( struct V_47 * V_48 )
{
F_116 () ;
if ( F_25 ( & V_48 -> V_118 ) ) {
F_117 ( V_48 ) ;
F_118 ( V_48 ) ;
F_119 ( V_48 ) ;
F_120 ( V_48 ) ;
F_121 ( V_48 , NULL ) ;
if ( ! F_122 ( & V_48 -> V_120 ) ) {
F_123 ( & V_136 ) ;
F_124 ( & V_48 -> V_120 ) ;
F_125 ( & V_136 ) ;
}
F_126 ( V_48 ) ;
if ( V_48 -> V_137 )
F_127 ( V_48 -> V_137 -> V_138 ) ;
F_128 ( V_48 ) ;
}
}
void F_129 ( struct V_47 * V_48 )
{
V_48 -> V_139 ++ ;
}
void F_130 ( struct V_47 * V_48 )
{
V_48 -> V_139 -- ;
if ( ( V_48 -> V_139 == 0 ) && V_48 -> V_140 ) {
F_131 ( V_48 -> V_140 ) ;
V_48 -> V_140 = NULL ;
}
}
void F_121 ( struct V_47 * V_48 , struct V_74 * V_141 )
{
if ( V_141 )
F_70 ( V_141 ) ;
if ( V_48 -> V_140 )
F_131 ( V_48 -> V_140 ) ;
V_48 -> V_140 = V_141 ;
V_48 -> V_139 = 0 ;
}
struct V_74 * F_132 ( struct V_47 * V_48 )
{
struct V_74 * V_140 ;
F_133 ( & V_48 -> V_62 ) ;
V_140 = V_48 -> V_140 ;
if ( V_140 )
F_70 ( V_140 ) ;
F_134 ( & V_48 -> V_62 ) ;
return V_140 ;
}
static void F_135 ( struct V_47 * V_49 , struct V_47 * V_142 )
{
V_142 -> V_140 = F_132 ( V_49 ) ;
}
struct V_47 * F_136 ( struct V_6 * V_143 )
{
struct V_47 * V_48 ;
F_137 ( V_143 ) ;
V_48 = V_143 -> V_48 ;
if ( V_48 ) {
if ( V_143 -> V_121 & V_144 )
V_48 = NULL ;
else
F_138 ( & V_48 -> V_118 ) ;
}
F_139 ( V_143 ) ;
return V_48 ;
}
struct V_47 * F_140 ( struct V_6 * V_143 , unsigned int V_145 )
{
struct V_47 * V_48 ;
int V_41 ;
V_41 = F_141 ( & V_143 -> signal -> V_146 ) ;
if ( V_41 )
return F_142 ( V_41 ) ;
V_48 = F_136 ( V_143 ) ;
if ( V_48 && V_48 != V_25 -> V_48 &&
! F_143 ( V_143 , V_145 ) ) {
F_115 ( V_48 ) ;
V_48 = F_142 ( - V_147 ) ;
}
F_76 ( & V_143 -> signal -> V_146 ) ;
return V_48 ;
}
static void F_144 ( struct V_6 * V_7 )
{
struct V_148 * V_149 ;
F_137 ( V_7 ) ;
V_149 = V_7 -> V_150 ;
if ( F_100 ( V_149 ) ) {
V_7 -> V_150 = NULL ;
F_145 ( V_149 ) ;
}
F_139 ( V_7 ) ;
}
static int F_146 ( struct V_6 * V_151 ,
struct V_148 * V_149 )
{
int V_152 ;
F_147 () ;
V_152 = F_148 ( V_149 ) ;
F_149 () ;
if ( V_152 ) {
F_137 ( V_151 ) ;
V_151 -> V_150 = NULL ;
F_139 ( V_151 ) ;
}
F_150 ( V_151 ) ;
return V_152 ;
}
void F_151 ( struct V_6 * V_7 , struct V_47 * V_48 )
{
#ifdef F_152
if ( F_88 ( V_7 -> V_153 ) ) {
F_153 ( V_7 ) ;
V_7 -> V_153 = NULL ;
}
#ifdef F_154
if ( F_88 ( V_7 -> V_154 ) ) {
F_155 ( V_7 ) ;
V_7 -> V_154 = NULL ;
}
#endif
if ( F_88 ( ! F_122 ( & V_7 -> V_155 ) ) )
F_156 ( V_7 ) ;
#endif
F_157 ( V_7 , V_48 ) ;
if ( V_7 -> V_150 )
F_144 ( V_7 ) ;
if ( V_7 -> V_156 ) {
if ( ! ( V_7 -> V_121 & V_157 ) &&
F_28 ( & V_48 -> V_118 ) > 1 ) {
F_158 ( 0 , V_7 -> V_156 ) ;
F_159 ( V_7 -> V_156 , V_158 ,
1 , NULL , NULL , 0 ) ;
}
V_7 -> V_156 = NULL ;
}
}
struct V_47 * F_160 ( struct V_6 * V_7 )
{
struct V_47 * V_48 , * V_49 = V_25 -> V_48 ;
int V_41 ;
if ( ! V_49 )
return NULL ;
V_48 = F_109 () ;
if ( ! V_48 )
goto V_85;
memcpy ( V_48 , V_49 , sizeof( * V_48 ) ) ;
F_110 ( V_48 ) ;
V_48 -> V_159 = 0 ;
V_48 -> V_160 = 0 ;
#ifdef F_106
V_48 -> V_134 = NULL ;
#endif
if ( ! F_97 ( V_48 , V_7 ) )
goto V_85;
if ( F_161 ( V_7 , V_48 ) )
goto V_161;
F_135 ( V_49 , V_48 ) ;
V_41 = F_51 ( V_48 , V_49 ) ;
if ( V_41 )
goto V_162;
V_48 -> V_163 = F_162 ( V_48 ) ;
V_48 -> V_164 = V_48 -> V_78 ;
if ( V_48 -> V_137 && ! F_163 ( V_48 -> V_137 -> V_138 ) )
goto V_162;
return V_48 ;
V_162:
V_48 -> V_137 = NULL ;
F_115 ( V_48 ) ;
V_85:
return NULL ;
V_161:
F_89 ( V_48 ) ;
F_102 ( V_48 ) ;
return NULL ;
}
static int F_164 ( unsigned long V_165 , struct V_6 * V_7 )
{
struct V_47 * V_48 , * V_49 ;
int V_58 ;
V_7 -> V_166 = V_7 -> V_167 = 0 ;
V_7 -> V_168 = V_7 -> V_169 = 0 ;
#ifdef F_165
V_7 -> V_170 = V_7 -> V_168 + V_7 -> V_169 ;
#endif
V_7 -> V_48 = NULL ;
V_7 -> V_171 = NULL ;
V_49 = V_25 -> V_48 ;
if ( ! V_49 )
return 0 ;
if ( V_165 & V_172 ) {
F_138 ( & V_49 -> V_118 ) ;
V_48 = V_49 ;
goto V_173;
}
V_58 = - V_109 ;
V_48 = F_160 ( V_7 ) ;
if ( ! V_48 )
goto V_85;
V_173:
V_48 -> V_159 = 0 ;
V_48 -> V_160 = 0 ;
V_7 -> V_48 = V_48 ;
V_7 -> V_171 = V_48 ;
return 0 ;
V_85:
return V_58 ;
}
static int F_166 ( unsigned long V_165 , struct V_6 * V_7 )
{
struct V_174 * V_175 = V_25 -> V_175 ;
if ( V_165 & V_176 ) {
F_123 ( & V_175 -> V_177 ) ;
if ( V_175 -> V_178 ) {
F_125 ( & V_175 -> V_177 ) ;
return - V_179 ;
}
V_175 -> V_180 ++ ;
F_125 ( & V_175 -> V_177 ) ;
return 0 ;
}
V_7 -> V_175 = F_167 ( V_175 ) ;
if ( ! V_7 -> V_175 )
return - V_109 ;
return 0 ;
}
static int F_168 ( unsigned long V_165 , struct V_6 * V_7 )
{
struct V_181 * V_182 , * V_183 ;
int error = 0 ;
V_182 = V_25 -> V_184 ;
if ( ! V_182 )
goto V_42;
if ( V_165 & V_185 ) {
F_138 ( & V_182 -> V_132 ) ;
goto V_42;
}
V_183 = F_169 ( V_182 , & error ) ;
if ( ! V_183 )
goto V_42;
V_7 -> V_184 = V_183 ;
error = 0 ;
V_42:
return error ;
}
static int F_170 ( unsigned long V_165 , struct V_6 * V_7 )
{
#ifdef F_171
struct V_186 * V_187 = V_25 -> V_186 ;
struct V_186 * V_188 ;
if ( ! V_187 )
return 0 ;
if ( V_165 & V_189 ) {
V_7 -> V_186 = F_172 ( V_187 ) ;
if ( F_88 ( ! V_7 -> V_186 ) )
return - V_109 ;
} else if ( F_173 ( V_187 -> V_190 ) ) {
V_188 = F_174 ( V_7 , V_10 , V_191 ) ;
if ( F_88 ( ! V_188 ) )
return - V_109 ;
V_188 -> V_190 = V_187 -> V_190 ;
F_175 ( V_188 ) ;
}
#endif
return 0 ;
}
static int F_176 ( unsigned long V_165 , struct V_6 * V_7 )
{
struct V_192 * V_20 ;
if ( V_165 & V_193 ) {
F_138 ( & V_25 -> V_194 -> V_132 ) ;
return 0 ;
}
V_20 = F_62 ( V_195 , V_10 ) ;
F_177 ( V_7 -> V_194 , V_20 ) ;
if ( ! V_20 )
return - V_109 ;
F_49 ( & V_20 -> V_132 , 1 ) ;
memcpy ( V_20 -> V_196 , V_25 -> V_194 -> V_196 , sizeof( V_20 -> V_196 ) ) ;
return 0 ;
}
void F_178 ( struct V_192 * V_194 )
{
if ( F_25 ( & V_194 -> V_132 ) ) {
F_179 ( V_194 ) ;
F_23 ( V_195 , V_194 ) ;
}
}
static void F_180 ( struct V_19 * V_20 )
{
unsigned long V_197 ;
F_181 ( V_20 ) ;
V_197 = F_182 ( V_20 -> V_34 [ V_198 ] . V_36 ) ;
if ( V_197 != V_199 ) {
V_20 -> V_200 . V_201 = F_183 ( V_197 ) ;
V_20 -> V_202 . V_203 = 1 ;
}
F_63 ( & V_20 -> V_204 [ 0 ] ) ;
F_63 ( & V_20 -> V_204 [ 1 ] ) ;
F_63 ( & V_20 -> V_204 [ 2 ] ) ;
}
static int F_184 ( unsigned long V_165 , struct V_6 * V_7 )
{
struct V_19 * V_20 ;
if ( V_165 & V_205 )
return 0 ;
V_20 = F_185 ( V_21 , V_10 ) ;
V_7 -> signal = V_20 ;
if ( ! V_20 )
return - V_109 ;
V_20 -> V_206 = 1 ;
F_49 ( & V_20 -> V_207 , 1 ) ;
F_49 ( & V_20 -> V_22 , 1 ) ;
F_186 ( & V_20 -> V_208 ) ;
if ( V_165 & V_209 )
V_20 -> V_121 |= V_210 ;
V_20 -> V_211 = V_7 ;
F_187 ( & V_20 -> V_212 ) ;
F_63 ( & V_20 -> V_213 ) ;
F_188 ( & V_20 -> V_214 , V_215 , V_216 ) ;
V_20 -> V_214 . V_217 = V_218 ;
F_137 ( V_25 -> V_219 ) ;
memcpy ( V_20 -> V_34 , V_25 -> signal -> V_34 , sizeof V_20 -> V_34 ) ;
F_139 ( V_25 -> V_219 ) ;
F_180 ( V_20 ) ;
F_189 ( V_20 ) ;
F_190 ( V_20 ) ;
#ifdef F_191
F_98 ( & V_20 -> V_220 ) ;
#endif
V_20 -> V_221 = V_25 -> signal -> V_221 ;
V_20 -> V_222 = V_25 -> signal -> V_222 ;
V_20 -> V_223 = V_25 -> signal -> V_223 ;
V_20 -> V_224 = V_25 -> signal -> V_224 ||
V_25 -> signal -> V_225 ;
F_192 ( & V_20 -> V_146 ) ;
return 0 ;
}
static void F_193 ( unsigned long V_165 , struct V_6 * V_117 )
{
unsigned long V_226 = V_117 -> V_121 ;
V_226 &= ~ ( V_227 | V_228 ) ;
V_226 |= V_229 ;
V_117 -> V_121 = V_226 ;
}
static void F_194 ( struct V_6 * V_117 )
{
F_195 ( & V_117 -> V_230 ) ;
#ifdef F_196
F_197 ( & V_117 -> V_231 ) ;
V_117 -> V_232 = NULL ;
#endif
}
void F_99 ( struct V_47 * V_48 , struct V_6 * V_117 )
{
V_48 -> V_233 = V_117 ;
}
static void F_198 ( struct V_6 * V_7 )
{
V_7 -> V_200 . V_201 = 0 ;
V_7 -> V_200 . V_234 = 0 ;
V_7 -> V_200 . V_235 = 0 ;
F_63 ( & V_7 -> V_204 [ 0 ] ) ;
F_63 ( & V_7 -> V_204 [ 1 ] ) ;
F_63 ( & V_7 -> V_204 [ 2 ] ) ;
}
static struct V_6 * F_199 ( unsigned long V_165 ,
unsigned long V_236 ,
struct V_237 * V_238 ,
unsigned long V_239 ,
int T_3 * V_240 ,
struct V_241 * V_241 ,
int V_242 )
{
int V_58 ;
struct V_6 * V_117 ;
int V_243 = 0 ;
if ( ( V_165 & ( V_244 | V_176 ) ) == ( V_244 | V_176 ) )
return F_142 ( - V_245 ) ;
if ( ( V_165 & V_205 ) && ! ( V_165 & V_193 ) )
return F_142 ( - V_245 ) ;
if ( ( V_165 & V_193 ) && ! ( V_165 & V_172 ) )
return F_142 ( - V_245 ) ;
if ( ( V_165 & V_246 ) &&
V_25 -> signal -> V_121 & V_210 )
return F_142 ( - V_245 ) ;
V_58 = F_200 ( V_165 ) ;
if ( V_58 )
goto V_247;
V_58 = - V_109 ;
V_117 = F_38 ( V_25 ) ;
if ( ! V_117 )
goto V_247;
F_201 ( V_117 ) ;
F_194 ( V_117 ) ;
#ifdef F_202
F_203 ( ! V_117 -> V_248 ) ;
F_203 ( ! V_117 -> V_249 ) ;
#endif
V_58 = - V_179 ;
if ( F_28 ( & V_117 -> V_250 -> V_251 -> V_252 ) >=
F_204 ( V_117 , V_35 ) ) {
if ( ! F_205 ( V_253 ) && ! F_205 ( V_254 ) &&
V_117 -> V_250 -> V_251 != V_255 )
goto V_256;
}
V_25 -> V_121 &= ~ V_257 ;
V_58 = F_206 ( V_117 , V_165 ) ;
if ( V_58 < 0 )
goto V_256;
V_58 = - V_179 ;
if ( V_206 >= V_30 )
goto V_258;
if ( ! F_163 ( F_207 ( V_117 ) -> V_259 -> V_138 ) )
goto V_258;
V_117 -> V_260 = 0 ;
F_208 ( V_117 ) ;
F_193 ( V_165 , V_117 ) ;
F_63 ( & V_117 -> V_261 ) ;
F_63 ( & V_117 -> V_262 ) ;
F_209 ( V_117 ) ;
V_117 -> V_150 = NULL ;
F_95 ( & V_117 -> V_263 ) ;
F_187 ( & V_117 -> V_264 ) ;
V_117 -> V_265 = V_117 -> V_266 = V_117 -> V_267 = 0 ;
V_117 -> V_268 = V_117 -> V_269 = 0 ;
#ifndef F_210
V_117 -> V_270 = V_117 -> V_271 = 0 ;
#endif
#if F_211 ( V_272 )
memset ( & V_117 -> V_125 , 0 , sizeof( V_117 -> V_125 ) ) ;
#endif
V_117 -> V_273 = V_25 -> V_274 ;
F_212 ( & V_117 -> V_275 ) ;
F_213 ( V_117 ) ;
F_198 ( V_117 ) ;
F_214 ( & V_117 -> V_276 ) ;
V_117 -> V_277 = V_117 -> V_276 ;
F_215 ( & V_117 -> V_277 ) ;
V_117 -> V_186 = NULL ;
V_117 -> V_278 = NULL ;
if ( V_165 & V_205 )
F_216 ( V_25 ) ;
F_217 ( V_117 ) ;
#ifdef F_218
V_117 -> V_60 = F_64 ( V_117 -> V_60 ) ;
if ( F_67 ( V_117 -> V_60 ) ) {
V_58 = F_66 ( V_117 -> V_60 ) ;
V_117 -> V_60 = NULL ;
goto V_279;
}
F_219 ( V_117 ) ;
#endif
#ifdef F_220
V_117 -> V_280 = V_191 ;
V_117 -> V_281 = V_191 ;
F_221 ( & V_117 -> V_282 ) ;
#endif
#ifdef F_222
V_117 -> V_283 = 0 ;
#ifdef F_223
V_117 -> V_248 = 1 ;
#else
V_117 -> V_248 = 0 ;
#endif
V_117 -> V_284 = 0 ;
V_117 -> V_285 = 0 ;
V_117 -> V_286 = V_287 ;
V_117 -> V_288 = 0 ;
V_117 -> V_249 = 1 ;
V_117 -> V_289 = V_287 ;
V_117 -> V_290 = 0 ;
V_117 -> V_291 = 0 ;
V_117 -> V_292 = 0 ;
V_117 -> V_293 = 0 ;
V_117 -> V_294 = 0 ;
#endif
#ifdef F_224
V_117 -> V_295 = 0 ;
V_117 -> V_296 = 0 ;
V_117 -> V_297 = 0 ;
#endif
#ifdef F_225
V_117 -> V_298 = NULL ;
#endif
#ifdef F_226
V_117 -> V_299 . V_300 = 0 ;
V_117 -> V_299 . V_301 = NULL ;
#endif
F_227 ( V_117 ) ;
V_58 = F_228 ( V_117 ) ;
if ( V_58 )
goto V_302;
V_58 = F_229 ( V_117 ) ;
if ( V_58 )
goto V_302;
V_58 = F_230 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_303;
V_58 = F_168 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_304;
V_58 = F_166 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_305;
V_58 = F_176 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_306;
V_58 = F_184 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_307;
V_58 = F_164 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_308;
V_58 = F_231 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_309;
V_58 = F_170 ( V_165 , V_117 ) ;
if ( V_58 )
goto V_310;
V_58 = F_232 ( V_165 , V_236 , V_239 , V_117 , V_238 ) ;
if ( V_58 )
goto V_311;
if ( V_241 != & V_312 ) {
V_58 = - V_109 ;
V_241 = F_233 ( V_117 -> V_313 -> V_314 ) ;
if ( ! V_241 )
goto V_311;
}
V_117 -> V_241 = F_234 ( V_241 ) ;
V_117 -> V_315 = V_117 -> V_241 ;
if ( V_165 & V_205 )
V_117 -> V_315 = V_25 -> V_315 ;
V_117 -> V_316 = ( V_165 & V_317 ) ? V_240 : NULL ;
V_117 -> V_156 = ( V_165 & V_318 ) ? V_240 : NULL ;
#ifdef F_171
V_117 -> V_319 = NULL ;
#endif
#ifdef F_152
V_117 -> V_153 = NULL ;
#ifdef F_154
V_117 -> V_154 = NULL ;
#endif
F_63 ( & V_117 -> V_155 ) ;
V_117 -> V_320 = NULL ;
#endif
if ( ( V_165 & ( V_172 | V_321 ) ) == V_172 )
V_117 -> V_322 = V_117 -> V_323 = 0 ;
F_235 ( V_117 ) ;
F_236 ( V_117 , V_324 ) ;
#ifdef F_237
F_236 ( V_117 , F_237 ) ;
#endif
F_238 ( V_117 ) ;
if ( V_165 & V_205 )
V_117 -> V_325 = - 1 ;
else if ( V_165 & V_246 )
V_117 -> V_325 = V_25 -> V_219 -> V_325 ;
else
V_117 -> V_325 = ( V_165 & V_326 ) ;
V_117 -> V_327 = 0 ;
V_117 -> V_23 = 0 ;
V_117 -> V_328 = 0 ;
V_117 -> V_329 = 128 >> ( V_84 - 10 ) ;
V_117 -> V_330 = 0 ;
V_117 -> V_219 = V_117 ;
F_63 ( & V_117 -> V_331 ) ;
F_239 ( V_117 ) ;
V_243 = 1 ;
F_240 ( & V_1 ) ;
if ( V_165 & ( V_246 | V_205 ) ) {
V_117 -> V_332 = V_25 -> V_332 ;
V_117 -> V_333 = V_25 -> V_333 ;
} else {
V_117 -> V_332 = V_25 ;
V_117 -> V_333 = V_25 -> V_334 ;
}
F_123 ( & V_25 -> V_194 -> V_335 ) ;
F_241 () ;
if ( F_242 ( V_25 ) ) {
F_125 ( & V_25 -> V_194 -> V_335 ) ;
F_243 ( & V_1 ) ;
V_58 = - V_336 ;
goto V_337;
}
if ( V_165 & V_205 ) {
V_25 -> signal -> V_206 ++ ;
F_138 ( & V_25 -> signal -> V_207 ) ;
F_138 ( & V_25 -> signal -> V_22 ) ;
V_117 -> V_219 = V_25 -> V_219 ;
F_244 ( & V_117 -> V_331 , & V_117 -> V_219 -> V_331 ) ;
}
if ( F_100 ( V_117 -> V_241 ) ) {
F_245 ( V_117 , ( V_165 & V_338 ) || V_242 ) ;
if ( F_246 ( V_117 ) ) {
if ( F_247 ( V_241 ) )
V_117 -> V_313 -> V_314 -> V_339 = V_117 ;
V_117 -> signal -> V_340 = V_241 ;
V_117 -> signal -> V_341 = F_248 ( V_25 -> signal -> V_341 ) ;
F_249 ( V_117 , V_342 , F_250 ( V_25 ) ) ;
F_249 ( V_117 , V_343 , F_251 ( V_25 ) ) ;
F_252 ( & V_117 -> V_262 , & V_117 -> V_332 -> V_261 ) ;
F_244 ( & V_117 -> V_344 , & V_33 . V_344 ) ;
F_253 ( V_4 ) ;
}
F_249 ( V_117 , V_345 , V_241 ) ;
V_206 ++ ;
}
V_346 ++ ;
F_125 ( & V_25 -> V_194 -> V_335 ) ;
F_243 ( & V_1 ) ;
F_254 ( V_117 ) ;
F_255 ( V_117 ) ;
if ( V_165 & V_205 )
F_256 ( V_25 ) ;
F_257 ( V_117 ) ;
F_258 ( V_117 , V_165 ) ;
return V_117 ;
V_337:
if ( V_241 != & V_312 )
F_259 ( V_241 ) ;
V_311:
if ( V_117 -> V_186 )
F_260 ( V_117 ) ;
V_310:
if ( F_88 ( V_165 & V_209 ) )
F_261 ( V_117 -> V_313 -> V_314 ) ;
F_262 ( V_117 ) ;
V_309:
if ( V_117 -> V_48 )
F_115 ( V_117 -> V_48 ) ;
V_308:
if ( ! ( V_165 & V_205 ) )
F_20 ( V_117 -> signal ) ;
V_307:
F_178 ( V_117 -> V_194 ) ;
V_306:
F_263 ( V_117 ) ;
V_305:
F_264 ( V_117 ) ;
V_304:
F_265 ( V_117 ) ;
V_303:
F_266 ( V_117 ) ;
V_302:
F_267 ( V_117 ) ;
#ifdef F_218
F_84 ( V_117 -> V_60 ) ;
V_279:
#endif
if ( V_165 & V_205 )
F_256 ( V_25 ) ;
F_268 ( V_117 , V_243 ) ;
F_31 ( V_117 ) ;
F_127 ( F_207 ( V_117 ) -> V_259 -> V_138 ) ;
V_258:
F_71 ( & V_117 -> V_347 -> V_251 -> V_252 ) ;
F_30 ( V_117 ) ;
V_256:
F_16 ( V_117 ) ;
V_247:
return F_142 ( V_58 ) ;
}
static inline void F_269 ( struct V_348 * V_349 )
{
enum V_350 type ;
for ( type = V_345 ; type < V_351 ; ++ type ) {
F_270 ( & V_349 [ type ] . V_8 ) ;
V_349 [ type ] . V_241 = & V_312 ;
}
}
struct V_6 * T_4 F_271 ( int V_2 )
{
struct V_6 * V_143 ;
struct V_237 V_238 ;
V_143 = F_199 ( V_172 , 0 , F_272 ( & V_238 ) , 0 , NULL ,
& V_312 , 0 ) ;
if ( ! F_67 ( V_143 ) ) {
F_269 ( V_143 -> V_352 ) ;
F_273 ( V_143 , V_2 ) ;
}
return V_143 ;
}
long F_274 ( unsigned long V_165 ,
unsigned long V_236 ,
struct V_237 * V_238 ,
unsigned long V_239 ,
int T_3 * V_353 ,
int T_3 * V_240 )
{
struct V_6 * V_117 ;
int V_242 = 0 ;
long V_354 ;
if ( V_165 & V_355 ) {
if ( V_165 & V_205 )
return - V_245 ;
if ( ! F_205 ( V_253 ) || ! F_205 ( V_356 ) ||
! F_205 ( V_357 ) )
return - V_358 ;
}
if ( F_100 ( F_275 ( V_238 ) ) && ! ( V_165 & V_359 ) ) {
if ( V_165 & V_321 )
V_242 = V_360 ;
else if ( ( V_165 & V_326 ) != V_361 )
V_242 = V_362 ;
else
V_242 = V_363 ;
if ( F_100 ( ! F_276 ( V_25 , V_242 ) ) )
V_242 = 0 ;
}
V_117 = F_199 ( V_165 , V_236 , V_238 , V_239 ,
V_240 , NULL , V_242 ) ;
if ( ! F_67 ( V_117 ) ) {
struct V_148 V_149 ;
F_277 ( V_25 , V_117 ) ;
V_354 = F_278 ( V_117 ) ;
if ( V_165 & V_364 )
F_158 ( V_354 , V_353 ) ;
if ( V_165 & V_321 ) {
V_117 -> V_150 = & V_149 ;
F_279 ( & V_149 ) ;
F_280 ( V_117 ) ;
}
F_281 ( V_117 ) ;
if ( F_88 ( V_242 ) )
F_282 ( V_242 , V_354 ) ;
if ( V_165 & V_321 ) {
if ( ! F_146 ( V_117 , & V_149 ) )
F_282 ( V_365 , V_354 ) ;
}
} else {
V_354 = F_66 ( V_117 ) ;
}
return V_354 ;
}
static void F_283 ( void * V_366 )
{
struct V_192 * V_194 = V_366 ;
F_95 ( & V_194 -> V_335 ) ;
F_186 ( & V_194 -> V_367 ) ;
}
void T_2 F_284 ( void )
{
V_195 = F_36 ( L_4 ,
sizeof( struct V_192 ) , 0 ,
V_368 | V_28 | V_369 |
V_29 , F_283 ) ;
V_21 = F_36 ( L_5 ,
sizeof( struct V_19 ) , 0 ,
V_368 | V_28 | V_29 , NULL ) ;
V_370 = F_36 ( L_6 ,
sizeof( struct V_181 ) , 0 ,
V_368 | V_28 | V_29 , NULL ) ;
V_371 = F_36 ( L_7 ,
sizeof( struct V_174 ) , 0 ,
V_368 | V_28 | V_29 , NULL ) ;
V_372 = F_36 ( L_8 ,
sizeof( struct V_47 ) , V_373 ,
V_368 | V_28 | V_29 , NULL ) ;
V_86 = F_285 ( V_50 , V_28 ) ;
F_286 () ;
F_287 () ;
}
static int F_288 ( unsigned long V_374 )
{
if ( V_374 & ~ ( V_205 | V_176 | V_244 | V_193 |
V_172 | V_185 | V_375 |
V_376 | V_377 | V_378 ) )
return - V_245 ;
if ( V_374 & ( V_205 | V_193 | V_172 ) ) {
if ( F_28 ( & V_25 -> V_48 -> V_118 ) > 1 )
return - V_245 ;
}
return 0 ;
}
static int F_289 ( unsigned long V_374 , struct V_174 * * V_379 )
{
struct V_174 * V_175 = V_25 -> V_175 ;
if ( ! ( V_374 & V_176 ) || ! V_175 )
return 0 ;
if ( V_175 -> V_180 == 1 )
return 0 ;
* V_379 = F_167 ( V_175 ) ;
if ( ! * V_379 )
return - V_109 ;
return 0 ;
}
static int F_290 ( unsigned long V_374 , struct V_181 * * V_380 )
{
struct V_181 * V_381 = V_25 -> V_184 ;
int error = 0 ;
if ( ( V_374 & V_185 ) &&
( V_381 && F_28 ( & V_381 -> V_132 ) > 1 ) ) {
* V_380 = F_169 ( V_381 , & error ) ;
if ( ! * V_380 )
return error ;
}
return 0 ;
}
int F_291 ( struct V_181 * * V_382 )
{
struct V_6 * V_143 = V_25 ;
struct V_181 * V_383 = NULL ;
int error ;
error = F_290 ( V_185 , & V_383 ) ;
if ( error || ! V_383 ) {
* V_382 = NULL ;
return error ;
}
* V_382 = V_143 -> V_184 ;
F_137 ( V_143 ) ;
V_143 -> V_184 = V_383 ;
F_139 ( V_143 ) ;
return 0 ;
}
