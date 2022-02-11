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
F_56 () ;
F_57 ( & V_52 -> V_63 ) ;
F_58 ( V_52 ) ;
F_59 ( V_52 , V_51 ) ;
F_60 ( & V_51 -> V_63 , V_64 ) ;
V_51 -> V_65 = 0 ;
V_51 -> V_66 = NULL ;
V_51 -> V_67 = NULL ;
V_51 -> V_68 = 0 ;
F_61 ( F_62 ( V_51 ) ) ;
V_51 -> V_69 = V_70 ;
V_59 = & V_51 -> V_69 . V_58 ;
V_60 = NULL ;
V_57 = & V_51 -> V_66 ;
V_61 = F_63 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_71;
V_61 = F_64 ( V_51 , V_52 ) ;
if ( V_61 )
goto V_71;
V_56 = NULL ;
for ( V_54 = V_52 -> V_66 ; V_54 ; V_54 = V_54 -> V_72 ) {
struct V_73 * V_73 ;
if ( V_54 -> V_74 & V_75 ) {
F_65 ( V_51 , V_54 -> V_74 , V_54 -> V_76 ,
- F_66 ( V_54 ) ) ;
continue;
}
V_62 = 0 ;
if ( V_54 -> V_74 & V_77 ) {
unsigned long V_78 = F_66 ( V_54 ) ;
if ( F_67 ( V_52 , V_78 ) )
goto V_79;
V_62 = V_78 ;
}
V_55 = F_68 ( V_80 , V_9 ) ;
if ( ! V_55 )
goto V_79;
* V_55 = * V_54 ;
F_69 ( & V_55 -> V_81 ) ;
V_61 = F_70 ( V_54 , V_55 ) ;
if ( V_61 )
goto V_82;
V_55 -> V_83 = V_51 ;
if ( F_71 ( V_55 , V_54 ) )
goto V_84;
V_55 -> V_74 &= ~ V_85 ;
V_55 -> V_72 = V_55 -> V_86 = NULL ;
V_73 = V_55 -> V_76 ;
if ( V_73 ) {
struct V_87 * V_87 = F_72 ( V_73 ) ;
struct V_88 * V_89 = V_73 -> V_90 ;
F_73 ( V_73 ) ;
if ( V_55 -> V_74 & V_91 )
F_74 ( & V_87 -> V_92 ) ;
F_75 ( & V_89 -> V_93 ) ;
if ( V_55 -> V_74 & V_94 )
V_89 -> V_95 ++ ;
F_76 ( V_89 ) ;
if ( F_77 ( V_55 -> V_74 & V_96 ) )
F_78 ( V_55 ,
& V_89 -> V_97 ) ;
else
F_79 ( V_55 , V_54 ,
& V_89 -> V_98 ) ;
F_80 ( V_89 ) ;
F_81 ( & V_89 -> V_93 ) ;
}
if ( F_82 ( V_55 ) )
F_83 ( V_55 ) ;
* V_57 = V_55 ;
V_57 = & V_55 -> V_72 ;
V_55 -> V_86 = V_56 ;
V_56 = V_55 ;
F_84 ( V_51 , V_55 , V_59 , V_60 ) ;
V_59 = & V_55 -> V_99 . V_100 ;
V_60 = & V_55 -> V_99 ;
V_51 -> V_68 ++ ;
V_61 = F_85 ( V_51 , V_52 , V_54 ) ;
if ( V_55 -> V_101 && V_55 -> V_101 -> V_102 )
V_55 -> V_101 -> V_102 ( V_55 ) ;
if ( V_61 )
goto V_71;
}
F_86 ( V_52 , V_51 ) ;
V_61 = 0 ;
V_71:
F_87 ( & V_51 -> V_63 ) ;
F_88 ( V_52 ) ;
F_87 ( & V_52 -> V_63 ) ;
F_89 () ;
return V_61 ;
V_84:
F_90 ( F_91 ( V_55 ) ) ;
V_82:
F_10 ( V_80 , V_55 ) ;
V_79:
V_61 = - V_103 ;
F_92 ( V_62 ) ;
goto V_71;
}
static inline int F_93 ( struct V_50 * V_51 )
{
V_51 -> V_104 = F_94 ( V_51 ) ;
if ( F_77 ( ! V_51 -> V_104 ) )
return - V_103 ;
return 0 ;
}
static inline void F_95 ( struct V_50 * V_51 )
{
F_96 ( V_51 , V_51 -> V_104 ) ;
}
static int T_1 F_97 ( char * V_105 )
{
V_106 =
( F_98 ( V_105 , NULL , 0 ) << V_107 ) &
V_108 ;
return 1 ;
}
static void F_99 ( struct V_50 * V_51 )
{
#ifdef F_100
F_101 ( & V_51 -> V_109 ) ;
V_51 -> V_110 = NULL ;
#endif
}
static struct V_50 * F_102 ( struct V_50 * V_51 , struct V_5 * V_111 )
{
F_53 ( & V_51 -> V_112 , 1 ) ;
F_53 ( & V_51 -> V_113 , 1 ) ;
F_103 ( & V_51 -> V_63 ) ;
F_69 ( & V_51 -> V_114 ) ;
V_51 -> V_115 = ( V_28 -> V_51 ) ?
( V_28 -> V_51 -> V_115 & V_116 ) : V_106 ;
V_51 -> V_117 = NULL ;
F_104 ( & V_51 -> V_118 , 0 ) ;
memset ( & V_51 -> V_119 , 0 , sizeof( V_51 -> V_119 ) ) ;
F_101 ( & V_51 -> V_120 ) ;
F_99 ( V_51 ) ;
F_105 ( V_51 , V_111 ) ;
F_106 ( V_51 ) ;
if ( F_107 ( ! F_93 ( V_51 ) ) ) {
V_51 -> V_121 = 0 ;
F_108 ( V_51 ) ;
return V_51 ;
}
F_109 ( V_51 ) ;
return NULL ;
}
static void F_110 ( struct V_50 * V_51 )
{
int V_122 ;
for ( V_122 = 0 ; V_122 < V_123 ; V_122 ++ ) {
long V_124 = F_111 ( & V_51 -> V_119 . V_125 [ V_122 ] ) ;
if ( F_77 ( V_124 ) )
F_112 ( V_126 L_3
L_4 , V_51 , V_122 , V_124 ) ;
}
#if F_113 ( V_127 ) && ! V_128
F_114 ( V_51 -> V_129 ) ;
#endif
}
struct V_50 * F_115 ( void )
{
struct V_50 * V_51 ;
V_51 = F_116 () ;
if ( ! V_51 )
return NULL ;
memset ( V_51 , 0 , sizeof( * V_51 ) ) ;
F_117 ( V_51 ) ;
return F_102 ( V_51 , V_28 ) ;
}
void F_118 ( struct V_50 * V_51 )
{
F_19 ( V_51 == & V_130 ) ;
F_95 ( V_51 ) ;
F_119 ( V_51 ) ;
F_120 ( V_51 ) ;
F_110 ( V_51 ) ;
F_109 ( V_51 ) ;
}
void F_121 ( struct V_50 * V_51 )
{
F_122 () ;
if ( F_32 ( & V_51 -> V_112 ) ) {
F_123 ( V_51 ) ;
F_124 ( V_51 ) ;
F_125 ( V_51 ) ;
F_126 ( V_51 ) ;
F_127 ( V_51 ) ;
F_128 ( V_51 , NULL ) ;
if ( ! F_129 ( & V_51 -> V_114 ) ) {
F_130 ( & V_131 ) ;
F_131 ( & V_51 -> V_114 ) ;
F_132 ( & V_131 ) ;
}
if ( V_51 -> V_132 )
F_133 ( V_51 -> V_132 -> V_133 ) ;
F_134 ( V_51 ) ;
}
}
void F_128 ( struct V_50 * V_51 , struct V_73 * V_134 )
{
if ( V_134 )
F_73 ( V_134 ) ;
if ( V_51 -> V_135 )
F_135 ( V_51 -> V_135 ) ;
V_51 -> V_135 = V_134 ;
}
struct V_73 * F_136 ( struct V_50 * V_51 )
{
struct V_73 * V_135 ;
F_137 ( & V_51 -> V_63 ) ;
V_135 = V_51 -> V_135 ;
if ( V_135 )
F_73 ( V_135 ) ;
F_138 ( & V_51 -> V_63 ) ;
return V_135 ;
}
static void F_139 ( struct V_50 * V_52 , struct V_50 * V_136 )
{
V_136 -> V_135 = F_136 ( V_52 ) ;
}
struct V_50 * F_140 ( struct V_5 * V_137 )
{
struct V_50 * V_51 ;
F_141 ( V_137 ) ;
V_51 = V_137 -> V_51 ;
if ( V_51 ) {
if ( V_137 -> V_115 & V_138 )
V_51 = NULL ;
else
F_142 ( & V_51 -> V_112 ) ;
}
F_143 ( V_137 ) ;
return V_51 ;
}
struct V_50 * F_144 ( struct V_5 * V_137 , unsigned int V_139 )
{
struct V_50 * V_51 ;
int V_42 ;
V_42 = F_145 ( & V_137 -> signal -> V_140 ) ;
if ( V_42 )
return F_146 ( V_42 ) ;
V_51 = F_140 ( V_137 ) ;
if ( V_51 && V_51 != V_28 -> V_51 &&
! F_147 ( V_137 , V_139 ) ) {
F_121 ( V_51 ) ;
V_51 = F_146 ( - V_141 ) ;
}
F_81 ( & V_137 -> signal -> V_140 ) ;
return V_51 ;
}
static void F_148 ( struct V_5 * V_6 )
{
struct V_142 * V_143 ;
F_141 ( V_6 ) ;
V_143 = V_6 -> V_144 ;
if ( F_107 ( V_143 ) ) {
V_6 -> V_144 = NULL ;
F_149 ( V_143 ) ;
}
F_143 ( V_6 ) ;
}
static int F_150 ( struct V_5 * V_145 ,
struct V_142 * V_143 )
{
int V_146 ;
F_151 () ;
V_146 = F_152 ( V_143 ) ;
F_153 () ;
if ( V_146 ) {
F_141 ( V_145 ) ;
V_145 -> V_144 = NULL ;
F_143 ( V_145 ) ;
}
F_154 ( V_145 ) ;
return V_146 ;
}
void F_155 ( struct V_5 * V_6 , struct V_50 * V_51 )
{
#ifdef F_156
if ( F_77 ( V_6 -> V_147 ) ) {
F_157 ( V_6 ) ;
V_6 -> V_147 = NULL ;
}
#ifdef F_158
if ( F_77 ( V_6 -> V_148 ) ) {
F_159 ( V_6 ) ;
V_6 -> V_148 = NULL ;
}
#endif
if ( F_77 ( ! F_129 ( & V_6 -> V_149 ) ) )
F_160 ( V_6 ) ;
#endif
F_161 ( V_6 ) ;
F_162 ( V_6 , V_51 ) ;
if ( V_6 -> V_150 ) {
if ( ! ( V_6 -> V_115 & V_151 ) &&
F_35 ( & V_51 -> V_112 ) > 1 ) {
F_163 ( 0 , V_6 -> V_150 ) ;
F_164 ( V_6 -> V_150 , V_152 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_150 = NULL ;
}
if ( V_6 -> V_144 )
F_148 ( V_6 ) ;
}
static struct V_50 * F_165 ( struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 = V_28 -> V_51 ;
int V_42 ;
V_51 = F_116 () ;
if ( ! V_51 )
goto V_79;
memcpy ( V_51 , V_52 , sizeof( * V_51 ) ) ;
F_117 ( V_51 ) ;
#if F_113 ( V_127 ) && ! V_128
V_51 -> V_129 = NULL ;
#endif
if ( ! F_102 ( V_51 , V_6 ) )
goto V_79;
if ( F_166 ( V_6 , V_51 ) )
goto V_153;
F_139 ( V_52 , V_51 ) ;
V_42 = F_55 ( V_51 , V_52 ) ;
if ( V_42 )
goto V_154;
V_51 -> V_155 = F_167 ( V_51 ) ;
V_51 -> V_156 = V_51 -> V_157 ;
if ( V_51 -> V_132 && ! F_168 ( V_51 -> V_132 -> V_133 ) )
goto V_154;
return V_51 ;
V_154:
V_51 -> V_132 = NULL ;
F_121 ( V_51 ) ;
V_79:
return NULL ;
V_153:
F_95 ( V_51 ) ;
F_109 ( V_51 ) ;
return NULL ;
}
static int F_169 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_50 * V_51 , * V_52 ;
int V_61 ;
V_6 -> V_159 = V_6 -> V_160 = 0 ;
V_6 -> V_161 = V_6 -> V_162 = 0 ;
#ifdef F_170
V_6 -> V_163 = V_6 -> V_161 + V_6 -> V_162 ;
#endif
V_6 -> V_51 = NULL ;
V_6 -> V_164 = NULL ;
V_52 = V_28 -> V_51 ;
if ( ! V_52 )
return 0 ;
if ( V_158 & V_165 ) {
F_142 ( & V_52 -> V_112 ) ;
V_51 = V_52 ;
goto V_166;
}
V_61 = - V_103 ;
V_51 = F_165 ( V_6 ) ;
if ( ! V_51 )
goto V_79;
V_166:
V_6 -> V_51 = V_51 ;
V_6 -> V_164 = V_51 ;
return 0 ;
V_79:
return V_61 ;
}
static int F_171 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_167 * V_168 = V_28 -> V_168 ;
if ( V_158 & V_169 ) {
F_130 ( & V_168 -> V_170 ) ;
if ( V_168 -> V_171 ) {
F_132 ( & V_168 -> V_170 ) ;
return - V_172 ;
}
V_168 -> V_173 ++ ;
F_132 ( & V_168 -> V_170 ) ;
return 0 ;
}
V_6 -> V_168 = F_172 ( V_168 ) ;
if ( ! V_6 -> V_168 )
return - V_103 ;
return 0 ;
}
static int F_173 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_174 * V_175 , * V_176 ;
int error = 0 ;
V_175 = V_28 -> V_177 ;
if ( ! V_175 )
goto V_71;
if ( V_158 & V_178 ) {
F_142 ( & V_175 -> V_125 ) ;
goto V_71;
}
V_176 = F_174 ( V_175 , & error ) ;
if ( ! V_176 )
goto V_71;
V_6 -> V_177 = V_176 ;
error = 0 ;
V_71:
return error ;
}
static int F_175 ( unsigned long V_158 , struct V_5 * V_6 )
{
#ifdef F_176
struct V_179 * V_180 = V_28 -> V_179 ;
struct V_179 * V_181 ;
if ( ! V_180 )
return 0 ;
if ( V_158 & V_182 ) {
F_177 ( V_180 ) ;
V_6 -> V_179 = V_180 ;
} else if ( F_178 ( V_180 -> V_183 ) ) {
V_181 = F_179 ( V_6 , V_9 , V_184 ) ;
if ( F_77 ( ! V_181 ) )
return - V_103 ;
V_181 -> V_183 = V_180 -> V_183 ;
F_180 ( V_181 ) ;
}
#endif
return 0 ;
}
static int F_181 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_185 * V_23 ;
if ( V_158 & V_186 ) {
F_142 ( & V_28 -> V_187 -> V_125 ) ;
return 0 ;
}
V_23 = F_68 ( V_188 , V_9 ) ;
F_182 ( V_6 -> V_187 , V_23 ) ;
if ( ! V_23 )
return - V_103 ;
F_53 ( & V_23 -> V_125 , 1 ) ;
memcpy ( V_23 -> V_189 , V_28 -> V_187 -> V_189 , sizeof( V_23 -> V_189 ) ) ;
return 0 ;
}
void F_183 ( struct V_185 * V_187 )
{
if ( F_32 ( & V_187 -> V_125 ) ) {
F_184 ( V_187 ) ;
F_10 ( V_188 , V_187 ) ;
}
}
static void F_185 ( struct V_22 * V_23 )
{
unsigned long V_190 ;
F_186 ( V_23 ) ;
V_190 = F_187 ( V_23 -> V_35 [ V_191 ] . V_37 ) ;
if ( V_190 != V_192 ) {
V_23 -> V_193 . V_194 = F_188 ( V_190 ) ;
V_23 -> V_195 . V_196 = 1 ;
}
F_69 ( & V_23 -> V_197 [ 0 ] ) ;
F_69 ( & V_23 -> V_197 [ 1 ] ) ;
F_69 ( & V_23 -> V_197 [ 2 ] ) ;
}
static int F_189 ( unsigned long V_158 , struct V_5 * V_6 )
{
struct V_22 * V_23 ;
if ( V_158 & V_198 )
return 0 ;
V_23 = F_190 ( V_24 , V_9 ) ;
V_6 -> signal = V_23 ;
if ( ! V_23 )
return - V_103 ;
V_23 -> V_199 = 1 ;
F_53 ( & V_23 -> V_200 , 1 ) ;
F_53 ( & V_23 -> V_25 , 1 ) ;
V_23 -> V_201 = (struct V_202 ) F_191 ( V_6 -> V_203 ) ;
V_6 -> V_203 = (struct V_202 ) F_191 ( V_23 -> V_201 ) ;
F_192 ( & V_23 -> V_204 ) ;
V_23 -> V_205 = V_6 ;
F_193 ( & V_23 -> V_206 ) ;
F_69 ( & V_23 -> V_207 ) ;
F_194 ( & V_23 -> V_208 , V_209 , V_210 ) ;
V_23 -> V_208 . V_211 = V_212 ;
F_141 ( V_28 -> V_213 ) ;
memcpy ( V_23 -> V_35 , V_28 -> signal -> V_35 , sizeof V_23 -> V_35 ) ;
F_143 ( V_28 -> V_213 ) ;
F_185 ( V_23 ) ;
F_195 ( V_23 ) ;
F_196 ( V_23 ) ;
#ifdef F_197
F_103 ( & V_23 -> V_214 ) ;
#endif
V_23 -> V_215 = V_28 -> signal -> V_215 ;
V_23 -> V_216 = V_28 -> signal -> V_216 ;
V_23 -> V_217 = V_28 -> signal -> V_217 ||
V_28 -> signal -> V_218 ;
F_198 ( & V_23 -> V_140 ) ;
return 0 ;
}
static void F_199 ( unsigned long V_158 , struct V_5 * V_111 )
{
unsigned long V_219 = V_111 -> V_115 ;
V_219 &= ~ ( V_220 | V_221 ) ;
V_219 |= V_222 ;
V_111 -> V_115 = V_219 ;
}
static void F_200 ( struct V_5 * V_111 )
{
F_201 ( & V_111 -> V_223 ) ;
#ifdef F_202
V_111 -> V_224 = V_70 ;
V_111 -> V_225 = NULL ;
V_111 -> V_226 = NULL ;
V_111 -> V_227 = NULL ;
#endif
}
void F_105 ( struct V_50 * V_51 , struct V_5 * V_111 )
{
V_51 -> V_228 = V_111 ;
}
static void F_203 ( struct V_5 * V_6 )
{
V_6 -> V_193 . V_194 = 0 ;
V_6 -> V_193 . V_229 = 0 ;
V_6 -> V_193 . V_230 = 0 ;
F_69 ( & V_6 -> V_197 [ 0 ] ) ;
F_69 ( & V_6 -> V_197 [ 1 ] ) ;
F_69 ( & V_6 -> V_197 [ 2 ] ) ;
}
static inline void
F_204 ( struct V_5 * V_137 , enum V_231 type , struct V_232 * V_232 )
{
V_137 -> V_233 [ type ] . V_232 = V_232 ;
}
static struct V_5 * F_205 ( unsigned long V_158 ,
unsigned long V_234 ,
unsigned long V_235 ,
int T_2 * V_236 ,
struct V_232 * V_232 ,
int V_237 )
{
int V_61 ;
struct V_5 * V_111 ;
if ( ( V_158 & ( V_238 | V_169 ) ) == ( V_238 | V_169 ) )
return F_146 ( - V_239 ) ;
if ( ( V_158 & ( V_240 | V_169 ) ) == ( V_240 | V_169 ) )
return F_146 ( - V_239 ) ;
if ( ( V_158 & V_198 ) && ! ( V_158 & V_186 ) )
return F_146 ( - V_239 ) ;
if ( ( V_158 & V_186 ) && ! ( V_158 & V_165 ) )
return F_146 ( - V_239 ) ;
if ( ( V_158 & V_241 ) &&
V_28 -> signal -> V_115 & V_242 )
return F_146 ( - V_239 ) ;
if ( V_158 & V_186 ) {
if ( ( V_158 & ( V_240 | V_243 ) ) ||
( F_206 ( V_28 ) !=
V_28 -> V_244 -> V_245 ) )
return F_146 ( - V_239 ) ;
}
V_61 = F_207 ( V_158 ) ;
if ( V_61 )
goto V_246;
V_61 = - V_103 ;
V_111 = F_44 ( V_28 ) ;
if ( ! V_111 )
goto V_246;
F_208 ( V_111 ) ;
F_209 ( V_111 ) ;
F_200 ( V_111 ) ;
#ifdef F_210
F_211 ( ! V_111 -> V_247 ) ;
F_211 ( ! V_111 -> V_248 ) ;
#endif
V_61 = - V_172 ;
if ( F_35 ( & V_111 -> V_249 -> V_250 -> V_251 ) >=
F_212 ( V_111 , V_36 ) ) {
if ( V_111 -> V_249 -> V_250 != V_252 &&
! F_213 ( V_253 ) && ! F_213 ( V_254 ) )
goto V_255;
}
V_28 -> V_115 &= ~ V_256 ;
V_61 = F_214 ( V_111 , V_158 ) ;
if ( V_61 < 0 )
goto V_255;
V_61 = - V_172 ;
if ( V_199 >= V_32 )
goto V_257;
if ( ! F_168 ( F_215 ( V_111 ) -> V_258 -> V_133 ) )
goto V_257;
F_216 ( V_111 ) ;
F_199 ( V_158 , V_111 ) ;
F_69 ( & V_111 -> V_259 ) ;
F_69 ( & V_111 -> V_260 ) ;
F_217 ( V_111 ) ;
V_111 -> V_144 = NULL ;
F_101 ( & V_111 -> V_261 ) ;
F_193 ( & V_111 -> V_262 ) ;
V_111 -> V_263 = V_111 -> V_264 = V_111 -> V_265 = 0 ;
V_111 -> V_266 = V_111 -> V_267 = 0 ;
#ifndef F_218
V_111 -> V_268 . V_263 = V_111 -> V_268 . V_264 = 0 ;
#endif
#ifdef F_219
F_220 ( & V_111 -> V_269 ) ;
V_111 -> V_270 = 0 ;
V_111 -> V_271 = V_272 ;
#endif
#if F_113 ( V_273 )
memset ( & V_111 -> V_119 , 0 , sizeof( V_111 -> V_119 ) ) ;
#endif
V_111 -> V_274 = V_28 -> V_275 ;
F_221 ( & V_111 -> V_276 ) ;
F_222 ( V_111 ) ;
F_203 ( V_111 ) ;
F_223 ( & V_111 -> V_277 ) ;
V_111 -> V_278 = V_111 -> V_277 ;
F_224 ( & V_111 -> V_278 ) ;
V_111 -> V_179 = NULL ;
V_111 -> V_279 = NULL ;
if ( V_158 & V_198 )
F_225 ( V_28 ) ;
F_226 ( V_111 ) ;
#ifdef F_227
V_111 -> V_280 = F_228 ( V_111 -> V_280 ) ;
if ( F_229 ( V_111 -> V_280 ) ) {
V_61 = F_230 ( V_111 -> V_280 ) ;
V_111 -> V_280 = NULL ;
goto V_281;
}
F_231 ( V_111 ) ;
#endif
#ifdef F_232
V_111 -> V_282 = V_184 ;
V_111 -> V_283 = V_184 ;
F_233 ( & V_111 -> V_284 ) ;
#endif
#ifdef F_234
V_111 -> V_285 = 0 ;
V_111 -> V_247 = 0 ;
V_111 -> V_286 = 0 ;
V_111 -> V_287 = 0 ;
V_111 -> V_288 = V_289 ;
V_111 -> V_290 = 0 ;
V_111 -> V_248 = 1 ;
V_111 -> V_291 = V_289 ;
V_111 -> V_292 = 0 ;
V_111 -> V_293 = 0 ;
V_111 -> V_294 = 0 ;
V_111 -> V_295 = 0 ;
V_111 -> V_296 = 0 ;
#endif
#ifdef F_235
V_111 -> V_297 = 0 ;
V_111 -> V_298 = 0 ;
V_111 -> V_299 = 0 ;
#endif
#ifdef F_236
V_111 -> V_300 = NULL ;
#endif
#ifdef F_237
V_111 -> V_301 . V_302 = 0 ;
V_111 -> V_301 . V_303 = NULL ;
#endif
#ifdef F_238
V_111 -> V_304 = 0 ;
V_111 -> V_305 = 0 ;
#endif
V_61 = F_239 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_306;
V_61 = F_240 ( V_111 ) ;
if ( V_61 )
goto V_306;
V_61 = F_241 ( V_111 ) ;
if ( V_61 )
goto V_306;
V_61 = F_242 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_307;
V_61 = F_173 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_308;
V_61 = F_171 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_309;
V_61 = F_181 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_310;
V_61 = F_189 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_311;
V_61 = F_169 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_312;
V_61 = F_243 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_313;
V_61 = F_175 ( V_158 , V_111 ) ;
if ( V_61 )
goto V_314;
V_61 = F_244 ( V_158 , V_234 , V_235 , V_111 ) ;
if ( V_61 )
goto V_315;
if ( V_232 != & V_316 ) {
V_61 = - V_103 ;
V_232 = F_245 ( V_111 -> V_244 -> V_245 ) ;
if ( ! V_232 )
goto V_315;
}
V_111 -> V_317 = ( V_158 & V_318 ) ? V_236 : NULL ;
V_111 -> V_150 = ( V_158 & V_319 ) ? V_236 : NULL ;
#ifdef F_176
V_111 -> V_320 = NULL ;
#endif
#ifdef F_156
V_111 -> V_147 = NULL ;
#ifdef F_158
V_111 -> V_148 = NULL ;
#endif
F_69 ( & V_111 -> V_149 ) ;
V_111 -> V_321 = NULL ;
#endif
if ( ( V_158 & ( V_165 | V_322 ) ) == V_165 )
V_111 -> V_323 = V_111 -> V_324 = 0 ;
F_246 ( V_111 ) ;
F_247 ( V_111 , V_325 ) ;
#ifdef F_248
F_247 ( V_111 , F_248 ) ;
#endif
F_249 ( V_111 ) ;
V_111 -> V_232 = F_250 ( V_232 ) ;
if ( V_158 & V_198 ) {
V_111 -> V_326 = - 1 ;
V_111 -> V_213 = V_28 -> V_213 ;
V_111 -> V_327 = V_28 -> V_327 ;
} else {
if ( V_158 & V_241 )
V_111 -> V_326 = V_28 -> V_213 -> V_326 ;
else
V_111 -> V_326 = ( V_158 & V_328 ) ;
V_111 -> V_213 = V_111 ;
V_111 -> V_327 = V_111 -> V_232 ;
}
V_111 -> V_329 = 0 ;
V_111 -> V_330 = 128 >> ( V_331 - 10 ) ;
V_111 -> V_332 = 0 ;
V_111 -> V_333 = 0 ;
F_69 ( & V_111 -> V_334 ) ;
V_111 -> V_335 = NULL ;
F_251 ( & V_1 ) ;
if ( V_158 & ( V_241 | V_198 ) ) {
V_111 -> V_336 = V_28 -> V_336 ;
V_111 -> V_337 = V_28 -> V_337 ;
} else {
V_111 -> V_336 = V_28 ;
V_111 -> V_337 = V_28 -> V_338 ;
}
F_130 ( & V_28 -> V_187 -> V_339 ) ;
F_252 () ;
if ( F_253 ( V_28 ) ) {
F_132 ( & V_28 -> V_187 -> V_339 ) ;
F_254 ( & V_1 ) ;
V_61 = - V_340 ;
goto V_341;
}
if ( F_107 ( V_111 -> V_232 ) ) {
F_255 ( V_111 , ( V_158 & V_342 ) || V_237 ) ;
F_204 ( V_111 , V_343 , V_232 ) ;
if ( F_256 ( V_111 ) ) {
F_204 ( V_111 , V_344 , F_257 ( V_28 ) ) ;
F_204 ( V_111 , V_345 , F_258 ( V_28 ) ) ;
if ( F_259 ( V_232 ) ) {
F_260 ( V_232 ) -> V_346 = V_111 ;
V_111 -> signal -> V_115 |= V_242 ;
}
V_111 -> signal -> V_347 = V_232 ;
V_111 -> signal -> V_348 = F_261 ( V_28 -> signal -> V_348 ) ;
F_262 ( & V_111 -> V_260 , & V_111 -> V_336 -> V_259 ) ;
F_263 ( & V_111 -> V_349 , & V_34 . V_349 ) ;
F_264 ( V_111 , V_344 ) ;
F_264 ( V_111 , V_345 ) ;
F_265 ( V_4 ) ;
} else {
V_28 -> signal -> V_199 ++ ;
F_142 ( & V_28 -> signal -> V_200 ) ;
F_142 ( & V_28 -> signal -> V_25 ) ;
F_263 ( & V_111 -> V_334 ,
& V_111 -> V_213 -> V_334 ) ;
F_263 ( & V_111 -> V_203 ,
& V_111 -> signal -> V_201 ) ;
}
F_264 ( V_111 , V_343 ) ;
V_199 ++ ;
}
V_350 ++ ;
F_132 ( & V_28 -> V_187 -> V_339 ) ;
F_254 ( & V_1 ) ;
F_266 ( V_111 ) ;
F_267 ( V_111 ) ;
if ( V_158 & V_198 )
F_268 ( V_28 ) ;
F_269 ( V_111 ) ;
F_270 ( V_111 , V_158 ) ;
F_271 ( V_111 , V_158 ) ;
return V_111 ;
V_341:
if ( V_232 != & V_316 )
F_272 ( V_232 ) ;
V_315:
if ( V_111 -> V_179 )
F_273 ( V_111 ) ;
V_314:
F_274 ( V_111 ) ;
V_313:
if ( V_111 -> V_51 )
F_121 ( V_111 -> V_51 ) ;
V_312:
if ( ! ( V_158 & V_198 ) )
F_28 ( V_111 -> signal ) ;
V_311:
F_183 ( V_111 -> V_187 ) ;
V_310:
F_275 ( V_111 ) ;
V_309:
F_276 ( V_111 ) ;
V_308:
F_277 ( V_111 ) ;
V_307:
F_278 ( V_111 ) ;
V_306:
F_279 ( V_111 ) ;
#ifdef F_227
F_90 ( V_111 -> V_280 ) ;
V_281:
#endif
if ( V_158 & V_198 )
F_268 ( V_28 ) ;
F_280 ( V_111 , 0 ) ;
F_38 ( V_111 ) ;
F_133 ( F_215 ( V_111 ) -> V_258 -> V_133 ) ;
V_257:
F_74 ( & V_111 -> V_351 -> V_250 -> V_251 ) ;
F_37 ( V_111 ) ;
V_255:
F_24 ( V_111 ) ;
V_246:
return F_146 ( V_61 ) ;
}
static inline void F_281 ( struct V_352 * V_353 )
{
enum V_231 type ;
for ( type = V_343 ; type < V_354 ; ++ type ) {
F_282 ( & V_353 [ type ] . V_7 ) ;
V_353 [ type ] . V_232 = & V_316 ;
}
}
struct V_5 * F_283 ( int V_2 )
{
struct V_5 * V_137 ;
V_137 = F_205 ( V_165 , 0 , 0 , NULL , & V_316 , 0 ) ;
if ( ! F_229 ( V_137 ) ) {
F_281 ( V_137 -> V_233 ) ;
F_284 ( V_137 , V_2 ) ;
}
return V_137 ;
}
long F_285 ( unsigned long V_158 ,
unsigned long V_234 ,
unsigned long V_235 ,
int T_2 * V_355 ,
int T_2 * V_236 )
{
struct V_5 * V_111 ;
int V_237 = 0 ;
long V_356 ;
if ( ! ( V_158 & V_357 ) ) {
if ( V_158 & V_322 )
V_237 = V_358 ;
else if ( ( V_158 & V_328 ) != V_359 )
V_237 = V_360 ;
else
V_237 = V_361 ;
if ( F_107 ( ! F_286 ( V_28 , V_237 ) ) )
V_237 = 0 ;
}
V_111 = F_205 ( V_158 , V_234 , V_235 ,
V_236 , NULL , V_237 ) ;
if ( ! F_229 ( V_111 ) ) {
struct V_142 V_143 ;
F_287 ( V_28 , V_111 ) ;
V_356 = F_288 ( V_111 ) ;
if ( V_158 & V_362 )
F_163 ( V_356 , V_355 ) ;
if ( V_158 & V_322 ) {
V_111 -> V_144 = & V_143 ;
F_289 ( & V_143 ) ;
F_290 ( V_111 ) ;
}
F_291 ( V_111 ) ;
if ( F_77 ( V_237 ) )
F_292 ( V_237 , V_356 ) ;
if ( V_158 & V_322 ) {
if ( ! F_150 ( V_111 , & V_143 ) )
F_292 ( V_363 , V_356 ) ;
}
} else {
V_356 = F_230 ( V_111 ) ;
}
return V_356 ;
}
T_3 F_293 ( int (* F_294)( void * ) , void * V_364 , unsigned long V_115 )
{
return F_285 ( V_115 | V_165 | V_357 , ( unsigned long ) F_294 ,
( unsigned long ) V_364 , NULL , NULL ) ;
}
static void F_295 ( void * V_365 )
{
struct V_185 * V_187 = V_365 ;
F_101 ( & V_187 -> V_339 ) ;
F_192 ( & V_187 -> V_366 ) ;
}
void T_1 F_296 ( void )
{
V_188 = F_18 ( L_5 ,
sizeof( struct V_185 ) , 0 ,
V_367 | V_30 | V_368 |
V_31 , F_295 ) ;
V_24 = F_18 ( L_6 ,
sizeof( struct V_22 ) , 0 ,
V_367 | V_30 | V_31 , NULL ) ;
V_369 = F_18 ( L_7 ,
sizeof( struct V_174 ) , 0 ,
V_367 | V_30 | V_31 , NULL ) ;
V_370 = F_18 ( L_8 ,
sizeof( struct V_167 ) , 0 ,
V_367 | V_30 | V_31 , NULL ) ;
V_371 = F_18 ( L_9 ,
sizeof( struct V_50 ) , V_372 ,
V_367 | V_30 | V_31 , NULL ) ;
V_80 = F_297 ( V_53 , V_30 ) ;
F_298 () ;
F_299 () ;
}
static int F_300 ( unsigned long V_373 )
{
if ( V_373 & ~ ( V_198 | V_169 | V_238 | V_186 |
V_165 | V_178 | V_374 |
V_375 | V_376 | V_377 |
V_240 | V_243 ) )
return - V_239 ;
if ( V_373 & ( V_198 | V_186 | V_165 ) ) {
if ( F_35 ( & V_28 -> V_51 -> V_112 ) > 1 )
return - V_239 ;
}
return 0 ;
}
static int F_301 ( unsigned long V_373 , struct V_167 * * V_378 )
{
struct V_167 * V_168 = V_28 -> V_168 ;
if ( ! ( V_373 & V_169 ) || ! V_168 )
return 0 ;
if ( V_168 -> V_173 == 1 )
return 0 ;
* V_378 = F_172 ( V_168 ) ;
if ( ! * V_378 )
return - V_103 ;
return 0 ;
}
static int F_302 ( unsigned long V_373 , struct V_174 * * V_379 )
{
struct V_174 * V_380 = V_28 -> V_177 ;
int error = 0 ;
if ( ( V_373 & V_178 ) &&
( V_380 && F_35 ( & V_380 -> V_125 ) > 1 ) ) {
* V_379 = F_174 ( V_380 , & error ) ;
if ( ! * V_379 )
return error ;
}
return 0 ;
}
int F_303 ( struct V_174 * * V_381 )
{
struct V_5 * V_137 = V_28 ;
struct V_174 * V_382 = NULL ;
int error ;
error = F_302 ( V_178 , & V_382 ) ;
if ( error || ! V_382 ) {
* V_381 = NULL ;
return error ;
}
* V_381 = V_137 -> V_177 ;
F_141 ( V_137 ) ;
V_137 -> V_177 = V_382 ;
F_143 ( V_137 ) ;
return 0 ;
}
