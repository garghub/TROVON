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
F_17 () ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
struct V_11 * V_18 = F_18 ( V_13 [ V_14 ] ) ;
if ( ! V_18 )
continue;
F_19 ( V_13 [ V_14 ] , NULL ) ;
V_6 -> V_19 = V_18 ;
F_20 () ;
return V_18 -> V_17 ;
}
F_20 () ;
V_10 = F_21 ( V_20 , V_20 ,
V_21 , V_22 ,
V_23 ,
V_24 ,
0 , V_7 , F_22 ( 0 ) ) ;
if ( V_10 )
V_6 -> V_19 = F_23 ( V_10 ) ;
return V_10 ;
#else
struct V_25 * V_25 = F_24 ( V_7 , V_23 ,
V_26 ) ;
return V_25 ? F_25 ( V_25 ) : NULL ;
#endif
}
static inline void F_26 ( struct V_5 * V_6 )
{
#ifdef F_16
if ( F_27 ( V_6 ) ) {
unsigned long V_27 ;
int V_14 ;
F_28 ( V_27 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
if ( F_18 ( V_13 [ V_14 ] ) )
continue;
F_19 ( V_13 [ V_14 ] , V_6 -> V_19 ) ;
F_29 ( V_27 ) ;
return;
}
F_29 ( V_27 ) ;
F_30 ( V_6 -> V_10 ) ;
return;
}
#endif
F_31 ( F_32 ( V_6 -> V_10 ) , V_26 ) ;
}
static unsigned long * F_15 ( struct V_5 * V_6 ,
int V_7 )
{
return F_8 ( V_28 , V_23 , V_7 ) ;
}
static void F_26 ( struct V_5 * V_6 )
{
F_10 ( V_28 , V_6 -> V_10 ) ;
}
void F_33 ( void )
{
V_28 = F_34 ( L_1 , V_20 ,
V_20 , 0 , NULL ) ;
F_35 ( V_28 == NULL ) ;
}
static void F_36 ( struct V_5 * V_6 , int V_29 )
{
void * V_10 = F_37 ( V_6 ) ;
struct V_11 * V_30 = F_27 ( V_6 ) ;
F_38 ( F_39 ( F_16 ) && V_31 % 1024 != 0 ) ;
if ( V_30 ) {
int V_14 ;
F_35 ( V_30 -> V_32 != V_20 / V_31 ) ;
for ( V_14 = 0 ; V_14 < V_20 / V_31 ; V_14 ++ ) {
F_40 ( F_41 ( V_30 -> V_33 [ V_14 ] ) ,
V_34 ,
V_31 / 1024 * V_29 ) ;
}
F_42 ( V_30 -> V_33 [ 0 ] , V_35 ,
V_29 * ( V_20 / 1024 ) ) ;
} else {
struct V_25 * V_36 = F_32 ( V_10 ) ;
F_40 ( F_41 ( V_36 ) , V_34 ,
V_20 / 1024 * V_29 ) ;
F_42 ( V_36 , V_35 ,
V_29 * ( V_20 / 1024 ) ) ;
}
}
static void F_43 ( struct V_5 * V_6 )
{
if ( F_44 ( V_6 -> V_37 != V_38 ) )
return;
F_36 ( V_6 , - 1 ) ;
F_11 ( V_6 -> V_10 ) ;
F_26 ( V_6 ) ;
V_6 -> V_10 = NULL ;
#ifdef F_16
V_6 -> V_19 = NULL ;
#endif
}
void F_45 ( struct V_5 * V_6 )
{
if ( F_46 ( & V_6 -> V_39 ) )
F_43 ( V_6 ) ;
}
void F_47 ( struct V_5 * V_6 )
{
#ifndef F_48
F_43 ( V_6 ) ;
#else
F_49 ( F_50 ( & V_6 -> V_39 ) != 0 ) ;
#endif
F_51 ( V_6 ) ;
F_52 ( V_6 ) ;
F_53 ( V_6 ) ;
F_6 ( V_6 ) ;
if ( V_6 -> V_27 & V_40 )
F_54 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_55 ( struct V_41 * V_42 )
{
F_56 ( V_42 ) ;
F_57 ( V_42 ) ;
if ( V_42 -> V_43 )
F_58 ( V_42 -> V_43 ) ;
F_10 ( V_44 , V_42 ) ;
}
static inline void F_59 ( struct V_41 * V_42 )
{
if ( F_46 ( & V_42 -> V_45 ) )
F_55 ( V_42 ) ;
}
void F_60 ( struct V_5 * V_6 )
{
F_44 ( ! V_6 -> V_46 ) ;
F_44 ( F_50 ( & V_6 -> V_47 ) ) ;
F_44 ( V_6 == V_48 ) ;
F_61 ( V_6 ) ;
F_62 ( V_6 ) ;
F_63 ( V_6 ) ;
F_64 ( V_6 ) ;
F_65 ( V_6 ) ;
F_59 ( V_6 -> signal ) ;
if ( ! F_66 ( V_6 ) )
F_47 ( V_6 ) ;
}
void T_1 __weak F_67 ( void ) { }
static void F_68 ( unsigned int V_49 )
{
T_2 V_50 ;
if ( F_69 ( V_51 ) + F_69 ( V_31 ) > 64 )
V_50 = V_52 ;
else
V_50 = F_70 ( ( T_2 ) V_51 * ( T_2 ) V_31 ,
( T_2 ) V_20 * 8UL ) ;
if ( V_50 > V_49 )
V_50 = V_49 ;
V_53 = F_71 ( T_2 , V_50 , V_54 , V_52 ) ;
}
void T_1 F_72 ( void )
{
int V_14 ;
#ifndef F_73
#ifndef F_74
#define F_74 0
#endif
int V_55 = F_75 ( int , V_56 , F_74 ) ;
V_8 = F_34 ( L_2 ,
V_57 , V_55 ,
V_58 | V_59 | V_60 , NULL ) ;
#endif
F_67 () ;
F_68 ( V_52 ) ;
V_61 . signal -> V_62 [ V_63 ] . V_64 = V_53 / 2 ;
V_61 . signal -> V_62 [ V_63 ] . V_65 = V_53 / 2 ;
V_61 . signal -> V_62 [ V_66 ] =
V_61 . signal -> V_62 [ V_63 ] ;
for ( V_14 = 0 ; V_14 < V_67 ; V_14 ++ ) {
V_68 . V_69 [ V_14 ] = V_53 / 2 ;
}
#ifdef F_16
F_76 ( V_70 , L_3 ,
NULL , F_12 ) ;
#endif
}
int __weak F_77 ( struct V_5 * V_71 ,
struct V_5 * V_72 )
{
* V_71 = * V_72 ;
return 0 ;
}
void F_78 ( struct V_5 * V_6 )
{
unsigned long * V_73 ;
V_73 = F_79 ( V_6 ) ;
* V_73 = V_74 ;
}
static struct V_5 * F_80 ( struct V_5 * V_75 , int V_7 )
{
struct V_5 * V_6 ;
unsigned long * V_10 ;
struct V_11 * V_19 ;
int V_76 ;
if ( V_7 == V_77 )
V_7 = F_81 ( V_75 ) ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_10 = F_15 ( V_6 , V_7 ) ;
if ( ! V_10 )
goto V_78;
V_19 = F_27 ( V_6 ) ;
V_76 = F_77 ( V_6 , V_75 ) ;
V_6 -> V_10 = V_10 ;
#ifdef F_16
V_6 -> V_19 = V_19 ;
#endif
#ifdef F_48
F_82 ( & V_6 -> V_39 , 1 ) ;
#endif
if ( V_76 )
goto V_79;
#ifdef F_83
V_6 -> V_80 . V_81 = NULL ;
#endif
F_84 ( V_6 , V_75 ) ;
F_85 ( V_6 ) ;
F_86 ( V_6 ) ;
F_78 ( V_6 ) ;
#ifdef F_87
V_6 -> V_82 = F_88 () ;
#endif
F_82 ( & V_6 -> V_47 , 2 ) ;
#ifdef F_89
V_6 -> V_83 = 0 ;
#endif
V_6 -> V_84 = NULL ;
V_6 -> V_85 . V_25 = NULL ;
V_6 -> V_86 . V_87 = NULL ;
F_36 ( V_6 , 1 ) ;
F_90 ( V_6 ) ;
return V_6 ;
V_79:
F_26 ( V_6 ) ;
V_78:
F_9 ( V_6 ) ;
return NULL ;
}
static T_3 int F_91 ( struct V_88 * V_89 ,
struct V_88 * V_90 )
{
struct V_91 * V_92 , * V_93 , * V_94 , * * V_95 ;
struct V_96 * * V_97 , * V_98 ;
int V_99 ;
unsigned long V_100 ;
F_92 ( V_101 ) ;
F_93 () ;
if ( F_94 ( & V_90 -> V_102 ) ) {
V_99 = - V_103 ;
goto V_104;
}
F_95 ( V_90 ) ;
F_96 ( V_90 , V_89 ) ;
F_97 ( & V_89 -> V_102 , V_105 ) ;
F_98 ( V_89 -> V_106 , F_99 ( V_90 ) ) ;
V_89 -> V_107 = V_90 -> V_107 ;
V_89 -> V_108 = V_90 -> V_108 ;
V_89 -> V_109 = V_90 -> V_109 ;
V_89 -> V_110 = V_90 -> V_110 ;
V_97 = & V_89 -> V_111 . V_96 ;
V_98 = NULL ;
V_95 = & V_89 -> V_112 ;
V_99 = F_100 ( V_89 , V_90 ) ;
if ( V_99 )
goto V_113;
V_99 = F_101 ( V_89 , V_90 ) ;
if ( V_99 )
goto V_113;
V_94 = NULL ;
for ( V_92 = V_90 -> V_112 ; V_92 ; V_92 = V_92 -> V_114 ) {
struct V_115 * V_115 ;
if ( V_92 -> V_116 & V_117 ) {
F_102 ( V_89 , V_92 -> V_116 , - F_103 ( V_92 ) ) ;
continue;
}
V_100 = 0 ;
if ( V_92 -> V_116 & V_118 ) {
unsigned long V_119 = F_103 ( V_92 ) ;
if ( F_104 ( V_90 , V_119 ) )
goto V_120;
V_100 = V_119 ;
}
V_93 = F_105 ( V_121 , V_9 ) ;
if ( ! V_93 )
goto V_120;
* V_93 = * V_92 ;
F_106 ( & V_93 -> V_122 ) ;
V_99 = F_107 ( V_92 , V_93 ) ;
if ( V_99 )
goto V_123;
V_93 -> V_124 = V_89 ;
V_99 = F_108 ( V_93 , & V_101 ) ;
if ( V_99 )
goto V_125;
if ( F_109 ( V_93 , V_92 ) )
goto V_125;
V_93 -> V_116 &= ~ ( V_126 | V_127 ) ;
V_93 -> V_114 = V_93 -> V_128 = NULL ;
V_115 = V_93 -> V_129 ;
if ( V_115 ) {
struct V_130 * V_130 = F_110 ( V_115 ) ;
struct V_131 * V_132 = V_115 -> V_133 ;
F_111 ( V_115 ) ;
if ( V_93 -> V_116 & V_134 )
F_112 ( & V_130 -> V_135 ) ;
F_113 ( V_132 ) ;
if ( V_93 -> V_116 & V_136 )
F_114 ( & V_132 -> V_137 ) ;
F_115 ( V_132 ) ;
F_116 ( V_93 , V_92 ,
& V_132 -> V_138 ) ;
F_117 ( V_132 ) ;
F_118 ( V_132 ) ;
}
if ( F_119 ( V_93 ) )
F_120 ( V_93 ) ;
* V_95 = V_93 ;
V_95 = & V_93 -> V_114 ;
V_93 -> V_128 = V_94 ;
V_94 = V_93 ;
F_121 ( V_89 , V_93 , V_97 , V_98 ) ;
V_97 = & V_93 -> V_139 . V_140 ;
V_98 = & V_93 -> V_139 ;
V_89 -> V_141 ++ ;
V_99 = F_122 ( V_89 , V_90 , V_92 ) ;
if ( V_93 -> V_142 && V_93 -> V_142 -> V_143 )
V_93 -> V_142 -> V_143 ( V_93 ) ;
if ( V_99 )
goto V_113;
}
F_123 ( V_90 , V_89 ) ;
V_99 = 0 ;
V_113:
F_124 ( & V_89 -> V_102 ) ;
F_125 ( V_90 ) ;
F_124 ( & V_90 -> V_102 ) ;
F_126 ( & V_101 ) ;
V_104:
F_127 () ;
return V_99 ;
V_125:
F_128 ( F_129 ( V_93 ) ) ;
V_123:
F_10 ( V_121 , V_93 ) ;
V_120:
V_99 = - V_144 ;
F_130 ( V_100 ) ;
goto V_113;
}
static inline int F_131 ( struct V_88 * V_89 )
{
V_89 -> V_145 = F_132 ( V_89 ) ;
if ( F_133 ( ! V_89 -> V_145 ) )
return - V_144 ;
return 0 ;
}
static inline void F_134 ( struct V_88 * V_89 )
{
F_135 ( V_89 , V_89 -> V_145 ) ;
}
static int F_91 ( struct V_88 * V_89 , struct V_88 * V_90 )
{
F_136 ( & V_90 -> V_102 ) ;
F_98 ( V_89 -> V_106 , F_99 ( V_90 ) ) ;
F_124 ( & V_90 -> V_102 ) ;
return 0 ;
}
static int T_1 F_137 ( char * V_18 )
{
V_146 =
( F_138 ( V_18 , NULL , 0 ) << V_147 ) &
V_148 ;
return 1 ;
}
static void F_139 ( struct V_88 * V_89 )
{
#ifdef F_140
F_141 ( & V_89 -> V_149 ) ;
V_89 -> V_150 = NULL ;
#endif
}
static void F_142 ( struct V_88 * V_89 , struct V_5 * V_151 )
{
#ifdef F_143
V_89 -> V_152 = V_151 ;
#endif
}
static struct V_88 * F_144 ( struct V_88 * V_89 , struct V_5 * V_151 ,
struct V_153 * V_154 )
{
V_89 -> V_112 = NULL ;
V_89 -> V_111 = V_155 ;
V_89 -> V_156 = 0 ;
F_82 ( & V_89 -> V_157 , 1 ) ;
F_82 ( & V_89 -> V_158 , 1 ) ;
F_145 ( & V_89 -> V_102 ) ;
F_106 ( & V_89 -> V_159 ) ;
V_89 -> V_160 = NULL ;
F_146 ( & V_89 -> V_161 , 0 ) ;
F_147 ( V_89 ) ;
V_89 -> V_141 = 0 ;
V_89 -> V_162 = 0 ;
V_89 -> V_163 = 0 ;
memset ( & V_89 -> V_164 , 0 , sizeof( V_89 -> V_164 ) ) ;
F_141 ( & V_89 -> V_165 ) ;
F_148 ( V_89 ) ;
F_139 ( V_89 ) ;
F_142 ( V_89 , V_151 ) ;
F_149 ( V_89 ) ;
F_150 ( V_89 ) ;
#if F_151 ( V_166 ) && ! V_167
V_89 -> V_168 = NULL ;
#endif
if ( V_48 -> V_89 ) {
V_89 -> V_27 = V_48 -> V_89 -> V_27 & V_169 ;
V_89 -> V_170 = V_48 -> V_89 -> V_170 & V_171 ;
} else {
V_89 -> V_27 = V_146 ;
V_89 -> V_170 = 0 ;
}
if ( F_131 ( V_89 ) )
goto V_172;
if ( F_152 ( V_151 , V_89 ) )
goto V_173;
V_89 -> V_154 = F_153 ( V_154 ) ;
return V_89 ;
V_173:
F_134 ( V_89 ) ;
V_172:
F_154 ( V_89 ) ;
return NULL ;
}
static void F_155 ( struct V_88 * V_89 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_174 ; V_14 ++ ) {
long V_175 = F_156 ( & V_89 -> V_164 . V_176 [ V_14 ] ) ;
if ( F_133 ( V_175 ) )
F_157 ( V_177 L_4
L_5 , V_89 , V_14 , V_175 ) ;
}
if ( F_156 ( & V_89 -> V_161 ) )
F_158 ( L_6 ,
F_156 ( & V_89 -> V_161 ) ) ;
if ( F_159 ( V_89 ) )
F_158 ( L_7 ,
F_159 ( V_89 ) ) ;
#if F_151 ( V_166 ) && ! V_167
F_160 ( V_89 -> V_168 , V_89 ) ;
#endif
}
struct V_88 * F_161 ( void )
{
struct V_88 * V_89 ;
V_89 = F_162 () ;
if ( ! V_89 )
return NULL ;
memset ( V_89 , 0 , sizeof( * V_89 ) ) ;
return F_144 ( V_89 , V_48 , F_163 () ) ;
}
void F_164 ( struct V_88 * V_89 )
{
F_35 ( V_89 == & V_178 ) ;
F_134 ( V_89 ) ;
F_165 ( V_89 ) ;
F_166 ( V_89 ) ;
F_155 ( V_89 ) ;
F_167 ( V_89 -> V_154 ) ;
F_154 ( V_89 ) ;
}
static inline void F_168 ( struct V_88 * V_89 )
{
F_169 ( F_50 ( & V_89 -> V_157 ) ) ;
F_170 ( V_89 ) ;
F_171 ( V_89 ) ;
F_172 ( V_89 ) ;
F_173 ( V_89 ) ;
F_174 ( V_89 ) ;
F_175 ( V_89 ) ;
F_176 ( V_89 , NULL ) ;
if ( ! F_177 ( & V_89 -> V_159 ) ) {
F_178 ( & V_179 ) ;
F_179 ( & V_89 -> V_159 ) ;
F_180 ( & V_179 ) ;
}
if ( V_89 -> V_180 )
F_181 ( V_89 -> V_180 -> V_181 ) ;
F_182 ( V_182 , & V_89 -> V_27 ) ;
F_183 ( V_89 ) ;
}
void F_184 ( struct V_88 * V_89 )
{
F_185 () ;
if ( F_46 ( & V_89 -> V_157 ) )
F_168 ( V_89 ) ;
}
static void F_186 ( struct V_183 * V_184 )
{
struct V_88 * V_89 = F_187 ( V_184 , struct V_88 , V_185 ) ;
F_168 ( V_89 ) ;
}
void F_188 ( struct V_88 * V_89 )
{
if ( F_46 ( & V_89 -> V_157 ) ) {
F_189 ( & V_89 -> V_185 , F_186 ) ;
F_190 ( & V_89 -> V_185 ) ;
}
}
void F_176 ( struct V_88 * V_89 , struct V_115 * V_186 )
{
struct V_115 * V_187 ;
V_187 = F_191 ( V_89 -> V_106 ) ;
if ( V_186 )
F_111 ( V_186 ) ;
F_192 ( V_89 -> V_106 , V_186 ) ;
if ( V_187 )
F_193 ( V_187 ) ;
}
struct V_115 * F_99 ( struct V_88 * V_89 )
{
struct V_115 * V_106 ;
F_194 () ;
V_106 = F_195 ( V_89 -> V_106 ) ;
if ( V_106 && ! F_196 ( V_106 ) )
V_106 = NULL ;
F_197 () ;
return V_106 ;
}
struct V_115 * F_198 ( struct V_5 * V_188 )
{
struct V_115 * V_106 = NULL ;
struct V_88 * V_89 ;
F_199 ( V_188 ) ;
V_89 = V_188 -> V_89 ;
if ( V_89 ) {
if ( ! ( V_188 -> V_27 & V_40 ) )
V_106 = F_99 ( V_89 ) ;
}
F_200 ( V_188 ) ;
return V_106 ;
}
struct V_88 * F_201 ( struct V_5 * V_188 )
{
struct V_88 * V_89 ;
F_199 ( V_188 ) ;
V_89 = V_188 -> V_89 ;
if ( V_89 ) {
if ( V_188 -> V_27 & V_40 )
V_89 = NULL ;
else
F_202 ( V_89 ) ;
}
F_200 ( V_188 ) ;
return V_89 ;
}
struct V_88 * F_203 ( struct V_5 * V_188 , unsigned int V_189 )
{
struct V_88 * V_89 ;
int V_76 ;
V_76 = F_204 ( & V_188 -> signal -> V_190 ) ;
if ( V_76 )
return F_205 ( V_76 ) ;
V_89 = F_201 ( V_188 ) ;
if ( V_89 && V_89 != V_48 -> V_89 &&
! F_206 ( V_188 , V_189 ) ) {
F_184 ( V_89 ) ;
V_89 = F_205 ( - V_191 ) ;
}
F_207 ( & V_188 -> signal -> V_190 ) ;
return V_89 ;
}
static void F_208 ( struct V_5 * V_6 )
{
struct V_192 * V_193 ;
F_199 ( V_6 ) ;
V_193 = V_6 -> V_194 ;
if ( F_209 ( V_193 ) ) {
V_6 -> V_194 = NULL ;
F_210 ( V_193 ) ;
}
F_200 ( V_6 ) ;
}
static int F_211 ( struct V_5 * V_195 ,
struct V_192 * V_193 )
{
int V_196 ;
F_212 () ;
V_196 = F_213 ( V_193 ) ;
F_214 () ;
if ( V_196 ) {
F_199 ( V_195 ) ;
V_195 -> V_194 = NULL ;
F_200 ( V_195 ) ;
}
F_215 ( V_195 ) ;
return V_196 ;
}
void F_216 ( struct V_5 * V_6 , struct V_88 * V_89 )
{
#ifdef F_217
if ( F_133 ( V_6 -> V_197 ) ) {
F_218 ( V_6 ) ;
V_6 -> V_197 = NULL ;
}
#ifdef F_219
if ( F_133 ( V_6 -> V_198 ) ) {
F_220 ( V_6 ) ;
V_6 -> V_198 = NULL ;
}
#endif
if ( F_133 ( ! F_177 ( & V_6 -> V_199 ) ) )
F_221 ( V_6 ) ;
#endif
F_222 ( V_6 ) ;
F_223 ( V_6 , V_89 ) ;
if ( V_6 -> V_200 ) {
if ( ! ( V_6 -> signal -> V_27 & V_201 ) &&
F_50 ( & V_89 -> V_157 ) > 1 ) {
F_224 ( 0 , V_6 -> V_200 ) ;
F_225 ( V_6 -> V_200 , V_202 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_200 = NULL ;
}
if ( V_6 -> V_194 )
F_208 ( V_6 ) ;
}
static struct V_88 * F_226 ( struct V_5 * V_6 )
{
struct V_88 * V_89 , * V_90 = V_48 -> V_89 ;
int V_76 ;
V_89 = F_162 () ;
if ( ! V_89 )
goto V_120;
memcpy ( V_89 , V_90 , sizeof( * V_89 ) ) ;
if ( ! F_144 ( V_89 , V_6 , V_89 -> V_154 ) )
goto V_120;
V_76 = F_91 ( V_89 , V_90 ) ;
if ( V_76 )
goto V_203;
V_89 -> V_204 = F_227 ( V_89 ) ;
V_89 -> V_205 = V_89 -> V_107 ;
if ( V_89 -> V_180 && ! F_228 ( V_89 -> V_180 -> V_181 ) )
goto V_203;
return V_89 ;
V_203:
V_89 -> V_180 = NULL ;
F_184 ( V_89 ) ;
V_120:
return NULL ;
}
static int F_229 ( unsigned long V_206 , struct V_5 * V_6 )
{
struct V_88 * V_89 , * V_90 ;
int V_99 ;
V_6 -> V_207 = V_6 -> V_208 = 0 ;
V_6 -> V_209 = V_6 -> V_210 = 0 ;
#ifdef F_230
V_6 -> V_211 = V_6 -> V_209 + V_6 -> V_210 ;
#endif
V_6 -> V_89 = NULL ;
V_6 -> V_212 = NULL ;
V_90 = V_48 -> V_89 ;
if ( ! V_90 )
return 0 ;
F_231 ( V_6 ) ;
if ( V_206 & V_213 ) {
F_202 ( V_90 ) ;
V_89 = V_90 ;
goto V_214;
}
V_99 = - V_144 ;
V_89 = F_226 ( V_6 ) ;
if ( ! V_89 )
goto V_120;
V_214:
V_6 -> V_89 = V_89 ;
V_6 -> V_212 = V_89 ;
return 0 ;
V_120:
return V_99 ;
}
static int F_232 ( unsigned long V_206 , struct V_5 * V_6 )
{
struct V_215 * V_216 = V_48 -> V_216 ;
if ( V_206 & V_217 ) {
F_178 ( & V_216 -> V_218 ) ;
if ( V_216 -> V_219 ) {
F_180 ( & V_216 -> V_218 ) ;
return - V_220 ;
}
V_216 -> V_221 ++ ;
F_180 ( & V_216 -> V_218 ) ;
return 0 ;
}
V_6 -> V_216 = F_233 ( V_216 ) ;
if ( ! V_6 -> V_216 )
return - V_144 ;
return 0 ;
}
static int F_234 ( unsigned long V_206 , struct V_5 * V_6 )
{
struct V_222 * V_223 , * V_224 ;
int error = 0 ;
V_223 = V_48 -> V_225 ;
if ( ! V_223 )
goto V_113;
if ( V_206 & V_226 ) {
F_114 ( & V_223 -> V_176 ) ;
goto V_113;
}
V_224 = F_235 ( V_223 , & error ) ;
if ( ! V_224 )
goto V_113;
V_6 -> V_225 = V_224 ;
error = 0 ;
V_113:
return error ;
}
static int F_236 ( unsigned long V_206 , struct V_5 * V_6 )
{
#ifdef F_237
struct V_227 * V_228 = V_48 -> V_227 ;
struct V_227 * V_229 ;
if ( ! V_228 )
return 0 ;
if ( V_206 & V_230 ) {
F_238 ( V_228 ) ;
V_6 -> V_227 = V_228 ;
} else if ( F_239 ( V_228 -> V_231 ) ) {
V_229 = F_240 ( V_6 , V_9 , V_77 ) ;
if ( F_133 ( ! V_229 ) )
return - V_144 ;
V_229 -> V_231 = V_228 -> V_231 ;
F_241 ( V_229 ) ;
}
#endif
return 0 ;
}
static int F_242 ( unsigned long V_206 , struct V_5 * V_6 )
{
struct V_232 * V_42 ;
if ( V_206 & V_233 ) {
F_114 ( & V_48 -> V_234 -> V_176 ) ;
return 0 ;
}
V_42 = F_105 ( V_235 , V_9 ) ;
F_192 ( V_6 -> V_234 , V_42 ) ;
if ( ! V_42 )
return - V_144 ;
F_82 ( & V_42 -> V_176 , 1 ) ;
memcpy ( V_42 -> V_236 , V_48 -> V_234 -> V_236 , sizeof( V_42 -> V_236 ) ) ;
return 0 ;
}
void F_243 ( struct V_232 * V_234 )
{
if ( F_46 ( & V_234 -> V_176 ) ) {
F_244 ( V_234 ) ;
F_10 ( V_235 , V_234 ) ;
}
}
static void F_245 ( struct V_41 * V_42 )
{
unsigned long V_237 ;
V_237 = F_246 ( V_42 -> V_62 [ V_238 ] . V_64 ) ;
if ( V_237 != V_239 ) {
V_42 -> V_240 . V_241 = V_237 * V_242 ;
V_42 -> V_243 . V_244 = true ;
}
F_106 ( & V_42 -> V_245 [ 0 ] ) ;
F_106 ( & V_42 -> V_245 [ 1 ] ) ;
F_106 ( & V_42 -> V_245 [ 2 ] ) ;
}
static inline void F_245 ( struct V_41 * V_42 ) { }
static int F_247 ( unsigned long V_206 , struct V_5 * V_6 )
{
struct V_41 * V_42 ;
if ( V_206 & V_246 )
return 0 ;
V_42 = F_248 ( V_44 , V_9 ) ;
V_6 -> signal = V_42 ;
if ( ! V_42 )
return - V_144 ;
V_42 -> V_247 = 1 ;
F_82 ( & V_42 -> V_248 , 1 ) ;
F_82 ( & V_42 -> V_45 , 1 ) ;
V_42 -> V_249 = (struct V_250 ) F_249 ( V_6 -> V_251 ) ;
V_6 -> V_251 = (struct V_250 ) F_249 ( V_42 -> V_249 ) ;
F_250 ( & V_42 -> V_252 ) ;
V_42 -> V_253 = V_6 ;
F_251 ( & V_42 -> V_254 ) ;
F_252 ( & V_42 -> V_255 ) ;
F_253 ( & V_42 -> V_256 ) ;
#ifdef F_254
F_106 ( & V_42 -> V_257 ) ;
F_255 ( & V_42 -> V_258 , V_259 , V_260 ) ;
V_42 -> V_258 . V_261 = V_262 ;
#endif
F_199 ( V_48 -> V_263 ) ;
memcpy ( V_42 -> V_62 , V_48 -> signal -> V_62 , sizeof V_42 -> V_62 ) ;
F_200 ( V_48 -> V_263 ) ;
F_245 ( V_42 ) ;
F_256 ( V_42 ) ;
F_257 ( V_42 ) ;
V_42 -> V_264 = V_48 -> signal -> V_264 ;
V_42 -> V_265 = V_48 -> signal -> V_265 ;
F_258 ( & V_42 -> V_190 ) ;
return 0 ;
}
static void F_259 ( struct V_5 * V_151 )
{
#ifdef F_83
F_260 ( & V_48 -> V_234 -> V_266 ) ;
F_261 ( V_48 ) ;
V_151 -> V_80 = V_48 -> V_80 ;
if ( F_262 ( V_48 ) )
F_263 ( V_151 ) ;
if ( V_151 -> V_80 . V_189 != V_267 )
F_264 ( V_151 , V_268 ) ;
#endif
}
static void F_265 ( struct V_5 * V_151 )
{
F_266 ( & V_151 -> V_269 ) ;
#ifdef F_267
V_151 -> V_270 = V_155 ;
V_151 -> V_271 = NULL ;
V_151 -> V_272 = NULL ;
V_151 -> V_273 = NULL ;
#endif
}
static void F_268 ( struct V_5 * V_6 )
{
V_6 -> V_240 . V_241 = 0 ;
V_6 -> V_240 . V_274 = 0 ;
V_6 -> V_240 . V_275 = 0 ;
F_106 ( & V_6 -> V_245 [ 0 ] ) ;
F_106 ( & V_6 -> V_245 [ 1 ] ) ;
F_106 ( & V_6 -> V_245 [ 2 ] ) ;
}
static inline void F_268 ( struct V_5 * V_6 ) { }
static inline void
F_269 ( struct V_5 * V_188 , enum V_276 type , struct V_277 * V_277 )
{
V_188 -> V_278 [ type ] . V_277 = V_277 ;
}
static inline void F_270 ( struct V_5 * V_151 )
{
#ifdef F_271
V_151 -> V_279 = 0 ;
V_151 -> V_280 . V_18 = 0 ;
V_151 -> V_281 = NULL ;
F_106 ( & V_151 -> V_282 ) ;
#endif
#ifdef F_272
V_151 -> V_283 = false ;
F_106 ( & V_151 -> V_284 ) ;
V_151 -> V_285 = - 1 ;
#endif
}
inline void F_273 ( struct V_286 * V_287 )
{
enum V_276 type ;
for ( type = V_288 ; type < V_289 ; ++ type ) {
F_274 ( & V_287 [ type ] . V_7 ) ;
V_287 [ type ] . V_277 = & V_290 ;
}
}
struct V_5 * F_275 ( int V_2 )
{
struct V_5 * V_188 ;
V_188 = F_276 ( V_213 , 0 , 0 , NULL , & V_290 , 0 , 0 ,
F_277 ( V_2 ) ) ;
if ( ! F_278 ( V_188 ) ) {
F_273 ( V_188 -> V_278 ) ;
F_279 ( V_188 , V_2 ) ;
}
return V_188 ;
}
long F_280 ( unsigned long V_206 ,
unsigned long V_291 ,
unsigned long V_292 ,
int T_4 * V_293 ,
int T_4 * V_294 ,
unsigned long V_295 )
{
struct V_5 * V_151 ;
int V_296 = 0 ;
long V_297 ;
if ( ! ( V_206 & V_298 ) ) {
if ( V_206 & V_299 )
V_296 = V_300 ;
else if ( ( V_206 & V_301 ) != V_302 )
V_296 = V_303 ;
else
V_296 = V_304 ;
if ( F_209 ( ! F_281 ( V_48 , V_296 ) ) )
V_296 = 0 ;
}
V_151 = F_276 ( V_206 , V_291 , V_292 ,
V_294 , NULL , V_296 , V_295 , V_77 ) ;
F_282 () ;
if ( ! F_278 ( V_151 ) ) {
struct V_192 V_193 ;
struct V_277 * V_277 ;
F_283 ( V_48 , V_151 ) ;
V_277 = F_284 ( V_151 , V_288 ) ;
V_297 = F_285 ( V_277 ) ;
if ( V_206 & V_305 )
F_224 ( V_297 , V_293 ) ;
if ( V_206 & V_299 ) {
V_151 -> V_194 = & V_193 ;
F_286 ( & V_193 ) ;
F_287 ( V_151 ) ;
}
F_288 ( V_151 ) ;
if ( F_133 ( V_296 ) )
F_289 ( V_296 , V_277 ) ;
if ( V_206 & V_299 ) {
if ( ! F_211 ( V_151 , & V_193 ) )
F_289 ( V_306 , V_277 ) ;
}
F_290 ( V_277 ) ;
} else {
V_297 = F_291 ( V_151 ) ;
}
return V_297 ;
}
long F_292 ( unsigned long V_206 ,
unsigned long V_291 ,
unsigned long V_292 ,
int T_4 * V_293 ,
int T_4 * V_294 )
{
return F_280 ( V_206 , V_291 , V_292 ,
V_293 , V_294 , 0 ) ;
}
T_5 F_293 ( int (* F_294)( void * ) , void * V_307 , unsigned long V_27 )
{
return F_280 ( V_27 | V_213 | V_298 , ( unsigned long ) F_294 ,
( unsigned long ) V_307 , NULL , NULL , 0 ) ;
}
void F_295 ( struct V_5 * V_308 , T_6 V_309 , void * V_310 )
{
struct V_5 * V_311 , * V_312 , * V_195 ;
int V_313 ;
F_296 ( & V_1 ) ;
V_311 = V_308 = V_308 -> V_263 ;
V_314:
F_297 (leader, parent) {
F_298 (child, &parent->children, sibling) {
V_313 = V_309 ( V_195 , V_310 ) ;
if ( V_313 ) {
if ( V_313 < 0 )
goto V_113;
V_311 = V_195 ;
goto V_314;
}
V_315:
;
}
}
if ( V_311 != V_308 ) {
V_195 = V_311 ;
V_312 = V_195 -> V_316 ;
V_311 = V_312 -> V_263 ;
goto V_315;
}
V_113:
F_299 ( & V_1 ) ;
}
static void F_300 ( void * V_310 )
{
struct V_232 * V_234 = V_310 ;
F_141 ( & V_234 -> V_266 ) ;
F_250 ( & V_234 -> V_317 ) ;
}
void T_1 F_301 ( void )
{
V_235 = F_34 ( L_8 ,
sizeof( struct V_232 ) , 0 ,
V_318 | V_58 | V_319 |
V_59 | V_60 , F_300 ) ;
V_44 = F_34 ( L_9 ,
sizeof( struct V_41 ) , 0 ,
V_318 | V_58 | V_59 | V_60 ,
NULL ) ;
V_320 = F_34 ( L_10 ,
sizeof( struct V_222 ) , 0 ,
V_318 | V_58 | V_59 | V_60 ,
NULL ) ;
V_321 = F_34 ( L_11 ,
sizeof( struct V_215 ) , 0 ,
V_318 | V_58 | V_59 | V_60 ,
NULL ) ;
V_322 = F_34 ( L_12 ,
sizeof( struct V_88 ) , V_323 ,
V_318 | V_58 | V_59 | V_60 ,
NULL ) ;
V_121 = F_302 ( V_91 , V_58 | V_60 ) ;
F_303 () ;
F_304 () ;
}
static int F_305 ( unsigned long V_324 )
{
if ( V_324 & ~ ( V_246 | V_217 | V_325 | V_233 |
V_213 | V_226 | V_326 |
V_327 | V_328 | V_329 |
V_330 | V_331 | V_332 ) )
return - V_333 ;
if ( V_324 & ( V_246 | V_233 | V_213 ) ) {
if ( ! F_306 ( V_48 ) )
return - V_333 ;
}
if ( V_324 & ( V_233 | V_213 ) ) {
if ( F_50 ( & V_48 -> V_234 -> V_176 ) > 1 )
return - V_333 ;
}
if ( V_324 & V_213 ) {
if ( ! F_307 () )
return - V_333 ;
}
return 0 ;
}
static int F_308 ( unsigned long V_324 , struct V_215 * * V_334 )
{
struct V_215 * V_216 = V_48 -> V_216 ;
if ( ! ( V_324 & V_217 ) || ! V_216 )
return 0 ;
if ( V_216 -> V_221 == 1 )
return 0 ;
* V_334 = F_233 ( V_216 ) ;
if ( ! * V_334 )
return - V_144 ;
return 0 ;
}
static int F_309 ( unsigned long V_324 , struct V_222 * * V_335 )
{
struct V_222 * V_336 = V_48 -> V_225 ;
int error = 0 ;
if ( ( V_324 & V_226 ) &&
( V_336 && F_50 ( & V_336 -> V_176 ) > 1 ) ) {
* V_335 = F_235 ( V_336 , & error ) ;
if ( ! * V_335 )
return error ;
}
return 0 ;
}
int F_310 ( struct V_222 * * V_337 )
{
struct V_5 * V_188 = V_48 ;
struct V_222 * V_338 = NULL ;
int error ;
error = F_309 ( V_226 , & V_338 ) ;
if ( error || ! V_338 ) {
* V_337 = NULL ;
return error ;
}
* V_337 = V_188 -> V_225 ;
F_199 ( V_188 ) ;
V_188 -> V_225 = V_338 ;
F_200 ( V_188 ) ;
return 0 ;
}
int F_311 ( struct V_339 * V_340 , int V_341 ,
void T_4 * V_342 , T_7 * V_343 , T_8 * V_344 )
{
struct V_339 V_345 ;
int V_346 ;
int V_50 = V_53 ;
int V_347 = V_54 ;
int V_348 = V_52 ;
V_345 = * V_340 ;
V_345 . V_310 = & V_50 ;
V_345 . V_349 = & V_347 ;
V_345 . V_350 = & V_348 ;
V_346 = F_312 ( & V_345 , V_341 , V_342 , V_343 , V_344 ) ;
if ( V_346 || ! V_341 )
return V_346 ;
F_68 ( V_50 ) ;
return 0 ;
}
