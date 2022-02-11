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
return F_8 ( V_15 , V_13 , V_7 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_10 ( V_15 , V_11 ) ;
}
void F_17 ( void )
{
V_15 = F_18 ( L_1 , V_16 ,
V_16 , 0 , NULL ) ;
F_19 ( V_15 == NULL ) ;
}
static void F_20 ( struct V_10 * V_11 , int V_17 )
{
struct V_18 * V_18 = F_21 ( F_22 ( V_11 ) ) ;
F_23 ( V_18 , V_19 , V_17 ) ;
}
void F_24 ( struct V_5 * V_6 )
{
F_20 ( V_6 -> V_20 , - 1 ) ;
F_11 ( V_6 -> V_20 ) ;
F_15 ( V_6 -> V_20 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
F_6 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_28 ( struct V_21 * V_22 )
{
F_29 ( V_22 ) ;
F_30 ( V_22 ) ;
F_10 ( V_23 , V_22 ) ;
}
static inline void F_31 ( struct V_21 * V_22 )
{
if ( F_32 ( & V_22 -> V_24 ) )
F_28 ( V_22 ) ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( ! V_6 -> V_25 ) ;
F_34 ( F_35 ( & V_6 -> V_26 ) ) ;
F_34 ( V_6 == V_27 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_31 ( V_6 -> signal ) ;
if ( ! F_39 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_40 ( void ) { }
void T_1 F_41 ( unsigned long V_28 )
{
#ifndef F_42
#ifndef F_43
#define F_43 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , sizeof( struct V_5 ) ,
F_43 , V_29 | V_30 , NULL ) ;
#endif
F_40 () ;
V_31 = V_28 / ( 8 * V_16 / V_32 ) ;
if ( V_31 < 20 )
V_31 = 20 ;
V_33 . signal -> V_34 [ V_35 ] . V_36 = V_31 / 2 ;
V_33 . signal -> V_34 [ V_35 ] . V_37 = V_31 / 2 ;
V_33 . signal -> V_34 [ V_38 ] =
V_33 . signal -> V_34 [ V_35 ] ;
}
static struct V_5 * F_44 ( struct V_5 * V_39 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
unsigned long * V_40 ;
int V_7 = F_45 ( V_39 ) ;
int V_41 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_42;
V_41 = F_46 ( V_6 , V_39 ) ;
if ( V_41 )
goto V_43;
V_6 -> V_20 = V_11 ;
F_47 ( V_6 , V_39 ) ;
F_48 ( V_6 ) ;
F_49 ( V_6 ) ;
V_40 = F_50 ( V_6 ) ;
* V_40 = V_44 ;
#ifdef F_51
V_6 -> V_45 = F_52 () ;
#endif
F_53 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_54
V_6 -> V_46 = 0 ;
#endif
V_6 -> V_47 = NULL ;
V_6 -> V_48 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_43:
F_15 ( V_11 ) ;
V_42:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_55 ( struct V_49 * V_50 , struct V_49 * V_51 )
{
struct V_52 * V_53 , * V_54 , * V_55 , * * V_56 ;
struct V_57 * * V_58 , * V_59 ;
int V_60 ;
unsigned long V_61 ;
struct V_62 * V_63 ;
F_56 ( & V_51 -> V_64 ) ;
F_57 ( V_51 ) ;
F_58 ( V_51 , V_50 ) ;
F_59 ( & V_50 -> V_64 , V_65 ) ;
V_50 -> V_66 = 0 ;
V_50 -> V_67 = NULL ;
V_50 -> V_68 = NULL ;
V_50 -> V_69 = V_51 -> V_70 ;
V_50 -> V_71 = ~ 0UL ;
V_50 -> V_72 = 0 ;
F_60 ( F_61 ( V_50 ) ) ;
V_50 -> V_73 = V_74 ;
V_58 = & V_50 -> V_73 . V_57 ;
V_59 = NULL ;
V_56 = & V_50 -> V_67 ;
V_60 = F_62 ( V_50 , V_51 ) ;
if ( V_60 )
goto V_75;
V_60 = F_63 ( V_50 , V_51 ) ;
if ( V_60 )
goto V_75;
V_55 = NULL ;
for ( V_53 = V_51 -> V_67 ; V_53 ; V_53 = V_53 -> V_76 ) {
struct V_77 * V_77 ;
if ( V_53 -> V_78 & V_79 ) {
F_64 ( V_50 , V_53 -> V_78 , V_53 -> V_80 ,
- F_65 ( V_53 ) ) ;
continue;
}
V_61 = 0 ;
if ( V_53 -> V_78 & V_81 ) {
unsigned long V_82 = F_65 ( V_53 ) ;
if ( F_66 ( V_51 , V_82 ) )
goto V_83;
V_61 = V_82 ;
}
V_54 = F_67 ( V_84 , V_9 ) ;
if ( ! V_54 )
goto V_83;
* V_54 = * V_53 ;
F_68 ( & V_54 -> V_85 ) ;
V_63 = F_69 ( F_70 ( V_53 ) ) ;
V_60 = F_71 ( V_63 ) ;
if ( F_72 ( V_63 ) )
goto V_86;
F_73 ( V_54 , V_63 ) ;
V_54 -> V_87 = V_50 ;
if ( F_74 ( V_54 , V_53 ) )
goto V_88;
V_54 -> V_78 &= ~ V_89 ;
V_54 -> V_76 = V_54 -> V_90 = NULL ;
V_77 = V_54 -> V_80 ;
if ( V_77 ) {
struct V_91 * V_91 = V_77 -> V_92 . V_93 -> V_94 ;
struct V_95 * V_96 = V_77 -> V_97 ;
F_75 ( V_77 ) ;
if ( V_54 -> V_78 & V_98 )
F_76 ( & V_91 -> V_99 ) ;
F_77 ( & V_96 -> V_100 ) ;
if ( V_54 -> V_78 & V_101 )
V_96 -> V_102 ++ ;
F_78 ( V_96 ) ;
if ( F_79 ( V_54 -> V_78 & V_103 ) )
F_80 ( V_54 ,
& V_96 -> V_104 ) ;
else
F_81 ( V_54 , V_53 ,
& V_96 -> V_105 ) ;
F_82 ( V_96 ) ;
F_83 ( & V_96 -> V_100 ) ;
}
if ( F_84 ( V_54 ) )
F_85 ( V_54 ) ;
* V_56 = V_54 ;
V_56 = & V_54 -> V_76 ;
V_54 -> V_90 = V_55 ;
V_55 = V_54 ;
F_86 ( V_50 , V_54 , V_58 , V_59 ) ;
V_58 = & V_54 -> V_106 . V_107 ;
V_59 = & V_54 -> V_106 ;
V_50 -> V_72 ++ ;
V_60 = F_87 ( V_50 , V_51 , V_53 ) ;
if ( V_54 -> V_108 && V_54 -> V_108 -> V_109 )
V_54 -> V_108 -> V_109 ( V_54 ) ;
if ( V_60 )
goto V_75;
}
F_88 ( V_51 , V_50 ) ;
V_60 = 0 ;
V_75:
F_89 ( & V_50 -> V_64 ) ;
F_90 ( V_51 ) ;
F_89 ( & V_51 -> V_64 ) ;
return V_60 ;
V_88:
F_91 ( V_63 ) ;
V_86:
F_10 ( V_84 , V_54 ) ;
V_83:
V_60 = - V_110 ;
F_92 ( V_61 ) ;
goto V_75;
}
static inline int F_93 ( struct V_49 * V_50 )
{
V_50 -> V_111 = F_94 ( V_50 ) ;
if ( F_79 ( ! V_50 -> V_111 ) )
return - V_110 ;
return 0 ;
}
static inline void F_95 ( struct V_49 * V_50 )
{
F_96 ( V_50 , V_50 -> V_111 ) ;
}
static int T_1 F_97 ( char * V_112 )
{
V_113 =
( F_98 ( V_112 , NULL , 0 ) << V_114 ) &
V_115 ;
return 1 ;
}
static void F_99 ( struct V_49 * V_50 )
{
#ifdef F_100
F_101 ( & V_50 -> V_116 ) ;
F_102 ( & V_50 -> V_117 ) ;
#endif
}
static struct V_49 * F_103 ( struct V_49 * V_50 , struct V_5 * V_118 )
{
F_53 ( & V_50 -> V_119 , 1 ) ;
F_53 ( & V_50 -> V_120 , 1 ) ;
F_104 ( & V_50 -> V_64 ) ;
F_68 ( & V_50 -> V_121 ) ;
V_50 -> V_122 = ( V_27 -> V_50 ) ?
( V_27 -> V_50 -> V_122 & V_123 ) : V_113 ;
V_50 -> V_124 = NULL ;
V_50 -> V_125 = 0 ;
memset ( & V_50 -> V_126 , 0 , sizeof( V_50 -> V_126 ) ) ;
F_101 ( & V_50 -> V_127 ) ;
V_50 -> V_69 = V_128 ;
V_50 -> V_71 = ~ 0UL ;
F_99 ( V_50 ) ;
F_105 ( V_50 , V_118 ) ;
if ( F_106 ( ! F_93 ( V_50 ) ) ) {
V_50 -> V_129 = 0 ;
F_107 ( V_50 ) ;
return V_50 ;
}
F_108 ( V_50 ) ;
return NULL ;
}
static void F_109 ( struct V_49 * V_50 )
{
int V_130 ;
for ( V_130 = 0 ; V_130 < V_131 ; V_130 ++ ) {
long V_132 = F_110 ( & V_50 -> V_126 . V_133 [ V_130 ] ) ;
if ( F_79 ( V_132 ) )
F_111 ( V_134 L_3
L_4 , V_50 , V_130 , V_132 ) ;
}
#ifdef F_112
F_113 ( V_50 -> V_135 ) ;
#endif
}
struct V_49 * F_114 ( void )
{
struct V_49 * V_50 ;
V_50 = F_115 () ;
if ( ! V_50 )
return NULL ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
F_116 ( V_50 ) ;
return F_103 ( V_50 , V_27 ) ;
}
void F_117 ( struct V_49 * V_50 )
{
F_19 ( V_50 == & V_136 ) ;
F_95 ( V_50 ) ;
F_118 ( V_50 ) ;
F_119 ( V_50 ) ;
F_109 ( V_50 ) ;
F_108 ( V_50 ) ;
}
void F_120 ( struct V_49 * V_50 )
{
F_121 () ;
if ( F_32 ( & V_50 -> V_119 ) ) {
F_122 ( V_50 ) ;
F_123 ( V_50 ) ;
F_124 ( V_50 ) ;
F_125 ( V_50 ) ;
F_126 ( V_50 ) ;
F_127 ( V_50 , NULL ) ;
if ( ! F_128 ( & V_50 -> V_121 ) ) {
F_129 ( & V_137 ) ;
F_130 ( & V_50 -> V_121 ) ;
F_131 ( & V_137 ) ;
}
if ( V_50 -> V_138 )
F_132 ( V_50 -> V_138 -> V_139 ) ;
F_133 ( V_50 ) ;
}
}
void F_127 ( struct V_49 * V_50 , struct V_77 * V_140 )
{
if ( V_140 )
F_75 ( V_140 ) ;
if ( V_50 -> V_141 )
F_134 ( V_50 -> V_141 ) ;
V_50 -> V_141 = V_140 ;
}
struct V_77 * F_135 ( struct V_49 * V_50 )
{
struct V_77 * V_141 ;
F_136 ( & V_50 -> V_64 ) ;
V_141 = V_50 -> V_141 ;
if ( V_141 )
F_75 ( V_141 ) ;
F_137 ( & V_50 -> V_64 ) ;
return V_141 ;
}
static void F_138 ( struct V_49 * V_51 , struct V_49 * V_142 )
{
V_142 -> V_141 = F_135 ( V_51 ) ;
}
struct V_49 * F_139 ( struct V_5 * V_143 )
{
struct V_49 * V_50 ;
F_140 ( V_143 ) ;
V_50 = V_143 -> V_50 ;
if ( V_50 ) {
if ( V_143 -> V_122 & V_144 )
V_50 = NULL ;
else
F_141 ( & V_50 -> V_119 ) ;
}
F_142 ( V_143 ) ;
return V_50 ;
}
struct V_49 * F_143 ( struct V_5 * V_143 , unsigned int V_145 )
{
struct V_49 * V_50 ;
int V_41 ;
V_41 = F_144 ( & V_143 -> signal -> V_146 ) ;
if ( V_41 )
return F_145 ( V_41 ) ;
V_50 = F_139 ( V_143 ) ;
if ( V_50 && V_50 != V_27 -> V_50 &&
! F_146 ( V_143 , V_145 ) ) {
F_120 ( V_50 ) ;
V_50 = F_145 ( - V_147 ) ;
}
F_83 ( & V_143 -> signal -> V_146 ) ;
return V_50 ;
}
static void F_147 ( struct V_5 * V_6 )
{
struct V_148 * V_149 ;
F_140 ( V_6 ) ;
V_149 = V_6 -> V_150 ;
if ( F_106 ( V_149 ) ) {
V_6 -> V_150 = NULL ;
F_148 ( V_149 ) ;
}
F_142 ( V_6 ) ;
}
static int F_149 ( struct V_5 * V_151 ,
struct V_148 * V_149 )
{
int V_152 ;
F_150 () ;
V_152 = F_151 ( V_149 ) ;
F_152 () ;
if ( V_152 ) {
F_140 ( V_151 ) ;
V_151 -> V_150 = NULL ;
F_142 ( V_151 ) ;
}
F_153 ( V_151 ) ;
return V_152 ;
}
void F_154 ( struct V_5 * V_6 , struct V_49 * V_50 )
{
#ifdef F_155
if ( F_79 ( V_6 -> V_153 ) ) {
F_156 ( V_6 ) ;
V_6 -> V_153 = NULL ;
}
#ifdef F_157
if ( F_79 ( V_6 -> V_154 ) ) {
F_158 ( V_6 ) ;
V_6 -> V_154 = NULL ;
}
#endif
if ( F_79 ( ! F_128 ( & V_6 -> V_155 ) ) )
F_159 ( V_6 ) ;
#endif
F_160 ( V_6 ) ;
F_161 ( V_6 , V_50 ) ;
if ( V_6 -> V_156 ) {
if ( ! ( V_6 -> V_122 & V_157 ) &&
F_35 ( & V_50 -> V_119 ) > 1 ) {
F_162 ( 0 , V_6 -> V_156 ) ;
F_163 ( V_6 -> V_156 , V_158 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_156 = NULL ;
}
if ( V_6 -> V_150 )
F_147 ( V_6 ) ;
}
struct V_49 * F_164 ( struct V_5 * V_6 )
{
struct V_49 * V_50 , * V_51 = V_27 -> V_50 ;
int V_41 ;
if ( ! V_51 )
return NULL ;
V_50 = F_115 () ;
if ( ! V_50 )
goto V_83;
memcpy ( V_50 , V_51 , sizeof( * V_50 ) ) ;
F_116 ( V_50 ) ;
#ifdef F_112
V_50 -> V_135 = NULL ;
#endif
if ( ! F_103 ( V_50 , V_6 ) )
goto V_83;
if ( F_165 ( V_6 , V_50 ) )
goto V_159;
F_138 ( V_51 , V_50 ) ;
V_41 = F_55 ( V_50 , V_51 ) ;
if ( V_41 )
goto V_160;
V_50 -> V_161 = F_166 ( V_50 ) ;
V_50 -> V_162 = V_50 -> V_163 ;
if ( V_50 -> V_138 && ! F_167 ( V_50 -> V_138 -> V_139 ) )
goto V_160;
return V_50 ;
V_160:
V_50 -> V_138 = NULL ;
F_120 ( V_50 ) ;
V_83:
return NULL ;
V_159:
F_95 ( V_50 ) ;
F_108 ( V_50 ) ;
return NULL ;
}
static int F_168 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_49 * V_50 , * V_51 ;
int V_60 ;
V_6 -> V_165 = V_6 -> V_166 = 0 ;
V_6 -> V_167 = V_6 -> V_168 = 0 ;
#ifdef F_169
V_6 -> V_169 = V_6 -> V_167 + V_6 -> V_168 ;
#endif
V_6 -> V_50 = NULL ;
V_6 -> V_170 = NULL ;
V_51 = V_27 -> V_50 ;
if ( ! V_51 )
return 0 ;
if ( V_164 & V_171 ) {
F_141 ( & V_51 -> V_119 ) ;
V_50 = V_51 ;
goto V_172;
}
V_60 = - V_110 ;
V_50 = F_164 ( V_6 ) ;
if ( ! V_50 )
goto V_83;
V_172:
V_6 -> V_50 = V_50 ;
V_6 -> V_170 = V_50 ;
return 0 ;
V_83:
return V_60 ;
}
static int F_170 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_173 * V_174 = V_27 -> V_174 ;
if ( V_164 & V_175 ) {
F_129 ( & V_174 -> V_176 ) ;
if ( V_174 -> V_177 ) {
F_131 ( & V_174 -> V_176 ) ;
return - V_178 ;
}
V_174 -> V_179 ++ ;
F_131 ( & V_174 -> V_176 ) ;
return 0 ;
}
V_6 -> V_174 = F_171 ( V_174 ) ;
if ( ! V_6 -> V_174 )
return - V_110 ;
return 0 ;
}
static int F_172 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_180 * V_181 , * V_182 ;
int error = 0 ;
V_181 = V_27 -> V_183 ;
if ( ! V_181 )
goto V_75;
if ( V_164 & V_184 ) {
F_141 ( & V_181 -> V_133 ) ;
goto V_75;
}
V_182 = F_173 ( V_181 , & error ) ;
if ( ! V_182 )
goto V_75;
V_6 -> V_183 = V_182 ;
error = 0 ;
V_75:
return error ;
}
static int F_174 ( unsigned long V_164 , struct V_5 * V_6 )
{
#ifdef F_175
struct V_185 * V_186 = V_27 -> V_185 ;
struct V_185 * V_187 ;
if ( ! V_186 )
return 0 ;
if ( V_164 & V_188 ) {
F_176 ( V_186 ) ;
V_6 -> V_185 = V_186 ;
} else if ( F_177 ( V_186 -> V_189 ) ) {
V_187 = F_178 ( V_6 , V_9 , V_190 ) ;
if ( F_79 ( ! V_187 ) )
return - V_110 ;
V_187 -> V_189 = V_186 -> V_189 ;
F_179 ( V_187 ) ;
}
#endif
return 0 ;
}
static int F_180 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_191 * V_22 ;
if ( V_164 & V_192 ) {
F_141 ( & V_27 -> V_193 -> V_133 ) ;
return 0 ;
}
V_22 = F_67 ( V_194 , V_9 ) ;
F_181 ( V_6 -> V_193 , V_22 ) ;
if ( ! V_22 )
return - V_110 ;
F_53 ( & V_22 -> V_133 , 1 ) ;
memcpy ( V_22 -> V_195 , V_27 -> V_193 -> V_195 , sizeof( V_22 -> V_195 ) ) ;
return 0 ;
}
void F_182 ( struct V_191 * V_193 )
{
if ( F_32 ( & V_193 -> V_133 ) ) {
F_183 ( V_193 ) ;
F_10 ( V_194 , V_193 ) ;
}
}
static void F_184 ( struct V_21 * V_22 )
{
unsigned long V_196 ;
F_185 ( V_22 ) ;
V_196 = F_186 ( V_22 -> V_34 [ V_197 ] . V_36 ) ;
if ( V_196 != V_198 ) {
V_22 -> V_199 . V_200 = F_187 ( V_196 ) ;
V_22 -> V_201 . V_202 = 1 ;
}
F_68 ( & V_22 -> V_203 [ 0 ] ) ;
F_68 ( & V_22 -> V_203 [ 1 ] ) ;
F_68 ( & V_22 -> V_203 [ 2 ] ) ;
}
static int F_188 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_164 & V_204 )
return 0 ;
V_22 = F_189 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_110 ;
V_22 -> V_205 = 1 ;
F_53 ( & V_22 -> V_206 , 1 ) ;
F_53 ( & V_22 -> V_24 , 1 ) ;
F_190 ( & V_22 -> V_207 ) ;
if ( V_164 & V_208 )
V_22 -> V_122 |= V_209 ;
V_22 -> V_210 = V_6 ;
F_191 ( & V_22 -> V_211 ) ;
F_68 ( & V_22 -> V_212 ) ;
F_192 ( & V_22 -> V_213 , V_214 , V_215 ) ;
V_22 -> V_213 . V_216 = V_217 ;
F_140 ( V_27 -> V_218 ) ;
memcpy ( V_22 -> V_34 , V_27 -> signal -> V_34 , sizeof V_22 -> V_34 ) ;
F_142 ( V_27 -> V_218 ) ;
F_184 ( V_22 ) ;
F_193 ( V_22 ) ;
F_194 ( V_22 ) ;
#ifdef F_195
F_104 ( & V_22 -> V_219 ) ;
#endif
V_22 -> V_220 = V_27 -> signal -> V_220 ;
V_22 -> V_221 = V_27 -> signal -> V_221 ;
V_22 -> V_222 = V_27 -> signal -> V_222 ||
V_27 -> signal -> V_223 ;
F_196 ( & V_22 -> V_146 ) ;
return 0 ;
}
static void F_197 ( unsigned long V_164 , struct V_5 * V_118 )
{
unsigned long V_224 = V_118 -> V_122 ;
V_224 &= ~ ( V_225 | V_226 ) ;
V_224 |= V_227 ;
V_118 -> V_122 = V_224 ;
}
static void F_198 ( struct V_5 * V_118 )
{
F_199 ( & V_118 -> V_228 ) ;
#ifdef F_200
F_201 ( & V_118 -> V_229 ) ;
V_118 -> V_230 = NULL ;
#endif
}
void F_105 ( struct V_49 * V_50 , struct V_5 * V_118 )
{
V_50 -> V_231 = V_118 ;
}
static void F_202 ( struct V_5 * V_6 )
{
V_6 -> V_199 . V_200 = 0 ;
V_6 -> V_199 . V_232 = 0 ;
V_6 -> V_199 . V_233 = 0 ;
F_68 ( & V_6 -> V_203 [ 0 ] ) ;
F_68 ( & V_6 -> V_203 [ 1 ] ) ;
F_68 ( & V_6 -> V_203 [ 2 ] ) ;
}
static struct V_5 * F_203 ( unsigned long V_164 ,
unsigned long V_234 ,
struct V_235 * V_236 ,
unsigned long V_237 ,
int T_2 * V_238 ,
struct V_239 * V_239 ,
int V_240 )
{
int V_60 ;
struct V_5 * V_118 ;
int V_241 = 0 ;
if ( ( V_164 & ( V_242 | V_175 ) ) == ( V_242 | V_175 ) )
return F_145 ( - V_243 ) ;
if ( ( V_164 & V_204 ) && ! ( V_164 & V_192 ) )
return F_145 ( - V_243 ) ;
if ( ( V_164 & V_192 ) && ! ( V_164 & V_171 ) )
return F_145 ( - V_243 ) ;
if ( ( V_164 & V_244 ) &&
V_27 -> signal -> V_122 & V_209 )
return F_145 ( - V_243 ) ;
V_60 = F_204 ( V_164 ) ;
if ( V_60 )
goto V_245;
V_60 = - V_110 ;
V_118 = F_44 ( V_27 ) ;
if ( ! V_118 )
goto V_245;
F_205 ( V_118 ) ;
F_206 ( V_118 ) ;
F_198 ( V_118 ) ;
#ifdef F_207
F_208 ( ! V_118 -> V_246 ) ;
F_208 ( ! V_118 -> V_247 ) ;
#endif
V_60 = - V_178 ;
if ( F_35 ( & V_118 -> V_248 -> V_249 -> V_250 ) >=
F_209 ( V_118 , V_35 ) ) {
if ( ! F_210 ( V_251 ) && ! F_210 ( V_252 ) &&
V_118 -> V_248 -> V_249 != V_253 )
goto V_254;
}
V_27 -> V_122 &= ~ V_255 ;
V_60 = F_211 ( V_118 , V_164 ) ;
if ( V_60 < 0 )
goto V_254;
V_60 = - V_178 ;
if ( V_205 >= V_31 )
goto V_256;
if ( ! F_167 ( F_212 ( V_118 ) -> V_257 -> V_139 ) )
goto V_256;
V_118 -> V_258 = 0 ;
F_213 ( V_118 ) ;
F_197 ( V_164 , V_118 ) ;
F_68 ( & V_118 -> V_259 ) ;
F_68 ( & V_118 -> V_260 ) ;
F_214 ( V_118 ) ;
V_118 -> V_150 = NULL ;
F_101 ( & V_118 -> V_261 ) ;
F_191 ( & V_118 -> V_262 ) ;
V_118 -> V_263 = V_118 -> V_264 = V_118 -> V_265 = 0 ;
V_118 -> V_266 = V_118 -> V_267 = 0 ;
#ifndef F_215
V_118 -> V_268 = V_118 -> V_269 = 0 ;
#endif
#if F_216 ( V_270 )
memset ( & V_118 -> V_126 , 0 , sizeof( V_118 -> V_126 ) ) ;
#endif
V_118 -> V_271 = V_27 -> V_272 ;
F_217 ( & V_118 -> V_273 ) ;
F_218 ( V_118 ) ;
F_202 ( V_118 ) ;
F_219 ( & V_118 -> V_274 ) ;
V_118 -> V_275 = V_118 -> V_274 ;
F_220 ( & V_118 -> V_275 ) ;
V_118 -> V_185 = NULL ;
V_118 -> V_276 = NULL ;
if ( V_164 & V_204 )
F_221 ( V_27 ) ;
F_222 ( V_118 ) ;
#ifdef F_223
V_118 -> V_62 = F_69 ( V_118 -> V_62 ) ;
if ( F_72 ( V_118 -> V_62 ) ) {
V_60 = F_71 ( V_118 -> V_62 ) ;
V_118 -> V_62 = NULL ;
goto V_277;
}
F_224 ( V_118 ) ;
#endif
#ifdef F_225
V_118 -> V_278 = V_190 ;
V_118 -> V_279 = V_190 ;
F_226 ( & V_118 -> V_280 ) ;
#endif
#ifdef F_227
V_118 -> V_281 = 0 ;
V_118 -> V_246 = 0 ;
V_118 -> V_282 = 0 ;
V_118 -> V_283 = 0 ;
V_118 -> V_284 = V_285 ;
V_118 -> V_286 = 0 ;
V_118 -> V_247 = 1 ;
V_118 -> V_287 = V_285 ;
V_118 -> V_288 = 0 ;
V_118 -> V_289 = 0 ;
V_118 -> V_290 = 0 ;
V_118 -> V_291 = 0 ;
V_118 -> V_292 = 0 ;
#endif
#ifdef F_228
V_118 -> V_293 = 0 ;
V_118 -> V_294 = 0 ;
V_118 -> V_295 = 0 ;
#endif
#ifdef F_229
V_118 -> V_296 = NULL ;
#endif
#ifdef F_230
V_118 -> V_297 . V_298 = 0 ;
V_118 -> V_297 . V_299 = NULL ;
#endif
F_231 ( V_118 ) ;
V_60 = F_232 ( V_118 ) ;
if ( V_60 )
goto V_300;
V_60 = F_233 ( V_118 ) ;
if ( V_60 )
goto V_300;
V_60 = F_234 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_301;
V_60 = F_172 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_302;
V_60 = F_170 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_303;
V_60 = F_180 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_304;
V_60 = F_188 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_305;
V_60 = F_168 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_306;
V_60 = F_235 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_307;
V_60 = F_174 ( V_164 , V_118 ) ;
if ( V_60 )
goto V_308;
V_60 = F_236 ( V_164 , V_234 , V_237 , V_118 , V_236 ) ;
if ( V_60 )
goto V_309;
if ( V_239 != & V_310 ) {
V_60 = - V_110 ;
V_239 = F_237 ( V_118 -> V_311 -> V_312 ) ;
if ( ! V_239 )
goto V_309;
}
V_118 -> V_239 = F_238 ( V_239 ) ;
V_118 -> V_313 = V_118 -> V_239 ;
if ( V_164 & V_204 )
V_118 -> V_313 = V_27 -> V_313 ;
V_118 -> V_314 = ( V_164 & V_315 ) ? V_238 : NULL ;
V_118 -> V_156 = ( V_164 & V_316 ) ? V_238 : NULL ;
#ifdef F_175
V_118 -> V_317 = NULL ;
#endif
#ifdef F_155
V_118 -> V_153 = NULL ;
#ifdef F_157
V_118 -> V_154 = NULL ;
#endif
F_68 ( & V_118 -> V_155 ) ;
V_118 -> V_318 = NULL ;
#endif
F_239 ( V_118 ) ;
if ( ( V_164 & ( V_171 | V_319 ) ) == V_171 )
V_118 -> V_320 = V_118 -> V_321 = 0 ;
F_240 ( V_118 ) ;
F_241 ( V_118 , V_322 ) ;
#ifdef F_242
F_241 ( V_118 , F_242 ) ;
#endif
F_243 ( V_118 ) ;
if ( V_164 & V_204 )
V_118 -> V_323 = - 1 ;
else if ( V_164 & V_244 )
V_118 -> V_323 = V_27 -> V_218 -> V_323 ;
else
V_118 -> V_323 = ( V_164 & V_324 ) ;
V_118 -> V_325 = 0 ;
V_118 -> V_25 = 0 ;
V_118 -> V_326 = 0 ;
V_118 -> V_327 = 128 >> ( V_328 - 10 ) ;
V_118 -> V_329 = 0 ;
V_118 -> V_218 = V_118 ;
F_68 ( & V_118 -> V_330 ) ;
V_118 -> V_331 = NULL ;
F_244 ( V_118 ) ;
V_241 = 1 ;
F_245 ( & V_1 ) ;
if ( V_164 & ( V_244 | V_204 ) ) {
V_118 -> V_332 = V_27 -> V_332 ;
V_118 -> V_333 = V_27 -> V_333 ;
} else {
V_118 -> V_332 = V_27 ;
V_118 -> V_333 = V_27 -> V_334 ;
}
F_129 ( & V_27 -> V_193 -> V_335 ) ;
F_246 () ;
if ( F_247 ( V_27 ) ) {
F_131 ( & V_27 -> V_193 -> V_335 ) ;
F_248 ( & V_1 ) ;
V_60 = - V_336 ;
goto V_337;
}
if ( V_164 & V_204 ) {
V_27 -> signal -> V_205 ++ ;
F_141 ( & V_27 -> signal -> V_206 ) ;
F_141 ( & V_27 -> signal -> V_24 ) ;
V_118 -> V_218 = V_27 -> V_218 ;
F_249 ( & V_118 -> V_330 , & V_118 -> V_218 -> V_330 ) ;
}
if ( F_106 ( V_118 -> V_239 ) ) {
F_250 ( V_118 , ( V_164 & V_338 ) || V_240 ) ;
if ( F_251 ( V_118 ) ) {
if ( F_252 ( V_239 ) )
V_118 -> V_311 -> V_312 -> V_339 = V_118 ;
V_118 -> signal -> V_340 = V_239 ;
V_118 -> signal -> V_341 = F_253 ( V_27 -> signal -> V_341 ) ;
F_254 ( V_118 , V_342 , F_255 ( V_27 ) ) ;
F_254 ( V_118 , V_343 , F_256 ( V_27 ) ) ;
F_257 ( & V_118 -> V_260 , & V_118 -> V_332 -> V_259 ) ;
F_249 ( & V_118 -> V_344 , & V_33 . V_344 ) ;
F_258 ( V_4 ) ;
}
F_254 ( V_118 , V_345 , V_239 ) ;
V_205 ++ ;
}
V_346 ++ ;
F_131 ( & V_27 -> V_193 -> V_335 ) ;
F_248 ( & V_1 ) ;
F_259 ( V_118 ) ;
F_260 ( V_118 ) ;
if ( V_164 & V_204 )
F_261 ( V_27 ) ;
F_262 ( V_118 ) ;
F_263 ( V_118 , V_164 ) ;
return V_118 ;
V_337:
if ( V_239 != & V_310 )
F_264 ( V_239 ) ;
V_309:
if ( V_118 -> V_185 )
F_265 ( V_118 ) ;
V_308:
if ( F_79 ( V_164 & V_208 ) )
F_266 ( V_118 -> V_311 -> V_312 ) ;
F_267 ( V_118 ) ;
V_307:
if ( V_118 -> V_50 )
F_120 ( V_118 -> V_50 ) ;
V_306:
if ( ! ( V_164 & V_204 ) )
F_28 ( V_118 -> signal ) ;
V_305:
F_182 ( V_118 -> V_193 ) ;
V_304:
F_268 ( V_118 ) ;
V_303:
F_269 ( V_118 ) ;
V_302:
F_270 ( V_118 ) ;
V_301:
F_271 ( V_118 ) ;
V_300:
F_272 ( V_118 ) ;
#ifdef F_223
F_91 ( V_118 -> V_62 ) ;
V_277:
#endif
if ( V_164 & V_204 )
F_261 ( V_27 ) ;
F_273 ( V_118 , V_241 ) ;
F_38 ( V_118 ) ;
F_132 ( F_212 ( V_118 ) -> V_257 -> V_139 ) ;
V_256:
F_76 ( & V_118 -> V_347 -> V_249 -> V_250 ) ;
F_37 ( V_118 ) ;
V_254:
F_24 ( V_118 ) ;
V_245:
return F_145 ( V_60 ) ;
}
static inline void F_274 ( struct V_348 * V_349 )
{
enum V_350 type ;
for ( type = V_345 ; type < V_351 ; ++ type ) {
F_275 ( & V_349 [ type ] . V_7 ) ;
V_349 [ type ] . V_239 = & V_310 ;
}
}
struct V_5 * T_3 F_276 ( int V_2 )
{
struct V_5 * V_143 ;
struct V_235 V_236 ;
V_143 = F_203 ( V_171 , 0 , F_277 ( & V_236 ) , 0 , NULL ,
& V_310 , 0 ) ;
if ( ! F_72 ( V_143 ) ) {
F_274 ( V_143 -> V_352 ) ;
F_278 ( V_143 , V_2 ) ;
}
return V_143 ;
}
long F_279 ( unsigned long V_164 ,
unsigned long V_234 ,
struct V_235 * V_236 ,
unsigned long V_237 ,
int T_2 * V_353 ,
int T_2 * V_238 )
{
struct V_5 * V_118 ;
int V_240 = 0 ;
long V_354 ;
if ( V_164 & V_355 ) {
if ( V_164 & V_204 )
return - V_243 ;
if ( ! F_210 ( V_251 ) || ! F_210 ( V_356 ) ||
! F_210 ( V_357 ) )
return - V_358 ;
}
if ( ! ( V_164 & V_359 ) && F_106 ( F_280 ( V_236 ) ) ) {
if ( V_164 & V_319 )
V_240 = V_360 ;
else if ( ( V_164 & V_324 ) != V_361 )
V_240 = V_362 ;
else
V_240 = V_363 ;
if ( F_106 ( ! F_281 ( V_27 , V_240 ) ) )
V_240 = 0 ;
}
V_118 = F_203 ( V_164 , V_234 , V_236 , V_237 ,
V_238 , NULL , V_240 ) ;
if ( ! F_72 ( V_118 ) ) {
struct V_148 V_149 ;
F_282 ( V_27 , V_118 ) ;
V_354 = F_283 ( V_118 ) ;
if ( V_164 & V_364 )
F_162 ( V_354 , V_353 ) ;
if ( V_164 & V_319 ) {
V_118 -> V_150 = & V_149 ;
F_284 ( & V_149 ) ;
F_285 ( V_118 ) ;
}
F_286 ( V_118 ) ;
if ( F_79 ( V_240 ) )
F_287 ( V_240 , V_354 ) ;
if ( V_164 & V_319 ) {
if ( ! F_149 ( V_118 , & V_149 ) )
F_287 ( V_365 , V_354 ) ;
}
} else {
V_354 = F_71 ( V_118 ) ;
}
return V_354 ;
}
T_4 F_288 ( int (* F_289)( void * ) , void * V_366 , unsigned long V_122 )
{
return F_279 ( V_122 | V_171 | V_359 , ( unsigned long ) F_289 , NULL ,
( unsigned long ) V_366 , NULL , NULL ) ;
}
static void F_290 ( void * V_367 )
{
struct V_191 * V_193 = V_367 ;
F_101 ( & V_193 -> V_335 ) ;
F_190 ( & V_193 -> V_368 ) ;
}
void T_1 F_291 ( void )
{
V_194 = F_18 ( L_5 ,
sizeof( struct V_191 ) , 0 ,
V_369 | V_29 | V_370 |
V_30 , F_290 ) ;
V_23 = F_18 ( L_6 ,
sizeof( struct V_21 ) , 0 ,
V_369 | V_29 | V_30 , NULL ) ;
V_371 = F_18 ( L_7 ,
sizeof( struct V_180 ) , 0 ,
V_369 | V_29 | V_30 , NULL ) ;
V_372 = F_18 ( L_8 ,
sizeof( struct V_173 ) , 0 ,
V_369 | V_29 | V_30 , NULL ) ;
V_373 = F_18 ( L_9 ,
sizeof( struct V_49 ) , V_374 ,
V_369 | V_29 | V_30 , NULL ) ;
V_84 = F_292 ( V_52 , V_29 ) ;
F_293 () ;
F_294 () ;
}
static int F_295 ( unsigned long V_375 )
{
if ( V_375 & ~ ( V_204 | V_175 | V_242 | V_192 |
V_171 | V_184 | V_376 |
V_377 | V_378 | V_379 ) )
return - V_243 ;
if ( V_375 & ( V_204 | V_192 | V_171 ) ) {
if ( F_35 ( & V_27 -> V_50 -> V_119 ) > 1 )
return - V_243 ;
}
return 0 ;
}
static int F_296 ( unsigned long V_375 , struct V_173 * * V_380 )
{
struct V_173 * V_174 = V_27 -> V_174 ;
if ( ! ( V_375 & V_175 ) || ! V_174 )
return 0 ;
if ( V_174 -> V_179 == 1 )
return 0 ;
* V_380 = F_171 ( V_174 ) ;
if ( ! * V_380 )
return - V_110 ;
return 0 ;
}
static int F_297 ( unsigned long V_375 , struct V_180 * * V_381 )
{
struct V_180 * V_382 = V_27 -> V_183 ;
int error = 0 ;
if ( ( V_375 & V_184 ) &&
( V_382 && F_35 ( & V_382 -> V_133 ) > 1 ) ) {
* V_381 = F_173 ( V_382 , & error ) ;
if ( ! * V_381 )
return error ;
}
return 0 ;
}
int F_298 ( struct V_180 * * V_383 )
{
struct V_5 * V_143 = V_27 ;
struct V_180 * V_384 = NULL ;
int error ;
error = F_297 ( V_184 , & V_384 ) ;
if ( error || ! V_384 ) {
* V_383 = NULL ;
return error ;
}
* V_383 = V_143 -> V_183 ;
F_140 ( V_143 ) ;
V_143 -> V_183 = V_384 ;
F_142 ( V_143 ) ;
return 0 ;
}
