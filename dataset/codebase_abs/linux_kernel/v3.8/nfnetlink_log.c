static inline T_1 F_1 ( T_2 V_1 )
{
return ( ( V_1 & 0xff ) % V_2 ) ;
}
static struct V_3 *
F_2 ( T_2 V_1 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_3 * V_8 ;
V_5 = & V_9 [ F_1 ( V_1 ) ] ;
F_3 (inst, pos, head, hlist) {
if ( V_8 -> V_1 == V_1 )
return V_8 ;
}
return NULL ;
}
static inline void
F_4 ( struct V_3 * V_8 )
{
F_5 ( & V_8 -> V_10 ) ;
}
static struct V_3 *
F_6 ( T_2 V_1 )
{
struct V_3 * V_8 ;
F_7 () ;
V_8 = F_2 ( V_1 ) ;
if ( V_8 && ! F_8 ( & V_8 -> V_10 ) )
V_8 = NULL ;
F_9 () ;
return V_8 ;
}
static void F_10 ( struct V_11 * V_5 )
{
F_11 ( F_12 ( V_5 , struct V_3 , V_12 ) ) ;
F_13 ( V_13 ) ;
}
static void
F_14 ( struct V_3 * V_8 )
{
if ( V_8 && F_15 ( & V_8 -> V_10 ) )
F_16 ( & V_8 -> V_12 , F_10 ) ;
}
static struct V_3 *
F_17 ( T_2 V_1 , int V_14 , struct V_15 * V_16 )
{
struct V_3 * V_8 ;
int V_17 ;
F_18 ( & V_18 ) ;
if ( F_2 ( V_1 ) ) {
V_17 = - V_19 ;
goto V_20;
}
V_8 = F_19 ( sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 ) {
V_17 = - V_22 ;
goto V_20;
}
if ( ! F_20 ( V_13 ) ) {
F_11 ( V_8 ) ;
V_17 = - V_23 ;
goto V_20;
}
F_21 ( & V_8 -> V_24 ) ;
F_22 ( & V_8 -> V_25 ) ;
F_23 ( & V_8 -> V_10 , 2 ) ;
F_24 ( & V_8 -> V_26 , V_27 , ( unsigned long ) V_8 ) ;
V_8 -> V_28 = V_16 ;
V_8 -> V_29 = V_14 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_30 = V_31 ;
V_8 -> V_32 = V_33 ;
V_8 -> V_34 = V_35 ;
V_8 -> V_36 = V_37 ;
V_8 -> V_38 = V_39 ;
F_25 ( & V_8 -> V_24 ,
& V_9 [ F_1 ( V_1 ) ] ) ;
F_26 ( & V_18 ) ;
return V_8 ;
V_20:
F_26 ( & V_18 ) ;
return F_27 ( V_17 ) ;
}
static void
F_28 ( struct V_3 * V_8 )
{
F_29 ( & V_8 -> V_24 ) ;
F_30 ( & V_8 -> V_25 ) ;
V_8 -> V_36 = V_40 ;
if ( V_8 -> V_41 )
F_31 ( V_8 ) ;
F_32 ( & V_8 -> V_25 ) ;
F_14 ( V_8 ) ;
}
static inline void
F_33 ( struct V_3 * V_8 )
{
F_18 ( & V_18 ) ;
F_28 ( V_8 ) ;
F_26 ( & V_18 ) ;
}
static int
F_34 ( struct V_3 * V_8 , T_1 V_42 ,
unsigned int V_43 )
{
int V_44 = 0 ;
F_18 ( & V_8 -> V_25 ) ;
switch ( V_42 ) {
case V_45 :
case V_46 :
V_8 -> V_36 = V_42 ;
V_8 -> V_38 = 0 ;
break;
case V_37 :
V_8 -> V_36 = V_42 ;
V_8 -> V_38 = F_35 (unsigned int,
range, NFULNL_COPY_RANGE_MAX) ;
break;
default:
V_44 = - V_47 ;
break;
}
F_26 ( & V_8 -> V_25 ) ;
return V_44 ;
}
static int
F_36 ( struct V_3 * V_8 , T_3 V_34 )
{
int V_44 ;
F_18 ( & V_8 -> V_25 ) ;
if ( V_34 < V_35 )
V_44 = - V_48 ;
else if ( V_34 > 131072 )
V_44 = - V_48 ;
else {
V_8 -> V_34 = V_34 ;
V_44 = 0 ;
}
F_26 ( & V_8 -> V_25 ) ;
return V_44 ;
}
static int
F_37 ( struct V_3 * V_8 , T_3 V_49 )
{
F_18 ( & V_8 -> V_25 ) ;
V_8 -> V_32 = V_49 ;
F_26 ( & V_8 -> V_25 ) ;
return 0 ;
}
static int
F_38 ( struct V_3 * V_8 , T_3 V_50 )
{
F_18 ( & V_8 -> V_25 ) ;
V_8 -> V_30 = V_50 ;
F_26 ( & V_8 -> V_25 ) ;
return 0 ;
}
static int
F_39 ( struct V_3 * V_8 , T_2 V_51 )
{
F_18 ( & V_8 -> V_25 ) ;
V_8 -> V_51 = V_51 ;
F_26 ( & V_8 -> V_25 ) ;
return 0 ;
}
static struct V_52 *
F_40 ( unsigned int V_53 , unsigned int V_54 )
{
struct V_52 * V_41 ;
unsigned int V_55 ;
V_55 = F_41 ( V_53 , V_54 ) ;
V_41 = F_42 ( V_55 , V_21 ) ;
if ( ! V_41 ) {
if ( V_55 > V_54 ) {
V_41 = F_42 ( V_54 , V_21 ) ;
if ( ! V_41 )
F_43 ( L_1 ,
V_54 ) ;
}
}
return V_41 ;
}
static int
F_44 ( struct V_3 * V_8 )
{
int V_44 = - 1 ;
if ( V_8 -> V_56 > 1 ) {
struct V_57 * V_58 = F_45 ( V_8 -> V_41 , 0 , 0 ,
V_59 ,
sizeof( struct V_60 ) ,
0 ) ;
if ( ! V_58 )
goto V_61;
}
V_44 = F_46 ( V_8 -> V_41 , & V_62 , V_8 -> V_29 ,
V_63 ) ;
V_8 -> V_56 = 0 ;
V_8 -> V_41 = NULL ;
V_61:
return V_44 ;
}
static void
F_31 ( struct V_3 * V_8 )
{
if ( F_47 ( & V_8 -> V_26 ) )
F_14 ( V_8 ) ;
if ( V_8 -> V_41 )
F_44 ( V_8 ) ;
}
static void
V_27 ( unsigned long V_64 )
{
struct V_3 * V_8 = (struct V_3 * ) V_64 ;
F_18 ( & V_8 -> V_25 ) ;
if ( V_8 -> V_41 )
F_44 ( V_8 ) ;
F_26 ( & V_8 -> V_25 ) ;
F_14 ( V_8 ) ;
}
static inline int
F_48 ( struct V_3 * V_8 ,
const struct V_52 * V_41 ,
unsigned int V_65 ,
T_1 V_66 ,
unsigned int V_67 ,
const struct V_68 * V_69 ,
const struct V_68 * V_70 ,
const char * V_71 , unsigned int V_72 )
{
struct V_73 V_74 ;
struct V_57 * V_58 ;
struct V_60 * V_75 ;
T_4 V_76 = V_8 -> V_41 -> V_77 ;
struct V_78 * V_79 ;
const unsigned char * V_80 ;
V_58 = F_45 ( V_8 -> V_41 , 0 , 0 ,
V_81 << 8 | V_82 ,
sizeof( struct V_60 ) , 0 ) ;
if ( ! V_58 )
return - 1 ;
V_75 = F_49 ( V_58 ) ;
V_75 -> V_83 = V_66 ;
V_75 -> V_84 = V_85 ;
V_75 -> V_86 = F_50 ( V_8 -> V_1 ) ;
V_74 . V_87 = V_41 -> V_88 ;
V_74 . V_89 = V_67 ;
if ( F_51 ( V_8 -> V_41 , V_90 , sizeof( V_74 ) , & V_74 ) )
goto V_91;
if ( V_71 &&
F_51 ( V_8 -> V_41 , V_92 , V_72 , V_71 ) )
goto V_91;
if ( V_69 ) {
#ifndef F_52
if ( F_53 ( V_8 -> V_41 , V_93 ,
F_54 ( V_69 -> V_94 ) ) )
goto V_91;
#else
if ( V_66 == V_95 ) {
if ( F_53 ( V_8 -> V_41 , V_96 ,
F_54 ( V_69 -> V_94 ) ) ||
F_53 ( V_8 -> V_41 , V_93 ,
F_54 ( F_55 ( V_69 ) -> V_97 -> V_98 -> V_94 ) ) )
goto V_91;
} else {
if ( F_53 ( V_8 -> V_41 , V_93 ,
F_54 ( V_69 -> V_94 ) ) )
goto V_91;
if ( V_41 -> V_99 && V_41 -> V_99 -> V_100 &&
F_53 ( V_8 -> V_41 , V_96 ,
F_54 ( V_41 -> V_99 -> V_100 -> V_94 ) ) )
goto V_91;
}
#endif
}
if ( V_70 ) {
#ifndef F_52
if ( F_53 ( V_8 -> V_41 , V_101 ,
F_54 ( V_70 -> V_94 ) ) )
goto V_91;
#else
if ( V_66 == V_95 ) {
if ( F_53 ( V_8 -> V_41 , V_102 ,
F_54 ( V_70 -> V_94 ) ) ||
F_53 ( V_8 -> V_41 , V_101 ,
F_54 ( F_55 ( V_70 ) -> V_97 -> V_98 -> V_94 ) ) )
goto V_91;
} else {
if ( F_53 ( V_8 -> V_41 , V_101 ,
F_54 ( V_70 -> V_94 ) ) )
goto V_91;
if ( V_41 -> V_99 && V_41 -> V_99 -> V_103 &&
F_53 ( V_8 -> V_41 , V_102 ,
F_54 ( V_41 -> V_99 -> V_103 -> V_94 ) ) )
goto V_91;
}
#endif
}
if ( V_41 -> V_104 &&
F_53 ( V_8 -> V_41 , V_105 , F_54 ( V_41 -> V_104 ) ) )
goto V_91;
if ( V_69 && V_41 -> V_98 &&
V_41 -> V_106 != V_41 -> V_107 ) {
struct V_108 V_109 ;
int V_110 = F_56 ( V_41 , V_109 . V_111 ) ;
if ( V_110 > 0 ) {
V_109 . V_112 = F_50 ( V_110 ) ;
if ( F_51 ( V_8 -> V_41 , V_113 , sizeof( V_109 ) , & V_109 ) )
goto V_91;
}
}
if ( V_69 && F_57 ( V_41 ) ) {
if ( F_58 ( V_8 -> V_41 , V_114 , F_50 ( V_41 -> V_98 -> type ) ) ||
F_58 ( V_8 -> V_41 , V_115 ,
F_50 ( V_41 -> V_98 -> V_116 ) ) )
goto V_91;
V_80 = F_59 ( V_41 ) ;
if ( V_41 -> V_98 -> type == V_117 )
V_80 -= V_118 ;
if ( V_80 >= V_41 -> V_5 &&
F_51 ( V_8 -> V_41 , V_119 ,
V_41 -> V_98 -> V_116 , V_80 ) )
goto V_91;
}
if ( V_41 -> V_120 . V_121 ) {
struct V_122 V_123 ;
struct V_124 V_125 = F_60 ( V_41 -> V_120 ) ;
V_123 . V_126 = F_61 ( V_125 . V_127 ) ;
V_123 . V_128 = F_61 ( V_125 . V_129 ) ;
if ( F_51 ( V_8 -> V_41 , V_130 , sizeof( V_123 ) , & V_123 ) )
goto V_91;
}
V_79 = V_41 -> V_79 ;
if ( V_79 && V_79 -> V_131 != V_132 ) {
F_62 ( & V_79 -> V_133 ) ;
if ( V_79 -> V_134 && V_79 -> V_134 -> V_135 ) {
struct V_135 * V_135 = V_79 -> V_134 -> V_135 ;
const struct V_136 * V_136 = V_135 -> V_137 ;
struct V_15 * V_16 = V_8 -> V_28 ;
T_5 V_138 = F_54 ( F_63 ( V_16 , V_136 -> V_139 ) ) ;
T_5 V_140 = F_54 ( F_64 ( V_16 , V_136 -> V_141 ) ) ;
F_65 ( & V_79 -> V_133 ) ;
if ( F_53 ( V_8 -> V_41 , V_142 , V_138 ) ||
F_53 ( V_8 -> V_41 , V_143 , V_140 ) )
goto V_91;
} else
F_65 ( & V_79 -> V_133 ) ;
}
if ( ( V_8 -> V_51 & V_144 ) &&
F_53 ( V_8 -> V_41 , V_145 , F_54 ( V_8 -> V_146 ++ ) ) )
goto V_91;
if ( ( V_8 -> V_51 & V_147 ) &&
F_53 ( V_8 -> V_41 , V_148 ,
F_54 ( F_66 ( & V_149 ) ) ) )
goto V_91;
if ( V_65 ) {
struct V_150 * V_151 ;
int V_152 = F_67 ( V_65 ) ;
if ( F_68 ( V_8 -> V_41 ) < F_69 ( V_65 ) ) {
F_70 ( V_153 L_2 ) ;
return - 1 ;
}
V_151 = (struct V_150 * ) F_71 ( V_8 -> V_41 , F_69 ( V_65 ) ) ;
V_151 -> V_154 = V_155 ;
V_151 -> V_156 = V_152 ;
if ( F_72 ( V_41 , 0 , F_73 ( V_151 ) , V_65 ) )
F_74 () ;
}
V_58 -> V_157 = V_8 -> V_41 -> V_77 - V_76 ;
return 0 ;
V_91:
F_75 ( V_158 L_3 ) ;
return - 1 ;
}
void
F_76 ( T_1 V_66 ,
unsigned int V_67 ,
const struct V_52 * V_41 ,
const struct V_68 * V_159 ,
const struct V_68 * V_61 ,
const struct V_160 * V_161 ,
const char * V_71 )
{
unsigned int V_152 , V_65 ;
struct V_3 * V_8 ;
const struct V_160 * V_162 ;
unsigned int V_30 ;
unsigned int V_72 ;
if ( V_161 && V_161 -> type == V_163 )
V_162 = V_161 ;
else
V_162 = & V_164 ;
V_8 = F_6 ( V_162 -> V_165 . V_166 . V_167 ) ;
if ( ! V_8 )
return;
V_72 = 0 ;
if ( V_71 )
V_72 = strlen ( V_71 ) + 1 ;
V_152 = F_77 ( sizeof( struct V_60 ) )
+ F_69 ( sizeof( struct V_73 ) )
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
#ifdef F_52
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
#endif
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( V_72 )
+ F_69 ( sizeof( struct V_108 ) )
+ F_69 ( sizeof( struct V_122 ) ) ;
if ( V_159 && F_57 ( V_41 ) ) {
V_152 += F_69 ( V_41 -> V_98 -> V_116 )
+ F_69 ( sizeof( T_2 ) )
+ F_69 ( sizeof( T_2 ) ) ;
}
F_18 ( & V_8 -> V_25 ) ;
if ( V_8 -> V_51 & V_144 )
V_152 += F_69 ( sizeof( T_3 ) ) ;
if ( V_8 -> V_51 & V_147 )
V_152 += F_69 ( sizeof( T_3 ) ) ;
V_30 = V_8 -> V_30 ;
if ( V_162 -> V_165 . V_166 . V_30 )
if ( V_30 > V_162 -> V_165 . V_166 . V_30 )
V_30 = V_162 -> V_165 . V_166 . V_30 ;
switch ( V_8 -> V_36 ) {
case V_46 :
case V_45 :
V_65 = 0 ;
break;
case V_37 :
if ( V_8 -> V_38 == 0
|| V_8 -> V_38 > V_41 -> V_110 )
V_65 = V_41 -> V_110 ;
else
V_65 = V_8 -> V_38 ;
V_152 += F_69 ( V_65 ) ;
break;
case V_40 :
default:
goto V_168;
}
if ( V_8 -> V_41 &&
V_152 > F_68 ( V_8 -> V_41 ) - sizeof( struct V_60 ) ) {
F_31 ( V_8 ) ;
}
if ( ! V_8 -> V_41 ) {
V_8 -> V_41 = F_40 ( V_8 -> V_34 , V_152 ) ;
if ( ! V_8 -> V_41 )
goto V_169;
}
V_8 -> V_56 ++ ;
F_48 ( V_8 , V_41 , V_65 , V_66 ,
V_67 , V_159 , V_61 , V_71 , V_72 ) ;
if ( V_8 -> V_56 >= V_30 )
F_31 ( V_8 ) ;
else if ( ! F_78 ( & V_8 -> V_26 ) ) {
F_4 ( V_8 ) ;
V_8 -> V_26 . V_170 = V_171 + ( V_8 -> V_32 * V_172 / 100 ) ;
F_79 ( & V_8 -> V_26 ) ;
}
V_168:
F_26 ( & V_8 -> V_25 ) ;
F_14 ( V_8 ) ;
return;
V_169:
goto V_168;
}
static int
F_80 ( struct V_173 * V_174 ,
unsigned long V_175 , void * V_176 )
{
struct V_177 * V_55 = V_176 ;
if ( V_175 == V_178 && V_55 -> V_88 == V_179 ) {
int V_180 ;
F_18 ( & V_18 ) ;
for ( V_180 = 0 ; V_180 < V_2 ; V_180 ++ ) {
struct V_6 * V_181 , * V_182 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_180 ] ;
F_81 (inst, tmp, t2, head, hlist) {
if ( ( F_82 ( V_55 -> V_183 , & V_62 ) ) &&
( V_55 -> V_14 == V_8 -> V_29 ) )
F_28 ( V_8 ) ;
}
}
F_26 ( & V_18 ) ;
}
return V_184 ;
}
static int
F_83 ( struct V_78 * V_185 , struct V_52 * V_41 ,
const struct V_57 * V_58 ,
const struct V_150 * const V_186 [] )
{
return - V_187 ;
}
static int
F_84 ( struct V_78 * V_185 , struct V_52 * V_41 ,
const struct V_57 * V_58 ,
const struct V_150 * const V_188 [] )
{
struct V_60 * V_75 = F_49 ( V_58 ) ;
T_2 V_1 = F_85 ( V_75 -> V_86 ) ;
struct V_3 * V_8 ;
struct V_189 * V_190 = NULL ;
int V_191 = 0 ;
if ( V_188 [ V_192 ] ) {
T_1 V_66 = V_75 -> V_83 ;
V_190 = F_73 ( V_188 [ V_192 ] ) ;
switch ( V_190 -> V_193 ) {
case V_194 :
return F_86 ( V_66 , & V_195 ) ;
case V_196 :
F_87 ( V_66 ) ;
return 0 ;
}
}
V_8 = F_6 ( V_1 ) ;
if ( V_8 && V_8 -> V_29 != F_88 ( V_41 ) . V_14 ) {
V_191 = - V_197 ;
goto V_198;
}
if ( V_190 != NULL ) {
switch ( V_190 -> V_193 ) {
case V_199 :
if ( V_8 ) {
V_191 = - V_200 ;
goto V_198;
}
V_8 = F_17 ( V_1 ,
F_88 ( V_41 ) . V_14 ,
F_89 ( F_88 ( V_41 ) . V_201 ) ) ;
if ( F_90 ( V_8 ) ) {
V_191 = F_91 ( V_8 ) ;
goto V_61;
}
break;
case V_202 :
if ( ! V_8 ) {
V_191 = - V_203 ;
goto V_61;
}
F_33 ( V_8 ) ;
goto V_198;
default:
V_191 = - V_187 ;
break;
}
}
if ( V_188 [ V_204 ] ) {
struct V_205 * V_206 ;
V_206 = F_73 ( V_188 [ V_204 ] ) ;
if ( ! V_8 ) {
V_191 = - V_203 ;
goto V_61;
}
F_34 ( V_8 , V_206 -> V_36 ,
F_92 ( V_206 -> V_38 ) ) ;
}
if ( V_188 [ V_207 ] ) {
T_5 V_49 = F_93 ( V_188 [ V_207 ] ) ;
if ( ! V_8 ) {
V_191 = - V_203 ;
goto V_61;
}
F_37 ( V_8 , F_92 ( V_49 ) ) ;
}
if ( V_188 [ V_208 ] ) {
T_5 V_34 = F_93 ( V_188 [ V_208 ] ) ;
if ( ! V_8 ) {
V_191 = - V_203 ;
goto V_61;
}
F_36 ( V_8 , F_92 ( V_34 ) ) ;
}
if ( V_188 [ V_209 ] ) {
T_5 V_50 = F_93 ( V_188 [ V_209 ] ) ;
if ( ! V_8 ) {
V_191 = - V_203 ;
goto V_61;
}
F_38 ( V_8 , F_92 ( V_50 ) ) ;
}
if ( V_188 [ V_210 ] ) {
T_6 V_51 = F_94 ( V_188 [ V_210 ] ) ;
if ( ! V_8 ) {
V_191 = - V_203 ;
goto V_61;
}
F_39 ( V_8 , F_85 ( V_51 ) ) ;
}
V_198:
F_14 ( V_8 ) ;
V_61:
return V_191 ;
}
static struct V_6 * F_95 ( struct V_211 * V_212 )
{
if ( ! V_212 )
return NULL ;
for ( V_212 -> V_213 = 0 ; V_212 -> V_213 < V_2 ; V_212 -> V_213 ++ ) {
if ( ! F_96 ( & V_9 [ V_212 -> V_213 ] ) )
return F_97 ( F_98 ( & V_9 [ V_212 -> V_213 ] ) ) ;
}
return NULL ;
}
static struct V_6 * F_99 ( struct V_211 * V_212 , struct V_6 * V_214 )
{
V_214 = F_97 ( F_100 ( V_214 ) ) ;
while ( ! V_214 ) {
if ( ++ V_212 -> V_213 >= V_2 )
return NULL ;
V_214 = F_97 ( F_98 ( & V_9 [ V_212 -> V_213 ] ) ) ;
}
return V_214 ;
}
static struct V_6 * F_101 ( struct V_211 * V_212 , T_7 V_7 )
{
struct V_6 * V_5 ;
V_5 = F_95 ( V_212 ) ;
if ( V_5 )
while ( V_7 && ( V_5 = F_99 ( V_212 , V_5 ) ) )
V_7 -- ;
return V_7 ? NULL : V_5 ;
}
static void * F_102 ( struct V_215 * V_146 , T_7 * V_7 )
__acquires( T_8 )
{
F_7 () ;
return F_101 ( V_146 -> V_216 , * V_7 ) ;
}
static void * F_103 ( struct V_215 * V_217 , void * V_218 , T_7 * V_7 )
{
( * V_7 ) ++ ;
return F_99 ( V_217 -> V_216 , V_218 ) ;
}
static void F_104 ( struct V_215 * V_217 , void * V_218 )
__releases( T_8 )
{
F_9 () ;
}
static int F_105 ( struct V_215 * V_217 , void * V_218 )
{
const struct V_3 * V_8 = V_218 ;
return F_106 ( V_217 , L_4 ,
V_8 -> V_1 ,
V_8 -> V_29 , V_8 -> V_56 ,
V_8 -> V_36 , V_8 -> V_38 ,
V_8 -> V_32 , F_107 ( & V_8 -> V_10 ) ) ;
}
static int F_108 ( struct V_219 * V_219 , struct V_135 * V_135 )
{
return F_109 ( V_135 , & V_220 ,
sizeof( struct V_211 ) ) ;
}
static int T_9 F_110 ( void )
{
int V_180 , V_44 = - V_22 ;
for ( V_180 = 0 ; V_180 < V_2 ; V_180 ++ )
F_111 ( & V_9 [ V_180 ] ) ;
F_112 ( & V_221 , sizeof( V_221 ) ) ;
F_113 ( & V_222 ) ;
V_44 = F_114 ( & V_223 ) ;
if ( V_44 < 0 ) {
F_70 ( V_158 L_5 ) ;
goto V_224;
}
V_44 = F_115 ( V_225 , & V_195 ) ;
if ( V_44 < 0 ) {
F_70 ( V_158 L_6 ) ;
goto V_226;
}
#ifdef F_116
if ( ! F_117 ( L_7 , 0440 ,
V_227 , & V_228 ) ) {
V_44 = - V_22 ;
goto V_229;
}
#endif
return V_44 ;
#ifdef F_116
V_229:
F_118 ( & V_195 ) ;
#endif
V_226:
F_119 ( & V_223 ) ;
V_224:
F_120 ( & V_222 ) ;
return V_44 ;
}
static void T_10 F_121 ( void )
{
F_118 ( & V_195 ) ;
#ifdef F_116
F_122 ( L_7 , V_227 ) ;
#endif
F_119 ( & V_223 ) ;
F_120 ( & V_222 ) ;
}
