static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 . V_5 + ( V_3 << V_2 -> V_4 . V_6 ) ) ;
}
static void F_3 ( struct V_7 * V_4 , unsigned int V_8 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_2 -> V_4 . V_11 ;
T_2 V_12 ;
F_5 ( V_4 , V_8 ) ;
V_12 = F_6 ( V_2 , V_13 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
if ( ( V_8 & V_15 ) && ( V_4 -> V_16 & V_17 ) )
V_10 -> V_18 |= V_19 ;
else
V_10 -> V_18 &= ~ V_19 ;
F_7 ( V_2 , V_20 , V_10 -> V_18 ) ;
F_7 ( V_2 , V_13 , V_12 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_2 V_21 = 255 ;
T_2 V_22 ;
V_22 = F_6 ( V_2 , V_23 ) ;
if ( V_22 == V_10 -> V_24 )
return;
F_7 ( V_2 , V_23 , V_10 -> V_24 ) ;
F_9 ( 2 ) ;
F_7 ( V_2 , V_25 , V_2 -> V_26 | V_27 |
V_28 ) ;
while ( V_29 != ( F_6 ( V_2 , V_30 ) &
( V_29 | V_31 ) ) ) {
V_21 -- ;
if ( ! V_21 ) {
F_10 ( V_2 -> V_4 . V_32 , L_1 ,
F_6 ( V_2 , V_30 ) ) ;
break;
}
F_9 ( 1 ) ;
}
}
static void F_11 ( struct V_7 * V_4 , unsigned int V_33 ,
struct V_9 * V_10 )
{
unsigned int V_34 = V_4 -> V_34 ;
unsigned int V_35 , V_36 ;
unsigned int V_37 , V_38 ;
if ( V_33 == 38400 && ( V_4 -> V_39 & V_40 ) == V_41 ) {
V_10 -> V_42 = V_4 -> V_43 & 0xffff ;
if ( V_4 -> V_43 & ( 1 << 16 ) )
V_10 -> V_24 = V_44 ;
else
V_10 -> V_24 = V_45 ;
return;
}
V_35 = F_12 ( V_34 , 13 * V_33 ) ;
V_36 = F_12 ( V_34 , 16 * V_33 ) ;
if ( ! V_35 )
V_35 = 1 ;
if ( ! V_36 )
V_36 = 1 ;
V_37 = abs ( V_33 - V_34 / 13 / V_35 ) ;
V_38 = abs ( V_33 - V_34 / 16 / V_36 ) ;
if ( V_37 >= V_38 ) {
V_10 -> V_24 = V_45 ;
V_10 -> V_42 = V_36 ;
} else {
V_10 -> V_24 = V_44 ;
V_10 -> V_42 = V_35 ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_2 V_46 ;
V_46 = F_6 ( V_2 , V_47 ) ;
if ( V_46 == V_10 -> V_48 )
return;
if ( V_10 -> V_48 & V_49 )
F_7 ( V_2 , V_47 ,
V_10 -> V_48 & ~ V_49 ) ;
F_7 ( V_2 , V_47 , V_10 -> V_48 ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
if ( V_10 -> V_50 & V_51 )
F_8 ( V_2 , V_10 ) ;
else
F_7 ( V_2 , V_23 , V_10 -> V_24 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_4 . V_11 ;
struct V_52 * V_53 = V_2 -> V_53 ;
if ( V_53 && V_53 -> V_54 ) {
V_10 -> V_55 = 1 ;
return;
}
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_20 , V_56 ) ;
F_7 ( V_2 , V_13 , V_57 ) ;
F_7 ( V_2 , V_58 , V_59 ) ;
F_7 ( V_2 , V_25 , V_2 -> V_26 ) ;
F_13 ( V_2 , V_10 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_60 , F_16 ( 16 ) |
F_17 ( 52 ) ) ;
F_7 ( V_2 , V_61 ,
F_18 ( V_62 ) << V_63 |
F_18 ( V_64 ) << V_65 ) ;
F_7 ( V_2 , V_13 , 0 ) ;
F_7 ( V_2 , V_58 , V_2 -> V_66 ) ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_19 ( V_2 , V_10 -> V_42 ) ;
F_7 ( V_2 , V_20 , V_10 -> V_18 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_69 , V_10 -> V_70 ) ;
F_7 ( V_2 , V_71 , V_10 -> V_72 ) ;
F_7 ( V_2 , V_13 , V_2 -> V_12 ) ;
F_14 ( V_2 , V_10 ) ;
V_2 -> V_4 . V_73 -> V_74 ( & V_2 -> V_4 , V_2 -> V_4 . V_8 ) ;
}
static void F_20 ( struct V_7 * V_4 ,
struct V_75 * V_76 ,
struct V_75 * V_77 )
{
struct V_1 * V_2 =
F_21 ( V_4 , struct V_1 , V_4 ) ;
struct V_9 * V_10 = V_2 -> V_4 . V_11 ;
unsigned char V_78 = 0 ;
unsigned int V_33 ;
switch ( V_76 -> V_79 & V_80 ) {
case V_81 :
V_78 = V_82 ;
break;
case V_83 :
V_78 = V_84 ;
break;
case V_85 :
V_78 = V_86 ;
break;
default:
case V_87 :
V_78 = V_88 ;
break;
}
if ( V_76 -> V_79 & V_89 )
V_78 |= V_90 ;
if ( V_76 -> V_79 & V_91 )
V_78 |= V_92 ;
if ( ! ( V_76 -> V_79 & V_93 ) )
V_78 |= V_94 ;
if ( V_76 -> V_79 & V_95 )
V_78 |= V_96 ;
V_33 = F_22 ( V_4 , V_76 , V_77 ,
V_4 -> V_34 / 16 / 0xffff ,
V_4 -> V_34 / 13 ) ;
F_11 ( V_4 , V_33 , V_10 ) ;
F_23 ( V_4 -> V_32 ) ;
F_24 ( & V_4 -> V_97 ) ;
F_25 ( V_4 , V_76 -> V_79 , V_33 ) ;
V_2 -> V_4 . V_98 = V_99 | V_29 | V_31 ;
if ( V_76 -> V_100 & V_101 )
V_2 -> V_4 . V_98 |= V_102 | V_103 ;
if ( V_76 -> V_100 & ( V_104 | V_105 ) )
V_2 -> V_4 . V_98 |= V_106 ;
V_2 -> V_4 . V_107 = 0 ;
if ( V_76 -> V_100 & V_108 )
V_2 -> V_4 . V_107 |= V_103 | V_102 ;
if ( V_76 -> V_100 & V_104 ) {
V_2 -> V_4 . V_107 |= V_106 ;
if ( V_76 -> V_100 & V_108 )
V_2 -> V_4 . V_107 |= V_99 ;
}
if ( ( V_76 -> V_79 & V_109 ) == 0 )
V_2 -> V_4 . V_107 |= V_31 ;
V_2 -> V_68 &= ~ V_110 ;
if ( F_26 ( & V_2 -> V_4 , V_76 -> V_79 ) )
V_2 -> V_68 |= V_110 ;
V_2 -> V_12 = V_78 ;
V_2 -> V_26 = V_111 ;
V_2 -> V_26 |= F_27 ( V_62 ) << V_112 ;
V_2 -> V_26 |= F_27 ( V_64 ) << V_113 ;
V_10 -> V_48 = V_114 | V_115 |
V_116 ;
if ( V_2 -> V_53 )
V_10 -> V_48 |= V_117 |
V_118 ;
V_10 -> V_70 = V_76 -> V_119 [ V_120 ] ;
V_10 -> V_72 = V_76 -> V_119 [ V_121 ] ;
V_10 -> V_18 = 0 ;
V_2 -> V_66 &= ~ ( V_122 | V_123 ) ;
V_2 -> V_4 . V_16 &= ~ ( V_124 | V_17 | V_125 ) ;
if ( V_76 -> V_79 & V_126 && V_2 -> V_4 . V_39 & V_127 ) {
V_2 -> V_4 . V_16 |= V_124 | V_17 ;
V_10 -> V_18 |= V_128 ;
} else if ( V_2 -> V_4 . V_39 & V_129 ) {
if ( V_76 -> V_100 & V_130 ) {
V_2 -> V_4 . V_16 |= V_125 ;
V_10 -> V_18 |= V_131 ;
}
}
F_15 ( V_2 ) ;
F_28 ( & V_2 -> V_4 . V_97 ) ;
F_29 ( V_4 -> V_32 ) ;
F_30 ( V_4 -> V_32 ) ;
V_10 -> V_132 = V_133 * 64 * 8 / V_33 ;
V_10 -> V_134 = V_10 -> V_132 ;
F_31 ( & V_10 -> V_135 ) ;
if ( F_32 ( V_76 ) )
F_33 ( V_76 , V_33 , V_33 ) ;
}
static void F_34 ( struct V_7 * V_4 , unsigned int V_136 ,
unsigned int V_137 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
T_2 V_18 ;
F_23 ( V_4 -> V_32 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
V_18 = F_6 ( V_2 , V_20 ) ;
F_7 ( V_2 , V_20 , V_18 | V_56 ) ;
F_7 ( V_2 , V_13 , 0 ) ;
F_7 ( V_2 , V_67 , ( V_136 != 0 ) ? V_138 : 0 ) ;
F_7 ( V_2 , V_13 , V_14 ) ;
F_7 ( V_2 , V_20 , V_18 ) ;
F_7 ( V_2 , V_13 , 0 ) ;
F_29 ( V_4 -> V_32 ) ;
F_30 ( V_4 -> V_32 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_139 , V_140 ;
T_3 V_141 , V_142 , V_143 ;
V_139 = F_1 ( V_2 , V_144 ) ;
V_140 = V_139 >> V_145 ;
switch ( V_140 ) {
case 0 :
V_142 = ( V_139 & V_146 ) >>
V_147 ;
V_143 = ( V_139 & V_148 ) ;
break;
case 1 :
V_142 = ( V_139 & V_149 ) >>
V_150 ;
V_143 = ( V_139 & V_151 ) ;
break;
default:
F_36 ( V_2 -> V_4 . V_32 ,
L_2 ) ;
V_142 = 0xff ;
V_143 = 0xff ;
}
V_141 = F_37 ( V_142 , V_143 ) ;
switch ( V_141 ) {
case V_152 :
V_10 -> V_50 |= V_51 ;
break;
case V_153 :
V_10 -> V_50 |= V_51 |
V_154 ;
break;
case V_155 :
V_10 -> V_50 |= V_51 |
V_154 ;
break;
default:
break;
}
}
static void F_38 ( struct V_156 * V_157 )
{
struct V_9 * V_10 ;
V_10 = F_21 ( V_157 , struct V_9 , V_135 ) ;
F_39 ( & V_10 -> V_158 , V_10 -> V_134 ) ;
}
static T_4 F_40 ( int V_159 , void * V_160 )
{
struct V_7 * V_4 = V_160 ;
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned int V_161 ;
int V_162 ;
#ifdef F_41
if ( V_2 -> V_53 ) {
V_162 = F_42 ( V_4 ) ;
return F_43 ( V_162 ) ;
}
#endif
F_44 ( V_2 ) ;
V_161 = F_45 ( V_4 , V_163 ) ;
V_162 = F_46 ( V_4 , V_161 ) ;
F_47 ( V_2 ) ;
return F_43 ( V_162 ) ;
}
static int F_48 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_4 -> V_11 ;
int V_162 ;
if ( V_10 -> V_164 ) {
V_162 = F_49 ( V_4 -> V_32 , V_10 -> V_164 ) ;
if ( V_162 )
return V_162 ;
}
F_23 ( V_4 -> V_32 ) ;
V_2 -> V_66 = 0 ;
F_7 ( V_2 , V_25 , V_28 | V_27 ) ;
F_7 ( V_2 , V_13 , V_88 ) ;
V_2 -> V_165 = 0 ;
V_2 -> V_166 = 0 ;
if ( V_2 -> V_53 ) {
V_162 = F_50 ( V_2 ) ;
if ( V_162 ) {
F_51 ( V_4 -> V_32 ,
L_3 ) ;
V_2 -> V_53 = NULL ;
}
}
V_162 = F_52 ( V_4 -> V_159 , F_40 , V_167 ,
F_53 ( V_4 -> V_32 ) , V_4 ) ;
if ( V_162 < 0 )
goto V_168;
V_2 -> V_68 = V_169 | V_170 ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
#ifdef F_54
V_2 -> V_171 |= V_172 ;
#endif
V_10 -> V_173 = V_174 ;
if ( V_10 -> V_50 & V_154 )
V_10 -> V_173 |= V_175 ;
F_7 ( V_2 , V_176 , V_10 -> V_173 ) ;
if ( V_2 -> V_53 )
V_2 -> V_53 -> V_177 ( V_2 , 0 ) ;
F_29 ( V_4 -> V_32 ) ;
F_30 ( V_4 -> V_32 ) ;
return 0 ;
V_168:
F_29 ( V_4 -> V_32 ) ;
F_30 ( V_4 -> V_32 ) ;
F_55 ( V_4 -> V_32 ) ;
return V_162 ;
}
static void F_56 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
struct V_9 * V_10 = V_4 -> V_11 ;
F_57 ( & V_10 -> V_135 ) ;
if ( V_2 -> V_53 )
V_2 -> V_53 -> V_177 ( V_2 , V_178 ) ;
F_23 ( V_4 -> V_32 ) ;
F_7 ( V_2 , V_176 , 0 ) ;
V_2 -> V_68 = 0 ;
F_7 ( V_2 , V_67 , 0 ) ;
if ( V_2 -> V_53 )
F_58 ( V_2 ) ;
if ( V_2 -> V_12 & V_179 )
F_7 ( V_2 , V_13 , V_2 -> V_12 & ~ V_179 ) ;
F_7 ( V_2 , V_25 , V_28 | V_27 ) ;
F_29 ( V_4 -> V_32 ) ;
F_30 ( V_4 -> V_32 ) ;
F_59 ( V_4 -> V_159 , V_4 ) ;
F_55 ( V_4 -> V_32 ) ;
}
static void F_60 ( struct V_7 * V_4 )
{
unsigned long V_39 ;
struct V_1 * V_2 =
F_21 ( V_4 , struct V_1 , V_4 ) ;
F_23 ( V_4 -> V_32 ) ;
F_61 ( & V_4 -> V_97 , V_39 ) ;
V_2 -> V_68 &= ~ ( V_169 | V_170 ) ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
F_62 ( & V_4 -> V_97 , V_39 ) ;
F_29 ( V_4 -> V_32 ) ;
F_30 ( V_4 -> V_32 ) ;
}
static void F_63 ( struct V_7 * V_4 )
{
unsigned long V_39 ;
struct V_1 * V_2 =
F_21 ( V_4 , struct V_1 , V_4 ) ;
F_23 ( V_4 -> V_32 ) ;
F_61 ( & V_4 -> V_97 , V_39 ) ;
V_2 -> V_68 |= V_169 | V_170 ;
F_7 ( V_2 , V_67 , V_2 -> V_68 ) ;
F_62 ( & V_4 -> V_97 , V_39 ) ;
F_29 ( V_4 -> V_32 ) ;
F_30 ( V_4 -> V_32 ) ;
}
static void F_64 ( struct V_1 * V_180 , bool error )
{
struct V_9 * V_10 = V_180 -> V_4 . V_11 ;
struct V_52 * V_53 = V_180 -> V_53 ;
struct V_181 * V_181 = & V_180 -> V_4 . V_136 -> V_4 ;
struct V_182 V_136 ;
int V_183 ;
unsigned long V_39 ;
F_65 ( V_53 -> V_184 -> V_185 -> V_32 , V_53 -> V_186 ,
V_53 -> V_187 , V_188 ) ;
F_61 ( & V_10 -> V_189 , V_39 ) ;
if ( ! V_53 -> V_190 )
goto V_191;
V_53 -> V_190 = 0 ;
F_66 ( V_53 -> V_184 , V_53 -> V_192 , & V_136 ) ;
F_67 ( V_53 -> V_184 ) ;
V_183 = V_53 -> V_187 - V_136 . V_193 ;
F_68 ( V_181 , V_53 -> V_194 , V_183 ) ;
V_180 -> V_4 . V_195 . V_196 += V_183 ;
V_191:
F_62 ( & V_10 -> V_189 , V_39 ) ;
if ( ! error )
F_69 ( V_180 , 0 ) ;
F_70 ( V_181 ) ;
}
static void F_71 ( void * V_197 )
{
F_64 ( V_197 , false ) ;
}
static void F_72 ( struct V_1 * V_180 )
{
struct V_9 * V_10 = V_180 -> V_4 . V_11 ;
struct V_52 * V_53 = V_180 -> V_53 ;
unsigned long V_39 ;
int V_162 ;
F_61 ( & V_10 -> V_189 , V_39 ) ;
if ( ! V_53 -> V_190 ) {
F_62 ( & V_10 -> V_189 , V_39 ) ;
return;
}
V_162 = F_73 ( V_53 -> V_184 ) ;
if ( F_74 ( V_162 ) )
V_10 -> V_198 = true ;
F_62 ( & V_10 -> V_189 , V_39 ) ;
F_64 ( V_180 , true ) ;
}
static int F_69 ( struct V_1 * V_180 , unsigned int V_161 )
{
struct V_9 * V_10 = V_180 -> V_4 . V_11 ;
struct V_52 * V_53 = V_180 -> V_53 ;
int V_168 = 0 ;
struct V_199 * V_200 ;
unsigned long V_39 ;
switch ( V_161 & 0x3f ) {
case V_201 :
F_72 ( V_180 ) ;
return - V_202 ;
case V_178 :
F_72 ( V_180 ) ;
return - V_203 ;
case V_204 :
F_72 ( V_180 ) ;
return - V_203 ;
default:
break;
}
if ( V_10 -> V_198 )
return - V_205 ;
F_61 ( & V_10 -> V_189 , V_39 ) ;
if ( V_53 -> V_190 )
goto V_206;
V_200 = F_75 ( V_53 -> V_184 , V_53 -> V_186 ,
V_53 -> V_187 , V_207 ,
V_208 | V_209 ) ;
if ( ! V_200 ) {
V_168 = - V_210 ;
goto V_206;
}
V_53 -> V_190 = 1 ;
V_200 -> V_211 = F_71 ;
V_200 -> V_212 = V_180 ;
V_53 -> V_192 = F_76 ( V_200 ) ;
F_77 ( V_53 -> V_184 -> V_185 -> V_32 , V_53 -> V_186 ,
V_53 -> V_187 , V_188 ) ;
F_78 ( V_53 -> V_184 ) ;
V_206:
F_62 ( & V_10 -> V_189 , V_39 ) ;
return V_168 ;
}
static void F_79 ( void * V_197 )
{
struct V_1 * V_180 = V_197 ;
struct V_52 * V_53 = V_180 -> V_53 ;
struct V_213 * V_214 = & V_180 -> V_4 . V_136 -> V_214 ;
unsigned long V_39 ;
bool V_215 = false ;
struct V_9 * V_10 = V_180 -> V_4 . V_11 ;
F_65 ( V_53 -> V_216 -> V_185 -> V_32 , V_53 -> V_217 ,
V_218 , V_219 ) ;
F_61 ( & V_180 -> V_4 . V_97 , V_39 ) ;
V_53 -> V_54 = 0 ;
V_214 -> V_220 += V_53 -> V_221 ;
V_214 -> V_220 &= V_218 - 1 ;
V_180 -> V_4 . V_195 . V_222 += V_53 -> V_221 ;
if ( V_10 -> V_55 ) {
V_10 -> V_55 = 0 ;
F_15 ( V_180 ) ;
}
if ( F_80 ( V_214 ) < V_223 )
F_81 ( & V_180 -> V_4 ) ;
if ( ! F_82 ( V_214 ) && ! F_83 ( & V_180 -> V_4 ) ) {
int V_162 ;
V_162 = F_84 ( V_180 ) ;
if ( V_162 )
V_215 = true ;
} else if ( V_180 -> V_171 & V_172 ) {
V_215 = true ;
}
if ( V_215 ) {
V_53 -> V_224 = 1 ;
V_180 -> V_68 |= V_225 ;
F_85 ( & V_180 -> V_4 , V_67 , V_180 -> V_68 ) ;
}
F_62 ( & V_180 -> V_4 . V_97 , V_39 ) ;
}
static int F_84 ( struct V_1 * V_180 )
{
struct V_52 * V_53 = V_180 -> V_53 ;
struct V_9 * V_10 = V_180 -> V_4 . V_11 ;
struct V_213 * V_214 = & V_180 -> V_4 . V_136 -> V_214 ;
struct V_199 * V_200 ;
unsigned int V_226 = 0 ;
int V_162 ;
if ( V_53 -> V_54 )
return 0 ;
if ( F_83 ( & V_180 -> V_4 ) || F_82 ( V_214 ) ) {
if ( V_53 -> V_224 || V_180 -> V_171 & V_172 ) {
V_162 = - V_210 ;
goto V_168;
}
if ( V_180 -> V_68 & V_225 ) {
V_180 -> V_68 &= ~ V_225 ;
F_7 ( V_180 , V_67 , V_180 -> V_68 ) ;
}
return 0 ;
}
V_53 -> V_221 = F_86 ( V_214 -> V_227 , V_214 -> V_220 , V_218 ) ;
if ( V_10 -> V_50 & V_228 ) {
T_2 V_229 ;
V_229 = F_6 ( V_180 , V_230 ) ;
if ( V_229 == V_180 -> V_231 ) {
V_162 = - V_210 ;
goto V_168;
}
if ( V_53 -> V_221 < 4 ) {
V_162 = - V_205 ;
goto V_168;
}
V_226 = 1 ;
}
V_200 = F_75 ( V_53 -> V_216 ,
V_53 -> V_217 + V_214 -> V_220 + V_226 ,
V_53 -> V_221 - V_226 , V_232 ,
V_208 | V_209 ) ;
if ( ! V_200 ) {
V_162 = - V_210 ;
goto V_168;
}
V_53 -> V_54 = 1 ;
V_200 -> V_211 = F_79 ;
V_200 -> V_212 = V_180 ;
V_53 -> V_233 = F_76 ( V_200 ) ;
F_77 ( V_53 -> V_216 -> V_185 -> V_32 , V_53 -> V_217 ,
V_218 , V_219 ) ;
F_78 ( V_53 -> V_216 ) ;
if ( V_53 -> V_224 )
V_53 -> V_224 = 0 ;
if ( V_180 -> V_68 & V_225 ) {
V_180 -> V_68 &= ~ V_225 ;
F_7 ( V_180 , V_67 , V_180 -> V_68 ) ;
}
if ( V_226 )
F_7 ( V_180 , V_234 , V_214 -> V_235 [ V_214 -> V_220 ] ) ;
return 0 ;
V_168:
V_53 -> V_224 = 1 ;
return V_162 ;
}
static int F_42 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = F_4 ( V_4 ) ;
unsigned char V_16 ;
unsigned long V_39 ;
T_2 V_161 ;
int V_236 = 0 ;
F_44 ( V_2 ) ;
V_161 = F_45 ( V_4 , V_163 ) ;
if ( V_161 & V_237 ) {
F_47 ( V_2 ) ;
return 0 ;
}
F_61 ( & V_4 -> V_97 , V_39 ) ;
V_16 = F_45 ( V_4 , V_30 ) ;
if ( V_16 & ( V_31 | V_106 ) ) {
V_236 = F_69 ( V_2 , V_161 ) ;
if ( V_236 ) {
V_16 = F_87 ( V_2 , V_16 ) ;
F_69 ( V_2 , 0 ) ;
}
}
F_88 ( V_2 ) ;
if ( V_16 & V_29 && V_2 -> V_53 -> V_224 ) {
if ( F_83 ( & V_2 -> V_4 ) ||
F_82 ( & V_2 -> V_4 . V_136 -> V_214 ) ) {
V_2 -> V_53 -> V_224 = 0 ;
F_89 ( V_2 ) ;
} else {
V_236 = F_84 ( V_2 ) ;
if ( V_236 )
F_89 ( V_2 ) ;
}
}
F_62 ( & V_4 -> V_97 , V_39 ) ;
F_47 ( V_2 ) ;
return 1 ;
}
static bool F_90 ( struct V_238 * V_239 , void * V_197 )
{
return false ;
}
static inline int F_69 ( struct V_1 * V_180 , unsigned int V_161 )
{
return - V_205 ;
}
static int F_91 ( struct V_7 * V_4 )
{
F_92 ( 1 , L_4 ) ;
return 0 ;
}
static int F_93 ( struct V_240 * V_241 )
{
struct V_242 * V_243 = F_94 ( V_241 , V_244 , 0 ) ;
struct V_242 * V_159 = F_94 ( V_241 , V_245 , 0 ) ;
struct V_9 * V_10 ;
struct V_1 V_2 ;
int V_162 ;
void T_5 * V_5 ;
if ( ! V_243 || ! V_159 ) {
F_95 ( & V_241 -> V_32 , L_5 ) ;
return - V_205 ;
}
V_10 = F_96 ( & V_241 -> V_32 , sizeof( * V_10 ) , V_246 ) ;
if ( ! V_10 )
return - V_247 ;
V_5 = F_97 ( & V_241 -> V_32 , V_243 -> V_248 ,
F_98 ( V_243 ) ) ;
if ( ! V_5 )
return - V_249 ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_4 . V_32 = & V_241 -> V_32 ;
V_2 . V_4 . V_250 = V_243 -> V_248 ;
V_2 . V_4 . V_5 = V_5 ;
V_2 . V_4 . V_159 = V_159 -> V_248 ;
V_2 . V_4 . type = V_251 ;
V_2 . V_4 . V_252 = V_253 ;
V_2 . V_4 . V_39 = V_254 | V_255 | V_129 |
V_127 ;
V_2 . V_4 . V_11 = V_10 ;
V_2 . V_4 . V_6 = 2 ;
V_2 . V_4 . V_256 = 64 ;
V_2 . V_231 = 64 ;
V_2 . V_171 = V_257 ;
#ifdef F_54
V_2 . V_171 |= V_172 ;
#endif
V_2 . V_4 . V_258 = F_20 ;
V_2 . V_4 . V_74 = F_3 ;
V_2 . V_4 . V_259 = F_34 ;
V_2 . V_4 . V_260 = F_48 ;
V_2 . V_4 . V_261 = F_56 ;
V_2 . V_4 . V_262 = F_60 ;
V_2 . V_4 . V_263 = F_63 ;
if ( V_241 -> V_32 . V_264 ) {
const struct V_265 * V_266 ;
V_162 = F_99 ( V_241 -> V_32 . V_264 , L_6 ) ;
F_100 ( V_241 -> V_32 . V_264 , L_7 ,
& V_2 . V_4 . V_34 ) ;
V_10 -> V_164 = F_101 ( V_241 -> V_32 . V_264 , 1 ) ;
V_266 = F_102 ( F_103 ( V_267 ) , & V_241 -> V_32 ) ;
if ( V_266 && V_266 -> V_268 )
V_10 -> V_50 |= * ( T_2 * ) V_266 -> V_268 ;
} else {
V_162 = V_241 -> V_266 ;
}
if ( V_162 < 0 ) {
F_95 ( & V_241 -> V_32 , L_8 ) ;
return V_162 ;
}
V_2 . V_4 . line = V_162 ;
if ( ! V_2 . V_4 . V_34 ) {
V_2 . V_4 . V_34 = V_269 ;
F_36 ( & V_241 -> V_32 ,
L_9 ,
V_269 ) ;
}
V_10 -> V_134 = V_270 ;
V_10 -> V_132 = V_270 ;
F_104 ( & V_10 -> V_158 , V_271 ,
V_10 -> V_134 ) ;
F_105 ( & V_10 -> V_135 , F_38 ) ;
F_106 ( & V_10 -> V_189 ) ;
F_107 ( & V_241 -> V_32 , true ) ;
F_108 ( & V_241 -> V_32 ) ;
F_109 ( & V_241 -> V_32 , - 1 ) ;
F_110 ( & V_241 -> V_32 ) ;
F_111 ( & V_241 -> V_32 ) ;
F_23 ( & V_241 -> V_32 ) ;
F_35 ( & V_2 , V_10 ) ;
V_2 . V_4 . V_272 = F_91 ;
#ifdef F_41
if ( V_241 -> V_32 . V_264 ) {
V_162 = F_112 ( V_241 -> V_32 . V_264 , L_10 ) ;
if ( V_162 == 2 ) {
V_2 . V_53 = & V_10 -> V_273 ;
V_10 -> V_273 . V_274 = F_90 ;
V_10 -> V_273 . V_275 = F_84 ;
V_10 -> V_273 . V_177 = F_69 ;
V_10 -> V_273 . V_187 = V_64 ;
V_10 -> V_273 . V_276 . V_277 = V_64 ;
V_10 -> V_273 . V_278 . V_279 = V_62 ;
if ( F_113 ( L_11 ) )
V_10 -> V_50 |= V_228 ;
V_10 -> V_198 = true ;
}
}
#endif
V_162 = F_114 ( & V_2 ) ;
if ( V_162 < 0 ) {
F_95 ( & V_241 -> V_32 , L_12 ) ;
goto V_168;
}
V_10 -> line = V_162 ;
F_115 ( V_241 , V_10 ) ;
F_29 ( & V_241 -> V_32 ) ;
F_30 ( & V_241 -> V_32 ) ;
return 0 ;
V_168:
F_116 ( & V_241 -> V_32 ) ;
F_117 ( & V_241 -> V_32 ) ;
return V_162 ;
}
static int F_118 ( struct V_240 * V_241 )
{
struct V_9 * V_10 = F_119 ( V_241 ) ;
F_120 ( & V_241 -> V_32 ) ;
F_117 ( & V_241 -> V_32 ) ;
F_121 ( V_10 -> line ) ;
F_122 ( & V_10 -> V_158 ) ;
F_107 ( & V_241 -> V_32 , false ) ;
return 0 ;
}
static int F_123 ( struct V_185 * V_32 )
{
struct V_9 * V_10 = F_124 ( V_32 ) ;
if ( ! V_10 )
return 0 ;
V_10 -> V_280 = true ;
return 0 ;
}
static void F_125 ( struct V_185 * V_32 )
{
struct V_9 * V_10 = F_124 ( V_32 ) ;
if ( ! V_10 )
return;
V_10 -> V_280 = false ;
}
static int F_126 ( struct V_185 * V_32 )
{
struct V_9 * V_10 = F_124 ( V_32 ) ;
F_127 ( V_10 -> line ) ;
F_57 ( & V_10 -> V_135 ) ;
return 0 ;
}
static int F_128 ( struct V_185 * V_32 )
{
struct V_9 * V_10 = F_124 ( V_32 ) ;
F_129 ( V_10 -> line ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
T_1 V_281 ;
V_281 = F_6 ( V_2 , V_47 ) ;
if ( ! V_281 )
return 1 ;
return 0 ;
}
static int F_131 ( struct V_185 * V_32 )
{
struct V_9 * V_10 = F_124 ( V_32 ) ;
struct V_1 * V_2 = F_132 ( V_10 -> line ) ;
int V_21 = 100 ;
int V_282 ;
int V_283 ;
V_282 = F_6 ( V_2 , V_284 ) ;
V_282 |= V_285 ;
F_7 ( V_2 , V_284 , V_282 ) ;
do {
F_9 ( 1 ) ;
V_283 = F_6 ( V_2 , V_286 ) ;
} while ( -- V_21 && ! ( V_283 & V_287 ) );
if ( ! V_21 ) {
F_95 ( V_32 , L_13 ) ;
return - V_203 ;
}
return 0 ;
}
static int F_133 ( struct V_185 * V_32 )
{
struct V_9 * V_10 = F_124 ( V_32 ) ;
struct V_1 * V_2 ;
V_2 = F_132 ( V_10 -> line ) ;
if ( V_10 -> V_280 && ! V_288 ) {
if ( F_134 ( & V_2 -> V_4 ) )
return - V_210 ;
}
if ( V_10 -> V_50 & V_289 ) {
int V_162 ;
V_162 = F_131 ( V_32 ) ;
if ( V_162 )
return V_162 ;
F_14 ( V_2 , V_10 ) ;
}
if ( V_2 -> V_53 && V_2 -> V_53 -> V_184 )
F_69 ( V_2 , V_178 ) ;
V_10 -> V_134 = V_270 ;
F_31 ( & V_10 -> V_135 ) ;
return 0 ;
}
static int F_135 ( struct V_185 * V_32 )
{
struct V_9 * V_10 = F_124 ( V_32 ) ;
struct V_1 * V_2 ;
int V_290 ;
if ( ! V_10 )
return 0 ;
V_2 = F_132 ( V_10 -> line ) ;
V_290 = F_130 ( V_2 ) ;
if ( V_290 )
F_15 ( V_2 ) ;
if ( V_2 -> V_53 && V_2 -> V_53 -> V_184 )
F_69 ( V_2 , 0 ) ;
V_10 -> V_134 = V_10 -> V_132 ;
F_31 ( & V_10 -> V_135 ) ;
return 0 ;
}
static int T_6 F_136 ( void )
{
char * V_291 ;
char * V_292 ;
T_2 V_293 ;
if ( strstr ( V_294 , L_14 ) )
return 0 ;
V_291 = strstr ( V_294 , L_15 ) ;
if ( ! V_291 )
return 0 ;
V_291 += 12 ;
if ( '0' <= * V_291 && * V_291 <= '9' )
V_293 = * V_291 - '0' ;
else
return 0 ;
V_291 ++ ;
if ( V_291 [ 0 ] == ',' ) {
V_291 ++ ;
V_292 = V_291 ;
} else {
V_292 = NULL ;
}
F_137 ( L_16 , V_293 , V_292 ) ;
F_138 ( L_17 ,
V_293 , V_293 ) ;
F_138 ( L_18 ) ;
F_138 ( L_19 ) ;
return 0 ;
}
