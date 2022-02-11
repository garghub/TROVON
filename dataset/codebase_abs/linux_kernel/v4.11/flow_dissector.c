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
bool F_10 ( const struct V_13 * V_14 ,
struct V_1 * V_1 ,
void * V_24 ,
void * V_16 , T_1 V_25 , int V_26 , int V_17 ,
unsigned int V_27 )
{
struct V_28 * V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
bool V_46 = false ;
T_3 V_21 = 0 ;
bool V_47 ;
if ( ! V_16 ) {
V_16 = V_14 -> V_16 ;
V_25 = F_11 ( V_14 ) ?
V_14 -> V_48 : V_14 -> V_49 ;
V_26 = F_12 ( V_14 ) ;
V_17 = F_9 ( V_14 ) ;
}
V_29 = F_13 ( V_1 ,
V_11 ,
V_24 ) ;
V_31 = F_13 ( V_1 ,
V_12 ,
V_24 ) ;
if ( F_4 ( V_1 ,
V_50 ) ) {
struct V_51 * V_52 = F_14 ( V_14 ) ;
struct V_53 * V_54 ;
V_54 = F_13 ( V_1 ,
V_50 ,
V_24 ) ;
memcpy ( V_54 , & V_52 -> V_55 , sizeof( * V_54 ) ) ;
}
V_56:
switch ( V_25 ) {
case F_15 ( V_57 ) : {
const struct V_58 * V_59 ;
struct V_58 V_60 ;
V_61:
V_59 = F_6 ( V_14 , V_26 , sizeof( V_60 ) , V_16 , V_17 , & V_60 ) ;
if ( ! V_59 || V_59 -> V_62 < 5 )
goto V_63;
V_26 += V_59 -> V_62 * 4 ;
V_21 = V_59 -> V_49 ;
if ( F_4 ( V_1 ,
V_64 ) ) {
V_33 = F_13 ( V_1 ,
V_64 ,
V_24 ) ;
memcpy ( & V_33 -> V_65 , & V_59 -> V_66 ,
sizeof( V_33 -> V_65 ) ) ;
V_29 -> V_67 = V_64 ;
}
if ( F_16 ( V_59 ) ) {
V_29 -> V_27 |= V_68 ;
if ( V_59 -> V_69 & F_15 ( V_70 ) ) {
goto V_71;
} else {
V_29 -> V_27 |= V_72 ;
if ( ! ( V_27 & V_73 ) )
goto V_71;
}
}
if ( V_27 & V_74 )
goto V_71;
break;
}
case F_15 ( V_75 ) : {
const struct V_76 * V_59 ;
struct V_76 V_60 ;
V_77:
V_59 = F_6 ( V_14 , V_26 , sizeof( V_60 ) , V_16 , V_17 , & V_60 ) ;
if ( ! V_59 )
goto V_63;
V_21 = V_59 -> V_78 ;
V_26 += sizeof( struct V_76 ) ;
if ( F_4 ( V_1 ,
V_79 ) ) {
V_33 = F_13 ( V_1 ,
V_79 ,
V_24 ) ;
memcpy ( & V_33 -> V_80 , & V_59 -> V_66 ,
sizeof( V_33 -> V_80 ) ) ;
V_29 -> V_67 = V_79 ;
}
if ( ( F_4 ( V_1 ,
V_81 ) ||
( V_27 & V_82 ) ) &&
F_17 ( V_59 ) ) {
T_2 V_83 = F_17 ( V_59 ) ;
if ( F_4 ( V_1 ,
V_81 ) ) {
V_41 = F_13 ( V_1 ,
V_81 ,
V_24 ) ;
V_41 -> V_83 = F_18 ( V_83 ) ;
}
if ( V_27 & V_82 )
goto V_71;
}
if ( V_27 & V_74 )
goto V_71;
break;
}
case F_15 ( V_84 ) :
case F_15 ( V_85 ) : {
const struct V_86 * V_87 ;
struct V_86 V_88 ;
bool V_89 = V_14 && F_11 ( V_14 ) ;
if ( V_89 )
V_25 = V_14 -> V_49 ;
if ( ! V_89 || F_19 ( V_14 -> V_49 ) ) {
V_87 = F_6 ( V_14 , V_26 , sizeof( V_88 ) ,
V_16 , V_17 , & V_88 ) ;
if ( ! V_87 )
goto V_63;
V_25 = V_87 -> V_90 ;
V_26 += sizeof( * V_87 ) ;
if ( V_46 )
goto V_56;
}
V_46 = true ;
if ( F_4 ( V_1 ,
V_91 ) ) {
V_43 = F_13 ( V_1 ,
V_91 ,
V_24 ) ;
if ( V_89 ) {
V_43 -> V_92 = F_20 ( V_14 ) ;
V_43 -> V_93 =
( F_21 ( V_14 ) >> V_94 ) ;
} else {
V_43 -> V_92 = F_22 ( V_87 -> V_95 ) &
V_96 ;
V_43 -> V_93 =
( F_22 ( V_87 -> V_95 ) &
V_97 ) >> V_94 ;
}
}
goto V_56;
}
case F_15 ( V_98 ) : {
struct {
struct V_99 V_100 ;
T_1 V_25 ;
} * V_100 , V_101 ;
V_100 = F_6 ( V_14 , V_26 , sizeof( V_101 ) , V_16 , V_17 , & V_101 ) ;
if ( ! V_100 )
goto V_63;
V_25 = V_100 -> V_25 ;
V_26 += V_102 ;
switch ( V_25 ) {
case F_15 ( V_103 ) :
goto V_61;
case F_15 ( V_104 ) :
goto V_77;
default:
goto V_63;
}
}
case F_15 ( V_105 ) : {
struct {
T_2 V_106 [ 3 ] ;
T_2 V_107 ;
} * V_100 , V_101 ;
V_100 = F_6 ( V_14 , V_26 , sizeof( V_101 ) , V_16 , V_17 , & V_101 ) ;
if ( ! V_100 )
goto V_63;
if ( F_4 ( V_1 ,
V_108 ) ) {
V_33 = F_13 ( V_1 ,
V_108 ,
V_24 ) ;
V_33 -> V_109 . V_107 = V_100 -> V_107 ;
V_29 -> V_67 = V_108 ;
}
goto V_71;
}
case F_15 ( V_110 ) :
case F_15 ( V_111 ) : {
struct V_112 * V_100 , V_101 [ 2 ] ;
V_113:
V_100 = F_6 ( V_14 , V_26 , sizeof( V_101 ) , V_16 ,
V_17 , & V_101 ) ;
if ( ! V_100 )
goto V_63;
if ( ( F_18 ( V_100 [ 0 ] . V_114 ) & V_115 ) >>
V_116 == V_117 ) {
if ( F_4 ( V_1 ,
V_118 ) ) {
V_45 = F_13 ( V_1 ,
V_118 ,
V_24 ) ;
V_45 -> V_119 = V_100 [ 1 ] . V_114 &
F_23 ( V_115 ) ;
}
goto V_71;
}
goto V_71;
}
case F_15 ( V_120 ) :
if ( ( V_17 - V_26 ) < V_121 )
goto V_63;
V_26 += V_121 ;
goto V_71;
case F_15 ( V_122 ) :
case F_15 ( V_123 ) : {
struct {
unsigned char V_124 [ V_125 ] ;
unsigned char V_126 [ 4 ] ;
unsigned char V_127 [ V_125 ] ;
unsigned char V_128 [ 4 ] ;
} * V_129 , V_130 ;
const struct V_131 * V_132 ;
struct V_131 V_133 ;
V_132 = F_6 ( V_14 , V_26 , sizeof( V_133 ) , V_16 ,
V_17 , & V_133 ) ;
if ( ! V_132 )
goto V_63;
if ( V_132 -> V_134 != F_15 ( V_135 ) ||
V_132 -> V_136 != F_15 ( V_57 ) ||
V_132 -> V_137 != V_125 ||
V_132 -> V_138 != 4 ||
( V_132 -> V_139 != F_15 ( V_140 ) &&
V_132 -> V_139 != F_15 ( V_141 ) ) )
goto V_63;
V_129 = F_6 ( V_14 , V_26 + sizeof( V_133 ) ,
sizeof( V_130 ) , V_16 ,
V_17 ,
& V_130 ) ;
if ( ! V_129 )
goto V_63;
if ( F_4 ( V_1 ,
V_142 ) ) {
V_35 = F_13 ( V_1 ,
V_142 ,
V_24 ) ;
memcpy ( & V_35 -> V_143 , V_129 -> V_126 ,
sizeof( V_35 -> V_143 ) ) ;
memcpy ( & V_35 -> V_144 , V_129 -> V_128 ,
sizeof( V_35 -> V_144 ) ) ;
V_35 -> V_145 = F_22 ( V_132 -> V_139 ) & 0xff ;
F_24 ( V_35 -> V_146 , V_129 -> V_124 ) ;
F_24 ( V_35 -> V_147 , V_129 -> V_127 ) ;
}
goto V_71;
}
default:
goto V_63;
}
V_148:
switch ( V_21 ) {
case V_149 : {
struct V_150 * V_100 , V_101 ;
T_4 V_151 ;
int V_9 = 0 ;
V_100 = F_6 ( V_14 , V_26 , sizeof( V_101 ) , V_16 , V_17 , & V_101 ) ;
if ( ! V_100 )
goto V_63;
if ( V_100 -> V_27 & V_152 )
break;
V_151 = F_22 ( V_100 -> V_27 & V_153 ) ;
if ( V_151 > 1 )
break;
V_25 = V_100 -> V_49 ;
if ( V_151 ) {
if ( ! ( V_25 == V_154 && ( V_100 -> V_27 & V_155 ) ) )
break;
}
V_9 += sizeof( struct V_150 ) ;
if ( V_100 -> V_27 & V_156 )
V_9 += sizeof( ( (struct V_157 * ) 0 ) -> V_158 ) +
sizeof( ( (struct V_157 * ) 0 ) -> V_159 ) ;
if ( V_100 -> V_27 & V_155 ) {
const T_2 * V_119 ;
T_2 V_160 ;
V_119 = F_6 ( V_14 , V_26 + V_9 , sizeof( V_160 ) ,
V_16 , V_17 , & V_160 ) ;
if ( ! V_119 )
goto V_63;
if ( F_4 ( V_1 ,
V_161 ) ) {
V_45 = F_13 ( V_1 ,
V_161 ,
V_24 ) ;
if ( V_151 == 0 )
V_45 -> V_119 = * V_119 ;
else
V_45 -> V_119 = * V_119 & V_162 ;
}
V_9 += sizeof( ( (struct V_157 * ) 0 ) -> V_6 ) ;
}
if ( V_100 -> V_27 & V_163 )
V_9 += sizeof( ( (struct V_164 * ) 0 ) -> V_165 ) ;
if ( V_151 == 0 ) {
if ( V_25 == F_15 ( V_166 ) ) {
const struct V_51 * V_52 ;
struct V_51 V_167 ;
V_52 = F_6 ( V_14 , V_26 + V_9 ,
sizeof( V_167 ) ,
V_16 , V_17 , & V_167 ) ;
if ( ! V_52 )
goto V_63;
V_25 = V_52 -> V_168 ;
V_9 += sizeof( * V_52 ) ;
if ( V_169 )
V_17 = ( V_26 + V_9 ) ;
}
} else {
T_3 V_170 [ V_171 ] ;
T_3 * V_172 ;
if ( V_100 -> V_27 & V_173 )
V_9 += sizeof( ( (struct V_164 * ) 0 ) -> V_174 ) ;
V_172 = F_6 ( V_14 , V_26 + V_9 ,
sizeof( V_170 ) ,
V_16 , V_17 , V_170 ) ;
if ( ! V_172 )
goto V_63;
switch ( F_25 ( V_172 ) ) {
case V_103 :
V_25 = F_15 ( V_57 ) ;
break;
case V_104 :
V_25 = F_15 ( V_75 ) ;
break;
default:
break;
}
V_9 += V_171 ;
}
V_26 += V_9 ;
V_29 -> V_27 |= V_175 ;
if ( V_27 & V_176 )
goto V_71;
goto V_56;
}
case V_177 :
case V_178 :
case V_179 : {
T_3 V_180 [ 2 ] , * V_181 ;
if ( V_25 != F_15 ( V_75 ) )
break;
V_181 = F_6 ( V_14 , V_26 , sizeof( V_180 ) ,
V_16 , V_17 , & V_180 ) ;
if ( ! V_181 )
goto V_63;
V_21 = V_181 [ 0 ] ;
V_26 += ( V_181 [ 1 ] + 1 ) << 3 ;
goto V_148;
}
case V_182 : {
struct V_183 V_184 , * V_185 ;
if ( V_25 != F_15 ( V_75 ) )
break;
V_185 = F_6 ( V_14 , V_26 , sizeof( V_184 ) ,
V_16 , V_17 , & V_184 ) ;
if ( ! V_185 )
goto V_63;
V_29 -> V_27 |= V_68 ;
V_26 += sizeof( V_184 ) ;
V_21 = V_185 -> V_78 ;
if ( ! ( V_185 -> V_69 & F_15 ( V_186 ) ) ) {
V_29 -> V_27 |= V_72 ;
if ( V_27 & V_73 )
goto V_148;
}
goto V_71;
}
case V_187 :
V_25 = F_15 ( V_57 ) ;
V_29 -> V_27 |= V_175 ;
if ( V_27 & V_176 )
goto V_71;
goto V_61;
case V_188 :
V_25 = F_15 ( V_75 ) ;
V_29 -> V_27 |= V_175 ;
if ( V_27 & V_176 )
goto V_71;
goto V_77;
case V_189 :
V_25 = F_15 ( V_110 ) ;
goto V_113;
default:
break;
}
if ( F_4 ( V_1 ,
V_190 ) ) {
V_37 = F_13 ( V_1 ,
V_190 ,
V_24 ) ;
V_37 -> V_22 = F_7 ( V_14 , V_26 , V_21 ,
V_16 , V_17 ) ;
}
if ( F_4 ( V_1 ,
V_191 ) ) {
V_39 = F_13 ( V_1 ,
V_191 ,
V_24 ) ;
V_39 -> V_192 = F_5 ( V_14 , V_26 , V_16 , V_17 ) ;
}
V_71:
V_47 = true ;
V_29 -> V_20 = ( T_4 ) V_26 ;
V_193:
V_31 -> V_194 = V_25 ;
V_31 -> V_21 = V_21 ;
return V_47 ;
V_63:
V_47 = false ;
V_29 -> V_20 = F_26 ( T_4 , V_26 , V_14 ? V_14 -> V_195 : V_17 ) ;
goto V_193;
}
static T_5 void F_27 ( void )
{
F_28 ( & V_196 , sizeof( V_196 ) ) ;
}
static T_5 T_6 F_29 ( const T_6 * V_197 , T_6 V_198 ,
T_6 V_199 )
{
return F_30 ( V_197 , V_198 , V_199 ) ;
}
static inline const T_6 * F_31 ( const struct V_200 * V_201 )
{
const void * V_202 = V_201 ;
F_32 ( V_203 % sizeof( T_6 ) ) ;
return ( const T_6 * ) ( V_202 + V_203 ) ;
}
static inline T_7 F_33 ( const struct V_200 * V_201 )
{
T_7 V_204 = V_203 + sizeof( V_201 -> V_205 ) ;
F_32 ( ( sizeof( * V_201 ) - V_203 ) % sizeof( T_6 ) ) ;
F_32 ( F_34 ( F_35 ( * V_201 ) , V_205 ) !=
sizeof( * V_201 ) - sizeof( V_201 -> V_205 ) ) ;
switch ( V_201 -> V_206 . V_67 ) {
case V_64 :
V_204 -= sizeof( V_201 -> V_205 . V_65 ) ;
break;
case V_79 :
V_204 -= sizeof( V_201 -> V_205 . V_80 ) ;
break;
case V_108 :
V_204 -= sizeof( V_201 -> V_205 . V_109 ) ;
break;
}
return ( sizeof( * V_201 ) - V_204 ) / sizeof( T_6 ) ;
}
T_2 F_36 ( const struct V_200 * V_201 )
{
switch ( V_201 -> V_206 . V_67 ) {
case V_64 :
return V_201 -> V_205 . V_65 . V_207 ;
case V_79 :
return ( V_208 T_2 ) F_37 (
& V_201 -> V_205 . V_80 . V_207 ) ;
case V_108 :
return V_201 -> V_205 . V_109 . V_107 ;
default:
return 0 ;
}
}
T_2 F_38 ( const struct V_200 * V_201 )
{
switch ( V_201 -> V_206 . V_67 ) {
case V_64 :
return V_201 -> V_205 . V_65 . V_209 ;
case V_79 :
return ( V_208 T_2 ) F_37 (
& V_201 -> V_205 . V_80 . V_209 ) ;
default:
return 0 ;
}
}
static inline void F_39 ( struct V_200 * V_210 )
{
int V_211 , V_8 ;
switch ( V_210 -> V_206 . V_67 ) {
case V_64 :
V_211 = ( V_208 T_6 ) V_210 -> V_205 . V_65 . V_209 -
( V_208 T_6 ) V_210 -> V_205 . V_65 . V_207 ;
if ( ( V_211 < 0 ) ||
( V_211 == 0 &&
( ( V_208 T_4 ) V_210 -> V_22 . V_209 <
( V_208 T_4 ) V_210 -> V_22 . V_207 ) ) ) {
F_40 ( V_210 -> V_205 . V_65 . V_207 , V_210 -> V_205 . V_65 . V_209 ) ;
F_40 ( V_210 -> V_22 . V_207 , V_210 -> V_22 . V_209 ) ;
}
break;
case V_79 :
V_211 = memcmp ( & V_210 -> V_205 . V_80 . V_209 ,
& V_210 -> V_205 . V_80 . V_207 ,
sizeof( V_210 -> V_205 . V_80 . V_209 ) ) ;
if ( ( V_211 < 0 ) ||
( V_211 == 0 &&
( ( V_208 T_4 ) V_210 -> V_22 . V_209 <
( V_208 T_4 ) V_210 -> V_22 . V_207 ) ) ) {
for ( V_8 = 0 ; V_8 < 4 ; V_8 ++ )
F_40 ( V_210 -> V_205 . V_80 . V_207 . V_212 [ V_8 ] ,
V_210 -> V_205 . V_80 . V_209 . V_212 [ V_8 ] ) ;
F_40 ( V_210 -> V_22 . V_207 , V_210 -> V_22 . V_209 ) ;
}
break;
}
}
static inline T_6 F_41 ( struct V_200 * V_210 , T_6 V_199 )
{
T_6 V_213 ;
F_39 ( V_210 ) ;
V_213 = F_29 ( F_31 ( V_210 ) ,
F_33 ( V_210 ) , V_199 ) ;
if ( ! V_213 )
V_213 = 1 ;
return V_213 ;
}
T_6 F_42 ( struct V_200 * V_210 )
{
F_27 () ;
return F_41 ( V_210 , V_196 ) ;
}
static inline T_6 F_43 ( const struct V_13 * V_14 ,
struct V_200 * V_210 , T_6 V_199 )
{
F_44 ( V_14 , V_210 ,
V_82 ) ;
return F_41 ( V_210 , V_199 ) ;
}
void F_45 ( struct V_214 * V_215 ,
const struct V_200 * V_201 )
{
struct V_216 * V_16 =
(struct V_216 * ) V_215 ;
F_32 ( sizeof( * V_16 ) > sizeof( * V_215 ) ) ;
memset ( V_215 , 0 , sizeof( * V_215 ) ) ;
V_16 -> V_194 = V_201 -> V_217 . V_194 ;
V_16 -> V_21 = V_201 -> V_217 . V_21 ;
V_16 -> V_22 = V_201 -> V_22 . V_22 ;
V_16 -> V_207 = V_201 -> V_205 . V_65 . V_207 ;
V_16 -> V_209 = V_201 -> V_205 . V_65 . V_209 ;
}
T_6 F_46 ( const struct V_13 * V_14 )
{
struct V_200 V_210 ;
F_27 () ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
F_10 ( V_14 , & V_218 , & V_210 ,
NULL , 0 , 0 , 0 ,
V_82 ) ;
return F_41 ( & V_210 , V_196 ) ;
}
void F_47 ( struct V_13 * V_14 )
{
struct V_200 V_210 ;
T_6 V_213 ;
F_27 () ;
V_213 = F_43 ( V_14 , & V_210 , V_196 ) ;
F_48 ( V_14 , V_213 , F_49 ( & V_210 ) ) ;
}
T_8 F_50 ( const struct V_13 * V_14 , T_6 V_219 )
{
struct V_200 V_210 ;
return F_43 ( V_14 , & V_210 , V_219 ) ;
}
T_8 F_51 ( struct V_13 * V_14 , const struct V_220 * V_221 )
{
struct V_200 V_210 ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
memcpy ( & V_210 . V_205 . V_80 . V_207 , & V_221 -> V_66 ,
sizeof( V_210 . V_205 . V_80 . V_207 ) ) ;
memcpy ( & V_210 . V_205 . V_80 . V_209 , & V_221 -> V_222 ,
sizeof( V_210 . V_205 . V_80 . V_209 ) ) ;
V_210 . V_206 . V_67 = V_79 ;
V_210 . V_22 . V_207 = V_221 -> V_223 ;
V_210 . V_22 . V_209 = V_221 -> V_224 ;
V_210 . V_119 . V_119 = V_221 -> V_225 ;
V_210 . V_226 . V_83 = ( V_208 T_6 ) V_221 -> V_227 ;
V_210 . V_217 . V_21 = V_221 -> V_228 ;
F_48 ( V_14 , F_42 ( & V_210 ) ,
F_49 ( & V_210 ) ) ;
return V_14 -> V_213 ;
}
T_8 F_52 ( struct V_13 * V_14 , const struct V_229 * V_230 )
{
struct V_200 V_210 ;
memset ( & V_210 , 0 , sizeof( V_210 ) ) ;
V_210 . V_205 . V_65 . V_207 = V_230 -> V_66 ;
V_210 . V_205 . V_65 . V_209 = V_230 -> V_222 ;
V_210 . V_206 . V_67 = V_64 ;
V_210 . V_22 . V_207 = V_230 -> V_231 ;
V_210 . V_22 . V_209 = V_230 -> V_232 ;
V_210 . V_119 . V_119 = V_230 -> V_233 ;
V_210 . V_217 . V_21 = V_230 -> V_234 ;
F_48 ( V_14 , F_42 ( & V_210 ) ,
F_49 ( & V_210 ) ) ;
return V_14 -> V_213 ;
}
T_6 F_53 ( const struct V_13 * V_14 , void * V_16 ,
const struct V_200 * V_210 , int V_17 )
{
T_6 V_15 = V_210 -> V_206 . V_20 ;
if ( ( V_210 -> V_206 . V_27 & V_68 ) &&
! ( V_210 -> V_206 . V_27 & V_72 ) )
return V_15 ;
switch ( V_210 -> V_217 . V_21 ) {
case V_235 : {
const T_3 * V_236 ;
T_3 V_237 ;
V_236 = F_6 ( V_14 , V_15 + 12 , sizeof( V_237 ) ,
V_16 , V_17 , & V_237 ) ;
if ( ! V_236 )
return V_15 ;
V_15 += F_54 ( T_6 , sizeof( struct V_238 ) , ( * V_236 & 0xF0 ) >> 2 ) ;
break;
}
case V_239 :
case V_240 :
V_15 += sizeof( struct V_241 ) ;
break;
case V_242 :
V_15 += sizeof( struct V_243 ) ;
break;
case V_244 :
V_15 += sizeof( struct V_245 ) ;
break;
case V_246 :
V_15 += sizeof( struct V_247 ) ;
break;
case V_248 :
V_15 += sizeof( struct V_249 ) ;
break;
case V_250 :
V_15 += sizeof( struct V_251 ) ;
break;
}
return V_15 ;
}
T_6 F_55 ( const struct V_13 * V_14 )
{
struct V_200 V_210 ;
if ( ! F_44 ( V_14 , & V_210 , 0 ) )
return 0 ;
return F_53 ( V_14 , V_14 -> V_16 , & V_210 , F_9 ( V_14 ) ) ;
}
T_8 F_56 ( const struct V_220 * V_221 , struct V_200 * V_210 )
{
memset ( V_210 , 0 , sizeof( * V_210 ) ) ;
memcpy ( & V_210 -> V_205 . V_80 . V_207 , & V_221 -> V_66 ,
sizeof( V_210 -> V_205 . V_80 . V_207 ) ) ;
memcpy ( & V_210 -> V_205 . V_80 . V_209 , & V_221 -> V_222 ,
sizeof( V_210 -> V_205 . V_80 . V_209 ) ) ;
V_210 -> V_206 . V_67 = V_79 ;
V_210 -> V_22 . V_207 = V_221 -> V_223 ;
V_210 -> V_22 . V_209 = V_221 -> V_224 ;
V_210 -> V_119 . V_119 = V_221 -> V_225 ;
V_210 -> V_226 . V_83 = ( V_208 T_6 ) V_221 -> V_227 ;
V_210 -> V_217 . V_21 = V_221 -> V_228 ;
return F_42 ( V_210 ) ;
}
T_8 F_57 ( const struct V_229 * V_230 , struct V_200 * V_210 )
{
memset ( V_210 , 0 , sizeof( * V_210 ) ) ;
V_210 -> V_205 . V_65 . V_207 = V_230 -> V_66 ;
V_210 -> V_205 . V_65 . V_209 = V_230 -> V_222 ;
V_210 -> V_206 . V_67 = V_64 ;
V_210 -> V_22 . V_207 = V_230 -> V_231 ;
V_210 -> V_22 . V_209 = V_230 -> V_232 ;
V_210 -> V_119 . V_119 = V_230 -> V_233 ;
V_210 -> V_217 . V_21 = V_230 -> V_234 ;
return F_42 ( V_210 ) ;
}
static int T_9 F_58 ( void )
{
F_2 ( & V_252 ,
V_253 ,
F_59 ( V_253 ) ) ;
F_2 ( & V_218 ,
V_254 ,
F_59 ( V_254 ) ) ;
F_2 ( & V_255 ,
V_256 ,
F_59 ( V_256 ) ) ;
return 0 ;
}
