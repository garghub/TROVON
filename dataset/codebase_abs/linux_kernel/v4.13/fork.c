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
static int F_12 ( unsigned int V_2 )
{
struct V_11 * * V_12 = F_13 ( V_13 , V_2 ) ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
struct V_11 * V_16 = V_12 [ V_14 ] ;
if ( ! V_16 )
continue;
F_14 ( V_16 -> V_17 ) ;
V_12 [ V_14 ] = NULL ;
}
return 0 ;
}
static unsigned long * F_15 ( struct V_5 * V_6 , int V_7 )
{
#ifdef F_16
void * V_10 ;
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
struct V_11 * V_18 ;
V_18 = F_17 ( V_13 [ V_14 ] , NULL ) ;
if ( ! V_18 )
continue;
V_6 -> V_19 = V_18 ;
return V_18 -> V_17 ;
}
V_10 = F_18 ( V_20 , V_20 ,
V_21 , V_22 ,
V_23 ,
V_24 ,
0 , V_7 , F_19 ( 0 ) ) ;
if ( V_10 )
V_6 -> V_19 = F_20 ( V_10 ) ;
return V_10 ;
#else
struct V_25 * V_25 = F_21 ( V_7 , V_23 ,
V_26 ) ;
return V_25 ? F_22 ( V_25 ) : NULL ;
#endif
}
static inline void F_23 ( struct V_5 * V_6 )
{
#ifdef F_16
if ( F_24 ( V_6 ) ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( F_25 ( V_13 [ V_14 ] ,
NULL , V_6 -> V_19 ) != NULL )
continue;
return;
}
F_26 ( V_6 -> V_10 ) ;
return;
}
#endif
F_27 ( F_28 ( V_6 -> V_10 ) , V_26 ) ;
}
static unsigned long * F_15 ( struct V_5 * V_6 ,
int V_7 )
{
return F_8 ( V_27 , V_23 , V_7 ) ;
}
static void F_23 ( struct V_5 * V_6 )
{
F_10 ( V_27 , V_6 -> V_10 ) ;
}
void F_29 ( void )
{
V_27 = F_30 ( L_1 , V_20 ,
V_20 , 0 , NULL ) ;
F_31 ( V_27 == NULL ) ;
}
static void F_32 ( struct V_5 * V_6 , int V_28 )
{
void * V_10 = F_33 ( V_6 ) ;
struct V_11 * V_29 = F_24 ( V_6 ) ;
F_34 ( F_35 ( F_16 ) && V_30 % 1024 != 0 ) ;
if ( V_29 ) {
int V_14 ;
F_31 ( V_29 -> V_31 != V_20 / V_30 ) ;
for ( V_14 = 0 ; V_14 < V_20 / V_30 ; V_14 ++ ) {
F_36 ( F_37 ( V_29 -> V_32 [ V_14 ] ) ,
V_33 ,
V_30 / 1024 * V_28 ) ;
}
F_38 ( V_29 -> V_32 [ 0 ] , V_34 ,
V_28 * ( V_20 / 1024 ) ) ;
} else {
struct V_25 * V_35 = F_28 ( V_10 ) ;
F_36 ( F_37 ( V_35 ) , V_33 ,
V_20 / 1024 * V_28 ) ;
F_38 ( V_35 , V_34 ,
V_28 * ( V_20 / 1024 ) ) ;
}
}
static void F_39 ( struct V_5 * V_6 )
{
if ( F_40 ( V_6 -> V_36 != V_37 ) )
return;
F_32 ( V_6 , - 1 ) ;
F_11 ( V_6 -> V_10 ) ;
F_23 ( V_6 ) ;
V_6 -> V_10 = NULL ;
#ifdef F_16
V_6 -> V_19 = NULL ;
#endif
}
void F_41 ( struct V_5 * V_6 )
{
if ( F_42 ( & V_6 -> V_38 ) )
F_39 ( V_6 ) ;
}
void F_43 ( struct V_5 * V_6 )
{
#ifndef F_44
F_39 ( V_6 ) ;
#else
F_45 ( F_46 ( & V_6 -> V_38 ) != 0 ) ;
#endif
F_47 ( V_6 ) ;
F_48 ( V_6 ) ;
F_49 ( V_6 ) ;
F_6 ( V_6 ) ;
if ( V_6 -> V_39 & V_40 )
F_50 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_51 ( struct V_41 * V_42 )
{
F_52 ( V_42 ) ;
F_53 ( V_42 ) ;
if ( V_42 -> V_43 )
F_54 ( V_42 -> V_43 ) ;
F_10 ( V_44 , V_42 ) ;
}
static inline void F_55 ( struct V_41 * V_42 )
{
if ( F_42 ( & V_42 -> V_45 ) )
F_51 ( V_42 ) ;
}
void F_56 ( struct V_5 * V_6 )
{
F_40 ( ! V_6 -> V_46 ) ;
F_40 ( F_46 ( & V_6 -> V_47 ) ) ;
F_40 ( V_6 == V_48 ) ;
F_57 ( V_6 ) ;
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 ) ;
F_55 ( V_6 -> signal ) ;
if ( ! F_62 ( V_6 ) )
F_43 ( V_6 ) ;
}
void T_1 __weak F_63 ( void ) { }
static void F_64 ( unsigned int V_49 )
{
T_2 V_50 ;
if ( F_65 ( V_51 ) + F_65 ( V_30 ) > 64 )
V_50 = V_52 ;
else
V_50 = F_66 ( ( T_2 ) V_51 * ( T_2 ) V_30 ,
( T_2 ) V_20 * 8UL ) ;
if ( V_50 > V_49 )
V_50 = V_49 ;
V_53 = F_67 ( T_2 , V_50 , V_54 , V_52 ) ;
}
void T_1 F_68 ( void )
{
int V_14 ;
#ifndef F_69
#ifndef F_70
#define F_70 0
#endif
int V_55 = F_71 ( int , V_56 , F_70 ) ;
V_8 = F_30 ( L_2 ,
V_57 , V_55 ,
V_58 | V_59 | V_60 , NULL ) ;
#endif
F_63 () ;
F_64 ( V_52 ) ;
V_61 . signal -> V_62 [ V_63 ] . V_64 = V_53 / 2 ;
V_61 . signal -> V_62 [ V_63 ] . V_65 = V_53 / 2 ;
V_61 . signal -> V_62 [ V_66 ] =
V_61 . signal -> V_62 [ V_63 ] ;
for ( V_14 = 0 ; V_14 < V_67 ; V_14 ++ ) {
V_68 . V_69 [ V_14 ] = V_53 / 2 ;
}
#ifdef F_16
F_72 ( V_70 , L_3 ,
NULL , F_12 ) ;
#endif
}
int __weak F_73 ( struct V_5 * V_71 ,
struct V_5 * V_72 )
{
* V_71 = * V_72 ;
return 0 ;
}
void F_74 ( struct V_5 * V_6 )
{
unsigned long * V_73 ;
V_73 = F_75 ( V_6 ) ;
* V_73 = V_74 ;
}
static struct V_5 * F_76 ( struct V_5 * V_75 , int V_7 )
{
struct V_5 * V_6 ;
unsigned long * V_10 ;
struct V_11 * V_19 ;
int V_76 ;
if ( V_7 == V_77 )
V_7 = F_77 ( V_75 ) ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_10 = F_15 ( V_6 , V_7 ) ;
if ( ! V_10 )
goto V_78;
V_19 = F_24 ( V_6 ) ;
V_76 = F_73 ( V_6 , V_75 ) ;
V_6 -> V_10 = V_10 ;
#ifdef F_16
V_6 -> V_19 = V_19 ;
#endif
#ifdef F_44
F_78 ( & V_6 -> V_38 , 1 ) ;
#endif
if ( V_76 )
goto V_79;
#ifdef F_79
V_6 -> V_80 . V_81 = NULL ;
#endif
F_80 ( V_6 , V_75 ) ;
F_81 ( V_6 ) ;
F_82 ( V_6 ) ;
F_74 ( V_6 ) ;
#ifdef F_83
V_6 -> V_82 = F_84 () ;
#endif
F_78 ( & V_6 -> V_47 , 2 ) ;
#ifdef F_85
V_6 -> V_83 = 0 ;
#endif
V_6 -> V_84 = NULL ;
V_6 -> V_85 . V_25 = NULL ;
V_6 -> V_86 . V_87 = NULL ;
F_32 ( V_6 , 1 ) ;
F_86 ( V_6 ) ;
#ifdef F_87
V_6 -> V_88 = 0 ;
#endif
return V_6 ;
V_79:
F_23 ( V_6 ) ;
V_78:
F_9 ( V_6 ) ;
return NULL ;
}
static T_3 int F_88 ( struct V_89 * V_90 ,
struct V_89 * V_91 )
{
struct V_92 * V_93 , * V_94 , * V_95 , * * V_96 ;
struct V_97 * * V_98 , * V_99 ;
int V_100 ;
unsigned long V_101 ;
F_89 ( V_102 ) ;
F_90 () ;
if ( F_91 ( & V_91 -> V_103 ) ) {
V_100 = - V_104 ;
goto V_105;
}
F_92 ( V_91 ) ;
F_93 ( V_91 , V_90 ) ;
F_94 ( & V_90 -> V_103 , V_106 ) ;
F_95 ( V_90 -> V_107 , F_96 ( V_91 ) ) ;
V_90 -> V_108 = V_91 -> V_108 ;
V_90 -> V_109 = V_91 -> V_109 ;
V_90 -> V_110 = V_91 -> V_110 ;
V_90 -> V_111 = V_91 -> V_111 ;
V_98 = & V_90 -> V_112 . V_97 ;
V_99 = NULL ;
V_96 = & V_90 -> V_113 ;
V_100 = F_97 ( V_90 , V_91 ) ;
if ( V_100 )
goto V_114;
V_100 = F_98 ( V_90 , V_91 ) ;
if ( V_100 )
goto V_114;
V_95 = NULL ;
for ( V_93 = V_91 -> V_113 ; V_93 ; V_93 = V_93 -> V_115 ) {
struct V_116 * V_116 ;
if ( V_93 -> V_117 & V_118 ) {
F_99 ( V_90 , V_93 -> V_117 , - F_100 ( V_93 ) ) ;
continue;
}
V_101 = 0 ;
if ( V_93 -> V_117 & V_119 ) {
unsigned long V_120 = F_100 ( V_93 ) ;
if ( F_101 ( V_91 , V_120 ) )
goto V_121;
V_101 = V_120 ;
}
V_94 = F_102 ( V_122 , V_9 ) ;
if ( ! V_94 )
goto V_121;
* V_94 = * V_93 ;
F_103 ( & V_94 -> V_123 ) ;
V_100 = F_104 ( V_93 , V_94 ) ;
if ( V_100 )
goto V_124;
V_94 -> V_125 = V_90 ;
V_100 = F_105 ( V_94 , & V_102 ) ;
if ( V_100 )
goto V_126;
if ( F_106 ( V_94 , V_93 ) )
goto V_126;
V_94 -> V_117 &= ~ ( V_127 | V_128 ) ;
V_94 -> V_115 = V_94 -> V_129 = NULL ;
V_116 = V_94 -> V_130 ;
if ( V_116 ) {
struct V_131 * V_131 = F_107 ( V_116 ) ;
struct V_132 * V_133 = V_116 -> V_134 ;
F_108 ( V_116 ) ;
if ( V_94 -> V_117 & V_135 )
F_109 ( & V_131 -> V_136 ) ;
F_110 ( V_133 ) ;
if ( V_94 -> V_117 & V_137 )
F_111 ( & V_133 -> V_138 ) ;
F_112 ( V_133 ) ;
F_113 ( V_94 , V_93 ,
& V_133 -> V_139 ) ;
F_114 ( V_133 ) ;
F_115 ( V_133 ) ;
}
if ( F_116 ( V_94 ) )
F_117 ( V_94 ) ;
* V_96 = V_94 ;
V_96 = & V_94 -> V_115 ;
V_94 -> V_129 = V_95 ;
V_95 = V_94 ;
F_118 ( V_90 , V_94 , V_98 , V_99 ) ;
V_98 = & V_94 -> V_140 . V_141 ;
V_99 = & V_94 -> V_140 ;
V_90 -> V_142 ++ ;
V_100 = F_119 ( V_90 , V_91 , V_93 ) ;
if ( V_94 -> V_143 && V_94 -> V_143 -> V_144 )
V_94 -> V_143 -> V_144 ( V_94 ) ;
if ( V_100 )
goto V_114;
}
F_120 ( V_91 , V_90 ) ;
V_100 = 0 ;
V_114:
F_121 ( & V_90 -> V_103 ) ;
F_122 ( V_91 ) ;
F_121 ( & V_91 -> V_103 ) ;
F_123 ( & V_102 ) ;
V_105:
F_124 () ;
return V_100 ;
V_126:
F_125 ( F_126 ( V_94 ) ) ;
V_124:
F_10 ( V_122 , V_94 ) ;
V_121:
V_100 = - V_145 ;
F_127 ( V_101 ) ;
goto V_114;
}
static inline int F_128 ( struct V_89 * V_90 )
{
V_90 -> V_146 = F_129 ( V_90 ) ;
if ( F_130 ( ! V_90 -> V_146 ) )
return - V_145 ;
return 0 ;
}
static inline void F_131 ( struct V_89 * V_90 )
{
F_132 ( V_90 , V_90 -> V_146 ) ;
}
static int F_88 ( struct V_89 * V_90 , struct V_89 * V_91 )
{
F_133 ( & V_91 -> V_103 ) ;
F_95 ( V_90 -> V_107 , F_96 ( V_91 ) ) ;
F_121 ( & V_91 -> V_103 ) ;
return 0 ;
}
static int T_1 F_134 ( char * V_18 )
{
V_147 =
( F_135 ( V_18 , NULL , 0 ) << V_148 ) &
V_149 ;
return 1 ;
}
static void F_136 ( struct V_89 * V_90 )
{
#ifdef F_137
F_138 ( & V_90 -> V_150 ) ;
V_90 -> V_151 = NULL ;
#endif
}
static void F_139 ( struct V_89 * V_90 , struct V_5 * V_152 )
{
#ifdef F_140
V_90 -> V_153 = V_152 ;
#endif
}
static void F_141 ( struct V_89 * V_90 )
{
#ifdef F_142
V_90 -> V_154 . V_155 = NULL ;
#endif
}
static struct V_89 * F_143 ( struct V_89 * V_90 , struct V_5 * V_152 ,
struct V_156 * V_157 )
{
V_90 -> V_113 = NULL ;
V_90 -> V_112 = V_158 ;
V_90 -> V_159 = 0 ;
F_78 ( & V_90 -> V_160 , 1 ) ;
F_78 ( & V_90 -> V_161 , 1 ) ;
F_144 ( & V_90 -> V_103 ) ;
F_103 ( & V_90 -> V_162 ) ;
V_90 -> V_163 = NULL ;
F_145 ( & V_90 -> V_164 , 0 ) ;
F_146 ( V_90 ) ;
V_90 -> V_142 = 0 ;
V_90 -> V_165 = 0 ;
V_90 -> V_166 = 0 ;
memset ( & V_90 -> V_167 , 0 , sizeof( V_90 -> V_167 ) ) ;
F_138 ( & V_90 -> V_168 ) ;
F_147 ( V_90 ) ;
F_136 ( V_90 ) ;
F_139 ( V_90 , V_152 ) ;
F_95 ( V_90 -> V_107 , NULL ) ;
F_148 ( V_90 ) ;
F_149 ( V_90 ) ;
#if F_150 ( V_169 ) && ! V_170
V_90 -> V_171 = NULL ;
#endif
F_141 ( V_90 ) ;
if ( V_48 -> V_90 ) {
V_90 -> V_39 = V_48 -> V_90 -> V_39 & V_172 ;
V_90 -> V_173 = V_48 -> V_90 -> V_173 & V_174 ;
} else {
V_90 -> V_39 = V_147 ;
V_90 -> V_173 = 0 ;
}
if ( F_128 ( V_90 ) )
goto V_175;
if ( F_151 ( V_152 , V_90 ) )
goto V_176;
V_90 -> V_157 = F_152 ( V_157 ) ;
return V_90 ;
V_176:
F_131 ( V_90 ) ;
V_175:
F_153 ( V_90 ) ;
return NULL ;
}
static void F_154 ( struct V_89 * V_90 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_177 ; V_14 ++ ) {
long V_178 = F_155 ( & V_90 -> V_167 . V_179 [ V_14 ] ) ;
if ( F_130 ( V_178 ) )
F_156 ( V_180 L_4
L_5 , V_90 , V_14 , V_178 ) ;
}
if ( F_155 ( & V_90 -> V_164 ) )
F_157 ( L_6 ,
F_155 ( & V_90 -> V_164 ) ) ;
if ( F_158 ( V_90 ) )
F_157 ( L_7 ,
F_158 ( V_90 ) ) ;
#if F_150 ( V_169 ) && ! V_170
F_159 ( V_90 -> V_171 , V_90 ) ;
#endif
}
struct V_89 * F_160 ( void )
{
struct V_89 * V_90 ;
V_90 = F_161 () ;
if ( ! V_90 )
return NULL ;
memset ( V_90 , 0 , sizeof( * V_90 ) ) ;
return F_143 ( V_90 , V_48 , F_162 () ) ;
}
void F_163 ( struct V_89 * V_90 )
{
F_31 ( V_90 == & V_181 ) ;
F_131 ( V_90 ) ;
F_164 ( V_90 ) ;
F_165 ( V_90 ) ;
F_154 ( V_90 ) ;
F_166 ( V_90 -> V_157 ) ;
F_153 ( V_90 ) ;
}
static inline void F_167 ( struct V_89 * V_90 )
{
F_168 ( F_46 ( & V_90 -> V_160 ) ) ;
F_169 ( V_90 ) ;
F_170 ( V_90 ) ;
F_171 ( V_90 ) ;
F_172 ( V_90 ) ;
F_173 ( V_90 ) ;
F_174 ( V_90 ) ;
F_175 ( V_90 , NULL ) ;
if ( ! F_176 ( & V_90 -> V_162 ) ) {
F_177 ( & V_182 ) ;
F_178 ( & V_90 -> V_162 ) ;
F_179 ( & V_182 ) ;
}
if ( V_90 -> V_183 )
F_180 ( V_90 -> V_183 -> V_184 ) ;
F_181 ( V_185 , & V_90 -> V_39 ) ;
F_182 ( V_90 ) ;
}
void F_183 ( struct V_89 * V_90 )
{
F_184 () ;
if ( F_42 ( & V_90 -> V_160 ) )
F_167 ( V_90 ) ;
}
static void F_185 ( struct V_186 * V_187 )
{
struct V_89 * V_90 = F_186 ( V_187 , struct V_89 , V_188 ) ;
F_167 ( V_90 ) ;
}
void F_187 ( struct V_89 * V_90 )
{
if ( F_42 ( & V_90 -> V_160 ) ) {
F_188 ( & V_90 -> V_188 , F_185 ) ;
F_189 ( & V_90 -> V_188 ) ;
}
}
void F_175 ( struct V_89 * V_90 , struct V_116 * V_189 )
{
struct V_116 * V_190 ;
V_190 = F_190 ( V_90 -> V_107 ) ;
if ( V_189 )
F_108 ( V_189 ) ;
F_191 ( V_90 -> V_107 , V_189 ) ;
if ( V_190 )
F_192 ( V_190 ) ;
}
struct V_116 * F_96 ( struct V_89 * V_90 )
{
struct V_116 * V_107 ;
F_193 () ;
V_107 = F_194 ( V_90 -> V_107 ) ;
if ( V_107 && ! F_195 ( V_107 ) )
V_107 = NULL ;
F_196 () ;
return V_107 ;
}
struct V_116 * F_197 ( struct V_5 * V_191 )
{
struct V_116 * V_107 = NULL ;
struct V_89 * V_90 ;
F_198 ( V_191 ) ;
V_90 = V_191 -> V_90 ;
if ( V_90 ) {
if ( ! ( V_191 -> V_39 & V_40 ) )
V_107 = F_96 ( V_90 ) ;
}
F_199 ( V_191 ) ;
return V_107 ;
}
struct V_89 * F_200 ( struct V_5 * V_191 )
{
struct V_89 * V_90 ;
F_198 ( V_191 ) ;
V_90 = V_191 -> V_90 ;
if ( V_90 ) {
if ( V_191 -> V_39 & V_40 )
V_90 = NULL ;
else
F_201 ( V_90 ) ;
}
F_199 ( V_191 ) ;
return V_90 ;
}
struct V_89 * F_202 ( struct V_5 * V_191 , unsigned int V_192 )
{
struct V_89 * V_90 ;
int V_76 ;
V_76 = F_203 ( & V_191 -> signal -> V_193 ) ;
if ( V_76 )
return F_204 ( V_76 ) ;
V_90 = F_200 ( V_191 ) ;
if ( V_90 && V_90 != V_48 -> V_90 &&
! F_205 ( V_191 , V_192 ) ) {
F_183 ( V_90 ) ;
V_90 = F_204 ( - V_194 ) ;
}
F_206 ( & V_191 -> signal -> V_193 ) ;
return V_90 ;
}
static void F_207 ( struct V_5 * V_6 )
{
struct V_195 * V_196 ;
F_198 ( V_6 ) ;
V_196 = V_6 -> V_197 ;
if ( F_208 ( V_196 ) ) {
V_6 -> V_197 = NULL ;
F_209 ( V_196 ) ;
}
F_199 ( V_6 ) ;
}
static int F_210 ( struct V_5 * V_198 ,
struct V_195 * V_196 )
{
int V_199 ;
F_211 () ;
V_199 = F_212 ( V_196 ) ;
F_213 () ;
if ( V_199 ) {
F_198 ( V_198 ) ;
V_198 -> V_197 = NULL ;
F_199 ( V_198 ) ;
}
F_214 ( V_198 ) ;
return V_199 ;
}
void F_215 ( struct V_5 * V_6 , struct V_89 * V_90 )
{
#ifdef F_216
if ( F_130 ( V_6 -> V_200 ) ) {
F_217 ( V_6 ) ;
V_6 -> V_200 = NULL ;
}
#ifdef F_218
if ( F_130 ( V_6 -> V_201 ) ) {
F_219 ( V_6 ) ;
V_6 -> V_201 = NULL ;
}
#endif
if ( F_130 ( ! F_176 ( & V_6 -> V_202 ) ) )
F_220 ( V_6 ) ;
#endif
F_221 ( V_6 ) ;
F_222 ( V_6 , V_90 ) ;
if ( V_6 -> V_203 ) {
if ( ! ( V_6 -> signal -> V_39 & V_204 ) &&
F_46 ( & V_90 -> V_160 ) > 1 ) {
F_223 ( 0 , V_6 -> V_203 ) ;
F_224 ( V_6 -> V_203 , V_205 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_203 = NULL ;
}
if ( V_6 -> V_197 )
F_207 ( V_6 ) ;
}
static struct V_89 * F_225 ( struct V_5 * V_6 )
{
struct V_89 * V_90 , * V_91 = V_48 -> V_90 ;
int V_76 ;
V_90 = F_161 () ;
if ( ! V_90 )
goto V_121;
memcpy ( V_90 , V_91 , sizeof( * V_90 ) ) ;
if ( ! F_143 ( V_90 , V_6 , V_90 -> V_157 ) )
goto V_121;
V_76 = F_88 ( V_90 , V_91 ) ;
if ( V_76 )
goto V_206;
V_90 -> V_207 = F_226 ( V_90 ) ;
V_90 -> V_208 = V_90 -> V_108 ;
if ( V_90 -> V_183 && ! F_227 ( V_90 -> V_183 -> V_184 ) )
goto V_206;
return V_90 ;
V_206:
V_90 -> V_183 = NULL ;
F_183 ( V_90 ) ;
V_121:
return NULL ;
}
static int F_228 ( unsigned long V_209 , struct V_5 * V_6 )
{
struct V_89 * V_90 , * V_91 ;
int V_100 ;
V_6 -> V_210 = V_6 -> V_211 = 0 ;
V_6 -> V_212 = V_6 -> V_213 = 0 ;
#ifdef F_229
V_6 -> V_214 = V_6 -> V_212 + V_6 -> V_213 ;
#endif
V_6 -> V_90 = NULL ;
V_6 -> V_215 = NULL ;
V_91 = V_48 -> V_90 ;
if ( ! V_91 )
return 0 ;
F_230 ( V_6 ) ;
if ( V_209 & V_216 ) {
F_201 ( V_91 ) ;
V_90 = V_91 ;
goto V_217;
}
V_100 = - V_145 ;
V_90 = F_225 ( V_6 ) ;
if ( ! V_90 )
goto V_121;
V_217:
V_6 -> V_90 = V_90 ;
V_6 -> V_215 = V_90 ;
return 0 ;
V_121:
return V_100 ;
}
static int F_231 ( unsigned long V_209 , struct V_5 * V_6 )
{
struct V_218 * V_219 = V_48 -> V_219 ;
if ( V_209 & V_220 ) {
F_177 ( & V_219 -> V_221 ) ;
if ( V_219 -> V_222 ) {
F_179 ( & V_219 -> V_221 ) ;
return - V_223 ;
}
V_219 -> V_224 ++ ;
F_179 ( & V_219 -> V_221 ) ;
return 0 ;
}
V_6 -> V_219 = F_232 ( V_219 ) ;
if ( ! V_6 -> V_219 )
return - V_145 ;
return 0 ;
}
static int F_233 ( unsigned long V_209 , struct V_5 * V_6 )
{
struct V_225 * V_226 , * V_227 ;
int error = 0 ;
V_226 = V_48 -> V_228 ;
if ( ! V_226 )
goto V_114;
if ( V_209 & V_229 ) {
F_111 ( & V_226 -> V_179 ) ;
goto V_114;
}
V_227 = F_234 ( V_226 , & error ) ;
if ( ! V_227 )
goto V_114;
V_6 -> V_228 = V_227 ;
error = 0 ;
V_114:
return error ;
}
static int F_235 ( unsigned long V_209 , struct V_5 * V_6 )
{
#ifdef F_236
struct V_230 * V_231 = V_48 -> V_230 ;
struct V_230 * V_232 ;
if ( ! V_231 )
return 0 ;
if ( V_209 & V_233 ) {
F_237 ( V_231 ) ;
V_6 -> V_230 = V_231 ;
} else if ( F_238 ( V_231 -> V_234 ) ) {
V_232 = F_239 ( V_6 , V_9 , V_77 ) ;
if ( F_130 ( ! V_232 ) )
return - V_145 ;
V_232 -> V_234 = V_231 -> V_234 ;
F_240 ( V_232 ) ;
}
#endif
return 0 ;
}
static int F_241 ( unsigned long V_209 , struct V_5 * V_6 )
{
struct V_235 * V_42 ;
if ( V_209 & V_236 ) {
F_111 ( & V_48 -> V_237 -> V_179 ) ;
return 0 ;
}
V_42 = F_102 ( V_238 , V_9 ) ;
F_191 ( V_6 -> V_237 , V_42 ) ;
if ( ! V_42 )
return - V_145 ;
F_78 ( & V_42 -> V_179 , 1 ) ;
memcpy ( V_42 -> V_239 , V_48 -> V_237 -> V_239 , sizeof( V_42 -> V_239 ) ) ;
return 0 ;
}
void F_242 ( struct V_235 * V_237 )
{
if ( F_42 ( & V_237 -> V_179 ) ) {
F_243 ( V_237 ) ;
F_10 ( V_238 , V_237 ) ;
}
}
static void F_244 ( struct V_41 * V_42 )
{
unsigned long V_240 ;
V_240 = F_245 ( V_42 -> V_62 [ V_241 ] . V_64 ) ;
if ( V_240 != V_242 ) {
V_42 -> V_243 . V_244 = V_240 * V_245 ;
V_42 -> V_246 . V_247 = true ;
}
F_103 ( & V_42 -> V_248 [ 0 ] ) ;
F_103 ( & V_42 -> V_248 [ 1 ] ) ;
F_103 ( & V_42 -> V_248 [ 2 ] ) ;
}
static inline void F_244 ( struct V_41 * V_42 ) { }
static int F_246 ( unsigned long V_209 , struct V_5 * V_6 )
{
struct V_41 * V_42 ;
if ( V_209 & V_249 )
return 0 ;
V_42 = F_247 ( V_44 , V_9 ) ;
V_6 -> signal = V_42 ;
if ( ! V_42 )
return - V_145 ;
V_42 -> V_250 = 1 ;
F_78 ( & V_42 -> V_251 , 1 ) ;
F_78 ( & V_42 -> V_45 , 1 ) ;
V_42 -> V_252 = (struct V_253 ) F_248 ( V_6 -> V_254 ) ;
V_6 -> V_254 = (struct V_253 ) F_248 ( V_42 -> V_252 ) ;
F_249 ( & V_42 -> V_255 ) ;
V_42 -> V_256 = V_6 ;
F_250 ( & V_42 -> V_257 ) ;
F_251 ( & V_42 -> V_258 ) ;
F_252 ( & V_42 -> V_259 ) ;
#ifdef F_253
F_103 ( & V_42 -> V_260 ) ;
F_254 ( & V_42 -> V_261 , V_262 , V_263 ) ;
V_42 -> V_261 . V_264 = V_265 ;
#endif
F_198 ( V_48 -> V_266 ) ;
memcpy ( V_42 -> V_62 , V_48 -> signal -> V_62 , sizeof V_42 -> V_62 ) ;
F_199 ( V_48 -> V_266 ) ;
F_244 ( V_42 ) ;
F_255 ( V_42 ) ;
F_256 ( V_42 ) ;
V_42 -> V_267 = V_48 -> signal -> V_267 ;
V_42 -> V_268 = V_48 -> signal -> V_268 ;
F_257 ( & V_42 -> V_193 ) ;
return 0 ;
}
static void F_258 ( struct V_5 * V_152 )
{
#ifdef F_79
F_259 ( & V_48 -> V_237 -> V_269 ) ;
F_260 ( V_48 ) ;
V_152 -> V_80 = V_48 -> V_80 ;
if ( F_261 ( V_48 ) )
F_262 ( V_152 ) ;
if ( V_152 -> V_80 . V_192 != V_270 )
F_263 ( V_152 , V_271 ) ;
#endif
}
static void F_264 ( struct V_5 * V_152 )
{
F_265 ( & V_152 -> V_272 ) ;
#ifdef F_266
V_152 -> V_273 = V_158 ;
V_152 -> V_274 = NULL ;
V_152 -> V_275 = NULL ;
V_152 -> V_276 = NULL ;
#endif
}
static void F_267 ( struct V_5 * V_6 )
{
V_6 -> V_243 . V_244 = 0 ;
V_6 -> V_243 . V_277 = 0 ;
V_6 -> V_243 . V_278 = 0 ;
F_103 ( & V_6 -> V_248 [ 0 ] ) ;
F_103 ( & V_6 -> V_248 [ 1 ] ) ;
F_103 ( & V_6 -> V_248 [ 2 ] ) ;
}
static inline void F_267 ( struct V_5 * V_6 ) { }
static inline void
F_268 ( struct V_5 * V_191 , enum V_279 type , struct V_280 * V_280 )
{
V_191 -> V_281 [ type ] . V_280 = V_280 ;
}
static inline void F_269 ( struct V_5 * V_152 )
{
#ifdef F_270
V_152 -> V_282 = 0 ;
V_152 -> V_283 . V_18 = 0 ;
V_152 -> V_284 = NULL ;
F_103 ( & V_152 -> V_285 ) ;
#endif
#ifdef F_271
V_152 -> V_286 = false ;
F_103 ( & V_152 -> V_287 ) ;
V_152 -> V_288 = - 1 ;
#endif
}
inline void F_272 ( struct V_289 * V_290 )
{
enum V_279 type ;
for ( type = V_291 ; type < V_292 ; ++ type ) {
F_273 ( & V_290 [ type ] . V_7 ) ;
V_290 [ type ] . V_280 = & V_293 ;
}
}
struct V_5 * F_274 ( int V_2 )
{
struct V_5 * V_191 ;
V_191 = F_275 ( V_216 , 0 , 0 , NULL , & V_293 , 0 , 0 ,
F_276 ( V_2 ) ) ;
if ( ! F_277 ( V_191 ) ) {
F_272 ( V_191 -> V_281 ) ;
F_278 ( V_191 , V_2 ) ;
}
return V_191 ;
}
long F_279 ( unsigned long V_209 ,
unsigned long V_294 ,
unsigned long V_295 ,
int T_4 * V_296 ,
int T_4 * V_297 ,
unsigned long V_298 )
{
struct V_5 * V_152 ;
int V_299 = 0 ;
long V_300 ;
if ( ! ( V_209 & V_301 ) ) {
if ( V_209 & V_302 )
V_299 = V_303 ;
else if ( ( V_209 & V_304 ) != V_305 )
V_299 = V_306 ;
else
V_299 = V_307 ;
if ( F_208 ( ! F_280 ( V_48 , V_299 ) ) )
V_299 = 0 ;
}
V_152 = F_275 ( V_209 , V_294 , V_295 ,
V_297 , NULL , V_299 , V_298 , V_77 ) ;
F_281 () ;
if ( ! F_277 ( V_152 ) ) {
struct V_195 V_196 ;
struct V_280 * V_280 ;
F_282 ( V_48 , V_152 ) ;
V_280 = F_283 ( V_152 , V_291 ) ;
V_300 = F_284 ( V_280 ) ;
if ( V_209 & V_308 )
F_223 ( V_300 , V_296 ) ;
if ( V_209 & V_302 ) {
V_152 -> V_197 = & V_196 ;
F_285 ( & V_196 ) ;
F_286 ( V_152 ) ;
}
F_287 ( V_152 ) ;
if ( F_130 ( V_299 ) )
F_288 ( V_299 , V_280 ) ;
if ( V_209 & V_302 ) {
if ( ! F_210 ( V_152 , & V_196 ) )
F_288 ( V_309 , V_280 ) ;
}
F_289 ( V_280 ) ;
} else {
V_300 = F_290 ( V_152 ) ;
}
return V_300 ;
}
long F_291 ( unsigned long V_209 ,
unsigned long V_294 ,
unsigned long V_295 ,
int T_4 * V_296 ,
int T_4 * V_297 )
{
return F_279 ( V_209 , V_294 , V_295 ,
V_296 , V_297 , 0 ) ;
}
T_5 F_292 ( int (* F_293)( void * ) , void * V_310 , unsigned long V_39 )
{
return F_279 ( V_39 | V_216 | V_301 , ( unsigned long ) F_293 ,
( unsigned long ) V_310 , NULL , NULL , 0 ) ;
}
void F_294 ( struct V_5 * V_311 , T_6 V_312 , void * V_313 )
{
struct V_5 * V_314 , * V_315 , * V_198 ;
int V_316 ;
F_295 ( & V_1 ) ;
V_314 = V_311 = V_311 -> V_266 ;
V_317:
F_296 (leader, parent) {
F_297 (child, &parent->children, sibling) {
V_316 = V_312 ( V_198 , V_313 ) ;
if ( V_316 ) {
if ( V_316 < 0 )
goto V_114;
V_314 = V_198 ;
goto V_317;
}
V_318:
;
}
}
if ( V_314 != V_311 ) {
V_198 = V_314 ;
V_315 = V_198 -> V_319 ;
V_314 = V_315 -> V_266 ;
goto V_318;
}
V_114:
F_298 ( & V_1 ) ;
}
static void F_299 ( void * V_313 )
{
struct V_235 * V_237 = V_313 ;
F_138 ( & V_237 -> V_269 ) ;
F_249 ( & V_237 -> V_320 ) ;
}
void T_1 F_300 ( void )
{
V_238 = F_30 ( L_8 ,
sizeof( struct V_235 ) , 0 ,
V_321 | V_58 | V_322 |
V_59 | V_60 , F_299 ) ;
V_44 = F_30 ( L_9 ,
sizeof( struct V_41 ) , 0 ,
V_321 | V_58 | V_59 | V_60 ,
NULL ) ;
V_323 = F_30 ( L_10 ,
sizeof( struct V_225 ) , 0 ,
V_321 | V_58 | V_59 | V_60 ,
NULL ) ;
V_324 = F_30 ( L_11 ,
sizeof( struct V_218 ) , 0 ,
V_321 | V_58 | V_59 | V_60 ,
NULL ) ;
V_325 = F_30 ( L_12 ,
sizeof( struct V_89 ) , V_326 ,
V_321 | V_58 | V_59 | V_60 ,
NULL ) ;
V_122 = F_301 ( V_92 , V_58 | V_60 ) ;
F_302 () ;
F_303 () ;
}
static int F_304 ( unsigned long V_327 )
{
if ( V_327 & ~ ( V_249 | V_220 | V_328 | V_236 |
V_216 | V_229 | V_329 |
V_330 | V_331 | V_332 |
V_333 | V_334 | V_335 ) )
return - V_336 ;
if ( V_327 & ( V_249 | V_236 | V_216 ) ) {
if ( ! F_305 ( V_48 ) )
return - V_336 ;
}
if ( V_327 & ( V_236 | V_216 ) ) {
if ( F_46 ( & V_48 -> V_237 -> V_179 ) > 1 )
return - V_336 ;
}
if ( V_327 & V_216 ) {
if ( ! F_306 () )
return - V_336 ;
}
return 0 ;
}
static int F_307 ( unsigned long V_327 , struct V_218 * * V_337 )
{
struct V_218 * V_219 = V_48 -> V_219 ;
if ( ! ( V_327 & V_220 ) || ! V_219 )
return 0 ;
if ( V_219 -> V_224 == 1 )
return 0 ;
* V_337 = F_232 ( V_219 ) ;
if ( ! * V_337 )
return - V_145 ;
return 0 ;
}
static int F_308 ( unsigned long V_327 , struct V_225 * * V_338 )
{
struct V_225 * V_339 = V_48 -> V_228 ;
int error = 0 ;
if ( ( V_327 & V_229 ) &&
( V_339 && F_46 ( & V_339 -> V_179 ) > 1 ) ) {
* V_338 = F_234 ( V_339 , & error ) ;
if ( ! * V_338 )
return error ;
}
return 0 ;
}
int F_309 ( struct V_225 * * V_340 )
{
struct V_5 * V_191 = V_48 ;
struct V_225 * V_341 = NULL ;
int error ;
error = F_308 ( V_229 , & V_341 ) ;
if ( error || ! V_341 ) {
* V_340 = NULL ;
return error ;
}
* V_340 = V_191 -> V_228 ;
F_198 ( V_191 ) ;
V_191 -> V_228 = V_341 ;
F_199 ( V_191 ) ;
return 0 ;
}
int F_310 ( struct V_342 * V_343 , int V_344 ,
void T_4 * V_345 , T_7 * V_346 , T_8 * V_347 )
{
struct V_342 V_348 ;
int V_349 ;
int V_50 = V_53 ;
int V_350 = V_54 ;
int V_351 = V_52 ;
V_348 = * V_343 ;
V_348 . V_313 = & V_50 ;
V_348 . V_352 = & V_350 ;
V_348 . V_353 = & V_351 ;
V_349 = F_311 ( & V_348 , V_344 , V_345 , V_346 , V_347 ) ;
if ( V_349 || ! V_344 )
return V_349 ;
F_64 ( V_50 ) ;
return 0 ;
}
