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
T_2 * V_33 )
{
struct V_34 * V_35 = & V_4 -> V_11 . V_36 ;
F_6 ( V_2 -> V_29 -> V_30 , L_2 , V_32 ) ;
V_4 -> V_6 = F_2 ( V_37 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_34 )
- 1 + V_10 ) ;
if ( V_5 == V_38 ) {
V_35 -> V_39 = F_2 ( V_38 ) ;
V_35 -> V_40 = F_2 ( V_41 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ V_41 ) ;
}
switch ( V_32 ) {
case V_42 :
V_35 -> V_43 = F_2 ( ( T_1 ) V_42 ) ;
if ( V_5 == V_28 ) {
V_35 -> V_39 = F_2 ( V_28 ) ;
V_35 -> V_40 = F_2 ( sizeof( T_1 ) ) ;
* ( ( V_44 * ) ( V_35 -> V_45 ) ) =
F_2 ( ( T_1 ) * V_33 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
case V_46 :
V_35 -> V_43 = F_2 ( ( T_1 ) V_46 ) ;
if ( V_5 == V_28 ) {
V_35 -> V_39 = F_2 ( V_28 ) ;
V_35 -> V_40 = F_2 ( sizeof( T_1 ) ) ;
* ( V_44 * ) ( V_35 -> V_45 ) =
F_2 ( ( T_1 ) * V_33 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
case V_47 :
V_35 -> V_43 = F_2 ( ( T_1 ) V_47 ) ;
if ( V_5 == V_28 ) {
V_35 -> V_39 = F_2 ( V_28 ) ;
V_35 -> V_40 = F_2 ( sizeof( T_1 ) ) ;
* ( ( V_44 * ) ( V_35 -> V_45 ) ) =
F_2 ( ( T_1 ) * V_33 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
case V_48 :
V_35 -> V_43 = F_2 ( ( T_1 ) V_48 ) ;
if ( V_5 == V_28 ) {
V_35 -> V_39 = F_2 ( V_28 ) ;
V_35 -> V_40 = F_2 ( sizeof( T_1 ) ) ;
* ( ( V_44 * ) ( V_35 -> V_45 ) ) =
F_2 ( ( T_1 ) * V_33 ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 )
+ sizeof( T_1 ) ) ;
}
break;
default:
break;
}
F_6 ( V_2 -> V_29 -> V_30 ,
L_3
L_4 ,
V_5 , V_32 , F_7 ( V_35 -> V_40 ) ,
F_7 ( * ( V_44 * ) V_35 -> V_45 ) ) ;
return 0 ;
}
static int
F_8 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_49 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_50 ) +
V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_51 )
{
struct V_52 * V_53 = & V_4 -> V_11 . V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
T_2 V_59 ;
V_4 -> V_6 = F_2 ( V_60 ) ;
V_53 -> V_13 = F_2 ( V_5 ) ;
V_53 -> V_61 = 0 ;
V_56 = (struct V_55 * ) ( ( V_62 * ) V_53 +
sizeof( struct V_52 ) ) ;
V_56 -> type = F_2 ( V_63 ) ;
V_56 -> V_64 = F_2 ( sizeof( struct V_55 ) -
sizeof( struct V_65 ) ) ;
if ( V_51 != NULL ) {
V_56 -> V_66 = F_2 ( V_51 [ 0 ] ) ;
V_56 -> V_67 = F_2 ( V_51 [ 1 ] ) ;
for ( V_59 = 0 ;
V_59 < sizeof( V_56 -> V_68 ) / sizeof( T_1 ) ;
V_59 ++ )
V_56 -> V_68 [ V_59 ] =
F_2 ( V_51 [ 2 + V_59 ] ) ;
} else {
V_56 -> V_66 =
F_2 ( V_2 -> V_69 [ 0 ] ) ;
V_56 -> V_67 =
F_2 ( V_2 -> V_69 [ 1 ] ) ;
for ( V_59 = 0 ;
V_59 < sizeof( V_56 -> V_68 ) / sizeof( T_1 ) ;
V_59 ++ )
V_56 -> V_68 [ V_59 ] =
F_2 ( V_2 -> V_69 [ 2 + V_59 ] ) ;
}
V_58 = (struct V_57 * ) ( ( V_62 * ) V_56 +
sizeof( struct V_55 ) ) ;
V_58 -> type = F_2 ( V_70 ) ;
V_58 -> V_64 = F_2 ( sizeof( V_58 -> V_71 ) ) ;
V_58 -> V_71 = 0 ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_52 ) +
sizeof( struct V_55 ) +
sizeof( struct V_57 ) ) ;
return 0 ;
}
static int F_10 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_72 * V_73 )
{
struct V_74 * V_75 ;
struct V_72 * V_76 = & V_4 -> V_11 . V_77 ;
V_4 -> V_6 = F_2 ( V_78 ) ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_72 ) ) ;
switch ( V_5 ) {
case V_28 :
if ( V_73 -> V_79 ) {
V_75 = (struct V_74
* ) ( ( unsigned long ) V_73 +
sizeof( struct V_72 ) ) ;
memmove ( V_76 , V_73 ,
sizeof( struct V_72 ) +
sizeof( struct V_74 ) +
V_75 -> V_64 ) ;
V_75 = (struct V_74 * ) ( ( V_62 * )
V_76 +
sizeof( struct V_72 ) ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 ) +
sizeof( struct V_74 ) +
V_75 -> V_64 ) ;
} else {
memmove ( V_76 , V_73 , sizeof( * V_73 ) ) ;
}
V_76 -> V_13 = F_2 ( V_5 ) ;
break;
case V_38 :
V_76 -> V_13 = F_2 ( V_5 ) ;
break;
}
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_80 * V_81 )
{
struct V_82 * V_29 = V_2 -> V_29 ;
struct V_83 * V_84 = & V_4 -> V_11 . V_85 ;
T_1 V_86 = false ;
if ( ! V_81 )
V_86 = true ;
V_4 -> V_6 = F_2 ( V_87 ) ;
if ( ! V_86 &&
( V_81 -> V_88
!= F_12 ( V_89 ) )
&& ( ( V_29 -> V_90 > 0 )
&& ( V_29 -> V_90 <= V_91 ) ) ) {
F_6 ( V_29 -> V_30 ,
L_5 ,
V_29 -> V_90 ) ;
memcpy ( ( ( V_62 * ) V_84 ) +
sizeof( struct V_83 ) ,
V_29 -> V_92 , V_29 -> V_90 ) ;
V_4 -> V_8 = F_2 ( V_29 -> V_90 +
sizeof( struct V_83 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( V_10 + sizeof( struct
V_83 ) ) ;
}
if ( V_86 ) {
V_84 -> V_13 = F_2 ( V_93 ) ;
V_84 -> V_11 . V_86 . V_94 = V_95 ;
} else {
V_84 -> V_13 = F_2 ( V_96 ) ;
V_84 -> V_11 . V_97 . V_88 = V_81 -> V_88 ;
V_84 -> V_11 . V_97 . V_98 = V_81 -> V_98 ;
V_84 -> V_11 . V_97 . V_99 = V_81 -> V_99 ;
F_6 ( V_29 -> V_30 ,
L_6 ,
V_84 -> V_11 . V_97 . V_88 ,
V_84 -> V_11 . V_97 . V_98 ,
V_84 -> V_11 . V_97 . V_99 ) ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_100 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_101 ) +
V_10 ) ;
V_4 -> V_102 = 0 ;
V_4 -> V_11 . V_103 . V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 )
memcpy ( V_4 -> V_11 . V_103 . V_103 , V_2 -> V_104 ,
V_105 ) ;
return 0 ;
}
static int
F_14 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 = & V_4 -> V_11 . V_110 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_108 ) +
V_10 ) ;
V_4 -> V_6 = F_2 ( V_111 ) ;
V_109 -> V_13 = F_2 ( V_5 ) ;
V_109 -> V_112 =
F_2 ( ( T_1 ) V_107 -> V_113 ) ;
memcpy ( V_109 -> V_114 , V_107 -> V_114 ,
V_107 -> V_113 * V_105 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
V_62 * V_115 )
{
struct V_116 * V_117 = & V_4 -> V_11 . V_117 ;
V_4 -> V_6 = F_2 ( V_118 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_116 )
+ V_10 ) ;
memcpy ( V_117 -> V_103 , V_115 , V_105 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_7 , V_117 -> V_103 ) ;
V_117 -> V_119 = F_2 ( V_120 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_121 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_122 * V_123 ,
T_1 * V_124 )
{
int V_125 ;
V_62 V_59 ;
for ( V_59 = 0 ; V_59 < V_126 ; V_59 ++ ) {
if ( ( V_2 -> V_127 [ V_59 ] . V_128 == V_129 ) ||
( V_2 -> V_127 [ V_59 ] . V_128 == V_130 ) ) {
V_123 -> type =
F_2 ( V_131 ) ;
#define F_18 8
V_123 -> V_64 = F_2 ( ( T_1 )
( V_2 -> V_127 [ V_59 ] .
V_128 +
F_18 ) ) ;
V_123 -> V_132 =
F_2 ( V_133 ) ;
V_123 -> V_134 =
F_2 ( V_135 | V_136 |
V_137 ) ;
V_123 -> V_138 =
F_2 ( V_2 -> V_127 [ V_59 ] . V_128 ) ;
V_123 -> V_139 [ 0 ] = V_59 ;
if ( V_59 ==
( V_2 ->
V_140 & V_141 ) )
V_123 -> V_139 [ 1 ] = 1 ;
else
V_123 -> V_139 [ 1 ] = 0 ;
memmove ( & V_123 -> V_139 [ 2 ] ,
V_2 -> V_127 [ V_59 ] . V_142 ,
V_2 -> V_127 [ V_59 ] . V_128 ) ;
V_125 = V_2 -> V_127 [ V_59 ] . V_128 +
F_18 +
sizeof( struct V_65 ) ;
* V_124 += ( T_1 ) V_125 ;
V_123 =
(struct V_122 * )
( ( V_62 * ) V_123 +
V_125 ) ;
} else if ( ! V_2 -> V_127 [ V_59 ] . V_128 ) {
continue;
} else {
F_4 ( V_2 -> V_29 -> V_30 ,
L_8 ,
( V_59 + 1 ) , V_2 -> V_127 [ V_59 ] . V_128 ) ;
return - 1 ;
}
}
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_32 ,
struct V_143 * V_144 )
{
struct V_145 * V_142 =
& V_4 -> V_11 . V_142 ;
T_1 V_124 = 0 ;
int V_146 = 0 ;
const V_62 V_147 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_4 -> V_6 = F_2 ( V_148 ) ;
V_142 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_38 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_142 -> V_13 ) + V_10 ) ;
return V_146 ;
}
if ( ! V_144 ) {
memset ( & V_142 -> V_123 , 0 ,
( V_126 *
sizeof( struct V_122 ) ) ) ;
V_146 = F_17 ( V_2 ,
& V_142 -> V_123 ,
& V_124 ) ;
V_4 -> V_8 = F_2 ( V_124 +
sizeof( V_142 -> V_13 ) + V_10 ) ;
return V_146 ;
} else
memset ( & V_142 -> V_123 , 0 ,
sizeof( struct V_122 ) ) ;
if ( V_144 -> V_149 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_9 ) ;
V_142 -> V_123 . V_132 =
F_2 ( V_150 ) ;
if ( V_32 == V_151 )
V_142 -> V_123 . V_134 =
F_2 ( V_135 ) ;
else
V_142 -> V_123 . V_134 =
F_2 ( ! V_135 ) ;
V_142 -> V_123 . V_139 [ 0 ] = V_144 -> V_152 ;
if ( ! V_2 -> V_153 . V_154 )
V_142 -> V_123 . V_139 [ 1 ] = 1 ;
else
V_142 -> V_123 . V_139 [ 1 ] = 0 ;
if ( 0 != memcmp ( V_144 -> V_103 , V_147 , sizeof( V_147 ) ) ) {
V_142 -> V_123 . V_134 |=
F_2 ( V_136 ) ;
} else {
V_142 -> V_123 . V_134 |=
F_2 ( V_137 ) ;
V_2 -> V_153 . V_154 = true ;
}
V_142 -> V_123 . type =
F_2 ( V_131 ) ;
V_142 -> V_123 . V_138 =
F_2 ( V_155 ) ;
memcpy ( & V_142 -> V_123 . V_139 [ 2 ] ,
V_144 -> V_142 , V_144 -> V_138 ) ;
memcpy ( & V_142 -> V_123 . V_139 [ 2 + V_144 -> V_138 ] ,
V_144 -> V_156 , V_157 ) ;
V_142 -> V_123 . V_64 =
F_2 ( V_155 + V_158 ) ;
V_124 = ( V_155 + V_158 ) +
sizeof( struct V_65 ) ;
V_4 -> V_8 = F_2 ( V_124 +
sizeof( V_142 -> V_13 ) + V_10 ) ;
return V_146 ;
}
if ( V_144 -> V_138 == V_159 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_10 ) ;
V_142 -> V_123 . V_132 =
F_2 ( V_160 ) ;
if ( V_32 == V_151 )
V_142 -> V_123 . V_134 =
F_2 ( V_135 ) ;
else
V_142 -> V_123 . V_134 =
F_2 ( ! V_135 ) ;
if ( V_144 -> V_152 & V_161 )
V_142 -> V_123 . V_134 |=
F_2 ( V_136 ) ;
else
V_142 -> V_123 . V_134 |=
F_2 ( V_137 ) ;
} else if ( V_144 -> V_138 == V_162 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_11 ) ;
V_142 -> V_123 . V_132 =
F_2 ( V_163 ) ;
V_142 -> V_123 . V_134 =
F_2 ( V_135 ) ;
if ( V_144 -> V_152 & V_161 )
V_142 -> V_123 . V_134 |=
F_2 ( V_136 ) ;
else
V_142 -> V_123 . V_134 |=
F_2 ( V_137 ) ;
}
if ( V_142 -> V_123 . V_132 ) {
V_142 -> V_123 . type =
F_2 ( V_131 ) ;
V_142 -> V_123 . V_138 =
F_2 ( ( T_1 ) V_144 -> V_138 ) ;
memcpy ( V_142 -> V_123 . V_139 , V_144 -> V_142 ,
V_144 -> V_138 ) ;
V_142 -> V_123 . V_64 =
F_2 ( ( T_1 ) V_144 -> V_138 +
V_158 ) ;
V_124 = ( T_1 ) ( V_144 -> V_138 + V_158 )
+ sizeof( struct V_65 ) ;
V_4 -> V_8 = F_2 ( V_124 +
sizeof( V_142 -> V_13 ) + V_10 ) ;
}
return V_146 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_82 * V_29 = V_2 -> V_29 ;
struct V_164 * V_165 =
& V_4 -> V_11 . V_165 ;
struct V_166 * V_167 =
& V_165 -> V_167 ;
V_62 V_168 = V_29 -> V_169 . V_168 ;
F_6 ( V_29 -> V_30 , L_12 , V_168 ) ;
V_4 -> V_6 = F_2 ( V_170 ) ;
V_165 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_38 ) {
V_4 -> V_8 = F_2 ( sizeof( V_165 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_167 -> V_171 . type = F_2 ( V_172 ) ;
memcpy ( V_167 -> V_173 , V_29 -> V_169 . V_173 ,
sizeof( V_167 -> V_173 ) ) ;
V_167 -> V_171 . V_174 = F_2 ( ( V_168 *
sizeof( struct V_175 ) ) +
sizeof( V_167 -> V_173 ) ) ;
if ( V_168 ) {
memcpy ( V_167 -> V_176 , V_29 -> V_169 . V_176 ,
V_168 *
sizeof( struct V_175 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_165 -> V_13 ) +
F_7 ( V_167 -> V_171 . V_174 ) +
sizeof( struct V_65 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_165 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_177 )
{
struct V_178 * V_179 =
& V_4 -> V_11 . V_180 ;
T_3 V_181 = F_7 ( V_179 -> V_181 ) ;
V_4 -> V_6 = F_2 ( V_182 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_178 )
+ V_10 ) ;
if ( V_5 == V_28 ) {
if ( ( V_2 -> V_29 -> V_183 & V_184 )
|| ( V_2 -> V_29 -> V_183 & V_185 ) )
V_179 -> V_181 =
F_2 ( V_186 ) ;
V_181 = F_7 ( V_179 -> V_181 ) ;
F_22 ( V_181 , V_2 -> V_29 -> V_187 ) ;
V_179 -> V_188 = F_2 ( * V_177 ) ;
}
V_179 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_189 )
{
struct V_190 * V_191 =
& ( V_4 -> V_11 . V_192 ) ;
V_4 -> V_6 = F_2 ( V_193 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_190 ) +
V_10 ) ;
V_4 -> V_102 = 0 ;
V_191 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_189 )
V_191 -> V_189 = F_2 ( * V_189 ) ;
else
V_191 -> V_189 = 0 ;
break;
case V_38 :
default:
break;
}
return 0 ;
}
static int F_24 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_194 )
{
struct V_195 * V_196 = V_194 ;
switch ( F_7 ( V_4 -> V_6 ) ) {
case V_197 :
{
struct V_198 * V_199 ;
V_4 -> V_8 = F_2 ( sizeof( * V_199 ) + V_10 ) ;
V_199 = (struct V_198 * ) & V_4 ->
V_11 . V_199 ;
V_199 -> V_13 = F_2 ( V_5 ) ;
V_199 -> V_200 =
F_2 ( ( T_1 ) F_25 ( V_196 -> V_200 ) ) ;
V_199 -> V_45 = V_196 -> V_45 ;
break;
}
case V_201 :
{
struct V_202 * V_203 ;
V_4 -> V_8 = F_2 ( sizeof( * V_203 ) + V_10 ) ;
V_203 = (struct V_202 * ) & V_4 ->
V_11 . V_203 ;
V_203 -> V_13 = F_2 ( V_5 ) ;
V_203 -> V_200 =
F_2 ( ( T_1 ) F_25 ( V_196 -> V_200 ) ) ;
V_203 -> V_45 = ( V_62 ) F_25 ( V_196 -> V_45 ) ;
break;
}
case V_204 :
{
struct V_205 * V_206 ;
V_4 -> V_8 = F_2 ( sizeof( * V_206 ) + V_10 ) ;
V_206 = (struct V_205 * ) & V_4 ->
V_11 . V_206 ;
V_206 -> V_13 = F_2 ( V_5 ) ;
V_206 -> V_200 =
F_2 ( ( T_1 ) F_25 ( V_196 -> V_200 ) ) ;
V_206 -> V_45 = ( V_62 ) F_25 ( V_196 -> V_45 ) ;
break;
}
case V_207 :
{
struct V_208 * V_209 ;
V_4 -> V_8 = F_2 ( sizeof( * V_209 ) + V_10 ) ;
V_209 = (struct V_208 * ) & V_4 ->
V_11 . V_209 ;
V_209 -> V_13 = F_2 ( V_5 ) ;
V_209 -> V_200 =
F_2 ( ( T_1 ) F_25 ( V_196 -> V_200 ) ) ;
V_209 -> V_45 = ( V_62 ) F_25 ( V_196 -> V_45 ) ;
break;
}
case V_210 :
{
struct V_205 * V_211 ;
V_4 -> V_8 = F_2 ( sizeof( * V_211 ) + V_10 ) ;
V_211 = (struct V_205 * ) & V_4 ->
V_11 . V_206 ;
V_211 -> V_13 = F_2 ( V_5 ) ;
V_211 -> V_200 =
F_2 ( ( T_1 ) F_25 ( V_196 -> V_200 ) ) ;
V_211 -> V_45 = ( V_62 ) F_25 ( V_196 -> V_45 ) ;
break;
}
case V_212 :
{
struct V_213 * V_214 = V_194 ;
struct V_215 * V_216 =
(struct V_215 * )
& V_4 -> V_11 . V_217 ;
V_4 -> V_8 = F_2 ( sizeof( * V_216 ) + V_10 ) ;
V_216 -> V_13 = F_2 ( V_5 ) ;
V_216 -> V_200 = V_214 -> V_200 ;
V_216 -> V_218 = V_214 -> V_218 ;
V_216 -> V_45 = 0 ;
break;
}
default:
return - 1 ;
}
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_13 )
{
struct V_219 * V_220 =
& V_4 -> V_11 . V_221 ;
struct V_222 * V_223 = V_2 -> V_29 -> V_223 ;
T_4 * V_224 ;
V_4 -> V_6 = F_2 ( V_225 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_219 ) + V_10 ) ;
V_4 -> V_102 = 0 ;
memset ( V_220 , 0 , sizeof( struct V_219 ) ) ;
if ( V_13 == V_28 ) {
V_220 -> V_226 = ( T_2 ) ( V_223 -> V_227 ) ;
V_220 -> V_228 =
( T_2 ) ( ( ( V_229 ) V_223 -> V_227 ) >> 32 ) ;
V_220 -> V_230 = V_231 ;
V_220 -> V_232 = ( T_2 ) ( V_223 -> V_233 ) ;
V_220 -> V_234 =
( T_2 ) ( ( ( V_229 ) V_223 -> V_233 ) >> 32 ) ;
V_220 -> V_235 = V_231 ;
V_220 -> V_236 =
( T_2 ) ( V_223 -> V_237 ) ;
V_220 -> V_238 =
( T_2 ) ( ( ( V_229 ) V_223 -> V_237 ) >> 32 ) ;
V_220 -> V_239 = V_240 ;
if ( V_223 -> V_241 ) {
V_224 = F_27 ( V_223 -> V_241 ) ;
V_220 -> V_242 = ( T_2 ) * V_224 ;
V_220 -> V_243 =
( T_2 ) ( ( ( V_229 ) * V_224 ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_13
L_14 , V_220 -> V_242 ) ;
}
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 , T_3 V_244 ,
T_1 V_5 , T_2 V_32 ,
void * V_194 , void * V_245 )
{
struct V_3 * V_246 = V_245 ;
int V_146 = 0 ;
switch ( V_244 ) {
case V_247 :
V_146 = F_29 ( V_2 , V_246 ) ;
break;
case V_31 :
V_146 = F_3 ( V_2 , V_246 , V_5 ,
V_194 ) ;
break;
case V_100 :
V_146 = F_13 ( V_2 , V_246 ,
V_5 ) ;
break;
case V_111 :
V_146 = F_14 ( V_246 , V_5 ,
V_194 ) ;
break;
case V_60 :
V_146 = F_9 ( V_2 , V_246 , V_5 ,
V_194 ) ;
break;
case V_78 :
V_146 = F_10 ( V_246 , V_5 ,
V_194 ) ;
break;
case V_248 :
V_146 = F_30 ( V_2 , V_246 , V_5 ,
( T_3 ) V_32 , V_194 ) ;
break;
case V_87 :
V_146 = F_11 ( V_2 , V_246 , V_5 ,
(struct V_80 * ) V_194 ) ;
break;
case V_249 :
V_146 = F_31 ( V_246 , V_194 ) ;
break;
case V_250 :
V_146 = F_32 ( V_246 ) ;
break;
case V_251 :
V_146 = F_33 ( V_2 , V_246 , V_194 ) ;
break;
case V_118 :
V_146 = F_15 ( V_2 , V_246 ,
V_194 ) ;
break;
case V_252 :
V_146 = F_34 ( V_2 , V_246 ,
V_194 ) ;
break;
case V_49 :
V_146 = F_8 ( V_246 ) ;
break;
case V_253 :
V_146 = F_35 ( V_2 , V_246 ,
V_194 ) ;
break;
case V_121 :
V_146 = F_16 ( V_246 ) ;
break;
case V_7 :
V_146 = F_1 ( V_2 , V_246 , V_5 ) ;
break;
case V_37 :
V_146 = F_5 ( V_2 , V_246 , V_5 ,
V_32 , V_194 ) ;
break;
case V_254 :
V_246 -> V_6 =
F_2 ( V_254 ) ;
V_246 -> V_8 =
F_2 ( sizeof( struct V_255 ) +
V_10 ) ;
V_2 -> V_256 = 0 ;
V_146 = 0 ;
break;
case V_257 :
V_246 -> V_6 = F_2 ( V_244 ) ;
V_246 -> V_11 . V_258 . V_259 =
( V_62 ) ( * ( ( T_2 * ) V_194 ) ) ;
memcpy ( & V_246 -> V_11 , V_194 ,
sizeof( struct V_260 ) ) ;
V_246 -> V_8 =
F_2 ( sizeof( struct V_260 ) +
V_10 ) ;
V_146 = 0 ;
break;
case V_182 :
V_146 = F_21 ( V_2 , V_246 , V_5 ,
V_194 ) ;
break;
case V_261 :
if ( V_2 -> V_29 -> V_262 == V_263 )
V_2 -> V_29 -> V_262 = V_264 ;
V_246 -> V_6 = F_2 ( V_244 ) ;
V_246 -> V_8 = F_2 ( V_10 ) ;
break;
case V_265 :
V_2 -> V_29 -> V_262 = V_263 ;
V_246 -> V_6 = F_2 ( V_244 ) ;
V_246 -> V_8 = F_2 ( V_10 ) ;
break;
case V_266 :
V_146 = F_36 ( V_246 , V_194 ) ;
break;
case V_267 :
V_146 = F_37 ( V_246 , V_194 ) ;
break;
case V_268 :
V_146 = F_38 ( V_2 , V_246 , V_194 ) ;
break;
case V_148 :
V_146 = F_19 ( V_2 , V_246 ,
V_5 , V_32 ,
V_194 ) ;
break;
case V_170 :
V_146 = F_20 ( V_2 , V_246 ,
V_5 ) ;
break;
case V_269 :
V_146 = F_39 ( V_2 , V_246 , V_5 ,
V_194 ) ;
break;
case V_270 :
V_146 = F_40 ( V_246 , V_5 ,
V_194 ) ;
break;
case V_271 :
V_146 = F_41 ( V_246 , V_5 ,
V_194 ) ;
break;
case V_272 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_15 ) ;
V_246 -> V_6 = F_2 ( V_272 ) ;
V_246 -> V_8 =
F_2 ( sizeof( struct V_273 ) +
V_10 ) ;
V_146 = 0 ;
break;
case V_193 :
V_146 = F_23 ( V_246 , V_5 ,
V_194 ) ;
break;
case V_197 :
case V_201 :
case V_204 :
case V_207 :
case V_210 :
case V_212 :
V_146 = F_24 ( V_246 , V_5 , V_194 ) ;
break;
case V_274 :
V_246 -> V_6 = F_2 ( V_244 ) ;
if ( V_2 -> V_275 == V_276 )
V_246 -> V_11 . V_275 . V_277 =
V_278 ;
else if ( V_2 -> V_275 == V_279 )
V_246 -> V_11 . V_275 . V_277 =
V_280 ;
V_246 -> V_8 = F_2 ( sizeof( struct
V_281 ) + V_10 ) ;
V_146 = 0 ;
break;
case V_225 :
V_146 = F_26 ( V_2 , V_246 , V_5 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_16 , V_244 ) ;
V_146 = - 1 ;
break;
}
return V_146 ;
}
int F_42 ( struct V_1 * V_2 , V_62 V_282 )
{
int V_146 ;
T_1 V_189 = true ;
struct V_283 V_284 ;
struct V_285 V_286 ;
enum V_287 V_288 ;
struct V_289 V_290 ;
if ( V_282 ) {
if ( V_2 -> V_29 -> V_291 == V_292 ) {
V_146 = F_43 ( V_2 ,
V_225 ,
V_28 , 0 , NULL ) ;
if ( V_146 )
return - 1 ;
}
V_146 = F_43 ( V_2 , V_261 ,
V_28 , 0 , NULL ) ;
if ( V_146 )
return - 1 ;
V_146 = F_43 ( V_2 , V_247 ,
V_38 , 0 , NULL ) ;
if ( V_146 )
return - 1 ;
V_146 = F_43 ( V_2 ,
V_269 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_293 ) ;
if ( V_146 )
return - 1 ;
V_2 -> V_29 -> V_294 = V_295 ;
V_146 = F_43 ( V_2 ,
V_248 ,
V_296 , V_297 , NULL ) ;
if ( V_146 )
return - 1 ;
}
V_146 = F_43 ( V_2 , V_60 ,
V_38 , 0 , NULL ) ;
if ( V_146 )
return - 1 ;
V_2 -> V_298 = 0 ;
V_146 = F_43 ( V_2 , V_78 ,
V_38 , 0 , NULL ) ;
if ( V_146 )
return - 1 ;
V_146 = F_43 ( V_2 ,
V_193 ,
V_28 , 0 , & V_189 ) ;
if ( V_146 )
return - 1 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 . V_189 = true ;
V_146 = F_43 ( V_2 , V_270 ,
V_28 , 0 ,
& V_284 ) ;
if ( V_146 )
return - 1 ;
V_146 = F_43 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_299 ) ;
if ( V_146 )
return - 1 ;
if ( V_282 ) {
V_286 . V_286 = V_300 ;
V_286 . V_301 = V_302 ;
V_146 = F_43 ( V_2 ,
V_248 ,
V_296 , V_303 ,
& V_286 ) ;
if ( V_146 )
return - 1 ;
}
V_288 = V_304 ;
V_146 = F_43 ( V_2 , V_37 ,
V_28 , V_48 , & V_288 ) ;
if ( V_146 )
F_4 ( V_2 -> V_29 -> V_30 , L_17 ) ;
V_290 . V_305 = V_306 ;
V_146 = F_43 ( V_2 , V_271 ,
V_28 , 0 , & V_290 ) ;
V_2 -> V_29 -> V_307 = V_271 ;
V_146 = - V_308 ;
return V_146 ;
}
