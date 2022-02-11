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
static unsigned long * F_12 ( struct V_5 * V_6 , int V_7 )
{
#ifdef F_13
void * V_10 ;
int V_11 ;
F_14 () ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
struct V_13 * V_14 = F_15 ( V_15 [ V_11 ] ) ;
if ( ! V_14 )
continue;
F_16 ( V_15 [ V_11 ] , NULL ) ;
V_6 -> V_16 = V_14 ;
F_17 () ;
return V_14 -> V_17 ;
}
F_17 () ;
V_10 = F_18 ( V_18 , V_18 ,
V_19 , V_20 ,
V_21 | V_22 ,
V_23 ,
0 , V_7 , F_19 ( 0 ) ) ;
if ( V_10 )
V_6 -> V_16 = F_20 ( V_10 ) ;
return V_10 ;
#else
struct V_24 * V_24 = F_21 ( V_7 , V_21 ,
V_25 ) ;
return V_24 ? F_22 ( V_24 ) : NULL ;
#endif
}
static inline void F_23 ( struct V_5 * V_6 )
{
#ifdef F_13
if ( F_24 ( V_6 ) ) {
unsigned long V_26 ;
int V_11 ;
F_25 ( V_26 ) ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( F_15 ( V_15 [ V_11 ] ) )
continue;
F_16 ( V_15 [ V_11 ] , V_6 -> V_16 ) ;
F_26 ( V_26 ) ;
return;
}
F_26 ( V_26 ) ;
F_27 ( V_6 -> V_10 ) ;
return;
}
#endif
F_28 ( F_29 ( V_6 -> V_10 ) , V_25 ) ;
}
static unsigned long * F_12 ( struct V_5 * V_6 ,
int V_7 )
{
return F_8 ( V_27 , V_21 , V_7 ) ;
}
static void F_23 ( struct V_5 * V_6 )
{
F_10 ( V_27 , V_6 -> V_10 ) ;
}
void F_30 ( void )
{
V_27 = F_31 ( L_1 , V_18 ,
V_18 , 0 , NULL ) ;
F_32 ( V_27 == NULL ) ;
}
static void F_33 ( struct V_5 * V_6 , int V_28 )
{
void * V_10 = F_34 ( V_6 ) ;
struct V_13 * V_29 = F_24 ( V_6 ) ;
F_35 ( F_36 ( F_13 ) && V_30 % 1024 != 0 ) ;
if ( V_29 ) {
int V_11 ;
F_32 ( V_29 -> V_31 != V_18 / V_30 ) ;
for ( V_11 = 0 ; V_11 < V_18 / V_30 ; V_11 ++ ) {
F_37 ( F_38 ( V_29 -> V_32 [ V_11 ] ) ,
V_33 ,
V_30 / 1024 * V_28 ) ;
}
F_39 ( V_29 -> V_32 [ 0 ] , V_34 ,
V_28 * ( V_18 / 1024 ) ) ;
} else {
struct V_24 * V_35 = F_29 ( V_10 ) ;
F_37 ( F_38 ( V_35 ) , V_33 ,
V_18 / 1024 * V_28 ) ;
F_39 ( V_35 , V_34 ,
V_28 * ( V_18 / 1024 ) ) ;
}
}
static void F_40 ( struct V_5 * V_6 )
{
if ( F_41 ( V_6 -> V_36 != V_37 ) )
return;
F_33 ( V_6 , - 1 ) ;
F_11 ( V_6 -> V_10 ) ;
F_23 ( V_6 ) ;
V_6 -> V_10 = NULL ;
#ifdef F_13
V_6 -> V_16 = NULL ;
#endif
}
void F_42 ( struct V_5 * V_6 )
{
if ( F_43 ( & V_6 -> V_38 ) )
F_40 ( V_6 ) ;
}
void F_44 ( struct V_5 * V_6 )
{
#ifndef F_45
F_40 ( V_6 ) ;
#else
F_46 ( F_47 ( & V_6 -> V_38 ) != 0 ) ;
#endif
F_48 ( V_6 ) ;
F_49 ( V_6 ) ;
F_50 ( V_6 ) ;
F_6 ( V_6 ) ;
if ( V_6 -> V_26 & V_39 )
F_51 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_52 ( struct V_40 * V_41 )
{
F_53 ( V_41 ) ;
F_54 ( V_41 ) ;
if ( V_41 -> V_42 )
F_55 ( V_41 -> V_42 ) ;
F_10 ( V_43 , V_41 ) ;
}
static inline void F_56 ( struct V_40 * V_41 )
{
if ( F_43 ( & V_41 -> V_44 ) )
F_52 ( V_41 ) ;
}
void F_57 ( struct V_5 * V_6 )
{
F_41 ( ! V_6 -> V_45 ) ;
F_41 ( F_47 ( & V_6 -> V_46 ) ) ;
F_41 ( V_6 == V_47 ) ;
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
static void F_65 ( unsigned int V_48 )
{
T_2 V_49 ;
if ( F_66 ( V_50 ) + F_66 ( V_30 ) > 64 )
V_49 = V_51 ;
else
V_49 = F_67 ( ( T_2 ) V_50 * ( T_2 ) V_30 ,
( T_2 ) V_18 * 8UL ) ;
if ( V_49 > V_48 )
V_49 = V_48 ;
V_52 = F_68 ( T_2 , V_49 , V_53 , V_51 ) ;
}
void T_1 F_69 ( void )
{
int V_11 ;
#ifndef F_70
#ifndef F_71
#define F_71 L1_CACHE_BYTES
#endif
V_8 = F_31 ( L_2 ,
V_54 , F_71 ,
V_55 | V_56 | V_57 , NULL ) ;
#endif
F_64 () ;
F_65 ( V_51 ) ;
V_58 . signal -> V_59 [ V_60 ] . V_61 = V_52 / 2 ;
V_58 . signal -> V_59 [ V_60 ] . V_62 = V_52 / 2 ;
V_58 . signal -> V_59 [ V_63 ] =
V_58 . signal -> V_59 [ V_60 ] ;
for ( V_11 = 0 ; V_11 < V_64 ; V_11 ++ ) {
V_65 . V_66 [ V_11 ] = V_52 / 2 ;
}
}
int __weak F_72 ( struct V_5 * V_67 ,
struct V_5 * V_68 )
{
* V_67 = * V_68 ;
return 0 ;
}
void F_73 ( struct V_5 * V_6 )
{
unsigned long * V_69 ;
V_69 = F_74 ( V_6 ) ;
* V_69 = V_70 ;
}
static struct V_5 * F_75 ( struct V_5 * V_71 , int V_7 )
{
struct V_5 * V_6 ;
unsigned long * V_10 ;
struct V_13 * V_16 ;
int V_72 ;
if ( V_7 == V_73 )
V_7 = F_76 ( V_71 ) ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_10 = F_12 ( V_6 , V_7 ) ;
if ( ! V_10 )
goto V_74;
V_16 = F_24 ( V_6 ) ;
V_72 = F_72 ( V_6 , V_71 ) ;
V_6 -> V_10 = V_10 ;
#ifdef F_13
V_6 -> V_16 = V_16 ;
#endif
#ifdef F_45
F_77 ( & V_6 -> V_38 , 1 ) ;
#endif
if ( V_72 )
goto V_75;
#ifdef F_78
V_6 -> V_76 . V_77 = NULL ;
#endif
F_79 ( V_6 , V_71 ) ;
F_80 ( V_6 ) ;
F_81 ( V_6 ) ;
F_73 ( V_6 ) ;
#ifdef F_82
V_6 -> V_78 = F_83 () ;
#endif
F_77 ( & V_6 -> V_46 , 2 ) ;
#ifdef F_84
V_6 -> V_79 = 0 ;
#endif
V_6 -> V_80 = NULL ;
V_6 -> V_81 . V_24 = NULL ;
V_6 -> V_82 . V_83 = NULL ;
F_33 ( V_6 , 1 ) ;
F_85 ( V_6 ) ;
return V_6 ;
V_75:
F_23 ( V_6 ) ;
V_74:
F_9 ( V_6 ) ;
return NULL ;
}
static T_3 int F_86 ( struct V_84 * V_85 ,
struct V_84 * V_86 )
{
struct V_87 * V_88 , * V_89 , * V_90 , * * V_91 ;
struct V_92 * * V_93 , * V_94 ;
int V_95 ;
unsigned long V_96 ;
F_87 () ;
if ( F_88 ( & V_86 -> V_97 ) ) {
V_95 = - V_98 ;
goto V_99;
}
F_89 ( V_86 ) ;
F_90 ( V_86 , V_85 ) ;
F_91 ( & V_85 -> V_97 , V_100 ) ;
F_92 ( V_85 -> V_101 , F_93 ( V_86 ) ) ;
V_85 -> V_102 = V_86 -> V_102 ;
V_85 -> V_103 = V_86 -> V_103 ;
V_85 -> V_104 = V_86 -> V_104 ;
V_85 -> V_105 = V_86 -> V_105 ;
V_93 = & V_85 -> V_106 . V_92 ;
V_94 = NULL ;
V_91 = & V_85 -> V_107 ;
V_95 = F_94 ( V_85 , V_86 ) ;
if ( V_95 )
goto V_108;
V_95 = F_95 ( V_85 , V_86 ) ;
if ( V_95 )
goto V_108;
V_90 = NULL ;
for ( V_88 = V_86 -> V_107 ; V_88 ; V_88 = V_88 -> V_109 ) {
struct V_110 * V_110 ;
if ( V_88 -> V_111 & V_112 ) {
F_96 ( V_85 , V_88 -> V_111 , - F_97 ( V_88 ) ) ;
continue;
}
V_96 = 0 ;
if ( V_88 -> V_111 & V_113 ) {
unsigned long V_114 = F_97 ( V_88 ) ;
if ( F_98 ( V_86 , V_114 ) )
goto V_115;
V_96 = V_114 ;
}
V_89 = F_99 ( V_116 , V_9 ) ;
if ( ! V_89 )
goto V_115;
* V_89 = * V_88 ;
F_100 ( & V_89 -> V_117 ) ;
V_95 = F_101 ( V_88 , V_89 ) ;
if ( V_95 )
goto V_118;
V_89 -> V_119 = V_85 ;
if ( F_102 ( V_89 , V_88 ) )
goto V_120;
V_89 -> V_111 &=
~ ( V_121 | V_122 | V_123 | V_124 ) ;
V_89 -> V_109 = V_89 -> V_125 = NULL ;
V_89 -> V_126 = V_127 ;
V_110 = V_89 -> V_128 ;
if ( V_110 ) {
struct V_129 * V_129 = F_103 ( V_110 ) ;
struct V_130 * V_131 = V_110 -> V_132 ;
F_104 ( V_110 ) ;
if ( V_89 -> V_111 & V_133 )
F_105 ( & V_129 -> V_134 ) ;
F_106 ( V_131 ) ;
if ( V_89 -> V_111 & V_135 )
F_107 ( & V_131 -> V_136 ) ;
F_108 ( V_131 ) ;
F_109 ( V_89 , V_88 ,
& V_131 -> V_137 ) ;
F_110 ( V_131 ) ;
F_111 ( V_131 ) ;
}
if ( F_112 ( V_89 ) )
F_113 ( V_89 ) ;
* V_91 = V_89 ;
V_91 = & V_89 -> V_109 ;
V_89 -> V_125 = V_90 ;
V_90 = V_89 ;
F_114 ( V_85 , V_89 , V_93 , V_94 ) ;
V_93 = & V_89 -> V_138 . V_139 ;
V_94 = & V_89 -> V_138 ;
V_85 -> V_140 ++ ;
V_95 = F_115 ( V_85 , V_86 , V_88 ) ;
if ( V_89 -> V_141 && V_89 -> V_141 -> V_142 )
V_89 -> V_141 -> V_142 ( V_89 ) ;
if ( V_95 )
goto V_108;
}
F_116 ( V_86 , V_85 ) ;
V_95 = 0 ;
V_108:
F_117 ( & V_85 -> V_97 ) ;
F_118 ( V_86 ) ;
F_117 ( & V_86 -> V_97 ) ;
V_99:
F_119 () ;
return V_95 ;
V_120:
F_120 ( F_121 ( V_89 ) ) ;
V_118:
F_10 ( V_116 , V_89 ) ;
V_115:
V_95 = - V_143 ;
F_122 ( V_96 ) ;
goto V_108;
}
static inline int F_123 ( struct V_84 * V_85 )
{
V_85 -> V_144 = F_124 ( V_85 ) ;
if ( F_125 ( ! V_85 -> V_144 ) )
return - V_143 ;
return 0 ;
}
static inline void F_126 ( struct V_84 * V_85 )
{
F_127 ( V_85 , V_85 -> V_144 ) ;
}
static int F_86 ( struct V_84 * V_85 , struct V_84 * V_86 )
{
F_128 ( & V_86 -> V_97 ) ;
F_92 ( V_85 -> V_101 , F_93 ( V_86 ) ) ;
F_117 ( & V_86 -> V_97 ) ;
return 0 ;
}
static int T_1 F_129 ( char * V_14 )
{
V_145 =
( F_130 ( V_14 , NULL , 0 ) << V_146 ) &
V_147 ;
return 1 ;
}
static void F_131 ( struct V_84 * V_85 )
{
#ifdef F_132
F_133 ( & V_85 -> V_148 ) ;
V_85 -> V_149 = NULL ;
#endif
}
static void F_134 ( struct V_84 * V_85 , struct V_5 * V_150 )
{
#ifdef F_135
V_85 -> V_151 = V_150 ;
#endif
}
static struct V_84 * F_136 ( struct V_84 * V_85 , struct V_5 * V_150 ,
struct V_152 * V_153 )
{
V_85 -> V_107 = NULL ;
V_85 -> V_106 = V_154 ;
V_85 -> V_155 = 0 ;
F_77 ( & V_85 -> V_156 , 1 ) ;
F_77 ( & V_85 -> V_157 , 1 ) ;
F_137 ( & V_85 -> V_97 ) ;
F_100 ( & V_85 -> V_158 ) ;
V_85 -> V_159 = NULL ;
F_138 ( & V_85 -> V_160 , 0 ) ;
F_139 ( V_85 ) ;
V_85 -> V_140 = 0 ;
V_85 -> V_161 = 0 ;
V_85 -> V_162 = 0 ;
memset ( & V_85 -> V_163 , 0 , sizeof( V_85 -> V_163 ) ) ;
F_133 ( & V_85 -> V_164 ) ;
F_140 ( V_85 ) ;
F_131 ( V_85 ) ;
F_134 ( V_85 , V_150 ) ;
F_141 ( V_85 ) ;
F_142 ( V_85 ) ;
#if F_143 ( V_165 ) && ! V_166
V_85 -> V_167 = NULL ;
#endif
if ( V_47 -> V_85 ) {
V_85 -> V_26 = V_47 -> V_85 -> V_26 & V_168 ;
V_85 -> V_169 = V_47 -> V_85 -> V_169 & V_170 ;
} else {
V_85 -> V_26 = V_145 ;
V_85 -> V_169 = 0 ;
}
if ( F_123 ( V_85 ) )
goto V_171;
if ( F_144 ( V_150 , V_85 ) )
goto V_172;
V_85 -> V_153 = F_145 ( V_153 ) ;
return V_85 ;
V_172:
F_126 ( V_85 ) ;
V_171:
F_146 ( V_85 ) ;
return NULL ;
}
static void F_147 ( struct V_84 * V_85 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_173 ; V_11 ++ ) {
long V_174 = F_148 ( & V_85 -> V_163 . V_175 [ V_11 ] ) ;
if ( F_125 ( V_174 ) )
F_149 ( V_176 L_3
L_4 , V_85 , V_11 , V_174 ) ;
}
if ( F_148 ( & V_85 -> V_160 ) )
F_150 ( L_5 ,
F_148 ( & V_85 -> V_160 ) ) ;
if ( F_151 ( V_85 ) )
F_150 ( L_6 ,
F_151 ( V_85 ) ) ;
#if F_143 ( V_165 ) && ! V_166
F_152 ( V_85 -> V_167 , V_85 ) ;
#endif
}
struct V_84 * F_153 ( void )
{
struct V_84 * V_85 ;
V_85 = F_154 () ;
if ( ! V_85 )
return NULL ;
memset ( V_85 , 0 , sizeof( * V_85 ) ) ;
return F_136 ( V_85 , V_47 , F_155 () ) ;
}
void F_156 ( struct V_84 * V_85 )
{
F_32 ( V_85 == & V_177 ) ;
F_126 ( V_85 ) ;
F_157 ( V_85 ) ;
F_158 ( V_85 ) ;
F_147 ( V_85 ) ;
F_159 ( V_85 -> V_153 ) ;
F_146 ( V_85 ) ;
}
static inline void F_160 ( struct V_84 * V_85 )
{
F_161 ( F_47 ( & V_85 -> V_156 ) ) ;
F_162 ( V_85 ) ;
F_163 ( V_85 ) ;
F_164 ( V_85 ) ;
F_165 ( V_85 ) ;
F_166 ( V_85 ) ;
F_167 ( V_85 ) ;
F_168 ( V_85 , NULL ) ;
if ( ! F_169 ( & V_85 -> V_158 ) ) {
F_170 ( & V_178 ) ;
F_171 ( & V_85 -> V_158 ) ;
F_172 ( & V_178 ) ;
}
if ( V_85 -> V_179 )
F_173 ( V_85 -> V_179 -> V_180 ) ;
F_174 ( V_181 , & V_85 -> V_26 ) ;
F_175 ( V_85 ) ;
}
void F_176 ( struct V_84 * V_85 )
{
F_177 () ;
if ( F_43 ( & V_85 -> V_156 ) )
F_160 ( V_85 ) ;
}
static void F_178 ( struct V_182 * V_183 )
{
struct V_84 * V_85 = F_179 ( V_183 , struct V_84 , V_184 ) ;
F_160 ( V_85 ) ;
}
void F_180 ( struct V_84 * V_85 )
{
if ( F_43 ( & V_85 -> V_156 ) ) {
F_181 ( & V_85 -> V_184 , F_178 ) ;
F_182 ( & V_85 -> V_184 ) ;
}
}
void F_168 ( struct V_84 * V_85 , struct V_110 * V_185 )
{
struct V_110 * V_186 ;
V_186 = F_183 ( V_85 -> V_101 ) ;
if ( V_185 )
F_104 ( V_185 ) ;
F_184 ( V_85 -> V_101 , V_185 ) ;
if ( V_186 )
F_185 ( V_186 ) ;
}
struct V_110 * F_93 ( struct V_84 * V_85 )
{
struct V_110 * V_101 ;
F_186 () ;
V_101 = F_187 ( V_85 -> V_101 ) ;
if ( V_101 && ! F_188 ( V_101 ) )
V_101 = NULL ;
F_189 () ;
return V_101 ;
}
struct V_110 * F_190 ( struct V_5 * V_187 )
{
struct V_110 * V_101 = NULL ;
struct V_84 * V_85 ;
F_191 ( V_187 ) ;
V_85 = V_187 -> V_85 ;
if ( V_85 ) {
if ( ! ( V_187 -> V_26 & V_39 ) )
V_101 = F_93 ( V_85 ) ;
}
F_192 ( V_187 ) ;
return V_101 ;
}
struct V_84 * F_193 ( struct V_5 * V_187 )
{
struct V_84 * V_85 ;
F_191 ( V_187 ) ;
V_85 = V_187 -> V_85 ;
if ( V_85 ) {
if ( V_187 -> V_26 & V_39 )
V_85 = NULL ;
else
F_107 ( & V_85 -> V_156 ) ;
}
F_192 ( V_187 ) ;
return V_85 ;
}
struct V_84 * F_194 ( struct V_5 * V_187 , unsigned int V_188 )
{
struct V_84 * V_85 ;
int V_72 ;
V_72 = F_195 ( & V_187 -> signal -> V_189 ) ;
if ( V_72 )
return F_196 ( V_72 ) ;
V_85 = F_193 ( V_187 ) ;
if ( V_85 && V_85 != V_47 -> V_85 &&
! F_197 ( V_187 , V_188 ) ) {
F_176 ( V_85 ) ;
V_85 = F_196 ( - V_190 ) ;
}
F_198 ( & V_187 -> signal -> V_189 ) ;
return V_85 ;
}
static void F_199 ( struct V_5 * V_6 )
{
struct V_191 * V_192 ;
F_191 ( V_6 ) ;
V_192 = V_6 -> V_193 ;
if ( F_200 ( V_192 ) ) {
V_6 -> V_193 = NULL ;
F_201 ( V_192 ) ;
}
F_192 ( V_6 ) ;
}
static int F_202 ( struct V_5 * V_194 ,
struct V_191 * V_192 )
{
int V_195 ;
F_203 () ;
V_195 = F_204 ( V_192 ) ;
F_205 () ;
if ( V_195 ) {
F_191 ( V_194 ) ;
V_194 -> V_193 = NULL ;
F_192 ( V_194 ) ;
}
F_206 ( V_194 ) ;
return V_195 ;
}
void F_207 ( struct V_5 * V_6 , struct V_84 * V_85 )
{
#ifdef F_208
if ( F_125 ( V_6 -> V_196 ) ) {
F_209 ( V_6 ) ;
V_6 -> V_196 = NULL ;
}
#ifdef F_210
if ( F_125 ( V_6 -> V_197 ) ) {
F_211 ( V_6 ) ;
V_6 -> V_197 = NULL ;
}
#endif
if ( F_125 ( ! F_169 ( & V_6 -> V_198 ) ) )
F_212 ( V_6 ) ;
#endif
F_213 ( V_6 ) ;
F_214 ( V_6 , V_85 ) ;
if ( V_6 -> V_199 ) {
if ( ! ( V_6 -> signal -> V_26 & V_200 ) &&
F_47 ( & V_85 -> V_156 ) > 1 ) {
F_215 ( 0 , V_6 -> V_199 ) ;
F_216 ( V_6 -> V_199 , V_201 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_199 = NULL ;
}
if ( V_6 -> V_193 )
F_199 ( V_6 ) ;
}
static struct V_84 * F_217 ( struct V_5 * V_6 )
{
struct V_84 * V_85 , * V_86 = V_47 -> V_85 ;
int V_72 ;
V_85 = F_154 () ;
if ( ! V_85 )
goto V_115;
memcpy ( V_85 , V_86 , sizeof( * V_85 ) ) ;
if ( ! F_136 ( V_85 , V_6 , V_85 -> V_153 ) )
goto V_115;
V_72 = F_86 ( V_85 , V_86 ) ;
if ( V_72 )
goto V_202;
V_85 -> V_203 = F_218 ( V_85 ) ;
V_85 -> V_204 = V_85 -> V_102 ;
if ( V_85 -> V_179 && ! F_219 ( V_85 -> V_179 -> V_180 ) )
goto V_202;
return V_85 ;
V_202:
V_85 -> V_179 = NULL ;
F_176 ( V_85 ) ;
V_115:
return NULL ;
}
static int F_220 ( unsigned long V_205 , struct V_5 * V_6 )
{
struct V_84 * V_85 , * V_86 ;
int V_95 ;
V_6 -> V_206 = V_6 -> V_207 = 0 ;
V_6 -> V_208 = V_6 -> V_209 = 0 ;
#ifdef F_221
V_6 -> V_210 = V_6 -> V_208 + V_6 -> V_209 ;
#endif
V_6 -> V_85 = NULL ;
V_6 -> V_211 = NULL ;
V_86 = V_47 -> V_85 ;
if ( ! V_86 )
return 0 ;
F_222 ( V_6 ) ;
if ( V_205 & V_212 ) {
F_107 ( & V_86 -> V_156 ) ;
V_85 = V_86 ;
goto V_213;
}
V_95 = - V_143 ;
V_85 = F_217 ( V_6 ) ;
if ( ! V_85 )
goto V_115;
V_213:
V_6 -> V_85 = V_85 ;
V_6 -> V_211 = V_85 ;
return 0 ;
V_115:
return V_95 ;
}
static int F_223 ( unsigned long V_205 , struct V_5 * V_6 )
{
struct V_214 * V_215 = V_47 -> V_215 ;
if ( V_205 & V_216 ) {
F_170 ( & V_215 -> V_217 ) ;
if ( V_215 -> V_218 ) {
F_172 ( & V_215 -> V_217 ) ;
return - V_219 ;
}
V_215 -> V_220 ++ ;
F_172 ( & V_215 -> V_217 ) ;
return 0 ;
}
V_6 -> V_215 = F_224 ( V_215 ) ;
if ( ! V_6 -> V_215 )
return - V_143 ;
return 0 ;
}
static int F_225 ( unsigned long V_205 , struct V_5 * V_6 )
{
struct V_221 * V_222 , * V_223 ;
int error = 0 ;
V_222 = V_47 -> V_224 ;
if ( ! V_222 )
goto V_108;
if ( V_205 & V_225 ) {
F_107 ( & V_222 -> V_175 ) ;
goto V_108;
}
V_223 = F_226 ( V_222 , & error ) ;
if ( ! V_223 )
goto V_108;
V_6 -> V_224 = V_223 ;
error = 0 ;
V_108:
return error ;
}
static int F_227 ( unsigned long V_205 , struct V_5 * V_6 )
{
#ifdef F_228
struct V_226 * V_227 = V_47 -> V_226 ;
struct V_226 * V_228 ;
if ( ! V_227 )
return 0 ;
if ( V_205 & V_229 ) {
F_229 ( V_227 ) ;
V_6 -> V_226 = V_227 ;
} else if ( F_230 ( V_227 -> V_230 ) ) {
V_228 = F_231 ( V_6 , V_9 , V_73 ) ;
if ( F_125 ( ! V_228 ) )
return - V_143 ;
V_228 -> V_230 = V_227 -> V_230 ;
F_232 ( V_228 ) ;
}
#endif
return 0 ;
}
static int F_233 ( unsigned long V_205 , struct V_5 * V_6 )
{
struct V_231 * V_41 ;
if ( V_205 & V_232 ) {
F_107 ( & V_47 -> V_233 -> V_175 ) ;
return 0 ;
}
V_41 = F_99 ( V_234 , V_9 ) ;
F_184 ( V_6 -> V_233 , V_41 ) ;
if ( ! V_41 )
return - V_143 ;
F_77 ( & V_41 -> V_175 , 1 ) ;
memcpy ( V_41 -> V_235 , V_47 -> V_233 -> V_235 , sizeof( V_41 -> V_235 ) ) ;
return 0 ;
}
void F_234 ( struct V_231 * V_233 )
{
if ( F_43 ( & V_233 -> V_175 ) ) {
F_235 ( V_233 ) ;
F_10 ( V_234 , V_233 ) ;
}
}
static void F_236 ( struct V_40 * V_41 )
{
unsigned long V_236 ;
V_236 = F_237 ( V_41 -> V_59 [ V_237 ] . V_61 ) ;
if ( V_236 != V_238 ) {
V_41 -> V_239 . V_240 = F_238 ( V_236 ) ;
V_41 -> V_241 . V_242 = true ;
}
F_100 ( & V_41 -> V_243 [ 0 ] ) ;
F_100 ( & V_41 -> V_243 [ 1 ] ) ;
F_100 ( & V_41 -> V_243 [ 2 ] ) ;
}
static int F_239 ( unsigned long V_205 , struct V_5 * V_6 )
{
struct V_40 * V_41 ;
if ( V_205 & V_244 )
return 0 ;
V_41 = F_240 ( V_43 , V_9 ) ;
V_6 -> signal = V_41 ;
if ( ! V_41 )
return - V_143 ;
V_41 -> V_245 = 1 ;
F_77 ( & V_41 -> V_246 , 1 ) ;
F_77 ( & V_41 -> V_44 , 1 ) ;
V_41 -> V_247 = (struct V_248 ) F_241 ( V_6 -> V_249 ) ;
V_6 -> V_249 = (struct V_248 ) F_241 ( V_41 -> V_247 ) ;
F_242 ( & V_41 -> V_250 ) ;
V_41 -> V_251 = V_6 ;
F_243 ( & V_41 -> V_252 ) ;
F_100 ( & V_41 -> V_253 ) ;
F_244 ( & V_41 -> V_254 ) ;
F_245 ( & V_41 -> V_255 ) ;
#ifdef F_246
F_247 ( & V_41 -> V_256 , V_257 , V_258 ) ;
V_41 -> V_256 . V_259 = V_260 ;
#endif
F_191 ( V_47 -> V_261 ) ;
memcpy ( V_41 -> V_59 , V_47 -> signal -> V_59 , sizeof V_41 -> V_59 ) ;
F_192 ( V_47 -> V_261 ) ;
F_236 ( V_41 ) ;
F_248 ( V_41 ) ;
F_249 ( V_41 ) ;
V_41 -> V_262 = V_47 -> signal -> V_262 ;
V_41 -> V_263 = V_47 -> signal -> V_263 ;
V_41 -> V_264 = V_47 -> signal -> V_264 ||
V_47 -> signal -> V_265 ;
F_250 ( & V_41 -> V_189 ) ;
return 0 ;
}
static void F_251 ( struct V_5 * V_150 )
{
#ifdef F_78
F_252 ( & V_47 -> V_233 -> V_266 ) ;
F_253 ( V_47 ) ;
V_150 -> V_76 = V_47 -> V_76 ;
if ( F_254 ( V_47 ) )
F_255 ( V_150 ) ;
if ( V_150 -> V_76 . V_188 != V_267 )
F_256 ( V_150 , V_268 ) ;
#endif
}
static void F_257 ( struct V_5 * V_150 )
{
F_258 ( & V_150 -> V_269 ) ;
#ifdef F_259
V_150 -> V_270 = V_154 ;
V_150 -> V_271 = NULL ;
V_150 -> V_272 = NULL ;
#endif
}
static void F_260 ( struct V_5 * V_6 )
{
V_6 -> V_239 . V_240 = 0 ;
V_6 -> V_239 . V_273 = 0 ;
V_6 -> V_239 . V_274 = 0 ;
F_100 ( & V_6 -> V_243 [ 0 ] ) ;
F_100 ( & V_6 -> V_243 [ 1 ] ) ;
F_100 ( & V_6 -> V_243 [ 2 ] ) ;
}
static inline void
F_261 ( struct V_5 * V_187 , enum V_275 type , struct V_276 * V_276 )
{
V_187 -> V_277 [ type ] . V_276 = V_276 ;
}
inline void F_262 ( struct V_278 * V_279 )
{
enum V_275 type ;
for ( type = V_280 ; type < V_281 ; ++ type ) {
F_263 ( & V_279 [ type ] . V_7 ) ;
V_279 [ type ] . V_276 = & V_282 ;
}
}
struct V_5 * F_264 ( int V_2 )
{
struct V_5 * V_187 ;
V_187 = F_265 ( V_212 , 0 , 0 , NULL , & V_282 , 0 , 0 ,
F_266 ( V_2 ) ) ;
if ( ! F_267 ( V_187 ) ) {
F_262 ( V_187 -> V_277 ) ;
F_268 ( V_187 , V_2 ) ;
}
return V_187 ;
}
long F_269 ( unsigned long V_205 ,
unsigned long V_283 ,
unsigned long V_284 ,
int T_4 * V_285 ,
int T_4 * V_286 ,
unsigned long V_287 )
{
struct V_5 * V_150 ;
int V_288 = 0 ;
long V_289 ;
if ( ! ( V_205 & V_290 ) ) {
if ( V_205 & V_291 )
V_288 = V_292 ;
else if ( ( V_205 & V_293 ) != V_294 )
V_288 = V_295 ;
else
V_288 = V_296 ;
if ( F_200 ( ! F_270 ( V_47 , V_288 ) ) )
V_288 = 0 ;
}
V_150 = F_265 ( V_205 , V_283 , V_284 ,
V_286 , NULL , V_288 , V_287 , V_73 ) ;
F_271 () ;
if ( ! F_267 ( V_150 ) ) {
struct V_191 V_192 ;
struct V_276 * V_276 ;
F_272 ( V_47 , V_150 ) ;
V_276 = F_273 ( V_150 , V_280 ) ;
V_289 = F_274 ( V_276 ) ;
if ( V_205 & V_297 )
F_215 ( V_289 , V_285 ) ;
if ( V_205 & V_291 ) {
V_150 -> V_193 = & V_192 ;
F_275 ( & V_192 ) ;
F_276 ( V_150 ) ;
}
F_277 ( V_150 ) ;
if ( F_125 ( V_288 ) )
F_278 ( V_288 , V_276 ) ;
if ( V_205 & V_291 ) {
if ( ! F_202 ( V_150 , & V_192 ) )
F_278 ( V_298 , V_276 ) ;
}
F_279 ( V_276 ) ;
} else {
V_289 = F_280 ( V_150 ) ;
}
return V_289 ;
}
long F_281 ( unsigned long V_205 ,
unsigned long V_283 ,
unsigned long V_284 ,
int T_4 * V_285 ,
int T_4 * V_286 )
{
return F_269 ( V_205 , V_283 , V_284 ,
V_285 , V_286 , 0 ) ;
}
T_5 F_282 ( int (* F_283)( void * ) , void * V_299 , unsigned long V_26 )
{
return F_269 ( V_26 | V_212 | V_290 , ( unsigned long ) F_283 ,
( unsigned long ) V_299 , NULL , NULL , 0 ) ;
}
static void F_284 ( void * V_300 )
{
struct V_231 * V_233 = V_300 ;
F_133 ( & V_233 -> V_266 ) ;
F_242 ( & V_233 -> V_301 ) ;
}
void T_1 F_285 ( void )
{
V_234 = F_31 ( L_7 ,
sizeof( struct V_231 ) , 0 ,
V_302 | V_55 | V_303 |
V_56 | V_57 , F_284 ) ;
V_43 = F_31 ( L_8 ,
sizeof( struct V_40 ) , 0 ,
V_302 | V_55 | V_56 | V_57 ,
NULL ) ;
V_304 = F_31 ( L_9 ,
sizeof( struct V_221 ) , 0 ,
V_302 | V_55 | V_56 | V_57 ,
NULL ) ;
V_305 = F_31 ( L_10 ,
sizeof( struct V_214 ) , 0 ,
V_302 | V_55 | V_56 | V_57 ,
NULL ) ;
V_306 = F_31 ( L_11 ,
sizeof( struct V_84 ) , V_307 ,
V_302 | V_55 | V_56 | V_57 ,
NULL ) ;
V_116 = F_286 ( V_87 , V_55 | V_57 ) ;
F_287 () ;
F_288 () ;
}
static int F_289 ( unsigned long V_308 )
{
if ( V_308 & ~ ( V_244 | V_216 | V_309 | V_232 |
V_212 | V_225 | V_310 |
V_311 | V_312 | V_313 |
V_314 | V_315 | V_316 ) )
return - V_317 ;
if ( V_308 & ( V_244 | V_232 | V_212 ) ) {
if ( ! F_290 ( V_47 ) )
return - V_317 ;
}
if ( V_308 & ( V_232 | V_212 ) ) {
if ( F_47 ( & V_47 -> V_233 -> V_175 ) > 1 )
return - V_317 ;
}
if ( V_308 & V_212 ) {
if ( ! F_291 () )
return - V_317 ;
}
return 0 ;
}
static int F_292 ( unsigned long V_308 , struct V_214 * * V_318 )
{
struct V_214 * V_215 = V_47 -> V_215 ;
if ( ! ( V_308 & V_216 ) || ! V_215 )
return 0 ;
if ( V_215 -> V_220 == 1 )
return 0 ;
* V_318 = F_224 ( V_215 ) ;
if ( ! * V_318 )
return - V_143 ;
return 0 ;
}
static int F_293 ( unsigned long V_308 , struct V_221 * * V_319 )
{
struct V_221 * V_320 = V_47 -> V_224 ;
int error = 0 ;
if ( ( V_308 & V_225 ) &&
( V_320 && F_47 ( & V_320 -> V_175 ) > 1 ) ) {
* V_319 = F_226 ( V_320 , & error ) ;
if ( ! * V_319 )
return error ;
}
return 0 ;
}
int F_294 ( struct V_221 * * V_321 )
{
struct V_5 * V_187 = V_47 ;
struct V_221 * V_322 = NULL ;
int error ;
error = F_293 ( V_225 , & V_322 ) ;
if ( error || ! V_322 ) {
* V_321 = NULL ;
return error ;
}
* V_321 = V_187 -> V_224 ;
F_191 ( V_187 ) ;
V_187 -> V_224 = V_322 ;
F_192 ( V_187 ) ;
return 0 ;
}
int F_295 ( struct V_323 * V_324 , int V_325 ,
void T_4 * V_326 , T_6 * V_327 , T_7 * V_328 )
{
struct V_323 V_329 ;
int V_330 ;
int V_49 = V_52 ;
int V_331 = V_53 ;
int V_332 = V_51 ;
V_329 = * V_324 ;
V_329 . V_300 = & V_49 ;
V_329 . V_333 = & V_331 ;
V_329 . V_334 = & V_332 ;
V_330 = F_296 ( & V_329 , V_325 , V_326 , V_327 , V_328 ) ;
if ( V_330 || ! V_325 )
return V_330 ;
F_65 ( V_49 ) ;
return 0 ;
}
