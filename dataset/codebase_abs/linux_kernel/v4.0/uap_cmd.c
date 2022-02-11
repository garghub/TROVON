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
memcpy ( & V_65 -> V_74 , V_66 ,
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
F_7 ( V_2 -> V_68 -> V_82 ,
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
enum V_92 V_93 ,
bool V_94 )
{
struct V_95 * V_68 = V_2 -> V_68 ;
struct V_96 V_97 ;
V_97 . V_98 = V_99 ;
V_97 . V_67 = V_68 -> V_100 ;
if ( ! V_94 ) {
V_97 . V_101 = V_102 ;
V_97 . V_103 = V_102 ;
} else {
V_97 . V_101 = V_104 ;
V_97 . V_103 = V_104 ;
}
V_97 . V_105 = V_106 ;
if ( V_94 && V_93 >= V_107 )
V_97 . V_105 |= V_108 ;
F_11 ( V_2 , V_109 ,
V_110 , 0 , & V_97 , true ) ;
return;
}
void
F_12 ( struct V_3 * V_65 ,
struct V_5 * V_6 )
{
struct V_111 * V_112 ;
int V_113 = F_13 ( struct V_114 , V_115 . V_71 . V_116 ) ;
const T_1 * V_117 = V_6 -> V_71 . V_118 + V_113 ;
int V_119 = V_6 -> V_71 . V_120 - V_113 ;
T_1 V_121 = 0 ;
V_112 = ( void * ) F_4 ( V_122 , V_117 , V_119 ) ;
if ( V_112 ) {
memcpy ( V_65 -> V_123 , V_112 + 1 , V_112 -> V_119 ) ;
V_121 = V_112 -> V_119 ;
}
V_112 = ( void * ) F_4 ( V_124 ,
V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_112 )
memcpy ( V_65 -> V_123 + V_121 , V_112 + 1 , V_112 -> V_119 ) ;
return;
}
void F_14 ( struct V_3 * V_125 )
{
V_125 -> V_126 = 0x7F ;
V_125 -> V_127 = 0x7F ;
V_125 -> V_128 = 0x7F ;
V_125 -> V_129 = 0x7FFF ;
V_125 -> V_23 = 0x7F ;
V_125 -> V_130 = 0x7FFF ;
V_125 -> V_131 = 0x7FFF ;
V_125 -> V_132 = 0x7F ;
V_125 -> V_133 = 0xFF ;
}
static void
F_15 ( T_1 * * V_134 , void * V_135 , T_2 * V_136 )
{
struct V_137 * V_138 ;
struct V_139 * V_140 ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_3 * V_65 = V_135 ;
T_2 V_145 = * V_136 ;
T_1 * V_146 = * V_134 ;
V_144 = (struct V_143 * ) V_146 ;
V_144 -> V_147 . type = F_8 ( V_148 ) ;
V_144 -> V_147 . V_119 = F_8 ( sizeof( struct V_143 ) -
sizeof( struct V_149 ) ) ;
V_144 -> V_30 = F_8 ( V_65 -> V_30 ) ;
V_144 -> V_13 = F_8 ( V_65 -> V_13 ) ;
V_145 += sizeof( struct V_143 ) ;
V_146 += sizeof( struct V_143 ) ;
if ( V_65 -> V_15 . V_49 & V_150 ) {
V_138 = (struct V_137 * ) V_146 ;
V_138 -> V_147 . type = F_8 ( V_151 ) ;
V_138 -> V_147 . V_119 =
F_8 ( sizeof( struct V_137 ) -
sizeof( struct V_149 ) ) ;
V_138 -> V_152 = F_8 ( V_38 ) ;
V_138 -> V_153 = V_65 -> V_15 . V_49 ;
V_145 += sizeof( struct V_137 ) ;
V_146 += sizeof( struct V_137 ) ;
}
if ( V_65 -> V_15 . V_51 & V_150 ) {
V_138 = (struct V_137 * ) V_146 ;
V_138 -> V_147 . type = F_8 ( V_151 ) ;
V_138 -> V_147 . V_119 =
F_8 ( sizeof( struct V_137 ) -
sizeof( struct V_149 ) ) ;
V_138 -> V_152 = F_8 ( V_41 ) ;
V_138 -> V_153 = V_65 -> V_15 . V_51 ;
V_145 += sizeof( struct V_137 ) ;
V_146 += sizeof( struct V_137 ) ;
}
if ( V_65 -> V_15 . V_64 & V_150 ) {
V_140 = (struct V_139 * ) V_146 ;
V_140 -> V_147 . type = F_8 ( V_154 ) ;
V_140 -> V_147 . V_119 =
F_8 ( sizeof( struct V_139 ) -
sizeof( struct V_149 ) ) ;
V_140 -> V_153 = V_65 -> V_15 . V_64 ;
V_145 += sizeof( struct V_139 ) ;
V_146 += sizeof( struct V_139 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_142 = (struct V_141 * ) V_146 ;
V_142 -> V_147 . type =
F_8 ( V_155 ) ;
V_142 -> V_147 . V_119 = F_8 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_142 -> V_142 , V_65 -> V_15 . V_142 ,
V_65 -> V_15 . V_16 ) ;
V_145 += sizeof( struct V_149 ) +
V_65 -> V_15 . V_16 ;
V_146 += sizeof( struct V_149 ) +
V_65 -> V_15 . V_16 ;
}
* V_136 = V_145 ;
* V_134 = V_146 ;
return;
}
void
F_16 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_156 ;
struct V_111 * V_157 ;
T_1 V_158 [] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_156 = F_17 ( V_159 ,
V_160 ,
V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_156 ) {
V_157 = (struct V_111 * ) V_156 ;
memcpy ( & V_65 -> V_161 , V_157 + 1 ,
sizeof( V_65 -> V_161 ) ) ;
V_2 -> V_162 = 1 ;
} else {
memset ( & V_65 -> V_161 , 0 , sizeof( V_65 -> V_161 ) ) ;
memcpy ( & V_65 -> V_161 . V_163 , V_158 , sizeof( V_158 ) ) ;
V_65 -> V_161 . V_164 = V_165 ;
V_65 -> V_161 . V_166 = V_167 ;
V_2 -> V_162 = 0 ;
}
V_65 -> V_133 = 0x00 ;
return;
}
static void
F_18 ( T_1 * * V_134 , void * V_135 , T_2 * V_136 )
{
struct V_168 * V_9 ;
T_2 V_145 = * V_136 ;
int V_7 ;
T_1 * V_146 = * V_134 ;
struct V_3 * V_65 = V_135 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_169 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_170 ) ) {
V_9 = (struct V_168 * ) V_146 ;
V_9 -> V_147 . type =
F_8 ( V_171 ) ;
V_9 -> V_147 . V_119 =
F_8 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_145 += sizeof( struct V_149 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_146 += sizeof( struct V_149 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_136 = V_145 ;
* V_134 = V_146 ;
return;
}
static int
F_19 ( T_1 * V_146 , void * V_135 , T_2 * V_136 )
{
struct V_172 * V_128 ;
struct V_173 * V_129 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_180 * V_131 ;
struct V_181 * V_130 ;
struct V_182 * V_132 ;
struct V_183 * V_184 ;
struct V_185 * V_21 ;
struct V_186 * V_187 ;
struct V_188 * V_189 , * V_190 ;
struct V_191 * V_192 ;
struct V_193 * V_194 ;
struct V_3 * V_65 = V_135 ;
int V_7 ;
T_2 V_145 = * V_136 ;
if ( V_65 -> V_175 . V_195 ) {
V_175 = (struct V_174 * ) V_146 ;
V_175 -> V_147 . type = F_8 ( V_196 ) ;
V_175 -> V_147 . V_119 = F_8 ( ( T_2 ) V_65 -> V_175 . V_195 ) ;
memcpy ( V_175 -> V_175 , V_65 -> V_175 . V_175 , V_65 -> V_175 . V_195 ) ;
V_145 += sizeof( struct V_149 ) +
V_65 -> V_175 . V_195 ;
V_146 += sizeof( struct V_149 ) +
V_65 -> V_175 . V_195 ;
V_177 = (struct V_176 * ) V_146 ;
V_177 -> V_147 . type = F_8 ( V_197 ) ;
V_177 -> V_147 . V_119 =
F_8 ( sizeof( V_177 -> V_198 ) ) ;
V_177 -> V_198 = V_65 -> V_126 ;
V_145 += sizeof( struct V_176 ) ;
V_146 += sizeof( struct V_176 ) ;
}
if ( V_65 -> V_123 [ 0 ] ) {
V_187 = (struct V_186 * ) V_146 ;
V_187 -> V_147 . type = F_8 ( V_199 ) ;
for ( V_7 = 0 ; V_7 < V_200 && V_65 -> V_123 [ V_7 ] ;
V_7 ++ )
V_187 -> V_123 [ V_7 ] = V_65 -> V_123 [ V_7 ] ;
V_187 -> V_147 . V_119 = F_8 ( V_7 ) ;
V_145 += sizeof( struct V_186 ) + V_7 ;
V_146 += sizeof( struct V_186 ) + V_7 ;
}
if ( V_65 -> V_201 &&
( ( V_65 -> V_202 == V_203 &&
V_65 -> V_201 <= V_204 ) ||
( V_65 -> V_202 == V_205 &&
V_65 -> V_201 <= V_206 ) ) ) {
V_179 = (struct V_178 * ) V_146 ;
V_179 -> V_147 . type = F_8 ( V_207 ) ;
V_179 -> V_147 . V_119 =
F_8 ( sizeof( struct V_178 ) -
sizeof( struct V_149 ) ) ;
V_179 -> V_98 = V_65 -> V_202 ;
V_179 -> V_201 = V_65 -> V_201 ;
V_145 += sizeof( struct V_178 ) ;
V_146 += sizeof( struct V_178 ) ;
}
if ( V_65 -> V_129 >= V_208 &&
V_65 -> V_129 <= V_209 ) {
V_129 = (struct V_173 * ) V_146 ;
V_129 -> V_147 . type =
F_8 ( V_210 ) ;
V_129 -> V_147 . V_119 =
F_8 ( sizeof( struct V_173 ) -
sizeof( struct V_149 ) ) ;
V_129 -> V_211 = F_8 ( V_65 -> V_129 ) ;
V_145 += sizeof( struct V_173 ) ;
V_146 += sizeof( struct V_173 ) ;
}
if ( V_65 -> V_128 >= V_212 &&
V_65 -> V_128 <= V_213 ) {
V_128 = (struct V_172 * ) V_146 ;
V_128 -> V_147 . type =
F_8 ( V_214 ) ;
V_128 -> V_147 . V_119 =
F_8 ( sizeof( struct V_172 ) -
sizeof( struct V_149 ) ) ;
V_128 -> V_211 = V_65 -> V_128 ;
V_145 += sizeof( struct V_172 ) ;
V_146 += sizeof( struct V_172 ) ;
}
if ( V_65 -> V_130 <= V_215 ) {
V_130 = (struct V_181 * ) V_146 ;
V_130 -> V_147 . type =
F_8 ( V_216 ) ;
V_130 -> V_147 . V_119 =
F_8 ( sizeof( struct V_181 ) -
sizeof( struct V_149 ) ) ;
V_130 -> V_217 = F_8 ( V_65 -> V_130 ) ;
V_145 += sizeof( struct V_180 ) ;
V_146 += sizeof( struct V_180 ) ;
}
if ( ( V_65 -> V_131 >= V_218 ) &&
( V_65 -> V_131 <= V_219 ) ) {
V_131 = (struct V_180 * ) V_146 ;
V_131 -> V_147 . type =
F_8 ( V_220 ) ;
V_131 -> V_147 . V_119 =
F_8 ( sizeof( struct V_180 ) -
sizeof( struct V_149 ) ) ;
V_131 -> V_221 = F_8 ( V_65 -> V_131 ) ;
V_145 += sizeof( struct V_180 ) ;
V_146 += sizeof( struct V_180 ) ;
}
if ( V_65 -> V_132 <= V_222 ) {
V_132 = (struct V_182 * ) V_146 ;
V_132 -> V_147 . type =
F_8 ( V_223 ) ;
V_132 -> V_147 . V_119 =
F_8 ( sizeof( struct V_182 ) -
sizeof( struct V_149 ) ) ;
V_132 -> V_224 = ( T_1 ) V_65 -> V_132 ;
V_145 += sizeof( struct V_182 ) ;
V_146 += sizeof( struct V_182 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_225 ) )
F_15 ( & V_146 , V_135 , & V_145 ) ;
else
F_18 ( & V_146 , V_135 , & V_145 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_185 * ) V_146 ;
V_21 -> V_147 . type = F_8 ( V_226 ) ;
V_21 -> V_147 . V_119 =
F_8 ( sizeof( struct V_185 ) -
sizeof( struct V_149 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_145 += sizeof( struct V_185 ) ;
V_146 += sizeof( struct V_185 ) ;
}
if ( V_65 -> V_11 ) {
V_184 = (struct V_183 * ) V_146 ;
V_184 -> V_147 . type =
F_8 ( V_227 ) ;
V_184 -> V_147 . V_119 =
F_8 ( sizeof( struct V_183 )
- sizeof( struct V_149 ) ) ;
V_184 -> V_152 = F_8 ( V_65 -> V_11 ) ;
V_145 += sizeof( struct V_183 ) ;
V_146 += sizeof( struct V_183 ) ;
}
if ( V_65 -> V_74 . V_67 ) {
V_192 = (struct V_191 * ) V_146 ;
V_192 -> V_147 . type = F_8 ( V_70 ) ;
V_192 -> V_147 . V_119 =
F_8 ( sizeof( struct V_75 ) ) ;
V_192 -> V_74 . V_67 = V_65 -> V_74 . V_67 ;
V_192 -> V_74 . V_85 =
V_65 -> V_74 . V_85 ;
memcpy ( & V_192 -> V_74 . V_76 , & V_65 -> V_74 . V_76 ,
sizeof( struct V_228 ) ) ;
V_192 -> V_74 . V_229 =
V_65 -> V_74 . V_229 ;
V_192 -> V_74 . V_230 = V_65 -> V_74 . V_230 ;
V_192 -> V_74 . V_231 =
V_65 -> V_74 . V_231 ;
V_145 += sizeof( struct V_191 ) ;
V_146 += sizeof( struct V_191 ) ;
}
if ( V_65 -> V_161 . V_133 != 0xFF ) {
V_194 = (struct V_193 * ) V_146 ;
V_194 -> V_147 . type = F_8 ( V_232 ) ;
V_194 -> V_147 . V_119 = F_8 ( sizeof( V_194 -> V_161 ) ) ;
memcpy ( & V_194 -> V_161 , & V_65 -> V_161 ,
sizeof( V_194 -> V_161 ) ) ;
V_145 += sizeof( struct V_193 ) ;
V_146 += sizeof( struct V_193 ) ;
}
if ( V_65 -> V_233 ) {
V_189 = (struct V_188 * ) V_146 ;
V_189 -> V_147 . type = F_8 ( V_234 ) ;
V_189 -> V_147 . V_119 = F_8 ( sizeof( * V_189 ) -
sizeof( struct V_149 ) ) ;
V_189 -> V_233 = F_20 ( V_65 -> V_233 ) ;
V_145 += sizeof( * V_189 ) ;
V_146 += sizeof( * V_189 ) ;
}
if ( V_65 -> V_235 ) {
V_190 = (struct V_188 * ) V_146 ;
V_190 -> V_147 . type =
F_8 ( V_236 ) ;
V_190 -> V_147 . V_119 = F_8 ( sizeof( * V_190 ) -
sizeof( struct V_149 ) ) ;
V_190 -> V_233 =
F_20 ( V_65 -> V_235 ) ;
V_145 += sizeof( * V_190 ) ;
V_146 += sizeof( * V_190 ) ;
}
* V_136 = V_145 ;
return 0 ;
}
static int F_21 ( T_1 * V_146 , void * V_135 , T_2 * V_237 )
{
struct V_238 * V_239 = V_135 ;
struct V_149 * V_240 = ( void * ) V_146 ;
if ( ! V_239 || ! V_239 -> V_119 || ! V_239 -> V_241 )
return - 1 ;
* V_237 += F_5 ( V_239 -> V_119 ) +
sizeof( struct V_149 ) ;
V_240 -> type = F_8 ( V_242 ) ;
V_240 -> V_119 = V_239 -> V_119 ;
V_146 += sizeof( struct V_149 ) ;
memcpy ( V_146 , V_239 -> V_241 , F_5 ( V_239 -> V_119 ) ) ;
return 0 ;
}
static int
F_22 ( struct V_243 * V_244 , T_2 V_245 ,
T_3 type , void * V_135 )
{
T_1 * V_146 ;
T_2 V_145 , V_136 , V_237 ;
struct V_246 * V_247 ;
V_244 -> V_248 = F_8 ( V_249 ) ;
V_145 = ( T_2 ) ( sizeof( struct V_246 ) + V_250 ) ;
V_247 = (struct V_246 * ) & V_244 -> V_6 . V_251 ;
V_247 -> V_252 = F_8 ( V_245 ) ;
V_146 = V_247 -> V_146 ;
switch ( type ) {
case V_253 :
V_136 = V_145 ;
if ( F_19 ( V_146 , V_135 , & V_136 ) )
return - 1 ;
V_244 -> V_254 = F_8 ( V_136 ) ;
break;
case V_255 :
V_237 = V_145 ;
if ( F_21 ( V_146 , V_135 , & V_237 ) )
return - 1 ;
V_244 -> V_254 = F_8 ( V_237 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_243 * V_244 , T_1 * V_256 )
{
struct V_257 * V_258 = & V_244 -> V_6 . V_258 ;
V_244 -> V_248 = F_8 ( V_259 ) ;
memcpy ( V_258 -> V_256 , V_256 , V_260 ) ;
V_258 -> V_261 = F_8 ( V_262 ) ;
V_244 -> V_254 = F_8 ( sizeof( struct V_257 ) +
V_250 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_263 ,
T_2 V_245 , T_3 type ,
void * V_264 , void * V_135 )
{
struct V_243 * V_244 = V_135 ;
switch ( V_263 ) {
case V_249 :
if ( F_22 ( V_244 , V_245 , type , V_264 ) )
return - 1 ;
break;
case V_265 :
case V_266 :
V_244 -> V_248 = F_8 ( V_263 ) ;
V_244 -> V_254 = F_8 ( V_250 ) ;
break;
case V_259 :
if ( F_23 ( V_2 , V_244 , V_264 ) )
return - 1 ;
break;
case V_267 :
if ( F_25 ( V_2 , V_135 ,
V_264 ) )
return - 1 ;
break;
default:
F_26 ( V_2 -> V_68 -> V_82 ,
L_2 , V_263 ) ;
return - 1 ;
}
return 0 ;
}
void F_27 ( struct V_3 * V_65 ,
struct V_268 V_269 )
{
T_1 V_270 = 0 ;
V_65 -> V_201 = F_28 (
V_269 . V_271 -> V_272 ) ;
if ( V_269 . V_271 -> V_273 == V_274 ) {
V_65 -> V_202 = V_203 ;
V_270 = V_275 | V_276 ;
if ( V_269 . V_93 > V_277 )
V_270 |= V_278 ;
} else {
V_65 -> V_202 = V_205 ;
V_270 = V_279 ;
if ( V_269 . V_93 > V_277 )
V_270 |= V_280 ;
if ( V_269 . V_93 > V_281 )
V_270 |= V_282 ;
}
}
int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_65 )
{
if ( F_30 ( V_2 ) )
F_26 ( V_2 -> V_68 -> V_82 , L_3 ) ;
if ( F_11 ( V_2 , V_266 ,
V_110 , 0 , NULL , true ) ) {
F_26 ( V_2 -> V_68 -> V_82 , L_4 ) ;
return - 1 ;
}
if ( F_11 ( V_2 , V_249 ,
V_110 ,
V_253 , V_65 , false ) ) {
F_26 ( V_2 -> V_68 -> V_82 , L_5 ) ;
return - 1 ;
}
if ( F_11 ( V_2 , V_265 ,
V_110 , 0 , NULL , false ) ) {
F_26 ( V_2 -> V_68 -> V_82 , L_6 ) ;
return - 1 ;
}
if ( V_2 -> V_17 . V_18 )
V_2 -> V_283 |= V_284 ;
else
V_2 -> V_283 &= ~ V_284 ;
if ( F_11 ( V_2 , V_285 ,
V_110 , 0 ,
& V_2 -> V_283 , true ) )
return - 1 ;
return 0 ;
}
