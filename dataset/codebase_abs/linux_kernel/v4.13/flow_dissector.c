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
bool F_27 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 ,
void * V_16 , T_1 V_135 , int V_26 , int V_17 ,
unsigned int V_85 )
{
struct V_80 * V_81 ;
struct V_136 * V_137 ;
struct V_138 * V_139 ;
struct V_140 * V_141 ;
struct V_142 * V_143 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
bool V_148 = false ;
T_3 V_21 = 0 ;
bool V_149 ;
if ( ! V_16 ) {
V_16 = V_14 -> V_16 ;
V_135 = F_28 ( V_14 ) ?
V_14 -> V_150 : V_14 -> V_90 ;
V_26 = F_29 ( V_14 ) ;
V_17 = F_9 ( V_14 ) ;
}
V_81 = F_12 ( V_1 ,
V_11 ,
V_25 ) ;
V_137 = F_12 ( V_1 ,
V_12 ,
V_25 ) ;
if ( F_4 ( V_1 ,
V_151 ) ) {
struct V_104 * V_105 = F_30 ( V_14 ) ;
struct V_152 * V_153 ;
V_153 = F_12 ( V_1 ,
V_151 ,
V_25 ) ;
memcpy ( V_153 , & V_105 -> V_154 , sizeof( * V_153 ) ) ;
}
V_155:
switch ( V_135 ) {
case F_15 ( V_69 ) : {
const struct V_126 * V_127 ;
struct V_126 V_156 ;
V_157:
V_127 = F_6 ( V_14 , V_26 , sizeof( V_156 ) , V_16 , V_17 , & V_156 ) ;
if ( ! V_127 || V_127 -> V_158 < 5 )
goto V_159;
V_26 += V_127 -> V_158 * 4 ;
V_21 = V_127 -> V_90 ;
if ( F_4 ( V_1 ,
V_160 ) ) {
V_139 = F_12 ( V_1 ,
V_160 ,
V_25 ) ;
memcpy ( & V_139 -> V_161 , & V_127 -> V_162 ,
sizeof( V_139 -> V_161 ) ) ;
V_81 -> V_163 = V_160 ;
}
if ( F_31 ( V_127 ) ) {
V_81 -> V_85 |= V_164 ;
if ( V_127 -> V_165 & F_15 ( V_166 ) ) {
goto V_167;
} else {
V_81 -> V_85 |= V_168 ;
if ( ! ( V_85 & V_169 ) )
goto V_167;
}
}
F_24 ( V_14 , V_1 ,
V_25 , V_16 , V_127 ) ;
if ( V_85 & V_170 )
goto V_167;
break;
}
case F_15 ( V_116 ) : {
const struct V_133 * V_127 ;
struct V_133 V_156 ;
V_171:
V_127 = F_6 ( V_14 , V_26 , sizeof( V_156 ) , V_16 , V_17 , & V_156 ) ;
if ( ! V_127 )
goto V_159;
V_21 = V_127 -> V_172 ;
V_26 += sizeof( struct V_133 ) ;
if ( F_4 ( V_1 ,
V_173 ) ) {
V_139 = F_12 ( V_1 ,
V_173 ,
V_25 ) ;
memcpy ( & V_139 -> V_174 , & V_127 -> V_162 ,
sizeof( V_139 -> V_174 ) ) ;
V_81 -> V_163 = V_173 ;
}
if ( ( F_4 ( V_1 ,
V_175 ) ||
( V_85 & V_176 ) ) &&
F_32 ( V_127 ) ) {
T_2 V_177 = F_32 ( V_127 ) ;
if ( F_4 ( V_1 ,
V_175 ) ) {
V_145 = F_12 ( V_1 ,
V_175 ,
V_25 ) ;
V_145 -> V_177 = F_11 ( V_177 ) ;
}
if ( V_85 & V_176 )
goto V_167;
}
F_25 ( V_14 , V_1 ,
V_25 , V_16 , V_127 ) ;
if ( V_85 & V_170 )
goto V_167;
break;
}
case F_15 ( V_178 ) :
case F_15 ( V_179 ) : {
const struct V_180 * V_181 ;
struct V_180 V_182 ;
bool V_183 = V_14 && F_28 ( V_14 ) ;
if ( V_183 )
V_135 = V_14 -> V_90 ;
if ( ! V_183 || F_33 ( V_14 -> V_90 ) ) {
V_181 = F_6 ( V_14 , V_26 , sizeof( V_182 ) ,
V_16 , V_17 , & V_182 ) ;
if ( ! V_181 )
goto V_159;
V_135 = V_181 -> V_184 ;
V_26 += sizeof( * V_181 ) ;
if ( V_148 )
goto V_155;
}
V_148 = true ;
if ( F_4 ( V_1 ,
V_185 ) ) {
V_147 = F_12 ( V_1 ,
V_185 ,
V_25 ) ;
if ( V_183 ) {
V_147 -> V_186 = F_34 ( V_14 ) ;
V_147 -> V_187 =
( F_35 ( V_14 ) >> V_188 ) ;
} else {
V_147 -> V_186 = F_16 ( V_181 -> V_189 ) &
V_190 ;
V_147 -> V_187 =
( F_16 ( V_181 -> V_189 ) &
V_191 ) >> V_188 ;
}
}
goto V_155;
}
case F_15 ( V_192 ) : {
struct {
struct V_193 V_30 ;
T_1 V_135 ;
} * V_30 , V_31 ;
V_30 = F_6 ( V_14 , V_26 , sizeof( V_31 ) , V_16 , V_17 , & V_31 ) ;
if ( ! V_30 )
goto V_159;
V_135 = V_30 -> V_135 ;
V_26 += V_194 ;
switch ( V_135 ) {
case F_15 ( V_114 ) :
goto V_157;
case F_15 ( V_115 ) :
goto V_171;
default:
goto V_159;
}
}
case F_15 ( V_195 ) : {
struct {
T_2 V_196 [ 3 ] ;
T_2 V_197 ;
} * V_30 , V_31 ;
V_30 = F_6 ( V_14 , V_26 , sizeof( V_31 ) , V_16 , V_17 , & V_31 ) ;
if ( ! V_30 )
goto V_159;
if ( F_4 ( V_1 ,
V_198 ) ) {
V_139 = F_12 ( V_1 ,
V_198 ,
V_25 ) ;
V_139 -> V_199 . V_197 = V_30 -> V_197 ;
V_81 -> V_163 = V_198 ;
}
goto V_167;
}
case F_15 ( V_200 ) :
case F_15 ( V_201 ) :
V_202:
switch ( F_10 ( V_14 , V_1 ,
V_25 , V_16 ,
V_26 , V_17 ) ) {
case V_36 :
goto V_167;
case V_37 :
default:
goto V_159;
}
case F_15 ( V_203 ) :
if ( ( V_17 - V_26 ) < V_204 )
goto V_159;
V_26 += V_204 ;
goto V_167;
case F_15 ( V_205 ) :
case F_15 ( V_206 ) :
switch ( F_14 ( V_14 , V_1 ,
V_25 , V_16 ,
V_26 , V_17 ) ) {
case V_36 :
goto V_167;
case V_37 :
default:
goto V_159;
}
default:
goto V_159;
}
V_207:
switch ( V_21 ) {
case V_208 :
switch ( F_18 ( V_14 , V_81 , V_1 ,
V_25 , V_16 ,
& V_135 , & V_26 , & V_17 , V_85 ) ) {
case V_36 :
goto V_167;
case V_37 :
goto V_159;
case V_119 :
goto V_155;
}
case V_209 :
case V_210 :
case V_211 : {
T_3 V_212 [ 2 ] , * V_213 ;
if ( V_135 != F_15 ( V_116 ) )
break;
V_213 = F_6 ( V_14 , V_26 , sizeof( V_212 ) ,
V_16 , V_17 , & V_212 ) ;
if ( ! V_213 )
goto V_159;
V_21 = V_213 [ 0 ] ;
V_26 += ( V_213 [ 1 ] + 1 ) << 3 ;
goto V_207;
}
case V_214 : {
struct V_215 V_216 , * V_217 ;
if ( V_135 != F_15 ( V_116 ) )
break;
V_217 = F_6 ( V_14 , V_26 , sizeof( V_216 ) ,
V_16 , V_17 , & V_216 ) ;
if ( ! V_217 )
goto V_159;
V_81 -> V_85 |= V_164 ;
V_26 += sizeof( V_216 ) ;
V_21 = V_217 -> V_172 ;
if ( ! ( V_217 -> V_165 & F_15 ( V_218 ) ) ) {
V_81 -> V_85 |= V_168 ;
if ( V_85 & V_169 )
goto V_207;
}
goto V_167;
}
case V_219 :
V_135 = F_15 ( V_69 ) ;
V_81 -> V_85 |= V_117 ;
if ( V_85 & V_118 )
goto V_167;
goto V_157;
case V_220 :
V_135 = F_15 ( V_116 ) ;
V_81 -> V_85 |= V_117 ;
if ( V_85 & V_118 )
goto V_167;
goto V_171;
case V_221 :
V_135 = F_15 ( V_200 ) ;
goto V_202;
case V_222 :
F_20 ( V_14 , V_1 , V_25 ,
V_16 , V_26 , V_17 ) ;
break;
default:
break;
}
if ( F_4 ( V_1 ,
V_223 ) ) {
V_141 = F_12 ( V_1 ,
V_223 ,
V_25 ) ;
V_141 -> V_22 = F_7 ( V_14 , V_26 , V_21 ,
V_16 , V_17 ) ;
}
if ( F_4 ( V_1 ,
V_224 ) ) {
V_143 = F_12 ( V_1 ,
V_224 ,
V_25 ) ;
V_143 -> V_225 = F_5 ( V_14 , V_26 , V_16 , V_17 ) ;
}
V_167:
V_149 = true ;
V_81 -> V_20 = ( T_5 ) V_26 ;
V_226:
V_137 -> V_227 = V_135 ;
V_137 -> V_21 = V_21 ;
return V_149 ;
V_159:
V_149 = false ;
V_81 -> V_20 = F_36 ( T_5 , V_26 , V_14 ? V_14 -> V_228 : V_17 ) ;
goto V_226;
}
static T_6 void F_37 ( void )
{
F_38 ( & V_229 , sizeof( V_229 ) ) ;
}
static T_6 T_4 F_39 ( const T_4 * V_230 , T_4 V_231 ,
T_4 V_232 )
{
return F_40 ( V_230 , V_231 , V_232 ) ;
}
static inline const T_4 * F_41 ( const struct V_233 * V_234 )
{
const void * V_235 = V_234 ;
F_42 ( V_236 % sizeof( T_4 ) ) ;
return ( const T_4 * ) ( V_235 + V_236 ) ;
}
static inline T_7 F_43 ( const struct V_233 * V_234 )
{
T_7 V_237 = V_236 + sizeof( V_234 -> V_238 ) ;
F_42 ( ( sizeof( * V_234 ) - V_236 ) % sizeof( T_4 ) ) ;
F_42 ( F_44 ( F_45 ( * V_234 ) , V_238 ) !=
sizeof( * V_234 ) - sizeof( V_234 -> V_238 ) ) ;
switch ( V_234 -> V_239 . V_163 ) {
case V_160 :
V_237 -= sizeof( V_234 -> V_238 . V_161 ) ;
break;
case V_173 :
V_237 -= sizeof( V_234 -> V_238 . V_174 ) ;
break;
case V_198 :
V_237 -= sizeof( V_234 -> V_238 . V_199 ) ;
break;
}
return ( sizeof( * V_234 ) - V_237 ) / sizeof( T_4 ) ;
}
T_2 F_46 ( const struct V_233 * V_234 )
{
switch ( V_234 -> V_239 . V_163 ) {
case V_160 :
return V_234 -> V_238 . V_161 . V_240 ;
case V_173 :
return ( V_241 T_2 ) F_47 (
& V_234 -> V_238 . V_174 . V_240 ) ;
case V_198 :
return V_234 -> V_238 . V_199 . V_197 ;
default:
return 0 ;
}
}
T_2 F_48 ( const struct V_233 * V_234 )
{
switch ( V_234 -> V_239 . V_163 ) {
case V_160 :
return V_234 -> V_238 . V_161 . V_242 ;
case V_173 :
return ( V_241 T_2 ) F_47 (
& V_234 -> V_238 . V_174 . V_242 ) ;
default:
return 0 ;
}
}
static inline void F_49 ( struct V_233 * V_243 )
{
int V_244 , V_8 ;
switch ( V_243 -> V_239 . V_163 ) {
case V_160 :
V_244 = ( V_241 T_4 ) V_243 -> V_238 . V_161 . V_242 -
( V_241 T_4 ) V_243 -> V_238 . V_161 . V_240 ;
if ( ( V_244 < 0 ) ||
( V_244 == 0 &&
( ( V_241 T_5 ) V_243 -> V_22 . V_242 <
( V_241 T_5 ) V_243 -> V_22 . V_240 ) ) ) {
F_50 ( V_243 -> V_238 . V_161 . V_240 , V_243 -> V_238 . V_161 . V_242 ) ;
F_50 ( V_243 -> V_22 . V_240 , V_243 -> V_22 . V_242 ) ;
}
break;
case V_173 :
V_244 = memcmp ( & V_243 -> V_238 . V_174 . V_242 ,
& V_243 -> V_238 . V_174 . V_240 ,
sizeof( V_243 -> V_238 . V_174 . V_242 ) ) ;
if ( ( V_244 < 0 ) ||
( V_244 == 0 &&
( ( V_241 T_5 ) V_243 -> V_22 . V_242 <
( V_241 T_5 ) V_243 -> V_22 . V_240 ) ) ) {
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
F_50 ( V_243 -> V_238 . V_174 . V_240 . V_245 [ V_8 ] ,
V_243 -> V_238 . V_174 . V_242 . V_245 [ V_8 ] ) ;
F_50 ( V_243 -> V_22 . V_240 , V_243 -> V_22 . V_242 ) ;
}
break;
}
}
static inline T_4 F_51 ( struct V_233 * V_243 , T_4 V_232 )
{
T_4 V_246 ;
F_49 ( V_243 ) ;
V_246 = F_39 ( F_41 ( V_243 ) ,
F_43 ( V_243 ) , V_232 ) ;
if ( ! V_246 )
V_246 = 1 ;
return V_246 ;
}
T_4 F_52 ( struct V_233 * V_243 )
{
F_37 () ;
return F_51 ( V_243 , V_229 ) ;
}
static inline T_4 F_53 ( const struct V_13 * V_14 ,
struct V_233 * V_243 , T_4 V_232 )
{
F_54 ( V_14 , V_243 ,
V_176 ) ;
return F_51 ( V_243 , V_232 ) ;
}
void F_55 ( struct V_247 * V_248 ,
const struct V_233 * V_234 )
{
struct V_249 * V_16 =
(struct V_249 * ) V_248 ;
F_42 ( sizeof( * V_16 ) > sizeof( * V_248 ) ) ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
V_16 -> V_227 = V_234 -> V_250 . V_227 ;
V_16 -> V_21 = V_234 -> V_250 . V_21 ;
V_16 -> V_22 = V_234 -> V_22 . V_22 ;
V_16 -> V_240 = V_234 -> V_238 . V_161 . V_240 ;
V_16 -> V_242 = V_234 -> V_238 . V_161 . V_242 ;
}
T_4 F_56 ( const struct V_13 * V_14 )
{
struct V_233 V_243 ;
F_37 () ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
F_27 ( V_14 , & V_251 , & V_243 ,
NULL , 0 , 0 , 0 ,
V_176 ) ;
return F_51 ( & V_243 , V_229 ) ;
}
void F_57 ( struct V_13 * V_14 )
{
struct V_233 V_243 ;
T_4 V_246 ;
F_37 () ;
V_246 = F_53 ( V_14 , & V_243 , V_229 ) ;
F_58 ( V_14 , V_246 , F_59 ( & V_243 ) ) ;
}
T_8 F_60 ( const struct V_13 * V_14 , T_4 V_252 )
{
struct V_233 V_243 ;
return F_53 ( V_14 , & V_243 , V_252 ) ;
}
T_8 F_61 ( struct V_13 * V_14 , const struct V_253 * V_254 )
{
struct V_233 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
memcpy ( & V_243 . V_238 . V_174 . V_240 , & V_254 -> V_162 ,
sizeof( V_243 . V_238 . V_174 . V_240 ) ) ;
memcpy ( & V_243 . V_238 . V_174 . V_242 , & V_254 -> V_255 ,
sizeof( V_243 . V_238 . V_174 . V_242 ) ) ;
V_243 . V_239 . V_163 = V_173 ;
V_243 . V_22 . V_240 = V_254 -> V_256 ;
V_243 . V_22 . V_242 = V_254 -> V_257 ;
V_243 . V_52 . V_52 = V_254 -> V_258 ;
V_243 . V_259 . V_177 = ( V_241 T_4 ) V_254 -> V_260 ;
V_243 . V_250 . V_21 = V_254 -> V_261 ;
F_58 ( V_14 , F_52 ( & V_243 ) ,
F_59 ( & V_243 ) ) ;
return V_14 -> V_246 ;
}
T_8 F_62 ( struct V_13 * V_14 , const struct V_262 * V_263 )
{
struct V_233 V_243 ;
memset ( & V_243 , 0 , sizeof( V_243 ) ) ;
V_243 . V_238 . V_161 . V_240 = V_263 -> V_162 ;
V_243 . V_238 . V_161 . V_242 = V_263 -> V_255 ;
V_243 . V_239 . V_163 = V_160 ;
V_243 . V_22 . V_240 = V_263 -> V_264 ;
V_243 . V_22 . V_242 = V_263 -> V_265 ;
V_243 . V_52 . V_52 = V_263 -> V_266 ;
V_243 . V_250 . V_21 = V_263 -> V_267 ;
F_58 ( V_14 , F_52 ( & V_243 ) ,
F_59 ( & V_243 ) ) ;
return V_14 -> V_246 ;
}
T_4 F_63 ( const struct V_13 * V_14 , void * V_16 ,
const struct V_233 * V_243 , int V_17 )
{
T_4 V_15 = V_243 -> V_239 . V_20 ;
if ( ( V_243 -> V_239 . V_85 & V_164 ) &&
! ( V_243 -> V_239 . V_85 & V_168 ) )
return V_15 ;
switch ( V_243 -> V_250 . V_21 ) {
case V_222 : {
const T_3 * V_268 ;
T_3 V_269 ;
V_268 = F_6 ( V_14 , V_15 + 12 , sizeof( V_269 ) ,
V_16 , V_17 , & V_269 ) ;
if ( ! V_268 )
return V_15 ;
V_15 += F_64 ( T_4 , sizeof( struct V_122 ) , ( * V_268 & 0xF0 ) >> 2 ) ;
break;
}
case V_270 :
case V_271 :
V_15 += sizeof( struct V_272 ) ;
break;
case V_273 :
V_15 += sizeof( struct V_274 ) ;
break;
case V_275 :
V_15 += sizeof( struct V_276 ) ;
break;
case V_277 :
V_15 += sizeof( struct V_278 ) ;
break;
case V_279 :
V_15 += sizeof( struct V_280 ) ;
break;
case V_281 :
V_15 += sizeof( struct V_282 ) ;
break;
}
return V_15 ;
}
T_4 F_65 ( const struct V_13 * V_14 )
{
struct V_233 V_243 ;
if ( ! F_54 ( V_14 , & V_243 , 0 ) )
return 0 ;
return F_63 ( V_14 , V_14 -> V_16 , & V_243 , F_9 ( V_14 ) ) ;
}
T_8 F_66 ( const struct V_253 * V_254 , struct V_233 * V_243 )
{
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
memcpy ( & V_243 -> V_238 . V_174 . V_240 , & V_254 -> V_162 ,
sizeof( V_243 -> V_238 . V_174 . V_240 ) ) ;
memcpy ( & V_243 -> V_238 . V_174 . V_242 , & V_254 -> V_255 ,
sizeof( V_243 -> V_238 . V_174 . V_242 ) ) ;
V_243 -> V_239 . V_163 = V_173 ;
V_243 -> V_22 . V_240 = V_254 -> V_256 ;
V_243 -> V_22 . V_242 = V_254 -> V_257 ;
V_243 -> V_52 . V_52 = V_254 -> V_258 ;
V_243 -> V_259 . V_177 = ( V_241 T_4 ) V_254 -> V_260 ;
V_243 -> V_250 . V_21 = V_254 -> V_261 ;
return F_52 ( V_243 ) ;
}
T_8 F_67 ( const struct V_262 * V_263 , struct V_233 * V_243 )
{
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_243 -> V_238 . V_161 . V_240 = V_263 -> V_162 ;
V_243 -> V_238 . V_161 . V_242 = V_263 -> V_255 ;
V_243 -> V_239 . V_163 = V_160 ;
V_243 -> V_22 . V_240 = V_263 -> V_264 ;
V_243 -> V_22 . V_242 = V_263 -> V_265 ;
V_243 -> V_52 . V_52 = V_263 -> V_266 ;
V_243 -> V_250 . V_21 = V_263 -> V_267 ;
return F_52 ( V_243 ) ;
}
static int T_9 F_68 ( void )
{
F_2 ( & V_283 ,
V_284 ,
F_69 ( V_284 ) ) ;
F_2 ( & V_251 ,
V_285 ,
F_69 ( V_285 ) ) ;
F_2 ( & V_286 ,
V_287 ,
F_69 ( V_287 ) ) ;
return 0 ;
}
