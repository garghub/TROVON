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
static int
F_17 ( T_1 * V_142 , void * V_131 , T_2 * V_132 )
{
struct V_168 * V_124 ;
struct V_169 * V_125 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_176 * V_127 ;
struct V_177 * V_126 ;
struct V_178 * V_128 ;
struct V_179 * V_180 ;
struct V_181 * V_21 ;
struct V_182 * V_183 ;
struct V_184 * V_185 , * V_186 ;
struct V_187 * V_188 ;
struct V_189 * V_190 ;
struct V_191 * V_192 ;
struct V_3 * V_65 = V_131 ;
int V_7 ;
T_2 V_141 = * V_132 ;
if ( V_65 -> V_171 . V_193 ) {
V_171 = (struct V_170 * ) V_142 ;
V_171 -> V_143 . type = F_5 ( V_194 ) ;
V_171 -> V_143 . V_115 = F_5 ( ( T_2 ) V_65 -> V_171 . V_193 ) ;
memcpy ( V_171 -> V_171 , V_65 -> V_171 . V_171 , V_65 -> V_171 . V_193 ) ;
V_141 += sizeof( struct V_145 ) +
V_65 -> V_171 . V_193 ;
V_142 += sizeof( struct V_145 ) +
V_65 -> V_171 . V_193 ;
V_173 = (struct V_172 * ) V_142 ;
V_173 -> V_143 . type = F_5 ( V_195 ) ;
V_173 -> V_143 . V_115 =
F_5 ( sizeof( V_173 -> V_196 ) ) ;
V_173 -> V_196 = V_65 -> V_122 ;
V_141 += sizeof( struct V_172 ) ;
V_142 += sizeof( struct V_172 ) ;
}
if ( V_65 -> V_119 [ 0 ] ) {
V_183 = (struct V_182 * ) V_142 ;
V_183 -> V_143 . type = F_5 ( V_197 ) ;
for ( V_7 = 0 ; V_7 < V_198 && V_65 -> V_119 [ V_7 ] ;
V_7 ++ )
V_183 -> V_119 [ V_7 ] = V_65 -> V_119 [ V_7 ] ;
V_183 -> V_143 . V_115 = F_5 ( V_7 ) ;
V_141 += sizeof( struct V_182 ) + V_7 ;
V_142 += sizeof( struct V_182 ) + V_7 ;
}
if ( V_65 -> V_199 &&
( ( ( V_65 -> V_200 & F_18 ( 0 ) ) == V_201 &&
V_65 -> V_199 <= V_202 ) ||
( ( V_65 -> V_200 & F_18 ( 0 ) ) == V_203 &&
V_65 -> V_199 <= V_204 ) ) ) {
V_175 = (struct V_174 * ) V_142 ;
V_175 -> V_143 . type = F_5 ( V_205 ) ;
V_175 -> V_143 . V_115 =
F_5 ( sizeof( struct V_174 ) -
sizeof( struct V_145 ) ) ;
V_175 -> V_94 = V_65 -> V_200 ;
V_175 -> V_199 = V_65 -> V_199 ;
V_141 += sizeof( struct V_174 ) ;
V_142 += sizeof( struct V_174 ) ;
}
if ( V_65 -> V_125 >= V_206 &&
V_65 -> V_125 <= V_207 ) {
V_125 = (struct V_169 * ) V_142 ;
V_125 -> V_143 . type =
F_5 ( V_208 ) ;
V_125 -> V_143 . V_115 =
F_5 ( sizeof( struct V_169 ) -
sizeof( struct V_145 ) ) ;
V_125 -> V_209 = F_5 ( V_65 -> V_125 ) ;
V_141 += sizeof( struct V_169 ) ;
V_142 += sizeof( struct V_169 ) ;
}
if ( V_65 -> V_124 >= V_210 &&
V_65 -> V_124 <= V_211 ) {
V_124 = (struct V_168 * ) V_142 ;
V_124 -> V_143 . type =
F_5 ( V_212 ) ;
V_124 -> V_143 . V_115 =
F_5 ( sizeof( struct V_168 ) -
sizeof( struct V_145 ) ) ;
V_124 -> V_209 = V_65 -> V_124 ;
V_141 += sizeof( struct V_168 ) ;
V_142 += sizeof( struct V_168 ) ;
}
if ( V_65 -> V_126 <= V_213 ) {
V_126 = (struct V_177 * ) V_142 ;
V_126 -> V_143 . type =
F_5 ( V_214 ) ;
V_126 -> V_143 . V_115 =
F_5 ( sizeof( struct V_177 ) -
sizeof( struct V_145 ) ) ;
V_126 -> V_215 = F_5 ( V_65 -> V_126 ) ;
V_141 += sizeof( struct V_176 ) ;
V_142 += sizeof( struct V_176 ) ;
}
if ( ( V_65 -> V_127 >= V_216 ) &&
( V_65 -> V_127 <= V_217 ) ) {
V_127 = (struct V_176 * ) V_142 ;
V_127 -> V_143 . type =
F_5 ( V_218 ) ;
V_127 -> V_143 . V_115 =
F_5 ( sizeof( struct V_176 ) -
sizeof( struct V_145 ) ) ;
V_127 -> V_219 = F_5 ( V_65 -> V_127 ) ;
V_141 += sizeof( struct V_176 ) ;
V_142 += sizeof( struct V_176 ) ;
}
if ( V_65 -> V_128 <= V_220 ) {
V_128 = (struct V_178 * ) V_142 ;
V_128 -> V_143 . type =
F_5 ( V_221 ) ;
V_128 -> V_143 . V_115 =
F_5 ( sizeof( struct V_178 ) -
sizeof( struct V_145 ) ) ;
V_128 -> V_222 = ( T_1 ) V_65 -> V_128 ;
V_141 += sizeof( struct V_178 ) ;
V_142 += sizeof( struct V_178 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_223 ) )
F_13 ( & V_142 , V_131 , & V_141 ) ;
else
F_16 ( & V_142 , V_131 , & V_141 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_181 * ) V_142 ;
V_21 -> V_143 . type = F_5 ( V_224 ) ;
V_21 -> V_143 . V_115 =
F_5 ( sizeof( struct V_181 ) -
sizeof( struct V_145 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_141 += sizeof( struct V_181 ) ;
V_142 += sizeof( struct V_181 ) ;
}
if ( V_65 -> V_11 ) {
V_180 = (struct V_179 * ) V_142 ;
V_180 -> V_143 . type =
F_5 ( V_225 ) ;
V_180 -> V_143 . V_115 =
F_5 ( sizeof( struct V_179 )
- sizeof( struct V_145 ) ) ;
V_180 -> V_148 = F_5 ( V_65 -> V_11 ) ;
V_141 += sizeof( struct V_179 ) ;
V_142 += sizeof( struct V_179 ) ;
}
if ( V_65 -> V_73 . V_76 ) {
V_190 = (struct V_189 * ) V_142 ;
V_190 -> V_143 . type = F_5 ( V_69 ) ;
V_190 -> V_143 . V_115 =
F_5 ( sizeof( struct V_74 ) ) ;
V_190 -> V_73 . V_76 = V_65 -> V_73 . V_76 ;
V_190 -> V_73 . V_78 =
V_65 -> V_73 . V_78 ;
memcpy ( & V_190 -> V_73 . V_226 , & V_65 -> V_73 . V_226 ,
sizeof( struct V_227 ) ) ;
V_190 -> V_73 . V_228 =
V_65 -> V_73 . V_228 ;
V_190 -> V_73 . V_229 = V_65 -> V_73 . V_229 ;
V_190 -> V_73 . V_230 =
V_65 -> V_73 . V_230 ;
V_141 += sizeof( struct V_189 ) ;
V_142 += sizeof( struct V_189 ) ;
}
if ( V_65 -> V_157 . V_129 != 0xFF ) {
V_192 = (struct V_191 * ) V_142 ;
V_192 -> V_143 . type = F_5 ( V_231 ) ;
V_192 -> V_143 . V_115 = F_5 ( sizeof( V_192 -> V_157 ) ) ;
memcpy ( & V_192 -> V_157 , & V_65 -> V_157 ,
sizeof( V_192 -> V_157 ) ) ;
V_141 += sizeof( struct V_191 ) ;
V_142 += sizeof( struct V_191 ) ;
}
if ( V_65 -> V_232 ) {
V_185 = (struct V_184 * ) V_142 ;
V_185 -> V_143 . type = F_5 ( V_233 ) ;
V_185 -> V_143 . V_115 = F_5 ( sizeof( * V_185 ) -
sizeof( struct V_145 ) ) ;
V_185 -> V_232 = F_19 ( V_65 -> V_232 ) ;
V_141 += sizeof( * V_185 ) ;
V_142 += sizeof( * V_185 ) ;
}
if ( V_65 -> V_87 ) {
V_188 = ( void * ) V_142 ;
V_188 -> V_143 . type = F_5 ( V_234 ) ;
V_188 -> V_143 . V_115 = F_5 ( sizeof( T_1 ) ) ;
V_188 -> V_235 = V_65 -> V_87 ;
V_141 += sizeof( * V_188 ) ;
V_142 += sizeof( * V_188 ) ;
}
if ( V_65 -> V_236 ) {
V_186 = (struct V_184 * ) V_142 ;
V_186 -> V_143 . type =
F_5 ( V_237 ) ;
V_186 -> V_143 . V_115 = F_5 ( sizeof( * V_186 ) -
sizeof( struct V_145 ) ) ;
V_186 -> V_232 =
F_19 ( V_65 -> V_236 ) ;
V_141 += sizeof( * V_186 ) ;
V_142 += sizeof( * V_186 ) ;
}
* V_132 = V_141 ;
return 0 ;
}
static int F_20 ( T_1 * V_142 , void * V_131 , T_2 * V_238 )
{
struct V_239 * V_240 = V_131 ;
struct V_145 * V_241 = ( void * ) V_142 ;
if ( ! V_240 || ! V_240 -> V_115 )
return - 1 ;
* V_238 += F_21 ( V_240 -> V_115 ) +
sizeof( struct V_145 ) ;
V_241 -> type = F_5 ( V_242 ) ;
V_241 -> V_115 = V_240 -> V_115 ;
V_142 += sizeof( struct V_145 ) ;
memcpy ( V_142 , V_240 -> V_243 , F_21 ( V_240 -> V_115 ) ) ;
return 0 ;
}
static int
F_22 ( struct V_244 * V_245 , T_2 V_246 ,
T_3 type , void * V_131 )
{
T_1 * V_142 ;
T_2 V_141 , V_132 , V_238 ;
struct V_247 * V_248 ;
V_245 -> V_249 = F_5 ( V_250 ) ;
V_141 = ( T_2 ) ( sizeof( struct V_247 ) + V_251 ) ;
V_248 = (struct V_247 * ) & V_245 -> V_6 . V_252 ;
V_248 -> V_253 = F_5 ( V_246 ) ;
V_142 = V_248 -> V_142 ;
switch ( type ) {
case V_254 :
V_132 = V_141 ;
if ( F_17 ( V_142 , V_131 , & V_132 ) )
return - 1 ;
V_245 -> V_255 = F_5 ( V_132 ) ;
break;
case V_256 :
V_238 = V_141 ;
if ( F_20 ( V_142 , V_131 , & V_238 ) )
return - 1 ;
V_245 -> V_255 = F_5 ( V_238 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_244 * V_245 , T_1 * V_257 )
{
struct V_258 * V_259 = & V_245 -> V_6 . V_259 ;
V_245 -> V_249 = F_5 ( V_260 ) ;
memcpy ( V_259 -> V_257 , V_257 , V_261 ) ;
V_259 -> V_262 = F_5 ( V_263 ) ;
V_245 -> V_255 = F_5 ( sizeof( struct V_258 ) +
V_251 ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , T_2 V_264 ,
T_2 V_246 , T_3 type ,
void * V_265 , void * V_131 )
{
struct V_244 * V_245 = V_131 ;
switch ( V_264 ) {
case V_250 :
if ( F_22 ( V_245 , V_246 , type , V_265 ) )
return - 1 ;
break;
case V_266 :
case V_267 :
case V_268 :
case V_269 :
V_245 -> V_249 = F_5 ( V_264 ) ;
V_245 -> V_255 = F_5 ( V_251 ) ;
break;
case V_260 :
if ( F_23 ( V_2 , V_245 , V_265 ) )
return - 1 ;
break;
case V_270 :
if ( F_25 ( V_2 , V_131 ,
V_265 ) )
return - 1 ;
break;
default:
F_26 ( V_2 -> V_67 , ERROR ,
L_1 , V_264 ) ;
return - 1 ;
}
return 0 ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_271 V_272 )
{
T_1 V_273 = 0 , V_274 = V_2 -> V_67 -> V_273 ;
V_2 -> V_275 = V_272 ;
V_65 -> V_199 = F_28 (
V_272 . V_276 -> V_277 ) ;
if ( V_272 . V_276 -> V_278 == V_279 ) {
V_65 -> V_200 = V_201 ;
V_273 = V_280 | V_281 ;
if ( V_272 . V_89 > V_282 )
V_273 |= V_283 ;
} else {
V_65 -> V_200 = V_203 ;
V_273 = V_284 ;
if ( V_272 . V_89 > V_282 )
V_273 |= V_285 ;
if ( V_272 . V_89 > V_286 )
V_273 |= V_287 ;
}
switch ( V_272 . V_89 ) {
case V_288 :
case V_289 :
case V_282 :
case V_290 :
break;
case V_286 :
if ( V_272 . V_291 < V_272 . V_276 -> V_277 )
V_65 -> V_200 |= V_292 ;
else
V_65 -> V_200 |= V_293 ;
break;
case V_103 :
case V_294 :
case V_295 :
V_65 -> V_200 |=
F_29 ( V_65 -> V_199 ) << 4 ;
break;
default:
F_26 ( V_2 -> V_67 ,
V_296 , L_2 ,
V_272 . V_89 ) ;
break;
}
V_2 -> V_67 -> V_273 = V_273 ;
if ( V_274 != V_273 ) {
F_30 ( V_2 -> V_67 -> V_297 ) ;
F_31 ( V_2 ) ;
}
}
int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_65 )
{
enum V_298 V_299 ;
if ( F_9 ( V_2 , V_250 ,
V_106 ,
V_254 , V_65 , true ) ) {
F_26 ( V_2 -> V_67 , ERROR ,
L_3 ) ;
return - 1 ;
}
V_299 = V_300 ;
if ( F_9 ( V_2 , V_301 ,
V_106 , V_302 ,
& V_299 , true ) ) {
F_26 ( V_2 -> V_67 , ERROR ,
L_4 ) ;
return - 1 ;
}
if ( F_9 ( V_2 , V_266 ,
V_106 , 0 , NULL , true ) ) {
F_26 ( V_2 -> V_67 , ERROR ,
L_5 ) ;
return - 1 ;
}
if ( V_2 -> V_17 . V_18 )
V_2 -> V_303 |= V_304 ;
else
V_2 -> V_303 &= ~ V_304 ;
if ( F_9 ( V_2 , V_305 ,
V_106 , 0 ,
& V_2 -> V_303 , true ) )
return - 1 ;
return 0 ;
}
