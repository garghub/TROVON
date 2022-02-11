static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 ;
if ( ! F_3 ( V_4 -> V_6 ) )
return - V_7 ;
V_5 = F_4 ( V_4 -> V_6 ) ;
if ( V_4 -> V_8 )
V_5 = ! V_5 ;
return V_5 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ( F_6 ( V_4 -> V_9 + F_7 ( V_4 ) ) &
V_10 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
T_1 V_11 , V_12 ;
F_9 ( V_4 -> V_9 ) ;
V_11 = V_13 ;
V_12 = F_10 ( 0x3 , V_14 ) |
F_10 ( 0x7 , V_15 ) |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 ;
F_11 ( F_10 ( 0xffff , V_23 ) |
F_10 ( 2 , V_24 ) |
F_10 ( 0 , V_25 ) ,
V_4 -> V_9 + F_12 ( V_4 ) ) ;
if ( V_4 -> V_26 ) {
V_11 |= V_27 ;
V_12 |= V_28 ;
}
F_11 ( V_11 , V_4 -> V_9 + V_29 ) ;
F_11 ( V_12 , V_4 -> V_9 + F_13 ( V_4 ) ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_35 ;
if ( F_15 ( V_31 ) & V_36 ) {
if ( F_15 ( V_31 ) & V_37 ) {
V_31 -> V_38 [ 3 ] = F_6 ( V_4 -> V_9 + F_16 ( V_4 ) ) ;
V_31 -> V_38 [ 2 ] = F_6 ( V_4 -> V_9 + F_17 ( V_4 ) ) ;
V_31 -> V_38 [ 1 ] = F_6 ( V_4 -> V_9 + F_18 ( V_4 ) ) ;
V_31 -> V_38 [ 0 ] = F_6 ( V_4 -> V_9 + F_19 ( V_4 ) ) ;
} else {
V_31 -> V_38 [ 0 ] = F_6 ( V_4 -> V_9 + F_16 ( V_4 ) ) ;
}
}
if ( V_33 ) {
F_20 ( F_21 ( V_4 -> V_2 ) , V_33 -> V_39 ,
V_33 -> V_40 , V_4 -> V_41 ) ;
if ( ! V_33 -> error )
V_33 -> V_42 = V_33 -> V_43 * V_33 -> V_44 ;
else
V_33 -> V_42 = 0 ;
V_4 -> V_33 = NULL ;
if ( V_35 -> V_45 ) {
F_22 ( V_4 , V_35 -> V_45 ) ;
return;
}
}
V_4 -> V_35 = NULL ;
F_23 ( V_4 -> V_2 , V_35 ) ;
}
static void F_24 ( void * V_46 )
{
struct V_3 * V_4 = V_46 ;
F_14 ( V_4 ) ;
}
static T_2 F_25 ( int V_47 , void * V_48 )
{
struct V_3 * V_4 = V_48 ;
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_33 ;
T_1 V_49 ;
F_26 ( & V_4 -> V_50 ) ;
V_49 = F_6 ( V_4 -> V_9 + F_13 ( V_4 ) ) ;
F_11 ( V_49 & V_51 ,
V_4 -> V_9 + F_13 ( V_4 ) + V_52 ) ;
F_27 ( & V_4 -> V_50 ) ;
if ( ( V_49 & V_53 ) && ( V_49 & V_28 ) )
F_28 ( V_4 -> V_2 ) ;
if ( V_49 & V_54 )
V_31 -> error = - V_55 ;
else if ( V_49 & V_56 )
V_31 -> error = - V_57 ;
if ( V_33 ) {
if ( V_49 & ( V_58 |
V_59 ) )
V_33 -> error = - V_55 ;
else if ( V_49 & V_60 )
V_33 -> error = - V_61 ;
else if ( V_49 & ( V_62 |
V_63 ) )
V_33 -> error = - V_57 ;
}
return V_64 ;
}
static struct V_65 * F_29 (
struct V_3 * V_4 , unsigned long V_66 )
{
struct V_65 * V_67 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_68 * V_69 ;
unsigned int V_40 ;
if ( V_33 ) {
F_30 ( F_21 ( V_4 -> V_2 ) , V_33 -> V_39 ,
V_33 -> V_40 , V_4 -> V_41 ) ;
V_69 = V_33 -> V_39 ;
V_40 = V_33 -> V_40 ;
} else {
V_69 = (struct V_68 * ) V_4 -> V_70 ;
V_40 = V_71 ;
}
V_67 = F_31 ( V_4 -> V_72 ,
V_69 , V_40 , V_4 -> V_73 , V_66 ) ;
if ( V_67 ) {
V_67 -> V_74 = F_24 ;
V_67 -> V_75 = V_4 ;
} else {
if ( V_33 )
F_20 ( F_21 ( V_4 -> V_2 ) , V_33 -> V_39 ,
V_33 -> V_40 , V_4 -> V_41 ) ;
}
return V_67 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_65 * V_67 ;
T_1 V_11 , V_76 , V_77 ;
V_11 = V_78 | V_13 ;
V_76 = F_10 ( V_31 -> V_79 , V_80 ) | V_81 ;
V_77 = V_31 -> V_82 ;
if ( V_4 -> V_26 ) {
V_11 |= V_27 ;
V_76 |= V_83 | V_84 ;
}
V_4 -> V_70 [ 0 ] = V_11 ;
V_4 -> V_70 [ 1 ] = V_76 ;
V_4 -> V_70 [ 2 ] = V_77 ;
V_4 -> V_41 = V_85 ;
V_4 -> V_73 = V_86 ;
V_67 = F_29 ( V_4 , V_87 ) ;
if ( ! V_67 )
goto V_88;
F_33 ( V_67 ) ;
F_34 ( V_4 -> V_72 ) ;
return;
V_88:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_89 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_65 * V_67 ;
T_1 V_90 , V_91 , V_92 ;
T_1 V_11 , V_76 , V_77 ;
V_90 = ( F_15 ( V_31 ) & V_93 ) ?
0 : V_13 ;
V_91 = ( F_15 ( V_31 ) & V_36 ) ?
V_94 : 0 ;
V_92 = ( F_15 ( V_31 ) & V_37 ) ?
V_95 : 0 ;
V_11 = V_78 | V_90 | V_91 | V_92 ;
V_76 = F_10 ( V_31 -> V_79 , V_80 ) ;
V_77 = V_31 -> V_82 ;
if ( V_4 -> V_26 ) {
V_11 |= V_27 ;
V_76 |= V_83 | V_84 ;
}
V_4 -> V_70 [ 0 ] = V_11 ;
V_4 -> V_70 [ 1 ] = V_76 ;
V_4 -> V_70 [ 2 ] = V_77 ;
V_4 -> V_41 = V_85 ;
V_4 -> V_73 = V_86 ;
V_67 = F_29 ( V_4 , V_87 ) ;
if ( ! V_67 )
goto V_88;
F_33 ( V_67 ) ;
F_34 ( V_4 -> V_72 ) ;
return;
V_88:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_89 ) ;
}
static unsigned short F_37 ( unsigned V_96 , unsigned V_97 )
{
const unsigned int V_98 = 4096 ;
const unsigned int V_99 = V_96 / 1000 ;
const unsigned int V_100 = V_97 / 1000 ;
const unsigned int V_101 = V_100 * V_99 ;
const unsigned int V_102 = V_101 / V_98 ;
F_38 ( V_102 == 0 ) ;
return V_102 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_32 * V_33 = V_31 -> V_33 ;
struct V_65 * V_67 ;
struct V_68 * V_69 = V_33 -> V_39 , * V_39 ;
unsigned int V_40 = V_33 -> V_40 ;
int V_103 ;
unsigned short V_104 , V_105 ;
enum V_106 V_73 ;
unsigned int V_107 = 0 , V_108 ;
unsigned int V_43 = V_33 -> V_43 ;
T_1 V_90 , V_91 , V_92 , V_109 ;
T_1 V_11 , V_76 , V_77 , V_110 ;
V_90 = ( F_15 ( V_31 ) & V_93 ) ?
0 : V_13 ;
V_91 = ( F_15 ( V_31 ) & V_36 ) ?
V_94 : 0 ;
V_92 = ( F_15 ( V_31 ) & V_37 ) ?
V_95 : 0 ;
if ( V_33 -> V_66 & V_111 ) {
V_104 = V_112 ;
V_73 = V_113 ;
V_109 = 0 ;
} else {
V_104 = V_114 ;
V_73 = V_115 ;
V_109 = V_116 ;
}
V_11 = F_10 ( V_4 -> V_117 , V_118 ) |
V_90 | V_91 | V_92 |
V_119 | V_109 |
V_120 |
V_78 ;
V_76 = F_10 ( V_31 -> V_79 , V_80 ) ;
V_108 = F_40 ( V_33 -> V_44 ) ;
F_41 (sgl, sg, sg_len, i)
V_107 += V_39 -> V_121 ;
if ( V_107 != V_33 -> V_43 * V_33 -> V_44 )
V_43 = 1 ;
if ( F_42 ( V_4 ) ) {
V_11 |= F_10 ( V_107 , V_122 ) ;
V_76 |= F_10 ( V_108 , V_123 ) |
F_10 ( V_43 - 1 , V_124 ) ;
} else {
F_11 ( V_107 , V_4 -> V_9 + V_125 ) ;
F_11 ( F_10 ( V_108 , V_126 ) |
F_10 ( V_43 - 1 , V_127 ) ,
V_4 -> V_9 + V_128 ) ;
}
if ( ( V_31 -> V_79 == V_129 ) ||
( V_31 -> V_79 == V_130 ) )
V_76 |= V_81 ;
V_77 = V_31 -> V_82 ;
if ( V_4 -> V_26 ) {
V_11 |= V_27 ;
V_76 |= V_83 | V_84 ;
}
V_105 = F_37 ( V_4 -> V_131 , V_33 -> V_132 ) ;
V_110 = F_6 ( V_4 -> V_9 + F_12 ( V_4 ) ) ;
V_110 &= ~ ( V_133 ) ;
V_110 |= F_10 ( V_105 , V_23 ) ;
F_11 ( V_110 , V_4 -> V_9 + F_12 ( V_4 ) ) ;
V_4 -> V_70 [ 0 ] = V_11 ;
V_4 -> V_70 [ 1 ] = V_76 ;
V_4 -> V_70 [ 2 ] = V_77 ;
V_4 -> V_41 = V_85 ;
V_4 -> V_73 = V_86 ;
V_67 = F_29 ( V_4 , 0 ) ;
if ( ! V_67 )
goto V_88;
F_38 ( V_4 -> V_33 != NULL ) ;
V_4 -> V_33 = V_33 ;
V_4 -> V_41 = V_104 ;
V_4 -> V_73 = V_73 ;
V_67 = F_29 ( V_4 , V_134 | V_87 ) ;
if ( ! V_67 )
goto V_88;
F_33 ( V_67 ) ;
F_34 ( V_4 -> V_72 ) ;
return;
V_88:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_89 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_30 * V_31 )
{
V_4 -> V_31 = V_31 ;
switch ( F_43 ( V_31 ) ) {
case V_135 :
F_32 ( V_4 ) ;
break;
case V_136 :
F_36 ( V_4 ) ;
break;
case V_137 :
F_36 ( V_4 ) ;
break;
case V_138 :
F_39 ( V_4 ) ;
break;
default:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_2 , V_89 ) ;
break;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_4 -> V_35 != NULL ) ;
V_4 -> V_35 = V_35 ;
F_22 ( V_4 , V_35 -> V_31 ) ;
}
static void F_45 ( struct V_3 * V_4 , unsigned int V_139 )
{
unsigned int V_140 , V_141 ;
T_1 V_142 , V_96 ;
T_1 V_110 ;
V_140 = F_46 ( V_4 -> V_143 ) ;
for ( V_142 = 2 ; V_142 <= 254 ; V_142 += 2 ) {
V_96 = F_47 ( V_140 , V_139 * V_142 ) ;
V_96 = ( V_96 > 0 ) ? V_96 - 1 : 0 ;
if ( V_96 <= 255 )
break;
}
if ( V_142 > 254 ) {
F_48 ( F_21 ( V_4 -> V_2 ) ,
L_3 , V_89 , V_139 ) ;
return;
}
V_141 = V_140 / V_142 / ( 1 + V_96 ) ;
V_110 = F_6 ( V_4 -> V_9 + F_12 ( V_4 ) ) ;
V_110 &= ~ ( V_144 | V_145 ) ;
V_110 |= F_10 ( V_142 , V_24 ) ;
V_110 |= F_10 ( V_96 , V_25 ) ;
F_11 ( V_110 , V_4 -> V_9 + F_12 ( V_4 ) ) ;
V_4 -> V_131 = V_141 ;
F_49 ( F_21 ( V_4 -> V_2 ) ,
L_4 ,
V_89 , V_142 , V_96 , V_140 , V_141 , V_139 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_147 -> V_117 == V_148 )
V_4 -> V_117 = 2 ;
else if ( V_147 -> V_117 == V_149 )
V_4 -> V_117 = 1 ;
else
V_4 -> V_117 = 0 ;
if ( V_147 -> clock )
F_45 ( V_4 , V_147 -> clock ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_150 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_66 ;
F_52 ( & V_4 -> V_50 , V_66 ) ;
V_4 -> V_26 = V_150 ;
if ( V_150 ) {
F_11 ( V_27 ,
V_4 -> V_9 + V_29 + V_151 ) ;
F_11 ( V_28 ,
V_4 -> V_9 + F_13 ( V_4 ) + V_151 ) ;
} else {
F_11 ( V_27 ,
V_4 -> V_9 + V_29 + V_52 ) ;
F_11 ( V_28 ,
V_4 -> V_9 + F_13 ( V_4 ) + V_52 ) ;
}
F_53 ( & V_4 -> V_50 , V_66 ) ;
if ( V_150 && F_6 ( V_4 -> V_9 + F_7 ( V_4 ) ) &
V_152 )
F_28 ( V_4 -> V_2 ) ;
}
static bool F_54 ( struct V_153 * V_154 , void * V_46 )
{
struct V_3 * V_4 = V_46 ;
if ( ! F_55 ( V_154 ) )
return false ;
if ( V_154 -> V_155 != V_4 -> V_156 )
return false ;
V_154 -> V_157 = & V_4 -> V_158 ;
return true ;
}
static int F_56 ( struct V_159 * V_160 )
{
const struct V_161 * V_162 =
F_57 ( V_163 , & V_160 -> V_164 ) ;
struct V_165 * V_166 = V_160 -> V_164 . V_167 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_168 * V_169 , * V_170 ;
struct V_171 * V_172 ;
struct V_173 * V_173 ;
int V_5 = 0 , V_174 , V_175 ;
T_3 V_176 ;
struct V_177 * V_178 ;
enum V_179 V_66 ;
V_169 = F_58 ( V_160 , V_180 , 0 ) ;
V_170 = F_58 ( V_160 , V_181 , 0 ) ;
V_174 = F_59 ( V_160 , 0 ) ;
V_175 = F_59 ( V_160 , 1 ) ;
if ( ! V_169 || V_174 < 0 || V_175 < 0 )
return - V_7 ;
V_2 = F_60 ( sizeof( struct V_3 ) , & V_160 -> V_164 ) ;
if ( ! V_2 )
return - V_182 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_9 = F_61 ( & V_160 -> V_164 , V_169 ) ;
if ( ! V_4 -> V_9 ) {
V_5 = - V_183 ;
goto V_184;
}
if ( V_166 ) {
V_4 -> V_185 = (enum V_186 ) V_162 -> V_33 ;
V_5 = F_62 ( V_166 , L_5 ,
& V_4 -> V_156 ) ;
if ( V_5 ) {
F_48 ( F_21 ( V_4 -> V_2 ) ,
L_6 ) ;
goto V_184;
}
} else {
V_4 -> V_185 = V_160 -> V_187 -> V_188 ;
V_4 -> V_156 = V_170 -> V_189 ;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_26 = 0 ;
V_178 = F_63 ( & V_160 -> V_164 , L_7 ) ;
if ( ! F_64 ( V_178 ) ) {
V_5 = F_65 ( V_178 ) ;
if ( V_5 ) {
F_48 ( & V_160 -> V_164 ,
L_8 , V_5 ) ;
goto V_184;
}
}
V_173 = F_66 ( & V_160 -> V_164 ) ;
if ( F_64 ( V_173 ) ) {
V_5 = F_67 ( V_173 ) ;
goto V_184;
}
V_4 -> V_143 = F_68 ( & V_160 -> V_164 , NULL ) ;
if ( F_64 ( V_4 -> V_143 ) ) {
V_5 = F_67 ( V_4 -> V_143 ) ;
goto V_184;
}
F_69 ( V_4 -> V_143 ) ;
F_8 ( V_4 ) ;
F_70 ( V_176 ) ;
F_71 ( V_190 , V_176 ) ;
V_4 -> V_158 . V_191 = V_175 ;
V_4 -> V_72 = F_72 ( V_176 , F_54 , V_4 ) ;
if ( ! V_4 -> V_72 ) {
F_48 ( F_21 ( V_4 -> V_2 ) ,
L_9 , V_89 ) ;
goto V_192;
}
V_2 -> V_193 = & V_194 ;
V_2 -> V_195 = V_196 | V_197 |
V_198 | V_199 ;
V_172 = F_21 ( V_4 -> V_2 ) -> V_200 ;
if ( ! V_172 ) {
T_1 V_117 = 0 ;
F_62 ( V_166 , L_10 , & V_117 ) ;
if ( V_117 == 4 )
V_2 -> V_195 |= V_201 ;
else if ( V_117 == 8 )
V_2 -> V_195 |= V_201 | V_202 ;
V_4 -> V_6 = F_73 ( V_166 , L_11 , 0 ,
& V_66 ) ;
if ( V_66 & V_203 )
V_4 -> V_8 = 1 ;
} else {
if ( V_172 -> V_66 & V_204 )
V_2 -> V_195 |= V_201 | V_202 ;
if ( V_172 -> V_66 & V_205 )
V_2 -> V_195 |= V_201 ;
V_4 -> V_6 = V_172 -> V_6 ;
}
V_2 -> V_206 = 400000 ;
V_2 -> V_207 = 288000000 ;
V_2 -> V_208 = V_209 | V_210 ;
V_2 -> V_211 = 52 ;
V_2 -> V_212 = 1 << 0xf ;
V_2 -> V_213 = ( F_42 ( V_4 ) ) ? 0xff : 0xffffff ;
V_2 -> V_214 = ( F_42 ( V_4 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_215 = F_74 ( V_4 -> V_72 -> V_216 -> V_164 ) ;
F_75 ( V_160 , V_2 ) ;
V_5 = F_76 ( & V_160 -> V_164 , V_174 , F_25 , 0 ,
V_217 , V_4 ) ;
if ( V_5 )
goto V_218;
F_77 ( & V_4 -> V_50 ) ;
V_5 = F_78 ( V_2 ) ;
if ( V_5 )
goto V_218;
F_79 ( F_21 ( V_4 -> V_2 ) , L_12 ) ;
return 0 ;
V_218:
if ( V_4 -> V_72 )
F_80 ( V_4 -> V_72 ) ;
V_192:
F_81 ( V_4 -> V_143 ) ;
F_82 ( V_4 -> V_143 ) ;
V_184:
F_83 ( V_2 ) ;
return V_5 ;
}
static int F_84 ( struct V_159 * V_160 )
{
struct V_1 * V_2 = F_85 ( V_160 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_86 ( V_2 ) ;
F_75 ( V_160 , NULL ) ;
if ( V_4 -> V_72 )
F_80 ( V_4 -> V_72 ) ;
F_81 ( V_4 -> V_143 ) ;
F_82 ( V_4 -> V_143 ) ;
F_83 ( V_2 ) ;
return 0 ;
}
static int F_87 ( struct V_216 * V_164 )
{
struct V_1 * V_2 = F_88 ( V_164 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
V_5 = F_89 ( V_2 ) ;
F_81 ( V_4 -> V_143 ) ;
return V_5 ;
}
static int F_90 ( struct V_216 * V_164 )
{
struct V_1 * V_2 = F_88 ( V_164 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
F_69 ( V_4 -> V_143 ) ;
V_5 = F_91 ( V_2 ) ;
return V_5 ;
}
