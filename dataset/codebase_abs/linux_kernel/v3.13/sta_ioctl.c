int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
F_2 (ha, dev)
memcpy ( & V_2 -> V_8 [ V_5 ++ ] , V_7 -> V_9 , V_10 ) ;
return V_5 ;
}
int F_3 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
int V_15 ;
V_15 = F_4 ( V_12 -> V_16 . V_17 ,
* ( V_14 -> V_18 ) ) ;
if ( V_15 ) {
F_5 ( V_12 -> V_4 , L_1 , V_15 ) ;
return V_15 ;
}
V_15 = V_12 -> V_16 . V_15 ;
V_12 -> V_16 . V_15 = 0 ;
return V_15 ;
}
int F_6 ( struct V_19 * V_20 ,
struct V_1 * V_21 )
{
int V_22 = 0 ;
T_1 V_23 ;
V_23 = V_20 -> V_24 ;
if ( V_21 -> V_25 == V_26 ) {
F_7 ( V_20 -> V_12 -> V_4 , L_2 ) ;
V_20 -> V_24 |= V_27 ;
V_20 -> V_24 &=
~ V_28 ;
} else {
V_20 -> V_24 &= ~ V_27 ;
if ( V_21 -> V_25 == V_29 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_3 ) ;
V_20 -> V_24 |=
V_28 ;
} else {
V_20 -> V_24 &=
~ V_28 ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_4 ,
V_21 -> V_30 ) ;
V_22 = F_8 ( V_20 ,
V_31 ,
V_32 , 0 ,
V_21 ) ;
}
}
F_7 ( V_20 -> V_12 -> V_4 ,
L_5 ,
V_23 , V_20 -> V_24 ) ;
if ( V_23 != V_20 -> V_24 ) {
V_22 = F_8 ( V_20 , V_33 ,
V_32 ,
0 , & V_20 -> V_24 ) ;
}
return V_22 ;
}
int F_9 ( struct V_19 * V_20 ,
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
T_2 * V_38 ;
T_3 V_39 ;
struct V_40 * V_41 = ( void * ) V_35 -> V_20 ;
const struct V_42 * V_43 ;
F_10 () ;
V_43 = F_11 ( V_35 -> V_43 ) ;
V_38 = F_12 ( V_43 -> V_44 , V_43 -> V_45 , V_46 ) ;
V_39 = V_43 -> V_45 ;
V_37 -> V_47 = V_43 -> V_48 ;
F_13 () ;
if ( ! V_38 ) {
F_5 ( V_20 -> V_12 -> V_4 , L_6 ) ;
return - V_49 ;
}
memcpy ( V_37 -> V_50 , V_35 -> V_51 , V_10 ) ;
V_37 -> V_52 = V_35 -> signal ;
V_37 -> V_53 = V_38 ;
V_37 -> V_54 = V_39 ;
V_37 -> V_55 = V_35 -> V_56 ;
V_37 -> V_57 = V_35 -> V_58 ;
V_37 -> V_59 = V_41 -> V_60 ;
V_37 -> V_61 = V_41 -> V_61 ;
if ( V_37 -> V_57 & V_62 ) {
F_7 ( V_20 -> V_12 -> V_4 , L_7 ) ;
V_37 -> V_63 = V_64 ;
} else {
V_37 -> V_63 = V_65 ;
}
if ( V_37 -> V_57 & V_66 )
V_37 -> V_67 = V_68 ;
else
V_37 -> V_67 = V_69 ;
V_37 -> V_70 = true ;
if ( V_37 -> V_57 & V_71 )
V_37 -> V_72 = true ;
return F_14 ( V_20 -> V_12 , V_37 ) ;
}
static int F_15 ( struct V_19 * V_20 ,
struct V_34 * V_35 )
{
const T_2 * V_73 ;
T_2 V_74 ;
struct V_75 * V_76 =
& V_20 -> V_12 -> V_77 ;
F_10 () ;
V_73 = F_16 ( V_35 , V_78 ) ;
if ( ! V_73 ) {
F_13 () ;
return 0 ;
}
V_74 = V_73 [ 1 ] ;
if ( V_74 < V_79 ) {
F_13 () ;
return 0 ;
}
V_76 -> V_80 [ 0 ] = V_73 [ 2 ] ;
V_76 -> V_80 [ 1 ] = V_73 [ 3 ] ;
V_76 -> V_80 [ 2 ] = ' ' ;
V_74 -= V_81 ;
V_76 -> V_82 =
V_74 / sizeof( struct V_83 ) ;
memcpy ( ( T_2 * ) V_76 -> V_84 ,
& V_73 [ 2 ] + V_81 , V_74 ) ;
F_13 () ;
if ( F_8 ( V_20 , V_85 ,
V_32 , 0 , NULL ) ) {
F_17 ( V_20 -> V_12 -> V_86 ,
L_8 ) ;
return - 1 ;
}
return 0 ;
}
int F_18 ( struct V_19 * V_20 , struct V_34 * V_35 ,
struct V_87 * V_88 )
{
int V_22 ;
struct V_11 * V_12 = V_20 -> V_12 ;
struct V_36 * V_37 = NULL ;
V_20 -> V_89 = false ;
if ( V_35 ) {
F_15 ( V_20 , V_35 ) ;
V_37 = F_19 ( sizeof( struct V_36 ) ,
V_90 ) ;
if ( ! V_37 )
return - V_49 ;
V_22 = F_9 ( V_20 , V_35 , V_37 ) ;
if ( V_22 )
goto V_91;
}
if ( V_20 -> V_67 == V_69 ||
V_20 -> V_67 == V_92 ) {
T_2 V_93 ;
V_22 = F_20 ( V_20 , NULL ) ;
if ( V_22 )
goto V_91;
if ( ! V_37 )
return - 1 ;
if ( F_21 ( V_37 -> V_59 ) ==
V_94 )
V_93 = V_95 | V_96 | V_97 | V_98 ;
else
V_93 = V_99 | V_100 | V_101 ;
if ( ! ( ( V_93 | V_12 -> V_102 ) & ~ V_12 -> V_102 ) )
V_12 -> V_93 = V_93 ;
V_22 = F_22 ( V_20 , V_37 ) ;
if ( V_22 )
goto V_91;
if ( F_23 ( V_20 ) ==
( T_2 ) V_37 -> V_103 ) {
F_5 ( V_12 -> V_4 ,
L_9 ,
V_37 -> V_103 ) ;
goto V_91;
}
F_7 ( V_12 -> V_4 , L_10
L_11 ) ;
F_24 ( V_20 -> V_104 , V_12 ) ;
if ( F_25 ( V_20 -> V_104 ) )
F_26 ( V_20 -> V_104 ) ;
V_20 -> V_105 = 0 ;
V_22 = F_27 ( V_20 , V_37 ) ;
if ( V_22 == V_106 &&
V_20 -> V_107 . V_108 &&
V_20 -> V_107 . V_109 ) {
V_20 -> V_107 . V_110 =
V_111 ;
V_22 = F_27 ( V_20 , V_37 ) ;
}
if ( V_35 )
F_28 ( V_20 -> V_12 -> V_86 , V_35 ) ;
} else {
if ( V_37 && V_37 -> V_112 . V_113 &&
( ! F_29 ( & V_20 -> V_114 . V_115 .
V_112 , & V_37 -> V_112 ) ) ) {
V_22 = 0 ;
goto V_91;
}
F_7 ( V_12 -> V_4 , L_12 ) ;
V_22 = F_20 ( V_20 , NULL ) ;
if ( V_22 )
goto V_91;
V_20 -> V_116 = false ;
V_22 = F_22 ( V_20 , V_37 ) ;
F_24 ( V_20 -> V_104 , V_12 ) ;
if ( F_25 ( V_20 -> V_104 ) )
F_26 ( V_20 -> V_104 ) ;
if ( ! V_22 ) {
F_7 ( V_12 -> V_4 , L_13
L_14 ) ;
V_22 = F_30 ( V_20 , V_37 ) ;
if ( V_35 )
F_28 ( V_20 -> V_12 -> V_86 , V_35 ) ;
} else {
F_7 ( V_12 -> V_4 , L_15
L_16 ,
V_88 -> V_112 ) ;
V_22 = F_31 ( V_20 , V_88 ) ;
}
}
V_91:
if ( V_37 )
F_32 ( V_37 -> V_53 ) ;
F_32 ( V_37 ) ;
return V_22 ;
}
static int F_33 ( struct V_19 * V_20 , T_1 V_117 ,
int V_118 , struct V_119 * V_120 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
int V_15 = 0 ;
T_4 V_121 = 0 ;
if ( ! V_120 )
return - V_49 ;
switch ( V_117 ) {
case V_32 :
if ( V_12 -> V_122 ) {
F_7 ( V_12 -> V_4 , L_17
L_18 ) ;
V_15 = - 1 ;
break;
}
if ( V_120 -> V_123 ) {
if ( V_120 -> V_124 == V_125 ) {
if ( ! V_12 -> V_126 )
break;
V_121 = F_34 ( V_12 -> V_120
. V_124 ) ;
V_12 -> V_120 . V_124 =
F_35 ( V_120 -> V_124 ) ;
} else if ( V_120 -> V_124 ) {
V_12 -> V_120 . V_124 =
F_35 ( V_120 -> V_124 ) ;
V_12 -> V_120 . V_127 = ( T_2 ) V_120 -> V_127 ;
if ( V_120 -> V_128 )
V_12 -> V_120 . V_128 = ( T_2 ) V_120 -> V_128 ;
} else if ( V_12 -> V_120 . V_124 ==
F_35 ( V_125 ) ) {
V_15 = - 1 ;
break;
}
if ( V_118 == V_129 )
V_15 = F_36 ( V_20 ,
V_130 ,
V_32 , 0 ,
& V_12 -> V_120 ) ;
else
V_15 = F_8 ( V_20 ,
V_130 ,
V_32 , 0 ,
& V_12 -> V_120 ) ;
if ( V_120 -> V_124 == V_125 )
V_12 -> V_120 . V_124 =
F_35 ( V_121 ) ;
} else {
V_12 -> V_120 . V_124 =
F_35 ( V_120 -> V_124 ) ;
V_12 -> V_120 . V_127 = ( T_2 ) V_120 -> V_127 ;
V_12 -> V_120 . V_128 = ( T_2 ) V_120 -> V_128 ;
}
break;
case V_131 :
V_120 -> V_124 = F_34 ( V_12 -> V_120 . V_124 ) ;
V_120 -> V_127 = V_12 -> V_120 . V_127 ;
V_120 -> V_128 = V_12 -> V_120 . V_128 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_37 ( struct V_19 * V_20 , int V_118 )
{
struct V_119 V_132 ;
V_132 . V_124 = V_125 ;
V_132 . V_123 = true ;
return F_33 ( V_20 , V_32 ,
V_118 , & V_132 ) ;
}
int F_38 ( struct V_11 * V_12 )
{
struct V_119 V_132 ;
struct V_19 * V_20 ;
int V_5 ;
if ( V_133 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_134 ; V_5 ++ ) {
V_20 = V_12 -> V_20 [ V_5 ] ;
if ( V_20 )
F_20 ( V_20 , NULL ) ;
}
}
if ( V_12 -> V_135 ) {
F_7 ( V_12 -> V_4 , L_19 ) ;
return true ;
}
V_12 -> V_136 = false ;
memset ( & V_132 , 0 , sizeof( struct V_119 ) ) ;
V_132 . V_123 = true ;
if ( F_33 ( F_39 ( V_12 ,
V_137 ) ,
V_32 , V_129 ,
& V_132 ) ) {
F_5 ( V_12 -> V_4 , L_20 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_138 ,
V_12 -> V_136 ) ) {
F_5 ( V_12 -> V_4 , L_21 ) ;
return false ;
}
return true ;
}
int F_40 ( struct V_19 * V_20 ,
struct V_139 * V_140 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
struct V_36 * V_37 ;
if ( ! V_140 )
return - 1 ;
V_37 = & V_20 -> V_114 . V_115 ;
V_140 -> V_67 = V_20 -> V_67 ;
memcpy ( & V_140 -> V_112 , & V_37 -> V_112 , sizeof( struct V_87 ) ) ;
memcpy ( & V_140 -> V_51 , & V_37 -> V_50 , V_10 ) ;
V_140 -> V_141 = V_37 -> V_103 ;
memcpy ( V_140 -> V_80 , V_12 -> V_80 ,
V_81 ) ;
V_140 -> V_142 = V_20 -> V_142 ;
V_140 -> V_143 = V_20 -> V_144 ;
V_140 -> V_145 = V_20 -> V_146 ;
V_140 -> V_147 = V_20 -> V_147 ;
V_140 -> V_148 = V_20 -> V_148 ;
if ( V_20 -> V_107 . V_109 )
V_140 -> V_149 = true ;
else
V_140 -> V_149 = false ;
V_140 -> V_126 = V_12 -> V_126 ;
V_140 -> V_150 = V_12 -> V_150 ;
return 0 ;
}
int F_41 ( struct V_19 * V_20 )
{
struct V_151 V_152 ;
V_152 . V_152 = V_153 ;
return F_36 ( V_20 , V_154 ,
V_155 , V_156 , & V_152 ) ;
}
int F_42 ( struct V_19 * V_20 , T_4 * V_157 )
{
int V_22 ;
V_22 = F_36 ( V_20 , V_158 ,
V_131 , 0 , NULL ) ;
if ( ! V_22 ) {
if ( V_20 -> V_159 )
* V_157 = F_43 ( V_20 , V_20 -> V_160 ,
V_20 -> V_161 ) ;
else
* V_157 = V_20 -> V_162 ;
}
return V_22 ;
}
int F_44 ( struct V_19 * V_20 ,
struct V_163 * V_164 )
{
int V_22 ;
struct V_165 * V_166 ;
struct V_167 * V_168 ;
struct V_169 * V_170 ;
T_2 * V_171 ;
T_1 V_172 = 0 ;
if ( ! V_164 -> V_173 ) {
V_172 = ( T_1 ) V_164 -> V_174 ;
if ( ( V_172 < V_20 -> V_146 ) ||
( V_172 > V_20 -> V_144 ) ) {
F_5 ( V_20 -> V_12 -> V_4 , L_22
L_23 ,
V_172 , V_20 -> V_146 ,
V_20 -> V_144 ) ;
return - 1 ;
}
}
V_171 = F_19 ( V_175 , V_90 ) ;
if ( ! V_171 )
return - V_49 ;
V_166 = (struct V_165 * ) V_171 ;
V_166 -> V_117 = F_45 ( V_32 ) ;
if ( ! V_164 -> V_173 ) {
V_166 -> V_25 = F_35 ( 1 ) ;
V_168 = (struct V_167 * )
( V_171 + sizeof( struct V_165 ) ) ;
V_168 -> type = F_45 ( V_176 ) ;
V_168 -> V_177 =
F_45 ( 4 * sizeof( struct V_169 ) ) ;
V_170 = (struct V_169 * )
( V_171 + sizeof( struct V_165 )
+ sizeof( struct V_167 ) ) ;
V_170 -> V_178 = 0x00 ;
V_170 -> V_179 = 0x03 ;
V_170 -> V_180 = V_181 ;
V_170 -> V_182 = 0 ;
V_170 -> V_183 = ( V_184 ) V_172 ;
V_170 -> V_185 = ( V_184 ) V_172 ;
V_170 ++ ;
V_170 -> V_178 = 0x00 ;
V_170 -> V_179 = 0x07 ;
V_170 -> V_180 = V_186 ;
V_170 -> V_182 = 0 ;
V_170 -> V_183 = ( V_184 ) V_172 ;
V_170 -> V_185 = ( V_184 ) V_172 ;
V_170 ++ ;
V_170 -> V_178 = 0x00 ;
V_170 -> V_179 = 0x20 ;
V_170 -> V_180 = V_187 ;
V_170 -> V_182 = 0 ;
V_170 -> V_183 = ( V_184 ) V_172 ;
V_170 -> V_185 = ( V_184 ) V_172 ;
V_170 -> V_188 = V_189 ;
V_170 ++ ;
V_170 -> V_178 = 0x00 ;
V_170 -> V_179 = 0x20 ;
V_170 -> V_180 = V_187 ;
V_170 -> V_182 = 0 ;
V_170 -> V_183 = ( V_184 ) V_172 ;
V_170 -> V_185 = ( V_184 ) V_172 ;
V_170 -> V_188 = V_190 ;
}
V_22 = F_36 ( V_20 , V_191 ,
V_32 , 0 , V_171 ) ;
F_32 ( V_171 ) ;
return V_22 ;
}
int F_46 ( struct V_19 * V_20 , T_4 * V_192 )
{
int V_22 ;
struct V_11 * V_12 = V_20 -> V_12 ;
T_1 V_193 ;
if ( * V_192 )
V_12 -> V_192 = V_194 ;
else
V_12 -> V_192 = V_195 ;
V_193 = ( * V_192 ) ? V_196 : V_155 ;
V_22 = F_36 ( V_20 , V_154 ,
V_193 , V_197 , NULL ) ;
if ( ( ! V_22 ) && ( V_193 == V_155 ) )
V_22 = F_8 ( V_20 ,
V_154 ,
V_198 , 0 , NULL ) ;
return V_22 ;
}
static int F_47 ( struct V_19 * V_20 ,
T_2 * V_199 , T_1 V_200 )
{
if ( V_200 ) {
if ( V_200 > sizeof( V_20 -> V_201 ) ) {
F_5 ( V_20 -> V_12 -> V_4 ,
L_24 ) ;
return - 1 ;
}
memcpy ( V_20 -> V_201 , V_199 , V_200 ) ;
V_20 -> V_202 = ( T_2 ) V_200 ;
F_7 ( V_20 -> V_12 -> V_4 , L_25 ,
V_20 -> V_202 , V_20 -> V_201 [ 0 ] ) ;
if ( V_20 -> V_201 [ 0 ] == V_203 ) {
V_20 -> V_107 . V_204 = true ;
} else if ( V_20 -> V_201 [ 0 ] == V_205 ) {
V_20 -> V_107 . V_206 = true ;
} else {
V_20 -> V_107 . V_204 = false ;
V_20 -> V_107 . V_206 = false ;
}
} else {
memset ( V_20 -> V_201 , 0 , sizeof( V_20 -> V_201 ) ) ;
V_20 -> V_202 = 0 ;
F_7 ( V_20 -> V_12 -> V_4 , L_26 ,
V_20 -> V_202 , V_20 -> V_201 [ 0 ] ) ;
V_20 -> V_107 . V_204 = false ;
V_20 -> V_107 . V_206 = false ;
}
return 0 ;
}
static int F_48 ( struct V_19 * V_20 ,
T_2 * V_199 , T_1 V_200 )
{
if ( V_200 ) {
if ( V_200 > sizeof( V_20 -> V_207 ) ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_27 ) ;
return - 1 ;
}
memcpy ( V_20 -> V_207 , V_199 , V_200 ) ;
V_20 -> V_208 = V_200 ;
F_7 ( V_20 -> V_12 -> V_4 , L_28 ,
V_20 -> V_208 , V_20 -> V_207 [ 0 ] ) ;
if ( V_20 -> V_207 [ 0 ] == V_209 )
V_20 -> V_107 . V_210 = true ;
} else {
memset ( V_20 -> V_207 , 0 , sizeof( V_20 -> V_207 ) ) ;
V_20 -> V_208 = V_200 ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_29 ,
V_20 -> V_208 , V_20 -> V_207 [ 0 ] ) ;
V_20 -> V_107 . V_210 = false ;
}
return 0 ;
}
static int F_49 ( struct V_19 * V_20 ,
T_2 * V_199 , T_1 V_200 )
{
if ( V_200 ) {
if ( V_200 > V_211 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_30 ) ;
return - 1 ;
}
V_20 -> V_212 = F_19 ( V_211 , V_90 ) ;
if ( ! V_20 -> V_212 )
return - V_49 ;
memcpy ( V_20 -> V_212 , V_199 , V_200 ) ;
V_20 -> V_213 = V_200 ;
F_7 ( V_20 -> V_12 -> V_4 , L_31 ,
V_20 -> V_213 , V_20 -> V_212 [ 0 ] ) ;
} else {
F_32 ( V_20 -> V_212 ) ;
V_20 -> V_213 = V_200 ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_32 , V_20 -> V_213 ) ;
}
return 0 ;
}
static int F_50 ( struct V_19 * V_20 ,
struct V_214 * V_215 )
{
return F_36 ( V_20 , V_216 ,
V_32 , V_217 ,
V_215 ) ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_214 * V_215 )
{
int V_22 ;
struct V_218 * V_219 ;
int V_220 ;
if ( V_20 -> V_221 >= V_222 )
V_20 -> V_221 = 0 ;
V_219 = & V_20 -> V_219 [ V_20 -> V_221 ] ;
V_220 = V_215 -> V_223 ;
if ( V_215 -> V_224 ) {
V_20 -> V_107 . V_109 = 0 ;
} else if ( ! V_215 -> V_225 ) {
V_219 = & V_20 -> V_219 [ V_220 ] ;
if ( ! V_219 -> V_226 ) {
F_5 ( V_20 -> V_12 -> V_4 ,
L_33 ) ;
return - 1 ;
}
V_20 -> V_221 = ( T_1 ) V_220 ;
V_20 -> V_107 . V_109 = 1 ;
} else {
V_219 = & V_20 -> V_219 [ V_220 ] ;
memset ( V_219 , 0 , sizeof( struct V_218 ) ) ;
memcpy ( V_219 -> V_227 ,
V_215 -> V_227 ,
V_215 -> V_225 ) ;
V_219 -> V_223 = V_220 ;
V_219 -> V_226 = V_215 -> V_225 ;
V_20 -> V_107 . V_109 = 1 ;
}
if ( V_219 -> V_226 ) {
V_22 = F_8 ( V_20 ,
V_216 ,
V_32 , 0 , NULL ) ;
if ( V_22 )
return V_22 ;
}
if ( V_20 -> V_107 . V_109 )
V_20 -> V_24 |= V_228 ;
else
V_20 -> V_24 &= ~ V_228 ;
V_22 = F_36 ( V_20 , V_33 ,
V_32 , 0 ,
& V_20 -> V_24 ) ;
return V_22 ;
}
static int F_52 ( struct V_19 * V_20 ,
struct V_214 * V_215 )
{
int V_22 ;
T_2 V_229 = false ;
struct V_230 * V_231 ;
if ( V_215 -> V_225 > V_232 ) {
F_5 ( V_20 -> V_12 -> V_4 , L_34 ) ;
return - 1 ;
}
if ( V_20 -> V_67 == V_68 ) {
V_215 -> V_223 = V_233 ;
V_22 = F_8 ( V_20 ,
V_216 ,
V_32 ,
V_217 , V_215 ) ;
if ( V_22 )
return V_22 ;
V_231 = & V_20 -> V_234 ;
memset ( V_231 , 0 ,
sizeof( struct V_230 ) ) ;
memcpy ( V_231 -> V_235 . V_236 , V_215 -> V_227 ,
V_215 -> V_225 ) ;
memcpy ( & V_231 -> V_235 . V_225 , & V_215 -> V_225 ,
sizeof( V_231 -> V_235 . V_225 ) ) ;
V_231 -> V_235 . V_237
= F_45 ( V_238 ) ;
V_231 -> V_235 . V_239 = F_45 ( V_240 ) ;
V_215 -> V_223 = ~ V_233 ;
}
if ( ! V_215 -> V_223 )
V_215 -> V_223 = V_233 ;
if ( V_229 )
V_22 = F_36 ( V_20 ,
V_216 ,
V_32 ,
! V_217 , V_215 ) ;
else
V_22 = F_36 ( V_20 ,
V_216 ,
V_32 ,
V_217 , V_215 ) ;
return V_22 ;
}
static int
F_53 ( struct V_19 * V_20 ,
struct V_214 * V_215 )
{
int V_15 ;
if ( V_215 -> V_241 )
V_15 = F_50 ( V_20 , V_215 ) ;
else if ( V_215 -> V_225 > V_242 )
V_15 = F_52 ( V_20 , V_215 ) ;
else
V_15 = F_51 ( V_20 , V_215 ) ;
return V_15 ;
}
int
F_54 ( struct V_11 * V_12 , char * V_243 ,
int V_244 )
{
union {
T_4 V_245 ;
T_2 V_246 [ 4 ] ;
} V_247 ;
char V_248 [ 32 ] ;
V_247 . V_245 = V_12 -> V_249 ;
sprintf ( V_248 , L_35 , V_247 . V_246 [ 2 ] , V_247 . V_246 [ 1 ] , V_247 . V_246 [ 0 ] , V_247 . V_246 [ 3 ] ) ;
snprintf ( V_243 , V_244 , V_250 , V_248 ) ;
F_7 ( V_12 -> V_4 , L_36 , V_243 ) ;
return 0 ;
}
int F_55 ( struct V_19 * V_20 , struct V_251 * V_252 ,
const T_2 * V_236 , int V_225 , T_2 V_223 ,
const T_2 * V_253 , int V_254 )
{
struct V_214 V_215 ;
memset ( & V_215 , 0 , sizeof( struct V_214 ) ) ;
V_215 . V_225 = V_225 ;
if ( V_252 && V_252 -> V_255 == V_256 )
V_215 . V_257 = true ;
if ( ! V_254 ) {
V_215 . V_223 = V_223 ;
if ( V_225 )
memcpy ( V_215 . V_227 , V_236 , V_225 ) ;
if ( V_253 )
memcpy ( V_215 . V_253 , V_253 , V_10 ) ;
if ( V_252 && V_252 -> V_258 && V_252 -> V_259 )
memcpy ( V_215 . V_260 , V_252 -> V_258 , V_252 -> V_259 ) ;
} else {
V_215 . V_224 = true ;
if ( V_253 )
memcpy ( V_215 . V_253 , V_253 , V_10 ) ;
}
return F_53 ( V_20 , & V_215 ) ;
}
int
F_56 ( struct V_19 * V_20 )
{
struct V_261 V_262 ;
memset ( & V_262 , 0 , sizeof( struct V_263 ) ) ;
if ( F_36 ( V_20 , V_264 ,
V_131 , 0 , & V_262 ) )
return - 1 ;
return 0 ;
}
int
F_57 ( struct V_19 * V_20 , T_1 V_117 ,
struct V_265 * V_266 ,
unsigned int V_267 )
{
struct V_268 V_269 ;
T_2 V_270 ;
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
V_269 . V_117 = F_45 ( V_117 ) ;
if ( V_117 == V_32 ) {
V_269 . V_271 = V_266 -> V_60 ;
V_270 = F_58 ( V_272 ) ;
V_269 . V_271 |= ( V_270 << 2 ) ;
V_269 . V_103 =
F_59 ( V_266 -> V_273 ) ;
V_269 . V_267 = F_35 ( V_267 ) ;
}
if ( F_36 ( V_20 , V_274 ,
V_117 , 0 , & V_269 ) ) {
F_5 ( V_20 -> V_12 -> V_4 , L_37 ) ;
return - 1 ;
}
return V_269 . V_15 ;
}
int
F_60 ( struct V_19 * V_20 , T_2 V_275 )
{
if ( F_61 ( V_20 ) == V_275 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_38 ) ;
return 0 ;
}
F_62 ( V_20 ) ;
F_63 ( V_20 ) ;
V_20 -> V_275 = V_275 ;
switch ( V_275 ) {
case V_276 :
V_20 -> V_67 = V_277 ;
break;
case V_137 :
case V_278 :
default:
V_20 -> V_67 = V_69 ;
break;
}
F_36 ( V_20 , V_279 ,
V_32 , 0 , NULL ) ;
return F_64 ( V_20 , false ) ;
}
int
F_65 ( struct V_19 * V_20 ,
struct V_280 * log )
{
return F_36 ( V_20 , V_281 ,
V_131 , 0 , log ) ;
}
static int F_66 ( struct V_19 * V_20 ,
struct V_282 * V_283 ,
T_1 V_117 )
{
T_1 V_284 ;
switch ( F_34 ( V_283 -> type ) ) {
case V_285 :
V_284 = V_286 ;
break;
case V_287 :
V_284 = V_288 ;
break;
case V_289 :
V_284 = V_290 ;
break;
case V_291 :
V_284 = V_292 ;
break;
case V_293 :
V_284 = V_294 ;
break;
default:
return - 1 ;
}
return F_36 ( V_20 , V_284 , V_117 , 0 , V_283 ) ;
}
int
F_67 ( struct V_19 * V_20 , T_4 V_295 ,
T_4 V_296 , T_4 V_297 )
{
struct V_282 V_283 ;
V_283 . type = F_35 ( V_295 ) ;
V_283 . V_298 = F_35 ( V_296 ) ;
V_283 . V_299 = F_35 ( V_297 ) ;
return F_66 ( V_20 , & V_283 , V_32 ) ;
}
int
F_68 ( struct V_19 * V_20 , T_4 V_295 ,
T_4 V_296 , T_4 * V_299 )
{
int V_22 ;
struct V_282 V_283 ;
V_283 . type = F_35 ( V_295 ) ;
V_283 . V_298 = F_35 ( V_296 ) ;
V_22 = F_66 ( V_20 , & V_283 , V_131 ) ;
if ( V_22 )
goto V_91;
* V_299 = F_34 ( V_283 . V_299 ) ;
V_91:
return V_22 ;
}
int
F_69 ( struct V_19 * V_20 , T_1 V_298 , T_1 V_300 ,
T_2 * V_299 )
{
int V_22 ;
struct V_301 V_302 ;
V_302 . V_298 = F_45 ( ( T_1 ) V_298 ) ;
V_302 . V_303 = F_45 ( ( T_1 ) V_300 ) ;
V_22 = F_36 ( V_20 , V_304 ,
V_131 , 0 , & V_302 ) ;
if ( ! V_22 )
memcpy ( V_299 , V_302 . V_299 , V_305 ) ;
return V_22 ;
}
static int
F_70 ( struct V_19 * V_20 , T_2 * V_199 ,
T_1 V_200 )
{
int V_22 = 0 ;
struct V_306 * V_307 ;
const T_2 V_308 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_309 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_200 ) {
V_20 -> V_310 = 0 ;
V_20 -> V_311 . V_312 = false ;
return 0 ;
} else if ( ! V_199 ) {
return - 1 ;
}
V_307 = (struct V_306 * ) V_199 ;
if ( ( ( V_307 -> V_313 == V_203 ) &&
( ! memcmp ( V_307 -> V_314 , V_308 , sizeof( V_308 ) ) ) ) ||
( V_307 -> V_313 == V_205 ) ) {
V_22 = F_47 ( V_20 , V_199 , V_200 ) ;
V_20 -> V_311 . V_312 = false ;
return V_22 ;
} else if ( V_307 -> V_313 == V_209 ) {
V_22 = F_48 ( V_20 , V_199 , V_200 ) ;
return V_22 ;
}
if ( V_200 < ( sizeof( V_20 -> V_315 ) - V_20 -> V_310 ) ) {
V_307 = (struct V_306 * ) V_199 ;
if ( ( V_307 -> V_313 == V_203 ) &&
( ! memcmp ( V_307 -> V_314 , V_309 , sizeof( V_309 ) ) ) ) {
V_20 -> V_311 . V_312 = true ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_39 ) ;
V_22 = F_49 ( V_20 , V_199 , V_200 ) ;
}
memcpy ( V_20 -> V_315 + V_20 -> V_310 , V_199 ,
V_200 ) ;
V_20 -> V_310 += V_200 ;
} else {
V_22 = - 1 ;
}
return V_22 ;
}
static int F_71 ( struct V_19 * V_20 ,
struct V_316 * V_317 ,
T_1 V_117 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
switch ( V_317 -> type ) {
case V_318 :
if ( V_117 == V_131 ) {
V_317 -> V_45 = V_20 -> V_202 ;
memcpy ( V_317 -> V_319 , V_20 -> V_201 , V_317 -> V_45 ) ;
} else {
F_70 ( V_20 , V_317 -> V_319 ,
( T_1 ) V_317 -> V_45 ) ;
}
break;
case V_320 :
memset ( V_12 -> V_321 , 0 , sizeof( V_12 -> V_321 ) ) ;
if ( V_317 -> V_45 > V_322 ) {
V_12 -> V_323 = 0 ;
F_5 ( V_12 -> V_4 , L_40 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_321 , V_317 -> V_319 ,
V_317 -> V_45 ) ;
V_12 -> V_323 = V_317 -> V_45 ;
}
break;
default:
F_5 ( V_12 -> V_4 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
int
F_72 ( struct V_19 * V_20 , T_2 * V_324 , int V_200 )
{
struct V_316 V_317 ;
if ( V_200 > V_325 )
return - V_326 ;
V_317 . type = V_318 ;
V_317 . V_45 = V_200 ;
memcpy ( V_317 . V_319 , V_324 , V_200 ) ;
if ( F_71 ( V_20 , & V_317 , V_32 ) )
return - V_326 ;
return 0 ;
}
