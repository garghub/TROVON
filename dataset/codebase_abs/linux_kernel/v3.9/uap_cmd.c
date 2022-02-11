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
void
F_6 ( struct V_3 * V_65 ,
struct V_5 * V_6 )
{
struct V_80 * V_81 ;
int V_82 = F_7 ( struct V_83 , V_84 . V_70 . V_85 ) ;
const T_1 * V_86 = V_6 -> V_70 . V_87 + V_82 ;
int V_88 = V_6 -> V_70 . V_89 - V_82 ;
T_1 V_90 = 0 ;
V_81 = ( void * ) F_4 ( V_91 , V_86 , V_88 ) ;
if ( V_81 ) {
memcpy ( V_65 -> V_92 , V_81 + 1 , V_81 -> V_88 ) ;
V_90 = V_81 -> V_88 ;
}
V_81 = ( void * ) F_4 ( V_93 ,
V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_81 )
memcpy ( V_65 -> V_92 + V_90 , V_81 + 1 , V_81 -> V_88 ) ;
return;
}
void F_8 ( struct V_3 * V_94 )
{
V_94 -> V_95 = 0x7F ;
V_94 -> V_96 = 0x7F ;
V_94 -> V_97 = 0x7F ;
V_94 -> V_98 = 0x7FFF ;
V_94 -> V_23 = 0x7F ;
V_94 -> V_99 = 0x7FFF ;
V_94 -> V_100 = 0x7FFF ;
V_94 -> V_101 = 0x7F ;
V_94 -> V_102 = 0xFF ;
}
static void
F_9 ( T_1 * * V_103 , void * V_104 , T_2 * V_105 )
{
struct V_106 * V_107 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
struct V_112 * V_113 ;
struct V_3 * V_65 = V_104 ;
T_2 V_114 = * V_105 ;
T_1 * V_115 = * V_103 ;
V_113 = (struct V_112 * ) V_115 ;
V_113 -> V_115 . type = F_5 ( V_116 ) ;
V_113 -> V_115 . V_88 = F_5 ( sizeof( struct V_112 ) -
sizeof( struct V_117 ) ) ;
V_113 -> V_30 = F_5 ( V_65 -> V_30 ) ;
V_113 -> V_13 = F_5 ( V_65 -> V_13 ) ;
V_114 += sizeof( struct V_112 ) ;
V_115 += sizeof( struct V_112 ) ;
if ( V_65 -> V_15 . V_49 & V_118 ) {
V_107 = (struct V_106 * ) V_115 ;
V_107 -> V_115 . type = F_5 ( V_119 ) ;
V_107 -> V_115 . V_88 =
F_5 ( sizeof( struct V_106 ) -
sizeof( struct V_117 ) ) ;
V_107 -> V_120 = F_5 ( V_38 ) ;
V_107 -> V_121 = V_65 -> V_15 . V_49 ;
V_114 += sizeof( struct V_106 ) ;
V_115 += sizeof( struct V_106 ) ;
}
if ( V_65 -> V_15 . V_51 & V_118 ) {
V_107 = (struct V_106 * ) V_115 ;
V_107 -> V_115 . type = F_5 ( V_119 ) ;
V_107 -> V_115 . V_88 =
F_5 ( sizeof( struct V_106 ) -
sizeof( struct V_117 ) ) ;
V_107 -> V_120 = F_5 ( V_41 ) ;
V_107 -> V_121 = V_65 -> V_15 . V_51 ;
V_114 += sizeof( struct V_106 ) ;
V_115 += sizeof( struct V_106 ) ;
}
if ( V_65 -> V_15 . V_64 & V_118 ) {
V_109 = (struct V_108 * ) V_115 ;
V_109 -> V_115 . type = F_5 ( V_122 ) ;
V_109 -> V_115 . V_88 =
F_5 ( sizeof( struct V_108 ) -
sizeof( struct V_117 ) ) ;
V_109 -> V_121 = V_65 -> V_15 . V_64 ;
V_114 += sizeof( struct V_108 ) ;
V_115 += sizeof( struct V_108 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_111 = (struct V_110 * ) V_115 ;
V_111 -> V_115 . type = F_5 ( V_123 ) ;
V_111 -> V_115 . V_88 = F_5 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_111 -> V_111 , V_65 -> V_15 . V_111 ,
V_65 -> V_15 . V_16 ) ;
V_114 += sizeof( struct V_117 ) +
V_65 -> V_15 . V_16 ;
V_115 += sizeof( struct V_117 ) + V_65 -> V_15 . V_16 ;
}
* V_105 = V_114 ;
* V_103 = V_115 ;
return;
}
void
F_10 ( struct V_1 * V_2 ,
struct V_3 * V_65 ,
struct V_5 * V_6 )
{
const T_1 * V_124 ;
struct V_80 * V_125 ;
T_1 V_126 [] = { 0x00 , 0x50 , 0xf2 , 0x02 } ;
V_124 = F_11 ( V_127 ,
V_128 ,
V_6 -> V_70 . V_71 ,
V_6 -> V_70 . V_72 ) ;
if ( V_124 ) {
V_125 = (struct V_80 * ) V_124 ;
memcpy ( & V_65 -> V_129 , V_125 + 1 ,
sizeof( V_65 -> V_129 ) ) ;
V_2 -> V_130 = 1 ;
} else {
memset ( & V_65 -> V_129 , 0 , sizeof( V_65 -> V_129 ) ) ;
memcpy ( & V_65 -> V_129 . V_131 , V_126 , sizeof( V_126 ) ) ;
V_65 -> V_129 . V_132 = V_133 ;
V_65 -> V_129 . V_134 = V_135 ;
V_2 -> V_130 = 0 ;
}
V_65 -> V_102 = 0x00 ;
return;
}
static void
F_12 ( T_1 * * V_103 , void * V_104 , T_2 * V_105 )
{
struct V_136 * V_9 ;
T_2 V_114 = * V_105 ;
int V_7 ;
T_1 * V_115 = * V_103 ;
struct V_3 * V_65 = V_104 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_137 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_138 ) ) {
V_9 = (struct V_136 * ) V_115 ;
V_9 -> V_115 . type = F_5 ( V_139 ) ;
V_9 -> V_115 . V_88 =
F_5 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_114 += sizeof( struct V_117 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_115 += sizeof( struct V_117 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_105 = V_114 ;
* V_103 = V_115 ;
return;
}
static int
F_13 ( T_1 * V_115 , void * V_104 , T_2 * V_105 )
{
struct V_140 * V_97 ;
struct V_141 * V_98 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_100 ;
struct V_149 * V_99 ;
struct V_150 * V_101 ;
struct V_151 * V_152 ;
struct V_153 * V_21 ;
struct V_154 * V_155 ;
struct V_156 * V_157 , * V_158 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
struct V_3 * V_65 = V_104 ;
int V_7 ;
T_2 V_114 = * V_105 ;
if ( V_65 -> V_143 . V_163 ) {
V_143 = (struct V_142 * ) V_115 ;
V_143 -> V_115 . type = F_5 ( V_164 ) ;
V_143 -> V_115 . V_88 = F_5 ( ( T_2 ) V_65 -> V_143 . V_163 ) ;
memcpy ( V_143 -> V_143 , V_65 -> V_143 . V_143 , V_65 -> V_143 . V_163 ) ;
V_114 += sizeof( struct V_117 ) +
V_65 -> V_143 . V_163 ;
V_115 += sizeof( struct V_117 ) + V_65 -> V_143 . V_163 ;
V_145 = (struct V_144 * ) V_115 ;
V_145 -> V_115 . type = F_5 ( V_165 ) ;
V_145 -> V_115 . V_88 =
F_5 ( sizeof( V_145 -> V_166 ) ) ;
V_145 -> V_166 = V_65 -> V_95 ;
V_114 += sizeof( struct V_144 ) ;
V_115 += sizeof( struct V_144 ) ;
}
if ( V_65 -> V_92 [ 0 ] ) {
V_155 = (struct V_154 * ) V_115 ;
V_155 -> V_115 . type = F_5 ( V_167 ) ;
for ( V_7 = 0 ; V_7 < V_168 && V_65 -> V_92 [ V_7 ] ;
V_7 ++ )
V_155 -> V_92 [ V_7 ] = V_65 -> V_92 [ V_7 ] ;
V_155 -> V_115 . V_88 = F_5 ( V_7 ) ;
V_114 += sizeof( struct V_154 ) + V_7 ;
V_115 += sizeof( struct V_154 ) + V_7 ;
}
if ( V_65 -> V_169 &&
( ( V_65 -> V_170 == V_171 &&
V_65 -> V_169 <= V_172 ) ||
( V_65 -> V_170 == V_173 &&
V_65 -> V_169 <= V_174 ) ) ) {
V_147 = (struct V_146 * ) V_115 ;
V_147 -> V_115 . type = F_5 ( V_175 ) ;
V_147 -> V_115 . V_88 =
F_5 ( sizeof( struct V_146 ) -
sizeof( struct V_117 ) ) ;
V_147 -> V_176 = V_65 -> V_170 ;
V_147 -> V_169 = V_65 -> V_169 ;
V_114 += sizeof( struct V_146 ) ;
V_115 += sizeof( struct V_146 ) ;
}
if ( V_65 -> V_98 >= V_177 &&
V_65 -> V_98 <= V_178 ) {
V_98 = (struct V_141 * ) V_115 ;
V_98 -> V_115 . type =
F_5 ( V_179 ) ;
V_98 -> V_115 . V_88 =
F_5 ( sizeof( struct V_141 ) -
sizeof( struct V_117 ) ) ;
V_98 -> V_180 = F_5 ( V_65 -> V_98 ) ;
V_114 += sizeof( struct V_141 ) ;
V_115 += sizeof( struct V_141 ) ;
}
if ( V_65 -> V_97 >= V_181 &&
V_65 -> V_97 <= V_182 ) {
V_97 = (struct V_140 * ) V_115 ;
V_97 -> V_115 . type = F_5 ( V_183 ) ;
V_97 -> V_115 . V_88 =
F_5 ( sizeof( struct V_140 ) -
sizeof( struct V_117 ) ) ;
V_97 -> V_180 = V_65 -> V_97 ;
V_114 += sizeof( struct V_140 ) ;
V_115 += sizeof( struct V_140 ) ;
}
if ( V_65 -> V_99 <= V_184 ) {
V_99 = (struct V_149 * ) V_115 ;
V_99 -> V_115 . type =
F_5 ( V_185 ) ;
V_99 -> V_115 . V_88 =
F_5 ( sizeof( struct V_149 ) -
sizeof( struct V_117 ) ) ;
V_99 -> V_186 = F_5 ( V_65 -> V_99 ) ;
V_114 += sizeof( struct V_148 ) ;
V_115 += sizeof( struct V_148 ) ;
}
if ( ( V_65 -> V_100 >= V_187 ) &&
( V_65 -> V_100 <= V_188 ) ) {
V_100 = (struct V_148 * ) V_115 ;
V_100 -> V_115 . type =
F_5 ( V_189 ) ;
V_100 -> V_115 . V_88 =
F_5 ( sizeof( struct V_148 ) -
sizeof( struct V_117 ) ) ;
V_100 -> V_190 = F_5 ( V_65 -> V_100 ) ;
V_114 += sizeof( struct V_148 ) ;
V_115 += sizeof( struct V_148 ) ;
}
if ( V_65 -> V_101 <= V_191 ) {
V_101 = (struct V_150 * ) V_115 ;
V_101 -> V_115 . type = F_5 ( V_192 ) ;
V_101 -> V_115 . V_88 =
F_5 ( sizeof( struct V_150 ) -
sizeof( struct V_117 ) ) ;
V_101 -> V_193 = ( T_1 ) V_65 -> V_101 ;
V_114 += sizeof( struct V_150 ) ;
V_115 += sizeof( struct V_150 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_194 ) )
F_9 ( & V_115 , V_104 , & V_114 ) ;
else
F_12 ( & V_115 , V_104 , & V_114 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_153 * ) V_115 ;
V_21 -> V_115 . type = F_5 ( V_195 ) ;
V_21 -> V_115 . V_88 =
F_5 ( sizeof( struct V_153 ) -
sizeof( struct V_117 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_114 += sizeof( struct V_153 ) ;
V_115 += sizeof( struct V_153 ) ;
}
if ( V_65 -> V_11 ) {
V_152 = (struct V_151 * ) V_115 ;
V_152 -> V_115 . type =
F_5 ( V_196 ) ;
V_152 -> V_115 . V_88 =
F_5 ( sizeof( struct V_151 )
- sizeof( struct V_117 ) ) ;
V_152 -> V_120 = F_5 ( V_65 -> V_11 ) ;
V_114 += sizeof( struct V_151 ) ;
V_115 += sizeof( struct V_151 ) ;
}
if ( V_65 -> V_73 . V_76 ) {
V_160 = (struct V_159 * ) V_115 ;
V_160 -> V_197 . type = F_5 ( V_69 ) ;
V_160 -> V_197 . V_88 =
F_5 ( sizeof( struct V_74 ) ) ;
V_160 -> V_73 . V_76 = V_65 -> V_73 . V_76 ;
V_160 -> V_73 . V_78 =
V_65 -> V_73 . V_78 ;
memcpy ( & V_160 -> V_73 . V_198 , & V_65 -> V_73 . V_198 ,
sizeof( struct V_199 ) ) ;
V_160 -> V_73 . V_200 =
V_65 -> V_73 . V_200 ;
V_160 -> V_73 . V_201 = V_65 -> V_73 . V_201 ;
V_160 -> V_73 . V_202 =
V_65 -> V_73 . V_202 ;
V_114 += sizeof( struct V_159 ) ;
V_115 += sizeof( struct V_159 ) ;
}
if ( V_65 -> V_129 . V_102 != 0xFF ) {
V_162 = (struct V_161 * ) V_115 ;
V_162 -> V_197 . type = F_5 ( V_203 ) ;
V_162 -> V_197 . V_88 = F_5 ( sizeof( V_162 -> V_129 ) ) ;
memcpy ( & V_162 -> V_129 , & V_65 -> V_129 ,
sizeof( V_162 -> V_129 ) ) ;
V_114 += sizeof( struct V_161 ) ;
V_115 += sizeof( struct V_161 ) ;
}
if ( V_65 -> V_204 ) {
V_157 = (struct V_156 * ) V_115 ;
V_157 -> V_115 . type = F_5 ( V_205 ) ;
V_157 -> V_115 . V_88 = F_5 ( sizeof( * V_157 ) -
sizeof( struct V_117 ) ) ;
V_157 -> V_204 = F_14 ( V_65 -> V_204 ) ;
V_114 += sizeof( * V_157 ) ;
V_115 += sizeof( * V_157 ) ;
}
if ( V_65 -> V_206 ) {
V_158 = (struct V_156 * ) V_115 ;
V_158 -> V_115 . type = F_5 ( V_207 ) ;
V_158 -> V_115 . V_88 = F_5 ( sizeof( * V_158 ) -
sizeof( struct V_117 ) ) ;
V_158 -> V_204 =
F_14 ( V_65 -> V_206 ) ;
V_114 += sizeof( * V_158 ) ;
V_115 += sizeof( * V_158 ) ;
}
* V_105 = V_114 ;
return 0 ;
}
static int F_15 ( T_1 * V_115 , void * V_104 , T_2 * V_208 )
{
struct V_209 * V_210 = V_104 ;
struct V_117 * V_211 = (struct V_117 * ) V_115 ;
if ( ! V_210 || ! V_210 -> V_88 || ! V_210 -> V_212 )
return - 1 ;
* V_208 += F_16 ( V_210 -> V_88 ) + sizeof( struct V_117 ) ;
V_211 -> type = F_5 ( V_213 ) ;
V_211 -> V_88 = V_210 -> V_88 ;
V_115 += sizeof( struct V_117 ) ;
memcpy ( V_115 , V_210 -> V_212 , F_16 ( V_210 -> V_88 ) ) ;
return 0 ;
}
static int
F_17 ( struct V_214 * V_215 , T_2 V_216 ,
T_3 type , void * V_104 )
{
T_1 * V_115 ;
T_2 V_114 , V_105 , V_208 ;
struct V_217 * V_218 ;
V_215 -> V_219 = F_5 ( V_220 ) ;
V_114 = ( T_2 ) ( sizeof( struct V_217 ) + V_221 ) ;
V_218 = (struct V_217 * ) & V_215 -> V_6 . V_222 ;
V_218 -> V_223 = F_5 ( V_216 ) ;
V_115 = V_218 -> V_115 ;
switch ( type ) {
case V_224 :
V_105 = V_114 ;
if ( F_13 ( V_115 , V_104 , & V_105 ) )
return - 1 ;
V_215 -> V_225 = F_5 ( V_105 ) ;
break;
case V_226 :
V_208 = V_114 ;
if ( F_15 ( V_115 , V_104 , & V_208 ) )
return - 1 ;
V_215 -> V_225 = F_5 ( V_208 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
int F_18 ( struct V_1 * V_2 , T_2 V_227 ,
T_2 V_216 , T_3 type ,
void * V_228 , void * V_104 )
{
struct V_214 * V_215 = V_104 ;
switch ( V_227 ) {
case V_220 :
if ( F_17 ( V_215 , V_216 , type , V_228 ) )
return - 1 ;
break;
case V_229 :
case V_230 :
V_215 -> V_219 = F_5 ( V_227 ) ;
V_215 -> V_225 = F_5 ( V_221 ) ;
break;
default:
F_19 ( V_2 -> V_67 -> V_231 ,
L_1 , V_227 ) ;
return - 1 ;
}
return 0 ;
}
