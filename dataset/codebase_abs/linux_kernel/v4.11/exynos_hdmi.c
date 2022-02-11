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
return V_62 ;
}
static void F_32 ( struct V_5 * V_7 )
{
F_33 ( V_7 ) ;
F_34 ( V_7 ) ;
}
static int F_35 ( struct V_5 * V_7 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
struct V_63 * V_63 ;
int V_25 ;
if ( ! V_8 -> V_64 )
return - V_65 ;
V_63 = F_36 ( V_7 , V_8 -> V_64 ) ;
if ( ! V_63 )
return - V_65 ;
V_8 -> V_38 = ! F_37 ( V_63 ) ;
F_38 ( L_4 ,
( V_8 -> V_38 ? L_5 : L_6 ) ,
V_63 -> V_66 , V_63 -> V_67 ) ;
F_39 ( V_7 , V_63 ) ;
V_25 = F_40 ( V_7 , V_63 ) ;
F_41 ( V_63 ) ;
return V_25 ;
}
static int F_42 ( struct V_1 * V_8 , T_1 V_68 )
{
const struct V_69 * V_70 = & V_8 -> V_12 -> V_71 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_70 -> V_29 ; V_26 ++ )
if ( V_70 -> V_31 [ V_26 ] . V_68 == V_68 )
return V_26 ;
F_38 ( L_7 , V_68 ) ;
return - V_23 ;
}
static int F_43 ( struct V_5 * V_7 ,
struct V_72 * V_73 )
{
struct V_1 * V_8 = F_3 ( V_7 ) ;
int V_25 ;
F_38 ( L_8 ,
V_73 -> V_74 , V_73 -> V_75 , V_73 -> V_76 ,
( V_73 -> V_77 & V_78 ) ? true :
false , V_73 -> clock * 1000 ) ;
V_25 = F_42 ( V_8 , V_73 -> clock * 1000 ) ;
if ( V_25 < 0 )
return V_79 ;
return V_80 ;
}
static int F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_5 * V_7 = & V_8 -> V_7 ;
int V_25 ;
V_7 -> V_81 = true ;
V_7 -> V_82 = V_83 ;
V_25 = F_45 ( V_8 -> V_84 , V_7 ,
& V_85 , V_86 ) ;
if ( V_25 ) {
F_46 ( L_9 ) ;
return V_25 ;
}
F_47 ( V_7 , & V_87 ) ;
F_48 ( V_7 ) ;
F_49 ( V_7 , V_4 ) ;
if ( V_8 -> V_88 ) {
V_4 -> V_88 = V_8 -> V_88 ;
V_8 -> V_88 -> V_4 = V_4 ;
V_25 = F_50 ( V_4 , V_8 -> V_88 , NULL ) ;
if ( V_25 )
F_46 ( L_10 ) ;
}
return V_25 ;
}
static bool F_51 ( struct V_2 * V_4 ,
const struct V_72 * V_73 ,
struct V_72 * V_89 )
{
struct V_90 * V_30 = V_4 -> V_30 ;
struct V_5 * V_7 ;
struct V_72 * V_91 ;
int V_92 ;
F_52 ( V_89 , 0 ) ;
F_53 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_4 == V_4 )
break;
}
if ( V_7 -> V_4 != V_4 )
return true ;
V_92 = F_43 ( V_7 , V_89 ) ;
if ( V_92 == V_80 )
return true ;
F_53 (m, &connector->modes, head) {
V_92 = F_43 ( V_7 , V_91 ) ;
if ( V_92 == V_80 ) {
F_24 ( L_11 ) ;
F_24 ( L_12 ) ;
F_38 ( L_13 ,
V_91 -> V_74 , V_91 -> V_75 , V_91 -> V_76 ) ;
F_54 ( V_89 , V_91 ) ;
break;
}
}
return true ;
}
static void F_55 ( struct V_1 * V_8 , T_1 V_93 )
{
T_1 V_94 , V_95 ;
V_95 = ( V_93 % 9 ) ? 27000 : 30000 ;
V_94 = 128 * V_93 / ( 27000000 / V_95 ) ;
F_9 ( V_8 , V_96 , 3 , V_94 ) ;
F_9 ( V_8 , V_97 , 3 , V_95 ) ;
F_9 ( V_8 , V_98 , 3 , V_95 ) ;
F_7 ( V_8 , V_99 , 4 ) ;
}
static void F_56 ( struct V_1 * V_8 )
{
T_1 V_100 , V_101 ;
T_1 V_102 , V_103 , V_104 ;
T_1 V_16 ;
V_100 = 44100 ;
V_101 = 16 ;
switch ( V_101 ) {
case 20 :
V_102 = 2 ;
V_103 = 1 ;
break;
case 24 :
V_102 = 3 ;
V_103 = 1 ;
break;
default:
V_102 = 1 ;
V_103 = 0 ;
break;
}
F_55 ( V_8 , V_100 ) ;
F_7 ( V_8 , V_105 , V_106
| V_107 | V_108
| V_109 ) ;
F_7 ( V_8 , V_110 , V_111
| V_112 | V_113 ) ;
F_7 ( V_8 , V_114 , V_115 ) ;
V_104 = ( V_100 == 44100 ) ? 0 :
( V_100 == 48000 ) ? 2 :
( V_100 == 32000 ) ? 3 :
( V_100 == 96000 ) ? 0xa : 0x0 ;
F_7 ( V_8 , V_116 , V_117 ) ;
F_7 ( V_8 , V_116 , V_118 ) ;
V_16 = F_5 ( V_8 , V_119 ) | 0x01 ;
F_7 ( V_8 , V_119 , V_16 ) ;
F_7 ( V_8 , V_120 , F_57 ( 5 )
| F_58 ( 6 ) ) ;
F_7 ( V_8 , V_121 , F_59 ( 1 )
| F_60 ( 4 ) ) ;
F_7 ( V_8 , V_122 , F_61 ( 1 )
| F_60 ( 2 ) ) ;
F_7 ( V_8 , V_123 , F_62 ( 0 ) ) ;
F_7 ( V_8 , V_124 , V_125
| V_126 ) ;
F_7 ( V_8 , V_127 , V_128
| F_63 ( V_103 )
| F_64 ( V_102 )
| V_129 ) ;
F_7 ( V_8 , V_130 , V_131
| V_132
| V_133
| V_134
| V_135 ) ;
F_7 ( V_8 , V_136 , V_137 ) ;
F_7 ( V_8 , V_138 , F_65 ( 0 ) ) ;
F_7 ( V_8 , V_139 , V_140
| F_66 ( V_104 ) ) ;
F_7 ( V_8 , V_141 ,
V_142
| V_143
| V_144 ) ;
F_7 ( V_8 , V_145 , V_146 ) ;
}
static void F_67 ( struct V_1 * V_8 , bool V_147 )
{
if ( V_8 -> V_38 )
return;
F_7 ( V_8 , V_43 , V_147 ? 2 : 0 ) ;
F_11 ( V_8 , V_148 , V_147 ?
V_149 : V_150 , V_151 ) ;
}
static void F_68 ( struct V_1 * V_8 , bool V_152 )
{
T_1 V_16 = V_152 ? V_153 : 0 ;
if ( V_8 -> V_46 . V_77 & V_78 )
V_16 |= V_154 ;
F_11 ( V_8 , V_148 , V_16 , V_155 ) ;
F_11 ( V_8 , V_156 , V_16 , V_153 | V_154 ) ;
}
static void F_69 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_157 , 0 , V_158 |
V_159 | V_160 ) ;
F_11 ( V_8 , V_161 ,
V_162 , V_163 ) ;
F_7 ( V_8 , V_164 , 0 ) ;
F_11 ( V_8 , V_148 , 0 , V_165 ) ;
if ( V_8 -> V_38 ) {
F_11 ( V_8 , V_161 ,
V_166 , V_163 ) ;
F_7 ( V_8 , V_164 ,
V_167 | V_168 ) ;
}
if ( V_8 -> V_12 -> type == V_169 ) {
F_7 ( V_8 , V_170 , 0x12 ) ;
F_7 ( V_8 , V_171 , 0x34 ) ;
F_7 ( V_8 , V_172 , 0x56 ) ;
F_7 ( V_8 , V_173 , 0x02 ) ;
F_7 ( V_8 , F_70 ( 0 ) , 0 << 5 ) ;
F_11 ( V_8 , V_174 , 0x10 << 5 , 0x11 << 5 ) ;
F_7 ( V_8 , V_175 , 0x02 ) ;
F_7 ( V_8 , V_176 , 0x02 ) ;
F_7 ( V_8 , V_177 , 0x04 ) ;
} else {
F_21 ( V_8 ) ;
F_11 ( V_8 , V_174 , 2 , 3 << 5 ) ;
}
}
static void F_71 ( struct V_1 * V_8 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < 10 ; ++ V_178 ) {
T_1 V_16 = F_5 ( V_8 , V_179 ) ;
if ( V_16 & V_180 ) {
F_38 ( L_14 , V_178 ) ;
return;
}
F_72 ( 10 , 20 ) ;
}
F_46 ( L_15 ) ;
}
static void F_73 ( struct V_1 * V_8 )
{
struct V_72 * V_91 = & V_8 -> V_46 ;
unsigned int V_16 ;
F_9 ( V_8 , V_181 , 2 , V_91 -> V_182 - V_91 -> V_74 ) ;
F_9 ( V_8 , V_183 , 3 ,
( V_91 -> V_182 << 12 ) | V_91 -> V_184 ) ;
V_16 = ( V_91 -> V_77 & V_185 ) ? 1 : 0 ;
F_9 ( V_8 , V_186 , 1 , V_16 ) ;
V_16 = ( V_91 -> V_77 & V_78 ) ? 1 : 0 ;
F_9 ( V_8 , V_187 , 1 , V_16 ) ;
V_16 = ( V_91 -> V_188 - V_91 -> V_74 - 2 ) ;
V_16 |= ( ( V_91 -> V_189 - V_91 -> V_74 - 2 ) << 10 ) ;
V_16 |= ( ( V_91 -> V_77 & V_190 ) ? 1 : 0 ) << 20 ;
F_9 ( V_8 , V_191 , 3 , V_16 ) ;
if ( V_91 -> V_77 & V_78 ) {
V_16 = ( ( V_91 -> V_192 - V_91 -> V_75 ) / 2 ) ;
V_16 |= ( ( V_91 -> V_193 - V_91 -> V_75 ) / 2 ) << 12 ;
F_9 ( V_8 , V_194 , 3 , V_16 ) ;
V_16 = V_91 -> V_184 / 2 ;
V_16 |= ( ( V_91 -> V_184 - V_91 -> V_75 ) / 2 ) << 11 ;
F_9 ( V_8 , V_195 , 3 , V_16 ) ;
V_16 = ( V_91 -> V_184 +
( ( V_91 -> V_192 - V_91 -> V_193 ) * 4 ) + 5 ) / 2 ;
V_16 |= V_91 -> V_184 << 11 ;
F_9 ( V_8 , V_196 , 3 , V_16 ) ;
V_16 = ( ( V_91 -> V_184 / 2 ) + 7 ) ;
V_16 |= ( ( V_91 -> V_184 / 2 ) + 2 ) << 12 ;
F_9 ( V_8 , V_197 , 3 , V_16 ) ;
V_16 = ( ( V_91 -> V_182 / 2 ) + ( V_91 -> V_188 - V_91 -> V_74 ) ) ;
V_16 |= ( ( V_91 -> V_182 / 2 ) +
( V_91 -> V_188 - V_91 -> V_74 ) ) << 12 ;
F_9 ( V_8 , V_198 , 3 , V_16 ) ;
F_9 ( V_8 , V_199 , 2 ,
( V_91 -> V_184 - V_91 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_200 , 2 , V_91 -> V_75 / 2 ) ;
F_9 ( V_8 , V_201 , 2 , 0x249 ) ;
} else {
V_16 = V_91 -> V_184 ;
V_16 |= ( V_91 -> V_184 - V_91 -> V_75 ) << 11 ;
F_9 ( V_8 , V_195 , 3 , V_16 ) ;
F_9 ( V_8 , V_196 , 3 , 0 ) ;
V_16 = ( V_91 -> V_192 - V_91 -> V_75 ) ;
V_16 |= ( ( V_91 -> V_193 - V_91 -> V_75 ) << 12 ) ;
F_9 ( V_8 , V_194 , 3 , V_16 ) ;
F_9 ( V_8 , V_197 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_198 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_199 , 2 ,
V_91 -> V_184 - V_91 -> V_75 ) ;
F_9 ( V_8 , V_200 , 2 , V_91 -> V_75 ) ;
}
F_9 ( V_8 , V_202 , 2 , V_91 -> V_182 ) ;
F_9 ( V_8 , V_203 , 2 , V_91 -> V_182 - V_91 -> V_74 ) ;
F_9 ( V_8 , V_204 , 2 , V_91 -> V_74 ) ;
F_9 ( V_8 , V_205 , 2 , V_91 -> V_184 ) ;
}
static void F_74 ( struct V_1 * V_8 )
{
struct V_72 * V_91 = & V_8 -> V_46 ;
F_9 ( V_8 , V_181 , 2 , V_91 -> V_182 - V_91 -> V_74 ) ;
F_9 ( V_8 , V_206 , 2 , V_91 -> V_184 ) ;
F_9 ( V_8 , V_207 , 2 , V_91 -> V_182 ) ;
F_9 ( V_8 , V_208 , 1 ,
( V_91 -> V_77 & V_190 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_186 , 1 ,
( V_91 -> V_77 & V_185 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_187 , 1 ,
( V_91 -> V_77 & V_78 ) ? 1 : 0 ) ;
if ( V_91 -> V_77 & V_78 ) {
F_9 ( V_8 , V_209 , 2 ,
( V_91 -> V_192 - V_91 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_210 , 2 ,
( V_91 -> V_193 - V_91 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_211 , 2 , V_91 -> V_184 / 2 ) ;
F_9 ( V_8 , V_212 , 2 ,
( V_91 -> V_184 - V_91 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_213 , 2 ,
V_91 -> V_184 - V_91 -> V_75 / 2 ) ;
F_9 ( V_8 , V_214 , 2 , V_91 -> V_184 ) ;
F_9 ( V_8 , V_215 , 2 ,
( V_91 -> V_184 / 2 ) + 7 ) ;
F_9 ( V_8 , V_216 , 2 ,
( V_91 -> V_184 / 2 ) + 2 ) ;
F_9 ( V_8 , V_217 , 2 ,
( V_91 -> V_182 / 2 ) + ( V_91 -> V_188 - V_91 -> V_74 ) ) ;
F_9 ( V_8 , V_218 , 2 ,
( V_91 -> V_182 / 2 ) + ( V_91 -> V_188 - V_91 -> V_74 ) ) ;
F_9 ( V_8 , V_199 , 2 ,
( V_91 -> V_184 - V_91 -> V_75 ) / 2 ) ;
F_9 ( V_8 , V_200 , 2 , V_91 -> V_75 / 2 ) ;
F_9 ( V_8 , V_201 , 2 ,
V_91 -> V_184 - V_91 -> V_75 / 2 ) ;
F_9 ( V_8 , V_219 , 2 ,
( V_91 -> V_184 / 2 ) + 1 ) ;
F_9 ( V_8 , V_220 , 2 ,
( V_91 -> V_184 / 2 ) + 1 ) ;
F_9 ( V_8 , V_221 , 2 ,
( V_91 -> V_184 / 2 ) + 1 ) ;
F_9 ( V_8 , V_222 , 2 , 0x0 ) ;
F_9 ( V_8 , V_223 , 2 , 0x0 ) ;
} else {
F_9 ( V_8 , V_209 , 2 ,
V_91 -> V_192 - V_91 -> V_75 ) ;
F_9 ( V_8 , V_210 , 2 ,
V_91 -> V_193 - V_91 -> V_75 ) ;
F_9 ( V_8 , V_211 , 2 , V_91 -> V_184 ) ;
F_9 ( V_8 , V_212 , 2 ,
V_91 -> V_184 - V_91 -> V_75 ) ;
F_9 ( V_8 , V_213 , 2 , 0xffff ) ;
F_9 ( V_8 , V_214 , 2 , 0xffff ) ;
F_9 ( V_8 , V_215 , 2 , 0xffff ) ;
F_9 ( V_8 , V_216 , 2 , 0xffff ) ;
F_9 ( V_8 , V_217 , 2 , 0xffff ) ;
F_9 ( V_8 , V_218 , 2 , 0xffff ) ;
F_9 ( V_8 , V_199 , 2 ,
V_91 -> V_184 - V_91 -> V_75 ) ;
F_9 ( V_8 , V_200 , 2 , V_91 -> V_75 ) ;
}
F_9 ( V_8 , V_224 , 2 ,
V_91 -> V_188 - V_91 -> V_74 - 2 ) ;
F_9 ( V_8 , V_225 , 2 ,
V_91 -> V_189 - V_91 -> V_74 - 2 ) ;
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
F_9 ( V_8 , V_243 , 2 , 0xffff ) ;
F_9 ( V_8 , V_202 , 2 , V_91 -> V_182 ) ;
F_9 ( V_8 , V_203 , 2 , V_91 -> V_182 - V_91 -> V_74 ) ;
F_9 ( V_8 , V_204 , 2 , V_91 -> V_74 ) ;
F_9 ( V_8 , V_205 , 2 , V_91 -> V_184 ) ;
if ( V_8 -> V_12 == & V_244 )
F_7 ( V_8 , V_245 , 1 ) ;
}
static void F_75 ( struct V_1 * V_8 )
{
if ( V_8 -> V_12 -> type == V_169 )
F_73 ( V_8 ) ;
else
F_74 ( V_8 ) ;
F_68 ( V_8 , true ) ;
}
static void F_76 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_246 , 0 , 1 ) ;
F_72 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_246 , ~ 0 , 1 ) ;
F_72 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_247 , ~ 0 , V_248 ) ;
F_72 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_247 , 0 , V_248 ) ;
F_72 ( 10000 , 12000 ) ;
}
static void F_77 ( struct V_1 * V_8 , bool V_249 )
{
T_2 V_250 = V_249 ? V_251 : V_252 ;
if ( V_8 -> V_12 == & V_244 )
F_8 ( V_250 , V_8 -> V_27 + V_253 ) ;
}
static void F_78 ( struct V_1 * V_8 )
{
int V_25 ;
const T_2 * V_254 ;
V_25 = F_42 ( V_8 , V_8 -> V_46 . clock * 1000 ) ;
if ( V_25 < 0 ) {
F_46 ( L_16 ) ;
return;
}
V_254 = V_8 -> V_12 -> V_71 . V_31 [ V_25 ] . V_255 ;
F_19 ( V_8 , false ) ;
F_76 ( V_8 ) ;
F_77 ( V_8 , true ) ;
V_25 = F_12 ( V_8 , 0 , V_254 , 32 ) ;
if ( V_25 ) {
F_46 ( L_17 ) ;
return;
}
F_77 ( V_8 , false ) ;
F_19 ( V_8 , true ) ;
F_72 ( 10000 , 12000 ) ;
F_71 ( V_8 ) ;
}
static void F_79 ( struct V_1 * V_8 )
{
F_68 ( V_8 , false ) ;
F_69 ( V_8 ) ;
F_56 ( V_8 ) ;
F_75 ( V_8 ) ;
F_67 ( V_8 , true ) ;
}
static void F_80 ( struct V_2 * V_4 ,
struct V_72 * V_73 ,
struct V_72 * V_89 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_72 * V_91 = V_89 ;
F_38 ( L_18 ,
V_91 -> V_74 , V_91 -> V_75 ,
V_91 -> V_76 , ( V_91 -> V_77 & V_78 ) ?
L_19 : L_20 ) ;
F_54 ( & V_8 -> V_46 , V_91 ) ;
}
static void F_81 ( struct V_1 * V_8 , bool V_256 )
{
if ( ! V_8 -> V_257 )
return;
F_82 ( V_8 -> V_257 , V_258 ,
V_259 , V_256 ? ~ 0 : 0 ) ;
}
static void F_83 ( struct V_1 * V_8 )
{
if ( V_8 -> V_260 )
return;
F_84 ( V_8 -> V_30 ) ;
if ( F_85 ( F_86 ( V_261 ) , V_8 -> V_262 ) )
F_38 ( L_21 ) ;
F_82 ( V_8 -> V_263 , V_264 ,
V_265 , 1 ) ;
F_81 ( V_8 , true ) ;
F_11 ( V_8 , V_266 , 0 , V_267 ) ;
F_78 ( V_8 ) ;
V_8 -> V_260 = true ;
}
static void F_87 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_260 )
return;
F_11 ( V_8 , V_148 , 0 , V_155 ) ;
F_11 ( V_8 , V_266 , ~ 0 , V_267 ) ;
F_81 ( V_8 , false ) ;
F_82 ( V_8 -> V_263 , V_264 ,
V_265 , 0 ) ;
F_88 ( F_86 ( V_261 ) , V_8 -> V_262 ) ;
F_89 ( V_8 -> V_30 ) ;
V_8 -> V_260 = false ;
}
static void F_90 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_83 ( V_8 ) ;
F_79 ( V_8 ) ;
}
static void F_91 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_268 * V_269 = V_4 -> V_269 ;
const struct V_270 * V_271 = NULL ;
if ( ! V_8 -> V_260 )
return;
if ( V_269 )
V_271 = V_269 -> V_272 ;
if ( V_271 && V_271 -> V_273 )
(* V_271 -> V_273 )( V_269 ) ;
F_92 ( & V_8 -> V_274 ) ;
F_87 ( V_8 ) ;
}
static void F_93 ( struct V_275 * V_276 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( V_276 , struct V_1 , V_274 . V_276 ) ;
if ( V_8 -> V_84 )
F_94 ( V_8 -> V_84 ) ;
}
static T_3 F_95 ( int V_277 , void * V_278 )
{
struct V_1 * V_8 = V_278 ;
F_96 ( V_279 , & V_8 -> V_274 ,
F_97 ( V_280 ) ) ;
return V_281 ;
}
static int F_98 ( struct V_1 * V_8 ,
const struct V_282 * V_283 ,
struct V_35 * * V_284 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_283 -> V_29 ; ++ V_26 ) {
struct V_35 * V_35 = F_99 ( V_30 , V_283 -> V_31 [ V_26 ] ) ;
if ( F_100 ( V_35 ) ) {
int V_25 = F_101 ( V_35 ) ;
F_16 ( V_30 , L_22 ,
V_283 -> V_31 [ V_26 ] , V_25 ) ;
return V_25 ;
}
V_284 [ V_26 ] = V_35 ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_8 )
{
const struct V_285 * V_12 = V_8 -> V_12 ;
int V_29 = V_12 -> V_28 . V_29 + V_12 -> V_34 . V_29 ;
struct V_33 * V_30 = V_8 -> V_30 ;
struct V_35 * * V_284 ;
int V_25 ;
if ( ! V_29 )
return 0 ;
V_284 = F_103 ( V_30 , sizeof( * V_284 ) * V_29 , V_286 ) ;
if ( ! V_284 )
return - V_287 ;
V_8 -> V_28 = V_284 ;
V_8 -> V_34 = V_284 + V_12 -> V_28 . V_29 ;
V_25 = F_98 ( V_8 , & V_12 -> V_28 , V_8 -> V_28 ) ;
if ( V_25 )
return V_25 ;
return F_98 ( V_8 , & V_12 -> V_34 , V_8 -> V_34 ) ;
}
static void F_104 ( struct V_288 * V_35 , bool V_249 )
{
struct V_1 * V_8 = F_2 ( V_35 , struct V_1 ,
V_289 ) ;
if ( V_249 )
F_83 ( V_8 ) ;
else
F_87 ( V_8 ) ;
}
static int F_105 ( struct V_1 * V_8 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
struct V_290 * V_291 , * V_292 ;
V_291 = F_106 ( V_30 -> V_293 , 1 , - 1 ) ;
if ( ! V_291 )
return 0 ;
V_292 = F_107 ( V_291 ) ;
F_108 ( V_291 ) ;
if ( ! V_292 ) {
F_46 ( L_23 ) ;
return - V_23 ;
}
V_8 -> V_88 = F_109 ( V_292 ) ;
F_108 ( V_292 ) ;
if ( ! V_8 -> V_88 )
return - V_294 ;
return 0 ;
}
static int F_110 ( struct V_1 * V_8 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 , V_25 ;
F_38 ( L_24 ) ;
V_8 -> V_60 = F_111 ( V_30 , L_25 , V_295 ) ;
if ( F_100 ( V_8 -> V_60 ) ) {
F_46 ( L_26 ) ;
return F_101 ( V_8 -> V_60 ) ;
}
V_8 -> V_277 = F_112 ( V_8 -> V_60 ) ;
if ( V_8 -> V_277 < 0 ) {
F_46 ( L_27 ) ;
return V_8 -> V_277 ;
}
V_25 = F_102 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_19 ( V_8 , false ) ;
if ( V_25 )
return V_25 ;
for ( V_26 = 0 ; V_26 < F_86 ( V_261 ) ; ++ V_26 )
V_8 -> V_262 [ V_26 ] . V_261 = V_261 [ V_26 ] ;
V_25 = F_113 ( V_30 , F_86 ( V_261 ) , V_8 -> V_262 ) ;
if ( V_25 ) {
if ( V_25 != - V_294 )
F_46 ( L_28 ) ;
return V_25 ;
}
V_8 -> V_296 = F_114 ( V_30 , L_29 ) ;
if ( F_101 ( V_8 -> V_296 ) != - V_65 ) {
if ( F_100 ( V_8 -> V_296 ) )
return F_101 ( V_8 -> V_296 ) ;
V_25 = F_115 ( V_8 -> V_296 ) ;
if ( V_25 ) {
F_46 ( L_30 ) ;
return V_25 ;
}
}
return F_105 ( V_8 ) ;
}
static int F_116 ( struct V_33 * V_30 , struct V_33 * V_297 , void * V_31 )
{
struct V_90 * V_84 = V_31 ;
struct V_1 * V_8 = F_117 ( V_30 ) ;
struct V_2 * V_4 = & V_8 -> V_4 ;
int V_25 , V_298 ;
V_8 -> V_84 = V_84 ;
V_298 = F_118 ( V_84 ,
V_299 ) ;
if ( V_298 < 0 )
return V_298 ;
V_8 -> V_289 . V_249 = F_104 ;
F_119 ( V_84 , V_298 ) -> V_300 = & V_8 -> V_289 ;
V_4 -> V_301 = 1 << V_298 ;
F_38 ( L_31 , V_4 -> V_301 ) ;
F_120 ( V_84 , V_4 , & V_302 ,
V_303 , NULL ) ;
F_121 ( V_4 , & V_304 ) ;
V_25 = F_44 ( V_4 ) ;
if ( V_25 ) {
F_46 ( L_32 , V_25 ) ;
F_122 ( V_4 ) ;
return V_25 ;
}
return 0 ;
}
static void F_123 ( struct V_33 * V_30 , struct V_33 * V_297 , void * V_31 )
{
}
static int F_124 ( struct V_1 * V_8 )
{
const char * V_305 = L_33 ;
struct V_290 * V_292 ;
struct V_306 * V_307 ;
V_292 = F_125 ( NULL , NULL , V_305 ) ;
if ( V_292 )
V_292 = F_126 ( V_292 ) ;
else
V_292 = F_127 ( V_8 -> V_30 -> V_293 , L_34 , 0 ) ;
if ( ! V_292 ) {
F_46 ( L_35 ) ;
return - V_65 ;
}
V_307 = F_128 ( V_292 ) ;
F_108 ( V_292 ) ;
if ( ! V_307 ) {
F_24 ( L_36 ) ;
return - V_294 ;
}
V_8 -> V_64 = V_307 ;
return 0 ;
}
static int F_129 ( struct V_1 * V_8 )
{
const char * V_305 = L_37 ;
struct V_290 * V_292 ;
int V_25 = 0 ;
V_292 = F_125 ( NULL , NULL , V_305 ) ;
if ( ! V_292 ) {
V_292 = F_127 ( V_8 -> V_30 -> V_293 , L_38 , 0 ) ;
if ( ! V_292 ) {
F_46 ( L_39 ) ;
return - V_65 ;
}
}
if ( V_8 -> V_12 -> V_308 ) {
V_8 -> V_27 = F_130 ( V_292 , 0 ) ;
if ( ! V_8 -> V_27 ) {
F_46 ( L_40 ) ;
V_25 = - V_287 ;
goto V_309;
}
} else {
V_8 -> V_24 = F_131 ( V_292 ) ;
if ( ! V_8 -> V_24 ) {
F_24 ( L_41 ) ;
V_25 = - V_294 ;
goto V_309;
}
}
V_309:
F_108 ( V_292 ) ;
return V_25 ;
}
static int F_132 ( struct V_310 * V_311 )
{
struct V_33 * V_30 = & V_311 -> V_30 ;
struct V_1 * V_8 ;
struct V_312 * V_313 ;
int V_25 ;
V_8 = F_103 ( V_30 , sizeof( struct V_1 ) , V_286 ) ;
if ( ! V_8 )
return - V_287 ;
V_8 -> V_12 = F_133 ( V_30 ) ;
F_134 ( V_311 , V_8 ) ;
V_8 -> V_30 = V_30 ;
V_25 = F_110 ( V_8 ) ;
if ( V_25 ) {
if ( V_25 != - V_294 )
F_46 ( L_42 ) ;
return V_25 ;
}
V_313 = F_135 ( V_311 , V_314 , 0 ) ;
V_8 -> V_13 = F_136 ( V_30 , V_313 ) ;
if ( F_100 ( V_8 -> V_13 ) ) {
V_25 = F_101 ( V_8 -> V_13 ) ;
return V_25 ;
}
V_25 = F_124 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_129 ( V_8 ) ;
if ( V_25 )
goto V_315;
F_137 ( & V_8 -> V_274 , F_93 ) ;
V_25 = F_138 ( V_30 , V_8 -> V_277 , NULL ,
F_95 , V_316 |
V_317 | V_318 ,
L_43 , V_8 ) ;
if ( V_25 ) {
F_46 ( L_44 ) ;
goto V_319;
}
V_8 -> V_263 = F_139 ( V_30 -> V_293 ,
L_45 ) ;
if ( F_100 ( V_8 -> V_263 ) ) {
F_46 ( L_46 ) ;
V_25 = - V_294 ;
goto V_319;
}
if ( V_8 -> V_12 -> V_320 ) {
V_8 -> V_257 = F_139 ( V_30 -> V_293 ,
L_47 ) ;
if ( F_100 ( V_8 -> V_257 ) ) {
F_46 ( L_48 ) ;
V_25 = - V_294 ;
goto V_319;
}
}
F_140 ( V_30 ) ;
V_25 = F_141 ( & V_311 -> V_30 , & V_321 ) ;
if ( V_25 )
goto V_322;
return V_25 ;
V_322:
F_142 ( V_30 ) ;
V_319:
if ( V_8 -> V_24 )
F_143 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_144 ( V_8 -> V_27 ) ;
V_315:
F_143 ( & V_8 -> V_64 -> V_30 ) ;
return V_25 ;
}
static int F_145 ( struct V_310 * V_311 )
{
struct V_1 * V_8 = F_146 ( V_311 ) ;
F_147 ( & V_8 -> V_274 ) ;
F_148 ( & V_311 -> V_30 , & V_321 ) ;
F_142 ( & V_311 -> V_30 ) ;
if ( ! F_100 ( V_8 -> V_296 ) )
F_149 ( V_8 -> V_296 ) ;
if ( V_8 -> V_24 )
F_143 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_144 ( V_8 -> V_27 ) ;
F_143 ( & V_8 -> V_64 -> V_30 ) ;
return 0 ;
}
static int F_150 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_117 ( V_30 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int F_151 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_117 ( V_30 ) ;
int V_25 ;
V_25 = F_14 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
