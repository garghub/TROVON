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
V_63 -> V_83 &= ~ V_94 ;
V_63 -> V_81 = V_63 -> V_95 = NULL ;
V_82 = V_63 -> V_85 ;
if ( V_82 ) {
struct V_96 * V_96 = F_79 ( V_82 ) ;
struct V_97 * V_98 = V_82 -> V_99 ;
F_80 ( V_82 ) ;
if ( V_63 -> V_83 & V_100 )
F_81 ( & V_96 -> V_101 ) ;
F_82 ( V_98 ) ;
if ( V_63 -> V_83 & V_102 )
F_83 ( & V_98 -> V_103 ) ;
F_84 ( V_98 ) ;
F_85 ( V_63 , V_62 ,
& V_98 -> V_104 ) ;
F_86 ( V_98 ) ;
F_87 ( V_98 ) ;
}
if ( F_88 ( V_63 ) )
F_89 ( V_63 ) ;
* V_65 = V_63 ;
V_65 = & V_63 -> V_81 ;
V_63 -> V_95 = V_64 ;
V_64 = V_63 ;
F_90 ( V_59 , V_63 , V_67 , V_68 ) ;
V_67 = & V_63 -> V_105 . V_106 ;
V_68 = & V_63 -> V_105 ;
V_59 -> V_107 ++ ;
V_69 = F_91 ( V_59 , V_60 , V_62 ) ;
if ( V_63 -> V_108 && V_63 -> V_108 -> V_109 )
V_63 -> V_108 -> V_109 ( V_63 ) ;
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
V_69 = - V_110 ;
F_98 ( V_70 ) ;
goto V_80;
}
static inline int F_99 ( struct V_58 * V_59 )
{
V_59 -> V_111 = F_100 ( V_59 ) ;
if ( F_101 ( ! V_59 -> V_111 ) )
return - V_110 ;
return 0 ;
}
static inline void F_102 ( struct V_58 * V_59 )
{
F_103 ( V_59 , V_59 -> V_111 ) ;
}
static int F_62 ( struct V_58 * V_59 , struct V_58 * V_60 )
{
F_64 ( & V_60 -> V_71 ) ;
F_68 ( V_59 -> V_73 , F_69 ( V_60 ) ) ;
F_93 ( & V_60 -> V_71 ) ;
return 0 ;
}
static int T_1 F_104 ( char * V_112 )
{
V_113 =
( F_105 ( V_112 , NULL , 0 ) << V_114 ) &
V_115 ;
return 1 ;
}
static void F_106 ( struct V_58 * V_59 )
{
#ifdef F_107
F_108 ( & V_59 -> V_116 ) ;
V_59 -> V_117 = NULL ;
#endif
}
static void F_109 ( struct V_58 * V_59 , struct V_5 * V_118 )
{
#ifdef F_110
V_59 -> V_119 = V_118 ;
#endif
}
static struct V_58 * F_111 ( struct V_58 * V_59 , struct V_5 * V_118 )
{
V_59 -> V_79 = NULL ;
V_59 -> V_78 = V_120 ;
V_59 -> V_121 = 0 ;
F_60 ( & V_59 -> V_122 , 1 ) ;
F_60 ( & V_59 -> V_123 , 1 ) ;
F_112 ( & V_59 -> V_71 ) ;
F_76 ( & V_59 -> V_124 ) ;
V_59 -> V_125 = NULL ;
F_113 ( & V_59 -> V_126 , 0 ) ;
F_114 ( V_59 ) ;
V_59 -> V_107 = 0 ;
V_59 -> V_127 = 0 ;
V_59 -> V_128 = 0 ;
memset ( & V_59 -> V_129 , 0 , sizeof( V_59 -> V_129 ) ) ;
F_108 ( & V_59 -> V_130 ) ;
F_115 ( V_59 ) ;
F_106 ( V_59 ) ;
F_109 ( V_59 , V_118 ) ;
F_116 ( V_59 ) ;
F_117 ( V_59 ) ;
#if F_118 ( V_131 ) && ! V_132
V_59 -> V_133 = NULL ;
#endif
if ( V_27 -> V_59 ) {
V_59 -> V_134 = V_27 -> V_59 -> V_134 & V_135 ;
V_59 -> V_136 = V_27 -> V_59 -> V_136 & V_137 ;
} else {
V_59 -> V_134 = V_113 ;
V_59 -> V_136 = 0 ;
}
if ( F_99 ( V_59 ) )
goto V_138;
if ( F_119 ( V_118 , V_59 ) )
goto V_139;
return V_59 ;
V_139:
F_102 ( V_59 ) ;
V_138:
F_120 ( V_59 ) ;
return NULL ;
}
static void F_121 ( struct V_58 * V_59 )
{
int V_140 ;
for ( V_140 = 0 ; V_140 < V_141 ; V_140 ++ ) {
long V_142 = F_122 ( & V_59 -> V_129 . V_143 [ V_140 ] ) ;
if ( F_101 ( V_142 ) )
F_123 ( V_144 L_3
L_4 , V_59 , V_140 , V_142 ) ;
}
if ( F_122 ( & V_59 -> V_126 ) )
F_124 ( L_5 ,
F_122 ( & V_59 -> V_126 ) ) ;
if ( F_125 ( V_59 ) )
F_124 ( L_6 ,
F_125 ( V_59 ) ) ;
#if F_118 ( V_131 ) && ! V_132
F_126 ( V_59 -> V_133 , V_59 ) ;
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
F_19 ( V_59 == & V_145 ) ;
F_102 ( V_59 ) ;
F_130 ( V_59 ) ;
F_131 ( V_59 ) ;
F_121 ( V_59 ) ;
F_120 ( V_59 ) ;
}
void F_132 ( struct V_58 * V_59 )
{
F_133 () ;
if ( F_32 ( & V_59 -> V_122 ) ) {
F_134 ( V_59 ) ;
F_135 ( V_59 ) ;
F_136 ( V_59 ) ;
F_137 ( V_59 ) ;
F_138 ( V_59 ) ;
F_139 ( V_59 , NULL ) ;
if ( ! F_140 ( & V_59 -> V_124 ) ) {
F_141 ( & V_146 ) ;
F_142 ( & V_59 -> V_124 ) ;
F_143 ( & V_146 ) ;
}
if ( V_59 -> V_147 )
F_144 ( V_59 -> V_147 -> V_148 ) ;
F_145 ( V_59 ) ;
}
}
void F_139 ( struct V_58 * V_59 , struct V_82 * V_149 )
{
struct V_82 * V_150 ;
V_150 = F_146 ( V_59 -> V_73 ) ;
if ( V_149 )
F_80 ( V_149 ) ;
F_147 ( V_59 -> V_73 , V_149 ) ;
if ( V_150 )
F_148 ( V_150 ) ;
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
struct V_58 * F_153 ( struct V_5 * V_151 )
{
struct V_58 * V_59 ;
F_154 ( V_151 ) ;
V_59 = V_151 -> V_59 ;
if ( V_59 ) {
if ( V_151 -> V_134 & V_152 )
V_59 = NULL ;
else
F_83 ( & V_59 -> V_122 ) ;
}
F_155 ( V_151 ) ;
return V_59 ;
}
struct V_58 * F_156 ( struct V_5 * V_151 , unsigned int V_153 )
{
struct V_58 * V_59 ;
int V_49 ;
V_49 = F_157 ( & V_151 -> signal -> V_154 ) ;
if ( V_49 )
return F_158 ( V_49 ) ;
V_59 = F_153 ( V_151 ) ;
if ( V_59 && V_59 != V_27 -> V_59 &&
! F_159 ( V_151 , V_153 ) ) {
F_132 ( V_59 ) ;
V_59 = F_158 ( - V_155 ) ;
}
F_160 ( & V_151 -> signal -> V_154 ) ;
return V_59 ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_156 * V_157 ;
F_154 ( V_6 ) ;
V_157 = V_6 -> V_158 ;
if ( F_162 ( V_157 ) ) {
V_6 -> V_158 = NULL ;
F_163 ( V_157 ) ;
}
F_155 ( V_6 ) ;
}
static int F_164 ( struct V_5 * V_159 ,
struct V_156 * V_157 )
{
int V_160 ;
F_165 () ;
V_160 = F_166 ( V_157 ) ;
F_167 () ;
if ( V_160 ) {
F_154 ( V_159 ) ;
V_159 -> V_158 = NULL ;
F_155 ( V_159 ) ;
}
F_168 ( V_159 ) ;
return V_160 ;
}
void F_169 ( struct V_5 * V_6 , struct V_58 * V_59 )
{
#ifdef F_170
if ( F_101 ( V_6 -> V_161 ) ) {
F_171 ( V_6 ) ;
V_6 -> V_161 = NULL ;
}
#ifdef F_172
if ( F_101 ( V_6 -> V_162 ) ) {
F_173 ( V_6 ) ;
V_6 -> V_162 = NULL ;
}
#endif
if ( F_101 ( ! F_140 ( & V_6 -> V_163 ) ) )
F_174 ( V_6 ) ;
#endif
F_175 ( V_6 ) ;
F_176 ( V_6 , V_59 ) ;
if ( V_6 -> V_164 ) {
if ( ! ( V_6 -> V_134 & V_165 ) &&
F_35 ( & V_59 -> V_122 ) > 1 ) {
F_177 ( 0 , V_6 -> V_164 ) ;
F_178 ( V_6 -> V_164 , V_166 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_164 = NULL ;
}
if ( V_6 -> V_158 )
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
goto V_167;
V_59 -> V_168 = F_180 ( V_59 ) ;
V_59 -> V_169 = V_59 -> V_74 ;
if ( V_59 -> V_147 && ! F_181 ( V_59 -> V_147 -> V_148 ) )
goto V_167;
return V_59 ;
V_167:
V_59 -> V_147 = NULL ;
F_132 ( V_59 ) ;
V_88:
return NULL ;
}
static int F_182 ( unsigned long V_170 , struct V_5 * V_6 )
{
struct V_58 * V_59 , * V_60 ;
int V_69 ;
V_6 -> V_171 = V_6 -> V_172 = 0 ;
V_6 -> V_173 = V_6 -> V_174 = 0 ;
#ifdef F_183
V_6 -> V_175 = V_6 -> V_173 + V_6 -> V_174 ;
#endif
V_6 -> V_59 = NULL ;
V_6 -> V_176 = NULL ;
V_60 = V_27 -> V_59 ;
if ( ! V_60 )
return 0 ;
F_184 ( V_6 ) ;
if ( V_170 & V_177 ) {
F_83 ( & V_60 -> V_122 ) ;
V_59 = V_60 ;
goto V_178;
}
V_69 = - V_110 ;
V_59 = F_179 ( V_6 ) ;
if ( ! V_59 )
goto V_88;
V_178:
V_6 -> V_59 = V_59 ;
V_6 -> V_176 = V_59 ;
return 0 ;
V_88:
return V_69 ;
}
static int F_185 ( unsigned long V_170 , struct V_5 * V_6 )
{
struct V_179 * V_180 = V_27 -> V_180 ;
if ( V_170 & V_181 ) {
F_141 ( & V_180 -> V_182 ) ;
if ( V_180 -> V_183 ) {
F_143 ( & V_180 -> V_182 ) ;
return - V_184 ;
}
V_180 -> V_185 ++ ;
F_143 ( & V_180 -> V_182 ) ;
return 0 ;
}
V_6 -> V_180 = F_186 ( V_180 ) ;
if ( ! V_6 -> V_180 )
return - V_110 ;
return 0 ;
}
static int F_187 ( unsigned long V_170 , struct V_5 * V_6 )
{
struct V_186 * V_187 , * V_188 ;
int error = 0 ;
V_187 = V_27 -> V_189 ;
if ( ! V_187 )
goto V_80;
if ( V_170 & V_190 ) {
F_83 ( & V_187 -> V_143 ) ;
goto V_80;
}
V_188 = F_188 ( V_187 , & error ) ;
if ( ! V_188 )
goto V_80;
V_6 -> V_189 = V_188 ;
error = 0 ;
V_80:
return error ;
}
static int F_189 ( unsigned long V_170 , struct V_5 * V_6 )
{
#ifdef F_190
struct V_191 * V_192 = V_27 -> V_191 ;
struct V_191 * V_193 ;
if ( ! V_192 )
return 0 ;
if ( V_170 & V_194 ) {
F_191 ( V_192 ) ;
V_6 -> V_191 = V_192 ;
} else if ( F_192 ( V_192 -> V_195 ) ) {
V_193 = F_193 ( V_6 , V_9 , V_196 ) ;
if ( F_101 ( ! V_193 ) )
return - V_110 ;
V_193 -> V_195 = V_192 -> V_195 ;
F_194 ( V_193 ) ;
}
#endif
return 0 ;
}
static int F_195 ( unsigned long V_170 , struct V_5 * V_6 )
{
struct V_197 * V_22 ;
if ( V_170 & V_198 ) {
F_83 ( & V_27 -> V_199 -> V_143 ) ;
return 0 ;
}
V_22 = F_75 ( V_200 , V_9 ) ;
F_147 ( V_6 -> V_199 , V_22 ) ;
if ( ! V_22 )
return - V_110 ;
F_60 ( & V_22 -> V_143 , 1 ) ;
memcpy ( V_22 -> V_201 , V_27 -> V_199 -> V_201 , sizeof( V_22 -> V_201 ) ) ;
return 0 ;
}
void F_196 ( struct V_197 * V_199 )
{
if ( F_32 ( & V_199 -> V_143 ) ) {
F_197 ( V_199 ) ;
F_10 ( V_200 , V_199 ) ;
}
}
static void F_198 ( struct V_21 * V_22 )
{
unsigned long V_202 ;
V_202 = F_199 ( V_22 -> V_39 [ V_203 ] . V_41 ) ;
if ( V_202 != V_204 ) {
V_22 -> V_205 . V_206 = F_200 ( V_202 ) ;
V_22 -> V_207 . V_208 = 1 ;
}
F_76 ( & V_22 -> V_209 [ 0 ] ) ;
F_76 ( & V_22 -> V_209 [ 1 ] ) ;
F_76 ( & V_22 -> V_209 [ 2 ] ) ;
}
static int F_201 ( unsigned long V_170 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_170 & V_210 )
return 0 ;
V_22 = F_202 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_110 ;
V_22 -> V_211 = 1 ;
F_60 ( & V_22 -> V_212 , 1 ) ;
F_60 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_213 = (struct V_214 ) F_203 ( V_6 -> V_215 ) ;
V_6 -> V_215 = (struct V_214 ) F_203 ( V_22 -> V_213 ) ;
F_204 ( & V_22 -> V_216 ) ;
V_22 -> V_217 = V_6 ;
F_205 ( & V_22 -> V_218 ) ;
F_76 ( & V_22 -> V_219 ) ;
F_206 ( & V_22 -> V_220 ) ;
F_207 ( & V_22 -> V_221 , V_222 , V_223 ) ;
V_22 -> V_221 . V_224 = V_225 ;
F_154 ( V_27 -> V_226 ) ;
memcpy ( V_22 -> V_39 , V_27 -> signal -> V_39 , sizeof V_22 -> V_39 ) ;
F_155 ( V_27 -> V_226 ) ;
F_198 ( V_22 ) ;
F_208 ( V_22 ) ;
F_209 ( V_22 ) ;
V_22 -> V_227 = V_27 -> signal -> V_227 ;
V_22 -> V_228 = V_27 -> signal -> V_228 ;
V_22 -> V_229 = V_27 -> signal -> V_229 ||
V_27 -> signal -> V_230 ;
F_210 ( & V_22 -> V_154 ) ;
return 0 ;
}
static void F_211 ( struct V_5 * V_118 )
{
#ifdef F_54
F_212 ( & V_27 -> V_199 -> V_231 ) ;
F_213 ( V_27 ) ;
V_118 -> V_52 = V_27 -> V_52 ;
if ( F_214 ( V_27 ) )
F_215 ( V_118 ) ;
if ( V_118 -> V_52 . V_153 != V_232 )
F_216 ( V_118 , V_233 ) ;
#endif
}
static void F_217 ( struct V_5 * V_118 )
{
F_218 ( & V_118 -> V_234 ) ;
#ifdef F_219
V_118 -> V_235 = V_120 ;
V_118 -> V_236 = NULL ;
V_118 -> V_237 = NULL ;
#endif
}
static void F_220 ( struct V_5 * V_6 )
{
V_6 -> V_205 . V_206 = 0 ;
V_6 -> V_205 . V_238 = 0 ;
V_6 -> V_205 . V_239 = 0 ;
F_76 ( & V_6 -> V_209 [ 0 ] ) ;
F_76 ( & V_6 -> V_209 [ 1 ] ) ;
F_76 ( & V_6 -> V_209 [ 2 ] ) ;
}
static inline void
F_221 ( struct V_5 * V_151 , enum V_240 type , struct V_241 * V_241 )
{
V_151 -> V_242 [ type ] . V_241 = V_241 ;
}
static struct V_5 * F_222 ( unsigned long V_170 ,
unsigned long V_243 ,
unsigned long V_244 ,
int T_3 * V_245 ,
struct V_241 * V_241 ,
int V_246 ,
unsigned long V_247 )
{
int V_69 ;
struct V_5 * V_118 ;
if ( ( V_170 & ( V_248 | V_181 ) ) == ( V_248 | V_181 ) )
return F_158 ( - V_249 ) ;
if ( ( V_170 & ( V_250 | V_181 ) ) == ( V_250 | V_181 ) )
return F_158 ( - V_249 ) ;
if ( ( V_170 & V_210 ) && ! ( V_170 & V_198 ) )
return F_158 ( - V_249 ) ;
if ( ( V_170 & V_198 ) && ! ( V_170 & V_177 ) )
return F_158 ( - V_249 ) ;
if ( ( V_170 & V_251 ) &&
V_27 -> signal -> V_134 & V_252 )
return F_158 ( - V_249 ) ;
if ( V_170 & V_198 ) {
if ( ( V_170 & ( V_250 | V_253 ) ) ||
( F_223 ( V_27 ) !=
V_27 -> V_254 -> V_255 ) )
return F_158 ( - V_249 ) ;
}
V_69 = F_224 ( V_170 ) ;
if ( V_69 )
goto V_256;
V_69 = - V_110 ;
V_118 = F_52 ( V_27 ) ;
if ( ! V_118 )
goto V_256;
F_225 ( V_118 ) ;
F_217 ( V_118 ) ;
#ifdef F_226
F_227 ( ! V_118 -> V_257 ) ;
F_227 ( ! V_118 -> V_258 ) ;
#endif
V_69 = - V_184 ;
if ( F_35 ( & V_118 -> V_259 -> V_260 -> V_261 ) >=
F_228 ( V_118 , V_40 ) ) {
if ( V_118 -> V_259 -> V_260 != V_262 &&
! F_229 ( V_263 ) && ! F_229 ( V_264 ) )
goto V_265;
}
V_27 -> V_134 &= ~ V_266 ;
V_69 = F_230 ( V_118 , V_170 ) ;
if ( V_69 < 0 )
goto V_265;
V_69 = - V_184 ;
if ( V_211 >= V_33 )
goto V_267;
F_231 ( V_118 ) ;
V_118 -> V_134 &= ~ ( V_268 | V_269 ) ;
V_118 -> V_134 |= V_270 ;
F_76 ( & V_118 -> V_271 ) ;
F_76 ( & V_118 -> V_272 ) ;
F_232 ( V_118 ) ;
V_118 -> V_158 = NULL ;
F_108 ( & V_118 -> V_273 ) ;
F_205 ( & V_118 -> V_274 ) ;
V_118 -> V_275 = V_118 -> V_276 = V_118 -> V_277 = 0 ;
V_118 -> V_278 = V_118 -> V_279 = 0 ;
#ifndef F_233
V_118 -> V_280 . V_275 = V_118 -> V_280 . V_276 = 0 ;
#endif
#ifdef F_234
F_206 ( & V_118 -> V_281 ) ;
V_118 -> V_282 = 0 ;
V_118 -> V_283 = V_284 ;
#endif
#if F_118 ( V_285 )
memset ( & V_118 -> V_129 , 0 , sizeof( V_118 -> V_129 ) ) ;
#endif
V_118 -> V_286 = V_27 -> V_287 ;
F_235 ( & V_118 -> V_288 ) ;
F_236 ( V_118 ) ;
F_220 ( V_118 ) ;
V_118 -> V_289 = F_237 () ;
V_118 -> V_290 = F_238 () ;
V_118 -> V_191 = NULL ;
V_118 -> V_291 = NULL ;
if ( V_170 & V_210 )
F_239 ( V_27 ) ;
F_240 ( V_118 ) ;
#ifdef F_241
V_118 -> V_292 = F_242 ( V_118 -> V_292 ) ;
if ( F_243 ( V_118 -> V_292 ) ) {
V_69 = F_244 ( V_118 -> V_292 ) ;
V_118 -> V_292 = NULL ;
goto V_293;
}
#endif
#ifdef F_245
V_118 -> V_294 = V_196 ;
V_118 -> V_295 = V_196 ;
F_246 ( & V_118 -> V_296 ) ;
#endif
#ifdef F_247
V_118 -> V_297 = 0 ;
V_118 -> V_257 = 0 ;
V_118 -> V_298 = 0 ;
V_118 -> V_299 = 0 ;
V_118 -> V_300 = V_301 ;
V_118 -> V_302 = 0 ;
V_118 -> V_258 = 1 ;
V_118 -> V_303 = V_301 ;
V_118 -> V_304 = 0 ;
V_118 -> V_305 = 0 ;
V_118 -> V_306 = 0 ;
V_118 -> V_307 = 0 ;
V_118 -> V_308 = 0 ;
#endif
V_118 -> V_309 = 0 ;
#ifdef F_248
V_118 -> V_310 = 0 ;
V_118 -> V_311 = 0 ;
V_118 -> V_312 = 0 ;
#endif
#ifdef F_249
V_118 -> V_313 = NULL ;
#endif
#ifdef F_250
V_118 -> V_314 = 0 ;
V_118 -> V_315 = 0 ;
#endif
V_69 = F_251 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_316;
V_69 = F_252 ( V_118 ) ;
if ( V_69 )
goto V_316;
V_69 = F_253 ( V_118 ) ;
if ( V_69 )
goto V_317;
F_254 ( V_118 ) ;
V_69 = F_255 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_318;
V_69 = F_187 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_319;
V_69 = F_185 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_320;
V_69 = F_195 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_321;
V_69 = F_201 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_322;
V_69 = F_182 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_323;
V_69 = F_256 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_324;
V_69 = F_189 ( V_170 , V_118 ) ;
if ( V_69 )
goto V_325;
V_69 = F_257 ( V_170 , V_243 , V_244 , V_118 , V_247 ) ;
if ( V_69 )
goto V_326;
if ( V_241 != & V_327 ) {
V_241 = F_258 ( V_118 -> V_254 -> V_255 ) ;
if ( F_243 ( V_241 ) ) {
V_69 = F_244 ( V_241 ) ;
goto V_326;
}
}
V_118 -> V_328 = ( V_170 & V_329 ) ? V_245 : NULL ;
V_118 -> V_164 = ( V_170 & V_330 ) ? V_245 : NULL ;
#ifdef F_190
V_118 -> V_331 = NULL ;
#endif
#ifdef F_170
V_118 -> V_161 = NULL ;
#ifdef F_172
V_118 -> V_162 = NULL ;
#endif
F_76 ( & V_118 -> V_163 ) ;
V_118 -> V_332 = NULL ;
#endif
if ( ( V_170 & ( V_177 | V_333 ) ) == V_177 )
V_118 -> V_334 = V_118 -> V_335 = 0 ;
F_259 ( V_118 ) ;
F_260 ( V_118 , V_336 ) ;
#ifdef F_261
F_260 ( V_118 , F_261 ) ;
#endif
F_262 ( V_118 ) ;
V_118 -> V_241 = F_263 ( V_241 ) ;
if ( V_170 & V_210 ) {
V_118 -> V_337 = - 1 ;
V_118 -> V_226 = V_27 -> V_226 ;
V_118 -> V_338 = V_27 -> V_338 ;
} else {
if ( V_170 & V_251 )
V_118 -> V_337 = V_27 -> V_226 -> V_337 ;
else
V_118 -> V_337 = ( V_170 & V_339 ) ;
V_118 -> V_226 = V_118 ;
V_118 -> V_338 = V_118 -> V_241 ;
}
V_118 -> V_340 = 0 ;
V_118 -> V_341 = 128 >> ( V_342 - 10 ) ;
V_118 -> V_343 = 0 ;
V_118 -> V_344 = 0 ;
F_76 ( & V_118 -> V_345 ) ;
V_118 -> V_346 = NULL ;
F_264 ( & V_1 ) ;
if ( V_170 & ( V_251 | V_210 ) ) {
V_118 -> V_347 = V_27 -> V_347 ;
V_118 -> V_348 = V_27 -> V_348 ;
} else {
V_118 -> V_347 = V_27 ;
V_118 -> V_348 = V_27 -> V_349 ;
}
F_141 ( & V_27 -> V_199 -> V_231 ) ;
F_211 ( V_118 ) ;
F_265 () ;
if ( F_266 ( V_27 ) ) {
F_143 ( & V_27 -> V_199 -> V_231 ) ;
F_267 ( & V_1 ) ;
V_69 = - V_350 ;
goto V_351;
}
if ( F_162 ( V_118 -> V_241 ) ) {
F_268 ( V_118 , ( V_170 & V_352 ) || V_246 ) ;
F_221 ( V_118 , V_353 , V_241 ) ;
if ( F_269 ( V_118 ) ) {
F_221 ( V_118 , V_354 , F_270 ( V_27 ) ) ;
F_221 ( V_118 , V_355 , F_271 ( V_27 ) ) ;
if ( F_272 ( V_241 ) ) {
F_273 ( V_241 ) -> V_356 = V_118 ;
V_118 -> signal -> V_134 |= V_252 ;
}
V_118 -> signal -> V_357 = V_241 ;
V_118 -> signal -> V_358 = F_274 ( V_27 -> signal -> V_358 ) ;
F_275 ( & V_118 -> V_272 , & V_118 -> V_347 -> V_271 ) ;
F_276 ( & V_118 -> V_359 , & V_38 . V_359 ) ;
F_277 ( V_118 , V_354 ) ;
F_277 ( V_118 , V_355 ) ;
F_278 ( V_4 ) ;
} else {
V_27 -> signal -> V_211 ++ ;
F_83 ( & V_27 -> signal -> V_212 ) ;
F_83 ( & V_27 -> signal -> V_24 ) ;
F_276 ( & V_118 -> V_345 ,
& V_118 -> V_226 -> V_345 ) ;
F_276 ( & V_118 -> V_215 ,
& V_118 -> signal -> V_213 ) ;
}
F_277 ( V_118 , V_353 ) ;
V_211 ++ ;
}
V_360 ++ ;
F_143 ( & V_27 -> V_199 -> V_231 ) ;
F_279 ( V_118 ) ;
F_267 ( & V_1 ) ;
F_280 ( V_118 ) ;
F_281 ( V_118 ) ;
if ( V_170 & V_210 )
F_282 ( V_27 ) ;
F_283 ( V_118 ) ;
F_284 ( V_118 , V_170 ) ;
F_285 ( V_118 , V_170 ) ;
return V_118 ;
V_351:
if ( V_241 != & V_327 )
F_286 ( V_241 ) ;
V_326:
if ( V_118 -> V_191 )
F_287 ( V_118 ) ;
V_325:
F_288 ( V_118 ) ;
V_324:
if ( V_118 -> V_59 )
F_132 ( V_118 -> V_59 ) ;
V_323:
if ( ! ( V_170 & V_210 ) )
F_28 ( V_118 -> signal ) ;
V_322:
F_196 ( V_118 -> V_199 ) ;
V_321:
F_289 ( V_118 ) ;
V_320:
F_290 ( V_118 ) ;
V_319:
F_291 ( V_118 ) ;
V_318:
F_292 ( V_118 ) ;
V_317:
F_293 ( V_118 ) ;
V_316:
#ifdef F_241
F_96 ( V_118 -> V_292 ) ;
V_293:
#endif
if ( V_170 & V_210 )
F_282 ( V_27 ) ;
F_39 ( V_118 ) ;
V_267:
F_81 ( & V_118 -> V_361 -> V_260 -> V_261 ) ;
F_38 ( V_118 ) ;
V_265:
F_24 ( V_118 ) ;
V_256:
return F_158 ( V_69 ) ;
}
static inline void F_294 ( struct V_362 * V_363 )
{
enum V_240 type ;
for ( type = V_353 ; type < V_364 ; ++ type ) {
F_295 ( & V_363 [ type ] . V_7 ) ;
V_363 [ type ] . V_241 = & V_327 ;
}
}
struct V_5 * F_296 ( int V_2 )
{
struct V_5 * V_151 ;
V_151 = F_222 ( V_177 , 0 , 0 , NULL , & V_327 , 0 , 0 ) ;
if ( ! F_243 ( V_151 ) ) {
F_294 ( V_151 -> V_242 ) ;
F_297 ( V_151 , V_2 ) ;
}
return V_151 ;
}
long F_298 ( unsigned long V_170 ,
unsigned long V_243 ,
unsigned long V_244 ,
int T_3 * V_365 ,
int T_3 * V_245 ,
unsigned long V_247 )
{
struct V_5 * V_118 ;
int V_246 = 0 ;
long V_366 ;
if ( ! ( V_170 & V_367 ) ) {
if ( V_170 & V_333 )
V_246 = V_368 ;
else if ( ( V_170 & V_339 ) != V_369 )
V_246 = V_370 ;
else
V_246 = V_371 ;
if ( F_162 ( ! F_299 ( V_27 , V_246 ) ) )
V_246 = 0 ;
}
V_118 = F_222 ( V_170 , V_243 , V_244 ,
V_245 , NULL , V_246 , V_247 ) ;
if ( ! F_243 ( V_118 ) ) {
struct V_156 V_157 ;
struct V_241 * V_241 ;
F_300 ( V_27 , V_118 ) ;
V_241 = F_301 ( V_118 , V_353 ) ;
V_366 = F_302 ( V_241 ) ;
if ( V_170 & V_372 )
F_177 ( V_366 , V_365 ) ;
if ( V_170 & V_333 ) {
V_118 -> V_158 = & V_157 ;
F_303 ( & V_157 ) ;
F_304 ( V_118 ) ;
}
F_305 ( V_118 ) ;
if ( F_101 ( V_246 ) )
F_306 ( V_246 , V_241 ) ;
if ( V_170 & V_333 ) {
if ( ! F_164 ( V_118 , & V_157 ) )
F_306 ( V_373 , V_241 ) ;
}
F_307 ( V_241 ) ;
} else {
V_366 = F_244 ( V_118 ) ;
}
return V_366 ;
}
long F_308 ( unsigned long V_170 ,
unsigned long V_243 ,
unsigned long V_244 ,
int T_3 * V_365 ,
int T_3 * V_245 )
{
return F_298 ( V_170 , V_243 , V_244 ,
V_365 , V_245 , 0 ) ;
}
T_4 F_309 ( int (* F_310)( void * ) , void * V_374 , unsigned long V_134 )
{
return F_298 ( V_134 | V_177 | V_367 , ( unsigned long ) F_310 ,
( unsigned long ) V_374 , NULL , NULL , 0 ) ;
}
static void F_311 ( void * V_375 )
{
struct V_197 * V_199 = V_375 ;
F_108 ( & V_199 -> V_231 ) ;
F_204 ( & V_199 -> V_376 ) ;
}
void T_1 F_312 ( void )
{
V_200 = F_18 ( L_7 ,
sizeof( struct V_197 ) , 0 ,
V_377 | V_36 | V_378 |
V_37 , F_311 ) ;
V_23 = F_18 ( L_8 ,
sizeof( struct V_21 ) , 0 ,
V_377 | V_36 | V_37 , NULL ) ;
V_379 = F_18 ( L_9 ,
sizeof( struct V_186 ) , 0 ,
V_377 | V_36 | V_37 , NULL ) ;
V_380 = F_18 ( L_10 ,
sizeof( struct V_179 ) , 0 ,
V_377 | V_36 | V_37 , NULL ) ;
V_381 = F_18 ( L_11 ,
sizeof( struct V_58 ) , V_382 ,
V_377 | V_36 | V_37 , NULL ) ;
V_89 = F_313 ( V_61 , V_36 ) ;
F_314 () ;
F_315 () ;
}
static int F_316 ( unsigned long V_383 )
{
if ( V_383 & ~ ( V_210 | V_181 | V_248 | V_198 |
V_177 | V_190 | V_384 |
V_385 | V_386 | V_387 |
V_250 | V_253 ) )
return - V_249 ;
if ( V_383 & ( V_210 | V_198 | V_177 ) ) {
if ( F_35 ( & V_27 -> V_59 -> V_122 ) > 1 )
return - V_249 ;
}
return 0 ;
}
static int F_317 ( unsigned long V_383 , struct V_179 * * V_388 )
{
struct V_179 * V_180 = V_27 -> V_180 ;
if ( ! ( V_383 & V_181 ) || ! V_180 )
return 0 ;
if ( V_180 -> V_185 == 1 )
return 0 ;
* V_388 = F_186 ( V_180 ) ;
if ( ! * V_388 )
return - V_110 ;
return 0 ;
}
static int F_318 ( unsigned long V_383 , struct V_186 * * V_389 )
{
struct V_186 * V_390 = V_27 -> V_189 ;
int error = 0 ;
if ( ( V_383 & V_190 ) &&
( V_390 && F_35 ( & V_390 -> V_143 ) > 1 ) ) {
* V_389 = F_188 ( V_390 , & error ) ;
if ( ! * V_389 )
return error ;
}
return 0 ;
}
int F_319 ( struct V_186 * * V_391 )
{
struct V_5 * V_151 = V_27 ;
struct V_186 * V_392 = NULL ;
int error ;
error = F_318 ( V_190 , & V_392 ) ;
if ( error || ! V_392 ) {
* V_391 = NULL ;
return error ;
}
* V_391 = V_151 -> V_189 ;
F_154 ( V_151 ) ;
V_151 -> V_189 = V_392 ;
F_155 ( V_151 ) ;
return 0 ;
}
int F_320 ( struct V_393 * V_394 , int V_395 ,
void T_3 * V_396 , T_5 * V_397 , T_6 * V_398 )
{
struct V_393 V_399 ;
int V_400 ;
int V_29 = V_33 ;
int V_401 = V_34 ;
int V_402 = V_32 ;
V_399 = * V_394 ;
V_399 . V_375 = & V_29 ;
V_399 . V_403 = & V_401 ;
V_399 . V_404 = & V_402 ;
V_400 = F_321 ( & V_399 , V_395 , V_396 , V_397 , V_398 ) ;
if ( V_400 || ! V_395 )
return V_400 ;
F_42 ( V_29 ) ;
return 0 ;
}
