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
V_4 -> V_6 = F_2 ( V_168 ) ;
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
if ( V_162 -> V_169 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_9 ) ;
V_160 -> V_141 . V_150 =
F_2 ( V_170 ) ;
if ( V_32 == V_171 )
V_160 -> V_141 . V_152 =
F_2 ( V_153 ) ;
else
V_160 -> V_141 . V_152 =
F_2 ( ! V_153 ) ;
V_160 -> V_141 . V_157 [ 0 ] = V_162 -> V_172 ;
if ( ! V_2 -> V_173 . V_174 )
V_160 -> V_141 . V_157 [ 1 ] = 1 ;
else
V_160 -> V_141 . V_157 [ 1 ] = 0 ;
if ( ! F_23 ( V_162 -> V_121 ) ) {
V_160 -> V_141 . V_152 |=
F_2 ( V_154 ) ;
} else {
V_160 -> V_141 . V_152 |=
F_2 ( V_155 ) ;
V_2 -> V_173 . V_174 = true ;
}
V_160 -> V_141 . type =
F_2 ( V_149 ) ;
V_160 -> V_141 . V_156 =
F_2 ( V_175 ) ;
memcpy ( & V_160 -> V_141 . V_157 [ 2 ] ,
V_162 -> V_160 , V_162 -> V_156 ) ;
memcpy ( & V_160 -> V_141 . V_157 [ 2 + V_162 -> V_156 ] ,
V_162 -> V_176 , V_177 ) ;
V_160 -> V_141 . V_60 =
F_2 ( V_175 + V_178 ) ;
V_142 = ( V_175 + V_178 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_160 -> V_13 )
+ V_10 + V_142 ) ;
return V_167 ;
}
if ( V_162 -> V_156 == V_179 ) {
if ( V_162 -> V_180 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_10 ) ;
V_160 -> V_141 . V_150 =
F_2 ( V_181 ) ;
if ( V_32 == V_171 )
V_160 -> V_141 . V_152 =
F_2 ( V_153 ) ;
else
V_160 -> V_141 . V_152 =
F_2 ( ! V_153 ) ;
V_160 -> V_141 . V_152 |=
F_2 ( V_182 ) ;
} else {
F_6 ( V_2 -> V_29 -> V_30 , L_11 ) ;
V_160 -> V_141 . V_150 =
F_2 ( V_183 ) ;
if ( V_32 == V_171 )
V_160 -> V_141 . V_152 =
F_2 ( V_153 ) ;
else
V_160 -> V_141 . V_152 =
F_2 ( ! V_153 ) ;
if ( V_162 -> V_172 & V_184 )
V_160 -> V_141 . V_152 |=
F_2 ( V_154 ) ;
else
V_160 -> V_141 . V_152 |=
F_2 ( V_155 ) ;
}
} else if ( V_162 -> V_156 == V_185 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_12 ) ;
V_160 -> V_141 . V_150 =
F_2 ( V_186 ) ;
V_160 -> V_141 . V_152 =
F_2 ( V_153 ) ;
if ( V_162 -> V_172 & V_184 )
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
V_178 ) ;
V_142 = ( T_1 ) ( V_162 -> V_156 + V_178 )
+ sizeof( struct V_61 ) ;
if ( F_8 ( V_160 -> V_141 . V_150 ) ==
V_181 ) {
struct V_187 * V_188 =
( void * ) V_160 -> V_141 . V_157 ;
memcpy ( V_188 -> V_189 , V_162 -> V_176 , V_190 ) ;
memcpy ( V_188 -> V_157 , V_162 -> V_160 ,
V_191 ) ;
V_142 = sizeof( struct V_187 ) ;
V_160 -> V_141 . V_156 =
F_2 ( V_142 ) ;
V_142 += V_178 ;
V_160 -> V_141 . V_60 =
F_2 ( V_142 ) ;
V_142 += sizeof( struct V_61 ) ;
}
V_4 -> V_8 = F_2 ( sizeof( V_160 -> V_13 ) + V_10
+ V_142 ) ;
if ( V_2 -> V_192 == V_193 ) {
V_165 = ( void * ) ( ( V_58 * ) & V_160 -> V_141 +
V_142 ) ;
V_165 -> V_194 . type =
F_2 ( V_195 ) ;
V_165 -> V_194 . V_196 = F_2 ( V_123 ) ;
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
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_100 * V_29 = V_2 -> V_29 ;
struct V_197 * V_198 =
& V_4 -> V_11 . V_198 ;
struct V_199 * V_200 =
& V_198 -> V_200 ;
V_58 V_201 = V_29 -> V_202 . V_201 ;
F_6 ( V_29 -> V_30 , L_13 , V_201 ) ;
V_4 -> V_6 = F_2 ( V_203 ) ;
V_198 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_198 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_200 -> V_194 . type = F_2 ( V_204 ) ;
memcpy ( V_200 -> V_205 , V_29 -> V_202 . V_205 ,
sizeof( V_200 -> V_205 ) ) ;
V_200 -> V_194 . V_196 =
F_2 ( ( V_201 *
sizeof( struct V_206 ) )
+ sizeof( V_200 -> V_205 ) ) ;
if ( V_201 ) {
memcpy ( V_200 -> V_207 , V_29 -> V_202 . V_207 ,
V_201 * sizeof( struct
V_206 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_198 -> V_13 ) +
F_8 ( V_200 -> V_194 . V_196 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_198 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_208 )
{
struct V_209 * V_210 =
& ( V_4 -> V_11 . V_211 ) ;
V_4 -> V_6 = F_2 ( V_212 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_209 ) +
V_10 ) ;
V_4 -> V_120 = 0 ;
V_210 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_208 )
V_210 -> V_208 = F_2 ( * V_208 ) ;
else
V_210 -> V_208 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int F_26 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_76 )
{
struct V_213 * V_214 = V_76 ;
switch ( F_8 ( V_4 -> V_6 ) ) {
case V_215 :
{
struct V_216 * V_217 ;
V_4 -> V_8 = F_2 ( sizeof( * V_217 ) + V_10 ) ;
V_217 = & V_4 -> V_11 . V_217 ;
V_217 -> V_13 = F_2 ( V_5 ) ;
V_217 -> V_218 =
F_2 ( ( T_1 ) F_27 ( V_214 -> V_218 ) ) ;
V_217 -> V_44 = V_214 -> V_44 ;
break;
}
case V_219 :
{
struct V_220 * V_221 ;
V_4 -> V_8 = F_2 ( sizeof( * V_221 ) + V_10 ) ;
V_221 = & V_4 -> V_11 . V_221 ;
V_221 -> V_13 = F_2 ( V_5 ) ;
V_221 -> V_218 =
F_2 ( ( T_1 ) F_27 ( V_214 -> V_218 ) ) ;
V_221 -> V_44 = ( V_58 ) F_27 ( V_214 -> V_44 ) ;
break;
}
case V_222 :
{
struct V_223 * V_224 ;
V_4 -> V_8 = F_2 ( sizeof( * V_224 ) + V_10 ) ;
V_224 = & V_4 -> V_11 . V_224 ;
V_224 -> V_13 = F_2 ( V_5 ) ;
V_224 -> V_218 = F_2 ( ( T_1 ) F_27 ( V_214 -> V_218 ) ) ;
V_224 -> V_44 = ( V_58 ) F_27 ( V_214 -> V_44 ) ;
break;
}
case V_225 :
{
struct V_226 * V_227 ;
V_4 -> V_8 = F_2 ( sizeof( * V_227 ) + V_10 ) ;
V_227 = & V_4 -> V_11 . V_227 ;
V_227 -> V_13 = F_2 ( V_5 ) ;
V_227 -> V_218 =
F_2 ( ( T_1 ) F_27 ( V_214 -> V_218 ) ) ;
V_227 -> V_44 = ( V_58 ) F_27 ( V_214 -> V_44 ) ;
break;
}
case V_228 :
{
struct V_223 * V_229 ;
V_4 -> V_8 = F_2 ( sizeof( * V_229 ) + V_10 ) ;
V_229 = & V_4 -> V_11 . V_224 ;
V_229 -> V_13 = F_2 ( V_5 ) ;
V_229 -> V_218 =
F_2 ( ( T_1 ) F_27 ( V_214 -> V_218 ) ) ;
V_229 -> V_44 = ( V_58 ) F_27 ( V_214 -> V_44 ) ;
break;
}
case V_230 :
{
struct V_231 * V_232 = V_76 ;
struct V_233 * V_234 =
& V_4 -> V_11 . V_235 ;
V_4 -> V_8 = F_2 ( sizeof( * V_234 ) + V_10 ) ;
V_234 -> V_13 = F_2 ( V_5 ) ;
V_234 -> V_218 = V_232 -> V_218 ;
V_234 -> V_236 = V_232 -> V_236 ;
V_234 -> V_44 = 0 ;
break;
}
default:
return - 1 ;
}
return 0 ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_13 )
{
struct V_237 * V_238 =
& V_4 -> V_11 . V_239 ;
struct V_240 * V_241 = V_2 -> V_29 -> V_241 ;
V_4 -> V_6 = F_2 ( V_242 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_237 ) + V_10 ) ;
V_4 -> V_120 = 0 ;
memset ( V_238 , 0 , sizeof( struct V_237 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_238 -> V_243 = ( T_2 ) ( V_241 -> V_244 ) ;
V_238 -> V_245 = ( T_2 ) ( ( ( V_246 ) V_241 -> V_244 ) >> 32 ) ;
V_238 -> V_247 = V_248 ;
V_238 -> V_249 = ( T_2 ) ( V_241 -> V_250 ) ;
V_238 -> V_251 = ( T_2 ) ( ( ( V_246 ) V_241 -> V_250 ) >> 32 ) ;
V_238 -> V_252 = V_248 ;
V_238 -> V_253 = ( T_2 ) ( V_241 -> V_254 ) ;
V_238 -> V_255 = ( T_2 ) ( ( ( V_246 ) V_241 -> V_254 ) >> 32 ) ;
V_238 -> V_256 = V_257 ;
if ( V_241 -> V_258 ) {
V_238 -> V_259 =
( T_2 ) ( V_241 -> V_260 ) ;
V_238 -> V_261 =
( T_2 ) ( ( ( V_246 ) ( V_241 -> V_260 ) ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_14 ,
V_238 -> V_259 ) ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_262 * V_263 )
{
struct V_264 * V_265 = & V_4 -> V_11 . V_265 ;
struct V_266 * V_267 ;
T_1 V_268 ;
V_58 * V_269 ;
V_4 -> V_6 = F_2 ( V_270 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_264 ) +
V_10 ) ;
V_265 -> V_13 = F_2 ( V_263 -> V_13 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_15 , V_263 -> V_13 ) ;
if ( V_263 -> V_13 == V_39 )
return 0 ;
V_265 -> V_271 = F_2 ( V_263 -> V_271 ) ;
V_268 = V_263 -> V_271 ;
F_6 ( V_2 -> V_29 -> V_30 , L_16 ,
V_268 ) ;
if ( ( ( V_263 -> V_13 == V_272 ) ||
( V_263 -> V_13 == V_273 ) ) &&
( V_268 == 0 ) ) {
F_6 ( V_2 -> V_29 -> V_30 , L_17
L_18 ) ;
return - V_274 ;
}
if ( V_263 -> V_13 == V_272 )
return 0 ;
V_269 = ( ( V_58 * ) V_265 ) +
sizeof( struct V_264 ) ;
if ( V_268 & V_275 ) {
V_267 = (struct V_266 * ) V_269 ;
V_267 -> V_194 . type = F_2 ( V_276 ) ;
V_267 -> V_194 . V_196 =
F_2 ( sizeof( struct V_266 ) -
sizeof( struct V_61 ) ) ;
V_267 -> V_277 = V_263 -> V_278 . V_277 ;
V_267 -> V_279 = V_263 -> V_278 . V_279 ;
F_6 ( V_2 -> V_29 -> V_30 , L_19
L_20 ,
V_263 -> V_278 . V_277 ,
V_263 -> V_278 . V_279 ) ;
V_269 += sizeof( struct V_266 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_266 ) ) ;
}
if ( V_268 & V_280 ) {
V_267 = (struct V_266 * ) V_269 ;
V_267 -> V_194 . type = F_2 ( V_281 ) ;
V_267 -> V_194 . V_196 =
F_2 ( sizeof( struct V_266 ) -
sizeof( struct V_61 ) ) ;
V_267 -> V_277 = V_263 -> V_282 . V_277 ;
V_267 -> V_279 = V_263 -> V_282 . V_279 ;
F_6 ( V_2 -> V_29 -> V_30 , L_21
L_20 ,
V_263 -> V_282 . V_277 ,
V_263 -> V_282 . V_279 ) ;
V_269 += sizeof( struct V_266 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_266 ) ) ;
}
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 ,
struct V_283 * V_284 ,
V_58 * * V_285 )
{
struct V_286 * V_287 = V_284 -> V_287 ;
int V_55 , V_288 ;
V_58 * V_289 = * V_285 ;
for ( V_55 = 0 ; V_55 < V_290 ; V_55 ++ ) {
V_287 = & V_284 -> V_287 [ V_55 ] ;
if ( ! V_287 -> V_291 )
break;
* ( V_292 * ) V_289 = F_15 ( ( T_2 ) V_287 -> V_293 ) ;
V_289 += 4 ;
* V_289 = V_294 ;
V_289 += 1 ;
V_288 = V_287 -> V_295 [ V_296 ] ;
memcpy ( V_289 , V_287 -> V_295 , V_288 ) ;
V_289 += V_288 ;
* V_289 = V_288 ;
V_289 += 1 ;
* V_289 = V_297 ;
V_289 += 1 ;
* ( V_292 * ) V_289 = F_15 ( ( T_2 ) V_287 -> V_218 ) ;
V_289 += 4 ;
* V_289 = V_294 ;
V_289 += 1 ;
* V_289 = V_287 -> V_291 ;
V_289 += 1 ;
if ( V_287 -> V_298 ) {
* V_289 = V_287 -> V_298 ;
V_289 += 1 ;
}
if ( V_289 - * V_285 > V_299 )
return - 1 ;
}
* V_285 = V_289 ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_300 * V_301 )
{
struct V_302 * V_303 = & V_4 -> V_11 . V_303 ;
V_58 * V_269 = ( V_58 * ) V_303 ;
V_4 -> V_6 = F_2 ( V_304 ) ;
V_303 -> V_305 = F_15 ( V_301 -> V_305 ) ;
V_303 -> V_306 = F_2 ( V_301 -> V_306 ) ;
V_269 += sizeof( * V_303 ) ;
V_303 -> V_284 -> V_75 = V_301 -> V_284 -> V_75 ;
V_303 -> V_284 -> V_13 = V_301 -> V_284 -> V_13 ;
V_269 += sizeof( * ( V_303 -> V_284 ) ) ;
if ( F_30 ( V_2 , V_301 -> V_284 , & V_269 ) )
return - 1 ;
V_303 -> V_284 -> V_307 =
F_2 ( V_269 - V_303 -> V_284 -> V_308 ) ;
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_269 - ( V_58 * ) V_303 ) + V_10 ) ;
return 0 ;
}
static T_2 F_32 ( V_58 * V_309 , T_3 V_196 , V_58 * V_310 )
{
V_58 * V_311 = V_309 , * V_312 = V_310 ;
while ( V_311 - V_309 < V_196 ) {
if ( * V_311 && ( isspace ( * V_311 ) || * V_311 == '\t' ) ) {
V_311 ++ ;
continue;
}
if ( isxdigit ( * V_311 ) ) {
* V_312 ++ = F_33 ( V_311 , NULL , 16 ) ;
V_311 += 2 ;
} else {
V_311 ++ ;
}
}
return V_312 - V_310 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_313 * V_314 = & V_4 -> V_11 . V_314 ;
struct V_100 * V_29 = V_2 -> V_29 ;
T_2 V_196 , V_315 ;
V_58 * V_316 = ( V_58 * ) V_4 ;
V_315 = V_10 + sizeof( * V_314 ) ;
if ( ( V_29 -> V_317 -> V_318 ) && ( V_29 -> V_317 -> V_8 > 0 ) )
V_196 = F_32 ( ( V_58 * ) V_29 -> V_317 -> V_318 ,
V_29 -> V_317 -> V_8 ,
( V_58 * ) ( V_316 + V_315 ) ) ;
else
return - 1 ;
V_314 -> V_13 = F_2 ( V_5 ) ;
V_314 -> type = F_2 ( V_319 ) ;
V_314 -> V_320 = F_2 ( V_196 ) ;
V_4 -> V_6 = F_2 ( V_321 ) ;
V_4 -> V_8 = F_2 ( V_10 + sizeof( * V_314 ) + V_196 ) ;
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_76 )
{
struct V_322 * V_323 =
& V_4 -> V_11 . V_323 ;
struct V_324 * V_325 = V_76 ;
struct V_326 * V_188 ;
T_1 V_327 , V_328 , V_60 ;
struct V_329 * V_330 ;
V_4 -> V_6 = F_2 ( V_331 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_323 -> V_13 = F_2 ( V_5 ) ;
V_323 -> V_332 = F_2 ( V_325 -> V_332 ) ;
V_330 = V_323 -> V_330 ;
for ( V_327 = 0 ; V_327 < V_325 -> V_332 ; V_327 ++ ) {
V_330 -> V_194 . type = F_2 ( V_333 ) ;
V_330 -> V_334 =
F_2 ( V_325 -> V_330 [ V_327 ] . V_334 ) ;
V_330 -> V_335 = V_325 -> V_330 [ V_327 ] . V_335 ;
V_330 -> V_336 = V_325 -> V_330 [ V_327 ] . V_336 ;
V_60 = 0 ;
V_188 = V_330 -> V_11 ;
for ( V_328 = 0 ; V_328 < V_325 -> V_330 [ V_327 ] . V_336 ; V_328 ++ ) {
V_188 -> V_337 = V_325 -> V_330 [ V_327 ] . V_11 [ V_328 ] . V_337 ;
V_188 -> V_338 =
V_325 -> V_330 [ V_327 ] . V_11 [ V_328 ] . V_338 ;
V_188 -> V_218 =
F_2 ( V_325 -> V_330 [ V_327 ] . V_11 [ V_328 ] . V_218 ) ;
memcpy ( V_188 -> V_339 ,
V_325 -> V_330 [ V_327 ] . V_11 [ V_328 ] . V_339 ,
V_188 -> V_338 ) ;
V_60 += sizeof( struct V_326 ) ;
V_188 ++ ;
}
V_330 -> V_194 . V_196 = F_2 ( V_60 + sizeof( T_1 ) +
sizeof( V_58 ) + sizeof( V_58 ) ) ;
F_7 ( & V_4 -> V_8 , F_8 ( V_330 -> V_194 . V_196 ) +
sizeof( struct V_61 ) ) ;
V_330 = ( void * ) ( ( V_58 * ) V_330 -> V_11 + V_60 ) ;
}
F_7 ( & V_4 -> V_8 , sizeof( T_1 ) + sizeof( T_1 ) ) ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_4 V_340 ,
T_1 V_5 , T_2 V_32 ,
void * V_76 , void * V_341 )
{
struct V_3 * V_342 = V_341 ;
int V_167 = 0 ;
switch ( V_340 ) {
case V_343 :
V_167 = F_37 ( V_2 , V_342 ) ;
break;
case V_321 :
V_167 = F_34 ( V_2 , V_342 , V_5 ) ;
break;
case V_31 :
V_167 = F_3 ( V_2 , V_342 , V_5 ,
V_76 ) ;
break;
case V_118 :
V_167 = F_16 ( V_2 , V_342 ,
V_5 ) ;
break;
case V_129 :
V_167 = F_17 ( V_342 , V_5 ,
V_76 ) ;
break;
case V_56 :
V_167 = F_10 ( V_2 , V_342 , V_5 ,
V_76 ) ;
break;
case V_74 :
V_167 = F_11 ( V_342 , V_5 ,
V_76 ) ;
break;
case V_78 :
V_167 = F_12 ( V_2 , V_342 , V_5 ,
V_76 ) ;
break;
case V_85 :
V_167 = F_13 ( V_2 , V_342 , V_5 ,
V_76 ) ;
break;
case V_344 :
V_167 = F_38 ( V_2 , V_342 , V_5 ,
( T_4 ) V_32 , V_76 ) ;
break;
case V_105 :
V_167 = F_14 ( V_2 , V_342 , V_5 ,
(struct V_98 * ) V_76 ) ;
break;
case V_345 :
V_167 = F_39 ( V_342 , V_76 ) ;
break;
case V_346 :
V_167 = F_40 ( V_342 ) ;
break;
case V_347 :
V_167 = F_41 ( V_2 , V_342 , V_76 ) ;
break;
case V_136 :
V_167 = F_18 ( V_2 , V_342 ,
V_76 ) ;
break;
case V_348 :
V_167 = F_42 ( V_2 , V_342 ,
V_76 ) ;
break;
case V_45 :
V_167 = F_9 ( V_342 ) ;
break;
case V_349 :
V_167 = F_43 ( V_2 , V_342 ,
V_76 ) ;
break;
case V_139 :
V_167 = F_19 ( V_342 ) ;
break;
case V_7 :
V_167 = F_1 ( V_2 , V_342 , V_5 ) ;
break;
case V_37 :
V_167 = F_5 ( V_2 , V_342 , V_5 ,
V_32 , V_76 ) ;
break;
case V_350 :
V_342 -> V_6 =
F_2 ( V_350 ) ;
V_342 -> V_8 =
F_2 ( sizeof( struct V_351 ) +
V_10 ) ;
V_2 -> V_352 = 0 ;
V_167 = 0 ;
break;
case V_353 :
V_342 -> V_6 = F_2 ( V_340 ) ;
V_342 -> V_11 . V_354 . V_355 =
( V_58 ) ( * ( ( T_2 * ) V_76 ) ) ;
memcpy ( & V_342 -> V_11 , V_76 ,
sizeof( struct V_356 ) ) ;
V_342 -> V_8 =
F_2 ( sizeof( struct V_356 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_357 :
V_342 -> V_6 = F_2 ( V_340 ) ;
V_342 -> V_11 . V_358 . V_13 = F_2 ( V_5 ) ;
V_342 -> V_11 . V_358 . V_359 = F_15 ( * ( T_2 * ) V_76 ) ;
V_342 -> V_8 =
F_2 ( sizeof( struct V_360 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_361 :
V_342 -> V_6 = F_2 ( V_340 ) ;
memcpy ( & V_342 -> V_11 , V_76 ,
sizeof( struct V_362 ) ) ;
V_342 -> V_8 =
F_2 ( sizeof( struct V_362 ) +
V_10 ) ;
break;
case V_363 :
V_167 = F_44 ( V_2 , V_342 , V_5 , V_76 ) ;
break;
case V_364 :
V_342 -> V_6 = F_2 ( V_340 ) ;
V_342 -> V_11 . V_365 . V_13 = F_2 ( V_5 ) ;
V_342 -> V_11 . V_365 . V_75 = F_2 ( * ( T_1 * ) V_76 ) ;
V_342 -> V_8 =
F_2 ( sizeof( struct V_366 ) +
V_10 ) ;
break;
case V_367 :
if ( V_2 -> V_29 -> V_368 == V_369 )
V_2 -> V_29 -> V_368 = V_370 ;
V_342 -> V_6 = F_2 ( V_340 ) ;
V_342 -> V_8 = F_2 ( V_10 ) ;
break;
case V_371 :
V_2 -> V_29 -> V_368 = V_369 ;
V_342 -> V_6 = F_2 ( V_340 ) ;
V_342 -> V_8 = F_2 ( V_10 ) ;
break;
case V_372 :
V_167 = F_45 ( V_342 , V_76 ) ;
break;
case V_373 :
V_167 = F_46 ( V_342 , V_76 ) ;
break;
case V_374 :
V_167 = F_47 ( V_2 , V_342 , V_76 ) ;
break;
case V_168 :
V_167 = F_22 ( V_2 , V_342 ,
V_5 , V_32 ,
V_76 ) ;
break;
case V_203 :
V_167 = F_24 ( V_2 , V_342 ,
V_5 ) ;
break;
case V_375 :
V_167 = F_48 ( V_2 , V_342 , V_5 ,
V_76 ) ;
break;
case V_376 :
V_167 = F_49 ( V_342 , V_5 ,
V_76 ) ;
break;
case V_377 :
V_167 = F_50 ( V_2 , V_342 , V_5 , V_76 ) ;
break;
case V_378 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_22 ) ;
V_342 -> V_6 = F_2 ( V_378 ) ;
V_342 -> V_8 =
F_2 ( sizeof( struct V_379 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_212 :
V_167 = F_25 ( V_342 , V_5 ,
V_76 ) ;
break;
case V_215 :
case V_219 :
case V_222 :
case V_225 :
case V_228 :
case V_230 :
V_167 = F_26 ( V_342 , V_5 , V_76 ) ;
break;
case V_380 :
V_342 -> V_6 = F_2 ( V_340 ) ;
if ( V_2 -> V_381 == V_382 )
V_342 -> V_11 . V_381 . V_383 =
V_384 ;
else if ( V_2 -> V_381 == V_385 )
V_342 -> V_11 . V_381 . V_383 =
V_386 ;
else if ( V_2 -> V_381 == V_387 )
V_342 -> V_11 . V_381 . V_383 = V_388 ;
V_342 -> V_8 = F_2 ( sizeof( struct
V_389 ) + V_10 ) ;
V_167 = 0 ;
break;
case V_242 :
V_167 = F_28 ( V_2 , V_342 , V_5 ) ;
break;
case V_270 :
V_167 = F_29 ( V_2 , V_342 , V_76 ) ;
break;
case V_304 :
V_167 = F_31 ( V_2 , V_342 , V_76 ) ;
break;
case V_331 :
V_167 = F_35 ( V_2 , V_342 , V_5 ,
V_76 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_23 , V_340 ) ;
V_167 = - 1 ;
break;
}
return V_167 ;
}
int F_51 ( struct V_1 * V_2 , V_58 V_390 )
{
struct V_100 * V_29 = V_2 -> V_29 ;
int V_167 ;
T_1 V_208 = true ;
struct V_391 V_392 ;
struct V_393 V_394 ;
enum V_395 V_396 ;
struct V_397 V_398 ;
if ( V_390 ) {
if ( V_2 -> V_29 -> V_399 == V_400 ) {
V_167 = F_52 ( V_2 ,
V_242 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
}
V_167 = F_52 ( V_2 , V_367 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
if ( V_29 -> V_317 ) {
V_167 = F_52 ( V_2 , V_321 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
}
V_167 = F_52 ( V_2 , V_343 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
V_167 = F_52 ( V_2 ,
V_375 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_401 ) ;
if ( V_167 )
return - 1 ;
if ( V_2 -> V_192 != V_193 ) {
V_2 -> V_29 -> V_402 = V_403 ;
V_167 = F_52 (
V_2 , V_344 ,
V_404 , V_405 , NULL ) ;
if ( V_167 )
return - 1 ;
}
}
V_167 = F_52 ( V_2 , V_56 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
V_2 -> V_406 = 0 ;
V_167 = F_52 ( V_2 , V_78 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
if ( V_2 -> V_192 == V_407 ) {
V_167 = F_52 (
V_2 , V_212 ,
V_28 , 0 , & V_208 ) ;
if ( V_167 )
return - 1 ;
}
memset ( & V_392 , 0 , sizeof( V_392 ) ) ;
V_392 . V_208 = true ;
V_167 = F_52 ( V_2 , V_376 ,
V_28 , 0 ,
& V_392 ) ;
if ( V_167 )
return - 1 ;
V_167 = F_52 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_408 ) ;
if ( V_167 )
return - 1 ;
if ( V_390 && V_2 -> V_29 -> V_399 != V_409 &&
V_2 -> V_192 != V_193 ) {
V_394 . V_394 = V_410 ;
V_394 . V_411 = V_412 ;
V_167 = F_52 ( V_2 ,
V_344 ,
V_404 , V_413 ,
& V_394 ) ;
if ( V_167 )
return - 1 ;
}
if ( V_2 -> V_192 != V_193 ) {
V_396 = V_414 ;
V_167 = F_52 ( V_2 , V_37 ,
V_28 , V_415 ,
& V_396 ) ;
if ( V_167 )
F_4 ( V_2 -> V_29 -> V_30 ,
L_24 ) ;
}
V_2 -> V_29 -> V_416 = V_377 ;
V_398 . V_417 = V_418 ;
V_167 = F_52 ( V_2 , V_377 ,
V_28 , 0 , & V_398 ) ;
V_167 = - V_419 ;
return V_167 ;
}
