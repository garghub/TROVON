static T_1 F_1 ( int V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_4 ;
return V_5 ;
}
static T_1 F_3 ( int V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_3 ) ; V_2 ++ )
if ( V_3 [ V_2 ] . V_1 == V_1 )
return V_3 [ V_2 ] . V_6 ;
return V_7 ;
}
static T_1 F_4 ( int V_8 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_9 ) ; V_2 ++ )
if ( V_9 [ V_2 ] . V_8 == V_8 )
return V_9 [ V_2 ] . V_4 ;
return V_10 ;
}
static int F_5 ( void )
{
if ( F_6 ( 1 , 8 , 0 ) < 0 )
return 0 ;
else
return 1 ;
}
int F_7 ( void )
{
int V_11 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
struct V_16 V_17 ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_11 = F_8 ( V_18 , sizeof( V_15 . V_19 ) ,
sizeof( V_15 ) , & V_15 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_15 ) ;
if ( V_11 ) {
F_10 ( V_20 L_1 , V_11 ) ;
return V_11 ;
}
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
V_11 = F_8 ( V_21 , sizeof( V_17 . V_19 ) ,
sizeof( V_17 ) , & V_17 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_17 ) ;
if ( V_11 ) {
F_10 ( V_20 L_2 , V_11 ) ;
return V_11 ;
}
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
V_13 . V_22 = 0 ;
V_11 = F_8 ( V_23 , sizeof( V_13 ) , sizeof( V_13 ) ,
& V_13 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_13 ) ;
if ( V_11 )
F_10 ( V_20 L_3 , V_11 ) ;
return V_11 ;
}
int F_11 ( void )
{
int V_11 ;
struct V_24 V_25 ;
memset ( & V_25 , 0 , sizeof( V_25 ) ) ;
V_11 = F_8 ( V_26 , sizeof( V_25 . V_19 ) ,
sizeof( V_25 ) , & V_25 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_25 ) ;
if ( V_11 )
F_10 ( V_20 L_4 , V_11 ) ;
return V_11 ;
}
int F_12 ( int V_27 , T_1 * V_28 , T_1 V_29 )
{
int V_2 , V_30 , V_11 ;
struct V_31 V_32 ;
if ( V_27 > V_33 )
return - V_34 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
for ( V_2 = 0 ; V_2 < V_27 ; V_2 ++ ) {
V_32 . V_29 [ V_2 ] . V_35 = V_28 [ V_2 ] ;
V_32 . V_29 [ V_2 ] . V_29 = V_29 ;
}
V_30 = sizeof( V_32 . V_19 ) +
sizeof( struct V_36 ) * V_27 ;
V_11 = F_8 ( V_37 , V_30 ,
sizeof( V_32 ) , & V_32 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_32 ) ;
if ( V_11 )
F_10 ( V_20 L_5 , V_11 ) ;
return V_11 ;
}
int F_13 ( T_1 V_28 )
{
int V_11 ;
struct V_38 V_39 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_35 = V_28 ;
V_11 = F_8 ( V_40 ,
sizeof( V_39 ) , sizeof( V_39 ) ,
& V_39 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_39 ) ;
if ( V_11 )
F_10 ( V_20
L_6 ,
V_11 , V_28 ) ;
return V_11 ;
}
int F_14 ( T_1 V_35 , T_1 V_29 )
{
int V_11 ;
struct V_41 V_42 ;
memset ( & V_42 , 0 , sizeof( V_42 ) ) ;
V_42 . V_35 = V_35 ;
V_42 . V_29 = V_29 ;
V_11 = F_8 ( V_43 , sizeof( V_42 ) ,
sizeof( V_42 ) , & V_42 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_42 ) ;
if ( V_11 )
F_10 ( V_20 L_7 ,
V_11 , V_35 ) ;
return V_11 ;
}
int F_15 ( void )
{
int V_11 ;
struct V_44 V_45 ;
memset ( & V_45 , 0 , sizeof( V_45 ) ) ;
V_45 . V_22 = V_46 |
V_47 | V_48 ;
V_11 = F_8 ( V_49 , sizeof( V_45 ) ,
sizeof( V_45 ) , & V_45 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_45 ) ;
if ( V_11 )
F_10 ( V_20 L_8 , V_11 ) ;
return V_11 ;
}
int F_16 ( T_2 V_50 )
{
int V_11 ;
struct V_51 V_52 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_50 = V_50 ;
V_11 = F_8 ( V_53 , sizeof( V_52 ) ,
sizeof( V_52 ) , & V_52 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_52 ) ;
if ( V_11 && V_11 != V_54 )
F_10 ( V_20 L_9 , V_11 ) ;
return V_11 ;
}
T_1 F_17 ( void * V_55 , T_1 V_35 , int V_56 , int V_57 ,
int V_58 , T_1 V_59 )
{
struct V_60 * V_61 ;
V_61 = (struct V_60 * ) V_55 ;
if ( V_56 == - 1 )
V_56 = V_62 ;
if ( V_57 == - 1 )
V_57 = V_63 ;
if ( V_58 == - 1 )
V_58 = 0 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
F_18 ( V_64 , sizeof( * V_61 ) ,
& V_61 -> V_19 ) ;
V_61 -> V_35 = V_35 ;
V_61 -> V_65 = F_4 ( V_56 ) ;
V_61 -> V_66 = F_1 ( V_57 ) ;
V_61 -> V_67 = F_1 ( V_68 ) ;
V_61 -> V_69 = F_3 ( V_57 ) ;
if ( ( V_59 & V_70 ) && F_5 () )
V_61 -> V_71 = V_72 ;
else
V_61 -> V_71 = V_73 ;
V_61 -> V_58 = V_58 ;
if ( V_59 & V_74 ) {
V_61 -> V_75 = V_76
| V_77 ;
} else {
V_61 -> V_75 = V_78 ;
}
return sizeof( * V_61 ) ;
}
T_1 F_19 ( void * V_55 , T_1 V_79 , int V_56 , int V_80 ,
T_1 V_59 )
{
struct V_81 * V_82 ;
T_1 V_83 , V_84 ;
V_82 = (struct V_81 * ) V_55 ;
if ( V_56 == - 1 )
V_56 = V_62 ;
if ( V_80 == - 1 )
V_80 = V_85 ;
if ( F_20 ( V_59 , & V_83 , & V_84 ) )
return 0 ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
F_18 ( V_86 , sizeof( * V_82 ) ,
& V_82 -> V_19 ) ;
V_82 -> V_87 = V_79 ;
if ( V_56 == V_88
&& V_79 == V_89 )
V_82 -> V_56 = V_90 ;
else
V_82 -> V_56 = V_56 ;
V_82 -> V_91 = ( V_92 ) V_83 ;
V_82 -> V_93 = ( V_92 ) V_84 ;
V_82 -> V_94 = V_82 -> V_91 * 4 ;
V_82 -> V_95 = V_96 ;
V_82 -> V_97 = V_98 [ V_80 ] . V_99 ;
if ( ( V_59 & V_100 ) && F_5 () )
V_82 -> V_101 = V_102 ;
else
V_82 -> V_101 = V_103 ;
V_82 -> V_104 = V_98 [ V_80 ] . V_105 ;
F_21 ( L_10 ,
V_106 , V_56 , V_82 -> V_91 , V_82 -> V_93 ,
V_82 -> V_94 , V_82 -> V_95 ,
V_82 -> V_97 , V_82 -> V_104 ) ;
return sizeof( * V_82 ) ;
}
int F_22 ( T_1 V_79 , T_1 V_80 , T_1 V_29 )
{
int V_11 ;
struct V_107 V_97 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_87 = V_79 ;
if ( V_29 != V_108 )
V_97 . V_97 = V_109 ;
else
V_97 . V_97 =
V_98 [ V_80 ] . V_99 ;
V_97 . V_104 = V_98 [ V_80 ] . V_105 ;
V_11 = F_8 ( V_110 , sizeof( V_97 ) ,
sizeof( V_97 ) , & V_97 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_97 ) ;
if ( V_11 )
F_10 ( V_20 L_11 , V_11 ) ;
return V_11 ;
}
int F_23 ( int V_27 , T_1 * V_28 , T_1 V_29 )
{
int V_2 , V_11 ;
struct V_111 V_112 ;
if ( V_27 > V_33 )
return - V_34 ;
memset ( & V_112 , 0 , sizeof( V_112 ) ) ;
for ( V_2 = 0 ; V_2 < V_27 ; V_2 ++ ) {
V_112 . V_29 [ V_2 ] . V_35 = V_28 [ V_2 ] ;
V_112 . V_29 [ V_2 ] . V_29 = V_29 ;
}
V_11 = F_8 ( V_113 ,
sizeof( V_112 . V_19 ) +
sizeof( struct V_36 ) * V_27 ,
sizeof( V_112 ) , & V_112 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_112 ) ;
if ( V_11 )
F_10 ( V_20 L_12 , V_11 ) ;
return V_11 ;
}
static T_2 F_24 ( T_1 V_114 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < F_2 ( V_115 ) ; V_2 ++ )
if ( V_115 [ V_2 ] . V_114 == V_114 )
return V_115 [ V_2 ] . V_116 ;
F_10 ( V_20 L_13 , V_106 , V_114 ) ;
return 0 ;
}
static void F_25 ( T_2 * V_117 , T_1 V_114 , T_1 V_56 )
{
T_1 V_65 , V_118 ;
int V_119 ;
V_119 = V_118 = 0 ;
V_65 = F_4 ( V_56 ) ;
switch ( V_65 ) {
case V_120 :
case V_121 :
V_119 = 0 ;
break;
case V_10 :
case V_122 :
V_119 = 1 ;
break;
case V_123 :
case V_124 :
V_119 = 2 ;
break;
case V_125 :
case V_126 :
V_119 = 3 ;
break;
case V_127 :
case V_128 :
case V_129 :
case V_130 :
case V_131 :
V_119 = 4 ;
break;
default:
F_10 ( V_20 L_14 , V_106 , V_56 ) ;
break;
}
if ( V_114 < V_132 || V_114 > V_133 )
F_10 ( V_20 L_13 , V_106 , V_114 ) ;
else
V_118 = V_134 [ V_132 - V_135 ] [ V_119 ] ;
* V_117 ++ = V_118 & 0x000000FF ;
* V_117 ++ = ( V_118 & 0x0000FF00 ) >> 8 ;
* V_117 = ( V_118 & 0x00FF0000 ) >> 16 ;
}
static T_2 F_26 ( T_1 V_136 , const T_2 * V_137 )
{
T_2 V_138 = 0 ;
if ( V_136 == V_139 ) {
V_138 = 0x03 ;
} else if ( V_136 == V_140 ) {
V_138 = ( ( V_137 [ 0 ] << 4 ) + ( V_137 [ 1 ] << 5 ) + ( V_137 [ 2 ] << 6 ) +
( V_137 [ 3 ] << 7 ) ) | 0x01 ;
} else
F_10 ( V_20 L_15 , V_106 , V_136 ) ;
return V_138 ;
}
static T_2 F_27 ( const T_2 * V_141 )
{
T_2 V_138 = 0 ;
V_138 = V_141 [ 0 ] + ( V_141 [ 1 ] << 2 ) + ( V_141 [ 2 ] << 4 ) + ( V_141 [ 3 ] << 6 ) ;
return V_138 ;
}
static T_2 F_28 ( T_1 V_142 )
{
T_2 V_138 = 0 ;
switch ( V_142 ) {
case V_143 :
V_138 = V_144 ;
break;
case V_145 :
V_138 = V_146 ;
break;
case V_147 :
V_138 = V_148 ;
break;
default:
F_10 ( V_20 L_16 , V_106 ,
V_142 ) ;
break;
}
return V_138 ;
}
static T_2 F_29 ( T_1 V_149 )
{
if ( V_149 > V_150 ) {
F_10 ( V_20 L_17 , V_106 ,
V_149 ) ;
return 0 ;
}
return V_149 == V_151 ? 0x0 : 0x1 ;
}
static void F_30 ( struct V_152 * V_153 ,
const struct V_154 * V_50 )
{
V_153 -> V_155 . V_156 = V_50 -> V_157 + 1 ;
V_153 -> V_155 . V_158 = 0 ;
V_153 -> V_159 . V_160 = 0 ;
V_153 -> V_159 . V_161 = 0 ;
V_153 -> V_162 = 0 ;
V_153 -> V_163 = V_50 -> V_164 ;
V_153 -> V_165 . V_166 = V_50 -> V_167 ;
V_153 -> V_165 . V_168 = V_50 -> V_169 ;
}
static void F_31 ( T_2 * V_170 , const T_2 * V_171 )
{
memcpy ( V_170 , V_171 , 5 ) ;
}
T_1 F_32 ( void * V_55 , T_1 V_28 ,
const struct V_154 * V_172 ,
T_1 V_56 )
{
struct V_173 * V_174 ;
V_174 = (struct V_173 * ) V_55 ;
memset ( V_174 , 0 , sizeof( * V_174 ) ) ;
F_18 ( V_175 , sizeof( * V_174 ) ,
& V_174 -> V_19 ) ;
V_174 -> V_35 = V_28 ;
V_174 -> V_116 = F_24 ( V_172 -> V_176 ) | 0x80 ;
F_25 ( V_174 -> V_117 , V_172 -> V_176 , V_56 ) ;
V_174 -> V_137 = F_26 ( V_172 -> V_177 ,
V_172 -> V_178 ) ;
V_174 -> V_179 = 0x09 ;
V_174 -> V_180 = F_27 ( V_172 -> V_181 ) ;
V_174 -> V_182 = 0x49 ;
V_174 -> V_183 = F_28 ( V_172 -> V_184 ) ;
V_174 -> V_185 = F_29 ( V_172 -> V_157 ) ;
F_30 ( & V_174 -> V_153 , V_172 ) ;
F_31 ( V_174 -> V_170 , V_172 -> V_186 ) ;
return sizeof( * V_174 ) ;
}
void F_33 ( struct V_154 * V_187 , T_1 V_35 ,
T_1 V_188 , T_1 V_114 , T_1 V_142 , T_1 V_99 ,
T_1 V_136 )
{
int V_189 ;
int V_2 ;
if ( ! ( V_188 | V_114 | V_99 | V_142 | V_136 ) ) {
V_188 = V_151 ;
V_114 = V_190 ;
V_142 = V_143 ;
V_99 = V_191 ;
V_136 = V_140 ;
}
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
F_18 ( V_192 , sizeof( * V_187 ) , & V_187 -> V_19 ) ;
V_187 -> V_35 = ( T_2 ) V_35 ;
V_187 -> V_193 = 0x0FFF ;
V_187 -> V_157 = V_188 ;
V_187 -> V_176 = V_114 ;
V_187 -> V_184 = V_142 ;
V_187 -> V_194 = V_99 ;
V_187 -> V_177 = V_136 ;
switch ( V_188 ) {
case V_150 :
V_187 -> V_178 [ 3 ] = 1 ;
case V_195 :
V_187 -> V_178 [ 2 ] = 1 ;
V_187 -> V_178 [ 1 ] = 1 ;
case V_151 :
default:
V_187 -> V_178 [ 0 ] = 1 ;
}
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ )
V_187 -> V_196 [ V_2 ] = V_197 ;
V_187 -> V_181 [ 0 ] = V_198 ;
V_187 -> V_181 [ 1 ] = V_199 ;
V_187 -> V_181 [ 2 ] = V_200 ;
V_187 -> V_181 [ 3 ] = V_201 ;
if ( V_35 == V_202 ||
V_35 == V_203 ) {
switch ( V_188 ) {
case V_150 :
V_187 -> V_164 = V_204 ;
break;
case V_195 :
V_187 -> V_164 = V_205 ;
break;
case V_151 :
default:
V_187 -> V_164 = V_206 ;
break;
}
} else {
V_187 -> V_164 = V_206 ;
}
V_187 -> V_167 = V_207 ;
V_187 -> V_169 = 0 ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ )
V_187 -> V_186 [ V_2 ] = V_208 [ V_2 ] ;
switch ( V_114 ) {
case V_132 :
V_187 -> V_186 [ 3 ] &= ~ V_209 ;
V_187 -> V_186 [ 3 ] |= V_210 ;
break;
case V_211 :
V_187 -> V_186 [ 3 ] &= ~ V_209 ;
V_187 -> V_186 [ 3 ] |= V_212 ;
break;
case V_213 :
V_187 -> V_186 [ 3 ] &= ~ V_209 ;
V_187 -> V_186 [ 3 ] |= V_214 ;
break;
case V_215 :
V_187 -> V_186 [ 3 ] &= ~ V_209 ;
V_187 -> V_186 [ 3 ] |= V_216 ;
break;
case V_133 :
V_187 -> V_186 [ 3 ] &= ~ V_209 ;
V_187 -> V_186 [ 3 ] |= V_217 ;
break;
default:
break;
}
V_189 = V_187 -> V_186 [ 0 ] & 0x02 ;
if ( V_189 &&
( V_35 == V_218 ||
V_35 == V_219 ||
V_35 == V_202 ||
V_35 == V_203 ) ) {
V_187 -> V_184 = V_143 ;
V_187 -> V_194 = V_220 ;
}
}
int F_34 ( struct V_154 * V_172 )
{
int V_11 ;
V_11 = F_8 ( V_192 , sizeof( * V_172 ) ,
sizeof( * V_172 ) , & V_172 -> V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_172 ) ;
if ( V_11 )
F_10 ( V_20 L_18 , V_11 ) ;
return V_11 ;
}
int F_35 ( int V_27 , T_1 * V_28 , T_1 V_29 )
{
int V_2 , V_11 ;
struct V_221 V_222 ;
if ( V_27 > V_223 )
return - V_34 ;
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
for ( V_2 = 0 ; V_2 < V_27 ; V_2 ++ ) {
V_222 . V_29 [ V_2 ] . V_35 = V_28 [ V_2 ] ;
V_222 . V_29 [ V_2 ] . V_29 = V_29 ;
}
V_11 = F_8 ( V_224 ,
sizeof( V_222 . V_19 ) +
sizeof( struct V_225 ) * V_27 ,
sizeof( V_222 ) , & V_222 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_222 ) ;
if ( V_11 )
F_10 ( V_20 L_19 , V_11 ) ;
return V_11 ;
}
int F_36 ( int V_226 , T_1 V_28 )
{
int V_11 ;
struct V_227 V_228 ;
T_1 V_229 ;
memset ( & V_228 , 0 , sizeof( V_228 ) ) ;
V_228 . V_230 = V_28 ;
V_229 = V_226 ? V_231 : V_232 ;
V_11 = F_8 ( V_229 , sizeof( V_228 ) , sizeof( V_228 ) ,
& V_228 . V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( & V_228 ) ;
if ( V_11 )
F_10 ( V_20 L_20 , V_229 ,
V_11 ) ;
return V_11 ;
}
int F_37 ( struct V_233 * V_234 , T_1 V_30 )
{
int V_11 ;
F_38 ( & V_235 ) ;
V_11 = F_8 ( V_236 , V_30 , sizeof( * V_234 ) ,
& V_234 -> V_19 ) ;
if ( V_11 < 0 )
goto V_237;
V_11 = F_9 ( V_234 ) ;
if ( V_11 )
F_21 ( L_21 , V_106 ,
V_11 ) ;
V_237:
F_39 ( & V_235 ) ;
return V_11 ;
}
int F_40 ( struct V_238 * V_239 )
{
int V_11 ;
memset ( V_239 , 0 , sizeof( * V_239 ) ) ;
V_11 = F_8 ( V_240 , sizeof( V_239 -> V_19 ) ,
sizeof( * V_239 ) , & V_239 -> V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_239 ) ;
if ( V_11 )
F_10 ( V_20 L_22 , V_11 ) ;
return V_11 ;
}
int F_41 ( struct V_241 * V_153 ,
T_1 V_35 )
{
int V_11 ;
memset ( V_153 , 0 , sizeof( * V_153 ) ) ;
V_153 -> V_35 = V_35 ;
V_11 = F_8 ( V_242 ,
sizeof( V_153 -> V_19 ) + sizeof( V_153 -> V_35 ) +
sizeof( V_153 -> V_243 ) ,
sizeof( * V_153 ) , & V_153 -> V_19 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_9 ( V_153 ) ;
if ( V_11 )
F_10 ( V_20 L_23 ,
V_11 ) ;
return V_11 ;
}
