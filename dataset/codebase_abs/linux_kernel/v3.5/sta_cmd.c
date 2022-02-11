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
static int
F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_76 * V_77 )
{
struct V_78 * V_29 = V_2 -> V_29 ;
struct V_79 * V_80 = & V_4 -> V_11 . V_81 ;
T_1 V_82 = false ;
if ( ! V_77 )
V_82 = true ;
V_4 -> V_6 = F_2 ( V_83 ) ;
if ( ! V_82 &&
( V_77 -> V_84 != F_13 ( V_85 ) ) &&
( ( V_29 -> V_86 > 0 ) &&
( V_29 -> V_86 <= V_87 ) ) ) {
F_6 ( V_29 -> V_30 ,
L_5 ,
V_29 -> V_86 ) ;
memcpy ( ( ( V_58 * ) V_80 ) +
sizeof( struct V_79 ) ,
V_29 -> V_88 , V_29 -> V_86 ) ;
V_4 -> V_8 = F_2
( V_29 -> V_86 +
sizeof( struct V_79 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( V_10 + sizeof( struct
V_79 ) ) ;
}
if ( V_82 ) {
V_80 -> V_13 = F_2 ( V_89 ) ;
V_80 -> V_11 . V_82 . V_90 = V_91 ;
} else {
V_80 -> V_13 = F_2 ( V_92 ) ;
V_80 -> V_11 . V_93 . V_84 = V_77 -> V_84 ;
V_80 -> V_11 . V_93 . V_94 = V_77 -> V_94 ;
V_80 -> V_11 . V_93 . V_95 = V_77 -> V_95 ;
F_6 ( V_29 -> V_30 ,
L_6 ,
V_80 -> V_11 . V_93 . V_84 ,
V_80 -> V_11 . V_93 . V_94 ,
V_80 -> V_11 . V_93 . V_95 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_96 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_97 ) +
V_10 ) ;
V_4 -> V_98 = 0 ;
V_4 -> V_11 . V_99 . V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 )
memcpy ( V_4 -> V_11 . V_99 . V_99 , V_2 -> V_100 ,
V_101 ) ;
return 0 ;
}
static int
F_15 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_102 * V_103 )
{
struct V_104 * V_105 = & V_4 -> V_11 . V_106 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_104 ) +
V_10 ) ;
V_4 -> V_6 = F_2 ( V_107 ) ;
V_105 -> V_13 = F_2 ( V_5 ) ;
V_105 -> V_108 =
F_2 ( ( T_1 ) V_103 -> V_109 ) ;
memcpy ( V_105 -> V_110 , V_103 -> V_110 ,
V_103 -> V_109 * V_101 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
V_58 * V_111 )
{
struct V_112 * V_113 = & V_4 -> V_11 . V_113 ;
V_4 -> V_6 = F_2 ( V_114 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_112 )
+ V_10 ) ;
memcpy ( V_113 -> V_99 , V_111 , V_101 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_7 , V_113 -> V_99 ) ;
V_113 -> V_115 = F_2 ( V_116 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_117 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 ,
struct V_118 * V_119 ,
T_1 * V_120 )
{
int V_121 ;
V_58 V_55 ;
for ( V_55 = 0 ; V_55 < V_122 ; V_55 ++ ) {
if ( ( V_2 -> V_123 [ V_55 ] . V_124 == V_125 ) ||
( V_2 -> V_123 [ V_55 ] . V_124 == V_126 ) ) {
V_119 -> type =
F_2 ( V_127 ) ;
#define F_19 8
V_119 -> V_60 = F_2 ( ( T_1 )
( V_2 -> V_123 [ V_55 ] .
V_124 +
F_19 ) ) ;
V_119 -> V_128 =
F_2 ( V_129 ) ;
V_119 -> V_130 =
F_2 ( V_131 | V_132 |
V_133 ) ;
V_119 -> V_134 =
F_2 ( V_2 -> V_123 [ V_55 ] . V_124 ) ;
V_119 -> V_135 [ 0 ] = V_55 ;
if ( V_55 ==
( V_2 ->
V_136 & V_137 ) )
V_119 -> V_135 [ 1 ] = 1 ;
else
V_119 -> V_135 [ 1 ] = 0 ;
memmove ( & V_119 -> V_135 [ 2 ] ,
V_2 -> V_123 [ V_55 ] . V_138 ,
V_2 -> V_123 [ V_55 ] . V_124 ) ;
V_121 = V_2 -> V_123 [ V_55 ] . V_124 +
F_19 +
sizeof( struct V_61 ) ;
* V_120 += ( T_1 ) V_121 ;
V_119 =
(struct V_118 * )
( ( V_58 * ) V_119 +
V_121 ) ;
} else if ( ! V_2 -> V_123 [ V_55 ] . V_124 ) {
continue;
} else {
F_4 ( V_2 -> V_29 -> V_30 ,
L_8 ,
( V_55 + 1 ) , V_2 -> V_123 [ V_55 ] . V_124 ) ;
return - 1 ;
}
}
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_32 ,
struct V_139 * V_140 )
{
struct V_141 * V_138 =
& V_4 -> V_11 . V_138 ;
struct V_142 * V_143 ;
T_1 V_120 = 0 , V_144 ;
int V_145 = 0 ;
const V_58 V_146 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_6 = F_2 ( V_147 ) ;
V_138 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_138 -> V_13 ) + V_10 ) ;
return V_145 ;
}
if ( ! V_140 ) {
memset ( & V_138 -> V_119 , 0 ,
( V_122 *
sizeof( struct V_118 ) ) ) ;
V_145 = F_18 ( V_2 ,
& V_138 -> V_119 ,
& V_120 ) ;
V_4 -> V_8 = F_2 ( V_120 +
sizeof( V_138 -> V_13 ) + V_10 ) ;
return V_145 ;
} else
memset ( & V_138 -> V_119 , 0 ,
sizeof( struct V_118 ) ) ;
if ( V_140 -> V_148 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_9 ) ;
V_138 -> V_119 . V_128 =
F_2 ( V_149 ) ;
if ( V_32 == V_150 )
V_138 -> V_119 . V_130 =
F_2 ( V_131 ) ;
else
V_138 -> V_119 . V_130 =
F_2 ( ! V_131 ) ;
V_138 -> V_119 . V_135 [ 0 ] = V_140 -> V_151 ;
if ( ! V_2 -> V_152 . V_153 )
V_138 -> V_119 . V_135 [ 1 ] = 1 ;
else
V_138 -> V_119 . V_135 [ 1 ] = 0 ;
if ( 0 != memcmp ( V_140 -> V_99 , V_146 , sizeof( V_146 ) ) ) {
V_138 -> V_119 . V_130 |=
F_2 ( V_132 ) ;
} else {
V_138 -> V_119 . V_130 |=
F_2 ( V_133 ) ;
V_2 -> V_152 . V_153 = true ;
}
V_138 -> V_119 . type =
F_2 ( V_127 ) ;
V_138 -> V_119 . V_134 =
F_2 ( V_154 ) ;
memcpy ( & V_138 -> V_119 . V_135 [ 2 ] ,
V_140 -> V_138 , V_140 -> V_134 ) ;
memcpy ( & V_138 -> V_119 . V_135 [ 2 + V_140 -> V_134 ] ,
V_140 -> V_155 , V_156 ) ;
V_138 -> V_119 . V_60 =
F_2 ( V_154 + V_157 ) ;
V_120 = ( V_154 + V_157 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_138 -> V_13 )
+ V_10 + V_120 ) ;
return V_145 ;
}
if ( V_140 -> V_134 == V_158 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_10 ) ;
V_138 -> V_119 . V_128 =
F_2 ( V_159 ) ;
if ( V_32 == V_150 )
V_138 -> V_119 . V_130 =
F_2 ( V_131 ) ;
else
V_138 -> V_119 . V_130 =
F_2 ( ! V_131 ) ;
if ( V_140 -> V_151 & V_160 )
V_138 -> V_119 . V_130 |=
F_2 ( V_132 ) ;
else
V_138 -> V_119 . V_130 |=
F_2 ( V_133 ) ;
} else if ( V_140 -> V_134 == V_161 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_11 ) ;
V_138 -> V_119 . V_128 =
F_2 ( V_162 ) ;
V_138 -> V_119 . V_130 =
F_2 ( V_131 ) ;
if ( V_140 -> V_151 & V_160 )
V_138 -> V_119 . V_130 |=
F_2 ( V_132 ) ;
else
V_138 -> V_119 . V_130 |=
F_2 ( V_133 ) ;
}
if ( V_138 -> V_119 . V_128 ) {
V_138 -> V_119 . type =
F_2 ( V_127 ) ;
V_138 -> V_119 . V_134 =
F_2 ( ( T_1 ) V_140 -> V_134 ) ;
memcpy ( V_138 -> V_119 . V_135 , V_140 -> V_138 ,
V_140 -> V_134 ) ;
V_138 -> V_119 . V_60 =
F_2 ( ( T_1 ) V_140 -> V_134 +
V_157 ) ;
V_120 = ( T_1 ) ( V_140 -> V_134 + V_157 )
+ sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_138 -> V_13 ) + V_10
+ V_120 ) ;
if ( V_2 -> V_163 == V_164 ) {
V_143 = ( void * ) ( ( V_58 * ) & V_138 -> V_119 +
V_120 ) ;
V_143 -> V_165 . type = F_2 ( V_166 ) ;
V_143 -> V_165 . V_167 = F_2 ( V_101 ) ;
memcpy ( V_143 -> V_99 , V_140 -> V_99 , V_101 ) ;
V_144 = V_120 + V_10 +
sizeof( V_138 -> V_13 ) +
sizeof( struct V_142 ) ;
} else {
V_144 = V_120 + V_10 +
sizeof( V_138 -> V_13 ) ;
}
V_4 -> V_8 = F_2 ( V_144 ) ;
}
return V_145 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_78 * V_29 = V_2 -> V_29 ;
struct V_168 * V_169 =
& V_4 -> V_11 . V_169 ;
struct V_170 * V_171 =
& V_169 -> V_171 ;
V_58 V_172 = V_29 -> V_173 . V_172 ;
F_6 ( V_29 -> V_30 , L_12 , V_172 ) ;
V_4 -> V_6 = F_2 ( V_174 ) ;
V_169 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_169 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_171 -> V_175 . type = F_2 ( V_176 ) ;
memcpy ( V_171 -> V_177 , V_29 -> V_173 . V_177 ,
sizeof( V_171 -> V_177 ) ) ;
V_171 -> V_175 . V_167 =
F_2 ( ( V_172 *
sizeof( struct V_178 ) )
+ sizeof( V_171 -> V_177 ) ) ;
if ( V_172 ) {
memcpy ( V_171 -> V_179 , V_29 -> V_173 . V_179 ,
V_172 * sizeof( struct
V_178 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_169 -> V_13 ) +
F_8 ( V_171 -> V_175 . V_167 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_169 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_180 )
{
struct V_181 * V_182 =
& V_4 -> V_11 . V_183 ;
T_3 V_184 = F_8 ( V_182 -> V_184 ) ;
V_4 -> V_6 = F_2 ( V_185 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_181 )
+ V_10 ) ;
if ( V_5 == V_28 ) {
if ( ( V_2 -> V_29 -> V_186 & V_187 ) ||
( V_2 -> V_29 -> V_186 & V_188 ) )
V_182 -> V_184 =
F_2 ( V_189 ) ;
V_184 = F_8 ( V_182 -> V_184 ) ;
F_23 ( V_184 , V_2 -> V_29 -> V_190 ) ;
V_182 -> V_191 = F_2 ( * V_180 ) ;
}
V_182 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_192 )
{
struct V_193 * V_194 =
& ( V_4 -> V_11 . V_195 ) ;
V_4 -> V_6 = F_2 ( V_196 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_193 ) +
V_10 ) ;
V_4 -> V_98 = 0 ;
V_194 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_192 )
V_194 -> V_192 = F_2 ( * V_192 ) ;
else
V_194 -> V_192 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_197 )
{
struct V_198 * V_199 = V_197 ;
switch ( F_8 ( V_4 -> V_6 ) ) {
case V_200 :
{
struct V_201 * V_202 ;
V_4 -> V_8 = F_2 ( sizeof( * V_202 ) + V_10 ) ;
V_202 = (struct V_201 * ) & V_4 ->
V_11 . V_202 ;
V_202 -> V_13 = F_2 ( V_5 ) ;
V_202 -> V_203 =
F_2 ( ( T_1 ) F_26 ( V_199 -> V_203 ) ) ;
V_202 -> V_44 = V_199 -> V_44 ;
break;
}
case V_204 :
{
struct V_205 * V_206 ;
V_4 -> V_8 = F_2 ( sizeof( * V_206 ) + V_10 ) ;
V_206 = (struct V_205 * )
& V_4 -> V_11 . V_206 ;
V_206 -> V_13 = F_2 ( V_5 ) ;
V_206 -> V_203 =
F_2 ( ( T_1 ) F_26 ( V_199 -> V_203 ) ) ;
V_206 -> V_44 = ( V_58 ) F_26 ( V_199 -> V_44 ) ;
break;
}
case V_207 :
{
struct V_208 * V_209 ;
V_4 -> V_8 = F_2 ( sizeof( * V_209 ) + V_10 ) ;
V_209 = (struct V_208 * )
& V_4 -> V_11 . V_209 ;
V_209 -> V_13 = F_2 ( V_5 ) ;
V_209 -> V_203 = F_2 ( ( T_1 ) F_26 ( V_199 -> V_203 ) ) ;
V_209 -> V_44 = ( V_58 ) F_26 ( V_199 -> V_44 ) ;
break;
}
case V_210 :
{
struct V_211 * V_212 ;
V_4 -> V_8 = F_2 ( sizeof( * V_212 ) + V_10 ) ;
V_212 = (struct V_211 * ) & V_4 ->
V_11 . V_212 ;
V_212 -> V_13 = F_2 ( V_5 ) ;
V_212 -> V_203 =
F_2 ( ( T_1 ) F_26 ( V_199 -> V_203 ) ) ;
V_212 -> V_44 = ( V_58 ) F_26 ( V_199 -> V_44 ) ;
break;
}
case V_213 :
{
struct V_208 * V_214 ;
V_4 -> V_8 = F_2 ( sizeof( * V_214 ) + V_10 ) ;
V_214 = (struct V_208 * )
& V_4 -> V_11 . V_209 ;
V_214 -> V_13 = F_2 ( V_5 ) ;
V_214 -> V_203 =
F_2 ( ( T_1 ) F_26 ( V_199 -> V_203 ) ) ;
V_214 -> V_44 = ( V_58 ) F_26 ( V_199 -> V_44 ) ;
break;
}
case V_215 :
{
struct V_216 * V_217 = V_197 ;
struct V_218 * V_219 =
(struct V_218 * )
& V_4 -> V_11 . V_220 ;
V_4 -> V_8 = F_2 ( sizeof( * V_219 ) + V_10 ) ;
V_219 -> V_13 = F_2 ( V_5 ) ;
V_219 -> V_203 = V_217 -> V_203 ;
V_219 -> V_221 = V_217 -> V_221 ;
V_219 -> V_44 = 0 ;
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
struct V_222 * V_223 =
& V_4 -> V_11 . V_224 ;
struct V_225 * V_226 = V_2 -> V_29 -> V_226 ;
T_4 * V_227 ;
V_4 -> V_6 = F_2 ( V_228 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_222 ) + V_10 ) ;
V_4 -> V_98 = 0 ;
memset ( V_223 , 0 , sizeof( struct V_222 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_223 -> V_229 = ( T_2 ) ( V_226 -> V_230 ) ;
V_223 -> V_231 = ( T_2 ) ( ( ( V_232 ) V_226 -> V_230 ) >> 32 ) ;
V_223 -> V_233 = V_234 ;
V_223 -> V_235 = ( T_2 ) ( V_226 -> V_236 ) ;
V_223 -> V_237 = ( T_2 ) ( ( ( V_232 ) V_226 -> V_236 ) >> 32 ) ;
V_223 -> V_238 = V_234 ;
V_223 -> V_239 = ( T_2 ) ( V_226 -> V_240 ) ;
V_223 -> V_241 = ( T_2 ) ( ( ( V_232 ) V_226 -> V_240 ) >> 32 ) ;
V_223 -> V_242 = V_243 ;
if ( V_226 -> V_244 ) {
V_227 = F_28 ( V_226 -> V_244 ) ;
V_223 -> V_245 = ( T_2 ) * V_227 ;
V_223 -> V_246 = ( T_2 ) ( ( ( V_232 ) * V_227 ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_13 ,
V_223 -> V_245 ) ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_247 * V_248 )
{
struct V_249 * V_250 = & V_4 -> V_11 . V_250 ;
struct V_251 * V_252 ;
T_1 V_253 ;
V_58 * V_254 ;
V_4 -> V_6 = F_2 ( V_255 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_249 ) +
V_10 ) ;
V_250 -> V_13 = F_2 ( V_248 -> V_13 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_14 , V_248 -> V_13 ) ;
if ( V_248 -> V_13 == V_39 )
return 0 ;
V_250 -> V_256 = F_2 ( V_248 -> V_256 ) ;
V_253 = V_248 -> V_256 ;
F_6 ( V_2 -> V_29 -> V_30 , L_15 ,
V_253 ) ;
if ( ( ( V_248 -> V_13 == V_257 ) ||
( V_248 -> V_13 == V_258 ) ) &&
( V_253 == 0 ) ) {
F_6 ( V_2 -> V_29 -> V_30 , L_16
L_17 ) ;
return - V_259 ;
}
if ( V_248 -> V_13 == V_257 )
return 0 ;
V_254 = ( ( V_58 * ) V_250 ) +
sizeof( struct V_249 ) ;
if ( V_253 & V_260 ) {
V_252 = (struct V_251 * ) V_254 ;
V_252 -> V_175 . type = F_2 ( V_261 ) ;
V_252 -> V_175 . V_167 =
F_2 ( sizeof( struct V_251 ) -
sizeof( struct V_61 ) ) ;
V_252 -> V_262 = V_248 -> V_263 . V_262 ;
V_252 -> V_264 = V_248 -> V_263 . V_264 ;
F_6 ( V_2 -> V_29 -> V_30 , L_18
L_19 ,
V_248 -> V_263 . V_262 ,
V_248 -> V_263 . V_264 ) ;
V_254 += sizeof( struct V_251 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_251 ) ) ;
}
if ( V_253 & V_265 ) {
V_252 = (struct V_251 * ) V_254 ;
V_252 -> V_175 . type = F_2 ( V_266 ) ;
V_252 -> V_175 . V_167 =
F_2 ( sizeof( struct V_251 ) -
sizeof( struct V_61 ) ) ;
V_252 -> V_262 = V_248 -> V_267 . V_262 ;
V_252 -> V_264 = V_248 -> V_267 . V_264 ;
F_6 ( V_2 -> V_29 -> V_30 , L_20
L_19 ,
V_248 -> V_267 . V_262 ,
V_248 -> V_267 . V_264 ) ;
V_254 += sizeof( struct V_251 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_251 ) ) ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 , T_3 V_268 ,
T_1 V_5 , T_2 V_32 ,
void * V_197 , void * V_269 )
{
struct V_3 * V_270 = V_269 ;
int V_145 = 0 ;
switch ( V_268 ) {
case V_271 :
V_145 = F_31 ( V_2 , V_270 ) ;
break;
case V_31 :
V_145 = F_3 ( V_2 , V_270 , V_5 ,
V_197 ) ;
break;
case V_96 :
V_145 = F_14 ( V_2 , V_270 ,
V_5 ) ;
break;
case V_107 :
V_145 = F_15 ( V_270 , V_5 ,
V_197 ) ;
break;
case V_56 :
V_145 = F_10 ( V_2 , V_270 , V_5 ,
V_197 ) ;
break;
case V_74 :
V_145 = F_11 ( V_270 , V_5 ,
V_197 ) ;
break;
case V_272 :
V_145 = F_32 ( V_2 , V_270 , V_5 ,
( T_3 ) V_32 , V_197 ) ;
break;
case V_83 :
V_145 = F_12 ( V_2 , V_270 , V_5 ,
(struct V_76 * ) V_197 ) ;
break;
case V_273 :
V_145 = F_33 ( V_270 , V_197 ) ;
break;
case V_274 :
V_145 = F_34 ( V_270 ) ;
break;
case V_275 :
V_145 = F_35 ( V_2 , V_270 , V_197 ) ;
break;
case V_114 :
V_145 = F_16 ( V_2 , V_270 ,
V_197 ) ;
break;
case V_276 :
V_145 = F_36 ( V_2 , V_270 ,
V_197 ) ;
break;
case V_45 :
V_145 = F_9 ( V_270 ) ;
break;
case V_277 :
V_145 = F_37 ( V_2 , V_270 ,
V_197 ) ;
break;
case V_117 :
V_145 = F_17 ( V_270 ) ;
break;
case V_7 :
V_145 = F_1 ( V_2 , V_270 , V_5 ) ;
break;
case V_37 :
V_145 = F_5 ( V_2 , V_270 , V_5 ,
V_32 , V_197 ) ;
break;
case V_278 :
V_270 -> V_6 =
F_2 ( V_278 ) ;
V_270 -> V_8 =
F_2 ( sizeof( struct V_279 ) +
V_10 ) ;
V_2 -> V_280 = 0 ;
V_145 = 0 ;
break;
case V_281 :
V_270 -> V_6 = F_2 ( V_268 ) ;
V_270 -> V_11 . V_282 . V_283 =
( V_58 ) ( * ( ( T_2 * ) V_197 ) ) ;
memcpy ( & V_270 -> V_11 , V_197 ,
sizeof( struct V_284 ) ) ;
V_270 -> V_8 =
F_2 ( sizeof( struct V_284 ) +
V_10 ) ;
V_145 = 0 ;
break;
case V_185 :
V_145 = F_22 ( V_2 , V_270 , V_5 ,
V_197 ) ;
break;
case V_285 :
if ( V_2 -> V_29 -> V_286 == V_287 )
V_2 -> V_29 -> V_286 = V_288 ;
V_270 -> V_6 = F_2 ( V_268 ) ;
V_270 -> V_8 = F_2 ( V_10 ) ;
break;
case V_289 :
V_2 -> V_29 -> V_286 = V_287 ;
V_270 -> V_6 = F_2 ( V_268 ) ;
V_270 -> V_8 = F_2 ( V_10 ) ;
break;
case V_290 :
V_145 = F_38 ( V_270 , V_197 ) ;
break;
case V_291 :
V_145 = F_39 ( V_270 , V_197 ) ;
break;
case V_292 :
V_145 = F_40 ( V_2 , V_270 , V_197 ) ;
break;
case V_147 :
V_145 = F_20 ( V_2 , V_270 ,
V_5 , V_32 ,
V_197 ) ;
break;
case V_174 :
V_145 = F_21 ( V_2 , V_270 ,
V_5 ) ;
break;
case V_293 :
V_145 = F_41 ( V_2 , V_270 , V_5 ,
V_197 ) ;
break;
case V_294 :
V_145 = F_42 ( V_270 , V_5 ,
V_197 ) ;
break;
case V_295 :
V_145 = F_43 ( V_270 , V_5 , V_197 ) ;
break;
case V_296 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_21 ) ;
V_270 -> V_6 = F_2 ( V_296 ) ;
V_270 -> V_8 =
F_2 ( sizeof( struct V_297 ) +
V_10 ) ;
V_145 = 0 ;
break;
case V_196 :
V_145 = F_24 ( V_270 , V_5 ,
V_197 ) ;
break;
case V_200 :
case V_204 :
case V_207 :
case V_210 :
case V_213 :
case V_215 :
V_145 = F_25 ( V_270 , V_5 , V_197 ) ;
break;
case V_298 :
V_270 -> V_6 = F_2 ( V_268 ) ;
if ( V_2 -> V_299 == V_300 )
V_270 -> V_11 . V_299 . V_301 =
V_302 ;
else if ( V_2 -> V_299 == V_303 )
V_270 -> V_11 . V_299 . V_301 =
V_304 ;
V_270 -> V_8 = F_2 ( sizeof( struct
V_305 ) + V_10 ) ;
V_145 = 0 ;
break;
case V_228 :
V_145 = F_27 ( V_2 , V_270 , V_5 ) ;
break;
case V_255 :
V_145 = F_29 ( V_2 , V_270 , V_197 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_22 , V_268 ) ;
V_145 = - 1 ;
break;
}
return V_145 ;
}
int F_44 ( struct V_1 * V_2 , V_58 V_306 )
{
int V_145 ;
T_1 V_192 = true ;
struct V_307 V_308 ;
struct V_309 V_310 ;
enum V_311 V_312 ;
struct V_313 V_314 ;
if ( V_306 ) {
if ( V_2 -> V_29 -> V_315 == V_316 ) {
V_145 = F_45 ( V_2 ,
V_228 ,
V_28 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
}
V_145 = F_45 ( V_2 , V_285 ,
V_28 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
V_145 = F_45 ( V_2 , V_271 ,
V_39 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
V_145 = F_45 ( V_2 ,
V_293 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_317 ) ;
if ( V_145 )
return - 1 ;
if ( V_2 -> V_163 != V_164 ) {
V_2 -> V_29 -> V_318 = V_319 ;
V_145 = F_45 (
V_2 , V_272 ,
V_320 , V_321 , NULL ) ;
if ( V_145 )
return - 1 ;
}
}
V_145 = F_45 ( V_2 , V_56 ,
V_39 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
V_2 -> V_322 = 0 ;
V_145 = F_45 ( V_2 , V_74 ,
V_39 , 0 , NULL ) ;
if ( V_145 )
return - 1 ;
if ( V_2 -> V_163 == V_323 ) {
V_145 = F_45 (
V_2 , V_196 ,
V_28 , 0 , & V_192 ) ;
if ( V_145 )
return - 1 ;
}
memset ( & V_308 , 0 , sizeof( V_308 ) ) ;
V_308 . V_192 = true ;
V_145 = F_45 ( V_2 , V_294 ,
V_28 , 0 ,
& V_308 ) ;
if ( V_145 )
return - 1 ;
V_145 = F_45 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_324 ) ;
if ( V_145 )
return - 1 ;
if ( V_306 && V_2 -> V_29 -> V_315 != V_325 &&
V_2 -> V_163 != V_164 ) {
V_310 . V_310 = V_326 ;
V_310 . V_327 = V_328 ;
V_145 = F_45 ( V_2 ,
V_272 ,
V_320 , V_329 ,
& V_310 ) ;
if ( V_145 )
return - 1 ;
}
if ( V_2 -> V_163 != V_164 ) {
V_312 = V_330 ;
V_145 = F_45 ( V_2 , V_37 ,
V_28 , V_331 ,
& V_312 ) ;
if ( V_145 )
F_4 ( V_2 -> V_29 -> V_30 ,
L_23 ) ;
}
V_314 . V_332 = V_333 ;
V_145 = F_45 ( V_2 , V_295 ,
V_28 , 0 , & V_314 ) ;
V_2 -> V_29 -> V_334 = V_295 ;
V_145 = - V_335 ;
return V_145 ;
}
