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
F_39 ( V_6 ) ;
F_40 ( V_6 ) ;
F_31 ( V_6 -> signal ) ;
if ( ! F_41 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_42 ( void ) { }
static void F_43 ( unsigned int V_28 )
{
T_2 V_29 ;
if ( F_44 ( V_30 ) + F_44 ( V_31 ) > 64 )
V_29 = V_32 ;
else
V_29 = F_45 ( ( T_2 ) V_30 * ( T_2 ) V_31 ,
( T_2 ) V_16 * 8UL ) ;
if ( V_29 > V_28 )
V_29 = V_28 ;
V_33 = F_46 ( T_2 , V_29 , V_34 , V_32 ) ;
}
void T_1 F_47 ( void )
{
#ifndef F_48
#ifndef F_49
#define F_49 L1_CACHE_BYTES
#endif
V_8 = F_18 ( L_2 ,
V_35 , F_49 ,
V_36 | V_37 | V_38 , NULL ) ;
#endif
F_42 () ;
F_43 ( V_32 ) ;
V_39 . signal -> V_40 [ V_41 ] . V_42 = V_33 / 2 ;
V_39 . signal -> V_40 [ V_41 ] . V_43 = V_33 / 2 ;
V_39 . signal -> V_40 [ V_44 ] =
V_39 . signal -> V_40 [ V_41 ] ;
}
int __weak F_50 ( struct V_5 * V_45 ,
struct V_5 * V_46 )
{
* V_45 = * V_46 ;
return 0 ;
}
void F_51 ( struct V_5 * V_6 )
{
unsigned long * V_47 ;
V_47 = F_52 ( V_6 ) ;
* V_47 = V_48 ;
}
static struct V_5 * F_53 ( struct V_5 * V_49 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_7 = F_54 ( V_49 ) ;
int V_50 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_51;
V_50 = F_50 ( V_6 , V_49 ) ;
if ( V_50 )
goto V_52;
V_6 -> V_20 = V_11 ;
#ifdef F_55
V_6 -> V_53 . V_54 = NULL ;
#endif
F_56 ( V_6 , V_49 ) ;
F_57 ( V_6 ) ;
F_58 ( V_6 ) ;
F_51 ( V_6 ) ;
#ifdef F_59
V_6 -> V_55 = F_60 () ;
#endif
F_61 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_62
V_6 -> V_56 = 0 ;
#endif
V_6 -> V_57 = NULL ;
V_6 -> V_58 . V_12 = NULL ;
V_6 -> V_59 . V_60 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_52:
F_15 ( V_11 ) ;
V_51:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_63 ( struct V_61 * V_62 , struct V_61 * V_63 )
{
struct V_64 * V_65 , * V_66 , * V_67 , * * V_68 ;
struct V_69 * * V_70 , * V_71 ;
int V_72 ;
unsigned long V_73 ;
F_64 () ;
F_65 ( & V_63 -> V_74 ) ;
F_66 ( V_63 ) ;
F_67 ( V_63 , V_62 ) ;
F_68 ( & V_62 -> V_74 , V_75 ) ;
F_69 ( V_62 -> V_76 , F_70 ( V_63 ) ) ;
V_62 -> V_77 = V_63 -> V_77 ;
V_62 -> V_78 = V_63 -> V_78 ;
V_62 -> V_79 = V_63 -> V_79 ;
V_62 -> V_80 = V_63 -> V_80 ;
V_70 = & V_62 -> V_81 . V_69 ;
V_71 = NULL ;
V_68 = & V_62 -> V_82 ;
V_72 = F_71 ( V_62 , V_63 ) ;
if ( V_72 )
goto V_83;
V_72 = F_72 ( V_62 , V_63 ) ;
if ( V_72 )
goto V_83;
V_67 = NULL ;
for ( V_65 = V_63 -> V_82 ; V_65 ; V_65 = V_65 -> V_84 ) {
struct V_85 * V_85 ;
if ( V_65 -> V_86 & V_87 ) {
F_73 ( V_62 , V_65 -> V_86 , - F_74 ( V_65 ) ) ;
continue;
}
V_73 = 0 ;
if ( V_65 -> V_86 & V_88 ) {
unsigned long V_89 = F_74 ( V_65 ) ;
if ( F_75 ( V_63 , V_89 ) )
goto V_90;
V_73 = V_89 ;
}
V_66 = F_76 ( V_91 , V_9 ) ;
if ( ! V_66 )
goto V_90;
* V_66 = * V_65 ;
F_77 ( & V_66 -> V_92 ) ;
V_72 = F_78 ( V_65 , V_66 ) ;
if ( V_72 )
goto V_93;
V_66 -> V_94 = V_62 ;
if ( F_79 ( V_66 , V_65 ) )
goto V_95;
V_66 -> V_86 &=
~ ( V_96 | V_97 | V_98 | V_99 ) ;
V_66 -> V_84 = V_66 -> V_100 = NULL ;
V_66 -> V_101 = V_102 ;
V_85 = V_66 -> V_103 ;
if ( V_85 ) {
struct V_104 * V_104 = F_80 ( V_85 ) ;
struct V_105 * V_106 = V_85 -> V_107 ;
F_81 ( V_85 ) ;
if ( V_66 -> V_86 & V_108 )
F_82 ( & V_104 -> V_109 ) ;
F_83 ( V_106 ) ;
if ( V_66 -> V_86 & V_110 )
F_84 ( & V_106 -> V_111 ) ;
F_85 ( V_106 ) ;
F_86 ( V_66 , V_65 ,
& V_106 -> V_112 ) ;
F_87 ( V_106 ) ;
F_88 ( V_106 ) ;
}
if ( F_89 ( V_66 ) )
F_90 ( V_66 ) ;
* V_68 = V_66 ;
V_68 = & V_66 -> V_84 ;
V_66 -> V_100 = V_67 ;
V_67 = V_66 ;
F_91 ( V_62 , V_66 , V_70 , V_71 ) ;
V_70 = & V_66 -> V_113 . V_114 ;
V_71 = & V_66 -> V_113 ;
V_62 -> V_115 ++ ;
V_72 = F_92 ( V_62 , V_63 , V_65 ) ;
if ( V_66 -> V_116 && V_66 -> V_116 -> V_117 )
V_66 -> V_116 -> V_117 ( V_66 ) ;
if ( V_72 )
goto V_83;
}
F_93 ( V_63 , V_62 ) ;
V_72 = 0 ;
V_83:
F_94 ( & V_62 -> V_74 ) ;
F_95 ( V_63 ) ;
F_94 ( & V_63 -> V_74 ) ;
F_96 () ;
return V_72 ;
V_95:
F_97 ( F_98 ( V_66 ) ) ;
V_93:
F_10 ( V_91 , V_66 ) ;
V_90:
V_72 = - V_118 ;
F_99 ( V_73 ) ;
goto V_83;
}
static inline int F_100 ( struct V_61 * V_62 )
{
V_62 -> V_119 = F_101 ( V_62 ) ;
if ( F_102 ( ! V_62 -> V_119 ) )
return - V_118 ;
return 0 ;
}
static inline void F_103 ( struct V_61 * V_62 )
{
F_104 ( V_62 , V_62 -> V_119 ) ;
}
static int F_63 ( struct V_61 * V_62 , struct V_61 * V_63 )
{
F_65 ( & V_63 -> V_74 ) ;
F_69 ( V_62 -> V_76 , F_70 ( V_63 ) ) ;
F_94 ( & V_63 -> V_74 ) ;
return 0 ;
}
static int T_1 F_105 ( char * V_120 )
{
V_121 =
( F_106 ( V_120 , NULL , 0 ) << V_122 ) &
V_123 ;
return 1 ;
}
static void F_107 ( struct V_61 * V_62 )
{
#ifdef F_108
F_109 ( & V_62 -> V_124 ) ;
V_62 -> V_125 = NULL ;
#endif
}
static void F_110 ( struct V_61 * V_62 , struct V_5 * V_126 )
{
#ifdef F_111
V_62 -> V_127 = V_126 ;
#endif
}
static struct V_61 * F_112 ( struct V_61 * V_62 , struct V_5 * V_126 )
{
V_62 -> V_82 = NULL ;
V_62 -> V_81 = V_128 ;
V_62 -> V_129 = 0 ;
F_61 ( & V_62 -> V_130 , 1 ) ;
F_61 ( & V_62 -> V_131 , 1 ) ;
F_113 ( & V_62 -> V_74 ) ;
F_77 ( & V_62 -> V_132 ) ;
V_62 -> V_133 = NULL ;
F_114 ( & V_62 -> V_134 , 0 ) ;
F_115 ( V_62 ) ;
V_62 -> V_115 = 0 ;
V_62 -> V_135 = 0 ;
V_62 -> V_136 = 0 ;
memset ( & V_62 -> V_137 , 0 , sizeof( V_62 -> V_137 ) ) ;
F_109 ( & V_62 -> V_138 ) ;
F_116 ( V_62 ) ;
F_107 ( V_62 ) ;
F_110 ( V_62 , V_126 ) ;
F_117 ( V_62 ) ;
F_118 ( V_62 ) ;
#if F_119 ( V_139 ) && ! V_140
V_62 -> V_141 = NULL ;
#endif
if ( V_27 -> V_62 ) {
V_62 -> V_142 = V_27 -> V_62 -> V_142 & V_143 ;
V_62 -> V_144 = V_27 -> V_62 -> V_144 & V_145 ;
} else {
V_62 -> V_142 = V_121 ;
V_62 -> V_144 = 0 ;
}
if ( F_100 ( V_62 ) )
goto V_146;
if ( F_120 ( V_126 , V_62 ) )
goto V_147;
return V_62 ;
V_147:
F_103 ( V_62 ) ;
V_146:
F_121 ( V_62 ) ;
return NULL ;
}
static void F_122 ( struct V_61 * V_62 )
{
int V_148 ;
for ( V_148 = 0 ; V_148 < V_149 ; V_148 ++ ) {
long V_150 = F_123 ( & V_62 -> V_137 . V_151 [ V_148 ] ) ;
if ( F_102 ( V_150 ) )
F_124 ( V_152 L_3
L_4 , V_62 , V_148 , V_150 ) ;
}
if ( F_123 ( & V_62 -> V_134 ) )
F_125 ( L_5 ,
F_123 ( & V_62 -> V_134 ) ) ;
if ( F_126 ( V_62 ) )
F_125 ( L_6 ,
F_126 ( V_62 ) ) ;
#if F_119 ( V_139 ) && ! V_140
F_127 ( V_62 -> V_141 , V_62 ) ;
#endif
}
struct V_61 * F_128 ( void )
{
struct V_61 * V_62 ;
V_62 = F_129 () ;
if ( ! V_62 )
return NULL ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
return F_112 ( V_62 , V_27 ) ;
}
void F_130 ( struct V_61 * V_62 )
{
F_19 ( V_62 == & V_153 ) ;
F_103 ( V_62 ) ;
F_131 ( V_62 ) ;
F_132 ( V_62 ) ;
F_122 ( V_62 ) ;
F_121 ( V_62 ) ;
}
void F_133 ( struct V_61 * V_62 )
{
F_134 () ;
if ( F_32 ( & V_62 -> V_130 ) ) {
F_135 ( V_62 ) ;
F_136 ( V_62 ) ;
F_137 ( V_62 ) ;
F_138 ( V_62 ) ;
F_139 ( V_62 ) ;
F_140 ( V_62 , NULL ) ;
if ( ! F_141 ( & V_62 -> V_132 ) ) {
F_142 ( & V_154 ) ;
F_143 ( & V_62 -> V_132 ) ;
F_144 ( & V_154 ) ;
}
if ( V_62 -> V_155 )
F_145 ( V_62 -> V_155 -> V_156 ) ;
F_146 ( V_62 ) ;
}
}
void F_140 ( struct V_61 * V_62 , struct V_85 * V_157 )
{
struct V_85 * V_158 ;
V_158 = F_147 ( V_62 -> V_76 ) ;
if ( V_157 )
F_81 ( V_157 ) ;
F_148 ( V_62 -> V_76 , V_157 ) ;
if ( V_158 )
F_149 ( V_158 ) ;
}
struct V_85 * F_70 ( struct V_61 * V_62 )
{
struct V_85 * V_76 ;
F_150 () ;
V_76 = F_151 ( V_62 -> V_76 ) ;
if ( V_76 && ! F_152 ( V_76 ) )
V_76 = NULL ;
F_153 () ;
return V_76 ;
}
struct V_61 * F_154 ( struct V_5 * V_159 )
{
struct V_61 * V_62 ;
F_155 ( V_159 ) ;
V_62 = V_159 -> V_62 ;
if ( V_62 ) {
if ( V_159 -> V_142 & V_160 )
V_62 = NULL ;
else
F_84 ( & V_62 -> V_130 ) ;
}
F_156 ( V_159 ) ;
return V_62 ;
}
struct V_61 * F_157 ( struct V_5 * V_159 , unsigned int V_161 )
{
struct V_61 * V_62 ;
int V_50 ;
V_50 = F_158 ( & V_159 -> signal -> V_162 ) ;
if ( V_50 )
return F_159 ( V_50 ) ;
V_62 = F_154 ( V_159 ) ;
if ( V_62 && V_62 != V_27 -> V_62 &&
! F_160 ( V_159 , V_161 ) ) {
F_133 ( V_62 ) ;
V_62 = F_159 ( - V_163 ) ;
}
F_161 ( & V_159 -> signal -> V_162 ) ;
return V_62 ;
}
static void F_162 ( struct V_5 * V_6 )
{
struct V_164 * V_165 ;
F_155 ( V_6 ) ;
V_165 = V_6 -> V_166 ;
if ( F_163 ( V_165 ) ) {
V_6 -> V_166 = NULL ;
F_164 ( V_165 ) ;
}
F_156 ( V_6 ) ;
}
static int F_165 ( struct V_5 * V_167 ,
struct V_164 * V_165 )
{
int V_168 ;
F_166 () ;
V_168 = F_167 ( V_165 ) ;
F_168 () ;
if ( V_168 ) {
F_155 ( V_167 ) ;
V_167 -> V_166 = NULL ;
F_156 ( V_167 ) ;
}
F_169 ( V_167 ) ;
return V_168 ;
}
void F_170 ( struct V_5 * V_6 , struct V_61 * V_62 )
{
#ifdef F_171
if ( F_102 ( V_6 -> V_169 ) ) {
F_172 ( V_6 ) ;
V_6 -> V_169 = NULL ;
}
#ifdef F_173
if ( F_102 ( V_6 -> V_170 ) ) {
F_174 ( V_6 ) ;
V_6 -> V_170 = NULL ;
}
#endif
if ( F_102 ( ! F_141 ( & V_6 -> V_171 ) ) )
F_175 ( V_6 ) ;
#endif
F_176 ( V_6 ) ;
F_177 ( V_6 , V_62 ) ;
if ( V_6 -> V_172 ) {
if ( ! ( V_6 -> V_142 & V_173 ) &&
F_35 ( & V_62 -> V_130 ) > 1 ) {
F_178 ( 0 , V_6 -> V_172 ) ;
F_179 ( V_6 -> V_172 , V_174 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_172 = NULL ;
}
if ( V_6 -> V_166 )
F_162 ( V_6 ) ;
}
static struct V_61 * F_180 ( struct V_5 * V_6 )
{
struct V_61 * V_62 , * V_63 = V_27 -> V_62 ;
int V_50 ;
V_62 = F_129 () ;
if ( ! V_62 )
goto V_90;
memcpy ( V_62 , V_63 , sizeof( * V_62 ) ) ;
if ( ! F_112 ( V_62 , V_6 ) )
goto V_90;
V_50 = F_63 ( V_62 , V_63 ) ;
if ( V_50 )
goto V_175;
V_62 -> V_176 = F_181 ( V_62 ) ;
V_62 -> V_177 = V_62 -> V_77 ;
if ( V_62 -> V_155 && ! F_182 ( V_62 -> V_155 -> V_156 ) )
goto V_175;
return V_62 ;
V_175:
V_62 -> V_155 = NULL ;
F_133 ( V_62 ) ;
V_90:
return NULL ;
}
static int F_183 ( unsigned long V_178 , struct V_5 * V_6 )
{
struct V_61 * V_62 , * V_63 ;
int V_72 ;
V_6 -> V_179 = V_6 -> V_180 = 0 ;
V_6 -> V_181 = V_6 -> V_182 = 0 ;
#ifdef F_184
V_6 -> V_183 = V_6 -> V_181 + V_6 -> V_182 ;
#endif
V_6 -> V_62 = NULL ;
V_6 -> V_184 = NULL ;
V_63 = V_27 -> V_62 ;
if ( ! V_63 )
return 0 ;
F_185 ( V_6 ) ;
if ( V_178 & V_185 ) {
F_84 ( & V_63 -> V_130 ) ;
V_62 = V_63 ;
goto V_186;
}
V_72 = - V_118 ;
V_62 = F_180 ( V_6 ) ;
if ( ! V_62 )
goto V_90;
V_186:
V_6 -> V_62 = V_62 ;
V_6 -> V_184 = V_62 ;
return 0 ;
V_90:
return V_72 ;
}
static int F_186 ( unsigned long V_178 , struct V_5 * V_6 )
{
struct V_187 * V_188 = V_27 -> V_188 ;
if ( V_178 & V_189 ) {
F_142 ( & V_188 -> V_190 ) ;
if ( V_188 -> V_191 ) {
F_144 ( & V_188 -> V_190 ) ;
return - V_192 ;
}
V_188 -> V_193 ++ ;
F_144 ( & V_188 -> V_190 ) ;
return 0 ;
}
V_6 -> V_188 = F_187 ( V_188 ) ;
if ( ! V_6 -> V_188 )
return - V_118 ;
return 0 ;
}
static int F_188 ( unsigned long V_178 , struct V_5 * V_6 )
{
struct V_194 * V_195 , * V_196 ;
int error = 0 ;
V_195 = V_27 -> V_197 ;
if ( ! V_195 )
goto V_83;
if ( V_178 & V_198 ) {
F_84 ( & V_195 -> V_151 ) ;
goto V_83;
}
V_196 = F_189 ( V_195 , & error ) ;
if ( ! V_196 )
goto V_83;
V_6 -> V_197 = V_196 ;
error = 0 ;
V_83:
return error ;
}
static int F_190 ( unsigned long V_178 , struct V_5 * V_6 )
{
#ifdef F_191
struct V_199 * V_200 = V_27 -> V_199 ;
struct V_199 * V_201 ;
if ( ! V_200 )
return 0 ;
if ( V_178 & V_202 ) {
F_192 ( V_200 ) ;
V_6 -> V_199 = V_200 ;
} else if ( F_193 ( V_200 -> V_203 ) ) {
V_201 = F_194 ( V_6 , V_9 , V_204 ) ;
if ( F_102 ( ! V_201 ) )
return - V_118 ;
V_201 -> V_203 = V_200 -> V_203 ;
F_195 ( V_201 ) ;
}
#endif
return 0 ;
}
static int F_196 ( unsigned long V_178 , struct V_5 * V_6 )
{
struct V_205 * V_22 ;
if ( V_178 & V_206 ) {
F_84 ( & V_27 -> V_207 -> V_151 ) ;
return 0 ;
}
V_22 = F_76 ( V_208 , V_9 ) ;
F_148 ( V_6 -> V_207 , V_22 ) ;
if ( ! V_22 )
return - V_118 ;
F_61 ( & V_22 -> V_151 , 1 ) ;
memcpy ( V_22 -> V_209 , V_27 -> V_207 -> V_209 , sizeof( V_22 -> V_209 ) ) ;
return 0 ;
}
void F_197 ( struct V_205 * V_207 )
{
if ( F_32 ( & V_207 -> V_151 ) ) {
F_198 ( V_207 ) ;
F_10 ( V_208 , V_207 ) ;
}
}
static void F_199 ( struct V_21 * V_22 )
{
unsigned long V_210 ;
V_210 = F_200 ( V_22 -> V_40 [ V_211 ] . V_42 ) ;
if ( V_210 != V_212 ) {
V_22 -> V_213 . V_214 = F_201 ( V_210 ) ;
V_22 -> V_215 . V_216 = true ;
}
F_77 ( & V_22 -> V_217 [ 0 ] ) ;
F_77 ( & V_22 -> V_217 [ 1 ] ) ;
F_77 ( & V_22 -> V_217 [ 2 ] ) ;
}
static int F_202 ( unsigned long V_178 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_178 & V_218 )
return 0 ;
V_22 = F_203 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_118 ;
V_22 -> V_219 = 1 ;
F_61 ( & V_22 -> V_220 , 1 ) ;
F_61 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_221 = (struct V_222 ) F_204 ( V_6 -> V_223 ) ;
V_6 -> V_223 = (struct V_222 ) F_204 ( V_22 -> V_221 ) ;
F_205 ( & V_22 -> V_224 ) ;
V_22 -> V_225 = V_6 ;
F_206 ( & V_22 -> V_226 ) ;
F_77 ( & V_22 -> V_227 ) ;
F_207 ( & V_22 -> V_228 ) ;
F_208 ( & V_22 -> V_229 ) ;
F_209 ( & V_22 -> V_230 , V_231 , V_232 ) ;
V_22 -> V_230 . V_233 = V_234 ;
F_155 ( V_27 -> V_235 ) ;
memcpy ( V_22 -> V_40 , V_27 -> signal -> V_40 , sizeof V_22 -> V_40 ) ;
F_156 ( V_27 -> V_235 ) ;
F_199 ( V_22 ) ;
F_210 ( V_22 ) ;
F_211 ( V_22 ) ;
V_22 -> V_236 = V_27 -> signal -> V_236 ;
V_22 -> V_237 = V_27 -> signal -> V_237 ;
V_22 -> V_238 = V_27 -> signal -> V_238 ||
V_27 -> signal -> V_239 ;
F_212 ( & V_22 -> V_162 ) ;
return 0 ;
}
static void F_213 ( struct V_5 * V_126 )
{
#ifdef F_55
F_214 ( & V_27 -> V_207 -> V_240 ) ;
F_215 ( V_27 ) ;
V_126 -> V_53 = V_27 -> V_53 ;
if ( F_216 ( V_27 ) )
F_217 ( V_126 ) ;
if ( V_126 -> V_53 . V_161 != V_241 )
F_218 ( V_126 , V_242 ) ;
#endif
}
static void F_219 ( struct V_5 * V_126 )
{
F_220 ( & V_126 -> V_243 ) ;
#ifdef F_221
V_126 -> V_244 = V_128 ;
V_126 -> V_245 = NULL ;
V_126 -> V_246 = NULL ;
#endif
}
static void F_222 ( struct V_5 * V_6 )
{
V_6 -> V_213 . V_214 = 0 ;
V_6 -> V_213 . V_247 = 0 ;
V_6 -> V_213 . V_248 = 0 ;
F_77 ( & V_6 -> V_217 [ 0 ] ) ;
F_77 ( & V_6 -> V_217 [ 1 ] ) ;
F_77 ( & V_6 -> V_217 [ 2 ] ) ;
}
static inline void
F_223 ( struct V_5 * V_159 , enum V_249 type , struct V_250 * V_250 )
{
V_159 -> V_251 [ type ] . V_250 = V_250 ;
}
static struct V_5 * F_224 ( unsigned long V_178 ,
unsigned long V_252 ,
unsigned long V_253 ,
int T_3 * V_254 ,
struct V_250 * V_250 ,
int V_255 ,
unsigned long V_256 )
{
int V_72 ;
struct V_5 * V_126 ;
if ( ( V_178 & ( V_257 | V_189 ) ) == ( V_257 | V_189 ) )
return F_159 ( - V_258 ) ;
if ( ( V_178 & ( V_259 | V_189 ) ) == ( V_259 | V_189 ) )
return F_159 ( - V_258 ) ;
if ( ( V_178 & V_218 ) && ! ( V_178 & V_206 ) )
return F_159 ( - V_258 ) ;
if ( ( V_178 & V_206 ) && ! ( V_178 & V_185 ) )
return F_159 ( - V_258 ) ;
if ( ( V_178 & V_260 ) &&
V_27 -> signal -> V_142 & V_261 )
return F_159 ( - V_258 ) ;
if ( V_178 & V_218 ) {
if ( ( V_178 & ( V_259 | V_262 ) ) ||
( F_225 ( V_27 ) !=
V_27 -> V_263 -> V_264 ) )
return F_159 ( - V_258 ) ;
}
V_72 = F_226 ( V_178 ) ;
if ( V_72 )
goto V_265;
V_72 = - V_118 ;
V_126 = F_53 ( V_27 ) ;
if ( ! V_126 )
goto V_265;
F_227 ( V_126 ) ;
F_219 ( V_126 ) ;
#ifdef F_228
F_229 ( ! V_126 -> V_266 ) ;
F_229 ( ! V_126 -> V_267 ) ;
#endif
V_72 = - V_192 ;
if ( F_35 ( & V_126 -> V_268 -> V_269 -> V_270 ) >=
F_230 ( V_126 , V_41 ) ) {
if ( V_126 -> V_268 -> V_269 != V_271 &&
! F_231 ( V_272 ) && ! F_231 ( V_273 ) )
goto V_274;
}
V_27 -> V_142 &= ~ V_275 ;
V_72 = F_232 ( V_126 , V_178 ) ;
if ( V_72 < 0 )
goto V_274;
V_72 = - V_192 ;
if ( V_219 >= V_33 )
goto V_276;
F_233 ( V_126 ) ;
V_126 -> V_142 &= ~ ( V_277 | V_278 ) ;
V_126 -> V_142 |= V_279 ;
F_77 ( & V_126 -> V_280 ) ;
F_77 ( & V_126 -> V_281 ) ;
F_234 ( V_126 ) ;
V_126 -> V_166 = NULL ;
F_109 ( & V_126 -> V_282 ) ;
F_206 ( & V_126 -> V_283 ) ;
V_126 -> V_284 = V_126 -> V_285 = V_126 -> V_286 = 0 ;
V_126 -> V_287 = V_126 -> V_288 = 0 ;
F_208 ( & V_126 -> V_229 ) ;
#ifdef F_235
F_236 ( & V_126 -> V_289 ) ;
V_126 -> V_290 = 0 ;
V_126 -> V_291 = V_292 ;
#endif
#if F_119 ( V_293 )
memset ( & V_126 -> V_137 , 0 , sizeof( V_126 -> V_137 ) ) ;
#endif
V_126 -> V_294 = V_27 -> V_295 ;
F_237 ( & V_126 -> V_296 ) ;
F_238 ( V_126 ) ;
F_222 ( V_126 ) ;
V_126 -> V_297 = F_239 () ;
V_126 -> V_298 = F_240 () ;
V_126 -> V_199 = NULL ;
V_126 -> V_299 = NULL ;
F_241 ( V_27 ) ;
F_242 ( V_126 ) ;
#ifdef F_243
V_126 -> V_300 = F_244 ( V_126 -> V_300 ) ;
if ( F_245 ( V_126 -> V_300 ) ) {
V_72 = F_246 ( V_126 -> V_300 ) ;
V_126 -> V_300 = NULL ;
goto V_301;
}
#endif
#ifdef F_247
V_126 -> V_302 = V_204 ;
V_126 -> V_303 = V_204 ;
F_236 ( & V_126 -> V_304 ) ;
#endif
#ifdef F_248
V_126 -> V_305 = 0 ;
V_126 -> V_266 = 0 ;
V_126 -> V_306 = 0 ;
V_126 -> V_307 = 0 ;
V_126 -> V_308 = V_309 ;
V_126 -> V_310 = 0 ;
V_126 -> V_267 = 1 ;
V_126 -> V_311 = V_309 ;
V_126 -> V_312 = 0 ;
V_126 -> V_313 = 0 ;
V_126 -> V_314 = 0 ;
V_126 -> V_315 = 0 ;
V_126 -> V_316 = 0 ;
#endif
V_126 -> V_317 = 0 ;
#ifdef F_249
V_126 -> V_318 = 0 ;
V_126 -> V_319 = 0 ;
V_126 -> V_320 = 0 ;
#endif
#ifdef F_250
V_126 -> V_321 = NULL ;
#endif
#ifdef F_251
V_126 -> V_322 = 0 ;
V_126 -> V_323 = 0 ;
#endif
V_72 = F_252 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_324;
V_72 = F_253 ( V_126 ) ;
if ( V_72 )
goto V_324;
V_72 = F_254 ( V_126 ) ;
if ( V_72 )
goto V_325;
F_255 ( V_126 ) ;
V_72 = F_256 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_326;
V_72 = F_188 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_327;
V_72 = F_186 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_328;
V_72 = F_196 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_329;
V_72 = F_202 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_330;
V_72 = F_183 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_331;
V_72 = F_257 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_332;
V_72 = F_190 ( V_178 , V_126 ) ;
if ( V_72 )
goto V_333;
V_72 = F_258 ( V_178 , V_252 , V_253 , V_126 , V_256 ) ;
if ( V_72 )
goto V_334;
if ( V_250 != & V_335 ) {
V_250 = F_259 ( V_126 -> V_263 -> V_264 ) ;
if ( F_245 ( V_250 ) ) {
V_72 = F_246 ( V_250 ) ;
goto V_334;
}
}
V_126 -> V_336 = ( V_178 & V_337 ) ? V_254 : NULL ;
V_126 -> V_172 = ( V_178 & V_338 ) ? V_254 : NULL ;
#ifdef F_191
V_126 -> V_339 = NULL ;
#endif
#ifdef F_171
V_126 -> V_169 = NULL ;
#ifdef F_173
V_126 -> V_170 = NULL ;
#endif
F_77 ( & V_126 -> V_171 ) ;
V_126 -> V_340 = NULL ;
#endif
if ( ( V_178 & ( V_185 | V_341 ) ) == V_185 )
V_126 -> V_342 = V_126 -> V_343 = 0 ;
F_260 ( V_126 ) ;
F_261 ( V_126 , V_344 ) ;
#ifdef F_262
F_261 ( V_126 , F_262 ) ;
#endif
F_263 ( V_126 ) ;
V_126 -> V_250 = F_264 ( V_250 ) ;
if ( V_178 & V_218 ) {
V_126 -> V_345 = - 1 ;
V_126 -> V_235 = V_27 -> V_235 ;
V_126 -> V_346 = V_27 -> V_346 ;
} else {
if ( V_178 & V_260 )
V_126 -> V_345 = V_27 -> V_235 -> V_345 ;
else
V_126 -> V_345 = ( V_178 & V_347 ) ;
V_126 -> V_235 = V_126 ;
V_126 -> V_346 = V_126 -> V_250 ;
}
V_126 -> V_348 = 0 ;
V_126 -> V_349 = 128 >> ( V_350 - 10 ) ;
V_126 -> V_351 = 0 ;
V_126 -> V_352 = 0 ;
F_77 ( & V_126 -> V_353 ) ;
V_126 -> V_354 = NULL ;
V_72 = F_265 ( V_126 ) ;
if ( V_72 )
goto V_355;
F_266 ( & V_1 ) ;
if ( V_178 & ( V_260 | V_218 ) ) {
V_126 -> V_356 = V_27 -> V_356 ;
V_126 -> V_357 = V_27 -> V_357 ;
} else {
V_126 -> V_356 = V_27 ;
V_126 -> V_357 = V_27 -> V_358 ;
}
F_142 ( & V_27 -> V_207 -> V_240 ) ;
F_213 ( V_126 ) ;
F_267 () ;
if ( F_268 ( V_27 ) ) {
F_144 ( & V_27 -> V_207 -> V_240 ) ;
F_269 ( & V_1 ) ;
V_72 = - V_359 ;
goto V_360;
}
if ( F_163 ( V_126 -> V_250 ) ) {
F_270 ( V_126 , ( V_178 & V_361 ) || V_255 ) ;
F_223 ( V_126 , V_362 , V_250 ) ;
if ( F_271 ( V_126 ) ) {
F_223 ( V_126 , V_363 , F_272 ( V_27 ) ) ;
F_223 ( V_126 , V_364 , F_273 ( V_27 ) ) ;
if ( F_274 ( V_250 ) ) {
F_275 ( V_250 ) -> V_365 = V_126 ;
V_126 -> signal -> V_142 |= V_261 ;
}
V_126 -> signal -> V_366 = V_250 ;
V_126 -> signal -> V_367 = F_276 ( V_27 -> signal -> V_367 ) ;
F_277 ( & V_126 -> V_281 , & V_126 -> V_356 -> V_280 ) ;
F_278 ( & V_126 -> V_368 , & V_39 . V_368 ) ;
F_279 ( V_126 , V_363 ) ;
F_279 ( V_126 , V_364 ) ;
F_280 ( V_4 ) ;
} else {
V_27 -> signal -> V_219 ++ ;
F_84 ( & V_27 -> signal -> V_220 ) ;
F_84 ( & V_27 -> signal -> V_24 ) ;
F_278 ( & V_126 -> V_353 ,
& V_126 -> V_235 -> V_353 ) ;
F_278 ( & V_126 -> V_223 ,
& V_126 -> signal -> V_221 ) ;
}
F_279 ( V_126 , V_362 ) ;
V_219 ++ ;
}
V_369 ++ ;
F_144 ( & V_27 -> V_207 -> V_240 ) ;
F_281 ( V_126 ) ;
F_269 ( & V_1 ) ;
F_282 ( V_126 ) ;
F_283 ( V_126 ) ;
F_284 ( V_27 ) ;
F_285 ( V_126 ) ;
F_286 ( V_126 , V_178 ) ;
F_287 ( V_126 , V_178 ) ;
return V_126 ;
V_360:
F_288 ( V_126 ) ;
V_355:
if ( V_250 != & V_335 )
F_289 ( V_250 ) ;
V_334:
if ( V_126 -> V_199 )
F_290 ( V_126 ) ;
V_333:
F_291 ( V_126 ) ;
V_332:
if ( V_126 -> V_62 )
F_133 ( V_126 -> V_62 ) ;
V_331:
if ( ! ( V_178 & V_218 ) )
F_28 ( V_126 -> signal ) ;
V_330:
F_197 ( V_126 -> V_207 ) ;
V_329:
F_292 ( V_126 ) ;
V_328:
F_293 ( V_126 ) ;
V_327:
F_294 ( V_126 ) ;
V_326:
F_295 ( V_126 ) ;
V_325:
F_296 ( V_126 ) ;
V_324:
#ifdef F_243
F_97 ( V_126 -> V_300 ) ;
V_301:
#endif
F_284 ( V_27 ) ;
F_40 ( V_126 ) ;
V_276:
F_82 ( & V_126 -> V_370 -> V_269 -> V_270 ) ;
F_39 ( V_126 ) ;
V_274:
F_24 ( V_126 ) ;
V_265:
return F_159 ( V_72 ) ;
}
static inline void F_297 ( struct V_371 * V_372 )
{
enum V_249 type ;
for ( type = V_362 ; type < V_373 ; ++ type ) {
F_298 ( & V_372 [ type ] . V_7 ) ;
V_372 [ type ] . V_250 = & V_335 ;
}
}
struct V_5 * F_299 ( int V_2 )
{
struct V_5 * V_159 ;
V_159 = F_224 ( V_185 , 0 , 0 , NULL , & V_335 , 0 , 0 ) ;
if ( ! F_245 ( V_159 ) ) {
F_297 ( V_159 -> V_251 ) ;
F_300 ( V_159 , V_2 ) ;
}
return V_159 ;
}
long F_301 ( unsigned long V_178 ,
unsigned long V_252 ,
unsigned long V_253 ,
int T_3 * V_374 ,
int T_3 * V_254 ,
unsigned long V_256 )
{
struct V_5 * V_126 ;
int V_255 = 0 ;
long V_375 ;
if ( ! ( V_178 & V_376 ) ) {
if ( V_178 & V_341 )
V_255 = V_377 ;
else if ( ( V_178 & V_347 ) != V_378 )
V_255 = V_379 ;
else
V_255 = V_380 ;
if ( F_163 ( ! F_302 ( V_27 , V_255 ) ) )
V_255 = 0 ;
}
V_126 = F_224 ( V_178 , V_252 , V_253 ,
V_254 , NULL , V_255 , V_256 ) ;
if ( ! F_245 ( V_126 ) ) {
struct V_164 V_165 ;
struct V_250 * V_250 ;
F_303 ( V_27 , V_126 ) ;
V_250 = F_304 ( V_126 , V_362 ) ;
V_375 = F_305 ( V_250 ) ;
if ( V_178 & V_381 )
F_178 ( V_375 , V_374 ) ;
if ( V_178 & V_341 ) {
V_126 -> V_166 = & V_165 ;
F_306 ( & V_165 ) ;
F_307 ( V_126 ) ;
}
F_308 ( V_126 ) ;
if ( F_102 ( V_255 ) )
F_309 ( V_255 , V_250 ) ;
if ( V_178 & V_341 ) {
if ( ! F_165 ( V_126 , & V_165 ) )
F_309 ( V_382 , V_250 ) ;
}
F_310 ( V_250 ) ;
} else {
V_375 = F_246 ( V_126 ) ;
}
return V_375 ;
}
long F_311 ( unsigned long V_178 ,
unsigned long V_252 ,
unsigned long V_253 ,
int T_3 * V_374 ,
int T_3 * V_254 )
{
return F_301 ( V_178 , V_252 , V_253 ,
V_374 , V_254 , 0 ) ;
}
T_4 F_312 ( int (* F_313)( void * ) , void * V_383 , unsigned long V_142 )
{
return F_301 ( V_142 | V_185 | V_376 , ( unsigned long ) F_313 ,
( unsigned long ) V_383 , NULL , NULL , 0 ) ;
}
static void F_314 ( void * V_384 )
{
struct V_205 * V_207 = V_384 ;
F_109 ( & V_207 -> V_240 ) ;
F_205 ( & V_207 -> V_385 ) ;
}
void T_1 F_315 ( void )
{
V_208 = F_18 ( L_7 ,
sizeof( struct V_205 ) , 0 ,
V_386 | V_36 | V_387 |
V_37 | V_38 , F_314 ) ;
V_23 = F_18 ( L_8 ,
sizeof( struct V_21 ) , 0 ,
V_386 | V_36 | V_37 | V_38 ,
NULL ) ;
V_388 = F_18 ( L_9 ,
sizeof( struct V_194 ) , 0 ,
V_386 | V_36 | V_37 | V_38 ,
NULL ) ;
V_389 = F_18 ( L_10 ,
sizeof( struct V_187 ) , 0 ,
V_386 | V_36 | V_37 | V_38 ,
NULL ) ;
V_390 = F_18 ( L_11 ,
sizeof( struct V_61 ) , V_391 ,
V_386 | V_36 | V_37 | V_38 ,
NULL ) ;
V_91 = F_316 ( V_64 , V_36 | V_38 ) ;
F_317 () ;
F_318 () ;
}
static int F_319 ( unsigned long V_392 )
{
if ( V_392 & ~ ( V_218 | V_189 | V_257 | V_206 |
V_185 | V_198 | V_393 |
V_394 | V_395 | V_396 |
V_259 | V_262 ) )
return - V_258 ;
if ( V_392 & ( V_218 | V_206 | V_185 ) ) {
if ( ! F_320 ( V_27 ) )
return - V_258 ;
}
if ( V_392 & ( V_206 | V_185 ) ) {
if ( F_35 ( & V_27 -> V_207 -> V_151 ) > 1 )
return - V_258 ;
}
if ( V_392 & V_185 ) {
if ( ! F_321 () )
return - V_258 ;
}
return 0 ;
}
static int F_322 ( unsigned long V_392 , struct V_187 * * V_397 )
{
struct V_187 * V_188 = V_27 -> V_188 ;
if ( ! ( V_392 & V_189 ) || ! V_188 )
return 0 ;
if ( V_188 -> V_193 == 1 )
return 0 ;
* V_397 = F_187 ( V_188 ) ;
if ( ! * V_397 )
return - V_118 ;
return 0 ;
}
static int F_323 ( unsigned long V_392 , struct V_194 * * V_398 )
{
struct V_194 * V_399 = V_27 -> V_197 ;
int error = 0 ;
if ( ( V_392 & V_198 ) &&
( V_399 && F_35 ( & V_399 -> V_151 ) > 1 ) ) {
* V_398 = F_189 ( V_399 , & error ) ;
if ( ! * V_398 )
return error ;
}
return 0 ;
}
int F_324 ( struct V_194 * * V_400 )
{
struct V_5 * V_159 = V_27 ;
struct V_194 * V_401 = NULL ;
int error ;
error = F_323 ( V_198 , & V_401 ) ;
if ( error || ! V_401 ) {
* V_400 = NULL ;
return error ;
}
* V_400 = V_159 -> V_197 ;
F_155 ( V_159 ) ;
V_159 -> V_197 = V_401 ;
F_156 ( V_159 ) ;
return 0 ;
}
int F_325 ( struct V_402 * V_403 , int V_404 ,
void T_3 * V_405 , T_5 * V_406 , T_6 * V_407 )
{
struct V_402 V_408 ;
int V_409 ;
int V_29 = V_33 ;
int V_410 = V_34 ;
int V_411 = V_32 ;
V_408 = * V_403 ;
V_408 . V_384 = & V_29 ;
V_408 . V_412 = & V_410 ;
V_408 . V_413 = & V_411 ;
V_409 = F_326 ( & V_408 , V_404 , V_405 , V_406 , V_407 ) ;
if ( V_409 || ! V_404 )
return V_409 ;
F_43 ( V_29 ) ;
return 0 ;
}
