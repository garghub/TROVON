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
struct V_9 * V_10 = & V_4 -> V_10 ;
return ! ( F_6 ( V_10 -> V_11 + F_7 ( V_10 ) ) &
V_12 ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_13 , V_14 ;
F_9 ( V_10 -> V_11 ) ;
V_13 = V_15 ;
V_14 = F_10 ( 0x3 , V_16 ) |
F_10 ( 0x7 , V_17 ) |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 ;
F_11 ( F_10 ( 0xffff , V_25 ) |
F_10 ( 2 , V_26 ) |
F_10 ( 0 , V_27 ) ,
V_10 -> V_11 + F_12 ( V_10 ) ) ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_14 |= V_30 ;
}
F_11 ( V_13 , V_10 -> V_11 + V_31 ) ;
F_11 ( V_14 , V_10 -> V_11 + F_13 ( V_10 ) ) ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
if ( F_15 ( V_33 ) & V_38 ) {
if ( F_15 ( V_33 ) & V_39 ) {
V_33 -> V_40 [ 3 ] = F_6 ( V_10 -> V_11 + F_16 ( V_10 ) ) ;
V_33 -> V_40 [ 2 ] = F_6 ( V_10 -> V_11 + F_17 ( V_10 ) ) ;
V_33 -> V_40 [ 1 ] = F_6 ( V_10 -> V_11 + F_18 ( V_10 ) ) ;
V_33 -> V_40 [ 0 ] = F_6 ( V_10 -> V_11 + F_19 ( V_10 ) ) ;
} else {
V_33 -> V_40 [ 0 ] = F_6 ( V_10 -> V_11 + F_16 ( V_10 ) ) ;
}
}
if ( V_35 ) {
F_20 ( F_21 ( V_4 -> V_2 ) , V_35 -> V_41 ,
V_35 -> V_42 , V_10 -> V_43 ) ;
if ( ! V_35 -> error )
V_35 -> V_44 = V_35 -> V_45 * V_35 -> V_46 ;
else
V_35 -> V_44 = 0 ;
V_4 -> V_35 = NULL ;
if ( V_37 -> V_47 ) {
F_22 ( V_4 , V_37 -> V_47 ) ;
return;
}
}
V_4 -> V_37 = NULL ;
F_23 ( V_4 -> V_2 , V_37 ) ;
}
static void F_24 ( void * V_48 )
{
struct V_3 * V_4 = V_48 ;
F_14 ( V_4 ) ;
}
static T_2 F_25 ( int V_49 , void * V_50 )
{
struct V_3 * V_4 = V_50 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_51 ;
F_26 ( & V_4 -> V_52 ) ;
V_51 = F_6 ( V_10 -> V_11 + F_13 ( V_10 ) ) ;
F_11 ( V_51 & V_53 ,
V_10 -> V_11 + F_13 ( V_10 ) + V_54 ) ;
F_27 ( & V_4 -> V_52 ) ;
if ( ( V_51 & V_55 ) && ( V_51 & V_30 ) )
F_28 ( V_4 -> V_2 ) ;
if ( V_51 & V_56 )
V_33 -> error = - V_57 ;
else if ( V_51 & V_58 )
V_33 -> error = - V_59 ;
if ( V_35 ) {
if ( V_51 & ( V_60 |
V_61 ) )
V_35 -> error = - V_57 ;
else if ( V_51 & V_62 )
V_35 -> error = - V_63 ;
else if ( V_51 & ( V_64 |
V_65 ) )
V_35 -> error = - V_59 ;
}
return V_66 ;
}
static struct V_67 * F_29 (
struct V_3 * V_4 , unsigned long V_68 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_67 * V_69 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_70 * V_71 ;
unsigned int V_42 ;
if ( V_35 ) {
F_30 ( F_21 ( V_4 -> V_2 ) , V_35 -> V_41 ,
V_35 -> V_42 , V_10 -> V_43 ) ;
V_71 = V_35 -> V_41 ;
V_42 = V_35 -> V_42 ;
} else {
V_71 = (struct V_70 * ) V_10 -> V_72 ;
V_42 = V_73 ;
}
V_69 = F_31 ( V_10 -> V_74 ,
V_71 , V_42 , V_10 -> V_75 , V_68 ) ;
if ( V_69 ) {
V_69 -> V_76 = F_24 ;
V_69 -> V_77 = V_4 ;
} else {
if ( V_35 )
F_20 ( F_21 ( V_4 -> V_2 ) , V_35 -> V_41 ,
V_35 -> V_42 , V_10 -> V_43 ) ;
}
return V_69 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_67 * V_69 ;
T_1 V_13 , V_78 , V_79 ;
V_13 = V_80 | V_15 ;
V_78 = F_10 ( V_33 -> V_81 , V_82 ) | V_83 ;
V_79 = V_33 -> V_84 ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_78 |= V_85 | V_86 ;
}
V_10 -> V_72 [ 0 ] = V_13 ;
V_10 -> V_72 [ 1 ] = V_78 ;
V_10 -> V_72 [ 2 ] = V_79 ;
V_10 -> V_43 = V_87 ;
V_10 -> V_75 = V_88 ;
V_69 = F_29 ( V_4 , V_89 ) ;
if ( ! V_69 )
goto V_90;
F_33 ( V_69 ) ;
F_34 ( V_10 -> V_74 ) ;
return;
V_90:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_91 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_67 * V_69 ;
T_1 V_92 , V_93 , V_94 ;
T_1 V_13 , V_78 , V_79 ;
V_92 = ( F_15 ( V_33 ) & V_95 ) ?
0 : V_15 ;
V_93 = ( F_15 ( V_33 ) & V_38 ) ?
V_96 : 0 ;
V_94 = ( F_15 ( V_33 ) & V_39 ) ?
V_97 : 0 ;
V_13 = V_80 | V_92 | V_93 | V_94 ;
V_78 = F_10 ( V_33 -> V_81 , V_82 ) ;
V_79 = V_33 -> V_84 ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_78 |= V_85 | V_86 ;
}
V_10 -> V_72 [ 0 ] = V_13 ;
V_10 -> V_72 [ 1 ] = V_78 ;
V_10 -> V_72 [ 2 ] = V_79 ;
V_10 -> V_43 = V_87 ;
V_10 -> V_75 = V_88 ;
V_69 = F_29 ( V_4 , V_89 ) ;
if ( ! V_69 )
goto V_90;
F_33 ( V_69 ) ;
F_34 ( V_10 -> V_74 ) ;
return;
V_90:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_91 ) ;
}
static unsigned short F_37 ( unsigned V_98 , unsigned V_99 )
{
const unsigned int V_100 = 4096 ;
const unsigned int V_101 = V_98 / 1000 ;
const unsigned int V_102 = V_99 / 1000 ;
const unsigned int V_103 = V_102 * V_101 ;
const unsigned int V_104 = V_103 / V_100 ;
F_38 ( V_104 == 0 ) ;
return V_104 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_67 * V_69 ;
struct V_70 * V_71 = V_35 -> V_41 , * V_41 ;
unsigned int V_42 = V_35 -> V_42 ;
unsigned int V_105 ;
unsigned short V_106 , V_107 ;
enum V_108 V_75 ;
unsigned int V_109 = 0 , V_110 ;
unsigned int V_45 = V_35 -> V_45 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_92 , V_93 , V_94 , V_111 ;
T_1 V_13 , V_78 , V_79 , V_112 ;
V_92 = ( F_15 ( V_33 ) & V_95 ) ?
0 : V_15 ;
V_93 = ( F_15 ( V_33 ) & V_38 ) ?
V_96 : 0 ;
V_94 = ( F_15 ( V_33 ) & V_39 ) ?
V_97 : 0 ;
if ( V_35 -> V_68 & V_113 ) {
V_106 = V_114 ;
V_75 = V_115 ;
V_111 = 0 ;
} else {
V_106 = V_116 ;
V_75 = V_117 ;
V_111 = V_118 ;
}
V_13 = F_10 ( V_4 -> V_119 , V_120 ) |
V_92 | V_93 | V_94 |
V_121 | V_111 |
V_122 |
V_80 ;
V_78 = F_10 ( V_33 -> V_81 , V_82 ) ;
V_110 = F_40 ( V_35 -> V_46 ) ;
F_41 (sgl, sg, sg_len, i)
V_109 += V_41 -> V_123 ;
if ( V_109 != V_35 -> V_45 * V_35 -> V_46 )
V_45 = 1 ;
if ( F_42 ( V_10 ) ) {
V_13 |= F_10 ( V_109 , V_124 ) ;
V_78 |= F_10 ( V_110 , V_125 ) |
F_10 ( V_45 - 1 , V_126 ) ;
} else {
F_11 ( V_109 , V_10 -> V_11 + V_127 ) ;
F_11 ( F_10 ( V_110 , V_128 ) |
F_10 ( V_45 - 1 , V_129 ) ,
V_10 -> V_11 + V_130 ) ;
}
if ( ( V_33 -> V_81 == V_131 ) ||
( V_33 -> V_81 == V_132 ) )
V_78 |= V_83 ;
V_79 = V_33 -> V_84 ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_78 |= V_85 | V_86 ;
}
V_107 = F_37 ( V_10 -> V_133 , V_35 -> V_134 ) ;
V_112 = F_6 ( V_10 -> V_11 + F_12 ( V_10 ) ) ;
V_112 &= ~ ( V_135 ) ;
V_112 |= F_10 ( V_107 , V_25 ) ;
F_11 ( V_112 , V_10 -> V_11 + F_12 ( V_10 ) ) ;
V_10 -> V_72 [ 0 ] = V_13 ;
V_10 -> V_72 [ 1 ] = V_78 ;
V_10 -> V_72 [ 2 ] = V_79 ;
V_10 -> V_43 = V_87 ;
V_10 -> V_75 = V_88 ;
V_69 = F_29 ( V_4 , 0 ) ;
if ( ! V_69 )
goto V_90;
F_38 ( V_4 -> V_35 != NULL ) ;
V_4 -> V_35 = V_35 ;
V_10 -> V_43 = V_106 ;
V_10 -> V_75 = V_75 ;
V_69 = F_29 ( V_4 , V_136 | V_89 ) ;
if ( ! V_69 )
goto V_90;
F_33 ( V_69 ) ;
F_34 ( V_10 -> V_74 ) ;
return;
V_90:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_91 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_32 * V_33 )
{
V_4 -> V_33 = V_33 ;
switch ( F_43 ( V_33 ) ) {
case V_137 :
F_32 ( V_4 ) ;
break;
case V_138 :
F_36 ( V_4 ) ;
break;
case V_139 :
F_36 ( V_4 ) ;
break;
case V_140 :
F_39 ( V_4 ) ;
break;
default:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_2 , V_91 ) ;
break;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_4 -> V_37 != NULL ) ;
V_4 -> V_37 = V_37 ;
F_22 ( V_4 , V_37 -> V_33 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_142 -> V_119 == V_143 )
V_4 -> V_119 = 2 ;
else if ( V_142 -> V_119 == V_144 )
V_4 -> V_119 = 1 ;
else
V_4 -> V_119 = 0 ;
if ( V_142 -> clock )
F_46 ( & V_4 -> V_10 , V_142 -> clock ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_145 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned long V_68 ;
F_48 ( & V_4 -> V_52 , V_68 ) ;
V_4 -> V_28 = V_145 ;
if ( V_145 ) {
F_11 ( V_29 ,
V_10 -> V_11 + V_31 + V_146 ) ;
F_11 ( V_30 ,
V_10 -> V_11 + F_13 ( V_10 ) + V_146 ) ;
} else {
F_11 ( V_29 ,
V_10 -> V_11 + V_31 + V_54 ) ;
F_11 ( V_30 ,
V_10 -> V_11 + F_13 ( V_10 ) + V_54 ) ;
}
F_49 ( & V_4 -> V_52 , V_68 ) ;
if ( V_145 && F_6 ( V_10 -> V_11 + F_7 ( V_10 ) ) &
V_147 )
F_28 ( V_4 -> V_2 ) ;
}
static bool F_50 ( struct V_148 * V_149 , void * V_48 )
{
struct V_3 * V_4 = V_48 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
if ( ! F_51 ( V_149 ) )
return false ;
if ( V_149 -> V_150 != V_10 -> V_151 )
return false ;
V_149 -> V_152 = & V_10 -> V_153 ;
return true ;
}
static int F_52 ( struct V_154 * V_155 )
{
const struct V_156 * V_157 =
F_53 ( V_158 , & V_155 -> V_159 ) ;
struct V_160 * V_161 = V_155 -> V_159 . V_162 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_163 * V_164 , * V_165 ;
struct V_166 * V_166 ;
int V_5 = 0 , V_167 , V_168 ;
T_3 V_169 ;
struct V_170 * V_171 ;
enum V_172 V_68 ;
struct V_9 * V_10 ;
T_1 V_119 = 0 ;
V_164 = F_54 ( V_155 , V_173 , 0 ) ;
V_165 = F_54 ( V_155 , V_174 , 0 ) ;
V_167 = F_55 ( V_155 , 0 ) ;
V_168 = F_55 ( V_155 , 1 ) ;
if ( ! V_164 || V_167 < 0 || V_168 < 0 )
return - V_7 ;
V_2 = F_56 ( sizeof( struct V_3 ) , & V_155 -> V_159 ) ;
if ( ! V_2 )
return - V_175 ;
V_4 = F_2 ( V_2 ) ;
V_10 = & V_4 -> V_10 ;
V_10 -> V_159 = & V_155 -> V_159 ;
V_10 -> V_11 = F_57 ( & V_155 -> V_159 , V_164 ) ;
if ( F_58 ( V_10 -> V_11 ) ) {
V_5 = F_59 ( V_10 -> V_11 ) ;
goto V_176;
}
if ( V_161 ) {
V_10 -> V_177 = (enum V_178 ) V_157 -> V_35 ;
V_5 = F_60 ( V_161 , L_3 ,
& V_10 -> V_151 ) ;
if ( V_5 ) {
F_61 ( F_21 ( V_4 -> V_2 ) ,
L_4 ) ;
goto V_176;
}
} else {
V_10 -> V_177 = V_155 -> V_179 -> V_180 ;
V_10 -> V_151 = V_165 -> V_181 ;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_28 = 0 ;
V_171 = F_62 ( & V_155 -> V_159 , L_5 ) ;
if ( ! F_58 ( V_171 ) ) {
V_5 = F_63 ( V_171 ) ;
if ( V_5 ) {
F_61 ( & V_155 -> V_159 ,
L_6 , V_5 ) ;
goto V_176;
}
}
V_166 = F_64 ( & V_155 -> V_159 ) ;
if ( F_58 ( V_166 ) ) {
V_5 = F_59 ( V_166 ) ;
goto V_176;
}
V_10 -> V_182 = F_65 ( & V_155 -> V_159 , NULL ) ;
if ( F_58 ( V_10 -> V_182 ) ) {
V_5 = F_59 ( V_10 -> V_182 ) ;
goto V_176;
}
F_66 ( V_10 -> V_182 ) ;
F_8 ( V_4 ) ;
F_67 ( V_169 ) ;
F_68 ( V_183 , V_169 ) ;
V_10 -> V_153 . V_184 = V_168 ;
V_10 -> V_74 = F_69 ( V_169 , F_50 , V_4 ) ;
if ( ! V_10 -> V_74 ) {
F_61 ( F_21 ( V_4 -> V_2 ) ,
L_7 , V_91 ) ;
goto V_185;
}
V_2 -> V_186 = & V_187 ;
V_2 -> V_188 = V_189 | V_190 |
V_191 | V_192 ;
F_60 ( V_161 , L_8 , & V_119 ) ;
if ( V_119 == 4 )
V_2 -> V_188 |= V_193 ;
else if ( V_119 == 8 )
V_2 -> V_188 |= V_193 | V_194 ;
V_4 -> V_6 = F_70 ( V_161 , L_9 , 0 , & V_68 ) ;
if ( V_68 & V_195 )
V_4 -> V_8 = 1 ;
V_2 -> V_196 = 400000 ;
V_2 -> V_197 = 288000000 ;
V_2 -> V_198 = V_199 | V_200 ;
V_2 -> V_201 = 52 ;
V_2 -> V_202 = 1 << 0xf ;
V_2 -> V_203 = ( F_42 ( V_10 ) ) ? 0xff : 0xffffff ;
V_2 -> V_204 = ( F_42 ( V_10 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_205 = F_71 ( V_10 -> V_74 -> V_206 -> V_159 ) ;
F_72 ( V_155 , V_2 ) ;
V_5 = F_73 ( & V_155 -> V_159 , V_167 , F_25 , 0 ,
V_207 , V_4 ) ;
if ( V_5 )
goto V_208;
F_74 ( & V_4 -> V_52 ) ;
V_5 = F_75 ( V_2 ) ;
if ( V_5 )
goto V_208;
F_76 ( F_21 ( V_4 -> V_2 ) , L_10 ) ;
return 0 ;
V_208:
if ( V_10 -> V_74 )
F_77 ( V_10 -> V_74 ) ;
V_185:
F_78 ( V_10 -> V_182 ) ;
F_79 ( V_10 -> V_182 ) ;
V_176:
F_80 ( V_2 ) ;
return V_5 ;
}
static int F_81 ( struct V_154 * V_155 )
{
struct V_1 * V_2 = F_82 ( V_155 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
F_83 ( V_2 ) ;
F_72 ( V_155 , NULL ) ;
if ( V_10 -> V_74 )
F_77 ( V_10 -> V_74 ) ;
F_78 ( V_10 -> V_182 ) ;
F_79 ( V_10 -> V_182 ) ;
F_80 ( V_2 ) ;
return 0 ;
}
static int F_84 ( struct V_206 * V_159 )
{
struct V_1 * V_2 = F_85 ( V_159 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
int V_5 = 0 ;
V_5 = F_86 ( V_2 ) ;
F_78 ( V_10 -> V_182 ) ;
return V_5 ;
}
static int F_87 ( struct V_206 * V_159 )
{
struct V_1 * V_2 = F_85 ( V_159 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
int V_5 = 0 ;
F_66 ( V_10 -> V_182 ) ;
V_5 = F_88 ( V_2 ) ;
return V_5 ;
}
