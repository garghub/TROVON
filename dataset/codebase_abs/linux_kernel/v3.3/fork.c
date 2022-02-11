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
struct V_47 * F_136 ( struct V_6 * V_138 , unsigned int V_140 )
{
struct V_47 * V_48 ;
int V_41 ;
V_41 = F_137 ( & V_138 -> signal -> V_141 ) ;
if ( V_41 )
return F_138 ( V_41 ) ;
V_48 = F_132 ( V_138 ) ;
if ( V_48 && V_48 != V_25 -> V_48 &&
! F_139 ( V_138 , V_140 ) ) {
F_111 ( V_48 ) ;
V_48 = F_138 ( - V_142 ) ;
}
F_75 ( & V_138 -> signal -> V_141 ) ;
return V_48 ;
}
static void F_140 ( struct V_6 * V_7 )
{
struct V_143 * V_144 ;
F_133 ( V_7 ) ;
V_144 = V_7 -> V_145 ;
if ( F_99 ( V_144 ) ) {
V_7 -> V_145 = NULL ;
F_141 ( V_144 ) ;
}
F_135 ( V_7 ) ;
}
static int F_142 ( struct V_6 * V_146 ,
struct V_143 * V_144 )
{
int V_147 ;
F_143 () ;
V_147 = F_144 ( V_144 ) ;
F_145 () ;
if ( V_147 ) {
F_133 ( V_146 ) ;
V_146 -> V_145 = NULL ;
F_135 ( V_146 ) ;
}
F_146 ( V_146 ) ;
return V_147 ;
}
void F_147 ( struct V_6 * V_7 , struct V_47 * V_48 )
{
#ifdef F_148
if ( F_87 ( V_7 -> V_148 ) ) {
F_149 ( V_7 ) ;
V_7 -> V_148 = NULL ;
}
#ifdef F_150
if ( F_87 ( V_7 -> V_149 ) ) {
F_151 ( V_7 ) ;
V_7 -> V_149 = NULL ;
}
#endif
if ( F_87 ( ! F_118 ( & V_7 -> V_150 ) ) )
F_152 ( V_7 ) ;
#endif
F_153 ( V_7 , V_48 ) ;
if ( V_7 -> V_145 )
F_140 ( V_7 ) ;
if ( V_7 -> V_151 ) {
if ( ! ( V_7 -> V_121 & V_152 ) &&
F_28 ( & V_48 -> V_118 ) > 1 ) {
F_154 ( 0 , V_7 -> V_151 ) ;
F_155 ( V_7 -> V_151 , V_153 ,
1 , NULL , NULL , 0 ) ;
}
V_7 -> V_151 = NULL ;
}
}
struct V_47 * F_156 ( struct V_6 * V_7 )
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
V_48 -> V_154 = 0 ;
V_48 -> V_155 = 0 ;
#ifdef F_109
V_48 -> V_130 = NULL ;
#endif
if ( ! F_96 ( V_48 , V_7 ) )
goto V_85;
if ( F_157 ( V_7 , V_48 ) )
goto V_156;
F_131 ( V_49 , V_48 ) ;
V_41 = F_50 ( V_48 , V_49 ) ;
if ( V_41 )
goto V_157;
V_48 -> V_158 = F_158 ( V_48 ) ;
V_48 -> V_159 = V_48 -> V_78 ;
if ( V_48 -> V_132 && ! F_159 ( V_48 -> V_132 -> V_133 ) )
goto V_157;
return V_48 ;
V_157:
V_48 -> V_132 = NULL ;
F_111 ( V_48 ) ;
V_85:
return NULL ;
V_156:
F_88 ( V_48 ) ;
F_101 ( V_48 ) ;
return NULL ;
}
static int F_160 ( unsigned long V_160 , struct V_6 * V_7 )
{
struct V_47 * V_48 , * V_49 ;
int V_58 ;
V_7 -> V_161 = V_7 -> V_162 = 0 ;
V_7 -> V_163 = V_7 -> V_164 = 0 ;
#ifdef F_161
V_7 -> V_165 = V_7 -> V_163 + V_7 -> V_164 ;
#endif
V_7 -> V_48 = NULL ;
V_7 -> V_166 = NULL ;
V_49 = V_25 -> V_48 ;
if ( ! V_49 )
return 0 ;
if ( V_160 & V_167 ) {
F_134 ( & V_49 -> V_118 ) ;
V_48 = V_49 ;
goto V_168;
}
V_58 = - V_109 ;
V_48 = F_156 ( V_7 ) ;
if ( ! V_48 )
goto V_85;
V_168:
V_48 -> V_154 = 0 ;
V_48 -> V_155 = 0 ;
V_7 -> V_48 = V_48 ;
V_7 -> V_166 = V_48 ;
return 0 ;
V_85:
return V_58 ;
}
static int F_162 ( unsigned long V_160 , struct V_6 * V_7 )
{
struct V_169 * V_170 = V_25 -> V_170 ;
if ( V_160 & V_171 ) {
F_119 ( & V_170 -> V_172 ) ;
if ( V_170 -> V_173 ) {
F_121 ( & V_170 -> V_172 ) ;
return - V_174 ;
}
V_170 -> V_175 ++ ;
F_121 ( & V_170 -> V_172 ) ;
return 0 ;
}
V_7 -> V_170 = F_163 ( V_170 ) ;
if ( ! V_7 -> V_170 )
return - V_109 ;
return 0 ;
}
static int F_164 ( unsigned long V_160 , struct V_6 * V_7 )
{
struct V_176 * V_177 , * V_178 ;
int error = 0 ;
V_177 = V_25 -> V_179 ;
if ( ! V_177 )
goto V_42;
if ( V_160 & V_180 ) {
F_134 ( & V_177 -> V_181 ) ;
goto V_42;
}
V_178 = F_165 ( V_177 , & error ) ;
if ( ! V_178 )
goto V_42;
V_7 -> V_179 = V_178 ;
error = 0 ;
V_42:
return error ;
}
static int F_166 ( unsigned long V_160 , struct V_6 * V_7 )
{
#ifdef F_167
struct V_182 * V_183 = V_25 -> V_182 ;
struct V_182 * V_184 ;
if ( ! V_183 )
return 0 ;
if ( V_160 & V_185 ) {
V_7 -> V_182 = F_168 ( V_183 ) ;
if ( F_87 ( ! V_7 -> V_182 ) )
return - V_109 ;
} else if ( F_169 ( V_183 -> V_186 ) ) {
V_184 = F_170 ( V_7 , V_10 , V_187 ) ;
if ( F_87 ( ! V_184 ) )
return - V_109 ;
V_184 -> V_186 = V_183 -> V_186 ;
F_171 ( V_184 ) ;
}
#endif
return 0 ;
}
static int F_172 ( unsigned long V_160 , struct V_6 * V_7 )
{
struct V_188 * V_20 ;
if ( V_160 & V_189 ) {
F_134 ( & V_25 -> V_190 -> V_181 ) ;
return 0 ;
}
V_20 = F_61 ( V_191 , V_10 ) ;
F_173 ( V_7 -> V_190 , V_20 ) ;
if ( ! V_20 )
return - V_109 ;
F_48 ( & V_20 -> V_181 , 1 ) ;
memcpy ( V_20 -> V_192 , V_25 -> V_190 -> V_192 , sizeof( V_20 -> V_192 ) ) ;
return 0 ;
}
void F_174 ( struct V_188 * V_190 )
{
if ( F_25 ( & V_190 -> V_181 ) ) {
F_175 ( V_190 ) ;
F_23 ( V_191 , V_190 ) ;
}
}
static void F_176 ( struct V_19 * V_20 )
{
unsigned long V_193 ;
F_177 ( V_20 ) ;
V_193 = F_178 ( V_20 -> V_34 [ V_194 ] . V_36 ) ;
if ( V_193 != V_195 ) {
V_20 -> V_196 . V_197 = F_179 ( V_193 ) ;
V_20 -> V_198 . V_199 = 1 ;
}
F_62 ( & V_20 -> V_200 [ 0 ] ) ;
F_62 ( & V_20 -> V_200 [ 1 ] ) ;
F_62 ( & V_20 -> V_200 [ 2 ] ) ;
}
static int F_180 ( unsigned long V_160 , struct V_6 * V_7 )
{
struct V_19 * V_20 ;
if ( V_160 & V_201 )
return 0 ;
V_20 = F_181 ( V_21 , V_10 ) ;
V_7 -> signal = V_20 ;
if ( ! V_20 )
return - V_109 ;
V_20 -> V_202 = 1 ;
F_48 ( & V_20 -> V_203 , 1 ) ;
F_48 ( & V_20 -> V_22 , 1 ) ;
F_182 ( & V_20 -> V_204 ) ;
if ( V_160 & V_205 )
V_20 -> V_121 |= V_206 ;
V_20 -> V_207 = V_7 ;
F_183 ( & V_20 -> V_208 ) ;
F_62 ( & V_20 -> V_209 ) ;
F_184 ( & V_20 -> V_210 , V_211 , V_212 ) ;
V_20 -> V_210 . V_213 = V_214 ;
F_133 ( V_25 -> V_215 ) ;
memcpy ( V_20 -> V_34 , V_25 -> signal -> V_34 , sizeof V_20 -> V_34 ) ;
F_135 ( V_25 -> V_215 ) ;
F_176 ( V_20 ) ;
F_185 ( V_20 ) ;
F_186 ( V_20 ) ;
#ifdef F_187
F_97 ( & V_20 -> V_216 ) ;
#endif
V_20 -> V_217 = V_25 -> signal -> V_217 ;
V_20 -> V_218 = V_25 -> signal -> V_218 ;
V_20 -> V_219 = V_25 -> signal -> V_219 ;
F_188 ( & V_20 -> V_141 ) ;
return 0 ;
}
static void F_189 ( unsigned long V_160 , struct V_6 * V_117 )
{
unsigned long V_220 = V_117 -> V_121 ;
V_220 &= ~ ( V_221 | V_222 ) ;
V_220 |= V_223 ;
V_117 -> V_121 = V_220 ;
}
static void F_190 ( struct V_6 * V_117 )
{
F_191 ( & V_117 -> V_224 ) ;
#ifdef F_192
F_193 ( & V_117 -> V_225 ) ;
V_117 -> V_226 = NULL ;
#endif
}
void F_98 ( struct V_47 * V_48 , struct V_6 * V_117 )
{
V_48 -> V_227 = V_117 ;
}
static void F_194 ( struct V_6 * V_7 )
{
V_7 -> V_196 . V_197 = 0 ;
V_7 -> V_196 . V_228 = 0 ;
V_7 -> V_196 . V_229 = 0 ;
F_62 ( & V_7 -> V_200 [ 0 ] ) ;
F_62 ( & V_7 -> V_200 [ 1 ] ) ;
F_62 ( & V_7 -> V_200 [ 2 ] ) ;
}
static struct V_6 * F_195 ( unsigned long V_160 ,
unsigned long V_230 ,
struct V_231 * V_232 ,
unsigned long V_233 ,
int T_3 * V_234 ,
struct V_235 * V_235 ,
int V_236 )
{
int V_58 ;
struct V_6 * V_117 ;
int V_237 = 0 ;
if ( ( V_160 & ( V_238 | V_171 ) ) == ( V_238 | V_171 ) )
return F_138 ( - V_239 ) ;
if ( ( V_160 & V_201 ) && ! ( V_160 & V_189 ) )
return F_138 ( - V_239 ) ;
if ( ( V_160 & V_189 ) && ! ( V_160 & V_167 ) )
return F_138 ( - V_239 ) ;
if ( ( V_160 & V_240 ) &&
V_25 -> signal -> V_121 & V_206 )
return F_138 ( - V_239 ) ;
V_58 = F_196 ( V_160 ) ;
if ( V_58 )
goto V_241;
V_58 = - V_109 ;
V_117 = F_37 ( V_25 ) ;
if ( ! V_117 )
goto V_241;
F_197 ( V_117 ) ;
F_190 ( V_117 ) ;
#ifdef F_198
F_199 ( ! V_117 -> V_242 ) ;
F_199 ( ! V_117 -> V_243 ) ;
#endif
V_58 = - V_174 ;
if ( F_28 ( & V_117 -> V_244 -> V_245 -> V_246 ) >=
F_200 ( V_117 , V_35 ) ) {
if ( ! F_201 ( V_247 ) && ! F_201 ( V_248 ) &&
V_117 -> V_244 -> V_245 != V_249 )
goto V_250;
}
V_25 -> V_121 &= ~ V_251 ;
V_58 = F_202 ( V_117 , V_160 ) ;
if ( V_58 < 0 )
goto V_250;
V_58 = - V_174 ;
if ( V_202 >= V_30 )
goto V_252;
if ( ! F_159 ( F_203 ( V_117 ) -> V_253 -> V_133 ) )
goto V_252;
V_117 -> V_254 = 0 ;
F_204 ( V_117 ) ;
F_189 ( V_160 , V_117 ) ;
F_62 ( & V_117 -> V_255 ) ;
F_62 ( & V_117 -> V_256 ) ;
F_205 ( V_117 ) ;
V_117 -> V_145 = NULL ;
F_94 ( & V_117 -> V_257 ) ;
F_183 ( & V_117 -> V_258 ) ;
V_117 -> V_259 = V_117 -> V_260 = V_117 -> V_261 = 0 ;
V_117 -> V_262 = V_117 -> V_263 = 0 ;
#ifndef F_206
V_117 -> V_264 = V_117 -> V_265 = 0 ;
#endif
#if F_207 ( V_266 )
memset ( & V_117 -> V_125 , 0 , sizeof( V_117 -> V_125 ) ) ;
#endif
V_117 -> V_267 = V_25 -> V_268 ;
F_208 ( & V_117 -> V_269 ) ;
F_209 ( V_117 ) ;
F_194 ( V_117 ) ;
F_210 ( & V_117 -> V_270 ) ;
V_117 -> V_271 = V_117 -> V_270 ;
F_211 ( & V_117 -> V_271 ) ;
V_117 -> V_182 = NULL ;
V_117 -> V_272 = NULL ;
if ( V_160 & V_201 )
F_212 ( V_25 ) ;
F_213 ( V_117 ) ;
#ifdef F_214
V_117 -> V_60 = F_63 ( V_117 -> V_60 ) ;
if ( F_66 ( V_117 -> V_60 ) ) {
V_58 = F_65 ( V_117 -> V_60 ) ;
V_117 -> V_60 = NULL ;
goto V_273;
}
F_215 ( V_117 ) ;
#endif
#ifdef F_216
V_117 -> V_274 = V_187 ;
V_117 -> V_275 = V_187 ;
#endif
#ifdef F_217
V_117 -> V_276 = 0 ;
#ifdef F_218
V_117 -> V_242 = 1 ;
#else
V_117 -> V_242 = 0 ;
#endif
V_117 -> V_277 = 0 ;
V_117 -> V_278 = 0 ;
V_117 -> V_279 = V_280 ;
V_117 -> V_281 = 0 ;
V_117 -> V_243 = 1 ;
V_117 -> V_282 = V_280 ;
V_117 -> V_283 = 0 ;
V_117 -> V_284 = 0 ;
V_117 -> V_285 = 0 ;
V_117 -> V_286 = 0 ;
V_117 -> V_287 = 0 ;
#endif
#ifdef F_219
V_117 -> V_288 = 0 ;
V_117 -> V_289 = 0 ;
V_117 -> V_290 = 0 ;
#endif
#ifdef F_220
V_117 -> V_291 = NULL ;
#endif
#ifdef F_221
V_117 -> V_292 . V_293 = 0 ;
V_117 -> V_292 . V_294 = NULL ;
#endif
F_222 ( V_117 ) ;
V_58 = F_223 ( V_117 ) ;
if ( V_58 )
goto V_295;
V_58 = F_224 ( V_117 ) ;
if ( V_58 )
goto V_295;
V_58 = F_225 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_296;
V_58 = F_164 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_297;
V_58 = F_162 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_298;
V_58 = F_172 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_299;
V_58 = F_180 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_300;
V_58 = F_160 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_301;
V_58 = F_226 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_302;
V_58 = F_166 ( V_160 , V_117 ) ;
if ( V_58 )
goto V_303;
V_58 = F_227 ( V_160 , V_230 , V_233 , V_117 , V_232 ) ;
if ( V_58 )
goto V_304;
if ( V_235 != & V_305 ) {
V_58 = - V_109 ;
V_235 = F_228 ( V_117 -> V_306 -> V_307 ) ;
if ( ! V_235 )
goto V_304;
}
V_117 -> V_235 = F_229 ( V_235 ) ;
V_117 -> V_308 = V_117 -> V_235 ;
if ( V_160 & V_201 )
V_117 -> V_308 = V_25 -> V_308 ;
V_117 -> V_309 = ( V_160 & V_310 ) ? V_234 : NULL ;
V_117 -> V_151 = ( V_160 & V_311 ) ? V_234 : NULL ;
#ifdef F_167
V_117 -> V_312 = NULL ;
#endif
#ifdef F_148
V_117 -> V_148 = NULL ;
#ifdef F_150
V_117 -> V_149 = NULL ;
#endif
F_62 ( & V_117 -> V_150 ) ;
V_117 -> V_313 = NULL ;
#endif
if ( ( V_160 & ( V_167 | V_314 ) ) == V_167 )
V_117 -> V_315 = V_117 -> V_316 = 0 ;
F_230 ( V_117 ) ;
F_231 ( V_117 , V_317 ) ;
#ifdef F_232
F_231 ( V_117 , F_232 ) ;
#endif
F_233 ( V_117 ) ;
V_117 -> V_318 = ( V_160 & V_201 ) ? - 1 : ( V_160 & V_319 ) ;
V_117 -> V_320 = 0 ;
V_117 -> V_23 = 0 ;
V_117 -> V_321 = 0 ;
V_117 -> V_322 = 128 >> ( V_84 - 10 ) ;
V_117 -> V_323 = 0 ;
V_117 -> V_215 = V_117 ;
F_62 ( & V_117 -> V_324 ) ;
F_234 ( V_117 ) ;
V_237 = 1 ;
F_235 ( & V_1 ) ;
if ( V_160 & ( V_240 | V_201 ) ) {
V_117 -> V_325 = V_25 -> V_325 ;
V_117 -> V_326 = V_25 -> V_326 ;
} else {
V_117 -> V_325 = V_25 ;
V_117 -> V_326 = V_25 -> V_327 ;
}
F_119 ( & V_25 -> V_190 -> V_328 ) ;
F_236 () ;
if ( F_237 ( V_25 ) ) {
F_121 ( & V_25 -> V_190 -> V_328 ) ;
F_238 ( & V_1 ) ;
V_58 = - V_329 ;
goto V_330;
}
if ( V_160 & V_201 ) {
V_25 -> signal -> V_202 ++ ;
F_134 ( & V_25 -> signal -> V_203 ) ;
F_134 ( & V_25 -> signal -> V_22 ) ;
V_117 -> V_215 = V_25 -> V_215 ;
F_239 ( & V_117 -> V_324 , & V_117 -> V_215 -> V_324 ) ;
}
if ( F_99 ( V_117 -> V_235 ) ) {
F_240 ( V_117 , ( V_160 & V_331 ) || V_236 ) ;
if ( F_241 ( V_117 ) ) {
if ( F_242 ( V_235 ) )
V_117 -> V_306 -> V_307 -> V_332 = V_117 ;
V_117 -> signal -> V_333 = V_235 ;
V_117 -> signal -> V_334 = F_243 ( V_25 -> signal -> V_334 ) ;
F_244 ( V_117 , V_335 , F_245 ( V_25 ) ) ;
F_244 ( V_117 , V_336 , F_246 ( V_25 ) ) ;
F_247 ( & V_117 -> V_256 , & V_117 -> V_325 -> V_255 ) ;
F_239 ( & V_117 -> V_337 , & V_33 . V_337 ) ;
F_248 ( V_4 ) ;
}
F_244 ( V_117 , V_338 , V_235 ) ;
V_202 ++ ;
}
V_339 ++ ;
F_121 ( & V_25 -> V_190 -> V_328 ) ;
F_238 ( & V_1 ) ;
F_249 ( V_117 ) ;
F_250 ( V_117 ) ;
if ( V_160 & V_201 )
F_251 ( V_25 ) ;
F_252 ( V_117 ) ;
F_253 ( V_117 , V_160 ) ;
return V_117 ;
V_330:
if ( V_235 != & V_305 )
F_254 ( V_235 ) ;
V_304:
if ( V_117 -> V_182 )
F_255 ( V_117 ) ;
V_303:
F_256 ( V_117 ) ;
V_302:
if ( V_117 -> V_48 )
F_111 ( V_117 -> V_48 ) ;
V_301:
if ( ! ( V_160 & V_201 ) )
F_20 ( V_117 -> signal ) ;
V_300:
F_174 ( V_117 -> V_190 ) ;
V_299:
F_257 ( V_117 ) ;
V_298:
F_258 ( V_117 ) ;
V_297:
F_259 ( V_117 ) ;
V_296:
F_260 ( V_117 ) ;
V_295:
F_261 ( V_117 ) ;
#ifdef F_214
F_83 ( V_117 -> V_60 ) ;
V_273:
#endif
if ( V_160 & V_201 )
F_251 ( V_25 ) ;
F_262 ( V_117 , V_237 ) ;
F_30 ( V_117 ) ;
F_123 ( F_203 ( V_117 ) -> V_253 -> V_133 ) ;
V_252:
F_70 ( & V_117 -> V_340 -> V_245 -> V_246 ) ;
F_29 ( V_117 ) ;
V_250:
F_16 ( V_117 ) ;
V_241:
return F_138 ( V_58 ) ;
}
static inline void F_263 ( struct V_341 * V_342 )
{
enum V_343 type ;
for ( type = V_338 ; type < V_344 ; ++ type ) {
F_264 ( & V_342 [ type ] . V_8 ) ;
V_342 [ type ] . V_235 = & V_305 ;
}
}
struct V_6 * T_4 F_265 ( int V_2 )
{
struct V_6 * V_138 ;
struct V_231 V_232 ;
V_138 = F_195 ( V_167 , 0 , F_266 ( & V_232 ) , 0 , NULL ,
& V_305 , 0 ) ;
if ( ! F_66 ( V_138 ) ) {
F_263 ( V_138 -> V_345 ) ;
F_267 ( V_138 , V_2 ) ;
}
return V_138 ;
}
long F_268 ( unsigned long V_160 ,
unsigned long V_230 ,
struct V_231 * V_232 ,
unsigned long V_233 ,
int T_3 * V_346 ,
int T_3 * V_234 )
{
struct V_6 * V_117 ;
int V_236 = 0 ;
long V_347 ;
if ( V_160 & V_348 ) {
if ( V_160 & V_201 )
return - V_239 ;
if ( ! F_201 ( V_247 ) || ! F_201 ( V_349 ) ||
! F_201 ( V_350 ) )
return - V_351 ;
}
if ( F_99 ( F_269 ( V_232 ) ) && ! ( V_160 & V_352 ) ) {
if ( V_160 & V_314 )
V_236 = V_353 ;
else if ( ( V_160 & V_319 ) != V_354 )
V_236 = V_355 ;
else
V_236 = V_356 ;
if ( F_99 ( ! F_270 ( V_25 , V_236 ) ) )
V_236 = 0 ;
}
V_117 = F_195 ( V_160 , V_230 , V_232 , V_233 ,
V_234 , NULL , V_236 ) ;
if ( ! F_66 ( V_117 ) ) {
struct V_143 V_144 ;
F_271 ( V_25 , V_117 ) ;
V_347 = F_272 ( V_117 ) ;
if ( V_160 & V_357 )
F_154 ( V_347 , V_346 ) ;
if ( V_160 & V_314 ) {
V_117 -> V_145 = & V_144 ;
F_273 ( & V_144 ) ;
F_274 ( V_117 ) ;
}
F_275 ( V_117 ) ;
if ( F_87 ( V_236 ) )
F_276 ( V_236 , V_347 ) ;
if ( V_160 & V_314 ) {
if ( ! F_142 ( V_117 , & V_144 ) )
F_276 ( V_358 , V_347 ) ;
}
} else {
V_347 = F_65 ( V_117 ) ;
}
return V_347 ;
}
static void F_277 ( void * V_359 )
{
struct V_188 * V_190 = V_359 ;
F_94 ( & V_190 -> V_328 ) ;
F_182 ( & V_190 -> V_360 ) ;
}
void T_2 F_278 ( void )
{
V_191 = F_35 ( L_2 ,
sizeof( struct V_188 ) , 0 ,
V_361 | V_28 | V_362 |
V_29 , F_277 ) ;
V_21 = F_35 ( L_3 ,
sizeof( struct V_19 ) , 0 ,
V_361 | V_28 | V_29 , NULL ) ;
V_363 = F_35 ( L_4 ,
sizeof( struct V_176 ) , 0 ,
V_361 | V_28 | V_29 , NULL ) ;
V_364 = F_35 ( L_5 ,
sizeof( struct V_169 ) , 0 ,
V_361 | V_28 | V_29 , NULL ) ;
V_365 = F_35 ( L_6 ,
sizeof( struct V_47 ) , V_366 ,
V_361 | V_28 | V_29 , NULL ) ;
V_86 = F_279 ( V_50 , V_28 ) ;
F_280 () ;
F_281 () ;
}
static int F_282 ( unsigned long V_367 )
{
if ( V_367 & ~ ( V_201 | V_171 | V_238 | V_189 |
V_167 | V_180 | V_368 |
V_369 | V_370 | V_371 ) )
return - V_239 ;
if ( V_367 & ( V_201 | V_189 | V_167 ) ) {
if ( F_28 ( & V_25 -> V_48 -> V_118 ) > 1 )
return - V_239 ;
}
return 0 ;
}
static int F_283 ( unsigned long V_367 , struct V_169 * * V_372 )
{
struct V_169 * V_170 = V_25 -> V_170 ;
if ( ! ( V_367 & V_171 ) || ! V_170 )
return 0 ;
if ( V_170 -> V_175 == 1 )
return 0 ;
* V_372 = F_163 ( V_170 ) ;
if ( ! * V_372 )
return - V_109 ;
return 0 ;
}
static int F_284 ( unsigned long V_367 , struct V_176 * * V_373 )
{
struct V_176 * V_374 = V_25 -> V_179 ;
int error = 0 ;
if ( ( V_367 & V_180 ) &&
( V_374 && F_28 ( & V_374 -> V_181 ) > 1 ) ) {
* V_373 = F_165 ( V_374 , & error ) ;
if ( ! * V_373 )
return error ;
}
return 0 ;
}
int F_285 ( struct V_176 * * V_375 )
{
struct V_6 * V_138 = V_25 ;
struct V_176 * V_376 = NULL ;
int error ;
error = F_284 ( V_180 , & V_376 ) ;
if ( error || ! V_376 ) {
* V_375 = NULL ;
return error ;
}
* V_375 = V_138 -> V_179 ;
F_133 ( V_138 ) ;
V_138 -> V_179 = V_376 ;
F_135 ( V_138 ) ;
return 0 ;
}
