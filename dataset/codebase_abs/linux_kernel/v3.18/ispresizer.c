static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
unsigned int V_6 , enum V_7 V_8 )
{
if ( V_8 == V_9 )
return F_2 ( V_5 , V_6 ) ;
else
return & V_3 -> V_10 [ V_6 ] ;
}
static struct V_11 *
F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_7 V_8 )
{
if ( V_8 == V_9 )
return F_4 ( V_5 , V_12 ) ;
else
return & V_3 -> V_13 . V_14 ;
}
static void F_5 ( struct V_2 * V_3 , const T_1 * V_15 ,
const T_1 * V_16 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_19 , V_20 , V_21 , V_22 ;
int V_23 ;
V_19 = V_24 ;
V_20 = V_25 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 += 2 ) {
V_21 = V_15 [ V_23 ] |
( V_15 [ V_23 + 1 ] << V_27 ) ;
V_22 = V_16 [ V_23 ] |
( V_16 [ V_23 + 1 ] << V_28 ) ;
F_7 ( V_18 , V_21 , V_29 , V_19 ) ;
F_7 ( V_18 , V_22 , V_29 , V_20 ) ;
V_19 += 4 ;
V_20 += 4 ;
}
}
static void F_8 ( struct V_2 * V_3 ,
enum V_30 type )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
if ( type == V_31 )
F_9 ( V_18 , V_29 , V_32 ,
V_33 ) ;
else
F_10 ( V_18 , V_29 , V_32 ,
V_33 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
enum V_34 V_35 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
switch ( V_35 ) {
case V_36 :
F_9 ( V_18 , V_29 , V_32 ,
V_37 ) ;
break;
case V_38 :
F_10 ( V_18 , V_29 , V_32 ,
V_37 ) ;
break;
default:
return;
}
}
static void F_12 ( struct V_2 * V_3 , T_2 V_39 ,
T_2 V_40 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = F_13 ( V_18 , V_29 , V_32 ) &
~ ( V_42 | V_43 ) ;
V_41 |= ( V_39 << V_44 ) & V_42 ;
V_41 |= ( V_40 << V_45 ) & V_43 ;
F_7 ( V_18 , V_41 , V_29 , V_32 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_46 * V_47 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_47 -> V_48 << V_49 )
& V_50 ;
V_41 |= ( V_47 -> V_51 << V_52 )
& V_53 ;
V_41 |= ( V_47 -> V_54 << V_55 )
& V_56 ;
V_41 |= ( V_47 -> V_57 << V_58 )
& V_59 ;
F_7 ( V_18 , V_41 , V_29 , V_60 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
enum V_61 V_62 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
if ( V_62 == V_63 )
F_9 ( V_18 , V_29 , V_32 ,
V_64 ) ;
else
F_10 ( V_18 , V_29 , V_32 ,
V_64 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
const struct V_65 * V_66 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
const T_1 * V_67 , * V_68 ;
T_2 V_41 ;
V_41 = F_13 ( V_18 , V_29 , V_32 ) &
~ ( V_69 | V_70 ) ;
V_41 |= ( ( V_66 -> V_71 - 1 ) << V_72 )
& V_69 ;
V_41 |= ( ( V_66 -> V_73 - 1 ) << V_74 )
& V_70 ;
F_7 ( V_18 , V_41 , V_29 , V_32 ) ;
if ( V_66 -> V_71 > V_75 )
V_67 = & V_76 . V_77 [ 0 ] ;
else
V_67 = & V_76 . V_78 [ 0 ] ;
if ( V_66 -> V_73 > V_75 )
V_68 = & V_76 . V_79 [ 0 ] ;
else
V_68 = & V_76 . V_80 [ 0 ] ;
F_5 ( V_3 , V_67 , V_68 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
T_2 V_81 , T_2 V_82 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_81 << V_83 )
& V_84 ;
V_41 |= ( V_82 << V_85 )
& V_86 ;
F_7 ( V_18 , V_41 , V_29 , V_87 ) ;
}
static void F_18 ( struct V_2 * V_3 , T_2 V_88 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_88 , V_29 , V_89 ) ;
}
static void F_19 ( struct V_2 * V_3 , T_2 V_90 , T_2 V_91 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_90 << V_92 )
& V_93 ;
V_41 |= ( V_91 << V_94 )
& V_95 ;
F_7 ( V_18 , V_41 , V_29 , V_96 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
T_2 V_81 , T_2 V_82 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_81 << V_97 )
& V_98 ;
V_41 |= ( V_82 << V_99 )
& V_100 ;
F_7 ( V_18 , V_41 , V_29 , V_101 ) ;
}
static void F_21 ( struct V_2 * V_3 , T_2 V_88 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_88 , V_29 , V_102 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
enum V_103 type )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
if ( type == V_104 )
F_9 ( V_18 , V_29 , V_32 ,
V_105 ) ;
else
F_10 ( V_18 , V_29 , V_32 ,
V_105 ) ;
}
static void F_23 ( struct V_2 * V_3 , T_2 V_106 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_106 , V_29 , V_107 ) ;
}
void F_24 ( struct V_2 * V_3 ,
unsigned int * V_108 )
{
struct V_109 * V_110 = F_25 ( & V_3 -> V_111 . V_112 ) ;
const struct V_1 * V_113 = & V_3 -> V_10 [ V_114 ] ;
unsigned long V_115 = F_26 ( V_110 -> V_116 , 200000000UL ) ;
unsigned long clock ;
clock = F_27 ( ( V_117 ) V_115 * V_3 -> V_13 . V_118 . V_82 , V_113 -> V_82 ) ;
clock = F_26 ( clock , V_115 / 2 ) ;
* V_108 = F_27 ( ( V_117 ) clock * V_3 -> V_13 . V_118 . V_81 , V_113 -> V_81 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_109 * V_110 = F_25 ( & V_3 -> V_111 . V_112 ) ;
struct V_17 * V_18 = F_6 ( V_3 ) ;
unsigned long V_116 = V_110 -> V_116 ;
struct V_119 * V_120 ;
unsigned int V_121 ;
unsigned int V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_125 ;
unsigned int V_126 ;
unsigned int V_127 ;
if ( V_3 -> V_128 != V_63 ) {
F_10 ( V_18 , V_129 , V_130 ,
V_131 ) ;
return;
}
switch ( V_18 -> V_132 ) {
case V_133 :
case V_134 :
default:
V_124 = 1024 ;
break;
case V_135 :
V_124 = 32 ;
break;
}
V_123 = F_27 ( ( V_117 ) V_116 / 2 * 256 + V_110 -> V_108 - 1 ,
V_110 -> V_108 ) ;
V_125 = F_29 ( V_123 , V_124 ) ;
V_120 = & V_110 -> V_136 ;
V_122 = F_29 ( V_3 -> V_13 . V_118 . V_81 * 2 , 256 )
* V_3 -> V_13 . V_118 . V_82 ;
V_121 = F_27 ( ( V_117 ) V_116 * V_120 -> V_137 ,
V_120 -> V_138 ) ;
V_123 = V_121 / V_122 ;
V_126 = V_123 / V_124 ;
V_127 = F_30 ( V_125 , V_126 ) ;
F_31 ( V_18 -> V_139 , L_1 , V_140 , V_127 ) ;
F_32 ( V_18 , V_129 , V_130 ,
V_131 ,
V_127 << V_141 ) ;
}
int F_33 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
return F_13 ( V_18 , V_29 , V_142 ) &
V_143 ;
}
static void F_34 ( struct V_2 * V_3 , T_2 V_106 )
{
V_3 -> V_144 = V_106 ;
if ( V_3 -> V_145 )
V_106 += V_3 -> V_145 & ~ 0x1f ;
F_23 ( V_3 , V_106 ) ;
}
static void F_35 ( struct V_2 * V_3 , T_2 V_106 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_106 << V_146 ,
V_29 , V_147 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_31 ( V_18 -> V_139 , L_2 ) ;
F_37 ( V_18 , V_148 ) ;
F_37 ( V_18 , V_149 ) ;
F_37 ( V_18 , V_150 ) ;
F_37 ( V_18 , V_151 ) ;
F_37 ( V_18 , V_152 ) ;
F_37 ( V_18 , V_153 ) ;
F_37 ( V_18 , V_154 ) ;
F_37 ( V_18 , V_155 ) ;
F_37 ( V_18 , V_156 ) ;
F_37 ( V_18 , V_157 ) ;
F_31 ( V_18 -> V_139 , L_3 ) ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_11 * V_128 ,
struct V_1 * V_158 ,
struct V_65 * V_66 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
const unsigned int V_159 = V_160 ;
const unsigned int V_161 = V_160 ;
unsigned int V_162 ;
unsigned int V_163 ;
unsigned int V_164 ;
unsigned int V_165 ;
unsigned int V_166 ;
unsigned int V_167 ;
unsigned int V_168 ;
unsigned int V_81 ;
unsigned int V_82 ;
V_165 = ( ( V_128 -> V_82 - 7 ) * 256 - 32 - 64 * V_159 ) / 1024 + 1 ;
V_165 = F_39 (unsigned int, min_height, MIN_OUT_HEIGHT) ;
V_167 = ( ( V_128 -> V_82 - 4 ) * 256 + 255 - 16 - 32 * V_159 ) / 64 + 1 ;
V_167 = F_40 (unsigned int, max_height, MAX_OUT_HEIGHT) ;
V_158 -> V_82 = F_41 ( V_158 -> V_82 , V_165 , V_167 ) ;
V_66 -> V_73 = ( ( V_128 -> V_82 - 4 ) * 256 + 255 - 16 - 32 * V_159 )
/ ( V_158 -> V_82 - 1 ) ;
if ( V_66 -> V_73 > V_75 )
V_66 -> V_73 = ( ( V_128 -> V_82 - 7 ) * 256 + 255 - 32 - 64 * V_159 )
/ ( V_158 -> V_82 - 1 ) ;
V_66 -> V_73 = F_42 (unsigned int, ratio->vert,
MIN_RESIZE_VALUE, MAX_RESIZE_VALUE) ;
if ( V_66 -> V_73 <= V_75 ) {
V_163 = ( V_158 -> V_82 - 1 ) * V_66 -> V_73
+ 32 * V_159 + 16 ;
V_82 = ( V_163 >> 8 ) + 4 ;
} else {
V_163 = ( V_158 -> V_82 - 1 ) * V_66 -> V_73
+ 64 * V_159 + 32 ;
V_82 = ( V_163 >> 8 ) + 7 ;
}
V_164 = ( ( V_128 -> V_81 - 7 ) * 256 - 32 - 64 * V_161 ) / 1024 + 1 ;
V_164 = F_39 (unsigned int, min_width, MIN_OUT_WIDTH) ;
if ( V_66 -> V_73 <= V_75 ) {
switch ( V_18 -> V_132 ) {
case V_133 :
V_166 = V_169 ;
break;
case V_134 :
default:
V_166 = V_170 ;
break;
case V_135 :
V_166 = V_171 ;
break;
}
} else {
switch ( V_18 -> V_132 ) {
case V_133 :
V_166 = V_172 ;
break;
case V_134 :
default:
V_166 = V_173 ;
break;
case V_135 :
V_166 = V_174 ;
break;
}
}
V_166 = F_26 ( ( ( V_128 -> V_81 - 7 ) * 256 + 255 - 16 - 32 * V_161 ) / 64
+ 1 , V_166 ) ;
V_168 = V_66 -> V_73 < 256 ? 8 : 2 ;
V_158 -> V_81 = F_41 ( V_158 -> V_81 , V_164 ,
V_166 & ~ ( V_168 - 1 ) ) ;
V_158 -> V_81 = F_43 ( V_158 -> V_81 , V_168 ) ;
V_66 -> V_71 = ( ( V_128 -> V_81 - 7 ) * 256 + 255 - 16 - 32 * V_161 )
/ ( V_158 -> V_81 - 1 ) ;
if ( V_66 -> V_71 > V_75 )
V_66 -> V_71 = ( ( V_128 -> V_81 - 7 ) * 256 + 255 - 32 - 64 * V_161 )
/ ( V_158 -> V_81 - 1 ) ;
V_66 -> V_71 = F_42 (unsigned int, ratio->horz,
MIN_RESIZE_VALUE, MAX_RESIZE_VALUE) ;
if ( V_66 -> V_71 <= V_75 ) {
V_162 = ( V_158 -> V_81 - 1 ) * V_66 -> V_71
+ 32 * V_161 + 16 ;
V_81 = ( V_162 >> 8 ) + 7 ;
} else {
V_162 = ( V_158 -> V_81 - 1 ) * V_66 -> V_71
+ 64 * V_161 + 32 ;
V_81 = ( V_162 >> 8 ) + 7 ;
}
V_128 -> V_90 += ( V_128 -> V_81 - V_81 ) / 2 ;
V_128 -> V_91 += ( V_128 -> V_82 - V_82 ) / 2 ;
V_128 -> V_81 = V_81 ;
V_128 -> V_82 = V_82 ;
}
static void F_44 ( struct V_2 * V_3 ,
const struct V_1 * V_128 ,
const struct V_1 * V_158 )
{
F_16 ( V_3 , & V_3 -> V_66 ) ;
if ( V_3 -> V_66 . V_71 >= V_175 )
F_8 ( V_3 , V_176 ) ;
else
F_8 ( V_3 , V_31 ) ;
F_28 ( V_3 ) ;
if ( V_3 -> V_128 == V_63 ) {
V_3 -> V_145 = ( V_3 -> V_13 . V_118 . V_91 * V_128 -> V_81 +
V_3 -> V_13 . V_118 . V_90 ) * 2 ;
F_19 ( V_3 , ( V_3 -> V_145 / 2 ) & 0xf , 0 ) ;
F_23 ( V_3 ,
V_3 -> V_144 + ( V_3 -> V_145 & ~ 0x1f ) ) ;
} else {
F_19 ( V_3 , V_3 -> V_13 . V_118 . V_90 * 2 ,
V_3 -> V_13 . V_118 . V_91 ) ;
F_23 ( V_3 , 0 ) ;
F_21 ( V_3 , 0 ) ;
}
F_20 ( V_3 , V_3 -> V_13 . V_118 . V_81 ,
V_3 -> V_13 . V_118 . V_82 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_177 , * V_178 ;
struct V_46 V_47 = { 0 , 0 , 0 , 0 } ;
F_15 ( V_3 , V_3 -> V_128 ) ;
V_177 = & V_3 -> V_10 [ V_12 ] ;
V_178 = & V_3 -> V_10 [ V_114 ] ;
if ( V_3 -> V_128 == V_179 )
F_21 ( V_3 , 0 ) ;
else
F_21 ( V_3 , F_43 ( V_177 -> V_81 , 0x10 ) * 2 ) ;
F_22 ( V_3 , V_180 ) ;
F_11 ( V_3 , V_177 -> V_181 ) ;
F_12 ( V_3 , V_160 , V_160 ) ;
F_14 ( V_3 , & V_47 ) ;
F_18 ( V_3 , F_43 ( V_178 -> V_81 * 2 , 32 ) ) ;
F_17 ( V_3 , V_178 -> V_81 , V_178 -> V_82 ) ;
F_44 ( V_3 , V_177 , V_178 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_9 ( V_18 , V_29 , V_142 ,
V_182 | V_183 ) ;
}
void F_47 ( struct V_2 * V_3 )
{
if ( V_3 -> V_184 == V_185 &&
V_3 -> V_186 . V_187 & V_188 ) {
F_46 ( V_3 ) ;
F_48 ( & V_3 -> V_186 ) ;
}
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_109 * V_110 = F_25 ( & V_3 -> V_111 . V_112 ) ;
struct V_189 * V_190 ;
int V_191 = 0 ;
if ( V_3 -> V_184 == V_192 )
return;
V_190 = F_50 ( & V_3 -> V_186 ) ;
if ( V_190 != NULL ) {
F_35 ( V_3 , V_190 -> V_193 ) ;
V_191 = 1 ;
}
V_110 -> V_184 |= V_194 ;
if ( V_3 -> V_128 == V_63 ) {
V_190 = F_50 ( & V_3 -> V_195 ) ;
if ( V_190 != NULL )
F_34 ( V_3 , V_190 -> V_193 ) ;
V_110 -> V_184 |= V_196 ;
}
if ( V_3 -> V_184 == V_197 ) {
if ( F_51 ( V_110 ) )
F_52 ( V_110 ,
V_197 ) ;
} else {
if ( V_191 )
F_46 ( V_3 ) ;
}
}
void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_177 , * V_178 ;
unsigned long V_198 ;
if ( F_54 ( & V_3 -> V_199 , & V_3 -> V_200 ) )
return;
F_55 ( & V_3 -> V_201 , V_198 ) ;
if ( V_3 -> V_202 ) {
V_178 = F_1 ( V_3 , NULL , V_114 ,
V_203 ) ;
V_177 = F_1 ( V_3 , NULL , V_12 ,
V_203 ) ;
F_44 ( V_3 , V_177 , V_178 ) ;
V_3 -> V_202 = 0 ;
}
F_56 ( & V_3 -> V_201 , V_198 ) ;
F_49 ( V_3 ) ;
}
static int F_57 ( struct V_204 * V_205 ,
struct V_189 * V_190 )
{
struct V_2 * V_3 = & V_205 -> V_18 -> V_206 ;
if ( V_205 -> type == V_207 )
F_34 ( V_3 , V_190 -> V_193 ) ;
if ( V_205 -> type == V_208 )
F_35 ( V_3 , V_190 -> V_193 ) ;
return 0 ;
}
static int F_58 ( struct V_209 * V_210 , int V_211 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_204 * V_186 = & V_3 -> V_186 ;
struct V_17 * V_18 = F_6 ( V_3 ) ;
struct V_212 * V_139 = F_60 ( V_3 ) ;
if ( V_3 -> V_184 == V_192 ) {
if ( V_211 == V_192 )
return 0 ;
F_61 ( V_18 , V_213 ) ;
F_45 ( V_3 ) ;
F_36 ( V_3 ) ;
}
switch ( V_211 ) {
case V_185 :
F_62 ( V_18 , V_214 ) ;
if ( V_186 -> V_187 & V_188 ) {
F_46 ( V_3 ) ;
F_48 ( V_186 ) ;
}
break;
case V_197 :
if ( V_3 -> V_128 == V_63 )
F_62 ( V_18 , V_215 ) ;
F_62 ( V_18 , V_214 ) ;
F_46 ( V_3 ) ;
break;
case V_192 :
if ( F_63 ( & V_210 -> V_112 , & V_3 -> V_199 ,
& V_3 -> V_200 ) )
F_31 ( V_139 , L_4 , V_210 -> V_216 ) ;
F_64 ( V_18 , V_215 |
V_214 ) ;
F_65 ( V_18 , V_213 ) ;
F_48 ( V_186 ) ;
break;
}
V_3 -> V_184 = V_211 ;
return 0 ;
}
static void F_66 ( const struct V_1 * V_217 ,
const struct V_1 * V_62 ,
struct V_11 * V_13 )
{
const unsigned int V_159 = V_160 ;
const unsigned int V_161 = V_160 ;
unsigned int V_164 =
( ( 32 * V_161 + ( V_62 -> V_81 - 1 ) * 64 + 16 ) >> 8 ) + 7 ;
unsigned int V_165 =
( ( 32 * V_159 + ( V_62 -> V_82 - 1 ) * 64 + 16 ) >> 8 ) + 4 ;
unsigned int V_166 =
( ( 64 * V_161 + ( V_62 -> V_81 - 1 ) * 1024 + 32 ) >> 8 ) + 7 ;
unsigned int V_167 =
( ( 64 * V_159 + ( V_62 -> V_82 - 1 ) * 1024 + 32 ) >> 8 ) + 7 ;
V_13 -> V_81 = F_42 ( T_2 , V_13 -> V_81 , V_164 , V_166 ) ;
V_13 -> V_82 = F_42 ( T_2 , V_13 -> V_82 , V_165 , V_167 ) ;
V_13 -> V_90 = F_42 ( T_2 , V_13 -> V_90 , 0 , V_217 -> V_81 - V_218 ) ;
V_13 -> V_81 = F_42 ( T_2 , V_13 -> V_81 , V_218 ,
V_217 -> V_81 - V_13 -> V_90 ) ;
V_13 -> V_91 = F_42 ( T_2 , V_13 -> V_91 , 0 , V_217 -> V_82 - V_219 ) ;
V_13 -> V_82 = F_42 ( T_2 , V_13 -> V_82 , V_219 ,
V_217 -> V_82 - V_13 -> V_91 ) ;
}
static int F_67 ( struct V_209 * V_210 ,
struct V_4 * V_5 ,
struct V_220 * V_221 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_1 * V_222 ;
struct V_1 * V_223 ;
struct V_65 V_66 ;
if ( V_221 -> V_6 != V_12 )
return - V_224 ;
V_223 = F_1 ( V_3 , V_5 , V_12 ,
V_221 -> V_8 ) ;
V_222 = F_1 ( V_3 , V_5 , V_114 ,
V_221 -> V_8 ) ;
switch ( V_221 -> V_225 ) {
case V_226 :
V_221 -> V_227 . V_90 = 0 ;
V_221 -> V_227 . V_91 = 0 ;
V_221 -> V_227 . V_81 = V_228 ;
V_221 -> V_227 . V_82 = V_228 ;
F_66 ( V_223 , V_222 , & V_221 -> V_227 ) ;
F_38 ( V_3 , & V_221 -> V_227 , V_222 , & V_66 ) ;
break;
case V_229 :
V_221 -> V_227 = * F_3 ( V_3 , V_5 , V_221 -> V_8 ) ;
F_38 ( V_3 , & V_221 -> V_227 , V_222 , & V_66 ) ;
break;
default:
return - V_224 ;
}
return 0 ;
}
static int F_68 ( struct V_209 * V_210 ,
struct V_4 * V_5 ,
struct V_220 * V_221 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_17 * V_18 = F_6 ( V_3 ) ;
const struct V_1 * V_223 ;
struct V_1 V_222 ;
struct V_65 V_66 ;
unsigned long V_198 ;
if ( V_221 -> V_225 != V_229 ||
V_221 -> V_6 != V_12 )
return - V_224 ;
V_223 = F_1 ( V_3 , V_5 , V_12 ,
V_221 -> V_8 ) ;
V_222 = * F_1 ( V_3 , V_5 , V_114 ,
V_221 -> V_8 ) ;
F_31 ( V_18 -> V_139 , L_5 ,
V_140 , V_221 -> V_8 == V_9 ? L_6 : L_7 ,
V_223 -> V_81 , V_223 -> V_82 ,
V_221 -> V_227 . V_90 , V_221 -> V_227 . V_91 , V_221 -> V_227 . V_81 , V_221 -> V_227 . V_82 ,
V_222 . V_81 , V_222 . V_82 ) ;
F_66 ( V_223 , & V_222 , & V_221 -> V_227 ) ;
* F_3 ( V_3 , V_5 , V_221 -> V_8 ) = V_221 -> V_227 ;
F_38 ( V_3 , & V_221 -> V_227 , & V_222 , & V_66 ) ;
F_31 ( V_18 -> V_139 , L_8 ,
V_140 , V_221 -> V_8 == V_9 ? L_6 : L_7 ,
V_223 -> V_81 , V_223 -> V_82 ,
V_221 -> V_227 . V_90 , V_221 -> V_227 . V_91 , V_221 -> V_227 . V_81 , V_221 -> V_227 . V_82 ,
V_222 . V_81 , V_222 . V_82 ) ;
if ( V_221 -> V_8 == V_9 ) {
* F_1 ( V_3 , V_5 , V_114 , V_221 -> V_8 ) =
V_222 ;
return 0 ;
}
F_55 ( & V_3 -> V_201 , V_198 ) ;
* F_1 ( V_3 , V_5 , V_114 , V_221 -> V_8 ) =
V_222 ;
V_3 -> V_66 = V_66 ;
V_3 -> V_13 . V_118 = V_221 -> V_227 ;
if ( V_3 -> V_184 != V_192 )
V_3 -> V_202 = 1 ;
F_56 ( & V_3 -> V_201 , V_198 ) ;
return 0 ;
}
static unsigned int F_69 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
if ( V_3 -> V_128 == V_63 ) {
return V_230 ;
} else {
if ( V_18 -> V_132 == V_133 )
return V_231 ;
else
return V_232 ;
}
}
static void F_70 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned int V_6 ,
struct V_1 * V_233 ,
enum V_7 V_8 )
{
struct V_1 * V_234 ;
struct V_65 V_66 ;
struct V_11 V_13 ;
switch ( V_6 ) {
case V_12 :
if ( V_233 -> V_181 != V_36 &&
V_233 -> V_181 != V_38 )
V_233 -> V_181 = V_36 ;
V_233 -> V_81 = F_42 ( T_2 , V_233 -> V_81 , V_218 ,
F_69 ( V_3 ) ) ;
V_233 -> V_82 = F_42 ( T_2 , V_233 -> V_82 , V_219 ,
V_235 ) ;
break;
case V_114 :
V_234 = F_1 ( V_3 , V_5 , V_12 , V_8 ) ;
V_233 -> V_181 = V_234 -> V_181 ;
V_13 = * F_3 ( V_3 , V_5 , V_8 ) ;
F_38 ( V_3 , & V_13 , V_233 , & V_66 ) ;
break;
}
V_233 -> V_236 = V_237 ;
V_233 -> V_238 = V_239 ;
}
static int F_71 ( struct V_209 * V_210 ,
struct V_4 * V_5 ,
struct V_240 * V_181 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_1 * V_234 ;
if ( V_181 -> V_6 == V_12 ) {
if ( V_181 -> V_241 >= F_72 ( V_242 ) )
return - V_224 ;
V_181 -> V_181 = V_242 [ V_181 -> V_241 ] ;
} else {
if ( V_181 -> V_241 != 0 )
return - V_224 ;
V_234 = F_1 ( V_3 , V_5 , V_12 ,
V_9 ) ;
V_181 -> V_181 = V_234 -> V_181 ;
}
return 0 ;
}
static int F_73 ( struct V_209 * V_210 ,
struct V_4 * V_5 ,
struct V_243 * V_244 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_1 V_234 ;
if ( V_244 -> V_241 != 0 )
return - V_224 ;
V_234 . V_181 = V_244 -> V_181 ;
V_234 . V_81 = 1 ;
V_234 . V_82 = 1 ;
F_70 ( V_3 , V_5 , V_244 -> V_6 , & V_234 , V_9 ) ;
V_244 -> V_164 = V_234 . V_81 ;
V_244 -> V_165 = V_234 . V_82 ;
if ( V_234 . V_181 != V_244 -> V_181 )
return - V_224 ;
V_234 . V_181 = V_244 -> V_181 ;
V_234 . V_81 = - 1 ;
V_234 . V_82 = - 1 ;
F_70 ( V_3 , V_5 , V_244 -> V_6 , & V_234 , V_9 ) ;
V_244 -> V_166 = V_234 . V_81 ;
V_244 -> V_167 = V_234 . V_82 ;
return 0 ;
}
static int F_74 ( struct V_209 * V_210 , struct V_4 * V_5 ,
struct V_245 * V_233 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_1 * V_234 ;
V_234 = F_1 ( V_3 , V_5 , V_233 -> V_6 , V_233 -> V_8 ) ;
if ( V_234 == NULL )
return - V_224 ;
V_233 -> V_234 = * V_234 ;
return 0 ;
}
static int F_75 ( struct V_209 * V_210 , struct V_4 * V_5 ,
struct V_245 * V_233 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_1 * V_234 ;
struct V_11 * V_13 ;
V_234 = F_1 ( V_3 , V_5 , V_233 -> V_6 , V_233 -> V_8 ) ;
if ( V_234 == NULL )
return - V_224 ;
F_70 ( V_3 , V_5 , V_233 -> V_6 , & V_233 -> V_234 , V_233 -> V_8 ) ;
* V_234 = V_233 -> V_234 ;
if ( V_233 -> V_6 == V_12 ) {
V_13 = F_3 ( V_3 , V_5 , V_233 -> V_8 ) ;
V_13 -> V_90 = 0 ;
V_13 -> V_91 = 0 ;
V_13 -> V_81 = V_233 -> V_234 . V_81 ;
V_13 -> V_82 = V_233 -> V_234 . V_82 ;
V_234 = F_1 ( V_3 , V_5 , V_114 ,
V_233 -> V_8 ) ;
* V_234 = V_233 -> V_234 ;
F_70 ( V_3 , V_5 , V_114 , V_234 ,
V_233 -> V_8 ) ;
}
if ( V_233 -> V_8 == V_203 ) {
V_3 -> V_13 . V_118 = V_3 -> V_13 . V_14 ;
F_38 ( V_3 , & V_3 -> V_13 . V_118 , V_234 ,
& V_3 -> V_66 ) ;
}
return 0 ;
}
static int F_76 ( struct V_209 * V_210 ,
struct V_246 * V_247 ,
struct V_245 * V_248 ,
struct V_245 * V_249 )
{
struct V_2 * V_3 = F_59 ( V_210 ) ;
struct V_109 * V_110 = F_25 ( & V_210 -> V_112 ) ;
F_24 ( V_3 , & V_110 -> V_108 ) ;
return F_77 ( V_210 , V_247 ,
V_248 , V_249 ) ;
}
static int F_78 ( struct V_209 * V_210 ,
struct V_4 * V_5 )
{
struct V_245 V_234 ;
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
V_234 . V_6 = V_12 ;
V_234 . V_8 = V_5 ? V_9 : V_203 ;
V_234 . V_234 . V_181 = V_36 ;
V_234 . V_234 . V_81 = 4096 ;
V_234 . V_234 . V_82 = 4096 ;
F_75 ( V_210 , V_5 , & V_234 ) ;
return 0 ;
}
static int F_79 ( struct V_250 * V_112 ,
const struct V_251 * V_252 ,
const struct V_251 * V_253 , T_2 V_198 )
{
struct V_209 * V_210 = F_80 ( V_112 ) ;
struct V_2 * V_3 = F_59 ( V_210 ) ;
switch ( V_252 -> V_241 | F_81 ( V_253 -> V_112 ) ) {
case V_12 | V_254 :
if ( V_198 & V_255 ) {
if ( V_3 -> V_128 == V_179 )
return - V_256 ;
V_3 -> V_128 = V_63 ;
} else {
if ( V_3 -> V_128 == V_63 )
V_3 -> V_128 = V_257 ;
}
break;
case V_12 | V_258 :
if ( V_198 & V_255 ) {
if ( V_3 -> V_128 == V_63 )
return - V_256 ;
V_3 -> V_128 = V_179 ;
} else {
if ( V_3 -> V_128 == V_179 )
V_3 -> V_128 = V_257 ;
}
break;
case V_114 | V_254 :
break;
default:
return - V_224 ;
}
return 0 ;
}
void F_82 ( struct V_2 * V_3 )
{
F_83 ( & V_3 -> V_111 ) ;
F_84 ( & V_3 -> V_195 ) ;
F_84 ( & V_3 -> V_186 ) ;
}
int F_85 ( struct V_2 * V_3 ,
struct V_259 * V_260 )
{
int V_261 ;
V_261 = F_86 ( V_260 , & V_3 -> V_111 ) ;
if ( V_261 < 0 )
goto error;
V_261 = F_87 ( & V_3 -> V_195 , V_260 ) ;
if ( V_261 < 0 )
goto error;
V_261 = F_87 ( & V_3 -> V_186 , V_260 ) ;
if ( V_261 < 0 )
goto error;
return 0 ;
error:
F_82 ( V_3 ) ;
return V_261 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_209 * V_210 = & V_3 -> V_111 ;
struct V_251 * V_262 = V_3 -> V_262 ;
struct V_250 * V_263 = & V_210 -> V_112 ;
int V_261 ;
V_3 -> V_128 = V_257 ;
F_89 ( V_210 , & V_264 ) ;
V_210 -> V_265 = & V_266 ;
F_90 ( V_210 -> V_216 , L_9 , sizeof( V_210 -> V_216 ) ) ;
V_210 -> V_267 = 1 << 16 ;
F_91 ( V_210 , V_3 ) ;
V_210 -> V_198 |= V_268 ;
V_262 [ V_12 ] . V_198 = V_269
| V_270 ;
V_262 [ V_114 ] . V_198 = V_271 ;
V_263 -> V_272 = & V_273 ;
V_261 = F_92 ( V_263 , V_274 , V_262 , 0 ) ;
if ( V_261 < 0 )
return V_261 ;
F_78 ( V_210 , NULL ) ;
V_3 -> V_195 . type = V_207 ;
V_3 -> V_195 . V_272 = & V_275 ;
V_3 -> V_195 . V_18 = F_6 ( V_3 ) ;
V_3 -> V_195 . V_276 = F_93 ( 4096 * 4096 ) * 2 * 3 ;
V_3 -> V_195 . V_277 = 32 ;
V_3 -> V_186 . type = V_208 ;
V_3 -> V_186 . V_272 = & V_275 ;
V_3 -> V_186 . V_18 = F_6 ( V_3 ) ;
V_3 -> V_186 . V_276 = F_93 ( 4096 * 4096 ) * 2 * 3 ;
V_3 -> V_186 . V_277 = 32 ;
V_261 = F_94 ( & V_3 -> V_195 , L_10 ) ;
if ( V_261 < 0 )
goto V_278;
V_261 = F_94 ( & V_3 -> V_186 , L_10 ) ;
if ( V_261 < 0 )
goto V_279;
V_3 -> V_186 . V_205 . V_112 . V_198 |= V_280 ;
V_261 = F_95 ( & V_3 -> V_195 . V_205 . V_112 , 0 ,
& V_3 -> V_111 . V_112 , V_12 , 0 ) ;
if ( V_261 < 0 )
goto V_281;
V_261 = F_95 ( & V_3 -> V_111 . V_112 , V_114 ,
& V_3 -> V_186 . V_205 . V_112 , 0 , 0 ) ;
if ( V_261 < 0 )
goto V_281;
return 0 ;
V_281:
F_96 ( & V_3 -> V_186 ) ;
V_279:
F_96 ( & V_3 -> V_195 ) ;
V_278:
F_97 ( & V_3 -> V_111 . V_112 ) ;
return V_261 ;
}
int F_98 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_206 ;
F_99 ( & V_3 -> V_199 ) ;
F_100 ( & V_3 -> V_200 , 0 ) ;
F_101 ( & V_3 -> V_201 ) ;
return F_88 ( V_3 ) ;
}
void F_102 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_206 ;
F_96 ( & V_3 -> V_195 ) ;
F_96 ( & V_3 -> V_186 ) ;
F_97 ( & V_3 -> V_111 . V_112 ) ;
}
