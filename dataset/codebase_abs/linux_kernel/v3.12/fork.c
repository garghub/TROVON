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
F_56 () ;
F_57 ( & V_52 -> V_63 ) ;
F_58 ( V_52 ) ;
F_59 ( V_52 , V_51 ) ;
F_60 ( & V_51 -> V_63 , V_64 ) ;
V_51 -> V_65 = 0 ;
V_51 -> V_66 = NULL ;
V_51 -> V_67 = NULL ;
V_51 -> V_68 = 0 ;
F_61 ( F_62 ( V_51 ) ) ;
V_51 -> V_69 = V_70 ;
V_59 = & V_51 -> V_69 . V_58 ;
V_60 = NULL ;
V_57 = & V_51 -> V_66 ;
V_61 = F_63 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_71;
V_61 = F_64 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_71;
V_56 = NULL ;
for ( V_54 = V_52 -> V_66 ; V_54 ; V_54 = V_54 -> V_72 ) {
struct V_73 * V_73 ;
if ( V_54 -> V_74 & V_75 ) {
F_65 ( V_51 , V_54 -> V_74 , V_54 -> V_76 ,
- F_66 ( V_54 ) ) ;
continue;
}
V_62 = 0 ;
if ( V_54 -> V_74 & V_77 ) {
unsigned long V_78 = F_66 ( V_54 ) ;
if ( F_67 ( V_52 , V_78 ) )
goto V_79;
V_62 = V_78 ;
}
V_55 = F_68 ( V_80 , V_9 ) ;
if ( ! V_55 )
goto V_79;
* V_55 = * V_54 ;
F_69 ( & V_55 -> V_81 ) ;
V_61 = F_70 ( V_54 , V_55 ) ;
if ( V_61 )
goto V_82;
V_55 -> V_83 = V_51 ;
if ( F_71 ( V_55 , V_54 ) )
goto V_84;
V_55 -> V_74 &= ~ V_85 ;
V_55 -> V_72 = V_55 -> V_86 = NULL ;
V_73 = V_55 -> V_76 ;
if ( V_73 ) {
struct V_87 * V_87 = F_72 ( V_73 ) ;
struct V_88 * V_89 = V_73 -> V_90 ;
F_73 ( V_73 ) ;
if ( V_55 -> V_74 & V_91 )
F_74 ( & V_87 -> V_92 ) ;
F_75 ( & V_89 -> V_93 ) ;
if ( V_55 -> V_74 & V_94 )
V_89 -> V_95 ++ ;
F_76 ( V_89 ) ;
if ( F_77 ( V_55 -> V_74 & V_96 ) )
F_78 ( V_55 ,
& V_89 -> V_97 ) ;
else
F_79 ( V_55 , V_54 ,
& V_89 -> V_98 ) ;
F_80 ( V_89 ) ;
F_81 ( & V_89 -> V_93 ) ;
}
if ( F_82 ( V_55 ) )
F_83 ( V_55 ) ;
* V_57 = V_55 ;
V_57 = & V_55 -> V_72 ;
V_55 -> V_86 = V_56 ;
V_56 = V_55 ;
F_84 ( V_51 , V_55 , V_59 , V_60 ) ;
V_59 = & V_55 -> V_99 . V_100 ;
V_60 = & V_55 -> V_99 ;
V_51 -> V_68 ++ ;
V_61 = F_85 ( V_51 , V_52 , V_54 ) ;
if ( V_55 -> V_101 && V_55 -> V_101 -> V_102 )
V_55 -> V_101 -> V_102 ( V_55 ) ;
if ( V_61 )
goto V_71;
}
F_86 ( V_52 , V_51 ) ;
V_61 = 0 ;
V_71:
F_87 ( & V_51 -> V_63 ) ;
F_88 ( V_52 ) ;
F_87 ( & V_52 -> V_63 ) ;
F_89 () ;
return V_61 ;
V_84:
F_90 ( F_91 ( V_55 ) ) ;
V_82:
F_10 ( V_80 , V_55 ) ;
V_79:
V_61 = - V_103 ;
F_92 ( V_62 ) ;
goto V_71;
}
static inline int F_93 ( struct V_50 * V_51 )
{
V_51 -> V_104 = F_94 ( V_51 ) ;
if ( F_77 ( ! V_51 -> V_104 ) )
return - V_103 ;
return 0 ;
}
static inline void F_95 ( struct V_50 * V_51 )
{
F_96 ( V_51 , V_51 -> V_104 ) ;
}
static int T_1 F_97 ( char * V_105 )
{
V_106 =
( F_98 ( V_105 , NULL , 0 ) << V_107 ) &
V_108 ;
return 1 ;
}
static void F_99 ( struct V_50 * V_51 )
{
#ifdef F_100
F_101 ( & V_51 -> V_109 ) ;
V_51 -> V_110 = NULL ;
#endif
}
static struct V_50 * F_102 ( struct V_50 * V_51 , struct V_5 * V_111 )
{
F_53 ( & V_51 -> V_112 , 1 ) ;
F_53 ( & V_51 -> V_113 , 1 ) ;
F_103 ( & V_51 -> V_63 ) ;
F_69 ( & V_51 -> V_114 ) ;
V_51 -> V_115 = ( V_28 -> V_51 ) ?
( V_28 -> V_51 -> V_115 & V_116 ) : V_106 ;
V_51 -> V_117 = NULL ;
V_51 -> V_118 = 0 ;
memset ( & V_51 -> V_119 , 0 , sizeof( V_51 -> V_119 ) ) ;
F_101 ( & V_51 -> V_120 ) ;
F_99 ( V_51 ) ;
F_104 ( V_51 , V_111 ) ;
if ( F_105 ( ! F_93 ( V_51 ) ) ) {
V_51 -> V_121 = 0 ;
F_106 ( V_51 ) ;
return V_51 ;
}
F_107 ( V_51 ) ;
return NULL ;
}
static void F_108 ( struct V_50 * V_51 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ ) {
long V_124 = F_109 ( & V_51 -> V_119 . V_125 [ V_122 ] ) ;
if ( F_77 ( V_124 ) )
F_110 ( V_126 L_3
L_4 , V_51 , V_122 , V_124 ) ;
}
#ifdef F_111
F_112 ( V_51 -> V_127 ) ;
#endif
}
struct V_50 * F_113 ( void )
{
struct V_50 * V_51 ;
V_51 = F_114 () ;
if ( ! V_51 )
return NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
F_115 ( V_51 ) ;
return F_102 ( V_51 , V_28 ) ;
}
void F_116 ( struct V_50 * V_51 )
{
F_19 ( V_51 == & V_128 ) ;
F_95 ( V_51 ) ;
F_117 ( V_51 ) ;
F_118 ( V_51 ) ;
F_108 ( V_51 ) ;
F_107 ( V_51 ) ;
}
void F_119 ( struct V_50 * V_51 )
{
F_120 () ;
if ( F_32 ( & V_51 -> V_112 ) ) {
F_121 ( V_51 ) ;
F_122 ( V_51 ) ;
F_123 ( V_51 ) ;
F_124 ( V_51 ) ;
F_125 ( V_51 ) ;
F_126 ( V_51 , NULL ) ;
if ( ! F_127 ( & V_51 -> V_114 ) ) {
F_128 ( & V_129 ) ;
F_129 ( & V_51 -> V_114 ) ;
F_130 ( & V_129 ) ;
}
if ( V_51 -> V_130 )
F_131 ( V_51 -> V_130 -> V_131 ) ;
F_132 ( V_51 ) ;
}
}
void F_126 ( struct V_50 * V_51 , struct V_73 * V_132 )
{
if ( V_132 )
F_73 ( V_132 ) ;
if ( V_51 -> V_133 )
F_133 ( V_51 -> V_133 ) ;
V_51 -> V_133 = V_132 ;
}
struct V_73 * F_134 ( struct V_50 * V_51 )
{
struct V_73 * V_133 ;
F_135 ( & V_51 -> V_63 ) ;
V_133 = V_51 -> V_133 ;
if ( V_133 )
F_73 ( V_133 ) ;
F_136 ( & V_51 -> V_63 ) ;
return V_133 ;
}
static void F_137 ( struct V_50 * V_52 , struct V_50 * V_134 )
{
V_134 -> V_133 = F_134 ( V_52 ) ;
}
struct V_50 * F_138 ( struct V_5 * V_135 )
{
struct V_50 * V_51 ;
F_139 ( V_135 ) ;
V_51 = V_135 -> V_51 ;
if ( V_51 ) {
if ( V_135 -> V_115 & V_136 )
V_51 = NULL ;
else
F_140 ( & V_51 -> V_112 ) ;
}
F_141 ( V_135 ) ;
return V_51 ;
}
struct V_50 * F_142 ( struct V_5 * V_135 , unsigned int V_137 )
{
struct V_50 * V_51 ;
int V_42 ;
V_42 = F_143 ( & V_135 -> signal -> V_138 ) ;
if ( V_42 )
return F_144 ( V_42 ) ;
V_51 = F_138 ( V_135 ) ;
if ( V_51 && V_51 != V_28 -> V_51 &&
! F_145 ( V_135 , V_137 ) ) {
F_119 ( V_51 ) ;
V_51 = F_144 ( - V_139 ) ;
}
F_81 ( & V_135 -> signal -> V_138 ) ;
return V_51 ;
}
static void F_146 ( struct V_5 * V_6 )
{
struct V_140 * V_141 ;
F_139 ( V_6 ) ;
V_141 = V_6 -> V_142 ;
if ( F_105 ( V_141 ) ) {
V_6 -> V_142 = NULL ;
F_147 ( V_141 ) ;
}
F_141 ( V_6 ) ;
}
static int F_148 ( struct V_5 * V_143 ,
struct V_140 * V_141 )
{
int V_144 ;
F_149 () ;
V_144 = F_150 ( V_141 ) ;
F_151 () ;
if ( V_144 ) {
F_139 ( V_143 ) ;
V_143 -> V_142 = NULL ;
F_141 ( V_143 ) ;
}
F_152 ( V_143 ) ;
return V_144 ;
}
void F_153 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
#ifdef F_154
if ( F_77 ( V_6 -> V_145 ) ) {
F_155 ( V_6 ) ;
V_6 -> V_145 = NULL ;
}
#ifdef F_156
if ( F_77 ( V_6 -> V_146 ) ) {
F_157 ( V_6 ) ;
V_6 -> V_146 = NULL ;
}
#endif
if ( F_77 ( ! F_127 ( & V_6 -> V_147 ) ) )
F_158 ( V_6 ) ;
#endif
F_159 ( V_6 ) ;
F_160 ( V_6 , V_51 ) ;
if ( V_6 -> V_148 ) {
if ( ! ( V_6 -> V_115 & V_149 ) &&
F_35 ( & V_51 -> V_112 ) > 1 ) {
F_161 ( 0 , V_6 -> V_148 ) ;
F_162 ( V_6 -> V_148 , V_150 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_148 = NULL ;
}
if ( V_6 -> V_142 )
F_146 ( V_6 ) ;
}
struct V_50 * F_163 ( struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 = V_28 -> V_51 ;
int V_42 ;
if ( ! V_52 )
return NULL ;
V_51 = F_114 () ;
if ( ! V_51 )
goto V_79;
memcpy ( V_51 , V_52 , sizeof( * V_51 ) ) ;
F_115 ( V_51 ) ;
#ifdef F_111
V_51 -> V_127 = NULL ;
#endif
#ifdef F_164
V_51 -> V_151 = V_152 ;
#endif
if ( ! F_102 ( V_51 , V_6 ) )
goto V_79;
if ( F_165 ( V_6 , V_51 ) )
goto V_153;
F_137 ( V_52 , V_51 ) ;
V_42 = F_55 ( V_51 , V_52 ) ;
if ( V_42 )
goto V_154;
V_51 -> V_155 = F_166 ( V_51 ) ;
V_51 -> V_156 = V_51 -> V_157 ;
if ( V_51 -> V_130 && ! F_167 ( V_51 -> V_130 -> V_131 ) )
goto V_154;
return V_51 ;
V_154:
V_51 -> V_130 = NULL ;
F_119 ( V_51 ) ;
V_79:
return NULL ;
V_153:
F_95 ( V_51 ) ;
F_107 ( V_51 ) ;
return NULL ;
}
static int F_168 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 ;
int V_61 ;
V_6 -> V_159 = V_6 -> V_160 = 0 ;
V_6 -> V_161 = V_6 -> V_162 = 0 ;
#ifdef F_169
V_6 -> V_163 = V_6 -> V_161 + V_6 -> V_162 ;
#endif
V_6 -> V_51 = NULL ;
V_6 -> V_164 = NULL ;
V_52 = V_28 -> V_51 ;
if ( ! V_52 )
return 0 ;
if ( V_158 & V_165 ) {
F_140 ( & V_52 -> V_112 ) ;
V_51 = V_52 ;
goto V_166;
}
V_61 = - V_103 ;
V_51 = F_163 ( V_6 ) ;
if ( ! V_51 )
goto V_79;
V_166:
V_6 -> V_51 = V_51 ;
V_6 -> V_164 = V_51 ;
return 0 ;
V_79:
return V_61 ;
}
static int F_170 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_167 * V_168 = V_28 -> V_168 ;
if ( V_158 & V_169 ) {
F_128 ( & V_168 -> V_170 ) ;
if ( V_168 -> V_171 ) {
F_130 ( & V_168 -> V_170 ) ;
return - V_172 ;
}
V_168 -> V_173 ++ ;
F_130 ( & V_168 -> V_170 ) ;
return 0 ;
}
V_6 -> V_168 = F_171 ( V_168 ) ;
if ( ! V_6 -> V_168 )
return - V_103 ;
return 0 ;
}
static int F_172 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_174 * V_175 , * V_176 ;
int error = 0 ;
V_175 = V_28 -> V_177 ;
if ( ! V_175 )
goto V_71;
if ( V_158 & V_178 ) {
F_140 ( & V_175 -> V_125 ) ;
goto V_71;
}
V_176 = F_173 ( V_175 , & error ) ;
if ( ! V_176 )
goto V_71;
V_6 -> V_177 = V_176 ;
error = 0 ;
V_71:
return error ;
}
static int F_174 ( unsigned long V_158 , struct V_5 * V_6 )
{
#ifdef F_175
struct V_179 * V_180 = V_28 -> V_179 ;
struct V_179 * V_181 ;
if ( ! V_180 )
return 0 ;
if ( V_158 & V_182 ) {
F_176 ( V_180 ) ;
V_6 -> V_179 = V_180 ;
} else if ( F_177 ( V_180 -> V_183 ) ) {
V_181 = F_178 ( V_6 , V_9 , V_184 ) ;
if ( F_77 ( ! V_181 ) )
return - V_103 ;
V_181 -> V_183 = V_180 -> V_183 ;
F_179 ( V_181 ) ;
}
#endif
return 0 ;
}
static int F_180 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_185 * V_23 ;
if ( V_158 & V_186 ) {
F_140 ( & V_28 -> V_187 -> V_125 ) ;
return 0 ;
}
V_23 = F_68 ( V_188 , V_9 ) ;
F_181 ( V_6 -> V_187 , V_23 ) ;
if ( ! V_23 )
return - V_103 ;
F_53 ( & V_23 -> V_125 , 1 ) ;
memcpy ( V_23 -> V_189 , V_28 -> V_187 -> V_189 , sizeof( V_23 -> V_189 ) ) ;
return 0 ;
}
void F_182 ( struct V_185 * V_187 )
{
if ( F_32 ( & V_187 -> V_125 ) ) {
F_183 ( V_187 ) ;
F_10 ( V_188 , V_187 ) ;
}
}
static void F_184 ( struct V_22 * V_23 )
{
unsigned long V_190 ;
F_185 ( V_23 ) ;
V_190 = F_186 ( V_23 -> V_35 [ V_191 ] . V_37 ) ;
if ( V_190 != V_192 ) {
V_23 -> V_193 . V_194 = F_187 ( V_190 ) ;
V_23 -> V_195 . V_196 = 1 ;
}
F_69 ( & V_23 -> V_197 [ 0 ] ) ;
F_69 ( & V_23 -> V_197 [ 1 ] ) ;
F_69 ( & V_23 -> V_197 [ 2 ] ) ;
}
static int F_188 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_22 * V_23 ;
if ( V_158 & V_198 )
return 0 ;
V_23 = F_189 ( V_24 , V_9 ) ;
V_6 -> signal = V_23 ;
if ( ! V_23 )
return - V_103 ;
V_23 -> V_199 = 1 ;
F_53 ( & V_23 -> V_200 , 1 ) ;
F_53 ( & V_23 -> V_25 , 1 ) ;
F_190 ( & V_23 -> V_201 ) ;
V_23 -> V_202 = V_6 ;
F_191 ( & V_23 -> V_203 ) ;
F_69 ( & V_23 -> V_204 ) ;
F_192 ( & V_23 -> V_205 , V_206 , V_207 ) ;
V_23 -> V_205 . V_208 = V_209 ;
F_139 ( V_28 -> V_210 ) ;
memcpy ( V_23 -> V_35 , V_28 -> signal -> V_35 , sizeof V_23 -> V_35 ) ;
F_141 ( V_28 -> V_210 ) ;
F_184 ( V_23 ) ;
F_193 ( V_23 ) ;
F_194 ( V_23 ) ;
#ifdef F_195
F_103 ( & V_23 -> V_211 ) ;
#endif
V_23 -> V_212 = V_28 -> signal -> V_212 ;
V_23 -> V_213 = V_28 -> signal -> V_213 ;
V_23 -> V_214 = V_28 -> signal -> V_214 ||
V_28 -> signal -> V_215 ;
F_196 ( & V_23 -> V_138 ) ;
return 0 ;
}
static void F_197 ( unsigned long V_158 , struct V_5 * V_111 )
{
unsigned long V_216 = V_111 -> V_115 ;
V_216 &= ~ ( V_217 | V_218 ) ;
V_216 |= V_219 ;
V_111 -> V_115 = V_216 ;
}
static void F_198 ( struct V_5 * V_111 )
{
F_199 ( & V_111 -> V_220 ) ;
#ifdef F_200
F_201 ( & V_111 -> V_221 ) ;
V_111 -> V_222 = NULL ;
#endif
}
void F_104 ( struct V_50 * V_51 , struct V_5 * V_111 )
{
V_51 -> V_223 = V_111 ;
}
static void F_202 ( struct V_5 * V_6 )
{
V_6 -> V_193 . V_194 = 0 ;
V_6 -> V_193 . V_224 = 0 ;
V_6 -> V_193 . V_225 = 0 ;
F_69 ( & V_6 -> V_197 [ 0 ] ) ;
F_69 ( & V_6 -> V_197 [ 1 ] ) ;
F_69 ( & V_6 -> V_197 [ 2 ] ) ;
}
static inline void
F_203 ( struct V_5 * V_135 , enum V_226 type , struct V_227 * V_227 )
{
V_135 -> V_228 [ type ] . V_227 = V_227 ;
}
static struct V_5 * F_204 ( unsigned long V_158 ,
unsigned long V_229 ,
unsigned long V_230 ,
int T_2 * V_231 ,
struct V_227 * V_227 ,
int V_232 )
{
int V_61 ;
struct V_5 * V_111 ;
if ( ( V_158 & ( V_233 | V_169 ) ) == ( V_233 | V_169 ) )
return F_144 ( - V_234 ) ;
if ( ( V_158 & ( V_235 | V_169 ) ) == ( V_235 | V_169 ) )
return F_144 ( - V_234 ) ;
if ( ( V_158 & V_198 ) && ! ( V_158 & V_186 ) )
return F_144 ( - V_234 ) ;
if ( ( V_158 & V_186 ) && ! ( V_158 & V_165 ) )
return F_144 ( - V_234 ) ;
if ( ( V_158 & V_236 ) &&
V_28 -> signal -> V_115 & V_237 )
return F_144 ( - V_234 ) ;
if ( V_158 & ( V_186 | V_236 ) ) {
if ( ( V_158 & ( V_235 | V_238 ) ) ||
( F_205 ( V_28 ) !=
V_28 -> V_239 -> V_240 ) )
return F_144 ( - V_234 ) ;
}
V_61 = F_206 ( V_158 ) ;
if ( V_61 )
goto V_241;
V_61 = - V_103 ;
V_111 = F_44 ( V_28 ) ;
if ( ! V_111 )
goto V_241;
F_207 ( V_111 ) ;
F_208 ( V_111 ) ;
F_198 ( V_111 ) ;
#ifdef F_209
F_210 ( ! V_111 -> V_242 ) ;
F_210 ( ! V_111 -> V_243 ) ;
#endif
V_61 = - V_172 ;
if ( F_35 ( & V_111 -> V_244 -> V_245 -> V_246 ) >=
F_211 ( V_111 , V_36 ) ) {
if ( V_111 -> V_244 -> V_245 != V_247 &&
! F_212 ( V_248 ) && ! F_212 ( V_249 ) )
goto V_250;
}
V_28 -> V_115 &= ~ V_251 ;
V_61 = F_213 ( V_111 , V_158 ) ;
if ( V_61 < 0 )
goto V_250;
V_61 = - V_172 ;
if ( V_199 >= V_32 )
goto V_252;
if ( ! F_167 ( F_214 ( V_111 ) -> V_253 -> V_131 ) )
goto V_252;
V_111 -> V_254 = 0 ;
F_215 ( V_111 ) ;
F_197 ( V_158 , V_111 ) ;
F_69 ( & V_111 -> V_255 ) ;
F_69 ( & V_111 -> V_256 ) ;
F_216 ( V_111 ) ;
V_111 -> V_142 = NULL ;
F_101 ( & V_111 -> V_257 ) ;
F_191 ( & V_111 -> V_258 ) ;
V_111 -> V_259 = V_111 -> V_260 = V_111 -> V_261 = 0 ;
V_111 -> V_262 = V_111 -> V_263 = 0 ;
#ifndef F_217
V_111 -> V_264 . V_259 = V_111 -> V_264 . V_260 = 0 ;
#endif
#ifdef F_218
F_219 ( & V_111 -> V_265 ) ;
V_111 -> V_266 = 0 ;
V_111 -> V_267 = V_268 ;
#endif
#if F_220 ( V_269 )
memset ( & V_111 -> V_119 , 0 , sizeof( V_111 -> V_119 ) ) ;
#endif
V_111 -> V_270 = V_28 -> V_271 ;
F_221 ( & V_111 -> V_272 ) ;
F_222 ( V_111 ) ;
F_202 ( V_111 ) ;
F_223 ( & V_111 -> V_273 ) ;
V_111 -> V_274 = V_111 -> V_273 ;
F_224 ( & V_111 -> V_274 ) ;
V_111 -> V_179 = NULL ;
V_111 -> V_275 = NULL ;
if ( V_158 & V_198 )
F_225 ( V_28 ) ;
F_226 ( V_111 ) ;
#ifdef F_227
V_111 -> V_276 = F_228 ( V_111 -> V_276 ) ;
if ( F_229 ( V_111 -> V_276 ) ) {
V_61 = F_230 ( V_111 -> V_276 ) ;
V_111 -> V_276 = NULL ;
goto V_277;
}
F_231 ( V_111 ) ;
#endif
#ifdef F_232
V_111 -> V_278 = V_184 ;
V_111 -> V_279 = V_184 ;
F_233 ( & V_111 -> V_280 ) ;
#endif
#ifdef F_234
V_111 -> V_281 = 0 ;
V_111 -> V_242 = 0 ;
V_111 -> V_282 = 0 ;
V_111 -> V_283 = 0 ;
V_111 -> V_284 = V_285 ;
V_111 -> V_286 = 0 ;
V_111 -> V_243 = 1 ;
V_111 -> V_287 = V_285 ;
V_111 -> V_288 = 0 ;
V_111 -> V_289 = 0 ;
V_111 -> V_290 = 0 ;
V_111 -> V_291 = 0 ;
V_111 -> V_292 = 0 ;
#endif
#ifdef F_235
V_111 -> V_293 = 0 ;
V_111 -> V_294 = 0 ;
V_111 -> V_295 = 0 ;
#endif
#ifdef F_236
V_111 -> V_296 = NULL ;
#endif
#ifdef F_237
V_111 -> V_297 . V_298 = 0 ;
V_111 -> V_297 . V_299 = NULL ;
#endif
#ifdef F_238
V_111 -> V_300 = 0 ;
V_111 -> V_301 = 0 ;
#endif
F_239 ( V_111 ) ;
V_61 = F_240 ( V_111 ) ;
if ( V_61 )
goto V_302;
V_61 = F_241 ( V_111 ) ;
if ( V_61 )
goto V_302;
V_61 = F_242 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_303;
V_61 = F_172 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_304;
V_61 = F_170 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_305;
V_61 = F_180 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_306;
V_61 = F_188 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_307;
V_61 = F_168 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_308;
V_61 = F_243 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_309;
V_61 = F_174 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_310;
V_61 = F_244 ( V_158 , V_229 , V_230 , V_111 ) ;
if ( V_61 )
goto V_311;
if ( V_227 != & V_312 ) {
V_61 = - V_103 ;
V_227 = F_245 ( V_111 -> V_239 -> V_240 ) ;
if ( ! V_227 )
goto V_311;
}
V_111 -> V_313 = ( V_158 & V_314 ) ? V_231 : NULL ;
V_111 -> V_148 = ( V_158 & V_315 ) ? V_231 : NULL ;
#ifdef F_175
V_111 -> V_316 = NULL ;
#endif
#ifdef F_154
V_111 -> V_145 = NULL ;
#ifdef F_156
V_111 -> V_146 = NULL ;
#endif
F_69 ( & V_111 -> V_147 ) ;
V_111 -> V_317 = NULL ;
#endif
F_246 ( V_111 ) ;
if ( ( V_158 & ( V_165 | V_318 ) ) == V_165 )
V_111 -> V_319 = V_111 -> V_320 = 0 ;
F_247 ( V_111 ) ;
F_248 ( V_111 , V_321 ) ;
#ifdef F_249
F_248 ( V_111 , F_249 ) ;
#endif
F_250 ( V_111 ) ;
V_111 -> V_227 = F_251 ( V_227 ) ;
if ( V_158 & V_198 ) {
V_111 -> V_322 = - 1 ;
V_111 -> V_210 = V_28 -> V_210 ;
V_111 -> V_323 = V_28 -> V_323 ;
} else {
if ( V_158 & V_236 )
V_111 -> V_322 = V_28 -> V_210 -> V_322 ;
else
V_111 -> V_322 = ( V_158 & V_324 ) ;
V_111 -> V_210 = V_111 ;
V_111 -> V_323 = V_111 -> V_227 ;
}
V_111 -> V_325 = 0 ;
V_111 -> V_26 = 0 ;
V_111 -> V_326 = 0 ;
V_111 -> V_327 = 128 >> ( V_328 - 10 ) ;
V_111 -> V_329 = 0 ;
F_69 ( & V_111 -> V_330 ) ;
V_111 -> V_331 = NULL ;
F_252 ( & V_1 ) ;
if ( V_158 & ( V_236 | V_198 ) ) {
V_111 -> V_332 = V_28 -> V_332 ;
V_111 -> V_333 = V_28 -> V_333 ;
} else {
V_111 -> V_332 = V_28 ;
V_111 -> V_333 = V_28 -> V_334 ;
}
F_128 ( & V_28 -> V_187 -> V_335 ) ;
F_253 () ;
if ( F_254 ( V_28 ) ) {
F_130 ( & V_28 -> V_187 -> V_335 ) ;
F_255 ( & V_1 ) ;
V_61 = - V_336 ;
goto V_337;
}
if ( F_105 ( V_111 -> V_227 ) ) {
F_256 ( V_111 , ( V_158 & V_338 ) || V_232 ) ;
F_203 ( V_111 , V_339 , V_227 ) ;
if ( F_257 ( V_111 ) ) {
F_203 ( V_111 , V_340 , F_258 ( V_28 ) ) ;
F_203 ( V_111 , V_341 , F_259 ( V_28 ) ) ;
if ( F_260 ( V_227 ) ) {
F_261 ( V_227 ) -> V_342 = V_111 ;
V_111 -> signal -> V_115 |= V_237 ;
}
V_111 -> signal -> V_343 = V_227 ;
V_111 -> signal -> V_344 = F_262 ( V_28 -> signal -> V_344 ) ;
F_263 ( & V_111 -> V_256 , & V_111 -> V_332 -> V_255 ) ;
F_264 ( & V_111 -> V_345 , & V_34 . V_345 ) ;
F_265 ( V_111 , V_340 ) ;
F_265 ( V_111 , V_341 ) ;
F_266 ( V_4 ) ;
} else {
V_28 -> signal -> V_199 ++ ;
F_140 ( & V_28 -> signal -> V_200 ) ;
F_140 ( & V_28 -> signal -> V_25 ) ;
F_264 ( & V_111 -> V_330 ,
& V_111 -> V_210 -> V_330 ) ;
}
F_265 ( V_111 , V_339 ) ;
V_199 ++ ;
}
V_346 ++ ;
F_130 ( & V_28 -> V_187 -> V_335 ) ;
F_255 ( & V_1 ) ;
F_267 ( V_111 ) ;
F_268 ( V_111 ) ;
if ( V_158 & V_198 )
F_269 ( V_28 ) ;
F_270 ( V_111 ) ;
F_271 ( V_111 , V_158 ) ;
return V_111 ;
V_337:
if ( V_227 != & V_312 )
F_272 ( V_227 ) ;
V_311:
if ( V_111 -> V_179 )
F_273 ( V_111 ) ;
V_310:
F_274 ( V_111 ) ;
V_309:
if ( V_111 -> V_51 )
F_119 ( V_111 -> V_51 ) ;
V_308:
if ( ! ( V_158 & V_198 ) )
F_28 ( V_111 -> signal ) ;
V_307:
F_182 ( V_111 -> V_187 ) ;
V_306:
F_275 ( V_111 ) ;
V_305:
F_276 ( V_111 ) ;
V_304:
F_277 ( V_111 ) ;
V_303:
F_278 ( V_111 ) ;
V_302:
F_279 ( V_111 ) ;
#ifdef F_227
F_90 ( V_111 -> V_276 ) ;
V_277:
#endif
if ( V_158 & V_198 )
F_269 ( V_28 ) ;
F_280 ( V_111 , 0 ) ;
F_38 ( V_111 ) ;
F_131 ( F_214 ( V_111 ) -> V_253 -> V_131 ) ;
V_252:
F_74 ( & V_111 -> V_347 -> V_245 -> V_246 ) ;
F_37 ( V_111 ) ;
V_250:
F_24 ( V_111 ) ;
V_241:
return F_144 ( V_61 ) ;
}
static inline void F_281 ( struct V_348 * V_349 )
{
enum V_226 type ;
for ( type = V_339 ; type < V_350 ; ++ type ) {
F_282 ( & V_349 [ type ] . V_7 ) ;
V_349 [ type ] . V_227 = & V_312 ;
}
}
struct V_5 * F_283 ( int V_2 )
{
struct V_5 * V_135 ;
V_135 = F_204 ( V_165 , 0 , 0 , NULL , & V_312 , 0 ) ;
if ( ! F_229 ( V_135 ) ) {
F_281 ( V_135 -> V_228 ) ;
F_284 ( V_135 , V_2 ) ;
}
return V_135 ;
}
long F_285 ( unsigned long V_158 ,
unsigned long V_229 ,
unsigned long V_230 ,
int T_2 * V_351 ,
int T_2 * V_231 )
{
struct V_5 * V_111 ;
int V_232 = 0 ;
long V_352 ;
if ( ! ( V_158 & V_353 ) ) {
if ( V_158 & V_318 )
V_232 = V_354 ;
else if ( ( V_158 & V_324 ) != V_355 )
V_232 = V_356 ;
else
V_232 = V_357 ;
if ( F_105 ( ! F_286 ( V_28 , V_232 ) ) )
V_232 = 0 ;
}
V_111 = F_204 ( V_158 , V_229 , V_230 ,
V_231 , NULL , V_232 ) ;
if ( ! F_229 ( V_111 ) ) {
struct V_140 V_141 ;
F_287 ( V_28 , V_111 ) ;
V_352 = F_288 ( V_111 ) ;
if ( V_158 & V_358 )
F_161 ( V_352 , V_351 ) ;
if ( V_158 & V_318 ) {
V_111 -> V_142 = & V_141 ;
F_289 ( & V_141 ) ;
F_290 ( V_111 ) ;
}
F_291 ( V_111 ) ;
if ( F_77 ( V_232 ) )
F_292 ( V_232 , V_352 ) ;
if ( V_158 & V_318 ) {
if ( ! F_148 ( V_111 , & V_141 ) )
F_292 ( V_359 , V_352 ) ;
}
} else {
V_352 = F_230 ( V_111 ) ;
}
return V_352 ;
}
T_3 F_293 ( int (* F_294)( void * ) , void * V_360 , unsigned long V_115 )
{
return F_285 ( V_115 | V_165 | V_353 , ( unsigned long ) F_294 ,
( unsigned long ) V_360 , NULL , NULL ) ;
}
static void F_295 ( void * V_361 )
{
struct V_185 * V_187 = V_361 ;
F_101 ( & V_187 -> V_335 ) ;
F_190 ( & V_187 -> V_362 ) ;
}
void T_1 F_296 ( void )
{
V_188 = F_18 ( L_5 ,
sizeof( struct V_185 ) , 0 ,
V_363 | V_30 | V_364 |
V_31 , F_295 ) ;
V_24 = F_18 ( L_6 ,
sizeof( struct V_22 ) , 0 ,
V_363 | V_30 | V_31 , NULL ) ;
V_365 = F_18 ( L_7 ,
sizeof( struct V_174 ) , 0 ,
V_363 | V_30 | V_31 , NULL ) ;
V_366 = F_18 ( L_8 ,
sizeof( struct V_167 ) , 0 ,
V_363 | V_30 | V_31 , NULL ) ;
V_367 = F_18 ( L_9 ,
sizeof( struct V_50 ) , V_368 ,
V_363 | V_30 | V_31 , NULL ) ;
V_80 = F_297 ( V_53 , V_30 ) ;
F_298 () ;
F_299 () ;
}
static int F_300 ( unsigned long V_369 )
{
if ( V_369 & ~ ( V_198 | V_169 | V_233 | V_186 |
V_165 | V_178 | V_370 |
V_371 | V_372 | V_373 |
V_235 | V_238 ) )
return - V_234 ;
if ( V_369 & ( V_198 | V_186 | V_165 ) ) {
if ( F_35 ( & V_28 -> V_51 -> V_112 ) > 1 )
return - V_234 ;
}
return 0 ;
}
static int F_301 ( unsigned long V_369 , struct V_167 * * V_374 )
{
struct V_167 * V_168 = V_28 -> V_168 ;
if ( ! ( V_369 & V_169 ) || ! V_168 )
return 0 ;
if ( V_168 -> V_173 == 1 )
return 0 ;
* V_374 = F_171 ( V_168 ) ;
if ( ! * V_374 )
return - V_103 ;
return 0 ;
}
static int F_302 ( unsigned long V_369 , struct V_174 * * V_375 )
{
struct V_174 * V_376 = V_28 -> V_177 ;
int error = 0 ;
if ( ( V_369 & V_178 ) &&
( V_376 && F_35 ( & V_376 -> V_125 ) > 1 ) ) {
* V_375 = F_173 ( V_376 , & error ) ;
if ( ! * V_375 )
return error ;
}
return 0 ;
}
int F_303 ( struct V_174 * * V_377 )
{
struct V_5 * V_135 = V_28 ;
struct V_174 * V_378 = NULL ;
int error ;
error = F_302 ( V_178 , & V_378 ) ;
if ( error || ! V_378 ) {
* V_377 = NULL ;
return error ;
}
* V_377 = V_135 -> V_177 ;
F_139 ( V_135 ) ;
V_135 -> V_177 = V_378 ;
F_141 ( V_135 ) ;
return 0 ;
}
