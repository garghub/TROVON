static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_1 , V_7 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_8 , T_1 V_9 )
{
if ( ( V_9 & 0xffff0000 ) == V_10 )
return V_11 [ V_9 & 0xffff ] [ V_8 -> V_12 -> type ] ;
return V_9 ;
}
static inline T_1 F_5 ( struct V_1 * V_8 , T_1 V_9 )
{
return F_6 ( V_8 -> V_13 + F_4 ( V_8 , V_9 ) ) ;
}
static inline void F_7 ( struct V_1 * V_8 ,
T_1 V_9 , T_2 V_14 )
{
F_8 ( V_14 , V_8 -> V_13 + F_4 ( V_8 , V_9 ) ) ;
}
static inline void F_9 ( struct V_1 * V_8 , T_1 V_9 ,
int V_15 , T_1 V_16 )
{
V_9 = F_4 ( V_8 , V_9 ) ;
while ( -- V_15 >= 0 ) {
F_8 ( V_16 & 0xff , V_8 -> V_13 + V_9 ) ;
V_16 >>= 8 ;
V_9 += 4 ;
}
}
static inline void F_10 ( struct V_1 * V_8 ,
T_1 V_9 , T_1 V_14 , T_1 V_17 )
{
T_1 V_18 ;
V_9 = F_4 ( V_8 , V_9 ) ;
V_18 = F_6 ( V_8 -> V_13 + V_9 ) ;
V_14 = ( V_14 & V_17 ) | ( V_18 & ~ V_17 ) ;
F_8 ( V_14 , V_8 -> V_13 + V_9 ) ;
}
static int F_11 ( struct V_1 * V_8 ,
T_1 V_19 , const T_2 * V_20 , T_1 V_21 )
{
if ( ( V_19 + V_21 ) > 32 )
return - V_22 ;
if ( V_8 -> V_23 ) {
int V_24 ;
V_24 = F_12 ( V_8 -> V_23 , V_20 , V_21 ) ;
if ( V_24 == V_21 )
return 0 ;
return V_24 ;
} else {
int V_25 ;
for ( V_25 = 0 ; V_25 < V_21 ; V_25 ++ )
F_8 ( V_20 [ V_25 ] , V_8 -> V_26 +
( ( V_19 + V_25 ) << 2 ) ) ;
return 0 ;
}
}
static int F_13 ( struct V_1 * V_8 )
{
int V_25 , V_24 ;
for ( V_25 = 0 ; V_25 < V_8 -> V_12 -> V_27 . V_28 ; ++ V_25 ) {
V_24 = F_14 ( V_8 -> V_27 [ V_25 ] ) ;
if ( ! V_24 )
continue;
F_15 ( V_8 -> V_29 , L_1 ,
V_8 -> V_12 -> V_27 . V_30 [ V_25 ] , V_24 ) ;
while ( V_25 -- )
F_16 ( V_8 -> V_27 [ V_25 ] ) ;
return V_24 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_8 )
{
int V_25 = V_8 -> V_12 -> V_27 . V_28 ;
while ( V_25 -- )
F_16 ( V_8 -> V_27 [ V_25 ] ) ;
}
static int F_18 ( struct V_1 * V_8 , bool V_31 )
{
struct V_32 * V_29 = V_8 -> V_29 ;
int V_24 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_8 -> V_12 -> V_33 . V_28 ; V_25 += 3 ) {
struct V_34 * * V_6 = & V_8 -> V_33 [ V_25 ] ;
V_24 = F_19 ( V_6 [ 2 ] , V_6 [ V_31 ] ) ;
if ( ! V_24 )
continue;
F_15 ( V_29 , L_2 ,
V_8 -> V_12 -> V_33 . V_30 [ V_25 + 2 ] ,
V_8 -> V_12 -> V_33 . V_30 [ V_25 + V_31 ] , V_24 ) ;
}
return V_24 ;
}
static T_2 F_20 ( struct V_1 * V_8 ,
T_1 V_35 , T_2 V_21 , T_1 V_36 )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < V_21 ; ++ V_25 )
V_36 += 0xff & F_5 ( V_8 , V_35 + V_25 * 4 ) ;
return ( T_2 ) ( ~ ( V_36 & 0xff ) + 1 ) ;
}
static void F_21 ( struct V_1 * V_8 ,
union V_37 * V_38 )
{
T_1 V_36 ;
T_2 V_39 ;
T_2 V_40 ;
if ( V_8 -> V_41 ) {
F_7 ( V_8 , V_42 ,
V_43 ) ;
F_7 ( V_8 , V_44 ,
V_45 ) ;
F_7 ( V_8 , V_46 , V_47 ) ;
return;
}
switch ( V_38 -> V_48 . type ) {
case V_49 :
F_7 ( V_8 , V_44 , V_50 ) ;
F_7 ( V_8 , V_51 , V_38 -> V_48 . type ) ;
F_7 ( V_8 , V_52 ,
V_38 -> V_48 . V_53 ) ;
F_7 ( V_8 , V_54 , V_38 -> V_48 . V_55 ) ;
V_36 = V_38 -> V_48 . type + V_38 -> V_48 . V_53 +
V_38 -> V_48 . V_55 ;
F_7 ( V_8 , F_22 ( 1 ) , 0 << 5 |
V_56 |
V_57 ) ;
V_40 = V_8 -> V_58 . V_59 ;
switch ( V_40 ) {
case V_60 :
V_40 |= V_61 ;
break;
case V_62 :
V_40 |= V_63 ;
break;
case V_64 :
default:
V_40 |= V_65 ;
break;
}
F_7 ( V_8 , F_22 ( 2 ) , V_40 ) ;
F_7 ( V_8 , F_22 ( 4 ) , V_8 -> V_66 ) ;
V_39 = F_20 ( V_8 , F_22 ( 1 ) ,
V_38 -> V_48 . V_55 , V_36 ) ;
F_23 ( L_3 , V_39 ) ;
F_7 ( V_8 , V_67 , V_39 ) ;
break;
case V_68 :
F_7 ( V_8 , V_46 , 0x02 ) ;
F_7 ( V_8 , V_69 , V_38 -> V_48 . type ) ;
F_7 ( V_8 , V_70 ,
V_38 -> V_48 . V_53 ) ;
F_7 ( V_8 , V_71 , V_38 -> V_48 . V_55 ) ;
V_36 = V_38 -> V_48 . type + V_38 -> V_48 . V_53 +
V_38 -> V_48 . V_55 ;
V_39 = F_20 ( V_8 , F_24 ( 1 ) ,
V_38 -> V_48 . V_55 , V_36 ) ;
F_23 ( L_4 , V_39 ) ;
F_7 ( V_8 , V_72 , V_39 ) ;
break;
default:
break;
}
}
static enum V_73 F_25 ( struct V_5 * V_7 ,
bool V_74 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
if ( F_26 ( V_8 -> V_75 ) )
return V_76 ;
return V_77 ;
}
static void F_27 ( struct V_5 * V_7 )
{
F_28 ( V_7 ) ;
F_29 ( V_7 ) ;
}
static int F_30 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_78 * V_78 ;
int V_24 ;
if ( ! V_8 -> V_79 )
return - V_80 ;
V_78 = F_31 ( V_7 , V_8 -> V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_8 -> V_41 = ! F_32 ( V_78 ) ;
F_23 ( L_5 ,
( V_8 -> V_41 ? L_6 : L_7 ) ,
V_78 -> V_81 , V_78 -> V_82 ) ;
F_33 ( V_7 , V_78 ) ;
V_24 = F_34 ( V_7 , V_78 ) ;
F_35 ( V_78 ) ;
return V_24 ;
}
static int F_36 ( struct V_1 * V_8 , T_1 V_83 )
{
const struct V_84 * V_85 = & V_8 -> V_12 -> V_86 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_85 -> V_28 ; V_25 ++ )
if ( V_85 -> V_30 [ V_25 ] . V_83 == V_83 )
return V_25 ;
F_23 ( L_8 , V_83 ) ;
return - V_22 ;
}
static int F_37 ( struct V_5 * V_7 ,
struct V_87 * V_88 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
int V_24 ;
F_23 ( L_9 ,
V_88 -> V_89 , V_88 -> V_90 , V_88 -> V_91 ,
( V_88 -> V_92 & V_93 ) ? true :
false , V_88 -> clock * 1000 ) ;
V_24 = F_36 ( V_8 , V_88 -> clock * 1000 ) ;
if ( V_24 < 0 )
return V_94 ;
return V_95 ;
}
static int F_38 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_5 * V_7 = & V_8 -> V_7 ;
int V_24 ;
V_7 -> V_96 = true ;
V_7 -> V_97 = V_98 ;
V_24 = F_39 ( V_8 -> V_99 , V_7 ,
& V_100 , V_101 ) ;
if ( V_24 ) {
F_40 ( L_10 ) ;
return V_24 ;
}
F_41 ( V_7 , & V_102 ) ;
F_42 ( V_7 ) ;
F_43 ( V_7 , V_4 ) ;
return 0 ;
}
static bool F_44 ( struct V_2 * V_4 ,
const struct V_87 * V_88 ,
struct V_87 * V_103 )
{
struct V_104 * V_29 = V_4 -> V_29 ;
struct V_5 * V_7 ;
struct V_87 * V_105 ;
int V_106 ;
F_45 ( V_103 , 0 ) ;
F_46 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_4 == V_4 )
break;
}
if ( V_7 -> V_4 != V_4 )
return true ;
V_106 = F_37 ( V_7 , V_103 ) ;
if ( V_106 == V_95 )
return true ;
F_46 (m, &connector->modes, head) {
V_106 = F_37 ( V_7 , V_105 ) ;
if ( V_106 == V_95 ) {
F_47 ( L_11 ) ;
F_47 ( L_12 ) ;
F_23 ( L_13 ,
V_105 -> V_89 , V_105 -> V_90 , V_105 -> V_91 ) ;
F_48 ( V_103 , V_105 ) ;
break;
}
}
return true ;
}
static void F_49 ( struct V_1 * V_8 , T_1 V_107 )
{
T_1 V_108 , V_109 ;
V_109 = ( V_107 % 9 ) ? 27000 : 30000 ;
V_108 = 128 * V_107 / ( 27000000 / V_109 ) ;
F_9 ( V_8 , V_110 , 3 , V_108 ) ;
F_9 ( V_8 , V_111 , 3 , V_109 ) ;
F_9 ( V_8 , V_112 , 3 , V_109 ) ;
F_7 ( V_8 , V_113 , 4 ) ;
}
static void F_50 ( struct V_1 * V_8 )
{
T_1 V_114 , V_115 ;
T_1 V_116 , V_117 , V_118 ;
T_1 V_16 ;
V_114 = 44100 ;
V_115 = 16 ;
switch ( V_115 ) {
case 20 :
V_116 = 2 ;
V_117 = 1 ;
break;
case 24 :
V_116 = 3 ;
V_117 = 1 ;
break;
default:
V_116 = 1 ;
V_117 = 0 ;
break;
}
F_49 ( V_8 , V_114 ) ;
F_7 ( V_8 , V_119 , V_120
| V_121 | V_122
| V_123 ) ;
F_7 ( V_8 , V_124 , V_125
| V_126 | V_127 ) ;
F_7 ( V_8 , V_128 , V_129 ) ;
V_118 = ( V_114 == 44100 ) ? 0 :
( V_114 == 48000 ) ? 2 :
( V_114 == 32000 ) ? 3 :
( V_114 == 96000 ) ? 0xa : 0x0 ;
F_7 ( V_8 , V_130 , V_131 ) ;
F_7 ( V_8 , V_130 , V_132 ) ;
V_16 = F_5 ( V_8 , V_133 ) | 0x01 ;
F_7 ( V_8 , V_133 , V_16 ) ;
F_7 ( V_8 , V_134 , F_51 ( 5 )
| F_52 ( 6 ) ) ;
F_7 ( V_8 , V_135 , F_53 ( 1 )
| F_54 ( 4 ) ) ;
F_7 ( V_8 , V_136 , F_55 ( 1 )
| F_54 ( 2 ) ) ;
F_7 ( V_8 , V_137 , F_56 ( 0 ) ) ;
F_7 ( V_8 , V_138 , V_139
| V_140 ) ;
F_7 ( V_8 , V_141 , V_142
| F_57 ( V_117 )
| F_58 ( V_116 )
| V_143 ) ;
F_7 ( V_8 , V_144 , V_145
| V_146
| V_147
| V_148
| V_149 ) ;
F_7 ( V_8 , V_150 , V_151 ) ;
F_7 ( V_8 , V_152 , F_59 ( 0 ) ) ;
F_7 ( V_8 , V_153 , V_154
| F_60 ( V_118 ) ) ;
F_7 ( V_8 , V_155 ,
V_156
| V_157
| V_158 ) ;
F_7 ( V_8 , V_159 , V_160 ) ;
}
static void F_61 ( struct V_1 * V_8 , bool V_161 )
{
if ( V_8 -> V_41 )
return;
F_7 ( V_8 , V_46 , V_161 ? 2 : 0 ) ;
F_10 ( V_8 , V_162 , V_161 ?
V_163 : V_164 , V_165 ) ;
}
static void F_62 ( struct V_1 * V_8 , bool V_35 )
{
T_1 V_16 = V_35 ? V_166 : 0 ;
if ( V_8 -> V_58 . V_92 & V_93 )
V_16 |= V_167 ;
F_10 ( V_8 , V_162 , V_16 , V_168 ) ;
F_10 ( V_8 , V_169 , V_16 , V_166 | V_167 ) ;
}
static void F_63 ( struct V_1 * V_8 )
{
union V_37 V_38 ;
F_10 ( V_8 , V_170 , 0 , V_171 |
V_172 | V_173 ) ;
F_10 ( V_8 , V_174 ,
V_175 , V_176 ) ;
F_7 ( V_8 , V_177 , 0 ) ;
F_10 ( V_8 , V_162 , 0 , V_178 ) ;
if ( V_8 -> V_41 ) {
F_10 ( V_8 , V_174 ,
V_179 , V_176 ) ;
F_7 ( V_8 , V_177 ,
V_180 | V_181 ) ;
}
if ( V_8 -> V_12 -> type == V_182 ) {
F_7 ( V_8 , V_183 , 0x12 ) ;
F_7 ( V_8 , V_184 , 0x34 ) ;
F_7 ( V_8 , V_185 , 0x56 ) ;
F_7 ( V_8 , V_186 , 0x02 ) ;
F_7 ( V_8 , F_64 ( 0 ) , 0 << 5 ) ;
F_10 ( V_8 , V_187 , 0x10 << 5 , 0x11 << 5 ) ;
F_7 ( V_8 , V_188 , 0x02 ) ;
F_7 ( V_8 , V_189 , 0x02 ) ;
F_7 ( V_8 , V_190 , 0x04 ) ;
} else {
V_38 . V_48 . type = V_49 ;
V_38 . V_48 . V_53 = V_191 ;
V_38 . V_48 . V_55 = V_192 ;
F_21 ( V_8 , & V_38 ) ;
V_38 . V_48 . type = V_68 ;
V_38 . V_48 . V_53 = V_193 ;
V_38 . V_48 . V_55 = V_194 ;
F_21 ( V_8 , & V_38 ) ;
F_10 ( V_8 , V_187 , 2 , 3 << 5 ) ;
}
}
static void F_65 ( struct V_1 * V_8 )
{
int V_195 ;
for ( V_195 = 0 ; V_195 < 10 ; ++ V_195 ) {
T_1 V_16 = F_5 ( V_8 , V_196 ) ;
if ( V_16 & V_197 ) {
F_23 ( L_14 , V_195 ) ;
return;
}
F_66 ( 10 , 20 ) ;
}
F_40 ( L_15 ) ;
}
static void F_67 ( struct V_1 * V_8 )
{
struct V_87 * V_105 = & V_8 -> V_58 ;
unsigned int V_16 ;
F_9 ( V_8 , V_198 , 2 , V_105 -> V_199 - V_105 -> V_89 ) ;
F_9 ( V_8 , V_200 , 3 ,
( V_105 -> V_199 << 12 ) | V_105 -> V_201 ) ;
V_16 = ( V_105 -> V_92 & V_202 ) ? 1 : 0 ;
F_9 ( V_8 , V_203 , 1 , V_16 ) ;
V_16 = ( V_105 -> V_92 & V_93 ) ? 1 : 0 ;
F_9 ( V_8 , V_204 , 1 , V_16 ) ;
V_16 = ( V_105 -> V_205 - V_105 -> V_89 - 2 ) ;
V_16 |= ( ( V_105 -> V_206 - V_105 -> V_89 - 2 ) << 10 ) ;
V_16 |= ( ( V_105 -> V_92 & V_207 ) ? 1 : 0 ) << 20 ;
F_9 ( V_8 , V_208 , 3 , V_16 ) ;
if ( V_105 -> V_92 & V_93 ) {
V_16 = ( ( V_105 -> V_209 - V_105 -> V_90 ) / 2 ) ;
V_16 |= ( ( V_105 -> V_210 - V_105 -> V_90 ) / 2 ) << 12 ;
F_9 ( V_8 , V_211 , 3 , V_16 ) ;
V_16 = V_105 -> V_201 / 2 ;
V_16 |= ( ( V_105 -> V_201 - V_105 -> V_90 ) / 2 ) << 11 ;
F_9 ( V_8 , V_212 , 3 , V_16 ) ;
V_16 = ( V_105 -> V_201 +
( ( V_105 -> V_209 - V_105 -> V_210 ) * 4 ) + 5 ) / 2 ;
V_16 |= V_105 -> V_201 << 11 ;
F_9 ( V_8 , V_213 , 3 , V_16 ) ;
V_16 = ( ( V_105 -> V_201 / 2 ) + 7 ) ;
V_16 |= ( ( V_105 -> V_201 / 2 ) + 2 ) << 12 ;
F_9 ( V_8 , V_214 , 3 , V_16 ) ;
V_16 = ( ( V_105 -> V_199 / 2 ) + ( V_105 -> V_205 - V_105 -> V_89 ) ) ;
V_16 |= ( ( V_105 -> V_199 / 2 ) +
( V_105 -> V_205 - V_105 -> V_89 ) ) << 12 ;
F_9 ( V_8 , V_215 , 3 , V_16 ) ;
F_9 ( V_8 , V_216 , 2 ,
( V_105 -> V_201 - V_105 -> V_90 ) / 2 ) ;
F_9 ( V_8 , V_217 , 2 , V_105 -> V_90 / 2 ) ;
F_9 ( V_8 , V_218 , 2 , 0x249 ) ;
} else {
V_16 = V_105 -> V_201 ;
V_16 |= ( V_105 -> V_201 - V_105 -> V_90 ) << 11 ;
F_9 ( V_8 , V_212 , 3 , V_16 ) ;
F_9 ( V_8 , V_213 , 3 , 0 ) ;
V_16 = ( V_105 -> V_209 - V_105 -> V_90 ) ;
V_16 |= ( ( V_105 -> V_210 - V_105 -> V_90 ) << 12 ) ;
F_9 ( V_8 , V_211 , 3 , V_16 ) ;
F_9 ( V_8 , V_214 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_215 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_216 , 2 ,
V_105 -> V_201 - V_105 -> V_90 ) ;
F_9 ( V_8 , V_217 , 2 , V_105 -> V_90 ) ;
}
F_9 ( V_8 , V_219 , 2 , V_105 -> V_199 ) ;
F_9 ( V_8 , V_220 , 2 , V_105 -> V_199 - V_105 -> V_89 ) ;
F_9 ( V_8 , V_221 , 2 , V_105 -> V_89 ) ;
F_9 ( V_8 , V_222 , 2 , V_105 -> V_201 ) ;
}
static void F_68 ( struct V_1 * V_8 )
{
struct V_87 * V_105 = & V_8 -> V_58 ;
F_9 ( V_8 , V_198 , 2 , V_105 -> V_199 - V_105 -> V_89 ) ;
F_9 ( V_8 , V_223 , 2 , V_105 -> V_201 ) ;
F_9 ( V_8 , V_224 , 2 , V_105 -> V_199 ) ;
F_9 ( V_8 , V_225 , 1 ,
( V_105 -> V_92 & V_207 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_203 , 1 ,
( V_105 -> V_92 & V_202 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_204 , 1 ,
( V_105 -> V_92 & V_93 ) ? 1 : 0 ) ;
if ( V_105 -> V_92 & V_93 ) {
F_9 ( V_8 , V_226 , 2 ,
( V_105 -> V_209 - V_105 -> V_90 ) / 2 ) ;
F_9 ( V_8 , V_227 , 2 ,
( V_105 -> V_210 - V_105 -> V_90 ) / 2 ) ;
F_9 ( V_8 , V_228 , 2 , V_105 -> V_201 / 2 ) ;
F_9 ( V_8 , V_229 , 2 ,
( V_105 -> V_201 - V_105 -> V_90 ) / 2 ) ;
F_9 ( V_8 , V_230 , 2 ,
V_105 -> V_201 - V_105 -> V_90 / 2 ) ;
F_9 ( V_8 , V_231 , 2 , V_105 -> V_201 ) ;
F_9 ( V_8 , V_232 , 2 ,
( V_105 -> V_201 / 2 ) + 7 ) ;
F_9 ( V_8 , V_233 , 2 ,
( V_105 -> V_201 / 2 ) + 2 ) ;
F_9 ( V_8 , V_234 , 2 ,
( V_105 -> V_199 / 2 ) + ( V_105 -> V_205 - V_105 -> V_89 ) ) ;
F_9 ( V_8 , V_235 , 2 ,
( V_105 -> V_199 / 2 ) + ( V_105 -> V_205 - V_105 -> V_89 ) ) ;
F_9 ( V_8 , V_216 , 2 ,
( V_105 -> V_201 - V_105 -> V_90 ) / 2 ) ;
F_9 ( V_8 , V_217 , 2 , V_105 -> V_90 / 2 ) ;
F_9 ( V_8 , V_218 , 2 ,
V_105 -> V_201 - V_105 -> V_90 / 2 ) ;
F_9 ( V_8 , V_236 , 2 ,
( V_105 -> V_201 / 2 ) + 1 ) ;
F_9 ( V_8 , V_237 , 2 ,
( V_105 -> V_201 / 2 ) + 1 ) ;
F_9 ( V_8 , V_238 , 2 ,
( V_105 -> V_201 / 2 ) + 1 ) ;
F_9 ( V_8 , V_239 , 2 , 0x0 ) ;
F_9 ( V_8 , V_240 , 2 , 0x0 ) ;
} else {
F_9 ( V_8 , V_226 , 2 ,
V_105 -> V_209 - V_105 -> V_90 ) ;
F_9 ( V_8 , V_227 , 2 ,
V_105 -> V_210 - V_105 -> V_90 ) ;
F_9 ( V_8 , V_228 , 2 , V_105 -> V_201 ) ;
F_9 ( V_8 , V_229 , 2 ,
V_105 -> V_201 - V_105 -> V_90 ) ;
F_9 ( V_8 , V_230 , 2 , 0xffff ) ;
F_9 ( V_8 , V_231 , 2 , 0xffff ) ;
F_9 ( V_8 , V_232 , 2 , 0xffff ) ;
F_9 ( V_8 , V_233 , 2 , 0xffff ) ;
F_9 ( V_8 , V_234 , 2 , 0xffff ) ;
F_9 ( V_8 , V_235 , 2 , 0xffff ) ;
F_9 ( V_8 , V_216 , 2 ,
V_105 -> V_201 - V_105 -> V_90 ) ;
F_9 ( V_8 , V_217 , 2 , V_105 -> V_90 ) ;
}
F_9 ( V_8 , V_241 , 2 ,
V_105 -> V_205 - V_105 -> V_89 - 2 ) ;
F_9 ( V_8 , V_242 , 2 ,
V_105 -> V_206 - V_105 -> V_89 - 2 ) ;
F_9 ( V_8 , V_243 , 2 , 0xffff ) ;
F_9 ( V_8 , V_244 , 2 , 0xffff ) ;
F_9 ( V_8 , V_245 , 2 , 0xffff ) ;
F_9 ( V_8 , V_246 , 2 , 0xffff ) ;
F_9 ( V_8 , V_247 , 2 , 0xffff ) ;
F_9 ( V_8 , V_248 , 2 , 0xffff ) ;
F_9 ( V_8 , V_249 , 2 , 0xffff ) ;
F_9 ( V_8 , V_250 , 2 , 0xffff ) ;
F_9 ( V_8 , V_251 , 2 , 0xffff ) ;
F_9 ( V_8 , V_252 , 2 , 0xffff ) ;
F_9 ( V_8 , V_253 , 2 , 0xffff ) ;
F_9 ( V_8 , V_254 , 2 , 0xffff ) ;
F_9 ( V_8 , V_255 , 2 , 0xffff ) ;
F_9 ( V_8 , V_256 , 2 , 0xffff ) ;
F_9 ( V_8 , V_257 , 2 , 0xffff ) ;
F_9 ( V_8 , V_258 , 2 , 0xffff ) ;
F_9 ( V_8 , V_259 , 2 , 0xffff ) ;
F_9 ( V_8 , V_260 , 2 , 0xffff ) ;
F_9 ( V_8 , V_219 , 2 , V_105 -> V_199 ) ;
F_9 ( V_8 , V_220 , 2 , V_105 -> V_199 - V_105 -> V_89 ) ;
F_9 ( V_8 , V_221 , 2 , V_105 -> V_89 ) ;
F_9 ( V_8 , V_222 , 2 , V_105 -> V_201 ) ;
if ( V_8 -> V_12 == & V_261 )
F_7 ( V_8 , V_262 , 1 ) ;
}
static void F_69 ( struct V_1 * V_8 )
{
if ( V_8 -> V_12 -> type == V_182 )
F_67 ( V_8 ) ;
else
F_68 ( V_8 ) ;
F_62 ( V_8 , true ) ;
}
static void F_70 ( struct V_1 * V_8 )
{
F_10 ( V_8 , V_263 , 0 , 1 ) ;
F_66 ( 10000 , 12000 ) ;
F_10 ( V_8 , V_263 , ~ 0 , 1 ) ;
F_66 ( 10000 , 12000 ) ;
F_10 ( V_8 , V_264 , ~ 0 , V_265 ) ;
F_66 ( 10000 , 12000 ) ;
F_10 ( V_8 , V_264 , 0 , V_265 ) ;
F_66 ( 10000 , 12000 ) ;
}
static void F_71 ( struct V_1 * V_8 , bool V_266 )
{
T_2 V_267 = V_266 ? V_268 : V_269 ;
if ( V_8 -> V_12 == & V_261 )
F_8 ( V_267 , V_8 -> V_26 + V_270 ) ;
}
static void F_72 ( struct V_1 * V_8 )
{
int V_24 ;
const T_2 * V_271 ;
V_24 = F_36 ( V_8 , V_8 -> V_58 . clock * 1000 ) ;
if ( V_24 < 0 ) {
F_40 ( L_16 ) ;
return;
}
V_271 = V_8 -> V_12 -> V_86 . V_30 [ V_24 ] . V_272 ;
F_18 ( V_8 , false ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 , true ) ;
V_24 = F_11 ( V_8 , 0 , V_271 , 32 ) ;
if ( V_24 ) {
F_40 ( L_17 ) ;
return;
}
F_71 ( V_8 , false ) ;
F_18 ( V_8 , true ) ;
F_66 ( 10000 , 12000 ) ;
F_65 ( V_8 ) ;
}
static void F_73 ( struct V_1 * V_8 )
{
F_62 ( V_8 , false ) ;
F_63 ( V_8 ) ;
F_50 ( V_8 ) ;
F_69 ( V_8 ) ;
F_61 ( V_8 , true ) ;
}
static void F_74 ( struct V_2 * V_4 ,
struct V_87 * V_88 ,
struct V_87 * V_103 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_87 * V_105 = V_103 ;
F_23 ( L_18 ,
V_105 -> V_89 , V_105 -> V_90 ,
V_105 -> V_91 , ( V_105 -> V_92 & V_93 ) ?
L_19 : L_20 ) ;
F_48 ( & V_8 -> V_58 , V_105 ) ;
V_8 -> V_66 = F_75 ( V_88 ) ;
}
static void F_76 ( struct V_1 * V_8 , bool V_273 )
{
if ( ! V_8 -> V_274 )
return;
F_77 ( V_8 -> V_274 , V_275 ,
V_276 , V_273 ? ~ 0 : 0 ) ;
}
static void F_78 ( struct V_1 * V_8 )
{
if ( V_8 -> V_277 )
return;
F_79 ( V_8 -> V_29 ) ;
if ( F_80 ( F_81 ( V_278 ) , V_8 -> V_279 ) )
F_23 ( L_21 ) ;
F_77 ( V_8 -> V_280 , V_281 ,
V_282 , 1 ) ;
F_76 ( V_8 , true ) ;
F_10 ( V_8 , V_283 , 0 , V_284 ) ;
F_72 ( V_8 ) ;
V_8 -> V_277 = true ;
}
static void F_82 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_277 )
return;
F_10 ( V_8 , V_162 , 0 , V_168 ) ;
F_10 ( V_8 , V_283 , ~ 0 , V_284 ) ;
F_76 ( V_8 , false ) ;
F_77 ( V_8 -> V_280 , V_281 ,
V_282 , 0 ) ;
F_83 ( F_81 ( V_278 ) , V_8 -> V_279 ) ;
F_84 ( V_8 -> V_29 ) ;
V_8 -> V_277 = false ;
}
static void F_85 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_78 ( V_8 ) ;
F_73 ( V_8 ) ;
}
static void F_86 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_285 * V_286 = V_4 -> V_286 ;
const struct V_287 * V_288 = NULL ;
if ( ! V_8 -> V_277 )
return;
if ( V_286 )
V_288 = V_286 -> V_289 ;
if ( V_288 && V_288 -> V_290 )
(* V_288 -> V_290 )( V_286 ) ;
F_87 ( & V_8 -> V_291 ) ;
F_82 ( V_8 ) ;
}
static void F_88 ( struct V_292 * V_293 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( V_293 , struct V_1 , V_291 . V_293 ) ;
if ( V_8 -> V_99 )
F_89 ( V_8 -> V_99 ) ;
}
static T_3 F_90 ( int V_294 , void * V_295 )
{
struct V_1 * V_8 = V_295 ;
F_91 ( V_296 , & V_8 -> V_291 ,
F_92 ( V_297 ) ) ;
return V_298 ;
}
static int F_93 ( struct V_1 * V_8 ,
const struct V_299 * V_300 ,
struct V_34 * * V_301 )
{
struct V_32 * V_29 = V_8 -> V_29 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_300 -> V_28 ; ++ V_25 ) {
struct V_34 * V_34 = F_94 ( V_29 , V_300 -> V_30 [ V_25 ] ) ;
if ( F_95 ( V_34 ) ) {
int V_24 = F_96 ( V_34 ) ;
F_15 ( V_29 , L_22 ,
V_300 -> V_30 [ V_25 ] , V_24 ) ;
return V_24 ;
}
V_301 [ V_25 ] = V_34 ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_8 )
{
const struct V_302 * V_12 = V_8 -> V_12 ;
int V_28 = V_12 -> V_27 . V_28 + V_12 -> V_33 . V_28 ;
struct V_32 * V_29 = V_8 -> V_29 ;
struct V_34 * * V_301 ;
int V_24 ;
if ( ! V_28 )
return 0 ;
V_301 = F_98 ( V_29 , sizeof( * V_301 ) * V_28 , V_303 ) ;
if ( ! V_301 )
return - V_304 ;
V_8 -> V_27 = V_301 ;
V_8 -> V_33 = V_301 + V_12 -> V_27 . V_28 ;
V_24 = F_93 ( V_8 , & V_12 -> V_27 , V_8 -> V_27 ) ;
if ( V_24 )
return V_24 ;
return F_93 ( V_8 , & V_12 -> V_33 , V_8 -> V_33 ) ;
}
static void F_99 ( struct V_305 * V_34 , bool V_266 )
{
struct V_1 * V_8 = F_2 ( V_34 , struct V_1 ,
V_306 ) ;
if ( V_266 )
F_78 ( V_8 ) ;
else
F_82 ( V_8 ) ;
}
static int F_100 ( struct V_1 * V_8 )
{
struct V_32 * V_29 = V_8 -> V_29 ;
int V_25 , V_24 ;
F_23 ( L_23 ) ;
V_8 -> V_75 = F_101 ( V_29 , L_24 , V_307 ) ;
if ( F_95 ( V_8 -> V_75 ) ) {
F_40 ( L_25 ) ;
return F_96 ( V_8 -> V_75 ) ;
}
V_8 -> V_294 = F_102 ( V_8 -> V_75 ) ;
if ( V_8 -> V_294 < 0 ) {
F_40 ( L_26 ) ;
return V_8 -> V_294 ;
}
V_24 = F_97 ( V_8 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_18 ( V_8 , false ) ;
if ( V_24 )
return V_24 ;
for ( V_25 = 0 ; V_25 < F_81 ( V_278 ) ; ++ V_25 )
V_8 -> V_279 [ V_25 ] . V_278 = V_278 [ V_25 ] ;
V_24 = F_103 ( V_29 , F_81 ( V_278 ) , V_8 -> V_279 ) ;
if ( V_24 ) {
if ( V_24 != - V_308 )
F_40 ( L_27 ) ;
return V_24 ;
}
V_8 -> V_309 = F_104 ( V_29 , L_28 ) ;
if ( F_96 ( V_8 -> V_309 ) == - V_80 )
return 0 ;
if ( F_95 ( V_8 -> V_309 ) )
return F_96 ( V_8 -> V_309 ) ;
V_24 = F_105 ( V_8 -> V_309 ) ;
if ( V_24 )
F_40 ( L_29 ) ;
return V_24 ;
}
static int F_106 ( struct V_32 * V_29 , struct V_32 * V_310 , void * V_30 )
{
struct V_104 * V_99 = V_30 ;
struct V_1 * V_8 = F_107 ( V_29 ) ;
struct V_2 * V_4 = & V_8 -> V_4 ;
int V_24 , V_311 ;
V_8 -> V_99 = V_99 ;
V_311 = F_108 ( V_99 ,
V_312 ) ;
if ( V_311 < 0 )
return V_311 ;
V_8 -> V_306 . V_266 = F_99 ;
F_109 ( V_99 , V_311 ) -> V_313 = & V_8 -> V_306 ;
V_4 -> V_314 = 1 << V_311 ;
F_23 ( L_30 , V_4 -> V_314 ) ;
F_110 ( V_99 , V_4 , & V_315 ,
V_316 , NULL ) ;
F_111 ( V_4 , & V_317 ) ;
V_24 = F_38 ( V_4 ) ;
if ( V_24 ) {
F_40 ( L_31 , V_24 ) ;
F_112 ( V_4 ) ;
return V_24 ;
}
return 0 ;
}
static void F_113 ( struct V_32 * V_29 , struct V_32 * V_310 , void * V_30 )
{
}
static int F_114 ( struct V_1 * V_8 )
{
const char * V_318 = L_32 ;
struct V_319 * V_320 ;
struct V_321 * V_322 ;
V_320 = F_115 ( NULL , NULL , V_318 ) ;
if ( V_320 )
V_320 = F_116 ( V_320 ) ;
else
V_320 = F_117 ( V_8 -> V_29 -> V_323 , L_33 , 0 ) ;
if ( ! V_320 ) {
F_40 ( L_34 ) ;
return - V_80 ;
}
V_322 = F_118 ( V_320 ) ;
F_119 ( V_320 ) ;
if ( ! V_322 ) {
F_47 ( L_35 ) ;
return - V_308 ;
}
V_8 -> V_79 = V_322 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_8 )
{
const char * V_318 = L_36 ;
struct V_319 * V_320 ;
int V_24 = 0 ;
V_320 = F_115 ( NULL , NULL , V_318 ) ;
if ( ! V_320 ) {
V_320 = F_117 ( V_8 -> V_29 -> V_323 , L_37 , 0 ) ;
if ( ! V_320 ) {
F_40 ( L_38 ) ;
return - V_80 ;
}
}
if ( V_8 -> V_12 -> V_324 ) {
V_8 -> V_26 = F_121 ( V_320 , 0 ) ;
if ( ! V_8 -> V_26 ) {
F_40 ( L_39 ) ;
V_24 = - V_304 ;
goto V_325;
}
} else {
V_8 -> V_23 = F_122 ( V_320 ) ;
if ( ! V_8 -> V_23 ) {
F_47 ( L_40 ) ;
V_24 = - V_308 ;
goto V_325;
}
}
V_325:
F_119 ( V_320 ) ;
return V_24 ;
}
static int F_123 ( struct V_326 * V_327 )
{
struct V_32 * V_29 = & V_327 -> V_29 ;
struct V_1 * V_8 ;
struct V_328 * V_329 ;
int V_24 ;
V_8 = F_98 ( V_29 , sizeof( struct V_1 ) , V_303 ) ;
if ( ! V_8 )
return - V_304 ;
V_8 -> V_12 = F_124 ( V_29 ) ;
F_125 ( V_327 , V_8 ) ;
V_8 -> V_29 = V_29 ;
V_24 = F_100 ( V_8 ) ;
if ( V_24 ) {
if ( V_24 != - V_308 )
F_40 ( L_41 ) ;
return V_24 ;
}
V_329 = F_126 ( V_327 , V_330 , 0 ) ;
V_8 -> V_13 = F_127 ( V_29 , V_329 ) ;
if ( F_95 ( V_8 -> V_13 ) ) {
V_24 = F_96 ( V_8 -> V_13 ) ;
return V_24 ;
}
V_24 = F_114 ( V_8 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_120 ( V_8 ) ;
if ( V_24 )
goto V_331;
F_128 ( & V_8 -> V_291 , F_88 ) ;
V_24 = F_129 ( V_29 , V_8 -> V_294 , NULL ,
F_90 , V_332 |
V_333 | V_334 ,
L_42 , V_8 ) ;
if ( V_24 ) {
F_40 ( L_43 ) ;
goto V_335;
}
V_8 -> V_280 = F_130 ( V_29 -> V_323 ,
L_44 ) ;
if ( F_95 ( V_8 -> V_280 ) ) {
F_40 ( L_45 ) ;
V_24 = - V_308 ;
goto V_335;
}
if ( V_8 -> V_12 -> V_336 ) {
V_8 -> V_274 = F_130 ( V_29 -> V_323 ,
L_46 ) ;
if ( F_95 ( V_8 -> V_274 ) ) {
F_40 ( L_47 ) ;
V_24 = - V_308 ;
goto V_335;
}
}
F_131 ( V_29 ) ;
V_24 = F_132 ( & V_327 -> V_29 , & V_337 ) ;
if ( V_24 )
goto V_338;
return V_24 ;
V_338:
F_133 ( V_29 ) ;
V_335:
if ( V_8 -> V_23 )
F_134 ( & V_8 -> V_23 -> V_29 ) ;
if ( V_8 -> V_26 )
F_135 ( V_8 -> V_26 ) ;
V_331:
F_134 ( & V_8 -> V_79 -> V_29 ) ;
return V_24 ;
}
static int F_136 ( struct V_326 * V_327 )
{
struct V_1 * V_8 = F_137 ( V_327 ) ;
F_138 ( & V_8 -> V_291 ) ;
F_139 ( & V_327 -> V_29 , & V_337 ) ;
F_133 ( & V_327 -> V_29 ) ;
if ( ! F_95 ( V_8 -> V_309 ) )
F_140 ( V_8 -> V_309 ) ;
if ( V_8 -> V_23 )
F_134 ( & V_8 -> V_23 -> V_29 ) ;
if ( V_8 -> V_26 )
F_135 ( V_8 -> V_26 ) ;
F_134 ( & V_8 -> V_79 -> V_29 ) ;
return 0 ;
}
static int F_141 ( struct V_32 * V_29 )
{
struct V_1 * V_8 = F_107 ( V_29 ) ;
F_17 ( V_8 ) ;
return 0 ;
}
static int F_142 ( struct V_32 * V_29 )
{
struct V_1 * V_8 = F_107 ( V_29 ) ;
int V_24 ;
V_24 = F_13 ( V_8 ) ;
if ( V_24 < 0 )
return V_24 ;
return 0 ;
}
