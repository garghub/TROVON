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
V_42 = F_46 ( V_56 , V_22 ) ;
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
if ( V_9 -> V_57 > 1 ) {
struct V_58 * V_59 = F_48 ( V_9 -> V_42 , 0 , 0 ,
V_60 ,
sizeof( struct V_61 ) ,
0 ) ;
if ( F_49 ( ! V_59 , L_1 ,
V_9 -> V_42 -> V_62 , F_50 ( V_9 -> V_42 ) ) ) {
F_51 ( V_9 -> V_42 ) ;
goto V_63;
}
}
F_52 ( V_9 -> V_42 , V_9 -> V_2 , V_9 -> V_30 ,
V_64 ) ;
V_63:
V_9 -> V_57 = 0 ;
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
V_28 ( unsigned long V_65 )
{
struct V_6 * V_9 = (struct V_6 * ) V_65 ;
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
unsigned int V_66 ,
T_1 V_67 ,
unsigned int V_68 ,
const struct V_69 * V_70 ,
const struct V_69 * V_71 ,
const char * V_72 , unsigned int V_73 ,
const struct V_74 * V_75 ,
struct V_76 * V_77 , enum V_78 V_79 )
{
struct V_80 V_81 ;
struct V_58 * V_59 ;
struct V_61 * V_82 ;
T_5 V_83 = V_9 -> V_42 -> V_84 ;
struct V_85 * V_86 ;
const unsigned char * V_87 ;
V_59 = F_48 ( V_9 -> V_42 , 0 , 0 ,
V_88 << 8 | V_89 ,
sizeof( struct V_61 ) , 0 ) ;
if ( ! V_59 )
return - 1 ;
V_82 = F_55 ( V_59 ) ;
V_82 -> V_90 = V_67 ;
V_82 -> V_91 = V_92 ;
V_82 -> V_93 = F_56 ( V_9 -> V_4 ) ;
memset ( & V_81 , 0 , sizeof( V_81 ) ) ;
V_81 . V_94 = V_42 -> V_95 ;
V_81 . V_96 = V_68 ;
if ( F_57 ( V_9 -> V_42 , V_97 , sizeof( V_81 ) , & V_81 ) )
goto V_98;
if ( V_72 &&
F_57 ( V_9 -> V_42 , V_99 , V_73 , V_72 ) )
goto V_98;
if ( V_70 ) {
#if ! F_58 ( V_100 )
if ( F_59 ( V_9 -> V_42 , V_101 ,
F_60 ( V_70 -> V_102 ) ) )
goto V_98;
#else
if ( V_67 == V_103 ) {
if ( F_59 ( V_9 -> V_42 , V_104 ,
F_60 ( V_70 -> V_102 ) ) ||
F_59 ( V_9 -> V_42 , V_101 ,
F_60 ( F_61 ( V_70 ) -> V_105 -> V_106 -> V_102 ) ) )
goto V_98;
} else {
struct V_69 * V_107 ;
if ( F_59 ( V_9 -> V_42 , V_101 ,
F_60 ( V_70 -> V_102 ) ) )
goto V_98;
V_107 = F_62 ( V_42 ) ;
if ( V_107 &&
F_59 ( V_9 -> V_42 , V_104 ,
F_60 ( V_107 -> V_102 ) ) )
goto V_98;
}
#endif
}
if ( V_71 ) {
#if ! F_58 ( V_100 )
if ( F_59 ( V_9 -> V_42 , V_108 ,
F_60 ( V_71 -> V_102 ) ) )
goto V_98;
#else
if ( V_67 == V_103 ) {
if ( F_59 ( V_9 -> V_42 , V_109 ,
F_60 ( V_71 -> V_102 ) ) ||
F_59 ( V_9 -> V_42 , V_108 ,
F_60 ( F_61 ( V_71 ) -> V_105 -> V_106 -> V_102 ) ) )
goto V_98;
} else {
struct V_69 * V_110 ;
if ( F_59 ( V_9 -> V_42 , V_108 ,
F_60 ( V_71 -> V_102 ) ) )
goto V_98;
V_110 = F_63 ( V_42 ) ;
if ( V_110 &&
F_59 ( V_9 -> V_42 , V_109 ,
F_60 ( V_110 -> V_102 ) ) )
goto V_98;
}
#endif
}
if ( V_42 -> V_111 &&
F_59 ( V_9 -> V_42 , V_112 , F_60 ( V_42 -> V_111 ) ) )
goto V_98;
if ( V_70 && V_42 -> V_106 &&
V_42 -> V_113 != V_42 -> V_114 ) {
struct V_115 V_116 ;
int V_62 ;
memset ( & V_116 , 0 , sizeof( V_116 ) ) ;
V_62 = F_64 ( V_42 , V_116 . V_117 ) ;
if ( V_62 > 0 ) {
V_116 . V_118 = F_56 ( V_62 ) ;
if ( F_57 ( V_9 -> V_42 , V_119 , sizeof( V_116 ) , & V_116 ) )
goto V_98;
}
}
if ( V_70 && F_65 ( V_42 ) ) {
if ( F_66 ( V_9 -> V_42 , V_120 , F_56 ( V_42 -> V_106 -> type ) ) ||
F_66 ( V_9 -> V_42 , V_121 ,
F_56 ( V_42 -> V_106 -> V_122 ) ) )
goto V_98;
V_87 = F_67 ( V_42 ) ;
if ( V_42 -> V_106 -> type == V_123 )
V_87 -= V_124 ;
if ( V_87 >= V_42 -> V_8 &&
F_57 ( V_9 -> V_42 , V_125 ,
V_42 -> V_106 -> V_122 , V_87 ) )
goto V_98;
}
if ( V_42 -> V_126 . V_127 ) {
struct V_128 V_129 ;
struct V_130 V_131 = F_68 ( V_42 -> V_126 ) ;
V_129 . V_132 = F_69 ( V_131 . V_133 ) ;
V_129 . V_134 = F_69 ( V_131 . V_135 / V_136 ) ;
if ( F_57 ( V_9 -> V_42 , V_137 , sizeof( V_129 ) , & V_129 ) )
goto V_98;
}
V_86 = V_42 -> V_86 ;
if ( V_86 && F_70 ( V_86 ) ) {
F_71 ( & V_86 -> V_138 ) ;
if ( V_86 -> V_139 && V_86 -> V_139 -> V_140 ) {
struct V_140 * V_140 = V_86 -> V_139 -> V_140 ;
const struct V_141 * V_141 = V_140 -> V_142 ;
struct V_16 * V_17 = V_9 -> V_29 ;
T_6 V_143 = F_60 ( F_72 ( V_17 , V_141 -> V_144 ) ) ;
T_6 V_145 = F_60 ( F_73 ( V_17 , V_141 -> V_146 ) ) ;
F_74 ( & V_86 -> V_138 ) ;
if ( F_59 ( V_9 -> V_42 , V_147 , V_143 ) ||
F_59 ( V_9 -> V_42 , V_148 , V_145 ) )
goto V_98;
} else
F_74 ( & V_86 -> V_138 ) ;
}
if ( ( V_9 -> V_52 & V_149 ) &&
F_59 ( V_9 -> V_42 , V_150 , F_60 ( V_9 -> V_151 ++ ) ) )
goto V_98;
if ( ( V_9 -> V_52 & V_152 ) &&
F_59 ( V_9 -> V_42 , V_153 ,
F_60 ( F_75 ( & log -> V_154 ) ) ) )
goto V_98;
if ( V_77 && V_75 -> V_155 ( V_9 -> V_42 , V_77 , V_79 ,
V_156 , V_157 ) < 0 )
goto V_98;
if ( V_66 ) {
struct V_158 * V_159 ;
int V_160 = F_76 ( V_66 ) ;
if ( F_50 ( V_9 -> V_42 ) < F_77 ( V_66 ) )
goto V_98;
V_159 = (struct V_158 * ) F_78 ( V_9 -> V_42 , F_77 ( V_66 ) ) ;
V_159 -> V_161 = V_162 ;
V_159 -> V_163 = V_160 ;
if ( F_79 ( V_42 , 0 , F_80 ( V_159 ) , V_66 ) )
F_81 () ;
}
V_59 -> V_164 = V_9 -> V_42 -> V_84 - V_83 ;
return 0 ;
V_98:
F_82 ( V_165 L_2 ) ;
return - 1 ;
}
void
F_83 ( struct V_2 * V_2 ,
T_1 V_67 ,
unsigned int V_68 ,
const struct V_53 * V_42 ,
const struct V_69 * V_166 ,
const struct V_69 * V_63 ,
const struct V_167 * V_168 ,
const char * V_72 )
{
T_7 V_160 ;
unsigned int V_66 ;
struct V_6 * V_9 ;
const struct V_167 * V_169 ;
unsigned int V_31 ;
unsigned int V_73 ;
struct V_1 * log = F_1 ( V_2 ) ;
const struct V_74 * V_75 = NULL ;
struct V_76 * V_77 = NULL ;
enum V_78 V_170 ( V_79 ) ;
if ( V_168 && V_168 -> type == V_171 )
V_169 = V_168 ;
else
V_169 = & V_172 ;
V_9 = F_8 ( log , V_169 -> V_173 . V_174 . V_175 ) ;
if ( ! V_9 )
return;
V_73 = 0 ;
if ( V_72 )
V_73 = strlen ( V_72 ) + 1 ;
V_160 = F_84 ( sizeof( struct V_61 ) )
+ F_77 ( sizeof( struct V_80 ) )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
#if F_58 ( V_100 )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
#endif
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( V_73 )
+ F_77 ( sizeof( struct V_115 ) )
+ F_77 ( sizeof( struct V_128 ) )
+ F_77 ( sizeof( struct V_61 ) ) ;
if ( V_166 && F_65 ( V_42 ) ) {
V_160 += F_77 ( V_42 -> V_106 -> V_122 )
+ F_77 ( sizeof( T_2 ) )
+ F_77 ( sizeof( T_2 ) ) ;
}
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_52 & V_149 )
V_160 += F_77 ( sizeof( T_4 ) ) ;
if ( V_9 -> V_52 & V_152 )
V_160 += F_77 ( sizeof( T_4 ) ) ;
if ( V_9 -> V_52 & V_176 ) {
V_75 = F_85 ( V_74 ) ;
if ( V_75 != NULL ) {
V_77 = V_75 -> V_177 ( V_42 , & V_79 ) ;
if ( V_77 != NULL )
V_160 += V_75 -> V_178 ( V_77 ) ;
}
}
V_31 = V_9 -> V_31 ;
if ( V_169 -> V_173 . V_174 . V_31 )
if ( V_31 > V_169 -> V_173 . V_174 . V_31 )
V_31 = V_169 -> V_173 . V_174 . V_31 ;
switch ( V_9 -> V_37 ) {
case V_47 :
case V_46 :
V_66 = 0 ;
break;
case V_38 :
V_66 = V_9 -> V_39 ;
if ( ( V_169 -> V_173 . V_174 . V_52 & V_179 ) &&
( V_169 -> V_173 . V_174 . V_180 < V_66 ) )
V_66 = V_169 -> V_173 . V_174 . V_180 ;
if ( V_66 > V_42 -> V_62 )
V_66 = V_42 -> V_62 ;
V_160 += F_77 ( V_66 ) ;
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
V_9 -> V_57 ++ ;
F_54 ( log , V_9 , V_42 , V_66 , V_67 ,
V_68 , V_166 , V_63 , V_72 , V_73 ,
V_75 , V_77 , V_79 ) ;
if ( V_9 -> V_57 >= V_31 )
F_35 ( V_9 ) ;
else if ( ! F_86 ( & V_9 -> V_27 ) ) {
F_6 ( V_9 ) ;
V_9 -> V_27 . V_183 = V_184 + ( V_9 -> V_33 * V_185 / 100 ) ;
F_87 ( & V_9 -> V_27 ) ;
}
V_181:
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
return;
V_182:
goto V_181;
}
static int
F_88 ( struct V_186 * V_187 ,
unsigned long V_188 , void * V_189 )
{
struct V_190 * V_56 = V_189 ;
struct V_1 * log = F_1 ( V_56 -> V_2 ) ;
if ( V_188 == V_191 && V_56 -> V_95 == V_192 ) {
int V_193 ;
F_21 ( & log -> V_19 ) ;
for ( V_193 = 0 ; V_193 < V_5 ; V_193 ++ ) {
struct V_194 * V_195 ;
struct V_6 * V_9 ;
struct V_7 * V_8 = & log -> V_10 [ V_193 ] ;
F_89 (inst, t2, head, hlist) {
if ( V_56 -> V_15 == V_9 -> V_30 )
F_32 ( V_9 ) ;
}
}
F_30 ( & log -> V_19 ) ;
}
return V_196 ;
}
static int F_90 ( struct V_2 * V_2 , struct V_85 * V_197 ,
struct V_53 * V_42 , const struct V_58 * V_59 ,
const struct V_158 * const V_198 [] )
{
return - V_199 ;
}
static int F_91 ( struct V_2 * V_2 , struct V_85 * V_197 ,
struct V_53 * V_42 , const struct V_58 * V_59 ,
const struct V_158 * const V_200 [] )
{
struct V_61 * V_82 = F_55 ( V_59 ) ;
T_2 V_4 = F_92 ( V_82 -> V_93 ) ;
struct V_6 * V_9 ;
struct V_201 * V_202 = NULL ;
struct V_1 * log = F_1 ( V_2 ) ;
int V_203 = 0 ;
T_8 V_52 = 0 ;
if ( V_200 [ V_204 ] ) {
T_1 V_67 = V_82 -> V_90 ;
V_202 = F_80 ( V_200 [ V_204 ] ) ;
switch ( V_202 -> V_205 ) {
case V_206 :
return F_93 ( V_2 , V_67 , & V_207 ) ;
case V_208 :
F_94 ( V_2 , V_67 ) ;
return 0 ;
}
}
V_9 = F_8 ( log , V_4 ) ;
if ( V_9 && V_9 -> V_30 != F_95 ( V_42 ) . V_15 ) {
V_203 = - V_209 ;
goto V_210;
}
if ( V_200 [ V_211 ] ) {
V_52 = F_92 ( F_96 ( V_200 [ V_211 ] ) ) ;
if ( ( V_52 & V_176 ) &&
! F_97 ( V_74 ) ) {
#ifdef F_98
F_99 ( V_88 ) ;
F_100 ( L_3 ) ;
F_101 ( V_88 ) ;
if ( F_97 ( V_74 ) ) {
V_203 = - V_24 ;
goto V_210;
}
#endif
V_203 = - V_212 ;
goto V_210;
}
}
if ( V_202 != NULL ) {
switch ( V_202 -> V_205 ) {
case V_213 :
if ( V_9 ) {
V_203 = - V_214 ;
goto V_210;
}
V_9 = F_20 ( V_2 , V_4 ,
F_95 ( V_42 ) . V_15 ,
F_102 ( F_95 ( V_42 ) . V_86 ) ) ;
if ( F_103 ( V_9 ) ) {
V_203 = F_104 ( V_9 ) ;
goto V_63;
}
break;
case V_215 :
if ( ! V_9 ) {
V_203 = - V_216 ;
goto V_63;
}
F_37 ( log , V_9 ) ;
goto V_210;
default:
V_203 = - V_199 ;
goto V_210;
}
} else if ( ! V_9 ) {
V_203 = - V_216 ;
goto V_63;
}
if ( V_200 [ V_217 ] ) {
struct V_218 * V_219 =
F_80 ( V_200 [ V_217 ] ) ;
F_38 ( V_9 , V_219 -> V_37 ,
F_105 ( V_219 -> V_39 ) ) ;
}
if ( V_200 [ V_220 ] ) {
T_6 V_50 = F_106 ( V_200 [ V_220 ] ) ;
F_41 ( V_9 , F_105 ( V_50 ) ) ;
}
if ( V_200 [ V_221 ] ) {
T_6 V_35 = F_106 ( V_200 [ V_221 ] ) ;
F_40 ( V_9 , F_105 ( V_35 ) ) ;
}
if ( V_200 [ V_222 ] ) {
T_6 V_51 = F_106 ( V_200 [ V_222 ] ) ;
F_42 ( V_9 , F_105 ( V_51 ) ) ;
}
if ( V_200 [ V_211 ] )
F_43 ( V_9 , V_52 ) ;
V_210:
F_17 ( V_9 ) ;
V_63:
return V_203 ;
}
static struct V_194 * F_107 ( struct V_2 * V_2 , struct V_223 * V_224 )
{
struct V_1 * log ;
if ( ! V_224 )
return NULL ;
log = F_1 ( V_2 ) ;
for ( V_224 -> V_225 = 0 ; V_224 -> V_225 < V_5 ; V_224 -> V_225 ++ ) {
struct V_7 * V_8 = & log -> V_10 [ V_224 -> V_225 ] ;
if ( ! F_108 ( V_8 ) )
return F_109 ( F_110 ( V_8 ) ) ;
}
return NULL ;
}
static struct V_194 * F_111 ( struct V_2 * V_2 , struct V_223 * V_224 ,
struct V_194 * V_226 )
{
V_226 = F_109 ( F_112 ( V_226 ) ) ;
while ( ! V_226 ) {
struct V_1 * log ;
struct V_7 * V_8 ;
if ( ++ V_224 -> V_225 >= V_5 )
return NULL ;
log = F_1 ( V_2 ) ;
V_8 = & log -> V_10 [ V_224 -> V_225 ] ;
V_226 = F_109 ( F_110 ( V_8 ) ) ;
}
return V_226 ;
}
static struct V_194 * F_113 ( struct V_2 * V_2 , struct V_223 * V_224 ,
T_9 V_227 )
{
struct V_194 * V_8 ;
V_8 = F_107 ( V_2 , V_224 ) ;
if ( V_8 )
while ( V_227 && ( V_8 = F_111 ( V_2 , V_224 , V_8 ) ) )
V_227 -- ;
return V_227 ? NULL : V_8 ;
}
static void * F_114 ( struct V_228 * V_229 , T_9 * V_227 )
__acquires( T_10 )
{
F_9 () ;
return F_113 ( F_115 ( V_229 ) , V_229 -> V_230 , * V_227 ) ;
}
static void * F_116 ( struct V_228 * V_229 , void * V_231 , T_9 * V_227 )
{
( * V_227 ) ++ ;
return F_111 ( F_115 ( V_229 ) , V_229 -> V_230 , V_231 ) ;
}
static void F_117 ( struct V_228 * V_229 , void * V_231 )
__releases( T_10 )
{
F_11 () ;
}
static int F_118 ( struct V_228 * V_229 , void * V_231 )
{
const struct V_6 * V_9 = V_231 ;
F_119 ( V_229 , L_4 ,
V_9 -> V_4 ,
V_9 -> V_30 , V_9 -> V_57 ,
V_9 -> V_37 , V_9 -> V_39 ,
V_9 -> V_33 , F_120 ( & V_9 -> V_11 ) ) ;
return 0 ;
}
static int F_121 ( struct V_232 * V_232 , struct V_140 * V_140 )
{
return F_122 ( V_232 , V_140 , & V_233 ,
sizeof( struct V_223 ) ) ;
}
static int T_11 F_123 ( struct V_2 * V_2 )
{
unsigned int V_193 ;
struct V_1 * log = F_1 ( V_2 ) ;
#ifdef F_124
struct V_234 * V_235 ;
T_12 V_236 ;
T_13 V_237 ;
#endif
for ( V_193 = 0 ; V_193 < V_5 ; V_193 ++ )
F_125 ( & log -> V_10 [ V_193 ] ) ;
F_25 ( & log -> V_19 ) ;
#ifdef F_124
V_235 = F_126 ( L_5 , 0440 ,
V_2 -> V_238 . V_239 , & V_240 ) ;
if ( ! V_235 )
return - V_23 ;
V_236 = F_127 ( V_2 -> V_17 , 0 ) ;
V_237 = F_128 ( V_2 -> V_17 , 0 ) ;
if ( F_129 ( V_236 ) && F_130 ( V_237 ) )
F_131 ( V_235 , V_236 , V_237 ) ;
#endif
return 0 ;
}
static void T_14 F_132 ( struct V_2 * V_2 )
{
#ifdef F_124
F_133 ( L_5 , V_2 -> V_238 . V_239 ) ;
#endif
F_134 ( V_2 , & V_207 ) ;
}
static int T_15 F_135 ( void )
{
int V_45 ;
V_45 = F_136 ( & V_241 ) ;
if ( V_45 < 0 ) {
F_137 ( L_6 ) ;
goto V_63;
}
F_138 ( & V_242 ) ;
V_45 = F_139 ( & V_243 ) ;
if ( V_45 < 0 ) {
F_137 ( L_7 ) ;
goto V_244;
}
V_45 = F_140 ( V_245 , & V_207 ) ;
if ( V_45 < 0 ) {
F_137 ( L_8 ) ;
goto V_246;
}
return V_45 ;
V_246:
F_141 ( & V_243 ) ;
V_244:
F_142 ( & V_242 ) ;
F_143 ( & V_241 ) ;
V_63:
return V_45 ;
}
static void T_16 F_144 ( void )
{
F_145 ( & V_207 ) ;
F_141 ( & V_243 ) ;
F_142 ( & V_242 ) ;
F_143 ( & V_241 ) ;
}
