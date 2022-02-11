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
static inline struct V_5 * F_6 ( int V_6 )
{
return F_7 ( V_7 , V_8 , V_6 ) ;
}
void __weak F_8 ( struct V_5 * V_9 ) { }
static inline void F_9 ( struct V_5 * V_9 )
{
F_8 ( V_9 ) ;
F_10 ( V_7 , V_9 ) ;
}
void __weak F_11 ( struct V_10 * V_11 ) { }
static struct V_10 * F_12 ( struct V_5 * V_9 ,
int V_6 )
{
struct V_12 * V_12 = F_13 ( V_6 , V_13 ,
V_14 ) ;
return V_12 ? F_14 ( V_12 ) : NULL ;
}
static inline void F_15 ( struct V_10 * V_11 )
{
F_11 ( V_11 ) ;
F_16 ( ( unsigned long ) V_11 , V_14 ) ;
}
static struct V_10 * F_12 ( struct V_5 * V_9 ,
int V_6 )
{
return F_7 ( V_15 , V_13 , V_6 ) ;
}
static void F_15 ( struct V_10 * V_11 )
{
F_11 ( V_11 ) ;
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
void F_24 ( struct V_5 * V_9 )
{
F_20 ( V_9 -> V_20 , - 1 ) ;
F_15 ( V_9 -> V_20 ) ;
F_25 ( V_9 ) ;
F_26 ( V_9 ) ;
F_27 ( V_9 ) ;
F_9 ( V_9 ) ;
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
void F_33 ( struct V_5 * V_9 )
{
F_34 ( ! V_9 -> V_25 ) ;
F_34 ( F_35 ( & V_9 -> V_26 ) ) ;
F_34 ( V_9 == V_27 ) ;
F_36 ( V_9 ) ;
F_37 ( V_9 ) ;
F_38 ( V_9 ) ;
F_31 ( V_9 -> signal ) ;
if ( ! F_39 ( V_9 ) )
F_24 ( V_9 ) ;
}
void T_1 __weak F_40 ( void ) { }
void T_1 F_41 ( unsigned long V_28 )
{
#ifndef F_42
#ifndef F_43
#define F_43 L1_CACHE_BYTES
#endif
V_7 =
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
struct V_5 * V_9 ;
struct V_10 * V_11 ;
unsigned long * V_40 ;
int V_6 = F_45 ( V_39 ) ;
int V_41 ;
V_9 = F_6 ( V_6 ) ;
if ( ! V_9 )
return NULL ;
V_11 = F_12 ( V_9 , V_6 ) ;
if ( ! V_11 ) {
F_9 ( V_9 ) ;
return NULL ;
}
V_41 = F_46 ( V_9 , V_39 ) ;
V_9 -> V_20 = V_11 ;
F_47 ( V_9 , V_39 ) ;
if ( V_41 )
goto V_42;
F_48 ( V_9 ) ;
F_49 ( V_9 ) ;
V_40 = F_50 ( V_9 ) ;
* V_40 = V_43 ;
#ifdef F_51
V_9 -> V_44 = F_52 () ;
#endif
F_53 ( & V_9 -> V_26 , 2 ) ;
#ifdef F_54
V_9 -> V_45 = 0 ;
#endif
V_9 -> V_46 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_9 ;
V_42:
F_15 ( V_11 ) ;
F_9 ( V_9 ) ;
return NULL ;
}
static int F_55 ( struct V_47 * V_48 , struct V_47 * V_49 )
{
struct V_50 * V_51 , * V_52 , * V_53 , * * V_54 ;
struct V_55 * * V_56 , * V_57 ;
int V_58 ;
unsigned long V_59 ;
struct V_60 * V_61 ;
F_56 ( & V_49 -> V_62 ) ;
F_57 ( V_49 ) ;
F_58 ( & V_48 -> V_62 , V_63 ) ;
V_48 -> V_64 = 0 ;
V_48 -> V_65 = NULL ;
V_48 -> V_66 = NULL ;
V_48 -> V_67 = V_49 -> V_68 ;
V_48 -> V_69 = ~ 0UL ;
V_48 -> V_70 = 0 ;
F_59 ( F_60 ( V_48 ) ) ;
V_48 -> V_71 = V_72 ;
V_56 = & V_48 -> V_71 . V_55 ;
V_57 = NULL ;
V_54 = & V_48 -> V_65 ;
V_58 = F_61 ( V_48 , V_49 ) ;
if ( V_58 )
goto V_42;
V_58 = F_62 ( V_48 , V_49 ) ;
if ( V_58 )
goto V_42;
V_53 = NULL ;
for ( V_51 = V_49 -> V_65 ; V_51 ; V_51 = V_51 -> V_73 ) {
struct V_74 * V_74 ;
if ( V_51 -> V_75 & V_76 ) {
long V_77 = F_63 ( V_51 ) ;
V_48 -> V_78 -= V_77 ;
F_64 ( V_48 , V_51 -> V_75 , V_51 -> V_79 ,
- V_77 ) ;
continue;
}
V_59 = 0 ;
if ( V_51 -> V_75 & V_80 ) {
unsigned long V_81 ;
V_81 = ( V_51 -> V_82 - V_51 -> V_83 ) >> V_84 ;
if ( F_65 ( V_49 , V_81 ) )
goto V_85;
V_59 = V_81 ;
}
V_52 = F_66 ( V_86 , V_8 ) ;
if ( ! V_52 )
goto V_85;
* V_52 = * V_51 ;
F_67 ( & V_52 -> V_87 ) ;
V_61 = F_68 ( F_69 ( V_51 ) ) ;
V_58 = F_70 ( V_61 ) ;
if ( F_71 ( V_61 ) )
goto V_88;
F_72 ( V_52 , V_61 ) ;
V_52 -> V_89 = V_48 ;
if ( F_73 ( V_52 , V_51 ) )
goto V_90;
V_52 -> V_75 &= ~ V_91 ;
V_52 -> V_73 = V_52 -> V_92 = NULL ;
V_74 = V_52 -> V_79 ;
if ( V_74 ) {
struct V_93 * V_93 = V_74 -> V_94 . V_95 -> V_96 ;
struct V_97 * V_98 = V_74 -> V_99 ;
F_74 ( V_74 ) ;
if ( V_52 -> V_75 & V_100 )
F_75 ( & V_93 -> V_101 ) ;
F_76 ( & V_98 -> V_102 ) ;
if ( V_52 -> V_75 & V_103 )
V_98 -> V_104 ++ ;
F_77 ( V_98 ) ;
F_78 ( V_52 , V_51 ) ;
F_79 ( V_98 ) ;
F_80 ( & V_98 -> V_102 ) ;
}
if ( F_81 ( V_52 ) )
F_82 ( V_52 ) ;
* V_54 = V_52 ;
V_54 = & V_52 -> V_73 ;
V_52 -> V_92 = V_53 ;
V_53 = V_52 ;
F_83 ( V_48 , V_52 , V_56 , V_57 ) ;
V_56 = & V_52 -> V_105 . V_106 ;
V_57 = & V_52 -> V_105 ;
V_48 -> V_70 ++ ;
V_58 = F_84 ( V_48 , V_49 , V_51 ) ;
if ( V_52 -> V_107 && V_52 -> V_107 -> V_108 )
V_52 -> V_107 -> V_108 ( V_52 ) ;
if ( V_58 )
goto V_42;
if ( V_74 && F_85 ( V_52 ) )
goto V_42;
}
F_86 ( V_49 , V_48 ) ;
V_58 = 0 ;
V_42:
F_87 ( & V_48 -> V_62 ) ;
F_88 ( V_49 ) ;
F_87 ( & V_49 -> V_62 ) ;
return V_58 ;
V_90:
F_89 ( V_61 ) ;
V_88:
F_10 ( V_86 , V_52 ) ;
V_85:
V_58 = - V_109 ;
F_90 ( V_59 ) ;
goto V_42;
}
static inline int F_91 ( struct V_47 * V_48 )
{
V_48 -> V_110 = F_92 ( V_48 ) ;
if ( F_93 ( ! V_48 -> V_110 ) )
return - V_109 ;
return 0 ;
}
static inline void F_94 ( struct V_47 * V_48 )
{
F_95 ( V_48 , V_48 -> V_110 ) ;
}
static int T_1 F_96 ( char * V_111 )
{
V_112 =
( F_97 ( V_111 , NULL , 0 ) << V_113 ) &
V_114 ;
return 1 ;
}
static void F_98 ( struct V_47 * V_48 )
{
#ifdef F_99
F_100 ( & V_48 -> V_115 ) ;
F_101 ( & V_48 -> V_116 ) ;
#endif
}
static struct V_47 * F_102 ( struct V_47 * V_48 , struct V_5 * V_117 )
{
F_53 ( & V_48 -> V_118 , 1 ) ;
F_53 ( & V_48 -> V_119 , 1 ) ;
F_103 ( & V_48 -> V_62 ) ;
F_67 ( & V_48 -> V_120 ) ;
V_48 -> V_121 = ( V_27 -> V_48 ) ?
( V_27 -> V_48 -> V_121 & V_122 ) : V_112 ;
V_48 -> V_123 = NULL ;
V_48 -> V_124 = 0 ;
memset ( & V_48 -> V_125 , 0 , sizeof( V_48 -> V_125 ) ) ;
F_100 ( & V_48 -> V_126 ) ;
V_48 -> V_67 = V_127 ;
V_48 -> V_69 = ~ 0UL ;
F_98 ( V_48 ) ;
F_104 ( V_48 , V_117 ) ;
if ( F_105 ( ! F_91 ( V_48 ) ) ) {
V_48 -> V_128 = 0 ;
F_106 ( V_48 ) ;
return V_48 ;
}
F_107 ( V_48 ) ;
return NULL ;
}
static void F_108 ( struct V_47 * V_48 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_130 ; V_129 ++ ) {
long V_131 = F_109 ( & V_48 -> V_125 . V_132 [ V_129 ] ) ;
if ( F_93 ( V_131 ) )
F_110 ( V_133 L_3
L_4 , V_48 , V_129 , V_131 ) ;
}
#ifdef F_111
F_112 ( V_48 -> V_134 ) ;
#endif
}
struct V_47 * F_113 ( void )
{
struct V_47 * V_48 ;
V_48 = F_114 () ;
if ( ! V_48 )
return NULL ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
F_115 ( V_48 ) ;
return F_102 ( V_48 , V_27 ) ;
}
void F_116 ( struct V_47 * V_48 )
{
F_19 ( V_48 == & V_135 ) ;
F_94 ( V_48 ) ;
F_117 ( V_48 ) ;
F_118 ( V_48 ) ;
F_108 ( V_48 ) ;
F_107 ( V_48 ) ;
}
void F_119 ( struct V_47 * V_48 )
{
F_120 () ;
if ( F_32 ( & V_48 -> V_118 ) ) {
F_121 ( V_48 ) ;
F_122 ( V_48 ) ;
F_123 ( V_48 ) ;
F_124 ( V_48 ) ;
F_125 ( V_48 ) ;
F_126 ( V_48 , NULL ) ;
if ( ! F_127 ( & V_48 -> V_120 ) ) {
F_128 ( & V_136 ) ;
F_129 ( & V_48 -> V_120 ) ;
F_130 ( & V_136 ) ;
}
if ( V_48 -> V_137 )
F_131 ( V_48 -> V_137 -> V_138 ) ;
F_132 ( V_48 ) ;
}
}
void F_133 ( struct V_47 * V_48 )
{
V_48 -> V_139 ++ ;
}
void F_134 ( struct V_47 * V_48 )
{
V_48 -> V_139 -- ;
if ( ( V_48 -> V_139 == 0 ) && V_48 -> V_140 ) {
F_135 ( V_48 -> V_140 ) ;
V_48 -> V_140 = NULL ;
}
}
void F_126 ( struct V_47 * V_48 , struct V_74 * V_141 )
{
if ( V_141 )
F_74 ( V_141 ) ;
if ( V_48 -> V_140 )
F_135 ( V_48 -> V_140 ) ;
V_48 -> V_140 = V_141 ;
V_48 -> V_139 = 0 ;
}
struct V_74 * F_136 ( struct V_47 * V_48 )
{
struct V_74 * V_140 ;
F_137 ( & V_48 -> V_62 ) ;
V_140 = V_48 -> V_140 ;
if ( V_140 )
F_74 ( V_140 ) ;
F_138 ( & V_48 -> V_62 ) ;
return V_140 ;
}
static void F_139 ( struct V_47 * V_49 , struct V_47 * V_142 )
{
V_142 -> V_140 = F_136 ( V_49 ) ;
}
struct V_47 * F_140 ( struct V_5 * V_143 )
{
struct V_47 * V_48 ;
F_141 ( V_143 ) ;
V_48 = V_143 -> V_48 ;
if ( V_48 ) {
if ( V_143 -> V_121 & V_144 )
V_48 = NULL ;
else
F_142 ( & V_48 -> V_118 ) ;
}
F_143 ( V_143 ) ;
return V_48 ;
}
struct V_47 * F_144 ( struct V_5 * V_143 , unsigned int V_145 )
{
struct V_47 * V_48 ;
int V_41 ;
V_41 = F_145 ( & V_143 -> signal -> V_146 ) ;
if ( V_41 )
return F_146 ( V_41 ) ;
V_48 = F_140 ( V_143 ) ;
if ( V_48 && V_48 != V_27 -> V_48 &&
! F_147 ( V_143 , V_145 ) ) {
F_119 ( V_48 ) ;
V_48 = F_146 ( - V_147 ) ;
}
F_80 ( & V_143 -> signal -> V_146 ) ;
return V_48 ;
}
static void F_148 ( struct V_5 * V_9 )
{
struct V_148 * V_149 ;
F_141 ( V_9 ) ;
V_149 = V_9 -> V_150 ;
if ( F_105 ( V_149 ) ) {
V_9 -> V_150 = NULL ;
F_149 ( V_149 ) ;
}
F_143 ( V_9 ) ;
}
static int F_150 ( struct V_5 * V_151 ,
struct V_148 * V_149 )
{
int V_152 ;
F_151 () ;
V_152 = F_152 ( V_149 ) ;
F_153 () ;
if ( V_152 ) {
F_141 ( V_151 ) ;
V_151 -> V_150 = NULL ;
F_143 ( V_151 ) ;
}
F_154 ( V_151 ) ;
return V_152 ;
}
void F_155 ( struct V_5 * V_9 , struct V_47 * V_48 )
{
#ifdef F_156
if ( F_93 ( V_9 -> V_153 ) ) {
F_157 ( V_9 ) ;
V_9 -> V_153 = NULL ;
}
#ifdef F_158
if ( F_93 ( V_9 -> V_154 ) ) {
F_159 ( V_9 ) ;
V_9 -> V_154 = NULL ;
}
#endif
if ( F_93 ( ! F_127 ( & V_9 -> V_155 ) ) )
F_160 ( V_9 ) ;
#endif
F_161 ( V_9 ) ;
F_162 ( V_9 , V_48 ) ;
if ( V_9 -> V_156 ) {
if ( ! ( V_9 -> V_121 & V_157 ) &&
F_35 ( & V_48 -> V_118 ) > 1 ) {
F_163 ( 0 , V_9 -> V_156 ) ;
F_164 ( V_9 -> V_156 , V_158 ,
1 , NULL , NULL , 0 ) ;
}
V_9 -> V_156 = NULL ;
}
if ( V_9 -> V_150 )
F_148 ( V_9 ) ;
}
struct V_47 * F_165 ( struct V_5 * V_9 )
{
struct V_47 * V_48 , * V_49 = V_27 -> V_48 ;
int V_41 ;
if ( ! V_49 )
return NULL ;
V_48 = F_114 () ;
if ( ! V_48 )
goto V_85;
memcpy ( V_48 , V_49 , sizeof( * V_48 ) ) ;
F_115 ( V_48 ) ;
#ifdef F_111
V_48 -> V_134 = NULL ;
#endif
F_166 ( V_48 ) ;
if ( ! F_102 ( V_48 , V_9 ) )
goto V_85;
if ( F_167 ( V_9 , V_48 ) )
goto V_159;
F_139 ( V_49 , V_48 ) ;
V_41 = F_55 ( V_48 , V_49 ) ;
if ( V_41 )
goto V_160;
V_48 -> V_161 = F_168 ( V_48 ) ;
V_48 -> V_162 = V_48 -> V_78 ;
if ( V_48 -> V_137 && ! F_169 ( V_48 -> V_137 -> V_138 ) )
goto V_160;
return V_48 ;
V_160:
V_48 -> V_137 = NULL ;
F_119 ( V_48 ) ;
V_85:
return NULL ;
V_159:
F_94 ( V_48 ) ;
F_107 ( V_48 ) ;
return NULL ;
}
static int F_170 ( unsigned long V_163 , struct V_5 * V_9 )
{
struct V_47 * V_48 , * V_49 ;
int V_58 ;
V_9 -> V_164 = V_9 -> V_165 = 0 ;
V_9 -> V_166 = V_9 -> V_167 = 0 ;
#ifdef F_171
V_9 -> V_168 = V_9 -> V_166 + V_9 -> V_167 ;
#endif
V_9 -> V_48 = NULL ;
V_9 -> V_169 = NULL ;
V_49 = V_27 -> V_48 ;
if ( ! V_49 )
return 0 ;
if ( V_163 & V_170 ) {
F_142 ( & V_49 -> V_118 ) ;
V_48 = V_49 ;
goto V_171;
}
V_58 = - V_109 ;
V_48 = F_165 ( V_9 ) ;
if ( ! V_48 )
goto V_85;
V_171:
V_9 -> V_48 = V_48 ;
V_9 -> V_169 = V_48 ;
return 0 ;
V_85:
return V_58 ;
}
static int F_172 ( unsigned long V_163 , struct V_5 * V_9 )
{
struct V_172 * V_173 = V_27 -> V_173 ;
if ( V_163 & V_174 ) {
F_128 ( & V_173 -> V_175 ) ;
if ( V_173 -> V_176 ) {
F_130 ( & V_173 -> V_175 ) ;
return - V_177 ;
}
V_173 -> V_178 ++ ;
F_130 ( & V_173 -> V_175 ) ;
return 0 ;
}
V_9 -> V_173 = F_173 ( V_173 ) ;
if ( ! V_9 -> V_173 )
return - V_109 ;
return 0 ;
}
static int F_174 ( unsigned long V_163 , struct V_5 * V_9 )
{
struct V_179 * V_180 , * V_181 ;
int error = 0 ;
V_180 = V_27 -> V_182 ;
if ( ! V_180 )
goto V_42;
if ( V_163 & V_183 ) {
F_142 ( & V_180 -> V_132 ) ;
goto V_42;
}
V_181 = F_175 ( V_180 , & error ) ;
if ( ! V_181 )
goto V_42;
V_9 -> V_182 = V_181 ;
error = 0 ;
V_42:
return error ;
}
static int F_176 ( unsigned long V_163 , struct V_5 * V_9 )
{
#ifdef F_177
struct V_184 * V_185 = V_27 -> V_184 ;
struct V_184 * V_186 ;
if ( ! V_185 )
return 0 ;
if ( V_163 & V_187 ) {
F_178 ( V_185 ) ;
V_9 -> V_184 = V_185 ;
} else if ( F_179 ( V_185 -> V_188 ) ) {
V_186 = F_180 ( V_9 , V_8 , V_189 ) ;
if ( F_93 ( ! V_186 ) )
return - V_109 ;
V_186 -> V_188 = V_185 -> V_188 ;
F_181 ( V_186 ) ;
}
#endif
return 0 ;
}
static int F_182 ( unsigned long V_163 , struct V_5 * V_9 )
{
struct V_190 * V_22 ;
if ( V_163 & V_191 ) {
F_142 ( & V_27 -> V_192 -> V_132 ) ;
return 0 ;
}
V_22 = F_66 ( V_193 , V_8 ) ;
F_183 ( V_9 -> V_192 , V_22 ) ;
if ( ! V_22 )
return - V_109 ;
F_53 ( & V_22 -> V_132 , 1 ) ;
memcpy ( V_22 -> V_194 , V_27 -> V_192 -> V_194 , sizeof( V_22 -> V_194 ) ) ;
return 0 ;
}
void F_184 ( struct V_190 * V_192 )
{
if ( F_32 ( & V_192 -> V_132 ) ) {
F_185 ( V_192 ) ;
F_10 ( V_193 , V_192 ) ;
}
}
static void F_186 ( struct V_21 * V_22 )
{
unsigned long V_195 ;
F_187 ( V_22 ) ;
V_195 = F_188 ( V_22 -> V_34 [ V_196 ] . V_36 ) ;
if ( V_195 != V_197 ) {
V_22 -> V_198 . V_199 = F_189 ( V_195 ) ;
V_22 -> V_200 . V_201 = 1 ;
}
F_67 ( & V_22 -> V_202 [ 0 ] ) ;
F_67 ( & V_22 -> V_202 [ 1 ] ) ;
F_67 ( & V_22 -> V_202 [ 2 ] ) ;
}
static int F_190 ( unsigned long V_163 , struct V_5 * V_9 )
{
struct V_21 * V_22 ;
if ( V_163 & V_203 )
return 0 ;
V_22 = F_191 ( V_23 , V_8 ) ;
V_9 -> signal = V_22 ;
if ( ! V_22 )
return - V_109 ;
V_22 -> V_204 = 1 ;
F_53 ( & V_22 -> V_205 , 1 ) ;
F_53 ( & V_22 -> V_24 , 1 ) ;
F_192 ( & V_22 -> V_206 ) ;
if ( V_163 & V_207 )
V_22 -> V_121 |= V_208 ;
V_22 -> V_209 = V_9 ;
F_193 ( & V_22 -> V_210 ) ;
F_67 ( & V_22 -> V_211 ) ;
F_194 ( & V_22 -> V_212 , V_213 , V_214 ) ;
V_22 -> V_212 . V_215 = V_216 ;
F_141 ( V_27 -> V_217 ) ;
memcpy ( V_22 -> V_34 , V_27 -> signal -> V_34 , sizeof V_22 -> V_34 ) ;
F_143 ( V_27 -> V_217 ) ;
F_186 ( V_22 ) ;
F_195 ( V_22 ) ;
F_196 ( V_22 ) ;
#ifdef F_197
F_103 ( & V_22 -> V_218 ) ;
#endif
V_22 -> V_219 = V_27 -> signal -> V_219 ;
V_22 -> V_220 = V_27 -> signal -> V_220 ;
V_22 -> V_221 = V_27 -> signal -> V_221 ;
V_22 -> V_222 = V_27 -> signal -> V_222 ||
V_27 -> signal -> V_223 ;
F_198 ( & V_22 -> V_146 ) ;
return 0 ;
}
static void F_199 ( unsigned long V_163 , struct V_5 * V_117 )
{
unsigned long V_224 = V_117 -> V_121 ;
V_224 &= ~ ( V_225 | V_226 ) ;
V_224 |= V_227 ;
V_117 -> V_121 = V_224 ;
}
static void F_200 ( struct V_5 * V_117 )
{
F_201 ( & V_117 -> V_228 ) ;
#ifdef F_202
F_203 ( & V_117 -> V_229 ) ;
V_117 -> V_230 = NULL ;
#endif
}
void F_104 ( struct V_47 * V_48 , struct V_5 * V_117 )
{
V_48 -> V_231 = V_117 ;
}
static void F_204 ( struct V_5 * V_9 )
{
V_9 -> V_198 . V_199 = 0 ;
V_9 -> V_198 . V_232 = 0 ;
V_9 -> V_198 . V_233 = 0 ;
F_67 ( & V_9 -> V_202 [ 0 ] ) ;
F_67 ( & V_9 -> V_202 [ 1 ] ) ;
F_67 ( & V_9 -> V_202 [ 2 ] ) ;
}
static struct V_5 * F_205 ( unsigned long V_163 ,
unsigned long V_234 ,
struct V_235 * V_236 ,
unsigned long V_237 ,
int T_2 * V_238 ,
struct V_239 * V_239 ,
int V_240 )
{
int V_58 ;
struct V_5 * V_117 ;
int V_241 = 0 ;
if ( ( V_163 & ( V_242 | V_174 ) ) == ( V_242 | V_174 ) )
return F_146 ( - V_243 ) ;
if ( ( V_163 & V_203 ) && ! ( V_163 & V_191 ) )
return F_146 ( - V_243 ) ;
if ( ( V_163 & V_191 ) && ! ( V_163 & V_170 ) )
return F_146 ( - V_243 ) ;
if ( ( V_163 & V_244 ) &&
V_27 -> signal -> V_121 & V_208 )
return F_146 ( - V_243 ) ;
V_58 = F_206 ( V_163 ) ;
if ( V_58 )
goto V_245;
V_58 = - V_109 ;
V_117 = F_44 ( V_27 ) ;
if ( ! V_117 )
goto V_245;
F_207 ( V_117 ) ;
F_208 ( V_117 ) ;
F_200 ( V_117 ) ;
#ifdef F_209
F_210 ( ! V_117 -> V_246 ) ;
F_210 ( ! V_117 -> V_247 ) ;
#endif
V_58 = - V_177 ;
if ( F_35 ( & V_117 -> V_248 -> V_249 -> V_250 ) >=
F_211 ( V_117 , V_35 ) ) {
if ( ! F_212 ( V_251 ) && ! F_212 ( V_252 ) &&
V_117 -> V_248 -> V_249 != V_253 )
goto V_254;
}
V_27 -> V_121 &= ~ V_255 ;
V_58 = F_213 ( V_117 , V_163 ) ;
if ( V_58 < 0 )
goto V_254;
V_58 = - V_177 ;
if ( V_204 >= V_31 )
goto V_256;
if ( ! F_169 ( F_214 ( V_117 ) -> V_257 -> V_138 ) )
goto V_256;
V_117 -> V_258 = 0 ;
F_215 ( V_117 ) ;
F_199 ( V_163 , V_117 ) ;
F_67 ( & V_117 -> V_259 ) ;
F_67 ( & V_117 -> V_260 ) ;
F_216 ( V_117 ) ;
V_117 -> V_150 = NULL ;
F_100 ( & V_117 -> V_261 ) ;
F_193 ( & V_117 -> V_262 ) ;
V_117 -> V_263 = V_117 -> V_264 = V_117 -> V_265 = 0 ;
V_117 -> V_266 = V_117 -> V_267 = 0 ;
#ifndef F_217
V_117 -> V_268 = V_117 -> V_269 = 0 ;
#endif
#if F_218 ( V_270 )
memset ( & V_117 -> V_125 , 0 , sizeof( V_117 -> V_125 ) ) ;
#endif
V_117 -> V_271 = V_27 -> V_272 ;
F_219 ( & V_117 -> V_273 ) ;
F_220 ( V_117 ) ;
F_204 ( V_117 ) ;
F_221 ( & V_117 -> V_274 ) ;
V_117 -> V_275 = V_117 -> V_274 ;
F_222 ( & V_117 -> V_275 ) ;
V_117 -> V_184 = NULL ;
V_117 -> V_276 = NULL ;
if ( V_163 & V_203 )
F_223 ( V_27 ) ;
F_224 ( V_117 ) ;
#ifdef F_225
V_117 -> V_60 = F_68 ( V_117 -> V_60 ) ;
if ( F_71 ( V_117 -> V_60 ) ) {
V_58 = F_70 ( V_117 -> V_60 ) ;
V_117 -> V_60 = NULL ;
goto V_277;
}
F_226 ( V_117 ) ;
#endif
#ifdef F_227
V_117 -> V_278 = V_189 ;
V_117 -> V_279 = V_189 ;
F_228 ( & V_117 -> V_280 ) ;
#endif
#ifdef F_229
V_117 -> V_281 = 0 ;
#ifdef F_230
V_117 -> V_246 = 1 ;
#else
V_117 -> V_246 = 0 ;
#endif
V_117 -> V_282 = 0 ;
V_117 -> V_283 = 0 ;
V_117 -> V_284 = V_285 ;
V_117 -> V_286 = 0 ;
V_117 -> V_247 = 1 ;
V_117 -> V_287 = V_285 ;
V_117 -> V_288 = 0 ;
V_117 -> V_289 = 0 ;
V_117 -> V_290 = 0 ;
V_117 -> V_291 = 0 ;
V_117 -> V_292 = 0 ;
#endif
#ifdef F_231
V_117 -> V_293 = 0 ;
V_117 -> V_294 = 0 ;
V_117 -> V_295 = 0 ;
#endif
#ifdef F_232
V_117 -> V_296 = NULL ;
#endif
#ifdef F_233
V_117 -> V_297 . V_298 = 0 ;
V_117 -> V_297 . V_299 = NULL ;
#endif
F_234 ( V_117 ) ;
V_58 = F_235 ( V_117 ) ;
if ( V_58 )
goto V_300;
V_58 = F_236 ( V_117 ) ;
if ( V_58 )
goto V_300;
V_58 = F_237 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_301;
V_58 = F_174 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_302;
V_58 = F_172 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_303;
V_58 = F_182 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_304;
V_58 = F_190 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_305;
V_58 = F_170 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_306;
V_58 = F_238 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_307;
V_58 = F_176 ( V_163 , V_117 ) ;
if ( V_58 )
goto V_308;
V_58 = F_239 ( V_163 , V_234 , V_237 , V_117 , V_236 ) ;
if ( V_58 )
goto V_309;
if ( V_239 != & V_310 ) {
V_58 = - V_109 ;
V_239 = F_240 ( V_117 -> V_311 -> V_312 ) ;
if ( ! V_239 )
goto V_309;
}
V_117 -> V_239 = F_241 ( V_239 ) ;
V_117 -> V_313 = V_117 -> V_239 ;
if ( V_163 & V_203 )
V_117 -> V_313 = V_27 -> V_313 ;
V_117 -> V_314 = ( V_163 & V_315 ) ? V_238 : NULL ;
V_117 -> V_156 = ( V_163 & V_316 ) ? V_238 : NULL ;
#ifdef F_177
V_117 -> V_317 = NULL ;
#endif
#ifdef F_156
V_117 -> V_153 = NULL ;
#ifdef F_158
V_117 -> V_154 = NULL ;
#endif
F_67 ( & V_117 -> V_155 ) ;
V_117 -> V_318 = NULL ;
#endif
F_242 ( V_117 ) ;
if ( ( V_163 & ( V_170 | V_319 ) ) == V_170 )
V_117 -> V_320 = V_117 -> V_321 = 0 ;
F_243 ( V_117 ) ;
F_244 ( V_117 , V_322 ) ;
#ifdef F_245
F_244 ( V_117 , F_245 ) ;
#endif
F_246 ( V_117 ) ;
if ( V_163 & V_203 )
V_117 -> V_323 = - 1 ;
else if ( V_163 & V_244 )
V_117 -> V_323 = V_27 -> V_217 -> V_323 ;
else
V_117 -> V_323 = ( V_163 & V_324 ) ;
V_117 -> V_325 = 0 ;
V_117 -> V_25 = 0 ;
V_117 -> V_326 = 0 ;
V_117 -> V_327 = 128 >> ( V_84 - 10 ) ;
V_117 -> V_328 = 0 ;
V_117 -> V_217 = V_117 ;
F_67 ( & V_117 -> V_329 ) ;
F_101 ( & V_117 -> V_330 ) ;
F_247 ( V_117 ) ;
V_241 = 1 ;
F_248 ( & V_1 ) ;
if ( V_163 & ( V_244 | V_203 ) ) {
V_117 -> V_331 = V_27 -> V_331 ;
V_117 -> V_332 = V_27 -> V_332 ;
} else {
V_117 -> V_331 = V_27 ;
V_117 -> V_332 = V_27 -> V_333 ;
}
F_128 ( & V_27 -> V_192 -> V_334 ) ;
F_249 () ;
if ( F_250 ( V_27 ) ) {
F_130 ( & V_27 -> V_192 -> V_334 ) ;
F_251 ( & V_1 ) ;
V_58 = - V_335 ;
goto V_336;
}
if ( V_163 & V_203 ) {
V_27 -> signal -> V_204 ++ ;
F_142 ( & V_27 -> signal -> V_205 ) ;
F_142 ( & V_27 -> signal -> V_24 ) ;
V_117 -> V_217 = V_27 -> V_217 ;
F_252 ( & V_117 -> V_329 , & V_117 -> V_217 -> V_329 ) ;
}
if ( F_105 ( V_117 -> V_239 ) ) {
F_253 ( V_117 , ( V_163 & V_337 ) || V_240 ) ;
if ( F_254 ( V_117 ) ) {
if ( F_255 ( V_239 ) )
V_117 -> V_311 -> V_312 -> V_338 = V_117 ;
V_117 -> signal -> V_339 = V_239 ;
V_117 -> signal -> V_340 = F_256 ( V_27 -> signal -> V_340 ) ;
F_257 ( V_117 , V_341 , F_258 ( V_27 ) ) ;
F_257 ( V_117 , V_342 , F_259 ( V_27 ) ) ;
F_260 ( & V_117 -> V_260 , & V_117 -> V_331 -> V_259 ) ;
F_252 ( & V_117 -> V_343 , & V_33 . V_343 ) ;
F_261 ( V_4 ) ;
}
F_257 ( V_117 , V_344 , V_239 ) ;
V_204 ++ ;
}
V_345 ++ ;
F_130 ( & V_27 -> V_192 -> V_334 ) ;
F_251 ( & V_1 ) ;
F_262 ( V_117 ) ;
F_263 ( V_117 ) ;
if ( V_163 & V_203 )
F_264 ( V_27 ) ;
F_265 ( V_117 ) ;
F_266 ( V_117 , V_163 ) ;
return V_117 ;
V_336:
if ( V_239 != & V_310 )
F_267 ( V_239 ) ;
V_309:
if ( V_117 -> V_184 )
F_268 ( V_117 ) ;
V_308:
if ( F_93 ( V_163 & V_207 ) )
F_269 ( V_117 -> V_311 -> V_312 ) ;
F_270 ( V_117 ) ;
V_307:
if ( V_117 -> V_48 )
F_119 ( V_117 -> V_48 ) ;
V_306:
if ( ! ( V_163 & V_203 ) )
F_28 ( V_117 -> signal ) ;
V_305:
F_184 ( V_117 -> V_192 ) ;
V_304:
F_271 ( V_117 ) ;
V_303:
F_272 ( V_117 ) ;
V_302:
F_273 ( V_117 ) ;
V_301:
F_274 ( V_117 ) ;
V_300:
F_275 ( V_117 ) ;
#ifdef F_225
F_89 ( V_117 -> V_60 ) ;
V_277:
#endif
if ( V_163 & V_203 )
F_264 ( V_27 ) ;
F_276 ( V_117 , V_241 ) ;
F_38 ( V_117 ) ;
F_131 ( F_214 ( V_117 ) -> V_257 -> V_138 ) ;
V_256:
F_75 ( & V_117 -> V_346 -> V_249 -> V_250 ) ;
F_37 ( V_117 ) ;
V_254:
F_24 ( V_117 ) ;
V_245:
return F_146 ( V_58 ) ;
}
static inline void F_277 ( struct V_347 * V_348 )
{
enum V_349 type ;
for ( type = V_344 ; type < V_350 ; ++ type ) {
F_278 ( & V_348 [ type ] . V_6 ) ;
V_348 [ type ] . V_239 = & V_310 ;
}
}
struct V_5 * T_3 F_279 ( int V_2 )
{
struct V_5 * V_143 ;
struct V_235 V_236 ;
V_143 = F_205 ( V_170 , 0 , F_280 ( & V_236 ) , 0 , NULL ,
& V_310 , 0 ) ;
if ( ! F_71 ( V_143 ) ) {
F_277 ( V_143 -> V_351 ) ;
F_281 ( V_143 , V_2 ) ;
}
return V_143 ;
}
long F_282 ( unsigned long V_163 ,
unsigned long V_234 ,
struct V_235 * V_236 ,
unsigned long V_237 ,
int T_2 * V_352 ,
int T_2 * V_238 )
{
struct V_5 * V_117 ;
int V_240 = 0 ;
long V_353 ;
if ( V_163 & V_354 ) {
if ( V_163 & V_203 )
return - V_243 ;
if ( ! F_212 ( V_251 ) || ! F_212 ( V_355 ) ||
! F_212 ( V_356 ) )
return - V_357 ;
}
if ( F_105 ( F_283 ( V_236 ) ) && ! ( V_163 & V_358 ) ) {
if ( V_163 & V_319 )
V_240 = V_359 ;
else if ( ( V_163 & V_324 ) != V_360 )
V_240 = V_361 ;
else
V_240 = V_362 ;
if ( F_105 ( ! F_284 ( V_27 , V_240 ) ) )
V_240 = 0 ;
}
V_117 = F_205 ( V_163 , V_234 , V_236 , V_237 ,
V_238 , NULL , V_240 ) ;
if ( ! F_71 ( V_117 ) ) {
struct V_148 V_149 ;
F_285 ( V_27 , V_117 ) ;
V_353 = F_286 ( V_117 ) ;
if ( V_163 & V_363 )
F_163 ( V_353 , V_352 ) ;
if ( V_163 & V_319 ) {
V_117 -> V_150 = & V_149 ;
F_287 ( & V_149 ) ;
F_288 ( V_117 ) ;
}
F_289 ( V_117 ) ;
if ( F_93 ( V_240 ) )
F_290 ( V_240 , V_353 ) ;
if ( V_163 & V_319 ) {
if ( ! F_150 ( V_117 , & V_149 ) )
F_290 ( V_364 , V_353 ) ;
}
} else {
V_353 = F_70 ( V_117 ) ;
}
return V_353 ;
}
static void F_291 ( void * V_365 )
{
struct V_190 * V_192 = V_365 ;
F_100 ( & V_192 -> V_334 ) ;
F_192 ( & V_192 -> V_366 ) ;
}
void T_1 F_292 ( void )
{
V_193 = F_18 ( L_5 ,
sizeof( struct V_190 ) , 0 ,
V_367 | V_29 | V_368 |
V_30 , F_291 ) ;
V_23 = F_18 ( L_6 ,
sizeof( struct V_21 ) , 0 ,
V_367 | V_29 | V_30 , NULL ) ;
V_369 = F_18 ( L_7 ,
sizeof( struct V_179 ) , 0 ,
V_367 | V_29 | V_30 , NULL ) ;
V_370 = F_18 ( L_8 ,
sizeof( struct V_172 ) , 0 ,
V_367 | V_29 | V_30 , NULL ) ;
V_371 = F_18 ( L_9 ,
sizeof( struct V_47 ) , V_372 ,
V_367 | V_29 | V_30 , NULL ) ;
V_86 = F_293 ( V_50 , V_29 ) ;
F_294 () ;
F_295 () ;
}
static int F_296 ( unsigned long V_373 )
{
if ( V_373 & ~ ( V_203 | V_174 | V_242 | V_191 |
V_170 | V_183 | V_374 |
V_375 | V_376 | V_377 ) )
return - V_243 ;
if ( V_373 & ( V_203 | V_191 | V_170 ) ) {
if ( F_35 ( & V_27 -> V_48 -> V_118 ) > 1 )
return - V_243 ;
}
return 0 ;
}
static int F_297 ( unsigned long V_373 , struct V_172 * * V_378 )
{
struct V_172 * V_173 = V_27 -> V_173 ;
if ( ! ( V_373 & V_174 ) || ! V_173 )
return 0 ;
if ( V_173 -> V_178 == 1 )
return 0 ;
* V_378 = F_173 ( V_173 ) ;
if ( ! * V_378 )
return - V_109 ;
return 0 ;
}
static int F_298 ( unsigned long V_373 , struct V_179 * * V_379 )
{
struct V_179 * V_380 = V_27 -> V_182 ;
int error = 0 ;
if ( ( V_373 & V_183 ) &&
( V_380 && F_35 ( & V_380 -> V_132 ) > 1 ) ) {
* V_379 = F_175 ( V_380 , & error ) ;
if ( ! * V_379 )
return error ;
}
return 0 ;
}
int F_299 ( struct V_179 * * V_381 )
{
struct V_5 * V_143 = V_27 ;
struct V_179 * V_382 = NULL ;
int error ;
error = F_298 ( V_183 , & V_382 ) ;
if ( error || ! V_382 ) {
* V_381 = NULL ;
return error ;
}
* V_381 = V_143 -> V_182 ;
F_141 ( V_143 ) ;
V_143 -> V_182 = V_382 ;
F_143 ( V_143 ) ;
return 0 ;
}
