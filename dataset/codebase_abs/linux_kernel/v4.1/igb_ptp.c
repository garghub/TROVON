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
F_7 ( V_11 , V_15 -> V_18 ) ;
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
static void F_31 ( struct V_3 * V_4 , int V_63 , int V_52 )
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
static const T_3 V_85 [ V_58 ] = {
V_86 , V_87 ,
V_88 , V_89 ,
} ;
static const T_3 V_90 [ V_58 ] = {
V_91 , V_92 ,
V_93 , V_94 ,
} ;
static const T_3 V_95 [ V_58 ] = {
V_96 , V_97 ,
V_98 , V_99 ,
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
V_79 &= ~ V_95 [ V_52 ] ;
if ( V_63 == 1 )
V_79 |= V_90 [ V_52 ] ;
else
V_79 |= V_85 [ V_52 ] ;
V_79 |= V_74 [ V_52 ] ;
F_7 ( V_82 , V_79 ) ;
F_7 ( V_80 , V_54 ) ;
F_7 ( V_81 , V_55 ) ;
}
static int F_32 ( struct V_35 * V_36 ,
struct V_100 * V_101 , int V_102 )
{
struct V_3 * V_4 =
F_2 ( V_36 , struct V_3 , V_38 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_3 V_103 , V_104 , V_105 , V_106 , V_107 , V_108 ;
unsigned long V_23 ;
struct V_109 V_15 ;
int V_52 = - 1 ;
T_5 V_24 ;
switch ( V_101 -> type ) {
case V_110 :
if ( V_102 ) {
V_52 = F_33 ( V_4 -> V_111 , V_112 ,
V_101 -> V_113 . V_114 ) ;
if ( V_52 < 0 )
return - V_115 ;
}
if ( V_101 -> V_113 . V_114 == 1 ) {
V_105 = V_116 ;
V_106 = V_117 ;
} else {
V_105 = V_118 ;
V_106 = V_119 ;
}
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_103 = F_3 ( V_120 ) ;
V_104 = F_3 ( V_121 ) ;
if ( V_102 ) {
F_30 ( V_4 , V_101 -> V_113 . V_114 , V_52 ) ;
V_103 |= V_105 ;
V_104 |= V_106 ;
} else {
V_103 &= ~ V_105 ;
V_104 &= ~ V_106 ;
}
F_7 ( V_120 , V_103 ) ;
F_7 ( V_121 , V_104 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
case V_122 :
if ( V_102 ) {
V_52 = F_33 ( V_4 -> V_111 , V_123 ,
V_101 -> V_124 . V_114 ) ;
if ( V_52 < 0 )
return - V_115 ;
}
V_15 . V_18 = V_101 -> V_124 . V_125 . V_16 ;
V_15 . V_19 = V_101 -> V_124 . V_125 . V_17 ;
V_24 = F_34 ( & V_15 ) ;
V_24 = V_24 >> 1 ;
if ( V_102 && V_24 < 500000LL ) {
return - V_126 ;
}
V_15 = F_35 ( V_24 ) ;
if ( V_101 -> V_124 . V_114 == 1 ) {
V_105 = V_127 ;
V_106 = V_128 ;
V_107 = V_129 ;
V_108 = V_130 ;
} else {
V_105 = V_131 ;
V_106 = V_132 ;
V_107 = V_133 ;
V_108 = V_134 ;
}
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_103 = F_3 ( V_120 ) ;
V_104 = F_3 ( V_121 ) ;
if ( V_102 ) {
int V_135 = V_101 -> V_124 . V_114 ;
F_31 ( V_4 , V_135 , V_52 ) ;
V_4 -> V_124 [ V_135 ] . V_136 . V_18 = V_101 -> V_124 . V_136 . V_16 ;
V_4 -> V_124 [ V_135 ] . V_136 . V_19 = V_101 -> V_124 . V_136 . V_17 ;
V_4 -> V_124 [ V_135 ] . V_125 . V_18 = V_15 . V_18 ;
V_4 -> V_124 [ V_135 ] . V_125 . V_19 = V_15 . V_19 ;
F_7 ( V_108 , V_101 -> V_124 . V_136 . V_16 ) ;
F_7 ( V_107 , V_101 -> V_124 . V_136 . V_17 ) ;
V_103 |= V_105 ;
V_104 |= V_106 ;
} else {
V_103 &= ~ V_105 ;
V_104 &= ~ V_106 ;
}
F_7 ( V_120 , V_103 ) ;
F_7 ( V_121 , V_104 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
case V_137 :
F_9 ( & V_4 -> V_30 , V_23 ) ;
V_104 = F_3 ( V_121 ) ;
if ( V_102 )
V_104 |= V_138 ;
else
V_104 &= ~ V_138 ;
F_7 ( V_121 , V_104 ) ;
F_11 ( & V_4 -> V_30 , V_23 ) ;
return 0 ;
}
return - V_139 ;
}
static int F_36 ( struct V_35 * V_36 ,
struct V_100 * V_101 , int V_102 )
{
return - V_139 ;
}
static int F_37 ( struct V_35 * V_36 , unsigned int V_52 ,
enum V_140 V_141 , unsigned int V_63 )
{
switch ( V_141 ) {
case V_142 :
case V_112 :
case V_123 :
break;
case V_143 :
return - 1 ;
}
return 0 ;
}
static void F_38 ( struct V_144 * V_145 )
{
struct V_3 * V_13 = F_2 ( V_145 , struct V_3 ,
V_146 ) ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_147 ;
if ( ! V_13 -> V_148 )
return;
if ( F_39 ( V_13 -> V_149 +
V_150 ) ) {
F_40 ( V_13 -> V_148 ) ;
V_13 -> V_148 = NULL ;
F_41 ( V_151 , & V_13 -> V_152 ) ;
V_13 -> V_153 ++ ;
F_42 ( & V_13 -> V_154 -> V_155 , L_1 ) ;
return;
}
V_147 = F_3 ( V_156 ) ;
if ( V_147 & V_157 )
F_43 ( V_13 ) ;
else
F_44 ( & V_13 -> V_146 ) ;
}
static void F_45 ( struct V_144 * V_145 )
{
struct V_3 * V_4 =
F_2 ( V_145 , struct V_3 , V_158 . V_145 ) ;
struct V_14 V_15 ;
V_4 -> V_38 . V_159 ( & V_4 -> V_38 , & V_15 ) ;
F_46 ( L_2 ,
( long long ) V_15 . V_18 , V_15 . V_19 ) ;
F_47 ( & V_4 -> V_158 ,
V_160 ) ;
}
void F_48 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_161 = F_3 ( V_162 ) ;
unsigned long V_163 ;
if ( V_6 -> V_25 . type != V_26 )
return;
if ( ! ( V_161 & V_164 ) ) {
V_13 -> V_165 = V_166 ;
return;
}
V_163 = V_13 -> V_165 ;
if ( F_49 ( V_13 -> V_167 , V_163 ) )
V_163 = V_13 -> V_167 ;
if ( F_39 ( V_163 + 5 * V_168 ) ) {
F_3 ( V_169 ) ;
V_13 -> V_165 = V_166 ;
V_13 -> V_170 ++ ;
F_42 ( & V_13 -> V_154 -> V_155 , L_3 ) ;
}
}
static void F_43 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_20 V_171 ;
T_2 V_172 ;
V_172 = F_3 ( V_173 ) ;
V_172 |= ( T_2 ) F_3 ( V_174 ) << 32 ;
F_8 ( V_13 , & V_171 , V_172 ) ;
F_50 ( V_13 -> V_148 , & V_171 ) ;
F_40 ( V_13 -> V_148 ) ;
V_13 -> V_148 = NULL ;
F_41 ( V_151 , & V_13 -> V_152 ) ;
}
void F_51 ( struct V_175 * V_176 ,
unsigned char * V_177 ,
struct V_178 * V_179 )
{
T_6 * V_172 = ( T_6 * ) V_177 ;
F_8 ( V_176 -> V_13 , F_52 ( V_179 ) ,
F_53 ( V_172 [ 1 ] ) ) ;
}
void F_54 ( struct V_175 * V_176 ,
struct V_178 * V_179 )
{
struct V_3 * V_13 = V_176 -> V_13 ;
struct V_5 * V_6 = & V_13 -> V_6 ;
T_2 V_172 ;
if ( ! ( F_3 ( V_162 ) & V_164 ) )
return;
V_172 = F_3 ( V_180 ) ;
V_172 |= ( T_2 ) F_3 ( V_169 ) << 32 ;
F_8 ( V_13 , F_52 ( V_179 ) , V_172 ) ;
V_13 -> V_167 = V_166 ;
}
int F_55 ( struct V_181 * V_182 , struct V_183 * V_184 )
{
struct V_3 * V_13 = F_56 ( V_182 ) ;
struct V_185 * V_186 = & V_13 -> V_187 ;
return F_57 ( V_184 -> V_188 , V_186 , sizeof( * V_186 ) ) ?
- V_189 : 0 ;
}
static int F_58 ( struct V_3 * V_13 ,
struct V_185 * V_186 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
T_3 V_190 = V_191 ;
T_3 V_192 = V_193 ;
T_3 V_194 = 0 ;
bool V_195 = false ;
bool V_196 = false ;
T_3 V_172 ;
if ( V_186 -> V_23 )
return - V_126 ;
switch ( V_186 -> V_197 ) {
case V_198 :
V_190 = 0 ;
case V_199 :
break;
default:
return - V_200 ;
}
switch ( V_186 -> V_201 ) {
case V_202 :
V_192 = 0 ;
break;
case V_203 :
V_192 |= V_204 ;
V_194 = V_205 ;
V_195 = true ;
break;
case V_206 :
V_192 |= V_204 ;
V_194 = V_207 ;
V_195 = true ;
break;
case V_208 :
case V_209 :
case V_210 :
case V_211 :
case V_212 :
case V_213 :
case V_214 :
case V_215 :
case V_216 :
V_192 |= V_217 ;
V_186 -> V_201 = V_208 ;
V_196 = true ;
V_195 = true ;
break;
case V_218 :
case V_219 :
if ( V_6 -> V_25 . type != V_26 ) {
V_192 |= V_220 ;
V_186 -> V_201 = V_219 ;
break;
}
default:
V_186 -> V_201 = V_202 ;
return - V_200 ;
}
if ( V_6 -> V_25 . type == V_221 ) {
if ( V_192 | V_190 )
return - V_126 ;
return 0 ;
}
if ( ( V_6 -> V_25 . type >= V_27 ) && V_192 ) {
V_192 = V_193 ;
V_192 |= V_220 ;
V_186 -> V_201 = V_219 ;
V_196 = true ;
V_195 = true ;
if ( ( V_6 -> V_25 . type == V_33 ) ||
( V_6 -> V_25 . type == V_34 ) ) {
V_172 = F_3 ( V_222 ) ;
V_172 |= V_223 ;
F_7 ( V_222 , V_172 ) ;
}
}
V_172 = F_3 ( V_156 ) ;
V_172 &= ~ V_191 ;
V_172 |= V_190 ;
F_7 ( V_156 , V_172 ) ;
V_172 = F_3 ( V_162 ) ;
V_172 &= ~ ( V_193 | V_224 ) ;
V_172 |= V_192 ;
F_7 ( V_162 , V_172 ) ;
F_7 ( V_225 , V_194 ) ;
if ( V_196 )
F_7 ( F_59 ( 3 ) ,
( V_226 |
V_227 |
V_228 ) ) ;
else
F_7 ( F_59 ( 3 ) , 0 ) ;
if ( V_195 ) {
T_3 V_229 = ( V_230
| V_231
| V_232
| V_233 ) ;
V_229 &= ~ V_234 ;
F_7 ( F_60 ( 3 ) , F_61 ( V_235 ) ) ;
F_7 ( F_62 ( 3 ) ,
( V_236 | V_237 ) ) ;
if ( V_6 -> V_25 . type == V_26 ) {
F_7 ( F_63 ( 3 ) , F_61 ( V_235 ) ) ;
V_229 &= ~ V_238 ;
}
F_7 ( F_64 ( 3 ) , V_229 ) ;
} else {
F_7 ( F_64 ( 3 ) , V_233 ) ;
}
F_65 () ;
V_172 = F_3 ( V_173 ) ;
V_172 = F_3 ( V_174 ) ;
V_172 = F_3 ( V_180 ) ;
V_172 = F_3 ( V_169 ) ;
return 0 ;
}
int F_66 ( struct V_181 * V_182 , struct V_183 * V_184 )
{
struct V_3 * V_13 = F_56 ( V_182 ) ;
struct V_185 V_186 ;
int V_239 ;
if ( F_67 ( & V_186 , V_184 -> V_188 , sizeof( V_186 ) ) )
return - V_189 ;
V_239 = F_58 ( V_13 , & V_186 ) ;
if ( V_239 )
return V_239 ;
memcpy ( & V_13 -> V_187 , & V_186 ,
sizeof( V_13 -> V_187 ) ) ;
return F_57 ( V_184 -> V_188 , & V_186 , sizeof( V_186 ) ) ?
- V_189 : 0 ;
}
void F_68 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
struct V_181 * V_182 = V_13 -> V_182 ;
int V_135 ;
switch ( V_6 -> V_25 . type ) {
case V_26 :
snprintf ( V_13 -> V_38 . V_240 , 16 , L_4 , V_182 -> V_241 ) ;
V_13 -> V_38 . V_242 = V_243 ;
V_13 -> V_38 . V_244 = 999999881 ;
V_13 -> V_38 . V_245 = 0 ;
V_13 -> V_38 . V_246 = 0 ;
V_13 -> V_38 . V_247 = F_14 ;
V_13 -> V_38 . V_248 = F_17 ;
V_13 -> V_38 . V_159 = F_22 ;
V_13 -> V_38 . V_249 = F_25 ;
V_13 -> V_38 . V_250 = F_36 ;
V_13 -> V_2 . V_251 = F_1 ;
V_13 -> V_2 . V_57 = F_69 ( 64 ) ;
V_13 -> V_2 . V_252 = 1 ;
V_13 -> V_2 . V_253 = V_42 ;
F_7 ( V_43 , V_44 | V_254 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
snprintf ( V_13 -> V_38 . V_240 , 16 , L_4 , V_182 -> V_241 ) ;
V_13 -> V_38 . V_242 = V_243 ;
V_13 -> V_38 . V_244 = 62499999 ;
V_13 -> V_38 . V_245 = 0 ;
V_13 -> V_38 . V_246 = 0 ;
V_13 -> V_38 . V_247 = F_16 ;
V_13 -> V_38 . V_248 = F_17 ;
V_13 -> V_38 . V_159 = F_22 ;
V_13 -> V_38 . V_249 = F_25 ;
V_13 -> V_38 . V_250 = F_36 ;
V_13 -> V_2 . V_251 = F_4 ;
V_13 -> V_2 . V_57 = F_69 ( V_255 ) ;
V_13 -> V_2 . V_252 = 1 ;
V_13 -> V_2 . V_253 = 0 ;
F_7 ( V_120 , 0x0 ) ;
break;
case V_33 :
case V_34 :
for ( V_135 = 0 ; V_135 < V_58 ; V_135 ++ ) {
struct V_256 * V_257 = & V_13 -> V_258 [ V_135 ] ;
snprintf ( V_257 -> V_240 , sizeof( V_257 -> V_240 ) , L_5 , V_135 ) ;
V_257 -> V_114 = V_135 ;
V_257 -> V_141 = V_142 ;
}
snprintf ( V_13 -> V_38 . V_240 , 16 , L_4 , V_182 -> V_241 ) ;
V_13 -> V_38 . V_242 = V_243 ;
V_13 -> V_38 . V_244 = 62499999 ;
V_13 -> V_38 . V_245 = V_259 ;
V_13 -> V_38 . V_260 = V_261 ;
V_13 -> V_38 . V_262 = V_58 ;
V_13 -> V_38 . V_246 = 1 ;
V_13 -> V_38 . V_263 = V_13 -> V_258 ;
V_13 -> V_38 . V_247 = F_16 ;
V_13 -> V_38 . V_248 = F_19 ;
V_13 -> V_38 . V_159 = F_24 ;
V_13 -> V_38 . V_249 = F_28 ;
V_13 -> V_38 . V_250 = F_32 ;
V_13 -> V_38 . V_264 = F_37 ;
F_7 ( V_120 , 0x0 ) ;
break;
default:
V_13 -> V_111 = NULL ;
return;
}
F_65 () ;
F_70 ( & V_13 -> V_30 ) ;
F_71 ( & V_13 -> V_146 , F_38 ) ;
if ( ( V_6 -> V_25 . type == V_33 ) || ( V_6 -> V_25 . type == V_34 ) ) {
struct V_14 V_15 = F_72 ( F_73 () ) ;
F_28 ( & V_13 -> V_38 , & V_15 ) ;
} else {
F_27 ( & V_13 -> V_31 , & V_13 -> V_2 ,
F_74 ( F_73 () ) ) ;
F_75 ( & V_13 -> V_158 ,
F_45 ) ;
F_47 ( & V_13 -> V_158 ,
V_160 ) ;
}
if ( V_6 -> V_25 . type >= V_27 ) {
F_7 ( V_121 , V_265 ) ;
F_7 ( V_266 , V_267 ) ;
}
V_13 -> V_187 . V_201 = V_202 ;
V_13 -> V_187 . V_197 = V_198 ;
V_13 -> V_111 = F_76 ( & V_13 -> V_38 ,
& V_13 -> V_154 -> V_155 ) ;
if ( F_77 ( V_13 -> V_111 ) ) {
V_13 -> V_111 = NULL ;
F_78 ( & V_13 -> V_154 -> V_155 , L_6 ) ;
} else {
F_79 ( & V_13 -> V_154 -> V_155 , L_7 ,
V_13 -> V_182 -> V_240 ) ;
V_13 -> V_23 |= V_268 ;
}
}
void F_80 ( struct V_3 * V_13 )
{
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
case V_27 :
case V_28 :
case V_29 :
F_81 ( & V_13 -> V_158 ) ;
break;
case V_33 :
case V_34 :
break;
default:
return;
}
F_82 ( & V_13 -> V_146 ) ;
if ( V_13 -> V_148 ) {
F_40 ( V_13 -> V_148 ) ;
V_13 -> V_148 = NULL ;
F_41 ( V_151 , & V_13 -> V_152 ) ;
}
if ( V_13 -> V_111 ) {
F_83 ( V_13 -> V_111 ) ;
F_79 ( & V_13 -> V_154 -> V_155 , L_8 ,
V_13 -> V_182 -> V_240 ) ;
V_13 -> V_23 &= ~ V_268 ;
}
}
void F_84 ( struct V_3 * V_13 )
{
struct V_5 * V_6 = & V_13 -> V_6 ;
unsigned long V_23 ;
if ( ! ( V_13 -> V_23 & V_268 ) )
return;
F_58 ( V_13 , & V_13 -> V_187 ) ;
F_9 ( & V_13 -> V_30 , V_23 ) ;
switch ( V_13 -> V_6 . V_25 . type ) {
case V_26 :
F_7 ( V_43 , V_44 | V_254 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
case V_33 :
case V_34 :
F_7 ( V_120 , 0x0 ) ;
F_7 ( V_82 , 0x0 ) ;
F_7 ( V_121 , V_265 ) ;
F_7 ( V_266 , V_267 ) ;
break;
default:
goto V_269;
}
if ( ( V_6 -> V_25 . type == V_33 ) || ( V_6 -> V_25 . type == V_34 ) ) {
struct V_14 V_15 = F_72 ( F_73 () ) ;
F_6 ( V_13 , & V_15 ) ;
} else {
F_27 ( & V_13 -> V_31 , & V_13 -> V_2 ,
F_74 ( F_73 () ) ) ;
}
V_269:
F_11 ( & V_13 -> V_30 , V_23 ) ;
}
