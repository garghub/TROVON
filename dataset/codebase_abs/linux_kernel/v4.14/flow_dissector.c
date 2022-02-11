static void F_1 ( struct V_1 * V_1 ,
enum V_2 V_3 )
{
V_1 -> V_4 |= ( 1 << V_3 ) ;
}
void F_2 ( struct V_1 * V_1 ,
const struct V_5 * V_6 ,
unsigned int V_7 )
{
unsigned int V_8 ;
memset ( V_1 , 0 , sizeof( * V_1 ) ) ;
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ , V_6 ++ ) {
F_3 ( V_6 -> V_9 > V_10 ) ;
F_3 ( F_4 ( V_1 ,
V_6 -> V_3 ) ) ;
F_1 ( V_1 , V_6 -> V_3 ) ;
V_1 -> V_9 [ V_6 -> V_3 ] = V_6 -> V_9 ;
}
F_3 ( ! F_4 ( V_1 ,
V_11 ) ) ;
F_3 ( ! F_4 ( V_1 ,
V_12 ) ) ;
}
static T_1 F_5 ( const struct V_13 * V_14 , int V_15 ,
void * V_16 , int V_17 )
{
T_1 * V_18 , V_19 ;
V_18 = F_6 ( V_14 , V_15 , sizeof( V_19 ) , V_16 , V_17 , & V_19 ) ;
if ( V_18 )
return * V_18 ;
return 0 ;
}
T_2 F_7 ( const struct V_13 * V_14 , int V_20 , T_3 V_21 ,
void * V_16 , int V_17 )
{
int V_15 = F_8 ( V_21 ) ;
if ( ! V_16 ) {
V_16 = V_14 -> V_16 ;
V_17 = F_9 ( V_14 ) ;
}
if ( V_15 >= 0 ) {
T_2 * V_22 , V_23 ;
V_22 = F_6 ( V_14 , V_20 + V_15 ,
sizeof( V_23 ) , V_16 , V_17 , & V_23 ) ;
if ( V_22 )
return * V_22 ;
}
return 0 ;
}
static enum V_24
F_10 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 , void * V_16 , int V_26 , int V_17 )
{
struct V_27 * V_28 ;
struct V_29 * V_30 , V_31 [ 2 ] ;
T_4 V_32 , V_33 ;
if ( ! F_4 ( V_1 ,
V_34 ) &&
! F_4 ( V_1 , V_35 ) )
return V_36 ;
V_30 = F_6 ( V_14 , V_26 , sizeof( V_31 ) , V_16 ,
V_17 , & V_31 ) ;
if ( ! V_30 )
return V_37 ;
V_32 = F_11 ( V_30 [ 0 ] . V_32 ) ;
V_33 = ( V_32 & V_38 ) >> V_39 ;
if ( F_4 ( V_1 , V_35 ) ) {
struct V_40 * V_41 ;
V_41 = F_12 ( V_1 ,
V_35 ,
V_25 ) ;
V_41 -> V_29 = V_33 ;
V_41 -> V_42 = ( V_32 & V_43 )
>> V_44 ;
V_41 -> V_45 = ( V_32 & V_46 )
>> V_47 ;
V_41 -> V_48 = ( V_32 & V_49 )
>> V_50 ;
}
if ( V_33 == V_51 ) {
V_28 = F_12 ( V_1 ,
V_34 ,
V_25 ) ;
V_28 -> V_52 = V_30 [ 1 ] . V_32 & F_13 ( V_38 ) ;
}
return V_36 ;
}
static enum V_24
F_14 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 , void * V_16 , int V_26 , int V_17 )
{
struct V_53 * V_54 ;
struct {
unsigned char V_55 [ V_56 ] ;
unsigned char V_57 [ 4 ] ;
unsigned char V_58 [ V_56 ] ;
unsigned char V_59 [ 4 ] ;
} * V_60 , V_61 ;
const struct V_62 * V_63 ;
struct V_62 V_64 ;
if ( ! F_4 ( V_1 , V_65 ) )
return V_36 ;
V_63 = F_6 ( V_14 , V_26 , sizeof( V_64 ) , V_16 ,
V_17 , & V_64 ) ;
if ( ! V_63 )
return V_37 ;
if ( V_63 -> V_66 != F_15 ( V_67 ) ||
V_63 -> V_68 != F_15 ( V_69 ) ||
V_63 -> V_70 != V_56 ||
V_63 -> V_71 != 4 ||
( V_63 -> V_72 != F_15 ( V_73 ) &&
V_63 -> V_72 != F_15 ( V_74 ) ) )
return V_37 ;
V_60 = F_6 ( V_14 , V_26 + sizeof( V_64 ) ,
sizeof( V_61 ) , V_16 ,
V_17 , & V_61 ) ;
if ( ! V_60 )
return V_37 ;
V_54 = F_12 ( V_1 ,
V_65 ,
V_25 ) ;
memcpy ( & V_54 -> V_75 , V_60 -> V_57 , sizeof( V_54 -> V_75 ) ) ;
memcpy ( & V_54 -> V_76 , V_60 -> V_59 , sizeof( V_54 -> V_76 ) ) ;
V_54 -> V_77 = F_16 ( V_63 -> V_72 ) & 0xff ;
F_17 ( V_54 -> V_78 , V_60 -> V_55 ) ;
F_17 ( V_54 -> V_79 , V_60 -> V_58 ) ;
return V_36 ;
}
static enum V_24
F_18 ( const struct V_13 * V_14 ,
struct V_80 * V_81 ,
struct V_1 * V_1 ,
void * V_25 , void * V_16 ,
T_1 * V_82 , int * V_83 , int * V_84 ,
unsigned int V_85 )
{
struct V_27 * V_28 ;
struct V_86 * V_30 , V_31 ;
int V_9 = 0 ;
T_5 V_87 ;
V_30 = F_6 ( V_14 , * V_83 , sizeof( V_31 ) ,
V_16 , * V_84 , & V_31 ) ;
if ( ! V_30 )
return V_37 ;
if ( V_30 -> V_85 & V_88 )
return V_36 ;
V_87 = F_16 ( V_30 -> V_85 & V_89 ) ;
if ( V_87 > 1 )
return V_36 ;
* V_82 = V_30 -> V_90 ;
if ( V_87 ) {
if ( ! ( * V_82 == V_91 && ( V_30 -> V_85 & V_92 ) ) )
return V_36 ;
}
V_9 += sizeof( struct V_86 ) ;
if ( V_30 -> V_85 & V_93 )
V_9 += sizeof( ( (struct V_94 * ) 0 ) -> V_95 ) +
sizeof( ( (struct V_94 * ) 0 ) -> V_96 ) ;
if ( V_30 -> V_85 & V_92 ) {
const T_2 * V_52 ;
T_2 V_97 ;
V_52 = F_6 ( V_14 , * V_83 + V_9 ,
sizeof( V_97 ) ,
V_16 , * V_84 , & V_97 ) ;
if ( ! V_52 )
return V_37 ;
if ( F_4 ( V_1 ,
V_98 ) ) {
V_28 = F_12 ( V_1 ,
V_98 ,
V_25 ) ;
if ( V_87 == 0 )
V_28 -> V_52 = * V_52 ;
else
V_28 -> V_52 = * V_52 & V_99 ;
}
V_9 += sizeof( ( (struct V_94 * ) 0 ) -> V_6 ) ;
}
if ( V_30 -> V_85 & V_100 )
V_9 += sizeof( ( (struct V_101 * ) 0 ) -> V_102 ) ;
if ( V_87 == 0 ) {
if ( * V_82 == F_15 ( V_103 ) ) {
const struct V_104 * V_105 ;
struct V_104 V_106 ;
V_105 = F_6 ( V_14 , * V_83 + V_9 ,
sizeof( V_106 ) ,
V_16 , * V_84 , & V_106 ) ;
if ( ! V_105 )
return V_37 ;
* V_82 = V_105 -> V_107 ;
V_9 += sizeof( * V_105 ) ;
if ( V_108 )
* V_84 = * V_83 + V_9 ;
}
} else {
T_3 V_109 [ V_110 ] ;
T_3 * V_111 ;
if ( V_30 -> V_85 & V_112 )
V_9 += sizeof( ( (struct V_101 * ) 0 ) -> V_113 ) ;
V_111 = F_6 ( V_14 , * V_83 + V_9 ,
sizeof( V_109 ) ,
V_16 , * V_84 , V_109 ) ;
if ( ! V_111 )
return V_37 ;
switch ( F_19 ( V_111 ) ) {
case V_114 :
* V_82 = F_15 ( V_69 ) ;
break;
case V_115 :
* V_82 = F_15 ( V_116 ) ;
break;
default:
break;
}
V_9 += V_110 ;
}
* V_83 += V_9 ;
V_81 -> V_85 |= V_117 ;
if ( V_85 & V_118 )
return V_36 ;
return V_119 ;
}
static void
F_20 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 , void * V_16 , int V_20 , int V_17 )
{
struct V_120 * V_121 ;
struct V_122 * V_123 , V_124 ;
if ( ! F_4 ( V_1 , V_125 ) )
return;
V_123 = F_6 ( V_14 , V_20 , sizeof( V_124 ) , V_16 , V_17 , & V_124 ) ;
if ( ! V_123 )
return;
if ( F_21 ( F_22 ( V_123 ) < sizeof( V_124 ) ) )
return;
V_121 = F_12 ( V_1 ,
V_125 ,
V_25 ) ;
V_121 -> V_85 = ( * ( T_1 * ) & F_23 ( V_123 ) & F_15 ( 0x0FFF ) ) ;
}
static void
F_24 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 , void * V_16 , const struct V_126 * V_127 )
{
struct V_128 * V_129 ;
if ( ! F_4 ( V_1 , V_130 ) )
return;
V_129 = F_12 ( V_1 ,
V_130 ,
V_25 ) ;
V_129 -> V_131 = V_127 -> V_131 ;
V_129 -> V_132 = V_127 -> V_132 ;
}
static void
F_25 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 , void * V_16 , const struct V_133 * V_127 )
{
struct V_128 * V_129 ;
if ( ! F_4 ( V_1 , V_130 ) )
return;
V_129 = F_12 ( V_1 ,
V_130 ,
V_25 ) ;
V_129 -> V_131 = F_26 ( V_127 ) ;
V_129 -> V_132 = V_127 -> V_134 ;
}
static bool F_27 ( int * V_135 )
{
++ * V_135 ;
return ( * V_135 <= V_136 ) ;
}
bool F_28 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 ,
void * V_16 , T_1 V_137 , int V_26 , int V_17 ,
unsigned int V_85 )
{
struct V_80 * V_81 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
struct V_148 * V_149 ;
enum V_24 V_150 ;
bool V_151 = false ;
int V_135 = 0 ;
T_3 V_21 = 0 ;
bool V_152 ;
if ( ! V_16 ) {
V_16 = V_14 -> V_16 ;
V_137 = F_29 ( V_14 ) ?
V_14 -> V_153 : V_14 -> V_90 ;
V_26 = F_30 ( V_14 ) ;
V_17 = F_9 ( V_14 ) ;
#if F_31 ( V_154 )
if ( F_21 ( V_14 -> V_155 && F_32 ( V_14 -> V_155 ) ) ) {
const struct V_156 * V_157 ;
int V_9 ;
V_157 = V_14 -> V_155 -> V_158 -> V_159 ;
if ( V_157 -> V_160 &&
! V_157 -> V_160 ( V_14 , & V_137 , & V_9 ) ) {
V_17 -= V_9 ;
V_26 += V_9 ;
}
}
#endif
}
V_81 = F_12 ( V_1 ,
V_11 ,
V_25 ) ;
V_139 = F_12 ( V_1 ,
V_12 ,
V_25 ) ;
if ( F_4 ( V_1 ,
V_161 ) ) {
struct V_104 * V_105 = F_33 ( V_14 ) ;
struct V_162 * V_163 ;
V_163 = F_12 ( V_1 ,
V_161 ,
V_25 ) ;
memcpy ( V_163 , & V_105 -> V_164 , sizeof( * V_163 ) ) ;
}
V_165:
V_150 = V_166 ;
switch ( V_137 ) {
case F_15 ( V_69 ) : {
const struct V_126 * V_127 ;
struct V_126 V_167 ;
V_127 = F_6 ( V_14 , V_26 , sizeof( V_167 ) , V_16 , V_17 , & V_167 ) ;
if ( ! V_127 || V_127 -> V_168 < 5 ) {
V_150 = V_37 ;
break;
}
V_26 += V_127 -> V_168 * 4 ;
V_21 = V_127 -> V_90 ;
if ( F_4 ( V_1 ,
V_169 ) ) {
V_141 = F_12 ( V_1 ,
V_169 ,
V_25 ) ;
memcpy ( & V_141 -> V_170 , & V_127 -> V_171 ,
sizeof( V_141 -> V_170 ) ) ;
V_81 -> V_172 = V_169 ;
}
if ( F_34 ( V_127 ) ) {
V_81 -> V_85 |= V_173 ;
if ( V_127 -> V_174 & F_15 ( V_175 ) ) {
V_150 = V_36 ;
break;
} else {
V_81 -> V_85 |= V_176 ;
if ( ! ( V_85 &
V_177 ) ) {
V_150 = V_36 ;
break;
}
}
}
F_24 ( V_14 , V_1 ,
V_25 , V_16 , V_127 ) ;
if ( V_85 & V_178 ) {
V_150 = V_36 ;
break;
}
break;
}
case F_15 ( V_116 ) : {
const struct V_133 * V_127 ;
struct V_133 V_167 ;
V_127 = F_6 ( V_14 , V_26 , sizeof( V_167 ) , V_16 , V_17 , & V_167 ) ;
if ( ! V_127 ) {
V_150 = V_37 ;
break;
}
V_21 = V_127 -> V_179 ;
V_26 += sizeof( struct V_133 ) ;
if ( F_4 ( V_1 ,
V_180 ) ) {
V_141 = F_12 ( V_1 ,
V_180 ,
V_25 ) ;
memcpy ( & V_141 -> V_181 , & V_127 -> V_171 ,
sizeof( V_141 -> V_181 ) ) ;
V_81 -> V_172 = V_180 ;
}
if ( ( F_4 ( V_1 ,
V_182 ) ||
( V_85 & V_183 ) ) &&
F_35 ( V_127 ) ) {
T_2 V_184 = F_35 ( V_127 ) ;
if ( F_4 ( V_1 ,
V_182 ) ) {
V_147 = F_12 ( V_1 ,
V_182 ,
V_25 ) ;
V_147 -> V_184 = F_11 ( V_184 ) ;
}
if ( V_85 & V_183 ) {
V_150 = V_36 ;
break;
}
}
F_25 ( V_14 , V_1 ,
V_25 , V_16 , V_127 ) ;
if ( V_85 & V_178 )
V_150 = V_36 ;
break;
}
case F_15 ( V_185 ) :
case F_15 ( V_186 ) : {
const struct V_187 * V_188 ;
struct V_187 V_189 ;
bool V_190 = V_14 && F_29 ( V_14 ) ;
if ( V_190 )
V_137 = V_14 -> V_90 ;
if ( ! V_190 || F_36 ( V_14 -> V_90 ) ) {
V_188 = F_6 ( V_14 , V_26 , sizeof( V_189 ) ,
V_16 , V_17 , & V_189 ) ;
if ( ! V_188 ) {
V_150 = V_37 ;
break;
}
V_137 = V_188 -> V_191 ;
V_26 += sizeof( * V_188 ) ;
if ( V_151 ) {
V_150 = V_119 ;
break;
}
}
V_151 = true ;
if ( F_4 ( V_1 ,
V_192 ) ) {
V_149 = F_12 ( V_1 ,
V_192 ,
V_25 ) ;
if ( V_190 ) {
V_149 -> V_193 = F_37 ( V_14 ) ;
V_149 -> V_194 =
( F_38 ( V_14 ) >> V_195 ) ;
} else {
V_149 -> V_193 = F_16 ( V_188 -> V_196 ) &
V_197 ;
V_149 -> V_194 =
( F_16 ( V_188 -> V_196 ) &
V_198 ) >> V_195 ;
}
}
V_150 = V_119 ;
break;
}
case F_15 ( V_199 ) : {
struct {
struct V_200 V_30 ;
T_1 V_137 ;
} * V_30 , V_31 ;
V_30 = F_6 ( V_14 , V_26 , sizeof( V_31 ) , V_16 , V_17 , & V_31 ) ;
if ( ! V_30 ) {
V_150 = V_37 ;
break;
}
V_137 = V_30 -> V_137 ;
V_26 += V_201 ;
switch ( V_137 ) {
case F_15 ( V_114 ) :
V_137 = F_15 ( V_69 ) ;
V_150 = V_119 ;
break;
case F_15 ( V_115 ) :
V_137 = F_15 ( V_116 ) ;
V_150 = V_119 ;
break;
default:
V_150 = V_37 ;
break;
}
break;
}
case F_15 ( V_202 ) : {
struct {
T_2 V_203 [ 3 ] ;
T_2 V_204 ;
} * V_30 , V_31 ;
V_30 = F_6 ( V_14 , V_26 , sizeof( V_31 ) , V_16 , V_17 , & V_31 ) ;
if ( ! V_30 ) {
V_150 = V_37 ;
break;
}
if ( F_4 ( V_1 ,
V_205 ) ) {
V_141 = F_12 ( V_1 ,
V_205 ,
V_25 ) ;
V_141 -> V_206 . V_204 = V_30 -> V_204 ;
V_81 -> V_172 = V_205 ;
}
V_150 = V_36 ;
break;
}
case F_15 ( V_207 ) :
case F_15 ( V_208 ) :
V_150 = F_10 ( V_14 , V_1 ,
V_25 , V_16 ,
V_26 , V_17 ) ;
break;
case F_15 ( V_209 ) :
if ( ( V_17 - V_26 ) < V_210 ) {
V_150 = V_37 ;
break;
}
V_26 += V_210 ;
V_150 = V_36 ;
break;
case F_15 ( V_211 ) :
case F_15 ( V_212 ) :
V_150 = F_14 ( V_14 , V_1 ,
V_25 , V_16 ,
V_26 , V_17 ) ;
break;
default:
V_150 = V_37 ;
break;
}
switch ( V_150 ) {
case V_36 :
goto V_213;
case V_119 :
if ( F_27 ( & V_135 ) )
goto V_165;
goto V_213;
case V_166 :
case V_214 :
break;
case V_37 :
default:
goto V_215;
}
V_216:
V_150 = V_166 ;
switch ( V_21 ) {
case V_217 :
V_150 = F_18 ( V_14 , V_81 , V_1 ,
V_25 , V_16 ,
& V_137 , & V_26 , & V_17 , V_85 ) ;
break;
case V_218 :
case V_219 :
case V_220 : {
T_3 V_221 [ 2 ] , * V_222 ;
if ( V_137 != F_15 ( V_116 ) )
break;
V_222 = F_6 ( V_14 , V_26 , sizeof( V_221 ) ,
V_16 , V_17 , & V_221 ) ;
if ( ! V_222 ) {
V_150 = V_37 ;
break;
}
V_21 = V_222 [ 0 ] ;
V_26 += ( V_222 [ 1 ] + 1 ) << 3 ;
V_150 = V_214 ;
break;
}
case V_223 : {
struct V_224 V_225 , * V_226 ;
if ( V_137 != F_15 ( V_116 ) )
break;
V_226 = F_6 ( V_14 , V_26 , sizeof( V_225 ) ,
V_16 , V_17 , & V_225 ) ;
if ( ! V_226 ) {
V_150 = V_37 ;
break;
}
V_81 -> V_85 |= V_173 ;
V_26 += sizeof( V_225 ) ;
V_21 = V_226 -> V_179 ;
if ( ! ( V_226 -> V_174 & F_15 ( V_227 ) ) ) {
V_81 -> V_85 |= V_176 ;
if ( V_85 & V_177 ) {
V_150 = V_214 ;
break;
}
}
V_150 = V_36 ;
break;
}
case V_228 :
V_137 = F_15 ( V_69 ) ;
V_81 -> V_85 |= V_117 ;
if ( V_85 & V_118 ) {
V_150 = V_36 ;
break;
}
V_150 = V_119 ;
break;
case V_229 :
V_137 = F_15 ( V_116 ) ;
V_81 -> V_85 |= V_117 ;
if ( V_85 & V_118 ) {
V_150 = V_36 ;
break;
}
V_150 = V_119 ;
break;
case V_230 :
V_137 = F_15 ( V_207 ) ;
V_150 = V_119 ;
break;
case V_231 :
F_20 ( V_14 , V_1 , V_25 ,
V_16 , V_26 , V_17 ) ;
break;
default:
break;
}
if ( F_4 ( V_1 ,
V_232 ) ) {
V_143 = F_12 ( V_1 ,
V_232 ,
V_25 ) ;
V_143 -> V_22 = F_7 ( V_14 , V_26 , V_21 ,
V_16 , V_17 ) ;
}
if ( F_4 ( V_1 ,
V_233 ) ) {
V_145 = F_12 ( V_1 ,
V_233 ,
V_25 ) ;
V_145 -> V_234 = F_5 ( V_14 , V_26 , V_16 , V_17 ) ;
}
switch ( V_150 ) {
case V_119 :
if ( F_27 ( & V_135 ) )
goto V_165;
break;
case V_214 :
if ( F_27 ( & V_135 ) )
goto V_216;
break;
case V_36 :
case V_166 :
break;
case V_37 :
default:
goto V_215;
}
V_213:
V_152 = true ;
V_81 -> V_20 = ( T_5 ) V_26 ;
V_235:
V_139 -> V_236 = V_137 ;
V_139 -> V_21 = V_21 ;
return V_152 ;
V_215:
V_152 = false ;
V_81 -> V_20 = F_39 ( T_5 , V_26 , V_14 ? V_14 -> V_237 : V_17 ) ;
goto V_235;
}
static T_6 void F_40 ( void )
{
F_41 ( & V_238 , sizeof( V_238 ) ) ;
}
static T_6 T_4 F_42 ( const T_4 * V_239 , T_4 V_240 ,
T_4 V_241 )
{
return F_43 ( V_239 , V_240 , V_241 ) ;
}
static inline const T_4 * F_44 ( const struct V_242 * V_243 )
{
const void * V_244 = V_243 ;
F_45 ( V_245 % sizeof( T_4 ) ) ;
return ( const T_4 * ) ( V_244 + V_245 ) ;
}
static inline T_7 F_46 ( const struct V_242 * V_243 )
{
T_7 V_246 = V_245 + sizeof( V_243 -> V_247 ) ;
F_45 ( ( sizeof( * V_243 ) - V_245 ) % sizeof( T_4 ) ) ;
F_45 ( F_47 ( F_48 ( * V_243 ) , V_247 ) !=
sizeof( * V_243 ) - sizeof( V_243 -> V_247 ) ) ;
switch ( V_243 -> V_248 . V_172 ) {
case V_169 :
V_246 -= sizeof( V_243 -> V_247 . V_170 ) ;
break;
case V_180 :
V_246 -= sizeof( V_243 -> V_247 . V_181 ) ;
break;
case V_205 :
V_246 -= sizeof( V_243 -> V_247 . V_206 ) ;
break;
}
return ( sizeof( * V_243 ) - V_246 ) / sizeof( T_4 ) ;
}
T_2 F_49 ( const struct V_242 * V_243 )
{
switch ( V_243 -> V_248 . V_172 ) {
case V_169 :
return V_243 -> V_247 . V_170 . V_249 ;
case V_180 :
return ( V_250 T_2 ) F_50 (
& V_243 -> V_247 . V_181 . V_249 ) ;
case V_205 :
return V_243 -> V_247 . V_206 . V_204 ;
default:
return 0 ;
}
}
T_2 F_51 ( const struct V_242 * V_243 )
{
switch ( V_243 -> V_248 . V_172 ) {
case V_169 :
return V_243 -> V_247 . V_170 . V_251 ;
case V_180 :
return ( V_250 T_2 ) F_50 (
& V_243 -> V_247 . V_181 . V_251 ) ;
default:
return 0 ;
}
}
static inline void F_52 ( struct V_242 * V_252 )
{
int V_253 , V_8 ;
switch ( V_252 -> V_248 . V_172 ) {
case V_169 :
V_253 = ( V_250 T_4 ) V_252 -> V_247 . V_170 . V_251 -
( V_250 T_4 ) V_252 -> V_247 . V_170 . V_249 ;
if ( ( V_253 < 0 ) ||
( V_253 == 0 &&
( ( V_250 T_5 ) V_252 -> V_22 . V_251 <
( V_250 T_5 ) V_252 -> V_22 . V_249 ) ) ) {
F_53 ( V_252 -> V_247 . V_170 . V_249 , V_252 -> V_247 . V_170 . V_251 ) ;
F_53 ( V_252 -> V_22 . V_249 , V_252 -> V_22 . V_251 ) ;
}
break;
case V_180 :
V_253 = memcmp ( & V_252 -> V_247 . V_181 . V_251 ,
& V_252 -> V_247 . V_181 . V_249 ,
sizeof( V_252 -> V_247 . V_181 . V_251 ) ) ;
if ( ( V_253 < 0 ) ||
( V_253 == 0 &&
( ( V_250 T_5 ) V_252 -> V_22 . V_251 <
( V_250 T_5 ) V_252 -> V_22 . V_249 ) ) ) {
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
F_53 ( V_252 -> V_247 . V_181 . V_249 . V_254 [ V_8 ] ,
V_252 -> V_247 . V_181 . V_251 . V_254 [ V_8 ] ) ;
F_53 ( V_252 -> V_22 . V_249 , V_252 -> V_22 . V_251 ) ;
}
break;
}
}
static inline T_4 F_54 ( struct V_242 * V_252 , T_4 V_241 )
{
T_4 V_255 ;
F_52 ( V_252 ) ;
V_255 = F_42 ( F_44 ( V_252 ) ,
F_46 ( V_252 ) , V_241 ) ;
if ( ! V_255 )
V_255 = 1 ;
return V_255 ;
}
T_4 F_55 ( struct V_242 * V_252 )
{
F_40 () ;
return F_54 ( V_252 , V_238 ) ;
}
static inline T_4 F_56 ( const struct V_13 * V_14 ,
struct V_242 * V_252 , T_4 V_241 )
{
F_57 ( V_14 , V_252 ,
V_183 ) ;
return F_54 ( V_252 , V_241 ) ;
}
void F_58 ( struct V_256 * V_257 ,
const struct V_242 * V_243 )
{
struct V_258 * V_16 =
(struct V_258 * ) V_257 ;
F_45 ( sizeof( * V_16 ) > sizeof( * V_257 ) ) ;
memset ( V_257 , 0 , sizeof( * V_257 ) ) ;
V_16 -> V_236 = V_243 -> V_259 . V_236 ;
V_16 -> V_21 = V_243 -> V_259 . V_21 ;
V_16 -> V_22 = V_243 -> V_22 . V_22 ;
V_16 -> V_249 = V_243 -> V_247 . V_170 . V_249 ;
V_16 -> V_251 = V_243 -> V_247 . V_170 . V_251 ;
}
T_4 F_59 ( const struct V_13 * V_14 )
{
struct V_242 V_252 ;
F_40 () ;
memset ( & V_252 , 0 , sizeof( V_252 ) ) ;
F_28 ( V_14 , & V_260 , & V_252 ,
NULL , 0 , 0 , 0 ,
V_183 ) ;
return F_54 ( & V_252 , V_238 ) ;
}
void F_60 ( struct V_13 * V_14 )
{
struct V_242 V_252 ;
T_4 V_255 ;
F_40 () ;
V_255 = F_56 ( V_14 , & V_252 , V_238 ) ;
F_61 ( V_14 , V_255 , F_62 ( & V_252 ) ) ;
}
T_8 F_63 ( const struct V_13 * V_14 , T_4 V_261 )
{
struct V_242 V_252 ;
return F_56 ( V_14 , & V_252 , V_261 ) ;
}
T_4 F_64 ( const struct V_13 * V_14 , void * V_16 ,
const struct V_242 * V_252 , int V_17 )
{
T_4 V_15 = V_252 -> V_248 . V_20 ;
if ( ( V_252 -> V_248 . V_85 & V_173 ) &&
! ( V_252 -> V_248 . V_85 & V_176 ) )
return V_15 ;
switch ( V_252 -> V_259 . V_21 ) {
case V_231 : {
const T_3 * V_262 ;
T_3 V_263 ;
V_262 = F_6 ( V_14 , V_15 + 12 , sizeof( V_263 ) ,
V_16 , V_17 , & V_263 ) ;
if ( ! V_262 )
return V_15 ;
V_15 += F_65 ( T_4 , sizeof( struct V_122 ) , ( * V_262 & 0xF0 ) >> 2 ) ;
break;
}
case V_264 :
case V_265 :
V_15 += sizeof( struct V_266 ) ;
break;
case V_267 :
V_15 += sizeof( struct V_268 ) ;
break;
case V_269 :
V_15 += sizeof( struct V_270 ) ;
break;
case V_271 :
V_15 += sizeof( struct V_272 ) ;
break;
case V_273 :
V_15 += sizeof( struct V_274 ) ;
break;
case V_275 :
V_15 += sizeof( struct V_276 ) ;
break;
}
return V_15 ;
}
T_4 F_66 ( const struct V_13 * V_14 )
{
struct V_242 V_252 ;
if ( ! F_57 ( V_14 , & V_252 , 0 ) )
return 0 ;
return F_64 ( V_14 , V_14 -> V_16 , & V_252 , F_9 ( V_14 ) ) ;
}
T_8 F_67 ( const struct V_277 * V_278 , struct V_242 * V_252 )
{
memset ( V_252 , 0 , sizeof( * V_252 ) ) ;
memcpy ( & V_252 -> V_247 . V_181 . V_249 , & V_278 -> V_171 ,
sizeof( V_252 -> V_247 . V_181 . V_249 ) ) ;
memcpy ( & V_252 -> V_247 . V_181 . V_251 , & V_278 -> V_279 ,
sizeof( V_252 -> V_247 . V_181 . V_251 ) ) ;
V_252 -> V_248 . V_172 = V_180 ;
V_252 -> V_22 . V_249 = V_278 -> V_280 ;
V_252 -> V_22 . V_251 = V_278 -> V_281 ;
V_252 -> V_52 . V_52 = V_278 -> V_282 ;
V_252 -> V_283 . V_184 = ( V_250 T_4 ) V_278 -> V_284 ;
V_252 -> V_259 . V_21 = V_278 -> V_285 ;
return F_55 ( V_252 ) ;
}
T_8 F_68 ( const struct V_286 * V_287 , struct V_242 * V_252 )
{
memset ( V_252 , 0 , sizeof( * V_252 ) ) ;
V_252 -> V_247 . V_170 . V_249 = V_287 -> V_171 ;
V_252 -> V_247 . V_170 . V_251 = V_287 -> V_279 ;
V_252 -> V_248 . V_172 = V_169 ;
V_252 -> V_22 . V_249 = V_287 -> V_288 ;
V_252 -> V_22 . V_251 = V_287 -> V_289 ;
V_252 -> V_52 . V_52 = V_287 -> V_290 ;
V_252 -> V_259 . V_21 = V_287 -> V_291 ;
return F_55 ( V_252 ) ;
}
static int T_9 F_69 ( void )
{
F_2 ( & V_292 ,
V_293 ,
F_70 ( V_293 ) ) ;
F_2 ( & V_260 ,
V_294 ,
F_70 ( V_294 ) ) ;
F_2 ( & V_295 ,
V_296 ,
F_70 ( V_296 ) ) ;
return 0 ;
}
