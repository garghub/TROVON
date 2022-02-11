static inline void F_1 ( struct V_1 * V_2 ) { }
static T_1 F_2 ( struct V_1 * V_3 , T_1 V_4 )
{
return F_3 ( V_3 -> V_5 . V_6 + ( V_4 << V_3 -> V_5 . V_7 ) ) ;
}
static void F_4 ( struct V_8 * V_5 , unsigned int V_9 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
struct V_10 * V_11 = V_3 -> V_5 . V_12 ;
T_2 V_13 ;
F_6 ( V_5 , V_9 ) ;
V_13 = F_7 ( V_3 , V_14 ) ;
F_8 ( V_3 , V_14 , V_15 ) ;
if ( ( V_9 & V_16 ) && ( V_5 -> V_17 & V_18 ) )
V_11 -> V_19 |= V_20 ;
else
V_11 -> V_19 &= ~ V_20 ;
F_8 ( V_3 , V_21 , V_11 -> V_19 ) ;
F_8 ( V_3 , V_14 , V_13 ) ;
}
static void F_9 ( struct V_1 * V_3 ,
struct V_10 * V_11 )
{
T_2 V_22 = 255 ;
T_2 V_23 ;
V_23 = F_7 ( V_3 , V_24 ) ;
if ( V_23 == V_11 -> V_25 )
return;
F_8 ( V_3 , V_24 , V_11 -> V_25 ) ;
F_10 ( 2 ) ;
F_8 ( V_3 , V_26 , V_3 -> V_27 | V_28 |
V_29 ) ;
while ( V_30 != ( F_7 ( V_3 , V_31 ) &
( V_30 | V_32 ) ) ) {
V_22 -- ;
if ( ! V_22 ) {
F_11 ( V_3 -> V_5 . V_33 , L_1 ,
F_7 ( V_3 , V_31 ) ) ;
break;
}
F_10 ( 1 ) ;
}
}
static void F_12 ( struct V_8 * V_5 , unsigned int V_34 ,
struct V_10 * V_11 )
{
unsigned int V_35 = V_5 -> V_35 ;
unsigned int V_36 , V_37 ;
unsigned int V_38 , V_39 ;
if ( V_34 == 38400 && ( V_5 -> V_40 & V_41 ) == V_42 ) {
V_11 -> V_43 = V_5 -> V_44 & 0xffff ;
if ( V_5 -> V_44 & ( 1 << 16 ) )
V_11 -> V_25 = V_45 ;
else
V_11 -> V_25 = V_46 ;
return;
}
V_36 = F_13 ( V_35 , 13 * V_34 ) ;
V_37 = F_13 ( V_35 , 16 * V_34 ) ;
if ( ! V_36 )
V_36 = 1 ;
if ( ! V_37 )
V_37 = 1 ;
V_38 = abs ( V_34 - V_35 / 13 / V_36 ) ;
V_39 = abs ( V_34 - V_35 / 16 / V_37 ) ;
if ( V_38 >= V_39 ) {
V_11 -> V_25 = V_46 ;
V_11 -> V_43 = V_37 ;
} else {
V_11 -> V_25 = V_45 ;
V_11 -> V_43 = V_36 ;
}
}
static void F_14 ( struct V_1 * V_3 ,
struct V_10 * V_11 )
{
T_2 V_47 ;
V_47 = F_7 ( V_3 , V_48 ) ;
if ( V_47 == V_11 -> V_49 )
return;
if ( V_11 -> V_49 & V_50 )
F_8 ( V_3 , V_48 ,
V_11 -> V_49 & ~ V_50 ) ;
F_8 ( V_3 , V_48 , V_11 -> V_49 ) ;
}
static void F_15 ( struct V_1 * V_3 ,
struct V_10 * V_11 )
{
if ( V_11 -> V_51 & V_52 )
F_9 ( V_3 , V_11 ) ;
else
F_8 ( V_3 , V_24 , V_11 -> V_25 ) ;
}
static void F_16 ( struct V_1 * V_3 )
{
struct V_10 * V_11 = V_3 -> V_5 . V_12 ;
struct V_53 * V_54 = V_3 -> V_54 ;
if ( V_54 && V_54 -> V_55 ) {
V_11 -> V_56 = 1 ;
return;
}
F_8 ( V_3 , V_14 , V_15 ) ;
F_8 ( V_3 , V_21 , V_57 ) ;
F_8 ( V_3 , V_14 , V_58 ) ;
F_17 ( V_3 , V_59 ) ;
F_8 ( V_3 , V_26 , V_3 -> V_27 ) ;
F_14 ( V_3 , V_11 ) ;
F_8 ( V_3 , V_14 , V_15 ) ;
F_8 ( V_3 , V_60 , F_18 ( 16 ) |
F_19 ( 52 ) ) ;
F_8 ( V_3 , V_61 ,
F_20 ( V_62 ) << V_63 |
F_20 ( V_64 ) << V_65 ) ;
F_8 ( V_3 , V_14 , 0 ) ;
F_17 ( V_3 , V_3 -> V_66 ) ;
F_8 ( V_3 , V_67 , V_3 -> V_68 ) ;
F_8 ( V_3 , V_14 , V_15 ) ;
F_21 ( V_3 , V_11 -> V_43 ) ;
F_8 ( V_3 , V_21 , V_11 -> V_19 ) ;
F_8 ( V_3 , V_14 , V_15 ) ;
F_8 ( V_3 , V_69 , V_11 -> V_70 ) ;
F_8 ( V_3 , V_71 , V_11 -> V_72 ) ;
F_8 ( V_3 , V_14 , V_3 -> V_13 ) ;
F_15 ( V_3 , V_11 ) ;
V_3 -> V_5 . V_73 -> V_74 ( & V_3 -> V_5 , V_3 -> V_5 . V_9 ) ;
}
static void F_22 ( struct V_8 * V_5 ,
struct V_75 * V_76 ,
struct V_75 * V_77 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
struct V_10 * V_11 = V_3 -> V_5 . V_12 ;
unsigned char V_78 = 0 ;
unsigned int V_34 ;
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
V_34 = F_23 ( V_5 , V_76 , V_77 ,
V_5 -> V_35 / 16 / 0xffff ,
V_5 -> V_35 / 13 ) ;
F_12 ( V_5 , V_34 , V_11 ) ;
F_24 ( V_5 -> V_33 ) ;
F_25 ( & V_5 -> V_97 ) ;
F_26 ( V_5 , V_76 -> V_79 , V_34 ) ;
V_3 -> V_5 . V_98 = V_99 | V_30 | V_32 ;
if ( V_76 -> V_100 & V_101 )
V_3 -> V_5 . V_98 |= V_102 | V_103 ;
if ( V_76 -> V_100 & ( V_104 | V_105 ) )
V_3 -> V_5 . V_98 |= V_106 ;
V_3 -> V_5 . V_107 = 0 ;
if ( V_76 -> V_100 & V_108 )
V_3 -> V_5 . V_107 |= V_103 | V_102 ;
if ( V_76 -> V_100 & V_104 ) {
V_3 -> V_5 . V_107 |= V_106 ;
if ( V_76 -> V_100 & V_108 )
V_3 -> V_5 . V_107 |= V_99 ;
}
if ( ( V_76 -> V_79 & V_109 ) == 0 )
V_3 -> V_5 . V_107 |= V_32 ;
V_3 -> V_68 &= ~ V_110 ;
if ( F_27 ( & V_3 -> V_5 , V_76 -> V_79 ) )
V_3 -> V_68 |= V_110 ;
V_3 -> V_13 = V_78 ;
V_3 -> V_27 = V_111 ;
V_3 -> V_27 |= F_28 ( V_62 ) << V_112 ;
V_3 -> V_27 |= F_28 ( V_64 ) << V_113 ;
V_11 -> V_49 = V_114 | V_115 |
V_116 ;
if ( V_3 -> V_54 )
V_11 -> V_49 |= V_117 |
V_118 ;
V_11 -> V_70 = V_76 -> V_119 [ V_120 ] ;
V_11 -> V_72 = V_76 -> V_119 [ V_121 ] ;
V_11 -> V_19 = 0 ;
V_3 -> V_5 . V_17 &= ~ ( V_122 | V_18 | V_123 ) ;
if ( V_76 -> V_79 & V_124 && V_3 -> V_5 . V_40 & V_125 ) {
V_3 -> V_5 . V_17 |= V_122 | V_18 ;
V_11 -> V_19 |= V_126 ;
} else if ( V_3 -> V_5 . V_40 & V_127 ) {
if ( V_76 -> V_100 & V_128 ) {
V_3 -> V_5 . V_17 |= V_123 ;
V_11 -> V_19 |= V_129 ;
}
}
F_16 ( V_3 ) ;
F_29 ( & V_3 -> V_5 . V_97 ) ;
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_33 ) ;
V_11 -> V_130 = V_131 * 64 * 8 / V_34 ;
V_11 -> V_132 = V_11 -> V_130 ;
F_32 ( & V_11 -> V_133 ) ;
if ( F_33 ( V_76 ) )
F_34 ( V_76 , V_34 , V_34 ) ;
}
static void F_35 ( struct V_8 * V_5 , unsigned int V_134 ,
unsigned int V_135 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
T_2 V_19 ;
F_24 ( V_5 -> V_33 ) ;
F_8 ( V_3 , V_14 , V_15 ) ;
V_19 = F_7 ( V_3 , V_21 ) ;
F_8 ( V_3 , V_21 , V_19 | V_57 ) ;
F_8 ( V_3 , V_14 , 0 ) ;
F_8 ( V_3 , V_67 , ( V_134 != 0 ) ? V_136 : 0 ) ;
F_8 ( V_3 , V_14 , V_15 ) ;
F_8 ( V_3 , V_21 , V_19 ) ;
F_8 ( V_3 , V_14 , 0 ) ;
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_33 ) ;
}
static void F_36 ( struct V_1 * V_3 ,
struct V_10 * V_11 )
{
T_1 V_137 , V_138 ;
T_3 V_139 , V_140 , V_141 ;
V_137 = F_2 ( V_3 , V_142 ) ;
V_138 = V_137 >> V_143 ;
switch ( V_138 ) {
case 0 :
V_140 = ( V_137 & V_144 ) >>
V_145 ;
V_141 = ( V_137 & V_146 ) ;
break;
case 1 :
V_140 = ( V_137 & V_147 ) >>
V_148 ;
V_141 = ( V_137 & V_149 ) ;
break;
default:
F_37 ( V_3 -> V_5 . V_33 ,
L_2 ) ;
V_140 = 0xff ;
V_141 = 0xff ;
}
V_139 = F_38 ( V_140 , V_141 ) ;
switch ( V_139 ) {
case V_150 :
V_11 -> V_51 |= V_52 ;
break;
case V_151 :
V_11 -> V_51 |= V_52 |
V_152 ;
break;
case V_153 :
V_11 -> V_51 |= V_52 |
V_152 ;
break;
default:
break;
}
}
static void F_39 ( struct V_154 * V_155 )
{
struct V_10 * V_11 ;
V_11 = F_40 ( V_155 , struct V_10 , V_133 ) ;
F_41 ( & V_11 -> V_156 , V_11 -> V_132 ) ;
}
static T_4 F_42 ( int V_157 , void * V_158 )
{
struct V_8 * V_5 = V_158 ;
struct V_1 * V_3 = F_5 ( V_5 ) ;
unsigned int V_159 ;
int V_160 ;
#ifdef F_43
if ( V_3 -> V_54 ) {
V_160 = F_44 ( V_5 ) ;
return F_45 ( V_160 ) ;
}
#endif
F_46 ( V_3 ) ;
V_159 = F_47 ( V_5 , V_161 ) ;
V_160 = F_48 ( V_5 , V_159 ) ;
F_49 ( V_3 ) ;
return F_45 ( V_160 ) ;
}
static int F_50 ( struct V_8 * V_5 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
struct V_10 * V_11 = V_5 -> V_12 ;
int V_160 ;
if ( V_11 -> V_162 ) {
V_160 = F_51 ( V_5 -> V_33 , V_11 -> V_162 ) ;
if ( V_160 )
return V_160 ;
}
F_24 ( V_5 -> V_33 ) ;
V_3 -> V_66 = 0 ;
F_8 ( V_3 , V_26 , V_29 | V_28 ) ;
F_8 ( V_3 , V_14 , V_88 ) ;
V_3 -> V_163 = 0 ;
V_3 -> V_164 = 0 ;
if ( F_52 ( V_5 ) )
V_3 -> V_54 = NULL ;
if ( V_3 -> V_54 ) {
V_160 = F_53 ( V_3 ) ;
if ( V_160 ) {
F_54 ( V_5 -> V_33 ,
L_3 ) ;
V_3 -> V_54 = NULL ;
}
}
V_160 = F_55 ( V_5 -> V_157 , F_42 , V_165 ,
F_56 ( V_5 -> V_33 ) , V_5 ) ;
if ( V_160 < 0 )
goto V_166;
V_3 -> V_68 = V_167 | V_168 ;
F_8 ( V_3 , V_67 , V_3 -> V_68 ) ;
#ifdef F_57
V_3 -> V_169 |= V_170 ;
#endif
V_11 -> V_171 = V_172 ;
if ( V_11 -> V_51 & V_152 )
V_11 -> V_171 |= V_173 ;
F_8 ( V_3 , V_174 , V_11 -> V_171 ) ;
if ( V_3 -> V_54 )
V_3 -> V_54 -> V_175 ( V_3 ) ;
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_33 ) ;
return 0 ;
V_166:
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_33 ) ;
F_58 ( V_5 -> V_33 ) ;
return V_160 ;
}
static void F_59 ( struct V_8 * V_5 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
struct V_10 * V_11 = V_5 -> V_12 ;
F_60 ( & V_11 -> V_133 ) ;
if ( V_3 -> V_54 )
F_1 ( V_3 ) ;
F_24 ( V_5 -> V_33 ) ;
F_8 ( V_3 , V_174 , 0 ) ;
V_3 -> V_68 = 0 ;
F_8 ( V_3 , V_67 , 0 ) ;
if ( V_3 -> V_54 )
F_61 ( V_3 ) ;
if ( V_3 -> V_13 & V_176 )
F_8 ( V_3 , V_14 , V_3 -> V_13 & ~ V_176 ) ;
F_8 ( V_3 , V_26 , V_29 | V_28 ) ;
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_33 ) ;
F_62 ( V_5 -> V_157 , V_5 ) ;
F_58 ( V_5 -> V_33 ) ;
}
static void F_63 ( struct V_8 * V_5 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
unsigned long V_40 ;
F_24 ( V_5 -> V_33 ) ;
F_64 ( & V_5 -> V_97 , V_40 ) ;
V_3 -> V_68 &= ~ ( V_167 | V_168 ) ;
F_8 ( V_3 , V_67 , V_3 -> V_68 ) ;
F_65 ( & V_5 -> V_97 , V_40 ) ;
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_33 ) ;
}
static int F_66 ( struct V_8 * V_5 ,
struct V_177 * V_178 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
V_178 -> V_179 = F_67 ( V_178 -> V_179 , 100U ) ;
V_178 -> V_180 = F_67 ( V_178 -> V_180 , 100U ) ;
V_5 -> V_178 = * V_178 ;
if ( V_178 -> V_40 & V_181 ) {
int V_160 = F_68 ( V_3 ) ;
if ( V_160 ) {
V_178 -> V_40 &= ~ V_181 ;
V_5 -> V_178 . V_40 &= ~ V_181 ;
}
return V_160 ;
}
F_69 ( V_3 ) ;
return 0 ;
}
static void F_70 ( struct V_8 * V_5 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
unsigned long V_40 ;
F_24 ( V_5 -> V_33 ) ;
F_64 ( & V_5 -> V_97 , V_40 ) ;
V_3 -> V_68 |= V_167 | V_168 ;
F_8 ( V_3 , V_67 , V_3 -> V_68 ) ;
F_65 ( & V_5 -> V_97 , V_40 ) ;
F_30 ( V_5 -> V_33 ) ;
F_31 ( V_5 -> V_33 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_5 . V_12 ;
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_182 * V_182 = & V_2 -> V_5 . V_134 -> V_5 ;
struct V_183 V_134 ;
int V_184 ;
unsigned long V_40 ;
int V_160 ;
F_64 ( & V_11 -> V_185 , V_40 ) ;
if ( ! V_54 -> V_186 )
goto V_187;
V_54 -> V_186 = 0 ;
F_72 ( V_54 -> V_188 , V_54 -> V_189 , & V_134 ) ;
V_184 = V_54 -> V_190 - V_134 . V_191 ;
V_160 = F_73 ( V_182 , V_54 -> V_192 , V_184 ) ;
V_2 -> V_5 . V_193 . V_194 += V_160 ;
V_2 -> V_5 . V_193 . V_195 += V_184 - V_160 ;
V_187:
F_65 ( & V_11 -> V_185 , V_40 ) ;
F_74 ( V_182 ) ;
}
static void F_75 ( void * V_196 )
{
struct V_1 * V_2 = V_196 ;
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_183 V_134 ;
unsigned long V_40 ;
F_64 ( & V_2 -> V_5 . V_97 , V_40 ) ;
if ( F_72 ( V_54 -> V_188 , V_54 -> V_189 , & V_134 ) !=
V_197 ) {
F_65 ( & V_2 -> V_5 . V_97 , V_40 ) ;
return;
}
F_71 ( V_2 ) ;
F_76 ( V_2 ) ;
F_65 ( & V_2 -> V_5 . V_97 , V_40 ) ;
}
static void F_1 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_5 . V_12 ;
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_183 V_134 ;
unsigned long V_40 ;
int V_160 ;
F_64 ( & V_11 -> V_185 , V_40 ) ;
if ( ! V_54 -> V_186 ) {
F_65 ( & V_11 -> V_185 , V_40 ) ;
return;
}
V_160 = F_72 ( V_54 -> V_188 , V_54 -> V_189 , & V_134 ) ;
if ( V_160 == V_198 ) {
V_160 = F_77 ( V_54 -> V_188 ) ;
if ( F_78 ( V_160 ) )
V_11 -> V_199 = true ;
}
F_65 ( & V_11 -> V_185 , V_40 ) ;
F_71 ( V_2 ) ;
F_79 ( V_54 -> V_188 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_5 . V_12 ;
struct V_53 * V_54 = V_2 -> V_54 ;
int V_166 = 0 ;
struct V_200 * V_201 ;
unsigned long V_40 ;
if ( V_11 -> V_199 )
return - V_202 ;
F_64 ( & V_11 -> V_185 , V_40 ) ;
if ( V_54 -> V_186 )
goto V_203;
V_201 = F_80 ( V_54 -> V_188 , V_54 -> V_204 ,
V_54 -> V_190 , V_205 ,
V_206 | V_207 ) ;
if ( ! V_201 ) {
V_166 = - V_208 ;
goto V_203;
}
V_54 -> V_186 = 1 ;
V_201 -> V_209 = F_75 ;
V_201 -> V_210 = V_2 ;
V_54 -> V_189 = F_81 ( V_201 ) ;
F_82 ( V_54 -> V_188 ) ;
V_203:
F_65 ( & V_11 -> V_185 , V_40 ) ;
return V_166 ;
}
static void F_83 ( void * V_196 )
{
struct V_1 * V_2 = V_196 ;
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_211 * V_212 = & V_2 -> V_5 . V_134 -> V_212 ;
unsigned long V_40 ;
bool V_213 = false ;
struct V_10 * V_11 = V_2 -> V_5 . V_12 ;
F_84 ( V_54 -> V_214 -> V_215 -> V_33 , V_54 -> V_216 ,
V_217 , V_218 ) ;
F_64 ( & V_2 -> V_5 . V_97 , V_40 ) ;
V_54 -> V_55 = 0 ;
V_212 -> V_219 += V_54 -> V_220 ;
V_212 -> V_219 &= V_217 - 1 ;
V_2 -> V_5 . V_193 . V_221 += V_54 -> V_220 ;
if ( V_11 -> V_56 ) {
V_11 -> V_56 = 0 ;
F_16 ( V_2 ) ;
}
if ( F_85 ( V_212 ) < V_222 )
F_86 ( & V_2 -> V_5 ) ;
if ( ! F_87 ( V_212 ) && ! F_88 ( & V_2 -> V_5 ) ) {
int V_160 ;
V_160 = F_89 ( V_2 ) ;
if ( V_160 )
V_213 = true ;
} else if ( V_2 -> V_169 & V_170 ) {
V_213 = true ;
}
if ( V_213 ) {
V_54 -> V_223 = 1 ;
V_2 -> V_68 |= V_224 ;
F_90 ( & V_2 -> V_5 , V_67 , V_2 -> V_68 ) ;
}
F_65 ( & V_2 -> V_5 . V_97 , V_40 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_53 * V_54 = V_2 -> V_54 ;
struct V_10 * V_11 = V_2 -> V_5 . V_12 ;
struct V_211 * V_212 = & V_2 -> V_5 . V_134 -> V_212 ;
struct V_200 * V_201 ;
unsigned int V_225 = 0 ;
int V_160 ;
if ( V_54 -> V_55 )
return 0 ;
if ( F_88 ( & V_2 -> V_5 ) || F_87 ( V_212 ) ) {
if ( V_54 -> V_223 || V_2 -> V_169 & V_170 ) {
V_160 = - V_208 ;
goto V_166;
}
if ( V_2 -> V_68 & V_224 ) {
V_2 -> V_68 &= ~ V_224 ;
F_8 ( V_2 , V_67 , V_2 -> V_68 ) ;
}
return 0 ;
}
V_54 -> V_220 = F_91 ( V_212 -> V_226 , V_212 -> V_219 , V_217 ) ;
if ( V_11 -> V_51 & V_227 ) {
T_2 V_228 ;
V_228 = F_7 ( V_2 , V_229 ) ;
if ( V_228 == V_2 -> V_230 ) {
V_160 = - V_208 ;
goto V_166;
}
if ( V_54 -> V_220 < 4 ) {
V_160 = - V_202 ;
goto V_166;
}
V_225 = 1 ;
}
V_201 = F_80 ( V_54 -> V_214 ,
V_54 -> V_216 + V_212 -> V_219 + V_225 ,
V_54 -> V_220 - V_225 , V_231 ,
V_206 | V_207 ) ;
if ( ! V_201 ) {
V_160 = - V_208 ;
goto V_166;
}
V_54 -> V_55 = 1 ;
V_201 -> V_209 = F_83 ;
V_201 -> V_210 = V_2 ;
V_54 -> V_232 = F_81 ( V_201 ) ;
F_92 ( V_54 -> V_214 -> V_215 -> V_33 , V_54 -> V_216 ,
V_217 , V_218 ) ;
F_82 ( V_54 -> V_214 ) ;
if ( V_54 -> V_223 )
V_54 -> V_223 = 0 ;
if ( V_2 -> V_68 & V_224 ) {
V_2 -> V_68 &= ~ V_224 ;
F_8 ( V_2 , V_67 , V_2 -> V_68 ) ;
}
if ( V_225 )
F_8 ( V_2 , V_233 , V_212 -> V_234 [ V_212 -> V_219 ] ) ;
return 0 ;
V_166:
V_54 -> V_223 = 1 ;
return V_160 ;
}
static bool F_93 ( struct V_1 * V_3 , unsigned int V_159 )
{
switch ( V_159 & 0x3f ) {
case V_235 :
case V_236 :
case V_237 :
F_1 ( V_3 ) ;
return true ;
}
return F_76 ( V_3 ) ;
}
static int F_44 ( struct V_8 * V_5 )
{
struct V_1 * V_3 = F_5 ( V_5 ) ;
unsigned char V_17 ;
unsigned long V_40 ;
T_2 V_159 ;
F_46 ( V_3 ) ;
V_159 = F_47 ( V_5 , V_161 ) ;
if ( V_159 & V_238 ) {
F_49 ( V_3 ) ;
return 0 ;
}
F_64 ( & V_5 -> V_97 , V_40 ) ;
V_17 = F_47 ( V_5 , V_31 ) ;
if ( V_17 & ( V_32 | V_106 ) ) {
if ( F_93 ( V_3 , V_159 ) ) {
V_17 = F_94 ( V_3 , V_17 ) ;
F_76 ( V_3 ) ;
}
}
F_95 ( V_3 ) ;
if ( V_17 & V_30 && V_3 -> V_54 -> V_223 ) {
if ( F_88 ( & V_3 -> V_5 ) ||
F_87 ( & V_3 -> V_5 . V_134 -> V_212 ) ) {
V_3 -> V_54 -> V_223 = 0 ;
F_96 ( V_3 ) ;
} else {
if ( F_89 ( V_3 ) )
F_96 ( V_3 ) ;
}
}
F_65 ( & V_5 -> V_97 , V_40 ) ;
F_49 ( V_3 ) ;
return 1 ;
}
static bool F_97 ( struct V_239 * V_240 , void * V_196 )
{
return false ;
}
static inline int F_76 ( struct V_1 * V_2 )
{
return - V_202 ;
}
static int F_98 ( struct V_8 * V_5 )
{
F_99 ( 1 , L_4 ) ;
return 0 ;
}
static int F_100 ( struct V_241 * V_242 )
{
struct V_243 * V_244 = F_101 ( V_242 , V_245 , 0 ) ;
struct V_243 * V_157 = F_101 ( V_242 , V_246 , 0 ) ;
struct V_10 * V_11 ;
struct V_1 V_3 ;
int V_160 ;
void T_5 * V_6 ;
if ( ! V_244 || ! V_157 ) {
F_102 ( & V_242 -> V_33 , L_5 ) ;
return - V_202 ;
}
V_11 = F_103 ( & V_242 -> V_33 , sizeof( * V_11 ) , V_247 ) ;
if ( ! V_11 )
return - V_248 ;
V_6 = F_104 ( & V_242 -> V_33 , V_244 -> V_249 ,
F_105 ( V_244 ) ) ;
if ( ! V_6 )
return - V_250 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_5 . V_33 = & V_242 -> V_33 ;
V_3 . V_5 . V_251 = V_244 -> V_249 ;
V_3 . V_5 . V_6 = V_6 ;
V_3 . V_5 . V_157 = V_157 -> V_249 ;
V_3 . V_5 . type = V_252 ;
V_3 . V_5 . V_253 = V_254 ;
V_3 . V_5 . V_40 = V_255 | V_256 | V_127 |
V_125 ;
V_3 . V_5 . V_12 = V_11 ;
V_3 . V_5 . V_7 = 2 ;
V_3 . V_5 . V_257 = 64 ;
V_3 . V_230 = 64 ;
V_3 . V_169 = V_258 ;
#ifdef F_57
V_3 . V_169 |= V_170 ;
#endif
V_3 . V_5 . V_259 = F_22 ;
V_3 . V_5 . V_74 = F_4 ;
V_3 . V_5 . V_260 = F_35 ;
V_3 . V_5 . V_261 = F_50 ;
V_3 . V_5 . V_262 = F_59 ;
V_3 . V_5 . V_263 = F_63 ;
V_3 . V_5 . V_264 = F_70 ;
V_3 . V_5 . V_265 = F_66 ;
if ( V_242 -> V_33 . V_266 ) {
const struct V_267 * V_268 ;
V_160 = F_106 ( V_242 -> V_33 . V_266 , L_6 ) ;
F_107 ( V_242 -> V_33 . V_266 , L_7 ,
& V_3 . V_5 . V_35 ) ;
V_11 -> V_162 = F_108 ( V_242 -> V_33 . V_266 , 1 ) ;
V_268 = F_109 ( F_110 ( V_269 ) , & V_242 -> V_33 ) ;
if ( V_268 && V_268 -> V_270 )
V_11 -> V_51 |= * ( T_2 * ) V_268 -> V_270 ;
} else {
V_160 = V_242 -> V_268 ;
}
if ( V_160 < 0 ) {
F_102 ( & V_242 -> V_33 , L_8 ) ;
return V_160 ;
}
V_3 . V_5 . line = V_160 ;
if ( ! V_3 . V_5 . V_35 ) {
V_3 . V_5 . V_35 = V_271 ;
F_37 ( & V_242 -> V_33 ,
L_9 ,
V_271 ) ;
}
V_11 -> V_132 = V_272 ;
V_11 -> V_130 = V_272 ;
F_111 ( & V_11 -> V_156 , V_273 ,
V_11 -> V_132 ) ;
F_112 ( & V_11 -> V_133 , F_39 ) ;
F_113 ( & V_11 -> V_185 ) ;
F_114 ( & V_242 -> V_33 , true ) ;
F_115 ( & V_242 -> V_33 ) ;
F_116 ( & V_242 -> V_33 , - 1 ) ;
F_117 ( & V_242 -> V_33 ) ;
F_118 ( & V_242 -> V_33 ) ;
F_24 ( & V_242 -> V_33 ) ;
F_36 ( & V_3 , V_11 ) ;
V_3 . V_5 . V_274 = F_98 ;
#ifdef F_43
if ( V_242 -> V_33 . V_266 ) {
V_160 = F_119 ( V_242 -> V_33 . V_266 , L_10 ) ;
if ( V_160 == 2 ) {
V_3 . V_54 = & V_11 -> V_275 ;
V_11 -> V_275 . V_276 = F_97 ;
V_11 -> V_275 . V_277 = F_89 ;
V_11 -> V_275 . V_175 = F_76 ;
V_11 -> V_275 . V_190 = V_64 ;
V_11 -> V_275 . V_278 . V_279 = V_64 ;
V_11 -> V_275 . V_280 . V_281 = V_62 ;
}
}
#endif
V_160 = F_120 ( & V_3 ) ;
if ( V_160 < 0 ) {
F_102 ( & V_242 -> V_33 , L_11 ) ;
goto V_166;
}
V_11 -> line = V_160 ;
F_121 ( V_242 , V_11 ) ;
F_30 ( & V_242 -> V_33 ) ;
F_31 ( & V_242 -> V_33 ) ;
return 0 ;
V_166:
F_122 ( & V_242 -> V_33 ) ;
F_123 ( & V_242 -> V_33 ) ;
F_124 ( & V_242 -> V_33 ) ;
return V_160 ;
}
static int F_125 ( struct V_241 * V_242 )
{
struct V_10 * V_11 = F_126 ( V_242 ) ;
F_122 ( & V_242 -> V_33 ) ;
F_123 ( & V_242 -> V_33 ) ;
F_124 ( & V_242 -> V_33 ) ;
F_127 ( V_11 -> line ) ;
F_128 ( & V_11 -> V_156 ) ;
F_114 ( & V_242 -> V_33 , false ) ;
return 0 ;
}
static int F_129 ( struct V_215 * V_33 )
{
struct V_10 * V_11 = F_130 ( V_33 ) ;
if ( ! V_11 )
return 0 ;
V_11 -> V_282 = true ;
return 0 ;
}
static void F_131 ( struct V_215 * V_33 )
{
struct V_10 * V_11 = F_130 ( V_33 ) ;
if ( ! V_11 )
return;
V_11 -> V_282 = false ;
}
static int F_132 ( struct V_215 * V_33 )
{
struct V_10 * V_11 = F_130 ( V_33 ) ;
F_133 ( V_11 -> line ) ;
F_60 ( & V_11 -> V_133 ) ;
return 0 ;
}
static int F_134 ( struct V_215 * V_33 )
{
struct V_10 * V_11 = F_130 ( V_33 ) ;
F_135 ( V_11 -> line ) ;
return 0 ;
}
static int F_136 ( struct V_1 * V_3 )
{
T_1 V_283 ;
V_283 = F_7 ( V_3 , V_48 ) ;
if ( ! V_283 )
return 1 ;
return 0 ;
}
static int F_137 ( struct V_215 * V_33 )
{
struct V_10 * V_11 = F_130 ( V_33 ) ;
struct V_1 * V_3 = F_138 ( V_11 -> line ) ;
int V_22 = 100 ;
int V_284 ;
int V_285 ;
V_284 = F_7 ( V_3 , V_286 ) ;
V_284 |= V_287 ;
F_8 ( V_3 , V_286 , V_284 ) ;
do {
F_10 ( 1 ) ;
V_285 = F_7 ( V_3 , V_288 ) ;
} while ( -- V_22 && ! ( V_285 & V_289 ) );
if ( ! V_22 ) {
F_102 ( V_33 , L_12 ) ;
return - V_290 ;
}
return 0 ;
}
static int F_139 ( struct V_215 * V_33 )
{
struct V_10 * V_11 = F_130 ( V_33 ) ;
struct V_1 * V_3 ;
if ( ! V_11 )
return 0 ;
V_3 = F_138 ( V_11 -> line ) ;
if ( V_11 -> V_282 && ! V_291 ) {
if ( F_52 ( & V_3 -> V_5 ) )
return - V_208 ;
}
if ( V_11 -> V_51 & V_292 ) {
int V_160 ;
V_160 = F_137 ( V_33 ) ;
if ( V_160 )
return V_160 ;
F_15 ( V_3 , V_11 ) ;
}
if ( V_3 -> V_54 && V_3 -> V_54 -> V_188 )
F_1 ( V_3 ) ;
V_11 -> V_132 = V_272 ;
F_32 ( & V_11 -> V_133 ) ;
return 0 ;
}
static int F_140 ( struct V_215 * V_33 )
{
struct V_10 * V_11 = F_130 ( V_33 ) ;
struct V_1 * V_3 ;
if ( ! V_11 )
return 0 ;
V_3 = F_138 ( V_11 -> line ) ;
if ( F_136 ( V_3 ) )
F_16 ( V_3 ) ;
if ( V_3 -> V_54 && V_3 -> V_54 -> V_188 )
F_76 ( V_3 ) ;
V_11 -> V_132 = V_11 -> V_130 ;
F_32 ( & V_11 -> V_133 ) ;
return 0 ;
}
static int T_6 F_141 ( void )
{
char * V_293 ;
char * V_294 ;
T_2 V_295 ;
if ( strstr ( V_296 , L_13 ) )
return 0 ;
V_293 = strstr ( V_296 , L_14 ) ;
if ( ! V_293 )
return 0 ;
V_293 += 12 ;
if ( '0' <= * V_293 && * V_293 <= '9' )
V_295 = * V_293 - '0' ;
else
return 0 ;
V_293 ++ ;
if ( V_293 [ 0 ] == ',' ) {
V_293 ++ ;
V_294 = V_293 ;
} else {
V_294 = NULL ;
}
F_142 ( L_15 , V_295 , V_294 ) ;
F_143 ( L_16 ,
V_295 , V_295 ) ;
F_143 ( L_17 ) ;
F_143 ( L_18 ) ;
return 0 ;
}
