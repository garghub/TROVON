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
F_76 ( V_92 ) ;
if ( V_58 -> V_77 & V_96 )
F_77 ( & V_92 -> V_97 ) ;
F_78 ( V_92 ) ;
if ( F_79 ( V_58 -> V_77 & V_98 ) )
F_80 ( V_58 ,
& V_92 -> V_99 ) ;
else
F_81 ( V_58 , V_57 ,
& V_92 -> V_100 ) ;
F_82 ( V_92 ) ;
F_83 ( V_92 ) ;
}
if ( F_84 ( V_58 ) )
F_85 ( V_58 ) ;
* V_60 = V_58 ;
V_60 = & V_58 -> V_75 ;
V_58 -> V_89 = V_59 ;
V_59 = V_58 ;
F_86 ( V_54 , V_58 , V_62 , V_63 ) ;
V_62 = & V_58 -> V_101 . V_102 ;
V_63 = & V_58 -> V_101 ;
V_54 -> V_103 ++ ;
V_64 = F_87 ( V_54 , V_55 , V_57 ) ;
if ( V_58 -> V_104 && V_58 -> V_104 -> V_105 )
V_58 -> V_104 -> V_105 ( V_58 ) ;
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
V_64 = - V_106 ;
F_94 ( V_65 ) ;
goto V_74;
}
static inline int F_95 ( struct V_53 * V_54 )
{
V_54 -> V_107 = F_96 ( V_54 ) ;
if ( F_79 ( ! V_54 -> V_107 ) )
return - V_106 ;
return 0 ;
}
static inline void F_97 ( struct V_53 * V_54 )
{
F_98 ( V_54 , V_54 -> V_107 ) ;
}
static int T_1 F_99 ( char * V_108 )
{
V_109 =
( F_100 ( V_108 , NULL , 0 ) << V_110 ) &
V_111 ;
return 1 ;
}
static void F_101 ( struct V_53 * V_54 )
{
#ifdef F_102
F_103 ( & V_54 -> V_112 ) ;
V_54 -> V_113 = NULL ;
#endif
}
static void F_104 ( struct V_53 * V_54 , struct V_5 * V_114 )
{
#ifdef F_105
V_54 -> V_115 = V_114 ;
#endif
}
static struct V_53 * F_106 ( struct V_53 * V_54 , struct V_5 * V_114 )
{
V_54 -> V_73 = NULL ;
V_54 -> V_72 = V_116 ;
V_54 -> V_117 = 0 ;
F_56 ( & V_54 -> V_118 , 1 ) ;
F_56 ( & V_54 -> V_119 , 1 ) ;
F_107 ( & V_54 -> V_66 ) ;
F_70 ( & V_54 -> V_120 ) ;
V_54 -> V_121 = NULL ;
F_108 ( & V_54 -> V_122 , 0 ) ;
V_54 -> V_103 = 0 ;
V_54 -> V_123 = 0 ;
V_54 -> V_124 = 0 ;
memset ( & V_54 -> V_125 , 0 , sizeof( V_54 -> V_125 ) ) ;
F_103 ( & V_54 -> V_126 ) ;
F_109 ( V_54 ) ;
F_101 ( V_54 ) ;
F_104 ( V_54 , V_114 ) ;
F_110 ( V_54 ) ;
F_111 ( V_54 ) ;
#if F_112 ( V_127 ) && ! V_128
V_54 -> V_129 = NULL ;
#endif
if ( V_27 -> V_54 ) {
V_54 -> V_130 = V_27 -> V_54 -> V_130 & V_131 ;
V_54 -> V_132 = V_27 -> V_54 -> V_132 & V_133 ;
} else {
V_54 -> V_130 = V_109 ;
V_54 -> V_132 = 0 ;
}
if ( F_95 ( V_54 ) )
goto V_134;
if ( F_113 ( V_114 , V_54 ) )
goto V_135;
return V_54 ;
V_135:
F_97 ( V_54 ) ;
V_134:
F_114 ( V_54 ) ;
return NULL ;
}
static void F_115 ( struct V_53 * V_54 )
{
int V_136 ;
for ( V_136 = 0 ; V_136 < V_137 ; V_136 ++ ) {
long V_138 = F_116 ( & V_54 -> V_125 . V_139 [ V_136 ] ) ;
if ( F_79 ( V_138 ) )
F_117 ( V_140 L_3
L_4 , V_54 , V_136 , V_138 ) ;
}
#if F_112 ( V_127 ) && ! V_128
F_118 ( V_54 -> V_129 , V_54 ) ;
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
F_19 ( V_54 == & V_141 ) ;
F_97 ( V_54 ) ;
F_122 ( V_54 ) ;
F_123 ( V_54 ) ;
F_115 ( V_54 ) ;
F_114 ( V_54 ) ;
}
void F_124 ( struct V_53 * V_54 )
{
F_125 () ;
if ( F_32 ( & V_54 -> V_118 ) ) {
F_126 ( V_54 ) ;
F_127 ( V_54 ) ;
F_128 ( V_54 ) ;
F_129 ( V_54 ) ;
F_130 ( V_54 ) ;
F_131 ( V_54 , NULL ) ;
if ( ! F_132 ( & V_54 -> V_120 ) ) {
F_133 ( & V_142 ) ;
F_134 ( & V_54 -> V_120 ) ;
F_135 ( & V_142 ) ;
}
if ( V_54 -> V_143 )
F_136 ( V_54 -> V_143 -> V_144 ) ;
F_137 ( V_54 ) ;
}
}
void F_131 ( struct V_53 * V_54 , struct V_76 * V_145 )
{
if ( V_145 )
F_74 ( V_145 ) ;
if ( V_54 -> V_146 )
F_138 ( V_54 -> V_146 ) ;
V_54 -> V_146 = V_145 ;
}
struct V_76 * F_139 ( struct V_53 * V_54 )
{
struct V_76 * V_146 ;
F_140 ( & V_54 -> V_66 ) ;
V_146 = V_54 -> V_146 ;
if ( V_146 )
F_74 ( V_146 ) ;
F_141 ( & V_54 -> V_66 ) ;
return V_146 ;
}
static void F_142 ( struct V_53 * V_55 , struct V_53 * V_147 )
{
V_147 -> V_146 = F_139 ( V_55 ) ;
}
struct V_53 * F_143 ( struct V_5 * V_148 )
{
struct V_53 * V_54 ;
F_144 ( V_148 ) ;
V_54 = V_148 -> V_54 ;
if ( V_54 ) {
if ( V_148 -> V_130 & V_149 )
V_54 = NULL ;
else
F_77 ( & V_54 -> V_118 ) ;
}
F_145 ( V_148 ) ;
return V_54 ;
}
struct V_53 * F_146 ( struct V_5 * V_148 , unsigned int V_150 )
{
struct V_53 * V_54 ;
int V_44 ;
V_44 = F_147 ( & V_148 -> signal -> V_151 ) ;
if ( V_44 )
return F_148 ( V_44 ) ;
V_54 = F_143 ( V_148 ) ;
if ( V_54 && V_54 != V_27 -> V_54 &&
! F_149 ( V_148 , V_150 ) ) {
F_124 ( V_54 ) ;
V_54 = F_148 ( - V_152 ) ;
}
F_150 ( & V_148 -> signal -> V_151 ) ;
return V_54 ;
}
static void F_151 ( struct V_5 * V_6 )
{
struct V_153 * V_154 ;
F_144 ( V_6 ) ;
V_154 = V_6 -> V_155 ;
if ( F_152 ( V_154 ) ) {
V_6 -> V_155 = NULL ;
F_153 ( V_154 ) ;
}
F_145 ( V_6 ) ;
}
static int F_154 ( struct V_5 * V_156 ,
struct V_153 * V_154 )
{
int V_157 ;
F_155 () ;
V_157 = F_156 ( V_154 ) ;
F_157 () ;
if ( V_157 ) {
F_144 ( V_156 ) ;
V_156 -> V_155 = NULL ;
F_145 ( V_156 ) ;
}
F_158 ( V_156 ) ;
return V_157 ;
}
void F_159 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
#ifdef F_160
if ( F_79 ( V_6 -> V_158 ) ) {
F_161 ( V_6 ) ;
V_6 -> V_158 = NULL ;
}
#ifdef F_162
if ( F_79 ( V_6 -> V_159 ) ) {
F_163 ( V_6 ) ;
V_6 -> V_159 = NULL ;
}
#endif
if ( F_79 ( ! F_132 ( & V_6 -> V_160 ) ) )
F_164 ( V_6 ) ;
#endif
F_165 ( V_6 ) ;
F_166 ( V_6 , V_54 ) ;
if ( V_6 -> V_161 ) {
if ( ! ( V_6 -> V_130 & V_162 ) &&
F_35 ( & V_54 -> V_118 ) > 1 ) {
F_167 ( 0 , V_6 -> V_161 ) ;
F_168 ( V_6 -> V_161 , V_163 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_161 = NULL ;
}
if ( V_6 -> V_155 )
F_151 ( V_6 ) ;
}
static struct V_53 * F_169 ( struct V_5 * V_6 )
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
goto V_164;
V_54 -> V_165 = F_170 ( V_54 ) ;
V_54 -> V_166 = V_54 -> V_68 ;
if ( V_54 -> V_143 && ! F_171 ( V_54 -> V_143 -> V_144 ) )
goto V_164;
return V_54 ;
V_164:
V_54 -> V_143 = NULL ;
F_124 ( V_54 ) ;
V_82:
return NULL ;
}
static int F_172 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_53 * V_54 , * V_55 ;
int V_64 ;
V_6 -> V_168 = V_6 -> V_169 = 0 ;
V_6 -> V_170 = V_6 -> V_171 = 0 ;
#ifdef F_173
V_6 -> V_172 = V_6 -> V_170 + V_6 -> V_171 ;
#endif
V_6 -> V_54 = NULL ;
V_6 -> V_173 = NULL ;
V_55 = V_27 -> V_54 ;
if ( ! V_55 )
return 0 ;
F_174 ( V_6 ) ;
if ( V_167 & V_174 ) {
F_77 ( & V_55 -> V_118 ) ;
V_54 = V_55 ;
goto V_175;
}
V_64 = - V_106 ;
V_54 = F_169 ( V_6 ) ;
if ( ! V_54 )
goto V_82;
V_175:
V_6 -> V_54 = V_54 ;
V_6 -> V_173 = V_54 ;
return 0 ;
V_82:
return V_64 ;
}
static int F_175 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_176 * V_177 = V_27 -> V_177 ;
if ( V_167 & V_178 ) {
F_133 ( & V_177 -> V_179 ) ;
if ( V_177 -> V_180 ) {
F_135 ( & V_177 -> V_179 ) ;
return - V_181 ;
}
V_177 -> V_182 ++ ;
F_135 ( & V_177 -> V_179 ) ;
return 0 ;
}
V_6 -> V_177 = F_176 ( V_177 ) ;
if ( ! V_6 -> V_177 )
return - V_106 ;
return 0 ;
}
static int F_177 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_183 * V_184 , * V_185 ;
int error = 0 ;
V_184 = V_27 -> V_186 ;
if ( ! V_184 )
goto V_74;
if ( V_167 & V_187 ) {
F_77 ( & V_184 -> V_139 ) ;
goto V_74;
}
V_185 = F_178 ( V_184 , & error ) ;
if ( ! V_185 )
goto V_74;
V_6 -> V_186 = V_185 ;
error = 0 ;
V_74:
return error ;
}
static int F_179 ( unsigned long V_167 , struct V_5 * V_6 )
{
#ifdef F_180
struct V_188 * V_189 = V_27 -> V_188 ;
struct V_188 * V_190 ;
if ( ! V_189 )
return 0 ;
if ( V_167 & V_191 ) {
F_181 ( V_189 ) ;
V_6 -> V_188 = V_189 ;
} else if ( F_182 ( V_189 -> V_192 ) ) {
V_190 = F_183 ( V_6 , V_9 , V_193 ) ;
if ( F_79 ( ! V_190 ) )
return - V_106 ;
V_190 -> V_192 = V_189 -> V_192 ;
F_184 ( V_190 ) ;
}
#endif
return 0 ;
}
static int F_185 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_194 * V_22 ;
if ( V_167 & V_195 ) {
F_77 ( & V_27 -> V_196 -> V_139 ) ;
return 0 ;
}
V_22 = F_69 ( V_197 , V_9 ) ;
F_186 ( V_6 -> V_196 , V_22 ) ;
if ( ! V_22 )
return - V_106 ;
F_56 ( & V_22 -> V_139 , 1 ) ;
memcpy ( V_22 -> V_198 , V_27 -> V_196 -> V_198 , sizeof( V_22 -> V_198 ) ) ;
return 0 ;
}
void F_187 ( struct V_194 * V_196 )
{
if ( F_32 ( & V_196 -> V_139 ) ) {
F_188 ( V_196 ) ;
F_10 ( V_197 , V_196 ) ;
}
}
static void F_189 ( struct V_21 * V_22 )
{
unsigned long V_199 ;
F_190 ( V_22 ) ;
V_199 = F_191 ( V_22 -> V_34 [ V_200 ] . V_36 ) ;
if ( V_199 != V_201 ) {
V_22 -> V_202 . V_203 = F_192 ( V_199 ) ;
V_22 -> V_204 . V_205 = 1 ;
}
F_70 ( & V_22 -> V_206 [ 0 ] ) ;
F_70 ( & V_22 -> V_206 [ 1 ] ) ;
F_70 ( & V_22 -> V_206 [ 2 ] ) ;
}
static int F_193 ( unsigned long V_167 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_167 & V_207 )
return 0 ;
V_22 = F_194 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_106 ;
V_22 -> V_208 = 1 ;
F_56 ( & V_22 -> V_209 , 1 ) ;
F_56 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_210 = (struct V_211 ) F_195 ( V_6 -> V_212 ) ;
V_6 -> V_212 = (struct V_211 ) F_195 ( V_22 -> V_210 ) ;
F_196 ( & V_22 -> V_213 ) ;
V_22 -> V_214 = V_6 ;
F_197 ( & V_22 -> V_215 ) ;
F_70 ( & V_22 -> V_216 ) ;
F_198 ( & V_22 -> V_217 ) ;
F_199 ( & V_22 -> V_218 , V_219 , V_220 ) ;
V_22 -> V_218 . V_221 = V_222 ;
F_144 ( V_27 -> V_223 ) ;
memcpy ( V_22 -> V_34 , V_27 -> signal -> V_34 , sizeof V_22 -> V_34 ) ;
F_145 ( V_27 -> V_223 ) ;
F_189 ( V_22 ) ;
F_200 ( V_22 ) ;
F_201 ( V_22 ) ;
#ifdef F_202
F_107 ( & V_22 -> V_224 ) ;
#endif
V_22 -> V_225 = V_27 -> signal -> V_225 ;
V_22 -> V_226 = V_27 -> signal -> V_226 ;
V_22 -> V_227 = V_27 -> signal -> V_227 ||
V_27 -> signal -> V_228 ;
F_203 ( & V_22 -> V_151 ) ;
return 0 ;
}
static void F_204 ( struct V_5 * V_114 )
{
#ifdef F_50
F_205 ( & V_27 -> V_196 -> V_229 ) ;
F_206 ( V_27 ) ;
V_114 -> V_47 = V_27 -> V_47 ;
if ( F_207 ( V_27 ) )
F_208 ( V_114 ) ;
if ( V_114 -> V_47 . V_150 != V_230 )
F_209 ( V_114 , V_231 ) ;
#endif
}
static void F_210 ( struct V_5 * V_114 )
{
F_211 ( & V_114 -> V_232 ) ;
#ifdef F_212
V_114 -> V_233 = V_116 ;
V_114 -> V_234 = NULL ;
V_114 -> V_235 = NULL ;
#endif
}
static void F_213 ( struct V_5 * V_6 )
{
V_6 -> V_202 . V_203 = 0 ;
V_6 -> V_202 . V_236 = 0 ;
V_6 -> V_202 . V_237 = 0 ;
F_70 ( & V_6 -> V_206 [ 0 ] ) ;
F_70 ( & V_6 -> V_206 [ 1 ] ) ;
F_70 ( & V_6 -> V_206 [ 2 ] ) ;
}
static inline void
F_214 ( struct V_5 * V_148 , enum V_238 type , struct V_239 * V_239 )
{
V_148 -> V_240 [ type ] . V_239 = V_239 ;
}
static struct V_5 * F_215 ( unsigned long V_167 ,
unsigned long V_241 ,
unsigned long V_242 ,
int T_2 * V_243 ,
struct V_239 * V_239 ,
int V_244 )
{
int V_64 ;
struct V_5 * V_114 ;
if ( ( V_167 & ( V_245 | V_178 ) ) == ( V_245 | V_178 ) )
return F_148 ( - V_246 ) ;
if ( ( V_167 & ( V_247 | V_178 ) ) == ( V_247 | V_178 ) )
return F_148 ( - V_246 ) ;
if ( ( V_167 & V_207 ) && ! ( V_167 & V_195 ) )
return F_148 ( - V_246 ) ;
if ( ( V_167 & V_195 ) && ! ( V_167 & V_174 ) )
return F_148 ( - V_246 ) ;
if ( ( V_167 & V_248 ) &&
V_27 -> signal -> V_130 & V_249 )
return F_148 ( - V_246 ) ;
if ( V_167 & V_195 ) {
if ( ( V_167 & ( V_247 | V_250 ) ) ||
( F_216 ( V_27 ) !=
V_27 -> V_251 -> V_252 ) )
return F_148 ( - V_246 ) ;
}
V_64 = F_217 ( V_167 ) ;
if ( V_64 )
goto V_253;
V_64 = - V_106 ;
V_114 = F_48 ( V_27 ) ;
if ( ! V_114 )
goto V_253;
F_218 ( V_114 ) ;
F_210 ( V_114 ) ;
#ifdef F_219
F_220 ( ! V_114 -> V_254 ) ;
F_220 ( ! V_114 -> V_255 ) ;
#endif
V_64 = - V_181 ;
if ( F_35 ( & V_114 -> V_256 -> V_257 -> V_258 ) >=
F_221 ( V_114 , V_35 ) ) {
if ( V_114 -> V_256 -> V_257 != V_259 &&
! F_222 ( V_260 ) && ! F_222 ( V_261 ) )
goto V_262;
}
V_27 -> V_130 &= ~ V_263 ;
V_64 = F_223 ( V_114 , V_167 ) ;
if ( V_64 < 0 )
goto V_262;
V_64 = - V_181 ;
if ( V_208 >= V_31 )
goto V_264;
if ( ! F_171 ( F_224 ( V_114 ) -> V_265 -> V_144 ) )
goto V_264;
F_225 ( V_114 ) ;
V_114 -> V_130 &= ~ ( V_266 | V_267 ) ;
V_114 -> V_130 |= V_268 ;
F_70 ( & V_114 -> V_269 ) ;
F_70 ( & V_114 -> V_270 ) ;
F_226 ( V_114 ) ;
V_114 -> V_155 = NULL ;
F_103 ( & V_114 -> V_271 ) ;
F_197 ( & V_114 -> V_272 ) ;
V_114 -> V_273 = V_114 -> V_274 = V_114 -> V_275 = 0 ;
V_114 -> V_276 = V_114 -> V_277 = 0 ;
#ifndef F_227
V_114 -> V_278 . V_273 = V_114 -> V_278 . V_274 = 0 ;
#endif
#ifdef F_228
F_198 ( & V_114 -> V_279 ) ;
V_114 -> V_280 = 0 ;
V_114 -> V_281 = V_282 ;
#endif
#if F_112 ( V_283 )
memset ( & V_114 -> V_125 , 0 , sizeof( V_114 -> V_125 ) ) ;
#endif
V_114 -> V_284 = V_27 -> V_285 ;
F_229 ( & V_114 -> V_286 ) ;
F_230 ( V_114 ) ;
F_213 ( V_114 ) ;
V_114 -> V_287 = F_231 () ;
V_114 -> V_288 = F_232 () ;
V_114 -> V_188 = NULL ;
V_114 -> V_289 = NULL ;
if ( V_167 & V_207 )
F_233 ( V_27 ) ;
F_234 ( V_114 ) ;
#ifdef F_235
V_114 -> V_290 = F_236 ( V_114 -> V_290 ) ;
if ( F_237 ( V_114 -> V_290 ) ) {
V_64 = F_238 ( V_114 -> V_290 ) ;
V_114 -> V_290 = NULL ;
goto V_291;
}
#endif
#ifdef F_239
V_114 -> V_292 = V_193 ;
V_114 -> V_293 = V_193 ;
F_240 ( & V_114 -> V_294 ) ;
#endif
#ifdef F_241
V_114 -> V_295 = 0 ;
V_114 -> V_254 = 0 ;
V_114 -> V_296 = 0 ;
V_114 -> V_297 = 0 ;
V_114 -> V_298 = V_299 ;
V_114 -> V_300 = 0 ;
V_114 -> V_255 = 1 ;
V_114 -> V_301 = V_299 ;
V_114 -> V_302 = 0 ;
V_114 -> V_303 = 0 ;
V_114 -> V_304 = 0 ;
V_114 -> V_305 = 0 ;
V_114 -> V_306 = 0 ;
#endif
#ifdef F_242
V_114 -> V_307 = 0 ;
V_114 -> V_308 = 0 ;
V_114 -> V_309 = 0 ;
#endif
#ifdef F_243
V_114 -> V_310 = NULL ;
#endif
#ifdef F_244
V_114 -> V_311 = 0 ;
V_114 -> V_312 = 0 ;
#endif
V_64 = F_245 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_313;
V_64 = F_246 ( V_114 ) ;
if ( V_64 )
goto V_313;
V_64 = F_247 ( V_114 ) ;
if ( V_64 )
goto V_314;
F_248 ( V_114 ) ;
V_64 = F_249 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_315;
V_64 = F_177 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_316;
V_64 = F_175 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_317;
V_64 = F_185 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_318;
V_64 = F_193 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_319;
V_64 = F_172 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_320;
V_64 = F_250 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_321;
V_64 = F_179 ( V_167 , V_114 ) ;
if ( V_64 )
goto V_322;
V_64 = F_251 ( V_167 , V_241 , V_242 , V_114 ) ;
if ( V_64 )
goto V_323;
if ( V_239 != & V_324 ) {
V_64 = - V_106 ;
V_239 = F_252 ( V_114 -> V_251 -> V_252 ) ;
if ( ! V_239 )
goto V_323;
}
V_114 -> V_325 = ( V_167 & V_326 ) ? V_243 : NULL ;
V_114 -> V_161 = ( V_167 & V_327 ) ? V_243 : NULL ;
#ifdef F_180
V_114 -> V_328 = NULL ;
#endif
#ifdef F_160
V_114 -> V_158 = NULL ;
#ifdef F_162
V_114 -> V_159 = NULL ;
#endif
F_70 ( & V_114 -> V_160 ) ;
V_114 -> V_329 = NULL ;
#endif
if ( ( V_167 & ( V_174 | V_330 ) ) == V_174 )
V_114 -> V_331 = V_114 -> V_332 = 0 ;
F_253 ( V_114 ) ;
F_254 ( V_114 , V_333 ) ;
#ifdef F_255
F_254 ( V_114 , F_255 ) ;
#endif
F_256 ( V_114 ) ;
V_114 -> V_239 = F_257 ( V_239 ) ;
if ( V_167 & V_207 ) {
V_114 -> V_334 = - 1 ;
V_114 -> V_223 = V_27 -> V_223 ;
V_114 -> V_335 = V_27 -> V_335 ;
} else {
if ( V_167 & V_248 )
V_114 -> V_334 = V_27 -> V_223 -> V_334 ;
else
V_114 -> V_334 = ( V_167 & V_336 ) ;
V_114 -> V_223 = V_114 ;
V_114 -> V_335 = V_114 -> V_239 ;
}
V_114 -> V_337 = 0 ;
V_114 -> V_338 = 128 >> ( V_339 - 10 ) ;
V_114 -> V_340 = 0 ;
V_114 -> V_341 = 0 ;
F_70 ( & V_114 -> V_342 ) ;
V_114 -> V_343 = NULL ;
F_258 ( & V_1 ) ;
if ( V_167 & ( V_248 | V_207 ) ) {
V_114 -> V_344 = V_27 -> V_344 ;
V_114 -> V_345 = V_27 -> V_345 ;
} else {
V_114 -> V_344 = V_27 ;
V_114 -> V_345 = V_27 -> V_346 ;
}
F_133 ( & V_27 -> V_196 -> V_229 ) ;
F_204 ( V_114 ) ;
F_259 () ;
if ( F_260 ( V_27 ) ) {
F_135 ( & V_27 -> V_196 -> V_229 ) ;
F_261 ( & V_1 ) ;
V_64 = - V_347 ;
goto V_348;
}
if ( F_152 ( V_114 -> V_239 ) ) {
F_262 ( V_114 , ( V_167 & V_349 ) || V_244 ) ;
F_214 ( V_114 , V_350 , V_239 ) ;
if ( F_263 ( V_114 ) ) {
F_214 ( V_114 , V_351 , F_264 ( V_27 ) ) ;
F_214 ( V_114 , V_352 , F_265 ( V_27 ) ) ;
if ( F_266 ( V_239 ) ) {
F_267 ( V_239 ) -> V_353 = V_114 ;
V_114 -> signal -> V_130 |= V_249 ;
}
V_114 -> signal -> V_354 = V_239 ;
V_114 -> signal -> V_355 = F_268 ( V_27 -> signal -> V_355 ) ;
F_269 ( & V_114 -> V_270 , & V_114 -> V_344 -> V_269 ) ;
F_270 ( & V_114 -> V_356 , & V_33 . V_356 ) ;
F_271 ( V_114 , V_351 ) ;
F_271 ( V_114 , V_352 ) ;
F_272 ( V_4 ) ;
} else {
V_27 -> signal -> V_208 ++ ;
F_77 ( & V_27 -> signal -> V_209 ) ;
F_77 ( & V_27 -> signal -> V_24 ) ;
F_270 ( & V_114 -> V_342 ,
& V_114 -> V_223 -> V_342 ) ;
F_270 ( & V_114 -> V_212 ,
& V_114 -> signal -> V_210 ) ;
}
F_271 ( V_114 , V_350 ) ;
V_208 ++ ;
}
V_357 ++ ;
F_135 ( & V_27 -> V_196 -> V_229 ) ;
F_273 ( V_114 ) ;
F_261 ( & V_1 ) ;
F_274 ( V_114 ) ;
F_275 ( V_114 ) ;
if ( V_167 & V_207 )
F_276 ( V_27 ) ;
F_277 ( V_114 ) ;
F_278 ( V_114 , V_167 ) ;
F_279 ( V_114 , V_167 ) ;
return V_114 ;
V_348:
if ( V_239 != & V_324 )
F_280 ( V_239 ) ;
V_323:
if ( V_114 -> V_188 )
F_281 ( V_114 ) ;
V_322:
F_282 ( V_114 ) ;
V_321:
if ( V_114 -> V_54 )
F_124 ( V_114 -> V_54 ) ;
V_320:
if ( ! ( V_167 & V_207 ) )
F_28 ( V_114 -> signal ) ;
V_319:
F_187 ( V_114 -> V_196 ) ;
V_318:
F_283 ( V_114 ) ;
V_317:
F_284 ( V_114 ) ;
V_316:
F_285 ( V_114 ) ;
V_315:
F_286 ( V_114 ) ;
V_314:
F_287 ( V_114 ) ;
V_313:
#ifdef F_235
F_92 ( V_114 -> V_290 ) ;
V_291:
#endif
if ( V_167 & V_207 )
F_276 ( V_27 ) ;
F_39 ( V_114 ) ;
F_136 ( F_224 ( V_114 ) -> V_265 -> V_144 ) ;
V_264:
F_75 ( & V_114 -> V_358 -> V_257 -> V_258 ) ;
F_38 ( V_114 ) ;
V_262:
F_24 ( V_114 ) ;
V_253:
return F_148 ( V_64 ) ;
}
static inline void F_288 ( struct V_359 * V_360 )
{
enum V_238 type ;
for ( type = V_350 ; type < V_361 ; ++ type ) {
F_289 ( & V_360 [ type ] . V_7 ) ;
V_360 [ type ] . V_239 = & V_324 ;
}
}
struct V_5 * F_290 ( int V_2 )
{
struct V_5 * V_148 ;
V_148 = F_215 ( V_174 , 0 , 0 , NULL , & V_324 , 0 ) ;
if ( ! F_237 ( V_148 ) ) {
F_288 ( V_148 -> V_240 ) ;
F_291 ( V_148 , V_2 ) ;
}
return V_148 ;
}
long F_292 ( unsigned long V_167 ,
unsigned long V_241 ,
unsigned long V_242 ,
int T_2 * V_362 ,
int T_2 * V_243 )
{
struct V_5 * V_114 ;
int V_244 = 0 ;
long V_363 ;
if ( ! ( V_167 & V_364 ) ) {
if ( V_167 & V_330 )
V_244 = V_365 ;
else if ( ( V_167 & V_336 ) != V_366 )
V_244 = V_367 ;
else
V_244 = V_368 ;
if ( F_152 ( ! F_293 ( V_27 , V_244 ) ) )
V_244 = 0 ;
}
V_114 = F_215 ( V_167 , V_241 , V_242 ,
V_243 , NULL , V_244 ) ;
if ( ! F_237 ( V_114 ) ) {
struct V_153 V_154 ;
struct V_239 * V_239 ;
F_294 ( V_27 , V_114 ) ;
V_239 = F_295 ( V_114 , V_350 ) ;
V_363 = F_296 ( V_239 ) ;
if ( V_167 & V_369 )
F_167 ( V_363 , V_362 ) ;
if ( V_167 & V_330 ) {
V_114 -> V_155 = & V_154 ;
F_297 ( & V_154 ) ;
F_298 ( V_114 ) ;
}
F_299 ( V_114 ) ;
if ( F_79 ( V_244 ) )
F_300 ( V_244 , V_239 ) ;
if ( V_167 & V_330 ) {
if ( ! F_154 ( V_114 , & V_154 ) )
F_300 ( V_370 , V_239 ) ;
}
F_301 ( V_239 ) ;
} else {
V_363 = F_238 ( V_114 ) ;
}
return V_363 ;
}
T_3 F_302 ( int (* F_303)( void * ) , void * V_371 , unsigned long V_130 )
{
return F_292 ( V_130 | V_174 | V_364 , ( unsigned long ) F_303 ,
( unsigned long ) V_371 , NULL , NULL ) ;
}
static void F_304 ( void * V_372 )
{
struct V_194 * V_196 = V_372 ;
F_103 ( & V_196 -> V_229 ) ;
F_196 ( & V_196 -> V_373 ) ;
}
void T_1 F_305 ( void )
{
V_197 = F_18 ( L_5 ,
sizeof( struct V_194 ) , 0 ,
V_374 | V_29 | V_375 |
V_30 , F_304 ) ;
V_23 = F_18 ( L_6 ,
sizeof( struct V_21 ) , 0 ,
V_374 | V_29 | V_30 , NULL ) ;
V_376 = F_18 ( L_7 ,
sizeof( struct V_183 ) , 0 ,
V_374 | V_29 | V_30 , NULL ) ;
V_377 = F_18 ( L_8 ,
sizeof( struct V_176 ) , 0 ,
V_374 | V_29 | V_30 , NULL ) ;
V_378 = F_18 ( L_9 ,
sizeof( struct V_53 ) , V_379 ,
V_374 | V_29 | V_30 , NULL ) ;
V_83 = F_306 ( V_56 , V_29 ) ;
F_307 () ;
F_308 () ;
}
static int F_309 ( unsigned long V_380 )
{
if ( V_380 & ~ ( V_207 | V_178 | V_245 | V_195 |
V_174 | V_187 | V_381 |
V_382 | V_383 | V_384 |
V_247 | V_250 ) )
return - V_246 ;
if ( V_380 & ( V_207 | V_195 | V_174 ) ) {
if ( F_35 ( & V_27 -> V_54 -> V_118 ) > 1 )
return - V_246 ;
}
return 0 ;
}
static int F_310 ( unsigned long V_380 , struct V_176 * * V_385 )
{
struct V_176 * V_177 = V_27 -> V_177 ;
if ( ! ( V_380 & V_178 ) || ! V_177 )
return 0 ;
if ( V_177 -> V_182 == 1 )
return 0 ;
* V_385 = F_176 ( V_177 ) ;
if ( ! * V_385 )
return - V_106 ;
return 0 ;
}
static int F_311 ( unsigned long V_380 , struct V_183 * * V_386 )
{
struct V_183 * V_387 = V_27 -> V_186 ;
int error = 0 ;
if ( ( V_380 & V_187 ) &&
( V_387 && F_35 ( & V_387 -> V_139 ) > 1 ) ) {
* V_386 = F_178 ( V_387 , & error ) ;
if ( ! * V_386 )
return error ;
}
return 0 ;
}
int F_312 ( struct V_183 * * V_388 )
{
struct V_5 * V_148 = V_27 ;
struct V_183 * V_389 = NULL ;
int error ;
error = F_311 ( V_187 , & V_389 ) ;
if ( error || ! V_389 ) {
* V_388 = NULL ;
return error ;
}
* V_388 = V_148 -> V_186 ;
F_144 ( V_148 ) ;
V_148 -> V_186 = V_389 ;
F_145 ( V_148 ) ;
return 0 ;
}
