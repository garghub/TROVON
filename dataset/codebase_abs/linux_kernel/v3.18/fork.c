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
void T_1 F_42 ( unsigned long V_28 )
{
#ifndef F_43
#ifndef F_44
#define F_44 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , sizeof( struct V_5 ) ,
F_44 , V_29 | V_30 , NULL ) ;
#endif
F_41 () ;
V_31 = V_28 / ( 8 * V_16 / V_32 ) ;
if ( V_31 < 20 )
V_31 = 20 ;
V_33 . signal -> V_34 [ V_35 ] . V_36 = V_31 / 2 ;
V_33 . signal -> V_34 [ V_35 ] . V_37 = V_31 / 2 ;
V_33 . signal -> V_34 [ V_38 ] =
V_33 . signal -> V_34 [ V_35 ] ;
}
int __weak F_45 ( struct V_5 * V_39 ,
struct V_5 * V_40 )
{
* V_39 = * V_40 ;
return 0 ;
}
void F_46 ( struct V_5 * V_6 )
{
unsigned long * V_41 ;
V_41 = F_47 ( V_6 ) ;
* V_41 = V_42 ;
}
static struct V_5 * F_48 ( struct V_5 * V_43 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_7 = F_49 ( V_43 ) ;
int V_44 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_45;
V_44 = F_45 ( V_6 , V_43 ) ;
if ( V_44 )
goto V_46;
V_6 -> V_20 = V_11 ;
#ifdef F_50
V_6 -> V_47 . V_48 = NULL ;
#endif
F_51 ( V_6 , V_43 ) ;
F_52 ( V_6 ) ;
F_53 ( V_6 ) ;
F_46 ( V_6 ) ;
#ifdef F_54
V_6 -> V_49 = F_55 () ;
#endif
F_56 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_57
V_6 -> V_50 = 0 ;
#endif
V_6 -> V_51 = NULL ;
V_6 -> V_52 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_46:
F_15 ( V_11 ) ;
V_45:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_58 ( struct V_53 * V_54 , struct V_53 * V_55 )
{
struct V_56 * V_57 , * V_58 , * V_59 , * * V_60 ;
struct V_61 * * V_62 , * V_63 ;
int V_64 ;
unsigned long V_65 ;
F_59 () ;
F_60 ( & V_55 -> V_66 ) ;
F_61 ( V_55 ) ;
F_62 ( V_55 , V_54 ) ;
F_63 ( & V_54 -> V_66 , V_67 ) ;
V_54 -> V_68 = V_55 -> V_68 ;
V_54 -> V_69 = V_55 -> V_69 ;
V_54 -> V_70 = V_55 -> V_70 ;
V_54 -> V_71 = V_55 -> V_71 ;
V_62 = & V_54 -> V_72 . V_61 ;
V_63 = NULL ;
V_60 = & V_54 -> V_73 ;
V_64 = F_64 ( V_54 , V_55 ) ;
if ( V_64 )
goto V_74;
V_64 = F_65 ( V_54 , V_55 ) ;
if ( V_64 )
goto V_74;
V_59 = NULL ;
for ( V_57 = V_55 -> V_73 ; V_57 ; V_57 = V_57 -> V_75 ) {
struct V_76 * V_76 ;
if ( V_57 -> V_77 & V_78 ) {
F_66 ( V_54 , V_57 -> V_77 , V_57 -> V_79 ,
- F_67 ( V_57 ) ) ;
continue;
}
V_65 = 0 ;
if ( V_57 -> V_77 & V_80 ) {
unsigned long V_81 = F_67 ( V_57 ) ;
if ( F_68 ( V_55 , V_81 ) )
goto V_82;
V_65 = V_81 ;
}
V_58 = F_69 ( V_83 , V_9 ) ;
if ( ! V_58 )
goto V_82;
* V_58 = * V_57 ;
F_70 ( & V_58 -> V_84 ) ;
V_64 = F_71 ( V_57 , V_58 ) ;
if ( V_64 )
goto V_85;
V_58 -> V_86 = V_54 ;
if ( F_72 ( V_58 , V_57 ) )
goto V_87;
V_58 -> V_77 &= ~ V_88 ;
V_58 -> V_75 = V_58 -> V_89 = NULL ;
V_76 = V_58 -> V_79 ;
if ( V_76 ) {
struct V_90 * V_90 = F_73 ( V_76 ) ;
struct V_91 * V_92 = V_76 -> V_93 ;
F_74 ( V_76 ) ;
if ( V_58 -> V_77 & V_94 )
F_75 ( & V_90 -> V_95 ) ;
F_76 ( & V_92 -> V_96 ) ;
if ( V_58 -> V_77 & V_97 )
F_77 ( & V_92 -> V_98 ) ;
F_78 ( V_92 ) ;
if ( F_79 ( V_58 -> V_77 & V_99 ) )
F_80 ( V_58 ,
& V_92 -> V_100 ) ;
else
F_81 ( V_58 , V_57 ,
& V_92 -> V_101 ) ;
F_82 ( V_92 ) ;
F_83 ( & V_92 -> V_96 ) ;
}
if ( F_84 ( V_58 ) )
F_85 ( V_58 ) ;
* V_60 = V_58 ;
V_60 = & V_58 -> V_75 ;
V_58 -> V_89 = V_59 ;
V_59 = V_58 ;
F_86 ( V_54 , V_58 , V_62 , V_63 ) ;
V_62 = & V_58 -> V_102 . V_103 ;
V_63 = & V_58 -> V_102 ;
V_54 -> V_104 ++ ;
V_64 = F_87 ( V_54 , V_55 , V_57 ) ;
if ( V_58 -> V_105 && V_58 -> V_105 -> V_106 )
V_58 -> V_105 -> V_106 ( V_58 ) ;
if ( V_64 )
goto V_74;
}
F_88 ( V_55 , V_54 ) ;
V_64 = 0 ;
V_74:
F_89 ( & V_54 -> V_66 ) ;
F_90 ( V_55 ) ;
F_89 ( & V_55 -> V_66 ) ;
F_91 () ;
return V_64 ;
V_87:
F_92 ( F_93 ( V_58 ) ) ;
V_85:
F_10 ( V_83 , V_58 ) ;
V_82:
V_64 = - V_107 ;
F_94 ( V_65 ) ;
goto V_74;
}
static inline int F_95 ( struct V_53 * V_54 )
{
V_54 -> V_108 = F_96 ( V_54 ) ;
if ( F_79 ( ! V_54 -> V_108 ) )
return - V_107 ;
return 0 ;
}
static inline void F_97 ( struct V_53 * V_54 )
{
F_98 ( V_54 , V_54 -> V_108 ) ;
}
static int T_1 F_99 ( char * V_109 )
{
V_110 =
( F_100 ( V_109 , NULL , 0 ) << V_111 ) &
V_112 ;
return 1 ;
}
static void F_101 ( struct V_53 * V_54 )
{
#ifdef F_102
F_103 ( & V_54 -> V_113 ) ;
V_54 -> V_114 = NULL ;
#endif
}
static void F_104 ( struct V_53 * V_54 , struct V_5 * V_115 )
{
#ifdef F_105
V_54 -> V_116 = V_115 ;
#endif
}
static struct V_53 * F_106 ( struct V_53 * V_54 , struct V_5 * V_115 )
{
V_54 -> V_73 = NULL ;
V_54 -> V_72 = V_117 ;
V_54 -> V_118 = 0 ;
F_56 ( & V_54 -> V_119 , 1 ) ;
F_56 ( & V_54 -> V_120 , 1 ) ;
F_107 ( & V_54 -> V_66 ) ;
F_70 ( & V_54 -> V_121 ) ;
V_54 -> V_122 = NULL ;
F_108 ( & V_54 -> V_123 , 0 ) ;
V_54 -> V_104 = 0 ;
V_54 -> V_124 = 0 ;
V_54 -> V_125 = 0 ;
memset ( & V_54 -> V_126 , 0 , sizeof( V_54 -> V_126 ) ) ;
F_103 ( & V_54 -> V_127 ) ;
F_109 ( V_54 ) ;
F_101 ( V_54 ) ;
F_104 ( V_54 , V_115 ) ;
F_110 ( V_54 ) ;
F_111 ( V_54 ) ;
#if F_112 ( V_128 ) && ! V_129
V_54 -> V_130 = NULL ;
#endif
if ( V_27 -> V_54 ) {
V_54 -> V_131 = V_27 -> V_54 -> V_131 & V_132 ;
V_54 -> V_133 = V_27 -> V_54 -> V_133 & V_134 ;
} else {
V_54 -> V_131 = V_110 ;
V_54 -> V_133 = 0 ;
}
if ( F_95 ( V_54 ) )
goto V_135;
if ( F_113 ( V_115 , V_54 ) )
goto V_136;
return V_54 ;
V_136:
F_97 ( V_54 ) ;
V_135:
F_114 ( V_54 ) ;
return NULL ;
}
static void F_115 ( struct V_53 * V_54 )
{
int V_137 ;
for ( V_137 = 0 ; V_137 < V_138 ; V_137 ++ ) {
long V_139 = F_116 ( & V_54 -> V_126 . V_140 [ V_137 ] ) ;
if ( F_79 ( V_139 ) )
F_117 ( V_141 L_3
L_4 , V_54 , V_137 , V_139 ) ;
}
#if F_112 ( V_128 ) && ! V_129
F_118 ( V_54 -> V_130 , V_54 ) ;
#endif
}
struct V_53 * F_119 ( void )
{
struct V_53 * V_54 ;
V_54 = F_120 () ;
if ( ! V_54 )
return NULL ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
return F_106 ( V_54 , V_27 ) ;
}
void F_121 ( struct V_53 * V_54 )
{
F_19 ( V_54 == & V_142 ) ;
F_97 ( V_54 ) ;
F_122 ( V_54 ) ;
F_123 ( V_54 ) ;
F_115 ( V_54 ) ;
F_114 ( V_54 ) ;
}
void F_124 ( struct V_53 * V_54 )
{
F_125 () ;
if ( F_32 ( & V_54 -> V_119 ) ) {
F_126 ( V_54 ) ;
F_127 ( V_54 ) ;
F_128 ( V_54 ) ;
F_129 ( V_54 ) ;
F_130 ( V_54 ) ;
F_131 ( V_54 , NULL ) ;
if ( ! F_132 ( & V_54 -> V_121 ) ) {
F_133 ( & V_143 ) ;
F_134 ( & V_54 -> V_121 ) ;
F_135 ( & V_143 ) ;
}
if ( V_54 -> V_144 )
F_136 ( V_54 -> V_144 -> V_145 ) ;
F_137 ( V_54 ) ;
}
}
void F_131 ( struct V_53 * V_54 , struct V_76 * V_146 )
{
if ( V_146 )
F_74 ( V_146 ) ;
if ( V_54 -> V_147 )
F_138 ( V_54 -> V_147 ) ;
V_54 -> V_147 = V_146 ;
}
struct V_76 * F_139 ( struct V_53 * V_54 )
{
struct V_76 * V_147 ;
F_140 ( & V_54 -> V_66 ) ;
V_147 = V_54 -> V_147 ;
if ( V_147 )
F_74 ( V_147 ) ;
F_141 ( & V_54 -> V_66 ) ;
return V_147 ;
}
static void F_142 ( struct V_53 * V_55 , struct V_53 * V_148 )
{
V_148 -> V_147 = F_139 ( V_55 ) ;
}
struct V_53 * F_143 ( struct V_5 * V_149 )
{
struct V_53 * V_54 ;
F_144 ( V_149 ) ;
V_54 = V_149 -> V_54 ;
if ( V_54 ) {
if ( V_149 -> V_131 & V_150 )
V_54 = NULL ;
else
F_77 ( & V_54 -> V_119 ) ;
}
F_145 ( V_149 ) ;
return V_54 ;
}
struct V_53 * F_146 ( struct V_5 * V_149 , unsigned int V_151 )
{
struct V_53 * V_54 ;
int V_44 ;
V_44 = F_147 ( & V_149 -> signal -> V_152 ) ;
if ( V_44 )
return F_148 ( V_44 ) ;
V_54 = F_143 ( V_149 ) ;
if ( V_54 && V_54 != V_27 -> V_54 &&
! F_149 ( V_149 , V_151 ) ) {
F_124 ( V_54 ) ;
V_54 = F_148 ( - V_153 ) ;
}
F_83 ( & V_149 -> signal -> V_152 ) ;
return V_54 ;
}
static void F_150 ( struct V_5 * V_6 )
{
struct V_154 * V_155 ;
F_144 ( V_6 ) ;
V_155 = V_6 -> V_156 ;
if ( F_151 ( V_155 ) ) {
V_6 -> V_156 = NULL ;
F_152 ( V_155 ) ;
}
F_145 ( V_6 ) ;
}
static int F_153 ( struct V_5 * V_157 ,
struct V_154 * V_155 )
{
int V_158 ;
F_154 () ;
V_158 = F_155 ( V_155 ) ;
F_156 () ;
if ( V_158 ) {
F_144 ( V_157 ) ;
V_157 -> V_156 = NULL ;
F_145 ( V_157 ) ;
}
F_157 ( V_157 ) ;
return V_158 ;
}
void F_158 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
#ifdef F_159
if ( F_79 ( V_6 -> V_159 ) ) {
F_160 ( V_6 ) ;
V_6 -> V_159 = NULL ;
}
#ifdef F_161
if ( F_79 ( V_6 -> V_160 ) ) {
F_162 ( V_6 ) ;
V_6 -> V_160 = NULL ;
}
#endif
if ( F_79 ( ! F_132 ( & V_6 -> V_161 ) ) )
F_163 ( V_6 ) ;
#endif
F_164 ( V_6 ) ;
F_165 ( V_6 , V_54 ) ;
if ( V_6 -> V_162 ) {
if ( ! ( V_6 -> V_131 & V_163 ) &&
F_35 ( & V_54 -> V_119 ) > 1 ) {
F_166 ( 0 , V_6 -> V_162 ) ;
F_167 ( V_6 -> V_162 , V_164 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_162 = NULL ;
}
if ( V_6 -> V_156 )
F_150 ( V_6 ) ;
}
static struct V_53 * F_168 ( struct V_5 * V_6 )
{
struct V_53 * V_54 , * V_55 = V_27 -> V_54 ;
int V_44 ;
V_54 = F_120 () ;
if ( ! V_54 )
goto V_82;
memcpy ( V_54 , V_55 , sizeof( * V_54 ) ) ;
if ( ! F_106 ( V_54 , V_6 ) )
goto V_82;
F_142 ( V_55 , V_54 ) ;
V_44 = F_58 ( V_54 , V_55 ) ;
if ( V_44 )
goto V_165;
V_54 -> V_166 = F_169 ( V_54 ) ;
V_54 -> V_167 = V_54 -> V_68 ;
if ( V_54 -> V_144 && ! F_170 ( V_54 -> V_144 -> V_145 ) )
goto V_165;
return V_54 ;
V_165:
V_54 -> V_144 = NULL ;
F_124 ( V_54 ) ;
V_82:
return NULL ;
}
static int F_171 ( unsigned long V_168 , struct V_5 * V_6 )
{
struct V_53 * V_54 , * V_55 ;
int V_64 ;
V_6 -> V_169 = V_6 -> V_170 = 0 ;
V_6 -> V_171 = V_6 -> V_172 = 0 ;
#ifdef F_172
V_6 -> V_173 = V_6 -> V_171 + V_6 -> V_172 ;
#endif
V_6 -> V_54 = NULL ;
V_6 -> V_174 = NULL ;
V_55 = V_27 -> V_54 ;
if ( ! V_55 )
return 0 ;
F_173 ( V_6 ) ;
if ( V_168 & V_175 ) {
F_77 ( & V_55 -> V_119 ) ;
V_54 = V_55 ;
goto V_176;
}
V_64 = - V_107 ;
V_54 = F_168 ( V_6 ) ;
if ( ! V_54 )
goto V_82;
V_176:
V_6 -> V_54 = V_54 ;
V_6 -> V_174 = V_54 ;
return 0 ;
V_82:
return V_64 ;
}
static int F_174 ( unsigned long V_168 , struct V_5 * V_6 )
{
struct V_177 * V_178 = V_27 -> V_178 ;
if ( V_168 & V_179 ) {
F_133 ( & V_178 -> V_180 ) ;
if ( V_178 -> V_181 ) {
F_135 ( & V_178 -> V_180 ) ;
return - V_182 ;
}
V_178 -> V_183 ++ ;
F_135 ( & V_178 -> V_180 ) ;
return 0 ;
}
V_6 -> V_178 = F_175 ( V_178 ) ;
if ( ! V_6 -> V_178 )
return - V_107 ;
return 0 ;
}
static int F_176 ( unsigned long V_168 , struct V_5 * V_6 )
{
struct V_184 * V_185 , * V_186 ;
int error = 0 ;
V_185 = V_27 -> V_187 ;
if ( ! V_185 )
goto V_74;
if ( V_168 & V_188 ) {
F_77 ( & V_185 -> V_140 ) ;
goto V_74;
}
V_186 = F_177 ( V_185 , & error ) ;
if ( ! V_186 )
goto V_74;
V_6 -> V_187 = V_186 ;
error = 0 ;
V_74:
return error ;
}
static int F_178 ( unsigned long V_168 , struct V_5 * V_6 )
{
#ifdef F_179
struct V_189 * V_190 = V_27 -> V_189 ;
struct V_189 * V_191 ;
if ( ! V_190 )
return 0 ;
if ( V_168 & V_192 ) {
F_180 ( V_190 ) ;
V_6 -> V_189 = V_190 ;
} else if ( F_181 ( V_190 -> V_193 ) ) {
V_191 = F_182 ( V_6 , V_9 , V_194 ) ;
if ( F_79 ( ! V_191 ) )
return - V_107 ;
V_191 -> V_193 = V_190 -> V_193 ;
F_183 ( V_191 ) ;
}
#endif
return 0 ;
}
static int F_184 ( unsigned long V_168 , struct V_5 * V_6 )
{
struct V_195 * V_22 ;
if ( V_168 & V_196 ) {
F_77 ( & V_27 -> V_197 -> V_140 ) ;
return 0 ;
}
V_22 = F_69 ( V_198 , V_9 ) ;
F_185 ( V_6 -> V_197 , V_22 ) ;
if ( ! V_22 )
return - V_107 ;
F_56 ( & V_22 -> V_140 , 1 ) ;
memcpy ( V_22 -> V_199 , V_27 -> V_197 -> V_199 , sizeof( V_22 -> V_199 ) ) ;
return 0 ;
}
void F_186 ( struct V_195 * V_197 )
{
if ( F_32 ( & V_197 -> V_140 ) ) {
F_187 ( V_197 ) ;
F_10 ( V_198 , V_197 ) ;
}
}
static void F_188 ( struct V_21 * V_22 )
{
unsigned long V_200 ;
F_189 ( V_22 ) ;
V_200 = F_190 ( V_22 -> V_34 [ V_201 ] . V_36 ) ;
if ( V_200 != V_202 ) {
V_22 -> V_203 . V_204 = F_191 ( V_200 ) ;
V_22 -> V_205 . V_206 = 1 ;
}
F_70 ( & V_22 -> V_207 [ 0 ] ) ;
F_70 ( & V_22 -> V_207 [ 1 ] ) ;
F_70 ( & V_22 -> V_207 [ 2 ] ) ;
}
static int F_192 ( unsigned long V_168 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_168 & V_208 )
return 0 ;
V_22 = F_193 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_107 ;
V_22 -> V_209 = 1 ;
F_56 ( & V_22 -> V_210 , 1 ) ;
F_56 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_211 = (struct V_212 ) F_194 ( V_6 -> V_213 ) ;
V_6 -> V_213 = (struct V_212 ) F_194 ( V_22 -> V_211 ) ;
F_195 ( & V_22 -> V_214 ) ;
V_22 -> V_215 = V_6 ;
F_196 ( & V_22 -> V_216 ) ;
F_70 ( & V_22 -> V_217 ) ;
F_197 ( & V_22 -> V_218 ) ;
F_198 ( & V_22 -> V_219 , V_220 , V_221 ) ;
V_22 -> V_219 . V_222 = V_223 ;
F_144 ( V_27 -> V_224 ) ;
memcpy ( V_22 -> V_34 , V_27 -> signal -> V_34 , sizeof V_22 -> V_34 ) ;
F_145 ( V_27 -> V_224 ) ;
F_188 ( V_22 ) ;
F_199 ( V_22 ) ;
F_200 ( V_22 ) ;
#ifdef F_201
F_107 ( & V_22 -> V_225 ) ;
#endif
V_22 -> V_226 = V_27 -> signal -> V_226 ;
V_22 -> V_227 = V_27 -> signal -> V_227 ;
V_22 -> V_228 = V_27 -> signal -> V_228 ||
V_27 -> signal -> V_229 ;
F_202 ( & V_22 -> V_152 ) ;
return 0 ;
}
static void F_203 ( struct V_5 * V_115 )
{
#ifdef F_50
F_204 ( & V_27 -> V_197 -> V_230 ) ;
F_205 ( V_27 ) ;
V_115 -> V_47 = V_27 -> V_47 ;
if ( F_206 ( V_27 ) )
F_207 ( V_115 ) ;
if ( V_115 -> V_47 . V_151 != V_231 )
F_208 ( V_115 , V_232 ) ;
#endif
}
static void F_209 ( struct V_5 * V_115 )
{
F_210 ( & V_115 -> V_233 ) ;
#ifdef F_211
V_115 -> V_234 = V_117 ;
V_115 -> V_235 = NULL ;
V_115 -> V_236 = NULL ;
#endif
}
static void F_212 ( struct V_5 * V_6 )
{
V_6 -> V_203 . V_204 = 0 ;
V_6 -> V_203 . V_237 = 0 ;
V_6 -> V_203 . V_238 = 0 ;
F_70 ( & V_6 -> V_207 [ 0 ] ) ;
F_70 ( & V_6 -> V_207 [ 1 ] ) ;
F_70 ( & V_6 -> V_207 [ 2 ] ) ;
}
static inline void
F_213 ( struct V_5 * V_149 , enum V_239 type , struct V_240 * V_240 )
{
V_149 -> V_241 [ type ] . V_240 = V_240 ;
}
static struct V_5 * F_214 ( unsigned long V_168 ,
unsigned long V_242 ,
unsigned long V_243 ,
int T_2 * V_244 ,
struct V_240 * V_240 ,
int V_245 )
{
int V_64 ;
struct V_5 * V_115 ;
if ( ( V_168 & ( V_246 | V_179 ) ) == ( V_246 | V_179 ) )
return F_148 ( - V_247 ) ;
if ( ( V_168 & ( V_248 | V_179 ) ) == ( V_248 | V_179 ) )
return F_148 ( - V_247 ) ;
if ( ( V_168 & V_208 ) && ! ( V_168 & V_196 ) )
return F_148 ( - V_247 ) ;
if ( ( V_168 & V_196 ) && ! ( V_168 & V_175 ) )
return F_148 ( - V_247 ) ;
if ( ( V_168 & V_249 ) &&
V_27 -> signal -> V_131 & V_250 )
return F_148 ( - V_247 ) ;
if ( V_168 & V_196 ) {
if ( ( V_168 & ( V_248 | V_251 ) ) ||
( F_215 ( V_27 ) !=
V_27 -> V_252 -> V_253 ) )
return F_148 ( - V_247 ) ;
}
V_64 = F_216 ( V_168 ) ;
if ( V_64 )
goto V_254;
V_64 = - V_107 ;
V_115 = F_48 ( V_27 ) ;
if ( ! V_115 )
goto V_254;
F_217 ( V_115 ) ;
F_209 ( V_115 ) ;
#ifdef F_218
F_219 ( ! V_115 -> V_255 ) ;
F_219 ( ! V_115 -> V_256 ) ;
#endif
V_64 = - V_182 ;
if ( F_35 ( & V_115 -> V_257 -> V_258 -> V_259 ) >=
F_220 ( V_115 , V_35 ) ) {
if ( V_115 -> V_257 -> V_258 != V_260 &&
! F_221 ( V_261 ) && ! F_221 ( V_262 ) )
goto V_263;
}
V_27 -> V_131 &= ~ V_264 ;
V_64 = F_222 ( V_115 , V_168 ) ;
if ( V_64 < 0 )
goto V_263;
V_64 = - V_182 ;
if ( V_209 >= V_31 )
goto V_265;
if ( ! F_170 ( F_223 ( V_115 ) -> V_266 -> V_145 ) )
goto V_265;
F_224 ( V_115 ) ;
V_115 -> V_131 &= ~ ( V_267 | V_268 ) ;
V_115 -> V_131 |= V_269 ;
F_70 ( & V_115 -> V_270 ) ;
F_70 ( & V_115 -> V_271 ) ;
F_225 ( V_115 ) ;
V_115 -> V_156 = NULL ;
F_103 ( & V_115 -> V_272 ) ;
F_196 ( & V_115 -> V_273 ) ;
V_115 -> V_274 = V_115 -> V_275 = V_115 -> V_276 = 0 ;
V_115 -> V_277 = V_115 -> V_278 = 0 ;
#ifndef F_226
V_115 -> V_279 . V_274 = V_115 -> V_279 . V_275 = 0 ;
#endif
#ifdef F_227
F_197 ( & V_115 -> V_280 ) ;
V_115 -> V_281 = 0 ;
V_115 -> V_282 = V_283 ;
#endif
#if F_112 ( V_284 )
memset ( & V_115 -> V_126 , 0 , sizeof( V_115 -> V_126 ) ) ;
#endif
V_115 -> V_285 = V_27 -> V_286 ;
F_228 ( & V_115 -> V_287 ) ;
F_229 ( V_115 ) ;
F_212 ( V_115 ) ;
V_115 -> V_288 = F_230 () ;
V_115 -> V_289 = F_231 () ;
V_115 -> V_189 = NULL ;
V_115 -> V_290 = NULL ;
if ( V_168 & V_208 )
F_232 ( V_27 ) ;
F_233 ( V_115 ) ;
#ifdef F_234
V_115 -> V_291 = F_235 ( V_115 -> V_291 ) ;
if ( F_236 ( V_115 -> V_291 ) ) {
V_64 = F_237 ( V_115 -> V_291 ) ;
V_115 -> V_291 = NULL ;
goto V_292;
}
#endif
#ifdef F_238
V_115 -> V_293 = V_194 ;
V_115 -> V_294 = V_194 ;
F_239 ( & V_115 -> V_295 ) ;
#endif
#ifdef F_240
V_115 -> V_296 = 0 ;
V_115 -> V_255 = 0 ;
V_115 -> V_297 = 0 ;
V_115 -> V_298 = 0 ;
V_115 -> V_299 = V_300 ;
V_115 -> V_301 = 0 ;
V_115 -> V_256 = 1 ;
V_115 -> V_302 = V_300 ;
V_115 -> V_303 = 0 ;
V_115 -> V_304 = 0 ;
V_115 -> V_305 = 0 ;
V_115 -> V_306 = 0 ;
V_115 -> V_307 = 0 ;
#endif
#ifdef F_241
V_115 -> V_308 = 0 ;
V_115 -> V_309 = 0 ;
V_115 -> V_310 = 0 ;
#endif
#ifdef F_242
V_115 -> V_311 = NULL ;
#endif
#ifdef F_243
V_115 -> V_312 = 0 ;
V_115 -> V_313 = 0 ;
#endif
V_64 = F_244 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_314;
V_64 = F_245 ( V_115 ) ;
if ( V_64 )
goto V_314;
V_64 = F_246 ( V_115 ) ;
if ( V_64 )
goto V_315;
F_247 ( V_115 ) ;
V_64 = F_248 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_316;
V_64 = F_176 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_317;
V_64 = F_174 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_318;
V_64 = F_184 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_319;
V_64 = F_192 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_320;
V_64 = F_171 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_321;
V_64 = F_249 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_322;
V_64 = F_178 ( V_168 , V_115 ) ;
if ( V_64 )
goto V_323;
V_64 = F_250 ( V_168 , V_242 , V_243 , V_115 ) ;
if ( V_64 )
goto V_324;
if ( V_240 != & V_325 ) {
V_64 = - V_107 ;
V_240 = F_251 ( V_115 -> V_252 -> V_253 ) ;
if ( ! V_240 )
goto V_324;
}
V_115 -> V_326 = ( V_168 & V_327 ) ? V_244 : NULL ;
V_115 -> V_162 = ( V_168 & V_328 ) ? V_244 : NULL ;
#ifdef F_179
V_115 -> V_329 = NULL ;
#endif
#ifdef F_159
V_115 -> V_159 = NULL ;
#ifdef F_161
V_115 -> V_160 = NULL ;
#endif
F_70 ( & V_115 -> V_161 ) ;
V_115 -> V_330 = NULL ;
#endif
if ( ( V_168 & ( V_175 | V_331 ) ) == V_175 )
V_115 -> V_332 = V_115 -> V_333 = 0 ;
F_252 ( V_115 ) ;
F_253 ( V_115 , V_334 ) ;
#ifdef F_254
F_253 ( V_115 , F_254 ) ;
#endif
F_255 ( V_115 ) ;
V_115 -> V_240 = F_256 ( V_240 ) ;
if ( V_168 & V_208 ) {
V_115 -> V_335 = - 1 ;
V_115 -> V_224 = V_27 -> V_224 ;
V_115 -> V_336 = V_27 -> V_336 ;
} else {
if ( V_168 & V_249 )
V_115 -> V_335 = V_27 -> V_224 -> V_335 ;
else
V_115 -> V_335 = ( V_168 & V_337 ) ;
V_115 -> V_224 = V_115 ;
V_115 -> V_336 = V_115 -> V_240 ;
}
V_115 -> V_338 = 0 ;
V_115 -> V_339 = 128 >> ( V_340 - 10 ) ;
V_115 -> V_341 = 0 ;
V_115 -> V_342 = 0 ;
F_70 ( & V_115 -> V_343 ) ;
V_115 -> V_344 = NULL ;
F_257 ( & V_1 ) ;
if ( V_168 & ( V_249 | V_208 ) ) {
V_115 -> V_345 = V_27 -> V_345 ;
V_115 -> V_346 = V_27 -> V_346 ;
} else {
V_115 -> V_345 = V_27 ;
V_115 -> V_346 = V_27 -> V_347 ;
}
F_133 ( & V_27 -> V_197 -> V_230 ) ;
F_203 ( V_115 ) ;
F_258 () ;
if ( F_259 ( V_27 ) ) {
F_135 ( & V_27 -> V_197 -> V_230 ) ;
F_260 ( & V_1 ) ;
V_64 = - V_348 ;
goto V_349;
}
if ( F_151 ( V_115 -> V_240 ) ) {
F_261 ( V_115 , ( V_168 & V_350 ) || V_245 ) ;
F_213 ( V_115 , V_351 , V_240 ) ;
if ( F_262 ( V_115 ) ) {
F_213 ( V_115 , V_352 , F_263 ( V_27 ) ) ;
F_213 ( V_115 , V_353 , F_264 ( V_27 ) ) ;
if ( F_265 ( V_240 ) ) {
F_266 ( V_240 ) -> V_354 = V_115 ;
V_115 -> signal -> V_131 |= V_250 ;
}
V_115 -> signal -> V_355 = V_240 ;
V_115 -> signal -> V_356 = F_267 ( V_27 -> signal -> V_356 ) ;
F_268 ( & V_115 -> V_271 , & V_115 -> V_345 -> V_270 ) ;
F_269 ( & V_115 -> V_357 , & V_33 . V_357 ) ;
F_270 ( V_115 , V_352 ) ;
F_270 ( V_115 , V_353 ) ;
F_271 ( V_4 ) ;
} else {
V_27 -> signal -> V_209 ++ ;
F_77 ( & V_27 -> signal -> V_210 ) ;
F_77 ( & V_27 -> signal -> V_24 ) ;
F_269 ( & V_115 -> V_343 ,
& V_115 -> V_224 -> V_343 ) ;
F_269 ( & V_115 -> V_213 ,
& V_115 -> signal -> V_211 ) ;
}
F_270 ( V_115 , V_351 ) ;
V_209 ++ ;
}
V_358 ++ ;
F_135 ( & V_27 -> V_197 -> V_230 ) ;
F_272 ( V_115 ) ;
F_260 ( & V_1 ) ;
F_273 ( V_115 ) ;
F_274 ( V_115 ) ;
if ( V_168 & V_208 )
F_275 ( V_27 ) ;
F_276 ( V_115 ) ;
F_277 ( V_115 , V_168 ) ;
F_278 ( V_115 , V_168 ) ;
return V_115 ;
V_349:
if ( V_240 != & V_325 )
F_279 ( V_240 ) ;
V_324:
if ( V_115 -> V_189 )
F_280 ( V_115 ) ;
V_323:
F_281 ( V_115 ) ;
V_322:
if ( V_115 -> V_54 )
F_124 ( V_115 -> V_54 ) ;
V_321:
if ( ! ( V_168 & V_208 ) )
F_28 ( V_115 -> signal ) ;
V_320:
F_186 ( V_115 -> V_197 ) ;
V_319:
F_282 ( V_115 ) ;
V_318:
F_283 ( V_115 ) ;
V_317:
F_284 ( V_115 ) ;
V_316:
F_285 ( V_115 ) ;
V_315:
F_286 ( V_115 ) ;
V_314:
#ifdef F_234
F_92 ( V_115 -> V_291 ) ;
V_292:
#endif
if ( V_168 & V_208 )
F_275 ( V_27 ) ;
F_39 ( V_115 ) ;
F_136 ( F_223 ( V_115 ) -> V_266 -> V_145 ) ;
V_265:
F_75 ( & V_115 -> V_359 -> V_258 -> V_259 ) ;
F_38 ( V_115 ) ;
V_263:
F_24 ( V_115 ) ;
V_254:
return F_148 ( V_64 ) ;
}
static inline void F_287 ( struct V_360 * V_361 )
{
enum V_239 type ;
for ( type = V_351 ; type < V_362 ; ++ type ) {
F_288 ( & V_361 [ type ] . V_7 ) ;
V_361 [ type ] . V_240 = & V_325 ;
}
}
struct V_5 * F_289 ( int V_2 )
{
struct V_5 * V_149 ;
V_149 = F_214 ( V_175 , 0 , 0 , NULL , & V_325 , 0 ) ;
if ( ! F_236 ( V_149 ) ) {
F_287 ( V_149 -> V_241 ) ;
F_290 ( V_149 , V_2 ) ;
}
return V_149 ;
}
long F_291 ( unsigned long V_168 ,
unsigned long V_242 ,
unsigned long V_243 ,
int T_2 * V_363 ,
int T_2 * V_244 )
{
struct V_5 * V_115 ;
int V_245 = 0 ;
long V_364 ;
if ( ! ( V_168 & V_365 ) ) {
if ( V_168 & V_331 )
V_245 = V_366 ;
else if ( ( V_168 & V_337 ) != V_367 )
V_245 = V_368 ;
else
V_245 = V_369 ;
if ( F_151 ( ! F_292 ( V_27 , V_245 ) ) )
V_245 = 0 ;
}
V_115 = F_214 ( V_168 , V_242 , V_243 ,
V_244 , NULL , V_245 ) ;
if ( ! F_236 ( V_115 ) ) {
struct V_154 V_155 ;
struct V_240 * V_240 ;
F_293 ( V_27 , V_115 ) ;
V_240 = F_294 ( V_115 , V_351 ) ;
V_364 = F_295 ( V_240 ) ;
if ( V_168 & V_370 )
F_166 ( V_364 , V_363 ) ;
if ( V_168 & V_331 ) {
V_115 -> V_156 = & V_155 ;
F_296 ( & V_155 ) ;
F_297 ( V_115 ) ;
}
F_298 ( V_115 ) ;
if ( F_79 ( V_245 ) )
F_299 ( V_245 , V_240 ) ;
if ( V_168 & V_331 ) {
if ( ! F_153 ( V_115 , & V_155 ) )
F_299 ( V_371 , V_240 ) ;
}
F_300 ( V_240 ) ;
} else {
V_364 = F_237 ( V_115 ) ;
}
return V_364 ;
}
T_3 F_301 ( int (* F_302)( void * ) , void * V_372 , unsigned long V_131 )
{
return F_291 ( V_131 | V_175 | V_365 , ( unsigned long ) F_302 ,
( unsigned long ) V_372 , NULL , NULL ) ;
}
static void F_303 ( void * V_373 )
{
struct V_195 * V_197 = V_373 ;
F_103 ( & V_197 -> V_230 ) ;
F_195 ( & V_197 -> V_374 ) ;
}
void T_1 F_304 ( void )
{
V_198 = F_18 ( L_5 ,
sizeof( struct V_195 ) , 0 ,
V_375 | V_29 | V_376 |
V_30 , F_303 ) ;
V_23 = F_18 ( L_6 ,
sizeof( struct V_21 ) , 0 ,
V_375 | V_29 | V_30 , NULL ) ;
V_377 = F_18 ( L_7 ,
sizeof( struct V_184 ) , 0 ,
V_375 | V_29 | V_30 , NULL ) ;
V_378 = F_18 ( L_8 ,
sizeof( struct V_177 ) , 0 ,
V_375 | V_29 | V_30 , NULL ) ;
V_379 = F_18 ( L_9 ,
sizeof( struct V_53 ) , V_380 ,
V_375 | V_29 | V_30 , NULL ) ;
V_83 = F_305 ( V_56 , V_29 ) ;
F_306 () ;
F_307 () ;
}
static int F_308 ( unsigned long V_381 )
{
if ( V_381 & ~ ( V_208 | V_179 | V_246 | V_196 |
V_175 | V_188 | V_382 |
V_383 | V_384 | V_385 |
V_248 | V_251 ) )
return - V_247 ;
if ( V_381 & ( V_208 | V_196 | V_175 ) ) {
if ( F_35 ( & V_27 -> V_54 -> V_119 ) > 1 )
return - V_247 ;
}
return 0 ;
}
static int F_309 ( unsigned long V_381 , struct V_177 * * V_386 )
{
struct V_177 * V_178 = V_27 -> V_178 ;
if ( ! ( V_381 & V_179 ) || ! V_178 )
return 0 ;
if ( V_178 -> V_183 == 1 )
return 0 ;
* V_386 = F_175 ( V_178 ) ;
if ( ! * V_386 )
return - V_107 ;
return 0 ;
}
static int F_310 ( unsigned long V_381 , struct V_184 * * V_387 )
{
struct V_184 * V_388 = V_27 -> V_187 ;
int error = 0 ;
if ( ( V_381 & V_188 ) &&
( V_388 && F_35 ( & V_388 -> V_140 ) > 1 ) ) {
* V_387 = F_177 ( V_388 , & error ) ;
if ( ! * V_387 )
return error ;
}
return 0 ;
}
int F_311 ( struct V_184 * * V_389 )
{
struct V_5 * V_149 = V_27 ;
struct V_184 * V_390 = NULL ;
int error ;
error = F_310 ( V_188 , & V_390 ) ;
if ( error || ! V_390 ) {
* V_389 = NULL ;
return error ;
}
* V_389 = V_149 -> V_187 ;
F_144 ( V_149 ) ;
V_149 -> V_187 = V_390 ;
F_145 ( V_149 ) ;
return 0 ;
}
