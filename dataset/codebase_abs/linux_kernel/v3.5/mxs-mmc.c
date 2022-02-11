static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! F_3 ( V_4 -> V_5 ) )
return - V_6 ;
return F_4 ( V_4 -> V_5 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ( F_6 ( V_4 -> V_7 + F_7 ( V_4 ) ) &
V_8 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
T_1 V_9 , V_10 ;
F_9 ( V_4 -> V_7 ) ;
V_9 = V_11 ;
V_10 = F_10 ( 0x3 , V_12 ) |
F_10 ( 0x7 , V_13 ) |
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_20 ;
F_11 ( F_10 ( 0xffff , V_21 ) |
F_10 ( 2 , V_22 ) |
F_10 ( 0 , V_23 ) ,
V_4 -> V_7 + F_12 ( V_4 ) ) ;
if ( V_4 -> V_24 ) {
V_9 |= V_25 ;
V_10 |= V_26 ;
}
F_11 ( V_9 , V_4 -> V_7 + V_27 ) ;
F_11 ( V_10 , V_4 -> V_7 + F_13 ( V_4 ) ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_29 ;
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_32 * V_33 = V_4 -> V_33 ;
if ( F_15 ( V_29 ) & V_34 ) {
if ( F_15 ( V_29 ) & V_35 ) {
V_29 -> V_36 [ 3 ] = F_6 ( V_4 -> V_7 + F_16 ( V_4 ) ) ;
V_29 -> V_36 [ 2 ] = F_6 ( V_4 -> V_7 + F_17 ( V_4 ) ) ;
V_29 -> V_36 [ 1 ] = F_6 ( V_4 -> V_7 + F_18 ( V_4 ) ) ;
V_29 -> V_36 [ 0 ] = F_6 ( V_4 -> V_7 + F_19 ( V_4 ) ) ;
} else {
V_29 -> V_36 [ 0 ] = F_6 ( V_4 -> V_7 + F_16 ( V_4 ) ) ;
}
}
if ( V_31 ) {
F_20 ( F_21 ( V_4 -> V_2 ) , V_31 -> V_37 ,
V_31 -> V_38 , V_4 -> V_39 ) ;
if ( ! V_31 -> error )
V_31 -> V_40 = V_31 -> V_41 * V_31 -> V_42 ;
else
V_31 -> V_40 = 0 ;
V_4 -> V_31 = NULL ;
if ( V_33 -> V_43 ) {
F_22 ( V_4 , V_33 -> V_43 ) ;
return;
}
}
V_4 -> V_33 = NULL ;
F_23 ( V_4 -> V_2 , V_33 ) ;
}
static void F_24 ( void * V_44 )
{
struct V_3 * V_4 = V_44 ;
F_14 ( V_4 ) ;
}
static T_2 F_25 ( int V_45 , void * V_46 )
{
struct V_3 * V_4 = V_46 ;
struct V_28 * V_29 = V_4 -> V_29 ;
struct V_30 * V_31 = V_4 -> V_31 ;
T_1 V_47 ;
F_26 ( & V_4 -> V_48 ) ;
V_47 = F_6 ( V_4 -> V_7 + F_13 ( V_4 ) ) ;
F_11 ( V_47 & V_49 ,
V_4 -> V_7 + F_13 ( V_4 ) + V_50 ) ;
if ( ( V_47 & V_51 ) && ( V_47 & V_26 ) )
F_27 ( V_4 -> V_2 ) ;
F_28 ( & V_4 -> V_48 ) ;
if ( V_47 & V_52 )
V_29 -> error = - V_53 ;
else if ( V_47 & V_54 )
V_29 -> error = - V_55 ;
if ( V_31 ) {
if ( V_47 & ( V_56 |
V_57 ) )
V_31 -> error = - V_53 ;
else if ( V_47 & V_58 )
V_31 -> error = - V_59 ;
else if ( V_47 & ( V_60 |
V_61 ) )
V_31 -> error = - V_55 ;
}
return V_62 ;
}
static struct V_63 * F_29 (
struct V_3 * V_4 , unsigned long V_64 )
{
struct V_63 * V_65 ;
struct V_30 * V_31 = V_4 -> V_31 ;
struct V_66 * V_67 ;
unsigned int V_38 ;
if ( V_31 ) {
F_30 ( F_21 ( V_4 -> V_2 ) , V_31 -> V_37 ,
V_31 -> V_38 , V_4 -> V_39 ) ;
V_67 = V_31 -> V_37 ;
V_38 = V_31 -> V_38 ;
} else {
V_67 = (struct V_66 * ) V_4 -> V_68 ;
V_38 = V_69 ;
}
V_65 = F_31 ( V_4 -> V_70 ,
V_67 , V_38 , V_4 -> V_71 , V_64 ) ;
if ( V_65 ) {
V_65 -> V_72 = F_24 ;
V_65 -> V_73 = V_4 ;
} else {
if ( V_31 )
F_20 ( F_21 ( V_4 -> V_2 ) , V_31 -> V_37 ,
V_31 -> V_38 , V_4 -> V_39 ) ;
}
return V_65 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_29 ;
struct V_63 * V_65 ;
T_1 V_9 , V_74 , V_75 ;
V_9 = V_76 | V_11 ;
V_74 = F_10 ( V_29 -> V_77 , V_78 ) | V_79 ;
V_75 = V_29 -> V_80 ;
if ( V_4 -> V_24 ) {
V_9 |= V_25 ;
V_74 |= V_81 | V_82 ;
}
V_4 -> V_68 [ 0 ] = V_9 ;
V_4 -> V_68 [ 1 ] = V_74 ;
V_4 -> V_68 [ 2 ] = V_75 ;
V_4 -> V_39 = V_83 ;
V_4 -> V_71 = V_84 ;
V_65 = F_29 ( V_4 , V_85 ) ;
if ( ! V_65 )
goto V_86;
F_33 ( V_65 ) ;
F_34 ( V_4 -> V_70 ) ;
return;
V_86:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_87 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_29 ;
struct V_63 * V_65 ;
T_1 V_88 , V_89 , V_90 ;
T_1 V_9 , V_74 , V_75 ;
V_88 = ( F_15 ( V_29 ) & V_91 ) ?
0 : V_11 ;
V_89 = ( F_15 ( V_29 ) & V_34 ) ?
V_92 : 0 ;
V_90 = ( F_15 ( V_29 ) & V_35 ) ?
V_93 : 0 ;
V_9 = V_76 | V_88 | V_89 | V_90 ;
V_74 = F_10 ( V_29 -> V_77 , V_78 ) ;
V_75 = V_29 -> V_80 ;
if ( V_4 -> V_24 ) {
V_9 |= V_25 ;
V_74 |= V_81 | V_82 ;
}
V_4 -> V_68 [ 0 ] = V_9 ;
V_4 -> V_68 [ 1 ] = V_74 ;
V_4 -> V_68 [ 2 ] = V_75 ;
V_4 -> V_39 = V_83 ;
V_4 -> V_71 = V_84 ;
V_65 = F_29 ( V_4 , V_85 ) ;
if ( ! V_65 )
goto V_86;
F_33 ( V_65 ) ;
F_34 ( V_4 -> V_70 ) ;
return;
V_86:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_87 ) ;
}
static unsigned short F_37 ( unsigned V_94 , unsigned V_95 )
{
const unsigned int V_96 = 4096 ;
const unsigned int V_97 = V_94 / 1000 ;
const unsigned int V_98 = V_95 / 1000 ;
const unsigned int V_99 = V_98 * V_97 ;
const unsigned int V_100 = V_99 / V_96 ;
F_38 ( V_100 == 0 ) ;
return V_100 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_28 * V_29 = V_4 -> V_29 ;
struct V_30 * V_31 = V_29 -> V_31 ;
struct V_63 * V_65 ;
struct V_66 * V_67 = V_31 -> V_37 , * V_37 ;
unsigned int V_38 = V_31 -> V_38 ;
int V_101 ;
unsigned short V_102 , V_103 ;
enum V_104 V_71 ;
unsigned int V_105 = 0 , V_106 ;
unsigned int V_41 = V_31 -> V_41 ;
T_1 V_88 , V_89 , V_90 , V_107 ;
T_1 V_9 , V_74 , V_75 , V_108 ;
V_88 = ( F_15 ( V_29 ) & V_91 ) ?
0 : V_11 ;
V_89 = ( F_15 ( V_29 ) & V_34 ) ?
V_92 : 0 ;
V_90 = ( F_15 ( V_29 ) & V_35 ) ?
V_93 : 0 ;
if ( V_31 -> V_64 & V_109 ) {
V_102 = V_110 ;
V_71 = V_111 ;
V_107 = 0 ;
} else {
V_102 = V_112 ;
V_71 = V_113 ;
V_107 = V_114 ;
}
V_9 = F_10 ( V_4 -> V_115 , V_116 ) |
V_88 | V_89 | V_90 |
V_117 | V_107 |
V_118 |
V_76 ;
V_74 = F_10 ( V_29 -> V_77 , V_78 ) ;
V_106 = F_40 ( V_31 -> V_42 ) ;
F_41 (sgl, sg, sg_len, i)
V_105 += V_37 -> V_119 ;
if ( V_105 != V_31 -> V_41 * V_31 -> V_42 )
V_41 = 1 ;
if ( F_42 ( V_4 ) ) {
V_9 |= F_10 ( V_105 , V_120 ) ;
V_74 |= F_10 ( V_106 , V_121 ) |
F_10 ( V_41 - 1 , V_122 ) ;
} else {
F_11 ( V_105 , V_4 -> V_7 + V_123 ) ;
F_11 ( F_10 ( V_106 , V_124 ) |
F_10 ( V_41 - 1 , V_125 ) ,
V_4 -> V_7 + V_126 ) ;
}
if ( ( V_29 -> V_77 == V_127 ) ||
( V_29 -> V_77 == V_128 ) )
V_74 |= V_79 ;
V_75 = V_29 -> V_80 ;
if ( V_4 -> V_24 ) {
V_9 |= V_25 ;
V_74 |= V_81 | V_82 ;
}
V_103 = F_37 ( V_4 -> V_129 , V_31 -> V_130 ) ;
V_108 = F_6 ( V_4 -> V_7 + F_12 ( V_4 ) ) ;
V_108 &= ~ ( V_131 ) ;
V_108 |= F_10 ( V_103 , V_21 ) ;
F_11 ( V_108 , V_4 -> V_7 + F_12 ( V_4 ) ) ;
V_4 -> V_68 [ 0 ] = V_9 ;
V_4 -> V_68 [ 1 ] = V_74 ;
V_4 -> V_68 [ 2 ] = V_75 ;
V_4 -> V_39 = V_83 ;
V_4 -> V_71 = V_84 ;
V_65 = F_29 ( V_4 , 0 ) ;
if ( ! V_65 )
goto V_86;
F_38 ( V_4 -> V_31 != NULL ) ;
V_4 -> V_31 = V_31 ;
V_4 -> V_39 = V_102 ;
V_4 -> V_71 = V_71 ;
V_65 = F_29 ( V_4 , V_132 | V_85 ) ;
if ( ! V_65 )
goto V_86;
F_33 ( V_65 ) ;
F_34 ( V_4 -> V_70 ) ;
return;
V_86:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_87 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_28 * V_29 )
{
V_4 -> V_29 = V_29 ;
switch ( F_43 ( V_29 ) ) {
case V_133 :
F_32 ( V_4 ) ;
break;
case V_134 :
F_36 ( V_4 ) ;
break;
case V_135 :
F_36 ( V_4 ) ;
break;
case V_136 :
F_39 ( V_4 ) ;
break;
default:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_2 , V_87 ) ;
break;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_4 -> V_33 != NULL ) ;
V_4 -> V_33 = V_33 ;
F_22 ( V_4 , V_33 -> V_29 ) ;
}
static void F_45 ( struct V_3 * V_4 , unsigned int V_137 )
{
unsigned int V_138 , V_139 ;
T_1 V_140 , V_94 ;
T_1 V_108 ;
V_138 = F_46 ( V_4 -> V_141 ) ;
for ( V_140 = 2 ; V_140 <= 254 ; V_140 += 2 ) {
V_94 = F_47 ( V_138 , V_137 * V_140 ) ;
V_94 = ( V_94 > 0 ) ? V_94 - 1 : 0 ;
if ( V_94 <= 255 )
break;
}
if ( V_140 > 254 ) {
F_48 ( F_21 ( V_4 -> V_2 ) ,
L_3 , V_87 , V_137 ) ;
return;
}
V_139 = V_138 / V_140 / ( 1 + V_94 ) ;
V_108 = F_6 ( V_4 -> V_7 + F_12 ( V_4 ) ) ;
V_108 &= ~ ( V_142 | V_143 ) ;
V_108 |= F_10 ( V_140 , V_22 ) ;
V_108 |= F_10 ( V_94 , V_23 ) ;
F_11 ( V_108 , V_4 -> V_7 + F_12 ( V_4 ) ) ;
V_4 -> V_129 = V_139 ;
F_49 ( F_21 ( V_4 -> V_2 ) ,
L_4 ,
V_87 , V_140 , V_94 , V_138 , V_139 , V_137 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_145 -> V_115 == V_146 )
V_4 -> V_115 = 2 ;
else if ( V_145 -> V_115 == V_147 )
V_4 -> V_115 = 1 ;
else
V_4 -> V_115 = 0 ;
if ( V_145 -> clock )
F_45 ( V_4 , V_145 -> clock ) ;
}
static void F_51 ( struct V_1 * V_2 , int V_148 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_64 ;
F_52 ( & V_4 -> V_48 , V_64 ) ;
V_4 -> V_24 = V_148 ;
if ( V_148 ) {
F_11 ( V_25 ,
V_4 -> V_7 + V_27 + V_149 ) ;
F_11 ( V_26 ,
V_4 -> V_7 + F_13 ( V_4 ) + V_149 ) ;
if ( F_6 ( V_4 -> V_7 + F_7 ( V_4 ) ) &
V_150 )
F_27 ( V_4 -> V_2 ) ;
} else {
F_11 ( V_25 ,
V_4 -> V_7 + V_27 + V_50 ) ;
F_11 ( V_26 ,
V_4 -> V_7 + F_13 ( V_4 ) + V_50 ) ;
}
F_53 ( & V_4 -> V_48 , V_64 ) ;
}
static bool F_54 ( struct V_151 * V_152 , void * V_44 )
{
struct V_3 * V_4 = V_44 ;
if ( ! F_55 ( V_152 ) )
return false ;
if ( V_152 -> V_153 != V_4 -> V_154 )
return false ;
V_152 -> V_155 = & V_4 -> V_156 ;
return true ;
}
static int F_56 ( struct V_157 * V_158 )
{
const struct V_159 * V_160 =
F_57 ( V_161 , & V_158 -> V_162 ) ;
struct V_163 * V_164 = V_158 -> V_162 . V_165 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_166 * V_167 , * V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_171 ;
int V_172 = 0 , V_173 , V_174 ;
T_3 V_175 ;
V_167 = F_58 ( V_158 , V_176 , 0 ) ;
V_168 = F_58 ( V_158 , V_177 , 0 ) ;
V_173 = F_59 ( V_158 , 0 ) ;
V_174 = F_59 ( V_158 , 1 ) ;
if ( ! V_167 || V_173 < 0 || V_174 < 0 )
return - V_6 ;
V_2 = F_60 ( sizeof( struct V_3 ) , & V_158 -> V_162 ) ;
if ( ! V_2 )
return - V_178 ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_7 = F_61 ( & V_158 -> V_162 , V_167 ) ;
if ( ! V_4 -> V_7 ) {
V_172 = - V_179 ;
goto V_180;
}
if ( V_164 ) {
V_4 -> V_181 = (enum V_182 ) V_160 -> V_31 ;
V_172 = F_62 ( V_164 , L_5 ,
& V_4 -> V_154 ) ;
if ( V_172 ) {
F_48 ( F_21 ( V_4 -> V_2 ) ,
L_6 ) ;
goto V_180;
}
} else {
V_4 -> V_181 = V_158 -> V_183 -> V_184 ;
V_4 -> V_154 = V_168 -> V_185 ;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_24 = 0 ;
V_171 = F_63 ( & V_158 -> V_162 ) ;
if ( F_64 ( V_171 ) ) {
V_172 = F_65 ( V_171 ) ;
goto V_180;
}
V_4 -> V_141 = F_66 ( & V_158 -> V_162 , NULL ) ;
if ( F_64 ( V_4 -> V_141 ) ) {
V_172 = F_65 ( V_4 -> V_141 ) ;
goto V_180;
}
F_67 ( V_4 -> V_141 ) ;
F_8 ( V_4 ) ;
F_68 ( V_175 ) ;
F_69 ( V_186 , V_175 ) ;
V_4 -> V_156 . V_187 = V_174 ;
V_4 -> V_70 = F_70 ( V_175 , F_54 , V_4 ) ;
if ( ! V_4 -> V_70 ) {
F_48 ( F_21 ( V_4 -> V_2 ) ,
L_7 , V_87 ) ;
goto V_188;
}
V_2 -> V_189 = & V_190 ;
V_2 -> V_191 = V_192 | V_193 |
V_194 | V_195 ;
V_170 = F_21 ( V_4 -> V_2 ) -> V_196 ;
if ( ! V_170 ) {
T_1 V_115 = 0 ;
F_62 ( V_164 , L_8 , & V_115 ) ;
if ( V_115 == 4 )
V_2 -> V_191 |= V_197 ;
else if ( V_115 == 8 )
V_2 -> V_191 |= V_197 | V_198 ;
V_4 -> V_5 = F_71 ( V_164 , L_9 , 0 ) ;
} else {
if ( V_170 -> V_64 & V_199 )
V_2 -> V_191 |= V_197 | V_198 ;
if ( V_170 -> V_64 & V_200 )
V_2 -> V_191 |= V_197 ;
V_4 -> V_5 = V_170 -> V_5 ;
}
V_2 -> V_201 = 400000 ;
V_2 -> V_202 = 288000000 ;
V_2 -> V_203 = V_204 | V_205 ;
V_2 -> V_206 = 52 ;
V_2 -> V_207 = 1 << 0xf ;
V_2 -> V_208 = ( F_42 ( V_4 ) ) ? 0xff : 0xffffff ;
V_2 -> V_209 = ( F_42 ( V_4 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_210 = F_72 ( V_4 -> V_70 -> V_211 -> V_162 ) ;
F_73 ( V_158 , V_2 ) ;
V_172 = F_74 ( & V_158 -> V_162 , V_173 , F_25 , 0 ,
V_212 , V_4 ) ;
if ( V_172 )
goto V_213;
F_75 ( & V_4 -> V_48 ) ;
V_172 = F_76 ( V_2 ) ;
if ( V_172 )
goto V_213;
F_77 ( F_21 ( V_4 -> V_2 ) , L_10 ) ;
return 0 ;
V_213:
if ( V_4 -> V_70 )
F_78 ( V_4 -> V_70 ) ;
V_188:
F_79 ( V_4 -> V_141 ) ;
F_80 ( V_4 -> V_141 ) ;
V_180:
F_81 ( V_2 ) ;
return V_172 ;
}
static int F_82 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_83 ( V_158 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_84 ( V_2 ) ;
F_73 ( V_158 , NULL ) ;
if ( V_4 -> V_70 )
F_78 ( V_4 -> V_70 ) ;
F_79 ( V_4 -> V_141 ) ;
F_80 ( V_4 -> V_141 ) ;
F_81 ( V_2 ) ;
return 0 ;
}
static int F_85 ( struct V_211 * V_162 )
{
struct V_1 * V_2 = F_86 ( V_162 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_172 = 0 ;
V_172 = F_87 ( V_2 ) ;
F_79 ( V_4 -> V_141 ) ;
return V_172 ;
}
static int F_88 ( struct V_211 * V_162 )
{
struct V_1 * V_2 = F_86 ( V_162 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_172 = 0 ;
F_67 ( V_4 -> V_141 ) ;
V_172 = F_89 ( V_2 ) ;
return V_172 ;
}
