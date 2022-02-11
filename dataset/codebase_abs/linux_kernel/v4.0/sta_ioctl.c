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
F_5 ( V_12 -> V_4 , L_1 , V_15 ) ;
F_6 ( V_12 ) ;
return V_15 ;
}
V_15 = V_12 -> V_16 . V_15 ;
V_12 -> V_16 . V_15 = 0 ;
return V_15 ;
}
int F_7 ( struct V_20 * V_21 ,
struct V_1 * V_22 )
{
int V_23 = 0 ;
T_1 V_24 ;
V_24 = V_21 -> V_25 ;
if ( V_22 -> V_26 == V_27 ) {
F_8 ( V_21 -> V_12 -> V_4 , L_2 ) ;
V_21 -> V_25 |= V_28 ;
V_21 -> V_25 &=
~ V_29 ;
} else {
V_21 -> V_25 &= ~ V_28 ;
if ( V_22 -> V_26 == V_30 ) {
F_8 ( V_21 -> V_12 -> V_4 ,
L_3 ) ;
V_21 -> V_25 |=
V_29 ;
} else {
V_21 -> V_25 &=
~ V_29 ;
F_8 ( V_21 -> V_12 -> V_4 ,
L_4 ,
V_22 -> V_31 ) ;
V_23 = F_9 ( V_21 ,
V_32 ,
V_33 , 0 ,
V_22 , false ) ;
}
}
F_8 ( V_21 -> V_12 -> V_4 ,
L_5 ,
V_24 , V_21 -> V_25 ) ;
if ( V_24 != V_21 -> V_25 ) {
V_23 = F_9 ( V_21 , V_34 ,
V_33 ,
0 , & V_21 -> V_25 , false ) ;
}
return V_23 ;
}
int F_10 ( struct V_20 * V_21 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
T_2 * V_39 ;
T_3 V_40 ;
struct V_41 * V_42 = ( void * ) V_36 -> V_21 ;
const struct V_43 * V_44 ;
F_11 () ;
V_44 = F_12 ( V_36 -> V_44 ) ;
V_39 = F_13 ( V_44 -> V_45 , V_44 -> V_46 , V_47 ) ;
V_40 = V_44 -> V_46 ;
V_38 -> V_48 = V_44 -> V_49 ;
F_14 () ;
if ( ! V_39 ) {
F_5 ( V_21 -> V_12 -> V_4 , L_6 ) ;
return - V_50 ;
}
memcpy ( V_38 -> V_51 , V_36 -> V_52 , V_10 ) ;
V_38 -> V_53 = V_36 -> signal ;
V_38 -> V_54 = V_39 ;
V_38 -> V_55 = V_40 ;
V_38 -> V_56 = V_36 -> V_57 ;
V_38 -> V_58 = V_36 -> V_59 ;
V_38 -> V_60 = V_42 -> V_61 ;
V_38 -> V_62 = V_42 -> V_62 ;
if ( V_38 -> V_58 & V_63 ) {
F_8 ( V_21 -> V_12 -> V_4 , L_7 ) ;
V_38 -> V_64 = V_65 ;
} else {
V_38 -> V_64 = V_66 ;
}
if ( V_38 -> V_58 & V_67 )
V_38 -> V_68 = V_69 ;
else
V_38 -> V_68 = V_70 ;
V_38 -> V_71 = true ;
if ( V_38 -> V_58 & V_72 )
V_38 -> V_73 = true ;
return F_15 ( V_21 -> V_12 , V_38 ) ;
}
void F_16 ( struct V_20 * V_21 )
{
if ( V_21 -> V_12 -> V_74 ) {
char V_75 [] = { L_8 } ;
memcpy ( & V_75 [ 8 ] , V_21 -> V_12 -> V_76 , 2 ) ;
F_17 ( V_21 , V_21 -> V_12 -> V_74 , V_75 ) ;
}
}
static int F_18 ( struct V_20 * V_21 ,
struct V_35 * V_36 )
{
const T_2 * V_77 ;
T_2 V_78 ;
struct V_79 * V_80 =
& V_21 -> V_12 -> V_81 ;
F_11 () ;
V_77 = F_19 ( V_36 , V_82 ) ;
if ( ! V_77 ) {
F_14 () ;
return 0 ;
}
V_78 = V_77 [ 1 ] ;
if ( V_78 < V_83 ) {
F_14 () ;
return 0 ;
}
if ( ! strncmp ( V_21 -> V_12 -> V_76 , & V_77 [ 2 ] , 2 ) ) {
F_14 () ;
F_20 ( V_21 -> V_84 . V_85 ,
L_9 ) ;
return 0 ;
}
memcpy ( V_21 -> V_12 -> V_76 , & V_77 [ 2 ] , 2 ) ;
V_80 -> V_76 [ 0 ] = V_77 [ 2 ] ;
V_80 -> V_76 [ 1 ] = V_77 [ 3 ] ;
V_80 -> V_76 [ 2 ] = ' ' ;
V_78 -= V_86 ;
V_80 -> V_87 =
V_78 / sizeof( struct V_88 ) ;
memcpy ( ( T_2 * ) V_80 -> V_89 ,
& V_77 [ 2 ] + V_86 , V_78 ) ;
F_14 () ;
if ( F_9 ( V_21 , V_90 ,
V_33 , 0 , NULL , false ) ) {
F_21 ( V_21 -> V_12 -> V_85 ,
L_10 ) ;
return - 1 ;
}
F_16 ( V_21 ) ;
return 0 ;
}
int F_22 ( struct V_20 * V_21 , struct V_35 * V_36 ,
struct V_91 * V_92 )
{
int V_23 ;
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_37 * V_38 = NULL ;
V_21 -> V_93 = false ;
if ( V_36 ) {
F_18 ( V_21 , V_36 ) ;
V_38 = F_23 ( sizeof( struct V_37 ) ,
V_94 ) ;
if ( ! V_38 )
return - V_50 ;
V_23 = F_10 ( V_21 , V_36 , V_38 ) ;
if ( V_23 )
goto V_95;
}
if ( V_21 -> V_68 == V_70 ||
V_21 -> V_68 == V_96 ) {
T_2 V_97 ;
if ( ! V_38 )
return - 1 ;
if ( F_24 ( V_38 -> V_60 ) ==
V_98 ) {
V_97 = V_99 | V_100 | V_101 ;
} else {
V_97 = V_102 | V_103 ;
if ( V_12 -> V_104 & V_105 )
V_97 |= V_105 ;
}
if ( ! ( ( V_97 | V_12 -> V_104 ) & ~ V_12 -> V_104 ) )
V_12 -> V_97 = V_97 ;
V_23 = F_25 ( V_21 , V_38 ) ;
if ( V_23 )
goto V_95;
if ( F_26 ( V_21 ) ==
( T_2 ) V_38 -> V_106 ) {
F_5 ( V_12 -> V_4 ,
L_11 ,
V_38 -> V_106 ) ;
goto V_95;
}
F_8 ( V_12 -> V_4 , L_12
L_13 ) ;
F_27 ( V_21 -> V_107 , V_12 ) ;
if ( F_28 ( V_21 -> V_107 ) )
F_29 ( V_21 -> V_107 ) ;
V_21 -> V_108 = 0 ;
V_23 = F_30 ( V_21 , V_38 ) ;
if ( V_23 == V_109 &&
V_21 -> V_110 . V_111 &&
V_21 -> V_110 . V_112 ) {
V_21 -> V_110 . V_113 =
V_114 ;
V_23 = F_30 ( V_21 , V_38 ) ;
}
if ( V_36 )
F_31 ( V_21 -> V_12 -> V_85 , V_36 ) ;
} else {
if ( V_38 && V_38 -> V_115 . V_116 &&
( ! F_32 ( & V_21 -> V_117 . V_118 .
V_115 , & V_38 -> V_115 ) ) ) {
V_23 = 0 ;
goto V_95;
}
V_21 -> V_119 = false ;
V_23 = F_25 ( V_21 , V_38 ) ;
F_27 ( V_21 -> V_107 , V_12 ) ;
if ( F_28 ( V_21 -> V_107 ) )
F_29 ( V_21 -> V_107 ) ;
if ( ! V_23 ) {
F_8 ( V_12 -> V_4 , L_14
L_15 ) ;
V_23 = F_33 ( V_21 , V_38 ) ;
if ( V_36 )
F_31 ( V_21 -> V_12 -> V_85 , V_36 ) ;
} else {
F_8 ( V_12 -> V_4 , L_16
L_17 ,
V_92 -> V_115 ) ;
V_23 = F_34 ( V_21 , V_92 ) ;
}
}
V_95:
if ( V_38 )
F_35 ( V_38 -> V_54 ) ;
F_35 ( V_38 ) ;
return V_23 ;
}
int F_36 ( struct V_20 * V_21 , T_1 V_120 ,
int V_121 , struct V_122 * V_123 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
int V_15 = 0 ;
T_4 V_124 = 0 ;
if ( ! V_123 )
return - V_50 ;
switch ( V_120 ) {
case V_33 :
if ( V_12 -> V_125 ) {
F_8 ( V_12 -> V_4 , L_18
L_19 ) ;
V_15 = - 1 ;
break;
}
if ( V_123 -> V_126 ) {
if ( V_123 -> V_127 == V_128 ) {
if ( ! V_12 -> V_129 )
break;
V_124 = F_37 ( V_12 -> V_123
. V_127 ) ;
V_12 -> V_123 . V_127 =
F_38 ( V_123 -> V_127 ) ;
} else if ( V_123 -> V_127 ) {
V_12 -> V_123 . V_127 =
F_38 ( V_123 -> V_127 ) ;
V_12 -> V_123 . V_130 = ( T_2 ) V_123 -> V_130 ;
if ( V_123 -> V_131 )
V_12 -> V_123 . V_131 = ( T_2 ) V_123 -> V_131 ;
} else if ( V_12 -> V_123 . V_127 ==
F_38 ( V_128 ) ) {
V_15 = - 1 ;
break;
}
V_15 = F_9 ( V_21 ,
V_132 ,
V_33 , 0 ,
& V_12 -> V_123 ,
V_121 == V_133 ) ;
if ( V_123 -> V_127 == V_128 )
V_12 -> V_123 . V_127 =
F_38 ( V_124 ) ;
} else {
V_12 -> V_123 . V_127 =
F_38 ( V_123 -> V_127 ) ;
V_12 -> V_123 . V_130 = ( T_2 ) V_123 -> V_130 ;
V_12 -> V_123 . V_131 = ( T_2 ) V_123 -> V_131 ;
}
break;
case V_134 :
V_123 -> V_127 = F_37 ( V_12 -> V_123 . V_127 ) ;
V_123 -> V_130 = V_12 -> V_123 . V_130 ;
V_123 -> V_131 = V_12 -> V_123 . V_131 ;
break;
default:
V_15 = - 1 ;
break;
}
return V_15 ;
}
int F_39 ( struct V_20 * V_21 , int V_121 )
{
struct V_122 V_135 ;
V_135 . V_127 = V_128 ;
V_135 . V_126 = true ;
return F_36 ( V_21 , V_33 ,
V_121 , & V_135 ) ;
}
int F_40 ( struct V_11 * V_12 )
{
struct V_122 V_135 ;
struct V_20 * V_21 ;
int V_5 ;
if ( V_136 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_137 ; V_5 ++ ) {
V_21 = V_12 -> V_21 [ V_5 ] ;
if ( V_21 )
F_41 ( V_21 , NULL ) ;
}
}
if ( V_12 -> V_138 ) {
F_8 ( V_12 -> V_4 , L_20 ) ;
return true ;
}
V_12 -> V_139 = false ;
memset ( & V_135 , 0 , sizeof( struct V_122 ) ) ;
V_135 . V_126 = true ;
V_12 -> V_140 = true ;
F_6 ( V_12 ) ;
if ( F_36 ( F_42 ( V_12 ,
V_141 ) ,
V_33 , V_133 ,
& V_135 ) ) {
F_5 ( V_12 -> V_4 , L_21 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_142 ,
V_12 -> V_139 ,
( 10 * V_19 ) ) <= 0 ) {
F_5 ( V_12 -> V_4 , L_22 ) ;
return false ;
}
return true ;
}
int F_43 ( struct V_20 * V_21 ,
struct V_143 * V_144 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
struct V_37 * V_38 ;
if ( ! V_144 )
return - 1 ;
V_38 = & V_21 -> V_117 . V_118 ;
V_144 -> V_68 = V_21 -> V_68 ;
memcpy ( & V_144 -> V_115 , & V_38 -> V_115 , sizeof( struct V_91 ) ) ;
memcpy ( & V_144 -> V_52 , & V_38 -> V_51 , V_10 ) ;
V_144 -> V_145 = V_38 -> V_106 ;
memcpy ( V_144 -> V_76 , V_12 -> V_76 ,
V_86 ) ;
V_144 -> V_146 = V_21 -> V_146 ;
V_144 -> V_147 = V_21 -> V_148 ;
V_144 -> V_149 = V_21 -> V_150 ;
V_144 -> V_151 = V_21 -> V_151 ;
V_144 -> V_152 = V_21 -> V_152 ;
if ( V_21 -> V_110 . V_112 )
V_144 -> V_153 = true ;
else
V_144 -> V_153 = false ;
V_144 -> V_129 = V_12 -> V_129 ;
V_144 -> V_154 = V_12 -> V_154 ;
return 0 ;
}
int F_44 ( struct V_20 * V_21 )
{
struct V_155 V_156 ;
V_156 . V_156 = V_157 ;
return F_9 ( V_21 , V_158 ,
V_159 , V_160 , & V_156 , true ) ;
}
int F_45 ( struct V_20 * V_21 , T_4 * V_161 )
{
int V_23 ;
V_23 = F_9 ( V_21 , V_162 ,
V_134 , 0 , NULL , true ) ;
if ( ! V_23 ) {
if ( V_21 -> V_163 )
* V_161 = F_46 ( V_21 , V_21 -> V_164 ,
V_21 -> V_165 ) ;
else
* V_161 = V_21 -> V_166 ;
}
return V_23 ;
}
int F_47 ( struct V_20 * V_21 ,
struct V_167 * V_168 )
{
int V_23 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
struct V_173 * V_174 ;
T_2 * V_175 ;
T_1 V_176 = 0 ;
if ( ! V_168 -> V_177 ) {
V_176 = ( T_1 ) V_168 -> V_178 ;
if ( ( V_176 < V_21 -> V_150 ) ||
( V_176 > V_21 -> V_148 ) ) {
F_5 ( V_21 -> V_12 -> V_4 , L_23
L_24 ,
V_176 , V_21 -> V_150 ,
V_21 -> V_148 ) ;
return - 1 ;
}
}
V_175 = F_23 ( V_179 , V_94 ) ;
if ( ! V_175 )
return - V_50 ;
V_170 = (struct V_169 * ) V_175 ;
V_170 -> V_120 = F_48 ( V_33 ) ;
if ( ! V_168 -> V_177 ) {
V_170 -> V_26 = F_38 ( 1 ) ;
V_172 = (struct V_171 * )
( V_175 + sizeof( struct V_169 ) ) ;
V_172 -> type = F_48 ( V_180 ) ;
V_172 -> V_181 =
F_48 ( 4 * sizeof( struct V_173 ) ) ;
V_174 = (struct V_173 * )
( V_175 + sizeof( struct V_169 )
+ sizeof( struct V_171 ) ) ;
V_174 -> V_182 = 0x00 ;
V_174 -> V_183 = 0x03 ;
V_174 -> V_184 = V_185 ;
V_174 -> V_186 = 0 ;
V_174 -> V_187 = ( V_188 ) V_176 ;
V_174 -> V_189 = ( V_188 ) V_176 ;
V_174 ++ ;
V_174 -> V_182 = 0x00 ;
V_174 -> V_183 = 0x07 ;
V_174 -> V_184 = V_190 ;
V_174 -> V_186 = 0 ;
V_174 -> V_187 = ( V_188 ) V_176 ;
V_174 -> V_189 = ( V_188 ) V_176 ;
V_174 ++ ;
V_174 -> V_182 = 0x00 ;
V_174 -> V_183 = 0x20 ;
V_174 -> V_184 = V_191 ;
V_174 -> V_186 = 0 ;
V_174 -> V_187 = ( V_188 ) V_176 ;
V_174 -> V_189 = ( V_188 ) V_176 ;
V_174 -> V_192 = V_193 ;
V_174 ++ ;
V_174 -> V_182 = 0x00 ;
V_174 -> V_183 = 0x20 ;
V_174 -> V_184 = V_191 ;
V_174 -> V_186 = 0 ;
V_174 -> V_187 = ( V_188 ) V_176 ;
V_174 -> V_189 = ( V_188 ) V_176 ;
V_174 -> V_192 = V_194 ;
}
V_23 = F_9 ( V_21 , V_195 ,
V_33 , 0 , V_175 , true ) ;
F_35 ( V_175 ) ;
return V_23 ;
}
int F_49 ( struct V_20 * V_21 , T_4 * V_196 )
{
int V_23 ;
struct V_11 * V_12 = V_21 -> V_12 ;
T_1 V_197 ;
if ( * V_196 )
V_12 -> V_196 = V_198 ;
else
V_12 -> V_196 = V_199 ;
V_197 = ( * V_196 ) ? V_200 : V_159 ;
V_23 = F_9 ( V_21 , V_158 ,
V_197 , V_201 , NULL , true ) ;
if ( ( ! V_23 ) && ( V_197 == V_159 ) )
V_23 = F_9 ( V_21 , V_158 ,
V_202 , 0 , NULL , false ) ;
return V_23 ;
}
static int F_50 ( struct V_20 * V_21 ,
T_2 * V_203 , T_1 V_204 )
{
if ( V_204 ) {
if ( V_204 > sizeof( V_21 -> V_205 ) ) {
F_5 ( V_21 -> V_12 -> V_4 ,
L_25 ) ;
return - 1 ;
}
memcpy ( V_21 -> V_205 , V_203 , V_204 ) ;
V_21 -> V_206 = ( T_2 ) V_204 ;
F_8 ( V_21 -> V_12 -> V_4 , L_26 ,
V_21 -> V_206 , V_21 -> V_205 [ 0 ] ) ;
if ( V_21 -> V_205 [ 0 ] == V_207 ) {
V_21 -> V_110 . V_208 = true ;
} else if ( V_21 -> V_205 [ 0 ] == V_209 ) {
V_21 -> V_110 . V_210 = true ;
} else {
V_21 -> V_110 . V_208 = false ;
V_21 -> V_110 . V_210 = false ;
}
} else {
memset ( V_21 -> V_205 , 0 , sizeof( V_21 -> V_205 ) ) ;
V_21 -> V_206 = 0 ;
F_8 ( V_21 -> V_12 -> V_4 , L_27 ,
V_21 -> V_206 , V_21 -> V_205 [ 0 ] ) ;
V_21 -> V_110 . V_208 = false ;
V_21 -> V_110 . V_210 = false ;
}
return 0 ;
}
static int F_51 ( struct V_20 * V_21 ,
T_2 * V_203 , T_1 V_204 )
{
if ( V_204 ) {
if ( V_204 > sizeof( V_21 -> V_211 ) ) {
F_8 ( V_21 -> V_12 -> V_4 ,
L_28 ) ;
return - 1 ;
}
memcpy ( V_21 -> V_211 , V_203 , V_204 ) ;
V_21 -> V_212 = V_204 ;
F_8 ( V_21 -> V_12 -> V_4 , L_29 ,
V_21 -> V_212 , V_21 -> V_211 [ 0 ] ) ;
if ( V_21 -> V_211 [ 0 ] == V_213 )
V_21 -> V_110 . V_214 = true ;
} else {
memset ( V_21 -> V_211 , 0 , sizeof( V_21 -> V_211 ) ) ;
V_21 -> V_212 = V_204 ;
F_8 ( V_21 -> V_12 -> V_4 ,
L_30 ,
V_21 -> V_212 , V_21 -> V_211 [ 0 ] ) ;
V_21 -> V_110 . V_214 = false ;
}
return 0 ;
}
static int F_52 ( struct V_20 * V_21 ,
T_2 * V_203 , T_1 V_204 )
{
if ( V_204 ) {
if ( V_204 > V_215 ) {
F_8 ( V_21 -> V_12 -> V_4 ,
L_31 ) ;
return - 1 ;
}
V_21 -> V_216 = F_23 ( V_215 , V_94 ) ;
if ( ! V_21 -> V_216 )
return - V_50 ;
memcpy ( V_21 -> V_216 , V_203 , V_204 ) ;
V_21 -> V_217 = V_204 ;
F_8 ( V_21 -> V_12 -> V_4 , L_32 ,
V_21 -> V_217 , V_21 -> V_216 [ 0 ] ) ;
} else {
F_35 ( V_21 -> V_216 ) ;
V_21 -> V_217 = V_204 ;
F_8 ( V_21 -> V_12 -> V_4 ,
L_33 , V_21 -> V_217 ) ;
}
return 0 ;
}
static int F_53 ( struct V_20 * V_21 ,
struct V_218 * V_219 )
{
return F_9 ( V_21 , V_220 ,
V_33 , V_221 ,
V_219 , true ) ;
}
static int F_54 ( struct V_20 * V_21 ,
struct V_218 * V_219 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
int V_23 ;
struct V_222 * V_223 ;
int V_224 ;
if ( V_21 -> V_225 >= V_226 )
V_21 -> V_225 = 0 ;
V_223 = & V_21 -> V_223 [ V_21 -> V_225 ] ;
V_224 = V_219 -> V_227 ;
if ( V_219 -> V_228 ) {
V_21 -> V_110 . V_112 = 0 ;
} else if ( ! V_219 -> V_229 ) {
V_223 = & V_21 -> V_223 [ V_224 ] ;
if ( ! V_223 -> V_230 ) {
F_5 ( V_12 -> V_4 ,
L_34 ) ;
return - 1 ;
}
if ( V_12 -> V_231 == V_232 ) {
memcpy ( V_219 -> V_233 ,
V_223 -> V_233 , V_223 -> V_230 ) ;
V_219 -> V_229 = V_223 -> V_230 ;
}
V_21 -> V_225 = ( T_1 ) V_224 ;
V_21 -> V_110 . V_112 = 1 ;
} else {
V_223 = & V_21 -> V_223 [ V_224 ] ;
memset ( V_223 , 0 , sizeof( struct V_222 ) ) ;
memcpy ( V_223 -> V_233 ,
V_219 -> V_233 ,
V_219 -> V_229 ) ;
V_223 -> V_227 = V_224 ;
V_223 -> V_230 = V_219 -> V_229 ;
V_21 -> V_110 . V_112 = 1 ;
}
if ( V_223 -> V_230 ) {
void * V_234 ;
if ( V_219 -> V_228 ) {
memset ( & V_21 -> V_223 [ V_224 ] , 0 ,
sizeof( struct V_222 ) ) ;
if ( V_223 -> V_230 )
goto V_95;
}
if ( V_12 -> V_231 == V_232 )
V_234 = V_219 ;
else
V_234 = NULL ;
V_23 = F_9 ( V_21 , V_220 ,
V_33 , 0 , V_234 , false ) ;
if ( V_23 )
return V_23 ;
}
V_95:
if ( V_21 -> V_110 . V_112 )
V_21 -> V_25 |= V_235 ;
else
V_21 -> V_25 &= ~ V_235 ;
V_23 = F_9 ( V_21 , V_34 ,
V_33 , 0 ,
& V_21 -> V_25 , true ) ;
return V_23 ;
}
static int F_55 ( struct V_20 * V_21 ,
struct V_218 * V_219 )
{
int V_23 ;
T_2 V_236 = false ;
struct V_237 * V_238 ;
if ( V_219 -> V_229 > V_239 ) {
F_5 ( V_21 -> V_12 -> V_4 , L_35 ) ;
return - 1 ;
}
if ( V_21 -> V_68 == V_69 ) {
V_219 -> V_227 = V_240 ;
V_23 = F_9 ( V_21 , V_220 ,
V_33 ,
V_221 , V_219 , false ) ;
if ( V_23 )
return V_23 ;
V_238 = & V_21 -> V_241 ;
memset ( V_238 , 0 ,
sizeof( struct V_237 ) ) ;
memcpy ( V_238 -> V_242 . V_243 , V_219 -> V_233 ,
V_219 -> V_229 ) ;
memcpy ( & V_238 -> V_242 . V_229 , & V_219 -> V_229 ,
sizeof( V_238 -> V_242 . V_229 ) ) ;
V_238 -> V_242 . V_244
= F_48 ( V_245 ) ;
V_238 -> V_242 . V_246 = F_48 ( V_247 ) ;
V_219 -> V_227 = ~ V_240 ;
}
if ( ! V_219 -> V_227 )
V_219 -> V_227 = V_240 ;
if ( V_236 )
V_23 = F_9 ( V_21 , V_220 ,
V_33 ,
! V_221 , V_219 , true ) ;
else
V_23 = F_9 ( V_21 , V_220 ,
V_33 ,
V_221 , V_219 , true ) ;
return V_23 ;
}
static int
F_56 ( struct V_20 * V_21 ,
struct V_218 * V_219 )
{
int V_15 ;
if ( V_219 -> V_248 )
V_15 = F_53 ( V_21 , V_219 ) ;
else if ( V_219 -> V_229 > V_249 )
V_15 = F_55 ( V_21 , V_219 ) ;
else
V_15 = F_54 ( V_21 , V_219 ) ;
return V_15 ;
}
int
F_57 ( struct V_11 * V_12 , char * V_250 ,
int V_251 )
{
union {
T_5 V_252 ;
T_2 V_253 [ 4 ] ;
} V_254 ;
char V_255 [ 32 ] ;
V_254 . V_252 = F_38 ( V_12 -> V_256 ) ;
sprintf ( V_255 , L_36 , V_254 . V_253 [ 2 ] , V_254 . V_253 [ 1 ] , V_254 . V_253 [ 0 ] , V_254 . V_253 [ 3 ] ) ;
snprintf ( V_250 , V_251 , V_257 , V_255 ) ;
F_8 ( V_12 -> V_4 , L_37 , V_250 ) ;
return 0 ;
}
int F_58 ( struct V_20 * V_21 , struct V_258 * V_259 ,
const T_2 * V_243 , int V_229 , T_2 V_227 ,
const T_2 * V_260 , int V_261 )
{
struct V_218 V_219 ;
memset ( & V_219 , 0 , sizeof( struct V_218 ) ) ;
V_219 . V_229 = V_229 ;
V_219 . V_227 = V_227 ;
if ( V_259 && V_259 -> V_262 == V_263 )
V_219 . V_264 = true ;
if ( ! V_261 ) {
if ( V_229 )
memcpy ( V_219 . V_233 , V_243 , V_229 ) ;
else
V_219 . V_265 = true ;
if ( V_260 )
memcpy ( V_219 . V_260 , V_260 , V_10 ) ;
if ( V_259 && V_259 -> V_266 && V_259 -> V_267 ) {
memcpy ( V_219 . V_268 , V_259 -> V_266 , V_259 -> V_267 ) ;
V_219 . V_269 = V_259 -> V_267 ;
V_219 . V_270 = true ;
}
} else {
if ( F_59 ( V_21 ) == V_271 )
return 0 ;
V_219 . V_228 = true ;
if ( V_260 )
memcpy ( V_219 . V_260 , V_260 , V_10 ) ;
}
return F_56 ( V_21 , & V_219 ) ;
}
int
F_60 ( struct V_20 * V_21 )
{
struct V_272 V_273 ;
memset ( & V_273 , 0 , sizeof( struct V_274 ) ) ;
if ( F_9 ( V_21 , V_275 ,
V_134 , 0 , & V_273 , true ) )
return - 1 ;
return 0 ;
}
int
F_61 ( struct V_20 * V_21 , T_1 V_120 ,
struct V_276 * V_277 ,
unsigned int V_278 )
{
struct V_279 V_280 ;
T_2 V_281 ;
memset ( & V_280 , 0 , sizeof( V_280 ) ) ;
V_280 . V_120 = F_48 ( V_120 ) ;
if ( V_120 == V_33 ) {
V_280 . V_282 = V_277 -> V_61 ;
V_281 = F_62 ( V_283 ) ;
V_280 . V_282 |= ( V_281 << 2 ) ;
V_280 . V_106 =
F_63 ( V_277 -> V_284 ) ;
V_280 . V_278 = F_38 ( V_278 ) ;
}
if ( F_9 ( V_21 , V_285 ,
V_120 , 0 , & V_280 , true ) ) {
F_5 ( V_21 -> V_12 -> V_4 , L_38 ) ;
return - 1 ;
}
return V_280 . V_15 ;
}
int
F_64 ( struct V_20 * V_21 ,
struct V_286 * log )
{
return F_9 ( V_21 , V_287 ,
V_134 , 0 , log , true ) ;
}
static int F_65 ( struct V_20 * V_21 ,
struct V_288 * V_289 ,
T_1 V_120 )
{
T_1 V_290 ;
switch ( F_37 ( V_289 -> type ) ) {
case V_291 :
V_290 = V_292 ;
break;
case V_293 :
V_290 = V_294 ;
break;
case V_295 :
V_290 = V_296 ;
break;
case V_297 :
V_290 = V_298 ;
break;
case V_299 :
V_290 = V_300 ;
break;
default:
return - 1 ;
}
return F_9 ( V_21 , V_290 , V_120 , 0 , V_289 , true ) ;
}
int
F_66 ( struct V_20 * V_21 , T_4 V_301 ,
T_4 V_302 , T_4 V_303 )
{
struct V_288 V_289 ;
V_289 . type = F_38 ( V_301 ) ;
V_289 . V_304 = F_38 ( V_302 ) ;
V_289 . V_305 = F_38 ( V_303 ) ;
return F_65 ( V_21 , & V_289 , V_33 ) ;
}
int
F_67 ( struct V_20 * V_21 , T_4 V_301 ,
T_4 V_302 , T_4 * V_305 )
{
int V_23 ;
struct V_288 V_289 ;
V_289 . type = F_38 ( V_301 ) ;
V_289 . V_304 = F_38 ( V_302 ) ;
V_23 = F_65 ( V_21 , & V_289 , V_134 ) ;
if ( V_23 )
goto V_95;
* V_305 = F_37 ( V_289 . V_305 ) ;
V_95:
return V_23 ;
}
int
F_68 ( struct V_20 * V_21 , T_1 V_304 , T_1 V_306 ,
T_2 * V_305 )
{
int V_23 ;
struct V_307 V_308 ;
V_308 . V_304 = F_48 ( ( T_1 ) V_304 ) ;
V_308 . V_309 = F_48 ( ( T_1 ) V_306 ) ;
V_23 = F_9 ( V_21 , V_310 ,
V_134 , 0 , & V_308 , true ) ;
if ( ! V_23 )
memcpy ( V_305 , V_308 . V_305 , V_311 ) ;
return V_23 ;
}
static int
F_69 ( struct V_20 * V_21 , T_2 * V_203 ,
T_1 V_204 )
{
int V_23 = 0 ;
struct V_312 * V_313 ;
const T_2 V_314 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_315 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_204 ) {
V_21 -> V_316 = 0 ;
V_21 -> V_317 . V_318 = false ;
return 0 ;
} else if ( ! V_203 ) {
return - 1 ;
}
V_313 = (struct V_312 * ) V_203 ;
if ( ( ( V_313 -> V_319 == V_207 ) &&
( ! memcmp ( V_313 -> V_320 , V_314 , sizeof( V_314 ) ) ) ) ||
( V_313 -> V_319 == V_209 ) ) {
V_23 = F_50 ( V_21 , V_203 , V_204 ) ;
V_21 -> V_317 . V_318 = false ;
return V_23 ;
} else if ( V_313 -> V_319 == V_213 ) {
V_23 = F_51 ( V_21 , V_203 , V_204 ) ;
return V_23 ;
}
if ( V_204 < ( sizeof( V_21 -> V_321 ) - V_21 -> V_316 ) ) {
V_313 = (struct V_312 * ) V_203 ;
if ( ( V_313 -> V_319 == V_207 ) &&
( ! memcmp ( V_313 -> V_320 , V_315 , sizeof( V_315 ) ) ) ) {
V_21 -> V_317 . V_318 = true ;
F_8 ( V_21 -> V_12 -> V_4 ,
L_39 ) ;
V_23 = F_52 ( V_21 , V_203 , V_204 ) ;
}
memcpy ( V_21 -> V_321 + V_21 -> V_316 , V_203 ,
V_204 ) ;
V_21 -> V_316 += V_204 ;
} else {
V_23 = - 1 ;
}
return V_23 ;
}
static int F_70 ( struct V_20 * V_21 ,
struct V_322 * V_323 ,
T_1 V_120 )
{
struct V_11 * V_12 = V_21 -> V_12 ;
switch ( V_323 -> type ) {
case V_324 :
if ( V_120 == V_134 ) {
V_323 -> V_46 = V_21 -> V_206 ;
memcpy ( V_323 -> V_325 , V_21 -> V_205 , V_323 -> V_46 ) ;
} else {
F_69 ( V_21 , V_323 -> V_325 ,
( T_1 ) V_323 -> V_46 ) ;
}
break;
case V_326 :
memset ( V_12 -> V_327 , 0 , sizeof( V_12 -> V_327 ) ) ;
if ( V_323 -> V_46 > V_328 ) {
V_12 -> V_329 = 0 ;
F_5 ( V_12 -> V_4 , L_40 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_327 , V_323 -> V_325 ,
V_323 -> V_46 ) ;
V_12 -> V_329 = V_323 -> V_46 ;
}
break;
default:
F_5 ( V_12 -> V_4 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
int
F_71 ( struct V_20 * V_21 , const T_2 * V_330 , int V_204 )
{
struct V_322 V_323 ;
if ( V_204 > V_331 )
return - V_332 ;
V_323 . type = V_324 ;
V_323 . V_46 = V_204 ;
memcpy ( V_323 . V_325 , V_330 , V_204 ) ;
if ( F_70 ( V_21 , & V_323 , V_33 ) )
return - V_332 ;
return 0 ;
}
