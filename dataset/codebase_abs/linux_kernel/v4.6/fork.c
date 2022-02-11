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
if ( V_12 )
F_14 ( V_12 , V_15 ,
1 << V_14 ) ;
return V_12 ? F_15 ( V_12 ) : NULL ;
}
static inline void F_16 ( struct V_10 * V_11 )
{
struct V_12 * V_12 = F_17 ( V_11 ) ;
F_14 ( V_12 , V_15 ,
- ( 1 << V_14 ) ) ;
F_18 ( V_12 , V_14 ) ;
}
static struct V_10 * F_12 ( struct V_5 * V_6 ,
int V_7 )
{
return F_8 ( V_16 , V_13 , V_7 ) ;
}
static void F_16 ( struct V_10 * V_11 )
{
F_10 ( V_16 , V_11 ) ;
}
void F_19 ( void )
{
V_16 = F_20 ( L_1 , V_17 ,
V_17 , 0 , NULL ) ;
F_21 ( V_16 == NULL ) ;
}
static void F_22 ( struct V_10 * V_11 , int V_18 )
{
struct V_19 * V_19 = F_23 ( F_17 ( V_11 ) ) ;
F_24 ( V_19 , V_20 , V_18 ) ;
}
void F_25 ( struct V_5 * V_6 )
{
F_22 ( V_6 -> V_21 , - 1 ) ;
F_11 ( V_6 -> V_21 ) ;
F_16 ( V_6 -> V_21 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
F_28 ( V_6 ) ;
F_6 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_29 ( struct V_22 * V_23 )
{
F_30 ( V_23 ) ;
F_31 ( V_23 ) ;
F_10 ( V_24 , V_23 ) ;
}
static inline void F_32 ( struct V_22 * V_23 )
{
if ( F_33 ( & V_23 -> V_25 ) )
F_29 ( V_23 ) ;
}
void F_34 ( struct V_5 * V_6 )
{
F_35 ( ! V_6 -> V_26 ) ;
F_35 ( F_36 ( & V_6 -> V_27 ) ) ;
F_35 ( V_6 == V_28 ) ;
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
static void F_44 ( unsigned int V_29 )
{
T_2 V_30 ;
if ( F_45 ( V_31 ) + F_45 ( V_32 ) > 64 )
V_30 = V_33 ;
else
V_30 = F_46 ( ( T_2 ) V_31 * ( T_2 ) V_32 ,
( T_2 ) V_17 * 8UL ) ;
if ( V_30 > V_29 )
V_30 = V_29 ;
V_34 = F_47 ( T_2 , V_30 , V_35 , V_33 ) ;
}
void T_1 F_48 ( void )
{
#ifndef F_49
#ifndef F_50
#define F_50 L1_CACHE_BYTES
#endif
V_8 = F_20 ( L_2 ,
V_36 , F_50 ,
V_37 | V_38 | V_39 , NULL ) ;
#endif
F_43 () ;
F_44 ( V_33 ) ;
V_40 . signal -> V_41 [ V_42 ] . V_43 = V_34 / 2 ;
V_40 . signal -> V_41 [ V_42 ] . V_44 = V_34 / 2 ;
V_40 . signal -> V_41 [ V_45 ] =
V_40 . signal -> V_41 [ V_42 ] ;
}
int __weak F_51 ( struct V_5 * V_46 ,
struct V_5 * V_47 )
{
* V_46 = * V_47 ;
return 0 ;
}
void F_52 ( struct V_5 * V_6 )
{
unsigned long * V_48 ;
V_48 = F_53 ( V_6 ) ;
* V_48 = V_49 ;
}
static struct V_5 * F_54 ( struct V_5 * V_50 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_7 = F_55 ( V_50 ) ;
int V_51 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_52;
V_51 = F_51 ( V_6 , V_50 ) ;
if ( V_51 )
goto V_53;
V_6 -> V_21 = V_11 ;
#ifdef F_56
V_6 -> V_54 . V_55 = NULL ;
#endif
F_57 ( V_6 , V_50 ) ;
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
F_52 ( V_6 ) ;
#ifdef F_60
V_6 -> V_56 = F_61 () ;
#endif
F_62 ( & V_6 -> V_27 , 2 ) ;
#ifdef F_63
V_6 -> V_57 = 0 ;
#endif
V_6 -> V_58 = NULL ;
V_6 -> V_59 . V_12 = NULL ;
V_6 -> V_60 . V_61 = NULL ;
F_22 ( V_11 , 1 ) ;
F_64 ( V_6 ) ;
return V_6 ;
V_53:
F_16 ( V_11 ) ;
V_52:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_65 ( struct V_62 * V_63 , struct V_62 * V_64 )
{
struct V_65 * V_66 , * V_67 , * V_68 , * * V_69 ;
struct V_70 * * V_71 , * V_72 ;
int V_73 ;
unsigned long V_74 ;
F_66 () ;
F_67 ( & V_64 -> V_75 ) ;
F_68 ( V_64 ) ;
F_69 ( V_64 , V_63 ) ;
F_70 ( & V_63 -> V_75 , V_76 ) ;
F_71 ( V_63 -> V_77 , F_72 ( V_64 ) ) ;
V_63 -> V_78 = V_64 -> V_78 ;
V_63 -> V_79 = V_64 -> V_79 ;
V_63 -> V_80 = V_64 -> V_80 ;
V_63 -> V_81 = V_64 -> V_81 ;
V_71 = & V_63 -> V_82 . V_70 ;
V_72 = NULL ;
V_69 = & V_63 -> V_83 ;
V_73 = F_73 ( V_63 , V_64 ) ;
if ( V_73 )
goto V_84;
V_73 = F_74 ( V_63 , V_64 ) ;
if ( V_73 )
goto V_84;
V_68 = NULL ;
for ( V_66 = V_64 -> V_83 ; V_66 ; V_66 = V_66 -> V_85 ) {
struct V_86 * V_86 ;
if ( V_66 -> V_87 & V_88 ) {
F_75 ( V_63 , V_66 -> V_87 , - F_76 ( V_66 ) ) ;
continue;
}
V_74 = 0 ;
if ( V_66 -> V_87 & V_89 ) {
unsigned long V_90 = F_76 ( V_66 ) ;
if ( F_77 ( V_64 , V_90 ) )
goto V_91;
V_74 = V_90 ;
}
V_67 = F_78 ( V_92 , V_9 ) ;
if ( ! V_67 )
goto V_91;
* V_67 = * V_66 ;
F_79 ( & V_67 -> V_93 ) ;
V_73 = F_80 ( V_66 , V_67 ) ;
if ( V_73 )
goto V_94;
V_67 -> V_95 = V_63 ;
if ( F_81 ( V_67 , V_66 ) )
goto V_96;
V_67 -> V_87 &=
~ ( V_97 | V_98 | V_99 | V_100 ) ;
V_67 -> V_85 = V_67 -> V_101 = NULL ;
V_67 -> V_102 = V_103 ;
V_86 = V_67 -> V_104 ;
if ( V_86 ) {
struct V_105 * V_105 = F_82 ( V_86 ) ;
struct V_106 * V_107 = V_86 -> V_108 ;
F_83 ( V_86 ) ;
if ( V_67 -> V_87 & V_109 )
F_84 ( & V_105 -> V_110 ) ;
F_85 ( V_107 ) ;
if ( V_67 -> V_87 & V_111 )
F_86 ( & V_107 -> V_112 ) ;
F_87 ( V_107 ) ;
F_88 ( V_67 , V_66 ,
& V_107 -> V_113 ) ;
F_89 ( V_107 ) ;
F_90 ( V_107 ) ;
}
if ( F_91 ( V_67 ) )
F_92 ( V_67 ) ;
* V_69 = V_67 ;
V_69 = & V_67 -> V_85 ;
V_67 -> V_101 = V_68 ;
V_68 = V_67 ;
F_93 ( V_63 , V_67 , V_71 , V_72 ) ;
V_71 = & V_67 -> V_114 . V_115 ;
V_72 = & V_67 -> V_114 ;
V_63 -> V_116 ++ ;
V_73 = F_94 ( V_63 , V_64 , V_66 ) ;
if ( V_67 -> V_117 && V_67 -> V_117 -> V_118 )
V_67 -> V_117 -> V_118 ( V_67 ) ;
if ( V_73 )
goto V_84;
}
F_95 ( V_64 , V_63 ) ;
V_73 = 0 ;
V_84:
F_96 ( & V_63 -> V_75 ) ;
F_97 ( V_64 ) ;
F_96 ( & V_64 -> V_75 ) ;
F_98 () ;
return V_73 ;
V_96:
F_99 ( F_100 ( V_67 ) ) ;
V_94:
F_10 ( V_92 , V_67 ) ;
V_91:
V_73 = - V_119 ;
F_101 ( V_74 ) ;
goto V_84;
}
static inline int F_102 ( struct V_62 * V_63 )
{
V_63 -> V_120 = F_103 ( V_63 ) ;
if ( F_104 ( ! V_63 -> V_120 ) )
return - V_119 ;
return 0 ;
}
static inline void F_105 ( struct V_62 * V_63 )
{
F_106 ( V_63 , V_63 -> V_120 ) ;
}
static int F_65 ( struct V_62 * V_63 , struct V_62 * V_64 )
{
F_67 ( & V_64 -> V_75 ) ;
F_71 ( V_63 -> V_77 , F_72 ( V_64 ) ) ;
F_96 ( & V_64 -> V_75 ) ;
return 0 ;
}
static int T_1 F_107 ( char * V_121 )
{
V_122 =
( F_108 ( V_121 , NULL , 0 ) << V_123 ) &
V_124 ;
return 1 ;
}
static void F_109 ( struct V_62 * V_63 )
{
#ifdef F_110
F_111 ( & V_63 -> V_125 ) ;
V_63 -> V_126 = NULL ;
#endif
}
static void F_112 ( struct V_62 * V_63 , struct V_5 * V_127 )
{
#ifdef F_113
V_63 -> V_128 = V_127 ;
#endif
}
static struct V_62 * F_114 ( struct V_62 * V_63 , struct V_5 * V_127 )
{
V_63 -> V_83 = NULL ;
V_63 -> V_82 = V_129 ;
V_63 -> V_130 = 0 ;
F_62 ( & V_63 -> V_131 , 1 ) ;
F_62 ( & V_63 -> V_132 , 1 ) ;
F_115 ( & V_63 -> V_75 ) ;
F_79 ( & V_63 -> V_133 ) ;
V_63 -> V_134 = NULL ;
F_116 ( & V_63 -> V_135 , 0 ) ;
F_117 ( V_63 ) ;
V_63 -> V_116 = 0 ;
V_63 -> V_136 = 0 ;
V_63 -> V_137 = 0 ;
memset ( & V_63 -> V_138 , 0 , sizeof( V_63 -> V_138 ) ) ;
F_111 ( & V_63 -> V_139 ) ;
F_118 ( V_63 ) ;
F_109 ( V_63 ) ;
F_112 ( V_63 , V_127 ) ;
F_119 ( V_63 ) ;
F_120 ( V_63 ) ;
#if F_121 ( V_140 ) && ! V_141
V_63 -> V_142 = NULL ;
#endif
if ( V_28 -> V_63 ) {
V_63 -> V_143 = V_28 -> V_63 -> V_143 & V_144 ;
V_63 -> V_145 = V_28 -> V_63 -> V_145 & V_146 ;
} else {
V_63 -> V_143 = V_122 ;
V_63 -> V_145 = 0 ;
}
if ( F_102 ( V_63 ) )
goto V_147;
if ( F_122 ( V_127 , V_63 ) )
goto V_148;
return V_63 ;
V_148:
F_105 ( V_63 ) ;
V_147:
F_123 ( V_63 ) ;
return NULL ;
}
static void F_124 ( struct V_62 * V_63 )
{
int V_149 ;
for ( V_149 = 0 ; V_149 < V_150 ; V_149 ++ ) {
long V_151 = F_125 ( & V_63 -> V_138 . V_152 [ V_149 ] ) ;
if ( F_104 ( V_151 ) )
F_126 ( V_153 L_3
L_4 , V_63 , V_149 , V_151 ) ;
}
if ( F_125 ( & V_63 -> V_135 ) )
F_127 ( L_5 ,
F_125 ( & V_63 -> V_135 ) ) ;
if ( F_128 ( V_63 ) )
F_127 ( L_6 ,
F_128 ( V_63 ) ) ;
#if F_121 ( V_140 ) && ! V_141
F_129 ( V_63 -> V_142 , V_63 ) ;
#endif
}
struct V_62 * F_130 ( void )
{
struct V_62 * V_63 ;
V_63 = F_131 () ;
if ( ! V_63 )
return NULL ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
return F_114 ( V_63 , V_28 ) ;
}
void F_132 ( struct V_62 * V_63 )
{
F_21 ( V_63 == & V_154 ) ;
F_105 ( V_63 ) ;
F_133 ( V_63 ) ;
F_134 ( V_63 ) ;
F_124 ( V_63 ) ;
F_123 ( V_63 ) ;
}
void F_135 ( struct V_62 * V_63 )
{
F_136 () ;
if ( F_33 ( & V_63 -> V_131 ) ) {
F_137 ( V_63 ) ;
F_138 ( V_63 ) ;
F_139 ( V_63 ) ;
F_140 ( V_63 ) ;
F_141 ( V_63 ) ;
F_142 ( V_63 , NULL ) ;
if ( ! F_143 ( & V_63 -> V_133 ) ) {
F_144 ( & V_155 ) ;
F_145 ( & V_63 -> V_133 ) ;
F_146 ( & V_155 ) ;
}
if ( V_63 -> V_156 )
F_147 ( V_63 -> V_156 -> V_157 ) ;
F_148 ( V_63 ) ;
}
}
void F_142 ( struct V_62 * V_63 , struct V_86 * V_158 )
{
struct V_86 * V_159 ;
V_159 = F_149 ( V_63 -> V_77 ) ;
if ( V_158 )
F_83 ( V_158 ) ;
F_150 ( V_63 -> V_77 , V_158 ) ;
if ( V_159 )
F_151 ( V_159 ) ;
}
struct V_86 * F_72 ( struct V_62 * V_63 )
{
struct V_86 * V_77 ;
F_152 () ;
V_77 = F_153 ( V_63 -> V_77 ) ;
if ( V_77 && ! F_154 ( V_77 ) )
V_77 = NULL ;
F_155 () ;
return V_77 ;
}
struct V_62 * F_156 ( struct V_5 * V_160 )
{
struct V_62 * V_63 ;
F_157 ( V_160 ) ;
V_63 = V_160 -> V_63 ;
if ( V_63 ) {
if ( V_160 -> V_143 & V_161 )
V_63 = NULL ;
else
F_86 ( & V_63 -> V_131 ) ;
}
F_158 ( V_160 ) ;
return V_63 ;
}
struct V_62 * F_159 ( struct V_5 * V_160 , unsigned int V_162 )
{
struct V_62 * V_63 ;
int V_51 ;
V_51 = F_160 ( & V_160 -> signal -> V_163 ) ;
if ( V_51 )
return F_161 ( V_51 ) ;
V_63 = F_156 ( V_160 ) ;
if ( V_63 && V_63 != V_28 -> V_63 &&
! F_162 ( V_160 , V_162 ) ) {
F_135 ( V_63 ) ;
V_63 = F_161 ( - V_164 ) ;
}
F_163 ( & V_160 -> signal -> V_163 ) ;
return V_63 ;
}
static void F_164 ( struct V_5 * V_6 )
{
struct V_165 * V_166 ;
F_157 ( V_6 ) ;
V_166 = V_6 -> V_167 ;
if ( F_165 ( V_166 ) ) {
V_6 -> V_167 = NULL ;
F_166 ( V_166 ) ;
}
F_158 ( V_6 ) ;
}
static int F_167 ( struct V_5 * V_168 ,
struct V_165 * V_166 )
{
int V_169 ;
F_168 () ;
V_169 = F_169 ( V_166 ) ;
F_170 () ;
if ( V_169 ) {
F_157 ( V_168 ) ;
V_168 -> V_167 = NULL ;
F_158 ( V_168 ) ;
}
F_171 ( V_168 ) ;
return V_169 ;
}
void F_172 ( struct V_5 * V_6 , struct V_62 * V_63 )
{
#ifdef F_173
if ( F_104 ( V_6 -> V_170 ) ) {
F_174 ( V_6 ) ;
V_6 -> V_170 = NULL ;
}
#ifdef F_175
if ( F_104 ( V_6 -> V_171 ) ) {
F_176 ( V_6 ) ;
V_6 -> V_171 = NULL ;
}
#endif
if ( F_104 ( ! F_143 ( & V_6 -> V_172 ) ) )
F_177 ( V_6 ) ;
#endif
F_178 ( V_6 ) ;
F_179 ( V_6 , V_63 ) ;
if ( V_6 -> V_173 ) {
if ( ! ( V_6 -> V_143 & V_174 ) &&
F_36 ( & V_63 -> V_131 ) > 1 ) {
F_180 ( 0 , V_6 -> V_173 ) ;
F_181 ( V_6 -> V_173 , V_175 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_173 = NULL ;
}
if ( V_6 -> V_167 )
F_164 ( V_6 ) ;
}
static struct V_62 * F_182 ( struct V_5 * V_6 )
{
struct V_62 * V_63 , * V_64 = V_28 -> V_63 ;
int V_51 ;
V_63 = F_131 () ;
if ( ! V_63 )
goto V_91;
memcpy ( V_63 , V_64 , sizeof( * V_63 ) ) ;
if ( ! F_114 ( V_63 , V_6 ) )
goto V_91;
V_51 = F_65 ( V_63 , V_64 ) ;
if ( V_51 )
goto V_176;
V_63 -> V_177 = F_183 ( V_63 ) ;
V_63 -> V_178 = V_63 -> V_78 ;
if ( V_63 -> V_156 && ! F_184 ( V_63 -> V_156 -> V_157 ) )
goto V_176;
return V_63 ;
V_176:
V_63 -> V_156 = NULL ;
F_135 ( V_63 ) ;
V_91:
return NULL ;
}
static int F_185 ( unsigned long V_179 , struct V_5 * V_6 )
{
struct V_62 * V_63 , * V_64 ;
int V_73 ;
V_6 -> V_180 = V_6 -> V_181 = 0 ;
V_6 -> V_182 = V_6 -> V_183 = 0 ;
#ifdef F_186
V_6 -> V_184 = V_6 -> V_182 + V_6 -> V_183 ;
#endif
V_6 -> V_63 = NULL ;
V_6 -> V_185 = NULL ;
V_64 = V_28 -> V_63 ;
if ( ! V_64 )
return 0 ;
F_187 ( V_6 ) ;
if ( V_179 & V_186 ) {
F_86 ( & V_64 -> V_131 ) ;
V_63 = V_64 ;
goto V_187;
}
V_73 = - V_119 ;
V_63 = F_182 ( V_6 ) ;
if ( ! V_63 )
goto V_91;
V_187:
V_6 -> V_63 = V_63 ;
V_6 -> V_185 = V_63 ;
return 0 ;
V_91:
return V_73 ;
}
static int F_188 ( unsigned long V_179 , struct V_5 * V_6 )
{
struct V_188 * V_189 = V_28 -> V_189 ;
if ( V_179 & V_190 ) {
F_144 ( & V_189 -> V_191 ) ;
if ( V_189 -> V_192 ) {
F_146 ( & V_189 -> V_191 ) ;
return - V_193 ;
}
V_189 -> V_194 ++ ;
F_146 ( & V_189 -> V_191 ) ;
return 0 ;
}
V_6 -> V_189 = F_189 ( V_189 ) ;
if ( ! V_6 -> V_189 )
return - V_119 ;
return 0 ;
}
static int F_190 ( unsigned long V_179 , struct V_5 * V_6 )
{
struct V_195 * V_196 , * V_197 ;
int error = 0 ;
V_196 = V_28 -> V_198 ;
if ( ! V_196 )
goto V_84;
if ( V_179 & V_199 ) {
F_86 ( & V_196 -> V_152 ) ;
goto V_84;
}
V_197 = F_191 ( V_196 , & error ) ;
if ( ! V_197 )
goto V_84;
V_6 -> V_198 = V_197 ;
error = 0 ;
V_84:
return error ;
}
static int F_192 ( unsigned long V_179 , struct V_5 * V_6 )
{
#ifdef F_193
struct V_200 * V_201 = V_28 -> V_200 ;
struct V_200 * V_202 ;
if ( ! V_201 )
return 0 ;
if ( V_179 & V_203 ) {
F_194 ( V_201 ) ;
V_6 -> V_200 = V_201 ;
} else if ( F_195 ( V_201 -> V_204 ) ) {
V_202 = F_196 ( V_6 , V_9 , V_205 ) ;
if ( F_104 ( ! V_202 ) )
return - V_119 ;
V_202 -> V_204 = V_201 -> V_204 ;
F_197 ( V_202 ) ;
}
#endif
return 0 ;
}
static int F_198 ( unsigned long V_179 , struct V_5 * V_6 )
{
struct V_206 * V_23 ;
if ( V_179 & V_207 ) {
F_86 ( & V_28 -> V_208 -> V_152 ) ;
return 0 ;
}
V_23 = F_78 ( V_209 , V_9 ) ;
F_150 ( V_6 -> V_208 , V_23 ) ;
if ( ! V_23 )
return - V_119 ;
F_62 ( & V_23 -> V_152 , 1 ) ;
memcpy ( V_23 -> V_210 , V_28 -> V_208 -> V_210 , sizeof( V_23 -> V_210 ) ) ;
return 0 ;
}
void F_199 ( struct V_206 * V_208 )
{
if ( F_33 ( & V_208 -> V_152 ) ) {
F_200 ( V_208 ) ;
F_10 ( V_209 , V_208 ) ;
}
}
static void F_201 ( struct V_22 * V_23 )
{
unsigned long V_211 ;
V_211 = F_202 ( V_23 -> V_41 [ V_212 ] . V_43 ) ;
if ( V_211 != V_213 ) {
V_23 -> V_214 . V_215 = F_203 ( V_211 ) ;
V_23 -> V_216 . V_217 = true ;
}
F_79 ( & V_23 -> V_218 [ 0 ] ) ;
F_79 ( & V_23 -> V_218 [ 1 ] ) ;
F_79 ( & V_23 -> V_218 [ 2 ] ) ;
}
static int F_204 ( unsigned long V_179 , struct V_5 * V_6 )
{
struct V_22 * V_23 ;
if ( V_179 & V_219 )
return 0 ;
V_23 = F_205 ( V_24 , V_9 ) ;
V_6 -> signal = V_23 ;
if ( ! V_23 )
return - V_119 ;
V_23 -> V_220 = 1 ;
F_62 ( & V_23 -> V_221 , 1 ) ;
F_62 ( & V_23 -> V_25 , 1 ) ;
V_23 -> V_222 = (struct V_223 ) F_206 ( V_6 -> V_224 ) ;
V_6 -> V_224 = (struct V_223 ) F_206 ( V_23 -> V_222 ) ;
F_207 ( & V_23 -> V_225 ) ;
V_23 -> V_226 = V_6 ;
F_208 ( & V_23 -> V_227 ) ;
F_79 ( & V_23 -> V_228 ) ;
F_209 ( & V_23 -> V_229 ) ;
F_210 ( & V_23 -> V_230 ) ;
F_211 ( & V_23 -> V_231 , V_232 , V_233 ) ;
V_23 -> V_231 . V_234 = V_235 ;
F_157 ( V_28 -> V_236 ) ;
memcpy ( V_23 -> V_41 , V_28 -> signal -> V_41 , sizeof V_23 -> V_41 ) ;
F_158 ( V_28 -> V_236 ) ;
F_201 ( V_23 ) ;
F_212 ( V_23 ) ;
F_213 ( V_23 ) ;
V_23 -> V_237 = V_28 -> signal -> V_237 ;
V_23 -> V_238 = V_28 -> signal -> V_238 ;
V_23 -> V_239 = V_28 -> signal -> V_239 ||
V_28 -> signal -> V_240 ;
F_214 ( & V_23 -> V_163 ) ;
return 0 ;
}
static void F_215 ( struct V_5 * V_127 )
{
#ifdef F_56
F_216 ( & V_28 -> V_208 -> V_241 ) ;
F_217 ( V_28 ) ;
V_127 -> V_54 = V_28 -> V_54 ;
if ( F_218 ( V_28 ) )
F_219 ( V_127 ) ;
if ( V_127 -> V_54 . V_162 != V_242 )
F_220 ( V_127 , V_243 ) ;
#endif
}
static void F_221 ( struct V_5 * V_127 )
{
F_222 ( & V_127 -> V_244 ) ;
#ifdef F_223
V_127 -> V_245 = V_129 ;
V_127 -> V_246 = NULL ;
V_127 -> V_247 = NULL ;
#endif
}
static void F_224 ( struct V_5 * V_6 )
{
V_6 -> V_214 . V_215 = 0 ;
V_6 -> V_214 . V_248 = 0 ;
V_6 -> V_214 . V_249 = 0 ;
F_79 ( & V_6 -> V_218 [ 0 ] ) ;
F_79 ( & V_6 -> V_218 [ 1 ] ) ;
F_79 ( & V_6 -> V_218 [ 2 ] ) ;
}
static inline void
F_225 ( struct V_5 * V_160 , enum V_250 type , struct V_251 * V_251 )
{
V_160 -> V_252 [ type ] . V_251 = V_251 ;
}
static struct V_5 * F_226 ( unsigned long V_179 ,
unsigned long V_253 ,
unsigned long V_254 ,
int T_3 * V_255 ,
struct V_251 * V_251 ,
int V_256 ,
unsigned long V_257 )
{
int V_73 ;
struct V_5 * V_127 ;
if ( ( V_179 & ( V_258 | V_190 ) ) == ( V_258 | V_190 ) )
return F_161 ( - V_259 ) ;
if ( ( V_179 & ( V_260 | V_190 ) ) == ( V_260 | V_190 ) )
return F_161 ( - V_259 ) ;
if ( ( V_179 & V_219 ) && ! ( V_179 & V_207 ) )
return F_161 ( - V_259 ) ;
if ( ( V_179 & V_207 ) && ! ( V_179 & V_186 ) )
return F_161 ( - V_259 ) ;
if ( ( V_179 & V_261 ) &&
V_28 -> signal -> V_143 & V_262 )
return F_161 ( - V_259 ) ;
if ( V_179 & V_219 ) {
if ( ( V_179 & ( V_260 | V_263 ) ) ||
( F_227 ( V_28 ) !=
V_28 -> V_264 -> V_265 ) )
return F_161 ( - V_259 ) ;
}
V_73 = F_228 ( V_179 ) ;
if ( V_73 )
goto V_266;
V_73 = - V_119 ;
V_127 = F_54 ( V_28 ) ;
if ( ! V_127 )
goto V_266;
F_229 ( V_127 ) ;
F_221 ( V_127 ) ;
#ifdef F_230
F_231 ( ! V_127 -> V_267 ) ;
F_231 ( ! V_127 -> V_268 ) ;
#endif
V_73 = - V_193 ;
if ( F_36 ( & V_127 -> V_269 -> V_270 -> V_271 ) >=
F_232 ( V_127 , V_42 ) ) {
if ( V_127 -> V_269 -> V_270 != V_272 &&
! F_233 ( V_273 ) && ! F_233 ( V_274 ) )
goto V_275;
}
V_28 -> V_143 &= ~ V_276 ;
V_73 = F_234 ( V_127 , V_179 ) ;
if ( V_73 < 0 )
goto V_275;
V_73 = - V_193 ;
if ( V_220 >= V_34 )
goto V_277;
F_235 ( V_127 ) ;
V_127 -> V_143 &= ~ ( V_278 | V_279 ) ;
V_127 -> V_143 |= V_280 ;
F_79 ( & V_127 -> V_281 ) ;
F_79 ( & V_127 -> V_282 ) ;
F_236 ( V_127 ) ;
V_127 -> V_167 = NULL ;
F_111 ( & V_127 -> V_283 ) ;
F_208 ( & V_127 -> V_284 ) ;
V_127 -> V_285 = V_127 -> V_286 = V_127 -> V_287 = 0 ;
V_127 -> V_288 = V_127 -> V_289 = 0 ;
F_210 ( & V_127 -> V_230 ) ;
#ifdef F_237
F_238 ( & V_127 -> V_290 ) ;
V_127 -> V_291 = 0 ;
V_127 -> V_292 = V_293 ;
#endif
#if F_121 ( V_294 )
memset ( & V_127 -> V_138 , 0 , sizeof( V_127 -> V_138 ) ) ;
#endif
V_127 -> V_295 = V_28 -> V_296 ;
F_239 ( & V_127 -> V_297 ) ;
F_240 ( V_127 ) ;
F_224 ( V_127 ) ;
V_127 -> V_298 = F_241 () ;
V_127 -> V_299 = F_242 () ;
V_127 -> V_200 = NULL ;
V_127 -> V_300 = NULL ;
F_243 ( V_28 ) ;
F_244 ( V_127 ) ;
#ifdef F_245
V_127 -> V_301 = F_246 ( V_127 -> V_301 ) ;
if ( F_247 ( V_127 -> V_301 ) ) {
V_73 = F_248 ( V_127 -> V_301 ) ;
V_127 -> V_301 = NULL ;
goto V_302;
}
#endif
#ifdef F_249
V_127 -> V_303 = V_205 ;
V_127 -> V_304 = V_205 ;
F_238 ( & V_127 -> V_305 ) ;
#endif
#ifdef F_250
V_127 -> V_306 = 0 ;
V_127 -> V_267 = 0 ;
V_127 -> V_307 = 0 ;
V_127 -> V_308 = 0 ;
V_127 -> V_309 = V_310 ;
V_127 -> V_311 = 0 ;
V_127 -> V_268 = 1 ;
V_127 -> V_312 = V_310 ;
V_127 -> V_313 = 0 ;
V_127 -> V_314 = 0 ;
V_127 -> V_315 = 0 ;
V_127 -> V_316 = 0 ;
V_127 -> V_317 = 0 ;
#endif
V_127 -> V_318 = 0 ;
#ifdef F_251
V_127 -> V_319 = 0 ;
V_127 -> V_320 = 0 ;
V_127 -> V_321 = 0 ;
#endif
#ifdef F_252
V_127 -> V_322 = NULL ;
#endif
#ifdef F_253
V_127 -> V_323 = 0 ;
V_127 -> V_324 = 0 ;
#endif
V_73 = F_254 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_325;
V_73 = F_255 ( V_127 ) ;
if ( V_73 )
goto V_325;
V_73 = F_256 ( V_127 ) ;
if ( V_73 )
goto V_326;
F_257 ( V_127 ) ;
V_73 = F_258 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_327;
V_73 = F_190 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_328;
V_73 = F_188 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_329;
V_73 = F_198 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_330;
V_73 = F_204 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_331;
V_73 = F_185 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_332;
V_73 = F_259 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_333;
V_73 = F_192 ( V_179 , V_127 ) ;
if ( V_73 )
goto V_334;
V_73 = F_260 ( V_179 , V_253 , V_254 , V_127 , V_257 ) ;
if ( V_73 )
goto V_335;
if ( V_251 != & V_336 ) {
V_251 = F_261 ( V_127 -> V_264 -> V_265 ) ;
if ( F_247 ( V_251 ) ) {
V_73 = F_248 ( V_251 ) ;
goto V_335;
}
}
V_127 -> V_337 = ( V_179 & V_338 ) ? V_255 : NULL ;
V_127 -> V_173 = ( V_179 & V_339 ) ? V_255 : NULL ;
#ifdef F_193
V_127 -> V_340 = NULL ;
#endif
#ifdef F_173
V_127 -> V_170 = NULL ;
#ifdef F_175
V_127 -> V_171 = NULL ;
#endif
F_79 ( & V_127 -> V_172 ) ;
V_127 -> V_341 = NULL ;
#endif
if ( ( V_179 & ( V_186 | V_342 ) ) == V_186 )
V_127 -> V_343 = V_127 -> V_344 = 0 ;
F_262 ( V_127 ) ;
F_263 ( V_127 , V_345 ) ;
#ifdef F_264
F_263 ( V_127 , F_264 ) ;
#endif
F_265 ( V_127 ) ;
V_127 -> V_251 = F_266 ( V_251 ) ;
if ( V_179 & V_219 ) {
V_127 -> V_346 = - 1 ;
V_127 -> V_236 = V_28 -> V_236 ;
V_127 -> V_347 = V_28 -> V_347 ;
} else {
if ( V_179 & V_261 )
V_127 -> V_346 = V_28 -> V_236 -> V_346 ;
else
V_127 -> V_346 = ( V_179 & V_348 ) ;
V_127 -> V_236 = V_127 ;
V_127 -> V_347 = V_127 -> V_251 ;
}
V_127 -> V_349 = 0 ;
V_127 -> V_350 = 128 >> ( V_351 - 10 ) ;
V_127 -> V_352 = 0 ;
V_127 -> V_353 = 0 ;
F_79 ( & V_127 -> V_354 ) ;
V_127 -> V_355 = NULL ;
V_73 = F_267 ( V_127 ) ;
if ( V_73 )
goto V_356;
F_268 ( & V_1 ) ;
if ( V_179 & ( V_261 | V_219 ) ) {
V_127 -> V_357 = V_28 -> V_357 ;
V_127 -> V_358 = V_28 -> V_358 ;
} else {
V_127 -> V_357 = V_28 ;
V_127 -> V_358 = V_28 -> V_359 ;
}
F_144 ( & V_28 -> V_208 -> V_241 ) ;
F_215 ( V_127 ) ;
F_269 () ;
if ( F_270 ( V_28 ) ) {
F_146 ( & V_28 -> V_208 -> V_241 ) ;
F_271 ( & V_1 ) ;
V_73 = - V_360 ;
goto V_361;
}
if ( F_165 ( V_127 -> V_251 ) ) {
F_272 ( V_127 , ( V_179 & V_362 ) || V_256 ) ;
F_225 ( V_127 , V_363 , V_251 ) ;
if ( F_273 ( V_127 ) ) {
F_225 ( V_127 , V_364 , F_274 ( V_28 ) ) ;
F_225 ( V_127 , V_365 , F_275 ( V_28 ) ) ;
if ( F_276 ( V_251 ) ) {
F_277 ( V_251 ) -> V_366 = V_127 ;
V_127 -> signal -> V_143 |= V_262 ;
}
V_127 -> signal -> V_367 = V_251 ;
V_127 -> signal -> V_368 = F_278 ( V_28 -> signal -> V_368 ) ;
F_279 ( & V_127 -> V_282 , & V_127 -> V_357 -> V_281 ) ;
F_280 ( & V_127 -> V_369 , & V_40 . V_369 ) ;
F_281 ( V_127 , V_364 ) ;
F_281 ( V_127 , V_365 ) ;
F_282 ( V_4 ) ;
} else {
V_28 -> signal -> V_220 ++ ;
F_86 ( & V_28 -> signal -> V_221 ) ;
F_86 ( & V_28 -> signal -> V_25 ) ;
F_280 ( & V_127 -> V_354 ,
& V_127 -> V_236 -> V_354 ) ;
F_280 ( & V_127 -> V_224 ,
& V_127 -> signal -> V_222 ) ;
}
F_281 ( V_127 , V_363 ) ;
V_220 ++ ;
}
V_370 ++ ;
F_146 ( & V_28 -> V_208 -> V_241 ) ;
F_283 ( V_127 ) ;
F_271 ( & V_1 ) ;
F_284 ( V_127 ) ;
F_285 ( V_127 ) ;
F_286 ( V_28 ) ;
F_287 ( V_127 ) ;
F_288 ( V_127 , V_179 ) ;
F_289 ( V_127 , V_179 ) ;
return V_127 ;
V_361:
F_290 ( V_127 ) ;
V_356:
if ( V_251 != & V_336 )
F_291 ( V_251 ) ;
V_335:
if ( V_127 -> V_200 )
F_292 ( V_127 ) ;
V_334:
F_293 ( V_127 ) ;
V_333:
if ( V_127 -> V_63 )
F_135 ( V_127 -> V_63 ) ;
V_332:
if ( ! ( V_179 & V_219 ) )
F_29 ( V_127 -> signal ) ;
V_331:
F_199 ( V_127 -> V_208 ) ;
V_330:
F_294 ( V_127 ) ;
V_329:
F_295 ( V_127 ) ;
V_328:
F_296 ( V_127 ) ;
V_327:
F_297 ( V_127 ) ;
V_326:
F_298 ( V_127 ) ;
V_325:
#ifdef F_245
F_99 ( V_127 -> V_301 ) ;
V_302:
#endif
F_286 ( V_28 ) ;
F_41 ( V_127 ) ;
V_277:
F_84 ( & V_127 -> V_371 -> V_270 -> V_271 ) ;
F_40 ( V_127 ) ;
V_275:
F_25 ( V_127 ) ;
V_266:
return F_161 ( V_73 ) ;
}
static inline void F_299 ( struct V_372 * V_373 )
{
enum V_250 type ;
for ( type = V_363 ; type < V_374 ; ++ type ) {
F_300 ( & V_373 [ type ] . V_7 ) ;
V_373 [ type ] . V_251 = & V_336 ;
}
}
struct V_5 * F_301 ( int V_2 )
{
struct V_5 * V_160 ;
V_160 = F_226 ( V_186 , 0 , 0 , NULL , & V_336 , 0 , 0 ) ;
if ( ! F_247 ( V_160 ) ) {
F_299 ( V_160 -> V_252 ) ;
F_302 ( V_160 , V_2 ) ;
}
return V_160 ;
}
long F_303 ( unsigned long V_179 ,
unsigned long V_253 ,
unsigned long V_254 ,
int T_3 * V_375 ,
int T_3 * V_255 ,
unsigned long V_257 )
{
struct V_5 * V_127 ;
int V_256 = 0 ;
long V_376 ;
if ( ! ( V_179 & V_377 ) ) {
if ( V_179 & V_342 )
V_256 = V_378 ;
else if ( ( V_179 & V_348 ) != V_379 )
V_256 = V_380 ;
else
V_256 = V_381 ;
if ( F_165 ( ! F_304 ( V_28 , V_256 ) ) )
V_256 = 0 ;
}
V_127 = F_226 ( V_179 , V_253 , V_254 ,
V_255 , NULL , V_256 , V_257 ) ;
if ( ! F_247 ( V_127 ) ) {
struct V_165 V_166 ;
struct V_251 * V_251 ;
F_305 ( V_28 , V_127 ) ;
V_251 = F_306 ( V_127 , V_363 ) ;
V_376 = F_307 ( V_251 ) ;
if ( V_179 & V_382 )
F_180 ( V_376 , V_375 ) ;
if ( V_179 & V_342 ) {
V_127 -> V_167 = & V_166 ;
F_308 ( & V_166 ) ;
F_309 ( V_127 ) ;
}
F_310 ( V_127 ) ;
if ( F_104 ( V_256 ) )
F_311 ( V_256 , V_251 ) ;
if ( V_179 & V_342 ) {
if ( ! F_167 ( V_127 , & V_166 ) )
F_311 ( V_383 , V_251 ) ;
}
F_312 ( V_251 ) ;
} else {
V_376 = F_248 ( V_127 ) ;
}
return V_376 ;
}
long F_313 ( unsigned long V_179 ,
unsigned long V_253 ,
unsigned long V_254 ,
int T_3 * V_375 ,
int T_3 * V_255 )
{
return F_303 ( V_179 , V_253 , V_254 ,
V_375 , V_255 , 0 ) ;
}
T_4 F_314 ( int (* F_315)( void * ) , void * V_384 , unsigned long V_143 )
{
return F_303 ( V_143 | V_186 | V_377 , ( unsigned long ) F_315 ,
( unsigned long ) V_384 , NULL , NULL , 0 ) ;
}
static void F_316 ( void * V_385 )
{
struct V_206 * V_208 = V_385 ;
F_111 ( & V_208 -> V_241 ) ;
F_207 ( & V_208 -> V_386 ) ;
}
void T_1 F_317 ( void )
{
V_209 = F_20 ( L_7 ,
sizeof( struct V_206 ) , 0 ,
V_387 | V_37 | V_388 |
V_38 | V_39 , F_316 ) ;
V_24 = F_20 ( L_8 ,
sizeof( struct V_22 ) , 0 ,
V_387 | V_37 | V_38 | V_39 ,
NULL ) ;
V_389 = F_20 ( L_9 ,
sizeof( struct V_195 ) , 0 ,
V_387 | V_37 | V_38 | V_39 ,
NULL ) ;
V_390 = F_20 ( L_10 ,
sizeof( struct V_188 ) , 0 ,
V_387 | V_37 | V_38 | V_39 ,
NULL ) ;
V_391 = F_20 ( L_11 ,
sizeof( struct V_62 ) , V_392 ,
V_387 | V_37 | V_38 | V_39 ,
NULL ) ;
V_92 = F_318 ( V_65 , V_37 | V_39 ) ;
F_319 () ;
F_320 () ;
}
static int F_321 ( unsigned long V_393 )
{
if ( V_393 & ~ ( V_219 | V_190 | V_258 | V_207 |
V_186 | V_199 | V_394 |
V_395 | V_396 | V_397 |
V_260 | V_263 | V_398 ) )
return - V_259 ;
if ( V_393 & ( V_219 | V_207 | V_186 ) ) {
if ( ! F_322 ( V_28 ) )
return - V_259 ;
}
if ( V_393 & ( V_207 | V_186 ) ) {
if ( F_36 ( & V_28 -> V_208 -> V_152 ) > 1 )
return - V_259 ;
}
if ( V_393 & V_186 ) {
if ( ! F_323 () )
return - V_259 ;
}
return 0 ;
}
static int F_324 ( unsigned long V_393 , struct V_188 * * V_399 )
{
struct V_188 * V_189 = V_28 -> V_189 ;
if ( ! ( V_393 & V_190 ) || ! V_189 )
return 0 ;
if ( V_189 -> V_194 == 1 )
return 0 ;
* V_399 = F_189 ( V_189 ) ;
if ( ! * V_399 )
return - V_119 ;
return 0 ;
}
static int F_325 ( unsigned long V_393 , struct V_195 * * V_400 )
{
struct V_195 * V_401 = V_28 -> V_198 ;
int error = 0 ;
if ( ( V_393 & V_199 ) &&
( V_401 && F_36 ( & V_401 -> V_152 ) > 1 ) ) {
* V_400 = F_191 ( V_401 , & error ) ;
if ( ! * V_400 )
return error ;
}
return 0 ;
}
int F_326 ( struct V_195 * * V_402 )
{
struct V_5 * V_160 = V_28 ;
struct V_195 * V_403 = NULL ;
int error ;
error = F_325 ( V_199 , & V_403 ) ;
if ( error || ! V_403 ) {
* V_402 = NULL ;
return error ;
}
* V_402 = V_160 -> V_198 ;
F_157 ( V_160 ) ;
V_160 -> V_198 = V_403 ;
F_158 ( V_160 ) ;
return 0 ;
}
int F_327 ( struct V_404 * V_405 , int V_406 ,
void T_3 * V_407 , T_5 * V_408 , T_6 * V_409 )
{
struct V_404 V_410 ;
int V_411 ;
int V_30 = V_34 ;
int V_412 = V_35 ;
int V_413 = V_33 ;
V_410 = * V_405 ;
V_410 . V_385 = & V_30 ;
V_410 . V_414 = & V_412 ;
V_410 . V_415 = & V_413 ;
V_411 = F_328 ( & V_410 , V_406 , V_407 , V_408 , V_409 ) ;
if ( V_411 || ! V_406 )
return V_411 ;
F_44 ( V_30 ) ;
return 0 ;
}
