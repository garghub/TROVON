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
V_51 -> V_70 = 0 ;
F_61 ( F_62 ( V_51 ) ) ;
V_51 -> V_71 = V_72 ;
V_59 = & V_51 -> V_71 . V_58 ;
V_60 = NULL ;
V_57 = & V_51 -> V_68 ;
V_61 = F_63 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_73;
V_61 = F_64 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_73;
V_56 = NULL ;
for ( V_54 = V_52 -> V_68 ; V_54 ; V_54 = V_54 -> V_74 ) {
struct V_75 * V_75 ;
if ( V_54 -> V_76 & V_77 ) {
F_65 ( V_51 , V_54 -> V_76 , V_54 -> V_78 ,
- F_66 ( V_54 ) ) ;
continue;
}
V_62 = 0 ;
if ( V_54 -> V_76 & V_79 ) {
unsigned long V_80 = F_66 ( V_54 ) ;
if ( F_67 ( V_52 , V_80 ) )
goto V_81;
V_62 = V_80 ;
}
V_55 = F_68 ( V_82 , V_9 ) ;
if ( ! V_55 )
goto V_81;
* V_55 = * V_54 ;
F_69 ( & V_55 -> V_83 ) ;
V_64 = F_70 ( F_71 ( V_54 ) ) ;
V_61 = F_72 ( V_64 ) ;
if ( F_73 ( V_64 ) )
goto V_84;
F_74 ( V_55 , V_64 ) ;
V_55 -> V_85 = V_51 ;
if ( F_75 ( V_55 , V_54 ) )
goto V_86;
V_55 -> V_76 &= ~ V_87 ;
V_55 -> V_74 = V_55 -> V_88 = NULL ;
V_75 = V_55 -> V_78 ;
if ( V_75 ) {
struct V_89 * V_89 = F_76 ( V_75 ) ;
struct V_90 * V_91 = V_75 -> V_92 ;
F_77 ( V_75 ) ;
if ( V_55 -> V_76 & V_93 )
F_78 ( & V_89 -> V_94 ) ;
F_79 ( & V_91 -> V_95 ) ;
if ( V_55 -> V_76 & V_96 )
V_91 -> V_97 ++ ;
F_80 ( V_91 ) ;
if ( F_81 ( V_55 -> V_76 & V_98 ) )
F_82 ( V_55 ,
& V_91 -> V_99 ) ;
else
F_83 ( V_55 , V_54 ,
& V_91 -> V_100 ) ;
F_84 ( V_91 ) ;
F_85 ( & V_91 -> V_95 ) ;
}
if ( F_86 ( V_55 ) )
F_87 ( V_55 ) ;
* V_57 = V_55 ;
V_57 = & V_55 -> V_74 ;
V_55 -> V_88 = V_56 ;
V_56 = V_55 ;
F_88 ( V_51 , V_55 , V_59 , V_60 ) ;
V_59 = & V_55 -> V_101 . V_102 ;
V_60 = & V_55 -> V_101 ;
V_51 -> V_70 ++ ;
V_61 = F_89 ( V_51 , V_52 , V_54 ) ;
if ( V_55 -> V_103 && V_55 -> V_103 -> V_104 )
V_55 -> V_103 -> V_104 ( V_55 ) ;
if ( V_61 )
goto V_73;
}
F_90 ( V_52 , V_51 ) ;
V_61 = 0 ;
V_73:
F_91 ( & V_51 -> V_65 ) ;
F_92 ( V_52 ) ;
F_91 ( & V_52 -> V_65 ) ;
F_93 () ;
return V_61 ;
V_86:
F_94 ( V_64 ) ;
V_84:
F_10 ( V_82 , V_55 ) ;
V_81:
V_61 = - V_105 ;
F_95 ( V_62 ) ;
goto V_73;
}
static inline int F_96 ( struct V_50 * V_51 )
{
V_51 -> V_106 = F_97 ( V_51 ) ;
if ( F_81 ( ! V_51 -> V_106 ) )
return - V_105 ;
return 0 ;
}
static inline void F_98 ( struct V_50 * V_51 )
{
F_99 ( V_51 , V_51 -> V_106 ) ;
}
static int T_1 F_100 ( char * V_107 )
{
V_108 =
( F_101 ( V_107 , NULL , 0 ) << V_109 ) &
V_110 ;
return 1 ;
}
static void F_102 ( struct V_50 * V_51 )
{
#ifdef F_103
F_104 ( & V_51 -> V_111 ) ;
F_105 ( & V_51 -> V_112 ) ;
#endif
}
static struct V_50 * F_106 ( struct V_50 * V_51 , struct V_5 * V_113 )
{
F_53 ( & V_51 -> V_114 , 1 ) ;
F_53 ( & V_51 -> V_115 , 1 ) ;
F_107 ( & V_51 -> V_65 ) ;
F_69 ( & V_51 -> V_116 ) ;
V_51 -> V_117 = ( V_28 -> V_51 ) ?
( V_28 -> V_51 -> V_117 & V_118 ) : V_108 ;
V_51 -> V_119 = NULL ;
V_51 -> V_120 = 0 ;
memset ( & V_51 -> V_121 , 0 , sizeof( V_51 -> V_121 ) ) ;
F_104 ( & V_51 -> V_122 ) ;
F_102 ( V_51 ) ;
F_108 ( V_51 , V_113 ) ;
if ( F_109 ( ! F_96 ( V_51 ) ) ) {
V_51 -> V_123 = 0 ;
F_110 ( V_51 ) ;
return V_51 ;
}
F_111 ( V_51 ) ;
return NULL ;
}
static void F_112 ( struct V_50 * V_51 )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_125 ; V_124 ++ ) {
long V_126 = F_113 ( & V_51 -> V_121 . V_127 [ V_124 ] ) ;
if ( F_81 ( V_126 ) )
F_114 ( V_128 L_3
L_4 , V_51 , V_124 , V_126 ) ;
}
#ifdef F_115
F_116 ( V_51 -> V_129 ) ;
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
F_19 ( V_51 == & V_130 ) ;
F_98 ( V_51 ) ;
F_121 ( V_51 ) ;
F_122 ( V_51 ) ;
F_112 ( V_51 ) ;
F_111 ( V_51 ) ;
}
void F_123 ( struct V_50 * V_51 )
{
F_124 () ;
if ( F_32 ( & V_51 -> V_114 ) ) {
F_125 ( V_51 ) ;
F_126 ( V_51 ) ;
F_127 ( V_51 ) ;
F_128 ( V_51 ) ;
F_129 ( V_51 ) ;
F_130 ( V_51 , NULL ) ;
if ( ! F_131 ( & V_51 -> V_116 ) ) {
F_132 ( & V_131 ) ;
F_133 ( & V_51 -> V_116 ) ;
F_134 ( & V_131 ) ;
}
if ( V_51 -> V_132 )
F_135 ( V_51 -> V_132 -> V_133 ) ;
F_136 ( V_51 ) ;
}
}
void F_130 ( struct V_50 * V_51 , struct V_75 * V_134 )
{
if ( V_134 )
F_77 ( V_134 ) ;
if ( V_51 -> V_135 )
F_137 ( V_51 -> V_135 ) ;
V_51 -> V_135 = V_134 ;
}
struct V_75 * F_138 ( struct V_50 * V_51 )
{
struct V_75 * V_135 ;
F_139 ( & V_51 -> V_65 ) ;
V_135 = V_51 -> V_135 ;
if ( V_135 )
F_77 ( V_135 ) ;
F_140 ( & V_51 -> V_65 ) ;
return V_135 ;
}
static void F_141 ( struct V_50 * V_52 , struct V_50 * V_136 )
{
V_136 -> V_135 = F_138 ( V_52 ) ;
}
struct V_50 * F_142 ( struct V_5 * V_137 )
{
struct V_50 * V_51 ;
F_143 ( V_137 ) ;
V_51 = V_137 -> V_51 ;
if ( V_51 ) {
if ( V_137 -> V_117 & V_138 )
V_51 = NULL ;
else
F_144 ( & V_51 -> V_114 ) ;
}
F_145 ( V_137 ) ;
return V_51 ;
}
struct V_50 * F_146 ( struct V_5 * V_137 , unsigned int V_139 )
{
struct V_50 * V_51 ;
int V_42 ;
V_42 = F_147 ( & V_137 -> signal -> V_140 ) ;
if ( V_42 )
return F_148 ( V_42 ) ;
V_51 = F_142 ( V_137 ) ;
if ( V_51 && V_51 != V_28 -> V_51 &&
! F_149 ( V_137 , V_139 ) ) {
F_123 ( V_51 ) ;
V_51 = F_148 ( - V_141 ) ;
}
F_85 ( & V_137 -> signal -> V_140 ) ;
return V_51 ;
}
static void F_150 ( struct V_5 * V_6 )
{
struct V_142 * V_143 ;
F_143 ( V_6 ) ;
V_143 = V_6 -> V_144 ;
if ( F_109 ( V_143 ) ) {
V_6 -> V_144 = NULL ;
F_151 ( V_143 ) ;
}
F_145 ( V_6 ) ;
}
static int F_152 ( struct V_5 * V_145 ,
struct V_142 * V_143 )
{
int V_146 ;
F_153 () ;
V_146 = F_154 ( V_143 ) ;
F_155 () ;
if ( V_146 ) {
F_143 ( V_145 ) ;
V_145 -> V_144 = NULL ;
F_145 ( V_145 ) ;
}
F_156 ( V_145 ) ;
return V_146 ;
}
void F_157 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
#ifdef F_158
if ( F_81 ( V_6 -> V_147 ) ) {
F_159 ( V_6 ) ;
V_6 -> V_147 = NULL ;
}
#ifdef F_160
if ( F_81 ( V_6 -> V_148 ) ) {
F_161 ( V_6 ) ;
V_6 -> V_148 = NULL ;
}
#endif
if ( F_81 ( ! F_131 ( & V_6 -> V_149 ) ) )
F_162 ( V_6 ) ;
#endif
F_163 ( V_6 ) ;
F_164 ( V_6 , V_51 ) ;
if ( V_6 -> V_150 ) {
if ( ! ( V_6 -> V_117 & V_151 ) &&
F_35 ( & V_51 -> V_114 ) > 1 ) {
F_165 ( 0 , V_6 -> V_150 ) ;
F_166 ( V_6 -> V_150 , V_152 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_150 = NULL ;
}
if ( V_6 -> V_144 )
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
goto V_81;
memcpy ( V_51 , V_52 , sizeof( * V_51 ) ) ;
F_119 ( V_51 ) ;
#ifdef F_115
V_51 -> V_129 = NULL ;
#endif
#ifdef F_168
V_51 -> V_153 = V_154 ;
#endif
if ( ! F_106 ( V_51 , V_6 ) )
goto V_81;
if ( F_169 ( V_6 , V_51 ) )
goto V_155;
F_141 ( V_52 , V_51 ) ;
V_42 = F_55 ( V_51 , V_52 ) ;
if ( V_42 )
goto V_156;
V_51 -> V_157 = F_170 ( V_51 ) ;
V_51 -> V_158 = V_51 -> V_159 ;
if ( V_51 -> V_132 && ! F_171 ( V_51 -> V_132 -> V_133 ) )
goto V_156;
return V_51 ;
V_156:
V_51 -> V_132 = NULL ;
F_123 ( V_51 ) ;
V_81:
return NULL ;
V_155:
F_98 ( V_51 ) ;
F_111 ( V_51 ) ;
return NULL ;
}
static int F_172 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 ;
int V_61 ;
V_6 -> V_161 = V_6 -> V_162 = 0 ;
V_6 -> V_163 = V_6 -> V_164 = 0 ;
#ifdef F_173
V_6 -> V_165 = V_6 -> V_163 + V_6 -> V_164 ;
#endif
V_6 -> V_51 = NULL ;
V_6 -> V_166 = NULL ;
V_52 = V_28 -> V_51 ;
if ( ! V_52 )
return 0 ;
if ( V_160 & V_167 ) {
F_144 ( & V_52 -> V_114 ) ;
V_51 = V_52 ;
goto V_168;
}
V_61 = - V_105 ;
V_51 = F_167 ( V_6 ) ;
if ( ! V_51 )
goto V_81;
V_168:
V_6 -> V_51 = V_51 ;
V_6 -> V_166 = V_51 ;
return 0 ;
V_81:
return V_61 ;
}
static int F_174 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_169 * V_170 = V_28 -> V_170 ;
if ( V_160 & V_171 ) {
F_132 ( & V_170 -> V_172 ) ;
if ( V_170 -> V_173 ) {
F_134 ( & V_170 -> V_172 ) ;
return - V_174 ;
}
V_170 -> V_175 ++ ;
F_134 ( & V_170 -> V_172 ) ;
return 0 ;
}
V_6 -> V_170 = F_175 ( V_170 ) ;
if ( ! V_6 -> V_170 )
return - V_105 ;
return 0 ;
}
static int F_176 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_176 * V_177 , * V_178 ;
int error = 0 ;
V_177 = V_28 -> V_179 ;
if ( ! V_177 )
goto V_73;
if ( V_160 & V_180 ) {
F_144 ( & V_177 -> V_127 ) ;
goto V_73;
}
V_178 = F_177 ( V_177 , & error ) ;
if ( ! V_178 )
goto V_73;
V_6 -> V_179 = V_178 ;
error = 0 ;
V_73:
return error ;
}
static int F_178 ( unsigned long V_160 , struct V_5 * V_6 )
{
#ifdef F_179
struct V_181 * V_182 = V_28 -> V_181 ;
struct V_181 * V_183 ;
if ( ! V_182 )
return 0 ;
if ( V_160 & V_184 ) {
F_180 ( V_182 ) ;
V_6 -> V_181 = V_182 ;
} else if ( F_181 ( V_182 -> V_185 ) ) {
V_183 = F_182 ( V_6 , V_9 , V_186 ) ;
if ( F_81 ( ! V_183 ) )
return - V_105 ;
V_183 -> V_185 = V_182 -> V_185 ;
F_183 ( V_183 ) ;
}
#endif
return 0 ;
}
static int F_184 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_187 * V_23 ;
if ( V_160 & V_188 ) {
F_144 ( & V_28 -> V_189 -> V_127 ) ;
return 0 ;
}
V_23 = F_68 ( V_190 , V_9 ) ;
F_185 ( V_6 -> V_189 , V_23 ) ;
if ( ! V_23 )
return - V_105 ;
F_53 ( & V_23 -> V_127 , 1 ) ;
memcpy ( V_23 -> V_191 , V_28 -> V_189 -> V_191 , sizeof( V_23 -> V_191 ) ) ;
return 0 ;
}
void F_186 ( struct V_187 * V_189 )
{
if ( F_32 ( & V_189 -> V_127 ) ) {
F_187 ( V_189 ) ;
F_10 ( V_190 , V_189 ) ;
}
}
static void F_188 ( struct V_22 * V_23 )
{
unsigned long V_192 ;
F_189 ( V_23 ) ;
V_192 = F_190 ( V_23 -> V_35 [ V_193 ] . V_37 ) ;
if ( V_192 != V_194 ) {
V_23 -> V_195 . V_196 = F_191 ( V_192 ) ;
V_23 -> V_197 . V_198 = 1 ;
}
F_69 ( & V_23 -> V_199 [ 0 ] ) ;
F_69 ( & V_23 -> V_199 [ 1 ] ) ;
F_69 ( & V_23 -> V_199 [ 2 ] ) ;
}
static int F_192 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_22 * V_23 ;
if ( V_160 & V_200 )
return 0 ;
V_23 = F_193 ( V_24 , V_9 ) ;
V_6 -> signal = V_23 ;
if ( ! V_23 )
return - V_105 ;
V_23 -> V_201 = 1 ;
F_53 ( & V_23 -> V_202 , 1 ) ;
F_53 ( & V_23 -> V_25 , 1 ) ;
F_194 ( & V_23 -> V_203 ) ;
V_23 -> V_204 = V_6 ;
F_195 ( & V_23 -> V_205 ) ;
F_69 ( & V_23 -> V_206 ) ;
F_196 ( & V_23 -> V_207 , V_208 , V_209 ) ;
V_23 -> V_207 . V_210 = V_211 ;
F_143 ( V_28 -> V_212 ) ;
memcpy ( V_23 -> V_35 , V_28 -> signal -> V_35 , sizeof V_23 -> V_35 ) ;
F_145 ( V_28 -> V_212 ) ;
F_188 ( V_23 ) ;
F_197 ( V_23 ) ;
F_198 ( V_23 ) ;
#ifdef F_199
F_107 ( & V_23 -> V_213 ) ;
#endif
V_23 -> V_214 = V_28 -> signal -> V_214 ;
V_23 -> V_215 = V_28 -> signal -> V_215 ;
V_23 -> V_216 = V_28 -> signal -> V_216 ||
V_28 -> signal -> V_217 ;
F_200 ( & V_23 -> V_140 ) ;
return 0 ;
}
static void F_201 ( unsigned long V_160 , struct V_5 * V_113 )
{
unsigned long V_218 = V_113 -> V_117 ;
V_218 &= ~ ( V_219 | V_220 ) ;
V_218 |= V_221 ;
V_113 -> V_117 = V_218 ;
}
static void F_202 ( struct V_5 * V_113 )
{
F_203 ( & V_113 -> V_222 ) ;
#ifdef F_204
F_205 ( & V_113 -> V_223 ) ;
V_113 -> V_224 = NULL ;
#endif
}
void F_108 ( struct V_50 * V_51 , struct V_5 * V_113 )
{
V_51 -> V_225 = V_113 ;
}
static void F_206 ( struct V_5 * V_6 )
{
V_6 -> V_195 . V_196 = 0 ;
V_6 -> V_195 . V_226 = 0 ;
V_6 -> V_195 . V_227 = 0 ;
F_69 ( & V_6 -> V_199 [ 0 ] ) ;
F_69 ( & V_6 -> V_199 [ 1 ] ) ;
F_69 ( & V_6 -> V_199 [ 2 ] ) ;
}
static inline void
F_207 ( struct V_5 * V_137 , enum V_228 type , struct V_229 * V_229 )
{
V_137 -> V_230 [ type ] . V_229 = V_229 ;
}
static struct V_5 * F_208 ( unsigned long V_160 ,
unsigned long V_231 ,
unsigned long V_232 ,
int T_2 * V_233 ,
struct V_229 * V_229 ,
int V_234 )
{
int V_61 ;
struct V_5 * V_113 ;
if ( ( V_160 & ( V_235 | V_171 ) ) == ( V_235 | V_171 ) )
return F_148 ( - V_236 ) ;
if ( ( V_160 & ( V_237 | V_171 ) ) == ( V_237 | V_171 ) )
return F_148 ( - V_236 ) ;
if ( ( V_160 & V_200 ) && ! ( V_160 & V_188 ) )
return F_148 ( - V_236 ) ;
if ( ( V_160 & V_188 ) && ! ( V_160 & V_167 ) )
return F_148 ( - V_236 ) ;
if ( ( V_160 & V_238 ) &&
V_28 -> signal -> V_117 & V_239 )
return F_148 ( - V_236 ) ;
if ( ( V_160 & ( V_167 | V_240 ) ) &&
( F_209 ( V_28 ) !=
V_28 -> V_241 -> V_242 ) )
return F_148 ( - V_236 ) ;
V_61 = F_210 ( V_160 ) ;
if ( V_61 )
goto V_243;
V_61 = - V_105 ;
V_113 = F_44 ( V_28 ) ;
if ( ! V_113 )
goto V_243;
F_211 ( V_113 ) ;
F_212 ( V_113 ) ;
F_202 ( V_113 ) ;
#ifdef F_213
F_214 ( ! V_113 -> V_244 ) ;
F_214 ( ! V_113 -> V_245 ) ;
#endif
V_61 = - V_174 ;
if ( F_35 ( & V_113 -> V_246 -> V_247 -> V_248 ) >=
F_215 ( V_113 , V_36 ) ) {
if ( V_113 -> V_246 -> V_247 != V_249 &&
! F_216 ( V_250 ) && ! F_216 ( V_251 ) )
goto V_252;
}
V_28 -> V_117 &= ~ V_253 ;
V_61 = F_217 ( V_113 , V_160 ) ;
if ( V_61 < 0 )
goto V_252;
V_61 = - V_174 ;
if ( V_201 >= V_32 )
goto V_254;
if ( ! F_171 ( F_218 ( V_113 ) -> V_255 -> V_133 ) )
goto V_254;
V_113 -> V_256 = 0 ;
F_219 ( V_113 ) ;
F_201 ( V_160 , V_113 ) ;
F_69 ( & V_113 -> V_257 ) ;
F_69 ( & V_113 -> V_258 ) ;
F_220 ( V_113 ) ;
V_113 -> V_144 = NULL ;
F_104 ( & V_113 -> V_259 ) ;
F_195 ( & V_113 -> V_260 ) ;
V_113 -> V_261 = V_113 -> V_262 = V_113 -> V_263 = 0 ;
V_113 -> V_264 = V_113 -> V_265 = 0 ;
#ifndef F_221
V_113 -> V_266 . V_261 = V_113 -> V_266 . V_262 = 0 ;
#endif
#ifdef F_222
F_223 ( & V_113 -> V_267 ) ;
V_113 -> V_268 = 0 ;
V_113 -> V_269 = V_270 ;
#endif
#if F_224 ( V_271 )
memset ( & V_113 -> V_121 , 0 , sizeof( V_113 -> V_121 ) ) ;
#endif
V_113 -> V_272 = V_28 -> V_273 ;
F_225 ( & V_113 -> V_274 ) ;
F_226 ( V_113 ) ;
F_206 ( V_113 ) ;
F_227 ( & V_113 -> V_275 ) ;
V_113 -> V_276 = V_113 -> V_275 ;
F_228 ( & V_113 -> V_276 ) ;
V_113 -> V_181 = NULL ;
V_113 -> V_277 = NULL ;
if ( V_160 & V_200 )
F_229 ( V_28 ) ;
F_230 ( V_113 ) ;
#ifdef F_231
V_113 -> V_63 = F_70 ( V_113 -> V_63 ) ;
if ( F_73 ( V_113 -> V_63 ) ) {
V_61 = F_72 ( V_113 -> V_63 ) ;
V_113 -> V_63 = NULL ;
goto V_278;
}
F_232 ( V_113 ) ;
#endif
#ifdef F_233
V_113 -> V_279 = V_186 ;
V_113 -> V_280 = V_186 ;
F_234 ( & V_113 -> V_281 ) ;
#endif
#ifdef F_235
V_113 -> V_282 = 0 ;
V_113 -> V_244 = 0 ;
V_113 -> V_283 = 0 ;
V_113 -> V_284 = 0 ;
V_113 -> V_285 = V_286 ;
V_113 -> V_287 = 0 ;
V_113 -> V_245 = 1 ;
V_113 -> V_288 = V_286 ;
V_113 -> V_289 = 0 ;
V_113 -> V_290 = 0 ;
V_113 -> V_291 = 0 ;
V_113 -> V_292 = 0 ;
V_113 -> V_293 = 0 ;
#endif
#ifdef F_236
V_113 -> V_294 = 0 ;
V_113 -> V_295 = 0 ;
V_113 -> V_296 = 0 ;
#endif
#ifdef F_237
V_113 -> V_297 = NULL ;
#endif
#ifdef F_238
V_113 -> V_298 . V_299 = 0 ;
V_113 -> V_298 . V_300 = NULL ;
#endif
#ifdef F_239
V_113 -> V_301 = 0 ;
V_113 -> V_302 = 0 ;
#endif
F_240 ( V_113 ) ;
V_61 = F_241 ( V_113 ) ;
if ( V_61 )
goto V_303;
V_61 = F_242 ( V_113 ) ;
if ( V_61 )
goto V_303;
V_61 = F_243 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_304;
V_61 = F_176 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_305;
V_61 = F_174 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_306;
V_61 = F_184 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_307;
V_61 = F_192 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_308;
V_61 = F_172 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_309;
V_61 = F_244 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_310;
V_61 = F_178 ( V_160 , V_113 ) ;
if ( V_61 )
goto V_311;
V_61 = F_245 ( V_160 , V_231 , V_232 , V_113 ) ;
if ( V_61 )
goto V_312;
if ( V_229 != & V_313 ) {
V_61 = - V_105 ;
V_229 = F_246 ( V_113 -> V_241 -> V_242 ) ;
if ( ! V_229 )
goto V_312;
}
V_113 -> V_314 = ( V_160 & V_315 ) ? V_233 : NULL ;
V_113 -> V_150 = ( V_160 & V_316 ) ? V_233 : NULL ;
#ifdef F_179
V_113 -> V_317 = NULL ;
#endif
#ifdef F_158
V_113 -> V_147 = NULL ;
#ifdef F_160
V_113 -> V_148 = NULL ;
#endif
F_69 ( & V_113 -> V_149 ) ;
V_113 -> V_318 = NULL ;
#endif
F_247 ( V_113 ) ;
if ( ( V_160 & ( V_167 | V_319 ) ) == V_167 )
V_113 -> V_320 = V_113 -> V_321 = 0 ;
F_248 ( V_113 ) ;
F_249 ( V_113 , V_322 ) ;
#ifdef F_250
F_249 ( V_113 , F_250 ) ;
#endif
F_251 ( V_113 ) ;
V_113 -> V_229 = F_252 ( V_229 ) ;
if ( V_160 & V_200 ) {
V_113 -> V_323 = - 1 ;
V_113 -> V_212 = V_28 -> V_212 ;
V_113 -> V_324 = V_28 -> V_324 ;
} else {
if ( V_160 & V_238 )
V_113 -> V_323 = V_28 -> V_212 -> V_323 ;
else
V_113 -> V_323 = ( V_160 & V_325 ) ;
V_113 -> V_212 = V_113 ;
V_113 -> V_324 = V_113 -> V_229 ;
}
V_113 -> V_326 = 0 ;
V_113 -> V_26 = 0 ;
V_113 -> V_327 = 0 ;
V_113 -> V_328 = 128 >> ( V_329 - 10 ) ;
V_113 -> V_330 = 0 ;
F_69 ( & V_113 -> V_331 ) ;
V_113 -> V_332 = NULL ;
F_253 ( & V_1 ) ;
if ( V_160 & ( V_238 | V_200 ) ) {
V_113 -> V_333 = V_28 -> V_333 ;
V_113 -> V_334 = V_28 -> V_334 ;
} else {
V_113 -> V_333 = V_28 ;
V_113 -> V_334 = V_28 -> V_335 ;
}
F_132 ( & V_28 -> V_189 -> V_336 ) ;
F_254 () ;
if ( F_255 ( V_28 ) ) {
F_134 ( & V_28 -> V_189 -> V_336 ) ;
F_256 ( & V_1 ) ;
V_61 = - V_337 ;
goto V_338;
}
if ( F_109 ( V_113 -> V_229 ) ) {
F_257 ( V_113 , ( V_160 & V_339 ) || V_234 ) ;
F_207 ( V_113 , V_340 , V_229 ) ;
if ( F_258 ( V_113 ) ) {
F_207 ( V_113 , V_341 , F_259 ( V_28 ) ) ;
F_207 ( V_113 , V_342 , F_260 ( V_28 ) ) ;
if ( F_261 ( V_229 ) ) {
F_262 ( V_229 ) -> V_343 = V_113 ;
V_113 -> signal -> V_117 |= V_239 ;
}
V_113 -> signal -> V_344 = V_229 ;
V_113 -> signal -> V_345 = F_263 ( V_28 -> signal -> V_345 ) ;
F_264 ( & V_113 -> V_258 , & V_113 -> V_333 -> V_257 ) ;
F_265 ( & V_113 -> V_346 , & V_34 . V_346 ) ;
F_266 ( V_113 , V_341 ) ;
F_266 ( V_113 , V_342 ) ;
F_267 ( V_4 ) ;
} else {
V_28 -> signal -> V_201 ++ ;
F_144 ( & V_28 -> signal -> V_202 ) ;
F_144 ( & V_28 -> signal -> V_25 ) ;
F_265 ( & V_113 -> V_331 ,
& V_113 -> V_212 -> V_331 ) ;
}
F_266 ( V_113 , V_340 ) ;
V_201 ++ ;
}
V_347 ++ ;
F_134 ( & V_28 -> V_189 -> V_336 ) ;
F_256 ( & V_1 ) ;
F_268 ( V_113 ) ;
F_269 ( V_113 ) ;
if ( V_160 & V_200 )
F_270 ( V_28 ) ;
F_271 ( V_113 ) ;
F_272 ( V_113 , V_160 ) ;
return V_113 ;
V_338:
if ( V_229 != & V_313 )
F_273 ( V_229 ) ;
V_312:
if ( V_113 -> V_181 )
F_274 ( V_113 ) ;
V_311:
F_275 ( V_113 ) ;
V_310:
if ( V_113 -> V_51 )
F_123 ( V_113 -> V_51 ) ;
V_309:
if ( ! ( V_160 & V_200 ) )
F_28 ( V_113 -> signal ) ;
V_308:
F_186 ( V_113 -> V_189 ) ;
V_307:
F_276 ( V_113 ) ;
V_306:
F_277 ( V_113 ) ;
V_305:
F_278 ( V_113 ) ;
V_304:
F_279 ( V_113 ) ;
V_303:
F_280 ( V_113 ) ;
#ifdef F_231
F_94 ( V_113 -> V_63 ) ;
V_278:
#endif
if ( V_160 & V_200 )
F_270 ( V_28 ) ;
F_281 ( V_113 , 0 ) ;
F_38 ( V_113 ) ;
F_135 ( F_218 ( V_113 ) -> V_255 -> V_133 ) ;
V_254:
F_78 ( & V_113 -> V_348 -> V_247 -> V_248 ) ;
F_37 ( V_113 ) ;
V_252:
F_24 ( V_113 ) ;
V_243:
return F_148 ( V_61 ) ;
}
static inline void F_282 ( struct V_349 * V_350 )
{
enum V_228 type ;
for ( type = V_340 ; type < V_351 ; ++ type ) {
F_283 ( & V_350 [ type ] . V_7 ) ;
V_350 [ type ] . V_229 = & V_313 ;
}
}
struct V_5 * F_284 ( int V_2 )
{
struct V_5 * V_137 ;
V_137 = F_208 ( V_167 , 0 , 0 , NULL , & V_313 , 0 ) ;
if ( ! F_73 ( V_137 ) ) {
F_282 ( V_137 -> V_230 ) ;
F_285 ( V_137 , V_2 ) ;
}
return V_137 ;
}
long F_286 ( unsigned long V_160 ,
unsigned long V_231 ,
unsigned long V_232 ,
int T_2 * V_352 ,
int T_2 * V_233 )
{
struct V_5 * V_113 ;
int V_234 = 0 ;
long V_353 ;
if ( V_160 & ( V_237 | V_240 ) ) {
if ( V_160 & ( V_200 | V_238 ) )
return - V_236 ;
}
if ( ! ( V_160 & V_354 ) ) {
if ( V_160 & V_319 )
V_234 = V_355 ;
else if ( ( V_160 & V_325 ) != V_356 )
V_234 = V_357 ;
else
V_234 = V_358 ;
if ( F_109 ( ! F_287 ( V_28 , V_234 ) ) )
V_234 = 0 ;
}
V_113 = F_208 ( V_160 , V_231 , V_232 ,
V_233 , NULL , V_234 ) ;
if ( ! F_73 ( V_113 ) ) {
struct V_142 V_143 ;
F_288 ( V_28 , V_113 ) ;
V_353 = F_289 ( V_113 ) ;
if ( V_160 & V_359 )
F_165 ( V_353 , V_352 ) ;
if ( V_160 & V_319 ) {
V_113 -> V_144 = & V_143 ;
F_290 ( & V_143 ) ;
F_291 ( V_113 ) ;
}
F_292 ( V_113 ) ;
if ( F_81 ( V_234 ) )
F_293 ( V_234 , V_353 ) ;
if ( V_160 & V_319 ) {
if ( ! F_152 ( V_113 , & V_143 ) )
F_293 ( V_360 , V_353 ) ;
}
} else {
V_353 = F_72 ( V_113 ) ;
}
return V_353 ;
}
T_3 F_294 ( int (* F_295)( void * ) , void * V_361 , unsigned long V_117 )
{
return F_286 ( V_117 | V_167 | V_354 , ( unsigned long ) F_295 ,
( unsigned long ) V_361 , NULL , NULL ) ;
}
static void F_296 ( void * V_362 )
{
struct V_187 * V_189 = V_362 ;
F_104 ( & V_189 -> V_336 ) ;
F_194 ( & V_189 -> V_363 ) ;
}
void T_1 F_297 ( void )
{
V_190 = F_18 ( L_5 ,
sizeof( struct V_187 ) , 0 ,
V_364 | V_30 | V_365 |
V_31 , F_296 ) ;
V_24 = F_18 ( L_6 ,
sizeof( struct V_22 ) , 0 ,
V_364 | V_30 | V_31 , NULL ) ;
V_366 = F_18 ( L_7 ,
sizeof( struct V_176 ) , 0 ,
V_364 | V_30 | V_31 , NULL ) ;
V_367 = F_18 ( L_8 ,
sizeof( struct V_169 ) , 0 ,
V_364 | V_30 | V_31 , NULL ) ;
V_368 = F_18 ( L_9 ,
sizeof( struct V_50 ) , V_369 ,
V_364 | V_30 | V_31 , NULL ) ;
V_82 = F_298 ( V_53 , V_30 ) ;
F_299 () ;
F_300 () ;
}
static int F_301 ( unsigned long V_370 )
{
if ( V_370 & ~ ( V_200 | V_171 | V_235 | V_188 |
V_167 | V_180 | V_371 |
V_372 | V_373 | V_374 |
V_237 | V_240 ) )
return - V_236 ;
if ( V_370 & ( V_200 | V_188 | V_167 ) ) {
if ( F_35 ( & V_28 -> V_51 -> V_114 ) > 1 )
return - V_236 ;
}
return 0 ;
}
static int F_302 ( unsigned long V_370 , struct V_169 * * V_375 )
{
struct V_169 * V_170 = V_28 -> V_170 ;
if ( ! ( V_370 & V_171 ) || ! V_170 )
return 0 ;
if ( V_170 -> V_175 == 1 )
return 0 ;
* V_375 = F_175 ( V_170 ) ;
if ( ! * V_375 )
return - V_105 ;
return 0 ;
}
static int F_303 ( unsigned long V_370 , struct V_176 * * V_376 )
{
struct V_176 * V_377 = V_28 -> V_179 ;
int error = 0 ;
if ( ( V_370 & V_180 ) &&
( V_377 && F_35 ( & V_377 -> V_127 ) > 1 ) ) {
* V_376 = F_177 ( V_377 , & error ) ;
if ( ! * V_376 )
return error ;
}
return 0 ;
}
int F_304 ( struct V_176 * * V_378 )
{
struct V_5 * V_137 = V_28 ;
struct V_176 * V_379 = NULL ;
int error ;
error = F_303 ( V_180 , & V_379 ) ;
if ( error || ! V_379 ) {
* V_378 = NULL ;
return error ;
}
* V_378 = V_137 -> V_179 ;
F_143 ( V_137 ) ;
V_137 -> V_179 = V_379 ;
F_145 ( V_137 ) ;
return 0 ;
}
