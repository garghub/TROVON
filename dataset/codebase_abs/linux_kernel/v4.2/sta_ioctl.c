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
F_5 ( V_12 , ERROR ,
L_1 , V_15 ) ;
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
F_17 ( V_22 , V_38 ) ;
V_40 = F_20 ( sizeof( struct V_39 ) ,
V_94 ) ;
if ( ! V_40 )
return - V_52 ;
V_24 = F_9 ( V_22 , V_38 , V_40 ) ;
if ( V_24 )
goto V_95;
}
if ( V_22 -> V_70 == V_72 ||
V_22 -> V_70 == V_96 ) {
T_2 V_97 ;
if ( ! V_40 )
return - 1 ;
if ( F_21 ( V_40 -> V_62 ) ==
V_98 ) {
V_97 = V_99 | V_100 | V_101 ;
} else {
V_97 = V_102 | V_103 ;
if ( V_12 -> V_104 & V_105 )
V_97 |= V_105 ;
}
if ( ! ( ( V_97 | V_12 -> V_104 ) & ~ V_12 -> V_104 ) )
V_12 -> V_97 = V_97 ;
V_24 = F_22 ( V_22 , V_40 ) ;
if ( V_24 )
goto V_95;
if ( F_23 ( V_22 ) ==
( T_2 ) V_40 -> V_106 ) {
F_5 ( V_12 , ERROR ,
L_11 ,
V_40 -> V_106 ) ;
goto V_95;
}
F_5 ( V_12 , V_29 ,
L_12
L_13 ) ;
F_24 ( V_22 -> V_107 , V_12 ) ;
if ( F_25 ( V_22 -> V_107 ) )
F_26 ( V_22 -> V_107 ) ;
V_22 -> V_108 = 0 ;
V_24 = F_27 ( V_22 , V_40 ) ;
if ( V_24 == V_109 &&
V_22 -> V_110 . V_111 &&
V_22 -> V_110 . V_112 ) {
V_22 -> V_110 . V_113 =
V_114 ;
V_24 = F_27 ( V_22 , V_40 ) ;
}
if ( V_38 )
F_28 ( V_22 -> V_12 -> V_115 , V_38 ) ;
} else {
if ( V_40 && V_40 -> V_116 . V_117 &&
( ! F_29 ( & V_22 -> V_118 . V_119 .
V_116 , & V_40 -> V_116 ) ) ) {
V_24 = 0 ;
goto V_95;
}
V_22 -> V_120 = false ;
V_24 = F_22 ( V_22 , V_40 ) ;
F_24 ( V_22 -> V_107 , V_12 ) ;
if ( F_25 ( V_22 -> V_107 ) )
F_26 ( V_22 -> V_107 ) ;
if ( ! V_24 ) {
F_5 ( V_12 , V_29 ,
L_14
L_15 ) ;
V_24 = F_30 ( V_22 , V_40 ) ;
if ( V_38 )
F_28 ( V_22 -> V_12 -> V_115 , V_38 ) ;
} else {
F_5 ( V_12 , V_29 ,
L_16
L_17 ,
V_92 -> V_116 ) ;
V_24 = F_31 ( V_22 , V_92 ) ;
}
}
V_95:
if ( V_40 )
F_32 ( V_40 -> V_56 ) ;
F_32 ( V_40 ) ;
return V_24 ;
}
int F_33 ( struct V_21 * V_22 , T_1 V_121 ,
int V_122 , struct V_123 * V_124 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_15 = 0 ;
T_4 V_125 = 0 ;
if ( ! V_124 )
return - V_52 ;
switch ( V_121 ) {
case V_35 :
if ( V_12 -> V_126 ) {
F_5 ( V_12 , V_29 ,
L_18
L_19 ) ;
V_15 = - 1 ;
break;
}
if ( V_124 -> V_127 ) {
if ( V_124 -> V_128 == V_129 ) {
if ( ! V_12 -> V_130 )
break;
V_125 = F_34 ( V_12 -> V_124
. V_128 ) ;
V_12 -> V_124 . V_128 =
F_35 ( V_124 -> V_128 ) ;
} else if ( V_124 -> V_128 ) {
V_12 -> V_124 . V_128 =
F_35 ( V_124 -> V_128 ) ;
V_12 -> V_124 . V_131 = ( T_2 ) V_124 -> V_131 ;
if ( V_124 -> V_132 )
V_12 -> V_124 . V_132 = ( T_2 ) V_124 -> V_132 ;
} else if ( V_12 -> V_124 . V_128 ==
F_35 ( V_129 ) ) {
V_15 = - 1 ;
break;
}
V_15 = F_8 ( V_22 ,
V_133 ,
V_35 , 0 ,
& V_12 -> V_124 ,
V_122 == V_134 ) ;
if ( V_124 -> V_128 == V_129 )
V_12 -> V_124 . V_128 =
F_35 ( V_125 ) ;
} else {
V_12 -> V_124 . V_128 =
F_35 ( V_124 -> V_128 ) ;
V_12 -> V_124 . V_131 = ( T_2 ) V_124 -> V_131 ;
V_12 -> V_124 . V_132 = ( T_2 ) V_124 -> V_132 ;
}
break;
case V_135 :
V_124 -> V_128 = F_34 ( V_12 -> V_124 . V_128 ) ;
V_124 -> V_131 = V_12 -> V_124 . V_131 ;
V_124 -> V_132 = V_12 -> V_124 . V_132 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_36 ( struct V_21 * V_22 , int V_122 )
{
struct V_123 V_136 ;
V_136 . V_128 = V_129 ;
V_136 . V_127 = true ;
return F_33 ( V_22 , V_35 ,
V_122 , & V_136 ) ;
}
int F_37 ( struct V_11 * V_12 )
{
struct V_123 V_136 ;
struct V_21 * V_22 ;
int V_5 ;
if ( V_137 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_138 ; V_5 ++ ) {
V_22 = V_12 -> V_22 [ V_5 ] ;
if ( V_22 )
F_38 ( V_22 , NULL ) ;
}
}
if ( V_12 -> V_139 ) {
F_5 ( V_12 , V_140 ,
L_20 ) ;
return true ;
}
V_12 -> V_141 = false ;
memset ( & V_136 , 0 , sizeof( struct V_123 ) ) ;
V_136 . V_127 = true ;
V_12 -> V_142 = true ;
F_6 ( V_12 ) ;
if ( F_33 ( F_39 ( V_12 ,
V_143 ) ,
V_35 , V_134 ,
& V_136 ) ) {
F_5 ( V_12 , ERROR ,
L_21 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_144 ,
V_12 -> V_141 ,
( 10 * V_19 ) ) <= 0 ) {
F_5 ( V_12 , ERROR ,
L_22 ) ;
return false ;
}
return true ;
}
int F_40 ( struct V_21 * V_22 ,
struct V_145 * V_146 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_39 * V_40 ;
if ( ! V_146 )
return - 1 ;
V_40 = & V_22 -> V_118 . V_119 ;
V_146 -> V_70 = V_22 -> V_70 ;
memcpy ( & V_146 -> V_116 , & V_40 -> V_116 , sizeof( struct V_91 ) ) ;
memcpy ( & V_146 -> V_54 , & V_40 -> V_53 , V_10 ) ;
V_146 -> V_147 = V_40 -> V_106 ;
memcpy ( V_146 -> V_78 , V_12 -> V_78 ,
V_86 ) ;
V_146 -> V_148 = V_22 -> V_148 ;
V_146 -> V_149 = V_22 -> V_150 ;
V_146 -> V_151 = V_22 -> V_152 ;
V_146 -> V_153 = V_22 -> V_153 ;
V_146 -> V_154 = V_22 -> V_154 ;
if ( V_22 -> V_110 . V_112 )
V_146 -> V_155 = true ;
else
V_146 -> V_155 = false ;
V_146 -> V_130 = V_12 -> V_130 ;
V_146 -> V_156 = V_12 -> V_156 ;
return 0 ;
}
int F_41 ( struct V_21 * V_22 )
{
struct V_157 V_158 ;
V_158 . V_158 = V_159 ;
return F_8 ( V_22 , V_160 ,
V_161 , V_162 , & V_158 , true ) ;
}
int F_42 ( struct V_21 * V_22 , T_4 * V_163 )
{
int V_24 ;
V_24 = F_8 ( V_22 , V_164 ,
V_135 , 0 , NULL , true ) ;
if ( ! V_24 ) {
if ( V_22 -> V_165 )
* V_163 = F_43 ( V_22 , V_22 -> V_166 ,
V_22 -> V_167 ) ;
else
* V_163 = V_22 -> V_168 ;
}
return V_24 ;
}
int F_44 ( struct V_21 * V_22 ,
struct V_169 * V_170 )
{
int V_24 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
T_2 * V_177 ;
T_1 V_178 = 0 ;
if ( ! V_170 -> V_179 ) {
V_178 = ( T_1 ) V_170 -> V_180 ;
if ( ( V_178 < V_22 -> V_152 ) ||
( V_178 > V_22 -> V_150 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_23
L_24 ,
V_178 , V_22 -> V_152 ,
V_22 -> V_150 ) ;
return - 1 ;
}
}
V_177 = F_20 ( V_181 , V_94 ) ;
if ( ! V_177 )
return - V_52 ;
V_172 = (struct V_171 * ) V_177 ;
V_172 -> V_121 = F_45 ( V_35 ) ;
if ( ! V_170 -> V_179 ) {
V_172 -> V_27 = F_35 ( 1 ) ;
V_174 = (struct V_173 * )
( V_177 + sizeof( struct V_171 ) ) ;
V_174 -> type = F_45 ( V_182 ) ;
V_174 -> V_183 =
F_45 ( 4 * sizeof( struct V_175 ) ) ;
V_176 = (struct V_175 * )
( V_177 + sizeof( struct V_171 )
+ sizeof( struct V_173 ) ) ;
V_176 -> V_184 = 0x00 ;
V_176 -> V_185 = 0x03 ;
V_176 -> V_186 = V_187 ;
V_176 -> V_188 = 0 ;
V_176 -> V_189 = ( V_190 ) V_178 ;
V_176 -> V_191 = ( V_190 ) V_178 ;
V_176 ++ ;
V_176 -> V_184 = 0x00 ;
V_176 -> V_185 = 0x07 ;
V_176 -> V_186 = V_192 ;
V_176 -> V_188 = 0 ;
V_176 -> V_189 = ( V_190 ) V_178 ;
V_176 -> V_191 = ( V_190 ) V_178 ;
V_176 ++ ;
V_176 -> V_184 = 0x00 ;
V_176 -> V_185 = 0x20 ;
V_176 -> V_186 = V_193 ;
V_176 -> V_188 = 0 ;
V_176 -> V_189 = ( V_190 ) V_178 ;
V_176 -> V_191 = ( V_190 ) V_178 ;
V_176 -> V_194 = V_195 ;
V_176 ++ ;
V_176 -> V_184 = 0x00 ;
V_176 -> V_185 = 0x20 ;
V_176 -> V_186 = V_193 ;
V_176 -> V_188 = 0 ;
V_176 -> V_189 = ( V_190 ) V_178 ;
V_176 -> V_191 = ( V_190 ) V_178 ;
V_176 -> V_194 = V_196 ;
}
V_24 = F_8 ( V_22 , V_197 ,
V_35 , 0 , V_177 , true ) ;
F_32 ( V_177 ) ;
return V_24 ;
}
int F_46 ( struct V_21 * V_22 , T_4 * V_198 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_199 ;
if ( * V_198 )
V_12 -> V_198 = V_200 ;
else
V_12 -> V_198 = V_201 ;
V_199 = ( * V_198 ) ? V_202 : V_161 ;
V_24 = F_8 ( V_22 , V_160 ,
V_199 , V_203 , NULL , true ) ;
if ( ( ! V_24 ) && ( V_199 == V_161 ) )
V_24 = F_8 ( V_22 , V_160 ,
V_204 , 0 , NULL , false ) ;
return V_24 ;
}
static int F_47 ( struct V_21 * V_22 ,
T_2 * V_205 , T_1 V_206 )
{
if ( V_206 ) {
if ( V_206 > sizeof( V_22 -> V_207 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_25 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_207 , V_205 , V_206 ) ;
V_22 -> V_208 = ( T_2 ) V_206 ;
F_5 ( V_22 -> V_12 , V_140 ,
L_26 ,
V_22 -> V_208 , V_22 -> V_207 [ 0 ] ) ;
if ( V_22 -> V_207 [ 0 ] == V_209 ) {
V_22 -> V_110 . V_210 = true ;
} else if ( V_22 -> V_207 [ 0 ] == V_211 ) {
V_22 -> V_110 . V_212 = true ;
} else {
V_22 -> V_110 . V_210 = false ;
V_22 -> V_110 . V_212 = false ;
}
} else {
memset ( V_22 -> V_207 , 0 , sizeof( V_22 -> V_207 ) ) ;
V_22 -> V_208 = 0 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_27 ,
V_22 -> V_208 , V_22 -> V_207 [ 0 ] ) ;
V_22 -> V_110 . V_210 = false ;
V_22 -> V_110 . V_212 = false ;
}
return 0 ;
}
static int F_48 ( struct V_21 * V_22 ,
T_2 * V_205 , T_1 V_206 )
{
if ( V_206 ) {
if ( V_206 > sizeof( V_22 -> V_213 ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_28 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_213 , V_205 , V_206 ) ;
V_22 -> V_214 = V_206 ;
F_5 ( V_22 -> V_12 , V_140 ,
L_29 ,
V_22 -> V_214 , V_22 -> V_213 [ 0 ] ) ;
if ( V_22 -> V_213 [ 0 ] == V_215 )
V_22 -> V_110 . V_216 = true ;
} else {
memset ( V_22 -> V_213 , 0 , sizeof( V_22 -> V_213 ) ) ;
V_22 -> V_214 = V_206 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_30 ,
V_22 -> V_214 , V_22 -> V_213 [ 0 ] ) ;
V_22 -> V_110 . V_216 = false ;
}
return 0 ;
}
static int F_49 ( struct V_21 * V_22 ,
T_2 * V_205 , T_1 V_206 )
{
if ( V_206 ) {
if ( V_206 > V_217 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_31 ) ;
return - 1 ;
}
V_22 -> V_218 = F_20 ( V_217 , V_94 ) ;
if ( ! V_22 -> V_218 )
return - V_52 ;
memcpy ( V_22 -> V_218 , V_205 , V_206 ) ;
V_22 -> V_219 = V_206 ;
F_5 ( V_22 -> V_12 , V_140 ,
L_32 ,
V_22 -> V_219 , V_22 -> V_218 [ 0 ] ) ;
} else {
F_32 ( V_22 -> V_218 ) ;
V_22 -> V_219 = V_206 ;
F_5 ( V_22 -> V_12 , V_29 ,
L_33 , V_22 -> V_219 ) ;
}
return 0 ;
}
static int F_50 ( struct V_21 * V_22 ,
struct V_220 * V_221 )
{
return F_8 ( V_22 , V_222 ,
V_35 , V_223 ,
V_221 , true ) ;
}
static int F_51 ( struct V_21 * V_22 ,
struct V_220 * V_221 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_24 ;
struct V_224 * V_225 ;
int V_226 ;
if ( V_22 -> V_227 >= V_228 )
V_22 -> V_227 = 0 ;
V_225 = & V_22 -> V_225 [ V_22 -> V_227 ] ;
V_226 = V_221 -> V_229 ;
if ( V_221 -> V_230 ) {
V_22 -> V_110 . V_112 = 0 ;
} else if ( ! V_221 -> V_231 ) {
V_225 = & V_22 -> V_225 [ V_226 ] ;
if ( ! V_225 -> V_232 ) {
F_5 ( V_12 , ERROR ,
L_34 ) ;
return - 1 ;
}
if ( V_12 -> V_233 == V_234 ) {
memcpy ( V_221 -> V_235 ,
V_225 -> V_235 , V_225 -> V_232 ) ;
V_221 -> V_231 = V_225 -> V_232 ;
}
V_22 -> V_227 = ( T_1 ) V_226 ;
V_22 -> V_110 . V_112 = 1 ;
} else {
V_225 = & V_22 -> V_225 [ V_226 ] ;
memset ( V_225 , 0 , sizeof( struct V_224 ) ) ;
memcpy ( V_225 -> V_235 ,
V_221 -> V_235 ,
V_221 -> V_231 ) ;
V_225 -> V_229 = V_226 ;
V_225 -> V_232 = V_221 -> V_231 ;
V_22 -> V_110 . V_112 = 1 ;
}
if ( V_225 -> V_232 ) {
void * V_236 ;
if ( V_221 -> V_230 ) {
memset ( & V_22 -> V_225 [ V_226 ] , 0 ,
sizeof( struct V_224 ) ) ;
if ( V_225 -> V_232 )
goto V_95;
}
if ( V_12 -> V_233 == V_234 )
V_236 = V_221 ;
else
V_236 = NULL ;
V_24 = F_8 ( V_22 , V_222 ,
V_35 , 0 , V_236 , false ) ;
if ( V_24 )
return V_24 ;
}
V_95:
if ( V_22 -> V_110 . V_112 )
V_22 -> V_26 |= V_237 ;
else
V_22 -> V_26 &= ~ V_237 ;
V_24 = F_8 ( V_22 , V_36 ,
V_35 , 0 ,
& V_22 -> V_26 , true ) ;
return V_24 ;
}
static int F_52 ( struct V_21 * V_22 ,
struct V_220 * V_221 )
{
int V_24 ;
T_2 V_238 = false ;
struct V_239 * V_240 ;
if ( V_221 -> V_231 > V_241 ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_35 ) ;
return - 1 ;
}
if ( V_22 -> V_70 == V_71 ) {
V_221 -> V_229 = V_242 ;
V_24 = F_8 ( V_22 , V_222 ,
V_35 ,
V_223 , V_221 , false ) ;
if ( V_24 )
return V_24 ;
V_240 = & V_22 -> V_243 ;
memset ( V_240 , 0 ,
sizeof( struct V_239 ) ) ;
memcpy ( V_240 -> V_244 . V_245 , V_221 -> V_235 ,
V_221 -> V_231 ) ;
memcpy ( & V_240 -> V_244 . V_231 , & V_221 -> V_231 ,
sizeof( V_240 -> V_244 . V_231 ) ) ;
V_240 -> V_244 . V_246
= F_45 ( V_247 ) ;
V_240 -> V_244 . V_248 = F_45 ( V_249 ) ;
V_221 -> V_229 = ~ V_242 ;
}
if ( ! V_221 -> V_229 )
V_221 -> V_229 = V_242 ;
if ( V_238 )
V_24 = F_8 ( V_22 , V_222 ,
V_35 ,
! V_223 , V_221 , true ) ;
else
V_24 = F_8 ( V_22 , V_222 ,
V_35 ,
V_223 , V_221 , true ) ;
return V_24 ;
}
static int
F_53 ( struct V_21 * V_22 ,
struct V_220 * V_221 )
{
int V_15 ;
if ( V_221 -> V_250 )
V_15 = F_50 ( V_22 , V_221 ) ;
else if ( V_221 -> V_231 > V_251 )
V_15 = F_52 ( V_22 , V_221 ) ;
else
V_15 = F_51 ( V_22 , V_221 ) ;
return V_15 ;
}
int
F_54 ( struct V_11 * V_12 , char * V_252 ,
int V_253 )
{
union {
T_5 V_254 ;
T_2 V_255 [ 4 ] ;
} V_256 ;
char V_257 [ 32 ] ;
V_256 . V_254 = F_35 ( V_12 -> V_258 ) ;
sprintf ( V_257 , L_36 , V_256 . V_255 [ 2 ] , V_256 . V_255 [ 1 ] , V_256 . V_255 [ 0 ] , V_256 . V_255 [ 3 ] ) ;
snprintf ( V_252 , V_253 , V_259 , V_257 ) ;
F_5 ( V_12 , V_260 , L_37 , V_252 ) ;
return 0 ;
}
int F_55 ( struct V_21 * V_22 , struct V_261 * V_262 ,
const T_2 * V_245 , int V_231 , T_2 V_229 ,
const T_2 * V_263 , int V_264 )
{
struct V_220 V_221 ;
memset ( & V_221 , 0 , sizeof( struct V_220 ) ) ;
V_221 . V_231 = V_231 ;
V_221 . V_229 = V_229 ;
if ( V_262 && V_262 -> V_265 == V_266 )
V_221 . V_267 = true ;
if ( ! V_264 ) {
if ( V_231 )
memcpy ( V_221 . V_235 , V_245 , V_231 ) ;
else
V_221 . V_268 = true ;
if ( V_263 )
memcpy ( V_221 . V_263 , V_263 , V_10 ) ;
if ( V_262 && V_262 -> V_269 && V_262 -> V_270 ) {
memcpy ( V_221 . V_271 , V_262 -> V_269 , V_262 -> V_270 ) ;
V_221 . V_272 = V_262 -> V_270 ;
V_221 . V_273 = true ;
}
} else {
if ( F_56 ( V_22 ) == V_274 )
return 0 ;
V_221 . V_230 = true ;
if ( V_263 )
memcpy ( V_221 . V_263 , V_263 , V_10 ) ;
}
return F_53 ( V_22 , & V_221 ) ;
}
int
F_57 ( struct V_21 * V_22 )
{
struct V_275 V_276 ;
memset ( & V_276 , 0 , sizeof( struct V_277 ) ) ;
if ( F_8 ( V_22 , V_278 ,
V_135 , 0 , & V_276 , true ) )
return - 1 ;
return 0 ;
}
int
F_58 ( struct V_21 * V_22 , T_1 V_121 ,
struct V_279 * V_280 ,
unsigned int V_281 )
{
struct V_282 V_283 ;
T_2 V_284 ;
memset ( & V_283 , 0 , sizeof( V_283 ) ) ;
V_283 . V_121 = F_45 ( V_121 ) ;
if ( V_121 == V_35 ) {
V_283 . V_285 = V_280 -> V_63 ;
V_284 = F_59 ( V_286 ) ;
V_283 . V_285 |= ( V_284 << 2 ) ;
V_283 . V_106 =
F_60 ( V_280 -> V_287 ) ;
V_283 . V_281 = F_35 ( V_281 ) ;
}
if ( F_8 ( V_22 , V_288 ,
V_121 , 0 , & V_283 , true ) ) {
F_5 ( V_22 -> V_12 , ERROR ,
L_38 ) ;
return - 1 ;
}
return V_283 . V_15 ;
}
int
F_61 ( struct V_21 * V_22 ,
struct V_289 * log )
{
return F_8 ( V_22 , V_290 ,
V_135 , 0 , log , true ) ;
}
static int F_62 ( struct V_21 * V_22 ,
struct V_291 * V_292 ,
T_1 V_121 )
{
T_1 V_293 ;
switch ( F_34 ( V_292 -> type ) ) {
case V_294 :
V_293 = V_295 ;
break;
case V_296 :
V_293 = V_297 ;
break;
case V_298 :
V_293 = V_299 ;
break;
case V_300 :
V_293 = V_301 ;
break;
case V_302 :
V_293 = V_303 ;
break;
default:
return - 1 ;
}
return F_8 ( V_22 , V_293 , V_121 , 0 , V_292 , true ) ;
}
int
F_63 ( struct V_21 * V_22 , T_4 V_304 ,
T_4 V_305 , T_4 V_306 )
{
struct V_291 V_292 ;
V_292 . type = F_35 ( V_304 ) ;
V_292 . V_307 = F_35 ( V_305 ) ;
V_292 . V_308 = F_35 ( V_306 ) ;
return F_62 ( V_22 , & V_292 , V_35 ) ;
}
int
F_64 ( struct V_21 * V_22 , T_4 V_304 ,
T_4 V_305 , T_4 * V_308 )
{
int V_24 ;
struct V_291 V_292 ;
V_292 . type = F_35 ( V_304 ) ;
V_292 . V_307 = F_35 ( V_305 ) ;
V_24 = F_62 ( V_22 , & V_292 , V_135 ) ;
if ( V_24 )
goto V_95;
* V_308 = F_34 ( V_292 . V_308 ) ;
V_95:
return V_24 ;
}
int
F_65 ( struct V_21 * V_22 , T_1 V_307 , T_1 V_309 ,
T_2 * V_308 )
{
int V_24 ;
struct V_310 V_311 ;
V_311 . V_307 = F_45 ( ( T_1 ) V_307 ) ;
V_311 . V_312 = F_45 ( ( T_1 ) V_309 ) ;
V_24 = F_8 ( V_22 , V_313 ,
V_135 , 0 , & V_311 , true ) ;
if ( ! V_24 )
memcpy ( V_308 , V_311 . V_308 , V_314 ) ;
return V_24 ;
}
static int
F_66 ( struct V_21 * V_22 , T_2 * V_205 ,
T_1 V_206 )
{
int V_24 = 0 ;
struct V_315 * V_316 ;
const T_2 V_317 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_318 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_206 ) {
V_22 -> V_319 = 0 ;
V_22 -> V_320 . V_321 = false ;
return 0 ;
} else if ( ! V_205 ) {
return - 1 ;
}
V_316 = (struct V_315 * ) V_205 ;
if ( ( ( V_316 -> V_322 == V_209 ) &&
( ! memcmp ( V_316 -> V_323 , V_317 , sizeof( V_317 ) ) ) ) ||
( V_316 -> V_322 == V_211 ) ) {
V_24 = F_47 ( V_22 , V_205 , V_206 ) ;
V_22 -> V_320 . V_321 = false ;
return V_24 ;
} else if ( V_316 -> V_322 == V_215 ) {
V_24 = F_48 ( V_22 , V_205 , V_206 ) ;
return V_24 ;
}
if ( V_206 < ( sizeof( V_22 -> V_324 ) - V_22 -> V_319 ) ) {
V_316 = (struct V_315 * ) V_205 ;
if ( ( V_316 -> V_322 == V_209 ) &&
( ! memcmp ( V_316 -> V_323 , V_318 , sizeof( V_318 ) ) ) ) {
V_22 -> V_320 . V_321 = true ;
F_5 ( V_22 -> V_12 , V_29 ,
L_39 ) ;
V_24 = F_49 ( V_22 , V_205 , V_206 ) ;
}
memcpy ( V_22 -> V_324 + V_22 -> V_319 , V_205 ,
V_206 ) ;
V_22 -> V_319 += V_206 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_67 ( struct V_21 * V_22 ,
struct V_325 * V_326 ,
T_1 V_121 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_326 -> type ) {
case V_327 :
if ( V_121 == V_135 ) {
V_326 -> V_48 = V_22 -> V_208 ;
memcpy ( V_326 -> V_328 , V_22 -> V_207 , V_326 -> V_48 ) ;
} else {
F_66 ( V_22 , V_326 -> V_328 ,
( T_1 ) V_326 -> V_48 ) ;
}
break;
case V_329 :
memset ( V_12 -> V_330 , 0 , sizeof( V_12 -> V_330 ) ) ;
if ( V_326 -> V_48 > V_331 ) {
V_12 -> V_332 = 0 ;
F_5 ( V_12 , ERROR ,
L_40 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_330 , V_326 -> V_328 ,
V_326 -> V_48 ) ;
V_12 -> V_332 = V_326 -> V_48 ;
}
break;
default:
F_5 ( V_12 , ERROR , L_41 ) ;
return - 1 ;
}
return 0 ;
}
int
F_68 ( struct V_21 * V_22 , const T_2 * V_333 , int V_206 )
{
struct V_325 V_326 ;
if ( V_206 > V_334 )
return - V_335 ;
V_326 . type = V_327 ;
V_326 . V_48 = V_206 ;
memcpy ( V_326 . V_328 , V_333 , V_206 ) ;
if ( F_67 ( V_22 , & V_326 , V_35 ) )
return - V_335 ;
return 0 ;
}
