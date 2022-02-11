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
& V_8 -> V_46 , false ) ;
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
struct V_94 V_95 ;
int V_96 ;
F_53 ( V_91 , 0 ) ;
F_54 ( V_30 , & V_95 ) ;
F_55 (connector, &conn_iter) {
if ( V_7 -> V_4 == V_4 )
break;
}
if ( V_7 )
F_56 ( V_7 ) ;
F_57 ( & V_95 ) ;
if ( ! V_7 )
return true ;
V_96 = F_45 ( V_7 , V_91 ) ;
if ( V_96 == V_82 )
goto V_97;
F_58 (m, &connector->modes, head) {
V_96 = F_45 ( V_7 , V_93 ) ;
if ( V_96 == V_82 ) {
F_24 ( L_11 ) ;
F_24 ( L_12 ) ;
F_39 ( L_13 ,
V_93 -> V_76 , V_93 -> V_77 , V_93 -> V_78 ) ;
F_59 ( V_91 , V_93 ) ;
break;
}
}
V_97:
F_60 ( V_7 ) ;
return true ;
}
static void F_61 ( struct V_1 * V_8 , T_1 V_98 )
{
T_1 V_99 , V_100 ;
V_100 = ( V_98 % 9 ) ? 27000 : 30000 ;
V_99 = 128 * V_98 / ( 27000000 / V_100 ) ;
F_9 ( V_8 , V_101 , 3 , V_99 ) ;
F_9 ( V_8 , V_102 , 3 , V_100 ) ;
F_9 ( V_8 , V_103 , 3 , V_100 ) ;
F_7 ( V_8 , V_104 , 4 ) ;
}
static void F_62 ( struct V_1 * V_8 )
{
T_1 V_105 , V_106 ;
T_1 V_107 , V_108 , V_109 ;
T_1 V_16 ;
V_105 = 44100 ;
V_106 = 16 ;
switch ( V_106 ) {
case 20 :
V_107 = 2 ;
V_108 = 1 ;
break;
case 24 :
V_107 = 3 ;
V_108 = 1 ;
break;
default:
V_107 = 1 ;
V_108 = 0 ;
break;
}
F_61 ( V_8 , V_105 ) ;
F_7 ( V_8 , V_110 , V_111
| V_112 | V_113
| V_114 ) ;
F_7 ( V_8 , V_115 , V_116
| V_117 | V_118 ) ;
F_7 ( V_8 , V_119 , V_120 ) ;
V_109 = ( V_105 == 44100 ) ? 0 :
( V_105 == 48000 ) ? 2 :
( V_105 == 32000 ) ? 3 :
( V_105 == 96000 ) ? 0xa : 0x0 ;
F_7 ( V_8 , V_121 , V_122 ) ;
F_7 ( V_8 , V_121 , V_123 ) ;
V_16 = F_5 ( V_8 , V_124 ) | 0x01 ;
F_7 ( V_8 , V_124 , V_16 ) ;
F_7 ( V_8 , V_125 , F_63 ( 5 )
| F_64 ( 6 ) ) ;
F_7 ( V_8 , V_126 , F_65 ( 1 )
| F_66 ( 4 ) ) ;
F_7 ( V_8 , V_127 , F_67 ( 1 )
| F_66 ( 2 ) ) ;
F_7 ( V_8 , V_128 , F_68 ( 0 ) ) ;
F_7 ( V_8 , V_129 , V_130
| V_131 ) ;
F_7 ( V_8 , V_132 , V_133
| F_69 ( V_108 )
| F_70 ( V_107 )
| V_134 ) ;
F_7 ( V_8 , V_135 , V_136
| V_137
| V_138
| V_139
| V_140 ) ;
F_7 ( V_8 , V_141 , V_142 ) ;
F_7 ( V_8 , V_143 , F_71 ( 0 ) ) ;
F_7 ( V_8 , V_144 , V_145
| F_72 ( V_109 ) ) ;
F_7 ( V_8 , V_146 ,
V_147
| V_148
| V_149 ) ;
F_7 ( V_8 , V_150 , V_151 ) ;
}
static void F_73 ( struct V_1 * V_8 , bool V_152 )
{
if ( V_8 -> V_38 )
return;
F_7 ( V_8 , V_43 , V_152 ? 2 : 0 ) ;
F_11 ( V_8 , V_153 , V_152 ?
V_154 : V_155 , V_156 ) ;
}
static void F_74 ( struct V_1 * V_8 , bool V_157 )
{
T_1 V_16 = V_157 ? V_158 : 0 ;
if ( V_8 -> V_46 . V_79 & V_80 )
V_16 |= V_159 ;
F_11 ( V_8 , V_153 , V_16 , V_160 ) ;
F_11 ( V_8 , V_161 , V_16 , V_158 | V_159 ) ;
}
static void F_75 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_162 , 0 , V_163 |
V_164 | V_165 ) ;
F_11 ( V_8 , V_166 ,
V_167 , V_168 ) ;
F_7 ( V_8 , V_169 , 0 ) ;
F_11 ( V_8 , V_153 , 0 , V_170 ) ;
if ( V_8 -> V_38 ) {
F_11 ( V_8 , V_166 ,
V_171 , V_168 ) ;
F_7 ( V_8 , V_169 ,
V_172 | V_173 ) ;
}
if ( V_8 -> V_12 -> type == V_174 ) {
F_7 ( V_8 , V_175 , 0x12 ) ;
F_7 ( V_8 , V_176 , 0x34 ) ;
F_7 ( V_8 , V_177 , 0x56 ) ;
F_7 ( V_8 , V_178 , 0x02 ) ;
F_7 ( V_8 , F_76 ( 0 ) , 0 << 5 ) ;
F_11 ( V_8 , V_179 , 0x10 << 5 , 0x11 << 5 ) ;
F_7 ( V_8 , V_180 , 0x02 ) ;
F_7 ( V_8 , V_181 , 0x02 ) ;
F_7 ( V_8 , V_182 , 0x04 ) ;
} else {
F_21 ( V_8 ) ;
F_11 ( V_8 , V_179 , 2 , 3 << 5 ) ;
}
}
static void F_77 ( struct V_1 * V_8 )
{
int V_183 ;
for ( V_183 = 0 ; V_183 < 10 ; ++ V_183 ) {
T_1 V_16 = F_5 ( V_8 , V_184 ) ;
if ( V_16 & V_185 ) {
F_39 ( L_14 , V_183 ) ;
return;
}
F_78 ( 10 , 20 ) ;
}
F_48 ( L_15 ) ;
}
static void F_79 ( struct V_1 * V_8 )
{
struct V_74 * V_93 = & V_8 -> V_46 ;
unsigned int V_16 ;
F_9 ( V_8 , V_186 , 2 , V_93 -> V_187 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_188 , 3 ,
( V_93 -> V_187 << 12 ) | V_93 -> V_189 ) ;
V_16 = ( V_93 -> V_79 & V_190 ) ? 1 : 0 ;
F_9 ( V_8 , V_191 , 1 , V_16 ) ;
V_16 = ( V_93 -> V_79 & V_80 ) ? 1 : 0 ;
F_9 ( V_8 , V_192 , 1 , V_16 ) ;
V_16 = ( V_93 -> V_193 - V_93 -> V_76 - 2 ) ;
V_16 |= ( ( V_93 -> V_194 - V_93 -> V_76 - 2 ) << 10 ) ;
V_16 |= ( ( V_93 -> V_79 & V_195 ) ? 1 : 0 ) << 20 ;
F_9 ( V_8 , V_196 , 3 , V_16 ) ;
if ( V_93 -> V_79 & V_80 ) {
V_16 = ( ( V_93 -> V_197 - V_93 -> V_77 ) / 2 ) ;
V_16 |= ( ( V_93 -> V_198 - V_93 -> V_77 ) / 2 ) << 12 ;
F_9 ( V_8 , V_199 , 3 , V_16 ) ;
V_16 = V_93 -> V_189 / 2 ;
V_16 |= ( ( V_93 -> V_189 - V_93 -> V_77 ) / 2 ) << 11 ;
F_9 ( V_8 , V_200 , 3 , V_16 ) ;
V_16 = ( V_93 -> V_189 +
( ( V_93 -> V_197 - V_93 -> V_198 ) * 4 ) + 5 ) / 2 ;
V_16 |= V_93 -> V_189 << 11 ;
F_9 ( V_8 , V_201 , 3 , V_16 ) ;
V_16 = ( ( V_93 -> V_189 / 2 ) + 7 ) ;
V_16 |= ( ( V_93 -> V_189 / 2 ) + 2 ) << 12 ;
F_9 ( V_8 , V_202 , 3 , V_16 ) ;
V_16 = ( ( V_93 -> V_187 / 2 ) + ( V_93 -> V_193 - V_93 -> V_76 ) ) ;
V_16 |= ( ( V_93 -> V_187 / 2 ) +
( V_93 -> V_193 - V_93 -> V_76 ) ) << 12 ;
F_9 ( V_8 , V_203 , 3 , V_16 ) ;
F_9 ( V_8 , V_204 , 2 ,
( V_93 -> V_189 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_205 , 2 , V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_206 , 2 , 0x249 ) ;
} else {
V_16 = V_93 -> V_189 ;
V_16 |= ( V_93 -> V_189 - V_93 -> V_77 ) << 11 ;
F_9 ( V_8 , V_200 , 3 , V_16 ) ;
F_9 ( V_8 , V_201 , 3 , 0 ) ;
V_16 = ( V_93 -> V_197 - V_93 -> V_77 ) ;
V_16 |= ( ( V_93 -> V_198 - V_93 -> V_77 ) << 12 ) ;
F_9 ( V_8 , V_199 , 3 , V_16 ) ;
F_9 ( V_8 , V_202 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_203 , 3 , 0x1001 ) ;
F_9 ( V_8 , V_204 , 2 ,
V_93 -> V_189 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_205 , 2 , V_93 -> V_77 ) ;
}
F_9 ( V_8 , V_207 , 2 , V_93 -> V_187 ) ;
F_9 ( V_8 , V_208 , 2 , V_93 -> V_187 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_209 , 2 , V_93 -> V_76 ) ;
F_9 ( V_8 , V_210 , 2 , V_93 -> V_189 ) ;
}
static void F_80 ( struct V_1 * V_8 )
{
struct V_74 * V_93 = & V_8 -> V_46 ;
F_9 ( V_8 , V_186 , 2 , V_93 -> V_187 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_211 , 2 , V_93 -> V_189 ) ;
F_9 ( V_8 , V_212 , 2 , V_93 -> V_187 ) ;
F_9 ( V_8 , V_213 , 1 ,
( V_93 -> V_79 & V_195 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_191 , 1 ,
( V_93 -> V_79 & V_190 ) ? 1 : 0 ) ;
F_9 ( V_8 , V_192 , 1 ,
( V_93 -> V_79 & V_80 ) ? 1 : 0 ) ;
if ( V_93 -> V_79 & V_80 ) {
F_9 ( V_8 , V_214 , 2 ,
( V_93 -> V_197 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_215 , 2 ,
( V_93 -> V_198 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_216 , 2 , V_93 -> V_189 / 2 ) ;
F_9 ( V_8 , V_217 , 2 ,
( V_93 -> V_189 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_218 , 2 ,
V_93 -> V_189 - V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_219 , 2 , V_93 -> V_189 ) ;
F_9 ( V_8 , V_220 , 2 ,
( V_93 -> V_189 / 2 ) + 7 ) ;
F_9 ( V_8 , V_221 , 2 ,
( V_93 -> V_189 / 2 ) + 2 ) ;
F_9 ( V_8 , V_222 , 2 ,
( V_93 -> V_187 / 2 ) + ( V_93 -> V_193 - V_93 -> V_76 ) ) ;
F_9 ( V_8 , V_223 , 2 ,
( V_93 -> V_187 / 2 ) + ( V_93 -> V_193 - V_93 -> V_76 ) ) ;
F_9 ( V_8 , V_204 , 2 ,
( V_93 -> V_189 - V_93 -> V_77 ) / 2 ) ;
F_9 ( V_8 , V_205 , 2 , V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_206 , 2 ,
V_93 -> V_189 - V_93 -> V_77 / 2 ) ;
F_9 ( V_8 , V_224 , 2 ,
( V_93 -> V_189 / 2 ) + 1 ) ;
F_9 ( V_8 , V_225 , 2 ,
( V_93 -> V_189 / 2 ) + 1 ) ;
F_9 ( V_8 , V_226 , 2 ,
( V_93 -> V_189 / 2 ) + 1 ) ;
F_9 ( V_8 , V_227 , 2 , 0x0 ) ;
F_9 ( V_8 , V_228 , 2 , 0x0 ) ;
} else {
F_9 ( V_8 , V_214 , 2 ,
V_93 -> V_197 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_215 , 2 ,
V_93 -> V_198 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_216 , 2 , V_93 -> V_189 ) ;
F_9 ( V_8 , V_217 , 2 ,
V_93 -> V_189 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_218 , 2 , 0xffff ) ;
F_9 ( V_8 , V_219 , 2 , 0xffff ) ;
F_9 ( V_8 , V_220 , 2 , 0xffff ) ;
F_9 ( V_8 , V_221 , 2 , 0xffff ) ;
F_9 ( V_8 , V_222 , 2 , 0xffff ) ;
F_9 ( V_8 , V_223 , 2 , 0xffff ) ;
F_9 ( V_8 , V_204 , 2 ,
V_93 -> V_189 - V_93 -> V_77 ) ;
F_9 ( V_8 , V_205 , 2 , V_93 -> V_77 ) ;
}
F_9 ( V_8 , V_229 , 2 ,
V_93 -> V_193 - V_93 -> V_76 - 2 ) ;
F_9 ( V_8 , V_230 , 2 ,
V_93 -> V_194 - V_93 -> V_76 - 2 ) ;
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
F_9 ( V_8 , V_246 , 2 , 0xffff ) ;
F_9 ( V_8 , V_247 , 2 , 0xffff ) ;
F_9 ( V_8 , V_248 , 2 , 0xffff ) ;
F_9 ( V_8 , V_207 , 2 , V_93 -> V_187 ) ;
F_9 ( V_8 , V_208 , 2 , V_93 -> V_187 - V_93 -> V_76 ) ;
F_9 ( V_8 , V_209 , 2 , V_93 -> V_76 ) ;
F_9 ( V_8 , V_210 , 2 , V_93 -> V_189 ) ;
if ( V_8 -> V_12 == & V_249 )
F_7 ( V_8 , V_250 , 1 ) ;
}
static void F_81 ( struct V_1 * V_8 )
{
if ( V_8 -> V_12 -> type == V_174 )
F_79 ( V_8 ) ;
else
F_80 ( V_8 ) ;
F_74 ( V_8 , true ) ;
}
static void F_82 ( struct V_1 * V_8 )
{
F_11 ( V_8 , V_251 , 0 , 1 ) ;
F_78 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_251 , ~ 0 , 1 ) ;
F_78 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_252 , ~ 0 , V_253 ) ;
F_78 ( 10000 , 12000 ) ;
F_11 ( V_8 , V_252 , 0 , V_253 ) ;
F_78 ( 10000 , 12000 ) ;
}
static void F_83 ( struct V_1 * V_8 , bool V_254 )
{
T_2 V_255 = V_254 ? V_256 : V_257 ;
if ( V_8 -> V_12 == & V_249 )
F_8 ( V_255 , V_8 -> V_27 + V_258 ) ;
}
static void F_84 ( struct V_1 * V_8 )
{
int V_25 ;
const T_2 * V_259 ;
V_25 = F_44 ( V_8 , V_8 -> V_46 . clock * 1000 ) ;
if ( V_25 < 0 ) {
F_48 ( L_16 ) ;
return;
}
V_259 = V_8 -> V_12 -> V_73 . V_31 [ V_25 ] . V_260 ;
F_19 ( V_8 , false ) ;
F_82 ( V_8 ) ;
F_83 ( V_8 , true ) ;
V_25 = F_12 ( V_8 , 0 , V_259 , 32 ) ;
if ( V_25 ) {
F_48 ( L_17 ) ;
return;
}
F_83 ( V_8 , false ) ;
F_19 ( V_8 , true ) ;
F_78 ( 10000 , 12000 ) ;
F_77 ( V_8 ) ;
}
static void F_85 ( struct V_1 * V_8 )
{
F_74 ( V_8 , false ) ;
F_75 ( V_8 ) ;
F_62 ( V_8 ) ;
F_81 ( V_8 ) ;
F_73 ( V_8 , true ) ;
}
static void F_86 ( struct V_2 * V_4 ,
struct V_74 * V_75 ,
struct V_74 * V_91 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_74 * V_93 = V_91 ;
F_39 ( L_18 ,
V_93 -> V_76 , V_93 -> V_77 ,
V_93 -> V_78 , ( V_93 -> V_79 & V_80 ) ?
L_19 : L_20 ) ;
F_59 ( & V_8 -> V_46 , V_93 ) ;
}
static void F_87 ( struct V_1 * V_8 , bool V_261 )
{
if ( ! V_8 -> V_262 )
return;
F_88 ( V_8 -> V_262 , V_263 ,
V_264 , V_261 ? ~ 0 : 0 ) ;
}
static void F_89 ( struct V_1 * V_8 )
{
if ( V_8 -> V_265 )
return;
F_90 ( V_8 -> V_30 ) ;
if ( F_91 ( F_92 ( V_266 ) , V_8 -> V_267 ) )
F_39 ( L_21 ) ;
F_88 ( V_8 -> V_268 , V_269 ,
V_270 , 1 ) ;
F_87 ( V_8 , true ) ;
F_11 ( V_8 , V_271 , 0 , V_272 ) ;
F_84 ( V_8 ) ;
V_8 -> V_265 = true ;
}
static void F_93 ( struct V_1 * V_8 )
{
if ( ! V_8 -> V_265 )
return;
F_11 ( V_8 , V_153 , 0 , V_160 ) ;
F_11 ( V_8 , V_271 , ~ 0 , V_272 ) ;
F_87 ( V_8 , false ) ;
F_88 ( V_8 -> V_268 , V_269 ,
V_270 , 0 ) ;
F_94 ( F_92 ( V_266 ) , V_8 -> V_267 ) ;
F_95 ( V_8 -> V_30 ) ;
V_8 -> V_265 = false ;
}
static void F_96 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
F_89 ( V_8 ) ;
F_85 ( V_8 ) ;
}
static void F_97 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
if ( ! V_8 -> V_265 )
return;
F_98 ( & V_8 -> V_273 ) ;
F_32 ( V_8 -> V_62 , V_63 ) ;
}
static void F_99 ( struct V_274 * V_275 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( V_275 , struct V_1 , V_273 . V_275 ) ;
if ( V_8 -> V_86 )
F_100 ( V_8 -> V_86 ) ;
}
static T_3 F_101 ( int V_276 , void * V_277 )
{
struct V_1 * V_8 = V_277 ;
F_102 ( V_278 , & V_8 -> V_273 ,
F_103 ( V_279 ) ) ;
return V_280 ;
}
static int F_104 ( struct V_1 * V_8 ,
const struct V_281 * V_282 ,
struct V_35 * * V_283 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_282 -> V_29 ; ++ V_26 ) {
struct V_35 * V_35 = F_105 ( V_30 , V_282 -> V_31 [ V_26 ] ) ;
if ( F_106 ( V_35 ) ) {
int V_25 = F_107 ( V_35 ) ;
F_16 ( V_30 , L_22 ,
V_282 -> V_31 [ V_26 ] , V_25 ) ;
return V_25 ;
}
V_283 [ V_26 ] = V_35 ;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_8 )
{
const struct V_284 * V_12 = V_8 -> V_12 ;
int V_29 = V_12 -> V_28 . V_29 + V_12 -> V_34 . V_29 ;
struct V_33 * V_30 = V_8 -> V_30 ;
struct V_35 * * V_283 ;
int V_25 ;
if ( ! V_29 )
return 0 ;
V_283 = F_109 ( V_30 , sizeof( * V_283 ) * V_29 , V_285 ) ;
if ( ! V_283 )
return - V_286 ;
V_8 -> V_28 = V_283 ;
V_8 -> V_34 = V_283 + V_12 -> V_28 . V_29 ;
V_25 = F_104 ( V_8 , & V_12 -> V_28 , V_8 -> V_28 ) ;
if ( V_25 )
return V_25 ;
return F_104 ( V_8 , & V_12 -> V_34 , V_8 -> V_34 ) ;
}
static void F_110 ( struct V_287 * V_35 , bool V_254 )
{
struct V_1 * V_8 = F_2 ( V_35 , struct V_1 ,
V_288 ) ;
if ( V_254 )
F_89 ( V_8 ) ;
else
F_93 ( V_8 ) ;
}
static int F_111 ( struct V_1 * V_8 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
struct V_289 * V_290 , * V_291 ;
V_290 = F_112 ( V_30 -> V_292 , 1 , - 1 ) ;
if ( ! V_290 )
return 0 ;
V_291 = F_113 ( V_290 ) ;
F_114 ( V_290 ) ;
if ( ! V_291 ) {
F_48 ( L_23 ) ;
return - V_23 ;
}
V_8 -> V_90 = F_115 ( V_291 ) ;
F_114 ( V_291 ) ;
if ( ! V_8 -> V_90 )
return - V_293 ;
return 0 ;
}
static int F_116 ( struct V_1 * V_8 )
{
struct V_33 * V_30 = V_8 -> V_30 ;
int V_26 , V_25 ;
F_39 ( L_24 ) ;
V_8 -> V_60 = F_117 ( V_30 , L_25 , V_294 ) ;
if ( F_106 ( V_8 -> V_60 ) ) {
F_48 ( L_26 ) ;
return F_107 ( V_8 -> V_60 ) ;
}
V_8 -> V_276 = F_118 ( V_8 -> V_60 ) ;
if ( V_8 -> V_276 < 0 ) {
F_48 ( L_27 ) ;
return V_8 -> V_276 ;
}
V_25 = F_108 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_19 ( V_8 , false ) ;
if ( V_25 )
return V_25 ;
for ( V_26 = 0 ; V_26 < F_92 ( V_266 ) ; ++ V_26 )
V_8 -> V_267 [ V_26 ] . V_266 = V_266 [ V_26 ] ;
V_25 = F_119 ( V_30 , F_92 ( V_266 ) , V_8 -> V_267 ) ;
if ( V_25 ) {
if ( V_25 != - V_293 )
F_48 ( L_28 ) ;
return V_25 ;
}
V_8 -> V_295 = F_120 ( V_30 , L_29 ) ;
if ( F_107 ( V_8 -> V_295 ) != - V_67 ) {
if ( F_106 ( V_8 -> V_295 ) )
return F_107 ( V_8 -> V_295 ) ;
V_25 = F_121 ( V_8 -> V_295 ) ;
if ( V_25 ) {
F_48 ( L_30 ) ;
return V_25 ;
}
}
return F_111 ( V_8 ) ;
}
static int F_122 ( struct V_33 * V_30 , struct V_33 * V_296 , void * V_31 )
{
struct V_92 * V_86 = V_31 ;
struct V_1 * V_8 = F_123 ( V_30 ) ;
struct V_2 * V_4 = & V_8 -> V_4 ;
struct V_297 * V_298 ;
int V_25 ;
V_8 -> V_86 = V_86 ;
V_8 -> V_288 . V_254 = F_110 ;
F_124 ( V_86 , V_4 , & V_299 ,
V_300 , NULL ) ;
F_125 ( V_4 , & V_301 ) ;
V_25 = F_126 ( V_4 , V_302 ) ;
if ( V_25 < 0 )
return V_25 ;
V_298 = F_127 ( V_86 , V_302 ) ;
V_298 -> V_303 = & V_8 -> V_288 ;
V_25 = F_46 ( V_4 ) ;
if ( V_25 ) {
F_48 ( L_31 , V_25 ) ;
F_128 ( V_4 ) ;
return V_25 ;
}
return 0 ;
}
static void F_129 ( struct V_33 * V_30 , struct V_33 * V_296 , void * V_31 )
{
}
static int F_130 ( struct V_1 * V_8 )
{
const char * V_304 = L_32 ;
struct V_289 * V_291 ;
struct V_305 * V_306 ;
V_291 = F_131 ( NULL , NULL , V_304 ) ;
if ( V_291 )
V_291 = F_132 ( V_291 ) ;
else
V_291 = F_133 ( V_8 -> V_30 -> V_292 , L_33 , 0 ) ;
if ( ! V_291 ) {
F_48 ( L_34 ) ;
return - V_67 ;
}
V_306 = F_134 ( V_291 ) ;
F_114 ( V_291 ) ;
if ( ! V_306 ) {
F_24 ( L_35 ) ;
return - V_293 ;
}
V_8 -> V_66 = V_306 ;
return 0 ;
}
static int F_135 ( struct V_1 * V_8 )
{
const char * V_304 = L_36 ;
struct V_289 * V_291 ;
int V_25 = 0 ;
V_291 = F_131 ( NULL , NULL , V_304 ) ;
if ( ! V_291 ) {
V_291 = F_133 ( V_8 -> V_30 -> V_292 , L_37 , 0 ) ;
if ( ! V_291 ) {
F_48 ( L_38 ) ;
return - V_67 ;
}
}
if ( V_8 -> V_12 -> V_307 ) {
V_8 -> V_27 = F_136 ( V_291 , 0 ) ;
if ( ! V_8 -> V_27 ) {
F_48 ( L_39 ) ;
V_25 = - V_286 ;
goto V_308;
}
} else {
V_8 -> V_24 = F_137 ( V_291 ) ;
if ( ! V_8 -> V_24 ) {
F_24 ( L_40 ) ;
V_25 = - V_293 ;
goto V_308;
}
}
V_308:
F_114 ( V_291 ) ;
return V_25 ;
}
static int F_138 ( struct V_309 * V_310 )
{
struct V_33 * V_30 = & V_310 -> V_30 ;
struct V_1 * V_8 ;
struct V_311 * V_312 ;
int V_25 ;
V_8 = F_109 ( V_30 , sizeof( struct V_1 ) , V_285 ) ;
if ( ! V_8 )
return - V_286 ;
V_8 -> V_12 = F_139 ( V_30 ) ;
F_140 ( V_310 , V_8 ) ;
V_8 -> V_30 = V_30 ;
V_25 = F_116 ( V_8 ) ;
if ( V_25 ) {
if ( V_25 != - V_293 )
F_48 ( L_41 ) ;
return V_25 ;
}
V_312 = F_141 ( V_310 , V_313 , 0 ) ;
V_8 -> V_13 = F_142 ( V_30 , V_312 ) ;
if ( F_106 ( V_8 -> V_13 ) ) {
V_25 = F_107 ( V_8 -> V_13 ) ;
return V_25 ;
}
V_25 = F_130 ( V_8 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_135 ( V_8 ) ;
if ( V_25 )
goto V_314;
F_143 ( & V_8 -> V_273 , F_99 ) ;
V_25 = F_144 ( V_30 , V_8 -> V_276 , NULL ,
F_101 , V_315 |
V_316 | V_317 ,
L_42 , V_8 ) ;
if ( V_25 ) {
F_48 ( L_43 ) ;
goto V_318;
}
V_8 -> V_268 = F_145 ( V_30 -> V_292 ,
L_44 ) ;
if ( F_106 ( V_8 -> V_268 ) ) {
F_48 ( L_45 ) ;
V_25 = - V_293 ;
goto V_318;
}
if ( V_8 -> V_12 -> V_319 ) {
V_8 -> V_262 = F_145 ( V_30 -> V_292 ,
L_46 ) ;
if ( F_106 ( V_8 -> V_262 ) ) {
F_48 ( L_47 ) ;
V_25 = - V_293 ;
goto V_318;
}
}
V_8 -> V_62 = F_146 ( & V_310 -> V_30 ) ;
if ( V_8 -> V_62 == NULL ) {
V_25 = - V_286 ;
goto V_318;
}
F_147 ( V_30 ) ;
V_25 = F_148 ( & V_310 -> V_30 , & V_320 ) ;
if ( V_25 )
goto V_321;
return V_25 ;
V_321:
F_149 ( V_8 -> V_62 ) ;
F_150 ( V_30 ) ;
V_318:
if ( V_8 -> V_24 )
F_151 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_152 ( V_8 -> V_27 ) ;
V_314:
F_151 ( & V_8 -> V_66 -> V_30 ) ;
return V_25 ;
}
static int F_153 ( struct V_309 * V_310 )
{
struct V_1 * V_8 = F_154 ( V_310 ) ;
F_155 ( & V_8 -> V_273 ) ;
F_32 ( V_8 -> V_62 , V_63 ) ;
F_156 ( & V_310 -> V_30 , & V_320 ) ;
F_149 ( V_8 -> V_62 ) ;
F_150 ( & V_310 -> V_30 ) ;
if ( ! F_106 ( V_8 -> V_295 ) )
F_157 ( V_8 -> V_295 ) ;
if ( V_8 -> V_24 )
F_151 ( & V_8 -> V_24 -> V_30 ) ;
if ( V_8 -> V_27 )
F_152 ( V_8 -> V_27 ) ;
F_151 ( & V_8 -> V_66 -> V_30 ) ;
return 0 ;
}
static int T_4 F_158 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_123 ( V_30 ) ;
F_18 ( V_8 ) ;
return 0 ;
}
static int T_4 F_159 ( struct V_33 * V_30 )
{
struct V_1 * V_8 = F_123 ( V_30 ) ;
int V_25 ;
V_25 = F_14 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
