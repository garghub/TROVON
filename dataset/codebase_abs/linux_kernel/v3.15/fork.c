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
F_39 ( V_6 ) ;
F_31 ( V_6 -> signal ) ;
if ( ! F_40 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_41 ( void ) { }
void T_1 F_42 ( unsigned long V_29 )
{
#ifndef F_43
#ifndef F_44
#define F_44 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , sizeof( struct V_5 ) ,
F_44 , V_30 | V_31 , NULL ) ;
#endif
F_41 () ;
V_32 = V_29 / ( 8 * V_17 / V_33 ) ;
if ( V_32 < 20 )
V_32 = 20 ;
V_34 . signal -> V_35 [ V_36 ] . V_37 = V_32 / 2 ;
V_34 . signal -> V_35 [ V_36 ] . V_38 = V_32 / 2 ;
V_34 . signal -> V_35 [ V_39 ] =
V_34 . signal -> V_35 [ V_36 ] ;
}
int __weak F_45 ( struct V_5 * V_40 ,
struct V_5 * V_41 )
{
* V_40 = * V_41 ;
return 0 ;
}
static struct V_5 * F_46 ( struct V_5 * V_42 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
unsigned long * V_43 ;
int V_7 = F_47 ( V_42 ) ;
int V_44 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_45;
V_44 = F_45 ( V_6 , V_42 ) ;
if ( V_44 )
goto V_46;
V_6 -> V_21 = V_11 ;
F_48 ( V_6 , V_42 ) ;
F_49 ( V_6 ) ;
F_50 ( V_6 ) ;
V_43 = F_51 ( V_6 ) ;
* V_43 = V_47 ;
#ifdef F_52
V_6 -> V_48 = F_53 () ;
#endif
F_54 ( & V_6 -> V_27 , 2 ) ;
#ifdef F_55
V_6 -> V_49 = 0 ;
#endif
V_6 -> V_50 = NULL ;
V_6 -> V_51 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_46:
F_15 ( V_11 ) ;
V_45:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_56 ( struct V_52 * V_53 , struct V_52 * V_54 )
{
struct V_55 * V_56 , * V_57 , * V_58 , * * V_59 ;
struct V_60 * * V_61 , * V_62 ;
int V_63 ;
unsigned long V_64 ;
F_57 () ;
F_58 ( & V_54 -> V_65 ) ;
F_59 ( V_54 ) ;
F_60 ( V_54 , V_53 ) ;
F_61 ( & V_53 -> V_65 , V_66 ) ;
V_53 -> V_67 = 0 ;
V_53 -> V_68 = NULL ;
V_53 -> V_69 = 0 ;
V_53 -> V_70 = 0 ;
F_62 ( F_63 ( V_53 ) ) ;
V_53 -> V_71 = V_72 ;
V_61 = & V_53 -> V_71 . V_60 ;
V_62 = NULL ;
V_59 = & V_53 -> V_68 ;
V_63 = F_64 ( V_53 , V_54 ) ;
if ( V_63 )
goto V_73;
V_63 = F_65 ( V_53 , V_54 ) ;
if ( V_63 )
goto V_73;
V_58 = NULL ;
for ( V_56 = V_54 -> V_68 ; V_56 ; V_56 = V_56 -> V_74 ) {
struct V_75 * V_75 ;
if ( V_56 -> V_76 & V_77 ) {
F_66 ( V_53 , V_56 -> V_76 , V_56 -> V_78 ,
- F_67 ( V_56 ) ) ;
continue;
}
V_64 = 0 ;
if ( V_56 -> V_76 & V_79 ) {
unsigned long V_80 = F_67 ( V_56 ) ;
if ( F_68 ( V_54 , V_80 ) )
goto V_81;
V_64 = V_80 ;
}
V_57 = F_69 ( V_82 , V_9 ) ;
if ( ! V_57 )
goto V_81;
* V_57 = * V_56 ;
F_70 ( & V_57 -> V_83 ) ;
V_63 = F_71 ( V_56 , V_57 ) ;
if ( V_63 )
goto V_84;
V_57 -> V_85 = V_53 ;
if ( F_72 ( V_57 , V_56 ) )
goto V_86;
V_57 -> V_76 &= ~ V_87 ;
V_57 -> V_74 = V_57 -> V_88 = NULL ;
V_75 = V_57 -> V_78 ;
if ( V_75 ) {
struct V_89 * V_89 = F_73 ( V_75 ) ;
struct V_90 * V_91 = V_75 -> V_92 ;
F_74 ( V_75 ) ;
if ( V_57 -> V_76 & V_93 )
F_75 ( & V_89 -> V_94 ) ;
F_76 ( & V_91 -> V_95 ) ;
if ( V_57 -> V_76 & V_96 )
V_91 -> V_97 ++ ;
F_77 ( V_91 ) ;
if ( F_78 ( V_57 -> V_76 & V_98 ) )
F_79 ( V_57 ,
& V_91 -> V_99 ) ;
else
F_80 ( V_57 , V_56 ,
& V_91 -> V_100 ) ;
F_81 ( V_91 ) ;
F_82 ( & V_91 -> V_95 ) ;
}
if ( F_83 ( V_57 ) )
F_84 ( V_57 ) ;
* V_59 = V_57 ;
V_59 = & V_57 -> V_74 ;
V_57 -> V_88 = V_58 ;
V_58 = V_57 ;
F_85 ( V_53 , V_57 , V_61 , V_62 ) ;
V_61 = & V_57 -> V_101 . V_102 ;
V_62 = & V_57 -> V_101 ;
V_53 -> V_70 ++ ;
V_63 = F_86 ( V_53 , V_54 , V_56 ) ;
if ( V_57 -> V_103 && V_57 -> V_103 -> V_104 )
V_57 -> V_103 -> V_104 ( V_57 ) ;
if ( V_63 )
goto V_73;
}
F_87 ( V_54 , V_53 ) ;
V_63 = 0 ;
V_73:
F_88 ( & V_53 -> V_65 ) ;
F_89 ( V_54 ) ;
F_88 ( & V_54 -> V_65 ) ;
F_90 () ;
return V_63 ;
V_86:
F_91 ( F_92 ( V_57 ) ) ;
V_84:
F_10 ( V_82 , V_57 ) ;
V_81:
V_63 = - V_105 ;
F_93 ( V_64 ) ;
goto V_73;
}
static inline int F_94 ( struct V_52 * V_53 )
{
V_53 -> V_106 = F_95 ( V_53 ) ;
if ( F_78 ( ! V_53 -> V_106 ) )
return - V_105 ;
return 0 ;
}
static inline void F_96 ( struct V_52 * V_53 )
{
F_97 ( V_53 , V_53 -> V_106 ) ;
}
static int T_1 F_98 ( char * V_107 )
{
V_108 =
( F_99 ( V_107 , NULL , 0 ) << V_109 ) &
V_110 ;
return 1 ;
}
static void F_100 ( struct V_52 * V_53 )
{
#ifdef F_101
F_102 ( & V_53 -> V_111 ) ;
V_53 -> V_112 = NULL ;
#endif
}
static struct V_52 * F_103 ( struct V_52 * V_53 , struct V_5 * V_113 )
{
F_54 ( & V_53 -> V_114 , 1 ) ;
F_54 ( & V_53 -> V_115 , 1 ) ;
F_104 ( & V_53 -> V_65 ) ;
F_70 ( & V_53 -> V_116 ) ;
V_53 -> V_117 = NULL ;
F_105 ( & V_53 -> V_118 , 0 ) ;
memset ( & V_53 -> V_119 , 0 , sizeof( V_53 -> V_119 ) ) ;
F_102 ( & V_53 -> V_120 ) ;
F_100 ( V_53 ) ;
F_106 ( V_53 , V_113 ) ;
F_107 ( V_53 ) ;
if ( V_28 -> V_53 ) {
V_53 -> V_121 = V_28 -> V_53 -> V_121 & V_122 ;
V_53 -> V_123 = V_28 -> V_53 -> V_123 & V_124 ;
} else {
V_53 -> V_121 = V_108 ;
V_53 -> V_123 = 0 ;
}
if ( F_108 ( ! F_94 ( V_53 ) ) ) {
F_109 ( V_53 ) ;
return V_53 ;
}
F_110 ( V_53 ) ;
return NULL ;
}
static void F_111 ( struct V_52 * V_53 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
long V_127 = F_112 ( & V_53 -> V_119 . V_128 [ V_125 ] ) ;
if ( F_78 ( V_127 ) )
F_113 ( V_129 L_3
L_4 , V_53 , V_125 , V_127 ) ;
}
#if F_114 ( V_130 ) && ! V_131
F_115 ( V_53 -> V_132 ) ;
#endif
}
struct V_52 * F_116 ( void )
{
struct V_52 * V_53 ;
V_53 = F_117 () ;
if ( ! V_53 )
return NULL ;
memset ( V_53 , 0 , sizeof( * V_53 ) ) ;
F_118 ( V_53 ) ;
return F_103 ( V_53 , V_28 ) ;
}
void F_119 ( struct V_52 * V_53 )
{
F_19 ( V_53 == & V_133 ) ;
F_96 ( V_53 ) ;
F_120 ( V_53 ) ;
F_121 ( V_53 ) ;
F_111 ( V_53 ) ;
F_110 ( V_53 ) ;
}
void F_122 ( struct V_52 * V_53 )
{
F_123 () ;
if ( F_32 ( & V_53 -> V_114 ) ) {
F_124 ( V_53 ) ;
F_125 ( V_53 ) ;
F_126 ( V_53 ) ;
F_127 ( V_53 ) ;
F_128 ( V_53 ) ;
F_129 ( V_53 , NULL ) ;
if ( ! F_130 ( & V_53 -> V_116 ) ) {
F_131 ( & V_134 ) ;
F_132 ( & V_53 -> V_116 ) ;
F_133 ( & V_134 ) ;
}
if ( V_53 -> V_135 )
F_134 ( V_53 -> V_135 -> V_136 ) ;
F_135 ( V_53 ) ;
}
}
void F_129 ( struct V_52 * V_53 , struct V_75 * V_137 )
{
if ( V_137 )
F_74 ( V_137 ) ;
if ( V_53 -> V_138 )
F_136 ( V_53 -> V_138 ) ;
V_53 -> V_138 = V_137 ;
}
struct V_75 * F_137 ( struct V_52 * V_53 )
{
struct V_75 * V_138 ;
F_138 ( & V_53 -> V_65 ) ;
V_138 = V_53 -> V_138 ;
if ( V_138 )
F_74 ( V_138 ) ;
F_139 ( & V_53 -> V_65 ) ;
return V_138 ;
}
static void F_140 ( struct V_52 * V_54 , struct V_52 * V_139 )
{
V_139 -> V_138 = F_137 ( V_54 ) ;
}
struct V_52 * F_141 ( struct V_5 * V_140 )
{
struct V_52 * V_53 ;
F_142 ( V_140 ) ;
V_53 = V_140 -> V_53 ;
if ( V_53 ) {
if ( V_140 -> V_121 & V_141 )
V_53 = NULL ;
else
F_143 ( & V_53 -> V_114 ) ;
}
F_144 ( V_140 ) ;
return V_53 ;
}
struct V_52 * F_145 ( struct V_5 * V_140 , unsigned int V_142 )
{
struct V_52 * V_53 ;
int V_44 ;
V_44 = F_146 ( & V_140 -> signal -> V_143 ) ;
if ( V_44 )
return F_147 ( V_44 ) ;
V_53 = F_141 ( V_140 ) ;
if ( V_53 && V_53 != V_28 -> V_53 &&
! F_148 ( V_140 , V_142 ) ) {
F_122 ( V_53 ) ;
V_53 = F_147 ( - V_144 ) ;
}
F_82 ( & V_140 -> signal -> V_143 ) ;
return V_53 ;
}
static void F_149 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
F_142 ( V_6 ) ;
V_146 = V_6 -> V_147 ;
if ( F_108 ( V_146 ) ) {
V_6 -> V_147 = NULL ;
F_150 ( V_146 ) ;
}
F_144 ( V_6 ) ;
}
static int F_151 ( struct V_5 * V_148 ,
struct V_145 * V_146 )
{
int V_149 ;
F_152 () ;
V_149 = F_153 ( V_146 ) ;
F_154 () ;
if ( V_149 ) {
F_142 ( V_148 ) ;
V_148 -> V_147 = NULL ;
F_144 ( V_148 ) ;
}
F_155 ( V_148 ) ;
return V_149 ;
}
void F_156 ( struct V_5 * V_6 , struct V_52 * V_53 )
{
#ifdef F_157
if ( F_78 ( V_6 -> V_150 ) ) {
F_158 ( V_6 ) ;
V_6 -> V_150 = NULL ;
}
#ifdef F_159
if ( F_78 ( V_6 -> V_151 ) ) {
F_160 ( V_6 ) ;
V_6 -> V_151 = NULL ;
}
#endif
if ( F_78 ( ! F_130 ( & V_6 -> V_152 ) ) )
F_161 ( V_6 ) ;
#endif
F_162 ( V_6 ) ;
F_163 ( V_6 , V_53 ) ;
if ( V_6 -> V_153 ) {
if ( ! ( V_6 -> V_121 & V_154 ) &&
F_35 ( & V_53 -> V_114 ) > 1 ) {
F_164 ( 0 , V_6 -> V_153 ) ;
F_165 ( V_6 -> V_153 , V_155 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_153 = NULL ;
}
if ( V_6 -> V_147 )
F_149 ( V_6 ) ;
}
static struct V_52 * F_166 ( struct V_5 * V_6 )
{
struct V_52 * V_53 , * V_54 = V_28 -> V_53 ;
int V_44 ;
V_53 = F_117 () ;
if ( ! V_53 )
goto V_81;
memcpy ( V_53 , V_54 , sizeof( * V_53 ) ) ;
F_118 ( V_53 ) ;
#if F_114 ( V_130 ) && ! V_131
V_53 -> V_132 = NULL ;
#endif
if ( ! F_103 ( V_53 , V_6 ) )
goto V_81;
if ( F_167 ( V_6 , V_53 ) )
goto V_156;
F_140 ( V_54 , V_53 ) ;
V_44 = F_56 ( V_53 , V_54 ) ;
if ( V_44 )
goto V_157;
V_53 -> V_158 = F_168 ( V_53 ) ;
V_53 -> V_159 = V_53 -> V_160 ;
if ( V_53 -> V_135 && ! F_169 ( V_53 -> V_135 -> V_136 ) )
goto V_157;
return V_53 ;
V_157:
V_53 -> V_135 = NULL ;
F_122 ( V_53 ) ;
V_81:
return NULL ;
V_156:
F_96 ( V_53 ) ;
F_110 ( V_53 ) ;
return NULL ;
}
static int F_170 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_52 * V_53 , * V_54 ;
int V_63 ;
V_6 -> V_162 = V_6 -> V_163 = 0 ;
V_6 -> V_164 = V_6 -> V_165 = 0 ;
#ifdef F_171
V_6 -> V_166 = V_6 -> V_164 + V_6 -> V_165 ;
#endif
V_6 -> V_53 = NULL ;
V_6 -> V_167 = NULL ;
V_54 = V_28 -> V_53 ;
if ( ! V_54 )
return 0 ;
F_172 ( V_6 ) ;
if ( V_161 & V_168 ) {
F_143 ( & V_54 -> V_114 ) ;
V_53 = V_54 ;
goto V_169;
}
V_63 = - V_105 ;
V_53 = F_166 ( V_6 ) ;
if ( ! V_53 )
goto V_81;
V_169:
V_6 -> V_53 = V_53 ;
V_6 -> V_167 = V_53 ;
return 0 ;
V_81:
return V_63 ;
}
static int F_173 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_170 * V_171 = V_28 -> V_171 ;
if ( V_161 & V_172 ) {
F_131 ( & V_171 -> V_173 ) ;
if ( V_171 -> V_174 ) {
F_133 ( & V_171 -> V_173 ) ;
return - V_175 ;
}
V_171 -> V_176 ++ ;
F_133 ( & V_171 -> V_173 ) ;
return 0 ;
}
V_6 -> V_171 = F_174 ( V_171 ) ;
if ( ! V_6 -> V_171 )
return - V_105 ;
return 0 ;
}
static int F_175 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_177 * V_178 , * V_179 ;
int error = 0 ;
V_178 = V_28 -> V_180 ;
if ( ! V_178 )
goto V_73;
if ( V_161 & V_181 ) {
F_143 ( & V_178 -> V_128 ) ;
goto V_73;
}
V_179 = F_176 ( V_178 , & error ) ;
if ( ! V_179 )
goto V_73;
V_6 -> V_180 = V_179 ;
error = 0 ;
V_73:
return error ;
}
static int F_177 ( unsigned long V_161 , struct V_5 * V_6 )
{
#ifdef F_178
struct V_182 * V_183 = V_28 -> V_182 ;
struct V_182 * V_184 ;
if ( ! V_183 )
return 0 ;
if ( V_161 & V_185 ) {
F_179 ( V_183 ) ;
V_6 -> V_182 = V_183 ;
} else if ( F_180 ( V_183 -> V_186 ) ) {
V_184 = F_181 ( V_6 , V_9 , V_187 ) ;
if ( F_78 ( ! V_184 ) )
return - V_105 ;
V_184 -> V_186 = V_183 -> V_186 ;
F_182 ( V_184 ) ;
}
#endif
return 0 ;
}
static int F_183 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_188 * V_23 ;
if ( V_161 & V_189 ) {
F_143 ( & V_28 -> V_190 -> V_128 ) ;
return 0 ;
}
V_23 = F_69 ( V_191 , V_9 ) ;
F_184 ( V_6 -> V_190 , V_23 ) ;
if ( ! V_23 )
return - V_105 ;
F_54 ( & V_23 -> V_128 , 1 ) ;
memcpy ( V_23 -> V_192 , V_28 -> V_190 -> V_192 , sizeof( V_23 -> V_192 ) ) ;
return 0 ;
}
void F_185 ( struct V_188 * V_190 )
{
if ( F_32 ( & V_190 -> V_128 ) ) {
F_186 ( V_190 ) ;
F_10 ( V_191 , V_190 ) ;
}
}
static void F_187 ( struct V_22 * V_23 )
{
unsigned long V_193 ;
F_188 ( V_23 ) ;
V_193 = F_189 ( V_23 -> V_35 [ V_194 ] . V_37 ) ;
if ( V_193 != V_195 ) {
V_23 -> V_196 . V_197 = F_190 ( V_193 ) ;
V_23 -> V_198 . V_199 = 1 ;
}
F_70 ( & V_23 -> V_200 [ 0 ] ) ;
F_70 ( & V_23 -> V_200 [ 1 ] ) ;
F_70 ( & V_23 -> V_200 [ 2 ] ) ;
}
static int F_191 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_22 * V_23 ;
if ( V_161 & V_201 )
return 0 ;
V_23 = F_192 ( V_24 , V_9 ) ;
V_6 -> signal = V_23 ;
if ( ! V_23 )
return - V_105 ;
V_23 -> V_202 = 1 ;
F_54 ( & V_23 -> V_203 , 1 ) ;
F_54 ( & V_23 -> V_25 , 1 ) ;
V_23 -> V_204 = (struct V_205 ) F_193 ( V_6 -> V_206 ) ;
V_6 -> V_206 = (struct V_205 ) F_193 ( V_23 -> V_204 ) ;
F_194 ( & V_23 -> V_207 ) ;
V_23 -> V_208 = V_6 ;
F_195 ( & V_23 -> V_209 ) ;
F_70 ( & V_23 -> V_210 ) ;
F_196 ( & V_23 -> V_211 , V_212 , V_213 ) ;
V_23 -> V_211 . V_214 = V_215 ;
F_142 ( V_28 -> V_216 ) ;
memcpy ( V_23 -> V_35 , V_28 -> signal -> V_35 , sizeof V_23 -> V_35 ) ;
F_144 ( V_28 -> V_216 ) ;
F_187 ( V_23 ) ;
F_197 ( V_23 ) ;
F_198 ( V_23 ) ;
#ifdef F_199
F_104 ( & V_23 -> V_217 ) ;
#endif
V_23 -> V_218 = V_28 -> signal -> V_218 ;
V_23 -> V_219 = V_28 -> signal -> V_219 ;
V_23 -> V_220 = V_28 -> signal -> V_220 ||
V_28 -> signal -> V_221 ;
F_200 ( & V_23 -> V_143 ) ;
return 0 ;
}
static void F_201 ( struct V_5 * V_113 )
{
F_202 ( & V_113 -> V_222 ) ;
#ifdef F_203
V_113 -> V_223 = V_72 ;
V_113 -> V_224 = NULL ;
V_113 -> V_225 = NULL ;
V_113 -> V_226 = NULL ;
#endif
}
void F_106 ( struct V_52 * V_53 , struct V_5 * V_113 )
{
V_53 -> V_227 = V_113 ;
}
static void F_204 ( struct V_5 * V_6 )
{
V_6 -> V_196 . V_197 = 0 ;
V_6 -> V_196 . V_228 = 0 ;
V_6 -> V_196 . V_229 = 0 ;
F_70 ( & V_6 -> V_200 [ 0 ] ) ;
F_70 ( & V_6 -> V_200 [ 1 ] ) ;
F_70 ( & V_6 -> V_200 [ 2 ] ) ;
}
static inline void
F_205 ( struct V_5 * V_140 , enum V_230 type , struct V_231 * V_231 )
{
V_140 -> V_232 [ type ] . V_231 = V_231 ;
}
static struct V_5 * F_206 ( unsigned long V_161 ,
unsigned long V_233 ,
unsigned long V_234 ,
int T_2 * V_235 ,
struct V_231 * V_231 ,
int V_236 )
{
int V_63 ;
struct V_5 * V_113 ;
if ( ( V_161 & ( V_237 | V_172 ) ) == ( V_237 | V_172 ) )
return F_147 ( - V_238 ) ;
if ( ( V_161 & ( V_239 | V_172 ) ) == ( V_239 | V_172 ) )
return F_147 ( - V_238 ) ;
if ( ( V_161 & V_201 ) && ! ( V_161 & V_189 ) )
return F_147 ( - V_238 ) ;
if ( ( V_161 & V_189 ) && ! ( V_161 & V_168 ) )
return F_147 ( - V_238 ) ;
if ( ( V_161 & V_240 ) &&
V_28 -> signal -> V_121 & V_241 )
return F_147 ( - V_238 ) ;
if ( V_161 & V_189 ) {
if ( ( V_161 & ( V_239 | V_242 ) ) ||
( F_207 ( V_28 ) !=
V_28 -> V_243 -> V_244 ) )
return F_147 ( - V_238 ) ;
}
V_63 = F_208 ( V_161 ) ;
if ( V_63 )
goto V_245;
V_63 = - V_105 ;
V_113 = F_46 ( V_28 ) ;
if ( ! V_113 )
goto V_245;
F_209 ( V_113 ) ;
F_210 ( V_113 ) ;
F_201 ( V_113 ) ;
#ifdef F_211
F_212 ( ! V_113 -> V_246 ) ;
F_212 ( ! V_113 -> V_247 ) ;
#endif
V_63 = - V_175 ;
if ( F_35 ( & V_113 -> V_248 -> V_249 -> V_250 ) >=
F_213 ( V_113 , V_36 ) ) {
if ( V_113 -> V_248 -> V_249 != V_251 &&
! F_214 ( V_252 ) && ! F_214 ( V_253 ) )
goto V_254;
}
V_28 -> V_121 &= ~ V_255 ;
V_63 = F_215 ( V_113 , V_161 ) ;
if ( V_63 < 0 )
goto V_254;
V_63 = - V_175 ;
if ( V_202 >= V_32 )
goto V_256;
if ( ! F_169 ( F_216 ( V_113 ) -> V_257 -> V_136 ) )
goto V_256;
F_217 ( V_113 ) ;
V_113 -> V_121 &= ~ ( V_258 | V_259 ) ;
V_113 -> V_121 |= V_260 ;
F_70 ( & V_113 -> V_261 ) ;
F_70 ( & V_113 -> V_262 ) ;
F_218 ( V_113 ) ;
V_113 -> V_147 = NULL ;
F_102 ( & V_113 -> V_263 ) ;
F_195 ( & V_113 -> V_264 ) ;
V_113 -> V_265 = V_113 -> V_266 = V_113 -> V_267 = 0 ;
V_113 -> V_268 = V_113 -> V_269 = 0 ;
#ifndef F_219
V_113 -> V_270 . V_265 = V_113 -> V_270 . V_266 = 0 ;
#endif
#ifdef F_220
F_221 ( & V_113 -> V_271 ) ;
V_113 -> V_272 = 0 ;
V_113 -> V_273 = V_274 ;
#endif
#if F_114 ( V_275 )
memset ( & V_113 -> V_119 , 0 , sizeof( V_113 -> V_119 ) ) ;
#endif
V_113 -> V_276 = V_28 -> V_277 ;
F_222 ( & V_113 -> V_278 ) ;
F_223 ( V_113 ) ;
F_204 ( V_113 ) ;
F_224 ( & V_113 -> V_279 ) ;
V_113 -> V_280 = V_113 -> V_279 ;
F_225 ( & V_113 -> V_280 ) ;
V_113 -> V_182 = NULL ;
V_113 -> V_281 = NULL ;
if ( V_161 & V_201 )
F_226 ( V_28 ) ;
F_227 ( V_113 ) ;
#ifdef F_228
V_113 -> V_282 = F_229 ( V_113 -> V_282 ) ;
if ( F_230 ( V_113 -> V_282 ) ) {
V_63 = F_231 ( V_113 -> V_282 ) ;
V_113 -> V_282 = NULL ;
goto V_283;
}
#endif
#ifdef F_232
V_113 -> V_284 = V_187 ;
V_113 -> V_285 = V_187 ;
F_233 ( & V_113 -> V_286 ) ;
#endif
#ifdef F_234
V_113 -> V_287 = 0 ;
V_113 -> V_246 = 0 ;
V_113 -> V_288 = 0 ;
V_113 -> V_289 = 0 ;
V_113 -> V_290 = V_291 ;
V_113 -> V_292 = 0 ;
V_113 -> V_247 = 1 ;
V_113 -> V_293 = V_291 ;
V_113 -> V_294 = 0 ;
V_113 -> V_295 = 0 ;
V_113 -> V_296 = 0 ;
V_113 -> V_297 = 0 ;
V_113 -> V_298 = 0 ;
#endif
#ifdef F_235
V_113 -> V_299 = 0 ;
V_113 -> V_300 = 0 ;
V_113 -> V_301 = 0 ;
#endif
#ifdef F_236
V_113 -> V_302 = NULL ;
#endif
#ifdef F_237
V_113 -> V_303 . V_304 = 0 ;
V_113 -> V_303 . V_305 = NULL ;
#endif
#ifdef F_238
V_113 -> V_306 = 0 ;
V_113 -> V_307 = 0 ;
#endif
V_63 = F_239 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_308;
V_63 = F_240 ( V_113 ) ;
if ( V_63 )
goto V_308;
V_63 = F_241 ( V_113 ) ;
if ( V_63 )
goto V_308;
V_63 = F_242 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_309;
V_63 = F_175 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_310;
V_63 = F_173 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_311;
V_63 = F_183 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_312;
V_63 = F_191 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_313;
V_63 = F_170 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_314;
V_63 = F_243 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_315;
V_63 = F_177 ( V_161 , V_113 ) ;
if ( V_63 )
goto V_316;
V_63 = F_244 ( V_161 , V_233 , V_234 , V_113 ) ;
if ( V_63 )
goto V_317;
if ( V_231 != & V_318 ) {
V_63 = - V_105 ;
V_231 = F_245 ( V_113 -> V_243 -> V_244 ) ;
if ( ! V_231 )
goto V_317;
}
V_113 -> V_319 = ( V_161 & V_320 ) ? V_235 : NULL ;
V_113 -> V_153 = ( V_161 & V_321 ) ? V_235 : NULL ;
#ifdef F_178
V_113 -> V_322 = NULL ;
#endif
#ifdef F_157
V_113 -> V_150 = NULL ;
#ifdef F_159
V_113 -> V_151 = NULL ;
#endif
F_70 ( & V_113 -> V_152 ) ;
V_113 -> V_323 = NULL ;
#endif
if ( ( V_161 & ( V_168 | V_324 ) ) == V_168 )
V_113 -> V_325 = V_113 -> V_326 = 0 ;
F_246 ( V_113 ) ;
F_247 ( V_113 , V_327 ) ;
#ifdef F_248
F_247 ( V_113 , F_248 ) ;
#endif
F_249 ( V_113 ) ;
V_113 -> V_231 = F_250 ( V_231 ) ;
if ( V_161 & V_201 ) {
V_113 -> V_328 = - 1 ;
V_113 -> V_216 = V_28 -> V_216 ;
V_113 -> V_329 = V_28 -> V_329 ;
} else {
if ( V_161 & V_240 )
V_113 -> V_328 = V_28 -> V_216 -> V_328 ;
else
V_113 -> V_328 = ( V_161 & V_330 ) ;
V_113 -> V_216 = V_113 ;
V_113 -> V_329 = V_113 -> V_231 ;
}
V_113 -> V_331 = 0 ;
V_113 -> V_332 = 128 >> ( V_333 - 10 ) ;
V_113 -> V_334 = 0 ;
V_113 -> V_335 = 0 ;
F_70 ( & V_113 -> V_336 ) ;
V_113 -> V_337 = NULL ;
F_251 ( & V_1 ) ;
if ( V_161 & ( V_240 | V_201 ) ) {
V_113 -> V_338 = V_28 -> V_338 ;
V_113 -> V_339 = V_28 -> V_339 ;
} else {
V_113 -> V_338 = V_28 ;
V_113 -> V_339 = V_28 -> V_340 ;
}
F_131 ( & V_28 -> V_190 -> V_341 ) ;
F_252 () ;
if ( F_253 ( V_28 ) ) {
F_133 ( & V_28 -> V_190 -> V_341 ) ;
F_254 ( & V_1 ) ;
V_63 = - V_342 ;
goto V_343;
}
if ( F_108 ( V_113 -> V_231 ) ) {
F_255 ( V_113 , ( V_161 & V_344 ) || V_236 ) ;
F_205 ( V_113 , V_345 , V_231 ) ;
if ( F_256 ( V_113 ) ) {
F_205 ( V_113 , V_346 , F_257 ( V_28 ) ) ;
F_205 ( V_113 , V_347 , F_258 ( V_28 ) ) ;
if ( F_259 ( V_231 ) ) {
F_260 ( V_231 ) -> V_348 = V_113 ;
V_113 -> signal -> V_121 |= V_241 ;
}
V_113 -> signal -> V_349 = V_231 ;
V_113 -> signal -> V_350 = F_261 ( V_28 -> signal -> V_350 ) ;
F_262 ( & V_113 -> V_262 , & V_113 -> V_338 -> V_261 ) ;
F_263 ( & V_113 -> V_351 , & V_34 . V_351 ) ;
F_264 ( V_113 , V_346 ) ;
F_264 ( V_113 , V_347 ) ;
F_265 ( V_4 ) ;
} else {
V_28 -> signal -> V_202 ++ ;
F_143 ( & V_28 -> signal -> V_203 ) ;
F_143 ( & V_28 -> signal -> V_25 ) ;
F_263 ( & V_113 -> V_336 ,
& V_113 -> V_216 -> V_336 ) ;
F_263 ( & V_113 -> V_206 ,
& V_113 -> signal -> V_204 ) ;
}
F_264 ( V_113 , V_345 ) ;
V_202 ++ ;
}
V_352 ++ ;
F_133 ( & V_28 -> V_190 -> V_341 ) ;
F_254 ( & V_1 ) ;
F_266 ( V_113 ) ;
F_267 ( V_113 ) ;
if ( V_161 & V_201 )
F_268 ( V_28 ) ;
F_269 ( V_113 ) ;
F_270 ( V_113 , V_161 ) ;
F_271 ( V_113 , V_161 ) ;
return V_113 ;
V_343:
if ( V_231 != & V_318 )
F_272 ( V_231 ) ;
V_317:
if ( V_113 -> V_182 )
F_273 ( V_113 ) ;
V_316:
F_274 ( V_113 ) ;
V_315:
if ( V_113 -> V_53 )
F_122 ( V_113 -> V_53 ) ;
V_314:
if ( ! ( V_161 & V_201 ) )
F_28 ( V_113 -> signal ) ;
V_313:
F_185 ( V_113 -> V_190 ) ;
V_312:
F_275 ( V_113 ) ;
V_311:
F_276 ( V_113 ) ;
V_310:
F_277 ( V_113 ) ;
V_309:
F_278 ( V_113 ) ;
V_308:
F_279 ( V_113 ) ;
#ifdef F_228
F_91 ( V_113 -> V_282 ) ;
V_283:
#endif
if ( V_161 & V_201 )
F_268 ( V_28 ) ;
F_39 ( V_113 ) ;
F_134 ( F_216 ( V_113 ) -> V_257 -> V_136 ) ;
V_256:
F_75 ( & V_113 -> V_353 -> V_249 -> V_250 ) ;
F_38 ( V_113 ) ;
V_254:
F_24 ( V_113 ) ;
V_245:
return F_147 ( V_63 ) ;
}
static inline void F_280 ( struct V_354 * V_355 )
{
enum V_230 type ;
for ( type = V_345 ; type < V_356 ; ++ type ) {
F_281 ( & V_355 [ type ] . V_7 ) ;
V_355 [ type ] . V_231 = & V_318 ;
}
}
struct V_5 * F_282 ( int V_2 )
{
struct V_5 * V_140 ;
V_140 = F_206 ( V_168 , 0 , 0 , NULL , & V_318 , 0 ) ;
if ( ! F_230 ( V_140 ) ) {
F_280 ( V_140 -> V_232 ) ;
F_283 ( V_140 , V_2 ) ;
}
return V_140 ;
}
long F_284 ( unsigned long V_161 ,
unsigned long V_233 ,
unsigned long V_234 ,
int T_2 * V_357 ,
int T_2 * V_235 )
{
struct V_5 * V_113 ;
int V_236 = 0 ;
long V_358 ;
if ( ! ( V_161 & V_359 ) ) {
if ( V_161 & V_324 )
V_236 = V_360 ;
else if ( ( V_161 & V_330 ) != V_361 )
V_236 = V_362 ;
else
V_236 = V_363 ;
if ( F_108 ( ! F_285 ( V_28 , V_236 ) ) )
V_236 = 0 ;
}
V_113 = F_206 ( V_161 , V_233 , V_234 ,
V_235 , NULL , V_236 ) ;
if ( ! F_230 ( V_113 ) ) {
struct V_145 V_146 ;
F_286 ( V_28 , V_113 ) ;
V_358 = F_287 ( V_113 ) ;
if ( V_161 & V_364 )
F_164 ( V_358 , V_357 ) ;
if ( V_161 & V_324 ) {
V_113 -> V_147 = & V_146 ;
F_288 ( & V_146 ) ;
F_289 ( V_113 ) ;
}
F_290 ( V_113 ) ;
if ( F_78 ( V_236 ) )
F_291 ( V_236 , V_358 ) ;
if ( V_161 & V_324 ) {
if ( ! F_151 ( V_113 , & V_146 ) )
F_291 ( V_365 , V_358 ) ;
}
} else {
V_358 = F_231 ( V_113 ) ;
}
return V_358 ;
}
T_3 F_292 ( int (* F_293)( void * ) , void * V_366 , unsigned long V_121 )
{
return F_284 ( V_121 | V_168 | V_359 , ( unsigned long ) F_293 ,
( unsigned long ) V_366 , NULL , NULL ) ;
}
static void F_294 ( void * V_367 )
{
struct V_188 * V_190 = V_367 ;
F_102 ( & V_190 -> V_341 ) ;
F_194 ( & V_190 -> V_368 ) ;
}
void T_1 F_295 ( void )
{
V_191 = F_18 ( L_5 ,
sizeof( struct V_188 ) , 0 ,
V_369 | V_30 | V_370 |
V_31 , F_294 ) ;
V_24 = F_18 ( L_6 ,
sizeof( struct V_22 ) , 0 ,
V_369 | V_30 | V_31 , NULL ) ;
V_371 = F_18 ( L_7 ,
sizeof( struct V_177 ) , 0 ,
V_369 | V_30 | V_31 , NULL ) ;
V_372 = F_18 ( L_8 ,
sizeof( struct V_170 ) , 0 ,
V_369 | V_30 | V_31 , NULL ) ;
V_373 = F_18 ( L_9 ,
sizeof( struct V_52 ) , V_374 ,
V_369 | V_30 | V_31 , NULL ) ;
V_82 = F_296 ( V_55 , V_30 ) ;
F_297 () ;
F_298 () ;
}
static int F_299 ( unsigned long V_375 )
{
if ( V_375 & ~ ( V_201 | V_172 | V_237 | V_189 |
V_168 | V_181 | V_376 |
V_377 | V_378 | V_379 |
V_239 | V_242 ) )
return - V_238 ;
if ( V_375 & ( V_201 | V_189 | V_168 ) ) {
if ( F_35 ( & V_28 -> V_53 -> V_114 ) > 1 )
return - V_238 ;
}
return 0 ;
}
static int F_300 ( unsigned long V_375 , struct V_170 * * V_380 )
{
struct V_170 * V_171 = V_28 -> V_171 ;
if ( ! ( V_375 & V_172 ) || ! V_171 )
return 0 ;
if ( V_171 -> V_176 == 1 )
return 0 ;
* V_380 = F_174 ( V_171 ) ;
if ( ! * V_380 )
return - V_105 ;
return 0 ;
}
static int F_301 ( unsigned long V_375 , struct V_177 * * V_381 )
{
struct V_177 * V_382 = V_28 -> V_180 ;
int error = 0 ;
if ( ( V_375 & V_181 ) &&
( V_382 && F_35 ( & V_382 -> V_128 ) > 1 ) ) {
* V_381 = F_176 ( V_382 , & error ) ;
if ( ! * V_381 )
return error ;
}
return 0 ;
}
int F_302 ( struct V_177 * * V_383 )
{
struct V_5 * V_140 = V_28 ;
struct V_177 * V_384 = NULL ;
int error ;
error = F_301 ( V_181 , & V_384 ) ;
if ( error || ! V_384 ) {
* V_383 = NULL ;
return error ;
}
* V_383 = V_140 -> V_180 ;
F_142 ( V_140 ) ;
V_140 -> V_180 = V_384 ;
F_144 ( V_140 ) ;
return 0 ;
}
