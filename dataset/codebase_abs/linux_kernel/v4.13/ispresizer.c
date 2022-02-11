static struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
unsigned int V_6 , enum V_7 V_8 )
{
if ( V_8 == V_9 )
return F_2 ( & V_3 -> V_10 , V_5 , V_6 ) ;
else
return & V_3 -> V_11 [ V_6 ] ;
}
static struct V_12 *
F_3 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_7 V_8 )
{
if ( V_8 == V_9 )
return F_4 ( & V_3 -> V_10 , V_5 , V_13 ) ;
else
return & V_3 -> V_14 . V_15 ;
}
static void F_5 ( struct V_2 * V_3 , const T_1 * V_16 ,
const T_1 * V_17 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
T_2 V_20 , V_21 , V_22 , V_23 ;
int V_24 ;
V_20 = V_25 ;
V_21 = V_26 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 += 2 ) {
V_22 = V_16 [ V_24 ] |
( V_16 [ V_24 + 1 ] << V_28 ) ;
V_23 = V_17 [ V_24 ] |
( V_17 [ V_24 + 1 ] << V_29 ) ;
F_7 ( V_19 , V_22 , V_30 , V_20 ) ;
F_7 ( V_19 , V_23 , V_30 , V_21 ) ;
V_20 += 4 ;
V_21 += 4 ;
}
}
static void F_8 ( struct V_2 * V_3 ,
enum V_31 type )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
if ( type == V_32 )
F_9 ( V_19 , V_30 , V_33 ,
V_34 ) ;
else
F_10 ( V_19 , V_30 , V_33 ,
V_34 ) ;
}
static void F_11 ( struct V_2 * V_3 , T_2 V_35 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
switch ( V_35 ) {
case V_36 :
F_9 ( V_19 , V_30 , V_33 ,
V_37 ) ;
break;
case V_38 :
F_10 ( V_19 , V_30 , V_33 ,
V_37 ) ;
break;
default:
return;
}
}
static void F_12 ( struct V_2 * V_3 , T_2 V_39 ,
T_2 V_40 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = F_13 ( V_19 , V_30 , V_33 ) &
~ ( V_42 | V_43 ) ;
V_41 |= ( V_39 << V_44 ) & V_42 ;
V_41 |= ( V_40 << V_45 ) & V_43 ;
F_7 ( V_19 , V_41 , V_30 , V_33 ) ;
}
static void F_14 ( struct V_2 * V_3 ,
struct V_46 * V_47 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_47 -> V_48 << V_49 )
& V_50 ;
V_41 |= ( V_47 -> V_51 << V_52 )
& V_53 ;
V_41 |= ( V_47 -> V_54 << V_55 )
& V_56 ;
V_41 |= ( V_47 -> V_57 << V_58 )
& V_59 ;
F_7 ( V_19 , V_41 , V_30 , V_60 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
enum V_61 V_62 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
if ( V_62 == V_63 )
F_9 ( V_19 , V_30 , V_33 ,
V_64 ) ;
else
F_10 ( V_19 , V_30 , V_33 ,
V_64 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
const struct V_65 * V_66 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
const T_1 * V_67 , * V_68 ;
T_2 V_41 ;
V_41 = F_13 ( V_19 , V_30 , V_33 ) &
~ ( V_69 | V_70 ) ;
V_41 |= ( ( V_66 -> V_71 - 1 ) << V_72 )
& V_69 ;
V_41 |= ( ( V_66 -> V_73 - 1 ) << V_74 )
& V_70 ;
F_7 ( V_19 , V_41 , V_30 , V_33 ) ;
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
struct V_18 * V_19 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_81 << V_83 )
& V_84 ;
V_41 |= ( V_82 << V_85 )
& V_86 ;
F_7 ( V_19 , V_41 , V_30 , V_87 ) ;
}
static void F_18 ( struct V_2 * V_3 , T_2 V_88 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
F_7 ( V_19 , V_88 , V_30 , V_89 ) ;
}
static void F_19 ( struct V_2 * V_3 , T_2 V_90 , T_2 V_91 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_90 << V_92 )
& V_93 ;
V_41 |= ( V_91 << V_94 )
& V_95 ;
F_7 ( V_19 , V_41 , V_30 , V_96 ) ;
}
static void F_20 ( struct V_2 * V_3 ,
T_2 V_81 , T_2 V_82 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
T_2 V_41 ;
V_41 = ( V_81 << V_97 )
& V_98 ;
V_41 |= ( V_82 << V_99 )
& V_100 ;
F_7 ( V_19 , V_41 , V_30 , V_101 ) ;
}
static void F_21 ( struct V_2 * V_3 , T_2 V_88 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
F_7 ( V_19 , V_88 , V_30 , V_102 ) ;
}
static void F_22 ( struct V_2 * V_3 ,
enum V_103 type )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
if ( type == V_104 )
F_9 ( V_19 , V_30 , V_33 ,
V_105 ) ;
else
F_10 ( V_19 , V_30 , V_33 ,
V_105 ) ;
}
static void F_23 ( struct V_2 * V_3 , T_2 V_106 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
F_7 ( V_19 , V_106 , V_30 , V_107 ) ;
}
void F_24 ( struct V_2 * V_3 ,
unsigned int * V_108 )
{
struct V_109 * V_110 = F_25 ( & V_3 -> V_10 . V_111 ) ;
const struct V_1 * V_112 = & V_3 -> V_11 [ V_113 ] ;
unsigned long V_114 = F_26 ( V_110 -> V_115 , 200000000UL ) ;
unsigned long clock ;
clock = F_27 ( ( V_116 ) V_114 * V_3 -> V_14 . V_117 . V_82 , V_112 -> V_82 ) ;
clock = F_26 ( clock , V_114 / 2 ) ;
* V_108 = F_27 ( ( V_116 ) clock * V_3 -> V_14 . V_117 . V_81 , V_112 -> V_81 ) ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_109 * V_110 = F_25 ( & V_3 -> V_10 . V_111 ) ;
struct V_18 * V_19 = F_6 ( V_3 ) ;
unsigned long V_115 = V_110 -> V_115 ;
struct V_118 * V_119 ;
unsigned int V_120 ;
unsigned int V_121 ;
unsigned int V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_125 ;
unsigned int V_126 ;
if ( V_3 -> V_127 != V_63 ) {
F_10 ( V_19 , V_128 , V_129 ,
V_130 ) ;
return;
}
switch ( V_19 -> V_131 ) {
case V_132 :
case V_133 :
default:
V_123 = 1024 ;
break;
case V_134 :
V_123 = 32 ;
break;
}
V_122 = F_27 ( ( V_116 ) V_115 / 2 * 256 + V_110 -> V_108 - 1 ,
V_110 -> V_108 ) ;
V_124 = F_29 ( V_122 , V_123 ) ;
V_119 = & V_110 -> V_135 ;
V_121 = F_29 ( V_3 -> V_14 . V_117 . V_81 * 2 , 256 )
* V_3 -> V_14 . V_117 . V_82 ;
V_120 = F_27 ( ( V_116 ) V_115 * V_119 -> V_136 ,
V_119 -> V_137 ) ;
V_122 = V_120 / V_121 ;
V_125 = V_122 / V_123 ;
V_126 = F_30 ( V_124 , V_125 ) ;
F_31 ( V_19 -> V_138 , L_1 , V_139 , V_126 ) ;
F_32 ( V_19 , V_128 , V_129 ,
V_130 ,
V_126 << V_140 ) ;
}
int F_33 ( struct V_2 * V_3 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
return F_13 ( V_19 , V_30 , V_141 ) &
V_142 ;
}
static void F_34 ( struct V_2 * V_3 , T_2 V_106 )
{
V_3 -> V_143 = V_106 ;
if ( V_3 -> V_144 )
V_106 += V_3 -> V_144 & ~ 0x1f ;
F_23 ( V_3 , V_106 ) ;
}
static void F_35 ( struct V_2 * V_3 , T_2 V_106 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
F_7 ( V_19 , V_106 << V_145 ,
V_30 , V_146 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
F_31 ( V_19 -> V_138 , L_2 ) ;
F_37 ( V_19 , V_147 ) ;
F_37 ( V_19 , V_148 ) ;
F_37 ( V_19 , V_149 ) ;
F_37 ( V_19 , V_150 ) ;
F_37 ( V_19 , V_151 ) ;
F_37 ( V_19 , V_152 ) ;
F_37 ( V_19 , V_153 ) ;
F_37 ( V_19 , V_154 ) ;
F_37 ( V_19 , V_155 ) ;
F_37 ( V_19 , V_156 ) ;
F_31 ( V_19 -> V_138 , L_3 ) ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_12 * V_127 ,
struct V_1 * V_157 ,
struct V_65 * V_66 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
const unsigned int V_158 = V_159 ;
const unsigned int V_160 = V_159 ;
unsigned int V_161 ;
unsigned int V_162 ;
unsigned int V_163 ;
unsigned int V_164 ;
unsigned int V_165 ;
unsigned int V_166 ;
unsigned int V_167 ;
unsigned int V_81 ;
unsigned int V_82 ;
V_164 = ( ( V_127 -> V_82 - 7 ) * 256 - 32 - 64 * V_158 ) / 1024 + 1 ;
V_164 = F_39 (unsigned int, min_height, MIN_OUT_HEIGHT) ;
V_166 = ( ( V_127 -> V_82 - 4 ) * 256 + 255 - 16 - 32 * V_158 ) / 64 + 1 ;
V_166 = F_40 (unsigned int, max_height, MAX_OUT_HEIGHT) ;
V_157 -> V_82 = F_41 ( V_157 -> V_82 , V_164 , V_166 ) ;
V_66 -> V_73 = ( ( V_127 -> V_82 - 4 ) * 256 + 255 - 16 - 32 * V_158 )
/ ( V_157 -> V_82 - 1 ) ;
if ( V_66 -> V_73 > V_75 )
V_66 -> V_73 = ( ( V_127 -> V_82 - 7 ) * 256 + 255 - 32 - 64 * V_158 )
/ ( V_157 -> V_82 - 1 ) ;
V_66 -> V_73 = F_42 (unsigned int, ratio->vert,
MIN_RESIZE_VALUE, MAX_RESIZE_VALUE) ;
if ( V_66 -> V_73 <= V_75 ) {
V_162 = ( V_157 -> V_82 - 1 ) * V_66 -> V_73
+ 32 * V_158 + 16 ;
V_82 = ( V_162 >> 8 ) + 4 ;
} else {
V_162 = ( V_157 -> V_82 - 1 ) * V_66 -> V_73
+ 64 * V_158 + 32 ;
V_82 = ( V_162 >> 8 ) + 7 ;
}
V_163 = ( ( V_127 -> V_81 - 7 ) * 256 - 32 - 64 * V_160 ) / 1024 + 1 ;
V_163 = F_39 (unsigned int, min_width, MIN_OUT_WIDTH) ;
if ( V_66 -> V_73 <= V_75 ) {
switch ( V_19 -> V_131 ) {
case V_132 :
V_165 = V_168 ;
break;
case V_133 :
default:
V_165 = V_169 ;
break;
case V_134 :
V_165 = V_170 ;
break;
}
} else {
switch ( V_19 -> V_131 ) {
case V_132 :
V_165 = V_171 ;
break;
case V_133 :
default:
V_165 = V_172 ;
break;
case V_134 :
V_165 = V_173 ;
break;
}
}
V_165 = F_26 ( ( ( V_127 -> V_81 - 7 ) * 256 + 255 - 16 - 32 * V_160 ) / 64
+ 1 , V_165 ) ;
V_167 = V_66 -> V_73 < 256 ? 8 : 2 ;
V_157 -> V_81 = F_41 ( V_157 -> V_81 , V_163 ,
V_165 & ~ ( V_167 - 1 ) ) ;
V_157 -> V_81 = F_43 ( V_157 -> V_81 , V_167 ) ;
V_66 -> V_71 = ( ( V_127 -> V_81 - 7 ) * 256 + 255 - 16 - 32 * V_160 )
/ ( V_157 -> V_81 - 1 ) ;
if ( V_66 -> V_71 > V_75 )
V_66 -> V_71 = ( ( V_127 -> V_81 - 7 ) * 256 + 255 - 32 - 64 * V_160 )
/ ( V_157 -> V_81 - 1 ) ;
V_66 -> V_71 = F_42 (unsigned int, ratio->horz,
MIN_RESIZE_VALUE, MAX_RESIZE_VALUE) ;
if ( V_66 -> V_71 <= V_75 ) {
V_161 = ( V_157 -> V_81 - 1 ) * V_66 -> V_71
+ 32 * V_160 + 16 ;
V_81 = ( V_161 >> 8 ) + 7 ;
} else {
V_161 = ( V_157 -> V_81 - 1 ) * V_66 -> V_71
+ 64 * V_160 + 32 ;
V_81 = ( V_161 >> 8 ) + 7 ;
}
V_127 -> V_90 += ( V_127 -> V_81 - V_81 ) / 2 ;
V_127 -> V_91 += ( V_127 -> V_82 - V_82 ) / 2 ;
V_127 -> V_81 = V_81 ;
V_127 -> V_82 = V_82 ;
}
static void F_44 ( struct V_2 * V_3 ,
const struct V_1 * V_127 ,
const struct V_1 * V_157 )
{
F_16 ( V_3 , & V_3 -> V_66 ) ;
if ( V_3 -> V_66 . V_71 >= V_174 )
F_8 ( V_3 , V_175 ) ;
else
F_8 ( V_3 , V_32 ) ;
F_28 ( V_3 ) ;
if ( V_3 -> V_127 == V_63 ) {
V_3 -> V_144 = ( V_3 -> V_14 . V_117 . V_91 * V_127 -> V_81 +
V_3 -> V_14 . V_117 . V_90 ) * 2 ;
F_19 ( V_3 , ( V_3 -> V_144 / 2 ) & 0xf , 0 ) ;
F_23 ( V_3 ,
V_3 -> V_143 + ( V_3 -> V_144 & ~ 0x1f ) ) ;
} else {
F_19 ( V_3 , V_3 -> V_14 . V_117 . V_90 * 2 ,
V_3 -> V_14 . V_117 . V_91 ) ;
F_23 ( V_3 , 0 ) ;
F_21 ( V_3 , 0 ) ;
}
F_20 ( V_3 , V_3 -> V_14 . V_117 . V_81 ,
V_3 -> V_14 . V_117 . V_82 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_176 , * V_177 ;
struct V_46 V_47 = { 0 , 0 , 0 , 0 } ;
F_15 ( V_3 , V_3 -> V_127 ) ;
V_176 = & V_3 -> V_11 [ V_13 ] ;
V_177 = & V_3 -> V_11 [ V_113 ] ;
if ( V_3 -> V_127 == V_178 )
F_21 ( V_3 , 0 ) ;
else
F_21 ( V_3 , F_43 ( V_176 -> V_81 , 0x10 ) * 2 ) ;
F_22 ( V_3 , V_179 ) ;
F_11 ( V_3 , V_176 -> V_180 ) ;
F_12 ( V_3 , V_159 , V_159 ) ;
F_14 ( V_3 , & V_47 ) ;
F_18 ( V_3 , F_43 ( V_177 -> V_81 * 2 , 32 ) ) ;
F_17 ( V_3 , V_177 -> V_81 , V_177 -> V_82 ) ;
F_44 ( V_3 , V_176 , V_177 ) ;
}
static void F_46 ( struct V_2 * V_3 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
F_9 ( V_19 , V_30 , V_141 ,
V_181 | V_182 ) ;
}
void F_47 ( struct V_2 * V_3 )
{
if ( V_3 -> V_183 == V_184 &&
V_3 -> V_185 . V_186 & V_187 ) {
F_46 ( V_3 ) ;
F_48 ( & V_3 -> V_185 ) ;
}
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_109 * V_110 = F_25 ( & V_3 -> V_10 . V_111 ) ;
struct V_188 * V_189 ;
int V_190 = 0 ;
if ( V_3 -> V_183 == V_191 )
return;
V_189 = F_50 ( & V_3 -> V_185 ) ;
if ( V_189 != NULL ) {
F_35 ( V_3 , V_189 -> V_192 ) ;
V_190 = 1 ;
}
V_110 -> V_183 |= V_193 ;
if ( V_3 -> V_127 == V_63 ) {
V_189 = F_50 ( & V_3 -> V_194 ) ;
if ( V_189 != NULL )
F_34 ( V_3 , V_189 -> V_192 ) ;
V_110 -> V_183 |= V_195 ;
}
if ( V_3 -> V_183 == V_196 ) {
if ( F_51 ( V_110 ) )
F_52 ( V_110 ,
V_196 ) ;
} else {
if ( V_190 )
F_46 ( V_3 ) ;
}
}
void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_176 , * V_177 ;
unsigned long V_197 ;
if ( F_54 ( & V_3 -> V_198 , & V_3 -> V_199 ) )
return;
F_55 ( & V_3 -> V_200 , V_197 ) ;
if ( V_3 -> V_201 ) {
V_177 = F_1 ( V_3 , NULL , V_113 ,
V_202 ) ;
V_176 = F_1 ( V_3 , NULL , V_13 ,
V_202 ) ;
F_44 ( V_3 , V_176 , V_177 ) ;
V_3 -> V_201 = 0 ;
}
F_56 ( & V_3 -> V_200 , V_197 ) ;
F_49 ( V_3 ) ;
}
static int F_57 ( struct V_203 * V_204 ,
struct V_188 * V_189 )
{
struct V_2 * V_3 = & V_204 -> V_19 -> V_205 ;
if ( V_204 -> type == V_206 )
F_34 ( V_3 , V_189 -> V_192 ) ;
if ( V_204 -> type == V_207 )
F_35 ( V_3 , V_189 -> V_192 ) ;
return 0 ;
}
static int F_58 ( struct V_208 * V_209 , int V_210 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_203 * V_185 = & V_3 -> V_185 ;
struct V_18 * V_19 = F_6 ( V_3 ) ;
struct V_211 * V_138 = F_60 ( V_3 ) ;
if ( V_3 -> V_183 == V_191 ) {
if ( V_210 == V_191 )
return 0 ;
F_61 ( V_19 , V_212 ) ;
F_45 ( V_3 ) ;
F_36 ( V_3 ) ;
}
switch ( V_210 ) {
case V_184 :
F_62 ( V_19 , V_213 ) ;
if ( V_185 -> V_186 & V_187 ) {
F_46 ( V_3 ) ;
F_48 ( V_185 ) ;
}
break;
case V_196 :
if ( V_3 -> V_127 == V_63 )
F_62 ( V_19 , V_214 ) ;
F_62 ( V_19 , V_213 ) ;
F_46 ( V_3 ) ;
break;
case V_191 :
if ( F_63 ( & V_209 -> V_111 , & V_3 -> V_198 ,
& V_3 -> V_199 ) )
F_31 ( V_138 , L_4 , V_209 -> V_215 ) ;
F_64 ( V_19 , V_214 |
V_213 ) ;
F_65 ( V_19 , V_212 ) ;
F_48 ( V_185 ) ;
break;
}
V_3 -> V_183 = V_210 ;
return 0 ;
}
static void F_66 ( const struct V_1 * V_216 ,
const struct V_1 * V_62 ,
struct V_12 * V_14 )
{
const unsigned int V_158 = V_159 ;
const unsigned int V_160 = V_159 ;
unsigned int V_163 =
( ( 32 * V_160 + ( V_62 -> V_81 - 1 ) * 64 + 16 ) >> 8 ) + 7 ;
unsigned int V_164 =
( ( 32 * V_158 + ( V_62 -> V_82 - 1 ) * 64 + 16 ) >> 8 ) + 4 ;
unsigned int V_165 =
( ( 64 * V_160 + ( V_62 -> V_81 - 1 ) * 1024 + 32 ) >> 8 ) + 7 ;
unsigned int V_166 =
( ( 64 * V_158 + ( V_62 -> V_82 - 1 ) * 1024 + 32 ) >> 8 ) + 7 ;
V_14 -> V_81 = F_42 ( T_2 , V_14 -> V_81 , V_163 , V_165 ) ;
V_14 -> V_82 = F_42 ( T_2 , V_14 -> V_82 , V_164 , V_166 ) ;
V_14 -> V_90 = F_42 ( T_2 , V_14 -> V_90 , 0 , V_216 -> V_81 - V_217 ) ;
V_14 -> V_81 = F_42 ( T_2 , V_14 -> V_81 , V_217 ,
V_216 -> V_81 - V_14 -> V_90 ) ;
V_14 -> V_91 = F_42 ( T_2 , V_14 -> V_91 , 0 , V_216 -> V_82 - V_218 ) ;
V_14 -> V_82 = F_42 ( T_2 , V_14 -> V_82 , V_218 ,
V_216 -> V_82 - V_14 -> V_91 ) ;
}
static int F_67 ( struct V_208 * V_209 ,
struct V_4 * V_5 ,
struct V_219 * V_220 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_1 * V_221 ;
struct V_1 * V_222 ;
struct V_65 V_66 ;
if ( V_220 -> V_6 != V_13 )
return - V_223 ;
V_222 = F_1 ( V_3 , V_5 , V_13 ,
V_220 -> V_8 ) ;
V_221 = F_1 ( V_3 , V_5 , V_113 ,
V_220 -> V_8 ) ;
switch ( V_220 -> V_224 ) {
case V_225 :
V_220 -> V_226 . V_90 = 0 ;
V_220 -> V_226 . V_91 = 0 ;
V_220 -> V_226 . V_81 = V_227 ;
V_220 -> V_226 . V_82 = V_227 ;
F_66 ( V_222 , V_221 , & V_220 -> V_226 ) ;
F_38 ( V_3 , & V_220 -> V_226 , V_221 , & V_66 ) ;
break;
case V_228 :
V_220 -> V_226 = * F_3 ( V_3 , V_5 , V_220 -> V_8 ) ;
F_38 ( V_3 , & V_220 -> V_226 , V_221 , & V_66 ) ;
break;
default:
return - V_223 ;
}
return 0 ;
}
static int F_68 ( struct V_208 * V_209 ,
struct V_4 * V_5 ,
struct V_219 * V_220 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_18 * V_19 = F_6 ( V_3 ) ;
const struct V_1 * V_222 ;
struct V_1 V_221 ;
struct V_65 V_66 ;
unsigned long V_197 ;
if ( V_220 -> V_224 != V_228 ||
V_220 -> V_6 != V_13 )
return - V_223 ;
V_222 = F_1 ( V_3 , V_5 , V_13 ,
V_220 -> V_8 ) ;
V_221 = * F_1 ( V_3 , V_5 , V_113 ,
V_220 -> V_8 ) ;
F_31 ( V_19 -> V_138 , L_5 ,
V_139 , V_220 -> V_8 == V_9 ? L_6 : L_7 ,
V_222 -> V_81 , V_222 -> V_82 ,
V_220 -> V_226 . V_90 , V_220 -> V_226 . V_91 , V_220 -> V_226 . V_81 , V_220 -> V_226 . V_82 ,
V_221 . V_81 , V_221 . V_82 ) ;
F_66 ( V_222 , & V_221 , & V_220 -> V_226 ) ;
* F_3 ( V_3 , V_5 , V_220 -> V_8 ) = V_220 -> V_226 ;
F_38 ( V_3 , & V_220 -> V_226 , & V_221 , & V_66 ) ;
F_31 ( V_19 -> V_138 , L_8 ,
V_139 , V_220 -> V_8 == V_9 ? L_6 : L_7 ,
V_222 -> V_81 , V_222 -> V_82 ,
V_220 -> V_226 . V_90 , V_220 -> V_226 . V_91 , V_220 -> V_226 . V_81 , V_220 -> V_226 . V_82 ,
V_221 . V_81 , V_221 . V_82 ) ;
if ( V_220 -> V_8 == V_9 ) {
* F_1 ( V_3 , V_5 , V_113 , V_220 -> V_8 ) =
V_221 ;
return 0 ;
}
F_55 ( & V_3 -> V_200 , V_197 ) ;
* F_1 ( V_3 , V_5 , V_113 , V_220 -> V_8 ) =
V_221 ;
V_3 -> V_66 = V_66 ;
V_3 -> V_14 . V_117 = V_220 -> V_226 ;
if ( V_3 -> V_183 != V_191 )
V_3 -> V_201 = 1 ;
F_56 ( & V_3 -> V_200 , V_197 ) ;
return 0 ;
}
static unsigned int F_69 ( struct V_2 * V_3 )
{
struct V_18 * V_19 = F_6 ( V_3 ) ;
if ( V_3 -> V_127 == V_63 ) {
return V_229 ;
} else {
if ( V_19 -> V_131 == V_132 )
return V_230 ;
else
return V_231 ;
}
}
static void F_70 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned int V_6 ,
struct V_1 * V_232 ,
enum V_7 V_8 )
{
struct V_1 * V_233 ;
struct V_65 V_66 ;
struct V_12 V_14 ;
switch ( V_6 ) {
case V_13 :
if ( V_232 -> V_180 != V_36 &&
V_232 -> V_180 != V_38 )
V_232 -> V_180 = V_36 ;
V_232 -> V_81 = F_42 ( T_2 , V_232 -> V_81 , V_217 ,
F_69 ( V_3 ) ) ;
V_232 -> V_82 = F_42 ( T_2 , V_232 -> V_82 , V_218 ,
V_234 ) ;
break;
case V_113 :
V_233 = F_1 ( V_3 , V_5 , V_13 , V_8 ) ;
V_232 -> V_180 = V_233 -> V_180 ;
V_14 = * F_3 ( V_3 , V_5 , V_8 ) ;
F_38 ( V_3 , & V_14 , V_232 , & V_66 ) ;
break;
}
V_232 -> V_235 = V_236 ;
V_232 -> V_237 = V_238 ;
}
static int F_71 ( struct V_208 * V_209 ,
struct V_4 * V_5 ,
struct V_239 * V_180 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_1 * V_233 ;
if ( V_180 -> V_6 == V_13 ) {
if ( V_180 -> V_240 >= F_72 ( V_241 ) )
return - V_223 ;
V_180 -> V_180 = V_241 [ V_180 -> V_240 ] ;
} else {
if ( V_180 -> V_240 != 0 )
return - V_223 ;
V_233 = F_1 ( V_3 , V_5 , V_13 ,
V_180 -> V_8 ) ;
V_180 -> V_180 = V_233 -> V_180 ;
}
return 0 ;
}
static int F_73 ( struct V_208 * V_209 ,
struct V_4 * V_5 ,
struct V_242 * V_243 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_1 V_233 ;
if ( V_243 -> V_240 != 0 )
return - V_223 ;
V_233 . V_180 = V_243 -> V_180 ;
V_233 . V_81 = 1 ;
V_233 . V_82 = 1 ;
F_70 ( V_3 , V_5 , V_243 -> V_6 , & V_233 , V_243 -> V_8 ) ;
V_243 -> V_163 = V_233 . V_81 ;
V_243 -> V_164 = V_233 . V_82 ;
if ( V_233 . V_180 != V_243 -> V_180 )
return - V_223 ;
V_233 . V_180 = V_243 -> V_180 ;
V_233 . V_81 = - 1 ;
V_233 . V_82 = - 1 ;
F_70 ( V_3 , V_5 , V_243 -> V_6 , & V_233 , V_243 -> V_8 ) ;
V_243 -> V_165 = V_233 . V_81 ;
V_243 -> V_166 = V_233 . V_82 ;
return 0 ;
}
static int F_74 ( struct V_208 * V_209 , struct V_4 * V_5 ,
struct V_244 * V_232 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_1 * V_233 ;
V_233 = F_1 ( V_3 , V_5 , V_232 -> V_6 , V_232 -> V_8 ) ;
if ( V_233 == NULL )
return - V_223 ;
V_232 -> V_233 = * V_233 ;
return 0 ;
}
static int F_75 ( struct V_208 * V_209 , struct V_4 * V_5 ,
struct V_244 * V_232 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_1 * V_233 ;
struct V_12 * V_14 ;
V_233 = F_1 ( V_3 , V_5 , V_232 -> V_6 , V_232 -> V_8 ) ;
if ( V_233 == NULL )
return - V_223 ;
F_70 ( V_3 , V_5 , V_232 -> V_6 , & V_232 -> V_233 , V_232 -> V_8 ) ;
* V_233 = V_232 -> V_233 ;
if ( V_232 -> V_6 == V_13 ) {
V_14 = F_3 ( V_3 , V_5 , V_232 -> V_8 ) ;
V_14 -> V_90 = 0 ;
V_14 -> V_91 = 0 ;
V_14 -> V_81 = V_232 -> V_233 . V_81 ;
V_14 -> V_82 = V_232 -> V_233 . V_82 ;
V_233 = F_1 ( V_3 , V_5 , V_113 ,
V_232 -> V_8 ) ;
* V_233 = V_232 -> V_233 ;
F_70 ( V_3 , V_5 , V_113 , V_233 ,
V_232 -> V_8 ) ;
}
if ( V_232 -> V_8 == V_202 ) {
V_3 -> V_14 . V_117 = V_3 -> V_14 . V_15 ;
F_38 ( V_3 , & V_3 -> V_14 . V_117 , V_233 ,
& V_3 -> V_66 ) ;
}
return 0 ;
}
static int F_76 ( struct V_208 * V_209 ,
struct V_245 * V_246 ,
struct V_244 * V_247 ,
struct V_244 * V_248 )
{
struct V_2 * V_3 = F_59 ( V_209 ) ;
struct V_109 * V_110 = F_25 ( & V_209 -> V_111 ) ;
F_24 ( V_3 , & V_110 -> V_108 ) ;
return F_77 ( V_209 , V_246 ,
V_247 , V_248 ) ;
}
static int F_78 ( struct V_208 * V_209 ,
struct V_249 * V_250 )
{
struct V_244 V_233 ;
memset ( & V_233 , 0 , sizeof( V_233 ) ) ;
V_233 . V_6 = V_13 ;
V_233 . V_8 = V_250 ? V_9 : V_202 ;
V_233 . V_233 . V_180 = V_36 ;
V_233 . V_233 . V_81 = 4096 ;
V_233 . V_233 . V_82 = 4096 ;
F_75 ( V_209 , V_250 ? V_250 -> V_6 : NULL , & V_233 ) ;
return 0 ;
}
static int F_79 ( struct V_251 * V_111 ,
const struct V_252 * V_253 ,
const struct V_252 * V_254 , T_2 V_197 )
{
struct V_208 * V_209 = F_80 ( V_111 ) ;
struct V_2 * V_3 = F_59 ( V_209 ) ;
unsigned int V_240 = V_253 -> V_240 ;
if ( F_81 ( V_254 -> V_111 ) )
V_240 |= 2 << 16 ;
switch ( V_240 ) {
case V_13 :
if ( V_197 & V_255 ) {
if ( V_3 -> V_127 == V_178 )
return - V_256 ;
V_3 -> V_127 = V_63 ;
} else {
if ( V_3 -> V_127 == V_63 )
V_3 -> V_127 = V_257 ;
}
break;
case V_13 | 2 << 16 :
if ( V_197 & V_255 ) {
if ( V_3 -> V_127 == V_63 )
return - V_256 ;
V_3 -> V_127 = V_178 ;
} else {
if ( V_3 -> V_127 == V_178 )
V_3 -> V_127 = V_257 ;
}
break;
case V_113 :
break;
default:
return - V_223 ;
}
return 0 ;
}
void F_82 ( struct V_2 * V_3 )
{
F_83 ( & V_3 -> V_10 ) ;
F_84 ( & V_3 -> V_194 ) ;
F_84 ( & V_3 -> V_185 ) ;
}
int F_85 ( struct V_2 * V_3 ,
struct V_258 * V_259 )
{
int V_260 ;
V_260 = F_86 ( V_259 , & V_3 -> V_10 ) ;
if ( V_260 < 0 )
goto error;
V_260 = F_87 ( & V_3 -> V_194 , V_259 ) ;
if ( V_260 < 0 )
goto error;
V_260 = F_87 ( & V_3 -> V_185 , V_259 ) ;
if ( V_260 < 0 )
goto error;
return 0 ;
error:
F_82 ( V_3 ) ;
return V_260 ;
}
static int F_88 ( struct V_2 * V_3 )
{
struct V_208 * V_209 = & V_3 -> V_10 ;
struct V_252 * V_261 = V_3 -> V_261 ;
struct V_251 * V_262 = & V_209 -> V_111 ;
int V_260 ;
V_3 -> V_127 = V_257 ;
F_89 ( V_209 , & V_263 ) ;
V_209 -> V_264 = & V_265 ;
F_90 ( V_209 -> V_215 , L_9 , sizeof( V_209 -> V_215 ) ) ;
V_209 -> V_266 = 1 << 16 ;
F_91 ( V_209 , V_3 ) ;
V_209 -> V_197 |= V_267 ;
V_261 [ V_13 ] . V_197 = V_268
| V_269 ;
V_261 [ V_113 ] . V_197 = V_270 ;
V_262 -> V_271 = & V_272 ;
V_260 = F_92 ( V_262 , V_273 , V_261 ) ;
if ( V_260 < 0 )
return V_260 ;
F_78 ( V_209 , NULL ) ;
V_3 -> V_194 . type = V_206 ;
V_3 -> V_194 . V_271 = & V_274 ;
V_3 -> V_194 . V_19 = F_6 ( V_3 ) ;
V_3 -> V_194 . V_275 = F_93 ( 4096 * 4096 ) * 2 * 3 ;
V_3 -> V_194 . V_276 = 32 ;
V_3 -> V_185 . type = V_207 ;
V_3 -> V_185 . V_271 = & V_274 ;
V_3 -> V_185 . V_19 = F_6 ( V_3 ) ;
V_3 -> V_185 . V_275 = F_93 ( 4096 * 4096 ) * 2 * 3 ;
V_3 -> V_185 . V_276 = 32 ;
V_260 = F_94 ( & V_3 -> V_194 , L_10 ) ;
if ( V_260 < 0 )
goto V_277;
V_260 = F_94 ( & V_3 -> V_185 , L_10 ) ;
if ( V_260 < 0 )
goto V_278;
V_3 -> V_185 . V_204 . V_111 . V_197 |= V_279 ;
return 0 ;
V_278:
F_95 ( & V_3 -> V_194 ) ;
V_277:
F_96 ( & V_3 -> V_10 . V_111 ) ;
return V_260 ;
}
int F_97 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = & V_19 -> V_205 ;
F_98 ( & V_3 -> V_198 ) ;
F_99 ( & V_3 -> V_199 , 0 ) ;
F_100 ( & V_3 -> V_200 ) ;
return F_88 ( V_3 ) ;
}
void F_101 ( struct V_18 * V_19 )
{
struct V_2 * V_3 = & V_19 -> V_205 ;
F_95 ( & V_3 -> V_194 ) ;
F_95 ( & V_3 -> V_185 ) ;
F_96 ( & V_3 -> V_10 . V_111 ) ;
}
