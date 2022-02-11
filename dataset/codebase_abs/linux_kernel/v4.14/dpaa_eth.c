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
V_33 | V_34 ) ;
V_7 -> V_30 |= V_35 | V_36 ;
V_7 -> V_37 |= V_38 ;
V_7 -> V_37 |= V_39 ;
V_7 -> V_40 |= V_41 ;
V_7 -> V_40 &= ~ V_42 ;
V_7 -> V_37 |= V_7 -> V_30 ;
V_7 -> V_43 = V_7 -> V_37 ;
memcpy ( V_7 -> V_44 , V_18 , V_7 -> V_45 ) ;
memcpy ( V_7 -> V_46 , V_18 , V_7 -> V_45 ) ;
V_7 -> V_47 = & V_48 ;
V_7 -> V_49 = V_12 -> V_50 ;
V_7 -> V_51 = F_7 ( V_10 ) ;
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
struct V_52 * V_21 ;
struct V_11 * V_12 ;
int V_5 , V_19 , error ;
V_12 = F_3 ( V_7 ) ;
V_21 = V_12 -> V_21 ;
F_12 ( V_7 ) ;
F_13 ( 5000 , 10000 ) ;
V_19 = V_21 -> V_53 ( V_21 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_54 , V_7 , L_2 ,
V_19 ) ;
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_55 ) ; V_5 ++ ) {
error = F_16 ( V_21 -> V_55 [ V_5 ] ) ;
if ( error )
V_19 = error ;
}
if ( V_7 -> V_56 )
F_17 ( V_7 -> V_56 ) ;
V_7 -> V_56 = NULL ;
return V_19 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_16 * V_17 ;
const struct V_11 * V_12 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
F_20 ( V_12 , V_57 , V_7 , L_3 ,
F_21 ( V_58 - F_22 ( V_7 ) ) ) ;
V_17 -> V_59 . V_60 ++ ;
}
static void F_23 ( struct V_6 * V_7 ,
struct V_61 * V_62 )
{
int V_63 = sizeof( struct V_61 ) / sizeof( V_64 ) ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
V_64 * V_65 = ( V_64 * ) V_62 ;
V_64 * V_66 ;
int V_5 , V_67 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_66 = ( V_64 * ) & V_17 -> V_59 ;
for ( V_67 = 0 ; V_67 < V_63 ; V_67 ++ )
V_65 [ V_67 ] += V_66 [ V_67 ] ;
}
}
static int F_24 ( struct V_6 * V_7 , enum V_68 type ,
void * V_69 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_70 * V_71 = V_69 ;
T_2 V_72 ;
int V_5 ;
if ( type != V_73 )
return - V_74 ;
V_71 -> V_75 = V_76 ;
V_72 = V_71 -> V_72 ;
if ( V_72 == V_12 -> V_72 )
return 0 ;
if ( ! V_72 ) {
F_25 ( V_7 ) ;
goto V_77;
}
if ( V_72 > V_78 ) {
F_26 ( V_7 , L_4 ,
V_78 ) ;
return - V_79 ;
}
F_27 ( V_7 , V_72 ) ;
for ( V_5 = 0 ; V_5 < V_72 ; V_5 ++ )
F_28 ( V_7 , V_5 , V_80 ,
V_5 * V_80 ) ;
V_77:
V_12 -> V_72 = V_72 ? : 1 ;
F_29 ( V_7 , V_12 -> V_72 * V_80 ) ;
return 0 ;
}
static struct V_52 * F_30 ( struct V_81 * V_82 )
{
struct V_81 * V_83 ;
struct V_84 * V_85 ;
struct V_13 * V_86 , * V_14 ;
struct V_87 * V_88 ;
struct V_52 * V_21 ;
V_86 = & V_82 -> V_14 ;
V_85 = V_86 -> V_89 ;
if ( ! V_85 )
return F_31 ( - V_90 ) ;
V_88 = V_85 -> V_88 ;
V_83 = F_32 ( V_88 ) ;
if ( ! V_83 ) {
F_10 ( V_86 , L_5 ,
V_88 ) ;
F_33 ( V_88 ) ;
return F_31 ( - V_79 ) ;
}
F_33 ( V_88 ) ;
V_14 = & V_83 -> V_14 ;
V_21 = F_34 ( V_14 ) ;
if ( ! V_21 ) {
F_10 ( V_86 , L_6 ,
F_35 ( V_14 ) ) ;
return F_31 ( - V_79 ) ;
}
return V_21 ;
}
static int F_36 ( struct V_6 * V_7 , void * V_22 )
{
const struct V_11 * V_12 ;
struct V_52 * V_21 ;
struct V_91 V_92 ;
int V_19 ;
V_12 = F_3 ( V_7 ) ;
memcpy ( V_92 . V_93 , V_7 -> V_46 , V_94 ) ;
V_19 = F_37 ( V_7 , V_22 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_95 , V_7 , L_7 , V_19 ) ;
return V_19 ;
}
V_21 = V_12 -> V_21 ;
V_19 = V_21 -> V_96 ( V_21 -> V_97 ,
( V_98 * ) V_7 -> V_46 ) ;
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
return - V_79 ;
}
if ( V_104 -> V_105 != V_112 &&
F_41 ( V_104 -> V_105 ) )
return 0 ;
if ( V_104 -> V_105 == V_112 ) {
V_104 -> V_113 = F_47 () ;
if ( ! V_104 -> V_113 ) {
F_46 ( L_12 ,
V_111 ) ;
return - V_90 ;
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
case V_134 :
V_125 -> V_130 = 6 ;
break;
case V_135 :
switch ( V_126 / V_80 ) {
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
V_136 ) ;
}
break;
default:
F_56 ( 1 , L_15 ,
V_125 -> V_127 , V_125 -> V_137 ) ;
}
}
static struct V_124 * F_57 ( struct V_13 * V_14 ,
T_4 V_24 , T_4 V_138 ,
struct V_139 * V_140 ,
enum V_141 V_127 )
{
struct V_124 * V_124 ;
int V_5 ;
V_124 = F_58 ( V_14 , sizeof( * V_124 ) * V_138 ,
V_142 ) ;
if ( ! V_124 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ ) {
V_124 [ V_5 ] . V_127 = V_127 ;
V_124 [ V_5 ] . V_137 = V_24 ? V_24 + V_5 : 0 ;
F_59 ( & V_124 [ V_5 ] . V_140 , V_140 ) ;
}
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ )
F_55 ( V_124 + V_5 , V_5 ) ;
return V_124 ;
}
static int F_60 ( struct V_13 * V_14 , struct V_139 * V_140 ,
struct V_143 * V_144 )
{
struct V_124 * V_124 ;
T_4 V_145 , V_146 , V_5 ;
V_124 = F_57 ( V_14 , 0 , 1 , V_140 , V_131 ) ;
if ( ! V_124 )
goto V_147;
V_144 -> V_148 = & V_124 [ 0 ] ;
V_124 = F_57 ( V_14 , 0 , 1 , V_140 , V_133 ) ;
if ( ! V_124 )
goto V_147;
V_144 -> V_149 = & V_124 [ 0 ] ;
if ( F_61 ( & V_145 , 2 * V_150 ) )
goto V_147;
V_146 = F_62 ( V_145 , V_150 ) ;
for ( V_5 = V_145 ; V_5 < V_146 ; V_5 ++ )
F_63 ( V_5 ) ;
for ( V_5 = V_146 + V_150 ;
V_5 < ( V_145 + 2 * V_150 ) ; V_5 ++ )
F_63 ( V_5 ) ;
V_124 = F_57 ( V_14 , V_146 , V_150 ,
V_140 , V_134 ) ;
if ( ! V_124 )
goto V_147;
V_144 -> V_151 = & V_124 [ 0 ] ;
if ( ! F_57 ( V_14 , 0 , V_136 , V_140 , V_129 ) )
goto V_147;
V_124 = F_57 ( V_14 , 0 , 1 , V_140 , V_132 ) ;
if ( ! V_124 )
goto V_147;
V_144 -> V_152 = & V_124 [ 0 ] ;
V_124 = F_57 ( V_14 , 0 , 1 , V_140 , V_128 ) ;
if ( ! V_124 )
goto V_147;
V_144 -> V_153 = & V_124 [ 0 ] ;
if ( ! F_57 ( V_14 , 0 , V_136 , V_140 , V_135 ) )
goto V_147;
return 0 ;
V_147:
F_10 ( V_14 , L_16 ) ;
return - V_154 ;
}
static int F_64 ( void )
{
F_65 ( & V_155 ) ;
if ( ! V_156 ) {
T_4 V_113 ;
int V_118 ;
V_118 = F_66 ( & V_113 ) ;
if ( ! V_118 )
V_156 = V_113 ;
}
F_67 ( & V_155 ) ;
if ( ! V_156 )
return - V_154 ;
return V_156 ;
}
static void F_68 ( void )
{
F_69 ( V_156 ) ;
}
static void F_70 ( T_3 V_157 )
{
T_4 V_113 = F_71 ( V_157 ) ;
const T_5 * V_158 = F_72 () ;
struct V_159 * V_160 ;
int V_161 ;
F_73 (cpu, cpus) {
V_160 = F_74 ( V_161 ) ;
F_75 ( V_160 , V_113 ) ;
}
}
static void F_76 ( struct V_159 * V_162 , struct V_163 * V_164 ,
int V_165 )
{
struct V_11 * V_12 = (struct V_11 * ) F_77 ( V_164 ,
struct V_11 , V_166 . V_164 ) ;
if ( V_165 ) {
V_12 -> V_166 . V_167 = V_58 ;
F_12 ( V_12 -> V_7 ) ;
V_12 -> V_166 . V_168 ++ ;
} else {
V_12 -> V_166 . V_169 +=
( V_58 - V_12 -> V_166 . V_167 ) ;
F_78 ( V_12 -> V_7 ) ;
}
}
static int F_79 ( struct V_11 * V_12 )
{
struct V_170 V_171 ;
T_4 V_172 ;
int V_19 ;
V_19 = F_80 ( & V_12 -> V_166 . V_164 . V_173 ) ;
if ( V_19 < 0 ) {
if ( F_81 ( V_12 ) )
F_46 ( L_17 ,
V_111 , V_19 ) ;
goto V_174;
}
V_12 -> V_166 . V_164 . V_175 = F_76 ;
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_176 = F_82 ( V_177 | V_178 ) ;
V_171 . V_164 . V_179 = V_180 ;
if ( V_12 -> V_21 -> V_181 & V_182 )
V_172 = V_183 ;
else
V_172 = V_184 ;
F_83 ( & V_171 . V_164 . V_185 , V_172 , 1 ) ;
V_171 . V_176 |= F_82 ( V_186 ) ;
V_171 . V_164 . V_187 = V_180 ;
V_19 = F_84 ( & V_12 -> V_166 . V_164 , V_188 ,
& V_171 ) ;
if ( V_19 < 0 ) {
if ( F_81 ( V_12 ) )
F_46 ( L_18 ,
V_111 , V_19 , V_12 -> V_166 . V_164 . V_173 ) ;
F_85 ( V_12 -> V_166 . V_164 . V_173 ) ;
goto V_174;
}
if ( F_81 ( V_12 ) )
F_86 ( L_19 ,
V_12 -> V_166 . V_164 . V_173 , V_12 -> V_21 -> V_22 ,
V_12 -> V_166 . V_164 . V_189 ) ;
V_174:
return V_19 ;
}
static inline void F_87 ( const struct V_11 * V_12 ,
struct V_124 * V_125 ,
const struct V_190 * V_191 )
{
V_125 -> V_145 = * V_191 ;
V_125 -> V_7 = V_12 -> V_7 ;
V_125 -> V_99 = V_192 ;
V_125 -> V_157 = V_12 -> V_157 ;
}
static inline void F_88 ( const struct V_11 * V_12 ,
struct V_124 * V_125 ,
struct V_193 * V_55 ,
const struct V_190 * V_191 )
{
V_125 -> V_145 = * V_191 ;
V_125 -> V_7 = V_12 -> V_7 ;
if ( V_55 ) {
V_125 -> V_99 = V_194 ;
V_125 -> V_157 = ( T_3 ) F_89 ( V_55 ) ;
} else {
V_125 -> V_99 = V_195 ;
}
}
static void F_90 ( struct V_11 * V_12 ,
const struct V_196 * V_197 ,
struct V_193 * V_198 )
{
int V_199 = 0 , V_200 = 0 , V_201 = 0 , V_202 = 0 , V_161 ;
const T_5 * V_203 = F_72 () ;
T_3 V_204 [ V_205 ] ;
struct V_124 * V_125 ;
F_73 (cpu, affine_cpus)
V_204 [ V_201 ++ ] = F_91 ( V_161 ) ;
if ( V_201 == 0 )
F_10 ( V_12 -> V_7 -> V_14 . V_15 ,
L_20 ) ;
F_92 (fq, &priv->dpaa_fq_list, list) {
switch ( V_125 -> V_127 ) {
case V_133 :
F_87 ( V_12 , V_125 , & V_197 -> V_149 ) ;
break;
case V_131 :
F_87 ( V_12 , V_125 , & V_197 -> V_148 ) ;
break;
case V_134 :
if ( ! V_201 )
continue;
F_87 ( V_12 , V_125 , & V_197 -> V_149 ) ;
V_125 -> V_157 = V_204 [ V_202 ++ % V_201 ] ;
break;
case V_135 :
F_88 ( V_12 , V_125 , V_198 ,
& V_197 -> V_206 ) ;
if ( V_199 < V_136 )
V_12 -> V_207 [ V_199 ++ ] = & V_125 -> V_145 ;
break;
case V_129 :
V_12 -> V_208 [ V_200 ++ ] = & V_125 -> V_145 ;
case V_128 :
F_87 ( V_12 , V_125 , & V_197 -> V_153 ) ;
break;
case V_132 :
F_87 ( V_12 , V_125 , & V_197 -> V_152 ) ;
break;
default:
F_93 ( V_12 -> V_7 -> V_14 . V_15 ,
L_21 ) ;
break;
}
}
while ( V_199 < V_136 ) {
F_92 (fq, &priv->dpaa_fq_list, list) {
if ( V_125 -> V_127 != V_135 )
continue;
V_12 -> V_207 [ V_199 ++ ] = & V_125 -> V_145 ;
if ( V_199 == V_136 )
break;
}
}
}
static inline int F_94 ( const struct V_11 * V_12 ,
struct V_190 * V_209 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_136 ; V_5 ++ )
if ( V_12 -> V_207 [ V_5 ] == V_209 )
return V_5 ;
return - V_79 ;
}
static int F_95 ( struct V_124 * V_124 , bool V_210 )
{
const struct V_11 * V_12 ;
struct V_190 * V_211 = NULL ;
struct V_212 V_213 ;
struct V_13 * V_14 ;
struct V_190 * V_125 ;
int V_214 ;
int V_19 ;
V_12 = F_3 ( V_124 -> V_7 ) ;
V_14 = V_124 -> V_7 -> V_14 . V_15 ;
if ( V_124 -> V_137 == 0 )
V_124 -> V_99 |= V_215 ;
V_124 -> V_216 = ! ( V_124 -> V_99 & V_195 ) ;
V_19 = F_96 ( V_124 -> V_137 , V_124 -> V_99 , & V_124 -> V_145 ) ;
if ( V_19 ) {
F_10 ( V_14 , L_22 ) ;
return V_19 ;
}
V_125 = & V_124 -> V_145 ;
if ( V_124 -> V_216 ) {
memset ( & V_213 , 0 , sizeof( V_213 ) ) ;
V_213 . V_176 = F_82 ( V_217 ) ;
V_213 . V_218 . V_219 = F_82 ( V_220 ) ;
if ( V_124 -> V_127 == V_128 )
V_213 . V_218 . V_219 |= F_82 ( V_221 ) ;
V_213 . V_176 |= F_82 ( V_222 ) ;
F_97 ( & V_213 . V_218 , V_124 -> V_157 , V_124 -> V_130 ) ;
if ( V_124 -> V_127 == V_135 ||
V_124 -> V_127 == V_128 ||
V_124 -> V_127 == V_129 ) {
V_213 . V_176 |= F_82 ( V_223 ) ;
V_213 . V_218 . V_219 |= F_82 ( V_224 ) ;
V_213 . V_218 . V_225 = ( T_2 ) V_12 -> V_166 . V_164 . V_173 ;
V_213 . V_176 |= F_82 ( V_226 ) ;
F_98 ( & V_213 . V_218 , V_227 ) ;
F_99 ( & V_213 . V_218 ,
F_100 ( sizeof( struct V_228 ) +
V_12 -> V_50 ,
( T_1 ) V_229 ) ) ;
}
if ( V_210 ) {
V_213 . V_176 |= F_82 ( V_230 ) ;
F_101 ( & V_213 . V_218 , V_231 , 1 ) ;
V_213 . V_218 . V_219 = F_82 ( V_232 ) ;
}
if ( V_124 -> V_127 == V_135 ) {
V_214 = F_94 ( V_12 , & V_124 -> V_145 ) ;
if ( V_214 >= 0 )
V_211 = V_12 -> V_208 [ V_214 ] ;
if ( V_211 ) {
V_213 . V_176 |=
F_82 ( V_233 ) ;
F_102 ( & V_213 . V_218 ,
0x1e00000080000000ULL ) ;
}
}
if ( V_12 -> V_234 &&
( V_124 -> V_127 == V_133 ||
V_124 -> V_127 == V_131 ||
V_124 -> V_127 == V_134 ) ) {
V_213 . V_176 |= F_82 ( V_223 ) ;
V_213 . V_218 . V_219 |= F_82 ( V_224 ) ;
V_213 . V_218 . V_225 = ( T_2 ) V_12 -> V_235 . V_173 ;
V_213 . V_176 |= F_82 ( V_226 ) ;
F_98 ( & V_213 . V_218 , V_227 ) ;
F_99 ( & V_213 . V_218 ,
F_100 ( sizeof( struct V_228 ) +
V_12 -> V_50 ,
( T_1 ) V_229 ) ) ;
}
if ( V_124 -> V_99 & V_192 ) {
V_213 . V_176 |= F_82 ( V_233 ) ;
V_213 . V_218 . V_219 |= F_82 ( V_236 |
V_237 ) ;
V_213 . V_218 . V_238 . V_239 . V_240 =
V_241 | V_242 |
V_243 ;
F_103 ( & V_213 . V_218 , 1 , 2 ,
F_104 ( sizeof( struct V_190 ) ,
64 ) ) ;
}
V_19 = F_105 ( V_125 , V_244 , & V_213 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_23 ,
F_106 ( V_125 ) , V_19 ) ;
F_107 ( V_125 ) ;
return V_19 ;
}
}
V_124 -> V_137 = F_106 ( V_125 ) ;
return 0 ;
}
static int F_108 ( struct V_13 * V_14 , struct V_190 * V_125 )
{
const struct V_11 * V_12 ;
struct V_124 * V_124 ;
int V_19 , error ;
V_19 = 0 ;
V_124 = F_77 ( V_125 , struct V_124 , V_145 ) ;
V_12 = F_3 ( V_124 -> V_7 ) ;
if ( V_124 -> V_216 ) {
V_19 = F_109 ( V_125 , NULL ) ;
if ( V_19 < 0 && F_81 ( V_12 ) )
F_10 ( V_14 , L_24 ,
F_106 ( V_125 ) , V_19 ) ;
error = F_110 ( V_125 ) ;
if ( error < 0 && F_81 ( V_12 ) ) {
F_10 ( V_14 , L_25 ,
F_106 ( V_125 ) , error ) ;
if ( V_19 >= 0 )
V_19 = error ;
}
}
F_107 ( V_125 ) ;
F_111 ( & V_124 -> V_140 ) ;
return V_19 ;
}
static int F_112 ( struct V_13 * V_14 , struct V_139 * V_140 )
{
struct V_124 * V_124 , * V_245 ;
int V_19 , error ;
V_19 = 0 ;
F_113 (dpaa_fq, tmp, list, list) {
error = F_108 ( V_14 , (struct V_190 * ) V_124 ) ;
if ( error < 0 && V_19 >= 0 )
V_19 = error ;
}
return V_19 ;
}
static int F_114 ( struct V_193 * V_55 , struct V_124 * V_246 ,
struct V_124 * V_247 ,
struct V_248 * V_249 )
{
struct V_250 V_251 ;
struct V_252 V_253 ;
int V_19 ;
memset ( & V_253 , 0 , sizeof( V_253 ) ) ;
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
V_251 . V_254 = V_249 -> V_254 ;
V_251 . V_255 = true ;
V_251 . V_256 = true ;
V_251 . V_257 = false ;
V_251 . V_258 = V_259 ;
V_253 . V_260 . V_261 . V_262 = V_246 -> V_137 ;
V_253 . V_260 . V_261 . V_263 = V_247 -> V_137 ;
V_19 = F_115 ( V_55 , & V_253 ) ;
if ( V_19 ) {
F_46 ( L_26 , V_111 ) ;
return V_19 ;
}
V_19 = F_116 ( V_55 , & V_251 ) ;
if ( V_19 ) {
F_46 ( L_27 ,
V_111 ) ;
return V_19 ;
}
V_19 = F_117 ( V_55 ) ;
if ( V_19 )
F_46 ( L_28 , V_111 ) ;
return V_19 ;
}
static int F_118 ( struct V_193 * V_55 , struct V_104 * * V_264 ,
T_1 V_138 , struct V_124 * V_246 ,
struct V_124 * V_247 , struct V_124 * V_265 ,
struct V_248 * V_249 )
{
struct V_250 V_251 ;
struct V_266 * V_267 ;
struct V_252 V_253 ;
int V_5 , V_19 ;
memset ( & V_253 , 0 , sizeof( V_253 ) ) ;
memset ( & V_251 , 0 , sizeof( V_251 ) ) ;
V_251 . V_254 = V_249 -> V_254 ;
V_251 . V_255 = true ;
V_251 . V_256 = true ;
V_251 . V_257 = false ;
V_251 . V_258 = V_259 ;
V_267 = & V_253 . V_260 . V_268 ;
V_267 -> V_262 = V_246 -> V_137 ;
V_267 -> V_263 = V_247 -> V_137 ;
if ( V_265 ) {
V_267 -> V_269 = V_265 -> V_137 ;
V_267 -> V_270 = V_150 ;
}
V_138 = F_100 ( F_15 ( V_267 -> V_271 . V_272 ) , V_138 ) ;
V_267 -> V_271 . V_273 = ( T_2 ) V_138 ;
for ( V_5 = 0 ; V_5 < V_138 ; V_5 ++ ) {
V_267 -> V_271 . V_272 [ V_5 ] . V_274 = V_264 [ V_5 ] -> V_105 ;
V_267 -> V_271 . V_272 [ V_5 ] . V_109 = ( T_3 ) V_264 [ V_5 ] -> V_109 ;
}
V_19 = F_115 ( V_55 , & V_253 ) ;
if ( V_19 ) {
F_46 ( L_26 , V_111 ) ;
return V_19 ;
}
V_19 = F_116 ( V_55 , & V_251 ) ;
if ( V_19 ) {
F_46 ( L_27 ,
V_111 ) ;
return V_19 ;
}
V_19 = F_117 ( V_55 ) ;
if ( V_19 )
F_46 ( L_28 , V_111 ) ;
return V_19 ;
}
static int F_119 ( struct V_52 * V_21 ,
struct V_104 * * V_264 , T_1 V_138 ,
struct V_143 * V_144 ,
struct V_248 * V_249 ,
struct V_13 * V_14 )
{
struct V_193 * V_275 = V_21 -> V_55 [ V_276 ] ;
struct V_193 * V_277 = V_21 -> V_55 [ V_278 ] ;
int V_19 ;
V_19 = F_114 ( V_277 , V_144 -> V_152 ,
V_144 -> V_153 , & V_249 [ V_278 ] ) ;
if ( V_19 )
return V_19 ;
V_19 = F_118 ( V_275 , V_264 , V_138 , V_144 -> V_148 ,
V_144 -> V_149 , V_144 -> V_151 ,
& V_249 [ V_276 ] ) ;
return V_19 ;
}
static int F_120 ( const struct V_104 * V_104 ,
struct V_119 * V_120 , int V_2 )
{
int V_19 ;
V_19 = F_121 ( V_104 -> V_113 , V_120 , V_2 ) ;
if ( F_122 ( F_40 ( V_19 ) ) && V_104 -> V_121 )
while ( V_2 -- > 0 )
V_104 -> V_121 ( V_104 , & V_120 [ V_2 ] ) ;
return V_2 ;
}
static void F_123 ( struct V_279 * V_280 )
{
struct V_119 V_120 [ V_281 ] ;
struct V_104 * V_104 ;
int V_5 = 0 , V_67 ;
memset ( V_120 , 0 , sizeof( V_120 ) ) ;
do {
V_104 = F_39 ( V_280 [ V_5 ] . V_105 ) ;
if ( ! V_104 )
return;
V_67 = 0 ;
do {
F_40 ( F_124 ( & V_280 [ V_5 ] ) ) ;
F_125 ( & V_120 [ V_67 ] , F_126 ( & V_280 [ V_5 ] ) ) ;
V_67 ++ ; V_5 ++ ;
} while ( V_67 < F_15 ( V_120 ) &&
! F_127 ( & V_280 [ V_5 - 1 ] ) &&
V_280 [ V_5 - 1 ] . V_105 == V_280 [ V_5 ] . V_105 );
F_120 ( V_104 , V_120 , V_67 ) ;
} while ( ! F_127 ( & V_280 [ V_5 - 1 ] ) );
}
static void F_128 ( const struct V_6 * V_7 ,
const struct V_282 * V_283 )
{
struct V_279 * V_280 ;
struct V_104 * V_104 ;
struct V_119 V_120 ;
T_6 V_22 ;
void * V_284 ;
V_120 . V_285 = 0 ;
F_125 ( & V_120 , F_129 ( V_283 ) ) ;
V_104 = F_39 ( V_283 -> V_105 ) ;
if ( ! V_104 )
return;
if ( F_130 ( V_283 ) == V_286 ) {
V_284 = F_131 ( F_129 ( V_283 ) ) ;
V_280 = V_284 + F_132 ( V_283 ) ;
F_133 ( V_104 -> V_14 , F_129 ( V_283 ) , V_104 -> V_109 ,
V_287 ) ;
F_123 ( V_280 ) ;
V_22 = F_134 ( V_104 -> V_14 , V_284 , V_104 -> V_109 ,
V_287 ) ;
if ( F_135 ( V_104 -> V_14 , V_22 ) ) {
F_10 ( V_104 -> V_14 , L_29 ) ;
return;
}
F_125 ( & V_120 , V_22 ) ;
}
F_120 ( V_104 , & V_120 , 1 ) ;
}
static void F_136 ( struct V_16 * V_17 ,
const union V_288 * V_289 )
{
switch ( V_289 -> V_290 . V_291 & V_292 ) {
case V_293 :
V_17 -> V_294 . V_295 ++ ;
break;
case V_296 :
V_17 -> V_294 . V_297 ++ ;
break;
case V_298 :
V_17 -> V_294 . V_299 ++ ;
break;
case V_300 :
V_17 -> V_294 . V_301 ++ ;
break;
case V_302 :
V_17 -> V_294 . V_303 ++ ;
break;
case V_304 :
V_17 -> V_294 . V_305 ++ ;
break;
case V_306 :
V_17 -> V_294 . V_307 ++ ;
break;
case V_308 :
V_17 -> V_294 . V_309 ++ ;
break;
}
}
static int F_137 ( struct V_11 * V_12 ,
struct V_228 * V_310 ,
struct V_282 * V_283 ,
char * V_311 )
{
struct V_312 * V_313 ;
T_3 V_314 = F_138 ( V_310 -> V_315 ) ;
struct V_316 * V_317 = NULL ;
struct V_318 * V_319 ;
int V_320 = 0 ;
T_2 V_321 ;
if ( V_310 -> V_322 != V_323 )
return 0 ;
V_313 = (struct V_312 * ) V_311 ;
if ( V_314 == V_324 ) {
F_139 ( V_310 ) ;
V_314 = F_138 ( F_140 ( V_310 ) -> V_325 ) ;
}
switch ( V_314 ) {
case V_326 :
V_313 -> V_327 = F_82 ( V_328 ) ;
V_319 = F_141 ( V_310 ) ;
F_40 ( ! V_319 ) ;
V_321 = V_319 -> V_315 ;
break;
case V_329 :
V_313 -> V_327 = F_82 ( V_330 ) ;
V_317 = F_142 ( V_310 ) ;
F_40 ( ! V_317 ) ;
V_321 = V_317 -> V_331 ;
break;
default:
if ( F_143 () )
F_144 ( V_12 , V_332 , V_12 -> V_7 ,
L_30 ,
F_138 ( V_310 -> V_315 ) ) ;
V_320 = - V_333 ;
goto V_334;
}
switch ( V_321 ) {
case V_335 :
V_313 -> V_336 = V_337 ;
break;
case V_338 :
V_313 -> V_336 = V_339 ;
break;
default:
if ( F_143 () )
F_144 ( V_12 , V_332 , V_12 -> V_7 ,
L_31 ,
V_321 ) ;
V_320 = - V_333 ;
goto V_334;
}
V_313 -> V_340 [ 0 ] = ( T_2 ) F_145 ( V_310 ) ;
V_313 -> V_341 = ( T_2 ) F_146 ( V_310 ) ;
V_283 -> V_342 |= F_147 ( V_343 | V_344 ) ;
V_334:
return V_320 ;
}
static int F_148 ( const struct V_104 * V_104 )
{
struct V_13 * V_14 = V_104 -> V_14 ;
struct V_119 V_120 [ 8 ] ;
T_6 V_22 ;
void * V_345 ;
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_345 = F_149 ( V_104 -> V_346 ) ;
if ( F_122 ( ! V_345 ) ) {
F_10 ( V_14 , L_32 ,
V_104 -> V_346 ) ;
goto V_347;
}
V_345 = F_150 ( V_345 , V_348 ) ;
V_22 = F_134 ( V_14 , V_345 ,
V_104 -> V_109 , V_287 ) ;
if ( F_122 ( F_135 ( V_14 , V_22 ) ) ) {
F_10 ( V_104 -> V_14 , L_33 ) ;
goto V_347;
}
V_120 [ V_5 ] . V_285 = 0 ;
F_125 ( & V_120 [ V_5 ] , V_22 ) ;
}
V_349:
return F_120 ( V_104 , V_120 , V_5 ) ;
V_347:
F_151 ( 1 , L_34 ) ;
F_125 ( & V_120 [ V_5 ] , 0 ) ;
if ( F_152 ( V_5 ) )
goto V_349;
return 0 ;
}
static int F_153 ( struct V_104 * V_104 )
{
int V_5 ;
F_4 (i) {
int * V_350 = F_5 ( V_104 -> V_351 , V_5 ) ;
int V_67 ;
for ( V_67 = 0 ; V_67 < V_104 -> V_110 ; V_67 += 8 )
* V_350 += F_148 ( V_104 ) ;
}
return 0 ;
}
static int F_154 ( struct V_104 * V_104 , int * V_352 )
{
int V_138 = * V_352 ;
int V_353 ;
if ( F_122 ( V_138 < V_354 ) ) {
do {
V_353 = F_148 ( V_104 ) ;
if ( F_122 ( ! V_353 ) ) {
break;
}
V_138 += V_353 ;
} while ( V_138 < V_355 );
* V_352 = V_138 ;
if ( F_122 ( V_138 < V_355 ) )
return - V_154 ;
}
return 0 ;
}
static int F_155 ( struct V_11 * V_12 )
{
struct V_104 * V_104 ;
int * V_352 ;
int V_3 , V_5 ;
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ ) {
V_104 = V_12 -> V_123 [ V_5 ] ;
if ( ! V_104 )
return - V_79 ;
V_352 = F_19 ( V_104 -> V_351 ) ;
V_3 = F_154 ( V_104 , V_352 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static struct V_228 * F_156 ( const struct V_11 * V_12 ,
const struct V_282 * V_283 )
{
const enum V_356 V_357 = V_358 ;
struct V_13 * V_14 = V_12 -> V_7 -> V_14 . V_15 ;
T_6 V_22 = F_129 ( V_283 ) ;
const struct V_279 * V_280 ;
struct V_228 * * V_359 , * V_310 ;
int V_360 , V_5 ;
V_359 = (struct V_228 * * ) F_131 ( V_22 ) ;
V_310 = * V_359 ;
if ( F_122 ( F_130 ( V_283 ) == V_286 ) ) {
V_360 = F_157 ( V_310 ) -> V_360 ;
F_133 ( V_14 , V_22 , F_132 ( V_283 ) +
sizeof( struct V_279 ) * ( 1 + V_360 ) ,
V_357 ) ;
V_280 = F_131 ( V_22 + F_132 ( V_283 ) ) ;
F_133 ( V_14 , F_158 ( & V_280 [ 0 ] ) ,
F_159 ( & V_280 [ 0 ] ) , V_357 ) ;
for ( V_5 = 1 ; V_5 < V_360 ; V_5 ++ ) {
F_40 ( F_124 ( & V_280 [ V_5 ] ) ) ;
F_160 ( V_14 , F_158 ( & V_280 [ V_5 ] ) ,
F_159 ( & V_280 [ V_5 ] ) , V_357 ) ;
}
F_161 ( F_131 ( V_22 ) ) ;
} else {
F_133 ( V_14 , V_22 ,
F_162 ( V_310 ) - ( T_2 * ) V_359 , V_357 ) ;
}
return V_310 ;
}
static T_2 F_163 ( const struct V_11 * V_12 , const struct V_282 * V_283 )
{
if ( ( V_12 -> V_7 -> V_37 & V_39 ) &&
( F_164 ( V_283 -> V_361 ) & V_362 ) )
return V_363 ;
return V_364 ;
}
static struct V_228 * F_165 ( const struct V_11 * V_12 ,
const struct V_282 * V_283 )
{
T_7 V_365 = F_132 ( V_283 ) ;
T_6 V_22 = F_129 ( V_283 ) ;
struct V_104 * V_104 ;
struct V_228 * V_310 ;
void * V_284 ;
V_284 = F_131 ( V_22 ) ;
F_40 ( ! F_166 ( ( unsigned long ) V_284 , V_348 ) ) ;
V_104 = F_39 ( V_283 -> V_105 ) ;
if ( ! V_104 )
goto V_366;
V_310 = F_167 ( V_284 , V_104 -> V_109 +
F_168 ( sizeof( struct V_367 ) ) ) ;
if ( F_122 ( ! V_310 ) ) {
F_151 ( 1 , L_35 ) ;
goto V_366;
}
F_40 ( V_365 != V_12 -> V_368 ) ;
F_169 ( V_310 , V_365 ) ;
F_170 ( V_310 , F_171 ( V_283 ) ) ;
V_310 -> V_322 = F_163 ( V_12 , V_283 ) ;
return V_310 ;
V_366:
F_161 ( V_284 ) ;
return NULL ;
}
static struct V_228 * F_172 ( const struct V_11 * V_12 ,
const struct V_282 * V_283 )
{
T_7 V_365 = F_132 ( V_283 ) ;
T_6 V_22 = F_129 ( V_283 ) ;
const struct V_279 * V_280 ;
struct V_369 * V_369 , * V_370 ;
struct V_104 * V_104 ;
void * V_284 , * V_371 ;
int V_372 , V_373 ;
struct V_228 * V_310 ;
T_6 V_374 ;
int V_375 ;
unsigned int V_376 ;
int * V_350 ;
int V_5 ;
V_284 = F_131 ( V_22 ) ;
F_40 ( ! F_166 ( ( unsigned long ) V_284 , V_348 ) ) ;
V_280 = V_284 + V_365 ;
for ( V_5 = 0 ; V_5 < V_377 ; V_5 ++ ) {
F_40 ( F_124 ( & V_280 [ V_5 ] ) ) ;
V_374 = F_158 ( & V_280 [ V_5 ] ) ;
V_371 = F_131 ( V_374 ) ;
F_40 ( ! F_166 ( ( unsigned long ) V_371 ,
V_348 ) ) ;
V_104 = F_39 ( V_280 [ V_5 ] . V_105 ) ;
if ( ! V_104 )
goto V_378;
V_350 = F_19 ( V_104 -> V_351 ) ;
F_133 ( V_104 -> V_14 , V_374 , V_104 -> V_109 ,
V_287 ) ;
if ( V_5 == 0 ) {
V_376 = V_104 -> V_109 +
F_168 ( sizeof( struct V_367 ) ) ;
V_310 = F_167 ( V_371 , V_376 ) ;
if ( F_40 ( F_122 ( ! V_310 ) ) )
goto V_378;
V_310 -> V_322 = F_163 ( V_12 , V_283 ) ;
F_40 ( V_365 != V_12 -> V_368 ) ;
F_169 ( V_310 , V_365 ) ;
F_170 ( V_310 , F_159 ( & V_280 [ V_5 ] ) ) ;
} else {
V_369 = F_173 ( V_371 ) ;
V_370 = F_174 ( V_371 ) ;
V_375 = ( ( unsigned long ) V_371 &
( V_379 - 1 ) ) +
( F_175 ( V_369 ) - F_175 ( V_370 ) ) ;
V_372 = F_176 ( & V_280 [ V_5 ] ) + V_375 ;
V_373 = F_159 ( & V_280 [ V_5 ] ) ;
F_177 ( V_310 , V_5 - 1 , V_370 , V_372 ,
V_373 , V_104 -> V_109 ) ;
}
( * V_350 ) -- ;
if ( F_127 ( & V_280 [ V_5 ] ) )
break;
}
F_151 ( V_5 == V_377 , L_36 ) ;
F_161 ( V_284 ) ;
return V_310 ;
V_378:
for ( V_5 -- ; V_5 >= 0 ; V_5 -- ) {
V_104 = F_39 ( V_280 [ V_5 ] . V_105 ) ;
if ( V_104 ) {
V_350 = F_19 ( V_104 -> V_351 ) ;
( * V_350 ) ++ ;
}
}
for ( V_5 = 0 ; V_5 < V_377 ; V_5 ++ ) {
V_374 = F_158 ( & V_280 [ V_5 ] ) ;
V_371 = F_131 ( V_374 ) ;
F_161 ( V_371 ) ;
V_104 = F_39 ( V_280 [ V_5 ] . V_105 ) ;
if ( V_104 ) {
V_350 = F_19 ( V_104 -> V_351 ) ;
( * V_350 ) -- ;
}
if ( F_127 ( & V_280 [ V_5 ] ) )
break;
}
F_161 ( V_284 ) ;
return NULL ;
}
static int F_178 ( struct V_11 * V_12 ,
struct V_228 * V_310 , struct V_282 * V_283 ,
int * V_380 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
enum V_356 V_357 ;
unsigned char * V_381 ;
struct V_228 * * V_359 ;
T_6 V_22 ;
int V_19 ;
V_283 -> V_105 = V_112 ;
V_381 = V_310 -> V_285 - V_12 -> V_50 ;
V_357 = V_358 ;
V_359 = (struct V_228 * * ) V_381 ;
* V_359 = V_310 ;
V_19 = F_137 ( V_12 , V_310 , V_283 ,
( ( char * ) V_359 ) + V_382 ) ;
if ( F_122 ( V_19 < 0 ) ) {
if ( F_143 () )
F_14 ( V_12 , V_332 , V_7 , L_37 ,
V_19 ) ;
return V_19 ;
}
F_179 ( V_283 , V_12 -> V_50 , V_310 -> V_383 ) ;
V_283 -> V_342 |= F_147 ( V_384 ) ;
V_22 = F_134 ( V_14 , V_359 ,
F_162 ( V_310 ) - V_381 , V_357 ) ;
if ( F_122 ( F_135 ( V_14 , V_22 ) ) ) {
if ( F_143 () )
F_14 ( V_12 , V_332 , V_7 , L_38 ) ;
return - V_79 ;
}
F_180 ( V_283 , V_22 ) ;
return 0 ;
}
static int F_181 ( struct V_11 * V_12 ,
struct V_228 * V_310 , struct V_282 * V_283 )
{
const enum V_356 V_357 = V_358 ;
const int V_360 = F_157 ( V_310 ) -> V_360 ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
struct V_279 * V_280 ;
struct V_228 * * V_359 ;
int V_5 , V_67 , V_19 , V_376 ;
void * V_381 ;
T_8 * V_385 ;
T_6 V_22 ;
T_1 V_373 ;
void * V_386 ;
V_376 = F_168 ( V_12 -> V_50 +
sizeof( struct V_279 ) * ( 1 + V_360 ) ) ;
V_386 = F_149 ( V_376 ) ;
if ( F_122 ( ! V_386 ) ) {
F_26 ( V_7 , L_39 ,
V_376 ) ;
return - V_154 ;
}
V_19 = F_137 ( V_12 , V_310 , V_283 ,
V_386 + V_382 ) ;
if ( F_122 ( V_19 < 0 ) ) {
if ( F_143 () )
F_14 ( V_12 , V_332 , V_7 , L_37 ,
V_19 ) ;
goto V_387;
}
V_280 = (struct V_279 * ) ( V_386 + V_12 -> V_50 ) ;
F_182 ( & V_280 [ 0 ] , F_183 ( V_310 ) ) ;
V_280 [ 0 ] . V_105 = V_112 ;
V_280 [ 0 ] . V_380 = 0 ;
V_22 = F_134 ( V_14 , V_310 -> V_285 ,
F_183 ( V_310 ) , V_357 ) ;
if ( F_122 ( F_135 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_79 ;
goto V_388;
}
F_184 ( & V_280 [ 0 ] , V_22 ) ;
V_385 = & F_157 ( V_310 ) -> V_389 [ 0 ] ;
V_373 = V_385 -> V_109 ;
for ( V_5 = 1 ; V_5 <= V_360 ; V_5 ++ , V_385 ++ ) {
F_40 ( ! F_185 ( V_385 ) ) ;
V_22 = F_186 ( V_14 , V_385 , 0 ,
V_373 , V_357 ) ;
if ( F_122 ( F_135 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_79 ;
goto V_390;
}
F_182 ( & V_280 [ V_5 ] , V_373 ) ;
V_280 [ V_5 ] . V_105 = V_112 ;
V_280 [ V_5 ] . V_380 = 0 ;
F_184 ( & V_280 [ V_5 ] , V_22 ) ;
V_373 = V_385 -> V_109 ;
}
F_187 ( & V_280 [ V_5 - 1 ] , V_373 ) ;
F_188 ( V_283 , V_12 -> V_50 , V_310 -> V_383 ) ;
V_381 = ( void * ) V_280 - V_12 -> V_50 ;
V_359 = (struct V_228 * * ) V_381 ;
* V_359 = V_310 ;
V_22 = F_134 ( V_14 , V_381 , V_12 -> V_50 +
sizeof( struct V_279 ) * ( 1 + V_360 ) ,
V_357 ) ;
if ( F_122 ( F_135 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_29 ) ;
V_19 = - V_79 ;
goto V_391;
}
V_283 -> V_105 = V_112 ;
V_283 -> V_342 |= F_147 ( V_384 ) ;
F_180 ( V_283 , V_22 ) ;
return 0 ;
V_391:
V_390:
for ( V_67 = 0 ; V_67 < V_5 ; V_67 ++ )
F_160 ( V_14 , F_158 ( & V_280 [ V_67 ] ) ,
F_159 ( & V_280 [ V_67 ] ) , V_357 ) ;
V_388:
V_387:
F_161 ( V_386 ) ;
return V_19 ;
}
static inline int F_189 ( struct V_11 * V_12 ,
struct V_61 * V_392 ,
int V_393 ,
struct V_282 * V_283 )
{
struct V_190 * V_394 ;
int V_19 , V_5 ;
V_394 = V_12 -> V_207 [ V_393 ] ;
if ( V_283 -> V_105 == V_112 )
V_283 -> V_342 |= F_147 ( F_106 ( V_12 -> V_208 [ V_393 ] ) ) ;
F_190 ( V_12 -> V_7 , V_394 , V_283 ) ;
for ( V_5 = 0 ; V_5 < V_395 ; V_5 ++ ) {
V_19 = F_191 ( V_394 , V_283 ) ;
if ( V_19 != - V_396 )
break;
}
if ( F_122 ( V_19 < 0 ) ) {
V_392 -> V_60 ++ ;
V_392 -> V_397 ++ ;
return V_19 ;
}
V_392 -> V_398 ++ ;
V_392 -> V_399 += F_171 ( V_283 ) ;
return 0 ;
}
static int F_192 ( struct V_228 * V_310 , struct V_6 * V_7 )
{
const int V_400 = F_193 ( V_310 ) ;
bool V_401 = F_194 ( V_310 ) ;
struct V_61 * V_392 ;
struct V_16 * V_17 ;
struct V_11 * V_12 ;
struct V_282 V_283 ;
int V_380 = 0 ;
int V_19 = 0 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_392 = & V_17 -> V_59 ;
F_195 ( & V_283 ) ;
if ( ! V_401 ) {
if ( F_196 ( V_310 , V_12 -> V_50 ) )
goto V_402;
F_40 ( F_194 ( V_310 ) ) ;
}
if ( V_401 &&
F_152 ( F_157 ( V_310 ) -> V_360 < V_377 ) ) {
V_19 = F_181 ( V_12 , V_310 , & V_283 ) ;
V_17 -> V_403 ++ ;
} else {
if ( F_122 ( V_401 ) && F_197 ( V_310 ) )
goto V_402;
V_19 = F_178 ( V_12 , V_310 , & V_283 , & V_380 ) ;
}
if ( F_122 ( V_19 < 0 ) )
goto V_404;
if ( F_152 ( F_189 ( V_12 , V_392 , V_400 , & V_283 ) == 0 ) )
return V_405 ;
F_156 ( V_12 , & V_283 ) ;
V_404:
V_402:
V_392 -> V_60 ++ ;
F_198 ( V_310 ) ;
return V_405 ;
}
static void F_199 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_282 * V_283 ,
T_4 V_137 )
{
if ( F_143 () )
F_14 ( V_12 , V_75 , V_7 , L_40 ,
F_164 ( V_283 -> V_361 ) & V_406 ) ;
V_17 -> V_59 . V_407 ++ ;
if ( F_164 ( V_283 -> V_361 ) & V_408 )
V_17 -> V_407 . V_409 ++ ;
if ( F_164 ( V_283 -> V_361 ) & V_410 )
V_17 -> V_407 . V_411 ++ ;
if ( F_164 ( V_283 -> V_361 ) & V_412 )
V_17 -> V_407 . V_413 ++ ;
if ( F_164 ( V_283 -> V_361 ) & V_414 )
V_17 -> V_407 . V_415 ++ ;
F_128 ( V_7 , V_283 ) ;
}
static void F_200 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_282 * V_283 ,
T_4 V_137 )
{
struct V_228 * V_310 ;
if ( F_143 () )
F_201 ( V_12 , V_75 , V_7 , L_41 ,
F_164 ( V_283 -> V_361 ) & V_416 ) ;
V_17 -> V_59 . V_60 ++ ;
V_310 = F_156 ( V_12 , V_283 ) ;
F_198 ( V_310 ) ;
}
static int F_202 ( struct V_417 * V_418 , int V_419 )
{
struct V_420 * V_421 =
F_77 ( V_418 , struct V_420 , V_418 ) ;
int V_422 = F_203 ( V_421 -> V_423 , V_419 ) ;
if ( V_422 < V_419 ) {
F_204 ( V_418 , V_422 ) ;
F_205 ( V_421 -> V_423 , V_424 ) ;
} else if ( V_421 -> V_425 ) {
F_205 ( V_421 -> V_423 , V_424 ) ;
}
return V_422 ;
}
static void F_206 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_282 * V_283 ,
T_4 V_137 )
{
struct V_228 * V_310 ;
if ( F_122 ( F_164 ( V_283 -> V_361 ) & V_416 ) ) {
if ( F_143 () )
F_201 ( V_12 , V_75 , V_7 , L_41 ,
F_164 ( V_283 -> V_361 ) &
V_416 ) ;
V_17 -> V_59 . V_60 ++ ;
}
V_17 -> V_426 ++ ;
V_310 = F_156 ( V_12 , V_283 ) ;
F_207 ( V_310 ) ;
}
static inline int F_208 ( struct V_16 * V_17 ,
struct V_159 * V_160 )
{
if ( F_122 ( F_209 () || ! F_210 () ) ) {
F_211 ( V_160 , V_424 ) ;
V_17 -> V_421 . V_423 = V_160 ;
F_212 ( & V_17 -> V_421 . V_418 ) ;
V_17 -> V_427 ++ ;
return 1 ;
}
return 0 ;
}
static enum V_428 F_213 ( struct V_159 * V_160 ,
struct V_190 * V_125 ,
const struct V_429 * V_430 )
{
struct V_124 * V_124 = F_77 ( V_125 , struct V_124 , V_145 ) ;
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_104 * V_104 ;
struct V_11 * V_12 ;
V_7 = V_124 -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_104 = F_39 ( V_430 -> V_283 . V_105 ) ;
if ( ! V_104 )
return V_431 ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_208 ( V_17 , V_160 ) )
return V_432 ;
if ( F_155 ( V_12 ) )
F_128 ( V_7 , & V_430 -> V_283 ) ;
else
F_199 ( V_7 , V_12 , V_17 , & V_430 -> V_283 , V_125 -> V_137 ) ;
return V_431 ;
}
static enum V_428 F_214 ( struct V_159 * V_160 ,
struct V_190 * V_125 ,
const struct V_429 * V_430 )
{
struct V_61 * V_392 ;
struct V_16 * V_17 ;
const struct V_282 * V_283 = & V_430 -> V_283 ;
T_6 V_22 = F_129 ( V_283 ) ;
enum V_433 V_434 ;
struct V_6 * V_7 ;
T_4 V_435 , V_436 ;
struct V_104 * V_104 ;
struct V_11 * V_12 ;
unsigned int V_437 ;
struct V_228 * V_310 ;
int * V_350 ;
void * V_284 ;
V_435 = F_164 ( V_283 -> V_361 ) ;
V_434 = F_130 ( V_283 ) ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_104 = F_39 ( V_430 -> V_283 . V_105 ) ;
if ( ! V_104 )
return V_431 ;
F_215 ( V_7 , V_125 , & V_430 -> V_283 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_392 = & V_17 -> V_59 ;
if ( F_122 ( F_208 ( V_17 , V_160 ) ) )
return V_432 ;
if ( F_122 ( F_155 ( V_12 ) ) ) {
F_128 ( V_7 , & V_430 -> V_283 ) ;
return V_431 ;
}
if ( F_122 ( V_435 & V_406 ) != 0 ) {
if ( F_143 () )
F_201 ( V_12 , V_75 , V_7 , L_41 ,
V_435 & V_406 ) ;
V_392 -> V_407 ++ ;
F_128 ( V_7 , V_283 ) ;
return V_431 ;
}
V_104 = F_39 ( V_283 -> V_105 ) ;
if ( ! V_104 )
return V_431 ;
F_133 ( V_104 -> V_14 , V_22 , V_104 -> V_109 , V_287 ) ;
V_284 = F_131 ( V_22 ) ;
F_216 ( V_284 + F_132 ( V_283 ) ) ;
V_434 = F_130 ( V_283 ) ;
F_40 ( ( V_434 != V_438 ) && ( V_434 != V_286 ) ) ;
V_350 = F_19 ( V_104 -> V_351 ) ;
( * V_350 ) -- ;
if ( F_152 ( V_434 == V_438 ) )
V_310 = F_165 ( V_12 , V_283 ) ;
else
V_310 = F_172 ( V_12 , V_283 ) ;
if ( ! V_310 )
return V_431 ;
V_310 -> V_315 = F_217 ( V_310 , V_7 ) ;
if ( V_7 -> V_37 & V_34 && V_12 -> V_439 &&
! F_218 ( V_12 -> V_21 -> V_55 [ V_276 ] ,
& V_436 ) ) {
enum V_440 type ;
type = F_164 ( V_283 -> V_361 ) & V_362 ?
V_441 : V_442 ;
F_219 ( V_310 , F_164 ( * ( T_4 * ) ( V_284 + V_436 ) ) ,
type ) ;
}
V_437 = V_310 -> V_383 ;
if ( F_122 ( F_220 ( V_310 ) == V_443 ) )
return V_431 ;
V_392 -> V_444 ++ ;
V_392 -> V_445 += V_437 ;
return V_431 ;
}
static enum V_428 F_221 ( struct V_159 * V_160 ,
struct V_190 * V_125 ,
const struct V_429 * V_430 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_208 ( V_17 , V_160 ) )
return V_432 ;
F_200 ( V_7 , V_12 , V_17 , & V_430 -> V_283 , V_125 -> V_137 ) ;
return V_431 ;
}
static enum V_428 F_222 ( struct V_159 * V_160 ,
struct V_190 * V_125 ,
const struct V_429 * V_430 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
F_223 ( V_7 , V_125 , & V_430 -> V_283 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_208 ( V_17 , V_160 ) )
return V_432 ;
F_206 ( V_7 , V_12 , V_17 , & V_430 -> V_283 , V_125 -> V_137 ) ;
return V_431 ;
}
static void V_206 ( struct V_159 * V_160 ,
struct V_190 * V_125 ,
const union V_288 * V_289 )
{
const struct V_282 * V_283 = & V_289 -> V_290 . V_283 ;
struct V_16 * V_17 ;
const struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_228 * V_310 ;
V_7 = ( (struct V_124 * ) V_125 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_17 -> V_59 . V_446 ++ ;
V_17 -> V_59 . V_397 ++ ;
F_136 ( V_17 , V_289 ) ;
V_310 = F_156 ( V_12 , V_283 ) ;
F_224 ( V_310 ) ;
}
static void F_225 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_421 . V_425 = 0 ;
F_226 ( & V_17 -> V_421 . V_418 ) ;
}
}
static void F_227 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_421 . V_425 = 1 ;
F_228 ( & V_17 -> V_421 . V_418 ) ;
}
}
static int F_229 ( struct V_6 * V_7 )
{
struct V_52 * V_21 ;
struct V_11 * V_12 ;
int V_19 , V_5 ;
V_12 = F_3 ( V_7 ) ;
V_21 = V_12 -> V_21 ;
F_225 ( V_12 ) ;
V_7 -> V_56 = V_21 -> V_447 ( V_7 , V_12 -> V_21 ) ;
if ( ! V_7 -> V_56 ) {
F_14 ( V_12 , V_448 , V_7 , L_42 ) ;
V_19 = - V_90 ;
goto V_449;
}
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_55 ) ; V_5 ++ ) {
V_19 = F_230 ( V_21 -> V_55 [ V_5 ] ) ;
if ( V_19 )
goto V_450;
}
V_19 = V_12 -> V_21 -> V_24 ( V_21 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_448 , V_7 , L_43 , V_19 ) ;
goto V_450;
}
F_231 ( V_7 ) ;
return 0 ;
V_450:
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_55 ) ; V_5 ++ )
F_16 ( V_21 -> V_55 [ V_5 ] ) ;
V_449:
F_227 ( V_12 ) ;
return V_19 ;
}
static int F_232 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
int V_19 ;
V_19 = F_11 ( V_7 ) ;
V_12 = F_3 ( V_7 ) ;
F_227 ( V_12 ) ;
return V_19 ;
}
static int F_233 ( struct V_6 * V_7 , struct V_451 * V_452 , int V_342 )
{
if ( ! V_7 -> V_56 )
return - V_79 ;
return F_234 ( V_7 -> V_56 , V_452 , V_342 ) ;
}
static int F_235 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_161 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_161 ) ;
F_236 ( V_7 , & V_17 -> V_421 . V_418 ,
F_202 , V_453 ) ;
}
return 0 ;
}
static void F_237 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_161 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_161 ) ;
F_238 ( & V_17 -> V_421 . V_418 ) ;
}
}
static inline void F_239 ( const struct V_104 * V_116 ,
struct V_119 * V_120 )
{
T_6 V_22 = F_240 ( V_120 ) ;
F_133 ( V_116 -> V_14 , V_22 , V_116 -> V_109 , V_287 ) ;
F_161 ( F_131 ( V_22 ) ) ;
}
static struct V_104 * F_241 ( struct V_13 * V_14 )
{
struct V_104 * V_104 ;
V_104 = F_58 ( V_14 , sizeof( * V_104 ) , V_142 ) ;
if ( ! V_104 )
return F_31 ( - V_154 ) ;
V_104 -> V_105 = V_112 ;
V_104 -> V_351 = F_242 ( V_14 , * V_104 -> V_351 ) ;
if ( ! V_104 -> V_351 )
return F_31 ( - V_154 ) ;
V_104 -> V_110 = V_355 ;
V_104 -> V_114 = F_153 ;
V_104 -> V_121 = F_239 ;
return V_104 ;
}
static int F_243 ( struct V_11 * V_12 )
{
struct V_170 V_171 ;
T_4 V_172 ;
int V_19 ;
V_19 = F_80 ( & V_12 -> V_235 . V_173 ) ;
if ( V_19 < 0 ) {
if ( F_81 ( V_12 ) )
F_46 ( L_44 , V_19 ) ;
goto V_174;
}
memset ( & V_171 , 0 , sizeof( V_171 ) ) ;
V_171 . V_176 = F_82 ( V_178 ) ;
V_171 . V_164 . V_179 = V_180 ;
V_172 = V_454 ;
F_83 ( & V_171 . V_164 . V_185 , V_172 , 1 ) ;
V_171 . V_176 |= F_82 ( V_186 ) ;
V_171 . V_164 . V_187 = V_180 ;
V_19 = F_84 ( & V_12 -> V_235 , V_188 ,
& V_171 ) ;
if ( V_19 < 0 ) {
if ( F_81 ( V_12 ) )
F_46 ( L_45 ,
V_19 , V_12 -> V_235 . V_173 ) ;
F_85 ( V_12 -> V_235 . V_173 ) ;
goto V_174;
}
if ( F_81 ( V_12 ) )
F_86 ( L_46 ,
V_12 -> V_235 . V_173 , V_12 -> V_21 -> V_22 ) ;
V_12 -> V_234 = true ;
V_174:
return V_19 ;
}
static inline T_3 F_244 ( struct V_248 * V_455 )
{
T_3 V_456 ;
V_456 = ( T_3 ) ( V_455 -> V_254 + V_457 +
V_458 + V_459 ) ;
return V_259 ? F_62 ( V_456 ,
V_259 ) :
V_456 ;
}
static int F_245 ( struct V_81 * V_82 )
{
struct V_104 * V_123 [ V_122 ] = { NULL } ;
struct V_16 * V_17 ;
struct V_6 * V_7 = NULL ;
struct V_124 * V_124 , * V_245 ;
struct V_11 * V_12 = NULL ;
struct V_143 V_144 ;
struct V_52 * V_21 ;
int V_19 = 0 , V_5 , V_157 ;
struct V_13 * V_14 ;
V_14 = & V_82 -> V_14 ;
V_7 = F_246 ( sizeof( * V_12 ) , V_136 ) ;
if ( ! V_7 ) {
F_10 ( V_14 , L_47 ) ;
goto V_460;
}
F_247 ( V_7 , V_14 ) ;
F_248 ( V_14 , V_7 ) ;
V_12 = F_3 ( V_7 ) ;
V_12 -> V_7 = V_7 ;
V_12 -> V_461 = F_249 ( V_462 , V_463 ) ;
V_21 = F_30 ( V_82 ) ;
if ( F_250 ( V_21 ) ) {
F_10 ( V_14 , L_48 ) ;
V_19 = F_251 ( V_21 ) ;
goto V_464;
}
V_7 -> V_465 = F_100 ( F_6 () , V_466 ) ;
F_252 ( V_7 , L_49 ,
V_7 -> V_465 ) ;
V_12 -> V_249 [ V_276 ] . V_254 = V_467 ;
V_12 -> V_249 [ V_278 ] . V_254 = V_382 ;
F_253 ( V_14 , F_254 ( & V_82 -> V_14 ) ) ;
V_19 = F_255 ( V_14 , F_256 ( 40 ) ) ;
if ( V_19 ) {
F_10 ( V_14 , L_50 ) ;
goto V_468;
}
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ ) {
int V_19 ;
V_123 [ V_5 ] = F_241 ( V_14 ) ;
if ( F_250 ( V_123 [ V_5 ] ) )
return F_251 ( V_123 [ V_5 ] ) ;
V_123 [ V_5 ] -> V_346 = F_1 ( V_5 , V_122 ) ;
V_123 [ V_5 ] -> V_109 = F_257 ( V_123 [ V_5 ] -> V_346 ) ;
V_123 [ V_5 ] -> V_14 = V_14 ;
V_19 = F_45 ( V_123 [ V_5 ] ) ;
if ( V_19 < 0 ) {
F_54 ( V_12 ) ;
V_12 -> V_123 [ V_5 ] = NULL ;
goto V_469;
}
V_12 -> V_123 [ V_5 ] = V_123 [ V_5 ] ;
}
F_258 ( & V_12 -> V_470 ) ;
memset ( & V_144 , 0 , sizeof( V_144 ) ) ;
V_19 = F_60 ( V_14 , & V_12 -> V_470 , & V_144 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_51 ) ;
goto V_471;
}
V_12 -> V_21 = V_21 ;
V_157 = F_64 () ;
if ( V_157 < 0 ) {
F_10 ( V_14 , L_52 ) ;
V_19 = V_157 ;
goto V_472;
}
V_12 -> V_157 = ( T_3 ) V_157 ;
F_70 ( V_12 -> V_157 ) ;
F_90 ( V_12 , & V_196 , V_12 -> V_21 -> V_55 [ V_278 ] ) ;
V_19 = F_79 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_53 ) ;
goto V_473;
}
V_19 = F_243 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_54 ) ;
goto V_474;
}
F_113 (dpaa_fq, tmp, &priv->dpaa_fq_list, list) {
V_19 = F_95 ( V_124 , false ) ;
if ( V_19 < 0 )
goto V_147;
}
V_12 -> V_50 = F_244 ( & V_12 -> V_249 [ V_278 ] ) ;
V_12 -> V_368 = F_244 ( & V_12 -> V_249 [ V_276 ] ) ;
V_19 = F_119 ( V_21 , V_123 , V_122 , & V_144 ,
& V_12 -> V_249 [ 0 ] , V_14 ) ;
if ( V_19 )
goto V_475;
V_12 -> V_439 = true ;
V_12 -> V_17 = F_242 ( V_14 , * V_12 -> V_17 ) ;
if ( ! V_12 -> V_17 ) {
F_10 ( V_14 , L_55 ) ;
V_19 = - V_154 ;
goto V_476;
}
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
}
V_12 -> V_72 = 1 ;
F_29 ( V_7 , V_12 -> V_72 * V_80 ) ;
V_19 = F_235 ( V_7 ) ;
if ( V_19 < 0 )
goto V_477;
V_19 = F_2 ( V_7 , & V_9 , V_10 ) ;
if ( V_19 < 0 )
goto V_478;
F_259 ( & V_7 -> V_14 ) ;
F_260 ( V_12 , V_479 , V_7 , L_56 ,
V_7 -> V_480 ) ;
return 0 ;
V_478:
V_477:
F_237 ( V_7 ) ;
V_476:
V_475:
F_112 ( V_14 , & V_12 -> V_470 ) ;
V_147:
F_261 ( & V_12 -> V_235 ) ;
F_85 ( V_12 -> V_235 . V_173 ) ;
V_474:
F_261 ( & V_12 -> V_166 . V_164 ) ;
F_85 ( V_12 -> V_166 . V_164 . V_173 ) ;
V_473:
V_472:
F_54 ( V_12 ) ;
V_469:
V_471:
V_468:
V_464:
F_248 ( V_14 , NULL ) ;
F_262 ( V_7 ) ;
V_460:
for ( V_5 = 0 ; V_5 < V_122 && V_123 [ V_5 ] ; V_5 ++ ) {
if ( F_263 ( & V_123 [ V_5 ] -> V_108 ) == 0 )
F_264 ( V_14 , V_123 [ V_5 ] ) ;
}
return V_19 ;
}
static int F_265 ( struct V_81 * V_82 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_19 ;
V_14 = & V_82 -> V_14 ;
V_7 = F_34 ( V_14 ) ;
V_12 = F_3 ( V_7 ) ;
F_266 ( V_14 ) ;
F_248 ( V_14 , NULL ) ;
F_267 ( V_7 ) ;
V_19 = F_112 ( V_14 , & V_12 -> V_470 ) ;
F_261 ( & V_12 -> V_235 ) ;
F_85 ( V_12 -> V_235 . V_173 ) ;
F_261 ( & V_12 -> V_166 . V_164 ) ;
F_85 ( V_12 -> V_166 . V_164 . V_173 ) ;
F_237 ( V_7 ) ;
F_54 ( V_12 ) ;
F_262 ( V_7 ) ;
return V_19 ;
}
static int T_9 F_268 ( void )
{
int V_19 ;
F_86 ( L_57 ) ;
V_481 = F_269 () ;
V_482 = F_270 () ;
V_19 = F_271 ( & V_483 ) ;
if ( V_19 < 0 )
F_46 ( L_58 , V_19 ) ;
return V_19 ;
}
static void T_10 F_272 ( void )
{
F_273 ( & V_483 ) ;
F_68 () ;
}
