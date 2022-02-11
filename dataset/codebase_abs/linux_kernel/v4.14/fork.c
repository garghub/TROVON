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
#ifdef F_18
memset ( V_18 -> V_17 , 0 , V_19 ) ;
#endif
V_6 -> V_20 = V_18 ;
return V_18 -> V_17 ;
}
V_10 = F_19 ( V_19 , V_21 ,
V_22 , V_23 ,
V_24 ,
V_25 ,
0 , V_7 , F_20 ( 0 ) ) ;
if ( V_10 )
V_6 -> V_20 = F_21 ( V_10 ) ;
return V_10 ;
#else
struct V_26 * V_26 = F_22 ( V_7 , V_24 ,
V_27 ) ;
return V_26 ? F_23 ( V_26 ) : NULL ;
#endif
}
static inline void F_24 ( struct V_5 * V_6 )
{
#ifdef F_16
if ( F_25 ( V_6 ) ) {
int V_14 ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( F_26 ( V_13 [ V_14 ] ,
NULL , V_6 -> V_20 ) != NULL )
continue;
return;
}
F_27 ( V_6 -> V_10 ) ;
return;
}
#endif
F_28 ( F_29 ( V_6 -> V_10 ) , V_27 ) ;
}
static unsigned long * F_15 ( struct V_5 * V_6 ,
int V_7 )
{
return F_8 ( V_28 , V_24 , V_7 ) ;
}
static void F_24 ( struct V_5 * V_6 )
{
F_10 ( V_28 , V_6 -> V_10 ) ;
}
void F_30 ( void )
{
V_28 = F_31 ( L_1 , V_19 ,
V_19 , 0 , NULL ) ;
F_32 ( V_28 == NULL ) ;
}
static void F_33 ( struct V_5 * V_6 , int V_29 )
{
void * V_10 = F_34 ( V_6 ) ;
struct V_11 * V_30 = F_25 ( V_6 ) ;
F_35 ( F_36 ( F_16 ) && V_31 % 1024 != 0 ) ;
if ( V_30 ) {
int V_14 ;
F_32 ( V_30 -> V_32 != V_19 / V_31 ) ;
for ( V_14 = 0 ; V_14 < V_19 / V_31 ; V_14 ++ ) {
F_37 ( F_38 ( V_30 -> V_33 [ V_14 ] ) ,
V_34 ,
V_31 / 1024 * V_29 ) ;
}
F_39 ( V_30 -> V_33 [ 0 ] , V_35 ,
V_29 * ( V_19 / 1024 ) ) ;
} else {
struct V_26 * V_36 = F_29 ( V_10 ) ;
F_37 ( F_38 ( V_36 ) , V_34 ,
V_19 / 1024 * V_29 ) ;
F_39 ( V_36 , V_35 ,
V_29 * ( V_19 / 1024 ) ) ;
}
}
static void F_40 ( struct V_5 * V_6 )
{
if ( F_41 ( V_6 -> V_37 != V_38 ) )
return;
F_33 ( V_6 , - 1 ) ;
F_11 ( V_6 -> V_10 ) ;
F_24 ( V_6 ) ;
V_6 -> V_10 = NULL ;
#ifdef F_16
V_6 -> V_20 = NULL ;
#endif
}
void F_42 ( struct V_5 * V_6 )
{
if ( F_43 ( & V_6 -> V_39 ) )
F_40 ( V_6 ) ;
}
void F_44 ( struct V_5 * V_6 )
{
#ifndef F_45
F_40 ( V_6 ) ;
#else
F_46 ( F_47 ( & V_6 -> V_39 ) != 0 ) ;
#endif
F_48 ( V_6 ) ;
F_49 ( V_6 ) ;
F_50 ( V_6 ) ;
F_6 ( V_6 ) ;
if ( V_6 -> V_40 & V_41 )
F_51 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_52 ( struct V_42 * V_43 )
{
F_53 ( V_43 ) ;
F_54 ( V_43 ) ;
if ( V_43 -> V_44 )
F_55 ( V_43 -> V_44 ) ;
F_10 ( V_45 , V_43 ) ;
}
static inline void F_56 ( struct V_42 * V_43 )
{
if ( F_43 ( & V_43 -> V_46 ) )
F_52 ( V_43 ) ;
}
void F_57 ( struct V_5 * V_6 )
{
F_41 ( ! V_6 -> V_47 ) ;
F_41 ( F_47 ( & V_6 -> V_48 ) ) ;
F_41 ( V_6 == V_49 ) ;
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 ) ;
F_62 ( V_6 ) ;
F_56 ( V_6 -> signal ) ;
if ( ! F_63 ( V_6 ) )
F_44 ( V_6 ) ;
}
void T_1 __weak F_64 ( void ) { }
static void F_65 ( unsigned int V_50 )
{
T_2 V_51 ;
if ( F_66 ( V_52 ) + F_66 ( V_31 ) > 64 )
V_51 = V_53 ;
else
V_51 = F_67 ( ( T_2 ) V_52 * ( T_2 ) V_31 ,
( T_2 ) V_19 * 8UL ) ;
if ( V_51 > V_50 )
V_51 = V_50 ;
V_54 = F_68 ( T_2 , V_51 , V_55 , V_53 ) ;
}
void T_1 F_69 ( void )
{
int V_14 ;
#ifndef F_70
#ifndef F_71
#define F_71 0
#endif
int V_56 = F_72 ( int , V_57 , F_71 ) ;
V_8 = F_31 ( L_2 ,
V_58 , V_56 ,
V_59 | V_60 | V_61 , NULL ) ;
#endif
F_64 () ;
F_65 ( V_53 ) ;
V_62 . signal -> V_63 [ V_64 ] . V_65 = V_54 / 2 ;
V_62 . signal -> V_63 [ V_64 ] . V_66 = V_54 / 2 ;
V_62 . signal -> V_63 [ V_67 ] =
V_62 . signal -> V_63 [ V_64 ] ;
for ( V_14 = 0 ; V_14 < V_68 ; V_14 ++ ) {
V_69 . V_70 [ V_14 ] = V_54 / 2 ;
}
#ifdef F_16
F_73 ( V_71 , L_3 ,
NULL , F_12 ) ;
#endif
F_74 ( & V_62 ) ;
}
int __weak F_75 ( struct V_5 * V_72 ,
struct V_5 * V_73 )
{
* V_72 = * V_73 ;
return 0 ;
}
void F_76 ( struct V_5 * V_6 )
{
unsigned long * V_74 ;
V_74 = F_77 ( V_6 ) ;
* V_74 = V_75 ;
}
static struct V_5 * F_78 ( struct V_5 * V_76 , int V_7 )
{
struct V_5 * V_6 ;
unsigned long * V_10 ;
struct V_11 * V_20 ;
int V_77 ;
if ( V_7 == V_78 )
V_7 = F_79 ( V_76 ) ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_10 = F_15 ( V_6 , V_7 ) ;
if ( ! V_10 )
goto V_79;
V_20 = F_25 ( V_6 ) ;
V_77 = F_75 ( V_6 , V_76 ) ;
V_6 -> V_10 = V_10 ;
#ifdef F_16
V_6 -> V_20 = V_20 ;
#endif
#ifdef F_45
F_80 ( & V_6 -> V_39 , 1 ) ;
#endif
if ( V_77 )
goto V_80;
#ifdef F_81
V_6 -> V_81 . V_82 = NULL ;
#endif
F_82 ( V_6 , V_76 ) ;
F_83 ( V_6 ) ;
F_84 ( V_6 ) ;
F_76 ( V_6 ) ;
#ifdef F_85
V_6 -> V_83 = F_86 () ;
#endif
F_80 ( & V_6 -> V_48 , 2 ) ;
#ifdef F_87
V_6 -> V_84 = 0 ;
#endif
V_6 -> V_85 = NULL ;
V_6 -> V_86 . V_26 = NULL ;
V_6 -> V_87 . V_88 = NULL ;
F_33 ( V_6 , 1 ) ;
F_88 ( V_6 ) ;
#ifdef F_89
V_6 -> V_89 = 0 ;
#endif
return V_6 ;
V_80:
F_24 ( V_6 ) ;
V_79:
F_9 ( V_6 ) ;
return NULL ;
}
static T_3 int F_90 ( struct V_90 * V_91 ,
struct V_90 * V_92 )
{
struct V_93 * V_94 , * V_95 , * V_96 , * * V_97 ;
struct V_98 * * V_99 , * V_100 ;
int V_101 ;
unsigned long V_102 ;
F_91 ( V_103 ) ;
F_92 () ;
if ( F_93 ( & V_92 -> V_104 ) ) {
V_101 = - V_105 ;
goto V_106;
}
F_94 ( V_92 ) ;
F_95 ( V_92 , V_91 ) ;
F_96 ( & V_91 -> V_104 , V_107 ) ;
F_97 ( V_91 -> V_108 , F_98 ( V_92 ) ) ;
V_91 -> V_109 = V_92 -> V_109 ;
V_91 -> V_110 = V_92 -> V_110 ;
V_91 -> V_111 = V_92 -> V_111 ;
V_91 -> V_112 = V_92 -> V_112 ;
V_99 = & V_91 -> V_113 . V_98 ;
V_100 = NULL ;
V_97 = & V_91 -> V_114 ;
V_101 = F_99 ( V_91 , V_92 ) ;
if ( V_101 )
goto V_115;
V_101 = F_100 ( V_91 , V_92 ) ;
if ( V_101 )
goto V_115;
V_96 = NULL ;
for ( V_94 = V_92 -> V_114 ; V_94 ; V_94 = V_94 -> V_116 ) {
struct V_117 * V_117 ;
if ( V_94 -> V_118 & V_119 ) {
F_101 ( V_91 , V_94 -> V_118 , - F_102 ( V_94 ) ) ;
continue;
}
V_102 = 0 ;
if ( V_94 -> V_118 & V_120 ) {
unsigned long V_121 = F_102 ( V_94 ) ;
if ( F_103 ( V_92 , V_121 ) )
goto V_122;
V_102 = V_121 ;
}
V_95 = F_104 ( V_123 , V_9 ) ;
if ( ! V_95 )
goto V_122;
* V_95 = * V_94 ;
F_105 ( & V_95 -> V_124 ) ;
V_101 = F_106 ( V_94 , V_95 ) ;
if ( V_101 )
goto V_125;
V_95 -> V_126 = V_91 ;
V_101 = F_107 ( V_95 , & V_103 ) ;
if ( V_101 )
goto V_127;
if ( V_95 -> V_118 & V_128 ) {
V_95 -> V_129 = NULL ;
if ( F_108 ( V_95 ) )
goto V_127;
} else if ( F_109 ( V_95 , V_94 ) )
goto V_127;
V_95 -> V_118 &= ~ ( V_130 | V_131 ) ;
V_95 -> V_116 = V_95 -> V_132 = NULL ;
V_117 = V_95 -> V_133 ;
if ( V_117 ) {
struct V_134 * V_134 = F_110 ( V_117 ) ;
struct V_135 * V_136 = V_117 -> V_137 ;
F_111 ( V_117 ) ;
if ( V_95 -> V_118 & V_138 )
F_112 ( & V_134 -> V_139 ) ;
F_113 ( V_136 ) ;
if ( V_95 -> V_118 & V_140 )
F_114 ( & V_136 -> V_141 ) ;
F_115 ( V_136 ) ;
F_116 ( V_95 , V_94 ,
& V_136 -> V_142 ) ;
F_117 ( V_136 ) ;
F_118 ( V_136 ) ;
}
if ( F_119 ( V_95 ) )
F_120 ( V_95 ) ;
* V_97 = V_95 ;
V_97 = & V_95 -> V_116 ;
V_95 -> V_132 = V_96 ;
V_96 = V_95 ;
F_121 ( V_91 , V_95 , V_99 , V_100 ) ;
V_99 = & V_95 -> V_143 . V_144 ;
V_100 = & V_95 -> V_143 ;
V_91 -> V_145 ++ ;
if ( ! ( V_95 -> V_118 & V_128 ) )
V_101 = F_122 ( V_91 , V_92 , V_94 ) ;
if ( V_95 -> V_146 && V_95 -> V_146 -> V_147 )
V_95 -> V_146 -> V_147 ( V_95 ) ;
if ( V_101 )
goto V_115;
}
F_123 ( V_92 , V_91 ) ;
V_101 = 0 ;
V_115:
F_124 ( & V_91 -> V_104 ) ;
F_125 ( V_92 ) ;
F_124 ( & V_92 -> V_104 ) ;
F_126 ( & V_103 ) ;
V_106:
F_127 () ;
return V_101 ;
V_127:
F_128 ( F_129 ( V_95 ) ) ;
V_125:
F_10 ( V_123 , V_95 ) ;
V_122:
V_101 = - V_148 ;
F_130 ( V_102 ) ;
goto V_115;
}
static inline int F_131 ( struct V_90 * V_91 )
{
V_91 -> V_149 = F_132 ( V_91 ) ;
if ( F_133 ( ! V_91 -> V_149 ) )
return - V_148 ;
return 0 ;
}
static inline void F_134 ( struct V_90 * V_91 )
{
F_135 ( V_91 , V_91 -> V_149 ) ;
}
static int F_90 ( struct V_90 * V_91 , struct V_90 * V_92 )
{
F_136 ( & V_92 -> V_104 ) ;
F_97 ( V_91 -> V_108 , F_98 ( V_92 ) ) ;
F_124 ( & V_92 -> V_104 ) ;
return 0 ;
}
static int T_1 F_137 ( char * V_18 )
{
V_150 =
( F_138 ( V_18 , NULL , 0 ) << V_151 ) &
V_152 ;
return 1 ;
}
static void F_139 ( struct V_90 * V_91 )
{
#ifdef F_140
F_141 ( & V_91 -> V_153 ) ;
V_91 -> V_154 = NULL ;
#endif
}
static void F_142 ( struct V_90 * V_91 , struct V_5 * V_155 )
{
#ifdef F_143
V_91 -> V_156 = V_155 ;
#endif
}
static void F_144 ( struct V_90 * V_91 )
{
#ifdef F_145
V_91 -> V_157 . V_158 = NULL ;
#endif
}
static struct V_90 * F_146 ( struct V_90 * V_91 , struct V_5 * V_155 ,
struct V_159 * V_160 )
{
V_91 -> V_114 = NULL ;
V_91 -> V_113 = V_161 ;
V_91 -> V_162 = 0 ;
F_80 ( & V_91 -> V_163 , 1 ) ;
F_80 ( & V_91 -> V_164 , 1 ) ;
F_147 ( & V_91 -> V_104 ) ;
F_105 ( & V_91 -> V_165 ) ;
V_91 -> V_166 = NULL ;
F_148 ( & V_91 -> V_167 , 0 ) ;
F_149 ( V_91 ) ;
V_91 -> V_145 = 0 ;
V_91 -> V_168 = 0 ;
V_91 -> V_169 = 0 ;
memset ( & V_91 -> V_170 , 0 , sizeof( V_91 -> V_170 ) ) ;
F_141 ( & V_91 -> V_171 ) ;
F_150 ( V_91 ) ;
F_139 ( V_91 ) ;
F_142 ( V_91 , V_155 ) ;
F_97 ( V_91 -> V_108 , NULL ) ;
F_151 ( V_91 ) ;
F_152 ( V_91 ) ;
F_153 ( V_91 ) ;
#if F_154 ( V_172 ) && ! V_173
V_91 -> V_174 = NULL ;
#endif
F_144 ( V_91 ) ;
if ( V_49 -> V_91 ) {
V_91 -> V_40 = V_49 -> V_91 -> V_40 & V_175 ;
V_91 -> V_176 = V_49 -> V_91 -> V_176 & V_177 ;
} else {
V_91 -> V_40 = V_150 ;
V_91 -> V_176 = 0 ;
}
if ( F_131 ( V_91 ) )
goto V_178;
if ( F_155 ( V_155 , V_91 ) )
goto V_179;
V_91 -> V_160 = F_156 ( V_160 ) ;
return V_91 ;
V_179:
F_134 ( V_91 ) ;
V_178:
F_157 ( V_91 ) ;
return NULL ;
}
static void F_158 ( struct V_90 * V_91 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_180 ; V_14 ++ ) {
long V_181 = F_159 ( & V_91 -> V_170 . V_182 [ V_14 ] ) ;
if ( F_133 ( V_181 ) )
F_160 ( V_183 L_4
L_5 , V_91 , V_14 , V_181 ) ;
}
if ( F_159 ( & V_91 -> V_167 ) )
F_161 ( L_6 ,
F_159 ( & V_91 -> V_167 ) ) ;
if ( F_162 ( V_91 ) )
F_161 ( L_7 ,
F_162 ( V_91 ) ) ;
#if F_154 ( V_172 ) && ! V_173
F_163 ( V_91 -> V_174 , V_91 ) ;
#endif
}
struct V_90 * F_164 ( void )
{
struct V_90 * V_91 ;
V_91 = F_165 () ;
if ( ! V_91 )
return NULL ;
memset ( V_91 , 0 , sizeof( * V_91 ) ) ;
return F_146 ( V_91 , V_49 , F_166 () ) ;
}
void F_167 ( struct V_90 * V_91 )
{
F_32 ( V_91 == & V_184 ) ;
F_134 ( V_91 ) ;
F_168 ( V_91 ) ;
F_169 ( V_91 ) ;
F_170 ( V_91 ) ;
F_158 ( V_91 ) ;
F_171 ( V_91 -> V_160 ) ;
F_157 ( V_91 ) ;
}
static inline void F_172 ( struct V_90 * V_91 )
{
F_173 ( F_47 ( & V_91 -> V_163 ) ) ;
F_174 ( V_91 ) ;
F_175 ( V_91 ) ;
F_176 ( V_91 ) ;
F_177 ( V_91 ) ;
F_178 ( V_91 ) ;
F_179 ( V_91 ) ;
F_180 ( V_91 , NULL ) ;
if ( ! F_181 ( & V_91 -> V_165 ) ) {
F_182 ( & V_185 ) ;
F_183 ( & V_91 -> V_165 ) ;
F_184 ( & V_185 ) ;
}
if ( V_91 -> V_186 )
F_185 ( V_91 -> V_186 -> V_187 ) ;
F_186 ( V_91 ) ;
}
void F_187 ( struct V_90 * V_91 )
{
F_188 () ;
if ( F_43 ( & V_91 -> V_163 ) )
F_172 ( V_91 ) ;
}
static void F_189 ( struct V_188 * V_189 )
{
struct V_90 * V_91 = F_190 ( V_189 , struct V_90 ,
V_190 ) ;
F_172 ( V_91 ) ;
}
void F_191 ( struct V_90 * V_91 )
{
if ( F_43 ( & V_91 -> V_163 ) ) {
F_192 ( & V_91 -> V_190 , F_189 ) ;
F_193 ( & V_91 -> V_190 ) ;
}
}
void F_180 ( struct V_90 * V_91 , struct V_117 * V_191 )
{
struct V_117 * V_192 ;
V_192 = F_194 ( V_91 -> V_108 ) ;
if ( V_191 )
F_111 ( V_191 ) ;
F_195 ( V_91 -> V_108 , V_191 ) ;
if ( V_192 )
F_196 ( V_192 ) ;
}
struct V_117 * F_98 ( struct V_90 * V_91 )
{
struct V_117 * V_108 ;
F_197 () ;
V_108 = F_198 ( V_91 -> V_108 ) ;
if ( V_108 && ! F_199 ( V_108 ) )
V_108 = NULL ;
F_200 () ;
return V_108 ;
}
struct V_117 * F_201 ( struct V_5 * V_193 )
{
struct V_117 * V_108 = NULL ;
struct V_90 * V_91 ;
F_202 ( V_193 ) ;
V_91 = V_193 -> V_91 ;
if ( V_91 ) {
if ( ! ( V_193 -> V_40 & V_41 ) )
V_108 = F_98 ( V_91 ) ;
}
F_203 ( V_193 ) ;
return V_108 ;
}
struct V_90 * F_204 ( struct V_5 * V_193 )
{
struct V_90 * V_91 ;
F_202 ( V_193 ) ;
V_91 = V_193 -> V_91 ;
if ( V_91 ) {
if ( V_193 -> V_40 & V_41 )
V_91 = NULL ;
else
F_205 ( V_91 ) ;
}
F_203 ( V_193 ) ;
return V_91 ;
}
struct V_90 * F_206 ( struct V_5 * V_193 , unsigned int V_194 )
{
struct V_90 * V_91 ;
int V_77 ;
V_77 = F_207 ( & V_193 -> signal -> V_195 ) ;
if ( V_77 )
return F_208 ( V_77 ) ;
V_91 = F_204 ( V_193 ) ;
if ( V_91 && V_91 != V_49 -> V_91 &&
! F_209 ( V_193 , V_194 ) ) {
F_187 ( V_91 ) ;
V_91 = F_208 ( - V_196 ) ;
}
F_210 ( & V_193 -> signal -> V_195 ) ;
return V_91 ;
}
static void F_211 ( struct V_5 * V_6 )
{
struct V_197 * V_198 ;
F_202 ( V_6 ) ;
V_198 = V_6 -> V_199 ;
if ( F_212 ( V_198 ) ) {
V_6 -> V_199 = NULL ;
F_213 ( V_198 ) ;
}
F_203 ( V_6 ) ;
}
static int F_214 ( struct V_5 * V_200 ,
struct V_197 * V_198 )
{
int V_201 ;
F_215 () ;
V_201 = F_216 ( V_198 ) ;
F_217 () ;
if ( V_201 ) {
F_202 ( V_200 ) ;
V_200 -> V_199 = NULL ;
F_203 ( V_200 ) ;
}
F_218 ( V_200 ) ;
return V_201 ;
}
void F_219 ( struct V_5 * V_6 , struct V_90 * V_91 )
{
#ifdef F_220
if ( F_133 ( V_6 -> V_202 ) ) {
F_221 ( V_6 ) ;
V_6 -> V_202 = NULL ;
}
#ifdef F_222
if ( F_133 ( V_6 -> V_203 ) ) {
F_223 ( V_6 ) ;
V_6 -> V_203 = NULL ;
}
#endif
if ( F_133 ( ! F_181 ( & V_6 -> V_204 ) ) )
F_224 ( V_6 ) ;
#endif
F_225 ( V_6 ) ;
F_226 ( V_6 , V_91 ) ;
if ( V_6 -> V_205 ) {
if ( ! ( V_6 -> signal -> V_40 & V_206 ) &&
F_47 ( & V_91 -> V_163 ) > 1 ) {
F_227 ( 0 , V_6 -> V_205 ) ;
F_228 ( V_6 -> V_205 , V_207 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_205 = NULL ;
}
if ( V_6 -> V_199 )
F_211 ( V_6 ) ;
}
static struct V_90 * F_229 ( struct V_5 * V_6 )
{
struct V_90 * V_91 , * V_92 = V_49 -> V_91 ;
int V_77 ;
V_91 = F_165 () ;
if ( ! V_91 )
goto V_122;
memcpy ( V_91 , V_92 , sizeof( * V_91 ) ) ;
if ( ! F_146 ( V_91 , V_6 , V_91 -> V_160 ) )
goto V_122;
V_77 = F_90 ( V_91 , V_92 ) ;
if ( V_77 )
goto V_208;
V_91 -> V_209 = F_230 ( V_91 ) ;
V_91 -> V_210 = V_91 -> V_109 ;
if ( V_91 -> V_186 && ! F_231 ( V_91 -> V_186 -> V_187 ) )
goto V_208;
return V_91 ;
V_208:
V_91 -> V_186 = NULL ;
F_187 ( V_91 ) ;
V_122:
return NULL ;
}
static int F_232 ( unsigned long V_211 , struct V_5 * V_6 )
{
struct V_90 * V_91 , * V_92 ;
int V_101 ;
V_6 -> V_212 = V_6 -> V_213 = 0 ;
V_6 -> V_214 = V_6 -> V_215 = 0 ;
#ifdef F_233
V_6 -> V_216 = V_6 -> V_214 + V_6 -> V_215 ;
#endif
V_6 -> V_91 = NULL ;
V_6 -> V_217 = NULL ;
V_92 = V_49 -> V_91 ;
if ( ! V_92 )
return 0 ;
F_234 ( V_6 ) ;
if ( V_211 & V_218 ) {
F_205 ( V_92 ) ;
V_91 = V_92 ;
goto V_219;
}
V_101 = - V_148 ;
V_91 = F_229 ( V_6 ) ;
if ( ! V_91 )
goto V_122;
V_219:
V_6 -> V_91 = V_91 ;
V_6 -> V_217 = V_91 ;
return 0 ;
V_122:
return V_101 ;
}
static int F_235 ( unsigned long V_211 , struct V_5 * V_6 )
{
struct V_220 * V_221 = V_49 -> V_221 ;
if ( V_211 & V_222 ) {
F_182 ( & V_221 -> V_223 ) ;
if ( V_221 -> V_224 ) {
F_184 ( & V_221 -> V_223 ) ;
return - V_225 ;
}
V_221 -> V_226 ++ ;
F_184 ( & V_221 -> V_223 ) ;
return 0 ;
}
V_6 -> V_221 = F_236 ( V_221 ) ;
if ( ! V_6 -> V_221 )
return - V_148 ;
return 0 ;
}
static int F_237 ( unsigned long V_211 , struct V_5 * V_6 )
{
struct V_227 * V_228 , * V_229 ;
int error = 0 ;
V_228 = V_49 -> V_230 ;
if ( ! V_228 )
goto V_115;
if ( V_211 & V_231 ) {
F_114 ( & V_228 -> V_182 ) ;
goto V_115;
}
V_229 = F_238 ( V_228 , & error ) ;
if ( ! V_229 )
goto V_115;
V_6 -> V_230 = V_229 ;
error = 0 ;
V_115:
return error ;
}
static int F_239 ( unsigned long V_211 , struct V_5 * V_6 )
{
#ifdef F_240
struct V_232 * V_233 = V_49 -> V_232 ;
struct V_232 * V_234 ;
if ( ! V_233 )
return 0 ;
if ( V_211 & V_235 ) {
F_241 ( V_233 ) ;
V_6 -> V_232 = V_233 ;
} else if ( F_242 ( V_233 -> V_236 ) ) {
V_234 = F_243 ( V_6 , V_9 , V_78 ) ;
if ( F_133 ( ! V_234 ) )
return - V_148 ;
V_234 -> V_236 = V_233 -> V_236 ;
F_244 ( V_234 ) ;
}
#endif
return 0 ;
}
static int F_245 ( unsigned long V_211 , struct V_5 * V_6 )
{
struct V_237 * V_43 ;
if ( V_211 & V_238 ) {
F_114 ( & V_49 -> V_239 -> V_182 ) ;
return 0 ;
}
V_43 = F_104 ( V_240 , V_9 ) ;
F_195 ( V_6 -> V_239 , V_43 ) ;
if ( ! V_43 )
return - V_148 ;
F_80 ( & V_43 -> V_182 , 1 ) ;
memcpy ( V_43 -> V_241 , V_49 -> V_239 -> V_241 , sizeof( V_43 -> V_241 ) ) ;
return 0 ;
}
void F_246 ( struct V_237 * V_239 )
{
if ( F_43 ( & V_239 -> V_182 ) ) {
F_247 ( V_239 ) ;
F_10 ( V_240 , V_239 ) ;
}
}
static void F_248 ( struct V_42 * V_43 )
{
unsigned long V_242 ;
V_242 = F_249 ( V_43 -> V_63 [ V_243 ] . V_65 ) ;
if ( V_242 != V_244 ) {
V_43 -> V_245 . V_246 = V_242 * V_247 ;
V_43 -> V_248 . V_249 = true ;
}
F_105 ( & V_43 -> V_250 [ 0 ] ) ;
F_105 ( & V_43 -> V_250 [ 1 ] ) ;
F_105 ( & V_43 -> V_250 [ 2 ] ) ;
}
static inline void F_248 ( struct V_42 * V_43 ) { }
static int F_250 ( unsigned long V_211 , struct V_5 * V_6 )
{
struct V_42 * V_43 ;
if ( V_211 & V_251 )
return 0 ;
V_43 = F_251 ( V_45 , V_9 ) ;
V_6 -> signal = V_43 ;
if ( ! V_43 )
return - V_148 ;
V_43 -> V_252 = 1 ;
F_80 ( & V_43 -> V_253 , 1 ) ;
F_80 ( & V_43 -> V_46 , 1 ) ;
V_43 -> V_254 = (struct V_255 ) F_252 ( V_6 -> V_256 ) ;
V_6 -> V_256 = (struct V_255 ) F_252 ( V_43 -> V_254 ) ;
F_253 ( & V_43 -> V_257 ) ;
V_43 -> V_258 = V_6 ;
F_254 ( & V_43 -> V_259 ) ;
F_255 ( & V_43 -> V_260 ) ;
F_256 ( & V_43 -> V_261 ) ;
#ifdef F_257
F_105 ( & V_43 -> V_262 ) ;
F_258 ( & V_43 -> V_263 , V_264 , V_265 ) ;
V_43 -> V_263 . V_266 = V_267 ;
#endif
F_202 ( V_49 -> V_268 ) ;
memcpy ( V_43 -> V_63 , V_49 -> signal -> V_63 , sizeof V_43 -> V_63 ) ;
F_203 ( V_49 -> V_268 ) ;
F_248 ( V_43 ) ;
F_259 ( V_43 ) ;
F_260 ( V_43 ) ;
V_43 -> V_269 = V_49 -> signal -> V_269 ;
V_43 -> V_270 = V_49 -> signal -> V_270 ;
F_261 ( & V_43 -> V_195 ) ;
return 0 ;
}
static void F_262 ( struct V_5 * V_155 )
{
#ifdef F_81
F_263 ( & V_49 -> V_239 -> V_271 ) ;
F_264 ( V_49 ) ;
V_155 -> V_81 = V_49 -> V_81 ;
if ( F_265 ( V_49 ) )
F_266 ( V_155 ) ;
if ( V_155 -> V_81 . V_194 != V_272 )
F_267 ( V_155 , V_273 ) ;
#endif
}
static void F_268 ( struct V_5 * V_155 )
{
F_269 ( & V_155 -> V_274 ) ;
#ifdef F_270
V_155 -> V_275 = V_276 ;
V_155 -> V_277 = NULL ;
V_155 -> V_278 = NULL ;
#endif
}
static void F_271 ( struct V_5 * V_6 )
{
V_6 -> V_245 . V_246 = 0 ;
V_6 -> V_245 . V_279 = 0 ;
V_6 -> V_245 . V_280 = 0 ;
F_105 ( & V_6 -> V_250 [ 0 ] ) ;
F_105 ( & V_6 -> V_250 [ 1 ] ) ;
F_105 ( & V_6 -> V_250 [ 2 ] ) ;
}
static inline void F_271 ( struct V_5 * V_6 ) { }
static inline void
F_272 ( struct V_5 * V_193 , enum V_281 type , struct V_282 * V_282 )
{
V_193 -> V_283 [ type ] . V_282 = V_282 ;
}
static inline void F_273 ( struct V_5 * V_155 )
{
#ifdef F_274
V_155 -> V_284 = 0 ;
V_155 -> V_285 . V_18 = 0 ;
V_155 -> V_286 = NULL ;
F_105 ( & V_155 -> V_287 ) ;
#endif
#ifdef F_275
V_155 -> V_288 = false ;
F_105 ( & V_155 -> V_289 ) ;
V_155 -> V_290 = - 1 ;
#endif
}
inline void F_276 ( struct V_291 * V_292 )
{
enum V_281 type ;
for ( type = V_293 ; type < V_294 ; ++ type ) {
F_277 ( & V_292 [ type ] . V_7 ) ;
V_292 [ type ] . V_282 = & V_295 ;
}
}
struct V_5 * F_278 ( int V_2 )
{
struct V_5 * V_193 ;
V_193 = F_279 ( V_218 , 0 , 0 , NULL , & V_295 , 0 , 0 ,
F_280 ( V_2 ) ) ;
if ( ! F_281 ( V_193 ) ) {
F_276 ( V_193 -> V_283 ) ;
F_282 ( V_193 , V_2 ) ;
}
return V_193 ;
}
long F_283 ( unsigned long V_211 ,
unsigned long V_296 ,
unsigned long V_297 ,
int T_4 * V_298 ,
int T_4 * V_299 ,
unsigned long V_300 )
{
struct V_5 * V_155 ;
int V_301 = 0 ;
long V_302 ;
if ( ! ( V_211 & V_303 ) ) {
if ( V_211 & V_304 )
V_301 = V_305 ;
else if ( ( V_211 & V_306 ) != V_307 )
V_301 = V_308 ;
else
V_301 = V_309 ;
if ( F_212 ( ! F_284 ( V_49 , V_301 ) ) )
V_301 = 0 ;
}
V_155 = F_279 ( V_211 , V_296 , V_297 ,
V_299 , NULL , V_301 , V_300 , V_78 ) ;
F_285 () ;
if ( ! F_281 ( V_155 ) ) {
struct V_197 V_198 ;
struct V_282 * V_282 ;
F_286 ( V_49 , V_155 ) ;
V_282 = F_287 ( V_155 , V_293 ) ;
V_302 = F_288 ( V_282 ) ;
if ( V_211 & V_310 )
F_227 ( V_302 , V_298 ) ;
if ( V_211 & V_304 ) {
V_155 -> V_199 = & V_198 ;
F_289 ( & V_198 ) ;
F_290 ( V_155 ) ;
}
F_291 ( V_155 ) ;
if ( F_133 ( V_301 ) )
F_292 ( V_301 , V_282 ) ;
if ( V_211 & V_304 ) {
if ( ! F_214 ( V_155 , & V_198 ) )
F_292 ( V_311 , V_282 ) ;
}
F_293 ( V_282 ) ;
} else {
V_302 = F_294 ( V_155 ) ;
}
return V_302 ;
}
long F_295 ( unsigned long V_211 ,
unsigned long V_296 ,
unsigned long V_297 ,
int T_4 * V_298 ,
int T_4 * V_299 )
{
return F_283 ( V_211 , V_296 , V_297 ,
V_298 , V_299 , 0 ) ;
}
T_5 F_296 ( int (* F_297)( void * ) , void * V_312 , unsigned long V_40 )
{
return F_283 ( V_40 | V_218 | V_303 , ( unsigned long ) F_297 ,
( unsigned long ) V_312 , NULL , NULL , 0 ) ;
}
void F_298 ( struct V_5 * V_313 , T_6 V_314 , void * V_315 )
{
struct V_5 * V_316 , * V_317 , * V_200 ;
int V_318 ;
F_299 ( & V_1 ) ;
V_316 = V_313 = V_313 -> V_268 ;
V_319:
F_300 (leader, parent) {
F_301 (child, &parent->children, sibling) {
V_318 = V_314 ( V_200 , V_315 ) ;
if ( V_318 ) {
if ( V_318 < 0 )
goto V_115;
V_316 = V_200 ;
goto V_319;
}
V_320:
;
}
}
if ( V_316 != V_313 ) {
V_200 = V_316 ;
V_317 = V_200 -> V_321 ;
V_316 = V_317 -> V_268 ;
goto V_320;
}
V_115:
F_302 ( & V_1 ) ;
}
static void F_303 ( void * V_315 )
{
struct V_237 * V_239 = V_315 ;
F_141 ( & V_239 -> V_271 ) ;
F_253 ( & V_239 -> V_322 ) ;
}
void T_1 F_304 ( void )
{
V_240 = F_31 ( L_8 ,
sizeof( struct V_237 ) , 0 ,
V_323 | V_59 | V_324 |
V_60 | V_61 , F_303 ) ;
V_45 = F_31 ( L_9 ,
sizeof( struct V_42 ) , 0 ,
V_323 | V_59 | V_60 | V_61 ,
NULL ) ;
V_325 = F_31 ( L_10 ,
sizeof( struct V_227 ) , 0 ,
V_323 | V_59 | V_60 | V_61 ,
NULL ) ;
V_326 = F_31 ( L_11 ,
sizeof( struct V_220 ) , 0 ,
V_323 | V_59 | V_60 | V_61 ,
NULL ) ;
V_327 = F_31 ( L_12 ,
sizeof( struct V_90 ) , V_328 ,
V_323 | V_59 | V_60 | V_61 ,
NULL ) ;
V_123 = F_305 ( V_93 , V_59 | V_61 ) ;
F_306 () ;
F_307 () ;
}
static int F_308 ( unsigned long V_329 )
{
if ( V_329 & ~ ( V_251 | V_222 | V_330 | V_238 |
V_218 | V_231 | V_331 |
V_332 | V_333 | V_334 |
V_335 | V_336 | V_337 ) )
return - V_338 ;
if ( V_329 & ( V_251 | V_238 | V_218 ) ) {
if ( ! F_309 ( V_49 ) )
return - V_338 ;
}
if ( V_329 & ( V_238 | V_218 ) ) {
if ( F_47 ( & V_49 -> V_239 -> V_182 ) > 1 )
return - V_338 ;
}
if ( V_329 & V_218 ) {
if ( ! F_310 () )
return - V_338 ;
}
return 0 ;
}
static int F_311 ( unsigned long V_329 , struct V_220 * * V_339 )
{
struct V_220 * V_221 = V_49 -> V_221 ;
if ( ! ( V_329 & V_222 ) || ! V_221 )
return 0 ;
if ( V_221 -> V_226 == 1 )
return 0 ;
* V_339 = F_236 ( V_221 ) ;
if ( ! * V_339 )
return - V_148 ;
return 0 ;
}
static int F_312 ( unsigned long V_329 , struct V_227 * * V_340 )
{
struct V_227 * V_341 = V_49 -> V_230 ;
int error = 0 ;
if ( ( V_329 & V_231 ) &&
( V_341 && F_47 ( & V_341 -> V_182 ) > 1 ) ) {
* V_340 = F_238 ( V_341 , & error ) ;
if ( ! * V_340 )
return error ;
}
return 0 ;
}
int F_313 ( struct V_227 * * V_342 )
{
struct V_5 * V_193 = V_49 ;
struct V_227 * V_343 = NULL ;
int error ;
error = F_312 ( V_231 , & V_343 ) ;
if ( error || ! V_343 ) {
* V_342 = NULL ;
return error ;
}
* V_342 = V_193 -> V_230 ;
F_202 ( V_193 ) ;
V_193 -> V_230 = V_343 ;
F_203 ( V_193 ) ;
return 0 ;
}
int F_314 ( struct V_344 * V_345 , int V_346 ,
void T_4 * V_347 , T_7 * V_348 , T_8 * V_349 )
{
struct V_344 V_350 ;
int V_351 ;
int V_51 = V_54 ;
int V_352 = V_55 ;
int V_353 = V_53 ;
V_350 = * V_345 ;
V_350 . V_315 = & V_51 ;
V_350 . V_354 = & V_352 ;
V_350 . V_355 = & V_353 ;
V_351 = F_315 ( & V_350 , V_346 , V_347 , V_348 , V_349 ) ;
if ( V_351 || ! V_346 )
return V_351 ;
F_65 ( V_51 ) ;
return 0 ;
}
