static void
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 V_5 ,
void * V_6 )
{
struct V_7 * V_8 = V_6 ;
const struct V_9 * V_10 = & V_4 -> V_11 ;
T_1 V_12 , V_13 , V_14 ;
V_12 = V_5 + V_4 -> V_15 + V_10 -> V_16 ;
V_13 = ( V_12 + V_10 -> V_17 ) >> 8 ;
V_14 = ( V_12 + V_10 -> V_18 ) >> 8 ;
V_8 -> V_19 = V_20 ;
V_8 -> V_21 = F_2 ( V_13 ) ;
V_8 -> V_22 = F_3 ( V_13 ) ;
V_8 -> V_23 = V_10 -> V_17 ;
V_8 -> V_24 = V_10 -> V_25 ;
V_8 -> V_26 = V_10 -> V_27 ;
V_8 -> V_28 = F_2 ( V_14 ) ;
V_8 -> V_29 = F_3 ( V_14 ) ;
V_8 -> V_30 = V_10 -> V_31 ;
}
struct V_3 *
F_4 ( const struct V_32 * V_2 ,
const struct V_33 * V_34 ,
enum V_35 V_36 )
{
const struct V_37 * V_38 = V_2 -> V_12 . V_38 ;
struct V_39 * V_4 ;
int V_40 ;
V_4 = F_5 ( sizeof( * V_4 ) , V_41 ) ;
if ( ! V_4 )
return F_6 ( - V_42 ) ;
V_4 -> V_12 . V_36 = V_36 ;
V_40 = V_2 -> V_43 -> V_44 [ V_36 ] -> F_7 ( V_34 , & V_4 -> V_12 ) ;
if ( V_40 ) {
F_8 ( V_4 -> V_12 . V_45 ) ;
F_8 ( V_4 -> V_12 . V_46 ) ;
F_8 ( V_4 ) ;
return F_6 ( V_40 ) ;
}
if ( V_4 -> V_12 . V_47 != sizeof( V_4 -> V_48 . V_49 ) ) {
F_9 ( V_38 , L_1 ,
V_50 [ V_36 ] ) ;
return F_6 ( - V_51 ) ;
}
memcpy ( & V_4 -> V_48 . V_49 , V_4 -> V_12 . V_46 , V_4 -> V_12 . V_47 ) ;
V_4 -> V_48 . V_49 . V_36 = V_36 ;
return & V_4 -> V_12 ;
}
static T_2
F_10 ( struct V_32 * V_2 ,
struct V_39 * V_4 , T_2 V_52 )
{
struct V_3 * V_53 = & V_4 -> V_12 ;
struct V_54 * V_55 = & V_4 -> V_56 ;
struct V_57 * V_58 = & V_4 -> V_48 ;
struct V_9 * V_8 = & V_53 -> V_11 ;
const struct V_59 * V_43 =
V_2 -> V_43 -> V_44 [ V_53 -> V_36 ] ;
V_55 -> V_36 = V_53 -> V_36 ;
V_55 -> V_60 = V_2 -> V_12 . V_61 ;
V_55 -> V_62 = V_63 ;
if ( V_2 -> V_64 & F_11 ( V_53 -> V_36 ) )
V_55 -> V_64 = 1 ;
V_52 = F_12 ( V_52 , V_65 ) ;
V_55 -> V_66 = V_52 ;
V_52 += sizeof( * V_58 ) ;
V_52 = F_12 ( V_52 , V_67 ) ;
V_53 -> V_15 = V_58 -> V_15 = V_52 ;
V_52 += V_53 -> V_68 ;
V_58 -> V_69 = F_12 ( V_8 -> V_70 ,
V_71 ) ;
V_58 -> V_68 = F_12 ( V_8 -> V_18 ,
V_71 ) + V_58 -> V_69 ;
V_58 -> V_30 = F_12 ( V_8 -> V_72 , V_71 ) +
V_58 -> V_69 - V_58 -> V_68 ;
V_58 -> V_73 = V_8 -> V_74 ;
V_58 -> V_75 = V_8 -> V_16 +
V_8 -> V_17 ;
V_58 -> V_76 = V_8 -> V_25 ;
V_58 -> V_77 = V_8 -> V_16 +
V_8 -> V_18 ;
V_58 -> V_78 = V_8 -> V_31 ;
V_58 -> V_79 = V_43 -> V_80 ;
if ( V_53 -> V_36 == V_2 -> V_12 . V_61 )
V_58 -> V_79 |= V_81 ;
V_58 -> V_82 = F_12 ( V_43 -> V_83 , V_84 ) ;
V_52 = F_12 ( V_52 , V_85 ) ;
V_58 -> V_86 = V_52 ;
V_52 += V_58 -> V_82 ;
return V_52 ;
}
int
F_13 ( struct V_32 * V_2 , struct V_87 * V_88 )
{
struct V_39 * V_4 ;
struct V_87 * V_89 ;
T_2 V_90 = 0 ;
T_2 V_52 ;
F_14 (l, imgs)
V_90 ++ ;
V_52 = sizeof( V_4 -> V_56 ) * ( V_90 + 1 ) ;
F_15 (img, imgs, base.node) {
V_52 = F_10 ( V_2 , V_4 , V_52 ) ;
}
return V_52 ;
}
int
F_16 ( struct V_32 * V_2 , struct V_87 * V_88 ,
struct V_91 * V_92 , T_1 V_5 )
{
struct V_3 * V_53 ;
T_2 V_93 = 0 ;
F_17 ( V_92 ) ;
F_15 (_img, imgs, node) {
struct V_39 * V_4 = V_39 ( V_53 ) ;
const struct V_59 * V_44 =
V_2 -> V_43 -> V_44 [ V_53 -> V_36 ] ;
T_3 V_94 [ V_44 -> V_83 ] ;
F_18 ( V_92 , V_93 , & V_4 -> V_56 ,
sizeof( V_4 -> V_56 ) ) ;
F_18 ( V_92 , V_4 -> V_56 . V_66 ,
& V_4 -> V_48 , sizeof( V_4 -> V_48 ) ) ;
memset ( V_94 , 0 , V_44 -> V_83 ) ;
V_44 -> V_95 ( & V_2 -> V_12 , V_53 , V_5 , V_94 ) ;
F_18 ( V_92 , V_4 -> V_48 . V_86 ,
V_94 , V_44 -> V_83 ) ;
F_18 ( V_92 , V_4 -> V_48 . V_15 ,
V_53 -> V_45 , V_53 -> V_68 ) ;
V_93 += sizeof( V_4 -> V_56 ) ;
}
F_19 ( V_92 , V_93 , V_96 ) ;
F_20 ( V_92 ) ;
return 0 ;
}
static int
F_21 ( struct V_32 * V_2 , struct V_33 * V_34 )
{
const struct V_37 * V_38 = V_2 -> V_12 . V_38 ;
struct V_87 V_88 ;
struct V_3 * V_4 , * V_97 ;
unsigned long V_98 = V_2 -> V_12 . V_98 ;
T_1 V_5 = V_34 -> V_5 ;
T_2 V_99 = V_34 -> V_99 ;
int V_100 = 0 ;
T_2 V_101 , V_102 ;
int V_36 ;
int V_40 ;
F_22 ( & V_88 ) ;
F_23 (falcon_id, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
struct V_3 * V_4 ;
V_4 = V_2 -> V_43 -> V_103 ( V_2 , V_34 , V_36 ) ;
if ( F_24 ( V_4 ) ) {
if ( V_2 -> V_12 . V_104 & F_11 ( V_36 ) ) {
V_98 &= ~ F_11 ( V_36 ) ;
F_25 ( V_38 , L_2 ,
V_50 [ V_36 ] ) ;
continue;
}
V_40 = F_26 ( V_4 ) ;
goto V_105;
}
F_27 ( & V_4 -> V_106 , & V_88 ) ;
V_100 ++ ;
}
V_2 -> V_12 . V_98 = V_98 ;
if ( V_2 -> V_43 -> V_44 [ V_2 -> V_12 . V_61 ] &&
( V_98 & F_11 ( V_2 -> V_12 . V_61 ) ) ) {
F_23 (falcon_id, &managed_falcons,
NVKM_SECBOOT_FALCON_END) {
if ( V_36 == V_2 -> V_12 . V_61 )
continue;
V_2 -> V_64 |= F_11 ( V_36 ) ;
}
}
V_101 = V_2 -> V_43 -> V_107 ( V_2 , & V_88 ) ;
V_101 = F_12 ( V_101 , V_108 ) ;
V_102 = V_101 ;
if ( V_99 == 0 && V_2 -> V_43 -> V_109 )
V_102 *= 2 ;
V_40 = F_28 ( V_38 -> V_110 , V_102 , V_108 ,
false , NULL , & V_2 -> V_111 ) ;
if ( V_40 )
goto V_105;
F_29 ( V_38 , L_3 ,
V_100 , V_101 ) ;
if ( V_99 == 0 ) {
V_5 = V_2 -> V_111 -> V_112 ;
if ( V_2 -> V_43 -> V_109 )
V_5 += V_2 -> V_111 -> V_113 / 2 ;
V_99 = V_101 ;
} else if ( V_101 > V_99 ) {
F_9 ( V_38 , L_4 ) ;
F_9 ( V_38 , L_5 , V_101 ) ;
F_9 ( V_38 , L_6 , V_99 ) ;
V_40 = - V_114 ;
goto V_105;
}
V_40 = V_2 -> V_43 -> V_115 ( V_2 , & V_88 , V_2 -> V_111 , V_5 ) ;
if ( V_40 )
F_30 ( & V_2 -> V_111 ) ;
V_105:
F_31 (img, t, &imgs, node) {
F_8 ( V_4 -> V_45 ) ;
F_8 ( V_4 -> V_46 ) ;
F_8 ( V_4 ) ;
}
return V_40 ;
}
void
F_32 ( struct V_32 * V_2 , struct V_33 * V_34 ,
void * V_6 )
{
struct V_116 * V_8 = V_6 ;
struct V_91 * V_111 = V_2 -> V_111 ;
if ( V_34 -> V_99 == 0 ) {
T_1 V_117 = V_111 -> V_112 ;
T_1 V_118 = V_117 + V_111 -> V_113 ;
V_8 -> V_119 = 1 ;
V_8 -> V_120 . V_121 = 2 ;
V_8 -> V_120 . V_122 [ 0 ] . V_123 = V_117 >> 8 ;
V_8 -> V_120 . V_122 [ 0 ] . V_124 = V_118 >> 8 ;
V_8 -> V_120 . V_122 [ 0 ] . V_125 = 1 ;
V_8 -> V_120 . V_122 [ 0 ] . V_126 = 0xf ;
V_8 -> V_120 . V_122 [ 0 ] . V_127 = 0xc ;
V_8 -> V_120 . V_122 [ 0 ] . V_128 = 0x2 ;
} else {
V_8 -> V_129 = V_111 -> V_112 ;
V_8 -> V_130 = V_111 -> V_113 ;
}
}
static void
F_33 ( const struct V_131 * V_132 , void * V_133 ,
T_1 V_52 )
{
struct V_7 * V_134 = V_133 ;
T_1 V_13 , V_14 ;
V_13 = V_52 >> 8 ;
V_14 = ( V_52 + V_132 -> V_28 ) >> 8 ;
V_134 -> V_19 = V_135 ;
V_134 -> V_21 = F_2 ( V_13 ) ;
V_134 -> V_23 = V_132 -> V_23 ;
V_134 -> V_24 = V_132 -> V_24 ;
V_134 -> V_136 = F_34 ( V_132 , 0 ) ;
V_134 -> V_137 = F_35 ( V_132 , 0 ) ;
V_134 -> V_26 = 0 ;
V_134 -> V_28 = F_2 ( V_14 ) ;
V_134 -> V_30 = V_132 -> V_30 ;
}
static int
F_36 ( struct V_32 * V_2 , struct V_33 * V_34 ,
const char * V_138 , struct V_91 * * V_139 ,
struct V_131 * V_140 , bool V_141 )
{
struct V_37 * V_38 = & V_34 -> V_38 ;
void * V_142 ;
struct V_143 * V_144 ;
struct V_145 * V_146 ;
struct V_131 * V_147 ;
void * V_148 ;
int V_40 ;
V_142 = F_37 ( V_38 , V_34 -> V_61 , V_138 ) ;
if ( F_24 ( V_142 ) )
return F_26 ( V_142 ) ;
V_144 = V_142 ;
V_146 = V_142 + V_144 -> V_149 ;
V_147 = V_142 + V_146 -> V_150 ;
V_148 = V_142 + V_144 -> V_151 ;
if ( V_141 ) {
struct V_116 * V_8 ;
V_8 = V_148 + V_147 -> V_28 ;
V_2 -> V_43 -> V_152 ( V_2 , V_34 , V_8 ) ;
}
if ( V_147 -> V_153 > V_154 ) {
F_9 ( V_38 , L_7 ,
V_147 -> V_153 , V_154 ) ;
V_40 = - V_51 ;
goto V_105;
}
memcpy ( V_140 , V_147 , sizeof( * V_140 ) +
( sizeof( V_147 -> V_155 [ 0 ] ) * 2 * V_147 -> V_153 ) ) ;
V_40 = F_28 ( V_38 -> V_110 , F_12 ( V_144 -> V_30 , 256 ) ,
0x1000 , false , NULL , V_139 ) ;
if ( V_40 )
goto V_105;
F_17 ( * V_139 ) ;
F_18 ( * V_139 , 0 , V_148 , V_144 -> V_30 ) ;
F_20 ( * V_139 ) ;
V_105:
F_8 ( V_142 ) ;
return V_40 ;
}
int
F_38 ( struct V_32 * V_2 , struct V_33 * V_34 )
{
struct V_37 * V_38 = & V_34 -> V_38 ;
int V_40 ;
if ( V_2 -> V_156 )
return 0 ;
V_40 = F_21 ( V_2 , V_34 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_2 -> V_157 ) {
V_40 = F_36 ( V_2 , V_34 , L_8 ,
& V_2 -> V_157 ,
& V_2 -> V_158 , true ) ;
if ( V_40 )
return V_40 ;
}
if ( V_34 -> V_99 == 0 ) {
V_40 = F_36 ( V_2 , V_34 , L_9 ,
& V_2 -> V_159 ,
& V_2 -> V_160 , false ) ;
if ( V_40 )
return V_40 ;
}
if ( ! V_2 -> V_161 ) {
V_2 -> V_161 = F_39 ( V_38 , L_10 , 0 ) ;
if ( F_24 ( V_2 -> V_161 ) ) {
V_40 = F_26 ( V_2 -> V_161 ) ;
V_2 -> V_161 = NULL ;
return V_40 ;
}
if ( V_2 -> V_12 . V_61 != V_162 ) {
V_2 -> V_163 = F_39 ( V_38 ,
L_11 , 0 ) ;
if ( F_24 ( V_2 -> V_163 ) ) {
V_40 = F_26 ( V_2 -> V_163 ) ;
V_2 -> V_163 = NULL ;
return V_40 ;
}
} else {
V_2 -> V_163 = V_2 -> V_161 ;
}
}
V_2 -> V_156 = true ;
F_29 ( & V_34 -> V_38 , L_12 ) ;
return 0 ;
}
static int
F_40 ( struct V_1 * V_164 , struct V_165 * V_166 ,
struct V_91 * V_139 , T_1 V_52 )
{
struct V_32 * V_2 = V_32 ( V_164 ) ;
const T_2 V_83 = V_2 -> V_43 -> V_167 ;
const struct V_131 * V_147 ;
struct V_143 * V_168 ;
struct V_169 * V_170 ;
void * V_171 , * V_172 , * V_173 , * V_174 ;
T_2 V_175 ;
T_3 V_134 [ V_83 ] ;
if ( V_139 == V_2 -> V_157 ) {
V_147 = & V_2 -> V_158 ;
V_171 = V_2 -> V_161 ;
} else if ( V_139 == V_2 -> V_159 ) {
V_147 = & V_2 -> V_160 ;
V_171 = V_2 -> V_163 ;
} else {
F_9 ( V_164 -> V_38 , L_13 ) ;
return - V_51 ;
}
V_168 = V_171 ;
V_170 = V_171 + V_168 -> V_149 ;
V_172 = V_171 + V_168 -> V_151 ;
V_173 = V_172 + V_170 -> V_176 ;
V_174 = V_172 + V_170 -> V_177 ;
V_175 = F_12 ( V_170 -> V_175 , 256 ) ;
F_41 ( V_166 , V_174 , 0x0 , V_170 -> V_30 , 0 ) ;
F_42 ( V_166 , V_173 , V_166 -> V_178 . V_179 - V_175 ,
V_175 , V_170 -> V_180 , 0 , false ) ;
memset ( V_134 , 0 , V_83 ) ;
V_2 -> V_43 -> V_181 ( V_147 , V_134 , V_52 ) ;
F_41 ( V_166 , V_134 , V_170 -> V_182 ,
V_83 , 0 ) ;
return V_170 -> V_180 << 8 ;
}
static int
F_43 ( struct V_32 * V_2 , struct V_33 * V_34 )
{
struct V_37 * V_38 = & V_34 -> V_38 ;
int V_183 ;
if ( V_2 -> V_159 && V_34 -> V_184 ) {
int V_40 ;
F_29 ( V_38 , L_14 ) ;
V_40 = V_34 -> V_43 -> V_185 ( V_34 , V_2 -> V_159 , V_34 -> V_186 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_40 && V_40 != 0x1d ) {
F_9 ( V_38 , L_15 , V_40 ) ;
return - V_51 ;
}
F_29 ( V_38 , L_16 ) ;
}
for ( V_183 = 0 ; V_183 < V_187 ; V_183 ++ )
V_2 -> V_188 [ V_183 ] = V_189 ;
V_34 -> V_184 = false ;
return 0 ;
}
static bool
F_44 ( const struct V_32 * V_2 , const struct V_33 * V_34 )
{
const struct V_37 * V_38 = & V_34 -> V_38 ;
const struct V_190 * V_110 = V_38 -> V_110 ;
T_1 V_191 , V_192 ;
T_1 V_193 , V_194 ;
F_45 ( V_110 , 0x100cd4 , 0x2 ) ;
V_191 = ( F_46 ( V_110 , 0x100cd4 ) & ~ 0xff ) ;
V_191 <<= 8 ;
F_45 ( V_110 , 0x100cd4 , 0x3 ) ;
V_192 = ( F_46 ( V_110 , 0x100cd4 ) & ~ 0xff ) ;
V_192 <<= 8 ;
if ( V_34 -> V_99 != 0 ) {
V_193 = V_34 -> V_5 ;
V_194 = V_193 + V_34 -> V_99 ;
} else {
V_193 = V_2 -> V_111 -> V_112 ;
V_194 = V_193 + V_2 -> V_111 -> V_113 ;
}
return ( V_191 >= V_193 && V_191 < V_194 &&
V_192 > V_193 && V_192 <= V_194 ) ;
}
static int
F_47 ( struct V_32 * V_2 , struct V_33 * V_34 )
{
const struct V_37 * V_38 = & V_34 -> V_38 ;
unsigned long V_98 = V_2 -> V_12 . V_98 ;
int V_36 ;
int V_40 ;
if ( V_34 -> V_184 )
return 0 ;
V_40 = F_38 ( V_2 , V_34 ) ;
if ( V_40 )
return V_40 ;
F_29 ( V_38 , L_17 ) ;
V_40 = V_34 -> V_43 -> V_185 ( V_34 , V_2 -> V_157 , V_34 -> V_61 ) ;
F_48 ( V_34 -> V_61 , 0x10 ) ;
V_34 -> V_184 = F_44 ( V_2 , V_34 ) ;
if ( V_40 < 0 ) {
return V_40 ;
} else if ( V_40 > 0 ) {
F_9 ( V_38 , L_18 , V_40 ) ;
return - V_51 ;
}
F_29 ( V_38 , L_19 ) ;
if ( ! V_34 -> V_184 ) {
F_9 ( V_38 , L_20 ) ;
return - V_51 ;
}
F_23 (falcon_id, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
const struct V_59 * V_43 =
V_2 -> V_43 -> V_44 [ V_36 ] ;
if ( V_43 -> V_195 ) {
V_40 = V_43 -> V_195 ( & V_2 -> V_12 , V_34 ) ;
if ( V_40 )
return V_40 ;
}
}
return 0 ;
}
static int
F_49 ( struct V_32 * V_2 , struct V_33 * V_34 ,
unsigned long V_196 )
{
int V_166 ;
int V_40 ;
if ( ! ( V_196 & F_11 ( V_197 ) ) )
goto V_198;
V_40 = F_43 ( V_2 , V_34 ) ;
if ( V_40 )
return V_40 ;
V_40 = F_47 ( V_2 , V_34 ) ;
if ( V_40 )
return V_40 ;
V_198:
F_23 (falcon, &falcon_mask, NVKM_SECBOOT_FALCON_END) {
V_2 -> V_188 [ V_166 ] = V_199 ;
}
return 0 ;
}
static int
F_50 ( struct V_1 * V_164 , struct V_33 * V_34 ,
unsigned long V_196 )
{
struct V_32 * V_2 = V_32 ( V_164 ) ;
struct V_200 * V_201 ;
int V_166 ;
bool V_202 = V_34 -> V_184 ;
int V_40 ;
V_40 = F_47 ( V_2 , V_34 ) ;
if ( V_40 )
return V_40 ;
if ( ! F_51 ( V_34 , V_164 -> V_61 ) ) {
if ( V_202 )
return F_49 ( V_2 , V_34 , V_196 ) ;
else
return V_40 ;
}
switch ( V_164 -> V_61 ) {
case V_162 :
V_201 = V_34 -> V_38 . V_110 -> V_203 -> V_201 ;
break;
case V_204 :
V_201 = V_34 -> V_38 . V_110 -> V_205 -> V_201 ;
break;
default:
return - V_51 ;
}
F_23 (falcon, &falcon_mask, NVKM_SECBOOT_FALCON_END)
F_29 ( & V_34 -> V_38 , L_21 ,
V_50 [ V_166 ] ) ;
V_40 = F_52 ( V_201 , V_196 ) ;
if ( V_40 ) {
F_9 ( & V_34 -> V_38 , L_22 , V_40 ) ;
return V_40 ;
}
F_29 ( & V_34 -> V_38 , L_23 ) ;
return 0 ;
}
static int
F_53 ( struct V_1 * V_164 , struct V_33 * V_34 , bool V_206 )
{
struct V_32 * V_2 = V_32 ( V_164 ) ;
return F_43 ( V_2 , V_34 ) ;
}
static void
F_54 ( struct V_1 * V_164 )
{
struct V_32 * V_2 = V_32 ( V_164 ) ;
F_30 ( & V_2 -> V_159 ) ;
if ( V_164 -> V_61 != V_162 )
F_8 ( V_2 -> V_163 ) ;
F_8 ( V_2 -> V_161 ) ;
F_30 ( & V_2 -> V_157 ) ;
F_30 ( & V_2 -> V_111 ) ;
F_8 ( V_2 ) ;
}
static void
F_55 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 V_5 ,
void * V_6 )
{
const struct V_9 * V_10 = & V_4 -> V_11 ;
const struct V_207 * V_203 = V_2 -> V_38 -> V_110 -> V_203 ;
struct V_208 * V_8 = V_6 ;
T_1 V_12 ;
T_1 V_13 ;
T_1 V_14 ;
T_2 V_209 ;
V_12 = V_5 + V_4 -> V_15 + V_10 -> V_16 ;
V_13 = ( V_12 + V_10 -> V_17 ) >> 8 ;
V_14 = ( V_12 + V_10 -> V_18 ) >> 8 ;
V_209 = V_203 -> V_166 -> V_210 . V_179 ;
V_209 -= V_211 ;
V_8 -> V_212 = V_20 ;
V_8 -> V_21 = F_2 ( V_13 ) ;
V_8 -> V_22 = F_3 ( V_13 ) ;
V_8 -> V_213 = V_10 -> V_72 ;
V_8 -> V_214 = V_10 -> V_25 ;
V_8 -> V_26 = V_10 -> V_27 ;
V_8 -> V_28 = F_2 ( V_14 ) ;
V_8 -> V_29 = F_3 ( V_14 ) ;
V_8 -> V_30 = V_10 -> V_31 ;
V_8 -> V_215 = F_2 ( V_13 ) ;
V_8 -> V_216 = F_3 ( V_13 ) ;
V_8 -> V_217 = 1 ;
V_8 -> V_218 = V_209 ;
}
struct V_1 *
F_56 ( const struct V_219 * V_43 ,
enum V_35 V_61 ,
unsigned long V_98 )
{
struct V_32 * V_2 ;
int V_183 ;
F_23 (i, &managed_falcons, NVKM_SECBOOT_FALCON_END) {
if ( ! V_43 -> V_44 [ V_183 ] )
return F_6 ( - V_220 ) ;
}
V_2 = F_5 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return F_6 ( - V_42 ) ;
V_2 -> V_12 . V_61 = V_61 ;
V_2 -> V_12 . V_98 = V_98 ;
V_2 -> V_12 . V_43 = & V_221 ;
V_2 -> V_43 = V_43 ;
return & V_2 -> V_12 ;
}
struct V_1 *
F_57 ( unsigned long V_98 )
{
return F_56 ( & V_219 , V_162 ,
V_98 ) ;
}
