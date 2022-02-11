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
bool F_20 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_25 ,
void * V_16 , T_1 V_120 , int V_26 , int V_17 ,
unsigned int V_85 )
{
struct V_80 * V_81 ;
struct V_121 * V_122 ;
struct V_123 * V_124 ;
struct V_125 * V_126 ;
struct V_127 * V_128 ;
struct V_129 * V_130 ;
struct V_131 * V_132 ;
bool V_133 = false ;
T_3 V_21 = 0 ;
bool V_134 ;
if ( ! V_16 ) {
V_16 = V_14 -> V_16 ;
V_120 = F_21 ( V_14 ) ?
V_14 -> V_135 : V_14 -> V_90 ;
V_26 = F_22 ( V_14 ) ;
V_17 = F_9 ( V_14 ) ;
}
V_81 = F_12 ( V_1 ,
V_11 ,
V_25 ) ;
V_122 = F_12 ( V_1 ,
V_12 ,
V_25 ) ;
if ( F_4 ( V_1 ,
V_136 ) ) {
struct V_104 * V_105 = F_23 ( V_14 ) ;
struct V_137 * V_138 ;
V_138 = F_12 ( V_1 ,
V_136 ,
V_25 ) ;
memcpy ( V_138 , & V_105 -> V_139 , sizeof( * V_138 ) ) ;
}
V_140:
switch ( V_120 ) {
case F_15 ( V_69 ) : {
const struct V_141 * V_142 ;
struct V_141 V_143 ;
V_144:
V_142 = F_6 ( V_14 , V_26 , sizeof( V_143 ) , V_16 , V_17 , & V_143 ) ;
if ( ! V_142 || V_142 -> V_145 < 5 )
goto V_146;
V_26 += V_142 -> V_145 * 4 ;
V_21 = V_142 -> V_90 ;
if ( F_4 ( V_1 ,
V_147 ) ) {
V_124 = F_12 ( V_1 ,
V_147 ,
V_25 ) ;
memcpy ( & V_124 -> V_148 , & V_142 -> V_149 ,
sizeof( V_124 -> V_148 ) ) ;
V_81 -> V_150 = V_147 ;
}
if ( F_24 ( V_142 ) ) {
V_81 -> V_85 |= V_151 ;
if ( V_142 -> V_152 & F_15 ( V_153 ) ) {
goto V_154;
} else {
V_81 -> V_85 |= V_155 ;
if ( ! ( V_85 & V_156 ) )
goto V_154;
}
}
if ( V_85 & V_157 )
goto V_154;
break;
}
case F_15 ( V_116 ) : {
const struct V_158 * V_142 ;
struct V_158 V_143 ;
V_159:
V_142 = F_6 ( V_14 , V_26 , sizeof( V_143 ) , V_16 , V_17 , & V_143 ) ;
if ( ! V_142 )
goto V_146;
V_21 = V_142 -> V_160 ;
V_26 += sizeof( struct V_158 ) ;
if ( F_4 ( V_1 ,
V_161 ) ) {
V_124 = F_12 ( V_1 ,
V_161 ,
V_25 ) ;
memcpy ( & V_124 -> V_162 , & V_142 -> V_149 ,
sizeof( V_124 -> V_162 ) ) ;
V_81 -> V_150 = V_161 ;
}
if ( ( F_4 ( V_1 ,
V_163 ) ||
( V_85 & V_164 ) ) &&
F_25 ( V_142 ) ) {
T_2 V_165 = F_25 ( V_142 ) ;
if ( F_4 ( V_1 ,
V_163 ) ) {
V_130 = F_12 ( V_1 ,
V_163 ,
V_25 ) ;
V_130 -> V_165 = F_11 ( V_165 ) ;
}
if ( V_85 & V_164 )
goto V_154;
}
if ( V_85 & V_157 )
goto V_154;
break;
}
case F_15 ( V_166 ) :
case F_15 ( V_167 ) : {
const struct V_168 * V_169 ;
struct V_168 V_170 ;
bool V_171 = V_14 && F_21 ( V_14 ) ;
if ( V_171 )
V_120 = V_14 -> V_90 ;
if ( ! V_171 || F_26 ( V_14 -> V_90 ) ) {
V_169 = F_6 ( V_14 , V_26 , sizeof( V_170 ) ,
V_16 , V_17 , & V_170 ) ;
if ( ! V_169 )
goto V_146;
V_120 = V_169 -> V_172 ;
V_26 += sizeof( * V_169 ) ;
if ( V_133 )
goto V_140;
}
V_133 = true ;
if ( F_4 ( V_1 ,
V_173 ) ) {
V_132 = F_12 ( V_1 ,
V_173 ,
V_25 ) ;
if ( V_171 ) {
V_132 -> V_174 = F_27 ( V_14 ) ;
V_132 -> V_175 =
( F_28 ( V_14 ) >> V_176 ) ;
} else {
V_132 -> V_174 = F_16 ( V_169 -> V_177 ) &
V_178 ;
V_132 -> V_175 =
( F_16 ( V_169 -> V_177 ) &
V_179 ) >> V_176 ;
}
}
goto V_140;
}
case F_15 ( V_180 ) : {
struct {
struct V_181 V_30 ;
T_1 V_120 ;
} * V_30 , V_31 ;
V_30 = F_6 ( V_14 , V_26 , sizeof( V_31 ) , V_16 , V_17 , & V_31 ) ;
if ( ! V_30 )
goto V_146;
V_120 = V_30 -> V_120 ;
V_26 += V_182 ;
switch ( V_120 ) {
case F_15 ( V_114 ) :
goto V_144;
case F_15 ( V_115 ) :
goto V_159;
default:
goto V_146;
}
}
case F_15 ( V_183 ) : {
struct {
T_2 V_184 [ 3 ] ;
T_2 V_185 ;
} * V_30 , V_31 ;
V_30 = F_6 ( V_14 , V_26 , sizeof( V_31 ) , V_16 , V_17 , & V_31 ) ;
if ( ! V_30 )
goto V_146;
if ( F_4 ( V_1 ,
V_186 ) ) {
V_124 = F_12 ( V_1 ,
V_186 ,
V_25 ) ;
V_124 -> V_187 . V_185 = V_30 -> V_185 ;
V_81 -> V_150 = V_186 ;
}
goto V_154;
}
case F_15 ( V_188 ) :
case F_15 ( V_189 ) :
V_190:
switch ( F_10 ( V_14 , V_1 ,
V_25 , V_16 ,
V_26 , V_17 ) ) {
case V_36 :
goto V_154;
case V_37 :
default:
goto V_146;
}
case F_15 ( V_191 ) :
if ( ( V_17 - V_26 ) < V_192 )
goto V_146;
V_26 += V_192 ;
goto V_154;
case F_15 ( V_193 ) :
case F_15 ( V_194 ) :
switch ( F_14 ( V_14 , V_1 ,
V_25 , V_16 ,
V_26 , V_17 ) ) {
case V_36 :
goto V_154;
case V_37 :
default:
goto V_146;
}
default:
goto V_146;
}
V_195:
switch ( V_21 ) {
case V_196 :
switch ( F_18 ( V_14 , V_81 , V_1 ,
V_25 , V_16 ,
& V_120 , & V_26 , & V_17 , V_85 ) ) {
case V_36 :
goto V_154;
case V_37 :
goto V_146;
case V_119 :
goto V_140;
}
case V_197 :
case V_198 :
case V_199 : {
T_3 V_200 [ 2 ] , * V_201 ;
if ( V_120 != F_15 ( V_116 ) )
break;
V_201 = F_6 ( V_14 , V_26 , sizeof( V_200 ) ,
V_16 , V_17 , & V_200 ) ;
if ( ! V_201 )
goto V_146;
V_21 = V_201 [ 0 ] ;
V_26 += ( V_201 [ 1 ] + 1 ) << 3 ;
goto V_195;
}
case V_202 : {
struct V_203 V_204 , * V_205 ;
if ( V_120 != F_15 ( V_116 ) )
break;
V_205 = F_6 ( V_14 , V_26 , sizeof( V_204 ) ,
V_16 , V_17 , & V_204 ) ;
if ( ! V_205 )
goto V_146;
V_81 -> V_85 |= V_151 ;
V_26 += sizeof( V_204 ) ;
V_21 = V_205 -> V_160 ;
if ( ! ( V_205 -> V_152 & F_15 ( V_206 ) ) ) {
V_81 -> V_85 |= V_155 ;
if ( V_85 & V_156 )
goto V_195;
}
goto V_154;
}
case V_207 :
V_120 = F_15 ( V_69 ) ;
V_81 -> V_85 |= V_117 ;
if ( V_85 & V_118 )
goto V_154;
goto V_144;
case V_208 :
V_120 = F_15 ( V_116 ) ;
V_81 -> V_85 |= V_117 ;
if ( V_85 & V_118 )
goto V_154;
goto V_159;
case V_209 :
V_120 = F_15 ( V_188 ) ;
goto V_190;
default:
break;
}
if ( F_4 ( V_1 ,
V_210 ) ) {
V_126 = F_12 ( V_1 ,
V_210 ,
V_25 ) ;
V_126 -> V_22 = F_7 ( V_14 , V_26 , V_21 ,
V_16 , V_17 ) ;
}
if ( F_4 ( V_1 ,
V_211 ) ) {
V_128 = F_12 ( V_1 ,
V_211 ,
V_25 ) ;
V_128 -> V_212 = F_5 ( V_14 , V_26 , V_16 , V_17 ) ;
}
V_154:
V_134 = true ;
V_81 -> V_20 = ( T_5 ) V_26 ;
V_213:
V_122 -> V_214 = V_120 ;
V_122 -> V_21 = V_21 ;
return V_134 ;
V_146:
V_134 = false ;
V_81 -> V_20 = F_29 ( T_5 , V_26 , V_14 ? V_14 -> V_215 : V_17 ) ;
goto V_213;
}
static T_6 void F_30 ( void )
{
F_31 ( & V_216 , sizeof( V_216 ) ) ;
}
static T_6 T_4 F_32 ( const T_4 * V_217 , T_4 V_218 ,
T_4 V_219 )
{
return F_33 ( V_217 , V_218 , V_219 ) ;
}
static inline const T_4 * F_34 ( const struct V_220 * V_221 )
{
const void * V_222 = V_221 ;
F_35 ( V_223 % sizeof( T_4 ) ) ;
return ( const T_4 * ) ( V_222 + V_223 ) ;
}
static inline T_7 F_36 ( const struct V_220 * V_221 )
{
T_7 V_224 = V_223 + sizeof( V_221 -> V_225 ) ;
F_35 ( ( sizeof( * V_221 ) - V_223 ) % sizeof( T_4 ) ) ;
F_35 ( F_37 ( F_38 ( * V_221 ) , V_225 ) !=
sizeof( * V_221 ) - sizeof( V_221 -> V_225 ) ) ;
switch ( V_221 -> V_226 . V_150 ) {
case V_147 :
V_224 -= sizeof( V_221 -> V_225 . V_148 ) ;
break;
case V_161 :
V_224 -= sizeof( V_221 -> V_225 . V_162 ) ;
break;
case V_186 :
V_224 -= sizeof( V_221 -> V_225 . V_187 ) ;
break;
}
return ( sizeof( * V_221 ) - V_224 ) / sizeof( T_4 ) ;
}
T_2 F_39 ( const struct V_220 * V_221 )
{
switch ( V_221 -> V_226 . V_150 ) {
case V_147 :
return V_221 -> V_225 . V_148 . V_227 ;
case V_161 :
return ( V_228 T_2 ) F_40 (
& V_221 -> V_225 . V_162 . V_227 ) ;
case V_186 :
return V_221 -> V_225 . V_187 . V_185 ;
default:
return 0 ;
}
}
T_2 F_41 ( const struct V_220 * V_221 )
{
switch ( V_221 -> V_226 . V_150 ) {
case V_147 :
return V_221 -> V_225 . V_148 . V_229 ;
case V_161 :
return ( V_228 T_2 ) F_40 (
& V_221 -> V_225 . V_162 . V_229 ) ;
default:
return 0 ;
}
}
static inline void F_42 ( struct V_220 * V_230 )
{
int V_231 , V_8 ;
switch ( V_230 -> V_226 . V_150 ) {
case V_147 :
V_231 = ( V_228 T_4 ) V_230 -> V_225 . V_148 . V_229 -
( V_228 T_4 ) V_230 -> V_225 . V_148 . V_227 ;
if ( ( V_231 < 0 ) ||
( V_231 == 0 &&
( ( V_228 T_5 ) V_230 -> V_22 . V_229 <
( V_228 T_5 ) V_230 -> V_22 . V_227 ) ) ) {
F_43 ( V_230 -> V_225 . V_148 . V_227 , V_230 -> V_225 . V_148 . V_229 ) ;
F_43 ( V_230 -> V_22 . V_227 , V_230 -> V_22 . V_229 ) ;
}
break;
case V_161 :
V_231 = memcmp ( & V_230 -> V_225 . V_162 . V_229 ,
& V_230 -> V_225 . V_162 . V_227 ,
sizeof( V_230 -> V_225 . V_162 . V_229 ) ) ;
if ( ( V_231 < 0 ) ||
( V_231 == 0 &&
( ( V_228 T_5 ) V_230 -> V_22 . V_229 <
( V_228 T_5 ) V_230 -> V_22 . V_227 ) ) ) {
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
F_43 ( V_230 -> V_225 . V_162 . V_227 . V_232 [ V_8 ] ,
V_230 -> V_225 . V_162 . V_229 . V_232 [ V_8 ] ) ;
F_43 ( V_230 -> V_22 . V_227 , V_230 -> V_22 . V_229 ) ;
}
break;
}
}
static inline T_4 F_44 ( struct V_220 * V_230 , T_4 V_219 )
{
T_4 V_233 ;
F_42 ( V_230 ) ;
V_233 = F_32 ( F_34 ( V_230 ) ,
F_36 ( V_230 ) , V_219 ) ;
if ( ! V_233 )
V_233 = 1 ;
return V_233 ;
}
T_4 F_45 ( struct V_220 * V_230 )
{
F_30 () ;
return F_44 ( V_230 , V_216 ) ;
}
static inline T_4 F_46 ( const struct V_13 * V_14 ,
struct V_220 * V_230 , T_4 V_219 )
{
F_47 ( V_14 , V_230 ,
V_164 ) ;
return F_44 ( V_230 , V_219 ) ;
}
void F_48 ( struct V_234 * V_235 ,
const struct V_220 * V_221 )
{
struct V_236 * V_16 =
(struct V_236 * ) V_235 ;
F_35 ( sizeof( * V_16 ) > sizeof( * V_235 ) ) ;
memset ( V_235 , 0 , sizeof( * V_235 ) ) ;
V_16 -> V_214 = V_221 -> V_237 . V_214 ;
V_16 -> V_21 = V_221 -> V_237 . V_21 ;
V_16 -> V_22 = V_221 -> V_22 . V_22 ;
V_16 -> V_227 = V_221 -> V_225 . V_148 . V_227 ;
V_16 -> V_229 = V_221 -> V_225 . V_148 . V_229 ;
}
T_4 F_49 ( const struct V_13 * V_14 )
{
struct V_220 V_230 ;
F_30 () ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
F_20 ( V_14 , & V_238 , & V_230 ,
NULL , 0 , 0 , 0 ,
V_164 ) ;
return F_44 ( & V_230 , V_216 ) ;
}
void F_50 ( struct V_13 * V_14 )
{
struct V_220 V_230 ;
T_4 V_233 ;
F_30 () ;
V_233 = F_46 ( V_14 , & V_230 , V_216 ) ;
F_51 ( V_14 , V_233 , F_52 ( & V_230 ) ) ;
}
T_8 F_53 ( const struct V_13 * V_14 , T_4 V_239 )
{
struct V_220 V_230 ;
return F_46 ( V_14 , & V_230 , V_239 ) ;
}
T_8 F_54 ( struct V_13 * V_14 , const struct V_240 * V_241 )
{
struct V_220 V_230 ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
memcpy ( & V_230 . V_225 . V_162 . V_227 , & V_241 -> V_149 ,
sizeof( V_230 . V_225 . V_162 . V_227 ) ) ;
memcpy ( & V_230 . V_225 . V_162 . V_229 , & V_241 -> V_242 ,
sizeof( V_230 . V_225 . V_162 . V_229 ) ) ;
V_230 . V_226 . V_150 = V_161 ;
V_230 . V_22 . V_227 = V_241 -> V_243 ;
V_230 . V_22 . V_229 = V_241 -> V_244 ;
V_230 . V_52 . V_52 = V_241 -> V_245 ;
V_230 . V_246 . V_165 = ( V_228 T_4 ) V_241 -> V_247 ;
V_230 . V_237 . V_21 = V_241 -> V_248 ;
F_51 ( V_14 , F_45 ( & V_230 ) ,
F_52 ( & V_230 ) ) ;
return V_14 -> V_233 ;
}
T_8 F_55 ( struct V_13 * V_14 , const struct V_249 * V_250 )
{
struct V_220 V_230 ;
memset ( & V_230 , 0 , sizeof( V_230 ) ) ;
V_230 . V_225 . V_148 . V_227 = V_250 -> V_149 ;
V_230 . V_225 . V_148 . V_229 = V_250 -> V_242 ;
V_230 . V_226 . V_150 = V_147 ;
V_230 . V_22 . V_227 = V_250 -> V_251 ;
V_230 . V_22 . V_229 = V_250 -> V_252 ;
V_230 . V_52 . V_52 = V_250 -> V_253 ;
V_230 . V_237 . V_21 = V_250 -> V_254 ;
F_51 ( V_14 , F_45 ( & V_230 ) ,
F_52 ( & V_230 ) ) ;
return V_14 -> V_233 ;
}
T_4 F_56 ( const struct V_13 * V_14 , void * V_16 ,
const struct V_220 * V_230 , int V_17 )
{
T_4 V_15 = V_230 -> V_226 . V_20 ;
if ( ( V_230 -> V_226 . V_85 & V_151 ) &&
! ( V_230 -> V_226 . V_85 & V_155 ) )
return V_15 ;
switch ( V_230 -> V_237 . V_21 ) {
case V_255 : {
const T_3 * V_256 ;
T_3 V_257 ;
V_256 = F_6 ( V_14 , V_15 + 12 , sizeof( V_257 ) ,
V_16 , V_17 , & V_257 ) ;
if ( ! V_256 )
return V_15 ;
V_15 += F_57 ( T_4 , sizeof( struct V_258 ) , ( * V_256 & 0xF0 ) >> 2 ) ;
break;
}
case V_259 :
case V_260 :
V_15 += sizeof( struct V_261 ) ;
break;
case V_262 :
V_15 += sizeof( struct V_263 ) ;
break;
case V_264 :
V_15 += sizeof( struct V_265 ) ;
break;
case V_266 :
V_15 += sizeof( struct V_267 ) ;
break;
case V_268 :
V_15 += sizeof( struct V_269 ) ;
break;
case V_270 :
V_15 += sizeof( struct V_271 ) ;
break;
}
return V_15 ;
}
T_4 F_58 ( const struct V_13 * V_14 )
{
struct V_220 V_230 ;
if ( ! F_47 ( V_14 , & V_230 , 0 ) )
return 0 ;
return F_56 ( V_14 , V_14 -> V_16 , & V_230 , F_9 ( V_14 ) ) ;
}
T_8 F_59 ( const struct V_240 * V_241 , struct V_220 * V_230 )
{
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
memcpy ( & V_230 -> V_225 . V_162 . V_227 , & V_241 -> V_149 ,
sizeof( V_230 -> V_225 . V_162 . V_227 ) ) ;
memcpy ( & V_230 -> V_225 . V_162 . V_229 , & V_241 -> V_242 ,
sizeof( V_230 -> V_225 . V_162 . V_229 ) ) ;
V_230 -> V_226 . V_150 = V_161 ;
V_230 -> V_22 . V_227 = V_241 -> V_243 ;
V_230 -> V_22 . V_229 = V_241 -> V_244 ;
V_230 -> V_52 . V_52 = V_241 -> V_245 ;
V_230 -> V_246 . V_165 = ( V_228 T_4 ) V_241 -> V_247 ;
V_230 -> V_237 . V_21 = V_241 -> V_248 ;
return F_45 ( V_230 ) ;
}
T_8 F_60 ( const struct V_249 * V_250 , struct V_220 * V_230 )
{
memset ( V_230 , 0 , sizeof( * V_230 ) ) ;
V_230 -> V_225 . V_148 . V_227 = V_250 -> V_149 ;
V_230 -> V_225 . V_148 . V_229 = V_250 -> V_242 ;
V_230 -> V_226 . V_150 = V_147 ;
V_230 -> V_22 . V_227 = V_250 -> V_251 ;
V_230 -> V_22 . V_229 = V_250 -> V_252 ;
V_230 -> V_52 . V_52 = V_250 -> V_253 ;
V_230 -> V_237 . V_21 = V_250 -> V_254 ;
return F_45 ( V_230 ) ;
}
static int T_9 F_61 ( void )
{
F_2 ( & V_272 ,
V_273 ,
F_62 ( V_273 ) ) ;
F_2 ( & V_238 ,
V_274 ,
F_62 ( V_274 ) ) ;
F_2 ( & V_275 ,
V_276 ,
F_62 ( V_276 ) ) ;
return 0 ;
}
