static void
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) -> V_7 ;
T_2 V_8 [] = { V_3 , V_4 } ;
int V_9 ;
V_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_1 , V_9 , V_3 ) ;
}
static T_2
F_6 ( struct V_1 * V_2 , T_2 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) -> V_7 ;
T_2 V_4 ;
int V_9 ;
V_9 = F_3 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_7 ( V_6 , & V_4 , sizeof( V_4 ) ) ;
if ( V_9 < 0 )
goto V_11;
return V_4 ;
V_11:
F_5 ( & V_6 -> V_10 , L_2 , V_9 , V_3 ) ;
return 0 ;
}
static void
F_8 ( struct V_1 * V_2 , T_1 V_12 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( F_9 ( V_12 ) != V_14 -> V_15 ) {
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_8 [] = {
V_16 , F_9 (reg)
} ;
int V_9 = F_3 ( V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_3 , V_9 ) ;
V_14 -> V_15 = F_9 ( V_12 ) ;
}
}
static int
F_11 ( struct V_1 * V_2 , T_1 V_12 , char * V_8 , int V_17 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_3 = F_12 ( V_12 ) ;
int V_9 ;
F_8 ( V_2 , V_12 ) ;
V_9 = F_3 ( V_6 , & V_3 , sizeof( V_3 ) ) ;
if ( V_9 < 0 )
goto V_11;
V_9 = F_7 ( V_6 , V_8 , V_17 ) ;
if ( V_9 < 0 )
goto V_11;
return V_9 ;
V_11:
F_5 ( & V_6 -> V_10 , L_4 , V_9 , V_12 ) ;
return V_9 ;
}
static void
F_13 ( struct V_1 * V_2 , T_1 V_12 , T_2 * V_18 , int V_17 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_8 [ V_17 + 1 ] ;
int V_9 ;
V_8 [ 0 ] = F_12 ( V_12 ) ;
memcpy ( & V_8 [ 1 ] , V_18 , V_17 ) ;
F_8 ( V_2 , V_12 ) ;
V_9 = F_3 ( V_6 , V_8 , V_17 + 1 ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static T_2
F_14 ( struct V_1 * V_2 , T_1 V_12 )
{
T_2 V_4 = 0 ;
F_11 ( V_2 , V_12 , & V_4 , sizeof( V_4 ) ) ;
return V_4 ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_8 [] = { F_12 ( V_12 ) , V_4 } ;
int V_9 ;
F_8 ( V_2 , V_12 ) ;
V_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static void
F_16 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_4 )
{
struct V_5 * V_6 = F_10 ( V_2 ) ;
T_2 V_8 [] = { F_12 ( V_12 ) , V_4 >> 8 , V_4 } ;
int V_9 ;
F_8 ( V_2 , V_12 ) ;
V_9 = F_3 ( V_6 , V_8 , F_4 ( V_8 ) ) ;
if ( V_9 < 0 )
F_5 ( & V_6 -> V_10 , L_5 , V_9 , V_12 ) ;
}
static void
F_17 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
F_15 ( V_2 , V_12 , F_14 ( V_2 , V_12 ) | V_4 ) ;
}
static void
F_18 ( struct V_1 * V_2 , T_1 V_12 , T_2 V_4 )
{
F_15 ( V_2 , V_12 , F_14 ( V_2 , V_12 ) & ~ V_4 ) ;
}
static void
F_19 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_19 , V_20 | V_21 ) ;
F_20 ( 50 ) ;
F_18 ( V_2 , V_19 , V_20 | V_21 ) ;
F_20 ( 50 ) ;
F_17 ( V_2 , V_22 , V_23 ) ;
F_18 ( V_2 , V_22 , V_23 ) ;
F_15 ( V_2 , V_24 , 0x00 ) ;
F_15 ( V_2 , V_25 , F_21 ( 1 ) ) ;
F_15 ( V_2 , V_26 , 0x00 ) ;
F_15 ( V_2 , V_27 , 0x00 ) ;
F_15 ( V_2 , V_28 , 0x00 ) ;
F_15 ( V_2 , V_29 , 0x00 ) ;
F_15 ( V_2 , V_30 , V_31 ) ;
F_15 ( V_2 , V_32 , V_33 | V_34 ) ;
F_15 ( V_2 , V_35 , 0xfa ) ;
F_15 ( V_2 , V_36 , 0x00 ) ;
F_15 ( V_2 , V_37 , 0x5b ) ;
F_15 ( V_2 , V_38 , 0x00 ) ;
F_15 ( V_2 , V_39 , 0x10 ) ;
F_15 ( V_2 , V_40 , 0x24 ) ;
}
static T_2 F_22 ( T_2 * V_8 , T_3 V_41 )
{
T_2 V_42 = 0 ;
while ( V_41 -- )
V_42 += * V_8 ++ ;
return ( 255 - V_42 ) + 1 ;
}
static void
F_23 ( struct V_1 * V_2 , T_2 V_43 , T_1 V_3 ,
T_2 * V_8 , T_3 V_44 )
{
V_8 [ F_24 ( 0 ) ] = F_22 ( V_8 , V_44 ) ;
F_18 ( V_2 , V_45 , V_43 ) ;
F_13 ( V_2 , V_3 , V_8 , V_44 ) ;
F_17 ( V_2 , V_45 , V_43 ) ;
}
static void
F_25 ( struct V_1 * V_2 , struct V_46 * V_18 )
{
T_2 V_8 [ F_24 ( 5 ) + 1 ] ;
V_8 [ F_26 ( 0 ) ] = 0x84 ;
V_8 [ F_26 ( 1 ) ] = 0x01 ;
V_8 [ F_26 ( 2 ) ] = 10 ;
V_8 [ F_24 ( 0 ) ] = 0 ;
V_8 [ F_24 ( 1 ) ] = V_18 -> V_47 [ 1 ] & 0x07 ;
V_8 [ F_24 ( 2 ) ] = V_18 -> V_47 [ 2 ] & 0x1c ;
V_8 [ F_24 ( 4 ) ] = V_18 -> V_47 [ 4 ] ;
V_8 [ F_24 ( 5 ) ] = V_18 -> V_47 [ 5 ] & 0xf8 ;
F_23 ( V_2 , V_48 , V_49 , V_8 ,
sizeof( V_8 ) ) ;
}
static void
F_27 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
T_2 V_8 [ F_24 ( 13 ) + 1 ] ;
memset ( V_8 , 0 , sizeof( V_8 ) ) ;
V_8 [ F_26 ( 0 ) ] = 0x82 ;
V_8 [ F_26 ( 1 ) ] = 0x02 ;
V_8 [ F_26 ( 2 ) ] = 13 ;
V_8 [ F_24 ( 1 ) ] = V_52 ;
V_8 [ F_24 ( 3 ) ] = V_53 << 2 ;
V_8 [ F_24 ( 4 ) ] = F_28 ( V_51 ) ;
F_23 ( V_2 , V_54 , V_55 , V_8 ,
sizeof( V_8 ) ) ;
}
static void F_29 ( struct V_1 * V_2 , bool V_56 )
{
if ( V_56 ) {
F_17 ( V_2 , V_19 , V_20 ) ;
F_18 ( V_2 , V_19 , V_20 ) ;
F_17 ( V_2 , V_57 , V_58 ) ;
} else {
F_18 ( V_2 , V_57 , V_58 ) ;
}
}
static void
F_30 ( struct V_1 * V_2 ,
struct V_50 * V_51 , struct V_46 * V_18 )
{
T_2 V_8 [ 6 ] , V_59 , V_60 , V_61 , V_62 , V_63 ;
T_4 V_64 ;
F_15 ( V_2 , V_65 , V_18 -> V_66 ) ;
F_15 ( V_2 , V_67 , V_18 -> V_68 ) ;
switch ( V_18 -> V_69 ) {
case V_70 :
F_15 ( V_2 , V_71 , 0x40 ) ;
V_59 = F_31 ( 0 ) ;
V_60 = F_32 ( 2 ) ;
V_62 = F_33 ( 3 ) | F_34 ( 3 ) ;
V_61 = 0 ;
break;
case V_72 :
F_15 ( V_2 , V_71 , 0x64 ) ;
V_59 = F_31 ( 1 ) ;
V_60 = F_32 ( 0 ) ;
V_62 = F_33 ( 3 ) | F_34 ( 3 ) ;
V_61 = F_35 ( 0 ) ;
break;
default:
F_36 () ;
return;
}
F_15 ( V_2 , V_73 , V_59 ) ;
F_18 ( V_2 , V_57 , V_74 ) ;
F_18 ( V_2 , V_57 , V_75 ) ;
F_15 ( V_2 , V_76 , V_62 ) ;
if ( V_51 -> clock > 100000 )
V_63 = V_77 ;
else
V_63 = V_31 ;
F_15 ( V_2 , V_30 , V_63 ) ;
V_64 = 128 * V_18 -> V_78 / 1000 ;
V_8 [ 0 ] = 0x44 ;
V_8 [ 1 ] = 0x42 ;
V_8 [ 2 ] = 0x01 ;
V_8 [ 3 ] = V_64 ;
V_8 [ 4 ] = V_64 >> 8 ;
V_8 [ 5 ] = V_64 >> 16 ;
F_13 ( V_2 , V_79 , V_8 , 6 ) ;
F_15 ( V_2 , V_73 , V_59 | V_60 ) ;
F_17 ( V_2 , V_57 , V_80 ) ;
F_18 ( V_2 , V_57 , V_80 ) ;
V_8 [ 0 ] = 0x04 ;
V_8 [ 1 ] = 0x00 ;
V_8 [ 2 ] = 0x00 ;
V_8 [ 3 ] = 0xf1 ;
F_13 ( V_2 , F_37 ( 0 ) , V_8 , 4 ) ;
F_29 ( V_2 , true ) ;
F_38 ( 20 ) ;
F_29 ( V_2 , false ) ;
F_25 ( V_2 , V_18 ) ;
}
static void
F_39 ( struct V_1 * V_2 , void * V_81 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_46 * V_18 = V_81 ;
V_14 -> V_82 = F_40 ( V_18 -> V_83 ) |
( V_18 -> V_84 ? V_85 : 0 ) |
F_41 ( V_18 -> V_86 ) |
( V_18 -> V_87 ? V_88 : 0 ) ;
V_14 -> V_89 = F_42 ( V_18 -> V_90 ) |
( V_18 -> V_91 ? V_92 : 0 ) |
F_43 ( V_18 -> V_93 ) |
( V_18 -> V_94 ? V_95 : 0 ) ;
V_14 -> V_96 = F_44 ( V_18 -> V_97 ) |
( V_18 -> V_98 ? V_99 : 0 ) |
F_45 ( V_18 -> V_100 ) |
( V_18 -> V_101 ? V_102 : 0 ) ;
V_14 -> V_81 = * V_18 ;
}
static void
F_46 ( struct V_1 * V_2 , int V_51 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
if ( V_51 != V_103 )
V_51 = V_104 ;
if ( V_51 == V_14 -> V_105 )
return;
switch ( V_51 ) {
case V_103 :
F_15 ( V_2 , V_106 , 0xff ) ;
F_15 ( V_2 , V_107 , 0xff ) ;
F_15 ( V_2 , V_108 , 0xff ) ;
F_15 ( V_2 , V_109 , V_14 -> V_82 ) ;
F_15 ( V_2 , V_110 , V_14 -> V_89 ) ;
F_15 ( V_2 , V_111 , V_14 -> V_96 ) ;
break;
case V_104 :
F_15 ( V_2 , V_106 , 0x00 ) ;
F_15 ( V_2 , V_107 , 0x00 ) ;
F_15 ( V_2 , V_108 , 0x00 ) ;
break;
}
V_14 -> V_105 = V_51 ;
}
static void
F_47 ( struct V_1 * V_2 )
{
F_48 ( L_6 ) ;
}
static void
F_49 ( struct V_1 * V_2 )
{
F_48 ( L_6 ) ;
}
static bool
F_50 ( struct V_1 * V_2 ,
const struct V_50 * V_51 ,
struct V_50 * V_112 )
{
return true ;
}
static int
F_51 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
return V_113 ;
}
static void
F_52 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_50 * V_112 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
T_1 V_114 , V_115 , V_116 , V_117 ;
T_1 V_118 , V_119 ;
T_1 V_120 , V_121 , V_122 , V_123 ;
T_1 V_124 , V_125 , V_126 , V_127 ;
T_1 V_128 , V_129 ;
T_1 V_130 , V_131 ;
T_1 V_132 , V_133 ;
T_2 V_12 , div , V_134 ;
V_116 = V_51 -> V_135 ;
V_117 = V_51 -> V_136 ;
V_119 = V_51 -> V_137 - V_51 -> V_138 ;
V_118 = V_51 -> V_139 - V_51 -> V_138 ;
V_133 = V_51 -> V_135 ;
V_132 = V_51 -> V_135 - V_51 -> V_138 ;
V_114 = 3 + V_118 ;
if ( V_112 -> V_140 & V_141 )
V_114 += V_112 -> V_142 ;
if ( ( V_51 -> V_140 & V_143 ) == 0 ) {
V_115 = 1 + V_51 -> V_144 - V_51 -> V_145 ;
V_128 = V_51 -> V_136 - V_51 -> V_145 - 1 ;
V_129 = V_128 + V_51 -> V_145 ;
V_120 = V_121 = V_118 ;
V_122 = V_51 -> V_144 - V_51 -> V_145 ;
V_123 = V_122 +
V_51 -> V_146 - V_51 -> V_144 ;
V_130 = V_131 = 0 ;
V_124 = V_125 = 0 ;
V_126 = V_127 = 0 ;
} else {
V_115 = 1 + ( V_51 -> V_144 - V_51 -> V_145 ) / 2 ;
V_128 = ( V_51 -> V_136 - V_51 -> V_145 ) / 2 ;
V_129 = V_128 + V_51 -> V_145 / 2 ;
V_120 = V_121 = V_118 ;
V_122 = ( V_51 -> V_144 - V_51 -> V_145 ) / 2 ;
V_123 = V_122 +
( V_51 -> V_146 - V_51 -> V_144 ) / 2 ;
V_130 = V_128 + V_51 -> V_136 / 2 ;
V_131 = V_130 + V_51 -> V_145 / 2 ;
V_124 = V_125 = V_118 + V_51 -> V_135 / 2 ;
V_126 = V_122 + V_51 -> V_136 / 2 ;
V_127 = V_126 +
( V_51 -> V_146 - V_51 -> V_144 ) / 2 ;
}
div = 148500 / V_51 -> clock ;
F_17 ( V_2 , V_57 , V_58 ) ;
F_17 ( V_2 , V_147 , V_148 ) ;
F_18 ( V_2 , V_149 , V_150 ) ;
F_15 ( V_2 , V_151 , F_53 ( 0 ) ) ;
F_15 ( V_2 , V_152 , F_54 ( 0 ) |
F_55 ( 0 ) ) ;
F_15 ( V_2 , V_153 , F_56 ( 0 ) ) ;
F_15 ( V_2 , V_154 , F_57 ( 0 ) |
F_58 ( 0 ) ) ;
F_18 ( V_2 , V_26 , V_155 ) ;
F_18 ( V_2 , V_24 , V_156 ) ;
F_18 ( V_2 , V_26 , V_157 ) ;
F_15 ( V_2 , V_27 , 0 ) ;
F_15 ( V_2 , V_158 , F_59 ( 0 ) ) ;
V_134 = 0 ;
F_15 ( V_2 , V_159 , 0 ) ;
F_15 ( V_2 , V_32 , F_60 ( 0 ) |
V_33 | V_34 ) ;
F_15 ( V_2 , V_25 , F_21 ( div ) |
F_61 ( V_134 ) ) ;
F_17 ( V_2 , V_160 , V_161 ) ;
F_15 ( V_2 , V_162 , 0x09 ) ;
F_18 ( V_2 , V_163 , V_164 ) ;
F_15 ( V_2 , V_165 , 0 ) ;
F_17 ( V_2 , V_165 , V_166 ) ;
if ( V_51 -> V_140 & V_167 )
F_17 ( V_2 , V_165 , V_168 ) ;
if ( V_51 -> V_140 & V_169 )
F_17 ( V_2 , V_165 , V_170 ) ;
V_12 = V_171 ;
if ( V_51 -> V_140 & V_167 )
V_12 |= V_172 ;
if ( V_51 -> V_140 & V_169 )
V_12 |= V_173 ;
F_15 ( V_2 , V_147 , V_12 ) ;
F_15 ( V_2 , V_174 , 0x00 ) ;
F_16 ( V_2 , V_175 , V_114 ) ;
F_16 ( V_2 , V_176 , V_115 ) ;
F_16 ( V_2 , V_177 , V_116 ) ;
F_16 ( V_2 , V_178 , V_117 ) ;
F_16 ( V_2 , V_179 , V_122 ) ;
F_16 ( V_2 , V_180 , V_120 ) ;
F_16 ( V_2 , V_181 , V_123 ) ;
F_16 ( V_2 , V_182 , V_121 ) ;
F_16 ( V_2 , V_183 , V_126 ) ;
F_16 ( V_2 , V_184 , V_124 ) ;
F_16 ( V_2 , V_185 , V_127 ) ;
F_16 ( V_2 , V_186 , V_125 ) ;
F_16 ( V_2 , V_187 , V_118 ) ;
F_16 ( V_2 , V_188 , V_119 ) ;
F_16 ( V_2 , V_189 , V_128 ) ;
F_16 ( V_2 , V_190 , V_129 ) ;
F_16 ( V_2 , V_191 , V_130 ) ;
F_16 ( V_2 , V_192 , V_131 ) ;
F_16 ( V_2 , V_193 , V_132 ) ;
F_16 ( V_2 , V_194 , V_133 ) ;
if ( V_14 -> V_195 == V_196 ) {
F_15 ( V_2 , V_197 , 0x01 ) ;
}
F_18 ( V_2 , V_163 , V_198 ) ;
if ( V_14 -> V_199 ) {
F_18 ( V_2 , V_147 , V_148 ) ;
F_15 ( V_2 , V_151 , F_53 ( 1 ) ) ;
F_17 ( V_2 , V_149 , V_150 ) ;
F_27 ( V_2 , V_112 ) ;
if ( V_14 -> V_81 . V_66 )
F_30 ( V_2 , V_112 ,
& V_14 -> V_81 ) ;
}
}
static enum V_200
F_62 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
T_2 V_4 = F_6 ( V_2 , V_203 ) ;
return ( V_4 & V_204 ) ? V_205 :
V_206 ;
}
static int
F_63 ( struct V_1 * V_2 , T_2 * V_8 , int V_207 )
{
T_2 V_208 , V_209 ;
int V_9 , V_210 ;
F_17 ( V_2 , V_211 , V_212 ) ;
V_208 = ( V_207 & 1 ) ? 128 : 0 ;
V_209 = V_207 / 2 ;
F_15 ( V_2 , V_213 , 0xa0 ) ;
F_15 ( V_2 , V_214 , V_208 ) ;
F_15 ( V_2 , V_215 , 0x60 ) ;
F_15 ( V_2 , V_216 , V_209 ) ;
F_15 ( V_2 , V_217 , 0x1 ) ;
F_15 ( V_2 , V_217 , 0x0 ) ;
for ( V_210 = 100 ; V_210 > 0 ; V_210 -- ) {
T_2 V_4 = F_14 ( V_2 , V_211 ) ;
if ( V_4 & V_212 )
break;
F_20 ( 1 ) ;
}
if ( V_210 == 0 )
return - V_218 ;
V_9 = F_11 ( V_2 , V_219 , V_8 , V_220 ) ;
if ( V_9 != V_220 ) {
F_5 ( V_2 -> V_10 -> V_10 , L_7 ,
V_207 , V_9 ) ;
return V_9 ;
}
F_18 ( V_2 , V_211 , V_212 ) ;
return 0 ;
}
static T_2 *
F_64 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
int V_221 = 0 , V_222 = 0 ;
T_2 * V_223 , * V_224 ;
bool V_225 = V_226 & V_227 ;
if ( ( V_223 = F_65 ( V_220 , V_228 ) ) == NULL )
return NULL ;
if ( V_14 -> V_195 == V_196 )
F_18 ( V_2 , V_229 , V_230 ) ;
if ( F_63 ( V_2 , V_223 , 0 ) )
goto V_11;
if ( ! F_66 ( V_223 , 0 , V_225 ) )
goto V_11;
if ( V_223 [ 0x7e ] == 0 )
goto V_231;
V_224 = F_67 ( V_223 , ( V_223 [ 0x7e ] + 1 ) * V_220 , V_228 ) ;
if ( ! V_224 )
goto V_11;
V_223 = V_224 ;
for ( V_221 = 1 ; V_221 <= V_223 [ 0x7e ] ; V_221 ++ ) {
T_2 * V_232 = V_223 + ( V_222 + 1 ) * V_220 ;
if ( F_63 ( V_2 , V_232 , V_221 ) )
goto V_11;
if ( ! F_66 ( V_232 , V_221 , V_225 ) )
goto V_11;
V_222 ++ ;
}
if ( V_222 != V_223 [ 0x7e ] ) {
V_223 [ V_220 - 1 ] += V_223 [ 0x7e ] - V_222 ;
V_223 [ 0x7e ] = V_222 ;
V_224 = F_67 ( V_223 , ( V_222 + 1 ) * V_220 , V_228 ) ;
if ( ! V_224 )
goto V_11;
V_223 = V_224 ;
}
V_231:
if ( V_14 -> V_195 == V_196 )
F_17 ( V_2 , V_229 , V_230 ) ;
return V_223 ;
V_11:
if ( V_14 -> V_195 == V_196 )
F_17 ( V_2 , V_229 , V_230 ) ;
F_68 ( V_2 -> V_10 -> V_10 , L_8 ) ;
F_69 ( V_223 ) ;
return NULL ;
}
static int
F_70 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
struct V_233 * V_233 = (struct V_233 * ) F_64 ( V_2 ) ;
int V_64 = 0 ;
if ( V_233 ) {
F_71 ( V_202 , V_233 ) ;
V_64 = F_72 ( V_202 , V_233 ) ;
V_14 -> V_199 = F_73 ( V_233 ) ;
F_69 ( V_233 ) ;
}
return V_64 ;
}
static int
F_74 ( struct V_1 * V_2 ,
struct V_201 * V_202 )
{
F_48 ( L_6 ) ;
return 0 ;
}
static int
F_75 ( struct V_1 * V_2 ,
struct V_201 * V_202 ,
struct V_234 * V_235 ,
T_5 V_4 )
{
F_48 ( L_6 ) ;
return 0 ;
}
static void
F_76 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_2 ( V_2 ) ;
F_77 ( V_2 ) ;
F_69 ( V_14 ) ;
}
static int
F_78 ( struct V_5 * V_6 , const struct V_236 * V_237 )
{
return 0 ;
}
static int
F_79 ( struct V_5 * V_6 )
{
return 0 ;
}
static int
F_80 ( struct V_5 * V_6 ,
struct V_238 * V_10 ,
struct V_239 * V_240 )
{
struct V_1 * V_2 = & V_240 -> V_241 ;
struct V_13 * V_14 ;
V_14 = F_81 ( sizeof( * V_14 ) , V_228 ) ;
if ( ! V_14 )
return - V_242 ;
V_14 -> V_82 = F_40 ( 2 ) | F_41 ( 3 ) ;
V_14 -> V_89 = F_42 ( 0 ) | F_43 ( 1 ) ;
V_14 -> V_96 = F_44 ( 4 ) | F_45 ( 5 ) ;
V_14 -> V_15 = 0 ;
V_14 -> V_7 = F_82 ( V_6 -> V_243 , 0x34 ) ;
V_14 -> V_105 = V_104 ;
V_240 -> V_244 = V_14 ;
V_240 -> V_245 = & V_246 ;
F_1 ( V_2 , V_247 ,
V_248 | V_249 ) ;
F_19 ( V_2 ) ;
V_14 -> V_195 = F_14 ( V_2 , V_250 ) |
F_14 ( V_2 , V_251 ) << 8 ;
V_14 -> V_195 &= ~ 0x30 ;
switch ( V_14 -> V_195 ) {
case V_252 : F_83 ( V_10 -> V_10 , L_9 ) ; break;
case V_253 : F_83 ( V_10 -> V_10 , L_10 ) ; break;
case V_254 : F_83 ( V_10 -> V_10 , L_11 ) ; break;
case V_196 : F_83 ( V_10 -> V_10 , L_12 ) ; break;
default:
F_48 ( L_13 , V_14 -> V_195 ) ;
goto V_11;
}
F_15 ( V_2 , V_255 , 0x00 ) ;
F_15 ( V_2 , V_256 , 39 ) ;
if ( V_14 -> V_195 == V_253 )
F_17 ( V_2 , V_257 , V_258 ) ;
F_1 ( V_2 , V_259 ,
V_260 | V_261 ) ;
return 0 ;
V_11:
if ( V_14 -> V_7 )
F_84 ( V_14 -> V_7 ) ;
F_69 ( V_14 ) ;
V_240 -> V_244 = NULL ;
V_240 -> V_245 = NULL ;
return - V_262 ;
}
static int T_6
F_85 ( void )
{
F_48 ( L_6 ) ;
return F_86 ( V_263 , & V_264 ) ;
}
static void T_7
F_87 ( void )
{
F_48 ( L_6 ) ;
F_88 ( & V_264 ) ;
}
