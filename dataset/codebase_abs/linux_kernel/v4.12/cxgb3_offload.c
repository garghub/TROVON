static inline int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_3 ( V_4 , & V_3 -> V_5 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
F_5 ( & V_8 ) ;
F_6 ( & V_7 -> V_9 , & V_9 ) ;
if ( V_7 -> V_10 ) {
F_7 (tdev, &ofld_dev_list, ofld_dev_list) {
if ( F_1 ( V_2 ) )
V_7 -> V_10 ( V_2 ) ;
}
}
F_8 ( & V_8 ) ;
}
void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 ;
F_5 ( & V_8 ) ;
F_10 ( & V_7 -> V_9 ) ;
if ( V_7 -> remove ) {
F_7 (tdev, &ofld_dev_list, ofld_dev_list) {
if ( F_1 ( V_2 ) )
V_7 -> remove ( V_2 ) ;
}
}
F_8 ( & V_8 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_5 ( & V_8 ) ;
F_7 (client, &client_list, client_list) {
if ( V_7 -> V_10 )
V_7 -> V_10 ( V_2 ) ;
}
F_8 ( & V_8 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_5 ( & V_8 ) ;
F_7 (client, &client_list, client_list) {
if ( V_7 -> remove )
V_7 -> remove ( V_2 ) ;
}
F_8 ( & V_8 ) ;
}
void F_13 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 )
{
struct V_6 * V_7 ;
F_5 ( & V_8 ) ;
F_7 (client, &client_list, client_list) {
if ( V_7 -> V_13 )
V_7 -> V_13 ( V_2 , V_11 , V_12 ) ;
}
F_8 ( & V_8 ) ;
}
static struct V_14 * F_14 ( struct V_3 * V_3 ,
const unsigned char * V_15 ,
unsigned int V_16 )
{
int V_17 ;
F_15 (adapter, i) {
struct V_14 * V_18 = V_3 -> V_12 [ V_17 ] ;
if ( F_16 ( V_18 -> V_19 , V_15 ) ) {
F_17 () ;
if ( V_16 && V_16 != V_20 ) {
V_18 = F_18 ( V_18 , F_19 ( V_21 ) , V_16 ) ;
} else if ( F_20 ( V_18 ) ) {
struct V_14 * V_22 ;
while ( ( V_22 =
F_21 ( V_18 ) ) )
V_18 = V_22 ;
}
F_22 () ;
return V_18 ;
}
}
return NULL ;
}
static int F_23 ( struct V_3 * V_3 , unsigned int V_23 ,
void * V_24 )
{
int V_17 ;
int V_25 = 0 ;
unsigned int V_26 = 0 ;
struct V_27 * V_28 = V_24 ;
switch ( V_23 ) {
case V_29 :
V_28 -> V_30 = V_3 -> V_30 ;
V_28 -> V_31 = F_24 ( V_3 , V_32 ) ;
V_28 -> V_33 = F_24 ( V_3 , V_34 ) ;
V_28 -> V_35 = F_24 ( V_3 , V_36 ) ;
V_26 = F_24 ( V_3 , V_37 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ , V_26 >>= 8 )
V_28 -> V_38 [ V_17 ] = V_26 & 0xFF ;
V_26 = F_24 ( V_3 , V_39 ) ;
V_28 -> V_40 =
V_28 -> V_41 = F_25 ( ( V_26 >> V_42 ) & V_43 ,
( V_26 >> V_44 ) & V_45 ) ;
V_26 = F_25 ( V_3 -> V_46 . V_47 . V_48 ,
F_24 ( V_3 , V_49 ) >> 17 ) ;
V_28 -> V_40 = F_25 ( V_26 , V_28 -> V_40 ) ;
V_26 = F_24 ( V_3 , V_50 ) ;
if ( ( V_26 >> V_51 ) != 0x3f60 ) {
V_26 &= ( V_52 << V_53 ) ;
V_26 |= F_26 ( 0x3f60 ) ;
F_27 ( L_1 ,
V_3 -> V_54 , V_26 ) ;
F_28 ( V_3 , V_50 , V_26 ) ;
}
V_26 = F_25 ( V_3 -> V_46 . V_47 . V_55 ,
( ( F_24 ( V_3 , V_50 ) ) >>
V_51 ) & V_56 ) ;
V_28 -> V_41 = F_25 ( V_26 , V_28 -> V_41 ) ;
break;
case V_57 :
F_28 ( V_3 , V_36 , V_28 -> V_35 ) ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ )
V_26 |= ( V_28 -> V_38 [ V_17 ] & 0xF ) << ( 8 * V_17 ) ;
if ( V_26 && ( V_26 != F_24 ( V_3 , V_37 ) ) ) {
F_27 ( L_2 ,
V_3 -> V_54 , V_26 , V_28 -> V_38 [ 0 ] ,
V_28 -> V_38 [ 1 ] , V_28 -> V_38 [ 2 ] ,
V_28 -> V_38 [ 3 ] ) ;
F_28 ( V_3 , V_37 , V_26 ) ;
}
break;
default:
V_25 = - V_58 ;
}
return V_25 ;
}
static int F_29 ( struct V_3 * V_3 , unsigned int V_23 , void * V_24 )
{
int V_25 = 0 ;
switch ( V_23 ) {
case V_59 : {
struct V_60 * V_61 = V_24 ;
struct V_62 * V_30 = V_3 -> V_30 ;
V_61 -> V_63 = F_30 ( V_30 , 2 ) ;
V_61 -> V_64 = F_31 ( V_30 , 2 ) ;
V_61 -> V_65 =
F_24 ( V_3 , V_66 ) ;
V_61 -> V_67 = F_24 ( V_3 , V_68 ) ;
V_61 -> V_69 =
F_24 ( V_3 , V_70 ) ;
V_61 -> V_71 = F_24 ( V_3 , V_72 ) ;
V_61 -> V_73 = F_24 ( V_3 , V_74 ) ;
V_61 -> V_75 = F_24 ( V_3 , V_76 ) ;
V_61 -> V_77 = V_3 -> V_78 + V_79 ;
V_61 -> V_30 = V_30 ;
break;
}
case V_80 : {
unsigned long V_81 ;
struct V_82 * V_61 = V_24 ;
F_32 ( & V_3 -> V_83 . V_84 , V_81 ) ;
V_25 = F_33 ( V_3 , V_61 -> V_85 , V_61 -> V_86 ,
V_61 -> V_87 ) ;
F_34 ( & V_3 -> V_83 . V_84 , V_81 ) ;
break;
}
case V_88 : {
struct V_89 * V_90 = V_24 ;
struct V_91 * V_92 ;
if ( ( V_90 -> V_93 & 7 ) || ( V_90 -> V_94 & 7 ) )
return - V_95 ;
if ( V_90 -> V_96 == V_97 )
V_92 = & V_3 -> V_98 ;
else if ( V_90 -> V_96 == V_99 )
V_92 = & V_3 -> V_100 ;
else if ( V_90 -> V_96 == V_101 )
V_92 = & V_3 -> V_102 ;
else
return - V_95 ;
V_25 =
F_35 ( V_92 , V_90 -> V_93 / 8 , V_90 -> V_94 / 8 ,
( V_103 * ) V_90 -> V_104 ) ;
if ( V_25 )
return V_25 ;
break;
}
case V_105 : {
struct V_106 * V_61 = V_24 ;
F_36 ( & V_3 -> V_83 . V_84 ) ;
V_25 =
F_37 ( V_3 , V_61 -> V_85 ,
V_61 -> V_107 , V_61 -> V_108 ,
V_109 ,
V_61 -> V_110 , V_61 -> V_87 ,
V_61 -> V_111 ) ;
F_38 ( & V_3 -> V_83 . V_84 ) ;
break;
}
case V_112 :
F_36 ( & V_3 -> V_83 . V_84 ) ;
V_25 = F_39 ( V_3 , * ( unsigned int * ) V_24 ) ;
F_38 ( & V_3 -> V_83 . V_84 ) ;
break;
case V_113 : {
struct V_114 * V_61 = V_24 ;
F_36 ( & V_3 -> V_83 . V_84 ) ;
V_25 = F_40 ( V_3 , V_115 , 0 ,
V_116 ,
V_109 ,
V_61 -> V_107 , V_61 -> V_108 ,
V_117 , 1 , 0 ) ;
F_38 ( & V_3 -> V_83 . V_84 ) ;
break;
}
case V_118 : {
F_41 ( & V_3 -> V_119 ) ;
F_42 ( V_3 , (struct V_120 * ) V_24 ) ;
F_43 ( & V_3 -> V_119 ) ;
break;
}
default:
V_25 = - V_58 ;
}
return V_25 ;
}
static int F_44 ( struct V_1 * V_2 , unsigned int V_23 , void * V_24 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_47 = & V_3 -> V_46 . V_47 ;
int V_17 ;
switch ( V_23 ) {
case V_134 :
* ( unsigned int * ) V_24 = V_135 ;
break;
case V_136 :
* ( unsigned int * ) V_24 = V_137 ;
break;
case V_138 :
* ( unsigned int * ) V_24 = 1 << 20 ;
break;
case V_139 :
V_122 = V_24 ;
V_122 -> V_140 = F_45 ( & V_3 -> V_141 ) -
V_3 -> V_46 . V_141 . V_142 -
V_3 -> V_46 . V_141 . V_143 - V_3 -> V_46 . V_141 . V_144 ;
V_122 -> V_145 = 0 ;
break;
case V_146 :
V_122 = V_24 ;
V_122 -> V_140 = V_3 -> V_46 . V_141 . V_144 ;
V_122 -> V_145 = F_45 ( & V_3 -> V_141 ) - V_122 -> V_140 -
V_3 -> V_46 . V_141 . V_143 - V_3 -> V_46 . V_141 . V_142 ;
break;
case V_147 :
* ( unsigned int * ) V_24 = 2048 ;
break;
case V_148 :
V_124 = V_24 ;
V_124 -> V_108 = V_149 ;
V_124 -> V_150 = V_3 -> V_46 . V_150 ;
break;
case V_151 :
V_126 = V_24 ;
V_126 -> V_18 = F_14 ( V_3 , V_126 -> V_152 ,
V_126 -> V_153 &
V_20 ) ;
break;
case V_154 :
V_128 = V_24 ;
V_128 -> V_31 = F_24 ( V_3 , V_155 ) ;
V_128 -> V_33 = F_24 ( V_3 , V_156 ) ;
V_128 -> V_157 = F_24 ( V_3 , V_158 ) ;
break;
case V_159 :
V_130 = V_24 ;
V_130 -> V_160 = V_3 -> V_46 . V_160 ;
F_15 (adapter, i)
V_130 -> V_161 [ V_17 ] = V_3 -> V_12 [ V_17 ] ;
break;
case V_29 :
case V_57 :
if ( ! F_46 ( V_3 ) )
return - V_162 ;
return F_23 ( V_3 , V_23 , V_24 ) ;
case V_59 :
case V_80 :
case V_105 :
case V_112 :
case V_113 :
case V_88 :
case V_118 :
if ( ! F_46 ( V_3 ) )
return - V_162 ;
return F_29 ( V_3 , V_23 , V_24 ) ;
case V_163 :
V_132 = V_24 ;
V_132 -> V_164 = V_47 -> V_55 ;
V_132 -> V_140 = V_47 -> V_165 ;
break;
case V_166 : {
struct V_167 * V_168 = V_24 ;
struct V_169 * V_170 = F_47 ( V_168 -> V_18 ) ;
V_168 -> V_171 = V_170 -> V_167 ;
break;
}
case V_172 : {
struct V_173 * V_174 = V_24 ;
F_41 ( & V_3 -> V_119 ) ;
F_48 ( V_3 , & V_174 -> V_175 ) ;
F_49 ( V_3 , & V_174 -> V_176 ) ;
F_43 ( & V_3 -> V_119 ) ;
break;
}
default:
return - V_58 ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_18 , struct V_177 * * V_178 ,
int V_179 )
{
while ( V_179 -- )
F_51 ( V_178 [ V_179 ] ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_18 , struct V_180 * V_181 )
{
}
void F_53 ( struct V_1 * V_18 )
{
V_18 -> V_182 = F_50 ;
V_18 -> V_183 = F_52 ;
}
void * F_54 ( struct V_1 * V_2 , int V_184 )
{
struct V_185 * V_90 = & ( F_55 ( V_2 ) ) -> V_186 ;
union V_187 * V_168 = F_56 ( V_90 , V_184 ) ;
void * V_188 = V_168 -> V_189 . V_188 ;
F_57 ( & V_90 -> V_190 ) ;
V_168 -> V_191 = V_90 -> V_192 ;
V_90 -> V_192 = V_168 ;
V_90 -> V_193 -- ;
F_58 ( & V_90 -> V_190 ) ;
return V_188 ;
}
void F_59 ( struct V_1 * V_2 , int V_194 )
{
struct V_185 * V_90 = & ( F_55 ( V_2 ) ) -> V_186 ;
union V_195 * V_168 = F_60 ( V_90 , V_194 ) ;
F_57 ( & V_90 -> V_196 ) ;
V_168 -> V_191 = V_90 -> V_197 ;
V_90 -> V_197 = V_168 ;
V_90 -> V_198 -- ;
F_58 ( & V_90 -> V_196 ) ;
}
void F_61 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_188 , unsigned int V_122 )
{
struct V_185 * V_90 = & ( F_55 ( V_2 ) ) -> V_186 ;
V_90 -> V_199 [ V_122 ] . V_7 = V_7 ;
V_90 -> V_199 [ V_122 ] . V_188 = V_188 ;
F_62 ( & V_90 -> V_200 ) ;
}
static inline void F_63 ( struct V_177 * V_201 , unsigned int V_122 )
{
struct V_202 * V_23 ;
V_201 -> V_203 = V_204 ;
V_23 = (struct V_202 * ) F_64 ( V_201 , sizeof( * V_23 ) ) ;
V_23 -> V_205 . V_206 = F_65 ( F_66 ( V_207 ) ) ;
F_67 ( V_23 ) = F_65 ( F_68 ( V_208 , V_122 ) ) ;
}
static void F_69 ( struct V_209 * V_210 )
{
struct V_211 * V_212 = F_70 ( V_210 , struct V_211 ,
V_213 ) ;
struct V_177 * V_201 ;
struct V_1 * V_2 = V_212 -> V_18 ;
F_57 ( & V_212 -> V_214 ) ;
while ( V_212 -> V_215 ) {
struct V_216 * V_168 = V_212 -> V_215 ;
V_212 -> V_215 = V_168 -> V_188 ;
F_58 ( & V_212 -> V_214 ) ;
V_201 = F_71 ( sizeof( struct V_202 ) ,
V_217 ) ;
if ( ! V_201 )
V_201 = V_212 -> V_218 ;
if ( ! V_201 ) {
F_57 ( & V_212 -> V_214 ) ;
V_168 -> V_188 = ( void * ) V_212 -> V_215 ;
V_212 -> V_215 = V_168 ;
break;
}
F_63 ( V_201 , V_168 - V_212 -> V_186 . V_199 ) ;
F_72 ( V_2 , V_201 ) ;
V_168 -> V_188 = NULL ;
if ( V_201 == V_212 -> V_218 )
V_212 -> V_218 =
F_71 ( sizeof( struct V_202 ) ,
V_217 ) ;
F_57 ( & V_212 -> V_214 ) ;
}
V_212 -> V_219 = ( V_212 -> V_215 == NULL ) ? 0 : 1 ;
F_58 ( & V_212 -> V_214 ) ;
if ( ! V_212 -> V_218 )
V_212 -> V_218 =
F_71 ( sizeof( struct V_202 ) ,
V_217 ) ;
}
void F_73 ( struct V_1 * V_2 , unsigned int V_122 )
{
struct V_211 * V_212 = F_55 ( V_2 ) ;
struct V_216 * V_168 = & V_212 -> V_186 . V_199 [ V_122 ] ;
F_57 ( & V_212 -> V_214 ) ;
V_168 -> V_188 = ( void * ) V_212 -> V_215 ;
V_168 -> V_7 = NULL ;
V_212 -> V_215 = V_168 ;
if ( ! V_168 -> V_188 || V_212 -> V_219 )
F_74 ( & V_212 -> V_213 ) ;
F_58 ( & V_212 -> V_214 ) ;
}
void F_75 ( struct V_1 * V_2 , void * V_188 , unsigned int V_122 )
{
struct V_185 * V_90 = & ( F_55 ( V_2 ) ) -> V_186 ;
F_76 ( V_122 >= V_90 -> V_220 ) ;
if ( V_2 -> type == V_221 )
( void ) F_77 ( & V_90 -> V_199 [ V_122 ] . V_188 , V_188 , NULL ) ;
else {
struct V_177 * V_201 ;
V_201 = F_71 ( sizeof( struct V_202 ) , V_222 ) ;
if ( F_78 ( V_201 ) ) {
F_63 ( V_201 , V_122 ) ;
F_72 ( V_2 , V_201 ) ;
V_90 -> V_199 [ V_122 ] . V_188 = NULL ;
} else
F_73 ( V_2 , V_122 ) ;
}
F_79 ( & V_90 -> V_200 ) ;
}
int F_80 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_188 )
{
int V_184 = - 1 ;
struct V_185 * V_90 = & ( F_55 ( V_2 ) ) -> V_186 ;
F_57 ( & V_90 -> V_190 ) ;
if ( V_90 -> V_192 &&
V_90 -> V_193 + F_81 ( & V_90 -> V_200 ) + V_223 <=
V_90 -> V_220 ) {
union V_187 * V_168 = V_90 -> V_192 ;
V_184 = ( V_168 - V_90 -> V_224 ) + V_90 -> V_225 ;
V_90 -> V_192 = V_168 -> V_191 ;
V_168 -> V_189 . V_188 = V_188 ;
V_168 -> V_189 . V_7 = V_7 ;
V_90 -> V_193 ++ ;
}
F_58 ( & V_90 -> V_190 ) ;
return V_184 ;
}
int F_82 ( struct V_1 * V_2 , struct V_6 * V_7 ,
void * V_188 )
{
int V_194 = - 1 ;
struct V_185 * V_90 = & ( F_55 ( V_2 ) ) -> V_186 ;
F_57 ( & V_90 -> V_196 ) ;
if ( V_90 -> V_197 ) {
union V_195 * V_168 = V_90 -> V_197 ;
V_194 = ( V_168 - V_90 -> V_226 ) + V_90 -> V_227 ;
V_90 -> V_197 = V_168 -> V_191 ;
V_168 -> V_189 . V_188 = V_188 ;
V_168 -> V_189 . V_7 = V_7 ;
V_90 -> V_198 ++ ;
}
F_58 ( & V_90 -> V_196 ) ;
return V_194 ;
}
struct V_1 * F_83 ( struct V_14 * V_18 )
{
const struct V_169 * V_170 = F_47 ( V_18 ) ;
return (struct V_1 * ) V_170 -> V_3 ;
}
static int F_84 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
struct V_228 * V_229 = F_85 ( V_201 ) ;
if ( V_229 -> V_230 != V_231 )
F_86 ( L_3 ,
V_229 -> V_230 , F_87 ( V_229 ) ) ;
return V_232 ;
}
static int F_88 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
struct V_233 * V_229 = F_85 ( V_201 ) ;
if ( V_229 -> V_230 != V_231 )
F_86 ( L_4 ,
V_229 -> V_230 , F_87 ( V_229 ) ) ;
return V_232 ;
}
static int F_89 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
struct V_234 * V_229 = F_85 ( V_201 ) ;
if ( V_229 -> V_230 != V_231 )
F_86 ( L_5 ,
V_229 -> V_230 , F_87 ( V_229 ) ) ;
return V_232 ;
}
static int F_90 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
struct V_235 * V_229 = F_85 ( V_201 ) ;
unsigned int V_184 = F_91 ( F_92 ( V_229 -> V_184 ) ) ;
struct V_216 * V_189 ;
V_189 = F_93 ( & ( F_55 ( V_18 ) ) -> V_186 , V_184 ) ;
if ( V_189 && V_189 -> V_188 && V_189 -> V_7 &&
V_189 -> V_7 -> V_236 &&
V_189 -> V_7 -> V_236 [ V_237 ] ) {
return V_189 -> V_7 -> V_236 [ V_237 ] ( V_18 , V_201 ,
V_189 ->
V_188 ) ;
} else {
F_86 ( L_6 ,
V_18 -> V_54 , V_237 ) ;
return V_232 | V_238 ;
}
}
static int F_94 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
union V_239 * V_168 = F_85 ( V_201 ) ;
unsigned int V_194 = F_91 ( F_92 ( V_168 -> V_239 ) ) ;
struct V_216 * V_189 ;
V_189 = F_95 ( & ( F_55 ( V_18 ) ) -> V_186 , V_194 ) ;
if ( V_189 && V_189 -> V_188 && V_189 -> V_7 -> V_236 &&
V_189 -> V_7 -> V_236 [ V_168 -> V_240 ] ) {
return V_189 -> V_7 -> V_236 [ V_168 -> V_240 ] ( V_18 , V_201 ,
V_189 -> V_188 ) ;
} else {
F_86 ( L_6 ,
V_18 -> V_54 , V_168 -> V_240 ) ;
return V_232 | V_238 ;
}
}
static int F_96 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
union V_239 * V_168 = F_85 ( V_201 ) ;
unsigned int V_241 = F_91 ( F_92 ( V_168 -> V_239 ) ) ;
struct V_216 * V_189 ;
V_189 = F_97 ( & ( F_55 ( V_18 ) ) -> V_186 , V_241 ) ;
if ( V_189 && V_189 -> V_188 && V_189 -> V_7 -> V_236 &&
V_189 -> V_7 -> V_236 [ V_168 -> V_240 ] ) {
return V_189 -> V_7 -> V_236 [ V_168 -> V_240 ]
( V_18 , V_201 , V_189 -> V_188 ) ;
} else {
F_86 ( L_6 ,
V_18 -> V_54 , V_168 -> V_240 ) ;
return V_232 | V_238 ;
}
}
static int F_98 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
struct V_242 * V_23 = F_85 ( V_201 ) ;
unsigned int V_194 = F_99 ( F_92 ( V_23 -> V_243 ) ) ;
struct V_185 * V_90 = & ( F_55 ( V_18 ) ) -> V_186 ;
struct V_216 * V_189 ;
unsigned int V_122 = F_87 ( V_23 ) ;
if ( F_100 ( V_122 >= V_90 -> V_220 ) ) {
F_101 ( L_7 ,
V_18 -> V_54 , V_122 ) ;
F_102 ( F_2 ( V_18 ) ) ;
return V_232 ;
}
V_189 = F_95 ( V_90 , V_194 ) ;
if ( V_189 && V_189 -> V_188 && V_189 -> V_7 -> V_236 &&
V_189 -> V_7 -> V_236 [ V_244 ] ) {
return V_189 -> V_7 -> V_236 [ V_244 ]
( V_18 , V_201 , V_189 -> V_188 ) ;
} else {
F_86 ( L_6 ,
V_18 -> V_54 , V_244 ) ;
return V_232 | V_238 ;
}
}
static struct V_177 * F_103 ( struct V_177 * V_201 , T_2 V_94 ,
T_3 V_245 )
{
if ( F_78 ( ! F_104 ( V_201 ) ) ) {
F_76 ( V_201 -> V_94 < V_94 ) ;
F_105 ( V_201 , V_94 ) ;
F_106 ( V_201 ) ;
} else {
V_201 = F_71 ( V_94 , V_245 ) ;
if ( V_201 )
F_64 ( V_201 , V_94 ) ;
}
return V_201 ;
}
static int F_107 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
union V_239 * V_168 = F_85 ( V_201 ) ;
unsigned int V_241 = F_91 ( F_92 ( V_168 -> V_239 ) ) ;
struct V_216 * V_189 ;
V_189 = F_97 ( & ( F_55 ( V_18 ) ) -> V_186 , V_241 ) ;
if ( V_189 && V_189 -> V_188 && V_189 -> V_7 -> V_236 &&
V_189 -> V_7 -> V_236 [ V_168 -> V_240 ] ) {
return V_189 -> V_7 -> V_236 [ V_168 -> V_240 ]
( V_18 , V_201 , V_189 -> V_188 ) ;
} else {
struct V_246 * V_23 = F_85 ( V_201 ) ;
struct V_247 * V_229 ;
struct V_177 * V_248 ;
unsigned int V_122 = F_87 ( V_23 ) ;
T_4 V_249 = V_23 -> V_230 ;
if ( V_23 -> V_230 == V_250 ||
V_23 -> V_230 == V_251 )
goto V_252;
V_248 = F_103 ( V_201 ,
sizeof( struct
V_247 ) ,
V_222 ) ;
if ( ! V_248 ) {
F_101 ( L_8 ) ;
goto V_252;
}
V_248 -> V_203 = V_253 ;
F_64 ( V_248 , sizeof( struct V_247 ) ) ;
V_229 = F_85 ( V_248 ) ;
V_229 -> V_205 . V_206 =
F_65 ( F_66 ( V_254 ) ) ;
V_229 -> V_205 . V_255 = F_65 ( F_108 ( V_122 ) ) ;
F_67 ( V_229 ) = F_65 ( F_68 ( V_256 , V_122 ) ) ;
V_229 -> V_249 = V_249 ;
F_72 ( V_18 , V_248 ) ;
V_252:
return V_232 ;
}
}
static int F_109 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
struct V_257 * V_23 = F_85 ( V_201 ) ;
unsigned int V_184 = F_99 ( F_92 ( V_23 -> V_243 ) ) ;
struct V_185 * V_90 = & ( F_55 ( V_18 ) ) -> V_186 ;
struct V_216 * V_189 ;
unsigned int V_122 = F_87 ( V_23 ) ;
if ( F_100 ( V_122 >= V_90 -> V_220 ) ) {
F_101 ( L_9 ,
V_18 -> V_54 , V_122 ) ;
F_102 ( F_2 ( V_18 ) ) ;
return V_232 ;
}
V_189 = F_93 ( V_90 , V_184 ) ;
if ( V_189 && V_189 -> V_188 && V_189 -> V_7 -> V_236 &&
V_189 -> V_7 -> V_236 [ V_258 ] ) {
return V_189 -> V_7 -> V_236 [ V_258 ]
( V_18 , V_201 , V_189 -> V_188 ) ;
} else {
F_86 ( L_6 ,
V_18 -> V_54 , V_258 ) ;
return V_232 | V_238 ;
}
}
static int F_110 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
struct V_259 * V_168 = F_85 ( V_201 ) ;
V_201 -> V_260 = F_19 ( 0xffff ) ;
V_201 -> V_18 = V_18 -> V_261 ;
F_111 ( V_201 , sizeof( * V_168 ) ) ;
F_112 ( V_201 ) ;
F_113 ( V_201 ) ;
return 0 ;
}
static inline T_1 F_114 ( struct V_177 * V_201 )
{
return F_92 ( ( V_262 V_263 ) V_201 -> V_203 ) >> 8 & 0xfffff ;
}
static inline T_1 F_115 ( struct V_177 * V_201 )
{
return F_116 ( F_92 ( ( V_262 V_263 ) V_201 -> V_264 ) ) ;
}
static int F_117 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
unsigned int V_241 = F_114 ( V_201 ) ;
unsigned int V_240 = F_115 ( V_201 ) ;
struct V_216 * V_189 ;
V_189 = F_97 ( & ( F_55 ( V_18 ) ) -> V_186 , V_241 ) ;
if ( V_189 && V_189 -> V_188 && V_189 -> V_7 -> V_236 &&
V_189 -> V_7 -> V_236 [ V_240 ] ) {
return V_189 -> V_7 -> V_236 [ V_240 ] ( V_18 , V_201 ,
V_189 -> V_188 ) ;
} else {
F_86 ( L_6 ,
V_18 -> V_54 , V_240 ) ;
return V_232 | V_238 ;
}
}
static int F_118 ( struct V_265 * V_266 , unsigned long V_11 ,
void * V_188 )
{
switch ( V_11 ) {
case ( V_267 ) : {
F_119 ( (struct V_180 * ) V_188 ) ;
break;
}
case ( V_268 ) : {
struct V_269 * V_270 = V_188 ;
F_120 ( V_270 -> V_271 , V_270 -> V_272 , V_270 -> V_181 ,
V_270 -> V_273 ) ;
F_119 ( V_270 -> V_181 ) ;
break;
}
default:
break;
}
return 0 ;
}
static int F_121 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
F_86 ( L_10 , V_18 -> V_54 , * V_201 -> V_24 ) ;
return V_232 | V_238 ;
}
void F_122 ( unsigned int V_240 , T_5 V_274 )
{
if ( V_240 < V_275 )
V_276 [ V_240 ] = V_274 ? V_274 : F_121 ;
else
F_86 ( L_11 ,
V_240 ) ;
}
static int F_123 ( struct V_1 * V_18 , struct V_177 * * V_178 , int V_179 )
{
while ( V_179 -- ) {
struct V_177 * V_201 = * V_178 ++ ;
unsigned int V_240 = F_115 ( V_201 ) ;
int V_25 = V_276 [ V_240 ] ( V_18, V_201 ) ;
#if V_277
if ( V_25 & V_278 ) {
union V_239 * V_168 = F_85 ( V_201 ) ;
F_86 ( L_12 ,
V_18 -> V_54 , V_240 , F_91 ( F_92 ( V_168 -> V_239 ) ) ) ;
}
#endif
if ( V_25 & V_232 )
F_124 ( V_201 ) ;
}
return 0 ;
}
int F_72 ( struct V_1 * V_18 , struct V_177 * V_201 )
{
int V_279 ;
F_125 () ;
V_279 = V_18 -> V_280 ( V_18 , V_201 ) ;
F_126 () ;
return V_279 ;
}
static int F_127 ( struct V_14 * V_18 )
{
struct V_3 * V_3 ;
int V_17 ;
F_128 ( & V_281 ) ;
F_7 (adapter, &adapter_list, adapter_list) {
F_15 (adapter, i) {
if ( V_18 == V_3 -> V_12 [ V_17 ] ) {
F_129 ( & V_281 ) ;
return 1 ;
}
}
}
F_129 ( & V_281 ) ;
return 0 ;
}
static void F_119 ( struct V_180 * V_181 )
{
struct V_14 * V_18 ;
if ( ! V_181 )
return;
V_18 = V_181 -> V_18 ;
if ( V_18 && ( F_127 ( V_18 ) ) ) {
struct V_1 * V_2 = F_83 ( V_18 ) ;
F_76 ( ! V_2 ) ;
F_130 ( V_2 , V_181 ) ;
}
}
static void F_131 ( struct V_1 * V_2 , T_1 V_122 , struct V_282 * V_174 )
{
struct V_177 * V_201 ;
struct V_283 * V_23 ;
V_201 = F_71 ( sizeof( * V_23 ) , V_222 ) ;
if ( ! V_201 ) {
F_86 ( L_13 , V_284 ) ;
return;
}
V_201 -> V_203 = V_285 ;
V_23 = (struct V_283 * ) F_132 ( V_201 , sizeof( * V_23 ) ) ;
V_23 -> V_205 . V_206 = F_65 ( F_66 ( V_207 ) ) ;
F_67 ( V_23 ) = F_65 ( F_68 ( V_286 , V_122 ) ) ;
V_23 -> V_287 = 0 ;
V_23 -> V_288 = 0 ;
V_23 -> V_289 = F_19 ( V_290 ) ;
V_23 -> V_291 = F_133 ( F_134 ( V_292 ) ) ;
V_23 -> V_26 = F_133 ( F_134 ( V_174 -> V_293 ) ) ;
V_2 -> V_280 ( V_2 , V_201 ) ;
}
static void F_120 ( struct V_294 * V_271 , struct V_294 * V_272 ,
struct V_180 * V_181 ,
const void * V_273 )
{
struct V_14 * V_18 ;
struct V_185 * V_295 ;
struct V_1 * V_2 ;
T_1 V_122 ;
int V_296 ;
struct V_282 * V_174 ;
struct V_216 * V_297 ;
V_18 = V_181 -> V_18 ;
if ( ! F_127 ( V_18 ) )
return;
V_2 = F_83 ( V_18 ) ;
F_76 ( ! V_2 ) ;
V_174 = F_135 ( V_2 , V_272 , V_18 , V_273 ) ;
if ( ! V_174 ) {
F_86 ( L_14 , V_284 ) ;
return;
}
V_295 = & ( F_55 ( V_2 ) ) -> V_186 ;
for ( V_122 = 0 ; V_122 < V_295 -> V_220 ; V_122 ++ ) {
V_297 = F_97 ( V_295 , V_122 ) ;
F_76 ( ! V_297 ) ;
if ( V_297 && V_297 -> V_188 && V_297 -> V_7 && V_297 -> V_7 -> V_298 ) {
V_296 = V_297 -> V_7 -> V_298 ( V_297 -> V_188 , V_271 , V_272 , V_174 ) ;
if ( V_296 ) {
F_17 () ;
F_136 ( F_137 ( V_2 ) , V_174 ) ;
F_22 () ;
F_131 ( V_2 , V_122 , V_174 ) ;
}
}
}
F_138 ( V_2 , V_174 ) ;
}
static int F_139 ( struct V_185 * V_90 , unsigned int V_220 ,
unsigned int V_299 , unsigned int V_300 ,
unsigned int V_225 , unsigned int V_227 )
{
unsigned long V_108 = V_220 * sizeof( * V_90 -> V_199 ) +
V_299 * sizeof( * V_90 -> V_224 ) + V_300 * sizeof( * V_90 -> V_226 ) ;
V_90 -> V_199 = F_140 ( V_108 , V_217 ) ;
if ( ! V_90 -> V_199 )
return - V_301 ;
V_90 -> V_226 = (union V_195 * ) & V_90 -> V_199 [ V_220 ] ;
V_90 -> V_224 = (union V_187 * ) & V_90 -> V_226 [ V_300 ] ;
V_90 -> V_220 = V_220 ;
V_90 -> V_300 = V_300 ;
V_90 -> V_227 = V_227 ;
V_90 -> V_197 = NULL ;
V_90 -> V_299 = V_299 ;
V_90 -> V_225 = V_225 ;
V_90 -> V_192 = NULL ;
V_90 -> V_198 = V_90 -> V_193 = 0 ;
F_141 ( & V_90 -> V_200 , 0 ) ;
F_142 ( & V_90 -> V_196 ) ;
F_142 ( & V_90 -> V_190 ) ;
if ( V_300 ) {
while ( -- V_300 )
V_90 -> V_226 [ V_300 - 1 ] . V_191 = & V_90 -> V_226 [ V_300 ] ;
V_90 -> V_197 = V_90 -> V_226 ;
}
if ( V_299 ) {
while ( -- V_299 )
V_90 -> V_224 [ V_299 - 1 ] . V_191 = & V_90 -> V_224 [ V_299 ] ;
V_90 -> V_192 = V_90 -> V_224 ;
}
return 0 ;
}
static void F_143 ( struct V_185 * V_90 )
{
F_144 ( V_90 -> V_199 ) ;
}
static inline void F_145 ( struct V_3 * V_302 )
{
F_146 ( & V_281 ) ;
F_6 ( & V_302 -> V_303 , & V_303 ) ;
F_147 ( & V_281 ) ;
}
static inline void F_148 ( struct V_3 * V_302 )
{
F_146 ( & V_281 ) ;
F_10 ( & V_302 -> V_303 ) ;
F_147 ( & V_281 ) ;
}
int F_149 ( struct V_3 * V_3 )
{
struct V_1 * V_18 = & V_3 -> V_2 ;
int V_299 , V_304 ;
struct V_211 * V_90 ;
struct V_121 V_305 , V_121 ;
struct V_123 V_123 ;
unsigned int V_306 ;
struct V_307 * V_308 ;
V_90 = F_150 ( sizeof( * V_90 ) , V_217 ) ;
if ( ! V_90 )
return - V_301 ;
V_304 = - V_58 ;
if ( V_18 -> V_309 ( V_18 , V_138 , & V_90 -> V_310 ) < 0 ||
V_18 -> V_309 ( V_18 , V_134 , & V_90 -> V_311 ) < 0 ||
V_18 -> V_309 ( V_18 , V_147 , & V_306 ) < 0 ||
V_18 -> V_309 ( V_18 , V_148 , & V_123 ) < 0 ||
V_18 -> V_309 ( V_18 , V_139 , & V_121 ) < 0 ||
V_18 -> V_309 ( V_18 , V_146 , & V_305 ) < 0 )
goto V_312;
V_304 = - V_301 ;
V_308 = F_151 ( V_306 ) ;
if ( ! V_308 )
goto V_312;
V_299 = F_25 ( V_121 . V_140 / 2 , V_313 ) ;
V_304 = F_139 ( & V_90 -> V_186 , V_121 . V_140 , V_299 ,
V_305 . V_140 , V_314 , V_305 . V_145 ) ;
if ( V_304 )
goto V_315;
V_90 -> V_150 = V_123 . V_150 ;
V_90 -> V_316 = V_123 . V_108 ;
F_152 ( & V_90 -> V_213 , F_69 ) ;
F_142 ( & V_90 -> V_214 ) ;
F_153 ( & V_90 -> V_317 ) ;
V_90 -> V_18 = V_18 ;
F_154 ( V_18 -> V_318 , V_308 ) ;
F_55 ( V_18 ) = V_90 ;
V_18 -> V_182 = F_123 ;
V_18 -> V_183 = F_130 ;
if ( F_155 ( & V_303 ) )
F_156 ( & V_319 ) ;
V_90 -> V_218 = F_71 ( sizeof( struct V_202 ) , V_217 ) ;
V_90 -> V_219 = 0 ;
F_145 ( V_3 ) ;
return 0 ;
V_315:
F_144 ( V_308 ) ;
V_312:
F_157 ( V_90 ) ;
return V_304 ;
}
static void F_158 ( struct V_320 * V_321 )
{
struct V_307 * V_322 = F_70 ( V_321 , struct V_307 , V_320 ) ;
F_144 ( V_322 ) ;
}
void F_159 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
struct V_211 * V_90 = F_55 ( V_2 ) ;
struct V_307 * V_322 ;
F_148 ( V_3 ) ;
if ( F_155 ( & V_303 ) )
F_160 ( & V_319 ) ;
F_143 ( & V_90 -> V_186 ) ;
F_55 ( V_2 ) = NULL ;
F_17 () ;
V_322 = F_137 ( V_2 ) ;
F_22 () ;
F_154 ( V_2 -> V_318 , NULL ) ;
F_161 ( & V_322 -> V_320 , F_158 ) ;
if ( V_90 -> V_218 )
F_124 ( V_90 -> V_218 ) ;
F_157 ( V_90 ) ;
}
static inline void F_162 ( struct V_1 * V_2 )
{
static int V_323 ;
F_5 ( & V_8 ) ;
snprintf ( V_2 -> V_54 , sizeof( V_2 -> V_54 ) , L_15 , V_323 ++ ) ;
F_6 ( & V_2 -> V_324 , & V_324 ) ;
F_8 ( & V_8 ) ;
}
static inline void F_163 ( struct V_1 * V_2 )
{
F_5 ( & V_8 ) ;
F_10 ( & V_2 -> V_324 ) ;
F_8 ( & V_8 ) ;
}
static inline int F_164 ( struct V_3 * V_3 )
{
int type = 0 ;
switch ( V_3 -> V_46 . V_325 ) {
case V_326 :
type = V_221 ;
break;
case V_327 :
case V_328 :
type = V_329 ;
break;
case V_330 :
type = V_331 ;
break;
}
return type ;
}
void F_165 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
F_153 ( & V_2 -> V_324 ) ;
F_53 ( V_2 ) ;
V_2 -> V_280 = V_332 ;
V_2 -> V_309 = F_44 ;
V_2 -> type = F_164 ( V_3 ) ;
F_162 ( V_2 ) ;
}
void F_166 ( struct V_3 * V_3 )
{
struct V_1 * V_2 = & V_3 -> V_2 ;
V_2 -> V_182 = NULL ;
V_2 -> V_183 = NULL ;
F_163 ( V_2 ) ;
}
void T_6 F_167 ( void )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_275 ; ++ V_17 )
V_276 [ V_17 ] = F_121 ;
F_122 ( V_333 , F_84 ) ;
F_122 ( V_334 , F_88 ) ;
F_122 ( V_335 , F_89 ) ;
F_122 ( V_336 , F_94 ) ;
F_122 ( V_337 , F_94 ) ;
F_122 ( V_244 , F_98 ) ;
F_122 ( V_338 , F_96 ) ;
F_122 ( V_339 , F_96 ) ;
F_122 ( V_256 , F_96 ) ;
F_122 ( V_340 , F_96 ) ;
F_122 ( V_341 , F_96 ) ;
F_122 ( V_342 , F_96 ) ;
F_122 ( V_343 , F_96 ) ;
F_122 ( V_237 , F_90 ) ;
F_122 ( V_344 , F_96 ) ;
F_122 ( V_345 , F_96 ) ;
F_122 ( V_346 , F_107 ) ;
F_122 ( V_258 , F_109 ) ;
F_122 ( V_347 , F_96 ) ;
F_122 ( V_348 , F_96 ) ;
F_122 ( V_349 , F_117 ) ;
F_122 ( V_350 , F_96 ) ;
F_122 ( V_351 , F_110 ) ;
F_122 ( V_352 , F_96 ) ;
F_122 ( V_353 , F_96 ) ;
F_122 ( V_354 , F_96 ) ;
}
