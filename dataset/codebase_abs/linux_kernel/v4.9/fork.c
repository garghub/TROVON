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
F_9 ( V_6 ) ;
}
static inline void F_51 ( struct V_39 * V_40 )
{
F_52 ( V_40 ) ;
F_53 ( V_40 ) ;
if ( V_40 -> V_41 )
F_54 ( V_40 -> V_41 ) ;
F_10 ( V_42 , V_40 ) ;
}
static inline void F_55 ( struct V_39 * V_40 )
{
if ( F_43 ( & V_40 -> V_43 ) )
F_51 ( V_40 ) ;
}
void F_56 ( struct V_5 * V_6 )
{
F_41 ( ! V_6 -> V_44 ) ;
F_41 ( F_47 ( & V_6 -> V_45 ) ) ;
F_41 ( V_6 == V_46 ) ;
F_57 ( V_6 ) ;
F_58 ( V_6 ) ;
F_59 ( V_6 ) ;
F_60 ( V_6 ) ;
F_61 ( V_6 ) ;
F_55 ( V_6 -> signal ) ;
if ( ! F_62 ( V_6 ) )
F_44 ( V_6 ) ;
}
void T_1 __weak F_63 ( void ) { }
static void F_64 ( unsigned int V_47 )
{
T_2 V_48 ;
if ( F_65 ( V_49 ) + F_65 ( V_30 ) > 64 )
V_48 = V_50 ;
else
V_48 = F_66 ( ( T_2 ) V_49 * ( T_2 ) V_30 ,
( T_2 ) V_18 * 8UL ) ;
if ( V_48 > V_47 )
V_48 = V_47 ;
V_51 = F_67 ( T_2 , V_48 , V_52 , V_50 ) ;
}
void T_1 F_68 ( void )
{
int V_11 ;
#ifndef F_69
#ifndef F_70
#define F_70 L1_CACHE_BYTES
#endif
V_8 = F_31 ( L_2 ,
V_53 , F_70 ,
V_54 | V_55 | V_56 , NULL ) ;
#endif
F_63 () ;
F_64 ( V_50 ) ;
V_57 . signal -> V_58 [ V_59 ] . V_60 = V_51 / 2 ;
V_57 . signal -> V_58 [ V_59 ] . V_61 = V_51 / 2 ;
V_57 . signal -> V_58 [ V_62 ] =
V_57 . signal -> V_58 [ V_59 ] ;
for ( V_11 = 0 ; V_11 < V_63 ; V_11 ++ ) {
V_64 . V_65 [ V_11 ] = V_51 / 2 ;
}
}
int __weak F_71 ( struct V_5 * V_66 ,
struct V_5 * V_67 )
{
* V_66 = * V_67 ;
return 0 ;
}
void F_72 ( struct V_5 * V_6 )
{
unsigned long * V_68 ;
V_68 = F_73 ( V_6 ) ;
* V_68 = V_69 ;
}
static struct V_5 * F_74 ( struct V_5 * V_70 , int V_7 )
{
struct V_5 * V_6 ;
unsigned long * V_10 ;
struct V_13 * V_16 ;
int V_71 ;
if ( V_7 == V_72 )
V_7 = F_75 ( V_70 ) ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_10 = F_12 ( V_6 , V_7 ) ;
if ( ! V_10 )
goto V_73;
V_16 = F_24 ( V_6 ) ;
V_71 = F_71 ( V_6 , V_70 ) ;
V_6 -> V_10 = V_10 ;
#ifdef F_13
V_6 -> V_16 = V_16 ;
#endif
#ifdef F_45
F_76 ( & V_6 -> V_38 , 1 ) ;
#endif
if ( V_71 )
goto V_74;
#ifdef F_77
V_6 -> V_75 . V_76 = NULL ;
#endif
F_78 ( V_6 , V_70 ) ;
F_79 ( V_6 ) ;
F_80 ( V_6 ) ;
F_72 ( V_6 ) ;
#ifdef F_81
V_6 -> V_77 = F_82 () ;
#endif
F_76 ( & V_6 -> V_45 , 2 ) ;
#ifdef F_83
V_6 -> V_78 = 0 ;
#endif
V_6 -> V_79 = NULL ;
V_6 -> V_80 . V_24 = NULL ;
V_6 -> V_81 . V_82 = NULL ;
F_33 ( V_6 , 1 ) ;
F_84 ( V_6 ) ;
return V_6 ;
V_74:
F_23 ( V_6 ) ;
V_73:
F_9 ( V_6 ) ;
return NULL ;
}
static T_3 int F_85 ( struct V_83 * V_84 ,
struct V_83 * V_85 )
{
struct V_86 * V_87 , * V_88 , * V_89 , * * V_90 ;
struct V_91 * * V_92 , * V_93 ;
int V_94 ;
unsigned long V_95 ;
F_86 () ;
if ( F_87 ( & V_85 -> V_96 ) ) {
V_94 = - V_97 ;
goto V_98;
}
F_88 ( V_85 ) ;
F_89 ( V_85 , V_84 ) ;
F_90 ( & V_84 -> V_96 , V_99 ) ;
F_91 ( V_84 -> V_100 , F_92 ( V_85 ) ) ;
V_84 -> V_101 = V_85 -> V_101 ;
V_84 -> V_102 = V_85 -> V_102 ;
V_84 -> V_103 = V_85 -> V_103 ;
V_84 -> V_104 = V_85 -> V_104 ;
V_92 = & V_84 -> V_105 . V_91 ;
V_93 = NULL ;
V_90 = & V_84 -> V_106 ;
V_94 = F_93 ( V_84 , V_85 ) ;
if ( V_94 )
goto V_107;
V_94 = F_94 ( V_84 , V_85 ) ;
if ( V_94 )
goto V_107;
V_89 = NULL ;
for ( V_87 = V_85 -> V_106 ; V_87 ; V_87 = V_87 -> V_108 ) {
struct V_109 * V_109 ;
if ( V_87 -> V_110 & V_111 ) {
F_95 ( V_84 , V_87 -> V_110 , - F_96 ( V_87 ) ) ;
continue;
}
V_95 = 0 ;
if ( V_87 -> V_110 & V_112 ) {
unsigned long V_113 = F_96 ( V_87 ) ;
if ( F_97 ( V_85 , V_113 ) )
goto V_114;
V_95 = V_113 ;
}
V_88 = F_98 ( V_115 , V_9 ) ;
if ( ! V_88 )
goto V_114;
* V_88 = * V_87 ;
F_99 ( & V_88 -> V_116 ) ;
V_94 = F_100 ( V_87 , V_88 ) ;
if ( V_94 )
goto V_117;
V_88 -> V_118 = V_84 ;
if ( F_101 ( V_88 , V_87 ) )
goto V_119;
V_88 -> V_110 &=
~ ( V_120 | V_121 | V_122 | V_123 ) ;
V_88 -> V_108 = V_88 -> V_124 = NULL ;
V_88 -> V_125 = V_126 ;
V_109 = V_88 -> V_127 ;
if ( V_109 ) {
struct V_128 * V_128 = F_102 ( V_109 ) ;
struct V_129 * V_130 = V_109 -> V_131 ;
F_103 ( V_109 ) ;
if ( V_88 -> V_110 & V_132 )
F_104 ( & V_128 -> V_133 ) ;
F_105 ( V_130 ) ;
if ( V_88 -> V_110 & V_134 )
F_106 ( & V_130 -> V_135 ) ;
F_107 ( V_130 ) ;
F_108 ( V_88 , V_87 ,
& V_130 -> V_136 ) ;
F_109 ( V_130 ) ;
F_110 ( V_130 ) ;
}
if ( F_111 ( V_88 ) )
F_112 ( V_88 ) ;
* V_90 = V_88 ;
V_90 = & V_88 -> V_108 ;
V_88 -> V_124 = V_89 ;
V_89 = V_88 ;
F_113 ( V_84 , V_88 , V_92 , V_93 ) ;
V_92 = & V_88 -> V_137 . V_138 ;
V_93 = & V_88 -> V_137 ;
V_84 -> V_139 ++ ;
V_94 = F_114 ( V_84 , V_85 , V_87 ) ;
if ( V_88 -> V_140 && V_88 -> V_140 -> V_141 )
V_88 -> V_140 -> V_141 ( V_88 ) ;
if ( V_94 )
goto V_107;
}
F_115 ( V_85 , V_84 ) ;
V_94 = 0 ;
V_107:
F_116 ( & V_84 -> V_96 ) ;
F_117 ( V_85 ) ;
F_116 ( & V_85 -> V_96 ) ;
V_98:
F_118 () ;
return V_94 ;
V_119:
F_119 ( F_120 ( V_88 ) ) ;
V_117:
F_10 ( V_115 , V_88 ) ;
V_114:
V_94 = - V_142 ;
F_121 ( V_95 ) ;
goto V_107;
}
static inline int F_122 ( struct V_83 * V_84 )
{
V_84 -> V_143 = F_123 ( V_84 ) ;
if ( F_124 ( ! V_84 -> V_143 ) )
return - V_142 ;
return 0 ;
}
static inline void F_125 ( struct V_83 * V_84 )
{
F_126 ( V_84 , V_84 -> V_143 ) ;
}
static int F_85 ( struct V_83 * V_84 , struct V_83 * V_85 )
{
F_127 ( & V_85 -> V_96 ) ;
F_91 ( V_84 -> V_100 , F_92 ( V_85 ) ) ;
F_116 ( & V_85 -> V_96 ) ;
return 0 ;
}
static int T_1 F_128 ( char * V_14 )
{
V_144 =
( F_129 ( V_14 , NULL , 0 ) << V_145 ) &
V_146 ;
return 1 ;
}
static void F_130 ( struct V_83 * V_84 )
{
#ifdef F_131
F_132 ( & V_84 -> V_147 ) ;
V_84 -> V_148 = NULL ;
#endif
}
static void F_133 ( struct V_83 * V_84 , struct V_5 * V_149 )
{
#ifdef F_134
V_84 -> V_150 = V_149 ;
#endif
}
static struct V_83 * F_135 ( struct V_83 * V_84 , struct V_5 * V_149 )
{
V_84 -> V_106 = NULL ;
V_84 -> V_105 = V_151 ;
V_84 -> V_152 = 0 ;
F_76 ( & V_84 -> V_153 , 1 ) ;
F_76 ( & V_84 -> V_154 , 1 ) ;
F_136 ( & V_84 -> V_96 ) ;
F_99 ( & V_84 -> V_155 ) ;
V_84 -> V_156 = NULL ;
F_137 ( & V_84 -> V_157 , 0 ) ;
F_138 ( V_84 ) ;
V_84 -> V_139 = 0 ;
V_84 -> V_158 = 0 ;
V_84 -> V_159 = 0 ;
memset ( & V_84 -> V_160 , 0 , sizeof( V_84 -> V_160 ) ) ;
F_132 ( & V_84 -> V_161 ) ;
F_139 ( V_84 ) ;
F_130 ( V_84 ) ;
F_133 ( V_84 , V_149 ) ;
F_140 ( V_84 ) ;
F_141 ( V_84 ) ;
#if F_142 ( V_162 ) && ! V_163
V_84 -> V_164 = NULL ;
#endif
if ( V_46 -> V_84 ) {
V_84 -> V_26 = V_46 -> V_84 -> V_26 & V_165 ;
V_84 -> V_166 = V_46 -> V_84 -> V_166 & V_167 ;
} else {
V_84 -> V_26 = V_144 ;
V_84 -> V_166 = 0 ;
}
if ( F_122 ( V_84 ) )
goto V_168;
if ( F_143 ( V_149 , V_84 ) )
goto V_169;
return V_84 ;
V_169:
F_125 ( V_84 ) ;
V_168:
F_144 ( V_84 ) ;
return NULL ;
}
static void F_145 ( struct V_83 * V_84 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_170 ; V_11 ++ ) {
long V_171 = F_146 ( & V_84 -> V_160 . V_172 [ V_11 ] ) ;
if ( F_124 ( V_171 ) )
F_147 ( V_173 L_3
L_4 , V_84 , V_11 , V_171 ) ;
}
if ( F_146 ( & V_84 -> V_157 ) )
F_148 ( L_5 ,
F_146 ( & V_84 -> V_157 ) ) ;
if ( F_149 ( V_84 ) )
F_148 ( L_6 ,
F_149 ( V_84 ) ) ;
#if F_142 ( V_162 ) && ! V_163
F_150 ( V_84 -> V_164 , V_84 ) ;
#endif
}
struct V_83 * F_151 ( void )
{
struct V_83 * V_84 ;
V_84 = F_152 () ;
if ( ! V_84 )
return NULL ;
memset ( V_84 , 0 , sizeof( * V_84 ) ) ;
return F_135 ( V_84 , V_46 ) ;
}
void F_153 ( struct V_83 * V_84 )
{
F_32 ( V_84 == & V_174 ) ;
F_125 ( V_84 ) ;
F_154 ( V_84 ) ;
F_155 ( V_84 ) ;
F_145 ( V_84 ) ;
F_144 ( V_84 ) ;
}
static inline void F_156 ( struct V_83 * V_84 )
{
F_157 ( F_47 ( & V_84 -> V_153 ) ) ;
F_158 ( V_84 ) ;
F_159 ( V_84 ) ;
F_160 ( V_84 ) ;
F_161 ( V_84 ) ;
F_162 ( V_84 ) ;
F_163 ( V_84 ) ;
F_164 ( V_84 , NULL ) ;
if ( ! F_165 ( & V_84 -> V_155 ) ) {
F_166 ( & V_175 ) ;
F_167 ( & V_84 -> V_155 ) ;
F_168 ( & V_175 ) ;
}
if ( V_84 -> V_176 )
F_169 ( V_84 -> V_176 -> V_177 ) ;
F_170 ( V_178 , & V_84 -> V_26 ) ;
F_171 ( V_84 ) ;
}
void F_172 ( struct V_83 * V_84 )
{
F_173 () ;
if ( F_43 ( & V_84 -> V_153 ) )
F_156 ( V_84 ) ;
}
static void F_174 ( struct V_179 * V_180 )
{
struct V_83 * V_84 = F_175 ( V_180 , struct V_83 , V_181 ) ;
F_156 ( V_84 ) ;
}
void F_176 ( struct V_83 * V_84 )
{
if ( F_43 ( & V_84 -> V_153 ) ) {
F_177 ( & V_84 -> V_181 , F_174 ) ;
F_178 ( & V_84 -> V_181 ) ;
}
}
void F_164 ( struct V_83 * V_84 , struct V_109 * V_182 )
{
struct V_109 * V_183 ;
V_183 = F_179 ( V_84 -> V_100 ) ;
if ( V_182 )
F_103 ( V_182 ) ;
F_180 ( V_84 -> V_100 , V_182 ) ;
if ( V_183 )
F_181 ( V_183 ) ;
}
struct V_109 * F_92 ( struct V_83 * V_84 )
{
struct V_109 * V_100 ;
F_182 () ;
V_100 = F_183 ( V_84 -> V_100 ) ;
if ( V_100 && ! F_184 ( V_100 ) )
V_100 = NULL ;
F_185 () ;
return V_100 ;
}
struct V_109 * F_186 ( struct V_5 * V_184 )
{
struct V_109 * V_100 = NULL ;
struct V_83 * V_84 ;
F_187 ( V_184 ) ;
V_84 = V_184 -> V_84 ;
if ( V_84 ) {
if ( ! ( V_184 -> V_26 & V_185 ) )
V_100 = F_92 ( V_84 ) ;
}
F_188 ( V_184 ) ;
return V_100 ;
}
struct V_83 * F_189 ( struct V_5 * V_184 )
{
struct V_83 * V_84 ;
F_187 ( V_184 ) ;
V_84 = V_184 -> V_84 ;
if ( V_84 ) {
if ( V_184 -> V_26 & V_185 )
V_84 = NULL ;
else
F_106 ( & V_84 -> V_153 ) ;
}
F_188 ( V_184 ) ;
return V_84 ;
}
struct V_83 * F_190 ( struct V_5 * V_184 , unsigned int V_186 )
{
struct V_83 * V_84 ;
int V_71 ;
V_71 = F_191 ( & V_184 -> signal -> V_187 ) ;
if ( V_71 )
return F_192 ( V_71 ) ;
V_84 = F_189 ( V_184 ) ;
if ( V_84 && V_84 != V_46 -> V_84 &&
! F_193 ( V_184 , V_186 ) ) {
F_172 ( V_84 ) ;
V_84 = F_192 ( - V_188 ) ;
}
F_194 ( & V_184 -> signal -> V_187 ) ;
return V_84 ;
}
static void F_195 ( struct V_5 * V_6 )
{
struct V_189 * V_190 ;
F_187 ( V_6 ) ;
V_190 = V_6 -> V_191 ;
if ( F_196 ( V_190 ) ) {
V_6 -> V_191 = NULL ;
F_197 ( V_190 ) ;
}
F_188 ( V_6 ) ;
}
static int F_198 ( struct V_5 * V_192 ,
struct V_189 * V_190 )
{
int V_193 ;
F_199 () ;
V_193 = F_200 ( V_190 ) ;
F_201 () ;
if ( V_193 ) {
F_187 ( V_192 ) ;
V_192 -> V_191 = NULL ;
F_188 ( V_192 ) ;
}
F_202 ( V_192 ) ;
return V_193 ;
}
void F_203 ( struct V_5 * V_6 , struct V_83 * V_84 )
{
#ifdef F_204
if ( F_124 ( V_6 -> V_194 ) ) {
F_205 ( V_6 ) ;
V_6 -> V_194 = NULL ;
}
#ifdef F_206
if ( F_124 ( V_6 -> V_195 ) ) {
F_207 ( V_6 ) ;
V_6 -> V_195 = NULL ;
}
#endif
if ( F_124 ( ! F_165 ( & V_6 -> V_196 ) ) )
F_208 ( V_6 ) ;
#endif
F_209 ( V_6 ) ;
F_210 ( V_6 , V_84 ) ;
if ( V_6 -> V_197 ) {
if ( ! ( V_6 -> signal -> V_26 & V_198 ) &&
F_47 ( & V_84 -> V_153 ) > 1 ) {
F_211 ( 0 , V_6 -> V_197 ) ;
F_212 ( V_6 -> V_197 , V_199 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_197 = NULL ;
}
if ( V_6 -> V_191 )
F_195 ( V_6 ) ;
}
static struct V_83 * F_213 ( struct V_5 * V_6 )
{
struct V_83 * V_84 , * V_85 = V_46 -> V_84 ;
int V_71 ;
V_84 = F_152 () ;
if ( ! V_84 )
goto V_114;
memcpy ( V_84 , V_85 , sizeof( * V_84 ) ) ;
if ( ! F_135 ( V_84 , V_6 ) )
goto V_114;
V_71 = F_85 ( V_84 , V_85 ) ;
if ( V_71 )
goto V_200;
V_84 -> V_201 = F_214 ( V_84 ) ;
V_84 -> V_202 = V_84 -> V_101 ;
if ( V_84 -> V_176 && ! F_215 ( V_84 -> V_176 -> V_177 ) )
goto V_200;
return V_84 ;
V_200:
V_84 -> V_176 = NULL ;
F_172 ( V_84 ) ;
V_114:
return NULL ;
}
static int F_216 ( unsigned long V_203 , struct V_5 * V_6 )
{
struct V_83 * V_84 , * V_85 ;
int V_94 ;
V_6 -> V_204 = V_6 -> V_205 = 0 ;
V_6 -> V_206 = V_6 -> V_207 = 0 ;
#ifdef F_217
V_6 -> V_208 = V_6 -> V_206 + V_6 -> V_207 ;
#endif
V_6 -> V_84 = NULL ;
V_6 -> V_209 = NULL ;
V_85 = V_46 -> V_84 ;
if ( ! V_85 )
return 0 ;
F_218 ( V_6 ) ;
if ( V_203 & V_210 ) {
F_106 ( & V_85 -> V_153 ) ;
V_84 = V_85 ;
goto V_211;
}
V_94 = - V_142 ;
V_84 = F_213 ( V_6 ) ;
if ( ! V_84 )
goto V_114;
V_211:
V_6 -> V_84 = V_84 ;
V_6 -> V_209 = V_84 ;
return 0 ;
V_114:
return V_94 ;
}
static int F_219 ( unsigned long V_203 , struct V_5 * V_6 )
{
struct V_212 * V_213 = V_46 -> V_213 ;
if ( V_203 & V_214 ) {
F_166 ( & V_213 -> V_215 ) ;
if ( V_213 -> V_216 ) {
F_168 ( & V_213 -> V_215 ) ;
return - V_217 ;
}
V_213 -> V_218 ++ ;
F_168 ( & V_213 -> V_215 ) ;
return 0 ;
}
V_6 -> V_213 = F_220 ( V_213 ) ;
if ( ! V_6 -> V_213 )
return - V_142 ;
return 0 ;
}
static int F_221 ( unsigned long V_203 , struct V_5 * V_6 )
{
struct V_219 * V_220 , * V_221 ;
int error = 0 ;
V_220 = V_46 -> V_222 ;
if ( ! V_220 )
goto V_107;
if ( V_203 & V_223 ) {
F_106 ( & V_220 -> V_172 ) ;
goto V_107;
}
V_221 = F_222 ( V_220 , & error ) ;
if ( ! V_221 )
goto V_107;
V_6 -> V_222 = V_221 ;
error = 0 ;
V_107:
return error ;
}
static int F_223 ( unsigned long V_203 , struct V_5 * V_6 )
{
#ifdef F_224
struct V_224 * V_225 = V_46 -> V_224 ;
struct V_224 * V_226 ;
if ( ! V_225 )
return 0 ;
if ( V_203 & V_227 ) {
F_225 ( V_225 ) ;
V_6 -> V_224 = V_225 ;
} else if ( F_226 ( V_225 -> V_228 ) ) {
V_226 = F_227 ( V_6 , V_9 , V_72 ) ;
if ( F_124 ( ! V_226 ) )
return - V_142 ;
V_226 -> V_228 = V_225 -> V_228 ;
F_228 ( V_226 ) ;
}
#endif
return 0 ;
}
static int F_229 ( unsigned long V_203 , struct V_5 * V_6 )
{
struct V_229 * V_40 ;
if ( V_203 & V_230 ) {
F_106 ( & V_46 -> V_231 -> V_172 ) ;
return 0 ;
}
V_40 = F_98 ( V_232 , V_9 ) ;
F_180 ( V_6 -> V_231 , V_40 ) ;
if ( ! V_40 )
return - V_142 ;
F_76 ( & V_40 -> V_172 , 1 ) ;
memcpy ( V_40 -> V_233 , V_46 -> V_231 -> V_233 , sizeof( V_40 -> V_233 ) ) ;
return 0 ;
}
void F_230 ( struct V_229 * V_231 )
{
if ( F_43 ( & V_231 -> V_172 ) ) {
F_231 ( V_231 ) ;
F_10 ( V_232 , V_231 ) ;
}
}
static void F_232 ( struct V_39 * V_40 )
{
unsigned long V_234 ;
V_234 = F_233 ( V_40 -> V_58 [ V_235 ] . V_60 ) ;
if ( V_234 != V_236 ) {
V_40 -> V_237 . V_238 = F_234 ( V_234 ) ;
V_40 -> V_239 . V_240 = true ;
}
F_99 ( & V_40 -> V_241 [ 0 ] ) ;
F_99 ( & V_40 -> V_241 [ 1 ] ) ;
F_99 ( & V_40 -> V_241 [ 2 ] ) ;
}
static int F_235 ( unsigned long V_203 , struct V_5 * V_6 )
{
struct V_39 * V_40 ;
if ( V_203 & V_242 )
return 0 ;
V_40 = F_236 ( V_42 , V_9 ) ;
V_6 -> signal = V_40 ;
if ( ! V_40 )
return - V_142 ;
V_40 -> V_243 = 1 ;
F_76 ( & V_40 -> V_244 , 1 ) ;
F_76 ( & V_40 -> V_43 , 1 ) ;
V_40 -> V_245 = (struct V_246 ) F_237 ( V_6 -> V_247 ) ;
V_6 -> V_247 = (struct V_246 ) F_237 ( V_40 -> V_245 ) ;
F_238 ( & V_40 -> V_248 ) ;
V_40 -> V_249 = V_6 ;
F_239 ( & V_40 -> V_250 ) ;
F_99 ( & V_40 -> V_251 ) ;
F_240 ( & V_40 -> V_252 ) ;
F_241 ( & V_40 -> V_253 ) ;
F_242 ( & V_40 -> V_254 , V_255 , V_256 ) ;
V_40 -> V_254 . V_257 = V_258 ;
F_187 ( V_46 -> V_259 ) ;
memcpy ( V_40 -> V_58 , V_46 -> signal -> V_58 , sizeof V_40 -> V_58 ) ;
F_188 ( V_46 -> V_259 ) ;
F_232 ( V_40 ) ;
F_243 ( V_40 ) ;
F_244 ( V_40 ) ;
V_40 -> V_260 = V_46 -> signal -> V_260 ;
V_40 -> V_261 = V_46 -> signal -> V_261 ;
V_40 -> V_262 = V_46 -> signal -> V_262 ||
V_46 -> signal -> V_263 ;
F_245 ( & V_40 -> V_187 ) ;
return 0 ;
}
static void F_246 ( struct V_5 * V_149 )
{
#ifdef F_77
F_247 ( & V_46 -> V_231 -> V_264 ) ;
F_248 ( V_46 ) ;
V_149 -> V_75 = V_46 -> V_75 ;
if ( F_249 ( V_46 ) )
F_250 ( V_149 ) ;
if ( V_149 -> V_75 . V_186 != V_265 )
F_251 ( V_149 , V_266 ) ;
#endif
}
static void F_252 ( struct V_5 * V_149 )
{
F_253 ( & V_149 -> V_267 ) ;
#ifdef F_254
V_149 -> V_268 = V_151 ;
V_149 -> V_269 = NULL ;
V_149 -> V_270 = NULL ;
#endif
}
static void F_255 ( struct V_5 * V_6 )
{
V_6 -> V_237 . V_238 = 0 ;
V_6 -> V_237 . V_271 = 0 ;
V_6 -> V_237 . V_272 = 0 ;
F_99 ( & V_6 -> V_241 [ 0 ] ) ;
F_99 ( & V_6 -> V_241 [ 1 ] ) ;
F_99 ( & V_6 -> V_241 [ 2 ] ) ;
}
static inline void
F_256 ( struct V_5 * V_184 , enum V_273 type , struct V_274 * V_274 )
{
V_184 -> V_275 [ type ] . V_274 = V_274 ;
}
inline void F_257 ( struct V_276 * V_277 )
{
enum V_273 type ;
for ( type = V_278 ; type < V_279 ; ++ type ) {
F_258 ( & V_277 [ type ] . V_7 ) ;
V_277 [ type ] . V_274 = & V_280 ;
}
}
struct V_5 * F_259 ( int V_2 )
{
struct V_5 * V_184 ;
V_184 = F_260 ( V_210 , 0 , 0 , NULL , & V_280 , 0 , 0 ,
F_261 ( V_2 ) ) ;
if ( ! F_262 ( V_184 ) ) {
F_257 ( V_184 -> V_275 ) ;
F_263 ( V_184 , V_2 ) ;
}
return V_184 ;
}
long F_264 ( unsigned long V_203 ,
unsigned long V_281 ,
unsigned long V_282 ,
int T_4 * V_283 ,
int T_4 * V_284 ,
unsigned long V_285 )
{
struct V_5 * V_149 ;
int V_286 = 0 ;
long V_287 ;
if ( ! ( V_203 & V_288 ) ) {
if ( V_203 & V_289 )
V_286 = V_290 ;
else if ( ( V_203 & V_291 ) != V_292 )
V_286 = V_293 ;
else
V_286 = V_294 ;
if ( F_196 ( ! F_265 ( V_46 , V_286 ) ) )
V_286 = 0 ;
}
V_149 = F_260 ( V_203 , V_281 , V_282 ,
V_284 , NULL , V_286 , V_285 , V_72 ) ;
F_266 () ;
if ( ! F_262 ( V_149 ) ) {
struct V_189 V_190 ;
struct V_274 * V_274 ;
F_267 ( V_46 , V_149 ) ;
V_274 = F_268 ( V_149 , V_278 ) ;
V_287 = F_269 ( V_274 ) ;
if ( V_203 & V_295 )
F_211 ( V_287 , V_283 ) ;
if ( V_203 & V_289 ) {
V_149 -> V_191 = & V_190 ;
F_270 ( & V_190 ) ;
F_271 ( V_149 ) ;
}
F_272 ( V_149 ) ;
if ( F_124 ( V_286 ) )
F_273 ( V_286 , V_274 ) ;
if ( V_203 & V_289 ) {
if ( ! F_198 ( V_149 , & V_190 ) )
F_273 ( V_296 , V_274 ) ;
}
F_274 ( V_274 ) ;
} else {
V_287 = F_275 ( V_149 ) ;
}
return V_287 ;
}
long F_276 ( unsigned long V_203 ,
unsigned long V_281 ,
unsigned long V_282 ,
int T_4 * V_283 ,
int T_4 * V_284 )
{
return F_264 ( V_203 , V_281 , V_282 ,
V_283 , V_284 , 0 ) ;
}
T_5 F_277 ( int (* F_278)( void * ) , void * V_297 , unsigned long V_26 )
{
return F_264 ( V_26 | V_210 | V_288 , ( unsigned long ) F_278 ,
( unsigned long ) V_297 , NULL , NULL , 0 ) ;
}
static void F_279 ( void * V_298 )
{
struct V_229 * V_231 = V_298 ;
F_132 ( & V_231 -> V_264 ) ;
F_238 ( & V_231 -> V_299 ) ;
}
void T_1 F_280 ( void )
{
V_232 = F_31 ( L_7 ,
sizeof( struct V_229 ) , 0 ,
V_300 | V_54 | V_301 |
V_55 | V_56 , F_279 ) ;
V_42 = F_31 ( L_8 ,
sizeof( struct V_39 ) , 0 ,
V_300 | V_54 | V_55 | V_56 ,
NULL ) ;
V_302 = F_31 ( L_9 ,
sizeof( struct V_219 ) , 0 ,
V_300 | V_54 | V_55 | V_56 ,
NULL ) ;
V_303 = F_31 ( L_10 ,
sizeof( struct V_212 ) , 0 ,
V_300 | V_54 | V_55 | V_56 ,
NULL ) ;
V_304 = F_31 ( L_11 ,
sizeof( struct V_83 ) , V_305 ,
V_300 | V_54 | V_55 | V_56 ,
NULL ) ;
V_115 = F_281 ( V_86 , V_54 | V_56 ) ;
F_282 () ;
F_283 () ;
}
static int F_284 ( unsigned long V_306 )
{
if ( V_306 & ~ ( V_242 | V_214 | V_307 | V_230 |
V_210 | V_223 | V_308 |
V_309 | V_310 | V_311 |
V_312 | V_313 | V_314 ) )
return - V_315 ;
if ( V_306 & ( V_242 | V_230 | V_210 ) ) {
if ( ! F_285 ( V_46 ) )
return - V_315 ;
}
if ( V_306 & ( V_230 | V_210 ) ) {
if ( F_47 ( & V_46 -> V_231 -> V_172 ) > 1 )
return - V_315 ;
}
if ( V_306 & V_210 ) {
if ( ! F_286 () )
return - V_315 ;
}
return 0 ;
}
static int F_287 ( unsigned long V_306 , struct V_212 * * V_316 )
{
struct V_212 * V_213 = V_46 -> V_213 ;
if ( ! ( V_306 & V_214 ) || ! V_213 )
return 0 ;
if ( V_213 -> V_218 == 1 )
return 0 ;
* V_316 = F_220 ( V_213 ) ;
if ( ! * V_316 )
return - V_142 ;
return 0 ;
}
static int F_288 ( unsigned long V_306 , struct V_219 * * V_317 )
{
struct V_219 * V_318 = V_46 -> V_222 ;
int error = 0 ;
if ( ( V_306 & V_223 ) &&
( V_318 && F_47 ( & V_318 -> V_172 ) > 1 ) ) {
* V_317 = F_222 ( V_318 , & error ) ;
if ( ! * V_317 )
return error ;
}
return 0 ;
}
int F_289 ( struct V_219 * * V_319 )
{
struct V_5 * V_184 = V_46 ;
struct V_219 * V_320 = NULL ;
int error ;
error = F_288 ( V_223 , & V_320 ) ;
if ( error || ! V_320 ) {
* V_319 = NULL ;
return error ;
}
* V_319 = V_184 -> V_222 ;
F_187 ( V_184 ) ;
V_184 -> V_222 = V_320 ;
F_188 ( V_184 ) ;
return 0 ;
}
int F_290 ( struct V_321 * V_322 , int V_323 ,
void T_4 * V_324 , T_6 * V_325 , T_7 * V_326 )
{
struct V_321 V_327 ;
int V_328 ;
int V_48 = V_51 ;
int V_329 = V_52 ;
int V_330 = V_50 ;
V_327 = * V_322 ;
V_327 . V_298 = & V_48 ;
V_327 . V_331 = & V_329 ;
V_327 . V_332 = & V_330 ;
V_328 = F_291 ( & V_327 , V_323 , V_324 , V_325 , V_326 ) ;
if ( V_328 || ! V_323 )
return V_328 ;
F_64 ( V_48 ) ;
return 0 ;
}
