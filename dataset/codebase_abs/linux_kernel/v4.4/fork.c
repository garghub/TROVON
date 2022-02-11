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
F_40 ( V_6 ) ;
F_31 ( V_6 -> signal ) ;
if ( ! F_41 ( V_6 ) )
F_24 ( V_6 ) ;
}
void T_1 __weak F_42 ( void ) { }
static void F_43 ( unsigned int V_28 )
{
T_2 V_29 ;
if ( F_44 ( V_30 ) + F_44 ( V_31 ) > 64 )
V_29 = V_32 ;
else
V_29 = F_45 ( ( T_2 ) V_30 * ( T_2 ) V_31 ,
( T_2 ) V_16 * 8UL ) ;
if ( V_29 > V_28 )
V_29 = V_28 ;
V_33 = F_46 ( T_2 , V_29 , V_34 , V_32 ) ;
}
void T_1 F_47 ( void )
{
#ifndef F_48
#ifndef F_49
#define F_49 L1_CACHE_BYTES
#endif
V_8 =
F_18 ( L_2 , V_35 ,
F_49 , V_36 | V_37 , NULL ) ;
#endif
F_42 () ;
F_43 ( V_32 ) ;
V_38 . signal -> V_39 [ V_40 ] . V_41 = V_33 / 2 ;
V_38 . signal -> V_39 [ V_40 ] . V_42 = V_33 / 2 ;
V_38 . signal -> V_39 [ V_43 ] =
V_38 . signal -> V_39 [ V_40 ] ;
}
int __weak F_50 ( struct V_5 * V_44 ,
struct V_5 * V_45 )
{
* V_44 = * V_45 ;
return 0 ;
}
void F_51 ( struct V_5 * V_6 )
{
unsigned long * V_46 ;
V_46 = F_52 ( V_6 ) ;
* V_46 = V_47 ;
}
static struct V_5 * F_53 ( struct V_5 * V_48 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_7 = F_54 ( V_48 ) ;
int V_49 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_50;
V_49 = F_50 ( V_6 , V_48 ) ;
if ( V_49 )
goto V_51;
V_6 -> V_20 = V_11 ;
#ifdef F_55
V_6 -> V_52 . V_53 = NULL ;
#endif
F_56 ( V_6 , V_48 ) ;
F_57 ( V_6 ) ;
F_58 ( V_6 ) ;
F_51 ( V_6 ) ;
#ifdef F_59
V_6 -> V_54 = F_60 () ;
#endif
F_61 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_62
V_6 -> V_55 = 0 ;
#endif
V_6 -> V_56 = NULL ;
V_6 -> V_57 . V_12 = NULL ;
V_6 -> V_58 . V_59 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_51:
F_15 ( V_11 ) ;
V_50:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_63 ( struct V_60 * V_61 , struct V_60 * V_62 )
{
struct V_63 * V_64 , * V_65 , * V_66 , * * V_67 ;
struct V_68 * * V_69 , * V_70 ;
int V_71 ;
unsigned long V_72 ;
F_64 () ;
F_65 ( & V_62 -> V_73 ) ;
F_66 ( V_62 ) ;
F_67 ( V_62 , V_61 ) ;
F_68 ( & V_61 -> V_73 , V_74 ) ;
F_69 ( V_61 -> V_75 , F_70 ( V_62 ) ) ;
V_61 -> V_76 = V_62 -> V_76 ;
V_61 -> V_77 = V_62 -> V_77 ;
V_61 -> V_78 = V_62 -> V_78 ;
V_61 -> V_79 = V_62 -> V_79 ;
V_69 = & V_61 -> V_80 . V_68 ;
V_70 = NULL ;
V_67 = & V_61 -> V_81 ;
V_71 = F_71 ( V_61 , V_62 ) ;
if ( V_71 )
goto V_82;
V_71 = F_72 ( V_61 , V_62 ) ;
if ( V_71 )
goto V_82;
V_66 = NULL ;
for ( V_64 = V_62 -> V_81 ; V_64 ; V_64 = V_64 -> V_83 ) {
struct V_84 * V_84 ;
if ( V_64 -> V_85 & V_86 ) {
F_73 ( V_61 , V_64 -> V_85 , V_64 -> V_87 ,
- F_74 ( V_64 ) ) ;
continue;
}
V_72 = 0 ;
if ( V_64 -> V_85 & V_88 ) {
unsigned long V_89 = F_74 ( V_64 ) ;
if ( F_75 ( V_62 , V_89 ) )
goto V_90;
V_72 = V_89 ;
}
V_65 = F_76 ( V_91 , V_9 ) ;
if ( ! V_65 )
goto V_90;
* V_65 = * V_64 ;
F_77 ( & V_65 -> V_92 ) ;
V_71 = F_78 ( V_64 , V_65 ) ;
if ( V_71 )
goto V_93;
V_65 -> V_94 = V_61 ;
if ( F_79 ( V_65 , V_64 ) )
goto V_95;
V_65 -> V_85 &=
~ ( V_96 | V_97 | V_98 | V_99 ) ;
V_65 -> V_83 = V_65 -> V_100 = NULL ;
V_65 -> V_101 = V_102 ;
V_84 = V_65 -> V_87 ;
if ( V_84 ) {
struct V_103 * V_103 = F_80 ( V_84 ) ;
struct V_104 * V_105 = V_84 -> V_106 ;
F_81 ( V_84 ) ;
if ( V_65 -> V_85 & V_107 )
F_82 ( & V_103 -> V_108 ) ;
F_83 ( V_105 ) ;
if ( V_65 -> V_85 & V_109 )
F_84 ( & V_105 -> V_110 ) ;
F_85 ( V_105 ) ;
F_86 ( V_65 , V_64 ,
& V_105 -> V_111 ) ;
F_87 ( V_105 ) ;
F_88 ( V_105 ) ;
}
if ( F_89 ( V_65 ) )
F_90 ( V_65 ) ;
* V_67 = V_65 ;
V_67 = & V_65 -> V_83 ;
V_65 -> V_100 = V_66 ;
V_66 = V_65 ;
F_91 ( V_61 , V_65 , V_69 , V_70 ) ;
V_69 = & V_65 -> V_112 . V_113 ;
V_70 = & V_65 -> V_112 ;
V_61 -> V_114 ++ ;
V_71 = F_92 ( V_61 , V_62 , V_64 ) ;
if ( V_65 -> V_115 && V_65 -> V_115 -> V_116 )
V_65 -> V_115 -> V_116 ( V_65 ) ;
if ( V_71 )
goto V_82;
}
F_93 ( V_62 , V_61 ) ;
V_71 = 0 ;
V_82:
F_94 ( & V_61 -> V_73 ) ;
F_95 ( V_62 ) ;
F_94 ( & V_62 -> V_73 ) ;
F_96 () ;
return V_71 ;
V_95:
F_97 ( F_98 ( V_65 ) ) ;
V_93:
F_10 ( V_91 , V_65 ) ;
V_90:
V_71 = - V_117 ;
F_99 ( V_72 ) ;
goto V_82;
}
static inline int F_100 ( struct V_60 * V_61 )
{
V_61 -> V_118 = F_101 ( V_61 ) ;
if ( F_102 ( ! V_61 -> V_118 ) )
return - V_117 ;
return 0 ;
}
static inline void F_103 ( struct V_60 * V_61 )
{
F_104 ( V_61 , V_61 -> V_118 ) ;
}
static int F_63 ( struct V_60 * V_61 , struct V_60 * V_62 )
{
F_65 ( & V_62 -> V_73 ) ;
F_69 ( V_61 -> V_75 , F_70 ( V_62 ) ) ;
F_94 ( & V_62 -> V_73 ) ;
return 0 ;
}
static int T_1 F_105 ( char * V_119 )
{
V_120 =
( F_106 ( V_119 , NULL , 0 ) << V_121 ) &
V_122 ;
return 1 ;
}
static void F_107 ( struct V_60 * V_61 )
{
#ifdef F_108
F_109 ( & V_61 -> V_123 ) ;
V_61 -> V_124 = NULL ;
#endif
}
static void F_110 ( struct V_60 * V_61 , struct V_5 * V_125 )
{
#ifdef F_111
V_61 -> V_126 = V_125 ;
#endif
}
static struct V_60 * F_112 ( struct V_60 * V_61 , struct V_5 * V_125 )
{
V_61 -> V_81 = NULL ;
V_61 -> V_80 = V_127 ;
V_61 -> V_128 = 0 ;
F_61 ( & V_61 -> V_129 , 1 ) ;
F_61 ( & V_61 -> V_130 , 1 ) ;
F_113 ( & V_61 -> V_73 ) ;
F_77 ( & V_61 -> V_131 ) ;
V_61 -> V_132 = NULL ;
F_114 ( & V_61 -> V_133 , 0 ) ;
F_115 ( V_61 ) ;
V_61 -> V_114 = 0 ;
V_61 -> V_134 = 0 ;
V_61 -> V_135 = 0 ;
memset ( & V_61 -> V_136 , 0 , sizeof( V_61 -> V_136 ) ) ;
F_109 ( & V_61 -> V_137 ) ;
F_116 ( V_61 ) ;
F_107 ( V_61 ) ;
F_110 ( V_61 , V_125 ) ;
F_117 ( V_61 ) ;
F_118 ( V_61 ) ;
#if F_119 ( V_138 ) && ! V_139
V_61 -> V_140 = NULL ;
#endif
if ( V_27 -> V_61 ) {
V_61 -> V_141 = V_27 -> V_61 -> V_141 & V_142 ;
V_61 -> V_143 = V_27 -> V_61 -> V_143 & V_144 ;
} else {
V_61 -> V_141 = V_120 ;
V_61 -> V_143 = 0 ;
}
if ( F_100 ( V_61 ) )
goto V_145;
if ( F_120 ( V_125 , V_61 ) )
goto V_146;
return V_61 ;
V_146:
F_103 ( V_61 ) ;
V_145:
F_121 ( V_61 ) ;
return NULL ;
}
static void F_122 ( struct V_60 * V_61 )
{
int V_147 ;
for ( V_147 = 0 ; V_147 < V_148 ; V_147 ++ ) {
long V_149 = F_123 ( & V_61 -> V_136 . V_150 [ V_147 ] ) ;
if ( F_102 ( V_149 ) )
F_124 ( V_151 L_3
L_4 , V_61 , V_147 , V_149 ) ;
}
if ( F_123 ( & V_61 -> V_133 ) )
F_125 ( L_5 ,
F_123 ( & V_61 -> V_133 ) ) ;
if ( F_126 ( V_61 ) )
F_125 ( L_6 ,
F_126 ( V_61 ) ) ;
#if F_119 ( V_138 ) && ! V_139
F_127 ( V_61 -> V_140 , V_61 ) ;
#endif
}
struct V_60 * F_128 ( void )
{
struct V_60 * V_61 ;
V_61 = F_129 () ;
if ( ! V_61 )
return NULL ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
return F_112 ( V_61 , V_27 ) ;
}
void F_130 ( struct V_60 * V_61 )
{
F_19 ( V_61 == & V_152 ) ;
F_103 ( V_61 ) ;
F_131 ( V_61 ) ;
F_132 ( V_61 ) ;
F_122 ( V_61 ) ;
F_121 ( V_61 ) ;
}
void F_133 ( struct V_60 * V_61 )
{
F_134 () ;
if ( F_32 ( & V_61 -> V_129 ) ) {
F_135 ( V_61 ) ;
F_136 ( V_61 ) ;
F_137 ( V_61 ) ;
F_138 ( V_61 ) ;
F_139 ( V_61 ) ;
F_140 ( V_61 , NULL ) ;
if ( ! F_141 ( & V_61 -> V_131 ) ) {
F_142 ( & V_153 ) ;
F_143 ( & V_61 -> V_131 ) ;
F_144 ( & V_153 ) ;
}
if ( V_61 -> V_154 )
F_145 ( V_61 -> V_154 -> V_155 ) ;
F_146 ( V_61 ) ;
}
}
void F_140 ( struct V_60 * V_61 , struct V_84 * V_156 )
{
struct V_84 * V_157 ;
V_157 = F_147 ( V_61 -> V_75 ) ;
if ( V_156 )
F_81 ( V_156 ) ;
F_148 ( V_61 -> V_75 , V_156 ) ;
if ( V_157 )
F_149 ( V_157 ) ;
}
struct V_84 * F_70 ( struct V_60 * V_61 )
{
struct V_84 * V_75 ;
F_150 () ;
V_75 = F_151 ( V_61 -> V_75 ) ;
if ( V_75 && ! F_152 ( V_75 ) )
V_75 = NULL ;
F_153 () ;
return V_75 ;
}
struct V_60 * F_154 ( struct V_5 * V_158 )
{
struct V_60 * V_61 ;
F_155 ( V_158 ) ;
V_61 = V_158 -> V_61 ;
if ( V_61 ) {
if ( V_158 -> V_141 & V_159 )
V_61 = NULL ;
else
F_84 ( & V_61 -> V_129 ) ;
}
F_156 ( V_158 ) ;
return V_61 ;
}
struct V_60 * F_157 ( struct V_5 * V_158 , unsigned int V_160 )
{
struct V_60 * V_61 ;
int V_49 ;
V_49 = F_158 ( & V_158 -> signal -> V_161 ) ;
if ( V_49 )
return F_159 ( V_49 ) ;
V_61 = F_154 ( V_158 ) ;
if ( V_61 && V_61 != V_27 -> V_61 &&
! F_160 ( V_158 , V_160 ) ) {
F_133 ( V_61 ) ;
V_61 = F_159 ( - V_162 ) ;
}
F_161 ( & V_158 -> signal -> V_161 ) ;
return V_61 ;
}
static void F_162 ( struct V_5 * V_6 )
{
struct V_163 * V_164 ;
F_155 ( V_6 ) ;
V_164 = V_6 -> V_165 ;
if ( F_163 ( V_164 ) ) {
V_6 -> V_165 = NULL ;
F_164 ( V_164 ) ;
}
F_156 ( V_6 ) ;
}
static int F_165 ( struct V_5 * V_166 ,
struct V_163 * V_164 )
{
int V_167 ;
F_166 () ;
V_167 = F_167 ( V_164 ) ;
F_168 () ;
if ( V_167 ) {
F_155 ( V_166 ) ;
V_166 -> V_165 = NULL ;
F_156 ( V_166 ) ;
}
F_169 ( V_166 ) ;
return V_167 ;
}
void F_170 ( struct V_5 * V_6 , struct V_60 * V_61 )
{
#ifdef F_171
if ( F_102 ( V_6 -> V_168 ) ) {
F_172 ( V_6 ) ;
V_6 -> V_168 = NULL ;
}
#ifdef F_173
if ( F_102 ( V_6 -> V_169 ) ) {
F_174 ( V_6 ) ;
V_6 -> V_169 = NULL ;
}
#endif
if ( F_102 ( ! F_141 ( & V_6 -> V_170 ) ) )
F_175 ( V_6 ) ;
#endif
F_176 ( V_6 ) ;
F_177 ( V_6 , V_61 ) ;
if ( V_6 -> V_171 ) {
if ( ! ( V_6 -> V_141 & V_172 ) &&
F_35 ( & V_61 -> V_129 ) > 1 ) {
F_178 ( 0 , V_6 -> V_171 ) ;
F_179 ( V_6 -> V_171 , V_173 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_171 = NULL ;
}
if ( V_6 -> V_165 )
F_162 ( V_6 ) ;
}
static struct V_60 * F_180 ( struct V_5 * V_6 )
{
struct V_60 * V_61 , * V_62 = V_27 -> V_61 ;
int V_49 ;
V_61 = F_129 () ;
if ( ! V_61 )
goto V_90;
memcpy ( V_61 , V_62 , sizeof( * V_61 ) ) ;
if ( ! F_112 ( V_61 , V_6 ) )
goto V_90;
V_49 = F_63 ( V_61 , V_62 ) ;
if ( V_49 )
goto V_174;
V_61 -> V_175 = F_181 ( V_61 ) ;
V_61 -> V_176 = V_61 -> V_76 ;
if ( V_61 -> V_154 && ! F_182 ( V_61 -> V_154 -> V_155 ) )
goto V_174;
return V_61 ;
V_174:
V_61 -> V_154 = NULL ;
F_133 ( V_61 ) ;
V_90:
return NULL ;
}
static int F_183 ( unsigned long V_177 , struct V_5 * V_6 )
{
struct V_60 * V_61 , * V_62 ;
int V_71 ;
V_6 -> V_178 = V_6 -> V_179 = 0 ;
V_6 -> V_180 = V_6 -> V_181 = 0 ;
#ifdef F_184
V_6 -> V_182 = V_6 -> V_180 + V_6 -> V_181 ;
#endif
V_6 -> V_61 = NULL ;
V_6 -> V_183 = NULL ;
V_62 = V_27 -> V_61 ;
if ( ! V_62 )
return 0 ;
F_185 ( V_6 ) ;
if ( V_177 & V_184 ) {
F_84 ( & V_62 -> V_129 ) ;
V_61 = V_62 ;
goto V_185;
}
V_71 = - V_117 ;
V_61 = F_180 ( V_6 ) ;
if ( ! V_61 )
goto V_90;
V_185:
V_6 -> V_61 = V_61 ;
V_6 -> V_183 = V_61 ;
return 0 ;
V_90:
return V_71 ;
}
static int F_186 ( unsigned long V_177 , struct V_5 * V_6 )
{
struct V_186 * V_187 = V_27 -> V_187 ;
if ( V_177 & V_188 ) {
F_142 ( & V_187 -> V_189 ) ;
if ( V_187 -> V_190 ) {
F_144 ( & V_187 -> V_189 ) ;
return - V_191 ;
}
V_187 -> V_192 ++ ;
F_144 ( & V_187 -> V_189 ) ;
return 0 ;
}
V_6 -> V_187 = F_187 ( V_187 ) ;
if ( ! V_6 -> V_187 )
return - V_117 ;
return 0 ;
}
static int F_188 ( unsigned long V_177 , struct V_5 * V_6 )
{
struct V_193 * V_194 , * V_195 ;
int error = 0 ;
V_194 = V_27 -> V_196 ;
if ( ! V_194 )
goto V_82;
if ( V_177 & V_197 ) {
F_84 ( & V_194 -> V_150 ) ;
goto V_82;
}
V_195 = F_189 ( V_194 , & error ) ;
if ( ! V_195 )
goto V_82;
V_6 -> V_196 = V_195 ;
error = 0 ;
V_82:
return error ;
}
static int F_190 ( unsigned long V_177 , struct V_5 * V_6 )
{
#ifdef F_191
struct V_198 * V_199 = V_27 -> V_198 ;
struct V_198 * V_200 ;
if ( ! V_199 )
return 0 ;
if ( V_177 & V_201 ) {
F_192 ( V_199 ) ;
V_6 -> V_198 = V_199 ;
} else if ( F_193 ( V_199 -> V_202 ) ) {
V_200 = F_194 ( V_6 , V_9 , V_203 ) ;
if ( F_102 ( ! V_200 ) )
return - V_117 ;
V_200 -> V_202 = V_199 -> V_202 ;
F_195 ( V_200 ) ;
}
#endif
return 0 ;
}
static int F_196 ( unsigned long V_177 , struct V_5 * V_6 )
{
struct V_204 * V_22 ;
if ( V_177 & V_205 ) {
F_84 ( & V_27 -> V_206 -> V_150 ) ;
return 0 ;
}
V_22 = F_76 ( V_207 , V_9 ) ;
F_148 ( V_6 -> V_206 , V_22 ) ;
if ( ! V_22 )
return - V_117 ;
F_61 ( & V_22 -> V_150 , 1 ) ;
memcpy ( V_22 -> V_208 , V_27 -> V_206 -> V_208 , sizeof( V_22 -> V_208 ) ) ;
return 0 ;
}
void F_197 ( struct V_204 * V_206 )
{
if ( F_32 ( & V_206 -> V_150 ) ) {
F_198 ( V_206 ) ;
F_10 ( V_207 , V_206 ) ;
}
}
static void F_199 ( struct V_21 * V_22 )
{
unsigned long V_209 ;
V_209 = F_200 ( V_22 -> V_39 [ V_210 ] . V_41 ) ;
if ( V_209 != V_211 ) {
V_22 -> V_212 . V_213 = F_201 ( V_209 ) ;
V_22 -> V_214 . V_215 = true ;
}
F_77 ( & V_22 -> V_216 [ 0 ] ) ;
F_77 ( & V_22 -> V_216 [ 1 ] ) ;
F_77 ( & V_22 -> V_216 [ 2 ] ) ;
}
static int F_202 ( unsigned long V_177 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_177 & V_217 )
return 0 ;
V_22 = F_203 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_117 ;
V_22 -> V_218 = 1 ;
F_61 ( & V_22 -> V_219 , 1 ) ;
F_61 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_220 = (struct V_221 ) F_204 ( V_6 -> V_222 ) ;
V_6 -> V_222 = (struct V_221 ) F_204 ( V_22 -> V_220 ) ;
F_205 ( & V_22 -> V_223 ) ;
V_22 -> V_224 = V_6 ;
F_206 ( & V_22 -> V_225 ) ;
F_77 ( & V_22 -> V_226 ) ;
F_207 ( & V_22 -> V_227 ) ;
F_208 ( & V_22 -> V_228 ) ;
F_209 ( & V_22 -> V_229 , V_230 , V_231 ) ;
V_22 -> V_229 . V_232 = V_233 ;
F_155 ( V_27 -> V_234 ) ;
memcpy ( V_22 -> V_39 , V_27 -> signal -> V_39 , sizeof V_22 -> V_39 ) ;
F_156 ( V_27 -> V_234 ) ;
F_199 ( V_22 ) ;
F_210 ( V_22 ) ;
F_211 ( V_22 ) ;
V_22 -> V_235 = V_27 -> signal -> V_235 ;
V_22 -> V_236 = V_27 -> signal -> V_236 ;
V_22 -> V_237 = V_27 -> signal -> V_237 ||
V_27 -> signal -> V_238 ;
F_212 ( & V_22 -> V_161 ) ;
return 0 ;
}
static void F_213 ( struct V_5 * V_125 )
{
#ifdef F_55
F_214 ( & V_27 -> V_206 -> V_239 ) ;
F_215 ( V_27 ) ;
V_125 -> V_52 = V_27 -> V_52 ;
if ( F_216 ( V_27 ) )
F_217 ( V_125 ) ;
if ( V_125 -> V_52 . V_160 != V_240 )
F_218 ( V_125 , V_241 ) ;
#endif
}
static void F_219 ( struct V_5 * V_125 )
{
F_220 ( & V_125 -> V_242 ) ;
#ifdef F_221
V_125 -> V_243 = V_127 ;
V_125 -> V_244 = NULL ;
V_125 -> V_245 = NULL ;
#endif
}
static void F_222 ( struct V_5 * V_6 )
{
V_6 -> V_212 . V_213 = 0 ;
V_6 -> V_212 . V_246 = 0 ;
V_6 -> V_212 . V_247 = 0 ;
F_77 ( & V_6 -> V_216 [ 0 ] ) ;
F_77 ( & V_6 -> V_216 [ 1 ] ) ;
F_77 ( & V_6 -> V_216 [ 2 ] ) ;
}
static inline void
F_223 ( struct V_5 * V_158 , enum V_248 type , struct V_249 * V_249 )
{
V_158 -> V_250 [ type ] . V_249 = V_249 ;
}
static struct V_5 * F_224 ( unsigned long V_177 ,
unsigned long V_251 ,
unsigned long V_252 ,
int T_3 * V_253 ,
struct V_249 * V_249 ,
int V_254 ,
unsigned long V_255 )
{
int V_71 ;
struct V_5 * V_125 ;
void * V_256 [ V_257 ] = {} ;
if ( ( V_177 & ( V_258 | V_188 ) ) == ( V_258 | V_188 ) )
return F_159 ( - V_259 ) ;
if ( ( V_177 & ( V_260 | V_188 ) ) == ( V_260 | V_188 ) )
return F_159 ( - V_259 ) ;
if ( ( V_177 & V_217 ) && ! ( V_177 & V_205 ) )
return F_159 ( - V_259 ) ;
if ( ( V_177 & V_205 ) && ! ( V_177 & V_184 ) )
return F_159 ( - V_259 ) ;
if ( ( V_177 & V_261 ) &&
V_27 -> signal -> V_141 & V_262 )
return F_159 ( - V_259 ) ;
if ( V_177 & V_217 ) {
if ( ( V_177 & ( V_260 | V_263 ) ) ||
( F_225 ( V_27 ) !=
V_27 -> V_264 -> V_265 ) )
return F_159 ( - V_259 ) ;
}
V_71 = F_226 ( V_177 ) ;
if ( V_71 )
goto V_266;
V_71 = - V_117 ;
V_125 = F_53 ( V_27 ) ;
if ( ! V_125 )
goto V_266;
F_227 ( V_125 ) ;
F_219 ( V_125 ) ;
#ifdef F_228
F_229 ( ! V_125 -> V_267 ) ;
F_229 ( ! V_125 -> V_268 ) ;
#endif
V_71 = - V_191 ;
if ( F_35 ( & V_125 -> V_269 -> V_270 -> V_271 ) >=
F_230 ( V_125 , V_40 ) ) {
if ( V_125 -> V_269 -> V_270 != V_272 &&
! F_231 ( V_273 ) && ! F_231 ( V_274 ) )
goto V_275;
}
V_27 -> V_141 &= ~ V_276 ;
V_71 = F_232 ( V_125 , V_177 ) ;
if ( V_71 < 0 )
goto V_275;
V_71 = - V_191 ;
if ( V_218 >= V_33 )
goto V_277;
F_233 ( V_125 ) ;
V_125 -> V_141 &= ~ ( V_278 | V_279 ) ;
V_125 -> V_141 |= V_280 ;
F_77 ( & V_125 -> V_281 ) ;
F_77 ( & V_125 -> V_282 ) ;
F_234 ( V_125 ) ;
V_125 -> V_165 = NULL ;
F_109 ( & V_125 -> V_283 ) ;
F_206 ( & V_125 -> V_284 ) ;
V_125 -> V_285 = V_125 -> V_286 = V_125 -> V_287 = 0 ;
V_125 -> V_288 = V_125 -> V_289 = 0 ;
F_208 ( & V_125 -> V_228 ) ;
#ifdef F_235
F_207 ( & V_125 -> V_290 ) ;
V_125 -> V_291 = 0 ;
V_125 -> V_292 = V_293 ;
#endif
#if F_119 ( V_294 )
memset ( & V_125 -> V_136 , 0 , sizeof( V_125 -> V_136 ) ) ;
#endif
V_125 -> V_295 = V_27 -> V_296 ;
F_236 ( & V_125 -> V_297 ) ;
F_237 ( V_125 ) ;
F_222 ( V_125 ) ;
V_125 -> V_298 = F_238 () ;
V_125 -> V_299 = F_239 () ;
V_125 -> V_198 = NULL ;
V_125 -> V_300 = NULL ;
F_240 ( V_27 ) ;
F_241 ( V_125 ) ;
#ifdef F_242
V_125 -> V_301 = F_243 ( V_125 -> V_301 ) ;
if ( F_244 ( V_125 -> V_301 ) ) {
V_71 = F_245 ( V_125 -> V_301 ) ;
V_125 -> V_301 = NULL ;
goto V_302;
}
#endif
#ifdef F_246
V_125 -> V_303 = V_203 ;
V_125 -> V_304 = V_203 ;
F_247 ( & V_125 -> V_305 ) ;
#endif
#ifdef F_248
V_125 -> V_306 = 0 ;
V_125 -> V_267 = 0 ;
V_125 -> V_307 = 0 ;
V_125 -> V_308 = 0 ;
V_125 -> V_309 = V_310 ;
V_125 -> V_311 = 0 ;
V_125 -> V_268 = 1 ;
V_125 -> V_312 = V_310 ;
V_125 -> V_313 = 0 ;
V_125 -> V_314 = 0 ;
V_125 -> V_315 = 0 ;
V_125 -> V_316 = 0 ;
V_125 -> V_317 = 0 ;
#endif
V_125 -> V_318 = 0 ;
#ifdef F_249
V_125 -> V_319 = 0 ;
V_125 -> V_320 = 0 ;
V_125 -> V_321 = 0 ;
#endif
#ifdef F_250
V_125 -> V_322 = NULL ;
#endif
#ifdef F_251
V_125 -> V_323 = 0 ;
V_125 -> V_324 = 0 ;
#endif
V_71 = F_252 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_325;
V_71 = F_253 ( V_125 ) ;
if ( V_71 )
goto V_325;
V_71 = F_254 ( V_125 ) ;
if ( V_71 )
goto V_326;
F_255 ( V_125 ) ;
V_71 = F_256 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_327;
V_71 = F_188 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_328;
V_71 = F_186 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_329;
V_71 = F_196 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_330;
V_71 = F_202 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_331;
V_71 = F_183 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_332;
V_71 = F_257 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_333;
V_71 = F_190 ( V_177 , V_125 ) ;
if ( V_71 )
goto V_334;
V_71 = F_258 ( V_177 , V_251 , V_252 , V_125 , V_255 ) ;
if ( V_71 )
goto V_335;
if ( V_249 != & V_336 ) {
V_249 = F_259 ( V_125 -> V_264 -> V_265 ) ;
if ( F_244 ( V_249 ) ) {
V_71 = F_245 ( V_249 ) ;
goto V_335;
}
}
V_125 -> V_337 = ( V_177 & V_338 ) ? V_253 : NULL ;
V_125 -> V_171 = ( V_177 & V_339 ) ? V_253 : NULL ;
#ifdef F_191
V_125 -> V_340 = NULL ;
#endif
#ifdef F_171
V_125 -> V_168 = NULL ;
#ifdef F_173
V_125 -> V_169 = NULL ;
#endif
F_77 ( & V_125 -> V_170 ) ;
V_125 -> V_341 = NULL ;
#endif
if ( ( V_177 & ( V_184 | V_342 ) ) == V_184 )
V_125 -> V_343 = V_125 -> V_344 = 0 ;
F_260 ( V_125 ) ;
F_261 ( V_125 , V_345 ) ;
#ifdef F_262
F_261 ( V_125 , F_262 ) ;
#endif
F_263 ( V_125 ) ;
V_125 -> V_249 = F_264 ( V_249 ) ;
if ( V_177 & V_217 ) {
V_125 -> V_346 = - 1 ;
V_125 -> V_234 = V_27 -> V_234 ;
V_125 -> V_347 = V_27 -> V_347 ;
} else {
if ( V_177 & V_261 )
V_125 -> V_346 = V_27 -> V_234 -> V_346 ;
else
V_125 -> V_346 = ( V_177 & V_348 ) ;
V_125 -> V_234 = V_125 ;
V_125 -> V_347 = V_125 -> V_249 ;
}
V_125 -> V_349 = 0 ;
V_125 -> V_350 = 128 >> ( V_351 - 10 ) ;
V_125 -> V_352 = 0 ;
V_125 -> V_353 = 0 ;
F_77 ( & V_125 -> V_354 ) ;
V_125 -> V_355 = NULL ;
V_71 = F_265 ( V_125 , V_256 ) ;
if ( V_71 )
goto V_356;
F_266 ( & V_1 ) ;
if ( V_177 & ( V_261 | V_217 ) ) {
V_125 -> V_357 = V_27 -> V_357 ;
V_125 -> V_358 = V_27 -> V_358 ;
} else {
V_125 -> V_357 = V_27 ;
V_125 -> V_358 = V_27 -> V_359 ;
}
F_142 ( & V_27 -> V_206 -> V_239 ) ;
F_213 ( V_125 ) ;
F_267 () ;
if ( F_268 ( V_27 ) ) {
F_144 ( & V_27 -> V_206 -> V_239 ) ;
F_269 ( & V_1 ) ;
V_71 = - V_360 ;
goto V_361;
}
if ( F_163 ( V_125 -> V_249 ) ) {
F_270 ( V_125 , ( V_177 & V_362 ) || V_254 ) ;
F_223 ( V_125 , V_363 , V_249 ) ;
if ( F_271 ( V_125 ) ) {
F_223 ( V_125 , V_364 , F_272 ( V_27 ) ) ;
F_223 ( V_125 , V_365 , F_273 ( V_27 ) ) ;
if ( F_274 ( V_249 ) ) {
F_275 ( V_249 ) -> V_366 = V_125 ;
V_125 -> signal -> V_141 |= V_262 ;
}
V_125 -> signal -> V_367 = V_249 ;
V_125 -> signal -> V_368 = F_276 ( V_27 -> signal -> V_368 ) ;
F_277 ( & V_125 -> V_282 , & V_125 -> V_357 -> V_281 ) ;
F_278 ( & V_125 -> V_369 , & V_38 . V_369 ) ;
F_279 ( V_125 , V_364 ) ;
F_279 ( V_125 , V_365 ) ;
F_280 ( V_4 ) ;
} else {
V_27 -> signal -> V_218 ++ ;
F_84 ( & V_27 -> signal -> V_219 ) ;
F_84 ( & V_27 -> signal -> V_24 ) ;
F_278 ( & V_125 -> V_354 ,
& V_125 -> V_234 -> V_354 ) ;
F_278 ( & V_125 -> V_222 ,
& V_125 -> signal -> V_220 ) ;
}
F_279 ( V_125 , V_363 ) ;
V_218 ++ ;
}
V_370 ++ ;
F_144 ( & V_27 -> V_206 -> V_239 ) ;
F_281 ( V_125 ) ;
F_269 ( & V_1 ) ;
F_282 ( V_125 ) ;
F_283 ( V_125 , V_256 ) ;
F_284 ( V_27 ) ;
F_285 ( V_125 ) ;
F_286 ( V_125 , V_177 ) ;
F_287 ( V_125 , V_177 ) ;
return V_125 ;
V_361:
F_288 ( V_125 , V_256 ) ;
V_356:
if ( V_249 != & V_336 )
F_289 ( V_249 ) ;
V_335:
if ( V_125 -> V_198 )
F_290 ( V_125 ) ;
V_334:
F_291 ( V_125 ) ;
V_333:
if ( V_125 -> V_61 )
F_133 ( V_125 -> V_61 ) ;
V_332:
if ( ! ( V_177 & V_217 ) )
F_28 ( V_125 -> signal ) ;
V_331:
F_197 ( V_125 -> V_206 ) ;
V_330:
F_292 ( V_125 ) ;
V_329:
F_293 ( V_125 ) ;
V_328:
F_294 ( V_125 ) ;
V_327:
F_295 ( V_125 ) ;
V_326:
F_296 ( V_125 ) ;
V_325:
#ifdef F_242
F_97 ( V_125 -> V_301 ) ;
V_302:
#endif
F_284 ( V_27 ) ;
F_40 ( V_125 ) ;
V_277:
F_82 ( & V_125 -> V_371 -> V_270 -> V_271 ) ;
F_39 ( V_125 ) ;
V_275:
F_24 ( V_125 ) ;
V_266:
return F_159 ( V_71 ) ;
}
static inline void F_297 ( struct V_372 * V_373 )
{
enum V_248 type ;
for ( type = V_363 ; type < V_374 ; ++ type ) {
F_298 ( & V_373 [ type ] . V_7 ) ;
V_373 [ type ] . V_249 = & V_336 ;
}
}
struct V_5 * F_299 ( int V_2 )
{
struct V_5 * V_158 ;
V_158 = F_224 ( V_184 , 0 , 0 , NULL , & V_336 , 0 , 0 ) ;
if ( ! F_244 ( V_158 ) ) {
F_297 ( V_158 -> V_250 ) ;
F_300 ( V_158 , V_2 ) ;
}
return V_158 ;
}
long F_301 ( unsigned long V_177 ,
unsigned long V_251 ,
unsigned long V_252 ,
int T_3 * V_375 ,
int T_3 * V_253 ,
unsigned long V_255 )
{
struct V_5 * V_125 ;
int V_254 = 0 ;
long V_376 ;
if ( ! ( V_177 & V_377 ) ) {
if ( V_177 & V_342 )
V_254 = V_378 ;
else if ( ( V_177 & V_348 ) != V_379 )
V_254 = V_380 ;
else
V_254 = V_381 ;
if ( F_163 ( ! F_302 ( V_27 , V_254 ) ) )
V_254 = 0 ;
}
V_125 = F_224 ( V_177 , V_251 , V_252 ,
V_253 , NULL , V_254 , V_255 ) ;
if ( ! F_244 ( V_125 ) ) {
struct V_163 V_164 ;
struct V_249 * V_249 ;
F_303 ( V_27 , V_125 ) ;
V_249 = F_304 ( V_125 , V_363 ) ;
V_376 = F_305 ( V_249 ) ;
if ( V_177 & V_382 )
F_178 ( V_376 , V_375 ) ;
if ( V_177 & V_342 ) {
V_125 -> V_165 = & V_164 ;
F_306 ( & V_164 ) ;
F_307 ( V_125 ) ;
}
F_308 ( V_125 ) ;
if ( F_102 ( V_254 ) )
F_309 ( V_254 , V_249 ) ;
if ( V_177 & V_342 ) {
if ( ! F_165 ( V_125 , & V_164 ) )
F_309 ( V_383 , V_249 ) ;
}
F_310 ( V_249 ) ;
} else {
V_376 = F_245 ( V_125 ) ;
}
return V_376 ;
}
long F_311 ( unsigned long V_177 ,
unsigned long V_251 ,
unsigned long V_252 ,
int T_3 * V_375 ,
int T_3 * V_253 )
{
return F_301 ( V_177 , V_251 , V_252 ,
V_375 , V_253 , 0 ) ;
}
T_4 F_312 ( int (* F_313)( void * ) , void * V_384 , unsigned long V_141 )
{
return F_301 ( V_141 | V_184 | V_377 , ( unsigned long ) F_313 ,
( unsigned long ) V_384 , NULL , NULL , 0 ) ;
}
static void F_314 ( void * V_385 )
{
struct V_204 * V_206 = V_385 ;
F_109 ( & V_206 -> V_239 ) ;
F_205 ( & V_206 -> V_386 ) ;
}
void T_1 F_315 ( void )
{
V_207 = F_18 ( L_7 ,
sizeof( struct V_204 ) , 0 ,
V_387 | V_36 | V_388 |
V_37 , F_314 ) ;
V_23 = F_18 ( L_8 ,
sizeof( struct V_21 ) , 0 ,
V_387 | V_36 | V_37 , NULL ) ;
V_389 = F_18 ( L_9 ,
sizeof( struct V_193 ) , 0 ,
V_387 | V_36 | V_37 , NULL ) ;
V_390 = F_18 ( L_10 ,
sizeof( struct V_186 ) , 0 ,
V_387 | V_36 | V_37 , NULL ) ;
V_391 = F_18 ( L_11 ,
sizeof( struct V_60 ) , V_392 ,
V_387 | V_36 | V_37 , NULL ) ;
V_91 = F_316 ( V_63 , V_36 ) ;
F_317 () ;
F_318 () ;
}
static int F_319 ( unsigned long V_393 )
{
if ( V_393 & ~ ( V_217 | V_188 | V_258 | V_205 |
V_184 | V_197 | V_394 |
V_395 | V_396 | V_397 |
V_260 | V_263 ) )
return - V_259 ;
if ( V_393 & ( V_217 | V_205 | V_184 ) ) {
if ( ! F_320 ( V_27 ) )
return - V_259 ;
}
if ( V_393 & ( V_205 | V_184 ) ) {
if ( F_35 ( & V_27 -> V_206 -> V_150 ) > 1 )
return - V_259 ;
}
if ( V_393 & V_184 ) {
if ( ! F_321 () )
return - V_259 ;
}
return 0 ;
}
static int F_322 ( unsigned long V_393 , struct V_186 * * V_398 )
{
struct V_186 * V_187 = V_27 -> V_187 ;
if ( ! ( V_393 & V_188 ) || ! V_187 )
return 0 ;
if ( V_187 -> V_192 == 1 )
return 0 ;
* V_398 = F_187 ( V_187 ) ;
if ( ! * V_398 )
return - V_117 ;
return 0 ;
}
static int F_323 ( unsigned long V_393 , struct V_193 * * V_399 )
{
struct V_193 * V_400 = V_27 -> V_196 ;
int error = 0 ;
if ( ( V_393 & V_197 ) &&
( V_400 && F_35 ( & V_400 -> V_150 ) > 1 ) ) {
* V_399 = F_189 ( V_400 , & error ) ;
if ( ! * V_399 )
return error ;
}
return 0 ;
}
int F_324 ( struct V_193 * * V_401 )
{
struct V_5 * V_158 = V_27 ;
struct V_193 * V_402 = NULL ;
int error ;
error = F_323 ( V_197 , & V_402 ) ;
if ( error || ! V_402 ) {
* V_401 = NULL ;
return error ;
}
* V_401 = V_158 -> V_196 ;
F_155 ( V_158 ) ;
V_158 -> V_196 = V_402 ;
F_156 ( V_158 ) ;
return 0 ;
}
int F_325 ( struct V_403 * V_404 , int V_405 ,
void T_3 * V_406 , T_5 * V_407 , T_6 * V_408 )
{
struct V_403 V_409 ;
int V_410 ;
int V_29 = V_33 ;
int V_411 = V_34 ;
int V_412 = V_32 ;
V_409 = * V_404 ;
V_409 . V_385 = & V_29 ;
V_409 . V_413 = & V_411 ;
V_409 . V_414 = & V_412 ;
V_410 = F_326 ( & V_409 , V_405 , V_406 , V_407 , V_408 ) ;
if ( V_410 || ! V_405 )
return V_410 ;
F_43 ( V_29 ) ;
return 0 ;
}
