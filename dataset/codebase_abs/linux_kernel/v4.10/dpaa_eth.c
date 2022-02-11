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
V_7 -> V_38 |= V_39 ;
V_7 -> V_38 &= ~ V_40 ;
V_7 -> V_36 |= V_7 -> V_30 ;
V_7 -> V_41 = V_7 -> V_36 ;
memcpy ( V_7 -> V_42 , V_18 , V_7 -> V_43 ) ;
memcpy ( V_7 -> V_44 , V_18 , V_7 -> V_43 ) ;
V_7 -> V_45 = & V_46 ;
V_7 -> V_47 = V_12 -> V_48 ;
V_7 -> V_49 = F_7 ( V_10 ) ;
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
struct V_50 * V_21 ;
struct V_11 * V_12 ;
int V_5 , V_19 , error ;
V_12 = F_3 ( V_7 ) ;
V_21 = V_12 -> V_21 ;
F_12 ( V_7 ) ;
F_13 ( 5000 , 10000 ) ;
V_19 = V_21 -> V_51 ( V_21 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_52 , V_7 , L_2 ,
V_19 ) ;
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_53 ) ; V_5 ++ ) {
error = F_16 ( V_21 -> V_53 [ V_5 ] ) ;
if ( error )
V_19 = error ;
}
if ( V_7 -> V_54 )
F_17 ( V_7 -> V_54 ) ;
V_7 -> V_54 = NULL ;
return V_19 ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_16 * V_17 ;
const struct V_11 * V_12 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
F_20 ( V_12 , V_55 , V_7 , L_3 ,
F_21 ( V_56 - F_22 ( V_7 ) ) ) ;
V_17 -> V_57 . V_58 ++ ;
}
static struct V_59 * F_23 ( struct V_6 * V_7 ,
struct V_59 * V_60 )
{
int V_61 = sizeof( struct V_59 ) / sizeof( V_62 ) ;
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
V_62 * V_63 = ( V_62 * ) V_60 ;
V_62 * V_64 ;
int V_5 , V_65 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_64 = ( V_62 * ) & V_17 -> V_57 ;
for ( V_65 = 0 ; V_65 < V_61 ; V_65 ++ )
V_63 [ V_65 ] += V_64 [ V_65 ] ;
}
return V_60 ;
}
static struct V_50 * F_24 ( struct V_66 * V_67 )
{
struct V_66 * V_68 ;
struct V_69 * V_70 ;
struct V_13 * V_71 , * V_14 ;
struct V_72 * V_73 ;
struct V_50 * V_21 ;
V_71 = & V_67 -> V_14 ;
V_70 = V_71 -> V_74 ;
if ( ! V_70 )
return F_25 ( - V_75 ) ;
V_73 = V_70 -> V_73 ;
V_68 = F_26 ( V_73 ) ;
if ( ! V_68 ) {
F_10 ( V_71 , L_4 ,
V_73 -> V_76 ) ;
F_27 ( V_73 ) ;
return F_25 ( - V_77 ) ;
}
F_27 ( V_73 ) ;
V_14 = & V_68 -> V_14 ;
V_21 = F_28 ( V_14 ) ;
if ( ! V_21 ) {
F_10 ( V_71 , L_5 ,
F_29 ( V_14 ) ) ;
return F_25 ( - V_77 ) ;
}
return V_21 ;
}
static int F_30 ( struct V_6 * V_7 , void * V_22 )
{
const struct V_11 * V_12 ;
struct V_50 * V_21 ;
struct V_78 V_79 ;
int V_19 ;
V_12 = F_3 ( V_7 ) ;
memcpy ( V_79 . V_80 , V_7 -> V_44 , V_81 ) ;
V_19 = F_31 ( V_7 , V_22 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_82 , V_7 , L_6 , V_19 ) ;
return V_19 ;
}
V_21 = V_12 -> V_21 ;
V_19 = V_21 -> V_83 ( V_21 -> V_84 ,
( V_85 * ) V_7 -> V_44 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_82 , V_7 , L_7 ,
V_19 ) ;
F_31 ( V_7 , & V_79 ) ;
return V_19 ;
}
return 0 ;
}
static void F_32 ( struct V_6 * V_7 )
{
const struct V_11 * V_12 ;
int V_19 ;
V_12 = F_3 ( V_7 ) ;
if ( ! ! ( V_7 -> V_86 & V_87 ) != V_12 -> V_21 -> V_88 ) {
V_12 -> V_21 -> V_88 = ! V_12 -> V_21 -> V_88 ;
V_19 = V_12 -> V_21 -> V_89 ( V_12 -> V_21 -> V_84 ,
V_12 -> V_21 -> V_88 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_82 , V_7 ,
L_8 ,
V_19 ) ;
}
V_19 = V_12 -> V_21 -> V_90 ( V_7 , V_12 -> V_21 ) ;
if ( V_19 < 0 )
F_14 ( V_12 , V_82 , V_7 , L_9 ,
V_19 ) ;
}
static struct V_91 * F_33 ( int V_92 )
{
if ( F_34 ( V_92 < 0 || V_92 >= V_93 ) )
return NULL ;
return V_94 [ V_92 ] ;
}
static bool F_35 ( int V_92 )
{
if ( F_33 ( V_92 ) ) {
F_36 ( & V_94 [ V_92 ] -> V_95 ) ;
return true ;
}
return false ;
}
static void F_37 ( int V_92 , struct V_91 * V_91 )
{
V_94 [ V_92 ] = V_91 ;
F_38 ( & V_91 -> V_95 , 1 ) ;
}
static int F_39 ( struct V_91 * V_91 )
{
int V_19 ;
if ( V_91 -> V_96 == 0 || V_91 -> V_97 == 0 ) {
F_40 ( L_10 ,
V_98 ) ;
return - V_77 ;
}
if ( V_91 -> V_92 != V_99 &&
F_35 ( V_91 -> V_92 ) )
return 0 ;
if ( V_91 -> V_92 == V_99 ) {
V_91 -> V_100 = F_41 () ;
if ( ! V_91 -> V_100 ) {
F_40 ( L_11 ,
V_98 ) ;
return - V_75 ;
}
V_91 -> V_92 = ( T_2 ) F_42 ( V_91 -> V_100 ) ;
}
if ( V_91 -> V_101 ) {
V_19 = V_91 -> V_101 ( V_91 ) ;
if ( V_19 )
goto V_102;
}
F_37 ( V_91 -> V_92 , V_91 ) ;
return 0 ;
V_102:
F_40 ( L_12 , V_98 ) ;
F_43 ( V_91 -> V_100 ) ;
return V_19 ;
}
static void F_44 ( struct V_91 * V_103 )
{
T_2 V_104 = 8 ;
int V_105 ;
do {
struct V_106 V_107 [ 8 ] ;
int V_5 ;
V_105 = F_45 ( V_103 -> V_100 , V_107 , V_104 ) ;
if ( V_105 < 0 ) {
if ( V_104 == 8 ) {
V_104 = 1 ;
V_105 = 1 ;
continue;
} else {
break;
}
}
if ( V_103 -> V_108 )
for ( V_5 = 0 ; V_5 < V_104 ; V_5 ++ )
V_103 -> V_108 ( V_103 , & V_107 [ V_5 ] ) ;
} while ( V_105 > 0 );
}
static void F_46 ( struct V_91 * V_91 )
{
struct V_91 * V_103 = F_33 ( V_91 -> V_92 ) ;
if ( ! V_103 )
return;
if ( ! F_47 ( & V_103 -> V_95 ) )
return;
if ( V_103 -> V_108 )
F_44 ( V_103 ) ;
V_94 [ V_103 -> V_92 ] = NULL ;
F_43 ( V_103 -> V_100 ) ;
}
static void F_48 ( struct V_11 * V_12 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_109 ; V_5 ++ )
F_46 ( V_12 -> V_110 [ V_5 ] ) ;
}
static inline void F_49 ( struct V_111 * V_112 )
{
switch ( V_112 -> V_113 ) {
case V_114 :
case V_115 :
V_112 -> V_116 = 1 ;
break;
case V_117 :
case V_118 :
V_112 -> V_116 = 2 ;
break;
case V_119 :
case V_120 :
V_112 -> V_116 = 3 ;
break;
default:
F_50 ( 1 , L_13 ,
V_112 -> V_113 , V_112 -> V_121 ) ;
}
}
static struct V_111 * F_51 ( struct V_13 * V_14 ,
T_4 V_24 , T_4 V_122 ,
struct V_123 * V_124 ,
enum V_125 V_113 )
{
struct V_111 * V_111 ;
int V_5 ;
V_111 = F_52 ( V_14 , sizeof( * V_111 ) * V_122 ,
V_126 ) ;
if ( ! V_111 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ ) {
V_111 [ V_5 ] . V_113 = V_113 ;
V_111 [ V_5 ] . V_121 = V_24 ? V_24 + V_5 : 0 ;
F_53 ( & V_111 [ V_5 ] . V_124 , V_124 ) ;
}
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ )
F_49 ( V_111 + V_5 ) ;
return V_111 ;
}
static int F_54 ( struct V_13 * V_14 , struct V_123 * V_124 ,
struct V_127 * V_128 )
{
struct V_111 * V_111 ;
V_111 = F_51 ( V_14 , 0 , 1 , V_124 , V_117 ) ;
if ( ! V_111 )
goto V_129;
V_128 -> V_130 = & V_111 [ 0 ] ;
V_111 = F_51 ( V_14 , 0 , 1 , V_124 , V_119 ) ;
if ( ! V_111 )
goto V_129;
V_128 -> V_131 = & V_111 [ 0 ] ;
if ( ! F_51 ( V_14 , 0 , V_132 , V_124 , V_115 ) )
goto V_129;
V_111 = F_51 ( V_14 , 0 , 1 , V_124 , V_118 ) ;
if ( ! V_111 )
goto V_129;
V_128 -> V_133 = & V_111 [ 0 ] ;
V_111 = F_51 ( V_14 , 0 , 1 , V_124 , V_114 ) ;
if ( ! V_111 )
goto V_129;
V_128 -> V_134 = & V_111 [ 0 ] ;
if ( ! F_51 ( V_14 , 0 , V_132 , V_124 , V_120 ) )
goto V_129;
return 0 ;
V_129:
F_10 ( V_14 , L_14 ) ;
return - V_135 ;
}
static int F_55 ( void )
{
F_56 ( & V_136 ) ;
if ( ! V_137 ) {
T_4 V_100 ;
int V_105 ;
V_105 = F_57 ( & V_100 ) ;
if ( ! V_105 )
V_137 = V_100 ;
}
F_58 ( & V_136 ) ;
if ( ! V_137 )
return - V_135 ;
return V_137 ;
}
static void F_59 ( void )
{
F_60 ( V_137 ) ;
}
static void F_61 ( T_3 V_138 )
{
T_4 V_100 = F_62 ( V_138 ) ;
const T_5 * V_139 = F_63 () ;
struct V_140 * V_141 ;
int V_142 ;
F_64 (cpu, cpus) {
V_141 = F_65 ( V_142 ) ;
F_66 ( V_141 , V_100 ) ;
}
}
static void F_67 ( struct V_140 * V_143 , struct V_144 * V_145 ,
int V_146 )
{
struct V_11 * V_12 = (struct V_11 * ) F_68 ( V_145 ,
struct V_11 , V_147 . V_145 ) ;
if ( V_146 ) {
V_12 -> V_147 . V_148 = V_56 ;
F_12 ( V_12 -> V_7 ) ;
V_12 -> V_147 . V_149 ++ ;
} else {
V_12 -> V_147 . V_150 +=
( V_56 - V_12 -> V_147 . V_148 ) ;
F_69 ( V_12 -> V_7 ) ;
}
}
static int F_70 ( struct V_11 * V_12 )
{
struct V_151 V_152 ;
T_4 V_153 ;
int V_19 ;
V_19 = F_71 ( & V_12 -> V_147 . V_145 . V_154 ) ;
if ( V_19 < 0 ) {
if ( F_72 ( V_12 ) )
F_40 ( L_15 ,
V_98 , V_19 ) ;
goto V_155;
}
V_12 -> V_147 . V_145 . V_156 = F_67 ;
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_157 = F_73 ( V_158 | V_159 ) ;
V_152 . V_145 . V_160 = V_161 ;
if ( V_12 -> V_21 -> V_162 & V_163 )
V_153 = V_164 ;
else
V_153 = V_165 ;
F_74 ( & V_152 . V_145 . V_166 , V_153 , 1 ) ;
V_152 . V_157 |= F_73 ( V_167 ) ;
V_152 . V_145 . V_168 = V_161 ;
V_19 = F_75 ( & V_12 -> V_147 . V_145 , V_169 ,
& V_152 ) ;
if ( V_19 < 0 ) {
if ( F_72 ( V_12 ) )
F_40 ( L_16 ,
V_98 , V_19 , V_12 -> V_147 . V_145 . V_154 ) ;
F_76 ( V_12 -> V_147 . V_145 . V_154 ) ;
goto V_155;
}
if ( F_72 ( V_12 ) )
F_77 ( L_17 ,
V_12 -> V_147 . V_145 . V_154 , V_12 -> V_21 -> V_22 ,
V_12 -> V_147 . V_145 . V_170 ) ;
V_155:
return V_19 ;
}
static inline void F_78 ( const struct V_11 * V_12 ,
struct V_111 * V_112 ,
const struct V_171 * V_172 )
{
V_112 -> V_173 = * V_172 ;
V_112 -> V_7 = V_12 -> V_7 ;
V_112 -> V_86 = V_174 ;
V_112 -> V_138 = V_12 -> V_138 ;
}
static inline void F_79 ( const struct V_11 * V_12 ,
struct V_111 * V_112 ,
struct V_175 * V_53 ,
const struct V_171 * V_172 )
{
V_112 -> V_173 = * V_172 ;
V_112 -> V_7 = V_12 -> V_7 ;
if ( V_53 ) {
V_112 -> V_86 = V_176 ;
V_112 -> V_138 = ( T_3 ) F_80 ( V_53 ) ;
} else {
V_112 -> V_86 = V_177 ;
}
}
static void F_81 ( struct V_11 * V_12 ,
const struct V_178 * V_179 ,
struct V_175 * V_180 )
{
int V_181 = 0 , V_182 = 0 , V_183 = 0 , V_142 ;
const T_5 * V_184 = F_63 () ;
T_3 V_185 [ V_186 ] ;
struct V_111 * V_112 ;
F_64 (cpu, affine_cpus)
V_185 [ V_183 ++ ] = F_82 ( V_142 ) ;
if ( V_183 == 0 )
F_10 ( V_12 -> V_7 -> V_14 . V_15 ,
L_18 ) ;
F_83 (fq, &priv->dpaa_fq_list, list) {
switch ( V_112 -> V_113 ) {
case V_119 :
F_78 ( V_12 , V_112 , & V_179 -> V_131 ) ;
break;
case V_117 :
F_78 ( V_12 , V_112 , & V_179 -> V_130 ) ;
break;
case V_120 :
F_79 ( V_12 , V_112 , V_180 ,
& V_179 -> V_187 ) ;
if ( V_181 < V_132 )
V_12 -> V_188 [ V_181 ++ ] = & V_112 -> V_173 ;
break;
case V_115 :
V_12 -> V_189 [ V_182 ++ ] = & V_112 -> V_173 ;
case V_114 :
F_78 ( V_12 , V_112 , & V_179 -> V_134 ) ;
break;
case V_118 :
F_78 ( V_12 , V_112 , & V_179 -> V_133 ) ;
break;
default:
F_84 ( V_12 -> V_7 -> V_14 . V_15 ,
L_19 ) ;
break;
}
}
while ( V_181 < V_132 ) {
F_83 (fq, &priv->dpaa_fq_list, list) {
if ( V_112 -> V_113 != V_120 )
continue;
V_12 -> V_188 [ V_181 ++ ] = & V_112 -> V_173 ;
if ( V_181 == V_132 )
break;
}
}
}
static inline int F_85 ( const struct V_11 * V_12 ,
struct V_171 * V_190 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_132 ; V_5 ++ )
if ( V_12 -> V_188 [ V_5 ] == V_190 )
return V_5 ;
return - V_77 ;
}
static int F_86 ( struct V_111 * V_111 , bool V_191 )
{
const struct V_11 * V_12 ;
struct V_171 * V_192 = NULL ;
struct V_193 V_194 ;
struct V_13 * V_14 ;
struct V_171 * V_112 ;
int V_195 ;
int V_19 ;
V_12 = F_3 ( V_111 -> V_7 ) ;
V_14 = V_111 -> V_7 -> V_14 . V_15 ;
if ( V_111 -> V_121 == 0 )
V_111 -> V_86 |= V_196 ;
V_111 -> V_197 = ! ( V_111 -> V_86 & V_177 ) ;
V_19 = F_87 ( V_111 -> V_121 , V_111 -> V_86 , & V_111 -> V_173 ) ;
if ( V_19 ) {
F_10 ( V_14 , L_20 ) ;
return V_19 ;
}
V_112 = & V_111 -> V_173 ;
if ( V_111 -> V_197 ) {
memset ( & V_194 , 0 , sizeof( V_194 ) ) ;
V_194 . V_157 = F_73 ( V_198 ) ;
V_194 . V_199 . V_200 = F_73 ( V_201 ) ;
if ( V_111 -> V_113 == V_114 )
V_194 . V_199 . V_200 |= F_73 ( V_202 ) ;
V_194 . V_157 |= F_73 ( V_203 ) ;
F_88 ( & V_194 . V_199 , V_111 -> V_138 , V_111 -> V_116 ) ;
if ( V_111 -> V_113 == V_120 ||
V_111 -> V_113 == V_114 ||
V_111 -> V_113 == V_115 ) {
V_194 . V_157 |= F_73 ( V_204 ) ;
V_194 . V_199 . V_200 |= F_73 ( V_205 ) ;
V_194 . V_199 . V_206 = ( T_2 ) V_12 -> V_147 . V_145 . V_154 ;
V_194 . V_157 |= F_73 ( V_207 ) ;
F_89 ( & V_194 . V_199 , V_208 ) ;
F_90 ( & V_194 . V_199 ,
F_91 ( sizeof( struct V_209 ) +
V_12 -> V_48 ,
( T_1 ) V_210 ) ) ;
}
if ( V_191 ) {
V_194 . V_157 |= F_73 ( V_211 ) ;
F_92 ( & V_194 . V_199 , V_212 , 1 ) ;
V_194 . V_199 . V_200 = F_73 ( V_213 ) ;
}
if ( V_111 -> V_113 == V_120 ) {
V_195 = F_85 ( V_12 , & V_111 -> V_173 ) ;
if ( V_195 >= 0 )
V_192 = V_12 -> V_189 [ V_195 ] ;
if ( V_192 ) {
V_194 . V_157 |=
F_73 ( V_214 ) ;
F_93 ( & V_194 . V_199 ,
0x1e00000080000000ULL ) ;
}
}
if ( V_12 -> V_215 &&
( V_111 -> V_113 == V_119 ||
V_111 -> V_113 == V_117 ) ) {
V_194 . V_157 |= F_73 ( V_204 ) ;
V_194 . V_199 . V_200 |= F_73 ( V_205 ) ;
V_194 . V_199 . V_206 = ( T_2 ) V_12 -> V_216 . V_154 ;
V_194 . V_157 |= F_73 ( V_207 ) ;
F_89 ( & V_194 . V_199 , V_208 ) ;
F_90 ( & V_194 . V_199 ,
F_91 ( sizeof( struct V_209 ) +
V_12 -> V_48 ,
( T_1 ) V_210 ) ) ;
}
if ( V_111 -> V_86 & V_174 ) {
V_194 . V_157 |= F_73 ( V_214 ) ;
V_194 . V_199 . V_200 |= F_73 ( V_202 ) ;
V_194 . V_199 . V_217 . V_218 . V_219 =
V_220 | V_221 |
V_222 ;
F_94 ( & V_194 . V_199 , 1 , 2 ,
F_95 ( sizeof( struct V_171 ) ,
64 ) ) ;
}
V_19 = F_96 ( V_112 , V_223 , & V_194 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_21 ,
F_97 ( V_112 ) , V_19 ) ;
F_98 ( V_112 ) ;
return V_19 ;
}
}
V_111 -> V_121 = F_97 ( V_112 ) ;
return 0 ;
}
static int F_99 ( struct V_13 * V_14 , struct V_171 * V_112 )
{
const struct V_11 * V_12 ;
struct V_111 * V_111 ;
int V_19 , error ;
V_19 = 0 ;
V_111 = F_68 ( V_112 , struct V_111 , V_173 ) ;
V_12 = F_3 ( V_111 -> V_7 ) ;
if ( V_111 -> V_197 ) {
V_19 = F_100 ( V_112 , NULL ) ;
if ( V_19 < 0 && F_72 ( V_12 ) )
F_10 ( V_14 , L_22 ,
F_97 ( V_112 ) , V_19 ) ;
error = F_101 ( V_112 ) ;
if ( error < 0 && F_72 ( V_12 ) ) {
F_10 ( V_14 , L_23 ,
F_97 ( V_112 ) , error ) ;
if ( V_19 >= 0 )
V_19 = error ;
}
}
F_98 ( V_112 ) ;
F_102 ( & V_111 -> V_124 ) ;
return V_19 ;
}
static int F_103 ( struct V_13 * V_14 , struct V_123 * V_124 )
{
struct V_111 * V_111 , * V_224 ;
int V_19 , error ;
V_19 = 0 ;
F_104 (dpaa_fq, tmp, list, list) {
error = F_99 ( V_14 , (struct V_171 * ) V_111 ) ;
if ( error < 0 && V_19 >= 0 )
V_19 = error ;
}
return V_19 ;
}
static void F_105 ( struct V_175 * V_53 , struct V_111 * V_225 ,
struct V_111 * V_226 ,
struct V_227 * V_228 )
{
struct V_229 V_230 ;
struct V_231 V_232 ;
int V_19 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_230 . V_233 = V_228 -> V_233 ;
V_230 . V_234 = true ;
V_230 . V_235 = true ;
V_230 . V_236 = false ;
V_230 . V_237 = V_238 ;
V_232 . V_239 . V_240 . V_241 = V_225 -> V_121 ;
V_232 . V_239 . V_240 . V_242 = V_226 -> V_121 ;
V_19 = F_106 ( V_53 , & V_232 ) ;
if ( V_19 )
F_40 ( L_24 , V_98 ) ;
V_19 = F_107 ( V_53 , & V_230 ) ;
if ( V_19 )
F_40 ( L_25 ,
V_98 ) ;
V_19 = F_108 ( V_53 ) ;
if ( V_19 )
F_40 ( L_26 , V_98 ) ;
}
static void F_109 ( struct V_175 * V_53 , struct V_91 * * V_243 ,
T_1 V_122 , struct V_111 * V_225 ,
struct V_111 * V_226 ,
struct V_227 * V_228 )
{
struct V_229 V_230 ;
struct V_244 * V_245 ;
struct V_231 V_232 ;
int V_5 , V_19 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_230 . V_233 = V_228 -> V_233 ;
V_230 . V_234 = true ;
V_230 . V_235 = true ;
V_230 . V_236 = false ;
V_230 . V_237 = V_238 ;
V_245 = & V_232 . V_239 . V_246 ;
V_245 -> V_241 = V_225 -> V_121 ;
V_245 -> V_242 = V_226 -> V_121 ;
V_122 = F_91 ( F_15 ( V_245 -> V_247 . V_248 ) , V_122 ) ;
V_245 -> V_247 . V_249 = ( T_2 ) V_122 ;
for ( V_5 = 0 ; V_5 < V_122 ; V_5 ++ ) {
V_245 -> V_247 . V_248 [ V_5 ] . V_250 = V_243 [ V_5 ] -> V_92 ;
V_245 -> V_247 . V_248 [ V_5 ] . V_96 = ( T_3 ) V_243 [ V_5 ] -> V_96 ;
}
V_19 = F_106 ( V_53 , & V_232 ) ;
if ( V_19 )
F_40 ( L_24 , V_98 ) ;
V_19 = F_107 ( V_53 , & V_230 ) ;
if ( V_19 )
F_40 ( L_25 ,
V_98 ) ;
V_19 = F_108 ( V_53 ) ;
if ( V_19 )
F_40 ( L_26 , V_98 ) ;
}
static void F_110 ( struct V_50 * V_21 ,
struct V_91 * * V_243 , T_1 V_122 ,
struct V_127 * V_128 ,
struct V_227 * V_228 ,
struct V_13 * V_14 )
{
struct V_175 * V_251 = V_21 -> V_53 [ V_252 ] ;
struct V_175 * V_253 = V_21 -> V_53 [ V_254 ] ;
F_105 ( V_253 , V_128 -> V_133 ,
V_128 -> V_134 , & V_228 [ V_254 ] ) ;
F_109 ( V_251 , V_243 , V_122 , V_128 -> V_130 ,
V_128 -> V_131 , & V_228 [ V_252 ] ) ;
}
static int F_111 ( const struct V_91 * V_91 ,
struct V_106 * V_107 , int V_2 )
{
int V_19 ;
V_19 = F_112 ( V_91 -> V_100 , V_107 , V_2 ) ;
if ( F_113 ( F_34 ( V_19 ) ) && V_91 -> V_108 )
while ( V_2 -- > 0 )
V_91 -> V_108 ( V_91 , & V_107 [ V_2 ] ) ;
return V_2 ;
}
static void F_114 ( struct V_255 * V_256 )
{
struct V_106 V_107 [ V_257 ] ;
struct V_91 * V_91 ;
int V_5 = 0 , V_65 ;
memset ( V_107 , 0 , sizeof( V_107 ) ) ;
do {
V_91 = F_33 ( V_256 [ V_5 ] . V_92 ) ;
if ( ! V_91 )
return;
V_65 = 0 ;
do {
F_34 ( F_115 ( & V_256 [ V_5 ] ) ) ;
F_116 ( & V_107 [ V_65 ] , F_117 ( & V_256 [ V_5 ] ) ) ;
V_65 ++ ; V_5 ++ ;
} while ( V_65 < F_15 ( V_107 ) &&
! F_118 ( & V_256 [ V_5 - 1 ] ) &&
V_256 [ V_5 - 1 ] . V_92 == V_256 [ V_5 ] . V_92 );
F_111 ( V_91 , V_107 , V_65 ) ;
} while ( ! F_118 ( & V_256 [ V_5 - 1 ] ) );
}
static void F_119 ( const struct V_6 * V_7 ,
const struct V_258 * V_259 )
{
struct V_255 * V_256 ;
struct V_91 * V_91 ;
struct V_106 V_107 ;
T_6 V_22 ;
void * V_260 ;
V_107 . V_261 = 0 ;
F_116 ( & V_107 , F_120 ( V_259 ) ) ;
V_91 = F_33 ( V_259 -> V_92 ) ;
if ( ! V_91 )
return;
if ( F_121 ( V_259 ) == V_262 ) {
V_260 = F_122 ( F_120 ( V_259 ) ) ;
V_256 = V_260 + F_123 ( V_259 ) ;
F_124 ( V_91 -> V_14 , F_120 ( V_259 ) , V_91 -> V_96 ,
V_263 ) ;
F_114 ( V_256 ) ;
V_22 = F_125 ( V_91 -> V_14 , V_260 , V_91 -> V_96 ,
V_263 ) ;
if ( F_126 ( V_91 -> V_14 , V_22 ) ) {
F_10 ( V_91 -> V_14 , L_27 ) ;
return;
}
F_116 ( & V_107 , V_22 ) ;
}
F_111 ( V_91 , & V_107 , 1 ) ;
}
static void F_127 ( struct V_16 * V_17 ,
const union V_264 * V_265 )
{
switch ( V_265 -> V_266 . V_267 & V_268 ) {
case V_269 :
V_17 -> V_270 . V_271 ++ ;
break;
case V_272 :
V_17 -> V_270 . V_273 ++ ;
break;
case V_274 :
V_17 -> V_270 . V_275 ++ ;
break;
case V_276 :
V_17 -> V_270 . V_277 ++ ;
break;
case V_278 :
V_17 -> V_270 . V_279 ++ ;
break;
case V_280 :
V_17 -> V_270 . V_281 ++ ;
break;
case V_282 :
V_17 -> V_270 . V_283 ++ ;
break;
case V_284 :
V_17 -> V_270 . V_285 ++ ;
break;
}
}
static int F_128 ( struct V_11 * V_12 ,
struct V_209 * V_286 ,
struct V_258 * V_259 ,
char * V_287 )
{
struct V_288 * V_289 ;
T_3 V_290 = F_129 ( V_286 -> V_291 ) ;
struct V_292 * V_293 = NULL ;
struct V_294 * V_295 ;
int V_296 = 0 ;
T_2 V_297 ;
if ( V_286 -> V_298 != V_299 )
return 0 ;
V_289 = (struct V_288 * ) V_287 ;
if ( V_290 == V_300 ) {
F_130 ( V_286 ) ;
V_290 = F_129 ( F_131 ( V_286 ) -> V_301 ) ;
}
switch ( V_290 ) {
case V_302 :
V_289 -> V_303 = F_73 ( V_304 ) ;
V_295 = F_132 ( V_286 ) ;
F_34 ( ! V_295 ) ;
V_297 = V_295 -> V_291 ;
break;
case V_305 :
V_289 -> V_303 = F_73 ( V_306 ) ;
V_293 = F_133 ( V_286 ) ;
F_34 ( ! V_293 ) ;
V_297 = V_293 -> V_307 ;
break;
default:
if ( F_134 () )
F_135 ( V_12 , V_308 , V_12 -> V_7 ,
L_28 ,
F_129 ( V_286 -> V_291 ) ) ;
V_296 = - V_309 ;
goto V_310;
}
switch ( V_297 ) {
case V_311 :
V_289 -> V_312 = V_313 ;
break;
case V_314 :
V_289 -> V_312 = V_315 ;
break;
default:
if ( F_134 () )
F_135 ( V_12 , V_308 , V_12 -> V_7 ,
L_29 ,
V_297 ) ;
V_296 = - V_309 ;
goto V_310;
}
V_289 -> V_316 [ 0 ] = ( T_2 ) F_136 ( V_286 ) ;
V_289 -> V_317 = ( T_2 ) F_137 ( V_286 ) ;
V_259 -> V_318 |= F_138 ( V_319 | V_320 ) ;
V_310:
return V_296 ;
}
static int F_139 ( const struct V_91 * V_91 )
{
struct V_13 * V_14 = V_91 -> V_14 ;
struct V_106 V_107 [ 8 ] ;
T_6 V_22 ;
void * V_321 ;
T_2 V_5 ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ ) {
V_321 = F_140 ( V_91 -> V_322 ) ;
if ( F_113 ( ! V_321 ) ) {
F_10 ( V_14 , L_30 ,
V_91 -> V_322 ) ;
goto V_323;
}
V_321 = F_141 ( V_321 , V_324 ) ;
V_22 = F_125 ( V_14 , V_321 ,
V_91 -> V_96 , V_263 ) ;
if ( F_113 ( F_126 ( V_14 , V_22 ) ) ) {
F_10 ( V_91 -> V_14 , L_31 ) ;
goto V_323;
}
V_107 [ V_5 ] . V_261 = 0 ;
F_116 ( & V_107 [ V_5 ] , V_22 ) ;
}
V_325:
return F_111 ( V_91 , V_107 , V_5 ) ;
V_323:
F_142 ( 1 , L_32 ) ;
F_116 ( & V_107 [ V_5 ] , 0 ) ;
if ( F_143 ( V_5 ) )
goto V_325;
return 0 ;
}
static int F_144 ( struct V_91 * V_91 )
{
int V_5 ;
F_4 (i) {
int * V_326 = F_5 ( V_91 -> V_327 , V_5 ) ;
int V_65 ;
for ( V_65 = 0 ; V_65 < V_91 -> V_97 ; V_65 += 8 )
* V_326 += F_139 ( V_91 ) ;
}
return 0 ;
}
static int F_145 ( struct V_91 * V_91 , int * V_328 )
{
int V_122 = * V_328 ;
int V_329 ;
if ( F_113 ( V_122 < V_330 ) ) {
do {
V_329 = F_139 ( V_91 ) ;
if ( F_113 ( ! V_329 ) ) {
break;
}
V_122 += V_329 ;
} while ( V_122 < V_331 );
* V_328 = V_122 ;
if ( F_113 ( V_122 < V_331 ) )
return - V_135 ;
}
return 0 ;
}
static int F_146 ( struct V_11 * V_12 )
{
struct V_91 * V_91 ;
int * V_328 ;
int V_3 , V_5 ;
for ( V_5 = 0 ; V_5 < V_109 ; V_5 ++ ) {
V_91 = V_12 -> V_110 [ V_5 ] ;
if ( ! V_91 )
return - V_77 ;
V_328 = F_19 ( V_91 -> V_327 ) ;
V_3 = F_145 ( V_91 , V_328 ) ;
if ( V_3 )
return V_3 ;
}
return 0 ;
}
static struct V_209 * F_147 ( const struct V_11 * V_12 ,
const struct V_258 * V_259 )
{
const enum V_332 V_333 = V_334 ;
struct V_13 * V_14 = V_12 -> V_7 -> V_14 . V_15 ;
T_6 V_22 = F_120 ( V_259 ) ;
const struct V_255 * V_256 ;
struct V_209 * * V_335 , * V_286 ;
int V_336 , V_5 ;
V_335 = (struct V_209 * * ) F_122 ( V_22 ) ;
V_286 = * V_335 ;
if ( F_113 ( F_121 ( V_259 ) == V_262 ) ) {
V_336 = F_148 ( V_286 ) -> V_336 ;
F_124 ( V_14 , V_22 , F_123 ( V_259 ) +
sizeof( struct V_255 ) * ( 1 + V_336 ) ,
V_333 ) ;
V_256 = F_122 ( V_22 + F_123 ( V_259 ) ) ;
F_124 ( V_14 , F_149 ( & V_256 [ 0 ] ) ,
F_150 ( & V_256 [ 0 ] ) , V_333 ) ;
for ( V_5 = 1 ; V_5 < V_336 ; V_5 ++ ) {
F_34 ( F_115 ( & V_256 [ V_5 ] ) ) ;
F_151 ( V_14 , F_149 ( & V_256 [ V_5 ] ) ,
F_150 ( & V_256 [ V_5 ] ) , V_333 ) ;
}
F_152 ( F_122 ( V_22 ) ) ;
} else {
F_124 ( V_14 , V_22 ,
F_153 ( V_286 ) - ( T_2 * ) V_335 , V_333 ) ;
}
return V_286 ;
}
static struct V_209 * F_154 ( const struct V_11 * V_12 ,
const struct V_258 * V_259 )
{
T_7 V_337 = F_123 ( V_259 ) ;
T_6 V_22 = F_120 ( V_259 ) ;
struct V_91 * V_91 ;
struct V_209 * V_286 ;
void * V_260 ;
V_260 = F_122 ( V_22 ) ;
F_34 ( ! F_155 ( ( unsigned long ) V_260 , V_324 ) ) ;
V_91 = F_33 ( V_259 -> V_92 ) ;
if ( ! V_91 )
goto V_338;
V_286 = F_156 ( V_260 , V_91 -> V_96 +
F_157 ( sizeof( struct V_339 ) ) ) ;
if ( F_113 ( ! V_286 ) ) {
F_142 ( 1 , L_33 ) ;
goto V_338;
}
F_34 ( V_337 != V_12 -> V_340 ) ;
F_158 ( V_286 , V_337 ) ;
F_159 ( V_286 , F_160 ( V_259 ) ) ;
V_286 -> V_298 = V_341 ;
return V_286 ;
V_338:
F_152 ( V_260 ) ;
return NULL ;
}
static struct V_209 * F_161 ( const struct V_11 * V_12 ,
const struct V_258 * V_259 )
{
T_7 V_337 = F_123 ( V_259 ) ;
T_6 V_22 = F_120 ( V_259 ) ;
const struct V_255 * V_256 ;
struct V_342 * V_342 , * V_343 ;
struct V_91 * V_91 ;
void * V_260 , * V_344 ;
int V_345 , V_346 ;
struct V_209 * V_286 ;
T_6 V_347 ;
int V_348 ;
unsigned int V_349 ;
int * V_326 ;
int V_5 ;
V_260 = F_122 ( V_22 ) ;
F_34 ( ! F_155 ( ( unsigned long ) V_260 , V_324 ) ) ;
V_256 = V_260 + V_337 ;
for ( V_5 = 0 ; V_5 < V_350 ; V_5 ++ ) {
F_34 ( F_115 ( & V_256 [ V_5 ] ) ) ;
V_347 = F_149 ( & V_256 [ V_5 ] ) ;
V_344 = F_122 ( V_347 ) ;
F_34 ( ! F_155 ( ( unsigned long ) V_344 ,
V_324 ) ) ;
V_91 = F_33 ( V_256 [ V_5 ] . V_92 ) ;
if ( ! V_91 )
goto V_351;
V_326 = F_19 ( V_91 -> V_327 ) ;
F_124 ( V_91 -> V_14 , V_347 , V_91 -> V_96 ,
V_263 ) ;
if ( V_5 == 0 ) {
V_349 = V_91 -> V_96 +
F_157 ( sizeof( struct V_339 ) ) ;
V_286 = F_156 ( V_344 , V_349 ) ;
if ( F_34 ( F_113 ( ! V_286 ) ) )
goto V_351;
V_286 -> V_298 = V_341 ;
F_34 ( V_337 != V_12 -> V_340 ) ;
F_158 ( V_286 , V_337 ) ;
F_159 ( V_286 , F_150 ( & V_256 [ V_5 ] ) ) ;
} else {
V_342 = F_162 ( V_344 ) ;
V_343 = F_163 ( V_344 ) ;
V_348 = ( ( unsigned long ) V_344 &
( V_352 - 1 ) ) +
( F_164 ( V_342 ) - F_164 ( V_343 ) ) ;
V_345 = F_165 ( & V_256 [ V_5 ] ) + V_348 ;
V_346 = F_150 ( & V_256 [ V_5 ] ) ;
F_166 ( V_286 , V_5 - 1 , V_343 , V_345 ,
V_346 , V_91 -> V_96 ) ;
}
( * V_326 ) -- ;
if ( F_118 ( & V_256 [ V_5 ] ) )
break;
}
F_142 ( V_5 == V_350 , L_34 ) ;
F_152 ( V_260 ) ;
return V_286 ;
V_351:
for ( V_5 -- ; V_5 >= 0 ; V_5 -- ) {
V_91 = F_33 ( V_256 [ V_5 ] . V_92 ) ;
if ( V_91 ) {
V_326 = F_19 ( V_91 -> V_327 ) ;
( * V_326 ) ++ ;
}
}
for ( V_5 = 0 ; V_5 < V_350 ; V_5 ++ ) {
V_347 = F_149 ( & V_256 [ V_5 ] ) ;
V_344 = F_122 ( V_347 ) ;
F_152 ( V_344 ) ;
V_91 = F_33 ( V_256 [ V_5 ] . V_92 ) ;
if ( V_91 ) {
V_326 = F_19 ( V_91 -> V_327 ) ;
( * V_326 ) -- ;
}
if ( F_118 ( & V_256 [ V_5 ] ) )
break;
}
F_152 ( V_260 ) ;
return NULL ;
}
static int F_167 ( struct V_11 * V_12 ,
struct V_209 * V_286 , struct V_258 * V_259 ,
int * V_353 )
{
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
enum V_332 V_333 ;
unsigned char * V_354 ;
struct V_209 * * V_335 ;
T_6 V_22 ;
int V_19 ;
V_259 -> V_92 = V_99 ;
V_354 = V_286 -> V_261 - V_12 -> V_48 ;
V_333 = V_334 ;
V_335 = (struct V_209 * * ) V_354 ;
* V_335 = V_286 ;
V_19 = F_128 ( V_12 , V_286 , V_259 ,
( ( char * ) V_335 ) + V_355 ) ;
if ( F_113 ( V_19 < 0 ) ) {
if ( F_134 () )
F_14 ( V_12 , V_308 , V_7 , L_35 ,
V_19 ) ;
return V_19 ;
}
F_168 ( V_259 , V_12 -> V_48 , V_286 -> V_356 ) ;
V_259 -> V_318 |= F_138 ( V_357 ) ;
V_22 = F_125 ( V_14 , V_335 ,
F_153 ( V_286 ) - V_354 , V_333 ) ;
if ( F_113 ( F_126 ( V_14 , V_22 ) ) ) {
if ( F_134 () )
F_14 ( V_12 , V_308 , V_7 , L_36 ) ;
return - V_77 ;
}
F_169 ( V_259 , V_22 ) ;
return 0 ;
}
static int F_170 ( struct V_11 * V_12 ,
struct V_209 * V_286 , struct V_258 * V_259 )
{
const enum V_332 V_333 = V_334 ;
const int V_336 = F_148 ( V_286 ) -> V_336 ;
struct V_6 * V_7 = V_12 -> V_7 ;
struct V_13 * V_14 = V_7 -> V_14 . V_15 ;
struct V_255 * V_256 ;
struct V_209 * * V_335 ;
int V_5 , V_65 , V_19 , V_349 ;
void * V_354 ;
T_8 * V_358 ;
T_6 V_22 ;
T_1 V_346 ;
void * V_359 ;
V_349 = F_157 ( V_12 -> V_48 +
sizeof( struct V_255 ) * ( 1 + V_336 ) ) ;
V_359 = F_140 ( V_349 ) ;
if ( F_113 ( ! V_359 ) ) {
F_171 ( V_7 , L_37 ,
V_349 ) ;
return - V_135 ;
}
V_19 = F_128 ( V_12 , V_286 , V_259 ,
V_359 + V_355 ) ;
if ( F_113 ( V_19 < 0 ) ) {
if ( F_134 () )
F_14 ( V_12 , V_308 , V_7 , L_35 ,
V_19 ) ;
goto V_360;
}
V_256 = (struct V_255 * ) ( V_359 + V_12 -> V_48 ) ;
F_172 ( & V_256 [ 0 ] , F_173 ( V_286 ) ) ;
V_256 [ 0 ] . V_92 = V_99 ;
V_256 [ 0 ] . V_353 = 0 ;
V_22 = F_125 ( V_14 , V_286 -> V_261 ,
F_173 ( V_286 ) , V_333 ) ;
if ( F_113 ( F_126 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_27 ) ;
V_19 = - V_77 ;
goto V_361;
}
F_174 ( & V_256 [ 0 ] , V_22 ) ;
V_358 = & F_148 ( V_286 ) -> V_362 [ 0 ] ;
V_346 = V_358 -> V_96 ;
for ( V_5 = 1 ; V_5 <= V_336 ; V_5 ++ , V_358 ++ ) {
F_34 ( ! F_175 ( V_358 ) ) ;
V_22 = F_176 ( V_14 , V_358 , 0 ,
V_346 , V_333 ) ;
if ( F_113 ( F_126 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_27 ) ;
V_19 = - V_77 ;
goto V_363;
}
F_172 ( & V_256 [ V_5 ] , V_346 ) ;
V_256 [ V_5 ] . V_92 = V_99 ;
V_256 [ V_5 ] . V_353 = 0 ;
F_174 ( & V_256 [ V_5 ] , V_22 ) ;
V_346 = V_358 -> V_96 ;
}
F_177 ( & V_256 [ V_5 - 1 ] , V_346 ) ;
F_178 ( V_259 , V_12 -> V_48 , V_286 -> V_356 ) ;
V_354 = ( void * ) V_256 - V_12 -> V_48 ;
V_335 = (struct V_209 * * ) V_354 ;
* V_335 = V_286 ;
V_22 = F_125 ( V_14 , V_354 , V_12 -> V_48 +
sizeof( struct V_255 ) * ( 1 + V_336 ) ,
V_333 ) ;
if ( F_113 ( F_126 ( V_14 , V_22 ) ) ) {
F_10 ( V_14 , L_27 ) ;
V_19 = - V_77 ;
goto V_364;
}
V_259 -> V_92 = V_99 ;
V_259 -> V_318 |= F_138 ( V_357 ) ;
F_169 ( V_259 , V_22 ) ;
return 0 ;
V_364:
V_363:
for ( V_65 = 0 ; V_65 < V_5 ; V_65 ++ )
F_151 ( V_14 , F_149 ( & V_256 [ V_65 ] ) ,
F_150 ( & V_256 [ V_65 ] ) , V_333 ) ;
V_361:
V_360:
F_152 ( V_359 ) ;
return V_19 ;
}
static inline int F_179 ( struct V_11 * V_12 ,
struct V_59 * V_365 ,
int V_366 ,
struct V_258 * V_259 )
{
struct V_171 * V_367 ;
int V_19 , V_5 ;
V_367 = V_12 -> V_188 [ V_366 ] ;
if ( V_259 -> V_92 == V_99 )
V_259 -> V_318 |= F_138 ( F_97 ( V_12 -> V_189 [ V_366 ] ) ) ;
F_180 ( V_12 -> V_7 , V_367 , V_259 ) ;
for ( V_5 = 0 ; V_5 < V_368 ; V_5 ++ ) {
V_19 = F_181 ( V_367 , V_259 ) ;
if ( V_19 != - V_369 )
break;
}
if ( F_113 ( V_19 < 0 ) ) {
V_365 -> V_58 ++ ;
V_365 -> V_370 ++ ;
return V_19 ;
}
V_365 -> V_371 ++ ;
V_365 -> V_372 += F_160 ( V_259 ) ;
return 0 ;
}
static int F_182 ( struct V_209 * V_286 , struct V_6 * V_7 )
{
const int V_373 = F_183 ( V_286 ) ;
bool V_374 = F_184 ( V_286 ) ;
struct V_59 * V_365 ;
struct V_16 * V_17 ;
struct V_11 * V_12 ;
struct V_258 V_259 ;
int V_353 = 0 ;
int V_19 = 0 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_365 = & V_17 -> V_57 ;
F_185 ( & V_259 ) ;
if ( ! V_374 ) {
if ( F_186 ( V_286 , V_12 -> V_48 ) )
goto V_375;
F_34 ( F_184 ( V_286 ) ) ;
}
if ( V_374 &&
F_143 ( F_148 ( V_286 ) -> V_336 < V_350 ) ) {
V_19 = F_170 ( V_12 , V_286 , & V_259 ) ;
V_17 -> V_376 ++ ;
} else {
if ( F_113 ( V_374 ) && F_187 ( V_286 ) )
goto V_375;
V_19 = F_167 ( V_12 , V_286 , & V_259 , & V_353 ) ;
}
if ( F_113 ( V_19 < 0 ) )
goto V_377;
if ( F_143 ( F_179 ( V_12 , V_365 , V_373 , & V_259 ) == 0 ) )
return V_378 ;
F_147 ( V_12 , & V_259 ) ;
V_377:
V_375:
V_365 -> V_58 ++ ;
F_188 ( V_286 ) ;
return V_378 ;
}
static void F_189 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_258 * V_259 ,
T_4 V_121 )
{
if ( F_134 () )
F_14 ( V_12 , V_379 , V_7 , L_38 ,
F_190 ( V_259 -> V_380 ) & V_381 ) ;
V_17 -> V_57 . V_382 ++ ;
if ( F_190 ( V_259 -> V_380 ) & V_383 )
V_17 -> V_382 . V_384 ++ ;
if ( F_190 ( V_259 -> V_380 ) & V_385 )
V_17 -> V_382 . V_386 ++ ;
if ( F_190 ( V_259 -> V_380 ) & V_387 )
V_17 -> V_382 . V_388 ++ ;
if ( F_190 ( V_259 -> V_380 ) & V_389 )
V_17 -> V_382 . V_390 ++ ;
F_119 ( V_7 , V_259 ) ;
}
static void F_191 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_258 * V_259 ,
T_4 V_121 )
{
struct V_209 * V_286 ;
if ( F_134 () )
F_192 ( V_12 , V_379 , V_7 , L_39 ,
F_190 ( V_259 -> V_380 ) & V_391 ) ;
V_17 -> V_57 . V_58 ++ ;
V_286 = F_147 ( V_12 , V_259 ) ;
F_188 ( V_286 ) ;
}
static int F_193 ( struct V_392 * V_393 , int V_394 )
{
struct V_395 * V_396 =
F_68 ( V_393 , struct V_395 , V_393 ) ;
int V_397 = F_194 ( V_396 -> V_398 , V_394 ) ;
if ( V_397 < V_394 ) {
F_195 ( V_393 ) ;
F_196 ( V_396 -> V_398 , V_399 ) ;
} else if ( V_396 -> V_400 ) {
F_196 ( V_396 -> V_398 , V_399 ) ;
}
return V_397 ;
}
static void F_197 ( struct V_6 * V_7 ,
const struct V_11 * V_12 ,
struct V_16 * V_17 ,
const struct V_258 * V_259 ,
T_4 V_121 )
{
struct V_209 * V_286 ;
if ( F_113 ( F_190 ( V_259 -> V_380 ) & V_391 ) ) {
if ( F_134 () )
F_192 ( V_12 , V_379 , V_7 , L_39 ,
F_190 ( V_259 -> V_380 ) &
V_391 ) ;
V_17 -> V_57 . V_58 ++ ;
}
V_17 -> V_401 ++ ;
V_286 = F_147 ( V_12 , V_259 ) ;
F_198 ( V_286 ) ;
}
static inline int F_199 ( struct V_16 * V_17 ,
struct V_140 * V_141 )
{
if ( F_113 ( F_200 () || ! F_201 () ) ) {
F_202 ( V_141 , V_399 ) ;
V_17 -> V_396 . V_398 = V_141 ;
F_203 ( & V_17 -> V_396 . V_393 ) ;
V_17 -> V_402 ++ ;
return 1 ;
}
return 0 ;
}
static enum V_403 F_204 ( struct V_140 * V_141 ,
struct V_171 * V_112 ,
const struct V_404 * V_405 )
{
struct V_111 * V_111 = F_68 ( V_112 , struct V_111 , V_173 ) ;
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_91 * V_91 ;
struct V_11 * V_12 ;
V_7 = V_111 -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_91 = F_33 ( V_405 -> V_259 . V_92 ) ;
if ( ! V_91 )
return V_406 ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_199 ( V_17 , V_141 ) )
return V_407 ;
if ( F_146 ( V_12 ) )
F_119 ( V_7 , & V_405 -> V_259 ) ;
else
F_189 ( V_7 , V_12 , V_17 , & V_405 -> V_259 , V_112 -> V_121 ) ;
return V_406 ;
}
static enum V_403 F_205 ( struct V_140 * V_141 ,
struct V_171 * V_112 ,
const struct V_404 * V_405 )
{
struct V_59 * V_365 ;
struct V_16 * V_17 ;
const struct V_258 * V_259 = & V_405 -> V_259 ;
T_6 V_22 = F_120 ( V_259 ) ;
enum V_408 V_409 ;
struct V_6 * V_7 ;
T_4 V_410 = V_259 -> V_380 ;
struct V_91 * V_91 ;
struct V_11 * V_12 ;
unsigned int V_411 ;
struct V_209 * V_286 ;
int * V_326 ;
V_410 = F_190 ( V_259 -> V_380 ) ;
V_409 = F_121 ( V_259 ) ;
V_7 = ( (struct V_111 * ) V_112 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_91 = F_33 ( V_405 -> V_259 . V_92 ) ;
if ( ! V_91 )
return V_406 ;
F_206 ( V_7 , V_112 , & V_405 -> V_259 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_365 = & V_17 -> V_57 ;
if ( F_113 ( F_199 ( V_17 , V_141 ) ) )
return V_407 ;
if ( F_113 ( F_146 ( V_12 ) ) ) {
F_119 ( V_7 , & V_405 -> V_259 ) ;
return V_406 ;
}
if ( F_113 ( V_410 & V_381 ) != 0 ) {
if ( F_134 () )
F_192 ( V_12 , V_379 , V_7 , L_39 ,
V_410 & V_381 ) ;
V_365 -> V_382 ++ ;
F_119 ( V_7 , V_259 ) ;
return V_406 ;
}
V_91 = F_33 ( V_259 -> V_92 ) ;
if ( ! V_91 )
return V_406 ;
F_124 ( V_91 -> V_14 , V_22 , V_91 -> V_96 , V_263 ) ;
F_207 ( F_122 ( V_22 ) + F_123 ( V_259 ) ) ;
V_409 = F_121 ( V_259 ) ;
F_34 ( ( V_409 != V_412 ) && ( V_409 != V_262 ) ) ;
V_326 = F_19 ( V_91 -> V_327 ) ;
( * V_326 ) -- ;
if ( F_143 ( V_409 == V_412 ) )
V_286 = F_154 ( V_12 , V_259 ) ;
else
V_286 = F_161 ( V_12 , V_259 ) ;
if ( ! V_286 )
return V_406 ;
V_286 -> V_291 = F_208 ( V_286 , V_7 ) ;
V_411 = V_286 -> V_356 ;
if ( F_113 ( F_209 ( V_286 ) == V_413 ) )
return V_406 ;
V_365 -> V_414 ++ ;
V_365 -> V_415 += V_411 ;
return V_406 ;
}
static enum V_403 F_210 ( struct V_140 * V_141 ,
struct V_171 * V_112 ,
const struct V_404 * V_405 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_111 * ) V_112 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_199 ( V_17 , V_141 ) )
return V_407 ;
F_191 ( V_7 , V_12 , V_17 , & V_405 -> V_259 , V_112 -> V_121 ) ;
return V_406 ;
}
static enum V_403 F_211 ( struct V_140 * V_141 ,
struct V_171 * V_112 ,
const struct V_404 * V_405 )
{
struct V_16 * V_17 ;
struct V_6 * V_7 ;
struct V_11 * V_12 ;
V_7 = ( (struct V_111 * ) V_112 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
F_212 ( V_7 , V_112 , & V_405 -> V_259 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
if ( F_199 ( V_17 , V_141 ) )
return V_407 ;
F_197 ( V_7 , V_12 , V_17 , & V_405 -> V_259 , V_112 -> V_121 ) ;
return V_406 ;
}
static void V_187 ( struct V_140 * V_141 ,
struct V_171 * V_112 ,
const union V_264 * V_265 )
{
const struct V_258 * V_259 = & V_265 -> V_266 . V_259 ;
struct V_16 * V_17 ;
const struct V_11 * V_12 ;
struct V_6 * V_7 ;
struct V_209 * V_286 ;
V_7 = ( (struct V_111 * ) V_112 ) -> V_7 ;
V_12 = F_3 ( V_7 ) ;
V_17 = F_19 ( V_12 -> V_17 ) ;
V_17 -> V_57 . V_416 ++ ;
V_17 -> V_57 . V_370 ++ ;
F_127 ( V_17 , V_265 ) ;
V_286 = F_147 ( V_12 , V_259 ) ;
F_213 ( V_286 ) ;
}
static void F_214 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_396 . V_400 = 0 ;
F_215 ( & V_17 -> V_396 . V_393 ) ;
}
}
static void F_216 ( struct V_11 * V_12 )
{
struct V_16 * V_17 ;
int V_5 ;
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
V_17 -> V_396 . V_400 = 1 ;
F_217 ( & V_17 -> V_396 . V_393 ) ;
}
}
static int F_218 ( struct V_6 * V_7 )
{
struct V_50 * V_21 ;
struct V_11 * V_12 ;
int V_19 , V_5 ;
V_12 = F_3 ( V_7 ) ;
V_21 = V_12 -> V_21 ;
F_214 ( V_12 ) ;
V_7 -> V_54 = V_21 -> V_417 ( V_7 , V_12 -> V_21 ) ;
if ( ! V_7 -> V_54 ) {
F_14 ( V_12 , V_418 , V_7 , L_40 ) ;
V_19 = - V_75 ;
goto V_419;
}
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_53 ) ; V_5 ++ ) {
V_19 = F_219 ( V_21 -> V_53 [ V_5 ] ) ;
if ( V_19 )
goto V_420;
}
V_19 = V_12 -> V_21 -> V_24 ( V_21 ) ;
if ( V_19 < 0 ) {
F_14 ( V_12 , V_418 , V_7 , L_41 , V_19 ) ;
goto V_420;
}
F_220 ( V_7 ) ;
return 0 ;
V_420:
for ( V_5 = 0 ; V_5 < F_15 ( V_21 -> V_53 ) ; V_5 ++ )
F_16 ( V_21 -> V_53 [ V_5 ] ) ;
V_419:
F_216 ( V_12 ) ;
return V_19 ;
}
static int F_221 ( struct V_6 * V_7 )
{
struct V_11 * V_12 ;
int V_19 ;
V_19 = F_11 ( V_7 ) ;
V_12 = F_3 ( V_7 ) ;
F_216 ( V_12 ) ;
return V_19 ;
}
static int F_222 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_142 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_142 ) ;
F_223 ( V_7 , & V_17 -> V_396 . V_393 ,
F_193 , V_421 ) ;
}
return 0 ;
}
static void F_224 ( struct V_6 * V_7 )
{
struct V_11 * V_12 = F_3 ( V_7 ) ;
struct V_16 * V_17 ;
int V_142 ;
F_4 (cpu) {
V_17 = F_5 ( V_12 -> V_17 , V_142 ) ;
F_225 ( & V_17 -> V_396 . V_393 ) ;
}
}
static inline void F_226 ( const struct V_91 * V_103 ,
struct V_106 * V_107 )
{
T_6 V_22 = F_227 ( V_107 ) ;
F_124 ( V_103 -> V_14 , V_22 , V_103 -> V_96 , V_263 ) ;
F_152 ( F_122 ( V_22 ) ) ;
}
static struct V_91 * F_228 ( struct V_13 * V_14 )
{
struct V_91 * V_91 ;
V_91 = F_52 ( V_14 , sizeof( * V_91 ) , V_126 ) ;
if ( ! V_91 )
return F_25 ( - V_135 ) ;
V_91 -> V_92 = V_99 ;
V_91 -> V_327 = F_229 ( V_14 , * V_91 -> V_327 ) ;
V_91 -> V_97 = V_331 ;
V_91 -> V_101 = F_144 ;
V_91 -> V_108 = F_226 ;
return V_91 ;
}
static int F_230 ( struct V_11 * V_12 )
{
struct V_151 V_152 ;
T_4 V_153 ;
int V_19 ;
V_19 = F_71 ( & V_12 -> V_216 . V_154 ) ;
if ( V_19 < 0 ) {
if ( F_72 ( V_12 ) )
F_40 ( L_42 , V_19 ) ;
goto V_155;
}
memset ( & V_152 , 0 , sizeof( V_152 ) ) ;
V_152 . V_157 = F_73 ( V_159 ) ;
V_152 . V_145 . V_160 = V_161 ;
V_153 = V_422 ;
F_74 ( & V_152 . V_145 . V_166 , V_153 , 1 ) ;
V_152 . V_157 |= F_73 ( V_167 ) ;
V_152 . V_145 . V_168 = V_161 ;
V_19 = F_75 ( & V_12 -> V_216 , V_169 ,
& V_152 ) ;
if ( V_19 < 0 ) {
if ( F_72 ( V_12 ) )
F_40 ( L_43 ,
V_19 , V_12 -> V_216 . V_154 ) ;
F_76 ( V_12 -> V_216 . V_154 ) ;
goto V_155;
}
if ( F_72 ( V_12 ) )
F_77 ( L_44 ,
V_12 -> V_216 . V_154 , V_12 -> V_21 -> V_22 ) ;
V_12 -> V_215 = true ;
V_155:
return V_19 ;
}
static inline T_3 F_231 ( struct V_227 * V_423 )
{
T_3 V_424 ;
V_424 = ( T_3 ) ( V_423 -> V_233 + V_425 +
V_426 + V_427 ) ;
return V_238 ? F_232 ( V_424 ,
V_238 ) :
V_424 ;
}
static int F_233 ( struct V_66 * V_67 )
{
struct V_91 * V_110 [ V_109 ] = { NULL } ;
struct V_16 * V_17 ;
struct V_6 * V_7 = NULL ;
struct V_111 * V_111 , * V_224 ;
struct V_11 * V_12 = NULL ;
struct V_127 V_128 ;
struct V_50 * V_21 ;
int V_19 = 0 , V_5 , V_138 ;
struct V_13 * V_14 ;
V_14 = & V_67 -> V_14 ;
V_7 = F_234 ( sizeof( * V_12 ) , V_132 ) ;
if ( ! V_7 ) {
F_10 ( V_14 , L_45 ) ;
goto V_428;
}
F_235 ( V_7 , V_14 ) ;
F_236 ( V_14 , V_7 ) ;
V_12 = F_3 ( V_7 ) ;
V_12 -> V_7 = V_7 ;
V_12 -> V_429 = F_237 ( V_430 , V_431 ) ;
V_21 = F_24 ( V_67 ) ;
if ( F_238 ( V_21 ) ) {
F_10 ( V_14 , L_46 ) ;
V_19 = F_239 ( V_21 ) ;
goto V_432;
}
V_7 -> V_433 = F_91 ( F_6 () , V_434 ) ;
F_240 ( V_7 , L_47 ,
V_7 -> V_433 ) ;
V_12 -> V_228 [ V_252 ] . V_233 = V_435 ;
V_12 -> V_228 [ V_254 ] . V_233 = V_355 ;
F_241 ( V_14 , 0 , 0 , NULL , false ) ;
V_19 = F_242 ( V_14 , F_243 ( 40 ) ) ;
if ( V_19 ) {
F_10 ( V_14 , L_48 ) ;
goto V_436;
}
for ( V_5 = 0 ; V_5 < V_109 ; V_5 ++ ) {
int V_19 ;
V_110 [ V_5 ] = F_228 ( V_14 ) ;
if ( F_238 ( V_110 [ V_5 ] ) )
return F_239 ( V_110 [ V_5 ] ) ;
V_110 [ V_5 ] -> V_322 = F_1 ( V_5 , V_109 ) ;
V_110 [ V_5 ] -> V_96 = F_244 ( V_110 [ V_5 ] -> V_322 ) ;
V_110 [ V_5 ] -> V_14 = V_14 ;
V_19 = F_39 ( V_110 [ V_5 ] ) ;
if ( V_19 < 0 ) {
F_48 ( V_12 ) ;
V_12 -> V_110 [ V_5 ] = NULL ;
goto V_437;
}
V_12 -> V_110 [ V_5 ] = V_110 [ V_5 ] ;
}
F_245 ( & V_12 -> V_438 ) ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
V_19 = F_54 ( V_14 , & V_12 -> V_438 , & V_128 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_49 ) ;
goto V_439;
}
V_12 -> V_21 = V_21 ;
V_138 = F_55 () ;
if ( V_138 < 0 ) {
F_10 ( V_14 , L_50 ) ;
V_19 = V_138 ;
goto V_440;
}
V_12 -> V_138 = ( T_3 ) V_138 ;
F_61 ( V_12 -> V_138 ) ;
F_81 ( V_12 , & V_178 , V_12 -> V_21 -> V_53 [ V_254 ] ) ;
V_19 = F_70 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_51 ) ;
goto V_441;
}
V_19 = F_230 ( V_12 ) ;
if ( V_19 < 0 ) {
F_10 ( V_14 , L_52 ) ;
goto V_442;
}
F_104 (dpaa_fq, tmp, &priv->dpaa_fq_list, list) {
V_19 = F_86 ( V_111 , false ) ;
if ( V_19 < 0 )
goto V_129;
}
V_12 -> V_48 = F_231 ( & V_12 -> V_228 [ V_254 ] ) ;
V_12 -> V_340 = F_231 ( & V_12 -> V_228 [ V_252 ] ) ;
F_110 ( V_21 , V_110 , V_109 , & V_128 ,
& V_12 -> V_228 [ 0 ] , V_14 ) ;
V_12 -> V_17 = F_229 ( V_14 , * V_12 -> V_17 ) ;
if ( ! V_12 -> V_17 ) {
F_10 ( V_14 , L_53 ) ;
V_19 = - V_135 ;
goto V_443;
}
F_4 (i) {
V_17 = F_5 ( V_12 -> V_17 , V_5 ) ;
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
}
V_19 = F_222 ( V_7 ) ;
if ( V_19 < 0 )
goto V_444;
V_19 = F_2 ( V_7 , & V_9 , V_10 ) ;
if ( V_19 < 0 )
goto V_445;
F_246 ( & V_7 -> V_14 ) ;
F_247 ( V_12 , V_446 , V_7 , L_54 ,
V_7 -> V_447 ) ;
return 0 ;
V_445:
V_444:
F_224 ( V_7 ) ;
V_443:
F_103 ( V_14 , & V_12 -> V_438 ) ;
V_129:
F_248 ( & V_12 -> V_216 ) ;
F_76 ( V_12 -> V_216 . V_154 ) ;
V_442:
F_248 ( & V_12 -> V_147 . V_145 ) ;
F_76 ( V_12 -> V_147 . V_145 . V_154 ) ;
V_441:
V_440:
F_48 ( V_12 ) ;
V_437:
V_439:
V_436:
V_432:
F_236 ( V_14 , NULL ) ;
F_249 ( V_7 ) ;
V_428:
for ( V_5 = 0 ; V_5 < V_109 && V_110 [ V_5 ] ; V_5 ++ ) {
if ( F_250 ( & V_110 [ V_5 ] -> V_95 ) == 0 )
F_251 ( V_14 , V_110 [ V_5 ] ) ;
}
return V_19 ;
}
static int F_252 ( struct V_66 * V_67 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
int V_19 ;
V_14 = & V_67 -> V_14 ;
V_7 = F_28 ( V_14 ) ;
V_12 = F_3 ( V_7 ) ;
F_253 ( V_14 ) ;
F_236 ( V_14 , NULL ) ;
F_254 ( V_7 ) ;
V_19 = F_103 ( V_14 , & V_12 -> V_438 ) ;
F_248 ( & V_12 -> V_216 ) ;
F_76 ( V_12 -> V_216 . V_154 ) ;
F_248 ( & V_12 -> V_147 . V_145 ) ;
F_76 ( V_12 -> V_147 . V_145 . V_154 ) ;
F_224 ( V_7 ) ;
F_48 ( V_12 ) ;
F_249 ( V_7 ) ;
return V_19 ;
}
static int T_9 F_255 ( void )
{
int V_19 ;
F_77 ( L_55 ) ;
V_448 = F_256 () ;
V_449 = F_257 () ;
V_19 = F_258 ( & V_450 ) ;
if ( V_19 < 0 )
F_40 ( L_56 , V_19 ) ;
return V_19 ;
}
static void T_10 F_259 ( void )
{
F_260 ( & V_450 ) ;
F_59 () ;
}
