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
static void F_14 ( struct V_1 * V_2 )
{
struct V_120 * V_121 =
F_15 ( & V_2 -> V_122 . V_123 ) ;
if ( V_121 -> V_124 )
F_16 ( & V_121 -> V_125 ) ;
F_12 ( V_2 ) ;
}
void F_17 ( struct V_1 * V_2 , T_2 V_126 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_120 * V_121 =
F_15 ( & V_2 -> V_122 . V_123 ) ;
if ( V_126 & ( V_127 |
V_128 ) ) {
F_3 ( V_4 -> V_5 , L_3 ,
V_126 & V_127 ? 1 : 0 ,
V_126 & V_128 ? 1 : 0 ) ;
F_18 ( V_121 ) ;
}
if ( F_19 ( & V_2 -> V_129 ,
& V_2 -> V_130 ) )
return;
if ( V_126 & V_131 )
F_14 ( V_2 ) ;
}
static int F_20 ( struct V_132 * V_133 ,
struct V_117 * V_118 )
{
struct V_1 * V_2 = F_21 ( V_133 ,
struct V_1 , V_80 ) ;
if ( ! ( V_2 -> V_134 & V_135 ) )
return - V_136 ;
F_8 ( V_2 , V_118 -> V_119 ) ;
if ( V_133 -> V_137 & V_138 ) {
F_6 ( V_2 , 1 ) ;
F_22 ( V_133 ) ;
}
return 0 ;
}
static int F_23 ( struct V_139 * V_140 , int V_59 )
{
struct V_1 * V_2 = F_24 ( V_140 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_132 * V_80 = & V_2 -> V_80 ;
int V_141 = 0 ;
if ( V_2 -> V_142 == V_143 ) {
if ( V_59 == V_143 )
return 0 ;
F_25 ( V_4 , V_144 ) ;
F_26 ( V_4 , V_60 , V_145 ,
V_146 ) ;
F_26 ( V_4 , V_60 , V_147 ,
V_148 ) ;
F_26 ( V_4 , V_60 , V_149 ,
V_150 ) ;
}
switch ( V_59 ) {
case V_151 :
F_10 ( V_2 ) ;
F_1 ( V_2 ) ;
if ( V_2 -> V_134 & V_135 &&
! ( V_80 -> V_137 & V_152 ) )
break;
F_27 ( & V_2 -> V_130 , 0 ) ;
F_6 ( V_2 , 1 ) ;
F_22 ( V_80 ) ;
break;
case V_143 :
if ( V_2 -> V_142 == V_143 )
return 0 ;
if ( F_28 ( & V_140 -> V_123 , & V_2 -> V_129 ,
& V_2 -> V_130 ) )
V_141 = - V_153 ;
F_6 ( V_2 , 0 ) ;
F_11 ( V_4 , V_60 , V_149 ,
V_150 ) ;
F_11 ( V_4 , V_60 , V_147 ,
V_148 ) ;
F_11 ( V_4 , V_60 , V_145 ,
V_146 ) ;
F_29 ( V_4 , V_144 ) ;
F_22 ( V_80 ) ;
break;
}
V_2 -> V_142 = V_59 ;
return V_141 ;
}
static struct V_66 *
F_30 ( struct V_1 * V_2 ,
struct V_154 * V_155 , unsigned int V_156 ,
enum V_157 V_158 )
{
if ( V_158 == V_159 )
return F_31 ( V_155 , V_156 ) ;
else
return & V_2 -> V_69 [ V_156 ] ;
}
static void
F_32 ( struct V_1 * V_2 ,
struct V_154 * V_155 , unsigned int V_156 ,
struct V_66 * V_160 ,
enum V_157 V_158 )
{
enum V_161 V_162 ;
struct V_66 * V_163 ;
unsigned int V_101 = V_160 -> V_101 ;
unsigned int V_82 = V_160 -> V_82 ;
unsigned int V_164 ;
switch ( V_156 ) {
case V_70 :
for ( V_164 = 0 ; V_164 < F_33 ( V_165 ) ; V_164 ++ ) {
if ( V_160 -> V_76 == V_165 [ V_164 ] )
break;
}
if ( V_164 >= F_33 ( V_165 ) )
V_160 -> V_76 = V_77 ;
V_160 -> V_101 = F_34 ( T_2 , V_101 , 1 , 8192 ) ;
V_160 -> V_82 = F_34 ( T_2 , V_82 , 1 , 8192 ) ;
break;
case V_71 :
V_162 = V_160 -> V_76 ;
V_163 = F_30 ( V_2 , V_155 , V_70 ,
V_158 ) ;
memcpy ( V_160 , V_163 , sizeof( * V_160 ) ) ;
if ( ( V_162 == V_78 ) &&
( V_160 -> V_76 == V_77 ) )
V_160 -> V_76 = V_162 ;
V_160 -> V_101 = F_34 ( T_2 , V_101 , 32 , ( V_160 -> V_101 + 15 ) & ~ 15 ) ;
V_160 -> V_101 &= ~ 15 ;
V_160 -> V_82 = F_34 ( T_2 , V_82 , 32 , V_160 -> V_82 ) ;
break;
}
V_160 -> V_166 = V_167 ;
V_160 -> V_168 = V_169 ;
}
static int F_35 ( struct V_139 * V_140 ,
struct V_154 * V_155 ,
struct V_170 * V_76 )
{
struct V_1 * V_2 = F_24 ( V_140 ) ;
struct V_66 * V_163 ;
switch ( V_76 -> V_156 ) {
case V_70 :
if ( V_76 -> V_171 >= F_33 ( V_165 ) )
return - V_172 ;
V_76 -> V_76 = V_165 [ V_76 -> V_171 ] ;
break;
case V_71 :
V_163 = F_30 ( V_2 , V_155 , V_70 ,
V_159 ) ;
if ( V_76 -> V_171 == 0 ) {
V_76 -> V_76 = V_163 -> V_76 ;
break;
}
switch ( V_163 -> V_76 ) {
case V_77 :
if ( V_76 -> V_171 == 1 )
V_76 -> V_76 = V_78 ;
else
return - V_172 ;
break;
default:
if ( V_76 -> V_171 != 0 )
return - V_172 ;
}
break;
default:
return - V_172 ;
}
return 0 ;
}
static int F_36 ( struct V_139 * V_140 ,
struct V_154 * V_155 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_24 ( V_140 ) ;
struct V_66 V_163 ;
if ( V_174 -> V_171 != 0 )
return - V_172 ;
V_163 . V_76 = V_174 -> V_76 ;
V_163 . V_101 = 1 ;
V_163 . V_82 = 1 ;
F_32 ( V_2 , V_155 , V_174 -> V_156 , & V_163 ,
V_159 ) ;
V_174 -> V_175 = V_163 . V_101 ;
V_174 -> V_176 = V_163 . V_82 ;
if ( V_163 . V_76 != V_174 -> V_76 )
return - V_172 ;
V_163 . V_76 = V_174 -> V_76 ;
V_163 . V_101 = - 1 ;
V_163 . V_82 = - 1 ;
F_32 ( V_2 , V_155 , V_174 -> V_156 , & V_163 ,
V_159 ) ;
V_174 -> V_177 = V_163 . V_101 ;
V_174 -> V_178 = V_163 . V_82 ;
return 0 ;
}
static int F_37 ( struct V_139 * V_140 , struct V_154 * V_155 ,
struct V_179 * V_160 )
{
struct V_1 * V_2 = F_24 ( V_140 ) ;
struct V_66 * V_163 ;
V_163 = F_30 ( V_2 , V_155 , V_160 -> V_156 , V_160 -> V_158 ) ;
if ( V_163 == NULL )
return - V_172 ;
V_160 -> V_163 = * V_163 ;
return 0 ;
}
static int F_38 ( struct V_139 * V_140 , struct V_154 * V_155 ,
struct V_179 * V_160 )
{
struct V_1 * V_2 = F_24 ( V_140 ) ;
struct V_66 * V_163 ;
V_163 = F_30 ( V_2 , V_155 , V_160 -> V_156 , V_160 -> V_158 ) ;
if ( V_163 == NULL )
return - V_172 ;
F_32 ( V_2 , V_155 , V_160 -> V_156 , & V_160 -> V_163 , V_160 -> V_158 ) ;
* V_163 = V_160 -> V_163 ;
if ( V_160 -> V_156 == V_70 ) {
V_163 = F_30 ( V_2 , V_155 ,
V_71 ,
V_160 -> V_158 ) ;
* V_163 = V_160 -> V_163 ;
F_32 ( V_2 , V_155 , V_71 , V_163 ,
V_160 -> V_158 ) ;
}
return 0 ;
}
static int F_39 ( struct V_139 * V_140 ,
struct V_180 * V_181 ,
struct V_179 * V_182 ,
struct V_179 * V_183 )
{
if ( V_182 -> V_163 . V_101 != V_183 -> V_163 . V_101 ||
V_182 -> V_163 . V_82 != V_183 -> V_163 . V_82 )
return - V_184 ;
if ( V_182 -> V_163 . V_76 != V_183 -> V_163 . V_76 )
return - V_184 ;
return 0 ;
}
static int F_40 ( struct V_139 * V_140 ,
struct V_154 * V_155 )
{
struct V_179 V_163 ;
memset ( & V_163 , 0 , sizeof( V_163 ) ) ;
V_163 . V_156 = V_70 ;
V_163 . V_158 = V_155 ? V_159 : V_185 ;
V_163 . V_163 . V_76 = V_77 ;
V_163 . V_163 . V_101 = 4096 ;
V_163 . V_163 . V_82 = 4096 ;
F_38 ( V_140 , V_155 , & V_163 ) ;
return 0 ;
}
static int F_41 ( struct V_186 * V_123 ,
const struct V_187 * V_188 ,
const struct V_187 * V_189 , T_2 V_190 )
{
struct V_139 * V_140 = F_42 ( V_123 ) ;
struct V_1 * V_2 = F_24 ( V_140 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_188 -> V_171 | F_43 ( V_189 -> V_123 ) ) {
case V_70 | V_191 :
if ( ! ( V_190 & V_192 ) ) {
V_2 -> V_90 = V_193 ;
break;
}
if ( V_2 -> V_90 != V_193 )
return - V_194 ;
if ( V_189 -> V_123 == & V_4 -> V_195 . V_122 . V_123 )
V_2 -> V_90 = V_91 ;
else if ( V_189 -> V_123 == & V_4 -> V_196 . V_122 . V_123 )
V_2 -> V_90 = V_197 ;
break;
case V_71 | V_198 :
if ( V_190 & V_192 ) {
if ( V_2 -> V_134 & ~ V_135 )
return - V_194 ;
V_2 -> V_134 |= V_135 ;
} else {
V_2 -> V_134 &= ~ V_135 ;
}
break;
default:
return - V_172 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_139 * V_140 = & V_2 -> V_122 ;
struct V_187 * V_199 = V_2 -> V_199 ;
struct V_186 * V_200 = & V_140 -> V_123 ;
int V_141 ;
V_2 -> V_90 = V_193 ;
F_45 ( V_140 , & V_201 ) ;
V_140 -> V_202 = & V_203 ;
F_46 ( V_140 -> V_204 , L_4 , sizeof( V_140 -> V_204 ) ) ;
V_140 -> V_205 = 1 << 16 ;
F_47 ( V_140 , V_2 ) ;
V_140 -> V_190 |= V_206 ;
V_199 [ V_70 ] . V_190 = V_207 ;
V_199 [ V_71 ] . V_190 = V_208 ;
V_200 -> V_209 = & V_210 ;
V_141 = F_48 ( V_200 , V_211 , V_199 , 0 ) ;
if ( V_141 < 0 )
return V_141 ;
F_40 ( V_140 , NULL ) ;
V_2 -> V_80 . type = V_212 ;
V_2 -> V_80 . V_209 = & V_213 ;
V_2 -> V_80 . V_4 = F_2 ( V_2 ) ;
V_2 -> V_80 . V_214 = F_49 ( 4096 * 4096 ) * 3 ;
V_2 -> V_80 . V_215 = 32 ;
V_2 -> V_80 . V_216 = 1 ;
V_2 -> V_80 . V_217 = 0x1ffe0 ;
V_141 = F_50 ( & V_2 -> V_80 , L_5 ) ;
if ( V_141 < 0 )
return V_141 ;
V_141 = F_51 ( & V_2 -> V_122 . V_123 ,
V_71 ,
& V_2 -> V_80 . V_133 . V_123 , 0 , 0 ) ;
if ( V_141 < 0 )
return V_141 ;
return 0 ;
}
void F_52 ( struct V_1 * V_2 )
{
F_53 ( & V_2 -> V_122 . V_123 ) ;
F_54 ( & V_2 -> V_122 ) ;
F_55 ( & V_2 -> V_80 ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_218 * V_219 )
{
int V_141 ;
V_141 = F_57 ( V_219 , & V_2 -> V_122 ) ;
if ( V_141 < 0 )
goto error;
V_141 = F_58 ( & V_2 -> V_80 , V_219 ) ;
if ( V_141 < 0 )
goto error;
return 0 ;
error:
F_52 ( V_2 ) ;
return V_141 ;
}
int F_59 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
V_2 -> V_142 = V_143 ;
F_60 ( & V_2 -> V_129 ) ;
return F_44 ( V_2 ) ;
}
void F_61 ( struct V_3 * V_4 )
{
}
