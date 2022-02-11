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
memset ( & V_65 -> V_74 . V_76 , 0xff , 1 ) ;
break;
case V_79 :
case V_80 :
memset ( & V_65 -> V_74 . V_76 , 0xff , 2 ) ;
break;
default:
F_7 ( V_2 -> V_68 -> V_81 ,
L_1 ) ;
memset ( & V_65 -> V_74 . V_76 , 0xff , 2 ) ;
break;
}
V_2 -> V_82 = 1 ;
} else {
memset ( & V_65 -> V_74 , 0 , sizeof( struct V_75 ) ) ;
V_65 -> V_74 . V_67 = F_8 ( V_83 ) ;
V_65 -> V_74 . V_84 = V_85 ;
}
return;
}
void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_86 ;
V_86 = F_4 ( V_87 , V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_86 ) {
memcpy ( & V_65 -> V_88 , V_86 + 2 ,
sizeof( struct V_89 ) ) ;
V_2 -> V_90 = 1 ;
} else {
V_2 -> V_90 = 0 ;
}
return;
}
void F_10 ( struct V_1 * V_2 ,
enum V_91 V_92 ,
bool V_93 )
{
struct V_94 * V_68 = V_2 -> V_68 ;
struct V_95 V_96 ;
V_96 . V_97 = V_98 ;
V_96 . V_67 = V_68 -> V_99 ;
if ( ! V_93 ) {
V_96 . V_100 = V_101 ;
V_96 . V_102 = V_101 ;
} else {
V_96 . V_100 = V_103 ;
V_96 . V_102 = V_103 ;
}
V_96 . V_104 = V_105 ;
if ( V_93 && V_92 >= V_106 )
V_96 . V_104 |= V_107 ;
F_11 ( V_2 , V_108 ,
V_109 , 0 , & V_96 , true ) ;
return;
}
void
F_12 ( struct V_3 * V_65 ,
struct V_5 * V_6 )
{
struct V_110 * V_111 ;
int V_112 = F_13 ( struct V_113 , V_114 . V_71 . V_115 ) ;
const T_1 * V_116 = V_6 -> V_71 . V_117 + V_112 ;
int V_118 = V_6 -> V_71 . V_119 - V_112 ;
T_1 V_120 = 0 ;
V_111 = ( void * ) F_4 ( V_121 , V_116 , V_118 ) ;
if ( V_111 ) {
memcpy ( V_65 -> V_122 , V_111 + 1 , V_111 -> V_118 ) ;
V_120 = V_111 -> V_118 ;
}
V_111 = ( void * ) F_4 ( V_123 ,
V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_111 )
memcpy ( V_65 -> V_122 + V_120 , V_111 + 1 , V_111 -> V_118 ) ;
return;
}
void F_14 ( struct V_3 * V_124 )
{
V_124 -> V_125 = 0x7F ;
V_124 -> V_126 = 0x7F ;
V_124 -> V_127 = 0x7F ;
V_124 -> V_128 = 0x7FFF ;
V_124 -> V_23 = 0x7F ;
V_124 -> V_129 = 0x7FFF ;
V_124 -> V_130 = 0x7FFF ;
V_124 -> V_131 = 0x7F ;
V_124 -> V_132 = 0xFF ;
}
static void
F_15 ( T_1 * * V_133 , void * V_134 , T_2 * V_135 )
{
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_3 * V_65 = V_134 ;
T_2 V_144 = * V_135 ;
T_1 * V_145 = * V_133 ;
V_143 = (struct V_142 * ) V_145 ;
V_143 -> V_146 . type = F_8 ( V_147 ) ;
V_143 -> V_146 . V_118 = F_8 ( sizeof( struct V_142 ) -
sizeof( struct V_148 ) ) ;
V_143 -> V_30 = F_8 ( V_65 -> V_30 ) ;
V_143 -> V_13 = F_8 ( V_65 -> V_13 ) ;
V_144 += sizeof( struct V_142 ) ;
V_145 += sizeof( struct V_142 ) ;
if ( V_65 -> V_15 . V_49 & V_149 ) {
V_137 = (struct V_136 * ) V_145 ;
V_137 -> V_146 . type = F_8 ( V_150 ) ;
V_137 -> V_146 . V_118 =
F_8 ( sizeof( struct V_136 ) -
sizeof( struct V_148 ) ) ;
V_137 -> V_151 = F_8 ( V_38 ) ;
V_137 -> V_152 = V_65 -> V_15 . V_49 ;
V_144 += sizeof( struct V_136 ) ;
V_145 += sizeof( struct V_136 ) ;
}
if ( V_65 -> V_15 . V_51 & V_149 ) {
V_137 = (struct V_136 * ) V_145 ;
V_137 -> V_146 . type = F_8 ( V_150 ) ;
V_137 -> V_146 . V_118 =
F_8 ( sizeof( struct V_136 ) -
sizeof( struct V_148 ) ) ;
V_137 -> V_151 = F_8 ( V_41 ) ;
V_137 -> V_152 = V_65 -> V_15 . V_51 ;
V_144 += sizeof( struct V_136 ) ;
V_145 += sizeof( struct V_136 ) ;
}
if ( V_65 -> V_15 . V_64 & V_149 ) {
V_139 = (struct V_138 * ) V_145 ;
V_139 -> V_146 . type = F_8 ( V_153 ) ;
V_139 -> V_146 . V_118 =
F_8 ( sizeof( struct V_138 ) -
sizeof( struct V_148 ) ) ;
V_139 -> V_152 = V_65 -> V_15 . V_64 ;
V_144 += sizeof( struct V_138 ) ;
V_145 += sizeof( struct V_138 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_141 = (struct V_140 * ) V_145 ;
V_141 -> V_146 . type =
F_8 ( V_154 ) ;
V_141 -> V_146 . V_118 = F_8 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_141 -> V_141 , V_65 -> V_15 . V_141 ,
V_65 -> V_15 . V_16 ) ;
V_144 += sizeof( struct V_148 ) +
V_65 -> V_15 . V_16 ;
V_145 += sizeof( struct V_148 ) +
V_65 -> V_15 . V_16 ;
}
* V_135 = V_144 ;
* V_133 = V_145 ;
return;
}
void
F_16 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_155 ;
struct V_110 * V_156 ;
T_1 V_157 [] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_155 = F_17 ( V_158 ,
V_159 ,
V_6 -> V_71 . V_72 ,
V_6 -> V_71 . V_73 ) ;
if ( V_155 ) {
V_156 = (struct V_110 * ) V_155 ;
memcpy ( & V_65 -> V_160 , V_156 + 1 ,
sizeof( V_65 -> V_160 ) ) ;
V_2 -> V_161 = 1 ;
} else {
memset ( & V_65 -> V_160 , 0 , sizeof( V_65 -> V_160 ) ) ;
memcpy ( & V_65 -> V_160 . V_162 , V_157 , sizeof( V_157 ) ) ;
V_65 -> V_160 . V_163 = V_164 ;
V_65 -> V_160 . V_165 = V_166 ;
V_2 -> V_161 = 0 ;
}
V_65 -> V_132 = 0x00 ;
return;
}
static void
F_18 ( T_1 * * V_133 , void * V_134 , T_2 * V_135 )
{
struct V_167 * V_9 ;
T_2 V_144 = * V_135 ;
int V_7 ;
T_1 * V_145 = * V_133 ;
struct V_3 * V_65 = V_134 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_168 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_169 ) ) {
V_9 = (struct V_167 * ) V_145 ;
V_9 -> V_146 . type =
F_8 ( V_170 ) ;
V_9 -> V_146 . V_118 =
F_8 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_144 += sizeof( struct V_148 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_145 += sizeof( struct V_148 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_135 = V_144 ;
* V_133 = V_145 ;
return;
}
static int
F_19 ( T_1 * V_145 , void * V_134 , T_2 * V_135 )
{
struct V_171 * V_127 ;
struct V_172 * V_128 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
struct V_177 * V_178 ;
struct V_179 * V_130 ;
struct V_180 * V_129 ;
struct V_181 * V_131 ;
struct V_182 * V_183 ;
struct V_184 * V_21 ;
struct V_185 * V_186 ;
struct V_187 * V_188 , * V_189 ;
struct V_190 * V_191 ;
struct V_192 * V_193 ;
struct V_3 * V_65 = V_134 ;
int V_7 ;
T_2 V_144 = * V_135 ;
if ( V_65 -> V_174 . V_194 ) {
V_174 = (struct V_173 * ) V_145 ;
V_174 -> V_146 . type = F_8 ( V_195 ) ;
V_174 -> V_146 . V_118 = F_8 ( ( T_2 ) V_65 -> V_174 . V_194 ) ;
memcpy ( V_174 -> V_174 , V_65 -> V_174 . V_174 , V_65 -> V_174 . V_194 ) ;
V_144 += sizeof( struct V_148 ) +
V_65 -> V_174 . V_194 ;
V_145 += sizeof( struct V_148 ) +
V_65 -> V_174 . V_194 ;
V_176 = (struct V_175 * ) V_145 ;
V_176 -> V_146 . type = F_8 ( V_196 ) ;
V_176 -> V_146 . V_118 =
F_8 ( sizeof( V_176 -> V_197 ) ) ;
V_176 -> V_197 = V_65 -> V_125 ;
V_144 += sizeof( struct V_175 ) ;
V_145 += sizeof( struct V_175 ) ;
}
if ( V_65 -> V_122 [ 0 ] ) {
V_186 = (struct V_185 * ) V_145 ;
V_186 -> V_146 . type = F_8 ( V_198 ) ;
for ( V_7 = 0 ; V_7 < V_199 && V_65 -> V_122 [ V_7 ] ;
V_7 ++ )
V_186 -> V_122 [ V_7 ] = V_65 -> V_122 [ V_7 ] ;
V_186 -> V_146 . V_118 = F_8 ( V_7 ) ;
V_144 += sizeof( struct V_185 ) + V_7 ;
V_145 += sizeof( struct V_185 ) + V_7 ;
}
if ( V_65 -> V_200 &&
( ( V_65 -> V_201 == V_202 &&
V_65 -> V_200 <= V_203 ) ||
( V_65 -> V_201 == V_204 &&
V_65 -> V_200 <= V_205 ) ) ) {
V_178 = (struct V_177 * ) V_145 ;
V_178 -> V_146 . type = F_8 ( V_206 ) ;
V_178 -> V_146 . V_118 =
F_8 ( sizeof( struct V_177 ) -
sizeof( struct V_148 ) ) ;
V_178 -> V_97 = V_65 -> V_201 ;
V_178 -> V_200 = V_65 -> V_200 ;
V_144 += sizeof( struct V_177 ) ;
V_145 += sizeof( struct V_177 ) ;
}
if ( V_65 -> V_128 >= V_207 &&
V_65 -> V_128 <= V_208 ) {
V_128 = (struct V_172 * ) V_145 ;
V_128 -> V_146 . type =
F_8 ( V_209 ) ;
V_128 -> V_146 . V_118 =
F_8 ( sizeof( struct V_172 ) -
sizeof( struct V_148 ) ) ;
V_128 -> V_210 = F_8 ( V_65 -> V_128 ) ;
V_144 += sizeof( struct V_172 ) ;
V_145 += sizeof( struct V_172 ) ;
}
if ( V_65 -> V_127 >= V_211 &&
V_65 -> V_127 <= V_212 ) {
V_127 = (struct V_171 * ) V_145 ;
V_127 -> V_146 . type =
F_8 ( V_213 ) ;
V_127 -> V_146 . V_118 =
F_8 ( sizeof( struct V_171 ) -
sizeof( struct V_148 ) ) ;
V_127 -> V_210 = V_65 -> V_127 ;
V_144 += sizeof( struct V_171 ) ;
V_145 += sizeof( struct V_171 ) ;
}
if ( V_65 -> V_129 <= V_214 ) {
V_129 = (struct V_180 * ) V_145 ;
V_129 -> V_146 . type =
F_8 ( V_215 ) ;
V_129 -> V_146 . V_118 =
F_8 ( sizeof( struct V_180 ) -
sizeof( struct V_148 ) ) ;
V_129 -> V_216 = F_8 ( V_65 -> V_129 ) ;
V_144 += sizeof( struct V_179 ) ;
V_145 += sizeof( struct V_179 ) ;
}
if ( ( V_65 -> V_130 >= V_217 ) &&
( V_65 -> V_130 <= V_218 ) ) {
V_130 = (struct V_179 * ) V_145 ;
V_130 -> V_146 . type =
F_8 ( V_219 ) ;
V_130 -> V_146 . V_118 =
F_8 ( sizeof( struct V_179 ) -
sizeof( struct V_148 ) ) ;
V_130 -> V_220 = F_8 ( V_65 -> V_130 ) ;
V_144 += sizeof( struct V_179 ) ;
V_145 += sizeof( struct V_179 ) ;
}
if ( V_65 -> V_131 <= V_221 ) {
V_131 = (struct V_181 * ) V_145 ;
V_131 -> V_146 . type =
F_8 ( V_222 ) ;
V_131 -> V_146 . V_118 =
F_8 ( sizeof( struct V_181 ) -
sizeof( struct V_148 ) ) ;
V_131 -> V_223 = ( T_1 ) V_65 -> V_131 ;
V_144 += sizeof( struct V_181 ) ;
V_145 += sizeof( struct V_181 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_224 ) )
F_15 ( & V_145 , V_134 , & V_144 ) ;
else
F_18 ( & V_145 , V_134 , & V_144 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_184 * ) V_145 ;
V_21 -> V_146 . type = F_8 ( V_225 ) ;
V_21 -> V_146 . V_118 =
F_8 ( sizeof( struct V_184 ) -
sizeof( struct V_148 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_144 += sizeof( struct V_184 ) ;
V_145 += sizeof( struct V_184 ) ;
}
if ( V_65 -> V_11 ) {
V_183 = (struct V_182 * ) V_145 ;
V_183 -> V_146 . type =
F_8 ( V_226 ) ;
V_183 -> V_146 . V_118 =
F_8 ( sizeof( struct V_182 )
- sizeof( struct V_148 ) ) ;
V_183 -> V_151 = F_8 ( V_65 -> V_11 ) ;
V_144 += sizeof( struct V_182 ) ;
V_145 += sizeof( struct V_182 ) ;
}
if ( V_65 -> V_74 . V_67 ) {
V_191 = (struct V_190 * ) V_145 ;
V_191 -> V_146 . type = F_8 ( V_70 ) ;
V_191 -> V_146 . V_118 =
F_8 ( sizeof( struct V_75 ) ) ;
V_191 -> V_74 . V_67 = V_65 -> V_74 . V_67 ;
V_191 -> V_74 . V_84 =
V_65 -> V_74 . V_84 ;
memcpy ( & V_191 -> V_74 . V_76 , & V_65 -> V_74 . V_76 ,
sizeof( struct V_227 ) ) ;
V_191 -> V_74 . V_228 =
V_65 -> V_74 . V_228 ;
V_191 -> V_74 . V_229 = V_65 -> V_74 . V_229 ;
V_191 -> V_74 . V_230 =
V_65 -> V_74 . V_230 ;
V_144 += sizeof( struct V_190 ) ;
V_145 += sizeof( struct V_190 ) ;
}
if ( V_65 -> V_160 . V_132 != 0xFF ) {
V_193 = (struct V_192 * ) V_145 ;
V_193 -> V_146 . type = F_8 ( V_231 ) ;
V_193 -> V_146 . V_118 = F_8 ( sizeof( V_193 -> V_160 ) ) ;
memcpy ( & V_193 -> V_160 , & V_65 -> V_160 ,
sizeof( V_193 -> V_160 ) ) ;
V_144 += sizeof( struct V_192 ) ;
V_145 += sizeof( struct V_192 ) ;
}
if ( V_65 -> V_232 ) {
V_188 = (struct V_187 * ) V_145 ;
V_188 -> V_146 . type = F_8 ( V_233 ) ;
V_188 -> V_146 . V_118 = F_8 ( sizeof( * V_188 ) -
sizeof( struct V_148 ) ) ;
V_188 -> V_232 = F_20 ( V_65 -> V_232 ) ;
V_144 += sizeof( * V_188 ) ;
V_145 += sizeof( * V_188 ) ;
}
if ( V_65 -> V_234 ) {
V_189 = (struct V_187 * ) V_145 ;
V_189 -> V_146 . type =
F_8 ( V_235 ) ;
V_189 -> V_146 . V_118 = F_8 ( sizeof( * V_189 ) -
sizeof( struct V_148 ) ) ;
V_189 -> V_232 =
F_20 ( V_65 -> V_234 ) ;
V_144 += sizeof( * V_189 ) ;
V_145 += sizeof( * V_189 ) ;
}
* V_135 = V_144 ;
return 0 ;
}
static int F_21 ( T_1 * V_145 , void * V_134 , T_2 * V_236 )
{
struct V_237 * V_238 = V_134 ;
struct V_148 * V_239 = ( void * ) V_145 ;
if ( ! V_238 || ! V_238 -> V_118 || ! V_238 -> V_240 )
return - 1 ;
* V_236 += F_5 ( V_238 -> V_118 ) +
sizeof( struct V_148 ) ;
V_239 -> type = F_8 ( V_241 ) ;
V_239 -> V_118 = V_238 -> V_118 ;
V_145 += sizeof( struct V_148 ) ;
memcpy ( V_145 , V_238 -> V_240 , F_5 ( V_238 -> V_118 ) ) ;
return 0 ;
}
static int
F_22 ( struct V_242 * V_243 , T_2 V_244 ,
T_3 type , void * V_134 )
{
T_1 * V_145 ;
T_2 V_144 , V_135 , V_236 ;
struct V_245 * V_246 ;
V_243 -> V_247 = F_8 ( V_248 ) ;
V_144 = ( T_2 ) ( sizeof( struct V_245 ) + V_249 ) ;
V_246 = (struct V_245 * ) & V_243 -> V_6 . V_250 ;
V_246 -> V_251 = F_8 ( V_244 ) ;
V_145 = V_246 -> V_145 ;
switch ( type ) {
case V_252 :
V_135 = V_144 ;
if ( F_19 ( V_145 , V_134 , & V_135 ) )
return - 1 ;
V_243 -> V_253 = F_8 ( V_135 ) ;
break;
case V_254 :
V_236 = V_144 ;
if ( F_21 ( V_145 , V_134 , & V_236 ) )
return - 1 ;
V_243 -> V_253 = F_8 ( V_236 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_242 * V_243 , T_1 * V_255 )
{
struct V_256 * V_257 = & V_243 -> V_6 . V_257 ;
V_243 -> V_247 = F_8 ( V_258 ) ;
memcpy ( V_257 -> V_255 , V_255 , V_259 ) ;
V_257 -> V_260 = F_8 ( V_261 ) ;
V_243 -> V_253 = F_8 ( sizeof( struct V_256 ) +
V_249 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_262 ,
T_2 V_244 , T_3 type ,
void * V_263 , void * V_134 )
{
struct V_242 * V_243 = V_134 ;
switch ( V_262 ) {
case V_248 :
if ( F_22 ( V_243 , V_244 , type , V_263 ) )
return - 1 ;
break;
case V_264 :
case V_265 :
V_243 -> V_247 = F_8 ( V_262 ) ;
V_243 -> V_253 = F_8 ( V_249 ) ;
break;
case V_258 :
if ( F_23 ( V_2 , V_243 , V_263 ) )
return - 1 ;
break;
default:
F_25 ( V_2 -> V_68 -> V_81 ,
L_2 , V_262 ) ;
return - 1 ;
}
return 0 ;
}
