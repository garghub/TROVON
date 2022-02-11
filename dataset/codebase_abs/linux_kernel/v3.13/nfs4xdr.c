static T_1
F_1 ( char * V_1 , int V_2 )
{
int V_3 ;
if ( V_2 == 0 )
return V_4 ;
if ( F_2 ( V_1 , V_2 ) )
return V_5 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ )
if ( V_1 [ V_3 ] == '/' )
return V_5 ;
return 0 ;
}
static void F_3 ( struct V_6 * V_7 )
{
V_7 -> V_8 = F_4 ( V_7 -> V_9 [ 0 ] ) ;
V_7 -> V_9 ++ ;
if ( V_7 -> V_10 < V_11 ) {
V_7 -> V_12 = V_7 -> V_8 + ( V_7 -> V_10 >> 2 ) ;
V_7 -> V_10 = 0 ;
} else {
V_7 -> V_12 = V_7 -> V_8 + ( V_11 >> 2 ) ;
V_7 -> V_10 -= V_11 ;
}
}
static T_1 * F_5 ( struct V_6 * V_7 , T_2 V_13 )
{
unsigned int V_14 = ( char * ) V_7 -> V_12 - ( char * ) V_7 -> V_8 ;
T_1 * V_8 ;
if ( V_14 + V_7 -> V_10 < V_13 )
return NULL ;
if ( V_14 + V_11 < V_13 )
return NULL ;
if ( V_13 <= sizeof( V_7 -> V_15 ) )
V_8 = V_7 -> V_15 ;
else {
F_6 ( V_7 -> V_16 ) ;
V_8 = V_7 -> V_16 = F_7 ( V_13 , V_17 ) ;
if ( ! V_8 )
return NULL ;
}
memcpy ( V_8 , V_7 -> V_8 , V_14 ) ;
F_3 ( V_7 ) ;
memcpy ( ( ( char * ) V_8 ) + V_14 , V_7 -> V_8 , ( V_13 - V_14 ) ) ;
V_7 -> V_8 += F_8 ( V_13 - V_14 ) ;
return V_8 ;
}
static int F_9 ( T_3 * V_18 )
{
return ( V_18 -> V_19 == 0 ) && ( V_18 -> V_20 == 0 ) ;
}
static int
F_10 ( struct V_6 * V_7 ,
void (* F_11)( const void * ) , void * V_8 )
{
struct V_21 * V_22 ;
V_22 = F_7 ( sizeof( * V_22 ) , V_17 ) ;
if ( ! V_22 )
return - V_23 ;
V_22 -> V_24 = V_8 ;
V_22 -> F_11 = F_11 ;
V_22 -> V_25 = V_7 -> V_26 ;
V_7 -> V_26 = V_22 ;
return 0 ;
}
static char * F_12 ( struct V_6 * V_7 , T_1 * V_8 , int V_13 )
{
if ( V_8 == V_7 -> V_15 ) {
V_8 = F_13 ( V_7 -> V_15 , V_13 , V_17 ) ;
if ( ! V_8 )
return NULL ;
} else {
F_14 ( V_8 != V_7 -> V_16 ) ;
V_7 -> V_16 = NULL ;
}
if ( F_10 ( V_7 , F_6 , V_8 ) ) {
F_6 ( V_8 ) ;
return NULL ;
} else
return ( char * ) V_8 ;
}
static T_1
F_15 ( struct V_6 * V_7 , T_2 * V_27 )
{
T_2 V_28 ;
V_29 ;
V_27 [ 0 ] = 0 ;
V_27 [ 1 ] = 0 ;
V_27 [ 2 ] = 0 ;
F_16 ( 4 ) ;
F_17 ( V_28 ) ;
if ( V_28 > 1000 )
goto V_30;
F_16 ( V_28 << 2 ) ;
if ( V_28 > 0 )
F_17 ( V_27 [ 0 ] ) ;
if ( V_28 > 1 )
F_17 ( V_27 [ 1 ] ) ;
if ( V_28 > 2 )
F_17 ( V_27 [ 2 ] ) ;
V_31 ;
}
static T_1
F_18 ( struct V_6 * V_7 , T_2 * V_27 ,
struct V_32 * V_32 , struct V_33 * * V_34 ,
struct V_35 * V_36 )
{
int V_37 , V_2 = 0 ;
T_2 V_38 ;
char * V_24 ;
int V_39 ;
V_29 ;
V_32 -> V_40 = 0 ;
if ( ( V_41 = F_15 ( V_7 , V_27 ) ) )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_37 ) ;
if ( V_27 [ 0 ] & V_42 ) {
F_16 ( 8 ) ;
V_2 += 8 ;
F_19 ( V_32 -> V_43 ) ;
V_32 -> V_40 |= V_44 ;
}
if ( V_27 [ 0 ] & V_45 ) {
T_2 V_46 ;
struct V_47 * V_48 ;
F_16 ( 4 ) ; V_2 += 4 ;
F_17 ( V_46 ) ;
if ( V_46 > V_49 )
return V_50 ;
* V_34 = F_20 ( V_46 ) ;
if ( * V_34 == NULL ) {
V_39 = - V_23 ;
goto V_51;
}
F_10 ( V_7 , F_6 , * V_34 ) ;
( * V_34 ) -> V_52 = V_46 ;
for ( V_48 = ( * V_34 ) -> V_53 ; V_48 < ( * V_34 ) -> V_53 + V_46 ; V_48 ++ ) {
F_16 ( 16 ) ; V_2 += 16 ;
F_17 ( V_48 -> type ) ;
F_17 ( V_48 -> V_54 ) ;
F_17 ( V_48 -> V_55 ) ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += F_8 ( V_38 ) << 2 ;
F_21 ( V_24 , V_38 ) ;
V_48 -> V_56 = F_22 ( V_24 , V_38 ) ;
V_41 = V_57 ;
if ( V_48 -> V_56 != V_58 )
;
else if ( V_48 -> V_54 & V_59 )
V_41 = F_23 ( V_7 -> V_60 ,
V_24 , V_38 , & V_48 -> V_61 ) ;
else
V_41 = F_24 ( V_7 -> V_60 ,
V_24 , V_38 , & V_48 -> V_62 ) ;
if ( V_41 )
return V_41 ;
}
} else
* V_34 = NULL ;
if ( V_27 [ 1 ] & V_63 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_32 -> V_64 ) ;
V_32 -> V_64 &= ( V_65 | V_66 ) ;
V_32 -> V_40 |= V_67 ;
}
if ( V_27 [ 1 ] & V_68 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += ( F_8 ( V_38 ) << 2 ) ;
F_21 ( V_24 , V_38 ) ;
if ( ( V_41 = F_24 ( V_7 -> V_60 , V_24 , V_38 , & V_32 -> V_69 ) ) )
return V_41 ;
V_32 -> V_40 |= V_70 ;
}
if ( V_27 [ 1 ] & V_71 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
V_2 += ( F_8 ( V_38 ) << 2 ) ;
F_21 ( V_24 , V_38 ) ;
if ( ( V_41 = F_23 ( V_7 -> V_60 , V_24 , V_38 , & V_32 -> V_72 ) ) )
return V_41 ;
V_32 -> V_40 |= V_73 ;
}
if ( V_27 [ 1 ] & V_74 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
switch ( V_38 ) {
case V_75 :
F_16 ( 12 ) ;
V_2 += 12 ;
F_19 ( V_32 -> V_76 . V_77 ) ;
F_17 ( V_32 -> V_76 . V_78 ) ;
if ( V_32 -> V_76 . V_78 >= ( T_2 ) 1000000000 )
return V_4 ;
V_32 -> V_40 |= ( V_79 | V_80 ) ;
break;
case V_81 :
V_32 -> V_40 |= V_79 ;
break;
default:
goto V_30;
}
}
if ( V_27 [ 1 ] & V_82 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
switch ( V_38 ) {
case V_75 :
F_16 ( 12 ) ;
V_2 += 12 ;
F_19 ( V_32 -> V_83 . V_77 ) ;
F_17 ( V_32 -> V_83 . V_78 ) ;
if ( V_32 -> V_83 . V_78 >= ( T_2 ) 1000000000 )
return V_4 ;
V_32 -> V_40 |= ( V_84 | V_85 ) ;
break;
case V_81 :
V_32 -> V_40 |= V_84 ;
break;
default:
goto V_30;
}
}
V_36 -> V_2 = 0 ;
#ifdef F_25
if ( V_27 [ 2 ] & V_86 ) {
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( 4 ) ;
V_2 += 4 ;
F_17 ( V_38 ) ;
F_16 ( V_38 ) ;
if ( V_38 > V_87 )
return V_88 ;
V_2 += ( F_8 ( V_38 ) << 2 ) ;
F_21 ( V_24 , V_38 ) ;
V_36 -> V_89 = F_26 ( V_38 + 1 , V_17 ) ;
if ( ! V_36 -> V_89 )
return V_90 ;
V_36 -> V_2 = V_38 ;
F_10 ( V_7 , F_6 , V_36 -> V_89 ) ;
memcpy ( V_36 -> V_89 , V_24 , V_38 ) ;
}
#endif
if ( V_27 [ 0 ] & ~ V_91
|| V_27 [ 1 ] & ~ V_92
|| V_27 [ 2 ] & ~ V_93 )
F_16 ( V_37 - V_2 ) ;
else if ( V_2 != V_37 )
goto V_30;
V_31 ;
V_51:
V_41 = F_27 ( V_39 ) ;
goto V_94;
}
static T_1
F_28 ( struct V_6 * V_7 , T_4 * V_95 )
{
V_29 ;
F_16 ( sizeof( T_4 ) ) ;
F_17 ( V_95 -> V_96 ) ;
F_29 ( & V_95 -> V_97 , sizeof( V_98 ) ) ;
V_31 ;
}
static T_1
F_30 ( struct V_6 * V_7 , struct V_99 * V_100 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_100 -> V_101 ) ;
V_31 ;
}
static T_1 F_31 ( struct V_6 * V_7 , struct V_102 * V_103 )
{
V_29 ;
T_2 V_104 , V_105 , V_106 ;
char * V_107 ;
int V_3 ;
int V_108 ;
F_16 ( 4 ) ;
F_17 ( V_108 ) ;
if ( V_108 )
V_103 -> V_109 = ( T_2 ) ( - 1 ) ;
else
V_103 -> V_109 = 0 ;
for ( V_3 = 0 ; V_3 < V_108 ; ++ V_3 ) {
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
switch ( V_104 ) {
case V_110 :
if ( V_103 -> V_109 == ( T_2 ) ( - 1 ) )
V_103 -> V_109 = V_110 ;
break;
case V_111 :
F_16 ( 8 ) ;
F_17 ( V_104 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 ) ;
F_32 ( V_107 , V_104 ) ;
F_16 ( 8 ) ;
F_17 ( V_105 ) ;
F_17 ( V_106 ) ;
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 * 4 ) ;
if ( V_103 -> V_109 == ( T_2 ) ( - 1 ) ) {
T_5 V_112 = F_33 ( & V_113 , V_105 ) ;
T_6 V_114 = F_34 ( & V_113 , V_106 ) ;
if ( F_35 ( V_112 ) && F_36 ( V_114 ) ) {
V_103 -> V_105 = V_112 ;
V_103 -> V_106 = V_114 ;
V_103 -> V_109 = V_111 ;
} else {
F_37 ( L_1
L_2 ) ;
}
}
break;
case V_115 :
F_37 ( L_3
L_4 ) ;
F_16 ( 8 ) ;
F_17 ( V_104 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 ) ;
V_8 += F_8 ( V_104 ) ;
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 ) ;
break;
default:
F_37 ( L_5 ) ;
return V_4 ;
}
}
V_31 ;
}
static T_1 F_38 ( struct V_6 * V_7 , struct V_116 * V_117 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_117 -> V_118 ) ;
F_31 ( V_7 , & V_117 -> V_119 ) ;
V_31 ;
}
static T_1 F_39 ( struct V_6 * V_7 , struct V_120 * V_121 )
{
V_29 ;
F_16 ( V_122 + 8 ) ;
F_29 ( V_121 -> V_123 . V_89 , V_122 ) ;
F_17 ( V_121 -> V_124 ) ;
V_31 ;
}
static T_1
F_40 ( struct V_6 * V_7 , struct V_125 * V_126 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_126 -> V_127 ) ;
return F_28 ( V_7 , & V_126 -> V_128 ) ;
V_31 ;
}
static T_1
F_41 ( struct V_6 * V_7 , struct V_129 * V_130 )
{
V_29 ;
F_16 ( 12 ) ;
F_19 ( V_130 -> V_131 ) ;
F_17 ( V_130 -> V_132 ) ;
V_31 ;
}
static T_1
F_42 ( struct V_6 * V_7 , struct V_133 * V_134 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_134 -> V_135 ) ;
switch ( V_134 -> V_135 ) {
case V_136 :
F_16 ( 4 ) ;
F_17 ( V_134 -> V_137 ) ;
F_16 ( V_134 -> V_137 ) ;
F_32 ( V_134 -> V_138 , V_134 -> V_137 ) ;
break;
case V_139 :
case V_140 :
F_16 ( 8 ) ;
F_17 ( V_134 -> V_141 ) ;
F_17 ( V_134 -> V_142 ) ;
break;
case V_143 :
case V_144 :
case V_145 :
default:
break;
}
F_16 ( 4 ) ;
F_17 ( V_134 -> V_146 ) ;
F_16 ( V_134 -> V_146 ) ;
F_32 ( V_134 -> V_147 , V_134 -> V_146 ) ;
if ( ( V_41 = F_1 ( V_134 -> V_147 , V_134 -> V_146 ) ) )
return V_41 ;
V_41 = F_18 ( V_7 , V_134 -> V_148 , & V_134 -> V_149 ,
& V_134 -> V_150 , & V_134 -> V_151 ) ;
if ( V_41 )
goto V_94;
V_31 ;
}
static inline T_1
F_43 ( struct V_6 * V_7 , struct V_152 * V_153 )
{
return F_28 ( V_7 , & V_153 -> V_154 ) ;
}
static inline T_1
F_44 ( struct V_6 * V_7 , struct V_155 * V_156 )
{
return F_15 ( V_7 , V_156 -> V_157 ) ;
}
static T_1
F_45 ( struct V_6 * V_7 , struct V_158 * V_159 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_159 -> V_160 ) ;
F_16 ( V_159 -> V_160 ) ;
F_32 ( V_159 -> V_161 , V_159 -> V_160 ) ;
if ( ( V_41 = F_1 ( V_159 -> V_161 , V_159 -> V_160 ) ) )
return V_41 ;
V_31 ;
}
static T_1
F_46 ( struct V_6 * V_7 , struct V_162 * V_163 )
{
V_29 ;
F_16 ( 28 ) ;
F_17 ( V_163 -> V_164 ) ;
if ( ( V_163 -> V_164 < V_165 ) || ( V_163 -> V_164 > V_166 ) )
goto V_30;
F_17 ( V_163 -> V_167 ) ;
F_19 ( V_163 -> V_168 ) ;
F_19 ( V_163 -> V_169 ) ;
F_17 ( V_163 -> V_170 ) ;
if ( V_163 -> V_170 ) {
F_16 ( 4 ) ;
F_17 ( V_163 -> V_171 ) ;
V_41 = F_28 ( V_7 , & V_163 -> V_172 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 8 + sizeof( T_3 ) ) ;
F_17 ( V_163 -> V_173 ) ;
F_29 ( & V_163 -> V_174 , sizeof( T_3 ) ) ;
F_17 ( V_163 -> V_175 . V_2 ) ;
F_16 ( V_163 -> V_175 . V_2 ) ;
F_21 ( V_163 -> V_175 . V_89 , V_163 -> V_175 . V_2 ) ;
} else {
V_41 = F_28 ( V_7 , & V_163 -> V_176 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_163 -> V_177 ) ;
}
V_31 ;
}
static T_1
F_47 ( struct V_6 * V_7 , struct V_178 * V_179 )
{
V_29 ;
F_16 ( 32 ) ;
F_17 ( V_179 -> V_180 ) ;
if( ( V_179 -> V_180 < V_165 ) || ( V_179 -> V_180 > V_166 ) )
goto V_30;
F_19 ( V_179 -> V_181 ) ;
F_19 ( V_179 -> V_182 ) ;
F_29 ( & V_179 -> V_183 , 8 ) ;
F_17 ( V_179 -> V_184 . V_2 ) ;
F_16 ( V_179 -> V_184 . V_2 ) ;
F_21 ( V_179 -> V_184 . V_89 , V_179 -> V_184 . V_2 ) ;
V_31 ;
}
static T_1
F_48 ( struct V_6 * V_7 , struct V_185 * V_186 )
{
V_29 ;
F_16 ( 8 ) ;
F_17 ( V_186 -> V_187 ) ;
if ( ( V_186 -> V_187 < V_165 ) || ( V_186 -> V_187 > V_166 ) )
goto V_30;
F_17 ( V_186 -> V_188 ) ;
V_41 = F_28 ( V_7 , & V_186 -> V_189 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 16 ) ;
F_19 ( V_186 -> V_190 ) ;
F_19 ( V_186 -> V_191 ) ;
V_31 ;
}
static T_1
F_49 ( struct V_6 * V_7 , struct V_192 * V_193 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_193 -> V_194 ) ;
F_16 ( V_193 -> V_194 ) ;
F_32 ( V_193 -> V_195 , V_193 -> V_194 ) ;
if ( ( V_41 = F_1 ( V_193 -> V_195 , V_193 -> V_194 ) ) )
return V_41 ;
V_31 ;
}
static T_1 F_50 ( struct V_6 * V_7 , T_2 * V_196 , T_2 * V_197 , T_2 * V_198 )
{
T_1 * V_8 ;
T_2 V_199 ;
F_16 ( 4 ) ;
F_17 ( V_199 ) ;
* V_196 = V_199 & V_200 ;
* V_197 = V_199 & V_201 ;
if ( V_198 )
* V_198 = V_199 & V_202 ;
switch ( V_199 & V_200 ) {
case V_203 :
case V_204 :
case V_205 :
break;
default:
return V_206 ;
}
V_199 &= ~ V_200 ;
if ( ! V_199 )
return V_57 ;
if ( ! V_7 -> V_207 )
return V_206 ;
switch ( V_199 & V_201 ) {
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
break;
default:
return V_206 ;
}
V_199 &= ~ V_201 ;
if ( ! V_199 )
return V_57 ;
if ( ! V_198 )
return V_4 ;
switch ( V_199 ) {
case V_214 :
case V_215 :
case ( V_214 |
V_215 ) :
return V_57 ;
}
V_30:
return V_206 ;
}
static T_1 F_51 ( struct V_6 * V_7 , T_2 * V_216 )
{
T_1 * V_8 ;
F_16 ( 4 ) ;
F_17 ( * V_216 ) ;
if ( * V_216 & ~ V_217 )
return V_206 ;
return V_57 ;
V_30:
return V_206 ;
}
static T_1 F_52 ( struct V_6 * V_7 , struct V_35 * V_218 )
{
T_1 * V_8 ;
F_16 ( 4 ) ;
F_17 ( V_218 -> V_2 ) ;
if ( V_218 -> V_2 == 0 || V_218 -> V_2 > V_219 )
return V_206 ;
F_16 ( V_218 -> V_2 ) ;
F_32 ( V_218 -> V_89 , V_218 -> V_2 ) ;
return V_57 ;
V_30:
return V_206 ;
}
static T_1
F_53 ( struct V_6 * V_7 , struct V_220 * V_221 )
{
V_29 ;
T_2 V_104 ;
memset ( V_221 -> V_222 , 0 , sizeof( V_221 -> V_222 ) ) ;
V_221 -> V_223 . V_40 = 0 ;
V_221 -> V_224 = NULL ;
V_221 -> V_225 = 0 ;
F_16 ( 4 ) ;
F_17 ( V_221 -> V_226 ) ;
V_41 = F_50 ( V_7 , & V_221 -> V_227 ,
& V_221 -> V_228 , & V_104 ) ;
if ( V_41 )
goto V_30;
V_41 = F_51 ( V_7 , & V_221 -> V_229 ) ;
if ( V_41 )
goto V_30;
F_16 ( sizeof( T_3 ) ) ;
F_29 ( & V_221 -> V_230 , sizeof( T_3 ) ) ;
V_41 = F_52 ( V_7 , & V_221 -> V_231 ) ;
if ( V_41 )
goto V_30;
F_16 ( 4 ) ;
F_17 ( V_221 -> V_232 ) ;
switch ( V_221 -> V_232 ) {
case V_233 :
break;
case V_234 :
F_16 ( 4 ) ;
F_17 ( V_221 -> V_235 ) ;
switch ( V_221 -> V_235 ) {
case V_236 :
case V_237 :
V_41 = F_18 ( V_7 , V_221 -> V_222 ,
& V_221 -> V_223 , & V_221 -> V_238 , & V_221 -> V_239 ) ;
if ( V_41 )
goto V_94;
break;
case V_240 :
F_16 ( V_241 ) ;
F_29 ( V_221 -> V_242 . V_89 , V_241 ) ;
break;
case V_243 :
if ( V_7 -> V_207 < 1 )
goto V_30;
F_16 ( V_241 ) ;
F_29 ( V_221 -> V_242 . V_89 , V_241 ) ;
V_41 = F_18 ( V_7 , V_221 -> V_222 ,
& V_221 -> V_223 , & V_221 -> V_238 , & V_221 -> V_239 ) ;
if ( V_41 )
goto V_94;
break;
default:
goto V_30;
}
break;
default:
goto V_30;
}
F_16 ( 4 ) ;
F_17 ( V_221 -> V_244 ) ;
switch ( V_221 -> V_244 ) {
case V_245 :
case V_246 :
F_16 ( 4 ) ;
F_17 ( V_221 -> V_247 . V_2 ) ;
F_16 ( V_221 -> V_247 . V_2 ) ;
F_32 ( V_221 -> V_247 . V_89 , V_221 -> V_247 . V_2 ) ;
if ( ( V_41 = F_1 ( V_221 -> V_247 . V_89 , V_221 -> V_247 . V_2 ) ) )
return V_41 ;
break;
case V_248 :
F_16 ( 4 ) ;
F_17 ( V_221 -> V_249 ) ;
break;
case V_250 :
V_41 = F_28 ( V_7 , & V_221 -> V_251 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_221 -> V_247 . V_2 ) ;
F_16 ( V_221 -> V_247 . V_2 ) ;
F_32 ( V_221 -> V_247 . V_89 , V_221 -> V_247 . V_2 ) ;
if ( ( V_41 = F_1 ( V_221 -> V_247 . V_89 , V_221 -> V_247 . V_2 ) ) )
return V_41 ;
break;
case V_252 :
case V_253 :
if ( V_7 -> V_207 < 1 )
goto V_30;
break;
case V_254 :
if ( V_7 -> V_207 < 1 )
goto V_30;
V_41 = F_28 ( V_7 , & V_221 -> V_251 ) ;
if ( V_41 )
return V_41 ;
break;
default:
goto V_30;
}
V_31 ;
}
static T_1
F_54 ( struct V_6 * V_7 , struct V_255 * V_256 )
{
V_29 ;
if ( V_7 -> V_207 >= 1 )
return V_257 ;
V_41 = F_28 ( V_7 , & V_256 -> V_258 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_256 -> V_259 ) ;
V_31 ;
}
static T_1
F_55 ( struct V_6 * V_7 , struct V_260 * V_261 )
{
V_29 ;
V_41 = F_28 ( V_7 , & V_261 -> V_262 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 4 ) ;
F_17 ( V_261 -> V_263 ) ;
V_41 = F_50 ( V_7 , & V_261 -> V_264 ,
& V_261 -> V_265 , NULL ) ;
if ( V_41 )
return V_41 ;
V_41 = F_51 ( V_7 , & V_261 -> V_266 ) ;
if ( V_41 )
return V_41 ;
V_31 ;
}
static T_1
F_56 ( struct V_6 * V_7 , struct V_267 * V_268 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_268 -> V_269 ) ;
if ( V_268 -> V_269 > V_270 )
goto V_30;
F_16 ( V_268 -> V_269 ) ;
F_32 ( V_268 -> V_271 , V_268 -> V_269 ) ;
V_31 ;
}
static T_1
F_57 ( struct V_6 * V_7 , void * V_8 )
{
if ( V_7 -> V_207 == 0 )
return V_57 ;
return V_257 ;
}
static T_1
F_58 ( struct V_6 * V_7 , struct V_272 * V_273 )
{
V_29 ;
V_41 = F_28 ( V_7 , & V_273 -> V_274 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 12 ) ;
F_19 ( V_273 -> V_275 ) ;
F_17 ( V_273 -> V_276 ) ;
V_31 ;
}
static T_1
F_59 ( struct V_6 * V_7 , struct V_277 * V_278 )
{
V_29 ;
F_16 ( 24 ) ;
F_19 ( V_278 -> V_279 ) ;
F_29 ( V_278 -> V_280 . V_89 , sizeof( V_278 -> V_280 . V_89 ) ) ;
F_17 ( V_278 -> V_281 ) ;
F_17 ( V_278 -> V_282 ) ;
if ( ( V_41 = F_15 ( V_7 , V_278 -> V_283 ) ) )
goto V_94;
V_31 ;
}
static T_1
F_60 ( struct V_6 * V_7 , struct V_284 * remove )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( remove -> V_285 ) ;
F_16 ( remove -> V_285 ) ;
F_32 ( remove -> V_286 , remove -> V_285 ) ;
if ( ( V_41 = F_1 ( remove -> V_286 , remove -> V_285 ) ) )
return V_41 ;
V_31 ;
}
static T_1
F_61 ( struct V_6 * V_7 , struct V_287 * rename )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( rename -> V_288 ) ;
F_16 ( rename -> V_288 + 4 ) ;
F_32 ( rename -> V_289 , rename -> V_288 ) ;
F_17 ( rename -> V_290 ) ;
F_16 ( rename -> V_290 ) ;
F_32 ( rename -> V_291 , rename -> V_290 ) ;
if ( ( V_41 = F_1 ( rename -> V_289 , rename -> V_288 ) ) )
return V_41 ;
if ( ( V_41 = F_1 ( rename -> V_291 , rename -> V_290 ) ) )
return V_41 ;
V_31 ;
}
static T_1
F_62 ( struct V_6 * V_7 , T_3 * V_292 )
{
V_29 ;
if ( V_7 -> V_207 >= 1 )
return V_257 ;
F_16 ( sizeof( T_3 ) ) ;
F_29 ( V_292 , sizeof( T_3 ) ) ;
V_31 ;
}
static T_1
F_63 ( struct V_6 * V_7 ,
struct V_293 * V_294 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_294 -> V_295 ) ;
F_16 ( V_294 -> V_295 ) ;
F_32 ( V_294 -> V_296 , V_294 -> V_295 ) ;
V_41 = F_1 ( V_294 -> V_296 , V_294 -> V_295 ) ;
if ( V_41 )
return V_41 ;
V_31 ;
}
static T_1
F_64 ( struct V_6 * V_7 ,
struct V_297 * sin )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( sin -> V_298 ) ;
V_31 ;
}
static T_1
F_65 ( struct V_6 * V_7 , struct V_299 * V_300 )
{
T_1 V_41 ;
V_41 = F_28 ( V_7 , & V_300 -> V_301 ) ;
if ( V_41 )
return V_41 ;
return F_18 ( V_7 , V_300 -> V_302 , & V_300 -> V_303 ,
& V_300 -> V_304 , & V_300 -> V_305 ) ;
}
static T_1
F_66 ( struct V_6 * V_7 , struct V_306 * V_307 )
{
V_29 ;
if ( V_7 -> V_207 >= 1 )
return V_257 ;
F_16 ( V_241 ) ;
F_29 ( V_307 -> V_308 . V_89 , V_241 ) ;
V_41 = F_52 ( V_7 , & V_307 -> V_309 ) ;
if ( V_41 )
return V_206 ;
F_16 ( 8 ) ;
F_17 ( V_307 -> V_310 ) ;
F_17 ( V_307 -> V_311 ) ;
F_16 ( V_307 -> V_311 + 4 ) ;
F_32 ( V_307 -> V_312 , V_307 -> V_311 ) ;
F_17 ( V_307 -> V_313 ) ;
F_16 ( V_307 -> V_313 + 4 ) ;
F_32 ( V_307 -> V_314 , V_307 -> V_313 ) ;
F_17 ( V_307 -> V_315 ) ;
V_31 ;
}
static T_1
F_67 ( struct V_6 * V_7 , struct V_316 * V_317 )
{
V_29 ;
if ( V_7 -> V_207 >= 1 )
return V_257 ;
F_16 ( 8 + V_241 ) ;
F_29 ( & V_317 -> V_318 , 8 ) ;
F_29 ( & V_317 -> V_319 , V_241 ) ;
V_31 ;
}
static T_1
F_68 ( struct V_6 * V_7 , struct V_320 * V_321 )
{
V_29 ;
if ( ( V_41 = F_15 ( V_7 , V_321 -> V_322 ) ) )
goto V_94;
F_16 ( 4 ) ;
F_17 ( V_321 -> V_323 ) ;
F_16 ( V_321 -> V_323 ) ;
F_32 ( V_321 -> V_324 , V_321 -> V_323 ) ;
V_31 ;
}
static T_1
F_69 ( struct V_6 * V_7 , struct V_325 * V_326 )
{
int V_14 ;
int V_2 ;
V_29 ;
V_41 = F_28 ( V_7 , & V_326 -> V_327 ) ;
if ( V_41 )
return V_41 ;
F_16 ( 16 ) ;
F_19 ( V_326 -> V_328 ) ;
F_17 ( V_326 -> V_329 ) ;
if ( V_326 -> V_329 > 2 )
goto V_30;
F_17 ( V_326 -> V_330 ) ;
V_14 = ( char * ) V_7 -> V_12 - ( char * ) V_7 -> V_8 ;
if ( V_14 + V_7 -> V_10 < V_326 -> V_330 ) {
F_37 ( L_6 ,
__FILE__ , __LINE__ ) ;
goto V_30;
}
V_326 -> V_331 . V_332 = V_8 ;
V_326 -> V_331 . V_333 = V_14 ;
F_70 ( V_14 != ( F_8 ( V_14 ) << 2 ) ) ;
V_326 -> V_334 = V_7 -> V_9 ;
V_2 = F_8 ( V_326 -> V_330 ) << 2 ;
if ( V_2 >= V_14 ) {
int V_335 ;
V_2 -= V_14 ;
V_335 = V_2 >> V_336 ;
V_7 -> V_9 += V_335 ;
V_7 -> V_10 -= V_335 * V_11 ;
V_2 -= V_335 * V_11 ;
V_7 -> V_8 = ( T_1 * ) F_4 ( V_7 -> V_9 [ 0 ] ) ;
V_7 -> V_9 ++ ;
V_7 -> V_12 = V_7 -> V_8 + F_8 ( V_11 ) ;
}
V_7 -> V_8 += F_8 ( V_2 ) ;
V_31 ;
}
static T_1
F_71 ( struct V_6 * V_7 , struct V_337 * V_338 )
{
V_29 ;
if ( V_7 -> V_207 >= 1 )
return V_257 ;
F_16 ( 12 ) ;
F_29 ( & V_338 -> V_339 , sizeof( T_3 ) ) ;
F_17 ( V_338 -> V_340 . V_2 ) ;
F_16 ( V_338 -> V_340 . V_2 ) ;
F_21 ( V_338 -> V_340 . V_89 , V_338 -> V_340 . V_2 ) ;
if ( V_7 -> V_207 && ! F_9 ( & V_338 -> V_339 ) )
return V_4 ;
V_31 ;
}
static T_1
F_72 ( struct V_6 * V_7 ,
struct V_341 * V_342 )
{
int V_104 , V_15 ;
V_29 ;
F_16 ( V_241 ) ;
F_29 ( V_342 -> V_343 . V_89 , V_241 ) ;
V_41 = F_52 ( V_7 , & V_342 -> V_344 ) ;
if ( V_41 )
return V_206 ;
F_16 ( 4 ) ;
F_17 ( V_342 -> V_345 ) ;
F_16 ( 4 ) ;
F_17 ( V_342 -> V_346 ) ;
switch ( V_342 -> V_346 ) {
case V_347 :
break;
case V_348 :
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 * 4 ) ;
V_8 += V_104 ;
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 * 4 ) ;
V_8 += V_104 ;
break;
case V_349 :
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 * 4 ) ;
V_8 += V_104 ;
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 * 4 ) ;
V_8 += V_104 ;
F_16 ( 4 ) ;
F_17 ( V_15 ) ;
while ( V_15 -- ) {
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 ) ;
V_8 += F_8 ( V_104 ) ;
}
F_16 ( 4 ) ;
F_17 ( V_15 ) ;
while ( V_15 -- ) {
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 ) ;
V_8 += F_8 ( V_104 ) ;
}
F_16 ( 8 ) ;
F_17 ( V_104 ) ;
F_17 ( V_104 ) ;
break;
default:
goto V_30;
}
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
if ( V_104 > 1 )
goto V_30;
if ( V_104 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 ) ;
V_8 += F_8 ( V_104 ) ;
F_16 ( 4 ) ;
F_17 ( V_104 ) ;
F_16 ( V_104 ) ;
V_8 += F_8 ( V_104 ) ;
F_16 ( 12 ) ;
V_8 += 3 ;
}
V_31 ;
}
static T_1
F_73 ( struct V_6 * V_7 ,
struct V_350 * V_351 )
{
V_29 ;
T_2 V_104 ;
F_16 ( 16 ) ;
F_29 ( & V_351 -> V_292 , 8 ) ;
F_17 ( V_351 -> V_352 ) ;
F_17 ( V_351 -> V_345 ) ;
F_16 ( 28 ) ;
F_17 ( V_104 ) ;
F_17 ( V_351 -> V_353 . V_354 ) ;
F_17 ( V_351 -> V_353 . V_355 ) ;
F_17 ( V_351 -> V_353 . V_356 ) ;
F_17 ( V_351 -> V_353 . V_357 ) ;
F_17 ( V_351 -> V_353 . V_358 ) ;
F_17 ( V_351 -> V_353 . V_359 ) ;
if ( V_351 -> V_353 . V_359 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_351 -> V_353 . V_360 ) ;
} else if ( V_351 -> V_353 . V_359 > 1 ) {
F_37 ( L_7 ) ;
goto V_30;
}
F_16 ( 28 ) ;
F_17 ( V_104 ) ;
F_17 ( V_351 -> V_361 . V_354 ) ;
F_17 ( V_351 -> V_361 . V_355 ) ;
F_17 ( V_351 -> V_361 . V_356 ) ;
F_17 ( V_351 -> V_361 . V_357 ) ;
F_17 ( V_351 -> V_361 . V_358 ) ;
F_17 ( V_351 -> V_361 . V_359 ) ;
if ( V_351 -> V_361 . V_359 == 1 ) {
F_16 ( 4 ) ;
F_17 ( V_351 -> V_361 . V_360 ) ;
} else if ( V_351 -> V_361 . V_359 > 1 ) {
F_37 ( L_8 ) ;
goto V_30;
}
F_16 ( 4 ) ;
F_17 ( V_351 -> V_362 ) ;
F_31 ( V_7 , & V_351 -> V_363 ) ;
V_31 ;
}
static T_1
F_74 ( struct V_6 * V_7 ,
struct V_364 * V_365 )
{
V_29 ;
F_16 ( V_122 ) ;
F_29 ( V_365 -> V_123 . V_89 , V_122 ) ;
V_31 ;
}
static T_1
F_75 ( struct V_6 * V_7 ,
struct V_366 * V_367 )
{
V_29 ;
F_16 ( sizeof( T_4 ) ) ;
F_17 ( V_367 -> V_368 . V_96 ) ;
F_29 ( & V_367 -> V_368 . V_97 , sizeof( V_98 ) ) ;
V_31 ;
}
static T_1
F_76 ( struct V_6 * V_7 ,
struct V_369 * V_370 )
{
V_29 ;
F_16 ( V_122 + 16 ) ;
F_29 ( V_370 -> V_123 . V_89 , V_122 ) ;
F_17 ( V_370 -> V_352 ) ;
F_17 ( V_370 -> V_371 ) ;
F_17 ( V_370 -> V_372 ) ;
F_17 ( V_370 -> V_373 ) ;
V_31 ;
}
static T_1
F_77 ( struct V_6 * V_7 , struct V_374 * V_375 )
{
int V_3 ;
T_1 * V_8 , V_41 ;
struct V_376 * V_377 ;
F_16 ( 4 ) ;
V_375 -> V_378 = F_78 ( * V_8 ++ ) ;
F_79 ( & V_375 -> V_379 ) ;
for ( V_3 = 0 ; V_3 < V_375 -> V_378 ; V_3 ++ ) {
V_377 = F_7 ( sizeof( struct V_376 ) , V_17 ) ;
if ( ! V_377 ) {
V_41 = F_27 ( - V_23 ) ;
goto V_94;
}
F_10 ( V_7 , F_6 , V_377 ) ;
F_79 ( & V_377 -> V_380 ) ;
F_80 ( & V_377 -> V_380 , & V_375 -> V_379 ) ;
V_41 = F_28 ( V_7 , & V_377 -> V_381 ) ;
if ( V_41 )
goto V_94;
}
V_41 = 0 ;
V_94:
return V_41 ;
V_30:
F_37 ( L_6 , __FILE__ , __LINE__ ) ;
V_41 = V_206 ;
goto V_94;
}
static T_1 F_81 ( struct V_6 * V_7 , struct V_382 * V_383 )
{
V_29 ;
F_16 ( 8 ) ;
F_29 ( & V_383 -> V_292 , 8 ) ;
V_31 ;
}
static T_1 F_82 ( struct V_6 * V_7 , struct V_384 * V_385 )
{
V_29 ;
F_16 ( 4 ) ;
F_17 ( V_385 -> V_386 ) ;
V_31 ;
}
static T_1
F_83 ( struct V_6 * V_7 , void * V_8 )
{
return V_57 ;
}
static T_1
F_84 ( struct V_6 * V_7 , void * V_8 )
{
return V_257 ;
}
static inline bool
F_85 ( struct V_6 * V_7 , struct V_387 * V_388 )
{
if ( V_388 -> V_389 < V_390 )
return false ;
else if ( V_7 -> V_207 == 0 && V_388 -> V_389 > V_391 )
return false ;
else if ( V_7 -> V_207 == 1 && V_388 -> V_389 > V_392 )
return false ;
else if ( V_7 -> V_207 == 2 && V_388 -> V_389 > V_393 )
return false ;
return true ;
}
static int F_86 ( T_2 V_389 )
{
switch ( V_389 ) {
case V_394 :
case V_395 :
return 2 * V_11 ;
case V_396 :
return V_397 ;
default:
return V_11 ;
}
}
static T_1
F_87 ( struct V_6 * V_7 )
{
V_29 ;
struct V_387 * V_388 ;
bool V_373 = false ;
int V_398 = V_11 ;
int V_3 ;
F_16 ( 4 ) ;
F_17 ( V_7 -> V_399 ) ;
F_16 ( V_7 -> V_399 + 8 ) ;
F_32 ( V_7 -> V_400 , V_7 -> V_399 ) ;
F_17 ( V_7 -> V_207 ) ;
F_17 ( V_7 -> V_401 ) ;
if ( V_7 -> V_399 > V_402 )
goto V_30;
if ( V_7 -> V_401 > 100 )
goto V_30;
if ( V_7 -> V_401 > F_88 ( V_7 -> V_403 ) ) {
V_7 -> V_404 = F_7 ( V_7 -> V_401 * sizeof( * V_7 -> V_404 ) , V_17 ) ;
if ( ! V_7 -> V_404 ) {
V_7 -> V_404 = V_7 -> V_403 ;
F_37 ( L_9 ) ;
goto V_30;
}
}
if ( V_7 -> V_207 > V_405 )
V_7 -> V_401 = 0 ;
for ( V_3 = 0 ; V_3 < V_7 -> V_401 ; V_3 ++ ) {
V_388 = & V_7 -> V_404 [ V_3 ] ;
V_388 -> V_406 = NULL ;
F_16 ( 4 ) ;
F_17 ( V_388 -> V_389 ) ;
if ( F_85 ( V_7 , V_388 ) )
V_388 -> V_41 = V_407 [ V_388 -> V_389 ] ( V_7 , & V_388 -> V_408 ) ;
else {
V_388 -> V_389 = V_409 ;
V_388 -> V_41 = V_410 ;
}
if ( V_388 -> V_41 ) {
V_7 -> V_401 = V_3 + 1 ;
break;
}
V_373 |= F_89 ( V_388 ) ;
V_398 = F_90 ( V_398 , F_86 ( V_388 -> V_389 ) ) ;
}
if ( V_7 -> V_207 )
V_373 = false ;
if ( V_398 != V_397 )
F_91 ( V_7 -> V_60 , V_398 ) ;
V_7 -> V_60 -> V_411 = V_373 ? V_412 : V_413 ;
V_31 ;
}
static void F_92 ( T_1 * * V_8 , T_2 V_414 )
{
* ( * V_8 ) ++ = F_93 ( V_414 ) ;
}
static void F_94 ( T_1 * * V_8 , T_7 V_414 )
{
F_92 ( V_8 , ( V_414 >> 32 ) ) ;
F_92 ( V_8 , ( T_2 ) V_414 ) ;
}
static void F_95 ( T_1 * * V_8 , struct V_415 * V_416 , struct V_417 * V_417 )
{
if ( F_96 ( V_417 ) ) {
F_94 ( V_8 , V_417 -> V_418 ) ;
} else {
F_92 ( V_8 , V_416 -> ctime . V_77 ) ;
F_92 ( V_8 , V_416 -> ctime . V_78 ) ;
}
}
static void F_97 ( T_1 * * V_8 , struct V_419 * V_420 )
{
F_92 ( V_8 , V_420 -> V_421 ) ;
if ( V_420 -> V_422 ) {
F_94 ( V_8 , V_420 -> V_423 ) ;
F_94 ( V_8 , V_420 -> V_424 ) ;
} else {
F_92 ( V_8 , V_420 -> V_425 ) ;
F_92 ( V_8 , V_420 -> V_426 ) ;
F_92 ( V_8 , V_420 -> V_427 ) ;
F_92 ( V_8 , V_420 -> V_428 ) ;
}
}
static T_1 F_98 ( char V_429 , char * V_430 ,
T_1 * * V_431 , int * V_432 ,
char V_433 , char V_434 )
{
T_1 * V_8 = * V_431 ;
T_1 * V_435 = V_8 ;
int strlen , V_436 = 0 ;
char * V_1 , * V_12 , * V_25 ;
F_37 ( L_10 , V_430 ) ;
if ( ( * V_432 -= 4 ) < 0 )
return V_50 ;
F_99 ( 0 ) ;
V_12 = V_1 = V_430 ;
while ( * V_12 ) {
bool V_437 = false ;
if ( * V_1 == V_433 ) {
for (; * V_12 && ( * V_12 != V_434 ) ; V_12 ++ )
;
V_25 = V_12 + 1 ;
if ( * V_12 && ( ! * V_25 || * V_25 == V_429 ) ) {
V_1 ++ ;
V_437 = true ;
}
}
if ( ! V_437 )
for (; * V_12 && ( * V_12 != V_429 ) ; V_12 ++ )
;
strlen = V_12 - V_1 ;
if ( strlen ) {
if ( ( * V_432 -= ( ( F_8 ( strlen ) << 2 ) + 4 ) ) < 0 )
return V_50 ;
F_99 ( strlen ) ;
F_100 ( V_1 , strlen ) ;
V_436 ++ ;
}
else
V_12 ++ ;
V_1 = V_12 ;
}
* V_431 = V_8 ;
V_8 = V_435 ;
F_99 ( V_436 ) ;
return 0 ;
}
static T_1 F_101 ( char V_429 , char * V_430 ,
T_1 * * V_431 , int * V_432 )
{
return F_98 ( V_429 , V_430 , V_431 , V_432 , 0 , 0 ) ;
}
static T_1 F_102 ( struct V_438 * V_439 ,
T_1 * * V_431 , int * V_432 )
{
T_1 V_41 ;
T_1 * V_8 = * V_431 ;
V_41 = F_98 ( ':' , V_439 -> V_440 , & V_8 , V_432 ,
'[' , ']' ) ;
if ( V_41 )
return V_41 ;
V_41 = F_101 ( '/' , V_439 -> V_441 , & V_8 , V_432 ) ;
if ( V_41 )
return V_41 ;
* V_431 = V_8 ;
return 0 ;
}
static T_1 F_103 ( const struct V_441 * V_442 ,
const struct V_441 * V_441 , T_1 * * V_431 , int * V_432 )
{
struct V_441 V_443 = * V_441 ;
T_1 * V_8 = * V_431 ;
struct V_444 * * V_430 = NULL ;
unsigned int V_445 = 0 ;
T_1 V_446 = V_90 ;
F_37 ( L_11 ) ;
F_104 ( & V_443 ) ;
for (; ; ) {
if ( V_443 . V_444 == V_442 -> V_444 && V_443 . V_447 == V_442 -> V_447 )
break;
if ( V_443 . V_444 == V_443 . V_447 -> V_448 ) {
if ( F_105 ( & V_443 ) )
continue;
goto V_449;
}
if ( ( V_445 & 15 ) == 0 ) {
struct V_444 * * V_450 ;
V_450 = F_106 ( V_430 ,
sizeof( * V_450 ) * ( V_445 + 16 ) ,
V_17 ) ;
if ( ! V_450 )
goto V_449;
V_430 = V_450 ;
}
V_430 [ V_445 ++ ] = V_443 . V_444 ;
V_443 . V_444 = F_107 ( V_443 . V_444 ) ;
}
* V_432 -= 4 ;
if ( * V_432 < 0 )
goto V_449;
F_99 ( V_445 ) ;
while ( V_445 ) {
struct V_444 * V_444 = V_430 [ V_445 - 1 ] ;
unsigned int V_2 ;
F_108 ( & V_444 -> V_451 ) ;
V_2 = V_444 -> V_452 . V_2 ;
* V_432 -= 4 + ( F_8 ( V_2 ) << 2 ) ;
if ( * V_432 < 0 ) {
F_109 ( & V_444 -> V_451 ) ;
goto V_449;
}
F_99 ( V_2 ) ;
F_100 ( V_444 -> V_452 . V_453 , V_2 ) ;
F_37 ( L_12 , V_444 -> V_452 . V_453 ) ;
F_109 ( & V_444 -> V_451 ) ;
F_110 ( V_444 ) ;
V_445 -- ;
}
* V_431 = V_8 ;
V_446 = 0 ;
V_449:
F_37 ( L_13 ) ;
while ( V_445 )
F_110 ( V_430 [ -- V_445 ] ) ;
F_6 ( V_430 ) ;
F_111 ( & V_443 ) ;
return V_446 ;
}
static T_1 F_112 ( struct V_454 * V_60 ,
const struct V_441 * V_441 , T_1 * * V_431 , int * V_432 )
{
struct V_455 * V_456 ;
T_1 V_457 ;
V_456 = F_113 ( V_60 ) ;
if ( F_114 ( V_456 ) )
return F_27 ( F_115 ( V_456 ) ) ;
V_457 = F_103 ( & V_456 -> V_458 , V_441 , V_431 , V_432 ) ;
F_116 ( V_456 ) ;
return V_457 ;
}
static T_1 F_117 ( struct V_454 * V_60 ,
struct V_455 * exp ,
T_1 * * V_431 , int * V_432 )
{
T_1 V_41 ;
int V_3 ;
T_1 * V_8 = * V_431 ;
struct V_459 * V_460 = & exp -> V_461 ;
V_41 = F_112 ( V_60 , & exp -> V_458 , & V_8 , V_432 ) ;
if ( V_41 )
return V_41 ;
if ( ( * V_432 -= 4 ) < 0 )
return V_50 ;
F_99 ( V_460 -> V_462 ) ;
for ( V_3 = 0 ; V_3 < V_460 -> V_462 ; V_3 ++ ) {
V_41 = F_102 ( & V_460 -> V_463 [ V_3 ] ,
& V_8 , V_432 ) ;
if ( V_41 )
return V_41 ;
}
* V_431 = V_8 ;
return 0 ;
}
static T_2 F_118 ( T_8 V_464 )
{
switch ( V_464 & V_65 ) {
case V_465 : return V_144 ;
case V_466 : return V_140 ;
case V_467 : return V_145 ;
case V_468 : return V_139 ;
case V_469 : return V_136 ;
case V_470 : return V_471 ;
case V_472 : return V_143 ;
default: return V_473 ;
} ;
}
static T_1
F_119 ( struct V_454 * V_60 , int V_56 , T_5 V_105 , T_6 V_106 ,
T_1 * * V_8 , int * V_432 )
{
int V_41 ;
if ( * V_432 < ( F_8 ( V_474 ) << 2 ) + 4 )
return V_50 ;
if ( V_56 != V_58 )
V_41 = F_120 ( V_56 , ( V_475 * ) ( * V_8 + 1 ) ) ;
else if ( F_36 ( V_106 ) )
V_41 = F_121 ( V_60 , V_106 , ( V_475 * ) ( * V_8 + 1 ) ) ;
else
V_41 = F_122 ( V_60 , V_105 , ( V_475 * ) ( * V_8 + 1 ) ) ;
if ( V_41 < 0 )
return F_27 ( V_41 ) ;
* V_8 = F_123 ( * V_8 , NULL , V_41 ) ;
* V_432 -= ( F_8 ( V_41 ) << 2 ) + 4 ;
F_14 ( * V_432 < 0 ) ;
return 0 ;
}
static inline T_1
F_124 ( struct V_454 * V_60 , T_5 V_476 , T_1 * * V_8 , int * V_432 )
{
return F_119 ( V_60 , V_58 , V_476 , V_477 ,
V_8 , V_432 ) ;
}
static inline T_1
F_125 ( struct V_454 * V_60 , T_6 V_478 , T_1 * * V_8 , int * V_432 )
{
return F_119 ( V_60 , V_58 , V_479 , V_478 ,
V_8 , V_432 ) ;
}
static inline T_1
F_126 ( struct V_454 * V_60 , struct V_47 * V_48 ,
T_1 * * V_8 , int * V_432 )
{
T_5 V_105 = V_479 ;
T_6 V_106 = V_477 ;
if ( V_48 -> V_56 == V_58 ) {
if ( V_48 -> V_54 & V_59 )
V_106 = V_48 -> V_61 ;
else
V_105 = V_48 -> V_62 ;
}
return F_119 ( V_60 , V_48 -> V_56 , V_105 , V_106 , V_8 , V_432 ) ;
}
static inline T_1
F_127 ( struct V_454 * V_60 , void * V_480 , int V_2 , T_1 * * V_431 , int * V_432 )
{
T_1 * V_8 = * V_431 ;
if ( * V_432 < ( ( F_8 ( V_2 ) << 2 ) + 4 + 4 + 4 ) )
return V_50 ;
if ( ( * V_432 -= 8 ) < 0 )
return V_50 ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
V_8 = F_123 ( V_8 , V_480 , V_2 ) ;
* V_432 -= ( F_8 ( V_2 ) << 2 ) + 4 ;
* V_431 = V_8 ;
return 0 ;
}
static inline T_1
F_127 ( struct V_454 * V_60 , void * V_480 , int V_2 , T_1 * * V_431 , int * V_432 )
{ return 0 ; }
static T_1 F_128 ( T_2 * V_481 , T_2 * V_482 , T_2 * V_483 )
{
if ( * V_481 & ~ V_484 ||
* V_482 & ~ V_485 ) {
if ( * V_481 & V_486 ||
* V_481 & V_487 )
* V_483 = V_488 ;
else
return V_489 ;
}
* V_481 &= V_484 ;
* V_482 &= V_485 ;
return 0 ;
}
static int F_129 ( struct V_455 * exp , struct V_415 * V_416 )
{
struct V_441 V_441 = exp -> V_458 ;
int V_446 ;
F_104 ( & V_441 ) ;
while ( F_105 ( & V_441 ) ) {
if ( V_441 . V_444 != V_441 . V_447 -> V_448 )
break;
}
V_446 = F_130 ( & V_441 , V_416 ) ;
F_111 ( & V_441 ) ;
return V_446 ;
}
T_1
F_131 ( struct V_490 * V_491 , struct V_455 * exp ,
struct V_444 * V_444 , T_1 * * V_492 , int V_436 , T_2 * V_27 ,
struct V_454 * V_60 , int V_493 )
{
T_2 V_481 = V_27 [ 0 ] ;
T_2 V_482 = V_27 [ 1 ] ;
T_2 V_494 = V_27 [ 2 ] ;
struct V_415 V_416 ;
struct V_490 V_495 ;
struct V_496 V_497 ;
int V_432 = V_436 << 2 ;
T_1 * V_498 ;
T_2 V_104 ;
T_7 V_499 ;
T_2 V_483 = 0 ;
T_1 * V_8 = * V_492 ;
T_1 V_41 ;
int V_446 ;
int V_500 = 0 ;
struct V_33 * V_34 = NULL ;
void * V_480 = NULL ;
int V_501 ;
bool V_502 = false ;
struct V_503 * V_504 = V_60 -> V_505 ;
T_2 V_207 = V_504 -> V_506 . V_207 ;
struct V_441 V_441 = {
. V_447 = exp -> V_458 . V_447 ,
. V_444 = V_444 ,
} ;
struct V_507 * V_508 = F_132 ( F_133 ( V_60 ) , V_509 ) ;
F_14 ( V_482 & V_510 ) ;
F_14 ( V_481 & ~ F_134 ( V_207 ) ) ;
F_14 ( V_482 & ~ F_135 ( V_207 ) ) ;
F_14 ( V_494 & ~ F_136 ( V_207 ) ) ;
if ( exp -> V_461 . V_511 ) {
F_14 ( V_27 [ 2 ] ) ;
V_41 = F_128 ( & V_481 , & V_482 , & V_483 ) ;
if ( V_41 )
goto V_94;
}
V_446 = F_130 ( & V_441 , & V_416 ) ;
if ( V_446 )
goto V_51;
if ( ( V_481 & ( V_512 | V_513 |
V_514 ) ) ||
( V_482 & ( V_515 | V_516 |
V_517 ) ) ) {
V_446 = F_137 ( & V_441 , & V_497 ) ;
if ( V_446 )
goto V_51;
}
if ( ( V_481 & ( V_518 | V_519 ) ) && ! V_491 ) {
F_138 ( & V_495 , V_270 ) ;
V_41 = F_139 ( & V_495 , exp , V_444 , NULL ) ;
if ( V_41 )
goto V_94;
V_491 = & V_495 ;
}
if ( V_481 & ( V_45 | V_520
| V_521 ) ) {
V_446 = F_140 ( V_60 , V_444 , & V_34 ) ;
V_500 = ( V_446 == 0 ) ;
if ( V_481 & V_45 ) {
if ( V_446 == - V_522 )
V_481 &= ~ V_45 ;
else if ( V_446 == - V_523 ) {
V_41 = V_524 ;
goto V_94;
} else if ( V_446 != 0 )
goto V_51;
}
}
#ifdef F_25
if ( ( V_27 [ 2 ] & V_86 ) ||
V_27 [ 0 ] & V_521 ) {
V_446 = F_141 ( V_444 -> V_525 ,
& V_480 , & V_501 ) ;
V_502 = ( V_446 == 0 ) ;
if ( V_494 & V_86 ) {
if ( V_446 == - V_522 )
V_494 &= ~ V_86 ;
else if ( V_446 )
goto V_51;
}
}
#endif
if ( V_494 ) {
if ( ( V_432 -= 16 ) < 0 )
goto V_526;
F_99 ( 3 ) ;
F_99 ( V_481 ) ;
F_99 ( V_482 ) ;
F_99 ( V_494 ) ;
} else if ( V_482 ) {
if ( ( V_432 -= 12 ) < 0 )
goto V_526;
F_99 ( 2 ) ;
F_99 ( V_481 ) ;
F_99 ( V_482 ) ;
} else {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
F_99 ( V_481 ) ;
}
V_498 = V_8 ++ ;
if ( V_481 & V_521 ) {
T_2 V_527 = F_134 ( V_207 ) ;
T_2 V_528 = F_135 ( V_207 ) ;
T_2 V_529 = F_136 ( V_207 ) ;
if ( ! V_500 )
V_527 &= ~ V_45 ;
if ( ! V_502 )
V_529 &= ~ V_86 ;
if ( ! V_529 ) {
if ( ( V_432 -= 12 ) < 0 )
goto V_526;
F_99 ( 2 ) ;
F_99 ( V_527 ) ;
F_99 ( V_528 ) ;
} else {
if ( ( V_432 -= 16 ) < 0 )
goto V_526;
F_99 ( 3 ) ;
F_99 ( V_527 ) ;
F_99 ( V_528 ) ;
F_99 ( V_529 ) ;
}
}
if ( V_481 & V_530 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
V_104 = F_118 ( V_416 . V_464 ) ;
if ( V_104 == V_473 )
goto V_531;
F_99 ( V_104 ) ;
}
if ( V_481 & V_532 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
if ( exp -> V_533 & V_534 )
F_99 ( V_535 ) ;
else
F_99 ( V_535 | V_536 ) ;
}
if ( V_481 & V_537 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_95 ( & V_8 , & V_416 , V_444 -> V_525 ) ;
}
if ( V_481 & V_42 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( V_416 . V_538 ) ;
}
if ( V_481 & V_539 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
}
if ( V_481 & V_540 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
}
if ( V_481 & V_541 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 0 ) ;
}
if ( V_481 & V_519 ) {
if ( ( V_432 -= 16 ) < 0 )
goto V_526;
if ( exp -> V_461 . V_511 ) {
F_142 ( V_542 ) ;
F_142 ( V_543 ) ;
} else switch( F_143 ( V_491 ) ) {
case V_544 :
F_142 ( ( T_7 ) exp -> V_545 ) ;
F_142 ( ( T_7 ) 0 ) ;
break;
case V_546 :
F_99 ( 0 ) ;
F_99 ( F_144 ( V_416 . V_547 ) ) ;
F_99 ( 0 ) ;
F_99 ( F_145 ( V_416 . V_547 ) ) ;
break;
case V_548 :
F_100 ( exp -> V_549 , 16 ) ;
break;
}
}
if ( V_481 & V_550 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 0 ) ;
}
if ( V_481 & V_551 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( V_508 -> V_552 ) ;
}
if ( V_481 & V_486 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( V_483 ) ;
}
if ( V_481 & V_45 ) {
struct V_47 * V_48 ;
if ( V_34 == NULL ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 0 ) ;
goto V_553;
}
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( V_34 -> V_52 ) ;
for ( V_48 = V_34 -> V_53 ; V_48 < V_34 -> V_53 + V_34 -> V_52 ; V_48 ++ ) {
if ( ( V_432 -= 4 * 3 ) < 0 )
goto V_526;
F_99 ( V_48 -> type ) ;
F_99 ( V_48 -> V_54 ) ;
F_99 ( V_48 -> V_55 & V_554 ) ;
V_41 = F_126 ( V_60 , V_48 , & V_8 , & V_432 ) ;
if ( V_41 == V_50 )
goto V_526;
if ( V_41 )
goto V_94;
}
}
V_553:
if ( V_481 & V_520 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( V_500 ?
V_555 | V_556 : 0 ) ;
}
if ( V_481 & V_557 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
}
if ( V_481 & V_558 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 0 ) ;
}
if ( V_481 & V_559 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
}
if ( V_481 & V_560 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
}
if ( V_481 & V_518 ) {
V_432 -= ( F_8 ( V_491 -> V_561 . V_562 ) << 2 ) + 4 ;
if ( V_432 < 0 )
goto V_526;
F_99 ( V_491 -> V_561 . V_562 ) ;
F_100 ( & V_491 -> V_561 . V_563 , V_491 -> V_561 . V_562 ) ;
}
if ( V_481 & V_564 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( V_416 . V_565 ) ;
}
if ( V_481 & V_566 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( ( T_7 ) V_497 . V_567 ) ;
}
if ( V_481 & V_512 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( ( T_7 ) V_497 . V_567 ) ;
}
if ( V_481 & V_513 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( ( T_7 ) V_497 . V_568 ) ;
}
if ( V_481 & V_487 ) {
V_41 = F_117 ( V_60 , exp , & V_8 , & V_432 ) ;
if ( V_41 == V_50 )
goto V_526;
if ( V_41 )
goto V_94;
}
if ( V_481 & V_569 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
}
if ( V_481 & V_570 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( exp -> V_458 . V_447 -> V_571 -> V_572 ) ;
}
if ( V_481 & V_573 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 255 ) ;
}
if ( V_481 & V_514 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( V_497 . V_574 ) ;
}
if ( V_481 & V_575 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( ( T_7 ) F_146 ( V_60 ) ) ;
}
if ( V_481 & V_576 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_142 ( ( T_7 ) F_146 ( V_60 ) ) ;
}
if ( V_482 & V_63 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( V_416 . V_464 & V_66 ) ;
}
if ( V_482 & V_577 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( 1 ) ;
}
if ( V_482 & V_578 ) {
if ( ( V_432 -= 4 ) < 0 )
goto V_526;
F_99 ( V_416 . V_579 ) ;
}
if ( V_482 & V_68 ) {
V_41 = F_124 ( V_60 , V_416 . V_105 , & V_8 , & V_432 ) ;
if ( V_41 == V_50 )
goto V_526;
if ( V_41 )
goto V_94;
}
if ( V_482 & V_71 ) {
V_41 = F_125 ( V_60 , V_416 . V_106 , & V_8 , & V_432 ) ;
if ( V_41 == V_50 )
goto V_526;
if ( V_41 )
goto V_94;
}
if ( V_482 & V_580 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
F_99 ( ( T_2 ) F_144 ( V_416 . V_581 ) ) ;
F_99 ( ( T_2 ) F_145 ( V_416 . V_581 ) ) ;
}
if ( V_482 & V_515 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
V_499 = ( T_7 ) V_497 . V_582 * ( T_7 ) V_497 . V_583 ;
F_142 ( V_499 ) ;
}
if ( V_482 & V_516 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
V_499 = ( T_7 ) V_497 . V_584 * ( T_7 ) V_497 . V_583 ;
F_142 ( V_499 ) ;
}
if ( V_482 & V_517 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
V_499 = ( T_7 ) V_497 . V_585 * ( T_7 ) V_497 . V_583 ;
F_142 ( V_499 ) ;
}
if ( V_482 & V_586 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
V_499 = ( T_7 ) V_416 . V_587 << 9 ;
F_142 ( V_499 ) ;
}
if ( V_482 & V_588 ) {
if ( ( V_432 -= 12 ) < 0 )
goto V_526;
F_142 ( ( V_589 ) V_416 . V_590 . V_77 ) ;
F_99 ( V_416 . V_590 . V_78 ) ;
}
if ( V_482 & V_591 ) {
if ( ( V_432 -= 12 ) < 0 )
goto V_526;
F_99 ( 0 ) ;
F_99 ( 1 ) ;
F_99 ( 0 ) ;
}
if ( V_482 & V_592 ) {
if ( ( V_432 -= 12 ) < 0 )
goto V_526;
F_142 ( ( V_589 ) V_416 . ctime . V_77 ) ;
F_99 ( V_416 . ctime . V_78 ) ;
}
if ( V_482 & V_593 ) {
if ( ( V_432 -= 12 ) < 0 )
goto V_526;
F_142 ( ( V_589 ) V_416 . V_594 . V_77 ) ;
F_99 ( V_416 . V_594 . V_78 ) ;
}
if ( V_482 & V_595 ) {
if ( ( V_432 -= 8 ) < 0 )
goto V_526;
if ( V_493 == 0 &&
V_444 == exp -> V_458 . V_447 -> V_448 )
F_129 ( exp , & V_416 ) ;
F_142 ( V_416 . V_565 ) ;
}
if ( V_494 & V_86 ) {
V_41 = F_127 ( V_60 , V_480 ,
V_501 , & V_8 , & V_432 ) ;
if ( V_41 )
goto V_94;
}
if ( V_494 & V_596 ) {
F_99 ( 3 ) ;
F_99 ( V_597 ) ;
F_99 ( V_598 ) ;
F_99 ( V_599 ) ;
}
* V_498 = F_93 ( ( char * ) V_8 - ( char * ) V_498 - 4 ) ;
* V_492 = V_8 ;
V_41 = V_57 ;
V_94:
#ifdef F_25
if ( V_480 )
F_147 ( V_480 , V_501 ) ;
#endif
F_6 ( V_34 ) ;
if ( V_491 == & V_495 )
F_148 ( & V_495 ) ;
return V_41 ;
V_51:
V_41 = F_27 ( V_446 ) ;
goto V_94;
V_526:
V_41 = V_50 ;
goto V_94;
V_531:
V_41 = V_600 ;
goto V_94;
}
static inline int F_149 ( T_2 * V_27 )
{
if ( V_27 [ 0 ] & ~ ( V_486 | V_551 ) )
return 1 ;
if ( V_27 [ 1 ] & ~ V_595 )
return 1 ;
return 0 ;
}
static T_1
F_150 ( struct V_277 * V_601 ,
const char * V_453 , int V_602 , T_1 * * V_8 , int V_432 )
{
struct V_455 * exp = V_601 -> V_603 -> V_604 ;
struct V_444 * V_444 ;
T_1 V_605 ;
int V_493 = 0 ;
V_444 = F_151 ( V_453 , V_601 -> V_603 -> V_606 , V_602 ) ;
if ( F_114 ( V_444 ) )
return F_27 ( F_115 ( V_444 ) ) ;
if ( ! V_444 -> V_525 ) {
F_110 ( V_444 ) ;
return V_607 ;
}
F_152 ( exp ) ;
if ( F_153 ( V_444 , exp ) ) {
int V_446 ;
if ( ! ( exp -> V_533 & V_608 )
&& ! F_149 ( V_601 -> V_283 ) ) {
V_493 = 1 ;
goto V_609;
}
V_446 = F_154 ( V_601 -> V_610 , & V_444 , & exp ) ;
if ( V_446 ) {
V_605 = F_27 ( V_446 ) ;
goto V_611;
}
V_605 = F_155 ( exp , V_601 -> V_610 ) ;
if ( V_605 )
goto V_611;
}
V_609:
V_605 = F_131 ( NULL , exp , V_444 , V_8 , V_432 , V_601 -> V_283 ,
V_601 -> V_610 , V_493 ) ;
V_611:
F_110 ( V_444 ) ;
F_116 ( exp ) ;
return V_605 ;
}
static T_1 *
F_156 ( T_1 * V_8 , int V_432 , T_1 V_605 )
{
T_1 * V_498 ;
if ( V_432 < 6 )
return NULL ;
* V_8 ++ = F_93 ( 2 ) ;
* V_8 ++ = F_93 ( V_486 ) ;
* V_8 ++ = F_93 ( 0 ) ;
V_498 = V_8 ++ ;
* V_8 ++ = V_605 ;
* V_498 = F_93 ( ( char * ) V_8 - ( char * ) V_498 - 4 ) ;
return V_8 ;
}
static int
F_157 ( void * V_612 , const char * V_453 , int V_602 ,
T_9 V_613 , T_7 V_565 , unsigned int V_614 )
{
struct V_615 * V_616 = V_612 ;
struct V_277 * V_601 = F_158 ( V_616 , struct V_277 , V_617 ) ;
int V_432 ;
T_1 * V_8 = V_601 -> V_492 ;
T_1 * V_618 ;
T_1 V_605 = V_619 ;
if ( V_453 && F_2 ( V_453 , V_602 ) ) {
V_601 -> V_617 . V_446 = V_57 ;
return 0 ;
}
if ( V_601 -> V_613 )
F_159 ( V_601 -> V_613 , ( T_7 ) V_613 ) ;
V_432 = V_601 -> V_432 - 4 - F_8 ( V_602 ) ;
if ( V_432 < 0 )
goto V_620;
* V_8 ++ = V_621 ;
V_618 = V_8 ;
V_8 = F_159 ( V_8 , V_622 ) ;
V_8 = F_160 ( V_8 , V_453 , V_602 ) ;
V_605 = F_150 ( V_601 , V_453 , V_602 , & V_8 , V_432 ) ;
switch ( V_605 ) {
case V_57 :
break;
case V_50 :
V_605 = V_619 ;
goto V_620;
case V_607 :
goto V_623;
default:
if ( ! ( V_601 -> V_283 [ 0 ] & V_486 ) )
goto V_620;
V_8 = F_156 ( V_8 , V_432 , V_605 ) ;
if ( V_8 == NULL ) {
V_605 = V_619 ;
goto V_620;
}
}
V_601 -> V_432 -= ( V_8 - V_601 -> V_492 ) ;
V_601 -> V_492 = V_8 ;
V_601 -> V_613 = V_618 ;
V_623:
V_601 -> V_617 . V_446 = V_57 ;
return 0 ;
V_620:
V_601 -> V_617 . V_446 = V_605 ;
return - V_523 ;
}
static void
F_161 ( struct V_503 * V_504 , T_4 * V_95 )
{
T_1 * V_8 ;
F_162 ( sizeof( T_4 ) ) ;
F_99 ( V_95 -> V_96 ) ;
F_100 ( & V_95 -> V_97 , sizeof( V_98 ) ) ;
F_163 () ;
}
static T_1
F_164 ( struct V_503 * V_504 , T_1 V_605 , struct V_99 * V_100 )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( 8 ) ;
F_99 ( V_100 -> V_624 ) ;
F_99 ( V_100 -> V_625 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1 F_165 ( struct V_503 * V_504 , T_1 V_605 , struct V_120 * V_121 )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( V_122 + 8 ) ;
F_100 ( V_121 -> V_123 . V_89 , V_122 ) ;
F_99 ( V_121 -> V_124 ) ;
F_99 ( 0 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_166 ( struct V_503 * V_504 , T_1 V_605 , struct V_125 * V_126 )
{
if ( ! V_605 )
F_161 ( V_504 , & V_126 -> V_128 ) ;
return V_605 ;
}
static T_1
F_167 ( struct V_503 * V_504 , T_1 V_605 , struct V_129 * V_130 )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( V_241 ) ;
F_100 ( V_130 -> V_626 . V_89 , V_241 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_168 ( struct V_503 * V_504 , T_1 V_605 , struct V_133 * V_134 )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( 32 ) ;
F_97 ( & V_8 , & V_134 -> V_627 ) ;
F_99 ( 2 ) ;
F_99 ( V_134 -> V_148 [ 0 ] ) ;
F_99 ( V_134 -> V_148 [ 1 ] ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_169 ( struct V_503 * V_504 , T_1 V_605 , struct V_155 * V_156 )
{
struct V_490 * V_491 = V_156 -> V_628 ;
int V_432 ;
if ( V_605 )
return V_605 ;
V_432 = V_504 -> V_12 - V_504 -> V_8 - ( V_629 >> 2 ) ;
V_605 = F_131 ( V_491 , V_491 -> V_604 , V_491 -> V_606 ,
& V_504 -> V_8 , V_432 , V_156 -> V_157 ,
V_504 -> V_60 , 0 ) ;
return V_605 ;
}
static T_1
F_170 ( struct V_503 * V_504 , T_1 V_605 , struct V_490 * * V_630 )
{
struct V_490 * V_491 = * V_630 ;
unsigned int V_2 ;
T_1 * V_8 ;
if ( ! V_605 ) {
V_2 = V_491 -> V_561 . V_562 ;
F_162 ( V_2 + 4 ) ;
F_99 ( V_2 ) ;
F_100 ( & V_491 -> V_561 . V_563 , V_2 ) ;
F_163 () ;
}
return V_605 ;
}
static void
F_171 ( struct V_503 * V_504 , struct V_631 * V_632 )
{
struct V_35 * V_633 = & V_632 -> V_634 ;
T_1 * V_8 ;
F_162 ( 32 + F_172 ( V_633 -> V_2 ) ) ;
F_142 ( V_632 -> V_635 ) ;
F_142 ( V_632 -> V_636 ) ;
F_99 ( V_632 -> V_637 ) ;
if ( V_633 -> V_2 ) {
F_100 ( & V_632 -> V_638 , 8 ) ;
F_99 ( V_633 -> V_2 ) ;
F_100 ( V_633 -> V_89 , V_633 -> V_2 ) ;
F_6 ( V_633 -> V_89 ) ;
} else {
F_142 ( ( T_7 ) 0 ) ;
F_99 ( 0 ) ;
}
F_163 () ;
}
static T_1
F_173 ( struct V_503 * V_504 , T_1 V_605 , struct V_162 * V_163 )
{
if ( ! V_605 )
F_161 ( V_504 , & V_163 -> V_639 ) ;
else if ( V_605 == V_640 )
F_171 ( V_504 , & V_163 -> V_641 ) ;
return V_605 ;
}
static T_1
F_174 ( struct V_503 * V_504 , T_1 V_605 , struct V_178 * V_179 )
{
if ( V_605 == V_640 )
F_171 ( V_504 , & V_179 -> V_642 ) ;
return V_605 ;
}
static T_1
F_175 ( struct V_503 * V_504 , T_1 V_605 , struct V_185 * V_186 )
{
if ( ! V_605 )
F_161 ( V_504 , & V_186 -> V_189 ) ;
return V_605 ;
}
static T_1
F_176 ( struct V_503 * V_504 , T_1 V_605 , struct V_158 * V_159 )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( 20 ) ;
F_97 ( & V_8 , & V_159 -> V_643 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_177 ( struct V_503 * V_504 , T_1 V_605 , struct V_220 * V_221 )
{
T_1 * V_8 ;
if ( V_605 )
goto V_94;
F_161 ( V_504 , & V_221 -> V_644 ) ;
F_162 ( 40 ) ;
F_97 ( & V_8 , & V_221 -> V_645 ) ;
F_99 ( V_221 -> V_646 ) ;
F_99 ( 2 ) ;
F_99 ( V_221 -> V_222 [ 0 ] ) ;
F_99 ( V_221 -> V_222 [ 1 ] ) ;
F_99 ( V_221 -> V_249 ) ;
F_163 () ;
switch ( V_221 -> V_249 ) {
case V_647 :
break;
case V_648 :
F_161 ( V_504 , & V_221 -> V_251 ) ;
F_162 ( 20 ) ;
F_99 ( V_221 -> V_649 ) ;
F_99 ( V_650 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_163 () ;
break;
case V_651 :
F_161 ( V_504 , & V_221 -> V_251 ) ;
F_162 ( 32 ) ;
F_99 ( 0 ) ;
F_99 ( V_652 ) ;
F_99 ( ~ ( T_2 ) 0 ) ;
F_99 ( ~ ( T_2 ) 0 ) ;
F_99 ( V_650 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_163 () ;
break;
case V_653 :
switch ( V_221 -> V_654 ) {
case V_655 :
case V_656 :
F_162 ( 8 ) ;
F_99 ( V_221 -> V_654 ) ;
F_99 ( 0 ) ;
break;
default:
F_162 ( 4 ) ;
F_99 ( V_221 -> V_654 ) ;
}
F_163 () ;
break;
default:
F_178 () ;
}
V_94:
return V_605 ;
}
static T_1
F_179 ( struct V_503 * V_504 , T_1 V_605 , struct V_255 * V_657 )
{
if ( ! V_605 )
F_161 ( V_504 , & V_657 -> V_658 ) ;
return V_605 ;
}
static T_1
F_180 ( struct V_503 * V_504 , T_1 V_605 , struct V_260 * V_659 )
{
if ( ! V_605 )
F_161 ( V_504 , & V_659 -> V_262 ) ;
return V_605 ;
}
static T_1
F_181 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_272 * V_273 )
{
T_2 V_660 ;
int V_661 ;
struct V_662 * V_662 ;
unsigned long V_663 ;
long V_2 ;
T_1 * V_8 ;
if ( V_605 )
return V_605 ;
if ( V_504 -> V_664 -> V_665 )
return V_50 ;
F_162 ( 8 ) ;
V_663 = F_146 ( V_504 -> V_60 ) ;
if ( V_663 > V_273 -> V_276 )
V_663 = V_273 -> V_276 ;
V_2 = V_663 ;
V_661 = 0 ;
while ( V_2 > 0 ) {
V_662 = * ( V_504 -> V_60 -> V_666 ) ;
if ( ! V_662 ) {
V_663 -= V_2 ;
break;
}
V_504 -> V_60 -> V_667 [ V_661 ] . V_332 = F_4 ( V_662 ) ;
V_504 -> V_60 -> V_667 [ V_661 ] . V_333 =
V_2 < V_11 ? V_2 : V_11 ;
V_504 -> V_60 -> V_666 ++ ;
V_661 ++ ;
V_2 -= V_11 ;
}
V_273 -> V_668 = V_661 ;
V_605 = F_182 ( V_273 -> V_610 , V_273 -> V_603 , V_273 -> V_669 ,
V_273 -> V_275 , V_504 -> V_60 -> V_667 , V_273 -> V_668 ,
& V_663 ) ;
if ( V_605 )
return V_605 ;
V_660 = ( V_273 -> V_275 + V_663 >=
V_273 -> V_603 -> V_606 -> V_525 -> V_670 ) ;
F_99 ( V_660 ) ;
F_99 ( V_663 ) ;
F_163 () ;
V_504 -> V_664 -> V_671 [ 0 ] . V_333 = ( char * ) V_8
- ( char * ) V_504 -> V_664 -> V_671 [ 0 ] . V_332 ;
V_504 -> V_664 -> V_665 = V_663 ;
V_504 -> V_664 -> V_672 [ 0 ] . V_332 = V_8 ;
V_504 -> V_664 -> V_672 [ 0 ] . V_333 = 0 ;
if ( V_663 & 3 ) {
F_162 ( 4 ) ;
F_99 ( 0 ) ;
V_504 -> V_664 -> V_672 [ 0 ] . V_332 += V_663 & 3 ;
V_504 -> V_664 -> V_672 [ 0 ] . V_333 = 4 - ( V_663 & 3 ) ;
F_163 () ;
}
return 0 ;
}
static T_1
F_183 ( struct V_503 * V_504 , T_1 V_605 , struct V_673 * V_674 )
{
int V_663 ;
char * V_662 ;
T_1 * V_8 ;
if ( V_605 )
return V_605 ;
if ( V_504 -> V_664 -> V_665 )
return V_50 ;
if ( ! * V_504 -> V_60 -> V_666 )
return V_50 ;
V_662 = F_4 ( * ( V_504 -> V_60 -> V_666 ++ ) ) ;
V_663 = V_11 ;
F_162 ( 4 ) ;
V_605 = F_184 ( V_674 -> V_675 , V_674 -> V_676 , V_662 , & V_663 ) ;
if ( V_605 == V_677 )
return V_4 ;
if ( V_605 )
return V_605 ;
F_99 ( V_663 ) ;
F_163 () ;
V_504 -> V_664 -> V_671 [ 0 ] . V_333 = ( char * ) V_8
- ( char * ) V_504 -> V_664 -> V_671 [ 0 ] . V_332 ;
V_504 -> V_664 -> V_665 = V_663 ;
V_504 -> V_664 -> V_672 [ 0 ] . V_332 = V_8 ;
V_504 -> V_664 -> V_672 [ 0 ] . V_333 = 0 ;
if ( V_663 & 3 ) {
F_162 ( 4 ) ;
F_99 ( 0 ) ;
V_504 -> V_664 -> V_672 [ 0 ] . V_332 += V_663 & 3 ;
V_504 -> V_664 -> V_672 [ 0 ] . V_333 = 4 - ( V_663 & 3 ) ;
F_163 () ;
}
return 0 ;
}
static T_1
F_185 ( struct V_503 * V_504 , T_1 V_605 , struct V_277 * V_278 )
{
int V_663 ;
T_9 V_613 ;
T_1 * V_662 , * V_678 , * V_679 ;
T_1 * V_8 ;
if ( V_605 )
return V_605 ;
if ( V_504 -> V_664 -> V_665 )
return V_50 ;
if ( ! * V_504 -> V_60 -> V_666 )
return V_50 ;
F_162 ( V_241 ) ;
V_678 = V_8 ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_163 () ;
V_504 -> V_664 -> V_671 [ 0 ] . V_333 = ( ( char * ) V_504 -> V_8 ) - ( char * ) V_504 -> V_664 -> V_671 [ 0 ] . V_332 ;
V_679 = V_8 ;
V_663 = V_11 ;
if ( V_663 > V_278 -> V_282 )
V_663 = V_278 -> V_282 ;
V_663 = ( V_663 >> 2 ) - 4 ;
if ( V_663 < 0 ) {
V_605 = V_619 ;
goto V_680;
}
V_662 = F_4 ( * ( V_504 -> V_60 -> V_666 ++ ) ) ;
V_278 -> V_617 . V_446 = 0 ;
V_278 -> V_432 = V_663 ;
V_278 -> V_492 = V_662 ;
V_278 -> V_613 = NULL ;
V_613 = V_278 -> V_279 ;
V_605 = F_186 ( V_278 -> V_610 , V_278 -> V_603 ,
& V_613 ,
& V_278 -> V_617 , F_157 ) ;
if ( V_605 == V_57 &&
V_278 -> V_617 . V_446 == V_619 &&
V_278 -> V_492 == V_662 )
V_605 = V_619 ;
if ( V_605 )
goto V_680;
if ( V_278 -> V_613 )
F_159 ( V_278 -> V_613 , V_613 ) ;
V_8 = V_278 -> V_492 ;
* V_8 ++ = 0 ;
* V_8 ++ = F_93 ( V_278 -> V_617 . V_446 == V_681 ) ;
V_504 -> V_664 -> V_665 = ( ( char * ) V_8 ) -
( char * ) F_4 ( * ( V_504 -> V_60 -> V_666 - 1 ) ) ;
V_504 -> V_664 -> V_672 [ 0 ] . V_332 = V_679 ;
V_504 -> V_664 -> V_672 [ 0 ] . V_333 = 0 ;
V_504 -> V_8 = V_504 -> V_664 -> V_672 [ 0 ] . V_332 ;
V_504 -> V_12 = V_504 -> V_8 + ( V_11 - V_504 -> V_664 -> V_671 [ 0 ] . V_333 ) / 4 ;
return 0 ;
V_680:
V_8 = V_678 ;
F_163 () ;
return V_605 ;
}
static T_1
F_187 ( struct V_503 * V_504 , T_1 V_605 , struct V_284 * remove )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( 20 ) ;
F_97 ( & V_8 , & remove -> V_682 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_188 ( struct V_503 * V_504 , T_1 V_605 , struct V_287 * rename )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( 40 ) ;
F_97 ( & V_8 , & rename -> V_683 ) ;
F_97 ( & V_8 , & rename -> V_684 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_189 ( struct V_503 * V_504 ,
T_1 V_605 , struct V_455 * exp )
{
T_2 V_3 , V_685 , V_686 ;
struct V_687 * V_688 ;
struct V_687 V_689 [ 2 ] ;
T_1 * V_8 , * V_690 ;
static bool V_691 = true ;
if ( V_605 )
goto V_94;
if ( exp -> V_692 ) {
V_688 = exp -> V_693 ;
V_685 = exp -> V_692 ;
} else {
V_688 = V_689 ;
if ( exp -> V_694 -> V_695 -> V_695 == V_111 ) {
V_685 = 2 ;
V_688 [ 0 ] . V_696 = V_111 ;
V_688 [ 1 ] . V_696 = V_110 ;
} else if ( exp -> V_694 -> V_695 -> V_695 == V_115 ) {
V_685 = 1 ;
V_688 [ 0 ] . V_696
= F_190 ( exp -> V_694 ) ;
} else {
V_685 = 1 ;
V_688 [ 0 ] . V_696
= exp -> V_694 -> V_695 -> V_695 ;
}
}
V_686 = 0 ;
F_162 ( 4 ) ;
V_690 = V_8 ++ ;
F_163 () ;
for ( V_3 = 0 ; V_3 < V_685 ; V_3 ++ ) {
T_10 V_697 = V_688 [ V_3 ] . V_696 ;
struct V_698 V_699 ;
if ( F_191 ( V_697 , & V_699 ) == 0 ) {
V_686 ++ ;
F_162 ( 4 + 4 + V_699 . V_700 . V_2 + 4 + 4 ) ;
F_99 ( V_115 ) ;
F_99 ( V_699 . V_700 . V_2 ) ;
F_100 ( V_699 . V_700 . V_89 , V_699 . V_700 . V_2 ) ;
F_99 ( V_699 . V_701 ) ;
F_99 ( V_699 . V_702 ) ;
F_163 () ;
} else if ( V_697 < V_703 ) {
V_686 ++ ;
F_162 ( 4 ) ;
F_99 ( V_697 ) ;
F_163 () ;
} else {
if ( V_691 )
F_192 ( L_14
L_15 , V_697 ) ;
}
}
if ( V_685 != V_686 )
V_691 = false ;
* V_690 = F_93 ( V_686 ) ;
V_94:
if ( exp )
F_116 ( exp ) ;
return V_605 ;
}
static T_1
F_193 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_293 * V_294 )
{
return F_189 ( V_504 , V_605 , V_294 -> V_704 ) ;
}
static T_1
F_194 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_297 * V_294 )
{
return F_189 ( V_504 , V_605 , V_294 -> V_705 ) ;
}
static T_1
F_195 ( struct V_503 * V_504 , T_1 V_605 , struct V_299 * V_300 )
{
T_1 * V_8 ;
F_162 ( 16 ) ;
if ( V_605 ) {
F_99 ( 3 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
}
else {
F_99 ( 3 ) ;
F_99 ( V_300 -> V_302 [ 0 ] ) ;
F_99 ( V_300 -> V_302 [ 1 ] ) ;
F_99 ( V_300 -> V_302 [ 2 ] ) ;
}
F_163 () ;
return V_605 ;
}
static T_1
F_196 ( struct V_503 * V_504 , T_1 V_605 , struct V_306 * V_706 )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( 8 + V_241 ) ;
F_100 ( & V_706 -> V_707 , 8 ) ;
F_100 ( & V_706 -> V_708 , V_241 ) ;
F_163 () ;
}
else if ( V_605 == V_709 ) {
F_162 ( 8 ) ;
F_99 ( 0 ) ;
F_99 ( 0 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_197 ( struct V_503 * V_504 , T_1 V_605 , struct V_325 * V_326 )
{
T_1 * V_8 ;
if ( ! V_605 ) {
F_162 ( 16 ) ;
F_99 ( V_326 -> V_710 ) ;
F_99 ( V_326 -> V_711 ) ;
F_100 ( V_326 -> V_712 . V_89 , V_241 ) ;
F_163 () ;
}
return V_605 ;
}
static T_1
F_198 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_341 * V_342 )
{
T_1 * V_8 ;
char * V_713 ;
char * V_714 ;
int V_715 ;
int V_716 ;
T_11 V_717 = 0 ;
if ( V_605 )
return V_605 ;
V_713 = F_199 () -> V_718 ;
V_715 = strlen ( V_713 ) ;
V_714 = F_199 () -> V_718 ;
V_716 = strlen ( V_714 ) ;
F_162 (
8 +
4 +
4 +
4 +
8 +
8 +
4 +
( F_8 ( V_715 ) * 4 ) +
4 +
( F_8 ( V_716 ) * 4 ) +
4 ) ;
F_100 ( & V_342 -> V_292 , 8 ) ;
F_99 ( V_342 -> V_352 ) ;
F_99 ( V_342 -> V_345 ) ;
F_99 ( V_342 -> V_346 ) ;
switch ( V_342 -> V_346 ) {
case V_347 :
break;
case V_348 :
F_99 ( 2 ) ;
F_99 ( V_719 [ 0 ] ) ;
F_99 ( V_719 [ 1 ] ) ;
F_99 ( 0 ) ;
break;
default:
F_200 ( 1 ) ;
}
F_142 ( V_717 ) ;
F_99 ( V_715 ) ;
F_100 ( V_713 , V_715 ) ;
F_99 ( V_716 ) ;
F_100 ( V_714 , V_716 ) ;
F_99 ( 0 ) ;
F_163 () ;
return 0 ;
}
static T_1
F_201 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_350 * V_351 )
{
T_1 * V_8 ;
if ( V_605 )
return V_605 ;
F_162 ( 24 ) ;
F_100 ( V_351 -> V_123 . V_89 , V_122 ) ;
F_99 ( V_351 -> V_352 ) ;
F_99 ( V_351 -> V_345 ) ;
F_163 () ;
F_162 ( 28 ) ;
F_99 ( 0 ) ;
F_99 ( V_351 -> V_353 . V_354 ) ;
F_99 ( V_351 -> V_353 . V_355 ) ;
F_99 ( V_351 -> V_353 . V_356 ) ;
F_99 ( V_351 -> V_353 . V_357 ) ;
F_99 ( V_351 -> V_353 . V_358 ) ;
F_99 ( V_351 -> V_353 . V_359 ) ;
F_163 () ;
if ( V_351 -> V_353 . V_359 ) {
F_162 ( 4 ) ;
F_99 ( V_351 -> V_353 . V_360 ) ;
F_163 () ;
}
F_162 ( 28 ) ;
F_99 ( 0 ) ;
F_99 ( V_351 -> V_361 . V_354 ) ;
F_99 ( V_351 -> V_361 . V_355 ) ;
F_99 ( V_351 -> V_361 . V_356 ) ;
F_99 ( V_351 -> V_361 . V_357 ) ;
F_99 ( V_351 -> V_361 . V_358 ) ;
F_99 ( V_351 -> V_361 . V_359 ) ;
F_163 () ;
if ( V_351 -> V_361 . V_359 ) {
F_162 ( 4 ) ;
F_99 ( V_351 -> V_361 . V_360 ) ;
F_163 () ;
}
return 0 ;
}
static T_1
F_202 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_364 * V_365 )
{
return V_605 ;
}
static T_1
F_203 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_366 * V_367 )
{
T_1 * V_8 ;
if ( V_605 )
return V_605 ;
F_162 ( 4 ) ;
* V_8 ++ = V_605 ;
F_163 () ;
return V_605 ;
}
static T_1
F_204 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_369 * V_370 )
{
T_1 * V_8 ;
if ( V_605 )
return V_605 ;
F_162 ( V_122 + 20 ) ;
F_100 ( V_370 -> V_123 . V_89 , V_122 ) ;
F_99 ( V_370 -> V_352 ) ;
F_99 ( V_370 -> V_371 ) ;
F_99 ( V_370 -> V_372 - 1 ) ;
F_99 ( V_370 -> V_372 - 1 ) ;
F_99 ( V_370 -> V_720 ) ;
F_163 () ;
V_504 -> V_506 . V_721 = V_8 ;
return 0 ;
}
static T_1
F_205 ( struct V_503 * V_504 , T_1 V_605 ,
struct V_374 * V_375 )
{
struct V_376 * V_377 , * V_25 ;
T_1 * V_8 ;
F_162 ( 4 + ( 4 * V_375 -> V_378 ) ) ;
* V_8 ++ = F_93 ( V_375 -> V_378 ) ;
F_206 (stateid, next, &test_stateid->ts_stateid_list, ts_id_list) {
* V_8 ++ = V_377 -> V_722 ;
}
F_163 () ;
return V_605 ;
}
static T_1
F_207 ( struct V_503 * V_504 , T_1 V_605 , void * V_8 )
{
return V_605 ;
}
T_1 F_208 ( struct V_503 * V_504 , T_2 V_723 )
{
struct V_724 * V_725 = & V_504 -> V_60 -> V_726 ;
struct V_727 * V_728 = NULL ;
struct V_729 * V_730 = V_504 -> V_506 . V_730 ;
T_2 V_731 , V_732 = 0 ;
if ( ! F_209 ( & V_504 -> V_506 ) )
return 0 ;
V_728 = V_504 -> V_506 . V_728 ;
if ( V_728 == NULL )
return 0 ;
if ( V_725 -> V_665 == 0 ) {
V_731 = ( char * ) V_504 -> V_8 - ( char * ) V_725 -> V_671 [ 0 ] . V_332 + V_723 ;
} else {
if ( V_725 -> V_672 [ 0 ] . V_332 && V_725 -> V_672 [ 0 ] . V_333 > 0 )
V_732 = ( char * ) V_504 -> V_8 - ( char * ) V_725 -> V_672 [ 0 ] . V_332 ;
V_731 = V_725 -> V_671 [ 0 ] . V_333 + V_725 -> V_665 + V_732 + V_723 ;
}
F_37 ( L_16 , V_733 ,
V_731 , V_725 -> V_665 , V_732 , V_723 ) ;
if ( V_731 > V_728 -> V_734 . V_355 )
return V_735 ;
if ( ( V_730 -> V_736 & V_737 ) &&
V_731 > V_728 -> V_734 . V_356 )
return V_738 ;
return 0 ;
}
void
F_210 ( struct V_503 * V_504 , struct V_387 * V_388 )
{
struct V_739 * V_740 = V_504 -> V_506 . V_741 ;
T_1 * V_742 ;
T_1 * V_8 ;
F_162 ( 8 ) ;
F_99 ( V_388 -> V_389 ) ;
V_742 = V_8 ++ ;
F_163 () ;
if ( V_388 -> V_389 == V_409 )
goto V_41;
F_14 ( V_388 -> V_389 < 0 || V_388 -> V_389 >= F_88 ( V_743 ) ||
! V_743 [ V_388 -> V_389 ] ) ;
V_388 -> V_41 = V_743 [ V_388 -> V_389 ] ( V_504 , V_388 -> V_41 , & V_388 -> V_408 ) ;
if ( ! V_388 -> V_41 )
V_388 -> V_41 = F_208 ( V_504 , 0 ) ;
if ( V_740 ) {
V_740 -> V_744 . V_745 = V_388 -> V_41 ;
V_740 -> V_744 . V_746 = ( char * ) V_504 -> V_8 - ( char * ) ( V_742 + 1 ) ;
memcpy ( V_740 -> V_744 . V_747 , V_742 + 1 , V_740 -> V_744 . V_746 ) ;
}
V_41:
* V_742 = V_388 -> V_41 ;
}
void
F_211 ( struct V_503 * V_504 , struct V_387 * V_388 )
{
T_1 * V_8 ;
struct V_748 * V_749 = V_388 -> V_406 ;
F_14 ( ! V_749 ) ;
F_162 ( 8 ) ;
F_99 ( V_388 -> V_389 ) ;
* V_8 ++ = V_749 -> V_745 ;
F_163 () ;
F_162 ( V_749 -> V_746 ) ;
F_100 ( V_749 -> V_747 , V_749 -> V_746 ) ;
F_163 () ;
}
int
F_212 ( struct V_454 * V_60 , T_1 * V_8 , void * V_104 )
{
return F_213 ( V_60 , V_8 ) ;
}
int F_214 ( void * V_750 , T_1 * V_8 , void * V_504 )
{
struct V_454 * V_60 = V_750 ;
struct V_6 * args = V_60 -> V_751 ;
if ( args -> V_404 != args -> V_403 ) {
F_6 ( args -> V_404 ) ;
args -> V_404 = args -> V_403 ;
}
F_6 ( args -> V_16 ) ;
args -> V_16 = NULL ;
while ( args -> V_26 ) {
struct V_21 * V_22 = args -> V_26 ;
args -> V_26 = V_22 -> V_25 ;
V_22 -> F_11 ( V_22 -> V_24 ) ;
F_6 ( V_22 ) ;
}
return 1 ;
}
int
F_215 ( struct V_454 * V_60 , T_1 * V_8 , struct V_6 * args )
{
args -> V_8 = V_8 ;
args -> V_12 = V_60 -> V_752 . V_671 [ 0 ] . V_332 + V_60 -> V_752 . V_671 [ 0 ] . V_333 ;
args -> V_9 = V_60 -> V_752 . V_335 ;
args -> V_10 = V_60 -> V_752 . V_665 ;
args -> V_16 = NULL ;
args -> V_26 = NULL ;
args -> V_404 = args -> V_403 ;
args -> V_60 = V_60 ;
return ! F_87 ( args ) ;
}
int
F_216 ( struct V_454 * V_60 , T_1 * V_8 , struct V_503 * V_504 )
{
struct V_753 * V_754 = & V_504 -> V_506 ;
struct V_755 * V_756 ;
V_8 = V_504 -> V_757 ;
* V_8 ++ = F_93 ( V_504 -> V_399 ) ;
memcpy ( V_8 , V_504 -> V_400 , V_504 -> V_399 ) ;
V_8 += F_8 ( V_504 -> V_399 ) ;
* V_8 ++ = F_93 ( V_504 -> V_401 ) ;
if ( V_60 -> V_726 . V_665 )
V_756 = & V_60 -> V_726 . V_672 [ 0 ] ;
else
V_756 = & V_60 -> V_726 . V_671 [ 0 ] ;
V_756 -> V_333 = ( ( char * ) V_504 -> V_8 ) - ( char * ) V_756 -> V_332 ;
F_14 ( V_756 -> V_333 > V_11 ) ;
if ( F_209 ( V_754 ) ) {
struct V_507 * V_508 = F_132 ( F_133 ( V_60 ) , V_509 ) ;
struct V_758 * V_759 = V_754 -> V_728 -> V_760 ;
if ( V_754 -> V_41 != V_761 ) {
F_217 ( V_504 ) ;
V_754 -> V_730 -> V_736 &= ~ V_762 ;
}
F_108 ( & V_508 -> V_763 ) ;
F_218 ( V_754 -> V_728 ) ;
F_109 ( & V_508 -> V_763 ) ;
F_219 ( V_759 ) ;
}
return 1 ;
}
