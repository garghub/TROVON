static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , L_1 ) ;
F_4 ( V_4 , V_6 ) ;
F_4 ( V_4 , V_7 ) ;
F_4 ( V_4 , V_8 ) ;
F_4 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_10 ) ;
F_4 ( V_4 , V_11 ) ;
F_4 ( V_4 , V_12 ) ;
F_4 ( V_4 , V_13 ) ;
F_4 ( V_4 , V_14 ) ;
F_4 ( V_4 , V_15 ) ;
F_4 ( V_4 , V_16 ) ;
F_4 ( V_4 , V_17 ) ;
F_4 ( V_4 , V_18 ) ;
F_4 ( V_4 , V_19 ) ;
F_4 ( V_4 , V_20 ) ;
F_4 ( V_4 , V_21 ) ;
F_4 ( V_4 , V_22 ) ;
F_4 ( V_4 , V_23 ) ;
F_4 ( V_4 , V_24 ) ;
F_4 ( V_4 , V_25 ) ;
F_4 ( V_4 , V_26 ) ;
F_4 ( V_4 , V_27 ) ;
F_4 ( V_4 , V_28 ) ;
F_5 ( V_4 , V_29 ) ;
F_5 ( V_4 , V_30 ) ;
F_5 ( V_4 , 420 ) ;
F_5 ( V_4 , V_31 ) ;
F_5 ( V_4 , V_32 ) ;
F_5 ( V_4 , V_33 ) ;
F_5 ( V_4 , V_34 ) ;
F_5 ( V_4 , V_35 ) ;
F_5 ( V_4 , V_36 ) ;
F_5 ( V_4 , V_37 ) ;
F_5 ( V_4 , V_38 ) ;
F_5 ( V_4 , V_39 ) ;
F_5 ( V_4 , V_40 ) ;
F_5 ( V_4 , V_41 ) ;
F_5 ( V_4 , V_42 ) ;
F_5 ( V_4 , V_43 ) ;
F_5 ( V_4 , V_44 ) ;
F_5 ( V_4 , V_45 ) ;
F_5 ( V_4 , V_46 ) ;
F_5 ( V_4 , V_47 ) ;
F_5 ( V_4 , V_48 ) ;
F_5 ( V_4 , V_49 ) ;
F_5 ( V_4 , V_50 ) ;
F_5 ( V_4 , V_51 ) ;
F_5 ( V_4 , V_52 ) ;
F_5 ( V_4 , V_53 ) ;
F_5 ( V_4 , V_54 ) ;
F_5 ( V_4 , V_55 ) ;
F_5 ( V_4 , V_56 ) ;
F_5 ( V_4 , V_57 ) ;
F_5 ( V_4 , V_58 ) ;
F_3 ( V_4 -> V_5 , L_2 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_7 ( V_4 , V_60 , V_61 ,
V_62 , V_59 ? V_62 : 0 ) ;
F_7 ( V_4 , V_60 , V_63 , V_64 ,
V_59 ? V_64 : 0 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_65 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_66 * V_67 , * V_68 ;
V_67 = & V_2 -> V_69 [ V_70 ] ;
V_68 = & V_2 -> V_69 [ V_71 ] ;
F_9 ( V_4 , V_60 , V_72 ,
( V_65 >> 16 ) & 0xffff ) ;
F_9 ( V_4 , V_60 , V_73 ,
V_65 & 0xffff ) ;
F_9 ( V_4 , V_60 , V_74 ,
( V_65 >> 16 ) & 0xffff ) ;
F_9 ( V_4 , V_60 , V_75 ,
V_65 & 0xffff ) ;
if ( ( V_67 -> V_76 == V_77 ) &&
( V_68 -> V_76 == V_78 ) ) {
T_2 V_79 = V_65 + ( V_2 -> V_80 . V_81 *
( V_68 -> V_82 - 1 ) ) ;
if ( ( V_79 ^ V_65 ) & 0x7f ) {
V_79 &= ~ 0x7f ;
V_79 += 0x80 ;
V_79 |= V_65 & 0x7f ;
}
F_9 ( V_4 , V_60 , V_83 ,
( V_79 >> 16 ) & 0xffff ) ;
F_9 ( V_4 , V_60 , V_84 ,
V_79 & 0xffff ) ;
F_9 ( V_4 , V_60 , V_85 ,
( V_79 >> 16 ) & 0xffff ) ;
F_9 ( V_4 , V_60 , V_86 ,
V_79 & 0xffff ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_66 * V_67 , * V_68 ;
V_67 = & V_2 -> V_69 [ V_70 ] ;
V_68 = & V_2 -> V_69 [ V_71 ] ;
F_11 ( V_4 , V_60 , V_87 ,
V_88 ) ;
F_7 ( V_4 , V_60 , V_87 ,
V_89 ,
V_2 -> V_90 == V_91 ?
V_89 : 0 ) ;
F_11 ( V_4 , V_60 , V_92 ,
V_93 ) ;
F_11 ( V_4 , V_60 , V_92 ,
V_94 ) ;
F_11 ( V_4 , V_60 , V_95 ,
V_96 ) ;
F_9 ( V_4 , V_60 , V_97 , 0 ) ;
F_9 ( V_4 , V_60 , V_98 , 0 ) ;
F_9 ( V_4 , V_60 , V_99 ,
V_67 -> V_82 - 2 ) ;
F_9 ( V_4 , V_60 , V_100 ,
V_67 -> V_101 - 1 ) ;
F_9 ( V_4 , V_60 , V_102 , 0 ) ;
F_9 ( V_4 , V_60 , V_103 , 0 ) ;
F_9 ( V_4 , V_60 , V_104 ,
V_68 -> V_82 - 2 ) ;
F_9 ( V_4 , V_60 , V_105 ,
V_68 -> V_101 - 1 ) ;
F_9 ( V_4 , V_60 , V_106 , 0x100 ) ;
F_9 ( V_4 , V_60 , V_107 , 0x100 ) ;
F_9 ( V_4 , V_60 , V_108 , 0 ) ;
F_9 ( V_4 , V_60 , V_109 ,
V_68 -> V_82 - 1 ) ;
F_9 ( V_4 , V_60 , V_110 ,
V_2 -> V_80 . V_81 ) ;
if ( ( V_67 -> V_76 == V_77 ) &&
( V_68 -> V_76 == V_78 ) ) {
F_9 ( V_4 , V_60 , V_111 ,
V_112 | V_113 ) ;
F_9 ( V_4 , V_60 , V_114 ,
0 ) ;
F_9 ( V_4 , V_60 , V_115 ,
V_68 -> V_82 - 1 ) ;
F_9 ( V_4 , V_60 , V_116 ,
V_2 -> V_80 . V_81 ) ;
} else {
F_9 ( V_4 , V_60 , V_111 , 0 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
F_6 ( V_2 , 0 ) ;
V_118 = F_13 ( & V_2 -> V_80 ) ;
if ( V_118 == NULL )
return;
F_8 ( V_2 , V_118 -> V_119 ) ;
F_6 ( V_2 , 1 ) ;
}
void F_14 ( struct V_1 * V_2 , T_2 V_120 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_121 * V_122 =
F_15 ( & V_2 -> V_123 . V_124 ) ;
if ( V_120 & ( V_125 |
V_126 ) ) {
F_3 ( V_4 -> V_5 , L_3 ,
V_120 & V_125 ? 1 : 0 ,
V_120 & V_126 ? 1 : 0 ) ;
F_16 ( V_122 ) ;
}
if ( F_17 ( & V_2 -> V_127 ,
& V_2 -> V_128 ) )
return;
if ( V_120 & V_129 )
F_12 ( V_2 ) ;
}
static int F_18 ( struct V_130 * V_131 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_19 ( V_131 ,
struct V_1 , V_80 ) ;
if ( ! ( V_2 -> V_132 & V_133 ) )
return - V_134 ;
F_8 ( V_2 , V_118 -> V_119 ) ;
if ( V_131 -> V_135 & V_136 ) {
F_6 ( V_2 , 1 ) ;
F_20 ( V_131 ) ;
}
return 0 ;
}
static int F_21 ( struct V_137 * V_138 , int V_59 )
{
struct V_1 * V_2 = F_22 ( V_138 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_130 * V_80 = & V_2 -> V_80 ;
int V_139 = 0 ;
if ( V_2 -> V_140 == V_141 ) {
if ( V_59 == V_141 )
return 0 ;
F_23 ( V_4 , V_142 ) ;
F_24 ( V_4 , V_60 , V_143 ,
V_144 ) ;
F_24 ( V_4 , V_60 , V_145 ,
V_146 ) ;
F_24 ( V_4 , V_60 , V_147 ,
V_148 ) ;
}
switch ( V_59 ) {
case V_149 :
F_10 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_132 & V_133 &&
! ( V_80 -> V_135 & V_150 ) )
break;
F_25 ( & V_2 -> V_128 , 0 ) ;
F_6 ( V_2 , 1 ) ;
F_20 ( V_80 ) ;
break;
case V_141 :
if ( V_2 -> V_140 == V_141 )
return 0 ;
if ( F_26 ( & V_138 -> V_124 , & V_2 -> V_127 ,
& V_2 -> V_128 ) )
V_139 = - V_151 ;
F_6 ( V_2 , 0 ) ;
F_11 ( V_4 , V_60 , V_147 ,
V_148 ) ;
F_11 ( V_4 , V_60 , V_145 ,
V_146 ) ;
F_11 ( V_4 , V_60 , V_143 ,
V_144 ) ;
F_27 ( V_4 , V_142 ) ;
F_20 ( V_80 ) ;
break;
}
V_2 -> V_140 = V_59 ;
return V_139 ;
}
static struct V_66 *
F_28 ( struct V_1 * V_2 ,
struct V_152 * V_153 , unsigned int V_154 ,
enum V_155 V_156 )
{
if ( V_156 == V_157 )
return F_29 ( & V_2 -> V_123 , V_153 , V_154 ) ;
return & V_2 -> V_69 [ V_154 ] ;
}
static void
F_30 ( struct V_1 * V_2 ,
struct V_152 * V_153 , unsigned int V_154 ,
struct V_66 * V_158 ,
enum V_155 V_156 )
{
T_2 V_159 ;
struct V_66 * V_160 ;
unsigned int V_101 = V_158 -> V_101 ;
unsigned int V_82 = V_158 -> V_82 ;
unsigned int V_161 ;
switch ( V_154 ) {
case V_70 :
for ( V_161 = 0 ; V_161 < F_31 ( V_162 ) ; V_161 ++ ) {
if ( V_158 -> V_76 == V_162 [ V_161 ] )
break;
}
if ( V_161 >= F_31 ( V_162 ) )
V_158 -> V_76 = V_77 ;
V_158 -> V_101 = F_32 ( T_2 , V_101 , 1 , 8192 ) ;
V_158 -> V_82 = F_32 ( T_2 , V_82 , 1 , 8192 ) ;
break;
case V_71 :
V_159 = V_158 -> V_76 ;
V_160 = F_28 ( V_2 , V_153 , V_70 ,
V_156 ) ;
memcpy ( V_158 , V_160 , sizeof( * V_158 ) ) ;
if ( ( V_159 == V_78 ) &&
( V_158 -> V_76 == V_77 ) )
V_158 -> V_76 = V_159 ;
V_158 -> V_101 = F_32 ( T_2 , V_101 , 32 , ( V_158 -> V_101 + 15 ) & ~ 15 ) ;
V_158 -> V_101 &= ~ 15 ;
V_158 -> V_82 = F_32 ( T_2 , V_82 , 32 , V_158 -> V_82 ) ;
break;
}
V_158 -> V_163 = V_164 ;
V_158 -> V_165 = V_166 ;
}
static int F_33 ( struct V_137 * V_138 ,
struct V_152 * V_153 ,
struct V_167 * V_76 )
{
struct V_1 * V_2 = F_22 ( V_138 ) ;
struct V_66 * V_160 ;
switch ( V_76 -> V_154 ) {
case V_70 :
if ( V_76 -> V_168 >= F_31 ( V_162 ) )
return - V_169 ;
V_76 -> V_76 = V_162 [ V_76 -> V_168 ] ;
break;
case V_71 :
V_160 = F_28 ( V_2 , V_153 , V_70 ,
V_76 -> V_156 ) ;
if ( V_76 -> V_168 == 0 ) {
V_76 -> V_76 = V_160 -> V_76 ;
break;
}
switch ( V_160 -> V_76 ) {
case V_77 :
if ( V_76 -> V_168 == 1 )
V_76 -> V_76 = V_78 ;
else
return - V_169 ;
break;
default:
if ( V_76 -> V_168 != 0 )
return - V_169 ;
}
break;
default:
return - V_169 ;
}
return 0 ;
}
static int F_34 ( struct V_137 * V_138 ,
struct V_152 * V_153 ,
struct V_170 * V_171 )
{
struct V_1 * V_2 = F_22 ( V_138 ) ;
struct V_66 V_160 ;
if ( V_171 -> V_168 != 0 )
return - V_169 ;
V_160 . V_76 = V_171 -> V_76 ;
V_160 . V_101 = 1 ;
V_160 . V_82 = 1 ;
F_30 ( V_2 , V_153 , V_171 -> V_154 , & V_160 , V_171 -> V_156 ) ;
V_171 -> V_172 = V_160 . V_101 ;
V_171 -> V_173 = V_160 . V_82 ;
if ( V_160 . V_76 != V_171 -> V_76 )
return - V_169 ;
V_160 . V_76 = V_171 -> V_76 ;
V_160 . V_101 = - 1 ;
V_160 . V_82 = - 1 ;
F_30 ( V_2 , V_153 , V_171 -> V_154 , & V_160 , V_171 -> V_156 ) ;
V_171 -> V_174 = V_160 . V_101 ;
V_171 -> V_175 = V_160 . V_82 ;
return 0 ;
}
static int F_35 ( struct V_137 * V_138 , struct V_152 * V_153 ,
struct V_176 * V_158 )
{
struct V_1 * V_2 = F_22 ( V_138 ) ;
struct V_66 * V_160 ;
V_160 = F_28 ( V_2 , V_153 , V_158 -> V_154 , V_158 -> V_156 ) ;
if ( V_160 == NULL )
return - V_169 ;
V_158 -> V_160 = * V_160 ;
return 0 ;
}
static int F_36 ( struct V_137 * V_138 , struct V_152 * V_153 ,
struct V_176 * V_158 )
{
struct V_1 * V_2 = F_22 ( V_138 ) ;
struct V_66 * V_160 ;
V_160 = F_28 ( V_2 , V_153 , V_158 -> V_154 , V_158 -> V_156 ) ;
if ( V_160 == NULL )
return - V_169 ;
F_30 ( V_2 , V_153 , V_158 -> V_154 , & V_158 -> V_160 , V_158 -> V_156 ) ;
* V_160 = V_158 -> V_160 ;
if ( V_158 -> V_154 == V_70 ) {
V_160 = F_28 ( V_2 , V_153 ,
V_71 ,
V_158 -> V_156 ) ;
* V_160 = V_158 -> V_160 ;
F_30 ( V_2 , V_153 , V_71 , V_160 ,
V_158 -> V_156 ) ;
}
return 0 ;
}
static int F_37 ( struct V_137 * V_138 ,
struct V_177 * V_178 ,
struct V_176 * V_179 ,
struct V_176 * V_180 )
{
if ( V_179 -> V_160 . V_101 != V_180 -> V_160 . V_101 ||
V_179 -> V_160 . V_82 != V_180 -> V_160 . V_82 )
return - V_181 ;
if ( V_179 -> V_160 . V_76 != V_180 -> V_160 . V_76 )
return - V_181 ;
return 0 ;
}
static int F_38 ( struct V_137 * V_138 ,
struct V_182 * V_183 )
{
struct V_176 V_160 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
V_160 . V_154 = V_70 ;
V_160 . V_156 = V_183 ? V_157 : V_184 ;
V_160 . V_160 . V_76 = V_77 ;
V_160 . V_160 . V_101 = 4096 ;
V_160 . V_160 . V_82 = 4096 ;
F_36 ( V_138 , V_183 ? V_183 -> V_154 : NULL , & V_160 ) ;
return 0 ;
}
static int F_39 ( struct V_185 * V_124 ,
const struct V_186 * V_187 ,
const struct V_186 * V_188 , T_2 V_189 )
{
struct V_137 * V_138 = F_40 ( V_124 ) ;
struct V_1 * V_2 = F_22 ( V_138 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_187 -> V_168 | F_41 ( V_188 -> V_124 ) ) {
case V_70 | V_190 :
if ( ! ( V_189 & V_191 ) ) {
V_2 -> V_90 = V_192 ;
break;
}
if ( V_2 -> V_90 != V_192 )
return - V_193 ;
if ( V_188 -> V_124 == & V_4 -> V_194 . V_123 . V_124 )
V_2 -> V_90 = V_91 ;
else if ( V_188 -> V_124 == & V_4 -> V_195 . V_123 . V_124 )
V_2 -> V_90 = V_196 ;
break;
case V_71 | V_197 :
if ( V_189 & V_191 ) {
if ( V_2 -> V_132 & ~ V_133 )
return - V_193 ;
V_2 -> V_132 |= V_133 ;
} else {
V_2 -> V_132 &= ~ V_133 ;
}
break;
default:
return - V_169 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_137 * V_138 = & V_2 -> V_123 ;
struct V_186 * V_198 = V_2 -> V_198 ;
struct V_185 * V_199 = & V_138 -> V_124 ;
int V_139 ;
V_2 -> V_90 = V_192 ;
F_43 ( V_138 , & V_200 ) ;
V_138 -> V_201 = & V_202 ;
F_44 ( V_138 -> V_203 , L_4 , sizeof( V_138 -> V_203 ) ) ;
V_138 -> V_204 = 1 << 16 ;
F_45 ( V_138 , V_2 ) ;
V_138 -> V_189 |= V_205 ;
V_198 [ V_70 ] . V_189 = V_206 ;
V_198 [ V_71 ] . V_189 = V_207 ;
V_199 -> V_208 = & V_209 ;
V_139 = F_46 ( V_199 , V_210 , V_198 , 0 ) ;
if ( V_139 < 0 )
return V_139 ;
F_38 ( V_138 , NULL ) ;
V_2 -> V_80 . type = V_211 ;
V_2 -> V_80 . V_208 = & V_212 ;
V_2 -> V_80 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_80 . V_213 = F_47 ( 4096 * 4096 ) * 3 ;
V_2 -> V_80 . V_214 = 32 ;
V_2 -> V_80 . V_215 = 1 ;
V_2 -> V_80 . V_216 = 0x1ffe0 ;
V_139 = F_48 ( & V_2 -> V_80 , L_5 ) ;
if ( V_139 < 0 )
return V_139 ;
V_139 = F_49 ( & V_2 -> V_123 . V_124 ,
V_71 ,
& V_2 -> V_80 . V_131 . V_124 , 0 , 0 ) ;
if ( V_139 < 0 )
return V_139 ;
return 0 ;
}
void F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_123 ) ;
F_52 ( & V_2 -> V_80 ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_217 * V_218 )
{
int V_139 ;
V_139 = F_54 ( V_218 , & V_2 -> V_123 ) ;
if ( V_139 < 0 )
goto error;
V_139 = F_55 ( & V_2 -> V_80 , V_218 ) ;
if ( V_139 < 0 )
goto error;
return 0 ;
error:
F_50 ( V_2 ) ;
return V_139 ;
}
int F_56 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
V_2 -> V_140 = V_141 ;
F_57 ( & V_2 -> V_127 ) ;
return F_42 ( V_2 ) ;
}
void F_58 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_59 ( & V_2 -> V_123 . V_124 ) ;
}
