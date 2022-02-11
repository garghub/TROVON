void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_3 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( ! F_2 ( & V_5 -> V_8 ) )
F_3 ( V_7 , V_5 ) ;
}
static T_1 F_4 ( T_2 V_9 )
{
T_1 V_10 ;
T_1 V_11 = 1 ;
while ( V_11 < V_9 )
V_11 *= 2 ;
switch ( V_11 ) {
case V_12 :
V_10 = 3 ;
break;
case V_13 :
case V_14 :
V_10 = 2 ;
break;
case V_15 :
case V_16 :
V_10 = 1 ;
break;
case V_17 :
default:
V_10 = 0 ;
break;
}
return V_10 ;
}
static void F_5 ( struct V_18 * V_19 , T_2 V_20 , T_2 V_21 )
{
if ( V_20 > V_22 )
V_20 = V_22 ;
if ( V_21 > V_23 )
V_21 = V_23 ;
V_19 -> V_24 = V_20 ;
V_19 -> V_25 = V_21 ;
}
void F_6 ( T_3 * V_26 , T_4 * V_27 )
{
* V_26 ++ = F_7 ( * V_27 ++ ) ;
* V_26 ++ = F_7 ( * V_27 ++ ) ;
* V_26 ++ = F_7 ( * V_27 ++ ) ;
* V_26 = F_7 ( * V_27 ) ;
}
static inline void F_8 ( T_4 * V_26 , T_3 * V_27 )
{
* V_26 ++ = F_9 ( * V_27 ++ ) ;
* V_26 ++ = F_9 ( * V_27 ++ ) ;
* V_26 ++ = F_9 ( * V_27 ++ ) ;
* V_26 = F_9 ( * V_27 ) ;
}
static inline void F_10 ( struct V_18 * V_19 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 = (struct V_30 * ) & V_29 -> V_32 ;
struct V_30 * V_33 = (struct V_30 * ) & V_29 -> V_34 ;
V_31 -> V_35 = V_36 ;
V_33 -> V_35 = V_36 ;
V_31 -> V_37 = F_11 ( V_19 -> V_38 ) ;
V_33 -> V_37 = F_11 ( V_19 -> V_39 ) ;
V_31 -> V_40 . V_41 = F_9 ( V_19 -> V_42 [ 0 ] ) ;
V_33 -> V_40 . V_41 = F_9 ( V_19 -> V_43 [ 0 ] ) ;
}
static inline void F_12 ( struct V_18 * V_19 ,
struct V_28 * V_29 )
{
struct V_44 * V_45 = (struct V_44 * ) & V_29 -> V_32 ;
struct V_44 * V_46 = (struct V_44 * ) & V_29 -> V_34 ;
V_45 -> V_47 = V_48 ;
V_46 -> V_47 = V_48 ;
V_45 -> V_49 = F_11 ( V_19 -> V_38 ) ;
V_46 -> V_49 = F_11 ( V_19 -> V_39 ) ;
F_8 ( V_45 -> V_50 . V_51 . V_52 ,
V_19 -> V_42 ) ;
F_8 ( V_46 -> V_50 . V_51 . V_52 ,
V_19 -> V_43 ) ;
}
static void F_13 ( struct V_18 * V_19 ,
struct V_53 * V_54 )
{
V_54 -> V_55 = V_19 -> V_55 ;
V_54 -> V_56 = V_19 -> V_56 ;
memcpy ( V_54 -> V_42 , V_19 -> V_42 , sizeof( V_54 -> V_42 ) ) ;
memcpy ( V_54 -> V_43 , V_19 -> V_43 , sizeof( V_54 -> V_43 ) ) ;
V_54 -> V_38 = V_19 -> V_38 ;
V_54 -> V_39 = V_19 -> V_39 ;
V_54 -> V_57 = V_19 -> V_57 ;
}
static inline void F_14 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
struct V_28 * V_29 )
{
memcpy ( & V_29 -> V_32 , & V_59 -> V_60 ,
sizeof( V_29 -> V_32 ) ) ;
memcpy ( & V_29 -> V_34 , & V_59 -> V_61 ,
sizeof( V_29 -> V_34 ) ) ;
if ( V_19 ) {
V_29 -> V_62 = ( void * ) V_19 -> V_63 ;
V_29 -> V_64 = ( T_1 ) V_19 -> V_65 . V_66 ;
V_29 -> V_67 = V_19 -> V_24 ;
V_29 -> V_68 = V_19 -> V_25 ;
}
}
static int F_15 ( struct V_18 * V_19 ,
struct V_58 * V_59 ,
enum V_69 type ,
int V_70 )
{
struct V_28 V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_29 = type ;
V_29 . V_70 = V_70 ;
switch ( type ) {
case V_71 :
if ( V_19 -> V_55 )
F_10 ( V_19 , & V_29 ) ;
else
F_12 ( V_19 , & V_29 ) ;
V_29 . V_72 = ( void * ) V_19 ;
V_29 . V_62 = ( void * ) V_19 -> V_63 ;
V_29 . V_64 = ( T_1 ) V_19 -> V_65 . V_66 ;
V_29 . V_67 = V_19 -> V_24 ;
break;
case V_73 :
F_14 ( V_19 , V_59 , & V_29 ) ;
break;
case V_74 :
V_29 . V_67 = V_19 -> V_24 ;
V_29 . V_68 = V_19 -> V_25 ;
break;
case V_75 :
break;
case V_76 :
break;
default:
F_16 ( L_1 , type ) ;
return - 1 ;
}
return V_59 -> V_77 ( V_59 , & V_29 ) ;
}
static struct V_78 * F_17 ( struct V_18 * V_19 ,
enum V_79 type )
{
struct V_78 * V_29 ;
if ( ! V_19 -> V_59 )
return NULL ;
V_29 = F_18 ( sizeof( * V_29 ) , V_80 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> type = type ;
V_29 -> V_19 = V_19 ;
memcpy ( V_29 -> V_54 . V_43 , V_19 -> V_43 , sizeof( V_29 -> V_54 . V_43 ) ) ;
memcpy ( V_29 -> V_54 . V_42 , V_19 -> V_42 , sizeof( V_29 -> V_54 . V_42 ) ) ;
V_29 -> V_54 . V_39 = V_19 -> V_39 ;
V_29 -> V_54 . V_38 = V_19 -> V_38 ;
V_29 -> V_54 . V_59 = V_19 -> V_59 ;
F_19 ( V_19 -> V_81 ,
V_82 ,
L_2 ,
V_19 ,
V_29 ,
type ,
V_29 -> V_54 . V_42 ,
V_29 -> V_54 . V_43 ) ;
F_20 ( V_29 ) ;
return V_29 ;
}
static void F_21 ( struct V_18 * V_19 )
{
struct V_83 * V_84 = V_19 -> V_84 ;
struct V_85 * V_86 ;
V_86 = V_19 -> V_86 ;
if ( V_86 ) {
V_19 -> V_86 = NULL ;
F_1 ( & V_84 -> V_2 , ( void * ) V_86 -> V_87 ) ;
F_22 ( V_86 ) ;
F_23 ( & V_19 -> V_88 ) ;
}
}
static void F_24 ( struct V_18 * V_19 )
{
unsigned long V_89 ;
F_25 ( & V_19 -> V_90 , V_89 ) ;
F_21 ( V_19 ) ;
F_26 ( & V_19 -> V_90 , V_89 ) ;
}
static struct V_4 * F_27 ( struct V_18 * V_19 ,
struct V_91 * V_92 ,
struct V_91 * V_93 ,
struct V_91 * V_65 ,
T_1 V_89 )
{
struct V_4 * V_87 ;
struct V_1 * V_2 = & V_19 -> V_84 -> V_2 ;
T_1 * V_5 ;
struct V_94 * V_95 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_100 * V_101 ;
T_2 V_102 ;
T_2 V_103 = V_104 ;
T_3 V_105 = 0 ;
T_3 V_106 = 0 ;
T_3 V_107 = 0 ;
T_2 V_108 ;
V_87 = F_28 ( V_2 -> V_7 ) ;
if ( ! V_87 )
return NULL ;
V_5 = V_87 -> V_109 . V_110 ;
if ( V_92 )
V_105 = ( T_3 ) V_92 -> V_66 ;
if ( V_93 )
V_107 = V_93 -> V_66 ;
if ( V_65 )
V_106 = V_65 -> V_66 ;
if ( V_19 -> V_56 < V_111 )
V_103 += 4 ;
if ( V_19 -> V_55 )
V_102 = sizeof( * V_97 ) + sizeof( * V_95 ) ;
else
V_102 = sizeof( * V_99 ) + sizeof( * V_95 ) ;
V_102 += V_105 + V_107 + V_106 ;
memset ( V_5 , 0x00 , V_103 + V_102 ) ;
V_87 -> V_112 = V_102 + V_103 ;
V_87 -> V_113 = V_103 ;
V_87 -> V_114 = sizeof( * V_95 ) + V_105 ;
V_87 -> V_115 = ( void * ) V_19 ;
V_101 = (struct V_100 * ) V_5 ;
V_5 += V_103 ;
if ( V_19 -> V_55 ) {
V_87 -> V_55 = true ;
V_97 = (struct V_96 * ) V_5 ;
V_5 += sizeof( * V_97 ) ;
V_95 = (struct V_94 * ) V_5 ;
V_5 += sizeof( * V_95 ) ;
F_29 ( V_101 -> V_116 , V_19 -> V_117 ) ;
F_29 ( V_101 -> V_118 , V_19 -> V_119 ) ;
if ( V_19 -> V_56 < V_111 ) {
( (struct V_120 * ) V_101 ) -> V_121 = F_11 ( V_122 ) ;
V_108 = ( V_19 -> V_57 << V_123 ) | V_19 -> V_56 ;
( (struct V_120 * ) V_101 ) -> V_124 = F_11 ( V_108 ) ;
( (struct V_120 * ) V_101 ) -> V_125 = F_11 ( V_126 ) ;
} else {
V_101 -> V_127 = F_11 ( V_126 ) ;
}
V_97 -> V_128 = V_129 ;
V_97 -> V_130 = 5 ;
V_97 -> V_131 = V_19 -> V_131 ;
V_97 -> V_132 = F_11 ( V_102 ) ;
V_97 -> V_133 = F_11 ( ++ V_19 -> V_134 . V_135 ) ;
V_97 -> V_136 = F_11 ( 0x4000 ) ;
V_97 -> V_137 = 0x40 ;
V_97 -> V_138 = V_139 ;
V_97 -> V_140 = F_9 ( V_19 -> V_42 [ 0 ] ) ;
V_97 -> V_141 = F_9 ( V_19 -> V_43 [ 0 ] ) ;
} else {
V_87 -> V_55 = false ;
V_99 = (struct V_98 * ) V_5 ;
V_5 += sizeof( * V_99 ) ;
V_95 = (struct V_94 * ) V_5 ;
V_5 += sizeof( * V_95 ) ;
F_29 ( V_101 -> V_116 , V_19 -> V_117 ) ;
F_29 ( V_101 -> V_118 , V_19 -> V_119 ) ;
if ( V_19 -> V_56 < V_111 ) {
( (struct V_120 * ) V_101 ) -> V_121 = F_11 ( V_122 ) ;
V_108 = ( V_19 -> V_57 << V_123 ) | V_19 -> V_56 ;
( (struct V_120 * ) V_101 ) -> V_124 = F_11 ( V_108 ) ;
( (struct V_120 * ) V_101 ) -> V_125 = F_11 ( V_142 ) ;
} else {
V_101 -> V_127 = F_11 ( V_142 ) ;
}
V_99 -> V_128 = 6 ;
V_99 -> V_143 = V_19 -> V_131 >> 4 ;
V_99 -> V_144 [ 0 ] = V_19 -> V_131 << 4 ;
V_99 -> V_144 [ 1 ] = 0 ;
V_99 -> V_144 [ 2 ] = 0 ;
V_99 -> V_145 = F_11 ( V_102 - sizeof( * V_99 ) ) ;
V_99 -> V_146 = 6 ;
V_99 -> V_147 = 128 ;
F_8 ( V_99 -> V_140 . V_51 . V_52 ,
V_19 -> V_42 ) ;
F_8 ( V_99 -> V_141 . V_51 . V_52 ,
V_19 -> V_43 ) ;
}
V_95 -> V_148 = F_11 ( V_19 -> V_38 ) ;
V_95 -> V_149 = F_11 ( V_19 -> V_39 ) ;
V_95 -> V_150 = F_9 ( V_19 -> V_134 . V_151 ) ;
if ( V_89 & V_152 ) {
V_19 -> V_134 . V_153 = V_19 -> V_134 . V_154 ;
V_95 -> V_155 = F_9 ( V_19 -> V_134 . V_153 ) ;
V_95 -> V_156 = 1 ;
} else {
V_95 -> V_155 = 0 ;
}
if ( V_89 & V_157 ) {
V_19 -> V_134 . V_151 ++ ;
V_95 -> V_158 = 1 ;
} else {
V_19 -> V_134 . V_151 += V_107 + V_106 ;
}
if ( V_89 & V_159 ) {
V_19 -> V_134 . V_151 ++ ;
V_95 -> V_160 = 1 ;
}
if ( V_89 & V_161 )
V_95 -> V_162 = 1 ;
V_95 -> V_163 = ( T_2 ) ( ( sizeof( * V_95 ) + V_105 + 3 ) >> 2 ) ;
V_87 -> V_114 = V_95 -> V_163 << 2 ;
V_95 -> V_164 = F_11 ( V_19 -> V_134 . V_165 ) ;
V_95 -> V_166 = 0 ;
if ( V_105 ) {
memcpy ( V_5 , V_92 -> V_167 , V_105 ) ;
V_5 += V_105 ;
}
if ( V_107 ) {
memcpy ( V_5 , V_93 -> V_167 , V_107 ) ;
V_5 += V_107 ;
}
if ( V_65 && V_65 -> V_167 )
memcpy ( V_5 , V_65 -> V_167 , V_65 -> V_66 ) ;
F_30 ( & V_87 -> V_8 , 1 ) ;
return V_87 ;
}
static int F_31 ( struct V_18 * V_19 )
{
struct V_4 * V_87 ;
int V_89 = V_161 | V_152 ;
V_87 = F_27 ( V_19 , NULL , NULL , NULL , V_89 ) ;
if ( ! V_87 ) {
F_16 ( L_3 ) ;
return - 1 ;
}
return F_32 ( V_19 , V_87 , V_168 , 0 , 1 ) ;
}
static void F_33 ( struct V_18 * V_19 , bool V_169 )
{
F_24 ( V_19 ) ;
V_19 -> V_170 -> V_171 ++ ;
if ( V_169 ) {
F_19 ( V_19 -> V_81 ,
V_82 ,
L_4 ,
V_172 ,
V_19 ,
V_19 -> V_173 ) ;
F_34 ( & V_19 -> V_88 ) ;
F_31 ( V_19 ) ;
}
V_19 -> V_173 = V_174 ;
F_17 ( V_19 , V_175 ) ;
}
static void F_35 ( struct V_18 * V_19 , bool V_169 )
{
F_24 ( V_19 ) ;
V_19 -> V_170 -> V_176 ++ ;
V_19 -> V_173 = V_174 ;
F_19 ( V_19 -> V_81 ,
V_82 ,
L_5 ,
V_172 ,
V_19 ,
V_19 -> V_173 ) ;
if ( V_169 )
F_31 ( V_19 ) ;
else
F_36 ( V_19 ) ;
}
static void F_37 ( struct V_78 * V_29 )
{
struct V_177 * V_178 ;
struct V_58 * V_59 ;
V_59 = V_29 -> V_19 -> V_59 ;
if ( ! V_59 )
return;
V_178 = V_59 -> V_72 ;
if ( ! V_178 || ! V_178 -> V_84 )
return;
V_178 -> V_59 = NULL ;
V_59 -> V_72 = NULL ;
F_15 ( V_29 -> V_19 , V_59 ,
V_73 ,
- V_179 ) ;
V_59 -> V_180 ( V_59 ) ;
F_36 ( V_29 -> V_19 ) ;
}
static int F_38 ( struct V_18 * V_19 ,
T_1 * V_181 ,
T_3 V_182 ,
T_3 V_183 )
{
T_3 V_184 ;
T_3 V_185 = 0 ;
union V_186 * V_187 ;
char V_188 = 0 ;
while ( V_185 < V_182 ) {
V_187 = (union V_186 * ) ( V_181 + V_185 ) ;
switch ( V_187 -> V_189 . V_190 ) {
case V_191 :
V_185 = V_182 ;
break;
case V_192 :
V_185 += 1 ;
continue;
case V_193 :
F_19 ( V_19 -> V_81 ,
V_82 ,
L_6 ,
V_172 ,
V_187 -> V_194 . V_195 ,
V_185 ,
V_182 ) ;
V_188 = 1 ;
if ( V_187 -> V_194 . V_195 != 4 )
return - 1 ;
V_184 = F_39 ( V_187 -> V_194 . V_196 ) ;
if ( V_184 > 0 && V_184 < V_19 -> V_134 . V_196 )
V_19 -> V_134 . V_196 = V_184 ;
break;
case V_197 :
V_19 -> V_134 . V_198 =
V_187 -> V_199 . V_200 ;
break;
default:
F_19 ( V_19 -> V_81 ,
V_82 ,
L_7 ,
V_187 -> V_189 . V_190 ) ;
break;
}
V_185 += V_187 -> V_189 . V_195 ;
}
if ( ! V_188 && V_183 )
V_19 -> V_134 . V_196 = V_201 ;
return 0 ;
}
static int F_40 ( struct V_18 * V_19 ,
struct V_94 * V_95 ,
int V_182 ,
int V_202 )
{
T_1 * V_181 = ( T_1 * ) & V_95 [ 1 ] ;
if ( V_182 ) {
if ( F_38 ( V_19 ,
V_181 ,
V_182 ,
( T_3 ) V_95 -> V_158 ) ) {
F_19 ( V_19 -> V_81 ,
V_82 ,
L_8 ,
V_172 ,
V_19 ) ;
if ( V_202 )
F_35 ( V_19 , true ) ;
else
F_33 ( V_19 , true ) ;
return - 1 ;
}
}
V_19 -> V_134 . V_203 = F_39 ( V_95 -> V_164 ) <<
V_19 -> V_134 . V_198 ;
if ( V_19 -> V_134 . V_203 > V_19 -> V_134 . V_204 )
V_19 -> V_134 . V_204 = V_19 -> V_134 . V_203 ;
return 0 ;
}
static void F_41 ( struct V_18 * V_19 ,
void * V_205 ,
T_1 V_206 )
{
struct V_207 * V_208 = (struct V_207 * ) V_205 ;
switch ( V_206 ) {
case V_209 :
memcpy ( V_208 -> V_210 , V_211 , V_212 ) ;
break;
case V_213 :
memcpy ( V_208 -> V_210 , V_214 , V_212 ) ;
break;
default:
break;
}
V_208 -> V_89 = V_215 ;
V_208 -> V_216 = V_19 -> V_217 ;
V_208 -> V_218 = F_11 ( V_19 -> V_65 . V_66 ) ;
}
static void F_42 ( struct V_18 * V_19 ,
void * V_205 ,
T_1 V_206 )
{
struct V_219 * V_208 = (struct V_219 * ) V_205 ;
struct V_220 * V_221 = & V_208 -> V_221 ;
T_2 V_222 , V_223 ;
F_41 ( V_19 , V_205 , V_206 ) ;
V_208 -> V_89 |= V_224 ;
V_208 -> V_218 += F_11 ( V_225 ) ;
if ( V_19 -> V_226 == V_227 ) {
V_222 = V_227 ;
V_223 = V_227 ;
} else {
V_222 = ( V_19 -> V_24 > V_227 ) ?
V_227 : V_19 -> V_24 ;
V_223 = ( V_19 -> V_25 > V_227 ) ?
V_227 : V_19 -> V_25 ;
}
V_222 |= V_228 ;
V_222 |= V_229 ;
switch ( V_206 ) {
case V_209 :
V_223 |= V_230 ;
V_223 |= V_231 ;
break;
case V_213 :
switch ( V_19 -> V_232 ) {
case V_233 :
V_223 |= V_230 ;
break;
case V_234 :
V_223 |= V_231 ;
break;
}
break;
default:
break;
}
V_221 -> V_222 = F_11 ( V_222 ) ;
V_221 -> V_223 = F_11 ( V_223 ) ;
}
static int F_43 ( struct V_18 * V_19 ,
struct V_91 * V_235 ,
T_1 V_206 )
{
int V_107 = 0 ;
switch ( V_19 -> V_217 ) {
case V_236 :
V_107 = sizeof( struct V_207 ) ;
F_41 ( V_19 , V_235 -> V_167 , V_206 ) ;
break;
case V_237 :
V_107 = sizeof( struct V_219 ) ;
F_42 ( V_19 , V_235 -> V_167 , V_206 ) ;
break;
default:
break;
}
return V_107 ;
}
static int F_44 ( struct V_18 * V_19 )
{
struct V_4 * V_87 ;
if ( ! V_19 ) {
F_16 ( L_9 ) ;
return - 1 ;
}
V_19 -> V_238 . V_167 = & V_19 -> V_208 ;
V_19 -> V_238 . V_66 = F_43 ( V_19 ,
& V_19 -> V_238 ,
V_209 ) ;
if ( ! V_19 -> V_238 . V_66 ) {
F_16 ( L_10 , V_19 -> V_238 . V_66 ) ;
return - 1 ;
}
V_87 = F_27 ( V_19 ,
NULL ,
& V_19 -> V_238 ,
& V_19 -> V_65 ,
V_152 ) ;
if ( ! V_87 ) {
F_16 ( L_11 ) ;
return - 1 ;
}
return F_32 ( V_19 , V_87 , V_168 , 1 , 0 ) ;
}
static int F_45 ( struct V_18 * V_19 ,
const void * V_65 ,
T_1 V_239 )
{
struct V_4 * V_87 ;
struct V_91 V_240 ;
V_19 -> V_238 . V_167 = & V_19 -> V_208 ;
V_19 -> V_238 . V_66 = F_43 ( V_19 ,
& V_19 -> V_238 ,
V_213 ) ;
V_19 -> V_208 . V_89 |= V_241 ;
V_240 . V_167 = ( void * ) V_65 ;
V_240 . V_66 = V_239 ;
V_87 = F_27 ( V_19 ,
NULL ,
& V_19 -> V_238 ,
& V_240 ,
V_152 | V_159 ) ;
if ( ! V_87 ) {
F_16 ( L_3 ) ;
return - V_242 ;
}
V_19 -> V_173 = V_243 ;
return F_32 ( V_19 , V_87 , V_168 , 1 , 0 ) ;
}
static int F_46 ( struct V_18 * V_19 , T_1 * V_244 , T_3 * type , T_3 V_245 )
{
struct V_207 * V_208 ;
struct V_219 * V_246 ;
struct V_220 * V_221 ;
int V_247 ;
int V_218 ;
* type = V_248 ;
if ( V_245 < sizeof( struct V_207 ) ) {
F_16 ( L_12 , V_245 ) ;
return - 1 ;
}
V_208 = (struct V_207 * ) V_244 ;
V_247 = sizeof( struct V_207 ) ;
V_218 = F_39 ( V_208 -> V_218 ) ;
if ( V_218 > V_249 ) {
F_16 ( L_13 , V_218 ) ;
return - 1 ;
}
if ( V_208 -> V_216 != V_236 && V_208 -> V_216 != V_237 ) {
F_16 ( L_14 , V_208 -> V_216 ) ;
return - 1 ;
}
if ( V_208 -> V_216 > V_19 -> V_217 ) {
F_16 ( L_15 , V_208 -> V_216 ) ;
return - 1 ;
}
V_19 -> V_217 = V_208 -> V_216 ;
if ( V_19 -> V_173 != V_250 ) {
if ( memcmp ( V_208 -> V_210 , V_211 , V_212 ) ) {
F_16 ( L_16 ) ;
return - 1 ;
}
} else {
if ( memcmp ( V_208 -> V_210 , V_214 , V_212 ) ) {
F_16 ( L_16 ) ;
return - 1 ;
}
}
if ( V_218 + V_247 > V_245 ) {
F_16 ( L_17 ,
V_218 , V_247 , V_245 ) ;
return - 1 ;
}
if ( V_245 > V_251 ) {
F_16 ( L_18 , V_245 ) ;
return - 1 ;
}
switch ( V_208 -> V_216 ) {
case V_237 : {
T_2 V_24 ;
T_2 V_25 ;
T_2 V_223 ;
T_2 V_222 ;
V_246 = (struct V_219 * ) V_244 ;
V_247 += V_225 ;
V_221 = & V_246 -> V_221 ;
V_223 = F_39 ( V_221 -> V_223 ) ;
V_222 = F_39 ( V_221 -> V_222 ) ;
V_24 = V_222 & V_227 ;
V_25 = V_223 & V_227 ;
if ( ! ( V_222 & V_228 ) )
return - 1 ;
if ( V_24 == V_227 || V_25 == V_227 ) {
V_19 -> V_226 = V_227 ;
goto V_252;
}
if ( V_19 -> V_173 != V_250 ) {
if ( ! V_25 && ( V_223 & V_231 ) )
V_19 -> V_24 = 1 ;
if ( V_19 -> V_25 > V_24 )
V_19 -> V_25 = V_24 ;
} else {
if ( ! V_24 && ( V_223 & V_231 ) )
return - 1 ;
if ( V_19 -> V_25 > V_24 )
V_19 -> V_25 = V_24 ;
if ( V_19 -> V_24 < V_25 )
return - 1 ;
}
V_252:
if ( V_223 & V_231 )
V_19 -> V_232 = V_234 ;
else if ( V_223 & V_230 )
V_19 -> V_232 = V_233 ;
else
return - 1 ;
F_19 ( V_19 -> V_81 , V_82 ,
L_19 ,
V_19 -> V_25 , V_19 -> V_24 ) ;
break;
}
break;
case V_236 :
default:
break;
}
memcpy ( V_19 -> V_63 , V_244 + V_247 , V_218 ) ;
V_19 -> V_65 . V_66 = V_218 ;
if ( V_208 -> V_89 & V_241 )
* type = V_253 ;
if ( V_208 -> V_89 & V_254 )
V_19 -> V_255 = true ;
return 0 ;
}
int F_32 ( struct V_18 * V_19 ,
struct V_4 * V_87 ,
enum V_256 type ,
int V_257 ,
int V_258 )
{
struct V_1 * V_2 = & V_19 -> V_84 -> V_2 ;
struct V_259 * V_170 = V_19 -> V_170 ;
struct V_85 * V_260 ;
int V_261 = 0 ;
T_3 V_262 ;
unsigned long V_89 ;
V_260 = F_18 ( sizeof( * V_260 ) , V_80 ) ;
if ( ! V_260 ) {
F_1 ( V_2 , ( void * ) V_87 ) ;
return - V_242 ;
}
V_260 -> V_263 = V_264 ;
V_260 -> V_265 = V_266 ;
V_260 -> V_87 = V_87 ;
V_260 -> V_267 = V_268 ;
V_260 -> type = type ;
V_260 -> V_257 = V_257 ;
V_260 -> V_258 = V_258 ;
if ( type == V_269 ) {
V_260 -> V_267 += ( V_270 / 10 ) ;
if ( V_19 -> V_271 ) {
F_22 ( V_260 ) ;
F_1 ( V_2 , ( void * ) V_87 ) ;
F_16 ( L_20 ) ;
return - V_272 ;
}
V_19 -> V_271 = V_260 ;
}
if ( type == V_168 ) {
F_25 ( & V_19 -> V_90 , V_89 ) ;
V_19 -> V_86 = V_260 ;
F_34 ( & V_19 -> V_88 ) ;
F_26 ( & V_19 -> V_90 , V_89 ) ;
V_260 -> V_267 = V_268 + V_273 ;
F_34 ( & V_87 -> V_8 ) ;
F_47 ( V_2 -> V_7 , V_87 ) ;
if ( ! V_257 ) {
F_24 ( V_19 ) ;
if ( V_258 )
F_36 ( V_19 ) ;
return V_261 ;
}
}
F_25 ( & V_170 -> V_274 , V_89 ) ;
V_262 = F_48 ( & V_170 -> V_275 ) ;
if ( ! V_262 ) {
V_170 -> V_275 . V_276 = V_260 -> V_267 ;
F_49 ( & V_170 -> V_275 ) ;
}
F_26 ( & V_170 -> V_274 , V_89 ) ;
return V_261 ;
}
static void F_50 ( struct V_18 * V_19 )
{
struct V_58 * V_59 = V_19 -> V_59 ;
enum V_277 V_173 = V_19 -> V_173 ;
V_19 -> V_173 = V_174 ;
switch ( V_173 ) {
case V_278 :
case V_279 :
F_36 ( V_19 ) ;
break;
case V_243 :
case V_280 :
if ( V_19 -> V_59 )
V_59 -> V_180 ( V_59 ) ;
F_31 ( V_19 ) ;
break;
default:
F_34 ( & V_19 -> V_88 ) ;
F_31 ( V_19 ) ;
F_17 ( V_19 , V_175 ) ;
break;
}
}
static void F_51 ( struct V_18 * V_19 , T_3 V_281 )
{
struct V_85 * V_271 = V_19 -> V_271 ;
struct V_58 * V_59 = V_19 -> V_59 ;
struct V_177 * V_178 ;
unsigned long V_89 ;
if ( ! V_271 )
return;
V_178 = (struct V_177 * ) V_271 -> V_87 ;
if ( V_178 ) {
F_25 ( & V_178 -> V_282 , V_89 ) ;
if ( V_178 -> V_59 ) {
V_178 -> V_283 = V_284 ;
V_178 -> V_285 = V_286 ;
V_178 -> V_287 = V_288 ;
V_178 -> V_289 = V_290 ;
F_26 ( & V_178 -> V_282 , V_89 ) ;
F_52 ( V_178 ) ;
} else {
F_26 ( & V_178 -> V_282 , V_89 ) ;
}
} else if ( V_281 ) {
F_36 ( V_19 ) ;
}
if ( V_59 )
V_59 -> V_180 ( V_59 ) ;
F_22 ( V_271 ) ;
V_19 -> V_271 = NULL ;
}
static void F_53 ( unsigned long V_291 )
{
unsigned long V_292 = V_268 + V_293 ;
struct V_18 * V_19 ;
struct V_85 * V_86 , * V_271 ;
struct V_294 * V_295 ;
struct V_1 * V_2 ;
struct V_294 * V_296 ;
struct V_259 * V_170 = (struct V_259 * ) V_291 ;
T_3 V_297 = 0 ;
unsigned long V_267 ;
struct V_298 * V_81 ;
unsigned long V_89 ;
struct V_294 V_299 ;
F_54 ( & V_299 ) ;
F_25 ( & V_170 -> V_274 , V_89 ) ;
F_55 (list_node, list_core_temp, &cm_core->connected_nodes) {
V_19 = F_56 ( V_296 , struct V_18 , V_300 ) ;
if ( V_19 -> V_271 || V_19 -> V_86 ) {
F_34 ( & V_19 -> V_88 ) ;
F_57 ( & V_19 -> V_301 , & V_299 ) ;
}
}
F_26 ( & V_170 -> V_274 , V_89 ) ;
F_55 (list_node, list_core_temp, &timer_list) {
V_19 = F_56 ( V_296 ,
struct V_18 ,
V_301 ) ;
V_271 = V_19 -> V_271 ;
if ( V_271 ) {
if ( F_58 ( V_271 -> V_267 , V_268 ) ) {
if ( V_292 > V_271 -> V_267 ||
! V_297 ) {
V_292 = V_271 -> V_267 ;
V_297 = 1 ;
}
} else {
F_51 ( V_19 , 1 ) ;
}
}
F_25 ( & V_19 -> V_90 , V_89 ) ;
V_86 = V_19 -> V_86 ;
if ( ! V_86 )
goto V_302;
if ( F_58 ( V_86 -> V_267 , V_268 ) ) {
if ( V_19 -> V_173 != V_303 ) {
if ( ( V_292 > V_86 -> V_267 ) ||
! V_297 ) {
V_292 = V_86 -> V_267 ;
V_297 = 1 ;
}
} else {
F_21 ( V_19 ) ;
}
goto V_302;
}
if ( ( V_19 -> V_173 == V_303 ) ||
( V_19 -> V_173 == V_174 ) ) {
F_21 ( V_19 ) ;
goto V_302;
}
if ( ! V_86 -> V_265 || ! V_86 -> V_263 ) {
F_21 ( V_19 ) ;
F_26 ( & V_19 -> V_90 , V_89 ) ;
F_50 ( V_19 ) ;
V_19 -> V_173 = V_174 ;
F_25 ( & V_19 -> V_90 , V_89 ) ;
goto V_302;
}
V_19 -> V_170 -> V_304 ++ ;
F_26 ( & V_19 -> V_90 , V_89 ) ;
V_2 = & V_19 -> V_84 -> V_2 ;
V_81 = V_19 -> V_81 ;
F_34 ( & V_86 -> V_87 -> V_8 ) ;
F_47 ( V_2 -> V_7 , V_86 -> V_87 ) ;
F_25 ( & V_19 -> V_90 , V_89 ) ;
if ( V_86 -> V_257 ) {
V_86 -> V_265 -- ;
V_267 = ( V_273 <<
( V_266 -
V_86 -> V_265 ) ) ;
V_86 -> V_267 = V_268 +
F_59 ( V_267 , V_305 ) ;
if ( V_292 > V_86 -> V_267 || ! V_297 ) {
V_292 = V_86 -> V_267 ;
V_297 = 1 ;
}
} else {
int V_258 ;
V_258 = V_86 -> V_258 ;
F_19 ( V_19 -> V_81 ,
V_82 ,
L_21 ,
V_19 ,
V_19 -> V_173 ) ;
F_21 ( V_19 ) ;
if ( V_258 )
F_36 ( V_19 ) ;
}
V_302:
F_26 ( & V_19 -> V_90 , V_89 ) ;
F_36 ( V_19 ) ;
}
if ( V_297 ) {
F_25 ( & V_170 -> V_274 , V_89 ) ;
if ( ! F_48 ( & V_170 -> V_275 ) ) {
V_170 -> V_275 . V_276 = V_292 ;
F_49 ( & V_170 -> V_275 ) ;
}
F_26 ( & V_170 -> V_274 , V_89 ) ;
}
}
int F_60 ( struct V_18 * V_19 , T_3 V_306 )
{
struct V_4 * V_87 ;
int V_89 = V_157 ;
char V_307 [ sizeof( struct V_308 ) +
sizeof( struct V_309 ) +
sizeof( struct V_310 ) + V_311 ] ;
struct V_91 V_312 ;
int V_313 = 0 ;
union V_186 * V_92 ;
V_312 . V_167 = V_307 ;
if ( ! V_19 ) {
F_16 ( L_22 ) ;
return - V_272 ;
}
V_92 = (union V_186 * ) & V_307 [ V_313 ] ;
V_92 -> V_194 . V_190 = V_193 ;
V_92 -> V_194 . V_195 = sizeof( struct V_308 ) ;
V_92 -> V_194 . V_196 = F_11 ( V_19 -> V_134 . V_196 ) ;
V_313 += sizeof( struct V_308 ) ;
V_92 = (union V_186 * ) & V_307 [ V_313 ] ;
V_92 -> V_199 . V_190 = V_197 ;
V_92 -> V_199 . V_195 = sizeof( struct V_309 ) ;
V_92 -> V_199 . V_200 = V_19 -> V_134 . V_314 ;
V_313 += sizeof( struct V_309 ) ;
V_92 = (union V_186 * ) & V_307 [ V_313 ] ;
V_92 -> V_315 = V_191 ;
V_313 += 1 ;
if ( V_306 )
V_89 |= V_152 ;
V_312 . V_66 = V_313 ;
V_87 = F_27 ( V_19 , & V_312 , NULL , NULL , V_89 ) ;
if ( ! V_87 ) {
F_16 ( L_3 ) ;
return - 1 ;
}
return F_32 ( V_19 , V_87 , V_168 , 1 , 0 ) ;
}
static void F_61 ( struct V_18 * V_19 )
{
struct V_4 * V_87 ;
struct V_1 * V_2 = & V_19 -> V_84 -> V_2 ;
V_87 = F_27 ( V_19 , NULL , NULL , NULL , V_152 ) ;
if ( V_87 )
F_47 ( V_2 -> V_7 , V_87 ) ;
else
F_16 ( L_3 ) ;
}
static int F_62 ( struct V_18 * V_19 )
{
struct V_4 * V_87 ;
V_87 = F_27 ( V_19 , NULL , NULL , NULL , V_152 | V_159 ) ;
if ( ! V_87 ) {
F_16 ( L_3 ) ;
return - 1 ;
}
return F_32 ( V_19 , V_87 , V_168 , 1 , 0 ) ;
}
struct V_18 * F_63 ( struct V_259 * V_170 ,
T_2 V_39 ,
T_3 * V_43 ,
T_2 V_38 ,
T_3 * V_42 ,
bool V_316 )
{
struct V_294 * V_317 ;
struct V_18 * V_19 ;
unsigned long V_89 ;
V_317 = & V_170 -> V_318 ;
F_25 ( & V_170 -> V_274 , V_89 ) ;
F_64 (cm_node, hte, list) {
if ( ! memcmp ( V_19 -> V_42 , V_42 , sizeof( V_19 -> V_42 ) ) &&
( V_19 -> V_38 == V_38 ) &&
! memcmp ( V_19 -> V_43 , V_43 , sizeof( V_19 -> V_43 ) ) &&
( V_19 -> V_39 == V_39 ) ) {
if ( V_316 )
F_34 ( & V_19 -> V_88 ) ;
F_26 ( & V_170 -> V_274 , V_89 ) ;
return V_19 ;
}
}
F_26 ( & V_170 -> V_274 , V_89 ) ;
return NULL ;
}
static struct V_319 * F_65 (
struct V_259 * V_170 ,
T_3 * V_320 ,
T_2 V_321 ,
T_2 V_56 ,
enum V_322
V_323 )
{
struct V_319 * V_324 ;
static const T_3 V_325 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_3 V_326 [ 4 ] ;
T_2 V_327 ;
unsigned long V_89 ;
F_25 ( & V_170 -> V_328 , V_89 ) ;
F_64 (listen_node, &cm_core->listen_nodes, list) {
memcpy ( V_326 , V_324 -> V_42 , sizeof( V_326 ) ) ;
V_327 = V_324 -> V_38 ;
if ( ( ! memcmp ( V_326 , V_320 , sizeof( V_326 ) ) ||
! memcmp ( V_326 , V_325 , sizeof( V_326 ) ) ) &&
( V_327 == V_321 ) &&
( V_323 & V_324 -> V_323 ) ) {
F_34 ( & V_324 -> V_88 ) ;
F_26 ( & V_170 -> V_328 , V_89 ) ;
return V_324 ;
}
}
F_26 ( & V_170 -> V_328 , V_89 ) ;
return NULL ;
}
static void F_66 ( struct V_259 * V_170 ,
struct V_18 * V_19 )
{
struct V_294 * V_317 ;
unsigned long V_89 ;
if ( ! V_19 || ! V_170 ) {
F_16 ( L_23 ) ;
return;
}
F_25 ( & V_170 -> V_274 , V_89 ) ;
V_317 = & V_170 -> V_318 ;
F_67 ( & V_19 -> V_300 , V_317 ) ;
F_26 ( & V_170 -> V_274 , V_89 ) ;
}
static bool F_68 ( struct V_259 * V_170 , T_2 V_329 )
{
struct V_319 * V_324 ;
unsigned long V_89 ;
bool V_261 = false ;
F_25 ( & V_170 -> V_328 , V_89 ) ;
F_64 (listen_node, &cm_core->listen_nodes, list) {
if ( V_324 -> V_38 == V_329 ) {
V_261 = true ;
break;
}
}
F_26 ( & V_170 -> V_328 , V_89 ) ;
return V_261 ;
}
static enum V_330 F_69 (
struct V_83 * V_84 ,
struct V_53 * V_54 ,
struct V_319 * V_331 )
{
struct V_319 * V_332 ;
enum V_330 V_261 = V_333 ;
struct V_294 * V_334 , * V_335 ;
unsigned long V_89 ;
F_25 ( & V_84 -> V_170 . V_328 , V_89 ) ;
F_55 (pos, tpos, &cm_parent_listen_node->child_listen_list) {
V_332 = F_70 ( V_334 , struct V_319 , V_336 ) ;
if ( V_332 -> V_55 )
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_24 ,
V_332 -> V_42 ,
V_332 -> V_38 ,
V_332 -> V_56 ) ;
else
F_19 ( & V_84 -> V_337 , V_82 ,
L_25 ,
V_332 -> V_42 ,
V_332 -> V_38 ,
V_332 -> V_56 ) ;
F_71 ( V_334 ) ;
memcpy ( V_54 -> V_42 , V_332 -> V_42 ,
sizeof( V_54 -> V_42 ) ) ;
V_54 -> V_56 = V_332 -> V_56 ;
if ( V_332 -> V_338 ) {
V_261 = F_72 ( V_84 , V_54 ,
V_339 ,
V_340 ,
NULL , false ) ;
V_332 -> V_338 = false ;
} else {
V_261 = V_341 ;
}
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_26 ,
V_332 ) ;
F_22 ( V_332 ) ;
V_331 -> V_170 -> V_342 ++ ;
}
F_26 ( & V_84 -> V_170 . V_328 , V_89 ) ;
return V_261 ;
}
static struct V_343 * F_73 ( T_3 * V_167 , T_2 * V_56 , T_1 * V_344 )
{
struct V_343 * V_345 = NULL ;
struct V_346 V_45 ;
if ( ! F_74 ( V_347 ) )
return NULL ;
F_8 ( V_45 . V_51 . V_52 , V_167 ) ;
if ( V_56 )
* V_56 = V_348 ;
if ( V_344 )
F_75 ( V_344 ) ;
F_76 () ;
F_77 (&init_net, ip_dev) {
if ( F_78 ( & V_349 , & V_45 , V_345 , 1 ) ) {
if ( V_56 )
* V_56 = F_79 ( V_345 ) ;
if ( V_345 -> V_350 && V_344 )
F_29 ( V_344 , V_345 -> V_350 ) ;
break;
}
}
F_80 () ;
return V_345 ;
}
static T_2 F_81 ( T_3 * V_167 )
{
struct V_343 * V_351 ;
T_2 V_56 = V_348 ;
V_351 = F_82 ( & V_349 , F_9 ( V_167 [ 0 ] ) ) ;
if ( V_351 ) {
V_56 = F_79 ( V_351 ) ;
F_83 ( V_351 ) ;
}
return V_56 ;
}
static enum V_330 F_84 ( struct V_83 * V_84 ,
struct V_53 * V_54 ,
struct V_319 * V_331 )
{
struct V_343 * V_345 ;
struct V_352 * V_353 ;
struct V_354 * V_355 , * V_184 ;
enum V_330 V_261 = 0 ;
struct V_319 * V_332 ;
unsigned long V_89 ;
F_85 () ;
F_77 (&init_net, ip_dev) {
if ( ( ( ( F_79 ( V_345 ) < V_348 ) &&
( F_86 ( V_345 ) == V_84 -> V_351 ) ) ||
( V_345 == V_84 -> V_351 ) ) && ( V_345 -> V_89 & V_356 ) ) {
V_353 = F_87 ( V_345 ) ;
if ( ! V_353 ) {
F_16 ( L_27 ) ;
break;
}
F_88 (ifp, tmp, &idev->addr_list, if_list) {
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_28 ,
& V_355 -> V_167 ,
F_79 ( V_345 ) ,
V_345 -> V_350 ) ;
V_332 =
F_18 ( sizeof( * V_332 ) , V_80 ) ;
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_29 ,
V_332 ) ;
if ( ! V_332 ) {
V_261 = V_357 ;
goto exit;
}
V_54 -> V_56 = F_79 ( V_345 ) ;
V_331 -> V_56 = V_54 -> V_56 ;
memcpy ( V_332 , V_331 ,
sizeof( * V_332 ) ) ;
F_6 ( V_332 -> V_42 ,
V_355 -> V_167 . V_51 . V_52 ) ;
memcpy ( V_54 -> V_42 , V_332 -> V_42 ,
sizeof( V_54 -> V_42 ) ) ;
V_261 = F_72 ( V_84 , V_54 ,
V_339 ,
V_358 ,
NULL , true ) ;
if ( ! V_261 ) {
V_332 -> V_338 = true ;
F_25 ( & V_84 -> V_170 . V_328 , V_89 ) ;
F_57 ( & V_332 -> V_336 ,
& V_331 -> V_336 ) ;
F_26 ( & V_84 -> V_170 . V_328 , V_89 ) ;
V_331 -> V_170 -> V_359 ++ ;
} else {
F_22 ( V_332 ) ;
}
}
}
}
exit:
F_89 () ;
return V_261 ;
}
static enum V_330 F_90 (
struct V_83 * V_84 ,
struct V_53 * V_54 ,
struct V_319 * V_331 )
{
struct V_343 * V_81 ;
struct V_360 * V_353 ;
struct V_319 * V_332 ;
enum V_330 V_261 = 0 ;
unsigned long V_89 ;
F_85 () ;
F_91 (&init_net, dev) {
if ( ( ( ( F_79 ( V_81 ) < V_348 ) &&
( F_86 ( V_81 ) == V_84 -> V_351 ) ) ||
( V_81 == V_84 -> V_351 ) ) && ( V_81 -> V_89 & V_356 ) ) {
V_353 = F_92 ( V_81 ) ;
F_93 (idev) {
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_30 ,
& V_361 -> V_362 ,
F_79 ( V_81 ) ,
V_81 -> V_350 ) ;
V_332 = F_18 ( sizeof( * V_332 ) , V_80 ) ;
V_331 -> V_170 -> V_359 ++ ;
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_29 ,
V_332 ) ;
if ( ! V_332 ) {
F_94 ( V_353 ) ;
V_261 = V_357 ;
goto exit;
}
V_54 -> V_56 = F_79 ( V_81 ) ;
V_331 -> V_56 = V_54 -> V_56 ;
memcpy ( V_332 ,
V_331 ,
sizeof( * V_332 ) ) ;
V_332 -> V_42 [ 0 ] = F_7 ( V_361 -> V_362 ) ;
memcpy ( V_54 -> V_42 , V_332 -> V_42 ,
sizeof( V_54 -> V_42 ) ) ;
V_261 = F_72 ( V_84 ,
V_54 ,
V_339 ,
V_358 ,
NULL ,
true ) ;
if ( ! V_261 ) {
V_332 -> V_338 = true ;
F_25 ( & V_84 -> V_170 . V_328 , V_89 ) ;
F_57 ( & V_332 -> V_336 ,
& V_331 -> V_336 ) ;
F_26 ( & V_84 -> V_170 . V_328 , V_89 ) ;
} else {
F_22 ( V_332 ) ;
V_331 -> V_170 -> V_359 -- ;
}
}
F_95 ( V_353 ) ;
F_94 ( V_353 ) ;
}
}
exit:
F_89 () ;
return V_261 ;
}
static int F_96 ( struct V_259 * V_170 ,
struct V_319 * V_363 ,
int V_364 , bool V_365 )
{
int V_261 = - V_272 ;
int V_366 = 0 ;
struct V_294 * V_367 ;
struct V_294 * V_368 ;
struct V_18 * V_19 ;
struct V_294 V_369 ;
struct V_53 V_370 ;
struct V_18 * V_371 ;
enum V_277 V_372 ;
unsigned long V_89 ;
F_54 ( & V_369 ) ;
if ( V_364 ) {
F_25 ( & V_170 -> V_274 , V_89 ) ;
F_55 (list_pos, list_temp, &cm_core->connected_nodes) {
V_19 = F_56 ( V_367 , struct V_18 , V_300 ) ;
if ( ( V_19 -> V_363 == V_363 ) && ! V_19 -> V_373 ) {
F_34 ( & V_19 -> V_88 ) ;
F_57 ( & V_19 -> V_374 , & V_369 ) ;
}
}
F_26 ( & V_170 -> V_274 , V_89 ) ;
}
F_55 (list_pos, list_temp, &reset_list) {
V_19 = F_56 ( V_367 , struct V_18 , V_374 ) ;
V_371 = V_19 -> V_375 ;
if ( V_19 -> V_173 >= V_243 ) {
F_36 ( V_19 ) ;
} else {
if ( ! V_371 ) {
F_24 ( V_19 ) ;
V_366 = F_31 ( V_19 ) ;
if ( V_366 ) {
V_19 -> V_173 = V_174 ;
F_16 ( L_31 ) ;
} else {
V_372 = V_19 -> V_173 ;
V_19 -> V_173 = V_376 ;
if ( V_372 != V_377 )
F_36 ( V_19 ) ;
}
} else {
struct V_78 V_29 ;
V_29 . V_19 = V_371 ;
memcpy ( V_29 . V_54 . V_43 ,
V_371 -> V_43 , sizeof( V_29 . V_54 . V_43 ) ) ;
memcpy ( V_29 . V_54 . V_42 ,
V_371 -> V_42 , sizeof( V_29 . V_54 . V_42 ) ) ;
V_29 . V_54 . V_39 = V_371 -> V_39 ;
V_29 . V_54 . V_38 = V_371 -> V_38 ;
V_29 . V_54 . V_59 = V_371 -> V_59 ;
V_29 . V_54 . V_55 = V_371 -> V_55 ;
F_34 ( & V_371 -> V_88 ) ;
V_371 -> V_173 = V_174 ;
F_37 ( & V_29 ) ;
V_19 -> V_173 = V_376 ;
F_36 ( V_19 ) ;
}
}
}
if ( ! F_2 ( & V_363 -> V_88 ) ) {
F_25 ( & V_170 -> V_328 , V_89 ) ;
F_71 ( & V_363 -> V_300 ) ;
F_26 ( & V_170 -> V_328 , V_89 ) ;
if ( V_363 -> V_84 ) {
if ( V_365 && ! F_68 ( V_170 , V_363 -> V_38 ) )
F_97 ( V_363 -> V_84 ,
V_363 -> V_38 ,
V_378 ) ;
memcpy ( V_370 . V_42 , V_363 -> V_42 , sizeof( V_370 . V_42 ) ) ;
V_370 . V_38 = V_363 -> V_38 ;
V_370 . V_55 = V_363 -> V_55 ;
V_370 . V_56 = V_363 -> V_56 ;
V_370 . V_57 = V_363 -> V_57 ;
if ( ! F_98 ( & V_363 -> V_336 ) ) {
F_69 ( V_363 -> V_84 , & V_370 , V_363 ) ;
} else {
if ( V_363 -> V_338 )
F_72 ( V_363 -> V_84 ,
& V_370 ,
V_339 ,
V_340 ,
NULL ,
false ) ;
}
}
V_170 -> V_379 ++ ;
F_22 ( V_363 ) ;
V_170 -> V_342 ++ ;
V_363 = NULL ;
V_261 = 0 ;
}
if ( V_363 ) {
if ( F_99 ( & V_363 -> V_380 ) > 0 )
F_19 ( V_170 -> V_81 ,
V_82 ,
L_32 ,
V_172 ,
V_363 ,
F_99 ( & V_363 -> V_380 ) ) ;
}
return V_261 ;
}
static int F_100 ( struct V_259 * V_170 ,
struct V_319 * V_363 ,
bool V_365 )
{
V_363 -> V_323 = V_381 ;
V_363 -> V_59 = NULL ;
return F_96 ( V_170 , V_363 , 1 , V_365 ) ;
}
static int F_101 ( struct V_83 * V_84 ,
T_3 V_382 ,
T_3 V_383 ,
int V_384 )
{
struct V_385 * V_386 ;
struct V_387 * V_388 ;
int V_389 = V_384 ;
struct V_343 * V_351 = V_84 -> V_351 ;
T_4 V_390 = F_9 ( V_383 ) ;
T_4 V_391 = F_9 ( V_382 ) ;
V_386 = F_102 ( & V_349 , V_390 , V_391 , 0 , 0 ) ;
if ( F_103 ( V_386 ) ) {
F_16 ( L_33 ) ;
return V_389 ;
}
if ( F_104 ( V_351 ) )
V_351 = F_105 ( V_351 ) ;
V_388 = F_106 ( & V_386 -> V_26 , & V_390 ) ;
F_76 () ;
if ( V_388 ) {
if ( V_388 -> V_392 & V_393 ) {
if ( V_384 >= 0 ) {
if ( F_107 ( V_84 -> V_394 [ V_384 ] . V_395 ,
V_388 -> V_396 ) )
goto V_397;
F_108 ( V_84 ,
V_84 -> V_394 [ V_384 ] . V_395 ,
& V_383 ,
true ,
V_398 ) ;
}
F_108 ( V_84 , V_388 -> V_396 , & V_383 , true , V_399 ) ;
V_389 = F_109 ( V_84 , & V_383 , true , NULL , V_400 ) ;
} else {
F_110 ( V_388 , NULL ) ;
}
}
V_397:
F_80 () ;
if ( V_388 )
F_111 ( V_388 ) ;
F_112 ( V_386 ) ;
return V_389 ;
}
static struct V_401 * F_113 ( struct V_44 * V_402 ,
struct V_44 * V_320 )
{
struct V_401 * V_26 ;
struct V_403 V_404 ;
memset ( & V_404 , 0 , sizeof( V_404 ) ) ;
V_404 . V_141 = V_320 -> V_50 ;
V_404 . V_140 = V_402 -> V_50 ;
if ( F_114 ( & V_404 . V_141 ) & V_405 )
V_404 . V_406 = V_320 -> V_407 ;
V_26 = F_115 ( & V_349 , NULL , & V_404 ) ;
return V_26 ;
}
static int F_116 ( struct V_83 * V_84 ,
T_3 * V_27 ,
T_3 * V_149 ,
int V_384 )
{
struct V_387 * V_388 ;
int V_389 = V_384 ;
struct V_343 * V_351 = V_84 -> V_351 ;
struct V_401 * V_26 ;
struct V_44 V_320 ;
struct V_44 V_402 ;
memset ( & V_320 , 0 , sizeof( V_320 ) ) ;
V_320 . V_47 = V_48 ;
F_8 ( V_320 . V_50 . V_51 . V_52 , V_149 ) ;
memset ( & V_402 , 0 , sizeof( V_402 ) ) ;
V_402 . V_47 = V_48 ;
F_8 ( V_402 . V_50 . V_51 . V_52 , V_27 ) ;
V_26 = F_113 ( & V_402 , & V_320 ) ;
if ( ! V_26 || V_26 -> error ) {
if ( V_26 ) {
F_117 ( V_26 ) ;
F_16 ( L_34 ,
V_26 -> error ) ;
}
return V_389 ;
}
if ( F_104 ( V_351 ) )
V_351 = F_105 ( V_351 ) ;
V_388 = F_106 ( V_26 , & V_320 ) ;
F_76 () ;
if ( V_388 ) {
F_19 ( & V_84 -> V_337 , V_82 , L_35 , V_388 -> V_396 ) ;
if ( V_388 -> V_392 & V_393 ) {
if ( V_384 >= 0 ) {
if ( F_107
( V_84 -> V_394 [ V_384 ] . V_395 ,
V_388 -> V_396 ) ) {
goto V_408;
}
F_108 ( V_84 ,
V_84 -> V_394 [ V_384 ] . V_395 ,
V_149 ,
false ,
V_398 ) ;
}
F_108 ( V_84 ,
V_388 -> V_396 ,
V_149 ,
false ,
V_399 ) ;
V_389 = F_109 ( V_84 ,
V_149 ,
false ,
NULL ,
V_400 ) ;
} else {
F_110 ( V_388 , NULL ) ;
}
}
V_408:
F_80 () ;
if ( V_388 )
F_111 ( V_388 ) ;
F_117 ( V_26 ) ;
return V_389 ;
}
static bool F_118 ( T_3 V_42 , T_3 V_43 )
{
return F_119 ( F_9 ( V_43 ) ) || ( V_42 == V_43 ) ;
}
static bool F_120 ( T_3 * V_42 , T_3 * V_43 )
{
struct V_346 V_46 ;
F_8 ( V_46 . V_51 . V_52 , V_43 ) ;
return ! memcmp ( V_42 , V_43 , 16 ) || F_121 ( & V_46 ) ;
}
static struct V_18 * F_122 (
struct V_259 * V_170 ,
struct V_83 * V_84 ,
struct V_53 * V_54 ,
struct V_319 * V_363 )
{
struct V_18 * V_19 ;
struct V_409 V_410 ;
int V_411 ;
int V_384 ;
struct V_343 * V_351 = V_84 -> V_351 ;
V_19 = F_18 ( sizeof( * V_19 ) , V_80 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_55 = V_54 -> V_55 ;
V_19 -> V_56 = V_54 -> V_56 ;
if ( ( V_19 -> V_56 == V_348 ) && V_84 -> V_412 )
V_19 -> V_56 = 0 ;
V_19 -> V_131 = V_54 -> V_131 ;
V_19 -> V_57 = V_54 -> V_57 ;
if ( V_363 ) {
if ( V_363 -> V_131 != V_54 -> V_131 )
F_19 ( & V_84 -> V_337 , V_413 ,
L_36 ,
V_363 -> V_131 , V_54 -> V_131 ) ;
V_19 -> V_131 = F_123 ( V_363 -> V_131 , V_54 -> V_131 ) ;
V_19 -> V_57 = F_124 ( V_19 -> V_131 ) ;
F_19 ( & V_84 -> V_337 , V_413 , L_37 ,
V_19 -> V_131 , V_19 -> V_57 ) ;
}
memcpy ( V_19 -> V_42 , V_54 -> V_42 , sizeof( V_19 -> V_42 ) ) ;
memcpy ( V_19 -> V_43 , V_54 -> V_43 , sizeof( V_19 -> V_43 ) ) ;
V_19 -> V_38 = V_54 -> V_38 ;
V_19 -> V_39 = V_54 -> V_39 ;
V_19 -> V_217 = V_84 -> V_414 ;
V_19 -> V_232 = V_234 ;
V_19 -> V_24 = V_22 ;
V_19 -> V_25 = V_23 ;
V_19 -> V_363 = V_363 ;
V_19 -> V_59 = V_54 -> V_59 ;
F_29 ( V_19 -> V_119 , V_351 -> V_350 ) ;
F_125 ( & V_19 -> V_90 ) ;
F_30 ( & V_19 -> V_88 , 1 ) ;
V_19 -> V_170 = V_170 ;
V_19 -> V_134 . V_135 = V_415 ;
V_19 -> V_134 . V_314 = V_416 ;
V_19 -> V_134 . V_165 =
V_417 >> V_416 ;
V_410 = F_126 () ;
V_19 -> V_134 . V_151 = V_410 . V_418 ;
V_19 -> V_134 . V_196 = V_84 -> V_2 . V_196 ;
V_19 -> V_84 = V_84 ;
V_19 -> V_81 = & V_84 -> V_337 ;
if ( ( V_19 -> V_55 &&
F_118 ( V_19 -> V_42 [ 0 ] , V_19 -> V_43 [ 0 ] ) ) ||
( ! V_19 -> V_55 && F_120 ( V_19 -> V_42 ,
V_19 -> V_43 ) ) ) {
V_384 = F_109 ( V_84 ,
V_19 -> V_43 ,
false ,
NULL ,
V_400 ) ;
} else {
V_411 = F_109 ( V_84 ,
V_19 -> V_43 ,
false ,
NULL ,
V_400 ) ;
if ( V_19 -> V_55 )
V_384 = F_101 ( V_84 ,
V_54 -> V_42 [ 0 ] ,
V_54 -> V_43 [ 0 ] ,
V_411 ) ;
else if ( F_74 ( V_347 ) )
V_384 = F_116 ( V_84 ,
V_54 -> V_42 ,
V_54 -> V_43 ,
V_411 ) ;
else
V_384 = - V_272 ;
}
if ( V_384 < 0 ) {
F_16 ( L_38 ) ;
F_22 ( V_19 ) ;
return NULL ;
}
F_29 ( V_19 -> V_117 , V_84 -> V_394 [ V_384 ] . V_395 ) ;
F_66 ( V_170 , V_19 ) ;
V_170 -> V_419 ++ ;
return V_19 ;
}
static void F_36 ( struct V_18 * V_19 )
{
struct V_259 * V_170 = V_19 -> V_170 ;
struct V_177 * V_178 ;
struct V_53 V_370 ;
unsigned long V_89 ;
F_25 ( & V_19 -> V_170 -> V_274 , V_89 ) ;
if ( F_2 ( & V_19 -> V_88 ) ) {
F_26 ( & V_19 -> V_170 -> V_274 , V_89 ) ;
return;
}
F_71 ( & V_19 -> V_300 ) ;
F_26 ( & V_19 -> V_170 -> V_274 , V_89 ) ;
if ( ! V_19 -> V_373 && V_19 -> V_420 ) {
F_127 ( L_39 ) ;
F_23 ( & V_19 -> V_363 -> V_380 ) ;
}
if ( V_19 -> V_271 )
F_51 ( V_19 , 0 ) ;
if ( V_19 -> V_363 ) {
F_96 ( V_170 , V_19 -> V_363 , 0 , true ) ;
} else {
if ( ! F_68 ( V_170 , V_19 -> V_38 ) &&
V_19 -> V_421 ) {
F_97 ( V_19 -> V_84 ,
V_19 -> V_38 ,
V_378 ) ;
F_13 ( V_19 , & V_370 ) ;
if ( V_19 -> V_338 ) {
F_72 ( V_19 -> V_84 ,
& V_370 ,
V_422 ,
V_340 ,
NULL ,
false ) ;
V_19 -> V_338 = 0 ;
}
}
}
V_178 = V_19 -> V_178 ;
if ( V_178 ) {
V_178 -> V_19 = NULL ;
F_128 ( & V_178 -> V_423 ) ;
V_19 -> V_178 = NULL ;
} else if ( V_19 -> V_338 ) {
F_13 ( V_19 , & V_370 ) ;
F_72 ( V_19 -> V_84 ,
& V_370 ,
V_422 ,
V_340 ,
NULL ,
false ) ;
V_19 -> V_338 = 0 ;
}
V_19 -> V_170 -> V_424 ++ ;
F_22 ( V_19 ) ;
}
static void F_129 ( struct V_18 * V_19 )
{
T_3 V_261 ;
switch ( V_19 -> V_173 ) {
case V_278 :
case V_425 :
case V_426 :
case V_427 :
V_19 -> V_134 . V_154 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_173 = V_280 ;
F_62 ( V_19 ) ;
break;
case V_250 :
F_17 ( V_19 , V_175 ) ;
V_19 -> V_134 . V_154 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_173 = V_174 ;
F_34 ( & V_19 -> V_88 ) ;
F_31 ( V_19 ) ;
break;
case V_243 :
V_19 -> V_134 . V_154 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_173 = V_279 ;
F_61 ( V_19 ) ;
break;
case V_428 :
V_19 -> V_134 . V_154 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_173 = V_429 ;
F_61 ( V_19 ) ;
V_261 =
F_32 ( V_19 , NULL , V_269 , 1 , 0 ) ;
if ( V_261 )
F_16 ( L_40 , V_19 , V_19 -> V_173 ) ;
break;
case V_429 :
V_19 -> V_134 . V_154 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_173 = V_174 ;
F_36 ( V_19 ) ;
break;
case V_303 :
default:
F_16 ( L_41 , V_19 , V_19 -> V_173 ) ;
break;
}
}
static void F_130 ( struct V_18 * V_19 ,
struct V_4 * V_430 )
{
F_24 ( V_19 ) ;
switch ( V_19 -> V_173 ) {
case V_425 :
case V_250 :
switch ( V_19 -> V_217 ) {
case V_237 :
V_19 -> V_217 = V_236 ;
V_19 -> V_173 = V_425 ;
if ( F_60 ( V_19 , 0 ) )
F_33 ( V_19 , false ) ;
break;
case V_236 :
default:
F_33 ( V_19 , false ) ;
break;
}
break;
case V_377 :
F_131 ( 1 , & V_19 -> V_431 ) ;
break;
case V_426 :
case V_278 :
case V_432 :
F_16 ( L_42 , V_19 -> V_173 ) ;
F_35 ( V_19 , false ) ;
break;
case V_303 :
F_33 ( V_19 , false ) ;
break;
case V_174 :
break;
case V_428 :
case V_243 :
case V_280 :
V_19 -> V_59 -> V_180 ( V_19 -> V_59 ) ;
case V_429 :
V_19 -> V_173 = V_174 ;
F_36 ( V_19 ) ;
break;
default:
break;
}
}
static void F_132 ( struct V_18 * V_19 ,
struct V_4 * V_430 )
{
int V_261 ;
int V_433 = V_430 -> V_434 ;
T_1 * V_435 = V_430 -> V_436 ;
enum V_79 type = V_437 ;
T_3 V_438 ;
V_261 = F_46 ( V_19 , V_435 , & V_438 , V_433 ) ;
if ( V_261 ) {
if ( V_19 -> V_173 == V_250 )
F_33 ( V_19 , true ) ;
else
F_35 ( V_19 , true ) ;
return;
}
switch ( V_19 -> V_173 ) {
case V_426 :
if ( V_438 == V_253 )
F_16 ( L_43 ) ;
V_19 -> V_173 = V_377 ;
type = V_439 ;
F_61 ( V_19 ) ;
F_30 ( & V_19 -> V_431 ,
V_440 ) ;
break;
case V_250 :
F_24 ( V_19 ) ;
if ( V_438 == V_253 ) {
type = V_441 ;
V_19 -> V_173 = V_427 ;
} else {
type = V_442 ;
V_19 -> V_173 = V_303 ;
F_61 ( V_19 ) ;
}
break;
default:
F_127 ( L_44 , V_172 , V_19 -> V_173 ) ;
break;
}
F_17 ( V_19 , type ) ;
}
static void F_133 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_173 ) {
case V_425 :
case V_250 :
F_33 ( V_19 , true ) ;
break;
case V_426 :
case V_278 :
F_35 ( V_19 , true ) ;
break;
case V_303 :
default:
break;
}
}
static int F_134 ( struct V_18 * V_19 , struct V_94 * V_95 )
{
int V_366 = 0 ;
if ( F_7 ( V_95 -> V_155 ) != V_19 -> V_134 . V_151 ) {
V_366 = 1 ;
F_33 ( V_19 , true ) ;
}
return V_366 ;
}
static int F_135 ( struct V_18 * V_19 , struct V_94 * V_95 )
{
int V_366 = 0 ;
T_3 V_150 ;
T_3 V_155 ;
T_3 V_151 = V_19 -> V_134 . V_151 ;
T_3 V_154 = V_19 -> V_134 . V_154 ;
T_3 V_165 ;
V_150 = F_7 ( V_95 -> V_150 ) ;
V_155 = F_7 ( V_95 -> V_155 ) ;
V_165 = V_19 -> V_134 . V_165 ;
if ( V_155 != V_151 )
V_366 = - 1 ;
else if ( ! F_136 ( V_150 , V_154 , ( V_154 + V_165 ) ) )
V_366 = - 1 ;
if ( V_366 ) {
F_16 ( L_45 ) ;
F_133 ( V_19 ) ;
}
return V_366 ;
}
static void F_137 ( struct V_18 * V_19 ,
struct V_4 * V_430 )
{
struct V_94 * V_95 = (struct V_94 * ) V_430 -> V_95 ;
int V_261 ;
T_3 V_443 ;
int V_182 ;
struct V_53 V_370 ;
V_182 = ( V_95 -> V_163 << 2 ) - sizeof( struct V_94 ) ;
V_443 = F_7 ( V_95 -> V_150 ) ;
switch ( V_19 -> V_173 ) {
case V_425 :
case V_250 :
F_33 ( V_19 , 1 ) ;
break;
case V_432 :
if ( F_99 ( & V_19 -> V_363 -> V_380 ) >
V_19 -> V_363 -> V_444 ) {
V_19 -> V_170 -> V_445 ++ ;
F_35 ( V_19 , false ) ;
break;
}
V_261 = F_40 ( V_19 , V_95 , V_182 , 1 ) ;
if ( V_261 ) {
F_35 ( V_19 , false ) ;
break;
}
V_19 -> V_134 . V_154 = V_443 + 1 ;
V_19 -> V_420 = 1 ;
F_34 ( & V_19 -> V_363 -> V_380 ) ;
V_19 -> V_173 = V_278 ;
F_13 ( V_19 , & V_370 ) ;
V_261 = F_72 ( V_19 -> V_84 ,
& V_370 ,
V_422 ,
V_358 ,
( void * ) V_19 ,
false ) ;
V_19 -> V_338 = true ;
break;
case V_174 :
F_24 ( V_19 ) ;
F_34 ( & V_19 -> V_88 ) ;
F_31 ( V_19 ) ;
break;
case V_303 :
case V_426 :
case V_243 :
case V_428 :
case V_377 :
case V_280 :
case V_279 :
case V_446 :
default:
break;
}
}
static void F_138 ( struct V_18 * V_19 ,
struct V_4 * V_430 )
{
struct V_94 * V_95 = (struct V_94 * ) V_430 -> V_95 ;
int V_261 ;
T_3 V_443 ;
int V_182 ;
V_182 = ( V_95 -> V_163 << 2 ) - sizeof( struct V_94 ) ;
V_443 = F_7 ( V_95 -> V_150 ) ;
switch ( V_19 -> V_173 ) {
case V_425 :
F_24 ( V_19 ) ;
if ( F_134 ( V_19 , V_95 ) ) {
F_16 ( L_46 ) ;
return;
}
V_19 -> V_134 . V_447 = F_7 ( V_95 -> V_155 ) ;
V_261 = F_40 ( V_19 , V_95 , V_182 , 0 ) ;
if ( V_261 ) {
F_19 ( V_19 -> V_81 ,
V_82 ,
L_47 ,
V_19 ) ;
break;
}
F_24 ( V_19 ) ;
V_19 -> V_134 . V_154 = V_443 + 1 ;
F_61 ( V_19 ) ;
V_261 = F_44 ( V_19 ) ;
if ( V_261 ) {
F_19 ( V_19 -> V_81 ,
V_82 ,
L_48 ,
V_19 ) ;
break;
}
V_19 -> V_173 = V_250 ;
break;
case V_377 :
F_35 ( V_19 , true ) ;
break;
case V_432 :
V_19 -> V_134 . V_151 = F_7 ( V_95 -> V_155 ) ;
F_24 ( V_19 ) ;
V_19 -> V_173 = V_174 ;
F_31 ( V_19 ) ;
break;
case V_174 :
V_19 -> V_134 . V_151 = F_7 ( V_95 -> V_155 ) ;
F_24 ( V_19 ) ;
F_34 ( & V_19 -> V_88 ) ;
F_31 ( V_19 ) ;
break;
case V_426 :
case V_243 :
case V_428 :
case V_280 :
case V_303 :
case V_279 :
case V_446 :
case V_250 :
default:
break;
}
}
static int F_139 ( struct V_18 * V_19 ,
struct V_4 * V_430 )
{
struct V_94 * V_95 = (struct V_94 * ) V_430 -> V_95 ;
T_3 V_443 ;
int V_261 = 0 ;
int V_182 ;
T_3 V_433 = V_430 -> V_434 ;
V_182 = ( V_95 -> V_163 << 2 ) - sizeof( struct V_94 ) ;
if ( F_135 ( V_19 , V_95 ) )
return - V_272 ;
V_443 = F_7 ( V_95 -> V_150 ) ;
switch ( V_19 -> V_173 ) {
case V_278 :
F_24 ( V_19 ) ;
V_261 = F_40 ( V_19 , V_95 , V_182 , 1 ) ;
if ( V_261 )
break;
V_19 -> V_134 . V_447 = F_7 ( V_95 -> V_155 ) ;
V_19 -> V_173 = V_426 ;
if ( V_433 ) {
V_19 -> V_134 . V_154 = V_443 + V_433 ;
F_132 ( V_19 , V_430 ) ;
}
break;
case V_426 :
F_24 ( V_19 ) ;
if ( V_433 ) {
V_19 -> V_134 . V_154 = V_443 + V_433 ;
F_132 ( V_19 , V_430 ) ;
}
break;
case V_250 :
V_19 -> V_134 . V_447 = F_7 ( V_95 -> V_155 ) ;
if ( V_433 ) {
V_19 -> V_134 . V_154 = V_443 + V_433 ;
F_132 ( V_19 , V_430 ) ;
}
break;
case V_432 :
F_24 ( V_19 ) ;
V_19 -> V_173 = V_174 ;
F_31 ( V_19 ) ;
break;
case V_174 :
F_24 ( V_19 ) ;
F_34 ( & V_19 -> V_88 ) ;
F_31 ( V_19 ) ;
break;
case V_280 :
case V_279 :
F_24 ( V_19 ) ;
V_19 -> V_173 = V_174 ;
if ( ! V_19 -> V_420 )
V_19 -> V_59 -> V_180 ( V_19 -> V_59 ) ;
F_36 ( V_19 ) ;
break;
case V_243 :
F_24 ( V_19 ) ;
V_19 -> V_173 = V_428 ;
break;
case V_425 :
case V_428 :
case V_303 :
case V_377 :
case V_446 :
default:
F_24 ( V_19 ) ;
break;
}
return V_261 ;
}
static void F_140 ( struct V_18 * V_19 ,
struct V_4 * V_430 )
{
enum V_448 V_449 = V_450 ;
struct V_94 * V_95 = (struct V_94 * ) V_430 -> V_95 ;
T_3 V_451 = 0 ;
int V_261 ;
if ( V_95 -> V_162 ) {
V_449 = V_452 ;
} else if ( V_95 -> V_158 ) {
V_449 = V_453 ;
if ( V_95 -> V_156 )
V_449 = V_454 ;
} else if ( V_95 -> V_156 ) {
V_449 = V_455 ;
}
if ( V_95 -> V_160 )
V_451 = 1 ;
switch ( V_449 ) {
case V_453 :
F_137 ( V_19 , V_430 ) ;
break;
case V_454 :
F_138 ( V_19 , V_430 ) ;
break;
case V_455 :
V_261 = F_139 ( V_19 , V_430 ) ;
if ( V_451 && ! V_261 )
F_129 ( V_19 ) ;
break;
case V_452 :
F_130 ( V_19 , V_430 ) ;
break;
default:
if ( V_451 &&
( ! F_135 ( V_19 , (struct V_94 * ) V_430 -> V_95 ) ) )
F_129 ( V_19 ) ;
break;
}
}
static struct V_319 * F_141 (
struct V_259 * V_170 ,
struct V_83 * V_84 ,
struct V_53 * V_54 )
{
struct V_319 * V_363 ;
unsigned long V_89 ;
V_363 = F_65 ( V_170 , V_54 -> V_42 ,
V_54 -> V_38 ,
V_54 -> V_56 ,
V_456 ) ;
if ( V_363 &&
( V_363 -> V_323 == V_457 ) ) {
F_23 ( & V_363 -> V_88 ) ;
F_19 ( V_170 -> V_81 ,
V_82 ,
L_49 ) ;
return NULL ;
}
if ( ! V_363 ) {
V_363 = F_18 ( sizeof( * V_363 ) , V_80 ) ;
if ( ! V_363 )
return NULL ;
V_170 -> V_359 ++ ;
memcpy ( V_363 -> V_42 , V_54 -> V_42 , sizeof( V_363 -> V_42 ) ) ;
V_363 -> V_38 = V_54 -> V_38 ;
F_54 ( & V_363 -> V_336 ) ;
F_30 ( & V_363 -> V_88 , 1 ) ;
} else {
V_363 -> V_458 = 1 ;
}
V_363 -> V_59 = V_54 -> V_59 ;
V_363 -> V_55 = V_54 -> V_55 ;
V_363 -> V_56 = V_54 -> V_56 ;
F_30 ( & V_363 -> V_380 , 0 ) ;
V_363 -> V_170 = V_170 ;
V_363 -> V_84 = V_84 ;
V_363 -> V_444 = V_54 -> V_444 ;
V_363 -> V_323 = V_457 ;
if ( ! V_363 -> V_458 ) {
F_25 ( & V_170 -> V_328 , V_89 ) ;
F_57 ( & V_363 -> V_300 , & V_170 -> V_459 ) ;
F_26 ( & V_170 -> V_328 , V_89 ) ;
}
return V_363 ;
}
static struct V_18 * F_142 (
struct V_259 * V_170 ,
struct V_83 * V_84 ,
T_2 V_64 ,
void * V_62 ,
struct V_53 * V_54 )
{
struct V_18 * V_19 ;
struct V_319 * V_460 ;
struct V_18 * V_461 ;
struct V_53 V_462 ;
V_19 = F_122 ( V_170 , V_84 , V_54 , NULL ) ;
if ( ! V_19 )
return F_143 ( - V_242 ) ;
V_19 -> V_134 . V_463 = 1 ;
V_19 -> V_134 . V_314 = V_416 ;
if ( ! memcmp ( V_54 -> V_42 , V_54 -> V_43 , sizeof( V_54 -> V_42 ) ) ) {
V_460 = F_65 (
V_170 ,
V_54 -> V_43 ,
V_19 -> V_39 ,
V_19 -> V_56 ,
V_457 ) ;
if ( ! V_460 ) {
F_36 ( V_19 ) ;
return F_143 ( - V_464 ) ;
} else {
V_462 = * V_54 ;
V_462 . V_38 = V_54 -> V_39 ;
V_462 . V_39 = V_54 -> V_38 ;
V_462 . V_59 = V_460 -> V_59 ;
V_462 . V_55 = V_54 -> V_55 ;
V_461 = F_122 ( V_170 ,
V_84 ,
& V_462 ,
V_460 ) ;
if ( ! V_461 ) {
F_36 ( V_19 ) ;
return F_143 ( - V_242 ) ;
}
V_170 -> V_465 ++ ;
V_461 -> V_375 = V_19 ;
V_461 -> V_134 . V_314 =
V_416 ;
V_19 -> V_375 = V_461 ;
memcpy ( V_461 -> V_63 , V_62 ,
V_64 ) ;
V_461 -> V_65 . V_66 = V_64 ;
V_19 -> V_173 = V_303 ;
V_19 -> V_134 . V_154 =
V_461 -> V_134 . V_151 ;
V_461 -> V_134 . V_154 =
V_19 -> V_134 . V_151 ;
V_19 -> V_134 . V_204 =
V_461 -> V_134 . V_165 ;
V_461 -> V_134 . V_204 = V_19 -> V_134 . V_165 ;
V_19 -> V_134 . V_203 = V_461 -> V_134 . V_165 ;
V_461 -> V_134 . V_203 = V_19 -> V_134 . V_165 ;
V_19 -> V_134 . V_198 = V_461 -> V_134 . V_314 ;
V_461 -> V_134 . V_198 = V_19 -> V_134 . V_314 ;
V_461 -> V_173 = V_377 ;
F_17 ( V_461 , V_439 ) ;
}
return V_19 ;
}
V_19 -> V_65 . V_66 = V_64 ;
V_19 -> V_65 . V_167 = V_19 -> V_63 ;
memcpy ( V_19 -> V_63 , V_62 , V_64 ) ;
V_19 -> V_173 = V_425 ;
return V_19 ;
}
static int F_144 ( struct V_18 * V_19 , const void * V_65 , T_1 V_239 )
{
int V_261 = 0 ;
int V_366 ;
int V_431 ;
struct V_58 * V_59 = V_19 -> V_59 ;
struct V_18 * V_371 = V_19 -> V_375 ;
if ( V_19 -> V_134 . V_463 )
return V_261 ;
F_24 ( V_19 ) ;
if ( ! V_371 ) {
V_431 = F_131 ( 1 , & V_19 -> V_431 ) ;
if ( V_431 == V_466 ) {
V_19 -> V_173 = V_174 ;
F_36 ( V_19 ) ;
} else {
if ( V_19 -> V_173 == V_376 ) {
F_36 ( V_19 ) ;
} else {
V_261 = F_45 ( V_19 , V_65 , V_239 ) ;
if ( V_261 ) {
V_19 -> V_173 = V_174 ;
V_366 = F_31 ( V_19 ) ;
if ( V_366 )
F_16 ( L_50 ) ;
} else {
V_59 -> V_467 ( V_59 ) ;
}
}
}
} else {
V_19 -> V_59 = NULL ;
if ( V_19 -> V_173 == V_376 ) {
F_36 ( V_19 ) ;
F_36 ( V_371 ) ;
} else {
V_261 = F_15 ( V_371 ,
V_371 -> V_59 ,
V_73 ,
- V_464 ) ;
F_36 ( V_19 ) ;
V_371 -> V_173 = V_279 ;
V_59 = V_371 -> V_59 ;
F_36 ( V_371 ) ;
V_59 -> V_180 ( V_59 ) ;
}
}
return V_261 ;
}
static int F_145 ( struct V_18 * V_19 )
{
int V_261 = 0 ;
if ( ! V_19 )
return - V_272 ;
switch ( V_19 -> V_173 ) {
case V_278 :
case V_425 :
case V_468 :
case V_426 :
case V_469 :
case V_250 :
case V_377 :
F_24 ( V_19 ) ;
F_31 ( V_19 ) ;
break;
case V_470 :
V_19 -> V_173 = V_280 ;
F_62 ( V_19 ) ;
break;
case V_243 :
case V_428 :
case V_280 :
case V_429 :
case V_279 :
V_261 = - 1 ;
break;
case V_432 :
F_24 ( V_19 ) ;
F_31 ( V_19 ) ;
break;
case V_427 :
case V_446 :
case V_471 :
case V_174 :
case V_376 :
F_36 ( V_19 ) ;
break;
case V_303 :
if ( V_19 -> V_86 )
F_16 ( L_51 ) ;
F_36 ( V_19 ) ;
break;
}
return V_261 ;
}
void F_146 ( struct V_1 * V_2 , struct V_4 * V_430 )
{
struct V_18 * V_19 ;
struct V_319 * V_363 ;
struct V_96 * V_97 ;
struct V_98 * V_99 ;
struct V_94 * V_95 ;
struct V_53 V_54 ;
struct V_298 * V_81 = V_2 -> V_81 ;
struct V_83 * V_84 = (struct V_83 * ) V_81 -> V_472 ;
struct V_259 * V_170 = & V_84 -> V_170 ;
struct V_120 * V_101 ;
T_2 V_108 ;
V_97 = (struct V_96 * ) V_430 -> V_97 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_147 ( V_81 ,
V_473 ,
L_52 ,
V_430 -> V_109 . V_110 ,
V_430 -> V_112 ) ;
V_101 = (struct V_120 * ) V_430 -> V_109 . V_110 ;
if ( V_101 -> V_121 == F_11 ( V_122 ) ) {
V_108 = F_39 ( V_101 -> V_124 ) ;
V_54 . V_57 = ( V_108 & V_474 ) >> V_123 ;
V_54 . V_56 = V_108 & V_475 ;
F_19 ( V_170 -> V_81 ,
V_82 ,
L_53 ,
V_172 ,
V_54 . V_56 ) ;
} else {
V_54 . V_56 = V_348 ;
}
V_95 = (struct V_94 * ) V_430 -> V_95 ;
if ( V_430 -> V_55 ) {
V_54 . V_42 [ 0 ] = F_7 ( V_97 -> V_141 ) ;
V_54 . V_43 [ 0 ] = F_7 ( V_97 -> V_140 ) ;
V_54 . V_55 = true ;
V_54 . V_131 = V_97 -> V_131 ;
} else {
V_99 = (struct V_98 * ) V_430 -> V_97 ;
F_6 ( V_54 . V_42 ,
V_99 -> V_141 . V_51 . V_52 ) ;
F_6 ( V_54 . V_43 ,
V_99 -> V_140 . V_51 . V_52 ) ;
V_54 . V_55 = false ;
V_54 . V_131 = ( V_99 -> V_143 << 4 ) | ( V_99 -> V_144 [ 0 ] >> 4 ) ;
}
V_54 . V_38 = F_39 ( V_95 -> V_149 ) ;
V_54 . V_39 = F_39 ( V_95 -> V_148 ) ;
V_19 = F_63 ( V_170 ,
V_54 . V_39 ,
V_54 . V_43 ,
V_54 . V_38 ,
V_54 . V_42 ,
true ) ;
if ( ! V_19 ) {
if ( ! V_95 -> V_158 || V_95 -> V_156 )
return;
V_363 =
F_65 ( V_170 ,
V_54 . V_42 ,
V_54 . V_38 ,
V_54 . V_56 ,
V_457 ) ;
if ( ! V_363 ) {
V_54 . V_59 = NULL ;
F_19 ( V_170 -> V_81 ,
V_82 ,
L_54 ,
V_172 ) ;
return;
}
V_54 . V_59 = V_363 -> V_59 ;
V_19 = F_122 ( V_170 , V_84 , & V_54 , V_363 ) ;
if ( ! V_19 ) {
F_19 ( V_170 -> V_81 ,
V_82 ,
L_55 ,
V_172 ) ;
F_23 ( & V_363 -> V_88 ) ;
return;
}
if ( ! V_95 -> V_162 && ! V_95 -> V_160 ) {
V_19 -> V_173 = V_432 ;
} else {
F_36 ( V_19 ) ;
return;
}
F_34 ( & V_19 -> V_88 ) ;
} else if ( V_19 -> V_173 == V_303 ) {
F_36 ( V_19 ) ;
return;
}
F_140 ( V_19 , V_430 ) ;
F_36 ( V_19 ) ;
}
void F_148 ( struct V_83 * V_84 )
{
struct V_259 * V_170 = & V_84 -> V_170 ;
V_170 -> V_84 = V_84 ;
V_170 -> V_81 = & V_84 -> V_337 ;
F_54 ( & V_170 -> V_318 ) ;
F_54 ( & V_170 -> V_459 ) ;
F_149 ( & V_170 -> V_275 ) ;
V_170 -> V_275 . V_476 = F_53 ;
V_170 -> V_275 . V_436 = ( unsigned long ) V_170 ;
F_125 ( & V_170 -> V_274 ) ;
F_125 ( & V_170 -> V_328 ) ;
V_170 -> V_477 = F_150 ( L_56 ,
V_478 ) ;
V_170 -> V_479 = F_150 ( L_57 ,
V_478 ) ;
}
void F_151 ( struct V_259 * V_170 )
{
unsigned long V_89 ;
if ( ! V_170 )
return;
F_25 ( & V_170 -> V_274 , V_89 ) ;
if ( F_48 ( & V_170 -> V_275 ) )
F_152 ( & V_170 -> V_275 ) ;
F_26 ( & V_170 -> V_274 , V_89 ) ;
F_153 ( V_170 -> V_477 ) ;
F_153 ( V_170 -> V_479 ) ;
}
static void F_154 ( struct V_18 * V_19 ,
struct V_480 * V_481 ,
struct V_177 * V_178 )
{
V_481 -> V_55 = V_19 -> V_55 ;
V_481 -> V_482 = true ;
V_481 -> V_483 = true ;
V_481 -> V_484 = true ;
V_481 -> V_485 = true ;
V_481 -> V_486 = false ;
V_481 -> V_137 = V_487 ;
V_481 -> V_488 = F_155 ( V_489 ) ;
V_481 -> V_490 = F_155 ( V_491 ) ;
V_481 -> V_492 = V_493 ;
V_481 -> V_494 = V_495 ;
V_481 -> V_198 = V_19 -> V_134 . V_198 ;
V_481 -> V_314 = V_19 -> V_134 . V_314 ;
V_481 -> V_496 = F_155 ( V_19 -> V_134 . V_151 ) ;
V_481 -> V_203 = F_155 ( V_19 -> V_134 . V_203 ) ;
V_481 -> V_154 = F_155 ( V_19 -> V_134 . V_154 ) ;
V_481 -> V_497 = F_155 ( V_19 -> V_134 . V_151 ) ;
V_481 -> V_498 = F_155 ( V_19 -> V_134 . V_151 ) ;
V_481 -> V_499 = F_155 ( 2 * V_19 -> V_134 . V_196 ) ;
V_481 -> V_500 = F_155 ( V_19 -> V_134 . V_154 ) ;
V_481 -> V_501 = F_155 ( V_19 -> V_134 . V_151 ) ;
V_481 -> V_502 = F_155 ( V_19 -> V_134 . V_204 ) ;
V_481 -> V_165 = F_155 ( V_19 -> V_134 . V_165 <<
V_19 -> V_134 . V_314 ) ;
V_481 -> V_503 = 0 ;
V_481 -> V_504 = F_155 ( ( ( T_3 ) V_19 -> V_134 . V_196 ) ) ;
if ( V_19 -> V_56 < V_111 ) {
V_481 -> V_505 = true ;
V_481 -> V_506 = F_156 ( V_19 -> V_56 ) ;
}
if ( V_19 -> V_55 ) {
V_481 -> V_507 = F_156 ( V_19 -> V_38 ) ;
V_481 -> V_321 = F_156 ( V_19 -> V_39 ) ;
V_481 -> V_508 = F_155 ( V_19 -> V_43 [ 0 ] ) ;
V_481 -> V_509 = F_155 ( V_19 -> V_42 [ 0 ] ) ;
V_481 -> V_510 =
F_156 ( ( T_2 ) F_109 (
V_178 -> V_84 ,
& V_481 -> V_508 ,
true ,
NULL ,
V_400 ) ) ;
} else {
V_481 -> V_507 = F_156 ( V_19 -> V_38 ) ;
V_481 -> V_321 = F_156 ( V_19 -> V_39 ) ;
V_481 -> V_511 = F_155 ( V_19 -> V_43 [ 0 ] ) ;
V_481 -> V_512 = F_155 ( V_19 -> V_43 [ 1 ] ) ;
V_481 -> V_513 = F_155 ( V_19 -> V_43 [ 2 ] ) ;
V_481 -> V_508 = F_155 ( V_19 -> V_43 [ 3 ] ) ;
V_481 -> V_514 = F_155 ( V_19 -> V_42 [ 0 ] ) ;
V_481 -> V_515 = F_155 ( V_19 -> V_42 [ 1 ] ) ;
V_481 -> V_516 = F_155 ( V_19 -> V_42 [ 2 ] ) ;
V_481 -> V_509 = F_155 ( V_19 -> V_42 [ 3 ] ) ;
V_481 -> V_510 =
F_156 ( ( T_2 ) F_109 (
V_178 -> V_84 ,
& V_481 -> V_511 ,
false ,
NULL ,
V_400 ) ) ;
}
}
static void F_157 ( struct V_177 * V_178 ,
struct V_18 * V_19 )
{
struct V_480 V_481 ;
struct V_517 * V_518 ;
struct V_519 * V_520 ;
struct V_83 * V_84 = V_178 -> V_84 ;
struct V_298 * V_81 = & V_178 -> V_84 -> V_337 ;
memset ( & V_481 , 0x00 , sizeof( struct V_480 ) ) ;
V_518 = & V_178 -> V_518 ;
V_520 = & V_178 -> V_520 ;
V_520 -> V_481 = & V_481 ;
V_520 -> V_521 = V_178 -> V_522 -> V_523 . V_524 . V_525 ;
V_520 -> V_526 = V_178 -> V_527 -> V_523 . V_524 . V_525 ;
V_518 -> V_25 = V_19 -> V_25 ;
V_518 -> V_24 = F_4 ( V_19 -> V_24 ) ;
if ( V_518 -> V_25 == 1 )
V_518 -> V_25 = 2 ;
V_518 -> V_528 = true ;
V_518 -> V_529 = 1 ;
V_518 -> V_530 = 1 ;
V_518 -> V_531 = V_178 -> V_532 -> V_533 . V_531 ;
V_520 -> V_534 = true ;
V_520 -> V_535 = true ;
V_520 -> V_536 = true ;
V_520 -> V_57 = V_19 -> V_57 ;
F_154 ( V_19 , & V_481 , V_178 ) ;
if ( V_19 -> V_255 ) {
V_518 -> V_255 = true ;
V_518 -> V_537 = ( V_481 . V_496 &
V_538 ) + V_19 -> V_539 ;
}
V_19 -> V_173 = V_303 ;
V_481 . V_494 = V_495 ;
V_481 . V_540 = V_84 -> V_541 ;
V_481 . V_131 = V_19 -> V_131 ;
V_81 -> V_542 -> V_543 ( & V_178 -> V_544 , ( V_545 * ) ( V_178 -> V_546 . V_110 ) , V_520 ) ;
V_520 -> V_534 = false ;
V_520 -> V_535 = false ;
V_520 -> V_536 = false ;
}
void F_52 ( struct V_177 * V_178 )
{
struct V_547 * V_548 ;
struct V_83 * V_84 = V_178 -> V_84 ;
struct V_259 * V_170 = & V_84 -> V_170 ;
unsigned long V_89 ;
V_548 = F_18 ( sizeof( * V_548 ) , V_80 ) ;
if ( ! V_548 )
return;
F_25 ( & V_84 -> V_549 , V_89 ) ;
if ( ! V_84 -> V_550 [ V_178 -> V_423 . V_551 ] ) {
F_26 ( & V_84 -> V_549 , V_89 ) ;
F_19 ( & V_84 -> V_337 , V_82 ,
L_58 ,
V_172 , V_178 -> V_423 . V_551 ) ;
F_22 ( V_548 ) ;
return;
}
F_158 ( & V_178 -> V_423 ) ;
F_26 ( & V_84 -> V_549 , V_89 ) ;
V_548 -> V_178 = V_178 ;
F_159 ( & V_548 -> V_548 , V_552 ) ;
F_160 ( V_170 -> V_479 , & V_548 -> V_548 ) ;
return;
}
static void F_161 ( struct V_177 * V_178 )
{
struct V_83 * V_84 ;
struct V_553 * V_554 ;
V_84 = F_162 ( V_178 -> V_423 . V_555 ) ;
if ( ! V_84 ) {
F_16 ( L_59 ) ;
return;
}
V_554 = V_84 -> V_554 ;
if ( V_178 -> V_556 ) {
V_178 -> V_556 = 0 ;
} else {
if ( V_178 -> V_557 . V_110 ) {
if ( V_178 -> V_558 )
V_554 -> V_559 . V_560 ( V_178 -> V_558 ) ;
F_163 ( V_84 -> V_337 . V_561 , & V_178 -> V_557 ) ;
}
}
if ( V_178 -> V_19 ) {
F_19 ( & V_84 -> V_337 , V_82 , L_60 , V_172 ) ;
F_145 ( V_178 -> V_19 ) ;
}
}
static void F_164 ( struct V_177 * V_178 )
{
struct V_58 * V_59 ;
struct V_83 * V_84 ;
struct V_562 * V_563 = & V_178 -> V_544 ;
T_2 V_564 ;
T_1 V_565 ;
T_1 V_566 ;
int V_567 = 0 ;
int V_568 = 0 ;
int V_569 = 0 ;
int V_570 = 0 ;
struct V_571 V_572 ;
unsigned long V_89 ;
int V_261 ;
if ( ! V_178 ) {
F_16 ( L_61 ) ;
return;
}
F_25 ( & V_178 -> V_282 , V_89 ) ;
V_59 = V_178 -> V_59 ;
if ( ! V_59 ) {
F_26 ( & V_178 -> V_282 , V_89 ) ;
return;
}
V_84 = F_162 ( V_178 -> V_423 . V_555 ) ;
V_565 = V_178 -> V_283 ;
V_566 = V_178 -> V_289 ;
V_564 = V_178 -> V_287 ;
if ( V_563 -> V_573 ) {
V_568 = 1 ;
V_569 = 1 ;
V_178 -> V_59 = NULL ;
F_165 ( V_563 ) ;
if ( ! V_178 -> V_574 ) {
V_178 -> V_574 = 1 ;
V_570 = 1 ;
}
} else if ( ( V_565 == V_575 ) ||
( ( V_566 == V_576 ) &&
( V_564 == V_577 ) ) ) {
V_568 = 1 ;
if ( V_564 == V_577 )
V_567 = - V_179 ;
}
if ( ( ( V_565 == V_284 ) ||
( V_565 == V_578 ) ||
( V_564 == V_579 ) ||
( V_564 == V_577 ) ) ) {
V_569 = 1 ;
V_178 -> V_59 = NULL ;
if ( ! V_178 -> V_574 ) {
V_178 -> V_574 = 1 ;
V_570 = 1 ;
}
}
F_26 ( & V_178 -> V_282 , V_89 ) ;
if ( V_570 && ! V_178 -> V_580 ) {
F_166 ( V_84 , V_178 ) ;
if ( V_563 -> V_573 && V_178 -> V_423 . V_77 ) {
V_572 . V_555 = V_178 -> V_423 . V_555 ;
V_572 . V_29 = ( V_563 -> V_581 == V_582 ) ?
V_583 : V_584 ;
V_572 . V_585 . V_563 = & V_178 -> V_423 ;
V_178 -> V_423 . V_77 ( & V_572 , V_178 -> V_423 . V_586 ) ;
}
}
if ( V_59 && V_59 -> V_77 ) {
if ( V_568 ) {
V_261 = F_15 ( NULL ,
V_59 ,
V_75 ,
V_567 ) ;
if ( V_261 )
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_62 ,
V_172 , V_59 ) ;
}
if ( V_569 ) {
F_161 ( V_178 ) ;
V_59 -> V_72 = V_178 ;
V_261 = F_15 ( NULL , V_59 , V_76 , 0 ) ;
if ( V_261 )
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_63 ,
V_172 , V_59 ) ;
V_59 -> V_180 ( V_59 ) ;
}
}
}
static void V_552 ( struct V_587 * V_548 )
{
struct V_547 * V_588 = F_56 ( V_548 , struct V_547 , V_548 ) ;
struct V_177 * V_178 = V_588 -> V_178 ;
F_22 ( V_588 ) ;
F_164 ( V_178 ) ;
F_128 ( & V_178 -> V_423 ) ;
}
int F_167 ( struct V_58 * V_59 , struct V_589 * V_590 )
{
struct V_591 * V_423 ;
struct V_177 * V_178 ;
struct V_83 * V_84 ;
struct V_298 * V_81 ;
struct V_18 * V_19 ;
struct V_592 V_593 ;
int V_431 ;
struct V_594 * V_595 ;
struct V_596 * V_532 ;
T_2 V_597 = 0 ;
struct V_91 V_598 ;
enum V_330 V_70 ;
V_545 V_599 ;
memset ( & V_593 , 0 , sizeof( V_593 ) ) ;
V_423 = F_168 ( V_59 -> V_555 , V_590 -> V_600 ) ;
if ( ! V_423 )
return - V_272 ;
V_178 = F_169 ( V_423 ) ;
V_84 = V_178 -> V_84 ;
V_81 = & V_84 -> V_337 ;
V_19 = (struct V_18 * ) V_59 -> V_72 ;
if ( ( (struct V_30 * ) & V_59 -> V_32 ) -> V_35 == V_36 ) {
V_19 -> V_55 = true ;
V_19 -> V_56 = F_81 ( V_19 -> V_42 ) ;
} else {
V_19 -> V_55 = false ;
F_73 ( V_19 -> V_42 , & V_19 -> V_56 , NULL ) ;
}
F_19 ( V_19 -> V_81 ,
V_82 ,
L_64 ,
V_19 -> V_56 ) ;
if ( V_19 -> V_173 == V_376 ) {
if ( V_19 -> V_375 )
F_36 ( V_19 -> V_375 ) ;
F_36 ( V_19 ) ;
return - V_272 ;
}
V_431 = F_131 ( 1 , & V_19 -> V_431 ) ;
if ( V_431 == V_466 ) {
F_36 ( V_19 ) ;
return - V_179 ;
}
V_19 -> V_170 -> V_601 ++ ;
V_178 -> V_19 = ( void * ) V_19 ;
V_19 -> V_178 = V_178 ;
V_597 = V_590 -> V_64 + V_602 ;
V_70 = F_170 ( V_81 -> V_561 , & V_178 -> V_557 , V_597 , 1 ) ;
if ( V_70 )
return - V_242 ;
V_19 -> V_65 . V_66 = V_590 -> V_64 ;
V_598 . V_167 = V_178 -> V_557 . V_110 ;
V_598 . V_66 = F_43 ( V_19 , & V_598 , V_213 ) ;
memcpy ( V_598 . V_167 + V_598 . V_66 , V_590 -> V_62 ,
V_590 -> V_64 ) ;
if ( ( V_19 -> V_55 &&
! F_118 ( V_19 -> V_42 [ 0 ] , V_19 -> V_43 [ 0 ] ) ) ||
( ! V_19 -> V_55 &&
! F_120 ( V_19 -> V_42 , V_19 -> V_43 ) ) ) {
V_532 = V_178 -> V_532 ;
V_599 = ( V_603 ) V_178 -> V_557 . V_110 ;
V_595 = F_171 ( & V_532 -> V_604 ,
V_178 -> V_557 . V_605 ,
V_597 ,
V_606 ,
& V_599 ) ;
if ( F_103 ( V_595 ) ) {
F_163 ( V_81 -> V_561 , & V_178 -> V_557 ) ;
return - V_242 ;
}
V_595 -> V_607 = & V_532 -> V_604 ;
V_595 -> V_555 = V_532 -> V_604 . V_555 ;
V_178 -> V_558 = V_595 ;
if ( V_178 -> V_608 )
V_178 -> V_544 . V_609 . V_610 = F_172 ( V_178 -> V_608 ) ;
V_81 -> V_542 -> V_611 ( & V_178 -> V_544 ,
V_178 -> V_557 . V_110 ,
( V_598 . V_66 + V_590 -> V_64 ) ,
V_595 -> V_612 ) ;
} else {
if ( V_178 -> V_608 )
V_178 -> V_544 . V_609 . V_610 = F_172 ( V_178 -> V_608 ) ;
V_81 -> V_542 -> V_611 ( & V_178 -> V_544 , NULL , 0 , 0 ) ;
}
if ( V_178 -> V_608 )
F_173 ( V_178 -> V_608 ) ;
V_178 -> V_59 = V_59 ;
V_19 -> V_59 = V_59 ;
V_59 -> V_72 = ( void * ) V_178 ;
V_178 -> V_556 = 0 ;
V_19 -> V_539 = V_598 . V_66 + V_590 -> V_64 ;
F_157 ( V_178 , V_19 ) ;
V_59 -> V_467 ( V_59 ) ;
F_158 ( & V_178 -> V_423 ) ;
F_15 ( V_19 , V_59 , V_74 , 0 ) ;
V_593 . V_613 = V_576 ;
V_19 -> V_338 = false ;
F_174 ( & V_178 -> V_423 , & V_593 , V_614 , NULL ) ;
if ( V_19 -> V_375 ) {
V_19 -> V_375 -> V_65 . V_66 = V_590 -> V_64 ;
memcpy ( V_19 -> V_375 -> V_63 ,
V_590 -> V_62 ,
V_590 -> V_64 ) ;
F_17 ( V_19 -> V_375 , V_442 ) ;
}
V_19 -> V_373 = 1 ;
if ( V_19 -> V_420 ) {
if ( ! V_19 -> V_363 )
F_16 ( L_65 ) ;
F_23 ( & V_19 -> V_363 -> V_380 ) ;
V_19 -> V_420 = 0 ;
}
return 0 ;
}
int F_175 ( struct V_58 * V_59 , const void * V_65 , T_1 V_615 )
{
struct V_83 * V_84 ;
struct V_18 * V_19 ;
struct V_18 * V_371 ;
V_19 = (struct V_18 * ) V_59 -> V_72 ;
V_371 = V_19 -> V_375 ;
V_19 -> V_59 = V_59 ;
V_19 -> V_65 . V_66 = V_615 ;
V_84 = F_162 ( V_59 -> V_555 ) ;
if ( ! V_84 )
return - V_272 ;
V_19 -> V_170 -> V_616 ++ ;
if ( V_615 + sizeof( struct V_219 ) > V_251 )
return - V_272 ;
if ( V_371 ) {
memcpy ( & V_371 -> V_63 , V_65 , V_615 ) ;
V_371 -> V_65 . V_66 = V_615 ;
}
return F_144 ( V_19 , V_65 , V_615 ) ;
}
int F_176 ( struct V_58 * V_59 , struct V_589 * V_590 )
{
struct V_591 * V_423 ;
struct V_177 * V_178 ;
struct V_83 * V_84 ;
struct V_18 * V_19 ;
struct V_53 V_54 ;
struct V_30 * V_31 ;
struct V_30 * V_33 ;
struct V_44 * V_45 ;
struct V_44 * V_46 ;
bool V_338 = false ;
int V_421 = 0 ;
int V_366 = 0 ;
enum V_330 V_70 ;
V_423 = F_168 ( V_59 -> V_555 , V_590 -> V_600 ) ;
if ( ! V_423 )
return - V_272 ;
V_178 = F_169 ( V_423 ) ;
if ( ! V_178 )
return - V_272 ;
V_84 = F_162 ( V_178 -> V_423 . V_555 ) ;
if ( ! V_84 )
return - V_272 ;
V_31 = (struct V_30 * ) & V_59 -> V_60 ;
V_33 = (struct V_30 * ) & V_59 -> V_61 ;
V_45 = (struct V_44 * ) & V_59 -> V_60 ;
V_46 = (struct V_44 * ) & V_59 -> V_61 ;
if ( ! ( V_31 -> V_37 ) || ! ( V_33 -> V_37 ) )
return - V_272 ;
V_178 -> V_556 = 1 ;
V_178 -> V_59 = NULL ;
V_59 -> V_72 = V_178 ;
if ( V_59 -> V_34 . V_617 == V_36 ) {
V_54 . V_55 = true ;
memset ( V_54 . V_42 , 0 , sizeof( V_54 . V_42 ) ) ;
memset ( V_54 . V_43 , 0 , sizeof( V_54 . V_43 ) ) ;
V_54 . V_42 [ 0 ] = F_7 ( V_31 -> V_40 . V_41 ) ;
V_54 . V_43 [ 0 ] = F_7 ( V_33 -> V_40 . V_41 ) ;
V_54 . V_38 = F_39 ( V_31 -> V_37 ) ;
V_54 . V_39 = F_39 ( V_33 -> V_37 ) ;
V_54 . V_56 = F_81 ( V_54 . V_42 ) ;
} else {
V_54 . V_55 = false ;
F_6 ( V_54 . V_42 ,
V_45 -> V_50 . V_51 . V_52 ) ;
F_6 ( V_54 . V_43 ,
V_46 -> V_50 . V_51 . V_52 ) ;
V_54 . V_38 = F_39 ( V_45 -> V_49 ) ;
V_54 . V_39 = F_39 ( V_46 -> V_49 ) ;
F_73 ( V_54 . V_42 , & V_54 . V_56 , NULL ) ;
}
V_54 . V_59 = V_59 ;
V_54 . V_131 = V_59 -> V_131 ;
V_54 . V_57 = F_124 ( V_59 -> V_131 ) ;
F_19 ( & V_84 -> V_337 , V_413 , L_66 ,
V_172 , V_59 -> V_131 , V_54 . V_57 ) ;
if ( ( V_54 . V_55 && ( V_31 -> V_40 . V_41 != V_33 -> V_40 . V_41 ) ) ||
( ! V_54 . V_55 && memcmp ( V_45 -> V_50 . V_51 . V_52 ,
V_46 -> V_50 . V_51 . V_52 ,
sizeof( V_45 -> V_50 . V_51 . V_52 ) ) ) ) {
V_70 = F_72 ( V_84 ,
& V_54 ,
V_422 ,
V_358 ,
NULL ,
true ) ;
if ( V_70 )
return - V_272 ;
V_338 = true ;
}
V_70 = F_97 ( V_84 , V_54 . V_38 , V_618 ) ;
if ( V_70 ) {
F_72 ( V_84 ,
& V_54 ,
V_422 ,
V_340 ,
NULL ,
false ) ;
return - V_272 ;
}
V_421 = 1 ;
V_59 -> V_467 ( V_59 ) ;
V_19 = F_142 ( & V_84 -> V_170 , V_84 ,
V_590 -> V_64 ,
( void * ) V_590 -> V_62 ,
& V_54 ) ;
if ( F_103 ( V_19 ) ) {
V_366 = F_177 ( V_19 ) ;
goto V_619;
}
F_5 ( V_19 , ( T_2 ) V_590 -> V_67 , ( T_2 ) V_590 -> V_68 ) ;
if ( V_19 -> V_232 == V_234 &&
! V_19 -> V_25 )
V_19 -> V_25 = 1 ;
V_19 -> V_421 = V_421 ;
V_19 -> V_338 = V_338 ;
V_178 -> V_19 = V_19 ;
V_19 -> V_178 = V_178 ;
V_178 -> V_59 = V_59 ;
F_158 ( & V_178 -> V_423 ) ;
if ( V_19 -> V_173 != V_303 ) {
V_19 -> V_173 = V_425 ;
V_366 = F_60 ( V_19 , 0 ) ;
if ( V_366 ) {
F_36 ( V_19 ) ;
goto V_619;
}
}
F_19 ( V_19 -> V_81 ,
V_82 ,
L_67 ,
V_19 -> V_39 ,
V_19 ,
V_19 -> V_59 ) ;
return 0 ;
V_619:
if ( V_54 . V_55 )
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_68 ,
V_54 . V_43 ) ;
else
F_19 ( & V_84 -> V_337 ,
V_82 ,
L_69 ,
V_54 . V_43 ) ;
if ( V_338 )
F_72 ( V_84 ,
& V_54 ,
V_422 ,
V_340 ,
NULL ,
false ) ;
if ( V_421 && ! F_68 ( & V_84 -> V_170 ,
V_54 . V_38 ) )
F_97 ( V_84 ,
V_54 . V_38 ,
V_378 ) ;
V_59 -> V_180 ( V_59 ) ;
V_84 -> V_170 . V_171 ++ ;
return V_366 ;
}
int F_178 ( struct V_58 * V_59 , int V_444 )
{
struct V_83 * V_84 ;
struct V_319 * V_620 ;
struct V_53 V_54 ;
enum V_330 V_261 ;
struct V_30 * V_31 ;
struct V_44 * V_45 ;
bool V_621 = false ;
V_84 = F_162 ( V_59 -> V_555 ) ;
if ( ! V_84 )
return - V_272 ;
V_31 = (struct V_30 * ) & V_59 -> V_60 ;
V_45 = (struct V_44 * ) & V_59 -> V_60 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
if ( V_31 -> V_35 == V_36 ) {
V_54 . V_55 = true ;
V_54 . V_42 [ 0 ] = F_7 ( V_31 -> V_40 . V_41 ) ;
V_54 . V_38 = F_39 ( V_31 -> V_37 ) ;
if ( V_31 -> V_40 . V_41 != V_622 )
V_54 . V_56 = F_81 ( V_54 . V_42 ) ;
else
V_621 = true ;
} else {
V_54 . V_55 = false ;
F_6 ( V_54 . V_42 ,
V_45 -> V_50 . V_51 . V_52 ) ;
V_54 . V_38 = F_39 ( V_45 -> V_49 ) ;
if ( F_114 ( & V_45 -> V_50 ) != V_623 )
F_73 ( V_54 . V_42 ,
& V_54 . V_56 ,
NULL ) ;
else
V_621 = true ;
}
V_54 . V_444 = V_444 ;
V_54 . V_59 = V_59 ;
V_620 = F_141 ( & V_84 -> V_170 , V_84 , & V_54 ) ;
if ( ! V_620 ) {
F_16 ( L_70 ) ;
return - V_242 ;
}
V_59 -> V_72 = V_620 ;
V_620 -> V_131 = V_59 -> V_131 ;
V_620 -> V_57 = F_124 ( V_59 -> V_131 ) ;
V_54 . V_57 = V_620 -> V_57 ;
if ( ! V_620 -> V_458 ) {
if ( V_621 ) {
if ( V_54 . V_55 )
V_261 = F_90 ( V_84 ,
& V_54 ,
V_620 ) ;
else
V_261 = F_84 ( V_84 ,
& V_54 ,
V_620 ) ;
if ( V_261 )
goto error;
V_261 = F_97 ( V_84 ,
V_54 . V_38 ,
V_618 ) ;
if ( V_261 )
goto error;
} else {
V_261 = F_72 ( V_84 ,
& V_54 ,
V_339 ,
V_358 ,
NULL ,
true ) ;
if ( V_261 )
goto error;
V_620 -> V_338 = true ;
V_261 = F_97 ( V_84 ,
V_54 . V_38 ,
V_618 ) ;
if ( V_261 )
goto error;
}
}
V_59 -> V_467 ( V_59 ) ;
V_620 -> V_170 -> V_624 ++ ;
return 0 ;
error:
F_100 ( & V_84 -> V_170 , ( void * ) V_620 , false ) ;
return - V_272 ;
}
int F_179 ( struct V_58 * V_59 )
{
struct V_83 * V_84 ;
V_84 = F_162 ( V_59 -> V_555 ) ;
if ( V_59 -> V_72 )
F_100 ( & V_84 -> V_170 , V_59 -> V_72 , true ) ;
else
F_16 ( L_71 ) ;
V_59 -> V_180 ( V_59 ) ;
return 0 ;
}
static void F_180 ( struct V_78 * V_29 )
{
struct V_177 * V_178 ;
struct V_83 * V_84 ;
struct V_18 * V_19 ;
struct V_298 * V_81 ;
struct V_592 V_593 ;
struct V_58 * V_59 ;
int V_70 ;
bool V_625 ;
V_19 = V_29 -> V_19 ;
V_59 = V_19 -> V_59 ;
V_178 = (struct V_177 * ) V_59 -> V_72 ;
V_84 = F_162 ( V_178 -> V_423 . V_555 ) ;
V_81 = & V_84 -> V_337 ;
if ( V_178 -> V_580 ) {
V_70 = - V_626 ;
goto error;
}
F_157 ( V_178 , V_19 ) ;
V_625 = ( V_19 -> V_232 == V_234 ) ;
if ( V_178 -> V_608 )
V_178 -> V_544 . V_609 . V_610 = F_172 ( V_178 -> V_608 ) ;
V_81 -> V_542 -> V_627 ( & V_178 -> V_544 , V_625 ) ;
if ( V_178 -> V_608 )
F_173 ( V_178 -> V_608 ) ;
V_70 = F_15 ( V_19 , V_59 , V_73 , 0 ) ;
if ( V_70 )
F_16 ( L_72 ) ;
memset ( & V_593 , 0 , sizeof( V_593 ) ) ;
V_593 . V_613 = V_576 ;
V_19 -> V_338 = false ;
F_174 ( & V_178 -> V_423 , & V_593 , V_614 , NULL ) ;
V_19 -> V_373 = 1 ;
if ( V_19 -> V_420 ) {
if ( ! V_19 -> V_363 )
F_16 ( L_73 ) ;
F_23 ( & V_19 -> V_363 -> V_380 ) ;
V_19 -> V_420 = 0 ;
}
return;
error:
V_178 -> V_59 = NULL ;
V_59 -> V_72 = NULL ;
F_15 ( V_29 -> V_19 ,
V_59 ,
V_73 ,
V_70 ) ;
V_59 -> V_180 ( V_59 ) ;
F_36 ( V_29 -> V_19 ) ;
}
static void F_181 ( struct V_78 * V_29 )
{
struct V_18 * V_19 = V_29 -> V_19 ;
struct V_58 * V_59 = V_19 -> V_59 ;
struct V_177 * V_178 ;
if ( ! V_59 )
return;
V_178 = V_59 -> V_72 ;
if ( ! V_178 )
return;
F_19 ( V_19 -> V_81 ,
V_82 ,
L_74 ,
V_29 -> V_19 , V_59 ) ;
V_178 -> V_59 = NULL ;
F_15 ( V_19 , V_19 -> V_59 , V_75 , - V_179 ) ;
F_15 ( V_19 , V_19 -> V_59 , V_76 , 0 ) ;
}
static void F_182 ( struct V_587 * V_548 )
{
struct V_78 * V_29 = F_56 ( V_548 ,
struct V_78 ,
V_628 ) ;
struct V_18 * V_19 ;
if ( ! V_29 || ! V_29 -> V_19 || ! V_29 -> V_19 -> V_170 )
return;
V_19 = V_29 -> V_19 ;
switch ( V_29 -> type ) {
case V_439 :
F_15 ( V_19 ,
V_19 -> V_59 ,
V_71 ,
0 ) ;
break;
case V_629 :
F_181 ( V_29 ) ;
break;
case V_442 :
if ( ! V_29 -> V_19 -> V_59 ||
( V_29 -> V_19 -> V_173 != V_303 ) )
break;
F_180 ( V_29 ) ;
break;
case V_441 :
if ( ! V_29 -> V_19 -> V_59 ||
( V_19 -> V_173 == V_303 ) )
break;
F_15 ( V_19 ,
V_19 -> V_59 ,
V_73 ,
- V_464 ) ;
break;
case V_175 :
if ( ! V_29 -> V_19 -> V_59 ||
( V_29 -> V_19 -> V_173 == V_303 ) )
break;
F_37 ( V_29 ) ;
break;
default:
F_16 ( L_75 , V_29 -> type ) ;
break;
}
V_29 -> V_54 . V_59 -> V_180 ( V_29 -> V_54 . V_59 ) ;
F_36 ( V_29 -> V_19 ) ;
F_22 ( V_29 ) ;
}
static void F_20 ( struct V_78 * V_29 )
{
F_34 ( & V_29 -> V_19 -> V_88 ) ;
V_29 -> V_54 . V_59 -> V_467 ( V_29 -> V_54 . V_59 ) ;
F_159 ( & V_29 -> V_628 , F_182 ) ;
F_160 ( V_29 -> V_19 -> V_170 -> V_477 , & V_29 -> V_628 ) ;
}
static void F_183 ( struct V_83 * V_84 ,
struct V_319 * V_630 ,
struct V_53 * V_370 ,
T_3 * V_631 , bool V_55 , bool V_632 )
{
struct V_294 * V_336 = & V_630 -> V_336 ;
struct V_319 * V_332 ;
struct V_294 * V_334 , * V_335 ;
enum V_330 V_261 ;
bool V_633 = false ;
enum V_634 V_635 =
V_632 ? V_358 : V_340 ;
F_55 (pos, tpos, child_listen_list) {
V_332 =
F_70 ( V_334 ,
struct V_319 ,
V_336 ) ;
if ( ! memcmp ( V_332 -> V_42 , V_631 , V_55 ? 4 : 16 ) )
goto V_636;
}
if ( ! V_632 )
return;
V_332 = F_18 ( sizeof( * V_332 ) , V_80 ) ;
if ( ! V_332 )
return;
V_633 = true ;
memcpy ( V_332 , V_630 , sizeof( * V_332 ) ) ;
memcpy ( V_332 -> V_42 , V_631 , V_55 ? 4 : 16 ) ;
V_636:
memcpy ( V_370 -> V_42 ,
V_332 -> V_42 ,
sizeof( V_370 -> V_42 ) ) ;
V_370 -> V_56 = V_332 -> V_56 ;
V_261 = F_72 ( V_84 , V_370 ,
V_339 ,
V_635 ,
NULL , false ) ;
if ( ! V_261 ) {
V_332 -> V_338 = V_632 ;
if ( V_633 )
F_57 ( & V_332 -> V_336 ,
& V_630 -> V_336 ) ;
} else if ( V_633 ) {
F_22 ( V_332 ) ;
}
}
void F_184 ( struct V_83 * V_84 )
{
struct V_259 * V_170 = & V_84 -> V_170 ;
struct V_294 * V_295 ;
struct V_294 * V_296 ;
struct V_18 * V_19 ;
unsigned long V_89 ;
struct V_294 V_637 ;
struct V_592 V_593 ;
F_54 ( & V_637 ) ;
F_25 ( & V_170 -> V_274 , V_89 ) ;
F_55 (list_node, list_core_temp, &cm_core->connected_nodes) {
V_19 = F_56 ( V_296 , struct V_18 , V_300 ) ;
F_34 ( & V_19 -> V_88 ) ;
F_57 ( & V_19 -> V_638 , & V_637 ) ;
}
F_26 ( & V_170 -> V_274 , V_89 ) ;
F_55 (list_node, list_core_temp, &connected_list) {
V_19 = F_56 ( V_296 , struct V_18 , V_638 ) ;
V_593 . V_613 = V_290 ;
F_174 ( & V_19 -> V_178 -> V_423 , & V_593 , V_614 , NULL ) ;
F_36 ( V_19 ) ;
}
}
void F_185 ( struct V_83 * V_84 , struct V_343 * V_351 ,
T_3 * V_631 , bool V_55 , bool V_632 )
{
struct V_259 * V_170 = & V_84 -> V_170 ;
unsigned long V_89 ;
struct V_319 * V_324 ;
static const T_3 V_325 [ 4 ] = { 0 , 0 , 0 , 0 } ;
struct V_53 V_370 ;
T_2 V_56 = F_79 ( V_351 ) ;
enum V_330 V_261 ;
enum V_634 V_635 =
V_632 ? V_358 : V_340 ;
F_25 ( & V_170 -> V_328 , V_89 ) ;
F_64 (listen_node, &cm_core->listen_nodes, list) {
if ( V_56 == V_324 -> V_56 &&
( ! memcmp ( V_324 -> V_42 , V_631 , V_55 ? 4 : 16 ) ||
! memcmp ( V_324 -> V_42 , V_325 , V_55 ? 4 : 16 ) ) ) {
memcpy ( V_370 . V_42 , V_324 -> V_42 ,
sizeof( V_370 . V_42 ) ) ;
V_370 . V_38 = V_324 -> V_38 ;
V_370 . V_55 = V_324 -> V_55 ;
V_370 . V_56 = V_324 -> V_56 ;
V_370 . V_57 = V_324 -> V_57 ;
if ( ! F_98 ( & V_324 -> V_336 ) ) {
F_183 ( V_84 ,
V_324 ,
& V_370 ,
V_631 , V_55 , V_632 ) ;
} else if ( memcmp ( V_324 -> V_42 , V_325 ,
V_55 ? 4 : 16 ) ) {
V_261 = F_72 ( V_84 ,
& V_370 ,
V_339 ,
V_635 ,
NULL ,
false ) ;
if ( ! V_261 )
V_324 -> V_338 = V_632 ;
}
}
}
F_26 ( & V_170 -> V_328 , V_89 ) ;
if ( ! V_632 )
F_184 ( V_84 ) ;
}
