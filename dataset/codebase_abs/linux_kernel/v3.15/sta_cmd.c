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
if ( V_2 -> V_29 -> V_65 == V_66 ) {
for ( V_55 = 0 ;
V_55 < F_11 ( V_52 -> V_67 ) ;
V_55 ++ )
V_52 -> V_67 [ V_55 ] =
F_2 ( V_47 [ 10 + V_55 ] ) ;
}
} else {
V_52 -> V_62 =
F_2 ( V_2 -> V_68 [ 0 ] ) ;
V_52 -> V_63 =
F_2 ( V_2 -> V_68 [ 1 ] ) ;
for ( V_55 = 0 ;
V_55 < sizeof( V_52 -> V_64 ) / sizeof( T_1 ) ;
V_55 ++ )
V_52 -> V_64 [ V_55 ] =
F_2 ( V_2 -> V_68 [ 2 + V_55 ] ) ;
if ( V_2 -> V_29 -> V_65 == V_66 ) {
for ( V_55 = 0 ;
V_55 < F_11 ( V_52 -> V_67 ) ;
V_55 ++ )
V_52 -> V_67 [ V_55 ] =
F_2 ( V_2 -> V_68 [ 10 + V_55 ] ) ;
}
}
V_54 = (struct V_53 * ) ( ( V_58 * ) V_52 +
sizeof( struct V_51 ) ) ;
V_54 -> type = F_2 ( V_69 ) ;
V_54 -> V_60 = F_2 ( sizeof( V_54 -> V_70 ) ) ;
V_54 -> V_70 = 0 ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_48 ) +
sizeof( struct V_51 ) +
sizeof( struct V_53 ) ) ;
return 0 ;
}
static int F_12 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_71 * V_72 )
{
struct V_73 * V_74 ;
struct V_71 * V_75 = & V_4 -> V_11 . V_76 ;
V_4 -> V_6 = F_2 ( V_77 ) ;
V_4 -> V_8 =
F_2 ( V_10 + sizeof( struct V_71 ) ) ;
switch ( V_5 ) {
case V_28 :
if ( V_72 -> V_78 ) {
V_74 = (struct V_73
* ) ( ( unsigned long ) V_72 +
sizeof( struct V_71 ) ) ;
memmove ( V_75 , V_72 ,
sizeof( struct V_71 ) +
sizeof( struct V_73 ) +
F_8 ( V_74 -> V_60 ) ) ;
V_74 = (struct V_73 * ) ( ( V_58 * )
V_75 +
sizeof( struct V_71 ) ) ;
V_4 -> V_8 = F_2 ( F_8 ( V_4 -> V_8 ) +
sizeof( struct V_73 ) +
F_8 ( V_74 -> V_60 ) ) ;
} else {
memmove ( V_75 , V_72 , sizeof( * V_72 ) ) ;
}
V_75 -> V_13 = F_2 ( V_5 ) ;
break;
case V_39 :
V_75 -> V_13 = F_2 ( V_5 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_80 * V_72 = & V_4 -> V_11 . V_72 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_80 )
+ V_10 ) ;
V_4 -> V_6 = F_2 ( V_81 ) ;
V_72 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_82 * V_83 )
{
struct V_84 * V_85 = & V_4 -> V_11 . V_85 ;
struct V_86 * V_87 = & V_4 -> V_11 . V_87 ;
V_4 -> V_6 = F_2 ( V_88 ) ;
if ( V_5 != V_28 )
return 0 ;
if ( V_2 -> V_29 -> V_89 == V_90 ) {
V_4 -> V_8 = F_2 ( sizeof( struct V_84 ) +
V_10 ) ;
V_85 -> V_91 = F_2 ( V_92 ) ;
V_85 -> V_93 = F_2 ( ( T_1 ) V_83 -> V_94 ) ;
V_85 -> V_95 = F_2 ( V_96 ) ;
V_85 -> V_97 = F_2 ( ( T_1 ) V_83 -> V_98 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( struct V_86 ) +
V_10 ) ;
V_87 -> V_13 = F_2 ( V_99 ) ;
V_87 -> V_100 = F_2 ( ( T_1 ) V_83 -> V_94 ) ;
}
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_101 * V_102 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
struct V_104 * V_105 = & V_4 -> V_11 . V_106 ;
bool V_107 = false ;
if ( ! V_102 )
V_107 = true ;
V_4 -> V_6 = F_2 ( V_108 ) ;
if ( ! V_107 &&
( V_102 -> V_109 != F_16 ( V_110 ) ) &&
( ( V_29 -> V_111 > 0 ) &&
( V_29 -> V_111 <= V_112 ) ) ) {
F_6 ( V_29 -> V_30 ,
L_5 ,
V_29 -> V_111 ) ;
memcpy ( ( ( V_58 * ) V_105 ) +
sizeof( struct V_104 ) ,
V_29 -> V_113 , V_29 -> V_111 ) ;
V_4 -> V_8 = F_2
( V_29 -> V_111 +
sizeof( struct V_104 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( V_10 + sizeof( struct
V_104 ) ) ;
}
if ( V_107 ) {
V_105 -> V_13 = F_2 ( V_114 ) ;
V_105 -> V_11 . V_107 . V_115 = F_2 ( V_116 ) ;
} else {
V_105 -> V_13 = F_2 ( V_117 ) ;
V_105 -> V_11 . V_118 . V_109 = V_102 -> V_109 ;
V_105 -> V_11 . V_118 . V_119 = V_102 -> V_119 ;
V_105 -> V_11 . V_118 . V_120 = V_102 -> V_120 ;
F_6 ( V_29 -> V_30 ,
L_6 ,
V_105 -> V_11 . V_118 . V_109 ,
V_105 -> V_11 . V_118 . V_119 ,
V_105 -> V_11 . V_118 . V_120 ) ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_121 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_122 ) +
V_10 ) ;
V_4 -> V_123 = 0 ;
V_4 -> V_11 . V_124 . V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 )
memcpy ( V_4 -> V_11 . V_124 . V_124 , V_2 -> V_125 ,
V_126 ) ;
return 0 ;
}
static int
F_18 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_127 * V_128 )
{
struct V_129 * V_130 = & V_4 -> V_11 . V_131 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_129 ) +
V_10 ) ;
V_4 -> V_6 = F_2 ( V_132 ) ;
V_130 -> V_13 = F_2 ( V_5 ) ;
V_130 -> V_133 =
F_2 ( ( T_1 ) V_128 -> V_134 ) ;
memcpy ( V_130 -> V_135 , V_128 -> V_135 ,
V_128 -> V_134 * V_126 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
V_58 * V_136 )
{
struct V_137 * V_138 = & V_4 -> V_11 . V_138 ;
V_4 -> V_6 = F_2 ( V_139 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_137 )
+ V_10 ) ;
memcpy ( V_138 -> V_124 , V_136 , V_126 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_7 , V_138 -> V_124 ) ;
V_138 -> V_140 = F_2 ( V_141 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_142 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 ,
struct V_143 * V_144 ,
T_1 * V_145 )
{
int V_146 ;
V_58 V_55 ;
for ( V_55 = 0 ; V_55 < V_147 ; V_55 ++ ) {
if ( ( V_2 -> V_148 [ V_55 ] . V_149 == V_150 ) ||
( V_2 -> V_148 [ V_55 ] . V_149 == V_151 ) ) {
V_144 -> type =
F_2 ( V_152 ) ;
#define F_22 8
V_144 -> V_60 = F_2 ( ( T_1 )
( V_2 -> V_148 [ V_55 ] .
V_149 +
F_22 ) ) ;
V_144 -> V_153 =
F_2 ( V_154 ) ;
V_144 -> V_155 =
F_2 ( V_156 | V_157 |
V_158 ) ;
V_144 -> V_159 =
F_2 ( V_2 -> V_148 [ V_55 ] . V_149 ) ;
V_144 -> V_160 [ 0 ] = V_55 ;
if ( V_55 ==
( V_2 ->
V_161 & V_162 ) )
V_144 -> V_160 [ 1 ] = 1 ;
else
V_144 -> V_160 [ 1 ] = 0 ;
memmove ( & V_144 -> V_160 [ 2 ] ,
V_2 -> V_148 [ V_55 ] . V_163 ,
V_2 -> V_148 [ V_55 ] . V_149 ) ;
V_146 = V_2 -> V_148 [ V_55 ] . V_149 +
F_22 +
sizeof( struct V_61 ) ;
* V_145 += ( T_1 ) V_146 ;
V_144 =
(struct V_143 * )
( ( V_58 * ) V_144 +
V_146 ) ;
} else if ( ! V_2 -> V_148 [ V_55 ] . V_149 ) {
continue;
} else {
F_4 ( V_2 -> V_29 -> V_30 ,
L_8 ,
( V_55 + 1 ) , V_2 -> V_148 [ V_55 ] . V_149 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_164 * V_165 ,
struct V_166 * V_167 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
T_1 V_8 , V_168 = V_169 ;
if ( V_165 -> V_170 ) {
F_6 ( V_29 -> V_30 , L_9 , V_171 ) ;
if ( V_165 -> V_172 )
memcpy ( V_167 -> V_144 . V_173 . V_174 . V_175 ,
V_165 -> V_176 , V_165 -> V_177 ) ;
V_167 -> V_144 . V_155 &= F_2 ( ~ V_158 ) ;
V_167 -> V_144 . V_155 |= F_2 ( V_178 ) ;
V_167 -> V_144 . V_179 = V_180 ;
V_167 -> V_144 . V_173 . V_174 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_173 . V_174 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_168 += sizeof( struct V_181 ) ;
} else {
F_6 ( V_29 -> V_30 , L_10 , V_171 ) ;
if ( V_165 -> V_172 )
memcpy ( V_167 -> V_144 . V_173 . V_182 . V_176 ,
V_165 -> V_176 , V_165 -> V_177 ) ;
V_167 -> V_144 . V_179 = V_183 ;
V_167 -> V_144 . V_173 . V_182 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_173 . V_182 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_168 += sizeof( struct V_184 ) ;
}
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_8 = V_168 + sizeof( struct V_61 ) +
sizeof( V_167 -> V_13 ) + V_10 ;
V_4 -> V_8 = F_2 ( V_8 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_32 ,
struct V_164 * V_165 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
V_58 * V_136 = V_165 -> V_124 ;
T_1 V_155 , V_168 = V_169 ;
struct V_166 * V_167 =
& V_4 -> V_11 . V_185 ;
V_4 -> V_6 = F_2 ( V_186 ) ;
V_167 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
F_6 ( V_29 -> V_30 , L_11 , V_171 ) ;
V_167 -> V_144 . V_187 =
V_165 -> V_188 & V_189 ;
V_167 -> V_144 . type = F_2 ( V_190 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_169 ) ;
memcpy ( V_167 -> V_144 . V_124 , V_136 , V_126 ) ;
if ( V_165 -> V_188 & V_191 )
V_155 = V_157 ;
else
V_155 = V_158 ;
if ( V_165 -> V_170 )
V_155 |= V_178 ;
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_10 + V_169 +
sizeof( V_167 -> V_13 ) ) ;
return 0 ;
}
memset ( & V_167 -> V_144 , 0 ,
sizeof( struct V_192 ) ) ;
if ( V_165 -> V_193 ) {
F_6 ( V_29 -> V_30 , L_12 , V_171 ) ;
V_167 -> V_13 = F_2 ( V_194 ) ;
V_167 -> V_144 . type = F_2 ( V_190 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_169 ) ;
V_167 -> V_144 . V_187 = V_165 -> V_188 & V_189 ;
V_155 = V_158 | V_157 ;
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
memcpy ( V_167 -> V_144 . V_124 , V_136 , V_126 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_10 + V_169 +
sizeof( V_167 -> V_13 ) ) ;
return 0 ;
}
V_167 -> V_13 = F_2 ( V_28 ) ;
V_167 -> V_144 . V_187 = V_165 -> V_188 & V_189 ;
V_167 -> V_144 . type = F_2 ( V_190 ) ;
V_155 = V_156 ;
memcpy ( V_167 -> V_144 . V_124 , V_136 , V_126 ) ;
if ( V_165 -> V_159 <= V_151 ) {
F_6 ( V_29 -> V_30 , L_13 , V_171 ) ;
V_168 += sizeof( struct V_195 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_167 -> V_144 . V_179 = V_154 ;
if ( F_25 ( V_2 ) == V_196 ) {
V_155 |= V_158 | V_157 ;
} else {
if ( V_165 -> V_197 ) {
V_155 |= V_158 | V_157 ;
if ( V_167 -> V_144 . V_187 ==
( V_2 -> V_161 & V_189 ) )
V_155 |= V_198 ;
} else {
if ( V_136 ) {
if ( F_26 ( V_136 ) )
V_155 |= V_158 ;
else
V_155 |= V_157 |
V_198 ;
} else {
V_155 |= V_158 ;
}
}
}
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
V_167 -> V_144 . V_173 . V_199 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_173 . V_199 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_168 + sizeof( V_167 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( F_26 ( V_136 ) )
V_155 |= V_158 | V_200 ;
else
V_155 |= V_157 | V_201 | V_200 ;
if ( V_165 -> V_202 ) {
F_6 ( V_29 -> V_30 , L_14 , V_171 ) ;
V_167 -> V_144 . V_179 = V_203 ;
memcpy ( V_167 -> V_144 . V_173 . V_204 . V_176 , V_165 -> V_176 ,
V_205 ) ;
V_167 -> V_144 . V_173 . V_204 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_173 . V_204 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
if ( F_26 ( V_136 ) )
V_2 -> V_206 . V_207 = true ;
if ( ! V_2 -> V_206 . V_207 )
V_155 |= V_198 ;
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
V_168 += sizeof( struct V_208 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_168 + sizeof( V_167 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( V_2 -> V_209 == V_210 ) {
V_155 |= V_198 ;
if ( ! V_2 -> V_206 . V_211 &&
! F_26 ( V_136 ) )
V_155 |= V_157 ;
} else {
if ( ! V_2 -> V_212 )
V_155 |= V_198 ;
}
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
if ( V_165 -> V_159 == V_213 )
return F_23 ( V_2 , V_4 , V_165 , V_167 ) ;
if ( V_165 -> V_159 == V_214 ) {
F_6 ( V_29 -> V_30 , L_15 , V_171 ) ;
if ( V_165 -> V_172 )
memcpy ( V_167 -> V_144 . V_173 . V_215 . V_176 ,
V_165 -> V_176 , V_165 -> V_177 ) ;
V_167 -> V_144 . V_179 = V_216 ;
V_167 -> V_144 . V_173 . V_215 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_173 . V_215 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_168 += sizeof( struct V_217 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_168 + sizeof( V_167 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_32 ,
struct V_164 * V_165 )
{
struct V_218 * V_163 =
& V_4 -> V_11 . V_163 ;
struct V_219 * V_220 ;
T_1 V_145 = 0 , V_221 ;
int V_222 = 0 ;
V_4 -> V_6 = F_2 ( V_186 ) ;
V_163 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_163 -> V_13 ) + V_10 ) ;
return V_222 ;
}
if ( ! V_165 ) {
memset ( & V_163 -> V_144 , 0 ,
( V_147 *
sizeof( struct V_143 ) ) ) ;
V_222 = F_21 ( V_2 ,
& V_163 -> V_144 ,
& V_145 ) ;
V_4 -> V_8 = F_2 ( V_145 +
sizeof( V_163 -> V_13 ) + V_10 ) ;
return V_222 ;
} else
memset ( & V_163 -> V_144 , 0 ,
sizeof( struct V_143 ) ) ;
if ( V_165 -> V_202 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_16 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_203 ) ;
if ( V_32 == V_223 )
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
else
V_163 -> V_144 . V_155 =
F_2 ( ! V_156 ) ;
V_163 -> V_144 . V_160 [ 0 ] = V_165 -> V_188 ;
if ( ! V_2 -> V_206 . V_207 )
V_163 -> V_144 . V_160 [ 1 ] = 1 ;
else
V_163 -> V_144 . V_160 [ 1 ] = 0 ;
if ( ! F_26 ( V_165 -> V_124 ) ) {
V_163 -> V_144 . V_155 |=
F_2 ( V_157 ) ;
} else {
V_163 -> V_144 . V_155 |=
F_2 ( V_158 ) ;
V_2 -> V_206 . V_207 = true ;
}
V_163 -> V_144 . type =
F_2 ( V_152 ) ;
V_163 -> V_144 . V_159 =
F_2 ( V_224 ) ;
memcpy ( & V_163 -> V_144 . V_160 [ 2 ] ,
V_165 -> V_163 , V_165 -> V_159 ) ;
memcpy ( & V_163 -> V_144 . V_160 [ 2 + V_165 -> V_159 ] ,
V_165 -> V_176 , V_205 ) ;
V_163 -> V_144 . V_60 =
F_2 ( V_224 + V_225 ) ;
V_145 = ( V_224 + V_225 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_163 -> V_13 )
+ V_10 + V_145 ) ;
return V_222 ;
}
if ( V_165 -> V_159 == V_213 ) {
if ( V_165 -> V_170 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_17 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_180 ) ;
if ( V_32 == V_223 )
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
else
V_163 -> V_144 . V_155 =
F_2 ( ! V_156 ) ;
V_163 -> V_144 . V_155 |=
F_2 ( V_178 ) ;
} else {
F_6 ( V_2 -> V_29 -> V_30 , L_18 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_183 ) ;
if ( V_32 == V_223 )
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
else
V_163 -> V_144 . V_155 =
F_2 ( ! V_156 ) ;
if ( V_165 -> V_188 & V_191 )
V_163 -> V_144 . V_155 |=
F_2 ( V_157 ) ;
else
V_163 -> V_144 . V_155 |=
F_2 ( V_158 ) ;
}
} else if ( V_165 -> V_159 == V_214 ) {
F_6 ( V_2 -> V_29 -> V_30 , L_19 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_216 ) ;
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
if ( V_165 -> V_188 & V_191 )
V_163 -> V_144 . V_155 |=
F_2 ( V_157 ) ;
else
V_163 -> V_144 . V_155 |=
F_2 ( V_158 ) ;
}
if ( V_163 -> V_144 . V_153 ) {
V_163 -> V_144 . type =
F_2 ( V_152 ) ;
V_163 -> V_144 . V_159 =
F_2 ( ( T_1 ) V_165 -> V_159 ) ;
memcpy ( V_163 -> V_144 . V_160 , V_165 -> V_163 ,
V_165 -> V_159 ) ;
V_163 -> V_144 . V_60 =
F_2 ( ( T_1 ) V_165 -> V_159 +
V_225 ) ;
V_145 = ( T_1 ) ( V_165 -> V_159 + V_225 )
+ sizeof( struct V_61 ) ;
if ( F_8 ( V_163 -> V_144 . V_153 ) ==
V_180 ) {
struct V_226 * V_227 =
( void * ) V_163 -> V_144 . V_160 ;
memcpy ( V_227 -> V_175 , V_165 -> V_176 , V_228 ) ;
memcpy ( V_227 -> V_160 , V_165 -> V_163 ,
V_229 ) ;
V_145 = sizeof( struct V_226 ) ;
V_163 -> V_144 . V_159 =
F_2 ( V_145 ) ;
V_145 += V_225 ;
V_163 -> V_144 . V_60 =
F_2 ( V_145 ) ;
V_145 += sizeof( struct V_61 ) ;
}
V_4 -> V_8 = F_2 ( sizeof( V_163 -> V_13 ) + V_10
+ V_145 ) ;
if ( V_2 -> V_230 == V_231 ) {
V_220 = ( void * ) ( ( V_58 * ) & V_163 -> V_144 +
V_145 ) ;
V_220 -> V_232 . type =
F_2 ( V_233 ) ;
V_220 -> V_232 . V_168 = F_2 ( V_126 ) ;
memcpy ( V_220 -> V_124 , V_165 -> V_124 , V_126 ) ;
V_221 = V_145 + V_10 +
sizeof( V_163 -> V_13 ) +
sizeof( struct V_219 ) ;
} else {
V_221 = V_145 + V_10 +
sizeof( V_163 -> V_13 ) ;
}
V_4 -> V_8 = F_2 ( V_221 ) ;
}
return V_222 ;
}
static int
F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_32 ,
struct V_164 * V_165 )
{
if ( V_2 -> V_29 -> V_234 == V_235 )
return F_24 ( V_2 , V_4 ,
V_5 , V_32 ,
V_165 ) ;
else
return F_27 ( V_2 , V_4 ,
V_5 , V_32 ,
V_165 ) ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
struct V_236 * V_237 =
& V_4 -> V_11 . V_237 ;
struct V_238 * V_239 =
& V_237 -> V_239 ;
V_58 V_240 = V_29 -> V_241 . V_240 ;
F_6 ( V_29 -> V_30 , L_20 , V_240 ) ;
V_4 -> V_6 = F_2 ( V_242 ) ;
V_237 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_237 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_239 -> V_232 . type = F_2 ( V_243 ) ;
memcpy ( V_239 -> V_244 , V_29 -> V_241 . V_244 ,
sizeof( V_239 -> V_244 ) ) ;
V_239 -> V_232 . V_168 =
F_2 ( ( V_240 *
sizeof( struct V_245 ) )
+ sizeof( V_239 -> V_244 ) ) ;
if ( V_240 ) {
memcpy ( V_239 -> V_246 , V_29 -> V_241 . V_246 ,
V_240 * sizeof( struct
V_245 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_237 -> V_13 ) +
F_8 ( V_239 -> V_232 . V_168 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_237 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_30 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_247 )
{
struct V_248 * V_249 =
& ( V_4 -> V_11 . V_250 ) ;
V_4 -> V_6 = F_2 ( V_251 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_248 ) +
V_10 ) ;
V_4 -> V_123 = 0 ;
V_249 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_247 )
V_249 -> V_247 = F_2 ( * V_247 ) ;
else
V_249 -> V_247 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_252 * V_253 = V_79 ;
switch ( F_8 ( V_4 -> V_6 ) ) {
case V_254 :
{
struct V_255 * V_256 ;
V_4 -> V_8 = F_2 ( sizeof( * V_256 ) + V_10 ) ;
V_256 = & V_4 -> V_11 . V_256 ;
V_256 -> V_13 = F_2 ( V_5 ) ;
V_256 -> V_257 =
F_2 ( ( T_1 ) F_32 ( V_253 -> V_257 ) ) ;
V_256 -> V_44 = V_253 -> V_44 ;
break;
}
case V_258 :
{
struct V_259 * V_260 ;
V_4 -> V_8 = F_2 ( sizeof( * V_260 ) + V_10 ) ;
V_260 = & V_4 -> V_11 . V_260 ;
V_260 -> V_13 = F_2 ( V_5 ) ;
V_260 -> V_257 =
F_2 ( ( T_1 ) F_32 ( V_253 -> V_257 ) ) ;
V_260 -> V_44 = ( V_58 ) F_32 ( V_253 -> V_44 ) ;
break;
}
case V_261 :
{
struct V_262 * V_263 ;
V_4 -> V_8 = F_2 ( sizeof( * V_263 ) + V_10 ) ;
V_263 = & V_4 -> V_11 . V_263 ;
V_263 -> V_13 = F_2 ( V_5 ) ;
V_263 -> V_257 = F_2 ( ( T_1 ) F_32 ( V_253 -> V_257 ) ) ;
V_263 -> V_44 = ( V_58 ) F_32 ( V_253 -> V_44 ) ;
break;
}
case V_264 :
{
struct V_265 * V_266 ;
V_4 -> V_8 = F_2 ( sizeof( * V_266 ) + V_10 ) ;
V_266 = & V_4 -> V_11 . V_266 ;
V_266 -> V_13 = F_2 ( V_5 ) ;
V_266 -> V_257 =
F_2 ( ( T_1 ) F_32 ( V_253 -> V_257 ) ) ;
V_266 -> V_44 = ( V_58 ) F_32 ( V_253 -> V_44 ) ;
break;
}
case V_267 :
{
struct V_262 * V_268 ;
V_4 -> V_8 = F_2 ( sizeof( * V_268 ) + V_10 ) ;
V_268 = & V_4 -> V_11 . V_263 ;
V_268 -> V_13 = F_2 ( V_5 ) ;
V_268 -> V_257 =
F_2 ( ( T_1 ) F_32 ( V_253 -> V_257 ) ) ;
V_268 -> V_44 = ( V_58 ) F_32 ( V_253 -> V_44 ) ;
break;
}
case V_269 :
{
struct V_270 * V_271 = V_79 ;
struct V_272 * V_273 =
& V_4 -> V_11 . V_274 ;
V_4 -> V_8 = F_2 ( sizeof( * V_273 ) + V_10 ) ;
V_273 -> V_13 = F_2 ( V_5 ) ;
V_273 -> V_257 = V_271 -> V_257 ;
V_273 -> V_275 = V_271 -> V_275 ;
V_273 -> V_44 = 0 ;
break;
}
default:
return - 1 ;
}
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_13 )
{
struct V_276 * V_277 =
& V_4 -> V_11 . V_278 ;
struct V_279 * V_280 = V_2 -> V_29 -> V_280 ;
V_4 -> V_6 = F_2 ( V_281 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_276 ) + V_10 ) ;
V_4 -> V_123 = 0 ;
memset ( V_277 , 0 , sizeof( struct V_276 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_277 -> V_282 = ( T_2 ) ( V_280 -> V_283 ) ;
V_277 -> V_284 = ( T_2 ) ( ( ( V_285 ) V_280 -> V_283 ) >> 32 ) ;
V_277 -> V_286 = V_287 ;
V_277 -> V_288 = ( T_2 ) ( V_280 -> V_289 ) ;
V_277 -> V_290 = ( T_2 ) ( ( ( V_285 ) V_280 -> V_289 ) >> 32 ) ;
V_277 -> V_291 = V_287 ;
V_277 -> V_292 = ( T_2 ) ( V_280 -> V_293 ) ;
V_277 -> V_294 = ( T_2 ) ( ( ( V_285 ) V_280 -> V_293 ) >> 32 ) ;
V_277 -> V_295 = V_296 ;
if ( V_280 -> V_297 ) {
V_277 -> V_298 =
( T_2 ) ( V_280 -> V_299 ) ;
V_277 -> V_300 =
( T_2 ) ( ( ( V_285 ) ( V_280 -> V_299 ) ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_21 ,
V_277 -> V_298 ) ;
}
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_301 * V_302 )
{
struct V_303 * V_304 = & V_4 -> V_11 . V_304 ;
struct V_305 * V_306 ;
T_1 V_307 ;
V_58 * V_308 ;
V_4 -> V_6 = F_2 ( V_309 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_303 ) +
V_10 ) ;
V_304 -> V_13 = F_2 ( V_302 -> V_13 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_22 , V_302 -> V_13 ) ;
if ( V_302 -> V_13 == V_39 )
return 0 ;
V_304 -> V_310 = F_2 ( V_302 -> V_310 ) ;
V_307 = V_302 -> V_310 ;
F_6 ( V_2 -> V_29 -> V_30 , L_23 ,
V_307 ) ;
if ( ( ( V_302 -> V_13 == V_311 ) ||
( V_302 -> V_13 == V_312 ) ) &&
( V_307 == 0 ) ) {
F_6 ( V_2 -> V_29 -> V_30 , L_24
L_25 ) ;
return - V_313 ;
}
if ( V_302 -> V_13 == V_311 )
return 0 ;
V_308 = ( ( V_58 * ) V_304 ) +
sizeof( struct V_303 ) ;
if ( V_307 & V_314 ) {
V_306 = (struct V_305 * ) V_308 ;
V_306 -> V_232 . type = F_2 ( V_315 ) ;
V_306 -> V_232 . V_168 =
F_2 ( sizeof( struct V_305 ) -
sizeof( struct V_61 ) ) ;
V_306 -> V_316 = V_302 -> V_317 . V_316 ;
V_306 -> V_318 = V_302 -> V_317 . V_318 ;
F_6 ( V_2 -> V_29 -> V_30 , L_26
L_27 ,
V_302 -> V_317 . V_316 ,
V_302 -> V_317 . V_318 ) ;
V_308 += sizeof( struct V_305 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_305 ) ) ;
}
if ( V_307 & V_319 ) {
V_306 = (struct V_305 * ) V_308 ;
V_306 -> V_232 . type = F_2 ( V_320 ) ;
V_306 -> V_232 . V_168 =
F_2 ( sizeof( struct V_305 ) -
sizeof( struct V_61 ) ) ;
V_306 -> V_316 = V_302 -> V_321 . V_316 ;
V_306 -> V_318 = V_302 -> V_321 . V_318 ;
F_6 ( V_2 -> V_29 -> V_30 , L_28
L_27 ,
V_302 -> V_321 . V_316 ,
V_302 -> V_321 . V_318 ) ;
V_308 += sizeof( struct V_305 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_305 ) ) ;
}
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_322 * V_323 ,
V_58 * * V_324 )
{
struct V_325 * V_326 = V_323 -> V_326 ;
int V_55 , V_327 ;
V_58 * V_328 = * V_324 ;
for ( V_55 = 0 ; V_55 < V_329 ; V_55 ++ ) {
V_326 = & V_323 -> V_326 [ V_55 ] ;
if ( ! V_326 -> V_330 )
break;
* ( V_331 * ) V_328 = F_16 ( ( T_2 ) V_326 -> V_332 ) ;
V_328 += 4 ;
* V_328 = V_333 ;
V_328 += 1 ;
V_327 = V_326 -> V_334 [ V_335 ] ;
memcpy ( V_328 , V_326 -> V_334 , V_327 ) ;
V_328 += V_327 ;
* V_328 = V_327 ;
V_328 += 1 ;
* V_328 = V_336 ;
V_328 += 1 ;
* ( V_331 * ) V_328 = F_16 ( ( T_2 ) V_326 -> V_257 ) ;
V_328 += 4 ;
* V_328 = V_333 ;
V_328 += 1 ;
* V_328 = V_326 -> V_330 ;
V_328 += 1 ;
if ( V_326 -> V_337 ) {
* V_328 = V_326 -> V_337 ;
V_328 += 1 ;
}
if ( V_328 - * V_324 > V_338 )
return - 1 ;
}
* V_324 = V_328 ;
return 0 ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_339 * V_340 )
{
struct V_341 * V_342 = & V_4 -> V_11 . V_342 ;
V_58 * V_308 = ( V_58 * ) V_342 ;
V_4 -> V_6 = F_2 ( V_343 ) ;
V_342 -> V_344 = F_16 ( V_340 -> V_344 ) ;
V_342 -> V_345 = F_2 ( V_340 -> V_345 ) ;
V_308 += sizeof( * V_342 ) ;
V_342 -> V_323 -> V_78 = V_340 -> V_323 -> V_78 ;
V_342 -> V_323 -> V_13 = V_340 -> V_323 -> V_13 ;
V_308 += sizeof( * ( V_342 -> V_323 ) ) ;
if ( F_35 ( V_2 , V_340 -> V_323 , & V_308 ) )
return - 1 ;
V_342 -> V_323 -> V_346 =
F_2 ( V_308 - V_342 -> V_323 -> V_347 ) ;
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_308 - ( V_58 * ) V_342 ) + V_10 ) ;
return 0 ;
}
static T_2 F_37 ( V_58 * V_348 , T_3 V_168 , V_58 * V_349 )
{
V_58 * V_350 = V_348 , * V_351 = V_349 ;
while ( V_350 - V_348 < V_168 ) {
if ( * V_350 && ( isspace ( * V_350 ) || * V_350 == '\t' ) ) {
V_350 ++ ;
continue;
}
if ( isxdigit ( * V_350 ) ) {
* V_351 ++ = F_38 ( V_350 , NULL , 16 ) ;
V_350 += 2 ;
} else {
V_350 ++ ;
}
}
return V_351 - V_349 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_352 * V_353 , const char * V_354 )
{
#ifdef F_40
struct V_355 * V_356 ;
T_3 V_168 = strlen ( V_354 ) ;
int V_222 ;
F_41 (node, prop) {
if ( V_168 > strlen ( V_356 -> V_357 ) ||
strncmp ( V_356 -> V_357 , V_354 , V_168 ) )
continue;
if ( V_356 && V_356 -> V_44 && V_356 -> V_60 > 6 &&
V_356 -> V_60 <= V_358 - V_10 ) {
V_222 = F_42 ( V_2 , V_359 ,
V_28 , 0 ,
V_356 , true ) ;
if ( V_222 )
return V_222 ;
}
}
#endif
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_79 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
struct V_355 * V_356 = V_79 ;
T_2 V_168 ;
V_58 * V_360 = ( V_58 * ) V_4 + V_10 ;
int V_222 ;
if ( V_356 ) {
V_168 = V_356 -> V_60 ;
V_222 = F_44 ( V_29 -> V_361 , V_356 -> V_357 ,
V_360 , V_168 ) ;
if ( V_222 )
return V_222 ;
F_6 ( V_29 -> V_30 ,
L_29 , V_356 -> V_357 ) ;
} else if ( V_29 -> V_362 -> V_360 && V_29 -> V_362 -> V_8 > 0 ) {
V_168 = F_37 ( ( V_58 * ) V_29 -> V_362 -> V_360 ,
V_29 -> V_362 -> V_8 , V_360 ) ;
F_6 ( V_29 -> V_30 , L_30 ) ;
} else {
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_359 ) ;
V_4 -> V_8 = F_2 ( V_10 + V_168 ) ;
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_363 * V_364 =
& V_4 -> V_11 . V_364 ;
struct V_365 * V_366 = V_79 ;
struct V_367 * V_227 ;
T_1 V_368 , V_369 , V_60 ;
struct V_370 * V_371 ;
V_4 -> V_6 = F_2 ( V_372 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_364 -> V_13 = F_2 ( V_5 ) ;
V_364 -> V_373 = F_2 ( V_366 -> V_373 ) ;
V_371 = V_364 -> V_371 ;
for ( V_368 = 0 ; V_368 < V_366 -> V_373 ; V_368 ++ ) {
V_371 -> V_232 . type = F_2 ( V_374 ) ;
V_371 -> V_375 =
F_2 ( V_366 -> V_371 [ V_368 ] . V_375 ) ;
V_371 -> V_376 = V_366 -> V_371 [ V_368 ] . V_376 ;
V_371 -> V_377 = V_366 -> V_371 [ V_368 ] . V_377 ;
V_60 = 0 ;
V_227 = V_371 -> V_11 ;
for ( V_369 = 0 ; V_369 < V_366 -> V_371 [ V_368 ] . V_377 ; V_369 ++ ) {
V_227 -> V_378 = V_366 -> V_371 [ V_368 ] . V_11 [ V_369 ] . V_378 ;
V_227 -> V_379 =
V_366 -> V_371 [ V_368 ] . V_11 [ V_369 ] . V_379 ;
V_227 -> V_257 =
F_2 ( V_366 -> V_371 [ V_368 ] . V_11 [ V_369 ] . V_257 ) ;
memcpy ( V_227 -> V_380 ,
V_366 -> V_371 [ V_368 ] . V_11 [ V_369 ] . V_380 ,
V_227 -> V_379 ) ;
V_60 += sizeof( struct V_367 ) ;
V_227 ++ ;
}
V_371 -> V_232 . V_168 = F_2 ( V_60 + sizeof( T_1 ) +
sizeof( V_58 ) + sizeof( V_58 ) ) ;
F_7 ( & V_4 -> V_8 , F_8 ( V_371 -> V_232 . V_168 ) +
sizeof( struct V_61 ) ) ;
V_371 = ( void * ) ( ( V_58 * ) V_371 -> V_11 + V_60 ) ;
}
F_7 ( & V_4 -> V_8 , sizeof( T_1 ) + sizeof( T_1 ) ) ;
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_79 )
{
struct V_381 * V_382 = & V_4 -> V_11 . V_382 ;
struct V_383 * V_384 = V_79 ;
struct V_385 * V_386 ;
struct V_387 * V_388 ;
struct V_389 * V_390 ;
struct V_391 * V_392 ;
struct V_393 * V_394 ;
struct V_395 * V_396 ;
struct V_397 * V_398 ;
V_58 * V_308 , V_399 ;
T_1 V_400 = 0 ;
struct V_401 * V_11 = V_2 -> V_402 ;
V_4 -> V_6 = F_2 ( V_403 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
F_7 ( & V_4 -> V_8 , sizeof( struct V_381 ) ) ;
V_382 -> V_404 = 0 ;
memcpy ( V_382 -> V_405 , V_384 -> V_405 , V_126 ) ;
V_386 = F_47 ( V_2 , V_384 -> V_405 ) ;
V_308 = ( V_58 * ) V_382 + sizeof( struct V_381 ) ;
switch ( V_384 -> V_406 ) {
case V_407 :
V_382 -> V_406 = F_2 ( V_408 ) ;
break;
case V_409 :
V_382 -> V_406 = F_2 ( V_410 ) ;
break;
case V_411 :
V_382 -> V_406 = F_2 ( V_412 ) ;
if ( ! V_11 ) {
F_4 ( V_2 -> V_29 -> V_30 ,
L_31 ,
V_384 -> V_405 ) ;
return - V_413 ;
}
* ( V_43 * ) V_308 = F_2 ( V_11 -> V_414 ) ;
V_400 += sizeof( V_11 -> V_414 ) ;
V_399 = V_11 -> V_415 | ( V_11 -> V_416 << 5 ) ;
V_392 = (struct V_391 * ) ( V_308 +
V_400 ) ;
V_392 -> V_232 . type = F_2 ( V_417 ) ;
V_392 -> V_232 . V_168 = F_2 ( sizeof( V_399 ) ) ;
V_392 -> V_399 = V_399 ;
V_400 += sizeof( struct V_391 ) ;
if ( V_11 -> V_418 ) {
V_390 = (struct V_389 * ) ( V_308 +
V_400 ) ;
V_390 -> V_232 . type =
F_2 ( V_419 ) ;
V_390 -> V_232 . V_168 =
F_2 ( sizeof( struct V_420 ) ) ;
memcpy ( & V_390 -> V_421 , V_11 -> V_418 ,
sizeof( struct V_420 ) ) ;
V_400 += sizeof( struct V_389 ) ;
}
if ( V_11 -> V_422 && V_11 -> V_423 ) {
V_388 = (struct V_387 * ) ( V_308 +
V_400 ) ;
V_388 -> V_232 . type =
F_2 ( V_424 ) ;
V_388 -> V_232 . V_168 =
F_2 ( V_11 -> V_423 ) ;
memcpy ( V_388 -> V_425 , V_11 -> V_422 ,
V_11 -> V_423 ) ;
V_400 += sizeof( struct V_387 ) +
V_11 -> V_423 ;
}
if ( V_11 -> V_426 && V_11 -> V_427 ) {
V_394 = (struct V_393 * ) ( V_308 +
V_400 ) ;
V_394 -> V_232 . type =
F_2 ( V_428 ) ;
V_394 -> V_232 . V_168 = F_2 ( V_11 -> V_427 ) ;
memcpy ( V_394 -> V_426 , V_11 -> V_426 ,
V_11 -> V_427 ) ;
V_400 += sizeof( struct V_393 ) +
V_11 -> V_427 ;
}
if ( V_11 -> V_429 ) {
V_396 = (struct V_395 * ) ( V_308 +
V_400 ) ;
V_396 -> V_232 . type =
F_2 ( V_430 ) ;
V_396 -> V_232 . V_168 =
F_2 ( sizeof( struct V_431 ) ) ;
memcpy ( & V_396 -> V_432 , V_11 -> V_429 ,
sizeof( struct V_431 ) ) ;
V_400 += sizeof( struct V_395 ) ;
}
if ( V_11 -> V_398 ) {
V_398 = (struct V_397 * ) ( V_308 + V_400 ) ;
V_398 -> V_232 . type = F_2 ( V_433 ) ;
V_398 -> V_232 . V_168 = F_2 ( sizeof( V_11 -> V_398 ) ) ;
V_398 -> V_398 = F_2 ( V_11 -> V_398 ) ;
V_400 += sizeof( struct V_397 ) ;
}
break;
default:
F_4 ( V_2 -> V_29 -> V_30 , L_32 ) ;
return - V_434 ;
}
F_7 ( & V_4 -> V_8 , V_400 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 , T_4 V_435 ,
T_1 V_5 , T_2 V_32 ,
void * V_79 , void * V_436 )
{
struct V_3 * V_437 = V_436 ;
int V_222 = 0 ;
switch ( V_435 ) {
case V_438 :
V_222 = F_49 ( V_2 , V_437 ) ;
break;
case V_359 :
V_222 = F_43 ( V_2 , V_437 , V_79 ) ;
break;
case V_31 :
V_222 = F_3 ( V_2 , V_437 , V_5 ,
V_79 ) ;
break;
case V_121 :
V_222 = F_17 ( V_2 , V_437 ,
V_5 ) ;
break;
case V_132 :
V_222 = F_18 ( V_437 , V_5 ,
V_79 ) ;
break;
case V_56 :
V_222 = F_10 ( V_2 , V_437 , V_5 ,
V_79 ) ;
break;
case V_77 :
V_222 = F_12 ( V_437 , V_5 ,
V_79 ) ;
break;
case V_81 :
V_222 = F_13 ( V_2 , V_437 , V_5 ,
V_79 ) ;
break;
case V_88 :
V_222 = F_14 ( V_2 , V_437 , V_5 ,
V_79 ) ;
break;
case V_439 :
V_222 = F_50 ( V_2 , V_437 , V_5 ,
( T_4 ) V_32 , V_79 ) ;
break;
case V_108 :
V_222 = F_15 ( V_2 , V_437 , V_5 ,
(struct V_101 * ) V_79 ) ;
break;
case V_440 :
V_222 = F_51 ( V_437 , V_79 ) ;
break;
case V_441 :
V_222 = F_52 ( V_437 ) ;
break;
case V_442 :
V_222 = F_53 ( V_2 , V_437 , V_79 ) ;
break;
case V_139 :
V_222 = F_19 ( V_2 , V_437 ,
V_79 ) ;
break;
case V_443 :
V_222 = F_54 ( V_2 , V_437 ,
V_79 ) ;
break;
case V_45 :
V_222 = F_9 ( V_437 ) ;
break;
case V_444 :
V_222 = F_55 ( V_2 , V_437 ,
V_79 ) ;
break;
case V_142 :
V_222 = F_20 ( V_437 ) ;
break;
case V_7 :
V_222 = F_1 ( V_2 , V_437 , V_5 ) ;
break;
case V_37 :
V_222 = F_5 ( V_2 , V_437 , V_5 ,
V_32 , V_79 ) ;
break;
case V_445 :
V_437 -> V_6 =
F_2 ( V_445 ) ;
V_437 -> V_8 =
F_2 ( sizeof( struct V_446 ) +
V_10 ) ;
V_2 -> V_447 = 0 ;
V_222 = 0 ;
break;
case V_448 :
V_437 -> V_6 = F_2 ( V_435 ) ;
V_437 -> V_11 . V_449 . V_450 =
( V_58 ) ( * ( ( T_2 * ) V_79 ) ) ;
memcpy ( & V_437 -> V_11 , V_79 ,
sizeof( struct V_451 ) ) ;
V_437 -> V_8 =
F_2 ( sizeof( struct V_451 ) +
V_10 ) ;
V_222 = 0 ;
break;
case V_452 :
V_437 -> V_6 = F_2 ( V_435 ) ;
V_437 -> V_11 . V_453 . V_13 = F_2 ( V_5 ) ;
V_437 -> V_11 . V_453 . V_454 = F_16 ( * ( T_2 * ) V_79 ) ;
V_437 -> V_8 =
F_2 ( sizeof( struct V_455 ) +
V_10 ) ;
V_222 = 0 ;
break;
case V_456 :
V_437 -> V_6 = F_2 ( V_435 ) ;
memcpy ( & V_437 -> V_11 , V_79 ,
sizeof( struct V_457 ) ) ;
V_437 -> V_8 =
F_2 ( sizeof( struct V_457 ) +
V_10 ) ;
break;
case V_458 :
V_222 = F_56 ( V_2 , V_437 , V_5 , V_79 ) ;
break;
case V_459 :
V_437 -> V_6 = F_2 ( V_435 ) ;
V_437 -> V_11 . V_460 . V_13 = F_2 ( V_5 ) ;
V_437 -> V_11 . V_460 . V_78 = F_2 ( * ( T_1 * ) V_79 ) ;
V_437 -> V_8 =
F_2 ( sizeof( struct V_461 ) +
V_10 ) ;
break;
case V_462 :
if ( V_2 -> V_29 -> V_463 == V_464 )
V_2 -> V_29 -> V_463 = V_465 ;
V_437 -> V_6 = F_2 ( V_435 ) ;
V_437 -> V_8 = F_2 ( V_10 ) ;
break;
case V_466 :
V_2 -> V_29 -> V_463 = V_464 ;
V_437 -> V_6 = F_2 ( V_435 ) ;
V_437 -> V_8 = F_2 ( V_10 ) ;
break;
case V_467 :
V_222 = F_57 ( V_437 , V_79 ) ;
break;
case V_468 :
V_222 = F_58 ( V_437 , V_79 ) ;
break;
case V_469 :
V_222 = F_59 ( V_2 , V_437 , V_79 ) ;
break;
case V_186 :
V_222 = F_28 ( V_2 , V_437 ,
V_5 , V_32 ,
V_79 ) ;
break;
case V_242 :
V_222 = F_29 ( V_2 , V_437 ,
V_5 ) ;
break;
case V_470 :
V_222 = F_60 ( V_2 , V_437 , V_5 ,
V_79 ) ;
break;
case V_471 :
V_222 = F_61 ( V_437 , V_5 ,
V_79 ) ;
break;
case V_472 :
V_222 = F_62 ( V_2 , V_437 , V_5 , V_79 ) ;
break;
case V_473 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_33 ) ;
V_437 -> V_6 = F_2 ( V_473 ) ;
V_437 -> V_8 =
F_2 ( sizeof( struct V_474 ) +
V_10 ) ;
V_222 = 0 ;
break;
case V_251 :
V_222 = F_30 ( V_437 , V_5 ,
V_79 ) ;
break;
case V_475 :
V_222 = F_63 ( V_2 , V_437 , V_79 ) ;
break;
case V_254 :
case V_258 :
case V_261 :
case V_264 :
case V_267 :
case V_269 :
V_222 = F_31 ( V_437 , V_5 , V_79 ) ;
break;
case V_476 :
V_437 -> V_6 = F_2 ( V_435 ) ;
if ( V_2 -> V_209 == V_210 )
V_437 -> V_11 . V_209 . V_477 =
V_478 ;
else if ( V_2 -> V_209 == V_479 )
V_437 -> V_11 . V_209 . V_477 =
V_480 ;
else if ( V_2 -> V_209 == V_481 )
V_437 -> V_11 . V_209 . V_477 = V_482 ;
V_437 -> V_8 = F_2 ( sizeof( struct
V_483 ) + V_10 ) ;
V_222 = 0 ;
break;
case V_281 :
V_222 = F_33 ( V_2 , V_437 , V_5 ) ;
break;
case V_309 :
V_222 = F_34 ( V_2 , V_437 , V_79 ) ;
break;
case V_343 :
V_222 = F_36 ( V_2 , V_437 , V_79 ) ;
break;
case V_372 :
V_222 = F_45 ( V_2 , V_437 , V_5 ,
V_79 ) ;
break;
case V_403 :
V_222 = F_46 ( V_2 , V_437 , V_79 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_34 , V_435 ) ;
V_222 = - 1 ;
break;
}
return V_222 ;
}
int F_64 ( struct V_1 * V_2 , V_58 V_484 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
int V_222 ;
T_1 V_247 = true ;
struct V_485 V_486 ;
struct V_487 V_488 ;
enum V_489 V_490 ;
struct V_491 V_492 ;
if ( V_484 ) {
if ( V_2 -> V_29 -> V_493 == V_494 ) {
V_222 = F_42 ( V_2 ,
V_281 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_222 )
return - 1 ;
}
V_222 = F_42 ( V_2 , V_462 ,
V_28 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
V_29 -> V_361 =
F_65 ( NULL , L_35 ) ;
if ( V_29 -> V_361 ) {
V_222 = F_39 ( V_2 , V_29 -> V_361 ,
L_36 ) ;
if ( V_222 )
return - 1 ;
}
if ( V_29 -> V_362 ) {
V_222 = F_42 ( V_2 , V_359 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_222 )
return - 1 ;
}
V_222 = F_42 ( V_2 , V_438 ,
V_39 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
V_222 = F_42 ( V_2 , V_470 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_495 , true ) ;
if ( V_222 )
return - 1 ;
if ( V_2 -> V_230 != V_231 ) {
V_2 -> V_29 -> V_496 = V_497 ;
V_222 = F_42 ( V_2 ,
V_439 ,
V_498 , V_499 , NULL ,
true ) ;
if ( V_222 )
return - 1 ;
}
}
V_222 = F_42 ( V_2 , V_56 ,
V_39 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
V_2 -> V_500 = 0 ;
V_222 = F_42 ( V_2 , V_81 ,
V_39 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
if ( V_2 -> V_230 == V_501 ) {
V_222 = F_42 (
V_2 ,
V_251 ,
V_28 , 0 , & V_247 , true ) ;
if ( V_222 )
return - 1 ;
}
memset ( & V_486 , 0 , sizeof( V_486 ) ) ;
V_486 . V_247 = true ;
V_222 = F_42 ( V_2 , V_471 ,
V_28 , 0 ,
& V_486 , true ) ;
if ( V_222 )
return - 1 ;
V_222 = F_42 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_502 , true ) ;
if ( V_222 )
return - 1 ;
if ( V_484 && V_2 -> V_29 -> V_493 != V_503 &&
V_2 -> V_230 != V_231 ) {
V_488 . V_488 = V_504 ;
V_488 . V_505 = V_506 ;
V_222 = F_42 ( V_2 , V_439 ,
V_498 , V_507 ,
& V_488 , true ) ;
if ( V_222 )
return - 1 ;
}
if ( V_2 -> V_230 != V_231 ) {
V_490 = V_508 ;
V_222 = F_42 ( V_2 , V_37 ,
V_28 , V_509 ,
& V_490 , true ) ;
if ( V_222 )
F_4 ( V_2 -> V_29 -> V_30 ,
L_37 ) ;
}
V_2 -> V_29 -> V_510 = V_472 ;
V_492 . V_511 = V_512 ;
V_222 = F_42 ( V_2 , V_472 ,
V_28 , 0 , & V_492 , true ) ;
V_222 = - V_513 ;
return V_222 ;
}
