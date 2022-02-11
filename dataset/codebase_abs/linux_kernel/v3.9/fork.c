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
return F_8 ( V_15 , V_16 , V_7 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_10 ( V_15 , V_11 ) ;
}
void F_17 ( void )
{
V_15 = F_18 ( L_1 , V_17 ,
V_17 , 0 , NULL ) ;
F_19 ( V_15 == NULL ) ;
}
static void F_20 ( struct V_10 * V_11 , int V_18 )
{
struct V_19 * V_19 = F_21 ( F_22 ( V_11 ) ) ;
F_23 ( V_19 , V_20 , V_18 ) ;
}
void F_24 ( struct V_5 * V_6 )
{
F_20 ( V_6 -> V_21 , - 1 ) ;
F_11 ( V_6 -> V_21 ) ;
F_15 ( V_6 -> V_21 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
F_27 ( V_6 ) ;
F_6 ( V_6 ) ;
F_9 ( V_6 ) ;
}
static inline void F_28 ( struct V_22 * V_23 )
{
F_29 ( V_23 ) ;
F_30 ( V_23 ) ;
F_10 ( V_24 , V_23 ) ;
}
static inline void F_31 ( struct V_22 * V_23 )
{
if ( F_32 ( & V_23 -> V_25 ) )
F_28 ( V_23 ) ;
}
void F_33 ( struct V_5 * V_6 )
{
F_34 ( ! V_6 -> V_26 ) ;
F_34 ( F_35 ( & V_6 -> V_27 ) ) ;
F_34 ( V_6 == V_28 ) ;
F_36 ( V_6 ) ;
F_37 ( V_6 ) ;
F_38 ( V_6 ) ;
F_31 ( V_6 -> signal ) ;
if ( ! F_39 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_40 ( void ) { }
void T_1 F_41 ( unsigned long V_29 )
{
#ifndef F_42
#ifndef F_43
#define F_43 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , sizeof( struct V_5 ) ,
F_43 , V_30 | V_31 , NULL ) ;
#endif
F_40 () ;
V_32 = V_29 / ( 8 * V_17 / V_33 ) ;
if ( V_32 < 20 )
V_32 = 20 ;
V_34 . signal -> V_35 [ V_36 ] . V_37 = V_32 / 2 ;
V_34 . signal -> V_35 [ V_36 ] . V_38 = V_32 / 2 ;
V_34 . signal -> V_35 [ V_39 ] =
V_34 . signal -> V_35 [ V_36 ] ;
}
static struct V_5 * F_44 ( struct V_5 * V_40 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
unsigned long * V_41 ;
int V_7 = F_45 ( V_40 ) ;
int V_42 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_43;
V_42 = F_46 ( V_6 , V_40 ) ;
if ( V_42 )
goto V_44;
V_6 -> V_21 = V_11 ;
F_47 ( V_6 , V_40 ) ;
F_48 ( V_6 ) ;
F_49 ( V_6 ) ;
V_41 = F_50 ( V_6 ) ;
* V_41 = V_45 ;
#ifdef F_51
V_6 -> V_46 = F_52 () ;
#endif
F_53 ( & V_6 -> V_27 , 2 ) ;
#ifdef F_54
V_6 -> V_47 = 0 ;
#endif
V_6 -> V_48 = NULL ;
V_6 -> V_49 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_44:
F_15 ( V_11 ) ;
V_43:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_55 ( struct V_50 * V_51 , struct V_50 * V_52 )
{
struct V_53 * V_54 , * V_55 , * V_56 , * * V_57 ;
struct V_58 * * V_59 , * V_60 ;
int V_61 ;
unsigned long V_62 ;
struct V_63 * V_64 ;
F_56 () ;
F_57 ( & V_52 -> V_65 ) ;
F_58 ( V_52 ) ;
F_59 ( V_52 , V_51 ) ;
F_60 ( & V_51 -> V_65 , V_66 ) ;
V_51 -> V_67 = 0 ;
V_51 -> V_68 = NULL ;
V_51 -> V_69 = NULL ;
V_51 -> V_70 = V_52 -> V_71 ;
V_51 -> V_72 = ~ 0UL ;
V_51 -> V_73 = 0 ;
F_61 ( F_62 ( V_51 ) ) ;
V_51 -> V_74 = V_75 ;
V_59 = & V_51 -> V_74 . V_58 ;
V_60 = NULL ;
V_57 = & V_51 -> V_68 ;
V_61 = F_63 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_76;
V_61 = F_64 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_76;
V_56 = NULL ;
for ( V_54 = V_52 -> V_68 ; V_54 ; V_54 = V_54 -> V_77 ) {
struct V_78 * V_78 ;
if ( V_54 -> V_79 & V_80 ) {
F_65 ( V_51 , V_54 -> V_79 , V_54 -> V_81 ,
- F_66 ( V_54 ) ) ;
continue;
}
V_62 = 0 ;
if ( V_54 -> V_79 & V_82 ) {
unsigned long V_83 = F_66 ( V_54 ) ;
if ( F_67 ( V_52 , V_83 ) )
goto V_84;
V_62 = V_83 ;
}
V_55 = F_68 ( V_85 , V_9 ) ;
if ( ! V_55 )
goto V_84;
* V_55 = * V_54 ;
F_69 ( & V_55 -> V_86 ) ;
V_64 = F_70 ( F_71 ( V_54 ) ) ;
V_61 = F_72 ( V_64 ) ;
if ( F_73 ( V_64 ) )
goto V_87;
F_74 ( V_55 , V_64 ) ;
V_55 -> V_88 = V_51 ;
if ( F_75 ( V_55 , V_54 ) )
goto V_89;
V_55 -> V_79 &= ~ V_90 ;
V_55 -> V_77 = V_55 -> V_91 = NULL ;
V_78 = V_55 -> V_81 ;
if ( V_78 ) {
struct V_92 * V_92 = F_76 ( V_78 ) ;
struct V_93 * V_94 = V_78 -> V_95 ;
F_77 ( V_78 ) ;
if ( V_55 -> V_79 & V_96 )
F_78 ( & V_92 -> V_97 ) ;
F_79 ( & V_94 -> V_98 ) ;
if ( V_55 -> V_79 & V_99 )
V_94 -> V_100 ++ ;
F_80 ( V_94 ) ;
if ( F_81 ( V_55 -> V_79 & V_101 ) )
F_82 ( V_55 ,
& V_94 -> V_102 ) ;
else
F_83 ( V_55 , V_54 ,
& V_94 -> V_103 ) ;
F_84 ( V_94 ) ;
F_85 ( & V_94 -> V_98 ) ;
}
if ( F_86 ( V_55 ) )
F_87 ( V_55 ) ;
* V_57 = V_55 ;
V_57 = & V_55 -> V_77 ;
V_55 -> V_91 = V_56 ;
V_56 = V_55 ;
F_88 ( V_51 , V_55 , V_59 , V_60 ) ;
V_59 = & V_55 -> V_104 . V_105 ;
V_60 = & V_55 -> V_104 ;
V_51 -> V_73 ++ ;
V_61 = F_89 ( V_51 , V_52 , V_54 ) ;
if ( V_55 -> V_106 && V_55 -> V_106 -> V_107 )
V_55 -> V_106 -> V_107 ( V_55 ) ;
if ( V_61 )
goto V_76;
}
F_90 ( V_52 , V_51 ) ;
V_61 = 0 ;
V_76:
F_91 ( & V_51 -> V_65 ) ;
F_92 ( V_52 ) ;
F_91 ( & V_52 -> V_65 ) ;
F_93 () ;
return V_61 ;
V_89:
F_94 ( V_64 ) ;
V_87:
F_10 ( V_85 , V_55 ) ;
V_84:
V_61 = - V_108 ;
F_95 ( V_62 ) ;
goto V_76;
}
static inline int F_96 ( struct V_50 * V_51 )
{
V_51 -> V_109 = F_97 ( V_51 ) ;
if ( F_81 ( ! V_51 -> V_109 ) )
return - V_108 ;
return 0 ;
}
static inline void F_98 ( struct V_50 * V_51 )
{
F_99 ( V_51 , V_51 -> V_109 ) ;
}
static int T_1 F_100 ( char * V_110 )
{
V_111 =
( F_101 ( V_110 , NULL , 0 ) << V_112 ) &
V_113 ;
return 1 ;
}
static void F_102 ( struct V_50 * V_51 )
{
#ifdef F_103
F_104 ( & V_51 -> V_114 ) ;
F_105 ( & V_51 -> V_115 ) ;
#endif
}
static struct V_50 * F_106 ( struct V_50 * V_51 , struct V_5 * V_116 )
{
F_53 ( & V_51 -> V_117 , 1 ) ;
F_53 ( & V_51 -> V_118 , 1 ) ;
F_107 ( & V_51 -> V_65 ) ;
F_69 ( & V_51 -> V_119 ) ;
V_51 -> V_120 = ( V_28 -> V_51 ) ?
( V_28 -> V_51 -> V_120 & V_121 ) : V_111 ;
V_51 -> V_122 = NULL ;
V_51 -> V_123 = 0 ;
memset ( & V_51 -> V_124 , 0 , sizeof( V_51 -> V_124 ) ) ;
F_104 ( & V_51 -> V_125 ) ;
V_51 -> V_70 = V_126 ;
V_51 -> V_72 = ~ 0UL ;
F_102 ( V_51 ) ;
F_108 ( V_51 , V_116 ) ;
if ( F_109 ( ! F_96 ( V_51 ) ) ) {
V_51 -> V_127 = 0 ;
F_110 ( V_51 ) ;
return V_51 ;
}
F_111 ( V_51 ) ;
return NULL ;
}
static void F_112 ( struct V_50 * V_51 )
{
int V_128 ;
for ( V_128 = 0 ; V_128 < V_129 ; V_128 ++ ) {
long V_130 = F_113 ( & V_51 -> V_124 . V_131 [ V_128 ] ) ;
if ( F_81 ( V_130 ) )
F_114 ( V_132 L_3
L_4 , V_51 , V_128 , V_130 ) ;
}
#ifdef F_115
F_116 ( V_51 -> V_133 ) ;
#endif
}
struct V_50 * F_117 ( void )
{
struct V_50 * V_51 ;
V_51 = F_118 () ;
if ( ! V_51 )
return NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
F_119 ( V_51 ) ;
return F_106 ( V_51 , V_28 ) ;
}
void F_120 ( struct V_50 * V_51 )
{
F_19 ( V_51 == & V_134 ) ;
F_98 ( V_51 ) ;
F_121 ( V_51 ) ;
F_122 ( V_51 ) ;
F_112 ( V_51 ) ;
F_111 ( V_51 ) ;
}
void F_123 ( struct V_50 * V_51 )
{
F_124 () ;
if ( F_32 ( & V_51 -> V_117 ) ) {
F_125 ( V_51 ) ;
F_126 ( V_51 ) ;
F_127 ( V_51 ) ;
F_128 ( V_51 ) ;
F_129 ( V_51 ) ;
F_130 ( V_51 , NULL ) ;
if ( ! F_131 ( & V_51 -> V_119 ) ) {
F_132 ( & V_135 ) ;
F_133 ( & V_51 -> V_119 ) ;
F_134 ( & V_135 ) ;
}
if ( V_51 -> V_136 )
F_135 ( V_51 -> V_136 -> V_137 ) ;
F_136 ( V_51 ) ;
}
}
void F_130 ( struct V_50 * V_51 , struct V_78 * V_138 )
{
if ( V_138 )
F_77 ( V_138 ) ;
if ( V_51 -> V_139 )
F_137 ( V_51 -> V_139 ) ;
V_51 -> V_139 = V_138 ;
}
struct V_78 * F_138 ( struct V_50 * V_51 )
{
struct V_78 * V_139 ;
F_139 ( & V_51 -> V_65 ) ;
V_139 = V_51 -> V_139 ;
if ( V_139 )
F_77 ( V_139 ) ;
F_140 ( & V_51 -> V_65 ) ;
return V_139 ;
}
static void F_141 ( struct V_50 * V_52 , struct V_50 * V_140 )
{
V_140 -> V_139 = F_138 ( V_52 ) ;
}
struct V_50 * F_142 ( struct V_5 * V_141 )
{
struct V_50 * V_51 ;
F_143 ( V_141 ) ;
V_51 = V_141 -> V_51 ;
if ( V_51 ) {
if ( V_141 -> V_120 & V_142 )
V_51 = NULL ;
else
F_144 ( & V_51 -> V_117 ) ;
}
F_145 ( V_141 ) ;
return V_51 ;
}
struct V_50 * F_146 ( struct V_5 * V_141 , unsigned int V_143 )
{
struct V_50 * V_51 ;
int V_42 ;
V_42 = F_147 ( & V_141 -> signal -> V_144 ) ;
if ( V_42 )
return F_148 ( V_42 ) ;
V_51 = F_142 ( V_141 ) ;
if ( V_51 && V_51 != V_28 -> V_51 &&
! F_149 ( V_141 , V_143 ) ) {
F_123 ( V_51 ) ;
V_51 = F_148 ( - V_145 ) ;
}
F_85 ( & V_141 -> signal -> V_144 ) ;
return V_51 ;
}
static void F_150 ( struct V_5 * V_6 )
{
struct V_146 * V_147 ;
F_143 ( V_6 ) ;
V_147 = V_6 -> V_148 ;
if ( F_109 ( V_147 ) ) {
V_6 -> V_148 = NULL ;
F_151 ( V_147 ) ;
}
F_145 ( V_6 ) ;
}
static int F_152 ( struct V_5 * V_149 ,
struct V_146 * V_147 )
{
int V_150 ;
F_153 () ;
V_150 = F_154 ( V_147 ) ;
F_155 () ;
if ( V_150 ) {
F_143 ( V_149 ) ;
V_149 -> V_148 = NULL ;
F_145 ( V_149 ) ;
}
F_156 ( V_149 ) ;
return V_150 ;
}
void F_157 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
#ifdef F_158
if ( F_81 ( V_6 -> V_151 ) ) {
F_159 ( V_6 ) ;
V_6 -> V_151 = NULL ;
}
#ifdef F_160
if ( F_81 ( V_6 -> V_152 ) ) {
F_161 ( V_6 ) ;
V_6 -> V_152 = NULL ;
}
#endif
if ( F_81 ( ! F_131 ( & V_6 -> V_153 ) ) )
F_162 ( V_6 ) ;
#endif
F_163 ( V_6 ) ;
F_164 ( V_6 , V_51 ) ;
if ( V_6 -> V_154 ) {
if ( ! ( V_6 -> V_120 & V_155 ) &&
F_35 ( & V_51 -> V_117 ) > 1 ) {
F_165 ( 0 , V_6 -> V_154 ) ;
F_166 ( V_6 -> V_154 , V_156 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_154 = NULL ;
}
if ( V_6 -> V_148 )
F_150 ( V_6 ) ;
}
struct V_50 * F_167 ( struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 = V_28 -> V_51 ;
int V_42 ;
if ( ! V_52 )
return NULL ;
V_51 = F_118 () ;
if ( ! V_51 )
goto V_84;
memcpy ( V_51 , V_52 , sizeof( * V_51 ) ) ;
F_119 ( V_51 ) ;
#ifdef F_115
V_51 -> V_133 = NULL ;
#endif
#ifdef F_168
V_51 -> V_157 = V_158 ;
#endif
if ( ! F_106 ( V_51 , V_6 ) )
goto V_84;
if ( F_169 ( V_6 , V_51 ) )
goto V_159;
F_141 ( V_52 , V_51 ) ;
V_42 = F_55 ( V_51 , V_52 ) ;
if ( V_42 )
goto V_160;
V_51 -> V_161 = F_170 ( V_51 ) ;
V_51 -> V_162 = V_51 -> V_163 ;
if ( V_51 -> V_136 && ! F_171 ( V_51 -> V_136 -> V_137 ) )
goto V_160;
return V_51 ;
V_160:
V_51 -> V_136 = NULL ;
F_123 ( V_51 ) ;
V_84:
return NULL ;
V_159:
F_98 ( V_51 ) ;
F_111 ( V_51 ) ;
return NULL ;
}
static int F_172 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 ;
int V_61 ;
V_6 -> V_165 = V_6 -> V_166 = 0 ;
V_6 -> V_167 = V_6 -> V_168 = 0 ;
#ifdef F_173
V_6 -> V_169 = V_6 -> V_167 + V_6 -> V_168 ;
#endif
V_6 -> V_51 = NULL ;
V_6 -> V_170 = NULL ;
V_52 = V_28 -> V_51 ;
if ( ! V_52 )
return 0 ;
if ( V_164 & V_171 ) {
F_144 ( & V_52 -> V_117 ) ;
V_51 = V_52 ;
goto V_172;
}
V_61 = - V_108 ;
V_51 = F_167 ( V_6 ) ;
if ( ! V_51 )
goto V_84;
V_172:
V_6 -> V_51 = V_51 ;
V_6 -> V_170 = V_51 ;
return 0 ;
V_84:
return V_61 ;
}
static int F_174 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_173 * V_174 = V_28 -> V_174 ;
if ( V_164 & V_175 ) {
F_132 ( & V_174 -> V_176 ) ;
if ( V_174 -> V_177 ) {
F_134 ( & V_174 -> V_176 ) ;
return - V_178 ;
}
V_174 -> V_179 ++ ;
F_134 ( & V_174 -> V_176 ) ;
return 0 ;
}
V_6 -> V_174 = F_175 ( V_174 ) ;
if ( ! V_6 -> V_174 )
return - V_108 ;
return 0 ;
}
static int F_176 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_180 * V_181 , * V_182 ;
int error = 0 ;
V_181 = V_28 -> V_183 ;
if ( ! V_181 )
goto V_76;
if ( V_164 & V_184 ) {
F_144 ( & V_181 -> V_131 ) ;
goto V_76;
}
V_182 = F_177 ( V_181 , & error ) ;
if ( ! V_182 )
goto V_76;
V_6 -> V_183 = V_182 ;
error = 0 ;
V_76:
return error ;
}
static int F_178 ( unsigned long V_164 , struct V_5 * V_6 )
{
#ifdef F_179
struct V_185 * V_186 = V_28 -> V_185 ;
struct V_185 * V_187 ;
if ( ! V_186 )
return 0 ;
if ( V_164 & V_188 ) {
F_180 ( V_186 ) ;
V_6 -> V_185 = V_186 ;
} else if ( F_181 ( V_186 -> V_189 ) ) {
V_187 = F_182 ( V_6 , V_9 , V_190 ) ;
if ( F_81 ( ! V_187 ) )
return - V_108 ;
V_187 -> V_189 = V_186 -> V_189 ;
F_183 ( V_187 ) ;
}
#endif
return 0 ;
}
static int F_184 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_191 * V_23 ;
if ( V_164 & V_192 ) {
F_144 ( & V_28 -> V_193 -> V_131 ) ;
return 0 ;
}
V_23 = F_68 ( V_194 , V_9 ) ;
F_185 ( V_6 -> V_193 , V_23 ) ;
if ( ! V_23 )
return - V_108 ;
F_53 ( & V_23 -> V_131 , 1 ) ;
memcpy ( V_23 -> V_195 , V_28 -> V_193 -> V_195 , sizeof( V_23 -> V_195 ) ) ;
return 0 ;
}
void F_186 ( struct V_191 * V_193 )
{
if ( F_32 ( & V_193 -> V_131 ) ) {
F_187 ( V_193 ) ;
F_10 ( V_194 , V_193 ) ;
}
}
static void F_188 ( struct V_22 * V_23 )
{
unsigned long V_196 ;
F_189 ( V_23 ) ;
V_196 = F_190 ( V_23 -> V_35 [ V_197 ] . V_37 ) ;
if ( V_196 != V_198 ) {
V_23 -> V_199 . V_200 = F_191 ( V_196 ) ;
V_23 -> V_201 . V_202 = 1 ;
}
F_69 ( & V_23 -> V_203 [ 0 ] ) ;
F_69 ( & V_23 -> V_203 [ 1 ] ) ;
F_69 ( & V_23 -> V_203 [ 2 ] ) ;
}
static int F_192 ( unsigned long V_164 , struct V_5 * V_6 )
{
struct V_22 * V_23 ;
if ( V_164 & V_204 )
return 0 ;
V_23 = F_193 ( V_24 , V_9 ) ;
V_6 -> signal = V_23 ;
if ( ! V_23 )
return - V_108 ;
V_23 -> V_205 = 1 ;
F_53 ( & V_23 -> V_206 , 1 ) ;
F_53 ( & V_23 -> V_25 , 1 ) ;
F_194 ( & V_23 -> V_207 ) ;
V_23 -> V_208 = V_6 ;
F_195 ( & V_23 -> V_209 ) ;
F_69 ( & V_23 -> V_210 ) ;
F_196 ( & V_23 -> V_211 , V_212 , V_213 ) ;
V_23 -> V_211 . V_214 = V_215 ;
F_143 ( V_28 -> V_216 ) ;
memcpy ( V_23 -> V_35 , V_28 -> signal -> V_35 , sizeof V_23 -> V_35 ) ;
F_145 ( V_28 -> V_216 ) ;
F_188 ( V_23 ) ;
F_197 ( V_23 ) ;
F_198 ( V_23 ) ;
#ifdef F_199
F_107 ( & V_23 -> V_217 ) ;
#endif
V_23 -> V_218 = V_28 -> signal -> V_218 ;
V_23 -> V_219 = V_28 -> signal -> V_219 ;
V_23 -> V_220 = V_28 -> signal -> V_220 ||
V_28 -> signal -> V_221 ;
F_200 ( & V_23 -> V_144 ) ;
return 0 ;
}
static void F_201 ( unsigned long V_164 , struct V_5 * V_116 )
{
unsigned long V_222 = V_116 -> V_120 ;
V_222 &= ~ ( V_223 | V_224 ) ;
V_222 |= V_225 ;
V_116 -> V_120 = V_222 ;
}
static void F_202 ( struct V_5 * V_116 )
{
F_203 ( & V_116 -> V_226 ) ;
#ifdef F_204
F_205 ( & V_116 -> V_227 ) ;
V_116 -> V_228 = NULL ;
#endif
}
void F_108 ( struct V_50 * V_51 , struct V_5 * V_116 )
{
V_51 -> V_229 = V_116 ;
}
static void F_206 ( struct V_5 * V_6 )
{
V_6 -> V_199 . V_200 = 0 ;
V_6 -> V_199 . V_230 = 0 ;
V_6 -> V_199 . V_231 = 0 ;
F_69 ( & V_6 -> V_203 [ 0 ] ) ;
F_69 ( & V_6 -> V_203 [ 1 ] ) ;
F_69 ( & V_6 -> V_203 [ 2 ] ) ;
}
static struct V_5 * F_207 ( unsigned long V_164 ,
unsigned long V_232 ,
unsigned long V_233 ,
int T_2 * V_234 ,
struct V_235 * V_235 ,
int V_236 )
{
int V_61 ;
struct V_5 * V_116 ;
if ( ( V_164 & ( V_237 | V_175 ) ) == ( V_237 | V_175 ) )
return F_148 ( - V_238 ) ;
if ( ( V_164 & ( V_239 | V_175 ) ) == ( V_239 | V_175 ) )
return F_148 ( - V_238 ) ;
if ( ( V_164 & V_204 ) && ! ( V_164 & V_192 ) )
return F_148 ( - V_238 ) ;
if ( ( V_164 & V_192 ) && ! ( V_164 & V_171 ) )
return F_148 ( - V_238 ) ;
if ( ( V_164 & V_240 ) &&
V_28 -> signal -> V_120 & V_241 )
return F_148 ( - V_238 ) ;
if ( ( V_164 & ( V_171 | V_242 ) ) &&
( F_208 ( V_28 ) != V_28 -> V_243 -> V_244 ) )
return F_148 ( - V_238 ) ;
V_61 = F_209 ( V_164 ) ;
if ( V_61 )
goto V_245;
V_61 = - V_108 ;
V_116 = F_44 ( V_28 ) ;
if ( ! V_116 )
goto V_245;
F_210 ( V_116 ) ;
F_211 ( V_116 ) ;
F_202 ( V_116 ) ;
#ifdef F_212
F_213 ( ! V_116 -> V_246 ) ;
F_213 ( ! V_116 -> V_247 ) ;
#endif
V_61 = - V_178 ;
if ( F_35 ( & V_116 -> V_248 -> V_249 -> V_250 ) >=
F_214 ( V_116 , V_36 ) ) {
if ( ! F_215 ( V_251 ) && ! F_215 ( V_252 ) &&
V_116 -> V_248 -> V_249 != V_253 )
goto V_254;
}
V_28 -> V_120 &= ~ V_255 ;
V_61 = F_216 ( V_116 , V_164 ) ;
if ( V_61 < 0 )
goto V_254;
V_61 = - V_178 ;
if ( V_205 >= V_32 )
goto V_256;
if ( ! F_171 ( F_217 ( V_116 ) -> V_257 -> V_137 ) )
goto V_256;
V_116 -> V_258 = 0 ;
F_218 ( V_116 ) ;
F_201 ( V_164 , V_116 ) ;
F_69 ( & V_116 -> V_259 ) ;
F_69 ( & V_116 -> V_260 ) ;
F_219 ( V_116 ) ;
V_116 -> V_148 = NULL ;
F_104 ( & V_116 -> V_261 ) ;
F_195 ( & V_116 -> V_262 ) ;
V_116 -> V_263 = V_116 -> V_264 = V_116 -> V_265 = 0 ;
V_116 -> V_266 = V_116 -> V_267 = 0 ;
#ifndef F_220
V_116 -> V_268 . V_263 = V_116 -> V_268 . V_264 = 0 ;
#endif
#ifdef F_221
F_222 ( & V_116 -> V_269 ) ;
V_116 -> V_270 = 0 ;
V_116 -> V_271 = V_272 ;
#endif
#if F_223 ( V_273 )
memset ( & V_116 -> V_124 , 0 , sizeof( V_116 -> V_124 ) ) ;
#endif
V_116 -> V_274 = V_28 -> V_275 ;
F_224 ( & V_116 -> V_276 ) ;
F_225 ( V_116 ) ;
F_206 ( V_116 ) ;
F_226 ( & V_116 -> V_277 ) ;
V_116 -> V_278 = V_116 -> V_277 ;
F_227 ( & V_116 -> V_278 ) ;
V_116 -> V_185 = NULL ;
V_116 -> V_279 = NULL ;
if ( V_164 & V_204 )
F_228 ( V_28 ) ;
F_229 ( V_116 ) ;
#ifdef F_230
V_116 -> V_63 = F_70 ( V_116 -> V_63 ) ;
if ( F_73 ( V_116 -> V_63 ) ) {
V_61 = F_72 ( V_116 -> V_63 ) ;
V_116 -> V_63 = NULL ;
goto V_280;
}
F_231 ( V_116 ) ;
#endif
#ifdef F_232
V_116 -> V_281 = V_190 ;
V_116 -> V_282 = V_190 ;
F_233 ( & V_116 -> V_283 ) ;
#endif
#ifdef F_234
V_116 -> V_284 = 0 ;
V_116 -> V_246 = 0 ;
V_116 -> V_285 = 0 ;
V_116 -> V_286 = 0 ;
V_116 -> V_287 = V_288 ;
V_116 -> V_289 = 0 ;
V_116 -> V_247 = 1 ;
V_116 -> V_290 = V_288 ;
V_116 -> V_291 = 0 ;
V_116 -> V_292 = 0 ;
V_116 -> V_293 = 0 ;
V_116 -> V_294 = 0 ;
V_116 -> V_295 = 0 ;
#endif
#ifdef F_235
V_116 -> V_296 = 0 ;
V_116 -> V_297 = 0 ;
V_116 -> V_298 = 0 ;
#endif
#ifdef F_236
V_116 -> V_299 = NULL ;
#endif
#ifdef F_237
V_116 -> V_300 . V_301 = 0 ;
V_116 -> V_300 . V_302 = NULL ;
#endif
F_238 ( V_116 ) ;
V_61 = F_239 ( V_116 ) ;
if ( V_61 )
goto V_303;
V_61 = F_240 ( V_116 ) ;
if ( V_61 )
goto V_303;
V_61 = F_241 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_304;
V_61 = F_176 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_305;
V_61 = F_174 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_306;
V_61 = F_184 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_307;
V_61 = F_192 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_308;
V_61 = F_172 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_309;
V_61 = F_242 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_310;
V_61 = F_178 ( V_164 , V_116 ) ;
if ( V_61 )
goto V_311;
V_61 = F_243 ( V_164 , V_232 , V_233 , V_116 ) ;
if ( V_61 )
goto V_312;
if ( V_235 != & V_313 ) {
V_61 = - V_108 ;
V_235 = F_244 ( V_116 -> V_243 -> V_244 ) ;
if ( ! V_235 )
goto V_312;
}
V_116 -> V_235 = F_245 ( V_235 ) ;
V_116 -> V_314 = V_116 -> V_235 ;
if ( V_164 & V_204 )
V_116 -> V_314 = V_28 -> V_314 ;
V_116 -> V_315 = ( V_164 & V_316 ) ? V_234 : NULL ;
V_116 -> V_154 = ( V_164 & V_317 ) ? V_234 : NULL ;
#ifdef F_179
V_116 -> V_318 = NULL ;
#endif
#ifdef F_158
V_116 -> V_151 = NULL ;
#ifdef F_160
V_116 -> V_152 = NULL ;
#endif
F_69 ( & V_116 -> V_153 ) ;
V_116 -> V_319 = NULL ;
#endif
F_246 ( V_116 ) ;
if ( ( V_164 & ( V_171 | V_320 ) ) == V_171 )
V_116 -> V_321 = V_116 -> V_322 = 0 ;
F_247 ( V_116 ) ;
F_248 ( V_116 , V_323 ) ;
#ifdef F_249
F_248 ( V_116 , F_249 ) ;
#endif
F_250 ( V_116 ) ;
if ( V_164 & V_204 )
V_116 -> V_324 = - 1 ;
else if ( V_164 & V_240 )
V_116 -> V_324 = V_28 -> V_216 -> V_324 ;
else
V_116 -> V_324 = ( V_164 & V_325 ) ;
V_116 -> V_326 = 0 ;
V_116 -> V_26 = 0 ;
V_116 -> V_327 = 0 ;
V_116 -> V_328 = 128 >> ( V_329 - 10 ) ;
V_116 -> V_330 = 0 ;
V_116 -> V_216 = V_116 ;
F_69 ( & V_116 -> V_331 ) ;
V_116 -> V_332 = NULL ;
F_251 ( & V_1 ) ;
if ( V_164 & ( V_240 | V_204 ) ) {
V_116 -> V_333 = V_28 -> V_333 ;
V_116 -> V_334 = V_28 -> V_334 ;
} else {
V_116 -> V_333 = V_28 ;
V_116 -> V_334 = V_28 -> V_335 ;
}
F_132 ( & V_28 -> V_193 -> V_336 ) ;
F_252 () ;
if ( F_253 ( V_28 ) ) {
F_134 ( & V_28 -> V_193 -> V_336 ) ;
F_254 ( & V_1 ) ;
V_61 = - V_337 ;
goto V_338;
}
if ( V_164 & V_204 ) {
V_28 -> signal -> V_205 ++ ;
F_144 ( & V_28 -> signal -> V_206 ) ;
F_144 ( & V_28 -> signal -> V_25 ) ;
V_116 -> V_216 = V_28 -> V_216 ;
F_255 ( & V_116 -> V_331 , & V_116 -> V_216 -> V_331 ) ;
}
if ( F_109 ( V_116 -> V_235 ) ) {
F_256 ( V_116 , ( V_164 & V_339 ) || V_236 ) ;
if ( F_257 ( V_116 ) ) {
if ( F_258 ( V_235 ) ) {
F_259 ( V_235 ) -> V_340 = V_116 ;
V_116 -> signal -> V_120 |= V_241 ;
}
V_116 -> signal -> V_341 = V_235 ;
V_116 -> signal -> V_342 = F_260 ( V_28 -> signal -> V_342 ) ;
F_261 ( V_116 , V_343 , F_262 ( V_28 ) ) ;
F_261 ( V_116 , V_344 , F_263 ( V_28 ) ) ;
F_264 ( & V_116 -> V_260 , & V_116 -> V_333 -> V_259 ) ;
F_255 ( & V_116 -> V_345 , & V_34 . V_345 ) ;
F_265 ( V_4 ) ;
}
F_261 ( V_116 , V_346 , V_235 ) ;
V_205 ++ ;
}
V_347 ++ ;
F_134 ( & V_28 -> V_193 -> V_336 ) ;
F_254 ( & V_1 ) ;
F_266 ( V_116 ) ;
F_267 ( V_116 ) ;
if ( V_164 & V_204 )
F_268 ( V_28 ) ;
F_269 ( V_116 ) ;
F_270 ( V_116 , V_164 ) ;
return V_116 ;
V_338:
if ( V_235 != & V_313 )
F_271 ( V_235 ) ;
V_312:
if ( V_116 -> V_185 )
F_272 ( V_116 ) ;
V_311:
F_273 ( V_116 ) ;
V_310:
if ( V_116 -> V_51 )
F_123 ( V_116 -> V_51 ) ;
V_309:
if ( ! ( V_164 & V_204 ) )
F_28 ( V_116 -> signal ) ;
V_308:
F_186 ( V_116 -> V_193 ) ;
V_307:
F_274 ( V_116 ) ;
V_306:
F_275 ( V_116 ) ;
V_305:
F_276 ( V_116 ) ;
V_304:
F_277 ( V_116 ) ;
V_303:
F_278 ( V_116 ) ;
#ifdef F_230
F_94 ( V_116 -> V_63 ) ;
V_280:
#endif
if ( V_164 & V_204 )
F_268 ( V_28 ) ;
F_279 ( V_116 , 0 ) ;
F_38 ( V_116 ) ;
F_135 ( F_217 ( V_116 ) -> V_257 -> V_137 ) ;
V_256:
F_78 ( & V_116 -> V_348 -> V_249 -> V_250 ) ;
F_37 ( V_116 ) ;
V_254:
F_24 ( V_116 ) ;
V_245:
return F_148 ( V_61 ) ;
}
static inline void F_280 ( struct V_349 * V_350 )
{
enum V_351 type ;
for ( type = V_346 ; type < V_352 ; ++ type ) {
F_281 ( & V_350 [ type ] . V_7 ) ;
V_350 [ type ] . V_235 = & V_313 ;
}
}
struct V_5 * T_3 F_282 ( int V_2 )
{
struct V_5 * V_141 ;
V_141 = F_207 ( V_171 , 0 , 0 , NULL , & V_313 , 0 ) ;
if ( ! F_73 ( V_141 ) ) {
F_280 ( V_141 -> V_353 ) ;
F_283 ( V_141 , V_2 ) ;
}
return V_141 ;
}
long F_284 ( unsigned long V_164 ,
unsigned long V_232 ,
unsigned long V_233 ,
int T_2 * V_354 ,
int T_2 * V_234 )
{
struct V_5 * V_116 ;
int V_236 = 0 ;
long V_355 ;
if ( V_164 & ( V_239 | V_242 ) ) {
if ( V_164 & ( V_204 | V_240 ) )
return - V_238 ;
}
if ( ! ( V_164 & V_356 ) ) {
if ( V_164 & V_320 )
V_236 = V_357 ;
else if ( ( V_164 & V_325 ) != V_358 )
V_236 = V_359 ;
else
V_236 = V_360 ;
if ( F_109 ( ! F_285 ( V_28 , V_236 ) ) )
V_236 = 0 ;
}
V_116 = F_207 ( V_164 , V_232 , V_233 ,
V_234 , NULL , V_236 ) ;
if ( ! F_73 ( V_116 ) ) {
struct V_146 V_147 ;
F_286 ( V_28 , V_116 ) ;
V_355 = F_287 ( V_116 ) ;
if ( V_164 & V_361 )
F_165 ( V_355 , V_354 ) ;
if ( V_164 & V_320 ) {
V_116 -> V_148 = & V_147 ;
F_288 ( & V_147 ) ;
F_289 ( V_116 ) ;
}
F_290 ( V_116 ) ;
if ( F_81 ( V_236 ) )
F_291 ( V_236 , V_355 ) ;
if ( V_164 & V_320 ) {
if ( ! F_152 ( V_116 , & V_147 ) )
F_291 ( V_362 , V_355 ) ;
}
} else {
V_355 = F_72 ( V_116 ) ;
}
return V_355 ;
}
T_4 F_292 ( int (* F_293)( void * ) , void * V_363 , unsigned long V_120 )
{
return F_284 ( V_120 | V_171 | V_356 , ( unsigned long ) F_293 ,
( unsigned long ) V_363 , NULL , NULL ) ;
}
static void F_294 ( void * V_364 )
{
struct V_191 * V_193 = V_364 ;
F_104 ( & V_193 -> V_336 ) ;
F_194 ( & V_193 -> V_365 ) ;
}
void T_1 F_295 ( void )
{
V_194 = F_18 ( L_5 ,
sizeof( struct V_191 ) , 0 ,
V_366 | V_30 | V_367 |
V_31 , F_294 ) ;
V_24 = F_18 ( L_6 ,
sizeof( struct V_22 ) , 0 ,
V_366 | V_30 | V_31 , NULL ) ;
V_368 = F_18 ( L_7 ,
sizeof( struct V_180 ) , 0 ,
V_366 | V_30 | V_31 , NULL ) ;
V_369 = F_18 ( L_8 ,
sizeof( struct V_173 ) , 0 ,
V_366 | V_30 | V_31 , NULL ) ;
V_370 = F_18 ( L_9 ,
sizeof( struct V_50 ) , V_371 ,
V_366 | V_30 | V_31 , NULL ) ;
V_85 = F_296 ( V_53 , V_30 ) ;
F_297 () ;
F_298 () ;
}
static int F_299 ( unsigned long V_372 )
{
if ( V_372 & ~ ( V_204 | V_175 | V_237 | V_192 |
V_171 | V_184 | V_373 |
V_374 | V_375 | V_376 |
V_239 | V_242 ) )
return - V_238 ;
if ( V_372 & ( V_204 | V_192 | V_171 ) ) {
if ( F_35 ( & V_28 -> V_51 -> V_117 ) > 1 )
return - V_238 ;
}
return 0 ;
}
static int F_300 ( unsigned long V_372 , struct V_173 * * V_377 )
{
struct V_173 * V_174 = V_28 -> V_174 ;
if ( ! ( V_372 & V_175 ) || ! V_174 )
return 0 ;
if ( V_174 -> V_179 == 1 )
return 0 ;
* V_377 = F_175 ( V_174 ) ;
if ( ! * V_377 )
return - V_108 ;
return 0 ;
}
static int F_301 ( unsigned long V_372 , struct V_180 * * V_378 )
{
struct V_180 * V_379 = V_28 -> V_183 ;
int error = 0 ;
if ( ( V_372 & V_184 ) &&
( V_379 && F_35 ( & V_379 -> V_131 ) > 1 ) ) {
* V_378 = F_177 ( V_379 , & error ) ;
if ( ! * V_378 )
return error ;
}
return 0 ;
}
int F_302 ( struct V_180 * * V_380 )
{
struct V_5 * V_141 = V_28 ;
struct V_180 * V_381 = NULL ;
int error ;
error = F_301 ( V_184 , & V_381 ) ;
if ( error || ! V_381 ) {
* V_380 = NULL ;
return error ;
}
* V_380 = V_141 -> V_183 ;
F_143 ( V_141 ) ;
V_141 -> V_183 = V_381 ;
F_145 ( V_141 ) ;
return 0 ;
}
