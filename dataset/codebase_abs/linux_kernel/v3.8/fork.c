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
void __weak F_6 ( struct V_5 * V_6 )
{
}
static inline struct V_5 * F_7 ( int V_7 )
{
return F_8 ( V_8 , V_9 , V_7 ) ;
}
static inline void F_9 ( struct V_5 * V_6 )
{
F_10 ( V_8 , V_6 ) ;
}
void __weak F_11 ( struct V_10 * V_11 )
{
}
static struct V_10 * F_12 ( struct V_5 * V_6 ,
int V_7 )
{
struct V_12 * V_12 = F_13 ( V_7 , V_13 ,
V_14 ) ;
return V_12 ? F_14 ( V_12 ) : NULL ;
}
static inline void F_15 ( struct V_10 * V_11 )
{
F_16 ( ( unsigned long ) V_11 , V_14 ) ;
}
static struct V_10 * F_12 ( struct V_5 * V_6 ,
int V_7 )
{
return F_8 ( V_15 , V_16 , V_7 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_10 ( V_15 , V_11 ) ;
}
void F_17 ( void )
{
V_15 = F_18 ( L_1 , V_17 ,
V_17 , 0 , NULL ) ;
F_19 ( V_15 == NULL ) ;
}
static void F_20 ( struct V_10 * V_11 , int V_18 )
{
struct V_19 * V_19 = F_21 ( F_22 ( V_11 ) ) ;
F_23 ( V_19 , V_20 , V_18 ) ;
}
void F_24 ( struct V_5 * V_6 )
{
F_20 ( V_6 -> V_21 , - 1 ) ;
F_11 ( V_6 -> V_21 ) ;
F_15 ( V_6 -> V_21 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
F_6 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_28 ( struct V_22 * V_23 )
{
F_29 ( V_23 ) ;
F_30 ( V_23 ) ;
F_10 ( V_24 , V_23 ) ;
}
static inline void F_31 ( struct V_22 * V_23 )
{
if ( F_32 ( & V_23 -> V_25 ) )
F_28 ( V_23 ) ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( ! V_6 -> V_26 ) ;
F_34 ( F_35 ( & V_6 -> V_27 ) ) ;
F_34 ( V_6 == V_28 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_31 ( V_6 -> signal ) ;
if ( ! F_39 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_40 ( void ) { }
void T_1 F_41 ( unsigned long V_29 )
{
#ifndef F_42
#ifndef F_43
#define F_43 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , sizeof( struct V_5 ) ,
F_43 , V_30 | V_31 , NULL ) ;
#endif
F_40 () ;
V_32 = V_29 / ( 8 * V_17 / V_33 ) ;
if ( V_32 < 20 )
V_32 = 20 ;
V_34 . signal -> V_35 [ V_36 ] . V_37 = V_32 / 2 ;
V_34 . signal -> V_35 [ V_36 ] . V_38 = V_32 / 2 ;
V_34 . signal -> V_35 [ V_39 ] =
V_34 . signal -> V_35 [ V_36 ] ;
}
static struct V_5 * F_44 ( struct V_5 * V_40 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
unsigned long * V_41 ;
int V_7 = F_45 ( V_40 ) ;
int V_42 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_43;
V_42 = F_46 ( V_6 , V_40 ) ;
if ( V_42 )
goto V_44;
V_6 -> V_21 = V_11 ;
F_47 ( V_6 , V_40 ) ;
F_48 ( V_6 ) ;
F_49 ( V_6 ) ;
V_41 = F_50 ( V_6 ) ;
* V_41 = V_45 ;
#ifdef F_51
V_6 -> V_46 = F_52 () ;
#endif
F_53 ( & V_6 -> V_27 , 2 ) ;
#ifdef F_54
V_6 -> V_47 = 0 ;
#endif
V_6 -> V_48 = NULL ;
V_6 -> V_49 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_44:
F_15 ( V_11 ) ;
V_43:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_55 ( struct V_50 * V_51 , struct V_50 * V_52 )
{
struct V_53 * V_54 , * V_55 , * V_56 , * * V_57 ;
struct V_58 * * V_59 , * V_60 ;
int V_61 ;
unsigned long V_62 ;
struct V_63 * V_64 ;
F_56 () ;
F_57 ( & V_52 -> V_65 ) ;
F_58 ( V_52 ) ;
F_59 ( V_52 , V_51 ) ;
F_60 ( & V_51 -> V_65 , V_66 ) ;
V_51 -> V_67 = 0 ;
V_51 -> V_68 = NULL ;
V_51 -> V_69 = NULL ;
V_51 -> V_70 = V_52 -> V_71 ;
V_51 -> V_72 = ~ 0UL ;
V_51 -> V_73 = 0 ;
F_61 ( F_62 ( V_51 ) ) ;
V_51 -> V_74 = V_75 ;
V_59 = & V_51 -> V_74 . V_58 ;
V_60 = NULL ;
V_57 = & V_51 -> V_68 ;
V_61 = F_63 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_76;
V_61 = F_64 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_76;
V_56 = NULL ;
for ( V_54 = V_52 -> V_68 ; V_54 ; V_54 = V_54 -> V_77 ) {
struct V_78 * V_78 ;
if ( V_54 -> V_79 & V_80 ) {
F_65 ( V_51 , V_54 -> V_79 , V_54 -> V_81 ,
- F_66 ( V_54 ) ) ;
continue;
}
V_62 = 0 ;
if ( V_54 -> V_79 & V_82 ) {
unsigned long V_83 = F_66 ( V_54 ) ;
if ( F_67 ( V_52 , V_83 ) )
goto V_84;
V_62 = V_83 ;
}
V_55 = F_68 ( V_85 , V_9 ) ;
if ( ! V_55 )
goto V_84;
* V_55 = * V_54 ;
F_69 ( & V_55 -> V_86 ) ;
V_64 = F_70 ( F_71 ( V_54 ) ) ;
V_61 = F_72 ( V_64 ) ;
if ( F_73 ( V_64 ) )
goto V_87;
F_74 ( V_55 , V_64 ) ;
V_55 -> V_88 = V_51 ;
if ( F_75 ( V_55 , V_54 ) )
goto V_89;
V_55 -> V_79 &= ~ V_90 ;
V_55 -> V_77 = V_55 -> V_91 = NULL ;
V_78 = V_55 -> V_81 ;
if ( V_78 ) {
struct V_92 * V_92 = V_78 -> V_93 . V_94 -> V_95 ;
struct V_96 * V_97 = V_78 -> V_98 ;
F_76 ( V_78 ) ;
if ( V_55 -> V_79 & V_99 )
F_77 ( & V_92 -> V_100 ) ;
F_78 ( & V_97 -> V_101 ) ;
if ( V_55 -> V_79 & V_102 )
V_97 -> V_103 ++ ;
F_79 ( V_97 ) ;
if ( F_80 ( V_55 -> V_79 & V_104 ) )
F_81 ( V_55 ,
& V_97 -> V_105 ) ;
else
F_82 ( V_55 , V_54 ,
& V_97 -> V_106 ) ;
F_83 ( V_97 ) ;
F_84 ( & V_97 -> V_101 ) ;
}
if ( F_85 ( V_55 ) )
F_86 ( V_55 ) ;
* V_57 = V_55 ;
V_57 = & V_55 -> V_77 ;
V_55 -> V_91 = V_56 ;
V_56 = V_55 ;
F_87 ( V_51 , V_55 , V_59 , V_60 ) ;
V_59 = & V_55 -> V_107 . V_108 ;
V_60 = & V_55 -> V_107 ;
V_51 -> V_73 ++ ;
V_61 = F_88 ( V_51 , V_52 , V_54 ) ;
if ( V_55 -> V_109 && V_55 -> V_109 -> V_110 )
V_55 -> V_109 -> V_110 ( V_55 ) ;
if ( V_61 )
goto V_76;
}
F_89 ( V_52 , V_51 ) ;
V_61 = 0 ;
V_76:
F_90 ( & V_51 -> V_65 ) ;
F_91 ( V_52 ) ;
F_90 ( & V_52 -> V_65 ) ;
F_92 () ;
return V_61 ;
V_89:
F_93 ( V_64 ) ;
V_87:
F_10 ( V_85 , V_55 ) ;
V_84:
V_61 = - V_111 ;
F_94 ( V_62 ) ;
goto V_76;
}
static inline int F_95 ( struct V_50 * V_51 )
{
V_51 -> V_112 = F_96 ( V_51 ) ;
if ( F_80 ( ! V_51 -> V_112 ) )
return - V_111 ;
return 0 ;
}
static inline void F_97 ( struct V_50 * V_51 )
{
F_98 ( V_51 , V_51 -> V_112 ) ;
}
static int T_1 F_99 ( char * V_113 )
{
V_114 =
( F_100 ( V_113 , NULL , 0 ) << V_115 ) &
V_116 ;
return 1 ;
}
static void F_101 ( struct V_50 * V_51 )
{
#ifdef F_102
F_103 ( & V_51 -> V_117 ) ;
F_104 ( & V_51 -> V_118 ) ;
#endif
}
static struct V_50 * F_105 ( struct V_50 * V_51 , struct V_5 * V_119 )
{
F_53 ( & V_51 -> V_120 , 1 ) ;
F_53 ( & V_51 -> V_121 , 1 ) ;
F_106 ( & V_51 -> V_65 ) ;
F_69 ( & V_51 -> V_122 ) ;
V_51 -> V_123 = ( V_28 -> V_51 ) ?
( V_28 -> V_51 -> V_123 & V_124 ) : V_114 ;
V_51 -> V_125 = NULL ;
V_51 -> V_126 = 0 ;
memset ( & V_51 -> V_127 , 0 , sizeof( V_51 -> V_127 ) ) ;
F_103 ( & V_51 -> V_128 ) ;
V_51 -> V_70 = V_129 ;
V_51 -> V_72 = ~ 0UL ;
F_101 ( V_51 ) ;
F_107 ( V_51 , V_119 ) ;
if ( F_108 ( ! F_95 ( V_51 ) ) ) {
V_51 -> V_130 = 0 ;
F_109 ( V_51 ) ;
return V_51 ;
}
F_110 ( V_51 ) ;
return NULL ;
}
static void F_111 ( struct V_50 * V_51 )
{
int V_131 ;
for ( V_131 = 0 ; V_131 < V_132 ; V_131 ++ ) {
long V_133 = F_112 ( & V_51 -> V_127 . V_134 [ V_131 ] ) ;
if ( F_80 ( V_133 ) )
F_113 ( V_135 L_3
L_4 , V_51 , V_131 , V_133 ) ;
}
#ifdef F_114
F_115 ( V_51 -> V_136 ) ;
#endif
}
struct V_50 * F_116 ( void )
{
struct V_50 * V_51 ;
V_51 = F_117 () ;
if ( ! V_51 )
return NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
F_118 ( V_51 ) ;
return F_105 ( V_51 , V_28 ) ;
}
void F_119 ( struct V_50 * V_51 )
{
F_19 ( V_51 == & V_137 ) ;
F_97 ( V_51 ) ;
F_120 ( V_51 ) ;
F_121 ( V_51 ) ;
F_111 ( V_51 ) ;
F_110 ( V_51 ) ;
}
void F_122 ( struct V_50 * V_51 )
{
F_123 () ;
if ( F_32 ( & V_51 -> V_120 ) ) {
F_124 ( V_51 ) ;
F_125 ( V_51 ) ;
F_126 ( V_51 ) ;
F_127 ( V_51 ) ;
F_128 ( V_51 ) ;
F_129 ( V_51 , NULL ) ;
if ( ! F_130 ( & V_51 -> V_122 ) ) {
F_131 ( & V_138 ) ;
F_132 ( & V_51 -> V_122 ) ;
F_133 ( & V_138 ) ;
}
if ( V_51 -> V_139 )
F_134 ( V_51 -> V_139 -> V_140 ) ;
F_135 ( V_51 ) ;
}
}
void F_129 ( struct V_50 * V_51 , struct V_78 * V_141 )
{
if ( V_141 )
F_76 ( V_141 ) ;
if ( V_51 -> V_142 )
F_136 ( V_51 -> V_142 ) ;
V_51 -> V_142 = V_141 ;
}
struct V_78 * F_137 ( struct V_50 * V_51 )
{
struct V_78 * V_142 ;
F_138 ( & V_51 -> V_65 ) ;
V_142 = V_51 -> V_142 ;
if ( V_142 )
F_76 ( V_142 ) ;
F_139 ( & V_51 -> V_65 ) ;
return V_142 ;
}
static void F_140 ( struct V_50 * V_52 , struct V_50 * V_143 )
{
V_143 -> V_142 = F_137 ( V_52 ) ;
}
struct V_50 * F_141 ( struct V_5 * V_144 )
{
struct V_50 * V_51 ;
F_142 ( V_144 ) ;
V_51 = V_144 -> V_51 ;
if ( V_51 ) {
if ( V_144 -> V_123 & V_145 )
V_51 = NULL ;
else
F_143 ( & V_51 -> V_120 ) ;
}
F_144 ( V_144 ) ;
return V_51 ;
}
struct V_50 * F_145 ( struct V_5 * V_144 , unsigned int V_146 )
{
struct V_50 * V_51 ;
int V_42 ;
V_42 = F_146 ( & V_144 -> signal -> V_147 ) ;
if ( V_42 )
return F_147 ( V_42 ) ;
V_51 = F_141 ( V_144 ) ;
if ( V_51 && V_51 != V_28 -> V_51 &&
! F_148 ( V_144 , V_146 ) ) {
F_122 ( V_51 ) ;
V_51 = F_147 ( - V_148 ) ;
}
F_84 ( & V_144 -> signal -> V_147 ) ;
return V_51 ;
}
static void F_149 ( struct V_5 * V_6 )
{
struct V_149 * V_150 ;
F_142 ( V_6 ) ;
V_150 = V_6 -> V_151 ;
if ( F_108 ( V_150 ) ) {
V_6 -> V_151 = NULL ;
F_150 ( V_150 ) ;
}
F_144 ( V_6 ) ;
}
static int F_151 ( struct V_5 * V_152 ,
struct V_149 * V_150 )
{
int V_153 ;
F_152 () ;
V_153 = F_153 ( V_150 ) ;
F_154 () ;
if ( V_153 ) {
F_142 ( V_152 ) ;
V_152 -> V_151 = NULL ;
F_144 ( V_152 ) ;
}
F_155 ( V_152 ) ;
return V_153 ;
}
void F_156 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
#ifdef F_157
if ( F_80 ( V_6 -> V_154 ) ) {
F_158 ( V_6 ) ;
V_6 -> V_154 = NULL ;
}
#ifdef F_159
if ( F_80 ( V_6 -> V_155 ) ) {
F_160 ( V_6 ) ;
V_6 -> V_155 = NULL ;
}
#endif
if ( F_80 ( ! F_130 ( & V_6 -> V_156 ) ) )
F_161 ( V_6 ) ;
#endif
F_162 ( V_6 ) ;
F_163 ( V_6 , V_51 ) ;
if ( V_6 -> V_157 ) {
if ( ! ( V_6 -> V_123 & V_158 ) &&
F_35 ( & V_51 -> V_120 ) > 1 ) {
F_164 ( 0 , V_6 -> V_157 ) ;
F_165 ( V_6 -> V_157 , V_159 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_157 = NULL ;
}
if ( V_6 -> V_151 )
F_149 ( V_6 ) ;
}
struct V_50 * F_166 ( struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 = V_28 -> V_51 ;
int V_42 ;
if ( ! V_52 )
return NULL ;
V_51 = F_117 () ;
if ( ! V_51 )
goto V_84;
memcpy ( V_51 , V_52 , sizeof( * V_51 ) ) ;
F_118 ( V_51 ) ;
#ifdef F_114
V_51 -> V_136 = NULL ;
#endif
#ifdef F_167
V_51 -> V_160 = V_161 ;
#endif
if ( ! F_105 ( V_51 , V_6 ) )
goto V_84;
if ( F_168 ( V_6 , V_51 ) )
goto V_162;
F_140 ( V_52 , V_51 ) ;
V_42 = F_55 ( V_51 , V_52 ) ;
if ( V_42 )
goto V_163;
V_51 -> V_164 = F_169 ( V_51 ) ;
V_51 -> V_165 = V_51 -> V_166 ;
if ( V_51 -> V_139 && ! F_170 ( V_51 -> V_139 -> V_140 ) )
goto V_163;
return V_51 ;
V_163:
V_51 -> V_139 = NULL ;
F_122 ( V_51 ) ;
V_84:
return NULL ;
V_162:
F_97 ( V_51 ) ;
F_110 ( V_51 ) ;
return NULL ;
}
static int F_171 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 ;
int V_61 ;
V_6 -> V_168 = V_6 -> V_169 = 0 ;
V_6 -> V_170 = V_6 -> V_171 = 0 ;
#ifdef F_172
V_6 -> V_172 = V_6 -> V_170 + V_6 -> V_171 ;
#endif
V_6 -> V_51 = NULL ;
V_6 -> V_173 = NULL ;
V_52 = V_28 -> V_51 ;
if ( ! V_52 )
return 0 ;
if ( V_167 & V_174 ) {
F_143 ( & V_52 -> V_120 ) ;
V_51 = V_52 ;
goto V_175;
}
V_61 = - V_111 ;
V_51 = F_166 ( V_6 ) ;
if ( ! V_51 )
goto V_84;
V_175:
V_6 -> V_51 = V_51 ;
V_6 -> V_173 = V_51 ;
return 0 ;
V_84:
return V_61 ;
}
static int F_173 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_176 * V_177 = V_28 -> V_177 ;
if ( V_167 & V_178 ) {
F_131 ( & V_177 -> V_179 ) ;
if ( V_177 -> V_180 ) {
F_133 ( & V_177 -> V_179 ) ;
return - V_181 ;
}
V_177 -> V_182 ++ ;
F_133 ( & V_177 -> V_179 ) ;
return 0 ;
}
V_6 -> V_177 = F_174 ( V_177 ) ;
if ( ! V_6 -> V_177 )
return - V_111 ;
return 0 ;
}
static int F_175 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_183 * V_184 , * V_185 ;
int error = 0 ;
V_184 = V_28 -> V_186 ;
if ( ! V_184 )
goto V_76;
if ( V_167 & V_187 ) {
F_143 ( & V_184 -> V_134 ) ;
goto V_76;
}
V_185 = F_176 ( V_184 , & error ) ;
if ( ! V_185 )
goto V_76;
V_6 -> V_186 = V_185 ;
error = 0 ;
V_76:
return error ;
}
static int F_177 ( unsigned long V_167 , struct V_5 * V_6 )
{
#ifdef F_178
struct V_188 * V_189 = V_28 -> V_188 ;
struct V_188 * V_190 ;
if ( ! V_189 )
return 0 ;
if ( V_167 & V_191 ) {
F_179 ( V_189 ) ;
V_6 -> V_188 = V_189 ;
} else if ( F_180 ( V_189 -> V_192 ) ) {
V_190 = F_181 ( V_6 , V_9 , V_193 ) ;
if ( F_80 ( ! V_190 ) )
return - V_111 ;
V_190 -> V_192 = V_189 -> V_192 ;
F_182 ( V_190 ) ;
}
#endif
return 0 ;
}
static int F_183 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_194 * V_23 ;
if ( V_167 & V_195 ) {
F_143 ( & V_28 -> V_196 -> V_134 ) ;
return 0 ;
}
V_23 = F_68 ( V_197 , V_9 ) ;
F_184 ( V_6 -> V_196 , V_23 ) ;
if ( ! V_23 )
return - V_111 ;
F_53 ( & V_23 -> V_134 , 1 ) ;
memcpy ( V_23 -> V_198 , V_28 -> V_196 -> V_198 , sizeof( V_23 -> V_198 ) ) ;
return 0 ;
}
void F_185 ( struct V_194 * V_196 )
{
if ( F_32 ( & V_196 -> V_134 ) ) {
F_186 ( V_196 ) ;
F_10 ( V_197 , V_196 ) ;
}
}
static void F_187 ( struct V_22 * V_23 )
{
unsigned long V_199 ;
F_188 ( V_23 ) ;
V_199 = F_189 ( V_23 -> V_35 [ V_200 ] . V_37 ) ;
if ( V_199 != V_201 ) {
V_23 -> V_202 . V_203 = F_190 ( V_199 ) ;
V_23 -> V_204 . V_205 = 1 ;
}
F_69 ( & V_23 -> V_206 [ 0 ] ) ;
F_69 ( & V_23 -> V_206 [ 1 ] ) ;
F_69 ( & V_23 -> V_206 [ 2 ] ) ;
}
static int F_191 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_22 * V_23 ;
if ( V_167 & V_207 )
return 0 ;
V_23 = F_192 ( V_24 , V_9 ) ;
V_6 -> signal = V_23 ;
if ( ! V_23 )
return - V_111 ;
V_23 -> V_208 = 1 ;
F_53 ( & V_23 -> V_209 , 1 ) ;
F_53 ( & V_23 -> V_25 , 1 ) ;
F_193 ( & V_23 -> V_210 ) ;
V_23 -> V_211 = V_6 ;
F_194 ( & V_23 -> V_212 ) ;
F_69 ( & V_23 -> V_213 ) ;
F_195 ( & V_23 -> V_214 , V_215 , V_216 ) ;
V_23 -> V_214 . V_217 = V_218 ;
F_142 ( V_28 -> V_219 ) ;
memcpy ( V_23 -> V_35 , V_28 -> signal -> V_35 , sizeof V_23 -> V_35 ) ;
F_144 ( V_28 -> V_219 ) ;
F_187 ( V_23 ) ;
F_196 ( V_23 ) ;
F_197 ( V_23 ) ;
#ifdef F_198
F_106 ( & V_23 -> V_220 ) ;
#endif
V_23 -> V_221 = V_28 -> signal -> V_221 ;
V_23 -> V_222 = V_28 -> signal -> V_222 ;
V_23 -> V_223 = V_28 -> signal -> V_223 ||
V_28 -> signal -> V_224 ;
F_199 ( & V_23 -> V_147 ) ;
return 0 ;
}
static void F_200 ( unsigned long V_167 , struct V_5 * V_119 )
{
unsigned long V_225 = V_119 -> V_123 ;
V_225 &= ~ ( V_226 | V_227 ) ;
V_225 |= V_228 ;
V_119 -> V_123 = V_225 ;
}
static void F_201 ( struct V_5 * V_119 )
{
F_202 ( & V_119 -> V_229 ) ;
#ifdef F_203
F_204 ( & V_119 -> V_230 ) ;
V_119 -> V_231 = NULL ;
#endif
}
void F_107 ( struct V_50 * V_51 , struct V_5 * V_119 )
{
V_51 -> V_232 = V_119 ;
}
static void F_205 ( struct V_5 * V_6 )
{
V_6 -> V_202 . V_203 = 0 ;
V_6 -> V_202 . V_233 = 0 ;
V_6 -> V_202 . V_234 = 0 ;
F_69 ( & V_6 -> V_206 [ 0 ] ) ;
F_69 ( & V_6 -> V_206 [ 1 ] ) ;
F_69 ( & V_6 -> V_206 [ 2 ] ) ;
}
static struct V_5 * F_206 ( unsigned long V_167 ,
unsigned long V_235 ,
unsigned long V_236 ,
int T_2 * V_237 ,
struct V_238 * V_238 ,
int V_239 )
{
int V_61 ;
struct V_5 * V_119 ;
if ( ( V_167 & ( V_240 | V_178 ) ) == ( V_240 | V_178 ) )
return F_147 ( - V_241 ) ;
if ( ( V_167 & V_207 ) && ! ( V_167 & V_195 ) )
return F_147 ( - V_241 ) ;
if ( ( V_167 & V_195 ) && ! ( V_167 & V_174 ) )
return F_147 ( - V_241 ) ;
if ( ( V_167 & V_242 ) &&
V_28 -> signal -> V_123 & V_243 )
return F_147 ( - V_241 ) ;
if ( ( V_167 & ( V_174 | V_244 ) ) &&
( F_207 ( V_28 ) != V_28 -> V_245 -> V_246 ) )
return F_147 ( - V_241 ) ;
V_61 = F_208 ( V_167 ) ;
if ( V_61 )
goto V_247;
V_61 = - V_111 ;
V_119 = F_44 ( V_28 ) ;
if ( ! V_119 )
goto V_247;
F_209 ( V_119 ) ;
F_210 ( V_119 ) ;
F_201 ( V_119 ) ;
#ifdef F_211
F_212 ( ! V_119 -> V_248 ) ;
F_212 ( ! V_119 -> V_249 ) ;
#endif
V_61 = - V_181 ;
if ( F_35 ( & V_119 -> V_250 -> V_251 -> V_252 ) >=
F_213 ( V_119 , V_36 ) ) {
if ( ! F_214 ( V_253 ) && ! F_214 ( V_254 ) &&
V_119 -> V_250 -> V_251 != V_255 )
goto V_256;
}
V_28 -> V_123 &= ~ V_257 ;
V_61 = F_215 ( V_119 , V_167 ) ;
if ( V_61 < 0 )
goto V_256;
V_61 = - V_181 ;
if ( V_208 >= V_32 )
goto V_258;
if ( ! F_170 ( F_216 ( V_119 ) -> V_259 -> V_140 ) )
goto V_258;
V_119 -> V_260 = 0 ;
F_217 ( V_119 ) ;
F_200 ( V_167 , V_119 ) ;
F_69 ( & V_119 -> V_261 ) ;
F_69 ( & V_119 -> V_262 ) ;
F_218 ( V_119 ) ;
V_119 -> V_151 = NULL ;
F_103 ( & V_119 -> V_263 ) ;
F_194 ( & V_119 -> V_264 ) ;
V_119 -> V_265 = V_119 -> V_266 = V_119 -> V_267 = 0 ;
V_119 -> V_268 = V_119 -> V_269 = 0 ;
#ifndef F_219
V_119 -> V_270 . V_265 = V_119 -> V_270 . V_266 = 0 ;
#endif
#if F_220 ( V_271 )
memset ( & V_119 -> V_127 , 0 , sizeof( V_119 -> V_127 ) ) ;
#endif
V_119 -> V_272 = V_28 -> V_273 ;
F_221 ( & V_119 -> V_274 ) ;
F_222 ( V_119 ) ;
F_205 ( V_119 ) ;
F_223 ( & V_119 -> V_275 ) ;
V_119 -> V_276 = V_119 -> V_275 ;
F_224 ( & V_119 -> V_276 ) ;
V_119 -> V_188 = NULL ;
V_119 -> V_277 = NULL ;
if ( V_167 & V_207 )
F_225 ( V_28 ) ;
F_226 ( V_119 ) ;
#ifdef F_227
V_119 -> V_63 = F_70 ( V_119 -> V_63 ) ;
if ( F_73 ( V_119 -> V_63 ) ) {
V_61 = F_72 ( V_119 -> V_63 ) ;
V_119 -> V_63 = NULL ;
goto V_278;
}
F_228 ( V_119 ) ;
#endif
#ifdef F_229
V_119 -> V_279 = V_193 ;
V_119 -> V_280 = V_193 ;
F_230 ( & V_119 -> V_281 ) ;
#endif
#ifdef F_231
V_119 -> V_282 = 0 ;
V_119 -> V_248 = 0 ;
V_119 -> V_283 = 0 ;
V_119 -> V_284 = 0 ;
V_119 -> V_285 = V_286 ;
V_119 -> V_287 = 0 ;
V_119 -> V_249 = 1 ;
V_119 -> V_288 = V_286 ;
V_119 -> V_289 = 0 ;
V_119 -> V_290 = 0 ;
V_119 -> V_291 = 0 ;
V_119 -> V_292 = 0 ;
V_119 -> V_293 = 0 ;
#endif
#ifdef F_232
V_119 -> V_294 = 0 ;
V_119 -> V_295 = 0 ;
V_119 -> V_296 = 0 ;
#endif
#ifdef F_233
V_119 -> V_297 = NULL ;
#endif
#ifdef F_234
V_119 -> V_298 . V_299 = 0 ;
V_119 -> V_298 . V_300 = NULL ;
#endif
F_235 ( V_119 ) ;
V_61 = F_236 ( V_119 ) ;
if ( V_61 )
goto V_301;
V_61 = F_237 ( V_119 ) ;
if ( V_61 )
goto V_301;
V_61 = F_238 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_302;
V_61 = F_175 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_303;
V_61 = F_173 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_304;
V_61 = F_183 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_305;
V_61 = F_191 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_306;
V_61 = F_171 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_307;
V_61 = F_239 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_308;
V_61 = F_177 ( V_167 , V_119 ) ;
if ( V_61 )
goto V_309;
V_61 = F_240 ( V_167 , V_235 , V_236 , V_119 ) ;
if ( V_61 )
goto V_310;
if ( V_238 != & V_311 ) {
V_61 = - V_111 ;
V_238 = F_241 ( V_119 -> V_245 -> V_246 ) ;
if ( ! V_238 )
goto V_310;
}
V_119 -> V_238 = F_242 ( V_238 ) ;
V_119 -> V_312 = V_119 -> V_238 ;
if ( V_167 & V_207 )
V_119 -> V_312 = V_28 -> V_312 ;
V_119 -> V_313 = ( V_167 & V_314 ) ? V_237 : NULL ;
V_119 -> V_157 = ( V_167 & V_315 ) ? V_237 : NULL ;
#ifdef F_178
V_119 -> V_316 = NULL ;
#endif
#ifdef F_157
V_119 -> V_154 = NULL ;
#ifdef F_159
V_119 -> V_155 = NULL ;
#endif
F_69 ( & V_119 -> V_156 ) ;
V_119 -> V_317 = NULL ;
#endif
F_243 ( V_119 ) ;
if ( ( V_167 & ( V_174 | V_318 ) ) == V_174 )
V_119 -> V_319 = V_119 -> V_320 = 0 ;
F_244 ( V_119 ) ;
F_245 ( V_119 , V_321 ) ;
#ifdef F_246
F_245 ( V_119 , F_246 ) ;
#endif
F_247 ( V_119 ) ;
if ( V_167 & V_207 )
V_119 -> V_322 = - 1 ;
else if ( V_167 & V_242 )
V_119 -> V_322 = V_28 -> V_219 -> V_322 ;
else
V_119 -> V_322 = ( V_167 & V_323 ) ;
V_119 -> V_324 = 0 ;
V_119 -> V_26 = 0 ;
V_119 -> V_325 = 0 ;
V_119 -> V_326 = 128 >> ( V_327 - 10 ) ;
V_119 -> V_328 = 0 ;
V_119 -> V_219 = V_119 ;
F_69 ( & V_119 -> V_329 ) ;
V_119 -> V_330 = NULL ;
F_248 ( & V_1 ) ;
if ( V_167 & ( V_242 | V_207 ) ) {
V_119 -> V_331 = V_28 -> V_331 ;
V_119 -> V_332 = V_28 -> V_332 ;
} else {
V_119 -> V_331 = V_28 ;
V_119 -> V_332 = V_28 -> V_333 ;
}
F_131 ( & V_28 -> V_196 -> V_334 ) ;
F_249 () ;
if ( F_250 ( V_28 ) ) {
F_133 ( & V_28 -> V_196 -> V_334 ) ;
F_251 ( & V_1 ) ;
V_61 = - V_335 ;
goto V_336;
}
if ( V_167 & V_207 ) {
V_28 -> signal -> V_208 ++ ;
F_143 ( & V_28 -> signal -> V_209 ) ;
F_143 ( & V_28 -> signal -> V_25 ) ;
V_119 -> V_219 = V_28 -> V_219 ;
F_252 ( & V_119 -> V_329 , & V_119 -> V_219 -> V_329 ) ;
}
if ( F_108 ( V_119 -> V_238 ) ) {
F_253 ( V_119 , ( V_167 & V_337 ) || V_239 ) ;
if ( F_254 ( V_119 ) ) {
if ( F_255 ( V_238 ) ) {
F_256 ( V_238 ) -> V_338 = V_119 ;
V_119 -> signal -> V_123 |= V_243 ;
}
V_119 -> signal -> V_339 = V_238 ;
V_119 -> signal -> V_340 = F_257 ( V_28 -> signal -> V_340 ) ;
F_258 ( V_119 , V_341 , F_259 ( V_28 ) ) ;
F_258 ( V_119 , V_342 , F_260 ( V_28 ) ) ;
F_261 ( & V_119 -> V_262 , & V_119 -> V_331 -> V_261 ) ;
F_252 ( & V_119 -> V_343 , & V_34 . V_343 ) ;
F_262 ( V_4 ) ;
}
F_258 ( V_119 , V_344 , V_238 ) ;
V_208 ++ ;
}
V_345 ++ ;
F_133 ( & V_28 -> V_196 -> V_334 ) ;
F_251 ( & V_1 ) ;
F_263 ( V_119 ) ;
F_264 ( V_119 ) ;
if ( V_167 & V_207 )
F_265 ( V_28 ) ;
F_266 ( V_119 ) ;
F_267 ( V_119 , V_167 ) ;
return V_119 ;
V_336:
if ( V_238 != & V_311 )
F_268 ( V_238 ) ;
V_310:
if ( V_119 -> V_188 )
F_269 ( V_119 ) ;
V_309:
F_270 ( V_119 ) ;
V_308:
if ( V_119 -> V_51 )
F_122 ( V_119 -> V_51 ) ;
V_307:
if ( ! ( V_167 & V_207 ) )
F_28 ( V_119 -> signal ) ;
V_306:
F_185 ( V_119 -> V_196 ) ;
V_305:
F_271 ( V_119 ) ;
V_304:
F_272 ( V_119 ) ;
V_303:
F_273 ( V_119 ) ;
V_302:
F_274 ( V_119 ) ;
V_301:
F_275 ( V_119 ) ;
#ifdef F_227
F_93 ( V_119 -> V_63 ) ;
V_278:
#endif
if ( V_167 & V_207 )
F_265 ( V_28 ) ;
F_276 ( V_119 , 0 ) ;
F_38 ( V_119 ) ;
F_134 ( F_216 ( V_119 ) -> V_259 -> V_140 ) ;
V_258:
F_77 ( & V_119 -> V_346 -> V_251 -> V_252 ) ;
F_37 ( V_119 ) ;
V_256:
F_24 ( V_119 ) ;
V_247:
return F_147 ( V_61 ) ;
}
static inline void F_277 ( struct V_347 * V_348 )
{
enum V_349 type ;
for ( type = V_344 ; type < V_350 ; ++ type ) {
F_278 ( & V_348 [ type ] . V_7 ) ;
V_348 [ type ] . V_238 = & V_311 ;
}
}
struct V_5 * T_3 F_279 ( int V_2 )
{
struct V_5 * V_144 ;
V_144 = F_206 ( V_174 , 0 , 0 , NULL , & V_311 , 0 ) ;
if ( ! F_73 ( V_144 ) ) {
F_277 ( V_144 -> V_351 ) ;
F_280 ( V_144 , V_2 ) ;
}
return V_144 ;
}
long F_281 ( unsigned long V_167 ,
unsigned long V_235 ,
unsigned long V_236 ,
int T_2 * V_352 ,
int T_2 * V_237 )
{
struct V_5 * V_119 ;
int V_239 = 0 ;
long V_353 ;
if ( V_167 & ( V_354 | V_244 ) ) {
if ( V_167 & ( V_207 | V_242 ) )
return - V_241 ;
}
if ( ! ( V_167 & V_355 ) ) {
if ( V_167 & V_318 )
V_239 = V_356 ;
else if ( ( V_167 & V_323 ) != V_357 )
V_239 = V_358 ;
else
V_239 = V_359 ;
if ( F_108 ( ! F_282 ( V_28 , V_239 ) ) )
V_239 = 0 ;
}
V_119 = F_206 ( V_167 , V_235 , V_236 ,
V_237 , NULL , V_239 ) ;
if ( ! F_73 ( V_119 ) ) {
struct V_149 V_150 ;
F_283 ( V_28 , V_119 ) ;
V_353 = F_284 ( V_119 ) ;
if ( V_167 & V_360 )
F_164 ( V_353 , V_352 ) ;
if ( V_167 & V_318 ) {
V_119 -> V_151 = & V_150 ;
F_285 ( & V_150 ) ;
F_286 ( V_119 ) ;
}
F_287 ( V_119 ) ;
if ( F_80 ( V_239 ) )
F_288 ( V_239 , V_353 ) ;
if ( V_167 & V_318 ) {
if ( ! F_151 ( V_119 , & V_150 ) )
F_288 ( V_361 , V_353 ) ;
}
} else {
V_353 = F_72 ( V_119 ) ;
}
return V_353 ;
}
T_4 F_289 ( int (* F_290)( void * ) , void * V_362 , unsigned long V_123 )
{
return F_281 ( V_123 | V_174 | V_355 , ( unsigned long ) F_290 ,
( unsigned long ) V_362 , NULL , NULL ) ;
}
static void F_291 ( void * V_363 )
{
struct V_194 * V_196 = V_363 ;
F_103 ( & V_196 -> V_334 ) ;
F_193 ( & V_196 -> V_364 ) ;
}
void T_1 F_292 ( void )
{
V_197 = F_18 ( L_5 ,
sizeof( struct V_194 ) , 0 ,
V_365 | V_30 | V_366 |
V_31 , F_291 ) ;
V_24 = F_18 ( L_6 ,
sizeof( struct V_22 ) , 0 ,
V_365 | V_30 | V_31 , NULL ) ;
V_367 = F_18 ( L_7 ,
sizeof( struct V_183 ) , 0 ,
V_365 | V_30 | V_31 , NULL ) ;
V_368 = F_18 ( L_8 ,
sizeof( struct V_176 ) , 0 ,
V_365 | V_30 | V_31 , NULL ) ;
V_369 = F_18 ( L_9 ,
sizeof( struct V_50 ) , V_370 ,
V_365 | V_30 | V_31 , NULL ) ;
V_85 = F_293 ( V_53 , V_30 ) ;
F_294 () ;
F_295 () ;
}
static int F_296 ( unsigned long V_371 )
{
if ( V_371 & ~ ( V_207 | V_178 | V_240 | V_195 |
V_174 | V_187 | V_372 |
V_373 | V_374 | V_375 |
V_354 | V_244 ) )
return - V_241 ;
if ( V_371 & ( V_207 | V_195 | V_174 ) ) {
if ( F_35 ( & V_28 -> V_51 -> V_120 ) > 1 )
return - V_241 ;
}
return 0 ;
}
static int F_297 ( unsigned long V_371 , struct V_176 * * V_376 )
{
struct V_176 * V_177 = V_28 -> V_177 ;
if ( ! ( V_371 & V_178 ) || ! V_177 )
return 0 ;
if ( V_177 -> V_182 == 1 )
return 0 ;
* V_376 = F_174 ( V_177 ) ;
if ( ! * V_376 )
return - V_111 ;
return 0 ;
}
static int F_298 ( unsigned long V_371 , struct V_183 * * V_377 )
{
struct V_183 * V_378 = V_28 -> V_186 ;
int error = 0 ;
if ( ( V_371 & V_187 ) &&
( V_378 && F_35 ( & V_378 -> V_134 ) > 1 ) ) {
* V_377 = F_176 ( V_378 , & error ) ;
if ( ! * V_377 )
return error ;
}
return 0 ;
}
int F_299 ( struct V_183 * * V_379 )
{
struct V_5 * V_144 = V_28 ;
struct V_183 * V_380 = NULL ;
int error ;
error = F_298 ( V_187 , & V_380 ) ;
if ( error || ! V_380 ) {
* V_379 = NULL ;
return error ;
}
* V_379 = V_144 -> V_186 ;
F_142 ( V_144 ) ;
V_144 -> V_186 = V_380 ;
F_144 ( V_144 ) ;
return 0 ;
}
