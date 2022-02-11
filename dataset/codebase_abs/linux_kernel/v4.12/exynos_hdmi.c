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
F_10 ( V_8 , V_53 , V_17 , 3 ) ;
F_10 ( V_8 , F_27 ( 0 ) , V_17 + 3 , V_25 - 3 ) ;
}
V_25 = F_28 ( & V_37 . V_54 ) ;
if ( ! V_25 ) {
V_37 . V_54 . V_55 = 2 ;
V_25 = F_29 ( & V_37 . V_54 , V_17 , sizeof( V_17 ) ) ;
}
if ( V_25 > 0 ) {
F_7 ( V_8 , V_43 , V_56 ) ;
F_10 ( V_8 , V_57 , V_17 , V_25 ) ;
}
}
static enum V_58 F_30 ( struct V_5 * V_7 ,
bool V_59 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
if ( F_31 ( V_8 -> V_60 ) )
return V_61 ;
F_32 ( V_8 -> V_62 , V_63 ) ;
return V_64 ;
}
static void F_33 ( struct V_5 * V_7 )
{
F_34 ( V_7 ) ;
F_35 ( V_7 ) ;
}
static int F_36 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_65 * V_65 ;
int V_25 ;
if ( ! V_8 -> V_66 )
return - V_67 ;
V_65 = F_37 ( V_7 , V_8 -> V_66 ) ;
if ( ! V_65 )
return - V_67 ;
V_8 -> V_38 = ! F_38 ( V_65 ) ;
F_39 ( L_4 ,
( V_8 -> V_38 ? L_5 : L_6 ) ,
V_65 -> V_68 , V_65 -> V_69 ) ;
F_40 ( V_7 , V_65 ) ;
F_41 ( V_8 -> V_62 , V_65 ) ;
V_25 = F_42 ( V_7 , V_65 ) ;
F_43 ( V_65 ) ;
return V_25 ;
}
static int F_44 ( struct V_1 * V_8 , T_1 V_70 )
{
const struct V_71 * V_72 = & V_8 -> V_12 -> V_73 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_72 -> V_29 ; V_26 ++ )
if ( V_72 -> V_31 [ V_26 ] . V_70 == V_70 )
return V_26 ;
F_39 ( L_7 , V_70 ) ;
return - V_23 ;
}
static int F_45 ( struct V_5 * V_7 ,
struct V_74 * V_75 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
int V_25 ;
F_39 ( L_8 ,
V_75 -> V_76 , V_75 -> V_77 , V_75 -> V_78 ,
( V_75 -> V_79 & V_80 ) ? true :
false , V_75 -> clock * 1000 ) ;
V_25 = F_44 ( V_8 , V_75 -> clock * 1000 ) ;
if ( V_25 < 0 )
return V_81 ;
return V_82 ;
}
static int F_46 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_5 * V_7 = & V_8 -> V_7 ;
int V_25 ;
V_7 -> V_83 = true ;
V_7 -> V_84 = V_85 ;
V_25 = F_47 ( V_8 -> V_86 , V_7 ,
& V_87 , V_88 ) ;
if ( V_25 ) {
F_48 ( L_9 ) ;
return V_25 ;
}
F_49 ( V_7 , & V_89 ) ;
F_50 ( V_7 , V_4 ) ;
if ( V_8 -> V_90 ) {
V_4 -> V_90 = V_8 -> V_90 ;
V_8 -> V_90 -> V_4 = V_4 ;
V_25 = F_51 ( V_4 , V_8 -> V_90 , NULL ) ;
if ( V_25 )
F_48 ( L_10 ) ;
}
return V_25 ;
}
static bool F_52 ( struct V_2 * V_4 ,
const struct V_74 * V_75 ,
struct V_74 * V_91 )
{
struct V_92 * V_30 = V_4 -> V_30 ;
struct V_5 * V_7 ;
struct V_74 * V_93 ;
int V_94 ;
F_53 ( V_91 , 0 ) ;
F_54 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_4 == V_4 )
break;
}
if ( V_7 -> V_4 != V_4 )
return true ;
V_94 = F_45 ( V_7 , V_91 ) ;
if ( V_94 == V_82 )
return true ;
F_54 (m, &connector->modes, head) {
V_94 = F_45 ( V_7 , V_93 ) ;
if ( V_94 == V_82 ) {
F_24 ( L_11 ) ;
F_24 ( L_12 ) ;
F_39 ( L_13 ,
V_93 -> V_76 , V_93 -> V_77 , V_93 -> V_78 ) ;
F_55 ( V_91 , V_93 ) ;
break;
}
}
return true ;
}
static void F_56 ( struct V_1 * V_8 , T_1 V_95 )
{
T_1 V_96 , V_97 ;
V_97 = ( V_95 % 9 ) ? 27000 : 30000 ;
V_96 = 128 * V_95 / ( 27000000 / V_97 ) ;
F_9 ( V_8 , V_98 , 3 , V_96 ) ;
F_9 ( V_8 , V_99 , 3 , V_97 ) ;
F_9 ( V_8 , V_100 , 3 , V_97 ) ;
F_7 ( V_8 , V_101 , 4 ) ;
}
static void F_57 ( struct V_1 * V_8 )
{
T_1 V_102 , V_103 ;
T_1 V_104 , V_105 , V_106 ;
T_1 V_16 ;
V_102 = 44100 ;
V_103 = 16 ;
switch ( V_103 ) {
case 20 :
V_104 = 2 ;
V_105 = 1 ;
break;
case 24 :
V_104 = 3 ;
V_105 = 1 ;
break;
default:
V_104 = 1 ;
V_105 = 0 ;
break;
}
F_56 ( V_8 , V_102 ) ;
F_7 ( V_8 , V_107 , V_108
| V_109 | V_110
| V_111 ) ;
F_7 ( V_8 , V_112 , V_113
| V_114 | V_115 ) ;
F_7 ( V_8 , V_116 , V_117 ) ;
V_106 = ( V_102 == 44100 ) ? 0 :
( V_102 == 48000 ) ? 2 :
( V_102 == 32000 ) ? 3 :
( V_102 == 96000 ) ? 0xa : 0x0 ;
F_7 ( V_8 , V_118 , V_119 ) ;
F_7 ( V_8 , V_118 , V_120 ) ;
V_16 = F_5 ( V_8 , V_121 ) | 0x01 ;
F_7 ( V_8 , V_121 , V_16 ) ;
F_7 ( V_8 , V_122 , F_58 ( 5 )
| F_59 ( 6 ) ) ;
F_7 ( V_8 , V_123 , F_60 ( 1 )
| F_61 ( 4 ) ) ;
F_7 ( V_8 , V_124 , F_62 ( 1 )
| F_61 ( 2 ) ) ;
F_7 ( V_8 , V_125 , F_63 ( 0 ) ) ;
F_7 ( V_8 , V_126 , V_127
| V_128 ) ;
F_7 ( V_8 , V_129 , V_130
| F_64 ( V_105 )
| F_65 ( V_104 )
| V_131 ) ;
F_7 ( V_8 , V_132 , V_133
| V_134
| V_135
| V_136
| V_137 ) ;
F_7 ( V_8 , V_138 , V_139 ) ;
F_7 ( V_8 , V_140 , F_66 ( 0 ) ) ;
F_7 ( V_8 , V_141 , V_142
| F_67 ( V_106 ) ) ;
F_7 ( V_8 , V_143 ,
V_144
| V_145
| V_146 ) ;
F_7 ( V_8 , V_147 , V_148 ) ;
}
static void F_68 ( struct V_1 * V_8 , bool V_149 )
{
if ( V_8 -> V_38 )
return;
F_7 ( V_8 , V_43 , V_149 ? 2 : 0 ) ;
F_11 ( V_8 , V_150 , V_149 ?
V_151 : V_152 , V_153 ) ;
}
static void F_69 ( struct V_1 * V_8 , bool V_154 )
{
T_1 V_16 = V_154 ? V_155 : 0 ;
if ( V_8 -> V_46 . V_79 & V_80 )
V_16 |= V_156 ;
F_11 ( V_8 , V_150 , V_16 , V_157 ) ;
F_11 ( V_8 , V_158 , V_16 , V_155 | V_156 ) ;
}
static void F_70 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_159 , 0 , V_160 |
V_161 | V_162 ) ;
F_11 ( V_8 , V_163 ,
V_164 , V_165 ) ;
F_7 ( V_8 , V_166 , 0 ) ;
F_11 ( V_8 , V_150 , 0 , V_167 ) ;
if ( V_8 -> V_38 ) {
F_11 ( V_8 , V_163 ,
V_168 , V_165 ) ;
F_7 ( V_8 , V_166 ,
V_169 | V_170 ) ;
}
if ( V_8 -> V_12 -> type == V_171 ) {
F_7 ( V_8 , V_172 , 0x12 ) ;
F_7 ( V_8 , V_173 , 0x34 ) ;
F_7 ( V_8 , V_174 , 0x56 ) ;
F_7 ( V_8 , V_175 , 0x02 ) ;
F_7 ( V_8 , F_71 ( 0 ) , 0 << 5 ) ;
F_11 ( V_8 , V_176 , 0x10 << 5 , 0x11 << 5 ) ;
F_7 ( V_8 , V_177 , 0x02 ) ;
F_7 ( V_8 , V_178 , 0x02 ) ;
F_7 ( V_8 , V_179 , 0x04 ) ;
} else {
F_21 ( V_8 ) ;
F_11 ( V_8 , V_176 , 2 , 3 << 5 ) ;
}
}
static void F_72 ( struct V_1 * V_8 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < 10 ; ++ V_180 ) {
T_1 V_16 = F_5 ( V_8 , V_181 ) ;
if ( V_16 & V_182 ) {
F_39 ( L_14 , V_180 ) ;
return;
}
F_73 ( 10 , 20 ) ;
}
F_48 ( L_15 ) ;
}
static void F_74 ( struct V_1 * V_8 )
{
struct V_74 * V_93 = & V_8 -> V_46 ;
unsigned int V_16 ;
F_9 ( V_8 , V_183 , 2 , V_93 -> V_184 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_185 , 3 ,
( V_93 -> V_184 << 12 ) | V_93 -> V_186 ) ;
V_16 = ( V_93 -> V_79 & V_187 ) ? 1 : 0 ;
F_9 ( V_8 , V_188 , 1 , V_16 ) ;
V_16 = ( V_93 -> V_79 & V_80 ) ? 1 : 0 ;
F_9 ( V_8 , V_189 , 1 , V_16 ) ;
V_16 = ( V_93 -> V_190 - V_93 -> V_76 - 2 ) ;
V_16 |= ( ( V_93 -> V_191 - V_93 -> V_76 - 2 ) << 10 ) ;
V_16 |= ( ( V_93 -> V_79 & V_192 ) ? 1 : 0 ) << 20 ;
F_9 ( V_8 , V_193 , 3 , V_16 ) ;
if ( V_93 -> V_79 & V_80 ) {
V_16 = ( ( V_93 -> V_194 - V_93 -> V_77 ) / 2 ) ;
V_16 |= ( ( V_93 -> V_195 - V_93 -> V_77 ) / 2 ) << 12 ;
F_9 ( V_8 , V_196 , 3 , V_16 ) ;
V_16 = V_93 -> V_186 / 2 ;
V_16 |= ( ( V_93 -> V_186 - V_93 -> V_77 ) / 2 ) << 11 ;
F_9 ( V_8 , V_197 , 3 , V_16 ) ;
V_16 = ( V_93 -> V_186 +
( ( V_93 -> V_194 - V_93 -> V_195 ) * 4 ) + 5 ) / 2 ;
V_16 |= V_93 -> V_186 << 11 ;
F_9 ( V_8 , V_198 , 3 , V_16 ) ;
V_16 = ( ( V_93 -> V_186 / 2 ) + 7 ) ;
V_16 |= ( ( V_93 -> V_186 / 2 ) + 2 ) << 12 ;
F_9 ( V_8 , V_199 , 3 , V_16 ) ;
V_16 = ( ( V_93 -> V_184 / 2 ) + ( V_93 -> V_190 - V_93 -> V_76 ) ) ;
V_16 |= ( ( V_93 -> V_184 / 2 ) +
( V_93 -> V_190 - V_93 -> V_76 ) ) << 12 ;
F_9 ( V_8 , V_200 , 3 , V_16 ) ;
F_9 ( V_8 , V_201 , 2 ,
( V_93 -> V_186 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_202 , 2 , V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_203 , 2 , 0x249 ) ;
} else {
V_16 = V_93 -> V_186 ;
V_16 |= ( V_93 -> V_186 - V_93 -> V_77 ) << 11 ;
F_9 ( V_8 , V_197 , 3 , V_16 ) ;
F_9 ( V_8 , V_198 , 3 , 0 ) ;
V_16 = ( V_93 -> V_194 - V_93 -> V_77 ) ;
V_16 |= ( ( V_93 -> V_195 - V_93 -> V_77 ) << 12 ) ;
F_9 ( V_8 , V_196 , 3 , V_16 ) ;
F_9 ( V_8 , V_199 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_200 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_201 , 2 ,
V_93 -> V_186 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_202 , 2 , V_93 -> V_77 ) ;
}
F_9 ( V_8 , V_204 , 2 , V_93 -> V_184 ) ;
F_9 ( V_8 , V_205 , 2 , V_93 -> V_184 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_206 , 2 , V_93 -> V_76 ) ;
F_9 ( V_8 , V_207 , 2 , V_93 -> V_186 ) ;
}
static void F_75 ( struct V_1 * V_8 )
{
struct V_74 * V_93 = & V_8 -> V_46 ;
F_9 ( V_8 , V_183 , 2 , V_93 -> V_184 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_208 , 2 , V_93 -> V_186 ) ;
F_9 ( V_8 , V_209 , 2 , V_93 -> V_184 ) ;
F_9 ( V_8 , V_210 , 1 ,
( V_93 -> V_79 & V_192 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_188 , 1 ,
( V_93 -> V_79 & V_187 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_189 , 1 ,
( V_93 -> V_79 & V_80 ) ? 1 : 0 ) ;
if ( V_93 -> V_79 & V_80 ) {
F_9 ( V_8 , V_211 , 2 ,
( V_93 -> V_194 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_212 , 2 ,
( V_93 -> V_195 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_213 , 2 , V_93 -> V_186 / 2 ) ;
F_9 ( V_8 , V_214 , 2 ,
( V_93 -> V_186 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_215 , 2 ,
V_93 -> V_186 - V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_216 , 2 , V_93 -> V_186 ) ;
F_9 ( V_8 , V_217 , 2 ,
( V_93 -> V_186 / 2 ) + 7 ) ;
F_9 ( V_8 , V_218 , 2 ,
( V_93 -> V_186 / 2 ) + 2 ) ;
F_9 ( V_8 , V_219 , 2 ,
( V_93 -> V_184 / 2 ) + ( V_93 -> V_190 - V_93 -> V_76 ) ) ;
F_9 ( V_8 , V_220 , 2 ,
( V_93 -> V_184 / 2 ) + ( V_93 -> V_190 - V_93 -> V_76 ) ) ;
F_9 ( V_8 , V_201 , 2 ,
( V_93 -> V_186 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_202 , 2 , V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_203 , 2 ,
V_93 -> V_186 - V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_221 , 2 ,
( V_93 -> V_186 / 2 ) + 1 ) ;
F_9 ( V_8 , V_222 , 2 ,
( V_93 -> V_186 / 2 ) + 1 ) ;
F_9 ( V_8 , V_223 , 2 ,
( V_93 -> V_186 / 2 ) + 1 ) ;
F_9 ( V_8 , V_224 , 2 , 0x0 ) ;
F_9 ( V_8 , V_225 , 2 , 0x0 ) ;
} else {
F_9 ( V_8 , V_211 , 2 ,
V_93 -> V_194 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_212 , 2 ,
V_93 -> V_195 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_213 , 2 , V_93 -> V_186 ) ;
F_9 ( V_8 , V_214 , 2 ,
V_93 -> V_186 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_215 , 2 , 0xffff ) ;
F_9 ( V_8 , V_216 , 2 , 0xffff ) ;
F_9 ( V_8 , V_217 , 2 , 0xffff ) ;
F_9 ( V_8 , V_218 , 2 , 0xffff ) ;
F_9 ( V_8 , V_219 , 2 , 0xffff ) ;
F_9 ( V_8 , V_220 , 2 , 0xffff ) ;
F_9 ( V_8 , V_201 , 2 ,
V_93 -> V_186 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_202 , 2 , V_93 -> V_77 ) ;
}
F_9 ( V_8 , V_226 , 2 ,
V_93 -> V_190 - V_93 -> V_76 - 2 ) ;
F_9 ( V_8 , V_227 , 2 ,
V_93 -> V_191 - V_93 -> V_76 - 2 ) ;
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
F_9 ( V_8 , V_243 , 2 , 0xffff ) ;
F_9 ( V_8 , V_244 , 2 , 0xffff ) ;
F_9 ( V_8 , V_245 , 2 , 0xffff ) ;
F_9 ( V_8 , V_204 , 2 , V_93 -> V_184 ) ;
F_9 ( V_8 , V_205 , 2 , V_93 -> V_184 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_206 , 2 , V_93 -> V_76 ) ;
F_9 ( V_8 , V_207 , 2 , V_93 -> V_186 ) ;
if ( V_8 -> V_12 == & V_246 )
F_7 ( V_8 , V_247 , 1 ) ;
}
static void F_76 ( struct V_1 * V_8 )
{
if ( V_8 -> V_12 -> type == V_171 )
F_74 ( V_8 ) ;
else
F_75 ( V_8 ) ;
F_69 ( V_8 , true ) ;
}
static void F_77 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_248 , 0 , 1 ) ;
F_73 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_248 , ~ 0 , 1 ) ;
F_73 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_249 , ~ 0 , V_250 ) ;
F_73 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_249 , 0 , V_250 ) ;
F_73 ( 10000 , 12000 ) ;
}
static void F_78 ( struct V_1 * V_8 , bool V_251 )
{
T_2 V_252 = V_251 ? V_253 : V_254 ;
if ( V_8 -> V_12 == & V_246 )
F_8 ( V_252 , V_8 -> V_27 + V_255 ) ;
}
static void F_79 ( struct V_1 * V_8 )
{
int V_25 ;
const T_2 * V_256 ;
V_25 = F_44 ( V_8 , V_8 -> V_46 . clock * 1000 ) ;
if ( V_25 < 0 ) {
F_48 ( L_16 ) ;
return;
}
V_256 = V_8 -> V_12 -> V_73 . V_31 [ V_25 ] . V_257 ;
F_19 ( V_8 , false ) ;
F_77 ( V_8 ) ;
F_78 ( V_8 , true ) ;
V_25 = F_12 ( V_8 , 0 , V_256 , 32 ) ;
if ( V_25 ) {
F_48 ( L_17 ) ;
return;
}
F_78 ( V_8 , false ) ;
F_19 ( V_8 , true ) ;
F_73 ( 10000 , 12000 ) ;
F_72 ( V_8 ) ;
}
static void F_80 ( struct V_1 * V_8 )
{
F_69 ( V_8 , false ) ;
F_70 ( V_8 ) ;
F_57 ( V_8 ) ;
F_76 ( V_8 ) ;
F_68 ( V_8 , true ) ;
}
static void F_81 ( struct V_2 * V_4 ,
struct V_74 * V_75 ,
struct V_74 * V_91 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_74 * V_93 = V_91 ;
F_39 ( L_18 ,
V_93 -> V_76 , V_93 -> V_77 ,
V_93 -> V_78 , ( V_93 -> V_79 & V_80 ) ?
L_19 : L_20 ) ;
F_55 ( & V_8 -> V_46 , V_93 ) ;
}
static void F_82 ( struct V_1 * V_8 , bool V_258 )
{
if ( ! V_8 -> V_259 )
return;
F_83 ( V_8 -> V_259 , V_260 ,
V_261 , V_258 ? ~ 0 : 0 ) ;
}
static void F_84 ( struct V_1 * V_8 )
{
if ( V_8 -> V_262 )
return;
F_85 ( V_8 -> V_30 ) ;
if ( F_86 ( F_87 ( V_263 ) , V_8 -> V_264 ) )
F_39 ( L_21 ) ;
F_83 ( V_8 -> V_265 , V_266 ,
V_267 , 1 ) ;
F_82 ( V_8 , true ) ;
F_11 ( V_8 , V_268 , 0 , V_269 ) ;
F_79 ( V_8 ) ;
V_8 -> V_262 = true ;
}
static void F_88 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_262 )
return;
F_11 ( V_8 , V_150 , 0 , V_157 ) ;
F_11 ( V_8 , V_268 , ~ 0 , V_269 ) ;
F_82 ( V_8 , false ) ;
F_83 ( V_8 -> V_265 , V_266 ,
V_267 , 0 ) ;
F_89 ( F_87 ( V_263 ) , V_8 -> V_264 ) ;
F_90 ( V_8 -> V_30 ) ;
V_8 -> V_262 = false ;
}
static void F_91 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_84 ( V_8 ) ;
F_80 ( V_8 ) ;
}
static void F_92 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_270 * V_271 = V_4 -> V_271 ;
const struct V_272 * V_273 = NULL ;
if ( ! V_8 -> V_262 )
return;
if ( V_271 )
V_273 = V_271 -> V_274 ;
if ( V_273 && V_273 -> V_275 )
(* V_273 -> V_275 )( V_271 ) ;
F_32 ( V_8 -> V_62 , V_63 ) ;
F_93 ( & V_8 -> V_276 ) ;
F_88 ( V_8 ) ;
}
static void F_94 ( struct V_277 * V_278 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( V_278 , struct V_1 , V_276 . V_278 ) ;
if ( V_8 -> V_86 )
F_95 ( V_8 -> V_86 ) ;
}
static T_3 F_96 ( int V_279 , void * V_280 )
{
struct V_1 * V_8 = V_280 ;
F_97 ( V_281 , & V_8 -> V_276 ,
F_98 ( V_282 ) ) ;
return V_283 ;
}
static int F_99 ( struct V_1 * V_8 ,
const struct V_284 * V_285 ,
struct V_35 * * V_286 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_285 -> V_29 ; ++ V_26 ) {
struct V_35 * V_35 = F_100 ( V_30 , V_285 -> V_31 [ V_26 ] ) ;
if ( F_101 ( V_35 ) ) {
int V_25 = F_102 ( V_35 ) ;
F_16 ( V_30 , L_22 ,
V_285 -> V_31 [ V_26 ] , V_25 ) ;
return V_25 ;
}
V_286 [ V_26 ] = V_35 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_8 )
{
const struct V_287 * V_12 = V_8 -> V_12 ;
int V_29 = V_12 -> V_28 . V_29 + V_12 -> V_34 . V_29 ;
struct V_33 * V_30 = V_8 -> V_30 ;
struct V_35 * * V_286 ;
int V_25 ;
if ( ! V_29 )
return 0 ;
V_286 = F_104 ( V_30 , sizeof( * V_286 ) * V_29 , V_288 ) ;
if ( ! V_286 )
return - V_289 ;
V_8 -> V_28 = V_286 ;
V_8 -> V_34 = V_286 + V_12 -> V_28 . V_29 ;
V_25 = F_99 ( V_8 , & V_12 -> V_28 , V_8 -> V_28 ) ;
if ( V_25 )
return V_25 ;
return F_99 ( V_8 , & V_12 -> V_34 , V_8 -> V_34 ) ;
}
static void F_105 ( struct V_290 * V_35 , bool V_251 )
{
struct V_1 * V_8 = F_2 ( V_35 , struct V_1 ,
V_291 ) ;
if ( V_251 )
F_84 ( V_8 ) ;
else
F_88 ( V_8 ) ;
}
static int F_106 ( struct V_1 * V_8 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
struct V_292 * V_293 , * V_294 ;
V_293 = F_107 ( V_30 -> V_295 , 1 , - 1 ) ;
if ( ! V_293 )
return 0 ;
V_294 = F_108 ( V_293 ) ;
F_109 ( V_293 ) ;
if ( ! V_294 ) {
F_48 ( L_23 ) ;
return - V_23 ;
}
V_8 -> V_90 = F_110 ( V_294 ) ;
F_109 ( V_294 ) ;
if ( ! V_8 -> V_90 )
return - V_296 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_8 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 , V_25 ;
F_39 ( L_24 ) ;
V_8 -> V_60 = F_112 ( V_30 , L_25 , V_297 ) ;
if ( F_101 ( V_8 -> V_60 ) ) {
F_48 ( L_26 ) ;
return F_102 ( V_8 -> V_60 ) ;
}
V_8 -> V_279 = F_113 ( V_8 -> V_60 ) ;
if ( V_8 -> V_279 < 0 ) {
F_48 ( L_27 ) ;
return V_8 -> V_279 ;
}
V_25 = F_103 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_19 ( V_8 , false ) ;
if ( V_25 )
return V_25 ;
for ( V_26 = 0 ; V_26 < F_87 ( V_263 ) ; ++ V_26 )
V_8 -> V_264 [ V_26 ] . V_263 = V_263 [ V_26 ] ;
V_25 = F_114 ( V_30 , F_87 ( V_263 ) , V_8 -> V_264 ) ;
if ( V_25 ) {
if ( V_25 != - V_296 )
F_48 ( L_28 ) ;
return V_25 ;
}
V_8 -> V_298 = F_115 ( V_30 , L_29 ) ;
if ( F_102 ( V_8 -> V_298 ) != - V_67 ) {
if ( F_101 ( V_8 -> V_298 ) )
return F_102 ( V_8 -> V_298 ) ;
V_25 = F_116 ( V_8 -> V_298 ) ;
if ( V_25 ) {
F_48 ( L_30 ) ;
return V_25 ;
}
}
return F_106 ( V_8 ) ;
}
static int F_117 ( struct V_33 * V_30 , struct V_33 * V_299 , void * V_31 )
{
struct V_92 * V_86 = V_31 ;
struct V_1 * V_8 = F_118 ( V_30 ) ;
struct V_2 * V_4 = & V_8 -> V_4 ;
struct V_300 * V_301 ;
struct V_270 * V_271 ;
int V_25 , V_302 ;
V_8 -> V_86 = V_86 ;
V_302 = F_119 ( V_86 ,
V_303 ) ;
if ( V_302 < 0 )
return V_302 ;
V_8 -> V_291 . V_251 = F_105 ;
V_271 = F_120 ( V_86 , V_302 ) ;
V_301 = F_121 ( V_271 ) ;
V_301 -> V_304 = & V_8 -> V_291 ;
V_4 -> V_305 = 1 << V_302 ;
F_39 ( L_31 , V_4 -> V_305 ) ;
F_122 ( V_86 , V_4 , & V_306 ,
V_307 , NULL ) ;
F_123 ( V_4 , & V_308 ) ;
V_25 = F_46 ( V_4 ) ;
if ( V_25 ) {
F_48 ( L_32 , V_25 ) ;
F_124 ( V_4 ) ;
return V_25 ;
}
return 0 ;
}
static void F_125 ( struct V_33 * V_30 , struct V_33 * V_299 , void * V_31 )
{
}
static int F_126 ( struct V_1 * V_8 )
{
const char * V_309 = L_33 ;
struct V_292 * V_294 ;
struct V_310 * V_311 ;
V_294 = F_127 ( NULL , NULL , V_309 ) ;
if ( V_294 )
V_294 = F_128 ( V_294 ) ;
else
V_294 = F_129 ( V_8 -> V_30 -> V_295 , L_34 , 0 ) ;
if ( ! V_294 ) {
F_48 ( L_35 ) ;
return - V_67 ;
}
V_311 = F_130 ( V_294 ) ;
F_109 ( V_294 ) ;
if ( ! V_311 ) {
F_24 ( L_36 ) ;
return - V_296 ;
}
V_8 -> V_66 = V_311 ;
return 0 ;
}
static int F_131 ( struct V_1 * V_8 )
{
const char * V_309 = L_37 ;
struct V_292 * V_294 ;
int V_25 = 0 ;
V_294 = F_127 ( NULL , NULL , V_309 ) ;
if ( ! V_294 ) {
V_294 = F_129 ( V_8 -> V_30 -> V_295 , L_38 , 0 ) ;
if ( ! V_294 ) {
F_48 ( L_39 ) ;
return - V_67 ;
}
}
if ( V_8 -> V_12 -> V_312 ) {
V_8 -> V_27 = F_132 ( V_294 , 0 ) ;
if ( ! V_8 -> V_27 ) {
F_48 ( L_40 ) ;
V_25 = - V_289 ;
goto V_313;
}
} else {
V_8 -> V_24 = F_133 ( V_294 ) ;
if ( ! V_8 -> V_24 ) {
F_24 ( L_41 ) ;
V_25 = - V_296 ;
goto V_313;
}
}
V_313:
F_109 ( V_294 ) ;
return V_25 ;
}
static int F_134 ( struct V_314 * V_315 )
{
struct V_33 * V_30 = & V_315 -> V_30 ;
struct V_1 * V_8 ;
struct V_316 * V_317 ;
int V_25 ;
V_8 = F_104 ( V_30 , sizeof( struct V_1 ) , V_288 ) ;
if ( ! V_8 )
return - V_289 ;
V_8 -> V_12 = F_135 ( V_30 ) ;
F_136 ( V_315 , V_8 ) ;
V_8 -> V_30 = V_30 ;
V_25 = F_111 ( V_8 ) ;
if ( V_25 ) {
if ( V_25 != - V_296 )
F_48 ( L_42 ) ;
return V_25 ;
}
V_317 = F_137 ( V_315 , V_318 , 0 ) ;
V_8 -> V_13 = F_138 ( V_30 , V_317 ) ;
if ( F_101 ( V_8 -> V_13 ) ) {
V_25 = F_102 ( V_8 -> V_13 ) ;
return V_25 ;
}
V_25 = F_126 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_131 ( V_8 ) ;
if ( V_25 )
goto V_319;
F_139 ( & V_8 -> V_276 , F_94 ) ;
V_25 = F_140 ( V_30 , V_8 -> V_279 , NULL ,
F_96 , V_320 |
V_321 | V_322 ,
L_43 , V_8 ) ;
if ( V_25 ) {
F_48 ( L_44 ) ;
goto V_323;
}
V_8 -> V_265 = F_141 ( V_30 -> V_295 ,
L_45 ) ;
if ( F_101 ( V_8 -> V_265 ) ) {
F_48 ( L_46 ) ;
V_25 = - V_296 ;
goto V_323;
}
if ( V_8 -> V_12 -> V_324 ) {
V_8 -> V_259 = F_141 ( V_30 -> V_295 ,
L_47 ) ;
if ( F_101 ( V_8 -> V_259 ) ) {
F_48 ( L_48 ) ;
V_25 = - V_296 ;
goto V_323;
}
}
V_8 -> V_62 = F_142 ( & V_315 -> V_30 ) ;
if ( V_8 -> V_62 == NULL ) {
V_25 = - V_289 ;
goto V_323;
}
F_143 ( V_30 ) ;
V_25 = F_144 ( & V_315 -> V_30 , & V_325 ) ;
if ( V_25 )
goto V_326;
return V_25 ;
V_326:
F_145 ( V_8 -> V_62 ) ;
F_146 ( V_30 ) ;
V_323:
if ( V_8 -> V_24 )
F_147 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_148 ( V_8 -> V_27 ) ;
V_319:
F_147 ( & V_8 -> V_66 -> V_30 ) ;
return V_25 ;
}
static int F_149 ( struct V_314 * V_315 )
{
struct V_1 * V_8 = F_150 ( V_315 ) ;
F_151 ( & V_8 -> V_276 ) ;
F_32 ( V_8 -> V_62 , V_63 ) ;
F_152 ( & V_315 -> V_30 , & V_325 ) ;
F_145 ( V_8 -> V_62 ) ;
F_146 ( & V_315 -> V_30 ) ;
if ( ! F_101 ( V_8 -> V_298 ) )
F_153 ( V_8 -> V_298 ) ;
if ( V_8 -> V_24 )
F_147 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_148 ( V_8 -> V_27 ) ;
F_147 ( & V_8 -> V_66 -> V_30 ) ;
return 0 ;
}
static int F_154 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_118 ( V_30 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int F_155 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_118 ( V_30 ) ;
int V_25 ;
V_25 = F_14 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
