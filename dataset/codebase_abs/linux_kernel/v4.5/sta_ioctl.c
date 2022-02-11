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
* ( V_14 -> V_18 ) ,
( 12 * V_19 ) ) ;
if ( V_15 <= 0 ) {
if ( V_15 == 0 )
V_15 = - V_20 ;
F_5 ( V_12 , ERROR , L_1 ,
V_15 ) ;
F_6 ( V_12 ) ;
return V_15 ;
}
V_15 = V_12 -> V_16 . V_15 ;
V_12 -> V_16 . V_15 = 0 ;
return V_15 ;
}
int F_7 ( struct V_21 * V_22 ,
struct V_1 * V_23 )
{
int V_24 = 0 ;
T_1 V_25 ;
V_25 = V_22 -> V_26 ;
if ( V_23 -> V_27 == V_28 ) {
F_5 ( V_22 -> V_12 , V_29 ,
L_2 ) ;
V_22 -> V_26 |= V_30 ;
V_22 -> V_26 &=
~ V_31 ;
} else {
V_22 -> V_26 &= ~ V_30 ;
if ( V_23 -> V_27 == V_32 ) {
F_5 ( V_22 -> V_12 , V_29 ,
L_3 ) ;
V_22 -> V_26 |=
V_31 ;
} else {
V_22 -> V_26 &=
~ V_31 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_4 ,
V_23 -> V_33 ) ;
V_24 = F_8 ( V_22 ,
V_34 ,
V_35 , 0 ,
V_23 , false ) ;
}
}
F_5 ( V_22 -> V_12 , V_29 ,
L_5 ,
V_25 , V_22 -> V_26 ) ;
if ( V_25 != V_22 -> V_26 ) {
V_24 = F_8 ( V_22 , V_36 ,
V_35 ,
0 , & V_22 -> V_26 , false ) ;
}
return V_24 ;
}
int F_9 ( struct V_21 * V_22 ,
struct V_37 * V_38 ,
struct V_39 * V_40 )
{
T_2 * V_41 ;
T_3 V_42 ;
struct V_43 * V_44 = ( void * ) V_38 -> V_22 ;
const struct V_45 * V_46 ;
F_10 () ;
V_46 = F_11 ( V_38 -> V_46 ) ;
V_41 = F_12 ( V_46 -> V_47 , V_46 -> V_48 , V_49 ) ;
V_42 = V_46 -> V_48 ;
V_40 -> V_50 = V_46 -> V_51 ;
F_13 () ;
if ( ! V_41 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_6 ) ;
return - V_52 ;
}
memcpy ( V_40 -> V_53 , V_38 -> V_54 , V_10 ) ;
V_40 -> V_55 = V_38 -> signal ;
V_40 -> V_56 = V_41 ;
V_40 -> V_57 = V_42 ;
V_40 -> V_58 = V_38 -> V_59 ;
V_40 -> V_60 = V_38 -> V_61 ;
V_40 -> V_62 = V_44 -> V_63 ;
V_40 -> V_64 = V_44 -> V_64 ;
if ( V_40 -> V_60 & V_65 ) {
F_5 ( V_22 -> V_12 , V_29 ,
L_7 ) ;
V_40 -> V_66 = V_67 ;
} else {
V_40 -> V_66 = V_68 ;
}
if ( V_40 -> V_60 & V_69 )
V_40 -> V_70 = V_71 ;
else
V_40 -> V_70 = V_72 ;
V_40 -> V_73 = true ;
if ( V_40 -> V_60 & V_74 )
V_40 -> V_75 = true ;
return F_14 ( V_22 -> V_12 , V_40 ) ;
}
void F_15 ( struct V_21 * V_22 )
{
if ( V_22 -> V_12 -> V_76 ) {
char V_77 [] = { L_8 } ;
memcpy ( & V_77 [ 8 ] , V_22 -> V_12 -> V_78 , 2 ) ;
F_16 ( V_22 , V_22 -> V_12 -> V_76 , V_77 ) ;
}
}
static int F_17 ( struct V_21 * V_22 ,
struct V_37 * V_38 )
{
const T_2 * V_79 ;
T_2 V_80 ;
struct V_81 * V_82 =
& V_22 -> V_12 -> V_83 ;
F_10 () ;
V_79 = F_18 ( V_38 , V_84 ) ;
if ( ! V_79 ) {
F_13 () ;
return 0 ;
}
V_80 = V_79 [ 1 ] ;
if ( V_80 < V_85 ) {
F_13 () ;
return 0 ;
}
if ( ! strncmp ( V_22 -> V_12 -> V_78 , & V_79 [ 2 ] , 2 ) ) {
F_13 () ;
F_5 ( V_22 -> V_12 , V_29 ,
L_9 ) ;
return 0 ;
}
memcpy ( V_22 -> V_12 -> V_78 , & V_79 [ 2 ] , 2 ) ;
V_82 -> V_78 [ 0 ] = V_79 [ 2 ] ;
V_82 -> V_78 [ 1 ] = V_79 [ 3 ] ;
V_82 -> V_78 [ 2 ] = ' ' ;
V_80 -= V_86 ;
V_82 -> V_87 =
V_80 / sizeof( struct V_88 ) ;
memcpy ( ( T_2 * ) V_82 -> V_89 ,
& V_79 [ 2 ] + V_86 , V_80 ) ;
F_13 () ;
if ( F_8 ( V_22 , V_90 ,
V_35 , 0 , NULL , false ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_10 ) ;
return - 1 ;
}
F_15 ( V_22 ) ;
return 0 ;
}
int F_19 ( struct V_21 * V_22 , struct V_37 * V_38 ,
struct V_91 * V_92 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 = NULL ;
V_22 -> V_93 = false ;
if ( V_38 ) {
if ( V_12 -> V_94 == 0x00 )
F_17 ( V_22 , V_38 ) ;
V_40 = F_20 ( sizeof( struct V_39 ) ,
V_95 ) ;
if ( ! V_40 )
return - V_52 ;
V_24 = F_9 ( V_22 , V_38 , V_40 ) ;
if ( V_24 )
goto V_96;
}
if ( V_22 -> V_70 == V_72 ||
V_22 -> V_70 == V_97 ) {
T_2 V_98 ;
if ( ! V_40 )
return - 1 ;
if ( F_21 ( V_40 -> V_62 ) ==
V_99 ) {
V_98 = V_100 | V_101 | V_102 ;
} else {
V_98 = V_103 | V_104 ;
if ( V_12 -> V_105 & V_106 )
V_98 |= V_106 ;
}
if ( ! ( ( V_98 | V_12 -> V_105 ) & ~ V_12 -> V_105 ) )
V_12 -> V_98 = V_98 ;
V_24 = F_22 ( V_22 , V_40 ) ;
if ( V_24 )
goto V_96;
if ( F_23 ( V_22 ) ==
( T_2 ) V_40 -> V_107 ) {
F_5 ( V_12 , ERROR ,
L_11 ,
V_40 -> V_107 ) ;
goto V_96;
}
F_5 ( V_12 , V_29 ,
L_12
L_13 ) ;
F_24 ( V_22 -> V_108 , V_12 ) ;
if ( F_25 ( V_22 -> V_108 ) )
F_26 ( V_22 -> V_108 ) ;
V_22 -> V_109 = 0 ;
V_24 = F_27 ( V_22 , V_40 ) ;
if ( V_24 == V_110 &&
V_22 -> V_111 . V_112 &&
V_22 -> V_111 . V_113 ) {
V_22 -> V_111 . V_114 =
V_115 ;
V_24 = F_27 ( V_22 , V_40 ) ;
}
if ( V_38 )
F_28 ( V_22 -> V_12 -> V_116 , V_38 ) ;
} else {
if ( V_40 && V_40 -> V_117 . V_118 &&
( ! F_29 ( & V_22 -> V_119 . V_120 .
V_117 , & V_40 -> V_117 ) ) ) {
V_24 = 0 ;
goto V_96;
}
V_22 -> V_121 = false ;
V_24 = F_22 ( V_22 , V_40 ) ;
F_24 ( V_22 -> V_108 , V_12 ) ;
if ( F_25 ( V_22 -> V_108 ) )
F_26 ( V_22 -> V_108 ) ;
if ( ! V_24 ) {
F_5 ( V_12 , V_29 ,
L_14
L_15 ) ;
V_24 = F_30 ( V_22 , V_40 ) ;
if ( V_38 )
F_28 ( V_22 -> V_12 -> V_116 , V_38 ) ;
} else {
F_5 ( V_12 , V_29 ,
L_16
L_17 ,
V_92 -> V_117 ) ;
V_24 = F_31 ( V_22 , V_92 ) ;
}
}
V_96:
if ( V_40 )
F_32 ( V_40 -> V_56 ) ;
F_32 ( V_40 ) ;
return V_24 ;
}
int F_33 ( struct V_21 * V_22 , T_1 V_122 ,
int V_123 , struct V_124 * V_125 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_15 = 0 ;
T_4 V_126 = 0 ;
if ( ! V_125 )
return - V_52 ;
switch ( V_122 ) {
case V_35 :
if ( V_12 -> V_127 ) {
F_5 ( V_12 , V_29 ,
L_18
L_19 ) ;
V_15 = - 1 ;
break;
}
if ( V_125 -> V_128 ) {
if ( V_125 -> V_129 == V_130 ) {
if ( ! V_12 -> V_131 )
break;
V_126 = F_34 ( V_12 -> V_125
. V_129 ) ;
V_12 -> V_125 . V_129 =
F_35 ( V_125 -> V_129 ) ;
} else if ( V_125 -> V_129 ) {
V_12 -> V_125 . V_129 =
F_35 ( V_125 -> V_129 ) ;
V_12 -> V_125 . V_132 = ( T_2 ) V_125 -> V_132 ;
if ( V_125 -> V_133 )
V_12 -> V_125 . V_133 = ( T_2 ) V_125 -> V_133 ;
} else if ( V_12 -> V_125 . V_129 ==
F_35 ( V_130 ) ) {
V_15 = - 1 ;
break;
}
V_15 = F_8 ( V_22 ,
V_134 ,
V_35 , 0 ,
& V_12 -> V_125 ,
V_123 == V_135 ) ;
if ( V_125 -> V_129 == V_130 )
V_12 -> V_125 . V_129 =
F_35 ( V_126 ) ;
} else {
V_12 -> V_125 . V_129 =
F_35 ( V_125 -> V_129 ) ;
V_12 -> V_125 . V_132 = ( T_2 ) V_125 -> V_132 ;
V_12 -> V_125 . V_133 = ( T_2 ) V_125 -> V_133 ;
}
break;
case V_136 :
V_125 -> V_129 = F_34 ( V_12 -> V_125 . V_129 ) ;
V_125 -> V_132 = V_12 -> V_125 . V_132 ;
V_125 -> V_133 = V_12 -> V_125 . V_133 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_36 ( struct V_21 * V_22 , int V_123 )
{
struct V_124 V_137 ;
V_137 . V_129 = V_130 ;
V_137 . V_128 = true ;
return F_33 ( V_22 , V_35 ,
V_123 , & V_137 ) ;
}
int F_37 ( struct V_11 * V_12 )
{
struct V_124 V_137 ;
struct V_21 * V_22 ;
int V_5 ;
if ( V_138 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_139 ; V_5 ++ ) {
V_22 = V_12 -> V_22 [ V_5 ] ;
if ( V_22 )
F_38 ( V_22 , NULL ) ;
}
}
if ( V_12 -> V_140 ) {
F_5 ( V_12 , V_141 ,
L_20 ) ;
return true ;
}
V_12 -> V_142 = false ;
memset ( & V_137 , 0 , sizeof( struct V_124 ) ) ;
V_137 . V_128 = true ;
V_12 -> V_143 = true ;
F_6 ( V_12 ) ;
if ( F_33 ( F_39 ( V_12 ,
V_144 ) ,
V_35 , V_135 ,
& V_137 ) ) {
F_5 ( V_12 , ERROR ,
L_21 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_145 ,
V_12 -> V_142 ,
( 10 * V_19 ) ) <= 0 ) {
F_5 ( V_12 , ERROR ,
L_22 ) ;
return false ;
}
return true ;
}
int F_40 ( struct V_21 * V_22 ,
struct V_146 * V_147 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 ;
if ( ! V_147 )
return - 1 ;
V_40 = & V_22 -> V_119 . V_120 ;
V_147 -> V_70 = V_22 -> V_70 ;
memcpy ( & V_147 -> V_117 , & V_40 -> V_117 , sizeof( struct V_91 ) ) ;
memcpy ( & V_147 -> V_54 , & V_40 -> V_53 , V_10 ) ;
V_147 -> V_148 = V_40 -> V_107 ;
memcpy ( V_147 -> V_78 , V_12 -> V_78 ,
V_86 ) ;
V_147 -> V_149 = V_22 -> V_149 ;
V_147 -> V_150 = V_22 -> V_151 ;
V_147 -> V_152 = V_22 -> V_153 ;
V_147 -> V_154 = V_22 -> V_154 ;
V_147 -> V_155 = V_22 -> V_155 ;
if ( V_22 -> V_111 . V_113 )
V_147 -> V_156 = true ;
else
V_147 -> V_156 = false ;
V_147 -> V_131 = V_12 -> V_131 ;
V_147 -> V_157 = V_12 -> V_157 ;
return 0 ;
}
int F_41 ( struct V_21 * V_22 )
{
struct V_158 V_159 ;
V_159 . V_159 = V_160 ;
return F_8 ( V_22 , V_161 ,
V_162 , V_163 , & V_159 , true ) ;
}
int F_42 ( struct V_21 * V_22 , T_4 * V_164 )
{
int V_24 ;
V_24 = F_8 ( V_22 , V_165 ,
V_136 , 0 , NULL , true ) ;
if ( ! V_24 ) {
if ( V_22 -> V_166 )
* V_164 = F_43 ( V_22 , V_22 -> V_167 ,
V_22 -> V_168 ) ;
else
* V_164 = V_22 -> V_169 ;
}
return V_24 ;
}
int F_44 ( struct V_21 * V_22 ,
struct V_170 * V_171 )
{
int V_24 ;
struct V_172 * V_173 ;
struct V_174 * V_175 ;
struct V_176 * V_177 ;
T_2 * V_178 ;
T_1 V_179 = 0 ;
if ( ! V_171 -> V_180 ) {
V_179 = ( T_1 ) V_171 -> V_181 ;
if ( ( V_179 < V_22 -> V_153 ) ||
( V_179 > V_22 -> V_151 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_23
L_24 ,
V_179 , V_22 -> V_153 ,
V_22 -> V_151 ) ;
return - 1 ;
}
}
V_178 = F_20 ( V_182 , V_95 ) ;
if ( ! V_178 )
return - V_52 ;
V_173 = (struct V_172 * ) V_178 ;
V_173 -> V_122 = F_45 ( V_35 ) ;
if ( ! V_171 -> V_180 ) {
V_173 -> V_27 = F_35 ( 1 ) ;
V_175 = (struct V_174 * )
( V_178 + sizeof( struct V_172 ) ) ;
V_175 -> type = F_45 ( V_183 ) ;
V_175 -> V_184 =
F_45 ( 4 * sizeof( struct V_176 ) ) ;
V_177 = (struct V_176 * )
( V_178 + sizeof( struct V_172 )
+ sizeof( struct V_174 ) ) ;
V_177 -> V_185 = 0x00 ;
V_177 -> V_186 = 0x03 ;
V_177 -> V_187 = V_188 ;
V_177 -> V_189 = 0 ;
V_177 -> V_190 = ( V_191 ) V_179 ;
V_177 -> V_192 = ( V_191 ) V_179 ;
V_177 ++ ;
V_177 -> V_185 = 0x00 ;
V_177 -> V_186 = 0x07 ;
V_177 -> V_187 = V_193 ;
V_177 -> V_189 = 0 ;
V_177 -> V_190 = ( V_191 ) V_179 ;
V_177 -> V_192 = ( V_191 ) V_179 ;
V_177 ++ ;
V_177 -> V_185 = 0x00 ;
V_177 -> V_186 = 0x20 ;
V_177 -> V_187 = V_194 ;
V_177 -> V_189 = 0 ;
V_177 -> V_190 = ( V_191 ) V_179 ;
V_177 -> V_192 = ( V_191 ) V_179 ;
V_177 -> V_195 = V_196 ;
V_177 ++ ;
V_177 -> V_185 = 0x00 ;
V_177 -> V_186 = 0x20 ;
V_177 -> V_187 = V_194 ;
V_177 -> V_189 = 0 ;
V_177 -> V_190 = ( V_191 ) V_179 ;
V_177 -> V_192 = ( V_191 ) V_179 ;
V_177 -> V_195 = V_197 ;
}
V_24 = F_8 ( V_22 , V_198 ,
V_35 , 0 , V_178 , true ) ;
F_32 ( V_178 ) ;
return V_24 ;
}
int F_46 ( struct V_21 * V_22 , T_4 * V_199 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_200 ;
if ( * V_199 )
V_12 -> V_199 = V_201 ;
else
V_12 -> V_199 = V_202 ;
V_200 = ( * V_199 ) ? V_203 : V_162 ;
V_24 = F_8 ( V_22 , V_161 ,
V_200 , V_204 , NULL , true ) ;
if ( ( ! V_24 ) && ( V_200 == V_162 ) )
V_24 = F_8 ( V_22 , V_161 ,
V_205 , 0 , NULL , false ) ;
return V_24 ;
}
static int F_47 ( struct V_21 * V_22 ,
T_2 * V_206 , T_1 V_207 )
{
if ( V_207 ) {
if ( V_207 > sizeof( V_22 -> V_208 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_25 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_208 , V_206 , V_207 ) ;
V_22 -> V_209 = V_207 ;
F_5 ( V_22 -> V_12 , V_141 ,
L_26 ,
V_22 -> V_209 , V_22 -> V_208 [ 0 ] ) ;
if ( V_22 -> V_208 [ 0 ] == V_210 ) {
V_22 -> V_111 . V_211 = true ;
} else if ( V_22 -> V_208 [ 0 ] == V_212 ) {
V_22 -> V_111 . V_213 = true ;
} else {
V_22 -> V_111 . V_211 = false ;
V_22 -> V_111 . V_213 = false ;
}
} else {
memset ( V_22 -> V_208 , 0 , sizeof( V_22 -> V_208 ) ) ;
V_22 -> V_209 = 0 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_27 ,
V_22 -> V_209 , V_22 -> V_208 [ 0 ] ) ;
V_22 -> V_111 . V_211 = false ;
V_22 -> V_111 . V_213 = false ;
}
return 0 ;
}
static int F_48 ( struct V_21 * V_22 ,
T_2 * V_206 , T_1 V_207 )
{
if ( V_207 ) {
if ( V_207 > sizeof( V_22 -> V_214 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_28 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_214 , V_206 , V_207 ) ;
V_22 -> V_215 = V_207 ;
F_5 ( V_22 -> V_12 , V_141 ,
L_29 ,
V_22 -> V_215 , V_22 -> V_214 [ 0 ] ) ;
if ( V_22 -> V_214 [ 0 ] == V_216 )
V_22 -> V_111 . V_217 = true ;
} else {
memset ( V_22 -> V_214 , 0 , sizeof( V_22 -> V_214 ) ) ;
V_22 -> V_215 = V_207 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_30 ,
V_22 -> V_215 , V_22 -> V_214 [ 0 ] ) ;
V_22 -> V_111 . V_217 = false ;
}
return 0 ;
}
static int F_49 ( struct V_21 * V_22 ,
T_2 * V_206 , T_1 V_207 )
{
if ( V_207 ) {
if ( V_207 > V_218 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_31 ) ;
return - 1 ;
}
V_22 -> V_219 = F_20 ( V_218 , V_95 ) ;
if ( ! V_22 -> V_219 )
return - V_52 ;
memcpy ( V_22 -> V_219 , V_206 , V_207 ) ;
V_22 -> V_220 = V_207 ;
F_5 ( V_22 -> V_12 , V_141 ,
L_32 ,
V_22 -> V_220 , V_22 -> V_219 [ 0 ] ) ;
} else {
F_32 ( V_22 -> V_219 ) ;
V_22 -> V_220 = V_207 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_33 , V_22 -> V_220 ) ;
}
return 0 ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_221 * V_222 )
{
return F_8 ( V_22 , V_223 ,
V_35 , V_224 ,
V_222 , true ) ;
}
static int F_51 ( struct V_21 * V_22 ,
struct V_221 * V_222 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_24 ;
struct V_225 * V_226 ;
int V_227 ;
if ( V_22 -> V_228 >= V_229 )
V_22 -> V_228 = 0 ;
V_226 = & V_22 -> V_226 [ V_22 -> V_228 ] ;
V_227 = V_222 -> V_230 ;
if ( V_222 -> V_231 ) {
V_22 -> V_111 . V_113 = 0 ;
} else if ( ! V_222 -> V_232 ) {
V_226 = & V_22 -> V_226 [ V_227 ] ;
if ( ! V_226 -> V_233 ) {
F_5 ( V_12 , ERROR ,
L_34 ) ;
return - 1 ;
}
if ( V_12 -> V_234 == V_235 ) {
memcpy ( V_222 -> V_236 ,
V_226 -> V_236 , V_226 -> V_233 ) ;
V_222 -> V_232 = V_226 -> V_233 ;
}
V_22 -> V_228 = ( T_1 ) V_227 ;
V_22 -> V_111 . V_113 = 1 ;
} else {
V_226 = & V_22 -> V_226 [ V_227 ] ;
memset ( V_226 , 0 , sizeof( struct V_225 ) ) ;
memcpy ( V_226 -> V_236 ,
V_222 -> V_236 ,
V_222 -> V_232 ) ;
V_226 -> V_230 = V_227 ;
V_226 -> V_233 = V_222 -> V_232 ;
V_22 -> V_111 . V_113 = 1 ;
}
if ( V_226 -> V_233 ) {
void * V_237 ;
if ( V_222 -> V_231 ) {
memset ( & V_22 -> V_226 [ V_227 ] , 0 ,
sizeof( struct V_225 ) ) ;
goto V_96;
}
if ( V_12 -> V_234 == V_235 )
V_237 = V_222 ;
else
V_237 = NULL ;
V_24 = F_8 ( V_22 , V_223 ,
V_35 , 0 , V_237 , false ) ;
if ( V_24 )
return V_24 ;
}
V_96:
if ( V_22 -> V_111 . V_113 )
V_22 -> V_26 |= V_238 ;
else
V_22 -> V_26 &= ~ V_238 ;
V_24 = F_8 ( V_22 , V_36 ,
V_35 , 0 ,
& V_22 -> V_26 , true ) ;
return V_24 ;
}
static int F_52 ( struct V_21 * V_22 ,
struct V_221 * V_222 )
{
int V_24 ;
T_2 V_239 = false ;
struct V_240 * V_241 ;
if ( V_222 -> V_232 > V_242 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_35 ) ;
return - 1 ;
}
if ( V_22 -> V_70 == V_71 ) {
V_222 -> V_230 = V_243 ;
V_24 = F_8 ( V_22 , V_223 ,
V_35 ,
V_224 , V_222 , false ) ;
if ( V_24 )
return V_24 ;
V_241 = & V_22 -> V_244 ;
memset ( V_241 , 0 ,
sizeof( struct V_240 ) ) ;
memcpy ( V_241 -> V_245 . V_246 , V_222 -> V_236 ,
V_222 -> V_232 ) ;
memcpy ( & V_241 -> V_245 . V_232 , & V_222 -> V_232 ,
sizeof( V_241 -> V_245 . V_232 ) ) ;
V_241 -> V_245 . V_247
= F_45 ( V_248 ) ;
V_241 -> V_245 . V_249 = F_45 ( V_250 ) ;
V_222 -> V_230 = ~ V_243 ;
}
if ( ! V_222 -> V_230 )
V_222 -> V_230 = V_243 ;
if ( V_239 )
V_24 = F_8 ( V_22 , V_223 ,
V_35 ,
! V_224 , V_222 , true ) ;
else
V_24 = F_8 ( V_22 , V_223 ,
V_35 ,
V_224 , V_222 , true ) ;
return V_24 ;
}
static int
F_53 ( struct V_21 * V_22 ,
struct V_221 * V_222 )
{
int V_15 ;
if ( V_222 -> V_251 )
V_15 = F_50 ( V_22 , V_222 ) ;
else if ( V_222 -> V_232 > V_252 )
V_15 = F_52 ( V_22 , V_222 ) ;
else
V_15 = F_51 ( V_22 , V_222 ) ;
return V_15 ;
}
int
F_54 ( struct V_11 * V_12 , char * V_253 ,
int V_254 )
{
union {
T_5 V_255 ;
T_2 V_256 [ 4 ] ;
} V_257 ;
char V_258 [ 32 ] ;
V_257 . V_255 = F_35 ( V_12 -> V_259 ) ;
sprintf ( V_258 , L_36 , V_257 . V_256 [ 2 ] , V_257 . V_256 [ 1 ] , V_257 . V_256 [ 0 ] , V_257 . V_256 [ 3 ] ) ;
snprintf ( V_253 , V_254 , V_260 , V_258 ) ;
F_5 ( V_12 , V_261 , L_37 , V_253 ) ;
return 0 ;
}
int F_55 ( struct V_21 * V_22 , struct V_262 * V_263 ,
const T_2 * V_246 , int V_232 , T_2 V_230 ,
const T_2 * V_264 , int V_265 )
{
struct V_221 V_222 ;
memset ( & V_222 , 0 , sizeof( struct V_221 ) ) ;
V_222 . V_232 = V_232 ;
V_222 . V_230 = V_230 ;
if ( V_263 && V_263 -> V_266 == V_267 )
V_222 . V_268 = true ;
if ( ! V_265 ) {
if ( V_232 )
memcpy ( V_222 . V_236 , V_246 , V_232 ) ;
else
V_222 . V_269 = true ;
if ( V_264 )
memcpy ( V_222 . V_264 , V_264 , V_10 ) ;
if ( V_263 && V_263 -> V_270 && V_263 -> V_271 ) {
memcpy ( V_222 . V_272 , V_263 -> V_270 , V_263 -> V_271 ) ;
V_222 . V_273 = V_263 -> V_271 ;
V_222 . V_274 = true ;
}
} else {
if ( F_56 ( V_22 ) == V_275 )
return 0 ;
V_222 . V_231 = true ;
if ( V_264 )
memcpy ( V_222 . V_264 , V_264 , V_10 ) ;
}
return F_53 ( V_22 , & V_222 ) ;
}
int
F_57 ( struct V_21 * V_22 )
{
struct V_276 V_277 ;
memset ( & V_277 , 0 , sizeof( struct V_278 ) ) ;
if ( F_8 ( V_22 , V_279 ,
V_136 , 0 , & V_277 , true ) )
return - 1 ;
return 0 ;
}
int
F_58 ( struct V_21 * V_22 , T_1 V_122 ,
struct V_280 * V_281 ,
unsigned int V_282 )
{
struct V_283 V_284 ;
T_2 V_285 ;
memset ( & V_284 , 0 , sizeof( V_284 ) ) ;
V_284 . V_122 = F_45 ( V_122 ) ;
if ( V_122 == V_35 ) {
V_284 . V_286 = V_281 -> V_63 ;
V_285 = F_59 ( V_287 ) ;
V_284 . V_286 |= ( V_285 << 2 ) ;
V_284 . V_107 =
F_60 ( V_281 -> V_288 ) ;
V_284 . V_282 = F_35 ( V_282 ) ;
}
if ( F_8 ( V_22 , V_289 ,
V_122 , 0 , & V_284 , true ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_38 ) ;
return - 1 ;
}
return V_284 . V_15 ;
}
int
F_61 ( struct V_21 * V_22 ,
struct V_290 * log )
{
return F_8 ( V_22 , V_291 ,
V_136 , 0 , log , true ) ;
}
static int F_62 ( struct V_21 * V_22 ,
struct V_292 * V_293 ,
T_1 V_122 )
{
T_1 V_294 ;
switch ( F_34 ( V_293 -> type ) ) {
case V_295 :
V_294 = V_296 ;
break;
case V_297 :
V_294 = V_298 ;
break;
case V_299 :
V_294 = V_300 ;
break;
case V_301 :
V_294 = V_302 ;
break;
case V_303 :
V_294 = V_304 ;
break;
default:
return - 1 ;
}
return F_8 ( V_22 , V_294 , V_122 , 0 , V_293 , true ) ;
}
int
F_63 ( struct V_21 * V_22 , T_4 V_305 ,
T_4 V_306 , T_4 V_307 )
{
struct V_292 V_293 ;
V_293 . type = F_35 ( V_305 ) ;
V_293 . V_308 = F_35 ( V_306 ) ;
V_293 . V_309 = F_35 ( V_307 ) ;
return F_62 ( V_22 , & V_293 , V_35 ) ;
}
int
F_64 ( struct V_21 * V_22 , T_4 V_305 ,
T_4 V_306 , T_4 * V_309 )
{
int V_24 ;
struct V_292 V_293 ;
V_293 . type = F_35 ( V_305 ) ;
V_293 . V_308 = F_35 ( V_306 ) ;
V_24 = F_62 ( V_22 , & V_293 , V_136 ) ;
if ( V_24 )
goto V_96;
* V_309 = F_34 ( V_293 . V_309 ) ;
V_96:
return V_24 ;
}
int
F_65 ( struct V_21 * V_22 , T_1 V_308 , T_1 V_310 ,
T_2 * V_309 )
{
int V_24 ;
struct V_311 V_312 ;
V_312 . V_308 = F_45 ( ( T_1 ) V_308 ) ;
V_312 . V_313 = F_45 ( ( T_1 ) V_310 ) ;
V_24 = F_8 ( V_22 , V_314 ,
V_136 , 0 , & V_312 , true ) ;
if ( ! V_24 )
memcpy ( V_309 , V_312 . V_309 , V_315 ) ;
return V_24 ;
}
static int
F_66 ( struct V_21 * V_22 , T_2 * V_206 ,
T_1 V_207 )
{
int V_24 = 0 ;
struct V_316 * V_317 ;
const T_2 V_318 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_319 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
T_1 V_320 = V_207 ;
int V_321 = 0 ;
if ( ! V_207 ) {
V_22 -> V_322 = 0 ;
V_22 -> V_323 . V_324 = false ;
return 0 ;
} else if ( ! V_206 ) {
return - 1 ;
}
V_317 = (struct V_316 * ) V_206 ;
while ( V_317 ) {
if ( V_317 -> V_325 == V_210 ) {
if ( ! memcmp ( V_317 -> V_326 , V_318 ,
sizeof( V_318 ) ) ) {
V_321 = 1 ;
break;
}
if ( ! memcmp ( V_317 -> V_326 , V_319 ,
sizeof( V_319 ) ) ) {
V_22 -> V_323 . V_324 = true ;
F_5 ( V_22 -> V_12 , V_261 ,
L_39 ) ;
V_24 = F_49 ( V_22 ,
( T_2 * ) V_317 ,
V_320 ) ;
}
}
if ( V_317 -> V_325 == V_212 ) {
V_321 = 1 ;
break;
}
if ( V_317 -> V_325 == V_216 ) {
V_24 = F_48 ( V_22 , ( T_2 * ) V_317 ,
V_320 ) ;
return V_24 ;
}
V_320 -= ( V_317 -> V_48 +
sizeof( struct V_327 ) ) ;
if ( V_320 <= sizeof( struct V_327 ) )
V_317 = NULL ;
else
V_317 = (struct V_316 * )
( ( ( T_2 * ) V_317 ) + V_317 -> V_48 +
sizeof( struct V_327 ) ) ;
}
if ( V_321 ) {
V_24 = F_47 ( V_22 , ( T_2 * ) V_317 ,
V_320 ) ;
V_22 -> V_323 . V_324 = false ;
return V_24 ;
}
if ( V_207 < ( sizeof( V_22 -> V_328 ) - V_22 -> V_322 ) ) {
memcpy ( V_22 -> V_328 + V_22 -> V_322 , V_206 ,
V_207 ) ;
V_22 -> V_322 += V_207 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_67 ( struct V_21 * V_22 ,
struct V_329 * V_330 ,
T_1 V_122 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_330 -> type ) {
case V_331 :
if ( V_122 == V_136 ) {
V_330 -> V_48 = V_22 -> V_209 ;
memcpy ( V_330 -> V_332 , V_22 -> V_208 , V_330 -> V_48 ) ;
} else {
F_66 ( V_22 , V_330 -> V_332 ,
( T_1 ) V_330 -> V_48 ) ;
}
break;
case V_333 :
memset ( V_12 -> V_334 , 0 , sizeof( V_12 -> V_334 ) ) ;
if ( V_330 -> V_48 > V_335 ) {
V_12 -> V_336 = 0 ;
F_5 ( V_12 , ERROR ,
L_40 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_334 , V_330 -> V_332 ,
V_330 -> V_48 ) ;
V_12 -> V_336 = V_330 -> V_48 ;
}
break;
default:
F_5 ( V_12 , ERROR , L_41 ) ;
return - 1 ;
}
return 0 ;
}
int
F_68 ( struct V_21 * V_22 , const T_2 * V_337 , int V_207 )
{
struct V_329 V_330 ;
if ( V_207 > V_338 )
return - V_339 ;
V_330 . type = V_331 ;
V_330 . V_48 = V_207 ;
memcpy ( V_330 . V_332 , V_337 , V_207 ) ;
if ( F_67 ( V_22 , & V_330 , V_35 ) )
return - V_339 ;
return 0 ;
}
