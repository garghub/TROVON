static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 )
{
T_1 V_3 = V_4 / 4 ;
T_2 V_5 ;
for ( V_5 = ( V_2 < 3 ) ? V_2 : 3 ; V_5 < 3 + V_1 ; V_5 ++ )
V_3 *= 2 ;
return V_3 ;
}
static int F_2 ( struct V_6 * V_7 ,
const struct V_8 * V_9 ,
T_3 V_10 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
struct V_16 * V_17 ;
const T_2 * V_18 ;
int V_5 , V_19 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_7 = V_7 ;
}
V_7 -> V_20 = V_9 ;
V_18 = V_12 -> V_21 -> V_22 ;
V_7 -> V_23 = V_12 -> V_21 -> V_3 -> V_24 ;
V_7 -> V_25 = V_12 -> V_21 -> V_3 -> V_26 ;
V_7 -> V_27 = V_28 ;
V_7 -> V_29 = F_6 () ;
V_7 -> V_30 |= ( V_31 | V_32 |
V_33 ) ;
V_7 -> V_30 |= V_34 | V_35 ;
V_7 -> V_36 |= V_37 ;
V_7 -> V_36 |= V_38 ;
V_7 -> V_39 |= V_40 ;
V_7 -> V_39 &= ~ V_41 ;
V_7 -> V_36 |= V_7 -> V_30 ;
V_7 -> V_42 = V_7 -> V_36 ;
memcpy ( V_7 -> V_43 , V_18 , V_7 -> V_44 ) ;
memcpy ( V_7 -> V_45 , V_18 , V_7 -> V_44 ) ;
V_7 -> V_46 = & V_47 ;
V_7 -> V_48 = V_12 -> V_49 ;
V_7 -> V_50 = F_7 ( V_10 ) ;
F_8 ( V_7 ) ;
V_19 = F_9 ( V_7 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_1 , V_19 ) ;
return V_19 ;
}
return 0 ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_51 * V_21 ;
struct V_11 * V_12 ;
int V_5 , V_19 , error ;
V_12 = F_3 ( V_7 ) ;
V_21 = V_12 -> V_21 ;
F_12 ( V_7 ) ;
F_13 ( 5000 , 10000 ) ;
V_19 = V_21 -> V_52 ( V_21 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_53 , V_7 , L_2 ,
V_19 ) ;
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_54 ) ; V_5 ++ ) {
error = F_16 ( V_21 -> V_54 [ V_5 ] ) ;
if ( error )
V_19 = error ;
}
if ( V_7 -> V_55 )
F_17 ( V_7 -> V_55 ) ;
V_7 -> V_55 = NULL ;
return V_19 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_16 * V_17 ;
const struct V_11 * V_12 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
F_20 ( V_12 , V_56 , V_7 , L_3 ,
F_21 ( V_57 - F_22 ( V_7 ) ) ) ;
V_17 -> V_58 . V_59 ++ ;
}
static void F_23 ( struct V_6 * V_7 ,
struct V_60 * V_61 )
{
int V_62 = sizeof( struct V_60 ) / sizeof( V_63 ) ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
V_63 * V_64 = ( V_63 * ) V_61 ;
V_63 * V_65 ;
int V_5 , V_66 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_65 = ( V_63 * ) & V_17 -> V_58 ;
for ( V_66 = 0 ; V_66 < V_62 ; V_66 ++ )
V_64 [ V_66 ] += V_65 [ V_66 ] ;
}
}
static int F_24 ( struct V_6 * V_7 , T_4 V_67 ,
T_4 V_68 , T_5 V_69 , struct V_70 * V_71 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
T_2 V_72 ;
int V_5 ;
if ( V_71 -> type != V_73 )
return - V_74 ;
V_71 -> V_75 -> V_76 = V_77 ;
V_72 = V_71 -> V_75 -> V_72 ;
if ( V_72 == V_12 -> V_72 )
return 0 ;
if ( ! V_72 ) {
F_25 ( V_7 ) ;
goto V_78;
}
if ( V_72 > V_79 ) {
F_26 ( V_7 , L_4 ,
V_79 ) ;
return - V_74 ;
}
F_27 ( V_7 , V_72 ) ;
for ( V_5 = 0 ; V_5 < V_72 ; V_5 ++ )
F_28 ( V_7 , V_5 , V_80 ,
V_5 * V_80 ) ;
V_78:
V_12 -> V_72 = V_72 ? : 1 ;
F_29 ( V_7 , V_12 -> V_72 * V_80 ) ;
return 0 ;
}
static struct V_51 * F_30 ( struct V_81 * V_82 )
{
struct V_81 * V_83 ;
struct V_84 * V_85 ;
struct V_13 * V_86 , * V_14 ;
struct V_87 * V_88 ;
struct V_51 * V_21 ;
V_86 = & V_82 -> V_14 ;
V_85 = V_86 -> V_89 ;
if ( ! V_85 )
return F_31 ( - V_90 ) ;
V_88 = V_85 -> V_88 ;
V_83 = F_32 ( V_88 ) ;
if ( ! V_83 ) {
F_10 ( V_86 , L_5 ,
V_88 -> V_91 ) ;
F_33 ( V_88 ) ;
return F_31 ( - V_74 ) ;
}
F_33 ( V_88 ) ;
V_14 = & V_83 -> V_14 ;
V_21 = F_34 ( V_14 ) ;
if ( ! V_21 ) {
F_10 ( V_86 , L_6 ,
F_35 ( V_14 ) ) ;
return F_31 ( - V_74 ) ;
}
return V_21 ;
}
static int F_36 ( struct V_6 * V_7 , void * V_22 )
{
const struct V_11 * V_12 ;
struct V_51 * V_21 ;
struct V_92 V_93 ;
int V_19 ;
V_12 = F_3 ( V_7 ) ;
memcpy ( V_93 . V_94 , V_7 -> V_45 , V_95 ) ;
V_19 = F_37 ( V_7 , V_22 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_96 , V_7 , L_7 , V_19 ) ;
return V_19 ;
}
V_21 = V_12 -> V_21 ;
V_19 = V_21 -> V_97 ( V_21 -> V_98 ,
( V_99 * ) V_7 -> V_45 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_96 , V_7 , L_8 ,
V_19 ) ;
F_37 ( V_7 , & V_93 ) ;
return V_19 ;
}
return 0 ;
}
static void F_38 ( struct V_6 * V_7 )
{
const struct V_11 * V_12 ;
int V_19 ;
V_12 = F_3 ( V_7 ) ;
if ( ! ! ( V_7 -> V_100 & V_101 ) != V_12 -> V_21 -> V_102 ) {
V_12 -> V_21 -> V_102 = ! V_12 -> V_21 -> V_102 ;
V_19 = V_12 -> V_21 -> V_103 ( V_12 -> V_21 -> V_98 ,
V_12 -> V_21 -> V_102 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_96 , V_7 ,
L_9 ,
V_19 ) ;
}
V_19 = V_12 -> V_21 -> V_104 ( V_7 , V_12 -> V_21 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_96 , V_7 , L_10 ,
V_19 ) ;
}
static struct V_105 * F_39 ( int V_106 )
{
if ( F_40 ( V_106 < 0 || V_106 >= V_107 ) )
return NULL ;
return V_108 [ V_106 ] ;
}
static bool F_41 ( int V_106 )
{
if ( F_39 ( V_106 ) ) {
F_42 ( & V_108 [ V_106 ] -> V_109 ) ;
return true ;
}
return false ;
}
static void F_43 ( int V_106 , struct V_105 * V_105 )
{
V_108 [ V_106 ] = V_105 ;
F_44 ( & V_105 -> V_109 , 1 ) ;
}
static int F_45 ( struct V_105 * V_105 )
{
int V_19 ;
if ( V_105 -> V_110 == 0 || V_105 -> V_111 == 0 ) {
F_46 ( L_11 ,
V_112 ) ;
return - V_74 ;
}
if ( V_105 -> V_106 != V_113 &&
F_41 ( V_105 -> V_106 ) )
return 0 ;
if ( V_105 -> V_106 == V_113 ) {
V_105 -> V_114 = F_47 () ;
if ( ! V_105 -> V_114 ) {
F_46 ( L_12 ,
V_112 ) ;
return - V_90 ;
}
V_105 -> V_106 = ( T_2 ) F_48 ( V_105 -> V_114 ) ;
}
if ( V_105 -> V_115 ) {
V_19 = V_105 -> V_115 ( V_105 ) ;
if ( V_19 )
goto V_116;
}
F_43 ( V_105 -> V_106 , V_105 ) ;
return 0 ;
V_116:
F_46 ( L_13 , V_112 ) ;
F_49 ( V_105 -> V_114 ) ;
return V_19 ;
}
static void F_50 ( struct V_105 * V_117 )
{
T_2 V_118 = 8 ;
int V_119 ;
do {
struct V_120 V_121 [ 8 ] ;
int V_5 ;
V_119 = F_51 ( V_117 -> V_114 , V_121 , V_118 ) ;
if ( V_119 < 0 ) {
if ( V_118 == 8 ) {
V_118 = 1 ;
V_119 = 1 ;
continue;
} else {
break;
}
}
if ( V_117 -> V_122 )
for ( V_5 = 0 ; V_5 < V_118 ; V_5 ++ )
V_117 -> V_122 ( V_117 , & V_121 [ V_5 ] ) ;
} while ( V_119 > 0 );
}
static void F_52 ( struct V_105 * V_105 )
{
struct V_105 * V_117 = F_39 ( V_105 -> V_106 ) ;
if ( ! V_117 )
return;
if ( ! F_53 ( & V_117 -> V_109 ) )
return;
if ( V_117 -> V_122 )
F_50 ( V_117 ) ;
V_108 [ V_117 -> V_106 ] = NULL ;
F_49 ( V_117 -> V_114 ) ;
}
static void F_54 ( struct V_11 * V_12 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ )
F_52 ( V_12 -> V_124 [ V_5 ] ) ;
}
static inline void F_55 ( struct V_125 * V_126 , int V_127 )
{
switch ( V_126 -> V_128 ) {
case V_129 :
case V_130 :
V_126 -> V_131 = 1 ;
break;
case V_132 :
case V_133 :
V_126 -> V_131 = 5 ;
break;
case V_134 :
V_126 -> V_131 = 6 ;
break;
case V_135 :
switch ( V_127 / V_80 ) {
case 0 :
V_126 -> V_131 = 6 ;
break;
case 1 :
V_126 -> V_131 = 2 ;
break;
case 2 :
V_126 -> V_131 = 1 ;
break;
case 3 :
V_126 -> V_131 = 0 ;
break;
default:
F_56 ( 1 , L_14 ,
V_136 ) ;
}
break;
default:
F_56 ( 1 , L_15 ,
V_126 -> V_128 , V_126 -> V_137 ) ;
}
}
static struct V_125 * F_57 ( struct V_13 * V_14 ,
T_4 V_24 , T_4 V_138 ,
struct V_139 * V_140 ,
enum V_141 V_128 )
{
struct V_125 * V_125 ;
int V_5 ;
V_125 = F_58 ( V_14 , sizeof( * V_125 ) * V_138 ,
V_142 ) ;
if ( ! V_125 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ ) {
V_125 [ V_5 ] . V_128 = V_128 ;
V_125 [ V_5 ] . V_137 = V_24 ? V_24 + V_5 : 0 ;
F_59 ( & V_125 [ V_5 ] . V_140 , V_140 ) ;
}
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ )
F_55 ( V_125 + V_5 , V_5 ) ;
return V_125 ;
}
static int F_60 ( struct V_13 * V_14 , struct V_139 * V_140 ,
struct V_143 * V_144 )
{
struct V_125 * V_125 ;
V_125 = F_57 ( V_14 , 0 , 1 , V_140 , V_132 ) ;
if ( ! V_125 )
goto V_145;
V_144 -> V_146 = & V_125 [ 0 ] ;
V_125 = F_57 ( V_14 , 0 , 1 , V_140 , V_134 ) ;
if ( ! V_125 )
goto V_145;
V_144 -> V_147 = & V_125 [ 0 ] ;
if ( ! F_57 ( V_14 , 0 , V_136 , V_140 , V_130 ) )
goto V_145;
V_125 = F_57 ( V_14 , 0 , 1 , V_140 , V_133 ) ;
if ( ! V_125 )
goto V_145;
V_144 -> V_148 = & V_125 [ 0 ] ;
V_125 = F_57 ( V_14 , 0 , 1 , V_140 , V_129 ) ;
if ( ! V_125 )
goto V_145;
V_144 -> V_149 = & V_125 [ 0 ] ;
if ( ! F_57 ( V_14 , 0 , V_136 , V_140 , V_135 ) )
goto V_145;
return 0 ;
V_145:
F_10 ( V_14 , L_16 ) ;
return - V_150 ;
}
static int F_61 ( void )
{
F_62 ( & V_151 ) ;
if ( ! V_152 ) {
T_4 V_114 ;
int V_119 ;
V_119 = F_63 ( & V_114 ) ;
if ( ! V_119 )
V_152 = V_114 ;
}
F_64 ( & V_151 ) ;
if ( ! V_152 )
return - V_150 ;
return V_152 ;
}
static void F_65 ( void )
{
F_66 ( V_152 ) ;
}
static void F_67 ( T_3 V_153 )
{
T_4 V_114 = F_68 ( V_153 ) ;
const T_6 * V_154 = F_69 () ;
struct V_155 * V_156 ;
int V_157 ;
F_70 (cpu, cpus) {
V_156 = F_71 ( V_157 ) ;
F_72 ( V_156 , V_114 ) ;
}
}
static void F_73 ( struct V_155 * V_158 , struct V_159 * V_160 ,
int V_161 )
{
struct V_11 * V_12 = (struct V_11 * ) F_74 ( V_160 ,
struct V_11 , V_162 . V_160 ) ;
if ( V_161 ) {
V_12 -> V_162 . V_163 = V_57 ;
F_12 ( V_12 -> V_7 ) ;
V_12 -> V_162 . V_164 ++ ;
} else {
V_12 -> V_162 . V_165 +=
( V_57 - V_12 -> V_162 . V_163 ) ;
F_75 ( V_12 -> V_7 ) ;
}
}
static int F_76 ( struct V_11 * V_12 )
{
struct V_166 V_167 ;
T_4 V_168 ;
int V_19 ;
V_19 = F_77 ( & V_12 -> V_162 . V_160 . V_169 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_17 ,
V_112 , V_19 ) ;
goto V_170;
}
V_12 -> V_162 . V_160 . V_171 = F_73 ;
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_172 = F_79 ( V_173 | V_174 ) ;
V_167 . V_160 . V_175 = V_176 ;
if ( V_12 -> V_21 -> V_177 & V_178 )
V_168 = V_179 ;
else
V_168 = V_180 ;
F_80 ( & V_167 . V_160 . V_181 , V_168 , 1 ) ;
V_167 . V_172 |= F_79 ( V_182 ) ;
V_167 . V_160 . V_183 = V_176 ;
V_19 = F_81 ( & V_12 -> V_162 . V_160 , V_184 ,
& V_167 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_18 ,
V_112 , V_19 , V_12 -> V_162 . V_160 . V_169 ) ;
F_82 ( V_12 -> V_162 . V_160 . V_169 ) ;
goto V_170;
}
if ( F_78 ( V_12 ) )
F_83 ( L_19 ,
V_12 -> V_162 . V_160 . V_169 , V_12 -> V_21 -> V_22 ,
V_12 -> V_162 . V_160 . V_185 ) ;
V_170:
return V_19 ;
}
static inline void F_84 ( const struct V_11 * V_12 ,
struct V_125 * V_126 ,
const struct V_186 * V_187 )
{
V_126 -> V_188 = * V_187 ;
V_126 -> V_7 = V_12 -> V_7 ;
V_126 -> V_100 = V_189 ;
V_126 -> V_153 = V_12 -> V_153 ;
}
static inline void F_85 ( const struct V_11 * V_12 ,
struct V_125 * V_126 ,
struct V_190 * V_54 ,
const struct V_186 * V_187 )
{
V_126 -> V_188 = * V_187 ;
V_126 -> V_7 = V_12 -> V_7 ;
if ( V_54 ) {
V_126 -> V_100 = V_191 ;
V_126 -> V_153 = ( T_3 ) F_86 ( V_54 ) ;
} else {
V_126 -> V_100 = V_192 ;
}
}
static void F_87 ( struct V_11 * V_12 ,
const struct V_193 * V_194 ,
struct V_190 * V_195 )
{
int V_196 = 0 , V_197 = 0 , V_198 = 0 , V_157 ;
const T_6 * V_199 = F_69 () ;
T_3 V_200 [ V_201 ] ;
struct V_125 * V_126 ;
F_70 (cpu, affine_cpus)
V_200 [ V_198 ++ ] = F_88 ( V_157 ) ;
if ( V_198 == 0 )
F_10 ( V_12 -> V_7 -> V_14 . V_15 ,
L_20 ) ;
F_89 (fq, &priv->dpaa_fq_list, list) {
switch ( V_126 -> V_128 ) {
case V_134 :
F_84 ( V_12 , V_126 , & V_194 -> V_147 ) ;
break;
case V_132 :
F_84 ( V_12 , V_126 , & V_194 -> V_146 ) ;
break;
case V_135 :
F_85 ( V_12 , V_126 , V_195 ,
& V_194 -> V_202 ) ;
if ( V_196 < V_136 )
V_12 -> V_203 [ V_196 ++ ] = & V_126 -> V_188 ;
break;
case V_130 :
V_12 -> V_204 [ V_197 ++ ] = & V_126 -> V_188 ;
case V_129 :
F_84 ( V_12 , V_126 , & V_194 -> V_149 ) ;
break;
case V_133 :
F_84 ( V_12 , V_126 , & V_194 -> V_148 ) ;
break;
default:
F_90 ( V_12 -> V_7 -> V_14 . V_15 ,
L_21 ) ;
break;
}
}
while ( V_196 < V_136 ) {
F_89 (fq, &priv->dpaa_fq_list, list) {
if ( V_126 -> V_128 != V_135 )
continue;
V_12 -> V_203 [ V_196 ++ ] = & V_126 -> V_188 ;
if ( V_196 == V_136 )
break;
}
}
}
static inline int F_91 ( const struct V_11 * V_12 ,
struct V_186 * V_205 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_136 ; V_5 ++ )
if ( V_12 -> V_203 [ V_5 ] == V_205 )
return V_5 ;
return - V_74 ;
}
static int F_92 ( struct V_125 * V_125 , bool V_206 )
{
const struct V_11 * V_12 ;
struct V_186 * V_207 = NULL ;
struct V_208 V_209 ;
struct V_13 * V_14 ;
struct V_186 * V_126 ;
int V_210 ;
int V_19 ;
V_12 = F_3 ( V_125 -> V_7 ) ;
V_14 = V_125 -> V_7 -> V_14 . V_15 ;
if ( V_125 -> V_137 == 0 )
V_125 -> V_100 |= V_211 ;
V_125 -> V_212 = ! ( V_125 -> V_100 & V_192 ) ;
V_19 = F_93 ( V_125 -> V_137 , V_125 -> V_100 , & V_125 -> V_188 ) ;
if ( V_19 ) {
F_10 ( V_14 , L_22 ) ;
return V_19 ;
}
V_126 = & V_125 -> V_188 ;
if ( V_125 -> V_212 ) {
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 . V_172 = F_79 ( V_213 ) ;
V_209 . V_214 . V_215 = F_79 ( V_216 ) ;
if ( V_125 -> V_128 == V_129 )
V_209 . V_214 . V_215 |= F_79 ( V_217 ) ;
V_209 . V_172 |= F_79 ( V_218 ) ;
F_94 ( & V_209 . V_214 , V_125 -> V_153 , V_125 -> V_131 ) ;
if ( V_125 -> V_128 == V_135 ||
V_125 -> V_128 == V_129 ||
V_125 -> V_128 == V_130 ) {
V_209 . V_172 |= F_79 ( V_219 ) ;
V_209 . V_214 . V_215 |= F_79 ( V_220 ) ;
V_209 . V_214 . V_221 = ( T_2 ) V_12 -> V_162 . V_160 . V_169 ;
V_209 . V_172 |= F_79 ( V_222 ) ;
F_95 ( & V_209 . V_214 , V_223 ) ;
F_96 ( & V_209 . V_214 ,
F_97 ( sizeof( struct V_224 ) +
V_12 -> V_49 ,
( T_1 ) V_225 ) ) ;
}
if ( V_206 ) {
V_209 . V_172 |= F_79 ( V_226 ) ;
F_98 ( & V_209 . V_214 , V_227 , 1 ) ;
V_209 . V_214 . V_215 = F_79 ( V_228 ) ;
}
if ( V_125 -> V_128 == V_135 ) {
V_210 = F_91 ( V_12 , & V_125 -> V_188 ) ;
if ( V_210 >= 0 )
V_207 = V_12 -> V_204 [ V_210 ] ;
if ( V_207 ) {
V_209 . V_172 |=
F_79 ( V_229 ) ;
F_99 ( & V_209 . V_214 ,
0x1e00000080000000ULL ) ;
}
}
if ( V_12 -> V_230 &&
( V_125 -> V_128 == V_134 ||
V_125 -> V_128 == V_132 ) ) {
V_209 . V_172 |= F_79 ( V_219 ) ;
V_209 . V_214 . V_215 |= F_79 ( V_220 ) ;
V_209 . V_214 . V_221 = ( T_2 ) V_12 -> V_231 . V_169 ;
V_209 . V_172 |= F_79 ( V_222 ) ;
F_95 ( & V_209 . V_214 , V_223 ) ;
F_96 ( & V_209 . V_214 ,
F_97 ( sizeof( struct V_224 ) +
V_12 -> V_49 ,
( T_1 ) V_225 ) ) ;
}
if ( V_125 -> V_100 & V_189 ) {
V_209 . V_172 |= F_79 ( V_229 ) ;
V_209 . V_214 . V_215 |= F_79 ( V_232 |
V_233 ) ;
V_209 . V_214 . V_234 . V_235 . V_236 =
V_237 | V_238 |
V_239 ;
F_100 ( & V_209 . V_214 , 1 , 2 ,
F_101 ( sizeof( struct V_186 ) ,
64 ) ) ;
}
V_19 = F_102 ( V_126 , V_240 , & V_209 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_23 ,
F_103 ( V_126 ) , V_19 ) ;
F_104 ( V_126 ) ;
return V_19 ;
}
}
V_125 -> V_137 = F_103 ( V_126 ) ;
return 0 ;
}
static int F_105 ( struct V_13 * V_14 , struct V_186 * V_126 )
{
const struct V_11 * V_12 ;
struct V_125 * V_125 ;
int V_19 , error ;
V_19 = 0 ;
V_125 = F_74 ( V_126 , struct V_125 , V_188 ) ;
V_12 = F_3 ( V_125 -> V_7 ) ;
if ( V_125 -> V_212 ) {
V_19 = F_106 ( V_126 , NULL ) ;
if ( V_19 < 0 && F_78 ( V_12 ) )
F_10 ( V_14 , L_24 ,
F_103 ( V_126 ) , V_19 ) ;
error = F_107 ( V_126 ) ;
if ( error < 0 && F_78 ( V_12 ) ) {
F_10 ( V_14 , L_25 ,
F_103 ( V_126 ) , error ) ;
if ( V_19 >= 0 )
V_19 = error ;
}
}
F_104 ( V_126 ) ;
F_108 ( & V_125 -> V_140 ) ;
return V_19 ;
}
static int F_109 ( struct V_13 * V_14 , struct V_139 * V_140 )
{
struct V_125 * V_125 , * V_241 ;
int V_19 , error ;
V_19 = 0 ;
F_110 (dpaa_fq, tmp, list, list) {
error = F_105 ( V_14 , (struct V_186 * ) V_125 ) ;
if ( error < 0 && V_19 >= 0 )
V_19 = error ;
}
return V_19 ;
}
static int F_111 ( struct V_190 * V_54 , struct V_125 * V_242 ,
struct V_125 * V_243 ,
struct V_244 * V_245 )
{
struct V_246 V_247 ;
struct V_248 V_249 ;
int V_19 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_250 = V_245 -> V_250 ;
V_247 . V_251 = true ;
V_247 . V_252 = true ;
V_247 . V_253 = false ;
V_247 . V_254 = V_255 ;
V_249 . V_256 . V_257 . V_258 = V_242 -> V_137 ;
V_249 . V_256 . V_257 . V_259 = V_243 -> V_137 ;
V_19 = F_112 ( V_54 , & V_249 ) ;
if ( V_19 ) {
F_46 ( L_26 , V_112 ) ;
return V_19 ;
}
V_19 = F_113 ( V_54 , & V_247 ) ;
if ( V_19 ) {
F_46 ( L_27 ,
V_112 ) ;
return V_19 ;
}
V_19 = F_114 ( V_54 ) ;
if ( V_19 )
F_46 ( L_28 , V_112 ) ;
return V_19 ;
}
static int F_115 ( struct V_190 * V_54 , struct V_105 * * V_260 ,
T_1 V_138 , struct V_125 * V_242 ,
struct V_125 * V_243 ,
struct V_244 * V_245 )
{
struct V_246 V_247 ;
struct V_261 * V_262 ;
struct V_248 V_249 ;
int V_5 , V_19 ;
memset ( & V_249 , 0 , sizeof( V_249 ) ) ;
memset ( & V_247 , 0 , sizeof( V_247 ) ) ;
V_247 . V_250 = V_245 -> V_250 ;
V_247 . V_251 = true ;
V_247 . V_252 = true ;
V_247 . V_253 = false ;
V_247 . V_254 = V_255 ;
V_262 = & V_249 . V_256 . V_263 ;
V_262 -> V_258 = V_242 -> V_137 ;
V_262 -> V_259 = V_243 -> V_137 ;
V_138 = F_97 ( F_15 ( V_262 -> V_264 . V_265 ) , V_138 ) ;
V_262 -> V_264 . V_266 = ( T_2 ) V_138 ;
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ ) {
V_262 -> V_264 . V_265 [ V_5 ] . V_267 = V_260 [ V_5 ] -> V_106 ;
V_262 -> V_264 . V_265 [ V_5 ] . V_110 = ( T_3 ) V_260 [ V_5 ] -> V_110 ;
}
V_19 = F_112 ( V_54 , & V_249 ) ;
if ( V_19 ) {
F_46 ( L_26 , V_112 ) ;
return V_19 ;
}
V_19 = F_113 ( V_54 , & V_247 ) ;
if ( V_19 ) {
F_46 ( L_27 ,
V_112 ) ;
return V_19 ;
}
V_19 = F_114 ( V_54 ) ;
if ( V_19 )
F_46 ( L_28 , V_112 ) ;
return V_19 ;
}
static int F_116 ( struct V_51 * V_21 ,
struct V_105 * * V_260 , T_1 V_138 ,
struct V_143 * V_144 ,
struct V_244 * V_245 ,
struct V_13 * V_14 )
{
struct V_190 * V_268 = V_21 -> V_54 [ V_269 ] ;
struct V_190 * V_270 = V_21 -> V_54 [ V_271 ] ;
int V_19 ;
V_19 = F_111 ( V_270 , V_144 -> V_148 ,
V_144 -> V_149 , & V_245 [ V_271 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_115 ( V_268 , V_260 , V_138 , V_144 -> V_146 ,
V_144 -> V_147 , & V_245 [ V_269 ] ) ;
return V_19 ;
}
static int F_117 ( const struct V_105 * V_105 ,
struct V_120 * V_121 , int V_2 )
{
int V_19 ;
V_19 = F_118 ( V_105 -> V_114 , V_121 , V_2 ) ;
if ( F_119 ( F_40 ( V_19 ) ) && V_105 -> V_122 )
while ( V_2 -- > 0 )
V_105 -> V_122 ( V_105 , & V_121 [ V_2 ] ) ;
return V_2 ;
}
static void F_120 ( struct V_272 * V_273 )
{
struct V_120 V_121 [ V_274 ] ;
struct V_105 * V_105 ;
int V_5 = 0 , V_66 ;
memset ( V_121 , 0 , sizeof( V_121 ) ) ;
do {
V_105 = F_39 ( V_273 [ V_5 ] . V_106 ) ;
if ( ! V_105 )
return;
V_66 = 0 ;
do {
F_40 ( F_121 ( & V_273 [ V_5 ] ) ) ;
F_122 ( & V_121 [ V_66 ] , F_123 ( & V_273 [ V_5 ] ) ) ;
V_66 ++ ; V_5 ++ ;
} while ( V_66 < F_15 ( V_121 ) &&
! F_124 ( & V_273 [ V_5 - 1 ] ) &&
V_273 [ V_5 - 1 ] . V_106 == V_273 [ V_5 ] . V_106 );
F_117 ( V_105 , V_121 , V_66 ) ;
} while ( ! F_124 ( & V_273 [ V_5 - 1 ] ) );
}
static void F_125 ( const struct V_6 * V_7 ,
const struct V_275 * V_276 )
{
struct V_272 * V_273 ;
struct V_105 * V_105 ;
struct V_120 V_121 ;
T_7 V_22 ;
void * V_277 ;
V_121 . V_278 = 0 ;
F_122 ( & V_121 , F_126 ( V_276 ) ) ;
V_105 = F_39 ( V_276 -> V_106 ) ;
if ( ! V_105 )
return;
if ( F_127 ( V_276 ) == V_279 ) {
V_277 = F_128 ( F_126 ( V_276 ) ) ;
V_273 = V_277 + F_129 ( V_276 ) ;
F_130 ( V_105 -> V_14 , F_126 ( V_276 ) , V_105 -> V_110 ,
V_280 ) ;
F_120 ( V_273 ) ;
V_22 = F_131 ( V_105 -> V_14 , V_277 , V_105 -> V_110 ,
V_280 ) ;
if ( F_132 ( V_105 -> V_14 , V_22 ) ) {
F_10 ( V_105 -> V_14 , L_29 ) ;
return;
}
F_122 ( & V_121 , V_22 ) ;
}
F_117 ( V_105 , & V_121 , 1 ) ;
}
static void F_133 ( struct V_16 * V_17 ,
const union V_281 * V_282 )
{
switch ( V_282 -> V_283 . V_284 & V_285 ) {
case V_286 :
V_17 -> V_287 . V_288 ++ ;
break;
case V_289 :
V_17 -> V_287 . V_290 ++ ;
break;
case V_291 :
V_17 -> V_287 . V_292 ++ ;
break;
case V_293 :
V_17 -> V_287 . V_294 ++ ;
break;
case V_295 :
V_17 -> V_287 . V_296 ++ ;
break;
case V_297 :
V_17 -> V_287 . V_298 ++ ;
break;
case V_299 :
V_17 -> V_287 . V_300 ++ ;
break;
case V_301 :
V_17 -> V_287 . V_302 ++ ;
break;
}
}
static int F_134 ( struct V_11 * V_12 ,
struct V_224 * V_303 ,
struct V_275 * V_276 ,
char * V_304 )
{
struct V_305 * V_306 ;
T_3 V_307 = F_135 ( V_303 -> V_308 ) ;
struct V_309 * V_310 = NULL ;
struct V_311 * V_312 ;
int V_313 = 0 ;
T_2 V_314 ;
if ( V_303 -> V_315 != V_316 )
return 0 ;
V_306 = (struct V_305 * ) V_304 ;
if ( V_307 == V_317 ) {
F_136 ( V_303 ) ;
V_307 = F_135 ( F_137 ( V_303 ) -> V_318 ) ;
}
switch ( V_307 ) {
case V_319 :
V_306 -> V_320 = F_79 ( V_321 ) ;
V_312 = F_138 ( V_303 ) ;
F_40 ( ! V_312 ) ;
V_314 = V_312 -> V_308 ;
break;
case V_322 :
V_306 -> V_320 = F_79 ( V_323 ) ;
V_310 = F_139 ( V_303 ) ;
F_40 ( ! V_310 ) ;
V_314 = V_310 -> V_324 ;
break;
default:
if ( F_140 () )
F_141 ( V_12 , V_325 , V_12 -> V_7 ,
L_30 ,
F_135 ( V_303 -> V_308 ) ) ;
V_313 = - V_326 ;
goto V_327;
}
switch ( V_314 ) {
case V_328 :
V_306 -> V_329 = V_330 ;
break;
case V_331 :
V_306 -> V_329 = V_332 ;
break;
default:
if ( F_140 () )
F_141 ( V_12 , V_325 , V_12 -> V_7 ,
L_31 ,
V_314 ) ;
V_313 = - V_326 ;
goto V_327;
}
V_306 -> V_333 [ 0 ] = ( T_2 ) F_142 ( V_303 ) ;
V_306 -> V_334 = ( T_2 ) F_143 ( V_303 ) ;
V_276 -> V_335 |= F_144 ( V_336 | V_337 ) ;
V_327:
return V_313 ;
}
static int F_145 ( const struct V_105 * V_105 )
{
struct V_13 * V_14 = V_105 -> V_14 ;
struct V_120 V_121 [ 8 ] ;
T_7 V_22 ;
void * V_338 ;
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_338 = F_146 ( V_105 -> V_339 ) ;
if ( F_119 ( ! V_338 ) ) {
F_10 ( V_14 , L_32 ,
V_105 -> V_339 ) ;
goto V_340;
}
V_338 = F_147 ( V_338 , V_341 ) ;
V_22 = F_131 ( V_14 , V_338 ,
V_105 -> V_110 , V_280 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_105 -> V_14 , L_33 ) ;
goto V_340;
}
V_121 [ V_5 ] . V_278 = 0 ;
F_122 ( & V_121 [ V_5 ] , V_22 ) ;
}
V_342:
return F_117 ( V_105 , V_121 , V_5 ) ;
V_340:
F_148 ( 1 , L_34 ) ;
F_122 ( & V_121 [ V_5 ] , 0 ) ;
if ( F_149 ( V_5 ) )
goto V_342;
return 0 ;
}
static int F_150 ( struct V_105 * V_105 )
{
int V_5 ;
F_4 (i) {
int * V_343 = F_5 ( V_105 -> V_344 , V_5 ) ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_105 -> V_111 ; V_66 += 8 )
* V_343 += F_145 ( V_105 ) ;
}
return 0 ;
}
static int F_151 ( struct V_105 * V_105 , int * V_345 )
{
int V_138 = * V_345 ;
int V_346 ;
if ( F_119 ( V_138 < V_347 ) ) {
do {
V_346 = F_145 ( V_105 ) ;
if ( F_119 ( ! V_346 ) ) {
break;
}
V_138 += V_346 ;
} while ( V_138 < V_348 );
* V_345 = V_138 ;
if ( F_119 ( V_138 < V_348 ) )
return - V_150 ;
}
return 0 ;
}
static int F_152 ( struct V_11 * V_12 )
{
struct V_105 * V_105 ;
int * V_345 ;
int V_3 , V_5 ;
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ ) {
V_105 = V_12 -> V_124 [ V_5 ] ;
if ( ! V_105 )
return - V_74 ;
V_345 = F_19 ( V_105 -> V_344 ) ;
V_3 = F_151 ( V_105 , V_345 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static struct V_224 * F_153 ( const struct V_11 * V_12 ,
const struct V_275 * V_276 )
{
const enum V_349 V_350 = V_351 ;
struct V_13 * V_14 = V_12 -> V_7 -> V_14 . V_15 ;
T_7 V_22 = F_126 ( V_276 ) ;
const struct V_272 * V_273 ;
struct V_224 * * V_352 , * V_303 ;
int V_353 , V_5 ;
V_352 = (struct V_224 * * ) F_128 ( V_22 ) ;
V_303 = * V_352 ;
if ( F_119 ( F_127 ( V_276 ) == V_279 ) ) {
V_353 = F_154 ( V_303 ) -> V_353 ;
F_130 ( V_14 , V_22 , F_129 ( V_276 ) +
sizeof( struct V_272 ) * ( 1 + V_353 ) ,
V_350 ) ;
V_273 = F_128 ( V_22 + F_129 ( V_276 ) ) ;
F_130 ( V_14 , F_155 ( & V_273 [ 0 ] ) ,
F_156 ( & V_273 [ 0 ] ) , V_350 ) ;
for ( V_5 = 1 ; V_5 < V_353 ; V_5 ++ ) {
F_40 ( F_121 ( & V_273 [ V_5 ] ) ) ;
F_157 ( V_14 , F_155 ( & V_273 [ V_5 ] ) ,
F_156 ( & V_273 [ V_5 ] ) , V_350 ) ;
}
F_158 ( F_128 ( V_22 ) ) ;
} else {
F_130 ( V_14 , V_22 ,
F_159 ( V_303 ) - ( T_2 * ) V_352 , V_350 ) ;
}
return V_303 ;
}
static T_2 F_160 ( const struct V_11 * V_12 , const struct V_275 * V_276 )
{
if ( ( V_12 -> V_7 -> V_36 & V_38 ) &&
( F_161 ( V_276 -> V_354 ) & V_355 ) )
return V_356 ;
return V_357 ;
}
static struct V_224 * F_162 ( const struct V_11 * V_12 ,
const struct V_275 * V_276 )
{
T_8 V_358 = F_129 ( V_276 ) ;
T_7 V_22 = F_126 ( V_276 ) ;
struct V_105 * V_105 ;
struct V_224 * V_303 ;
void * V_277 ;
V_277 = F_128 ( V_22 ) ;
F_40 ( ! F_163 ( ( unsigned long ) V_277 , V_341 ) ) ;
V_105 = F_39 ( V_276 -> V_106 ) ;
if ( ! V_105 )
goto V_359;
V_303 = F_164 ( V_277 , V_105 -> V_110 +
F_165 ( sizeof( struct V_360 ) ) ) ;
if ( F_119 ( ! V_303 ) ) {
F_148 ( 1 , L_35 ) ;
goto V_359;
}
F_40 ( V_358 != V_12 -> V_361 ) ;
F_166 ( V_303 , V_358 ) ;
F_167 ( V_303 , F_168 ( V_276 ) ) ;
V_303 -> V_315 = F_160 ( V_12 , V_276 ) ;
return V_303 ;
V_359:
F_158 ( V_277 ) ;
return NULL ;
}
static struct V_224 * F_169 ( const struct V_11 * V_12 ,
const struct V_275 * V_276 )
{
T_8 V_358 = F_129 ( V_276 ) ;
T_7 V_22 = F_126 ( V_276 ) ;
const struct V_272 * V_273 ;
struct V_362 * V_362 , * V_363 ;
struct V_105 * V_105 ;
void * V_277 , * V_364 ;
int V_365 , V_366 ;
struct V_224 * V_303 ;
T_7 V_367 ;
int V_368 ;
unsigned int V_369 ;
int * V_343 ;
int V_5 ;
V_277 = F_128 ( V_22 ) ;
F_40 ( ! F_163 ( ( unsigned long ) V_277 , V_341 ) ) ;
V_273 = V_277 + V_358 ;
for ( V_5 = 0 ; V_5 < V_370 ; V_5 ++ ) {
F_40 ( F_121 ( & V_273 [ V_5 ] ) ) ;
V_367 = F_155 ( & V_273 [ V_5 ] ) ;
V_364 = F_128 ( V_367 ) ;
F_40 ( ! F_163 ( ( unsigned long ) V_364 ,
V_341 ) ) ;
V_105 = F_39 ( V_273 [ V_5 ] . V_106 ) ;
if ( ! V_105 )
goto V_371;
V_343 = F_19 ( V_105 -> V_344 ) ;
F_130 ( V_105 -> V_14 , V_367 , V_105 -> V_110 ,
V_280 ) ;
if ( V_5 == 0 ) {
V_369 = V_105 -> V_110 +
F_165 ( sizeof( struct V_360 ) ) ;
V_303 = F_164 ( V_364 , V_369 ) ;
if ( F_40 ( F_119 ( ! V_303 ) ) )
goto V_371;
V_303 -> V_315 = F_160 ( V_12 , V_276 ) ;
F_40 ( V_358 != V_12 -> V_361 ) ;
F_166 ( V_303 , V_358 ) ;
F_167 ( V_303 , F_156 ( & V_273 [ V_5 ] ) ) ;
} else {
V_362 = F_170 ( V_364 ) ;
V_363 = F_171 ( V_364 ) ;
V_368 = ( ( unsigned long ) V_364 &
( V_372 - 1 ) ) +
( F_172 ( V_362 ) - F_172 ( V_363 ) ) ;
V_365 = F_173 ( & V_273 [ V_5 ] ) + V_368 ;
V_366 = F_156 ( & V_273 [ V_5 ] ) ;
F_174 ( V_303 , V_5 - 1 , V_363 , V_365 ,
V_366 , V_105 -> V_110 ) ;
}
( * V_343 ) -- ;
if ( F_124 ( & V_273 [ V_5 ] ) )
break;
}
F_148 ( V_5 == V_370 , L_36 ) ;
F_158 ( V_277 ) ;
return V_303 ;
V_371:
for ( V_5 -- ; V_5 >= 0 ; V_5 -- ) {
V_105 = F_39 ( V_273 [ V_5 ] . V_106 ) ;
if ( V_105 ) {
V_343 = F_19 ( V_105 -> V_344 ) ;
( * V_343 ) ++ ;
}
}
for ( V_5 = 0 ; V_5 < V_370 ; V_5 ++ ) {
V_367 = F_155 ( & V_273 [ V_5 ] ) ;
V_364 = F_128 ( V_367 ) ;
F_158 ( V_364 ) ;
V_105 = F_39 ( V_273 [ V_5 ] . V_106 ) ;
if ( V_105 ) {
V_343 = F_19 ( V_105 -> V_344 ) ;
( * V_343 ) -- ;
}
if ( F_124 ( & V_273 [ V_5 ] ) )
break;
}
F_158 ( V_277 ) ;
return NULL ;
}
static int F_175 ( struct V_11 * V_12 ,
struct V_224 * V_303 , struct V_275 * V_276 ,
int * V_373 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
enum V_349 V_350 ;
unsigned char * V_374 ;
struct V_224 * * V_352 ;
T_7 V_22 ;
int V_19 ;
V_276 -> V_106 = V_113 ;
V_374 = V_303 -> V_278 - V_12 -> V_49 ;
V_350 = V_351 ;
V_352 = (struct V_224 * * ) V_374 ;
* V_352 = V_303 ;
V_19 = F_134 ( V_12 , V_303 , V_276 ,
( ( char * ) V_352 ) + V_375 ) ;
if ( F_119 ( V_19 < 0 ) ) {
if ( F_140 () )
F_14 ( V_12 , V_325 , V_7 , L_37 ,
V_19 ) ;
return V_19 ;
}
F_176 ( V_276 , V_12 -> V_49 , V_303 -> V_376 ) ;
V_276 -> V_335 |= F_144 ( V_377 ) ;
V_22 = F_131 ( V_14 , V_352 ,
F_159 ( V_303 ) - V_374 , V_350 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
if ( F_140 () )
F_14 ( V_12 , V_325 , V_7 , L_38 ) ;
return - V_74 ;
}
F_177 ( V_276 , V_22 ) ;
return 0 ;
}
static int F_178 ( struct V_11 * V_12 ,
struct V_224 * V_303 , struct V_275 * V_276 )
{
const enum V_349 V_350 = V_351 ;
const int V_353 = F_154 ( V_303 ) -> V_353 ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
struct V_272 * V_273 ;
struct V_224 * * V_352 ;
int V_5 , V_66 , V_19 , V_369 ;
void * V_374 ;
T_9 * V_378 ;
T_7 V_22 ;
T_1 V_366 ;
void * V_379 ;
V_369 = F_165 ( V_12 -> V_49 +
sizeof( struct V_272 ) * ( 1 + V_353 ) ) ;
V_379 = F_146 ( V_369 ) ;
if ( F_119 ( ! V_379 ) ) {
F_26 ( V_7 , L_39 ,
V_369 ) ;
return - V_150 ;
}
V_19 = F_134 ( V_12 , V_303 , V_276 ,
V_379 + V_375 ) ;
if ( F_119 ( V_19 < 0 ) ) {
if ( F_140 () )
F_14 ( V_12 , V_325 , V_7 , L_37 ,
V_19 ) ;
goto V_380;
}
V_273 = (struct V_272 * ) ( V_379 + V_12 -> V_49 ) ;
F_179 ( & V_273 [ 0 ] , F_180 ( V_303 ) ) ;
V_273 [ 0 ] . V_106 = V_113 ;
V_273 [ 0 ] . V_373 = 0 ;
V_22 = F_131 ( V_14 , V_303 -> V_278 ,
F_180 ( V_303 ) , V_350 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_74 ;
goto V_381;
}
F_181 ( & V_273 [ 0 ] , V_22 ) ;
V_378 = & F_154 ( V_303 ) -> V_382 [ 0 ] ;
V_366 = V_378 -> V_110 ;
for ( V_5 = 1 ; V_5 <= V_353 ; V_5 ++ , V_378 ++ ) {
F_40 ( ! F_182 ( V_378 ) ) ;
V_22 = F_183 ( V_14 , V_378 , 0 ,
V_366 , V_350 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_74 ;
goto V_383;
}
F_179 ( & V_273 [ V_5 ] , V_366 ) ;
V_273 [ V_5 ] . V_106 = V_113 ;
V_273 [ V_5 ] . V_373 = 0 ;
F_181 ( & V_273 [ V_5 ] , V_22 ) ;
V_366 = V_378 -> V_110 ;
}
F_184 ( & V_273 [ V_5 - 1 ] , V_366 ) ;
F_185 ( V_276 , V_12 -> V_49 , V_303 -> V_376 ) ;
V_374 = ( void * ) V_273 - V_12 -> V_49 ;
V_352 = (struct V_224 * * ) V_374 ;
* V_352 = V_303 ;
V_22 = F_131 ( V_14 , V_374 , V_12 -> V_49 +
sizeof( struct V_272 ) * ( 1 + V_353 ) ,
V_350 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_74 ;
goto V_384;
}
V_276 -> V_106 = V_113 ;
V_276 -> V_335 |= F_144 ( V_377 ) ;
F_177 ( V_276 , V_22 ) ;
return 0 ;
V_384:
V_383:
for ( V_66 = 0 ; V_66 < V_5 ; V_66 ++ )
F_157 ( V_14 , F_155 ( & V_273 [ V_66 ] ) ,
F_156 ( & V_273 [ V_66 ] ) , V_350 ) ;
V_381:
V_380:
F_158 ( V_379 ) ;
return V_19 ;
}
static inline int F_186 ( struct V_11 * V_12 ,
struct V_60 * V_385 ,
int V_386 ,
struct V_275 * V_276 )
{
struct V_186 * V_387 ;
int V_19 , V_5 ;
V_387 = V_12 -> V_203 [ V_386 ] ;
if ( V_276 -> V_106 == V_113 )
V_276 -> V_335 |= F_144 ( F_103 ( V_12 -> V_204 [ V_386 ] ) ) ;
F_187 ( V_12 -> V_7 , V_387 , V_276 ) ;
for ( V_5 = 0 ; V_5 < V_388 ; V_5 ++ ) {
V_19 = F_188 ( V_387 , V_276 ) ;
if ( V_19 != - V_389 )
break;
}
if ( F_119 ( V_19 < 0 ) ) {
V_385 -> V_59 ++ ;
V_385 -> V_390 ++ ;
return V_19 ;
}
V_385 -> V_391 ++ ;
V_385 -> V_392 += F_168 ( V_276 ) ;
return 0 ;
}
static int F_189 ( struct V_224 * V_303 , struct V_6 * V_7 )
{
const int V_393 = F_190 ( V_303 ) ;
bool V_394 = F_191 ( V_303 ) ;
struct V_60 * V_385 ;
struct V_16 * V_17 ;
struct V_11 * V_12 ;
struct V_275 V_276 ;
int V_373 = 0 ;
int V_19 = 0 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_385 = & V_17 -> V_58 ;
F_192 ( & V_276 ) ;
if ( ! V_394 ) {
if ( F_193 ( V_303 , V_12 -> V_49 ) )
goto V_395;
F_40 ( F_191 ( V_303 ) ) ;
}
if ( V_394 &&
F_149 ( F_154 ( V_303 ) -> V_353 < V_370 ) ) {
V_19 = F_178 ( V_12 , V_303 , & V_276 ) ;
V_17 -> V_396 ++ ;
} else {
if ( F_119 ( V_394 ) && F_194 ( V_303 ) )
goto V_395;
V_19 = F_175 ( V_12 , V_303 , & V_276 , & V_373 ) ;
}
if ( F_119 ( V_19 < 0 ) )
goto V_397;
if ( F_149 ( F_186 ( V_12 , V_385 , V_393 , & V_276 ) == 0 ) )
return V_398 ;
F_153 ( V_12 , & V_276 ) ;
V_397:
V_395:
V_385 -> V_59 ++ ;
F_195 ( V_303 ) ;
return V_398 ;
}
static void F_196 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_275 * V_276 ,
T_4 V_137 )
{
if ( F_140 () )
F_14 ( V_12 , V_76 , V_7 , L_40 ,
F_161 ( V_276 -> V_354 ) & V_399 ) ;
V_17 -> V_58 . V_400 ++ ;
if ( F_161 ( V_276 -> V_354 ) & V_401 )
V_17 -> V_400 . V_402 ++ ;
if ( F_161 ( V_276 -> V_354 ) & V_403 )
V_17 -> V_400 . V_404 ++ ;
if ( F_161 ( V_276 -> V_354 ) & V_405 )
V_17 -> V_400 . V_406 ++ ;
if ( F_161 ( V_276 -> V_354 ) & V_407 )
V_17 -> V_400 . V_408 ++ ;
F_125 ( V_7 , V_276 ) ;
}
static void F_197 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_275 * V_276 ,
T_4 V_137 )
{
struct V_224 * V_303 ;
if ( F_140 () )
F_198 ( V_12 , V_76 , V_7 , L_41 ,
F_161 ( V_276 -> V_354 ) & V_409 ) ;
V_17 -> V_58 . V_59 ++ ;
V_303 = F_153 ( V_12 , V_276 ) ;
F_195 ( V_303 ) ;
}
static int F_199 ( struct V_410 * V_411 , int V_412 )
{
struct V_413 * V_414 =
F_74 ( V_411 , struct V_413 , V_411 ) ;
int V_415 = F_200 ( V_414 -> V_416 , V_412 ) ;
if ( V_415 < V_412 ) {
F_201 ( V_411 , V_415 ) ;
F_202 ( V_414 -> V_416 , V_417 ) ;
} else if ( V_414 -> V_418 ) {
F_202 ( V_414 -> V_416 , V_417 ) ;
}
return V_415 ;
}
static void F_203 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_275 * V_276 ,
T_4 V_137 )
{
struct V_224 * V_303 ;
if ( F_119 ( F_161 ( V_276 -> V_354 ) & V_409 ) ) {
if ( F_140 () )
F_198 ( V_12 , V_76 , V_7 , L_41 ,
F_161 ( V_276 -> V_354 ) &
V_409 ) ;
V_17 -> V_58 . V_59 ++ ;
}
V_17 -> V_419 ++ ;
V_303 = F_153 ( V_12 , V_276 ) ;
F_204 ( V_303 ) ;
}
static inline int F_205 ( struct V_16 * V_17 ,
struct V_155 * V_156 )
{
if ( F_119 ( F_206 () || ! F_207 () ) ) {
F_208 ( V_156 , V_417 ) ;
V_17 -> V_414 . V_416 = V_156 ;
F_209 ( & V_17 -> V_414 . V_411 ) ;
V_17 -> V_420 ++ ;
return 1 ;
}
return 0 ;
}
static enum V_421 F_210 ( struct V_155 * V_156 ,
struct V_186 * V_126 ,
const struct V_422 * V_423 )
{
struct V_125 * V_125 = F_74 ( V_126 , struct V_125 , V_188 ) ;
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_105 * V_105 ;
struct V_11 * V_12 ;
V_7 = V_125 -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_105 = F_39 ( V_423 -> V_276 . V_106 ) ;
if ( ! V_105 )
return V_424 ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_205 ( V_17 , V_156 ) )
return V_425 ;
if ( F_152 ( V_12 ) )
F_125 ( V_7 , & V_423 -> V_276 ) ;
else
F_196 ( V_7 , V_12 , V_17 , & V_423 -> V_276 , V_126 -> V_137 ) ;
return V_424 ;
}
static enum V_421 F_211 ( struct V_155 * V_156 ,
struct V_186 * V_126 ,
const struct V_422 * V_423 )
{
struct V_60 * V_385 ;
struct V_16 * V_17 ;
const struct V_275 * V_276 = & V_423 -> V_276 ;
T_7 V_22 = F_126 ( V_276 ) ;
enum V_426 V_427 ;
struct V_6 * V_7 ;
T_4 V_428 ;
struct V_105 * V_105 ;
struct V_11 * V_12 ;
unsigned int V_429 ;
struct V_224 * V_303 ;
int * V_343 ;
V_428 = F_161 ( V_276 -> V_354 ) ;
V_427 = F_127 ( V_276 ) ;
V_7 = ( (struct V_125 * ) V_126 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_105 = F_39 ( V_423 -> V_276 . V_106 ) ;
if ( ! V_105 )
return V_424 ;
F_212 ( V_7 , V_126 , & V_423 -> V_276 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_385 = & V_17 -> V_58 ;
if ( F_119 ( F_205 ( V_17 , V_156 ) ) )
return V_425 ;
if ( F_119 ( F_152 ( V_12 ) ) ) {
F_125 ( V_7 , & V_423 -> V_276 ) ;
return V_424 ;
}
if ( F_119 ( V_428 & V_399 ) != 0 ) {
if ( F_140 () )
F_198 ( V_12 , V_76 , V_7 , L_41 ,
V_428 & V_399 ) ;
V_385 -> V_400 ++ ;
F_125 ( V_7 , V_276 ) ;
return V_424 ;
}
V_105 = F_39 ( V_276 -> V_106 ) ;
if ( ! V_105 )
return V_424 ;
F_130 ( V_105 -> V_14 , V_22 , V_105 -> V_110 , V_280 ) ;
F_213 ( F_128 ( V_22 ) + F_129 ( V_276 ) ) ;
V_427 = F_127 ( V_276 ) ;
F_40 ( ( V_427 != V_430 ) && ( V_427 != V_279 ) ) ;
V_343 = F_19 ( V_105 -> V_344 ) ;
( * V_343 ) -- ;
if ( F_149 ( V_427 == V_430 ) )
V_303 = F_162 ( V_12 , V_276 ) ;
else
V_303 = F_169 ( V_12 , V_276 ) ;
if ( ! V_303 )
return V_424 ;
V_303 -> V_308 = F_214 ( V_303 , V_7 ) ;
V_429 = V_303 -> V_376 ;
if ( F_119 ( F_215 ( V_303 ) == V_431 ) )
return V_424 ;
V_385 -> V_432 ++ ;
V_385 -> V_433 += V_429 ;
return V_424 ;
}
static enum V_421 F_216 ( struct V_155 * V_156 ,
struct V_186 * V_126 ,
const struct V_422 * V_423 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_125 * ) V_126 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_205 ( V_17 , V_156 ) )
return V_425 ;
F_197 ( V_7 , V_12 , V_17 , & V_423 -> V_276 , V_126 -> V_137 ) ;
return V_424 ;
}
static enum V_421 F_217 ( struct V_155 * V_156 ,
struct V_186 * V_126 ,
const struct V_422 * V_423 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_125 * ) V_126 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
F_218 ( V_7 , V_126 , & V_423 -> V_276 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_205 ( V_17 , V_156 ) )
return V_425 ;
F_203 ( V_7 , V_12 , V_17 , & V_423 -> V_276 , V_126 -> V_137 ) ;
return V_424 ;
}
static void V_202 ( struct V_155 * V_156 ,
struct V_186 * V_126 ,
const union V_281 * V_282 )
{
const struct V_275 * V_276 = & V_282 -> V_283 . V_276 ;
struct V_16 * V_17 ;
const struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_224 * V_303 ;
V_7 = ( (struct V_125 * ) V_126 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_17 -> V_58 . V_434 ++ ;
V_17 -> V_58 . V_390 ++ ;
F_133 ( V_17 , V_282 ) ;
V_303 = F_153 ( V_12 , V_276 ) ;
F_219 ( V_303 ) ;
}
static void F_220 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_414 . V_418 = 0 ;
F_221 ( & V_17 -> V_414 . V_411 ) ;
}
}
static void F_222 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_414 . V_418 = 1 ;
F_223 ( & V_17 -> V_414 . V_411 ) ;
}
}
static int F_224 ( struct V_6 * V_7 )
{
struct V_51 * V_21 ;
struct V_11 * V_12 ;
int V_19 , V_5 ;
V_12 = F_3 ( V_7 ) ;
V_21 = V_12 -> V_21 ;
F_220 ( V_12 ) ;
V_7 -> V_55 = V_21 -> V_435 ( V_7 , V_12 -> V_21 ) ;
if ( ! V_7 -> V_55 ) {
F_14 ( V_12 , V_436 , V_7 , L_42 ) ;
V_19 = - V_90 ;
goto V_437;
}
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_54 ) ; V_5 ++ ) {
V_19 = F_225 ( V_21 -> V_54 [ V_5 ] ) ;
if ( V_19 )
goto V_438;
}
V_19 = V_12 -> V_21 -> V_24 ( V_21 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_436 , V_7 , L_43 , V_19 ) ;
goto V_438;
}
F_226 ( V_7 ) ;
return 0 ;
V_438:
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_54 ) ; V_5 ++ )
F_16 ( V_21 -> V_54 [ V_5 ] ) ;
V_437:
F_222 ( V_12 ) ;
return V_19 ;
}
static int F_227 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
int V_19 ;
V_19 = F_11 ( V_7 ) ;
V_12 = F_3 ( V_7 ) ;
F_222 ( V_12 ) ;
return V_19 ;
}
static int F_228 ( struct V_6 * V_7 , struct V_439 * V_440 , int V_335 )
{
if ( ! V_7 -> V_55 )
return - V_74 ;
return F_229 ( V_7 -> V_55 , V_440 , V_335 ) ;
}
static int F_230 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_157 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_157 ) ;
F_231 ( V_7 , & V_17 -> V_414 . V_411 ,
F_199 , V_441 ) ;
}
return 0 ;
}
static void F_232 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_157 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_157 ) ;
F_233 ( & V_17 -> V_414 . V_411 ) ;
}
}
static inline void F_234 ( const struct V_105 * V_117 ,
struct V_120 * V_121 )
{
T_7 V_22 = F_235 ( V_121 ) ;
F_130 ( V_117 -> V_14 , V_22 , V_117 -> V_110 , V_280 ) ;
F_158 ( F_128 ( V_22 ) ) ;
}
static struct V_105 * F_236 ( struct V_13 * V_14 )
{
struct V_105 * V_105 ;
V_105 = F_58 ( V_14 , sizeof( * V_105 ) , V_142 ) ;
if ( ! V_105 )
return F_31 ( - V_150 ) ;
V_105 -> V_106 = V_113 ;
V_105 -> V_344 = F_237 ( V_14 , * V_105 -> V_344 ) ;
V_105 -> V_111 = V_348 ;
V_105 -> V_115 = F_150 ;
V_105 -> V_122 = F_234 ;
return V_105 ;
}
static int F_238 ( struct V_11 * V_12 )
{
struct V_166 V_167 ;
T_4 V_168 ;
int V_19 ;
V_19 = F_77 ( & V_12 -> V_231 . V_169 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_44 , V_19 ) ;
goto V_170;
}
memset ( & V_167 , 0 , sizeof( V_167 ) ) ;
V_167 . V_172 = F_79 ( V_174 ) ;
V_167 . V_160 . V_175 = V_176 ;
V_168 = V_442 ;
F_80 ( & V_167 . V_160 . V_181 , V_168 , 1 ) ;
V_167 . V_172 |= F_79 ( V_182 ) ;
V_167 . V_160 . V_183 = V_176 ;
V_19 = F_81 ( & V_12 -> V_231 , V_184 ,
& V_167 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_45 ,
V_19 , V_12 -> V_231 . V_169 ) ;
F_82 ( V_12 -> V_231 . V_169 ) ;
goto V_170;
}
if ( F_78 ( V_12 ) )
F_83 ( L_46 ,
V_12 -> V_231 . V_169 , V_12 -> V_21 -> V_22 ) ;
V_12 -> V_230 = true ;
V_170:
return V_19 ;
}
static inline T_3 F_239 ( struct V_244 * V_443 )
{
T_3 V_444 ;
V_444 = ( T_3 ) ( V_443 -> V_250 + V_445 +
V_446 + V_447 ) ;
return V_255 ? F_240 ( V_444 ,
V_255 ) :
V_444 ;
}
static int F_241 ( struct V_81 * V_82 )
{
struct V_105 * V_124 [ V_123 ] = { NULL } ;
struct V_16 * V_17 ;
struct V_6 * V_7 = NULL ;
struct V_125 * V_125 , * V_241 ;
struct V_11 * V_12 = NULL ;
struct V_143 V_144 ;
struct V_51 * V_21 ;
int V_19 = 0 , V_5 , V_153 ;
struct V_13 * V_14 ;
V_14 = & V_82 -> V_14 ;
V_7 = F_242 ( sizeof( * V_12 ) , V_136 ) ;
if ( ! V_7 ) {
F_10 ( V_14 , L_47 ) ;
goto V_448;
}
F_243 ( V_7 , V_14 ) ;
F_244 ( V_14 , V_7 ) ;
V_12 = F_3 ( V_7 ) ;
V_12 -> V_7 = V_7 ;
V_12 -> V_449 = F_245 ( V_450 , V_451 ) ;
V_21 = F_30 ( V_82 ) ;
if ( F_246 ( V_21 ) ) {
F_10 ( V_14 , L_48 ) ;
V_19 = F_247 ( V_21 ) ;
goto V_452;
}
V_7 -> V_453 = F_97 ( F_6 () , V_454 ) ;
F_248 ( V_7 , L_49 ,
V_7 -> V_453 ) ;
V_12 -> V_245 [ V_269 ] . V_250 = V_455 ;
V_12 -> V_245 [ V_271 ] . V_250 = V_375 ;
F_249 ( V_14 , F_250 ( & V_82 -> V_14 ) ) ;
V_19 = F_251 ( V_14 , F_252 ( 40 ) ) ;
if ( V_19 ) {
F_10 ( V_14 , L_50 ) ;
goto V_456;
}
for ( V_5 = 0 ; V_5 < V_123 ; V_5 ++ ) {
int V_19 ;
V_124 [ V_5 ] = F_236 ( V_14 ) ;
if ( F_246 ( V_124 [ V_5 ] ) )
return F_247 ( V_124 [ V_5 ] ) ;
V_124 [ V_5 ] -> V_339 = F_1 ( V_5 , V_123 ) ;
V_124 [ V_5 ] -> V_110 = F_253 ( V_124 [ V_5 ] -> V_339 ) ;
V_124 [ V_5 ] -> V_14 = V_14 ;
V_19 = F_45 ( V_124 [ V_5 ] ) ;
if ( V_19 < 0 ) {
F_54 ( V_12 ) ;
V_12 -> V_124 [ V_5 ] = NULL ;
goto V_457;
}
V_12 -> V_124 [ V_5 ] = V_124 [ V_5 ] ;
}
F_254 ( & V_12 -> V_458 ) ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_19 = F_60 ( V_14 , & V_12 -> V_458 , & V_144 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_51 ) ;
goto V_459;
}
V_12 -> V_21 = V_21 ;
V_153 = F_61 () ;
if ( V_153 < 0 ) {
F_10 ( V_14 , L_52 ) ;
V_19 = V_153 ;
goto V_460;
}
V_12 -> V_153 = ( T_3 ) V_153 ;
F_67 ( V_12 -> V_153 ) ;
F_87 ( V_12 , & V_193 , V_12 -> V_21 -> V_54 [ V_271 ] ) ;
V_19 = F_76 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_53 ) ;
goto V_461;
}
V_19 = F_238 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_54 ) ;
goto V_462;
}
F_110 (dpaa_fq, tmp, &priv->dpaa_fq_list, list) {
V_19 = F_92 ( V_125 , false ) ;
if ( V_19 < 0 )
goto V_145;
}
V_12 -> V_49 = F_239 ( & V_12 -> V_245 [ V_271 ] ) ;
V_12 -> V_361 = F_239 ( & V_12 -> V_245 [ V_269 ] ) ;
V_19 = F_116 ( V_21 , V_124 , V_123 , & V_144 ,
& V_12 -> V_245 [ 0 ] , V_14 ) ;
if ( V_19 )
goto V_463;
V_12 -> V_17 = F_237 ( V_14 , * V_12 -> V_17 ) ;
if ( ! V_12 -> V_17 ) {
F_10 ( V_14 , L_55 ) ;
V_19 = - V_150 ;
goto V_464;
}
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
}
V_12 -> V_72 = 1 ;
F_29 ( V_7 , V_12 -> V_72 * V_80 ) ;
V_19 = F_230 ( V_7 ) ;
if ( V_19 < 0 )
goto V_465;
V_19 = F_2 ( V_7 , & V_9 , V_10 ) ;
if ( V_19 < 0 )
goto V_466;
F_255 ( & V_7 -> V_14 ) ;
F_256 ( V_12 , V_467 , V_7 , L_56 ,
V_7 -> V_468 ) ;
return 0 ;
V_466:
V_465:
F_232 ( V_7 ) ;
V_464:
V_463:
F_109 ( V_14 , & V_12 -> V_458 ) ;
V_145:
F_257 ( & V_12 -> V_231 ) ;
F_82 ( V_12 -> V_231 . V_169 ) ;
V_462:
F_257 ( & V_12 -> V_162 . V_160 ) ;
F_82 ( V_12 -> V_162 . V_160 . V_169 ) ;
V_461:
V_460:
F_54 ( V_12 ) ;
V_457:
V_459:
V_456:
V_452:
F_244 ( V_14 , NULL ) ;
F_258 ( V_7 ) ;
V_448:
for ( V_5 = 0 ; V_5 < V_123 && V_124 [ V_5 ] ; V_5 ++ ) {
if ( F_259 ( & V_124 [ V_5 ] -> V_109 ) == 0 )
F_260 ( V_14 , V_124 [ V_5 ] ) ;
}
return V_19 ;
}
static int F_261 ( struct V_81 * V_82 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_19 ;
V_14 = & V_82 -> V_14 ;
V_7 = F_34 ( V_14 ) ;
V_12 = F_3 ( V_7 ) ;
F_262 ( V_14 ) ;
F_244 ( V_14 , NULL ) ;
F_263 ( V_7 ) ;
V_19 = F_109 ( V_14 , & V_12 -> V_458 ) ;
F_257 ( & V_12 -> V_231 ) ;
F_82 ( V_12 -> V_231 . V_169 ) ;
F_257 ( & V_12 -> V_162 . V_160 ) ;
F_82 ( V_12 -> V_162 . V_160 . V_169 ) ;
F_232 ( V_7 ) ;
F_54 ( V_12 ) ;
F_258 ( V_7 ) ;
return V_19 ;
}
static int T_10 F_264 ( void )
{
int V_19 ;
F_83 ( L_57 ) ;
V_469 = F_265 () ;
V_470 = F_266 () ;
V_19 = F_267 ( & V_471 ) ;
if ( V_19 < 0 )
F_46 ( L_58 , V_19 ) ;
return V_19 ;
}
static void T_11 F_268 ( void )
{
F_269 ( & V_471 ) ;
F_65 () ;
}
