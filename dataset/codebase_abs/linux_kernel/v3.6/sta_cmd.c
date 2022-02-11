static int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_7 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_9 ) +
V_10 ) ;
V_4 -> V_11 . V_12 . V_13 = F_2 ( V_5 ) ;
V_4 -> V_11 . V_12 . V_14 = F_2 ( V_2 -> V_15 ) ;
V_4 -> V_11 . V_12 . V_16 = F_2 ( V_2 -> V_17 ) ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_13 )
{
struct V_26 * V_27 = & V_4 -> V_11 . V_27 ;
if ( V_5 != V_28 ) {
F_4 ( V_2 -> V_29 -> V_30 ,
L_1 ) ;
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_31 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_26 ) + V_10 ) ;
V_27 -> V_13 = F_2 ( * V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_32 ,
T_1 * V_33 )
{
struct V_34 * V_35 = & V_4 -> V_11 . V_36 ;
F_6 ( V_2 -> V_29 -> V_30 , L_2 , V_32 ) ;
V_4 -> V_6 = F_2 ( V_37 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_34 )
- 1 + V_10 ) ;
V_35 -> V_38 = F_2 ( ( T_1 ) V_32 ) ;
if ( V_5 == V_39 ) {
V_35 -> V_40 = F_2 ( V_39 ) ;
V_35 -> V_41 = F_2 ( V_42 ) ;
F_7 ( & V_4 -> V_8 , V_42 ) ;
} else if ( V_5 == V_28 ) {
V_35 -> V_40 = F_2 ( V_28 ) ;
V_35 -> V_41 = F_2 ( sizeof( T_1 ) ) ;
* ( ( V_43 * ) ( V_35 -> V_44 ) ) = F_2 ( * V_33 ) ;
F_7 ( & V_4 -> V_8 , sizeof( T_1 ) ) ;
}
F_6 ( V_2 -> V_29 -> V_30 ,
L_3
L_4 ,
V_5 , V_32 , F_8 ( V_35 -> V_41 ) ,
F_8 ( * ( V_43 * ) V_35 -> V_44 ) ) ;
return 0 ;
}
static int
F_9 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_45 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_46 ) +
V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_47 )
{
struct V_48 * V_49 = & V_4 -> V_11 . V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
T_2 V_55 ;
V_4 -> V_6 = F_2 ( V_56 ) ;
V_49 -> V_13 = F_2 ( V_5 ) ;
V_49 -> V_57 = 0 ;
V_52 = (struct V_51 * ) ( ( V_58 * ) V_49 +
sizeof( struct V_48 ) ) ;
V_52 -> type = F_2 ( V_59 ) ;
V_52 -> V_60 = F_2
( sizeof( * V_52 ) - sizeof( struct V_61 ) ) ;
if ( V_47 != NULL ) {
V_52 -> V_62 = F_2 ( V_47 [ 0 ] ) ;
V_52 -> V_63 = F_2 ( V_47 [ 1 ] ) ;
for ( V_55 = 0 ;
V_55 < sizeof( V_52 -> V_64 ) / sizeof( T_1 ) ;
V_55 ++ )
V_52 -> V_64 [ V_55 ] =
F_2 ( V_47 [ 2 + V_55 ] ) ;
} else {
V_52 -> V_62 =
F_2 ( V_2 -> V_65 [ 0 ] ) ;
V_52 -> V_63 =
F_2 ( V_2 -> V_65 [ 1 ] ) ;
for ( V_55 = 0 ;
V_55 < sizeof( V_52 -> V_64 ) / sizeof( T_1 ) ;
V_55 ++ )
V_52 -> V_64 [ V_55 ] =
F_2 ( V_2 -> V_65 [ 2 + V_55 ] ) ;
}
V_54 = (struct V_53 * ) ( ( V_58 * ) V_52 +
sizeof( struct V_51 ) ) ;
V_54 -> type = F_2 ( V_66 ) ;
V_54 -> V_60 = F_2 ( sizeof( V_54 -> V_67 ) ) ;
V_54 -> V_67 = 0 ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_48 ) +
sizeof( struct V_51 ) +
sizeof( struct V_53 ) ) ;
return 0 ;
}
static int F_11 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_68 * V_69 )
{
struct V_70 * V_71 ;
struct V_68 * V_72 = & V_4 -> V_11 . V_73 ;
V_4 -> V_6 = F_2 ( V_74 ) ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_68 ) ) ;
switch ( V_5 ) {
case V_28 :
if ( V_69 -> V_75 ) {
V_71 = (struct V_70
* ) ( ( unsigned long ) V_69 +
sizeof( struct V_68 ) ) ;
memmove ( V_72 , V_69 ,
sizeof( struct V_68 ) +
sizeof( struct V_70 ) +
V_71 -> V_60 ) ;
V_71 = (struct V_70 * ) ( ( V_58 * )
V_72 +
sizeof( struct V_68 ) ) ;
V_4 -> V_8 = F_2 ( F_8 ( V_4 -> V_8 ) +
sizeof( struct V_70 ) +
V_71 -> V_60 ) ;
} else {
memmove ( V_72 , V_69 , sizeof( * V_69 ) ) ;
}
V_72 -> V_13 = F_2 ( V_5 ) ;
break;
case V_39 :
V_72 -> V_13 = F_2 ( V_5 ) ;
break;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_76 )
{
struct V_77 * V_69 = & V_4 -> V_11 . V_69 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_77 )
+ V_10 ) ;
V_4 -> V_6 = F_2 ( V_78 ) ;
V_69 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_79 * V_80 )
{
struct V_81 * V_82 = & V_4 -> V_11 . V_82 ;
struct V_83 * V_84 = & V_4 -> V_11 . V_84 ;
V_4 -> V_6 = F_2 ( V_85 ) ;
if ( V_5 != V_28 )
return 0 ;
if ( V_2 -> V_29 -> V_86 == V_87 ) {
V_4 -> V_8 = F_2 ( sizeof( struct V_81 ) +
V_10 ) ;
V_82 -> V_88 = F_2 ( V_89 ) ;
V_82 -> V_90 = F_2 ( ( T_1 ) V_80 -> V_91 ) ;
V_82 -> V_92 = F_2 ( V_93 ) ;
V_82 -> V_94 = F_2 ( ( T_1 ) V_80 -> V_95 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( struct V_83 ) +
V_10 ) ;
V_84 -> V_13 = F_2 ( V_96 ) ;
V_84 -> V_97 = F_2 ( ( T_1 ) V_80 -> V_91 ) ;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_98 * V_99 )
{
struct V_100 * V_29 = V_2 -> V_29 ;
struct V_101 * V_102 = & V_4 -> V_11 . V_103 ;
T_1 V_104 = false ;
if ( ! V_99 )
V_104 = true ;
V_4 -> V_6 = F_2 ( V_105 ) ;
if ( ! V_104 &&
( V_99 -> V_106 != F_15 ( V_107 ) ) &&
( ( V_29 -> V_108 > 0 ) &&
( V_29 -> V_108 <= V_109 ) ) ) {
F_6 ( V_29 -> V_30 ,
L_5 ,
V_29 -> V_108 ) ;
memcpy ( ( ( V_58 * ) V_102 ) +
sizeof( struct V_101 ) ,
V_29 -> V_110 , V_29 -> V_108 ) ;
V_4 -> V_8 = F_2
( V_29 -> V_108 +
sizeof( struct V_101 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( V_10 + sizeof( struct
V_101 ) ) ;
}
if ( V_104 ) {
V_102 -> V_13 = F_2 ( V_111 ) ;
V_102 -> V_11 . V_104 . V_112 = V_113 ;
} else {
V_102 -> V_13 = F_2 ( V_114 ) ;
V_102 -> V_11 . V_115 . V_106 = V_99 -> V_106 ;
V_102 -> V_11 . V_115 . V_116 = V_99 -> V_116 ;
V_102 -> V_11 . V_115 . V_117 = V_99 -> V_117 ;
F_6 ( V_29 -> V_30 ,
L_6 ,
V_102 -> V_11 . V_115 . V_106 ,
V_102 -> V_11 . V_115 . V_116 ,
V_102 -> V_11 . V_115 . V_117 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_118 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_119 ) +
V_10 ) ;
V_4 -> V_120 = 0 ;
V_4 -> V_11 . V_121 . V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 )
memcpy ( V_4 -> V_11 . V_121 . V_121 , V_2 -> V_122 ,
V_123 ) ;
return 0 ;
}
static int
F_17 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_124 * V_125 )
{
struct V_126 * V_127 = & V_4 -> V_11 . V_128 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_126 ) +
V_10 ) ;
V_4 -> V_6 = F_2 ( V_129 ) ;
V_127 -> V_13 = F_2 ( V_5 ) ;
V_127 -> V_130 =
F_2 ( ( T_1 ) V_125 -> V_131 ) ;
memcpy ( V_127 -> V_132 , V_125 -> V_132 ,
V_125 -> V_131 * V_123 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
V_58 * V_133 )
{
struct V_134 * V_135 = & V_4 -> V_11 . V_135 ;
V_4 -> V_6 = F_2 ( V_136 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_134 )
+ V_10 ) ;
memcpy ( V_135 -> V_121 , V_133 , V_123 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_7 , V_135 -> V_121 ) ;
V_135 -> V_137 = F_2 ( V_138 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_139 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_140 * V_141 ,
T_1 * V_142 )
{
int V_143 ;
V_58 V_55 ;
for ( V_55 = 0 ; V_55 < V_144 ; V_55 ++ ) {
if ( ( V_2 -> V_145 [ V_55 ] . V_146 == V_147 ) ||
( V_2 -> V_145 [ V_55 ] . V_146 == V_148 ) ) {
V_141 -> type =
F_2 ( V_149 ) ;
#define F_21 8
V_141 -> V_60 = F_2 ( ( T_1 )
( V_2 -> V_145 [ V_55 ] .
V_146 +
F_21 ) ) ;
V_141 -> V_150 =
F_2 ( V_151 ) ;
V_141 -> V_152 =
F_2 ( V_153 | V_154 |
V_155 ) ;
V_141 -> V_156 =
F_2 ( V_2 -> V_145 [ V_55 ] . V_146 ) ;
V_141 -> V_157 [ 0 ] = V_55 ;
if ( V_55 ==
( V_2 ->
V_158 & V_159 ) )
V_141 -> V_157 [ 1 ] = 1 ;
else
V_141 -> V_157 [ 1 ] = 0 ;
memmove ( & V_141 -> V_157 [ 2 ] ,
V_2 -> V_145 [ V_55 ] . V_160 ,
V_2 -> V_145 [ V_55 ] . V_146 ) ;
V_143 = V_2 -> V_145 [ V_55 ] . V_146 +
F_21 +
sizeof( struct V_61 ) ;
* V_142 += ( T_1 ) V_143 ;
V_141 =
(struct V_140 * )
( ( V_58 * ) V_141 +
V_143 ) ;
} else if ( ! V_2 -> V_145 [ V_55 ] . V_146 ) {
continue;
} else {
F_4 ( V_2 -> V_29 -> V_30 ,
L_8 ,
( V_55 + 1 ) , V_2 -> V_145 [ V_55 ] . V_146 ) ;
return - 1 ;
}
}
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_32 ,
struct V_161 * V_162 )
{
struct V_163 * V_160 =
& V_4 -> V_11 . V_160 ;
struct V_164 * V_165 ;
T_1 V_142 = 0 , V_166 ;
int V_167 = 0 ;
const V_58 V_168 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_6 = F_2 ( V_169 ) ;
V_160 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_160 -> V_13 ) + V_10 ) ;
return V_167 ;
}
if ( ! V_162 ) {
memset ( & V_160 -> V_141 , 0 ,
( V_144 *
sizeof( struct V_140 ) ) ) ;
V_167 = F_20 ( V_2 ,
& V_160 -> V_141 ,
& V_142 ) ;
V_4 -> V_8 = F_2 ( V_142 +
sizeof( V_160 -> V_13 ) + V_10 ) ;
return V_167 ;
} else
memset ( & V_160 -> V_141 , 0 ,
sizeof( struct V_140 ) ) ;
if ( V_162 -> V_170 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_9 ) ;
V_160 -> V_141 . V_150 =
F_2 ( V_171 ) ;
if ( V_32 == V_172 )
V_160 -> V_141 . V_152 =
F_2 ( V_153 ) ;
else
V_160 -> V_141 . V_152 =
F_2 ( ! V_153 ) ;
V_160 -> V_141 . V_157 [ 0 ] = V_162 -> V_173 ;
if ( ! V_2 -> V_174 . V_175 )
V_160 -> V_141 . V_157 [ 1 ] = 1 ;
else
V_160 -> V_141 . V_157 [ 1 ] = 0 ;
if ( 0 != memcmp ( V_162 -> V_121 , V_168 , sizeof( V_168 ) ) ) {
V_160 -> V_141 . V_152 |=
F_2 ( V_154 ) ;
} else {
V_160 -> V_141 . V_152 |=
F_2 ( V_155 ) ;
V_2 -> V_174 . V_175 = true ;
}
V_160 -> V_141 . type =
F_2 ( V_149 ) ;
V_160 -> V_141 . V_156 =
F_2 ( V_176 ) ;
memcpy ( & V_160 -> V_141 . V_157 [ 2 ] ,
V_162 -> V_160 , V_162 -> V_156 ) ;
memcpy ( & V_160 -> V_141 . V_157 [ 2 + V_162 -> V_156 ] ,
V_162 -> V_177 , V_178 ) ;
V_160 -> V_141 . V_60 =
F_2 ( V_176 + V_179 ) ;
V_142 = ( V_176 + V_179 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_160 -> V_13 )
+ V_10 + V_142 ) ;
return V_167 ;
}
if ( V_162 -> V_156 == V_180 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_10 ) ;
V_160 -> V_141 . V_150 =
F_2 ( V_181 ) ;
if ( V_32 == V_172 )
V_160 -> V_141 . V_152 =
F_2 ( V_153 ) ;
else
V_160 -> V_141 . V_152 =
F_2 ( ! V_153 ) ;
if ( V_162 -> V_173 & V_182 )
V_160 -> V_141 . V_152 |=
F_2 ( V_154 ) ;
else
V_160 -> V_141 . V_152 |=
F_2 ( V_155 ) ;
} else if ( V_162 -> V_156 == V_183 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_11 ) ;
V_160 -> V_141 . V_150 =
F_2 ( V_184 ) ;
V_160 -> V_141 . V_152 =
F_2 ( V_153 ) ;
if ( V_162 -> V_173 & V_182 )
V_160 -> V_141 . V_152 |=
F_2 ( V_154 ) ;
else
V_160 -> V_141 . V_152 |=
F_2 ( V_155 ) ;
}
if ( V_160 -> V_141 . V_150 ) {
V_160 -> V_141 . type =
F_2 ( V_149 ) ;
V_160 -> V_141 . V_156 =
F_2 ( ( T_1 ) V_162 -> V_156 ) ;
memcpy ( V_160 -> V_141 . V_157 , V_162 -> V_160 ,
V_162 -> V_156 ) ;
V_160 -> V_141 . V_60 =
F_2 ( ( T_1 ) V_162 -> V_156 +
V_179 ) ;
V_142 = ( T_1 ) ( V_162 -> V_156 + V_179 )
+ sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_160 -> V_13 ) + V_10
+ V_142 ) ;
if ( V_2 -> V_185 == V_186 ) {
V_165 = ( void * ) ( ( V_58 * ) & V_160 -> V_141 +
V_142 ) ;
V_165 -> V_187 . type = F_2 ( V_188 ) ;
V_165 -> V_187 . V_189 = F_2 ( V_123 ) ;
memcpy ( V_165 -> V_121 , V_162 -> V_121 , V_123 ) ;
V_166 = V_142 + V_10 +
sizeof( V_160 -> V_13 ) +
sizeof( struct V_164 ) ;
} else {
V_166 = V_142 + V_10 +
sizeof( V_160 -> V_13 ) ;
}
V_4 -> V_8 = F_2 ( V_166 ) ;
}
return V_167 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_100 * V_29 = V_2 -> V_29 ;
struct V_190 * V_191 =
& V_4 -> V_11 . V_191 ;
struct V_192 * V_193 =
& V_191 -> V_193 ;
V_58 V_194 = V_29 -> V_195 . V_194 ;
F_6 ( V_29 -> V_30 , L_12 , V_194 ) ;
V_4 -> V_6 = F_2 ( V_196 ) ;
V_191 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_191 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_193 -> V_197 . type = F_2 ( V_198 ) ;
memcpy ( V_193 -> V_199 , V_29 -> V_195 . V_199 ,
sizeof( V_193 -> V_199 ) ) ;
V_193 -> V_197 . V_189 =
F_2 ( ( V_194 *
sizeof( struct V_200 ) )
+ sizeof( V_193 -> V_199 ) ) ;
if ( V_194 ) {
memcpy ( V_193 -> V_201 , V_29 -> V_195 . V_201 ,
V_194 * sizeof( struct
V_200 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_191 -> V_13 ) +
F_8 ( V_193 -> V_197 . V_189 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_191 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_202 )
{
struct V_203 * V_204 =
& ( V_4 -> V_11 . V_205 ) ;
V_4 -> V_6 = F_2 ( V_206 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_203 ) +
V_10 ) ;
V_4 -> V_120 = 0 ;
V_204 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_202 )
V_204 -> V_202 = F_2 ( * V_202 ) ;
else
V_204 -> V_202 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_76 )
{
struct V_207 * V_208 = V_76 ;
switch ( F_8 ( V_4 -> V_6 ) ) {
case V_209 :
{
struct V_210 * V_211 ;
V_4 -> V_8 = F_2 ( sizeof( * V_211 ) + V_10 ) ;
V_211 = & V_4 -> V_11 . V_211 ;
V_211 -> V_13 = F_2 ( V_5 ) ;
V_211 -> V_212 =
F_2 ( ( T_1 ) F_26 ( V_208 -> V_212 ) ) ;
V_211 -> V_44 = V_208 -> V_44 ;
break;
}
case V_213 :
{
struct V_214 * V_215 ;
V_4 -> V_8 = F_2 ( sizeof( * V_215 ) + V_10 ) ;
V_215 = & V_4 -> V_11 . V_215 ;
V_215 -> V_13 = F_2 ( V_5 ) ;
V_215 -> V_212 =
F_2 ( ( T_1 ) F_26 ( V_208 -> V_212 ) ) ;
V_215 -> V_44 = ( V_58 ) F_26 ( V_208 -> V_44 ) ;
break;
}
case V_216 :
{
struct V_217 * V_218 ;
V_4 -> V_8 = F_2 ( sizeof( * V_218 ) + V_10 ) ;
V_218 = & V_4 -> V_11 . V_218 ;
V_218 -> V_13 = F_2 ( V_5 ) ;
V_218 -> V_212 = F_2 ( ( T_1 ) F_26 ( V_208 -> V_212 ) ) ;
V_218 -> V_44 = ( V_58 ) F_26 ( V_208 -> V_44 ) ;
break;
}
case V_219 :
{
struct V_220 * V_221 ;
V_4 -> V_8 = F_2 ( sizeof( * V_221 ) + V_10 ) ;
V_221 = & V_4 -> V_11 . V_221 ;
V_221 -> V_13 = F_2 ( V_5 ) ;
V_221 -> V_212 =
F_2 ( ( T_1 ) F_26 ( V_208 -> V_212 ) ) ;
V_221 -> V_44 = ( V_58 ) F_26 ( V_208 -> V_44 ) ;
break;
}
case V_222 :
{
struct V_217 * V_223 ;
V_4 -> V_8 = F_2 ( sizeof( * V_223 ) + V_10 ) ;
V_223 = & V_4 -> V_11 . V_218 ;
V_223 -> V_13 = F_2 ( V_5 ) ;
V_223 -> V_212 =
F_2 ( ( T_1 ) F_26 ( V_208 -> V_212 ) ) ;
V_223 -> V_44 = ( V_58 ) F_26 ( V_208 -> V_44 ) ;
break;
}
case V_224 :
{
struct V_225 * V_226 = V_76 ;
struct V_227 * V_228 =
& V_4 -> V_11 . V_229 ;
V_4 -> V_8 = F_2 ( sizeof( * V_228 ) + V_10 ) ;
V_228 -> V_13 = F_2 ( V_5 ) ;
V_228 -> V_212 = V_226 -> V_212 ;
V_228 -> V_230 = V_226 -> V_230 ;
V_228 -> V_44 = 0 ;
break;
}
default:
return - 1 ;
}
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_13 )
{
struct V_231 * V_232 =
& V_4 -> V_11 . V_233 ;
struct V_234 * V_235 = V_2 -> V_29 -> V_235 ;
T_3 * V_236 ;
V_4 -> V_6 = F_2 ( V_237 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_231 ) + V_10 ) ;
V_4 -> V_120 = 0 ;
memset ( V_232 , 0 , sizeof( struct V_231 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_232 -> V_238 = ( T_2 ) ( V_235 -> V_239 ) ;
V_232 -> V_240 = ( T_2 ) ( ( ( V_241 ) V_235 -> V_239 ) >> 32 ) ;
V_232 -> V_242 = V_243 ;
V_232 -> V_244 = ( T_2 ) ( V_235 -> V_245 ) ;
V_232 -> V_246 = ( T_2 ) ( ( ( V_241 ) V_235 -> V_245 ) >> 32 ) ;
V_232 -> V_247 = V_243 ;
V_232 -> V_248 = ( T_2 ) ( V_235 -> V_249 ) ;
V_232 -> V_250 = ( T_2 ) ( ( ( V_241 ) V_235 -> V_249 ) >> 32 ) ;
V_232 -> V_251 = V_252 ;
if ( V_235 -> V_253 ) {
V_236 = F_28 ( V_235 -> V_253 ) ;
V_232 -> V_254 = ( T_2 ) * V_236 ;
V_232 -> V_255 = ( T_2 ) ( ( ( V_241 ) * V_236 ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_13 ,
V_232 -> V_254 ) ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_256 * V_257 )
{
struct V_258 * V_259 = & V_4 -> V_11 . V_259 ;
struct V_260 * V_261 ;
T_1 V_262 ;
V_58 * V_263 ;
V_4 -> V_6 = F_2 ( V_264 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_258 ) +
V_10 ) ;
V_259 -> V_13 = F_2 ( V_257 -> V_13 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_14 , V_257 -> V_13 ) ;
if ( V_257 -> V_13 == V_39 )
return 0 ;
V_259 -> V_265 = F_2 ( V_257 -> V_265 ) ;
V_262 = V_257 -> V_265 ;
F_6 ( V_2 -> V_29 -> V_30 , L_15 ,
V_262 ) ;
if ( ( ( V_257 -> V_13 == V_266 ) ||
( V_257 -> V_13 == V_267 ) ) &&
( V_262 == 0 ) ) {
F_6 ( V_2 -> V_29 -> V_30 , L_16
L_17 ) ;
return - V_268 ;
}
if ( V_257 -> V_13 == V_266 )
return 0 ;
V_263 = ( ( V_58 * ) V_259 ) +
sizeof( struct V_258 ) ;
if ( V_262 & V_269 ) {
V_261 = (struct V_260 * ) V_263 ;
V_261 -> V_197 . type = F_2 ( V_270 ) ;
V_261 -> V_197 . V_189 =
F_2 ( sizeof( struct V_260 ) -
sizeof( struct V_61 ) ) ;
V_261 -> V_271 = V_257 -> V_272 . V_271 ;
V_261 -> V_273 = V_257 -> V_272 . V_273 ;
F_6 ( V_2 -> V_29 -> V_30 , L_18
L_19 ,
V_257 -> V_272 . V_271 ,
V_257 -> V_272 . V_273 ) ;
V_263 += sizeof( struct V_260 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_260 ) ) ;
}
if ( V_262 & V_274 ) {
V_261 = (struct V_260 * ) V_263 ;
V_261 -> V_197 . type = F_2 ( V_275 ) ;
V_261 -> V_197 . V_189 =
F_2 ( sizeof( struct V_260 ) -
sizeof( struct V_61 ) ) ;
V_261 -> V_271 = V_257 -> V_276 . V_271 ;
V_261 -> V_273 = V_257 -> V_276 . V_273 ;
F_6 ( V_2 -> V_29 -> V_30 , L_20
L_19 ,
V_257 -> V_276 . V_271 ,
V_257 -> V_276 . V_273 ) ;
V_263 += sizeof( struct V_260 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_260 ) ) ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 , T_4 V_277 ,
T_1 V_5 , T_2 V_32 ,
void * V_76 , void * V_278 )
{
struct V_3 * V_279 = V_278 ;
int V_167 = 0 ;
switch ( V_277 ) {
case V_280 :
V_167 = F_31 ( V_2 , V_279 ) ;
break;
case V_31 :
V_167 = F_3 ( V_2 , V_279 , V_5 ,
V_76 ) ;
break;
case V_118 :
V_167 = F_16 ( V_2 , V_279 ,
V_5 ) ;
break;
case V_129 :
V_167 = F_17 ( V_279 , V_5 ,
V_76 ) ;
break;
case V_56 :
V_167 = F_10 ( V_2 , V_279 , V_5 ,
V_76 ) ;
break;
case V_74 :
V_167 = F_11 ( V_279 , V_5 ,
V_76 ) ;
break;
case V_78 :
V_167 = F_12 ( V_2 , V_279 , V_5 ,
V_76 ) ;
break;
case V_85 :
V_167 = F_13 ( V_2 , V_279 , V_5 ,
V_76 ) ;
break;
case V_281 :
V_167 = F_32 ( V_2 , V_279 , V_5 ,
( T_4 ) V_32 , V_76 ) ;
break;
case V_105 :
V_167 = F_14 ( V_2 , V_279 , V_5 ,
(struct V_98 * ) V_76 ) ;
break;
case V_282 :
V_167 = F_33 ( V_279 , V_76 ) ;
break;
case V_283 :
V_167 = F_34 ( V_279 ) ;
break;
case V_284 :
V_167 = F_35 ( V_2 , V_279 , V_76 ) ;
break;
case V_136 :
V_167 = F_18 ( V_2 , V_279 ,
V_76 ) ;
break;
case V_285 :
V_167 = F_36 ( V_2 , V_279 ,
V_76 ) ;
break;
case V_45 :
V_167 = F_9 ( V_279 ) ;
break;
case V_286 :
V_167 = F_37 ( V_2 , V_279 ,
V_76 ) ;
break;
case V_139 :
V_167 = F_19 ( V_279 ) ;
break;
case V_7 :
V_167 = F_1 ( V_2 , V_279 , V_5 ) ;
break;
case V_37 :
V_167 = F_5 ( V_2 , V_279 , V_5 ,
V_32 , V_76 ) ;
break;
case V_287 :
V_279 -> V_6 =
F_2 ( V_287 ) ;
V_279 -> V_8 =
F_2 ( sizeof( struct V_288 ) +
V_10 ) ;
V_2 -> V_289 = 0 ;
V_167 = 0 ;
break;
case V_290 :
V_279 -> V_6 = F_2 ( V_277 ) ;
V_279 -> V_11 . V_291 . V_292 =
( V_58 ) ( * ( ( T_2 * ) V_76 ) ) ;
memcpy ( & V_279 -> V_11 , V_76 ,
sizeof( struct V_293 ) ) ;
V_279 -> V_8 =
F_2 ( sizeof( struct V_293 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_294 :
if ( V_2 -> V_29 -> V_295 == V_296 )
V_2 -> V_29 -> V_295 = V_297 ;
V_279 -> V_6 = F_2 ( V_277 ) ;
V_279 -> V_8 = F_2 ( V_10 ) ;
break;
case V_298 :
V_2 -> V_29 -> V_295 = V_296 ;
V_279 -> V_6 = F_2 ( V_277 ) ;
V_279 -> V_8 = F_2 ( V_10 ) ;
break;
case V_299 :
V_167 = F_38 ( V_279 , V_76 ) ;
break;
case V_300 :
V_167 = F_39 ( V_279 , V_76 ) ;
break;
case V_301 :
V_167 = F_40 ( V_2 , V_279 , V_76 ) ;
break;
case V_169 :
V_167 = F_22 ( V_2 , V_279 ,
V_5 , V_32 ,
V_76 ) ;
break;
case V_196 :
V_167 = F_23 ( V_2 , V_279 ,
V_5 ) ;
break;
case V_302 :
V_167 = F_41 ( V_2 , V_279 , V_5 ,
V_76 ) ;
break;
case V_303 :
V_167 = F_42 ( V_279 , V_5 ,
V_76 ) ;
break;
case V_304 :
V_167 = F_43 ( V_279 , V_5 , V_76 ) ;
break;
case V_305 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_21 ) ;
V_279 -> V_6 = F_2 ( V_305 ) ;
V_279 -> V_8 =
F_2 ( sizeof( struct V_306 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_206 :
V_167 = F_24 ( V_279 , V_5 ,
V_76 ) ;
break;
case V_209 :
case V_213 :
case V_216 :
case V_219 :
case V_222 :
case V_224 :
V_167 = F_25 ( V_279 , V_5 , V_76 ) ;
break;
case V_307 :
V_279 -> V_6 = F_2 ( V_277 ) ;
if ( V_2 -> V_308 == V_309 )
V_279 -> V_11 . V_308 . V_310 =
V_311 ;
else if ( V_2 -> V_308 == V_312 )
V_279 -> V_11 . V_308 . V_310 =
V_313 ;
V_279 -> V_8 = F_2 ( sizeof( struct
V_314 ) + V_10 ) ;
V_167 = 0 ;
break;
case V_237 :
V_167 = F_27 ( V_2 , V_279 , V_5 ) ;
break;
case V_264 :
V_167 = F_29 ( V_2 , V_279 , V_76 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_22 , V_277 ) ;
V_167 = - 1 ;
break;
}
return V_167 ;
}
int F_44 ( struct V_1 * V_2 , V_58 V_315 )
{
int V_167 ;
T_1 V_202 = true ;
struct V_316 V_317 ;
struct V_318 V_319 ;
enum V_320 V_321 ;
struct V_322 V_323 ;
if ( V_315 ) {
if ( V_2 -> V_29 -> V_324 == V_325 ) {
V_167 = F_45 ( V_2 ,
V_237 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
}
V_167 = F_45 ( V_2 , V_294 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
V_167 = F_45 ( V_2 , V_280 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
V_167 = F_45 ( V_2 ,
V_302 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_326 ) ;
if ( V_167 )
return - 1 ;
if ( V_2 -> V_185 != V_186 ) {
V_2 -> V_29 -> V_327 = V_328 ;
V_167 = F_45 (
V_2 , V_281 ,
V_329 , V_330 , NULL ) ;
if ( V_167 )
return - 1 ;
}
}
V_167 = F_45 ( V_2 , V_56 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
V_2 -> V_331 = 0 ;
V_167 = F_45 ( V_2 , V_78 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
if ( V_2 -> V_185 == V_332 ) {
V_167 = F_45 (
V_2 , V_206 ,
V_28 , 0 , & V_202 ) ;
if ( V_167 )
return - 1 ;
}
memset ( & V_317 , 0 , sizeof( V_317 ) ) ;
V_317 . V_202 = true ;
V_167 = F_45 ( V_2 , V_303 ,
V_28 , 0 ,
& V_317 ) ;
if ( V_167 )
return - 1 ;
V_167 = F_45 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_333 ) ;
if ( V_167 )
return - 1 ;
if ( V_315 && V_2 -> V_29 -> V_324 != V_334 &&
V_2 -> V_185 != V_186 ) {
V_319 . V_319 = V_335 ;
V_319 . V_336 = V_337 ;
V_167 = F_45 ( V_2 ,
V_281 ,
V_329 , V_338 ,
& V_319 ) ;
if ( V_167 )
return - 1 ;
}
if ( V_2 -> V_185 != V_186 ) {
V_321 = V_339 ;
V_167 = F_45 ( V_2 , V_37 ,
V_28 , V_340 ,
& V_321 ) ;
if ( V_167 )
F_4 ( V_2 -> V_29 -> V_30 ,
L_23 ) ;
}
V_323 . V_341 = V_342 ;
V_167 = F_45 ( V_2 , V_304 ,
V_28 , 0 , & V_323 ) ;
V_2 -> V_29 -> V_343 = V_304 ;
V_167 = - V_344 ;
return V_167 ;
}
