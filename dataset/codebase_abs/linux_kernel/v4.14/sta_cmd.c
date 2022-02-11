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
T_1 V_5 , T_2 * V_13 )
{
struct V_26 * V_27 = & V_4 -> V_11 . V_27 ;
if ( V_5 != V_28 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_1 ) ;
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_30 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_26 ) + V_10 ) ;
V_27 -> V_13 = F_5 ( * V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
T_1 * V_32 )
{
struct V_33 * V_34 = & V_4 -> V_11 . V_35 ;
F_4 ( V_2 -> V_29 , V_36 ,
L_2 , V_31 ) ;
V_4 -> V_6 = F_2 ( V_37 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_33 )
- 1 + V_10 ) ;
V_34 -> V_38 = F_2 ( ( T_1 ) V_31 ) ;
if ( V_5 == V_39 ) {
V_34 -> V_40 = F_2 ( V_39 ) ;
V_34 -> V_41 = F_2 ( V_42 ) ;
F_7 ( & V_4 -> V_8 , V_42 ) ;
} else if ( V_5 == V_28 ) {
V_34 -> V_40 = F_2 ( V_28 ) ;
V_34 -> V_41 = F_2 ( sizeof( T_1 ) ) ;
F_8 ( * V_32 , V_34 -> V_43 ) ;
F_7 ( & V_4 -> V_8 , sizeof( T_1 ) ) ;
}
F_4 ( V_2 -> V_29 , V_36 ,
L_3
L_4 ,
V_5 , V_31 , F_9 ( V_34 -> V_41 ) ,
F_10 ( V_34 -> V_43 ) ) ;
return 0 ;
}
static int
F_11 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_44 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_45 ) +
V_10 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_46 )
{
struct V_47 * V_48 = & V_4 -> V_11 . V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
T_2 V_54 ;
V_4 -> V_6 = F_2 ( V_55 ) ;
V_48 -> V_13 = F_2 ( V_5 ) ;
V_48 -> V_56 = 0 ;
V_51 = (struct V_50 * ) ( ( V_57 * ) V_48 +
sizeof( struct V_47 ) ) ;
V_51 -> type = F_2 ( V_58 ) ;
V_51 -> V_59 = F_2
( sizeof( * V_51 ) - sizeof( struct V_60 ) ) ;
if ( V_46 != NULL ) {
V_51 -> V_61 = F_2 ( V_46 [ 0 ] ) ;
V_51 -> V_62 = F_2 ( V_46 [ 1 ] ) ;
for ( V_54 = 0 ; V_54 < F_13 ( V_51 -> V_63 ) ; V_54 ++ )
V_51 -> V_63 [ V_54 ] =
F_2 ( V_46 [ 2 + V_54 ] ) ;
if ( V_2 -> V_29 -> V_64 == V_65 ) {
for ( V_54 = 0 ;
V_54 < F_13 ( V_51 -> V_66 ) ;
V_54 ++ )
V_51 -> V_66 [ V_54 ] =
F_2 ( V_46 [ 10 + V_54 ] ) ;
}
} else {
V_51 -> V_61 =
F_2 ( V_2 -> V_67 [ 0 ] ) ;
V_51 -> V_62 =
F_2 ( V_2 -> V_67 [ 1 ] ) ;
for ( V_54 = 0 ; V_54 < F_13 ( V_51 -> V_63 ) ; V_54 ++ )
V_51 -> V_63 [ V_54 ] =
F_2 ( V_2 -> V_67 [ 2 + V_54 ] ) ;
if ( V_2 -> V_29 -> V_64 == V_65 ) {
for ( V_54 = 0 ;
V_54 < F_13 ( V_51 -> V_66 ) ;
V_54 ++ )
V_51 -> V_66 [ V_54 ] =
F_2 ( V_2 -> V_67 [ 10 + V_54 ] ) ;
}
}
V_53 = (struct V_52 * ) ( ( V_57 * ) V_51 +
sizeof( struct V_50 ) ) ;
V_53 -> type = F_2 ( V_68 ) ;
V_53 -> V_59 = F_2 ( sizeof( V_53 -> V_69 ) ) ;
V_53 -> V_69 = 0 ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_47 ) +
sizeof( struct V_50 ) +
sizeof( struct V_52 ) ) ;
return 0 ;
}
static int F_14 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_70 * V_71 )
{
struct V_72 * V_73 ;
struct V_70 * V_74 = & V_4 -> V_11 . V_75 ;
V_4 -> V_6 = F_2 ( V_76 ) ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_70 ) ) ;
switch ( V_5 ) {
case V_28 :
if ( V_71 -> V_77 ) {
V_73 = (struct V_72
* ) ( ( unsigned long ) V_71 +
sizeof( struct V_70 ) ) ;
memmove ( V_74 , V_71 ,
sizeof( struct V_70 ) +
sizeof( struct V_72 ) +
F_9 ( V_73 -> V_59 ) ) ;
V_73 = (struct V_72 * ) ( ( V_57 * )
V_74 +
sizeof( struct V_70 ) ) ;
V_4 -> V_8 = F_2 ( F_9 ( V_4 -> V_8 ) +
sizeof( struct V_72 ) +
F_9 ( V_73 -> V_59 ) ) ;
} else {
memmove ( V_74 , V_71 , sizeof( * V_71 ) ) ;
}
V_74 -> V_13 = F_2 ( V_5 ) ;
break;
case V_39 :
V_74 -> V_13 = F_2 ( V_5 ) ;
break;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_78 )
{
struct V_79 * V_71 = & V_4 -> V_11 . V_71 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_79 )
+ V_10 ) ;
V_4 -> V_6 = F_2 ( V_80 ) ;
V_71 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = & V_4 -> V_11 . V_84 ;
struct V_85 * V_86 = & V_4 -> V_11 . V_86 ;
V_4 -> V_6 = F_2 ( V_87 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_2 -> V_29 -> V_88 == V_89 ) {
V_4 -> V_8 = F_2 ( sizeof( struct
V_83 )
+ V_10 ) ;
V_84 -> V_90 = F_2 ( V_91 ) ;
V_84 -> V_92 = F_2 ( ( T_1 ) V_82 ->
V_93 ) ;
V_84 -> V_94 = F_2 ( V_95 ) ;
V_84 -> V_96 = F_2 ( ( T_1 ) V_82 ->
V_97 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( struct
V_85 ) +
V_10 ) ;
V_86 -> V_13 = F_2 ( V_98 ) ;
V_86 -> V_99 = F_2 ( ( T_1 ) V_82 -> V_93 ) ;
}
break;
case V_39 :
if ( V_2 -> V_29 -> V_88 == V_89 ) {
V_4 -> V_8 = F_2 ( sizeof( struct
V_83 ) +
V_10 ) ;
V_84 -> V_90 = F_2 ( V_100 ) ;
V_84 -> V_94 = F_2 ( V_101 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( struct
V_85 ) +
V_10 ) ;
V_86 -> V_13 = F_2 ( V_102 ) ;
}
break;
}
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_103 * V_104 )
{
struct V_105 * V_29 = V_2 -> V_29 ;
struct V_106 * V_107 = & V_4 -> V_11 . V_108 ;
V_57 * V_109 = ( V_57 * ) V_107 + sizeof( struct V_106 ) ;
struct V_110 * V_111 = NULL ;
bool V_112 = false ;
T_1 V_8 ;
if ( ! V_104 )
V_112 = true ;
V_4 -> V_6 = F_2 ( V_113 ) ;
if ( ! V_112 &&
( V_104 -> V_114 != F_5 ( V_115 ) ) &&
( ( V_29 -> V_116 > 0 ) &&
( V_29 -> V_116 <= V_117 ) ) ) {
F_4 ( V_29 , V_36 ,
L_5 ,
V_29 -> V_116 ) ;
memcpy ( ( ( V_57 * ) V_107 ) +
sizeof( struct V_106 ) ,
V_29 -> V_118 , V_29 -> V_116 ) ;
V_8 = V_29 -> V_116 +
sizeof( struct V_106 )
+ V_10 ;
V_109 = ( V_57 * ) V_107
+ sizeof( struct V_106 )
+ V_29 -> V_116 ;
} else {
V_8 = V_10 + sizeof( struct V_106 ) ;
}
if ( V_112 ) {
V_107 -> V_13 = F_2 ( V_119 ) ;
V_107 -> V_11 . V_112 . V_120 = F_2 ( V_121 ) ;
} else {
V_107 -> V_13 = F_2 ( V_122 ) ;
V_107 -> V_11 . V_123 . V_114 = V_104 -> V_114 ;
V_107 -> V_11 . V_123 . V_124 = V_104 -> V_124 ;
V_107 -> V_11 . V_123 . V_125 = V_104 -> V_125 ;
V_8 += sizeof( struct V_110 ) ;
V_111 = (struct V_110 * ) V_109 ;
V_111 -> V_126 . type =
F_2 ( V_127 ) ;
V_111 -> V_126 . V_128 =
F_2 ( sizeof( struct V_110 )
- sizeof( struct V_60 ) ) ;
V_111 -> V_129 = F_5 ( V_130 ) ;
V_111 -> V_131 =
F_5 ( V_132 ) ;
F_4 ( V_29 , V_36 ,
L_6 ,
V_107 -> V_11 . V_123 . V_114 ,
V_107 -> V_11 . V_123 . V_124 ,
V_107 -> V_11 . V_123 . V_125 ) ;
}
V_4 -> V_8 = F_2 ( V_8 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_133 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_134 ) +
V_10 ) ;
V_4 -> V_135 = 0 ;
V_4 -> V_11 . V_136 . V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 )
memcpy ( V_4 -> V_11 . V_136 . V_136 , V_2 -> V_137 ,
V_138 ) ;
return 0 ;
}
static int
F_19 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_139 * V_140 )
{
struct V_141 * V_142 = & V_4 -> V_11 . V_143 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_141 ) +
V_10 ) ;
V_4 -> V_6 = F_2 ( V_144 ) ;
V_142 -> V_13 = F_2 ( V_5 ) ;
V_142 -> V_145 =
F_2 ( ( T_1 ) V_140 -> V_146 ) ;
memcpy ( V_142 -> V_147 , V_140 -> V_147 ,
V_140 -> V_146 * V_138 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
V_57 * V_148 )
{
struct V_149 * V_150 = & V_4 -> V_11 . V_150 ;
V_4 -> V_6 = F_2 ( V_151 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_149 )
+ V_10 ) ;
memcpy ( V_150 -> V_136 , V_148 , V_138 ) ;
F_4 ( V_2 -> V_29 , V_36 , L_7 , V_150 -> V_136 ) ;
V_150 -> V_152 = F_2 ( V_153 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_154 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 ,
struct V_155 * V_156 ,
T_1 * V_157 )
{
int V_158 ;
V_57 V_54 ;
for ( V_54 = 0 ; V_54 < V_159 ; V_54 ++ ) {
if ( ( V_2 -> V_160 [ V_54 ] . V_161 == V_162 ) ||
( V_2 -> V_160 [ V_54 ] . V_161 == V_163 ) ) {
V_156 -> type =
F_2 ( V_164 ) ;
#define F_23 8
V_156 -> V_59 = F_2 ( ( T_1 )
( V_2 -> V_160 [ V_54 ] .
V_161 +
F_23 ) ) ;
V_156 -> V_165 =
F_2 ( V_166 ) ;
V_156 -> V_167 =
F_2 ( V_168 | V_169 |
V_170 ) ;
V_156 -> V_171 =
F_2 ( V_2 -> V_160 [ V_54 ] . V_161 ) ;
V_156 -> V_172 [ 0 ] = V_54 ;
if ( V_54 ==
( V_2 ->
V_173 & V_174 ) )
V_156 -> V_172 [ 1 ] = 1 ;
else
V_156 -> V_172 [ 1 ] = 0 ;
memmove ( & V_156 -> V_172 [ 2 ] ,
V_2 -> V_160 [ V_54 ] . V_175 ,
V_2 -> V_160 [ V_54 ] . V_161 ) ;
V_158 = V_2 -> V_160 [ V_54 ] . V_161 +
F_23 +
sizeof( struct V_60 ) ;
* V_157 += ( T_1 ) V_158 ;
V_156 =
(struct V_155 * )
( ( V_57 * ) V_156 +
V_158 ) ;
} else if ( ! V_2 -> V_160 [ V_54 ] . V_161 ) {
continue;
} else {
F_4 ( V_2 -> V_29 , ERROR ,
L_8 ,
( V_54 + 1 ) , V_2 -> V_160 [ V_54 ] . V_161 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_176 * V_177 ,
struct V_178 * V_179 )
{
struct V_105 * V_29 = V_2 -> V_29 ;
T_1 V_8 , V_128 = V_180 ;
if ( V_177 -> V_181 ) {
F_4 ( V_29 , V_182 ,
L_9 , V_183 ) ;
if ( V_177 -> V_184 )
memcpy ( V_179 -> V_156 . V_185 . V_186 . V_187 ,
V_177 -> V_188 , V_177 -> V_189 ) ;
V_179 -> V_156 . V_167 &= F_2 ( ~ V_170 ) ;
V_179 -> V_156 . V_167 |= F_2 ( V_190 ) ;
V_179 -> V_156 . V_191 = V_192 ;
V_179 -> V_156 . V_185 . V_186 . V_171 =
F_2 ( V_177 -> V_171 ) ;
memcpy ( V_179 -> V_156 . V_185 . V_186 . V_172 ,
V_177 -> V_175 , V_177 -> V_171 ) ;
V_128 += sizeof( struct V_193 ) ;
} else if ( V_177 -> V_194 ) {
F_4 ( V_29 , V_182 ,
L_10 , V_183 ) ;
V_179 -> V_156 . V_191 = V_195 ;
V_179 -> V_156 . V_196 = V_177 -> V_197 & V_198 ;
} else {
F_4 ( V_29 , V_182 ,
L_11 , V_183 ) ;
if ( V_177 -> V_184 )
memcpy ( V_179 -> V_156 . V_185 . V_199 . V_188 ,
V_177 -> V_188 , V_177 -> V_189 ) ;
V_179 -> V_156 . V_191 = V_200 ;
V_179 -> V_156 . V_185 . V_199 . V_171 =
F_2 ( V_177 -> V_171 ) ;
memcpy ( V_179 -> V_156 . V_185 . V_199 . V_172 ,
V_177 -> V_175 , V_177 -> V_171 ) ;
V_128 += sizeof( struct V_201 ) ;
}
V_179 -> V_156 . V_128 = F_2 ( V_128 ) ;
V_8 = V_128 + sizeof( struct V_60 ) +
sizeof( V_179 -> V_13 ) + V_10 ;
V_4 -> V_8 = F_2 ( V_8 ) ;
return 0 ;
}
static int
F_25 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_176 * V_177 )
{
struct V_105 * V_29 = V_2 -> V_29 ;
V_57 * V_148 = V_177 -> V_136 ;
T_1 V_167 , V_128 = V_180 ;
struct V_178 * V_179 =
& V_4 -> V_11 . V_202 ;
V_4 -> V_6 = F_2 ( V_203 ) ;
V_179 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
F_4 ( V_29 , V_182 , L_12 , V_183 ) ;
V_179 -> V_156 . V_196 =
V_177 -> V_197 & V_198 ;
V_179 -> V_156 . type = F_2 ( V_204 ) ;
V_179 -> V_156 . V_128 = F_2 ( V_180 ) ;
memcpy ( V_179 -> V_156 . V_136 , V_148 , V_138 ) ;
if ( V_177 -> V_197 & V_205 )
V_167 = V_169 ;
else
V_167 = V_170 ;
if ( V_177 -> V_181 )
V_167 |= V_190 ;
V_179 -> V_156 . V_167 = F_2 ( V_167 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_60 ) +
V_10 + V_180 +
sizeof( V_179 -> V_13 ) ) ;
return 0 ;
}
memset ( & V_179 -> V_156 , 0 ,
sizeof( struct V_206 ) ) ;
if ( V_177 -> V_207 ) {
F_4 ( V_29 , V_182 , L_13 , V_183 ) ;
V_179 -> V_13 = F_2 ( V_208 ) ;
V_179 -> V_156 . type = F_2 ( V_204 ) ;
V_179 -> V_156 . V_128 = F_2 ( V_180 ) ;
V_179 -> V_156 . V_196 = V_177 -> V_197 & V_198 ;
V_167 = V_170 | V_169 ;
V_179 -> V_156 . V_167 = F_2 ( V_167 ) ;
memcpy ( V_179 -> V_156 . V_136 , V_148 , V_138 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_60 ) +
V_10 + V_180 +
sizeof( V_179 -> V_13 ) ) ;
return 0 ;
}
V_179 -> V_13 = F_2 ( V_28 ) ;
V_179 -> V_156 . V_196 = V_177 -> V_197 & V_198 ;
V_179 -> V_156 . type = F_2 ( V_204 ) ;
V_167 = V_168 ;
memcpy ( V_179 -> V_156 . V_136 , V_148 , V_138 ) ;
if ( V_177 -> V_171 <= V_163 ) {
F_4 ( V_29 , V_182 , L_14 , V_183 ) ;
V_128 += sizeof( struct V_209 ) ;
V_179 -> V_156 . V_128 = F_2 ( V_128 ) ;
V_179 -> V_156 . V_191 = V_166 ;
if ( F_26 ( V_2 ) == V_210 ) {
V_167 |= V_170 | V_169 ;
} else {
if ( V_177 -> V_211 ) {
V_167 |= V_170 | V_169 ;
if ( V_179 -> V_156 . V_196 ==
( V_2 -> V_173 & V_198 ) )
V_167 |= V_212 ;
} else {
if ( F_27 ( V_148 ) )
V_167 |= V_170 ;
else
V_167 |= V_169 | V_212 ;
}
}
V_179 -> V_156 . V_167 = F_2 ( V_167 ) ;
V_179 -> V_156 . V_185 . V_213 . V_171 =
F_2 ( V_177 -> V_171 ) ;
memcpy ( V_179 -> V_156 . V_185 . V_213 . V_172 ,
V_177 -> V_175 , V_177 -> V_171 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_60 ) +
V_128 + sizeof( V_179 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( F_27 ( V_148 ) )
V_167 |= V_170 | V_214 ;
else
V_167 |= V_169 | V_215 | V_214 ;
if ( V_177 -> V_216 ) {
F_4 ( V_29 , V_182 , L_15 , V_183 ) ;
V_179 -> V_156 . V_191 = V_217 ;
memcpy ( V_179 -> V_156 . V_185 . V_218 . V_188 , V_177 -> V_188 ,
V_219 ) ;
V_179 -> V_156 . V_185 . V_218 . V_171 =
F_2 ( V_177 -> V_171 ) ;
memcpy ( V_179 -> V_156 . V_185 . V_218 . V_172 ,
V_177 -> V_175 , V_177 -> V_171 ) ;
if ( F_27 ( V_148 ) )
V_2 -> V_220 . V_221 = true ;
if ( ! V_2 -> V_220 . V_221 )
V_167 |= V_212 ;
V_179 -> V_156 . V_167 = F_2 ( V_167 ) ;
V_128 += sizeof( struct V_222 ) ;
V_179 -> V_156 . V_128 = F_2 ( V_128 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_60 ) +
V_128 + sizeof( V_179 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( V_2 -> V_223 == V_224 ) {
V_167 |= V_212 ;
if ( ! V_2 -> V_220 . V_225 &&
! F_27 ( V_148 ) )
V_167 |= V_169 ;
} else {
if ( ! V_2 -> V_226 )
V_167 |= V_212 ;
}
V_179 -> V_156 . V_167 = F_2 ( V_167 ) ;
if ( V_177 -> V_171 == V_227 )
return F_24 ( V_2 , V_4 , V_177 , V_179 ) ;
if ( V_177 -> V_171 == V_228 ) {
F_4 ( V_29 , V_182 ,
L_16 , V_183 ) ;
if ( V_177 -> V_184 )
memcpy ( V_179 -> V_156 . V_185 . V_229 . V_188 ,
V_177 -> V_188 , V_177 -> V_189 ) ;
V_179 -> V_156 . V_191 = V_230 ;
V_179 -> V_156 . V_185 . V_229 . V_171 =
F_2 ( V_177 -> V_171 ) ;
memcpy ( V_179 -> V_156 . V_185 . V_229 . V_172 ,
V_177 -> V_175 , V_177 -> V_171 ) ;
V_128 += sizeof( struct V_231 ) ;
V_179 -> V_156 . V_128 = F_2 ( V_128 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_60 ) +
V_128 + sizeof( V_179 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_176 * V_177 )
{
struct V_232 * V_175 =
& V_4 -> V_11 . V_175 ;
struct V_233 * V_234 ;
T_1 V_157 = 0 , V_235 ;
int V_236 = 0 ;
V_4 -> V_6 = F_2 ( V_203 ) ;
V_175 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_175 -> V_13 ) + V_10 ) ;
return V_236 ;
}
if ( ! V_177 ) {
memset ( & V_175 -> V_156 , 0 ,
( V_159 *
sizeof( struct V_155 ) ) ) ;
V_236 = F_22 ( V_2 ,
& V_175 -> V_156 ,
& V_157 ) ;
V_4 -> V_8 = F_2 ( V_157 +
sizeof( V_175 -> V_13 ) + V_10 ) ;
return V_236 ;
} else
memset ( & V_175 -> V_156 , 0 ,
sizeof( struct V_155 ) ) ;
if ( V_177 -> V_216 ) {
F_4 ( V_2 -> V_29 , V_182 , L_17 ) ;
V_175 -> V_156 . V_165 =
F_2 ( V_217 ) ;
if ( V_31 == V_237 )
V_175 -> V_156 . V_167 =
F_2 ( V_168 ) ;
else
V_175 -> V_156 . V_167 =
F_2 ( ! V_168 ) ;
V_175 -> V_156 . V_172 [ 0 ] = V_177 -> V_197 ;
if ( ! V_2 -> V_220 . V_221 )
V_175 -> V_156 . V_172 [ 1 ] = 1 ;
else
V_175 -> V_156 . V_172 [ 1 ] = 0 ;
if ( ! F_27 ( V_177 -> V_136 ) ) {
V_175 -> V_156 . V_167 |=
F_2 ( V_169 ) ;
} else {
V_175 -> V_156 . V_167 |=
F_2 ( V_170 ) ;
V_2 -> V_220 . V_221 = true ;
}
V_175 -> V_156 . type =
F_2 ( V_164 ) ;
V_175 -> V_156 . V_171 =
F_2 ( V_238 ) ;
memcpy ( & V_175 -> V_156 . V_172 [ 2 ] ,
V_177 -> V_175 , V_177 -> V_171 ) ;
memcpy ( & V_175 -> V_156 . V_172 [ 2 + V_177 -> V_171 ] ,
V_177 -> V_188 , V_219 ) ;
V_175 -> V_156 . V_59 =
F_2 ( V_238 + V_239 ) ;
V_157 = ( V_238 + V_239 ) +
sizeof( struct V_60 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_175 -> V_13 )
+ V_10 + V_157 ) ;
return V_236 ;
}
if ( V_177 -> V_171 == V_227 ) {
if ( V_177 -> V_181 ) {
F_4 ( V_2 -> V_29 , V_36 , L_18 ) ;
V_175 -> V_156 . V_165 =
F_2 ( V_192 ) ;
if ( V_31 == V_237 )
V_175 -> V_156 . V_167 =
F_2 ( V_168 ) ;
else
V_175 -> V_156 . V_167 =
F_2 ( ! V_168 ) ;
V_175 -> V_156 . V_167 |=
F_2 ( V_190 ) ;
} else {
F_4 ( V_2 -> V_29 , V_36 , L_19 ) ;
V_175 -> V_156 . V_165 =
F_2 ( V_200 ) ;
if ( V_31 == V_237 )
V_175 -> V_156 . V_167 =
F_2 ( V_168 ) ;
else
V_175 -> V_156 . V_167 =
F_2 ( ! V_168 ) ;
if ( V_177 -> V_197 & V_205 )
V_175 -> V_156 . V_167 |=
F_2 ( V_169 ) ;
else
V_175 -> V_156 . V_167 |=
F_2 ( V_170 ) ;
}
} else if ( V_177 -> V_171 == V_228 ) {
F_4 ( V_2 -> V_29 , V_36 , L_20 ) ;
V_175 -> V_156 . V_165 =
F_2 ( V_230 ) ;
V_175 -> V_156 . V_167 =
F_2 ( V_168 ) ;
if ( V_177 -> V_197 & V_205 )
V_175 -> V_156 . V_167 |=
F_2 ( V_169 ) ;
else
V_175 -> V_156 . V_167 |=
F_2 ( V_170 ) ;
}
if ( V_175 -> V_156 . V_165 ) {
V_175 -> V_156 . type =
F_2 ( V_164 ) ;
V_175 -> V_156 . V_171 =
F_2 ( ( T_1 ) V_177 -> V_171 ) ;
memcpy ( V_175 -> V_156 . V_172 , V_177 -> V_175 ,
V_177 -> V_171 ) ;
V_175 -> V_156 . V_59 =
F_2 ( ( T_1 ) V_177 -> V_171 +
V_239 ) ;
V_157 = ( T_1 ) ( V_177 -> V_171 + V_239 )
+ sizeof( struct V_60 ) ;
if ( F_9 ( V_175 -> V_156 . V_165 ) ==
V_192 ) {
struct V_240 * V_241 =
( void * ) V_175 -> V_156 . V_172 ;
memcpy ( V_241 -> V_187 , V_177 -> V_188 , V_242 ) ;
memcpy ( V_241 -> V_172 , V_177 -> V_175 ,
V_243 ) ;
V_157 = sizeof( struct V_240 ) ;
V_175 -> V_156 . V_171 =
F_2 ( V_157 ) ;
V_157 += V_239 ;
V_175 -> V_156 . V_59 =
F_2 ( V_157 ) ;
V_157 += sizeof( struct V_60 ) ;
}
V_4 -> V_8 = F_2 ( sizeof( V_175 -> V_13 ) + V_10
+ V_157 ) ;
if ( F_26 ( V_2 ) == V_210 ) {
V_234 = ( void * ) ( ( V_57 * ) & V_175 -> V_156 +
V_157 ) ;
V_234 -> V_126 . type =
F_2 ( V_244 ) ;
V_234 -> V_126 . V_128 = F_2 ( V_138 ) ;
memcpy ( V_234 -> V_136 , V_177 -> V_136 , V_138 ) ;
V_235 = V_157 + V_10 +
sizeof( V_175 -> V_13 ) +
sizeof( struct V_233 ) ;
} else {
V_235 = V_157 + V_10 +
sizeof( V_175 -> V_13 ) ;
}
V_4 -> V_8 = F_2 ( V_235 ) ;
}
return V_236 ;
}
static int
F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_176 * V_177 )
{
if ( V_2 -> V_29 -> V_245 == V_246 )
return F_25 ( V_2 , V_4 ,
V_5 , V_31 ,
V_177 ) ;
else
return F_28 ( V_2 , V_4 ,
V_5 , V_31 ,
V_177 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_105 * V_29 = V_2 -> V_29 ;
struct V_247 * V_248 =
& V_4 -> V_11 . V_248 ;
struct V_249 * V_250 =
& V_248 -> V_250 ;
V_57 V_251 = V_29 -> V_252 . V_251 ;
F_4 ( V_29 , V_182 ,
L_21 , V_251 ) ;
V_4 -> V_6 = F_2 ( V_253 ) ;
V_248 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_248 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_250 -> V_126 . type = F_2 ( V_254 ) ;
memcpy ( V_250 -> V_255 , V_29 -> V_252 . V_255 ,
sizeof( V_250 -> V_255 ) ) ;
V_250 -> V_126 . V_128 =
F_2 ( ( V_251 *
sizeof( struct V_256 ) )
+ sizeof( V_250 -> V_255 ) ) ;
if ( V_251 ) {
memcpy ( V_250 -> V_257 , V_29 -> V_252 . V_257 ,
V_251 * sizeof( struct
V_256 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_248 -> V_13 ) +
F_9 ( V_250 -> V_126 . V_128 ) +
sizeof( struct V_60 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_248 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_258 )
{
struct V_259 * V_260 =
& ( V_4 -> V_11 . V_261 ) ;
V_4 -> V_6 = F_2 ( V_262 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_259 ) +
V_10 ) ;
V_4 -> V_135 = 0 ;
V_260 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_258 )
V_260 -> V_258 = F_2 ( * V_258 ) ;
else
V_260 -> V_258 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int
F_32 ( struct V_3 * V_4 , T_1 V_5 ,
void * V_263 )
{
struct V_264 * V_265 = ( void * ) V_263 ;
struct V_266 * V_267 = ( void * ) & V_4 -> V_11 . V_268 ;
V_4 -> V_6 = F_2 ( V_269 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_266 ) +
V_10 ) ;
V_267 -> V_13 = F_2 ( V_5 ) ;
V_267 -> V_270 = F_5 ( V_265 -> V_270 ) ;
V_267 -> V_43 = F_5 ( V_265 -> V_43 ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_78 )
{
struct V_271 * V_272 = V_78 ;
switch ( F_9 ( V_4 -> V_6 ) ) {
case V_273 :
{
struct V_274 * V_275 ;
V_4 -> V_8 = F_2 ( sizeof( * V_275 ) + V_10 ) ;
V_275 = & V_4 -> V_11 . V_275 ;
V_275 -> V_13 = F_2 ( V_5 ) ;
V_275 -> V_276 = F_2 ( ( T_1 ) V_272 -> V_276 ) ;
V_275 -> V_43 = F_5 ( V_272 -> V_43 ) ;
break;
}
case V_277 :
{
struct V_278 * V_279 ;
V_4 -> V_8 = F_2 ( sizeof( * V_279 ) + V_10 ) ;
V_279 = & V_4 -> V_11 . V_279 ;
V_279 -> V_13 = F_2 ( V_5 ) ;
V_279 -> V_276 = F_2 ( ( T_1 ) V_272 -> V_276 ) ;
V_279 -> V_43 = ( V_57 ) V_272 -> V_43 ;
break;
}
case V_280 :
{
struct V_281 * V_282 ;
V_4 -> V_8 = F_2 ( sizeof( * V_282 ) + V_10 ) ;
V_282 = & V_4 -> V_11 . V_282 ;
V_282 -> V_13 = F_2 ( V_5 ) ;
V_282 -> V_276 = F_2 ( ( T_1 ) V_272 -> V_276 ) ;
V_282 -> V_43 = ( V_57 ) V_272 -> V_43 ;
break;
}
case V_283 :
{
struct V_284 * V_285 ;
V_4 -> V_8 = F_2 ( sizeof( * V_285 ) + V_10 ) ;
V_285 = & V_4 -> V_11 . V_285 ;
V_285 -> V_13 = F_2 ( V_5 ) ;
V_285 -> V_276 = F_2 ( ( T_1 ) V_272 -> V_276 ) ;
V_285 -> V_43 = ( V_57 ) V_272 -> V_43 ;
break;
}
case V_286 :
{
struct V_281 * V_287 ;
V_4 -> V_8 = F_2 ( sizeof( * V_287 ) + V_10 ) ;
V_287 = & V_4 -> V_11 . V_282 ;
V_287 -> V_13 = F_2 ( V_5 ) ;
V_287 -> V_276 = F_2 ( ( T_1 ) V_272 -> V_276 ) ;
V_287 -> V_43 = ( V_57 ) V_272 -> V_43 ;
break;
}
case V_288 :
{
struct V_289 * V_290 = V_78 ;
struct V_291 * V_292 =
& V_4 -> V_11 . V_293 ;
V_4 -> V_8 = F_2 ( sizeof( * V_292 ) + V_10 ) ;
V_292 -> V_13 = F_2 ( V_5 ) ;
V_292 -> V_276 = F_2 ( V_290 -> V_276 ) ;
V_292 -> V_294 = F_2 ( V_290 -> V_294 ) ;
V_292 -> V_43 = 0 ;
break;
}
default:
return - 1 ;
}
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_13 )
{
struct V_295 * V_296 =
& V_4 -> V_11 . V_297 ;
struct V_298 * V_299 = V_2 -> V_29 -> V_299 ;
V_4 -> V_6 = F_2 ( V_300 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_295 ) + V_10 ) ;
V_4 -> V_135 = 0 ;
memset ( V_296 , 0 , sizeof( struct V_295 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_296 -> V_301 = F_5 ( ( T_2 ) ( V_299 -> V_302 ) ) ;
V_296 -> V_303 =
F_5 ( ( T_2 ) ( ( ( V_304 ) V_299 -> V_302 ) >> 32 ) ) ;
V_296 -> V_305 = F_5 ( V_306 ) ;
V_296 -> V_307 = F_5 ( ( T_2 ) ( V_299 -> V_308 ) ) ;
V_296 -> V_309 =
F_5 ( ( T_2 ) ( ( ( V_304 ) V_299 -> V_308 ) >> 32 ) ) ;
V_296 -> V_310 = F_5 ( V_306 ) ;
V_296 -> V_311 = F_5 ( ( T_2 ) ( V_299 -> V_312 ) ) ;
V_296 -> V_313 =
F_5 ( ( T_2 ) ( ( ( V_304 ) V_299 -> V_312 ) >> 32 ) ) ;
V_296 -> V_314 = F_5 ( V_315 ) ;
if ( V_299 -> V_316 ) {
V_296 -> V_317 =
F_5 ( ( T_2 ) ( V_299 -> V_318 ) ) ;
V_296 -> V_319 = F_5 ( ( T_2 ) ( ( ( V_304 )
( V_299 -> V_318 ) ) >> 32 ) ) ;
F_4 ( V_2 -> V_29 , V_182 ,
L_22 ,
V_296 -> V_317 ) ;
}
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_320 * V_321 )
{
struct V_322 * V_323 = & V_4 -> V_11 . V_323 ;
struct V_324 * V_325 ;
T_1 V_326 ;
V_57 * V_327 ;
V_4 -> V_6 = F_2 ( V_328 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_322 ) +
V_10 ) ;
V_323 -> V_13 = F_2 ( V_321 -> V_13 ) ;
F_4 ( V_2 -> V_29 , V_36 ,
L_23 , V_321 -> V_13 ) ;
if ( V_321 -> V_13 == V_39 )
return 0 ;
V_323 -> V_329 = F_2 ( V_321 -> V_329 ) ;
V_326 = V_321 -> V_329 ;
F_4 ( V_2 -> V_29 , V_36 , L_24 ,
V_326 ) ;
if ( ( ( V_321 -> V_13 == V_330 ) ||
( V_321 -> V_13 == V_331 ) ) &&
( V_326 == 0 ) ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_25
L_26 ) ;
return - V_332 ;
}
if ( V_321 -> V_13 == V_330 )
return 0 ;
V_327 = ( ( V_57 * ) V_323 ) +
sizeof( struct V_322 ) ;
if ( V_326 & V_333 ) {
V_325 = (struct V_324 * ) V_327 ;
V_325 -> V_126 . type = F_2 ( V_334 ) ;
V_325 -> V_126 . V_128 =
F_2 ( sizeof( struct V_324 ) -
sizeof( struct V_60 ) ) ;
V_325 -> V_335 = V_321 -> V_336 . V_335 ;
V_325 -> V_337 = V_321 -> V_336 . V_337 ;
F_4 ( V_2 -> V_29 , V_338 ,
L_27
L_28 ,
V_321 -> V_336 . V_335 ,
V_321 -> V_336 . V_337 ) ;
V_327 += sizeof( struct V_324 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof(
struct V_324 ) ) ;
}
if ( V_326 & V_339 ) {
V_325 = (struct V_324 * ) V_327 ;
V_325 -> V_126 . type = F_2 ( V_340 ) ;
V_325 -> V_126 . V_128 =
F_2 ( sizeof( struct V_324 ) -
sizeof( struct V_60 ) ) ;
V_325 -> V_335 = V_321 -> V_341 . V_335 ;
V_325 -> V_337 = V_321 -> V_341 . V_337 ;
F_4 ( V_2 -> V_29 , V_338 ,
L_29
L_28 ,
V_321 -> V_341 . V_335 ,
V_321 -> V_341 . V_337 ) ;
V_327 += sizeof( struct V_324 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof(
struct V_324 ) ) ;
}
return 0 ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_342 * V_343 ,
V_57 * * V_344 )
{
struct V_345 * V_346 = V_343 -> V_346 ;
int V_54 , V_347 ;
V_57 * V_348 = * V_344 ;
for ( V_54 = 0 ; V_54 < V_349 ; V_54 ++ ) {
V_346 = & V_343 -> V_346 [ V_54 ] ;
if ( ! V_346 -> V_350 )
break;
F_37 ( ( T_2 ) V_346 -> V_351 , V_348 ) ;
V_348 += 4 ;
* V_348 = V_352 ;
V_348 += 1 ;
V_347 = V_346 -> V_353 [ V_354 ] ;
memcpy ( V_348 , V_346 -> V_353 , V_347 ) ;
V_348 += V_347 ;
* V_348 = V_347 ;
V_348 += 1 ;
* V_348 = V_355 ;
V_348 += 1 ;
F_37 ( ( T_2 ) V_346 -> V_276 , V_348 ) ;
V_348 += 4 ;
* V_348 = V_352 ;
V_348 += 1 ;
* V_348 = V_346 -> V_350 ;
V_348 += 1 ;
if ( V_346 -> V_356 ) {
* V_348 = V_346 -> V_356 ;
V_348 += 1 ;
}
if ( V_348 - * V_344 > V_357 )
return - 1 ;
}
* V_344 = V_348 ;
return 0 ;
}
static int
F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_358 * V_359 )
{
struct V_360 * V_361 = & V_4 -> V_11 . V_361 ;
struct V_362 * V_343 = NULL ;
V_57 * V_327 = ( V_57 * ) V_361 ;
T_1 V_54 ;
V_4 -> V_6 = F_2 ( V_363 ) ;
V_361 -> V_364 = F_5 ( V_359 -> V_364 ) ;
V_361 -> V_365 = F_2 ( V_359 -> V_365 ) ;
V_327 += sizeof( * V_361 ) ;
for ( V_54 = 0 ; V_54 < V_359 -> V_365 ; V_54 ++ ) {
V_343 = (struct V_362 * ) V_327 ;
V_343 -> V_77 = V_359 -> V_343 [ V_54 ] . V_77 ;
V_343 -> V_13 = V_359 -> V_343 [ V_54 ] . V_13 ;
V_327 += sizeof( * V_361 -> V_343 ) ;
if ( F_36 ( V_2 ,
& V_359 -> V_343 [ V_54 ] , & V_327 ) )
return - 1 ;
V_343 -> V_366 =
F_2 ( V_327 - V_343 -> V_367 ) ;
}
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_327 - ( V_57 * ) V_361 ) + V_10 ) ;
return 0 ;
}
static T_2 F_39 ( V_57 * V_368 , T_3 V_128 , V_57 * V_369 )
{
V_57 * V_370 = V_368 , * V_371 = V_369 ;
while ( V_370 - V_368 < V_128 ) {
if ( * V_370 && ( isspace ( * V_370 ) || * V_370 == '\t' ) ) {
V_370 ++ ;
continue;
}
if ( isxdigit ( * V_370 ) ) {
* V_371 ++ = F_40 ( V_370 , NULL , 16 ) ;
V_370 += 2 ;
} else {
V_370 ++ ;
}
}
return V_371 - V_369 ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_372 * V_373 , const char * V_374 )
{
#ifdef F_42
struct V_375 * V_376 ;
T_3 V_128 = strlen ( V_374 ) ;
int V_236 ;
F_43 (node, prop) {
if ( V_128 > strlen ( V_376 -> V_377 ) ||
strncmp ( V_376 -> V_377 , V_374 , V_128 ) )
continue;
if ( V_376 -> V_43 && V_376 -> V_59 > 6 &&
V_376 -> V_59 <= V_378 - V_10 ) {
V_236 = F_44 ( V_2 , V_379 ,
V_28 , 0 ,
V_376 , true ) ;
if ( V_236 )
return V_236 ;
}
}
#endif
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_78 )
{
struct V_105 * V_29 = V_2 -> V_29 ;
struct V_375 * V_376 = V_78 ;
T_2 V_128 ;
V_57 * V_380 = ( V_57 * ) V_4 + V_10 ;
int V_236 ;
if ( V_376 ) {
V_128 = V_376 -> V_59 ;
V_236 = F_46 ( V_29 -> V_381 , V_376 -> V_377 ,
V_380 , V_128 ) ;
if ( V_236 )
return V_236 ;
F_4 ( V_29 , V_182 ,
L_30 ,
V_376 -> V_377 ) ;
} else if ( V_29 -> V_382 -> V_380 && V_29 -> V_382 -> V_8 > 0 ) {
V_128 = F_39 ( ( V_57 * ) V_29 -> V_382 -> V_380 ,
V_29 -> V_382 -> V_8 , V_380 ) ;
F_4 ( V_29 , V_182 ,
L_31 ) ;
} else {
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_379 ) ;
V_4 -> V_8 = F_2 ( V_10 + V_128 ) ;
return 0 ;
}
static int
F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_78 )
{
struct V_383 * V_384 = & V_4 -> V_11 . V_385 ;
const T_1 * V_386 = V_78 ;
V_384 -> V_13 = F_2 ( V_5 ) ;
V_384 -> V_387 = F_2 ( * V_386 ) ;
V_4 -> V_6 = F_2 ( V_388 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_383 ) +
V_10 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , bool * V_389 )
{
struct V_390 * V_391 = & V_4 -> V_11 . V_391 ;
struct V_392 * V_393 ;
V_4 -> V_6 = F_2 ( V_394 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_391 ) + sizeof( * V_393 ) + V_10 ) ;
V_391 -> V_13 = F_2 ( V_5 ) ;
V_393 = (struct V_392 * )
( ( V_57 * ) V_391 + sizeof( * V_391 ) ) ;
V_393 -> V_126 . type = F_2 ( V_395 ) ;
V_393 -> V_126 . V_128 = F_2 ( sizeof( V_393 -> V_77 ) ) ;
if ( V_391 -> V_13 == V_39 )
return 0 ;
if ( * V_389 )
V_393 -> V_77 = F_5 ( V_396 ) ;
else
V_393 -> V_77 = F_5 ( V_397 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_398 * V_380 )
{
struct V_399 * V_400 = & V_4 -> V_11 . V_400 ;
V_304 V_401 ;
V_4 -> V_6 = F_2 ( V_402 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_400 ) + V_10 ) ;
V_400 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 ) {
memcpy ( V_400 -> V_403 , V_380 -> V_403 , V_404 ) ;
memcpy ( V_400 -> V_405 , V_380 -> V_405 , V_406 ) ;
V_401 = F_50 ( ( V_407 * ) V_380 -> V_408 ) ;
V_400 -> V_409 = F_5 ( ( T_2 ) V_401 ) ;
V_400 -> V_410 =
F_5 ( ( T_2 ) ( ( V_304 ) V_401 >> 32 ) ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_411 * V_412 = & V_4 -> V_11 . V_413 ;
V_4 -> V_6 = F_2 ( V_414 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_412 ) + V_10 ) ;
if ( V_5 == V_39 )
V_412 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int
F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_78 )
{
struct V_415 * V_416 =
& V_4 -> V_11 . V_416 ;
struct V_417 * V_418 = V_78 ;
struct V_419 * V_241 ;
T_1 V_420 , V_421 , V_59 ;
struct V_422 * V_423 ;
V_4 -> V_6 = F_2 ( V_424 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_416 -> V_13 = F_2 ( V_5 ) ;
V_416 -> V_425 = F_2 ( V_418 -> V_425 ) ;
V_423 = V_416 -> V_423 ;
for ( V_420 = 0 ; V_420 < V_418 -> V_425 ; V_420 ++ ) {
V_423 -> V_126 . type = F_2 ( V_426 ) ;
V_423 -> V_427 =
F_2 ( V_418 -> V_423 [ V_420 ] . V_427 ) ;
V_423 -> V_428 = V_418 -> V_423 [ V_420 ] . V_428 ;
V_423 -> V_429 = V_418 -> V_423 [ V_420 ] . V_429 ;
V_59 = 0 ;
V_241 = V_423 -> V_11 ;
for ( V_421 = 0 ; V_421 < V_418 -> V_423 [ V_420 ] . V_429 ; V_421 ++ ) {
V_241 -> V_430 = V_418 -> V_423 [ V_420 ] . V_11 [ V_421 ] . V_430 ;
V_241 -> V_431 =
V_418 -> V_423 [ V_420 ] . V_11 [ V_421 ] . V_431 ;
V_241 -> V_276 =
F_2 ( V_418 -> V_423 [ V_420 ] . V_11 [ V_421 ] . V_276 ) ;
memcpy ( V_241 -> V_432 ,
V_418 -> V_423 [ V_420 ] . V_11 [ V_421 ] . V_432 ,
V_241 -> V_431 ) ;
V_59 += sizeof( struct V_419 ) ;
V_241 ++ ;
}
V_423 -> V_126 . V_128 = F_2 ( V_59 + sizeof( T_1 ) +
sizeof( V_57 ) + sizeof( V_57 ) ) ;
F_7 ( & V_4 -> V_8 ,
F_9 ( V_423 -> V_126 . V_128 ) +
sizeof( struct V_60 ) ) ;
V_423 = ( void * ) ( ( V_57 * ) V_423 -> V_11 + V_59 ) ;
}
F_7 ( & V_4 -> V_8 , sizeof( T_1 ) + sizeof( T_1 ) ) ;
return 0 ;
}
static int
F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_78 )
{
struct V_433 * V_434 = & V_4 -> V_11 . V_434 ;
struct V_435 * V_436 ;
struct V_437 * V_438 ;
T_1 V_128 ;
V_4 -> V_6 = F_2 ( V_439 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_434 -> V_440 = F_2 ( V_5 ) ;
F_7 ( & V_4 -> V_8 , sizeof( V_434 -> V_440 ) ) ;
switch ( V_5 ) {
case V_441 :
V_438 = V_78 ;
V_128 = sizeof( * V_438 ) ;
memcpy ( V_434 -> V_442 , V_438 , V_128 ) ;
break;
case V_443 :
V_436 = V_78 ;
V_128 = sizeof( * V_436 ) ;
memcpy ( V_434 -> V_442 , V_436 , V_128 ) ;
break;
case V_444 :
V_128 = sizeof( struct V_445 ) ;
memcpy ( V_434 -> V_442 , V_78 , V_128 ) ;
break;
case V_446 :
V_128 = sizeof( struct V_447 ) ;
memcpy ( V_434 -> V_442 , V_78 , V_128 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_32 ) ;
return - V_448 ;
}
F_7 ( & V_4 -> V_8 , V_128 ) ;
return 0 ;
}
static int
F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_78 )
{
struct V_449 * V_450 = & V_4 -> V_11 . V_450 ;
struct V_451 * V_452 = V_78 ;
struct V_453 * V_454 ;
struct V_455 * V_456 ;
struct V_457 * V_458 ;
struct V_459 * V_460 ;
struct V_461 * V_462 ;
struct V_463 * V_464 ;
struct V_465 * V_466 ;
V_57 * V_327 ;
T_1 V_467 = 0 ;
struct V_468 * V_11 = V_2 -> V_469 ;
V_4 -> V_6 = F_2 ( V_470 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_449 ) ) ;
V_450 -> V_471 = 0 ;
memcpy ( V_450 -> V_472 , V_452 -> V_472 , V_138 ) ;
V_327 = ( V_57 * ) V_450 + sizeof( struct V_449 ) ;
switch ( V_452 -> V_440 ) {
case V_473 :
V_450 -> V_440 = F_2 ( V_474 ) ;
break;
case V_475 :
V_450 -> V_440 = F_2 ( V_476 ) ;
break;
case V_477 :
V_450 -> V_440 = F_2 ( V_478 ) ;
if ( ! V_11 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_33 ,
V_452 -> V_472 ) ;
return - V_479 ;
}
F_8 ( V_11 -> V_480 , V_327 ) ;
V_467 += sizeof( V_11 -> V_480 ) ;
V_458 = ( void * ) ( V_327 + V_467 ) ;
V_458 -> V_126 . type = F_2 ( V_481 ) ;
V_458 -> V_126 . V_128 =
F_2 ( sizeof( V_458 -> V_482 ) ) ;
V_458 -> V_482 = 0 ;
V_467 += sizeof( struct V_457 ) ;
if ( V_11 -> V_483 ) {
V_456 = (struct V_455 * ) ( V_327 +
V_467 ) ;
V_456 -> V_126 . type =
F_2 ( V_484 ) ;
V_456 -> V_126 . V_128 =
F_2 ( sizeof( struct V_485 ) ) ;
memcpy ( & V_456 -> V_486 , V_11 -> V_483 ,
sizeof( struct V_485 ) ) ;
V_467 += sizeof( struct V_455 ) ;
}
if ( V_11 -> V_487 && V_11 -> V_488 ) {
V_454 = (struct V_453 * ) ( V_327 +
V_467 ) ;
V_454 -> V_126 . type =
F_2 ( V_489 ) ;
V_454 -> V_126 . V_128 =
F_2 ( V_11 -> V_488 ) ;
memcpy ( V_454 -> V_490 , V_11 -> V_487 ,
V_11 -> V_488 ) ;
V_467 += sizeof( struct V_453 ) +
V_11 -> V_488 ;
}
if ( V_11 -> V_491 && V_11 -> V_492 ) {
V_460 = (struct V_459 * ) ( V_327 +
V_467 ) ;
V_460 -> V_126 . type =
F_2 ( V_493 ) ;
V_460 -> V_126 . V_128 = F_2 ( V_11 -> V_492 ) ;
memcpy ( V_460 -> V_491 , V_11 -> V_491 ,
V_11 -> V_492 ) ;
V_467 += sizeof( struct V_459 ) +
V_11 -> V_492 ;
}
if ( V_11 -> V_494 ) {
V_462 = (struct V_461 * ) ( V_327 +
V_467 ) ;
V_462 -> V_126 . type =
F_2 ( V_495 ) ;
V_462 -> V_126 . V_128 =
F_2 ( sizeof( struct V_496 ) ) ;
memcpy ( & V_462 -> V_497 , V_11 -> V_494 ,
sizeof( struct V_496 ) ) ;
V_467 += sizeof( struct V_461 ) ;
}
if ( V_11 -> V_464 ) {
V_464 = (struct V_463 * ) ( V_327 + V_467 ) ;
V_464 -> V_126 . type = F_2 ( V_498 ) ;
V_464 -> V_126 . V_128 = F_2 ( sizeof( V_11 -> V_464 ) ) ;
V_464 -> V_464 = F_2 ( V_11 -> V_464 ) ;
V_467 += sizeof( struct V_463 ) ;
}
V_466 = ( void * ) ( V_327 + V_467 ) ;
V_466 -> V_126 . type = F_2 ( V_499 ) ;
V_466 -> V_126 . V_128 = F_2 ( sizeof( V_466 -> V_43 ) ) ;
V_466 -> V_43 = F_2 ( V_500 ) ;
V_467 += sizeof( struct V_465 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR , L_34 ) ;
return - V_448 ;
}
F_7 ( & V_4 -> V_8 , V_467 ) ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_78 )
{
struct V_501 * V_418 =
& V_4 -> V_11 . V_502 ;
V_4 -> V_6 = F_2 ( V_503 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_501 ) +
V_10 ) ;
V_418 -> V_13 = V_5 ;
if ( V_5 == V_28 )
V_418 -> V_258 = * ( V_57 * ) V_78 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_504 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_505 ) +
V_10 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , T_1 V_506 )
{
if ( ! F_58 ( V_2 -> V_29 -> V_507 ) ) {
switch ( V_506 ) {
case V_262 :
case V_508 :
case V_509 :
case V_154 :
return - V_510 ;
default:
break;
}
}
return 0 ;
}
int F_59 ( struct V_1 * V_2 , T_4 V_506 ,
T_1 V_5 , T_2 V_31 ,
void * V_78 , void * V_511 )
{
struct V_3 * V_512 = V_511 ;
int V_236 = 0 ;
if ( F_57 ( V_2 , V_506 ) ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_35 ,
V_506 ) ;
return - V_510 ;
}
switch ( V_506 ) {
case V_513 :
V_236 = F_60 ( V_2 , V_512 ) ;
break;
case V_379 :
V_236 = F_45 ( V_2 , V_512 , V_78 ) ;
break;
case V_30 :
V_236 = F_3 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_133 :
V_236 = F_18 ( V_2 , V_512 ,
V_5 ) ;
break;
case V_144 :
V_236 = F_19 ( V_512 , V_5 ,
V_78 ) ;
break;
case V_55 :
V_236 = F_12 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_76 :
V_236 = F_14 ( V_512 , V_5 ,
V_78 ) ;
break;
case V_80 :
V_236 = F_15 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_87 :
V_236 = F_16 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_514 :
V_236 = F_61 ( V_2 , V_512 , V_5 ,
( T_4 ) V_31 , V_78 ) ;
break;
case V_113 :
V_236 = F_17 ( V_2 , V_512 , V_5 ,
(struct V_103 * ) V_78 ) ;
break;
case V_515 :
V_236 = F_62 ( V_512 , V_78 ) ;
break;
case V_516 :
V_236 = F_63 ( V_2 , V_512 ,
V_78 ) ;
break;
case V_517 :
V_236 = F_64 ( V_512 ) ;
break;
case V_518 :
V_236 = F_65 ( V_2 , V_512 , V_78 ) ;
break;
case V_151 :
V_236 = F_20 ( V_2 , V_512 ,
V_78 ) ;
break;
case V_508 :
V_236 = F_66 ( V_2 , V_512 ,
V_78 ) ;
break;
case V_44 :
V_236 = F_11 ( V_512 ) ;
break;
case V_509 :
V_236 = F_67 ( V_2 , V_512 ,
V_78 ) ;
break;
case V_154 :
V_236 = F_21 ( V_512 ) ;
break;
case V_7 :
V_236 = F_1 ( V_2 , V_512 , V_5 ) ;
break;
case V_37 :
V_236 = F_6 ( V_2 , V_512 , V_5 ,
V_31 , V_78 ) ;
break;
case V_519 :
V_512 -> V_6 =
F_2 ( V_519 ) ;
V_512 -> V_8 =
F_2 ( sizeof( struct V_520 ) +
V_10 ) ;
V_2 -> V_521 = 0 ;
V_236 = 0 ;
break;
case V_522 :
V_512 -> V_6 = F_2 ( V_506 ) ;
V_512 -> V_11 . V_523 . V_524 =
( V_57 ) ( F_68 ( ( T_2 * ) V_78 ) ) ;
memcpy ( & V_512 -> V_11 , V_78 ,
sizeof( struct V_525 ) ) ;
V_512 -> V_8 =
F_2 ( sizeof( struct V_525 ) +
V_10 ) ;
V_236 = 0 ;
break;
case V_526 :
V_512 -> V_6 = F_2 ( V_506 ) ;
V_512 -> V_11 . V_527 . V_13 = F_2 ( V_5 ) ;
V_512 -> V_11 . V_527 . V_528 = F_5 (
F_68 ( ( T_2 * ) V_78 ) ) ;
V_512 -> V_8 =
F_2 ( sizeof( struct V_529 ) +
V_10 ) ;
V_236 = 0 ;
break;
case V_530 :
V_512 -> V_6 = F_2 ( V_506 ) ;
memcpy ( & V_512 -> V_11 , V_78 ,
sizeof( struct V_531 ) ) ;
V_512 -> V_8 =
F_2 ( sizeof( struct V_531 ) +
V_10 ) ;
break;
case V_532 :
V_236 = F_69 ( V_2 , V_512 , V_5 , V_78 ) ;
break;
case V_533 :
V_512 -> V_6 = F_2 ( V_506 ) ;
V_512 -> V_11 . V_534 . V_13 = F_2 ( V_5 ) ;
V_512 -> V_11 . V_534 . V_258 =
F_2 ( * ( T_1 * ) V_78 ) ;
V_512 -> V_8 =
F_2 ( sizeof( struct V_535 ) +
V_10 ) ;
break;
case V_536 :
V_512 -> V_6 = F_2 ( V_506 ) ;
V_512 -> V_11 . V_537 . V_13 = F_2 ( V_5 ) ;
V_512 -> V_11 . V_537 . V_77 = F_2 (
F_68 ( ( T_1 * ) V_78 ) ) ;
V_512 -> V_8 =
F_2 ( sizeof( struct V_538 ) +
V_10 ) ;
break;
case V_539 :
if ( V_2 -> V_29 -> V_540 == V_541 )
V_2 -> V_29 -> V_540 = V_542 ;
V_512 -> V_6 = F_2 ( V_506 ) ;
V_512 -> V_8 = F_2 ( V_10 ) ;
break;
case V_543 :
V_2 -> V_29 -> V_540 = V_541 ;
V_512 -> V_6 = F_2 ( V_506 ) ;
V_512 -> V_8 = F_2 ( V_10 ) ;
break;
case V_544 :
V_236 = F_70 ( V_512 , V_78 ) ;
break;
case V_545 :
V_236 = F_71 ( V_512 , V_78 ) ;
break;
case V_546 :
V_236 = F_72 ( V_2 , V_512 , V_78 ) ;
break;
case V_203 :
V_236 = F_29 ( V_2 , V_512 ,
V_5 , V_31 ,
V_78 ) ;
break;
case V_253 :
V_236 = F_30 ( V_2 , V_512 ,
V_5 ) ;
break;
case V_547 :
V_236 = F_73 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_548 :
V_236 = F_74 ( V_512 , V_5 ,
V_78 ) ;
break;
case V_549 :
V_236 = F_75 ( V_2 , V_512 , V_5 , V_78 ) ;
break;
case V_550 :
F_4 ( V_2 -> V_29 , V_36 ,
L_36 ) ;
V_512 -> V_6 = F_2 ( V_550 ) ;
V_512 -> V_8 =
F_2 ( sizeof( struct V_551 ) +
V_10 ) ;
V_236 = 0 ;
break;
case V_262 :
V_236 = F_31 ( V_512 , V_5 ,
V_78 ) ;
break;
case V_552 :
V_236 = F_76 ( V_2 , V_512 , V_78 ) ;
break;
case V_269 :
V_236 = F_32 ( V_512 , V_5 , V_78 ) ;
break;
case V_273 :
case V_277 :
case V_280 :
case V_283 :
case V_286 :
case V_288 :
V_236 = F_33 ( V_512 , V_5 , V_78 ) ;
break;
case V_553 :
V_512 -> V_6 = F_2 ( V_506 ) ;
if ( V_2 -> V_223 == V_224 )
V_512 -> V_11 . V_223 . V_554 =
V_555 ;
else if ( V_2 -> V_223 == V_556 ||
V_2 -> V_223 == V_557 )
V_512 -> V_11 . V_223 . V_554 =
V_558 ;
else if ( V_2 -> V_223 == V_559 ||
V_2 -> V_223 == V_560 )
V_512 -> V_11 . V_223 . V_554 = V_561 ;
V_512 -> V_8 = F_2 ( sizeof( struct
V_562 ) + V_10 ) ;
V_236 = 0 ;
break;
case V_300 :
V_236 = F_34 ( V_2 , V_512 , V_5 ) ;
break;
case V_328 :
V_236 = F_35 ( V_2 , V_512 , V_78 ) ;
break;
case V_363 :
V_236 = F_38 ( V_2 , V_512 , V_78 ) ;
break;
case V_424 :
V_236 = F_52 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_470 :
V_236 = F_54 ( V_2 , V_512 , V_78 ) ;
break;
case V_439 :
V_236 = F_53 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_563 :
V_236 = F_77 ( V_2 , V_512 ,
V_78 ) ;
break;
case V_503 :
V_236 = F_55 ( V_512 , V_5 ,
V_78 ) ;
break;
case V_504 :
V_236 = F_56 ( V_2 , V_512 ) ;
break;
case V_388 :
V_236 = F_47 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_394 :
V_236 = F_48 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_402 :
V_236 = F_49 ( V_2 , V_512 , V_5 ,
V_78 ) ;
break;
case V_414 :
V_236 = F_51 ( V_2 , V_512 , V_5 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_37 , V_506 ) ;
V_236 = - 1 ;
break;
}
return V_236 ;
}
int F_78 ( struct V_1 * V_2 , V_57 V_564 , bool V_565 )
{
struct V_105 * V_29 = V_2 -> V_29 ;
int V_236 ;
struct V_566 V_567 ;
struct V_568 V_569 ;
enum V_570 V_571 ;
struct V_572 V_573 ;
V_57 V_574 ;
T_1 V_575 ;
int V_380 ;
if ( V_564 ) {
if ( V_2 -> V_29 -> V_576 == V_577 ) {
V_236 = F_44 ( V_2 ,
V_300 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_236 )
return - 1 ;
}
V_236 = F_44 ( V_2 , V_539 ,
V_28 , 0 , NULL , true ) ;
if ( V_236 )
return - 1 ;
if ( V_29 -> V_381 ) {
if ( F_79 ( V_29 -> V_381 ,
L_38 ,
& V_380 ) == 0 ) {
F_80 ( L_39 , V_380 ) ;
V_29 -> V_107 . V_124 = V_380 ;
}
F_41 ( V_2 , V_29 -> V_381 ,
L_40 ) ;
}
if ( V_29 -> V_382 )
F_44 ( V_2 , V_379 ,
V_28 , 0 , NULL , true ) ;
V_236 = F_44 ( V_2 , V_513 ,
V_39 , 0 , NULL , true ) ;
if ( V_236 )
return - 1 ;
if ( V_2 -> V_29 -> V_576 == V_578 &&
F_81 ( V_2 -> V_29 -> V_507 ) &&
! V_2 -> V_29 -> V_579 ) {
V_574 = true ;
V_236 = F_44 ( V_2 ,
V_503 ,
V_28 , 0 ,
& V_574 ,
true ) ;
if ( V_236 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_41 ) ;
V_29 -> V_580 = false ;
}
}
V_236 = F_44 ( V_2 , V_547 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_581 , true ) ;
if ( V_236 )
return - 1 ;
if ( V_2 -> V_582 != V_583 ) {
V_2 -> V_29 -> V_584 = V_585 ;
V_236 = F_44 ( V_2 ,
V_514 ,
V_586 , V_587 , NULL ,
true ) ;
if ( V_236 )
return - 1 ;
}
if ( V_588 ) {
V_29 -> V_589 = true ;
if ( F_82 ( V_29 -> V_507 ) )
V_236 = F_44 ( V_2 ,
V_388 ,
V_28 , 0 ,
& V_29 -> V_589 ,
true ) ;
if ( V_236 )
return - 1 ;
}
F_44 ( V_2 , V_414 ,
V_39 , 0 , NULL , true ) ;
}
V_236 = F_44 ( V_2 , V_55 ,
V_39 , 0 , NULL , true ) ;
if ( V_236 )
return - 1 ;
V_2 -> V_590 = 0 ;
V_236 = F_44 ( V_2 , V_80 ,
V_39 , 0 , NULL , true ) ;
if ( V_236 )
return - 1 ;
memset ( & V_567 , 0 , sizeof( V_567 ) ) ;
V_567 . V_258 = true ;
V_236 = F_44 ( V_2 , V_548 ,
V_28 , 0 ,
& V_567 , true ) ;
if ( V_236 )
return - 1 ;
V_236 = F_44 ( V_2 , V_30 ,
V_28 , 0 ,
& V_2 -> V_591 , true ) ;
if ( V_236 )
return - 1 ;
if ( ! V_592 && V_564 &&
V_2 -> V_582 != V_583 ) {
V_569 . V_569 = V_593 ;
V_569 . V_594 = V_595 ;
V_236 = F_44 ( V_2 , V_514 ,
V_586 , V_596 ,
& V_569 , true ) ;
if ( V_236 )
return - 1 ;
}
if ( V_2 -> V_582 != V_583 ) {
V_571 = V_597 ;
V_236 = F_44 ( V_2 , V_37 ,
V_28 , V_598 ,
& V_571 , true ) ;
if ( V_236 )
F_4 ( V_2 -> V_29 , ERROR ,
L_42 ) ;
}
if ( V_599 ) {
V_575 = true ;
F_44 ( V_2 , V_533 ,
V_28 , 0 ,
& V_575 , true ) ;
}
V_573 . V_600 = V_601 ;
V_236 = F_44 ( V_2 , V_549 ,
V_28 , 0 , & V_573 , true ) ;
if ( V_565 ) {
V_2 -> V_29 -> V_602 = V_549 ;
V_236 = - V_603 ;
}
return V_236 ;
}
