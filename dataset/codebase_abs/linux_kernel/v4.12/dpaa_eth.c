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
static int F_24 ( struct V_6 * V_7 , T_4 V_67 , T_5 V_68 ,
struct V_69 * V_70 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
T_2 V_71 ;
int V_5 ;
if ( V_70 -> type != V_72 )
return - V_73 ;
V_70 -> V_74 -> V_75 = V_76 ;
V_71 = V_70 -> V_74 -> V_71 ;
if ( V_71 == V_12 -> V_71 )
return 0 ;
if ( ! V_71 ) {
F_25 ( V_7 ) ;
goto V_77;
}
if ( V_71 > V_78 ) {
F_26 ( V_7 , L_4 ,
V_78 ) ;
return - V_73 ;
}
F_27 ( V_7 , V_71 ) ;
for ( V_5 = 0 ; V_5 < V_71 ; V_5 ++ )
F_28 ( V_7 , V_5 , V_79 ,
V_5 * V_79 ) ;
V_77:
V_12 -> V_71 = V_71 ? : 1 ;
F_29 ( V_7 , V_12 -> V_71 * V_79 ) ;
return 0 ;
}
static struct V_51 * F_30 ( struct V_80 * V_81 )
{
struct V_80 * V_82 ;
struct V_83 * V_84 ;
struct V_13 * V_85 , * V_14 ;
struct V_86 * V_87 ;
struct V_51 * V_21 ;
V_85 = & V_81 -> V_14 ;
V_84 = V_85 -> V_88 ;
if ( ! V_84 )
return F_31 ( - V_89 ) ;
V_87 = V_84 -> V_87 ;
V_82 = F_32 ( V_87 ) ;
if ( ! V_82 ) {
F_10 ( V_85 , L_5 ,
V_87 -> V_90 ) ;
F_33 ( V_87 ) ;
return F_31 ( - V_73 ) ;
}
F_33 ( V_87 ) ;
V_14 = & V_82 -> V_14 ;
V_21 = F_34 ( V_14 ) ;
if ( ! V_21 ) {
F_10 ( V_85 , L_6 ,
F_35 ( V_14 ) ) ;
return F_31 ( - V_73 ) ;
}
return V_21 ;
}
static int F_36 ( struct V_6 * V_7 , void * V_22 )
{
const struct V_11 * V_12 ;
struct V_51 * V_21 ;
struct V_91 V_92 ;
int V_19 ;
V_12 = F_3 ( V_7 ) ;
memcpy ( V_92 . V_93 , V_7 -> V_45 , V_94 ) ;
V_19 = F_37 ( V_7 , V_22 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_95 , V_7 , L_7 , V_19 ) ;
return V_19 ;
}
V_21 = V_12 -> V_21 ;
V_19 = V_21 -> V_96 ( V_21 -> V_97 ,
( V_98 * ) V_7 -> V_45 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_95 , V_7 , L_8 ,
V_19 ) ;
F_37 ( V_7 , & V_92 ) ;
return V_19 ;
}
return 0 ;
}
static void F_38 ( struct V_6 * V_7 )
{
const struct V_11 * V_12 ;
int V_19 ;
V_12 = F_3 ( V_7 ) ;
if ( ! ! ( V_7 -> V_99 & V_100 ) != V_12 -> V_21 -> V_101 ) {
V_12 -> V_21 -> V_101 = ! V_12 -> V_21 -> V_101 ;
V_19 = V_12 -> V_21 -> V_102 ( V_12 -> V_21 -> V_97 ,
V_12 -> V_21 -> V_101 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_95 , V_7 ,
L_9 ,
V_19 ) ;
}
V_19 = V_12 -> V_21 -> V_103 ( V_7 , V_12 -> V_21 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_95 , V_7 , L_10 ,
V_19 ) ;
}
static struct V_104 * F_39 ( int V_105 )
{
if ( F_40 ( V_105 < 0 || V_105 >= V_106 ) )
return NULL ;
return V_107 [ V_105 ] ;
}
static bool F_41 ( int V_105 )
{
if ( F_39 ( V_105 ) ) {
F_42 ( & V_107 [ V_105 ] -> V_108 ) ;
return true ;
}
return false ;
}
static void F_43 ( int V_105 , struct V_104 * V_104 )
{
V_107 [ V_105 ] = V_104 ;
F_44 ( & V_104 -> V_108 , 1 ) ;
}
static int F_45 ( struct V_104 * V_104 )
{
int V_19 ;
if ( V_104 -> V_109 == 0 || V_104 -> V_110 == 0 ) {
F_46 ( L_11 ,
V_111 ) ;
return - V_73 ;
}
if ( V_104 -> V_105 != V_112 &&
F_41 ( V_104 -> V_105 ) )
return 0 ;
if ( V_104 -> V_105 == V_112 ) {
V_104 -> V_113 = F_47 () ;
if ( ! V_104 -> V_113 ) {
F_46 ( L_12 ,
V_111 ) ;
return - V_89 ;
}
V_104 -> V_105 = ( T_2 ) F_48 ( V_104 -> V_113 ) ;
}
if ( V_104 -> V_114 ) {
V_19 = V_104 -> V_114 ( V_104 ) ;
if ( V_19 )
goto V_115;
}
F_43 ( V_104 -> V_105 , V_104 ) ;
return 0 ;
V_115:
F_46 ( L_13 , V_111 ) ;
F_49 ( V_104 -> V_113 ) ;
return V_19 ;
}
static void F_50 ( struct V_104 * V_116 )
{
T_2 V_117 = 8 ;
int V_118 ;
do {
struct V_119 V_120 [ 8 ] ;
int V_5 ;
V_118 = F_51 ( V_116 -> V_113 , V_120 , V_117 ) ;
if ( V_118 < 0 ) {
if ( V_117 == 8 ) {
V_117 = 1 ;
V_118 = 1 ;
continue;
} else {
break;
}
}
if ( V_116 -> V_121 )
for ( V_5 = 0 ; V_5 < V_117 ; V_5 ++ )
V_116 -> V_121 ( V_116 , & V_120 [ V_5 ] ) ;
} while ( V_118 > 0 );
}
static void F_52 ( struct V_104 * V_104 )
{
struct V_104 * V_116 = F_39 ( V_104 -> V_105 ) ;
if ( ! V_116 )
return;
if ( ! F_53 ( & V_116 -> V_108 ) )
return;
if ( V_116 -> V_121 )
F_50 ( V_116 ) ;
V_107 [ V_116 -> V_105 ] = NULL ;
F_49 ( V_116 -> V_113 ) ;
}
static void F_54 ( struct V_11 * V_12 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ )
F_52 ( V_12 -> V_123 [ V_5 ] ) ;
}
static inline void F_55 ( struct V_124 * V_125 , int V_126 )
{
switch ( V_125 -> V_127 ) {
case V_128 :
case V_129 :
V_125 -> V_130 = 1 ;
break;
case V_131 :
case V_132 :
V_125 -> V_130 = 5 ;
break;
case V_133 :
V_125 -> V_130 = 6 ;
break;
case V_134 :
switch ( V_126 / V_79 ) {
case 0 :
V_125 -> V_130 = 6 ;
break;
case 1 :
V_125 -> V_130 = 2 ;
break;
case 2 :
V_125 -> V_130 = 1 ;
break;
case 3 :
V_125 -> V_130 = 0 ;
break;
default:
F_56 ( 1 , L_14 ,
V_135 ) ;
}
break;
default:
F_56 ( 1 , L_15 ,
V_125 -> V_127 , V_125 -> V_136 ) ;
}
}
static struct V_124 * F_57 ( struct V_13 * V_14 ,
T_4 V_24 , T_4 V_137 ,
struct V_138 * V_139 ,
enum V_140 V_127 )
{
struct V_124 * V_124 ;
int V_5 ;
V_124 = F_58 ( V_14 , sizeof( * V_124 ) * V_137 ,
V_141 ) ;
if ( ! V_124 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_137 ; V_5 ++ ) {
V_124 [ V_5 ] . V_127 = V_127 ;
V_124 [ V_5 ] . V_136 = V_24 ? V_24 + V_5 : 0 ;
F_59 ( & V_124 [ V_5 ] . V_139 , V_139 ) ;
}
for ( V_5 = 0 ; V_5 < V_137 ; V_5 ++ )
F_55 ( V_124 + V_5 , V_5 ) ;
return V_124 ;
}
static int F_60 ( struct V_13 * V_14 , struct V_138 * V_139 ,
struct V_142 * V_143 )
{
struct V_124 * V_124 ;
V_124 = F_57 ( V_14 , 0 , 1 , V_139 , V_131 ) ;
if ( ! V_124 )
goto V_144;
V_143 -> V_145 = & V_124 [ 0 ] ;
V_124 = F_57 ( V_14 , 0 , 1 , V_139 , V_133 ) ;
if ( ! V_124 )
goto V_144;
V_143 -> V_146 = & V_124 [ 0 ] ;
if ( ! F_57 ( V_14 , 0 , V_135 , V_139 , V_129 ) )
goto V_144;
V_124 = F_57 ( V_14 , 0 , 1 , V_139 , V_132 ) ;
if ( ! V_124 )
goto V_144;
V_143 -> V_147 = & V_124 [ 0 ] ;
V_124 = F_57 ( V_14 , 0 , 1 , V_139 , V_128 ) ;
if ( ! V_124 )
goto V_144;
V_143 -> V_148 = & V_124 [ 0 ] ;
if ( ! F_57 ( V_14 , 0 , V_135 , V_139 , V_134 ) )
goto V_144;
return 0 ;
V_144:
F_10 ( V_14 , L_16 ) ;
return - V_149 ;
}
static int F_61 ( void )
{
F_62 ( & V_150 ) ;
if ( ! V_151 ) {
T_4 V_113 ;
int V_118 ;
V_118 = F_63 ( & V_113 ) ;
if ( ! V_118 )
V_151 = V_113 ;
}
F_64 ( & V_150 ) ;
if ( ! V_151 )
return - V_149 ;
return V_151 ;
}
static void F_65 ( void )
{
F_66 ( V_151 ) ;
}
static void F_67 ( T_3 V_152 )
{
T_4 V_113 = F_68 ( V_152 ) ;
const T_6 * V_153 = F_69 () ;
struct V_154 * V_155 ;
int V_156 ;
F_70 (cpu, cpus) {
V_155 = F_71 ( V_156 ) ;
F_72 ( V_155 , V_113 ) ;
}
}
static void F_73 ( struct V_154 * V_157 , struct V_158 * V_159 ,
int V_160 )
{
struct V_11 * V_12 = (struct V_11 * ) F_74 ( V_159 ,
struct V_11 , V_161 . V_159 ) ;
if ( V_160 ) {
V_12 -> V_161 . V_162 = V_57 ;
F_12 ( V_12 -> V_7 ) ;
V_12 -> V_161 . V_163 ++ ;
} else {
V_12 -> V_161 . V_164 +=
( V_57 - V_12 -> V_161 . V_162 ) ;
F_75 ( V_12 -> V_7 ) ;
}
}
static int F_76 ( struct V_11 * V_12 )
{
struct V_165 V_166 ;
T_4 V_167 ;
int V_19 ;
V_19 = F_77 ( & V_12 -> V_161 . V_159 . V_168 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_17 ,
V_111 , V_19 ) ;
goto V_169;
}
V_12 -> V_161 . V_159 . V_170 = F_73 ;
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_171 = F_79 ( V_172 | V_173 ) ;
V_166 . V_159 . V_174 = V_175 ;
if ( V_12 -> V_21 -> V_176 & V_177 )
V_167 = V_178 ;
else
V_167 = V_179 ;
F_80 ( & V_166 . V_159 . V_180 , V_167 , 1 ) ;
V_166 . V_171 |= F_79 ( V_181 ) ;
V_166 . V_159 . V_182 = V_175 ;
V_19 = F_81 ( & V_12 -> V_161 . V_159 , V_183 ,
& V_166 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_18 ,
V_111 , V_19 , V_12 -> V_161 . V_159 . V_168 ) ;
F_82 ( V_12 -> V_161 . V_159 . V_168 ) ;
goto V_169;
}
if ( F_78 ( V_12 ) )
F_83 ( L_19 ,
V_12 -> V_161 . V_159 . V_168 , V_12 -> V_21 -> V_22 ,
V_12 -> V_161 . V_159 . V_184 ) ;
V_169:
return V_19 ;
}
static inline void F_84 ( const struct V_11 * V_12 ,
struct V_124 * V_125 ,
const struct V_185 * V_186 )
{
V_125 -> V_187 = * V_186 ;
V_125 -> V_7 = V_12 -> V_7 ;
V_125 -> V_99 = V_188 ;
V_125 -> V_152 = V_12 -> V_152 ;
}
static inline void F_85 ( const struct V_11 * V_12 ,
struct V_124 * V_125 ,
struct V_189 * V_54 ,
const struct V_185 * V_186 )
{
V_125 -> V_187 = * V_186 ;
V_125 -> V_7 = V_12 -> V_7 ;
if ( V_54 ) {
V_125 -> V_99 = V_190 ;
V_125 -> V_152 = ( T_3 ) F_86 ( V_54 ) ;
} else {
V_125 -> V_99 = V_191 ;
}
}
static void F_87 ( struct V_11 * V_12 ,
const struct V_192 * V_193 ,
struct V_189 * V_194 )
{
int V_195 = 0 , V_196 = 0 , V_197 = 0 , V_156 ;
const T_6 * V_198 = F_69 () ;
T_3 V_199 [ V_200 ] ;
struct V_124 * V_125 ;
F_70 (cpu, affine_cpus)
V_199 [ V_197 ++ ] = F_88 ( V_156 ) ;
if ( V_197 == 0 )
F_10 ( V_12 -> V_7 -> V_14 . V_15 ,
L_20 ) ;
F_89 (fq, &priv->dpaa_fq_list, list) {
switch ( V_125 -> V_127 ) {
case V_133 :
F_84 ( V_12 , V_125 , & V_193 -> V_146 ) ;
break;
case V_131 :
F_84 ( V_12 , V_125 , & V_193 -> V_145 ) ;
break;
case V_134 :
F_85 ( V_12 , V_125 , V_194 ,
& V_193 -> V_201 ) ;
if ( V_195 < V_135 )
V_12 -> V_202 [ V_195 ++ ] = & V_125 -> V_187 ;
break;
case V_129 :
V_12 -> V_203 [ V_196 ++ ] = & V_125 -> V_187 ;
case V_128 :
F_84 ( V_12 , V_125 , & V_193 -> V_148 ) ;
break;
case V_132 :
F_84 ( V_12 , V_125 , & V_193 -> V_147 ) ;
break;
default:
F_90 ( V_12 -> V_7 -> V_14 . V_15 ,
L_21 ) ;
break;
}
}
while ( V_195 < V_135 ) {
F_89 (fq, &priv->dpaa_fq_list, list) {
if ( V_125 -> V_127 != V_134 )
continue;
V_12 -> V_202 [ V_195 ++ ] = & V_125 -> V_187 ;
if ( V_195 == V_135 )
break;
}
}
}
static inline int F_91 ( const struct V_11 * V_12 ,
struct V_185 * V_204 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_135 ; V_5 ++ )
if ( V_12 -> V_202 [ V_5 ] == V_204 )
return V_5 ;
return - V_73 ;
}
static int F_92 ( struct V_124 * V_124 , bool V_205 )
{
const struct V_11 * V_12 ;
struct V_185 * V_206 = NULL ;
struct V_207 V_208 ;
struct V_13 * V_14 ;
struct V_185 * V_125 ;
int V_209 ;
int V_19 ;
V_12 = F_3 ( V_124 -> V_7 ) ;
V_14 = V_124 -> V_7 -> V_14 . V_15 ;
if ( V_124 -> V_136 == 0 )
V_124 -> V_99 |= V_210 ;
V_124 -> V_211 = ! ( V_124 -> V_99 & V_191 ) ;
V_19 = F_93 ( V_124 -> V_136 , V_124 -> V_99 , & V_124 -> V_187 ) ;
if ( V_19 ) {
F_10 ( V_14 , L_22 ) ;
return V_19 ;
}
V_125 = & V_124 -> V_187 ;
if ( V_124 -> V_211 ) {
memset ( & V_208 , 0 , sizeof( V_208 ) ) ;
V_208 . V_171 = F_79 ( V_212 ) ;
V_208 . V_213 . V_214 = F_79 ( V_215 ) ;
if ( V_124 -> V_127 == V_128 )
V_208 . V_213 . V_214 |= F_79 ( V_216 ) ;
V_208 . V_171 |= F_79 ( V_217 ) ;
F_94 ( & V_208 . V_213 , V_124 -> V_152 , V_124 -> V_130 ) ;
if ( V_124 -> V_127 == V_134 ||
V_124 -> V_127 == V_128 ||
V_124 -> V_127 == V_129 ) {
V_208 . V_171 |= F_79 ( V_218 ) ;
V_208 . V_213 . V_214 |= F_79 ( V_219 ) ;
V_208 . V_213 . V_220 = ( T_2 ) V_12 -> V_161 . V_159 . V_168 ;
V_208 . V_171 |= F_79 ( V_221 ) ;
F_95 ( & V_208 . V_213 , V_222 ) ;
F_96 ( & V_208 . V_213 ,
F_97 ( sizeof( struct V_223 ) +
V_12 -> V_49 ,
( T_1 ) V_224 ) ) ;
}
if ( V_205 ) {
V_208 . V_171 |= F_79 ( V_225 ) ;
F_98 ( & V_208 . V_213 , V_226 , 1 ) ;
V_208 . V_213 . V_214 = F_79 ( V_227 ) ;
}
if ( V_124 -> V_127 == V_134 ) {
V_209 = F_91 ( V_12 , & V_124 -> V_187 ) ;
if ( V_209 >= 0 )
V_206 = V_12 -> V_203 [ V_209 ] ;
if ( V_206 ) {
V_208 . V_171 |=
F_79 ( V_228 ) ;
F_99 ( & V_208 . V_213 ,
0x1e00000080000000ULL ) ;
}
}
if ( V_12 -> V_229 &&
( V_124 -> V_127 == V_133 ||
V_124 -> V_127 == V_131 ) ) {
V_208 . V_171 |= F_79 ( V_218 ) ;
V_208 . V_213 . V_214 |= F_79 ( V_219 ) ;
V_208 . V_213 . V_220 = ( T_2 ) V_12 -> V_230 . V_168 ;
V_208 . V_171 |= F_79 ( V_221 ) ;
F_95 ( & V_208 . V_213 , V_222 ) ;
F_96 ( & V_208 . V_213 ,
F_97 ( sizeof( struct V_223 ) +
V_12 -> V_49 ,
( T_1 ) V_224 ) ) ;
}
if ( V_124 -> V_99 & V_188 ) {
V_208 . V_171 |= F_79 ( V_228 ) ;
V_208 . V_213 . V_214 |= F_79 ( V_231 |
V_232 ) ;
V_208 . V_213 . V_233 . V_234 . V_235 =
V_236 | V_237 |
V_238 ;
F_100 ( & V_208 . V_213 , 1 , 2 ,
F_101 ( sizeof( struct V_185 ) ,
64 ) ) ;
}
V_19 = F_102 ( V_125 , V_239 , & V_208 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_23 ,
F_103 ( V_125 ) , V_19 ) ;
F_104 ( V_125 ) ;
return V_19 ;
}
}
V_124 -> V_136 = F_103 ( V_125 ) ;
return 0 ;
}
static int F_105 ( struct V_13 * V_14 , struct V_185 * V_125 )
{
const struct V_11 * V_12 ;
struct V_124 * V_124 ;
int V_19 , error ;
V_19 = 0 ;
V_124 = F_74 ( V_125 , struct V_124 , V_187 ) ;
V_12 = F_3 ( V_124 -> V_7 ) ;
if ( V_124 -> V_211 ) {
V_19 = F_106 ( V_125 , NULL ) ;
if ( V_19 < 0 && F_78 ( V_12 ) )
F_10 ( V_14 , L_24 ,
F_103 ( V_125 ) , V_19 ) ;
error = F_107 ( V_125 ) ;
if ( error < 0 && F_78 ( V_12 ) ) {
F_10 ( V_14 , L_25 ,
F_103 ( V_125 ) , error ) ;
if ( V_19 >= 0 )
V_19 = error ;
}
}
F_104 ( V_125 ) ;
F_108 ( & V_124 -> V_139 ) ;
return V_19 ;
}
static int F_109 ( struct V_13 * V_14 , struct V_138 * V_139 )
{
struct V_124 * V_124 , * V_240 ;
int V_19 , error ;
V_19 = 0 ;
F_110 (dpaa_fq, tmp, list, list) {
error = F_105 ( V_14 , (struct V_185 * ) V_124 ) ;
if ( error < 0 && V_19 >= 0 )
V_19 = error ;
}
return V_19 ;
}
static int F_111 ( struct V_189 * V_54 , struct V_124 * V_241 ,
struct V_124 * V_242 ,
struct V_243 * V_244 )
{
struct V_245 V_246 ;
struct V_247 V_248 ;
int V_19 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
memset ( & V_246 , 0 , sizeof( V_246 ) ) ;
V_246 . V_249 = V_244 -> V_249 ;
V_246 . V_250 = true ;
V_246 . V_251 = true ;
V_246 . V_252 = false ;
V_246 . V_253 = V_254 ;
V_248 . V_255 . V_256 . V_257 = V_241 -> V_136 ;
V_248 . V_255 . V_256 . V_258 = V_242 -> V_136 ;
V_19 = F_112 ( V_54 , & V_248 ) ;
if ( V_19 ) {
F_46 ( L_26 , V_111 ) ;
return V_19 ;
}
V_19 = F_113 ( V_54 , & V_246 ) ;
if ( V_19 ) {
F_46 ( L_27 ,
V_111 ) ;
return V_19 ;
}
V_19 = F_114 ( V_54 ) ;
if ( V_19 )
F_46 ( L_28 , V_111 ) ;
return V_19 ;
}
static int F_115 ( struct V_189 * V_54 , struct V_104 * * V_259 ,
T_1 V_137 , struct V_124 * V_241 ,
struct V_124 * V_242 ,
struct V_243 * V_244 )
{
struct V_245 V_246 ;
struct V_260 * V_261 ;
struct V_247 V_248 ;
int V_5 , V_19 ;
memset ( & V_248 , 0 , sizeof( V_248 ) ) ;
memset ( & V_246 , 0 , sizeof( V_246 ) ) ;
V_246 . V_249 = V_244 -> V_249 ;
V_246 . V_250 = true ;
V_246 . V_251 = true ;
V_246 . V_252 = false ;
V_246 . V_253 = V_254 ;
V_261 = & V_248 . V_255 . V_262 ;
V_261 -> V_257 = V_241 -> V_136 ;
V_261 -> V_258 = V_242 -> V_136 ;
V_137 = F_97 ( F_15 ( V_261 -> V_263 . V_264 ) , V_137 ) ;
V_261 -> V_263 . V_265 = ( T_2 ) V_137 ;
for ( V_5 = 0 ; V_5 < V_137 ; V_5 ++ ) {
V_261 -> V_263 . V_264 [ V_5 ] . V_266 = V_259 [ V_5 ] -> V_105 ;
V_261 -> V_263 . V_264 [ V_5 ] . V_109 = ( T_3 ) V_259 [ V_5 ] -> V_109 ;
}
V_19 = F_112 ( V_54 , & V_248 ) ;
if ( V_19 ) {
F_46 ( L_26 , V_111 ) ;
return V_19 ;
}
V_19 = F_113 ( V_54 , & V_246 ) ;
if ( V_19 ) {
F_46 ( L_27 ,
V_111 ) ;
return V_19 ;
}
V_19 = F_114 ( V_54 ) ;
if ( V_19 )
F_46 ( L_28 , V_111 ) ;
return V_19 ;
}
static int F_116 ( struct V_51 * V_21 ,
struct V_104 * * V_259 , T_1 V_137 ,
struct V_142 * V_143 ,
struct V_243 * V_244 ,
struct V_13 * V_14 )
{
struct V_189 * V_267 = V_21 -> V_54 [ V_268 ] ;
struct V_189 * V_269 = V_21 -> V_54 [ V_270 ] ;
int V_19 ;
V_19 = F_111 ( V_269 , V_143 -> V_147 ,
V_143 -> V_148 , & V_244 [ V_270 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_115 ( V_267 , V_259 , V_137 , V_143 -> V_145 ,
V_143 -> V_146 , & V_244 [ V_268 ] ) ;
return V_19 ;
}
static int F_117 ( const struct V_104 * V_104 ,
struct V_119 * V_120 , int V_2 )
{
int V_19 ;
V_19 = F_118 ( V_104 -> V_113 , V_120 , V_2 ) ;
if ( F_119 ( F_40 ( V_19 ) ) && V_104 -> V_121 )
while ( V_2 -- > 0 )
V_104 -> V_121 ( V_104 , & V_120 [ V_2 ] ) ;
return V_2 ;
}
static void F_120 ( struct V_271 * V_272 )
{
struct V_119 V_120 [ V_273 ] ;
struct V_104 * V_104 ;
int V_5 = 0 , V_66 ;
memset ( V_120 , 0 , sizeof( V_120 ) ) ;
do {
V_104 = F_39 ( V_272 [ V_5 ] . V_105 ) ;
if ( ! V_104 )
return;
V_66 = 0 ;
do {
F_40 ( F_121 ( & V_272 [ V_5 ] ) ) ;
F_122 ( & V_120 [ V_66 ] , F_123 ( & V_272 [ V_5 ] ) ) ;
V_66 ++ ; V_5 ++ ;
} while ( V_66 < F_15 ( V_120 ) &&
! F_124 ( & V_272 [ V_5 - 1 ] ) &&
V_272 [ V_5 - 1 ] . V_105 == V_272 [ V_5 ] . V_105 );
F_117 ( V_104 , V_120 , V_66 ) ;
} while ( ! F_124 ( & V_272 [ V_5 - 1 ] ) );
}
static void F_125 ( const struct V_6 * V_7 ,
const struct V_274 * V_275 )
{
struct V_271 * V_272 ;
struct V_104 * V_104 ;
struct V_119 V_120 ;
T_7 V_22 ;
void * V_276 ;
V_120 . V_277 = 0 ;
F_122 ( & V_120 , F_126 ( V_275 ) ) ;
V_104 = F_39 ( V_275 -> V_105 ) ;
if ( ! V_104 )
return;
if ( F_127 ( V_275 ) == V_278 ) {
V_276 = F_128 ( F_126 ( V_275 ) ) ;
V_272 = V_276 + F_129 ( V_275 ) ;
F_130 ( V_104 -> V_14 , F_126 ( V_275 ) , V_104 -> V_109 ,
V_279 ) ;
F_120 ( V_272 ) ;
V_22 = F_131 ( V_104 -> V_14 , V_276 , V_104 -> V_109 ,
V_279 ) ;
if ( F_132 ( V_104 -> V_14 , V_22 ) ) {
F_10 ( V_104 -> V_14 , L_29 ) ;
return;
}
F_122 ( & V_120 , V_22 ) ;
}
F_117 ( V_104 , & V_120 , 1 ) ;
}
static void F_133 ( struct V_16 * V_17 ,
const union V_280 * V_281 )
{
switch ( V_281 -> V_282 . V_283 & V_284 ) {
case V_285 :
V_17 -> V_286 . V_287 ++ ;
break;
case V_288 :
V_17 -> V_286 . V_289 ++ ;
break;
case V_290 :
V_17 -> V_286 . V_291 ++ ;
break;
case V_292 :
V_17 -> V_286 . V_293 ++ ;
break;
case V_294 :
V_17 -> V_286 . V_295 ++ ;
break;
case V_296 :
V_17 -> V_286 . V_297 ++ ;
break;
case V_298 :
V_17 -> V_286 . V_299 ++ ;
break;
case V_300 :
V_17 -> V_286 . V_301 ++ ;
break;
}
}
static int F_134 ( struct V_11 * V_12 ,
struct V_223 * V_302 ,
struct V_274 * V_275 ,
char * V_303 )
{
struct V_304 * V_305 ;
T_3 V_306 = F_135 ( V_302 -> V_307 ) ;
struct V_308 * V_309 = NULL ;
struct V_310 * V_311 ;
int V_312 = 0 ;
T_2 V_313 ;
if ( V_302 -> V_314 != V_315 )
return 0 ;
V_305 = (struct V_304 * ) V_303 ;
if ( V_306 == V_316 ) {
F_136 ( V_302 ) ;
V_306 = F_135 ( F_137 ( V_302 ) -> V_317 ) ;
}
switch ( V_306 ) {
case V_318 :
V_305 -> V_319 = F_79 ( V_320 ) ;
V_311 = F_138 ( V_302 ) ;
F_40 ( ! V_311 ) ;
V_313 = V_311 -> V_307 ;
break;
case V_321 :
V_305 -> V_319 = F_79 ( V_322 ) ;
V_309 = F_139 ( V_302 ) ;
F_40 ( ! V_309 ) ;
V_313 = V_309 -> V_323 ;
break;
default:
if ( F_140 () )
F_141 ( V_12 , V_324 , V_12 -> V_7 ,
L_30 ,
F_135 ( V_302 -> V_307 ) ) ;
V_312 = - V_325 ;
goto V_326;
}
switch ( V_313 ) {
case V_327 :
V_305 -> V_328 = V_329 ;
break;
case V_330 :
V_305 -> V_328 = V_331 ;
break;
default:
if ( F_140 () )
F_141 ( V_12 , V_324 , V_12 -> V_7 ,
L_31 ,
V_313 ) ;
V_312 = - V_325 ;
goto V_326;
}
V_305 -> V_332 [ 0 ] = ( T_2 ) F_142 ( V_302 ) ;
V_305 -> V_333 = ( T_2 ) F_143 ( V_302 ) ;
V_275 -> V_334 |= F_144 ( V_335 | V_336 ) ;
V_326:
return V_312 ;
}
static int F_145 ( const struct V_104 * V_104 )
{
struct V_13 * V_14 = V_104 -> V_14 ;
struct V_119 V_120 [ 8 ] ;
T_7 V_22 ;
void * V_337 ;
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_337 = F_146 ( V_104 -> V_338 ) ;
if ( F_119 ( ! V_337 ) ) {
F_10 ( V_14 , L_32 ,
V_104 -> V_338 ) ;
goto V_339;
}
V_337 = F_147 ( V_337 , V_340 ) ;
V_22 = F_131 ( V_14 , V_337 ,
V_104 -> V_109 , V_279 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_104 -> V_14 , L_33 ) ;
goto V_339;
}
V_120 [ V_5 ] . V_277 = 0 ;
F_122 ( & V_120 [ V_5 ] , V_22 ) ;
}
V_341:
return F_117 ( V_104 , V_120 , V_5 ) ;
V_339:
F_148 ( 1 , L_34 ) ;
F_122 ( & V_120 [ V_5 ] , 0 ) ;
if ( F_149 ( V_5 ) )
goto V_341;
return 0 ;
}
static int F_150 ( struct V_104 * V_104 )
{
int V_5 ;
F_4 (i) {
int * V_342 = F_5 ( V_104 -> V_343 , V_5 ) ;
int V_66 ;
for ( V_66 = 0 ; V_66 < V_104 -> V_110 ; V_66 += 8 )
* V_342 += F_145 ( V_104 ) ;
}
return 0 ;
}
static int F_151 ( struct V_104 * V_104 , int * V_344 )
{
int V_137 = * V_344 ;
int V_345 ;
if ( F_119 ( V_137 < V_346 ) ) {
do {
V_345 = F_145 ( V_104 ) ;
if ( F_119 ( ! V_345 ) ) {
break;
}
V_137 += V_345 ;
} while ( V_137 < V_347 );
* V_344 = V_137 ;
if ( F_119 ( V_137 < V_347 ) )
return - V_149 ;
}
return 0 ;
}
static int F_152 ( struct V_11 * V_12 )
{
struct V_104 * V_104 ;
int * V_344 ;
int V_3 , V_5 ;
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ ) {
V_104 = V_12 -> V_123 [ V_5 ] ;
if ( ! V_104 )
return - V_73 ;
V_344 = F_19 ( V_104 -> V_343 ) ;
V_3 = F_151 ( V_104 , V_344 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static struct V_223 * F_153 ( const struct V_11 * V_12 ,
const struct V_274 * V_275 )
{
const enum V_348 V_349 = V_350 ;
struct V_13 * V_14 = V_12 -> V_7 -> V_14 . V_15 ;
T_7 V_22 = F_126 ( V_275 ) ;
const struct V_271 * V_272 ;
struct V_223 * * V_351 , * V_302 ;
int V_352 , V_5 ;
V_351 = (struct V_223 * * ) F_128 ( V_22 ) ;
V_302 = * V_351 ;
if ( F_119 ( F_127 ( V_275 ) == V_278 ) ) {
V_352 = F_154 ( V_302 ) -> V_352 ;
F_130 ( V_14 , V_22 , F_129 ( V_275 ) +
sizeof( struct V_271 ) * ( 1 + V_352 ) ,
V_349 ) ;
V_272 = F_128 ( V_22 + F_129 ( V_275 ) ) ;
F_130 ( V_14 , F_155 ( & V_272 [ 0 ] ) ,
F_156 ( & V_272 [ 0 ] ) , V_349 ) ;
for ( V_5 = 1 ; V_5 < V_352 ; V_5 ++ ) {
F_40 ( F_121 ( & V_272 [ V_5 ] ) ) ;
F_157 ( V_14 , F_155 ( & V_272 [ V_5 ] ) ,
F_156 ( & V_272 [ V_5 ] ) , V_349 ) ;
}
F_158 ( F_128 ( V_22 ) ) ;
} else {
F_130 ( V_14 , V_22 ,
F_159 ( V_302 ) - ( T_2 * ) V_351 , V_349 ) ;
}
return V_302 ;
}
static T_2 F_160 ( const struct V_11 * V_12 , const struct V_274 * V_275 )
{
if ( ( V_12 -> V_7 -> V_36 & V_38 ) &&
( F_161 ( V_275 -> V_353 ) & V_354 ) )
return V_355 ;
return V_356 ;
}
static struct V_223 * F_162 ( const struct V_11 * V_12 ,
const struct V_274 * V_275 )
{
T_8 V_357 = F_129 ( V_275 ) ;
T_7 V_22 = F_126 ( V_275 ) ;
struct V_104 * V_104 ;
struct V_223 * V_302 ;
void * V_276 ;
V_276 = F_128 ( V_22 ) ;
F_40 ( ! F_163 ( ( unsigned long ) V_276 , V_340 ) ) ;
V_104 = F_39 ( V_275 -> V_105 ) ;
if ( ! V_104 )
goto V_358;
V_302 = F_164 ( V_276 , V_104 -> V_109 +
F_165 ( sizeof( struct V_359 ) ) ) ;
if ( F_119 ( ! V_302 ) ) {
F_148 ( 1 , L_35 ) ;
goto V_358;
}
F_40 ( V_357 != V_12 -> V_360 ) ;
F_166 ( V_302 , V_357 ) ;
F_167 ( V_302 , F_168 ( V_275 ) ) ;
V_302 -> V_314 = F_160 ( V_12 , V_275 ) ;
return V_302 ;
V_358:
F_158 ( V_276 ) ;
return NULL ;
}
static struct V_223 * F_169 ( const struct V_11 * V_12 ,
const struct V_274 * V_275 )
{
T_8 V_357 = F_129 ( V_275 ) ;
T_7 V_22 = F_126 ( V_275 ) ;
const struct V_271 * V_272 ;
struct V_361 * V_361 , * V_362 ;
struct V_104 * V_104 ;
void * V_276 , * V_363 ;
int V_364 , V_365 ;
struct V_223 * V_302 ;
T_7 V_366 ;
int V_367 ;
unsigned int V_368 ;
int * V_342 ;
int V_5 ;
V_276 = F_128 ( V_22 ) ;
F_40 ( ! F_163 ( ( unsigned long ) V_276 , V_340 ) ) ;
V_272 = V_276 + V_357 ;
for ( V_5 = 0 ; V_5 < V_369 ; V_5 ++ ) {
F_40 ( F_121 ( & V_272 [ V_5 ] ) ) ;
V_366 = F_155 ( & V_272 [ V_5 ] ) ;
V_363 = F_128 ( V_366 ) ;
F_40 ( ! F_163 ( ( unsigned long ) V_363 ,
V_340 ) ) ;
V_104 = F_39 ( V_272 [ V_5 ] . V_105 ) ;
if ( ! V_104 )
goto V_370;
V_342 = F_19 ( V_104 -> V_343 ) ;
F_130 ( V_104 -> V_14 , V_366 , V_104 -> V_109 ,
V_279 ) ;
if ( V_5 == 0 ) {
V_368 = V_104 -> V_109 +
F_165 ( sizeof( struct V_359 ) ) ;
V_302 = F_164 ( V_363 , V_368 ) ;
if ( F_40 ( F_119 ( ! V_302 ) ) )
goto V_370;
V_302 -> V_314 = F_160 ( V_12 , V_275 ) ;
F_40 ( V_357 != V_12 -> V_360 ) ;
F_166 ( V_302 , V_357 ) ;
F_167 ( V_302 , F_156 ( & V_272 [ V_5 ] ) ) ;
} else {
V_361 = F_170 ( V_363 ) ;
V_362 = F_171 ( V_363 ) ;
V_367 = ( ( unsigned long ) V_363 &
( V_371 - 1 ) ) +
( F_172 ( V_361 ) - F_172 ( V_362 ) ) ;
V_364 = F_173 ( & V_272 [ V_5 ] ) + V_367 ;
V_365 = F_156 ( & V_272 [ V_5 ] ) ;
F_174 ( V_302 , V_5 - 1 , V_362 , V_364 ,
V_365 , V_104 -> V_109 ) ;
}
( * V_342 ) -- ;
if ( F_124 ( & V_272 [ V_5 ] ) )
break;
}
F_148 ( V_5 == V_369 , L_36 ) ;
F_158 ( V_276 ) ;
return V_302 ;
V_370:
for ( V_5 -- ; V_5 >= 0 ; V_5 -- ) {
V_104 = F_39 ( V_272 [ V_5 ] . V_105 ) ;
if ( V_104 ) {
V_342 = F_19 ( V_104 -> V_343 ) ;
( * V_342 ) ++ ;
}
}
for ( V_5 = 0 ; V_5 < V_369 ; V_5 ++ ) {
V_366 = F_155 ( & V_272 [ V_5 ] ) ;
V_363 = F_128 ( V_366 ) ;
F_158 ( V_363 ) ;
V_104 = F_39 ( V_272 [ V_5 ] . V_105 ) ;
if ( V_104 ) {
V_342 = F_19 ( V_104 -> V_343 ) ;
( * V_342 ) -- ;
}
if ( F_124 ( & V_272 [ V_5 ] ) )
break;
}
F_158 ( V_276 ) ;
return NULL ;
}
static int F_175 ( struct V_11 * V_12 ,
struct V_223 * V_302 , struct V_274 * V_275 ,
int * V_372 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
enum V_348 V_349 ;
unsigned char * V_373 ;
struct V_223 * * V_351 ;
T_7 V_22 ;
int V_19 ;
V_275 -> V_105 = V_112 ;
V_373 = V_302 -> V_277 - V_12 -> V_49 ;
V_349 = V_350 ;
V_351 = (struct V_223 * * ) V_373 ;
* V_351 = V_302 ;
V_19 = F_134 ( V_12 , V_302 , V_275 ,
( ( char * ) V_351 ) + V_374 ) ;
if ( F_119 ( V_19 < 0 ) ) {
if ( F_140 () )
F_14 ( V_12 , V_324 , V_7 , L_37 ,
V_19 ) ;
return V_19 ;
}
F_176 ( V_275 , V_12 -> V_49 , V_302 -> V_375 ) ;
V_275 -> V_334 |= F_144 ( V_376 ) ;
V_22 = F_131 ( V_14 , V_351 ,
F_159 ( V_302 ) - V_373 , V_349 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
if ( F_140 () )
F_14 ( V_12 , V_324 , V_7 , L_38 ) ;
return - V_73 ;
}
F_177 ( V_275 , V_22 ) ;
return 0 ;
}
static int F_178 ( struct V_11 * V_12 ,
struct V_223 * V_302 , struct V_274 * V_275 )
{
const enum V_348 V_349 = V_350 ;
const int V_352 = F_154 ( V_302 ) -> V_352 ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
struct V_271 * V_272 ;
struct V_223 * * V_351 ;
int V_5 , V_66 , V_19 , V_368 ;
void * V_373 ;
T_9 * V_377 ;
T_7 V_22 ;
T_1 V_365 ;
void * V_378 ;
V_368 = F_165 ( V_12 -> V_49 +
sizeof( struct V_271 ) * ( 1 + V_352 ) ) ;
V_378 = F_146 ( V_368 ) ;
if ( F_119 ( ! V_378 ) ) {
F_26 ( V_7 , L_39 ,
V_368 ) ;
return - V_149 ;
}
V_19 = F_134 ( V_12 , V_302 , V_275 ,
V_378 + V_374 ) ;
if ( F_119 ( V_19 < 0 ) ) {
if ( F_140 () )
F_14 ( V_12 , V_324 , V_7 , L_37 ,
V_19 ) ;
goto V_379;
}
V_272 = (struct V_271 * ) ( V_378 + V_12 -> V_49 ) ;
F_179 ( & V_272 [ 0 ] , F_180 ( V_302 ) ) ;
V_272 [ 0 ] . V_105 = V_112 ;
V_272 [ 0 ] . V_372 = 0 ;
V_22 = F_131 ( V_14 , V_302 -> V_277 ,
F_180 ( V_302 ) , V_349 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_73 ;
goto V_380;
}
F_181 ( & V_272 [ 0 ] , V_22 ) ;
V_377 = & F_154 ( V_302 ) -> V_381 [ 0 ] ;
V_365 = V_377 -> V_109 ;
for ( V_5 = 1 ; V_5 <= V_352 ; V_5 ++ , V_377 ++ ) {
F_40 ( ! F_182 ( V_377 ) ) ;
V_22 = F_183 ( V_14 , V_377 , 0 ,
V_365 , V_349 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_73 ;
goto V_382;
}
F_179 ( & V_272 [ V_5 ] , V_365 ) ;
V_272 [ V_5 ] . V_105 = V_112 ;
V_272 [ V_5 ] . V_372 = 0 ;
F_181 ( & V_272 [ V_5 ] , V_22 ) ;
V_365 = V_377 -> V_109 ;
}
F_184 ( & V_272 [ V_5 - 1 ] , V_365 ) ;
F_185 ( V_275 , V_12 -> V_49 , V_302 -> V_375 ) ;
V_373 = ( void * ) V_272 - V_12 -> V_49 ;
V_351 = (struct V_223 * * ) V_373 ;
* V_351 = V_302 ;
V_22 = F_131 ( V_14 , V_373 , V_12 -> V_49 +
sizeof( struct V_271 ) * ( 1 + V_352 ) ,
V_349 ) ;
if ( F_119 ( F_132 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_73 ;
goto V_383;
}
V_275 -> V_105 = V_112 ;
V_275 -> V_334 |= F_144 ( V_376 ) ;
F_177 ( V_275 , V_22 ) ;
return 0 ;
V_383:
V_382:
for ( V_66 = 0 ; V_66 < V_5 ; V_66 ++ )
F_157 ( V_14 , F_155 ( & V_272 [ V_66 ] ) ,
F_156 ( & V_272 [ V_66 ] ) , V_349 ) ;
V_380:
V_379:
F_158 ( V_378 ) ;
return V_19 ;
}
static inline int F_186 ( struct V_11 * V_12 ,
struct V_60 * V_384 ,
int V_385 ,
struct V_274 * V_275 )
{
struct V_185 * V_386 ;
int V_19 , V_5 ;
V_386 = V_12 -> V_202 [ V_385 ] ;
if ( V_275 -> V_105 == V_112 )
V_275 -> V_334 |= F_144 ( F_103 ( V_12 -> V_203 [ V_385 ] ) ) ;
F_187 ( V_12 -> V_7 , V_386 , V_275 ) ;
for ( V_5 = 0 ; V_5 < V_387 ; V_5 ++ ) {
V_19 = F_188 ( V_386 , V_275 ) ;
if ( V_19 != - V_388 )
break;
}
if ( F_119 ( V_19 < 0 ) ) {
V_384 -> V_59 ++ ;
V_384 -> V_389 ++ ;
return V_19 ;
}
V_384 -> V_390 ++ ;
V_384 -> V_391 += F_168 ( V_275 ) ;
return 0 ;
}
static int F_189 ( struct V_223 * V_302 , struct V_6 * V_7 )
{
const int V_392 = F_190 ( V_302 ) ;
bool V_393 = F_191 ( V_302 ) ;
struct V_60 * V_384 ;
struct V_16 * V_17 ;
struct V_11 * V_12 ;
struct V_274 V_275 ;
int V_372 = 0 ;
int V_19 = 0 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_384 = & V_17 -> V_58 ;
F_192 ( & V_275 ) ;
if ( ! V_393 ) {
if ( F_193 ( V_302 , V_12 -> V_49 ) )
goto V_394;
F_40 ( F_191 ( V_302 ) ) ;
}
if ( V_393 &&
F_149 ( F_154 ( V_302 ) -> V_352 < V_369 ) ) {
V_19 = F_178 ( V_12 , V_302 , & V_275 ) ;
V_17 -> V_395 ++ ;
} else {
if ( F_119 ( V_393 ) && F_194 ( V_302 ) )
goto V_394;
V_19 = F_175 ( V_12 , V_302 , & V_275 , & V_372 ) ;
}
if ( F_119 ( V_19 < 0 ) )
goto V_396;
if ( F_149 ( F_186 ( V_12 , V_384 , V_392 , & V_275 ) == 0 ) )
return V_397 ;
F_153 ( V_12 , & V_275 ) ;
V_396:
V_394:
V_384 -> V_59 ++ ;
F_195 ( V_302 ) ;
return V_397 ;
}
static void F_196 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_274 * V_275 ,
T_4 V_136 )
{
if ( F_140 () )
F_14 ( V_12 , V_75 , V_7 , L_40 ,
F_161 ( V_275 -> V_353 ) & V_398 ) ;
V_17 -> V_58 . V_399 ++ ;
if ( F_161 ( V_275 -> V_353 ) & V_400 )
V_17 -> V_399 . V_401 ++ ;
if ( F_161 ( V_275 -> V_353 ) & V_402 )
V_17 -> V_399 . V_403 ++ ;
if ( F_161 ( V_275 -> V_353 ) & V_404 )
V_17 -> V_399 . V_405 ++ ;
if ( F_161 ( V_275 -> V_353 ) & V_406 )
V_17 -> V_399 . V_407 ++ ;
F_125 ( V_7 , V_275 ) ;
}
static void F_197 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_274 * V_275 ,
T_4 V_136 )
{
struct V_223 * V_302 ;
if ( F_140 () )
F_198 ( V_12 , V_75 , V_7 , L_41 ,
F_161 ( V_275 -> V_353 ) & V_408 ) ;
V_17 -> V_58 . V_59 ++ ;
V_302 = F_153 ( V_12 , V_275 ) ;
F_195 ( V_302 ) ;
}
static int F_199 ( struct V_409 * V_410 , int V_411 )
{
struct V_412 * V_413 =
F_74 ( V_410 , struct V_412 , V_410 ) ;
int V_414 = F_200 ( V_413 -> V_415 , V_411 ) ;
if ( V_414 < V_411 ) {
F_201 ( V_410 , V_414 ) ;
F_202 ( V_413 -> V_415 , V_416 ) ;
} else if ( V_413 -> V_417 ) {
F_202 ( V_413 -> V_415 , V_416 ) ;
}
return V_414 ;
}
static void F_203 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_274 * V_275 ,
T_4 V_136 )
{
struct V_223 * V_302 ;
if ( F_119 ( F_161 ( V_275 -> V_353 ) & V_408 ) ) {
if ( F_140 () )
F_198 ( V_12 , V_75 , V_7 , L_41 ,
F_161 ( V_275 -> V_353 ) &
V_408 ) ;
V_17 -> V_58 . V_59 ++ ;
}
V_17 -> V_418 ++ ;
V_302 = F_153 ( V_12 , V_275 ) ;
F_204 ( V_302 ) ;
}
static inline int F_205 ( struct V_16 * V_17 ,
struct V_154 * V_155 )
{
if ( F_119 ( F_206 () || ! F_207 () ) ) {
F_208 ( V_155 , V_416 ) ;
V_17 -> V_413 . V_415 = V_155 ;
F_209 ( & V_17 -> V_413 . V_410 ) ;
V_17 -> V_419 ++ ;
return 1 ;
}
return 0 ;
}
static enum V_420 F_210 ( struct V_154 * V_155 ,
struct V_185 * V_125 ,
const struct V_421 * V_422 )
{
struct V_124 * V_124 = F_74 ( V_125 , struct V_124 , V_187 ) ;
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_104 * V_104 ;
struct V_11 * V_12 ;
V_7 = V_124 -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_104 = F_39 ( V_422 -> V_275 . V_105 ) ;
if ( ! V_104 )
return V_423 ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_205 ( V_17 , V_155 ) )
return V_424 ;
if ( F_152 ( V_12 ) )
F_125 ( V_7 , & V_422 -> V_275 ) ;
else
F_196 ( V_7 , V_12 , V_17 , & V_422 -> V_275 , V_125 -> V_136 ) ;
return V_423 ;
}
static enum V_420 F_211 ( struct V_154 * V_155 ,
struct V_185 * V_125 ,
const struct V_421 * V_422 )
{
struct V_60 * V_384 ;
struct V_16 * V_17 ;
const struct V_274 * V_275 = & V_422 -> V_275 ;
T_7 V_22 = F_126 ( V_275 ) ;
enum V_425 V_426 ;
struct V_6 * V_7 ;
T_4 V_427 ;
struct V_104 * V_104 ;
struct V_11 * V_12 ;
unsigned int V_428 ;
struct V_223 * V_302 ;
int * V_342 ;
V_427 = F_161 ( V_275 -> V_353 ) ;
V_426 = F_127 ( V_275 ) ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_104 = F_39 ( V_422 -> V_275 . V_105 ) ;
if ( ! V_104 )
return V_423 ;
F_212 ( V_7 , V_125 , & V_422 -> V_275 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_384 = & V_17 -> V_58 ;
if ( F_119 ( F_205 ( V_17 , V_155 ) ) )
return V_424 ;
if ( F_119 ( F_152 ( V_12 ) ) ) {
F_125 ( V_7 , & V_422 -> V_275 ) ;
return V_423 ;
}
if ( F_119 ( V_427 & V_398 ) != 0 ) {
if ( F_140 () )
F_198 ( V_12 , V_75 , V_7 , L_41 ,
V_427 & V_398 ) ;
V_384 -> V_399 ++ ;
F_125 ( V_7 , V_275 ) ;
return V_423 ;
}
V_104 = F_39 ( V_275 -> V_105 ) ;
if ( ! V_104 )
return V_423 ;
F_130 ( V_104 -> V_14 , V_22 , V_104 -> V_109 , V_279 ) ;
F_213 ( F_128 ( V_22 ) + F_129 ( V_275 ) ) ;
V_426 = F_127 ( V_275 ) ;
F_40 ( ( V_426 != V_429 ) && ( V_426 != V_278 ) ) ;
V_342 = F_19 ( V_104 -> V_343 ) ;
( * V_342 ) -- ;
if ( F_149 ( V_426 == V_429 ) )
V_302 = F_162 ( V_12 , V_275 ) ;
else
V_302 = F_169 ( V_12 , V_275 ) ;
if ( ! V_302 )
return V_423 ;
V_302 -> V_307 = F_214 ( V_302 , V_7 ) ;
V_428 = V_302 -> V_375 ;
if ( F_119 ( F_215 ( V_302 ) == V_430 ) )
return V_423 ;
V_384 -> V_431 ++ ;
V_384 -> V_432 += V_428 ;
return V_423 ;
}
static enum V_420 F_216 ( struct V_154 * V_155 ,
struct V_185 * V_125 ,
const struct V_421 * V_422 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_205 ( V_17 , V_155 ) )
return V_424 ;
F_197 ( V_7 , V_12 , V_17 , & V_422 -> V_275 , V_125 -> V_136 ) ;
return V_423 ;
}
static enum V_420 F_217 ( struct V_154 * V_155 ,
struct V_185 * V_125 ,
const struct V_421 * V_422 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
F_218 ( V_7 , V_125 , & V_422 -> V_275 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_205 ( V_17 , V_155 ) )
return V_424 ;
F_203 ( V_7 , V_12 , V_17 , & V_422 -> V_275 , V_125 -> V_136 ) ;
return V_423 ;
}
static void V_201 ( struct V_154 * V_155 ,
struct V_185 * V_125 ,
const union V_280 * V_281 )
{
const struct V_274 * V_275 = & V_281 -> V_282 . V_275 ;
struct V_16 * V_17 ;
const struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_223 * V_302 ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_17 -> V_58 . V_433 ++ ;
V_17 -> V_58 . V_389 ++ ;
F_133 ( V_17 , V_281 ) ;
V_302 = F_153 ( V_12 , V_275 ) ;
F_219 ( V_302 ) ;
}
static void F_220 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_413 . V_417 = 0 ;
F_221 ( & V_17 -> V_413 . V_410 ) ;
}
}
static void F_222 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_413 . V_417 = 1 ;
F_223 ( & V_17 -> V_413 . V_410 ) ;
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
V_7 -> V_55 = V_21 -> V_434 ( V_7 , V_12 -> V_21 ) ;
if ( ! V_7 -> V_55 ) {
F_14 ( V_12 , V_435 , V_7 , L_42 ) ;
V_19 = - V_89 ;
goto V_436;
}
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_54 ) ; V_5 ++ ) {
V_19 = F_225 ( V_21 -> V_54 [ V_5 ] ) ;
if ( V_19 )
goto V_437;
}
V_19 = V_12 -> V_21 -> V_24 ( V_21 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_435 , V_7 , L_43 , V_19 ) ;
goto V_437;
}
F_226 ( V_7 ) ;
return 0 ;
V_437:
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_54 ) ; V_5 ++ )
F_16 ( V_21 -> V_54 [ V_5 ] ) ;
V_436:
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
static int F_228 ( struct V_6 * V_7 , struct V_438 * V_439 , int V_334 )
{
if ( ! V_7 -> V_55 )
return - V_73 ;
return F_229 ( V_7 -> V_55 , V_439 , V_334 ) ;
}
static int F_230 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_156 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_156 ) ;
F_231 ( V_7 , & V_17 -> V_413 . V_410 ,
F_199 , V_440 ) ;
}
return 0 ;
}
static void F_232 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_156 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_156 ) ;
F_233 ( & V_17 -> V_413 . V_410 ) ;
}
}
static inline void F_234 ( const struct V_104 * V_116 ,
struct V_119 * V_120 )
{
T_7 V_22 = F_235 ( V_120 ) ;
F_130 ( V_116 -> V_14 , V_22 , V_116 -> V_109 , V_279 ) ;
F_158 ( F_128 ( V_22 ) ) ;
}
static struct V_104 * F_236 ( struct V_13 * V_14 )
{
struct V_104 * V_104 ;
V_104 = F_58 ( V_14 , sizeof( * V_104 ) , V_141 ) ;
if ( ! V_104 )
return F_31 ( - V_149 ) ;
V_104 -> V_105 = V_112 ;
V_104 -> V_343 = F_237 ( V_14 , * V_104 -> V_343 ) ;
V_104 -> V_110 = V_347 ;
V_104 -> V_114 = F_150 ;
V_104 -> V_121 = F_234 ;
return V_104 ;
}
static int F_238 ( struct V_11 * V_12 )
{
struct V_165 V_166 ;
T_4 V_167 ;
int V_19 ;
V_19 = F_77 ( & V_12 -> V_230 . V_168 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_44 , V_19 ) ;
goto V_169;
}
memset ( & V_166 , 0 , sizeof( V_166 ) ) ;
V_166 . V_171 = F_79 ( V_173 ) ;
V_166 . V_159 . V_174 = V_175 ;
V_167 = V_441 ;
F_80 ( & V_166 . V_159 . V_180 , V_167 , 1 ) ;
V_166 . V_171 |= F_79 ( V_181 ) ;
V_166 . V_159 . V_182 = V_175 ;
V_19 = F_81 ( & V_12 -> V_230 , V_183 ,
& V_166 ) ;
if ( V_19 < 0 ) {
if ( F_78 ( V_12 ) )
F_46 ( L_45 ,
V_19 , V_12 -> V_230 . V_168 ) ;
F_82 ( V_12 -> V_230 . V_168 ) ;
goto V_169;
}
if ( F_78 ( V_12 ) )
F_83 ( L_46 ,
V_12 -> V_230 . V_168 , V_12 -> V_21 -> V_22 ) ;
V_12 -> V_229 = true ;
V_169:
return V_19 ;
}
static inline T_3 F_239 ( struct V_243 * V_442 )
{
T_3 V_443 ;
V_443 = ( T_3 ) ( V_442 -> V_249 + V_444 +
V_445 + V_446 ) ;
return V_254 ? F_240 ( V_443 ,
V_254 ) :
V_443 ;
}
static int F_241 ( struct V_80 * V_81 )
{
struct V_104 * V_123 [ V_122 ] = { NULL } ;
struct V_16 * V_17 ;
struct V_6 * V_7 = NULL ;
struct V_124 * V_124 , * V_240 ;
struct V_11 * V_12 = NULL ;
struct V_142 V_143 ;
struct V_51 * V_21 ;
int V_19 = 0 , V_5 , V_152 ;
struct V_13 * V_14 ;
V_14 = & V_81 -> V_14 ;
V_7 = F_242 ( sizeof( * V_12 ) , V_135 ) ;
if ( ! V_7 ) {
F_10 ( V_14 , L_47 ) ;
goto V_447;
}
F_243 ( V_7 , V_14 ) ;
F_244 ( V_14 , V_7 ) ;
V_12 = F_3 ( V_7 ) ;
V_12 -> V_7 = V_7 ;
V_12 -> V_448 = F_245 ( V_449 , V_450 ) ;
V_21 = F_30 ( V_81 ) ;
if ( F_246 ( V_21 ) ) {
F_10 ( V_14 , L_48 ) ;
V_19 = F_247 ( V_21 ) ;
goto V_451;
}
V_7 -> V_452 = F_97 ( F_6 () , V_453 ) ;
F_248 ( V_7 , L_49 ,
V_7 -> V_452 ) ;
V_12 -> V_244 [ V_268 ] . V_249 = V_454 ;
V_12 -> V_244 [ V_270 ] . V_249 = V_374 ;
F_249 ( V_14 , F_250 ( & V_81 -> V_14 ) ) ;
V_19 = F_251 ( V_14 , F_252 ( 40 ) ) ;
if ( V_19 ) {
F_10 ( V_14 , L_50 ) ;
goto V_455;
}
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ ) {
int V_19 ;
V_123 [ V_5 ] = F_236 ( V_14 ) ;
if ( F_246 ( V_123 [ V_5 ] ) )
return F_247 ( V_123 [ V_5 ] ) ;
V_123 [ V_5 ] -> V_338 = F_1 ( V_5 , V_122 ) ;
V_123 [ V_5 ] -> V_109 = F_253 ( V_123 [ V_5 ] -> V_338 ) ;
V_123 [ V_5 ] -> V_14 = V_14 ;
V_19 = F_45 ( V_123 [ V_5 ] ) ;
if ( V_19 < 0 ) {
F_54 ( V_12 ) ;
V_12 -> V_123 [ V_5 ] = NULL ;
goto V_456;
}
V_12 -> V_123 [ V_5 ] = V_123 [ V_5 ] ;
}
F_254 ( & V_12 -> V_457 ) ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_19 = F_60 ( V_14 , & V_12 -> V_457 , & V_143 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_51 ) ;
goto V_458;
}
V_12 -> V_21 = V_21 ;
V_152 = F_61 () ;
if ( V_152 < 0 ) {
F_10 ( V_14 , L_52 ) ;
V_19 = V_152 ;
goto V_459;
}
V_12 -> V_152 = ( T_3 ) V_152 ;
F_67 ( V_12 -> V_152 ) ;
F_87 ( V_12 , & V_192 , V_12 -> V_21 -> V_54 [ V_270 ] ) ;
V_19 = F_76 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_53 ) ;
goto V_460;
}
V_19 = F_238 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_54 ) ;
goto V_461;
}
F_110 (dpaa_fq, tmp, &priv->dpaa_fq_list, list) {
V_19 = F_92 ( V_124 , false ) ;
if ( V_19 < 0 )
goto V_144;
}
V_12 -> V_49 = F_239 ( & V_12 -> V_244 [ V_270 ] ) ;
V_12 -> V_360 = F_239 ( & V_12 -> V_244 [ V_268 ] ) ;
V_19 = F_116 ( V_21 , V_123 , V_122 , & V_143 ,
& V_12 -> V_244 [ 0 ] , V_14 ) ;
if ( V_19 )
goto V_462;
V_12 -> V_17 = F_237 ( V_14 , * V_12 -> V_17 ) ;
if ( ! V_12 -> V_17 ) {
F_10 ( V_14 , L_55 ) ;
V_19 = - V_149 ;
goto V_463;
}
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
}
V_12 -> V_71 = 1 ;
F_29 ( V_7 , V_12 -> V_71 * V_79 ) ;
V_19 = F_230 ( V_7 ) ;
if ( V_19 < 0 )
goto V_464;
V_19 = F_2 ( V_7 , & V_9 , V_10 ) ;
if ( V_19 < 0 )
goto V_465;
F_255 ( & V_7 -> V_14 ) ;
F_256 ( V_12 , V_466 , V_7 , L_56 ,
V_7 -> V_467 ) ;
return 0 ;
V_465:
V_464:
F_232 ( V_7 ) ;
V_463:
V_462:
F_109 ( V_14 , & V_12 -> V_457 ) ;
V_144:
F_257 ( & V_12 -> V_230 ) ;
F_82 ( V_12 -> V_230 . V_168 ) ;
V_461:
F_257 ( & V_12 -> V_161 . V_159 ) ;
F_82 ( V_12 -> V_161 . V_159 . V_168 ) ;
V_460:
V_459:
F_54 ( V_12 ) ;
V_456:
V_458:
V_455:
V_451:
F_244 ( V_14 , NULL ) ;
F_258 ( V_7 ) ;
V_447:
for ( V_5 = 0 ; V_5 < V_122 && V_123 [ V_5 ] ; V_5 ++ ) {
if ( F_259 ( & V_123 [ V_5 ] -> V_108 ) == 0 )
F_260 ( V_14 , V_123 [ V_5 ] ) ;
}
return V_19 ;
}
static int F_261 ( struct V_80 * V_81 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_19 ;
V_14 = & V_81 -> V_14 ;
V_7 = F_34 ( V_14 ) ;
V_12 = F_3 ( V_7 ) ;
F_262 ( V_14 ) ;
F_244 ( V_14 , NULL ) ;
F_263 ( V_7 ) ;
V_19 = F_109 ( V_14 , & V_12 -> V_457 ) ;
F_257 ( & V_12 -> V_230 ) ;
F_82 ( V_12 -> V_230 . V_168 ) ;
F_257 ( & V_12 -> V_161 . V_159 ) ;
F_82 ( V_12 -> V_161 . V_159 . V_168 ) ;
F_232 ( V_7 ) ;
F_54 ( V_12 ) ;
F_258 ( V_7 ) ;
return V_19 ;
}
static int T_10 F_264 ( void )
{
int V_19 ;
F_83 ( L_57 ) ;
V_468 = F_265 () ;
V_469 = F_266 () ;
V_19 = F_267 ( & V_470 ) ;
if ( V_19 < 0 )
F_46 ( L_58 , V_19 ) ;
return V_19 ;
}
static void T_11 F_268 ( void )
{
F_269 ( & V_470 ) ;
F_65 () ;
}
