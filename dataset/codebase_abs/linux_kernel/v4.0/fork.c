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
F_79 ( V_58 , V_57 ,
& V_92 -> V_98 ) ;
F_80 ( V_92 ) ;
F_81 ( V_92 ) ;
}
if ( F_82 ( V_58 ) )
F_83 ( V_58 ) ;
* V_60 = V_58 ;
V_60 = & V_58 -> V_75 ;
V_58 -> V_89 = V_59 ;
V_59 = V_58 ;
F_84 ( V_54 , V_58 , V_62 , V_63 ) ;
V_62 = & V_58 -> V_99 . V_100 ;
V_63 = & V_58 -> V_99 ;
V_54 -> V_101 ++ ;
V_64 = F_85 ( V_54 , V_55 , V_57 ) ;
if ( V_58 -> V_102 && V_58 -> V_102 -> V_103 )
V_58 -> V_102 -> V_103 ( V_58 ) ;
if ( V_64 )
goto V_74;
}
F_86 ( V_55 , V_54 ) ;
V_64 = 0 ;
V_74:
F_87 ( & V_54 -> V_66 ) ;
F_88 ( V_55 ) ;
F_87 ( & V_55 -> V_66 ) ;
F_89 () ;
return V_64 ;
V_87:
F_90 ( F_91 ( V_58 ) ) ;
V_85:
F_10 ( V_83 , V_58 ) ;
V_82:
V_64 = - V_104 ;
F_92 ( V_65 ) ;
goto V_74;
}
static inline int F_93 ( struct V_53 * V_54 )
{
V_54 -> V_105 = F_94 ( V_54 ) ;
if ( F_95 ( ! V_54 -> V_105 ) )
return - V_104 ;
return 0 ;
}
static inline void F_96 ( struct V_53 * V_54 )
{
F_97 ( V_54 , V_54 -> V_105 ) ;
}
static int T_1 F_98 ( char * V_106 )
{
V_107 =
( F_99 ( V_106 , NULL , 0 ) << V_108 ) &
V_109 ;
return 1 ;
}
static void F_100 ( struct V_53 * V_54 )
{
#ifdef F_101
F_102 ( & V_54 -> V_110 ) ;
V_54 -> V_111 = NULL ;
#endif
}
static void F_103 ( struct V_53 * V_54 , struct V_5 * V_112 )
{
#ifdef F_104
V_54 -> V_113 = V_112 ;
#endif
}
static struct V_53 * F_105 ( struct V_53 * V_54 , struct V_5 * V_112 )
{
V_54 -> V_73 = NULL ;
V_54 -> V_72 = V_114 ;
V_54 -> V_115 = 0 ;
F_56 ( & V_54 -> V_116 , 1 ) ;
F_56 ( & V_54 -> V_117 , 1 ) ;
F_106 ( & V_54 -> V_66 ) ;
F_70 ( & V_54 -> V_118 ) ;
V_54 -> V_119 = NULL ;
F_107 ( & V_54 -> V_120 , 0 ) ;
F_108 ( V_54 ) ;
V_54 -> V_101 = 0 ;
V_54 -> V_121 = 0 ;
V_54 -> V_122 = 0 ;
memset ( & V_54 -> V_123 , 0 , sizeof( V_54 -> V_123 ) ) ;
F_102 ( & V_54 -> V_124 ) ;
F_109 ( V_54 ) ;
F_100 ( V_54 ) ;
F_103 ( V_54 , V_112 ) ;
F_110 ( V_54 ) ;
F_111 ( V_54 ) ;
#if F_112 ( V_125 ) && ! V_126
V_54 -> V_127 = NULL ;
#endif
if ( V_27 -> V_54 ) {
V_54 -> V_128 = V_27 -> V_54 -> V_128 & V_129 ;
V_54 -> V_130 = V_27 -> V_54 -> V_130 & V_131 ;
} else {
V_54 -> V_128 = V_107 ;
V_54 -> V_130 = 0 ;
}
if ( F_93 ( V_54 ) )
goto V_132;
if ( F_113 ( V_112 , V_54 ) )
goto V_133;
return V_54 ;
V_133:
F_96 ( V_54 ) ;
V_132:
F_114 ( V_54 ) ;
return NULL ;
}
static void F_115 ( struct V_53 * V_54 )
{
int V_134 ;
for ( V_134 = 0 ; V_134 < V_135 ; V_134 ++ ) {
long V_136 = F_116 ( & V_54 -> V_123 . V_137 [ V_134 ] ) ;
if ( F_95 ( V_136 ) )
F_117 ( V_138 L_3
L_4 , V_54 , V_134 , V_136 ) ;
}
if ( F_116 ( & V_54 -> V_120 ) )
F_118 ( L_5 ,
F_116 ( & V_54 -> V_120 ) ) ;
if ( F_119 ( V_54 ) )
F_118 ( L_6 ,
F_119 ( V_54 ) ) ;
#if F_112 ( V_125 ) && ! V_126
F_120 ( V_54 -> V_127 , V_54 ) ;
#endif
}
struct V_53 * F_121 ( void )
{
struct V_53 * V_54 ;
V_54 = F_122 () ;
if ( ! V_54 )
return NULL ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
return F_105 ( V_54 , V_27 ) ;
}
void F_123 ( struct V_53 * V_54 )
{
F_19 ( V_54 == & V_139 ) ;
F_96 ( V_54 ) ;
F_124 ( V_54 ) ;
F_125 ( V_54 ) ;
F_115 ( V_54 ) ;
F_114 ( V_54 ) ;
}
void F_126 ( struct V_53 * V_54 )
{
F_127 () ;
if ( F_32 ( & V_54 -> V_116 ) ) {
F_128 ( V_54 ) ;
F_129 ( V_54 ) ;
F_130 ( V_54 ) ;
F_131 ( V_54 ) ;
F_132 ( V_54 ) ;
F_133 ( V_54 , NULL ) ;
if ( ! F_134 ( & V_54 -> V_118 ) ) {
F_135 ( & V_140 ) ;
F_136 ( & V_54 -> V_118 ) ;
F_137 ( & V_140 ) ;
}
if ( V_54 -> V_141 )
F_138 ( V_54 -> V_141 -> V_142 ) ;
F_139 ( V_54 ) ;
}
}
void F_133 ( struct V_53 * V_54 , struct V_76 * V_143 )
{
if ( V_143 )
F_74 ( V_143 ) ;
if ( V_54 -> V_144 )
F_140 ( V_54 -> V_144 ) ;
V_54 -> V_144 = V_143 ;
}
struct V_76 * F_141 ( struct V_53 * V_54 )
{
struct V_76 * V_144 ;
F_142 ( & V_54 -> V_66 ) ;
V_144 = V_54 -> V_144 ;
if ( V_144 )
F_74 ( V_144 ) ;
F_143 ( & V_54 -> V_66 ) ;
return V_144 ;
}
static void F_144 ( struct V_53 * V_55 , struct V_53 * V_145 )
{
V_145 -> V_144 = F_141 ( V_55 ) ;
}
struct V_53 * F_145 ( struct V_5 * V_146 )
{
struct V_53 * V_54 ;
F_146 ( V_146 ) ;
V_54 = V_146 -> V_54 ;
if ( V_54 ) {
if ( V_146 -> V_128 & V_147 )
V_54 = NULL ;
else
F_77 ( & V_54 -> V_116 ) ;
}
F_147 ( V_146 ) ;
return V_54 ;
}
struct V_53 * F_148 ( struct V_5 * V_146 , unsigned int V_148 )
{
struct V_53 * V_54 ;
int V_44 ;
V_44 = F_149 ( & V_146 -> signal -> V_149 ) ;
if ( V_44 )
return F_150 ( V_44 ) ;
V_54 = F_145 ( V_146 ) ;
if ( V_54 && V_54 != V_27 -> V_54 &&
! F_151 ( V_146 , V_148 ) ) {
F_126 ( V_54 ) ;
V_54 = F_150 ( - V_150 ) ;
}
F_152 ( & V_146 -> signal -> V_149 ) ;
return V_54 ;
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_151 * V_152 ;
F_146 ( V_6 ) ;
V_152 = V_6 -> V_153 ;
if ( F_154 ( V_152 ) ) {
V_6 -> V_153 = NULL ;
F_155 ( V_152 ) ;
}
F_147 ( V_6 ) ;
}
static int F_156 ( struct V_5 * V_154 ,
struct V_151 * V_152 )
{
int V_155 ;
F_157 () ;
V_155 = F_158 ( V_152 ) ;
F_159 () ;
if ( V_155 ) {
F_146 ( V_154 ) ;
V_154 -> V_153 = NULL ;
F_147 ( V_154 ) ;
}
F_160 ( V_154 ) ;
return V_155 ;
}
void F_161 ( struct V_5 * V_6 , struct V_53 * V_54 )
{
#ifdef F_162
if ( F_95 ( V_6 -> V_156 ) ) {
F_163 ( V_6 ) ;
V_6 -> V_156 = NULL ;
}
#ifdef F_164
if ( F_95 ( V_6 -> V_157 ) ) {
F_165 ( V_6 ) ;
V_6 -> V_157 = NULL ;
}
#endif
if ( F_95 ( ! F_134 ( & V_6 -> V_158 ) ) )
F_166 ( V_6 ) ;
#endif
F_167 ( V_6 ) ;
F_168 ( V_6 , V_54 ) ;
if ( V_6 -> V_159 ) {
if ( ! ( V_6 -> V_128 & V_160 ) &&
F_35 ( & V_54 -> V_116 ) > 1 ) {
F_169 ( 0 , V_6 -> V_159 ) ;
F_170 ( V_6 -> V_159 , V_161 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_159 = NULL ;
}
if ( V_6 -> V_153 )
F_153 ( V_6 ) ;
}
static struct V_53 * F_171 ( struct V_5 * V_6 )
{
struct V_53 * V_54 , * V_55 = V_27 -> V_54 ;
int V_44 ;
V_54 = F_122 () ;
if ( ! V_54 )
goto V_82;
memcpy ( V_54 , V_55 , sizeof( * V_54 ) ) ;
if ( ! F_105 ( V_54 , V_6 ) )
goto V_82;
F_144 ( V_55 , V_54 ) ;
V_44 = F_58 ( V_54 , V_55 ) ;
if ( V_44 )
goto V_162;
V_54 -> V_163 = F_172 ( V_54 ) ;
V_54 -> V_164 = V_54 -> V_68 ;
if ( V_54 -> V_141 && ! F_173 ( V_54 -> V_141 -> V_142 ) )
goto V_162;
return V_54 ;
V_162:
V_54 -> V_141 = NULL ;
F_126 ( V_54 ) ;
V_82:
return NULL ;
}
static int F_174 ( unsigned long V_165 , struct V_5 * V_6 )
{
struct V_53 * V_54 , * V_55 ;
int V_64 ;
V_6 -> V_166 = V_6 -> V_167 = 0 ;
V_6 -> V_168 = V_6 -> V_169 = 0 ;
#ifdef F_175
V_6 -> V_170 = V_6 -> V_168 + V_6 -> V_169 ;
#endif
V_6 -> V_54 = NULL ;
V_6 -> V_171 = NULL ;
V_55 = V_27 -> V_54 ;
if ( ! V_55 )
return 0 ;
F_176 ( V_6 ) ;
if ( V_165 & V_172 ) {
F_77 ( & V_55 -> V_116 ) ;
V_54 = V_55 ;
goto V_173;
}
V_64 = - V_104 ;
V_54 = F_171 ( V_6 ) ;
if ( ! V_54 )
goto V_82;
V_173:
V_6 -> V_54 = V_54 ;
V_6 -> V_171 = V_54 ;
return 0 ;
V_82:
return V_64 ;
}
static int F_177 ( unsigned long V_165 , struct V_5 * V_6 )
{
struct V_174 * V_175 = V_27 -> V_175 ;
if ( V_165 & V_176 ) {
F_135 ( & V_175 -> V_177 ) ;
if ( V_175 -> V_178 ) {
F_137 ( & V_175 -> V_177 ) ;
return - V_179 ;
}
V_175 -> V_180 ++ ;
F_137 ( & V_175 -> V_177 ) ;
return 0 ;
}
V_6 -> V_175 = F_178 ( V_175 ) ;
if ( ! V_6 -> V_175 )
return - V_104 ;
return 0 ;
}
static int F_179 ( unsigned long V_165 , struct V_5 * V_6 )
{
struct V_181 * V_182 , * V_183 ;
int error = 0 ;
V_182 = V_27 -> V_184 ;
if ( ! V_182 )
goto V_74;
if ( V_165 & V_185 ) {
F_77 ( & V_182 -> V_137 ) ;
goto V_74;
}
V_183 = F_180 ( V_182 , & error ) ;
if ( ! V_183 )
goto V_74;
V_6 -> V_184 = V_183 ;
error = 0 ;
V_74:
return error ;
}
static int F_181 ( unsigned long V_165 , struct V_5 * V_6 )
{
#ifdef F_182
struct V_186 * V_187 = V_27 -> V_186 ;
struct V_186 * V_188 ;
if ( ! V_187 )
return 0 ;
if ( V_165 & V_189 ) {
F_183 ( V_187 ) ;
V_6 -> V_186 = V_187 ;
} else if ( F_184 ( V_187 -> V_190 ) ) {
V_188 = F_185 ( V_6 , V_9 , V_191 ) ;
if ( F_95 ( ! V_188 ) )
return - V_104 ;
V_188 -> V_190 = V_187 -> V_190 ;
F_186 ( V_188 ) ;
}
#endif
return 0 ;
}
static int F_187 ( unsigned long V_165 , struct V_5 * V_6 )
{
struct V_192 * V_22 ;
if ( V_165 & V_193 ) {
F_77 ( & V_27 -> V_194 -> V_137 ) ;
return 0 ;
}
V_22 = F_69 ( V_195 , V_9 ) ;
F_188 ( V_6 -> V_194 , V_22 ) ;
if ( ! V_22 )
return - V_104 ;
F_56 ( & V_22 -> V_137 , 1 ) ;
memcpy ( V_22 -> V_196 , V_27 -> V_194 -> V_196 , sizeof( V_22 -> V_196 ) ) ;
return 0 ;
}
void F_189 ( struct V_192 * V_194 )
{
if ( F_32 ( & V_194 -> V_137 ) ) {
F_190 ( V_194 ) ;
F_10 ( V_195 , V_194 ) ;
}
}
static void F_191 ( struct V_21 * V_22 )
{
unsigned long V_197 ;
F_192 ( V_22 ) ;
V_197 = F_193 ( V_22 -> V_34 [ V_198 ] . V_36 ) ;
if ( V_197 != V_199 ) {
V_22 -> V_200 . V_201 = F_194 ( V_197 ) ;
V_22 -> V_202 . V_203 = 1 ;
}
F_70 ( & V_22 -> V_204 [ 0 ] ) ;
F_70 ( & V_22 -> V_204 [ 1 ] ) ;
F_70 ( & V_22 -> V_204 [ 2 ] ) ;
}
static int F_195 ( unsigned long V_165 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_165 & V_205 )
return 0 ;
V_22 = F_196 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_104 ;
V_22 -> V_206 = 1 ;
F_56 ( & V_22 -> V_207 , 1 ) ;
F_56 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_208 = (struct V_209 ) F_197 ( V_6 -> V_210 ) ;
V_6 -> V_210 = (struct V_209 ) F_197 ( V_22 -> V_208 ) ;
F_198 ( & V_22 -> V_211 ) ;
V_22 -> V_212 = V_6 ;
F_199 ( & V_22 -> V_213 ) ;
F_70 ( & V_22 -> V_214 ) ;
F_200 ( & V_22 -> V_215 ) ;
F_201 ( & V_22 -> V_216 , V_217 , V_218 ) ;
V_22 -> V_216 . V_219 = V_220 ;
F_146 ( V_27 -> V_221 ) ;
memcpy ( V_22 -> V_34 , V_27 -> signal -> V_34 , sizeof V_22 -> V_34 ) ;
F_147 ( V_27 -> V_221 ) ;
F_191 ( V_22 ) ;
F_202 ( V_22 ) ;
F_203 ( V_22 ) ;
#ifdef F_204
F_106 ( & V_22 -> V_222 ) ;
#endif
V_22 -> V_223 = V_27 -> signal -> V_223 ;
V_22 -> V_224 = V_27 -> signal -> V_224 ;
V_22 -> V_225 = V_27 -> signal -> V_225 ||
V_27 -> signal -> V_226 ;
F_205 ( & V_22 -> V_149 ) ;
return 0 ;
}
static void F_206 ( struct V_5 * V_112 )
{
#ifdef F_50
F_207 ( & V_27 -> V_194 -> V_227 ) ;
F_208 ( V_27 ) ;
V_112 -> V_47 = V_27 -> V_47 ;
if ( F_209 ( V_27 ) )
F_210 ( V_112 ) ;
if ( V_112 -> V_47 . V_148 != V_228 )
F_211 ( V_112 , V_229 ) ;
#endif
}
static void F_212 ( struct V_5 * V_112 )
{
F_213 ( & V_112 -> V_230 ) ;
#ifdef F_214
V_112 -> V_231 = V_114 ;
V_112 -> V_232 = NULL ;
V_112 -> V_233 = NULL ;
#endif
}
static void F_215 ( struct V_5 * V_6 )
{
V_6 -> V_200 . V_201 = 0 ;
V_6 -> V_200 . V_234 = 0 ;
V_6 -> V_200 . V_235 = 0 ;
F_70 ( & V_6 -> V_204 [ 0 ] ) ;
F_70 ( & V_6 -> V_204 [ 1 ] ) ;
F_70 ( & V_6 -> V_204 [ 2 ] ) ;
}
static inline void
F_216 ( struct V_5 * V_146 , enum V_236 type , struct V_237 * V_237 )
{
V_146 -> V_238 [ type ] . V_237 = V_237 ;
}
static struct V_5 * F_217 ( unsigned long V_165 ,
unsigned long V_239 ,
unsigned long V_240 ,
int T_2 * V_241 ,
struct V_237 * V_237 ,
int V_242 )
{
int V_64 ;
struct V_5 * V_112 ;
if ( ( V_165 & ( V_243 | V_176 ) ) == ( V_243 | V_176 ) )
return F_150 ( - V_244 ) ;
if ( ( V_165 & ( V_245 | V_176 ) ) == ( V_245 | V_176 ) )
return F_150 ( - V_244 ) ;
if ( ( V_165 & V_205 ) && ! ( V_165 & V_193 ) )
return F_150 ( - V_244 ) ;
if ( ( V_165 & V_193 ) && ! ( V_165 & V_172 ) )
return F_150 ( - V_244 ) ;
if ( ( V_165 & V_246 ) &&
V_27 -> signal -> V_128 & V_247 )
return F_150 ( - V_244 ) ;
if ( V_165 & V_193 ) {
if ( ( V_165 & ( V_245 | V_248 ) ) ||
( F_218 ( V_27 ) !=
V_27 -> V_249 -> V_250 ) )
return F_150 ( - V_244 ) ;
}
V_64 = F_219 ( V_165 ) ;
if ( V_64 )
goto V_251;
V_64 = - V_104 ;
V_112 = F_48 ( V_27 ) ;
if ( ! V_112 )
goto V_251;
F_220 ( V_112 ) ;
F_212 ( V_112 ) ;
#ifdef F_221
F_222 ( ! V_112 -> V_252 ) ;
F_222 ( ! V_112 -> V_253 ) ;
#endif
V_64 = - V_179 ;
if ( F_35 ( & V_112 -> V_254 -> V_255 -> V_256 ) >=
F_223 ( V_112 , V_35 ) ) {
if ( V_112 -> V_254 -> V_255 != V_257 &&
! F_224 ( V_258 ) && ! F_224 ( V_259 ) )
goto V_260;
}
V_27 -> V_128 &= ~ V_261 ;
V_64 = F_225 ( V_112 , V_165 ) ;
if ( V_64 < 0 )
goto V_260;
V_64 = - V_179 ;
if ( V_206 >= V_31 )
goto V_262;
if ( ! F_173 ( F_226 ( V_112 ) -> V_263 -> V_142 ) )
goto V_262;
F_227 ( V_112 ) ;
V_112 -> V_128 &= ~ ( V_264 | V_265 ) ;
V_112 -> V_128 |= V_266 ;
F_70 ( & V_112 -> V_267 ) ;
F_70 ( & V_112 -> V_268 ) ;
F_228 ( V_112 ) ;
V_112 -> V_153 = NULL ;
F_102 ( & V_112 -> V_269 ) ;
F_199 ( & V_112 -> V_270 ) ;
V_112 -> V_271 = V_112 -> V_272 = V_112 -> V_273 = 0 ;
V_112 -> V_274 = V_112 -> V_275 = 0 ;
#ifndef F_229
V_112 -> V_276 . V_271 = V_112 -> V_276 . V_272 = 0 ;
#endif
#ifdef F_230
F_200 ( & V_112 -> V_277 ) ;
V_112 -> V_278 = 0 ;
V_112 -> V_279 = V_280 ;
#endif
#if F_112 ( V_281 )
memset ( & V_112 -> V_123 , 0 , sizeof( V_112 -> V_123 ) ) ;
#endif
V_112 -> V_282 = V_27 -> V_283 ;
F_231 ( & V_112 -> V_284 ) ;
F_232 ( V_112 ) ;
F_215 ( V_112 ) ;
V_112 -> V_285 = F_233 () ;
V_112 -> V_286 = F_234 () ;
V_112 -> V_186 = NULL ;
V_112 -> V_287 = NULL ;
if ( V_165 & V_205 )
F_235 ( V_27 ) ;
F_236 ( V_112 ) ;
#ifdef F_237
V_112 -> V_288 = F_238 ( V_112 -> V_288 ) ;
if ( F_239 ( V_112 -> V_288 ) ) {
V_64 = F_240 ( V_112 -> V_288 ) ;
V_112 -> V_288 = NULL ;
goto V_289;
}
#endif
#ifdef F_241
V_112 -> V_290 = V_191 ;
V_112 -> V_291 = V_191 ;
F_242 ( & V_112 -> V_292 ) ;
#endif
#ifdef F_243
V_112 -> V_293 = 0 ;
V_112 -> V_252 = 0 ;
V_112 -> V_294 = 0 ;
V_112 -> V_295 = 0 ;
V_112 -> V_296 = V_297 ;
V_112 -> V_298 = 0 ;
V_112 -> V_253 = 1 ;
V_112 -> V_299 = V_297 ;
V_112 -> V_300 = 0 ;
V_112 -> V_301 = 0 ;
V_112 -> V_302 = 0 ;
V_112 -> V_303 = 0 ;
V_112 -> V_304 = 0 ;
#endif
#ifdef F_244
V_112 -> V_305 = 0 ;
V_112 -> V_306 = 0 ;
V_112 -> V_307 = 0 ;
#endif
#ifdef F_245
V_112 -> V_308 = NULL ;
#endif
#ifdef F_246
V_112 -> V_309 = 0 ;
V_112 -> V_310 = 0 ;
#endif
V_64 = F_247 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_311;
V_64 = F_248 ( V_112 ) ;
if ( V_64 )
goto V_311;
V_64 = F_249 ( V_112 ) ;
if ( V_64 )
goto V_312;
F_250 ( V_112 ) ;
V_64 = F_251 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_313;
V_64 = F_179 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_314;
V_64 = F_177 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_315;
V_64 = F_187 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_316;
V_64 = F_195 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_317;
V_64 = F_174 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_318;
V_64 = F_252 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_319;
V_64 = F_181 ( V_165 , V_112 ) ;
if ( V_64 )
goto V_320;
V_64 = F_253 ( V_165 , V_239 , V_240 , V_112 ) ;
if ( V_64 )
goto V_321;
if ( V_237 != & V_322 ) {
V_64 = - V_104 ;
V_237 = F_254 ( V_112 -> V_249 -> V_250 ) ;
if ( ! V_237 )
goto V_321;
}
V_112 -> V_323 = ( V_165 & V_324 ) ? V_241 : NULL ;
V_112 -> V_159 = ( V_165 & V_325 ) ? V_241 : NULL ;
#ifdef F_182
V_112 -> V_326 = NULL ;
#endif
#ifdef F_162
V_112 -> V_156 = NULL ;
#ifdef F_164
V_112 -> V_157 = NULL ;
#endif
F_70 ( & V_112 -> V_158 ) ;
V_112 -> V_327 = NULL ;
#endif
if ( ( V_165 & ( V_172 | V_328 ) ) == V_172 )
V_112 -> V_329 = V_112 -> V_330 = 0 ;
F_255 ( V_112 ) ;
F_256 ( V_112 , V_331 ) ;
#ifdef F_257
F_256 ( V_112 , F_257 ) ;
#endif
F_258 ( V_112 ) ;
V_112 -> V_237 = F_259 ( V_237 ) ;
if ( V_165 & V_205 ) {
V_112 -> V_332 = - 1 ;
V_112 -> V_221 = V_27 -> V_221 ;
V_112 -> V_333 = V_27 -> V_333 ;
} else {
if ( V_165 & V_246 )
V_112 -> V_332 = V_27 -> V_221 -> V_332 ;
else
V_112 -> V_332 = ( V_165 & V_334 ) ;
V_112 -> V_221 = V_112 ;
V_112 -> V_333 = V_112 -> V_237 ;
}
V_112 -> V_335 = 0 ;
V_112 -> V_336 = 128 >> ( V_337 - 10 ) ;
V_112 -> V_338 = 0 ;
V_112 -> V_339 = 0 ;
F_70 ( & V_112 -> V_340 ) ;
V_112 -> V_341 = NULL ;
F_260 ( & V_1 ) ;
if ( V_165 & ( V_246 | V_205 ) ) {
V_112 -> V_342 = V_27 -> V_342 ;
V_112 -> V_343 = V_27 -> V_343 ;
} else {
V_112 -> V_342 = V_27 ;
V_112 -> V_343 = V_27 -> V_344 ;
}
F_135 ( & V_27 -> V_194 -> V_227 ) ;
F_206 ( V_112 ) ;
F_261 () ;
if ( F_262 ( V_27 ) ) {
F_137 ( & V_27 -> V_194 -> V_227 ) ;
F_263 ( & V_1 ) ;
V_64 = - V_345 ;
goto V_346;
}
if ( F_154 ( V_112 -> V_237 ) ) {
F_264 ( V_112 , ( V_165 & V_347 ) || V_242 ) ;
F_216 ( V_112 , V_348 , V_237 ) ;
if ( F_265 ( V_112 ) ) {
F_216 ( V_112 , V_349 , F_266 ( V_27 ) ) ;
F_216 ( V_112 , V_350 , F_267 ( V_27 ) ) ;
if ( F_268 ( V_237 ) ) {
F_269 ( V_237 ) -> V_351 = V_112 ;
V_112 -> signal -> V_128 |= V_247 ;
}
V_112 -> signal -> V_352 = V_237 ;
V_112 -> signal -> V_353 = F_270 ( V_27 -> signal -> V_353 ) ;
F_271 ( & V_112 -> V_268 , & V_112 -> V_342 -> V_267 ) ;
F_272 ( & V_112 -> V_354 , & V_33 . V_354 ) ;
F_273 ( V_112 , V_349 ) ;
F_273 ( V_112 , V_350 ) ;
F_274 ( V_4 ) ;
} else {
V_27 -> signal -> V_206 ++ ;
F_77 ( & V_27 -> signal -> V_207 ) ;
F_77 ( & V_27 -> signal -> V_24 ) ;
F_272 ( & V_112 -> V_340 ,
& V_112 -> V_221 -> V_340 ) ;
F_272 ( & V_112 -> V_210 ,
& V_112 -> signal -> V_208 ) ;
}
F_273 ( V_112 , V_348 ) ;
V_206 ++ ;
}
V_355 ++ ;
F_137 ( & V_27 -> V_194 -> V_227 ) ;
F_275 ( V_112 ) ;
F_263 ( & V_1 ) ;
F_276 ( V_112 ) ;
F_277 ( V_112 ) ;
if ( V_165 & V_205 )
F_278 ( V_27 ) ;
F_279 ( V_112 ) ;
F_280 ( V_112 , V_165 ) ;
F_281 ( V_112 , V_165 ) ;
return V_112 ;
V_346:
if ( V_237 != & V_322 )
F_282 ( V_237 ) ;
V_321:
if ( V_112 -> V_186 )
F_283 ( V_112 ) ;
V_320:
F_284 ( V_112 ) ;
V_319:
if ( V_112 -> V_54 )
F_126 ( V_112 -> V_54 ) ;
V_318:
if ( ! ( V_165 & V_205 ) )
F_28 ( V_112 -> signal ) ;
V_317:
F_189 ( V_112 -> V_194 ) ;
V_316:
F_285 ( V_112 ) ;
V_315:
F_286 ( V_112 ) ;
V_314:
F_287 ( V_112 ) ;
V_313:
F_288 ( V_112 ) ;
V_312:
F_289 ( V_112 ) ;
V_311:
#ifdef F_237
F_90 ( V_112 -> V_288 ) ;
V_289:
#endif
if ( V_165 & V_205 )
F_278 ( V_27 ) ;
F_39 ( V_112 ) ;
F_138 ( F_226 ( V_112 ) -> V_263 -> V_142 ) ;
V_262:
F_75 ( & V_112 -> V_356 -> V_255 -> V_256 ) ;
F_38 ( V_112 ) ;
V_260:
F_24 ( V_112 ) ;
V_251:
return F_150 ( V_64 ) ;
}
static inline void F_290 ( struct V_357 * V_358 )
{
enum V_236 type ;
for ( type = V_348 ; type < V_359 ; ++ type ) {
F_291 ( & V_358 [ type ] . V_7 ) ;
V_358 [ type ] . V_237 = & V_322 ;
}
}
struct V_5 * F_292 ( int V_2 )
{
struct V_5 * V_146 ;
V_146 = F_217 ( V_172 , 0 , 0 , NULL , & V_322 , 0 ) ;
if ( ! F_239 ( V_146 ) ) {
F_290 ( V_146 -> V_238 ) ;
F_293 ( V_146 , V_2 ) ;
}
return V_146 ;
}
long F_294 ( unsigned long V_165 ,
unsigned long V_239 ,
unsigned long V_240 ,
int T_2 * V_360 ,
int T_2 * V_241 )
{
struct V_5 * V_112 ;
int V_242 = 0 ;
long V_361 ;
if ( ! ( V_165 & V_362 ) ) {
if ( V_165 & V_328 )
V_242 = V_363 ;
else if ( ( V_165 & V_334 ) != V_364 )
V_242 = V_365 ;
else
V_242 = V_366 ;
if ( F_154 ( ! F_295 ( V_27 , V_242 ) ) )
V_242 = 0 ;
}
V_112 = F_217 ( V_165 , V_239 , V_240 ,
V_241 , NULL , V_242 ) ;
if ( ! F_239 ( V_112 ) ) {
struct V_151 V_152 ;
struct V_237 * V_237 ;
F_296 ( V_27 , V_112 ) ;
V_237 = F_297 ( V_112 , V_348 ) ;
V_361 = F_298 ( V_237 ) ;
if ( V_165 & V_367 )
F_169 ( V_361 , V_360 ) ;
if ( V_165 & V_328 ) {
V_112 -> V_153 = & V_152 ;
F_299 ( & V_152 ) ;
F_300 ( V_112 ) ;
}
F_301 ( V_112 ) ;
if ( F_95 ( V_242 ) )
F_302 ( V_242 , V_237 ) ;
if ( V_165 & V_328 ) {
if ( ! F_156 ( V_112 , & V_152 ) )
F_302 ( V_368 , V_237 ) ;
}
F_303 ( V_237 ) ;
} else {
V_361 = F_240 ( V_112 ) ;
}
return V_361 ;
}
T_3 F_304 ( int (* F_305)( void * ) , void * V_369 , unsigned long V_128 )
{
return F_294 ( V_128 | V_172 | V_362 , ( unsigned long ) F_305 ,
( unsigned long ) V_369 , NULL , NULL ) ;
}
static void F_306 ( void * V_370 )
{
struct V_192 * V_194 = V_370 ;
F_102 ( & V_194 -> V_227 ) ;
F_198 ( & V_194 -> V_371 ) ;
}
void T_1 F_307 ( void )
{
V_195 = F_18 ( L_7 ,
sizeof( struct V_192 ) , 0 ,
V_372 | V_29 | V_373 |
V_30 , F_306 ) ;
V_23 = F_18 ( L_8 ,
sizeof( struct V_21 ) , 0 ,
V_372 | V_29 | V_30 , NULL ) ;
V_374 = F_18 ( L_9 ,
sizeof( struct V_181 ) , 0 ,
V_372 | V_29 | V_30 , NULL ) ;
V_375 = F_18 ( L_10 ,
sizeof( struct V_174 ) , 0 ,
V_372 | V_29 | V_30 , NULL ) ;
V_376 = F_18 ( L_11 ,
sizeof( struct V_53 ) , V_377 ,
V_372 | V_29 | V_30 , NULL ) ;
V_83 = F_308 ( V_56 , V_29 ) ;
F_309 () ;
F_310 () ;
}
static int F_311 ( unsigned long V_378 )
{
if ( V_378 & ~ ( V_205 | V_176 | V_243 | V_193 |
V_172 | V_185 | V_379 |
V_380 | V_381 | V_382 |
V_245 | V_248 ) )
return - V_244 ;
if ( V_378 & ( V_205 | V_193 | V_172 ) ) {
if ( F_35 ( & V_27 -> V_54 -> V_116 ) > 1 )
return - V_244 ;
}
return 0 ;
}
static int F_312 ( unsigned long V_378 , struct V_174 * * V_383 )
{
struct V_174 * V_175 = V_27 -> V_175 ;
if ( ! ( V_378 & V_176 ) || ! V_175 )
return 0 ;
if ( V_175 -> V_180 == 1 )
return 0 ;
* V_383 = F_178 ( V_175 ) ;
if ( ! * V_383 )
return - V_104 ;
return 0 ;
}
static int F_313 ( unsigned long V_378 , struct V_181 * * V_384 )
{
struct V_181 * V_385 = V_27 -> V_184 ;
int error = 0 ;
if ( ( V_378 & V_185 ) &&
( V_385 && F_35 ( & V_385 -> V_137 ) > 1 ) ) {
* V_384 = F_180 ( V_385 , & error ) ;
if ( ! * V_384 )
return error ;
}
return 0 ;
}
int F_314 ( struct V_181 * * V_386 )
{
struct V_5 * V_146 = V_27 ;
struct V_181 * V_387 = NULL ;
int error ;
error = F_313 ( V_185 , & V_387 ) ;
if ( error || ! V_387 ) {
* V_386 = NULL ;
return error ;
}
* V_386 = V_146 -> V_184 ;
F_146 ( V_146 ) ;
V_146 -> V_184 = V_387 ;
F_147 ( V_146 ) ;
return 0 ;
}
