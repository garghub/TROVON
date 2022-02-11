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
T_2 V_41 = 0 ;
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
T_2 V_41 = 0 ;
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
T_2 V_41 = 0 ;
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
T_2 V_41 = 0 ;
F_18 ( V_18 -> V_83 , L_1 , V_81 , V_82 ) ;
V_41 = ( V_81 << V_84 )
& V_85 ;
V_41 |= ( V_82 << V_86 )
& V_87 ;
F_7 ( V_18 , V_41 , V_29 , V_88 ) ;
}
static void F_19 ( struct V_2 * V_3 , T_2 V_89 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_89 , V_29 , V_90 ) ;
}
static void F_20 ( struct V_2 * V_3 , T_2 V_91 , T_2 V_92 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_41 = 0 ;
V_41 = ( V_91 << V_93 )
& V_94 ;
V_41 |= ( V_92 << V_95 )
& V_96 ;
F_7 ( V_18 , V_41 , V_29 , V_97 ) ;
}
static void F_21 ( struct V_2 * V_3 ,
T_2 V_81 , T_2 V_82 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
T_2 V_41 = 0 ;
F_18 ( V_18 -> V_83 , L_2 , V_81 , V_82 ) ;
V_41 = ( V_81 << V_98 )
& V_99 ;
V_41 |= ( V_82 << V_100 )
& V_101 ;
F_7 ( V_18 , V_41 , V_29 , V_102 ) ;
}
static void F_22 ( struct V_2 * V_3 , T_2 V_89 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_89 , V_29 , V_103 ) ;
}
static void F_23 ( struct V_2 * V_3 ,
enum V_104 type )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
if ( type == V_105 )
F_9 ( V_18 , V_29 , V_32 ,
V_106 ) ;
else
F_10 ( V_18 , V_29 , V_32 ,
V_106 ) ;
}
static void F_24 ( struct V_2 * V_3 , T_2 V_107 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_107 , V_29 , V_108 ) ;
}
void F_25 ( struct V_2 * V_3 ,
unsigned int * V_109 )
{
struct V_110 * V_111 = F_26 ( & V_3 -> V_112 . V_113 ) ;
const struct V_1 * V_114 = & V_3 -> V_10 [ V_115 ] ;
unsigned long V_116 = F_27 ( V_111 -> V_117 , 200000000UL ) ;
unsigned long clock ;
clock = F_28 ( ( V_118 ) V_116 * V_3 -> V_13 . V_119 . V_82 , V_114 -> V_82 ) ;
clock = F_27 ( clock , V_116 / 2 ) ;
* V_109 = F_28 ( ( V_118 ) clock * V_3 -> V_13 . V_119 . V_81 , V_114 -> V_81 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_110 * V_111 = F_26 ( & V_3 -> V_112 . V_113 ) ;
struct V_17 * V_18 = F_6 ( V_3 ) ;
unsigned long V_117 = V_111 -> V_117 ;
struct V_120 * V_121 ;
unsigned int V_122 ;
unsigned int V_123 ;
unsigned int V_124 ;
unsigned int V_125 ;
unsigned int V_126 ;
unsigned int V_127 ;
unsigned int V_128 ;
if ( V_3 -> V_129 != V_63 ) {
F_10 ( V_18 , V_130 , V_131 ,
V_132 ) ;
return;
}
switch ( V_18 -> V_133 ) {
case V_134 :
case V_135 :
default:
V_125 = 1024 ;
break;
case V_136 :
V_125 = 32 ;
break;
}
V_124 = F_28 ( ( V_118 ) V_117 / 2 * 256 + V_111 -> V_109 - 1 ,
V_111 -> V_109 ) ;
V_126 = F_30 ( V_124 , V_125 ) ;
V_121 = & V_111 -> V_137 ;
V_123 = F_30 ( V_3 -> V_13 . V_119 . V_81 * 2 , 256 )
* V_3 -> V_13 . V_119 . V_82 ;
V_122 = F_28 ( ( V_118 ) V_117 * V_121 -> V_138 ,
V_121 -> V_139 ) ;
V_124 = V_122 / V_123 ;
V_127 = V_124 / V_125 ;
V_128 = F_31 ( V_126 , V_127 ) ;
F_18 ( V_18 -> V_83 , L_3 , V_140 , V_128 ) ;
F_32 ( V_18 , V_130 , V_131 ,
V_132 ,
V_128 << V_141 ) ;
}
int F_33 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
return F_13 ( V_18 , V_29 , V_142 ) &
V_143 ;
}
static void F_34 ( struct V_2 * V_3 , T_2 V_107 )
{
V_3 -> V_144 = V_107 ;
if ( V_3 -> V_145 )
V_107 += V_3 -> V_145 & ~ 0x1f ;
F_24 ( V_3 , V_107 ) ;
}
static void F_35 ( struct V_2 * V_3 , T_2 V_107 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_7 ( V_18 , V_107 << V_146 ,
V_29 , V_147 ) ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
F_18 ( V_18 -> V_83 , L_4 ) ;
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
F_18 ( V_18 -> V_83 , L_5 ) ;
}
static void F_38 ( struct V_2 * V_3 ,
struct V_11 * V_129 ,
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
V_165 = ( ( V_129 -> V_82 - 7 ) * 256 - 32 - 64 * V_159 ) / 1024 + 1 ;
V_165 = F_39 (unsigned int, min_height, MIN_OUT_HEIGHT) ;
V_167 = ( ( V_129 -> V_82 - 4 ) * 256 + 255 - 16 - 32 * V_159 ) / 64 + 1 ;
V_167 = F_40 (unsigned int, max_height, MAX_OUT_HEIGHT) ;
V_158 -> V_82 = F_41 ( V_158 -> V_82 , V_165 , V_167 ) ;
V_66 -> V_73 = ( ( V_129 -> V_82 - 4 ) * 256 + 255 - 16 - 32 * V_159 )
/ ( V_158 -> V_82 - 1 ) ;
if ( V_66 -> V_73 > V_75 )
V_66 -> V_73 = ( ( V_129 -> V_82 - 7 ) * 256 + 255 - 32 - 64 * V_159 )
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
V_164 = ( ( V_129 -> V_81 - 7 ) * 256 - 32 - 64 * V_161 ) / 1024 + 1 ;
V_164 = F_39 (unsigned int, min_width, MIN_OUT_WIDTH) ;
if ( V_66 -> V_73 <= V_75 ) {
switch ( V_18 -> V_133 ) {
case V_134 :
V_166 = V_169 ;
break;
case V_135 :
default:
V_166 = V_170 ;
break;
case V_136 :
V_166 = V_171 ;
break;
}
} else {
switch ( V_18 -> V_133 ) {
case V_134 :
V_166 = V_172 ;
break;
case V_135 :
default:
V_166 = V_173 ;
break;
case V_136 :
V_166 = V_174 ;
break;
}
}
V_166 = F_27 ( ( ( V_129 -> V_81 - 7 ) * 256 + 255 - 16 - 32 * V_161 ) / 64
+ 1 , V_166 ) ;
V_168 = V_66 -> V_73 < 256 ? 8 : 2 ;
V_158 -> V_81 = F_41 ( V_158 -> V_81 , V_164 ,
V_166 & ~ ( V_168 - 1 ) ) ;
V_158 -> V_81 = F_43 ( V_158 -> V_81 , V_168 ) ;
V_66 -> V_71 = ( ( V_129 -> V_81 - 7 ) * 256 + 255 - 16 - 32 * V_161 )
/ ( V_158 -> V_81 - 1 ) ;
if ( V_66 -> V_71 > V_75 )
V_66 -> V_71 = ( ( V_129 -> V_81 - 7 ) * 256 + 255 - 32 - 64 * V_161 )
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
V_129 -> V_91 += ( V_129 -> V_81 - V_81 ) / 2 ;
V_129 -> V_92 += ( V_129 -> V_82 - V_82 ) / 2 ;
V_129 -> V_81 = V_81 ;
V_129 -> V_82 = V_82 ;
}
static void F_44 ( struct V_2 * V_3 ,
const struct V_1 * V_129 ,
const struct V_1 * V_158 )
{
F_16 ( V_3 , & V_3 -> V_66 ) ;
if ( V_3 -> V_66 . V_71 >= V_175 )
F_8 ( V_3 , V_176 ) ;
else
F_8 ( V_3 , V_31 ) ;
F_29 ( V_3 ) ;
if ( V_3 -> V_129 == V_63 ) {
V_3 -> V_145 = ( V_3 -> V_13 . V_119 . V_92 * V_129 -> V_81 +
V_3 -> V_13 . V_119 . V_91 ) * 2 ;
F_20 ( V_3 , ( V_3 -> V_145 / 2 ) & 0xf , 0 ) ;
F_24 ( V_3 ,
V_3 -> V_144 + ( V_3 -> V_145 & ~ 0x1f ) ) ;
} else {
F_20 ( V_3 , V_3 -> V_13 . V_119 . V_91 * 2 ,
V_3 -> V_13 . V_119 . V_92 ) ;
F_24 ( V_3 , 0 ) ;
F_22 ( V_3 , 0 ) ;
}
F_21 ( V_3 , V_3 -> V_13 . V_119 . V_81 ,
V_3 -> V_13 . V_119 . V_82 ) ;
}
static void F_45 ( struct V_2 * V_3 )
{
struct V_1 * V_177 , * V_178 ;
struct V_46 V_47 = { 0 , 0 , 0 , 0 } ;
F_15 ( V_3 , V_3 -> V_129 ) ;
V_177 = & V_3 -> V_10 [ V_12 ] ;
V_178 = & V_3 -> V_10 [ V_115 ] ;
if ( V_3 -> V_129 == V_179 )
F_22 ( V_3 , 0 ) ;
else
F_22 ( V_3 , F_43 ( V_177 -> V_81 , 0x10 ) * 2 ) ;
F_23 ( V_3 , V_180 ) ;
F_11 ( V_3 , V_177 -> V_181 ) ;
F_12 ( V_3 , V_160 , V_160 ) ;
F_14 ( V_3 , & V_47 ) ;
F_19 ( V_3 , F_43 ( V_178 -> V_81 * 2 , 32 ) ) ;
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
struct V_110 * V_111 = F_26 ( & V_3 -> V_112 . V_113 ) ;
struct V_189 * V_190 ;
int V_191 = 0 ;
if ( V_3 -> V_184 == V_192 )
return;
V_190 = F_50 ( & V_3 -> V_186 , V_3 -> error ) ;
if ( V_190 != NULL ) {
F_35 ( V_3 , V_190 -> V_193 ) ;
V_191 = 1 ;
}
V_111 -> V_184 |= V_194 ;
if ( V_3 -> V_129 == V_63 ) {
V_190 = F_50 ( & V_3 -> V_195 , 0 ) ;
if ( V_190 != NULL )
F_34 ( V_3 , V_190 -> V_193 ) ;
V_111 -> V_184 |= V_196 ;
}
if ( V_3 -> V_184 == V_197 ) {
if ( F_51 ( V_111 ) )
F_52 ( V_111 ,
V_197 ) ;
} else {
if ( V_191 )
F_46 ( V_3 ) ;
}
V_3 -> error = 0 ;
}
void F_53 ( struct V_2 * V_3 )
{
struct V_1 * V_177 , * V_178 ;
if ( F_54 ( & V_3 -> V_198 , & V_3 -> V_199 ) )
return;
if ( V_3 -> V_200 ) {
V_178 = F_1 ( V_3 , NULL , V_115 ,
V_201 ) ;
V_177 = F_1 ( V_3 , NULL , V_12 ,
V_201 ) ;
F_44 ( V_3 , V_177 , V_178 ) ;
V_3 -> V_200 = 0 ;
}
F_49 ( V_3 ) ;
}
static int F_55 ( struct V_202 * V_203 ,
struct V_189 * V_190 )
{
struct V_2 * V_3 = & V_203 -> V_18 -> V_204 ;
if ( V_203 -> type == V_205 )
F_34 ( V_3 , V_190 -> V_193 ) ;
if ( V_203 -> type == V_206 )
F_35 ( V_3 , V_190 -> V_193 ) ;
return 0 ;
}
static int F_56 ( struct V_207 * V_208 , int V_209 )
{
struct V_2 * V_3 = F_57 ( V_208 ) ;
struct V_202 * V_186 = & V_3 -> V_186 ;
struct V_17 * V_18 = F_6 ( V_3 ) ;
struct V_210 * V_83 = F_58 ( V_3 ) ;
if ( V_3 -> V_184 == V_192 ) {
if ( V_209 == V_192 )
return 0 ;
F_59 ( V_18 , V_211 ) ;
F_45 ( V_3 ) ;
V_3 -> error = 0 ;
F_36 ( V_3 ) ;
}
switch ( V_209 ) {
case V_185 :
F_60 ( V_18 , V_212 ) ;
if ( V_186 -> V_187 & V_188 ) {
F_46 ( V_3 ) ;
F_48 ( V_186 ) ;
}
break;
case V_197 :
if ( V_3 -> V_129 == V_63 )
F_60 ( V_18 , V_213 ) ;
F_60 ( V_18 , V_212 ) ;
F_46 ( V_3 ) ;
break;
case V_192 :
if ( F_61 ( & V_208 -> V_113 , & V_3 -> V_198 ,
& V_3 -> V_199 ) )
F_18 ( V_83 , L_6 , V_208 -> V_214 ) ;
F_62 ( V_18 , V_213 |
V_212 ) ;
F_63 ( V_18 , V_211 ) ;
F_48 ( V_186 ) ;
break;
}
V_3 -> V_184 = V_209 ;
return 0 ;
}
static int F_64 ( struct V_207 * V_208 , struct V_4 * V_5 ,
struct V_215 * V_13 )
{
struct V_2 * V_3 = F_57 ( V_208 ) ;
struct V_1 * V_216 ;
struct V_65 V_66 ;
if ( V_13 -> V_6 != V_12 )
return - V_217 ;
V_216 = F_1 ( V_3 , V_5 , V_115 , V_13 -> V_8 ) ;
V_13 -> V_218 = * F_3 ( V_3 , V_5 , V_13 -> V_8 ) ;
F_38 ( V_3 , & V_13 -> V_218 , V_216 , & V_66 ) ;
return 0 ;
}
static void F_65 ( const struct V_1 * V_219 ,
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
V_13 -> V_91 = F_42 ( T_2 , V_13 -> V_91 , 0 , V_219 -> V_81 - V_220 ) ;
V_13 -> V_81 = F_42 ( T_2 , V_13 -> V_81 , V_220 ,
V_219 -> V_81 - V_13 -> V_91 ) ;
V_13 -> V_92 = F_42 ( T_2 , V_13 -> V_92 , 0 , V_219 -> V_82 - V_221 ) ;
V_13 -> V_82 = F_42 ( T_2 , V_13 -> V_82 , V_221 ,
V_219 -> V_82 - V_13 -> V_92 ) ;
}
static int F_66 ( struct V_207 * V_208 , struct V_4 * V_5 ,
struct V_215 * V_13 )
{
struct V_2 * V_3 = F_57 ( V_208 ) ;
struct V_17 * V_18 = F_6 ( V_3 ) ;
struct V_1 * V_222 , * V_223 ;
struct V_65 V_66 ;
if ( V_13 -> V_6 != V_12 )
return - V_217 ;
V_222 = F_1 ( V_3 , V_5 , V_12 ,
V_13 -> V_8 ) ;
V_223 = F_1 ( V_3 , V_5 , V_115 ,
V_13 -> V_8 ) ;
F_18 ( V_18 -> V_83 , L_7 , V_140 ,
V_13 -> V_218 . V_91 , V_13 -> V_218 . V_92 , V_13 -> V_218 . V_81 ,
V_13 -> V_218 . V_82 , V_13 -> V_8 ) ;
F_18 ( V_18 -> V_83 , L_8 , V_140 ,
V_222 -> V_81 , V_222 -> V_82 ,
V_223 -> V_81 , V_223 -> V_82 ) ;
F_65 ( V_222 , V_223 , & V_13 -> V_218 ) ;
* F_3 ( V_3 , V_5 , V_13 -> V_8 ) = V_13 -> V_218 ;
F_38 ( V_3 , & V_13 -> V_218 , V_223 , & V_66 ) ;
if ( V_13 -> V_8 == V_9 )
return 0 ;
V_3 -> V_66 = V_66 ;
V_3 -> V_13 . V_119 = V_13 -> V_218 ;
if ( V_3 -> V_184 != V_192 )
V_3 -> V_200 = 1 ;
return 0 ;
}
static unsigned int F_67 ( struct V_2 * V_3 )
{
struct V_17 * V_18 = F_6 ( V_3 ) ;
if ( V_3 -> V_129 == V_63 ) {
return V_224 ;
} else {
if ( V_18 -> V_133 == V_134 )
return V_225 ;
else
return V_226 ;
}
}
static void F_68 ( struct V_2 * V_3 ,
struct V_4 * V_5 , unsigned int V_6 ,
struct V_1 * V_227 ,
enum V_7 V_8 )
{
struct V_1 * V_216 ;
struct V_65 V_66 ;
struct V_11 V_13 ;
switch ( V_6 ) {
case V_12 :
if ( V_227 -> V_181 != V_36 &&
V_227 -> V_181 != V_38 )
V_227 -> V_181 = V_36 ;
V_227 -> V_81 = F_42 ( T_2 , V_227 -> V_81 , V_220 ,
F_67 ( V_3 ) ) ;
V_227 -> V_82 = F_42 ( T_2 , V_227 -> V_82 , V_221 ,
V_228 ) ;
break;
case V_115 :
V_216 = F_1 ( V_3 , V_5 , V_12 , V_8 ) ;
V_227 -> V_181 = V_216 -> V_181 ;
V_13 = * F_3 ( V_3 , V_5 , V_8 ) ;
F_38 ( V_3 , & V_13 , V_227 , & V_66 ) ;
break;
}
V_227 -> V_229 = V_230 ;
V_227 -> V_231 = V_232 ;
}
static int F_69 ( struct V_207 * V_208 ,
struct V_4 * V_5 ,
struct V_233 * V_181 )
{
struct V_2 * V_3 = F_57 ( V_208 ) ;
struct V_1 * V_216 ;
if ( V_181 -> V_6 == V_12 ) {
if ( V_181 -> V_234 >= F_70 ( V_235 ) )
return - V_217 ;
V_181 -> V_181 = V_235 [ V_181 -> V_234 ] ;
} else {
if ( V_181 -> V_234 != 0 )
return - V_217 ;
V_216 = F_1 ( V_3 , V_5 , V_12 ,
V_9 ) ;
V_181 -> V_181 = V_216 -> V_181 ;
}
return 0 ;
}
static int F_71 ( struct V_207 * V_208 ,
struct V_4 * V_5 ,
struct V_236 * V_237 )
{
struct V_2 * V_3 = F_57 ( V_208 ) ;
struct V_1 V_216 ;
if ( V_237 -> V_234 != 0 )
return - V_217 ;
V_216 . V_181 = V_237 -> V_181 ;
V_216 . V_81 = 1 ;
V_216 . V_82 = 1 ;
F_68 ( V_3 , V_5 , V_237 -> V_6 , & V_216 , V_9 ) ;
V_237 -> V_164 = V_216 . V_81 ;
V_237 -> V_165 = V_216 . V_82 ;
if ( V_216 . V_181 != V_237 -> V_181 )
return - V_217 ;
V_216 . V_181 = V_237 -> V_181 ;
V_216 . V_81 = - 1 ;
V_216 . V_82 = - 1 ;
F_68 ( V_3 , V_5 , V_237 -> V_6 , & V_216 , V_9 ) ;
V_237 -> V_166 = V_216 . V_81 ;
V_237 -> V_167 = V_216 . V_82 ;
return 0 ;
}
static int F_72 ( struct V_207 * V_208 , struct V_4 * V_5 ,
struct V_238 * V_227 )
{
struct V_2 * V_3 = F_57 ( V_208 ) ;
struct V_1 * V_216 ;
V_216 = F_1 ( V_3 , V_5 , V_227 -> V_6 , V_227 -> V_8 ) ;
if ( V_216 == NULL )
return - V_217 ;
V_227 -> V_216 = * V_216 ;
return 0 ;
}
static int F_73 ( struct V_207 * V_208 , struct V_4 * V_5 ,
struct V_238 * V_227 )
{
struct V_2 * V_3 = F_57 ( V_208 ) ;
struct V_1 * V_216 ;
struct V_11 * V_13 ;
V_216 = F_1 ( V_3 , V_5 , V_227 -> V_6 , V_227 -> V_8 ) ;
if ( V_216 == NULL )
return - V_217 ;
F_68 ( V_3 , V_5 , V_227 -> V_6 , & V_227 -> V_216 , V_227 -> V_8 ) ;
* V_216 = V_227 -> V_216 ;
if ( V_227 -> V_6 == V_12 ) {
V_13 = F_3 ( V_3 , V_5 , V_227 -> V_8 ) ;
V_13 -> V_91 = 0 ;
V_13 -> V_92 = 0 ;
V_13 -> V_81 = V_227 -> V_216 . V_81 ;
V_13 -> V_82 = V_227 -> V_216 . V_82 ;
V_216 = F_1 ( V_3 , V_5 , V_115 ,
V_227 -> V_8 ) ;
* V_216 = V_227 -> V_216 ;
F_68 ( V_3 , V_5 , V_115 , V_216 ,
V_227 -> V_8 ) ;
}
if ( V_227 -> V_8 == V_201 ) {
V_3 -> V_13 . V_119 = V_3 -> V_13 . V_14 ;
F_38 ( V_3 , & V_3 -> V_13 . V_119 , V_216 ,
& V_3 -> V_66 ) ;
}
return 0 ;
}
static int F_74 ( struct V_207 * V_208 ,
struct V_4 * V_5 )
{
struct V_238 V_216 ;
memset ( & V_216 , 0 , sizeof( V_216 ) ) ;
V_216 . V_6 = V_12 ;
V_216 . V_8 = V_5 ? V_9 : V_201 ;
V_216 . V_216 . V_181 = V_36 ;
V_216 . V_216 . V_81 = 4096 ;
V_216 . V_216 . V_82 = 4096 ;
F_73 ( V_208 , V_5 , & V_216 ) ;
return 0 ;
}
static int F_75 ( struct V_239 * V_113 ,
const struct V_240 * V_241 ,
const struct V_240 * V_242 , T_2 V_243 )
{
struct V_207 * V_208 = F_76 ( V_113 ) ;
struct V_2 * V_3 = F_57 ( V_208 ) ;
switch ( V_241 -> V_234 | F_77 ( V_242 -> V_113 ) ) {
case V_12 | V_244 :
if ( V_243 & V_245 ) {
if ( V_3 -> V_129 == V_179 )
return - V_246 ;
V_3 -> V_129 = V_63 ;
} else {
if ( V_3 -> V_129 == V_63 )
V_3 -> V_129 = V_247 ;
}
break;
case V_12 | V_248 :
if ( V_243 & V_245 ) {
if ( V_3 -> V_129 == V_63 )
return - V_246 ;
V_3 -> V_129 = V_179 ;
} else {
if ( V_3 -> V_129 == V_179 )
V_3 -> V_129 = V_247 ;
}
break;
case V_115 | V_244 :
break;
default:
return - V_217 ;
}
return 0 ;
}
static int F_78 ( struct V_2 * V_3 )
{
struct V_207 * V_208 = & V_3 -> V_112 ;
struct V_240 * V_249 = V_3 -> V_249 ;
struct V_239 * V_250 = & V_208 -> V_113 ;
int V_251 ;
V_3 -> V_129 = V_247 ;
F_79 ( V_208 , & V_252 ) ;
V_208 -> V_253 = & V_254 ;
F_80 ( V_208 -> V_214 , L_9 , sizeof( V_208 -> V_214 ) ) ;
V_208 -> V_255 = 1 << 16 ;
F_81 ( V_208 , V_3 ) ;
V_208 -> V_243 |= V_256 ;
V_249 [ V_12 ] . V_243 = V_257 ;
V_249 [ V_115 ] . V_243 = V_258 ;
V_250 -> V_259 = & V_260 ;
V_251 = F_82 ( V_250 , V_261 , V_249 , 0 ) ;
if ( V_251 < 0 )
return V_251 ;
F_74 ( V_208 , NULL ) ;
V_3 -> V_195 . type = V_205 ;
V_3 -> V_195 . V_259 = & V_262 ;
V_3 -> V_195 . V_18 = F_6 ( V_3 ) ;
V_3 -> V_195 . V_263 = F_83 ( 4096 * 4096 ) * 2 * 3 ;
V_3 -> V_195 . V_264 = 32 ;
V_3 -> V_186 . type = V_206 ;
V_3 -> V_186 . V_259 = & V_262 ;
V_3 -> V_186 . V_18 = F_6 ( V_3 ) ;
V_3 -> V_186 . V_263 = F_83 ( 4096 * 4096 ) * 2 * 3 ;
V_3 -> V_186 . V_264 = 32 ;
V_251 = F_84 ( & V_3 -> V_195 , L_10 ) ;
if ( V_251 < 0 )
return V_251 ;
V_251 = F_84 ( & V_3 -> V_186 , L_10 ) ;
if ( V_251 < 0 )
return V_251 ;
V_251 = F_85 ( & V_3 -> V_195 . V_203 . V_113 , 0 ,
& V_3 -> V_112 . V_113 , V_12 , 0 ) ;
if ( V_251 < 0 )
return V_251 ;
V_251 = F_85 ( & V_3 -> V_112 . V_113 , V_115 ,
& V_3 -> V_186 . V_203 . V_113 , 0 , 0 ) ;
if ( V_251 < 0 )
return V_251 ;
return 0 ;
}
void F_86 ( struct V_2 * V_3 )
{
F_87 ( & V_3 -> V_112 . V_113 ) ;
F_88 ( & V_3 -> V_112 ) ;
F_89 ( & V_3 -> V_195 ) ;
F_89 ( & V_3 -> V_186 ) ;
}
int F_90 ( struct V_2 * V_3 ,
struct V_265 * V_266 )
{
int V_251 ;
V_251 = F_91 ( V_266 , & V_3 -> V_112 ) ;
if ( V_251 < 0 )
goto error;
V_251 = F_92 ( & V_3 -> V_195 , V_266 ) ;
if ( V_251 < 0 )
goto error;
V_251 = F_92 ( & V_3 -> V_186 , V_266 ) ;
if ( V_251 < 0 )
goto error;
return 0 ;
error:
F_86 ( V_3 ) ;
return V_251 ;
}
void F_93 ( struct V_17 * V_18 )
{
}
int F_94 ( struct V_17 * V_18 )
{
struct V_2 * V_3 = & V_18 -> V_204 ;
int V_251 ;
F_95 ( & V_3 -> V_198 ) ;
F_96 ( & V_3 -> V_199 , 0 ) ;
V_251 = F_78 ( V_3 ) ;
if ( V_251 < 0 )
goto V_267;
V_267:
if ( V_251 )
F_93 ( V_18 ) ;
return V_251 ;
}
