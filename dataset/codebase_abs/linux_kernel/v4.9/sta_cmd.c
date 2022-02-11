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
switch ( V_5 ) {
case V_28 :
if ( V_2 -> V_29 -> V_89 == V_90 ) {
V_4 -> V_8 = F_2 ( sizeof( struct
V_84 )
+ V_10 ) ;
V_85 -> V_91 = F_2 ( V_92 ) ;
V_85 -> V_93 = F_2 ( ( T_1 ) V_83 ->
V_94 ) ;
V_85 -> V_95 = F_2 ( V_96 ) ;
V_85 -> V_97 = F_2 ( ( T_1 ) V_83 ->
V_98 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( struct
V_86 ) +
V_10 ) ;
V_87 -> V_13 = F_2 ( V_99 ) ;
V_87 -> V_100 = F_2 ( ( T_1 ) V_83 -> V_94 ) ;
}
break;
case V_39 :
if ( V_2 -> V_29 -> V_89 == V_90 ) {
V_4 -> V_8 = F_2 ( sizeof( struct
V_84 ) +
V_10 ) ;
V_85 -> V_91 = F_2 ( V_101 ) ;
V_85 -> V_95 = F_2 ( V_102 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( struct
V_86 ) +
V_10 ) ;
V_87 -> V_13 = F_2 ( V_103 ) ;
}
break;
}
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_104 * V_105 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
struct V_107 * V_108 = & V_4 -> V_11 . V_109 ;
bool V_110 = false ;
if ( ! V_105 )
V_110 = true ;
V_4 -> V_6 = F_2 ( V_111 ) ;
if ( ! V_110 &&
( V_105 -> V_112 != F_15 ( V_113 ) ) &&
( ( V_29 -> V_114 > 0 ) &&
( V_29 -> V_114 <= V_115 ) ) ) {
F_4 ( V_29 , V_36 ,
L_5 ,
V_29 -> V_114 ) ;
memcpy ( ( ( V_58 * ) V_108 ) +
sizeof( struct V_107 ) ,
V_29 -> V_116 , V_29 -> V_114 ) ;
V_4 -> V_8 = F_2
( V_29 -> V_114 +
sizeof( struct V_107 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( V_10 + sizeof( struct
V_107 ) ) ;
}
if ( V_110 ) {
V_108 -> V_13 = F_2 ( V_117 ) ;
V_108 -> V_11 . V_110 . V_118 = F_2 ( V_119 ) ;
} else {
V_108 -> V_13 = F_2 ( V_120 ) ;
V_108 -> V_11 . V_121 . V_112 = V_105 -> V_112 ;
V_108 -> V_11 . V_121 . V_122 = V_105 -> V_122 ;
V_108 -> V_11 . V_121 . V_123 = V_105 -> V_123 ;
F_4 ( V_29 , V_36 ,
L_6 ,
V_108 -> V_11 . V_121 . V_112 ,
V_108 -> V_11 . V_121 . V_122 ,
V_108 -> V_11 . V_121 . V_123 ) ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
V_4 -> V_6 = F_2 ( V_124 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_125 ) +
V_10 ) ;
V_4 -> V_126 = 0 ;
V_4 -> V_11 . V_127 . V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 )
memcpy ( V_4 -> V_11 . V_127 . V_127 , V_2 -> V_128 ,
V_129 ) ;
return 0 ;
}
static int
F_17 ( struct V_3 * V_4 ,
T_1 V_5 ,
struct V_130 * V_131 )
{
struct V_132 * V_133 = & V_4 -> V_11 . V_134 ;
V_4 -> V_8 = F_2 ( sizeof( struct V_132 ) +
V_10 ) ;
V_4 -> V_6 = F_2 ( V_135 ) ;
V_133 -> V_13 = F_2 ( V_5 ) ;
V_133 -> V_136 =
F_2 ( ( T_1 ) V_131 -> V_137 ) ;
memcpy ( V_133 -> V_138 , V_131 -> V_138 ,
V_131 -> V_137 * V_129 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
V_58 * V_139 )
{
struct V_140 * V_141 = & V_4 -> V_11 . V_141 ;
V_4 -> V_6 = F_2 ( V_142 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_140 )
+ V_10 ) ;
memcpy ( V_141 -> V_127 , V_139 , V_129 ) ;
F_4 ( V_2 -> V_29 , V_36 , L_7 , V_141 -> V_127 ) ;
V_141 -> V_143 = F_2 ( V_144 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_145 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
return 0 ;
}
static int
F_20 ( struct V_1 * V_2 ,
struct V_146 * V_147 ,
T_1 * V_148 )
{
int V_149 ;
V_58 V_55 ;
for ( V_55 = 0 ; V_55 < V_150 ; V_55 ++ ) {
if ( ( V_2 -> V_151 [ V_55 ] . V_152 == V_153 ) ||
( V_2 -> V_151 [ V_55 ] . V_152 == V_154 ) ) {
V_147 -> type =
F_2 ( V_155 ) ;
#define F_21 8
V_147 -> V_60 = F_2 ( ( T_1 )
( V_2 -> V_151 [ V_55 ] .
V_152 +
F_21 ) ) ;
V_147 -> V_156 =
F_2 ( V_157 ) ;
V_147 -> V_158 =
F_2 ( V_159 | V_160 |
V_161 ) ;
V_147 -> V_162 =
F_2 ( V_2 -> V_151 [ V_55 ] . V_152 ) ;
V_147 -> V_163 [ 0 ] = V_55 ;
if ( V_55 ==
( V_2 ->
V_164 & V_165 ) )
V_147 -> V_163 [ 1 ] = 1 ;
else
V_147 -> V_163 [ 1 ] = 0 ;
memmove ( & V_147 -> V_163 [ 2 ] ,
V_2 -> V_151 [ V_55 ] . V_166 ,
V_2 -> V_151 [ V_55 ] . V_152 ) ;
V_149 = V_2 -> V_151 [ V_55 ] . V_152 +
F_21 +
sizeof( struct V_61 ) ;
* V_148 += ( T_1 ) V_149 ;
V_147 =
(struct V_146 * )
( ( V_58 * ) V_147 +
V_149 ) ;
} else if ( ! V_2 -> V_151 [ V_55 ] . V_152 ) {
continue;
} else {
F_4 ( V_2 -> V_29 , ERROR ,
L_8 ,
( V_55 + 1 ) , V_2 -> V_151 [ V_55 ] . V_152 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_167 * V_168 ,
struct V_169 * V_170 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
T_1 V_8 , V_171 = V_172 ;
if ( V_168 -> V_173 ) {
F_4 ( V_29 , V_174 ,
L_9 , V_175 ) ;
if ( V_168 -> V_176 )
memcpy ( V_170 -> V_147 . V_177 . V_178 . V_179 ,
V_168 -> V_180 , V_168 -> V_181 ) ;
V_170 -> V_147 . V_158 &= F_2 ( ~ V_161 ) ;
V_170 -> V_147 . V_158 |= F_2 ( V_182 ) ;
V_170 -> V_147 . V_183 = V_184 ;
V_170 -> V_147 . V_177 . V_178 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_178 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
V_171 += sizeof( struct V_185 ) ;
} else if ( V_168 -> V_186 ) {
F_4 ( V_29 , V_174 ,
L_10 , V_175 ) ;
V_170 -> V_147 . V_183 = V_187 ;
V_170 -> V_147 . V_188 = V_168 -> V_189 & V_190 ;
} else {
F_4 ( V_29 , V_174 ,
L_11 , V_175 ) ;
if ( V_168 -> V_176 )
memcpy ( V_170 -> V_147 . V_177 . V_191 . V_180 ,
V_168 -> V_180 , V_168 -> V_181 ) ;
V_170 -> V_147 . V_183 = V_192 ;
V_170 -> V_147 . V_177 . V_191 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_191 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
V_171 += sizeof( struct V_193 ) ;
}
V_170 -> V_147 . V_171 = F_2 ( V_171 ) ;
V_8 = V_171 + sizeof( struct V_61 ) +
sizeof( V_170 -> V_13 ) + V_10 ;
V_4 -> V_8 = F_2 ( V_8 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_167 * V_168 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
V_58 * V_139 = V_168 -> V_127 ;
T_1 V_158 , V_171 = V_172 ;
struct V_169 * V_170 =
& V_4 -> V_11 . V_194 ;
V_4 -> V_6 = F_2 ( V_195 ) ;
V_170 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
F_4 ( V_29 , V_174 , L_12 , V_175 ) ;
V_170 -> V_147 . V_188 =
V_168 -> V_189 & V_190 ;
V_170 -> V_147 . type = F_2 ( V_196 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_172 ) ;
memcpy ( V_170 -> V_147 . V_127 , V_139 , V_129 ) ;
if ( V_168 -> V_189 & V_197 )
V_158 = V_160 ;
else
V_158 = V_161 ;
if ( V_168 -> V_173 )
V_158 |= V_182 ;
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_10 + V_172 +
sizeof( V_170 -> V_13 ) ) ;
return 0 ;
}
memset ( & V_170 -> V_147 , 0 ,
sizeof( struct V_198 ) ) ;
if ( V_168 -> V_199 ) {
F_4 ( V_29 , V_174 , L_13 , V_175 ) ;
V_170 -> V_13 = F_2 ( V_200 ) ;
V_170 -> V_147 . type = F_2 ( V_196 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_172 ) ;
V_170 -> V_147 . V_188 = V_168 -> V_189 & V_190 ;
V_158 = V_161 | V_160 ;
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
memcpy ( V_170 -> V_147 . V_127 , V_139 , V_129 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_10 + V_172 +
sizeof( V_170 -> V_13 ) ) ;
return 0 ;
}
V_170 -> V_13 = F_2 ( V_28 ) ;
V_170 -> V_147 . V_188 = V_168 -> V_189 & V_190 ;
V_170 -> V_147 . type = F_2 ( V_196 ) ;
V_158 = V_159 ;
memcpy ( V_170 -> V_147 . V_127 , V_139 , V_129 ) ;
if ( V_168 -> V_162 <= V_154 ) {
F_4 ( V_29 , V_174 , L_14 , V_175 ) ;
V_171 += sizeof( struct V_201 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_171 ) ;
V_170 -> V_147 . V_183 = V_157 ;
if ( F_24 ( V_2 ) == V_202 ) {
V_158 |= V_161 | V_160 ;
} else {
if ( V_168 -> V_203 ) {
V_158 |= V_161 | V_160 ;
if ( V_170 -> V_147 . V_188 ==
( V_2 -> V_164 & V_190 ) )
V_158 |= V_204 ;
} else {
if ( F_25 ( V_139 ) )
V_158 |= V_161 ;
else
V_158 |= V_160 | V_204 ;
}
}
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
V_170 -> V_147 . V_177 . V_205 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_205 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_171 + sizeof( V_170 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( F_25 ( V_139 ) )
V_158 |= V_161 | V_206 ;
else
V_158 |= V_160 | V_207 | V_206 ;
if ( V_168 -> V_208 ) {
F_4 ( V_29 , V_174 , L_15 , V_175 ) ;
V_170 -> V_147 . V_183 = V_209 ;
memcpy ( V_170 -> V_147 . V_177 . V_210 . V_180 , V_168 -> V_180 ,
V_211 ) ;
V_170 -> V_147 . V_177 . V_210 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_210 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
if ( F_25 ( V_139 ) )
V_2 -> V_212 . V_213 = true ;
if ( ! V_2 -> V_212 . V_213 )
V_158 |= V_204 ;
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
V_171 += sizeof( struct V_214 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_171 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_171 + sizeof( V_170 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( V_2 -> V_215 == V_216 ) {
V_158 |= V_204 ;
if ( ! V_2 -> V_212 . V_217 &&
! F_25 ( V_139 ) )
V_158 |= V_160 ;
} else {
if ( ! V_2 -> V_218 )
V_158 |= V_204 ;
}
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
if ( V_168 -> V_162 == V_219 )
return F_22 ( V_2 , V_4 , V_168 , V_170 ) ;
if ( V_168 -> V_162 == V_220 ) {
F_4 ( V_29 , V_174 ,
L_16 , V_175 ) ;
if ( V_168 -> V_176 )
memcpy ( V_170 -> V_147 . V_177 . V_221 . V_180 ,
V_168 -> V_180 , V_168 -> V_181 ) ;
V_170 -> V_147 . V_183 = V_222 ;
V_170 -> V_147 . V_177 . V_221 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_221 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
V_171 += sizeof( struct V_223 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_171 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_171 + sizeof( V_170 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int
F_26 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_167 * V_168 )
{
struct V_224 * V_166 =
& V_4 -> V_11 . V_166 ;
struct V_225 * V_226 ;
T_1 V_148 = 0 , V_227 ;
int V_228 = 0 ;
V_4 -> V_6 = F_2 ( V_195 ) ;
V_166 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_166 -> V_13 ) + V_10 ) ;
return V_228 ;
}
if ( ! V_168 ) {
memset ( & V_166 -> V_147 , 0 ,
( V_150 *
sizeof( struct V_146 ) ) ) ;
V_228 = F_20 ( V_2 ,
& V_166 -> V_147 ,
& V_148 ) ;
V_4 -> V_8 = F_2 ( V_148 +
sizeof( V_166 -> V_13 ) + V_10 ) ;
return V_228 ;
} else
memset ( & V_166 -> V_147 , 0 ,
sizeof( struct V_146 ) ) ;
if ( V_168 -> V_208 ) {
F_4 ( V_2 -> V_29 , V_174 , L_17 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_209 ) ;
if ( V_31 == V_229 )
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
else
V_166 -> V_147 . V_158 =
F_2 ( ! V_159 ) ;
V_166 -> V_147 . V_163 [ 0 ] = V_168 -> V_189 ;
if ( ! V_2 -> V_212 . V_213 )
V_166 -> V_147 . V_163 [ 1 ] = 1 ;
else
V_166 -> V_147 . V_163 [ 1 ] = 0 ;
if ( ! F_25 ( V_168 -> V_127 ) ) {
V_166 -> V_147 . V_158 |=
F_2 ( V_160 ) ;
} else {
V_166 -> V_147 . V_158 |=
F_2 ( V_161 ) ;
V_2 -> V_212 . V_213 = true ;
}
V_166 -> V_147 . type =
F_2 ( V_155 ) ;
V_166 -> V_147 . V_162 =
F_2 ( V_230 ) ;
memcpy ( & V_166 -> V_147 . V_163 [ 2 ] ,
V_168 -> V_166 , V_168 -> V_162 ) ;
memcpy ( & V_166 -> V_147 . V_163 [ 2 + V_168 -> V_162 ] ,
V_168 -> V_180 , V_211 ) ;
V_166 -> V_147 . V_60 =
F_2 ( V_230 + V_231 ) ;
V_148 = ( V_230 + V_231 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_166 -> V_13 )
+ V_10 + V_148 ) ;
return V_228 ;
}
if ( V_168 -> V_162 == V_219 ) {
if ( V_168 -> V_173 ) {
F_4 ( V_2 -> V_29 , V_36 , L_18 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_184 ) ;
if ( V_31 == V_229 )
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
else
V_166 -> V_147 . V_158 =
F_2 ( ! V_159 ) ;
V_166 -> V_147 . V_158 |=
F_2 ( V_182 ) ;
} else {
F_4 ( V_2 -> V_29 , V_36 , L_19 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_192 ) ;
if ( V_31 == V_229 )
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
else
V_166 -> V_147 . V_158 =
F_2 ( ! V_159 ) ;
if ( V_168 -> V_189 & V_197 )
V_166 -> V_147 . V_158 |=
F_2 ( V_160 ) ;
else
V_166 -> V_147 . V_158 |=
F_2 ( V_161 ) ;
}
} else if ( V_168 -> V_162 == V_220 ) {
F_4 ( V_2 -> V_29 , V_36 , L_20 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_222 ) ;
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
if ( V_168 -> V_189 & V_197 )
V_166 -> V_147 . V_158 |=
F_2 ( V_160 ) ;
else
V_166 -> V_147 . V_158 |=
F_2 ( V_161 ) ;
}
if ( V_166 -> V_147 . V_156 ) {
V_166 -> V_147 . type =
F_2 ( V_155 ) ;
V_166 -> V_147 . V_162 =
F_2 ( ( T_1 ) V_168 -> V_162 ) ;
memcpy ( V_166 -> V_147 . V_163 , V_168 -> V_166 ,
V_168 -> V_162 ) ;
V_166 -> V_147 . V_60 =
F_2 ( ( T_1 ) V_168 -> V_162 +
V_231 ) ;
V_148 = ( T_1 ) ( V_168 -> V_162 + V_231 )
+ sizeof( struct V_61 ) ;
if ( F_7 ( V_166 -> V_147 . V_156 ) ==
V_184 ) {
struct V_232 * V_233 =
( void * ) V_166 -> V_147 . V_163 ;
memcpy ( V_233 -> V_179 , V_168 -> V_180 , V_234 ) ;
memcpy ( V_233 -> V_163 , V_168 -> V_166 ,
V_235 ) ;
V_148 = sizeof( struct V_232 ) ;
V_166 -> V_147 . V_162 =
F_2 ( V_148 ) ;
V_148 += V_231 ;
V_166 -> V_147 . V_60 =
F_2 ( V_148 ) ;
V_148 += sizeof( struct V_61 ) ;
}
V_4 -> V_8 = F_2 ( sizeof( V_166 -> V_13 ) + V_10
+ V_148 ) ;
if ( F_24 ( V_2 ) == V_202 ) {
V_226 = ( void * ) ( ( V_58 * ) & V_166 -> V_147 +
V_148 ) ;
V_226 -> V_236 . type =
F_2 ( V_237 ) ;
V_226 -> V_236 . V_171 = F_2 ( V_129 ) ;
memcpy ( V_226 -> V_127 , V_168 -> V_127 , V_129 ) ;
V_227 = V_148 + V_10 +
sizeof( V_166 -> V_13 ) +
sizeof( struct V_225 ) ;
} else {
V_227 = V_148 + V_10 +
sizeof( V_166 -> V_13 ) ;
}
V_4 -> V_8 = F_2 ( V_227 ) ;
}
return V_228 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_167 * V_168 )
{
if ( V_2 -> V_29 -> V_238 == V_239 )
return F_23 ( V_2 , V_4 ,
V_5 , V_31 ,
V_168 ) ;
else
return F_26 ( V_2 , V_4 ,
V_5 , V_31 ,
V_168 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
struct V_240 * V_241 =
& V_4 -> V_11 . V_241 ;
struct V_242 * V_243 =
& V_241 -> V_243 ;
V_58 V_244 = V_29 -> V_245 . V_244 ;
F_4 ( V_29 , V_174 ,
L_21 , V_244 ) ;
V_4 -> V_6 = F_2 ( V_246 ) ;
V_241 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_241 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_243 -> V_236 . type = F_2 ( V_247 ) ;
memcpy ( V_243 -> V_248 , V_29 -> V_245 . V_248 ,
sizeof( V_243 -> V_248 ) ) ;
V_243 -> V_236 . V_171 =
F_2 ( ( V_244 *
sizeof( struct V_249 ) )
+ sizeof( V_243 -> V_248 ) ) ;
if ( V_244 ) {
memcpy ( V_243 -> V_250 , V_29 -> V_245 . V_250 ,
V_244 * sizeof( struct
V_249 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_241 -> V_13 ) +
F_7 ( V_243 -> V_236 . V_171 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_241 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_251 )
{
struct V_252 * V_253 =
& ( V_4 -> V_11 . V_254 ) ;
V_4 -> V_6 = F_2 ( V_255 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_252 ) +
V_10 ) ;
V_4 -> V_126 = 0 ;
V_253 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_251 )
V_253 -> V_251 = F_2 ( * V_251 ) ;
else
V_253 -> V_251 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int
F_30 ( struct V_3 * V_4 , T_1 V_5 ,
void * V_256 )
{
struct V_257 * V_258 = ( void * ) V_256 ;
struct V_259 * V_260 = ( void * ) & V_4 -> V_11 . V_261 ;
V_4 -> V_6 = F_2 ( V_262 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_259 ) +
V_10 ) ;
V_260 -> V_13 = F_2 ( V_5 ) ;
V_260 -> V_263 = F_15 ( V_258 -> V_263 ) ;
V_260 -> V_44 = F_15 ( V_258 -> V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_264 * V_265 = V_79 ;
switch ( F_7 ( V_4 -> V_6 ) ) {
case V_266 :
{
struct V_267 * V_268 ;
V_4 -> V_8 = F_2 ( sizeof( * V_268 ) + V_10 ) ;
V_268 = & V_4 -> V_11 . V_268 ;
V_268 -> V_13 = F_2 ( V_5 ) ;
V_268 -> V_269 = F_2 ( ( T_1 ) V_265 -> V_269 ) ;
V_268 -> V_44 = F_15 ( V_265 -> V_44 ) ;
break;
}
case V_270 :
{
struct V_271 * V_272 ;
V_4 -> V_8 = F_2 ( sizeof( * V_272 ) + V_10 ) ;
V_272 = & V_4 -> V_11 . V_272 ;
V_272 -> V_13 = F_2 ( V_5 ) ;
V_272 -> V_269 = F_2 ( ( T_1 ) V_265 -> V_269 ) ;
V_272 -> V_44 = ( V_58 ) V_265 -> V_44 ;
break;
}
case V_273 :
{
struct V_274 * V_275 ;
V_4 -> V_8 = F_2 ( sizeof( * V_275 ) + V_10 ) ;
V_275 = & V_4 -> V_11 . V_275 ;
V_275 -> V_13 = F_2 ( V_5 ) ;
V_275 -> V_269 = F_2 ( ( T_1 ) V_265 -> V_269 ) ;
V_275 -> V_44 = ( V_58 ) V_265 -> V_44 ;
break;
}
case V_276 :
{
struct V_277 * V_278 ;
V_4 -> V_8 = F_2 ( sizeof( * V_278 ) + V_10 ) ;
V_278 = & V_4 -> V_11 . V_278 ;
V_278 -> V_13 = F_2 ( V_5 ) ;
V_278 -> V_269 = F_2 ( ( T_1 ) V_265 -> V_269 ) ;
V_278 -> V_44 = ( V_58 ) V_265 -> V_44 ;
break;
}
case V_279 :
{
struct V_274 * V_280 ;
V_4 -> V_8 = F_2 ( sizeof( * V_280 ) + V_10 ) ;
V_280 = & V_4 -> V_11 . V_275 ;
V_280 -> V_13 = F_2 ( V_5 ) ;
V_280 -> V_269 = F_2 ( ( T_1 ) V_265 -> V_269 ) ;
V_280 -> V_44 = ( V_58 ) V_265 -> V_44 ;
break;
}
case V_281 :
{
struct V_282 * V_283 = V_79 ;
struct V_284 * V_285 =
& V_4 -> V_11 . V_286 ;
V_4 -> V_8 = F_2 ( sizeof( * V_285 ) + V_10 ) ;
V_285 -> V_13 = F_2 ( V_5 ) ;
V_285 -> V_269 = F_2 ( V_283 -> V_269 ) ;
V_285 -> V_287 = F_2 ( V_283 -> V_287 ) ;
V_285 -> V_44 = 0 ;
break;
}
default:
return - 1 ;
}
return 0 ;
}
static int
F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_13 )
{
struct V_288 * V_289 =
& V_4 -> V_11 . V_290 ;
struct V_291 * V_292 = V_2 -> V_29 -> V_292 ;
V_4 -> V_6 = F_2 ( V_293 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_288 ) + V_10 ) ;
V_4 -> V_126 = 0 ;
memset ( V_289 , 0 , sizeof( struct V_288 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_289 -> V_294 = F_15 ( ( T_2 ) ( V_292 -> V_295 ) ) ;
V_289 -> V_296 =
F_15 ( ( T_2 ) ( ( ( V_297 ) V_292 -> V_295 ) >> 32 ) ) ;
V_289 -> V_298 = F_15 ( V_299 ) ;
V_289 -> V_300 = F_15 ( ( T_2 ) ( V_292 -> V_301 ) ) ;
V_289 -> V_302 =
F_15 ( ( T_2 ) ( ( ( V_297 ) V_292 -> V_301 ) >> 32 ) ) ;
V_289 -> V_303 = F_15 ( V_299 ) ;
V_289 -> V_304 = F_15 ( ( T_2 ) ( V_292 -> V_305 ) ) ;
V_289 -> V_306 =
F_15 ( ( T_2 ) ( ( ( V_297 ) V_292 -> V_305 ) >> 32 ) ) ;
V_289 -> V_307 = F_15 ( V_308 ) ;
if ( V_292 -> V_309 ) {
V_289 -> V_310 =
F_15 ( ( T_2 ) ( V_292 -> V_311 ) ) ;
V_289 -> V_312 = F_15 ( ( T_2 ) ( ( ( V_297 )
( V_292 -> V_311 ) ) >> 32 ) ) ;
F_4 ( V_2 -> V_29 , V_174 ,
L_22 ,
V_289 -> V_310 ) ;
}
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_313 * V_314 )
{
struct V_315 * V_316 = & V_4 -> V_11 . V_316 ;
struct V_317 * V_318 ;
T_1 V_319 ;
V_58 * V_320 ;
V_4 -> V_6 = F_2 ( V_321 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_315 ) +
V_10 ) ;
V_316 -> V_13 = F_2 ( V_314 -> V_13 ) ;
F_4 ( V_2 -> V_29 , V_36 ,
L_23 , V_314 -> V_13 ) ;
if ( V_314 -> V_13 == V_39 )
return 0 ;
V_316 -> V_322 = F_2 ( V_314 -> V_322 ) ;
V_319 = V_314 -> V_322 ;
F_4 ( V_2 -> V_29 , V_36 , L_24 ,
V_319 ) ;
if ( ( ( V_314 -> V_13 == V_323 ) ||
( V_314 -> V_13 == V_324 ) ) &&
( V_319 == 0 ) ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_25
L_26 ) ;
return - V_325 ;
}
if ( V_314 -> V_13 == V_323 )
return 0 ;
V_320 = ( ( V_58 * ) V_316 ) +
sizeof( struct V_315 ) ;
if ( V_319 & V_326 ) {
V_318 = (struct V_317 * ) V_320 ;
V_318 -> V_236 . type = F_2 ( V_327 ) ;
V_318 -> V_236 . V_171 =
F_2 ( sizeof( struct V_317 ) -
sizeof( struct V_61 ) ) ;
V_318 -> V_328 = V_314 -> V_329 . V_328 ;
V_318 -> V_330 = V_314 -> V_329 . V_330 ;
F_4 ( V_2 -> V_29 , V_331 ,
L_27
L_28 ,
V_314 -> V_329 . V_328 ,
V_314 -> V_329 . V_330 ) ;
V_320 += sizeof( struct V_317 ) ;
F_6 ( & V_4 -> V_8 ,
sizeof( struct V_317 ) ) ;
}
if ( V_319 & V_332 ) {
V_318 = (struct V_317 * ) V_320 ;
V_318 -> V_236 . type = F_2 ( V_333 ) ;
V_318 -> V_236 . V_171 =
F_2 ( sizeof( struct V_317 ) -
sizeof( struct V_61 ) ) ;
V_318 -> V_328 = V_314 -> V_334 . V_328 ;
V_318 -> V_330 = V_314 -> V_334 . V_330 ;
F_4 ( V_2 -> V_29 , V_331 ,
L_29
L_28 ,
V_314 -> V_334 . V_328 ,
V_314 -> V_334 . V_330 ) ;
V_320 += sizeof( struct V_317 ) ;
F_6 ( & V_4 -> V_8 ,
sizeof( struct V_317 ) ) ;
}
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_335 * V_336 ,
V_58 * * V_337 )
{
struct V_338 * V_339 = V_336 -> V_339 ;
int V_55 , V_340 ;
V_58 * V_341 = * V_337 ;
for ( V_55 = 0 ; V_55 < V_342 ; V_55 ++ ) {
V_339 = & V_336 -> V_339 [ V_55 ] ;
if ( ! V_339 -> V_343 )
break;
* ( V_344 * ) V_341 = F_15 ( ( T_2 ) V_339 -> V_345 ) ;
V_341 += 4 ;
* V_341 = V_346 ;
V_341 += 1 ;
V_340 = V_339 -> V_347 [ V_348 ] ;
memcpy ( V_341 , V_339 -> V_347 , V_340 ) ;
V_341 += V_340 ;
* V_341 = V_340 ;
V_341 += 1 ;
* V_341 = V_349 ;
V_341 += 1 ;
* ( V_344 * ) V_341 = F_15 ( ( T_2 ) V_339 -> V_269 ) ;
V_341 += 4 ;
* V_341 = V_346 ;
V_341 += 1 ;
* V_341 = V_339 -> V_343 ;
V_341 += 1 ;
if ( V_339 -> V_350 ) {
* V_341 = V_339 -> V_350 ;
V_341 += 1 ;
}
if ( V_341 - * V_337 > V_351 )
return - 1 ;
}
* V_337 = V_341 ;
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_352 * V_353 )
{
struct V_354 * V_355 = & V_4 -> V_11 . V_355 ;
struct V_356 * V_336 = NULL ;
V_58 * V_320 = ( V_58 * ) V_355 ;
T_1 V_55 ;
V_4 -> V_6 = F_2 ( V_357 ) ;
V_355 -> V_358 = F_15 ( V_353 -> V_358 ) ;
V_355 -> V_359 = F_2 ( V_353 -> V_359 ) ;
V_320 += sizeof( * V_355 ) ;
for ( V_55 = 0 ; V_55 < V_353 -> V_359 ; V_55 ++ ) {
V_336 = (struct V_356 * ) V_320 ;
V_336 -> V_78 = V_353 -> V_336 [ V_55 ] . V_78 ;
V_336 -> V_13 = V_353 -> V_336 [ V_55 ] . V_13 ;
V_320 += sizeof( * V_355 -> V_336 ) ;
if ( F_34 ( V_2 ,
& V_353 -> V_336 [ V_55 ] , & V_320 ) )
return - 1 ;
V_336 -> V_360 =
F_2 ( V_320 - V_336 -> V_361 ) ;
}
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_320 - ( V_58 * ) V_355 ) + V_10 ) ;
return 0 ;
}
static T_2 F_36 ( V_58 * V_362 , T_3 V_171 , V_58 * V_363 )
{
V_58 * V_364 = V_362 , * V_365 = V_363 ;
while ( V_364 - V_362 < V_171 ) {
if ( * V_364 && ( isspace ( * V_364 ) || * V_364 == '\t' ) ) {
V_364 ++ ;
continue;
}
if ( isxdigit ( * V_364 ) ) {
* V_365 ++ = F_37 ( V_364 , NULL , 16 ) ;
V_364 += 2 ;
} else {
V_364 ++ ;
}
}
return V_365 - V_363 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_366 * V_367 , const char * V_368 )
{
#ifdef F_39
struct V_369 * V_370 ;
T_3 V_171 = strlen ( V_368 ) ;
int V_228 ;
F_40 (node, prop) {
if ( V_171 > strlen ( V_370 -> V_371 ) ||
strncmp ( V_370 -> V_371 , V_368 , V_171 ) )
continue;
if ( V_370 -> V_44 && V_370 -> V_60 > 6 &&
V_370 -> V_60 <= V_372 - V_10 ) {
V_228 = F_41 ( V_2 , V_373 ,
V_28 , 0 ,
V_370 , true ) ;
if ( V_228 )
return V_228 ;
}
}
#endif
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_79 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
struct V_369 * V_370 = V_79 ;
T_2 V_171 ;
V_58 * V_374 = ( V_58 * ) V_4 + V_10 ;
int V_228 ;
if ( V_370 ) {
V_171 = V_370 -> V_60 ;
V_228 = F_43 ( V_29 -> V_375 , V_370 -> V_371 ,
V_374 , V_171 ) ;
if ( V_228 )
return V_228 ;
F_4 ( V_29 , V_174 ,
L_30 ,
V_370 -> V_371 ) ;
} else if ( V_29 -> V_376 -> V_374 && V_29 -> V_376 -> V_8 > 0 ) {
V_171 = F_36 ( ( V_58 * ) V_29 -> V_376 -> V_374 ,
V_29 -> V_376 -> V_8 , V_374 ) ;
F_4 ( V_29 , V_174 ,
L_31 ) ;
} else {
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_373 ) ;
V_4 -> V_8 = F_2 ( V_10 + V_171 ) ;
return 0 ;
}
static int
F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_377 * V_378 = & V_4 -> V_11 . V_379 ;
const T_1 * V_380 = V_79 ;
V_378 -> V_13 = F_2 ( V_5 ) ;
V_378 -> V_381 = F_2 ( * V_380 ) ;
V_4 -> V_6 = F_2 ( V_382 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_377 ) +
V_10 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , bool * V_383 )
{
struct V_384 * V_385 = & V_4 -> V_11 . V_385 ;
struct V_386 * V_387 ;
V_4 -> V_6 = F_2 ( V_388 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_385 ) + sizeof( * V_387 ) + V_10 ) ;
V_385 -> V_13 = F_2 ( V_5 ) ;
V_387 = (struct V_386 * )
( ( V_58 * ) V_385 + sizeof( * V_385 ) ) ;
V_387 -> V_236 . type = F_2 ( V_389 ) ;
V_387 -> V_236 . V_171 = F_2 ( sizeof( V_387 -> V_78 ) ) ;
if ( V_385 -> V_13 == V_39 )
return 0 ;
if ( * V_383 )
V_387 -> V_78 = F_15 ( V_390 ) ;
else
V_387 -> V_78 = F_15 ( V_391 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_392 * V_374 )
{
struct V_393 * V_394 = & V_4 -> V_11 . V_394 ;
V_297 V_395 ;
V_4 -> V_6 = F_2 ( V_396 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_394 ) + V_10 ) ;
V_394 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 ) {
memcpy ( V_394 -> V_397 , V_374 -> V_397 , V_398 ) ;
memcpy ( V_394 -> V_399 , V_374 -> V_399 , V_400 ) ;
V_395 = F_47 ( ( V_401 * ) V_374 -> V_402 ) ;
V_394 -> V_403 = F_15 ( ( T_2 ) V_395 ) ;
V_394 -> V_404 =
F_15 ( ( T_2 ) ( ( V_297 ) V_395 >> 32 ) ) ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_405 * V_406 = & V_4 -> V_11 . V_407 ;
V_4 -> V_6 = F_2 ( V_408 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_406 ) + V_10 ) ;
if ( V_5 == V_39 )
V_406 -> V_13 = F_2 ( V_5 ) ;
return 0 ;
}
static int
F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_409 * V_410 =
& V_4 -> V_11 . V_410 ;
struct V_411 * V_412 = V_79 ;
struct V_413 * V_233 ;
T_1 V_414 , V_415 , V_60 ;
struct V_416 * V_417 ;
V_4 -> V_6 = F_2 ( V_418 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_410 -> V_13 = F_2 ( V_5 ) ;
V_410 -> V_419 = F_2 ( V_412 -> V_419 ) ;
V_417 = V_410 -> V_417 ;
for ( V_414 = 0 ; V_414 < V_412 -> V_419 ; V_414 ++ ) {
V_417 -> V_236 . type = F_2 ( V_420 ) ;
V_417 -> V_421 =
F_2 ( V_412 -> V_417 [ V_414 ] . V_421 ) ;
V_417 -> V_422 = V_412 -> V_417 [ V_414 ] . V_422 ;
V_417 -> V_423 = V_412 -> V_417 [ V_414 ] . V_423 ;
V_60 = 0 ;
V_233 = V_417 -> V_11 ;
for ( V_415 = 0 ; V_415 < V_412 -> V_417 [ V_414 ] . V_423 ; V_415 ++ ) {
V_233 -> V_424 = V_412 -> V_417 [ V_414 ] . V_11 [ V_415 ] . V_424 ;
V_233 -> V_425 =
V_412 -> V_417 [ V_414 ] . V_11 [ V_415 ] . V_425 ;
V_233 -> V_269 =
F_2 ( V_412 -> V_417 [ V_414 ] . V_11 [ V_415 ] . V_269 ) ;
memcpy ( V_233 -> V_426 ,
V_412 -> V_417 [ V_414 ] . V_11 [ V_415 ] . V_426 ,
V_233 -> V_425 ) ;
V_60 += sizeof( struct V_413 ) ;
V_233 ++ ;
}
V_417 -> V_236 . V_171 = F_2 ( V_60 + sizeof( T_1 ) +
sizeof( V_58 ) + sizeof( V_58 ) ) ;
F_6 ( & V_4 -> V_8 , F_7 ( V_417 -> V_236 . V_171 ) +
sizeof( struct V_61 ) ) ;
V_417 = ( void * ) ( ( V_58 * ) V_417 -> V_11 + V_60 ) ;
}
F_6 ( & V_4 -> V_8 , sizeof( T_1 ) + sizeof( T_1 ) ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_427 * V_428 = & V_4 -> V_11 . V_428 ;
struct V_429 * V_430 ;
struct V_431 * V_432 ;
T_1 V_171 ;
V_4 -> V_6 = F_2 ( V_433 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_428 -> V_434 = F_2 ( V_5 ) ;
F_6 ( & V_4 -> V_8 , sizeof( V_428 -> V_434 ) ) ;
switch ( V_5 ) {
case V_435 :
V_432 = V_79 ;
V_171 = sizeof( * V_432 ) ;
memcpy ( V_428 -> V_436 , V_432 , V_171 ) ;
break;
case V_437 :
V_430 = V_79 ;
V_171 = sizeof( * V_430 ) ;
memcpy ( V_428 -> V_436 , V_430 , V_171 ) ;
break;
case V_438 :
V_171 = sizeof( struct V_439 ) ;
memcpy ( V_428 -> V_436 , V_79 , V_171 ) ;
break;
case V_440 :
V_171 = sizeof( struct V_441 ) ;
memcpy ( V_428 -> V_436 , V_79 , V_171 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_32 ) ;
return - V_442 ;
}
F_6 ( & V_4 -> V_8 , V_171 ) ;
return 0 ;
}
static int
F_51 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_79 )
{
struct V_443 * V_444 = & V_4 -> V_11 . V_444 ;
struct V_445 * V_446 = V_79 ;
struct V_447 * V_448 ;
struct V_449 * V_450 ;
struct V_451 * V_452 ;
struct V_453 * V_454 ;
struct V_455 * V_456 ;
struct V_457 * V_458 ;
struct V_459 * V_460 ;
struct V_461 * V_462 ;
V_58 * V_320 , V_463 ;
T_1 V_464 = 0 ;
struct V_465 * V_11 = V_2 -> V_466 ;
V_4 -> V_6 = F_2 ( V_467 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
F_6 ( & V_4 -> V_8 , sizeof( struct V_443 ) ) ;
V_444 -> V_468 = 0 ;
memcpy ( V_444 -> V_469 , V_446 -> V_469 , V_129 ) ;
V_448 = F_52 ( V_2 , V_446 -> V_469 ) ;
V_320 = ( V_58 * ) V_444 + sizeof( struct V_443 ) ;
switch ( V_446 -> V_434 ) {
case V_470 :
V_444 -> V_434 = F_2 ( V_471 ) ;
break;
case V_472 :
V_444 -> V_434 = F_2 ( V_473 ) ;
break;
case V_474 :
V_444 -> V_434 = F_2 ( V_475 ) ;
if ( ! V_11 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_33 ,
V_446 -> V_469 ) ;
return - V_476 ;
}
* ( V_43 * ) V_320 = F_2 ( V_11 -> V_477 ) ;
V_464 += sizeof( V_11 -> V_477 ) ;
V_463 = V_11 -> V_478 | ( V_11 -> V_479 << 5 ) ;
V_454 = (struct V_453 * ) ( V_320 +
V_464 ) ;
V_454 -> V_236 . type = F_2 ( V_480 ) ;
V_454 -> V_236 . V_171 = F_2 ( sizeof( V_463 ) ) ;
V_454 -> V_463 = V_463 ;
V_464 += sizeof( struct V_453 ) ;
if ( V_11 -> V_481 ) {
V_452 = (struct V_451 * ) ( V_320 +
V_464 ) ;
V_452 -> V_236 . type =
F_2 ( V_482 ) ;
V_452 -> V_236 . V_171 =
F_2 ( sizeof( struct V_483 ) ) ;
memcpy ( & V_452 -> V_484 , V_11 -> V_481 ,
sizeof( struct V_483 ) ) ;
V_464 += sizeof( struct V_451 ) ;
}
if ( V_11 -> V_485 && V_11 -> V_486 ) {
V_450 = (struct V_449 * ) ( V_320 +
V_464 ) ;
V_450 -> V_236 . type =
F_2 ( V_487 ) ;
V_450 -> V_236 . V_171 =
F_2 ( V_11 -> V_486 ) ;
memcpy ( V_450 -> V_488 , V_11 -> V_485 ,
V_11 -> V_486 ) ;
V_464 += sizeof( struct V_449 ) +
V_11 -> V_486 ;
}
if ( V_11 -> V_489 && V_11 -> V_490 ) {
V_456 = (struct V_455 * ) ( V_320 +
V_464 ) ;
V_456 -> V_236 . type =
F_2 ( V_491 ) ;
V_456 -> V_236 . V_171 = F_2 ( V_11 -> V_490 ) ;
memcpy ( V_456 -> V_489 , V_11 -> V_489 ,
V_11 -> V_490 ) ;
V_464 += sizeof( struct V_455 ) +
V_11 -> V_490 ;
}
if ( V_11 -> V_492 ) {
V_458 = (struct V_457 * ) ( V_320 +
V_464 ) ;
V_458 -> V_236 . type =
F_2 ( V_493 ) ;
V_458 -> V_236 . V_171 =
F_2 ( sizeof( struct V_494 ) ) ;
memcpy ( & V_458 -> V_495 , V_11 -> V_492 ,
sizeof( struct V_494 ) ) ;
V_464 += sizeof( struct V_457 ) ;
}
if ( V_11 -> V_460 ) {
V_460 = (struct V_459 * ) ( V_320 + V_464 ) ;
V_460 -> V_236 . type = F_2 ( V_496 ) ;
V_460 -> V_236 . V_171 = F_2 ( sizeof( V_11 -> V_460 ) ) ;
V_460 -> V_460 = F_2 ( V_11 -> V_460 ) ;
V_464 += sizeof( struct V_459 ) ;
}
V_462 = ( void * ) ( V_320 + V_464 ) ;
V_462 -> V_236 . type = F_2 ( V_497 ) ;
V_462 -> V_236 . V_171 = F_2 ( sizeof( V_462 -> V_44 ) ) ;
V_462 -> V_44 = F_2 ( V_498 ) ;
V_464 += sizeof( struct V_461 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR , L_34 ) ;
return - V_442 ;
}
F_6 ( & V_4 -> V_8 , V_464 ) ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_499 * V_412 =
& V_4 -> V_11 . V_500 ;
V_4 -> V_6 = F_2 ( V_501 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_499 ) +
V_10 ) ;
V_412 -> V_13 = V_5 ;
if ( V_5 == V_28 )
V_412 -> V_251 = * ( V_58 * ) V_79 ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_502 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_503 ) +
V_10 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 , T_4 V_504 ,
T_1 V_5 , T_2 V_31 ,
void * V_79 , void * V_505 )
{
struct V_3 * V_506 = V_505 ;
int V_228 = 0 ;
switch ( V_504 ) {
case V_507 :
V_228 = F_56 ( V_2 , V_506 ) ;
break;
case V_373 :
V_228 = F_42 ( V_2 , V_506 , V_79 ) ;
break;
case V_30 :
V_228 = F_3 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_124 :
V_228 = F_16 ( V_2 , V_506 ,
V_5 ) ;
break;
case V_135 :
V_228 = F_17 ( V_506 , V_5 ,
V_79 ) ;
break;
case V_56 :
V_228 = F_9 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_77 :
V_228 = F_11 ( V_506 , V_5 ,
V_79 ) ;
break;
case V_81 :
V_228 = F_12 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_88 :
V_228 = F_13 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_508 :
V_228 = F_57 ( V_2 , V_506 , V_5 ,
( T_4 ) V_31 , V_79 ) ;
break;
case V_111 :
V_228 = F_14 ( V_2 , V_506 , V_5 ,
(struct V_104 * ) V_79 ) ;
break;
case V_509 :
V_228 = F_58 ( V_506 , V_79 ) ;
break;
case V_510 :
V_228 = F_59 ( V_2 , V_506 ,
V_79 ) ;
break;
case V_511 :
V_228 = F_60 ( V_506 ) ;
break;
case V_512 :
V_228 = F_61 ( V_2 , V_506 , V_79 ) ;
break;
case V_142 :
V_228 = F_18 ( V_2 , V_506 ,
V_79 ) ;
break;
case V_513 :
V_228 = F_62 ( V_2 , V_506 ,
V_79 ) ;
break;
case V_45 :
V_228 = F_8 ( V_506 ) ;
break;
case V_514 :
V_228 = F_63 ( V_2 , V_506 ,
V_79 ) ;
break;
case V_145 :
V_228 = F_19 ( V_506 ) ;
break;
case V_7 :
V_228 = F_1 ( V_2 , V_506 , V_5 ) ;
break;
case V_37 :
V_228 = F_5 ( V_2 , V_506 , V_5 ,
V_31 , V_79 ) ;
break;
case V_515 :
V_506 -> V_6 =
F_2 ( V_515 ) ;
V_506 -> V_8 =
F_2 ( sizeof( struct V_516 ) +
V_10 ) ;
V_2 -> V_517 = 0 ;
V_228 = 0 ;
break;
case V_518 :
V_506 -> V_6 = F_2 ( V_504 ) ;
V_506 -> V_11 . V_519 . V_520 =
( V_58 ) ( * ( ( T_2 * ) V_79 ) ) ;
memcpy ( & V_506 -> V_11 , V_79 ,
sizeof( struct V_521 ) ) ;
V_506 -> V_8 =
F_2 ( sizeof( struct V_521 ) +
V_10 ) ;
V_228 = 0 ;
break;
case V_522 :
V_506 -> V_6 = F_2 ( V_504 ) ;
V_506 -> V_11 . V_523 . V_13 = F_2 ( V_5 ) ;
V_506 -> V_11 . V_523 . V_524 = F_15 ( * ( T_2 * ) V_79 ) ;
V_506 -> V_8 =
F_2 ( sizeof( struct V_525 ) +
V_10 ) ;
V_228 = 0 ;
break;
case V_526 :
V_506 -> V_6 = F_2 ( V_504 ) ;
memcpy ( & V_506 -> V_11 , V_79 ,
sizeof( struct V_527 ) ) ;
V_506 -> V_8 =
F_2 ( sizeof( struct V_527 ) +
V_10 ) ;
break;
case V_528 :
V_228 = F_64 ( V_2 , V_506 , V_5 , V_79 ) ;
break;
case V_529 :
V_506 -> V_6 = F_2 ( V_504 ) ;
V_506 -> V_11 . V_530 . V_13 = F_2 ( V_5 ) ;
V_506 -> V_11 . V_530 . V_78 = F_2 ( * ( T_1 * ) V_79 ) ;
V_506 -> V_8 =
F_2 ( sizeof( struct V_531 ) +
V_10 ) ;
break;
case V_532 :
if ( V_2 -> V_29 -> V_533 == V_534 )
V_2 -> V_29 -> V_533 = V_535 ;
V_506 -> V_6 = F_2 ( V_504 ) ;
V_506 -> V_8 = F_2 ( V_10 ) ;
break;
case V_536 :
V_2 -> V_29 -> V_533 = V_534 ;
V_506 -> V_6 = F_2 ( V_504 ) ;
V_506 -> V_8 = F_2 ( V_10 ) ;
break;
case V_537 :
V_228 = F_65 ( V_506 , V_79 ) ;
break;
case V_538 :
V_228 = F_66 ( V_506 , V_79 ) ;
break;
case V_539 :
V_228 = F_67 ( V_2 , V_506 , V_79 ) ;
break;
case V_195 :
V_228 = F_27 ( V_2 , V_506 ,
V_5 , V_31 ,
V_79 ) ;
break;
case V_246 :
V_228 = F_28 ( V_2 , V_506 ,
V_5 ) ;
break;
case V_540 :
V_228 = F_68 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_541 :
V_228 = F_69 ( V_506 , V_5 ,
V_79 ) ;
break;
case V_542 :
V_228 = F_70 ( V_2 , V_506 , V_5 , V_79 ) ;
break;
case V_543 :
F_4 ( V_2 -> V_29 , V_36 ,
L_35 ) ;
V_506 -> V_6 = F_2 ( V_543 ) ;
V_506 -> V_8 =
F_2 ( sizeof( struct V_544 ) +
V_10 ) ;
V_228 = 0 ;
break;
case V_255 :
V_228 = F_29 ( V_506 , V_5 ,
V_79 ) ;
break;
case V_545 :
V_228 = F_71 ( V_2 , V_506 , V_79 ) ;
break;
case V_262 :
V_228 = F_30 ( V_506 , V_5 , V_79 ) ;
break;
case V_266 :
case V_270 :
case V_273 :
case V_276 :
case V_279 :
case V_281 :
V_228 = F_31 ( V_506 , V_5 , V_79 ) ;
break;
case V_546 :
V_506 -> V_6 = F_2 ( V_504 ) ;
if ( V_2 -> V_215 == V_216 )
V_506 -> V_11 . V_215 . V_547 =
V_548 ;
else if ( V_2 -> V_215 == V_549 ||
V_2 -> V_215 == V_550 )
V_506 -> V_11 . V_215 . V_547 =
V_551 ;
else if ( V_2 -> V_215 == V_552 ||
V_2 -> V_215 == V_553 )
V_506 -> V_11 . V_215 . V_547 = V_554 ;
V_506 -> V_8 = F_2 ( sizeof( struct
V_555 ) + V_10 ) ;
V_228 = 0 ;
break;
case V_293 :
V_228 = F_32 ( V_2 , V_506 , V_5 ) ;
break;
case V_321 :
V_228 = F_33 ( V_2 , V_506 , V_79 ) ;
break;
case V_357 :
V_228 = F_35 ( V_2 , V_506 , V_79 ) ;
break;
case V_418 :
V_228 = F_49 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_467 :
V_228 = F_51 ( V_2 , V_506 , V_79 ) ;
break;
case V_433 :
V_228 = F_50 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_556 :
V_228 = F_72 ( V_2 , V_506 ,
V_79 ) ;
break;
case V_501 :
V_228 = F_53 ( V_506 , V_5 ,
V_79 ) ;
break;
case V_502 :
V_228 = F_54 ( V_2 , V_506 ) ;
break;
case V_382 :
V_228 = F_44 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_388 :
V_228 = F_45 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_396 :
V_228 = F_46 ( V_2 , V_506 , V_5 ,
V_79 ) ;
break;
case V_408 :
V_228 = F_48 ( V_2 , V_506 , V_5 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_36 , V_504 ) ;
V_228 = - 1 ;
break;
}
return V_228 ;
}
int F_73 ( struct V_1 * V_2 , V_58 V_557 , bool V_558 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
int V_228 ;
T_1 V_251 = true ;
struct V_559 V_560 ;
struct V_561 V_562 ;
enum V_563 V_564 ;
struct V_565 V_566 ;
V_58 V_567 ;
int V_374 ;
if ( V_557 ) {
if ( V_2 -> V_29 -> V_568 == V_569 ) {
V_228 = F_41 ( V_2 ,
V_293 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_228 )
return - 1 ;
}
V_228 = F_41 ( V_2 , V_532 ,
V_28 , 0 , NULL , true ) ;
if ( V_228 )
return - 1 ;
if ( V_2 -> V_29 -> V_568 == V_570 &&
V_29 -> V_571 -> V_572 ) {
V_29 -> V_375 = V_29 -> V_571 -> V_572 ;
if ( F_74 ( V_29 -> V_375 ,
L_37 ,
& V_374 ) == 0 ) {
F_75 ( L_38 , V_374 ) ;
V_29 -> V_108 . V_122 = V_374 ;
}
V_228 = F_38 ( V_2 , V_29 -> V_375 ,
L_39 ) ;
if ( V_228 )
return - 1 ;
}
if ( V_29 -> V_376 ) {
V_228 = F_41 ( V_2 , V_373 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_228 )
return - 1 ;
}
V_228 = F_41 ( V_2 , V_507 ,
V_39 , 0 , NULL , true ) ;
if ( V_228 )
return - 1 ;
if ( V_2 -> V_29 -> V_568 == V_570 &&
F_76 ( V_2 -> V_29 -> V_573 ) &&
! V_2 -> V_29 -> V_574 ) {
V_567 = true ;
V_228 = F_41 ( V_2 ,
V_501 ,
V_28 , 0 ,
& V_567 ,
true ) ;
if ( V_228 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_40 ) ;
V_29 -> V_575 = false ;
}
}
V_228 = F_41 ( V_2 , V_540 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_576 , true ) ;
if ( V_228 )
return - 1 ;
if ( V_2 -> V_577 != V_578 ) {
V_2 -> V_29 -> V_579 = V_580 ;
V_228 = F_41 ( V_2 ,
V_508 ,
V_581 , V_582 , NULL ,
true ) ;
if ( V_228 )
return - 1 ;
}
if ( V_583 ) {
V_29 -> V_584 = true ;
if ( F_77 ( V_29 -> V_573 ) )
V_228 = F_41 ( V_2 ,
V_382 ,
V_28 , 0 ,
& V_29 -> V_584 ,
true ) ;
if ( V_228 )
return - 1 ;
}
F_41 ( V_2 , V_408 ,
V_39 , 0 , NULL , true ) ;
}
V_228 = F_41 ( V_2 , V_56 ,
V_39 , 0 , NULL , true ) ;
if ( V_228 )
return - 1 ;
V_2 -> V_585 = 0 ;
V_228 = F_41 ( V_2 , V_81 ,
V_39 , 0 , NULL , true ) ;
if ( V_228 )
return - 1 ;
if ( V_2 -> V_577 == V_586 ) {
V_228 = F_41 (
V_2 ,
V_255 ,
V_28 , 0 , & V_251 , true ) ;
if ( V_228 )
return - 1 ;
}
memset ( & V_560 , 0 , sizeof( V_560 ) ) ;
V_560 . V_251 = true ;
V_228 = F_41 ( V_2 , V_541 ,
V_28 , 0 ,
& V_560 , true ) ;
if ( V_228 )
return - 1 ;
V_228 = F_41 ( V_2 , V_30 ,
V_28 , 0 ,
& V_2 -> V_587 , true ) ;
if ( V_228 )
return - 1 ;
if ( ! V_588 &&
V_557 && V_2 -> V_29 -> V_568 != V_589 &&
V_2 -> V_577 != V_578 ) {
V_562 . V_562 = V_590 ;
V_562 . V_591 = V_592 ;
V_228 = F_41 ( V_2 , V_508 ,
V_581 , V_593 ,
& V_562 , true ) ;
if ( V_228 )
return - 1 ;
}
if ( V_2 -> V_577 != V_578 ) {
V_564 = V_594 ;
V_228 = F_41 ( V_2 , V_37 ,
V_28 , V_595 ,
& V_564 , true ) ;
if ( V_228 )
F_4 ( V_2 -> V_29 , ERROR ,
L_41 ) ;
}
V_566 . V_596 = V_597 ;
V_228 = F_41 ( V_2 , V_542 ,
V_28 , 0 , & V_566 , true ) ;
if ( V_558 ) {
V_2 -> V_29 -> V_598 = V_542 ;
V_228 = - V_599 ;
}
return V_228 ;
}
