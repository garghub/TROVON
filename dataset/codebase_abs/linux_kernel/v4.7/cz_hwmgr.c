static struct V_1 * F_1 ( struct V_2 * V_3 )
{
if ( V_4 != V_3 -> V_5 )
return NULL ;
return (struct V_1 * ) V_3 ;
}
static const struct V_1 * F_2 (
const struct V_2 * V_3 )
{
if ( V_4 != V_3 -> V_5 )
return NULL ;
return (struct V_1 * ) V_3 ;
}
T_1 F_3 ( struct V_6 * V_7 ,
T_1 clock , T_1 V_8 )
{
int V_9 = 0 ;
struct V_10 * V_11 =
V_7 -> V_12 . V_13 ;
switch ( V_8 ) {
case V_14 :
case V_15 :
for ( V_9 = 0 ; V_9 < ( int ) V_11 -> V_16 ; V_9 ++ ) {
if ( clock <= V_11 -> V_17 [ V_9 ] . V_18 )
break;
}
break;
case V_19 :
case V_20 :
for ( V_9 = V_11 -> V_16 - 1 ; V_9 >= 0 ; V_9 -- ) {
if ( clock >= V_11 -> V_17 [ V_9 ] . V_18 )
break;
}
break;
default:
break;
}
return V_9 ;
}
static T_1 F_4 ( struct V_6 * V_7 ,
T_1 clock , T_1 V_8 )
{
int V_9 = 0 ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
switch ( V_8 ) {
case V_24 :
case V_25 :
for ( V_9 = 0 ; V_9 < ( int ) V_22 -> V_16 ; V_9 ++ ) {
if ( clock <= V_22 -> V_17 [ V_9 ] . V_26 )
break;
}
break;
case V_27 :
case V_28 :
for ( V_9 = V_22 -> V_16 - 1 ; V_9 >= 0 ; V_9 -- ) {
if ( clock >= V_22 -> V_17 [ V_9 ] . V_26 )
break;
}
break;
default:
break;
}
return V_9 ;
}
static T_1 F_5 ( struct V_6 * V_7 ,
T_1 clock , T_1 V_8 )
{
int V_9 = 0 ;
struct V_29 * V_11 =
V_7 -> V_12 . V_30 ;
switch ( V_8 ) {
case V_31 :
case V_32 :
for ( V_9 = 0 ; V_9 < ( int ) V_11 -> V_16 ; V_9 ++ ) {
if ( clock <= V_11 -> V_17 [ V_9 ] . V_33 )
break;
}
break;
case V_34 :
case V_35 :
for ( V_9 = V_11 -> V_16 - 1 ; V_9 >= 0 ; V_9 -- ) {
if ( clock >= V_11 -> V_17 [ V_9 ] . V_33 )
break;
}
break;
default:
break;
}
return V_9 ;
}
static T_1 F_6 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_38 == 0 ) {
F_7 ( V_7 -> V_39 , V_40 ) ;
V_36 -> V_38 = F_8 ( V_7 -> V_39 ) + 1 ;
}
return V_36 -> V_38 ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
T_1 V_9 ;
struct V_41 V_42 = { 0 } ;
int V_43 ;
V_36 -> V_44 = 256 * 25 / 100 ;
V_36 -> V_45 = 1 ;
for ( V_9 = 0 ; V_9 < V_46 ; V_9 ++ )
V_36 -> V_47 [ V_9 ] = V_48 ;
V_36 -> V_49 = 0x00000000 ;
V_36 -> V_50 = 0x00000000 ;
V_36 -> V_51 = 25000 ;
V_36 -> V_52 = 1 ;
V_36 -> V_53 = 1 ;
V_36 -> V_54 = 0 ;
V_36 -> V_55 = 0x00C00033 ;
V_36 -> V_56 = 8 ;
V_36 -> V_57 = 0 ;
V_36 -> V_58 = 1 ;
V_36 -> V_59 = 0 ;
V_36 -> V_60 = 500 ;
V_36 -> V_61 = 20000 ;
V_36 -> V_62 = 30000 ;
V_36 -> V_63 = 1 ;
V_36 -> V_64 = 0 ;
F_10 ( V_7 -> V_65 . V_66 ,
V_67 ) ;
F_11 ( V_7 -> V_65 . V_66 ,
V_68 ) ;
F_11 ( V_7 -> V_65 . V_66 ,
V_69 ) ;
F_10 ( V_7 -> V_65 . V_66 ,
V_70 ) ;
V_36 -> V_71 = 1 ;
F_11 ( V_7 -> V_65 . V_66 ,
V_72 ) ;
V_36 -> V_73 = 0 ;
V_36 -> V_74 = 0 ;
V_36 -> V_75 = 0 ;
F_11 ( V_7 -> V_65 . V_66 ,
V_76 ) ;
F_11 ( V_7 -> V_65 . V_66 ,
V_77 ) ;
F_11 ( V_7 -> V_65 . V_66 ,
V_78 ) ;
V_36 -> V_79 . V_80 = false ;
V_36 -> V_79 . V_81 = false ;
V_36 -> V_79 . V_82 = false ;
V_36 -> V_79 . V_83 = 0 ;
F_11 ( V_7 -> V_65 . V_66 ,
V_84 ) ;
F_10 ( V_7 -> V_65 . V_66 ,
V_85 ) ;
F_10 ( V_7 -> V_65 . V_66 ,
V_86 ) ;
V_42 . V_87 = sizeof( struct V_41 ) ;
V_42 . V_88 = V_89 ;
V_43 = F_12 ( V_7 -> V_90 , & V_42 ) ;
if ( ! V_43 ) {
if ( V_42 . V_91 & V_92 )
F_11 ( V_7 -> V_65 . V_66 ,
V_85 ) ;
if ( V_42 . V_91 & V_93 )
F_11 ( V_7 -> V_65 . V_66 ,
V_86 ) ;
}
return 0 ;
}
static T_1 F_13 (
struct V_6 * V_7 , T_2 V_94 )
{
return 6200 - ( V_94 * 25 ) ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_95 * V_22 )
{
struct V_36 * V_36 = (struct V_36 * ) V_7 -> V_37 ;
struct V_96 * V_42 = & V_36 -> V_42 ;
struct V_21 * V_97 =
V_7 -> V_12 . V_23 ;
if ( V_97 -> V_16 > 0 ) {
V_22 -> V_98 = V_97 -> V_17 [ V_97 -> V_16 - 1 ] . V_26 ;
V_22 -> V_99 = F_13 ( V_7 ,
( T_2 ) V_97 -> V_17 [ V_97 -> V_16 - 1 ] . V_100 ) ;
}
V_22 -> V_101 = V_42 -> V_102 [ 0 ] ;
return 0 ;
}
static int F_15 (
struct V_6 * V_7 ,
T_3 * V_103 )
{
T_1 V_104 =
sizeof( struct V_21 ) +
( 7 * sizeof( struct V_105 ) ) ;
struct V_21 * V_106 =
F_16 ( V_104 , V_107 ) ;
if ( NULL == V_106 ) {
F_17 ( V_108 L_1 ) ;
return - V_109 ;
}
V_106 -> V_16 = 8 ;
V_106 -> V_17 [ 0 ] . V_26 = V_110 ;
V_106 -> V_17 [ 0 ] . V_100 = 0 ;
V_106 -> V_17 [ 1 ] . V_26 = V_111 ;
V_106 -> V_17 [ 1 ] . V_100 = 1 ;
V_106 -> V_17 [ 2 ] . V_26 = V_112 ;
V_106 -> V_17 [ 2 ] . V_100 = 2 ;
V_106 -> V_17 [ 3 ] . V_26 = V_113 ;
V_106 -> V_17 [ 3 ] . V_100 = 3 ;
V_106 -> V_17 [ 4 ] . V_26 = V_114 ;
V_106 -> V_17 [ 4 ] . V_100 = 4 ;
V_106 -> V_17 [ 5 ] . V_26 = V_115 ;
V_106 -> V_17 [ 5 ] . V_100 = 5 ;
V_106 -> V_17 [ 6 ] . V_26 = V_116 ;
V_106 -> V_17 [ 6 ] . V_100 = 6 ;
V_106 -> V_17 [ 7 ] . V_26 = V_117 ;
V_106 -> V_17 [ 7 ] . V_100 = 7 ;
V_7 -> V_12 . V_118 = V_106 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) V_7 -> V_37 ;
T_4 * V_119 = NULL ;
T_1 V_9 ;
int V_43 = 0 ;
T_5 V_120 , V_121 ;
T_2 V_87 ;
V_119 = ( T_4 * ) F_19 (
V_7 -> V_90 ,
F_20 ( V_122 , V_123 ) ,
& V_87 , & V_120 , & V_121 ) ;
if ( V_121 != 9 ) {
F_17 ( V_108 L_2 , V_120 , V_121 ) ;
return - V_124 ;
}
if ( V_119 == NULL ) {
F_17 ( V_108 L_3 ) ;
return - V_124 ;
}
V_36 -> V_42 . V_125 =
F_21 ( V_119 -> V_126 ) ;
V_36 -> V_42 . V_127 =
F_21 ( V_119 -> V_128 ) ;
V_36 -> V_42 . V_129 =
F_21 ( V_119 -> V_130 ) ;
V_36 -> V_42 . V_131 =
F_21 ( V_119 -> V_132 ) ;
V_36 -> V_42 . V_133 =
F_22 ( V_119 -> V_134 ) ;
V_36 -> V_42 . V_135 =
( V_119 -> V_136 == 0 ) ? 5 : V_119 -> V_136 ;
V_36 -> V_42 . V_137 =
( V_119 -> V_138 == 0 ) ? 203 : V_119 -> V_138 ;
if ( V_36 -> V_42 . V_137 <=
V_36 -> V_42 . V_135 ) {
F_17 ( V_108 L_4 ) ;
return - V_124 ;
}
V_36 -> V_42 . V_139 =
V_36 -> V_53 &&
( F_21 ( V_119 -> V_132 ) >> 3 & 0x1 ) ;
for ( V_9 = 0 ; V_9 < V_140 ; V_9 ++ ) {
if ( V_9 < V_141 ) {
V_36 -> V_42 . V_102 [ V_9 ] =
F_21 ( V_119 -> V_142 [ V_9 ] ) ;
}
V_36 -> V_42 . V_143 [ V_9 ] =
F_21 ( V_119 -> V_144 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_145 ; V_9 ++ ) {
V_36 -> V_42 . V_146 [ V_9 ] =
F_21 ( V_119 -> V_147 [ V_9 ] . V_148 ) ;
}
for ( V_9 = 0 ; V_9 < V_140 ; V_9 ++ ) {
V_36 -> V_42 . V_149 [ V_9 ] =
F_22 ( V_119 -> V_150 [ V_9 ] ) ;
}
if ( ! V_36 -> V_42 . V_139 ) {
for ( V_9 = 1 ; V_9 < V_140 ; V_9 ++ ) {
if ( V_9 < V_141 ) {
V_36 -> V_42 . V_102 [ V_9 ] =
V_36 -> V_42 . V_102 [ 0 ] ;
}
V_36 -> V_42 . V_143 [ V_9 ] =
V_36 -> V_42 . V_143 [ 0 ] ;
V_36 -> V_42 . V_149 [ V_9 ] =
V_36 -> V_42 . V_149 [ 0 ] ;
}
}
if ( F_21 ( V_119 -> V_151 ) &
V_152 ) {
F_11 ( V_7 -> V_65 . V_66 ,
V_153 ) ;
}
V_36 -> V_42 . V_154 = V_119 -> V_155 ;
F_14 ( V_7 ,
& V_7 -> V_12 . V_156 ) ;
F_15 ( V_7 ,
& V_119 -> V_157 [ 0 ] ) ;
return V_43 ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_158 . V_159 =
V_36 -> V_42 . V_127 ;
V_36 -> V_158 . V_160 =
( T_5 ) V_36 -> V_42 . V_133 ;
V_36 -> V_158 . V_161 = 0 ;
V_36 -> V_158 . V_162 = 0 ;
V_36 -> V_158 . V_163 = 1 ;
V_36 -> V_158 . V_164 = 0 ;
V_36 -> V_158 . V_165 = 0 ;
V_36 -> V_158 . V_166 = 0 ;
V_36 -> V_158 . V_167 = 0 ;
V_36 -> V_158 . V_168 = 0 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
return 0 ;
}
static int F_25 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_172 * V_173 ;
int V_174 ;
T_1 V_9 ;
void * V_22 = NULL ;
T_6 V_175 ;
struct V_21 * V_176 =
V_7 -> V_12 . V_23 ;
struct V_21 * V_177 =
V_7 -> V_12 . V_178 ;
struct V_179 * V_180 =
V_7 -> V_12 . V_181 ;
struct V_29 * V_182 =
V_7 -> V_12 . V_30 ;
struct V_10 * V_183 =
V_7 -> V_12 . V_13 ;
if ( ! V_7 -> V_184 )
return 0 ;
V_174 = F_26 ( V_7 -> V_39 , & V_22 ) ;
F_27 ((0 == ret && NULL != table),
L_5 , return -EINVAL;) ;
V_173 = (struct V_172 * ) V_22 ;
F_27 ((vddc_table->count <= CZ_MAX_HARDWARE_POWERLEVELS),
L_6 , return -EINVAL;) ;
F_27 ((vdd_gfx_table->count <= CZ_MAX_HARDWARE_POWERLEVELS),
L_6 , return -EINVAL;) ;
F_27 ((acp_table->count <= CZ_MAX_HARDWARE_POWERLEVELS),
L_6 , return -EINVAL;) ;
F_27 ((uvd_table->count <= CZ_MAX_HARDWARE_POWERLEVELS),
L_6 , return -EINVAL;) ;
F_27 ((vce_table->count <= CZ_MAX_HARDWARE_POWERLEVELS),
L_6 , return -EINVAL;) ;
for ( V_9 = 0 ; V_9 < V_46 ; V_9 ++ ) {
V_173 -> V_185 . V_186 [ V_9 ] . V_187 =
( V_9 < V_176 -> V_16 ) ? ( T_5 ) V_176 -> V_17 [ V_9 ] . V_100 : 0 ;
V_173 -> V_185 . V_186 [ V_9 ] . V_188 =
( V_9 < V_176 -> V_16 ) ? V_176 -> V_17 [ V_9 ] . V_26 : 0 ;
F_28 ( V_7 ,
V_173 -> V_185 . V_186 [ V_9 ] . V_188 ,
& V_175 ) ;
V_173 -> V_185 . V_186 [ V_9 ] . V_189 =
( T_5 ) V_175 . V_190 ;
V_173 -> V_185 . V_186 [ V_9 ] . V_191 =
( V_9 < V_177 -> V_16 ) ? ( T_5 ) V_177 -> V_17 [ V_9 ] . V_100 : 0 ;
V_173 -> V_192 . V_186 [ V_9 ] . V_191 =
( V_9 < V_180 -> V_16 ) ? ( T_5 ) V_180 -> V_17 [ V_9 ] . V_100 : 0 ;
V_173 -> V_192 . V_186 [ V_9 ] . V_188 =
( V_9 < V_180 -> V_16 ) ? V_180 -> V_17 [ V_9 ] . V_193 : 0 ;
F_28 ( V_7 ,
V_173 -> V_192 . V_186 [ V_9 ] . V_188 ,
& V_175 ) ;
V_173 -> V_192 . V_186 [ V_9 ] . V_189 =
( T_5 ) V_175 . V_190 ;
V_173 -> V_194 . V_186 [ V_9 ] . V_191 =
( V_9 < V_182 -> V_16 ) ? ( T_5 ) V_182 -> V_17 [ V_9 ] . V_100 : 0 ;
V_173 -> V_194 . V_186 [ V_9 ] . V_188 =
( V_9 < V_182 -> V_16 ) ? V_182 -> V_17 [ V_9 ] . V_33 : 0 ;
F_28 ( V_7 ,
V_173 -> V_194 . V_186 [ V_9 ] . V_188 ,
& V_175 ) ;
V_173 -> V_194 . V_186 [ V_9 ] . V_189 =
( T_5 ) V_175 . V_190 ;
V_173 -> V_195 . V_186 [ V_9 ] . V_191 =
( V_9 < V_182 -> V_16 ) ? ( T_5 ) V_182 -> V_17 [ V_9 ] . V_100 : 0 ;
V_173 -> V_195 . V_186 [ V_9 ] . V_188 =
( V_9 < V_182 -> V_16 ) ? V_182 -> V_17 [ V_9 ] . V_196 : 0 ;
F_28 ( V_7 ,
V_173 -> V_195 . V_186 [ V_9 ] . V_188 ,
& V_175 ) ;
V_173 -> V_195 . V_186 [ V_9 ] . V_189 =
( T_5 ) V_175 . V_190 ;
V_173 -> V_197 . V_186 [ V_9 ] . V_191 =
( V_9 < V_183 -> V_16 ) ? ( T_5 ) V_183 -> V_17 [ V_9 ] . V_100 : 0 ;
V_173 -> V_197 . V_186 [ V_9 ] . V_188 =
( V_9 < V_183 -> V_16 ) ? V_183 -> V_17 [ V_9 ] . V_18 : 0 ;
F_28 ( V_7 ,
V_173 -> V_197 . V_186 [ V_9 ] . V_188 ,
& V_175 ) ;
V_173 -> V_197 . V_186 [ V_9 ] . V_189 =
( T_5 ) V_175 . V_190 ;
}
V_174 = F_29 ( V_7 -> V_39 ) ;
return V_174 ;
}
static int F_30 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 , V_198 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_124 ;
V_36 -> V_199 . V_200 = V_22 -> V_17 [ 0 ] . V_26 ;
V_36 -> V_199 . V_201 = V_22 -> V_17 [ 0 ] . V_26 ;
V_198 = F_6 ( V_7 ) - 1 ;
if ( V_198 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_198 ] . V_26 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_36 -> V_199 . V_202 = clock ;
V_36 -> V_199 . V_203 = clock ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_29 * V_22 =
V_7 -> V_12 . V_30 ;
unsigned long clock = 0 , V_198 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_124 ;
V_36 -> V_204 . V_200 = 0 ;
V_36 -> V_204 . V_201 = 0 ;
F_7 ( V_7 -> V_39 , V_205 ) ;
V_198 = F_8 ( V_7 -> V_39 ) ;
if ( V_198 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_198 ] . V_33 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_33 ;
V_36 -> V_204 . V_202 = clock ;
V_36 -> V_204 . V_203 = clock ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_10 * V_22 =
V_7 -> V_12 . V_13 ;
unsigned long clock = 0 , V_198 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_124 ;
V_36 -> V_206 . V_200 = 0 ;
V_36 -> V_206 . V_201 = 0 ;
F_7 ( V_7 -> V_39 , V_207 ) ;
V_198 = F_8 ( V_7 -> V_39 ) ;
if ( V_198 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_198 ] . V_18 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_18 ;
V_36 -> V_206 . V_202 = clock ;
V_36 -> V_206 . V_203 = clock ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_179 * V_22 =
V_7 -> V_12 . V_181 ;
unsigned long clock = 0 , V_198 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_124 ;
V_36 -> V_208 . V_200 = 0 ;
V_36 -> V_208 . V_201 = 0 ;
F_7 ( V_7 -> V_39 , V_209 ) ;
V_198 = F_8 ( V_7 -> V_39 ) ;
if ( V_198 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_198 ] . V_193 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_193 ;
V_36 -> V_208 . V_202 = clock ;
V_36 -> V_208 . V_203 = clock ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_210 = false ;
V_36 -> V_211 = false ;
V_36 -> V_212 = false ;
V_36 -> V_213 = false ;
V_36 -> V_214 = true ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_215 = 0 ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 ;
unsigned long V_198 ;
unsigned long V_216 ;
unsigned long V_217 ;
V_36 -> V_199 . V_200 = V_22 -> V_17 [ 0 ] . V_26 ;
V_198 = F_6 ( V_7 ) - 1 ;
if ( V_198 < V_22 -> V_16 )
V_36 -> V_199 . V_202 = V_22 -> V_17 [ V_198 ] . V_26 ;
else
V_36 -> V_199 . V_202 = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
clock = V_7 -> V_218 . V_219 ;
;
if ( clock == 0 )
F_17 ( V_220 L_7 ) ;
if ( V_36 -> V_199 . V_201 != clock ) {
V_36 -> V_199 . V_201 = clock ;
F_37 ( V_7 -> V_39 ,
V_25 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_201 ,
V_25 ) ) ;
}
clock = V_36 -> V_199 . V_200 ;
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_221 ) ) {
V_217 = 75 ;
V_216 = ( V_7 -> V_12 . V_156 . V_101 *
V_217 ) / 100 ;
if ( clock < V_216 )
clock = V_216 ;
} else {
if ( clock < V_7 -> V_222 . V_98 )
clock = V_7 -> V_222 . V_98 ;
}
if ( V_36 -> V_199 . V_200 != clock ) {
V_36 -> V_199 . V_200 = clock ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_200 ,
V_24 ) ) ;
}
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_221 ) &&
V_36 -> V_199 . V_202 != clock ) {
V_36 -> V_199 . V_202 = clock ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_202 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_69 ) ) {
T_1 V_223 = V_7 -> V_218 . V_224 ;
if ( V_223 == 0 )
V_223 = V_225 ;
F_40 ( L_8 , V_223 ) ;
F_37 ( V_7 -> V_39 ,
V_226 ,
V_223 ) ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
struct V_36 * V_36 =
(struct V_36 * ) ( V_7 -> V_37 ) ;
F_37 ( V_7 -> V_39 ,
V_227 ,
V_36 -> V_199 . V_202 ) ;
return 0 ;
}
static int F_42 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
return 0 ;
}
static int F_43 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
int V_174 = 0 ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
unsigned long V_228 = 0 ;
if ( ! V_36 -> V_229 ) {
F_40 ( L_9 ) ;
V_228 |= V_230 ;
V_174 = F_37 (
V_7 -> V_39 ,
V_231 ,
V_228 ) ;
if ( V_174 == 0 )
V_36 -> V_229 = true ;
}
return V_174 ;
}
static int F_44 ( struct V_6 * V_7 , bool V_232 , bool V_233 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_234 -> V_229 ) {
if ( V_232 ) {
F_40 ( L_10 ) ;
return F_37 ( V_7 -> V_39 ,
V_235 ,
( V_233 ? 1 : 0 ) ) ;
} else {
F_40 ( L_11 ) ;
return F_37 ( V_7 -> V_39 ,
V_236 ,
( V_233 ? 1 : 0 ) ) ;
}
}
return 0 ;
}
static int F_45 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
bool V_237 ;
bool V_238 ;
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
const struct V_239 * V_240 = (struct V_239 * ) V_169 ;
const struct V_1 * V_241 = F_2 ( V_240 -> V_241 ) ;
if ( V_234 -> V_42 . V_139 ) {
V_237 = V_234 -> V_79 . V_82 ? true : false ;
V_238 = V_234 -> V_79 . V_82 ? false : true ;
if ( V_241 -> V_242 == V_243 )
F_44 ( V_7 , false , V_237 ) ;
else if ( V_241 -> V_242 == V_244 )
F_44 ( V_7 , true , V_237 ) ;
else
F_44 ( V_7 , V_238 , V_237 ) ;
}
return 0 ;
}
static int F_46 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_234 -> V_245 = false ;
V_234 -> V_246 = false ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_234 -> V_229 = false ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_234 -> V_79 . V_247 = false ;
V_234 -> V_79 . V_83 = 0 ;
V_234 -> V_79 . V_80 = false ;
V_234 -> V_79 . V_81 = false ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
F_50 ( V_7 -> V_90 , V_248 ,
V_249 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 , void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
int V_250 = 0xff ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
unsigned long V_228 = 0 ;
V_36 -> V_251 |= V_252 ;
V_228 |= V_253 ;
V_250 = F_37 ( V_7 -> V_39 ,
V_231 ,
V_228 ) ;
return V_250 ;
}
static int F_52 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_199 . V_200 = V_36 -> V_42 . V_127 ;
V_36 -> V_199 . V_202 = V_36 -> V_42 . V_127 ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_200 ,
V_24 ) ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_202 ,
V_27 ) ) ;
return 0 ;
}
int F_53 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_254 = 0xff ;
return 0 ;
}
static bool F_54 ( struct V_6 * V_7 ,
unsigned long V_255 )
{
int V_43 ;
unsigned long V_256 ;
V_43 = F_37 ( V_7 -> V_39 , V_257 , 0 ) ;
if ( V_43 == 0 ) {
V_256 = F_8 ( V_7 -> V_39 ) ;
if ( V_256 & V_255 )
return true ;
}
return V_43 ;
}
static int F_55 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
if ( F_54 ( V_7 , V_258 ) )
return V_259 ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 , void * V_169 ,
void * V_170 , void * V_171 , int V_43 )
{
return 0 ;
}
static int F_57 ( struct V_6 * V_7 ,
void * V_169 , void * V_170 ,
void * V_171 , int V_43 )
{
if ( ! F_54 ( V_7 ,
V_258 ) )
return V_259 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
struct V_260 * V_261 ,
const struct V_260 * V_262 )
{
struct V_1 * V_263 =
F_1 ( & V_261 -> V_264 ) ;
const struct V_1 * V_265 =
F_2 ( & V_262 -> V_264 ) ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_266 V_267 = { 0 , 0 , 0 , 0 } ;
bool V_268 ;
T_1 V_269 = 0 ;
struct V_270 V_119 = { 0 } ;
V_263 -> V_271 = V_7 -> V_272 . V_271 ;
V_263 -> V_18 = V_7 -> V_272 . V_18 ;
V_263 -> V_273 = true ;
V_36 -> V_274 = ( V_7 -> V_275 . V_33 != 0 || V_7 -> V_275 . V_196 != 0 ||
V_7 -> V_272 . V_271 != 0 || V_7 -> V_272 . V_18 != 0 ) ;
V_36 -> V_276 = ( V_277 == V_261 -> V_278 . V_279 ) ;
V_267 . V_280 = V_7 -> V_218 . V_281 != 0 ?
V_7 -> V_218 . V_281 :
V_36 -> V_42 . V_102 [ 1 ] ;
F_59 ( V_7 -> V_90 , & V_119 ) ;
V_269 = V_119 . V_282 ;
if ( F_38 ( V_7 -> V_65 . V_66 , V_221 ) )
V_267 . V_280 = V_7 -> V_12 . V_156 . V_101 ;
if ( V_267 . V_280 < V_7 -> V_222 . V_101 )
V_267 . V_280 = V_7 -> V_222 . V_101 ;
V_268 = ( V_267 . V_280 > V_36 -> V_42 . V_102 [ V_141 - 1 ] )
|| ( V_269 >= 3 ) ;
V_263 -> V_242 = V_265 -> V_242 ;
if ( ( V_268 == false ) && ( V_263 -> V_242 == V_243 ) )
V_263 -> V_242 = V_244 ;
else if ( ( V_268 == true ) && ( V_263 -> V_242 != V_243 ) )
V_263 -> V_242 = V_243 ;
else
V_263 -> V_242 = V_283 ;
return 0 ;
}
static int F_60 ( struct V_6 * V_7 )
{
int V_43 = 0 ;
V_43 = F_9 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_12 ) ;
return V_43 ;
}
V_43 = F_18 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_13 ) ;
return V_43 ;
}
F_23 ( V_7 ) ;
V_43 = F_61 ( V_7 , & V_284 ,
& ( V_7 -> V_285 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_14 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_286 ,
& ( V_7 -> V_287 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_15 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_288 ,
& ( V_7 -> V_289 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_16 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_290 ,
& ( V_7 -> V_291 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_17 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_292 ,
& ( V_7 -> V_293 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_18 ) ;
return V_43 ;
}
V_7 -> V_65 . V_294 = V_46 ;
V_43 = F_61 ( V_7 , & V_295 , & ( V_7 -> V_296 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_108 L_19 ) ;
return V_43 ;
}
return V_43 ;
}
static int F_62 ( struct V_6 * V_7 )
{
if ( V_7 != NULL || V_7 -> V_37 != NULL ) {
F_63 ( V_7 -> V_37 ) ;
F_63 ( V_7 ) ;
}
return 0 ;
}
int F_64 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_199 . V_200 !=
V_36 -> V_199 . V_202 )
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_202 ,
V_24 ) ) ;
return 0 ;
}
int F_65 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 , V_198 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_124 ;
V_36 -> V_199 . V_200 = V_22 -> V_17 [ 0 ] . V_26 ;
V_36 -> V_199 . V_201 = V_22 -> V_17 [ 0 ] . V_26 ;
V_198 = F_6 ( V_7 ) - 1 ;
if ( V_198 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_198 ] . V_26 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_36 -> V_199 . V_202 = clock ;
V_36 -> V_199 . V_203 = clock ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_200 ,
V_24 ) ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_202 ,
V_27 ) ) ;
return 0 ;
}
int F_66 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_199 . V_200 !=
V_36 -> V_199 . V_202 ) {
V_36 -> V_199 . V_202 =
V_36 -> V_199 . V_200 ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_199 . V_202 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_67 ( struct V_6 * V_7 ,
enum V_297 V_198 )
{
int V_174 = 0 ;
switch ( V_198 ) {
case V_298 :
V_174 = F_64 ( V_7 ) ;
if ( V_174 )
return V_174 ;
break;
case V_299 :
V_174 = F_66 ( V_7 ) ;
if ( V_174 )
return V_174 ;
break;
case V_300 :
V_174 = F_65 ( V_7 ) ;
if ( V_174 )
return V_174 ;
break;
default:
break;
}
V_7 -> V_301 = V_198 ;
return V_174 ;
}
int F_68 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_85 ) )
return F_7 ( V_7 -> V_39 ,
V_302 ) ;
return 0 ;
}
int F_69 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_85 ) ) {
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_303 ) ) {
return F_37 (
V_7 -> V_39 ,
V_304 , 1 ) ;
} else {
return F_37 (
V_7 -> V_39 ,
V_304 , 0 ) ;
}
}
return 0 ;
}
int F_70 ( struct V_6 * V_7 , bool V_305 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_29 * V_11 =
V_7 -> V_12 . V_30 ;
if ( ! V_305 ) {
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_221 ) ) {
V_36 -> V_204 . V_201 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_33 ;
F_37 ( V_7 -> V_39 ,
V_32 ,
F_5 ( V_7 ,
V_36 -> V_204 . V_201 ,
V_32 ) ) ;
F_71 ( V_7 , true ) ;
} else
F_71 ( V_7 , true ) ;
} else
F_71 ( V_7 , false ) ;
return 0 ;
}
int F_72 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_10 * V_11 =
V_7 -> V_12 . V_13 ;
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_221 ) ) {
V_36 -> V_206 . V_201 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_18 ;
F_37 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_206 . V_201 ,
V_15 ) ) ;
} else {
V_36 -> V_206 . V_201 = V_7 -> V_272 . V_18 ;
F_37 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_206 . V_201 ,
V_15 ) ) ;
}
return 0 ;
}
int F_73 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_86 ) )
return F_7 ( V_7 -> V_39 ,
V_306 ) ;
return 0 ;
}
int F_74 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_86 ) )
return F_7 ( V_7 -> V_39 ,
V_307 ) ;
return 0 ;
}
static int F_75 ( struct V_6 * V_7 , bool V_308 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
return V_36 -> V_42 . V_125 ;
}
static int F_76 ( struct V_6 * V_7 , bool V_308 )
{
struct V_260 * V_309 ;
struct V_1 * V_263 ;
if ( V_7 == NULL )
return - V_124 ;
V_309 = V_7 -> V_310 ;
if ( V_309 == NULL )
return - V_124 ;
V_263 = F_1 ( & V_309 -> V_264 ) ;
if ( V_308 )
return V_263 -> V_311 [ 0 ] . V_159 ;
else
return V_263 -> V_311 [ V_263 -> V_198 - 1 ] . V_159 ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_1 * V_263 = F_1 ( V_3 ) ;
V_263 -> V_198 = 1 ;
V_263 -> V_312 = 0 ;
V_263 -> V_313 = 0 ;
V_263 -> V_311 [ 0 ] = V_36 -> V_158 ;
return 0 ;
}
static int F_78 (
struct V_6 * V_7 ,
struct V_2 * V_3 ,
unsigned int V_314 ,
const void * V_315 )
{
struct V_1 * V_263 = F_1 ( V_3 ) ;
const T_7 * V_316 = V_315 ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
T_5 V_317 = V_316 -> V_314 ;
if ( V_317 > ( T_5 ) ( V_7 -> V_65 . V_294 - 1 ) )
V_317 = ( T_5 ) ( V_7 -> V_65 . V_294 - 1 ) ;
V_263 -> V_311 [ V_314 ] . V_159 = V_22 -> V_17 [ V_317 ] . V_26 ;
V_263 -> V_311 [ V_314 ] . V_160 = ( T_5 ) V_22 -> V_17 [ V_317 ] . V_100 ;
V_263 -> V_198 = V_314 + 1 ;
if ( F_38 ( V_7 -> V_65 . V_66 , V_69 ) ) {
V_263 -> V_311 [ V_314 ] . V_161 = 5 ;
V_263 -> V_311 [ V_314 ] . V_162 = 5 ;
}
return 0 ;
}
static int F_79 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned long V_174 = 0 ;
V_43 = F_80 ( V_7 , & V_174 ) ;
return V_43 ? 0 : V_174 ;
}
static int F_81 ( struct V_6 * V_7 ,
unsigned long V_318 , struct V_260 * V_309 )
{
int V_43 ;
struct V_1 * V_263 ;
V_309 -> V_264 . V_5 = V_4 ;
V_263 = F_1 ( & ( V_309 -> V_264 ) ) ;
V_43 = F_82 ( V_7 , V_318 , V_309 ,
F_78 ) ;
V_263 -> V_319 . V_33 = V_309 -> V_319 . V_320 ;
V_263 -> V_319 . V_196 = V_309 -> V_319 . V_321 ;
return V_43 ;
}
int F_83 ( struct V_6 * V_7 )
{
return sizeof( struct V_1 ) ;
}
static void
F_84 ( struct V_6 * V_7 , struct V_322 * V_323 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
struct V_10 * V_183 =
V_7 -> V_12 . V_13 ;
struct V_29 * V_182 =
V_7 -> V_12 . V_30 ;
T_1 V_324 = F_85 ( F_86 ( V_7 -> V_90 , V_325 , V_326 ) ,
V_327 , V_328 ) ;
T_1 V_329 = F_85 ( F_86 ( V_7 -> V_90 , V_325 , V_330 ) ,
V_331 , V_332 ) ;
T_1 V_333 = F_85 ( F_86 ( V_7 -> V_90 , V_325 , V_330 ) ,
V_331 , V_334 ) ;
T_1 V_98 , V_33 , V_196 , V_18 , V_335 , V_336 ;
T_2 V_337 , V_338 ;
int V_43 ;
if ( V_324 >= V_339 ) {
F_87 ( V_323 , L_20 , V_324 ) ;
} else {
V_98 = V_22 -> V_17 [ V_324 ] . V_26 ;
F_87 ( V_323 , L_21 , V_324 , V_98 / 100 ) ;
}
V_335 = ( F_86 ( V_7 -> V_90 , V_325 , V_340 ) &
V_341 ) >> V_342 ;
V_337 = F_13 ( V_7 , V_335 ) ;
V_335 = ( F_86 ( V_7 -> V_90 , V_325 , V_343 ) &
V_344 ) >> V_345 ;
V_338 = F_13 ( V_7 , ( V_346 ) V_335 ) ;
F_87 ( V_323 , L_22 , V_337 , V_338 ) ;
F_87 ( V_323 , L_23 , V_36 -> V_210 ? L_24 : L_25 ) ;
if ( ! V_36 -> V_210 ) {
if ( V_329 >= V_46 ) {
F_87 ( V_323 , L_26 , V_329 ) ;
} else {
V_33 = V_182 -> V_17 [ V_329 ] . V_33 ;
V_196 = V_182 -> V_17 [ V_329 ] . V_196 ;
F_87 ( V_323 , L_27 , V_329 , V_33 / 100 , V_196 / 100 ) ;
}
}
F_87 ( V_323 , L_28 , V_36 -> V_211 ? L_24 : L_25 ) ;
if ( ! V_36 -> V_211 ) {
if ( V_333 >= V_46 ) {
F_87 ( V_323 , L_29 , V_333 ) ;
} else {
V_18 = V_183 -> V_17 [ V_333 ] . V_18 ;
F_87 ( V_323 , L_30 , V_333 , V_18 / 100 ) ;
}
}
V_43 = F_7 ( V_7 -> V_39 , V_347 ) ;
if ( 0 == V_43 ) {
V_336 = F_88 ( V_7 -> V_90 , V_348 ) ;
V_336 = V_336 > 100 ? 100 : V_336 ;
} else {
V_336 = 50 ;
}
F_87 ( V_323 , L_31 , V_336 ) ;
}
static void F_89 (
const struct V_79 * V_79 )
{
F_40 ( L_32 ) ;
F_40 ( L_33 ,
V_79 -> V_80 ) ;
F_40 ( L_34 ,
V_79 -> V_81 ) ;
F_40 ( L_35 ,
V_79 -> V_82 ) ;
F_40 ( L_36 ,
V_79 -> V_83 ) ;
}
static int F_90 ( struct V_6 * V_7 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
T_1 V_349 = 0 ;
if ( V_234 -> V_79 . V_247 == true ) {
V_234 -> V_79 . V_247 = false ;
F_89 ( & V_234 -> V_79 ) ;
V_349 |= ( V_234 -> V_79 . V_83
& V_350 )
<< V_351 ;
V_349 |= ( V_234 -> V_79 . V_80 ? 0x1 : 0x0 )
<< V_352 ;
V_349 |= ( V_234 -> V_79 . V_81 ? 0x1 : 0x0 )
<< V_353 ;
F_40 ( L_37 ,
V_349 ) ;
F_37 ( V_7 -> V_39 ,
V_354 ,
V_349 ) ;
}
return 0 ;
}
static int F_91 ( struct V_6 * V_7 , T_1 V_355 ,
bool V_356 , bool V_357 , bool V_358 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_355 !=
V_234 -> V_79 . V_83
|| V_356 !=
V_234 -> V_79 . V_80
|| V_357 !=
V_234 -> V_79 . V_81
|| V_358 !=
V_234 -> V_79 . V_82 ) {
V_234 -> V_79 . V_247 = true ;
V_234 -> V_79 . V_83 =
V_355 ;
V_234 -> V_79 . V_80 =
V_356 ;
V_234 -> V_79 . V_81 =
V_357 ;
V_234 -> V_79 . V_82 =
V_358 ;
}
return 0 ;
}
static int F_92 ( struct V_6 * V_7 ,
struct V_359 * V_119 )
{
T_1 V_9 ;
const struct V_21 * V_22 =
V_7 -> V_12 . V_118 ;
const struct V_95 * V_360 =
& V_7 -> V_12 . V_156 ;
V_119 -> V_361 = V_360 -> V_98 ;
V_119 -> V_362 = V_360 -> V_101 ;
for ( V_9 = V_22 -> V_16 - 1 ; V_9 > 0 ; V_9 -- ) {
if ( V_360 -> V_99 >= V_22 -> V_17 [ V_9 ] . V_100 ) {
V_119 -> V_198 = V_22 -> V_17 [ V_9 ] . V_26 ;
return 0 ;
}
}
return - V_124 ;
}
static int F_93 ( struct V_6 * V_7 ,
enum V_363 type , T_1 V_364 )
{
if ( V_7 -> V_301 != V_365 )
return - V_124 ;
switch ( type ) {
case V_366 :
F_37 ( V_7 -> V_39 ,
V_24 ,
V_364 ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
V_364 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_94 ( struct V_6 * V_7 ,
enum V_363 type , char * V_367 )
{
struct V_21 * V_368 =
V_7 -> V_12 . V_23 ;
int V_9 , V_369 , V_87 = 0 ;
switch ( type ) {
case V_366 :
V_369 = F_85 ( F_86 ( V_7 -> V_90 ,
V_325 ,
V_326 ) ,
V_327 ,
V_328 ) ;
for ( V_9 = 0 ; V_9 < V_368 -> V_16 ; V_9 ++ )
V_87 += sprintf ( V_367 + V_87 , L_38 ,
V_9 , V_368 -> V_17 [ V_9 ] . V_26 / 100 ,
( V_9 == V_369 ) ? L_39 : L_40 ) ;
break;
default:
break;
}
return V_87 ;
}
static int F_95 ( struct V_6 * V_7 , const struct V_2 * V_370 ,
T_8 V_371 , T_1 V_314 ,
T_9 * V_198 )
{
const struct V_1 * V_309 ;
struct V_36 * V_349 ;
T_1 V_372 ;
T_1 V_9 ;
if ( V_198 == NULL || V_7 == NULL || V_370 == NULL )
return - V_124 ;
V_349 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_309 = F_2 ( V_370 ) ;
V_372 = V_314 > V_309 -> V_198 - 1 ? V_309 -> V_198 - 1 : V_314 ;
V_198 -> V_373 = V_309 -> V_311 [ V_372 ] . V_159 ;
if ( V_371 == V_374 ) {
for ( V_9 = 1 ; V_9 < V_309 -> V_198 ; V_9 ++ ) {
if ( V_309 -> V_311 [ V_9 ] . V_159 > V_349 -> V_62 ) {
V_198 -> V_373 = V_309 -> V_311 [ V_9 ] . V_159 ;
break;
}
}
}
if ( V_372 == 0 )
V_198 -> V_375 = V_349 -> V_42 . V_102 [ V_141 - 1 ] ;
else
V_198 -> V_375 = V_349 -> V_42 . V_102 [ 0 ] ;
V_198 -> V_99 = ( F_13 ( V_7 , V_309 -> V_311 [ V_372 ] . V_160 ) + 2 ) / 4 ;
V_198 -> V_376 = 0 ;
V_198 -> V_377 = 0 ;
return 0 ;
}
static int F_96 ( struct V_6 * V_7 ,
const struct V_2 * V_370 , struct V_378 * V_315 )
{
const struct V_1 * V_309 = F_2 ( V_370 ) ;
V_315 -> V_379 = V_309 -> V_311 [ 0 ] . V_159 / ( 1 << ( V_309 -> V_311 [ 0 ] . V_162 ) ) ;
V_315 -> V_380 = V_309 -> V_311 [ V_309 -> V_198 - 1 ] . V_159 / ( 1 << ( V_309 -> V_311 [ V_309 -> V_198 - 1 ] . V_162 ) ) ;
return 0 ;
}
static int F_97 ( struct V_6 * V_7 , enum V_381 type ,
struct V_382 * V_267 )
{
struct V_36 * V_349 = (struct V_36 * ) ( V_7 -> V_37 ) ;
int V_9 ;
struct V_21 * V_22 ;
V_267 -> V_16 = F_6 ( V_7 ) ;
switch ( type ) {
case V_383 :
for ( V_9 = 0 ; V_9 < V_267 -> V_16 ; V_9 ++ )
V_267 -> clock [ V_9 ] = V_349 -> V_42 . V_146 [ V_9 ] ;
break;
case V_384 :
V_22 = V_7 -> V_12 . V_23 ;
for ( V_9 = 0 ; V_9 < V_267 -> V_16 ; V_9 ++ )
V_267 -> clock [ V_9 ] = V_22 -> V_17 [ V_9 ] . V_26 ;
break;
case V_385 :
V_267 -> V_16 = V_141 ;
for ( V_9 = 0 ; V_9 < V_267 -> V_16 ; V_9 ++ )
V_267 -> clock [ V_9 ] = V_349 -> V_42 . V_102 [ V_267 -> V_16 - 1 - V_9 ] ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_98 ( struct V_6 * V_7 , struct V_359 * V_267 )
{
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long V_198 ;
const struct V_95 * V_360 =
& V_7 -> V_12 . V_156 ;
if ( ( NULL == V_22 ) || ( V_22 -> V_16 <= 0 ) || ( V_267 == NULL ) )
return - V_124 ;
V_198 = F_6 ( V_7 ) - 1 ;
if ( V_198 < V_22 -> V_16 )
V_267 -> V_361 = V_22 -> V_17 [ V_198 ] . V_26 ;
else
V_267 -> V_361 = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_267 -> V_362 = V_360 -> V_101 ;
return 0 ;
}
int F_99 ( struct V_6 * V_7 )
{
struct V_36 * V_36 ;
int V_174 = 0 ;
V_36 = F_16 ( sizeof( struct V_36 ) , V_107 ) ;
if ( V_36 == NULL )
return - V_109 ;
V_7 -> V_37 = V_36 ;
V_7 -> V_386 = & V_387 ;
V_7 -> V_388 = & V_389 ;
return V_174 ;
}
