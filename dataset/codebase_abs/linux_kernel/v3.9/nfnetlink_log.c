static inline T_1 F_1 ( T_2 V_1 )
{
return ( ( V_1 & 0xff ) % V_2 ) ;
}
static struct V_3 *
F_2 ( T_2 V_1 )
{
struct V_4 * V_5 ;
struct V_3 * V_6 ;
V_5 = & V_7 [ F_1 ( V_1 ) ] ;
F_3 (inst, head, hlist) {
if ( V_6 -> V_1 == V_1 )
return V_6 ;
}
return NULL ;
}
static inline void
F_4 ( struct V_3 * V_6 )
{
F_5 ( & V_6 -> V_8 ) ;
}
static struct V_3 *
F_6 ( T_2 V_1 )
{
struct V_3 * V_6 ;
F_7 () ;
V_6 = F_2 ( V_1 ) ;
if ( V_6 && ! F_8 ( & V_6 -> V_8 ) )
V_6 = NULL ;
F_9 () ;
return V_6 ;
}
static void F_10 ( struct V_9 * V_5 )
{
F_11 ( F_12 ( V_5 , struct V_3 , V_10 ) ) ;
F_13 ( V_11 ) ;
}
static void
F_14 ( struct V_3 * V_6 )
{
if ( V_6 && F_15 ( & V_6 -> V_8 ) )
F_16 ( & V_6 -> V_10 , F_10 ) ;
}
static struct V_3 *
F_17 ( T_2 V_1 , int V_12 , struct V_13 * V_14 )
{
struct V_3 * V_6 ;
int V_15 ;
F_18 ( & V_16 ) ;
if ( F_2 ( V_1 ) ) {
V_15 = - V_17 ;
goto V_18;
}
V_6 = F_19 ( sizeof( * V_6 ) , V_19 ) ;
if ( ! V_6 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( ! F_20 ( V_11 ) ) {
F_11 ( V_6 ) ;
V_15 = - V_21 ;
goto V_18;
}
F_21 ( & V_6 -> V_22 ) ;
F_22 ( & V_6 -> V_23 ) ;
F_23 ( & V_6 -> V_8 , 2 ) ;
F_24 ( & V_6 -> V_24 , V_25 , ( unsigned long ) V_6 ) ;
V_6 -> V_26 = V_14 ;
V_6 -> V_27 = V_12 ;
V_6 -> V_1 = V_1 ;
V_6 -> V_28 = V_29 ;
V_6 -> V_30 = V_31 ;
V_6 -> V_32 = V_33 ;
V_6 -> V_34 = V_35 ;
V_6 -> V_36 = V_37 ;
F_25 ( & V_6 -> V_22 ,
& V_7 [ F_1 ( V_1 ) ] ) ;
F_26 ( & V_16 ) ;
return V_6 ;
V_18:
F_26 ( & V_16 ) ;
return F_27 ( V_15 ) ;
}
static void
F_28 ( struct V_3 * V_6 )
{
F_29 ( & V_6 -> V_22 ) ;
F_30 ( & V_6 -> V_23 ) ;
V_6 -> V_34 = V_38 ;
if ( V_6 -> V_39 )
F_31 ( V_6 ) ;
F_32 ( & V_6 -> V_23 ) ;
F_14 ( V_6 ) ;
}
static inline void
F_33 ( struct V_3 * V_6 )
{
F_18 ( & V_16 ) ;
F_28 ( V_6 ) ;
F_26 ( & V_16 ) ;
}
static int
F_34 ( struct V_3 * V_6 , T_1 V_40 ,
unsigned int V_41 )
{
int V_42 = 0 ;
F_18 ( & V_6 -> V_23 ) ;
switch ( V_40 ) {
case V_43 :
case V_44 :
V_6 -> V_34 = V_40 ;
V_6 -> V_36 = 0 ;
break;
case V_35 :
V_6 -> V_34 = V_40 ;
V_6 -> V_36 = F_35 (unsigned int,
range, NFULNL_COPY_RANGE_MAX) ;
break;
default:
V_42 = - V_45 ;
break;
}
F_26 ( & V_6 -> V_23 ) ;
return V_42 ;
}
static int
F_36 ( struct V_3 * V_6 , T_3 V_32 )
{
int V_42 ;
F_18 ( & V_6 -> V_23 ) ;
if ( V_32 < V_33 )
V_42 = - V_46 ;
else if ( V_32 > 131072 )
V_42 = - V_46 ;
else {
V_6 -> V_32 = V_32 ;
V_42 = 0 ;
}
F_26 ( & V_6 -> V_23 ) ;
return V_42 ;
}
static int
F_37 ( struct V_3 * V_6 , T_3 V_47 )
{
F_18 ( & V_6 -> V_23 ) ;
V_6 -> V_30 = V_47 ;
F_26 ( & V_6 -> V_23 ) ;
return 0 ;
}
static int
F_38 ( struct V_3 * V_6 , T_3 V_48 )
{
F_18 ( & V_6 -> V_23 ) ;
V_6 -> V_28 = V_48 ;
F_26 ( & V_6 -> V_23 ) ;
return 0 ;
}
static int
F_39 ( struct V_3 * V_6 , T_2 V_49 )
{
F_18 ( & V_6 -> V_23 ) ;
V_6 -> V_49 = V_49 ;
F_26 ( & V_6 -> V_23 ) ;
return 0 ;
}
static struct V_50 *
F_40 ( unsigned int V_51 , unsigned int V_52 )
{
struct V_50 * V_39 ;
unsigned int V_53 ;
V_53 = F_41 ( V_51 , V_52 ) ;
V_39 = F_42 ( V_53 , V_19 ) ;
if ( ! V_39 ) {
if ( V_53 > V_52 ) {
V_39 = F_42 ( V_52 , V_19 ) ;
if ( ! V_39 )
F_43 ( L_1 ,
V_52 ) ;
}
}
return V_39 ;
}
static int
F_44 ( struct V_3 * V_6 )
{
int V_42 = - 1 ;
if ( V_6 -> V_54 > 1 ) {
struct V_55 * V_56 = F_45 ( V_6 -> V_39 , 0 , 0 ,
V_57 ,
sizeof( struct V_58 ) ,
0 ) ;
if ( ! V_56 )
goto V_59;
}
V_42 = F_46 ( V_6 -> V_39 , & V_60 , V_6 -> V_27 ,
V_61 ) ;
V_6 -> V_54 = 0 ;
V_6 -> V_39 = NULL ;
V_59:
return V_42 ;
}
static void
F_31 ( struct V_3 * V_6 )
{
if ( F_47 ( & V_6 -> V_24 ) )
F_14 ( V_6 ) ;
if ( V_6 -> V_39 )
F_44 ( V_6 ) ;
}
static void
V_25 ( unsigned long V_62 )
{
struct V_3 * V_6 = (struct V_3 * ) V_62 ;
F_18 ( & V_6 -> V_23 ) ;
if ( V_6 -> V_39 )
F_44 ( V_6 ) ;
F_26 ( & V_6 -> V_23 ) ;
F_14 ( V_6 ) ;
}
static inline int
F_48 ( struct V_3 * V_6 ,
const struct V_50 * V_39 ,
unsigned int V_63 ,
T_1 V_64 ,
unsigned int V_65 ,
const struct V_66 * V_67 ,
const struct V_66 * V_68 ,
const char * V_69 , unsigned int V_70 )
{
struct V_71 V_72 ;
struct V_55 * V_56 ;
struct V_58 * V_73 ;
T_4 V_74 = V_6 -> V_39 -> V_75 ;
struct V_76 * V_77 ;
const unsigned char * V_78 ;
V_56 = F_45 ( V_6 -> V_39 , 0 , 0 ,
V_79 << 8 | V_80 ,
sizeof( struct V_58 ) , 0 ) ;
if ( ! V_56 )
return - 1 ;
V_73 = F_49 ( V_56 ) ;
V_73 -> V_81 = V_64 ;
V_73 -> V_82 = V_83 ;
V_73 -> V_84 = F_50 ( V_6 -> V_1 ) ;
V_72 . V_85 = V_39 -> V_86 ;
V_72 . V_87 = V_65 ;
if ( F_51 ( V_6 -> V_39 , V_88 , sizeof( V_72 ) , & V_72 ) )
goto V_89;
if ( V_69 &&
F_51 ( V_6 -> V_39 , V_90 , V_70 , V_69 ) )
goto V_89;
if ( V_67 ) {
#ifndef F_52
if ( F_53 ( V_6 -> V_39 , V_91 ,
F_54 ( V_67 -> V_92 ) ) )
goto V_89;
#else
if ( V_64 == V_93 ) {
if ( F_53 ( V_6 -> V_39 , V_94 ,
F_54 ( V_67 -> V_92 ) ) ||
F_53 ( V_6 -> V_39 , V_91 ,
F_54 ( F_55 ( V_67 ) -> V_95 -> V_96 -> V_92 ) ) )
goto V_89;
} else {
if ( F_53 ( V_6 -> V_39 , V_91 ,
F_54 ( V_67 -> V_92 ) ) )
goto V_89;
if ( V_39 -> V_97 && V_39 -> V_97 -> V_98 &&
F_53 ( V_6 -> V_39 , V_94 ,
F_54 ( V_39 -> V_97 -> V_98 -> V_92 ) ) )
goto V_89;
}
#endif
}
if ( V_68 ) {
#ifndef F_52
if ( F_53 ( V_6 -> V_39 , V_99 ,
F_54 ( V_68 -> V_92 ) ) )
goto V_89;
#else
if ( V_64 == V_93 ) {
if ( F_53 ( V_6 -> V_39 , V_100 ,
F_54 ( V_68 -> V_92 ) ) ||
F_53 ( V_6 -> V_39 , V_99 ,
F_54 ( F_55 ( V_68 ) -> V_95 -> V_96 -> V_92 ) ) )
goto V_89;
} else {
if ( F_53 ( V_6 -> V_39 , V_99 ,
F_54 ( V_68 -> V_92 ) ) )
goto V_89;
if ( V_39 -> V_97 && V_39 -> V_97 -> V_101 &&
F_53 ( V_6 -> V_39 , V_100 ,
F_54 ( V_39 -> V_97 -> V_101 -> V_92 ) ) )
goto V_89;
}
#endif
}
if ( V_39 -> V_102 &&
F_53 ( V_6 -> V_39 , V_103 , F_54 ( V_39 -> V_102 ) ) )
goto V_89;
if ( V_67 && V_39 -> V_96 &&
V_39 -> V_104 != V_39 -> V_105 ) {
struct V_106 V_107 ;
int V_108 = F_56 ( V_39 , V_107 . V_109 ) ;
if ( V_108 > 0 ) {
V_107 . V_110 = F_50 ( V_108 ) ;
if ( F_51 ( V_6 -> V_39 , V_111 , sizeof( V_107 ) , & V_107 ) )
goto V_89;
}
}
if ( V_67 && F_57 ( V_39 ) ) {
if ( F_58 ( V_6 -> V_39 , V_112 , F_50 ( V_39 -> V_96 -> type ) ) ||
F_58 ( V_6 -> V_39 , V_113 ,
F_50 ( V_39 -> V_96 -> V_114 ) ) )
goto V_89;
V_78 = F_59 ( V_39 ) ;
if ( V_39 -> V_96 -> type == V_115 )
V_78 -= V_116 ;
if ( V_78 >= V_39 -> V_5 &&
F_51 ( V_6 -> V_39 , V_117 ,
V_39 -> V_96 -> V_114 , V_78 ) )
goto V_89;
}
if ( V_39 -> V_118 . V_119 ) {
struct V_120 V_121 ;
struct V_122 V_123 = F_60 ( V_39 -> V_118 ) ;
V_121 . V_124 = F_61 ( V_123 . V_125 ) ;
V_121 . V_126 = F_61 ( V_123 . V_127 ) ;
if ( F_51 ( V_6 -> V_39 , V_128 , sizeof( V_121 ) , & V_121 ) )
goto V_89;
}
V_77 = V_39 -> V_77 ;
if ( V_77 && V_77 -> V_129 != V_130 ) {
F_62 ( & V_77 -> V_131 ) ;
if ( V_77 -> V_132 && V_77 -> V_132 -> V_133 ) {
struct V_133 * V_133 = V_77 -> V_132 -> V_133 ;
const struct V_134 * V_134 = V_133 -> V_135 ;
struct V_13 * V_14 = V_6 -> V_26 ;
T_5 V_136 = F_54 ( F_63 ( V_14 , V_134 -> V_137 ) ) ;
T_5 V_138 = F_54 ( F_64 ( V_14 , V_134 -> V_139 ) ) ;
F_65 ( & V_77 -> V_131 ) ;
if ( F_53 ( V_6 -> V_39 , V_140 , V_136 ) ||
F_53 ( V_6 -> V_39 , V_141 , V_138 ) )
goto V_89;
} else
F_65 ( & V_77 -> V_131 ) ;
}
if ( ( V_6 -> V_49 & V_142 ) &&
F_53 ( V_6 -> V_39 , V_143 , F_54 ( V_6 -> V_144 ++ ) ) )
goto V_89;
if ( ( V_6 -> V_49 & V_145 ) &&
F_53 ( V_6 -> V_39 , V_146 ,
F_54 ( F_66 ( & V_147 ) ) ) )
goto V_89;
if ( V_63 ) {
struct V_148 * V_149 ;
int V_150 = F_67 ( V_63 ) ;
if ( F_68 ( V_6 -> V_39 ) < F_69 ( V_63 ) ) {
F_70 ( V_151 L_2 ) ;
return - 1 ;
}
V_149 = (struct V_148 * ) F_71 ( V_6 -> V_39 , F_69 ( V_63 ) ) ;
V_149 -> V_152 = V_153 ;
V_149 -> V_154 = V_150 ;
if ( F_72 ( V_39 , 0 , F_73 ( V_149 ) , V_63 ) )
F_74 () ;
}
V_56 -> V_155 = V_6 -> V_39 -> V_75 - V_74 ;
return 0 ;
V_89:
F_75 ( V_156 L_3 ) ;
return - 1 ;
}
void
F_76 ( T_1 V_64 ,
unsigned int V_65 ,
const struct V_50 * V_39 ,
const struct V_66 * V_157 ,
const struct V_66 * V_59 ,
const struct V_158 * V_159 ,
const char * V_69 )
{
unsigned int V_150 , V_63 ;
struct V_3 * V_6 ;
const struct V_158 * V_160 ;
unsigned int V_28 ;
unsigned int V_70 ;
if ( V_159 && V_159 -> type == V_161 )
V_160 = V_159 ;
else
V_160 = & V_162 ;
V_6 = F_6 ( V_160 -> V_163 . V_164 . V_165 ) ;
if ( ! V_6 )
return;
V_70 = 0 ;
if ( V_69 )
V_70 = strlen ( V_69 ) + 1 ;
V_150 = F_77 ( sizeof( struct V_58 ) )
+ F_69 ( sizeof( struct V_71 ) )
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
#ifdef F_52
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
#endif
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( sizeof( T_3 ) )
+ F_69 ( V_70 )
+ F_69 ( sizeof( struct V_106 ) )
+ F_69 ( sizeof( struct V_120 ) ) ;
if ( V_157 && F_57 ( V_39 ) ) {
V_150 += F_69 ( V_39 -> V_96 -> V_114 )
+ F_69 ( sizeof( T_2 ) )
+ F_69 ( sizeof( T_2 ) ) ;
}
F_18 ( & V_6 -> V_23 ) ;
if ( V_6 -> V_49 & V_142 )
V_150 += F_69 ( sizeof( T_3 ) ) ;
if ( V_6 -> V_49 & V_145 )
V_150 += F_69 ( sizeof( T_3 ) ) ;
V_28 = V_6 -> V_28 ;
if ( V_160 -> V_163 . V_164 . V_28 )
if ( V_28 > V_160 -> V_163 . V_164 . V_28 )
V_28 = V_160 -> V_163 . V_164 . V_28 ;
switch ( V_6 -> V_34 ) {
case V_44 :
case V_43 :
V_63 = 0 ;
break;
case V_35 :
if ( V_6 -> V_36 == 0
|| V_6 -> V_36 > V_39 -> V_108 )
V_63 = V_39 -> V_108 ;
else
V_63 = V_6 -> V_36 ;
V_150 += F_69 ( V_63 ) ;
break;
case V_38 :
default:
goto V_166;
}
if ( V_6 -> V_39 &&
V_150 > F_68 ( V_6 -> V_39 ) - sizeof( struct V_58 ) ) {
F_31 ( V_6 ) ;
}
if ( ! V_6 -> V_39 ) {
V_6 -> V_39 = F_40 ( V_6 -> V_32 , V_150 ) ;
if ( ! V_6 -> V_39 )
goto V_167;
}
V_6 -> V_54 ++ ;
F_48 ( V_6 , V_39 , V_63 , V_64 ,
V_65 , V_157 , V_59 , V_69 , V_70 ) ;
if ( V_6 -> V_54 >= V_28 )
F_31 ( V_6 ) ;
else if ( ! F_78 ( & V_6 -> V_24 ) ) {
F_4 ( V_6 ) ;
V_6 -> V_24 . V_168 = V_169 + ( V_6 -> V_30 * V_170 / 100 ) ;
F_79 ( & V_6 -> V_24 ) ;
}
V_166:
F_26 ( & V_6 -> V_23 ) ;
F_14 ( V_6 ) ;
return;
V_167:
goto V_166;
}
static int
F_80 ( struct V_171 * V_172 ,
unsigned long V_173 , void * V_174 )
{
struct V_175 * V_53 = V_174 ;
if ( V_173 == V_176 && V_53 -> V_86 == V_177 ) {
int V_178 ;
F_18 ( & V_16 ) ;
for ( V_178 = 0 ; V_178 < V_2 ; V_178 ++ ) {
struct V_179 * V_180 ;
struct V_3 * V_6 ;
struct V_4 * V_5 = & V_7 [ V_178 ] ;
F_81 (inst, t2, head, hlist) {
if ( ( F_82 ( V_53 -> V_181 , & V_60 ) ) &&
( V_53 -> V_12 == V_6 -> V_27 ) )
F_28 ( V_6 ) ;
}
}
F_26 ( & V_16 ) ;
}
return V_182 ;
}
static int
F_83 ( struct V_76 * V_183 , struct V_50 * V_39 ,
const struct V_55 * V_56 ,
const struct V_148 * const V_184 [] )
{
return - V_185 ;
}
static int
F_84 ( struct V_76 * V_183 , struct V_50 * V_39 ,
const struct V_55 * V_56 ,
const struct V_148 * const V_186 [] )
{
struct V_58 * V_73 = F_49 ( V_56 ) ;
T_2 V_1 = F_85 ( V_73 -> V_84 ) ;
struct V_3 * V_6 ;
struct V_187 * V_188 = NULL ;
int V_189 = 0 ;
if ( V_186 [ V_190 ] ) {
T_1 V_64 = V_73 -> V_81 ;
V_188 = F_73 ( V_186 [ V_190 ] ) ;
switch ( V_188 -> V_191 ) {
case V_192 :
return F_86 ( V_64 , & V_193 ) ;
case V_194 :
F_87 ( V_64 ) ;
return 0 ;
}
}
V_6 = F_6 ( V_1 ) ;
if ( V_6 && V_6 -> V_27 != F_88 ( V_39 ) . V_12 ) {
V_189 = - V_195 ;
goto V_196;
}
if ( V_188 != NULL ) {
switch ( V_188 -> V_191 ) {
case V_197 :
if ( V_6 ) {
V_189 = - V_198 ;
goto V_196;
}
V_6 = F_17 ( V_1 ,
F_88 ( V_39 ) . V_12 ,
F_89 ( F_88 ( V_39 ) . V_199 ) ) ;
if ( F_90 ( V_6 ) ) {
V_189 = F_91 ( V_6 ) ;
goto V_59;
}
break;
case V_200 :
if ( ! V_6 ) {
V_189 = - V_201 ;
goto V_59;
}
F_33 ( V_6 ) ;
goto V_196;
default:
V_189 = - V_185 ;
break;
}
}
if ( V_186 [ V_202 ] ) {
struct V_203 * V_204 ;
V_204 = F_73 ( V_186 [ V_202 ] ) ;
if ( ! V_6 ) {
V_189 = - V_201 ;
goto V_59;
}
F_34 ( V_6 , V_204 -> V_34 ,
F_92 ( V_204 -> V_36 ) ) ;
}
if ( V_186 [ V_205 ] ) {
T_5 V_47 = F_93 ( V_186 [ V_205 ] ) ;
if ( ! V_6 ) {
V_189 = - V_201 ;
goto V_59;
}
F_37 ( V_6 , F_92 ( V_47 ) ) ;
}
if ( V_186 [ V_206 ] ) {
T_5 V_32 = F_93 ( V_186 [ V_206 ] ) ;
if ( ! V_6 ) {
V_189 = - V_201 ;
goto V_59;
}
F_36 ( V_6 , F_92 ( V_32 ) ) ;
}
if ( V_186 [ V_207 ] ) {
T_5 V_48 = F_93 ( V_186 [ V_207 ] ) ;
if ( ! V_6 ) {
V_189 = - V_201 ;
goto V_59;
}
F_38 ( V_6 , F_92 ( V_48 ) ) ;
}
if ( V_186 [ V_208 ] ) {
T_6 V_49 = F_94 ( V_186 [ V_208 ] ) ;
if ( ! V_6 ) {
V_189 = - V_201 ;
goto V_59;
}
F_39 ( V_6 , F_85 ( V_49 ) ) ;
}
V_196:
F_14 ( V_6 ) ;
V_59:
return V_189 ;
}
static struct V_179 * F_95 ( struct V_209 * V_210 )
{
if ( ! V_210 )
return NULL ;
for ( V_210 -> V_211 = 0 ; V_210 -> V_211 < V_2 ; V_210 -> V_211 ++ ) {
if ( ! F_96 ( & V_7 [ V_210 -> V_211 ] ) )
return F_97 ( F_98 ( & V_7 [ V_210 -> V_211 ] ) ) ;
}
return NULL ;
}
static struct V_179 * F_99 ( struct V_209 * V_210 , struct V_179 * V_212 )
{
V_212 = F_97 ( F_100 ( V_212 ) ) ;
while ( ! V_212 ) {
if ( ++ V_210 -> V_211 >= V_2 )
return NULL ;
V_212 = F_97 ( F_98 ( & V_7 [ V_210 -> V_211 ] ) ) ;
}
return V_212 ;
}
static struct V_179 * F_101 ( struct V_209 * V_210 , T_7 V_213 )
{
struct V_179 * V_5 ;
V_5 = F_95 ( V_210 ) ;
if ( V_5 )
while ( V_213 && ( V_5 = F_99 ( V_210 , V_5 ) ) )
V_213 -- ;
return V_213 ? NULL : V_5 ;
}
static void * F_102 ( struct V_214 * V_144 , T_7 * V_213 )
__acquires( T_8 )
{
F_7 () ;
return F_101 ( V_144 -> V_215 , * V_213 ) ;
}
static void * F_103 ( struct V_214 * V_216 , void * V_217 , T_7 * V_213 )
{
( * V_213 ) ++ ;
return F_99 ( V_216 -> V_215 , V_217 ) ;
}
static void F_104 ( struct V_214 * V_216 , void * V_217 )
__releases( T_8 )
{
F_9 () ;
}
static int F_105 ( struct V_214 * V_216 , void * V_217 )
{
const struct V_3 * V_6 = V_217 ;
return F_106 ( V_216 , L_4 ,
V_6 -> V_1 ,
V_6 -> V_27 , V_6 -> V_54 ,
V_6 -> V_34 , V_6 -> V_36 ,
V_6 -> V_30 , F_107 ( & V_6 -> V_8 ) ) ;
}
static int F_108 ( struct V_218 * V_218 , struct V_133 * V_133 )
{
return F_109 ( V_133 , & V_219 ,
sizeof( struct V_209 ) ) ;
}
static int T_9 F_110 ( void )
{
int V_178 , V_42 = - V_20 ;
for ( V_178 = 0 ; V_178 < V_2 ; V_178 ++ )
F_111 ( & V_7 [ V_178 ] ) ;
F_112 ( & V_220 , sizeof( V_220 ) ) ;
F_113 ( & V_221 ) ;
V_42 = F_114 ( & V_222 ) ;
if ( V_42 < 0 ) {
F_70 ( V_156 L_5 ) ;
goto V_223;
}
V_42 = F_115 ( V_224 , & V_193 ) ;
if ( V_42 < 0 ) {
F_70 ( V_156 L_6 ) ;
goto V_225;
}
#ifdef F_116
if ( ! F_117 ( L_7 , 0440 ,
V_226 , & V_227 ) ) {
V_42 = - V_20 ;
goto V_228;
}
#endif
return V_42 ;
#ifdef F_116
V_228:
F_118 ( & V_193 ) ;
#endif
V_225:
F_119 ( & V_222 ) ;
V_223:
F_120 ( & V_221 ) ;
return V_42 ;
}
static void T_10 F_121 ( void )
{
F_118 ( & V_193 ) ;
#ifdef F_116
F_122 ( L_7 , V_226 ) ;
#endif
F_119 ( & V_222 ) ;
F_120 ( & V_221 ) ;
}
