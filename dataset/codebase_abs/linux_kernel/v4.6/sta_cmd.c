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
F_4 ( V_2 -> V_29 , ERROR ,
L_1 ) ;
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_30 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_26 ) + V_10 ) ;
V_27 -> V_13 = F_2 ( * V_13 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
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
F_6 ( & V_4 -> V_8 , V_42 ) ;
} else if ( V_5 == V_28 ) {
V_34 -> V_40 = F_2 ( V_28 ) ;
V_34 -> V_41 = F_2 ( sizeof( T_1 ) ) ;
* ( ( V_43 * ) ( V_34 -> V_44 ) ) = F_2 ( * V_32 ) ;
F_6 ( & V_4 -> V_8 , sizeof( T_1 ) ) ;
}
F_4 ( V_2 -> V_29 , V_36 ,
L_3
L_4 ,
V_5 , V_31 , F_7 ( V_34 -> V_41 ) ,
F_7 ( * ( V_43 * ) V_34 -> V_44 ) ) ;
return 0 ;
}
static int
F_8 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_45 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_46 ) +
V_10 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
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
V_55 < F_10 ( V_52 -> V_67 ) ;
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
V_55 < F_10 ( V_52 -> V_67 ) ;
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
static int F_11 ( struct V_3 * V_4 ,
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
F_7 ( V_74 -> V_60 ) ) ;
V_74 = (struct V_73 * ) ( ( V_58 * )
V_75 +
sizeof( struct V_71 ) ) ;
V_4 -> V_8 = F_2 ( F_7 ( V_4 -> V_8 ) +
sizeof( struct V_73 ) +
F_7 ( V_74 -> V_60 ) ) ;
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
static int F_12 ( struct V_1 * V_2 ,
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
static int F_13 ( struct V_1 * V_2 ,
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
F_14 ( struct V_1 * V_2 ,
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
( V_102 -> V_109 != F_15 ( V_110 ) ) &&
( ( V_29 -> V_111 > 0 ) &&
( V_29 -> V_111 <= V_112 ) ) ) {
F_4 ( V_29 , V_36 ,
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
F_4 ( V_29 , V_36 ,
L_6 ,
V_105 -> V_11 . V_118 . V_109 ,
V_105 -> V_11 . V_118 . V_119 ,
V_105 -> V_11 . V_118 . V_120 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
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
F_17 ( struct V_3 * V_4 ,
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
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
V_58 * V_136 )
{
struct V_137 * V_138 = & V_4 -> V_11 . V_138 ;
V_4 -> V_6 = F_2 ( V_139 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_137 )
+ V_10 ) ;
memcpy ( V_138 -> V_124 , V_136 , V_126 ) ;
F_4 ( V_2 -> V_29 , V_36 , L_7 , V_138 -> V_124 ) ;
V_138 -> V_140 = F_2 ( V_141 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_142 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 ,
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
#define F_21 8
V_144 -> V_60 = F_2 ( ( T_1 )
( V_2 -> V_148 [ V_55 ] .
V_149 +
F_21 ) ) ;
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
F_21 +
sizeof( struct V_61 ) ;
* V_145 += ( T_1 ) V_146 ;
V_144 =
(struct V_143 * )
( ( V_58 * ) V_144 +
V_146 ) ;
} else if ( ! V_2 -> V_148 [ V_55 ] . V_149 ) {
continue;
} else {
F_4 ( V_2 -> V_29 , ERROR ,
L_8 ,
( V_55 + 1 ) , V_2 -> V_148 [ V_55 ] . V_149 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_164 * V_165 ,
struct V_166 * V_167 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
T_1 V_8 , V_168 = V_169 ;
if ( V_165 -> V_170 ) {
F_4 ( V_29 , V_171 ,
L_9 , V_172 ) ;
if ( V_165 -> V_173 )
memcpy ( V_167 -> V_144 . V_174 . V_175 . V_176 ,
V_165 -> V_177 , V_165 -> V_178 ) ;
V_167 -> V_144 . V_155 &= F_2 ( ~ V_158 ) ;
V_167 -> V_144 . V_155 |= F_2 ( V_179 ) ;
V_167 -> V_144 . V_180 = V_181 ;
V_167 -> V_144 . V_174 . V_175 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_174 . V_175 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_168 += sizeof( struct V_182 ) ;
} else {
F_4 ( V_29 , V_171 ,
L_10 , V_172 ) ;
if ( V_165 -> V_173 )
memcpy ( V_167 -> V_144 . V_174 . V_183 . V_177 ,
V_165 -> V_177 , V_165 -> V_178 ) ;
V_167 -> V_144 . V_180 = V_184 ;
V_167 -> V_144 . V_174 . V_183 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_174 . V_183 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_168 += sizeof( struct V_185 ) ;
}
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_8 = V_168 + sizeof( struct V_61 ) +
sizeof( V_167 -> V_13 ) + V_10 ;
V_4 -> V_8 = F_2 ( V_8 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_164 * V_165 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
V_58 * V_136 = V_165 -> V_124 ;
T_1 V_155 , V_168 = V_169 ;
struct V_166 * V_167 =
& V_4 -> V_11 . V_186 ;
V_4 -> V_6 = F_2 ( V_187 ) ;
V_167 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
F_4 ( V_29 , V_171 , L_11 , V_172 ) ;
V_167 -> V_144 . V_188 =
V_165 -> V_189 & V_190 ;
V_167 -> V_144 . type = F_2 ( V_191 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_169 ) ;
memcpy ( V_167 -> V_144 . V_124 , V_136 , V_126 ) ;
if ( V_165 -> V_189 & V_192 )
V_155 = V_157 ;
else
V_155 = V_158 ;
if ( V_165 -> V_170 )
V_155 |= V_179 ;
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_10 + V_169 +
sizeof( V_167 -> V_13 ) ) ;
return 0 ;
}
memset ( & V_167 -> V_144 , 0 ,
sizeof( struct V_193 ) ) ;
if ( V_165 -> V_194 ) {
F_4 ( V_29 , V_171 , L_12 , V_172 ) ;
V_167 -> V_13 = F_2 ( V_195 ) ;
V_167 -> V_144 . type = F_2 ( V_191 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_169 ) ;
V_167 -> V_144 . V_188 = V_165 -> V_189 & V_190 ;
V_155 = V_158 | V_157 ;
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
memcpy ( V_167 -> V_144 . V_124 , V_136 , V_126 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_10 + V_169 +
sizeof( V_167 -> V_13 ) ) ;
return 0 ;
}
V_167 -> V_13 = F_2 ( V_28 ) ;
V_167 -> V_144 . V_188 = V_165 -> V_189 & V_190 ;
V_167 -> V_144 . type = F_2 ( V_191 ) ;
V_155 = V_156 ;
memcpy ( V_167 -> V_144 . V_124 , V_136 , V_126 ) ;
if ( V_165 -> V_159 <= V_151 ) {
F_4 ( V_29 , V_171 , L_13 , V_172 ) ;
V_168 += sizeof( struct V_196 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_167 -> V_144 . V_180 = V_154 ;
if ( F_24 ( V_2 ) == V_197 ) {
V_155 |= V_158 | V_157 ;
} else {
if ( V_165 -> V_198 ) {
V_155 |= V_158 | V_157 ;
if ( V_167 -> V_144 . V_188 ==
( V_2 -> V_161 & V_190 ) )
V_155 |= V_199 ;
} else {
if ( V_136 ) {
if ( F_25 ( V_136 ) )
V_155 |= V_158 ;
else
V_155 |= V_157 |
V_199 ;
} else {
V_155 |= V_158 ;
}
}
}
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
V_167 -> V_144 . V_174 . V_200 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_174 . V_200 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_168 + sizeof( V_167 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( F_25 ( V_136 ) )
V_155 |= V_158 | V_201 ;
else
V_155 |= V_157 | V_202 | V_201 ;
if ( V_165 -> V_203 ) {
F_4 ( V_29 , V_171 , L_14 , V_172 ) ;
V_167 -> V_144 . V_180 = V_204 ;
memcpy ( V_167 -> V_144 . V_174 . V_205 . V_177 , V_165 -> V_177 ,
V_206 ) ;
V_167 -> V_144 . V_174 . V_205 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_174 . V_205 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
if ( F_25 ( V_136 ) )
V_2 -> V_207 . V_208 = true ;
if ( ! V_2 -> V_207 . V_208 )
V_155 |= V_199 ;
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
V_168 += sizeof( struct V_209 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_168 + sizeof( V_167 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( V_2 -> V_210 == V_211 ) {
V_155 |= V_199 ;
if ( ! V_2 -> V_207 . V_212 &&
! F_25 ( V_136 ) )
V_155 |= V_157 ;
} else {
if ( ! V_2 -> V_213 )
V_155 |= V_199 ;
}
V_167 -> V_144 . V_155 = F_2 ( V_155 ) ;
if ( V_165 -> V_159 == V_214 )
return F_22 ( V_2 , V_4 , V_165 , V_167 ) ;
if ( V_165 -> V_159 == V_215 ) {
F_4 ( V_29 , V_171 ,
L_15 , V_172 ) ;
if ( V_165 -> V_173 )
memcpy ( V_167 -> V_144 . V_174 . V_216 . V_177 ,
V_165 -> V_177 , V_165 -> V_178 ) ;
V_167 -> V_144 . V_180 = V_217 ;
V_167 -> V_144 . V_174 . V_216 . V_159 =
F_2 ( V_165 -> V_159 ) ;
memcpy ( V_167 -> V_144 . V_174 . V_216 . V_160 ,
V_165 -> V_163 , V_165 -> V_159 ) ;
V_168 += sizeof( struct V_218 ) ;
V_167 -> V_144 . V_168 = F_2 ( V_168 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_168 + sizeof( V_167 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_164 * V_165 )
{
struct V_219 * V_163 =
& V_4 -> V_11 . V_163 ;
struct V_220 * V_221 ;
T_1 V_145 = 0 , V_222 ;
int V_223 = 0 ;
V_4 -> V_6 = F_2 ( V_187 ) ;
V_163 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_163 -> V_13 ) + V_10 ) ;
return V_223 ;
}
if ( ! V_165 ) {
memset ( & V_163 -> V_144 , 0 ,
( V_147 *
sizeof( struct V_143 ) ) ) ;
V_223 = F_20 ( V_2 ,
& V_163 -> V_144 ,
& V_145 ) ;
V_4 -> V_8 = F_2 ( V_145 +
sizeof( V_163 -> V_13 ) + V_10 ) ;
return V_223 ;
} else
memset ( & V_163 -> V_144 , 0 ,
sizeof( struct V_143 ) ) ;
if ( V_165 -> V_203 ) {
F_4 ( V_2 -> V_29 , V_171 , L_16 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_204 ) ;
if ( V_31 == V_224 )
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
else
V_163 -> V_144 . V_155 =
F_2 ( ! V_156 ) ;
V_163 -> V_144 . V_160 [ 0 ] = V_165 -> V_189 ;
if ( ! V_2 -> V_207 . V_208 )
V_163 -> V_144 . V_160 [ 1 ] = 1 ;
else
V_163 -> V_144 . V_160 [ 1 ] = 0 ;
if ( ! F_25 ( V_165 -> V_124 ) ) {
V_163 -> V_144 . V_155 |=
F_2 ( V_157 ) ;
} else {
V_163 -> V_144 . V_155 |=
F_2 ( V_158 ) ;
V_2 -> V_207 . V_208 = true ;
}
V_163 -> V_144 . type =
F_2 ( V_152 ) ;
V_163 -> V_144 . V_159 =
F_2 ( V_225 ) ;
memcpy ( & V_163 -> V_144 . V_160 [ 2 ] ,
V_165 -> V_163 , V_165 -> V_159 ) ;
memcpy ( & V_163 -> V_144 . V_160 [ 2 + V_165 -> V_159 ] ,
V_165 -> V_177 , V_206 ) ;
V_163 -> V_144 . V_60 =
F_2 ( V_225 + V_226 ) ;
V_145 = ( V_225 + V_226 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_163 -> V_13 )
+ V_10 + V_145 ) ;
return V_223 ;
}
if ( V_165 -> V_159 == V_214 ) {
if ( V_165 -> V_170 ) {
F_4 ( V_2 -> V_29 , V_36 , L_17 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_181 ) ;
if ( V_31 == V_224 )
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
else
V_163 -> V_144 . V_155 =
F_2 ( ! V_156 ) ;
V_163 -> V_144 . V_155 |=
F_2 ( V_179 ) ;
} else {
F_4 ( V_2 -> V_29 , V_36 , L_18 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_184 ) ;
if ( V_31 == V_224 )
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
else
V_163 -> V_144 . V_155 =
F_2 ( ! V_156 ) ;
if ( V_165 -> V_189 & V_192 )
V_163 -> V_144 . V_155 |=
F_2 ( V_157 ) ;
else
V_163 -> V_144 . V_155 |=
F_2 ( V_158 ) ;
}
} else if ( V_165 -> V_159 == V_215 ) {
F_4 ( V_2 -> V_29 , V_36 , L_19 ) ;
V_163 -> V_144 . V_153 =
F_2 ( V_217 ) ;
V_163 -> V_144 . V_155 =
F_2 ( V_156 ) ;
if ( V_165 -> V_189 & V_192 )
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
V_226 ) ;
V_145 = ( T_1 ) ( V_165 -> V_159 + V_226 )
+ sizeof( struct V_61 ) ;
if ( F_7 ( V_163 -> V_144 . V_153 ) ==
V_181 ) {
struct V_227 * V_228 =
( void * ) V_163 -> V_144 . V_160 ;
memcpy ( V_228 -> V_176 , V_165 -> V_177 , V_229 ) ;
memcpy ( V_228 -> V_160 , V_165 -> V_163 ,
V_230 ) ;
V_145 = sizeof( struct V_227 ) ;
V_163 -> V_144 . V_159 =
F_2 ( V_145 ) ;
V_145 += V_226 ;
V_163 -> V_144 . V_60 =
F_2 ( V_145 ) ;
V_145 += sizeof( struct V_61 ) ;
}
V_4 -> V_8 = F_2 ( sizeof( V_163 -> V_13 ) + V_10
+ V_145 ) ;
if ( F_24 ( V_2 ) == V_197 ) {
V_221 = ( void * ) ( ( V_58 * ) & V_163 -> V_144 +
V_145 ) ;
V_221 -> V_231 . type =
F_2 ( V_232 ) ;
V_221 -> V_231 . V_168 = F_2 ( V_126 ) ;
memcpy ( V_221 -> V_124 , V_165 -> V_124 , V_126 ) ;
V_222 = V_145 + V_10 +
sizeof( V_163 -> V_13 ) +
sizeof( struct V_220 ) ;
} else {
V_222 = V_145 + V_10 +
sizeof( V_163 -> V_13 ) ;
}
V_4 -> V_8 = F_2 ( V_222 ) ;
}
return V_223 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_164 * V_165 )
{
if ( V_2 -> V_29 -> V_233 == V_234 )
return F_23 ( V_2 , V_4 ,
V_5 , V_31 ,
V_165 ) ;
else
return F_26 ( V_2 , V_4 ,
V_5 , V_31 ,
V_165 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
struct V_235 * V_236 =
& V_4 -> V_11 . V_236 ;
struct V_237 * V_238 =
& V_236 -> V_238 ;
V_58 V_239 = V_29 -> V_240 . V_239 ;
F_4 ( V_29 , V_171 ,
L_20 , V_239 ) ;
V_4 -> V_6 = F_2 ( V_241 ) ;
V_236 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_236 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_238 -> V_231 . type = F_2 ( V_242 ) ;
memcpy ( V_238 -> V_243 , V_29 -> V_240 . V_243 ,
sizeof( V_238 -> V_243 ) ) ;
V_238 -> V_231 . V_168 =
F_2 ( ( V_239 *
sizeof( struct V_244 ) )
+ sizeof( V_238 -> V_243 ) ) ;
if ( V_239 ) {
memcpy ( V_238 -> V_245 , V_29 -> V_240 . V_245 ,
V_239 * sizeof( struct
V_244 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_236 -> V_13 ) +
F_7 ( V_238 -> V_231 . V_168 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_236 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_246 )
{
struct V_247 * V_248 =
& ( V_4 -> V_11 . V_249 ) ;
V_4 -> V_6 = F_2 ( V_250 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_247 ) +
V_10 ) ;
V_4 -> V_123 = 0 ;
V_248 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_246 )
V_248 -> V_246 = F_2 ( * V_246 ) ;
else
V_248 -> V_246 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int
F_30 ( struct V_3 * V_4 , T_1 V_5 ,
void * V_251 )
{
struct V_252 * V_253 = ( void * ) V_251 ;
struct V_254 * V_255 = ( void * ) & V_4 -> V_11 . V_256 ;
V_4 -> V_6 = F_2 ( V_257 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_254 ) +
V_10 ) ;
V_255 -> V_13 = F_2 ( V_5 ) ;
V_255 -> V_258 = F_15 ( V_253 -> V_258 ) ;
V_255 -> V_44 = F_15 ( V_253 -> V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_259 * V_260 = V_79 ;
switch ( F_7 ( V_4 -> V_6 ) ) {
case V_261 :
{
struct V_262 * V_263 ;
V_4 -> V_8 = F_2 ( sizeof( * V_263 ) + V_10 ) ;
V_263 = & V_4 -> V_11 . V_263 ;
V_263 -> V_13 = F_2 ( V_5 ) ;
V_263 -> V_264 =
F_2 ( ( T_1 ) F_32 ( V_260 -> V_264 ) ) ;
V_263 -> V_44 = V_260 -> V_44 ;
break;
}
case V_265 :
{
struct V_266 * V_267 ;
V_4 -> V_8 = F_2 ( sizeof( * V_267 ) + V_10 ) ;
V_267 = & V_4 -> V_11 . V_267 ;
V_267 -> V_13 = F_2 ( V_5 ) ;
V_267 -> V_264 =
F_2 ( ( T_1 ) F_32 ( V_260 -> V_264 ) ) ;
V_267 -> V_44 = ( V_58 ) F_32 ( V_260 -> V_44 ) ;
break;
}
case V_268 :
{
struct V_269 * V_270 ;
V_4 -> V_8 = F_2 ( sizeof( * V_270 ) + V_10 ) ;
V_270 = & V_4 -> V_11 . V_270 ;
V_270 -> V_13 = F_2 ( V_5 ) ;
V_270 -> V_264 = F_2 ( ( T_1 ) F_32 ( V_260 -> V_264 ) ) ;
V_270 -> V_44 = ( V_58 ) F_32 ( V_260 -> V_44 ) ;
break;
}
case V_271 :
{
struct V_272 * V_273 ;
V_4 -> V_8 = F_2 ( sizeof( * V_273 ) + V_10 ) ;
V_273 = & V_4 -> V_11 . V_273 ;
V_273 -> V_13 = F_2 ( V_5 ) ;
V_273 -> V_264 =
F_2 ( ( T_1 ) F_32 ( V_260 -> V_264 ) ) ;
V_273 -> V_44 = ( V_58 ) F_32 ( V_260 -> V_44 ) ;
break;
}
case V_274 :
{
struct V_269 * V_275 ;
V_4 -> V_8 = F_2 ( sizeof( * V_275 ) + V_10 ) ;
V_275 = & V_4 -> V_11 . V_270 ;
V_275 -> V_13 = F_2 ( V_5 ) ;
V_275 -> V_264 =
F_2 ( ( T_1 ) F_32 ( V_260 -> V_264 ) ) ;
V_275 -> V_44 = ( V_58 ) F_32 ( V_260 -> V_44 ) ;
break;
}
case V_276 :
{
struct V_277 * V_278 = V_79 ;
struct V_279 * V_280 =
& V_4 -> V_11 . V_281 ;
V_4 -> V_8 = F_2 ( sizeof( * V_280 ) + V_10 ) ;
V_280 -> V_13 = F_2 ( V_5 ) ;
V_280 -> V_264 = V_278 -> V_264 ;
V_280 -> V_282 = V_278 -> V_282 ;
V_280 -> V_44 = 0 ;
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
struct V_283 * V_284 =
& V_4 -> V_11 . V_285 ;
struct V_286 * V_287 = V_2 -> V_29 -> V_287 ;
V_4 -> V_6 = F_2 ( V_288 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_283 ) + V_10 ) ;
V_4 -> V_123 = 0 ;
memset ( V_284 , 0 , sizeof( struct V_283 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_284 -> V_289 = ( T_2 ) ( V_287 -> V_290 ) ;
V_284 -> V_291 = ( T_2 ) ( ( ( V_292 ) V_287 -> V_290 ) >> 32 ) ;
V_284 -> V_293 = V_294 ;
V_284 -> V_295 = ( T_2 ) ( V_287 -> V_296 ) ;
V_284 -> V_297 = ( T_2 ) ( ( ( V_292 ) V_287 -> V_296 ) >> 32 ) ;
V_284 -> V_298 = V_294 ;
V_284 -> V_299 = ( T_2 ) ( V_287 -> V_300 ) ;
V_284 -> V_301 = ( T_2 ) ( ( ( V_292 ) V_287 -> V_300 ) >> 32 ) ;
V_284 -> V_302 = V_303 ;
if ( V_287 -> V_304 ) {
V_284 -> V_305 =
( T_2 ) ( V_287 -> V_306 ) ;
V_284 -> V_307 =
( T_2 ) ( ( ( V_292 ) ( V_287 -> V_306 ) ) >> 32 ) ;
F_4 ( V_2 -> V_29 , V_171 ,
L_21 ,
V_284 -> V_305 ) ;
}
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_308 * V_309 )
{
struct V_310 * V_311 = & V_4 -> V_11 . V_311 ;
struct V_312 * V_313 ;
T_1 V_314 ;
V_58 * V_315 ;
V_4 -> V_6 = F_2 ( V_316 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_310 ) +
V_10 ) ;
V_311 -> V_13 = F_2 ( V_309 -> V_13 ) ;
F_4 ( V_2 -> V_29 , V_36 ,
L_22 , V_309 -> V_13 ) ;
if ( V_309 -> V_13 == V_39 )
return 0 ;
V_311 -> V_317 = F_2 ( V_309 -> V_317 ) ;
V_314 = V_309 -> V_317 ;
F_4 ( V_2 -> V_29 , V_36 , L_23 ,
V_314 ) ;
if ( ( ( V_309 -> V_13 == V_318 ) ||
( V_309 -> V_13 == V_319 ) ) &&
( V_314 == 0 ) ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_24
L_25 ) ;
return - V_320 ;
}
if ( V_309 -> V_13 == V_318 )
return 0 ;
V_315 = ( ( V_58 * ) V_311 ) +
sizeof( struct V_310 ) ;
if ( V_314 & V_321 ) {
V_313 = (struct V_312 * ) V_315 ;
V_313 -> V_231 . type = F_2 ( V_322 ) ;
V_313 -> V_231 . V_168 =
F_2 ( sizeof( struct V_312 ) -
sizeof( struct V_61 ) ) ;
V_313 -> V_323 = V_309 -> V_324 . V_323 ;
V_313 -> V_325 = V_309 -> V_324 . V_325 ;
F_4 ( V_2 -> V_29 , V_326 ,
L_26
L_27 ,
V_309 -> V_324 . V_323 ,
V_309 -> V_324 . V_325 ) ;
V_315 += sizeof( struct V_312 ) ;
F_6 ( & V_4 -> V_8 ,
sizeof( struct V_312 ) ) ;
}
if ( V_314 & V_327 ) {
V_313 = (struct V_312 * ) V_315 ;
V_313 -> V_231 . type = F_2 ( V_328 ) ;
V_313 -> V_231 . V_168 =
F_2 ( sizeof( struct V_312 ) -
sizeof( struct V_61 ) ) ;
V_313 -> V_323 = V_309 -> V_329 . V_323 ;
V_313 -> V_325 = V_309 -> V_329 . V_325 ;
F_4 ( V_2 -> V_29 , V_326 ,
L_28
L_27 ,
V_309 -> V_329 . V_323 ,
V_309 -> V_329 . V_325 ) ;
V_315 += sizeof( struct V_312 ) ;
F_6 ( & V_4 -> V_8 ,
sizeof( struct V_312 ) ) ;
}
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_330 * V_331 ,
V_58 * * V_332 )
{
struct V_333 * V_334 = V_331 -> V_334 ;
int V_55 , V_335 ;
V_58 * V_336 = * V_332 ;
for ( V_55 = 0 ; V_55 < V_337 ; V_55 ++ ) {
V_334 = & V_331 -> V_334 [ V_55 ] ;
if ( ! V_334 -> V_338 )
break;
* ( V_339 * ) V_336 = F_15 ( ( T_2 ) V_334 -> V_340 ) ;
V_336 += 4 ;
* V_336 = V_341 ;
V_336 += 1 ;
V_335 = V_334 -> V_342 [ V_343 ] ;
memcpy ( V_336 , V_334 -> V_342 , V_335 ) ;
V_336 += V_335 ;
* V_336 = V_335 ;
V_336 += 1 ;
* V_336 = V_344 ;
V_336 += 1 ;
* ( V_339 * ) V_336 = F_15 ( ( T_2 ) V_334 -> V_264 ) ;
V_336 += 4 ;
* V_336 = V_341 ;
V_336 += 1 ;
* V_336 = V_334 -> V_338 ;
V_336 += 1 ;
if ( V_334 -> V_345 ) {
* V_336 = V_334 -> V_345 ;
V_336 += 1 ;
}
if ( V_336 - * V_332 > V_346 )
return - 1 ;
}
* V_332 = V_336 ;
return 0 ;
}
static int
F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_347 * V_348 )
{
struct V_349 * V_350 = & V_4 -> V_11 . V_350 ;
struct V_351 * V_331 = NULL ;
V_58 * V_315 = ( V_58 * ) V_350 ;
T_1 V_55 ;
V_4 -> V_6 = F_2 ( V_352 ) ;
V_350 -> V_353 = F_15 ( V_348 -> V_353 ) ;
V_350 -> V_354 = F_2 ( V_348 -> V_354 ) ;
V_315 += sizeof( * V_350 ) ;
for ( V_55 = 0 ; V_55 < V_348 -> V_354 ; V_55 ++ ) {
V_331 = (struct V_351 * ) V_315 ;
V_331 -> V_78 = V_348 -> V_331 [ V_55 ] . V_78 ;
V_331 -> V_13 = V_348 -> V_331 [ V_55 ] . V_13 ;
V_315 += sizeof( * V_350 -> V_331 ) ;
if ( F_35 ( V_2 ,
& V_348 -> V_331 [ V_55 ] , & V_315 ) )
return - 1 ;
V_331 -> V_355 =
F_2 ( V_315 - V_331 -> V_356 ) ;
}
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_315 - ( V_58 * ) V_350 ) + V_10 ) ;
return 0 ;
}
static T_2 F_37 ( V_58 * V_357 , T_3 V_168 , V_58 * V_358 )
{
V_58 * V_359 = V_357 , * V_360 = V_358 ;
while ( V_359 - V_357 < V_168 ) {
if ( * V_359 && ( isspace ( * V_359 ) || * V_359 == '\t' ) ) {
V_359 ++ ;
continue;
}
if ( isxdigit ( * V_359 ) ) {
* V_360 ++ = F_38 ( V_359 , NULL , 16 ) ;
V_359 += 2 ;
} else {
V_359 ++ ;
}
}
return V_360 - V_358 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_361 * V_362 , const char * V_363 )
{
#ifdef F_40
struct V_364 * V_365 ;
T_3 V_168 = strlen ( V_363 ) ;
int V_223 ;
F_41 (node, prop) {
if ( V_168 > strlen ( V_365 -> V_366 ) ||
strncmp ( V_365 -> V_366 , V_363 , V_168 ) )
continue;
if ( V_365 && V_365 -> V_44 && V_365 -> V_60 > 6 &&
V_365 -> V_60 <= V_367 - V_10 ) {
V_223 = F_42 ( V_2 , V_368 ,
V_28 , 0 ,
V_365 , true ) ;
if ( V_223 )
return V_223 ;
}
}
#endif
return 0 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_79 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
struct V_364 * V_365 = V_79 ;
T_2 V_168 ;
V_58 * V_369 = ( V_58 * ) V_4 + V_10 ;
int V_223 ;
if ( V_365 ) {
V_168 = V_365 -> V_60 ;
V_223 = F_44 ( V_29 -> V_370 , V_365 -> V_366 ,
V_369 , V_168 ) ;
if ( V_223 )
return V_223 ;
F_4 ( V_29 , V_171 ,
L_29 ,
V_365 -> V_366 ) ;
} else if ( V_29 -> V_371 -> V_369 && V_29 -> V_371 -> V_8 > 0 ) {
V_168 = F_37 ( ( V_58 * ) V_29 -> V_371 -> V_369 ,
V_29 -> V_371 -> V_8 , V_369 ) ;
F_4 ( V_29 , V_171 ,
L_30 ) ;
} else {
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_368 ) ;
V_4 -> V_8 = F_2 ( V_10 + V_168 ) ;
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_372 * V_373 = & V_4 -> V_11 . V_374 ;
const T_1 * V_375 = V_79 ;
V_373 -> V_13 = F_2 ( V_5 ) ;
V_373 -> V_376 = F_2 ( * V_375 ) ;
V_4 -> V_6 = F_2 ( V_377 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_372 ) +
V_10 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , bool * V_378 )
{
struct V_379 * V_380 = & V_4 -> V_11 . V_380 ;
struct V_381 * V_382 ;
V_4 -> V_6 = F_2 ( V_383 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_380 ) + sizeof( * V_382 ) + V_10 ) ;
V_380 -> V_13 = F_2 ( V_5 ) ;
V_382 = (struct V_381 * )
( ( V_58 * ) V_380 + sizeof( * V_380 ) ) ;
V_382 -> V_231 . type = F_2 ( V_384 ) ;
V_382 -> V_231 . V_168 = F_2 ( sizeof( V_382 -> V_78 ) ) ;
if ( V_380 -> V_13 == V_39 )
return 0 ;
if ( * V_378 )
V_382 -> V_78 = F_15 ( V_385 ) ;
else
V_382 -> V_78 = F_15 ( V_386 ) ;
return 0 ;
}
static int
F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_387 * V_388 =
& V_4 -> V_11 . V_388 ;
struct V_389 * V_390 = V_79 ;
struct V_391 * V_228 ;
T_1 V_392 , V_393 , V_60 ;
struct V_394 * V_395 ;
V_4 -> V_6 = F_2 ( V_396 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_388 -> V_13 = F_2 ( V_5 ) ;
V_388 -> V_397 = F_2 ( V_390 -> V_397 ) ;
V_395 = V_388 -> V_395 ;
for ( V_392 = 0 ; V_392 < V_390 -> V_397 ; V_392 ++ ) {
V_395 -> V_231 . type = F_2 ( V_398 ) ;
V_395 -> V_399 =
F_2 ( V_390 -> V_395 [ V_392 ] . V_399 ) ;
V_395 -> V_400 = V_390 -> V_395 [ V_392 ] . V_400 ;
V_395 -> V_401 = V_390 -> V_395 [ V_392 ] . V_401 ;
V_60 = 0 ;
V_228 = V_395 -> V_11 ;
for ( V_393 = 0 ; V_393 < V_390 -> V_395 [ V_392 ] . V_401 ; V_393 ++ ) {
V_228 -> V_402 = V_390 -> V_395 [ V_392 ] . V_11 [ V_393 ] . V_402 ;
V_228 -> V_403 =
V_390 -> V_395 [ V_392 ] . V_11 [ V_393 ] . V_403 ;
V_228 -> V_264 =
F_2 ( V_390 -> V_395 [ V_392 ] . V_11 [ V_393 ] . V_264 ) ;
memcpy ( V_228 -> V_404 ,
V_390 -> V_395 [ V_392 ] . V_11 [ V_393 ] . V_404 ,
V_228 -> V_403 ) ;
V_60 += sizeof( struct V_391 ) ;
V_228 ++ ;
}
V_395 -> V_231 . V_168 = F_2 ( V_60 + sizeof( T_1 ) +
sizeof( V_58 ) + sizeof( V_58 ) ) ;
F_6 ( & V_4 -> V_8 , F_7 ( V_395 -> V_231 . V_168 ) +
sizeof( struct V_61 ) ) ;
V_395 = ( void * ) ( ( V_58 * ) V_395 -> V_11 + V_60 ) ;
}
F_6 ( & V_4 -> V_8 , sizeof( T_1 ) + sizeof( T_1 ) ) ;
return 0 ;
}
static int
F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_405 * V_406 = & V_4 -> V_11 . V_406 ;
struct V_407 * V_408 ;
struct V_409 * V_410 ;
T_1 V_168 ;
V_4 -> V_6 = F_2 ( V_411 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_406 -> V_412 = F_2 ( V_5 ) ;
F_6 ( & V_4 -> V_8 , sizeof( V_406 -> V_412 ) ) ;
switch ( V_5 ) {
case V_413 :
V_410 = V_79 ;
V_168 = sizeof( * V_410 ) ;
memcpy ( V_406 -> V_414 , V_410 , V_168 ) ;
break;
case V_415 :
V_408 = V_79 ;
V_168 = sizeof( * V_408 ) ;
memcpy ( V_406 -> V_414 , V_408 , V_168 ) ;
break;
case V_416 :
V_168 = sizeof( struct V_417 ) ;
memcpy ( V_406 -> V_414 , V_79 , V_168 ) ;
break;
case V_418 :
V_168 = sizeof( struct V_419 ) ;
memcpy ( V_406 -> V_414 , V_79 , V_168 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_31 ) ;
return - V_420 ;
}
F_6 ( & V_4 -> V_8 , V_168 ) ;
return 0 ;
}
static int
F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_79 )
{
struct V_421 * V_422 = & V_4 -> V_11 . V_422 ;
struct V_423 * V_424 = V_79 ;
struct V_425 * V_426 ;
struct V_427 * V_428 ;
struct V_429 * V_430 ;
struct V_431 * V_432 ;
struct V_433 * V_434 ;
struct V_435 * V_436 ;
struct V_437 * V_438 ;
struct V_439 * V_440 ;
V_58 * V_315 , V_441 ;
T_1 V_442 = 0 ;
struct V_443 * V_11 = V_2 -> V_444 ;
V_4 -> V_6 = F_2 ( V_445 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
F_6 ( & V_4 -> V_8 , sizeof( struct V_421 ) ) ;
V_422 -> V_446 = 0 ;
memcpy ( V_422 -> V_447 , V_424 -> V_447 , V_126 ) ;
V_426 = F_50 ( V_2 , V_424 -> V_447 ) ;
V_315 = ( V_58 * ) V_422 + sizeof( struct V_421 ) ;
switch ( V_424 -> V_412 ) {
case V_448 :
V_422 -> V_412 = F_2 ( V_449 ) ;
break;
case V_450 :
V_422 -> V_412 = F_2 ( V_451 ) ;
break;
case V_452 :
V_422 -> V_412 = F_2 ( V_453 ) ;
if ( ! V_11 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_32 ,
V_424 -> V_447 ) ;
return - V_454 ;
}
* ( V_43 * ) V_315 = F_2 ( V_11 -> V_455 ) ;
V_442 += sizeof( V_11 -> V_455 ) ;
V_441 = V_11 -> V_456 | ( V_11 -> V_457 << 5 ) ;
V_432 = (struct V_431 * ) ( V_315 +
V_442 ) ;
V_432 -> V_231 . type = F_2 ( V_458 ) ;
V_432 -> V_231 . V_168 = F_2 ( sizeof( V_441 ) ) ;
V_432 -> V_441 = V_441 ;
V_442 += sizeof( struct V_431 ) ;
if ( V_11 -> V_459 ) {
V_430 = (struct V_429 * ) ( V_315 +
V_442 ) ;
V_430 -> V_231 . type =
F_2 ( V_460 ) ;
V_430 -> V_231 . V_168 =
F_2 ( sizeof( struct V_461 ) ) ;
memcpy ( & V_430 -> V_462 , V_11 -> V_459 ,
sizeof( struct V_461 ) ) ;
V_442 += sizeof( struct V_429 ) ;
}
if ( V_11 -> V_463 && V_11 -> V_464 ) {
V_428 = (struct V_427 * ) ( V_315 +
V_442 ) ;
V_428 -> V_231 . type =
F_2 ( V_465 ) ;
V_428 -> V_231 . V_168 =
F_2 ( V_11 -> V_464 ) ;
memcpy ( V_428 -> V_466 , V_11 -> V_463 ,
V_11 -> V_464 ) ;
V_442 += sizeof( struct V_427 ) +
V_11 -> V_464 ;
}
if ( V_11 -> V_467 && V_11 -> V_468 ) {
V_434 = (struct V_433 * ) ( V_315 +
V_442 ) ;
V_434 -> V_231 . type =
F_2 ( V_469 ) ;
V_434 -> V_231 . V_168 = F_2 ( V_11 -> V_468 ) ;
memcpy ( V_434 -> V_467 , V_11 -> V_467 ,
V_11 -> V_468 ) ;
V_442 += sizeof( struct V_433 ) +
V_11 -> V_468 ;
}
if ( V_11 -> V_470 ) {
V_436 = (struct V_435 * ) ( V_315 +
V_442 ) ;
V_436 -> V_231 . type =
F_2 ( V_471 ) ;
V_436 -> V_231 . V_168 =
F_2 ( sizeof( struct V_472 ) ) ;
memcpy ( & V_436 -> V_473 , V_11 -> V_470 ,
sizeof( struct V_472 ) ) ;
V_442 += sizeof( struct V_435 ) ;
}
if ( V_11 -> V_438 ) {
V_438 = (struct V_437 * ) ( V_315 + V_442 ) ;
V_438 -> V_231 . type = F_2 ( V_474 ) ;
V_438 -> V_231 . V_168 = F_2 ( sizeof( V_11 -> V_438 ) ) ;
V_438 -> V_438 = F_2 ( V_11 -> V_438 ) ;
V_442 += sizeof( struct V_437 ) ;
}
V_440 = ( void * ) ( V_315 + V_442 ) ;
V_440 -> V_231 . type = F_2 ( V_475 ) ;
V_440 -> V_231 . V_168 = F_2 ( sizeof( V_440 -> V_44 ) ) ;
V_440 -> V_44 = F_2 ( V_476 ) ;
V_442 += sizeof( struct V_439 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR , L_33 ) ;
return - V_420 ;
}
F_6 ( & V_4 -> V_8 , V_442 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_477 * V_390 =
& V_4 -> V_11 . V_478 ;
V_4 -> V_6 = F_2 ( V_479 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_477 ) +
V_10 ) ;
V_390 -> V_13 = V_5 ;
if ( V_5 == V_28 )
V_390 -> V_246 = * ( V_58 * ) V_79 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_480 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_481 ) +
V_10 ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , T_4 V_482 ,
T_1 V_5 , T_2 V_31 ,
void * V_79 , void * V_483 )
{
struct V_3 * V_484 = V_483 ;
int V_223 = 0 ;
switch ( V_482 ) {
case V_485 :
V_223 = F_54 ( V_2 , V_484 ) ;
break;
case V_368 :
V_223 = F_43 ( V_2 , V_484 , V_79 ) ;
break;
case V_30 :
V_223 = F_3 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_121 :
V_223 = F_16 ( V_2 , V_484 ,
V_5 ) ;
break;
case V_132 :
V_223 = F_17 ( V_484 , V_5 ,
V_79 ) ;
break;
case V_56 :
V_223 = F_9 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_77 :
V_223 = F_11 ( V_484 , V_5 ,
V_79 ) ;
break;
case V_81 :
V_223 = F_12 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_88 :
V_223 = F_13 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_486 :
V_223 = F_55 ( V_2 , V_484 , V_5 ,
( T_4 ) V_31 , V_79 ) ;
break;
case V_108 :
V_223 = F_14 ( V_2 , V_484 , V_5 ,
(struct V_101 * ) V_79 ) ;
break;
case V_487 :
V_223 = F_56 ( V_484 , V_79 ) ;
break;
case V_488 :
V_223 = F_57 ( V_2 , V_484 ,
V_79 ) ;
break;
case V_489 :
V_223 = F_58 ( V_484 ) ;
break;
case V_490 :
V_223 = F_59 ( V_2 , V_484 , V_79 ) ;
break;
case V_139 :
V_223 = F_18 ( V_2 , V_484 ,
V_79 ) ;
break;
case V_491 :
V_223 = F_60 ( V_2 , V_484 ,
V_79 ) ;
break;
case V_45 :
V_223 = F_8 ( V_484 ) ;
break;
case V_492 :
V_223 = F_61 ( V_2 , V_484 ,
V_79 ) ;
break;
case V_142 :
V_223 = F_19 ( V_484 ) ;
break;
case V_7 :
V_223 = F_1 ( V_2 , V_484 , V_5 ) ;
break;
case V_37 :
V_223 = F_5 ( V_2 , V_484 , V_5 ,
V_31 , V_79 ) ;
break;
case V_493 :
V_484 -> V_6 =
F_2 ( V_493 ) ;
V_484 -> V_8 =
F_2 ( sizeof( struct V_494 ) +
V_10 ) ;
V_2 -> V_495 = 0 ;
V_223 = 0 ;
break;
case V_496 :
V_484 -> V_6 = F_2 ( V_482 ) ;
V_484 -> V_11 . V_497 . V_498 =
( V_58 ) ( * ( ( T_2 * ) V_79 ) ) ;
memcpy ( & V_484 -> V_11 , V_79 ,
sizeof( struct V_499 ) ) ;
V_484 -> V_8 =
F_2 ( sizeof( struct V_499 ) +
V_10 ) ;
V_223 = 0 ;
break;
case V_500 :
V_484 -> V_6 = F_2 ( V_482 ) ;
V_484 -> V_11 . V_501 . V_13 = F_2 ( V_5 ) ;
V_484 -> V_11 . V_501 . V_502 = F_15 ( * ( T_2 * ) V_79 ) ;
V_484 -> V_8 =
F_2 ( sizeof( struct V_503 ) +
V_10 ) ;
V_223 = 0 ;
break;
case V_504 :
V_484 -> V_6 = F_2 ( V_482 ) ;
memcpy ( & V_484 -> V_11 , V_79 ,
sizeof( struct V_505 ) ) ;
V_484 -> V_8 =
F_2 ( sizeof( struct V_505 ) +
V_10 ) ;
break;
case V_506 :
V_223 = F_62 ( V_2 , V_484 , V_5 , V_79 ) ;
break;
case V_507 :
V_484 -> V_6 = F_2 ( V_482 ) ;
V_484 -> V_11 . V_508 . V_13 = F_2 ( V_5 ) ;
V_484 -> V_11 . V_508 . V_78 = F_2 ( * ( T_1 * ) V_79 ) ;
V_484 -> V_8 =
F_2 ( sizeof( struct V_509 ) +
V_10 ) ;
break;
case V_510 :
if ( V_2 -> V_29 -> V_511 == V_512 )
V_2 -> V_29 -> V_511 = V_513 ;
V_484 -> V_6 = F_2 ( V_482 ) ;
V_484 -> V_8 = F_2 ( V_10 ) ;
break;
case V_514 :
V_2 -> V_29 -> V_511 = V_512 ;
V_484 -> V_6 = F_2 ( V_482 ) ;
V_484 -> V_8 = F_2 ( V_10 ) ;
break;
case V_515 :
V_223 = F_63 ( V_484 , V_79 ) ;
break;
case V_516 :
V_223 = F_64 ( V_484 , V_79 ) ;
break;
case V_517 :
V_223 = F_65 ( V_2 , V_484 , V_79 ) ;
break;
case V_187 :
V_223 = F_27 ( V_2 , V_484 ,
V_5 , V_31 ,
V_79 ) ;
break;
case V_241 :
V_223 = F_28 ( V_2 , V_484 ,
V_5 ) ;
break;
case V_518 :
V_223 = F_66 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_519 :
V_223 = F_67 ( V_484 , V_5 ,
V_79 ) ;
break;
case V_520 :
V_223 = F_68 ( V_2 , V_484 , V_5 , V_79 ) ;
break;
case V_521 :
F_4 ( V_2 -> V_29 , V_36 ,
L_34 ) ;
V_484 -> V_6 = F_2 ( V_521 ) ;
V_484 -> V_8 =
F_2 ( sizeof( struct V_522 ) +
V_10 ) ;
V_223 = 0 ;
break;
case V_250 :
V_223 = F_29 ( V_484 , V_5 ,
V_79 ) ;
break;
case V_523 :
V_223 = F_69 ( V_2 , V_484 , V_79 ) ;
break;
case V_257 :
V_223 = F_30 ( V_484 , V_5 , V_79 ) ;
break;
case V_261 :
case V_265 :
case V_268 :
case V_271 :
case V_274 :
case V_276 :
V_223 = F_31 ( V_484 , V_5 , V_79 ) ;
break;
case V_524 :
V_484 -> V_6 = F_2 ( V_482 ) ;
if ( V_2 -> V_210 == V_211 )
V_484 -> V_11 . V_210 . V_525 =
V_526 ;
else if ( V_2 -> V_210 == V_527 ||
V_2 -> V_210 == V_528 )
V_484 -> V_11 . V_210 . V_525 =
V_529 ;
else if ( V_2 -> V_210 == V_530 ||
V_2 -> V_210 == V_531 )
V_484 -> V_11 . V_210 . V_525 = V_532 ;
V_484 -> V_8 = F_2 ( sizeof( struct
V_533 ) + V_10 ) ;
V_223 = 0 ;
break;
case V_288 :
V_223 = F_33 ( V_2 , V_484 , V_5 ) ;
break;
case V_316 :
V_223 = F_34 ( V_2 , V_484 , V_79 ) ;
break;
case V_352 :
V_223 = F_36 ( V_2 , V_484 , V_79 ) ;
break;
case V_396 :
V_223 = F_47 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_445 :
V_223 = F_49 ( V_2 , V_484 , V_79 ) ;
break;
case V_411 :
V_223 = F_48 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_534 :
V_223 = F_70 ( V_2 , V_484 ,
V_79 ) ;
break;
case V_479 :
V_223 = F_51 ( V_484 , V_5 ,
V_79 ) ;
break;
case V_480 :
V_223 = F_52 ( V_2 , V_484 ) ;
break;
case V_377 :
V_223 = F_45 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
case V_383 :
V_223 = F_46 ( V_2 , V_484 , V_5 ,
V_79 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_35 , V_482 ) ;
V_223 = - 1 ;
break;
}
return V_223 ;
}
int F_71 ( struct V_1 * V_2 , V_58 V_535 , bool V_536 )
{
struct V_103 * V_29 = V_2 -> V_29 ;
int V_223 ;
T_1 V_246 = true ;
struct V_537 V_538 ;
struct V_539 V_540 ;
enum V_541 V_542 ;
struct V_543 V_544 ;
V_58 V_545 ;
if ( V_535 ) {
if ( V_2 -> V_29 -> V_546 == V_547 ) {
V_223 = F_42 ( V_2 ,
V_288 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_223 )
return - 1 ;
}
V_223 = F_42 ( V_2 , V_510 ,
V_28 , 0 , NULL , true ) ;
if ( V_223 )
return - 1 ;
V_29 -> V_370 =
F_72 ( NULL , L_36 ) ;
if ( V_29 -> V_370 ) {
V_223 = F_39 ( V_2 , V_29 -> V_370 ,
L_37 ) ;
if ( V_223 )
return - 1 ;
}
if ( V_29 -> V_371 ) {
V_223 = F_42 ( V_2 , V_368 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_223 )
return - 1 ;
}
V_223 = F_42 ( V_2 , V_485 ,
V_39 , 0 , NULL , true ) ;
if ( V_223 )
return - 1 ;
if ( V_2 -> V_29 -> V_546 == V_548 &&
F_73 ( V_2 -> V_29 -> V_549 ) &&
! V_2 -> V_29 -> V_550 ) {
V_545 = true ;
V_223 = F_42 ( V_2 ,
V_479 ,
V_28 , 0 ,
& V_545 ,
true ) ;
if ( V_223 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_38 ) ;
V_29 -> V_551 = false ;
}
}
V_223 = F_42 ( V_2 , V_518 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_552 , true ) ;
if ( V_223 )
return - 1 ;
if ( V_2 -> V_553 != V_554 ) {
V_2 -> V_29 -> V_555 = V_556 ;
V_223 = F_42 ( V_2 ,
V_486 ,
V_557 , V_558 , NULL ,
true ) ;
if ( V_223 )
return - 1 ;
}
if ( V_559 ) {
V_29 -> V_560 = true ;
if ( F_74 ( V_29 -> V_549 ) )
V_223 = F_42 ( V_2 ,
V_377 ,
V_28 , 0 ,
& V_29 -> V_560 ,
true ) ;
if ( V_223 )
return - 1 ;
}
}
V_223 = F_42 ( V_2 , V_56 ,
V_39 , 0 , NULL , true ) ;
if ( V_223 )
return - 1 ;
V_2 -> V_561 = 0 ;
V_223 = F_42 ( V_2 , V_81 ,
V_39 , 0 , NULL , true ) ;
if ( V_223 )
return - 1 ;
if ( V_2 -> V_553 == V_562 ) {
V_223 = F_42 (
V_2 ,
V_250 ,
V_28 , 0 , & V_246 , true ) ;
if ( V_223 )
return - 1 ;
}
memset ( & V_538 , 0 , sizeof( V_538 ) ) ;
V_538 . V_246 = true ;
V_223 = F_42 ( V_2 , V_519 ,
V_28 , 0 ,
& V_538 , true ) ;
if ( V_223 )
return - 1 ;
V_223 = F_42 ( V_2 , V_30 ,
V_28 , 0 ,
& V_2 -> V_563 , true ) ;
if ( V_223 )
return - 1 ;
if ( ! V_564 &&
V_535 && V_2 -> V_29 -> V_546 != V_565 &&
V_2 -> V_553 != V_554 ) {
V_540 . V_540 = V_566 ;
V_540 . V_567 = V_568 ;
V_223 = F_42 ( V_2 , V_486 ,
V_557 , V_569 ,
& V_540 , true ) ;
if ( V_223 )
return - 1 ;
}
if ( V_2 -> V_553 != V_554 ) {
V_542 = V_570 ;
V_223 = F_42 ( V_2 , V_37 ,
V_28 , V_571 ,
& V_542 , true ) ;
if ( V_223 )
F_4 ( V_2 -> V_29 , ERROR ,
L_39 ) ;
}
V_544 . V_572 = V_573 ;
V_223 = F_42 ( V_2 , V_520 ,
V_28 , 0 , & V_544 , true ) ;
if ( V_536 ) {
V_2 -> V_29 -> V_574 = V_520 ;
V_223 = - V_575 ;
}
return V_223 ;
}
