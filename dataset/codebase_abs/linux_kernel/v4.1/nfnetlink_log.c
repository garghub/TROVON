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
static int
F_41 ( struct V_6 * V_9 , T_4 V_50 )
{
F_21 ( & V_9 -> V_26 ) ;
V_9 -> V_33 = V_50 ;
F_30 ( & V_9 -> V_26 ) ;
return 0 ;
}
static int
F_42 ( struct V_6 * V_9 , T_4 V_51 )
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
F_44 ( struct V_2 * V_2 , T_3 V_30 , unsigned int V_54 ,
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
const char * V_72 , unsigned int V_73 )
{
struct V_74 V_75 ;
struct V_58 * V_59 ;
struct V_61 * V_76 ;
T_5 V_77 = V_9 -> V_42 -> V_78 ;
struct V_79 * V_80 ;
const unsigned char * V_81 ;
V_59 = F_48 ( V_9 -> V_42 , 0 , 0 ,
V_82 << 8 | V_83 ,
sizeof( struct V_61 ) , 0 ) ;
if ( ! V_59 )
return - 1 ;
V_76 = F_55 ( V_59 ) ;
V_76 -> V_84 = V_67 ;
V_76 -> V_85 = V_86 ;
V_76 -> V_87 = F_56 ( V_9 -> V_4 ) ;
memset ( & V_75 , 0 , sizeof( V_75 ) ) ;
V_75 . V_88 = V_42 -> V_89 ;
V_75 . V_90 = V_68 ;
if ( F_57 ( V_9 -> V_42 , V_91 , sizeof( V_75 ) , & V_75 ) )
goto V_92;
if ( V_72 &&
F_57 ( V_9 -> V_42 , V_93 , V_73 , V_72 ) )
goto V_92;
if ( V_70 ) {
#if ! F_58 ( V_94 )
if ( F_59 ( V_9 -> V_42 , V_95 ,
F_60 ( V_70 -> V_96 ) ) )
goto V_92;
#else
if ( V_67 == V_97 ) {
if ( F_59 ( V_9 -> V_42 , V_98 ,
F_60 ( V_70 -> V_96 ) ) ||
F_59 ( V_9 -> V_42 , V_95 ,
F_60 ( F_61 ( V_70 ) -> V_99 -> V_100 -> V_96 ) ) )
goto V_92;
} else {
struct V_69 * V_101 ;
if ( F_59 ( V_9 -> V_42 , V_95 ,
F_60 ( V_70 -> V_96 ) ) )
goto V_92;
V_101 = F_62 ( V_42 ) ;
if ( V_101 &&
F_59 ( V_9 -> V_42 , V_98 ,
F_60 ( V_101 -> V_96 ) ) )
goto V_92;
}
#endif
}
if ( V_71 ) {
#if ! F_58 ( V_94 )
if ( F_59 ( V_9 -> V_42 , V_102 ,
F_60 ( V_71 -> V_96 ) ) )
goto V_92;
#else
if ( V_67 == V_97 ) {
if ( F_59 ( V_9 -> V_42 , V_103 ,
F_60 ( V_71 -> V_96 ) ) ||
F_59 ( V_9 -> V_42 , V_102 ,
F_60 ( F_61 ( V_71 ) -> V_99 -> V_100 -> V_96 ) ) )
goto V_92;
} else {
struct V_69 * V_104 ;
if ( F_59 ( V_9 -> V_42 , V_102 ,
F_60 ( V_71 -> V_96 ) ) )
goto V_92;
V_104 = F_63 ( V_42 ) ;
if ( V_104 &&
F_59 ( V_9 -> V_42 , V_103 ,
F_60 ( V_104 -> V_96 ) ) )
goto V_92;
}
#endif
}
if ( V_42 -> V_105 &&
F_59 ( V_9 -> V_42 , V_106 , F_60 ( V_42 -> V_105 ) ) )
goto V_92;
if ( V_70 && V_42 -> V_100 &&
V_42 -> V_107 != V_42 -> V_108 ) {
struct V_109 V_110 ;
int V_62 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_62 = F_64 ( V_42 , V_110 . V_111 ) ;
if ( V_62 > 0 ) {
V_110 . V_112 = F_56 ( V_62 ) ;
if ( F_57 ( V_9 -> V_42 , V_113 , sizeof( V_110 ) , & V_110 ) )
goto V_92;
}
}
if ( V_70 && F_65 ( V_42 ) ) {
if ( F_66 ( V_9 -> V_42 , V_114 , F_56 ( V_42 -> V_100 -> type ) ) ||
F_66 ( V_9 -> V_42 , V_115 ,
F_56 ( V_42 -> V_100 -> V_116 ) ) )
goto V_92;
V_81 = F_67 ( V_42 ) ;
if ( V_42 -> V_100 -> type == V_117 )
V_81 -= V_118 ;
if ( V_81 >= V_42 -> V_8 &&
F_57 ( V_9 -> V_42 , V_119 ,
V_42 -> V_100 -> V_116 , V_81 ) )
goto V_92;
}
if ( V_42 -> V_120 . V_121 ) {
struct V_122 V_123 ;
struct V_124 V_125 = F_68 ( V_42 -> V_120 ) ;
V_123 . V_126 = F_69 ( V_125 . V_127 ) ;
V_123 . V_128 = F_69 ( V_125 . V_129 ) ;
if ( F_57 ( V_9 -> V_42 , V_130 , sizeof( V_123 ) , & V_123 ) )
goto V_92;
}
V_80 = V_42 -> V_80 ;
if ( V_80 && F_70 ( V_80 ) ) {
F_71 ( & V_80 -> V_131 ) ;
if ( V_80 -> V_132 && V_80 -> V_132 -> V_133 ) {
struct V_133 * V_133 = V_80 -> V_132 -> V_133 ;
const struct V_134 * V_134 = V_133 -> V_135 ;
struct V_16 * V_17 = V_9 -> V_29 ;
T_6 V_136 = F_60 ( F_72 ( V_17 , V_134 -> V_137 ) ) ;
T_6 V_138 = F_60 ( F_73 ( V_17 , V_134 -> V_139 ) ) ;
F_74 ( & V_80 -> V_131 ) ;
if ( F_59 ( V_9 -> V_42 , V_140 , V_136 ) ||
F_59 ( V_9 -> V_42 , V_141 , V_138 ) )
goto V_92;
} else
F_74 ( & V_80 -> V_131 ) ;
}
if ( ( V_9 -> V_52 & V_142 ) &&
F_59 ( V_9 -> V_42 , V_143 , F_60 ( V_9 -> V_144 ++ ) ) )
goto V_92;
if ( ( V_9 -> V_52 & V_145 ) &&
F_59 ( V_9 -> V_42 , V_146 ,
F_60 ( F_75 ( & log -> V_147 ) ) ) )
goto V_92;
if ( V_66 ) {
struct V_148 * V_149 ;
int V_150 = F_76 ( V_66 ) ;
if ( F_50 ( V_9 -> V_42 ) < F_77 ( V_66 ) )
goto V_92;
V_149 = (struct V_148 * ) F_78 ( V_9 -> V_42 , F_77 ( V_66 ) ) ;
V_149 -> V_151 = V_152 ;
V_149 -> V_153 = V_150 ;
if ( F_79 ( V_42 , 0 , F_80 ( V_149 ) , V_66 ) )
F_81 () ;
}
V_59 -> V_154 = V_9 -> V_42 -> V_78 - V_77 ;
return 0 ;
V_92:
F_82 ( V_155 L_2 ) ;
return - 1 ;
}
void
F_83 ( struct V_2 * V_2 ,
T_1 V_67 ,
unsigned int V_68 ,
const struct V_53 * V_42 ,
const struct V_69 * V_156 ,
const struct V_69 * V_63 ,
const struct V_157 * V_158 ,
const char * V_72 )
{
unsigned int V_150 , V_66 ;
struct V_6 * V_9 ;
const struct V_157 * V_159 ;
unsigned int V_31 ;
unsigned int V_73 ;
struct V_1 * log = F_1 ( V_2 ) ;
if ( V_158 && V_158 -> type == V_160 )
V_159 = V_158 ;
else
V_159 = & V_161 ;
V_9 = F_8 ( log , V_159 -> V_162 . V_163 . V_164 ) ;
if ( ! V_9 )
return;
V_73 = 0 ;
if ( V_72 )
V_73 = strlen ( V_72 ) + 1 ;
V_150 = F_84 ( sizeof( struct V_61 ) )
+ F_77 ( sizeof( struct V_74 ) )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
#if F_58 ( V_94 )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
#endif
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( sizeof( T_4 ) )
+ F_77 ( V_73 )
+ F_77 ( sizeof( struct V_109 ) )
+ F_77 ( sizeof( struct V_122 ) )
+ F_77 ( sizeof( struct V_61 ) ) ;
if ( V_156 && F_65 ( V_42 ) ) {
V_150 += F_77 ( V_42 -> V_100 -> V_116 )
+ F_77 ( sizeof( T_2 ) )
+ F_77 ( sizeof( T_2 ) ) ;
}
F_21 ( & V_9 -> V_26 ) ;
if ( V_9 -> V_52 & V_142 )
V_150 += F_77 ( sizeof( T_4 ) ) ;
if ( V_9 -> V_52 & V_145 )
V_150 += F_77 ( sizeof( T_4 ) ) ;
V_31 = V_9 -> V_31 ;
if ( V_159 -> V_162 . V_163 . V_31 )
if ( V_31 > V_159 -> V_162 . V_163 . V_31 )
V_31 = V_159 -> V_162 . V_163 . V_31 ;
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
V_150 += F_77 ( V_66 ) ;
break;
case V_41 :
default:
goto V_165;
}
if ( V_9 -> V_42 && V_150 > F_50 ( V_9 -> V_42 ) ) {
F_35 ( V_9 ) ;
}
if ( ! V_9 -> V_42 ) {
V_9 -> V_42 = F_44 ( V_2 , V_9 -> V_30 ,
V_9 -> V_35 , V_150 ) ;
if ( ! V_9 -> V_42 )
goto V_166;
}
V_9 -> V_57 ++ ;
F_54 ( log , V_9 , V_42 , V_66 , V_67 ,
V_68 , V_156 , V_63 , V_72 , V_73 ) ;
if ( V_9 -> V_57 >= V_31 )
F_35 ( V_9 ) ;
else if ( ! F_85 ( & V_9 -> V_27 ) ) {
F_6 ( V_9 ) ;
V_9 -> V_27 . V_167 = V_168 + ( V_9 -> V_33 * V_169 / 100 ) ;
F_86 ( & V_9 -> V_27 ) ;
}
V_165:
F_30 ( & V_9 -> V_26 ) ;
F_17 ( V_9 ) ;
return;
V_166:
goto V_165;
}
static int
F_87 ( struct V_170 * V_171 ,
unsigned long V_172 , void * V_173 )
{
struct V_174 * V_56 = V_173 ;
struct V_1 * log = F_1 ( V_56 -> V_2 ) ;
if ( V_172 == V_175 && V_56 -> V_89 == V_176 ) {
int V_177 ;
F_21 ( & log -> V_19 ) ;
for ( V_177 = 0 ; V_177 < V_5 ; V_177 ++ ) {
struct V_178 * V_179 ;
struct V_6 * V_9 ;
struct V_7 * V_8 = & log -> V_10 [ V_177 ] ;
F_88 (inst, t2, head, hlist) {
if ( V_56 -> V_15 == V_9 -> V_30 )
F_32 ( V_9 ) ;
}
}
F_30 ( & log -> V_19 ) ;
}
return V_180 ;
}
static int
F_89 ( struct V_79 * V_181 , struct V_53 * V_42 ,
const struct V_58 * V_59 ,
const struct V_148 * const V_182 [] )
{
return - V_183 ;
}
static int
F_90 ( struct V_79 * V_181 , struct V_53 * V_42 ,
const struct V_58 * V_59 ,
const struct V_148 * const V_184 [] )
{
struct V_61 * V_76 = F_55 ( V_59 ) ;
T_2 V_4 = F_91 ( V_76 -> V_87 ) ;
struct V_6 * V_9 ;
struct V_185 * V_186 = NULL ;
struct V_2 * V_2 = F_92 ( V_181 ) ;
struct V_1 * log = F_1 ( V_2 ) ;
int V_187 = 0 ;
if ( V_184 [ V_188 ] ) {
T_1 V_67 = V_76 -> V_84 ;
V_186 = F_80 ( V_184 [ V_188 ] ) ;
switch ( V_186 -> V_189 ) {
case V_190 :
return F_93 ( V_2 , V_67 , & V_191 ) ;
case V_192 :
F_94 ( V_2 , V_67 ) ;
return 0 ;
}
}
V_9 = F_8 ( log , V_4 ) ;
if ( V_9 && V_9 -> V_30 != F_95 ( V_42 ) . V_15 ) {
V_187 = - V_193 ;
goto V_194;
}
if ( V_186 != NULL ) {
switch ( V_186 -> V_189 ) {
case V_195 :
if ( V_9 ) {
V_187 = - V_196 ;
goto V_194;
}
V_9 = F_20 ( V_2 , V_4 ,
F_95 ( V_42 ) . V_15 ,
F_96 ( F_95 ( V_42 ) . V_80 ) ) ;
if ( F_97 ( V_9 ) ) {
V_187 = F_98 ( V_9 ) ;
goto V_63;
}
break;
case V_197 :
if ( ! V_9 ) {
V_187 = - V_198 ;
goto V_63;
}
F_37 ( log , V_9 ) ;
goto V_194;
default:
V_187 = - V_183 ;
break;
}
}
if ( V_184 [ V_199 ] ) {
struct V_200 * V_201 ;
V_201 = F_80 ( V_184 [ V_199 ] ) ;
if ( ! V_9 ) {
V_187 = - V_198 ;
goto V_63;
}
F_38 ( V_9 , V_201 -> V_37 ,
F_99 ( V_201 -> V_39 ) ) ;
}
if ( V_184 [ V_202 ] ) {
T_6 V_50 = F_100 ( V_184 [ V_202 ] ) ;
if ( ! V_9 ) {
V_187 = - V_198 ;
goto V_63;
}
F_41 ( V_9 , F_99 ( V_50 ) ) ;
}
if ( V_184 [ V_203 ] ) {
T_6 V_35 = F_100 ( V_184 [ V_203 ] ) ;
if ( ! V_9 ) {
V_187 = - V_198 ;
goto V_63;
}
F_40 ( V_9 , F_99 ( V_35 ) ) ;
}
if ( V_184 [ V_204 ] ) {
T_6 V_51 = F_100 ( V_184 [ V_204 ] ) ;
if ( ! V_9 ) {
V_187 = - V_198 ;
goto V_63;
}
F_42 ( V_9 , F_99 ( V_51 ) ) ;
}
if ( V_184 [ V_205 ] ) {
T_7 V_52 = F_101 ( V_184 [ V_205 ] ) ;
if ( ! V_9 ) {
V_187 = - V_198 ;
goto V_63;
}
F_43 ( V_9 , F_91 ( V_52 ) ) ;
}
V_194:
F_17 ( V_9 ) ;
V_63:
return V_187 ;
}
static struct V_178 * F_102 ( struct V_2 * V_2 , struct V_206 * V_207 )
{
struct V_1 * log ;
if ( ! V_207 )
return NULL ;
log = F_1 ( V_2 ) ;
for ( V_207 -> V_208 = 0 ; V_207 -> V_208 < V_5 ; V_207 -> V_208 ++ ) {
struct V_7 * V_8 = & log -> V_10 [ V_207 -> V_208 ] ;
if ( ! F_103 ( V_8 ) )
return F_104 ( F_105 ( V_8 ) ) ;
}
return NULL ;
}
static struct V_178 * F_106 ( struct V_2 * V_2 , struct V_206 * V_207 ,
struct V_178 * V_209 )
{
V_209 = F_104 ( F_107 ( V_209 ) ) ;
while ( ! V_209 ) {
struct V_1 * log ;
struct V_7 * V_8 ;
if ( ++ V_207 -> V_208 >= V_5 )
return NULL ;
log = F_1 ( V_2 ) ;
V_8 = & log -> V_10 [ V_207 -> V_208 ] ;
V_209 = F_104 ( F_105 ( V_8 ) ) ;
}
return V_209 ;
}
static struct V_178 * F_108 ( struct V_2 * V_2 , struct V_206 * V_207 ,
T_8 V_210 )
{
struct V_178 * V_8 ;
V_8 = F_102 ( V_2 , V_207 ) ;
if ( V_8 )
while ( V_210 && ( V_8 = F_106 ( V_2 , V_207 , V_8 ) ) )
V_210 -- ;
return V_210 ? NULL : V_8 ;
}
static void * F_109 ( struct V_211 * V_212 , T_8 * V_210 )
__acquires( T_9 )
{
F_9 () ;
return F_108 ( F_110 ( V_212 ) , V_212 -> V_213 , * V_210 ) ;
}
static void * F_111 ( struct V_211 * V_212 , void * V_214 , T_8 * V_210 )
{
( * V_210 ) ++ ;
return F_106 ( F_110 ( V_212 ) , V_212 -> V_213 , V_214 ) ;
}
static void F_112 ( struct V_211 * V_212 , void * V_214 )
__releases( T_9 )
{
F_11 () ;
}
static int F_113 ( struct V_211 * V_212 , void * V_214 )
{
const struct V_6 * V_9 = V_214 ;
F_114 ( V_212 , L_3 ,
V_9 -> V_4 ,
V_9 -> V_30 , V_9 -> V_57 ,
V_9 -> V_37 , V_9 -> V_39 ,
V_9 -> V_33 , F_115 ( & V_9 -> V_11 ) ) ;
return 0 ;
}
static int F_116 ( struct V_215 * V_215 , struct V_133 * V_133 )
{
return F_117 ( V_215 , V_133 , & V_216 ,
sizeof( struct V_206 ) ) ;
}
static int T_10 F_118 ( struct V_2 * V_2 )
{
unsigned int V_177 ;
struct V_1 * log = F_1 ( V_2 ) ;
for ( V_177 = 0 ; V_177 < V_5 ; V_177 ++ )
F_119 ( & log -> V_10 [ V_177 ] ) ;
F_25 ( & log -> V_19 ) ;
#ifdef F_120
if ( ! F_121 ( L_4 , 0440 ,
V_2 -> V_217 . V_218 , & V_219 ) )
return - V_23 ;
#endif
return 0 ;
}
static void T_11 F_122 ( struct V_2 * V_2 )
{
#ifdef F_120
F_123 ( L_4 , V_2 -> V_217 . V_218 ) ;
#endif
F_124 ( V_2 , & V_191 ) ;
}
static int T_12 F_125 ( void )
{
int V_45 ;
V_45 = F_126 ( & V_220 ) ;
if ( V_45 < 0 ) {
F_127 ( L_5 ) ;
goto V_63;
}
F_128 ( & V_221 ) ;
V_45 = F_129 ( & V_222 ) ;
if ( V_45 < 0 ) {
F_127 ( L_6 ) ;
goto V_223;
}
V_45 = F_130 ( V_224 , & V_191 ) ;
if ( V_45 < 0 ) {
F_127 ( L_7 ) ;
goto V_225;
}
return V_45 ;
V_225:
F_131 ( & V_222 ) ;
V_223:
F_132 ( & V_221 ) ;
F_133 ( & V_220 ) ;
V_63:
return V_45 ;
}
static void T_13 F_134 ( void )
{
F_135 ( & V_191 ) ;
F_131 ( & V_222 ) ;
F_132 ( & V_221 ) ;
F_133 ( & V_220 ) ;
}
