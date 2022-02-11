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
T_1 V_120 = 0 ;
int V_142 = 0 ;
const V_58 V_143 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_6 = F_2 ( V_144 ) ;
V_138 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_138 -> V_13 ) + V_10 ) ;
return V_142 ;
}
if ( ! V_140 ) {
memset ( & V_138 -> V_119 , 0 ,
( V_122 *
sizeof( struct V_118 ) ) ) ;
V_142 = F_18 ( V_2 ,
& V_138 -> V_119 ,
& V_120 ) ;
V_4 -> V_8 = F_2 ( V_120 +
sizeof( V_138 -> V_13 ) + V_10 ) ;
return V_142 ;
} else
memset ( & V_138 -> V_119 , 0 ,
sizeof( struct V_118 ) ) ;
if ( V_140 -> V_145 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_9 ) ;
V_138 -> V_119 . V_128 =
F_2 ( V_146 ) ;
if ( V_32 == V_147 )
V_138 -> V_119 . V_130 =
F_2 ( V_131 ) ;
else
V_138 -> V_119 . V_130 =
F_2 ( ! V_131 ) ;
V_138 -> V_119 . V_135 [ 0 ] = V_140 -> V_148 ;
if ( ! V_2 -> V_149 . V_150 )
V_138 -> V_119 . V_135 [ 1 ] = 1 ;
else
V_138 -> V_119 . V_135 [ 1 ] = 0 ;
if ( 0 != memcmp ( V_140 -> V_99 , V_143 , sizeof( V_143 ) ) ) {
V_138 -> V_119 . V_130 |=
F_2 ( V_132 ) ;
} else {
V_138 -> V_119 . V_130 |=
F_2 ( V_133 ) ;
V_2 -> V_149 . V_150 = true ;
}
V_138 -> V_119 . type =
F_2 ( V_127 ) ;
V_138 -> V_119 . V_134 =
F_2 ( V_151 ) ;
memcpy ( & V_138 -> V_119 . V_135 [ 2 ] ,
V_140 -> V_138 , V_140 -> V_134 ) ;
memcpy ( & V_138 -> V_119 . V_135 [ 2 + V_140 -> V_134 ] ,
V_140 -> V_152 , V_153 ) ;
V_138 -> V_119 . V_60 =
F_2 ( V_151 + V_154 ) ;
V_120 = ( V_151 + V_154 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_138 -> V_13 )
+ V_10 + V_120 ) ;
return V_142 ;
}
if ( V_140 -> V_134 == V_155 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_10 ) ;
V_138 -> V_119 . V_128 =
F_2 ( V_156 ) ;
if ( V_32 == V_147 )
V_138 -> V_119 . V_130 =
F_2 ( V_131 ) ;
else
V_138 -> V_119 . V_130 =
F_2 ( ! V_131 ) ;
if ( V_140 -> V_148 & V_157 )
V_138 -> V_119 . V_130 |=
F_2 ( V_132 ) ;
else
V_138 -> V_119 . V_130 |=
F_2 ( V_133 ) ;
} else if ( V_140 -> V_134 == V_158 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_11 ) ;
V_138 -> V_119 . V_128 =
F_2 ( V_159 ) ;
V_138 -> V_119 . V_130 =
F_2 ( V_131 ) ;
if ( V_140 -> V_148 & V_157 )
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
V_154 ) ;
V_120 = ( T_1 ) ( V_140 -> V_134 + V_154 )
+ sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_138 -> V_13 ) + V_10
+ V_120 ) ;
}
return V_142 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_78 * V_29 = V_2 -> V_29 ;
struct V_160 * V_161 =
& V_4 -> V_11 . V_161 ;
struct V_162 * V_163 =
& V_161 -> V_163 ;
V_58 V_164 = V_29 -> V_165 . V_164 ;
F_6 ( V_29 -> V_30 , L_12 , V_164 ) ;
V_4 -> V_6 = F_2 ( V_166 ) ;
V_161 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_161 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_163 -> V_167 . type = F_2 ( V_168 ) ;
memcpy ( V_163 -> V_169 , V_29 -> V_165 . V_169 ,
sizeof( V_163 -> V_169 ) ) ;
V_163 -> V_167 . V_170 =
F_2 ( ( V_164 *
sizeof( struct V_171 ) )
+ sizeof( V_163 -> V_169 ) ) ;
if ( V_164 ) {
memcpy ( V_163 -> V_172 , V_29 -> V_165 . V_172 ,
V_164 * sizeof( struct
V_171 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_161 -> V_13 ) +
F_8 ( V_163 -> V_167 . V_170 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_161 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_173 )
{
struct V_174 * V_175 =
& V_4 -> V_11 . V_176 ;
T_3 V_177 = F_8 ( V_175 -> V_177 ) ;
V_4 -> V_6 = F_2 ( V_178 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_174 )
+ V_10 ) ;
if ( V_5 == V_28 ) {
if ( ( V_2 -> V_29 -> V_179 & V_180 ) ||
( V_2 -> V_29 -> V_179 & V_181 ) )
V_175 -> V_177 =
F_2 ( V_182 ) ;
V_177 = F_8 ( V_175 -> V_177 ) ;
F_23 ( V_177 , V_2 -> V_29 -> V_183 ) ;
V_175 -> V_184 = F_2 ( * V_173 ) ;
}
V_175 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_185 )
{
struct V_186 * V_187 =
& ( V_4 -> V_11 . V_188 ) ;
V_4 -> V_6 = F_2 ( V_189 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_186 ) +
V_10 ) ;
V_4 -> V_98 = 0 ;
V_187 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_185 )
V_187 -> V_185 = F_2 ( * V_185 ) ;
else
V_187 -> V_185 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_190 )
{
struct V_191 * V_192 = V_190 ;
switch ( F_8 ( V_4 -> V_6 ) ) {
case V_193 :
{
struct V_194 * V_195 ;
V_4 -> V_8 = F_2 ( sizeof( * V_195 ) + V_10 ) ;
V_195 = (struct V_194 * ) & V_4 ->
V_11 . V_195 ;
V_195 -> V_13 = F_2 ( V_5 ) ;
V_195 -> V_196 =
F_2 ( ( T_1 ) F_26 ( V_192 -> V_196 ) ) ;
V_195 -> V_44 = V_192 -> V_44 ;
break;
}
case V_197 :
{
struct V_198 * V_199 ;
V_4 -> V_8 = F_2 ( sizeof( * V_199 ) + V_10 ) ;
V_199 = (struct V_198 * )
& V_4 -> V_11 . V_199 ;
V_199 -> V_13 = F_2 ( V_5 ) ;
V_199 -> V_196 =
F_2 ( ( T_1 ) F_26 ( V_192 -> V_196 ) ) ;
V_199 -> V_44 = ( V_58 ) F_26 ( V_192 -> V_44 ) ;
break;
}
case V_200 :
{
struct V_201 * V_202 ;
V_4 -> V_8 = F_2 ( sizeof( * V_202 ) + V_10 ) ;
V_202 = (struct V_201 * )
& V_4 -> V_11 . V_202 ;
V_202 -> V_13 = F_2 ( V_5 ) ;
V_202 -> V_196 = F_2 ( ( T_1 ) F_26 ( V_192 -> V_196 ) ) ;
V_202 -> V_44 = ( V_58 ) F_26 ( V_192 -> V_44 ) ;
break;
}
case V_203 :
{
struct V_204 * V_205 ;
V_4 -> V_8 = F_2 ( sizeof( * V_205 ) + V_10 ) ;
V_205 = (struct V_204 * ) & V_4 ->
V_11 . V_205 ;
V_205 -> V_13 = F_2 ( V_5 ) ;
V_205 -> V_196 =
F_2 ( ( T_1 ) F_26 ( V_192 -> V_196 ) ) ;
V_205 -> V_44 = ( V_58 ) F_26 ( V_192 -> V_44 ) ;
break;
}
case V_206 :
{
struct V_201 * V_207 ;
V_4 -> V_8 = F_2 ( sizeof( * V_207 ) + V_10 ) ;
V_207 = (struct V_201 * )
& V_4 -> V_11 . V_202 ;
V_207 -> V_13 = F_2 ( V_5 ) ;
V_207 -> V_196 =
F_2 ( ( T_1 ) F_26 ( V_192 -> V_196 ) ) ;
V_207 -> V_44 = ( V_58 ) F_26 ( V_192 -> V_44 ) ;
break;
}
case V_208 :
{
struct V_209 * V_210 = V_190 ;
struct V_211 * V_212 =
(struct V_211 * )
& V_4 -> V_11 . V_213 ;
V_4 -> V_8 = F_2 ( sizeof( * V_212 ) + V_10 ) ;
V_212 -> V_13 = F_2 ( V_5 ) ;
V_212 -> V_196 = V_210 -> V_196 ;
V_212 -> V_214 = V_210 -> V_214 ;
V_212 -> V_44 = 0 ;
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
struct V_215 * V_216 =
& V_4 -> V_11 . V_217 ;
struct V_218 * V_219 = V_2 -> V_29 -> V_219 ;
T_4 * V_220 ;
V_4 -> V_6 = F_2 ( V_221 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_215 ) + V_10 ) ;
V_4 -> V_98 = 0 ;
memset ( V_216 , 0 , sizeof( struct V_215 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_216 -> V_222 = ( T_2 ) ( V_219 -> V_223 ) ;
V_216 -> V_224 = ( T_2 ) ( ( ( V_225 ) V_219 -> V_223 ) >> 32 ) ;
V_216 -> V_226 = V_227 ;
V_216 -> V_228 = ( T_2 ) ( V_219 -> V_229 ) ;
V_216 -> V_230 = ( T_2 ) ( ( ( V_225 ) V_219 -> V_229 ) >> 32 ) ;
V_216 -> V_231 = V_227 ;
V_216 -> V_232 = ( T_2 ) ( V_219 -> V_233 ) ;
V_216 -> V_234 = ( T_2 ) ( ( ( V_225 ) V_219 -> V_233 ) >> 32 ) ;
V_216 -> V_235 = V_236 ;
if ( V_219 -> V_237 ) {
V_220 = F_28 ( V_219 -> V_237 ) ;
V_216 -> V_238 = ( T_2 ) * V_220 ;
V_216 -> V_239 = ( T_2 ) ( ( ( V_225 ) * V_220 ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_13 ,
V_216 -> V_238 ) ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_2 , T_3 V_240 ,
T_1 V_5 , T_2 V_32 ,
void * V_190 , void * V_241 )
{
struct V_3 * V_242 = V_241 ;
int V_142 = 0 ;
switch ( V_240 ) {
case V_243 :
V_142 = F_30 ( V_2 , V_242 ) ;
break;
case V_31 :
V_142 = F_3 ( V_2 , V_242 , V_5 ,
V_190 ) ;
break;
case V_96 :
V_142 = F_14 ( V_2 , V_242 ,
V_5 ) ;
break;
case V_107 :
V_142 = F_15 ( V_242 , V_5 ,
V_190 ) ;
break;
case V_56 :
V_142 = F_10 ( V_2 , V_242 , V_5 ,
V_190 ) ;
break;
case V_74 :
V_142 = F_11 ( V_242 , V_5 ,
V_190 ) ;
break;
case V_244 :
V_142 = F_31 ( V_2 , V_242 , V_5 ,
( T_3 ) V_32 , V_190 ) ;
break;
case V_83 :
V_142 = F_12 ( V_2 , V_242 , V_5 ,
(struct V_76 * ) V_190 ) ;
break;
case V_245 :
V_142 = F_32 ( V_242 , V_190 ) ;
break;
case V_246 :
V_142 = F_33 ( V_242 ) ;
break;
case V_247 :
V_142 = F_34 ( V_2 , V_242 , V_190 ) ;
break;
case V_114 :
V_142 = F_16 ( V_2 , V_242 ,
V_190 ) ;
break;
case V_248 :
V_142 = F_35 ( V_2 , V_242 ,
V_190 ) ;
break;
case V_45 :
V_142 = F_9 ( V_242 ) ;
break;
case V_249 :
V_142 = F_36 ( V_2 , V_242 ,
V_190 ) ;
break;
case V_117 :
V_142 = F_17 ( V_242 ) ;
break;
case V_7 :
V_142 = F_1 ( V_2 , V_242 , V_5 ) ;
break;
case V_37 :
V_142 = F_5 ( V_2 , V_242 , V_5 ,
V_32 , V_190 ) ;
break;
case V_250 :
V_242 -> V_6 =
F_2 ( V_250 ) ;
V_242 -> V_8 =
F_2 ( sizeof( struct V_251 ) +
V_10 ) ;
V_2 -> V_252 = 0 ;
V_142 = 0 ;
break;
case V_253 :
V_242 -> V_6 = F_2 ( V_240 ) ;
V_242 -> V_11 . V_254 . V_255 =
( V_58 ) ( * ( ( T_2 * ) V_190 ) ) ;
memcpy ( & V_242 -> V_11 , V_190 ,
sizeof( struct V_256 ) ) ;
V_242 -> V_8 =
F_2 ( sizeof( struct V_256 ) +
V_10 ) ;
V_142 = 0 ;
break;
case V_178 :
V_142 = F_22 ( V_2 , V_242 , V_5 ,
V_190 ) ;
break;
case V_257 :
if ( V_2 -> V_29 -> V_258 == V_259 )
V_2 -> V_29 -> V_258 = V_260 ;
V_242 -> V_6 = F_2 ( V_240 ) ;
V_242 -> V_8 = F_2 ( V_10 ) ;
break;
case V_261 :
V_2 -> V_29 -> V_258 = V_259 ;
V_242 -> V_6 = F_2 ( V_240 ) ;
V_242 -> V_8 = F_2 ( V_10 ) ;
break;
case V_262 :
V_142 = F_37 ( V_242 , V_190 ) ;
break;
case V_263 :
V_142 = F_38 ( V_242 , V_190 ) ;
break;
case V_264 :
V_142 = F_39 ( V_2 , V_242 , V_190 ) ;
break;
case V_144 :
V_142 = F_20 ( V_2 , V_242 ,
V_5 , V_32 ,
V_190 ) ;
break;
case V_166 :
V_142 = F_21 ( V_2 , V_242 ,
V_5 ) ;
break;
case V_265 :
V_142 = F_40 ( V_2 , V_242 , V_5 ,
V_190 ) ;
break;
case V_266 :
V_142 = F_41 ( V_242 , V_5 ,
V_190 ) ;
break;
case V_267 :
V_142 = F_42 ( V_242 , V_5 , V_190 ) ;
break;
case V_268 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_14 ) ;
V_242 -> V_6 = F_2 ( V_268 ) ;
V_242 -> V_8 =
F_2 ( sizeof( struct V_269 ) +
V_10 ) ;
V_142 = 0 ;
break;
case V_189 :
V_142 = F_24 ( V_242 , V_5 ,
V_190 ) ;
break;
case V_193 :
case V_197 :
case V_200 :
case V_203 :
case V_206 :
case V_208 :
V_142 = F_25 ( V_242 , V_5 , V_190 ) ;
break;
case V_270 :
V_242 -> V_6 = F_2 ( V_240 ) ;
if ( V_2 -> V_271 == V_272 )
V_242 -> V_11 . V_271 . V_273 =
V_274 ;
else if ( V_2 -> V_271 == V_275 )
V_242 -> V_11 . V_271 . V_273 =
V_276 ;
V_242 -> V_8 = F_2 ( sizeof( struct
V_277 ) + V_10 ) ;
V_142 = 0 ;
break;
case V_221 :
V_142 = F_27 ( V_2 , V_242 , V_5 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_15 , V_240 ) ;
V_142 = - 1 ;
break;
}
return V_142 ;
}
int F_43 ( struct V_1 * V_2 , V_58 V_278 )
{
int V_142 ;
T_1 V_185 = true ;
struct V_279 V_280 ;
struct V_281 V_282 ;
enum V_283 V_284 ;
struct V_285 V_286 ;
if ( V_278 ) {
if ( V_2 -> V_29 -> V_287 == V_288 ) {
V_142 = F_44 ( V_2 ,
V_221 ,
V_28 , 0 , NULL ) ;
if ( V_142 )
return - 1 ;
}
V_142 = F_44 ( V_2 , V_257 ,
V_28 , 0 , NULL ) ;
if ( V_142 )
return - 1 ;
V_142 = F_44 ( V_2 , V_243 ,
V_39 , 0 , NULL ) ;
if ( V_142 )
return - 1 ;
V_142 = F_44 ( V_2 ,
V_265 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_289 ) ;
if ( V_142 )
return - 1 ;
V_2 -> V_29 -> V_290 = V_291 ;
V_142 = F_44 ( V_2 ,
V_244 ,
V_292 , V_293 , NULL ) ;
if ( V_142 )
return - 1 ;
}
V_142 = F_44 ( V_2 , V_56 ,
V_39 , 0 , NULL ) ;
if ( V_142 )
return - 1 ;
V_2 -> V_294 = 0 ;
V_142 = F_44 ( V_2 , V_74 ,
V_39 , 0 , NULL ) ;
if ( V_142 )
return - 1 ;
V_142 = F_44 ( V_2 ,
V_189 ,
V_28 , 0 , & V_185 ) ;
if ( V_142 )
return - 1 ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
V_280 . V_185 = true ;
V_142 = F_44 ( V_2 , V_266 ,
V_28 , 0 ,
& V_280 ) ;
if ( V_142 )
return - 1 ;
V_142 = F_44 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_295 ) ;
if ( V_142 )
return - 1 ;
if ( V_278 ) {
V_282 . V_282 = V_296 ;
V_282 . V_297 = V_298 ;
V_142 = F_44 ( V_2 ,
V_244 ,
V_292 , V_299 ,
& V_282 ) ;
if ( V_142 )
return - 1 ;
}
V_284 = V_300 ;
V_142 = F_44 ( V_2 , V_37 ,
V_28 , V_301 , & V_284 ) ;
if ( V_142 )
F_4 ( V_2 -> V_29 -> V_30 , L_16 ) ;
V_286 . V_302 = V_303 ;
V_142 = F_44 ( V_2 , V_267 ,
V_28 , 0 , & V_286 ) ;
V_2 -> V_29 -> V_304 = V_267 ;
V_142 = - V_305 ;
return V_142 ;
}
