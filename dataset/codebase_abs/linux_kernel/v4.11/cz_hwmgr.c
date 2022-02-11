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
static T_1 F_3 ( struct V_6 * V_7 ,
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
F_17 ( L_1 ) ;
return - V_107 ;
}
V_105 -> V_16 = 8 ;
V_105 -> V_17 [ 0 ] . V_26 = V_108 ;
V_105 -> V_17 [ 0 ] . V_99 = 0 ;
V_105 -> V_17 [ 1 ] . V_26 = V_109 ;
V_105 -> V_17 [ 1 ] . V_99 = 1 ;
V_105 -> V_17 [ 2 ] . V_26 = V_110 ;
V_105 -> V_17 [ 2 ] . V_99 = 2 ;
V_105 -> V_17 [ 3 ] . V_26 = V_111 ;
V_105 -> V_17 [ 3 ] . V_99 = 3 ;
V_105 -> V_17 [ 4 ] . V_26 = V_112 ;
V_105 -> V_17 [ 4 ] . V_99 = 4 ;
V_105 -> V_17 [ 5 ] . V_26 = V_113 ;
V_105 -> V_17 [ 5 ] . V_99 = 5 ;
V_105 -> V_17 [ 6 ] . V_26 = V_114 ;
V_105 -> V_17 [ 6 ] . V_99 = 6 ;
V_105 -> V_17 [ 7 ] . V_26 = V_115 ;
V_105 -> V_17 [ 7 ] . V_99 = 7 ;
V_7 -> V_12 . V_116 = V_105 ;
return 0 ;
}
static int F_18 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) V_7 -> V_37 ;
T_4 * V_117 = NULL ;
T_1 V_9 ;
int V_43 = 0 ;
T_5 V_118 , V_119 ;
T_2 V_86 ;
V_117 = ( T_4 * ) F_19 (
V_7 -> V_89 ,
F_20 ( V_120 , V_121 ) ,
& V_86 , & V_118 , & V_119 ) ;
if ( V_119 != 9 ) {
F_17 ( L_2 , V_118 , V_119 ) ;
return - V_122 ;
}
if ( V_117 == NULL ) {
F_17 ( L_3 ) ;
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
F_17 ( L_4 ) ;
return - V_122 ;
}
V_36 -> V_42 . V_137 =
V_36 -> V_53 &&
( F_21 ( V_117 -> V_130 ) >> 3 & 0x1 ) ;
for ( V_9 = 0 ; V_9 < V_138 ; V_9 ++ ) {
if ( V_9 < V_139 ) {
V_36 -> V_42 . V_101 [ V_9 ] =
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
V_36 -> V_42 . V_101 [ V_9 ] =
V_36 -> V_42 . V_101 [ 0 ] ;
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
( V_9 < V_174 -> V_16 ) ? ( T_5 ) V_174 -> V_17 [ V_9 ] . V_99 : 0 ;
V_171 -> V_183 . V_184 [ V_9 ] . V_186 =
( V_9 < V_174 -> V_16 ) ? V_174 -> V_17 [ V_9 ] . V_26 : 0 ;
F_28 ( V_7 ,
V_171 -> V_183 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_183 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_183 . V_184 [ V_9 ] . V_189 =
( V_9 < V_175 -> V_16 ) ? ( T_5 ) V_175 -> V_17 [ V_9 ] . V_99 : 0 ;
V_171 -> V_190 . V_184 [ V_9 ] . V_189 =
( V_9 < V_178 -> V_16 ) ? ( T_5 ) V_178 -> V_17 [ V_9 ] . V_99 : 0 ;
V_171 -> V_190 . V_184 [ V_9 ] . V_186 =
( V_9 < V_178 -> V_16 ) ? V_178 -> V_17 [ V_9 ] . V_191 : 0 ;
F_28 ( V_7 ,
V_171 -> V_190 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_190 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_192 . V_184 [ V_9 ] . V_189 =
( V_9 < V_180 -> V_16 ) ? ( T_5 ) V_180 -> V_17 [ V_9 ] . V_99 : 0 ;
V_171 -> V_192 . V_184 [ V_9 ] . V_186 =
( V_9 < V_180 -> V_16 ) ? V_180 -> V_17 [ V_9 ] . V_33 : 0 ;
F_28 ( V_7 ,
V_171 -> V_192 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_192 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_193 . V_184 [ V_9 ] . V_189 =
( V_9 < V_180 -> V_16 ) ? ( T_5 ) V_180 -> V_17 [ V_9 ] . V_99 : 0 ;
V_171 -> V_193 . V_184 [ V_9 ] . V_186 =
( V_9 < V_180 -> V_16 ) ? V_180 -> V_17 [ V_9 ] . V_194 : 0 ;
F_28 ( V_7 ,
V_171 -> V_193 . V_184 [ V_9 ] . V_186 ,
& V_173 ) ;
V_171 -> V_193 . V_184 [ V_9 ] . V_187 =
( T_5 ) V_173 . V_188 ;
V_171 -> V_195 . V_184 [ V_9 ] . V_189 =
( V_9 < V_181 -> V_16 ) ? ( T_5 ) V_181 -> V_17 [ V_9 ] . V_99 : 0 ;
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
unsigned long V_215 ;
V_36 -> V_197 . V_198 = V_22 -> V_17 [ 0 ] . V_26 ;
V_196 = F_6 ( V_7 ) - 1 ;
if ( V_196 < V_22 -> V_16 )
V_36 -> V_197 . V_200 = V_22 -> V_17 [ V_196 ] . V_26 ;
else
V_36 -> V_197 . V_200 = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
clock = V_7 -> V_216 . V_217 ;
if ( clock == 0 )
F_37 ( L_7 ) ;
if ( V_36 -> V_197 . V_199 != clock ) {
V_36 -> V_197 . V_199 = clock ;
F_38 ( V_7 -> V_39 ,
V_25 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_199 ,
V_25 ) ) ;
}
clock = V_36 -> V_197 . V_198 ;
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_218 ) ) {
V_215 = 75 ;
V_214 = ( V_7 -> V_12 . V_154 . V_100 *
V_215 ) / 100 ;
if ( clock < V_214 )
clock = V_214 ;
} else {
if ( clock < V_7 -> V_219 . V_97 )
clock = V_7 -> V_219 . V_97 ;
}
if ( V_36 -> V_197 . V_198 != clock ) {
V_36 -> V_197 . V_198 = clock ;
F_38 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_198 ,
V_24 ) ) ;
}
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_218 ) &&
V_36 -> V_197 . V_200 != clock ) {
V_36 -> V_197 . V_200 = clock ;
F_38 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_40 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_220 ) ) {
T_1 V_221 = V_7 -> V_216 . V_222 ;
if ( V_221 == 0 )
V_221 = V_223 ;
F_41 ( L_8 , V_221 ) ;
F_38 ( V_7 -> V_39 ,
V_224 ,
V_221 ) ;
}
return 0 ;
}
static int F_42 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_36 =
(struct V_36 * ) ( V_7 -> V_37 ) ;
F_38 ( V_7 -> V_39 ,
V_225 ,
V_36 -> V_197 . V_200 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
return 0 ;
}
static int F_44 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
int V_172 = 0 ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
unsigned long V_226 = 0 ;
if ( ! V_36 -> V_227 ) {
F_41 ( L_9 ) ;
V_226 |= V_228 ;
V_172 = F_38 (
V_7 -> V_39 ,
V_229 ,
V_226 ) ;
if ( V_172 == 0 )
V_36 -> V_227 = true ;
}
return V_172 ;
}
static int F_45 ( struct V_6 * V_7 , bool V_230 , bool V_231 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_232 -> V_227 ) {
if ( V_230 ) {
F_41 ( L_10 ) ;
return F_38 ( V_7 -> V_39 ,
V_233 ,
( V_231 ? 1 : 0 ) ) ;
} else {
F_41 ( L_11 ) ;
return F_38 ( V_7 -> V_39 ,
V_234 ,
( V_231 ? 1 : 0 ) ) ;
}
}
return 0 ;
}
static int F_46 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
bool V_235 ;
bool V_236 ;
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
const struct V_237 * V_238 = (struct V_237 * ) V_167 ;
const struct V_1 * V_239 = F_2 ( V_238 -> V_239 ) ;
if ( V_232 -> V_42 . V_137 ) {
V_235 = V_232 -> V_78 . V_81 ? true : false ;
V_236 = V_232 -> V_78 . V_81 ? false : true ;
if ( V_239 -> V_240 == V_241 )
F_45 ( V_7 , false , V_235 ) ;
else if ( V_239 -> V_240 == V_242 )
F_45 ( V_7 , true , V_235 ) ;
else
F_45 ( V_7 , V_236 , V_235 ) ;
}
return 0 ;
}
static int F_47 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_232 -> V_243 = false ;
V_232 -> V_244 = false ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_232 -> V_227 = false ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_232 -> V_78 . V_245 = false ;
V_232 -> V_78 . V_82 = 0 ;
V_232 -> V_78 . V_79 = false ;
V_232 -> V_78 . V_80 = false ;
return 0 ;
}
static int F_50 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
F_51 ( V_7 -> V_89 , V_246 ,
V_247 ) ;
return 0 ;
}
static int F_52 ( struct V_6 * V_7 , void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
int V_248 = 0xff ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
unsigned long V_226 = 0 ;
V_36 -> V_249 |= V_250 ;
V_226 |= V_251 ;
V_248 = F_38 ( V_7 -> V_39 ,
V_229 ,
V_226 ) ;
return V_248 ;
}
static int F_53 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_197 . V_198 = V_36 -> V_42 . V_125 ;
V_36 -> V_197 . V_200 = V_36 -> V_42 . V_125 ;
F_38 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_198 ,
V_24 ) ) ;
F_38 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
return 0 ;
}
static int F_54 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_36 -> V_252 = 0xff ;
return 0 ;
}
static bool F_55 ( struct V_6 * V_7 ,
unsigned long V_253 )
{
int V_43 ;
unsigned long V_254 ;
V_43 = F_38 ( V_7 -> V_39 , V_255 , 0 ) ;
if ( V_43 == 0 ) {
V_254 = F_8 ( V_7 -> V_39 ) ;
if ( V_254 & V_253 )
return true ;
}
return V_43 ;
}
static int F_56 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
if ( F_55 ( V_7 , V_256 ) )
return V_257 ;
return 0 ;
}
static int F_57 ( struct V_6 * V_7 , void * V_167 ,
void * V_168 , void * V_169 , int V_43 )
{
return 0 ;
}
static int F_58 ( struct V_6 * V_7 ,
void * V_167 , void * V_168 ,
void * V_169 , int V_43 )
{
if ( ! F_55 ( V_7 ,
V_256 ) )
return V_257 ;
return 0 ;
}
static int F_59 ( struct V_6 * V_7 ,
struct V_258 * V_259 ,
const struct V_258 * V_260 )
{
struct V_1 * V_261 =
F_1 ( & V_259 -> V_262 ) ;
const struct V_1 * V_263 =
F_2 ( & V_260 -> V_262 ) ;
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_264 V_265 = { 0 , 0 , 0 , 0 } ;
bool V_266 ;
T_1 V_267 = 0 ;
struct V_268 V_117 = { 0 } ;
V_261 -> V_269 = V_7 -> V_270 . V_269 ;
V_261 -> V_18 = V_7 -> V_270 . V_18 ;
V_261 -> V_271 = true ;
V_36 -> V_272 = ( V_7 -> V_273 . V_33 != 0 || V_7 -> V_273 . V_194 != 0 ||
V_7 -> V_270 . V_269 != 0 || V_7 -> V_270 . V_18 != 0 ) ;
V_36 -> V_274 = ( V_275 == V_259 -> V_276 . V_277 ) ;
V_265 . V_278 = V_7 -> V_216 . V_279 != 0 ?
V_7 -> V_216 . V_279 :
V_36 -> V_42 . V_101 [ 1 ] ;
F_60 ( V_7 -> V_89 , & V_117 ) ;
V_267 = V_117 . V_280 ;
if ( F_39 ( V_7 -> V_65 . V_66 , V_218 ) )
V_265 . V_278 = V_7 -> V_12 . V_154 . V_100 ;
if ( V_265 . V_278 < V_7 -> V_219 . V_100 )
V_265 . V_278 = V_7 -> V_219 . V_100 ;
V_266 = ( V_265 . V_278 > V_36 -> V_42 . V_101 [ V_139 - 1 ] )
|| ( V_267 >= 3 ) ;
V_261 -> V_240 = V_263 -> V_240 ;
if ( ! V_266 && ( V_261 -> V_240 == V_241 ) )
V_261 -> V_240 = V_242 ;
else if ( V_266 && ( V_261 -> V_240 != V_241 ) )
V_261 -> V_240 = V_241 ;
else
V_261 -> V_240 = V_281 ;
return 0 ;
}
static int F_61 ( struct V_6 * V_7 )
{
int V_43 = 0 ;
struct V_36 * V_282 ;
V_282 = F_16 ( sizeof( struct V_36 ) , V_106 ) ;
if ( V_282 == NULL )
return - V_107 ;
V_7 -> V_37 = V_282 ;
V_43 = F_9 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( L_12 ) ;
return V_43 ;
}
V_43 = F_18 ( V_7 ) ;
if ( V_43 != 0 ) {
F_17 ( L_13 ) ;
return V_43 ;
}
F_23 ( V_7 ) ;
V_43 = F_62 ( V_7 , & V_283 ,
& ( V_7 -> V_284 ) ) ;
if ( V_43 != 0 ) {
F_17 ( L_14 ) ;
return V_43 ;
}
V_43 = F_62 ( V_7 , & V_285 ,
& ( V_7 -> V_286 ) ) ;
if ( V_43 != 0 ) {
F_17 ( L_15 ) ;
return V_43 ;
}
V_43 = F_62 ( V_7 , & V_287 ,
& ( V_7 -> V_288 ) ) ;
if ( V_43 != 0 ) {
F_17 ( L_16 ) ;
return V_43 ;
}
V_43 = F_62 ( V_7 , & V_289 ,
& ( V_7 -> V_290 ) ) ;
if ( V_43 != 0 ) {
F_17 ( L_17 ) ;
return V_43 ;
}
V_43 = F_62 ( V_7 , & V_291 ,
& ( V_7 -> V_292 ) ) ;
if ( V_43 != 0 ) {
F_17 ( L_18 ) ;
return V_43 ;
}
V_7 -> V_65 . V_293 = V_46 ;
V_43 = F_62 ( V_7 , & V_294 , & ( V_7 -> V_295 ) ) ;
if ( V_43 != 0 ) {
F_17 ( L_19 ) ;
return V_43 ;
}
return V_43 ;
}
static int F_63 ( struct V_6 * V_7 )
{
if ( V_7 != NULL ) {
F_64 ( V_7 , & ( V_7 -> V_295 ) ) ;
F_64 ( V_7 , & ( V_7 -> V_292 ) ) ;
F_64 ( V_7 , & ( V_7 -> V_290 ) ) ;
F_64 ( V_7 , & ( V_7 -> V_288 ) ) ;
F_64 ( V_7 , & ( V_7 -> V_286 ) ) ;
F_64 ( V_7 , & ( V_7 -> V_284 ) ) ;
F_65 ( V_7 -> V_37 ) ;
V_7 -> V_37 = NULL ;
}
return 0 ;
}
static int F_66 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_197 . V_198 !=
V_36 -> V_197 . V_200 )
F_38 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_24 ) ) ;
return 0 ;
}
static int F_67 ( struct V_6 * V_7 )
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
F_38 ( V_7 -> V_39 ,
V_24 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_198 ,
V_24 ) ) ;
F_38 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_36 -> V_197 . V_198 !=
V_36 -> V_197 . V_200 ) {
V_36 -> V_197 . V_200 =
V_36 -> V_197 . V_198 ;
F_38 ( V_7 -> V_39 ,
V_27 ,
F_4 ( V_7 ,
V_36 -> V_197 . V_200 ,
V_27 ) ) ;
}
return 0 ;
}
static int F_69 ( struct V_6 * V_7 ,
enum V_296 V_196 )
{
int V_172 = 0 ;
switch ( V_196 ) {
case V_297 :
V_172 = F_66 ( V_7 ) ;
if ( V_172 )
return V_172 ;
break;
case V_298 :
V_172 = F_68 ( V_7 ) ;
if ( V_172 )
return V_172 ;
break;
case V_299 :
V_172 = F_67 ( V_7 ) ;
if ( V_172 )
return V_172 ;
break;
default:
break;
}
V_7 -> V_300 = V_196 ;
return V_172 ;
}
int F_70 ( struct V_6 * V_7 )
{
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_84 ) )
return F_7 ( V_7 -> V_39 ,
V_301 ) ;
return 0 ;
}
int F_71 ( struct V_6 * V_7 )
{
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_84 ) ) {
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_302 ) ) {
return F_38 (
V_7 -> V_39 ,
V_303 , 1 ) ;
} else {
return F_38 (
V_7 -> V_39 ,
V_303 , 0 ) ;
}
}
return 0 ;
}
int F_72 ( struct V_6 * V_7 , bool V_304 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_29 * V_11 =
V_7 -> V_12 . V_30 ;
if ( ! V_304 ) {
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_218 ) ) {
V_36 -> V_202 . V_199 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_33 ;
F_38 ( V_7 -> V_39 ,
V_32 ,
F_5 ( V_7 ,
V_36 -> V_202 . V_199 ,
V_32 ) ) ;
F_73 ( V_7 , true ) ;
} else {
F_73 ( V_7 , true ) ;
}
} else {
F_73 ( V_7 , false ) ;
}
return 0 ;
}
int F_74 ( struct V_6 * V_7 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_10 * V_11 =
V_7 -> V_12 . V_13 ;
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_218 ) ) {
V_36 -> V_204 . V_199 =
V_11 -> V_17 [ V_11 -> V_16 - 1 ] . V_18 ;
F_38 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_204 . V_199 ,
V_15 ) ) ;
} else {
if ( V_7 -> V_270 . V_18 == 0 ) {
F_38 ( V_7 -> V_39 ,
V_15 , 0 ) ;
F_38 ( V_7 -> V_39 ,
V_14 , 1 ) ;
} else {
V_36 -> V_204 . V_199 = V_7 -> V_270 . V_18 ;
F_38 ( V_7 -> V_39 ,
V_15 ,
F_3 ( V_7 ,
V_36 -> V_204 . V_199 ,
V_15 ) ) ;
}
}
return 0 ;
}
int F_75 ( struct V_6 * V_7 )
{
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_85 ) )
return F_7 ( V_7 -> V_39 ,
V_305 ) ;
return 0 ;
}
int F_76 ( struct V_6 * V_7 )
{
if ( F_39 ( V_7 -> V_65 . V_66 ,
V_85 ) )
return F_7 ( V_7 -> V_39 ,
V_306 ) ;
return 0 ;
}
static int F_77 ( struct V_6 * V_7 , bool V_307 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
return V_36 -> V_42 . V_123 ;
}
static int F_78 ( struct V_6 * V_7 , bool V_307 )
{
struct V_258 * V_308 ;
struct V_1 * V_261 ;
if ( V_7 == NULL )
return - V_122 ;
V_308 = V_7 -> V_309 ;
if ( V_308 == NULL )
return - V_122 ;
V_261 = F_1 ( & V_308 -> V_262 ) ;
if ( V_307 )
return V_261 -> V_310 [ 0 ] . V_157 ;
else
return V_261 -> V_310 [ V_261 -> V_196 - 1 ] . V_157 ;
}
static int F_79 ( struct V_6 * V_7 ,
struct V_2 * V_3 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_1 * V_261 = F_1 ( V_3 ) ;
V_261 -> V_196 = 1 ;
V_261 -> V_311 = 0 ;
V_261 -> V_312 = 0 ;
V_261 -> V_310 [ 0 ] = V_36 -> V_156 ;
return 0 ;
}
static int F_80 (
struct V_6 * V_7 ,
struct V_2 * V_3 ,
unsigned int V_313 ,
const void * V_314 )
{
struct V_1 * V_261 = F_1 ( V_3 ) ;
const T_7 * V_315 = V_314 ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
T_5 V_316 = V_315 -> V_313 ;
if ( V_316 > ( T_5 ) ( V_7 -> V_65 . V_293 - 1 ) )
V_316 = ( T_5 ) ( V_7 -> V_65 . V_293 - 1 ) ;
V_261 -> V_310 [ V_313 ] . V_157 = V_22 -> V_17 [ V_316 ] . V_26 ;
V_261 -> V_310 [ V_313 ] . V_158 = ( T_5 ) V_22 -> V_17 [ V_316 ] . V_99 ;
V_261 -> V_196 = V_313 + 1 ;
if ( F_39 ( V_7 -> V_65 . V_66 , V_220 ) ) {
V_261 -> V_310 [ V_313 ] . V_159 = 5 ;
V_261 -> V_310 [ V_313 ] . V_160 = 5 ;
}
return 0 ;
}
static int F_81 ( struct V_6 * V_7 )
{
int V_43 ;
unsigned long V_172 = 0 ;
V_43 = F_82 ( V_7 , & V_172 ) ;
return V_43 ? 0 : V_172 ;
}
static int F_83 ( struct V_6 * V_7 ,
unsigned long V_317 , struct V_258 * V_308 )
{
int V_43 ;
struct V_1 * V_261 ;
V_308 -> V_262 . V_5 = V_4 ;
V_261 = F_1 ( & ( V_308 -> V_262 ) ) ;
V_43 = F_84 ( V_7 , V_317 , V_308 ,
F_80 ) ;
V_261 -> V_318 . V_33 = V_308 -> V_318 . V_319 ;
V_261 -> V_318 . V_194 = V_308 -> V_318 . V_320 ;
return V_43 ;
}
static int F_85 ( struct V_6 * V_7 )
{
return sizeof( struct V_1 ) ;
}
static void F_86 (
const struct V_78 * V_78 )
{
F_41 ( L_20 ) ;
F_41 ( L_21 ,
V_78 -> V_79 ) ;
F_41 ( L_22 ,
V_78 -> V_80 ) ;
F_41 ( L_23 ,
V_78 -> V_81 ) ;
F_41 ( L_24 ,
V_78 -> V_82 ) ;
}
static int F_87 ( struct V_6 * V_7 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
T_1 V_282 = 0 ;
if ( V_232 -> V_78 . V_245 ) {
V_232 -> V_78 . V_245 = false ;
F_86 ( & V_232 -> V_78 ) ;
V_282 |= ( V_232 -> V_78 . V_82
& V_321 )
<< V_322 ;
V_282 |= ( V_232 -> V_78 . V_79 ? 0x1 : 0x0 )
<< V_323 ;
V_282 |= ( V_232 -> V_78 . V_80 ? 0x1 : 0x0 )
<< V_324 ;
F_41 ( L_25 ,
V_282 ) ;
F_38 ( V_7 -> V_39 ,
V_325 ,
V_282 ) ;
}
return 0 ;
}
static int F_88 ( struct V_6 * V_7 , T_1 V_326 ,
bool V_327 , bool V_328 , bool V_329 )
{
struct V_36 * V_232 = (struct V_36 * ) ( V_7 -> V_37 ) ;
if ( V_326 !=
V_232 -> V_78 . V_82 ||
V_327 != V_232 -> V_78 . V_79 ||
V_328 != V_232 -> V_78 . V_80 ||
V_329 != V_232 -> V_78 . V_81 ) {
V_232 -> V_78 . V_245 = true ;
V_232 -> V_78 . V_82 =
V_326 ;
V_232 -> V_78 . V_79 =
V_327 ;
V_232 -> V_78 . V_80 =
V_328 ;
V_232 -> V_78 . V_81 =
V_329 ;
}
return 0 ;
}
static int F_89 ( struct V_6 * V_7 ,
struct V_330 * V_117 )
{
T_1 V_9 ;
const struct V_21 * V_22 =
V_7 -> V_12 . V_116 ;
const struct V_94 * V_331 =
& V_7 -> V_12 . V_154 ;
V_117 -> V_332 = V_331 -> V_97 ;
V_117 -> V_333 = V_331 -> V_100 ;
for ( V_9 = V_22 -> V_16 - 1 ; V_9 > 0 ; V_9 -- ) {
if ( V_331 -> V_98 >= V_22 -> V_17 [ V_9 ] . V_99 ) {
V_117 -> V_196 = V_22 -> V_17 [ V_9 ] . V_26 ;
return 0 ;
}
}
return - V_122 ;
}
static int F_90 ( struct V_6 * V_7 ,
enum V_334 type , T_1 V_335 )
{
if ( V_7 -> V_300 != V_336 )
return - V_122 ;
switch ( type ) {
case V_337 :
F_38 ( V_7 -> V_39 ,
V_24 ,
V_335 ) ;
F_38 ( V_7 -> V_39 ,
V_27 ,
V_335 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_91 ( struct V_6 * V_7 ,
enum V_334 type , char * V_338 )
{
struct V_21 * V_339 =
V_7 -> V_12 . V_23 ;
int V_9 , V_340 , V_86 = 0 ;
switch ( type ) {
case V_337 :
V_340 = F_92 ( F_93 ( V_7 -> V_89 ,
V_341 ,
V_342 ) ,
V_343 ,
V_344 ) ;
for ( V_9 = 0 ; V_9 < V_339 -> V_16 ; V_9 ++ )
V_86 += sprintf ( V_338 + V_86 , L_26 ,
V_9 , V_339 -> V_17 [ V_9 ] . V_26 / 100 ,
( V_9 == V_340 ) ? L_27 : L_28 ) ;
break;
default:
break;
}
return V_86 ;
}
static int F_94 ( struct V_6 * V_7 , const struct V_2 * V_345 ,
T_8 V_346 , T_1 V_313 ,
T_9 * V_196 )
{
const struct V_1 * V_308 ;
struct V_36 * V_282 ;
T_1 V_347 ;
T_1 V_9 ;
if ( V_196 == NULL || V_7 == NULL || V_345 == NULL )
return - V_122 ;
V_282 = (struct V_36 * ) ( V_7 -> V_37 ) ;
V_308 = F_2 ( V_345 ) ;
V_347 = V_313 > V_308 -> V_196 - 1 ? V_308 -> V_196 - 1 : V_313 ;
V_196 -> V_348 = V_308 -> V_310 [ V_347 ] . V_157 ;
if ( V_346 == V_349 ) {
for ( V_9 = 1 ; V_9 < V_308 -> V_196 ; V_9 ++ ) {
if ( V_308 -> V_310 [ V_9 ] . V_157 > V_282 -> V_62 ) {
V_196 -> V_348 = V_308 -> V_310 [ V_9 ] . V_157 ;
break;
}
}
}
if ( V_347 == 0 )
V_196 -> V_350 = V_282 -> V_42 . V_101 [ V_139 - 1 ] ;
else
V_196 -> V_350 = V_282 -> V_42 . V_101 [ 0 ] ;
V_196 -> V_98 = ( F_13 ( V_7 , V_308 -> V_310 [ V_347 ] . V_158 ) + 2 ) / 4 ;
V_196 -> V_351 = 0 ;
V_196 -> V_352 = 0 ;
return 0 ;
}
static int F_95 ( struct V_6 * V_7 ,
const struct V_2 * V_345 , struct V_353 * V_314 )
{
const struct V_1 * V_308 = F_2 ( V_345 ) ;
V_314 -> V_354 = V_308 -> V_310 [ 0 ] . V_157 / ( 1 << ( V_308 -> V_310 [ 0 ] . V_160 ) ) ;
V_314 -> V_355 = V_308 -> V_310 [ V_308 -> V_196 - 1 ] . V_157 / ( 1 << ( V_308 -> V_310 [ V_308 -> V_196 - 1 ] . V_160 ) ) ;
return 0 ;
}
static int F_96 ( struct V_6 * V_7 , enum V_356 type ,
struct V_357 * V_265 )
{
struct V_36 * V_282 = (struct V_36 * ) ( V_7 -> V_37 ) ;
int V_9 ;
struct V_21 * V_22 ;
V_265 -> V_16 = F_6 ( V_7 ) ;
switch ( type ) {
case V_358 :
for ( V_9 = 0 ; V_9 < V_265 -> V_16 ; V_9 ++ )
V_265 -> clock [ V_9 ] = V_282 -> V_42 . V_144 [ V_9 ] ;
break;
case V_359 :
V_22 = V_7 -> V_12 . V_23 ;
for ( V_9 = 0 ; V_9 < V_265 -> V_16 ; V_9 ++ )
V_265 -> clock [ V_9 ] = V_22 -> V_17 [ V_9 ] . V_26 ;
break;
case V_360 :
V_265 -> V_16 = V_139 ;
for ( V_9 = 0 ; V_9 < V_265 -> V_16 ; V_9 ++ )
V_265 -> clock [ V_9 ] = V_282 -> V_42 . V_101 [ V_265 -> V_16 - 1 - V_9 ] ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_97 ( struct V_6 * V_7 , struct V_330 * V_265 )
{
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
unsigned long V_196 ;
const struct V_94 * V_331 =
& V_7 -> V_12 . V_154 ;
if ( ( NULL == V_22 ) || ( V_22 -> V_16 <= 0 ) || ( V_265 == NULL ) )
return - V_122 ;
V_196 = F_6 ( V_7 ) - 1 ;
if ( V_196 < V_22 -> V_16 )
V_265 -> V_332 = V_22 -> V_17 [ V_196 ] . V_26 ;
else
V_265 -> V_332 = V_22 -> V_17 [ V_22 -> V_16 - 1 ] . V_26 ;
V_265 -> V_333 = V_331 -> V_100 ;
return 0 ;
}
static int F_98 ( struct V_6 * V_7 )
{
int V_361 = 0 ;
T_1 V_362 = F_93 ( V_7 -> V_89 ,
V_341 , V_363 ) ;
T_1 V_364 = F_92 ( V_362 , V_365 , V_366 ) ;
if ( F_92 ( V_362 , V_365 , V_367 ) )
V_361 = ( ( V_364 / 8 ) - 49 ) * V_368 ;
else
V_361 = ( V_364 / 8 ) * V_368 ;
return V_361 ;
}
static int F_99 ( struct V_6 * V_7 , int V_369 , T_10 * V_90 )
{
struct V_36 * V_36 = (struct V_36 * ) ( V_7 -> V_37 ) ;
struct V_21 * V_22 =
V_7 -> V_12 . V_23 ;
struct V_10 * V_181 =
V_7 -> V_12 . V_13 ;
struct V_29 * V_180 =
V_7 -> V_12 . V_30 ;
T_1 V_370 = F_92 ( F_93 ( V_7 -> V_89 , V_341 , V_342 ) ,
V_343 , V_344 ) ;
T_1 V_371 = F_92 ( F_93 ( V_7 -> V_89 , V_341 , V_372 ) ,
V_373 , V_374 ) ;
T_1 V_375 = F_92 ( F_93 ( V_7 -> V_89 , V_341 , V_372 ) ,
V_373 , V_376 ) ;
T_1 V_97 , V_33 , V_194 , V_18 , V_377 , V_378 ;
T_2 V_379 , V_380 ;
int V_43 ;
switch ( V_369 ) {
case V_381 :
if ( V_370 < V_382 ) {
V_97 = V_22 -> V_17 [ V_370 ] . V_26 ;
* V_90 = V_97 ;
return 0 ;
}
return - V_122 ;
case V_383 :
V_377 = ( F_93 ( V_7 -> V_89 , V_341 , V_384 ) &
V_385 ) >> V_386 ;
V_379 = F_13 ( V_7 , V_377 ) ;
* V_90 = V_379 ;
return 0 ;
case V_387 :
V_377 = ( F_93 ( V_7 -> V_89 , V_341 , V_388 ) &
V_389 ) >> V_390 ;
V_380 = F_13 ( V_7 , ( V_391 ) V_377 ) ;
* V_90 = V_380 ;
return 0 ;
case V_392 :
if ( ! V_36 -> V_208 ) {
if ( V_371 >= V_46 ) {
return - V_122 ;
} else {
V_33 = V_180 -> V_17 [ V_371 ] . V_33 ;
* V_90 = V_33 ;
return 0 ;
}
}
* V_90 = 0 ;
return 0 ;
case V_393 :
if ( ! V_36 -> V_208 ) {
if ( V_371 >= V_46 ) {
return - V_122 ;
} else {
V_194 = V_180 -> V_17 [ V_371 ] . V_194 ;
* V_90 = V_194 ;
return 0 ;
}
}
* V_90 = 0 ;
return 0 ;
case V_394 :
if ( ! V_36 -> V_209 ) {
if ( V_375 >= V_46 ) {
return - V_122 ;
} else {
V_18 = V_181 -> V_17 [ V_375 ] . V_18 ;
* V_90 = V_18 ;
return 0 ;
}
}
* V_90 = 0 ;
return 0 ;
case V_395 :
V_43 = F_7 ( V_7 -> V_39 , V_396 ) ;
if ( 0 == V_43 ) {
V_378 = F_100 ( V_7 -> V_89 , V_397 ) ;
V_378 = V_378 > 100 ? 100 : V_378 ;
} else {
V_378 = 50 ;
}
* V_90 = V_378 ;
return 0 ;
case V_398 :
* V_90 = V_36 -> V_208 ? 0 : 1 ;
return 0 ;
case V_399 :
* V_90 = V_36 -> V_209 ? 0 : 1 ;
return 0 ;
case V_400 :
* V_90 = F_98 ( V_7 ) ;
return 0 ;
default:
return - V_122 ;
}
}
int F_101 ( struct V_6 * V_7 )
{
V_7 -> V_401 = & V_402 ;
V_7 -> V_403 = & V_404 ;
return 0 ;
}
