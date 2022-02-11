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
}
static void
F_9 ( T_1 * * V_102 , void * V_103 , T_2 * V_104 )
{
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
struct V_111 * V_112 ;
struct V_3 * V_65 = V_103 ;
T_2 V_113 = * V_104 ;
T_1 * V_114 = * V_102 ;
V_112 = (struct V_111 * ) V_114 ;
V_112 -> V_114 . type = F_5 ( V_115 ) ;
V_112 -> V_114 . V_88 = F_5 ( sizeof( struct V_111 ) -
sizeof( struct V_116 ) ) ;
V_112 -> V_30 = F_5 ( V_65 -> V_30 ) ;
V_112 -> V_13 = F_5 ( V_65 -> V_13 ) ;
V_113 += sizeof( struct V_111 ) ;
V_114 += sizeof( struct V_111 ) ;
if ( V_65 -> V_15 . V_49 & V_117 ) {
V_106 = (struct V_105 * ) V_114 ;
V_106 -> V_114 . type = F_5 ( V_118 ) ;
V_106 -> V_114 . V_88 =
F_5 ( sizeof( struct V_105 ) -
sizeof( struct V_116 ) ) ;
V_106 -> V_119 = F_5 ( V_38 ) ;
V_106 -> V_120 = V_65 -> V_15 . V_49 ;
V_113 += sizeof( struct V_105 ) ;
V_114 += sizeof( struct V_105 ) ;
}
if ( V_65 -> V_15 . V_51 & V_117 ) {
V_106 = (struct V_105 * ) V_114 ;
V_106 -> V_114 . type = F_5 ( V_118 ) ;
V_106 -> V_114 . V_88 =
F_5 ( sizeof( struct V_105 ) -
sizeof( struct V_116 ) ) ;
V_106 -> V_119 = F_5 ( V_41 ) ;
V_106 -> V_120 = V_65 -> V_15 . V_51 ;
V_113 += sizeof( struct V_105 ) ;
V_114 += sizeof( struct V_105 ) ;
}
if ( V_65 -> V_15 . V_64 & V_117 ) {
V_108 = (struct V_107 * ) V_114 ;
V_108 -> V_114 . type = F_5 ( V_121 ) ;
V_108 -> V_114 . V_88 =
F_5 ( sizeof( struct V_107 ) -
sizeof( struct V_116 ) ) ;
V_108 -> V_120 = V_65 -> V_15 . V_64 ;
V_113 += sizeof( struct V_107 ) ;
V_114 += sizeof( struct V_107 ) ;
}
if ( V_65 -> V_15 . V_16 ) {
V_110 = (struct V_109 * ) V_114 ;
V_110 -> V_114 . type = F_5 ( V_122 ) ;
V_110 -> V_114 . V_88 = F_5 ( V_65 -> V_15 . V_16 ) ;
memcpy ( V_110 -> V_110 , V_65 -> V_15 . V_110 ,
V_65 -> V_15 . V_16 ) ;
V_113 += sizeof( struct V_116 ) +
V_65 -> V_15 . V_16 ;
V_114 += sizeof( struct V_116 ) + V_65 -> V_15 . V_16 ;
}
* V_104 = V_113 ;
* V_102 = V_114 ;
return;
}
static void
F_10 ( T_1 * * V_102 , void * V_103 , T_2 * V_104 )
{
struct V_123 * V_9 ;
T_2 V_113 = * V_104 ;
int V_7 ;
T_1 * V_114 = * V_102 ;
struct V_3 * V_65 = V_103 ;
for ( V_7 = 0 ; V_7 < V_56 ; V_7 ++ ) {
if ( V_65 -> V_57 [ V_7 ] . V_16 &&
( V_65 -> V_57 [ V_7 ] . V_16 == V_124 ||
V_65 -> V_57 [ V_7 ] . V_16 == V_125 ) ) {
V_9 = (struct V_123 * ) V_114 ;
V_9 -> V_114 . type = F_5 ( V_126 ) ;
V_9 -> V_114 . V_88 =
F_5 ( V_65 -> V_57 [ V_7 ] . V_16 + 2 ) ;
V_9 -> V_58 = V_65 -> V_57 [ V_7 ] . V_58 ;
V_9 -> V_60 = V_65 -> V_57 [ V_7 ] . V_60 ;
memcpy ( V_9 -> V_62 , V_65 -> V_57 [ V_7 ] . V_62 ,
V_65 -> V_57 [ V_7 ] . V_16 ) ;
V_113 += sizeof( struct V_116 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
V_114 += sizeof( struct V_116 ) + 2 +
V_65 -> V_57 [ V_7 ] . V_16 ;
}
}
* V_104 = V_113 ;
* V_102 = V_114 ;
return;
}
static int
F_11 ( T_1 * V_114 , void * V_103 , T_2 * V_104 )
{
struct V_127 * V_97 ;
struct V_128 * V_98 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_135 * V_100 ;
struct V_136 * V_99 ;
struct V_137 * V_101 ;
struct V_138 * V_139 ;
struct V_140 * V_21 ;
struct V_141 * V_142 ;
struct V_143 * V_144 , * V_145 ;
struct V_146 * V_147 ;
struct V_3 * V_65 = V_103 ;
int V_7 ;
T_2 V_113 = * V_104 ;
if ( V_65 -> V_130 . V_148 ) {
V_130 = (struct V_129 * ) V_114 ;
V_130 -> V_114 . type = F_5 ( V_149 ) ;
V_130 -> V_114 . V_88 = F_5 ( ( T_2 ) V_65 -> V_130 . V_148 ) ;
memcpy ( V_130 -> V_130 , V_65 -> V_130 . V_130 , V_65 -> V_130 . V_148 ) ;
V_113 += sizeof( struct V_116 ) +
V_65 -> V_130 . V_148 ;
V_114 += sizeof( struct V_116 ) + V_65 -> V_130 . V_148 ;
V_132 = (struct V_131 * ) V_114 ;
V_132 -> V_114 . type = F_5 ( V_150 ) ;
V_132 -> V_114 . V_88 =
F_5 ( sizeof( V_132 -> V_151 ) ) ;
V_132 -> V_151 = V_65 -> V_95 ;
V_113 += sizeof( struct V_131 ) ;
V_114 += sizeof( struct V_131 ) ;
}
if ( V_65 -> V_92 [ 0 ] ) {
V_142 = (struct V_141 * ) V_114 ;
V_142 -> V_114 . type = F_5 ( V_152 ) ;
for ( V_7 = 0 ; V_7 < V_153 && V_65 -> V_92 [ V_7 ] ;
V_7 ++ )
V_142 -> V_92 [ V_7 ] = V_65 -> V_92 [ V_7 ] ;
V_142 -> V_114 . V_88 = F_5 ( V_7 ) ;
V_113 += sizeof( struct V_141 ) + V_7 ;
V_114 += sizeof( struct V_141 ) + V_7 ;
}
if ( V_65 -> V_154 &&
( ( V_65 -> V_155 == V_156 &&
V_65 -> V_154 <= V_157 ) ||
( V_65 -> V_155 == V_158 &&
V_65 -> V_154 <= V_159 ) ) ) {
V_134 = (struct V_133 * ) V_114 ;
V_134 -> V_114 . type = F_5 ( V_160 ) ;
V_134 -> V_114 . V_88 =
F_5 ( sizeof( struct V_133 ) -
sizeof( struct V_116 ) ) ;
V_134 -> V_161 = V_65 -> V_155 ;
V_134 -> V_154 = V_65 -> V_154 ;
V_113 += sizeof( struct V_133 ) ;
V_114 += sizeof( struct V_133 ) ;
}
if ( V_65 -> V_98 >= V_162 &&
V_65 -> V_98 <= V_163 ) {
V_98 = (struct V_128 * ) V_114 ;
V_98 -> V_114 . type =
F_5 ( V_164 ) ;
V_98 -> V_114 . V_88 =
F_5 ( sizeof( struct V_128 ) -
sizeof( struct V_116 ) ) ;
V_98 -> V_165 = F_5 ( V_65 -> V_98 ) ;
V_113 += sizeof( struct V_128 ) ;
V_114 += sizeof( struct V_128 ) ;
}
if ( V_65 -> V_97 >= V_166 &&
V_65 -> V_97 <= V_167 ) {
V_97 = (struct V_127 * ) V_114 ;
V_97 -> V_114 . type = F_5 ( V_168 ) ;
V_97 -> V_114 . V_88 =
F_5 ( sizeof( struct V_127 ) -
sizeof( struct V_116 ) ) ;
V_97 -> V_165 = V_65 -> V_97 ;
V_113 += sizeof( struct V_127 ) ;
V_114 += sizeof( struct V_127 ) ;
}
if ( V_65 -> V_99 <= V_169 ) {
V_99 = (struct V_136 * ) V_114 ;
V_99 -> V_114 . type =
F_5 ( V_170 ) ;
V_99 -> V_114 . V_88 =
F_5 ( sizeof( struct V_136 ) -
sizeof( struct V_116 ) ) ;
V_99 -> V_171 = F_5 ( V_65 -> V_99 ) ;
V_113 += sizeof( struct V_135 ) ;
V_114 += sizeof( struct V_135 ) ;
}
if ( ( V_65 -> V_100 >= V_172 ) &&
( V_65 -> V_100 <= V_173 ) ) {
V_100 = (struct V_135 * ) V_114 ;
V_100 -> V_114 . type =
F_5 ( V_174 ) ;
V_100 -> V_114 . V_88 =
F_5 ( sizeof( struct V_135 ) -
sizeof( struct V_116 ) ) ;
V_100 -> V_175 = F_5 ( V_65 -> V_100 ) ;
V_113 += sizeof( struct V_135 ) ;
V_114 += sizeof( struct V_135 ) ;
}
if ( V_65 -> V_101 <= V_176 ) {
V_101 = (struct V_137 * ) V_114 ;
V_101 -> V_114 . type = F_5 ( V_177 ) ;
V_101 -> V_114 . V_88 =
F_5 ( sizeof( struct V_137 ) -
sizeof( struct V_116 ) ) ;
V_101 -> V_178 = ( T_1 ) V_65 -> V_101 ;
V_113 += sizeof( struct V_137 ) ;
V_114 += sizeof( struct V_137 ) ;
}
if ( ( V_65 -> V_11 & V_38 ) ||
( V_65 -> V_11 & V_41 ) ||
( V_65 -> V_11 & V_179 ) )
F_9 ( & V_114 , V_103 , & V_113 ) ;
else
F_10 ( & V_114 , V_103 , & V_113 ) ;
if ( ( V_65 -> V_23 <= V_26 ) ||
( V_65 -> V_23 == V_29 ) ) {
V_21 = (struct V_140 * ) V_114 ;
V_21 -> V_114 . type = F_5 ( V_180 ) ;
V_21 -> V_114 . V_88 =
F_5 ( sizeof( struct V_140 ) -
sizeof( struct V_116 ) ) ;
V_21 -> V_21 = ( T_1 ) V_65 -> V_23 ;
V_113 += sizeof( struct V_140 ) ;
V_114 += sizeof( struct V_140 ) ;
}
if ( V_65 -> V_11 ) {
V_139 = (struct V_138 * ) V_114 ;
V_139 -> V_114 . type =
F_5 ( V_181 ) ;
V_139 -> V_114 . V_88 =
F_5 ( sizeof( struct V_138 )
- sizeof( struct V_116 ) ) ;
V_139 -> V_119 = F_5 ( V_65 -> V_11 ) ;
V_113 += sizeof( struct V_138 ) ;
V_114 += sizeof( struct V_138 ) ;
}
if ( V_65 -> V_73 . V_76 ) {
V_147 = (struct V_146 * ) V_114 ;
V_147 -> V_182 . type = F_5 ( V_69 ) ;
V_147 -> V_182 . V_88 =
F_5 ( sizeof( struct V_74 ) ) ;
V_147 -> V_73 . V_76 = V_65 -> V_73 . V_76 ;
V_147 -> V_73 . V_78 =
V_65 -> V_73 . V_78 ;
memcpy ( & V_147 -> V_73 . V_183 , & V_65 -> V_73 . V_183 ,
sizeof( struct V_184 ) ) ;
V_147 -> V_73 . V_185 =
V_65 -> V_73 . V_185 ;
V_147 -> V_73 . V_186 = V_65 -> V_73 . V_186 ;
V_147 -> V_73 . V_187 =
V_65 -> V_73 . V_187 ;
V_113 += sizeof( struct V_146 ) ;
V_114 += sizeof( struct V_146 ) ;
}
if ( V_65 -> V_188 ) {
V_144 = (struct V_143 * ) V_114 ;
V_144 -> V_114 . type = F_5 ( V_189 ) ;
V_144 -> V_114 . V_88 = F_5 ( sizeof( * V_144 ) -
sizeof( struct V_116 ) ) ;
V_144 -> V_188 = F_12 ( V_65 -> V_188 ) ;
V_113 += sizeof( * V_144 ) ;
V_114 += sizeof( * V_144 ) ;
}
if ( V_65 -> V_190 ) {
V_145 = (struct V_143 * ) V_114 ;
V_145 -> V_114 . type = F_5 ( V_191 ) ;
V_145 -> V_114 . V_88 = F_5 ( sizeof( * V_145 ) -
sizeof( struct V_116 ) ) ;
V_145 -> V_188 =
F_12 ( V_65 -> V_190 ) ;
V_113 += sizeof( * V_145 ) ;
V_114 += sizeof( * V_145 ) ;
}
* V_104 = V_113 ;
return 0 ;
}
static int F_13 ( T_1 * V_114 , void * V_103 , T_2 * V_192 )
{
struct V_193 * V_194 = V_103 ;
struct V_116 * V_195 = (struct V_116 * ) V_114 ;
if ( ! V_194 || ! V_194 -> V_88 || ! V_194 -> V_196 )
return - 1 ;
* V_192 += F_14 ( V_194 -> V_88 ) + sizeof( struct V_116 ) ;
V_195 -> type = F_5 ( V_197 ) ;
V_195 -> V_88 = V_194 -> V_88 ;
V_114 += sizeof( struct V_116 ) ;
memcpy ( V_114 , V_194 -> V_196 , F_14 ( V_194 -> V_88 ) ) ;
return 0 ;
}
static int
F_15 ( struct V_198 * V_199 , T_2 V_200 ,
T_3 type , void * V_103 )
{
T_1 * V_114 ;
T_2 V_113 , V_104 , V_192 ;
struct V_201 * V_202 ;
V_199 -> V_203 = F_5 ( V_204 ) ;
V_113 = ( T_2 ) ( sizeof( struct V_201 ) + V_205 ) ;
V_202 = (struct V_201 * ) & V_199 -> V_6 . V_206 ;
V_202 -> V_207 = F_5 ( V_200 ) ;
V_114 = V_202 -> V_114 ;
switch ( type ) {
case V_208 :
V_104 = V_113 ;
if ( F_11 ( V_114 , V_103 , & V_104 ) )
return - 1 ;
V_199 -> V_209 = F_5 ( V_104 ) ;
break;
case V_210 :
V_192 = V_113 ;
if ( F_13 ( V_114 , V_103 , & V_192 ) )
return - 1 ;
V_199 -> V_209 = F_5 ( V_192 ) ;
break;
default:
return - 1 ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_2 , T_2 V_211 ,
T_2 V_200 , T_3 type ,
void * V_212 , void * V_103 )
{
struct V_198 * V_199 = V_103 ;
switch ( V_211 ) {
case V_204 :
if ( F_15 ( V_199 , V_200 , type , V_212 ) )
return - 1 ;
break;
case V_213 :
case V_214 :
V_199 -> V_203 = F_5 ( V_211 ) ;
V_199 -> V_209 = F_5 ( V_205 ) ;
break;
default:
F_17 ( V_2 -> V_67 -> V_215 ,
L_1 , V_211 ) ;
return - 1 ;
}
return 0 ;
}
