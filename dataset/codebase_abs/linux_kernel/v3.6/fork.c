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
F_31 ( V_6 -> signal ) ;
if ( ! F_39 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_40 ( void ) { }
void T_1 F_41 ( unsigned long V_28 )
{
#ifndef F_42
#ifndef F_43
#define F_43 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , sizeof( struct V_5 ) ,
F_43 , V_29 | V_30 , NULL ) ;
#endif
F_40 () ;
V_31 = V_28 / ( 8 * V_16 / V_32 ) ;
if ( V_31 < 20 )
V_31 = 20 ;
V_33 . signal -> V_34 [ V_35 ] . V_36 = V_31 / 2 ;
V_33 . signal -> V_34 [ V_35 ] . V_37 = V_31 / 2 ;
V_33 . signal -> V_34 [ V_38 ] =
V_33 . signal -> V_34 [ V_35 ] ;
}
static struct V_5 * F_44 ( struct V_5 * V_39 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
unsigned long * V_40 ;
int V_7 = F_45 ( V_39 ) ;
int V_41 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_42;
V_41 = F_46 ( V_6 , V_39 ) ;
if ( V_41 )
goto V_43;
V_6 -> V_20 = V_11 ;
F_47 ( V_6 , V_39 ) ;
F_48 ( V_6 ) ;
F_49 ( V_6 ) ;
V_40 = F_50 ( V_6 ) ;
* V_40 = V_44 ;
#ifdef F_51
V_6 -> V_45 = F_52 () ;
#endif
F_53 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_54
V_6 -> V_46 = 0 ;
#endif
V_6 -> V_47 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_43:
F_15 ( V_11 ) ;
V_42:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_55 ( struct V_48 * V_49 , struct V_48 * V_50 )
{
struct V_51 * V_52 , * V_53 , * V_54 , * * V_55 ;
struct V_56 * * V_57 , * V_58 ;
int V_59 ;
unsigned long V_60 ;
struct V_61 * V_62 ;
F_56 ( & V_50 -> V_63 ) ;
F_57 ( V_50 ) ;
F_58 ( & V_49 -> V_63 , V_64 ) ;
V_49 -> V_65 = 0 ;
V_49 -> V_66 = NULL ;
V_49 -> V_67 = NULL ;
V_49 -> V_68 = V_50 -> V_69 ;
V_49 -> V_70 = ~ 0UL ;
V_49 -> V_71 = 0 ;
F_59 ( F_60 ( V_49 ) ) ;
V_49 -> V_72 = V_73 ;
V_57 = & V_49 -> V_72 . V_56 ;
V_58 = NULL ;
V_55 = & V_49 -> V_66 ;
V_59 = F_61 ( V_49 , V_50 ) ;
if ( V_59 )
goto V_74;
V_59 = F_62 ( V_49 , V_50 ) ;
if ( V_59 )
goto V_74;
V_54 = NULL ;
for ( V_52 = V_50 -> V_66 ; V_52 ; V_52 = V_52 -> V_75 ) {
struct V_76 * V_76 ;
if ( V_52 -> V_77 & V_78 ) {
F_63 ( V_49 , V_52 -> V_77 , V_52 -> V_79 ,
- F_64 ( V_52 ) ) ;
continue;
}
V_60 = 0 ;
if ( V_52 -> V_77 & V_80 ) {
unsigned long V_81 = F_64 ( V_52 ) ;
if ( F_65 ( V_50 , V_81 ) )
goto V_82;
V_60 = V_81 ;
}
V_53 = F_66 ( V_83 , V_9 ) ;
if ( ! V_53 )
goto V_82;
* V_53 = * V_52 ;
F_67 ( & V_53 -> V_84 ) ;
V_62 = F_68 ( F_69 ( V_52 ) ) ;
V_59 = F_70 ( V_62 ) ;
if ( F_71 ( V_62 ) )
goto V_85;
F_72 ( V_53 , V_62 ) ;
V_53 -> V_86 = V_49 ;
if ( F_73 ( V_53 , V_52 ) )
goto V_87;
V_53 -> V_77 &= ~ V_88 ;
V_53 -> V_75 = V_53 -> V_89 = NULL ;
V_76 = V_53 -> V_79 ;
if ( V_76 ) {
struct V_90 * V_90 = V_76 -> V_91 . V_92 -> V_93 ;
struct V_94 * V_95 = V_76 -> V_96 ;
F_74 ( V_76 ) ;
if ( V_53 -> V_77 & V_97 )
F_75 ( & V_90 -> V_98 ) ;
F_76 ( & V_95 -> V_99 ) ;
if ( V_53 -> V_77 & V_100 )
V_95 -> V_101 ++ ;
F_77 ( V_95 ) ;
F_78 ( V_53 , V_52 ) ;
F_79 ( V_95 ) ;
F_80 ( & V_95 -> V_99 ) ;
}
if ( F_81 ( V_53 ) )
F_82 ( V_53 ) ;
* V_55 = V_53 ;
V_55 = & V_53 -> V_75 ;
V_53 -> V_89 = V_54 ;
V_54 = V_53 ;
F_83 ( V_49 , V_53 , V_57 , V_58 ) ;
V_57 = & V_53 -> V_102 . V_103 ;
V_58 = & V_53 -> V_102 ;
V_49 -> V_71 ++ ;
V_59 = F_84 ( V_49 , V_50 , V_52 ) ;
if ( V_53 -> V_104 && V_53 -> V_104 -> V_105 )
V_53 -> V_104 -> V_105 ( V_53 ) ;
if ( V_59 )
goto V_74;
if ( V_76 )
F_85 ( V_53 ) ;
}
F_86 ( V_50 , V_49 ) ;
V_59 = 0 ;
V_74:
F_87 ( & V_49 -> V_63 ) ;
F_88 ( V_50 ) ;
F_87 ( & V_50 -> V_63 ) ;
return V_59 ;
V_87:
F_89 ( V_62 ) ;
V_85:
F_10 ( V_83 , V_53 ) ;
V_82:
V_59 = - V_106 ;
F_90 ( V_60 ) ;
goto V_74;
}
static inline int F_91 ( struct V_48 * V_49 )
{
V_49 -> V_107 = F_92 ( V_49 ) ;
if ( F_93 ( ! V_49 -> V_107 ) )
return - V_106 ;
return 0 ;
}
static inline void F_94 ( struct V_48 * V_49 )
{
F_95 ( V_49 , V_49 -> V_107 ) ;
}
static int T_1 F_96 ( char * V_108 )
{
V_109 =
( F_97 ( V_108 , NULL , 0 ) << V_110 ) &
V_111 ;
return 1 ;
}
static void F_98 ( struct V_48 * V_49 )
{
#ifdef F_99
F_100 ( & V_49 -> V_112 ) ;
F_101 ( & V_49 -> V_113 ) ;
#endif
}
static struct V_48 * F_102 ( struct V_48 * V_49 , struct V_5 * V_114 )
{
F_53 ( & V_49 -> V_115 , 1 ) ;
F_53 ( & V_49 -> V_116 , 1 ) ;
F_103 ( & V_49 -> V_63 ) ;
F_67 ( & V_49 -> V_117 ) ;
V_49 -> V_118 = ( V_27 -> V_49 ) ?
( V_27 -> V_49 -> V_118 & V_119 ) : V_109 ;
V_49 -> V_120 = NULL ;
V_49 -> V_121 = 0 ;
memset ( & V_49 -> V_122 , 0 , sizeof( V_49 -> V_122 ) ) ;
F_100 ( & V_49 -> V_123 ) ;
V_49 -> V_68 = V_124 ;
V_49 -> V_70 = ~ 0UL ;
F_98 ( V_49 ) ;
F_104 ( V_49 , V_114 ) ;
if ( F_105 ( ! F_91 ( V_49 ) ) ) {
V_49 -> V_125 = 0 ;
F_106 ( V_49 ) ;
return V_49 ;
}
F_107 ( V_49 ) ;
return NULL ;
}
static void F_108 ( struct V_48 * V_49 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < V_127 ; V_126 ++ ) {
long V_128 = F_109 ( & V_49 -> V_122 . V_129 [ V_126 ] ) ;
if ( F_93 ( V_128 ) )
F_110 ( V_130 L_3
L_4 , V_49 , V_126 , V_128 ) ;
}
#ifdef F_111
F_112 ( V_49 -> V_131 ) ;
#endif
}
struct V_48 * F_113 ( void )
{
struct V_48 * V_49 ;
V_49 = F_114 () ;
if ( ! V_49 )
return NULL ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_115 ( V_49 ) ;
return F_102 ( V_49 , V_27 ) ;
}
void F_116 ( struct V_48 * V_49 )
{
F_19 ( V_49 == & V_132 ) ;
F_94 ( V_49 ) ;
F_117 ( V_49 ) ;
F_118 ( V_49 ) ;
F_108 ( V_49 ) ;
F_107 ( V_49 ) ;
}
void F_119 ( struct V_48 * V_49 )
{
F_120 () ;
if ( F_32 ( & V_49 -> V_115 ) ) {
F_121 ( V_49 ) ;
F_122 ( V_49 ) ;
F_123 ( V_49 ) ;
F_124 ( V_49 ) ;
F_125 ( V_49 ) ;
F_126 ( V_49 , NULL ) ;
if ( ! F_127 ( & V_49 -> V_117 ) ) {
F_128 ( & V_133 ) ;
F_129 ( & V_49 -> V_117 ) ;
F_130 ( & V_133 ) ;
}
if ( V_49 -> V_134 )
F_131 ( V_49 -> V_134 -> V_135 ) ;
F_132 ( V_49 ) ;
}
}
void F_133 ( struct V_48 * V_49 )
{
V_49 -> V_136 ++ ;
}
void F_134 ( struct V_48 * V_49 )
{
V_49 -> V_136 -- ;
if ( ( V_49 -> V_136 == 0 ) && V_49 -> V_137 ) {
F_135 ( V_49 -> V_137 ) ;
V_49 -> V_137 = NULL ;
}
}
void F_126 ( struct V_48 * V_49 , struct V_76 * V_138 )
{
if ( V_138 )
F_74 ( V_138 ) ;
if ( V_49 -> V_137 )
F_135 ( V_49 -> V_137 ) ;
V_49 -> V_137 = V_138 ;
V_49 -> V_136 = 0 ;
}
struct V_76 * F_136 ( struct V_48 * V_49 )
{
struct V_76 * V_137 ;
F_137 ( & V_49 -> V_63 ) ;
V_137 = V_49 -> V_137 ;
if ( V_137 )
F_74 ( V_137 ) ;
F_138 ( & V_49 -> V_63 ) ;
return V_137 ;
}
static void F_139 ( struct V_48 * V_50 , struct V_48 * V_139 )
{
V_139 -> V_137 = F_136 ( V_50 ) ;
}
struct V_48 * F_140 ( struct V_5 * V_140 )
{
struct V_48 * V_49 ;
F_141 ( V_140 ) ;
V_49 = V_140 -> V_49 ;
if ( V_49 ) {
if ( V_140 -> V_118 & V_141 )
V_49 = NULL ;
else
F_142 ( & V_49 -> V_115 ) ;
}
F_143 ( V_140 ) ;
return V_49 ;
}
struct V_48 * F_144 ( struct V_5 * V_140 , unsigned int V_142 )
{
struct V_48 * V_49 ;
int V_41 ;
V_41 = F_145 ( & V_140 -> signal -> V_143 ) ;
if ( V_41 )
return F_146 ( V_41 ) ;
V_49 = F_140 ( V_140 ) ;
if ( V_49 && V_49 != V_27 -> V_49 &&
! F_147 ( V_140 , V_142 ) ) {
F_119 ( V_49 ) ;
V_49 = F_146 ( - V_144 ) ;
}
F_80 ( & V_140 -> signal -> V_143 ) ;
return V_49 ;
}
static void F_148 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
F_141 ( V_6 ) ;
V_146 = V_6 -> V_147 ;
if ( F_105 ( V_146 ) ) {
V_6 -> V_147 = NULL ;
F_149 ( V_146 ) ;
}
F_143 ( V_6 ) ;
}
static int F_150 ( struct V_5 * V_148 ,
struct V_145 * V_146 )
{
int V_149 ;
F_151 () ;
V_149 = F_152 ( V_146 ) ;
F_153 () ;
if ( V_149 ) {
F_141 ( V_148 ) ;
V_148 -> V_147 = NULL ;
F_143 ( V_148 ) ;
}
F_154 ( V_148 ) ;
return V_149 ;
}
void F_155 ( struct V_5 * V_6 , struct V_48 * V_49 )
{
#ifdef F_156
if ( F_93 ( V_6 -> V_150 ) ) {
F_157 ( V_6 ) ;
V_6 -> V_150 = NULL ;
}
#ifdef F_158
if ( F_93 ( V_6 -> V_151 ) ) {
F_159 ( V_6 ) ;
V_6 -> V_151 = NULL ;
}
#endif
if ( F_93 ( ! F_127 ( & V_6 -> V_152 ) ) )
F_160 ( V_6 ) ;
#endif
F_161 ( V_6 ) ;
F_162 ( V_6 , V_49 ) ;
if ( V_6 -> V_153 ) {
if ( ! ( V_6 -> V_118 & V_154 ) &&
F_35 ( & V_49 -> V_115 ) > 1 ) {
F_163 ( 0 , V_6 -> V_153 ) ;
F_164 ( V_6 -> V_153 , V_155 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_153 = NULL ;
}
if ( V_6 -> V_147 )
F_148 ( V_6 ) ;
}
struct V_48 * F_165 ( struct V_5 * V_6 )
{
struct V_48 * V_49 , * V_50 = V_27 -> V_49 ;
int V_41 ;
if ( ! V_50 )
return NULL ;
V_49 = F_114 () ;
if ( ! V_49 )
goto V_82;
memcpy ( V_49 , V_50 , sizeof( * V_49 ) ) ;
F_115 ( V_49 ) ;
#ifdef F_111
V_49 -> V_131 = NULL ;
#endif
F_166 ( V_49 ) ;
if ( ! F_102 ( V_49 , V_6 ) )
goto V_82;
if ( F_167 ( V_6 , V_49 ) )
goto V_156;
F_139 ( V_50 , V_49 ) ;
V_41 = F_55 ( V_49 , V_50 ) ;
if ( V_41 )
goto V_157;
V_49 -> V_158 = F_168 ( V_49 ) ;
V_49 -> V_159 = V_49 -> V_160 ;
if ( V_49 -> V_134 && ! F_169 ( V_49 -> V_134 -> V_135 ) )
goto V_157;
return V_49 ;
V_157:
V_49 -> V_134 = NULL ;
F_119 ( V_49 ) ;
V_82:
return NULL ;
V_156:
F_94 ( V_49 ) ;
F_107 ( V_49 ) ;
return NULL ;
}
static int F_170 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_48 * V_49 , * V_50 ;
int V_59 ;
V_6 -> V_162 = V_6 -> V_163 = 0 ;
V_6 -> V_164 = V_6 -> V_165 = 0 ;
#ifdef F_171
V_6 -> V_166 = V_6 -> V_164 + V_6 -> V_165 ;
#endif
V_6 -> V_49 = NULL ;
V_6 -> V_167 = NULL ;
V_50 = V_27 -> V_49 ;
if ( ! V_50 )
return 0 ;
if ( V_161 & V_168 ) {
F_142 ( & V_50 -> V_115 ) ;
V_49 = V_50 ;
goto V_169;
}
V_59 = - V_106 ;
V_49 = F_165 ( V_6 ) ;
if ( ! V_49 )
goto V_82;
V_169:
V_6 -> V_49 = V_49 ;
V_6 -> V_167 = V_49 ;
return 0 ;
V_82:
return V_59 ;
}
static int F_172 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_170 * V_171 = V_27 -> V_171 ;
if ( V_161 & V_172 ) {
F_128 ( & V_171 -> V_173 ) ;
if ( V_171 -> V_174 ) {
F_130 ( & V_171 -> V_173 ) ;
return - V_175 ;
}
V_171 -> V_176 ++ ;
F_130 ( & V_171 -> V_173 ) ;
return 0 ;
}
V_6 -> V_171 = F_173 ( V_171 ) ;
if ( ! V_6 -> V_171 )
return - V_106 ;
return 0 ;
}
static int F_174 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_177 * V_178 , * V_179 ;
int error = 0 ;
V_178 = V_27 -> V_180 ;
if ( ! V_178 )
goto V_74;
if ( V_161 & V_181 ) {
F_142 ( & V_178 -> V_129 ) ;
goto V_74;
}
V_179 = F_175 ( V_178 , & error ) ;
if ( ! V_179 )
goto V_74;
V_6 -> V_180 = V_179 ;
error = 0 ;
V_74:
return error ;
}
static int F_176 ( unsigned long V_161 , struct V_5 * V_6 )
{
#ifdef F_177
struct V_182 * V_183 = V_27 -> V_182 ;
struct V_182 * V_184 ;
if ( ! V_183 )
return 0 ;
if ( V_161 & V_185 ) {
F_178 ( V_183 ) ;
V_6 -> V_182 = V_183 ;
} else if ( F_179 ( V_183 -> V_186 ) ) {
V_184 = F_180 ( V_6 , V_9 , V_187 ) ;
if ( F_93 ( ! V_184 ) )
return - V_106 ;
V_184 -> V_186 = V_183 -> V_186 ;
F_181 ( V_184 ) ;
}
#endif
return 0 ;
}
static int F_182 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_188 * V_22 ;
if ( V_161 & V_189 ) {
F_142 ( & V_27 -> V_190 -> V_129 ) ;
return 0 ;
}
V_22 = F_66 ( V_191 , V_9 ) ;
F_183 ( V_6 -> V_190 , V_22 ) ;
if ( ! V_22 )
return - V_106 ;
F_53 ( & V_22 -> V_129 , 1 ) ;
memcpy ( V_22 -> V_192 , V_27 -> V_190 -> V_192 , sizeof( V_22 -> V_192 ) ) ;
return 0 ;
}
void F_184 ( struct V_188 * V_190 )
{
if ( F_32 ( & V_190 -> V_129 ) ) {
F_185 ( V_190 ) ;
F_10 ( V_191 , V_190 ) ;
}
}
static void F_186 ( struct V_21 * V_22 )
{
unsigned long V_193 ;
F_187 ( V_22 ) ;
V_193 = F_188 ( V_22 -> V_34 [ V_194 ] . V_36 ) ;
if ( V_193 != V_195 ) {
V_22 -> V_196 . V_197 = F_189 ( V_193 ) ;
V_22 -> V_198 . V_199 = 1 ;
}
F_67 ( & V_22 -> V_200 [ 0 ] ) ;
F_67 ( & V_22 -> V_200 [ 1 ] ) ;
F_67 ( & V_22 -> V_200 [ 2 ] ) ;
}
static int F_190 ( unsigned long V_161 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_161 & V_201 )
return 0 ;
V_22 = F_191 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_106 ;
V_22 -> V_202 = 1 ;
F_53 ( & V_22 -> V_203 , 1 ) ;
F_53 ( & V_22 -> V_24 , 1 ) ;
F_192 ( & V_22 -> V_204 ) ;
if ( V_161 & V_205 )
V_22 -> V_118 |= V_206 ;
V_22 -> V_207 = V_6 ;
F_193 ( & V_22 -> V_208 ) ;
F_67 ( & V_22 -> V_209 ) ;
F_194 ( & V_22 -> V_210 , V_211 , V_212 ) ;
V_22 -> V_210 . V_213 = V_214 ;
F_141 ( V_27 -> V_215 ) ;
memcpy ( V_22 -> V_34 , V_27 -> signal -> V_34 , sizeof V_22 -> V_34 ) ;
F_143 ( V_27 -> V_215 ) ;
F_186 ( V_22 ) ;
F_195 ( V_22 ) ;
F_196 ( V_22 ) ;
#ifdef F_197
F_103 ( & V_22 -> V_216 ) ;
#endif
V_22 -> V_217 = V_27 -> signal -> V_217 ;
V_22 -> V_218 = V_27 -> signal -> V_218 ;
V_22 -> V_219 = V_27 -> signal -> V_219 ;
V_22 -> V_220 = V_27 -> signal -> V_220 ||
V_27 -> signal -> V_221 ;
F_198 ( & V_22 -> V_143 ) ;
return 0 ;
}
static void F_199 ( unsigned long V_161 , struct V_5 * V_114 )
{
unsigned long V_222 = V_114 -> V_118 ;
V_222 &= ~ ( V_223 | V_224 ) ;
V_222 |= V_225 ;
V_114 -> V_118 = V_222 ;
}
static void F_200 ( struct V_5 * V_114 )
{
F_201 ( & V_114 -> V_226 ) ;
#ifdef F_202
F_203 ( & V_114 -> V_227 ) ;
V_114 -> V_228 = NULL ;
#endif
}
void F_104 ( struct V_48 * V_49 , struct V_5 * V_114 )
{
V_49 -> V_229 = V_114 ;
}
static void F_204 ( struct V_5 * V_6 )
{
V_6 -> V_196 . V_197 = 0 ;
V_6 -> V_196 . V_230 = 0 ;
V_6 -> V_196 . V_231 = 0 ;
F_67 ( & V_6 -> V_200 [ 0 ] ) ;
F_67 ( & V_6 -> V_200 [ 1 ] ) ;
F_67 ( & V_6 -> V_200 [ 2 ] ) ;
}
static struct V_5 * F_205 ( unsigned long V_161 ,
unsigned long V_232 ,
struct V_233 * V_234 ,
unsigned long V_235 ,
int T_2 * V_236 ,
struct V_237 * V_237 ,
int V_238 )
{
int V_59 ;
struct V_5 * V_114 ;
int V_239 = 0 ;
if ( ( V_161 & ( V_240 | V_172 ) ) == ( V_240 | V_172 ) )
return F_146 ( - V_241 ) ;
if ( ( V_161 & V_201 ) && ! ( V_161 & V_189 ) )
return F_146 ( - V_241 ) ;
if ( ( V_161 & V_189 ) && ! ( V_161 & V_168 ) )
return F_146 ( - V_241 ) ;
if ( ( V_161 & V_242 ) &&
V_27 -> signal -> V_118 & V_206 )
return F_146 ( - V_241 ) ;
V_59 = F_206 ( V_161 ) ;
if ( V_59 )
goto V_243;
V_59 = - V_106 ;
V_114 = F_44 ( V_27 ) ;
if ( ! V_114 )
goto V_243;
F_207 ( V_114 ) ;
F_208 ( V_114 ) ;
F_200 ( V_114 ) ;
#ifdef F_209
F_210 ( ! V_114 -> V_244 ) ;
F_210 ( ! V_114 -> V_245 ) ;
#endif
V_59 = - V_175 ;
if ( F_35 ( & V_114 -> V_246 -> V_247 -> V_248 ) >=
F_211 ( V_114 , V_35 ) ) {
if ( ! F_212 ( V_249 ) && ! F_212 ( V_250 ) &&
V_114 -> V_246 -> V_247 != V_251 )
goto V_252;
}
V_27 -> V_118 &= ~ V_253 ;
V_59 = F_213 ( V_114 , V_161 ) ;
if ( V_59 < 0 )
goto V_252;
V_59 = - V_175 ;
if ( V_202 >= V_31 )
goto V_254;
if ( ! F_169 ( F_214 ( V_114 ) -> V_255 -> V_135 ) )
goto V_254;
V_114 -> V_256 = 0 ;
F_215 ( V_114 ) ;
F_199 ( V_161 , V_114 ) ;
F_67 ( & V_114 -> V_257 ) ;
F_67 ( & V_114 -> V_258 ) ;
F_216 ( V_114 ) ;
V_114 -> V_147 = NULL ;
F_100 ( & V_114 -> V_259 ) ;
F_193 ( & V_114 -> V_260 ) ;
V_114 -> V_261 = V_114 -> V_262 = V_114 -> V_263 = 0 ;
V_114 -> V_264 = V_114 -> V_265 = 0 ;
#ifndef F_217
V_114 -> V_266 = V_114 -> V_267 = 0 ;
#endif
#if F_218 ( V_268 )
memset ( & V_114 -> V_122 , 0 , sizeof( V_114 -> V_122 ) ) ;
#endif
V_114 -> V_269 = V_27 -> V_270 ;
F_219 ( & V_114 -> V_271 ) ;
F_220 ( V_114 ) ;
F_204 ( V_114 ) ;
F_221 ( & V_114 -> V_272 ) ;
V_114 -> V_273 = V_114 -> V_272 ;
F_222 ( & V_114 -> V_273 ) ;
V_114 -> V_182 = NULL ;
V_114 -> V_274 = NULL ;
if ( V_161 & V_201 )
F_223 ( V_27 ) ;
F_224 ( V_114 ) ;
#ifdef F_225
V_114 -> V_61 = F_68 ( V_114 -> V_61 ) ;
if ( F_71 ( V_114 -> V_61 ) ) {
V_59 = F_70 ( V_114 -> V_61 ) ;
V_114 -> V_61 = NULL ;
goto V_275;
}
F_226 ( V_114 ) ;
#endif
#ifdef F_227
V_114 -> V_276 = V_187 ;
V_114 -> V_277 = V_187 ;
F_228 ( & V_114 -> V_278 ) ;
#endif
#ifdef F_229
V_114 -> V_279 = 0 ;
#ifdef F_230
V_114 -> V_244 = 1 ;
#else
V_114 -> V_244 = 0 ;
#endif
V_114 -> V_280 = 0 ;
V_114 -> V_281 = 0 ;
V_114 -> V_282 = V_283 ;
V_114 -> V_284 = 0 ;
V_114 -> V_245 = 1 ;
V_114 -> V_285 = V_283 ;
V_114 -> V_286 = 0 ;
V_114 -> V_287 = 0 ;
V_114 -> V_288 = 0 ;
V_114 -> V_289 = 0 ;
V_114 -> V_290 = 0 ;
#endif
#ifdef F_231
V_114 -> V_291 = 0 ;
V_114 -> V_292 = 0 ;
V_114 -> V_293 = 0 ;
#endif
#ifdef F_232
V_114 -> V_294 = NULL ;
#endif
#ifdef F_233
V_114 -> V_295 . V_296 = 0 ;
V_114 -> V_295 . V_297 = NULL ;
#endif
F_234 ( V_114 ) ;
V_59 = F_235 ( V_114 ) ;
if ( V_59 )
goto V_298;
V_59 = F_236 ( V_114 ) ;
if ( V_59 )
goto V_298;
V_59 = F_237 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_299;
V_59 = F_174 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_300;
V_59 = F_172 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_301;
V_59 = F_182 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_302;
V_59 = F_190 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_303;
V_59 = F_170 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_304;
V_59 = F_238 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_305;
V_59 = F_176 ( V_161 , V_114 ) ;
if ( V_59 )
goto V_306;
V_59 = F_239 ( V_161 , V_232 , V_235 , V_114 , V_234 ) ;
if ( V_59 )
goto V_307;
if ( V_237 != & V_308 ) {
V_59 = - V_106 ;
V_237 = F_240 ( V_114 -> V_309 -> V_310 ) ;
if ( ! V_237 )
goto V_307;
}
V_114 -> V_237 = F_241 ( V_237 ) ;
V_114 -> V_311 = V_114 -> V_237 ;
if ( V_161 & V_201 )
V_114 -> V_311 = V_27 -> V_311 ;
V_114 -> V_312 = ( V_161 & V_313 ) ? V_236 : NULL ;
V_114 -> V_153 = ( V_161 & V_314 ) ? V_236 : NULL ;
#ifdef F_177
V_114 -> V_315 = NULL ;
#endif
#ifdef F_156
V_114 -> V_150 = NULL ;
#ifdef F_158
V_114 -> V_151 = NULL ;
#endif
F_67 ( & V_114 -> V_152 ) ;
V_114 -> V_316 = NULL ;
#endif
F_242 ( V_114 ) ;
if ( ( V_161 & ( V_168 | V_317 ) ) == V_168 )
V_114 -> V_318 = V_114 -> V_319 = 0 ;
F_243 ( V_114 ) ;
F_244 ( V_114 , V_320 ) ;
#ifdef F_245
F_244 ( V_114 , F_245 ) ;
#endif
F_246 ( V_114 ) ;
if ( V_161 & V_201 )
V_114 -> V_321 = - 1 ;
else if ( V_161 & V_242 )
V_114 -> V_321 = V_27 -> V_215 -> V_321 ;
else
V_114 -> V_321 = ( V_161 & V_322 ) ;
V_114 -> V_323 = 0 ;
V_114 -> V_25 = 0 ;
V_114 -> V_324 = 0 ;
V_114 -> V_325 = 128 >> ( V_326 - 10 ) ;
V_114 -> V_327 = 0 ;
V_114 -> V_215 = V_114 ;
F_67 ( & V_114 -> V_328 ) ;
V_114 -> V_329 = NULL ;
F_247 ( V_114 ) ;
V_239 = 1 ;
F_248 ( & V_1 ) ;
if ( V_161 & ( V_242 | V_201 ) ) {
V_114 -> V_330 = V_27 -> V_330 ;
V_114 -> V_331 = V_27 -> V_331 ;
} else {
V_114 -> V_330 = V_27 ;
V_114 -> V_331 = V_27 -> V_332 ;
}
F_128 ( & V_27 -> V_190 -> V_333 ) ;
F_249 () ;
if ( F_250 ( V_27 ) ) {
F_130 ( & V_27 -> V_190 -> V_333 ) ;
F_251 ( & V_1 ) ;
V_59 = - V_334 ;
goto V_335;
}
if ( V_161 & V_201 ) {
V_27 -> signal -> V_202 ++ ;
F_142 ( & V_27 -> signal -> V_203 ) ;
F_142 ( & V_27 -> signal -> V_24 ) ;
V_114 -> V_215 = V_27 -> V_215 ;
F_252 ( & V_114 -> V_328 , & V_114 -> V_215 -> V_328 ) ;
}
if ( F_105 ( V_114 -> V_237 ) ) {
F_253 ( V_114 , ( V_161 & V_336 ) || V_238 ) ;
if ( F_254 ( V_114 ) ) {
if ( F_255 ( V_237 ) )
V_114 -> V_309 -> V_310 -> V_337 = V_114 ;
V_114 -> signal -> V_338 = V_237 ;
V_114 -> signal -> V_339 = F_256 ( V_27 -> signal -> V_339 ) ;
F_257 ( V_114 , V_340 , F_258 ( V_27 ) ) ;
F_257 ( V_114 , V_341 , F_259 ( V_27 ) ) ;
F_260 ( & V_114 -> V_258 , & V_114 -> V_330 -> V_257 ) ;
F_252 ( & V_114 -> V_342 , & V_33 . V_342 ) ;
F_261 ( V_4 ) ;
}
F_257 ( V_114 , V_343 , V_237 ) ;
V_202 ++ ;
}
V_344 ++ ;
F_130 ( & V_27 -> V_190 -> V_333 ) ;
F_251 ( & V_1 ) ;
F_262 ( V_114 ) ;
F_263 ( V_114 ) ;
if ( V_161 & V_201 )
F_264 ( V_27 ) ;
F_265 ( V_114 ) ;
F_266 ( V_114 , V_161 ) ;
return V_114 ;
V_335:
if ( V_237 != & V_308 )
F_267 ( V_237 ) ;
V_307:
if ( V_114 -> V_182 )
F_268 ( V_114 ) ;
V_306:
if ( F_93 ( V_161 & V_205 ) )
F_269 ( V_114 -> V_309 -> V_310 ) ;
F_270 ( V_114 ) ;
V_305:
if ( V_114 -> V_49 )
F_119 ( V_114 -> V_49 ) ;
V_304:
if ( ! ( V_161 & V_201 ) )
F_28 ( V_114 -> signal ) ;
V_303:
F_184 ( V_114 -> V_190 ) ;
V_302:
F_271 ( V_114 ) ;
V_301:
F_272 ( V_114 ) ;
V_300:
F_273 ( V_114 ) ;
V_299:
F_274 ( V_114 ) ;
V_298:
F_275 ( V_114 ) ;
#ifdef F_225
F_89 ( V_114 -> V_61 ) ;
V_275:
#endif
if ( V_161 & V_201 )
F_264 ( V_27 ) ;
F_276 ( V_114 , V_239 ) ;
F_38 ( V_114 ) ;
F_131 ( F_214 ( V_114 ) -> V_255 -> V_135 ) ;
V_254:
F_75 ( & V_114 -> V_345 -> V_247 -> V_248 ) ;
F_37 ( V_114 ) ;
V_252:
F_24 ( V_114 ) ;
V_243:
return F_146 ( V_59 ) ;
}
static inline void F_277 ( struct V_346 * V_347 )
{
enum V_348 type ;
for ( type = V_343 ; type < V_349 ; ++ type ) {
F_278 ( & V_347 [ type ] . V_7 ) ;
V_347 [ type ] . V_237 = & V_308 ;
}
}
struct V_5 * T_3 F_279 ( int V_2 )
{
struct V_5 * V_140 ;
struct V_233 V_234 ;
V_140 = F_205 ( V_168 , 0 , F_280 ( & V_234 ) , 0 , NULL ,
& V_308 , 0 ) ;
if ( ! F_71 ( V_140 ) ) {
F_277 ( V_140 -> V_350 ) ;
F_281 ( V_140 , V_2 ) ;
}
return V_140 ;
}
long F_282 ( unsigned long V_161 ,
unsigned long V_232 ,
struct V_233 * V_234 ,
unsigned long V_235 ,
int T_2 * V_351 ,
int T_2 * V_236 )
{
struct V_5 * V_114 ;
int V_238 = 0 ;
long V_352 ;
if ( V_161 & V_353 ) {
if ( V_161 & V_201 )
return - V_241 ;
if ( ! F_212 ( V_249 ) || ! F_212 ( V_354 ) ||
! F_212 ( V_355 ) )
return - V_356 ;
}
if ( F_105 ( F_283 ( V_234 ) ) && ! ( V_161 & V_357 ) ) {
if ( V_161 & V_317 )
V_238 = V_358 ;
else if ( ( V_161 & V_322 ) != V_359 )
V_238 = V_360 ;
else
V_238 = V_361 ;
if ( F_105 ( ! F_284 ( V_27 , V_238 ) ) )
V_238 = 0 ;
}
V_114 = F_205 ( V_161 , V_232 , V_234 , V_235 ,
V_236 , NULL , V_238 ) ;
if ( ! F_71 ( V_114 ) ) {
struct V_145 V_146 ;
F_285 ( V_27 , V_114 ) ;
V_352 = F_286 ( V_114 ) ;
if ( V_161 & V_362 )
F_163 ( V_352 , V_351 ) ;
if ( V_161 & V_317 ) {
V_114 -> V_147 = & V_146 ;
F_287 ( & V_146 ) ;
F_288 ( V_114 ) ;
}
F_289 ( V_114 ) ;
if ( F_93 ( V_238 ) )
F_290 ( V_238 , V_352 ) ;
if ( V_161 & V_317 ) {
if ( ! F_150 ( V_114 , & V_146 ) )
F_290 ( V_363 , V_352 ) ;
}
} else {
V_352 = F_70 ( V_114 ) ;
}
return V_352 ;
}
static void F_291 ( void * V_364 )
{
struct V_188 * V_190 = V_364 ;
F_100 ( & V_190 -> V_333 ) ;
F_192 ( & V_190 -> V_365 ) ;
}
void T_1 F_292 ( void )
{
V_191 = F_18 ( L_5 ,
sizeof( struct V_188 ) , 0 ,
V_366 | V_29 | V_367 |
V_30 , F_291 ) ;
V_23 = F_18 ( L_6 ,
sizeof( struct V_21 ) , 0 ,
V_366 | V_29 | V_30 , NULL ) ;
V_368 = F_18 ( L_7 ,
sizeof( struct V_177 ) , 0 ,
V_366 | V_29 | V_30 , NULL ) ;
V_369 = F_18 ( L_8 ,
sizeof( struct V_170 ) , 0 ,
V_366 | V_29 | V_30 , NULL ) ;
V_370 = F_18 ( L_9 ,
sizeof( struct V_48 ) , V_371 ,
V_366 | V_29 | V_30 , NULL ) ;
V_83 = F_293 ( V_51 , V_29 ) ;
F_294 () ;
F_295 () ;
}
static int F_296 ( unsigned long V_372 )
{
if ( V_372 & ~ ( V_201 | V_172 | V_240 | V_189 |
V_168 | V_181 | V_373 |
V_374 | V_375 | V_376 ) )
return - V_241 ;
if ( V_372 & ( V_201 | V_189 | V_168 ) ) {
if ( F_35 ( & V_27 -> V_49 -> V_115 ) > 1 )
return - V_241 ;
}
return 0 ;
}
static int F_297 ( unsigned long V_372 , struct V_170 * * V_377 )
{
struct V_170 * V_171 = V_27 -> V_171 ;
if ( ! ( V_372 & V_172 ) || ! V_171 )
return 0 ;
if ( V_171 -> V_176 == 1 )
return 0 ;
* V_377 = F_173 ( V_171 ) ;
if ( ! * V_377 )
return - V_106 ;
return 0 ;
}
static int F_298 ( unsigned long V_372 , struct V_177 * * V_378 )
{
struct V_177 * V_379 = V_27 -> V_180 ;
int error = 0 ;
if ( ( V_372 & V_181 ) &&
( V_379 && F_35 ( & V_379 -> V_129 ) > 1 ) ) {
* V_378 = F_175 ( V_379 , & error ) ;
if ( ! * V_378 )
return error ;
}
return 0 ;
}
int F_299 ( struct V_177 * * V_380 )
{
struct V_5 * V_140 = V_27 ;
struct V_177 * V_381 = NULL ;
int error ;
error = F_298 ( V_181 , & V_381 ) ;
if ( error || ! V_381 ) {
* V_380 = NULL ;
return error ;
}
* V_380 = V_140 -> V_180 ;
F_141 ( V_140 ) ;
V_140 -> V_180 = V_381 ;
F_143 ( V_140 ) ;
return 0 ;
}
