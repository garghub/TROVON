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
F_17 ( T_2 V_1 , int V_14 )
{
struct V_3 * V_8 ;
int V_15 ;
F_18 ( & V_16 ) ;
if ( F_2 ( V_1 ) ) {
V_15 = - V_17 ;
goto V_18;
}
V_8 = F_19 ( sizeof( * V_8 ) , V_19 ) ;
if ( ! V_8 ) {
V_15 = - V_20 ;
goto V_18;
}
if ( ! F_20 ( V_13 ) ) {
F_11 ( V_8 ) ;
V_15 = - V_21 ;
goto V_18;
}
F_21 ( & V_8 -> V_22 ) ;
F_22 ( & V_8 -> V_23 ) ;
F_23 ( & V_8 -> V_10 , 2 ) ;
F_24 ( & V_8 -> V_24 , V_25 , ( unsigned long ) V_8 ) ;
V_8 -> V_26 = V_14 ;
V_8 -> V_1 = V_1 ;
V_8 -> V_27 = V_28 ;
V_8 -> V_29 = V_30 ;
V_8 -> V_31 = V_32 ;
V_8 -> V_33 = V_34 ;
V_8 -> V_35 = V_36 ;
F_25 ( & V_8 -> V_22 ,
& V_9 [ F_1 ( V_1 ) ] ) ;
F_26 ( & V_16 ) ;
return V_8 ;
V_18:
F_26 ( & V_16 ) ;
return F_27 ( V_15 ) ;
}
static void
F_28 ( struct V_3 * V_8 )
{
F_29 ( & V_8 -> V_22 ) ;
F_30 ( & V_8 -> V_23 ) ;
V_8 -> V_33 = V_37 ;
if ( V_8 -> V_38 )
F_31 ( V_8 ) ;
F_32 ( & V_8 -> V_23 ) ;
F_14 ( V_8 ) ;
}
static inline void
F_33 ( struct V_3 * V_8 )
{
F_18 ( & V_16 ) ;
F_28 ( V_8 ) ;
F_26 ( & V_16 ) ;
}
static int
F_34 ( struct V_3 * V_8 , T_1 V_39 ,
unsigned int V_40 )
{
int V_41 = 0 ;
F_18 ( & V_8 -> V_23 ) ;
switch ( V_39 ) {
case V_42 :
case V_43 :
V_8 -> V_33 = V_39 ;
V_8 -> V_35 = 0 ;
break;
case V_34 :
V_8 -> V_33 = V_39 ;
V_8 -> V_35 = F_35 (unsigned int,
range, NFULNL_COPY_RANGE_MAX) ;
break;
default:
V_41 = - V_44 ;
break;
}
F_26 ( & V_8 -> V_23 ) ;
return V_41 ;
}
static int
F_36 ( struct V_3 * V_8 , T_3 V_31 )
{
int V_41 ;
F_18 ( & V_8 -> V_23 ) ;
if ( V_31 < V_32 )
V_41 = - V_45 ;
else if ( V_31 > 131072 )
V_41 = - V_45 ;
else {
V_8 -> V_31 = V_31 ;
V_41 = 0 ;
}
F_26 ( & V_8 -> V_23 ) ;
return V_41 ;
}
static int
F_37 ( struct V_3 * V_8 , T_3 V_46 )
{
F_18 ( & V_8 -> V_23 ) ;
V_8 -> V_29 = V_46 ;
F_26 ( & V_8 -> V_23 ) ;
return 0 ;
}
static int
F_38 ( struct V_3 * V_8 , T_3 V_47 )
{
F_18 ( & V_8 -> V_23 ) ;
V_8 -> V_27 = V_47 ;
F_26 ( & V_8 -> V_23 ) ;
return 0 ;
}
static int
F_39 ( struct V_3 * V_8 , T_2 V_48 )
{
F_18 ( & V_8 -> V_23 ) ;
V_8 -> V_48 = V_48 ;
F_26 ( & V_8 -> V_23 ) ;
return 0 ;
}
static struct V_49 *
F_40 ( unsigned int V_50 , unsigned int V_51 )
{
struct V_49 * V_38 ;
unsigned int V_52 ;
V_52 = F_41 ( V_50 , V_51 ) ;
V_38 = F_42 ( V_52 , V_19 ) ;
if ( ! V_38 ) {
F_43 ( L_1 ,
V_50 ) ;
if ( V_52 > V_51 ) {
V_38 = F_42 ( V_51 , V_19 ) ;
if ( ! V_38 )
F_44 ( L_2
L_3 , V_51 ) ;
}
}
return V_38 ;
}
static int
F_45 ( struct V_3 * V_8 )
{
int V_41 = - 1 ;
if ( V_8 -> V_53 > 1 )
F_46 ( V_8 -> V_38 , 0 , 0 ,
V_54 ,
sizeof( struct V_55 ) ) ;
V_41 = F_47 ( V_8 -> V_38 , & V_56 , V_8 -> V_26 ,
V_57 ) ;
V_8 -> V_53 = 0 ;
V_8 -> V_38 = NULL ;
V_58:
return V_41 ;
}
static void
F_31 ( struct V_3 * V_8 )
{
if ( F_48 ( & V_8 -> V_24 ) )
F_14 ( V_8 ) ;
if ( V_8 -> V_38 )
F_45 ( V_8 ) ;
}
static void
V_25 ( unsigned long V_59 )
{
struct V_3 * V_8 = (struct V_3 * ) V_59 ;
F_18 ( & V_8 -> V_23 ) ;
if ( V_8 -> V_38 )
F_45 ( V_8 ) ;
F_26 ( & V_8 -> V_23 ) ;
F_14 ( V_8 ) ;
}
static inline int
F_49 ( struct V_3 * V_8 ,
const struct V_49 * V_38 ,
unsigned int V_60 ,
T_1 V_61 ,
unsigned int V_62 ,
const struct V_63 * V_64 ,
const struct V_63 * V_65 ,
const char * V_66 , unsigned int V_67 )
{
struct V_68 V_69 ;
struct V_70 * V_71 ;
struct V_55 * V_72 ;
T_4 V_73 = V_8 -> V_38 -> V_74 ;
V_71 = F_46 ( V_8 -> V_38 , 0 , 0 ,
V_75 << 8 | V_76 ,
sizeof( struct V_55 ) ) ;
V_72 = F_50 ( V_71 ) ;
V_72 -> V_77 = V_61 ;
V_72 -> V_78 = V_79 ;
V_72 -> V_80 = F_51 ( V_8 -> V_1 ) ;
V_69 . V_81 = V_38 -> V_82 ;
V_69 . V_83 = V_62 ;
F_52 ( V_8 -> V_38 , V_84 , sizeof( V_69 ) , & V_69 ) ;
if ( V_66 )
F_52 ( V_8 -> V_38 , V_85 , V_67 , V_66 ) ;
if ( V_64 ) {
#ifndef F_53
F_54 ( V_8 -> V_38 , V_86 ,
F_55 ( V_64 -> V_87 ) ) ;
#else
if ( V_61 == V_88 ) {
F_54 ( V_8 -> V_38 , V_89 ,
F_55 ( V_64 -> V_87 ) ) ;
F_54 ( V_8 -> V_38 , V_86 ,
F_55 ( F_56 ( V_64 ) -> V_90 -> V_91 -> V_87 ) ) ;
} else {
F_54 ( V_8 -> V_38 , V_86 ,
F_55 ( V_64 -> V_87 ) ) ;
if ( V_38 -> V_92 && V_38 -> V_92 -> V_93 )
F_54 ( V_8 -> V_38 , V_89 ,
F_55 ( V_38 -> V_92 -> V_93 -> V_87 ) ) ;
}
#endif
}
if ( V_65 ) {
#ifndef F_53
F_54 ( V_8 -> V_38 , V_94 ,
F_55 ( V_65 -> V_87 ) ) ;
#else
if ( V_61 == V_88 ) {
F_54 ( V_8 -> V_38 , V_95 ,
F_55 ( V_65 -> V_87 ) ) ;
F_54 ( V_8 -> V_38 , V_94 ,
F_55 ( F_56 ( V_65 ) -> V_90 -> V_91 -> V_87 ) ) ;
} else {
F_54 ( V_8 -> V_38 , V_94 ,
F_55 ( V_65 -> V_87 ) ) ;
if ( V_38 -> V_92 && V_38 -> V_92 -> V_96 )
F_54 ( V_8 -> V_38 , V_95 ,
F_55 ( V_38 -> V_92 -> V_96 -> V_87 ) ) ;
}
#endif
}
if ( V_38 -> V_97 )
F_54 ( V_8 -> V_38 , V_98 , F_55 ( V_38 -> V_97 ) ) ;
if ( V_64 && V_38 -> V_91 &&
V_38 -> V_99 != V_38 -> V_100 ) {
struct V_101 V_102 ;
int V_103 = F_57 ( V_38 , V_102 . V_104 ) ;
if ( V_103 > 0 ) {
V_102 . V_105 = F_51 ( V_103 ) ;
F_52 ( V_8 -> V_38 , V_106 , sizeof( V_102 ) , & V_102 ) ;
}
}
if ( V_64 && F_58 ( V_38 ) ) {
F_59 ( V_8 -> V_38 , V_107 , F_51 ( V_38 -> V_91 -> type ) ) ;
F_59 ( V_8 -> V_38 , V_108 ,
F_51 ( V_38 -> V_91 -> V_109 ) ) ;
F_52 ( V_8 -> V_38 , V_110 , V_38 -> V_91 -> V_109 ,
F_60 ( V_38 ) ) ;
}
if ( V_38 -> V_111 . V_112 ) {
struct V_113 V_114 ;
struct V_115 V_116 = F_61 ( V_38 -> V_111 ) ;
V_114 . V_117 = F_62 ( V_116 . V_118 ) ;
V_114 . V_119 = F_62 ( V_116 . V_120 ) ;
F_52 ( V_8 -> V_38 , V_121 , sizeof( V_114 ) , & V_114 ) ;
}
if ( V_38 -> V_122 ) {
F_63 ( & V_38 -> V_122 -> V_123 ) ;
if ( V_38 -> V_122 -> V_124 && V_38 -> V_122 -> V_124 -> V_125 ) {
struct V_125 * V_125 = V_38 -> V_122 -> V_124 -> V_125 ;
T_5 V_126 = F_55 ( V_125 -> V_127 -> V_128 ) ;
T_5 V_129 = F_55 ( V_125 -> V_127 -> V_130 ) ;
F_64 ( & V_38 -> V_122 -> V_123 ) ;
F_54 ( V_8 -> V_38 , V_131 , V_126 ) ;
F_54 ( V_8 -> V_38 , V_132 , V_129 ) ;
} else
F_64 ( & V_38 -> V_122 -> V_123 ) ;
}
if ( V_8 -> V_48 & V_133 )
F_54 ( V_8 -> V_38 , V_134 , F_55 ( V_8 -> V_135 ++ ) ) ;
if ( V_8 -> V_48 & V_136 )
F_54 ( V_8 -> V_38 , V_137 ,
F_55 ( F_65 ( & V_138 ) ) ) ;
if ( V_60 ) {
struct V_139 * V_140 ;
int V_141 = F_66 ( V_60 ) ;
if ( F_67 ( V_8 -> V_38 ) < F_68 ( V_60 ) ) {
F_69 ( V_142 L_4 ) ;
goto V_58;
}
V_140 = (struct V_139 * ) F_70 ( V_8 -> V_38 , F_68 ( V_60 ) ) ;
V_140 -> V_143 = V_144 ;
V_140 -> V_145 = V_141 ;
if ( F_71 ( V_38 , 0 , F_72 ( V_140 ) , V_60 ) )
F_73 () ;
}
V_71 -> V_146 = V_8 -> V_38 -> V_74 - V_73 ;
return 0 ;
V_58:
V_147:
F_74 ( V_148 L_5 ) ;
return - 1 ;
}
void
F_75 ( T_1 V_61 ,
unsigned int V_62 ,
const struct V_49 * V_38 ,
const struct V_63 * V_149 ,
const struct V_63 * V_150 ,
const struct V_151 * V_152 ,
const char * V_66 )
{
unsigned int V_141 , V_60 ;
struct V_3 * V_8 ;
const struct V_151 * V_153 ;
unsigned int V_27 ;
unsigned int V_67 ;
if ( V_152 && V_152 -> type == V_154 )
V_153 = V_152 ;
else
V_153 = & V_155 ;
V_8 = F_6 ( V_153 -> V_156 . V_157 . V_158 ) ;
if ( ! V_8 )
return;
V_67 = 0 ;
if ( V_66 )
V_67 = strlen ( V_66 ) + 1 ;
V_141 = F_76 ( sizeof( struct V_55 ) )
+ F_68 ( sizeof( struct V_68 ) )
+ F_68 ( sizeof( T_3 ) )
+ F_68 ( sizeof( T_3 ) )
#ifdef F_53
+ F_68 ( sizeof( T_3 ) )
+ F_68 ( sizeof( T_3 ) )
#endif
+ F_68 ( sizeof( T_3 ) )
+ F_68 ( sizeof( T_3 ) )
+ F_68 ( sizeof( T_3 ) )
+ F_68 ( V_67 )
+ F_68 ( sizeof( struct V_101 ) )
+ F_68 ( sizeof( struct V_113 ) ) ;
if ( V_149 && F_58 ( V_38 ) ) {
V_141 += F_68 ( V_38 -> V_91 -> V_109 )
+ F_68 ( sizeof( T_2 ) )
+ F_68 ( sizeof( T_2 ) ) ;
}
F_18 ( & V_8 -> V_23 ) ;
if ( V_8 -> V_48 & V_133 )
V_141 += F_68 ( sizeof( T_3 ) ) ;
if ( V_8 -> V_48 & V_136 )
V_141 += F_68 ( sizeof( T_3 ) ) ;
V_27 = V_8 -> V_27 ;
if ( V_153 -> V_156 . V_157 . V_27 )
if ( V_27 > V_153 -> V_156 . V_157 . V_27 )
V_27 = V_153 -> V_156 . V_157 . V_27 ;
switch ( V_8 -> V_33 ) {
case V_43 :
case V_42 :
V_60 = 0 ;
break;
case V_34 :
if ( V_8 -> V_35 == 0
|| V_8 -> V_35 > V_38 -> V_103 )
V_60 = V_38 -> V_103 ;
else
V_60 = V_8 -> V_35 ;
V_141 += F_68 ( V_60 ) ;
break;
case V_37 :
default:
goto V_159;
}
if ( V_8 -> V_38 &&
V_141 > F_67 ( V_8 -> V_38 ) - sizeof( struct V_55 ) ) {
F_31 ( V_8 ) ;
}
if ( ! V_8 -> V_38 ) {
V_8 -> V_38 = F_40 ( V_8 -> V_31 , V_141 ) ;
if ( ! V_8 -> V_38 )
goto V_160;
}
V_8 -> V_53 ++ ;
F_49 ( V_8 , V_38 , V_60 , V_61 ,
V_62 , V_149 , V_150 , V_66 , V_67 ) ;
if ( V_8 -> V_53 >= V_27 )
F_31 ( V_8 ) ;
else if ( ! F_77 ( & V_8 -> V_24 ) ) {
F_4 ( V_8 ) ;
V_8 -> V_24 . V_161 = V_162 + ( V_8 -> V_29 * V_163 / 100 ) ;
F_78 ( & V_8 -> V_24 ) ;
}
V_159:
F_26 ( & V_8 -> V_23 ) ;
F_14 ( V_8 ) ;
return;
V_160:
goto V_159;
}
static int
F_79 ( struct V_164 * V_165 ,
unsigned long V_166 , void * V_167 )
{
struct V_168 * V_52 = V_167 ;
if ( V_166 == V_169 && V_52 -> V_82 == V_170 ) {
int V_171 ;
F_18 ( & V_16 ) ;
for ( V_171 = 0 ; V_171 < V_2 ; V_171 ++ ) {
struct V_6 * V_172 , * V_173 ;
struct V_3 * V_8 ;
struct V_4 * V_5 = & V_9 [ V_171 ] ;
F_80 (inst, tmp, t2, head, hlist) {
if ( ( F_81 ( V_52 -> V_174 , & V_56 ) ) &&
( V_52 -> V_14 == V_8 -> V_26 ) )
F_28 ( V_8 ) ;
}
}
F_26 ( & V_16 ) ;
}
return V_175 ;
}
static int
F_82 ( struct V_176 * V_177 , struct V_49 * V_38 ,
const struct V_70 * V_71 ,
const struct V_139 * const V_178 [] )
{
return - V_179 ;
}
static int
F_83 ( struct V_176 * V_177 , struct V_49 * V_38 ,
const struct V_70 * V_71 ,
const struct V_139 * const V_180 [] )
{
struct V_55 * V_72 = F_50 ( V_71 ) ;
T_2 V_1 = F_84 ( V_72 -> V_80 ) ;
struct V_3 * V_8 ;
struct V_181 * V_182 = NULL ;
int V_183 = 0 ;
if ( V_180 [ V_184 ] ) {
T_1 V_61 = V_72 -> V_77 ;
V_182 = F_72 ( V_180 [ V_184 ] ) ;
switch ( V_182 -> V_185 ) {
case V_186 :
return F_85 ( V_61 , & V_187 ) ;
case V_188 :
F_86 ( V_61 ) ;
return 0 ;
}
}
V_8 = F_6 ( V_1 ) ;
if ( V_8 && V_8 -> V_26 != F_87 ( V_38 ) . V_14 ) {
V_183 = - V_189 ;
goto V_190;
}
if ( V_182 != NULL ) {
switch ( V_182 -> V_185 ) {
case V_191 :
if ( V_8 ) {
V_183 = - V_192 ;
goto V_190;
}
V_8 = F_17 ( V_1 ,
F_87 ( V_38 ) . V_14 ) ;
if ( F_88 ( V_8 ) ) {
V_183 = F_89 ( V_8 ) ;
goto V_150;
}
break;
case V_193 :
if ( ! V_8 ) {
V_183 = - V_194 ;
goto V_150;
}
F_33 ( V_8 ) ;
goto V_190;
default:
V_183 = - V_179 ;
break;
}
}
if ( V_180 [ V_195 ] ) {
struct V_196 * V_197 ;
V_197 = F_72 ( V_180 [ V_195 ] ) ;
if ( ! V_8 ) {
V_183 = - V_194 ;
goto V_150;
}
F_34 ( V_8 , V_197 -> V_33 ,
F_90 ( V_197 -> V_35 ) ) ;
}
if ( V_180 [ V_198 ] ) {
T_5 V_46 = F_91 ( V_180 [ V_198 ] ) ;
if ( ! V_8 ) {
V_183 = - V_194 ;
goto V_150;
}
F_37 ( V_8 , F_90 ( V_46 ) ) ;
}
if ( V_180 [ V_199 ] ) {
T_5 V_31 = F_91 ( V_180 [ V_199 ] ) ;
if ( ! V_8 ) {
V_183 = - V_194 ;
goto V_150;
}
F_36 ( V_8 , F_90 ( V_31 ) ) ;
}
if ( V_180 [ V_200 ] ) {
T_5 V_47 = F_91 ( V_180 [ V_200 ] ) ;
if ( ! V_8 ) {
V_183 = - V_194 ;
goto V_150;
}
F_38 ( V_8 , F_90 ( V_47 ) ) ;
}
if ( V_180 [ V_201 ] ) {
T_6 V_48 = F_92 ( V_180 [ V_201 ] ) ;
if ( ! V_8 ) {
V_183 = - V_194 ;
goto V_150;
}
F_39 ( V_8 , F_84 ( V_48 ) ) ;
}
V_190:
F_14 ( V_8 ) ;
V_150:
return V_183 ;
}
static struct V_6 * F_93 ( struct V_202 * V_203 )
{
if ( ! V_203 )
return NULL ;
for ( V_203 -> V_204 = 0 ; V_203 -> V_204 < V_2 ; V_203 -> V_204 ++ ) {
if ( ! F_94 ( & V_9 [ V_203 -> V_204 ] ) )
return F_95 ( F_96 ( & V_9 [ V_203 -> V_204 ] ) ) ;
}
return NULL ;
}
static struct V_6 * F_97 ( struct V_202 * V_203 , struct V_6 * V_205 )
{
V_205 = F_95 ( F_98 ( V_205 ) ) ;
while ( ! V_205 ) {
if ( ++ V_203 -> V_204 >= V_2 )
return NULL ;
V_205 = F_95 ( F_96 ( & V_9 [ V_203 -> V_204 ] ) ) ;
}
return V_205 ;
}
static struct V_6 * F_99 ( struct V_202 * V_203 , T_7 V_7 )
{
struct V_6 * V_5 ;
V_5 = F_93 ( V_203 ) ;
if ( V_5 )
while ( V_7 && ( V_5 = F_97 ( V_203 , V_5 ) ) )
V_7 -- ;
return V_7 ? NULL : V_5 ;
}
static void * F_100 ( struct V_206 * V_135 , T_7 * V_7 )
__acquires( T_8 )
{
F_7 () ;
return F_99 ( V_135 -> V_207 , * V_7 ) ;
}
static void * F_101 ( struct V_206 * V_208 , void * V_209 , T_7 * V_7 )
{
( * V_7 ) ++ ;
return F_97 ( V_208 -> V_207 , V_209 ) ;
}
static void F_102 ( struct V_206 * V_208 , void * V_209 )
__releases( T_8 )
{
F_9 () ;
}
static int F_103 ( struct V_206 * V_208 , void * V_209 )
{
const struct V_3 * V_8 = V_209 ;
return F_104 ( V_208 , L_6 ,
V_8 -> V_1 ,
V_8 -> V_26 , V_8 -> V_53 ,
V_8 -> V_33 , V_8 -> V_35 ,
V_8 -> V_29 , F_105 ( & V_8 -> V_10 ) ) ;
}
static int F_106 ( struct V_210 * V_210 , struct V_125 * V_125 )
{
return F_107 ( V_125 , & V_211 ,
sizeof( struct V_202 ) ) ;
}
static int T_9 F_108 ( void )
{
int V_171 , V_41 = - V_20 ;
for ( V_171 = 0 ; V_171 < V_2 ; V_171 ++ )
F_109 ( & V_9 [ V_171 ] ) ;
F_110 ( & V_212 , sizeof( V_212 ) ) ;
F_111 ( & V_213 ) ;
V_41 = F_112 ( & V_214 ) ;
if ( V_41 < 0 ) {
F_69 ( V_148 L_7 ) ;
goto V_215;
}
V_41 = F_113 ( V_216 , & V_187 ) ;
if ( V_41 < 0 ) {
F_69 ( V_148 L_8 ) ;
goto V_217;
}
#ifdef F_114
if ( ! F_115 ( L_9 , 0440 ,
V_218 , & V_219 ) )
goto V_220;
#endif
return V_41 ;
#ifdef F_114
V_220:
F_116 ( & V_187 ) ;
#endif
V_217:
F_117 ( & V_214 ) ;
V_215:
F_118 ( & V_213 ) ;
return V_41 ;
}
static void T_10 F_119 ( void )
{
F_116 ( & V_187 ) ;
#ifdef F_114
F_120 ( L_9 , V_218 ) ;
#endif
F_117 ( & V_214 ) ;
F_118 ( & V_213 ) ;
}
