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
static inline void F_10 ( struct V_1 * V_8 , T_1 V_9 ,
T_2 * V_17 , int V_18 )
{
for ( V_9 = F_4 ( V_8 , V_9 ) ; V_18 ; -- V_18 , V_9 += 4 )
F_8 ( * V_17 ++ , V_8 -> V_13 + V_9 ) ;
}
static inline void F_11 ( struct V_1 * V_8 ,
T_1 V_9 , T_1 V_14 , T_1 V_19 )
{
T_1 V_20 ;
V_9 = F_4 ( V_8 , V_9 ) ;
V_20 = F_6 ( V_8 -> V_13 + V_9 ) ;
V_14 = ( V_14 & V_19 ) | ( V_20 & ~ V_19 ) ;
F_8 ( V_14 , V_8 -> V_13 + V_9 ) ;
}
static int F_12 ( struct V_1 * V_8 ,
T_1 V_21 , const T_2 * V_17 , T_1 V_22 )
{
if ( ( V_21 + V_22 ) > 32 )
return - V_23 ;
if ( V_8 -> V_24 ) {
int V_25 ;
V_25 = F_13 ( V_8 -> V_24 , V_17 , V_22 ) ;
if ( V_25 == V_22 )
return 0 ;
return V_25 ;
} else {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ )
F_8 ( V_17 [ V_26 ] , V_8 -> V_27 +
( ( V_21 + V_26 ) << 2 ) ) ;
return 0 ;
}
}
static int F_14 ( struct V_1 * V_8 )
{
int V_26 , V_25 ;
for ( V_26 = 0 ; V_26 < V_8 -> V_12 -> V_28 . V_29 ; ++ V_26 ) {
V_25 = F_15 ( V_8 -> V_28 [ V_26 ] ) ;
if ( ! V_25 )
continue;
F_16 ( V_8 -> V_30 , L_1 ,
V_8 -> V_12 -> V_28 . V_31 [ V_26 ] , V_25 ) ;
while ( V_26 -- )
F_17 ( V_8 -> V_28 [ V_26 ] ) ;
return V_25 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_8 )
{
int V_26 = V_8 -> V_12 -> V_28 . V_29 ;
while ( V_26 -- )
F_17 ( V_8 -> V_28 [ V_26 ] ) ;
}
static int F_19 ( struct V_1 * V_8 , bool V_32 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_25 = 0 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_8 -> V_12 -> V_34 . V_29 ; V_26 += 3 ) {
struct V_35 * * V_6 = & V_8 -> V_34 [ V_26 ] ;
V_25 = F_20 ( V_6 [ 2 ] , V_6 [ V_32 ] ) ;
if ( ! V_25 )
continue;
F_16 ( V_30 , L_2 ,
V_8 -> V_12 -> V_34 . V_31 [ V_26 + 2 ] ,
V_8 -> V_12 -> V_34 . V_31 [ V_26 + V_32 ] , V_25 ) ;
}
return V_25 ;
}
static void F_21 ( struct V_1 * V_8 )
{
union V_36 V_37 ;
T_2 V_17 [ 25 ] ;
int V_25 ;
if ( V_8 -> V_38 ) {
F_7 ( V_8 , V_39 ,
V_40 ) ;
F_7 ( V_8 , V_41 ,
V_42 ) ;
F_7 ( V_8 , V_43 , V_44 ) ;
return;
}
V_25 = F_22 ( & V_37 . V_45 ,
& V_8 -> V_46 ) ;
if ( ! V_25 )
V_25 = F_23 ( & V_37 . V_45 , V_17 , sizeof( V_17 ) ) ;
if ( V_25 > 0 ) {
F_7 ( V_8 , V_39 , V_47 ) ;
F_10 ( V_8 , V_48 , V_17 , V_25 ) ;
} else {
F_24 ( L_3 , V_49 , V_25 ) ;
}
V_25 = F_25 ( & V_37 . V_50 . V_51 ,
& V_8 -> V_46 ) ;
if ( ! V_25 )
V_25 = F_26 ( & V_37 . V_50 . V_51 , V_17 ,
sizeof( V_17 ) ) ;
if ( V_25 > 0 ) {
F_7 ( V_8 , V_41 , V_52 ) ;
F_10 ( V_8 , V_53 , V_17 , V_25 ) ;
}
V_25 = F_27 ( & V_37 . V_54 ) ;
if ( ! V_25 ) {
V_37 . V_54 . V_55 = 2 ;
V_25 = F_28 ( & V_37 . V_54 , V_17 , sizeof( V_17 ) ) ;
}
if ( V_25 > 0 ) {
F_7 ( V_8 , V_43 , V_56 ) ;
F_10 ( V_8 , V_57 , V_17 , V_25 ) ;
}
}
static enum V_58 F_29 ( struct V_5 * V_7 ,
bool V_59 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
if ( F_30 ( V_8 -> V_60 ) )
return V_61 ;
return V_62 ;
}
static void F_31 ( struct V_5 * V_7 )
{
F_32 ( V_7 ) ;
F_33 ( V_7 ) ;
}
static int F_34 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_63 * V_63 ;
int V_25 ;
if ( ! V_8 -> V_64 )
return - V_65 ;
V_63 = F_35 ( V_7 , V_8 -> V_64 ) ;
if ( ! V_63 )
return - V_65 ;
V_8 -> V_38 = ! F_36 ( V_63 ) ;
F_37 ( L_4 ,
( V_8 -> V_38 ? L_5 : L_6 ) ,
V_63 -> V_66 , V_63 -> V_67 ) ;
F_38 ( V_7 , V_63 ) ;
V_25 = F_39 ( V_7 , V_63 ) ;
F_40 ( V_63 ) ;
return V_25 ;
}
static int F_41 ( struct V_1 * V_8 , T_1 V_68 )
{
const struct V_69 * V_70 = & V_8 -> V_12 -> V_71 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_70 -> V_29 ; V_26 ++ )
if ( V_70 -> V_31 [ V_26 ] . V_68 == V_68 )
return V_26 ;
F_37 ( L_7 , V_68 ) ;
return - V_23 ;
}
static int F_42 ( struct V_5 * V_7 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
int V_25 ;
F_37 ( L_8 ,
V_73 -> V_74 , V_73 -> V_75 , V_73 -> V_76 ,
( V_73 -> V_77 & V_78 ) ? true :
false , V_73 -> clock * 1000 ) ;
V_25 = F_41 ( V_8 , V_73 -> clock * 1000 ) ;
if ( V_25 < 0 )
return V_79 ;
return V_80 ;
}
static int F_43 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_5 * V_7 = & V_8 -> V_7 ;
int V_25 ;
V_7 -> V_81 = true ;
V_7 -> V_82 = V_83 ;
V_25 = F_44 ( V_8 -> V_84 , V_7 ,
& V_85 , V_86 ) ;
if ( V_25 ) {
F_45 ( L_9 ) ;
return V_25 ;
}
F_46 ( V_7 , & V_87 ) ;
F_47 ( V_7 ) ;
F_48 ( V_7 , V_4 ) ;
return 0 ;
}
static bool F_49 ( struct V_2 * V_4 ,
const struct V_72 * V_73 ,
struct V_72 * V_88 )
{
struct V_89 * V_30 = V_4 -> V_30 ;
struct V_5 * V_7 ;
struct V_72 * V_90 ;
int V_91 ;
F_50 ( V_88 , 0 ) ;
F_51 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_4 == V_4 )
break;
}
if ( V_7 -> V_4 != V_4 )
return true ;
V_91 = F_42 ( V_7 , V_88 ) ;
if ( V_91 == V_80 )
return true ;
F_51 (m, &connector->modes, head) {
V_91 = F_42 ( V_7 , V_90 ) ;
if ( V_91 == V_80 ) {
F_24 ( L_10 ) ;
F_24 ( L_11 ) ;
F_37 ( L_12 ,
V_90 -> V_74 , V_90 -> V_75 , V_90 -> V_76 ) ;
F_52 ( V_88 , V_90 ) ;
break;
}
}
return true ;
}
static void F_53 ( struct V_1 * V_8 , T_1 V_92 )
{
T_1 V_93 , V_94 ;
V_94 = ( V_92 % 9 ) ? 27000 : 30000 ;
V_93 = 128 * V_92 / ( 27000000 / V_94 ) ;
F_9 ( V_8 , V_95 , 3 , V_93 ) ;
F_9 ( V_8 , V_96 , 3 , V_94 ) ;
F_9 ( V_8 , V_97 , 3 , V_94 ) ;
F_7 ( V_8 , V_98 , 4 ) ;
}
static void F_54 ( struct V_1 * V_8 )
{
T_1 V_99 , V_100 ;
T_1 V_101 , V_102 , V_103 ;
T_1 V_16 ;
V_99 = 44100 ;
V_100 = 16 ;
switch ( V_100 ) {
case 20 :
V_101 = 2 ;
V_102 = 1 ;
break;
case 24 :
V_101 = 3 ;
V_102 = 1 ;
break;
default:
V_101 = 1 ;
V_102 = 0 ;
break;
}
F_53 ( V_8 , V_99 ) ;
F_7 ( V_8 , V_104 , V_105
| V_106 | V_107
| V_108 ) ;
F_7 ( V_8 , V_109 , V_110
| V_111 | V_112 ) ;
F_7 ( V_8 , V_113 , V_114 ) ;
V_103 = ( V_99 == 44100 ) ? 0 :
( V_99 == 48000 ) ? 2 :
( V_99 == 32000 ) ? 3 :
( V_99 == 96000 ) ? 0xa : 0x0 ;
F_7 ( V_8 , V_115 , V_116 ) ;
F_7 ( V_8 , V_115 , V_117 ) ;
V_16 = F_5 ( V_8 , V_118 ) | 0x01 ;
F_7 ( V_8 , V_118 , V_16 ) ;
F_7 ( V_8 , V_119 , F_55 ( 5 )
| F_56 ( 6 ) ) ;
F_7 ( V_8 , V_120 , F_57 ( 1 )
| F_58 ( 4 ) ) ;
F_7 ( V_8 , V_121 , F_59 ( 1 )
| F_58 ( 2 ) ) ;
F_7 ( V_8 , V_122 , F_60 ( 0 ) ) ;
F_7 ( V_8 , V_123 , V_124
| V_125 ) ;
F_7 ( V_8 , V_126 , V_127
| F_61 ( V_102 )
| F_62 ( V_101 )
| V_128 ) ;
F_7 ( V_8 , V_129 , V_130
| V_131
| V_132
| V_133
| V_134 ) ;
F_7 ( V_8 , V_135 , V_136 ) ;
F_7 ( V_8 , V_137 , F_63 ( 0 ) ) ;
F_7 ( V_8 , V_138 , V_139
| F_64 ( V_103 ) ) ;
F_7 ( V_8 , V_140 ,
V_141
| V_142
| V_143 ) ;
F_7 ( V_8 , V_144 , V_145 ) ;
}
static void F_65 ( struct V_1 * V_8 , bool V_146 )
{
if ( V_8 -> V_38 )
return;
F_7 ( V_8 , V_43 , V_146 ? 2 : 0 ) ;
F_11 ( V_8 , V_147 , V_146 ?
V_148 : V_149 , V_150 ) ;
}
static void F_66 ( struct V_1 * V_8 , bool V_151 )
{
T_1 V_16 = V_151 ? V_152 : 0 ;
if ( V_8 -> V_46 . V_77 & V_78 )
V_16 |= V_153 ;
F_11 ( V_8 , V_147 , V_16 , V_154 ) ;
F_11 ( V_8 , V_155 , V_16 , V_152 | V_153 ) ;
}
static void F_67 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_156 , 0 , V_157 |
V_158 | V_159 ) ;
F_11 ( V_8 , V_160 ,
V_161 , V_162 ) ;
F_7 ( V_8 , V_163 , 0 ) ;
F_11 ( V_8 , V_147 , 0 , V_164 ) ;
if ( V_8 -> V_38 ) {
F_11 ( V_8 , V_160 ,
V_165 , V_162 ) ;
F_7 ( V_8 , V_163 ,
V_166 | V_167 ) ;
}
if ( V_8 -> V_12 -> type == V_168 ) {
F_7 ( V_8 , V_169 , 0x12 ) ;
F_7 ( V_8 , V_170 , 0x34 ) ;
F_7 ( V_8 , V_171 , 0x56 ) ;
F_7 ( V_8 , V_172 , 0x02 ) ;
F_7 ( V_8 , F_68 ( 0 ) , 0 << 5 ) ;
F_11 ( V_8 , V_173 , 0x10 << 5 , 0x11 << 5 ) ;
F_7 ( V_8 , V_174 , 0x02 ) ;
F_7 ( V_8 , V_175 , 0x02 ) ;
F_7 ( V_8 , V_176 , 0x04 ) ;
} else {
F_21 ( V_8 ) ;
F_11 ( V_8 , V_173 , 2 , 3 << 5 ) ;
}
}
static void F_69 ( struct V_1 * V_8 )
{
int V_177 ;
for ( V_177 = 0 ; V_177 < 10 ; ++ V_177 ) {
T_1 V_16 = F_5 ( V_8 , V_178 ) ;
if ( V_16 & V_179 ) {
F_37 ( L_13 , V_177 ) ;
return;
}
F_70 ( 10 , 20 ) ;
}
F_45 ( L_14 ) ;
}
static void F_71 ( struct V_1 * V_8 )
{
struct V_72 * V_90 = & V_8 -> V_46 ;
unsigned int V_16 ;
F_9 ( V_8 , V_180 , 2 , V_90 -> V_181 - V_90 -> V_74 ) ;
F_9 ( V_8 , V_182 , 3 ,
( V_90 -> V_181 << 12 ) | V_90 -> V_183 ) ;
V_16 = ( V_90 -> V_77 & V_184 ) ? 1 : 0 ;
F_9 ( V_8 , V_185 , 1 , V_16 ) ;
V_16 = ( V_90 -> V_77 & V_78 ) ? 1 : 0 ;
F_9 ( V_8 , V_186 , 1 , V_16 ) ;
V_16 = ( V_90 -> V_187 - V_90 -> V_74 - 2 ) ;
V_16 |= ( ( V_90 -> V_188 - V_90 -> V_74 - 2 ) << 10 ) ;
V_16 |= ( ( V_90 -> V_77 & V_189 ) ? 1 : 0 ) << 20 ;
F_9 ( V_8 , V_190 , 3 , V_16 ) ;
if ( V_90 -> V_77 & V_78 ) {
V_16 = ( ( V_90 -> V_191 - V_90 -> V_75 ) / 2 ) ;
V_16 |= ( ( V_90 -> V_192 - V_90 -> V_75 ) / 2 ) << 12 ;
F_9 ( V_8 , V_193 , 3 , V_16 ) ;
V_16 = V_90 -> V_183 / 2 ;
V_16 |= ( ( V_90 -> V_183 - V_90 -> V_75 ) / 2 ) << 11 ;
F_9 ( V_8 , V_194 , 3 , V_16 ) ;
V_16 = ( V_90 -> V_183 +
( ( V_90 -> V_191 - V_90 -> V_192 ) * 4 ) + 5 ) / 2 ;
V_16 |= V_90 -> V_183 << 11 ;
F_9 ( V_8 , V_195 , 3 , V_16 ) ;
V_16 = ( ( V_90 -> V_183 / 2 ) + 7 ) ;
V_16 |= ( ( V_90 -> V_183 / 2 ) + 2 ) << 12 ;
F_9 ( V_8 , V_196 , 3 , V_16 ) ;
V_16 = ( ( V_90 -> V_181 / 2 ) + ( V_90 -> V_187 - V_90 -> V_74 ) ) ;
V_16 |= ( ( V_90 -> V_181 / 2 ) +
( V_90 -> V_187 - V_90 -> V_74 ) ) << 12 ;
F_9 ( V_8 , V_197 , 3 , V_16 ) ;
F_9 ( V_8 , V_198 , 2 ,
( V_90 -> V_183 - V_90 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_199 , 2 , V_90 -> V_75 / 2 ) ;
F_9 ( V_8 , V_200 , 2 , 0x249 ) ;
} else {
V_16 = V_90 -> V_183 ;
V_16 |= ( V_90 -> V_183 - V_90 -> V_75 ) << 11 ;
F_9 ( V_8 , V_194 , 3 , V_16 ) ;
F_9 ( V_8 , V_195 , 3 , 0 ) ;
V_16 = ( V_90 -> V_191 - V_90 -> V_75 ) ;
V_16 |= ( ( V_90 -> V_192 - V_90 -> V_75 ) << 12 ) ;
F_9 ( V_8 , V_193 , 3 , V_16 ) ;
F_9 ( V_8 , V_196 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_197 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_198 , 2 ,
V_90 -> V_183 - V_90 -> V_75 ) ;
F_9 ( V_8 , V_199 , 2 , V_90 -> V_75 ) ;
}
F_9 ( V_8 , V_201 , 2 , V_90 -> V_181 ) ;
F_9 ( V_8 , V_202 , 2 , V_90 -> V_181 - V_90 -> V_74 ) ;
F_9 ( V_8 , V_203 , 2 , V_90 -> V_74 ) ;
F_9 ( V_8 , V_204 , 2 , V_90 -> V_183 ) ;
}
static void F_72 ( struct V_1 * V_8 )
{
struct V_72 * V_90 = & V_8 -> V_46 ;
F_9 ( V_8 , V_180 , 2 , V_90 -> V_181 - V_90 -> V_74 ) ;
F_9 ( V_8 , V_205 , 2 , V_90 -> V_183 ) ;
F_9 ( V_8 , V_206 , 2 , V_90 -> V_181 ) ;
F_9 ( V_8 , V_207 , 1 ,
( V_90 -> V_77 & V_189 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_185 , 1 ,
( V_90 -> V_77 & V_184 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_186 , 1 ,
( V_90 -> V_77 & V_78 ) ? 1 : 0 ) ;
if ( V_90 -> V_77 & V_78 ) {
F_9 ( V_8 , V_208 , 2 ,
( V_90 -> V_191 - V_90 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_209 , 2 ,
( V_90 -> V_192 - V_90 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_210 , 2 , V_90 -> V_183 / 2 ) ;
F_9 ( V_8 , V_211 , 2 ,
( V_90 -> V_183 - V_90 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_212 , 2 ,
V_90 -> V_183 - V_90 -> V_75 / 2 ) ;
F_9 ( V_8 , V_213 , 2 , V_90 -> V_183 ) ;
F_9 ( V_8 , V_214 , 2 ,
( V_90 -> V_183 / 2 ) + 7 ) ;
F_9 ( V_8 , V_215 , 2 ,
( V_90 -> V_183 / 2 ) + 2 ) ;
F_9 ( V_8 , V_216 , 2 ,
( V_90 -> V_181 / 2 ) + ( V_90 -> V_187 - V_90 -> V_74 ) ) ;
F_9 ( V_8 , V_217 , 2 ,
( V_90 -> V_181 / 2 ) + ( V_90 -> V_187 - V_90 -> V_74 ) ) ;
F_9 ( V_8 , V_198 , 2 ,
( V_90 -> V_183 - V_90 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_199 , 2 , V_90 -> V_75 / 2 ) ;
F_9 ( V_8 , V_200 , 2 ,
V_90 -> V_183 - V_90 -> V_75 / 2 ) ;
F_9 ( V_8 , V_218 , 2 ,
( V_90 -> V_183 / 2 ) + 1 ) ;
F_9 ( V_8 , V_219 , 2 ,
( V_90 -> V_183 / 2 ) + 1 ) ;
F_9 ( V_8 , V_220 , 2 ,
( V_90 -> V_183 / 2 ) + 1 ) ;
F_9 ( V_8 , V_221 , 2 , 0x0 ) ;
F_9 ( V_8 , V_222 , 2 , 0x0 ) ;
} else {
F_9 ( V_8 , V_208 , 2 ,
V_90 -> V_191 - V_90 -> V_75 ) ;
F_9 ( V_8 , V_209 , 2 ,
V_90 -> V_192 - V_90 -> V_75 ) ;
F_9 ( V_8 , V_210 , 2 , V_90 -> V_183 ) ;
F_9 ( V_8 , V_211 , 2 ,
V_90 -> V_183 - V_90 -> V_75 ) ;
F_9 ( V_8 , V_212 , 2 , 0xffff ) ;
F_9 ( V_8 , V_213 , 2 , 0xffff ) ;
F_9 ( V_8 , V_214 , 2 , 0xffff ) ;
F_9 ( V_8 , V_215 , 2 , 0xffff ) ;
F_9 ( V_8 , V_216 , 2 , 0xffff ) ;
F_9 ( V_8 , V_217 , 2 , 0xffff ) ;
F_9 ( V_8 , V_198 , 2 ,
V_90 -> V_183 - V_90 -> V_75 ) ;
F_9 ( V_8 , V_199 , 2 , V_90 -> V_75 ) ;
}
F_9 ( V_8 , V_223 , 2 ,
V_90 -> V_187 - V_90 -> V_74 - 2 ) ;
F_9 ( V_8 , V_224 , 2 ,
V_90 -> V_188 - V_90 -> V_74 - 2 ) ;
F_9 ( V_8 , V_225 , 2 , 0xffff ) ;
F_9 ( V_8 , V_226 , 2 , 0xffff ) ;
F_9 ( V_8 , V_227 , 2 , 0xffff ) ;
F_9 ( V_8 , V_228 , 2 , 0xffff ) ;
F_9 ( V_8 , V_229 , 2 , 0xffff ) ;
F_9 ( V_8 , V_230 , 2 , 0xffff ) ;
F_9 ( V_8 , V_231 , 2 , 0xffff ) ;
F_9 ( V_8 , V_232 , 2 , 0xffff ) ;
F_9 ( V_8 , V_233 , 2 , 0xffff ) ;
F_9 ( V_8 , V_234 , 2 , 0xffff ) ;
F_9 ( V_8 , V_235 , 2 , 0xffff ) ;
F_9 ( V_8 , V_236 , 2 , 0xffff ) ;
F_9 ( V_8 , V_237 , 2 , 0xffff ) ;
F_9 ( V_8 , V_238 , 2 , 0xffff ) ;
F_9 ( V_8 , V_239 , 2 , 0xffff ) ;
F_9 ( V_8 , V_240 , 2 , 0xffff ) ;
F_9 ( V_8 , V_241 , 2 , 0xffff ) ;
F_9 ( V_8 , V_242 , 2 , 0xffff ) ;
F_9 ( V_8 , V_201 , 2 , V_90 -> V_181 ) ;
F_9 ( V_8 , V_202 , 2 , V_90 -> V_181 - V_90 -> V_74 ) ;
F_9 ( V_8 , V_203 , 2 , V_90 -> V_74 ) ;
F_9 ( V_8 , V_204 , 2 , V_90 -> V_183 ) ;
if ( V_8 -> V_12 == & V_243 )
F_7 ( V_8 , V_244 , 1 ) ;
}
static void F_73 ( struct V_1 * V_8 )
{
if ( V_8 -> V_12 -> type == V_168 )
F_71 ( V_8 ) ;
else
F_72 ( V_8 ) ;
F_66 ( V_8 , true ) ;
}
static void F_74 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_245 , 0 , 1 ) ;
F_70 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_245 , ~ 0 , 1 ) ;
F_70 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_246 , ~ 0 , V_247 ) ;
F_70 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_246 , 0 , V_247 ) ;
F_70 ( 10000 , 12000 ) ;
}
static void F_75 ( struct V_1 * V_8 , bool V_248 )
{
T_2 V_249 = V_248 ? V_250 : V_251 ;
if ( V_8 -> V_12 == & V_243 )
F_8 ( V_249 , V_8 -> V_27 + V_252 ) ;
}
static void F_76 ( struct V_1 * V_8 )
{
int V_25 ;
const T_2 * V_253 ;
V_25 = F_41 ( V_8 , V_8 -> V_46 . clock * 1000 ) ;
if ( V_25 < 0 ) {
F_45 ( L_15 ) ;
return;
}
V_253 = V_8 -> V_12 -> V_71 . V_31 [ V_25 ] . V_254 ;
F_19 ( V_8 , false ) ;
F_74 ( V_8 ) ;
F_75 ( V_8 , true ) ;
V_25 = F_12 ( V_8 , 0 , V_253 , 32 ) ;
if ( V_25 ) {
F_45 ( L_16 ) ;
return;
}
F_75 ( V_8 , false ) ;
F_19 ( V_8 , true ) ;
F_70 ( 10000 , 12000 ) ;
F_69 ( V_8 ) ;
}
static void F_77 ( struct V_1 * V_8 )
{
F_66 ( V_8 , false ) ;
F_67 ( V_8 ) ;
F_54 ( V_8 ) ;
F_73 ( V_8 ) ;
F_65 ( V_8 , true ) ;
}
static void F_78 ( struct V_2 * V_4 ,
struct V_72 * V_73 ,
struct V_72 * V_88 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_72 * V_90 = V_88 ;
F_37 ( L_17 ,
V_90 -> V_74 , V_90 -> V_75 ,
V_90 -> V_76 , ( V_90 -> V_77 & V_78 ) ?
L_18 : L_19 ) ;
F_52 ( & V_8 -> V_46 , V_90 ) ;
}
static void F_79 ( struct V_1 * V_8 , bool V_255 )
{
if ( ! V_8 -> V_256 )
return;
F_80 ( V_8 -> V_256 , V_257 ,
V_258 , V_255 ? ~ 0 : 0 ) ;
}
static void F_81 ( struct V_1 * V_8 )
{
if ( V_8 -> V_259 )
return;
F_82 ( V_8 -> V_30 ) ;
if ( F_83 ( F_84 ( V_260 ) , V_8 -> V_261 ) )
F_37 ( L_20 ) ;
F_80 ( V_8 -> V_262 , V_263 ,
V_264 , 1 ) ;
F_79 ( V_8 , true ) ;
F_11 ( V_8 , V_265 , 0 , V_266 ) ;
F_76 ( V_8 ) ;
V_8 -> V_259 = true ;
}
static void F_85 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_259 )
return;
F_11 ( V_8 , V_147 , 0 , V_154 ) ;
F_11 ( V_8 , V_265 , ~ 0 , V_266 ) ;
F_79 ( V_8 , false ) ;
F_80 ( V_8 -> V_262 , V_263 ,
V_264 , 0 ) ;
F_86 ( F_84 ( V_260 ) , V_8 -> V_261 ) ;
F_87 ( V_8 -> V_30 ) ;
V_8 -> V_259 = false ;
}
static void F_88 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_81 ( V_8 ) ;
F_77 ( V_8 ) ;
}
static void F_89 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_267 * V_268 = V_4 -> V_268 ;
const struct V_269 * V_270 = NULL ;
if ( ! V_8 -> V_259 )
return;
if ( V_268 )
V_270 = V_268 -> V_271 ;
if ( V_270 && V_270 -> V_272 )
(* V_270 -> V_272 )( V_268 ) ;
F_90 ( & V_8 -> V_273 ) ;
F_85 ( V_8 ) ;
}
static void F_91 ( struct V_274 * V_275 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( V_275 , struct V_1 , V_273 . V_275 ) ;
if ( V_8 -> V_84 )
F_92 ( V_8 -> V_84 ) ;
}
static T_3 F_93 ( int V_276 , void * V_277 )
{
struct V_1 * V_8 = V_277 ;
F_94 ( V_278 , & V_8 -> V_273 ,
F_95 ( V_279 ) ) ;
return V_280 ;
}
static int F_96 ( struct V_1 * V_8 ,
const struct V_281 * V_282 ,
struct V_35 * * V_283 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_282 -> V_29 ; ++ V_26 ) {
struct V_35 * V_35 = F_97 ( V_30 , V_282 -> V_31 [ V_26 ] ) ;
if ( F_98 ( V_35 ) ) {
int V_25 = F_99 ( V_35 ) ;
F_16 ( V_30 , L_21 ,
V_282 -> V_31 [ V_26 ] , V_25 ) ;
return V_25 ;
}
V_283 [ V_26 ] = V_35 ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_8 )
{
const struct V_284 * V_12 = V_8 -> V_12 ;
int V_29 = V_12 -> V_28 . V_29 + V_12 -> V_34 . V_29 ;
struct V_33 * V_30 = V_8 -> V_30 ;
struct V_35 * * V_283 ;
int V_25 ;
if ( ! V_29 )
return 0 ;
V_283 = F_101 ( V_30 , sizeof( * V_283 ) * V_29 , V_285 ) ;
if ( ! V_283 )
return - V_286 ;
V_8 -> V_28 = V_283 ;
V_8 -> V_34 = V_283 + V_12 -> V_28 . V_29 ;
V_25 = F_96 ( V_8 , & V_12 -> V_28 , V_8 -> V_28 ) ;
if ( V_25 )
return V_25 ;
return F_96 ( V_8 , & V_12 -> V_34 , V_8 -> V_34 ) ;
}
static void F_102 ( struct V_287 * V_35 , bool V_248 )
{
struct V_1 * V_8 = F_2 ( V_35 , struct V_1 ,
V_288 ) ;
if ( V_248 )
F_81 ( V_8 ) ;
else
F_85 ( V_8 ) ;
}
static int F_103 ( struct V_1 * V_8 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 , V_25 ;
F_37 ( L_22 ) ;
V_8 -> V_60 = F_104 ( V_30 , L_23 , V_289 ) ;
if ( F_98 ( V_8 -> V_60 ) ) {
F_45 ( L_24 ) ;
return F_99 ( V_8 -> V_60 ) ;
}
V_8 -> V_276 = F_105 ( V_8 -> V_60 ) ;
if ( V_8 -> V_276 < 0 ) {
F_45 ( L_25 ) ;
return V_8 -> V_276 ;
}
V_25 = F_100 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_19 ( V_8 , false ) ;
if ( V_25 )
return V_25 ;
for ( V_26 = 0 ; V_26 < F_84 ( V_260 ) ; ++ V_26 )
V_8 -> V_261 [ V_26 ] . V_260 = V_260 [ V_26 ] ;
V_25 = F_106 ( V_30 , F_84 ( V_260 ) , V_8 -> V_261 ) ;
if ( V_25 ) {
if ( V_25 != - V_290 )
F_45 ( L_26 ) ;
return V_25 ;
}
V_8 -> V_291 = F_107 ( V_30 , L_27 ) ;
if ( F_99 ( V_8 -> V_291 ) == - V_65 )
return 0 ;
if ( F_98 ( V_8 -> V_291 ) )
return F_99 ( V_8 -> V_291 ) ;
V_25 = F_108 ( V_8 -> V_291 ) ;
if ( V_25 )
F_45 ( L_28 ) ;
return V_25 ;
}
static int F_109 ( struct V_33 * V_30 , struct V_33 * V_292 , void * V_31 )
{
struct V_89 * V_84 = V_31 ;
struct V_1 * V_8 = F_110 ( V_30 ) ;
struct V_2 * V_4 = & V_8 -> V_4 ;
int V_25 , V_293 ;
V_8 -> V_84 = V_84 ;
V_293 = F_111 ( V_84 ,
V_294 ) ;
if ( V_293 < 0 )
return V_293 ;
V_8 -> V_288 . V_248 = F_102 ;
F_112 ( V_84 , V_293 ) -> V_295 = & V_8 -> V_288 ;
V_4 -> V_296 = 1 << V_293 ;
F_37 ( L_29 , V_4 -> V_296 ) ;
F_113 ( V_84 , V_4 , & V_297 ,
V_298 , NULL ) ;
F_114 ( V_4 , & V_299 ) ;
V_25 = F_43 ( V_4 ) ;
if ( V_25 ) {
F_45 ( L_30 , V_25 ) ;
F_115 ( V_4 ) ;
return V_25 ;
}
return 0 ;
}
static void F_116 ( struct V_33 * V_30 , struct V_33 * V_292 , void * V_31 )
{
}
static int F_117 ( struct V_1 * V_8 )
{
const char * V_300 = L_31 ;
struct V_301 * V_302 ;
struct V_303 * V_304 ;
V_302 = F_118 ( NULL , NULL , V_300 ) ;
if ( V_302 )
V_302 = F_119 ( V_302 ) ;
else
V_302 = F_120 ( V_8 -> V_30 -> V_305 , L_32 , 0 ) ;
if ( ! V_302 ) {
F_45 ( L_33 ) ;
return - V_65 ;
}
V_304 = F_121 ( V_302 ) ;
F_122 ( V_302 ) ;
if ( ! V_304 ) {
F_24 ( L_34 ) ;
return - V_290 ;
}
V_8 -> V_64 = V_304 ;
return 0 ;
}
static int F_123 ( struct V_1 * V_8 )
{
const char * V_300 = L_35 ;
struct V_301 * V_302 ;
int V_25 = 0 ;
V_302 = F_118 ( NULL , NULL , V_300 ) ;
if ( ! V_302 ) {
V_302 = F_120 ( V_8 -> V_30 -> V_305 , L_36 , 0 ) ;
if ( ! V_302 ) {
F_45 ( L_37 ) ;
return - V_65 ;
}
}
if ( V_8 -> V_12 -> V_306 ) {
V_8 -> V_27 = F_124 ( V_302 , 0 ) ;
if ( ! V_8 -> V_27 ) {
F_45 ( L_38 ) ;
V_25 = - V_286 ;
goto V_307;
}
} else {
V_8 -> V_24 = F_125 ( V_302 ) ;
if ( ! V_8 -> V_24 ) {
F_24 ( L_39 ) ;
V_25 = - V_290 ;
goto V_307;
}
}
V_307:
F_122 ( V_302 ) ;
return V_25 ;
}
static int F_126 ( struct V_308 * V_309 )
{
struct V_33 * V_30 = & V_309 -> V_30 ;
struct V_1 * V_8 ;
struct V_310 * V_311 ;
int V_25 ;
V_8 = F_101 ( V_30 , sizeof( struct V_1 ) , V_285 ) ;
if ( ! V_8 )
return - V_286 ;
V_8 -> V_12 = F_127 ( V_30 ) ;
F_128 ( V_309 , V_8 ) ;
V_8 -> V_30 = V_30 ;
V_25 = F_103 ( V_8 ) ;
if ( V_25 ) {
if ( V_25 != - V_290 )
F_45 ( L_40 ) ;
return V_25 ;
}
V_311 = F_129 ( V_309 , V_312 , 0 ) ;
V_8 -> V_13 = F_130 ( V_30 , V_311 ) ;
if ( F_98 ( V_8 -> V_13 ) ) {
V_25 = F_99 ( V_8 -> V_13 ) ;
return V_25 ;
}
V_25 = F_117 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_123 ( V_8 ) ;
if ( V_25 )
goto V_313;
F_131 ( & V_8 -> V_273 , F_91 ) ;
V_25 = F_132 ( V_30 , V_8 -> V_276 , NULL ,
F_93 , V_314 |
V_315 | V_316 ,
L_41 , V_8 ) ;
if ( V_25 ) {
F_45 ( L_42 ) ;
goto V_317;
}
V_8 -> V_262 = F_133 ( V_30 -> V_305 ,
L_43 ) ;
if ( F_98 ( V_8 -> V_262 ) ) {
F_45 ( L_44 ) ;
V_25 = - V_290 ;
goto V_317;
}
if ( V_8 -> V_12 -> V_318 ) {
V_8 -> V_256 = F_133 ( V_30 -> V_305 ,
L_45 ) ;
if ( F_98 ( V_8 -> V_256 ) ) {
F_45 ( L_46 ) ;
V_25 = - V_290 ;
goto V_317;
}
}
F_134 ( V_30 ) ;
V_25 = F_135 ( & V_309 -> V_30 , & V_319 ) ;
if ( V_25 )
goto V_320;
return V_25 ;
V_320:
F_136 ( V_30 ) ;
V_317:
if ( V_8 -> V_24 )
F_137 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_138 ( V_8 -> V_27 ) ;
V_313:
F_137 ( & V_8 -> V_64 -> V_30 ) ;
return V_25 ;
}
static int F_139 ( struct V_308 * V_309 )
{
struct V_1 * V_8 = F_140 ( V_309 ) ;
F_141 ( & V_8 -> V_273 ) ;
F_142 ( & V_309 -> V_30 , & V_319 ) ;
F_136 ( & V_309 -> V_30 ) ;
if ( ! F_98 ( V_8 -> V_291 ) )
F_143 ( V_8 -> V_291 ) ;
if ( V_8 -> V_24 )
F_137 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_138 ( V_8 -> V_27 ) ;
F_137 ( & V_8 -> V_64 -> V_30 ) ;
return 0 ;
}
static int F_144 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_110 ( V_30 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int F_145 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_110 ( V_30 ) ;
int V_25 ;
V_25 = F_14 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
