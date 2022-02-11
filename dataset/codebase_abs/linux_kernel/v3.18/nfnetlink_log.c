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
int V_15 , struct V_16 * V_17 )
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
F_40 ( struct V_6 * V_9 , T_3 V_35 )
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
static int
F_41 ( struct V_6 * V_9 , T_3 V_50 )
{
F_21 ( & V_9 -> V_26 ) ;
V_9 -> V_33 = V_50 ;
F_30 ( & V_9 -> V_26 ) ;
return 0 ;
}
static int
F_42 ( struct V_6 * V_9 , T_3 V_51 )
{
F_21 ( & V_9 -> V_26 ) ;
V_9 -> V_31 = V_51 ;
F_30 ( & V_9 -> V_26 ) ;
return 0 ;
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
F_44 ( struct V_2 * V_2 , T_4 V_30 , unsigned int V_54 ,
unsigned int V_55 )
{
struct V_53 * V_42 ;
unsigned int V_56 ;
V_56 = F_45 ( V_54 , V_55 ) ;
V_42 = F_46 ( V_2 , V_56 , V_30 , V_22 ) ;
if ( ! V_42 ) {
if ( V_56 > V_55 ) {
V_42 = F_46 ( V_2 , V_55 ,
V_30 , V_22 ) ;
if ( ! V_42 )
F_47 ( L_1 ,
V_55 ) ;
}
}
return V_42 ;
}
static void
F_48 ( struct V_6 * V_9 )
{
if ( V_9 -> V_57 > 1 ) {
struct V_58 * V_59 = F_49 ( V_9 -> V_42 , 0 , 0 ,
V_60 ,
sizeof( struct V_61 ) ,
0 ) ;
if ( F_50 ( ! V_59 , L_2 ,
V_9 -> V_42 -> V_62 , F_51 ( V_9 -> V_42 ) ) ) {
F_52 ( V_9 -> V_42 ) ;
goto V_63;
}
}
F_53 ( V_9 -> V_42 , V_9 -> V_2 , V_9 -> V_30 ,
V_64 ) ;
V_63:
V_9 -> V_57 = 0 ;
V_9 -> V_42 = NULL ;
}
static void
F_35 ( struct V_6 * V_9 )
{
if ( F_54 ( & V_9 -> V_27 ) )
F_17 ( V_9 ) ;
if ( V_9 -> V_42 )
F_48 ( V_9 ) ;
}
static void
V_28 ( unsigned long V_65 )
{
struct V_6 * V_9 = (struct V_6 * ) V_65 ;
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_42 )
F_48 ( V_9 ) ;
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
}
static inline int
F_55 ( struct V_1 * log ,
struct V_6 * V_9 ,
const struct V_53 * V_42 ,
unsigned int V_66 ,
T_1 V_67 ,
unsigned int V_68 ,
const struct V_69 * V_70 ,
const struct V_69 * V_71 ,
const char * V_72 , unsigned int V_73 )
{
struct V_74 V_75 ;
struct V_58 * V_59 ;
struct V_61 * V_76 ;
T_5 V_77 = V_9 -> V_42 -> V_78 ;
struct V_79 * V_80 ;
const unsigned char * V_81 ;
V_59 = F_49 ( V_9 -> V_42 , 0 , 0 ,
V_82 << 8 | V_83 ,
sizeof( struct V_61 ) , 0 ) ;
if ( ! V_59 )
return - 1 ;
V_76 = F_56 ( V_59 ) ;
V_76 -> V_84 = V_67 ;
V_76 -> V_85 = V_86 ;
V_76 -> V_87 = F_57 ( V_9 -> V_4 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_88 = V_42 -> V_89 ;
V_75 . V_90 = V_68 ;
if ( F_58 ( V_9 -> V_42 , V_91 , sizeof( V_75 ) , & V_75 ) )
goto V_92;
if ( V_72 &&
F_58 ( V_9 -> V_42 , V_93 , V_73 , V_72 ) )
goto V_92;
if ( V_70 ) {
#if ! F_59 ( V_94 )
if ( F_60 ( V_9 -> V_42 , V_95 ,
F_61 ( V_70 -> V_96 ) ) )
goto V_92;
#else
if ( V_67 == V_97 ) {
if ( F_60 ( V_9 -> V_42 , V_98 ,
F_61 ( V_70 -> V_96 ) ) ||
F_60 ( V_9 -> V_42 , V_95 ,
F_61 ( F_62 ( V_70 ) -> V_99 -> V_100 -> V_96 ) ) )
goto V_92;
} else {
if ( F_60 ( V_9 -> V_42 , V_95 ,
F_61 ( V_70 -> V_96 ) ) )
goto V_92;
if ( V_42 -> V_101 && V_42 -> V_101 -> V_102 &&
F_60 ( V_9 -> V_42 , V_98 ,
F_61 ( V_42 -> V_101 -> V_102 -> V_96 ) ) )
goto V_92;
}
#endif
}
if ( V_71 ) {
#if ! F_59 ( V_94 )
if ( F_60 ( V_9 -> V_42 , V_103 ,
F_61 ( V_71 -> V_96 ) ) )
goto V_92;
#else
if ( V_67 == V_97 ) {
if ( F_60 ( V_9 -> V_42 , V_104 ,
F_61 ( V_71 -> V_96 ) ) ||
F_60 ( V_9 -> V_42 , V_103 ,
F_61 ( F_62 ( V_71 ) -> V_99 -> V_100 -> V_96 ) ) )
goto V_92;
} else {
if ( F_60 ( V_9 -> V_42 , V_103 ,
F_61 ( V_71 -> V_96 ) ) )
goto V_92;
if ( V_42 -> V_101 && V_42 -> V_101 -> V_105 &&
F_60 ( V_9 -> V_42 , V_104 ,
F_61 ( V_42 -> V_101 -> V_105 -> V_96 ) ) )
goto V_92;
}
#endif
}
if ( V_42 -> V_106 &&
F_60 ( V_9 -> V_42 , V_107 , F_61 ( V_42 -> V_106 ) ) )
goto V_92;
if ( V_70 && V_42 -> V_100 &&
V_42 -> V_108 != V_42 -> V_109 ) {
struct V_110 V_111 ;
int V_62 ;
memset ( & V_111 , 0 , sizeof( V_111 ) ) ;
V_62 = F_63 ( V_42 , V_111 . V_112 ) ;
if ( V_62 > 0 ) {
V_111 . V_113 = F_57 ( V_62 ) ;
if ( F_58 ( V_9 -> V_42 , V_114 , sizeof( V_111 ) , & V_111 ) )
goto V_92;
}
}
if ( V_70 && F_64 ( V_42 ) ) {
if ( F_65 ( V_9 -> V_42 , V_115 , F_57 ( V_42 -> V_100 -> type ) ) ||
F_65 ( V_9 -> V_42 , V_116 ,
F_57 ( V_42 -> V_100 -> V_117 ) ) )
goto V_92;
V_81 = F_66 ( V_42 ) ;
if ( V_42 -> V_100 -> type == V_118 )
V_81 -= V_119 ;
if ( V_81 >= V_42 -> V_8 &&
F_58 ( V_9 -> V_42 , V_120 ,
V_42 -> V_100 -> V_117 , V_81 ) )
goto V_92;
}
if ( V_42 -> V_121 . V_122 ) {
struct V_123 V_124 ;
struct V_125 V_126 = F_67 ( V_42 -> V_121 ) ;
V_124 . V_127 = F_68 ( V_126 . V_128 ) ;
V_124 . V_129 = F_68 ( V_126 . V_130 ) ;
if ( F_58 ( V_9 -> V_42 , V_131 , sizeof( V_124 ) , & V_124 ) )
goto V_92;
}
V_80 = V_42 -> V_80 ;
if ( V_80 && V_80 -> V_132 != V_133 ) {
F_69 ( & V_80 -> V_134 ) ;
if ( V_80 -> V_135 && V_80 -> V_135 -> V_136 ) {
struct V_136 * V_136 = V_80 -> V_135 -> V_136 ;
const struct V_137 * V_137 = V_136 -> V_138 ;
struct V_16 * V_17 = V_9 -> V_29 ;
T_6 V_139 = F_61 ( F_70 ( V_17 , V_137 -> V_140 ) ) ;
T_6 V_141 = F_61 ( F_71 ( V_17 , V_137 -> V_142 ) ) ;
F_72 ( & V_80 -> V_134 ) ;
if ( F_60 ( V_9 -> V_42 , V_143 , V_139 ) ||
F_60 ( V_9 -> V_42 , V_144 , V_141 ) )
goto V_92;
} else
F_72 ( & V_80 -> V_134 ) ;
}
if ( ( V_9 -> V_52 & V_145 ) &&
F_60 ( V_9 -> V_42 , V_146 , F_61 ( V_9 -> V_147 ++ ) ) )
goto V_92;
if ( ( V_9 -> V_52 & V_148 ) &&
F_60 ( V_9 -> V_42 , V_149 ,
F_61 ( F_73 ( & log -> V_150 ) ) ) )
goto V_92;
if ( V_66 ) {
struct V_151 * V_152 ;
int V_153 = F_74 ( V_66 ) ;
if ( F_51 ( V_9 -> V_42 ) < F_75 ( V_66 ) ) {
F_76 ( V_154 L_3 ) ;
return - 1 ;
}
V_152 = (struct V_151 * ) F_77 ( V_9 -> V_42 , F_75 ( V_66 ) ) ;
V_152 -> V_155 = V_156 ;
V_152 -> V_157 = V_153 ;
if ( F_78 ( V_42 , 0 , F_79 ( V_152 ) , V_66 ) )
F_80 () ;
}
V_59 -> V_158 = V_9 -> V_42 -> V_78 - V_77 ;
return 0 ;
V_92:
F_81 ( V_159 L_4 ) ;
return - 1 ;
}
void
F_82 ( struct V_2 * V_2 ,
T_1 V_67 ,
unsigned int V_68 ,
const struct V_53 * V_42 ,
const struct V_69 * V_160 ,
const struct V_69 * V_63 ,
const struct V_161 * V_162 ,
const char * V_72 )
{
unsigned int V_153 , V_66 ;
struct V_6 * V_9 ;
const struct V_161 * V_163 ;
unsigned int V_31 ;
unsigned int V_73 ;
struct V_1 * log = F_1 ( V_2 ) ;
if ( V_162 && V_162 -> type == V_164 )
V_163 = V_162 ;
else
V_163 = & V_165 ;
V_9 = F_8 ( log , V_163 -> V_166 . V_167 . V_168 ) ;
if ( ! V_9 )
return;
V_73 = 0 ;
if ( V_72 )
V_73 = strlen ( V_72 ) + 1 ;
V_153 = F_83 ( sizeof( struct V_61 ) )
+ F_75 ( sizeof( struct V_74 ) )
+ F_75 ( sizeof( T_3 ) )
+ F_75 ( sizeof( T_3 ) )
#if F_59 ( V_94 )
+ F_75 ( sizeof( T_3 ) )
+ F_75 ( sizeof( T_3 ) )
#endif
+ F_75 ( sizeof( T_3 ) )
+ F_75 ( sizeof( T_3 ) )
+ F_75 ( sizeof( T_3 ) )
+ F_75 ( V_73 )
+ F_75 ( sizeof( struct V_110 ) )
+ F_75 ( sizeof( struct V_123 ) )
+ F_75 ( sizeof( struct V_61 ) ) ;
if ( V_160 && F_64 ( V_42 ) ) {
V_153 += F_75 ( V_42 -> V_100 -> V_117 )
+ F_75 ( sizeof( T_2 ) )
+ F_75 ( sizeof( T_2 ) ) ;
}
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_52 & V_145 )
V_153 += F_75 ( sizeof( T_3 ) ) ;
if ( V_9 -> V_52 & V_148 )
V_153 += F_75 ( sizeof( T_3 ) ) ;
V_31 = V_9 -> V_31 ;
if ( V_163 -> V_166 . V_167 . V_31 )
if ( V_31 > V_163 -> V_166 . V_167 . V_31 )
V_31 = V_163 -> V_166 . V_167 . V_31 ;
switch ( V_9 -> V_37 ) {
case V_47 :
case V_46 :
V_66 = 0 ;
break;
case V_38 :
if ( V_9 -> V_39 > V_42 -> V_62 )
V_66 = V_42 -> V_62 ;
else
V_66 = V_9 -> V_39 ;
V_153 += F_75 ( V_66 ) ;
break;
case V_41 :
default:
goto V_169;
}
if ( V_9 -> V_42 && V_153 > F_51 ( V_9 -> V_42 ) ) {
F_35 ( V_9 ) ;
}
if ( ! V_9 -> V_42 ) {
V_9 -> V_42 = F_44 ( V_2 , V_9 -> V_30 ,
V_9 -> V_35 , V_153 ) ;
if ( ! V_9 -> V_42 )
goto V_170;
}
V_9 -> V_57 ++ ;
F_55 ( log , V_9 , V_42 , V_66 , V_67 ,
V_68 , V_160 , V_63 , V_72 , V_73 ) ;
if ( V_9 -> V_57 >= V_31 )
F_35 ( V_9 ) ;
else if ( ! F_84 ( & V_9 -> V_27 ) ) {
F_6 ( V_9 ) ;
V_9 -> V_27 . V_171 = V_172 + ( V_9 -> V_33 * V_173 / 100 ) ;
F_85 ( & V_9 -> V_27 ) ;
}
V_169:
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
return;
V_170:
goto V_169;
}
static int
F_86 ( struct V_174 * V_175 ,
unsigned long V_176 , void * V_177 )
{
struct V_178 * V_56 = V_177 ;
struct V_1 * log = F_1 ( V_56 -> V_2 ) ;
if ( V_176 == V_179 && V_56 -> V_89 == V_180 ) {
int V_181 ;
F_21 ( & log -> V_19 ) ;
for ( V_181 = 0 ; V_181 < V_5 ; V_181 ++ ) {
struct V_182 * V_183 ;
struct V_6 * V_9 ;
struct V_7 * V_8 = & log -> V_10 [ V_181 ] ;
F_87 (inst, t2, head, hlist) {
if ( V_56 -> V_15 == V_9 -> V_30 )
F_32 ( V_9 ) ;
}
}
F_30 ( & log -> V_19 ) ;
}
return V_184 ;
}
static int
F_88 ( struct V_79 * V_185 , struct V_53 * V_42 ,
const struct V_58 * V_59 ,
const struct V_151 * const V_186 [] )
{
return - V_187 ;
}
static int
F_89 ( struct V_79 * V_185 , struct V_53 * V_42 ,
const struct V_58 * V_59 ,
const struct V_151 * const V_188 [] )
{
struct V_61 * V_76 = F_56 ( V_59 ) ;
T_2 V_4 = F_90 ( V_76 -> V_87 ) ;
struct V_6 * V_9 ;
struct V_189 * V_190 = NULL ;
struct V_2 * V_2 = F_91 ( V_185 ) ;
struct V_1 * log = F_1 ( V_2 ) ;
int V_191 = 0 ;
if ( V_188 [ V_192 ] ) {
T_1 V_67 = V_76 -> V_84 ;
V_190 = F_79 ( V_188 [ V_192 ] ) ;
switch ( V_190 -> V_193 ) {
case V_194 :
return F_92 ( V_2 , V_67 , & V_195 ) ;
case V_196 :
F_93 ( V_2 , V_67 ) ;
return 0 ;
}
}
V_9 = F_8 ( log , V_4 ) ;
if ( V_9 && V_9 -> V_30 != F_94 ( V_42 ) . V_15 ) {
V_191 = - V_197 ;
goto V_198;
}
if ( V_190 != NULL ) {
switch ( V_190 -> V_193 ) {
case V_199 :
if ( V_9 ) {
V_191 = - V_200 ;
goto V_198;
}
V_9 = F_20 ( V_2 , V_4 ,
F_94 ( V_42 ) . V_15 ,
F_95 ( F_94 ( V_42 ) . V_80 ) ) ;
if ( F_96 ( V_9 ) ) {
V_191 = F_97 ( V_9 ) ;
goto V_63;
}
break;
case V_201 :
if ( ! V_9 ) {
V_191 = - V_202 ;
goto V_63;
}
F_37 ( log , V_9 ) ;
goto V_198;
default:
V_191 = - V_187 ;
break;
}
}
if ( V_188 [ V_203 ] ) {
struct V_204 * V_205 ;
V_205 = F_79 ( V_188 [ V_203 ] ) ;
if ( ! V_9 ) {
V_191 = - V_202 ;
goto V_63;
}
F_38 ( V_9 , V_205 -> V_37 ,
F_98 ( V_205 -> V_39 ) ) ;
}
if ( V_188 [ V_206 ] ) {
T_6 V_50 = F_99 ( V_188 [ V_206 ] ) ;
if ( ! V_9 ) {
V_191 = - V_202 ;
goto V_63;
}
F_41 ( V_9 , F_98 ( V_50 ) ) ;
}
if ( V_188 [ V_207 ] ) {
T_6 V_35 = F_99 ( V_188 [ V_207 ] ) ;
if ( ! V_9 ) {
V_191 = - V_202 ;
goto V_63;
}
F_40 ( V_9 , F_98 ( V_35 ) ) ;
}
if ( V_188 [ V_208 ] ) {
T_6 V_51 = F_99 ( V_188 [ V_208 ] ) ;
if ( ! V_9 ) {
V_191 = - V_202 ;
goto V_63;
}
F_42 ( V_9 , F_98 ( V_51 ) ) ;
}
if ( V_188 [ V_209 ] ) {
T_7 V_52 = F_100 ( V_188 [ V_209 ] ) ;
if ( ! V_9 ) {
V_191 = - V_202 ;
goto V_63;
}
F_43 ( V_9 , F_90 ( V_52 ) ) ;
}
V_198:
F_17 ( V_9 ) ;
V_63:
return V_191 ;
}
static struct V_182 * F_101 ( struct V_2 * V_2 , struct V_210 * V_211 )
{
struct V_1 * log ;
if ( ! V_211 )
return NULL ;
log = F_1 ( V_2 ) ;
for ( V_211 -> V_212 = 0 ; V_211 -> V_212 < V_5 ; V_211 -> V_212 ++ ) {
struct V_7 * V_8 = & log -> V_10 [ V_211 -> V_212 ] ;
if ( ! F_102 ( V_8 ) )
return F_103 ( F_104 ( V_8 ) ) ;
}
return NULL ;
}
static struct V_182 * F_105 ( struct V_2 * V_2 , struct V_210 * V_211 ,
struct V_182 * V_213 )
{
V_213 = F_103 ( F_106 ( V_213 ) ) ;
while ( ! V_213 ) {
struct V_1 * log ;
struct V_7 * V_8 ;
if ( ++ V_211 -> V_212 >= V_5 )
return NULL ;
log = F_1 ( V_2 ) ;
V_8 = & log -> V_10 [ V_211 -> V_212 ] ;
V_213 = F_103 ( F_104 ( V_8 ) ) ;
}
return V_213 ;
}
static struct V_182 * F_107 ( struct V_2 * V_2 , struct V_210 * V_211 ,
T_8 V_214 )
{
struct V_182 * V_8 ;
V_8 = F_101 ( V_2 , V_211 ) ;
if ( V_8 )
while ( V_214 && ( V_8 = F_105 ( V_2 , V_211 , V_8 ) ) )
V_214 -- ;
return V_214 ? NULL : V_8 ;
}
static void * F_108 ( struct V_215 * V_216 , T_8 * V_214 )
__acquires( T_9 )
{
F_9 () ;
return F_107 ( F_109 ( V_216 ) , V_216 -> V_217 , * V_214 ) ;
}
static void * F_110 ( struct V_215 * V_216 , void * V_218 , T_8 * V_214 )
{
( * V_214 ) ++ ;
return F_105 ( F_109 ( V_216 ) , V_216 -> V_217 , V_218 ) ;
}
static void F_111 ( struct V_215 * V_216 , void * V_218 )
__releases( T_9 )
{
F_11 () ;
}
static int F_112 ( struct V_215 * V_216 , void * V_218 )
{
const struct V_6 * V_9 = V_218 ;
return F_113 ( V_216 , L_5 ,
V_9 -> V_4 ,
V_9 -> V_30 , V_9 -> V_57 ,
V_9 -> V_37 , V_9 -> V_39 ,
V_9 -> V_33 , F_114 ( & V_9 -> V_11 ) ) ;
}
static int F_115 ( struct V_219 * V_219 , struct V_136 * V_136 )
{
return F_116 ( V_219 , V_136 , & V_220 ,
sizeof( struct V_210 ) ) ;
}
static int T_10 F_117 ( struct V_2 * V_2 )
{
unsigned int V_181 ;
struct V_1 * log = F_1 ( V_2 ) ;
for ( V_181 = 0 ; V_181 < V_5 ; V_181 ++ )
F_118 ( & log -> V_10 [ V_181 ] ) ;
F_25 ( & log -> V_19 ) ;
#ifdef F_119
if ( ! F_120 ( L_6 , 0440 ,
V_2 -> V_221 . V_222 , & V_223 ) )
return - V_23 ;
#endif
return 0 ;
}
static void T_11 F_121 ( struct V_2 * V_2 )
{
#ifdef F_119
F_122 ( L_6 , V_2 -> V_221 . V_222 ) ;
#endif
F_123 ( V_2 , & V_195 ) ;
}
static int T_12 F_124 ( void )
{
int V_45 = - V_23 ;
F_125 ( & V_224 ) ;
V_45 = F_126 ( & V_225 ) ;
if ( V_45 < 0 ) {
F_47 ( L_7 ) ;
goto V_226;
}
V_45 = F_127 ( V_227 , & V_195 ) ;
if ( V_45 < 0 ) {
F_47 ( L_8 ) ;
goto V_228;
}
V_45 = F_128 ( & V_229 ) ;
if ( V_45 < 0 ) {
F_47 ( L_9 ) ;
goto V_230;
}
return V_45 ;
V_230:
F_129 ( & V_195 ) ;
V_228:
F_130 ( & V_225 ) ;
V_226:
F_131 ( & V_224 ) ;
return V_45 ;
}
static void T_13 F_132 ( void )
{
F_133 ( & V_229 ) ;
F_129 ( & V_195 ) ;
F_130 ( & V_225 ) ;
F_131 ( & V_224 ) ;
}
