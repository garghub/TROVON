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
static int
F_48 ( struct V_6 * V_9 )
{
int V_45 = - 1 ;
if ( V_9 -> V_57 > 1 ) {
struct V_58 * V_59 = F_49 ( V_9 -> V_42 , 0 , 0 ,
V_60 ,
sizeof( struct V_61 ) ,
0 ) ;
if ( ! V_59 )
goto V_62;
}
V_45 = F_50 ( V_9 -> V_42 , V_9 -> V_2 , V_9 -> V_30 ,
V_63 ) ;
V_9 -> V_57 = 0 ;
V_9 -> V_42 = NULL ;
V_62:
return V_45 ;
}
static void
F_35 ( struct V_6 * V_9 )
{
if ( F_51 ( & V_9 -> V_27 ) )
F_17 ( V_9 ) ;
if ( V_9 -> V_42 )
F_48 ( V_9 ) ;
}
static void
V_28 ( unsigned long V_64 )
{
struct V_6 * V_9 = (struct V_6 * ) V_64 ;
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_42 )
F_48 ( V_9 ) ;
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
}
static inline int
F_52 ( struct V_1 * log ,
struct V_6 * V_9 ,
const struct V_53 * V_42 ,
unsigned int V_65 ,
T_1 V_66 ,
unsigned int V_67 ,
const struct V_68 * V_69 ,
const struct V_68 * V_70 ,
const char * V_71 , unsigned int V_72 )
{
struct V_73 V_74 ;
struct V_58 * V_59 ;
struct V_61 * V_75 ;
T_5 V_76 = V_9 -> V_42 -> V_77 ;
struct V_78 * V_79 ;
const unsigned char * V_80 ;
V_59 = F_49 ( V_9 -> V_42 , 0 , 0 ,
V_81 << 8 | V_82 ,
sizeof( struct V_61 ) , 0 ) ;
if ( ! V_59 )
return - 1 ;
V_75 = F_53 ( V_59 ) ;
V_75 -> V_83 = V_66 ;
V_75 -> V_84 = V_85 ;
V_75 -> V_86 = F_54 ( V_9 -> V_4 ) ;
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
V_74 . V_87 = V_42 -> V_88 ;
V_74 . V_89 = V_67 ;
if ( F_55 ( V_9 -> V_42 , V_90 , sizeof( V_74 ) , & V_74 ) )
goto V_91;
if ( V_71 &&
F_55 ( V_9 -> V_42 , V_92 , V_72 , V_71 ) )
goto V_91;
if ( V_69 ) {
#ifndef F_56
if ( F_57 ( V_9 -> V_42 , V_93 ,
F_58 ( V_69 -> V_94 ) ) )
goto V_91;
#else
if ( V_66 == V_95 ) {
if ( F_57 ( V_9 -> V_42 , V_96 ,
F_58 ( V_69 -> V_94 ) ) ||
F_57 ( V_9 -> V_42 , V_93 ,
F_58 ( F_59 ( V_69 ) -> V_97 -> V_98 -> V_94 ) ) )
goto V_91;
} else {
if ( F_57 ( V_9 -> V_42 , V_93 ,
F_58 ( V_69 -> V_94 ) ) )
goto V_91;
if ( V_42 -> V_99 && V_42 -> V_99 -> V_100 &&
F_57 ( V_9 -> V_42 , V_96 ,
F_58 ( V_42 -> V_99 -> V_100 -> V_94 ) ) )
goto V_91;
}
#endif
}
if ( V_70 ) {
#ifndef F_56
if ( F_57 ( V_9 -> V_42 , V_101 ,
F_58 ( V_70 -> V_94 ) ) )
goto V_91;
#else
if ( V_66 == V_95 ) {
if ( F_57 ( V_9 -> V_42 , V_102 ,
F_58 ( V_70 -> V_94 ) ) ||
F_57 ( V_9 -> V_42 , V_101 ,
F_58 ( F_59 ( V_70 ) -> V_97 -> V_98 -> V_94 ) ) )
goto V_91;
} else {
if ( F_57 ( V_9 -> V_42 , V_101 ,
F_58 ( V_70 -> V_94 ) ) )
goto V_91;
if ( V_42 -> V_99 && V_42 -> V_99 -> V_103 &&
F_57 ( V_9 -> V_42 , V_102 ,
F_58 ( V_42 -> V_99 -> V_103 -> V_94 ) ) )
goto V_91;
}
#endif
}
if ( V_42 -> V_104 &&
F_57 ( V_9 -> V_42 , V_105 , F_58 ( V_42 -> V_104 ) ) )
goto V_91;
if ( V_69 && V_42 -> V_98 &&
V_42 -> V_106 != V_42 -> V_107 ) {
struct V_108 V_109 ;
int V_110 ;
memset ( & V_109 , 0 , sizeof( V_109 ) ) ;
V_110 = F_60 ( V_42 , V_109 . V_111 ) ;
if ( V_110 > 0 ) {
V_109 . V_112 = F_54 ( V_110 ) ;
if ( F_55 ( V_9 -> V_42 , V_113 , sizeof( V_109 ) , & V_109 ) )
goto V_91;
}
}
if ( V_69 && F_61 ( V_42 ) ) {
if ( F_62 ( V_9 -> V_42 , V_114 , F_54 ( V_42 -> V_98 -> type ) ) ||
F_62 ( V_9 -> V_42 , V_115 ,
F_54 ( V_42 -> V_98 -> V_116 ) ) )
goto V_91;
V_80 = F_63 ( V_42 ) ;
if ( V_42 -> V_98 -> type == V_117 )
V_80 -= V_118 ;
if ( V_80 >= V_42 -> V_8 &&
F_55 ( V_9 -> V_42 , V_119 ,
V_42 -> V_98 -> V_116 , V_80 ) )
goto V_91;
}
if ( V_42 -> V_120 . V_121 ) {
struct V_122 V_123 ;
struct V_124 V_125 = F_64 ( V_42 -> V_120 ) ;
V_123 . V_126 = F_65 ( V_125 . V_127 ) ;
V_123 . V_128 = F_65 ( V_125 . V_129 ) ;
if ( F_55 ( V_9 -> V_42 , V_130 , sizeof( V_123 ) , & V_123 ) )
goto V_91;
}
V_79 = V_42 -> V_79 ;
if ( V_79 && V_79 -> V_131 != V_132 ) {
F_66 ( & V_79 -> V_133 ) ;
if ( V_79 -> V_134 && V_79 -> V_134 -> V_135 ) {
struct V_135 * V_135 = V_79 -> V_134 -> V_135 ;
const struct V_136 * V_136 = V_135 -> V_137 ;
struct V_16 * V_17 = V_9 -> V_29 ;
T_6 V_138 = F_58 ( F_67 ( V_17 , V_136 -> V_139 ) ) ;
T_6 V_140 = F_58 ( F_68 ( V_17 , V_136 -> V_141 ) ) ;
F_69 ( & V_79 -> V_133 ) ;
if ( F_57 ( V_9 -> V_42 , V_142 , V_138 ) ||
F_57 ( V_9 -> V_42 , V_143 , V_140 ) )
goto V_91;
} else
F_69 ( & V_79 -> V_133 ) ;
}
if ( ( V_9 -> V_52 & V_144 ) &&
F_57 ( V_9 -> V_42 , V_145 , F_58 ( V_9 -> V_146 ++ ) ) )
goto V_91;
if ( ( V_9 -> V_52 & V_147 ) &&
F_57 ( V_9 -> V_42 , V_148 ,
F_58 ( F_70 ( & log -> V_149 ) ) ) )
goto V_91;
if ( V_65 ) {
struct V_150 * V_151 ;
int V_152 = F_71 ( V_65 ) ;
if ( F_72 ( V_9 -> V_42 ) < F_73 ( V_65 ) ) {
F_74 ( V_153 L_2 ) ;
return - 1 ;
}
V_151 = (struct V_150 * ) F_75 ( V_9 -> V_42 , F_73 ( V_65 ) ) ;
V_151 -> V_154 = V_155 ;
V_151 -> V_156 = V_152 ;
if ( F_76 ( V_42 , 0 , F_77 ( V_151 ) , V_65 ) )
F_78 () ;
}
V_59 -> V_157 = V_9 -> V_42 -> V_77 - V_76 ;
return 0 ;
V_91:
F_79 ( V_158 L_3 ) ;
return - 1 ;
}
void
F_80 ( struct V_2 * V_2 ,
T_1 V_66 ,
unsigned int V_67 ,
const struct V_53 * V_42 ,
const struct V_68 * V_159 ,
const struct V_68 * V_62 ,
const struct V_160 * V_161 ,
const char * V_71 )
{
unsigned int V_152 , V_65 ;
struct V_6 * V_9 ;
const struct V_160 * V_162 ;
unsigned int V_31 ;
unsigned int V_72 ;
struct V_1 * log = F_1 ( V_2 ) ;
if ( V_161 && V_161 -> type == V_163 )
V_162 = V_161 ;
else
V_162 = & V_164 ;
V_9 = F_8 ( log , V_162 -> V_165 . V_166 . V_167 ) ;
if ( ! V_9 )
return;
V_72 = 0 ;
if ( V_71 )
V_72 = strlen ( V_71 ) + 1 ;
V_152 = F_81 ( sizeof( struct V_61 ) )
+ F_73 ( sizeof( struct V_73 ) )
+ F_73 ( sizeof( T_3 ) )
+ F_73 ( sizeof( T_3 ) )
#ifdef F_56
+ F_73 ( sizeof( T_3 ) )
+ F_73 ( sizeof( T_3 ) )
#endif
+ F_73 ( sizeof( T_3 ) )
+ F_73 ( sizeof( T_3 ) )
+ F_73 ( sizeof( T_3 ) )
+ F_73 ( V_72 )
+ F_73 ( sizeof( struct V_108 ) )
+ F_73 ( sizeof( struct V_122 ) ) ;
if ( V_159 && F_61 ( V_42 ) ) {
V_152 += F_73 ( V_42 -> V_98 -> V_116 )
+ F_73 ( sizeof( T_2 ) )
+ F_73 ( sizeof( T_2 ) ) ;
}
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_52 & V_144 )
V_152 += F_73 ( sizeof( T_3 ) ) ;
if ( V_9 -> V_52 & V_147 )
V_152 += F_73 ( sizeof( T_3 ) ) ;
V_31 = V_9 -> V_31 ;
if ( V_162 -> V_165 . V_166 . V_31 )
if ( V_31 > V_162 -> V_165 . V_166 . V_31 )
V_31 = V_162 -> V_165 . V_166 . V_31 ;
switch ( V_9 -> V_37 ) {
case V_47 :
case V_46 :
V_65 = 0 ;
break;
case V_38 :
if ( V_9 -> V_39 == 0
|| V_9 -> V_39 > V_42 -> V_110 )
V_65 = V_42 -> V_110 ;
else
V_65 = V_9 -> V_39 ;
V_152 += F_73 ( V_65 ) ;
break;
case V_41 :
default:
goto V_168;
}
if ( V_9 -> V_42 &&
V_152 > F_72 ( V_9 -> V_42 ) - sizeof( struct V_61 ) ) {
F_35 ( V_9 ) ;
}
if ( ! V_9 -> V_42 ) {
V_9 -> V_42 = F_44 ( V_2 , V_9 -> V_30 ,
V_9 -> V_35 , V_152 ) ;
if ( ! V_9 -> V_42 )
goto V_169;
}
V_9 -> V_57 ++ ;
F_52 ( log , V_9 , V_42 , V_65 , V_66 ,
V_67 , V_159 , V_62 , V_71 , V_72 ) ;
if ( V_9 -> V_57 >= V_31 )
F_35 ( V_9 ) ;
else if ( ! F_82 ( & V_9 -> V_27 ) ) {
F_6 ( V_9 ) ;
V_9 -> V_27 . V_170 = V_171 + ( V_9 -> V_33 * V_172 / 100 ) ;
F_83 ( & V_9 -> V_27 ) ;
}
V_168:
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
return;
V_169:
goto V_168;
}
static int
F_84 ( struct V_173 * V_174 ,
unsigned long V_175 , void * V_176 )
{
struct V_177 * V_56 = V_176 ;
struct V_1 * log = F_1 ( V_56 -> V_2 ) ;
if ( V_175 == V_178 && V_56 -> V_88 == V_179 ) {
int V_180 ;
F_21 ( & log -> V_19 ) ;
for ( V_180 = 0 ; V_180 < V_5 ; V_180 ++ ) {
struct V_181 * V_182 ;
struct V_6 * V_9 ;
struct V_7 * V_8 = & log -> V_10 [ V_180 ] ;
F_85 (inst, t2, head, hlist) {
if ( V_56 -> V_15 == V_9 -> V_30 )
F_32 ( V_9 ) ;
}
}
F_30 ( & log -> V_19 ) ;
}
return V_183 ;
}
static int
F_86 ( struct V_78 * V_184 , struct V_53 * V_42 ,
const struct V_58 * V_59 ,
const struct V_150 * const V_185 [] )
{
return - V_186 ;
}
static int
F_87 ( struct V_78 * V_184 , struct V_53 * V_42 ,
const struct V_58 * V_59 ,
const struct V_150 * const V_187 [] )
{
struct V_61 * V_75 = F_53 ( V_59 ) ;
T_2 V_4 = F_88 ( V_75 -> V_86 ) ;
struct V_6 * V_9 ;
struct V_188 * V_189 = NULL ;
struct V_2 * V_2 = F_89 ( V_184 ) ;
struct V_1 * log = F_1 ( V_2 ) ;
int V_190 = 0 ;
if ( V_187 [ V_191 ] ) {
T_1 V_66 = V_75 -> V_83 ;
V_189 = F_77 ( V_187 [ V_191 ] ) ;
switch ( V_189 -> V_192 ) {
case V_193 :
return F_90 ( V_2 , V_66 , & V_194 ) ;
case V_195 :
F_91 ( V_2 , V_66 ) ;
return 0 ;
}
}
V_9 = F_8 ( log , V_4 ) ;
if ( V_9 && V_9 -> V_30 != F_92 ( V_42 ) . V_15 ) {
V_190 = - V_196 ;
goto V_197;
}
if ( V_189 != NULL ) {
switch ( V_189 -> V_192 ) {
case V_198 :
if ( V_9 ) {
V_190 = - V_199 ;
goto V_197;
}
V_9 = F_20 ( V_2 , V_4 ,
F_92 ( V_42 ) . V_15 ,
F_93 ( F_92 ( V_42 ) . V_79 ) ) ;
if ( F_94 ( V_9 ) ) {
V_190 = F_95 ( V_9 ) ;
goto V_62;
}
break;
case V_200 :
if ( ! V_9 ) {
V_190 = - V_201 ;
goto V_62;
}
F_37 ( log , V_9 ) ;
goto V_197;
default:
V_190 = - V_186 ;
break;
}
}
if ( V_187 [ V_202 ] ) {
struct V_203 * V_204 ;
V_204 = F_77 ( V_187 [ V_202 ] ) ;
if ( ! V_9 ) {
V_190 = - V_201 ;
goto V_62;
}
F_38 ( V_9 , V_204 -> V_37 ,
F_96 ( V_204 -> V_39 ) ) ;
}
if ( V_187 [ V_205 ] ) {
T_6 V_50 = F_97 ( V_187 [ V_205 ] ) ;
if ( ! V_9 ) {
V_190 = - V_201 ;
goto V_62;
}
F_41 ( V_9 , F_96 ( V_50 ) ) ;
}
if ( V_187 [ V_206 ] ) {
T_6 V_35 = F_97 ( V_187 [ V_206 ] ) ;
if ( ! V_9 ) {
V_190 = - V_201 ;
goto V_62;
}
F_40 ( V_9 , F_96 ( V_35 ) ) ;
}
if ( V_187 [ V_207 ] ) {
T_6 V_51 = F_97 ( V_187 [ V_207 ] ) ;
if ( ! V_9 ) {
V_190 = - V_201 ;
goto V_62;
}
F_42 ( V_9 , F_96 ( V_51 ) ) ;
}
if ( V_187 [ V_208 ] ) {
T_7 V_52 = F_98 ( V_187 [ V_208 ] ) ;
if ( ! V_9 ) {
V_190 = - V_201 ;
goto V_62;
}
F_43 ( V_9 , F_88 ( V_52 ) ) ;
}
V_197:
F_17 ( V_9 ) ;
V_62:
return V_190 ;
}
static struct V_181 * F_99 ( struct V_2 * V_2 , struct V_209 * V_210 )
{
struct V_1 * log ;
if ( ! V_210 )
return NULL ;
log = F_1 ( V_2 ) ;
for ( V_210 -> V_211 = 0 ; V_210 -> V_211 < V_5 ; V_210 -> V_211 ++ ) {
struct V_7 * V_8 = & log -> V_10 [ V_210 -> V_211 ] ;
if ( ! F_100 ( V_8 ) )
return F_101 ( F_102 ( V_8 ) ) ;
}
return NULL ;
}
static struct V_181 * F_103 ( struct V_2 * V_2 , struct V_209 * V_210 ,
struct V_181 * V_212 )
{
V_212 = F_101 ( F_104 ( V_212 ) ) ;
while ( ! V_212 ) {
struct V_1 * log ;
struct V_7 * V_8 ;
if ( ++ V_210 -> V_211 >= V_5 )
return NULL ;
log = F_1 ( V_2 ) ;
V_8 = & log -> V_10 [ V_210 -> V_211 ] ;
V_212 = F_101 ( F_102 ( V_8 ) ) ;
}
return V_212 ;
}
static struct V_181 * F_105 ( struct V_2 * V_2 , struct V_209 * V_210 ,
T_8 V_213 )
{
struct V_181 * V_8 ;
V_8 = F_99 ( V_2 , V_210 ) ;
if ( V_8 )
while ( V_213 && ( V_8 = F_103 ( V_2 , V_210 , V_8 ) ) )
V_213 -- ;
return V_213 ? NULL : V_8 ;
}
static void * F_106 ( struct V_214 * V_215 , T_8 * V_213 )
__acquires( T_9 )
{
F_9 () ;
return F_105 ( F_107 ( V_215 ) , V_215 -> V_216 , * V_213 ) ;
}
static void * F_108 ( struct V_214 * V_215 , void * V_217 , T_8 * V_213 )
{
( * V_213 ) ++ ;
return F_103 ( F_107 ( V_215 ) , V_215 -> V_216 , V_217 ) ;
}
static void F_109 ( struct V_214 * V_215 , void * V_217 )
__releases( T_9 )
{
F_11 () ;
}
static int F_110 ( struct V_214 * V_215 , void * V_217 )
{
const struct V_6 * V_9 = V_217 ;
return F_111 ( V_215 , L_4 ,
V_9 -> V_4 ,
V_9 -> V_30 , V_9 -> V_57 ,
V_9 -> V_37 , V_9 -> V_39 ,
V_9 -> V_33 , F_112 ( & V_9 -> V_11 ) ) ;
}
static int F_113 ( struct V_218 * V_218 , struct V_135 * V_135 )
{
return F_114 ( V_218 , V_135 , & V_219 ,
sizeof( struct V_209 ) ) ;
}
static int T_10 F_115 ( struct V_2 * V_2 )
{
unsigned int V_180 ;
struct V_1 * log = F_1 ( V_2 ) ;
for ( V_180 = 0 ; V_180 < V_5 ; V_180 ++ )
F_116 ( & log -> V_10 [ V_180 ] ) ;
F_25 ( & log -> V_19 ) ;
#ifdef F_117
if ( ! F_118 ( L_5 , 0440 ,
V_2 -> V_220 . V_221 , & V_222 ) )
return - V_23 ;
#endif
return 0 ;
}
static void T_11 F_119 ( struct V_2 * V_2 )
{
#ifdef F_117
F_120 ( L_5 , V_2 -> V_220 . V_221 ) ;
#endif
F_121 ( V_2 , & V_194 ) ;
}
static int T_12 F_122 ( void )
{
int V_45 = - V_23 ;
F_123 ( & V_223 , sizeof( V_223 ) ) ;
F_124 ( & V_224 ) ;
V_45 = F_125 ( & V_225 ) ;
if ( V_45 < 0 ) {
F_47 ( L_6 ) ;
goto V_226;
}
V_45 = F_126 ( V_227 , & V_194 ) ;
if ( V_45 < 0 ) {
F_47 ( L_7 ) ;
goto V_228;
}
V_45 = F_127 ( & V_229 ) ;
if ( V_45 < 0 ) {
F_47 ( L_8 ) ;
goto V_230;
}
return V_45 ;
V_230:
F_128 ( & V_194 ) ;
V_228:
F_129 ( & V_225 ) ;
V_226:
F_130 ( & V_224 ) ;
return V_45 ;
}
static void T_13 F_131 ( void )
{
F_132 ( & V_229 ) ;
F_128 ( & V_194 ) ;
F_129 ( & V_225 ) ;
F_130 ( & V_224 ) ;
}
