static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return false ;
default:
return true ;
}
}
static bool F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_8 :
case V_9 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
return true ;
default:
return false ;
}
}
static int F_4 ( struct V_47 * V_48 ,
struct V_49 * V_50 , int V_51 )
{
struct V_52 * V_53 = F_5 ( V_48 -> V_54 ) ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
switch ( V_51 ) {
case V_57 :
if ( ! V_56 -> V_58 ) {
F_7 ( 8000 , 9000 ) ;
V_56 -> V_58 = true ;
F_8 ( V_56 -> V_59 , V_22 ,
V_60 , 0 ) ;
F_9 ( V_53 -> V_2 , L_1 ) ;
}
F_9 ( V_53 -> V_2 , L_2 ) ;
break;
case V_61 :
F_9 ( V_53 -> V_2 , L_3 ) ;
break;
default:
F_10 ( V_53 -> V_2 , L_4 , V_51 ) ;
break;
}
return 0 ;
}
static int F_11 ( struct V_47 * V_48 ,
struct V_49 * V_50 , int V_51 )
{
struct V_52 * V_53 = F_5 ( V_48 -> V_54 ) ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
unsigned int V_62 ;
switch ( V_51 ) {
case V_63 :
F_8 ( V_56 -> V_59 , V_11 ,
V_64 , 0 ) ;
V_62 = V_56 -> V_65 ? 0 : V_66 ;
F_8 ( V_56 -> V_59 , V_12 ,
V_66 , V_62 ) ;
F_9 ( V_53 -> V_2 , L_5 ) ;
break;
case V_57 :
F_9 ( V_53 -> V_2 , L_6 ) ;
if ( ! V_56 -> V_58 ) {
F_8 ( V_56 -> V_59 , V_22 ,
V_60 , V_60 ) ;
F_9 ( V_53 -> V_2 , L_7 ) ;
F_7 ( 10000 , 11000 ) ;
}
break;
case V_61 :
F_8 ( V_56 -> V_59 , V_12 ,
V_66 , V_66 ) ;
F_7 ( 4000 , 4100 ) ;
F_8 ( V_56 -> V_59 , V_11 ,
V_64 , V_64 ) ;
F_9 ( V_53 -> V_2 , L_8 ) ;
break;
default:
F_10 ( V_53 -> V_2 , L_4 , V_51 ) ;
}
return 0 ;
}
static int F_12 ( struct V_47 * V_48 ,
struct V_49 * V_50 , int V_51 )
{
struct V_52 * V_53 = F_5 ( V_48 -> V_54 ) ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
unsigned int V_67 = V_68 | V_66 ;
unsigned int V_69 = V_70 ;
unsigned int V_62 , V_71 ;
switch ( V_51 ) {
case V_63 :
if ( V_56 -> V_65 ) {
V_62 = V_68 ;
V_71 = 0 ;
} else {
V_62 = V_66 ;
V_71 = V_70 ;
}
F_9 ( V_53 -> V_2 , L_9 ) ;
break;
case V_72 :
V_62 = V_68 | V_66 ;
V_71 = V_70 ;
F_9 ( V_53 -> V_2 , L_10 ) ;
break;
default:
F_10 ( V_53 -> V_2 , L_4 , V_51 ) ;
return 0 ;
}
F_8 ( V_56 -> V_59 , V_12 ,
V_67 , V_62 ) ;
F_8 ( V_56 -> V_59 , V_13 ,
V_69 , V_71 ) ;
return 0 ;
}
static int F_13 ( struct V_52 * V_53 ,
enum V_73 V_74 )
{
unsigned int V_62 ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
switch ( V_74 ) {
case V_75 :
break;
case V_76 :
F_8 ( V_56 -> V_59 , V_11 ,
V_77 , 0 ) ;
F_8 ( V_56 -> V_59 , V_13 ,
V_78 , 0 ) ;
break;
case V_79 :
F_8 ( V_56 -> V_59 , V_11 ,
V_77 , V_77 ) ;
F_14 ( V_56 -> V_59 , V_9 , & V_62 ) ;
F_7 ( 1000 , 1100 ) ;
if ( V_62 & V_80 )
F_8 ( V_56 -> V_59 , V_13 ,
V_78 , V_78 ) ;
break;
case V_81 :
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_15 ( int V_83 , int V_84 )
{
int V_85 ;
for ( V_85 = 0 ; V_85 < F_16 ( V_86 ) ; V_85 ++ ) {
if ( V_86 [ V_85 ] . V_83 == V_83 &&
V_86 [ V_85 ] . V_84 == V_84 )
return V_85 ;
}
return - V_82 ;
}
static int F_17 ( struct V_87 * V_88 , unsigned int V_89 )
{
struct V_52 * V_53 = V_88 -> V_53 ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
switch ( V_89 & V_90 ) {
case V_91 :
F_8 ( V_56 -> V_59 , V_18 ,
V_92 , V_92 ) ;
F_9 ( V_53 -> V_2 , L_11 ) ;
break;
case V_93 :
F_8 ( V_56 -> V_59 , V_18 ,
V_92 , 0 ) ;
F_9 ( V_53 -> V_2 , L_12 ) ;
break;
default:
return - V_82 ;
}
switch ( V_89 & V_94 ) {
case V_95 :
V_56 -> V_65 = true ;
F_9 ( V_53 -> V_2 , L_13 ) ;
break;
case V_96 :
V_56 -> V_65 = false ;
F_9 ( V_53 -> V_2 , L_14 ) ;
break;
default:
return - V_82 ;
}
return 0 ;
}
static int F_18 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
struct V_87 * V_101 )
{
struct V_52 * V_53 = V_101 -> V_53 ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
int V_102 = F_19 ( V_100 ) ;
int V_103 = F_15 ( V_56 -> V_104 , F_20 ( V_100 ) ) ;
if ( V_103 < 0 )
return V_103 ;
F_8 ( V_56 -> V_59 , V_13 ,
V_105 | V_106 ,
V_86 [ V_103 ] . V_107
| V_86 [ V_103 ] . V_108 ) ;
if ( V_56 -> V_65 ) {
V_102 = ( V_102 / 8 ) - 1 ;
if ( V_102 > 2 )
V_102 = 2 ;
F_8 ( V_56 -> V_59 , V_43 ,
V_109 ,
V_102 << V_110 ) ;
}
F_9 ( V_53 -> V_2 , L_15 ,
F_20 ( V_100 ) , F_19 ( V_100 ) ) ;
return 0 ;
}
static int F_21 ( struct V_97 * V_98 ,
struct V_87 * V_101 )
{
F_22 ( V_98 -> V_111 , 0 ,
V_112 ,
& V_113 ) ;
return 0 ;
}
static int F_23 ( struct V_87 * V_101 , int V_114 )
{
struct V_52 * V_53 = V_101 -> V_53 ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
if ( V_114 ) {
F_8 ( V_56 -> V_59 , V_12 ,
V_68 , V_68 ) ;
F_8 ( V_56 -> V_59 , V_13 ,
V_70 , V_70 ) ;
} else {
F_8 ( V_56 -> V_59 , V_12 ,
V_68 , 0 ) ;
F_8 ( V_56 -> V_59 , V_13 ,
V_70 , 0 ) ;
}
return 0 ;
}
static int F_24 ( struct V_87 * V_101 , unsigned int V_115 ,
unsigned int V_116 , int V_117 , int V_118 )
{
struct V_52 * V_53 = V_101 -> V_53 ;
struct V_119 * V_54 = F_25 ( V_53 ) ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
unsigned int V_3 , V_120 , V_85 ;
int V_121 , V_122 ;
if ( V_118 != 8 )
return - V_82 ;
V_121 = F_26 ( V_116 ) - 1 ;
if ( V_121 >= 0 ) {
F_8 ( V_56 -> V_59 , V_43 ,
V_123 , V_121 ) ;
F_9 ( V_53 -> V_2 , L_16 , V_121 ) ;
}
V_121 = F_26 ( V_115 ) - 1 ;
V_122 = 0 ;
for ( V_85 = 0 ; V_85 < 2 ; V_85 ++ ) {
F_8 ( V_56 -> V_59 , V_36 + V_85 ,
V_124 | V_123 , V_124
| V_123 ) ;
}
F_27 ( V_54 , V_125 ,
F_16 ( V_125 ) ) ;
while ( V_121 >= 0 ) {
if ( V_122 == 0 ) {
F_8 ( V_56 -> V_59 , V_34 ,
V_124 | V_123 , V_121 ) ;
F_9 ( V_53 -> V_2 , L_17 ,
V_121 , V_121 + 1 ) ;
}
if ( V_122 == 3 ) {
F_8 ( V_56 -> V_59 , V_35 ,
V_124 | V_123 , V_121 ) ;
F_9 ( V_53 -> V_2 , L_18 ,
V_121 , V_121 + 1 ) ;
}
if ( V_122 == 4 ) {
F_8 ( V_56 -> V_59 , V_36 ,
V_124 | V_123 , V_121 ) ;
F_28 ( V_54 ,
& V_125 [ 0 ] , 2 ) ;
F_9 ( V_53 -> V_2 , L_19 , V_121 ) ;
}
if ( V_122 == 5 ) {
F_8 ( V_56 -> V_59 , V_37 ,
V_124 | V_123 , V_121 ) ;
F_28 ( V_54 ,
& V_125 [ 2 ] , 2 ) ;
F_9 ( V_53 -> V_2 ,
L_20 , V_121 ) ;
}
V_3 = V_42 - ( V_121 / 8 ) ;
V_120 = V_121 - ( ( V_121 / 8 ) * ( 8 ) ) ;
F_8 ( V_56 -> V_59 , V_3 ,
1 << V_120 , 1 << V_120 ) ;
V_115 &= ~ ( 1 << V_121 ) ;
V_121 = F_26 ( V_115 ) - 1 ;
V_122 ++ ;
}
return 0 ;
}
static int F_29 ( struct V_52 * V_53 ,
int V_126 , int V_127 , unsigned int V_128 , int V_129 )
{
struct V_55 * V_130 = F_6 ( V_53 ) ;
switch ( V_128 ) {
case V_131 :
case V_132 :
case V_133 :
F_8 ( V_130 -> V_59 , V_13 ,
V_134 , 0 ) ;
V_130 -> V_104 = V_128 ;
break;
case V_135 :
case V_136 :
case V_137 :
F_8 ( V_130 -> V_59 , V_13 ,
V_134 , V_134 ) ;
V_130 -> V_104 = V_128 / 2 ;
break;
default:
V_130 -> V_104 = 0 ;
return - V_82 ;
}
F_9 ( V_53 -> V_2 , L_21 ,
V_128 , V_130 -> V_104 ) ;
return 0 ;
}
static int F_30 ( struct V_52 * V_53 ,
struct V_138 * V_139 )
{
struct V_140 * V_141 = & V_139 -> V_141 ;
struct V_119 * V_54 = F_25 ( V_53 ) ;
struct V_55 * V_56 = F_6 ( V_53 ) ;
if ( V_141 -> V_142 ) {
F_8 ( V_56 -> V_59 , V_29 ,
V_143 ,
V_141 -> V_144 << V_145 ) ;
F_31 ( V_56 -> V_59 , V_30 ,
V_141 -> V_146 ) ;
F_8 ( V_56 -> V_59 , V_32 ,
V_147 ,
V_141 -> V_148 << V_149 ) ;
F_8 ( V_56 -> V_59 , V_29 ,
V_150 ,
V_141 -> V_151 << V_152 ) ;
F_8 ( V_56 -> V_59 , V_29 ,
V_153 ,
V_141 -> V_154 <<
V_155 ) ;
F_8 ( V_56 -> V_59 , V_31 ,
V_156 ,
V_141 -> V_157 <<
V_158 ) ;
if ( V_141 -> V_159 ) {
F_8 ( V_56 -> V_59 , V_33 ,
V_160 ,
V_160 ) ;
F_28 ( V_54 , V_161 ,
F_16 ( V_161 ) ) ;
}
F_8 ( V_56 -> V_59 , V_33 ,
V_162 ,
V_141 -> V_163 << V_164 ) ;
F_8 ( V_56 -> V_59 , V_31 ,
V_165 ,
V_141 -> V_166 << V_167 ) ;
F_8 ( V_56 -> V_59 , V_31 ,
V_168 ,
V_141 -> V_169 << V_170 ) ;
F_8 ( V_56 -> V_59 , V_33 ,
V_171 , V_171 ) ;
}
return 0 ;
}
static int F_32 ( struct V_52 * V_53 , unsigned int V_172 )
{
struct V_55 * V_130 = F_6 ( V_53 ) ;
int V_173 = 0 , V_174 = 0 ;
if ( V_172 > 3600000 || V_172 < 1850000 ) {
F_10 ( V_53 -> V_2 , L_22 , V_172 ) ;
V_173 = - V_82 ;
goto V_175;
}
if ( V_172 % 15625 ) {
F_10 ( V_53 -> V_2 , L_23 ,
V_172 ) ;
V_173 = - V_82 ;
goto V_175;
}
while ( V_172 > 1850000 ) {
V_172 -= 15625 ;
V_174 ++ ;
}
F_31 ( V_130 -> V_59 , V_14 ,
V_174 + 0x70 ) ;
V_175:
return V_173 ;
}
static int F_33 ( struct V_52 * V_53 )
{
struct V_55 * V_130 = F_6 ( V_53 ) ;
V_130 -> V_53 = V_53 ;
F_34 ( V_53 -> V_2 ) ;
F_8 ( V_130 -> V_59 , V_15 ,
V_176 , 0x8 ) ;
F_8 ( V_130 -> V_59 , V_17 ,
V_177 ,
V_177 ) ;
F_8 ( V_130 -> V_59 , V_16 ,
V_178 , V_130 -> V_139 . V_179 ) ;
F_8 ( V_130 -> V_59 , V_22 ,
V_180 ,
V_130 -> V_139 . V_181 << V_182 ) ;
if ( V_130 -> V_139 . V_183 )
F_32 ( V_53 , V_130 -> V_139 . V_183 ) ;
if ( V_130 -> V_184 ) {
F_35 ( V_53 , V_20 ,
V_185 , V_185 ) ;
F_35 ( V_53 , V_20 ,
V_186 , V_130 -> V_139 . V_187 ) ;
} else {
F_35 ( V_53 , V_20 ,
V_185 , 0 ) ;
}
if ( V_130 -> V_139 . V_188 != 0x8 )
F_35 ( V_53 , V_19 ,
V_189 , V_130 -> V_139 . V_188 ) ;
F_30 ( V_53 , & ( V_130 -> V_139 ) ) ;
F_8 ( V_130 -> V_59 , V_24 ,
V_190 | V_191 | V_192 |
V_193 , 0 ) ;
F_36 ( V_53 -> V_2 ) ;
return 0 ;
}
static int T_1 F_37 ( struct V_1 * V_2 )
{
struct V_55 * V_130 = F_38 ( V_2 ) ;
int V_173 ;
F_9 ( V_2 , L_24 , V_194 ) ;
F_39 ( V_130 -> V_195 , 0 ) ;
V_173 = F_40 ( V_130 -> V_196 ,
V_130 -> V_197 ) ;
if ( V_173 != 0 ) {
F_10 ( V_2 , L_25 , V_173 ) ;
return V_173 ;
}
F_41 ( V_130 -> V_59 , false ) ;
F_39 ( V_130 -> V_195 , 1 ) ;
F_42 ( V_198 ) ;
V_173 = F_43 ( V_130 -> V_59 ) ;
if ( V_173 != 0 ) {
F_10 ( V_2 , L_26 ) ;
goto V_175;
}
return 0 ;
V_175:
F_41 ( V_130 -> V_59 , true ) ;
F_44 ( V_130 -> V_196 ,
V_130 -> V_197 ) ;
return V_173 ;
}
static int T_1 F_45 ( struct V_1 * V_2 )
{
struct V_55 * V_130 = F_38 ( V_2 ) ;
F_9 ( V_2 , L_24 , V_194 ) ;
V_130 -> V_58 = false ;
F_41 ( V_130 -> V_59 , true ) ;
F_46 ( V_130 -> V_59 ) ;
F_44 ( V_130 -> V_196 ,
V_130 -> V_197 ) ;
return 0 ;
}
static int F_47 ( const struct V_199 * V_200 ,
struct V_138 * V_139 )
{
struct V_199 * V_201 ;
struct V_140 * V_141 = & V_139 -> V_141 ;
T_2 V_202 ;
V_201 = F_48 ( V_200 , L_27 ) ;
V_141 -> V_142 = V_201 ? true : false ;
if ( V_141 -> V_142 ) {
if ( F_49 ( V_201 , L_28 , & V_202 ) >= 0 )
V_141 -> V_144 = V_202 ;
if ( F_49 ( V_201 , L_29 ,
& V_202 ) >= 0 )
V_141 -> V_146 = V_202 ;
if ( F_49 ( V_201 , L_30 , & V_202 ) >= 0 )
V_141 -> V_151 = V_202 ;
if ( F_49 ( V_201 , L_31 ,
& V_202 ) >= 0 )
V_141 -> V_154 = V_202 ;
if ( F_49 ( V_201 , L_32 ,
& V_202 ) >= 0 )
V_141 -> V_157 = V_202 ;
V_141 -> V_159 = F_50 ( V_201 ,
L_33 ) ;
if ( F_49 ( V_201 , L_34 , & V_202 ) >= 0 )
V_141 -> V_163 = V_202 ;
if ( F_49 ( V_201 , L_35 , & V_202 ) >= 0 )
V_141 -> V_166 = V_202 ;
if ( F_49 ( V_201 , L_36 , & V_202 ) >= 0 )
V_141 -> V_169 = V_202 ;
}
F_51 ( V_201 ) ;
return 0 ;
}
static T_3 F_52 ( int V_203 , void * V_204 )
{
struct V_55 * V_130 = V_204 ;
struct V_52 * V_53 = V_130 -> V_53 ;
unsigned int V_205 , V_206 , V_207 , V_208 , V_69 ;
F_14 ( V_130 -> V_59 , V_9 ,
& V_206 ) ;
F_14 ( V_130 -> V_59 , V_8 ,
& V_205 ) ;
F_14 ( V_130 -> V_59 , V_25 , & V_69 ) ;
F_14 ( V_130 -> V_59 , V_24 , & V_208 ) ;
if ( ! ( V_205 & ~ V_208 ) && ! ( V_206 & ~ V_69 ) )
return V_209 ;
F_14 ( V_130 -> V_59 , V_8 ,
& V_207 ) ;
if ( V_205 & V_210 ) {
F_53 ( V_53 -> V_2 , L_37 ) ;
if ( ! ( V_207 & V_210 ) ) {
F_9 ( V_53 -> V_2 ,
L_38 ) ;
F_8 ( V_130 -> V_59 ,
V_23 ,
V_211 , 0 ) ;
F_8 ( V_130 -> V_59 ,
V_23 ,
V_211 ,
V_211 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_211 ,
0 ) ;
}
}
if ( V_205 & V_212 ) {
F_10 ( V_53 -> V_2 , L_39 ) ;
V_130 -> V_58 = false ;
if ( ! ( V_207 & V_212 ) ) {
F_9 ( V_53 -> V_2 , L_40 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_213 ,
0 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_213 ,
V_213 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_213 ,
0 ) ;
}
}
if ( V_205 & V_214 ) {
F_53 ( V_53 -> V_2 , L_41 ) ;
if ( ! ( V_207 & V_214 ) ) {
F_9 ( V_53 -> V_2 ,
L_42 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_215 , 0 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_215 ,
V_215 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_215 , 0 ) ;
}
}
if ( V_205 & V_216 ) {
F_10 ( V_53 -> V_2 , L_43 ) ;
if ( ! ( V_207 & V_216 ) ) {
F_9 ( V_53 -> V_2 ,
L_44 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_217 , 0 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_217 ,
V_217 ) ;
F_8 ( V_130 -> V_59 ,
V_23 , V_217 , 0 ) ;
}
}
if ( V_218 & V_205 )
F_10 ( V_53 -> V_2 , L_45 ) ;
if ( V_219 & V_205 )
F_10 ( V_53 -> V_2 , L_46 ) ;
if ( V_220 & V_206 )
F_10 ( V_53 -> V_2 ,
L_47 ) ;
if ( V_221 & V_206 )
F_10 ( V_53 -> V_2 ,
L_48 ) ;
if ( V_222 & V_206 )
F_10 ( V_53 -> V_2 ,
L_49 ) ;
return V_223 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_55 * V_130 )
{
struct V_199 * V_200 = V_2 -> V_224 ;
struct V_138 * V_139 = & V_130 -> V_139 ;
T_2 V_202 ;
if ( ! V_200 )
return 0 ;
if ( F_49 ( V_200 , L_50 , & V_202 ) >= 0 ) {
V_139 -> V_179 = V_202 ;
V_139 -> V_181 = 1 ;
}
if ( F_49 ( V_200 , L_51 , & V_202 ) >= 0 ) {
V_139 -> V_187 = V_202 ;
V_130 -> V_184 = true ;
}
if ( F_49 ( V_200 , L_52 , & V_202 ) >= 0 )
V_139 -> V_183 = V_202 ;
if ( F_49 ( V_200 , L_53 , & V_202 ) >= 0 ) {
if ( ( V_202 == 0x0 ) || ( V_202 == 0x7 ) || ( V_202 == 0x6 ) )
V_139 -> V_188 = V_202 ;
else
V_139 -> V_188 = 0x8 ;
} else {
V_139 -> V_188 = 0x8 ;
}
F_47 ( V_200 , V_139 ) ;
return 0 ;
}
static int F_55 ( struct V_225 * V_225 ,
const struct V_226 * V_227 )
{
struct V_55 * V_130 ;
struct V_138 * V_139 = F_56 ( & V_225 -> V_2 ) ;
int V_173 , V_228 , V_85 ;
unsigned int V_3 ;
V_130 = F_57 ( & V_225 -> V_2 , sizeof( struct V_55 ) ,
V_229 ) ;
if ( ! V_130 )
return - V_230 ;
F_58 ( V_225 , V_130 ) ;
V_130 -> V_59 = F_59 ( V_225 , & V_231 ) ;
if ( F_60 ( V_130 -> V_59 ) ) {
V_173 = F_61 ( V_130 -> V_59 ) ;
F_10 ( & V_225 -> V_2 , L_54 , V_173 ) ;
return V_173 ;
}
F_41 ( V_130 -> V_59 , true ) ;
for ( V_85 = 0 ; V_85 < F_16 ( V_232 ) ; V_85 ++ )
V_130 -> V_197 [ V_85 ] . V_233
= V_232 [ V_85 ] ;
V_130 -> V_196 = F_16 ( V_232 ) ;
V_173 = F_62 ( & V_225 -> V_2 ,
V_130 -> V_196 ,
V_130 -> V_197 ) ;
if ( V_173 != 0 ) {
F_10 ( & V_225 -> V_2 ,
L_55 ,
V_173 ) ;
return V_173 ;
}
if ( V_139 ) {
V_130 -> V_139 = * V_139 ;
} else {
F_54 ( & V_225 -> V_2 , V_130 ) ;
V_139 = & V_130 -> V_139 ;
}
V_173 = F_63 ( & V_225 -> V_2 , V_225 -> V_203 , NULL ,
F_52 , V_234 | V_235 ,
L_56 , V_130 ) ;
if ( V_173 != 0 )
F_64 ( & V_225 -> V_2 , L_57 , V_173 ) ;
V_130 -> V_195 = F_65 ( & V_225 -> V_2 ,
L_58 , V_236 ) ;
if ( F_60 ( V_130 -> V_195 ) ) {
F_10 ( & V_225 -> V_2 , L_59 ,
V_194 ) ;
return F_61 ( V_130 -> V_195 ) ;
}
V_173 = F_40 ( V_130 -> V_196 ,
V_130 -> V_197 ) ;
if ( V_173 != 0 ) {
F_10 ( & V_225 -> V_2 ,
L_25 ,
V_173 ) ;
return V_173 ;
}
F_39 ( V_130 -> V_195 , 1 ) ;
F_42 ( V_198 ) ;
F_41 ( V_130 -> V_59 , false ) ;
V_173 = F_14 ( V_130 -> V_59 , V_4 , & V_3 ) ;
V_228 = ( V_3 & 0xFF ) << 12 ;
V_173 = F_14 ( V_130 -> V_59 , V_5 , & V_3 ) ;
V_228 |= ( V_3 & 0xFF ) << 4 ;
V_173 = F_14 ( V_130 -> V_59 , V_6 , & V_3 ) ;
V_228 |= ( V_3 & 0xF0 ) >> 4 ;
if ( V_228 != V_237 ) {
F_10 ( & V_225 -> V_2 ,
L_60 ,
V_228 , V_237 ) ;
goto V_238;
}
V_173 = F_14 ( V_130 -> V_59 , V_7 , & V_3 ) ;
if ( V_173 < 0 ) {
F_10 ( & V_225 -> V_2 , L_61 ) ;
goto V_238;
}
F_66 ( & V_225 -> V_2 ,
L_62 , V_3 & 0xFF ) ;
V_173 = F_67 ( V_130 -> V_59 ,
V_239 , F_16 ( V_239 ) ) ;
if ( V_173 < 0 ) {
F_10 ( & V_225 -> V_2 ,
L_63 , V_173 ) ;
goto V_238;
}
F_8 ( V_130 -> V_59 , V_13 ,
V_78 | V_70 ,
V_78 | V_70 ) ;
F_68 ( & V_225 -> V_2 , 100 ) ;
F_69 ( & V_225 -> V_2 ) ;
F_70 ( & V_225 -> V_2 ) ;
F_71 ( & V_225 -> V_2 ) ;
V_173 = F_72 ( & V_225 -> V_2 ,
& V_240 , & V_241 , 1 ) ;
if ( V_173 < 0 ) {
F_10 ( & V_225 -> V_2 , L_64 ,
V_194 ) ;
goto V_238;
}
return 0 ;
V_238:
F_44 ( V_130 -> V_196 ,
V_130 -> V_197 ) ;
return V_173 ;
}
static int F_73 ( struct V_225 * V_242 )
{
struct V_55 * V_130 = F_74 ( V_242 ) ;
F_75 ( & V_242 -> V_2 ) ;
F_39 ( V_130 -> V_195 , 0 ) ;
F_76 ( & V_242 -> V_2 ) ;
F_44 ( V_130 -> V_196 ,
V_130 -> V_197 ) ;
return 0 ;
}
