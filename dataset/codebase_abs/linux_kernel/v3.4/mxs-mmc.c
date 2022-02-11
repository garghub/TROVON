static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 =
F_3 ( V_4 -> V_2 ) -> V_7 ;
if ( ! V_6 )
return - V_8 ;
if ( ! F_4 ( V_6 -> V_9 ) )
return - V_10 ;
return F_5 ( V_6 -> V_9 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ( F_7 ( V_4 -> V_11 + V_12 ) &
V_13 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
T_1 V_14 , V_15 ;
F_9 ( V_4 -> V_11 ) ;
V_14 = V_16 ;
V_15 = F_10 ( 0x3 , V_17 ) |
F_10 ( 0x7 , V_18 ) |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 |
V_25 ;
F_11 ( F_10 ( 0xffff , V_26 ) |
F_10 ( 2 , V_27 ) |
F_10 ( 0 , V_28 ) ,
V_4 -> V_11 + V_29 ) ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_15 |= V_32 ;
}
F_11 ( V_14 , V_4 -> V_11 + V_33 ) ;
F_11 ( V_15 , V_4 -> V_11 + V_34 ) ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_4 -> V_38 ;
struct V_39 * V_40 = V_4 -> V_40 ;
if ( F_13 ( V_36 ) & V_41 ) {
if ( F_13 ( V_36 ) & V_42 ) {
V_36 -> V_43 [ 3 ] = F_7 ( V_4 -> V_11 + V_44 ) ;
V_36 -> V_43 [ 2 ] = F_7 ( V_4 -> V_11 + V_45 ) ;
V_36 -> V_43 [ 1 ] = F_7 ( V_4 -> V_11 + V_46 ) ;
V_36 -> V_43 [ 0 ] = F_7 ( V_4 -> V_11 + V_47 ) ;
} else {
V_36 -> V_43 [ 0 ] = F_7 ( V_4 -> V_11 + V_44 ) ;
}
}
if ( V_38 ) {
F_14 ( F_3 ( V_4 -> V_2 ) , V_38 -> V_48 ,
V_38 -> V_49 , V_4 -> V_50 ) ;
if ( ! V_38 -> error )
V_38 -> V_51 = V_38 -> V_52 * V_38 -> V_53 ;
else
V_38 -> V_51 = 0 ;
V_4 -> V_38 = NULL ;
if ( V_40 -> V_54 ) {
F_15 ( V_4 , V_40 -> V_54 ) ;
return;
}
}
V_4 -> V_40 = NULL ;
F_16 ( V_4 -> V_2 , V_40 ) ;
}
static void F_17 ( void * V_55 )
{
struct V_3 * V_4 = V_55 ;
F_12 ( V_4 ) ;
}
static T_2 F_18 ( int V_56 , void * V_57 )
{
struct V_3 * V_4 = V_57 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_4 -> V_38 ;
T_1 V_58 ;
F_19 ( & V_4 -> V_59 ) ;
V_58 = F_7 ( V_4 -> V_11 + V_34 ) ;
F_11 ( V_58 & V_60 ,
V_4 -> V_11 + V_34 + V_61 ) ;
if ( ( V_58 & V_62 ) && ( V_58 & V_32 ) )
F_20 ( V_4 -> V_2 ) ;
F_21 ( & V_4 -> V_59 ) ;
if ( V_58 & V_63 )
V_36 -> error = - V_64 ;
else if ( V_58 & V_65 )
V_36 -> error = - V_66 ;
if ( V_38 ) {
if ( V_58 & ( V_67 |
V_68 ) )
V_38 -> error = - V_64 ;
else if ( V_58 & V_69 )
V_38 -> error = - V_70 ;
else if ( V_58 & ( V_71 |
V_72 ) )
V_38 -> error = - V_66 ;
}
return V_73 ;
}
static struct V_74 * F_22 (
struct V_3 * V_4 , unsigned long V_75 )
{
struct V_74 * V_76 ;
struct V_37 * V_38 = V_4 -> V_38 ;
struct V_77 * V_78 ;
unsigned int V_49 ;
if ( V_38 ) {
F_23 ( F_3 ( V_4 -> V_2 ) , V_38 -> V_48 ,
V_38 -> V_49 , V_4 -> V_50 ) ;
V_78 = V_38 -> V_48 ;
V_49 = V_38 -> V_49 ;
} else {
V_78 = (struct V_77 * ) V_4 -> V_79 ;
V_49 = V_80 ;
}
V_76 = F_24 ( V_4 -> V_81 ,
V_78 , V_49 , V_4 -> V_82 , V_75 ) ;
if ( V_76 ) {
V_76 -> V_83 = F_17 ;
V_76 -> V_84 = V_4 ;
} else {
if ( V_38 )
F_14 ( F_3 ( V_4 -> V_2 ) , V_38 -> V_48 ,
V_38 -> V_49 , V_4 -> V_50 ) ;
}
return V_76 ;
}
static void F_25 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_74 * V_76 ;
T_1 V_14 , V_85 , V_86 ;
V_14 = V_87 | V_16 ;
V_85 = F_10 ( V_36 -> V_88 , V_89 ) | V_90 ;
V_86 = V_36 -> V_91 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_85 |= V_92 | V_93 ;
}
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_85 ;
V_4 -> V_79 [ 2 ] = V_86 ;
V_4 -> V_50 = V_94 ;
V_4 -> V_82 = V_95 ;
V_76 = F_22 ( V_4 , V_96 ) ;
if ( ! V_76 )
goto V_97;
F_26 ( V_76 ) ;
F_27 ( V_4 -> V_81 ) ;
return;
V_97:
F_28 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_98 ) ;
}
static void F_29 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_74 * V_76 ;
T_1 V_99 , V_100 , V_101 ;
T_1 V_14 , V_85 , V_86 ;
V_99 = ( F_13 ( V_36 ) & V_102 ) ?
0 : V_16 ;
V_100 = ( F_13 ( V_36 ) & V_41 ) ?
V_103 : 0 ;
V_101 = ( F_13 ( V_36 ) & V_42 ) ?
V_104 : 0 ;
V_14 = V_87 | V_99 | V_100 | V_101 ;
V_85 = F_10 ( V_36 -> V_88 , V_89 ) ;
V_86 = V_36 -> V_91 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_85 |= V_92 | V_93 ;
}
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_85 ;
V_4 -> V_79 [ 2 ] = V_86 ;
V_4 -> V_50 = V_94 ;
V_4 -> V_82 = V_95 ;
V_76 = F_22 ( V_4 , V_96 ) ;
if ( ! V_76 )
goto V_97;
F_26 ( V_76 ) ;
F_27 ( V_4 -> V_81 ) ;
return;
V_97:
F_28 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_98 ) ;
}
static unsigned short F_30 ( unsigned V_105 , unsigned V_106 )
{
const unsigned int V_107 = 4096 ;
const unsigned int V_108 = V_105 / 1000 ;
const unsigned int V_109 = V_106 / 1000 ;
const unsigned int V_110 = V_109 * V_108 ;
const unsigned int V_111 = V_110 / V_107 ;
F_31 ( V_111 == 0 ) ;
return V_111 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_38 ;
struct V_74 * V_76 ;
struct V_77 * V_78 = V_38 -> V_48 , * V_48 ;
unsigned int V_49 = V_38 -> V_49 ;
int V_112 ;
unsigned short V_113 , V_114 ;
enum V_115 V_82 ;
unsigned int V_116 = 0 , V_117 ;
unsigned int V_52 = V_38 -> V_52 ;
T_1 V_99 , V_100 , V_101 , V_118 ;
T_1 V_14 , V_85 , V_86 , V_119 ;
V_99 = ( F_13 ( V_36 ) & V_102 ) ?
0 : V_16 ;
V_100 = ( F_13 ( V_36 ) & V_41 ) ?
V_103 : 0 ;
V_101 = ( F_13 ( V_36 ) & V_42 ) ?
V_104 : 0 ;
if ( V_38 -> V_75 & V_120 ) {
V_113 = V_121 ;
V_82 = V_122 ;
V_118 = 0 ;
} else {
V_113 = V_123 ;
V_82 = V_124 ;
V_118 = V_125 ;
}
V_14 = F_10 ( V_4 -> V_126 , V_127 ) |
V_99 | V_100 | V_101 |
V_128 | V_118 |
V_129 |
V_87 ;
V_85 = F_10 ( V_36 -> V_88 , V_89 ) ;
V_117 = F_33 ( V_38 -> V_53 ) ;
F_34 (sgl, sg, sg_len, i)
V_116 += V_48 -> V_130 ;
if ( V_116 != V_38 -> V_52 * V_38 -> V_53 )
V_52 = 1 ;
if ( F_35 () ) {
V_14 |= F_10 ( V_116 , V_131 ) ;
V_85 |= F_10 ( V_117 , V_132 ) |
F_10 ( V_52 - 1 , V_133 ) ;
} else {
F_11 ( V_116 , V_4 -> V_11 + V_134 ) ;
F_11 ( F_10 ( V_117 , V_135 ) |
F_10 ( V_52 - 1 , V_136 ) ,
V_4 -> V_11 + V_137 ) ;
}
if ( ( V_36 -> V_88 == V_138 ) ||
( V_36 -> V_88 == V_139 ) )
V_85 |= V_90 ;
V_86 = V_36 -> V_91 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_85 |= V_92 | V_93 ;
}
V_114 = F_30 ( V_4 -> V_140 , V_38 -> V_141 ) ;
V_119 = F_7 ( V_4 -> V_11 + V_29 ) ;
V_119 &= ~ ( V_142 ) ;
V_119 |= F_10 ( V_114 , V_26 ) ;
F_11 ( V_119 , V_4 -> V_11 + V_29 ) ;
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_85 ;
V_4 -> V_79 [ 2 ] = V_86 ;
V_4 -> V_50 = V_94 ;
V_4 -> V_82 = V_95 ;
V_76 = F_22 ( V_4 , 0 ) ;
if ( ! V_76 )
goto V_97;
F_31 ( V_4 -> V_38 != NULL ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_50 = V_113 ;
V_4 -> V_82 = V_82 ;
V_76 = F_22 ( V_4 , V_143 | V_96 ) ;
if ( ! V_76 )
goto V_97;
F_26 ( V_76 ) ;
F_27 ( V_4 -> V_81 ) ;
return;
V_97:
F_28 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_98 ) ;
}
static void F_15 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
V_4 -> V_36 = V_36 ;
switch ( F_36 ( V_36 ) ) {
case V_144 :
F_25 ( V_4 ) ;
break;
case V_145 :
F_29 ( V_4 ) ;
break;
case V_146 :
F_29 ( V_4 ) ;
break;
case V_147 :
F_32 ( V_4 ) ;
break;
default:
F_28 ( F_3 ( V_4 -> V_2 ) ,
L_2 , V_98 ) ;
break;
}
}
static void F_37 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_31 ( V_4 -> V_40 != NULL ) ;
V_4 -> V_40 = V_40 ;
F_15 ( V_4 , V_40 -> V_36 ) ;
}
static void F_38 ( struct V_3 * V_4 , unsigned int V_148 )
{
unsigned int V_149 , V_150 ;
T_1 V_151 , V_105 ;
T_1 V_119 ;
V_149 = F_39 ( V_4 -> V_152 ) ;
for ( V_151 = 2 ; V_151 <= 254 ; V_151 += 2 ) {
V_105 = F_40 ( V_149 , V_148 * V_151 ) ;
V_105 = ( V_105 > 0 ) ? V_105 - 1 : 0 ;
if ( V_105 <= 255 )
break;
}
if ( V_151 > 254 ) {
F_41 ( F_3 ( V_4 -> V_2 ) ,
L_3 , V_98 , V_148 ) ;
return;
}
V_150 = V_149 / V_151 / ( 1 + V_105 ) ;
V_119 = F_7 ( V_4 -> V_11 + V_29 ) ;
V_119 &= ~ ( V_153 | V_154 ) ;
V_119 |= F_10 ( V_151 , V_27 ) ;
V_119 |= F_10 ( V_105 , V_28 ) ;
F_11 ( V_119 , V_4 -> V_11 + V_29 ) ;
V_4 -> V_140 = V_150 ;
F_42 ( F_3 ( V_4 -> V_2 ) ,
L_4 ,
V_98 , V_151 , V_105 , V_149 , V_150 , V_148 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_155 * V_156 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_156 -> V_126 == V_157 )
V_4 -> V_126 = 2 ;
else if ( V_156 -> V_126 == V_158 )
V_4 -> V_126 = 1 ;
else
V_4 -> V_126 = 0 ;
if ( V_156 -> clock )
F_38 ( V_4 , V_156 -> clock ) ;
}
static void F_44 ( struct V_1 * V_2 , int V_159 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_75 ;
F_45 ( & V_4 -> V_59 , V_75 ) ;
V_4 -> V_30 = V_159 ;
if ( V_159 ) {
F_11 ( V_31 ,
V_4 -> V_11 + V_33 + V_160 ) ;
F_11 ( V_32 ,
V_4 -> V_11 + V_34 + V_160 ) ;
if ( F_7 ( V_4 -> V_11 + V_12 ) & V_161 )
F_20 ( V_4 -> V_2 ) ;
} else {
F_11 ( V_31 ,
V_4 -> V_11 + V_33 + V_61 ) ;
F_11 ( V_32 ,
V_4 -> V_11 + V_34 + V_61 ) ;
}
F_46 ( & V_4 -> V_59 , V_75 ) ;
}
static bool F_47 ( struct V_162 * V_163 , void * V_55 )
{
struct V_3 * V_4 = V_55 ;
if ( ! F_48 ( V_163 ) )
return false ;
if ( V_163 -> V_164 != V_4 -> V_165 -> V_166 )
return false ;
V_163 -> V_167 = & V_4 -> V_168 ;
return true ;
}
static int F_49 ( struct V_169 * V_170 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_171 * V_172 , * V_173 , * V_174 ;
struct V_5 * V_6 ;
int V_175 = 0 , V_176 , V_177 ;
T_3 V_178 ;
V_172 = F_50 ( V_170 , V_179 , 0 ) ;
V_173 = F_50 ( V_170 , V_180 , 0 ) ;
V_176 = F_51 ( V_170 , 0 ) ;
V_177 = F_51 ( V_170 , 1 ) ;
if ( ! V_172 || ! V_173 || V_176 < 0 || V_177 < 0 )
return - V_10 ;
V_174 = F_52 ( V_172 -> V_166 , F_53 ( V_172 ) , V_170 -> V_181 ) ;
if ( ! V_174 )
return - V_182 ;
V_2 = F_54 ( sizeof( struct V_3 ) , & V_170 -> V_183 ) ;
if ( ! V_2 ) {
V_175 = - V_184 ;
goto V_185;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_11 = F_55 ( V_174 -> V_166 , F_53 ( V_174 ) ) ;
if ( ! V_4 -> V_11 ) {
V_175 = - V_184 ;
goto V_186;
}
V_4 -> V_187 = F_7 ( V_4 -> V_11 + V_188 ) >>
V_189 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_190 = V_174 ;
V_4 -> V_165 = V_173 ;
V_4 -> V_56 = V_176 ;
V_4 -> V_30 = 0 ;
V_4 -> V_152 = F_56 ( & V_170 -> V_183 , NULL ) ;
if ( F_57 ( V_4 -> V_152 ) ) {
V_175 = F_58 ( V_4 -> V_152 ) ;
goto V_191;
}
F_59 ( V_4 -> V_152 ) ;
F_8 ( V_4 ) ;
F_60 ( V_178 ) ;
F_61 ( V_192 , V_178 ) ;
V_4 -> V_168 . V_193 = V_177 ;
V_4 -> V_81 = F_62 ( V_178 , F_47 , V_4 ) ;
if ( ! V_4 -> V_81 ) {
F_41 ( F_3 ( V_4 -> V_2 ) ,
L_5 , V_98 ) ;
goto V_194;
}
V_2 -> V_195 = & V_196 ;
V_2 -> V_197 = V_198 | V_199 |
V_200 | V_201 ;
V_6 = F_3 ( V_4 -> V_2 ) -> V_7 ;
if ( V_6 ) {
if ( V_6 -> V_75 & V_202 )
V_2 -> V_197 |= V_203 | V_204 ;
if ( V_6 -> V_75 & V_205 )
V_2 -> V_197 |= V_203 ;
}
V_2 -> V_206 = 400000 ;
V_2 -> V_207 = 288000000 ;
V_2 -> V_208 = V_209 | V_210 ;
V_2 -> V_211 = 52 ;
V_2 -> V_212 = 1 << 0xf ;
V_2 -> V_213 = ( F_35 () ) ? 0xff : 0xffffff ;
V_2 -> V_214 = ( F_35 () ) ? 0xffff : 0xffffffff ;
V_2 -> V_215 = F_63 ( V_4 -> V_81 -> V_216 -> V_183 ) ;
F_64 ( V_170 , V_2 ) ;
V_175 = F_65 ( V_4 -> V_56 , F_18 , 0 , V_217 , V_4 ) ;
if ( V_175 )
goto V_218;
F_66 ( & V_4 -> V_59 ) ;
V_175 = F_67 ( V_2 ) ;
if ( V_175 )
goto V_219;
F_68 ( F_3 ( V_4 -> V_2 ) , L_6 ) ;
return 0 ;
V_219:
F_69 ( V_4 -> V_56 , V_4 ) ;
V_218:
if ( V_4 -> V_81 )
F_70 ( V_4 -> V_81 ) ;
V_194:
F_71 ( V_4 -> V_152 ) ;
F_72 ( V_4 -> V_152 ) ;
V_191:
F_73 ( V_4 -> V_11 ) ;
V_186:
F_74 ( V_2 ) ;
V_185:
F_75 ( V_172 -> V_166 , F_53 ( V_172 ) ) ;
return V_175 ;
}
static int F_76 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = F_77 ( V_170 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_171 * V_190 = V_4 -> V_190 ;
F_78 ( V_2 ) ;
F_69 ( V_4 -> V_56 , V_4 ) ;
F_64 ( V_170 , NULL ) ;
if ( V_4 -> V_81 )
F_70 ( V_4 -> V_81 ) ;
F_71 ( V_4 -> V_152 ) ;
F_72 ( V_4 -> V_152 ) ;
F_73 ( V_4 -> V_11 ) ;
F_74 ( V_2 ) ;
F_75 ( V_190 -> V_166 , F_53 ( V_190 ) ) ;
return 0 ;
}
static int F_79 ( struct V_216 * V_183 )
{
struct V_1 * V_2 = F_80 ( V_183 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_175 = 0 ;
V_175 = F_81 ( V_2 ) ;
F_71 ( V_4 -> V_152 ) ;
return V_175 ;
}
static int F_82 ( struct V_216 * V_183 )
{
struct V_1 * V_2 = F_80 ( V_183 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_175 = 0 ;
F_59 ( V_4 -> V_152 ) ;
V_175 = F_83 ( V_2 ) ;
return V_175 ;
}
