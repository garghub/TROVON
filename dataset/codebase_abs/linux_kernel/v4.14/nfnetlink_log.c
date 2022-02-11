static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static inline T_1 F_3 ( T_2 V_4 )
{
return ( ( V_4 & 0xff ) % V_5 ) ;
}
static struct V_6 *
F_4 ( struct V_1 * log , T_2 V_4 )
{
struct V_7 * V_8 ;
struct V_6 * V_9 ;
V_8 = & log -> V_10 [ F_3 ( V_4 ) ] ;
F_5 (inst, head, hlist) {
if ( V_9 -> V_4 == V_4 )
return V_9 ;
}
return NULL ;
}
static inline void
F_6 ( struct V_6 * V_9 )
{
F_7 ( & V_9 -> V_11 ) ;
}
static struct V_6 *
F_8 ( struct V_1 * log , T_2 V_4 )
{
struct V_6 * V_9 ;
F_9 () ;
V_9 = F_4 ( log , V_4 ) ;
if ( V_9 && ! F_10 ( & V_9 -> V_11 ) )
V_9 = NULL ;
F_11 () ;
return V_9 ;
}
static void F_12 ( struct V_12 * V_8 )
{
struct V_6 * V_9 =
F_13 ( V_8 , struct V_6 , V_13 ) ;
F_14 ( V_9 -> V_2 ) ;
F_15 ( V_9 ) ;
F_16 ( V_14 ) ;
}
static void
F_17 ( struct V_6 * V_9 )
{
if ( V_9 && F_18 ( & V_9 -> V_11 ) )
F_19 ( & V_9 -> V_13 , F_12 ) ;
}
static struct V_6 *
F_20 ( struct V_2 * V_2 , T_2 V_4 ,
T_3 V_15 , struct V_16 * V_17 )
{
struct V_6 * V_9 ;
struct V_1 * log = F_1 ( V_2 ) ;
int V_18 ;
F_21 ( & log -> V_19 ) ;
if ( F_4 ( log , V_4 ) ) {
V_18 = - V_20 ;
goto V_21;
}
V_9 = F_22 ( sizeof( * V_9 ) , V_22 ) ;
if ( ! V_9 ) {
V_18 = - V_23 ;
goto V_21;
}
if ( ! F_23 ( V_14 ) ) {
F_15 ( V_9 ) ;
V_18 = - V_24 ;
goto V_21;
}
F_24 ( & V_9 -> V_25 ) ;
F_25 ( & V_9 -> V_26 ) ;
F_26 ( & V_9 -> V_11 , 2 ) ;
F_27 ( & V_9 -> V_27 , V_28 , ( unsigned long ) V_9 ) ;
V_9 -> V_2 = F_28 ( V_2 ) ;
V_9 -> V_29 = V_17 ;
V_9 -> V_30 = V_15 ;
V_9 -> V_4 = V_4 ;
V_9 -> V_31 = V_32 ;
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
V_9 -> V_37 = V_38 ;
V_9 -> V_39 = V_40 ;
F_29 ( & V_9 -> V_25 ,
& log -> V_10 [ F_3 ( V_4 ) ] ) ;
F_30 ( & log -> V_19 ) ;
return V_9 ;
V_21:
F_30 ( & log -> V_19 ) ;
return F_31 ( V_18 ) ;
}
static void
F_32 ( struct V_6 * V_9 )
{
F_33 ( & V_9 -> V_25 ) ;
F_34 ( & V_9 -> V_26 ) ;
V_9 -> V_37 = V_41 ;
if ( V_9 -> V_42 )
F_35 ( V_9 ) ;
F_36 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
}
static inline void
F_37 ( struct V_1 * log ,
struct V_6 * V_9 )
{
F_21 ( & log -> V_19 ) ;
F_32 ( V_9 ) ;
F_30 ( & log -> V_19 ) ;
}
static int
F_38 ( struct V_6 * V_9 , T_1 V_43 ,
unsigned int V_44 )
{
int V_45 = 0 ;
F_21 ( & V_9 -> V_26 ) ;
switch ( V_43 ) {
case V_46 :
case V_47 :
V_9 -> V_37 = V_43 ;
V_9 -> V_39 = 0 ;
break;
case V_38 :
V_9 -> V_37 = V_43 ;
if ( V_44 == 0 )
V_44 = V_40 ;
V_9 -> V_39 = F_39 (unsigned int,
range, NFULNL_COPY_RANGE_MAX) ;
break;
default:
V_45 = - V_48 ;
break;
}
F_30 ( & V_9 -> V_26 ) ;
return V_45 ;
}
static int
F_40 ( struct V_6 * V_9 , T_4 V_35 )
{
int V_45 ;
F_21 ( & V_9 -> V_26 ) ;
if ( V_35 < V_36 )
V_45 = - V_49 ;
else if ( V_35 > 131072 )
V_45 = - V_49 ;
else {
V_9 -> V_35 = V_35 ;
V_45 = 0 ;
}
F_30 ( & V_9 -> V_26 ) ;
return V_45 ;
}
static void
F_41 ( struct V_6 * V_9 , T_4 V_50 )
{
F_21 ( & V_9 -> V_26 ) ;
V_9 -> V_33 = V_50 ;
F_30 ( & V_9 -> V_26 ) ;
}
static void
F_42 ( struct V_6 * V_9 , T_4 V_51 )
{
F_21 ( & V_9 -> V_26 ) ;
V_9 -> V_31 = V_51 ;
F_30 ( & V_9 -> V_26 ) ;
}
static int
F_43 ( struct V_6 * V_9 , T_2 V_52 )
{
F_21 ( & V_9 -> V_26 ) ;
V_9 -> V_52 = V_52 ;
F_30 ( & V_9 -> V_26 ) ;
return 0 ;
}
static struct V_53 *
F_44 ( struct V_2 * V_2 , T_3 V_30 , unsigned int V_54 ,
unsigned int V_55 )
{
struct V_53 * V_42 ;
unsigned int V_56 ;
V_56 = F_45 ( V_54 , V_55 ) ;
V_42 = F_46 ( V_56 , V_22 | V_57 ) ;
if ( ! V_42 ) {
if ( V_56 > V_55 ) {
V_42 = F_46 ( V_55 , V_22 ) ;
}
}
return V_42 ;
}
static void
F_47 ( struct V_6 * V_9 )
{
if ( V_9 -> V_58 > 1 ) {
struct V_59 * V_60 = F_48 ( V_9 -> V_42 , 0 , 0 ,
V_61 ,
sizeof( struct V_62 ) ,
0 ) ;
if ( F_49 ( ! V_60 , L_1 ,
V_9 -> V_42 -> V_63 , F_50 ( V_9 -> V_42 ) ) ) {
F_51 ( V_9 -> V_42 ) ;
goto V_64;
}
}
F_52 ( V_9 -> V_42 , V_9 -> V_2 , V_9 -> V_30 ,
V_65 ) ;
V_64:
V_9 -> V_58 = 0 ;
V_9 -> V_42 = NULL ;
}
static void
F_35 ( struct V_6 * V_9 )
{
if ( F_53 ( & V_9 -> V_27 ) )
F_17 ( V_9 ) ;
if ( V_9 -> V_42 )
F_47 ( V_9 ) ;
}
static void
V_28 ( unsigned long V_66 )
{
struct V_6 * V_9 = (struct V_6 * ) V_66 ;
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_42 )
F_47 ( V_9 ) ;
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
}
static inline int
F_54 ( struct V_1 * log ,
struct V_6 * V_9 ,
const struct V_53 * V_42 ,
unsigned int V_67 ,
T_1 V_68 ,
unsigned int V_69 ,
const struct V_70 * V_71 ,
const struct V_70 * V_72 ,
const char * V_73 , unsigned int V_74 ,
const struct V_75 * V_76 ,
struct V_77 * V_78 , enum V_79 V_80 )
{
struct V_81 V_82 ;
struct V_59 * V_60 ;
struct V_62 * V_83 ;
T_5 V_84 = V_9 -> V_42 -> V_85 ;
struct V_86 * V_87 ;
const unsigned char * V_88 ;
V_60 = F_48 ( V_9 -> V_42 , 0 , 0 ,
F_55 ( V_89 , V_90 ) ,
sizeof( struct V_62 ) , 0 ) ;
if ( ! V_60 )
return - 1 ;
V_83 = F_56 ( V_60 ) ;
V_83 -> V_91 = V_68 ;
V_83 -> V_92 = V_93 ;
V_83 -> V_94 = F_57 ( V_9 -> V_4 ) ;
memset ( & V_82 , 0 , sizeof( V_82 ) ) ;
V_82 . V_95 = V_42 -> V_96 ;
V_82 . V_97 = V_69 ;
if ( F_58 ( V_9 -> V_42 , V_98 , sizeof( V_82 ) , & V_82 ) )
goto V_99;
if ( V_73 &&
F_58 ( V_9 -> V_42 , V_100 , V_74 , V_73 ) )
goto V_99;
if ( V_71 ) {
#if ! F_59 ( V_101 )
if ( F_60 ( V_9 -> V_42 , V_102 ,
F_61 ( V_71 -> V_103 ) ) )
goto V_99;
#else
if ( V_68 == V_104 ) {
if ( F_60 ( V_9 -> V_42 , V_105 ,
F_61 ( V_71 -> V_103 ) ) ||
F_60 ( V_9 -> V_42 , V_102 ,
F_61 ( F_62 ( V_71 ) -> V_106 -> V_107 -> V_103 ) ) )
goto V_99;
} else {
struct V_70 * V_108 ;
if ( F_60 ( V_9 -> V_42 , V_102 ,
F_61 ( V_71 -> V_103 ) ) )
goto V_99;
V_108 = F_63 ( V_42 ) ;
if ( V_108 &&
F_60 ( V_9 -> V_42 , V_105 ,
F_61 ( V_108 -> V_103 ) ) )
goto V_99;
}
#endif
}
if ( V_72 ) {
#if ! F_59 ( V_101 )
if ( F_60 ( V_9 -> V_42 , V_109 ,
F_61 ( V_72 -> V_103 ) ) )
goto V_99;
#else
if ( V_68 == V_104 ) {
if ( F_60 ( V_9 -> V_42 , V_110 ,
F_61 ( V_72 -> V_103 ) ) ||
F_60 ( V_9 -> V_42 , V_109 ,
F_61 ( F_62 ( V_72 ) -> V_106 -> V_107 -> V_103 ) ) )
goto V_99;
} else {
struct V_70 * V_111 ;
if ( F_60 ( V_9 -> V_42 , V_109 ,
F_61 ( V_72 -> V_103 ) ) )
goto V_99;
V_111 = F_64 ( V_42 ) ;
if ( V_111 &&
F_60 ( V_9 -> V_42 , V_110 ,
F_61 ( V_111 -> V_103 ) ) )
goto V_99;
}
#endif
}
if ( V_42 -> V_112 &&
F_60 ( V_9 -> V_42 , V_113 , F_61 ( V_42 -> V_112 ) ) )
goto V_99;
if ( V_71 && V_42 -> V_107 &&
V_42 -> V_114 != V_42 -> V_115 ) {
struct V_116 V_117 ;
int V_63 ;
memset ( & V_117 , 0 , sizeof( V_117 ) ) ;
V_63 = F_65 ( V_42 , V_117 . V_118 ) ;
if ( V_63 > 0 ) {
V_117 . V_119 = F_57 ( V_63 ) ;
if ( F_58 ( V_9 -> V_42 , V_120 , sizeof( V_117 ) , & V_117 ) )
goto V_99;
}
}
if ( V_71 && F_66 ( V_42 ) ) {
if ( F_67 ( V_9 -> V_42 , V_121 , F_57 ( V_42 -> V_107 -> type ) ) ||
F_67 ( V_9 -> V_42 , V_122 ,
F_57 ( V_42 -> V_107 -> V_123 ) ) )
goto V_99;
V_88 = F_68 ( V_42 ) ;
if ( V_42 -> V_107 -> type == V_124 )
V_88 -= V_125 ;
if ( V_88 >= V_42 -> V_8 &&
F_58 ( V_9 -> V_42 , V_126 ,
V_42 -> V_107 -> V_123 , V_88 ) )
goto V_99;
}
if ( V_42 -> V_127 ) {
struct V_128 V_129 ;
struct V_130 V_131 = F_69 ( V_42 -> V_127 ) ;
V_129 . V_132 = F_70 ( V_131 . V_133 ) ;
V_129 . V_134 = F_70 ( V_131 . V_135 / V_136 ) ;
if ( F_58 ( V_9 -> V_42 , V_137 , sizeof( V_129 ) , & V_129 ) )
goto V_99;
}
V_87 = V_42 -> V_87 ;
if ( V_87 && F_71 ( V_87 ) ) {
F_72 ( & V_87 -> V_138 ) ;
if ( V_87 -> V_139 && V_87 -> V_139 -> V_140 ) {
struct V_140 * V_140 = V_87 -> V_139 -> V_140 ;
const struct V_141 * V_141 = V_140 -> V_142 ;
struct V_16 * V_17 = V_9 -> V_29 ;
T_6 V_143 = F_61 ( F_73 ( V_17 , V_141 -> V_144 ) ) ;
T_6 V_145 = F_61 ( F_74 ( V_17 , V_141 -> V_146 ) ) ;
F_75 ( & V_87 -> V_138 ) ;
if ( F_60 ( V_9 -> V_42 , V_147 , V_143 ) ||
F_60 ( V_9 -> V_42 , V_148 , V_145 ) )
goto V_99;
} else
F_75 ( & V_87 -> V_138 ) ;
}
if ( ( V_9 -> V_52 & V_149 ) &&
F_60 ( V_9 -> V_42 , V_150 , F_61 ( V_9 -> V_151 ++ ) ) )
goto V_99;
if ( ( V_9 -> V_52 & V_152 ) &&
F_60 ( V_9 -> V_42 , V_153 ,
F_61 ( F_76 ( & log -> V_154 ) ) ) )
goto V_99;
if ( V_78 && V_76 -> V_155 ( V_9 -> V_42 , V_78 , V_80 ,
V_156 , V_157 ) < 0 )
goto V_99;
if ( V_67 ) {
struct V_158 * V_159 ;
int V_160 = F_77 ( V_67 ) ;
if ( F_50 ( V_9 -> V_42 ) < F_78 ( V_67 ) )
goto V_99;
V_159 = F_79 ( V_9 -> V_42 , F_78 ( V_67 ) ) ;
V_159 -> V_161 = V_162 ;
V_159 -> V_163 = V_160 ;
if ( F_80 ( V_42 , 0 , F_81 ( V_159 ) , V_67 ) )
F_82 () ;
}
V_60 -> V_164 = V_9 -> V_42 -> V_85 - V_84 ;
return 0 ;
V_99:
F_83 ( V_165 L_2 ) ;
return - 1 ;
}
void
F_84 ( struct V_2 * V_2 ,
T_1 V_68 ,
unsigned int V_69 ,
const struct V_53 * V_42 ,
const struct V_70 * V_166 ,
const struct V_70 * V_64 ,
const struct V_167 * V_168 ,
const char * V_73 )
{
T_7 V_160 ;
unsigned int V_67 ;
struct V_6 * V_9 ;
const struct V_167 * V_169 ;
unsigned int V_31 ;
unsigned int V_74 ;
struct V_1 * log = F_1 ( V_2 ) ;
const struct V_75 * V_76 = NULL ;
struct V_77 * V_78 = NULL ;
enum V_79 V_170 ( V_80 ) ;
if ( V_168 && V_168 -> type == V_171 )
V_169 = V_168 ;
else
V_169 = & V_172 ;
V_9 = F_8 ( log , V_169 -> V_173 . V_174 . V_175 ) ;
if ( ! V_9 )
return;
V_74 = 0 ;
if ( V_73 )
V_74 = strlen ( V_73 ) + 1 ;
V_160 = F_85 ( sizeof( struct V_62 ) )
+ F_78 ( sizeof( struct V_81 ) )
+ F_78 ( sizeof( T_4 ) )
+ F_78 ( sizeof( T_4 ) )
#if F_59 ( V_101 )
+ F_78 ( sizeof( T_4 ) )
+ F_78 ( sizeof( T_4 ) )
#endif
+ F_78 ( sizeof( T_4 ) )
+ F_78 ( sizeof( T_4 ) )
+ F_78 ( sizeof( T_4 ) )
+ F_78 ( V_74 )
+ F_78 ( sizeof( struct V_116 ) )
+ F_78 ( sizeof( struct V_128 ) )
+ F_78 ( sizeof( struct V_62 ) ) ;
if ( V_166 && F_66 ( V_42 ) ) {
V_160 += F_78 ( V_42 -> V_107 -> V_123 )
+ F_78 ( sizeof( T_2 ) )
+ F_78 ( sizeof( T_2 ) ) ;
}
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_52 & V_149 )
V_160 += F_78 ( sizeof( T_4 ) ) ;
if ( V_9 -> V_52 & V_152 )
V_160 += F_78 ( sizeof( T_4 ) ) ;
if ( V_9 -> V_52 & V_176 ) {
V_76 = F_86 ( V_75 ) ;
if ( V_76 != NULL ) {
V_78 = V_76 -> V_177 ( V_42 , & V_80 ) ;
if ( V_78 != NULL )
V_160 += V_76 -> V_178 ( V_78 ) ;
}
}
V_31 = V_9 -> V_31 ;
if ( V_169 -> V_173 . V_174 . V_31 )
if ( V_31 > V_169 -> V_173 . V_174 . V_31 )
V_31 = V_169 -> V_173 . V_174 . V_31 ;
switch ( V_9 -> V_37 ) {
case V_47 :
case V_46 :
V_67 = 0 ;
break;
case V_38 :
V_67 = V_9 -> V_39 ;
if ( ( V_169 -> V_173 . V_174 . V_52 & V_179 ) &&
( V_169 -> V_173 . V_174 . V_180 < V_67 ) )
V_67 = V_169 -> V_173 . V_174 . V_180 ;
if ( V_67 > V_42 -> V_63 )
V_67 = V_42 -> V_63 ;
V_160 += F_78 ( V_67 ) ;
break;
case V_41 :
default:
goto V_181;
}
if ( V_9 -> V_42 && V_160 > F_50 ( V_9 -> V_42 ) ) {
F_35 ( V_9 ) ;
}
if ( ! V_9 -> V_42 ) {
V_9 -> V_42 = F_44 ( V_2 , V_9 -> V_30 ,
V_9 -> V_35 , V_160 ) ;
if ( ! V_9 -> V_42 )
goto V_182;
}
V_9 -> V_58 ++ ;
F_54 ( log , V_9 , V_42 , V_67 , V_68 ,
V_69 , V_166 , V_64 , V_73 , V_74 ,
V_76 , V_78 , V_80 ) ;
if ( V_9 -> V_58 >= V_31 )
F_35 ( V_9 ) ;
else if ( ! F_87 ( & V_9 -> V_27 ) ) {
F_6 ( V_9 ) ;
V_9 -> V_27 . V_183 = V_184 + ( V_9 -> V_33 * V_185 / 100 ) ;
F_88 ( & V_9 -> V_27 ) ;
}
V_181:
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
return;
V_182:
goto V_181;
}
static int
F_89 ( struct V_186 * V_187 ,
unsigned long V_188 , void * V_189 )
{
struct V_190 * V_56 = V_189 ;
struct V_1 * log = F_1 ( V_56 -> V_2 ) ;
if ( V_188 == V_191 && V_56 -> V_96 == V_192 ) {
int V_193 ;
F_21 ( & log -> V_19 ) ;
for ( V_193 = 0 ; V_193 < V_5 ; V_193 ++ ) {
struct V_194 * V_195 ;
struct V_6 * V_9 ;
struct V_7 * V_8 = & log -> V_10 [ V_193 ] ;
F_90 (inst, t2, head, hlist) {
if ( V_56 -> V_15 == V_9 -> V_30 )
F_32 ( V_9 ) ;
}
}
F_30 ( & log -> V_19 ) ;
}
return V_196 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_86 * V_197 ,
struct V_53 * V_42 , const struct V_59 * V_60 ,
const struct V_158 * const V_198 [] ,
struct V_199 * V_200 )
{
return - V_201 ;
}
static int F_92 ( struct V_2 * V_2 , struct V_86 * V_197 ,
struct V_53 * V_42 , const struct V_59 * V_60 ,
const struct V_158 * const V_202 [] ,
struct V_199 * V_200 )
{
struct V_62 * V_83 = F_56 ( V_60 ) ;
T_2 V_4 = F_93 ( V_83 -> V_94 ) ;
struct V_6 * V_9 ;
struct V_203 * V_204 = NULL ;
struct V_1 * log = F_1 ( V_2 ) ;
int V_205 = 0 ;
T_8 V_52 = 0 ;
if ( V_202 [ V_206 ] ) {
T_1 V_68 = V_83 -> V_91 ;
V_204 = F_81 ( V_202 [ V_206 ] ) ;
switch ( V_204 -> V_207 ) {
case V_208 :
return F_94 ( V_2 , V_68 , & V_209 ) ;
case V_210 :
F_95 ( V_2 , V_68 ) ;
return 0 ;
}
}
V_9 = F_8 ( log , V_4 ) ;
if ( V_9 && V_9 -> V_30 != F_96 ( V_42 ) . V_15 ) {
V_205 = - V_211 ;
goto V_212;
}
if ( V_202 [ V_213 ] ) {
V_52 = F_93 ( F_97 ( V_202 [ V_213 ] ) ) ;
if ( ( V_52 & V_176 ) &&
! F_98 ( V_75 ) ) {
#ifdef F_99
F_100 ( V_89 ) ;
F_101 ( L_3 ) ;
F_102 ( V_89 ) ;
if ( F_98 ( V_75 ) ) {
V_205 = - V_24 ;
goto V_212;
}
#endif
V_205 = - V_214 ;
goto V_212;
}
}
if ( V_204 != NULL ) {
switch ( V_204 -> V_207 ) {
case V_215 :
if ( V_9 ) {
V_205 = - V_216 ;
goto V_212;
}
V_9 = F_20 ( V_2 , V_4 ,
F_96 ( V_42 ) . V_15 ,
F_103 ( F_96 ( V_42 ) . V_87 ) ) ;
if ( F_104 ( V_9 ) ) {
V_205 = F_105 ( V_9 ) ;
goto V_64;
}
break;
case V_217 :
if ( ! V_9 ) {
V_205 = - V_218 ;
goto V_64;
}
F_37 ( log , V_9 ) ;
goto V_212;
default:
V_205 = - V_201 ;
goto V_212;
}
} else if ( ! V_9 ) {
V_205 = - V_218 ;
goto V_64;
}
if ( V_202 [ V_219 ] ) {
struct V_220 * V_221 =
F_81 ( V_202 [ V_219 ] ) ;
F_38 ( V_9 , V_221 -> V_37 ,
F_106 ( V_221 -> V_39 ) ) ;
}
if ( V_202 [ V_222 ] ) {
T_6 V_50 = F_107 ( V_202 [ V_222 ] ) ;
F_41 ( V_9 , F_106 ( V_50 ) ) ;
}
if ( V_202 [ V_223 ] ) {
T_6 V_35 = F_107 ( V_202 [ V_223 ] ) ;
F_40 ( V_9 , F_106 ( V_35 ) ) ;
}
if ( V_202 [ V_224 ] ) {
T_6 V_51 = F_107 ( V_202 [ V_224 ] ) ;
F_42 ( V_9 , F_106 ( V_51 ) ) ;
}
if ( V_202 [ V_213 ] )
F_43 ( V_9 , V_52 ) ;
V_212:
F_17 ( V_9 ) ;
V_64:
return V_205 ;
}
static struct V_194 * F_108 ( struct V_2 * V_2 , struct V_225 * V_226 )
{
struct V_1 * log ;
if ( ! V_226 )
return NULL ;
log = F_1 ( V_2 ) ;
for ( V_226 -> V_227 = 0 ; V_226 -> V_227 < V_5 ; V_226 -> V_227 ++ ) {
struct V_7 * V_8 = & log -> V_10 [ V_226 -> V_227 ] ;
if ( ! F_109 ( V_8 ) )
return F_110 ( F_111 ( V_8 ) ) ;
}
return NULL ;
}
static struct V_194 * F_112 ( struct V_2 * V_2 , struct V_225 * V_226 ,
struct V_194 * V_228 )
{
V_228 = F_110 ( F_113 ( V_228 ) ) ;
while ( ! V_228 ) {
struct V_1 * log ;
struct V_7 * V_8 ;
if ( ++ V_226 -> V_227 >= V_5 )
return NULL ;
log = F_1 ( V_2 ) ;
V_8 = & log -> V_10 [ V_226 -> V_227 ] ;
V_228 = F_110 ( F_111 ( V_8 ) ) ;
}
return V_228 ;
}
static struct V_194 * F_114 ( struct V_2 * V_2 , struct V_225 * V_226 ,
T_9 V_229 )
{
struct V_194 * V_8 ;
V_8 = F_108 ( V_2 , V_226 ) ;
if ( V_8 )
while ( V_229 && ( V_8 = F_112 ( V_2 , V_226 , V_8 ) ) )
V_229 -- ;
return V_229 ? NULL : V_8 ;
}
static void * F_115 ( struct V_230 * V_231 , T_9 * V_229 )
__acquires( T_10 )
{
F_9 () ;
return F_114 ( F_116 ( V_231 ) , V_231 -> V_232 , * V_229 ) ;
}
static void * F_117 ( struct V_230 * V_231 , void * V_233 , T_9 * V_229 )
{
( * V_229 ) ++ ;
return F_112 ( F_116 ( V_231 ) , V_231 -> V_232 , V_233 ) ;
}
static void F_118 ( struct V_230 * V_231 , void * V_233 )
__releases( T_10 )
{
F_11 () ;
}
static int F_119 ( struct V_230 * V_231 , void * V_233 )
{
const struct V_6 * V_9 = V_233 ;
F_120 ( V_231 , L_4 ,
V_9 -> V_4 ,
V_9 -> V_30 , V_9 -> V_58 ,
V_9 -> V_37 , V_9 -> V_39 ,
V_9 -> V_33 , F_121 ( & V_9 -> V_11 ) ) ;
return 0 ;
}
static int F_122 ( struct V_234 * V_234 , struct V_140 * V_140 )
{
return F_123 ( V_234 , V_140 , & V_235 ,
sizeof( struct V_225 ) ) ;
}
static int T_11 F_124 ( struct V_2 * V_2 )
{
unsigned int V_193 ;
struct V_1 * log = F_1 ( V_2 ) ;
#ifdef F_125
struct V_236 * V_237 ;
T_12 V_238 ;
T_13 V_239 ;
#endif
for ( V_193 = 0 ; V_193 < V_5 ; V_193 ++ )
F_126 ( & log -> V_10 [ V_193 ] ) ;
F_25 ( & log -> V_19 ) ;
#ifdef F_125
V_237 = F_127 ( L_5 , 0440 ,
V_2 -> V_240 . V_241 , & V_242 ) ;
if ( ! V_237 )
return - V_23 ;
V_238 = F_128 ( V_2 -> V_17 , 0 ) ;
V_239 = F_129 ( V_2 -> V_17 , 0 ) ;
if ( F_130 ( V_238 ) && F_131 ( V_239 ) )
F_132 ( V_237 , V_238 , V_239 ) ;
#endif
return 0 ;
}
static void T_14 F_133 ( struct V_2 * V_2 )
{
#ifdef F_125
F_134 ( L_5 , V_2 -> V_240 . V_241 ) ;
#endif
F_135 ( V_2 , & V_209 ) ;
}
static int T_15 F_136 ( void )
{
int V_45 ;
V_45 = F_137 ( & V_243 ) ;
if ( V_45 < 0 ) {
F_138 ( L_6 ) ;
goto V_64;
}
F_139 ( & V_244 ) ;
V_45 = F_140 ( & V_245 ) ;
if ( V_45 < 0 ) {
F_138 ( L_7 ) ;
goto V_246;
}
V_45 = F_141 ( V_247 , & V_209 ) ;
if ( V_45 < 0 ) {
F_138 ( L_8 ) ;
goto V_248;
}
return V_45 ;
V_248:
F_142 ( & V_245 ) ;
V_246:
F_143 ( & V_244 ) ;
F_144 ( & V_243 ) ;
V_64:
return V_45 ;
}
static void T_16 F_145 ( void )
{
F_142 ( & V_245 ) ;
F_143 ( & V_244 ) ;
F_144 ( & V_243 ) ;
F_146 ( & V_209 ) ;
}
