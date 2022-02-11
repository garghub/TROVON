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
void __weak F_11 ( unsigned long * V_10 )
{
}
static unsigned long * F_12 ( struct V_5 * V_6 ,
int V_7 )
{
struct V_11 * V_11 = F_13 ( V_7 , V_12 ,
V_13 ) ;
if ( V_11 )
F_14 ( V_11 , V_14 ,
1 << V_13 ) ;
return V_11 ? F_15 ( V_11 ) : NULL ;
}
static inline void F_16 ( unsigned long * V_10 )
{
struct V_11 * V_11 = F_17 ( V_10 ) ;
F_14 ( V_11 , V_14 ,
- ( 1 << V_13 ) ) ;
F_18 ( V_11 , V_13 ) ;
}
static unsigned long * F_12 ( struct V_5 * V_6 ,
int V_7 )
{
return F_8 ( V_15 , V_12 , V_7 ) ;
}
static void F_16 ( unsigned long * V_10 )
{
F_10 ( V_15 , V_10 ) ;
}
void F_19 ( void )
{
V_15 = F_20 ( L_1 , V_16 ,
V_16 , 0 , NULL ) ;
F_21 ( V_15 == NULL ) ;
}
static void F_22 ( unsigned long * V_10 , int V_17 )
{
struct V_18 * V_18 = F_23 ( F_17 ( V_10 ) ) ;
F_24 ( V_18 , V_19 , V_17 ) ;
}
void F_25 ( struct V_5 * V_6 )
{
F_22 ( V_6 -> V_10 , - 1 ) ;
F_11 ( V_6 -> V_10 ) ;
F_16 ( V_6 -> V_10 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
F_6 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_29 ( struct V_20 * V_21 )
{
F_30 ( V_21 ) ;
F_31 ( V_21 ) ;
F_10 ( V_22 , V_21 ) ;
}
static inline void F_32 ( struct V_20 * V_21 )
{
if ( F_33 ( & V_21 -> V_23 ) )
F_29 ( V_21 ) ;
}
void F_34 ( struct V_5 * V_6 )
{
F_35 ( ! V_6 -> V_24 ) ;
F_35 ( F_36 ( & V_6 -> V_25 ) ) ;
F_35 ( V_6 == V_26 ) ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_39 ( V_6 ) ;
F_40 ( V_6 ) ;
F_41 ( V_6 ) ;
F_32 ( V_6 -> signal ) ;
if ( ! F_42 ( V_6 ) )
F_25 ( V_6 ) ;
}
void T_1 __weak F_43 ( void ) { }
static void F_44 ( unsigned int V_27 )
{
T_2 V_28 ;
if ( F_45 ( V_29 ) + F_45 ( V_30 ) > 64 )
V_28 = V_31 ;
else
V_28 = F_46 ( ( T_2 ) V_29 * ( T_2 ) V_30 ,
( T_2 ) V_16 * 8UL ) ;
if ( V_28 > V_27 )
V_28 = V_27 ;
V_32 = F_47 ( T_2 , V_28 , V_33 , V_31 ) ;
}
void T_1 F_48 ( void )
{
#ifndef F_49
#ifndef F_50
#define F_50 L1_CACHE_BYTES
#endif
V_8 = F_20 ( L_2 ,
V_34 , F_50 ,
V_35 | V_36 | V_37 , NULL ) ;
#endif
F_43 () ;
F_44 ( V_31 ) ;
V_38 . signal -> V_39 [ V_40 ] . V_41 = V_32 / 2 ;
V_38 . signal -> V_39 [ V_40 ] . V_42 = V_32 / 2 ;
V_38 . signal -> V_39 [ V_43 ] =
V_38 . signal -> V_39 [ V_40 ] ;
}
int __weak F_51 ( struct V_5 * V_44 ,
struct V_5 * V_45 )
{
* V_44 = * V_45 ;
return 0 ;
}
void F_52 ( struct V_5 * V_6 )
{
unsigned long * V_46 ;
V_46 = F_53 ( V_6 ) ;
* V_46 = V_47 ;
}
static struct V_5 * F_54 ( struct V_5 * V_48 , int V_7 )
{
struct V_5 * V_6 ;
unsigned long * V_10 ;
int V_49 ;
if ( V_7 == V_50 )
V_7 = F_55 ( V_48 ) ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_10 = F_12 ( V_6 , V_7 ) ;
if ( ! V_10 )
goto V_51;
V_49 = F_51 ( V_6 , V_48 ) ;
if ( V_49 )
goto V_52;
V_6 -> V_10 = V_10 ;
#ifdef F_56
V_6 -> V_53 . V_54 = NULL ;
#endif
F_57 ( V_6 , V_48 ) ;
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
F_52 ( V_6 ) ;
#ifdef F_60
V_6 -> V_55 = F_61 () ;
#endif
F_62 ( & V_6 -> V_25 , 2 ) ;
#ifdef F_63
V_6 -> V_56 = 0 ;
#endif
V_6 -> V_57 = NULL ;
V_6 -> V_58 . V_11 = NULL ;
V_6 -> V_59 . V_60 = NULL ;
F_22 ( V_10 , 1 ) ;
F_64 ( V_6 ) ;
return V_6 ;
V_52:
F_16 ( V_10 ) ;
V_51:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_65 ( struct V_61 * V_62 , struct V_61 * V_63 )
{
struct V_64 * V_65 , * V_66 , * V_67 , * * V_68 ;
struct V_69 * * V_70 , * V_71 ;
int V_72 ;
unsigned long V_73 ;
F_66 () ;
if ( F_67 ( & V_63 -> V_74 ) ) {
V_72 = - V_75 ;
goto V_76;
}
F_68 ( V_63 ) ;
F_69 ( V_63 , V_62 ) ;
F_70 ( & V_62 -> V_74 , V_77 ) ;
F_71 ( V_62 -> V_78 , F_72 ( V_63 ) ) ;
V_62 -> V_79 = V_63 -> V_79 ;
V_62 -> V_80 = V_63 -> V_80 ;
V_62 -> V_81 = V_63 -> V_81 ;
V_62 -> V_82 = V_63 -> V_82 ;
V_70 = & V_62 -> V_83 . V_69 ;
V_71 = NULL ;
V_68 = & V_62 -> V_84 ;
V_72 = F_73 ( V_62 , V_63 ) ;
if ( V_72 )
goto V_85;
V_72 = F_74 ( V_62 , V_63 ) ;
if ( V_72 )
goto V_85;
V_67 = NULL ;
for ( V_65 = V_63 -> V_84 ; V_65 ; V_65 = V_65 -> V_86 ) {
struct V_87 * V_87 ;
if ( V_65 -> V_88 & V_89 ) {
F_75 ( V_62 , V_65 -> V_88 , - F_76 ( V_65 ) ) ;
continue;
}
V_73 = 0 ;
if ( V_65 -> V_88 & V_90 ) {
unsigned long V_91 = F_76 ( V_65 ) ;
if ( F_77 ( V_63 , V_91 ) )
goto V_92;
V_73 = V_91 ;
}
V_66 = F_78 ( V_93 , V_9 ) ;
if ( ! V_66 )
goto V_92;
* V_66 = * V_65 ;
F_79 ( & V_66 -> V_94 ) ;
V_72 = F_80 ( V_65 , V_66 ) ;
if ( V_72 )
goto V_95;
V_66 -> V_96 = V_62 ;
if ( F_81 ( V_66 , V_65 ) )
goto V_97;
V_66 -> V_88 &=
~ ( V_98 | V_99 | V_100 | V_101 ) ;
V_66 -> V_86 = V_66 -> V_102 = NULL ;
V_66 -> V_103 = V_104 ;
V_87 = V_66 -> V_105 ;
if ( V_87 ) {
struct V_106 * V_106 = F_82 ( V_87 ) ;
struct V_107 * V_108 = V_87 -> V_109 ;
F_83 ( V_87 ) ;
if ( V_66 -> V_88 & V_110 )
F_84 ( & V_106 -> V_111 ) ;
F_85 ( V_108 ) ;
if ( V_66 -> V_88 & V_112 )
F_86 ( & V_108 -> V_113 ) ;
F_87 ( V_108 ) ;
F_88 ( V_66 , V_65 ,
& V_108 -> V_114 ) ;
F_89 ( V_108 ) ;
F_90 ( V_108 ) ;
}
if ( F_91 ( V_66 ) )
F_92 ( V_66 ) ;
* V_68 = V_66 ;
V_68 = & V_66 -> V_86 ;
V_66 -> V_102 = V_67 ;
V_67 = V_66 ;
F_93 ( V_62 , V_66 , V_70 , V_71 ) ;
V_70 = & V_66 -> V_115 . V_116 ;
V_71 = & V_66 -> V_115 ;
V_62 -> V_117 ++ ;
V_72 = F_94 ( V_62 , V_63 , V_65 ) ;
if ( V_66 -> V_118 && V_66 -> V_118 -> V_119 )
V_66 -> V_118 -> V_119 ( V_66 ) ;
if ( V_72 )
goto V_85;
}
F_95 ( V_63 , V_62 ) ;
V_72 = 0 ;
V_85:
F_96 ( & V_62 -> V_74 ) ;
F_97 ( V_63 ) ;
F_96 ( & V_63 -> V_74 ) ;
V_76:
F_98 () ;
return V_72 ;
V_97:
F_99 ( F_100 ( V_66 ) ) ;
V_95:
F_10 ( V_93 , V_66 ) ;
V_92:
V_72 = - V_120 ;
F_101 ( V_73 ) ;
goto V_85;
}
static inline int F_102 ( struct V_61 * V_62 )
{
V_62 -> V_121 = F_103 ( V_62 ) ;
if ( F_104 ( ! V_62 -> V_121 ) )
return - V_120 ;
return 0 ;
}
static inline void F_105 ( struct V_61 * V_62 )
{
F_106 ( V_62 , V_62 -> V_121 ) ;
}
static int F_65 ( struct V_61 * V_62 , struct V_61 * V_63 )
{
F_107 ( & V_63 -> V_74 ) ;
F_71 ( V_62 -> V_78 , F_72 ( V_63 ) ) ;
F_96 ( & V_63 -> V_74 ) ;
return 0 ;
}
static int T_1 F_108 ( char * V_122 )
{
V_123 =
( F_109 ( V_122 , NULL , 0 ) << V_124 ) &
V_125 ;
return 1 ;
}
static void F_110 ( struct V_61 * V_62 )
{
#ifdef F_111
F_112 ( & V_62 -> V_126 ) ;
V_62 -> V_127 = NULL ;
#endif
}
static void F_113 ( struct V_61 * V_62 , struct V_5 * V_128 )
{
#ifdef F_114
V_62 -> V_129 = V_128 ;
#endif
}
static struct V_61 * F_115 ( struct V_61 * V_62 , struct V_5 * V_128 )
{
V_62 -> V_84 = NULL ;
V_62 -> V_83 = V_130 ;
V_62 -> V_131 = 0 ;
F_62 ( & V_62 -> V_132 , 1 ) ;
F_62 ( & V_62 -> V_133 , 1 ) ;
F_116 ( & V_62 -> V_74 ) ;
F_79 ( & V_62 -> V_134 ) ;
V_62 -> V_135 = NULL ;
F_117 ( & V_62 -> V_136 , 0 ) ;
F_118 ( V_62 ) ;
V_62 -> V_117 = 0 ;
V_62 -> V_137 = 0 ;
V_62 -> V_138 = 0 ;
memset ( & V_62 -> V_139 , 0 , sizeof( V_62 -> V_139 ) ) ;
F_112 ( & V_62 -> V_140 ) ;
F_119 ( V_62 ) ;
F_110 ( V_62 ) ;
F_113 ( V_62 , V_128 ) ;
F_120 ( V_62 ) ;
F_121 ( V_62 ) ;
#if F_122 ( V_141 ) && ! V_142
V_62 -> V_143 = NULL ;
#endif
if ( V_26 -> V_62 ) {
V_62 -> V_144 = V_26 -> V_62 -> V_144 & V_145 ;
V_62 -> V_146 = V_26 -> V_62 -> V_146 & V_147 ;
} else {
V_62 -> V_144 = V_123 ;
V_62 -> V_146 = 0 ;
}
if ( F_102 ( V_62 ) )
goto V_148;
if ( F_123 ( V_128 , V_62 ) )
goto V_149;
return V_62 ;
V_149:
F_105 ( V_62 ) ;
V_148:
F_124 ( V_62 ) ;
return NULL ;
}
static void F_125 ( struct V_61 * V_62 )
{
int V_150 ;
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
long V_152 = F_126 ( & V_62 -> V_139 . V_153 [ V_150 ] ) ;
if ( F_104 ( V_152 ) )
F_127 ( V_154 L_3
L_4 , V_62 , V_150 , V_152 ) ;
}
if ( F_126 ( & V_62 -> V_136 ) )
F_128 ( L_5 ,
F_126 ( & V_62 -> V_136 ) ) ;
if ( F_129 ( V_62 ) )
F_128 ( L_6 ,
F_129 ( V_62 ) ) ;
#if F_122 ( V_141 ) && ! V_142
F_130 ( V_62 -> V_143 , V_62 ) ;
#endif
}
struct V_61 * F_131 ( void )
{
struct V_61 * V_62 ;
V_62 = F_132 () ;
if ( ! V_62 )
return NULL ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
return F_115 ( V_62 , V_26 ) ;
}
void F_133 ( struct V_61 * V_62 )
{
F_21 ( V_62 == & V_155 ) ;
F_105 ( V_62 ) ;
F_134 ( V_62 ) ;
F_135 ( V_62 ) ;
F_125 ( V_62 ) ;
F_124 ( V_62 ) ;
}
static inline void F_136 ( struct V_61 * V_62 )
{
F_137 ( F_36 ( & V_62 -> V_132 ) ) ;
F_138 ( V_62 ) ;
F_139 ( V_62 ) ;
F_140 ( V_62 ) ;
F_141 ( V_62 ) ;
F_142 ( V_62 ) ;
F_143 ( V_62 , NULL ) ;
if ( ! F_144 ( & V_62 -> V_134 ) ) {
F_145 ( & V_156 ) ;
F_146 ( & V_62 -> V_134 ) ;
F_147 ( & V_156 ) ;
}
if ( V_62 -> V_157 )
F_148 ( V_62 -> V_157 -> V_158 ) ;
F_149 ( V_62 ) ;
}
void F_150 ( struct V_61 * V_62 )
{
F_151 () ;
if ( F_33 ( & V_62 -> V_132 ) )
F_136 ( V_62 ) ;
}
static void F_152 ( struct V_159 * V_160 )
{
struct V_61 * V_62 = F_153 ( V_160 , struct V_61 , V_161 ) ;
F_136 ( V_62 ) ;
}
void F_154 ( struct V_61 * V_62 )
{
if ( F_33 ( & V_62 -> V_132 ) ) {
F_155 ( & V_62 -> V_161 , F_152 ) ;
F_156 ( & V_62 -> V_161 ) ;
}
}
void F_143 ( struct V_61 * V_62 , struct V_87 * V_162 )
{
struct V_87 * V_163 ;
V_163 = F_157 ( V_62 -> V_78 ) ;
if ( V_162 )
F_83 ( V_162 ) ;
F_158 ( V_62 -> V_78 , V_162 ) ;
if ( V_163 )
F_159 ( V_163 ) ;
}
struct V_87 * F_72 ( struct V_61 * V_62 )
{
struct V_87 * V_78 ;
F_160 () ;
V_78 = F_161 ( V_62 -> V_78 ) ;
if ( V_78 && ! F_162 ( V_78 ) )
V_78 = NULL ;
F_163 () ;
return V_78 ;
}
struct V_61 * F_164 ( struct V_5 * V_164 )
{
struct V_61 * V_62 ;
F_165 ( V_164 ) ;
V_62 = V_164 -> V_62 ;
if ( V_62 ) {
if ( V_164 -> V_144 & V_165 )
V_62 = NULL ;
else
F_86 ( & V_62 -> V_132 ) ;
}
F_166 ( V_164 ) ;
return V_62 ;
}
struct V_61 * F_167 ( struct V_5 * V_164 , unsigned int V_166 )
{
struct V_61 * V_62 ;
int V_49 ;
V_49 = F_168 ( & V_164 -> signal -> V_167 ) ;
if ( V_49 )
return F_169 ( V_49 ) ;
V_62 = F_164 ( V_164 ) ;
if ( V_62 && V_62 != V_26 -> V_62 &&
! F_170 ( V_164 , V_166 ) ) {
F_150 ( V_62 ) ;
V_62 = F_169 ( - V_168 ) ;
}
F_171 ( & V_164 -> signal -> V_167 ) ;
return V_62 ;
}
static void F_172 ( struct V_5 * V_6 )
{
struct V_169 * V_170 ;
F_165 ( V_6 ) ;
V_170 = V_6 -> V_171 ;
if ( F_173 ( V_170 ) ) {
V_6 -> V_171 = NULL ;
F_174 ( V_170 ) ;
}
F_166 ( V_6 ) ;
}
static int F_175 ( struct V_5 * V_172 ,
struct V_169 * V_170 )
{
int V_173 ;
F_176 () ;
V_173 = F_177 ( V_170 ) ;
F_178 () ;
if ( V_173 ) {
F_165 ( V_172 ) ;
V_172 -> V_171 = NULL ;
F_166 ( V_172 ) ;
}
F_179 ( V_172 ) ;
return V_173 ;
}
void F_180 ( struct V_5 * V_6 , struct V_61 * V_62 )
{
#ifdef F_181
if ( F_104 ( V_6 -> V_174 ) ) {
F_182 ( V_6 ) ;
V_6 -> V_174 = NULL ;
}
#ifdef F_183
if ( F_104 ( V_6 -> V_175 ) ) {
F_184 ( V_6 ) ;
V_6 -> V_175 = NULL ;
}
#endif
if ( F_104 ( ! F_144 ( & V_6 -> V_176 ) ) )
F_185 ( V_6 ) ;
#endif
F_186 ( V_6 ) ;
F_187 ( V_6 , V_62 ) ;
if ( V_6 -> V_177 ) {
if ( ! ( V_6 -> V_144 & V_178 ) &&
F_36 ( & V_62 -> V_132 ) > 1 ) {
F_188 ( 0 , V_6 -> V_177 ) ;
F_189 ( V_6 -> V_177 , V_179 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_177 = NULL ;
}
if ( V_6 -> V_171 )
F_172 ( V_6 ) ;
}
static struct V_61 * F_190 ( struct V_5 * V_6 )
{
struct V_61 * V_62 , * V_63 = V_26 -> V_62 ;
int V_49 ;
V_62 = F_132 () ;
if ( ! V_62 )
goto V_92;
memcpy ( V_62 , V_63 , sizeof( * V_62 ) ) ;
if ( ! F_115 ( V_62 , V_6 ) )
goto V_92;
V_49 = F_65 ( V_62 , V_63 ) ;
if ( V_49 )
goto V_180;
V_62 -> V_181 = F_191 ( V_62 ) ;
V_62 -> V_182 = V_62 -> V_79 ;
if ( V_62 -> V_157 && ! F_192 ( V_62 -> V_157 -> V_158 ) )
goto V_180;
return V_62 ;
V_180:
V_62 -> V_157 = NULL ;
F_150 ( V_62 ) ;
V_92:
return NULL ;
}
static int F_193 ( unsigned long V_183 , struct V_5 * V_6 )
{
struct V_61 * V_62 , * V_63 ;
int V_72 ;
V_6 -> V_184 = V_6 -> V_185 = 0 ;
V_6 -> V_186 = V_6 -> V_187 = 0 ;
#ifdef F_194
V_6 -> V_188 = V_6 -> V_186 + V_6 -> V_187 ;
#endif
V_6 -> V_62 = NULL ;
V_6 -> V_189 = NULL ;
V_63 = V_26 -> V_62 ;
if ( ! V_63 )
return 0 ;
F_195 ( V_6 ) ;
if ( V_183 & V_190 ) {
F_86 ( & V_63 -> V_132 ) ;
V_62 = V_63 ;
goto V_191;
}
V_72 = - V_120 ;
V_62 = F_190 ( V_6 ) ;
if ( ! V_62 )
goto V_92;
V_191:
V_6 -> V_62 = V_62 ;
V_6 -> V_189 = V_62 ;
return 0 ;
V_92:
return V_72 ;
}
static int F_196 ( unsigned long V_183 , struct V_5 * V_6 )
{
struct V_192 * V_193 = V_26 -> V_193 ;
if ( V_183 & V_194 ) {
F_145 ( & V_193 -> V_195 ) ;
if ( V_193 -> V_196 ) {
F_147 ( & V_193 -> V_195 ) ;
return - V_197 ;
}
V_193 -> V_198 ++ ;
F_147 ( & V_193 -> V_195 ) ;
return 0 ;
}
V_6 -> V_193 = F_197 ( V_193 ) ;
if ( ! V_6 -> V_193 )
return - V_120 ;
return 0 ;
}
static int F_198 ( unsigned long V_183 , struct V_5 * V_6 )
{
struct V_199 * V_200 , * V_201 ;
int error = 0 ;
V_200 = V_26 -> V_202 ;
if ( ! V_200 )
goto V_85;
if ( V_183 & V_203 ) {
F_86 ( & V_200 -> V_153 ) ;
goto V_85;
}
V_201 = F_199 ( V_200 , & error ) ;
if ( ! V_201 )
goto V_85;
V_6 -> V_202 = V_201 ;
error = 0 ;
V_85:
return error ;
}
static int F_200 ( unsigned long V_183 , struct V_5 * V_6 )
{
#ifdef F_201
struct V_204 * V_205 = V_26 -> V_204 ;
struct V_204 * V_206 ;
if ( ! V_205 )
return 0 ;
if ( V_183 & V_207 ) {
F_202 ( V_205 ) ;
V_6 -> V_204 = V_205 ;
} else if ( F_203 ( V_205 -> V_208 ) ) {
V_206 = F_204 ( V_6 , V_9 , V_50 ) ;
if ( F_104 ( ! V_206 ) )
return - V_120 ;
V_206 -> V_208 = V_205 -> V_208 ;
F_205 ( V_206 ) ;
}
#endif
return 0 ;
}
static int F_206 ( unsigned long V_183 , struct V_5 * V_6 )
{
struct V_209 * V_21 ;
if ( V_183 & V_210 ) {
F_86 ( & V_26 -> V_211 -> V_153 ) ;
return 0 ;
}
V_21 = F_78 ( V_212 , V_9 ) ;
F_158 ( V_6 -> V_211 , V_21 ) ;
if ( ! V_21 )
return - V_120 ;
F_62 ( & V_21 -> V_153 , 1 ) ;
memcpy ( V_21 -> V_213 , V_26 -> V_211 -> V_213 , sizeof( V_21 -> V_213 ) ) ;
return 0 ;
}
void F_207 ( struct V_209 * V_211 )
{
if ( F_33 ( & V_211 -> V_153 ) ) {
F_208 ( V_211 ) ;
F_10 ( V_212 , V_211 ) ;
}
}
static void F_209 ( struct V_20 * V_21 )
{
unsigned long V_214 ;
V_214 = F_210 ( V_21 -> V_39 [ V_215 ] . V_41 ) ;
if ( V_214 != V_216 ) {
V_21 -> V_217 . V_218 = F_211 ( V_214 ) ;
V_21 -> V_219 . V_220 = true ;
}
F_79 ( & V_21 -> V_221 [ 0 ] ) ;
F_79 ( & V_21 -> V_221 [ 1 ] ) ;
F_79 ( & V_21 -> V_221 [ 2 ] ) ;
}
static int F_212 ( unsigned long V_183 , struct V_5 * V_6 )
{
struct V_20 * V_21 ;
if ( V_183 & V_222 )
return 0 ;
V_21 = F_213 ( V_22 , V_9 ) ;
V_6 -> signal = V_21 ;
if ( ! V_21 )
return - V_120 ;
V_21 -> V_223 = 1 ;
F_62 ( & V_21 -> V_224 , 1 ) ;
F_62 ( & V_21 -> V_23 , 1 ) ;
V_21 -> V_225 = (struct V_226 ) F_214 ( V_6 -> V_227 ) ;
V_6 -> V_227 = (struct V_226 ) F_214 ( V_21 -> V_225 ) ;
F_215 ( & V_21 -> V_228 ) ;
V_21 -> V_229 = V_6 ;
F_216 ( & V_21 -> V_230 ) ;
F_79 ( & V_21 -> V_231 ) ;
F_217 ( & V_21 -> V_232 ) ;
F_218 ( & V_21 -> V_233 ) ;
F_219 ( & V_21 -> V_234 , V_235 , V_236 ) ;
V_21 -> V_234 . V_237 = V_238 ;
F_165 ( V_26 -> V_239 ) ;
memcpy ( V_21 -> V_39 , V_26 -> signal -> V_39 , sizeof V_21 -> V_39 ) ;
F_166 ( V_26 -> V_239 ) ;
F_209 ( V_21 ) ;
F_220 ( V_21 ) ;
F_221 ( V_21 ) ;
V_21 -> V_240 = V_26 -> signal -> V_240 ;
V_21 -> V_241 = V_26 -> signal -> V_241 ;
V_21 -> V_242 = V_26 -> signal -> V_242 ||
V_26 -> signal -> V_243 ;
F_222 ( & V_21 -> V_167 ) ;
return 0 ;
}
static void F_223 ( struct V_5 * V_128 )
{
#ifdef F_56
F_224 ( & V_26 -> V_211 -> V_244 ) ;
F_225 ( V_26 ) ;
V_128 -> V_53 = V_26 -> V_53 ;
if ( F_226 ( V_26 ) )
F_227 ( V_128 ) ;
if ( V_128 -> V_53 . V_166 != V_245 )
F_228 ( V_128 , V_246 ) ;
#endif
}
static void F_229 ( struct V_5 * V_128 )
{
F_230 ( & V_128 -> V_247 ) ;
#ifdef F_231
V_128 -> V_248 = V_130 ;
V_128 -> V_249 = NULL ;
V_128 -> V_250 = NULL ;
#endif
}
static void F_232 ( struct V_5 * V_6 )
{
V_6 -> V_217 . V_218 = 0 ;
V_6 -> V_217 . V_251 = 0 ;
V_6 -> V_217 . V_252 = 0 ;
F_79 ( & V_6 -> V_221 [ 0 ] ) ;
F_79 ( & V_6 -> V_221 [ 1 ] ) ;
F_79 ( & V_6 -> V_221 [ 2 ] ) ;
}
static inline void
F_233 ( struct V_5 * V_164 , enum V_253 type , struct V_254 * V_254 )
{
V_164 -> V_255 [ type ] . V_254 = V_254 ;
}
static struct V_5 * F_234 ( unsigned long V_183 ,
unsigned long V_256 ,
unsigned long V_257 ,
int T_3 * V_258 ,
struct V_254 * V_254 ,
int V_259 ,
unsigned long V_260 ,
int V_7 )
{
int V_72 ;
struct V_5 * V_128 ;
if ( ( V_183 & ( V_261 | V_194 ) ) == ( V_261 | V_194 ) )
return F_169 ( - V_262 ) ;
if ( ( V_183 & ( V_263 | V_194 ) ) == ( V_263 | V_194 ) )
return F_169 ( - V_262 ) ;
if ( ( V_183 & V_222 ) && ! ( V_183 & V_210 ) )
return F_169 ( - V_262 ) ;
if ( ( V_183 & V_210 ) && ! ( V_183 & V_190 ) )
return F_169 ( - V_262 ) ;
if ( ( V_183 & V_264 ) &&
V_26 -> signal -> V_144 & V_265 )
return F_169 ( - V_262 ) ;
if ( V_183 & V_222 ) {
if ( ( V_183 & ( V_263 | V_266 ) ) ||
( F_235 ( V_26 ) !=
V_26 -> V_267 -> V_268 ) )
return F_169 ( - V_262 ) ;
}
V_72 = F_236 ( V_183 ) ;
if ( V_72 )
goto V_269;
V_72 = - V_120 ;
V_128 = F_54 ( V_26 , V_7 ) ;
if ( ! V_128 )
goto V_269;
F_237 ( V_128 ) ;
F_229 ( V_128 ) ;
#ifdef F_238
F_239 ( ! V_128 -> V_270 ) ;
F_239 ( ! V_128 -> V_271 ) ;
#endif
V_72 = - V_197 ;
if ( F_36 ( & V_128 -> V_272 -> V_273 -> V_274 ) >=
F_240 ( V_128 , V_40 ) ) {
if ( V_128 -> V_272 -> V_273 != V_275 &&
! F_241 ( V_276 ) && ! F_241 ( V_277 ) )
goto V_278;
}
V_26 -> V_144 &= ~ V_279 ;
V_72 = F_242 ( V_128 , V_183 ) ;
if ( V_72 < 0 )
goto V_278;
V_72 = - V_197 ;
if ( V_223 >= V_32 )
goto V_280;
F_243 ( V_128 ) ;
V_128 -> V_144 &= ~ ( V_281 | V_282 ) ;
V_128 -> V_144 |= V_283 ;
F_79 ( & V_128 -> V_284 ) ;
F_79 ( & V_128 -> V_285 ) ;
F_244 ( V_128 ) ;
V_128 -> V_171 = NULL ;
F_112 ( & V_128 -> V_286 ) ;
F_216 ( & V_128 -> V_287 ) ;
V_128 -> V_288 = V_128 -> V_289 = V_128 -> V_290 = 0 ;
V_128 -> V_291 = V_128 -> V_292 = 0 ;
F_218 ( & V_128 -> V_233 ) ;
#ifdef F_245
F_246 ( & V_128 -> V_293 ) ;
V_128 -> V_294 = 0 ;
V_128 -> V_295 = V_296 ;
#endif
#if F_122 ( V_297 )
memset ( & V_128 -> V_139 , 0 , sizeof( V_128 -> V_139 ) ) ;
#endif
V_128 -> V_298 = V_26 -> V_299 ;
F_247 ( & V_128 -> V_300 ) ;
F_248 ( V_128 ) ;
F_232 ( V_128 ) ;
V_128 -> V_301 = F_249 () ;
V_128 -> V_302 = F_250 () ;
V_128 -> V_204 = NULL ;
V_128 -> V_303 = NULL ;
F_251 ( V_26 ) ;
F_252 ( V_128 ) ;
#ifdef F_253
V_128 -> V_304 = F_254 ( V_128 -> V_304 ) ;
if ( F_255 ( V_128 -> V_304 ) ) {
V_72 = F_256 ( V_128 -> V_304 ) ;
V_128 -> V_304 = NULL ;
goto V_305;
}
#endif
#ifdef F_257
V_128 -> V_306 = V_50 ;
V_128 -> V_307 = V_50 ;
F_246 ( & V_128 -> V_308 ) ;
#endif
#ifdef F_258
V_128 -> V_309 = 0 ;
V_128 -> V_270 = 0 ;
V_128 -> V_310 = 0 ;
V_128 -> V_311 = 0 ;
V_128 -> V_312 = V_313 ;
V_128 -> V_314 = 0 ;
V_128 -> V_271 = 1 ;
V_128 -> V_315 = V_313 ;
V_128 -> V_316 = 0 ;
V_128 -> V_317 = 0 ;
V_128 -> V_318 = 0 ;
V_128 -> V_319 = 0 ;
V_128 -> V_320 = 0 ;
#endif
V_128 -> V_321 = 0 ;
#ifdef F_259
V_128 -> V_322 = 0 ;
V_128 -> V_323 = 0 ;
V_128 -> V_324 = 0 ;
#endif
#ifdef F_260
V_128 -> V_325 = NULL ;
#endif
#ifdef F_261
V_128 -> V_326 = 0 ;
V_128 -> V_327 = 0 ;
#endif
V_72 = F_262 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_328;
V_72 = F_263 ( V_128 ) ;
if ( V_72 )
goto V_328;
V_72 = F_264 ( V_128 ) ;
if ( V_72 )
goto V_329;
F_265 ( V_128 ) ;
V_72 = F_266 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_330;
V_72 = F_198 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_331;
V_72 = F_196 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_332;
V_72 = F_206 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_333;
V_72 = F_212 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_334;
V_72 = F_193 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_335;
V_72 = F_267 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_336;
V_72 = F_200 ( V_183 , V_128 ) ;
if ( V_72 )
goto V_337;
V_72 = F_268 ( V_183 , V_256 , V_257 , V_128 , V_260 ) ;
if ( V_72 )
goto V_338;
if ( V_254 != & V_339 ) {
V_254 = F_269 ( V_128 -> V_267 -> V_268 ) ;
if ( F_255 ( V_254 ) ) {
V_72 = F_256 ( V_254 ) ;
goto V_340;
}
}
V_128 -> V_341 = ( V_183 & V_342 ) ? V_258 : NULL ;
V_128 -> V_177 = ( V_183 & V_343 ) ? V_258 : NULL ;
#ifdef F_201
V_128 -> V_344 = NULL ;
#endif
#ifdef F_181
V_128 -> V_174 = NULL ;
#ifdef F_183
V_128 -> V_175 = NULL ;
#endif
F_79 ( & V_128 -> V_176 ) ;
V_128 -> V_345 = NULL ;
#endif
if ( ( V_183 & ( V_190 | V_346 ) ) == V_190 )
F_270 ( V_128 ) ;
F_271 ( V_128 ) ;
F_272 ( V_128 , V_347 ) ;
#ifdef F_273
F_272 ( V_128 , F_273 ) ;
#endif
F_274 ( V_128 ) ;
V_128 -> V_254 = F_275 ( V_254 ) ;
if ( V_183 & V_222 ) {
V_128 -> V_348 = - 1 ;
V_128 -> V_239 = V_26 -> V_239 ;
V_128 -> V_349 = V_26 -> V_349 ;
} else {
if ( V_183 & V_264 )
V_128 -> V_348 = V_26 -> V_239 -> V_348 ;
else
V_128 -> V_348 = ( V_183 & V_350 ) ;
V_128 -> V_239 = V_128 ;
V_128 -> V_349 = V_128 -> V_254 ;
}
V_128 -> V_351 = 0 ;
V_128 -> V_352 = 128 >> ( V_353 - 10 ) ;
V_128 -> V_354 = 0 ;
V_128 -> V_355 = 0 ;
F_79 ( & V_128 -> V_356 ) ;
V_128 -> V_357 = NULL ;
V_72 = F_276 ( V_128 ) ;
if ( V_72 )
goto V_358;
F_277 ( & V_1 ) ;
if ( V_183 & ( V_264 | V_222 ) ) {
V_128 -> V_359 = V_26 -> V_359 ;
V_128 -> V_360 = V_26 -> V_360 ;
} else {
V_128 -> V_359 = V_26 ;
V_128 -> V_360 = V_26 -> V_361 ;
}
F_145 ( & V_26 -> V_211 -> V_244 ) ;
F_223 ( V_128 ) ;
F_278 () ;
if ( F_279 ( V_26 ) ) {
F_147 ( & V_26 -> V_211 -> V_244 ) ;
F_280 ( & V_1 ) ;
V_72 = - V_362 ;
goto V_363;
}
if ( F_173 ( V_128 -> V_254 ) ) {
F_281 ( V_128 , ( V_183 & V_364 ) || V_259 ) ;
F_233 ( V_128 , V_365 , V_254 ) ;
if ( F_282 ( V_128 ) ) {
F_233 ( V_128 , V_366 , F_283 ( V_26 ) ) ;
F_233 ( V_128 , V_367 , F_284 ( V_26 ) ) ;
if ( F_285 ( V_254 ) ) {
F_286 ( V_254 ) -> V_368 = V_128 ;
V_128 -> signal -> V_144 |= V_265 ;
}
V_128 -> signal -> V_369 = V_254 ;
V_128 -> signal -> V_370 = F_287 ( V_26 -> signal -> V_370 ) ;
F_288 ( & V_128 -> V_285 , & V_128 -> V_359 -> V_284 ) ;
F_289 ( & V_128 -> V_371 , & V_38 . V_371 ) ;
F_290 ( V_128 , V_366 ) ;
F_290 ( V_128 , V_367 ) ;
F_291 ( V_4 ) ;
} else {
V_26 -> signal -> V_223 ++ ;
F_86 ( & V_26 -> signal -> V_224 ) ;
F_86 ( & V_26 -> signal -> V_23 ) ;
F_289 ( & V_128 -> V_356 ,
& V_128 -> V_239 -> V_356 ) ;
F_289 ( & V_128 -> V_227 ,
& V_128 -> signal -> V_225 ) ;
}
F_290 ( V_128 , V_365 ) ;
V_223 ++ ;
}
V_372 ++ ;
F_147 ( & V_26 -> V_211 -> V_244 ) ;
F_292 ( V_128 ) ;
F_280 ( & V_1 ) ;
F_293 ( V_128 ) ;
F_294 ( V_128 ) ;
F_295 ( V_26 ) ;
F_296 ( V_128 ) ;
F_297 ( V_128 , V_183 ) ;
F_298 ( V_128 , V_183 ) ;
return V_128 ;
V_363:
F_299 ( V_128 ) ;
V_358:
if ( V_254 != & V_339 )
F_300 ( V_254 ) ;
V_340:
F_301 ( V_128 ) ;
V_338:
if ( V_128 -> V_204 )
F_302 ( V_128 ) ;
V_337:
F_303 ( V_128 ) ;
V_336:
if ( V_128 -> V_62 )
F_150 ( V_128 -> V_62 ) ;
V_335:
if ( ! ( V_183 & V_222 ) )
F_29 ( V_128 -> signal ) ;
V_334:
F_207 ( V_128 -> V_211 ) ;
V_333:
F_304 ( V_128 ) ;
V_332:
F_305 ( V_128 ) ;
V_331:
F_306 ( V_128 ) ;
V_330:
F_307 ( V_128 ) ;
V_329:
F_308 ( V_128 ) ;
V_328:
#ifdef F_253
F_99 ( V_128 -> V_304 ) ;
V_305:
#endif
F_295 ( V_26 ) ;
F_41 ( V_128 ) ;
V_280:
F_84 ( & V_128 -> V_373 -> V_273 -> V_274 ) ;
F_40 ( V_128 ) ;
V_278:
F_25 ( V_128 ) ;
V_269:
return F_169 ( V_72 ) ;
}
static inline void F_309 ( struct V_374 * V_375 )
{
enum V_253 type ;
for ( type = V_365 ; type < V_376 ; ++ type ) {
F_310 ( & V_375 [ type ] . V_7 ) ;
V_375 [ type ] . V_254 = & V_339 ;
}
}
struct V_5 * F_311 ( int V_2 )
{
struct V_5 * V_164 ;
V_164 = F_234 ( V_190 , 0 , 0 , NULL , & V_339 , 0 , 0 ,
F_312 ( V_2 ) ) ;
if ( ! F_255 ( V_164 ) ) {
F_309 ( V_164 -> V_255 ) ;
F_313 ( V_164 , V_2 ) ;
}
return V_164 ;
}
long F_314 ( unsigned long V_183 ,
unsigned long V_256 ,
unsigned long V_257 ,
int T_3 * V_377 ,
int T_3 * V_258 ,
unsigned long V_260 )
{
struct V_5 * V_128 ;
int V_259 = 0 ;
long V_378 ;
if ( ! ( V_183 & V_379 ) ) {
if ( V_183 & V_346 )
V_259 = V_380 ;
else if ( ( V_183 & V_350 ) != V_381 )
V_259 = V_382 ;
else
V_259 = V_383 ;
if ( F_173 ( ! F_315 ( V_26 , V_259 ) ) )
V_259 = 0 ;
}
V_128 = F_234 ( V_183 , V_256 , V_257 ,
V_258 , NULL , V_259 , V_260 , V_50 ) ;
if ( ! F_255 ( V_128 ) ) {
struct V_169 V_170 ;
struct V_254 * V_254 ;
F_316 ( V_26 , V_128 ) ;
V_254 = F_317 ( V_128 , V_365 ) ;
V_378 = F_318 ( V_254 ) ;
if ( V_183 & V_384 )
F_188 ( V_378 , V_377 ) ;
if ( V_183 & V_346 ) {
V_128 -> V_171 = & V_170 ;
F_319 ( & V_170 ) ;
F_320 ( V_128 ) ;
}
F_321 ( V_128 ) ;
if ( F_104 ( V_259 ) )
F_322 ( V_259 , V_254 ) ;
if ( V_183 & V_346 ) {
if ( ! F_175 ( V_128 , & V_170 ) )
F_322 ( V_385 , V_254 ) ;
}
F_323 ( V_254 ) ;
} else {
V_378 = F_256 ( V_128 ) ;
}
return V_378 ;
}
long F_324 ( unsigned long V_183 ,
unsigned long V_256 ,
unsigned long V_257 ,
int T_3 * V_377 ,
int T_3 * V_258 )
{
return F_314 ( V_183 , V_256 , V_257 ,
V_377 , V_258 , 0 ) ;
}
T_4 F_325 ( int (* F_326)( void * ) , void * V_386 , unsigned long V_144 )
{
return F_314 ( V_144 | V_190 | V_379 , ( unsigned long ) F_326 ,
( unsigned long ) V_386 , NULL , NULL , 0 ) ;
}
static void F_327 ( void * V_387 )
{
struct V_209 * V_211 = V_387 ;
F_112 ( & V_211 -> V_244 ) ;
F_215 ( & V_211 -> V_388 ) ;
}
void T_1 F_328 ( void )
{
V_212 = F_20 ( L_7 ,
sizeof( struct V_209 ) , 0 ,
V_389 | V_35 | V_390 |
V_36 | V_37 , F_327 ) ;
V_22 = F_20 ( L_8 ,
sizeof( struct V_20 ) , 0 ,
V_389 | V_35 | V_36 | V_37 ,
NULL ) ;
V_391 = F_20 ( L_9 ,
sizeof( struct V_199 ) , 0 ,
V_389 | V_35 | V_36 | V_37 ,
NULL ) ;
V_392 = F_20 ( L_10 ,
sizeof( struct V_192 ) , 0 ,
V_389 | V_35 | V_36 | V_37 ,
NULL ) ;
V_393 = F_20 ( L_11 ,
sizeof( struct V_61 ) , V_394 ,
V_389 | V_35 | V_36 | V_37 ,
NULL ) ;
V_93 = F_329 ( V_64 , V_35 | V_37 ) ;
F_330 () ;
F_331 () ;
}
static int F_332 ( unsigned long V_395 )
{
if ( V_395 & ~ ( V_222 | V_194 | V_261 | V_210 |
V_190 | V_203 | V_396 |
V_397 | V_398 | V_399 |
V_263 | V_266 | V_400 ) )
return - V_262 ;
if ( V_395 & ( V_222 | V_210 | V_190 ) ) {
if ( ! F_333 ( V_26 ) )
return - V_262 ;
}
if ( V_395 & ( V_210 | V_190 ) ) {
if ( F_36 ( & V_26 -> V_211 -> V_153 ) > 1 )
return - V_262 ;
}
if ( V_395 & V_190 ) {
if ( ! F_334 () )
return - V_262 ;
}
return 0 ;
}
static int F_335 ( unsigned long V_395 , struct V_192 * * V_401 )
{
struct V_192 * V_193 = V_26 -> V_193 ;
if ( ! ( V_395 & V_194 ) || ! V_193 )
return 0 ;
if ( V_193 -> V_198 == 1 )
return 0 ;
* V_401 = F_197 ( V_193 ) ;
if ( ! * V_401 )
return - V_120 ;
return 0 ;
}
static int F_336 ( unsigned long V_395 , struct V_199 * * V_402 )
{
struct V_199 * V_403 = V_26 -> V_202 ;
int error = 0 ;
if ( ( V_395 & V_203 ) &&
( V_403 && F_36 ( & V_403 -> V_153 ) > 1 ) ) {
* V_402 = F_199 ( V_403 , & error ) ;
if ( ! * V_402 )
return error ;
}
return 0 ;
}
int F_337 ( struct V_199 * * V_404 )
{
struct V_5 * V_164 = V_26 ;
struct V_199 * V_405 = NULL ;
int error ;
error = F_336 ( V_203 , & V_405 ) ;
if ( error || ! V_405 ) {
* V_404 = NULL ;
return error ;
}
* V_404 = V_164 -> V_202 ;
F_165 ( V_164 ) ;
V_164 -> V_202 = V_405 ;
F_166 ( V_164 ) ;
return 0 ;
}
int F_338 ( struct V_406 * V_407 , int V_408 ,
void T_3 * V_409 , T_5 * V_410 , T_6 * V_411 )
{
struct V_406 V_412 ;
int V_413 ;
int V_28 = V_32 ;
int V_414 = V_33 ;
int V_415 = V_31 ;
V_412 = * V_407 ;
V_412 . V_387 = & V_28 ;
V_412 . V_416 = & V_414 ;
V_412 . V_417 = & V_415 ;
V_413 = F_339 ( & V_412 , V_408 , V_409 , V_410 , V_411 ) ;
if ( V_413 || ! V_408 )
return V_413 ;
F_44 ( V_28 ) ;
return 0 ;
}
