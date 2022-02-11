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
static struct V_5 * F_46 ( struct V_5 * V_41 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
unsigned long * V_42 ;
int V_7 = F_47 ( V_41 ) ;
int V_43 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_44;
V_43 = F_45 ( V_6 , V_41 ) ;
if ( V_43 )
goto V_45;
V_6 -> V_20 = V_11 ;
F_48 ( V_6 , V_41 ) ;
F_49 ( V_6 ) ;
F_50 ( V_6 ) ;
V_42 = F_51 ( V_6 ) ;
* V_42 = V_46 ;
#ifdef F_52
V_6 -> V_47 = F_53 () ;
#endif
F_54 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_55
V_6 -> V_48 = 0 ;
#endif
V_6 -> V_49 = NULL ;
V_6 -> V_50 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_45:
F_15 ( V_11 ) ;
V_44:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_56 ( struct V_51 * V_52 , struct V_51 * V_53 )
{
struct V_54 * V_55 , * V_56 , * V_57 , * * V_58 ;
struct V_59 * * V_60 , * V_61 ;
int V_62 ;
unsigned long V_63 ;
F_57 () ;
F_58 ( & V_53 -> V_64 ) ;
F_59 ( V_53 ) ;
F_60 ( V_53 , V_52 ) ;
F_61 ( & V_52 -> V_64 , V_65 ) ;
V_52 -> V_66 = 0 ;
V_52 -> V_67 = NULL ;
V_52 -> V_68 = 0 ;
V_52 -> V_69 = 0 ;
F_62 ( F_63 ( V_52 ) ) ;
V_52 -> V_70 = V_71 ;
V_60 = & V_52 -> V_70 . V_59 ;
V_61 = NULL ;
V_58 = & V_52 -> V_67 ;
V_62 = F_64 ( V_52 , V_53 ) ;
if ( V_62 )
goto V_72;
V_62 = F_65 ( V_52 , V_53 ) ;
if ( V_62 )
goto V_72;
V_57 = NULL ;
for ( V_55 = V_53 -> V_67 ; V_55 ; V_55 = V_55 -> V_73 ) {
struct V_74 * V_74 ;
if ( V_55 -> V_75 & V_76 ) {
F_66 ( V_52 , V_55 -> V_75 , V_55 -> V_77 ,
- F_67 ( V_55 ) ) ;
continue;
}
V_63 = 0 ;
if ( V_55 -> V_75 & V_78 ) {
unsigned long V_79 = F_67 ( V_55 ) ;
if ( F_68 ( V_53 , V_79 ) )
goto V_80;
V_63 = V_79 ;
}
V_56 = F_69 ( V_81 , V_9 ) ;
if ( ! V_56 )
goto V_80;
* V_56 = * V_55 ;
F_70 ( & V_56 -> V_82 ) ;
V_62 = F_71 ( V_55 , V_56 ) ;
if ( V_62 )
goto V_83;
V_56 -> V_84 = V_52 ;
if ( F_72 ( V_56 , V_55 ) )
goto V_85;
V_56 -> V_75 &= ~ V_86 ;
V_56 -> V_73 = V_56 -> V_87 = NULL ;
V_74 = V_56 -> V_77 ;
if ( V_74 ) {
struct V_88 * V_88 = F_73 ( V_74 ) ;
struct V_89 * V_90 = V_74 -> V_91 ;
F_74 ( V_74 ) ;
if ( V_56 -> V_75 & V_92 )
F_75 ( & V_88 -> V_93 ) ;
F_76 ( & V_90 -> V_94 ) ;
if ( V_56 -> V_75 & V_95 )
V_90 -> V_96 ++ ;
F_77 ( V_90 ) ;
if ( F_78 ( V_56 -> V_75 & V_97 ) )
F_79 ( V_56 ,
& V_90 -> V_98 ) ;
else
F_80 ( V_56 , V_55 ,
& V_90 -> V_99 ) ;
F_81 ( V_90 ) ;
F_82 ( & V_90 -> V_94 ) ;
}
if ( F_83 ( V_56 ) )
F_84 ( V_56 ) ;
* V_58 = V_56 ;
V_58 = & V_56 -> V_73 ;
V_56 -> V_87 = V_57 ;
V_57 = V_56 ;
F_85 ( V_52 , V_56 , V_60 , V_61 ) ;
V_60 = & V_56 -> V_100 . V_101 ;
V_61 = & V_56 -> V_100 ;
V_52 -> V_69 ++ ;
V_62 = F_86 ( V_52 , V_53 , V_55 ) ;
if ( V_56 -> V_102 && V_56 -> V_102 -> V_103 )
V_56 -> V_102 -> V_103 ( V_56 ) ;
if ( V_62 )
goto V_72;
}
F_87 ( V_53 , V_52 ) ;
V_62 = 0 ;
V_72:
F_88 ( & V_52 -> V_64 ) ;
F_89 ( V_53 ) ;
F_88 ( & V_53 -> V_64 ) ;
F_90 () ;
return V_62 ;
V_85:
F_91 ( F_92 ( V_56 ) ) ;
V_83:
F_10 ( V_81 , V_56 ) ;
V_80:
V_62 = - V_104 ;
F_93 ( V_63 ) ;
goto V_72;
}
static inline int F_94 ( struct V_51 * V_52 )
{
V_52 -> V_105 = F_95 ( V_52 ) ;
if ( F_78 ( ! V_52 -> V_105 ) )
return - V_104 ;
return 0 ;
}
static inline void F_96 ( struct V_51 * V_52 )
{
F_97 ( V_52 , V_52 -> V_105 ) ;
}
static int T_1 F_98 ( char * V_106 )
{
V_107 =
( F_99 ( V_106 , NULL , 0 ) << V_108 ) &
V_109 ;
return 1 ;
}
static void F_100 ( struct V_51 * V_52 )
{
#ifdef F_101
F_102 ( & V_52 -> V_110 ) ;
V_52 -> V_111 = NULL ;
#endif
}
static struct V_51 * F_103 ( struct V_51 * V_52 , struct V_5 * V_112 )
{
F_54 ( & V_52 -> V_113 , 1 ) ;
F_54 ( & V_52 -> V_114 , 1 ) ;
F_104 ( & V_52 -> V_64 ) ;
F_70 ( & V_52 -> V_115 ) ;
V_52 -> V_116 = NULL ;
F_105 ( & V_52 -> V_117 , 0 ) ;
memset ( & V_52 -> V_118 , 0 , sizeof( V_52 -> V_118 ) ) ;
F_102 ( & V_52 -> V_119 ) ;
F_100 ( V_52 ) ;
F_106 ( V_52 , V_112 ) ;
F_107 ( V_52 ) ;
if ( V_27 -> V_52 ) {
V_52 -> V_120 = V_27 -> V_52 -> V_120 & V_121 ;
V_52 -> V_122 = V_27 -> V_52 -> V_122 & V_123 ;
} else {
V_52 -> V_120 = V_107 ;
V_52 -> V_122 = 0 ;
}
if ( F_108 ( ! F_94 ( V_52 ) ) ) {
F_109 ( V_52 ) ;
return V_52 ;
}
F_110 ( V_52 ) ;
return NULL ;
}
static void F_111 ( struct V_51 * V_52 )
{
int V_124 ;
for ( V_124 = 0 ; V_124 < V_125 ; V_124 ++ ) {
long V_126 = F_112 ( & V_52 -> V_118 . V_127 [ V_124 ] ) ;
if ( F_78 ( V_126 ) )
F_113 ( V_128 L_3
L_4 , V_52 , V_124 , V_126 ) ;
}
#if F_114 ( V_129 ) && ! V_130
F_115 ( V_52 -> V_131 ) ;
#endif
}
struct V_51 * F_116 ( void )
{
struct V_51 * V_52 ;
V_52 = F_117 () ;
if ( ! V_52 )
return NULL ;
memset ( V_52 , 0 , sizeof( * V_52 ) ) ;
F_118 ( V_52 ) ;
return F_103 ( V_52 , V_27 ) ;
}
void F_119 ( struct V_51 * V_52 )
{
F_19 ( V_52 == & V_132 ) ;
F_96 ( V_52 ) ;
F_120 ( V_52 ) ;
F_121 ( V_52 ) ;
F_111 ( V_52 ) ;
F_110 ( V_52 ) ;
}
void F_122 ( struct V_51 * V_52 )
{
F_123 () ;
if ( F_32 ( & V_52 -> V_113 ) ) {
F_124 ( V_52 ) ;
F_125 ( V_52 ) ;
F_126 ( V_52 ) ;
F_127 ( V_52 ) ;
F_128 ( V_52 ) ;
F_129 ( V_52 , NULL ) ;
if ( ! F_130 ( & V_52 -> V_115 ) ) {
F_131 ( & V_133 ) ;
F_132 ( & V_52 -> V_115 ) ;
F_133 ( & V_133 ) ;
}
if ( V_52 -> V_134 )
F_134 ( V_52 -> V_134 -> V_135 ) ;
F_135 ( V_52 ) ;
}
}
void F_129 ( struct V_51 * V_52 , struct V_74 * V_136 )
{
if ( V_136 )
F_74 ( V_136 ) ;
if ( V_52 -> V_137 )
F_136 ( V_52 -> V_137 ) ;
V_52 -> V_137 = V_136 ;
}
struct V_74 * F_137 ( struct V_51 * V_52 )
{
struct V_74 * V_137 ;
F_138 ( & V_52 -> V_64 ) ;
V_137 = V_52 -> V_137 ;
if ( V_137 )
F_74 ( V_137 ) ;
F_139 ( & V_52 -> V_64 ) ;
return V_137 ;
}
static void F_140 ( struct V_51 * V_53 , struct V_51 * V_138 )
{
V_138 -> V_137 = F_137 ( V_53 ) ;
}
struct V_51 * F_141 ( struct V_5 * V_139 )
{
struct V_51 * V_52 ;
F_142 ( V_139 ) ;
V_52 = V_139 -> V_52 ;
if ( V_52 ) {
if ( V_139 -> V_120 & V_140 )
V_52 = NULL ;
else
F_143 ( & V_52 -> V_113 ) ;
}
F_144 ( V_139 ) ;
return V_52 ;
}
struct V_51 * F_145 ( struct V_5 * V_139 , unsigned int V_141 )
{
struct V_51 * V_52 ;
int V_43 ;
V_43 = F_146 ( & V_139 -> signal -> V_142 ) ;
if ( V_43 )
return F_147 ( V_43 ) ;
V_52 = F_141 ( V_139 ) ;
if ( V_52 && V_52 != V_27 -> V_52 &&
! F_148 ( V_139 , V_141 ) ) {
F_122 ( V_52 ) ;
V_52 = F_147 ( - V_143 ) ;
}
F_82 ( & V_139 -> signal -> V_142 ) ;
return V_52 ;
}
static void F_149 ( struct V_5 * V_6 )
{
struct V_144 * V_145 ;
F_142 ( V_6 ) ;
V_145 = V_6 -> V_146 ;
if ( F_108 ( V_145 ) ) {
V_6 -> V_146 = NULL ;
F_150 ( V_145 ) ;
}
F_144 ( V_6 ) ;
}
static int F_151 ( struct V_5 * V_147 ,
struct V_144 * V_145 )
{
int V_148 ;
F_152 () ;
V_148 = F_153 ( V_145 ) ;
F_154 () ;
if ( V_148 ) {
F_142 ( V_147 ) ;
V_147 -> V_146 = NULL ;
F_144 ( V_147 ) ;
}
F_155 ( V_147 ) ;
return V_148 ;
}
void F_156 ( struct V_5 * V_6 , struct V_51 * V_52 )
{
#ifdef F_157
if ( F_78 ( V_6 -> V_149 ) ) {
F_158 ( V_6 ) ;
V_6 -> V_149 = NULL ;
}
#ifdef F_159
if ( F_78 ( V_6 -> V_150 ) ) {
F_160 ( V_6 ) ;
V_6 -> V_150 = NULL ;
}
#endif
if ( F_78 ( ! F_130 ( & V_6 -> V_151 ) ) )
F_161 ( V_6 ) ;
#endif
F_162 ( V_6 ) ;
F_163 ( V_6 , V_52 ) ;
if ( V_6 -> V_152 ) {
if ( ! ( V_6 -> V_120 & V_153 ) &&
F_35 ( & V_52 -> V_113 ) > 1 ) {
F_164 ( 0 , V_6 -> V_152 ) ;
F_165 ( V_6 -> V_152 , V_154 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_152 = NULL ;
}
if ( V_6 -> V_146 )
F_149 ( V_6 ) ;
}
static struct V_51 * F_166 ( struct V_5 * V_6 )
{
struct V_51 * V_52 , * V_53 = V_27 -> V_52 ;
int V_43 ;
V_52 = F_117 () ;
if ( ! V_52 )
goto V_80;
memcpy ( V_52 , V_53 , sizeof( * V_52 ) ) ;
F_118 ( V_52 ) ;
#if F_114 ( V_129 ) && ! V_130
V_52 -> V_131 = NULL ;
#endif
if ( ! F_103 ( V_52 , V_6 ) )
goto V_80;
if ( F_167 ( V_6 , V_52 ) )
goto V_155;
F_140 ( V_53 , V_52 ) ;
V_43 = F_56 ( V_52 , V_53 ) ;
if ( V_43 )
goto V_156;
V_52 -> V_157 = F_168 ( V_52 ) ;
V_52 -> V_158 = V_52 -> V_159 ;
if ( V_52 -> V_134 && ! F_169 ( V_52 -> V_134 -> V_135 ) )
goto V_156;
return V_52 ;
V_156:
V_52 -> V_134 = NULL ;
F_122 ( V_52 ) ;
V_80:
return NULL ;
V_155:
F_96 ( V_52 ) ;
F_110 ( V_52 ) ;
return NULL ;
}
static int F_170 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_51 * V_52 , * V_53 ;
int V_62 ;
V_6 -> V_161 = V_6 -> V_162 = 0 ;
V_6 -> V_163 = V_6 -> V_164 = 0 ;
#ifdef F_171
V_6 -> V_165 = V_6 -> V_163 + V_6 -> V_164 ;
#endif
V_6 -> V_52 = NULL ;
V_6 -> V_166 = NULL ;
V_53 = V_27 -> V_52 ;
if ( ! V_53 )
return 0 ;
F_172 ( V_6 ) ;
if ( V_160 & V_167 ) {
F_143 ( & V_53 -> V_113 ) ;
V_52 = V_53 ;
goto V_168;
}
V_62 = - V_104 ;
V_52 = F_166 ( V_6 ) ;
if ( ! V_52 )
goto V_80;
V_168:
V_6 -> V_52 = V_52 ;
V_6 -> V_166 = V_52 ;
return 0 ;
V_80:
return V_62 ;
}
static int F_173 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_169 * V_170 = V_27 -> V_170 ;
if ( V_160 & V_171 ) {
F_131 ( & V_170 -> V_172 ) ;
if ( V_170 -> V_173 ) {
F_133 ( & V_170 -> V_172 ) ;
return - V_174 ;
}
V_170 -> V_175 ++ ;
F_133 ( & V_170 -> V_172 ) ;
return 0 ;
}
V_6 -> V_170 = F_174 ( V_170 ) ;
if ( ! V_6 -> V_170 )
return - V_104 ;
return 0 ;
}
static int F_175 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_176 * V_177 , * V_178 ;
int error = 0 ;
V_177 = V_27 -> V_179 ;
if ( ! V_177 )
goto V_72;
if ( V_160 & V_180 ) {
F_143 ( & V_177 -> V_127 ) ;
goto V_72;
}
V_178 = F_176 ( V_177 , & error ) ;
if ( ! V_178 )
goto V_72;
V_6 -> V_179 = V_178 ;
error = 0 ;
V_72:
return error ;
}
static int F_177 ( unsigned long V_160 , struct V_5 * V_6 )
{
#ifdef F_178
struct V_181 * V_182 = V_27 -> V_181 ;
struct V_181 * V_183 ;
if ( ! V_182 )
return 0 ;
if ( V_160 & V_184 ) {
F_179 ( V_182 ) ;
V_6 -> V_181 = V_182 ;
} else if ( F_180 ( V_182 -> V_185 ) ) {
V_183 = F_181 ( V_6 , V_9 , V_186 ) ;
if ( F_78 ( ! V_183 ) )
return - V_104 ;
V_183 -> V_185 = V_182 -> V_185 ;
F_182 ( V_183 ) ;
}
#endif
return 0 ;
}
static int F_183 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_187 * V_22 ;
if ( V_160 & V_188 ) {
F_143 ( & V_27 -> V_189 -> V_127 ) ;
return 0 ;
}
V_22 = F_69 ( V_190 , V_9 ) ;
F_184 ( V_6 -> V_189 , V_22 ) ;
if ( ! V_22 )
return - V_104 ;
F_54 ( & V_22 -> V_127 , 1 ) ;
memcpy ( V_22 -> V_191 , V_27 -> V_189 -> V_191 , sizeof( V_22 -> V_191 ) ) ;
return 0 ;
}
void F_185 ( struct V_187 * V_189 )
{
if ( F_32 ( & V_189 -> V_127 ) ) {
F_186 ( V_189 ) ;
F_10 ( V_190 , V_189 ) ;
}
}
static void F_187 ( struct V_21 * V_22 )
{
unsigned long V_192 ;
F_188 ( V_22 ) ;
V_192 = F_189 ( V_22 -> V_34 [ V_193 ] . V_36 ) ;
if ( V_192 != V_194 ) {
V_22 -> V_195 . V_196 = F_190 ( V_192 ) ;
V_22 -> V_197 . V_198 = 1 ;
}
F_70 ( & V_22 -> V_199 [ 0 ] ) ;
F_70 ( & V_22 -> V_199 [ 1 ] ) ;
F_70 ( & V_22 -> V_199 [ 2 ] ) ;
}
static int F_191 ( unsigned long V_160 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_160 & V_200 )
return 0 ;
V_22 = F_192 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_104 ;
V_22 -> V_201 = 1 ;
F_54 ( & V_22 -> V_202 , 1 ) ;
F_54 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_203 = (struct V_204 ) F_193 ( V_6 -> V_205 ) ;
V_6 -> V_205 = (struct V_204 ) F_193 ( V_22 -> V_203 ) ;
F_194 ( & V_22 -> V_206 ) ;
V_22 -> V_207 = V_6 ;
F_195 ( & V_22 -> V_208 ) ;
F_70 ( & V_22 -> V_209 ) ;
F_196 ( & V_22 -> V_210 , V_211 , V_212 ) ;
V_22 -> V_210 . V_213 = V_214 ;
F_142 ( V_27 -> V_215 ) ;
memcpy ( V_22 -> V_34 , V_27 -> signal -> V_34 , sizeof V_22 -> V_34 ) ;
F_144 ( V_27 -> V_215 ) ;
F_187 ( V_22 ) ;
F_197 ( V_22 ) ;
F_198 ( V_22 ) ;
#ifdef F_199
F_104 ( & V_22 -> V_216 ) ;
#endif
V_22 -> V_217 = V_27 -> signal -> V_217 ;
V_22 -> V_218 = V_27 -> signal -> V_218 ;
V_22 -> V_219 = V_27 -> signal -> V_219 ||
V_27 -> signal -> V_220 ;
F_200 ( & V_22 -> V_142 ) ;
return 0 ;
}
static void F_201 ( struct V_5 * V_112 )
{
F_202 ( & V_112 -> V_221 ) ;
#ifdef F_203
V_112 -> V_222 = V_71 ;
V_112 -> V_223 = NULL ;
V_112 -> V_224 = NULL ;
V_112 -> V_225 = NULL ;
#endif
}
void F_106 ( struct V_51 * V_52 , struct V_5 * V_112 )
{
V_52 -> V_226 = V_112 ;
}
static void F_204 ( struct V_5 * V_6 )
{
V_6 -> V_195 . V_196 = 0 ;
V_6 -> V_195 . V_227 = 0 ;
V_6 -> V_195 . V_228 = 0 ;
F_70 ( & V_6 -> V_199 [ 0 ] ) ;
F_70 ( & V_6 -> V_199 [ 1 ] ) ;
F_70 ( & V_6 -> V_199 [ 2 ] ) ;
}
static inline void
F_205 ( struct V_5 * V_139 , enum V_229 type , struct V_230 * V_230 )
{
V_139 -> V_231 [ type ] . V_230 = V_230 ;
}
static struct V_5 * F_206 ( unsigned long V_160 ,
unsigned long V_232 ,
unsigned long V_233 ,
int T_2 * V_234 ,
struct V_230 * V_230 ,
int V_235 )
{
int V_62 ;
struct V_5 * V_112 ;
if ( ( V_160 & ( V_236 | V_171 ) ) == ( V_236 | V_171 ) )
return F_147 ( - V_237 ) ;
if ( ( V_160 & ( V_238 | V_171 ) ) == ( V_238 | V_171 ) )
return F_147 ( - V_237 ) ;
if ( ( V_160 & V_200 ) && ! ( V_160 & V_188 ) )
return F_147 ( - V_237 ) ;
if ( ( V_160 & V_188 ) && ! ( V_160 & V_167 ) )
return F_147 ( - V_237 ) ;
if ( ( V_160 & V_239 ) &&
V_27 -> signal -> V_120 & V_240 )
return F_147 ( - V_237 ) ;
if ( V_160 & V_188 ) {
if ( ( V_160 & ( V_238 | V_241 ) ) ||
( F_207 ( V_27 ) !=
V_27 -> V_242 -> V_243 ) )
return F_147 ( - V_237 ) ;
}
V_62 = F_208 ( V_160 ) ;
if ( V_62 )
goto V_244;
V_62 = - V_104 ;
V_112 = F_46 ( V_27 ) ;
if ( ! V_112 )
goto V_244;
F_209 ( V_112 ) ;
F_210 ( V_112 ) ;
F_201 ( V_112 ) ;
#ifdef F_211
F_212 ( ! V_112 -> V_245 ) ;
F_212 ( ! V_112 -> V_246 ) ;
#endif
V_62 = - V_174 ;
if ( F_35 ( & V_112 -> V_247 -> V_248 -> V_249 ) >=
F_213 ( V_112 , V_35 ) ) {
if ( V_112 -> V_247 -> V_248 != V_250 &&
! F_214 ( V_251 ) && ! F_214 ( V_252 ) )
goto V_253;
}
V_27 -> V_120 &= ~ V_254 ;
V_62 = F_215 ( V_112 , V_160 ) ;
if ( V_62 < 0 )
goto V_253;
V_62 = - V_174 ;
if ( V_201 >= V_31 )
goto V_255;
if ( ! F_169 ( F_216 ( V_112 ) -> V_256 -> V_135 ) )
goto V_255;
F_217 ( V_112 ) ;
V_112 -> V_120 &= ~ ( V_257 | V_258 ) ;
V_112 -> V_120 |= V_259 ;
F_70 ( & V_112 -> V_260 ) ;
F_70 ( & V_112 -> V_261 ) ;
F_218 ( V_112 ) ;
V_112 -> V_146 = NULL ;
F_102 ( & V_112 -> V_262 ) ;
F_195 ( & V_112 -> V_263 ) ;
V_112 -> V_264 = V_112 -> V_265 = V_112 -> V_266 = 0 ;
V_112 -> V_267 = V_112 -> V_268 = 0 ;
#ifndef F_219
V_112 -> V_269 . V_264 = V_112 -> V_269 . V_265 = 0 ;
#endif
#ifdef F_220
F_221 ( & V_112 -> V_270 ) ;
V_112 -> V_271 = 0 ;
V_112 -> V_272 = V_273 ;
#endif
#if F_114 ( V_274 )
memset ( & V_112 -> V_118 , 0 , sizeof( V_112 -> V_118 ) ) ;
#endif
V_112 -> V_275 = V_27 -> V_276 ;
F_222 ( & V_112 -> V_277 ) ;
F_223 ( V_112 ) ;
F_204 ( V_112 ) ;
F_224 ( & V_112 -> V_278 ) ;
V_112 -> V_279 = V_112 -> V_278 ;
F_225 ( & V_112 -> V_279 ) ;
V_112 -> V_181 = NULL ;
V_112 -> V_280 = NULL ;
if ( V_160 & V_200 )
F_226 ( V_27 ) ;
F_227 ( V_112 ) ;
#ifdef F_228
V_112 -> V_281 = F_229 ( V_112 -> V_281 ) ;
if ( F_230 ( V_112 -> V_281 ) ) {
V_62 = F_231 ( V_112 -> V_281 ) ;
V_112 -> V_281 = NULL ;
goto V_282;
}
#endif
#ifdef F_232
V_112 -> V_283 = V_186 ;
V_112 -> V_284 = V_186 ;
F_233 ( & V_112 -> V_285 ) ;
#endif
#ifdef F_234
V_112 -> V_286 = 0 ;
V_112 -> V_245 = 0 ;
V_112 -> V_287 = 0 ;
V_112 -> V_288 = 0 ;
V_112 -> V_289 = V_290 ;
V_112 -> V_291 = 0 ;
V_112 -> V_246 = 1 ;
V_112 -> V_292 = V_290 ;
V_112 -> V_293 = 0 ;
V_112 -> V_294 = 0 ;
V_112 -> V_295 = 0 ;
V_112 -> V_296 = 0 ;
V_112 -> V_297 = 0 ;
#endif
#ifdef F_235
V_112 -> V_298 = 0 ;
V_112 -> V_299 = 0 ;
V_112 -> V_300 = 0 ;
#endif
#ifdef F_236
V_112 -> V_301 = NULL ;
#endif
#ifdef F_237
V_112 -> V_302 . V_303 = 0 ;
V_112 -> V_302 . V_304 = NULL ;
#endif
#ifdef F_238
V_112 -> V_305 = 0 ;
V_112 -> V_306 = 0 ;
#endif
V_62 = F_239 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_307;
V_62 = F_240 ( V_112 ) ;
if ( V_62 )
goto V_307;
V_62 = F_241 ( V_112 ) ;
if ( V_62 )
goto V_307;
V_62 = F_242 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_308;
V_62 = F_175 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_309;
V_62 = F_173 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_310;
V_62 = F_183 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_311;
V_62 = F_191 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_312;
V_62 = F_170 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_313;
V_62 = F_243 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_314;
V_62 = F_177 ( V_160 , V_112 ) ;
if ( V_62 )
goto V_315;
V_62 = F_244 ( V_160 , V_232 , V_233 , V_112 ) ;
if ( V_62 )
goto V_316;
if ( V_230 != & V_317 ) {
V_62 = - V_104 ;
V_230 = F_245 ( V_112 -> V_242 -> V_243 ) ;
if ( ! V_230 )
goto V_316;
}
V_112 -> V_318 = ( V_160 & V_319 ) ? V_234 : NULL ;
V_112 -> V_152 = ( V_160 & V_320 ) ? V_234 : NULL ;
#ifdef F_178
V_112 -> V_321 = NULL ;
#endif
#ifdef F_157
V_112 -> V_149 = NULL ;
#ifdef F_159
V_112 -> V_150 = NULL ;
#endif
F_70 ( & V_112 -> V_151 ) ;
V_112 -> V_322 = NULL ;
#endif
if ( ( V_160 & ( V_167 | V_323 ) ) == V_167 )
V_112 -> V_324 = V_112 -> V_325 = 0 ;
F_246 ( V_112 ) ;
F_247 ( V_112 , V_326 ) ;
#ifdef F_248
F_247 ( V_112 , F_248 ) ;
#endif
F_249 ( V_112 ) ;
V_112 -> V_230 = F_250 ( V_230 ) ;
if ( V_160 & V_200 ) {
V_112 -> V_327 = - 1 ;
V_112 -> V_215 = V_27 -> V_215 ;
V_112 -> V_328 = V_27 -> V_328 ;
} else {
if ( V_160 & V_239 )
V_112 -> V_327 = V_27 -> V_215 -> V_327 ;
else
V_112 -> V_327 = ( V_160 & V_329 ) ;
V_112 -> V_215 = V_112 ;
V_112 -> V_328 = V_112 -> V_230 ;
}
V_112 -> V_330 = 0 ;
V_112 -> V_331 = 128 >> ( V_332 - 10 ) ;
V_112 -> V_333 = 0 ;
V_112 -> V_334 = 0 ;
F_70 ( & V_112 -> V_335 ) ;
V_112 -> V_336 = NULL ;
F_251 ( & V_1 ) ;
if ( V_160 & ( V_239 | V_200 ) ) {
V_112 -> V_337 = V_27 -> V_337 ;
V_112 -> V_338 = V_27 -> V_338 ;
} else {
V_112 -> V_337 = V_27 ;
V_112 -> V_338 = V_27 -> V_339 ;
}
F_131 ( & V_27 -> V_189 -> V_340 ) ;
F_252 () ;
if ( F_253 ( V_27 ) ) {
F_133 ( & V_27 -> V_189 -> V_340 ) ;
F_254 ( & V_1 ) ;
V_62 = - V_341 ;
goto V_342;
}
if ( F_108 ( V_112 -> V_230 ) ) {
F_255 ( V_112 , ( V_160 & V_343 ) || V_235 ) ;
F_205 ( V_112 , V_344 , V_230 ) ;
if ( F_256 ( V_112 ) ) {
F_205 ( V_112 , V_345 , F_257 ( V_27 ) ) ;
F_205 ( V_112 , V_346 , F_258 ( V_27 ) ) ;
if ( F_259 ( V_230 ) ) {
F_260 ( V_230 ) -> V_347 = V_112 ;
V_112 -> signal -> V_120 |= V_240 ;
}
V_112 -> signal -> V_348 = V_230 ;
V_112 -> signal -> V_349 = F_261 ( V_27 -> signal -> V_349 ) ;
F_262 ( & V_112 -> V_261 , & V_112 -> V_337 -> V_260 ) ;
F_263 ( & V_112 -> V_350 , & V_33 . V_350 ) ;
F_264 ( V_112 , V_345 ) ;
F_264 ( V_112 , V_346 ) ;
F_265 ( V_4 ) ;
} else {
V_27 -> signal -> V_201 ++ ;
F_143 ( & V_27 -> signal -> V_202 ) ;
F_143 ( & V_27 -> signal -> V_24 ) ;
F_263 ( & V_112 -> V_335 ,
& V_112 -> V_215 -> V_335 ) ;
F_263 ( & V_112 -> V_205 ,
& V_112 -> signal -> V_203 ) ;
}
F_264 ( V_112 , V_344 ) ;
V_201 ++ ;
}
V_351 ++ ;
F_133 ( & V_27 -> V_189 -> V_340 ) ;
F_266 ( V_112 ) ;
F_254 ( & V_1 ) ;
F_267 ( V_112 ) ;
F_268 ( V_112 ) ;
if ( V_160 & V_200 )
F_269 ( V_27 ) ;
F_270 ( V_112 ) ;
F_271 ( V_112 , V_160 ) ;
F_272 ( V_112 , V_160 ) ;
return V_112 ;
V_342:
if ( V_230 != & V_317 )
F_273 ( V_230 ) ;
V_316:
if ( V_112 -> V_181 )
F_274 ( V_112 ) ;
V_315:
F_275 ( V_112 ) ;
V_314:
if ( V_112 -> V_52 )
F_122 ( V_112 -> V_52 ) ;
V_313:
if ( ! ( V_160 & V_200 ) )
F_28 ( V_112 -> signal ) ;
V_312:
F_185 ( V_112 -> V_189 ) ;
V_311:
F_276 ( V_112 ) ;
V_310:
F_277 ( V_112 ) ;
V_309:
F_278 ( V_112 ) ;
V_308:
F_279 ( V_112 ) ;
V_307:
F_280 ( V_112 ) ;
#ifdef F_228
F_91 ( V_112 -> V_281 ) ;
V_282:
#endif
if ( V_160 & V_200 )
F_269 ( V_27 ) ;
F_39 ( V_112 ) ;
F_134 ( F_216 ( V_112 ) -> V_256 -> V_135 ) ;
V_255:
F_75 ( & V_112 -> V_352 -> V_248 -> V_249 ) ;
F_38 ( V_112 ) ;
V_253:
F_24 ( V_112 ) ;
V_244:
return F_147 ( V_62 ) ;
}
static inline void F_281 ( struct V_353 * V_354 )
{
enum V_229 type ;
for ( type = V_344 ; type < V_355 ; ++ type ) {
F_282 ( & V_354 [ type ] . V_7 ) ;
V_354 [ type ] . V_230 = & V_317 ;
}
}
struct V_5 * F_283 ( int V_2 )
{
struct V_5 * V_139 ;
V_139 = F_206 ( V_167 , 0 , 0 , NULL , & V_317 , 0 ) ;
if ( ! F_230 ( V_139 ) ) {
F_281 ( V_139 -> V_231 ) ;
F_284 ( V_139 , V_2 ) ;
}
return V_139 ;
}
long F_285 ( unsigned long V_160 ,
unsigned long V_232 ,
unsigned long V_233 ,
int T_2 * V_356 ,
int T_2 * V_234 )
{
struct V_5 * V_112 ;
int V_235 = 0 ;
long V_357 ;
if ( ! ( V_160 & V_358 ) ) {
if ( V_160 & V_323 )
V_235 = V_359 ;
else if ( ( V_160 & V_329 ) != V_360 )
V_235 = V_361 ;
else
V_235 = V_362 ;
if ( F_108 ( ! F_286 ( V_27 , V_235 ) ) )
V_235 = 0 ;
}
V_112 = F_206 ( V_160 , V_232 , V_233 ,
V_234 , NULL , V_235 ) ;
if ( ! F_230 ( V_112 ) ) {
struct V_144 V_145 ;
struct V_230 * V_230 ;
F_287 ( V_27 , V_112 ) ;
V_230 = F_288 ( V_112 , V_344 ) ;
V_357 = F_289 ( V_230 ) ;
if ( V_160 & V_363 )
F_164 ( V_357 , V_356 ) ;
if ( V_160 & V_323 ) {
V_112 -> V_146 = & V_145 ;
F_290 ( & V_145 ) ;
F_291 ( V_112 ) ;
}
F_292 ( V_112 ) ;
if ( F_78 ( V_235 ) )
F_293 ( V_235 , V_230 ) ;
if ( V_160 & V_323 ) {
if ( ! F_151 ( V_112 , & V_145 ) )
F_293 ( V_364 , V_230 ) ;
}
F_294 ( V_230 ) ;
} else {
V_357 = F_231 ( V_112 ) ;
}
return V_357 ;
}
T_3 F_295 ( int (* F_296)( void * ) , void * V_365 , unsigned long V_120 )
{
return F_285 ( V_120 | V_167 | V_358 , ( unsigned long ) F_296 ,
( unsigned long ) V_365 , NULL , NULL ) ;
}
static void F_297 ( void * V_366 )
{
struct V_187 * V_189 = V_366 ;
F_102 ( & V_189 -> V_340 ) ;
F_194 ( & V_189 -> V_367 ) ;
}
void T_1 F_298 ( void )
{
V_190 = F_18 ( L_5 ,
sizeof( struct V_187 ) , 0 ,
V_368 | V_29 | V_369 |
V_30 , F_297 ) ;
V_23 = F_18 ( L_6 ,
sizeof( struct V_21 ) , 0 ,
V_368 | V_29 | V_30 , NULL ) ;
V_370 = F_18 ( L_7 ,
sizeof( struct V_176 ) , 0 ,
V_368 | V_29 | V_30 , NULL ) ;
V_371 = F_18 ( L_8 ,
sizeof( struct V_169 ) , 0 ,
V_368 | V_29 | V_30 , NULL ) ;
V_372 = F_18 ( L_9 ,
sizeof( struct V_51 ) , V_373 ,
V_368 | V_29 | V_30 , NULL ) ;
V_81 = F_299 ( V_54 , V_29 ) ;
F_300 () ;
F_301 () ;
}
static int F_302 ( unsigned long V_374 )
{
if ( V_374 & ~ ( V_200 | V_171 | V_236 | V_188 |
V_167 | V_180 | V_375 |
V_376 | V_377 | V_378 |
V_238 | V_241 ) )
return - V_237 ;
if ( V_374 & ( V_200 | V_188 | V_167 ) ) {
if ( F_35 ( & V_27 -> V_52 -> V_113 ) > 1 )
return - V_237 ;
}
return 0 ;
}
static int F_303 ( unsigned long V_374 , struct V_169 * * V_379 )
{
struct V_169 * V_170 = V_27 -> V_170 ;
if ( ! ( V_374 & V_171 ) || ! V_170 )
return 0 ;
if ( V_170 -> V_175 == 1 )
return 0 ;
* V_379 = F_174 ( V_170 ) ;
if ( ! * V_379 )
return - V_104 ;
return 0 ;
}
static int F_304 ( unsigned long V_374 , struct V_176 * * V_380 )
{
struct V_176 * V_381 = V_27 -> V_179 ;
int error = 0 ;
if ( ( V_374 & V_180 ) &&
( V_381 && F_35 ( & V_381 -> V_127 ) > 1 ) ) {
* V_380 = F_176 ( V_381 , & error ) ;
if ( ! * V_380 )
return error ;
}
return 0 ;
}
int F_305 ( struct V_176 * * V_382 )
{
struct V_5 * V_139 = V_27 ;
struct V_176 * V_383 = NULL ;
int error ;
error = F_304 ( V_180 , & V_383 ) ;
if ( error || ! V_383 ) {
* V_382 = NULL ;
return error ;
}
* V_382 = V_139 -> V_179 ;
F_142 ( V_139 ) ;
V_139 -> V_179 = V_383 ;
F_144 ( V_139 ) ;
return 0 ;
}
