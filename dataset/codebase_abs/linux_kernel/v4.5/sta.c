static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (event, tmp, list, link) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
}
int F_5 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
int V_11 = 0 ;
F_6 ( & V_10 -> V_12 , V_13 ) ;
F_7 ( & V_10 -> V_14 ) ;
F_8 ( & V_10 -> V_15 , 0 , 0x0002 , 0x0003 , 0x0007 , 47 , 0xc8 , false ) ;
F_8 ( & V_10 -> V_15 , 1 , 0x0002 , 0x0007 , 0x000f , 94 , 0xc8 , false ) ;
F_8 ( & V_10 -> V_15 , 2 , 0x0003 , 0x000f , 0x03ff , 0 , 0xc8 , false ) ;
F_8 ( & V_10 -> V_15 , 3 , 0x0007 , 0x000f , 0x03ff , 0 , 0xc8 , false ) ;
V_11 = F_9 ( V_10 , & V_10 -> V_15 ) ;
if ( V_11 )
goto V_16;
V_11 = F_10 ( V_10 , & V_10 -> V_15 ) ;
if ( V_11 )
goto V_16;
V_10 -> V_17 = false ;
memcpy ( V_10 -> V_18 , V_8 -> V_19 -> V_20 , V_21 ) ;
V_10 -> V_22 = V_23 ;
V_10 -> V_24 = - 1 ;
V_10 -> V_25 = 10 ;
V_11 = F_11 ( V_10 ) ;
if ( V_11 )
goto V_16;
V_16:
F_12 ( & V_10 -> V_14 ) ;
return V_11 ;
}
void F_13 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
F_14 ( V_2 ) ;
int V_26 ;
F_15 ( V_10 ) ;
while ( F_16 ( & V_10 -> V_27 . V_28 ) ) {
V_10 -> V_27 . V_29 = NULL ;
F_17 () ;
}
F_18 ( & V_10 -> V_27 . V_28 ) ;
F_19 ( & V_10 -> V_27 . V_30 ) ;
F_19 ( & V_10 -> V_27 . V_31 ) ;
F_19 ( & V_10 -> V_32 ) ;
F_19 ( & V_10 -> V_33 ) ;
F_20 ( V_10 , 0 , 0 , 0 ) ;
F_21 ( & V_10 -> V_34 ) ;
F_19 ( & V_10 -> V_35 ) ;
F_22 ( V_10 -> V_36 ) ;
F_23 ( & V_10 -> V_37 ) ;
F_7 ( & V_10 -> V_14 ) ;
V_10 -> V_22 = V_38 ;
V_10 -> V_39 = false ;
F_24 ( & V_10 -> V_40 ) ;
F_25 ( & V_10 -> V_41 , & V_2 ) ;
F_26 ( & V_10 -> V_40 ) ;
F_1 ( & V_2 ) ;
V_10 -> V_42 = V_43 ;
V_10 -> V_44 = false ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ )
F_27 ( & V_10 -> V_45 [ V_26 ] ) ;
F_12 ( & V_10 -> V_14 ) ;
F_28 ( V_10 ) ;
if ( F_29 ( & V_10 -> V_46 , 1 ) != 1 )
F_30 ( L_1 ) ;
F_31 ( V_10 ) ;
F_29 ( & V_10 -> V_46 , 0 ) ;
}
void F_32 ( struct V_9 * V_10 ,
int V_47 , int V_48 , int V_49 )
{
int V_50 = 0 ;
V_10 -> V_51 = 0 ;
F_21 ( & V_10 -> V_52 ) ;
F_30 ( L_2 ,
V_10 -> V_53 ,
V_47 , V_48 , V_49 ,
F_33 ( & V_10 -> V_46 ) ,
V_10 -> V_54 ) ;
if ( V_10 -> V_54 )
return;
if ( V_47 ) {
F_34 ( V_10 -> V_36 ,
& V_10 -> V_55 ,
V_13 ) ;
V_10 -> V_53 = 0 ;
if ( ! V_10 -> V_56 -> V_57 && ! F_33 ( & V_10 -> V_46 ) )
V_50 = 1 ;
} else if ( V_48 ) {
F_19 ( & V_10 -> V_55 ) ;
V_10 -> V_53 = 0 ;
F_35 ( V_10 -> V_36 , & V_10 -> V_52 ) ;
} else if ( V_49 ) {
if ( V_10 -> V_53 < 3 )
V_50 = 1 ;
} else {
F_19 ( & V_10 -> V_55 ) ;
V_10 -> V_53 = 0 ;
}
if ( ! V_58 )
V_50 = 0 ;
if ( V_50 ) {
struct V_59 * V_60 ;
V_10 -> V_53 ++ ;
V_60 = F_36 ( V_10 -> V_61 , V_10 -> V_56 ) ;
F_37 ( ! V_60 ) ;
if ( V_60 )
F_38 ( V_10 -> V_61 , NULL , V_60 ) ;
}
}
int F_39 ( struct V_7 * V_8 ,
struct V_62 * V_56 )
{
int V_11 ;
struct V_9 * V_10 = V_8 -> V_10 ;
V_56 -> V_63 |= V_64 |
V_65 |
V_66 ;
F_7 ( & V_10 -> V_14 ) ;
if ( V_10 -> V_22 != V_23 ) {
F_12 ( & V_10 -> V_14 ) ;
return - V_67 ;
}
switch ( V_56 -> type ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_10 -> V_22 = V_56 -> type ;
break;
default:
F_12 ( & V_10 -> V_14 ) ;
return - V_67 ;
}
V_10 -> V_56 = V_56 ;
memcpy ( V_10 -> V_18 , V_56 -> V_72 , V_21 ) ;
V_11 = F_11 ( V_10 ) ;
F_12 ( & V_10 -> V_14 ) ;
return V_11 ;
}
void F_40 ( struct V_7 * V_8 ,
struct V_62 * V_56 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_73 V_74 = {
. V_75 = true ,
} ;
int V_26 ;
F_7 ( & V_10 -> V_14 ) ;
switch ( V_10 -> V_42 ) {
case V_76 :
case V_77 :
case V_78 :
case V_79 :
F_15 ( V_10 ) ;
if ( F_35 ( V_10 -> V_36 , & V_10 -> V_34 ) <= 0 )
F_31 ( V_10 ) ;
break;
case V_80 :
for ( V_26 = 0 ; V_10 -> V_81 ; ++ V_26 ) {
if ( V_10 -> V_81 & F_41 ( V_26 ) ) {
V_74 . V_82 = V_26 ;
V_73 ( V_10 , & V_74 ) ;
V_10 -> V_81 &= ~ F_41 ( V_26 ) ;
}
}
memset ( V_10 -> V_83 , 0 , sizeof( V_10 -> V_83 ) ) ;
V_10 -> V_84 = 0 ;
V_10 -> V_85 = false ;
V_10 -> V_86 = false ;
V_10 -> V_87 = false ;
V_10 -> V_88 = false ;
V_10 -> V_89 = 0 ;
V_74 . V_82 = 0 ;
V_73 ( V_10 , & V_74 ) ;
break;
case V_90 :
F_42 ( V_10 , false ) ;
break;
default:
break;
}
V_10 -> V_56 = NULL ;
V_10 -> V_22 = V_23 ;
F_43 ( V_10 -> V_18 ) ;
memset ( & V_10 -> V_91 , 0 , sizeof( V_10 -> V_91 ) ) ;
F_44 ( V_10 ) ;
F_11 ( V_10 ) ;
V_10 -> V_39 = false ;
V_10 -> V_42 = V_43 ;
if ( ! F_45 ( V_10 , true ) )
F_31 ( V_10 ) ;
F_12 ( & V_10 -> V_14 ) ;
}
int F_46 ( struct V_7 * V_8 ,
struct V_62 * V_56 ,
enum V_92 V_93 ,
bool V_57 )
{
int V_11 = 0 ;
F_30 ( L_3 , V_93 ,
V_57 , V_56 -> type , V_56 -> V_57 ) ;
if ( V_93 != V_56 -> type || V_56 -> V_57 != V_57 ) {
F_40 ( V_8 , V_56 ) ;
V_56 -> type = V_93 ;
V_56 -> V_57 = V_57 ;
V_11 = F_39 ( V_8 , V_56 ) ;
}
return V_11 ;
}
int F_47 ( struct V_7 * V_8 , T_1 V_94 )
{
int V_11 = 0 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_95 * V_96 = & V_8 -> V_96 ;
F_30 ( L_4 , V_94 ) ;
F_48 ( & V_10 -> V_27 . V_28 ) ;
F_7 ( & V_10 -> V_14 ) ;
if ( V_94 & V_97 ) {
V_10 -> V_98 = V_96 -> V_99 ;
F_30 ( L_5 , V_10 -> V_98 ) ;
F_49 ( V_10 , V_10 -> V_98 * 10 ) ;
}
if ( ( V_94 & V_100 ) &&
( V_10 -> V_101 != V_96 -> V_102 . V_103 ) ) {
struct V_104 * V_105 = V_96 -> V_102 . V_103 ;
struct V_106 V_101 = {
. V_107 = V_105 -> V_108 ,
} ;
F_30 ( L_6 ,
V_105 -> V_109 , V_105 -> V_108 ) ;
if ( ! F_45 ( V_10 , false ) ) {
if ( ! V_106 ( V_10 , & V_101 ) ) {
V_11 = F_50 ( V_10 -> V_110 ,
! V_10 -> V_111 ,
3 * V_13 ) ;
if ( V_11 ) {
V_10 -> V_101 = V_105 ;
V_11 = 0 ;
} else {
V_11 = - V_112 ;
}
} else {
F_31 ( V_10 ) ;
}
}
}
if ( V_94 & V_113 ) {
if ( ! ( V_96 -> V_114 & V_115 ) )
V_10 -> V_116 . V_22 = V_117 ;
else if ( V_96 -> V_118 <= 0 )
V_10 -> V_116 . V_22 = V_119 ;
else
V_10 -> V_116 . V_22 = V_120 ;
if ( V_96 -> V_118 >= 0x80 )
V_10 -> V_116 . V_121 = 0xFF ;
else
V_10 -> V_116 . V_121 =
V_96 -> V_118 << 1 ;
if ( V_10 -> V_42 == V_78 &&
V_10 -> V_122 . V_123 )
F_51 ( V_10 , & V_10 -> V_116 ) ;
}
if ( V_94 & V_124 ) {
}
if ( V_94 & V_125 ) {
struct V_126 V_22 = {
. V_127 = V_128 ,
. V_129 = true ,
} ;
F_15 ( V_10 ) ;
if ( ( V_10 -> V_42 == V_90 ) &&
( V_96 -> V_114 & V_130 ) &&
! V_10 -> V_39 ) {
F_52 ( V_10 ) ;
V_10 -> V_42 = V_43 ;
}
F_53 ( V_10 , & V_22 ) ;
F_31 ( V_10 ) ;
}
if ( V_94 & V_131 ) {
F_30 ( L_7 ,
V_96 -> V_132 ,
V_96 -> V_133 ) ;
F_54 ( & V_10 -> V_134 . V_28 ) ;
V_10 -> V_132 = V_96 -> V_132 ;
V_10 -> V_133 =
( V_96 -> V_133 < 0x0F ) ?
V_96 -> V_133 : 0x0F ;
V_10 -> V_61 -> V_135 = V_10 -> V_133 ;
F_55 ( & V_10 -> V_134 . V_28 ) ;
}
F_12 ( & V_10 -> V_14 ) ;
F_18 ( & V_10 -> V_27 . V_28 ) ;
return V_11 ;
}
void F_56 ( struct V_9 * V_10 )
{
int V_11 ;
bool V_136 = ! V_10 -> V_137 . V_138 ;
bool V_139 = V_10 -> V_56 && V_10 -> V_56 -> V_57 ;
bool V_140 = V_10 -> V_56 && V_68 == V_10 -> V_56 -> type ;
static struct V_141 V_142 ;
static struct V_143 V_144 = {
. V_145 [ 0 ] . V_146 = V_147 ,
. V_145 [ 0 ] . V_114 = V_148 |
V_149 |
V_150 ,
. V_145 [ 0 ] . V_151 [ 0 ] = 0x50 ,
. V_145 [ 0 ] . V_151 [ 1 ] = 0x6F ,
. V_145 [ 0 ] . V_151 [ 2 ] = 0x9A ,
. V_145 [ 1 ] . V_146 = V_152 ,
. V_145 [ 1 ] . V_114 = V_148 |
V_149 |
V_150 ,
. V_145 [ 2 ] . V_146 = V_153 ,
. V_145 [ 2 ] . V_114 = V_148 |
V_149 |
V_150 ,
} ;
if ( V_10 -> V_42 == V_43 )
return;
else if ( V_10 -> V_42 == V_90 )
V_136 = false ;
if ( V_10 -> V_154 ) {
V_142 . V_155 = 0 ;
V_142 . V_156 = 1 ;
V_144 . V_157 = F_57 ( 0 ) ;
} else if ( V_139 || ! V_140 ) {
V_142 . V_155 = V_158 |
V_159 ;
V_142 . V_156 = 0 ;
V_144 . V_157 = F_57 ( 2 ) ;
} else {
V_142 . V_155 = V_158 ;
V_142 . V_156 = 0 ;
V_144 . V_157 = F_57 ( 3 ) ;
}
if ( V_139 )
V_136 = false ;
V_11 = F_58 ( V_10 , & V_10 -> V_137 ) ;
if ( ! V_11 )
V_11 = F_59 ( V_10 , & V_144 ) ;
if ( ! V_11 )
V_11 = V_141 ( V_10 , & V_142 ) ;
if ( ! V_11 )
V_11 = F_60 ( V_10 , V_136 ) ;
if ( ! V_11 )
V_11 = F_61 ( V_10 , & V_10 -> V_160 ) ;
if ( V_11 )
F_62 ( V_10 -> V_61 -> V_19 ,
L_8 , V_11 ) ;
return;
}
void F_63 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 ,
V_163 ) ;
F_56 ( V_10 ) ;
}
void F_65 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 ,
V_164 ) ;
F_66 ( V_10 ,
V_10 -> V_165 * V_10 -> V_166 >
V_167 ? 1 :
V_10 -> V_166 , 0 ) ;
}
T_2 F_67 ( struct V_7 * V_61 ,
struct V_168 * V_169 )
{
static T_3 V_170 [ V_21 ] = {
0x33 , 0x33 , 0x00 , 0x00 , 0x00 , 0x01
} ;
static T_3 V_171 [ V_21 ] = {
0x01 , 0x00 , 0x5e , 0x00 , 0x00 , 0x01
} ;
struct V_9 * V_10 = V_61 -> V_10 ;
struct V_172 * V_173 ;
int V_174 = 0 ;
V_10 -> V_175 = false ;
memset ( & V_10 -> V_160 , 0x00 , sizeof( V_10 -> V_160 ) ) ;
if ( F_68 ( V_169 ) > V_176 )
return 0 ;
F_69 (ha, mc_list) {
F_30 ( L_9 , V_173 -> V_72 ) ;
memcpy ( & V_10 -> V_160 . V_177 [ V_174 ] ,
V_173 -> V_72 , V_21 ) ;
if ( ! F_70 ( V_173 -> V_72 , V_171 ) &&
! F_70 ( V_173 -> V_72 , V_170 ) )
V_10 -> V_175 = true ;
V_174 ++ ;
}
if ( V_174 ) {
V_10 -> V_160 . V_178 = F_57 ( 1 ) ;
V_10 -> V_160 . V_179 = F_57 ( V_174 ) ;
}
return F_68 ( V_169 ) ;
}
void F_71 ( struct V_7 * V_8 ,
unsigned int V_180 ,
unsigned int * V_181 ,
T_2 V_182 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
bool V_39 = ! ! ( * V_181 &
( V_183 |
V_184 |
V_185 ) ) ;
* V_181 &= V_183 |
V_186 |
V_184 |
V_185 ;
F_48 ( & V_10 -> V_27 . V_28 ) ;
F_7 ( & V_10 -> V_14 ) ;
V_10 -> V_137 . V_187 = 0 ;
V_10 -> V_137 . V_138 = ( * V_181 & ( V_183 |
V_185 ) ) ? 1 : 0 ;
V_10 -> V_137 . V_188 = ( * V_181 & V_186 ) ? 1 : 0 ;
V_10 -> V_154 = ! ( * V_181 &
( V_184 |
V_185 ) ) ;
if ( V_10 -> V_39 != V_39 ) {
V_10 -> V_39 = V_39 ;
F_15 ( V_10 ) ;
F_42 ( V_10 , V_39 ) ;
F_31 ( V_10 ) ;
}
F_56 ( V_10 ) ;
F_12 ( & V_10 -> V_14 ) ;
F_18 ( & V_10 -> V_27 . V_28 ) ;
}
int F_72 ( struct V_7 * V_8 , struct V_62 * V_56 ,
T_4 V_189 , const struct V_190 * V_191 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
int V_11 = 0 ;
bool V_192 ;
F_7 ( & V_10 -> V_14 ) ;
if ( V_189 < V_8 -> V_193 ) {
V_192 = F_73 ( V_10 -> V_194 . V_195 ) ;
F_74 ( & V_10 -> V_196 , V_189 , 0 , 0 , 0 ) ;
V_11 = F_75 ( V_10 ,
& V_10 -> V_196 . V_191 [ V_189 ] , V_189 ) ;
if ( V_11 ) {
V_11 = - V_197 ;
goto V_16;
}
F_8 ( & V_10 -> V_15 , V_189 , V_191 -> V_198 ,
V_191 -> V_199 , V_191 -> V_200 ,
V_191 -> V_201 , 0xc8 ,
V_191 -> V_202 ) ;
V_11 = F_9 ( V_10 , & V_10 -> V_15 ) ;
if ( V_11 ) {
V_11 = - V_197 ;
goto V_16;
}
if ( V_10 -> V_22 == V_68 ) {
V_11 = F_10 ( V_10 , & V_10 -> V_15 ) ;
if ( ! V_11 && V_10 -> V_17 &&
( V_10 -> V_42 == V_78 ) &&
( V_192 != F_73 ( V_10 -> V_194 . V_195 ) ) )
V_11 = F_51 ( V_10 , & V_10 -> V_116 ) ;
}
} else {
V_11 = - V_197 ;
}
V_16:
F_12 ( & V_10 -> V_14 ) ;
return V_11 ;
}
int F_76 ( struct V_7 * V_8 ,
struct V_203 * V_204 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
memcpy ( V_204 , & V_10 -> V_204 , sizeof( * V_204 ) ) ;
return 0 ;
}
int F_51 ( struct V_9 * V_10 , const struct V_205 * V_206 )
{
struct V_205 V_207 = * V_206 ;
if ( V_10 -> V_194 . V_195 != 0 )
V_207 . V_22 &= ~ V_208 ;
if ( memcmp ( & V_207 , & V_10 -> V_209 ,
sizeof( struct V_205 ) ) ) {
V_10 -> V_209 = V_207 ;
return V_205 ( V_10 , & V_207 ) ;
} else {
return 0 ;
}
}
int F_77 ( struct V_7 * V_8 , enum V_210 V_211 ,
struct V_62 * V_56 , struct V_212 * V_213 ,
struct V_214 * V_215 )
{
int V_11 = - V_67 ;
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_216 V_217 ;
F_7 ( & V_10 -> V_14 ) ;
if ( V_211 == V_218 ) {
T_3 * V_219 = NULL ;
int V_220 = ( V_215 -> V_114 & V_221 ) ?
1 : 0 ;
int V_222 = F_78 ( V_10 ) ;
struct V_223 * V_224 = & V_10 -> V_225 [ V_222 ] ;
if ( V_222 < 0 ) {
V_11 = - V_197 ;
goto V_226;
}
if ( V_213 )
V_219 = V_213 -> V_72 ;
V_215 -> V_114 |= V_227 |
V_228 ;
switch ( V_215 -> V_229 ) {
case V_230 :
case V_231 :
if ( V_215 -> V_232 > 16 ) {
F_79 ( V_10 , V_222 ) ;
V_11 = - V_197 ;
goto V_226;
}
if ( V_220 ) {
V_224 -> type = V_233 ;
memcpy ( V_224 -> V_234 . V_235 ,
V_219 , V_21 ) ;
memcpy ( V_224 -> V_234 . V_236 ,
& V_215 -> V_215 [ 0 ] , V_215 -> V_232 ) ;
V_224 -> V_234 . V_232 = V_215 -> V_232 ;
} else {
V_224 -> type = V_237 ;
memcpy ( V_224 -> V_238 . V_236 ,
& V_215 -> V_215 [ 0 ] , V_215 -> V_232 ) ;
V_224 -> V_238 . V_232 = V_215 -> V_232 ;
V_224 -> V_238 . V_239 = V_215 -> V_240 ;
}
break;
case V_241 :
F_80 ( V_215 , 0 , & V_217 ) ;
if ( V_220 ) {
V_224 -> type = V_242 ;
memcpy ( V_224 -> V_243 . V_235 ,
V_219 , V_21 ) ;
memcpy ( V_224 -> V_243 . V_236 ,
& V_215 -> V_215 [ 0 ] , 16 ) ;
memcpy ( V_224 -> V_243 . V_244 ,
& V_215 -> V_215 [ 16 ] , 8 ) ;
memcpy ( V_224 -> V_243 . V_245 ,
& V_215 -> V_215 [ 24 ] , 8 ) ;
} else {
T_5 V_246 =
( V_10 -> V_22 == V_71 ) ?
16 : 24 ;
V_224 -> type = V_247 ;
memcpy ( V_224 -> V_248 . V_236 ,
& V_215 -> V_215 [ 0 ] , 16 ) ;
memcpy ( V_224 -> V_248 . V_245 ,
& V_215 -> V_215 [ V_246 ] , 8 ) ;
V_224 -> V_248 . V_249 [ 0 ] = V_217 . V_250 . V_251 & 0xff ;
V_224 -> V_248 . V_249 [ 1 ] = ( V_217 . V_250 . V_251 >> 8 ) & 0xff ;
V_224 -> V_248 . V_249 [ 2 ] = V_217 . V_250 . V_252 & 0xff ;
V_224 -> V_248 . V_249 [ 3 ] = ( V_217 . V_250 . V_252 >> 8 ) & 0xff ;
V_224 -> V_248 . V_249 [ 4 ] = ( V_217 . V_250 . V_252 >> 16 ) & 0xff ;
V_224 -> V_248 . V_249 [ 5 ] = ( V_217 . V_250 . V_252 >> 24 ) & 0xff ;
V_224 -> V_248 . V_249 [ 6 ] = 0 ;
V_224 -> V_248 . V_249 [ 7 ] = 0 ;
V_224 -> V_248 . V_239 = V_215 -> V_240 ;
}
break;
case V_253 :
F_80 ( V_215 , 0 , & V_217 ) ;
if ( V_220 ) {
V_224 -> type = V_254 ;
memcpy ( V_224 -> V_255 . V_235 ,
V_219 , V_21 ) ;
memcpy ( V_224 -> V_255 . V_236 ,
& V_215 -> V_215 [ 0 ] , 16 ) ;
} else {
V_224 -> type = V_256 ;
memcpy ( V_224 -> V_257 . V_236 ,
& V_215 -> V_215 [ 0 ] , 16 ) ;
V_224 -> V_257 . V_249 [ 0 ] = V_217 . V_258 . V_259 [ 5 ] ;
V_224 -> V_257 . V_249 [ 1 ] = V_217 . V_258 . V_259 [ 4 ] ;
V_224 -> V_257 . V_249 [ 2 ] = V_217 . V_258 . V_259 [ 3 ] ;
V_224 -> V_257 . V_249 [ 3 ] = V_217 . V_258 . V_259 [ 2 ] ;
V_224 -> V_257 . V_249 [ 4 ] = V_217 . V_258 . V_259 [ 1 ] ;
V_224 -> V_257 . V_249 [ 5 ] = V_217 . V_258 . V_259 [ 0 ] ;
V_224 -> V_257 . V_249 [ 6 ] = 0 ;
V_224 -> V_257 . V_249 [ 7 ] = 0 ;
V_224 -> V_257 . V_239 = V_215 -> V_240 ;
}
break;
case V_260 :
if ( V_220 ) {
V_224 -> type = V_261 ;
memcpy ( V_224 -> V_262 . V_235 ,
V_219 , V_21 ) ;
memcpy ( V_224 -> V_262 . V_236 ,
& V_215 -> V_215 [ 0 ] , 16 ) ;
memcpy ( V_224 -> V_262 . V_263 ,
& V_215 -> V_215 [ 16 ] , 16 ) ;
V_224 -> V_262 . V_239 = V_215 -> V_240 ;
} else {
V_224 -> type = V_264 ;
memcpy ( V_224 -> V_265 . V_236 ,
& V_215 -> V_215 [ 0 ] , 16 ) ;
memcpy ( V_224 -> V_265 . V_263 ,
& V_215 -> V_215 [ 16 ] , 16 ) ;
V_224 -> V_265 . V_239 = V_215 -> V_240 ;
}
break;
default:
F_81 ( L_10 , V_215 -> V_229 ) ;
F_79 ( V_10 , V_222 ) ;
V_11 = - V_67 ;
goto V_226;
}
V_11 = V_223 ( V_10 , V_224 ) ;
if ( ! V_11 )
V_215 -> V_266 = V_222 ;
else
F_79 ( V_10 , V_222 ) ;
} else if ( V_211 == V_267 ) {
struct V_268 V_224 = {
. V_269 = V_215 -> V_266 ,
} ;
if ( V_224 . V_269 > V_270 ) {
V_11 = - V_197 ;
goto V_226;
}
F_79 ( V_10 , V_224 . V_269 ) ;
V_11 = V_268 ( V_10 , & V_224 ) ;
} else {
F_81 ( L_11 , V_211 ) ;
}
V_226:
F_12 ( & V_10 -> V_14 ) ;
return V_11 ;
}
void F_82 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_271 ) ;
T_3 V_272 = F_83 ( V_10 -> V_273 ) ;
struct V_274 * V_189 = & V_10 -> V_45 [ V_272 ] ;
T_6 V_24 = F_57 (
V_10 -> V_24 ) ;
F_30 ( L_12 ,
V_10 -> V_24 ) ;
F_84 ( V_10 ) ;
F_85 ( V_10 , V_275 ,
& V_24 , sizeof( V_24 ) ) ;
F_86 ( V_189 , V_10 -> V_273 ) ;
F_31 ( V_10 ) ;
}
int F_87 ( struct V_7 * V_61 , T_1 V_276 )
{
int V_11 = 0 ;
T_6 V_277 ;
struct V_9 * V_10 = V_61 -> V_10 ;
if ( V_10 -> V_22 == V_38 )
return 0 ;
if ( V_276 != ( T_1 ) - 1 )
V_277 = F_57 ( V_276 ) ;
else
V_277 = 0 ;
if ( V_10 -> V_278 == V_276 )
goto V_16;
F_30 ( L_13 ,
V_10 -> V_278 ) ;
V_11 = F_85 ( V_10 , V_279 ,
& V_277 , sizeof( V_277 ) ) ;
if ( ! V_11 )
V_10 -> V_278 = V_276 ;
V_16:
return V_11 ;
}
static int F_45 ( struct V_9 * V_10 , bool V_280 )
{
int V_26 , V_11 ;
for (; ; ) {
if ( V_280 ) {
for ( V_26 = 0 ; V_26 < 4 ; ++ V_26 )
F_27 ( & V_10 -> V_45 [ V_26 ] ) ;
} else {
V_11 = F_50 (
V_10 -> V_281 . V_282 ,
F_88 (
& V_10 -> V_281 , - 1 ) ,
2 * V_13 ) ;
}
if ( ! V_280 && V_11 <= 0 ) {
V_11 = - V_112 ;
break;
} else {
V_11 = 0 ;
}
F_15 ( V_10 ) ;
if ( ! F_88 ( & V_10 -> V_281 , - 1 ) ) {
F_31 ( V_10 ) ;
continue;
}
break;
}
return V_11 ;
}
void F_89 ( struct V_7 * V_61 , struct V_62 * V_56 ,
T_1 V_193 , bool V_280 )
{
struct V_9 * V_10 = V_61 -> V_10 ;
switch ( V_10 -> V_22 ) {
case V_23 :
V_280 = true ;
break;
case V_71 :
if ( ! V_10 -> V_85 )
V_280 = true ;
break;
}
if ( ! F_45 ( V_10 , V_280 ) )
F_31 ( V_10 ) ;
return;
}
void F_90 ( struct V_9 * V_10 )
{
F_14 ( V_2 ) ;
F_24 ( & V_10 -> V_40 ) ;
F_25 ( & V_10 -> V_41 , & V_2 ) ;
F_26 ( & V_10 -> V_40 ) ;
F_1 ( & V_2 ) ;
}
void F_91 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_283 ) ;
struct V_3 * V_4 ;
F_14 ( V_2 ) ;
F_24 ( & V_10 -> V_40 ) ;
F_25 ( & V_10 -> V_41 , & V_2 ) ;
F_26 ( & V_10 -> V_40 ) ;
F_92 (event, &list, link) {
switch ( V_4 -> V_284 . V_285 ) {
case V_286 :
F_93 ( L_14 ) ;
break;
case V_287 :
F_30 ( L_15 ) ;
F_21 ( & V_10 -> V_34 ) ;
if ( ! F_16 ( & V_10 -> V_27 . V_28 ) ) {
F_20 ( V_10 , 1 , 0 , 0 ) ;
F_18 ( & V_10 -> V_27 . V_28 ) ;
} else {
V_10 -> V_51 = 1 ;
F_34 ( V_10 -> V_36 ,
& V_10 -> V_55 , 5 * V_13 ) ;
}
break;
case V_288 :
F_30 ( L_16 ) ;
F_20 ( V_10 , 0 , 0 , 0 ) ;
F_21 ( & V_10 -> V_34 ) ;
break;
case V_289 :
F_94 ( V_10 -> V_61 -> V_19 , L_17 ) ;
break;
case V_290 :
{
int V_291 = ( int ) ( V_4 -> V_284 . V_292 & 0xFF ) ;
int V_293 ;
if ( V_10 -> V_294 )
V_291 = ( V_295 ) V_291 ;
else
V_291 = V_291 / 2 - 110 ;
V_293 = ( V_291 <= V_10 -> V_296 ) ?
V_297 :
V_298 ;
F_30 ( L_18 , V_291 ) ;
F_95 ( V_10 -> V_56 , V_293 ,
V_299 ) ;
break;
}
case V_300 :
F_81 ( L_19 ) ;
break;
case V_301 :
F_81 ( L_20 ) ;
break;
}
}
F_1 ( & V_2 ) ;
}
void F_96 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_55 . V_162 ) ;
F_30 ( L_21 ) ;
F_15 ( V_10 ) ;
if ( F_35 ( V_10 -> V_36 , & V_10 -> V_34 ) <= 0 )
F_31 ( V_10 ) ;
}
void F_97 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_52 ) ;
F_7 ( & V_10 -> V_14 ) ;
V_10 -> V_122 . V_302 = 1 ;
F_98 ( V_10 , & V_10 -> V_122 ) ;
V_10 -> V_122 . V_302 = 0 ;
F_12 ( & V_10 -> V_14 ) ;
}
static int F_99 ( struct V_9 * V_10 )
{
const T_3 * V_303 = V_10 -> V_304 -> V_292 ;
int V_11 = 0 ;
while ( V_303 + 2 <= V_10 -> V_304 -> V_292 + V_10 -> V_304 -> V_305 ) {
if ( V_303 + V_303 [ 1 ] + 2 > V_10 -> V_304 -> V_292 + V_10 -> V_304 -> V_305 ) {
F_81 ( L_22 ) ;
return - 1 ;
}
switch ( V_303 [ 0 ] ) {
case V_306 : {
T_4 V_307 ;
if ( V_303 [ 1 ] < 4 ) {
F_81 ( L_23 ) ;
V_11 = - 1 ;
break;
}
V_307 = F_73 ( * ( ( V_308 * ) ( V_303 + 2 ) ) ) ;
if ( ! V_307 )
break;
V_307 = F_73 ( * ( ( V_308 * ) ( V_303 + 4 ) ) ) ;
V_10 -> V_309 = ( V_307 >> 7 ) & 0x1F ;
F_30 ( L_24 ,
V_10 -> V_309 ) ;
break;
}
case V_310 : {
T_4 V_311 = F_73 ( * ( ( V_308 * ) ( V_303 + 2 ) ) ) ;
if ( V_311 != V_10 -> V_312 )
F_81 ( L_25 ,
V_311 , V_10 -> V_312 ) ;
break;
}
default:
break;
}
V_303 += V_303 [ 1 ] + 2 ;
}
if ( ! V_10 -> V_313 ) {
F_30 ( L_26 ) ;
V_10 -> V_309 = 0 ;
}
return V_11 ;
}
int F_11 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_314 V_315 = {
. V_316 = V_317 |
V_318 |
V_319 ,
. V_320 = 16 ,
} ;
struct V_321 V_322 = {
. V_323 = & V_10 -> V_18 [ 0 ] ,
} ;
if ( V_315 . V_316 & V_324 )
V_10 -> V_294 = true ;
if ( ! V_10 -> V_304 ) {
V_11 = F_100 ( & V_10 -> V_304 , V_10 -> V_325 , V_10 -> V_326 ) ;
if ( V_11 ) {
F_93 ( L_27 , V_10 -> V_325 ) ;
return V_11 ;
}
F_99 ( V_10 ) ;
}
V_322 . V_327 = V_10 -> V_304 -> V_292 ;
V_322 . V_328 = V_10 -> V_304 -> V_305 ;
V_11 = V_321 ( V_10 , & V_322 ) ;
if ( V_11 )
return V_11 ;
F_101 ( V_10 , & V_315 ) ;
return 0 ;
}
static void F_102 ( struct V_9 * V_10 )
{
F_30 ( L_28 , V_10 -> V_329 ) ;
V_10 -> V_44 = false ;
if ( V_10 -> V_329 ) {
V_10 -> V_42 = V_43 ;
F_42 ( V_10 , V_10 -> V_39 ) ;
F_103 ( V_10 ) ;
F_104 ( V_10 -> V_56 ) ;
} else {
if ( V_10 -> V_22 == V_69 )
V_10 -> V_42 = V_79 ;
else
V_10 -> V_42 = V_77 ;
}
F_31 ( V_10 ) ;
}
void F_105 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_330 ) ;
F_7 ( & V_10 -> V_14 ) ;
F_102 ( V_10 ) ;
F_12 ( & V_10 -> V_14 ) ;
}
void F_106 ( struct V_9 * V_10 ,
struct V_331 * V_206 )
{
F_30 ( L_29 ,
V_206 -> V_332 ) ;
if ( F_107 ( & V_10 -> V_33 ) ) {
V_10 -> V_329 = V_206 -> V_332 ;
F_35 ( V_10 -> V_36 , & V_10 -> V_330 ) ;
}
}
static void F_108 ( struct V_9 * V_10 )
{
const T_3 * V_138 ;
struct V_333 * V_96 = & V_10 -> V_56 -> V_334 ;
struct V_335 * V_336 = NULL ;
struct V_337 V_338 ;
struct V_339 V_340 = {
. V_22 = V_96 -> V_341 ?
V_342 : V_343 ,
. V_344 = V_345 ,
. V_346 = 1 ,
. V_347 = 0 ,
. V_348 = F_109 ( V_10 ,
V_96 -> V_349 ) ,
} ;
if ( F_110 ( & V_10 -> V_33 ) ) {
F_81 ( L_30 ) ;
F_31 ( V_10 ) ;
return;
}
if ( V_10 -> V_42 )
F_103 ( V_10 ) ;
V_138 = V_10 -> V_56 -> V_334 . V_138 ;
V_336 = F_111 ( V_10 -> V_61 -> V_19 , V_10 -> V_101 , V_138 , NULL , 0 ,
V_350 , V_351 ) ;
if ( ! V_336 && ! V_96 -> V_341 ) {
F_31 ( V_10 ) ;
return;
}
F_7 ( & V_10 -> V_14 ) ;
if ( F_33 ( & V_10 -> V_27 . V_352 ) ) {
F_31 ( V_10 ) ;
goto V_353;
}
V_10 -> V_44 = true ;
if ( ! V_340 . V_348 )
V_340 . V_348 = 7 ;
if ( ! V_10 -> V_165 )
V_10 -> V_165 = 1 ;
V_340 . V_354 = V_10 -> V_165 ;
if ( V_10 -> V_313 ) {
if ( ( ( V_10 -> V_309 * 100 ) %
V_10 -> V_165 ) == 0 )
V_10 -> V_355 =
( ( V_10 -> V_309 * 100 ) /
V_10 -> V_165 ) ;
else
V_10 -> V_355 =
( ( V_10 -> V_309 * 100 ) /
V_10 -> V_165 + 1 ) ;
}
if ( V_10 -> V_61 -> V_96 . V_356 )
V_10 -> V_166 = V_10 -> V_61 -> V_96 . V_356 ;
V_340 . V_357 = V_10 -> V_166 ;
V_340 . V_107 = V_10 -> V_101 -> V_108 ;
V_340 . V_358 = ( V_10 -> V_101 -> V_358 == V_359 ) ?
V_360 : V_361 ;
memcpy ( V_340 . V_138 , V_138 , sizeof( V_340 . V_138 ) ) ;
F_30 ( L_31 ,
V_340 . V_138 ,
V_340 . V_357 , V_10 -> V_165 ) ;
if ( ! V_96 -> V_341 ) {
const T_3 * V_362 ;
F_112 () ;
V_362 = F_113 ( V_336 , V_363 ) ;
if ( V_362 ) {
V_340 . V_364 = V_362 [ 1 ] ;
memcpy ( V_340 . V_365 , & V_362 [ 2 ] , V_340 . V_364 ) ;
}
F_114 () ;
}
if ( V_10 -> V_56 -> V_57 ) {
V_340 . V_114 |= V_366 ;
V_340 . V_348 =
F_109 ( V_10 , 0xFF0 ) ;
}
if ( ! V_96 -> V_341 ) {
V_340 . V_114 |= V_367 ;
V_340 . V_114 |= V_368 ;
}
F_84 ( V_10 ) ;
F_6 ( & V_10 -> V_12 ,
V_369 + V_370 ) ;
F_42 ( V_10 , false ) ;
F_115 ( V_10 , V_10 -> V_371 ,
V_10 -> V_372 ) ;
if ( V_340 . V_114 & V_368 ) {
V_10 -> V_42 = V_76 ;
F_34 ( V_10 -> V_36 ,
& V_10 -> V_33 ,
V_369 ) ;
}
V_338 . V_373 = 0 ;
V_338 . V_374 = 1 ;
V_338 . V_375 = 1 ;
F_116 ( V_10 , & V_338 ) ;
if ( V_339 ( V_10 , & V_340 ) ) {
F_93 ( L_32 ) ;
F_19 ( & V_10 -> V_33 ) ;
F_42 ( V_10 , V_10 -> V_39 ) ;
if ( F_35 ( V_10 -> V_36 , & V_10 -> V_34 ) <= 0 )
F_31 ( V_10 ) ;
} else {
if ( ! ( V_340 . V_114 & V_368 ) )
F_102 ( V_10 ) ;
F_117 ( V_10 ) ;
V_10 -> V_154 = true ;
}
F_56 ( V_10 ) ;
V_353:
F_12 ( & V_10 -> V_14 ) ;
if ( V_336 )
F_118 ( V_10 -> V_61 -> V_19 , V_336 ) ;
}
void F_119 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_33 . V_162 ) ;
F_30 ( L_33 ) ;
F_15 ( V_10 ) ;
if ( F_35 ( V_10 -> V_36 , & V_10 -> V_34 ) <= 0 )
F_31 ( V_10 ) ;
}
static void F_103 ( struct V_9 * V_10 )
{
struct V_73 V_74 = {
. V_75 = true ,
} ;
F_19 ( & V_10 -> V_33 ) ;
F_7 ( & V_10 -> V_14 ) ;
V_10 -> V_44 = false ;
if ( F_33 ( & V_10 -> V_27 . V_352 ) ) {
if ( V_10 -> V_54 )
F_120 ( V_10 -> V_61 -> V_19 , L_34 ) ;
else
V_10 -> V_54 = true ;
goto V_376;
}
V_10 -> V_51 = false ;
if ( ! V_10 -> V_42 )
goto V_376;
if ( V_10 -> V_42 == V_80 )
goto V_376;
F_21 ( & V_10 -> V_163 ) ;
F_21 ( & V_10 -> V_164 ) ;
V_10 -> V_42 = V_43 ;
F_84 ( V_10 ) ;
F_121 ( V_10 , 0 ) ;
V_73 ( V_10 , & V_74 ) ;
F_49 ( V_10 , V_10 -> V_98 * 10 ) ;
V_10 -> V_166 = 0 ;
F_11 ( V_10 ) ;
F_90 ( V_10 ) ;
F_21 ( & V_10 -> V_283 ) ;
F_42 ( V_10 , V_10 -> V_39 ) ;
F_20 ( V_10 , 0 , 0 , 0 ) ;
F_115 ( V_10 , 0 , 0 ) ;
V_10 -> V_154 = false ;
F_56 ( V_10 ) ;
memset ( & V_10 -> V_377 , 0 ,
sizeof( V_10 -> V_377 ) ) ;
memset ( & V_10 -> V_122 , 0 , sizeof( V_10 -> V_122 ) ) ;
V_10 -> V_17 = false ;
memset ( & V_10 -> V_209 , 0 ,
sizeof( V_10 -> V_209 ) ) ;
F_30 ( L_35 ) ;
V_376:
F_12 ( & V_10 -> V_14 ) ;
}
void F_122 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_34 ) ;
F_103 ( V_10 ) ;
F_104 ( V_10 -> V_56 ) ;
F_31 ( V_10 ) ;
}
int F_123 ( struct V_9 * V_10 )
{
struct V_378 V_379 = {
. V_22 = V_380 ,
. V_358 = V_361 ,
. V_354 = 100 ,
. V_357 = 1 ,
. V_381 = 0 ,
. V_348 = 0x0F ,
} ;
if ( V_10 -> V_101 ) {
V_379 . V_358 = V_10 -> V_101 -> V_358 == V_359 ?
V_360 : V_361 ;
V_379 . V_107 = V_10 -> V_101 -> V_108 ;
} else {
V_379 . V_358 = V_361 ;
V_379 . V_107 = 1 ;
}
return V_378 ( V_10 , & V_379 ) ;
}
int F_52 ( struct V_9 * V_10 )
{
int V_11 ;
struct V_73 V_74 = {
. V_75 = true ,
} ;
V_11 = V_73 ( V_10 , & V_74 ) ;
return V_11 ;
}
void F_42 ( struct V_9 * V_10 , bool V_155 )
{
if ( V_155 ) {
if ( V_10 -> V_42 == V_43 ) {
if ( ! F_123 ( V_10 ) )
V_10 -> V_42 = V_90 ;
F_124 ( V_10 , true ) ;
}
} else {
if ( V_10 -> V_42 == V_90 ) {
if ( ! F_52 ( V_10 ) )
V_10 -> V_42 = V_43 ;
F_124 ( V_10 , false ) ;
}
}
}
int F_10 ( struct V_9 * V_10 ,
const struct V_382 * V_206 )
{
int V_11 ;
T_4 V_195 = 0 ;
if ( V_206 -> V_383 [ 0 ] )
V_195 |= 1 << 3 ;
if ( V_206 -> V_383 [ 1 ] )
V_195 |= 1 << 2 ;
if ( V_206 -> V_383 [ 2 ] )
V_195 |= 1 << 1 ;
if ( V_206 -> V_383 [ 3 ] )
V_195 |= 1 ;
V_10 -> V_194 . V_195 = F_125 ( V_195 ) ;
V_10 -> V_194 . V_384 = 0 ;
V_10 -> V_194 . V_385 = 0 ;
V_10 -> V_194 . V_386 = 0 ;
V_11 = F_126 ( V_10 , & V_10 -> V_194 ) ;
return V_11 ;
}
int F_127 ( struct V_7 * V_61 , struct V_62 * V_56 ,
struct V_212 * V_213 )
{
struct V_9 * V_10 = V_61 -> V_10 ;
struct V_387 * V_388 =
(struct V_387 * ) & V_213 -> V_389 ;
struct V_390 * V_145 ;
struct V_59 * V_60 ;
if ( V_10 -> V_22 != V_71 )
return 0 ;
V_388 -> V_82 = F_128 ( V_10 , V_213 -> V_72 ) ;
if ( F_37 ( ! V_388 -> V_82 ) ) {
F_94 ( V_10 -> V_61 -> V_19 ,
L_36 ) ;
return - V_391 ;
}
V_145 = & V_10 -> V_83 [ V_388 -> V_82 - 1 ] ;
F_54 ( & V_10 -> V_392 ) ;
if ( ( V_213 -> V_393 & V_394 ) ==
V_394 )
V_10 -> V_84 |= F_41 ( V_388 -> V_82 ) ;
V_145 -> V_332 = V_395 ;
while ( ( V_60 = F_129 ( & V_145 -> V_396 ) ) )
F_130 ( V_10 -> V_61 , V_60 ) ;
F_55 ( & V_10 -> V_392 ) ;
return 0 ;
}
int F_131 ( struct V_7 * V_61 , struct V_62 * V_56 ,
struct V_212 * V_213 )
{
struct V_9 * V_10 = V_61 -> V_10 ;
struct V_387 * V_388 =
(struct V_387 * ) & V_213 -> V_389 ;
struct V_390 * V_145 ;
if ( V_10 -> V_22 != V_71 || ! V_388 -> V_82 )
return 0 ;
V_145 = & V_10 -> V_83 [ V_388 -> V_82 - 1 ] ;
F_54 ( & V_10 -> V_392 ) ;
V_145 -> V_332 = V_397 ;
V_145 -> V_398 = V_399 ;
F_132 ( V_10 ) ;
if ( F_35 ( V_10 -> V_36 , & V_10 -> V_400 ) <= 0 )
F_31 ( V_10 ) ;
F_55 ( & V_10 -> V_392 ) ;
F_22 ( V_10 -> V_36 ) ;
return 0 ;
}
static void F_133 ( struct V_7 * V_8 ,
struct V_62 * V_56 ,
enum V_401 V_402 ,
int V_82 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
T_1 V_403 , V_404 ;
if ( V_82 )
V_403 = F_41 ( V_82 ) ;
else if ( F_134 ( V_402 != V_405 ) )
V_403 = 0 ;
else
V_403 = V_10 -> V_81 ;
V_404 = V_10 -> V_84 & V_403 ;
switch ( V_402 ) {
case V_406 :
if ( ! V_404 ) {
if ( V_10 -> V_88 &&
! V_10 -> V_84 )
F_35 ( V_10 -> V_36 ,
& V_10 -> V_407 ) ;
V_10 -> V_84 |= V_403 ;
}
break;
case V_405 :
if ( V_404 ) {
V_10 -> V_84 &= ~ V_403 ;
V_10 -> V_89 &= ~ V_403 ;
if ( V_10 -> V_86 && V_82 &&
! V_10 -> V_84 )
F_35 ( V_10 -> V_36 ,
& V_10 -> V_408 ) ;
F_135 ( V_10 ) ;
}
break;
}
}
void F_136 ( struct V_7 * V_8 ,
struct V_62 * V_56 ,
enum V_401 V_402 ,
struct V_212 * V_213 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
struct V_387 * V_388 =
(struct V_387 * ) & V_213 -> V_389 ;
F_54 ( & V_10 -> V_392 ) ;
F_133 ( V_8 , V_56 , V_402 , V_388 -> V_82 ) ;
F_55 ( & V_10 -> V_392 ) ;
}
static void F_137 ( struct V_9 * V_10 ,
int V_82 , bool V_409 )
{
if ( V_82 > V_410 )
return;
F_30 ( L_37 ,
V_409 ? L_38 : L_39 ,
V_82 , V_10 -> V_84 ) ;
F_133 ( V_10 -> V_61 , V_10 -> V_56 ,
V_409 ? V_406 : V_405 , V_82 ) ;
}
static int F_138 ( struct V_9 * V_10 , bool V_87 )
{
struct V_59 * V_60 ;
struct V_411 V_412 = {
. V_413 = V_414 ,
. V_174 = 1 ,
} ;
T_4 V_415 , V_416 ;
F_30 ( L_40 , V_87 ? L_41 : L_42 ) ;
V_60 = F_139 ( V_10 -> V_61 , V_10 -> V_56 ,
& V_415 , & V_416 ) ;
if ( ! V_60 ) {
if ( ! F_45 ( V_10 , true ) )
F_31 ( V_10 ) ;
return - V_391 ;
}
if ( V_415 && V_416 >= 6 ) {
V_60 -> V_292 [ V_415 + 2 ] = 0 ;
if ( V_87 )
V_60 -> V_292 [ V_415 + 4 ] |= 1 ;
else
V_60 -> V_292 [ V_415 + 4 ] &= ~ 1 ;
}
V_412 . V_417 = & V_60 -> V_292 [ V_415 ] ;
V_412 . V_418 = V_416 ;
V_411 ( V_10 , & V_412 ) ;
F_140 ( V_60 ) ;
return 0 ;
}
void F_141 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_419 ) ;
( void ) F_138 ( V_10 , V_10 -> V_87 ) ;
}
int F_142 ( struct V_7 * V_8 , struct V_212 * V_213 ,
bool V_420 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
F_35 ( V_10 -> V_36 , & V_10 -> V_419 ) ;
return 0 ;
}
void F_143 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_421 ) ;
T_3 V_422 [ 3 ] = { V_153 , 0x1 , 0 } ;
struct V_411 V_412 = {
. V_413 = V_414 ,
. V_174 = 1 ,
. V_417 = V_422 ,
. V_418 = 3 ,
} ;
T_1 V_423 ;
T_6 V_424 ;
F_7 ( & V_10 -> V_14 ) ;
V_423 = V_10 -> V_423 ;
F_12 ( & V_10 -> V_14 ) ;
V_424 =
V_423 & V_425 ?
F_57 ( 1 ) : 0 ;
V_422 [ V_426 ] = V_423 ;
F_30 ( L_43 , V_423 ) ;
F_85 ( V_10 , V_427 ,
& V_424 , sizeof( V_424 ) ) ;
V_411 ( V_10 , & V_412 ) ;
return;
}
static int F_144 ( struct V_9 * V_10 )
{
struct V_428 V_206 ;
int V_11 = 0 ;
if ( V_10 -> V_22 == V_68 ) {
F_145 ( V_10 ) ;
F_146 ( V_10 ) ;
F_147 ( V_10 ) ;
} else {
return 0 ;
}
memset ( & V_206 , 0 , sizeof( struct V_428 ) ) ;
if ( ! V_10 -> V_56 -> V_57 ) {
if ( V_10 -> V_122 . V_429 & ~ 0xF ) {
F_30 ( L_44 ) ;
V_206 . V_430 = ( F_148 (
V_10 -> V_122 . V_429 & ~ 0xF ) ) ;
} else {
F_30 ( L_45 ) ;
V_206 . V_430 = ( F_148 ( F_149 ( V_10 -> V_377 . V_348 ) ) ) ;
}
V_206 . V_431 = ( F_148 ( F_149 ( V_10 -> V_377 . V_348 ) ) ) ;
} else {
V_206 . V_430 = ( F_148 ( V_10 -> V_122 . V_429 & ~ 0xF ) ) ;
V_206 . V_431 = ( F_148 ( V_10 -> V_122 . V_429 & ~ 0xF ) ) ;
}
F_30 ( L_46 ,
V_10 -> V_22 ,
V_206 . V_430 ,
V_206 . V_431 ) ;
V_11 = F_85 ( V_10 , V_432 ,
& V_206 , sizeof( V_206 ) ) ;
return V_11 ;
}
void F_150 ( struct V_7 * V_8 ,
struct V_62 * V_56 ,
struct V_333 * V_433 ,
T_1 V_94 )
{
struct V_9 * V_10 = V_8 -> V_10 ;
bool V_434 = false ;
F_7 ( & V_10 -> V_14 ) ;
F_30 ( L_47 , V_94 ) ;
if ( V_94 & V_435 ) {
struct V_436 V_437 = { 0 } ;
int V_26 ;
F_30 ( L_48 ,
V_433 -> V_438 ) ;
if ( V_433 -> V_438 > 0 &&
V_433 -> V_438 <= V_439 ) {
for ( V_26 = 0 ; V_26 < V_433 -> V_438 ; V_26 ++ ) {
V_437 . V_440 [ V_26 ] = V_433 -> V_441 [ V_26 ] ;
F_30 ( L_49 ,
V_26 , V_437 . V_440 [ V_26 ] ) ;
}
V_437 . V_178 = F_57 ( 1 ) ;
}
F_30 ( L_50 ,
F_151 ( V_437 . V_178 ) ) ;
F_152 ( V_10 , & V_437 ) ;
}
if ( V_94 &
( V_442 |
V_443 |
V_444 |
V_445 |
V_446 ) ) {
F_30 ( L_51 ) ;
V_10 -> V_165 = V_433 -> V_165 ;
F_153 ( V_10 ) ;
F_154 ( V_10 ) ;
}
if ( V_94 & V_447 ) {
F_30 ( L_52 , V_433 -> V_85 ) ;
if ( V_10 -> V_85 != V_433 -> V_85 ) {
F_155 ( V_10 , V_433 -> V_85 ) ;
V_10 -> V_85 = V_433 -> V_85 ;
}
}
if ( V_94 & V_448 ) {
F_30 ( L_53 ) ;
if ( V_433 -> V_341 )
V_434 = true ;
else if ( V_10 -> V_42 == V_80 )
F_153 ( V_10 ) ;
}
if ( V_94 & V_449 ) {
F_15 ( V_10 ) ;
V_10 -> V_24 = - 1 ;
F_31 ( V_10 ) ;
}
if ( V_94 & V_444 ) {
F_30 ( L_54 ) ;
V_434 = true ;
}
if ( V_94 &
( V_449 |
V_444 |
V_446 |
V_450 |
V_451 ) ) {
F_30 ( L_55 ) ;
if ( V_433 -> V_452 ) {
if ( V_10 -> V_42 < V_77 ) {
F_104 ( V_56 ) ;
F_12 ( & V_10 -> V_14 ) ;
return;
} else if ( V_10 -> V_42 == V_77 ) {
V_10 -> V_42 = V_78 ;
}
} else {
V_434 = true ;
}
if ( V_433 -> V_452 || V_433 -> V_341 ) {
struct V_212 * V_213 = NULL ;
T_6 V_453 = 0 ;
if ( V_433 -> V_357 )
V_10 -> V_166 = V_433 -> V_357 ;
V_10 -> V_165 = V_433 -> V_165 ;
F_112 () ;
if ( V_433 -> V_138 && ! V_433 -> V_341 )
V_213 = F_156 ( V_56 , V_433 -> V_138 ) ;
if ( V_213 ) {
V_10 -> V_454 . V_455 = V_213 -> V_455 ;
V_10 -> V_122 . V_429 =
F_109 ( V_10 ,
V_213 -> V_456 [ V_10 -> V_101 -> V_358 ] ) ;
V_10 -> V_454 . V_457 = F_157 ( & V_8 -> V_96 . V_102 ) ;
V_10 -> V_454 . V_458 = V_433 -> V_459 ;
} else {
memset ( & V_10 -> V_454 , 0 ,
sizeof( V_10 -> V_454 ) ) ;
V_10 -> V_122 . V_429 = - 1 ;
}
F_114 () ;
if ( V_10 -> V_454 . V_458 &
V_460 )
V_453 |= F_158 ( V_461 ) ;
V_453 |= F_158 ( ( V_10 -> V_454 . V_458 & V_462 ) << 2 ) ;
F_85 ( V_10 , V_463 ,
& V_453 , sizeof( V_453 ) ) ;
V_10 -> V_377 . V_464 =
F_159 ( & V_10 -> V_454 ) ;
V_10 -> V_377 . V_114 =
V_465 |
V_466 |
V_467 |
V_468 |
V_469 ;
V_10 -> V_377 . V_470 =
V_433 -> V_471 ?
V_472 :
V_345 ;
V_10 -> V_377 . V_348 = F_57 (
F_109 ( V_10 ,
V_433 -> V_349 ) ) ;
V_10 -> V_377 . V_473 =
F_160 ( & V_10 -> V_454 ) ;
F_20 ( V_10 , 0 , 0 , 0 ) ;
F_21 ( & V_10 -> V_34 ) ;
V_10 -> V_122 . V_474 = V_10 -> V_25 ;
V_10 -> V_122 . V_123 = V_433 -> V_123 ;
if ( V_10 -> V_166 < 1 )
V_10 -> V_166 = 1 ;
F_30 ( L_56 ,
V_10 -> V_166 , V_10 -> V_165 ) ;
F_30 ( L_57 ,
V_10 -> V_377 . V_470 ,
V_10 -> V_377 . V_464 ,
V_10 -> V_122 . V_123 ,
V_10 -> V_122 . V_429 ,
V_10 -> V_377 . V_348 ) ;
F_161 ( V_10 , & V_10 -> V_377 ) ;
if ( ! V_433 -> V_341 ) {
F_121 ( V_10 , 30 ) ;
F_98 ( V_10 , & V_10 -> V_122 ) ;
V_10 -> V_17 = true ;
F_65 ( & V_10 -> V_164 ) ;
F_51 ( V_10 , & V_10 -> V_116 ) ;
}
if ( V_10 -> V_56 -> V_57 ) {
F_30 ( L_58 ) ;
F_162 ( V_10 ,
& V_10 -> V_91 ) ;
}
if ( V_10 -> V_313 )
F_144 ( V_10 ) ;
} else {
memset ( & V_10 -> V_377 , 0 ,
sizeof( V_10 -> V_377 ) ) ;
memset ( & V_10 -> V_122 , 0 , sizeof( V_10 -> V_122 ) ) ;
}
}
if ( V_94 & ( V_449 |
V_475 |
V_476 ) ) {
T_1 V_477 = V_10 -> V_423 ;
if ( V_433 -> V_424 )
V_10 -> V_423 |= V_425 ;
else if ( ! ( V_477 & V_478 ) )
V_10 -> V_423 &= ~ V_425 ;
if ( V_433 -> V_471 )
V_10 -> V_423 |= V_479 ;
else
V_10 -> V_423 &= ~ V_479 ;
F_30 ( L_59 , V_10 -> V_423 ) ;
if ( V_477 != V_10 -> V_423 )
F_35 ( V_10 -> V_36 , & V_10 -> V_421 ) ;
}
if ( V_94 & ( V_449 | V_480 ) ) {
T_6 V_481 = V_433 -> V_482 ?
F_57 ( 9 ) : F_57 ( 20 ) ;
F_30 ( L_60 ,
F_151 ( V_481 ) ) ;
F_85 ( V_10 , V_483 ,
& V_481 , sizeof( V_481 ) ) ;
}
if ( V_94 & ( V_449 | V_484 ) ) {
struct V_314 V_315 = {
. V_320 = 8 ,
} ;
F_30 ( L_61 ,
V_433 -> V_296 , V_433 -> V_485 ) ;
V_10 -> V_296 = V_433 -> V_296 ;
V_10 -> V_485 = V_433 -> V_485 ;
if ( V_433 -> V_296 || V_433 -> V_485 ) {
if ( V_10 -> V_294 ) {
V_315 . V_486 =
V_433 -> V_296 + V_433 -> V_485 ;
V_315 . V_487 =
V_433 -> V_296 ;
V_315 . V_316 |= V_324 ;
} else {
V_315 . V_486 = ( V_433 -> V_296 + V_433 -> V_485 + 110 ) * 2 ;
V_315 . V_487 = ( V_433 -> V_296 + 110 ) * 2 ;
}
V_315 . V_316 |= V_317 ;
} else {
V_315 . V_316 |=
V_317 |
V_318 |
V_319 ;
if ( V_10 -> V_294 )
V_315 . V_316 |= V_324 ;
}
F_101 ( V_10 , & V_315 ) ;
}
F_12 ( & V_10 -> V_14 ) ;
if ( V_434 ) {
F_15 ( V_10 ) ;
F_108 ( V_10 ) ;
}
}
void F_163 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_407 ) ;
long V_488 = V_10 -> V_166 *
( V_10 -> V_165 + 20 ) * V_13 / 1024 ;
F_21 ( & V_10 -> V_408 ) ;
if ( ! V_10 -> V_87 ) {
F_15 ( V_10 ) ;
F_138 ( V_10 , true ) ;
V_10 -> V_87 = true ;
F_164 ( & V_10 -> V_37 , V_399 + V_488 ) ;
F_31 ( V_10 ) ;
}
}
void F_165 ( struct V_161 * V_162 )
{
struct V_9 * V_10 =
F_64 ( V_162 , struct V_9 , V_408 ) ;
if ( V_10 -> V_87 ) {
F_23 ( & V_10 -> V_37 ) ;
F_15 ( V_10 ) ;
V_10 -> V_87 = false ;
F_138 ( V_10 , false ) ;
F_31 ( V_10 ) ;
}
}
void F_166 ( unsigned long V_206 )
{
struct V_9 * V_10 =
(struct V_9 * ) V_206 ;
F_167 ( V_10 -> V_61 -> V_19 ,
L_62 ) ;
F_54 ( & V_10 -> V_392 ) ;
V_10 -> V_86 = V_10 -> V_87 &&
V_10 -> V_88 ;
if ( V_10 -> V_86 )
F_135 ( V_10 ) ;
F_55 ( & V_10 -> V_392 ) ;
}
int F_168 ( struct V_7 * V_61 ,
struct V_62 * V_56 ,
enum V_489 V_490 ,
struct V_212 * V_213 , T_4 V_491 , T_4 * V_492 ,
T_3 V_493 , bool V_494 )
{
return - V_495 ;
}
void F_169 ( struct V_9 * V_10 ,
struct V_496 * V_206 )
{
F_30 ( L_63 ,
V_206 -> V_497 ? L_64 : L_65 ,
V_206 -> V_182 ? L_66 : L_67 ) ;
if ( V_206 -> V_182 ) {
bool V_498 = false ;
F_54 ( & V_10 -> V_392 ) ;
if ( V_206 -> V_497 ) {
V_10 -> V_86 = false ;
} else {
F_6 ( & V_10 -> V_12 ,
V_10 -> V_166 *
( V_10 -> V_165 + 20 ) * V_13 / 1024 ) ;
V_10 -> V_86 = ( V_10 -> V_87 &&
V_10 -> V_88 ) ;
if ( V_10 -> V_86 ) {
V_498 = true ;
F_135 ( V_10 ) ;
}
}
F_55 ( & V_10 -> V_392 ) ;
if ( V_498 )
F_23 ( & V_10 -> V_37 ) ;
} else {
F_54 ( & V_10 -> V_392 ) ;
F_137 ( V_10 , V_206 -> V_82 , V_206 -> V_497 ) ;
F_55 ( & V_10 -> V_392 ) ;
if ( ! V_206 -> V_497 )
F_135 ( V_10 ) ;
}
return;
}
static int F_154 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_499 * V_500 ;
struct V_501 V_502 = {
. V_503 = V_504 ,
} ;
T_4 V_415 ;
T_4 V_505 ;
if ( V_10 -> V_22 == V_68 ||
V_10 -> V_22 == V_23 ||
V_10 -> V_22 == V_38 )
goto V_376;
if ( V_10 -> V_56 -> V_57 )
V_502 . V_506 = V_507 ;
V_502 . V_60 = F_139 ( V_10 -> V_61 , V_10 -> V_56 ,
& V_415 , & V_505 ) ;
if ( ! V_502 . V_60 )
return - V_508 ;
V_11 = F_170 ( V_10 , & V_502 ) ;
if ( V_11 )
goto V_376;
V_500 = ( void * ) V_502 . V_60 -> V_292 ;
V_500 -> V_509 =
F_171 ( V_510 |
V_511 ) ;
V_502 . V_503 = V_512 ;
if ( V_10 -> V_56 -> V_57 ) {
V_11 = F_124 ( V_10 , true ) ;
} else {
V_11 = F_170 ( V_10 , & V_502 ) ;
F_124 ( V_10 , false ) ;
}
V_376:
F_140 ( V_502 . V_60 ) ;
return V_11 ;
}
static int F_145 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_501 V_502 = {
. V_503 = V_513 ,
. V_506 = 0xFF ,
} ;
V_502 . V_60 = F_172 ( V_10 -> V_61 , V_10 -> V_56 ) ;
if ( ! V_502 . V_60 )
return - V_508 ;
V_11 = F_170 ( V_10 , & V_502 ) ;
F_140 ( V_502 . V_60 ) ;
return V_11 ;
}
static int F_146 ( struct V_9 * V_10 )
{
int V_11 = 0 ;
struct V_501 V_502 = {
. V_503 = V_514 ,
. V_506 = 0xFF ,
} ;
V_502 . V_60 = F_36 ( V_10 -> V_61 , V_10 -> V_56 ) ;
if ( ! V_502 . V_60 )
return - V_508 ;
V_11 = F_170 ( V_10 , & V_502 ) ;
F_140 ( V_502 . V_60 ) ;
return V_11 ;
}
static int F_147 ( struct V_9 * V_10 )
{
return 0 ;
}
static int F_155 ( struct V_9 * V_10 ,
bool V_178 )
{
struct V_515 V_516 = {
. V_517 = V_178 ,
} ;
return V_515 ( V_10 , & V_516 ) ;
}
static int F_173 ( struct V_9 * V_10 )
{
int V_11 ;
struct V_333 * V_96 = & V_10 -> V_56 -> V_334 ;
struct V_378 V_379 = {
. V_22 = V_10 -> V_56 -> V_57 ?
V_518 : V_519 ,
. V_358 = ( V_10 -> V_101 -> V_358 == V_359 ) ?
V_360 : V_361 ,
. V_107 = V_10 -> V_101 -> V_108 ,
. V_354 = V_96 -> V_165 ,
. V_357 = V_96 -> V_357 ,
. V_470 = V_96 -> V_471 ?
V_472 :
V_345 ,
. V_381 = 100 ,
. V_348 = F_109 ( V_10 ,
V_96 -> V_349 ) ,
} ;
struct V_126 V_22 = {
. V_127 = V_128 ,
. V_129 = true ,
} ;
memset ( V_379 . V_365 , 0 , sizeof( V_379 . V_365 ) ) ;
if ( ! V_96 -> V_520 ) {
V_379 . V_364 = V_96 -> V_364 ;
memcpy ( V_379 . V_365 , V_96 -> V_365 , V_379 . V_364 ) ;
}
V_10 -> V_165 = V_96 -> V_165 ;
V_10 -> V_166 = V_96 -> V_357 ;
memset ( & V_10 -> V_83 , 0 , sizeof( V_10 -> V_83 ) ) ;
F_30 ( L_68 ,
V_379 . V_107 , V_379 . V_358 ,
V_379 . V_354 , V_379 . V_357 ,
V_379 . V_348 ,
V_379 . V_364 , V_379 . V_365 ) ;
V_11 = V_378 ( V_10 , & V_379 ) ;
if ( ! V_11 )
V_11 = F_117 ( V_10 ) ;
if ( ! V_11 && V_10 -> V_56 -> V_57 ) {
F_30 ( L_69 ) ;
F_162 ( V_10 , & V_10 -> V_91 ) ;
}
if ( ! V_11 ) {
F_115 ( V_10 , 0 , 0 ) ;
V_10 -> V_42 = V_80 ;
F_56 ( V_10 ) ;
}
F_53 ( V_10 , & V_22 ) ;
return V_11 ;
}
static int F_153 ( struct V_9 * V_10 )
{
struct V_333 * V_96 = & V_10 -> V_56 -> V_334 ;
struct V_73 V_74 = {
. V_82 = 0 ,
. V_75 = true ,
} ;
if ( V_10 -> V_22 == V_71 ) {
if ( V_10 -> V_42 != V_80 ||
V_10 -> V_165 != V_96 -> V_165 ) {
F_30 ( L_70 ) ;
F_15 ( V_10 ) ;
if ( V_10 -> V_42 != V_43 )
V_73 ( V_10 , & V_74 ) ;
V_10 -> V_42 = V_43 ;
F_173 ( V_10 ) ;
F_31 ( V_10 ) ;
} else
F_30 ( L_71 ,
V_10 -> V_42 ) ;
}
return 0 ;
}
