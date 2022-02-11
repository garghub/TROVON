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
#define F_71 0
#endif
int V_54 = F_72 ( int , V_55 , F_71 ) ;
V_8 = F_31 ( L_2 ,
V_56 , V_54 ,
V_57 | V_58 | V_59 , NULL ) ;
#endif
F_64 () ;
F_65 ( V_51 ) ;
V_60 . signal -> V_61 [ V_62 ] . V_63 = V_52 / 2 ;
V_60 . signal -> V_61 [ V_62 ] . V_64 = V_52 / 2 ;
V_60 . signal -> V_61 [ V_65 ] =
V_60 . signal -> V_61 [ V_62 ] ;
for ( V_11 = 0 ; V_11 < V_66 ; V_11 ++ ) {
V_67 . V_68 [ V_11 ] = V_52 / 2 ;
}
}
int __weak F_73 ( struct V_5 * V_69 ,
struct V_5 * V_70 )
{
* V_69 = * V_70 ;
return 0 ;
}
void F_74 ( struct V_5 * V_6 )
{
unsigned long * V_71 ;
V_71 = F_75 ( V_6 ) ;
* V_71 = V_72 ;
}
static struct V_5 * F_76 ( struct V_5 * V_73 , int V_7 )
{
struct V_5 * V_6 ;
unsigned long * V_10 ;
struct V_13 * V_16 ;
int V_74 ;
if ( V_7 == V_75 )
V_7 = F_77 ( V_73 ) ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_10 = F_12 ( V_6 , V_7 ) ;
if ( ! V_10 )
goto V_76;
V_16 = F_24 ( V_6 ) ;
V_74 = F_73 ( V_6 , V_73 ) ;
V_6 -> V_10 = V_10 ;
#ifdef F_13
V_6 -> V_16 = V_16 ;
#endif
#ifdef F_45
F_78 ( & V_6 -> V_38 , 1 ) ;
#endif
if ( V_74 )
goto V_77;
#ifdef F_79
V_6 -> V_78 . V_79 = NULL ;
#endif
F_80 ( V_6 , V_73 ) ;
F_81 ( V_6 ) ;
F_82 ( V_6 ) ;
F_74 ( V_6 ) ;
#ifdef F_83
V_6 -> V_80 = F_84 () ;
#endif
F_78 ( & V_6 -> V_46 , 2 ) ;
#ifdef F_85
V_6 -> V_81 = 0 ;
#endif
V_6 -> V_82 = NULL ;
V_6 -> V_83 . V_24 = NULL ;
V_6 -> V_84 . V_85 = NULL ;
F_33 ( V_6 , 1 ) ;
F_86 ( V_6 ) ;
return V_6 ;
V_77:
F_23 ( V_6 ) ;
V_76:
F_9 ( V_6 ) ;
return NULL ;
}
static T_3 int F_87 ( struct V_86 * V_87 ,
struct V_86 * V_88 )
{
struct V_89 * V_90 , * V_91 , * V_92 , * * V_93 ;
struct V_94 * * V_95 , * V_96 ;
int V_97 ;
unsigned long V_98 ;
F_88 ( V_99 ) ;
F_89 () ;
if ( F_90 ( & V_88 -> V_100 ) ) {
V_97 = - V_101 ;
goto V_102;
}
F_91 ( V_88 ) ;
F_92 ( V_88 , V_87 ) ;
F_93 ( & V_87 -> V_100 , V_103 ) ;
F_94 ( V_87 -> V_104 , F_95 ( V_88 ) ) ;
V_87 -> V_105 = V_88 -> V_105 ;
V_87 -> V_106 = V_88 -> V_106 ;
V_87 -> V_107 = V_88 -> V_107 ;
V_87 -> V_108 = V_88 -> V_108 ;
V_95 = & V_87 -> V_109 . V_94 ;
V_96 = NULL ;
V_93 = & V_87 -> V_110 ;
V_97 = F_96 ( V_87 , V_88 ) ;
if ( V_97 )
goto V_111;
V_97 = F_97 ( V_87 , V_88 ) ;
if ( V_97 )
goto V_111;
V_92 = NULL ;
for ( V_90 = V_88 -> V_110 ; V_90 ; V_90 = V_90 -> V_112 ) {
struct V_113 * V_113 ;
if ( V_90 -> V_114 & V_115 ) {
F_98 ( V_87 , V_90 -> V_114 , - F_99 ( V_90 ) ) ;
continue;
}
V_98 = 0 ;
if ( V_90 -> V_114 & V_116 ) {
unsigned long V_117 = F_99 ( V_90 ) ;
if ( F_100 ( V_88 , V_117 ) )
goto V_118;
V_98 = V_117 ;
}
V_91 = F_101 ( V_119 , V_9 ) ;
if ( ! V_91 )
goto V_118;
* V_91 = * V_90 ;
F_102 ( & V_91 -> V_120 ) ;
V_97 = F_103 ( V_90 , V_91 ) ;
if ( V_97 )
goto V_121;
V_91 -> V_122 = V_87 ;
V_97 = F_104 ( V_91 , & V_99 ) ;
if ( V_97 )
goto V_123;
if ( F_105 ( V_91 , V_90 ) )
goto V_123;
V_91 -> V_114 &= ~ ( V_124 | V_125 ) ;
V_91 -> V_112 = V_91 -> V_126 = NULL ;
V_113 = V_91 -> V_127 ;
if ( V_113 ) {
struct V_128 * V_128 = F_106 ( V_113 ) ;
struct V_129 * V_130 = V_113 -> V_131 ;
F_107 ( V_113 ) ;
if ( V_91 -> V_114 & V_132 )
F_108 ( & V_128 -> V_133 ) ;
F_109 ( V_130 ) ;
if ( V_91 -> V_114 & V_134 )
F_110 ( & V_130 -> V_135 ) ;
F_111 ( V_130 ) ;
F_112 ( V_91 , V_90 ,
& V_130 -> V_136 ) ;
F_113 ( V_130 ) ;
F_114 ( V_130 ) ;
}
if ( F_115 ( V_91 ) )
F_116 ( V_91 ) ;
* V_93 = V_91 ;
V_93 = & V_91 -> V_112 ;
V_91 -> V_126 = V_92 ;
V_92 = V_91 ;
F_117 ( V_87 , V_91 , V_95 , V_96 ) ;
V_95 = & V_91 -> V_137 . V_138 ;
V_96 = & V_91 -> V_137 ;
V_87 -> V_139 ++ ;
V_97 = F_118 ( V_87 , V_88 , V_90 ) ;
if ( V_91 -> V_140 && V_91 -> V_140 -> V_141 )
V_91 -> V_140 -> V_141 ( V_91 ) ;
if ( V_97 )
goto V_111;
}
F_119 ( V_88 , V_87 ) ;
V_97 = 0 ;
V_111:
F_120 ( & V_87 -> V_100 ) ;
F_121 ( V_88 ) ;
F_120 ( & V_88 -> V_100 ) ;
F_122 ( & V_99 ) ;
V_102:
F_123 () ;
return V_97 ;
V_123:
F_124 ( F_125 ( V_91 ) ) ;
V_121:
F_10 ( V_119 , V_91 ) ;
V_118:
V_97 = - V_142 ;
F_126 ( V_98 ) ;
goto V_111;
}
static inline int F_127 ( struct V_86 * V_87 )
{
V_87 -> V_143 = F_128 ( V_87 ) ;
if ( F_129 ( ! V_87 -> V_143 ) )
return - V_142 ;
return 0 ;
}
static inline void F_130 ( struct V_86 * V_87 )
{
F_131 ( V_87 , V_87 -> V_143 ) ;
}
static int F_87 ( struct V_86 * V_87 , struct V_86 * V_88 )
{
F_132 ( & V_88 -> V_100 ) ;
F_94 ( V_87 -> V_104 , F_95 ( V_88 ) ) ;
F_120 ( & V_88 -> V_100 ) ;
return 0 ;
}
static int T_1 F_133 ( char * V_14 )
{
V_144 =
( F_134 ( V_14 , NULL , 0 ) << V_145 ) &
V_146 ;
return 1 ;
}
static void F_135 ( struct V_86 * V_87 )
{
#ifdef F_136
F_137 ( & V_87 -> V_147 ) ;
V_87 -> V_148 = NULL ;
#endif
}
static void F_138 ( struct V_86 * V_87 , struct V_5 * V_149 )
{
#ifdef F_139
V_87 -> V_150 = V_149 ;
#endif
}
static struct V_86 * F_140 ( struct V_86 * V_87 , struct V_5 * V_149 ,
struct V_151 * V_152 )
{
V_87 -> V_110 = NULL ;
V_87 -> V_109 = V_153 ;
V_87 -> V_154 = 0 ;
F_78 ( & V_87 -> V_155 , 1 ) ;
F_78 ( & V_87 -> V_156 , 1 ) ;
F_141 ( & V_87 -> V_100 ) ;
F_102 ( & V_87 -> V_157 ) ;
V_87 -> V_158 = NULL ;
F_142 ( & V_87 -> V_159 , 0 ) ;
F_143 ( V_87 ) ;
V_87 -> V_139 = 0 ;
V_87 -> V_160 = 0 ;
V_87 -> V_161 = 0 ;
memset ( & V_87 -> V_162 , 0 , sizeof( V_87 -> V_162 ) ) ;
F_137 ( & V_87 -> V_163 ) ;
F_144 ( V_87 ) ;
F_135 ( V_87 ) ;
F_138 ( V_87 , V_149 ) ;
F_145 ( V_87 ) ;
F_146 ( V_87 ) ;
#if F_147 ( V_164 ) && ! V_165
V_87 -> V_166 = NULL ;
#endif
if ( V_47 -> V_87 ) {
V_87 -> V_26 = V_47 -> V_87 -> V_26 & V_167 ;
V_87 -> V_168 = V_47 -> V_87 -> V_168 & V_169 ;
} else {
V_87 -> V_26 = V_144 ;
V_87 -> V_168 = 0 ;
}
if ( F_127 ( V_87 ) )
goto V_170;
if ( F_148 ( V_149 , V_87 ) )
goto V_171;
V_87 -> V_152 = F_149 ( V_152 ) ;
return V_87 ;
V_171:
F_130 ( V_87 ) ;
V_170:
F_150 ( V_87 ) ;
return NULL ;
}
static void F_151 ( struct V_86 * V_87 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_172 ; V_11 ++ ) {
long V_173 = F_152 ( & V_87 -> V_162 . V_174 [ V_11 ] ) ;
if ( F_129 ( V_173 ) )
F_153 ( V_175 L_3
L_4 , V_87 , V_11 , V_173 ) ;
}
if ( F_152 ( & V_87 -> V_159 ) )
F_154 ( L_5 ,
F_152 ( & V_87 -> V_159 ) ) ;
if ( F_155 ( V_87 ) )
F_154 ( L_6 ,
F_155 ( V_87 ) ) ;
#if F_147 ( V_164 ) && ! V_165
F_156 ( V_87 -> V_166 , V_87 ) ;
#endif
}
struct V_86 * F_157 ( void )
{
struct V_86 * V_87 ;
V_87 = F_158 () ;
if ( ! V_87 )
return NULL ;
memset ( V_87 , 0 , sizeof( * V_87 ) ) ;
return F_140 ( V_87 , V_47 , F_159 () ) ;
}
void F_160 ( struct V_86 * V_87 )
{
F_32 ( V_87 == & V_176 ) ;
F_130 ( V_87 ) ;
F_161 ( V_87 ) ;
F_162 ( V_87 ) ;
F_151 ( V_87 ) ;
F_163 ( V_87 -> V_152 ) ;
F_150 ( V_87 ) ;
}
static inline void F_164 ( struct V_86 * V_87 )
{
F_165 ( F_47 ( & V_87 -> V_155 ) ) ;
F_166 ( V_87 ) ;
F_167 ( V_87 ) ;
F_168 ( V_87 ) ;
F_169 ( V_87 ) ;
F_170 ( V_87 ) ;
F_171 ( V_87 ) ;
F_172 ( V_87 , NULL ) ;
if ( ! F_173 ( & V_87 -> V_157 ) ) {
F_174 ( & V_177 ) ;
F_175 ( & V_87 -> V_157 ) ;
F_176 ( & V_177 ) ;
}
if ( V_87 -> V_178 )
F_177 ( V_87 -> V_178 -> V_179 ) ;
F_178 ( V_180 , & V_87 -> V_26 ) ;
F_179 ( V_87 ) ;
}
void F_180 ( struct V_86 * V_87 )
{
F_181 () ;
if ( F_43 ( & V_87 -> V_155 ) )
F_164 ( V_87 ) ;
}
static void F_182 ( struct V_181 * V_182 )
{
struct V_86 * V_87 = F_183 ( V_182 , struct V_86 , V_183 ) ;
F_164 ( V_87 ) ;
}
void F_184 ( struct V_86 * V_87 )
{
if ( F_43 ( & V_87 -> V_155 ) ) {
F_185 ( & V_87 -> V_183 , F_182 ) ;
F_186 ( & V_87 -> V_183 ) ;
}
}
void F_172 ( struct V_86 * V_87 , struct V_113 * V_184 )
{
struct V_113 * V_185 ;
V_185 = F_187 ( V_87 -> V_104 ) ;
if ( V_184 )
F_107 ( V_184 ) ;
F_188 ( V_87 -> V_104 , V_184 ) ;
if ( V_185 )
F_189 ( V_185 ) ;
}
struct V_113 * F_95 ( struct V_86 * V_87 )
{
struct V_113 * V_104 ;
F_190 () ;
V_104 = F_191 ( V_87 -> V_104 ) ;
if ( V_104 && ! F_192 ( V_104 ) )
V_104 = NULL ;
F_193 () ;
return V_104 ;
}
struct V_113 * F_194 ( struct V_5 * V_186 )
{
struct V_113 * V_104 = NULL ;
struct V_86 * V_87 ;
F_195 ( V_186 ) ;
V_87 = V_186 -> V_87 ;
if ( V_87 ) {
if ( ! ( V_186 -> V_26 & V_39 ) )
V_104 = F_95 ( V_87 ) ;
}
F_196 ( V_186 ) ;
return V_104 ;
}
struct V_86 * F_197 ( struct V_5 * V_186 )
{
struct V_86 * V_87 ;
F_195 ( V_186 ) ;
V_87 = V_186 -> V_87 ;
if ( V_87 ) {
if ( V_186 -> V_26 & V_39 )
V_87 = NULL ;
else
F_198 ( V_87 ) ;
}
F_196 ( V_186 ) ;
return V_87 ;
}
struct V_86 * F_199 ( struct V_5 * V_186 , unsigned int V_187 )
{
struct V_86 * V_87 ;
int V_74 ;
V_74 = F_200 ( & V_186 -> signal -> V_188 ) ;
if ( V_74 )
return F_201 ( V_74 ) ;
V_87 = F_197 ( V_186 ) ;
if ( V_87 && V_87 != V_47 -> V_87 &&
! F_202 ( V_186 , V_187 ) ) {
F_180 ( V_87 ) ;
V_87 = F_201 ( - V_189 ) ;
}
F_203 ( & V_186 -> signal -> V_188 ) ;
return V_87 ;
}
static void F_204 ( struct V_5 * V_6 )
{
struct V_190 * V_191 ;
F_195 ( V_6 ) ;
V_191 = V_6 -> V_192 ;
if ( F_205 ( V_191 ) ) {
V_6 -> V_192 = NULL ;
F_206 ( V_191 ) ;
}
F_196 ( V_6 ) ;
}
static int F_207 ( struct V_5 * V_193 ,
struct V_190 * V_191 )
{
int V_194 ;
F_208 () ;
V_194 = F_209 ( V_191 ) ;
F_210 () ;
if ( V_194 ) {
F_195 ( V_193 ) ;
V_193 -> V_192 = NULL ;
F_196 ( V_193 ) ;
}
F_211 ( V_193 ) ;
return V_194 ;
}
void F_212 ( struct V_5 * V_6 , struct V_86 * V_87 )
{
#ifdef F_213
if ( F_129 ( V_6 -> V_195 ) ) {
F_214 ( V_6 ) ;
V_6 -> V_195 = NULL ;
}
#ifdef F_215
if ( F_129 ( V_6 -> V_196 ) ) {
F_216 ( V_6 ) ;
V_6 -> V_196 = NULL ;
}
#endif
if ( F_129 ( ! F_173 ( & V_6 -> V_197 ) ) )
F_217 ( V_6 ) ;
#endif
F_218 ( V_6 ) ;
F_219 ( V_6 , V_87 ) ;
if ( V_6 -> V_198 ) {
if ( ! ( V_6 -> signal -> V_26 & V_199 ) &&
F_47 ( & V_87 -> V_155 ) > 1 ) {
F_220 ( 0 , V_6 -> V_198 ) ;
F_221 ( V_6 -> V_198 , V_200 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_198 = NULL ;
}
if ( V_6 -> V_192 )
F_204 ( V_6 ) ;
}
static struct V_86 * F_222 ( struct V_5 * V_6 )
{
struct V_86 * V_87 , * V_88 = V_47 -> V_87 ;
int V_74 ;
V_87 = F_158 () ;
if ( ! V_87 )
goto V_118;
memcpy ( V_87 , V_88 , sizeof( * V_87 ) ) ;
if ( ! F_140 ( V_87 , V_6 , V_87 -> V_152 ) )
goto V_118;
V_74 = F_87 ( V_87 , V_88 ) ;
if ( V_74 )
goto V_201;
V_87 -> V_202 = F_223 ( V_87 ) ;
V_87 -> V_203 = V_87 -> V_105 ;
if ( V_87 -> V_178 && ! F_224 ( V_87 -> V_178 -> V_179 ) )
goto V_201;
return V_87 ;
V_201:
V_87 -> V_178 = NULL ;
F_180 ( V_87 ) ;
V_118:
return NULL ;
}
static int F_225 ( unsigned long V_204 , struct V_5 * V_6 )
{
struct V_86 * V_87 , * V_88 ;
int V_97 ;
V_6 -> V_205 = V_6 -> V_206 = 0 ;
V_6 -> V_207 = V_6 -> V_208 = 0 ;
#ifdef F_226
V_6 -> V_209 = V_6 -> V_207 + V_6 -> V_208 ;
#endif
V_6 -> V_87 = NULL ;
V_6 -> V_210 = NULL ;
V_88 = V_47 -> V_87 ;
if ( ! V_88 )
return 0 ;
F_227 ( V_6 ) ;
if ( V_204 & V_211 ) {
F_198 ( V_88 ) ;
V_87 = V_88 ;
goto V_212;
}
V_97 = - V_142 ;
V_87 = F_222 ( V_6 ) ;
if ( ! V_87 )
goto V_118;
V_212:
V_6 -> V_87 = V_87 ;
V_6 -> V_210 = V_87 ;
return 0 ;
V_118:
return V_97 ;
}
static int F_228 ( unsigned long V_204 , struct V_5 * V_6 )
{
struct V_213 * V_214 = V_47 -> V_214 ;
if ( V_204 & V_215 ) {
F_174 ( & V_214 -> V_216 ) ;
if ( V_214 -> V_217 ) {
F_176 ( & V_214 -> V_216 ) ;
return - V_218 ;
}
V_214 -> V_219 ++ ;
F_176 ( & V_214 -> V_216 ) ;
return 0 ;
}
V_6 -> V_214 = F_229 ( V_214 ) ;
if ( ! V_6 -> V_214 )
return - V_142 ;
return 0 ;
}
static int F_230 ( unsigned long V_204 , struct V_5 * V_6 )
{
struct V_220 * V_221 , * V_222 ;
int error = 0 ;
V_221 = V_47 -> V_223 ;
if ( ! V_221 )
goto V_111;
if ( V_204 & V_224 ) {
F_110 ( & V_221 -> V_174 ) ;
goto V_111;
}
V_222 = F_231 ( V_221 , & error ) ;
if ( ! V_222 )
goto V_111;
V_6 -> V_223 = V_222 ;
error = 0 ;
V_111:
return error ;
}
static int F_232 ( unsigned long V_204 , struct V_5 * V_6 )
{
#ifdef F_233
struct V_225 * V_226 = V_47 -> V_225 ;
struct V_225 * V_227 ;
if ( ! V_226 )
return 0 ;
if ( V_204 & V_228 ) {
F_234 ( V_226 ) ;
V_6 -> V_225 = V_226 ;
} else if ( F_235 ( V_226 -> V_229 ) ) {
V_227 = F_236 ( V_6 , V_9 , V_75 ) ;
if ( F_129 ( ! V_227 ) )
return - V_142 ;
V_227 -> V_229 = V_226 -> V_229 ;
F_237 ( V_227 ) ;
}
#endif
return 0 ;
}
static int F_238 ( unsigned long V_204 , struct V_5 * V_6 )
{
struct V_230 * V_41 ;
if ( V_204 & V_231 ) {
F_110 ( & V_47 -> V_232 -> V_174 ) ;
return 0 ;
}
V_41 = F_101 ( V_233 , V_9 ) ;
F_188 ( V_6 -> V_232 , V_41 ) ;
if ( ! V_41 )
return - V_142 ;
F_78 ( & V_41 -> V_174 , 1 ) ;
memcpy ( V_41 -> V_234 , V_47 -> V_232 -> V_234 , sizeof( V_41 -> V_234 ) ) ;
return 0 ;
}
void F_239 ( struct V_230 * V_232 )
{
if ( F_43 ( & V_232 -> V_174 ) ) {
F_240 ( V_232 ) ;
F_10 ( V_233 , V_232 ) ;
}
}
static void F_241 ( struct V_40 * V_41 )
{
unsigned long V_235 ;
V_235 = F_242 ( V_41 -> V_61 [ V_236 ] . V_63 ) ;
if ( V_235 != V_237 ) {
V_41 -> V_238 . V_239 = V_235 * V_240 ;
V_41 -> V_241 . V_242 = true ;
}
F_102 ( & V_41 -> V_243 [ 0 ] ) ;
F_102 ( & V_41 -> V_243 [ 1 ] ) ;
F_102 ( & V_41 -> V_243 [ 2 ] ) ;
}
static inline void F_241 ( struct V_40 * V_41 ) { }
static int F_243 ( unsigned long V_204 , struct V_5 * V_6 )
{
struct V_40 * V_41 ;
if ( V_204 & V_244 )
return 0 ;
V_41 = F_244 ( V_43 , V_9 ) ;
V_6 -> signal = V_41 ;
if ( ! V_41 )
return - V_142 ;
V_41 -> V_245 = 1 ;
F_78 ( & V_41 -> V_246 , 1 ) ;
F_78 ( & V_41 -> V_44 , 1 ) ;
V_41 -> V_247 = (struct V_248 ) F_245 ( V_6 -> V_249 ) ;
V_6 -> V_249 = (struct V_248 ) F_245 ( V_41 -> V_247 ) ;
F_246 ( & V_41 -> V_250 ) ;
V_41 -> V_251 = V_6 ;
F_247 ( & V_41 -> V_252 ) ;
F_248 ( & V_41 -> V_253 ) ;
F_249 ( & V_41 -> V_254 ) ;
#ifdef F_250
F_102 ( & V_41 -> V_255 ) ;
F_251 ( & V_41 -> V_256 , V_257 , V_258 ) ;
V_41 -> V_256 . V_259 = V_260 ;
#endif
F_195 ( V_47 -> V_261 ) ;
memcpy ( V_41 -> V_61 , V_47 -> signal -> V_61 , sizeof V_41 -> V_61 ) ;
F_196 ( V_47 -> V_261 ) ;
F_241 ( V_41 ) ;
F_252 ( V_41 ) ;
F_253 ( V_41 ) ;
V_41 -> V_262 = V_47 -> signal -> V_262 ;
V_41 -> V_263 = V_47 -> signal -> V_263 ;
F_254 ( & V_41 -> V_188 ) ;
return 0 ;
}
static void F_255 ( struct V_5 * V_149 )
{
#ifdef F_79
F_256 ( & V_47 -> V_232 -> V_264 ) ;
F_257 ( V_47 ) ;
V_149 -> V_78 = V_47 -> V_78 ;
if ( F_258 ( V_47 ) )
F_259 ( V_149 ) ;
if ( V_149 -> V_78 . V_187 != V_265 )
F_260 ( V_149 , V_266 ) ;
#endif
}
static void F_261 ( struct V_5 * V_149 )
{
F_262 ( & V_149 -> V_267 ) ;
#ifdef F_263
V_149 -> V_268 = V_153 ;
V_149 -> V_269 = NULL ;
V_149 -> V_270 = NULL ;
#endif
}
static void F_264 ( struct V_5 * V_6 )
{
V_6 -> V_238 . V_239 = 0 ;
V_6 -> V_238 . V_271 = 0 ;
V_6 -> V_238 . V_272 = 0 ;
F_102 ( & V_6 -> V_243 [ 0 ] ) ;
F_102 ( & V_6 -> V_243 [ 1 ] ) ;
F_102 ( & V_6 -> V_243 [ 2 ] ) ;
}
static inline void F_264 ( struct V_5 * V_6 ) { }
static inline void
F_265 ( struct V_5 * V_186 , enum V_273 type , struct V_274 * V_274 )
{
V_186 -> V_275 [ type ] . V_274 = V_274 ;
}
static inline void F_266 ( struct V_5 * V_149 )
{
#ifdef F_267
V_149 -> V_276 = 0 ;
V_149 -> V_277 . V_14 = 0 ;
V_149 -> V_278 = NULL ;
F_102 ( & V_149 -> V_279 ) ;
#endif
#ifdef F_268
V_149 -> V_280 = false ;
F_102 ( & V_149 -> V_281 ) ;
V_149 -> V_282 = - 1 ;
#endif
}
inline void F_269 ( struct V_283 * V_284 )
{
enum V_273 type ;
for ( type = V_285 ; type < V_286 ; ++ type ) {
F_270 ( & V_284 [ type ] . V_7 ) ;
V_284 [ type ] . V_274 = & V_287 ;
}
}
struct V_5 * F_271 ( int V_2 )
{
struct V_5 * V_186 ;
V_186 = F_272 ( V_211 , 0 , 0 , NULL , & V_287 , 0 , 0 ,
F_273 ( V_2 ) ) ;
if ( ! F_274 ( V_186 ) ) {
F_269 ( V_186 -> V_275 ) ;
F_275 ( V_186 , V_2 ) ;
}
return V_186 ;
}
long F_276 ( unsigned long V_204 ,
unsigned long V_288 ,
unsigned long V_289 ,
int T_4 * V_290 ,
int T_4 * V_291 ,
unsigned long V_292 )
{
struct V_5 * V_149 ;
int V_293 = 0 ;
long V_294 ;
if ( ! ( V_204 & V_295 ) ) {
if ( V_204 & V_296 )
V_293 = V_297 ;
else if ( ( V_204 & V_298 ) != V_299 )
V_293 = V_300 ;
else
V_293 = V_301 ;
if ( F_205 ( ! F_277 ( V_47 , V_293 ) ) )
V_293 = 0 ;
}
V_149 = F_272 ( V_204 , V_288 , V_289 ,
V_291 , NULL , V_293 , V_292 , V_75 ) ;
F_278 () ;
if ( ! F_274 ( V_149 ) ) {
struct V_190 V_191 ;
struct V_274 * V_274 ;
F_279 ( V_47 , V_149 ) ;
V_274 = F_280 ( V_149 , V_285 ) ;
V_294 = F_281 ( V_274 ) ;
if ( V_204 & V_302 )
F_220 ( V_294 , V_290 ) ;
if ( V_204 & V_296 ) {
V_149 -> V_192 = & V_191 ;
F_282 ( & V_191 ) ;
F_283 ( V_149 ) ;
}
F_284 ( V_149 ) ;
if ( F_129 ( V_293 ) )
F_285 ( V_293 , V_274 ) ;
if ( V_204 & V_296 ) {
if ( ! F_207 ( V_149 , & V_191 ) )
F_285 ( V_303 , V_274 ) ;
}
F_286 ( V_274 ) ;
} else {
V_294 = F_287 ( V_149 ) ;
}
return V_294 ;
}
long F_288 ( unsigned long V_204 ,
unsigned long V_288 ,
unsigned long V_289 ,
int T_4 * V_290 ,
int T_4 * V_291 )
{
return F_276 ( V_204 , V_288 , V_289 ,
V_290 , V_291 , 0 ) ;
}
T_5 F_289 ( int (* F_290)( void * ) , void * V_304 , unsigned long V_26 )
{
return F_276 ( V_26 | V_211 | V_295 , ( unsigned long ) F_290 ,
( unsigned long ) V_304 , NULL , NULL , 0 ) ;
}
void F_291 ( struct V_5 * V_305 , T_6 V_306 , void * V_307 )
{
struct V_5 * V_308 , * V_309 , * V_193 ;
int V_310 ;
F_292 ( & V_1 ) ;
V_308 = V_305 = V_305 -> V_261 ;
V_311:
F_293 (leader, parent) {
F_294 (child, &parent->children, sibling) {
V_310 = V_306 ( V_193 , V_307 ) ;
if ( V_310 ) {
if ( V_310 < 0 )
goto V_111;
V_308 = V_193 ;
goto V_311;
}
V_312:
;
}
}
if ( V_308 != V_305 ) {
V_193 = V_308 ;
V_309 = V_193 -> V_313 ;
V_308 = V_309 -> V_261 ;
goto V_312;
}
V_111:
F_295 ( & V_1 ) ;
}
static void F_296 ( void * V_307 )
{
struct V_230 * V_232 = V_307 ;
F_137 ( & V_232 -> V_264 ) ;
F_246 ( & V_232 -> V_314 ) ;
}
void T_1 F_297 ( void )
{
V_233 = F_31 ( L_7 ,
sizeof( struct V_230 ) , 0 ,
V_315 | V_57 | V_316 |
V_58 | V_59 , F_296 ) ;
V_43 = F_31 ( L_8 ,
sizeof( struct V_40 ) , 0 ,
V_315 | V_57 | V_58 | V_59 ,
NULL ) ;
V_317 = F_31 ( L_9 ,
sizeof( struct V_220 ) , 0 ,
V_315 | V_57 | V_58 | V_59 ,
NULL ) ;
V_318 = F_31 ( L_10 ,
sizeof( struct V_213 ) , 0 ,
V_315 | V_57 | V_58 | V_59 ,
NULL ) ;
V_319 = F_31 ( L_11 ,
sizeof( struct V_86 ) , V_320 ,
V_315 | V_57 | V_58 | V_59 ,
NULL ) ;
V_119 = F_298 ( V_89 , V_57 | V_59 ) ;
F_299 () ;
F_300 () ;
}
static int F_301 ( unsigned long V_321 )
{
if ( V_321 & ~ ( V_244 | V_215 | V_322 | V_231 |
V_211 | V_224 | V_323 |
V_324 | V_325 | V_326 |
V_327 | V_328 | V_329 ) )
return - V_330 ;
if ( V_321 & ( V_244 | V_231 | V_211 ) ) {
if ( ! F_302 ( V_47 ) )
return - V_330 ;
}
if ( V_321 & ( V_231 | V_211 ) ) {
if ( F_47 ( & V_47 -> V_232 -> V_174 ) > 1 )
return - V_330 ;
}
if ( V_321 & V_211 ) {
if ( ! F_303 () )
return - V_330 ;
}
return 0 ;
}
static int F_304 ( unsigned long V_321 , struct V_213 * * V_331 )
{
struct V_213 * V_214 = V_47 -> V_214 ;
if ( ! ( V_321 & V_215 ) || ! V_214 )
return 0 ;
if ( V_214 -> V_219 == 1 )
return 0 ;
* V_331 = F_229 ( V_214 ) ;
if ( ! * V_331 )
return - V_142 ;
return 0 ;
}
static int F_305 ( unsigned long V_321 , struct V_220 * * V_332 )
{
struct V_220 * V_333 = V_47 -> V_223 ;
int error = 0 ;
if ( ( V_321 & V_224 ) &&
( V_333 && F_47 ( & V_333 -> V_174 ) > 1 ) ) {
* V_332 = F_231 ( V_333 , & error ) ;
if ( ! * V_332 )
return error ;
}
return 0 ;
}
int F_306 ( struct V_220 * * V_334 )
{
struct V_5 * V_186 = V_47 ;
struct V_220 * V_335 = NULL ;
int error ;
error = F_305 ( V_224 , & V_335 ) ;
if ( error || ! V_335 ) {
* V_334 = NULL ;
return error ;
}
* V_334 = V_186 -> V_223 ;
F_195 ( V_186 ) ;
V_186 -> V_223 = V_335 ;
F_196 ( V_186 ) ;
return 0 ;
}
int F_307 ( struct V_336 * V_337 , int V_338 ,
void T_4 * V_339 , T_7 * V_340 , T_8 * V_341 )
{
struct V_336 V_342 ;
int V_343 ;
int V_49 = V_52 ;
int V_344 = V_53 ;
int V_345 = V_51 ;
V_342 = * V_337 ;
V_342 . V_307 = & V_49 ;
V_342 . V_346 = & V_344 ;
V_342 . V_347 = & V_345 ;
V_343 = F_308 ( & V_342 , V_338 , V_339 , V_340 , V_341 ) ;
if ( V_343 || ! V_338 )
return V_343 ;
F_65 ( V_49 ) ;
return 0 ;
}
