static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_7 ;
T_2 V_8 , V_9 ;
V_8 = F_3 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_7 = ( ( T_1 ) V_9 ) << 32 ;
V_7 |= V_8 ;
return V_7 ;
}
static T_1 F_4 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_8 , V_9 ;
T_1 V_7 ;
F_3 ( V_12 ) ;
V_8 = F_3 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_7 = ( ( T_1 ) V_9 ) << 32 ;
V_7 |= V_8 ;
return V_7 ;
}
static void F_5 ( struct V_3 * V_13 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_2 V_16 , V_17 ;
F_3 ( V_12 ) ;
V_17 = F_3 ( V_10 ) ;
V_16 = F_3 ( V_11 ) ;
V_15 -> V_18 = V_16 ;
V_15 -> V_19 = V_17 ;
}
static void F_6 ( struct V_3 * V_13 ,
const struct V_14 * V_15 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
F_7 ( V_10 , V_15 -> V_19 ) ;
F_7 ( V_11 , ( T_2 ) V_15 -> V_18 ) ;
}
static void F_8 ( struct V_3 * V_13 ,
struct V_20 * V_21 ,
T_1 V_22 )
{
unsigned long V_23 ;
T_1 V_24 ;
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
F_9 ( & V_13 -> V_30 , V_23 ) ;
V_24 = F_10 ( & V_13 -> V_31 , V_22 ) ;
F_11 ( & V_13 -> V_30 , V_23 ) ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_32 = F_12 ( V_24 ) ;
break;
case V_33 :
case V_34 :
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
V_21 -> V_32 = F_13 ( V_22 >> 32 ,
V_22 & 0xFFFFFFFF ) ;
break;
default:
break;
}
}
static int F_14 ( struct V_35 * V_36 , T_3 V_37 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_39 = 0 ;
T_1 V_40 ;
T_2 V_41 ;
if ( V_37 < 0 ) {
V_39 = 1 ;
V_37 = - V_37 ;
}
V_40 = V_37 ;
V_40 <<= 14 ;
V_40 = F_15 ( V_40 , 1953125 ) ;
V_41 = 16 << V_42 ;
if ( V_39 )
V_41 -= V_40 ;
else
V_41 += V_40 ;
F_7 ( V_43 , V_44 | ( V_41 & V_45 ) ) ;
return 0 ;
}
static int F_16 ( struct V_35 * V_36 , long V_46 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_39 = 0 ;
T_1 V_40 ;
T_2 V_47 ;
if ( V_46 < 0 ) {
V_39 = 1 ;
V_46 = - V_46 ;
}
V_40 = V_46 ;
V_40 <<= 13 ;
V_40 = F_15 ( V_40 , 15625 ) ;
V_47 = V_40 & V_48 ;
if ( V_39 )
V_47 |= V_49 ;
F_7 ( V_43 , V_47 ) ;
return 0 ;
}
static int F_17 ( struct V_35 * V_36 , T_4 V_50 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_18 ( & V_4 -> V_31 , V_50 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_35 * V_36 , T_4 V_50 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
struct V_14 V_51 , V_52 = F_20 ( V_50 ) ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_5 ( V_4 , & V_51 ) ;
V_51 = F_21 ( V_51 , V_52 ) ;
F_6 ( V_4 , ( const struct V_14 * ) & V_51 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
T_1 V_24 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_24 = F_23 ( & V_4 -> V_31 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
* V_15 = F_20 ( V_24 ) ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_5 ( V_4 , V_15 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_25 ( struct V_35 * V_36 ,
const struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
T_1 V_24 ;
V_24 = F_26 ( V_15 ) ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_27 ( & V_4 -> V_31 , & V_4 -> V_2 , V_24 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_28 ( struct V_35 * V_36 ,
const struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_6 ( V_4 , V_15 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static void F_29 ( int V_53 , int V_54 , T_2 * V_55 , T_2 * V_56 )
{
T_2 * V_57 = V_53 < 2 ? V_55 : V_56 ;
static const T_2 V_58 [ V_59 ] = {
V_60 ,
V_61 ,
V_62 ,
V_63 ,
} ;
if ( V_54 )
* V_57 &= ~ V_58 [ V_53 ] ;
else
* V_57 |= V_58 [ V_53 ] ;
}
static void F_30 ( struct V_3 * V_4 , int V_64 , int V_53 )
{
static const T_2 V_65 [ V_59 ] = {
V_66 , V_67 , V_68 , V_69 ,
} ;
static const T_2 V_70 [ V_59 ] = {
V_71 , V_72 , V_73 , V_74 ,
} ;
static const T_2 V_75 [ V_59 ] = {
V_76 , V_77 , V_78 , V_79 ,
} ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_55 , V_56 , V_80 = 0 ;
V_55 = F_3 ( V_81 ) ;
V_56 = F_3 ( V_82 ) ;
V_80 = F_3 ( V_83 ) ;
F_29 ( V_53 , 1 , & V_55 , & V_56 ) ;
V_80 &= ~ V_75 [ V_53 ] ;
if ( V_64 == 1 ) {
V_80 &= ~ V_74 ;
V_80 |= V_70 [ V_53 ] | V_84 ;
} else {
V_80 &= ~ V_69 ;
V_80 |= V_65 [ V_53 ] | V_85 ;
}
F_7 ( V_83 , V_80 ) ;
F_7 ( V_81 , V_55 ) ;
F_7 ( V_82 , V_56 ) ;
}
static void F_31 ( struct V_3 * V_4 , int V_64 , int V_53 , int V_86 )
{
static const T_2 V_65 [ V_59 ] = {
V_66 , V_67 , V_68 , V_69 ,
} ;
static const T_2 V_70 [ V_59 ] = {
V_71 , V_72 , V_73 , V_74 ,
} ;
static const T_2 V_75 [ V_59 ] = {
V_76 , V_77 , V_78 , V_79 ,
} ;
static const T_2 V_87 [ V_59 ] = {
V_88 , V_89 ,
V_90 , V_91 ,
} ;
static const T_2 V_92 [ V_59 ] = {
V_93 , V_94 ,
V_95 , V_96 ,
} ;
static const T_2 V_97 [ V_59 ] = {
V_98 , V_99 ,
V_100 , V_101 ,
} ;
static const T_2 V_102 [ V_59 ] = {
V_103 , V_104 ,
V_105 , V_106 ,
} ;
static const T_2 V_107 [ V_59 ] = {
V_103 , V_104 ,
V_105 , V_106 ,
} ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_55 , V_56 , V_80 = 0 ;
V_55 = F_3 ( V_81 ) ;
V_56 = F_3 ( V_82 ) ;
V_80 = F_3 ( V_83 ) ;
F_29 ( V_53 , 0 , & V_55 , & V_56 ) ;
if ( ( V_80 & V_69 ) == V_65 [ V_53 ] )
V_80 &= ~ V_85 ;
if ( ( V_80 & V_74 ) == V_70 [ V_53 ] )
V_80 &= ~ V_84 ;
V_80 &= ~ V_107 [ V_53 ] ;
if ( V_86 ) {
if ( V_64 == 1 )
V_80 |= V_102 [ V_53 ] ;
else
V_80 |= V_97 [ V_53 ] ;
} else {
if ( V_64 == 1 )
V_80 |= V_92 [ V_53 ] ;
else
V_80 |= V_87 [ V_53 ] ;
}
V_80 |= V_75 [ V_53 ] ;
F_7 ( V_83 , V_80 ) ;
F_7 ( V_81 , V_55 ) ;
F_7 ( V_82 , V_56 ) ;
}
static int F_32 ( struct V_35 * V_36 ,
struct V_108 * V_109 , int V_110 )
{
struct V_3 * V_4 =
F_2 ( V_36 , struct V_3 , V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_111 , V_112 , V_113 , V_114 , V_115 , V_116 , V_117 ;
unsigned long V_23 ;
struct V_14 V_15 ;
int V_118 = 0 , V_53 = - 1 ;
T_4 V_24 ;
switch ( V_109 -> type ) {
case V_119 :
if ( V_110 ) {
V_53 = F_33 ( V_4 -> V_120 , V_121 ,
V_109 -> V_122 . V_123 ) ;
if ( V_53 < 0 )
return - V_124 ;
}
if ( V_109 -> V_122 . V_123 == 1 ) {
V_113 = V_125 ;
V_114 = V_126 ;
} else {
V_113 = V_127 ;
V_114 = V_128 ;
}
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_111 = F_3 ( V_129 ) ;
V_112 = F_3 ( V_130 ) ;
if ( V_110 ) {
F_30 ( V_4 , V_109 -> V_122 . V_123 , V_53 ) ;
V_111 |= V_113 ;
V_112 |= V_114 ;
} else {
V_111 &= ~ V_113 ;
V_112 &= ~ V_114 ;
}
F_7 ( V_129 , V_111 ) ;
F_7 ( V_130 , V_112 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
case V_131 :
if ( V_110 ) {
V_53 = F_33 ( V_4 -> V_120 , V_132 ,
V_109 -> V_133 . V_123 ) ;
if ( V_53 < 0 )
return - V_124 ;
}
V_15 . V_18 = V_109 -> V_133 . V_134 . V_16 ;
V_15 . V_19 = V_109 -> V_133 . V_134 . V_17 ;
V_24 = F_26 ( & V_15 ) ;
V_24 = V_24 >> 1 ;
if ( V_110 && ( ( V_24 <= 70000000LL ) || ( V_24 == 125000000LL ) ||
( V_24 == 250000000LL ) || ( V_24 == 500000000LL ) ) ) {
if ( V_24 < 8LL )
return - V_135 ;
V_118 = 1 ;
}
V_15 = F_20 ( V_24 ) ;
if ( V_109 -> V_133 . V_123 == 1 ) {
if ( V_118 ) {
V_113 = V_136 | V_137 ;
V_114 = 0 ;
} else {
V_113 = V_138 ;
V_114 = V_139 ;
}
V_115 = V_140 ;
V_116 = V_141 ;
V_117 = V_142 ;
} else {
if ( V_118 ) {
V_113 = V_143 | V_144 ;
V_114 = 0 ;
} else {
V_113 = V_145 ;
V_114 = V_146 ;
}
V_115 = V_147 ;
V_116 = V_148 ;
V_117 = V_149 ;
}
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_111 = F_3 ( V_129 ) ;
V_112 = F_3 ( V_130 ) ;
if ( V_109 -> V_133 . V_123 == 1 ) {
V_111 &= ~ ( V_138 | V_136 | V_137 ) ;
V_112 &= ~ V_139 ;
} else {
V_111 &= ~ ( V_145 | V_143 | V_144 ) ;
V_112 &= ~ V_146 ;
}
if ( V_110 ) {
int V_150 = V_109 -> V_133 . V_123 ;
F_31 ( V_4 , V_150 , V_53 , V_118 ) ;
V_4 -> V_133 [ V_150 ] . V_151 . V_18 = V_109 -> V_133 . V_151 . V_16 ;
V_4 -> V_133 [ V_150 ] . V_151 . V_19 = V_109 -> V_133 . V_151 . V_17 ;
V_4 -> V_133 [ V_150 ] . V_134 . V_18 = V_15 . V_18 ;
V_4 -> V_133 [ V_150 ] . V_134 . V_19 = V_15 . V_19 ;
F_7 ( V_116 , V_109 -> V_133 . V_151 . V_16 ) ;
F_7 ( V_115 , V_109 -> V_133 . V_151 . V_17 ) ;
if ( V_118 )
F_7 ( V_117 , V_24 ) ;
V_111 |= V_113 ;
V_112 |= V_114 ;
}
F_7 ( V_129 , V_111 ) ;
F_7 ( V_130 , V_112 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
case V_152 :
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_112 = F_3 ( V_130 ) ;
if ( V_110 )
V_112 |= V_153 ;
else
V_112 &= ~ V_153 ;
V_4 -> V_154 = ! ! V_110 ;
F_7 ( V_130 , V_112 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
return - V_155 ;
}
static int F_34 ( struct V_35 * V_36 ,
struct V_108 * V_109 , int V_110 )
{
return - V_155 ;
}
static int F_35 ( struct V_35 * V_36 , unsigned int V_53 ,
enum V_156 V_157 , unsigned int V_64 )
{
switch ( V_157 ) {
case V_158 :
case V_121 :
case V_132 :
break;
case V_159 :
return - 1 ;
}
return 0 ;
}
static void F_36 ( struct V_160 * V_161 )
{
struct V_3 * V_13 = F_2 ( V_161 , struct V_3 ,
V_162 ) ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_2 V_163 ;
if ( ! V_13 -> V_164 )
return;
if ( F_37 ( V_13 -> V_165 +
V_166 ) ) {
F_38 ( V_13 -> V_164 ) ;
V_13 -> V_164 = NULL ;
F_39 ( V_167 , & V_13 -> V_168 ) ;
V_13 -> V_169 ++ ;
F_40 ( & V_13 -> V_170 -> V_171 , L_1 ) ;
return;
}
V_163 = F_3 ( V_172 ) ;
if ( V_163 & V_173 )
F_41 ( V_13 ) ;
else
F_42 ( & V_13 -> V_162 ) ;
}
static void F_43 ( struct V_160 * V_161 )
{
struct V_3 * V_4 =
F_2 ( V_161 , struct V_3 , V_174 . V_161 ) ;
struct V_14 V_15 ;
V_4 -> V_38 . V_175 ( & V_4 -> V_38 , & V_15 ) ;
F_44 ( L_2 ,
( long long ) V_15 . V_18 , V_15 . V_19 ) ;
F_45 ( & V_4 -> V_174 ,
V_176 ) ;
}
void F_46 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_2 V_177 = F_3 ( V_178 ) ;
unsigned long V_179 ;
if ( V_6 -> V_25 . type != V_26 )
return;
if ( ! ( V_177 & V_180 ) ) {
V_13 -> V_181 = V_182 ;
return;
}
V_179 = V_13 -> V_181 ;
if ( F_47 ( V_13 -> V_183 , V_179 ) )
V_179 = V_13 -> V_183 ;
if ( F_37 ( V_179 + 5 * V_184 ) ) {
F_3 ( V_185 ) ;
V_13 -> V_181 = V_182 ;
V_13 -> V_186 ++ ;
F_40 ( & V_13 -> V_170 -> V_171 , L_3 ) ;
}
}
static void F_41 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_20 V_187 ;
T_1 V_188 ;
int V_189 = 0 ;
V_188 = F_3 ( V_190 ) ;
V_188 |= ( T_1 ) F_3 ( V_191 ) << 32 ;
F_8 ( V_13 , & V_187 , V_188 ) ;
if ( V_13 -> V_6 . V_25 . type == V_33 ) {
switch ( V_13 -> V_192 ) {
case V_193 :
V_189 = V_194 ;
break;
case V_195 :
V_189 = V_196 ;
break;
case V_197 :
V_189 = V_198 ;
break;
}
}
V_187 . V_32 =
F_48 ( V_187 . V_32 , V_189 ) ;
F_49 ( V_13 -> V_164 , & V_187 ) ;
F_38 ( V_13 -> V_164 ) ;
V_13 -> V_164 = NULL ;
F_39 ( V_167 , & V_13 -> V_168 ) ;
}
void F_50 ( struct V_199 * V_200 , void * V_201 ,
struct V_202 * V_203 )
{
T_5 * V_188 = ( T_5 * ) V_201 ;
struct V_3 * V_13 = V_200 -> V_13 ;
int V_189 = 0 ;
F_8 ( V_13 , F_51 ( V_203 ) ,
F_52 ( V_188 [ 1 ] ) ) ;
if ( V_13 -> V_6 . V_25 . type == V_33 ) {
switch ( V_13 -> V_192 ) {
case V_193 :
V_189 = V_204 ;
break;
case V_195 :
V_189 = V_205 ;
break;
case V_197 :
V_189 = V_206 ;
break;
}
}
F_51 ( V_203 ) -> V_32 =
F_53 ( F_51 ( V_203 ) -> V_32 , V_189 ) ;
}
void F_54 ( struct V_199 * V_200 ,
struct V_202 * V_203 )
{
struct V_3 * V_13 = V_200 -> V_13 ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_1 V_188 ;
int V_189 = 0 ;
if ( ! ( F_3 ( V_178 ) & V_180 ) )
return;
V_188 = F_3 ( V_207 ) ;
V_188 |= ( T_1 ) F_3 ( V_185 ) << 32 ;
F_8 ( V_13 , F_51 ( V_203 ) , V_188 ) ;
if ( V_13 -> V_6 . V_25 . type == V_33 ) {
switch ( V_13 -> V_192 ) {
case V_193 :
V_189 = V_204 ;
break;
case V_195 :
V_189 = V_205 ;
break;
case V_197 :
V_189 = V_206 ;
break;
}
}
F_51 ( V_203 ) -> V_32 =
F_53 ( F_51 ( V_203 ) -> V_32 , V_189 ) ;
V_13 -> V_183 = V_182 ;
}
int F_55 ( struct V_208 * V_209 , struct V_210 * V_211 )
{
struct V_3 * V_13 = F_56 ( V_209 ) ;
struct V_212 * V_213 = & V_13 -> V_214 ;
return F_57 ( V_211 -> V_215 , V_213 , sizeof( * V_213 ) ) ?
- V_216 : 0 ;
}
static int F_58 ( struct V_3 * V_13 ,
struct V_212 * V_213 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_2 V_217 = V_218 ;
T_2 V_219 = V_220 ;
T_2 V_221 = 0 ;
bool V_222 = false ;
bool V_223 = false ;
T_2 V_188 ;
if ( V_213 -> V_23 )
return - V_135 ;
switch ( V_213 -> V_224 ) {
case V_225 :
V_217 = 0 ;
case V_226 :
break;
default:
return - V_227 ;
}
switch ( V_213 -> V_228 ) {
case V_229 :
V_219 = 0 ;
break;
case V_230 :
V_219 |= V_231 ;
V_221 = V_232 ;
V_222 = true ;
break;
case V_233 :
V_219 |= V_231 ;
V_221 = V_234 ;
V_222 = true ;
break;
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
V_219 |= V_244 ;
V_213 -> V_228 = V_235 ;
V_223 = true ;
V_222 = true ;
break;
case V_245 :
case V_246 :
if ( V_6 -> V_25 . type != V_26 ) {
V_219 |= V_247 ;
V_213 -> V_228 = V_246 ;
break;
}
default:
V_213 -> V_228 = V_229 ;
return - V_227 ;
}
if ( V_6 -> V_25 . type == V_248 ) {
if ( V_219 | V_217 )
return - V_135 ;
return 0 ;
}
if ( ( V_6 -> V_25 . type >= V_27 ) && V_219 ) {
V_219 = V_220 ;
V_219 |= V_247 ;
V_213 -> V_228 = V_246 ;
V_223 = true ;
V_222 = true ;
if ( ( V_6 -> V_25 . type == V_33 ) ||
( V_6 -> V_25 . type == V_34 ) ) {
V_188 = F_3 ( V_249 ) ;
V_188 |= V_250 ;
F_7 ( V_249 , V_188 ) ;
}
}
V_188 = F_3 ( V_172 ) ;
V_188 &= ~ V_218 ;
V_188 |= V_217 ;
F_7 ( V_172 , V_188 ) ;
V_188 = F_3 ( V_178 ) ;
V_188 &= ~ ( V_220 | V_251 ) ;
V_188 |= V_219 ;
F_7 ( V_178 , V_188 ) ;
F_7 ( V_252 , V_221 ) ;
if ( V_223 )
F_7 ( F_59 ( V_253 ) ,
( V_254 |
V_255 |
V_256 ) ) ;
else
F_7 ( F_59 ( V_253 ) , 0 ) ;
if ( V_222 ) {
T_2 V_257 = ( V_258
| V_259
| V_260
| V_261 ) ;
V_257 &= ~ V_262 ;
F_7 ( F_60 ( 3 ) , F_61 ( V_263 ) ) ;
F_7 ( F_62 ( 3 ) ,
( V_264 | V_265 ) ) ;
if ( V_6 -> V_25 . type == V_26 ) {
F_7 ( F_63 ( 3 ) , F_61 ( V_263 ) ) ;
V_257 &= ~ V_266 ;
}
F_7 ( F_64 ( 3 ) , V_257 ) ;
} else {
F_7 ( F_64 ( 3 ) , V_261 ) ;
}
F_65 () ;
V_188 = F_3 ( V_190 ) ;
V_188 = F_3 ( V_191 ) ;
V_188 = F_3 ( V_207 ) ;
V_188 = F_3 ( V_185 ) ;
return 0 ;
}
int F_66 ( struct V_208 * V_209 , struct V_210 * V_211 )
{
struct V_3 * V_13 = F_56 ( V_209 ) ;
struct V_212 V_213 ;
int V_267 ;
if ( F_67 ( & V_213 , V_211 -> V_215 , sizeof( V_213 ) ) )
return - V_216 ;
V_267 = F_58 ( V_13 , & V_213 ) ;
if ( V_267 )
return V_267 ;
memcpy ( & V_13 -> V_214 , & V_213 ,
sizeof( V_13 -> V_214 ) ) ;
return F_57 ( V_211 -> V_215 , & V_213 , sizeof( V_213 ) ) ?
- V_216 : 0 ;
}
void F_68 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_208 * V_209 = V_13 -> V_209 ;
int V_150 ;
switch ( V_6 -> V_25 . type ) {
case V_26 :
snprintf ( V_13 -> V_38 . V_268 , 16 , L_4 , V_209 -> V_269 ) ;
V_13 -> V_38 . V_270 = V_271 ;
V_13 -> V_38 . V_272 = 999999881 ;
V_13 -> V_38 . V_273 = 0 ;
V_13 -> V_38 . V_274 = 0 ;
V_13 -> V_38 . V_275 = F_14 ;
V_13 -> V_38 . V_276 = F_17 ;
V_13 -> V_38 . V_175 = F_22 ;
V_13 -> V_38 . V_277 = F_25 ;
V_13 -> V_38 . V_278 = F_34 ;
V_13 -> V_2 . V_279 = F_1 ;
V_13 -> V_2 . V_58 = F_69 ( 64 ) ;
V_13 -> V_2 . V_280 = 1 ;
V_13 -> V_2 . V_281 = V_42 ;
V_13 -> V_282 |= V_283 ;
break;
case V_27 :
case V_28 :
case V_29 :
snprintf ( V_13 -> V_38 . V_268 , 16 , L_4 , V_209 -> V_269 ) ;
V_13 -> V_38 . V_270 = V_271 ;
V_13 -> V_38 . V_272 = 62499999 ;
V_13 -> V_38 . V_273 = 0 ;
V_13 -> V_38 . V_274 = 0 ;
V_13 -> V_38 . V_284 = F_16 ;
V_13 -> V_38 . V_276 = F_17 ;
V_13 -> V_38 . V_175 = F_22 ;
V_13 -> V_38 . V_277 = F_25 ;
V_13 -> V_38 . V_278 = F_34 ;
V_13 -> V_2 . V_279 = F_4 ;
V_13 -> V_2 . V_58 = F_69 ( V_285 ) ;
V_13 -> V_2 . V_280 = 1 ;
V_13 -> V_2 . V_281 = 0 ;
V_13 -> V_282 |= V_283 ;
break;
case V_33 :
case V_34 :
for ( V_150 = 0 ; V_150 < V_59 ; V_150 ++ ) {
struct V_286 * V_287 = & V_13 -> V_288 [ V_150 ] ;
snprintf ( V_287 -> V_268 , sizeof( V_287 -> V_268 ) , L_5 , V_150 ) ;
V_287 -> V_123 = V_150 ;
V_287 -> V_157 = V_158 ;
}
snprintf ( V_13 -> V_38 . V_268 , 16 , L_4 , V_209 -> V_269 ) ;
V_13 -> V_38 . V_270 = V_271 ;
V_13 -> V_38 . V_272 = 62499999 ;
V_13 -> V_38 . V_273 = V_289 ;
V_13 -> V_38 . V_290 = V_291 ;
V_13 -> V_38 . V_292 = V_59 ;
V_13 -> V_38 . V_274 = 1 ;
V_13 -> V_38 . V_293 = V_13 -> V_288 ;
V_13 -> V_38 . V_284 = F_16 ;
V_13 -> V_38 . V_276 = F_19 ;
V_13 -> V_38 . V_175 = F_24 ;
V_13 -> V_38 . V_277 = F_28 ;
V_13 -> V_38 . V_278 = F_32 ;
V_13 -> V_38 . V_294 = F_35 ;
break;
default:
V_13 -> V_120 = NULL ;
return;
}
F_70 ( & V_13 -> V_30 ) ;
F_71 ( & V_13 -> V_162 , F_36 ) ;
if ( V_13 -> V_282 & V_283 )
F_72 ( & V_13 -> V_174 ,
F_43 ) ;
V_13 -> V_214 . V_228 = V_229 ;
V_13 -> V_214 . V_224 = V_225 ;
F_73 ( V_13 ) ;
V_13 -> V_120 = F_74 ( & V_13 -> V_38 ,
& V_13 -> V_170 -> V_171 ) ;
if ( F_75 ( V_13 -> V_120 ) ) {
V_13 -> V_120 = NULL ;
F_76 ( & V_13 -> V_170 -> V_171 , L_6 ) ;
} else if ( V_13 -> V_120 ) {
F_77 ( & V_13 -> V_170 -> V_171 , L_7 ,
V_13 -> V_209 -> V_268 ) ;
V_13 -> V_282 |= V_295 ;
}
}
void F_78 ( struct V_3 * V_13 )
{
if ( ! ( V_13 -> V_282 & V_295 ) )
return;
if ( V_13 -> V_282 & V_283 )
F_79 ( & V_13 -> V_174 ) ;
F_80 ( & V_13 -> V_162 ) ;
if ( V_13 -> V_164 ) {
F_38 ( V_13 -> V_164 ) ;
V_13 -> V_164 = NULL ;
F_39 ( V_167 , & V_13 -> V_168 ) ;
}
}
void F_81 ( struct V_3 * V_13 )
{
F_78 ( V_13 ) ;
if ( V_13 -> V_120 ) {
F_82 ( V_13 -> V_120 ) ;
F_77 ( & V_13 -> V_170 -> V_171 , L_8 ,
V_13 -> V_209 -> V_268 ) ;
V_13 -> V_282 &= ~ V_295 ;
}
}
void F_73 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
unsigned long V_23 ;
F_58 ( V_13 , & V_13 -> V_214 ) ;
F_9 ( & V_13 -> V_30 , V_23 ) ;
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
F_7 ( V_43 , V_44 | V_296 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_33 :
case V_34 :
F_7 ( V_129 , 0x0 ) ;
F_7 ( V_83 , 0x0 ) ;
F_7 ( V_130 ,
V_297 |
( V_13 -> V_154 ? V_153 : 0 ) ) ;
F_7 ( V_298 , V_299 ) ;
break;
default:
goto V_300;
}
if ( ( V_6 -> V_25 . type == V_33 ) || ( V_6 -> V_25 . type == V_34 ) ) {
struct V_14 V_15 = F_83 ( F_84 () ) ;
F_6 ( V_13 , & V_15 ) ;
} else {
F_27 ( & V_13 -> V_31 , & V_13 -> V_2 ,
F_85 ( F_84 () ) ) ;
}
V_300:
F_11 ( & V_13 -> V_30 , V_23 ) ;
F_65 () ;
if ( V_13 -> V_282 & V_283 )
F_45 ( & V_13 -> V_174 ,
V_176 ) ;
}
