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
V_36 -> V_77 . V_78 = false ;
V_36 -> V_77 . V_79 = false ;
V_36 -> V_77 . V_80 = false ;
V_36 -> V_77 . V_81 = 0 ;
F_11 ( V_7 -> V_65 . V_66 ,
V_82 ) ;
F_10 ( V_7 -> V_65 . V_66 ,
V_83 ) ;
F_10 ( V_7 -> V_65 . V_66 ,
V_84 ) ;
V_42 . V_85 = sizeof( struct V_41 ) ;
V_42 . V_86 = V_87 ;
V_43 = F_12 ( V_7 -> V_88 , & V_42 ) ;
if ( ! V_43 ) {
if ( V_42 . V_89 & V_90 )
F_11 ( V_7 -> V_65 . V_66 ,
V_83 ) ;
if ( V_42 . V_89 & V_91 )
F_11 ( V_7 -> V_65 . V_66 ,
V_84 ) ;
}
return 0 ;
}
static T_1 F_13 (
struct V_6 * V_7 , T_2 V_92 )
{
return 6200 - ( V_92 * 25 ) ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_93 * V_22 )
{
struct V_36 * V_36 = (struct V_36 * ) V_7 -> V_37 ;
struct V_94 * V_42 = & V_36 -> V_42 ;
struct V_21 * V_95 =
V_7 -> V_12 . V_23 ;
if ( V_95 -> V_16 > 0 ) {
V_22 -> V_96 = V_95 -> V_17 [ V_95 -> V_16 - 1 ] . V_26 ;
V_22 -> V_97 = F_13 ( V_7 ,
( T_2 ) V_95 -> V_17 [ V_95 -> V_16 - 1 ] . V_98 ) ;
}
V_22 -> V_99 = V_42 -> V_100 [ 0 ] ;
return 0 ;
}
static int F_15 (
struct V_6 * V_7 ,
T_3 * V_101 )
{
T_1 V_102 =
sizeof( struct V_21 ) +
( 7 * sizeof( struct V_103 ) ) ;
struct V_21 * V_104 =
F_16 ( V_102 , V_105 ) ;
if ( NULL == V_104 ) {
F_17 ( V_106 L_1 ) ;
return - V_107 ;
}
V_104 -> V_16 = 8 ;
V_104 -> V_17 [ 0 ] . V_26 = V_108 ;
V_104 -> V_17 [ 0 ] . V_98 = 0 ;
V_104 -> V_17 [ 1 ] . V_26 = V_109 ;
V_104 -> V_17 [ 1 ] . V_98 = 1 ;
V_104 -> V_17 [ 2 ] . V_26 = V_110 ;
V_104 -> V_17 [ 2 ] . V_98 = 2 ;
V_104 -> V_17 [ 3 ] . V_26 = V_111 ;
V_104 -> V_17 [ 3 ] . V_98 = 3 ;
V_104 -> V_17 [ 4 ] . V_26 = V_112 ;
V_104 -> V_17 [ 4 ] . V_98 = 4 ;
V_104 -> V_17 [ 5 ] . V_26 = V_113 ;
V_104 -> V_17 [ 5 ] . V_98 = 5 ;
V_104 -> V_17 [ 6 ] . V_26 = V_114 ;
V_104 -> V_17 [ 6 ] . V_98 = 6 ;
V_104 -> V_17 [ 7 ] . V_26 = V_115 ;
V_104 -> V_17 [ 7 ] . V_98 = 7 ;
V_7 -> V_12 . V_116 = V_104 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) V_7 -> V_37 ;
T_4 * V_117 = NULL ;
T_1 V_9 ;
int V_43 = 0 ;
T_5 V_118 , V_119 ;
T_2 V_85 ;
V_117 = ( T_4 * ) F_19 (
V_7 -> V_88 ,
F_20 ( V_120 , V_121 ) ,
& V_85 , & V_118 , & V_119 ) ;
if ( V_119 != 9 ) {
F_17 ( V_106 L_2 , V_118 , V_119 ) ;
return - V_122 ;
}
if ( V_117 == NULL ) {
F_17 ( V_106 L_3 ) ;
return - V_122 ;
}
V_36 -> V_42 . V_123 =
F_21 ( V_117 -> V_124 ) ;
V_36 -> V_42 . V_125 =
F_21 ( V_117 -> V_126 ) ;
V_36 -> V_42 . V_127 =
F_21 ( V_117 -> V_128 ) ;
V_36 -> V_42 . V_129 =
F_21 ( V_117 -> V_130 ) ;
V_36 -> V_42 . V_131 =
F_22 ( V_117 -> V_132 ) ;
V_36 -> V_42 . V_133 =
( V_117 -> V_134 == 0 ) ? 5 : V_117 -> V_134 ;
V_36 -> V_42 . V_135 =
( V_117 -> V_136 == 0 ) ? 203 : V_117 -> V_136 ;
if ( V_36 -> V_42 . V_135 <=
V_36 -> V_42 . V_133 ) {
F_17 ( V_106 L_4 ) ;
return - V_122 ;
}
V_36 -> V_42 . V_137 =
V_36 -> V_53 &&
( F_21 ( V_117 -> V_130 ) >> 3 & 0x1 ) ;
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ ) {
if ( V_9 < V_139 ) {
V_36 -> V_42 . V_100 [ V_9 ] =
F_21 ( V_117 -> V_140 [ V_9 ] ) ;
}
V_36 -> V_42 . V_141 [ V_9 ] =
F_21 ( V_117 -> V_142 [ V_9 ] ) ;
}
for ( V_9 = 0 ; V_9 < V_143 ; V_9 ++ ) {
V_36 -> V_42 . V_144 [ V_9 ] =
F_21 ( V_117 -> V_145 [ V_9 ] . V_146 ) ;
}
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ ) {
V_36 -> V_42 . V_147 [ V_9 ] =
F_22 ( V_117 -> V_148 [ V_9 ] ) ;
}
if ( ! V_36 -> V_42 . V_137 ) {
for ( V_9 = 1 ; V_9 < V_138 ; V_9 ++ ) {
if ( V_9 < V_139 ) {
V_36 -> V_42 . V_100 [ V_9 ] =
V_36 -> V_42 . V_100 [ 0 ] ;
}
V_36 -> V_42 . V_141 [ V_9 ] =
V_36 -> V_42 . V_141 [ 0 ] ;
V_36 -> V_42 . V_147 [ V_9 ] =
V_36 -> V_42 . V_147 [ 0 ] ;
}
}
if ( F_21 ( V_117 -> V_149 ) &
V_150 ) {
F_11 ( V_7 -> V_65 . V_66 ,
V_151 ) ;
}
V_36 -> V_42 . V_152 = V_117 -> V_153 ;
F_14 ( V_7 ,
& V_7 -> V_12 . V_154 ) ;
F_15 ( V_7 ,
& V_117 -> V_155 [ 0 ] ) ;
return V_43 ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_156 . V_157 =
V_36 -> V_42 . V_125 ;
V_36 -> V_156 . V_158 =
( T_5 ) V_36 -> V_42 . V_131 ;
V_36 -> V_156 . V_159 = 0 ;
V_36 -> V_156 . V_160 = 0 ;
V_36 -> V_156 . V_161 = 1 ;
V_36 -> V_156 . V_162 = 0 ;
V_36 -> V_156 . V_163 = 0 ;
V_36 -> V_156 . V_164 = 0 ;
V_36 -> V_156 . V_165 = 0 ;
V_36 -> V_156 . V_166 = 0 ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
return 0 ;
}
static int F_25 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_170 * V_171 ;
int V_172 ;
T_1 V_9 ;
void * V_22 = NULL ;
T_6 V_173 ;
struct V_21 * V_174 =
V_7 -> V_12 . V_23 ;
struct V_21 * V_175 =
V_7 -> V_12 . V_176 ;
struct V_177 * V_178 =
V_7 -> V_12 . V_179 ;
struct V_29 * V_180 =
V_7 -> V_12 . V_30 ;
struct V_10 * V_181 =
V_7 -> V_12 . V_13 ;
if ( ! V_7 -> V_182 )
return 0 ;
V_172 = F_26 ( V_7 -> V_39 , & V_22 ) ;
F_27 ((0 == ret && NULL != table),
L_5 , return -EINVAL;) ;
V_171 = (struct V_170 * ) V_22 ;
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
V_171 -> V_183 . V_184 [ V_9 ] . V_185 =
( V_9 < V_174 -> V_16 ) ? ( T_5 ) V_174 -> V_17 [ V_9 ] . V_98 : 0 ;
V_171 -> V_183 . V_184 [ V_9 ] . V_186 =
( V_9 < V_174 -> V_16 ) ? V_174 -> V_17 [ V_9 ] . V_26 : 0 ;
F_28 ( V_7 ,
V_171 -> V_183 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_183 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_183 . V_184 [ V_9 ] . V_189 =
( V_9 < V_175 -> V_16 ) ? ( T_5 ) V_175 -> V_17 [ V_9 ] . V_98 : 0 ;
V_171 -> V_190 . V_184 [ V_9 ] . V_189 =
( V_9 < V_178 -> V_16 ) ? ( T_5 ) V_178 -> V_17 [ V_9 ] . V_98 : 0 ;
V_171 -> V_190 . V_184 [ V_9 ] . V_186 =
( V_9 < V_178 -> V_16 ) ? V_178 -> V_17 [ V_9 ] . V_191 : 0 ;
F_28 ( V_7 ,
V_171 -> V_190 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_190 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_192 . V_184 [ V_9 ] . V_189 =
( V_9 < V_180 -> V_16 ) ? ( T_5 ) V_180 -> V_17 [ V_9 ] . V_98 : 0 ;
V_171 -> V_192 . V_184 [ V_9 ] . V_186 =
( V_9 < V_180 -> V_16 ) ? V_180 -> V_17 [ V_9 ] . V_33 : 0 ;
F_28 ( V_7 ,
V_171 -> V_192 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_192 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_193 . V_184 [ V_9 ] . V_189 =
( V_9 < V_180 -> V_16 ) ? ( T_5 ) V_180 -> V_17 [ V_9 ] . V_98 : 0 ;
V_171 -> V_193 . V_184 [ V_9 ] . V_186 =
( V_9 < V_180 -> V_16 ) ? V_180 -> V_17 [ V_9 ] . V_194 : 0 ;
F_28 ( V_7 ,
V_171 -> V_193 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_193 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_195 . V_184 [ V_9 ] . V_189 =
( V_9 < V_181 -> V_16 ) ? ( T_5 ) V_181 -> V_17 [ V_9 ] . V_98 : 0 ;
V_171 -> V_195 . V_184 [ V_9 ] . V_186 =
( V_9 < V_181 -> V_16 ) ? V_181 -> V_17 [ V_9 ] . V_18 : 0 ;
F_28 ( V_7 ,
V_171 -> V_195 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_195 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
}
V_172 = F_29 ( V_7 -> V_39 ) ;
return V_172 ;
}
static int F_30 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 , V_196 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_122 ;
V_36 -> V_197 . V_198 = V_22 -> V_17 [ 0 ] . V_26 ;
V_36 -> V_197 . V_199 = V_22 -> V_17 [ 0 ] . V_26 ;
V_196 = F_6 ( V_7 ) - 1 ;
if ( V_196 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_196 ] . V_26 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_36 -> V_197 . V_200 = clock ;
V_36 -> V_197 . V_201 = clock ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_29 * V_22 =
V_7 -> V_12 . V_30 ;
unsigned long clock = 0 , V_196 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_122 ;
V_36 -> V_202 . V_198 = 0 ;
V_36 -> V_202 . V_199 = 0 ;
F_7 ( V_7 -> V_39 , V_203 ) ;
V_196 = F_8 ( V_7 -> V_39 ) ;
if ( V_196 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_196 ] . V_33 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_33 ;
V_36 -> V_202 . V_200 = clock ;
V_36 -> V_202 . V_201 = clock ;
return 0 ;
}
static int F_32 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_10 * V_22 =
V_7 -> V_12 . V_13 ;
unsigned long clock = 0 , V_196 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_122 ;
V_36 -> V_204 . V_198 = 0 ;
V_36 -> V_204 . V_199 = 0 ;
F_7 ( V_7 -> V_39 , V_205 ) ;
V_196 = F_8 ( V_7 -> V_39 ) ;
if ( V_196 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_196 ] . V_18 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_18 ;
V_36 -> V_204 . V_200 = clock ;
V_36 -> V_204 . V_201 = clock ;
return 0 ;
}
static int F_33 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_177 * V_22 =
V_7 -> V_12 . V_179 ;
unsigned long clock = 0 , V_196 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_122 ;
V_36 -> V_206 . V_198 = 0 ;
V_36 -> V_206 . V_199 = 0 ;
F_7 ( V_7 -> V_39 , V_207 ) ;
V_196 = F_8 ( V_7 -> V_39 ) ;
if ( V_196 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_196 ] . V_191 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_191 ;
V_36 -> V_206 . V_200 = clock ;
V_36 -> V_206 . V_201 = clock ;
return 0 ;
}
static int F_34 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_208 = false ;
V_36 -> V_209 = false ;
V_36 -> V_210 = false ;
V_36 -> V_211 = false ;
V_36 -> V_212 = true ;
return 0 ;
}
static int F_35 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_213 = 0 ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 ;
unsigned long V_196 ;
unsigned long V_214 ;
struct V_215 V_216 ;
unsigned long V_217 ;
V_36 -> V_197 . V_198 = V_22 -> V_17 [ 0 ] . V_26 ;
V_196 = F_6 ( V_7 ) - 1 ;
if ( V_196 < V_22 -> V_16 )
V_36 -> V_197 . V_200 = V_22 -> V_17 [ V_196 ] . V_26 ;
else
V_36 -> V_197 . V_200 = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
clock = V_216 . V_157 ;
if ( V_36 -> V_197 . V_199 != clock ) {
V_36 -> V_197 . V_199 = clock ;
F_37 ( V_7 -> V_39 ,
V_25 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_199 ,
V_25 ) ) ;
}
clock = V_36 -> V_197 . V_198 ;
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_218 ) ) {
V_217 = 75 ;
V_214 = ( V_7 -> V_12 . V_154 . V_99 *
V_217 ) / 100 ;
if ( clock < V_214 )
clock = V_214 ;
} else {
if ( clock < V_7 -> V_219 . V_96 )
clock = V_7 -> V_219 . V_96 ;
}
if ( V_36 -> V_197 . V_198 != clock ) {
V_36 -> V_197 . V_198 = clock ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_198 ,
V_24 ) ) ;
}
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_218 ) &&
V_36 -> V_197 . V_200 != clock ) {
V_36 -> V_197 . V_200 = clock ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_69 ) ) {
T_1 V_220 = V_7 -> V_221 . V_222 ;
if ( V_220 == 0 )
V_220 = V_223 ;
F_40 ( L_7 , V_220 ) ;
F_37 ( V_7 -> V_39 ,
V_224 ,
V_220 ) ;
}
return 0 ;
}
static int F_41 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_36 =
(struct V_36 * ) ( V_7 -> V_37 ) ;
F_37 ( V_7 -> V_39 ,
V_225 ,
V_36 -> V_197 . V_200 ) ;
return 0 ;
}
static int F_42 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
return 0 ;
}
static int F_43 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
int V_172 = 0 ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
unsigned long V_226 = 0 ;
if ( ! V_36 -> V_227 ) {
F_40 ( L_8 ) ;
V_226 |= V_228 ;
V_172 = F_37 (
V_7 -> V_39 ,
V_229 ,
V_226 ) ;
if ( V_172 == 0 )
V_36 -> V_227 = true ;
}
return V_172 ;
}
static int F_44 ( struct V_6 * V_7 , bool V_230 , bool V_231 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_232 -> V_227 ) {
if ( V_230 ) {
F_40 ( L_9 ) ;
return F_37 ( V_7 -> V_39 ,
V_233 ,
( V_231 ? 1 : 0 ) ) ;
} else {
F_40 ( L_10 ) ;
return F_37 ( V_7 -> V_39 ,
V_234 ,
( V_231 ? 1 : 0 ) ) ;
}
}
return 0 ;
}
static int F_45 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
bool V_235 ;
bool V_236 ;
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
const struct V_237 * V_238 = (struct V_237 * ) V_167 ;
const struct V_1 * V_239 = F_2 ( V_238 -> V_239 ) ;
if ( V_232 -> V_42 . V_137 ) {
V_235 = V_232 -> V_77 . V_80 ? true : false ;
V_236 = V_232 -> V_77 . V_80 ? false : true ;
if ( V_239 -> V_240 == V_241 )
F_44 ( V_7 , false , V_235 ) ;
else if( V_239 -> V_240 == V_242 )
F_44 ( V_7 , false , V_235 ) ;
else
F_44 ( V_7 , V_236 , V_235 ) ;
}
return 0 ;
}
static int F_46 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_232 -> V_243 = false ;
V_232 -> V_244 = false ;
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_232 -> V_227 = false ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_232 -> V_77 . V_245 = false ;
V_232 -> V_77 . V_81 = 0 ;
V_232 -> V_77 . V_78 = false ;
V_232 -> V_77 . V_79 = false ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
F_50 ( V_7 -> V_88 , V_246 ,
V_247 ) ;
return 0 ;
}
static int F_51 ( struct V_6 * V_7 , void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
int V_248 = 0xff ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
unsigned long V_226 = 0 ;
V_36 -> V_249 |= V_250 ;
V_226 |= V_251 ;
V_248 = F_37 ( V_7 -> V_39 ,
V_229 ,
V_226 ) ;
return V_248 ;
}
static int F_52 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_197 . V_198 = V_36 -> V_42 . V_125 ;
V_36 -> V_197 . V_200 = V_36 -> V_42 . V_125 ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_198 ,
V_24 ) ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
return 0 ;
}
int F_53 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_252 = 0xff ;
return 0 ;
}
static bool F_54 ( struct V_6 * V_7 ,
unsigned long V_253 )
{
int V_43 ;
unsigned long V_254 ;
V_43 = F_37 ( V_7 -> V_39 , V_255 , 0 ) ;
if ( V_43 == 0 ) {
V_254 = F_8 ( V_7 -> V_39 ) ;
if ( V_254 & V_253 )
return true ;
}
return V_43 ;
}
static int F_55 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
if ( F_54 ( V_7 , V_256 ) )
return V_257 ;
return 0 ;
}
static int F_56 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
return 0 ;
}
static int F_57 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
if ( ! F_54 ( V_7 ,
V_256 ) )
return V_257 ;
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
struct V_258 * V_259 ,
const struct V_258 * V_260 )
{
struct V_1 * V_261 =
F_1 ( & V_259 -> V_262 ) ;
const struct V_1 * V_263 =
F_2 ( & V_260 -> V_262 ) ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_215 V_216 ;
bool V_264 ;
unsigned long V_265 = 4 ;
V_261 -> V_266 = V_7 -> V_267 . V_266 ;
V_261 -> V_18 = V_7 -> V_267 . V_18 ;
V_261 -> V_268 = true ;
V_36 -> V_269 = ( V_7 -> V_270 . V_33 != 0 || V_7 -> V_270 . V_194 != 0 ||
V_7 -> V_267 . V_266 != 0 || V_7 -> V_267 . V_18 != 0 ) ;
V_36 -> V_271 = ( V_272 == V_259 -> V_273 . V_274 ) ;
if ( F_38 ( V_7 -> V_65 . V_66 , V_218 ) )
V_216 . V_275 = V_7 -> V_12 . V_154 . V_99 ;
else
V_216 . V_275 = 0 ;
if ( V_216 . V_275 < V_7 -> V_219 . V_99 )
V_216 . V_275 = V_7 -> V_219 . V_99 ;
V_264 = ( V_216 . V_275 > V_36 -> V_42 . V_100 [ V_139 - 1 ] )
|| ( V_265 >= 3 ) ;
V_261 -> V_240 = V_263 -> V_240 ;
if ( ( V_264 == false ) && ( V_261 -> V_240 == V_241 ) )
V_261 -> V_240 = V_242 ;
else if ( ( V_264 == true ) && ( V_261 -> V_240 != V_241 ) )
V_261 -> V_240 = V_241 ;
else
V_261 -> V_240 = V_276 ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 )
{
int V_43 = 0 ;
V_43 = F_9 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_11 ) ;
return V_43 ;
}
V_43 = F_18 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_12 ) ;
return V_43 ;
}
F_23 ( V_7 ) ;
V_43 = F_60 ( V_7 , & V_277 ,
& ( V_7 -> V_278 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_13 ) ;
return V_43 ;
}
V_43 = F_60 ( V_7 , & V_279 ,
& ( V_7 -> V_280 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_14 ) ;
return V_43 ;
}
V_43 = F_60 ( V_7 , & V_281 ,
& ( V_7 -> V_282 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_15 ) ;
return V_43 ;
}
V_43 = F_60 ( V_7 , & V_283 ,
& ( V_7 -> V_284 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_16 ) ;
return V_43 ;
}
V_43 = F_60 ( V_7 , & V_285 ,
& ( V_7 -> V_286 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_17 ) ;
return V_43 ;
}
V_43 = F_60 ( V_7 , & V_287 , & ( V_7 -> V_288 ) ) ;
if ( V_43 != 0 ) {
F_17 ( V_106 L_18 ) ;
return V_43 ;
}
return V_43 ;
}
static int F_61 ( struct V_6 * V_7 )
{
if ( V_7 != NULL || V_7 -> V_37 != NULL ) {
F_62 ( V_7 -> V_37 ) ;
F_62 ( V_7 ) ;
}
return 0 ;
}
int F_63 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_197 . V_198 !=
V_36 -> V_197 . V_200 )
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_24 ) ) ;
return 0 ;
}
int F_64 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long clock = 0 , V_196 ;
if ( NULL == V_22 || V_22 -> V_16 <= 0 )
return - V_122 ;
V_36 -> V_197 . V_198 = V_22 -> V_17 [ 0 ] . V_26 ;
V_36 -> V_197 . V_199 = V_22 -> V_17 [ 0 ] . V_26 ;
V_196 = F_6 ( V_7 ) - 1 ;
if ( V_196 < V_22 -> V_16 )
clock = V_22 -> V_17 [ V_196 ] . V_26 ;
else
clock = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_36 -> V_197 . V_200 = clock ;
V_36 -> V_197 . V_201 = clock ;
F_37 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_198 ,
V_24 ) ) ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
return 0 ;
}
int F_65 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_197 . V_198 !=
V_36 -> V_197 . V_200 ) {
V_36 -> V_197 . V_200 =
V_36 -> V_197 . V_198 ;
F_37 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_66 ( struct V_6 * V_7 ,
enum V_289 V_196 )
{
int V_172 = 0 ;
switch ( V_196 ) {
case V_290 :
V_172 = F_63 ( V_7 ) ;
if ( V_172 )
return V_172 ;
break;
case V_291 :
V_172 = F_65 ( V_7 ) ;
if ( V_172 )
return V_172 ;
break;
case V_292 :
V_172 = F_64 ( V_7 ) ;
if ( V_172 )
return V_172 ;
break;
default:
break;
}
V_7 -> V_293 = V_196 ;
return V_172 ;
}
int F_67 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_83 ) )
return F_7 ( V_7 -> V_39 ,
V_294 ) ;
return 0 ;
}
int F_68 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_83 ) ) {
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_295 ) ) {
return F_37 (
V_7 -> V_39 ,
V_296 , 1 ) ;
} else {
return F_37 (
V_7 -> V_39 ,
V_296 , 0 ) ;
}
}
return 0 ;
}
int F_69 ( struct V_6 * V_7 , bool V_297 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_29 * V_11 =
V_7 -> V_12 . V_30 ;
if ( ! V_297 ) {
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_218 ) ) {
V_36 -> V_202 . V_199 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_33 ;
F_37 ( V_7 -> V_39 ,
V_32 ,
F_5 ( V_7 ,
V_36 -> V_202 . V_199 ,
V_32 ) ) ;
F_70 ( V_7 , true ) ;
} else
F_70 ( V_7 , true ) ;
} else
F_70 ( V_7 , false ) ;
return 0 ;
}
int F_71 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_10 * V_11 =
V_7 -> V_12 . V_13 ;
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_218 ) ) {
V_36 -> V_204 . V_199 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_18 ;
F_37 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_204 . V_199 ,
V_15 ) ) ;
} else {
V_36 -> V_204 . V_199 = V_7 -> V_267 . V_18 ;
F_37 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_204 . V_199 ,
V_15 ) ) ;
}
return 0 ;
}
int F_72 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_84 ) )
return F_7 ( V_7 -> V_39 ,
V_298 ) ;
return 0 ;
}
int F_73 ( struct V_6 * V_7 )
{
if ( F_38 ( V_7 -> V_65 . V_66 ,
V_84 ) )
return F_7 ( V_7 -> V_39 ,
V_299 ) ;
return 0 ;
}
static int F_74 ( struct V_6 * V_7 , bool V_300 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
return V_36 -> V_42 . V_123 ;
}
static int F_75 ( struct V_6 * V_7 , bool V_300 )
{
struct V_258 * V_301 ;
struct V_1 * V_261 ;
if ( V_7 == NULL )
return - V_122 ;
V_301 = V_7 -> V_302 ;
if ( V_301 == NULL )
return - V_122 ;
V_261 = F_1 ( & V_301 -> V_262 ) ;
if ( V_300 )
return V_261 -> V_303 [ 0 ] . V_157 ;
else
return V_261 -> V_303 [ V_261 -> V_196 - 1 ] . V_157 ;
}
static int F_76 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_1 * V_261 = F_1 ( V_3 ) ;
V_261 -> V_196 = 1 ;
V_261 -> V_304 = 0 ;
V_261 -> V_305 = 0 ;
V_261 -> V_303 [ 0 ] = V_36 -> V_156 ;
return 0 ;
}
static int F_77 (
struct V_6 * V_7 ,
struct V_2 * V_3 ,
unsigned int V_306 ,
const void * V_307 )
{
struct V_1 * V_261 = F_1 ( V_3 ) ;
const T_7 * V_308 = V_307 ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
T_5 V_309 = V_308 -> V_306 ;
if ( V_309 > ( T_5 ) ( V_7 -> V_65 . V_310 - 1 ) )
V_309 = ( T_5 ) ( V_7 -> V_65 . V_310 - 1 ) ;
V_261 -> V_303 [ V_306 ] . V_157 = V_22 -> V_17 [ V_309 ] . V_26 ;
V_261 -> V_303 [ V_306 ] . V_158 = ( T_5 ) V_22 -> V_17 [ V_309 ] . V_98 ;
V_261 -> V_196 = V_306 + 1 ;
if ( F_38 ( V_7 -> V_65 . V_66 , V_69 ) ) {
V_261 -> V_303 [ V_306 ] . V_159 = 5 ;
V_261 -> V_303 [ V_306 ] . V_160 = 5 ;
}
return 0 ;
}
static int F_78 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned long V_172 = 0 ;
V_43 = F_79 ( V_7 , & V_172 ) ;
return V_43 ? 0 : V_172 ;
}
static int F_80 ( struct V_6 * V_7 ,
unsigned long V_311 , struct V_258 * V_301 )
{
int V_43 ;
struct V_1 * V_261 ;
V_301 -> V_262 . V_5 = V_4 ;
V_261 = F_1 ( & ( V_301 -> V_262 ) ) ;
V_43 = F_81 ( V_7 , V_311 , V_301 ,
F_77 ) ;
V_261 -> V_312 . V_33 = V_301 -> V_312 . V_313 ;
V_261 -> V_312 . V_194 = V_301 -> V_312 . V_314 ;
return V_43 ;
}
int F_82 ( struct V_6 * V_7 )
{
return sizeof( struct V_1 ) ;
}
static void
F_83 ( struct V_6 * V_7 , struct V_315 * V_316 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
struct V_10 * V_181 =
V_7 -> V_12 . V_13 ;
struct V_29 * V_180 =
V_7 -> V_12 . V_30 ;
T_1 V_317 = F_84 ( F_85 ( V_7 -> V_88 , V_318 , V_319 ) ,
V_320 , V_321 ) ;
T_1 V_322 = F_84 ( F_85 ( V_7 -> V_88 , V_318 , V_323 ) ,
V_324 , V_325 ) ;
T_1 V_326 = F_84 ( F_85 ( V_7 -> V_88 , V_318 , V_323 ) ,
V_324 , V_327 ) ;
T_1 V_96 , V_33 , V_194 , V_18 , V_328 , V_329 ;
T_2 V_330 , V_331 ;
int V_43 ;
if ( V_317 >= V_332 ) {
F_86 ( V_316 , L_19 , V_317 ) ;
} else {
V_96 = V_22 -> V_17 [ V_317 ] . V_26 ;
F_86 ( V_316 , L_20 , V_317 , V_96 / 100 ) ;
}
V_328 = ( F_85 ( V_7 -> V_88 , V_318 , V_333 ) &
V_334 ) >> V_335 ;
V_330 = F_13 ( V_7 , V_328 ) ;
V_328 = ( F_85 ( V_7 -> V_88 , V_318 , V_336 ) &
V_337 ) >> V_338 ;
V_331 = F_13 ( V_7 , ( V_339 ) V_328 ) ;
F_86 ( V_316 , L_21 , V_330 , V_331 ) ;
F_86 ( V_316 , L_22 , V_36 -> V_208 ? L_23 : L_24 ) ;
if ( ! V_36 -> V_208 ) {
if ( V_322 >= V_46 ) {
F_86 ( V_316 , L_25 , V_322 ) ;
} else {
V_33 = V_180 -> V_17 [ V_322 ] . V_33 ;
V_194 = V_180 -> V_17 [ V_322 ] . V_194 ;
F_86 ( V_316 , L_26 , V_322 , V_33 / 100 , V_194 / 100 ) ;
}
}
F_86 ( V_316 , L_27 , V_36 -> V_209 ? L_23 : L_24 ) ;
if ( ! V_36 -> V_209 ) {
if ( V_326 >= V_46 ) {
F_86 ( V_316 , L_28 , V_326 ) ;
} else {
V_18 = V_181 -> V_17 [ V_326 ] . V_18 ;
F_86 ( V_316 , L_29 , V_326 , V_18 / 100 ) ;
}
}
V_43 = F_7 ( V_7 -> V_39 , V_340 ) ;
if ( 0 == V_43 ) {
V_329 = F_87 ( V_7 -> V_88 , V_341 ) ;
V_329 = V_329 > 100 ? 100 : V_329 ;
} else {
V_329 = 50 ;
}
F_86 ( V_316 , L_30 , V_329 ) ;
}
static void F_88 (
const struct V_77 * V_77 )
{
F_40 ( L_31 ) ;
F_40 ( L_32 ,
V_77 -> V_78 ) ;
F_40 ( L_33 ,
V_77 -> V_79 ) ;
F_40 ( L_34 ,
V_77 -> V_80 ) ;
F_40 ( L_35 ,
V_77 -> V_81 ) ;
}
static int F_89 ( struct V_6 * V_7 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
T_1 V_342 = 0 ;
if ( V_232 -> V_77 . V_245 == true ) {
V_232 -> V_77 . V_245 = false ;
F_88 ( & V_232 -> V_77 ) ;
V_342 |= ( V_232 -> V_77 . V_81
& V_343 )
<< V_344 ;
V_342 |= ( V_232 -> V_77 . V_78 ? 0x1 : 0x0 )
<< V_345 ;
V_342 |= ( V_232 -> V_77 . V_79 ? 0x1 : 0x0 )
<< V_346 ;
F_40 ( L_36 ,
V_342 ) ;
F_37 ( V_7 -> V_39 ,
V_347 ,
V_342 ) ;
}
return 0 ;
}
static int F_90 ( struct V_6 * V_7 , T_1 V_348 ,
bool V_349 , bool V_350 , bool V_351 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_348 !=
V_232 -> V_77 . V_81
|| V_349 !=
V_232 -> V_77 . V_78
|| V_350 !=
V_232 -> V_77 . V_79
|| V_351 !=
V_232 -> V_77 . V_80 ) {
V_232 -> V_77 . V_245 = true ;
V_232 -> V_77 . V_81 =
V_348 ;
V_232 -> V_77 . V_78 =
V_349 ;
V_232 -> V_77 . V_79 =
V_350 ;
V_232 -> V_77 . V_80 =
V_351 ;
}
return 0 ;
}
static int F_91 ( struct V_6 * V_7 ,
struct V_352 * V_117 )
{
T_1 V_9 ;
const struct V_21 * V_22 =
V_7 -> V_12 . V_116 ;
const struct V_93 * V_353 =
& V_7 -> V_12 . V_154 ;
V_117 -> V_354 = V_353 -> V_96 ;
V_117 -> V_355 = V_353 -> V_99 ;
for ( V_9 = V_22 -> V_16 - 1 ; V_9 > 0 ; V_9 -- ) {
if ( V_353 -> V_97 >= V_22 -> V_17 [ V_9 ] . V_98 ) {
V_117 -> V_196 = V_22 -> V_17 [ V_9 ] . V_26 ;
return 0 ;
}
}
return - V_122 ;
}
int F_92 ( struct V_6 * V_7 )
{
struct V_36 * V_36 ;
int V_172 = 0 ;
V_36 = F_16 ( sizeof( struct V_36 ) , V_105 ) ;
if ( V_36 == NULL )
return - V_107 ;
V_7 -> V_37 = V_36 ;
V_7 -> V_356 = & V_357 ;
V_7 -> V_358 = & V_359 ;
return V_172 ;
}
