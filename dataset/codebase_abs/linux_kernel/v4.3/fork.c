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
F_31 ( V_6 -> signal ) ;
if ( ! F_40 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_41 ( void ) { }
static void F_42 ( unsigned int V_28 )
{
T_2 V_29 ;
if ( F_43 ( V_30 ) + F_43 ( V_31 ) > 64 )
V_29 = V_32 ;
else
V_29 = F_44 ( ( T_2 ) V_30 * ( T_2 ) V_31 ,
( T_2 ) V_16 * 8UL ) ;
if ( V_29 > V_28 )
V_29 = V_28 ;
V_33 = F_45 ( T_2 , V_29 , V_34 , V_32 ) ;
}
void T_1 F_46 ( void )
{
#ifndef F_47
#ifndef F_48
#define F_48 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , V_35 ,
F_48 , V_36 | V_37 , NULL ) ;
#endif
F_41 () ;
F_42 ( V_32 ) ;
V_38 . signal -> V_39 [ V_40 ] . V_41 = V_33 / 2 ;
V_38 . signal -> V_39 [ V_40 ] . V_42 = V_33 / 2 ;
V_38 . signal -> V_39 [ V_43 ] =
V_38 . signal -> V_39 [ V_40 ] ;
}
int __weak F_49 ( struct V_5 * V_44 ,
struct V_5 * V_45 )
{
* V_44 = * V_45 ;
return 0 ;
}
void F_50 ( struct V_5 * V_6 )
{
unsigned long * V_46 ;
V_46 = F_51 ( V_6 ) ;
* V_46 = V_47 ;
}
static struct V_5 * F_52 ( struct V_5 * V_48 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_7 = F_53 ( V_48 ) ;
int V_49 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_50;
V_49 = F_49 ( V_6 , V_48 ) ;
if ( V_49 )
goto V_51;
V_6 -> V_20 = V_11 ;
#ifdef F_54
V_6 -> V_52 . V_53 = NULL ;
#endif
F_55 ( V_6 , V_48 ) ;
F_56 ( V_6 ) ;
F_57 ( V_6 ) ;
F_50 ( V_6 ) ;
#ifdef F_58
V_6 -> V_54 = F_59 () ;
#endif
F_60 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_61
V_6 -> V_55 = 0 ;
#endif
V_6 -> V_56 = NULL ;
V_6 -> V_57 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_51:
F_15 ( V_11 ) ;
V_50:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_62 ( struct V_58 * V_59 , struct V_58 * V_60 )
{
struct V_61 * V_62 , * V_63 , * V_64 , * * V_65 ;
struct V_66 * * V_67 , * V_68 ;
int V_69 ;
unsigned long V_70 ;
F_63 () ;
F_64 ( & V_60 -> V_71 ) ;
F_65 ( V_60 ) ;
F_66 ( V_60 , V_59 ) ;
F_67 ( & V_59 -> V_71 , V_72 ) ;
F_68 ( V_59 -> V_73 , F_69 ( V_60 ) ) ;
V_59 -> V_74 = V_60 -> V_74 ;
V_59 -> V_75 = V_60 -> V_75 ;
V_59 -> V_76 = V_60 -> V_76 ;
V_59 -> V_77 = V_60 -> V_77 ;
V_67 = & V_59 -> V_78 . V_66 ;
V_68 = NULL ;
V_65 = & V_59 -> V_79 ;
V_69 = F_70 ( V_59 , V_60 ) ;
if ( V_69 )
goto V_80;
V_69 = F_71 ( V_59 , V_60 ) ;
if ( V_69 )
goto V_80;
V_64 = NULL ;
for ( V_62 = V_60 -> V_79 ; V_62 ; V_62 = V_62 -> V_81 ) {
struct V_82 * V_82 ;
if ( V_62 -> V_83 & V_84 ) {
F_72 ( V_59 , V_62 -> V_83 , V_62 -> V_85 ,
- F_73 ( V_62 ) ) ;
continue;
}
V_70 = 0 ;
if ( V_62 -> V_83 & V_86 ) {
unsigned long V_87 = F_73 ( V_62 ) ;
if ( F_74 ( V_60 , V_87 ) )
goto V_88;
V_70 = V_87 ;
}
V_63 = F_75 ( V_89 , V_9 ) ;
if ( ! V_63 )
goto V_88;
* V_63 = * V_62 ;
F_76 ( & V_63 -> V_90 ) ;
V_69 = F_77 ( V_62 , V_63 ) ;
if ( V_69 )
goto V_91;
V_63 -> V_92 = V_59 ;
if ( F_78 ( V_63 , V_62 ) )
goto V_93;
V_63 -> V_83 &= ~ ( V_94 | V_95 | V_96 ) ;
V_63 -> V_81 = V_63 -> V_97 = NULL ;
V_63 -> V_98 = V_99 ;
V_82 = V_63 -> V_85 ;
if ( V_82 ) {
struct V_100 * V_100 = F_79 ( V_82 ) ;
struct V_101 * V_102 = V_82 -> V_103 ;
F_80 ( V_82 ) ;
if ( V_63 -> V_83 & V_104 )
F_81 ( & V_100 -> V_105 ) ;
F_82 ( V_102 ) ;
if ( V_63 -> V_83 & V_106 )
F_83 ( & V_102 -> V_107 ) ;
F_84 ( V_102 ) ;
F_85 ( V_63 , V_62 ,
& V_102 -> V_108 ) ;
F_86 ( V_102 ) ;
F_87 ( V_102 ) ;
}
if ( F_88 ( V_63 ) )
F_89 ( V_63 ) ;
* V_65 = V_63 ;
V_65 = & V_63 -> V_81 ;
V_63 -> V_97 = V_64 ;
V_64 = V_63 ;
F_90 ( V_59 , V_63 , V_67 , V_68 ) ;
V_67 = & V_63 -> V_109 . V_110 ;
V_68 = & V_63 -> V_109 ;
V_59 -> V_111 ++ ;
V_69 = F_91 ( V_59 , V_60 , V_62 ) ;
if ( V_63 -> V_112 && V_63 -> V_112 -> V_113 )
V_63 -> V_112 -> V_113 ( V_63 ) ;
if ( V_69 )
goto V_80;
}
F_92 ( V_60 , V_59 ) ;
V_69 = 0 ;
V_80:
F_93 ( & V_59 -> V_71 ) ;
F_94 ( V_60 ) ;
F_93 ( & V_60 -> V_71 ) ;
F_95 () ;
return V_69 ;
V_93:
F_96 ( F_97 ( V_63 ) ) ;
V_91:
F_10 ( V_89 , V_63 ) ;
V_88:
V_69 = - V_114 ;
F_98 ( V_70 ) ;
goto V_80;
}
static inline int F_99 ( struct V_58 * V_59 )
{
V_59 -> V_115 = F_100 ( V_59 ) ;
if ( F_101 ( ! V_59 -> V_115 ) )
return - V_114 ;
return 0 ;
}
static inline void F_102 ( struct V_58 * V_59 )
{
F_103 ( V_59 , V_59 -> V_115 ) ;
}
static int F_62 ( struct V_58 * V_59 , struct V_58 * V_60 )
{
F_64 ( & V_60 -> V_71 ) ;
F_68 ( V_59 -> V_73 , F_69 ( V_60 ) ) ;
F_93 ( & V_60 -> V_71 ) ;
return 0 ;
}
static int T_1 F_104 ( char * V_116 )
{
V_117 =
( F_105 ( V_116 , NULL , 0 ) << V_118 ) &
V_119 ;
return 1 ;
}
static void F_106 ( struct V_58 * V_59 )
{
#ifdef F_107
F_108 ( & V_59 -> V_120 ) ;
V_59 -> V_121 = NULL ;
#endif
}
static void F_109 ( struct V_58 * V_59 , struct V_5 * V_122 )
{
#ifdef F_110
V_59 -> V_123 = V_122 ;
#endif
}
static struct V_58 * F_111 ( struct V_58 * V_59 , struct V_5 * V_122 )
{
V_59 -> V_79 = NULL ;
V_59 -> V_78 = V_124 ;
V_59 -> V_125 = 0 ;
F_60 ( & V_59 -> V_126 , 1 ) ;
F_60 ( & V_59 -> V_127 , 1 ) ;
F_112 ( & V_59 -> V_71 ) ;
F_76 ( & V_59 -> V_128 ) ;
V_59 -> V_129 = NULL ;
F_113 ( & V_59 -> V_130 , 0 ) ;
F_114 ( V_59 ) ;
V_59 -> V_111 = 0 ;
V_59 -> V_131 = 0 ;
V_59 -> V_132 = 0 ;
memset ( & V_59 -> V_133 , 0 , sizeof( V_59 -> V_133 ) ) ;
F_108 ( & V_59 -> V_134 ) ;
F_115 ( V_59 ) ;
F_106 ( V_59 ) ;
F_109 ( V_59 , V_122 ) ;
F_116 ( V_59 ) ;
F_117 ( V_59 ) ;
#if F_118 ( V_135 ) && ! V_136
V_59 -> V_137 = NULL ;
#endif
if ( V_27 -> V_59 ) {
V_59 -> V_138 = V_27 -> V_59 -> V_138 & V_139 ;
V_59 -> V_140 = V_27 -> V_59 -> V_140 & V_141 ;
} else {
V_59 -> V_138 = V_117 ;
V_59 -> V_140 = 0 ;
}
if ( F_99 ( V_59 ) )
goto V_142;
if ( F_119 ( V_122 , V_59 ) )
goto V_143;
return V_59 ;
V_143:
F_102 ( V_59 ) ;
V_142:
F_120 ( V_59 ) ;
return NULL ;
}
static void F_121 ( struct V_58 * V_59 )
{
int V_144 ;
for ( V_144 = 0 ; V_144 < V_145 ; V_144 ++ ) {
long V_146 = F_122 ( & V_59 -> V_133 . V_147 [ V_144 ] ) ;
if ( F_101 ( V_146 ) )
F_123 ( V_148 L_3
L_4 , V_59 , V_144 , V_146 ) ;
}
if ( F_122 ( & V_59 -> V_130 ) )
F_124 ( L_5 ,
F_122 ( & V_59 -> V_130 ) ) ;
if ( F_125 ( V_59 ) )
F_124 ( L_6 ,
F_125 ( V_59 ) ) ;
#if F_118 ( V_135 ) && ! V_136
F_126 ( V_59 -> V_137 , V_59 ) ;
#endif
}
struct V_58 * F_127 ( void )
{
struct V_58 * V_59 ;
V_59 = F_128 () ;
if ( ! V_59 )
return NULL ;
memset ( V_59 , 0 , sizeof( * V_59 ) ) ;
return F_111 ( V_59 , V_27 ) ;
}
void F_129 ( struct V_58 * V_59 )
{
F_19 ( V_59 == & V_149 ) ;
F_102 ( V_59 ) ;
F_130 ( V_59 ) ;
F_131 ( V_59 ) ;
F_121 ( V_59 ) ;
F_120 ( V_59 ) ;
}
void F_132 ( struct V_58 * V_59 )
{
F_133 () ;
if ( F_32 ( & V_59 -> V_126 ) ) {
F_134 ( V_59 ) ;
F_135 ( V_59 ) ;
F_136 ( V_59 ) ;
F_137 ( V_59 ) ;
F_138 ( V_59 ) ;
F_139 ( V_59 , NULL ) ;
if ( ! F_140 ( & V_59 -> V_128 ) ) {
F_141 ( & V_150 ) ;
F_142 ( & V_59 -> V_128 ) ;
F_143 ( & V_150 ) ;
}
if ( V_59 -> V_151 )
F_144 ( V_59 -> V_151 -> V_152 ) ;
F_145 ( V_59 ) ;
}
}
void F_139 ( struct V_58 * V_59 , struct V_82 * V_153 )
{
struct V_82 * V_154 ;
V_154 = F_146 ( V_59 -> V_73 ) ;
if ( V_153 )
F_80 ( V_153 ) ;
F_147 ( V_59 -> V_73 , V_153 ) ;
if ( V_154 )
F_148 ( V_154 ) ;
}
struct V_82 * F_69 ( struct V_58 * V_59 )
{
struct V_82 * V_73 ;
F_149 () ;
V_73 = F_150 ( V_59 -> V_73 ) ;
if ( V_73 && ! F_151 ( V_73 ) )
V_73 = NULL ;
F_152 () ;
return V_73 ;
}
struct V_58 * F_153 ( struct V_5 * V_155 )
{
struct V_58 * V_59 ;
F_154 ( V_155 ) ;
V_59 = V_155 -> V_59 ;
if ( V_59 ) {
if ( V_155 -> V_138 & V_156 )
V_59 = NULL ;
else
F_83 ( & V_59 -> V_126 ) ;
}
F_155 ( V_155 ) ;
return V_59 ;
}
struct V_58 * F_156 ( struct V_5 * V_155 , unsigned int V_157 )
{
struct V_58 * V_59 ;
int V_49 ;
V_49 = F_157 ( & V_155 -> signal -> V_158 ) ;
if ( V_49 )
return F_158 ( V_49 ) ;
V_59 = F_153 ( V_155 ) ;
if ( V_59 && V_59 != V_27 -> V_59 &&
! F_159 ( V_155 , V_157 ) ) {
F_132 ( V_59 ) ;
V_59 = F_158 ( - V_159 ) ;
}
F_160 ( & V_155 -> signal -> V_158 ) ;
return V_59 ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_160 * V_161 ;
F_154 ( V_6 ) ;
V_161 = V_6 -> V_162 ;
if ( F_162 ( V_161 ) ) {
V_6 -> V_162 = NULL ;
F_163 ( V_161 ) ;
}
F_155 ( V_6 ) ;
}
static int F_164 ( struct V_5 * V_163 ,
struct V_160 * V_161 )
{
int V_164 ;
F_165 () ;
V_164 = F_166 ( V_161 ) ;
F_167 () ;
if ( V_164 ) {
F_154 ( V_163 ) ;
V_163 -> V_162 = NULL ;
F_155 ( V_163 ) ;
}
F_168 ( V_163 ) ;
return V_164 ;
}
void F_169 ( struct V_5 * V_6 , struct V_58 * V_59 )
{
#ifdef F_170
if ( F_101 ( V_6 -> V_165 ) ) {
F_171 ( V_6 ) ;
V_6 -> V_165 = NULL ;
}
#ifdef F_172
if ( F_101 ( V_6 -> V_166 ) ) {
F_173 ( V_6 ) ;
V_6 -> V_166 = NULL ;
}
#endif
if ( F_101 ( ! F_140 ( & V_6 -> V_167 ) ) )
F_174 ( V_6 ) ;
#endif
F_175 ( V_6 ) ;
F_176 ( V_6 , V_59 ) ;
if ( V_6 -> V_168 ) {
if ( ! ( V_6 -> V_138 & V_169 ) &&
F_35 ( & V_59 -> V_126 ) > 1 ) {
F_177 ( 0 , V_6 -> V_168 ) ;
F_178 ( V_6 -> V_168 , V_170 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_168 = NULL ;
}
if ( V_6 -> V_162 )
F_161 ( V_6 ) ;
}
static struct V_58 * F_179 ( struct V_5 * V_6 )
{
struct V_58 * V_59 , * V_60 = V_27 -> V_59 ;
int V_49 ;
V_59 = F_128 () ;
if ( ! V_59 )
goto V_88;
memcpy ( V_59 , V_60 , sizeof( * V_59 ) ) ;
if ( ! F_111 ( V_59 , V_6 ) )
goto V_88;
V_49 = F_62 ( V_59 , V_60 ) ;
if ( V_49 )
goto V_171;
V_59 -> V_172 = F_180 ( V_59 ) ;
V_59 -> V_173 = V_59 -> V_74 ;
if ( V_59 -> V_151 && ! F_181 ( V_59 -> V_151 -> V_152 ) )
goto V_171;
return V_59 ;
V_171:
V_59 -> V_151 = NULL ;
F_132 ( V_59 ) ;
V_88:
return NULL ;
}
static int F_182 ( unsigned long V_174 , struct V_5 * V_6 )
{
struct V_58 * V_59 , * V_60 ;
int V_69 ;
V_6 -> V_175 = V_6 -> V_176 = 0 ;
V_6 -> V_177 = V_6 -> V_178 = 0 ;
#ifdef F_183
V_6 -> V_179 = V_6 -> V_177 + V_6 -> V_178 ;
#endif
V_6 -> V_59 = NULL ;
V_6 -> V_180 = NULL ;
V_60 = V_27 -> V_59 ;
if ( ! V_60 )
return 0 ;
F_184 ( V_6 ) ;
if ( V_174 & V_181 ) {
F_83 ( & V_60 -> V_126 ) ;
V_59 = V_60 ;
goto V_182;
}
V_69 = - V_114 ;
V_59 = F_179 ( V_6 ) ;
if ( ! V_59 )
goto V_88;
V_182:
V_6 -> V_59 = V_59 ;
V_6 -> V_180 = V_59 ;
return 0 ;
V_88:
return V_69 ;
}
static int F_185 ( unsigned long V_174 , struct V_5 * V_6 )
{
struct V_183 * V_184 = V_27 -> V_184 ;
if ( V_174 & V_185 ) {
F_141 ( & V_184 -> V_186 ) ;
if ( V_184 -> V_187 ) {
F_143 ( & V_184 -> V_186 ) ;
return - V_188 ;
}
V_184 -> V_189 ++ ;
F_143 ( & V_184 -> V_186 ) ;
return 0 ;
}
V_6 -> V_184 = F_186 ( V_184 ) ;
if ( ! V_6 -> V_184 )
return - V_114 ;
return 0 ;
}
static int F_187 ( unsigned long V_174 , struct V_5 * V_6 )
{
struct V_190 * V_191 , * V_192 ;
int error = 0 ;
V_191 = V_27 -> V_193 ;
if ( ! V_191 )
goto V_80;
if ( V_174 & V_194 ) {
F_83 ( & V_191 -> V_147 ) ;
goto V_80;
}
V_192 = F_188 ( V_191 , & error ) ;
if ( ! V_192 )
goto V_80;
V_6 -> V_193 = V_192 ;
error = 0 ;
V_80:
return error ;
}
static int F_189 ( unsigned long V_174 , struct V_5 * V_6 )
{
#ifdef F_190
struct V_195 * V_196 = V_27 -> V_195 ;
struct V_195 * V_197 ;
if ( ! V_196 )
return 0 ;
if ( V_174 & V_198 ) {
F_191 ( V_196 ) ;
V_6 -> V_195 = V_196 ;
} else if ( F_192 ( V_196 -> V_199 ) ) {
V_197 = F_193 ( V_6 , V_9 , V_200 ) ;
if ( F_101 ( ! V_197 ) )
return - V_114 ;
V_197 -> V_199 = V_196 -> V_199 ;
F_194 ( V_197 ) ;
}
#endif
return 0 ;
}
static int F_195 ( unsigned long V_174 , struct V_5 * V_6 )
{
struct V_201 * V_22 ;
if ( V_174 & V_202 ) {
F_83 ( & V_27 -> V_203 -> V_147 ) ;
return 0 ;
}
V_22 = F_75 ( V_204 , V_9 ) ;
F_147 ( V_6 -> V_203 , V_22 ) ;
if ( ! V_22 )
return - V_114 ;
F_60 ( & V_22 -> V_147 , 1 ) ;
memcpy ( V_22 -> V_205 , V_27 -> V_203 -> V_205 , sizeof( V_22 -> V_205 ) ) ;
return 0 ;
}
void F_196 ( struct V_201 * V_203 )
{
if ( F_32 ( & V_203 -> V_147 ) ) {
F_197 ( V_203 ) ;
F_10 ( V_204 , V_203 ) ;
}
}
static void F_198 ( struct V_21 * V_22 )
{
unsigned long V_206 ;
V_206 = F_199 ( V_22 -> V_39 [ V_207 ] . V_41 ) ;
if ( V_206 != V_208 ) {
V_22 -> V_209 . V_210 = F_200 ( V_206 ) ;
V_22 -> V_211 . V_212 = 1 ;
}
F_76 ( & V_22 -> V_213 [ 0 ] ) ;
F_76 ( & V_22 -> V_213 [ 1 ] ) ;
F_76 ( & V_22 -> V_213 [ 2 ] ) ;
}
static int F_201 ( unsigned long V_174 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_174 & V_214 )
return 0 ;
V_22 = F_202 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_114 ;
V_22 -> V_215 = 1 ;
F_60 ( & V_22 -> V_216 , 1 ) ;
F_60 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_217 = (struct V_218 ) F_203 ( V_6 -> V_219 ) ;
V_6 -> V_219 = (struct V_218 ) F_203 ( V_22 -> V_217 ) ;
F_204 ( & V_22 -> V_220 ) ;
V_22 -> V_221 = V_6 ;
F_205 ( & V_22 -> V_222 ) ;
F_76 ( & V_22 -> V_223 ) ;
F_206 ( & V_22 -> V_224 ) ;
F_207 ( & V_22 -> V_225 ) ;
F_208 ( & V_22 -> V_226 , V_227 , V_228 ) ;
V_22 -> V_226 . V_229 = V_230 ;
F_154 ( V_27 -> V_231 ) ;
memcpy ( V_22 -> V_39 , V_27 -> signal -> V_39 , sizeof V_22 -> V_39 ) ;
F_155 ( V_27 -> V_231 ) ;
F_198 ( V_22 ) ;
F_209 ( V_22 ) ;
F_210 ( V_22 ) ;
#ifdef F_211
F_112 ( & V_22 -> V_232 ) ;
#endif
V_22 -> V_233 = V_27 -> signal -> V_233 ;
V_22 -> V_234 = V_27 -> signal -> V_234 ;
V_22 -> V_235 = V_27 -> signal -> V_235 ||
V_27 -> signal -> V_236 ;
F_212 ( & V_22 -> V_158 ) ;
return 0 ;
}
static void F_213 ( struct V_5 * V_122 )
{
#ifdef F_54
F_214 ( & V_27 -> V_203 -> V_237 ) ;
F_215 ( V_27 ) ;
V_122 -> V_52 = V_27 -> V_52 ;
if ( F_216 ( V_27 ) )
F_217 ( V_122 ) ;
if ( V_122 -> V_52 . V_157 != V_238 )
F_218 ( V_122 , V_239 ) ;
#endif
}
static void F_219 ( struct V_5 * V_122 )
{
F_220 ( & V_122 -> V_240 ) ;
#ifdef F_221
V_122 -> V_241 = V_124 ;
V_122 -> V_242 = NULL ;
V_122 -> V_243 = NULL ;
#endif
}
static void F_222 ( struct V_5 * V_6 )
{
V_6 -> V_209 . V_210 = 0 ;
V_6 -> V_209 . V_244 = 0 ;
V_6 -> V_209 . V_245 = 0 ;
F_76 ( & V_6 -> V_213 [ 0 ] ) ;
F_76 ( & V_6 -> V_213 [ 1 ] ) ;
F_76 ( & V_6 -> V_213 [ 2 ] ) ;
}
static inline void
F_223 ( struct V_5 * V_155 , enum V_246 type , struct V_247 * V_247 )
{
V_155 -> V_248 [ type ] . V_247 = V_247 ;
}
static struct V_5 * F_224 ( unsigned long V_174 ,
unsigned long V_249 ,
unsigned long V_250 ,
int T_3 * V_251 ,
struct V_247 * V_247 ,
int V_252 ,
unsigned long V_253 )
{
int V_69 ;
struct V_5 * V_122 ;
void * V_254 [ V_255 ] = {} ;
if ( ( V_174 & ( V_256 | V_185 ) ) == ( V_256 | V_185 ) )
return F_158 ( - V_257 ) ;
if ( ( V_174 & ( V_258 | V_185 ) ) == ( V_258 | V_185 ) )
return F_158 ( - V_257 ) ;
if ( ( V_174 & V_214 ) && ! ( V_174 & V_202 ) )
return F_158 ( - V_257 ) ;
if ( ( V_174 & V_202 ) && ! ( V_174 & V_181 ) )
return F_158 ( - V_257 ) ;
if ( ( V_174 & V_259 ) &&
V_27 -> signal -> V_138 & V_260 )
return F_158 ( - V_257 ) ;
if ( V_174 & V_214 ) {
if ( ( V_174 & ( V_258 | V_261 ) ) ||
( F_225 ( V_27 ) !=
V_27 -> V_262 -> V_263 ) )
return F_158 ( - V_257 ) ;
}
V_69 = F_226 ( V_174 ) ;
if ( V_69 )
goto V_264;
V_69 = - V_114 ;
V_122 = F_52 ( V_27 ) ;
if ( ! V_122 )
goto V_264;
F_227 ( V_122 ) ;
F_219 ( V_122 ) ;
#ifdef F_228
F_229 ( ! V_122 -> V_265 ) ;
F_229 ( ! V_122 -> V_266 ) ;
#endif
V_69 = - V_188 ;
if ( F_35 ( & V_122 -> V_267 -> V_268 -> V_269 ) >=
F_230 ( V_122 , V_40 ) ) {
if ( V_122 -> V_267 -> V_268 != V_270 &&
! F_231 ( V_271 ) && ! F_231 ( V_272 ) )
goto V_273;
}
V_27 -> V_138 &= ~ V_274 ;
V_69 = F_232 ( V_122 , V_174 ) ;
if ( V_69 < 0 )
goto V_273;
V_69 = - V_188 ;
if ( V_215 >= V_33 )
goto V_275;
F_233 ( V_122 ) ;
V_122 -> V_138 &= ~ ( V_276 | V_277 ) ;
V_122 -> V_138 |= V_278 ;
F_76 ( & V_122 -> V_279 ) ;
F_76 ( & V_122 -> V_280 ) ;
F_234 ( V_122 ) ;
V_122 -> V_162 = NULL ;
F_108 ( & V_122 -> V_281 ) ;
F_205 ( & V_122 -> V_282 ) ;
V_122 -> V_283 = V_122 -> V_284 = V_122 -> V_285 = 0 ;
V_122 -> V_286 = V_122 -> V_287 = 0 ;
F_207 ( & V_122 -> V_225 ) ;
#ifdef F_235
F_206 ( & V_122 -> V_288 ) ;
V_122 -> V_289 = 0 ;
V_122 -> V_290 = V_291 ;
#endif
#if F_118 ( V_292 )
memset ( & V_122 -> V_133 , 0 , sizeof( V_122 -> V_133 ) ) ;
#endif
V_122 -> V_293 = V_27 -> V_294 ;
F_236 ( & V_122 -> V_295 ) ;
F_237 ( V_122 ) ;
F_222 ( V_122 ) ;
V_122 -> V_296 = F_238 () ;
V_122 -> V_297 = F_239 () ;
V_122 -> V_195 = NULL ;
V_122 -> V_298 = NULL ;
if ( V_174 & V_214 )
F_240 ( V_27 ) ;
F_241 ( V_122 ) ;
#ifdef F_242
V_122 -> V_299 = F_243 ( V_122 -> V_299 ) ;
if ( F_244 ( V_122 -> V_299 ) ) {
V_69 = F_245 ( V_122 -> V_299 ) ;
V_122 -> V_299 = NULL ;
goto V_300;
}
#endif
#ifdef F_246
V_122 -> V_301 = V_200 ;
V_122 -> V_302 = V_200 ;
F_247 ( & V_122 -> V_303 ) ;
#endif
#ifdef F_248
V_122 -> V_304 = 0 ;
V_122 -> V_265 = 0 ;
V_122 -> V_305 = 0 ;
V_122 -> V_306 = 0 ;
V_122 -> V_307 = V_308 ;
V_122 -> V_309 = 0 ;
V_122 -> V_266 = 1 ;
V_122 -> V_310 = V_308 ;
V_122 -> V_311 = 0 ;
V_122 -> V_312 = 0 ;
V_122 -> V_313 = 0 ;
V_122 -> V_314 = 0 ;
V_122 -> V_315 = 0 ;
#endif
V_122 -> V_316 = 0 ;
#ifdef F_249
V_122 -> V_317 = 0 ;
V_122 -> V_318 = 0 ;
V_122 -> V_319 = 0 ;
#endif
#ifdef F_250
V_122 -> V_320 = NULL ;
#endif
#ifdef F_251
V_122 -> V_321 = 0 ;
V_122 -> V_322 = 0 ;
#endif
V_69 = F_252 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_323;
V_69 = F_253 ( V_122 ) ;
if ( V_69 )
goto V_323;
V_69 = F_254 ( V_122 ) ;
if ( V_69 )
goto V_324;
F_255 ( V_122 ) ;
V_69 = F_256 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_325;
V_69 = F_187 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_326;
V_69 = F_185 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_327;
V_69 = F_195 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_328;
V_69 = F_201 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_329;
V_69 = F_182 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_330;
V_69 = F_257 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_331;
V_69 = F_189 ( V_174 , V_122 ) ;
if ( V_69 )
goto V_332;
V_69 = F_258 ( V_174 , V_249 , V_250 , V_122 , V_253 ) ;
if ( V_69 )
goto V_333;
if ( V_247 != & V_334 ) {
V_247 = F_259 ( V_122 -> V_262 -> V_263 ) ;
if ( F_244 ( V_247 ) ) {
V_69 = F_245 ( V_247 ) ;
goto V_333;
}
}
V_122 -> V_335 = ( V_174 & V_336 ) ? V_251 : NULL ;
V_122 -> V_168 = ( V_174 & V_337 ) ? V_251 : NULL ;
#ifdef F_190
V_122 -> V_338 = NULL ;
#endif
#ifdef F_170
V_122 -> V_165 = NULL ;
#ifdef F_172
V_122 -> V_166 = NULL ;
#endif
F_76 ( & V_122 -> V_167 ) ;
V_122 -> V_339 = NULL ;
#endif
if ( ( V_174 & ( V_181 | V_340 ) ) == V_181 )
V_122 -> V_341 = V_122 -> V_342 = 0 ;
F_260 ( V_122 ) ;
F_261 ( V_122 , V_343 ) ;
#ifdef F_262
F_261 ( V_122 , F_262 ) ;
#endif
F_263 ( V_122 ) ;
V_122 -> V_247 = F_264 ( V_247 ) ;
if ( V_174 & V_214 ) {
V_122 -> V_344 = - 1 ;
V_122 -> V_231 = V_27 -> V_231 ;
V_122 -> V_345 = V_27 -> V_345 ;
} else {
if ( V_174 & V_259 )
V_122 -> V_344 = V_27 -> V_231 -> V_344 ;
else
V_122 -> V_344 = ( V_174 & V_346 ) ;
V_122 -> V_231 = V_122 ;
V_122 -> V_345 = V_122 -> V_247 ;
}
V_122 -> V_347 = 0 ;
V_122 -> V_348 = 128 >> ( V_349 - 10 ) ;
V_122 -> V_350 = 0 ;
V_122 -> V_351 = 0 ;
F_76 ( & V_122 -> V_352 ) ;
V_122 -> V_353 = NULL ;
V_69 = F_265 ( V_122 , V_254 ) ;
if ( V_69 )
goto V_354;
F_266 ( & V_1 ) ;
if ( V_174 & ( V_259 | V_214 ) ) {
V_122 -> V_355 = V_27 -> V_355 ;
V_122 -> V_356 = V_27 -> V_356 ;
} else {
V_122 -> V_355 = V_27 ;
V_122 -> V_356 = V_27 -> V_357 ;
}
F_141 ( & V_27 -> V_203 -> V_237 ) ;
F_213 ( V_122 ) ;
F_267 () ;
if ( F_268 ( V_27 ) ) {
F_143 ( & V_27 -> V_203 -> V_237 ) ;
F_269 ( & V_1 ) ;
V_69 = - V_358 ;
goto V_359;
}
if ( F_162 ( V_122 -> V_247 ) ) {
F_270 ( V_122 , ( V_174 & V_360 ) || V_252 ) ;
F_223 ( V_122 , V_361 , V_247 ) ;
if ( F_271 ( V_122 ) ) {
F_223 ( V_122 , V_362 , F_272 ( V_27 ) ) ;
F_223 ( V_122 , V_363 , F_273 ( V_27 ) ) ;
if ( F_274 ( V_247 ) ) {
F_275 ( V_247 ) -> V_364 = V_122 ;
V_122 -> signal -> V_138 |= V_260 ;
}
V_122 -> signal -> V_365 = V_247 ;
V_122 -> signal -> V_366 = F_276 ( V_27 -> signal -> V_366 ) ;
F_277 ( & V_122 -> V_280 , & V_122 -> V_355 -> V_279 ) ;
F_278 ( & V_122 -> V_367 , & V_38 . V_367 ) ;
F_279 ( V_122 , V_362 ) ;
F_279 ( V_122 , V_363 ) ;
F_280 ( V_4 ) ;
} else {
V_27 -> signal -> V_215 ++ ;
F_83 ( & V_27 -> signal -> V_216 ) ;
F_83 ( & V_27 -> signal -> V_24 ) ;
F_278 ( & V_122 -> V_352 ,
& V_122 -> V_231 -> V_352 ) ;
F_278 ( & V_122 -> V_219 ,
& V_122 -> signal -> V_217 ) ;
}
F_279 ( V_122 , V_361 ) ;
V_215 ++ ;
}
V_368 ++ ;
F_143 ( & V_27 -> V_203 -> V_237 ) ;
F_281 ( V_122 ) ;
F_269 ( & V_1 ) ;
F_282 ( V_122 ) ;
F_283 ( V_122 , V_254 ) ;
if ( V_174 & V_214 )
F_284 ( V_27 ) ;
F_285 ( V_122 ) ;
F_286 ( V_122 , V_174 ) ;
F_287 ( V_122 , V_174 ) ;
return V_122 ;
V_359:
F_288 ( V_122 , V_254 ) ;
V_354:
if ( V_247 != & V_334 )
F_289 ( V_247 ) ;
V_333:
if ( V_122 -> V_195 )
F_290 ( V_122 ) ;
V_332:
F_291 ( V_122 ) ;
V_331:
if ( V_122 -> V_59 )
F_132 ( V_122 -> V_59 ) ;
V_330:
if ( ! ( V_174 & V_214 ) )
F_28 ( V_122 -> signal ) ;
V_329:
F_196 ( V_122 -> V_203 ) ;
V_328:
F_292 ( V_122 ) ;
V_327:
F_293 ( V_122 ) ;
V_326:
F_294 ( V_122 ) ;
V_325:
F_295 ( V_122 ) ;
V_324:
F_296 ( V_122 ) ;
V_323:
#ifdef F_242
F_96 ( V_122 -> V_299 ) ;
V_300:
#endif
if ( V_174 & V_214 )
F_284 ( V_27 ) ;
F_39 ( V_122 ) ;
V_275:
F_81 ( & V_122 -> V_369 -> V_268 -> V_269 ) ;
F_38 ( V_122 ) ;
V_273:
F_24 ( V_122 ) ;
V_264:
return F_158 ( V_69 ) ;
}
static inline void F_297 ( struct V_370 * V_371 )
{
enum V_246 type ;
for ( type = V_361 ; type < V_372 ; ++ type ) {
F_298 ( & V_371 [ type ] . V_7 ) ;
V_371 [ type ] . V_247 = & V_334 ;
}
}
struct V_5 * F_299 ( int V_2 )
{
struct V_5 * V_155 ;
V_155 = F_224 ( V_181 , 0 , 0 , NULL , & V_334 , 0 , 0 ) ;
if ( ! F_244 ( V_155 ) ) {
F_297 ( V_155 -> V_248 ) ;
F_300 ( V_155 , V_2 ) ;
}
return V_155 ;
}
long F_301 ( unsigned long V_174 ,
unsigned long V_249 ,
unsigned long V_250 ,
int T_3 * V_373 ,
int T_3 * V_251 ,
unsigned long V_253 )
{
struct V_5 * V_122 ;
int V_252 = 0 ;
long V_374 ;
if ( ! ( V_174 & V_375 ) ) {
if ( V_174 & V_340 )
V_252 = V_376 ;
else if ( ( V_174 & V_346 ) != V_377 )
V_252 = V_378 ;
else
V_252 = V_379 ;
if ( F_162 ( ! F_302 ( V_27 , V_252 ) ) )
V_252 = 0 ;
}
V_122 = F_224 ( V_174 , V_249 , V_250 ,
V_251 , NULL , V_252 , V_253 ) ;
if ( ! F_244 ( V_122 ) ) {
struct V_160 V_161 ;
struct V_247 * V_247 ;
F_303 ( V_27 , V_122 ) ;
V_247 = F_304 ( V_122 , V_361 ) ;
V_374 = F_305 ( V_247 ) ;
if ( V_174 & V_380 )
F_177 ( V_374 , V_373 ) ;
if ( V_174 & V_340 ) {
V_122 -> V_162 = & V_161 ;
F_306 ( & V_161 ) ;
F_307 ( V_122 ) ;
}
F_308 ( V_122 ) ;
if ( F_101 ( V_252 ) )
F_309 ( V_252 , V_247 ) ;
if ( V_174 & V_340 ) {
if ( ! F_164 ( V_122 , & V_161 ) )
F_309 ( V_381 , V_247 ) ;
}
F_310 ( V_247 ) ;
} else {
V_374 = F_245 ( V_122 ) ;
}
return V_374 ;
}
long F_311 ( unsigned long V_174 ,
unsigned long V_249 ,
unsigned long V_250 ,
int T_3 * V_373 ,
int T_3 * V_251 )
{
return F_301 ( V_174 , V_249 , V_250 ,
V_373 , V_251 , 0 ) ;
}
T_4 F_312 ( int (* F_313)( void * ) , void * V_382 , unsigned long V_138 )
{
return F_301 ( V_138 | V_181 | V_375 , ( unsigned long ) F_313 ,
( unsigned long ) V_382 , NULL , NULL , 0 ) ;
}
static void F_314 ( void * V_383 )
{
struct V_201 * V_203 = V_383 ;
F_108 ( & V_203 -> V_237 ) ;
F_204 ( & V_203 -> V_384 ) ;
}
void T_1 F_315 ( void )
{
V_204 = F_18 ( L_7 ,
sizeof( struct V_201 ) , 0 ,
V_385 | V_36 | V_386 |
V_37 , F_314 ) ;
V_23 = F_18 ( L_8 ,
sizeof( struct V_21 ) , 0 ,
V_385 | V_36 | V_37 , NULL ) ;
V_387 = F_18 ( L_9 ,
sizeof( struct V_190 ) , 0 ,
V_385 | V_36 | V_37 , NULL ) ;
V_388 = F_18 ( L_10 ,
sizeof( struct V_183 ) , 0 ,
V_385 | V_36 | V_37 , NULL ) ;
V_389 = F_18 ( L_11 ,
sizeof( struct V_58 ) , V_390 ,
V_385 | V_36 | V_37 , NULL ) ;
V_89 = F_316 ( V_61 , V_36 ) ;
F_317 () ;
F_318 () ;
}
static int F_319 ( unsigned long V_391 )
{
if ( V_391 & ~ ( V_214 | V_185 | V_256 | V_202 |
V_181 | V_194 | V_392 |
V_393 | V_394 | V_395 |
V_258 | V_261 ) )
return - V_257 ;
if ( V_391 & ( V_214 | V_202 | V_181 ) ) {
if ( ! F_320 ( V_27 ) )
return - V_257 ;
}
if ( V_391 & ( V_202 | V_181 ) ) {
if ( F_35 ( & V_27 -> V_203 -> V_147 ) > 1 )
return - V_257 ;
}
if ( V_391 & V_181 ) {
if ( ! F_321 () )
return - V_257 ;
}
return 0 ;
}
static int F_322 ( unsigned long V_391 , struct V_183 * * V_396 )
{
struct V_183 * V_184 = V_27 -> V_184 ;
if ( ! ( V_391 & V_185 ) || ! V_184 )
return 0 ;
if ( V_184 -> V_189 == 1 )
return 0 ;
* V_396 = F_186 ( V_184 ) ;
if ( ! * V_396 )
return - V_114 ;
return 0 ;
}
static int F_323 ( unsigned long V_391 , struct V_190 * * V_397 )
{
struct V_190 * V_398 = V_27 -> V_193 ;
int error = 0 ;
if ( ( V_391 & V_194 ) &&
( V_398 && F_35 ( & V_398 -> V_147 ) > 1 ) ) {
* V_397 = F_188 ( V_398 , & error ) ;
if ( ! * V_397 )
return error ;
}
return 0 ;
}
int F_324 ( struct V_190 * * V_399 )
{
struct V_5 * V_155 = V_27 ;
struct V_190 * V_400 = NULL ;
int error ;
error = F_323 ( V_194 , & V_400 ) ;
if ( error || ! V_400 ) {
* V_399 = NULL ;
return error ;
}
* V_399 = V_155 -> V_193 ;
F_154 ( V_155 ) ;
V_155 -> V_193 = V_400 ;
F_155 ( V_155 ) ;
return 0 ;
}
int F_325 ( struct V_401 * V_402 , int V_403 ,
void T_3 * V_404 , T_5 * V_405 , T_6 * V_406 )
{
struct V_401 V_407 ;
int V_408 ;
int V_29 = V_33 ;
int V_409 = V_34 ;
int V_410 = V_32 ;
V_407 = * V_402 ;
V_407 . V_383 = & V_29 ;
V_407 . V_411 = & V_409 ;
V_407 . V_412 = & V_410 ;
V_408 = F_326 ( & V_407 , V_403 , V_404 , V_405 , V_406 ) ;
if ( V_408 || ! V_403 )
return V_408 ;
F_42 ( V_29 ) ;
return 0 ;
}
