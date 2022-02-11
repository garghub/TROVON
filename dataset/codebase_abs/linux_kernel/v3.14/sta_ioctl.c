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
void F_15 ( struct V_19 * V_20 )
{
if ( V_20 -> V_12 -> V_73 ) {
char V_74 [] = { L_8 } ;
memcpy ( & V_74 [ 8 ] , V_20 -> V_12 -> V_75 , 2 ) ;
F_16 ( V_20 , V_20 -> V_12 -> V_73 , V_74 ) ;
}
}
static int F_17 ( struct V_19 * V_20 ,
struct V_34 * V_35 )
{
const T_2 * V_76 ;
T_2 V_77 ;
struct V_78 * V_79 =
& V_20 -> V_12 -> V_80 ;
F_10 () ;
V_76 = F_18 ( V_35 , V_81 ) ;
if ( ! V_76 ) {
F_13 () ;
return 0 ;
}
V_77 = V_76 [ 1 ] ;
if ( V_77 < V_82 ) {
F_13 () ;
return 0 ;
}
if ( ! strncmp ( V_20 -> V_12 -> V_75 , & V_76 [ 2 ] , 2 ) ) {
F_13 () ;
F_19 ( V_20 -> V_83 -> V_84 ,
L_9 ) ;
return 0 ;
}
memcpy ( V_20 -> V_12 -> V_75 , & V_76 [ 2 ] , 2 ) ;
V_79 -> V_75 [ 0 ] = V_76 [ 2 ] ;
V_79 -> V_75 [ 1 ] = V_76 [ 3 ] ;
V_79 -> V_75 [ 2 ] = ' ' ;
V_77 -= V_85 ;
V_79 -> V_86 =
V_77 / sizeof( struct V_87 ) ;
memcpy ( ( T_2 * ) V_79 -> V_88 ,
& V_76 [ 2 ] + V_85 , V_77 ) ;
F_13 () ;
if ( F_8 ( V_20 , V_89 ,
V_32 , 0 , NULL ) ) {
F_20 ( V_20 -> V_12 -> V_84 ,
L_10 ) ;
return - 1 ;
}
F_15 ( V_20 ) ;
return 0 ;
}
int F_21 ( struct V_19 * V_20 , struct V_34 * V_35 ,
struct V_90 * V_91 )
{
int V_22 ;
struct V_11 * V_12 = V_20 -> V_12 ;
struct V_36 * V_37 = NULL ;
V_20 -> V_92 = false ;
if ( V_35 ) {
F_17 ( V_20 , V_35 ) ;
V_37 = F_22 ( sizeof( struct V_36 ) ,
V_93 ) ;
if ( ! V_37 )
return - V_49 ;
V_22 = F_9 ( V_20 , V_35 , V_37 ) ;
if ( V_22 )
goto V_94;
}
if ( V_20 -> V_67 == V_69 ||
V_20 -> V_67 == V_95 ) {
T_2 V_96 ;
V_22 = F_23 ( V_20 , NULL ) ;
if ( V_22 )
goto V_94;
if ( ! V_37 )
return - 1 ;
if ( F_24 ( V_37 -> V_59 ) ==
V_97 )
V_96 = V_98 | V_99 | V_100 | V_101 ;
else
V_96 = V_102 | V_103 | V_104 ;
if ( ! ( ( V_96 | V_12 -> V_105 ) & ~ V_12 -> V_105 ) )
V_12 -> V_96 = V_96 ;
V_22 = F_25 ( V_20 , V_37 ) ;
if ( V_22 )
goto V_94;
if ( F_26 ( V_20 ) ==
( T_2 ) V_37 -> V_106 ) {
F_5 ( V_12 -> V_4 ,
L_11 ,
V_37 -> V_106 ) ;
goto V_94;
}
F_7 ( V_12 -> V_4 , L_12
L_13 ) ;
F_27 ( V_20 -> V_107 , V_12 ) ;
if ( F_28 ( V_20 -> V_107 ) )
F_29 ( V_20 -> V_107 ) ;
V_20 -> V_108 = 0 ;
V_22 = F_30 ( V_20 , V_37 ) ;
if ( V_22 == V_109 &&
V_20 -> V_110 . V_111 &&
V_20 -> V_110 . V_112 ) {
V_20 -> V_110 . V_113 =
V_114 ;
V_22 = F_30 ( V_20 , V_37 ) ;
}
if ( V_35 )
F_31 ( V_20 -> V_12 -> V_84 , V_35 ) ;
} else {
if ( V_37 && V_37 -> V_115 . V_116 &&
( ! F_32 ( & V_20 -> V_117 . V_118 .
V_115 , & V_37 -> V_115 ) ) ) {
V_22 = 0 ;
goto V_94;
}
F_7 ( V_12 -> V_4 , L_14 ) ;
V_22 = F_23 ( V_20 , NULL ) ;
if ( V_22 )
goto V_94;
V_20 -> V_119 = false ;
V_22 = F_25 ( V_20 , V_37 ) ;
F_27 ( V_20 -> V_107 , V_12 ) ;
if ( F_28 ( V_20 -> V_107 ) )
F_29 ( V_20 -> V_107 ) ;
if ( ! V_22 ) {
F_7 ( V_12 -> V_4 , L_15
L_16 ) ;
V_22 = F_33 ( V_20 , V_37 ) ;
if ( V_35 )
F_31 ( V_20 -> V_12 -> V_84 , V_35 ) ;
} else {
F_7 ( V_12 -> V_4 , L_17
L_18 ,
V_91 -> V_115 ) ;
V_22 = F_34 ( V_20 , V_91 ) ;
}
}
V_94:
if ( V_37 )
F_35 ( V_37 -> V_53 ) ;
F_35 ( V_37 ) ;
return V_22 ;
}
static int F_36 ( struct V_19 * V_20 , T_1 V_120 ,
int V_121 , struct V_122 * V_123 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
int V_15 = 0 ;
T_4 V_124 = 0 ;
if ( ! V_123 )
return - V_49 ;
switch ( V_120 ) {
case V_32 :
if ( V_12 -> V_125 ) {
F_7 ( V_12 -> V_4 , L_19
L_20 ) ;
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
if ( V_121 == V_132 )
V_15 = F_39 ( V_20 ,
V_133 ,
V_32 , 0 ,
& V_12 -> V_123 ) ;
else
V_15 = F_8 ( V_20 ,
V_133 ,
V_32 , 0 ,
& V_12 -> V_123 ) ;
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
int F_40 ( struct V_19 * V_20 , int V_121 )
{
struct V_122 V_135 ;
V_135 . V_127 = V_128 ;
V_135 . V_126 = true ;
return F_36 ( V_20 , V_32 ,
V_121 , & V_135 ) ;
}
int F_41 ( struct V_11 * V_12 )
{
struct V_122 V_135 ;
struct V_19 * V_20 ;
int V_5 ;
if ( V_136 ) {
for ( V_5 = 0 ; V_5 < V_12 -> V_137 ; V_5 ++ ) {
V_20 = V_12 -> V_20 [ V_5 ] ;
if ( V_20 )
F_23 ( V_20 , NULL ) ;
}
}
if ( V_12 -> V_138 ) {
F_7 ( V_12 -> V_4 , L_21 ) ;
return true ;
}
V_12 -> V_139 = false ;
memset ( & V_135 , 0 , sizeof( struct V_122 ) ) ;
V_135 . V_126 = true ;
if ( F_36 ( F_42 ( V_12 ,
V_140 ) ,
V_32 , V_132 ,
& V_135 ) ) {
F_5 ( V_12 -> V_4 , L_22 ) ;
return false ;
}
if ( F_4 ( V_12 -> V_141 ,
V_12 -> V_139 ) ) {
F_5 ( V_12 -> V_4 , L_23 ) ;
return false ;
}
return true ;
}
int F_43 ( struct V_19 * V_20 ,
struct V_142 * V_143 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
struct V_36 * V_37 ;
if ( ! V_143 )
return - 1 ;
V_37 = & V_20 -> V_117 . V_118 ;
V_143 -> V_67 = V_20 -> V_67 ;
memcpy ( & V_143 -> V_115 , & V_37 -> V_115 , sizeof( struct V_90 ) ) ;
memcpy ( & V_143 -> V_51 , & V_37 -> V_50 , V_10 ) ;
V_143 -> V_144 = V_37 -> V_106 ;
memcpy ( V_143 -> V_75 , V_12 -> V_75 ,
V_85 ) ;
V_143 -> V_145 = V_20 -> V_145 ;
V_143 -> V_146 = V_20 -> V_147 ;
V_143 -> V_148 = V_20 -> V_149 ;
V_143 -> V_150 = V_20 -> V_150 ;
V_143 -> V_151 = V_20 -> V_151 ;
if ( V_20 -> V_110 . V_112 )
V_143 -> V_152 = true ;
else
V_143 -> V_152 = false ;
V_143 -> V_129 = V_12 -> V_129 ;
V_143 -> V_153 = V_12 -> V_153 ;
return 0 ;
}
int F_44 ( struct V_19 * V_20 )
{
struct V_154 V_155 ;
V_155 . V_155 = V_156 ;
return F_39 ( V_20 , V_157 ,
V_158 , V_159 , & V_155 ) ;
}
int F_45 ( struct V_19 * V_20 , T_4 * V_160 )
{
int V_22 ;
V_22 = F_39 ( V_20 , V_161 ,
V_134 , 0 , NULL ) ;
if ( ! V_22 ) {
if ( V_20 -> V_162 )
* V_160 = F_46 ( V_20 , V_20 -> V_163 ,
V_20 -> V_164 ) ;
else
* V_160 = V_20 -> V_165 ;
}
return V_22 ;
}
int F_47 ( struct V_19 * V_20 ,
struct V_166 * V_167 )
{
int V_22 ;
struct V_168 * V_169 ;
struct V_170 * V_171 ;
struct V_172 * V_173 ;
T_2 * V_174 ;
T_1 V_175 = 0 ;
if ( ! V_167 -> V_176 ) {
V_175 = ( T_1 ) V_167 -> V_177 ;
if ( ( V_175 < V_20 -> V_149 ) ||
( V_175 > V_20 -> V_147 ) ) {
F_5 ( V_20 -> V_12 -> V_4 , L_24
L_25 ,
V_175 , V_20 -> V_149 ,
V_20 -> V_147 ) ;
return - 1 ;
}
}
V_174 = F_22 ( V_178 , V_93 ) ;
if ( ! V_174 )
return - V_49 ;
V_169 = (struct V_168 * ) V_174 ;
V_169 -> V_120 = F_48 ( V_32 ) ;
if ( ! V_167 -> V_176 ) {
V_169 -> V_25 = F_38 ( 1 ) ;
V_171 = (struct V_170 * )
( V_174 + sizeof( struct V_168 ) ) ;
V_171 -> type = F_48 ( V_179 ) ;
V_171 -> V_180 =
F_48 ( 4 * sizeof( struct V_172 ) ) ;
V_173 = (struct V_172 * )
( V_174 + sizeof( struct V_168 )
+ sizeof( struct V_170 ) ) ;
V_173 -> V_181 = 0x00 ;
V_173 -> V_182 = 0x03 ;
V_173 -> V_183 = V_184 ;
V_173 -> V_185 = 0 ;
V_173 -> V_186 = ( V_187 ) V_175 ;
V_173 -> V_188 = ( V_187 ) V_175 ;
V_173 ++ ;
V_173 -> V_181 = 0x00 ;
V_173 -> V_182 = 0x07 ;
V_173 -> V_183 = V_189 ;
V_173 -> V_185 = 0 ;
V_173 -> V_186 = ( V_187 ) V_175 ;
V_173 -> V_188 = ( V_187 ) V_175 ;
V_173 ++ ;
V_173 -> V_181 = 0x00 ;
V_173 -> V_182 = 0x20 ;
V_173 -> V_183 = V_190 ;
V_173 -> V_185 = 0 ;
V_173 -> V_186 = ( V_187 ) V_175 ;
V_173 -> V_188 = ( V_187 ) V_175 ;
V_173 -> V_191 = V_192 ;
V_173 ++ ;
V_173 -> V_181 = 0x00 ;
V_173 -> V_182 = 0x20 ;
V_173 -> V_183 = V_190 ;
V_173 -> V_185 = 0 ;
V_173 -> V_186 = ( V_187 ) V_175 ;
V_173 -> V_188 = ( V_187 ) V_175 ;
V_173 -> V_191 = V_193 ;
}
V_22 = F_39 ( V_20 , V_194 ,
V_32 , 0 , V_174 ) ;
F_35 ( V_174 ) ;
return V_22 ;
}
int F_49 ( struct V_19 * V_20 , T_4 * V_195 )
{
int V_22 ;
struct V_11 * V_12 = V_20 -> V_12 ;
T_1 V_196 ;
if ( * V_195 )
V_12 -> V_195 = V_197 ;
else
V_12 -> V_195 = V_198 ;
V_196 = ( * V_195 ) ? V_199 : V_158 ;
V_22 = F_39 ( V_20 , V_157 ,
V_196 , V_200 , NULL ) ;
if ( ( ! V_22 ) && ( V_196 == V_158 ) )
V_22 = F_8 ( V_20 ,
V_157 ,
V_201 , 0 , NULL ) ;
return V_22 ;
}
static int F_50 ( struct V_19 * V_20 ,
T_2 * V_202 , T_1 V_203 )
{
if ( V_203 ) {
if ( V_203 > sizeof( V_20 -> V_204 ) ) {
F_5 ( V_20 -> V_12 -> V_4 ,
L_26 ) ;
return - 1 ;
}
memcpy ( V_20 -> V_204 , V_202 , V_203 ) ;
V_20 -> V_205 = ( T_2 ) V_203 ;
F_7 ( V_20 -> V_12 -> V_4 , L_27 ,
V_20 -> V_205 , V_20 -> V_204 [ 0 ] ) ;
if ( V_20 -> V_204 [ 0 ] == V_206 ) {
V_20 -> V_110 . V_207 = true ;
} else if ( V_20 -> V_204 [ 0 ] == V_208 ) {
V_20 -> V_110 . V_209 = true ;
} else {
V_20 -> V_110 . V_207 = false ;
V_20 -> V_110 . V_209 = false ;
}
} else {
memset ( V_20 -> V_204 , 0 , sizeof( V_20 -> V_204 ) ) ;
V_20 -> V_205 = 0 ;
F_7 ( V_20 -> V_12 -> V_4 , L_28 ,
V_20 -> V_205 , V_20 -> V_204 [ 0 ] ) ;
V_20 -> V_110 . V_207 = false ;
V_20 -> V_110 . V_209 = false ;
}
return 0 ;
}
static int F_51 ( struct V_19 * V_20 ,
T_2 * V_202 , T_1 V_203 )
{
if ( V_203 ) {
if ( V_203 > sizeof( V_20 -> V_210 ) ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_29 ) ;
return - 1 ;
}
memcpy ( V_20 -> V_210 , V_202 , V_203 ) ;
V_20 -> V_211 = V_203 ;
F_7 ( V_20 -> V_12 -> V_4 , L_30 ,
V_20 -> V_211 , V_20 -> V_210 [ 0 ] ) ;
if ( V_20 -> V_210 [ 0 ] == V_212 )
V_20 -> V_110 . V_213 = true ;
} else {
memset ( V_20 -> V_210 , 0 , sizeof( V_20 -> V_210 ) ) ;
V_20 -> V_211 = V_203 ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_31 ,
V_20 -> V_211 , V_20 -> V_210 [ 0 ] ) ;
V_20 -> V_110 . V_213 = false ;
}
return 0 ;
}
static int F_52 ( struct V_19 * V_20 ,
T_2 * V_202 , T_1 V_203 )
{
if ( V_203 ) {
if ( V_203 > V_214 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_32 ) ;
return - 1 ;
}
V_20 -> V_215 = F_22 ( V_214 , V_93 ) ;
if ( ! V_20 -> V_215 )
return - V_49 ;
memcpy ( V_20 -> V_215 , V_202 , V_203 ) ;
V_20 -> V_216 = V_203 ;
F_7 ( V_20 -> V_12 -> V_4 , L_33 ,
V_20 -> V_216 , V_20 -> V_215 [ 0 ] ) ;
} else {
F_35 ( V_20 -> V_215 ) ;
V_20 -> V_216 = V_203 ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_34 , V_20 -> V_216 ) ;
}
return 0 ;
}
static int F_53 ( struct V_19 * V_20 ,
struct V_217 * V_218 )
{
return F_39 ( V_20 , V_219 ,
V_32 , V_220 ,
V_218 ) ;
}
static int F_54 ( struct V_19 * V_20 ,
struct V_217 * V_218 )
{
int V_22 ;
struct V_221 * V_222 ;
int V_223 ;
if ( V_20 -> V_224 >= V_225 )
V_20 -> V_224 = 0 ;
V_222 = & V_20 -> V_222 [ V_20 -> V_224 ] ;
V_223 = V_218 -> V_226 ;
if ( V_218 -> V_227 ) {
V_20 -> V_110 . V_112 = 0 ;
} else if ( ! V_218 -> V_228 ) {
V_222 = & V_20 -> V_222 [ V_223 ] ;
if ( ! V_222 -> V_229 ) {
F_5 ( V_20 -> V_12 -> V_4 ,
L_35 ) ;
return - 1 ;
}
V_20 -> V_224 = ( T_1 ) V_223 ;
V_20 -> V_110 . V_112 = 1 ;
} else {
V_222 = & V_20 -> V_222 [ V_223 ] ;
memset ( V_222 , 0 , sizeof( struct V_221 ) ) ;
memcpy ( V_222 -> V_230 ,
V_218 -> V_230 ,
V_218 -> V_228 ) ;
V_222 -> V_226 = V_223 ;
V_222 -> V_229 = V_218 -> V_228 ;
V_20 -> V_110 . V_112 = 1 ;
}
if ( V_222 -> V_229 ) {
V_22 = F_8 ( V_20 ,
V_219 ,
V_32 , 0 , NULL ) ;
if ( V_22 )
return V_22 ;
}
if ( V_20 -> V_110 . V_112 )
V_20 -> V_24 |= V_231 ;
else
V_20 -> V_24 &= ~ V_231 ;
V_22 = F_39 ( V_20 , V_33 ,
V_32 , 0 ,
& V_20 -> V_24 ) ;
return V_22 ;
}
static int F_55 ( struct V_19 * V_20 ,
struct V_217 * V_218 )
{
int V_22 ;
T_2 V_232 = false ;
struct V_233 * V_234 ;
if ( V_218 -> V_228 > V_235 ) {
F_5 ( V_20 -> V_12 -> V_4 , L_36 ) ;
return - 1 ;
}
if ( V_20 -> V_67 == V_68 ) {
V_218 -> V_226 = V_236 ;
V_22 = F_8 ( V_20 ,
V_219 ,
V_32 ,
V_220 , V_218 ) ;
if ( V_22 )
return V_22 ;
V_234 = & V_20 -> V_237 ;
memset ( V_234 , 0 ,
sizeof( struct V_233 ) ) ;
memcpy ( V_234 -> V_238 . V_239 , V_218 -> V_230 ,
V_218 -> V_228 ) ;
memcpy ( & V_234 -> V_238 . V_228 , & V_218 -> V_228 ,
sizeof( V_234 -> V_238 . V_228 ) ) ;
V_234 -> V_238 . V_240
= F_48 ( V_241 ) ;
V_234 -> V_238 . V_242 = F_48 ( V_243 ) ;
V_218 -> V_226 = ~ V_236 ;
}
if ( ! V_218 -> V_226 )
V_218 -> V_226 = V_236 ;
if ( V_232 )
V_22 = F_39 ( V_20 ,
V_219 ,
V_32 ,
! V_220 , V_218 ) ;
else
V_22 = F_39 ( V_20 ,
V_219 ,
V_32 ,
V_220 , V_218 ) ;
return V_22 ;
}
static int
F_56 ( struct V_19 * V_20 ,
struct V_217 * V_218 )
{
int V_15 ;
if ( V_218 -> V_244 )
V_15 = F_53 ( V_20 , V_218 ) ;
else if ( V_218 -> V_228 > V_245 )
V_15 = F_55 ( V_20 , V_218 ) ;
else
V_15 = F_54 ( V_20 , V_218 ) ;
return V_15 ;
}
int
F_57 ( struct V_11 * V_12 , char * V_246 ,
int V_247 )
{
union {
T_4 V_248 ;
T_2 V_249 [ 4 ] ;
} V_250 ;
char V_251 [ 32 ] ;
V_250 . V_248 = V_12 -> V_252 ;
sprintf ( V_251 , L_37 , V_250 . V_249 [ 2 ] , V_250 . V_249 [ 1 ] , V_250 . V_249 [ 0 ] , V_250 . V_249 [ 3 ] ) ;
snprintf ( V_246 , V_247 , V_253 , V_251 ) ;
F_7 ( V_12 -> V_4 , L_38 , V_246 ) ;
return 0 ;
}
int F_58 ( struct V_19 * V_20 , struct V_254 * V_255 ,
const T_2 * V_239 , int V_228 , T_2 V_226 ,
const T_2 * V_256 , int V_257 )
{
struct V_217 V_218 ;
memset ( & V_218 , 0 , sizeof( struct V_217 ) ) ;
V_218 . V_228 = V_228 ;
if ( V_255 && V_255 -> V_258 == V_259 )
V_218 . V_260 = true ;
if ( ! V_257 ) {
V_218 . V_226 = V_226 ;
if ( V_228 )
memcpy ( V_218 . V_230 , V_239 , V_228 ) ;
if ( V_256 )
memcpy ( V_218 . V_256 , V_256 , V_10 ) ;
if ( V_255 && V_255 -> V_261 && V_255 -> V_262 )
memcpy ( V_218 . V_263 , V_255 -> V_261 , V_255 -> V_262 ) ;
} else {
V_218 . V_227 = true ;
if ( V_256 )
memcpy ( V_218 . V_256 , V_256 , V_10 ) ;
}
return F_56 ( V_20 , & V_218 ) ;
}
int
F_59 ( struct V_19 * V_20 )
{
struct V_264 V_265 ;
memset ( & V_265 , 0 , sizeof( struct V_266 ) ) ;
if ( F_39 ( V_20 , V_267 ,
V_134 , 0 , & V_265 ) )
return - 1 ;
return 0 ;
}
int
F_60 ( struct V_19 * V_20 , T_1 V_120 ,
struct V_268 * V_269 ,
unsigned int V_270 )
{
struct V_271 V_272 ;
T_2 V_273 ;
memset ( & V_272 , 0 , sizeof( V_272 ) ) ;
V_272 . V_120 = F_48 ( V_120 ) ;
if ( V_120 == V_32 ) {
V_272 . V_274 = V_269 -> V_60 ;
V_273 = F_61 ( V_275 ) ;
V_272 . V_274 |= ( V_273 << 2 ) ;
V_272 . V_106 =
F_62 ( V_269 -> V_276 ) ;
V_272 . V_270 = F_38 ( V_270 ) ;
}
if ( F_39 ( V_20 , V_277 ,
V_120 , 0 , & V_272 ) ) {
F_5 ( V_20 -> V_12 -> V_4 , L_39 ) ;
return - 1 ;
}
return V_272 . V_15 ;
}
int
F_63 ( struct V_19 * V_20 , T_2 V_278 )
{
if ( F_64 ( V_20 ) == V_278 ) {
F_7 ( V_20 -> V_12 -> V_4 ,
L_40 ) ;
return 0 ;
}
F_65 ( V_20 ) ;
F_66 ( V_20 ) ;
V_20 -> V_278 = V_278 ;
switch ( V_278 ) {
case V_279 :
V_20 -> V_67 = V_280 ;
break;
case V_140 :
case V_281 :
default:
V_20 -> V_67 = V_69 ;
break;
}
F_39 ( V_20 , V_282 ,
V_32 , 0 , NULL ) ;
return F_67 ( V_20 , false ) ;
}
int
F_68 ( struct V_19 * V_20 ,
struct V_283 * log )
{
return F_39 ( V_20 , V_284 ,
V_134 , 0 , log ) ;
}
static int F_69 ( struct V_19 * V_20 ,
struct V_285 * V_286 ,
T_1 V_120 )
{
T_1 V_287 ;
switch ( F_37 ( V_286 -> type ) ) {
case V_288 :
V_287 = V_289 ;
break;
case V_290 :
V_287 = V_291 ;
break;
case V_292 :
V_287 = V_293 ;
break;
case V_294 :
V_287 = V_295 ;
break;
case V_296 :
V_287 = V_297 ;
break;
default:
return - 1 ;
}
return F_39 ( V_20 , V_287 , V_120 , 0 , V_286 ) ;
}
int
F_70 ( struct V_19 * V_20 , T_4 V_298 ,
T_4 V_299 , T_4 V_300 )
{
struct V_285 V_286 ;
V_286 . type = F_38 ( V_298 ) ;
V_286 . V_301 = F_38 ( V_299 ) ;
V_286 . V_302 = F_38 ( V_300 ) ;
return F_69 ( V_20 , & V_286 , V_32 ) ;
}
int
F_71 ( struct V_19 * V_20 , T_4 V_298 ,
T_4 V_299 , T_4 * V_302 )
{
int V_22 ;
struct V_285 V_286 ;
V_286 . type = F_38 ( V_298 ) ;
V_286 . V_301 = F_38 ( V_299 ) ;
V_22 = F_69 ( V_20 , & V_286 , V_134 ) ;
if ( V_22 )
goto V_94;
* V_302 = F_37 ( V_286 . V_302 ) ;
V_94:
return V_22 ;
}
int
F_72 ( struct V_19 * V_20 , T_1 V_301 , T_1 V_303 ,
T_2 * V_302 )
{
int V_22 ;
struct V_304 V_305 ;
V_305 . V_301 = F_48 ( ( T_1 ) V_301 ) ;
V_305 . V_306 = F_48 ( ( T_1 ) V_303 ) ;
V_22 = F_39 ( V_20 , V_307 ,
V_134 , 0 , & V_305 ) ;
if ( ! V_22 )
memcpy ( V_302 , V_305 . V_302 , V_308 ) ;
return V_22 ;
}
static int
F_73 ( struct V_19 * V_20 , T_2 * V_202 ,
T_1 V_203 )
{
int V_22 = 0 ;
struct V_309 * V_310 ;
const T_2 V_311 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const T_2 V_312 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_203 ) {
V_20 -> V_313 = 0 ;
V_20 -> V_314 . V_315 = false ;
return 0 ;
} else if ( ! V_202 ) {
return - 1 ;
}
V_310 = (struct V_309 * ) V_202 ;
if ( ( ( V_310 -> V_316 == V_206 ) &&
( ! memcmp ( V_310 -> V_317 , V_311 , sizeof( V_311 ) ) ) ) ||
( V_310 -> V_316 == V_208 ) ) {
V_22 = F_50 ( V_20 , V_202 , V_203 ) ;
V_20 -> V_314 . V_315 = false ;
return V_22 ;
} else if ( V_310 -> V_316 == V_212 ) {
V_22 = F_51 ( V_20 , V_202 , V_203 ) ;
return V_22 ;
}
if ( V_203 < ( sizeof( V_20 -> V_318 ) - V_20 -> V_313 ) ) {
V_310 = (struct V_309 * ) V_202 ;
if ( ( V_310 -> V_316 == V_206 ) &&
( ! memcmp ( V_310 -> V_317 , V_312 , sizeof( V_312 ) ) ) ) {
V_20 -> V_314 . V_315 = true ;
F_7 ( V_20 -> V_12 -> V_4 ,
L_41 ) ;
V_22 = F_52 ( V_20 , V_202 , V_203 ) ;
}
memcpy ( V_20 -> V_318 + V_20 -> V_313 , V_202 ,
V_203 ) ;
V_20 -> V_313 += V_203 ;
} else {
V_22 = - 1 ;
}
return V_22 ;
}
static int F_74 ( struct V_19 * V_20 ,
struct V_319 * V_320 ,
T_1 V_120 )
{
struct V_11 * V_12 = V_20 -> V_12 ;
switch ( V_320 -> type ) {
case V_321 :
if ( V_120 == V_134 ) {
V_320 -> V_45 = V_20 -> V_205 ;
memcpy ( V_320 -> V_322 , V_20 -> V_204 , V_320 -> V_45 ) ;
} else {
F_73 ( V_20 , V_320 -> V_322 ,
( T_1 ) V_320 -> V_45 ) ;
}
break;
case V_323 :
memset ( V_12 -> V_324 , 0 , sizeof( V_12 -> V_324 ) ) ;
if ( V_320 -> V_45 > V_325 ) {
V_12 -> V_326 = 0 ;
F_5 ( V_12 -> V_4 , L_42 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_324 , V_320 -> V_322 ,
V_320 -> V_45 ) ;
V_12 -> V_326 = V_320 -> V_45 ;
}
break;
default:
F_5 ( V_12 -> V_4 , L_43 ) ;
return - 1 ;
}
return 0 ;
}
int
F_75 ( struct V_19 * V_20 , T_2 * V_327 , int V_203 )
{
struct V_319 V_320 ;
if ( V_203 > V_328 )
return - V_329 ;
V_320 . type = V_321 ;
V_320 . V_45 = V_203 ;
memcpy ( V_320 . V_322 , V_327 , V_203 ) ;
if ( F_74 ( V_20 , & V_320 , V_32 ) )
return - V_329 ;
return 0 ;
}
