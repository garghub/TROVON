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
} else {
F_4 ( V_29 , V_174 ,
L_10 , V_175 ) ;
if ( V_168 -> V_176 )
memcpy ( V_170 -> V_147 . V_177 . V_186 . V_180 ,
V_168 -> V_180 , V_168 -> V_181 ) ;
V_170 -> V_147 . V_183 = V_187 ;
V_170 -> V_147 . V_177 . V_186 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_186 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
V_171 += sizeof( struct V_188 ) ;
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
& V_4 -> V_11 . V_189 ;
V_4 -> V_6 = F_2 ( V_190 ) ;
V_170 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
F_4 ( V_29 , V_174 , L_11 , V_175 ) ;
V_170 -> V_147 . V_191 =
V_168 -> V_192 & V_193 ;
V_170 -> V_147 . type = F_2 ( V_194 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_172 ) ;
memcpy ( V_170 -> V_147 . V_127 , V_139 , V_129 ) ;
if ( V_168 -> V_192 & V_195 )
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
sizeof( struct V_196 ) ) ;
if ( V_168 -> V_197 ) {
F_4 ( V_29 , V_174 , L_12 , V_175 ) ;
V_170 -> V_13 = F_2 ( V_198 ) ;
V_170 -> V_147 . type = F_2 ( V_194 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_172 ) ;
V_170 -> V_147 . V_191 = V_168 -> V_192 & V_193 ;
V_158 = V_161 | V_160 ;
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
memcpy ( V_170 -> V_147 . V_127 , V_139 , V_129 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_10 + V_172 +
sizeof( V_170 -> V_13 ) ) ;
return 0 ;
}
V_170 -> V_13 = F_2 ( V_28 ) ;
V_170 -> V_147 . V_191 = V_168 -> V_192 & V_193 ;
V_170 -> V_147 . type = F_2 ( V_194 ) ;
V_158 = V_159 ;
memcpy ( V_170 -> V_147 . V_127 , V_139 , V_129 ) ;
if ( V_168 -> V_162 <= V_154 ) {
F_4 ( V_29 , V_174 , L_13 , V_175 ) ;
V_171 += sizeof( struct V_199 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_171 ) ;
V_170 -> V_147 . V_183 = V_157 ;
if ( F_24 ( V_2 ) == V_200 ) {
V_158 |= V_161 | V_160 ;
} else {
if ( V_168 -> V_201 ) {
V_158 |= V_161 | V_160 ;
if ( V_170 -> V_147 . V_191 ==
( V_2 -> V_164 & V_193 ) )
V_158 |= V_202 ;
} else {
if ( V_139 ) {
if ( F_25 ( V_139 ) )
V_158 |= V_161 ;
else
V_158 |= V_160 |
V_202 ;
} else {
V_158 |= V_161 ;
}
}
}
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
V_170 -> V_147 . V_177 . V_203 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_203 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_171 + sizeof( V_170 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( F_25 ( V_139 ) )
V_158 |= V_161 | V_204 ;
else
V_158 |= V_160 | V_205 | V_204 ;
if ( V_168 -> V_206 ) {
F_4 ( V_29 , V_174 , L_14 , V_175 ) ;
V_170 -> V_147 . V_183 = V_207 ;
memcpy ( V_170 -> V_147 . V_177 . V_208 . V_180 , V_168 -> V_180 ,
V_209 ) ;
V_170 -> V_147 . V_177 . V_208 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_208 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
if ( F_25 ( V_139 ) )
V_2 -> V_210 . V_211 = true ;
if ( ! V_2 -> V_210 . V_211 )
V_158 |= V_202 ;
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
V_171 += sizeof( struct V_212 ) ;
V_170 -> V_147 . V_171 = F_2 ( V_171 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_61 ) +
V_171 + sizeof( V_170 -> V_13 ) + V_10 ) ;
return 0 ;
}
if ( V_2 -> V_213 == V_214 ) {
V_158 |= V_202 ;
if ( ! V_2 -> V_210 . V_215 &&
! F_25 ( V_139 ) )
V_158 |= V_160 ;
} else {
if ( ! V_2 -> V_216 )
V_158 |= V_202 ;
}
V_170 -> V_147 . V_158 = F_2 ( V_158 ) ;
if ( V_168 -> V_162 == V_217 )
return F_22 ( V_2 , V_4 , V_168 , V_170 ) ;
if ( V_168 -> V_162 == V_218 ) {
F_4 ( V_29 , V_174 ,
L_15 , V_175 ) ;
if ( V_168 -> V_176 )
memcpy ( V_170 -> V_147 . V_177 . V_219 . V_180 ,
V_168 -> V_180 , V_168 -> V_181 ) ;
V_170 -> V_147 . V_183 = V_220 ;
V_170 -> V_147 . V_177 . V_219 . V_162 =
F_2 ( V_168 -> V_162 ) ;
memcpy ( V_170 -> V_147 . V_177 . V_219 . V_163 ,
V_168 -> V_166 , V_168 -> V_162 ) ;
V_171 += sizeof( struct V_221 ) ;
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
struct V_222 * V_166 =
& V_4 -> V_11 . V_166 ;
struct V_223 * V_224 ;
T_1 V_148 = 0 , V_225 ;
int V_226 = 0 ;
V_4 -> V_6 = F_2 ( V_190 ) ;
V_166 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 =
F_2 ( sizeof( V_166 -> V_13 ) + V_10 ) ;
return V_226 ;
}
if ( ! V_168 ) {
memset ( & V_166 -> V_147 , 0 ,
( V_150 *
sizeof( struct V_146 ) ) ) ;
V_226 = F_20 ( V_2 ,
& V_166 -> V_147 ,
& V_148 ) ;
V_4 -> V_8 = F_2 ( V_148 +
sizeof( V_166 -> V_13 ) + V_10 ) ;
return V_226 ;
} else
memset ( & V_166 -> V_147 , 0 ,
sizeof( struct V_146 ) ) ;
if ( V_168 -> V_206 ) {
F_4 ( V_2 -> V_29 , V_174 , L_16 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_207 ) ;
if ( V_31 == V_227 )
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
else
V_166 -> V_147 . V_158 =
F_2 ( ! V_159 ) ;
V_166 -> V_147 . V_163 [ 0 ] = V_168 -> V_192 ;
if ( ! V_2 -> V_210 . V_211 )
V_166 -> V_147 . V_163 [ 1 ] = 1 ;
else
V_166 -> V_147 . V_163 [ 1 ] = 0 ;
if ( ! F_25 ( V_168 -> V_127 ) ) {
V_166 -> V_147 . V_158 |=
F_2 ( V_160 ) ;
} else {
V_166 -> V_147 . V_158 |=
F_2 ( V_161 ) ;
V_2 -> V_210 . V_211 = true ;
}
V_166 -> V_147 . type =
F_2 ( V_155 ) ;
V_166 -> V_147 . V_162 =
F_2 ( V_228 ) ;
memcpy ( & V_166 -> V_147 . V_163 [ 2 ] ,
V_168 -> V_166 , V_168 -> V_162 ) ;
memcpy ( & V_166 -> V_147 . V_163 [ 2 + V_168 -> V_162 ] ,
V_168 -> V_180 , V_209 ) ;
V_166 -> V_147 . V_60 =
F_2 ( V_228 + V_229 ) ;
V_148 = ( V_228 + V_229 ) +
sizeof( struct V_61 ) ;
V_4 -> V_8 = F_2 ( sizeof( V_166 -> V_13 )
+ V_10 + V_148 ) ;
return V_226 ;
}
if ( V_168 -> V_162 == V_217 ) {
if ( V_168 -> V_173 ) {
F_4 ( V_2 -> V_29 , V_36 , L_17 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_184 ) ;
if ( V_31 == V_227 )
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
else
V_166 -> V_147 . V_158 =
F_2 ( ! V_159 ) ;
V_166 -> V_147 . V_158 |=
F_2 ( V_182 ) ;
} else {
F_4 ( V_2 -> V_29 , V_36 , L_18 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_187 ) ;
if ( V_31 == V_227 )
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
else
V_166 -> V_147 . V_158 =
F_2 ( ! V_159 ) ;
if ( V_168 -> V_192 & V_195 )
V_166 -> V_147 . V_158 |=
F_2 ( V_160 ) ;
else
V_166 -> V_147 . V_158 |=
F_2 ( V_161 ) ;
}
} else if ( V_168 -> V_162 == V_218 ) {
F_4 ( V_2 -> V_29 , V_36 , L_19 ) ;
V_166 -> V_147 . V_156 =
F_2 ( V_220 ) ;
V_166 -> V_147 . V_158 =
F_2 ( V_159 ) ;
if ( V_168 -> V_192 & V_195 )
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
V_229 ) ;
V_148 = ( T_1 ) ( V_168 -> V_162 + V_229 )
+ sizeof( struct V_61 ) ;
if ( F_7 ( V_166 -> V_147 . V_156 ) ==
V_184 ) {
struct V_230 * V_231 =
( void * ) V_166 -> V_147 . V_163 ;
memcpy ( V_231 -> V_179 , V_168 -> V_180 , V_232 ) ;
memcpy ( V_231 -> V_163 , V_168 -> V_166 ,
V_233 ) ;
V_148 = sizeof( struct V_230 ) ;
V_166 -> V_147 . V_162 =
F_2 ( V_148 ) ;
V_148 += V_229 ;
V_166 -> V_147 . V_60 =
F_2 ( V_148 ) ;
V_148 += sizeof( struct V_61 ) ;
}
V_4 -> V_8 = F_2 ( sizeof( V_166 -> V_13 ) + V_10
+ V_148 ) ;
if ( F_24 ( V_2 ) == V_200 ) {
V_224 = ( void * ) ( ( V_58 * ) & V_166 -> V_147 +
V_148 ) ;
V_224 -> V_234 . type =
F_2 ( V_235 ) ;
V_224 -> V_234 . V_171 = F_2 ( V_129 ) ;
memcpy ( V_224 -> V_127 , V_168 -> V_127 , V_129 ) ;
V_225 = V_148 + V_10 +
sizeof( V_166 -> V_13 ) +
sizeof( struct V_223 ) ;
} else {
V_225 = V_148 + V_10 +
sizeof( V_166 -> V_13 ) ;
}
V_4 -> V_8 = F_2 ( V_225 ) ;
}
return V_226 ;
}
static int
F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_2 V_31 ,
struct V_167 * V_168 )
{
if ( V_2 -> V_29 -> V_236 == V_237 )
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
struct V_238 * V_239 =
& V_4 -> V_11 . V_239 ;
struct V_240 * V_241 =
& V_239 -> V_241 ;
V_58 V_242 = V_29 -> V_243 . V_242 ;
F_4 ( V_29 , V_174 ,
L_20 , V_242 ) ;
V_4 -> V_6 = F_2 ( V_244 ) ;
V_239 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_39 ) {
V_4 -> V_8 = F_2 ( sizeof( V_239 -> V_13 ) + V_10 ) ;
return 0 ;
}
V_241 -> V_234 . type = F_2 ( V_245 ) ;
memcpy ( V_241 -> V_246 , V_29 -> V_243 . V_246 ,
sizeof( V_241 -> V_246 ) ) ;
V_241 -> V_234 . V_171 =
F_2 ( ( V_242 *
sizeof( struct V_247 ) )
+ sizeof( V_241 -> V_246 ) ) ;
if ( V_242 ) {
memcpy ( V_241 -> V_248 , V_29 -> V_243 . V_248 ,
V_242 * sizeof( struct
V_247 ) ) ;
V_4 -> V_8 = F_2 ( sizeof( V_239 -> V_13 ) +
F_7 ( V_241 -> V_234 . V_171 ) +
sizeof( struct V_61 )
+ V_10 ) ;
} else {
V_4 -> V_8 = F_2 ( sizeof( V_239 -> V_13 ) + V_10 ) ;
}
return 0 ;
}
static int F_29 ( struct V_3 * V_4 ,
T_1 V_5 , T_1 * V_249 )
{
struct V_250 * V_251 =
& ( V_4 -> V_11 . V_252 ) ;
V_4 -> V_6 = F_2 ( V_253 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_250 ) +
V_10 ) ;
V_4 -> V_126 = 0 ;
V_251 -> V_13 = F_2 ( V_5 ) ;
switch ( V_5 ) {
case V_28 :
if ( V_249 )
V_251 -> V_249 = F_2 ( * V_249 ) ;
else
V_251 -> V_249 = 0 ;
break;
case V_39 :
default:
break;
}
return 0 ;
}
static int
F_30 ( struct V_3 * V_4 , T_1 V_5 ,
void * V_254 )
{
struct V_255 * V_256 = ( void * ) V_254 ;
struct V_257 * V_258 = ( void * ) & V_4 -> V_11 . V_259 ;
V_4 -> V_6 = F_2 ( V_260 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_257 ) +
V_10 ) ;
V_258 -> V_13 = F_2 ( V_5 ) ;
V_258 -> V_261 = F_15 ( V_256 -> V_261 ) ;
V_258 -> V_44 = F_15 ( V_256 -> V_44 ) ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_262 * V_263 = V_79 ;
switch ( F_7 ( V_4 -> V_6 ) ) {
case V_264 :
{
struct V_265 * V_266 ;
V_4 -> V_8 = F_2 ( sizeof( * V_266 ) + V_10 ) ;
V_266 = & V_4 -> V_11 . V_266 ;
V_266 -> V_13 = F_2 ( V_5 ) ;
V_266 -> V_267 = F_2 ( ( T_1 ) V_263 -> V_267 ) ;
V_266 -> V_44 = F_15 ( V_263 -> V_44 ) ;
break;
}
case V_268 :
{
struct V_269 * V_270 ;
V_4 -> V_8 = F_2 ( sizeof( * V_270 ) + V_10 ) ;
V_270 = & V_4 -> V_11 . V_270 ;
V_270 -> V_13 = F_2 ( V_5 ) ;
V_270 -> V_267 = F_2 ( ( T_1 ) V_263 -> V_267 ) ;
V_270 -> V_44 = ( V_58 ) V_263 -> V_44 ;
break;
}
case V_271 :
{
struct V_272 * V_273 ;
V_4 -> V_8 = F_2 ( sizeof( * V_273 ) + V_10 ) ;
V_273 = & V_4 -> V_11 . V_273 ;
V_273 -> V_13 = F_2 ( V_5 ) ;
V_273 -> V_267 = F_2 ( ( T_1 ) V_263 -> V_267 ) ;
V_273 -> V_44 = ( V_58 ) V_263 -> V_44 ;
break;
}
case V_274 :
{
struct V_275 * V_276 ;
V_4 -> V_8 = F_2 ( sizeof( * V_276 ) + V_10 ) ;
V_276 = & V_4 -> V_11 . V_276 ;
V_276 -> V_13 = F_2 ( V_5 ) ;
V_276 -> V_267 = F_2 ( ( T_1 ) V_263 -> V_267 ) ;
V_276 -> V_44 = ( V_58 ) V_263 -> V_44 ;
break;
}
case V_277 :
{
struct V_272 * V_278 ;
V_4 -> V_8 = F_2 ( sizeof( * V_278 ) + V_10 ) ;
V_278 = & V_4 -> V_11 . V_273 ;
V_278 -> V_13 = F_2 ( V_5 ) ;
V_278 -> V_267 = F_2 ( ( T_1 ) V_263 -> V_267 ) ;
V_278 -> V_44 = ( V_58 ) V_263 -> V_44 ;
break;
}
case V_279 :
{
struct V_280 * V_281 = V_79 ;
struct V_282 * V_283 =
& V_4 -> V_11 . V_284 ;
V_4 -> V_8 = F_2 ( sizeof( * V_283 ) + V_10 ) ;
V_283 -> V_13 = F_2 ( V_5 ) ;
V_283 -> V_267 = F_2 ( V_281 -> V_267 ) ;
V_283 -> V_285 = F_2 ( V_281 -> V_285 ) ;
V_283 -> V_44 = 0 ;
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
struct V_286 * V_287 =
& V_4 -> V_11 . V_288 ;
struct V_289 * V_290 = V_2 -> V_29 -> V_290 ;
V_4 -> V_6 = F_2 ( V_291 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct
V_286 ) + V_10 ) ;
V_4 -> V_126 = 0 ;
memset ( V_287 , 0 , sizeof( struct V_286 ) ) ;
if ( V_13 != V_28 )
return 0 ;
V_287 -> V_292 = ( T_2 ) ( V_290 -> V_293 ) ;
V_287 -> V_294 = ( T_2 ) ( ( ( V_295 ) V_290 -> V_293 ) >> 32 ) ;
V_287 -> V_296 = V_297 ;
V_287 -> V_298 = ( T_2 ) ( V_290 -> V_299 ) ;
V_287 -> V_300 = ( T_2 ) ( ( ( V_295 ) V_290 -> V_299 ) >> 32 ) ;
V_287 -> V_301 = V_297 ;
V_287 -> V_302 = ( T_2 ) ( V_290 -> V_303 ) ;
V_287 -> V_304 = ( T_2 ) ( ( ( V_295 ) V_290 -> V_303 ) >> 32 ) ;
V_287 -> V_305 = V_306 ;
if ( V_290 -> V_307 ) {
V_287 -> V_308 =
( T_2 ) ( V_290 -> V_309 ) ;
V_287 -> V_310 =
( T_2 ) ( ( ( V_295 ) ( V_290 -> V_309 ) ) >> 32 ) ;
F_4 ( V_2 -> V_29 , V_174 ,
L_21 ,
V_287 -> V_308 ) ;
}
return 0 ;
}
static int
F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_311 * V_312 )
{
struct V_313 * V_314 = & V_4 -> V_11 . V_314 ;
struct V_315 * V_316 ;
T_1 V_317 ;
V_58 * V_318 ;
V_4 -> V_6 = F_2 ( V_319 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_313 ) +
V_10 ) ;
V_314 -> V_13 = F_2 ( V_312 -> V_13 ) ;
F_4 ( V_2 -> V_29 , V_36 ,
L_22 , V_312 -> V_13 ) ;
if ( V_312 -> V_13 == V_39 )
return 0 ;
V_314 -> V_320 = F_2 ( V_312 -> V_320 ) ;
V_317 = V_312 -> V_320 ;
F_4 ( V_2 -> V_29 , V_36 , L_23 ,
V_317 ) ;
if ( ( ( V_312 -> V_13 == V_321 ) ||
( V_312 -> V_13 == V_322 ) ) &&
( V_317 == 0 ) ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_24
L_25 ) ;
return - V_323 ;
}
if ( V_312 -> V_13 == V_321 )
return 0 ;
V_318 = ( ( V_58 * ) V_314 ) +
sizeof( struct V_313 ) ;
if ( V_317 & V_324 ) {
V_316 = (struct V_315 * ) V_318 ;
V_316 -> V_234 . type = F_2 ( V_325 ) ;
V_316 -> V_234 . V_171 =
F_2 ( sizeof( struct V_315 ) -
sizeof( struct V_61 ) ) ;
V_316 -> V_326 = V_312 -> V_327 . V_326 ;
V_316 -> V_328 = V_312 -> V_327 . V_328 ;
F_4 ( V_2 -> V_29 , V_329 ,
L_26
L_27 ,
V_312 -> V_327 . V_326 ,
V_312 -> V_327 . V_328 ) ;
V_318 += sizeof( struct V_315 ) ;
F_6 ( & V_4 -> V_8 ,
sizeof( struct V_315 ) ) ;
}
if ( V_317 & V_330 ) {
V_316 = (struct V_315 * ) V_318 ;
V_316 -> V_234 . type = F_2 ( V_331 ) ;
V_316 -> V_234 . V_171 =
F_2 ( sizeof( struct V_315 ) -
sizeof( struct V_61 ) ) ;
V_316 -> V_326 = V_312 -> V_332 . V_326 ;
V_316 -> V_328 = V_312 -> V_332 . V_328 ;
F_4 ( V_2 -> V_29 , V_329 ,
L_28
L_27 ,
V_312 -> V_332 . V_326 ,
V_312 -> V_332 . V_328 ) ;
V_318 += sizeof( struct V_315 ) ;
F_6 ( & V_4 -> V_8 ,
sizeof( struct V_315 ) ) ;
}
return 0 ;
}
static int
F_34 ( struct V_1 * V_2 ,
struct V_333 * V_334 ,
V_58 * * V_335 )
{
struct V_336 * V_337 = V_334 -> V_337 ;
int V_55 , V_338 ;
V_58 * V_339 = * V_335 ;
for ( V_55 = 0 ; V_55 < V_340 ; V_55 ++ ) {
V_337 = & V_334 -> V_337 [ V_55 ] ;
if ( ! V_337 -> V_341 )
break;
* ( V_342 * ) V_339 = F_15 ( ( T_2 ) V_337 -> V_343 ) ;
V_339 += 4 ;
* V_339 = V_344 ;
V_339 += 1 ;
V_338 = V_337 -> V_345 [ V_346 ] ;
memcpy ( V_339 , V_337 -> V_345 , V_338 ) ;
V_339 += V_338 ;
* V_339 = V_338 ;
V_339 += 1 ;
* V_339 = V_347 ;
V_339 += 1 ;
* ( V_342 * ) V_339 = F_15 ( ( T_2 ) V_337 -> V_267 ) ;
V_339 += 4 ;
* V_339 = V_344 ;
V_339 += 1 ;
* V_339 = V_337 -> V_341 ;
V_339 += 1 ;
if ( V_337 -> V_348 ) {
* V_339 = V_337 -> V_348 ;
V_339 += 1 ;
}
if ( V_339 - * V_335 > V_349 )
return - 1 ;
}
* V_335 = V_339 ;
return 0 ;
}
static int
F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_350 * V_351 )
{
struct V_352 * V_353 = & V_4 -> V_11 . V_353 ;
struct V_354 * V_334 = NULL ;
V_58 * V_318 = ( V_58 * ) V_353 ;
T_1 V_55 ;
V_4 -> V_6 = F_2 ( V_355 ) ;
V_353 -> V_356 = F_15 ( V_351 -> V_356 ) ;
V_353 -> V_357 = F_2 ( V_351 -> V_357 ) ;
V_318 += sizeof( * V_353 ) ;
for ( V_55 = 0 ; V_55 < V_351 -> V_357 ; V_55 ++ ) {
V_334 = (struct V_354 * ) V_318 ;
V_334 -> V_78 = V_351 -> V_334 [ V_55 ] . V_78 ;
V_334 -> V_13 = V_351 -> V_334 [ V_55 ] . V_13 ;
V_318 += sizeof( * V_353 -> V_334 ) ;
if ( F_34 ( V_2 ,
& V_351 -> V_334 [ V_55 ] , & V_318 ) )
return - 1 ;
V_334 -> V_358 =
F_2 ( V_318 - V_334 -> V_359 ) ;
}
V_4 -> V_8 = F_2 ( ( T_1 ) ( V_318 - ( V_58 * ) V_353 ) + V_10 ) ;
return 0 ;
}
static T_2 F_36 ( V_58 * V_360 , T_3 V_171 , V_58 * V_361 )
{
V_58 * V_362 = V_360 , * V_363 = V_361 ;
while ( V_362 - V_360 < V_171 ) {
if ( * V_362 && ( isspace ( * V_362 ) || * V_362 == '\t' ) ) {
V_362 ++ ;
continue;
}
if ( isxdigit ( * V_362 ) ) {
* V_363 ++ = F_37 ( V_362 , NULL , 16 ) ;
V_362 += 2 ;
} else {
V_362 ++ ;
}
}
return V_363 - V_361 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_364 * V_365 , const char * V_366 )
{
#ifdef F_39
struct V_367 * V_368 ;
T_3 V_171 = strlen ( V_366 ) ;
int V_226 ;
F_40 (node, prop) {
if ( V_171 > strlen ( V_368 -> V_369 ) ||
strncmp ( V_368 -> V_369 , V_366 , V_171 ) )
continue;
if ( V_368 && V_368 -> V_44 && V_368 -> V_60 > 6 &&
V_368 -> V_60 <= V_370 - V_10 ) {
V_226 = F_41 ( V_2 , V_371 ,
V_28 , 0 ,
V_368 , true ) ;
if ( V_226 )
return V_226 ;
}
}
#endif
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 , void * V_79 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
struct V_367 * V_368 = V_79 ;
T_2 V_171 ;
V_58 * V_372 = ( V_58 * ) V_4 + V_10 ;
int V_226 ;
if ( V_368 ) {
V_171 = V_368 -> V_60 ;
V_226 = F_43 ( V_29 -> V_373 , V_368 -> V_369 ,
V_372 , V_171 ) ;
if ( V_226 )
return V_226 ;
F_4 ( V_29 , V_174 ,
L_29 ,
V_368 -> V_369 ) ;
} else if ( V_29 -> V_374 -> V_372 && V_29 -> V_374 -> V_8 > 0 ) {
V_171 = F_36 ( ( V_58 * ) V_29 -> V_374 -> V_372 ,
V_29 -> V_374 -> V_8 , V_372 ) ;
F_4 ( V_29 , V_174 ,
L_30 ) ;
} else {
return - 1 ;
}
V_4 -> V_6 = F_2 ( V_371 ) ;
V_4 -> V_8 = F_2 ( V_10 + V_171 ) ;
return 0 ;
}
static int
F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_375 * V_376 = & V_4 -> V_11 . V_377 ;
const T_1 * V_378 = V_79 ;
V_376 -> V_13 = F_2 ( V_5 ) ;
V_376 -> V_379 = F_2 ( * V_378 ) ;
V_4 -> V_6 = F_2 ( V_380 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_375 ) +
V_10 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , bool * V_381 )
{
struct V_382 * V_383 = & V_4 -> V_11 . V_383 ;
struct V_384 * V_385 ;
V_4 -> V_6 = F_2 ( V_386 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_383 ) + sizeof( * V_385 ) + V_10 ) ;
V_383 -> V_13 = F_2 ( V_5 ) ;
V_385 = (struct V_384 * )
( ( V_58 * ) V_383 + sizeof( * V_383 ) ) ;
V_385 -> V_234 . type = F_2 ( V_387 ) ;
V_385 -> V_234 . V_171 = F_2 ( sizeof( V_385 -> V_78 ) ) ;
if ( V_383 -> V_13 == V_39 )
return 0 ;
if ( * V_381 )
V_385 -> V_78 = F_15 ( V_388 ) ;
else
V_385 -> V_78 = F_15 ( V_389 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 ,
struct V_390 * V_372 )
{
struct V_391 * V_392 = & V_4 -> V_11 . V_392 ;
V_295 V_393 ;
V_4 -> V_6 = F_2 ( V_394 ) ;
V_4 -> V_8 = F_2 ( sizeof( * V_392 ) + V_10 ) ;
V_392 -> V_13 = F_2 ( V_5 ) ;
if ( V_5 == V_28 ) {
memcpy ( V_392 -> V_395 , V_372 -> V_395 , V_396 ) ;
memcpy ( V_392 -> V_397 , V_372 -> V_397 , V_398 ) ;
V_393 = F_47 ( ( V_399 * ) V_372 -> V_400 ) ;
V_392 -> V_401 = F_15 ( ( T_2 ) V_393 ) ;
V_392 -> V_402 =
F_15 ( ( T_2 ) ( ( V_295 ) V_393 >> 32 ) ) ;
}
return 0 ;
}
static int
F_48 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_403 * V_404 =
& V_4 -> V_11 . V_404 ;
struct V_405 * V_406 = V_79 ;
struct V_407 * V_231 ;
T_1 V_408 , V_409 , V_60 ;
struct V_410 * V_411 ;
V_4 -> V_6 = F_2 ( V_412 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_404 -> V_13 = F_2 ( V_5 ) ;
V_404 -> V_413 = F_2 ( V_406 -> V_413 ) ;
V_411 = V_404 -> V_411 ;
for ( V_408 = 0 ; V_408 < V_406 -> V_413 ; V_408 ++ ) {
V_411 -> V_234 . type = F_2 ( V_414 ) ;
V_411 -> V_415 =
F_2 ( V_406 -> V_411 [ V_408 ] . V_415 ) ;
V_411 -> V_416 = V_406 -> V_411 [ V_408 ] . V_416 ;
V_411 -> V_417 = V_406 -> V_411 [ V_408 ] . V_417 ;
V_60 = 0 ;
V_231 = V_411 -> V_11 ;
for ( V_409 = 0 ; V_409 < V_406 -> V_411 [ V_408 ] . V_417 ; V_409 ++ ) {
V_231 -> V_418 = V_406 -> V_411 [ V_408 ] . V_11 [ V_409 ] . V_418 ;
V_231 -> V_419 =
V_406 -> V_411 [ V_408 ] . V_11 [ V_409 ] . V_419 ;
V_231 -> V_267 =
F_2 ( V_406 -> V_411 [ V_408 ] . V_11 [ V_409 ] . V_267 ) ;
memcpy ( V_231 -> V_420 ,
V_406 -> V_411 [ V_408 ] . V_11 [ V_409 ] . V_420 ,
V_231 -> V_419 ) ;
V_60 += sizeof( struct V_407 ) ;
V_231 ++ ;
}
V_411 -> V_234 . V_171 = F_2 ( V_60 + sizeof( T_1 ) +
sizeof( V_58 ) + sizeof( V_58 ) ) ;
F_6 ( & V_4 -> V_8 , F_7 ( V_411 -> V_234 . V_171 ) +
sizeof( struct V_61 ) ) ;
V_411 = ( void * ) ( ( V_58 * ) V_411 -> V_11 + V_60 ) ;
}
F_6 ( & V_4 -> V_8 , sizeof( T_1 ) + sizeof( T_1 ) ) ;
return 0 ;
}
static int
F_49 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_421 * V_422 = & V_4 -> V_11 . V_422 ;
struct V_423 * V_424 ;
struct V_425 * V_426 ;
T_1 V_171 ;
V_4 -> V_6 = F_2 ( V_427 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
V_422 -> V_428 = F_2 ( V_5 ) ;
F_6 ( & V_4 -> V_8 , sizeof( V_422 -> V_428 ) ) ;
switch ( V_5 ) {
case V_429 :
V_426 = V_79 ;
V_171 = sizeof( * V_426 ) ;
memcpy ( V_422 -> V_430 , V_426 , V_171 ) ;
break;
case V_431 :
V_424 = V_79 ;
V_171 = sizeof( * V_424 ) ;
memcpy ( V_422 -> V_430 , V_424 , V_171 ) ;
break;
case V_432 :
V_171 = sizeof( struct V_433 ) ;
memcpy ( V_422 -> V_430 , V_79 , V_171 ) ;
break;
case V_434 :
V_171 = sizeof( struct V_435 ) ;
memcpy ( V_422 -> V_430 , V_79 , V_171 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_31 ) ;
return - V_436 ;
}
F_6 ( & V_4 -> V_8 , V_171 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
void * V_79 )
{
struct V_437 * V_438 = & V_4 -> V_11 . V_438 ;
struct V_439 * V_440 = V_79 ;
struct V_441 * V_442 ;
struct V_443 * V_444 ;
struct V_445 * V_446 ;
struct V_447 * V_448 ;
struct V_449 * V_450 ;
struct V_451 * V_452 ;
struct V_453 * V_454 ;
struct V_455 * V_456 ;
V_58 * V_318 , V_457 ;
T_1 V_458 = 0 ;
struct V_459 * V_11 = V_2 -> V_460 ;
V_4 -> V_6 = F_2 ( V_461 ) ;
V_4 -> V_8 = F_2 ( V_10 ) ;
F_6 ( & V_4 -> V_8 , sizeof( struct V_437 ) ) ;
V_438 -> V_462 = 0 ;
memcpy ( V_438 -> V_463 , V_440 -> V_463 , V_129 ) ;
V_442 = F_51 ( V_2 , V_440 -> V_463 ) ;
V_318 = ( V_58 * ) V_438 + sizeof( struct V_437 ) ;
switch ( V_440 -> V_428 ) {
case V_464 :
V_438 -> V_428 = F_2 ( V_465 ) ;
break;
case V_466 :
V_438 -> V_428 = F_2 ( V_467 ) ;
break;
case V_468 :
V_438 -> V_428 = F_2 ( V_469 ) ;
if ( ! V_11 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_32 ,
V_440 -> V_463 ) ;
return - V_470 ;
}
* ( V_43 * ) V_318 = F_2 ( V_11 -> V_471 ) ;
V_458 += sizeof( V_11 -> V_471 ) ;
V_457 = V_11 -> V_472 | ( V_11 -> V_473 << 5 ) ;
V_448 = (struct V_447 * ) ( V_318 +
V_458 ) ;
V_448 -> V_234 . type = F_2 ( V_474 ) ;
V_448 -> V_234 . V_171 = F_2 ( sizeof( V_457 ) ) ;
V_448 -> V_457 = V_457 ;
V_458 += sizeof( struct V_447 ) ;
if ( V_11 -> V_475 ) {
V_446 = (struct V_445 * ) ( V_318 +
V_458 ) ;
V_446 -> V_234 . type =
F_2 ( V_476 ) ;
V_446 -> V_234 . V_171 =
F_2 ( sizeof( struct V_477 ) ) ;
memcpy ( & V_446 -> V_478 , V_11 -> V_475 ,
sizeof( struct V_477 ) ) ;
V_458 += sizeof( struct V_445 ) ;
}
if ( V_11 -> V_479 && V_11 -> V_480 ) {
V_444 = (struct V_443 * ) ( V_318 +
V_458 ) ;
V_444 -> V_234 . type =
F_2 ( V_481 ) ;
V_444 -> V_234 . V_171 =
F_2 ( V_11 -> V_480 ) ;
memcpy ( V_444 -> V_482 , V_11 -> V_479 ,
V_11 -> V_480 ) ;
V_458 += sizeof( struct V_443 ) +
V_11 -> V_480 ;
}
if ( V_11 -> V_483 && V_11 -> V_484 ) {
V_450 = (struct V_449 * ) ( V_318 +
V_458 ) ;
V_450 -> V_234 . type =
F_2 ( V_485 ) ;
V_450 -> V_234 . V_171 = F_2 ( V_11 -> V_484 ) ;
memcpy ( V_450 -> V_483 , V_11 -> V_483 ,
V_11 -> V_484 ) ;
V_458 += sizeof( struct V_449 ) +
V_11 -> V_484 ;
}
if ( V_11 -> V_486 ) {
V_452 = (struct V_451 * ) ( V_318 +
V_458 ) ;
V_452 -> V_234 . type =
F_2 ( V_487 ) ;
V_452 -> V_234 . V_171 =
F_2 ( sizeof( struct V_488 ) ) ;
memcpy ( & V_452 -> V_489 , V_11 -> V_486 ,
sizeof( struct V_488 ) ) ;
V_458 += sizeof( struct V_451 ) ;
}
if ( V_11 -> V_454 ) {
V_454 = (struct V_453 * ) ( V_318 + V_458 ) ;
V_454 -> V_234 . type = F_2 ( V_490 ) ;
V_454 -> V_234 . V_171 = F_2 ( sizeof( V_11 -> V_454 ) ) ;
V_454 -> V_454 = F_2 ( V_11 -> V_454 ) ;
V_458 += sizeof( struct V_453 ) ;
}
V_456 = ( void * ) ( V_318 + V_458 ) ;
V_456 -> V_234 . type = F_2 ( V_491 ) ;
V_456 -> V_234 . V_171 = F_2 ( sizeof( V_456 -> V_44 ) ) ;
V_456 -> V_44 = F_2 ( V_492 ) ;
V_458 += sizeof( struct V_455 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR , L_33 ) ;
return - V_436 ;
}
F_6 ( & V_4 -> V_8 , V_458 ) ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 ,
T_1 V_5 , void * V_79 )
{
struct V_493 * V_406 =
& V_4 -> V_11 . V_494 ;
V_4 -> V_6 = F_2 ( V_495 ) ;
V_4 -> V_8 =
F_2 ( sizeof( struct V_493 ) +
V_10 ) ;
V_406 -> V_13 = V_5 ;
if ( V_5 == V_28 )
V_406 -> V_249 = * ( V_58 * ) V_79 ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_4 -> V_6 = F_2 ( V_496 ) ;
V_4 -> V_8 = F_2 ( sizeof( struct V_497 ) +
V_10 ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 , T_4 V_498 ,
T_1 V_5 , T_2 V_31 ,
void * V_79 , void * V_499 )
{
struct V_3 * V_500 = V_499 ;
int V_226 = 0 ;
switch ( V_498 ) {
case V_501 :
V_226 = F_55 ( V_2 , V_500 ) ;
break;
case V_371 :
V_226 = F_42 ( V_2 , V_500 , V_79 ) ;
break;
case V_30 :
V_226 = F_3 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_124 :
V_226 = F_16 ( V_2 , V_500 ,
V_5 ) ;
break;
case V_135 :
V_226 = F_17 ( V_500 , V_5 ,
V_79 ) ;
break;
case V_56 :
V_226 = F_9 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_77 :
V_226 = F_11 ( V_500 , V_5 ,
V_79 ) ;
break;
case V_81 :
V_226 = F_12 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_88 :
V_226 = F_13 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_502 :
V_226 = F_56 ( V_2 , V_500 , V_5 ,
( T_4 ) V_31 , V_79 ) ;
break;
case V_111 :
V_226 = F_14 ( V_2 , V_500 , V_5 ,
(struct V_104 * ) V_79 ) ;
break;
case V_503 :
V_226 = F_57 ( V_500 , V_79 ) ;
break;
case V_504 :
V_226 = F_58 ( V_2 , V_500 ,
V_79 ) ;
break;
case V_505 :
V_226 = F_59 ( V_500 ) ;
break;
case V_506 :
V_226 = F_60 ( V_2 , V_500 , V_79 ) ;
break;
case V_142 :
V_226 = F_18 ( V_2 , V_500 ,
V_79 ) ;
break;
case V_507 :
V_226 = F_61 ( V_2 , V_500 ,
V_79 ) ;
break;
case V_45 :
V_226 = F_8 ( V_500 ) ;
break;
case V_508 :
V_226 = F_62 ( V_2 , V_500 ,
V_79 ) ;
break;
case V_145 :
V_226 = F_19 ( V_500 ) ;
break;
case V_7 :
V_226 = F_1 ( V_2 , V_500 , V_5 ) ;
break;
case V_37 :
V_226 = F_5 ( V_2 , V_500 , V_5 ,
V_31 , V_79 ) ;
break;
case V_509 :
V_500 -> V_6 =
F_2 ( V_509 ) ;
V_500 -> V_8 =
F_2 ( sizeof( struct V_510 ) +
V_10 ) ;
V_2 -> V_511 = 0 ;
V_226 = 0 ;
break;
case V_512 :
V_500 -> V_6 = F_2 ( V_498 ) ;
V_500 -> V_11 . V_513 . V_514 =
( V_58 ) ( * ( ( T_2 * ) V_79 ) ) ;
memcpy ( & V_500 -> V_11 , V_79 ,
sizeof( struct V_515 ) ) ;
V_500 -> V_8 =
F_2 ( sizeof( struct V_515 ) +
V_10 ) ;
V_226 = 0 ;
break;
case V_516 :
V_500 -> V_6 = F_2 ( V_498 ) ;
V_500 -> V_11 . V_517 . V_13 = F_2 ( V_5 ) ;
V_500 -> V_11 . V_517 . V_518 = F_15 ( * ( T_2 * ) V_79 ) ;
V_500 -> V_8 =
F_2 ( sizeof( struct V_519 ) +
V_10 ) ;
V_226 = 0 ;
break;
case V_520 :
V_500 -> V_6 = F_2 ( V_498 ) ;
memcpy ( & V_500 -> V_11 , V_79 ,
sizeof( struct V_521 ) ) ;
V_500 -> V_8 =
F_2 ( sizeof( struct V_521 ) +
V_10 ) ;
break;
case V_522 :
V_226 = F_63 ( V_2 , V_500 , V_5 , V_79 ) ;
break;
case V_523 :
V_500 -> V_6 = F_2 ( V_498 ) ;
V_500 -> V_11 . V_524 . V_13 = F_2 ( V_5 ) ;
V_500 -> V_11 . V_524 . V_78 = F_2 ( * ( T_1 * ) V_79 ) ;
V_500 -> V_8 =
F_2 ( sizeof( struct V_525 ) +
V_10 ) ;
break;
case V_526 :
if ( V_2 -> V_29 -> V_527 == V_528 )
V_2 -> V_29 -> V_527 = V_529 ;
V_500 -> V_6 = F_2 ( V_498 ) ;
V_500 -> V_8 = F_2 ( V_10 ) ;
break;
case V_530 :
V_2 -> V_29 -> V_527 = V_528 ;
V_500 -> V_6 = F_2 ( V_498 ) ;
V_500 -> V_8 = F_2 ( V_10 ) ;
break;
case V_531 :
V_226 = F_64 ( V_500 , V_79 ) ;
break;
case V_532 :
V_226 = F_65 ( V_500 , V_79 ) ;
break;
case V_533 :
V_226 = F_66 ( V_2 , V_500 , V_79 ) ;
break;
case V_190 :
V_226 = F_27 ( V_2 , V_500 ,
V_5 , V_31 ,
V_79 ) ;
break;
case V_244 :
V_226 = F_28 ( V_2 , V_500 ,
V_5 ) ;
break;
case V_534 :
V_226 = F_67 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_535 :
V_226 = F_68 ( V_500 , V_5 ,
V_79 ) ;
break;
case V_536 :
V_226 = F_69 ( V_2 , V_500 , V_5 , V_79 ) ;
break;
case V_537 :
F_4 ( V_2 -> V_29 , V_36 ,
L_34 ) ;
V_500 -> V_6 = F_2 ( V_537 ) ;
V_500 -> V_8 =
F_2 ( sizeof( struct V_538 ) +
V_10 ) ;
V_226 = 0 ;
break;
case V_253 :
V_226 = F_29 ( V_500 , V_5 ,
V_79 ) ;
break;
case V_539 :
V_226 = F_70 ( V_2 , V_500 , V_79 ) ;
break;
case V_260 :
V_226 = F_30 ( V_500 , V_5 , V_79 ) ;
break;
case V_264 :
case V_268 :
case V_271 :
case V_274 :
case V_277 :
case V_279 :
V_226 = F_31 ( V_500 , V_5 , V_79 ) ;
break;
case V_540 :
V_500 -> V_6 = F_2 ( V_498 ) ;
if ( V_2 -> V_213 == V_214 )
V_500 -> V_11 . V_213 . V_541 =
V_542 ;
else if ( V_2 -> V_213 == V_543 ||
V_2 -> V_213 == V_544 )
V_500 -> V_11 . V_213 . V_541 =
V_545 ;
else if ( V_2 -> V_213 == V_546 ||
V_2 -> V_213 == V_547 )
V_500 -> V_11 . V_213 . V_541 = V_548 ;
V_500 -> V_8 = F_2 ( sizeof( struct
V_549 ) + V_10 ) ;
V_226 = 0 ;
break;
case V_291 :
V_226 = F_32 ( V_2 , V_500 , V_5 ) ;
break;
case V_319 :
V_226 = F_33 ( V_2 , V_500 , V_79 ) ;
break;
case V_355 :
V_226 = F_35 ( V_2 , V_500 , V_79 ) ;
break;
case V_412 :
V_226 = F_48 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_461 :
V_226 = F_50 ( V_2 , V_500 , V_79 ) ;
break;
case V_427 :
V_226 = F_49 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_550 :
V_226 = F_71 ( V_2 , V_500 ,
V_79 ) ;
break;
case V_495 :
V_226 = F_52 ( V_500 , V_5 ,
V_79 ) ;
break;
case V_496 :
V_226 = F_53 ( V_2 , V_500 ) ;
break;
case V_380 :
V_226 = F_44 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_386 :
V_226 = F_45 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
case V_394 :
V_226 = F_46 ( V_2 , V_500 , V_5 ,
V_79 ) ;
break;
default:
F_4 ( V_2 -> V_29 , ERROR ,
L_35 , V_498 ) ;
V_226 = - 1 ;
break;
}
return V_226 ;
}
int F_72 ( struct V_1 * V_2 , V_58 V_551 , bool V_552 )
{
struct V_106 * V_29 = V_2 -> V_29 ;
int V_226 ;
T_1 V_249 = true ;
struct V_553 V_554 ;
struct V_555 V_556 ;
enum V_557 V_558 ;
struct V_559 V_560 ;
V_58 V_561 ;
int V_372 ;
if ( V_551 ) {
if ( V_2 -> V_29 -> V_562 == V_563 ) {
V_226 = F_41 ( V_2 ,
V_291 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_226 )
return - 1 ;
}
V_226 = F_41 ( V_2 , V_526 ,
V_28 , 0 , NULL , true ) ;
if ( V_226 )
return - 1 ;
if ( V_2 -> V_29 -> V_562 == V_564 &&
V_29 -> V_565 -> V_566 ) {
V_29 -> V_373 = V_29 -> V_565 -> V_566 ;
if ( F_73 ( V_29 -> V_373 ,
L_36 ,
& V_372 ) == 0 ) {
F_74 ( L_37 , V_372 ) ;
V_29 -> V_108 . V_122 = V_372 ;
}
V_226 = F_38 ( V_2 , V_29 -> V_373 ,
L_38 ) ;
if ( V_226 )
return - 1 ;
}
if ( V_29 -> V_374 ) {
V_226 = F_41 ( V_2 , V_371 ,
V_28 , 0 , NULL ,
true ) ;
if ( V_226 )
return - 1 ;
}
V_226 = F_41 ( V_2 , V_501 ,
V_39 , 0 , NULL , true ) ;
if ( V_226 )
return - 1 ;
if ( V_2 -> V_29 -> V_562 == V_564 &&
F_75 ( V_2 -> V_29 -> V_567 ) &&
! V_2 -> V_29 -> V_568 ) {
V_561 = true ;
V_226 = F_41 ( V_2 ,
V_495 ,
V_28 , 0 ,
& V_561 ,
true ) ;
if ( V_226 ) {
F_4 ( V_2 -> V_29 , ERROR ,
L_39 ) ;
V_29 -> V_569 = false ;
}
}
V_226 = F_41 ( V_2 , V_534 ,
V_28 , 0 ,
& V_2 -> V_29 -> V_570 , true ) ;
if ( V_226 )
return - 1 ;
if ( V_2 -> V_571 != V_572 ) {
V_2 -> V_29 -> V_573 = V_574 ;
V_226 = F_41 ( V_2 ,
V_502 ,
V_575 , V_576 , NULL ,
true ) ;
if ( V_226 )
return - 1 ;
}
if ( V_577 ) {
V_29 -> V_578 = true ;
if ( F_76 ( V_29 -> V_567 ) )
V_226 = F_41 ( V_2 ,
V_380 ,
V_28 , 0 ,
& V_29 -> V_578 ,
true ) ;
if ( V_226 )
return - 1 ;
}
}
V_226 = F_41 ( V_2 , V_56 ,
V_39 , 0 , NULL , true ) ;
if ( V_226 )
return - 1 ;
V_2 -> V_579 = 0 ;
V_226 = F_41 ( V_2 , V_81 ,
V_39 , 0 , NULL , true ) ;
if ( V_226 )
return - 1 ;
if ( V_2 -> V_571 == V_580 ) {
V_226 = F_41 (
V_2 ,
V_253 ,
V_28 , 0 , & V_249 , true ) ;
if ( V_226 )
return - 1 ;
}
memset ( & V_554 , 0 , sizeof( V_554 ) ) ;
V_554 . V_249 = true ;
V_226 = F_41 ( V_2 , V_535 ,
V_28 , 0 ,
& V_554 , true ) ;
if ( V_226 )
return - 1 ;
V_226 = F_41 ( V_2 , V_30 ,
V_28 , 0 ,
& V_2 -> V_581 , true ) ;
if ( V_226 )
return - 1 ;
if ( ! V_582 &&
V_551 && V_2 -> V_29 -> V_562 != V_583 &&
V_2 -> V_571 != V_572 ) {
V_556 . V_556 = V_584 ;
V_556 . V_585 = V_586 ;
V_226 = F_41 ( V_2 , V_502 ,
V_575 , V_587 ,
& V_556 , true ) ;
if ( V_226 )
return - 1 ;
}
if ( V_2 -> V_571 != V_572 ) {
V_558 = V_588 ;
V_226 = F_41 ( V_2 , V_37 ,
V_28 , V_589 ,
& V_558 , true ) ;
if ( V_226 )
F_4 ( V_2 -> V_29 , ERROR ,
L_40 ) ;
}
V_560 . V_590 = V_591 ;
V_226 = F_41 ( V_2 , V_536 ,
V_28 , 0 , & V_560 , true ) ;
if ( V_552 ) {
V_2 -> V_29 -> V_592 = V_536 ;
V_226 = - V_593 ;
}
return V_226 ;
}
