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
V_81 = ( void * ) F_4 ( V_90 , V_86 , V_88 ) ;
if ( V_81 )
memcpy ( V_65 -> V_91 , V_81 + 1 , V_81 -> V_88 ) ;
return;
}
void F_8 ( struct V_3 * V_92 )
{
V_92 -> V_93 = 0x7F ;
V_92 -> V_94 = 0x7F ;
V_92 -> V_95 = 0x7F ;
V_92 -> V_96 = 0x7FFF ;
V_92 -> V_23 = 0x7F ;
V_92 -> V_97 = 0x7FFF ;
V_92 -> V_98 = 0x7FFF ;
V_92 -> V_99 = 0x7F ;
}
static void
F_9 ( T_1 * * V_100 , void * V_101 , T_2 * V_102 )
{
struct V_103 * V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_3 * V_65 = V_101 ;
T_2 V_111 = * V_102 ;
T_1 * V_112 = * V_100 ;
V_110 = (struct V_109 * ) V_112 ;
V_110 -> V_112 . type = F_5 ( V_113 ) ;
V_110 -> V_112 . V_88 = F_5 ( sizeof( struct V_109 ) -
sizeof( struct V_114 ) ) ;
V_110 -> V_30 = F_5 ( V_65 -> V_30 ) ;
V_110 -> V_13 = F_5 ( V_65 -> V_13 ) ;
V_111 += sizeof( struct V_109 ) ;
V_112 += sizeof( struct V_109 ) ;
if ( V_65 -> V_15 . V_49 & V_115 ) {
V_104 = (struct V_103 * ) V_112 ;
V_104 -> V_112 . type = F_5 ( V_116 ) ;
V_104 -> V_112 . V_88 =
F_5 ( sizeof( struct V_103 ) -
sizeof( struct V_114 ) ) ;
V_104 -> V_117 = F_5 ( V_38 ) ;
V_104 -> V_118 = V_65 -> V_15 . V_49 ;
V_111 += sizeof( struct V_103 ) ;
V_112 += sizeof( struct V_103 ) ;
}
if ( V_65 -> V_15 . V_51 & V_115 ) {
V_104 = (struct V_103 * ) V_112 ;
V_104 -> V_112 . type = F_5 ( V_116 ) ;
V_104 -> V_112 . V_88 =
F_5 ( sizeof( struct V_103 ) -
sizeof( struct V_114 ) ) ;
V_104 -> V_117 = F_5 ( V_41 ) ;
V_104 -> V_118 = V_65 -> V_15 . V_51 ;
V_111 += sizeof( struct V_103 ) ;
V_112 += sizeof( struct V_103 ) ;
}
if ( V_65 -> V_15 . V_64 & V_115 ) {
V_106 = (struct V_105 * ) V_112 ;
V_106 -> V_112 . type = F_5 ( V_119 ) ;
V_106 -> V_112 . V_88 =
F_5 ( sizeof( struct V_105 ) -
sizeof( struct V_114 ) ) ;
V_106 -> V_118 = V_65 -> V_15 . V_64 ;
V_111 += sizeof( struct V_105 ) ;
V_112 += sizeof( struct V_105 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_108 = (struct V_107 * ) V_112 ;
V_108 -> V_112 . type = F_5 ( V_120 ) ;
V_108 -> V_112 . V_88 = F_5 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_108 -> V_108 , V_65 -> V_15 . V_108 ,
V_65 -> V_15 . V_16 ) ;
V_111 += sizeof( struct V_114 ) +
V_65 -> V_15 . V_16 ;
V_112 += sizeof( struct V_114 ) + V_65 -> V_15 . V_16 ;
}
* V_102 = V_111 ;
* V_100 = V_112 ;
return;
}
static void
F_10 ( T_1 * * V_100 , void * V_101 , T_2 * V_102 )
{
struct V_121 * V_9 ;
T_2 V_111 = * V_102 ;
int V_7 ;
T_1 * V_112 = * V_100 ;
struct V_3 * V_65 = V_101 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_122 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_123 ) ) {
V_9 = (struct V_121 * ) V_112 ;
V_9 -> V_112 . type = F_5 ( V_124 ) ;
V_9 -> V_112 . V_88 =
F_5 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_111 += sizeof( struct V_114 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_112 += sizeof( struct V_114 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_102 = V_111 ;
* V_100 = V_112 ;
return;
}
static int
F_11 ( T_1 * V_112 , void * V_101 , T_2 * V_102 )
{
struct V_125 * V_95 ;
struct V_126 * V_96 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_98 ;
struct V_134 * V_97 ;
struct V_135 * V_99 ;
struct V_136 * V_137 ;
struct V_138 * V_21 ;
struct V_139 * V_140 ;
struct V_141 * V_142 , * V_143 ;
struct V_144 * V_145 ;
struct V_3 * V_65 = V_101 ;
int V_7 ;
T_2 V_111 = * V_102 ;
if ( V_65 -> V_128 . V_146 ) {
V_128 = (struct V_127 * ) V_112 ;
V_128 -> V_112 . type = F_5 ( V_147 ) ;
V_128 -> V_112 . V_88 = F_5 ( ( T_2 ) V_65 -> V_128 . V_146 ) ;
memcpy ( V_128 -> V_128 , V_65 -> V_128 . V_128 , V_65 -> V_128 . V_146 ) ;
V_111 += sizeof( struct V_114 ) +
V_65 -> V_128 . V_146 ;
V_112 += sizeof( struct V_114 ) + V_65 -> V_128 . V_146 ;
V_130 = (struct V_129 * ) V_112 ;
V_130 -> V_112 . type = F_5 ( V_148 ) ;
V_130 -> V_112 . V_88 =
F_5 ( sizeof( V_130 -> V_149 ) ) ;
V_130 -> V_149 = V_65 -> V_93 ;
V_111 += sizeof( struct V_129 ) ;
V_112 += sizeof( struct V_129 ) ;
}
if ( V_65 -> V_91 [ 0 ] ) {
V_140 = (struct V_139 * ) V_112 ;
V_140 -> V_112 . type = F_5 ( V_150 ) ;
for ( V_7 = 0 ; V_7 < V_151 && V_65 -> V_91 [ V_7 ] ;
V_7 ++ )
V_140 -> V_91 [ V_7 ] = V_65 -> V_91 [ V_7 ] ;
V_140 -> V_112 . V_88 = F_5 ( V_7 ) ;
V_111 += sizeof( struct V_139 ) + V_7 ;
V_112 += sizeof( struct V_139 ) + V_7 ;
}
if ( V_65 -> V_152 &&
( ( V_65 -> V_153 == V_154 &&
V_65 -> V_152 <= V_155 ) ||
( V_65 -> V_153 == V_156 &&
V_65 -> V_152 <= V_157 ) ) ) {
V_132 = (struct V_131 * ) V_112 ;
V_132 -> V_112 . type = F_5 ( V_158 ) ;
V_132 -> V_112 . V_88 =
F_5 ( sizeof( struct V_131 ) -
sizeof( struct V_114 ) ) ;
V_132 -> V_159 = V_65 -> V_153 ;
V_132 -> V_152 = V_65 -> V_152 ;
V_111 += sizeof( struct V_131 ) ;
V_112 += sizeof( struct V_131 ) ;
}
if ( V_65 -> V_96 >= V_160 &&
V_65 -> V_96 <= V_161 ) {
V_96 = (struct V_126 * ) V_112 ;
V_96 -> V_112 . type =
F_5 ( V_162 ) ;
V_96 -> V_112 . V_88 =
F_5 ( sizeof( struct V_126 ) -
sizeof( struct V_114 ) ) ;
V_96 -> V_163 = F_5 ( V_65 -> V_96 ) ;
V_111 += sizeof( struct V_126 ) ;
V_112 += sizeof( struct V_126 ) ;
}
if ( V_65 -> V_95 >= V_164 &&
V_65 -> V_95 <= V_165 ) {
V_95 = (struct V_125 * ) V_112 ;
V_95 -> V_112 . type = F_5 ( V_166 ) ;
V_95 -> V_112 . V_88 =
F_5 ( sizeof( struct V_125 ) -
sizeof( struct V_114 ) ) ;
V_95 -> V_163 = V_65 -> V_95 ;
V_111 += sizeof( struct V_125 ) ;
V_112 += sizeof( struct V_125 ) ;
}
if ( V_65 -> V_97 <= V_167 ) {
V_97 = (struct V_134 * ) V_112 ;
V_97 -> V_112 . type =
F_5 ( V_168 ) ;
V_97 -> V_112 . V_88 =
F_5 ( sizeof( struct V_134 ) -
sizeof( struct V_114 ) ) ;
V_97 -> V_169 = F_5 ( V_65 -> V_97 ) ;
V_111 += sizeof( struct V_133 ) ;
V_112 += sizeof( struct V_133 ) ;
}
if ( ( V_65 -> V_98 >= V_170 ) &&
( V_65 -> V_98 <= V_171 ) ) {
V_98 = (struct V_133 * ) V_112 ;
V_98 -> V_112 . type =
F_5 ( V_172 ) ;
V_98 -> V_112 . V_88 =
F_5 ( sizeof( struct V_133 ) -
sizeof( struct V_114 ) ) ;
V_98 -> V_173 = F_5 ( V_65 -> V_98 ) ;
V_111 += sizeof( struct V_133 ) ;
V_112 += sizeof( struct V_133 ) ;
}
if ( V_65 -> V_99 <= V_174 ) {
V_99 = (struct V_135 * ) V_112 ;
V_99 -> V_112 . type = F_5 ( V_175 ) ;
V_99 -> V_112 . V_88 =
F_5 ( sizeof( struct V_135 ) -
sizeof( struct V_114 ) ) ;
V_99 -> V_176 = ( T_1 ) V_65 -> V_99 ;
V_111 += sizeof( struct V_135 ) ;
V_112 += sizeof( struct V_135 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_177 ) )
F_9 ( & V_112 , V_101 , & V_111 ) ;
else
F_10 ( & V_112 , V_101 , & V_111 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_138 * ) V_112 ;
V_21 -> V_112 . type = F_5 ( V_178 ) ;
V_21 -> V_112 . V_88 =
F_5 ( sizeof( struct V_138 ) -
sizeof( struct V_114 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_111 += sizeof( struct V_138 ) ;
V_112 += sizeof( struct V_138 ) ;
}
if ( V_65 -> V_11 ) {
V_137 = (struct V_136 * ) V_112 ;
V_137 -> V_112 . type =
F_5 ( V_179 ) ;
V_137 -> V_112 . V_88 =
F_5 ( sizeof( struct V_136 )
- sizeof( struct V_114 ) ) ;
V_137 -> V_117 = F_5 ( V_65 -> V_11 ) ;
V_111 += sizeof( struct V_136 ) ;
V_112 += sizeof( struct V_136 ) ;
}
if ( V_65 -> V_73 . V_76 ) {
V_145 = (struct V_144 * ) V_112 ;
V_145 -> V_180 . type = F_5 ( V_69 ) ;
V_145 -> V_180 . V_88 =
F_5 ( sizeof( struct V_74 ) ) ;
V_145 -> V_73 . V_76 = V_65 -> V_73 . V_76 ;
V_145 -> V_73 . V_78 =
V_65 -> V_73 . V_78 ;
memcpy ( & V_145 -> V_73 . V_181 , & V_65 -> V_73 . V_181 ,
sizeof( struct V_182 ) ) ;
V_145 -> V_73 . V_183 =
V_65 -> V_73 . V_183 ;
V_145 -> V_73 . V_184 = V_65 -> V_73 . V_184 ;
V_145 -> V_73 . V_185 =
V_65 -> V_73 . V_185 ;
V_111 += sizeof( struct V_144 ) ;
V_112 += sizeof( struct V_144 ) ;
}
if ( V_65 -> V_186 ) {
V_142 = (struct V_141 * ) V_112 ;
V_142 -> V_112 . type = F_5 ( V_187 ) ;
V_142 -> V_112 . V_88 = F_5 ( sizeof( * V_142 ) -
sizeof( struct V_114 ) ) ;
V_142 -> V_186 = F_12 ( V_65 -> V_186 ) ;
V_111 += sizeof( * V_142 ) ;
V_112 += sizeof( * V_142 ) ;
}
if ( V_65 -> V_188 ) {
V_143 = (struct V_141 * ) V_112 ;
V_143 -> V_112 . type = F_5 ( V_189 ) ;
V_143 -> V_112 . V_88 = F_5 ( sizeof( * V_143 ) -
sizeof( struct V_114 ) ) ;
V_143 -> V_186 =
F_12 ( V_65 -> V_188 ) ;
V_111 += sizeof( * V_143 ) ;
V_112 += sizeof( * V_143 ) ;
}
* V_102 = V_111 ;
return 0 ;
}
static int F_13 ( T_1 * V_112 , void * V_101 , T_2 * V_190 )
{
struct V_191 * V_192 = V_101 ;
struct V_114 * V_193 = (struct V_114 * ) V_112 ;
if ( ! V_192 || ! V_192 -> V_88 || ! V_192 -> V_194 )
return - 1 ;
* V_190 += F_14 ( V_192 -> V_88 ) + sizeof( struct V_114 ) ;
V_193 -> type = F_5 ( V_195 ) ;
V_193 -> V_88 = V_192 -> V_88 ;
V_112 += sizeof( struct V_114 ) ;
memcpy ( V_112 , V_192 -> V_194 , F_14 ( V_192 -> V_88 ) ) ;
return 0 ;
}
static int
F_15 ( struct V_196 * V_197 , T_2 V_198 ,
T_3 type , void * V_101 )
{
T_1 * V_112 ;
T_2 V_111 , V_102 , V_190 ;
struct V_199 * V_200 ;
V_197 -> V_201 = F_5 ( V_202 ) ;
V_111 = ( T_2 ) ( sizeof( struct V_199 ) + V_203 ) ;
V_200 = (struct V_199 * ) & V_197 -> V_6 . V_204 ;
V_200 -> V_205 = F_5 ( V_198 ) ;
V_112 = V_200 -> V_112 ;
switch ( type ) {
case V_206 :
V_102 = V_111 ;
if ( F_11 ( V_112 , V_101 , & V_102 ) )
return - 1 ;
V_197 -> V_207 = F_5 ( V_102 ) ;
break;
case V_208 :
V_190 = V_111 ;
if ( F_13 ( V_112 , V_101 , & V_190 ) )
return - 1 ;
V_197 -> V_207 = F_5 ( V_190 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_209 ,
T_2 V_198 , T_3 type ,
void * V_210 , void * V_101 )
{
struct V_196 * V_197 = V_101 ;
switch ( V_209 ) {
case V_202 :
if ( F_15 ( V_197 , V_198 , type , V_210 ) )
return - 1 ;
break;
case V_211 :
case V_212 :
V_197 -> V_201 = F_5 ( V_209 ) ;
V_197 -> V_207 = F_5 ( V_203 ) ;
break;
default:
F_17 ( V_2 -> V_67 -> V_213 ,
L_1 , V_209 ) ;
return - 1 ;
}
return 0 ;
}
