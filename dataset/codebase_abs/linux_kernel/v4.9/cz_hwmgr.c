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
F_10 ( V_7 -> V_65 . V_66 ,
V_69 ) ;
V_36 -> V_70 = 1 ;
F_11 ( V_7 -> V_65 . V_66 ,
V_71 ) ;
V_36 -> V_72 = 0 ;
V_36 -> V_73 = 0 ;
V_36 -> V_74 = 0 ;
F_11 ( V_7 -> V_65 . V_66 ,
V_75 ) ;
F_11 ( V_7 -> V_65 . V_66 ,
V_76 ) ;
F_11 ( V_7 -> V_65 . V_66 ,
V_77 ) ;
V_36 -> V_78 . V_79 = false ;
V_36 -> V_78 . V_80 = false ;
V_36 -> V_78 . V_81 = false ;
V_36 -> V_78 . V_82 = 0 ;
F_11 ( V_7 -> V_65 . V_66 ,
V_83 ) ;
F_10 ( V_7 -> V_65 . V_66 ,
V_84 ) ;
F_10 ( V_7 -> V_65 . V_66 ,
V_85 ) ;
V_42 . V_86 = sizeof( struct V_41 ) ;
V_42 . V_87 = V_88 ;
V_43 = F_12 ( V_7 -> V_89 , & V_42 ) ;
if ( ! V_43 ) {
if ( V_42 . V_90 & V_91 )
F_11 ( V_7 -> V_65 . V_66 ,
V_84 ) ;
if ( V_42 . V_90 & V_92 )
F_11 ( V_7 -> V_65 . V_66 ,
V_85 ) ;
}
return 0 ;
}
static T_1 F_13 (
struct V_6 * V_7 , T_2 V_93 )
{
return 6200 - ( V_93 * 25 ) ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_94 * V_22 )
{
struct V_36 * V_36 = (struct V_36 * ) V_7 -> V_37 ;
struct V_95 * V_42 = & V_36 -> V_42 ;
struct V_21 * V_96 =
V_7 -> V_12 . V_23 ;
if ( V_96 -> V_16 > 0 ) {
V_22 -> V_97 = V_96 -> V_17 [ V_96 -> V_16 - 1 ] . V_26 ;
V_22 -> V_98 = F_13 ( V_7 ,
( T_2 ) V_96 -> V_17 [ V_96 -> V_16 - 1 ] . V_99 ) ;
}
V_22 -> V_100 = V_42 -> V_101 [ 0 ] ;
return 0 ;
}
static int F_15 (
struct V_6 * V_7 ,
T_3 * V_102 )
{
T_1 V_103 =
sizeof( struct V_21 ) +
( 7 * sizeof( struct V_104 ) ) ;
struct V_21 * V_105 =
F_16 ( V_103 , V_106 ) ;
if ( NULL == V_105 ) {
F_17 ( V_107 L_1 ) ;
return - V_108 ;
}
V_105 -> V_16 = 8 ;
V_105 -> V_17 [ 0 ] . V_26 = V_109 ;
V_105 -> V_17 [ 0 ] . V_99 = 0 ;
V_105 -> V_17 [ 1 ] . V_26 = V_110 ;
V_105 -> V_17 [ 1 ] . V_99 = 1 ;
V_105 -> V_17 [ 2 ] . V_26 = V_111 ;
V_105 -> V_17 [ 2 ] . V_99 = 2 ;
V_105 -> V_17 [ 3 ] . V_26 = V_112 ;
V_105 -> V_17 [ 3 ] . V_99 = 3 ;
V_105 -> V_17 [ 4 ] . V_26 = V_113 ;
V_105 -> V_17 [ 4 ] . V_99 = 4 ;
V_105 -> V_17 [ 5 ] . V_26 = V_114 ;
V_105 -> V_17 [ 5 ] . V_99 = 5 ;
V_105 -> V_17 [ 6 ] . V_26 = V_115 ;
V_105 -> V_17 [ 6 ] . V_99 = 6 ;
V_105 -> V_17 [ 7 ] . V_26 = V_116 ;
V_105 -> V_17 [ 7 ] . V_99 = 7 ;
V_7 -> V_12 . V_117 = V_105 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) V_7 -> V_37 ;
T_4 * V_118 = NULL ;
T_1 V_9 ;
int V_43 = 0 ;
T_5 V_119 , V_120 ;
T_2 V_86 ;
V_118 = ( T_4 * ) F_19 (
V_7 -> V_89 ,
F_20 ( V_121 , V_122 ) ,
& V_86 , & V_119 , & V_120 ) ;
if ( V_120 != 9 ) {
F_17 ( V_107 L_2 , V_119 , V_120 ) ;
return - V_123 ;
}
if ( V_118 == NULL ) {
F_17 ( V_107 L_3 ) ;
return - V_123 ;
}
V_36 -> V_42 . V_124 =
F_21 ( V_118 -> V_125 ) ;
V_36 -> V_42 . V_126 =
F_21 ( V_118 -> V_127 ) ;
V_36 -> V_42 . V_128 =
F_21 ( V_118 -> V_129 ) ;
V_36 -> V_42 . V_130 =
F_21 ( V_118 -> V_131 ) ;
V_36 -> V_42 . V_132 =
F_22 ( V_118 -> V_133 ) ;
V_36 -> V_42 . V_134 =
( V_118 -> V_135 == 0 ) ? 5 : V_118 -> V_135 ;
V_36 -> V_42 . V_136 =
( V_118 -> V_137 == 0 ) ? 203 : V_118 -> V_137 ;
if ( V_36 -> V_42 . V_136 <=
V_36 -> V_42 . V_134 ) {
F_17 ( V_107 L_4 ) ;
return - V_123 ;
}
V_36 -> V_42 . V_138 =
V_36 -> V_53 &&
( F_21 ( V_118 -> V_131 ) >> 3 & 0x1 ) ;
for ( V_9 = 0 ; V_9 < V_139 ; V_9 ++ ) {
if ( V_9 < V_140 ) {
V_36 -> V_42 . V_101 [ V_9 ] =
F_21 ( V_118 -> V_141 [ V_9 ] ) ;
}
V_36 -> V_42 . V_142 [ V_9 ] =
F_21 ( V_118 -> V_143 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_144 ; V_9 ++ ) {
V_36 -> V_42 . V_145 [ V_9 ] =
F_21 ( V_118 -> V_146 [ V_9 ] . V_147 ) ;
}
for ( V_9 = 0 ; V_9 < V_139 ; V_9 ++ ) {
V_36 -> V_42 . V_148 [ V_9 ] =
F_22 ( V_118 -> V_149 [ V_9 ] ) ;
}
if ( ! V_36 -> V_42 . V_138 ) {
for ( V_9 = 1 ; V_9 < V_139 ; V_9 ++ ) {
if ( V_9 < V_140 ) {
V_36 -> V_42 . V_101 [ V_9 ] =
V_36 -> V_42 . V_101 [ 0 ] ;
}
V_36 -> V_42 . V_142 [ V_9 ] =
V_36 -> V_42 . V_142 [ 0 ] ;
V_36 -> V_42 . V_148 [ V_9 ] =
V_36 -> V_42 . V_148 [ 0 ] ;
}
}
if ( F_21 ( V_118 -> V_150 ) &
V_151 ) {
F_11 ( V_7 -> V_65 . V_66 ,
V_152 ) ;
}
V_36 -> V_42 . V_153 = V_118 -> V_154 ;
F_14 ( V_7 ,
& V_7 -> V_12 . V_155 ) ;
F_15 ( V_7 ,
& V_118 -> V_156 [ 0 ] ) ;
return V_43 ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_157 . V_158 =
V_36 -> V_42 . V_126 ;
V_36 -> V_157 . V_159 =
( T_5 ) V_36 -> V_42 . V_132 ;
V_36 -> V_157 . V_160 = 0 ;
V_36 -> V_157 . V_161 = 0 ;
V_36 -> V_157 . V_162 = 1 ;
V_36 -> V_157 . V_163 = 0 ;
V_36 -> V_157 . V_164 = 0 ;
V_36 -> V_157 . V_165 = 0 ;
V_36 -> V_157 . V_166 = 0 ;
V_36 -> V_157 . V_167 = 0 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
return 0 ;
}
static int F_25 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_171 * V_172 ;
int V_173 ;
T_1 V_9 ;
void * V_22 = NULL ;
T_6 V_174 ;
struct V_21 * V_175 =
V_7 -> V_12 . V_23 ;
struct V_21 * V_176 =
V_7 -> V_12 . V_177 ;
struct V_178 * V_179 =
V_7 -> V_12 . V_180 ;
struct V_29 * V_181 =
V_7 -> V_12 . V_30 ;
struct V_10 * V_182 =
V_7 -> V_12 . V_13 ;
if ( ! V_7 -> V_183 )
return 0 ;
V_173 = F_26 ( V_7 -> V_39 , & V_22 ) ;
F_27 ((0 == ret && NULL != table),
L_5 , return -EINVAL;) ;
V_172 = (struct V_171 * ) V_22 ;
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
V_172 -> V_184 . V_185 [ V_9 ] . V_186 =
( V_9 < V_175 -> V_16 ) ? ( T_5 ) V_175 -> V_17 [ V_9 ] . V_99 : 0 ;
V_172 -> V_184 . V_185 [ V_9 ] . V_187 =
( V_9 < V_175 -> V_16 ) ? V_175 -> V_17 [ V_9 ] . V_26 : 0 ;
F_28 ( V_7 ,
V_172 -> V_184 . V_185 [ V_9 ] . V_187 ,
& V_174 ) ;
V_172 -> V_184 . V_185 [ V_9 ] . V_188 =
( T_5 ) V_174 . V_189 ;
V_172 -> V_184 . V_185 [ V_9 ] . V_190 =
( V_9 < V_176 -> V_16 ) ? ( T_5 ) V_176 -> V_17 [ V_9 ] . V_99 : 0 ;
V_172 -> V_191 . V_185 [ V_9 ] . V_190 =
( V_9 < V_179 -> V_16 ) ? ( T_5 ) V_179 -> V_17 [ V_9 ] . V_99 : 0 ;
V_172 -> V_191 . V_185 [ V_9 ] . V_187 =
( V_9 < V_179 -> V_16 ) ? V_179 -> V_17 [ V_9 ] . V_192 : 0 ;
F_28 ( V_7 ,
V_172 -> V_191 . V_185 [ V_9 ] . V_187 ,
& V_174 ) ;
V_172 -> V_191 . V_185 [ V_9 ] . V_188 =
( T_5 ) V_174 . V_189 ;
V_172 -> V_193 . V_185 [ V_9 ] . V_190 =
( V_9 < V_181 -> V_16 ) ? ( T_5 ) V_181 -> V_17 [ V_9 ] . V_99 : 0 ;
V_172 -> V_193 . V_185 [ V_9 ] . V_187 =
( V_9 < V_181 -> V_16 ) ? V_181 -> V_17 [ V_9 ] . V_33 : 0 ;
F_28 ( V_7 ,
V_172 -> V_193 . V_185 [ V_9 ] . V_187 ,
& V_174 ) ;
V_172 -> V_193 . V_185 [ V_9 ] . V_188 =
( T_5 ) V_174 . V_189 ;
V_172 -> V_194 . V_185 [ V_9 ] . V_190 =
( V_9 < V_181 -> V_16 ) ? ( T_5 ) V_181 -> V_17 [ V_9 ] . V_99 : 0 ;
V_172 -> V_194 . V_185 [ V_9 ] . V_187 =
( V_9 < V_181 -> V_16 ) ? V_181 -> V_17 [ V_9 ] . V_195 : 0 ;
F_28 ( V_7 ,
V_172 -> V_194 . V_185 [ V_9 ] . V_187 ,
& V_174 ) ;
V_172 -> V_194 . V_185 [ V_9 ] . V_188 =
( T_5 ) V_174 . V_189 ;
V_172 -> V_196 . V_185 [ V_9 ] . V_190 =
( V_9 < V_182 -> V_16 ) ? ( T_5 ) V_182 -> V_17 [ V_9 ] . V_99 : 0 ;
V_172 -> V_196 . V_185 [ V_9 ] . V_187 =
( V_9 < V_182 -> V_16 ) ? V_182 -> V_17 [ V_9 ] . V_18 : 0 ;
F_28 ( V_7 ,
V_172 -> V_196 . V_185 [ V_9 ] . V_187 ,
& V_174 ) ;
V_172 -> V_196 . V_185 [ V_9 ] . V_188 =
( T_5 ) V_174 . V_189 ;
}
V_173 = F_29 ( V_7 -> V_39 ) ;
return V_173 ;
}
static int F_30 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 , V_197 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_123 ;
V_36 -> V_198 . V_199 = V_22 -> V_17 [ 0 ] . V_26 ;
V_36 -> V_198 . V_200 = V_22 -> V_17 [ 0 ] . V_26 ;
V_197 = F_6 ( V_7 ) - 1 ;
if ( V_197 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_197 ] . V_26 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_36 -> V_198 . V_201 = clock ;
V_36 -> V_198 . V_202 = clock ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_29 * V_22 =
V_7 -> V_12 . V_30 ;
unsigned long clock = 0 , V_197 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_123 ;
V_36 -> V_203 . V_199 = 0 ;
V_36 -> V_203 . V_200 = 0 ;
F_7 ( V_7 -> V_39 , V_204 ) ;
V_197 = F_8 ( V_7 -> V_39 ) ;
if ( V_197 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_197 ] . V_33 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_33 ;
V_36 -> V_203 . V_201 = clock ;
V_36 -> V_203 . V_202 = clock ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_10 * V_22 =
V_7 -> V_12 . V_13 ;
unsigned long clock = 0 , V_197 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_123 ;
V_36 -> V_205 . V_199 = 0 ;
V_36 -> V_205 . V_200 = 0 ;
F_7 ( V_7 -> V_39 , V_206 ) ;
V_197 = F_8 ( V_7 -> V_39 ) ;
if ( V_197 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_197 ] . V_18 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_18 ;
V_36 -> V_205 . V_201 = clock ;
V_36 -> V_205 . V_202 = clock ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_178 * V_22 =
V_7 -> V_12 . V_180 ;
unsigned long clock = 0 , V_197 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_123 ;
V_36 -> V_207 . V_199 = 0 ;
V_36 -> V_207 . V_200 = 0 ;
F_7 ( V_7 -> V_39 , V_208 ) ;
V_197 = F_8 ( V_7 -> V_39 ) ;
if ( V_197 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_197 ] . V_192 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_192 ;
V_36 -> V_207 . V_201 = clock ;
V_36 -> V_207 . V_202 = clock ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_209 = false ;
V_36 -> V_210 = false ;
V_36 -> V_211 = false ;
V_36 -> V_212 = false ;
V_36 -> V_213 = true ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_214 = 0 ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 ;
unsigned long V_197 ;
unsigned long V_215 ;
unsigned long V_216 ;
V_36 -> V_198 . V_199 = V_22 -> V_17 [ 0 ] . V_26 ;
V_197 = F_6 ( V_7 ) - 1 ;
if ( V_197 < V_22 -> V_16 )
V_36 -> V_198 . V_201 = V_22 -> V_17 [ V_197 ] . V_26 ;
else
V_36 -> V_198 . V_201 = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
clock = V_7 -> V_217 . V_218 ;
if ( clock == 0 )
F_17 ( V_219 L_7 ) ;
if ( V_36 -> V_198 . V_200 != clock ) {
V_36 -> V_198 . V_200 = clock ;
F_37 ( V_7 -> V_39 ,
V_25 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_200 ,
V_25 ) ) ;
}
clock = V_36 -> V_198 . V_199 ;
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_220 ) ) {
V_216 = 75 ;
V_215 = ( V_7 -> V_12 . V_155 . V_100 *
V_216 ) / 100 ;
if ( clock < V_215 )
clock = V_215 ;
} else {
if ( clock < V_7 -> V_221 . V_97 )
clock = V_7 -> V_221 . V_97 ;
}
if ( V_36 -> V_198 . V_199 != clock ) {
V_36 -> V_198 . V_199 = clock ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_199 ,
V_24 ) ) ;
}
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_220 ) &&
V_36 -> V_198 . V_201 != clock ) {
V_36 -> V_198 . V_201 = clock ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_201 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 ,
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_222 ) ) {
T_1 V_223 = V_7 -> V_217 . V_224 ;
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
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
struct V_36 * V_36 =
(struct V_36 * ) ( V_7 -> V_37 ) ;
F_37 ( V_7 -> V_39 ,
V_227 ,
V_36 -> V_198 . V_201 ) ;
return 0 ;
}
static int F_42 ( struct V_6 * V_7 ,
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
return 0 ;
}
static int F_43 ( struct V_6 * V_7 ,
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
int V_173 = 0 ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
unsigned long V_228 = 0 ;
if ( ! V_36 -> V_229 ) {
F_40 ( L_9 ) ;
V_228 |= V_230 ;
V_173 = F_37 (
V_7 -> V_39 ,
V_231 ,
V_228 ) ;
if ( V_173 == 0 )
V_36 -> V_229 = true ;
}
return V_173 ;
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
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
bool V_237 ;
bool V_238 ;
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
const struct V_239 * V_240 = (struct V_239 * ) V_168 ;
const struct V_1 * V_241 = F_2 ( V_240 -> V_241 ) ;
if ( V_234 -> V_42 . V_138 ) {
V_237 = V_234 -> V_78 . V_81 ? true : false ;
V_238 = V_234 -> V_78 . V_81 ? false : true ;
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
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_234 -> V_245 = false ;
V_234 -> V_246 = false ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_234 -> V_229 = false ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_234 -> V_78 . V_247 = false ;
V_234 -> V_78 . V_82 = 0 ;
V_234 -> V_78 . V_79 = false ;
V_234 -> V_78 . V_80 = false ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
F_50 ( V_7 -> V_89 , V_248 ,
V_249 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 , void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
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
static int F_52 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_198 . V_199 = V_36 -> V_42 . V_126 ;
V_36 -> V_198 . V_201 = V_36 -> V_42 . V_126 ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_199 ,
V_24 ) ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_201 ,
V_27 ) ) ;
return 0 ;
}
int F_53 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
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
static int F_55 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
if ( F_54 ( V_7 , V_258 ) )
return V_259 ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 , void * V_168 ,
void * V_169 , void * V_170 , int V_43 )
{
return 0 ;
}
static int F_57 ( struct V_6 * V_7 ,
void * V_168 , void * V_169 ,
void * V_170 , int V_43 )
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
struct V_270 V_118 = { 0 } ;
V_263 -> V_271 = V_7 -> V_272 . V_271 ;
V_263 -> V_18 = V_7 -> V_272 . V_18 ;
V_263 -> V_273 = true ;
V_36 -> V_274 = ( V_7 -> V_275 . V_33 != 0 || V_7 -> V_275 . V_195 != 0 ||
V_7 -> V_272 . V_271 != 0 || V_7 -> V_272 . V_18 != 0 ) ;
V_36 -> V_276 = ( V_277 == V_261 -> V_278 . V_279 ) ;
V_267 . V_280 = V_7 -> V_217 . V_281 != 0 ?
V_7 -> V_217 . V_281 :
V_36 -> V_42 . V_101 [ 1 ] ;
F_59 ( V_7 -> V_89 , & V_118 ) ;
V_269 = V_118 . V_282 ;
if ( F_38 ( V_7 -> V_65 . V_66 , V_220 ) )
V_267 . V_280 = V_7 -> V_12 . V_155 . V_100 ;
if ( V_267 . V_280 < V_7 -> V_221 . V_100 )
V_267 . V_280 = V_7 -> V_221 . V_100 ;
V_268 = ( V_267 . V_280 > V_36 -> V_42 . V_101 [ V_140 - 1 ] )
|| ( V_269 >= 3 ) ;
V_263 -> V_242 = V_265 -> V_242 ;
if ( ! V_268 && ( V_263 -> V_242 == V_243 ) )
V_263 -> V_242 = V_244 ;
else if ( V_268 && ( V_263 -> V_242 != V_243 ) )
V_263 -> V_242 = V_243 ;
else
V_263 -> V_242 = V_283 ;
return 0 ;
}
static int F_60 ( struct V_6 * V_7 )
{
int V_43 = 0 ;
struct V_36 * V_284 ;
V_284 = F_16 ( sizeof( struct V_36 ) , V_106 ) ;
if ( V_284 == NULL )
return - V_108 ;
V_7 -> V_37 = V_284 ;
V_43 = F_9 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_12 ) ;
return V_43 ;
}
V_43 = F_18 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_13 ) ;
return V_43 ;
}
F_23 ( V_7 ) ;
V_43 = F_61 ( V_7 , & V_285 ,
& ( V_7 -> V_286 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_14 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_287 ,
& ( V_7 -> V_288 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_15 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_289 ,
& ( V_7 -> V_290 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_16 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_291 ,
& ( V_7 -> V_292 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_17 ) ;
return V_43 ;
}
V_43 = F_61 ( V_7 , & V_293 ,
& ( V_7 -> V_294 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_18 ) ;
return V_43 ;
}
V_7 -> V_65 . V_295 = V_46 ;
V_43 = F_61 ( V_7 , & V_296 , & ( V_7 -> V_297 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_107 L_19 ) ;
return V_43 ;
}
return V_43 ;
}
static int F_62 ( struct V_6 * V_7 )
{
if ( V_7 != NULL && V_7 -> V_37 != NULL ) {
F_63 ( V_7 -> V_37 ) ;
F_63 ( V_7 ) ;
}
return 0 ;
}
int F_64 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_198 . V_199 !=
V_36 -> V_198 . V_201 )
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_201 ,
V_24 ) ) ;
return 0 ;
}
int F_65 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 , V_197 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_123 ;
V_36 -> V_198 . V_199 = V_22 -> V_17 [ 0 ] . V_26 ;
V_36 -> V_198 . V_200 = V_22 -> V_17 [ 0 ] . V_26 ;
V_197 = F_6 ( V_7 ) - 1 ;
if ( V_197 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_197 ] . V_26 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_36 -> V_198 . V_201 = clock ;
V_36 -> V_198 . V_202 = clock ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_199 ,
V_24 ) ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_201 ,
V_27 ) ) ;
return 0 ;
}
int F_66 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_198 . V_199 !=
V_36 -> V_198 . V_201 ) {
V_36 -> V_198 . V_201 =
V_36 -> V_198 . V_199 ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_198 . V_201 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_67 ( struct V_6 * V_7 ,
enum V_298 V_197 )
{
int V_173 = 0 ;
switch ( V_197 ) {
case V_299 :
V_173 = F_64 ( V_7 ) ;
if ( V_173 )
return V_173 ;
break;
case V_300 :
V_173 = F_66 ( V_7 ) ;
if ( V_173 )
return V_173 ;
break;
case V_301 :
V_173 = F_65 ( V_7 ) ;
if ( V_173 )
return V_173 ;
break;
default:
break;
}
V_7 -> V_302 = V_197 ;
return V_173 ;
}
int F_68 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_84 ) )
return F_7 ( V_7 -> V_39 ,
V_303 ) ;
return 0 ;
}
int F_69 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_84 ) ) {
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_304 ) ) {
return F_37 (
V_7 -> V_39 ,
V_305 , 1 ) ;
} else {
return F_37 (
V_7 -> V_39 ,
V_305 , 0 ) ;
}
}
return 0 ;
}
int F_70 ( struct V_6 * V_7 , bool V_306 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_29 * V_11 =
V_7 -> V_12 . V_30 ;
if ( ! V_306 ) {
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_220 ) ) {
V_36 -> V_203 . V_200 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_33 ;
F_37 ( V_7 -> V_39 ,
V_32 ,
F_5 ( V_7 ,
V_36 -> V_203 . V_200 ,
V_32 ) ) ;
F_71 ( V_7 , true ) ;
} else {
F_71 ( V_7 , true ) ;
}
} else {
F_71 ( V_7 , false ) ;
}
return 0 ;
}
int F_72 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_10 * V_11 =
V_7 -> V_12 . V_13 ;
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_220 ) ) {
V_36 -> V_205 . V_200 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_18 ;
F_37 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_205 . V_200 ,
V_15 ) ) ;
} else {
V_36 -> V_205 . V_200 = V_7 -> V_272 . V_18 ;
F_37 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_205 . V_200 ,
V_15 ) ) ;
}
return 0 ;
}
int F_73 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_85 ) )
return F_7 ( V_7 -> V_39 ,
V_307 ) ;
return 0 ;
}
int F_74 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_85 ) )
return F_7 ( V_7 -> V_39 ,
V_308 ) ;
return 0 ;
}
static int F_75 ( struct V_6 * V_7 , bool V_309 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
return V_36 -> V_42 . V_124 ;
}
static int F_76 ( struct V_6 * V_7 , bool V_309 )
{
struct V_260 * V_310 ;
struct V_1 * V_263 ;
if ( V_7 == NULL )
return - V_123 ;
V_310 = V_7 -> V_311 ;
if ( V_310 == NULL )
return - V_123 ;
V_263 = F_1 ( & V_310 -> V_264 ) ;
if ( V_309 )
return V_263 -> V_312 [ 0 ] . V_158 ;
else
return V_263 -> V_312 [ V_263 -> V_197 - 1 ] . V_158 ;
}
static int F_77 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_1 * V_263 = F_1 ( V_3 ) ;
V_263 -> V_197 = 1 ;
V_263 -> V_313 = 0 ;
V_263 -> V_314 = 0 ;
V_263 -> V_312 [ 0 ] = V_36 -> V_157 ;
return 0 ;
}
static int F_78 (
struct V_6 * V_7 ,
struct V_2 * V_3 ,
unsigned int V_315 ,
const void * V_316 )
{
struct V_1 * V_263 = F_1 ( V_3 ) ;
const T_7 * V_317 = V_316 ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
T_5 V_318 = V_317 -> V_315 ;
if ( V_318 > ( T_5 ) ( V_7 -> V_65 . V_295 - 1 ) )
V_318 = ( T_5 ) ( V_7 -> V_65 . V_295 - 1 ) ;
V_263 -> V_312 [ V_315 ] . V_158 = V_22 -> V_17 [ V_318 ] . V_26 ;
V_263 -> V_312 [ V_315 ] . V_159 = ( T_5 ) V_22 -> V_17 [ V_318 ] . V_99 ;
V_263 -> V_197 = V_315 + 1 ;
if ( F_38 ( V_7 -> V_65 . V_66 , V_222 ) ) {
V_263 -> V_312 [ V_315 ] . V_160 = 5 ;
V_263 -> V_312 [ V_315 ] . V_161 = 5 ;
}
return 0 ;
}
static int F_79 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned long V_173 = 0 ;
V_43 = F_80 ( V_7 , & V_173 ) ;
return V_43 ? 0 : V_173 ;
}
static int F_81 ( struct V_6 * V_7 ,
unsigned long V_319 , struct V_260 * V_310 )
{
int V_43 ;
struct V_1 * V_263 ;
V_310 -> V_264 . V_5 = V_4 ;
V_263 = F_1 ( & ( V_310 -> V_264 ) ) ;
V_43 = F_82 ( V_7 , V_319 , V_310 ,
F_78 ) ;
V_263 -> V_320 . V_33 = V_310 -> V_320 . V_321 ;
V_263 -> V_320 . V_195 = V_310 -> V_320 . V_322 ;
return V_43 ;
}
int F_83 ( struct V_6 * V_7 )
{
return sizeof( struct V_1 ) ;
}
static void F_84 (
const struct V_78 * V_78 )
{
F_40 ( L_20 ) ;
F_40 ( L_21 ,
V_78 -> V_79 ) ;
F_40 ( L_22 ,
V_78 -> V_80 ) ;
F_40 ( L_23 ,
V_78 -> V_81 ) ;
F_40 ( L_24 ,
V_78 -> V_82 ) ;
}
static int F_85 ( struct V_6 * V_7 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
T_1 V_284 = 0 ;
if ( V_234 -> V_78 . V_247 ) {
V_234 -> V_78 . V_247 = false ;
F_84 ( & V_234 -> V_78 ) ;
V_284 |= ( V_234 -> V_78 . V_82
& V_323 )
<< V_324 ;
V_284 |= ( V_234 -> V_78 . V_79 ? 0x1 : 0x0 )
<< V_325 ;
V_284 |= ( V_234 -> V_78 . V_80 ? 0x1 : 0x0 )
<< V_326 ;
F_40 ( L_25 ,
V_284 ) ;
F_37 ( V_7 -> V_39 ,
V_327 ,
V_284 ) ;
}
return 0 ;
}
static int F_86 ( struct V_6 * V_7 , T_1 V_328 ,
bool V_329 , bool V_330 , bool V_331 )
{
struct V_36 * V_234 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_328 !=
V_234 -> V_78 . V_82 ||
V_329 != V_234 -> V_78 . V_79 ||
V_330 != V_234 -> V_78 . V_80 ||
V_331 != V_234 -> V_78 . V_81 ) {
V_234 -> V_78 . V_247 = true ;
V_234 -> V_78 . V_82 =
V_328 ;
V_234 -> V_78 . V_79 =
V_329 ;
V_234 -> V_78 . V_80 =
V_330 ;
V_234 -> V_78 . V_81 =
V_331 ;
}
return 0 ;
}
static int F_87 ( struct V_6 * V_7 ,
struct V_332 * V_118 )
{
T_1 V_9 ;
const struct V_21 * V_22 =
V_7 -> V_12 . V_117 ;
const struct V_94 * V_333 =
& V_7 -> V_12 . V_155 ;
V_118 -> V_334 = V_333 -> V_97 ;
V_118 -> V_335 = V_333 -> V_100 ;
for ( V_9 = V_22 -> V_16 - 1 ; V_9 > 0 ; V_9 -- ) {
if ( V_333 -> V_98 >= V_22 -> V_17 [ V_9 ] . V_99 ) {
V_118 -> V_197 = V_22 -> V_17 [ V_9 ] . V_26 ;
return 0 ;
}
}
return - V_123 ;
}
static int F_88 ( struct V_6 * V_7 ,
enum V_336 type , T_1 V_337 )
{
if ( V_7 -> V_302 != V_338 )
return - V_123 ;
switch ( type ) {
case V_339 :
F_37 ( V_7 -> V_39 ,
V_24 ,
V_337 ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
V_337 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_7 ,
enum V_336 type , char * V_340 )
{
struct V_21 * V_341 =
V_7 -> V_12 . V_23 ;
int V_9 , V_342 , V_86 = 0 ;
switch ( type ) {
case V_339 :
V_342 = F_90 ( F_91 ( V_7 -> V_89 ,
V_343 ,
V_344 ) ,
V_345 ,
V_346 ) ;
for ( V_9 = 0 ; V_9 < V_341 -> V_16 ; V_9 ++ )
V_86 += sprintf ( V_340 + V_86 , L_26 ,
V_9 , V_341 -> V_17 [ V_9 ] . V_26 / 100 ,
( V_9 == V_342 ) ? L_27 : L_28 ) ;
break;
default:
break;
}
return V_86 ;
}
static int F_92 ( struct V_6 * V_7 , const struct V_2 * V_347 ,
T_8 V_348 , T_1 V_315 ,
T_9 * V_197 )
{
const struct V_1 * V_310 ;
struct V_36 * V_284 ;
T_1 V_349 ;
T_1 V_9 ;
if ( V_197 == NULL || V_7 == NULL || V_347 == NULL )
return - V_123 ;
V_284 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_310 = F_2 ( V_347 ) ;
V_349 = V_315 > V_310 -> V_197 - 1 ? V_310 -> V_197 - 1 : V_315 ;
V_197 -> V_350 = V_310 -> V_312 [ V_349 ] . V_158 ;
if ( V_348 == V_351 ) {
for ( V_9 = 1 ; V_9 < V_310 -> V_197 ; V_9 ++ ) {
if ( V_310 -> V_312 [ V_9 ] . V_158 > V_284 -> V_62 ) {
V_197 -> V_350 = V_310 -> V_312 [ V_9 ] . V_158 ;
break;
}
}
}
if ( V_349 == 0 )
V_197 -> V_352 = V_284 -> V_42 . V_101 [ V_140 - 1 ] ;
else
V_197 -> V_352 = V_284 -> V_42 . V_101 [ 0 ] ;
V_197 -> V_98 = ( F_13 ( V_7 , V_310 -> V_312 [ V_349 ] . V_159 ) + 2 ) / 4 ;
V_197 -> V_353 = 0 ;
V_197 -> V_354 = 0 ;
return 0 ;
}
static int F_93 ( struct V_6 * V_7 ,
const struct V_2 * V_347 , struct V_355 * V_316 )
{
const struct V_1 * V_310 = F_2 ( V_347 ) ;
V_316 -> V_356 = V_310 -> V_312 [ 0 ] . V_158 / ( 1 << ( V_310 -> V_312 [ 0 ] . V_161 ) ) ;
V_316 -> V_357 = V_310 -> V_312 [ V_310 -> V_197 - 1 ] . V_158 / ( 1 << ( V_310 -> V_312 [ V_310 -> V_197 - 1 ] . V_161 ) ) ;
return 0 ;
}
static int F_94 ( struct V_6 * V_7 , enum V_358 type ,
struct V_359 * V_267 )
{
struct V_36 * V_284 = (struct V_36 * ) ( V_7 -> V_37 ) ;
int V_9 ;
struct V_21 * V_22 ;
V_267 -> V_16 = F_6 ( V_7 ) ;
switch ( type ) {
case V_360 :
for ( V_9 = 0 ; V_9 < V_267 -> V_16 ; V_9 ++ )
V_267 -> clock [ V_9 ] = V_284 -> V_42 . V_145 [ V_9 ] ;
break;
case V_361 :
V_22 = V_7 -> V_12 . V_23 ;
for ( V_9 = 0 ; V_9 < V_267 -> V_16 ; V_9 ++ )
V_267 -> clock [ V_9 ] = V_22 -> V_17 [ V_9 ] . V_26 ;
break;
case V_362 :
V_267 -> V_16 = V_140 ;
for ( V_9 = 0 ; V_9 < V_267 -> V_16 ; V_9 ++ )
V_267 -> clock [ V_9 ] = V_284 -> V_42 . V_101 [ V_267 -> V_16 - 1 - V_9 ] ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_95 ( struct V_6 * V_7 , struct V_332 * V_267 )
{
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long V_197 ;
const struct V_94 * V_333 =
& V_7 -> V_12 . V_155 ;
if ( ( NULL == V_22 ) || ( V_22 -> V_16 <= 0 ) || ( V_267 == NULL ) )
return - V_123 ;
V_197 = F_6 ( V_7 ) - 1 ;
if ( V_197 < V_22 -> V_16 )
V_267 -> V_334 = V_22 -> V_17 [ V_197 ] . V_26 ;
else
V_267 -> V_334 = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_267 -> V_335 = V_333 -> V_100 ;
return 0 ;
}
static int F_96 ( struct V_6 * V_7 )
{
int V_363 = 0 ;
T_1 V_364 = F_91 ( V_7 -> V_89 ,
V_343 , V_365 ) ;
T_1 V_366 = F_90 ( V_364 , V_367 , V_368 ) ;
if ( F_90 ( V_364 , V_367 , V_369 ) )
V_363 = ( ( V_366 / 8 ) - 49 ) * V_370 ;
else
V_363 = ( V_366 / 8 ) * V_370 ;
return V_363 ;
}
static int F_97 ( struct V_6 * V_7 , int V_371 , T_10 * V_90 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
struct V_10 * V_182 =
V_7 -> V_12 . V_13 ;
struct V_29 * V_181 =
V_7 -> V_12 . V_30 ;
T_1 V_372 = F_90 ( F_91 ( V_7 -> V_89 , V_343 , V_344 ) ,
V_345 , V_346 ) ;
T_1 V_373 = F_90 ( F_91 ( V_7 -> V_89 , V_343 , V_374 ) ,
V_375 , V_376 ) ;
T_1 V_377 = F_90 ( F_91 ( V_7 -> V_89 , V_343 , V_374 ) ,
V_375 , V_378 ) ;
T_1 V_97 , V_33 , V_195 , V_18 , V_379 , V_380 ;
T_2 V_381 , V_382 ;
int V_43 ;
switch ( V_371 ) {
case V_383 :
if ( V_372 < V_384 ) {
V_97 = V_22 -> V_17 [ V_372 ] . V_26 ;
* V_90 = V_97 ;
return 0 ;
}
return - V_123 ;
case V_385 :
V_379 = ( F_91 ( V_7 -> V_89 , V_343 , V_386 ) &
V_387 ) >> V_388 ;
V_381 = F_13 ( V_7 , V_379 ) ;
* V_90 = V_381 ;
return 0 ;
case V_389 :
V_379 = ( F_91 ( V_7 -> V_89 , V_343 , V_390 ) &
V_391 ) >> V_392 ;
V_382 = F_13 ( V_7 , ( V_393 ) V_379 ) ;
* V_90 = V_382 ;
return 0 ;
case V_394 :
if ( ! V_36 -> V_209 ) {
if ( V_373 >= V_46 ) {
return - V_123 ;
} else {
V_33 = V_181 -> V_17 [ V_373 ] . V_33 ;
* V_90 = V_33 ;
return 0 ;
}
}
* V_90 = 0 ;
return 0 ;
case V_395 :
if ( ! V_36 -> V_209 ) {
if ( V_373 >= V_46 ) {
return - V_123 ;
} else {
V_195 = V_181 -> V_17 [ V_373 ] . V_195 ;
* V_90 = V_195 ;
return 0 ;
}
}
* V_90 = 0 ;
return 0 ;
case V_396 :
if ( ! V_36 -> V_210 ) {
if ( V_377 >= V_46 ) {
return - V_123 ;
} else {
V_18 = V_182 -> V_17 [ V_377 ] . V_18 ;
* V_90 = V_18 ;
return 0 ;
}
}
* V_90 = 0 ;
return 0 ;
case V_397 :
V_43 = F_7 ( V_7 -> V_39 , V_398 ) ;
if ( 0 == V_43 ) {
V_380 = F_98 ( V_7 -> V_89 , V_399 ) ;
V_380 = V_380 > 100 ? 100 : V_380 ;
} else {
V_380 = 50 ;
}
* V_90 = V_380 ;
return 0 ;
case V_400 :
* V_90 = V_36 -> V_209 ? 0 : 1 ;
return 0 ;
case V_401 :
* V_90 = V_36 -> V_210 ? 0 : 1 ;
return 0 ;
case V_402 :
* V_90 = F_96 ( V_7 ) ;
return 0 ;
default:
return - V_123 ;
}
}
int F_99 ( struct V_6 * V_7 )
{
V_7 -> V_403 = & V_404 ;
V_7 -> V_405 = & V_406 ;
return 0 ;
}
