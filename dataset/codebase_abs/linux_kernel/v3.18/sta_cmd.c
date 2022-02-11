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
if ( F_25 ( V_2 ) == V_196 ) {
V_220 = ( void * ) ( ( V_58 * ) & V_163 -> V_144 +
V_145 ) ;
V_220 -> V_230 . type =
F_2 ( V_231 ) ;
V_220 -> V_230 . V_168 = F_2 ( V_126 ) ;
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
if ( V_2 -> V_29 -> V_232 == V_233 )
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
struct V_234 * V_235 =
& V_4 -> V_11 . V_235 ;
struct V_236 * V_237 =
& V_235 -> V_237 ;
V_58 V_238 = V_29 -> V_239 . V_238 ;
F_6 ( V_29 -> V_30 , L_20 , V_238 ) ;
V_4 -> V_6 = F_2 ( V_240 ) ;
V_235 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_235 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_237 -> V_230 . type = F_2 ( V_241 ) ;
memcpy ( V_237 -> V_242 , V_29 -> V_239 . V_242 ,
sizeof( V_237 -> V_242 ) ) ;
V_237 -> V_230 . V_168 =
F_2 ( ( V_238 *
sizeof( struct V_243 ) )
+ sizeof( V_237 -> V_242 ) ) ;
if ( V_238 ) {
memcpy ( V_237 -> V_244 , V_29 -> V_239 . V_244 ,
V_238 * sizeof( struct
V_243 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_235 -> V_13 ) +
F_8 ( V_237 -> V_230 . V_168 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_235 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_30 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_245 )
{
struct V_246 * V_247 =
& ( V_4 -> V_11 . V_248 ) ;
V_4 -> V_6 = F_2 ( V_249 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_246 ) +
V_10 ) ;
V_4 -> V_123 = 0 ;
V_247 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_245 )
V_247 -> V_245 = F_2 ( * V_245 ) ;
else
V_247 -> V_245 = 0 ;
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
struct V_250 * V_251 = V_79 ;
switch ( F_8 ( V_4 -> V_6 ) ) {
case V_252 :
{
struct V_253 * V_254 ;
V_4 -> V_8 = F_2 ( sizeof( * V_254 ) + V_10 ) ;
V_254 = & V_4 -> V_11 . V_254 ;
V_254 -> V_13 = F_2 ( V_5 ) ;
V_254 -> V_255 =
F_2 ( ( T_1 ) F_32 ( V_251 -> V_255 ) ) ;
V_254 -> V_44 = V_251 -> V_44 ;
break;
}
case V_256 :
{
struct V_257 * V_258 ;
V_4 -> V_8 = F_2 ( sizeof( * V_258 ) + V_10 ) ;
V_258 = & V_4 -> V_11 . V_258 ;
V_258 -> V_13 = F_2 ( V_5 ) ;
V_258 -> V_255 =
F_2 ( ( T_1 ) F_32 ( V_251 -> V_255 ) ) ;
V_258 -> V_44 = ( V_58 ) F_32 ( V_251 -> V_44 ) ;
break;
}
case V_259 :
{
struct V_260 * V_261 ;
V_4 -> V_8 = F_2 ( sizeof( * V_261 ) + V_10 ) ;
V_261 = & V_4 -> V_11 . V_261 ;
V_261 -> V_13 = F_2 ( V_5 ) ;
V_261 -> V_255 = F_2 ( ( T_1 ) F_32 ( V_251 -> V_255 ) ) ;
V_261 -> V_44 = ( V_58 ) F_32 ( V_251 -> V_44 ) ;
break;
}
case V_262 :
{
struct V_263 * V_264 ;
V_4 -> V_8 = F_2 ( sizeof( * V_264 ) + V_10 ) ;
V_264 = & V_4 -> V_11 . V_264 ;
V_264 -> V_13 = F_2 ( V_5 ) ;
V_264 -> V_255 =
F_2 ( ( T_1 ) F_32 ( V_251 -> V_255 ) ) ;
V_264 -> V_44 = ( V_58 ) F_32 ( V_251 -> V_44 ) ;
break;
}
case V_265 :
{
struct V_260 * V_266 ;
V_4 -> V_8 = F_2 ( sizeof( * V_266 ) + V_10 ) ;
V_266 = & V_4 -> V_11 . V_261 ;
V_266 -> V_13 = F_2 ( V_5 ) ;
V_266 -> V_255 =
F_2 ( ( T_1 ) F_32 ( V_251 -> V_255 ) ) ;
V_266 -> V_44 = ( V_58 ) F_32 ( V_251 -> V_44 ) ;
break;
}
case V_267 :
{
struct V_268 * V_269 = V_79 ;
struct V_270 * V_271 =
& V_4 -> V_11 . V_272 ;
V_4 -> V_8 = F_2 ( sizeof( * V_271 ) + V_10 ) ;
V_271 -> V_13 = F_2 ( V_5 ) ;
V_271 -> V_255 = V_269 -> V_255 ;
V_271 -> V_273 = V_269 -> V_273 ;
V_271 -> V_44 = 0 ;
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
struct V_274 * V_275 =
& V_4 -> V_11 . V_276 ;
struct V_277 * V_278 = V_2 -> V_29 -> V_278 ;
V_4 -> V_6 = F_2 ( V_279 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_274 ) + V_10 ) ;
V_4 -> V_123 = 0 ;
memset ( V_275 , 0 , sizeof( struct V_274 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_275 -> V_280 = ( T_2 ) ( V_278 -> V_281 ) ;
V_275 -> V_282 = ( T_2 ) ( ( ( V_283 ) V_278 -> V_281 ) >> 32 ) ;
V_275 -> V_284 = V_285 ;
V_275 -> V_286 = ( T_2 ) ( V_278 -> V_287 ) ;
V_275 -> V_288 = ( T_2 ) ( ( ( V_283 ) V_278 -> V_287 ) >> 32 ) ;
V_275 -> V_289 = V_285 ;
V_275 -> V_290 = ( T_2 ) ( V_278 -> V_291 ) ;
V_275 -> V_292 = ( T_2 ) ( ( ( V_283 ) V_278 -> V_291 ) >> 32 ) ;
V_275 -> V_293 = V_294 ;
if ( V_278 -> V_295 ) {
V_275 -> V_296 =
( T_2 ) ( V_278 -> V_297 ) ;
V_275 -> V_298 =
( T_2 ) ( ( ( V_283 ) ( V_278 -> V_297 ) ) >> 32 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_21 ,
V_275 -> V_296 ) ;
}
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_299 * V_300 )
{
struct V_301 * V_302 = & V_4 -> V_11 . V_302 ;
struct V_303 * V_304 ;
T_1 V_305 ;
V_58 * V_306 ;
V_4 -> V_6 = F_2 ( V_307 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_301 ) +
V_10 ) ;
V_302 -> V_13 = F_2 ( V_300 -> V_13 ) ;
F_6 ( V_2 -> V_29 -> V_30 , L_22 , V_300 -> V_13 ) ;
if ( V_300 -> V_13 == V_39 )
return 0 ;
V_302 -> V_308 = F_2 ( V_300 -> V_308 ) ;
V_305 = V_300 -> V_308 ;
F_6 ( V_2 -> V_29 -> V_30 , L_23 ,
V_305 ) ;
if ( ( ( V_300 -> V_13 == V_309 ) ||
( V_300 -> V_13 == V_310 ) ) &&
( V_305 == 0 ) ) {
F_6 ( V_2 -> V_29 -> V_30 , L_24
L_25 ) ;
return - V_311 ;
}
if ( V_300 -> V_13 == V_309 )
return 0 ;
V_306 = ( ( V_58 * ) V_302 ) +
sizeof( struct V_301 ) ;
if ( V_305 & V_312 ) {
V_304 = (struct V_303 * ) V_306 ;
V_304 -> V_230 . type = F_2 ( V_313 ) ;
V_304 -> V_230 . V_168 =
F_2 ( sizeof( struct V_303 ) -
sizeof( struct V_61 ) ) ;
V_304 -> V_314 = V_300 -> V_315 . V_314 ;
V_304 -> V_316 = V_300 -> V_315 . V_316 ;
F_6 ( V_2 -> V_29 -> V_30 , L_26
L_27 ,
V_300 -> V_315 . V_314 ,
V_300 -> V_315 . V_316 ) ;
V_306 += sizeof( struct V_303 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_303 ) ) ;
}
if ( V_305 & V_317 ) {
V_304 = (struct V_303 * ) V_306 ;
V_304 -> V_230 . type = F_2 ( V_318 ) ;
V_304 -> V_230 . V_168 =
F_2 ( sizeof( struct V_303 ) -
sizeof( struct V_61 ) ) ;
V_304 -> V_314 = V_300 -> V_319 . V_314 ;
V_304 -> V_316 = V_300 -> V_319 . V_316 ;
F_6 ( V_2 -> V_29 -> V_30 , L_28
L_27 ,
V_300 -> V_319 . V_314 ,
V_300 -> V_319 . V_316 ) ;
V_306 += sizeof( struct V_303 ) ;
F_7 ( & V_4 -> V_8 ,
sizeof( struct V_303 ) ) ;
}
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_320 * V_321 ,
V_58 * * V_322 )
{
struct V_323 * V_324 = V_321 -> V_324 ;
int V_55 , V_325 ;
V_58 * V_326 = * V_322 ;
for ( V_55 = 0 ; V_55 < V_327 ; V_55 ++ ) {
V_324 = & V_321 -> V_324 [ V_55 ] ;
if ( ! V_324 -> V_328 )
break;
* ( V_329 * ) V_326 = F_16 ( ( T_2 ) V_324 -> V_330 ) ;
V_326 += 4 ;
* V_326 = V_331 ;
V_326 += 1 ;
V_325 = V_324 -> V_332 [ V_333 ] ;
memcpy ( V_326 , V_324 -> V_332 , V_325 ) ;
V_326 += V_325 ;
* V_326 = V_325 ;
V_326 += 1 ;
* V_326 = V_334 ;
V_326 += 1 ;
* ( V_329 * ) V_326 = F_16 ( ( T_2 ) V_324 -> V_255 ) ;
V_326 += 4 ;
* V_326 = V_331 ;
V_326 += 1 ;
* V_326 = V_324 -> V_328 ;
V_326 += 1 ;
if ( V_324 -> V_335 ) {
* V_326 = V_324 -> V_335 ;
V_326 += 1 ;
}
if ( V_326 - * V_322 > V_336 )
return - 1 ;
}
* V_322 = V_326 ;
return 0 ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_337 * V_338 )
{
struct V_339 * V_340 = & V_4 -> V_11 . V_340 ;
V_58 * V_306 = ( V_58 * ) V_340 ;
V_4 -> V_6 = F_2 ( V_341 ) ;
V_340 -> V_342 = F_16 ( V_338 -> V_342 ) ;
V_340 -> V_343 = F_2 ( V_338 -> V_343 ) ;
V_306 += sizeof( * V_340 ) ;
V_340 -> V_321 -> V_78 = V_338 -> V_321 -> V_78 ;
V_340 -> V_321 -> V_13 = V_338 -> V_321 -> V_13 ;
V_306 += sizeof( * ( V_340 -> V_321 ) ) ;
if ( F_35 ( V_2 , V_338 -> V_321 , & V_306 ) )
return - 1 ;
V_340 -> V_321 -> V_344 =
F_2 ( V_306 - V_340 -> V_321 -> V_345 ) ;
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_306 - ( V_58 * ) V_340 ) + V_10 ) ;
return 0 ;
}
static T_2 F_37 ( V_58 * V_346 , T_3 V_168 , V_58 * V_347 )
{
V_58 * V_348 = V_346 , * V_349 = V_347 ;
while ( V_348 - V_346 < V_168 ) {
if ( * V_348 && ( isspace ( * V_348 ) || * V_348 == '\t' ) ) {
V_348 ++ ;
continue;
}
if ( isxdigit ( * V_348 ) ) {
* V_349 ++ = F_38 ( V_348 , NULL , 16 ) ;
V_348 += 2 ;
} else {
V_348 ++ ;
}
}
return V_349 - V_347 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_350 * V_351 , const char * V_352 )
{
#ifdef F_40
struct V_353 * V_354 ;
T_3 V_168 = strlen ( V_352 ) ;
int V_222 ;
F_41 (node, prop) {
if ( V_168 > strlen ( V_354 -> V_355 ) ||
strncmp ( V_354 -> V_355 , V_352 , V_168 ) )
continue;
if ( V_354 && V_354 -> V_44 && V_354 -> V_60 > 6 &&
V_354 -> V_60 <= V_356 - V_10 ) {
V_222 = F_42 ( V_2 , V_357 ,
V_28 , 0 ,
V_354 , true ) ;
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
struct V_353 * V_354 = V_79 ;
T_2 V_168 ;
V_58 * V_358 = ( V_58 * ) V_4 + V_10 ;
int V_222 ;
if ( V_354 ) {
V_168 = V_354 -> V_60 ;
V_222 = F_44 ( V_29 -> V_359 , V_354 -> V_355 ,
V_358 , V_168 ) ;
if ( V_222 )
return V_222 ;
F_6 ( V_29 -> V_30 ,
L_29 , V_354 -> V_355 ) ;
} else if ( V_29 -> V_360 -> V_358 && V_29 -> V_360 -> V_8 > 0 ) {
V_168 = F_37 ( ( V_58 * ) V_29 -> V_360 -> V_358 ,
V_29 -> V_360 -> V_8 , V_358 ) ;
F_6 ( V_29 -> V_30 , L_30 ) ;
} else {
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_357 ) ;
V_4 -> V_8 = F_2 ( V_10 + V_168 ) ;
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_361 * V_362 =
& V_4 -> V_11 . V_362 ;
struct V_363 * V_364 = V_79 ;
struct V_365 * V_227 ;
T_1 V_366 , V_367 , V_60 ;
struct V_368 * V_369 ;
V_4 -> V_6 = F_2 ( V_370 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_362 -> V_13 = F_2 ( V_5 ) ;
V_362 -> V_371 = F_2 ( V_364 -> V_371 ) ;
V_369 = V_362 -> V_369 ;
for ( V_366 = 0 ; V_366 < V_364 -> V_371 ; V_366 ++ ) {
V_369 -> V_230 . type = F_2 ( V_372 ) ;
V_369 -> V_373 =
F_2 ( V_364 -> V_369 [ V_366 ] . V_373 ) ;
V_369 -> V_374 = V_364 -> V_369 [ V_366 ] . V_374 ;
V_369 -> V_375 = V_364 -> V_369 [ V_366 ] . V_375 ;
V_60 = 0 ;
V_227 = V_369 -> V_11 ;
for ( V_367 = 0 ; V_367 < V_364 -> V_369 [ V_366 ] . V_375 ; V_367 ++ ) {
V_227 -> V_376 = V_364 -> V_369 [ V_366 ] . V_11 [ V_367 ] . V_376 ;
V_227 -> V_377 =
V_364 -> V_369 [ V_366 ] . V_11 [ V_367 ] . V_377 ;
V_227 -> V_255 =
F_2 ( V_364 -> V_369 [ V_366 ] . V_11 [ V_367 ] . V_255 ) ;
memcpy ( V_227 -> V_378 ,
V_364 -> V_369 [ V_366 ] . V_11 [ V_367 ] . V_378 ,
V_227 -> V_377 ) ;
V_60 += sizeof( struct V_365 ) ;
V_227 ++ ;
}
V_369 -> V_230 . V_168 = F_2 ( V_60 + sizeof( T_1 ) +
sizeof( V_58 ) + sizeof( V_58 ) ) ;
F_7 ( & V_4 -> V_8 , F_8 ( V_369 -> V_230 . V_168 ) +
sizeof( struct V_61 ) ) ;
V_369 = ( void * ) ( ( V_58 * ) V_369 -> V_11 + V_60 ) ;
}
F_7 ( & V_4 -> V_8 , sizeof( T_1 ) + sizeof( T_1 ) ) ;
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_79 )
{
struct V_379 * V_380 = & V_4 -> V_11 . V_380 ;
struct V_381 * V_382 = V_79 ;
struct V_383 * V_384 ;
struct V_385 * V_386 ;
struct V_387 * V_388 ;
struct V_389 * V_390 ;
struct V_391 * V_392 ;
struct V_393 * V_394 ;
struct V_395 * V_396 ;
struct V_397 * V_398 ;
V_58 * V_306 , V_399 ;
T_1 V_400 = 0 ;
struct V_401 * V_11 = V_2 -> V_402 ;
V_4 -> V_6 = F_2 ( V_403 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
F_7 ( & V_4 -> V_8 , sizeof( struct V_379 ) ) ;
V_380 -> V_404 = 0 ;
memcpy ( V_380 -> V_405 , V_382 -> V_405 , V_126 ) ;
V_384 = F_47 ( V_2 , V_382 -> V_405 ) ;
V_306 = ( V_58 * ) V_380 + sizeof( struct V_379 ) ;
switch ( V_382 -> V_406 ) {
case V_407 :
V_380 -> V_406 = F_2 ( V_408 ) ;
break;
case V_409 :
V_380 -> V_406 = F_2 ( V_410 ) ;
break;
case V_411 :
V_380 -> V_406 = F_2 ( V_412 ) ;
if ( ! V_11 ) {
F_4 ( V_2 -> V_29 -> V_30 ,
L_31 ,
V_382 -> V_405 ) ;
return - V_413 ;
}
* ( V_43 * ) V_306 = F_2 ( V_11 -> V_414 ) ;
V_400 += sizeof( V_11 -> V_414 ) ;
V_399 = V_11 -> V_415 | ( V_11 -> V_416 << 5 ) ;
V_390 = (struct V_389 * ) ( V_306 +
V_400 ) ;
V_390 -> V_230 . type = F_2 ( V_417 ) ;
V_390 -> V_230 . V_168 = F_2 ( sizeof( V_399 ) ) ;
V_390 -> V_399 = V_399 ;
V_400 += sizeof( struct V_389 ) ;
if ( V_11 -> V_418 ) {
V_388 = (struct V_387 * ) ( V_306 +
V_400 ) ;
V_388 -> V_230 . type =
F_2 ( V_419 ) ;
V_388 -> V_230 . V_168 =
F_2 ( sizeof( struct V_420 ) ) ;
memcpy ( & V_388 -> V_421 , V_11 -> V_418 ,
sizeof( struct V_420 ) ) ;
V_400 += sizeof( struct V_387 ) ;
}
if ( V_11 -> V_422 && V_11 -> V_423 ) {
V_386 = (struct V_385 * ) ( V_306 +
V_400 ) ;
V_386 -> V_230 . type =
F_2 ( V_424 ) ;
V_386 -> V_230 . V_168 =
F_2 ( V_11 -> V_423 ) ;
memcpy ( V_386 -> V_425 , V_11 -> V_422 ,
V_11 -> V_423 ) ;
V_400 += sizeof( struct V_385 ) +
V_11 -> V_423 ;
}
if ( V_11 -> V_426 && V_11 -> V_427 ) {
V_392 = (struct V_391 * ) ( V_306 +
V_400 ) ;
V_392 -> V_230 . type =
F_2 ( V_428 ) ;
V_392 -> V_230 . V_168 = F_2 ( V_11 -> V_427 ) ;
memcpy ( V_392 -> V_426 , V_11 -> V_426 ,
V_11 -> V_427 ) ;
V_400 += sizeof( struct V_391 ) +
V_11 -> V_427 ;
}
if ( V_11 -> V_429 ) {
V_394 = (struct V_393 * ) ( V_306 +
V_400 ) ;
V_394 -> V_230 . type =
F_2 ( V_430 ) ;
V_394 -> V_230 . V_168 =
F_2 ( sizeof( struct V_431 ) ) ;
memcpy ( & V_394 -> V_432 , V_11 -> V_429 ,
sizeof( struct V_431 ) ) ;
V_400 += sizeof( struct V_393 ) ;
}
if ( V_11 -> V_396 ) {
V_396 = (struct V_395 * ) ( V_306 + V_400 ) ;
V_396 -> V_230 . type = F_2 ( V_433 ) ;
V_396 -> V_230 . V_168 = F_2 ( sizeof( V_11 -> V_396 ) ) ;
V_396 -> V_396 = F_2 ( V_11 -> V_396 ) ;
V_400 += sizeof( struct V_395 ) ;
}
V_398 = ( void * ) ( V_306 + V_400 ) ;
V_398 -> V_230 . type = F_2 ( V_434 ) ;
V_398 -> V_230 . V_168 = F_2 ( sizeof( V_398 -> V_44 ) ) ;
V_398 -> V_44 = F_2 ( V_435 ) ;
V_400 += sizeof( struct V_397 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 , L_32 ) ;
return - V_436 ;
}
F_7 ( & V_4 -> V_8 , V_400 ) ;
return 0 ;
}
int F_48 ( struct V_1 * V_2 , T_4 V_437 ,
T_1 V_5 , T_2 V_32 ,
void * V_79 , void * V_438 )
{
struct V_3 * V_439 = V_438 ;
int V_222 = 0 ;
switch ( V_437 ) {
case V_440 :
V_222 = F_49 ( V_2 , V_439 ) ;
break;
case V_357 :
V_222 = F_43 ( V_2 , V_439 , V_79 ) ;
break;
case V_31 :
V_222 = F_3 ( V_2 , V_439 , V_5 ,
V_79 ) ;
break;
case V_121 :
V_222 = F_17 ( V_2 , V_439 ,
V_5 ) ;
break;
case V_132 :
V_222 = F_18 ( V_439 , V_5 ,
V_79 ) ;
break;
case V_56 :
V_222 = F_10 ( V_2 , V_439 , V_5 ,
V_79 ) ;
break;
case V_77 :
V_222 = F_12 ( V_439 , V_5 ,
V_79 ) ;
break;
case V_81 :
V_222 = F_13 ( V_2 , V_439 , V_5 ,
V_79 ) ;
break;
case V_88 :
V_222 = F_14 ( V_2 , V_439 , V_5 ,
V_79 ) ;
break;
case V_441 :
V_222 = F_50 ( V_2 , V_439 , V_5 ,
( T_4 ) V_32 , V_79 ) ;
break;
case V_108 :
V_222 = F_15 ( V_2 , V_439 , V_5 ,
(struct V_101 * ) V_79 ) ;
break;
case V_442 :
V_222 = F_51 ( V_439 , V_79 ) ;
break;
case V_443 :
V_222 = F_52 ( V_439 ) ;
break;
case V_444 :
V_222 = F_53 ( V_2 , V_439 , V_79 ) ;
break;
case V_139 :
V_222 = F_19 ( V_2 , V_439 ,
V_79 ) ;
break;
case V_445 :
V_222 = F_54 ( V_2 , V_439 ,
V_79 ) ;
break;
case V_45 :
V_222 = F_9 ( V_439 ) ;
break;
case V_446 :
V_222 = F_55 ( V_2 , V_439 ,
V_79 ) ;
break;
case V_142 :
V_222 = F_20 ( V_439 ) ;
break;
case V_7 :
V_222 = F_1 ( V_2 , V_439 , V_5 ) ;
break;
case V_37 :
V_222 = F_5 ( V_2 , V_439 , V_5 ,
V_32 , V_79 ) ;
break;
case V_447 :
V_439 -> V_6 =
F_2 ( V_447 ) ;
V_439 -> V_8 =
F_2 ( sizeof( struct V_448 ) +
V_10 ) ;
V_2 -> V_449 = 0 ;
V_222 = 0 ;
break;
case V_450 :
V_439 -> V_6 = F_2 ( V_437 ) ;
V_439 -> V_11 . V_451 . V_452 =
( V_58 ) ( * ( ( T_2 * ) V_79 ) ) ;
memcpy ( & V_439 -> V_11 , V_79 ,
sizeof( struct V_453 ) ) ;
V_439 -> V_8 =
F_2 ( sizeof( struct V_453 ) +
V_10 ) ;
V_222 = 0 ;
break;
case V_454 :
V_439 -> V_6 = F_2 ( V_437 ) ;
V_439 -> V_11 . V_455 . V_13 = F_2 ( V_5 ) ;
V_439 -> V_11 . V_455 . V_456 = F_16 ( * ( T_2 * ) V_79 ) ;
V_439 -> V_8 =
F_2 ( sizeof( struct V_457 ) +
V_10 ) ;
V_222 = 0 ;
break;
case V_458 :
V_439 -> V_6 = F_2 ( V_437 ) ;
memcpy ( & V_439 -> V_11 , V_79 ,
sizeof( struct V_459 ) ) ;
V_439 -> V_8 =
F_2 ( sizeof( struct V_459 ) +
V_10 ) ;
break;
case V_460 :
V_222 = F_56 ( V_2 , V_439 , V_5 , V_79 ) ;
break;
case V_461 :
V_439 -> V_6 = F_2 ( V_437 ) ;
V_439 -> V_11 . V_462 . V_13 = F_2 ( V_5 ) ;
V_439 -> V_11 . V_462 . V_78 = F_2 ( * ( T_1 * ) V_79 ) ;
V_439 -> V_8 =
F_2 ( sizeof( struct V_463 ) +
V_10 ) ;
break;
case V_464 :
if ( V_2 -> V_29 -> V_465 == V_466 )
V_2 -> V_29 -> V_465 = V_467 ;
V_439 -> V_6 = F_2 ( V_437 ) ;
V_439 -> V_8 = F_2 ( V_10 ) ;
break;
case V_468 :
V_2 -> V_29 -> V_465 = V_466 ;
V_439 -> V_6 = F_2 ( V_437 ) ;
V_439 -> V_8 = F_2 ( V_10 ) ;
break;
case V_469 :
V_222 = F_57 ( V_439 , V_79 ) ;
break;
case V_470 :
V_222 = F_58 ( V_439 , V_79 ) ;
break;
case V_471 :
V_222 = F_59 ( V_2 , V_439 , V_79 ) ;
break;
case V_186 :
V_222 = F_28 ( V_2 , V_439 ,
V_5 , V_32 ,
V_79 ) ;
break;
case V_240 :
V_222 = F_29 ( V_2 , V_439 ,
V_5 ) ;
break;
case V_472 :
V_222 = F_60 ( V_2 , V_439 , V_5 ,
V_79 ) ;
break;
case V_473 :
V_222 = F_61 ( V_439 , V_5 ,
V_79 ) ;
break;
case V_474 :
V_222 = F_62 ( V_2 , V_439 , V_5 , V_79 ) ;
break;
case V_475 :
F_6 ( V_2 -> V_29 -> V_30 ,
L_33 ) ;
V_439 -> V_6 = F_2 ( V_475 ) ;
V_439 -> V_8 =
F_2 ( sizeof( struct V_476 ) +
V_10 ) ;
V_222 = 0 ;
break;
case V_249 :
V_222 = F_30 ( V_439 , V_5 ,
V_79 ) ;
break;
case V_477 :
V_222 = F_63 ( V_2 , V_439 , V_79 ) ;
break;
case V_252 :
case V_256 :
case V_259 :
case V_262 :
case V_265 :
case V_267 :
V_222 = F_31 ( V_439 , V_5 , V_79 ) ;
break;
case V_478 :
V_439 -> V_6 = F_2 ( V_437 ) ;
if ( V_2 -> V_209 == V_210 )
V_439 -> V_11 . V_209 . V_479 =
V_480 ;
else if ( V_2 -> V_209 == V_481 )
V_439 -> V_11 . V_209 . V_479 =
V_482 ;
else if ( V_2 -> V_209 == V_483 )
V_439 -> V_11 . V_209 . V_479 = V_484 ;
V_439 -> V_8 = F_2 ( sizeof( struct
V_485 ) + V_10 ) ;
V_222 = 0 ;
break;
case V_279 :
V_222 = F_33 ( V_2 , V_439 , V_5 ) ;
break;
case V_307 :
V_222 = F_34 ( V_2 , V_439 , V_79 ) ;
break;
case V_341 :
V_222 = F_36 ( V_2 , V_439 , V_79 ) ;
break;
case V_370 :
V_222 = F_45 ( V_2 , V_439 , V_5 ,
V_79 ) ;
break;
case V_403 :
V_222 = F_46 ( V_2 , V_439 , V_79 ) ;
break;
default:
F_4 ( V_2 -> V_29 -> V_30 ,
L_34 , V_437 ) ;
V_222 = - 1 ;
break;
}
return V_222 ;
}
int F_64 ( struct V_1 * V_2 , V_58 V_486 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
int V_222 ;
T_1 V_245 = true ;
struct V_487 V_488 ;
struct V_489 V_490 ;
enum V_491 V_492 ;
struct V_493 V_494 ;
if ( V_486 ) {
if ( V_2 -> V_29 -> V_495 == V_496 ) {
V_222 = F_42 ( V_2 ,
V_279 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_222 )
return - 1 ;
}
V_222 = F_42 ( V_2 , V_464 ,
V_28 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
V_29 -> V_359 =
F_65 ( NULL , L_35 ) ;
if ( V_29 -> V_359 ) {
V_222 = F_39 ( V_2 , V_29 -> V_359 ,
L_36 ) ;
if ( V_222 )
return - 1 ;
}
if ( V_29 -> V_360 ) {
V_222 = F_42 ( V_2 , V_357 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_222 )
return - 1 ;
}
V_222 = F_42 ( V_2 , V_440 ,
V_39 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
V_222 = F_42 ( V_2 , V_472 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_497 , true ) ;
if ( V_222 )
return - 1 ;
if ( V_2 -> V_498 != V_499 ) {
V_2 -> V_29 -> V_500 = V_501 ;
V_222 = F_42 ( V_2 ,
V_441 ,
V_502 , V_503 , NULL ,
true ) ;
if ( V_222 )
return - 1 ;
}
}
V_222 = F_42 ( V_2 , V_56 ,
V_39 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
V_2 -> V_504 = 0 ;
V_222 = F_42 ( V_2 , V_81 ,
V_39 , 0 , NULL , true ) ;
if ( V_222 )
return - 1 ;
if ( V_2 -> V_498 == V_505 ) {
V_222 = F_42 (
V_2 ,
V_249 ,
V_28 , 0 , & V_245 , true ) ;
if ( V_222 )
return - 1 ;
}
memset ( & V_488 , 0 , sizeof( V_488 ) ) ;
V_488 . V_245 = true ;
V_222 = F_42 ( V_2 , V_473 ,
V_28 , 0 ,
& V_488 , true ) ;
if ( V_222 )
return - 1 ;
V_222 = F_42 ( V_2 , V_31 ,
V_28 , 0 ,
& V_2 -> V_506 , true ) ;
if ( V_222 )
return - 1 ;
if ( V_486 && V_2 -> V_29 -> V_495 != V_507 &&
V_2 -> V_498 != V_499 ) {
V_490 . V_490 = V_508 ;
V_490 . V_509 = V_510 ;
V_222 = F_42 ( V_2 , V_441 ,
V_502 , V_511 ,
& V_490 , true ) ;
if ( V_222 )
return - 1 ;
}
if ( V_2 -> V_498 != V_499 ) {
V_492 = V_512 ;
V_222 = F_42 ( V_2 , V_37 ,
V_28 , V_513 ,
& V_492 , true ) ;
if ( V_222 )
F_4 ( V_2 -> V_29 -> V_30 ,
L_37 ) ;
}
V_2 -> V_29 -> V_514 = V_474 ;
V_494 . V_515 = V_516 ;
V_222 = F_42 ( V_2 , V_474 ,
V_28 , 0 , & V_494 , true ) ;
V_222 = - V_517 ;
return V_222 ;
}
