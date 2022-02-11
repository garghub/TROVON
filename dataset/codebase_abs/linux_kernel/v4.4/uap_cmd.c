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
T_2 V_67 ;
if ( ! F_3 ( V_2 -> V_68 -> V_69 ) )
return;
V_66 = F_4 ( V_70 , V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_66 ) {
memcpy ( & V_65 -> V_74 , V_66 + 2 ,
sizeof( struct V_75 ) ) ;
V_67 = F_5 ( V_65 -> V_74 . V_67 ) ;
memset ( & V_65 -> V_74 . V_76 , 0 ,
V_2 -> V_68 -> V_77 ) ;
switch ( F_6 ( V_67 ) ) {
case V_78 :
V_65 -> V_74 . V_76 . V_79 [ 0 ] = 0xff ;
break;
case V_80 :
case V_81 :
V_65 -> V_74 . V_76 . V_79 [ 0 ] = 0xff ;
V_65 -> V_74 . V_76 . V_79 [ 1 ] = 0xff ;
break;
default:
F_7 ( V_2 -> V_68 , V_82 ,
L_1 ) ;
V_65 -> V_74 . V_76 . V_79 [ 0 ] = 0xff ;
V_65 -> V_74 . V_76 . V_79 [ 1 ] = 0xff ;
break;
}
V_2 -> V_83 = 1 ;
} else {
memset ( & V_65 -> V_74 , 0 , sizeof( struct V_75 ) ) ;
V_65 -> V_74 . V_67 = F_8 ( V_84 ) ;
V_65 -> V_74 . V_85 = V_86 ;
}
return;
}
void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_87 ;
V_87 = F_4 ( V_88 , V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_87 ) {
memcpy ( & V_65 -> V_89 , V_87 + 2 ,
sizeof( struct V_90 ) ) ;
V_2 -> V_91 = 1 ;
} else {
V_2 -> V_91 = 0 ;
}
return;
}
void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_92 ;
V_92 = F_4 ( V_93 , V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_92 )
V_65 -> V_94 = * ( V_92 + 2 ) ;
else
V_65 -> V_94 = 0 ;
}
void F_11 ( struct V_1 * V_2 ,
enum V_95 V_96 ,
bool V_97 )
{
struct V_98 * V_68 = V_2 -> V_68 ;
struct V_99 V_100 ;
V_100 . V_101 = V_102 ;
V_100 . V_67 = V_68 -> V_103 ;
if ( ! V_97 ) {
V_100 . V_104 = V_105 ;
V_100 . V_106 = V_105 ;
} else {
V_100 . V_104 = V_107 ;
V_100 . V_106 = V_107 ;
}
V_100 . V_108 = V_109 ;
if ( V_97 && V_96 >= V_110 )
V_100 . V_108 |= V_111 ;
F_12 ( V_2 , V_112 ,
V_113 , 0 , & V_100 , true ) ;
return;
}
void
F_13 ( struct V_3 * V_65 ,
struct V_5 * V_6 )
{
struct V_114 * V_115 ;
int V_116 = F_14 ( struct V_117 , V_118 . V_71 . V_119 ) ;
const T_1 * V_120 = V_6 -> V_71 . V_121 + V_116 ;
int V_122 = V_6 -> V_71 . V_123 - V_116 ;
T_1 V_124 = 0 ;
V_115 = ( void * ) F_4 ( V_125 , V_120 , V_122 ) ;
if ( V_115 ) {
memcpy ( V_65 -> V_126 , V_115 + 1 , V_115 -> V_122 ) ;
V_124 = V_115 -> V_122 ;
}
V_115 = ( void * ) F_4 ( V_127 ,
V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_115 )
memcpy ( V_65 -> V_126 + V_124 , V_115 + 1 , V_115 -> V_122 ) ;
return;
}
void F_15 ( struct V_3 * V_128 )
{
V_128 -> V_129 = 0x7F ;
V_128 -> V_130 = 0x7F ;
V_128 -> V_131 = 0x7F ;
V_128 -> V_132 = 0x7FFF ;
V_128 -> V_23 = 0x7F ;
V_128 -> V_133 = 0x7FFF ;
V_128 -> V_134 = 0x7FFF ;
V_128 -> V_135 = 0x7F ;
V_128 -> V_136 = 0xFF ;
}
static void
F_16 ( T_1 * * V_137 , void * V_138 , T_2 * V_139 )
{
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_3 * V_65 = V_138 ;
T_2 V_148 = * V_139 ;
T_1 * V_149 = * V_137 ;
V_147 = (struct V_146 * ) V_149 ;
V_147 -> V_150 . type = F_8 ( V_151 ) ;
V_147 -> V_150 . V_122 = F_8 ( sizeof( struct V_146 ) -
sizeof( struct V_152 ) ) ;
V_147 -> V_30 = F_8 ( V_65 -> V_30 ) ;
V_147 -> V_13 = F_8 ( V_65 -> V_13 ) ;
V_148 += sizeof( struct V_146 ) ;
V_149 += sizeof( struct V_146 ) ;
if ( V_65 -> V_15 . V_49 & V_153 ) {
V_141 = (struct V_140 * ) V_149 ;
V_141 -> V_150 . type = F_8 ( V_154 ) ;
V_141 -> V_150 . V_122 =
F_8 ( sizeof( struct V_140 ) -
sizeof( struct V_152 ) ) ;
V_141 -> V_155 = F_8 ( V_38 ) ;
V_141 -> V_156 = V_65 -> V_15 . V_49 ;
V_148 += sizeof( struct V_140 ) ;
V_149 += sizeof( struct V_140 ) ;
}
if ( V_65 -> V_15 . V_51 & V_153 ) {
V_141 = (struct V_140 * ) V_149 ;
V_141 -> V_150 . type = F_8 ( V_154 ) ;
V_141 -> V_150 . V_122 =
F_8 ( sizeof( struct V_140 ) -
sizeof( struct V_152 ) ) ;
V_141 -> V_155 = F_8 ( V_41 ) ;
V_141 -> V_156 = V_65 -> V_15 . V_51 ;
V_148 += sizeof( struct V_140 ) ;
V_149 += sizeof( struct V_140 ) ;
}
if ( V_65 -> V_15 . V_64 & V_153 ) {
V_143 = (struct V_142 * ) V_149 ;
V_143 -> V_150 . type = F_8 ( V_157 ) ;
V_143 -> V_150 . V_122 =
F_8 ( sizeof( struct V_142 ) -
sizeof( struct V_152 ) ) ;
V_143 -> V_156 = V_65 -> V_15 . V_64 ;
V_148 += sizeof( struct V_142 ) ;
V_149 += sizeof( struct V_142 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_145 = (struct V_144 * ) V_149 ;
V_145 -> V_150 . type =
F_8 ( V_158 ) ;
V_145 -> V_150 . V_122 = F_8 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_145 -> V_145 , V_65 -> V_15 . V_145 ,
V_65 -> V_15 . V_16 ) ;
V_148 += sizeof( struct V_152 ) +
V_65 -> V_15 . V_16 ;
V_149 += sizeof( struct V_152 ) +
V_65 -> V_15 . V_16 ;
}
* V_139 = V_148 ;
* V_137 = V_149 ;
return;
}
void
F_17 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_159 ;
struct V_114 * V_160 ;
T_1 V_161 [] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_159 = F_18 ( V_162 ,
V_163 ,
V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_159 ) {
V_160 = (struct V_114 * ) V_159 ;
memcpy ( & V_65 -> V_164 , V_160 + 1 ,
sizeof( V_65 -> V_164 ) ) ;
V_2 -> V_165 = 1 ;
} else {
memset ( & V_65 -> V_164 , 0 , sizeof( V_65 -> V_164 ) ) ;
memcpy ( & V_65 -> V_164 . V_166 , V_161 , sizeof( V_161 ) ) ;
V_65 -> V_164 . V_167 = V_168 ;
V_65 -> V_164 . V_169 = V_170 ;
V_2 -> V_165 = 0 ;
}
V_65 -> V_136 = 0x00 ;
return;
}
static void
F_19 ( T_1 * * V_137 , void * V_138 , T_2 * V_139 )
{
struct V_171 * V_9 ;
T_2 V_148 = * V_139 ;
int V_7 ;
T_1 * V_149 = * V_137 ;
struct V_3 * V_65 = V_138 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_172 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_173 ) ) {
V_9 = (struct V_171 * ) V_149 ;
V_9 -> V_150 . type =
F_8 ( V_174 ) ;
V_9 -> V_150 . V_122 =
F_8 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_148 += sizeof( struct V_152 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_149 += sizeof( struct V_152 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_139 = V_148 ;
* V_137 = V_149 ;
return;
}
static int
F_20 ( T_1 * V_149 , void * V_138 , T_2 * V_139 )
{
struct V_175 * V_131 ;
struct V_176 * V_132 ;
struct V_177 * V_178 ;
struct V_179 * V_180 ;
struct V_181 * V_182 ;
struct V_183 * V_134 ;
struct V_184 * V_133 ;
struct V_185 * V_135 ;
struct V_186 * V_187 ;
struct V_188 * V_21 ;
struct V_189 * V_190 ;
struct V_191 * V_192 , * V_193 ;
struct V_194 * V_195 ;
struct V_196 * V_197 ;
struct V_198 * V_199 ;
struct V_3 * V_65 = V_138 ;
int V_7 ;
T_2 V_148 = * V_139 ;
if ( V_65 -> V_178 . V_200 ) {
V_178 = (struct V_177 * ) V_149 ;
V_178 -> V_150 . type = F_8 ( V_201 ) ;
V_178 -> V_150 . V_122 = F_8 ( ( T_2 ) V_65 -> V_178 . V_200 ) ;
memcpy ( V_178 -> V_178 , V_65 -> V_178 . V_178 , V_65 -> V_178 . V_200 ) ;
V_148 += sizeof( struct V_152 ) +
V_65 -> V_178 . V_200 ;
V_149 += sizeof( struct V_152 ) +
V_65 -> V_178 . V_200 ;
V_180 = (struct V_179 * ) V_149 ;
V_180 -> V_150 . type = F_8 ( V_202 ) ;
V_180 -> V_150 . V_122 =
F_8 ( sizeof( V_180 -> V_203 ) ) ;
V_180 -> V_203 = V_65 -> V_129 ;
V_148 += sizeof( struct V_179 ) ;
V_149 += sizeof( struct V_179 ) ;
}
if ( V_65 -> V_126 [ 0 ] ) {
V_190 = (struct V_189 * ) V_149 ;
V_190 -> V_150 . type = F_8 ( V_204 ) ;
for ( V_7 = 0 ; V_7 < V_205 && V_65 -> V_126 [ V_7 ] ;
V_7 ++ )
V_190 -> V_126 [ V_7 ] = V_65 -> V_126 [ V_7 ] ;
V_190 -> V_150 . V_122 = F_8 ( V_7 ) ;
V_148 += sizeof( struct V_189 ) + V_7 ;
V_149 += sizeof( struct V_189 ) + V_7 ;
}
if ( V_65 -> V_206 &&
( ( V_65 -> V_207 == V_208 &&
V_65 -> V_206 <= V_209 ) ||
( V_65 -> V_207 == V_210 &&
V_65 -> V_206 <= V_211 ) ) ) {
V_182 = (struct V_181 * ) V_149 ;
V_182 -> V_150 . type = F_8 ( V_212 ) ;
V_182 -> V_150 . V_122 =
F_8 ( sizeof( struct V_181 ) -
sizeof( struct V_152 ) ) ;
V_182 -> V_101 = V_65 -> V_207 ;
V_182 -> V_206 = V_65 -> V_206 ;
V_148 += sizeof( struct V_181 ) ;
V_149 += sizeof( struct V_181 ) ;
}
if ( V_65 -> V_132 >= V_213 &&
V_65 -> V_132 <= V_214 ) {
V_132 = (struct V_176 * ) V_149 ;
V_132 -> V_150 . type =
F_8 ( V_215 ) ;
V_132 -> V_150 . V_122 =
F_8 ( sizeof( struct V_176 ) -
sizeof( struct V_152 ) ) ;
V_132 -> V_216 = F_8 ( V_65 -> V_132 ) ;
V_148 += sizeof( struct V_176 ) ;
V_149 += sizeof( struct V_176 ) ;
}
if ( V_65 -> V_131 >= V_217 &&
V_65 -> V_131 <= V_218 ) {
V_131 = (struct V_175 * ) V_149 ;
V_131 -> V_150 . type =
F_8 ( V_219 ) ;
V_131 -> V_150 . V_122 =
F_8 ( sizeof( struct V_175 ) -
sizeof( struct V_152 ) ) ;
V_131 -> V_216 = V_65 -> V_131 ;
V_148 += sizeof( struct V_175 ) ;
V_149 += sizeof( struct V_175 ) ;
}
if ( V_65 -> V_133 <= V_220 ) {
V_133 = (struct V_184 * ) V_149 ;
V_133 -> V_150 . type =
F_8 ( V_221 ) ;
V_133 -> V_150 . V_122 =
F_8 ( sizeof( struct V_184 ) -
sizeof( struct V_152 ) ) ;
V_133 -> V_222 = F_8 ( V_65 -> V_133 ) ;
V_148 += sizeof( struct V_183 ) ;
V_149 += sizeof( struct V_183 ) ;
}
if ( ( V_65 -> V_134 >= V_223 ) &&
( V_65 -> V_134 <= V_224 ) ) {
V_134 = (struct V_183 * ) V_149 ;
V_134 -> V_150 . type =
F_8 ( V_225 ) ;
V_134 -> V_150 . V_122 =
F_8 ( sizeof( struct V_183 ) -
sizeof( struct V_152 ) ) ;
V_134 -> V_226 = F_8 ( V_65 -> V_134 ) ;
V_148 += sizeof( struct V_183 ) ;
V_149 += sizeof( struct V_183 ) ;
}
if ( V_65 -> V_135 <= V_227 ) {
V_135 = (struct V_185 * ) V_149 ;
V_135 -> V_150 . type =
F_8 ( V_228 ) ;
V_135 -> V_150 . V_122 =
F_8 ( sizeof( struct V_185 ) -
sizeof( struct V_152 ) ) ;
V_135 -> V_229 = ( T_1 ) V_65 -> V_135 ;
V_148 += sizeof( struct V_185 ) ;
V_149 += sizeof( struct V_185 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_230 ) )
F_16 ( & V_149 , V_138 , & V_148 ) ;
else
F_19 ( & V_149 , V_138 , & V_148 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_188 * ) V_149 ;
V_21 -> V_150 . type = F_8 ( V_231 ) ;
V_21 -> V_150 . V_122 =
F_8 ( sizeof( struct V_188 ) -
sizeof( struct V_152 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_148 += sizeof( struct V_188 ) ;
V_149 += sizeof( struct V_188 ) ;
}
if ( V_65 -> V_11 ) {
V_187 = (struct V_186 * ) V_149 ;
V_187 -> V_150 . type =
F_8 ( V_232 ) ;
V_187 -> V_150 . V_122 =
F_8 ( sizeof( struct V_186 )
- sizeof( struct V_152 ) ) ;
V_187 -> V_155 = F_8 ( V_65 -> V_11 ) ;
V_148 += sizeof( struct V_186 ) ;
V_149 += sizeof( struct V_186 ) ;
}
if ( V_65 -> V_74 . V_67 ) {
V_197 = (struct V_196 * ) V_149 ;
V_197 -> V_150 . type = F_8 ( V_70 ) ;
V_197 -> V_150 . V_122 =
F_8 ( sizeof( struct V_75 ) ) ;
V_197 -> V_74 . V_67 = V_65 -> V_74 . V_67 ;
V_197 -> V_74 . V_85 =
V_65 -> V_74 . V_85 ;
memcpy ( & V_197 -> V_74 . V_76 , & V_65 -> V_74 . V_76 ,
sizeof( struct V_233 ) ) ;
V_197 -> V_74 . V_234 =
V_65 -> V_74 . V_234 ;
V_197 -> V_74 . V_235 = V_65 -> V_74 . V_235 ;
V_197 -> V_74 . V_236 =
V_65 -> V_74 . V_236 ;
V_148 += sizeof( struct V_196 ) ;
V_149 += sizeof( struct V_196 ) ;
}
if ( V_65 -> V_164 . V_136 != 0xFF ) {
V_199 = (struct V_198 * ) V_149 ;
V_199 -> V_150 . type = F_8 ( V_237 ) ;
V_199 -> V_150 . V_122 = F_8 ( sizeof( V_199 -> V_164 ) ) ;
memcpy ( & V_199 -> V_164 , & V_65 -> V_164 ,
sizeof( V_199 -> V_164 ) ) ;
V_148 += sizeof( struct V_198 ) ;
V_149 += sizeof( struct V_198 ) ;
}
if ( V_65 -> V_238 ) {
V_192 = (struct V_191 * ) V_149 ;
V_192 -> V_150 . type = F_8 ( V_239 ) ;
V_192 -> V_150 . V_122 = F_8 ( sizeof( * V_192 ) -
sizeof( struct V_152 ) ) ;
V_192 -> V_238 = F_21 ( V_65 -> V_238 ) ;
V_148 += sizeof( * V_192 ) ;
V_149 += sizeof( * V_192 ) ;
}
if ( V_65 -> V_94 ) {
V_195 = ( void * ) V_149 ;
V_195 -> V_150 . type = F_8 ( V_240 ) ;
V_195 -> V_150 . V_122 = F_8 ( sizeof( T_1 ) ) ;
V_195 -> V_241 = V_65 -> V_94 ;
V_148 += sizeof( * V_195 ) ;
V_149 += sizeof( * V_195 ) ;
}
if ( V_65 -> V_242 ) {
V_193 = (struct V_191 * ) V_149 ;
V_193 -> V_150 . type =
F_8 ( V_243 ) ;
V_193 -> V_150 . V_122 = F_8 ( sizeof( * V_193 ) -
sizeof( struct V_152 ) ) ;
V_193 -> V_238 =
F_21 ( V_65 -> V_242 ) ;
V_148 += sizeof( * V_193 ) ;
V_149 += sizeof( * V_193 ) ;
}
* V_139 = V_148 ;
return 0 ;
}
static int F_22 ( T_1 * V_149 , void * V_138 , T_2 * V_244 )
{
struct V_245 * V_246 = V_138 ;
struct V_152 * V_247 = ( void * ) V_149 ;
if ( ! V_246 || ! V_246 -> V_122 || ! V_246 -> V_248 )
return - 1 ;
* V_244 += F_5 ( V_246 -> V_122 ) +
sizeof( struct V_152 ) ;
V_247 -> type = F_8 ( V_249 ) ;
V_247 -> V_122 = V_246 -> V_122 ;
V_149 += sizeof( struct V_152 ) ;
memcpy ( V_149 , V_246 -> V_248 , F_5 ( V_246 -> V_122 ) ) ;
return 0 ;
}
static int
F_23 ( struct V_250 * V_251 , T_2 V_252 ,
T_3 type , void * V_138 )
{
T_1 * V_149 ;
T_2 V_148 , V_139 , V_244 ;
struct V_253 * V_254 ;
V_251 -> V_255 = F_8 ( V_256 ) ;
V_148 = ( T_2 ) ( sizeof( struct V_253 ) + V_257 ) ;
V_254 = (struct V_253 * ) & V_251 -> V_6 . V_258 ;
V_254 -> V_259 = F_8 ( V_252 ) ;
V_149 = V_254 -> V_149 ;
switch ( type ) {
case V_260 :
V_139 = V_148 ;
if ( F_20 ( V_149 , V_138 , & V_139 ) )
return - 1 ;
V_251 -> V_261 = F_8 ( V_139 ) ;
break;
case V_262 :
V_244 = V_148 ;
if ( F_22 ( V_149 , V_138 , & V_244 ) )
return - 1 ;
V_251 -> V_261 = F_8 ( V_244 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_250 * V_251 , T_1 * V_263 )
{
struct V_264 * V_265 = & V_251 -> V_6 . V_265 ;
V_251 -> V_255 = F_8 ( V_266 ) ;
memcpy ( V_265 -> V_263 , V_263 , V_267 ) ;
V_265 -> V_268 = F_8 ( V_269 ) ;
V_251 -> V_261 = F_8 ( sizeof( struct V_264 ) +
V_257 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , T_2 V_270 ,
T_2 V_252 , T_3 type ,
void * V_271 , void * V_138 )
{
struct V_250 * V_251 = V_138 ;
switch ( V_270 ) {
case V_256 :
if ( F_23 ( V_251 , V_252 , type , V_271 ) )
return - 1 ;
break;
case V_272 :
case V_273 :
case V_274 :
case V_275 :
V_251 -> V_255 = F_8 ( V_270 ) ;
V_251 -> V_261 = F_8 ( V_257 ) ;
break;
case V_266 :
if ( F_24 ( V_2 , V_251 , V_271 ) )
return - 1 ;
break;
case V_276 :
if ( F_26 ( V_2 , V_138 ,
V_271 ) )
return - 1 ;
break;
default:
F_7 ( V_2 -> V_68 , ERROR ,
L_2 , V_270 ) ;
return - 1 ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_277 V_278 )
{
T_1 V_279 = 0 , V_280 = V_2 -> V_68 -> V_279 ;
V_2 -> V_281 = V_278 ;
V_65 -> V_206 = F_28 (
V_278 . V_282 -> V_283 ) ;
if ( V_278 . V_282 -> V_284 == V_285 ) {
V_65 -> V_207 = V_208 ;
V_279 = V_286 | V_287 ;
if ( V_278 . V_96 > V_288 )
V_279 |= V_289 ;
} else {
V_65 -> V_207 = V_210 ;
V_279 = V_290 ;
if ( V_278 . V_96 > V_288 )
V_279 |= V_291 ;
if ( V_278 . V_96 > V_292 )
V_279 |= V_293 ;
}
V_2 -> V_68 -> V_279 = V_279 ;
if ( V_280 != V_279 ) {
F_29 ( V_2 -> V_68 -> V_294 ) ;
F_30 ( V_2 ) ;
}
}
int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_65 )
{
enum V_295 V_296 ;
if ( F_12 ( V_2 , V_256 ,
V_113 ,
V_260 , V_65 , false ) ) {
F_7 ( V_2 -> V_68 , ERROR ,
L_3 ) ;
return - 1 ;
}
V_296 = V_297 ;
if ( F_12 ( V_2 , V_298 ,
V_113 , V_299 ,
& V_296 , true ) ) {
F_7 ( V_2 -> V_68 , ERROR ,
L_4 ) ;
return - 1 ;
}
if ( F_12 ( V_2 , V_272 ,
V_113 , 0 , NULL , false ) ) {
F_7 ( V_2 -> V_68 , ERROR ,
L_5 ) ;
return - 1 ;
}
if ( V_2 -> V_17 . V_18 )
V_2 -> V_300 |= V_301 ;
else
V_2 -> V_300 &= ~ V_301 ;
if ( F_12 ( V_2 , V_302 ,
V_113 , 0 ,
& V_2 -> V_300 , true ) )
return - 1 ;
return 0 ;
}
