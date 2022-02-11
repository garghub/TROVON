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
V_78 , V_49 , V_4 -> V_50 , V_75 ) ;
if ( V_76 ) {
V_76 -> V_84 = F_17 ;
V_76 -> V_85 = V_4 ;
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
T_1 V_14 , V_86 , V_87 ;
V_14 = V_88 | V_16 ;
V_86 = F_10 ( V_36 -> V_89 , V_90 ) | V_91 ;
V_87 = V_36 -> V_92 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_86 |= V_93 | V_94 ;
}
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_86 ;
V_4 -> V_79 [ 2 ] = V_87 ;
V_4 -> V_50 = V_95 ;
V_76 = F_22 ( V_4 , 0 ) ;
if ( ! V_76 )
goto V_96;
F_25 ( V_76 ) ;
return;
V_96:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_97 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_74 * V_76 ;
T_1 V_98 , V_99 , V_100 ;
T_1 V_14 , V_86 , V_87 ;
V_98 = ( F_13 ( V_36 ) & V_101 ) ?
0 : V_16 ;
V_99 = ( F_13 ( V_36 ) & V_41 ) ?
V_102 : 0 ;
V_100 = ( F_13 ( V_36 ) & V_42 ) ?
V_103 : 0 ;
V_14 = V_88 | V_98 | V_99 | V_100 ;
V_86 = F_10 ( V_36 -> V_89 , V_90 ) ;
V_87 = V_36 -> V_92 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_86 |= V_93 | V_94 ;
}
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_86 ;
V_4 -> V_79 [ 2 ] = V_87 ;
V_4 -> V_50 = V_95 ;
V_76 = F_22 ( V_4 , 0 ) ;
if ( ! V_76 )
goto V_96;
F_25 ( V_76 ) ;
return;
V_96:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_97 ) ;
}
static unsigned short F_28 ( unsigned V_104 , unsigned V_105 )
{
const unsigned int V_106 = 4096 ;
const unsigned int V_107 = V_104 / 1000 ;
const unsigned int V_108 = V_105 / 1000 ;
const unsigned int V_109 = V_108 * V_107 ;
const unsigned int V_110 = V_109 / V_106 ;
F_29 ( V_110 == 0 ) ;
return V_110 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_38 ;
struct V_74 * V_76 ;
struct V_77 * V_78 = V_38 -> V_48 , * V_48 ;
unsigned int V_49 = V_38 -> V_49 ;
int V_111 ;
unsigned short V_112 , V_113 ;
unsigned int V_114 = 0 , V_115 ;
unsigned int V_52 = V_38 -> V_52 ;
T_1 V_98 , V_99 , V_100 , V_116 ;
T_1 V_14 , V_86 , V_87 , V_117 ;
V_98 = ( F_13 ( V_36 ) & V_101 ) ?
0 : V_16 ;
V_99 = ( F_13 ( V_36 ) & V_41 ) ?
V_102 : 0 ;
V_100 = ( F_13 ( V_36 ) & V_42 ) ?
V_103 : 0 ;
if ( V_38 -> V_118 & V_119 ) {
V_112 = V_120 ;
V_116 = 0 ;
} else {
V_112 = V_121 ;
V_116 = V_122 ;
}
V_14 = F_10 ( V_4 -> V_123 , V_124 ) |
V_98 | V_99 | V_100 |
V_125 | V_116 |
V_126 |
V_88 ;
V_86 = F_10 ( V_36 -> V_89 , V_90 ) ;
V_115 = F_31 ( V_38 -> V_53 ) ;
F_32 (sgl, sg, sg_len, i)
V_114 += V_48 -> V_127 ;
if ( V_114 != V_38 -> V_52 * V_38 -> V_53 )
V_52 = 1 ;
if ( F_33 () ) {
V_14 |= F_10 ( V_114 , V_128 ) ;
V_86 |= F_10 ( V_115 , V_129 ) |
F_10 ( V_52 - 1 , V_130 ) ;
} else {
F_11 ( V_114 , V_4 -> V_11 + V_131 ) ;
F_11 ( F_10 ( V_115 , V_132 ) |
F_10 ( V_52 - 1 , V_133 ) ,
V_4 -> V_11 + V_134 ) ;
}
if ( ( V_36 -> V_89 == V_135 ) ||
( V_36 -> V_89 == V_136 ) )
V_86 |= V_91 ;
V_87 = V_36 -> V_92 ;
if ( V_4 -> V_30 ) {
V_14 |= V_31 ;
V_86 |= V_93 | V_94 ;
}
V_113 = F_28 ( V_4 -> V_137 , V_38 -> V_138 ) ;
V_117 = F_7 ( V_4 -> V_11 + V_29 ) ;
V_117 &= ~ ( V_139 ) ;
V_117 |= F_10 ( V_113 , V_26 ) ;
F_11 ( V_117 , V_4 -> V_11 + V_29 ) ;
V_4 -> V_79 [ 0 ] = V_14 ;
V_4 -> V_79 [ 1 ] = V_86 ;
V_4 -> V_79 [ 2 ] = V_87 ;
V_4 -> V_50 = V_95 ;
V_76 = F_22 ( V_4 , 0 ) ;
if ( ! V_76 )
goto V_96;
F_29 ( V_4 -> V_38 != NULL ) ;
V_4 -> V_38 = V_38 ;
V_4 -> V_50 = V_112 ;
V_76 = F_22 ( V_4 , 1 ) ;
if ( ! V_76 )
goto V_96;
F_25 ( V_76 ) ;
return;
V_96:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_1 , V_97 ) ;
}
static void F_15 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
V_4 -> V_36 = V_36 ;
switch ( F_34 ( V_36 ) ) {
case V_140 :
F_24 ( V_4 ) ;
break;
case V_141 :
F_27 ( V_4 ) ;
break;
case V_142 :
F_27 ( V_4 ) ;
break;
case V_143 :
F_30 ( V_4 ) ;
break;
default:
F_26 ( F_3 ( V_4 -> V_2 ) ,
L_2 , V_97 ) ;
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
static void F_36 ( struct V_3 * V_4 , unsigned int V_144 )
{
unsigned int V_145 , V_146 ;
T_1 V_147 , V_148 ;
T_1 V_117 ;
V_145 = F_37 ( V_4 -> V_149 ) ;
for ( V_147 = 2 ; V_147 < 254 ; V_147 += 2 ) {
V_148 = V_145 / V_144 / V_147 ;
if ( V_148 < 0x100 )
break;
}
if ( V_147 >= 254 ) {
F_38 ( F_3 ( V_4 -> V_2 ) ,
L_3 , V_97 , V_144 ) ;
return;
}
if ( V_148 == 0 )
V_146 = V_145 / V_147 ;
else
V_146 = V_145 / V_147 / V_148 ;
V_117 = F_7 ( V_4 -> V_11 + V_29 ) ;
V_117 &= ~ ( V_150 | V_151 ) ;
V_117 |= F_10 ( V_147 , V_27 ) ;
V_117 |= F_10 ( V_148 - 1 , V_28 ) ;
F_11 ( V_117 , V_4 -> V_11 + V_29 ) ;
V_4 -> V_137 = V_146 ;
F_39 ( F_3 ( V_4 -> V_2 ) ,
L_4 ,
V_97 , V_147 , V_148 , V_145 , V_146 , V_144 ) ;
}
static void F_40 ( struct V_1 * V_2 , struct V_152 * V_153 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_153 -> V_123 == V_154 )
V_4 -> V_123 = 2 ;
else if ( V_153 -> V_123 == V_155 )
V_4 -> V_123 = 1 ;
else
V_4 -> V_123 = 0 ;
if ( V_153 -> clock )
F_36 ( V_4 , V_153 -> clock ) ;
}
static void F_41 ( struct V_1 * V_2 , int V_156 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_118 ;
F_42 ( & V_4 -> V_59 , V_118 ) ;
V_4 -> V_30 = V_156 ;
if ( V_156 ) {
F_11 ( V_31 ,
V_4 -> V_11 + V_33 + V_157 ) ;
F_11 ( V_32 ,
V_4 -> V_11 + V_34 + V_157 ) ;
if ( F_7 ( V_4 -> V_11 + V_12 ) & V_158 )
F_20 ( V_4 -> V_2 ) ;
} else {
F_11 ( V_31 ,
V_4 -> V_11 + V_33 + V_61 ) ;
F_11 ( V_32 ,
V_4 -> V_11 + V_34 + V_61 ) ;
}
F_43 ( & V_4 -> V_59 , V_118 ) ;
}
static bool F_44 ( struct V_159 * V_160 , void * V_55 )
{
struct V_3 * V_4 = V_55 ;
if ( ! F_45 ( V_160 ) )
return false ;
if ( V_160 -> V_161 != V_4 -> V_162 -> V_163 )
return false ;
V_160 -> V_164 = & V_4 -> V_165 ;
return true ;
}
static int F_46 ( struct V_166 * V_167 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_168 * V_169 , * V_170 , * V_171 ;
struct V_5 * V_6 ;
int V_172 = 0 , V_173 , V_174 ;
T_3 V_175 ;
V_169 = F_47 ( V_167 , V_176 , 0 ) ;
V_170 = F_47 ( V_167 , V_177 , 0 ) ;
V_173 = F_48 ( V_167 , 0 ) ;
V_174 = F_48 ( V_167 , 1 ) ;
if ( ! V_169 || ! V_170 || V_173 < 0 || V_174 < 0 )
return - V_10 ;
V_171 = F_49 ( V_169 -> V_163 , F_50 ( V_169 ) , V_167 -> V_178 ) ;
if ( ! V_171 )
return - V_179 ;
V_2 = F_51 ( sizeof( struct V_3 ) , & V_167 -> V_180 ) ;
if ( ! V_2 ) {
V_172 = - V_181 ;
goto V_182;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_11 = F_52 ( V_171 -> V_163 , F_50 ( V_171 ) ) ;
if ( ! V_4 -> V_11 ) {
V_172 = - V_181 ;
goto V_183;
}
V_4 -> V_184 = F_7 ( V_4 -> V_11 + V_185 ) >>
V_186 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_187 = V_171 ;
V_4 -> V_162 = V_170 ;
V_4 -> V_56 = V_173 ;
V_4 -> V_30 = 0 ;
V_4 -> V_149 = F_53 ( & V_167 -> V_180 , NULL ) ;
if ( F_54 ( V_4 -> V_149 ) ) {
V_172 = F_55 ( V_4 -> V_149 ) ;
goto V_188;
}
F_56 ( V_4 -> V_149 ) ;
F_8 ( V_4 ) ;
F_57 ( V_175 ) ;
F_58 ( V_189 , V_175 ) ;
V_4 -> V_165 . V_190 = V_174 ;
V_4 -> V_81 = F_59 ( V_175 , F_44 , V_4 ) ;
if ( ! V_4 -> V_81 ) {
F_38 ( F_3 ( V_4 -> V_2 ) ,
L_5 , V_97 ) ;
goto V_191;
}
V_2 -> V_192 = & V_193 ;
V_2 -> V_194 = V_195 | V_196 |
V_197 | V_198 ;
V_6 = F_3 ( V_4 -> V_2 ) -> V_7 ;
if ( V_6 ) {
if ( V_6 -> V_118 & V_199 )
V_2 -> V_194 |= V_200 | V_201 ;
if ( V_6 -> V_118 & V_202 )
V_2 -> V_194 |= V_200 ;
}
V_2 -> V_203 = 400000 ;
V_2 -> V_204 = 288000000 ;
V_2 -> V_205 = V_206 | V_207 ;
V_2 -> V_208 = 52 ;
V_2 -> V_209 = 1 << 0xf ;
V_2 -> V_210 = ( F_33 () ) ? 0xff : 0xffffff ;
V_2 -> V_211 = ( F_33 () ) ? 0xffff : 0xffffffff ;
V_2 -> V_212 = F_60 ( V_4 -> V_81 -> V_82 -> V_180 ) ;
F_61 ( V_167 , V_2 ) ;
V_172 = F_62 ( V_4 -> V_56 , F_18 , 0 , V_213 , V_4 ) ;
if ( V_172 )
goto V_214;
F_63 ( & V_4 -> V_59 ) ;
V_172 = F_64 ( V_2 ) ;
if ( V_172 )
goto V_215;
F_65 ( F_3 ( V_4 -> V_2 ) , L_6 ) ;
return 0 ;
V_215:
F_66 ( V_4 -> V_56 , V_4 ) ;
V_214:
if ( V_4 -> V_81 )
F_67 ( V_4 -> V_81 ) ;
V_191:
F_68 ( V_4 -> V_149 ) ;
F_69 ( V_4 -> V_149 ) ;
V_188:
F_70 ( V_4 -> V_11 ) ;
V_183:
F_71 ( V_2 ) ;
V_182:
F_72 ( V_169 -> V_163 , F_50 ( V_169 ) ) ;
return V_172 ;
}
static int F_73 ( struct V_166 * V_167 )
{
struct V_1 * V_2 = F_74 ( V_167 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_168 * V_187 = V_4 -> V_187 ;
F_75 ( V_2 ) ;
F_66 ( V_4 -> V_56 , V_4 ) ;
F_61 ( V_167 , NULL ) ;
if ( V_4 -> V_81 )
F_67 ( V_4 -> V_81 ) ;
F_68 ( V_4 -> V_149 ) ;
F_69 ( V_4 -> V_149 ) ;
F_70 ( V_4 -> V_11 ) ;
F_71 ( V_2 ) ;
F_72 ( V_187 -> V_163 , F_50 ( V_187 ) ) ;
return 0 ;
}
static int F_76 ( struct V_82 * V_180 )
{
struct V_1 * V_2 = F_77 ( V_180 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_172 = 0 ;
V_172 = F_78 ( V_2 ) ;
F_68 ( V_4 -> V_149 ) ;
return V_172 ;
}
static int F_79 ( struct V_82 * V_180 )
{
struct V_1 * V_2 = F_77 ( V_180 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_172 = 0 ;
F_56 ( V_4 -> V_149 ) ;
V_172 = F_80 ( V_2 ) ;
return V_172 ;
}
static int T_4 F_81 ( void )
{
return F_82 ( & V_216 ) ;
}
static void T_5 F_83 ( void )
{
F_84 ( & V_216 ) ;
}
