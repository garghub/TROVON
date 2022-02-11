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
F_18 ( L_2 , sizeof( struct V_5 ) ,
F_48 , V_35 | V_36 , NULL ) ;
#endif
F_41 () ;
F_42 ( V_32 ) ;
V_37 . signal -> V_38 [ V_39 ] . V_40 = V_33 / 2 ;
V_37 . signal -> V_38 [ V_39 ] . V_41 = V_33 / 2 ;
V_37 . signal -> V_38 [ V_42 ] =
V_37 . signal -> V_38 [ V_39 ] ;
}
int __weak F_49 ( struct V_5 * V_43 ,
struct V_5 * V_44 )
{
* V_43 = * V_44 ;
return 0 ;
}
void F_50 ( struct V_5 * V_6 )
{
unsigned long * V_45 ;
V_45 = F_51 ( V_6 ) ;
* V_45 = V_46 ;
}
static struct V_5 * F_52 ( struct V_5 * V_47 )
{
struct V_5 * V_6 ;
struct V_10 * V_11 ;
int V_7 = F_53 ( V_47 ) ;
int V_48 ;
V_6 = F_7 ( V_7 ) ;
if ( ! V_6 )
return NULL ;
V_11 = F_12 ( V_6 , V_7 ) ;
if ( ! V_11 )
goto V_49;
V_48 = F_49 ( V_6 , V_47 ) ;
if ( V_48 )
goto V_50;
V_6 -> V_20 = V_11 ;
#ifdef F_54
V_6 -> V_51 . V_52 = NULL ;
#endif
F_55 ( V_6 , V_47 ) ;
F_56 ( V_6 ) ;
F_57 ( V_6 ) ;
F_50 ( V_6 ) ;
#ifdef F_58
V_6 -> V_53 = F_59 () ;
#endif
F_60 ( & V_6 -> V_26 , 2 ) ;
#ifdef F_61
V_6 -> V_54 = 0 ;
#endif
V_6 -> V_55 = NULL ;
V_6 -> V_56 . V_12 = NULL ;
F_20 ( V_11 , 1 ) ;
return V_6 ;
V_50:
F_15 ( V_11 ) ;
V_49:
F_9 ( V_6 ) ;
return NULL ;
}
static int F_62 ( struct V_57 * V_58 , struct V_57 * V_59 )
{
struct V_60 * V_61 , * V_62 , * V_63 , * * V_64 ;
struct V_65 * * V_66 , * V_67 ;
int V_68 ;
unsigned long V_69 ;
F_63 () ;
F_64 ( & V_59 -> V_70 ) ;
F_65 ( V_59 ) ;
F_66 ( V_59 , V_58 ) ;
F_67 ( & V_58 -> V_70 , V_71 ) ;
F_68 ( V_58 -> V_72 , F_69 ( V_59 ) ) ;
V_58 -> V_73 = V_59 -> V_73 ;
V_58 -> V_74 = V_59 -> V_74 ;
V_58 -> V_75 = V_59 -> V_75 ;
V_58 -> V_76 = V_59 -> V_76 ;
V_66 = & V_58 -> V_77 . V_65 ;
V_67 = NULL ;
V_64 = & V_58 -> V_78 ;
V_68 = F_70 ( V_58 , V_59 ) ;
if ( V_68 )
goto V_79;
V_68 = F_71 ( V_58 , V_59 ) ;
if ( V_68 )
goto V_79;
V_63 = NULL ;
for ( V_61 = V_59 -> V_78 ; V_61 ; V_61 = V_61 -> V_80 ) {
struct V_81 * V_81 ;
if ( V_61 -> V_82 & V_83 ) {
F_72 ( V_58 , V_61 -> V_82 , V_61 -> V_84 ,
- F_73 ( V_61 ) ) ;
continue;
}
V_69 = 0 ;
if ( V_61 -> V_82 & V_85 ) {
unsigned long V_86 = F_73 ( V_61 ) ;
if ( F_74 ( V_59 , V_86 ) )
goto V_87;
V_69 = V_86 ;
}
V_62 = F_75 ( V_88 , V_9 ) ;
if ( ! V_62 )
goto V_87;
* V_62 = * V_61 ;
F_76 ( & V_62 -> V_89 ) ;
V_68 = F_77 ( V_61 , V_62 ) ;
if ( V_68 )
goto V_90;
V_62 -> V_91 = V_58 ;
if ( F_78 ( V_62 , V_61 ) )
goto V_92;
V_62 -> V_82 &= ~ V_93 ;
V_62 -> V_80 = V_62 -> V_94 = NULL ;
V_81 = V_62 -> V_84 ;
if ( V_81 ) {
struct V_95 * V_95 = F_79 ( V_81 ) ;
struct V_96 * V_97 = V_81 -> V_98 ;
F_80 ( V_81 ) ;
if ( V_62 -> V_82 & V_99 )
F_81 ( & V_95 -> V_100 ) ;
F_82 ( V_97 ) ;
if ( V_62 -> V_82 & V_101 )
F_83 ( & V_97 -> V_102 ) ;
F_84 ( V_97 ) ;
F_85 ( V_62 , V_61 ,
& V_97 -> V_103 ) ;
F_86 ( V_97 ) ;
F_87 ( V_97 ) ;
}
if ( F_88 ( V_62 ) )
F_89 ( V_62 ) ;
* V_64 = V_62 ;
V_64 = & V_62 -> V_80 ;
V_62 -> V_94 = V_63 ;
V_63 = V_62 ;
F_90 ( V_58 , V_62 , V_66 , V_67 ) ;
V_66 = & V_62 -> V_104 . V_105 ;
V_67 = & V_62 -> V_104 ;
V_58 -> V_106 ++ ;
V_68 = F_91 ( V_58 , V_59 , V_61 ) ;
if ( V_62 -> V_107 && V_62 -> V_107 -> V_108 )
V_62 -> V_107 -> V_108 ( V_62 ) ;
if ( V_68 )
goto V_79;
}
F_92 ( V_59 , V_58 ) ;
V_68 = 0 ;
V_79:
F_93 ( & V_58 -> V_70 ) ;
F_94 ( V_59 ) ;
F_93 ( & V_59 -> V_70 ) ;
F_95 () ;
return V_68 ;
V_92:
F_96 ( F_97 ( V_62 ) ) ;
V_90:
F_10 ( V_88 , V_62 ) ;
V_87:
V_68 = - V_109 ;
F_98 ( V_69 ) ;
goto V_79;
}
static inline int F_99 ( struct V_57 * V_58 )
{
V_58 -> V_110 = F_100 ( V_58 ) ;
if ( F_101 ( ! V_58 -> V_110 ) )
return - V_109 ;
return 0 ;
}
static inline void F_102 ( struct V_57 * V_58 )
{
F_103 ( V_58 , V_58 -> V_110 ) ;
}
static int F_62 ( struct V_57 * V_58 , struct V_57 * V_59 )
{
F_64 ( & V_59 -> V_70 ) ;
F_68 ( V_58 -> V_72 , F_69 ( V_59 ) ) ;
F_93 ( & V_59 -> V_70 ) ;
return 0 ;
}
static int T_1 F_104 ( char * V_111 )
{
V_112 =
( F_105 ( V_111 , NULL , 0 ) << V_113 ) &
V_114 ;
return 1 ;
}
static void F_106 ( struct V_57 * V_58 )
{
#ifdef F_107
F_108 ( & V_58 -> V_115 ) ;
V_58 -> V_116 = NULL ;
#endif
}
static void F_109 ( struct V_57 * V_58 , struct V_5 * V_117 )
{
#ifdef F_110
V_58 -> V_118 = V_117 ;
#endif
}
static struct V_57 * F_111 ( struct V_57 * V_58 , struct V_5 * V_117 )
{
V_58 -> V_78 = NULL ;
V_58 -> V_77 = V_119 ;
V_58 -> V_120 = 0 ;
F_60 ( & V_58 -> V_121 , 1 ) ;
F_60 ( & V_58 -> V_122 , 1 ) ;
F_112 ( & V_58 -> V_70 ) ;
F_76 ( & V_58 -> V_123 ) ;
V_58 -> V_124 = NULL ;
F_113 ( & V_58 -> V_125 , 0 ) ;
F_114 ( V_58 ) ;
V_58 -> V_106 = 0 ;
V_58 -> V_126 = 0 ;
V_58 -> V_127 = 0 ;
memset ( & V_58 -> V_128 , 0 , sizeof( V_58 -> V_128 ) ) ;
F_108 ( & V_58 -> V_129 ) ;
F_115 ( V_58 ) ;
F_106 ( V_58 ) ;
F_109 ( V_58 , V_117 ) ;
F_116 ( V_58 ) ;
F_117 ( V_58 ) ;
#if F_118 ( V_130 ) && ! V_131
V_58 -> V_132 = NULL ;
#endif
if ( V_27 -> V_58 ) {
V_58 -> V_133 = V_27 -> V_58 -> V_133 & V_134 ;
V_58 -> V_135 = V_27 -> V_58 -> V_135 & V_136 ;
} else {
V_58 -> V_133 = V_112 ;
V_58 -> V_135 = 0 ;
}
if ( F_99 ( V_58 ) )
goto V_137;
if ( F_119 ( V_117 , V_58 ) )
goto V_138;
return V_58 ;
V_138:
F_102 ( V_58 ) ;
V_137:
F_120 ( V_58 ) ;
return NULL ;
}
static void F_121 ( struct V_57 * V_58 )
{
int V_139 ;
for ( V_139 = 0 ; V_139 < V_140 ; V_139 ++ ) {
long V_141 = F_122 ( & V_58 -> V_128 . V_142 [ V_139 ] ) ;
if ( F_101 ( V_141 ) )
F_123 ( V_143 L_3
L_4 , V_58 , V_139 , V_141 ) ;
}
if ( F_122 ( & V_58 -> V_125 ) )
F_124 ( L_5 ,
F_122 ( & V_58 -> V_125 ) ) ;
if ( F_125 ( V_58 ) )
F_124 ( L_6 ,
F_125 ( V_58 ) ) ;
#if F_118 ( V_130 ) && ! V_131
F_126 ( V_58 -> V_132 , V_58 ) ;
#endif
}
struct V_57 * F_127 ( void )
{
struct V_57 * V_58 ;
V_58 = F_128 () ;
if ( ! V_58 )
return NULL ;
memset ( V_58 , 0 , sizeof( * V_58 ) ) ;
return F_111 ( V_58 , V_27 ) ;
}
void F_129 ( struct V_57 * V_58 )
{
F_19 ( V_58 == & V_144 ) ;
F_102 ( V_58 ) ;
F_130 ( V_58 ) ;
F_131 ( V_58 ) ;
F_121 ( V_58 ) ;
F_120 ( V_58 ) ;
}
void F_132 ( struct V_57 * V_58 )
{
F_133 () ;
if ( F_32 ( & V_58 -> V_121 ) ) {
F_134 ( V_58 ) ;
F_135 ( V_58 ) ;
F_136 ( V_58 ) ;
F_137 ( V_58 ) ;
F_138 ( V_58 ) ;
F_139 ( V_58 , NULL ) ;
if ( ! F_140 ( & V_58 -> V_123 ) ) {
F_141 ( & V_145 ) ;
F_142 ( & V_58 -> V_123 ) ;
F_143 ( & V_145 ) ;
}
if ( V_58 -> V_146 )
F_144 ( V_58 -> V_146 -> V_147 ) ;
F_145 ( V_58 ) ;
}
}
void F_139 ( struct V_57 * V_58 , struct V_81 * V_148 )
{
struct V_81 * V_149 ;
V_149 = F_146 ( V_58 -> V_72 ) ;
if ( V_148 )
F_80 ( V_148 ) ;
F_147 ( V_58 -> V_72 , V_148 ) ;
if ( V_149 )
F_148 ( V_149 ) ;
}
struct V_81 * F_69 ( struct V_57 * V_58 )
{
struct V_81 * V_72 ;
F_149 () ;
V_72 = F_150 ( V_58 -> V_72 ) ;
if ( V_72 && ! F_151 ( V_72 ) )
V_72 = NULL ;
F_152 () ;
return V_72 ;
}
struct V_57 * F_153 ( struct V_5 * V_150 )
{
struct V_57 * V_58 ;
F_154 ( V_150 ) ;
V_58 = V_150 -> V_58 ;
if ( V_58 ) {
if ( V_150 -> V_133 & V_151 )
V_58 = NULL ;
else
F_83 ( & V_58 -> V_121 ) ;
}
F_155 ( V_150 ) ;
return V_58 ;
}
struct V_57 * F_156 ( struct V_5 * V_150 , unsigned int V_152 )
{
struct V_57 * V_58 ;
int V_48 ;
V_48 = F_157 ( & V_150 -> signal -> V_153 ) ;
if ( V_48 )
return F_158 ( V_48 ) ;
V_58 = F_153 ( V_150 ) ;
if ( V_58 && V_58 != V_27 -> V_58 &&
! F_159 ( V_150 , V_152 ) ) {
F_132 ( V_58 ) ;
V_58 = F_158 ( - V_154 ) ;
}
F_160 ( & V_150 -> signal -> V_153 ) ;
return V_58 ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_155 * V_156 ;
F_154 ( V_6 ) ;
V_156 = V_6 -> V_157 ;
if ( F_162 ( V_156 ) ) {
V_6 -> V_157 = NULL ;
F_163 ( V_156 ) ;
}
F_155 ( V_6 ) ;
}
static int F_164 ( struct V_5 * V_158 ,
struct V_155 * V_156 )
{
int V_159 ;
F_165 () ;
V_159 = F_166 ( V_156 ) ;
F_167 () ;
if ( V_159 ) {
F_154 ( V_158 ) ;
V_158 -> V_157 = NULL ;
F_155 ( V_158 ) ;
}
F_168 ( V_158 ) ;
return V_159 ;
}
void F_169 ( struct V_5 * V_6 , struct V_57 * V_58 )
{
#ifdef F_170
if ( F_101 ( V_6 -> V_160 ) ) {
F_171 ( V_6 ) ;
V_6 -> V_160 = NULL ;
}
#ifdef F_172
if ( F_101 ( V_6 -> V_161 ) ) {
F_173 ( V_6 ) ;
V_6 -> V_161 = NULL ;
}
#endif
if ( F_101 ( ! F_140 ( & V_6 -> V_162 ) ) )
F_174 ( V_6 ) ;
#endif
F_175 ( V_6 ) ;
F_176 ( V_6 , V_58 ) ;
if ( V_6 -> V_163 ) {
if ( ! ( V_6 -> V_133 & V_164 ) &&
F_35 ( & V_58 -> V_121 ) > 1 ) {
F_177 ( 0 , V_6 -> V_163 ) ;
F_178 ( V_6 -> V_163 , V_165 ,
1 , NULL , NULL , 0 ) ;
}
V_6 -> V_163 = NULL ;
}
if ( V_6 -> V_157 )
F_161 ( V_6 ) ;
}
static struct V_57 * F_179 ( struct V_5 * V_6 )
{
struct V_57 * V_58 , * V_59 = V_27 -> V_58 ;
int V_48 ;
V_58 = F_128 () ;
if ( ! V_58 )
goto V_87;
memcpy ( V_58 , V_59 , sizeof( * V_58 ) ) ;
if ( ! F_111 ( V_58 , V_6 ) )
goto V_87;
V_48 = F_62 ( V_58 , V_59 ) ;
if ( V_48 )
goto V_166;
V_58 -> V_167 = F_180 ( V_58 ) ;
V_58 -> V_168 = V_58 -> V_73 ;
if ( V_58 -> V_146 && ! F_181 ( V_58 -> V_146 -> V_147 ) )
goto V_166;
return V_58 ;
V_166:
V_58 -> V_146 = NULL ;
F_132 ( V_58 ) ;
V_87:
return NULL ;
}
static int F_182 ( unsigned long V_169 , struct V_5 * V_6 )
{
struct V_57 * V_58 , * V_59 ;
int V_68 ;
V_6 -> V_170 = V_6 -> V_171 = 0 ;
V_6 -> V_172 = V_6 -> V_173 = 0 ;
#ifdef F_183
V_6 -> V_174 = V_6 -> V_172 + V_6 -> V_173 ;
#endif
V_6 -> V_58 = NULL ;
V_6 -> V_175 = NULL ;
V_59 = V_27 -> V_58 ;
if ( ! V_59 )
return 0 ;
F_184 ( V_6 ) ;
if ( V_169 & V_176 ) {
F_83 ( & V_59 -> V_121 ) ;
V_58 = V_59 ;
goto V_177;
}
V_68 = - V_109 ;
V_58 = F_179 ( V_6 ) ;
if ( ! V_58 )
goto V_87;
V_177:
V_6 -> V_58 = V_58 ;
V_6 -> V_175 = V_58 ;
return 0 ;
V_87:
return V_68 ;
}
static int F_185 ( unsigned long V_169 , struct V_5 * V_6 )
{
struct V_178 * V_179 = V_27 -> V_179 ;
if ( V_169 & V_180 ) {
F_141 ( & V_179 -> V_181 ) ;
if ( V_179 -> V_182 ) {
F_143 ( & V_179 -> V_181 ) ;
return - V_183 ;
}
V_179 -> V_184 ++ ;
F_143 ( & V_179 -> V_181 ) ;
return 0 ;
}
V_6 -> V_179 = F_186 ( V_179 ) ;
if ( ! V_6 -> V_179 )
return - V_109 ;
return 0 ;
}
static int F_187 ( unsigned long V_169 , struct V_5 * V_6 )
{
struct V_185 * V_186 , * V_187 ;
int error = 0 ;
V_186 = V_27 -> V_188 ;
if ( ! V_186 )
goto V_79;
if ( V_169 & V_189 ) {
F_83 ( & V_186 -> V_142 ) ;
goto V_79;
}
V_187 = F_188 ( V_186 , & error ) ;
if ( ! V_187 )
goto V_79;
V_6 -> V_188 = V_187 ;
error = 0 ;
V_79:
return error ;
}
static int F_189 ( unsigned long V_169 , struct V_5 * V_6 )
{
#ifdef F_190
struct V_190 * V_191 = V_27 -> V_190 ;
struct V_190 * V_192 ;
if ( ! V_191 )
return 0 ;
if ( V_169 & V_193 ) {
F_191 ( V_191 ) ;
V_6 -> V_190 = V_191 ;
} else if ( F_192 ( V_191 -> V_194 ) ) {
V_192 = F_193 ( V_6 , V_9 , V_195 ) ;
if ( F_101 ( ! V_192 ) )
return - V_109 ;
V_192 -> V_194 = V_191 -> V_194 ;
F_194 ( V_192 ) ;
}
#endif
return 0 ;
}
static int F_195 ( unsigned long V_169 , struct V_5 * V_6 )
{
struct V_196 * V_22 ;
if ( V_169 & V_197 ) {
F_83 ( & V_27 -> V_198 -> V_142 ) ;
return 0 ;
}
V_22 = F_75 ( V_199 , V_9 ) ;
F_147 ( V_6 -> V_198 , V_22 ) ;
if ( ! V_22 )
return - V_109 ;
F_60 ( & V_22 -> V_142 , 1 ) ;
memcpy ( V_22 -> V_200 , V_27 -> V_198 -> V_200 , sizeof( V_22 -> V_200 ) ) ;
return 0 ;
}
void F_196 ( struct V_196 * V_198 )
{
if ( F_32 ( & V_198 -> V_142 ) ) {
F_197 ( V_198 ) ;
F_10 ( V_199 , V_198 ) ;
}
}
static void F_198 ( struct V_21 * V_22 )
{
unsigned long V_201 ;
F_199 ( V_22 ) ;
V_201 = F_200 ( V_22 -> V_38 [ V_202 ] . V_40 ) ;
if ( V_201 != V_203 ) {
V_22 -> V_204 . V_205 = F_201 ( V_201 ) ;
V_22 -> V_206 . V_207 = 1 ;
}
F_76 ( & V_22 -> V_208 [ 0 ] ) ;
F_76 ( & V_22 -> V_208 [ 1 ] ) ;
F_76 ( & V_22 -> V_208 [ 2 ] ) ;
}
static int F_202 ( unsigned long V_169 , struct V_5 * V_6 )
{
struct V_21 * V_22 ;
if ( V_169 & V_209 )
return 0 ;
V_22 = F_203 ( V_23 , V_9 ) ;
V_6 -> signal = V_22 ;
if ( ! V_22 )
return - V_109 ;
V_22 -> V_210 = 1 ;
F_60 ( & V_22 -> V_211 , 1 ) ;
F_60 ( & V_22 -> V_24 , 1 ) ;
V_22 -> V_212 = (struct V_213 ) F_204 ( V_6 -> V_214 ) ;
V_6 -> V_214 = (struct V_213 ) F_204 ( V_22 -> V_212 ) ;
F_205 ( & V_22 -> V_215 ) ;
V_22 -> V_216 = V_6 ;
F_206 ( & V_22 -> V_217 ) ;
F_76 ( & V_22 -> V_218 ) ;
F_207 ( & V_22 -> V_219 ) ;
F_208 ( & V_22 -> V_220 , V_221 , V_222 ) ;
V_22 -> V_220 . V_223 = V_224 ;
F_154 ( V_27 -> V_225 ) ;
memcpy ( V_22 -> V_38 , V_27 -> signal -> V_38 , sizeof V_22 -> V_38 ) ;
F_155 ( V_27 -> V_225 ) ;
F_198 ( V_22 ) ;
F_209 ( V_22 ) ;
F_210 ( V_22 ) ;
#ifdef F_211
F_112 ( & V_22 -> V_226 ) ;
#endif
V_22 -> V_227 = V_27 -> signal -> V_227 ;
V_22 -> V_228 = V_27 -> signal -> V_228 ;
V_22 -> V_229 = V_27 -> signal -> V_229 ||
V_27 -> signal -> V_230 ;
F_212 ( & V_22 -> V_153 ) ;
return 0 ;
}
static void F_213 ( struct V_5 * V_117 )
{
#ifdef F_54
F_214 ( & V_27 -> V_198 -> V_231 ) ;
F_215 ( V_27 ) ;
V_117 -> V_51 = V_27 -> V_51 ;
if ( F_216 ( V_27 ) )
F_217 ( V_117 ) ;
if ( V_117 -> V_51 . V_152 != V_232 )
F_218 ( V_117 , V_233 ) ;
#endif
}
static void F_219 ( struct V_5 * V_117 )
{
F_220 ( & V_117 -> V_234 ) ;
#ifdef F_221
V_117 -> V_235 = V_119 ;
V_117 -> V_236 = NULL ;
V_117 -> V_237 = NULL ;
#endif
}
static void F_222 ( struct V_5 * V_6 )
{
V_6 -> V_204 . V_205 = 0 ;
V_6 -> V_204 . V_238 = 0 ;
V_6 -> V_204 . V_239 = 0 ;
F_76 ( & V_6 -> V_208 [ 0 ] ) ;
F_76 ( & V_6 -> V_208 [ 1 ] ) ;
F_76 ( & V_6 -> V_208 [ 2 ] ) ;
}
static inline void
F_223 ( struct V_5 * V_150 , enum V_240 type , struct V_241 * V_241 )
{
V_150 -> V_242 [ type ] . V_241 = V_241 ;
}
static struct V_5 * F_224 ( unsigned long V_169 ,
unsigned long V_243 ,
unsigned long V_244 ,
int T_3 * V_245 ,
struct V_241 * V_241 ,
int V_246 )
{
int V_68 ;
struct V_5 * V_117 ;
if ( ( V_169 & ( V_247 | V_180 ) ) == ( V_247 | V_180 ) )
return F_158 ( - V_248 ) ;
if ( ( V_169 & ( V_249 | V_180 ) ) == ( V_249 | V_180 ) )
return F_158 ( - V_248 ) ;
if ( ( V_169 & V_209 ) && ! ( V_169 & V_197 ) )
return F_158 ( - V_248 ) ;
if ( ( V_169 & V_197 ) && ! ( V_169 & V_176 ) )
return F_158 ( - V_248 ) ;
if ( ( V_169 & V_250 ) &&
V_27 -> signal -> V_133 & V_251 )
return F_158 ( - V_248 ) ;
if ( V_169 & V_197 ) {
if ( ( V_169 & ( V_249 | V_252 ) ) ||
( F_225 ( V_27 ) !=
V_27 -> V_253 -> V_254 ) )
return F_158 ( - V_248 ) ;
}
V_68 = F_226 ( V_169 ) ;
if ( V_68 )
goto V_255;
V_68 = - V_109 ;
V_117 = F_52 ( V_27 ) ;
if ( ! V_117 )
goto V_255;
F_227 ( V_117 ) ;
F_219 ( V_117 ) ;
#ifdef F_228
F_229 ( ! V_117 -> V_256 ) ;
F_229 ( ! V_117 -> V_257 ) ;
#endif
V_68 = - V_183 ;
if ( F_35 ( & V_117 -> V_258 -> V_259 -> V_260 ) >=
F_230 ( V_117 , V_39 ) ) {
if ( V_117 -> V_258 -> V_259 != V_261 &&
! F_231 ( V_262 ) && ! F_231 ( V_263 ) )
goto V_264;
}
V_27 -> V_133 &= ~ V_265 ;
V_68 = F_232 ( V_117 , V_169 ) ;
if ( V_68 < 0 )
goto V_264;
V_68 = - V_183 ;
if ( V_210 >= V_33 )
goto V_266;
F_233 ( V_117 ) ;
V_117 -> V_133 &= ~ ( V_267 | V_268 ) ;
V_117 -> V_133 |= V_269 ;
F_76 ( & V_117 -> V_270 ) ;
F_76 ( & V_117 -> V_271 ) ;
F_234 ( V_117 ) ;
V_117 -> V_157 = NULL ;
F_108 ( & V_117 -> V_272 ) ;
F_206 ( & V_117 -> V_273 ) ;
V_117 -> V_274 = V_117 -> V_275 = V_117 -> V_276 = 0 ;
V_117 -> V_277 = V_117 -> V_278 = 0 ;
#ifndef F_235
V_117 -> V_279 . V_274 = V_117 -> V_279 . V_275 = 0 ;
#endif
#ifdef F_236
F_207 ( & V_117 -> V_280 ) ;
V_117 -> V_281 = 0 ;
V_117 -> V_282 = V_283 ;
#endif
#if F_118 ( V_284 )
memset ( & V_117 -> V_128 , 0 , sizeof( V_117 -> V_128 ) ) ;
#endif
V_117 -> V_285 = V_27 -> V_286 ;
F_237 ( & V_117 -> V_287 ) ;
F_238 ( V_117 ) ;
F_222 ( V_117 ) ;
V_117 -> V_288 = F_239 () ;
V_117 -> V_289 = F_240 () ;
V_117 -> V_190 = NULL ;
V_117 -> V_290 = NULL ;
if ( V_169 & V_209 )
F_241 ( V_27 ) ;
F_242 ( V_117 ) ;
#ifdef F_243
V_117 -> V_291 = F_244 ( V_117 -> V_291 ) ;
if ( F_245 ( V_117 -> V_291 ) ) {
V_68 = F_246 ( V_117 -> V_291 ) ;
V_117 -> V_291 = NULL ;
goto V_292;
}
#endif
#ifdef F_247
V_117 -> V_293 = V_195 ;
V_117 -> V_294 = V_195 ;
F_248 ( & V_117 -> V_295 ) ;
#endif
#ifdef F_249
V_117 -> V_296 = 0 ;
V_117 -> V_256 = 0 ;
V_117 -> V_297 = 0 ;
V_117 -> V_298 = 0 ;
V_117 -> V_299 = V_300 ;
V_117 -> V_301 = 0 ;
V_117 -> V_257 = 1 ;
V_117 -> V_302 = V_300 ;
V_117 -> V_303 = 0 ;
V_117 -> V_304 = 0 ;
V_117 -> V_305 = 0 ;
V_117 -> V_306 = 0 ;
V_117 -> V_307 = 0 ;
#endif
#ifdef F_250
V_117 -> V_308 = 0 ;
V_117 -> V_309 = 0 ;
V_117 -> V_310 = 0 ;
#endif
#ifdef F_251
V_117 -> V_311 = NULL ;
#endif
#ifdef F_252
V_117 -> V_312 = 0 ;
V_117 -> V_313 = 0 ;
#endif
V_68 = F_253 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_314;
V_68 = F_254 ( V_117 ) ;
if ( V_68 )
goto V_314;
V_68 = F_255 ( V_117 ) ;
if ( V_68 )
goto V_315;
F_256 ( V_117 ) ;
V_68 = F_257 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_316;
V_68 = F_187 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_317;
V_68 = F_185 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_318;
V_68 = F_195 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_319;
V_68 = F_202 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_320;
V_68 = F_182 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_321;
V_68 = F_258 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_322;
V_68 = F_189 ( V_169 , V_117 ) ;
if ( V_68 )
goto V_323;
V_68 = F_259 ( V_169 , V_243 , V_244 , V_117 ) ;
if ( V_68 )
goto V_324;
if ( V_241 != & V_325 ) {
V_241 = F_260 ( V_117 -> V_253 -> V_254 ) ;
if ( F_245 ( V_241 ) ) {
V_68 = F_246 ( V_241 ) ;
goto V_324;
}
}
V_117 -> V_326 = ( V_169 & V_327 ) ? V_245 : NULL ;
V_117 -> V_163 = ( V_169 & V_328 ) ? V_245 : NULL ;
#ifdef F_190
V_117 -> V_329 = NULL ;
#endif
#ifdef F_170
V_117 -> V_160 = NULL ;
#ifdef F_172
V_117 -> V_161 = NULL ;
#endif
F_76 ( & V_117 -> V_162 ) ;
V_117 -> V_330 = NULL ;
#endif
if ( ( V_169 & ( V_176 | V_331 ) ) == V_176 )
V_117 -> V_332 = V_117 -> V_333 = 0 ;
F_261 ( V_117 ) ;
F_262 ( V_117 , V_334 ) ;
#ifdef F_263
F_262 ( V_117 , F_263 ) ;
#endif
F_264 ( V_117 ) ;
V_117 -> V_241 = F_265 ( V_241 ) ;
if ( V_169 & V_209 ) {
V_117 -> V_335 = - 1 ;
V_117 -> V_225 = V_27 -> V_225 ;
V_117 -> V_336 = V_27 -> V_336 ;
} else {
if ( V_169 & V_250 )
V_117 -> V_335 = V_27 -> V_225 -> V_335 ;
else
V_117 -> V_335 = ( V_169 & V_337 ) ;
V_117 -> V_225 = V_117 ;
V_117 -> V_336 = V_117 -> V_241 ;
}
V_117 -> V_338 = 0 ;
V_117 -> V_339 = 128 >> ( V_340 - 10 ) ;
V_117 -> V_341 = 0 ;
V_117 -> V_342 = 0 ;
F_76 ( & V_117 -> V_343 ) ;
V_117 -> V_344 = NULL ;
F_266 ( & V_1 ) ;
if ( V_169 & ( V_250 | V_209 ) ) {
V_117 -> V_345 = V_27 -> V_345 ;
V_117 -> V_346 = V_27 -> V_346 ;
} else {
V_117 -> V_345 = V_27 ;
V_117 -> V_346 = V_27 -> V_347 ;
}
F_141 ( & V_27 -> V_198 -> V_231 ) ;
F_213 ( V_117 ) ;
F_267 () ;
if ( F_268 ( V_27 ) ) {
F_143 ( & V_27 -> V_198 -> V_231 ) ;
F_269 ( & V_1 ) ;
V_68 = - V_348 ;
goto V_349;
}
if ( F_162 ( V_117 -> V_241 ) ) {
F_270 ( V_117 , ( V_169 & V_350 ) || V_246 ) ;
F_223 ( V_117 , V_351 , V_241 ) ;
if ( F_271 ( V_117 ) ) {
F_223 ( V_117 , V_352 , F_272 ( V_27 ) ) ;
F_223 ( V_117 , V_353 , F_273 ( V_27 ) ) ;
if ( F_274 ( V_241 ) ) {
F_275 ( V_241 ) -> V_354 = V_117 ;
V_117 -> signal -> V_133 |= V_251 ;
}
V_117 -> signal -> V_355 = V_241 ;
V_117 -> signal -> V_356 = F_276 ( V_27 -> signal -> V_356 ) ;
F_277 ( & V_117 -> V_271 , & V_117 -> V_345 -> V_270 ) ;
F_278 ( & V_117 -> V_357 , & V_37 . V_357 ) ;
F_279 ( V_117 , V_352 ) ;
F_279 ( V_117 , V_353 ) ;
F_280 ( V_4 ) ;
} else {
V_27 -> signal -> V_210 ++ ;
F_83 ( & V_27 -> signal -> V_211 ) ;
F_83 ( & V_27 -> signal -> V_24 ) ;
F_278 ( & V_117 -> V_343 ,
& V_117 -> V_225 -> V_343 ) ;
F_278 ( & V_117 -> V_214 ,
& V_117 -> signal -> V_212 ) ;
}
F_279 ( V_117 , V_351 ) ;
V_210 ++ ;
}
V_358 ++ ;
F_143 ( & V_27 -> V_198 -> V_231 ) ;
F_281 ( V_117 ) ;
F_269 ( & V_1 ) ;
F_282 ( V_117 ) ;
F_283 ( V_117 ) ;
if ( V_169 & V_209 )
F_284 ( V_27 ) ;
F_285 ( V_117 ) ;
F_286 ( V_117 , V_169 ) ;
F_287 ( V_117 , V_169 ) ;
return V_117 ;
V_349:
if ( V_241 != & V_325 )
F_288 ( V_241 ) ;
V_324:
if ( V_117 -> V_190 )
F_289 ( V_117 ) ;
V_323:
F_290 ( V_117 ) ;
V_322:
if ( V_117 -> V_58 )
F_132 ( V_117 -> V_58 ) ;
V_321:
if ( ! ( V_169 & V_209 ) )
F_28 ( V_117 -> signal ) ;
V_320:
F_196 ( V_117 -> V_198 ) ;
V_319:
F_291 ( V_117 ) ;
V_318:
F_292 ( V_117 ) ;
V_317:
F_293 ( V_117 ) ;
V_316:
F_294 ( V_117 ) ;
V_315:
F_295 ( V_117 ) ;
V_314:
#ifdef F_243
F_96 ( V_117 -> V_291 ) ;
V_292:
#endif
if ( V_169 & V_209 )
F_284 ( V_27 ) ;
F_39 ( V_117 ) ;
V_266:
F_81 ( & V_117 -> V_359 -> V_259 -> V_260 ) ;
F_38 ( V_117 ) ;
V_264:
F_24 ( V_117 ) ;
V_255:
return F_158 ( V_68 ) ;
}
static inline void F_296 ( struct V_360 * V_361 )
{
enum V_240 type ;
for ( type = V_351 ; type < V_362 ; ++ type ) {
F_297 ( & V_361 [ type ] . V_7 ) ;
V_361 [ type ] . V_241 = & V_325 ;
}
}
struct V_5 * F_298 ( int V_2 )
{
struct V_5 * V_150 ;
V_150 = F_224 ( V_176 , 0 , 0 , NULL , & V_325 , 0 ) ;
if ( ! F_245 ( V_150 ) ) {
F_296 ( V_150 -> V_242 ) ;
F_299 ( V_150 , V_2 ) ;
}
return V_150 ;
}
long F_300 ( unsigned long V_169 ,
unsigned long V_243 ,
unsigned long V_244 ,
int T_3 * V_363 ,
int T_3 * V_245 )
{
struct V_5 * V_117 ;
int V_246 = 0 ;
long V_364 ;
if ( ! ( V_169 & V_365 ) ) {
if ( V_169 & V_331 )
V_246 = V_366 ;
else if ( ( V_169 & V_337 ) != V_367 )
V_246 = V_368 ;
else
V_246 = V_369 ;
if ( F_162 ( ! F_301 ( V_27 , V_246 ) ) )
V_246 = 0 ;
}
V_117 = F_224 ( V_169 , V_243 , V_244 ,
V_245 , NULL , V_246 ) ;
if ( ! F_245 ( V_117 ) ) {
struct V_155 V_156 ;
struct V_241 * V_241 ;
F_302 ( V_27 , V_117 ) ;
V_241 = F_303 ( V_117 , V_351 ) ;
V_364 = F_304 ( V_241 ) ;
if ( V_169 & V_370 )
F_177 ( V_364 , V_363 ) ;
if ( V_169 & V_331 ) {
V_117 -> V_157 = & V_156 ;
F_305 ( & V_156 ) ;
F_306 ( V_117 ) ;
}
F_307 ( V_117 ) ;
if ( F_101 ( V_246 ) )
F_308 ( V_246 , V_241 ) ;
if ( V_169 & V_331 ) {
if ( ! F_164 ( V_117 , & V_156 ) )
F_308 ( V_371 , V_241 ) ;
}
F_309 ( V_241 ) ;
} else {
V_364 = F_246 ( V_117 ) ;
}
return V_364 ;
}
T_4 F_310 ( int (* F_311)( void * ) , void * V_372 , unsigned long V_133 )
{
return F_300 ( V_133 | V_176 | V_365 , ( unsigned long ) F_311 ,
( unsigned long ) V_372 , NULL , NULL ) ;
}
static void F_312 ( void * V_373 )
{
struct V_196 * V_198 = V_373 ;
F_108 ( & V_198 -> V_231 ) ;
F_205 ( & V_198 -> V_374 ) ;
}
void T_1 F_313 ( void )
{
V_199 = F_18 ( L_7 ,
sizeof( struct V_196 ) , 0 ,
V_375 | V_35 | V_376 |
V_36 , F_312 ) ;
V_23 = F_18 ( L_8 ,
sizeof( struct V_21 ) , 0 ,
V_375 | V_35 | V_36 , NULL ) ;
V_377 = F_18 ( L_9 ,
sizeof( struct V_185 ) , 0 ,
V_375 | V_35 | V_36 , NULL ) ;
V_378 = F_18 ( L_10 ,
sizeof( struct V_178 ) , 0 ,
V_375 | V_35 | V_36 , NULL ) ;
V_379 = F_18 ( L_11 ,
sizeof( struct V_57 ) , V_380 ,
V_375 | V_35 | V_36 , NULL ) ;
V_88 = F_314 ( V_60 , V_35 ) ;
F_315 () ;
F_316 () ;
}
static int F_317 ( unsigned long V_381 )
{
if ( V_381 & ~ ( V_209 | V_180 | V_247 | V_197 |
V_176 | V_189 | V_382 |
V_383 | V_384 | V_385 |
V_249 | V_252 ) )
return - V_248 ;
if ( V_381 & ( V_209 | V_197 | V_176 ) ) {
if ( F_35 ( & V_27 -> V_58 -> V_121 ) > 1 )
return - V_248 ;
}
return 0 ;
}
static int F_318 ( unsigned long V_381 , struct V_178 * * V_386 )
{
struct V_178 * V_179 = V_27 -> V_179 ;
if ( ! ( V_381 & V_180 ) || ! V_179 )
return 0 ;
if ( V_179 -> V_184 == 1 )
return 0 ;
* V_386 = F_186 ( V_179 ) ;
if ( ! * V_386 )
return - V_109 ;
return 0 ;
}
static int F_319 ( unsigned long V_381 , struct V_185 * * V_387 )
{
struct V_185 * V_388 = V_27 -> V_188 ;
int error = 0 ;
if ( ( V_381 & V_189 ) &&
( V_388 && F_35 ( & V_388 -> V_142 ) > 1 ) ) {
* V_387 = F_188 ( V_388 , & error ) ;
if ( ! * V_387 )
return error ;
}
return 0 ;
}
int F_320 ( struct V_185 * * V_389 )
{
struct V_5 * V_150 = V_27 ;
struct V_185 * V_390 = NULL ;
int error ;
error = F_319 ( V_189 , & V_390 ) ;
if ( error || ! V_390 ) {
* V_389 = NULL ;
return error ;
}
* V_389 = V_150 -> V_188 ;
F_154 ( V_150 ) ;
V_150 -> V_188 = V_390 ;
F_155 ( V_150 ) ;
return 0 ;
}
int F_321 ( struct V_391 * V_392 , int V_393 ,
void T_3 * V_394 , T_5 * V_395 , T_6 * V_396 )
{
struct V_391 V_397 ;
int V_398 ;
int V_29 = V_33 ;
int V_399 = V_34 ;
int V_400 = V_32 ;
V_397 = * V_392 ;
V_397 . V_373 = & V_29 ;
V_397 . V_401 = & V_399 ;
V_397 . V_402 = & V_400 ;
V_398 = F_322 ( & V_397 , V_393 , V_394 , V_395 , V_396 ) ;
if ( V_398 || ! V_393 )
return V_398 ;
F_42 ( V_29 ) ;
return 0 ;
}
