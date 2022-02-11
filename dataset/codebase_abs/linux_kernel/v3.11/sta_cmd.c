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
V_165 -> V_194 . type = F_2 ( V_195 ) ;
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
V_200 -> V_204 . type = F_2 ( V_205 ) ;
memcpy ( V_200 -> V_206 , V_29 -> V_202 . V_206 ,
sizeof( V_200 -> V_206 ) ) ;
V_200 -> V_204 . V_196 =
F_2 ( ( V_201 *
sizeof( struct V_207 ) )
+ sizeof( V_200 -> V_206 ) ) ;
if ( V_201 ) {
memcpy ( V_200 -> V_208 , V_29 -> V_202 . V_208 ,
V_201 * sizeof( struct
V_207 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_198 -> V_13 ) +
F_8 ( V_200 -> V_204 . V_196 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_198 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_209 )
{
struct V_210 * V_211 =
& ( V_4 -> V_11 . V_212 ) ;
V_4 -> V_6 = F_2 ( V_213 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_210 ) +
V_10 ) ;
V_4 -> V_120 = 0 ;
V_211 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_209 )
V_211 -> V_209 = F_2 ( * V_209 ) ;
else
V_211 -> V_209 = 0 ;
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
struct V_214 * V_215 = V_76 ;
switch ( F_8 ( V_4 -> V_6 ) ) {
case V_216 :
{
struct V_217 * V_218 ;
V_4 -> V_8 = F_2 ( sizeof( * V_218 ) + V_10 ) ;
V_218 = & V_4 -> V_11 . V_218 ;
V_218 -> V_13 = F_2 ( V_5 ) ;
V_218 -> V_219 =
F_2 ( ( T_1 ) F_27 ( V_215 -> V_219 ) ) ;
V_218 -> V_44 = V_215 -> V_44 ;
break;
}
case V_220 :
{
struct V_221 * V_222 ;
V_4 -> V_8 = F_2 ( sizeof( * V_222 ) + V_10 ) ;
V_222 = & V_4 -> V_11 . V_222 ;
V_222 -> V_13 = F_2 ( V_5 ) ;
V_222 -> V_219 =
F_2 ( ( T_1 ) F_27 ( V_215 -> V_219 ) ) ;
V_222 -> V_44 = ( V_58 ) F_27 ( V_215 -> V_44 ) ;
break;
}
case V_223 :
{
struct V_224 * V_225 ;
V_4 -> V_8 = F_2 ( sizeof( * V_225 ) + V_10 ) ;
V_225 = & V_4 -> V_11 . V_225 ;
V_225 -> V_13 = F_2 ( V_5 ) ;
V_225 -> V_219 = F_2 ( ( T_1 ) F_27 ( V_215 -> V_219 ) ) ;
V_225 -> V_44 = ( V_58 ) F_27 ( V_215 -> V_44 ) ;
break;
}
case V_226 :
{
struct V_227 * V_228 ;
V_4 -> V_8 = F_2 ( sizeof( * V_228 ) + V_10 ) ;
V_228 = & V_4 -> V_11 . V_228 ;
V_228 -> V_13 = F_2 ( V_5 ) ;
V_228 -> V_219 =
F_2 ( ( T_1 ) F_27 ( V_215 -> V_219 ) ) ;
V_228 -> V_44 = ( V_58 ) F_27 ( V_215 -> V_44 ) ;
break;
}
case V_229 :
{
struct V_224 * V_230 ;
V_4 -> V_8 = F_2 ( sizeof( * V_230 ) + V_10 ) ;
V_230 = & V_4 -> V_11 . V_225 ;
V_230 -> V_13 = F_2 ( V_5 ) ;
V_230 -> V_219 =
F_2 ( ( T_1 ) F_27 ( V_215 -> V_219 ) ) ;
V_230 -> V_44 = ( V_58 ) F_27 ( V_215 -> V_44 ) ;
break;
}
case V_231 :
{
struct V_232 * V_233 = V_76 ;
struct V_234 * V_235 =
& V_4 -> V_11 . V_236 ;
V_4 -> V_8 = F_2 ( sizeof( * V_235 ) + V_10 ) ;
V_235 -> V_13 = F_2 ( V_5 ) ;
V_235 -> V_219 = V_233 -> V_219 ;
V_235 -> V_237 = V_233 -> V_237 ;
V_235 -> V_44 = 0 ;
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
struct V_238 * V_239 =
& V_4 -> V_11 . V_240 ;
struct V_241 * V_242 = V_2 -> V_29 -> V_242 ;
V_4 -> V_6 = F_2 ( V_243 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_238 ) + V_10 ) ;
V_4 -> V_120 = 0 ;
memset ( V_239 , 0 , sizeof( struct V_238 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_239 -> V_244 = ( T_2 ) ( V_242 -> V_245 ) ;
V_239 -> V_246 = ( T_2 ) ( ( ( V_247 ) V_242 -> V_245 ) >> 32 ) ;
V_239 -> V_248 = V_249 ;
V_239 -> V_250 = ( T_2 ) ( V_242 -> V_251 ) ;
V_239 -> V_252 = ( T_2 ) ( ( ( V_247 ) V_242 -> V_251 ) >> 32 ) ;
V_239 -> V_253 = V_249 ;
V_239 -> V_254 = ( T_2 ) ( V_242 -> V_255 ) ;
V_239 -> V_256 = ( T_2 ) ( ( ( V_247 ) V_242 -> V_255 ) >> 32 ) ;
V_239 -> V_257 = V_258 ;
if ( V_242 -> V_259 ) {
V_239 -> V_260 =
( T_2 ) ( V_242 -> V_261 ) ;
V_239 -> V_262 =
( T_2 ) ( ( ( V_247 ) ( V_242 -> V_261 ) ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_14 ,
V_239 -> V_260 ) ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_263 * V_264 )
{
struct V_265 * V_266 = & V_4 -> V_11 . V_266 ;
struct V_267 * V_268 ;
T_1 V_269 ;
V_58 * V_270 ;
V_4 -> V_6 = F_2 ( V_271 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_265 ) +
V_10 ) ;
V_266 -> V_13 = F_2 ( V_264 -> V_13 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_15 , V_264 -> V_13 ) ;
if ( V_264 -> V_13 == V_39 )
return 0 ;
V_266 -> V_272 = F_2 ( V_264 -> V_272 ) ;
V_269 = V_264 -> V_272 ;
F_6 ( V_2 -> V_29 -> V_30 , L_16 ,
V_269 ) ;
if ( ( ( V_264 -> V_13 == V_273 ) ||
( V_264 -> V_13 == V_274 ) ) &&
( V_269 == 0 ) ) {
F_6 ( V_2 -> V_29 -> V_30 , L_17
L_18 ) ;
return - V_275 ;
}
if ( V_264 -> V_13 == V_273 )
return 0 ;
V_270 = ( ( V_58 * ) V_266 ) +
sizeof( struct V_265 ) ;
if ( V_269 & V_276 ) {
V_268 = (struct V_267 * ) V_270 ;
V_268 -> V_204 . type = F_2 ( V_277 ) ;
V_268 -> V_204 . V_196 =
F_2 ( sizeof( struct V_267 ) -
sizeof( struct V_61 ) ) ;
V_268 -> V_278 = V_264 -> V_279 . V_278 ;
V_268 -> V_280 = V_264 -> V_279 . V_280 ;
F_6 ( V_2 -> V_29 -> V_30 , L_19
L_20 ,
V_264 -> V_279 . V_278 ,
V_264 -> V_279 . V_280 ) ;
V_270 += sizeof( struct V_267 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_267 ) ) ;
}
if ( V_269 & V_281 ) {
V_268 = (struct V_267 * ) V_270 ;
V_268 -> V_204 . type = F_2 ( V_282 ) ;
V_268 -> V_204 . V_196 =
F_2 ( sizeof( struct V_267 ) -
sizeof( struct V_61 ) ) ;
V_268 -> V_278 = V_264 -> V_283 . V_278 ;
V_268 -> V_280 = V_264 -> V_283 . V_280 ;
F_6 ( V_2 -> V_29 -> V_30 , L_21
L_20 ,
V_264 -> V_283 . V_278 ,
V_264 -> V_283 . V_280 ) ;
V_270 += sizeof( struct V_267 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_267 ) ) ;
}
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 ,
struct V_284 * V_285 ,
V_58 * * V_286 )
{
struct V_287 * V_288 = V_285 -> V_288 ;
int V_55 , V_289 ;
V_58 * V_290 = * V_286 ;
for ( V_55 = 0 ; V_55 < V_291 ; V_55 ++ ) {
V_288 = & V_285 -> V_288 [ V_55 ] ;
if ( ! V_288 -> V_292 )
break;
* ( V_293 * ) V_290 = F_15 ( ( T_2 ) V_288 -> V_294 ) ;
V_290 += 4 ;
* V_290 = V_295 ;
V_290 += 1 ;
V_289 = V_288 -> V_296 [ V_297 ] ;
memcpy ( V_290 , V_288 -> V_296 , V_289 ) ;
V_290 += V_289 ;
* V_290 = V_289 ;
V_290 += 1 ;
* V_290 = V_298 ;
V_290 += 1 ;
* ( V_293 * ) V_290 = F_15 ( ( T_2 ) V_288 -> V_219 ) ;
V_290 += 4 ;
* V_290 = V_295 ;
V_290 += 1 ;
* V_290 = V_288 -> V_292 ;
V_290 += 1 ;
if ( V_288 -> V_299 ) {
* V_290 = V_288 -> V_299 ;
V_290 += 1 ;
}
if ( V_290 - * V_286 > V_300 )
return - 1 ;
}
* V_286 = V_290 ;
return 0 ;
}
static int
F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_301 * V_302 )
{
struct V_303 * V_304 = & V_4 -> V_11 . V_304 ;
V_58 * V_270 = ( V_58 * ) V_304 ;
V_4 -> V_6 = F_2 ( V_305 ) ;
V_304 -> V_306 = F_15 ( V_302 -> V_306 ) ;
V_304 -> V_307 = F_2 ( V_302 -> V_307 ) ;
V_270 += sizeof( * V_304 ) ;
V_304 -> V_285 -> V_75 = V_302 -> V_285 -> V_75 ;
V_304 -> V_285 -> V_13 = V_302 -> V_285 -> V_13 ;
V_270 += sizeof( * ( V_304 -> V_285 ) ) ;
if ( F_30 ( V_2 , V_302 -> V_285 , & V_270 ) )
return - 1 ;
V_304 -> V_285 -> V_308 =
F_2 ( V_270 - V_304 -> V_285 -> V_309 ) ;
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_270 - ( V_58 * ) V_304 ) + V_10 ) ;
return 0 ;
}
static T_2 F_32 ( V_58 * V_310 , T_3 V_196 , V_58 * V_311 )
{
V_58 * V_312 = V_310 , * V_313 = V_311 ;
while ( V_312 - V_310 < V_196 ) {
if ( * V_312 && ( isspace ( * V_312 ) || * V_312 == '\t' ) ) {
V_312 ++ ;
continue;
}
if ( isxdigit ( * V_312 ) ) {
* V_313 ++ = F_33 ( V_312 , NULL , 16 ) ;
V_312 += 2 ;
} else {
V_312 ++ ;
}
}
return V_313 - V_311 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_314 * V_315 = & V_4 -> V_11 . V_315 ;
struct V_100 * V_29 = V_2 -> V_29 ;
T_2 V_196 , V_316 ;
V_58 * V_317 = ( V_58 * ) V_4 ;
V_316 = V_10 + sizeof( * V_315 ) ;
if ( ( V_29 -> V_318 -> V_319 ) && ( V_29 -> V_318 -> V_8 > 0 ) )
V_196 = F_32 ( ( V_58 * ) V_29 -> V_318 -> V_319 ,
V_29 -> V_318 -> V_8 ,
( V_58 * ) ( V_317 + V_316 ) ) ;
else
return - 1 ;
V_315 -> V_13 = F_2 ( V_5 ) ;
V_315 -> type = F_2 ( V_320 ) ;
V_315 -> V_321 = F_2 ( V_196 ) ;
V_4 -> V_6 = F_2 ( V_322 ) ;
V_4 -> V_8 = F_2 ( V_10 + sizeof( * V_315 ) + V_196 ) ;
return 0 ;
}
int F_35 ( struct V_1 * V_2 , T_4 V_323 ,
T_1 V_5 , T_2 V_32 ,
void * V_76 , void * V_324 )
{
struct V_3 * V_325 = V_324 ;
int V_167 = 0 ;
switch ( V_323 ) {
case V_326 :
V_167 = F_36 ( V_2 , V_325 ) ;
break;
case V_322 :
V_167 = F_34 ( V_2 , V_325 , V_5 ) ;
break;
case V_31 :
V_167 = F_3 ( V_2 , V_325 , V_5 ,
V_76 ) ;
break;
case V_118 :
V_167 = F_16 ( V_2 , V_325 ,
V_5 ) ;
break;
case V_129 :
V_167 = F_17 ( V_325 , V_5 ,
V_76 ) ;
break;
case V_56 :
V_167 = F_10 ( V_2 , V_325 , V_5 ,
V_76 ) ;
break;
case V_74 :
V_167 = F_11 ( V_325 , V_5 ,
V_76 ) ;
break;
case V_78 :
V_167 = F_12 ( V_2 , V_325 , V_5 ,
V_76 ) ;
break;
case V_85 :
V_167 = F_13 ( V_2 , V_325 , V_5 ,
V_76 ) ;
break;
case V_327 :
V_167 = F_37 ( V_2 , V_325 , V_5 ,
( T_4 ) V_32 , V_76 ) ;
break;
case V_105 :
V_167 = F_14 ( V_2 , V_325 , V_5 ,
(struct V_98 * ) V_76 ) ;
break;
case V_328 :
V_167 = F_38 ( V_325 , V_76 ) ;
break;
case V_329 :
V_167 = F_39 ( V_325 ) ;
break;
case V_330 :
V_167 = F_40 ( V_2 , V_325 , V_76 ) ;
break;
case V_136 :
V_167 = F_18 ( V_2 , V_325 ,
V_76 ) ;
break;
case V_331 :
V_167 = F_41 ( V_2 , V_325 ,
V_76 ) ;
break;
case V_45 :
V_167 = F_9 ( V_325 ) ;
break;
case V_332 :
V_167 = F_42 ( V_2 , V_325 ,
V_76 ) ;
break;
case V_139 :
V_167 = F_19 ( V_325 ) ;
break;
case V_7 :
V_167 = F_1 ( V_2 , V_325 , V_5 ) ;
break;
case V_37 :
V_167 = F_5 ( V_2 , V_325 , V_5 ,
V_32 , V_76 ) ;
break;
case V_333 :
V_325 -> V_6 =
F_2 ( V_333 ) ;
V_325 -> V_8 =
F_2 ( sizeof( struct V_334 ) +
V_10 ) ;
V_2 -> V_335 = 0 ;
V_167 = 0 ;
break;
case V_336 :
V_325 -> V_6 = F_2 ( V_323 ) ;
V_325 -> V_11 . V_337 . V_338 =
( V_58 ) ( * ( ( T_2 * ) V_76 ) ) ;
memcpy ( & V_325 -> V_11 , V_76 ,
sizeof( struct V_339 ) ) ;
V_325 -> V_8 =
F_2 ( sizeof( struct V_339 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_340 :
V_325 -> V_6 = F_2 ( V_323 ) ;
V_325 -> V_11 . V_341 . V_13 = F_2 ( V_5 ) ;
V_325 -> V_11 . V_341 . V_342 = F_15 ( * ( T_2 * ) V_76 ) ;
V_325 -> V_8 =
F_2 ( sizeof( struct V_343 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_344 :
V_325 -> V_6 = F_2 ( V_323 ) ;
memcpy ( & V_325 -> V_11 , V_76 ,
sizeof( struct V_345 ) ) ;
V_325 -> V_8 =
F_2 ( sizeof( struct V_345 ) +
V_10 ) ;
break;
case V_346 :
V_167 = F_43 ( V_2 , V_325 , V_5 , V_76 ) ;
break;
case V_347 :
V_325 -> V_6 = F_2 ( V_323 ) ;
V_325 -> V_11 . V_348 . V_13 = F_2 ( V_5 ) ;
V_325 -> V_11 . V_348 . V_75 = F_2 ( * ( T_1 * ) V_76 ) ;
V_325 -> V_8 =
F_2 ( sizeof( struct V_349 ) +
V_10 ) ;
break;
case V_350 :
if ( V_2 -> V_29 -> V_351 == V_352 )
V_2 -> V_29 -> V_351 = V_353 ;
V_325 -> V_6 = F_2 ( V_323 ) ;
V_325 -> V_8 = F_2 ( V_10 ) ;
break;
case V_354 :
V_2 -> V_29 -> V_351 = V_352 ;
V_325 -> V_6 = F_2 ( V_323 ) ;
V_325 -> V_8 = F_2 ( V_10 ) ;
break;
case V_355 :
V_167 = F_44 ( V_325 , V_76 ) ;
break;
case V_356 :
V_167 = F_45 ( V_325 , V_76 ) ;
break;
case V_357 :
V_167 = F_46 ( V_2 , V_325 , V_76 ) ;
break;
case V_168 :
V_167 = F_22 ( V_2 , V_325 ,
V_5 , V_32 ,
V_76 ) ;
break;
case V_203 :
V_167 = F_24 ( V_2 , V_325 ,
V_5 ) ;
break;
case V_358 :
V_167 = F_47 ( V_2 , V_325 , V_5 ,
V_76 ) ;
break;
case V_359 :
V_167 = F_48 ( V_325 , V_5 ,
V_76 ) ;
break;
case V_360 :
V_167 = F_49 ( V_2 , V_325 , V_5 , V_76 ) ;
break;
case V_361 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_22 ) ;
V_325 -> V_6 = F_2 ( V_361 ) ;
V_325 -> V_8 =
F_2 ( sizeof( struct V_362 ) +
V_10 ) ;
V_167 = 0 ;
break;
case V_213 :
V_167 = F_25 ( V_325 , V_5 ,
V_76 ) ;
break;
case V_216 :
case V_220 :
case V_223 :
case V_226 :
case V_229 :
case V_231 :
V_167 = F_26 ( V_325 , V_5 , V_76 ) ;
break;
case V_363 :
V_325 -> V_6 = F_2 ( V_323 ) ;
if ( V_2 -> V_364 == V_365 )
V_325 -> V_11 . V_364 . V_366 =
V_367 ;
else if ( V_2 -> V_364 == V_368 )
V_325 -> V_11 . V_364 . V_366 =
V_369 ;
else if ( V_2 -> V_364 == V_370 )
V_325 -> V_11 . V_364 . V_366 = V_371 ;
V_325 -> V_8 = F_2 ( sizeof( struct
V_372 ) + V_10 ) ;
V_167 = 0 ;
break;
case V_243 :
V_167 = F_28 ( V_2 , V_325 , V_5 ) ;
break;
case V_271 :
V_167 = F_29 ( V_2 , V_325 , V_76 ) ;
break;
case V_305 :
V_167 = F_31 ( V_2 , V_325 , V_76 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_23 , V_323 ) ;
V_167 = - 1 ;
break;
}
return V_167 ;
}
int F_50 ( struct V_1 * V_2 , V_58 V_373 )
{
struct V_100 * V_29 = V_2 -> V_29 ;
int V_167 ;
T_1 V_209 = true ;
struct V_374 V_375 ;
struct V_376 V_377 ;
enum V_378 V_379 ;
struct V_380 V_381 ;
if ( V_373 ) {
if ( V_2 -> V_29 -> V_382 == V_383 ) {
V_167 = F_51 ( V_2 ,
V_243 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
}
V_167 = F_51 ( V_2 , V_350 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
if ( V_29 -> V_318 ) {
V_167 = F_51 ( V_2 , V_322 ,
V_28 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
}
V_167 = F_51 ( V_2 , V_326 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
V_167 = F_51 ( V_2 ,
V_358 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_384 ) ;
if ( V_167 )
return - 1 ;
if ( V_2 -> V_192 != V_193 ) {
V_2 -> V_29 -> V_385 = V_386 ;
V_167 = F_51 (
V_2 , V_327 ,
V_387 , V_388 , NULL ) ;
if ( V_167 )
return - 1 ;
}
}
V_167 = F_51 ( V_2 , V_56 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
V_2 -> V_389 = 0 ;
V_167 = F_51 ( V_2 , V_78 ,
V_39 , 0 , NULL ) ;
if ( V_167 )
return - 1 ;
if ( V_2 -> V_192 == V_390 ) {
V_167 = F_51 (
V_2 , V_213 ,
V_28 , 0 , & V_209 ) ;
if ( V_167 )
return - 1 ;
}
memset ( & V_375 , 0 , sizeof( V_375 ) ) ;
V_375 . V_209 = true ;
V_167 = F_51 ( V_2 , V_359 ,
V_28 , 0 ,
& V_375 ) ;
if ( V_167 )
return - 1 ;
V_167 = F_51 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_391 ) ;
if ( V_167 )
return - 1 ;
if ( V_373 && V_2 -> V_29 -> V_382 != V_392 &&
V_2 -> V_192 != V_193 ) {
V_377 . V_377 = V_393 ;
V_377 . V_394 = V_395 ;
V_167 = F_51 ( V_2 ,
V_327 ,
V_387 , V_396 ,
& V_377 ) ;
if ( V_167 )
return - 1 ;
}
if ( V_2 -> V_192 != V_193 ) {
V_379 = V_397 ;
V_167 = F_51 ( V_2 , V_37 ,
V_28 , V_398 ,
& V_379 ) ;
if ( V_167 )
F_4 ( V_2 -> V_29 -> V_30 ,
L_24 ) ;
}
V_2 -> V_29 -> V_399 = V_360 ;
V_381 . V_400 = V_401 ;
V_167 = F_51 ( V_2 , V_360 ,
V_28 , 0 , & V_381 ) ;
V_167 = - V_402 ;
return V_167 ;
}
