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
}
static inline void F_14 ( struct V_18 * V_19 ,
struct V_57 * V_58 ,
struct V_28 * V_29 )
{
memcpy ( & V_29 -> V_32 , & V_58 -> V_59 ,
sizeof( V_29 -> V_32 ) ) ;
memcpy ( & V_29 -> V_34 , & V_58 -> V_60 ,
sizeof( V_29 -> V_34 ) ) ;
if ( V_19 ) {
V_29 -> V_61 = ( void * ) V_19 -> V_62 ;
V_29 -> V_63 = ( T_1 ) V_19 -> V_64 . V_65 ;
V_29 -> V_66 = V_19 -> V_24 ;
V_29 -> V_67 = V_19 -> V_25 ;
}
}
static int F_15 ( struct V_18 * V_19 ,
struct V_57 * V_58 ,
enum V_68 type ,
int V_69 )
{
struct V_28 V_29 ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_29 . V_29 = type ;
V_29 . V_69 = V_69 ;
switch ( type ) {
case V_70 :
if ( V_19 -> V_55 )
F_10 ( V_19 , & V_29 ) ;
else
F_12 ( V_19 , & V_29 ) ;
V_29 . V_71 = ( void * ) V_19 ;
V_29 . V_61 = ( void * ) V_19 -> V_62 ;
V_29 . V_63 = ( T_1 ) V_19 -> V_64 . V_65 ;
break;
case V_72 :
F_14 ( V_19 , V_58 , & V_29 ) ;
break;
case V_73 :
V_29 . V_66 = V_19 -> V_24 ;
V_29 . V_67 = V_19 -> V_25 ;
break;
case V_74 :
break;
case V_75 :
break;
default:
F_16 ( L_1 , type ) ;
return - 1 ;
}
return V_58 -> V_76 ( V_58 , & V_29 ) ;
}
static struct V_77 * F_17 ( struct V_18 * V_19 ,
enum V_78 type )
{
struct V_77 * V_29 ;
if ( ! V_19 -> V_58 )
return NULL ;
V_29 = F_18 ( sizeof( * V_29 ) , V_79 ) ;
if ( ! V_29 )
return NULL ;
V_29 -> type = type ;
V_29 -> V_19 = V_19 ;
memcpy ( V_29 -> V_54 . V_43 , V_19 -> V_43 , sizeof( V_29 -> V_54 . V_43 ) ) ;
memcpy ( V_29 -> V_54 . V_42 , V_19 -> V_42 , sizeof( V_29 -> V_54 . V_42 ) ) ;
V_29 -> V_54 . V_39 = V_19 -> V_39 ;
V_29 -> V_54 . V_38 = V_19 -> V_38 ;
V_29 -> V_54 . V_58 = V_19 -> V_58 ;
F_19 ( V_19 -> V_2 ,
V_80 ,
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
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_81 * V_82 ;
V_82 = V_19 -> V_82 ;
if ( V_82 ) {
V_19 -> V_82 = NULL ;
F_1 ( V_2 , ( void * ) V_82 -> V_83 ) ;
F_22 ( V_82 ) ;
F_23 ( & V_19 -> V_84 ) ;
}
}
static void F_24 ( struct V_18 * V_19 )
{
unsigned long V_85 ;
F_25 ( & V_19 -> V_86 , V_85 ) ;
F_21 ( V_19 ) ;
F_26 ( & V_19 -> V_86 , V_85 ) ;
}
static bool F_27 ( struct V_18 * V_19 )
{
if ( ( V_19 -> V_87 [ 0 ] == 0x0 ) &&
( ( ( V_19 -> V_87 [ 1 ] == 0x12 ) && ( V_19 -> V_87 [ 2 ] == 0x55 ) ) ||
( ( V_19 -> V_87 [ 1 ] == 0x07 && ( V_19 -> V_87 [ 2 ] == 0x43 ) ) ) ) )
return true ;
return false ;
}
static struct V_4 * F_28 ( struct V_18 * V_19 ,
struct V_88 * V_89 ,
struct V_88 * V_90 ,
struct V_88 * V_64 ,
T_1 V_85 )
{
struct V_4 * V_83 ;
struct V_1 * V_2 = V_19 -> V_2 ;
T_1 * V_5 ;
struct V_91 * V_92 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_97 * V_98 ;
T_2 V_99 ;
T_2 V_100 = V_101 ;
T_3 V_102 = 0 ;
T_3 V_103 = 0 ;
T_3 V_104 = 0 ;
V_83 = F_29 ( V_2 -> V_7 ) ;
if ( ! V_83 )
return NULL ;
V_5 = V_83 -> V_105 . V_106 ;
if ( V_89 )
V_102 = ( T_3 ) V_89 -> V_65 ;
if ( V_90 )
V_104 = V_90 -> V_65 ;
if ( V_64 ) {
V_103 = V_64 -> V_65 ;
if ( ! F_27 ( V_19 ) )
V_103 += V_107 ;
}
if ( V_19 -> V_56 < V_108 )
V_100 += 4 ;
if ( V_19 -> V_55 )
V_99 = sizeof( * V_94 ) + sizeof( * V_92 ) ;
else
V_99 = sizeof( * V_96 ) + sizeof( * V_92 ) ;
V_99 += V_102 + V_104 + V_103 ;
memset ( V_5 , 0x00 , V_100 + V_99 ) ;
V_83 -> V_109 = V_99 + V_100 ;
V_83 -> V_110 = V_100 ;
V_83 -> V_111 = sizeof( * V_92 ) + V_102 ;
V_83 -> V_112 = ( void * ) V_19 ;
V_98 = (struct V_97 * ) V_5 ;
V_5 += V_100 ;
if ( V_19 -> V_55 ) {
V_83 -> V_55 = true ;
V_94 = (struct V_93 * ) V_5 ;
V_5 += sizeof( * V_94 ) ;
V_92 = (struct V_91 * ) V_5 ;
V_5 += sizeof( * V_92 ) ;
F_30 ( V_98 -> V_113 , V_19 -> V_87 ) ;
F_30 ( V_98 -> V_114 , V_19 -> V_115 ) ;
if ( V_19 -> V_56 < V_108 ) {
( (struct V_116 * ) V_98 ) -> V_117 = F_11 ( V_118 ) ;
( (struct V_116 * ) V_98 ) -> V_119 = F_11 ( V_19 -> V_56 ) ;
( (struct V_116 * ) V_98 ) -> V_120 = F_11 ( V_121 ) ;
} else {
V_98 -> V_122 = F_11 ( V_121 ) ;
}
V_94 -> V_123 = V_124 ;
V_94 -> V_125 = 5 ;
V_94 -> V_126 = 0 ;
V_94 -> V_127 = F_11 ( V_99 ) ;
V_94 -> V_128 = F_11 ( ++ V_19 -> V_129 . V_130 ) ;
V_94 -> V_131 = F_11 ( 0x4000 ) ;
V_94 -> V_132 = 0x40 ;
V_94 -> V_133 = V_134 ;
V_94 -> V_135 = F_9 ( V_19 -> V_42 [ 0 ] ) ;
V_94 -> V_136 = F_9 ( V_19 -> V_43 [ 0 ] ) ;
} else {
V_83 -> V_55 = false ;
V_96 = (struct V_95 * ) V_5 ;
V_5 += sizeof( * V_96 ) ;
V_92 = (struct V_91 * ) V_5 ;
V_5 += sizeof( * V_92 ) ;
F_30 ( V_98 -> V_113 , V_19 -> V_87 ) ;
F_30 ( V_98 -> V_114 , V_19 -> V_115 ) ;
if ( V_19 -> V_56 < V_108 ) {
( (struct V_116 * ) V_98 ) -> V_117 = F_11 ( V_118 ) ;
( (struct V_116 * ) V_98 ) -> V_119 = F_11 ( V_19 -> V_56 ) ;
( (struct V_116 * ) V_98 ) -> V_120 = F_11 ( V_137 ) ;
} else {
V_98 -> V_122 = F_11 ( V_137 ) ;
}
V_96 -> V_123 = 6 ;
V_96 -> V_138 [ 0 ] = 0 ;
V_96 -> V_138 [ 1 ] = 0 ;
V_96 -> V_138 [ 2 ] = 0 ;
V_96 -> V_139 = F_11 ( V_99 - sizeof( * V_96 ) ) ;
V_96 -> V_140 = 6 ;
V_96 -> V_141 = 128 ;
F_8 ( V_96 -> V_135 . V_51 . V_52 ,
V_19 -> V_42 ) ;
F_8 ( V_96 -> V_136 . V_51 . V_52 ,
V_19 -> V_43 ) ;
}
V_92 -> V_142 = F_11 ( V_19 -> V_38 ) ;
V_92 -> V_143 = F_11 ( V_19 -> V_39 ) ;
V_92 -> V_144 = F_9 ( V_19 -> V_129 . V_145 ) ;
if ( V_85 & V_146 ) {
V_19 -> V_129 . V_147 = V_19 -> V_129 . V_148 ;
V_92 -> V_149 = F_9 ( V_19 -> V_129 . V_147 ) ;
V_92 -> V_150 = 1 ;
} else {
V_92 -> V_149 = 0 ;
}
if ( V_85 & V_151 ) {
V_19 -> V_129 . V_145 ++ ;
V_92 -> V_152 = 1 ;
} else {
V_19 -> V_129 . V_145 += V_104 + V_103 ;
}
if ( V_85 & V_153 ) {
V_19 -> V_129 . V_145 ++ ;
V_92 -> V_154 = 1 ;
}
if ( V_85 & V_155 )
V_92 -> V_156 = 1 ;
V_92 -> V_157 = ( T_2 ) ( ( sizeof( * V_92 ) + V_102 + 3 ) >> 2 ) ;
V_83 -> V_111 = V_92 -> V_157 << 2 ;
V_92 -> V_158 = F_11 ( V_19 -> V_129 . V_159 ) ;
V_92 -> V_160 = 0 ;
if ( V_102 ) {
memcpy ( V_5 , V_89 -> V_161 , V_102 ) ;
V_5 += V_102 ;
}
if ( V_104 ) {
memcpy ( V_5 , V_90 -> V_161 , V_104 ) ;
V_5 += V_104 ;
}
if ( V_64 && V_64 -> V_161 )
memcpy ( V_5 , V_64 -> V_161 , V_64 -> V_65 ) ;
F_31 ( & V_83 -> V_8 , 1 ) ;
return V_83 ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_4 * V_83 ;
int V_85 = V_155 | V_146 ;
V_83 = F_28 ( V_19 , NULL , NULL , NULL , V_85 ) ;
if ( ! V_83 ) {
F_16 ( L_3 ) ;
return - 1 ;
}
return F_33 ( V_19 , V_83 , V_162 , 0 , 1 ) ;
}
static void F_34 ( struct V_18 * V_19 , bool V_163 )
{
F_24 ( V_19 ) ;
V_19 -> V_164 -> V_165 ++ ;
if ( V_163 ) {
F_19 ( V_19 -> V_2 ,
V_80 ,
L_4 ,
V_166 ,
V_19 ,
V_19 -> V_167 ) ;
F_35 ( & V_19 -> V_84 ) ;
F_32 ( V_19 ) ;
}
V_19 -> V_167 = V_168 ;
F_17 ( V_19 , V_169 ) ;
}
static void F_36 ( struct V_18 * V_19 , bool V_163 )
{
F_24 ( V_19 ) ;
V_19 -> V_164 -> V_170 ++ ;
V_19 -> V_167 = V_168 ;
F_19 ( V_19 -> V_2 ,
V_80 ,
L_5 ,
V_166 ,
V_19 ,
V_19 -> V_167 ) ;
if ( V_163 )
F_32 ( V_19 ) ;
else
F_37 ( V_19 ) ;
}
static void F_38 ( struct V_77 * V_29 )
{
struct V_171 * V_172 ;
struct V_57 * V_58 ;
V_58 = V_29 -> V_19 -> V_58 ;
if ( ! V_58 )
return;
V_172 = V_58 -> V_71 ;
if ( ! V_172 || ! V_172 -> V_173 )
return;
V_172 -> V_58 = NULL ;
V_58 -> V_71 = NULL ;
F_15 ( V_29 -> V_19 , V_58 ,
V_72 ,
- V_174 ) ;
V_58 -> V_175 ( V_58 ) ;
F_37 ( V_29 -> V_19 ) ;
}
static int F_39 ( struct V_18 * V_19 ,
T_1 * V_176 ,
T_3 V_177 ,
T_3 V_178 )
{
T_3 V_179 ;
T_3 V_180 = 0 ;
union V_181 * V_182 ;
char V_183 = 0 ;
while ( V_180 < V_177 ) {
V_182 = (union V_181 * ) ( V_176 + V_180 ) ;
switch ( V_182 -> V_184 . V_185 ) {
case V_186 :
V_180 = V_177 ;
break;
case V_187 :
V_180 += 1 ;
continue;
case V_188 :
F_19 ( V_19 -> V_2 ,
V_80 ,
L_6 ,
V_166 ,
V_182 -> V_189 . V_190 ,
V_180 ,
V_177 ) ;
V_183 = 1 ;
if ( V_182 -> V_189 . V_190 != 4 )
return - 1 ;
V_179 = F_40 ( V_182 -> V_189 . V_191 ) ;
if ( V_179 > 0 && V_179 < V_19 -> V_129 . V_191 )
V_19 -> V_129 . V_191 = V_179 ;
break;
case V_192 :
V_19 -> V_129 . V_193 =
V_182 -> V_194 . V_195 ;
break;
default:
F_19 ( V_19 -> V_2 ,
V_80 ,
L_7 ,
V_182 -> V_184 . V_185 ) ;
break;
}
V_180 += V_182 -> V_184 . V_190 ;
}
if ( ! V_183 && V_178 )
V_19 -> V_129 . V_191 = V_196 ;
return 0 ;
}
static int F_41 ( struct V_18 * V_19 ,
struct V_91 * V_92 ,
int V_177 ,
int V_197 )
{
T_1 * V_176 = ( T_1 * ) & V_92 [ 1 ] ;
if ( V_177 ) {
if ( F_39 ( V_19 ,
V_176 ,
V_177 ,
( T_3 ) V_92 -> V_152 ) ) {
F_19 ( V_19 -> V_2 ,
V_80 ,
L_8 ,
V_166 ,
V_19 ) ;
if ( V_197 )
F_36 ( V_19 , true ) ;
else
F_34 ( V_19 , true ) ;
return - 1 ;
}
}
V_19 -> V_129 . V_198 = F_40 ( V_92 -> V_158 ) <<
V_19 -> V_129 . V_193 ;
if ( V_19 -> V_129 . V_198 > V_19 -> V_129 . V_199 )
V_19 -> V_129 . V_199 = V_19 -> V_129 . V_198 ;
return 0 ;
}
static void F_42 ( struct V_18 * V_19 ,
void * V_200 ,
T_1 V_201 )
{
struct V_202 * V_203 = (struct V_202 * ) V_200 ;
switch ( V_201 ) {
case V_204 :
memcpy ( V_203 -> V_205 , V_206 , V_207 ) ;
break;
case V_208 :
memcpy ( V_203 -> V_205 , V_209 , V_207 ) ;
break;
default:
break;
}
V_203 -> V_85 = V_210 ;
V_203 -> V_211 = V_19 -> V_212 ;
V_203 -> V_213 = F_11 ( V_19 -> V_64 . V_65 ) ;
}
static void F_43 ( struct V_18 * V_19 ,
void * V_200 ,
T_1 V_201 )
{
struct V_214 * V_203 = (struct V_214 * ) V_200 ;
struct V_215 * V_216 = & V_203 -> V_216 ;
T_2 V_217 , V_218 ;
F_42 ( V_19 , V_200 , V_201 ) ;
V_203 -> V_85 |= V_219 ;
V_203 -> V_213 += F_11 ( V_220 ) ;
if ( V_19 -> V_221 == V_222 ) {
V_217 = V_222 ;
V_218 = V_222 ;
} else {
V_217 = ( V_19 -> V_24 > V_222 ) ?
V_222 : V_19 -> V_24 ;
V_218 = ( V_19 -> V_25 > V_222 ) ?
V_222 : V_19 -> V_25 ;
}
V_217 |= V_223 ;
V_217 |= V_224 ;
switch ( V_201 ) {
case V_204 :
V_218 |= V_225 ;
V_218 |= V_226 ;
break;
case V_208 :
switch ( V_19 -> V_227 ) {
case V_228 :
V_218 |= V_225 ;
break;
case V_229 :
V_218 |= V_226 ;
break;
}
break;
default:
break;
}
V_216 -> V_217 = F_11 ( V_217 ) ;
V_216 -> V_218 = F_11 ( V_218 ) ;
}
static int F_44 ( struct V_18 * V_19 ,
struct V_88 * V_230 ,
T_1 V_201 )
{
int V_104 = 0 ;
switch ( V_19 -> V_212 ) {
case V_231 :
V_104 = sizeof( struct V_202 ) ;
F_42 ( V_19 , V_230 -> V_161 , V_201 ) ;
break;
case V_232 :
V_104 = sizeof( struct V_214 ) ;
F_43 ( V_19 , V_230 -> V_161 , V_201 ) ;
break;
default:
break;
}
return V_104 ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_4 * V_83 ;
if ( ! V_19 ) {
F_16 ( L_9 ) ;
return - 1 ;
}
V_19 -> V_233 . V_161 = & V_19 -> V_203 ;
V_19 -> V_233 . V_65 = F_44 ( V_19 ,
& V_19 -> V_233 ,
V_204 ) ;
if ( ! V_19 -> V_233 . V_65 ) {
F_16 ( L_10 , V_19 -> V_233 . V_65 ) ;
return - 1 ;
}
V_83 = F_28 ( V_19 ,
NULL ,
& V_19 -> V_233 ,
& V_19 -> V_64 ,
V_146 ) ;
if ( ! V_83 ) {
F_16 ( L_11 ) ;
return - 1 ;
}
return F_33 ( V_19 , V_83 , V_162 , 1 , 0 ) ;
}
static int F_46 ( struct V_18 * V_19 ,
const void * V_64 ,
T_1 V_234 )
{
struct V_4 * V_83 ;
struct V_88 V_235 ;
V_19 -> V_233 . V_161 = & V_19 -> V_203 ;
V_19 -> V_233 . V_65 = F_44 ( V_19 ,
& V_19 -> V_233 ,
V_208 ) ;
V_19 -> V_203 . V_85 |= V_236 ;
V_235 . V_161 = ( void * ) V_64 ;
V_235 . V_65 = V_234 ;
V_83 = F_28 ( V_19 ,
NULL ,
& V_19 -> V_233 ,
& V_235 ,
V_146 | V_153 ) ;
if ( ! V_83 ) {
F_16 ( L_3 ) ;
return - V_237 ;
}
V_19 -> V_167 = V_238 ;
return F_33 ( V_19 , V_83 , V_162 , 1 , 0 ) ;
}
static int F_47 ( struct V_18 * V_19 , T_1 * V_239 , T_3 * type , T_3 V_240 )
{
struct V_202 * V_203 ;
struct V_214 * V_241 ;
struct V_215 * V_216 ;
int V_242 ;
int V_213 ;
* type = V_243 ;
if ( V_240 < sizeof( struct V_202 ) ) {
F_16 ( L_12 , V_240 ) ;
return - 1 ;
}
V_203 = (struct V_202 * ) V_239 ;
V_242 = sizeof( struct V_202 ) ;
V_213 = F_40 ( V_203 -> V_213 ) ;
if ( V_213 > V_244 ) {
F_16 ( L_13 , V_213 ) ;
return - 1 ;
}
if ( V_203 -> V_211 != V_231 && V_203 -> V_211 != V_232 ) {
F_16 ( L_14 , V_203 -> V_211 ) ;
return - 1 ;
}
if ( V_203 -> V_211 > V_19 -> V_212 ) {
F_16 ( L_15 , V_203 -> V_211 ) ;
return - 1 ;
}
V_19 -> V_212 = V_203 -> V_211 ;
if ( V_19 -> V_167 != V_245 ) {
if ( memcmp ( V_203 -> V_205 , V_206 , V_207 ) ) {
F_16 ( L_16 ) ;
return - 1 ;
}
} else {
if ( memcmp ( V_203 -> V_205 , V_209 , V_207 ) ) {
F_16 ( L_16 ) ;
return - 1 ;
}
}
if ( V_213 + V_242 > V_240 ) {
F_16 ( L_17 ,
V_213 , V_242 , V_240 ) ;
return - 1 ;
}
if ( V_240 > V_246 ) {
F_16 ( L_18 , V_240 ) ;
return - 1 ;
}
switch ( V_203 -> V_211 ) {
case V_232 : {
T_2 V_24 ;
T_2 V_25 ;
T_2 V_218 ;
T_2 V_217 ;
V_241 = (struct V_214 * ) V_239 ;
V_242 += V_220 ;
V_216 = & V_241 -> V_216 ;
V_218 = F_40 ( V_216 -> V_218 ) ;
V_217 = F_40 ( V_216 -> V_217 ) ;
V_24 = V_217 & V_222 ;
V_25 = V_218 & V_222 ;
if ( ! ( V_217 & V_223 ) )
return - 1 ;
if ( V_24 == V_222 || V_25 == V_222 ) {
V_19 -> V_221 = V_222 ;
goto V_247;
}
if ( V_19 -> V_167 != V_245 ) {
if ( ! V_25 && ( V_218 & V_226 ) )
V_19 -> V_24 = 1 ;
if ( V_19 -> V_25 > V_24 )
V_19 -> V_25 = V_24 ;
} else {
if ( ! V_24 && ( V_218 & V_226 ) )
return - 1 ;
if ( V_19 -> V_25 > V_24 )
V_19 -> V_25 = V_24 ;
if ( V_19 -> V_24 < V_25 )
return - 1 ;
}
V_247:
if ( V_218 & V_226 )
V_19 -> V_227 = V_229 ;
else if ( V_218 & V_225 )
V_19 -> V_227 = V_228 ;
else
return - 1 ;
F_19 ( V_19 -> V_2 , V_80 ,
L_19 ,
V_19 -> V_25 , V_19 -> V_24 ) ;
break;
}
break;
case V_231 :
default:
break;
}
memcpy ( V_19 -> V_62 , V_239 + V_242 , V_213 ) ;
V_19 -> V_64 . V_65 = V_213 ;
if ( V_203 -> V_85 & V_236 )
* type = V_248 ;
if ( V_203 -> V_85 & V_249 )
V_19 -> V_250 = true ;
return 0 ;
}
int F_33 ( struct V_18 * V_19 ,
struct V_4 * V_83 ,
enum V_251 type ,
int V_252 ,
int V_253 )
{
struct V_1 * V_2 = V_19 -> V_2 ;
struct V_254 * V_164 = V_19 -> V_164 ;
struct V_81 * V_255 ;
int V_256 = 0 ;
T_3 V_257 ;
unsigned long V_85 ;
V_255 = F_18 ( sizeof( * V_255 ) , V_79 ) ;
if ( ! V_255 ) {
F_1 ( V_19 -> V_2 , ( void * ) V_83 ) ;
return - V_237 ;
}
V_255 -> V_258 = V_259 ;
V_255 -> V_260 = V_261 ;
V_255 -> V_83 = V_83 ;
V_255 -> V_262 = V_263 ;
V_255 -> type = type ;
V_255 -> V_252 = V_252 ;
V_255 -> V_253 = V_253 ;
if ( type == V_264 ) {
V_255 -> V_262 += ( V_265 / 10 ) ;
if ( V_19 -> V_266 ) {
F_22 ( V_255 ) ;
F_1 ( V_19 -> V_2 , ( void * ) V_83 ) ;
F_16 ( L_20 ) ;
return - V_267 ;
}
V_19 -> V_266 = V_255 ;
}
if ( type == V_162 ) {
F_25 ( & V_19 -> V_86 , V_85 ) ;
V_19 -> V_82 = V_255 ;
F_35 ( & V_19 -> V_84 ) ;
F_26 ( & V_19 -> V_86 , V_85 ) ;
V_255 -> V_262 = V_263 + V_268 ;
F_35 ( & V_83 -> V_8 ) ;
F_48 ( V_2 -> V_7 , V_83 ) ;
if ( ! V_252 ) {
F_24 ( V_19 ) ;
if ( V_253 )
F_37 ( V_19 ) ;
return V_256 ;
}
}
F_25 ( & V_164 -> V_269 , V_85 ) ;
V_257 = F_49 ( & V_164 -> V_270 ) ;
if ( ! V_257 ) {
V_164 -> V_270 . V_271 = V_255 -> V_262 ;
F_50 ( & V_164 -> V_270 ) ;
}
F_26 ( & V_164 -> V_269 , V_85 ) ;
return V_256 ;
}
static void F_51 ( struct V_18 * V_19 )
{
struct V_57 * V_58 = V_19 -> V_58 ;
enum V_272 V_167 = V_19 -> V_167 ;
V_19 -> V_167 = V_168 ;
switch ( V_167 ) {
case V_273 :
case V_274 :
F_37 ( V_19 ) ;
break;
case V_238 :
case V_275 :
if ( V_19 -> V_58 )
V_58 -> V_175 ( V_58 ) ;
F_32 ( V_19 ) ;
break;
default:
F_35 ( & V_19 -> V_84 ) ;
F_32 ( V_19 ) ;
F_17 ( V_19 , V_169 ) ;
break;
}
}
static void F_52 ( struct V_18 * V_19 , T_3 V_276 )
{
struct V_81 * V_266 = V_19 -> V_266 ;
struct V_57 * V_58 = V_19 -> V_58 ;
struct V_171 * V_172 ;
unsigned long V_85 ;
if ( ! V_266 )
return;
V_172 = (struct V_171 * ) V_266 -> V_83 ;
if ( V_172 ) {
F_25 ( & V_172 -> V_277 , V_85 ) ;
if ( V_172 -> V_58 ) {
V_172 -> V_278 = V_279 ;
V_172 -> V_280 = V_281 ;
V_172 -> V_282 = V_283 ;
V_172 -> V_284 = V_285 ;
F_26 ( & V_172 -> V_277 , V_85 ) ;
F_53 ( V_172 ) ;
} else {
F_26 ( & V_172 -> V_277 , V_85 ) ;
}
} else if ( V_276 ) {
F_37 ( V_19 ) ;
}
if ( V_58 )
V_58 -> V_175 ( V_58 ) ;
F_22 ( V_266 ) ;
V_19 -> V_266 = NULL ;
}
static void F_54 ( unsigned long V_286 )
{
unsigned long V_287 = V_263 + V_288 ;
struct V_18 * V_19 ;
struct V_81 * V_82 , * V_266 ;
struct V_289 * V_290 ;
struct V_289 * V_291 ;
struct V_254 * V_164 = (struct V_254 * ) V_286 ;
T_3 V_292 = 0 ;
unsigned long V_262 ;
struct V_1 * V_2 ;
unsigned long V_85 ;
struct V_289 V_293 ;
F_55 ( & V_293 ) ;
F_25 ( & V_164 -> V_269 , V_85 ) ;
F_56 (list_node, list_core_temp, &cm_core->connected_nodes) {
V_19 = F_57 ( V_291 , struct V_18 , V_294 ) ;
if ( V_19 -> V_266 || V_19 -> V_82 ) {
F_35 ( & V_19 -> V_84 ) ;
F_58 ( & V_19 -> V_295 , & V_293 ) ;
}
}
F_26 ( & V_164 -> V_269 , V_85 ) ;
F_56 (list_node, list_core_temp, &timer_list) {
V_19 = F_57 ( V_291 ,
struct V_18 ,
V_295 ) ;
V_266 = V_19 -> V_266 ;
if ( V_266 ) {
if ( F_59 ( V_266 -> V_262 , V_263 ) ) {
if ( V_287 > V_266 -> V_262 ||
! V_292 ) {
V_287 = V_266 -> V_262 ;
V_292 = 1 ;
}
} else {
F_52 ( V_19 , 1 ) ;
}
}
F_25 ( & V_19 -> V_86 , V_85 ) ;
V_82 = V_19 -> V_82 ;
if ( ! V_82 )
goto V_296;
if ( F_59 ( V_82 -> V_262 , V_263 ) ) {
if ( V_19 -> V_167 != V_297 ) {
if ( ( V_287 > V_82 -> V_262 ) ||
! V_292 ) {
V_287 = V_82 -> V_262 ;
V_292 = 1 ;
}
} else {
F_21 ( V_19 ) ;
}
goto V_296;
}
if ( ( V_19 -> V_167 == V_297 ) ||
( V_19 -> V_167 == V_168 ) ) {
F_21 ( V_19 ) ;
goto V_296;
}
if ( ! V_82 -> V_260 || ! V_82 -> V_258 ) {
F_21 ( V_19 ) ;
F_26 ( & V_19 -> V_86 , V_85 ) ;
F_51 ( V_19 ) ;
V_19 -> V_167 = V_168 ;
F_25 ( & V_19 -> V_86 , V_85 ) ;
goto V_296;
}
V_19 -> V_164 -> V_298 ++ ;
F_26 ( & V_19 -> V_86 , V_85 ) ;
V_2 = V_19 -> V_2 ;
F_35 ( & V_82 -> V_83 -> V_8 ) ;
F_48 ( V_2 -> V_7 , V_82 -> V_83 ) ;
F_25 ( & V_19 -> V_86 , V_85 ) ;
if ( V_82 -> V_252 ) {
V_82 -> V_260 -- ;
V_262 = ( V_268 <<
( V_261 -
V_82 -> V_260 ) ) ;
V_82 -> V_262 = V_263 +
F_60 ( V_262 , V_299 ) ;
if ( V_287 > V_82 -> V_262 || ! V_292 ) {
V_287 = V_82 -> V_262 ;
V_292 = 1 ;
}
} else {
int V_253 ;
V_253 = V_82 -> V_253 ;
F_19 ( V_19 -> V_2 ,
V_80 ,
L_21 ,
V_19 ,
V_19 -> V_167 ) ;
F_21 ( V_19 ) ;
if ( V_253 )
F_37 ( V_19 ) ;
}
V_296:
F_26 ( & V_19 -> V_86 , V_85 ) ;
F_37 ( V_19 ) ;
}
if ( V_292 ) {
F_25 ( & V_164 -> V_269 , V_85 ) ;
if ( ! F_49 ( & V_164 -> V_270 ) ) {
V_164 -> V_270 . V_271 = V_287 ;
F_50 ( & V_164 -> V_270 ) ;
}
F_26 ( & V_164 -> V_269 , V_85 ) ;
}
}
int F_61 ( struct V_18 * V_19 , T_3 V_300 )
{
struct V_4 * V_83 ;
int V_85 = V_151 ;
char V_301 [ sizeof( struct V_302 ) +
sizeof( struct V_303 ) +
sizeof( struct V_304 ) + V_305 ] ;
struct V_88 V_306 ;
int V_307 = 0 ;
union V_181 * V_89 ;
V_306 . V_161 = V_301 ;
if ( ! V_19 ) {
F_16 ( L_22 ) ;
return - V_267 ;
}
V_89 = (union V_181 * ) & V_301 [ V_307 ] ;
V_89 -> V_189 . V_185 = V_188 ;
V_89 -> V_189 . V_190 = sizeof( struct V_302 ) ;
V_89 -> V_189 . V_191 = F_11 ( V_19 -> V_129 . V_191 ) ;
V_307 += sizeof( struct V_302 ) ;
V_89 = (union V_181 * ) & V_301 [ V_307 ] ;
V_89 -> V_194 . V_185 = V_192 ;
V_89 -> V_194 . V_190 = sizeof( struct V_303 ) ;
V_89 -> V_194 . V_195 = V_19 -> V_129 . V_308 ;
V_307 += sizeof( struct V_303 ) ;
V_89 = (union V_181 * ) & V_301 [ V_307 ] ;
V_89 -> V_309 = V_186 ;
V_307 += 1 ;
if ( V_300 )
V_85 |= V_146 ;
V_306 . V_65 = V_307 ;
V_83 = F_28 ( V_19 , & V_306 , NULL , NULL , V_85 ) ;
if ( ! V_83 ) {
F_16 ( L_3 ) ;
return - 1 ;
}
return F_33 ( V_19 , V_83 , V_162 , 1 , 0 ) ;
}
static void F_62 ( struct V_18 * V_19 )
{
struct V_4 * V_83 ;
V_83 = F_28 ( V_19 , NULL , NULL , NULL , V_146 ) ;
if ( V_83 )
F_48 ( V_19 -> V_2 -> V_7 , V_83 ) ;
else
F_16 ( L_3 ) ;
}
static int F_63 ( struct V_18 * V_19 )
{
struct V_4 * V_83 ;
V_83 = F_28 ( V_19 , NULL , NULL , NULL , V_146 | V_153 ) ;
if ( ! V_83 ) {
F_16 ( L_3 ) ;
return - 1 ;
}
return F_33 ( V_19 , V_83 , V_162 , 1 , 0 ) ;
}
struct V_18 * F_64 ( struct V_254 * V_164 ,
T_2 V_39 ,
T_3 * V_43 ,
T_2 V_38 ,
T_3 * V_42 ,
bool V_310 )
{
struct V_289 * V_311 ;
struct V_18 * V_19 ;
unsigned long V_85 ;
V_311 = & V_164 -> V_312 ;
F_25 ( & V_164 -> V_269 , V_85 ) ;
F_65 (cm_node, hte, list) {
if ( ! memcmp ( V_19 -> V_42 , V_42 , sizeof( V_19 -> V_42 ) ) &&
( V_19 -> V_38 == V_38 ) &&
! memcmp ( V_19 -> V_43 , V_43 , sizeof( V_19 -> V_43 ) ) &&
( V_19 -> V_39 == V_39 ) ) {
if ( V_310 )
F_35 ( & V_19 -> V_84 ) ;
F_26 ( & V_164 -> V_269 , V_85 ) ;
return V_19 ;
}
}
F_26 ( & V_164 -> V_269 , V_85 ) ;
return NULL ;
}
static struct V_313 * F_66 (
struct V_254 * V_164 ,
T_3 * V_314 ,
T_2 V_315 ,
T_2 V_56 ,
enum V_316
V_317 )
{
struct V_313 * V_318 ;
static const T_3 V_319 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_3 V_320 [ 4 ] ;
T_2 V_321 ;
unsigned long V_85 ;
F_25 ( & V_164 -> V_322 , V_85 ) ;
F_65 (listen_node, &cm_core->listen_nodes, list) {
memcpy ( V_320 , V_318 -> V_42 , sizeof( V_320 ) ) ;
V_321 = V_318 -> V_38 ;
if ( ( ! memcmp ( V_320 , V_314 , sizeof( V_320 ) ) ||
! memcmp ( V_320 , V_319 , sizeof( V_320 ) ) ) &&
( V_321 == V_315 ) &&
( V_317 & V_318 -> V_317 ) ) {
F_35 ( & V_318 -> V_84 ) ;
F_26 ( & V_164 -> V_322 , V_85 ) ;
return V_318 ;
}
}
F_26 ( & V_164 -> V_322 , V_85 ) ;
return NULL ;
}
static void F_67 ( struct V_254 * V_164 ,
struct V_18 * V_19 )
{
struct V_289 * V_311 ;
unsigned long V_85 ;
if ( ! V_19 || ! V_164 ) {
F_16 ( L_23 ) ;
return;
}
F_25 ( & V_164 -> V_269 , V_85 ) ;
V_311 = & V_164 -> V_312 ;
F_68 ( & V_19 -> V_294 , V_311 ) ;
F_26 ( & V_164 -> V_269 , V_85 ) ;
}
static bool F_69 ( struct V_254 * V_164 , T_2 V_323 )
{
struct V_313 * V_318 ;
unsigned long V_85 ;
bool V_256 = false ;
F_25 ( & V_164 -> V_322 , V_85 ) ;
F_65 (listen_node, &cm_core->listen_nodes, list) {
if ( V_318 -> V_38 == V_323 ) {
V_256 = true ;
break;
}
}
F_26 ( & V_164 -> V_322 , V_85 ) ;
return V_256 ;
}
static enum V_324 F_70 (
struct V_325 * V_173 ,
struct V_53 * V_54 ,
struct V_313 * V_326 )
{
struct V_313 * V_327 ;
enum V_324 V_256 = V_328 ;
struct V_289 * V_329 , * V_330 ;
unsigned long V_85 ;
F_25 ( & V_173 -> V_164 . V_322 , V_85 ) ;
F_56 (pos, tpos, &cm_parent_listen_node->child_listen_list) {
V_327 = F_71 ( V_329 , struct V_313 , V_331 ) ;
if ( V_327 -> V_55 )
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_24 ,
V_327 -> V_42 ,
V_327 -> V_38 ,
V_327 -> V_56 ) ;
else
F_19 ( & V_173 -> V_332 , V_80 ,
L_25 ,
V_327 -> V_42 ,
V_327 -> V_38 ,
V_327 -> V_56 ) ;
F_72 ( V_329 ) ;
memcpy ( V_54 -> V_42 , V_327 -> V_42 ,
sizeof( V_54 -> V_42 ) ) ;
V_54 -> V_56 = V_327 -> V_56 ;
V_256 = F_73 ( V_173 , V_54 ,
V_333 ,
V_334 , NULL , false ) ;
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_26 ,
V_327 ) ;
F_22 ( V_327 ) ;
V_326 -> V_164 -> V_335 ++ ;
}
F_26 ( & V_173 -> V_164 . V_322 , V_85 ) ;
return V_256 ;
}
static struct V_336 * F_74 ( T_3 * V_161 , T_2 * V_56 , T_1 * V_337 )
{
struct V_336 * V_338 = NULL ;
#if F_75 ( V_339 )
struct V_340 V_45 ;
F_8 ( V_45 . V_51 . V_52 , V_161 ) ;
if ( V_56 )
* V_56 = V_341 ;
if ( V_337 )
F_76 ( V_337 ) ;
F_77 () ;
F_78 (&init_net, ip_dev) {
if ( F_79 ( & V_342 , & V_45 , V_338 , 1 ) ) {
if ( V_56 )
* V_56 = F_80 ( V_338 ) ;
if ( V_338 -> V_343 && V_337 )
F_30 ( V_337 , V_338 -> V_343 ) ;
break;
}
}
F_81 () ;
#endif
return V_338 ;
}
static T_2 F_82 ( T_3 * V_161 )
{
struct V_336 * V_344 ;
T_2 V_56 = V_341 ;
V_344 = F_83 ( & V_342 , F_9 ( V_161 [ 0 ] ) ) ;
if ( V_344 ) {
V_56 = F_80 ( V_344 ) ;
F_84 ( V_344 ) ;
}
return V_56 ;
}
static enum V_324 F_85 ( struct V_325 * V_173 ,
struct V_53 * V_54 ,
struct V_313 * V_326 )
{
struct V_336 * V_338 ;
struct V_345 * V_346 ;
struct V_347 * V_348 ;
enum V_324 V_256 = 0 ;
struct V_313 * V_327 ;
unsigned long V_85 ;
F_86 () ;
F_78 (&init_net, ip_dev) {
if ( ( ( ( F_80 ( V_338 ) < V_341 ) &&
( F_87 ( V_338 ) == V_173 -> V_344 ) ) ||
( V_338 == V_173 -> V_344 ) ) && ( V_338 -> V_85 & V_349 ) ) {
V_346 = F_88 ( V_338 ) ;
if ( ! V_346 ) {
F_16 ( L_27 ) ;
break;
}
F_65 (ifp, &idev->addr_list, if_list) {
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_28 ,
& V_348 -> V_161 ,
F_80 ( V_338 ) ,
V_338 -> V_343 ) ;
V_327 =
F_18 ( sizeof( * V_327 ) , V_79 ) ;
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_29 ,
V_327 ) ;
if ( ! V_327 ) {
F_16 ( L_30 ) ;
V_256 = V_350 ;
goto exit;
}
V_54 -> V_56 = F_80 ( V_338 ) ;
V_326 -> V_56 = V_54 -> V_56 ;
memcpy ( V_327 , V_326 ,
sizeof( * V_327 ) ) ;
F_6 ( V_327 -> V_42 ,
V_348 -> V_161 . V_51 . V_52 ) ;
memcpy ( V_54 -> V_42 , V_327 -> V_42 ,
sizeof( V_54 -> V_42 ) ) ;
V_256 = F_73 ( V_173 , V_54 ,
V_333 ,
V_351 ,
NULL , true ) ;
if ( ! V_256 ) {
F_25 ( & V_173 -> V_164 . V_322 , V_85 ) ;
F_58 ( & V_327 -> V_331 ,
& V_326 -> V_331 ) ;
F_26 ( & V_173 -> V_164 . V_322 , V_85 ) ;
V_326 -> V_164 -> V_352 ++ ;
} else {
F_22 ( V_327 ) ;
}
}
}
}
exit:
F_89 () ;
return V_256 ;
}
static enum V_324 F_90 (
struct V_325 * V_173 ,
struct V_53 * V_54 ,
struct V_313 * V_326 )
{
struct V_336 * V_2 ;
struct V_353 * V_346 ;
struct V_313 * V_327 ;
enum V_324 V_256 = 0 ;
unsigned long V_85 ;
F_86 () ;
F_91 (&init_net, dev) {
if ( ( ( ( F_80 ( V_2 ) < V_341 ) &&
( F_87 ( V_2 ) == V_173 -> V_344 ) ) ||
( V_2 == V_173 -> V_344 ) ) && ( V_2 -> V_85 & V_349 ) ) {
V_346 = F_92 ( V_2 ) ;
F_93 (idev) {
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_31 ,
& V_354 -> V_355 ,
F_80 ( V_2 ) ,
V_2 -> V_343 ) ;
V_327 = F_18 ( sizeof( * V_327 ) , V_79 ) ;
V_326 -> V_164 -> V_352 ++ ;
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_29 ,
V_327 ) ;
if ( ! V_327 ) {
F_16 ( L_30 ) ;
F_94 ( V_346 ) ;
V_256 = V_350 ;
goto exit;
}
V_54 -> V_56 = F_80 ( V_2 ) ;
V_326 -> V_56 = V_54 -> V_56 ;
memcpy ( V_327 ,
V_326 ,
sizeof( * V_327 ) ) ;
V_327 -> V_42 [ 0 ] = F_7 ( V_354 -> V_355 ) ;
memcpy ( V_54 -> V_42 , V_327 -> V_42 ,
sizeof( V_54 -> V_42 ) ) ;
V_256 = F_73 ( V_173 ,
V_54 ,
V_333 ,
V_351 ,
NULL ,
true ) ;
if ( ! V_256 ) {
F_25 ( & V_173 -> V_164 . V_322 , V_85 ) ;
F_58 ( & V_327 -> V_331 ,
& V_326 -> V_331 ) ;
F_26 ( & V_173 -> V_164 . V_322 , V_85 ) ;
} else {
F_22 ( V_327 ) ;
V_326 -> V_164 -> V_352 -- ;
}
}
F_95 ( V_346 ) ;
F_94 ( V_346 ) ;
}
}
exit:
F_89 () ;
return V_256 ;
}
static int F_96 ( struct V_254 * V_164 ,
struct V_313 * V_356 ,
int V_357 , bool V_358 )
{
int V_256 = - V_267 ;
int V_359 = 0 ;
struct V_289 * V_360 ;
struct V_289 * V_361 ;
struct V_18 * V_19 ;
struct V_289 V_362 ;
struct V_53 V_363 ;
struct V_18 * V_364 ;
enum V_272 V_365 ;
unsigned long V_85 ;
F_55 ( & V_362 ) ;
if ( V_357 ) {
F_25 ( & V_164 -> V_269 , V_85 ) ;
F_56 (list_pos, list_temp, &cm_core->connected_nodes) {
V_19 = F_57 ( V_360 , struct V_18 , V_294 ) ;
if ( ( V_19 -> V_356 == V_356 ) && ! V_19 -> V_366 ) {
F_35 ( & V_19 -> V_84 ) ;
F_58 ( & V_19 -> V_367 , & V_362 ) ;
}
}
F_26 ( & V_164 -> V_269 , V_85 ) ;
}
F_56 (list_pos, list_temp, &reset_list) {
V_19 = F_57 ( V_360 , struct V_18 , V_367 ) ;
V_364 = V_19 -> V_368 ;
if ( V_19 -> V_167 >= V_238 ) {
F_37 ( V_19 ) ;
} else {
if ( ! V_364 ) {
F_24 ( V_19 ) ;
V_359 = F_32 ( V_19 ) ;
if ( V_359 ) {
V_19 -> V_167 = V_168 ;
F_16 ( L_32 ) ;
} else {
V_365 = V_19 -> V_167 ;
V_19 -> V_167 = V_369 ;
if ( V_365 != V_370 )
F_37 ( V_19 ) ;
}
} else {
struct V_77 V_29 ;
V_29 . V_19 = V_364 ;
memcpy ( V_29 . V_54 . V_43 ,
V_364 -> V_43 , sizeof( V_29 . V_54 . V_43 ) ) ;
memcpy ( V_29 . V_54 . V_42 ,
V_364 -> V_42 , sizeof( V_29 . V_54 . V_42 ) ) ;
V_29 . V_54 . V_39 = V_364 -> V_39 ;
V_29 . V_54 . V_38 = V_364 -> V_38 ;
V_29 . V_54 . V_58 = V_364 -> V_58 ;
V_29 . V_54 . V_55 = V_364 -> V_55 ;
F_35 ( & V_364 -> V_84 ) ;
V_364 -> V_167 = V_168 ;
F_38 ( & V_29 ) ;
V_19 -> V_167 = V_369 ;
F_37 ( V_19 ) ;
}
}
}
if ( ! F_2 ( & V_356 -> V_84 ) ) {
F_25 ( & V_164 -> V_322 , V_85 ) ;
F_72 ( & V_356 -> V_294 ) ;
F_26 ( & V_164 -> V_322 , V_85 ) ;
if ( V_356 -> V_173 ) {
if ( V_358 && ! F_69 ( V_164 , V_356 -> V_38 ) )
F_97 ( V_356 -> V_173 ,
V_356 -> V_38 ,
V_371 ) ;
memcpy ( V_363 . V_42 , V_356 -> V_42 , sizeof( V_363 . V_42 ) ) ;
V_363 . V_38 = V_356 -> V_38 ;
V_363 . V_55 = V_356 -> V_55 ;
V_363 . V_56 = V_356 -> V_56 ;
if ( ! F_98 ( & V_356 -> V_331 ) ) {
F_70 ( V_356 -> V_173 , & V_363 , V_356 ) ;
} else {
if ( V_356 -> V_372 )
F_73 ( V_356 -> V_173 ,
& V_363 ,
V_333 ,
V_334 ,
NULL ,
false ) ;
}
}
V_164 -> V_373 ++ ;
F_22 ( V_356 ) ;
V_164 -> V_335 ++ ;
V_356 = NULL ;
V_256 = 0 ;
}
if ( V_356 ) {
if ( F_99 ( & V_356 -> V_374 ) > 0 )
F_19 ( V_164 -> V_2 ,
V_80 ,
L_33 ,
V_166 ,
V_356 ,
F_99 ( & V_356 -> V_374 ) ) ;
}
return V_256 ;
}
static int F_100 ( struct V_254 * V_164 ,
struct V_313 * V_356 ,
bool V_358 )
{
V_356 -> V_317 = V_375 ;
V_356 -> V_58 = NULL ;
return F_96 ( V_164 , V_356 , 1 , V_358 ) ;
}
static int F_101 ( struct V_325 * V_173 ,
T_3 V_376 ,
T_3 V_377 ,
int V_378 )
{
struct V_379 * V_380 ;
struct V_381 * V_382 ;
int V_383 = V_378 ;
struct V_336 * V_344 = V_173 -> V_344 ;
T_4 V_384 = F_9 ( V_377 ) ;
T_4 V_385 = F_9 ( V_376 ) ;
V_380 = F_102 ( & V_342 , V_384 , V_385 , 0 , 0 ) ;
if ( F_103 ( V_380 ) ) {
F_16 ( L_34 ) ;
return V_383 ;
}
if ( F_104 ( V_344 ) )
V_344 = F_105 ( V_344 ) ;
V_382 = F_106 ( & V_380 -> V_26 , & V_384 ) ;
F_77 () ;
if ( V_382 ) {
if ( V_382 -> V_386 & V_387 ) {
if ( V_378 >= 0 ) {
if ( F_107 ( V_173 -> V_388 [ V_378 ] . V_389 ,
V_382 -> V_390 ) )
goto V_391;
F_108 ( V_173 ,
V_173 -> V_388 [ V_378 ] . V_389 ,
& V_377 ,
true ,
V_392 ) ;
}
F_108 ( V_173 , V_382 -> V_390 , & V_377 , true , V_393 ) ;
V_383 = F_109 ( V_173 , & V_377 , true , NULL , V_394 ) ;
} else {
F_110 ( V_382 , NULL ) ;
}
}
V_391:
F_81 () ;
if ( V_382 )
F_111 ( V_382 ) ;
F_112 ( V_380 ) ;
return V_383 ;
}
static struct V_395 * F_113 ( struct V_44 * V_396 ,
struct V_44 * V_314 )
{
struct V_395 * V_26 ;
struct V_397 V_398 ;
memset ( & V_398 , 0 , sizeof( V_398 ) ) ;
V_398 . V_136 = V_314 -> V_50 ;
V_398 . V_135 = V_396 -> V_50 ;
if ( F_114 ( & V_398 . V_136 ) & V_399 )
V_398 . V_400 = V_314 -> V_401 ;
V_26 = F_115 ( & V_342 , NULL , & V_398 ) ;
return V_26 ;
}
static int F_116 ( struct V_325 * V_173 ,
T_3 * V_27 ,
T_3 * V_143 ,
int V_378 )
{
struct V_381 * V_382 ;
int V_383 = V_378 ;
struct V_336 * V_344 = V_173 -> V_344 ;
struct V_395 * V_26 ;
struct V_44 V_314 ;
struct V_44 V_396 ;
memset ( & V_314 , 0 , sizeof( V_314 ) ) ;
V_314 . V_47 = V_48 ;
F_8 ( V_314 . V_50 . V_51 . V_52 , V_143 ) ;
memset ( & V_396 , 0 , sizeof( V_396 ) ) ;
V_396 . V_47 = V_48 ;
F_8 ( V_396 . V_50 . V_51 . V_52 , V_27 ) ;
V_26 = F_113 ( & V_396 , & V_314 ) ;
if ( ! V_26 || V_26 -> error ) {
if ( V_26 ) {
F_117 ( V_26 ) ;
F_16 ( L_35 ,
V_26 -> error ) ;
}
return V_383 ;
}
if ( F_104 ( V_344 ) )
V_344 = F_105 ( V_344 ) ;
V_382 = F_106 ( V_26 , & V_314 ) ;
F_77 () ;
if ( V_382 ) {
F_19 ( & V_173 -> V_332 , V_80 , L_36 , V_382 -> V_390 ) ;
if ( V_382 -> V_386 & V_387 ) {
if ( V_378 >= 0 ) {
if ( F_107
( V_173 -> V_388 [ V_378 ] . V_389 ,
V_382 -> V_390 ) ) {
goto V_402;
}
F_108 ( V_173 ,
V_173 -> V_388 [ V_378 ] . V_389 ,
V_143 ,
false ,
V_392 ) ;
}
F_108 ( V_173 ,
V_382 -> V_390 ,
V_143 ,
false ,
V_393 ) ;
V_383 = F_109 ( V_173 ,
V_143 ,
false ,
NULL ,
V_394 ) ;
} else {
F_110 ( V_382 , NULL ) ;
}
}
V_402:
F_81 () ;
if ( V_382 )
F_111 ( V_382 ) ;
F_117 ( V_26 ) ;
return V_383 ;
}
static bool F_118 ( T_3 V_42 , T_3 V_43 )
{
return F_119 ( F_9 ( V_43 ) ) || ( V_42 == V_43 ) ;
}
static bool F_120 ( T_3 * V_42 , T_3 * V_43 )
{
struct V_340 V_46 ;
F_8 ( V_46 . V_51 . V_52 , V_43 ) ;
return ! memcmp ( V_42 , V_43 , 16 ) || F_121 ( & V_46 ) ;
}
static struct V_18 * F_122 (
struct V_254 * V_164 ,
struct V_325 * V_173 ,
struct V_53 * V_54 ,
struct V_313 * V_356 )
{
struct V_18 * V_19 ;
struct V_403 V_404 ;
int V_405 ;
int V_378 ;
struct V_336 * V_344 = V_173 -> V_344 ;
V_19 = F_18 ( sizeof( * V_19 ) , V_79 ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_55 = V_54 -> V_55 ;
V_19 -> V_56 = V_54 -> V_56 ;
memcpy ( V_19 -> V_42 , V_54 -> V_42 , sizeof( V_19 -> V_42 ) ) ;
memcpy ( V_19 -> V_43 , V_54 -> V_43 , sizeof( V_19 -> V_43 ) ) ;
V_19 -> V_38 = V_54 -> V_38 ;
V_19 -> V_39 = V_54 -> V_39 ;
V_19 -> V_212 = V_173 -> V_406 ;
V_19 -> V_227 = V_229 ;
V_19 -> V_24 = V_22 ;
V_19 -> V_25 = V_23 ;
V_19 -> V_356 = V_356 ;
V_19 -> V_58 = V_54 -> V_58 ;
F_30 ( V_19 -> V_115 , V_344 -> V_343 ) ;
F_123 ( & V_19 -> V_86 ) ;
F_31 ( & V_19 -> V_84 , 1 ) ;
V_19 -> V_164 = V_164 ;
V_19 -> V_129 . V_130 = V_407 ;
V_19 -> V_129 . V_308 = V_408 ;
V_19 -> V_129 . V_159 =
V_409 >> V_408 ;
V_404 = F_124 () ;
V_19 -> V_129 . V_145 = V_404 . V_410 ;
V_19 -> V_129 . V_191 = V_173 -> V_191 ;
V_19 -> V_173 = V_173 ;
V_19 -> V_2 = & V_173 -> V_332 ;
if ( ( V_19 -> V_55 &&
F_118 ( V_19 -> V_42 [ 0 ] , V_19 -> V_43 [ 0 ] ) ) ||
( ! V_19 -> V_55 && F_120 ( V_19 -> V_42 ,
V_19 -> V_43 ) ) ) {
V_378 = F_109 ( V_173 ,
V_19 -> V_43 ,
false ,
NULL ,
V_394 ) ;
} else {
V_405 = F_109 ( V_173 ,
V_19 -> V_43 ,
false ,
NULL ,
V_394 ) ;
if ( V_19 -> V_55 )
V_378 = F_101 ( V_173 ,
V_54 -> V_42 [ 0 ] ,
V_54 -> V_43 [ 0 ] ,
V_405 ) ;
else if ( F_75 ( V_339 ) )
V_378 = F_116 ( V_173 ,
V_54 -> V_42 ,
V_54 -> V_43 ,
V_405 ) ;
else
V_378 = - V_267 ;
}
if ( V_378 < 0 ) {
F_16 ( L_37 ) ;
F_22 ( V_19 ) ;
return NULL ;
}
F_30 ( V_19 -> V_87 , V_173 -> V_388 [ V_378 ] . V_389 ) ;
F_67 ( V_164 , V_19 ) ;
V_164 -> V_411 ++ ;
return V_19 ;
}
static void F_37 ( struct V_18 * V_19 )
{
struct V_254 * V_164 = V_19 -> V_164 ;
struct V_171 * V_172 ;
struct V_53 V_363 ;
unsigned long V_85 ;
F_25 ( & V_19 -> V_164 -> V_269 , V_85 ) ;
if ( F_2 ( & V_19 -> V_84 ) ) {
F_26 ( & V_19 -> V_164 -> V_269 , V_85 ) ;
return;
}
F_72 ( & V_19 -> V_294 ) ;
F_26 ( & V_19 -> V_164 -> V_269 , V_85 ) ;
if ( ! V_19 -> V_366 && V_19 -> V_412 ) {
F_125 ( L_38 ) ;
F_23 ( & V_19 -> V_356 -> V_374 ) ;
}
if ( V_19 -> V_266 )
F_52 ( V_19 , 0 ) ;
if ( V_19 -> V_356 ) {
F_96 ( V_164 , V_19 -> V_356 , 0 , true ) ;
} else {
if ( ! F_69 ( V_164 , V_19 -> V_38 ) &&
V_19 -> V_413 && V_19 -> V_173 ) {
F_97 ( V_19 -> V_173 ,
V_19 -> V_38 ,
V_371 ) ;
F_13 ( V_19 , & V_363 ) ;
if ( V_19 -> V_372 ) {
F_73 ( V_19 -> V_173 ,
& V_363 ,
V_414 ,
V_334 ,
NULL ,
false ) ;
V_19 -> V_372 = 0 ;
}
}
}
V_172 = V_19 -> V_172 ;
if ( V_172 ) {
V_172 -> V_19 = NULL ;
F_126 ( & V_172 -> V_415 ) ;
V_19 -> V_172 = NULL ;
} else if ( V_19 -> V_372 ) {
F_13 ( V_19 , & V_363 ) ;
F_73 ( V_19 -> V_173 ,
& V_363 ,
V_414 ,
V_334 ,
NULL ,
false ) ;
V_19 -> V_372 = 0 ;
}
V_19 -> V_164 -> V_416 ++ ;
F_22 ( V_19 ) ;
}
static void F_127 ( struct V_18 * V_19 )
{
T_3 V_256 ;
switch ( V_19 -> V_167 ) {
case V_273 :
case V_417 :
case V_418 :
case V_419 :
V_19 -> V_129 . V_148 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_167 = V_275 ;
F_63 ( V_19 ) ;
break;
case V_245 :
F_17 ( V_19 , V_169 ) ;
V_19 -> V_129 . V_148 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_167 = V_168 ;
F_35 ( & V_19 -> V_84 ) ;
F_32 ( V_19 ) ;
break;
case V_238 :
V_19 -> V_129 . V_148 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_167 = V_274 ;
F_62 ( V_19 ) ;
break;
case V_420 :
V_19 -> V_129 . V_148 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_167 = V_421 ;
F_62 ( V_19 ) ;
V_256 =
F_33 ( V_19 , NULL , V_264 , 1 , 0 ) ;
if ( V_256 )
F_16 ( L_39 , V_19 , V_19 -> V_167 ) ;
break;
case V_421 :
V_19 -> V_129 . V_148 ++ ;
F_24 ( V_19 ) ;
V_19 -> V_167 = V_168 ;
F_37 ( V_19 ) ;
break;
case V_297 :
default:
F_16 ( L_40 , V_19 , V_19 -> V_167 ) ;
break;
}
}
static void F_128 ( struct V_18 * V_19 ,
struct V_4 * V_422 )
{
F_24 ( V_19 ) ;
switch ( V_19 -> V_167 ) {
case V_417 :
case V_245 :
switch ( V_19 -> V_212 ) {
case V_232 :
V_19 -> V_212 = V_231 ;
V_19 -> V_167 = V_417 ;
if ( F_61 ( V_19 , 0 ) )
F_34 ( V_19 , false ) ;
break;
case V_231 :
default:
F_34 ( V_19 , false ) ;
break;
}
break;
case V_370 :
F_129 ( 1 , & V_19 -> V_423 ) ;
break;
case V_418 :
case V_273 :
case V_424 :
F_16 ( L_41 , V_19 -> V_167 ) ;
F_36 ( V_19 , false ) ;
break;
case V_297 :
F_34 ( V_19 , false ) ;
break;
case V_168 :
break;
case V_420 :
case V_238 :
case V_275 :
V_19 -> V_58 -> V_175 ( V_19 -> V_58 ) ;
case V_421 :
V_19 -> V_167 = V_168 ;
F_37 ( V_19 ) ;
break;
default:
break;
}
}
static void F_130 ( struct V_18 * V_19 ,
struct V_4 * V_422 )
{
int V_256 ;
int V_425 = V_422 -> V_426 ;
T_1 * V_427 = V_422 -> V_428 ;
enum V_78 type = V_429 ;
T_3 V_430 ;
V_256 = F_47 ( V_19 , V_427 , & V_430 , V_425 ) ;
if ( V_256 ) {
if ( V_19 -> V_167 == V_245 )
F_34 ( V_19 , true ) ;
else
F_36 ( V_19 , true ) ;
return;
}
switch ( V_19 -> V_167 ) {
case V_418 :
if ( V_430 == V_248 )
F_16 ( L_42 ) ;
V_19 -> V_167 = V_370 ;
type = V_431 ;
F_62 ( V_19 ) ;
F_31 ( & V_19 -> V_423 ,
V_432 ) ;
break;
case V_245 :
F_24 ( V_19 ) ;
if ( V_430 == V_248 ) {
type = V_433 ;
V_19 -> V_167 = V_419 ;
} else {
type = V_434 ;
V_19 -> V_167 = V_297 ;
F_62 ( V_19 ) ;
}
break;
default:
F_125 ( L_43 , V_166 , V_19 -> V_167 ) ;
break;
}
F_17 ( V_19 , type ) ;
}
static void F_131 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_167 ) {
case V_417 :
case V_245 :
F_34 ( V_19 , true ) ;
break;
case V_418 :
case V_273 :
F_36 ( V_19 , true ) ;
break;
case V_297 :
default:
break;
}
}
static int F_132 ( struct V_18 * V_19 , struct V_91 * V_92 )
{
int V_359 = 0 ;
if ( F_7 ( V_92 -> V_149 ) != V_19 -> V_129 . V_145 ) {
V_359 = 1 ;
F_34 ( V_19 , true ) ;
}
return V_359 ;
}
static int F_133 ( struct V_18 * V_19 , struct V_91 * V_92 )
{
int V_359 = 0 ;
T_3 V_144 ;
T_3 V_149 ;
T_3 V_145 = V_19 -> V_129 . V_145 ;
T_3 V_148 = V_19 -> V_129 . V_148 ;
T_3 V_159 ;
V_144 = F_7 ( V_92 -> V_144 ) ;
V_149 = F_7 ( V_92 -> V_149 ) ;
V_159 = V_19 -> V_129 . V_159 ;
if ( V_149 != V_145 )
V_359 = - 1 ;
else if ( ! F_134 ( V_144 , V_148 , ( V_148 + V_159 ) ) )
V_359 = - 1 ;
if ( V_359 ) {
F_16 ( L_44 ) ;
F_131 ( V_19 ) ;
}
return V_359 ;
}
static void F_135 ( struct V_18 * V_19 ,
struct V_4 * V_422 )
{
struct V_91 * V_92 = (struct V_91 * ) V_422 -> V_92 ;
int V_256 ;
T_3 V_435 ;
int V_177 ;
struct V_53 V_363 ;
V_177 = ( V_92 -> V_157 << 2 ) - sizeof( struct V_91 ) ;
V_435 = F_7 ( V_92 -> V_144 ) ;
switch ( V_19 -> V_167 ) {
case V_417 :
case V_245 :
F_34 ( V_19 , 1 ) ;
break;
case V_424 :
if ( F_99 ( & V_19 -> V_356 -> V_374 ) >
V_19 -> V_356 -> V_436 ) {
V_19 -> V_164 -> V_437 ++ ;
F_36 ( V_19 , false ) ;
break;
}
V_256 = F_41 ( V_19 , V_92 , V_177 , 1 ) ;
if ( V_256 ) {
F_36 ( V_19 , false ) ;
break;
}
V_19 -> V_129 . V_148 = V_435 + 1 ;
V_19 -> V_412 = 1 ;
F_35 ( & V_19 -> V_356 -> V_374 ) ;
V_19 -> V_167 = V_273 ;
F_13 ( V_19 , & V_363 ) ;
V_256 = F_73 ( V_19 -> V_173 ,
& V_363 ,
V_414 ,
V_351 ,
( void * ) V_19 ,
false ) ;
V_19 -> V_372 = true ;
break;
case V_168 :
F_24 ( V_19 ) ;
F_35 ( & V_19 -> V_84 ) ;
F_32 ( V_19 ) ;
break;
case V_297 :
case V_418 :
case V_238 :
case V_420 :
case V_370 :
case V_275 :
case V_274 :
case V_438 :
default:
break;
}
}
static void F_136 ( struct V_18 * V_19 ,
struct V_4 * V_422 )
{
struct V_91 * V_92 = (struct V_91 * ) V_422 -> V_92 ;
int V_256 ;
T_3 V_435 ;
int V_177 ;
V_177 = ( V_92 -> V_157 << 2 ) - sizeof( struct V_91 ) ;
V_435 = F_7 ( V_92 -> V_144 ) ;
switch ( V_19 -> V_167 ) {
case V_417 :
F_24 ( V_19 ) ;
if ( F_132 ( V_19 , V_92 ) ) {
F_16 ( L_45 ) ;
return;
}
V_19 -> V_129 . V_439 = F_7 ( V_92 -> V_149 ) ;
V_256 = F_41 ( V_19 , V_92 , V_177 , 0 ) ;
if ( V_256 ) {
F_19 ( V_19 -> V_2 ,
V_80 ,
L_46 ,
V_19 ) ;
break;
}
F_24 ( V_19 ) ;
V_19 -> V_129 . V_148 = V_435 + 1 ;
F_62 ( V_19 ) ;
V_256 = F_45 ( V_19 ) ;
if ( V_256 ) {
F_19 ( V_19 -> V_2 ,
V_80 ,
L_47 ,
V_19 ) ;
break;
}
V_19 -> V_167 = V_245 ;
break;
case V_370 :
F_36 ( V_19 , true ) ;
break;
case V_424 :
V_19 -> V_129 . V_145 = F_7 ( V_92 -> V_149 ) ;
F_24 ( V_19 ) ;
V_19 -> V_167 = V_168 ;
F_32 ( V_19 ) ;
break;
case V_168 :
V_19 -> V_129 . V_145 = F_7 ( V_92 -> V_149 ) ;
F_24 ( V_19 ) ;
F_35 ( & V_19 -> V_84 ) ;
F_32 ( V_19 ) ;
break;
case V_418 :
case V_238 :
case V_420 :
case V_275 :
case V_297 :
case V_274 :
case V_438 :
case V_245 :
default:
break;
}
}
static int F_137 ( struct V_18 * V_19 ,
struct V_4 * V_422 )
{
struct V_91 * V_92 = (struct V_91 * ) V_422 -> V_92 ;
T_3 V_435 ;
int V_256 = 0 ;
int V_177 ;
T_3 V_425 = V_422 -> V_426 ;
V_177 = ( V_92 -> V_157 << 2 ) - sizeof( struct V_91 ) ;
if ( F_133 ( V_19 , V_92 ) )
return - V_267 ;
V_435 = F_7 ( V_92 -> V_144 ) ;
switch ( V_19 -> V_167 ) {
case V_273 :
F_24 ( V_19 ) ;
V_256 = F_41 ( V_19 , V_92 , V_177 , 1 ) ;
if ( V_256 )
break;
V_19 -> V_129 . V_439 = F_7 ( V_92 -> V_149 ) ;
V_19 -> V_167 = V_418 ;
if ( V_425 ) {
V_19 -> V_129 . V_148 = V_435 + V_425 ;
F_130 ( V_19 , V_422 ) ;
}
break;
case V_418 :
F_24 ( V_19 ) ;
if ( V_425 ) {
V_19 -> V_129 . V_148 = V_435 + V_425 ;
F_130 ( V_19 , V_422 ) ;
}
break;
case V_245 :
V_19 -> V_129 . V_439 = F_7 ( V_92 -> V_149 ) ;
if ( V_425 ) {
V_19 -> V_129 . V_148 = V_435 + V_425 ;
F_130 ( V_19 , V_422 ) ;
}
break;
case V_424 :
F_24 ( V_19 ) ;
V_19 -> V_167 = V_168 ;
F_32 ( V_19 ) ;
break;
case V_168 :
F_24 ( V_19 ) ;
F_35 ( & V_19 -> V_84 ) ;
F_32 ( V_19 ) ;
break;
case V_275 :
case V_274 :
F_24 ( V_19 ) ;
V_19 -> V_167 = V_168 ;
if ( ! V_19 -> V_412 )
V_19 -> V_58 -> V_175 ( V_19 -> V_58 ) ;
F_37 ( V_19 ) ;
break;
case V_238 :
F_24 ( V_19 ) ;
V_19 -> V_167 = V_420 ;
break;
case V_417 :
case V_420 :
case V_297 :
case V_370 :
case V_438 :
default:
F_24 ( V_19 ) ;
break;
}
return V_256 ;
}
static void F_138 ( struct V_18 * V_19 ,
struct V_4 * V_422 )
{
enum V_440 V_441 = V_442 ;
struct V_91 * V_92 = (struct V_91 * ) V_422 -> V_92 ;
T_3 V_443 = 0 ;
int V_256 ;
if ( V_92 -> V_156 ) {
V_441 = V_444 ;
} else if ( V_92 -> V_152 ) {
V_441 = V_445 ;
if ( V_92 -> V_150 )
V_441 = V_446 ;
} else if ( V_92 -> V_150 ) {
V_441 = V_447 ;
}
if ( V_92 -> V_154 )
V_443 = 1 ;
switch ( V_441 ) {
case V_445 :
F_135 ( V_19 , V_422 ) ;
break;
case V_446 :
F_136 ( V_19 , V_422 ) ;
break;
case V_447 :
V_256 = F_137 ( V_19 , V_422 ) ;
if ( V_443 && ! V_256 )
F_127 ( V_19 ) ;
break;
case V_444 :
F_128 ( V_19 , V_422 ) ;
break;
default:
if ( V_443 &&
( ! F_133 ( V_19 , (struct V_91 * ) V_422 -> V_92 ) ) )
F_127 ( V_19 ) ;
break;
}
}
static struct V_313 * F_139 (
struct V_254 * V_164 ,
struct V_325 * V_173 ,
struct V_53 * V_54 )
{
struct V_313 * V_356 ;
unsigned long V_85 ;
V_356 = F_66 ( V_164 , V_54 -> V_42 ,
V_54 -> V_38 ,
V_54 -> V_56 ,
V_448 ) ;
if ( V_356 &&
( V_356 -> V_317 == V_449 ) ) {
F_23 ( & V_356 -> V_84 ) ;
F_19 ( V_164 -> V_2 ,
V_80 ,
L_48 ) ;
return NULL ;
}
if ( ! V_356 ) {
V_356 = F_18 ( sizeof( * V_356 ) , V_79 ) ;
if ( ! V_356 )
return NULL ;
V_164 -> V_352 ++ ;
memcpy ( V_356 -> V_42 , V_54 -> V_42 , sizeof( V_356 -> V_42 ) ) ;
V_356 -> V_38 = V_54 -> V_38 ;
F_55 ( & V_356 -> V_331 ) ;
F_31 ( & V_356 -> V_84 , 1 ) ;
} else {
V_356 -> V_450 = 1 ;
}
V_356 -> V_58 = V_54 -> V_58 ;
V_356 -> V_55 = V_54 -> V_55 ;
V_356 -> V_56 = V_54 -> V_56 ;
F_31 ( & V_356 -> V_374 , 0 ) ;
V_356 -> V_164 = V_164 ;
V_356 -> V_173 = V_173 ;
V_356 -> V_436 = V_54 -> V_436 ;
V_356 -> V_317 = V_449 ;
if ( ! V_356 -> V_450 ) {
F_25 ( & V_164 -> V_322 , V_85 ) ;
F_58 ( & V_356 -> V_294 , & V_164 -> V_451 ) ;
F_26 ( & V_164 -> V_322 , V_85 ) ;
}
return V_356 ;
}
static struct V_18 * F_140 (
struct V_254 * V_164 ,
struct V_325 * V_173 ,
T_2 V_63 ,
void * V_61 ,
struct V_53 * V_54 )
{
struct V_18 * V_19 ;
struct V_313 * V_452 ;
struct V_18 * V_453 ;
struct V_53 V_454 ;
V_19 = F_122 ( V_164 , V_173 , V_54 , NULL ) ;
if ( ! V_19 )
return NULL ;
V_19 -> V_129 . V_455 = 1 ;
V_19 -> V_129 . V_308 = V_408 ;
if ( ! memcmp ( V_54 -> V_42 , V_54 -> V_43 , sizeof( V_54 -> V_42 ) ) ) {
V_452 = F_66 (
V_164 ,
V_54 -> V_43 ,
V_19 -> V_39 ,
V_19 -> V_56 ,
V_449 ) ;
if ( ! V_452 ) {
F_17 ( V_19 , V_169 ) ;
} else {
V_454 = * V_54 ;
V_454 . V_38 = V_54 -> V_39 ;
V_454 . V_39 = V_54 -> V_38 ;
V_454 . V_58 = V_452 -> V_58 ;
V_454 . V_55 = V_54 -> V_55 ;
V_453 = F_122 ( V_164 ,
V_173 ,
& V_454 ,
V_452 ) ;
if ( ! V_453 ) {
F_37 ( V_19 ) ;
return NULL ;
}
V_164 -> V_456 ++ ;
V_453 -> V_368 = V_19 ;
V_453 -> V_129 . V_308 =
V_408 ;
V_19 -> V_368 = V_453 ;
memcpy ( V_453 -> V_62 , V_61 ,
V_63 ) ;
V_453 -> V_64 . V_65 = V_63 ;
V_19 -> V_167 = V_297 ;
V_19 -> V_129 . V_148 =
V_453 -> V_129 . V_145 ;
V_453 -> V_129 . V_148 =
V_19 -> V_129 . V_145 ;
V_19 -> V_129 . V_199 =
V_453 -> V_129 . V_159 ;
V_453 -> V_129 . V_199 = V_19 -> V_129 . V_159 ;
V_19 -> V_129 . V_198 = V_453 -> V_129 . V_159 ;
V_453 -> V_129 . V_198 = V_19 -> V_129 . V_159 ;
V_19 -> V_129 . V_193 = V_453 -> V_129 . V_308 ;
V_453 -> V_129 . V_193 = V_19 -> V_129 . V_308 ;
V_453 -> V_167 = V_370 ;
F_17 ( V_453 , V_431 ) ;
}
return V_19 ;
}
V_19 -> V_64 . V_65 = V_63 ;
V_19 -> V_64 . V_161 = V_19 -> V_62 ;
memcpy ( V_19 -> V_62 , V_61 , V_63 ) ;
V_19 -> V_167 = V_417 ;
return V_19 ;
}
static int F_141 ( struct V_18 * V_19 , const void * V_64 , T_1 V_234 )
{
int V_256 = 0 ;
int V_359 ;
int V_423 ;
struct V_57 * V_58 = V_19 -> V_58 ;
struct V_18 * V_364 = V_19 -> V_368 ;
if ( V_19 -> V_129 . V_455 )
return V_256 ;
F_24 ( V_19 ) ;
if ( ! V_364 ) {
V_423 = F_129 ( 1 , & V_19 -> V_423 ) ;
if ( V_423 == V_457 ) {
V_19 -> V_167 = V_168 ;
F_37 ( V_19 ) ;
} else {
if ( V_19 -> V_167 == V_369 ) {
F_37 ( V_19 ) ;
} else {
V_256 = F_46 ( V_19 , V_64 , V_234 ) ;
if ( V_256 ) {
V_19 -> V_167 = V_168 ;
V_359 = F_32 ( V_19 ) ;
if ( V_359 )
F_16 ( L_49 ) ;
} else {
V_58 -> V_458 ( V_58 ) ;
}
}
}
} else {
V_19 -> V_58 = NULL ;
if ( V_19 -> V_167 == V_369 ) {
F_37 ( V_19 ) ;
F_37 ( V_364 ) ;
} else {
V_256 = F_15 ( V_364 ,
V_364 -> V_58 ,
V_72 ,
- V_459 ) ;
F_37 ( V_19 ) ;
V_364 -> V_167 = V_274 ;
V_58 = V_364 -> V_58 ;
F_37 ( V_364 ) ;
V_58 -> V_175 ( V_58 ) ;
}
}
return V_256 ;
}
static int F_142 ( struct V_18 * V_19 )
{
int V_256 = 0 ;
if ( ! V_19 )
return - V_267 ;
switch ( V_19 -> V_167 ) {
case V_273 :
case V_417 :
case V_460 :
case V_418 :
case V_461 :
case V_245 :
case V_370 :
F_24 ( V_19 ) ;
F_32 ( V_19 ) ;
break;
case V_462 :
V_19 -> V_167 = V_275 ;
F_63 ( V_19 ) ;
break;
case V_238 :
case V_420 :
case V_275 :
case V_421 :
case V_274 :
V_256 = - 1 ;
break;
case V_424 :
F_24 ( V_19 ) ;
F_32 ( V_19 ) ;
break;
case V_419 :
case V_438 :
case V_463 :
case V_168 :
case V_369 :
F_37 ( V_19 ) ;
break;
case V_297 :
if ( V_19 -> V_82 )
F_16 ( L_50 ) ;
F_37 ( V_19 ) ;
break;
}
return V_256 ;
}
void F_143 ( struct V_1 * V_2 , struct V_4 * V_422 )
{
struct V_18 * V_19 ;
struct V_313 * V_356 ;
struct V_93 * V_94 ;
struct V_95 * V_96 ;
struct V_91 * V_92 ;
struct V_53 V_54 ;
struct V_325 * V_173 = (struct V_325 * ) V_2 -> V_464 ;
struct V_254 * V_164 = & V_173 -> V_164 ;
struct V_116 * V_98 ;
V_94 = (struct V_93 * ) V_422 -> V_94 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_144 ( V_2 ,
V_465 ,
L_51 ,
V_422 -> V_105 . V_106 ,
V_422 -> V_109 ) ;
V_98 = (struct V_116 * ) V_422 -> V_105 . V_106 ;
if ( V_98 -> V_117 == F_11 ( V_118 ) ) {
V_54 . V_56 = F_40 ( V_98 -> V_119 ) & V_466 ;
F_19 ( V_164 -> V_2 ,
V_80 ,
L_52 ,
V_166 ,
V_54 . V_56 ) ;
} else {
V_54 . V_56 = V_341 ;
}
V_92 = (struct V_91 * ) V_422 -> V_92 ;
if ( V_422 -> V_55 ) {
V_54 . V_42 [ 0 ] = F_7 ( V_94 -> V_136 ) ;
V_54 . V_43 [ 0 ] = F_7 ( V_94 -> V_135 ) ;
V_54 . V_55 = true ;
} else {
V_96 = (struct V_95 * ) V_422 -> V_94 ;
F_6 ( V_54 . V_42 ,
V_96 -> V_136 . V_51 . V_52 ) ;
F_6 ( V_54 . V_43 ,
V_96 -> V_135 . V_51 . V_52 ) ;
V_54 . V_55 = false ;
}
V_54 . V_38 = F_40 ( V_92 -> V_143 ) ;
V_54 . V_39 = F_40 ( V_92 -> V_142 ) ;
V_19 = F_64 ( V_164 ,
V_54 . V_39 ,
V_54 . V_43 ,
V_54 . V_38 ,
V_54 . V_42 ,
true ) ;
if ( ! V_19 ) {
if ( ! V_92 -> V_152 || V_92 -> V_150 )
return;
V_356 =
F_66 ( V_164 ,
V_54 . V_42 ,
V_54 . V_38 ,
V_54 . V_56 ,
V_449 ) ;
if ( ! V_356 ) {
V_54 . V_58 = NULL ;
F_19 ( V_164 -> V_2 ,
V_80 ,
L_53 ,
V_166 ) ;
return;
}
V_54 . V_58 = V_356 -> V_58 ;
V_19 = F_122 ( V_164 , V_173 , & V_54 , V_356 ) ;
if ( ! V_19 ) {
F_19 ( V_164 -> V_2 ,
V_80 ,
L_54 ,
V_166 ) ;
F_23 ( & V_356 -> V_84 ) ;
return;
}
if ( ! V_92 -> V_156 && ! V_92 -> V_154 ) {
V_19 -> V_167 = V_424 ;
} else {
F_37 ( V_19 ) ;
return;
}
F_35 ( & V_19 -> V_84 ) ;
} else if ( V_19 -> V_167 == V_297 ) {
F_37 ( V_19 ) ;
return;
}
F_138 ( V_19 , V_422 ) ;
F_37 ( V_19 ) ;
}
void F_145 ( struct V_325 * V_173 )
{
struct V_254 * V_164 = & V_173 -> V_164 ;
V_164 -> V_173 = V_173 ;
V_164 -> V_2 = & V_173 -> V_332 ;
F_55 ( & V_164 -> V_312 ) ;
F_55 ( & V_164 -> V_451 ) ;
F_146 ( & V_164 -> V_270 ) ;
V_164 -> V_270 . V_467 = F_54 ;
V_164 -> V_270 . V_428 = ( unsigned long ) V_164 ;
F_123 ( & V_164 -> V_269 ) ;
F_123 ( & V_164 -> V_322 ) ;
V_164 -> V_468 = F_147 ( L_55 ) ;
V_164 -> V_469 = F_147 ( L_56 ) ;
}
void F_148 ( struct V_254 * V_164 )
{
unsigned long V_85 ;
if ( ! V_164 )
return;
F_25 ( & V_164 -> V_269 , V_85 ) ;
if ( F_49 ( & V_164 -> V_270 ) )
F_149 ( & V_164 -> V_270 ) ;
F_26 ( & V_164 -> V_269 , V_85 ) ;
F_150 ( V_164 -> V_468 ) ;
F_150 ( V_164 -> V_469 ) ;
}
static void F_151 ( struct V_18 * V_19 ,
struct V_470 * V_471 ,
struct V_171 * V_172 )
{
V_471 -> V_55 = V_19 -> V_55 ;
V_471 -> V_472 = true ;
V_471 -> V_473 = true ;
V_471 -> V_474 = true ;
V_471 -> V_475 = true ;
V_471 -> V_476 = false ;
V_471 -> V_132 = V_477 ;
V_471 -> V_478 = F_152 ( V_479 ) ;
V_471 -> V_480 = F_152 ( V_481 ) ;
V_471 -> V_482 = V_483 ;
V_471 -> V_484 = V_485 ;
V_471 -> V_193 = V_19 -> V_129 . V_193 ;
V_471 -> V_308 = V_19 -> V_129 . V_308 ;
V_471 -> V_486 = F_152 ( V_19 -> V_129 . V_145 ) ;
V_471 -> V_198 = F_152 ( V_19 -> V_129 . V_198 ) ;
V_471 -> V_148 = F_152 ( V_19 -> V_129 . V_148 ) ;
V_471 -> V_487 = F_152 ( V_19 -> V_129 . V_145 ) ;
V_471 -> V_488 = F_152 ( V_19 -> V_129 . V_145 ) ;
V_471 -> V_489 = F_152 ( 2 * V_19 -> V_129 . V_191 ) ;
V_471 -> V_490 = F_152 ( V_19 -> V_129 . V_148 ) ;
V_471 -> V_491 = F_152 ( V_19 -> V_129 . V_145 ) ;
V_471 -> V_492 = F_152 ( V_19 -> V_129 . V_199 ) ;
V_471 -> V_159 = F_152 ( V_19 -> V_129 . V_159 <<
V_19 -> V_129 . V_308 ) ;
V_471 -> V_493 = 0 ;
V_471 -> V_494 = F_152 ( ( ( T_3 ) V_19 -> V_129 . V_191 ) ) ;
if ( V_19 -> V_56 < V_108 ) {
V_471 -> V_495 = true ;
V_471 -> V_496 = F_153 ( V_19 -> V_56 ) ;
}
if ( V_19 -> V_55 ) {
V_471 -> V_497 = F_153 ( V_19 -> V_38 ) ;
V_471 -> V_315 = F_153 ( V_19 -> V_39 ) ;
V_471 -> V_498 = F_152 ( V_19 -> V_43 [ 0 ] ) ;
V_471 -> V_499 = F_152 ( V_19 -> V_42 [ 0 ] ) ;
V_471 -> V_500 =
F_153 ( ( T_2 ) F_109 (
V_172 -> V_173 ,
& V_471 -> V_498 ,
true ,
NULL ,
V_394 ) ) ;
} else {
V_471 -> V_497 = F_153 ( V_19 -> V_38 ) ;
V_471 -> V_315 = F_153 ( V_19 -> V_39 ) ;
V_471 -> V_501 = F_152 ( V_19 -> V_43 [ 0 ] ) ;
V_471 -> V_502 = F_152 ( V_19 -> V_43 [ 1 ] ) ;
V_471 -> V_503 = F_152 ( V_19 -> V_43 [ 2 ] ) ;
V_471 -> V_498 = F_152 ( V_19 -> V_43 [ 3 ] ) ;
V_471 -> V_504 = F_152 ( V_19 -> V_42 [ 0 ] ) ;
V_471 -> V_505 = F_152 ( V_19 -> V_42 [ 1 ] ) ;
V_471 -> V_506 = F_152 ( V_19 -> V_42 [ 2 ] ) ;
V_471 -> V_499 = F_152 ( V_19 -> V_42 [ 3 ] ) ;
V_471 -> V_500 =
F_153 ( ( T_2 ) F_109 (
V_172 -> V_173 ,
& V_471 -> V_501 ,
false ,
NULL ,
V_394 ) ) ;
}
}
static void F_154 ( struct V_171 * V_172 ,
struct V_18 * V_19 )
{
struct V_470 V_471 ;
struct V_507 * V_508 ;
struct V_509 * V_510 ;
struct V_325 * V_173 = V_172 -> V_173 ;
struct V_1 * V_2 = & V_172 -> V_173 -> V_332 ;
memset ( & V_471 , 0x00 , sizeof( struct V_470 ) ) ;
V_508 = & V_172 -> V_508 ;
V_510 = & V_172 -> V_510 ;
V_510 -> V_471 = & V_471 ;
V_510 -> V_511 = V_172 -> V_512 -> V_513 . V_514 . V_515 ;
V_510 -> V_516 = V_172 -> V_517 -> V_513 . V_514 . V_515 ;
V_508 -> V_25 = V_19 -> V_25 ;
V_508 -> V_24 = F_4 ( V_19 -> V_24 ) ;
if ( V_508 -> V_25 == 1 )
V_508 -> V_25 = 2 ;
V_508 -> V_518 = true ;
V_508 -> V_519 = 1 ;
V_508 -> V_520 = 1 ;
V_508 -> V_521 = V_172 -> V_522 -> V_523 . V_521 ;
V_510 -> V_524 = true ;
V_510 -> V_525 = true ;
F_151 ( V_19 , & V_471 , V_172 ) ;
if ( V_19 -> V_250 ) {
V_508 -> V_250 = true ;
V_508 -> V_526 = ( V_471 . V_486 &
V_527 ) + V_19 -> V_528 ;
}
V_19 -> V_167 = V_297 ;
V_471 . V_484 = V_485 ;
V_471 . V_529 = V_173 -> V_530 ;
V_2 -> V_531 -> V_532 ( & V_172 -> V_533 , ( V_534 * ) ( V_172 -> V_535 . V_106 ) , V_510 ) ;
V_510 -> V_524 = false ;
V_510 -> V_525 = false ;
}
int F_53 ( struct V_171 * V_172 )
{
struct V_536 * V_537 ;
struct V_325 * V_173 = V_172 -> V_173 ;
struct V_254 * V_164 = & V_173 -> V_164 ;
V_537 = F_18 ( sizeof( * V_537 ) , V_79 ) ;
if ( ! V_537 )
return - V_237 ;
F_155 ( & V_172 -> V_415 ) ;
V_537 -> V_172 = V_172 ;
F_156 ( & V_537 -> V_537 , V_538 ) ;
F_157 ( V_164 -> V_469 , & V_537 -> V_537 ) ;
return 0 ;
}
static void F_158 ( struct V_171 * V_172 )
{
struct V_325 * V_173 ;
struct V_539 * V_540 ;
V_173 = F_159 ( V_172 -> V_415 . V_541 ) ;
if ( ! V_173 ) {
F_16 ( L_57 ) ;
return;
}
V_540 = V_173 -> V_540 ;
if ( V_172 -> V_542 ) {
V_172 -> V_542 = 0 ;
} else {
if ( V_172 -> V_543 . V_106 ) {
if ( V_172 -> V_544 )
V_540 -> V_545 . V_546 ( V_172 -> V_544 ) ;
F_160 ( V_173 -> V_332 . V_547 , & V_172 -> V_543 ) ;
}
}
if ( V_172 -> V_19 ) {
F_19 ( & V_173 -> V_332 , V_80 , L_58 , V_166 ) ;
F_142 ( V_172 -> V_19 ) ;
}
}
static void F_161 ( struct V_171 * V_172 )
{
struct V_57 * V_58 ;
struct V_325 * V_173 ;
struct V_548 * V_549 = & V_172 -> V_533 ;
T_2 V_550 ;
T_1 V_551 ;
T_1 V_552 ;
int V_553 = 0 ;
int V_554 = 0 ;
int V_555 = 0 ;
int V_556 = 0 ;
struct V_557 V_558 ;
unsigned long V_85 ;
int V_256 ;
if ( ! V_172 ) {
F_16 ( L_59 ) ;
return;
}
F_25 ( & V_172 -> V_277 , V_85 ) ;
V_58 = V_172 -> V_58 ;
if ( ! V_58 ) {
F_26 ( & V_172 -> V_277 , V_85 ) ;
return;
}
V_173 = F_159 ( V_172 -> V_415 . V_541 ) ;
V_551 = V_172 -> V_278 ;
V_552 = V_172 -> V_284 ;
V_550 = V_172 -> V_282 ;
if ( V_549 -> V_559 ) {
V_554 = 1 ;
V_555 = 1 ;
V_172 -> V_58 = NULL ;
F_162 ( & V_172 -> V_560 ) ;
if ( ! V_172 -> V_561 ) {
V_172 -> V_561 = 1 ;
V_556 = 1 ;
}
} else if ( ( V_551 == V_562 ) ||
( ( V_552 == V_563 ) &&
( V_550 == V_564 ) ) ) {
V_554 = 1 ;
if ( V_550 == V_564 )
V_553 = - V_174 ;
}
if ( ( ( V_551 == V_279 ) ||
( V_551 == V_565 ) ||
( V_550 == V_566 ) ||
( V_550 == V_564 ) ) ) {
V_555 = 1 ;
V_172 -> V_58 = NULL ;
if ( ! V_172 -> V_561 ) {
V_172 -> V_561 = 1 ;
V_556 = 1 ;
}
}
F_26 ( & V_172 -> V_277 , V_85 ) ;
if ( V_556 && ! V_172 -> V_567 ) {
F_163 ( V_173 , V_172 ) ;
if ( V_549 -> V_559 ) {
V_558 . V_541 = V_172 -> V_415 . V_541 ;
V_558 . V_29 = ( V_549 -> V_568 == V_569 ) ?
V_570 : V_571 ;
V_558 . V_572 . V_549 = & V_172 -> V_415 ;
V_172 -> V_415 . V_76 ( & V_558 , V_172 -> V_415 . V_573 ) ;
}
}
if ( V_58 && V_58 -> V_76 ) {
if ( V_554 ) {
V_256 = F_15 ( NULL ,
V_58 ,
V_74 ,
V_553 ) ;
if ( V_256 )
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_60 ,
V_166 , V_58 ) ;
}
if ( V_555 ) {
F_158 ( V_172 ) ;
V_58 -> V_71 = V_172 ;
V_256 = F_15 ( NULL , V_58 , V_75 , 0 ) ;
if ( V_256 )
F_19 ( & V_173 -> V_332 ,
V_80 ,
L_61 ,
V_166 , V_58 ) ;
V_58 -> V_175 ( V_58 ) ;
}
}
}
static void V_538 ( struct V_574 * V_537 )
{
struct V_536 * V_575 = F_57 ( V_537 , struct V_536 , V_537 ) ;
struct V_171 * V_172 = V_575 -> V_172 ;
F_22 ( V_575 ) ;
F_161 ( V_172 ) ;
F_126 ( & V_172 -> V_415 ) ;
}
int F_164 ( struct V_57 * V_58 , struct V_576 * V_577 )
{
struct V_578 * V_415 ;
struct V_171 * V_172 ;
struct V_325 * V_173 ;
struct V_1 * V_2 ;
struct V_18 * V_19 ;
struct V_579 V_580 ;
int V_423 ;
struct V_581 * V_582 ;
struct V_583 * V_522 ;
T_2 V_584 = 0 ;
struct V_88 V_585 ;
enum V_324 V_69 ;
V_534 V_586 ;
memset ( & V_580 , 0 , sizeof( V_580 ) ) ;
V_415 = F_165 ( V_58 -> V_541 , V_577 -> V_587 ) ;
if ( ! V_415 )
return - V_267 ;
V_172 = F_166 ( V_415 ) ;
V_173 = V_172 -> V_173 ;
V_2 = & V_173 -> V_332 ;
V_19 = (struct V_18 * ) V_58 -> V_71 ;
if ( ( (struct V_30 * ) & V_58 -> V_32 ) -> V_35 == V_36 ) {
V_19 -> V_55 = true ;
V_19 -> V_56 = F_82 ( V_19 -> V_42 ) ;
} else {
V_19 -> V_55 = false ;
F_74 ( V_19 -> V_42 , & V_19 -> V_56 , NULL ) ;
}
F_19 ( V_19 -> V_2 ,
V_80 ,
L_62 ,
V_19 -> V_56 ) ;
if ( V_19 -> V_167 == V_369 ) {
if ( V_19 -> V_368 )
F_37 ( V_19 -> V_368 ) ;
F_37 ( V_19 ) ;
return - V_267 ;
}
V_423 = F_129 ( 1 , & V_19 -> V_423 ) ;
if ( V_423 == V_457 ) {
F_37 ( V_19 ) ;
return - V_174 ;
}
V_19 -> V_164 -> V_588 ++ ;
V_172 -> V_19 = ( void * ) V_19 ;
V_19 -> V_172 = V_172 ;
V_584 = V_577 -> V_63 + V_589 + V_107 ;
V_69 = F_167 ( V_2 -> V_547 , & V_172 -> V_543 , V_584 , 1 ) ;
if ( V_69 )
return - V_237 ;
V_19 -> V_64 . V_65 = V_577 -> V_63 ;
V_585 . V_161 = V_172 -> V_543 . V_106 ;
V_585 . V_65 = F_44 ( V_19 , & V_585 , V_208 ) ;
memcpy ( V_585 . V_161 + V_585 . V_65 , V_577 -> V_61 ,
V_577 -> V_63 ) ;
if ( ( V_19 -> V_55 &&
! F_118 ( V_19 -> V_42 [ 0 ] , V_19 -> V_43 [ 0 ] ) ) ||
( ! V_19 -> V_55 &&
! F_120 ( V_19 -> V_42 , V_19 -> V_43 ) ) ) {
V_522 = V_172 -> V_522 ;
V_586 = ( V_590 ) V_172 -> V_543 . V_106 ;
V_582 = F_168 ( & V_522 -> V_591 ,
V_172 -> V_543 . V_592 ,
V_584 ,
V_593 ,
& V_586 ) ;
if ( F_103 ( V_582 ) ) {
F_160 ( V_2 -> V_547 , & V_172 -> V_543 ) ;
return - V_237 ;
}
V_582 -> V_594 = & V_522 -> V_591 ;
V_582 -> V_541 = V_522 -> V_591 . V_541 ;
V_172 -> V_544 = V_582 ;
if ( V_172 -> V_595 )
V_172 -> V_533 . V_596 . V_597 = F_169 ( V_172 -> V_595 ) ;
if ( F_27 ( V_19 ) )
V_2 -> V_531 -> V_598 (
& V_172 -> V_533 ,
V_172 -> V_543 . V_106 ,
( V_585 . V_65 + V_577 -> V_63 ) ,
V_582 -> V_599 ) ;
else
V_2 -> V_531 -> V_598 (
& V_172 -> V_533 ,
V_172 -> V_543 . V_106 ,
( V_585 . V_65 + V_577 -> V_63 + V_107 ) ,
V_582 -> V_599 ) ;
} else {
if ( V_172 -> V_595 )
V_172 -> V_533 . V_596 . V_597 = F_169 ( V_172 -> V_595 ) ;
V_2 -> V_531 -> V_598 ( & V_172 -> V_533 , NULL , 0 , 0 ) ;
}
if ( V_172 -> V_595 )
F_170 ( V_172 -> V_595 ) ;
V_172 -> V_58 = V_58 ;
V_19 -> V_58 = V_58 ;
V_58 -> V_71 = ( void * ) V_172 ;
V_172 -> V_542 = 0 ;
V_19 -> V_528 = V_585 . V_65 + V_577 -> V_63 ;
F_154 ( V_172 , V_19 ) ;
V_58 -> V_458 ( V_58 ) ;
F_155 ( & V_172 -> V_415 ) ;
F_15 ( V_19 , V_58 , V_73 , 0 ) ;
V_580 . V_600 = V_563 ;
V_19 -> V_372 = false ;
F_171 ( & V_172 -> V_415 , & V_580 , V_601 , NULL ) ;
if ( V_19 -> V_368 ) {
V_19 -> V_368 -> V_64 . V_65 = V_577 -> V_63 ;
memcpy ( V_19 -> V_368 -> V_62 ,
V_577 -> V_61 ,
V_577 -> V_63 ) ;
F_17 ( V_19 -> V_368 , V_434 ) ;
}
V_19 -> V_366 = 1 ;
if ( V_19 -> V_412 ) {
if ( ! V_19 -> V_356 )
F_16 ( L_63 ) ;
F_23 ( & V_19 -> V_356 -> V_374 ) ;
V_19 -> V_412 = 0 ;
}
return 0 ;
}
int F_172 ( struct V_57 * V_58 , const void * V_64 , T_1 V_602 )
{
struct V_325 * V_173 ;
struct V_18 * V_19 ;
struct V_18 * V_364 ;
V_19 = (struct V_18 * ) V_58 -> V_71 ;
V_364 = V_19 -> V_368 ;
V_19 -> V_58 = V_58 ;
V_19 -> V_64 . V_65 = V_602 ;
V_173 = F_159 ( V_58 -> V_541 ) ;
if ( ! V_173 )
return - V_267 ;
V_19 -> V_164 -> V_603 ++ ;
if ( V_602 + sizeof( struct V_214 ) > V_246 )
return - V_267 ;
if ( V_364 ) {
memcpy ( & V_364 -> V_62 , V_64 , V_602 ) ;
V_364 -> V_64 . V_65 = V_602 ;
}
return F_141 ( V_19 , V_64 , V_602 ) ;
}
int F_173 ( struct V_57 * V_58 , struct V_576 * V_577 )
{
struct V_578 * V_415 ;
struct V_171 * V_172 ;
struct V_325 * V_173 ;
struct V_18 * V_19 ;
struct V_53 V_54 ;
struct V_30 * V_31 ;
struct V_30 * V_33 ;
struct V_44 * V_45 ;
struct V_44 * V_46 ;
bool V_372 = false ;
int V_413 = 0 ;
enum V_324 V_69 ;
V_415 = F_165 ( V_58 -> V_541 , V_577 -> V_587 ) ;
if ( ! V_415 )
return - V_267 ;
V_172 = F_166 ( V_415 ) ;
if ( ! V_172 )
return - V_267 ;
V_173 = F_159 ( V_172 -> V_415 . V_541 ) ;
if ( ! V_173 )
return - V_267 ;
V_31 = (struct V_30 * ) & V_58 -> V_59 ;
V_33 = (struct V_30 * ) & V_58 -> V_60 ;
V_45 = (struct V_44 * ) & V_58 -> V_59 ;
V_46 = (struct V_44 * ) & V_58 -> V_60 ;
if ( ! ( V_31 -> V_37 ) || ! ( V_33 -> V_37 ) )
return - V_267 ;
V_172 -> V_542 = 1 ;
V_172 -> V_58 = NULL ;
V_58 -> V_71 = V_172 ;
if ( V_58 -> V_34 . V_604 == V_36 ) {
V_54 . V_55 = true ;
memset ( V_54 . V_42 , 0 , sizeof( V_54 . V_42 ) ) ;
memset ( V_54 . V_43 , 0 , sizeof( V_54 . V_43 ) ) ;
V_54 . V_42 [ 0 ] = F_7 ( V_31 -> V_40 . V_41 ) ;
V_54 . V_43 [ 0 ] = F_7 ( V_33 -> V_40 . V_41 ) ;
V_54 . V_38 = F_40 ( V_31 -> V_37 ) ;
V_54 . V_39 = F_40 ( V_33 -> V_37 ) ;
V_54 . V_56 = F_82 ( V_54 . V_42 ) ;
} else {
V_54 . V_55 = false ;
F_6 ( V_54 . V_42 ,
V_45 -> V_50 . V_51 . V_52 ) ;
F_6 ( V_54 . V_43 ,
V_46 -> V_50 . V_51 . V_52 ) ;
V_54 . V_38 = F_40 ( V_45 -> V_49 ) ;
V_54 . V_39 = F_40 ( V_46 -> V_49 ) ;
F_74 ( V_54 . V_42 , & V_54 . V_56 , NULL ) ;
}
V_54 . V_58 = V_58 ;
if ( ( V_54 . V_55 && ( V_31 -> V_40 . V_41 != V_33 -> V_40 . V_41 ) ) ||
( ! V_54 . V_55 && memcmp ( V_45 -> V_50 . V_51 . V_52 ,
V_46 -> V_50 . V_51 . V_52 ,
sizeof( V_45 -> V_50 . V_51 . V_52 ) ) ) ) {
V_69 = F_73 ( V_173 ,
& V_54 ,
V_414 ,
V_351 ,
NULL ,
true ) ;
if ( V_69 )
return - V_267 ;
V_372 = true ;
}
V_69 = F_97 ( V_173 , V_54 . V_38 , V_605 ) ;
if ( V_69 ) {
F_73 ( V_173 ,
& V_54 ,
V_414 ,
V_334 ,
NULL ,
false ) ;
return - V_267 ;
}
V_413 = 1 ;
V_58 -> V_458 ( V_58 ) ;
V_19 = F_140 ( & V_173 -> V_164 , V_173 ,
V_577 -> V_63 ,
( void * ) V_577 -> V_61 ,
& V_54 ) ;
if ( ! V_19 )
goto V_359;
F_5 ( V_19 , ( T_2 ) V_577 -> V_66 , ( T_2 ) V_577 -> V_67 ) ;
if ( V_19 -> V_227 == V_229 &&
! V_19 -> V_25 )
V_19 -> V_25 = 1 ;
V_19 -> V_413 = V_413 ;
V_19 -> V_372 = V_372 ;
V_172 -> V_19 = V_19 ;
V_19 -> V_172 = V_172 ;
V_172 -> V_58 = V_58 ;
F_155 ( & V_172 -> V_415 ) ;
if ( V_19 -> V_167 == V_417 ) {
if ( F_61 ( V_19 , 0 ) ) {
F_37 ( V_19 ) ;
goto V_359;
}
}
F_19 ( V_19 -> V_2 ,
V_80 ,
L_64 ,
V_19 -> V_39 ,
V_19 ,
V_19 -> V_58 ) ;
return 0 ;
V_359:
if ( V_19 ) {
if ( V_19 -> V_55 )
F_19 ( V_19 -> V_2 ,
V_80 ,
L_65 ,
V_19 -> V_43 ) ;
else
F_19 ( V_19 -> V_2 , V_80 ,
L_66 ,
V_19 -> V_43 ) ;
}
F_73 ( V_173 ,
& V_54 ,
V_414 ,
V_334 ,
NULL ,
false ) ;
if ( V_413 && ! F_69 ( & V_173 -> V_164 ,
V_54 . V_38 ) )
F_97 ( V_173 ,
V_54 . V_38 ,
V_371 ) ;
V_58 -> V_175 ( V_58 ) ;
V_173 -> V_164 . V_165 ++ ;
return - V_237 ;
}
int F_174 ( struct V_57 * V_58 , int V_436 )
{
struct V_325 * V_173 ;
struct V_313 * V_606 ;
struct V_53 V_54 ;
enum V_324 V_256 ;
struct V_30 * V_31 ;
struct V_44 * V_45 ;
bool V_607 = false ;
V_173 = F_159 ( V_58 -> V_541 ) ;
if ( ! V_173 )
return - V_267 ;
V_31 = (struct V_30 * ) & V_58 -> V_59 ;
V_45 = (struct V_44 * ) & V_58 -> V_59 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
if ( V_31 -> V_35 == V_36 ) {
V_54 . V_55 = true ;
V_54 . V_42 [ 0 ] = F_7 ( V_31 -> V_40 . V_41 ) ;
V_54 . V_38 = F_40 ( V_31 -> V_37 ) ;
if ( V_31 -> V_40 . V_41 != V_608 )
V_54 . V_56 = F_82 ( V_54 . V_42 ) ;
else
V_607 = true ;
} else {
V_54 . V_55 = false ;
F_6 ( V_54 . V_42 ,
V_45 -> V_50 . V_51 . V_52 ) ;
V_54 . V_38 = F_40 ( V_45 -> V_49 ) ;
if ( F_114 ( & V_45 -> V_50 ) != V_609 )
F_74 ( V_54 . V_42 ,
& V_54 . V_56 ,
NULL ) ;
else
V_607 = true ;
}
V_54 . V_436 = V_436 ;
V_54 . V_58 = V_58 ;
V_606 = F_139 ( & V_173 -> V_164 , V_173 , & V_54 ) ;
if ( ! V_606 ) {
F_16 ( L_67 ) ;
return - V_237 ;
}
V_58 -> V_71 = V_606 ;
if ( ! V_606 -> V_450 ) {
if ( V_607 ) {
if ( V_54 . V_55 )
V_256 = F_90 ( V_173 ,
& V_54 ,
V_606 ) ;
else
V_256 = F_85 ( V_173 ,
& V_54 ,
V_606 ) ;
if ( V_256 )
goto error;
V_256 = F_97 ( V_173 ,
V_54 . V_38 ,
V_605 ) ;
if ( V_256 )
goto error;
} else {
V_256 = F_73 ( V_173 ,
& V_54 ,
V_333 ,
V_351 ,
NULL ,
true ) ;
if ( V_256 )
goto error;
V_606 -> V_372 = true ;
V_256 = F_97 ( V_173 ,
V_54 . V_38 ,
V_605 ) ;
if ( V_256 )
goto error;
}
}
V_58 -> V_458 ( V_58 ) ;
V_606 -> V_164 -> V_610 ++ ;
return 0 ;
error:
F_100 ( & V_173 -> V_164 , ( void * ) V_606 , false ) ;
return - V_267 ;
}
int F_175 ( struct V_57 * V_58 )
{
struct V_325 * V_173 ;
V_173 = F_159 ( V_58 -> V_541 ) ;
if ( V_58 -> V_71 )
F_100 ( & V_173 -> V_164 , V_58 -> V_71 , true ) ;
else
F_16 ( L_68 ) ;
V_58 -> V_175 ( V_58 ) ;
return 0 ;
}
static void F_176 ( struct V_77 * V_29 )
{
struct V_171 * V_172 ;
struct V_325 * V_173 ;
struct V_18 * V_19 ;
struct V_1 * V_2 ;
struct V_579 V_580 ;
struct V_57 * V_58 ;
int V_69 ;
bool V_611 ;
V_19 = V_29 -> V_19 ;
V_58 = V_19 -> V_58 ;
V_172 = (struct V_171 * ) V_58 -> V_71 ;
V_173 = F_159 ( V_172 -> V_415 . V_541 ) ;
V_2 = & V_173 -> V_332 ;
if ( V_172 -> V_567 ) {
V_69 = - V_612 ;
goto error;
}
F_154 ( V_172 , V_19 ) ;
V_611 = ( V_19 -> V_227 == V_229 ) ;
if ( V_172 -> V_595 )
V_172 -> V_533 . V_596 . V_597 = F_169 ( V_172 -> V_595 ) ;
V_2 -> V_531 -> V_613 ( & V_172 -> V_533 , V_611 ) ;
if ( V_172 -> V_595 )
F_170 ( V_172 -> V_595 ) ;
V_69 = F_15 ( V_19 , V_58 , V_72 , 0 ) ;
if ( V_69 )
F_16 ( L_69 ) ;
memset ( & V_580 , 0 , sizeof( V_580 ) ) ;
V_580 . V_600 = V_563 ;
V_19 -> V_372 = false ;
F_171 ( & V_172 -> V_415 , & V_580 , V_601 , NULL ) ;
V_19 -> V_366 = 1 ;
if ( V_19 -> V_412 ) {
if ( ! V_19 -> V_356 )
F_16 ( L_70 ) ;
F_23 ( & V_19 -> V_356 -> V_374 ) ;
V_19 -> V_412 = 0 ;
}
return;
error:
V_172 -> V_58 = NULL ;
V_58 -> V_71 = NULL ;
F_15 ( V_29 -> V_19 ,
V_58 ,
V_72 ,
V_69 ) ;
V_58 -> V_175 ( V_58 ) ;
F_37 ( V_29 -> V_19 ) ;
}
static void F_177 ( struct V_77 * V_29 )
{
struct V_18 * V_19 = V_29 -> V_19 ;
struct V_57 * V_58 = V_19 -> V_58 ;
struct V_171 * V_172 ;
if ( ! V_58 )
return;
V_172 = V_58 -> V_71 ;
if ( ! V_172 )
return;
F_19 ( V_19 -> V_2 ,
V_80 ,
L_71 ,
V_29 -> V_19 , V_58 ) ;
V_172 -> V_58 = NULL ;
F_15 ( V_19 , V_19 -> V_58 , V_74 , - V_174 ) ;
F_15 ( V_19 , V_19 -> V_58 , V_75 , 0 ) ;
}
static void F_178 ( struct V_574 * V_537 )
{
struct V_77 * V_29 = F_57 ( V_537 ,
struct V_77 ,
V_614 ) ;
struct V_18 * V_19 ;
if ( ! V_29 || ! V_29 -> V_19 || ! V_29 -> V_19 -> V_164 )
return;
V_19 = V_29 -> V_19 ;
switch ( V_29 -> type ) {
case V_431 :
F_15 ( V_19 ,
V_19 -> V_58 ,
V_70 ,
0 ) ;
break;
case V_615 :
F_177 ( V_29 ) ;
break;
case V_434 :
if ( ! V_29 -> V_19 -> V_58 ||
( V_29 -> V_19 -> V_167 != V_297 ) )
break;
F_176 ( V_29 ) ;
break;
case V_433 :
if ( ! V_29 -> V_19 -> V_58 ||
( V_19 -> V_167 == V_297 ) )
break;
F_15 ( V_19 ,
V_19 -> V_58 ,
V_72 ,
- V_459 ) ;
break;
case V_169 :
if ( ! V_29 -> V_19 -> V_58 ||
( V_29 -> V_19 -> V_167 == V_297 ) )
break;
F_38 ( V_29 ) ;
break;
default:
F_16 ( L_72 , V_29 -> type ) ;
break;
}
V_29 -> V_54 . V_58 -> V_175 ( V_29 -> V_54 . V_58 ) ;
F_37 ( V_29 -> V_19 ) ;
F_22 ( V_29 ) ;
}
static void F_20 ( struct V_77 * V_29 )
{
F_35 ( & V_29 -> V_19 -> V_84 ) ;
V_29 -> V_54 . V_58 -> V_458 ( V_29 -> V_54 . V_58 ) ;
F_156 ( & V_29 -> V_614 , F_178 ) ;
F_157 ( V_29 -> V_19 -> V_164 -> V_468 , & V_29 -> V_614 ) ;
}
