static T_1 F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_2 V_7 ;
T_3 V_8 , V_9 ;
V_8 = F_3 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_7 = ( ( T_2 ) V_9 ) << 32 ;
V_7 |= V_8 ;
return V_7 ;
}
static T_1 F_4 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_3 V_8 , V_9 ;
T_2 V_7 ;
F_3 ( V_12 ) ;
V_8 = F_3 ( V_10 ) ;
V_9 = F_3 ( V_11 ) ;
V_7 = ( ( T_2 ) V_9 ) << 32 ;
V_7 |= V_8 ;
return V_7 ;
}
static void F_5 ( struct V_3 * V_13 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_16 , V_17 ;
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
F_7 ( V_11 , ( T_3 ) V_15 -> V_18 ) ;
}
static void F_8 ( struct V_3 * V_13 ,
struct V_20 * V_21 ,
T_2 V_22 )
{
unsigned long V_23 ;
T_2 V_24 ;
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
static int F_14 ( struct V_35 * V_36 , T_4 V_37 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_39 = 0 ;
T_2 V_40 ;
T_3 V_41 ;
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
static int F_16 ( struct V_35 * V_36 , T_4 V_37 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_39 = 0 ;
T_2 V_40 ;
T_3 V_46 ;
if ( V_37 < 0 ) {
V_39 = 1 ;
V_37 = - V_37 ;
}
V_40 = V_37 ;
V_40 <<= 26 ;
V_40 = F_15 ( V_40 , 1953125 ) ;
V_46 = V_40 & V_47 ;
if ( V_39 )
V_46 |= V_48 ;
F_7 ( V_43 , V_46 ) ;
return 0 ;
}
static int F_17 ( struct V_35 * V_36 , T_5 V_49 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_18 ( & V_4 -> V_31 , V_49 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_19 ( struct V_35 * V_36 , T_5 V_49 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
struct V_14 V_50 , V_51 = F_20 ( V_49 ) ;
F_9 ( & V_4 -> V_30 , V_23 ) ;
F_5 ( V_4 , & V_50 ) ;
V_50 = F_21 ( V_50 , V_51 ) ;
F_6 ( V_4 , ( const struct V_14 * ) & V_50 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 ,
struct V_14 * V_15 )
{
struct V_3 * V_4 = F_2 ( V_36 , struct V_3 ,
V_38 ) ;
unsigned long V_23 ;
T_2 V_24 ;
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
T_2 V_24 ;
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
static void F_29 ( int V_52 , int V_53 , T_3 * V_54 , T_3 * V_55 )
{
T_3 * V_56 = V_52 < 2 ? V_54 : V_55 ;
static const T_3 V_57 [ V_58 ] = {
V_59 ,
V_60 ,
V_61 ,
V_62 ,
} ;
if ( V_53 )
* V_56 &= ~ V_57 [ V_52 ] ;
else
* V_56 |= V_57 [ V_52 ] ;
}
static void F_30 ( struct V_3 * V_4 , int V_63 , int V_52 )
{
static const T_3 V_64 [ V_58 ] = {
V_65 , V_66 , V_67 , V_68 ,
} ;
static const T_3 V_69 [ V_58 ] = {
V_70 , V_71 , V_72 , V_73 ,
} ;
static const T_3 V_74 [ V_58 ] = {
V_75 , V_76 , V_77 , V_78 ,
} ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_3 V_54 , V_55 , V_79 = 0 ;
V_54 = F_3 ( V_80 ) ;
V_55 = F_3 ( V_81 ) ;
V_79 = F_3 ( V_82 ) ;
F_29 ( V_52 , 1 , & V_54 , & V_55 ) ;
V_79 &= ~ V_74 [ V_52 ] ;
if ( V_63 == 1 ) {
V_79 &= ~ V_73 ;
V_79 |= V_69 [ V_52 ] | V_83 ;
} else {
V_79 &= ~ V_68 ;
V_79 |= V_64 [ V_52 ] | V_84 ;
}
F_7 ( V_82 , V_79 ) ;
F_7 ( V_80 , V_54 ) ;
F_7 ( V_81 , V_55 ) ;
}
static void F_31 ( struct V_3 * V_4 , int V_63 , int V_52 , int V_85 )
{
static const T_3 V_64 [ V_58 ] = {
V_65 , V_66 , V_67 , V_68 ,
} ;
static const T_3 V_69 [ V_58 ] = {
V_70 , V_71 , V_72 , V_73 ,
} ;
static const T_3 V_74 [ V_58 ] = {
V_75 , V_76 , V_77 , V_78 ,
} ;
static const T_3 V_86 [ V_58 ] = {
V_87 , V_88 ,
V_89 , V_90 ,
} ;
static const T_3 V_91 [ V_58 ] = {
V_92 , V_93 ,
V_94 , V_95 ,
} ;
static const T_3 V_96 [ V_58 ] = {
V_97 , V_98 ,
V_99 , V_100 ,
} ;
static const T_3 V_101 [ V_58 ] = {
V_102 , V_103 ,
V_104 , V_105 ,
} ;
static const T_3 V_106 [ V_58 ] = {
V_102 , V_103 ,
V_104 , V_105 ,
} ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_3 V_54 , V_55 , V_79 = 0 ;
V_54 = F_3 ( V_80 ) ;
V_55 = F_3 ( V_81 ) ;
V_79 = F_3 ( V_82 ) ;
F_29 ( V_52 , 0 , & V_54 , & V_55 ) ;
if ( ( V_79 & V_68 ) == V_64 [ V_52 ] )
V_79 &= ~ V_84 ;
if ( ( V_79 & V_73 ) == V_69 [ V_52 ] )
V_79 &= ~ V_83 ;
V_79 &= ~ V_106 [ V_52 ] ;
if ( V_85 ) {
if ( V_63 == 1 )
V_79 |= V_101 [ V_52 ] ;
else
V_79 |= V_96 [ V_52 ] ;
} else {
if ( V_63 == 1 )
V_79 |= V_91 [ V_52 ] ;
else
V_79 |= V_86 [ V_52 ] ;
}
V_79 |= V_74 [ V_52 ] ;
F_7 ( V_82 , V_79 ) ;
F_7 ( V_80 , V_54 ) ;
F_7 ( V_81 , V_55 ) ;
}
static int F_32 ( struct V_35 * V_36 ,
struct V_107 * V_108 , int V_109 )
{
struct V_3 * V_4 =
F_2 ( V_36 , struct V_3 , V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_3 V_110 , V_111 , V_112 , V_113 , V_114 , V_115 , V_116 ;
unsigned long V_23 ;
struct V_14 V_15 ;
int V_117 = 0 , V_52 = - 1 ;
T_5 V_24 ;
switch ( V_108 -> type ) {
case V_118 :
if ( V_109 ) {
V_52 = F_33 ( V_4 -> V_119 , V_120 ,
V_108 -> V_121 . V_122 ) ;
if ( V_52 < 0 )
return - V_123 ;
}
if ( V_108 -> V_121 . V_122 == 1 ) {
V_112 = V_124 ;
V_113 = V_125 ;
} else {
V_112 = V_126 ;
V_113 = V_127 ;
}
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_110 = F_3 ( V_128 ) ;
V_111 = F_3 ( V_129 ) ;
if ( V_109 ) {
F_30 ( V_4 , V_108 -> V_121 . V_122 , V_52 ) ;
V_110 |= V_112 ;
V_111 |= V_113 ;
} else {
V_110 &= ~ V_112 ;
V_111 &= ~ V_113 ;
}
F_7 ( V_128 , V_110 ) ;
F_7 ( V_129 , V_111 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
case V_130 :
if ( V_109 ) {
V_52 = F_33 ( V_4 -> V_119 , V_131 ,
V_108 -> V_132 . V_122 ) ;
if ( V_52 < 0 )
return - V_123 ;
}
V_15 . V_18 = V_108 -> V_132 . V_133 . V_16 ;
V_15 . V_19 = V_108 -> V_132 . V_133 . V_17 ;
V_24 = F_26 ( & V_15 ) ;
V_24 = V_24 >> 1 ;
if ( V_109 && ( ( V_24 <= 70000000LL ) || ( V_24 == 125000000LL ) ||
( V_24 == 250000000LL ) || ( V_24 == 500000000LL ) ) ) {
if ( V_24 < 8LL )
return - V_134 ;
V_117 = 1 ;
}
V_15 = F_20 ( V_24 ) ;
if ( V_108 -> V_132 . V_122 == 1 ) {
if ( V_117 ) {
V_112 = V_135 | V_136 ;
V_113 = 0 ;
} else {
V_112 = V_137 ;
V_113 = V_138 ;
}
V_114 = V_139 ;
V_115 = V_140 ;
V_116 = V_141 ;
} else {
if ( V_117 ) {
V_112 = V_142 | V_143 ;
V_113 = 0 ;
} else {
V_112 = V_144 ;
V_113 = V_145 ;
}
V_114 = V_146 ;
V_115 = V_147 ;
V_116 = V_148 ;
}
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_110 = F_3 ( V_128 ) ;
V_111 = F_3 ( V_129 ) ;
if ( V_108 -> V_132 . V_122 == 1 ) {
V_110 &= ~ ( V_137 | V_135 | V_136 ) ;
V_111 &= ~ V_138 ;
} else {
V_110 &= ~ ( V_144 | V_142 | V_143 ) ;
V_111 &= ~ V_145 ;
}
if ( V_109 ) {
int V_149 = V_108 -> V_132 . V_122 ;
F_31 ( V_4 , V_149 , V_52 , V_117 ) ;
V_4 -> V_132 [ V_149 ] . V_150 . V_18 = V_108 -> V_132 . V_150 . V_16 ;
V_4 -> V_132 [ V_149 ] . V_150 . V_19 = V_108 -> V_132 . V_150 . V_17 ;
V_4 -> V_132 [ V_149 ] . V_133 . V_18 = V_15 . V_18 ;
V_4 -> V_132 [ V_149 ] . V_133 . V_19 = V_15 . V_19 ;
F_7 ( V_115 , V_108 -> V_132 . V_150 . V_16 ) ;
F_7 ( V_114 , V_108 -> V_132 . V_150 . V_17 ) ;
if ( V_117 )
F_7 ( V_116 , V_24 ) ;
V_110 |= V_112 ;
V_111 |= V_113 ;
}
F_7 ( V_128 , V_110 ) ;
F_7 ( V_129 , V_111 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
case V_151 :
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_111 = F_3 ( V_129 ) ;
if ( V_109 )
V_111 |= V_152 ;
else
V_111 &= ~ V_152 ;
V_4 -> V_153 = ! ! V_109 ;
F_7 ( V_129 , V_111 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
return - V_154 ;
}
static int F_34 ( struct V_35 * V_36 ,
struct V_107 * V_108 , int V_109 )
{
return - V_154 ;
}
static int F_35 ( struct V_35 * V_36 , unsigned int V_52 ,
enum V_155 V_156 , unsigned int V_63 )
{
switch ( V_156 ) {
case V_157 :
case V_120 :
case V_131 :
break;
case V_158 :
return - 1 ;
}
return 0 ;
}
static void F_36 ( struct V_159 * V_160 )
{
struct V_3 * V_13 = F_2 ( V_160 , struct V_3 ,
V_161 ) ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_162 ;
if ( ! V_13 -> V_163 )
return;
if ( F_37 ( V_13 -> V_164 +
V_165 ) ) {
F_38 ( V_13 -> V_163 ) ;
V_13 -> V_163 = NULL ;
F_39 ( V_166 , & V_13 -> V_167 ) ;
V_13 -> V_168 ++ ;
F_40 ( & V_13 -> V_169 -> V_170 , L_1 ) ;
return;
}
V_162 = F_3 ( V_171 ) ;
if ( V_162 & V_172 )
F_41 ( V_13 ) ;
else
F_42 ( & V_13 -> V_161 ) ;
}
static void F_43 ( struct V_159 * V_160 )
{
struct V_3 * V_4 =
F_2 ( V_160 , struct V_3 , V_173 . V_160 ) ;
struct V_14 V_15 ;
V_4 -> V_38 . V_174 ( & V_4 -> V_38 , & V_15 ) ;
F_44 ( L_2 ,
( long long ) V_15 . V_18 , V_15 . V_19 ) ;
F_45 ( & V_4 -> V_173 ,
V_175 ) ;
}
void F_46 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_176 = F_3 ( V_177 ) ;
unsigned long V_178 ;
if ( V_6 -> V_25 . type != V_26 )
return;
if ( ! ( V_176 & V_179 ) ) {
V_13 -> V_180 = V_181 ;
return;
}
V_178 = V_13 -> V_180 ;
if ( F_47 ( V_13 -> V_182 , V_178 ) )
V_178 = V_13 -> V_182 ;
if ( F_37 ( V_178 + 5 * V_183 ) ) {
F_3 ( V_184 ) ;
V_13 -> V_180 = V_181 ;
V_13 -> V_185 ++ ;
F_40 ( & V_13 -> V_169 -> V_170 , L_3 ) ;
}
}
static void F_41 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_20 V_186 ;
T_2 V_187 ;
int V_188 = 0 ;
V_187 = F_3 ( V_189 ) ;
V_187 |= ( T_2 ) F_3 ( V_190 ) << 32 ;
F_8 ( V_13 , & V_186 , V_187 ) ;
if ( V_13 -> V_6 . V_25 . type == V_33 ) {
switch ( V_13 -> V_191 ) {
case V_192 :
V_188 = V_193 ;
break;
case V_194 :
V_188 = V_195 ;
break;
case V_196 :
V_188 = V_197 ;
break;
}
}
V_186 . V_32 =
F_48 ( V_186 . V_32 , V_188 ) ;
F_49 ( V_13 -> V_163 , & V_186 ) ;
F_38 ( V_13 -> V_163 ) ;
V_13 -> V_163 = NULL ;
F_39 ( V_166 , & V_13 -> V_167 ) ;
}
void F_50 ( struct V_198 * V_199 ,
unsigned char * V_200 ,
struct V_201 * V_202 )
{
T_6 * V_187 = ( T_6 * ) V_200 ;
struct V_3 * V_13 = V_199 -> V_13 ;
int V_188 = 0 ;
F_8 ( V_13 , F_51 ( V_202 ) ,
F_52 ( V_187 [ 1 ] ) ) ;
if ( V_13 -> V_6 . V_25 . type == V_33 ) {
switch ( V_13 -> V_191 ) {
case V_192 :
V_188 = V_203 ;
break;
case V_194 :
V_188 = V_204 ;
break;
case V_196 :
V_188 = V_205 ;
break;
}
}
F_51 ( V_202 ) -> V_32 =
F_53 ( F_51 ( V_202 ) -> V_32 , V_188 ) ;
}
void F_54 ( struct V_198 * V_199 ,
struct V_201 * V_202 )
{
struct V_3 * V_13 = V_199 -> V_13 ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_2 V_187 ;
int V_188 = 0 ;
if ( ! ( F_3 ( V_177 ) & V_179 ) )
return;
V_187 = F_3 ( V_206 ) ;
V_187 |= ( T_2 ) F_3 ( V_184 ) << 32 ;
F_8 ( V_13 , F_51 ( V_202 ) , V_187 ) ;
if ( V_13 -> V_6 . V_25 . type == V_33 ) {
switch ( V_13 -> V_191 ) {
case V_192 :
V_188 = V_203 ;
break;
case V_194 :
V_188 = V_204 ;
break;
case V_196 :
V_188 = V_205 ;
break;
}
}
F_51 ( V_202 ) -> V_32 =
F_53 ( F_51 ( V_202 ) -> V_32 , V_188 ) ;
V_13 -> V_182 = V_181 ;
}
int F_55 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
struct V_3 * V_13 = F_56 ( V_208 ) ;
struct V_211 * V_212 = & V_13 -> V_213 ;
return F_57 ( V_210 -> V_214 , V_212 , sizeof( * V_212 ) ) ?
- V_215 : 0 ;
}
static int F_58 ( struct V_3 * V_13 ,
struct V_211 * V_212 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_216 = V_217 ;
T_3 V_218 = V_219 ;
T_3 V_220 = 0 ;
bool V_221 = false ;
bool V_222 = false ;
T_3 V_187 ;
if ( V_212 -> V_23 )
return - V_134 ;
switch ( V_212 -> V_223 ) {
case V_224 :
V_216 = 0 ;
case V_225 :
break;
default:
return - V_226 ;
}
switch ( V_212 -> V_227 ) {
case V_228 :
V_218 = 0 ;
break;
case V_229 :
V_218 |= V_230 ;
V_220 = V_231 ;
V_221 = true ;
break;
case V_232 :
V_218 |= V_230 ;
V_220 = V_233 ;
V_221 = true ;
break;
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
V_218 |= V_243 ;
V_212 -> V_227 = V_234 ;
V_222 = true ;
V_221 = true ;
break;
case V_244 :
case V_245 :
if ( V_6 -> V_25 . type != V_26 ) {
V_218 |= V_246 ;
V_212 -> V_227 = V_245 ;
break;
}
default:
V_212 -> V_227 = V_228 ;
return - V_226 ;
}
if ( V_6 -> V_25 . type == V_247 ) {
if ( V_218 | V_216 )
return - V_134 ;
return 0 ;
}
if ( ( V_6 -> V_25 . type >= V_27 ) && V_218 ) {
V_218 = V_219 ;
V_218 |= V_246 ;
V_212 -> V_227 = V_245 ;
V_222 = true ;
V_221 = true ;
if ( ( V_6 -> V_25 . type == V_33 ) ||
( V_6 -> V_25 . type == V_34 ) ) {
V_187 = F_3 ( V_248 ) ;
V_187 |= V_249 ;
F_7 ( V_248 , V_187 ) ;
}
}
V_187 = F_3 ( V_171 ) ;
V_187 &= ~ V_217 ;
V_187 |= V_216 ;
F_7 ( V_171 , V_187 ) ;
V_187 = F_3 ( V_177 ) ;
V_187 &= ~ ( V_219 | V_250 ) ;
V_187 |= V_218 ;
F_7 ( V_177 , V_187 ) ;
F_7 ( V_251 , V_220 ) ;
if ( V_222 )
F_7 ( F_59 ( V_252 ) ,
( V_253 |
V_254 |
V_255 ) ) ;
else
F_7 ( F_59 ( V_252 ) , 0 ) ;
if ( V_221 ) {
T_3 V_256 = ( V_257
| V_258
| V_259
| V_260 ) ;
V_256 &= ~ V_261 ;
F_7 ( F_60 ( 3 ) , F_61 ( V_262 ) ) ;
F_7 ( F_62 ( 3 ) ,
( V_263 | V_264 ) ) ;
if ( V_6 -> V_25 . type == V_26 ) {
F_7 ( F_63 ( 3 ) , F_61 ( V_262 ) ) ;
V_256 &= ~ V_265 ;
}
F_7 ( F_64 ( 3 ) , V_256 ) ;
} else {
F_7 ( F_64 ( 3 ) , V_260 ) ;
}
F_65 () ;
V_187 = F_3 ( V_189 ) ;
V_187 = F_3 ( V_190 ) ;
V_187 = F_3 ( V_206 ) ;
V_187 = F_3 ( V_184 ) ;
return 0 ;
}
int F_66 ( struct V_207 * V_208 , struct V_209 * V_210 )
{
struct V_3 * V_13 = F_56 ( V_208 ) ;
struct V_211 V_212 ;
int V_266 ;
if ( F_67 ( & V_212 , V_210 -> V_214 , sizeof( V_212 ) ) )
return - V_215 ;
V_266 = F_58 ( V_13 , & V_212 ) ;
if ( V_266 )
return V_266 ;
memcpy ( & V_13 -> V_213 , & V_212 ,
sizeof( V_13 -> V_213 ) ) ;
return F_57 ( V_210 -> V_214 , & V_212 , sizeof( V_212 ) ) ?
- V_215 : 0 ;
}
void F_68 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_207 * V_208 = V_13 -> V_208 ;
int V_149 ;
switch ( V_6 -> V_25 . type ) {
case V_26 :
snprintf ( V_13 -> V_38 . V_267 , 16 , L_4 , V_208 -> V_268 ) ;
V_13 -> V_38 . V_269 = V_270 ;
V_13 -> V_38 . V_271 = 999999881 ;
V_13 -> V_38 . V_272 = 0 ;
V_13 -> V_38 . V_273 = 0 ;
V_13 -> V_38 . V_274 = F_14 ;
V_13 -> V_38 . V_275 = F_17 ;
V_13 -> V_38 . V_174 = F_22 ;
V_13 -> V_38 . V_276 = F_25 ;
V_13 -> V_38 . V_277 = F_34 ;
V_13 -> V_2 . V_278 = F_1 ;
V_13 -> V_2 . V_57 = F_69 ( 64 ) ;
V_13 -> V_2 . V_279 = 1 ;
V_13 -> V_2 . V_280 = V_42 ;
V_13 -> V_281 |= V_282 ;
break;
case V_27 :
case V_28 :
case V_29 :
snprintf ( V_13 -> V_38 . V_267 , 16 , L_4 , V_208 -> V_268 ) ;
V_13 -> V_38 . V_269 = V_270 ;
V_13 -> V_38 . V_271 = 62499999 ;
V_13 -> V_38 . V_272 = 0 ;
V_13 -> V_38 . V_273 = 0 ;
V_13 -> V_38 . V_274 = F_16 ;
V_13 -> V_38 . V_275 = F_17 ;
V_13 -> V_38 . V_174 = F_22 ;
V_13 -> V_38 . V_276 = F_25 ;
V_13 -> V_38 . V_277 = F_34 ;
V_13 -> V_2 . V_278 = F_4 ;
V_13 -> V_2 . V_57 = F_69 ( V_283 ) ;
V_13 -> V_2 . V_279 = 1 ;
V_13 -> V_2 . V_280 = 0 ;
V_13 -> V_281 |= V_282 ;
break;
case V_33 :
case V_34 :
for ( V_149 = 0 ; V_149 < V_58 ; V_149 ++ ) {
struct V_284 * V_285 = & V_13 -> V_286 [ V_149 ] ;
snprintf ( V_285 -> V_267 , sizeof( V_285 -> V_267 ) , L_5 , V_149 ) ;
V_285 -> V_122 = V_149 ;
V_285 -> V_156 = V_157 ;
}
snprintf ( V_13 -> V_38 . V_267 , 16 , L_4 , V_208 -> V_268 ) ;
V_13 -> V_38 . V_269 = V_270 ;
V_13 -> V_38 . V_271 = 62499999 ;
V_13 -> V_38 . V_272 = V_287 ;
V_13 -> V_38 . V_288 = V_289 ;
V_13 -> V_38 . V_290 = V_58 ;
V_13 -> V_38 . V_273 = 1 ;
V_13 -> V_38 . V_291 = V_13 -> V_286 ;
V_13 -> V_38 . V_274 = F_16 ;
V_13 -> V_38 . V_275 = F_19 ;
V_13 -> V_38 . V_174 = F_24 ;
V_13 -> V_38 . V_276 = F_28 ;
V_13 -> V_38 . V_277 = F_32 ;
V_13 -> V_38 . V_292 = F_35 ;
break;
default:
V_13 -> V_119 = NULL ;
return;
}
F_70 ( & V_13 -> V_30 ) ;
F_71 ( & V_13 -> V_161 , F_36 ) ;
if ( V_13 -> V_281 & V_282 )
F_72 ( & V_13 -> V_173 ,
F_43 ) ;
V_13 -> V_213 . V_227 = V_228 ;
V_13 -> V_213 . V_223 = V_224 ;
F_73 ( V_13 ) ;
V_13 -> V_119 = F_74 ( & V_13 -> V_38 ,
& V_13 -> V_169 -> V_170 ) ;
if ( F_75 ( V_13 -> V_119 ) ) {
V_13 -> V_119 = NULL ;
F_76 ( & V_13 -> V_169 -> V_170 , L_6 ) ;
} else if ( V_13 -> V_119 ) {
F_77 ( & V_13 -> V_169 -> V_170 , L_7 ,
V_13 -> V_208 -> V_267 ) ;
V_13 -> V_281 |= V_293 ;
}
}
void F_78 ( struct V_3 * V_13 )
{
if ( ! ( V_13 -> V_281 & V_293 ) )
return;
if ( V_13 -> V_281 & V_282 )
F_79 ( & V_13 -> V_173 ) ;
F_80 ( & V_13 -> V_161 ) ;
if ( V_13 -> V_163 ) {
F_38 ( V_13 -> V_163 ) ;
V_13 -> V_163 = NULL ;
F_39 ( V_166 , & V_13 -> V_167 ) ;
}
}
void F_81 ( struct V_3 * V_13 )
{
F_78 ( V_13 ) ;
if ( V_13 -> V_119 ) {
F_82 ( V_13 -> V_119 ) ;
F_77 ( & V_13 -> V_169 -> V_170 , L_8 ,
V_13 -> V_208 -> V_267 ) ;
V_13 -> V_281 &= ~ V_293 ;
}
}
void F_73 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
unsigned long V_23 ;
F_58 ( V_13 , & V_13 -> V_213 ) ;
F_9 ( & V_13 -> V_30 , V_23 ) ;
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
F_7 ( V_43 , V_44 | V_294 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_33 :
case V_34 :
F_7 ( V_128 , 0x0 ) ;
F_7 ( V_82 , 0x0 ) ;
F_7 ( V_129 ,
V_295 |
( V_13 -> V_153 ? V_152 : 0 ) ) ;
F_7 ( V_296 , V_297 ) ;
break;
default:
goto V_298;
}
if ( ( V_6 -> V_25 . type == V_33 ) || ( V_6 -> V_25 . type == V_34 ) ) {
struct V_14 V_15 = F_83 ( F_84 () ) ;
F_6 ( V_13 , & V_15 ) ;
} else {
F_27 ( & V_13 -> V_31 , & V_13 -> V_2 ,
F_85 ( F_84 () ) ) ;
}
V_298:
F_11 ( & V_13 -> V_30 , V_23 ) ;
F_65 () ;
if ( V_13 -> V_281 & V_282 )
F_45 ( & V_13 -> V_173 ,
V_175 ) ;
}
