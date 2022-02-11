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
struct V_3 * V_4 , unsigned int V_75 )
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
V_76 = V_4 -> V_81 -> V_82 -> V_83 ( V_4 -> V_81 ,
V_78 , V_49 , V_4 -> V_84 , V_75 ) ;
if ( V_76 ) {
V_76 -> V_85 = F_17 ;
V_76 -> V_86 = V_4 ;
} else {
if ( V_38 )
F_14 ( F_3 ( V_4 -> V_2 ) , V_38 -> V_48 ,
V_38 -> V_49 , V_4 -> V_50 ) ;
}
return V_76 ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_74 * V_76 ;
T_1 V_14 , V_87 , V_88 ;
V_14 = V_89 | V_16 ;
V_87 = F_10 ( V_36 -> V_90 , V_91 ) | V_92 ;
V_88 = V_36 -> V_93 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_87 |= V_94 | V_95 ;
}
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_87 ;
V_4 -> V_79 [ 2 ] = V_88 ;
V_4 -> V_50 = V_96 ;
V_4 -> V_84 = V_97 ;
V_76 = F_22 ( V_4 , 0 ) ;
if ( ! V_76 )
goto V_98;
F_25 ( V_76 ) ;
return;
V_98:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_99 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_74 * V_76 ;
T_1 V_100 , V_101 , V_102 ;
T_1 V_14 , V_87 , V_88 ;
V_100 = ( F_13 ( V_36 ) & V_103 ) ?
0 : V_16 ;
V_101 = ( F_13 ( V_36 ) & V_41 ) ?
V_104 : 0 ;
V_102 = ( F_13 ( V_36 ) & V_42 ) ?
V_105 : 0 ;
V_14 = V_89 | V_100 | V_101 | V_102 ;
V_87 = F_10 ( V_36 -> V_90 , V_91 ) ;
V_88 = V_36 -> V_93 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_87 |= V_94 | V_95 ;
}
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_87 ;
V_4 -> V_79 [ 2 ] = V_88 ;
V_4 -> V_50 = V_96 ;
V_4 -> V_84 = V_97 ;
V_76 = F_22 ( V_4 , 0 ) ;
if ( ! V_76 )
goto V_98;
F_25 ( V_76 ) ;
return;
V_98:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_99 ) ;
}
static unsigned short F_28 ( unsigned V_106 , unsigned V_107 )
{
const unsigned int V_108 = 4096 ;
const unsigned int V_109 = V_106 / 1000 ;
const unsigned int V_110 = V_107 / 1000 ;
const unsigned int V_111 = V_110 * V_109 ;
const unsigned int V_112 = V_111 / V_108 ;
F_29 ( V_112 == 0 ) ;
return V_112 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_38 ;
struct V_74 * V_76 ;
struct V_77 * V_78 = V_38 -> V_48 , * V_48 ;
unsigned int V_49 = V_38 -> V_49 ;
int V_113 ;
unsigned short V_114 , V_115 ;
enum V_116 V_84 ;
unsigned int V_117 = 0 , V_118 ;
unsigned int V_52 = V_38 -> V_52 ;
T_1 V_100 , V_101 , V_102 , V_119 ;
T_1 V_14 , V_87 , V_88 , V_120 ;
V_100 = ( F_13 ( V_36 ) & V_103 ) ?
0 : V_16 ;
V_101 = ( F_13 ( V_36 ) & V_41 ) ?
V_104 : 0 ;
V_102 = ( F_13 ( V_36 ) & V_42 ) ?
V_105 : 0 ;
if ( V_38 -> V_121 & V_122 ) {
V_114 = V_123 ;
V_84 = V_124 ;
V_119 = 0 ;
} else {
V_114 = V_125 ;
V_84 = V_126 ;
V_119 = V_127 ;
}
V_14 = F_10 ( V_4 -> V_128 , V_129 ) |
V_100 | V_101 | V_102 |
V_130 | V_119 |
V_131 |
V_89 ;
V_87 = F_10 ( V_36 -> V_90 , V_91 ) ;
V_118 = F_31 ( V_38 -> V_53 ) ;
F_32 (sgl, sg, sg_len, i)
V_117 += V_48 -> V_132 ;
if ( V_117 != V_38 -> V_52 * V_38 -> V_53 )
V_52 = 1 ;
if ( F_33 () ) {
V_14 |= F_10 ( V_117 , V_133 ) ;
V_87 |= F_10 ( V_118 , V_134 ) |
F_10 ( V_52 - 1 , V_135 ) ;
} else {
F_11 ( V_117 , V_4 -> V_11 + V_136 ) ;
F_11 ( F_10 ( V_118 , V_137 ) |
F_10 ( V_52 - 1 , V_138 ) ,
V_4 -> V_11 + V_139 ) ;
}
if ( ( V_36 -> V_90 == V_140 ) ||
( V_36 -> V_90 == V_141 ) )
V_87 |= V_92 ;
V_88 = V_36 -> V_93 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_87 |= V_94 | V_95 ;
}
V_115 = F_28 ( V_4 -> V_142 , V_38 -> V_143 ) ;
V_120 = F_7 ( V_4 -> V_11 + V_29 ) ;
V_120 &= ~ ( V_144 ) ;
V_120 |= F_10 ( V_115 , V_26 ) ;
F_11 ( V_120 , V_4 -> V_11 + V_29 ) ;
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_87 ;
V_4 -> V_79 [ 2 ] = V_88 ;
V_4 -> V_50 = V_96 ;
V_4 -> V_84 = V_97 ;
V_76 = F_22 ( V_4 , 0 ) ;
if ( ! V_76 )
goto V_98;
F_29 ( V_4 -> V_38 != NULL ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_50 = V_114 ;
V_4 -> V_84 = V_84 ;
V_76 = F_22 ( V_4 , 1 ) ;
if ( ! V_76 )
goto V_98;
F_25 ( V_76 ) ;
return;
V_98:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_99 ) ;
}
static void F_15 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
V_4 -> V_36 = V_36 ;
switch ( F_34 ( V_36 ) ) {
case V_145 :
F_24 ( V_4 ) ;
break;
case V_146 :
F_27 ( V_4 ) ;
break;
case V_147 :
F_27 ( V_4 ) ;
break;
case V_148 :
F_30 ( V_4 ) ;
break;
default:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_2 , V_99 ) ;
break;
}
}
static void F_35 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_29 ( V_4 -> V_40 != NULL ) ;
V_4 -> V_40 = V_40 ;
F_15 ( V_4 , V_40 -> V_36 ) ;
}
static void F_36 ( struct V_3 * V_4 , unsigned int V_149 )
{
unsigned int V_150 , V_151 ;
T_1 V_152 , V_106 ;
T_1 V_120 ;
V_150 = F_37 ( V_4 -> V_153 ) ;
for ( V_152 = 2 ; V_152 <= 254 ; V_152 += 2 ) {
V_106 = F_38 ( V_150 , V_149 * V_152 ) ;
V_106 = ( V_106 > 0 ) ? V_106 - 1 : 0 ;
if ( V_106 <= 255 )
break;
}
if ( V_152 > 254 ) {
F_39 ( F_3 ( V_4 -> V_2 ) ,
L_3 , V_99 , V_149 ) ;
return;
}
V_151 = V_150 / V_152 / ( 1 + V_106 ) ;
V_120 = F_7 ( V_4 -> V_11 + V_29 ) ;
V_120 &= ~ ( V_154 | V_155 ) ;
V_120 |= F_10 ( V_152 , V_27 ) ;
V_120 |= F_10 ( V_106 , V_28 ) ;
F_11 ( V_120 , V_4 -> V_11 + V_29 ) ;
V_4 -> V_142 = V_151 ;
F_40 ( F_3 ( V_4 -> V_2 ) ,
L_4 ,
V_99 , V_152 , V_106 , V_150 , V_151 , V_149 ) ;
}
static void F_41 ( struct V_1 * V_2 , struct V_156 * V_157 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_157 -> V_128 == V_158 )
V_4 -> V_128 = 2 ;
else if ( V_157 -> V_128 == V_159 )
V_4 -> V_128 = 1 ;
else
V_4 -> V_128 = 0 ;
if ( V_157 -> clock )
F_36 ( V_4 , V_157 -> clock ) ;
}
static void F_42 ( struct V_1 * V_2 , int V_160 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_121 ;
F_43 ( & V_4 -> V_59 , V_121 ) ;
V_4 -> V_30 = V_160 ;
if ( V_160 ) {
F_11 ( V_31 ,
V_4 -> V_11 + V_33 + V_161 ) ;
F_11 ( V_32 ,
V_4 -> V_11 + V_34 + V_161 ) ;
if ( F_7 ( V_4 -> V_11 + V_12 ) & V_162 )
F_20 ( V_4 -> V_2 ) ;
} else {
F_11 ( V_31 ,
V_4 -> V_11 + V_33 + V_61 ) ;
F_11 ( V_32 ,
V_4 -> V_11 + V_34 + V_61 ) ;
}
F_44 ( & V_4 -> V_59 , V_121 ) ;
}
static bool F_45 ( struct V_163 * V_164 , void * V_55 )
{
struct V_3 * V_4 = V_55 ;
if ( ! F_46 ( V_164 ) )
return false ;
if ( V_164 -> V_165 != V_4 -> V_166 -> V_167 )
return false ;
V_164 -> V_168 = & V_4 -> V_169 ;
return true ;
}
static int F_47 ( struct V_170 * V_171 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_172 * V_173 , * V_174 , * V_175 ;
struct V_5 * V_6 ;
int V_176 = 0 , V_177 , V_178 ;
T_3 V_179 ;
V_173 = F_48 ( V_171 , V_180 , 0 ) ;
V_174 = F_48 ( V_171 , V_181 , 0 ) ;
V_177 = F_49 ( V_171 , 0 ) ;
V_178 = F_49 ( V_171 , 1 ) ;
if ( ! V_173 || ! V_174 || V_177 < 0 || V_178 < 0 )
return - V_10 ;
V_175 = F_50 ( V_173 -> V_167 , F_51 ( V_173 ) , V_171 -> V_182 ) ;
if ( ! V_175 )
return - V_183 ;
V_2 = F_52 ( sizeof( struct V_3 ) , & V_171 -> V_184 ) ;
if ( ! V_2 ) {
V_176 = - V_185 ;
goto V_186;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_11 = F_53 ( V_175 -> V_167 , F_51 ( V_175 ) ) ;
if ( ! V_4 -> V_11 ) {
V_176 = - V_185 ;
goto V_187;
}
V_4 -> V_188 = F_7 ( V_4 -> V_11 + V_189 ) >>
V_190 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_191 = V_175 ;
V_4 -> V_166 = V_174 ;
V_4 -> V_56 = V_177 ;
V_4 -> V_30 = 0 ;
V_4 -> V_153 = F_54 ( & V_171 -> V_184 , NULL ) ;
if ( F_55 ( V_4 -> V_153 ) ) {
V_176 = F_56 ( V_4 -> V_153 ) ;
goto V_192;
}
F_57 ( V_4 -> V_153 ) ;
F_8 ( V_4 ) ;
F_58 ( V_179 ) ;
F_59 ( V_193 , V_179 ) ;
V_4 -> V_169 . V_194 = V_178 ;
V_4 -> V_81 = F_60 ( V_179 , F_45 , V_4 ) ;
if ( ! V_4 -> V_81 ) {
F_39 ( F_3 ( V_4 -> V_2 ) ,
L_5 , V_99 ) ;
goto V_195;
}
V_2 -> V_196 = & V_197 ;
V_2 -> V_198 = V_199 | V_200 |
V_201 | V_202 ;
V_6 = F_3 ( V_4 -> V_2 ) -> V_7 ;
if ( V_6 ) {
if ( V_6 -> V_121 & V_203 )
V_2 -> V_198 |= V_204 | V_205 ;
if ( V_6 -> V_121 & V_206 )
V_2 -> V_198 |= V_204 ;
}
V_2 -> V_207 = 400000 ;
V_2 -> V_208 = 288000000 ;
V_2 -> V_209 = V_210 | V_211 ;
V_2 -> V_212 = 52 ;
V_2 -> V_213 = 1 << 0xf ;
V_2 -> V_214 = ( F_33 () ) ? 0xff : 0xffffff ;
V_2 -> V_215 = ( F_33 () ) ? 0xffff : 0xffffffff ;
V_2 -> V_216 = F_61 ( V_4 -> V_81 -> V_82 -> V_184 ) ;
F_62 ( V_171 , V_2 ) ;
V_176 = F_63 ( V_4 -> V_56 , F_18 , 0 , V_217 , V_4 ) ;
if ( V_176 )
goto V_218;
F_64 ( & V_4 -> V_59 ) ;
V_176 = F_65 ( V_2 ) ;
if ( V_176 )
goto V_219;
F_66 ( F_3 ( V_4 -> V_2 ) , L_6 ) ;
return 0 ;
V_219:
F_67 ( V_4 -> V_56 , V_4 ) ;
V_218:
if ( V_4 -> V_81 )
F_68 ( V_4 -> V_81 ) ;
V_195:
F_69 ( V_4 -> V_153 ) ;
F_70 ( V_4 -> V_153 ) ;
V_192:
F_71 ( V_4 -> V_11 ) ;
V_187:
F_72 ( V_2 ) ;
V_186:
F_73 ( V_173 -> V_167 , F_51 ( V_173 ) ) ;
return V_176 ;
}
static int F_74 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = F_75 ( V_171 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_172 * V_191 = V_4 -> V_191 ;
F_76 ( V_2 ) ;
F_67 ( V_4 -> V_56 , V_4 ) ;
F_62 ( V_171 , NULL ) ;
if ( V_4 -> V_81 )
F_68 ( V_4 -> V_81 ) ;
F_69 ( V_4 -> V_153 ) ;
F_70 ( V_4 -> V_153 ) ;
F_71 ( V_4 -> V_11 ) ;
F_72 ( V_2 ) ;
F_73 ( V_191 -> V_167 , F_51 ( V_191 ) ) ;
return 0 ;
}
static int F_77 ( struct V_82 * V_184 )
{
struct V_1 * V_2 = F_78 ( V_184 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_176 = 0 ;
V_176 = F_79 ( V_2 ) ;
F_69 ( V_4 -> V_153 ) ;
return V_176 ;
}
static int F_80 ( struct V_82 * V_184 )
{
struct V_1 * V_2 = F_78 ( V_184 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_176 = 0 ;
F_57 ( V_4 -> V_153 ) ;
V_176 = F_81 ( V_2 ) ;
return V_176 ;
}
