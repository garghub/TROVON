int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ) {
int V_7 ;
struct V_8 V_9 ;
if ( ! V_6 -> V_10 ) {
V_4 -> V_11 = V_12 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 . V_16 = 0 ;
V_2 -> V_17 . V_18 = 0 ;
V_2 -> V_17 . V_19 = 0 ;
V_2 -> V_17 . V_20 = 0 ;
return 0 ;
}
switch ( V_6 -> V_21 ) {
case V_22 :
V_4 -> V_23 = V_24 ;
break;
case V_25 :
V_4 -> V_23 = V_26 ;
break;
case V_27 :
V_4 -> V_23 = V_28 ;
break;
default:
V_4 -> V_23 = V_29 ;
break;
}
V_4 -> V_30 |= V_31 ;
for ( V_7 = 0 ; V_7 < V_6 -> V_32 . V_33 ; V_7 ++ ) {
switch ( V_6 -> V_32 . V_34 [ V_7 ] ) {
case V_35 :
if ( V_6 -> V_32 . V_36 &
V_37 ) {
V_4 -> V_11 = V_38 ;
V_4 -> V_13 = V_39 ;
}
if ( V_6 -> V_32 . V_36 &
V_40 ) {
V_4 -> V_11 |= V_41 ;
V_4 -> V_13 = V_39 ;
}
break;
case V_42 :
if ( V_6 -> V_32 . V_36 &
V_37 ) {
V_4 -> V_11 = V_38 ;
V_4 -> V_13 = V_43 ;
}
if ( V_6 -> V_32 . V_36 &
V_40 ) {
V_4 -> V_11 |= V_41 ;
V_4 -> V_13 = V_43 ;
}
break;
default:
break;
}
}
for ( V_7 = 0 ; V_7 < V_6 -> V_32 . V_44 ; V_7 ++ ) {
switch ( V_6 -> V_32 . V_45 [ V_7 ] ) {
case V_46 :
case V_47 :
break;
case V_48 :
if ( V_6 -> V_32 . V_36 & V_37 )
V_4 -> V_15 . V_49 |=
V_50 ;
if ( V_6 -> V_32 . V_36 & V_40 )
V_4 -> V_15 . V_51 |=
V_50 ;
break;
case V_52 :
if ( V_6 -> V_32 . V_36 & V_37 )
V_4 -> V_15 . V_49 |=
V_53 ;
if ( V_6 -> V_32 . V_36 & V_40 )
V_4 -> V_15 . V_51 |=
V_53 ;
default:
break;
}
}
switch ( V_6 -> V_32 . V_54 ) {
case V_46 :
case V_47 :
if ( V_2 -> V_17 . V_18 ) {
V_4 -> V_11 = V_55 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 . V_16 = 0 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
V_9 = V_2 -> V_9 [ V_7 ] ;
V_4 -> V_57 [ V_7 ] . V_58 = V_7 ;
if ( V_2 -> V_59 == V_7 )
V_4 -> V_57 [ V_7 ] . V_60 = 1 ;
else
V_4 -> V_57 [ V_7 ] . V_60 = 0 ;
V_4 -> V_57 [ V_7 ] . V_16 =
V_9 . V_61 ;
memcpy ( & V_4 -> V_57 [ V_7 ] . V_62 ,
& V_9 . V_63 ,
V_9 . V_61 ) ;
}
}
break;
case V_48 :
V_4 -> V_15 . V_64 = V_50 ;
break;
case V_52 :
V_4 -> V_15 . V_64 = V_53 ;
break;
default:
break;
}
return 0 ;
}
void
F_2 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_66 ;
if ( ! F_3 ( V_2 -> V_67 -> V_68 ) )
return;
V_66 = F_4 ( V_69 , V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_66 ) {
memcpy ( & V_65 -> V_73 , V_66 + 2 ,
sizeof( struct V_74 ) ) ;
V_2 -> V_75 = 1 ;
} else {
memset ( & V_65 -> V_73 , 0 , sizeof( struct V_74 ) ) ;
V_65 -> V_73 . V_76 = F_5 ( V_77 ) ;
V_65 -> V_73 . V_78 = V_79 ;
}
return;
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_80 ;
V_80 = F_4 ( V_81 , V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_80 ) {
memcpy ( & V_65 -> V_82 , V_80 + 2 ,
sizeof( struct V_83 ) ) ;
V_2 -> V_84 = 1 ;
} else {
V_2 -> V_84 = 0 ;
}
return;
}
void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_85 ;
V_85 = F_4 ( V_86 , V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_85 )
V_65 -> V_87 = * ( V_85 + 2 ) ;
else
V_65 -> V_87 = 0 ;
}
void F_8 ( struct V_1 * V_2 ,
enum V_88 V_89 ,
bool V_90 )
{
struct V_91 * V_67 = V_2 -> V_67 ;
struct V_92 V_93 ;
V_93 . V_94 = V_95 ;
V_93 . V_76 = V_67 -> V_96 ;
if ( ! V_90 ) {
V_93 . V_97 = V_98 ;
V_93 . V_99 = V_98 ;
} else {
V_93 . V_97 = V_100 ;
V_93 . V_99 = V_100 ;
}
V_93 . V_101 = V_102 ;
if ( V_90 && V_89 >= V_103 )
V_93 . V_101 |= V_104 ;
F_9 ( V_2 , V_105 ,
V_106 , 0 , & V_93 , true ) ;
return;
}
void
F_10 ( struct V_3 * V_65 ,
struct V_5 * V_6 )
{
struct V_107 * V_108 ;
int V_109 = F_11 ( struct V_110 , V_111 . V_70 . V_112 ) ;
const T_1 * V_113 = V_6 -> V_70 . V_114 + V_109 ;
int V_115 = V_6 -> V_70 . V_116 - V_109 ;
T_1 V_117 = 0 ;
V_108 = ( void * ) F_4 ( V_118 , V_113 , V_115 ) ;
if ( V_108 ) {
memcpy ( V_65 -> V_119 , V_108 + 1 , V_108 -> V_115 ) ;
V_117 = V_108 -> V_115 ;
}
V_108 = ( void * ) F_4 ( V_120 ,
V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_108 )
memcpy ( V_65 -> V_119 + V_117 , V_108 + 1 , V_108 -> V_115 ) ;
return;
}
void F_12 ( struct V_3 * V_121 )
{
V_121 -> V_122 = 0x7F ;
V_121 -> V_123 = 0x7F ;
V_121 -> V_124 = 0x7F ;
V_121 -> V_125 = 0x7FFF ;
V_121 -> V_23 = 0x7F ;
V_121 -> V_126 = 0x7FFF ;
V_121 -> V_127 = 0x7FFF ;
V_121 -> V_128 = 0x7F ;
V_121 -> V_129 = 0xFF ;
}
static void
F_13 ( T_1 * * V_130 , void * V_131 , T_2 * V_132 )
{
struct V_133 * V_134 ;
struct V_135 * V_136 ;
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_3 * V_65 = V_131 ;
T_2 V_141 = * V_132 ;
T_1 * V_142 = * V_130 ;
V_140 = (struct V_139 * ) V_142 ;
V_140 -> V_143 . type = F_5 ( V_144 ) ;
V_140 -> V_143 . V_115 = F_5 ( sizeof( struct V_139 ) -
sizeof( struct V_145 ) ) ;
V_140 -> V_30 = F_5 ( V_65 -> V_30 ) ;
V_140 -> V_13 = F_5 ( V_65 -> V_13 ) ;
V_141 += sizeof( struct V_139 ) ;
V_142 += sizeof( struct V_139 ) ;
if ( V_65 -> V_15 . V_49 & V_146 ) {
V_134 = (struct V_133 * ) V_142 ;
V_134 -> V_143 . type = F_5 ( V_147 ) ;
V_134 -> V_143 . V_115 =
F_5 ( sizeof( struct V_133 ) -
sizeof( struct V_145 ) ) ;
V_134 -> V_148 = F_5 ( V_38 ) ;
V_134 -> V_149 = V_65 -> V_15 . V_49 ;
V_141 += sizeof( struct V_133 ) ;
V_142 += sizeof( struct V_133 ) ;
}
if ( V_65 -> V_15 . V_51 & V_146 ) {
V_134 = (struct V_133 * ) V_142 ;
V_134 -> V_143 . type = F_5 ( V_147 ) ;
V_134 -> V_143 . V_115 =
F_5 ( sizeof( struct V_133 ) -
sizeof( struct V_145 ) ) ;
V_134 -> V_148 = F_5 ( V_41 ) ;
V_134 -> V_149 = V_65 -> V_15 . V_51 ;
V_141 += sizeof( struct V_133 ) ;
V_142 += sizeof( struct V_133 ) ;
}
if ( V_65 -> V_15 . V_64 & V_146 ) {
V_136 = (struct V_135 * ) V_142 ;
V_136 -> V_143 . type = F_5 ( V_150 ) ;
V_136 -> V_143 . V_115 =
F_5 ( sizeof( struct V_135 ) -
sizeof( struct V_145 ) ) ;
V_136 -> V_149 = V_65 -> V_15 . V_64 ;
V_141 += sizeof( struct V_135 ) ;
V_142 += sizeof( struct V_135 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_138 = (struct V_137 * ) V_142 ;
V_138 -> V_143 . type =
F_5 ( V_151 ) ;
V_138 -> V_143 . V_115 = F_5 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_138 -> V_138 , V_65 -> V_15 . V_138 ,
V_65 -> V_15 . V_16 ) ;
V_141 += sizeof( struct V_145 ) +
V_65 -> V_15 . V_16 ;
V_142 += sizeof( struct V_145 ) +
V_65 -> V_15 . V_16 ;
}
* V_132 = V_141 ;
* V_130 = V_142 ;
return;
}
void
F_14 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_152 ;
const T_1 * V_153 ;
T_1 V_154 [] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_152 = F_15 ( V_155 ,
V_156 ,
V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_152 ) {
V_153 = V_152 ;
memcpy ( & V_65 -> V_157 , V_153 +
sizeof( struct V_107 ) , * ( V_153 + 1 ) ) ;
V_2 -> V_158 = 1 ;
} else {
memset ( & V_65 -> V_157 , 0 , sizeof( V_65 -> V_157 ) ) ;
memcpy ( & V_65 -> V_157 . V_159 , V_154 , sizeof( V_154 ) ) ;
V_65 -> V_157 . V_160 = V_161 ;
V_65 -> V_157 . V_162 = V_163 ;
V_2 -> V_158 = 0 ;
}
V_65 -> V_129 = 0x00 ;
return;
}
static void
F_16 ( T_1 * * V_130 , void * V_131 , T_2 * V_132 )
{
struct V_164 * V_9 ;
T_2 V_141 = * V_132 ;
int V_7 ;
T_1 * V_142 = * V_130 ;
struct V_3 * V_65 = V_131 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_165 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_166 ) ) {
V_9 = (struct V_164 * ) V_142 ;
V_9 -> V_143 . type =
F_5 ( V_167 ) ;
V_9 -> V_143 . V_115 =
F_5 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_141 += sizeof( struct V_145 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_142 += sizeof( struct V_145 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_132 = V_141 ;
* V_130 = V_142 ;
return;
}
void F_17 ( struct V_1 * V_2 ,
struct V_168 * V_169 )
{
enum V_170 V_171 ;
const T_1 * V_172 ;
V_172 = F_4 ( V_173 , V_169 -> V_71 ,
V_169 -> V_72 ) ;
if ( V_172 ) {
V_171 = V_174 ;
if ( F_9 ( V_2 , V_175 ,
V_106 , V_176 ,
& V_171 , true ) ) {
F_18 ( V_2 -> V_67 , ERROR ,
L_1 ) ;
}
}
}
static int
F_19 ( T_1 * V_142 , void * V_131 , T_2 * V_132 )
{
struct V_177 * V_124 ;
struct V_178 * V_125 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
struct V_183 * V_184 ;
struct V_185 * V_127 ;
struct V_186 * V_126 ;
struct V_187 * V_128 ;
struct V_188 * V_189 ;
struct V_190 * V_21 ;
struct V_191 * V_192 ;
struct V_193 * V_194 , * V_195 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_200 * V_201 ;
struct V_3 * V_65 = V_131 ;
int V_7 ;
T_2 V_141 = * V_132 ;
if ( V_65 -> V_180 . V_202 ) {
V_180 = (struct V_179 * ) V_142 ;
V_180 -> V_143 . type = F_5 ( V_203 ) ;
V_180 -> V_143 . V_115 = F_5 ( ( T_2 ) V_65 -> V_180 . V_202 ) ;
memcpy ( V_180 -> V_180 , V_65 -> V_180 . V_180 , V_65 -> V_180 . V_202 ) ;
V_141 += sizeof( struct V_145 ) +
V_65 -> V_180 . V_202 ;
V_142 += sizeof( struct V_145 ) +
V_65 -> V_180 . V_202 ;
V_182 = (struct V_181 * ) V_142 ;
V_182 -> V_143 . type = F_5 ( V_204 ) ;
V_182 -> V_143 . V_115 =
F_5 ( sizeof( V_182 -> V_205 ) ) ;
V_182 -> V_205 = V_65 -> V_122 ;
V_141 += sizeof( struct V_181 ) ;
V_142 += sizeof( struct V_181 ) ;
}
if ( V_65 -> V_119 [ 0 ] ) {
V_192 = (struct V_191 * ) V_142 ;
V_192 -> V_143 . type = F_5 ( V_206 ) ;
for ( V_7 = 0 ; V_7 < V_207 && V_65 -> V_119 [ V_7 ] ;
V_7 ++ )
V_192 -> V_119 [ V_7 ] = V_65 -> V_119 [ V_7 ] ;
V_192 -> V_143 . V_115 = F_5 ( V_7 ) ;
V_141 += sizeof( struct V_191 ) + V_7 ;
V_142 += sizeof( struct V_191 ) + V_7 ;
}
if ( V_65 -> V_208 &&
( ( ( V_65 -> V_209 & F_20 ( 0 ) ) == V_210 &&
V_65 -> V_208 <= V_211 ) ||
( ( V_65 -> V_209 & F_20 ( 0 ) ) == V_212 &&
V_65 -> V_208 <= V_213 ) ) ) {
V_184 = (struct V_183 * ) V_142 ;
V_184 -> V_143 . type = F_5 ( V_214 ) ;
V_184 -> V_143 . V_115 =
F_5 ( sizeof( struct V_183 ) -
sizeof( struct V_145 ) ) ;
V_184 -> V_94 = V_65 -> V_209 ;
V_184 -> V_208 = V_65 -> V_208 ;
V_141 += sizeof( struct V_183 ) ;
V_142 += sizeof( struct V_183 ) ;
}
if ( V_65 -> V_125 >= V_215 &&
V_65 -> V_125 <= V_216 ) {
V_125 = (struct V_178 * ) V_142 ;
V_125 -> V_143 . type =
F_5 ( V_217 ) ;
V_125 -> V_143 . V_115 =
F_5 ( sizeof( struct V_178 ) -
sizeof( struct V_145 ) ) ;
V_125 -> V_218 = F_5 ( V_65 -> V_125 ) ;
V_141 += sizeof( struct V_178 ) ;
V_142 += sizeof( struct V_178 ) ;
}
if ( V_65 -> V_124 >= V_219 &&
V_65 -> V_124 <= V_220 ) {
V_124 = (struct V_177 * ) V_142 ;
V_124 -> V_143 . type =
F_5 ( V_221 ) ;
V_124 -> V_143 . V_115 =
F_5 ( sizeof( struct V_177 ) -
sizeof( struct V_145 ) ) ;
V_124 -> V_218 = V_65 -> V_124 ;
V_141 += sizeof( struct V_177 ) ;
V_142 += sizeof( struct V_177 ) ;
}
if ( V_65 -> V_126 <= V_222 ) {
V_126 = (struct V_186 * ) V_142 ;
V_126 -> V_143 . type =
F_5 ( V_223 ) ;
V_126 -> V_143 . V_115 =
F_5 ( sizeof( struct V_186 ) -
sizeof( struct V_145 ) ) ;
V_126 -> V_224 = F_5 ( V_65 -> V_126 ) ;
V_141 += sizeof( struct V_185 ) ;
V_142 += sizeof( struct V_185 ) ;
}
if ( ( V_65 -> V_127 >= V_225 ) &&
( V_65 -> V_127 <= V_226 ) ) {
V_127 = (struct V_185 * ) V_142 ;
V_127 -> V_143 . type =
F_5 ( V_227 ) ;
V_127 -> V_143 . V_115 =
F_5 ( sizeof( struct V_185 ) -
sizeof( struct V_145 ) ) ;
V_127 -> V_228 = F_5 ( V_65 -> V_127 ) ;
V_141 += sizeof( struct V_185 ) ;
V_142 += sizeof( struct V_185 ) ;
}
if ( V_65 -> V_128 <= V_229 ) {
V_128 = (struct V_187 * ) V_142 ;
V_128 -> V_143 . type =
F_5 ( V_230 ) ;
V_128 -> V_143 . V_115 =
F_5 ( sizeof( struct V_187 ) -
sizeof( struct V_145 ) ) ;
V_128 -> V_231 = ( T_1 ) V_65 -> V_128 ;
V_141 += sizeof( struct V_187 ) ;
V_142 += sizeof( struct V_187 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_232 ) )
F_13 ( & V_142 , V_131 , & V_141 ) ;
else
F_16 ( & V_142 , V_131 , & V_141 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_190 * ) V_142 ;
V_21 -> V_143 . type = F_5 ( V_233 ) ;
V_21 -> V_143 . V_115 =
F_5 ( sizeof( struct V_190 ) -
sizeof( struct V_145 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_141 += sizeof( struct V_190 ) ;
V_142 += sizeof( struct V_190 ) ;
}
if ( V_65 -> V_11 ) {
V_189 = (struct V_188 * ) V_142 ;
V_189 -> V_143 . type =
F_5 ( V_234 ) ;
V_189 -> V_143 . V_115 =
F_5 ( sizeof( struct V_188 )
- sizeof( struct V_145 ) ) ;
V_189 -> V_148 = F_5 ( V_65 -> V_11 ) ;
V_141 += sizeof( struct V_188 ) ;
V_142 += sizeof( struct V_188 ) ;
}
if ( V_65 -> V_73 . V_76 ) {
V_199 = (struct V_198 * ) V_142 ;
V_199 -> V_143 . type = F_5 ( V_69 ) ;
V_199 -> V_143 . V_115 =
F_5 ( sizeof( struct V_74 ) ) ;
V_199 -> V_73 . V_76 = V_65 -> V_73 . V_76 ;
V_199 -> V_73 . V_78 =
V_65 -> V_73 . V_78 ;
memcpy ( & V_199 -> V_73 . V_235 , & V_65 -> V_73 . V_235 ,
sizeof( struct V_236 ) ) ;
V_199 -> V_73 . V_237 =
V_65 -> V_73 . V_237 ;
V_199 -> V_73 . V_238 = V_65 -> V_73 . V_238 ;
V_199 -> V_73 . V_239 =
V_65 -> V_73 . V_239 ;
V_141 += sizeof( struct V_198 ) ;
V_142 += sizeof( struct V_198 ) ;
}
if ( V_65 -> V_157 . V_129 != 0xFF ) {
V_201 = (struct V_200 * ) V_142 ;
V_201 -> V_143 . type = F_5 ( V_240 ) ;
V_201 -> V_143 . V_115 = F_5 ( sizeof( V_201 -> V_157 ) ) ;
memcpy ( & V_201 -> V_157 , & V_65 -> V_157 ,
sizeof( V_201 -> V_157 ) ) ;
V_141 += sizeof( struct V_200 ) ;
V_142 += sizeof( struct V_200 ) ;
}
if ( V_65 -> V_241 ) {
V_194 = (struct V_193 * ) V_142 ;
V_194 -> V_143 . type = F_5 ( V_242 ) ;
V_194 -> V_143 . V_115 = F_5 ( sizeof( * V_194 ) -
sizeof( struct V_145 ) ) ;
V_194 -> V_241 = F_21 ( V_65 -> V_241 ) ;
V_141 += sizeof( * V_194 ) ;
V_142 += sizeof( * V_194 ) ;
}
if ( V_65 -> V_87 ) {
V_197 = ( void * ) V_142 ;
V_197 -> V_143 . type = F_5 ( V_243 ) ;
V_197 -> V_143 . V_115 = F_5 ( sizeof( T_1 ) ) ;
V_197 -> V_244 = V_65 -> V_87 ;
V_141 += sizeof( * V_197 ) ;
V_142 += sizeof( * V_197 ) ;
}
if ( V_65 -> V_245 ) {
V_195 = (struct V_193 * ) V_142 ;
V_195 -> V_143 . type =
F_5 ( V_246 ) ;
V_195 -> V_143 . V_115 = F_5 ( sizeof( * V_195 ) -
sizeof( struct V_145 ) ) ;
V_195 -> V_241 =
F_21 ( V_65 -> V_245 ) ;
V_141 += sizeof( * V_195 ) ;
V_142 += sizeof( * V_195 ) ;
}
* V_132 = V_141 ;
return 0 ;
}
static int F_22 ( T_1 * V_142 , void * V_131 , T_2 * V_247 )
{
struct V_248 * V_249 = V_131 ;
struct V_145 * V_250 = ( void * ) V_142 ;
if ( ! V_249 || ! V_249 -> V_115 )
return - 1 ;
* V_247 += F_23 ( V_249 -> V_115 ) +
sizeof( struct V_145 ) ;
V_250 -> type = F_5 ( V_251 ) ;
V_250 -> V_115 = V_249 -> V_115 ;
V_142 += sizeof( struct V_145 ) ;
memcpy ( V_142 , V_249 -> V_252 , F_23 ( V_249 -> V_115 ) ) ;
return 0 ;
}
static int
F_24 ( struct V_253 * V_254 , T_2 V_255 ,
T_3 type , void * V_131 )
{
T_1 * V_142 ;
T_2 V_141 , V_132 , V_247 ;
struct V_256 * V_257 ;
V_254 -> V_258 = F_5 ( V_259 ) ;
V_141 = ( T_2 ) ( sizeof( struct V_256 ) + V_260 ) ;
V_257 = (struct V_256 * ) & V_254 -> V_6 . V_261 ;
V_257 -> V_262 = F_5 ( V_255 ) ;
V_142 = V_257 -> V_142 ;
switch ( type ) {
case V_263 :
V_132 = V_141 ;
if ( F_19 ( V_142 , V_131 , & V_132 ) )
return - 1 ;
V_254 -> V_264 = F_5 ( V_132 ) ;
break;
case V_265 :
V_247 = V_141 ;
if ( F_22 ( V_142 , V_131 , & V_247 ) )
return - 1 ;
V_254 -> V_264 = F_5 ( V_247 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_253 * V_254 , T_1 * V_266 )
{
struct V_267 * V_268 = & V_254 -> V_6 . V_268 ;
V_254 -> V_258 = F_5 ( V_269 ) ;
memcpy ( V_268 -> V_266 , V_266 , V_270 ) ;
V_268 -> V_271 = F_5 ( V_272 ) ;
V_254 -> V_264 = F_5 ( sizeof( struct V_267 ) +
V_260 ) ;
return 0 ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_273 ,
T_2 V_255 , T_3 type ,
void * V_274 , void * V_131 )
{
struct V_253 * V_254 = V_131 ;
switch ( V_273 ) {
case V_259 :
if ( F_24 ( V_254 , V_255 , type , V_274 ) )
return - 1 ;
break;
case V_275 :
case V_276 :
case V_277 :
case V_278 :
V_254 -> V_258 = F_5 ( V_273 ) ;
V_254 -> V_264 = F_5 ( V_260 ) ;
break;
case V_269 :
if ( F_25 ( V_2 , V_254 , V_274 ) )
return - 1 ;
break;
case V_279 :
if ( F_27 ( V_2 , V_131 ,
V_274 ) )
return - 1 ;
break;
default:
F_18 ( V_2 -> V_67 , ERROR ,
L_2 , V_273 ) ;
return - 1 ;
}
return 0 ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_280 V_281 )
{
T_1 V_282 = 0 , V_283 = V_2 -> V_67 -> V_282 ;
V_2 -> V_284 = V_281 ;
V_65 -> V_208 = F_29 (
V_281 . V_285 -> V_286 ) ;
if ( V_281 . V_285 -> V_287 == V_288 ) {
V_65 -> V_209 = V_210 ;
V_282 = V_289 | V_290 ;
if ( V_281 . V_89 > V_291 )
V_282 |= V_292 ;
} else {
V_65 -> V_209 = V_212 ;
V_282 = V_293 ;
if ( V_281 . V_89 > V_291 )
V_282 |= V_294 ;
if ( V_281 . V_89 > V_295 )
V_282 |= V_296 ;
}
switch ( V_281 . V_89 ) {
case V_297 :
case V_298 :
case V_291 :
case V_299 :
break;
case V_295 :
if ( V_281 . V_300 < V_281 . V_285 -> V_286 )
V_65 -> V_209 |= V_301 ;
else
V_65 -> V_209 |= V_302 ;
break;
case V_103 :
case V_303 :
case V_304 :
V_65 -> V_209 |=
F_30 ( V_65 -> V_208 ) << 4 ;
break;
default:
F_18 ( V_2 -> V_67 ,
V_305 , L_3 ,
V_281 . V_89 ) ;
break;
}
V_2 -> V_67 -> V_282 = V_282 ;
if ( V_283 != V_282 ) {
F_31 ( V_2 -> V_67 -> V_306 ) ;
F_32 ( V_2 ) ;
}
}
int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_65 )
{
if ( F_9 ( V_2 , V_259 ,
V_106 ,
V_263 , V_65 , true ) ) {
F_18 ( V_2 -> V_67 , ERROR ,
L_4 ) ;
return - 1 ;
}
if ( F_9 ( V_2 , V_275 ,
V_106 , 0 , NULL , true ) ) {
F_18 ( V_2 -> V_67 , ERROR ,
L_5 ) ;
return - 1 ;
}
if ( V_2 -> V_17 . V_18 )
V_2 -> V_307 |= V_308 ;
else
V_2 -> V_307 &= ~ V_308 ;
if ( F_9 ( V_2 , V_309 ,
V_106 , 0 ,
& V_2 -> V_307 , true ) )
return - 1 ;
return 0 ;
}
