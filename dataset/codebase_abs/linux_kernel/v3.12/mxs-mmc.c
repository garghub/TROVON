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
return V_4 -> V_11 || V_4 -> V_12 ||
! ( F_6 ( V_10 -> V_13 + F_7 ( V_10 ) ) &
V_14 ) ^ V_4 -> V_15 ;
}
static int F_8 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_16 , V_17 ;
int V_5 ;
V_5 = F_9 ( V_10 -> V_13 ) ;
if ( V_5 )
return V_5 ;
V_16 = V_18 ;
V_17 = F_10 ( 0x3 , V_19 ) |
F_10 ( 0x7 , V_20 ) |
V_21 |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 ;
F_11 ( F_10 ( 0xffff , V_28 ) |
F_10 ( 2 , V_29 ) |
F_10 ( 0 , V_30 ) ,
V_10 -> V_13 + F_12 ( V_10 ) ) ;
if ( V_4 -> V_31 ) {
V_16 |= V_32 ;
V_17 |= V_33 ;
}
F_11 ( V_16 , V_10 -> V_13 + V_34 ) ;
F_11 ( V_17 , V_10 -> V_13 + F_13 ( V_10 ) ) ;
return 0 ;
}
static void F_14 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_4 -> V_38 ;
struct V_39 * V_40 = V_4 -> V_40 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
if ( F_15 ( V_36 ) & V_41 ) {
if ( F_15 ( V_36 ) & V_42 ) {
V_36 -> V_43 [ 3 ] = F_6 ( V_10 -> V_13 + F_16 ( V_10 ) ) ;
V_36 -> V_43 [ 2 ] = F_6 ( V_10 -> V_13 + F_17 ( V_10 ) ) ;
V_36 -> V_43 [ 1 ] = F_6 ( V_10 -> V_13 + F_18 ( V_10 ) ) ;
V_36 -> V_43 [ 0 ] = F_6 ( V_10 -> V_13 + F_19 ( V_10 ) ) ;
} else {
V_36 -> V_43 [ 0 ] = F_6 ( V_10 -> V_13 + F_16 ( V_10 ) ) ;
}
}
if ( V_38 ) {
F_20 ( F_21 ( V_4 -> V_2 ) , V_38 -> V_44 ,
V_38 -> V_45 , V_10 -> V_46 ) ;
if ( ! V_38 -> error )
V_38 -> V_47 = V_38 -> V_48 * V_38 -> V_49 ;
else
V_38 -> V_47 = 0 ;
V_4 -> V_38 = NULL ;
if ( V_40 -> V_50 ) {
F_22 ( V_4 , V_40 -> V_50 ) ;
return;
}
}
V_4 -> V_40 = NULL ;
F_23 ( V_4 -> V_2 , V_40 ) ;
}
static void F_24 ( void * V_51 )
{
struct V_3 * V_4 = V_51 ;
F_14 ( V_4 ) ;
}
static T_2 F_25 ( int V_52 , void * V_53 )
{
struct V_3 * V_4 = V_53 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_4 -> V_38 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_54 ;
F_26 ( & V_4 -> V_55 ) ;
V_54 = F_6 ( V_10 -> V_13 + F_13 ( V_10 ) ) ;
F_11 ( V_54 & V_56 ,
V_10 -> V_13 + F_13 ( V_10 ) + V_57 ) ;
F_27 ( & V_4 -> V_55 ) ;
if ( ( V_54 & V_58 ) && ( V_54 & V_33 ) )
F_28 ( V_4 -> V_2 ) ;
if ( V_54 & V_59 )
V_36 -> error = - V_60 ;
else if ( V_54 & V_61 )
V_36 -> error = - V_62 ;
if ( V_38 ) {
if ( V_54 & ( V_63 |
V_64 ) )
V_38 -> error = - V_60 ;
else if ( V_54 & V_65 )
V_38 -> error = - V_66 ;
else if ( V_54 & ( V_67 |
V_68 ) )
V_38 -> error = - V_62 ;
}
return V_69 ;
}
static struct V_70 * F_29 (
struct V_3 * V_4 , unsigned long V_71 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_70 * V_72 ;
struct V_37 * V_38 = V_4 -> V_38 ;
struct V_73 * V_74 ;
unsigned int V_45 ;
if ( V_38 ) {
F_30 ( F_21 ( V_4 -> V_2 ) , V_38 -> V_44 ,
V_38 -> V_45 , V_10 -> V_46 ) ;
V_74 = V_38 -> V_44 ;
V_45 = V_38 -> V_45 ;
} else {
V_74 = (struct V_73 * ) V_10 -> V_75 ;
V_45 = V_76 ;
}
V_72 = F_31 ( V_10 -> V_77 ,
V_74 , V_45 , V_10 -> V_78 , V_71 ) ;
if ( V_72 ) {
V_72 -> V_79 = F_24 ;
V_72 -> V_80 = V_4 ;
} else {
if ( V_38 )
F_20 ( F_21 ( V_4 -> V_2 ) , V_38 -> V_44 ,
V_38 -> V_45 , V_10 -> V_46 ) ;
}
return V_72 ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_70 * V_72 ;
T_1 V_16 , V_81 , V_82 ;
V_16 = V_83 | V_18 ;
V_81 = F_10 ( V_36 -> V_84 , V_85 ) | V_86 ;
V_82 = V_36 -> V_87 ;
if ( V_4 -> V_31 ) {
V_16 |= V_32 ;
V_81 |= V_88 | V_89 ;
}
V_10 -> V_75 [ 0 ] = V_16 ;
V_10 -> V_75 [ 1 ] = V_81 ;
V_10 -> V_75 [ 2 ] = V_82 ;
V_10 -> V_46 = V_90 ;
V_10 -> V_78 = V_91 ;
V_72 = F_29 ( V_4 , V_92 ) ;
if ( ! V_72 )
goto V_93;
F_33 ( V_72 ) ;
F_34 ( V_10 -> V_77 ) ;
return;
V_93:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_94 ) ;
}
static void F_36 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = & V_4 -> V_10 ;
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_70 * V_72 ;
T_1 V_95 , V_96 , V_97 ;
T_1 V_16 , V_81 , V_82 ;
V_95 = ( F_15 ( V_36 ) & V_98 ) ?
0 : V_18 ;
V_96 = ( F_15 ( V_36 ) & V_41 ) ?
V_99 : 0 ;
V_97 = ( F_15 ( V_36 ) & V_42 ) ?
V_100 : 0 ;
V_16 = V_83 | V_95 | V_96 | V_97 ;
V_81 = F_10 ( V_36 -> V_84 , V_85 ) ;
V_82 = V_36 -> V_87 ;
if ( V_4 -> V_31 ) {
V_16 |= V_32 ;
V_81 |= V_88 | V_89 ;
}
V_10 -> V_75 [ 0 ] = V_16 ;
V_10 -> V_75 [ 1 ] = V_81 ;
V_10 -> V_75 [ 2 ] = V_82 ;
V_10 -> V_46 = V_90 ;
V_10 -> V_78 = V_91 ;
V_72 = F_29 ( V_4 , V_92 ) ;
if ( ! V_72 )
goto V_93;
F_33 ( V_72 ) ;
F_34 ( V_10 -> V_77 ) ;
return;
V_93:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_94 ) ;
}
static unsigned short F_37 ( unsigned V_101 , unsigned V_102 )
{
const unsigned int V_103 = 4096 ;
const unsigned int V_104 = V_101 / 1000 ;
const unsigned int V_105 = V_102 / 1000 ;
const unsigned int V_106 = V_105 * V_104 ;
const unsigned int V_107 = V_106 / V_103 ;
F_38 ( V_107 == 0 ) ;
return V_107 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_35 * V_36 = V_4 -> V_36 ;
struct V_37 * V_38 = V_36 -> V_38 ;
struct V_70 * V_72 ;
struct V_73 * V_74 = V_38 -> V_44 , * V_44 ;
unsigned int V_45 = V_38 -> V_45 ;
unsigned int V_108 ;
unsigned short V_109 , V_110 ;
enum V_111 V_78 ;
unsigned int V_112 = 0 , V_113 ;
unsigned int V_48 = V_38 -> V_48 ;
struct V_9 * V_10 = & V_4 -> V_10 ;
T_1 V_95 , V_96 , V_97 , V_114 ;
T_1 V_16 , V_81 , V_82 , V_115 ;
V_95 = ( F_15 ( V_36 ) & V_98 ) ?
0 : V_18 ;
V_96 = ( F_15 ( V_36 ) & V_41 ) ?
V_99 : 0 ;
V_97 = ( F_15 ( V_36 ) & V_42 ) ?
V_100 : 0 ;
if ( V_38 -> V_71 & V_116 ) {
V_109 = V_117 ;
V_78 = V_118 ;
V_114 = 0 ;
} else {
V_109 = V_119 ;
V_78 = V_120 ;
V_114 = V_121 ;
}
V_16 = F_10 ( V_4 -> V_122 , V_123 ) |
V_95 | V_96 | V_97 |
V_124 | V_114 |
V_125 |
V_83 ;
V_81 = F_10 ( V_36 -> V_84 , V_85 ) ;
V_113 = F_40 ( V_38 -> V_49 ) ;
F_41 (sgl, sg, sg_len, i)
V_112 += V_44 -> V_126 ;
if ( V_112 != V_38 -> V_48 * V_38 -> V_49 )
V_48 = 1 ;
if ( F_42 ( V_10 ) ) {
V_16 |= F_10 ( V_112 , V_127 ) ;
V_81 |= F_10 ( V_113 , V_128 ) |
F_10 ( V_48 - 1 , V_129 ) ;
} else {
F_11 ( V_112 , V_10 -> V_13 + V_130 ) ;
F_11 ( F_10 ( V_113 , V_131 ) |
F_10 ( V_48 - 1 , V_132 ) ,
V_10 -> V_13 + V_133 ) ;
}
if ( ( V_36 -> V_84 == V_134 ) ||
( V_36 -> V_84 == V_135 ) )
V_81 |= V_86 ;
V_82 = V_36 -> V_87 ;
if ( V_4 -> V_31 ) {
V_16 |= V_32 ;
V_81 |= V_88 | V_89 ;
}
V_110 = F_37 ( V_10 -> V_136 , V_38 -> V_137 ) ;
V_115 = F_6 ( V_10 -> V_13 + F_12 ( V_10 ) ) ;
V_115 &= ~ ( V_138 ) ;
V_115 |= F_10 ( V_110 , V_28 ) ;
F_11 ( V_115 , V_10 -> V_13 + F_12 ( V_10 ) ) ;
V_10 -> V_75 [ 0 ] = V_16 ;
V_10 -> V_75 [ 1 ] = V_81 ;
V_10 -> V_75 [ 2 ] = V_82 ;
V_10 -> V_46 = V_90 ;
V_10 -> V_78 = V_91 ;
V_72 = F_29 ( V_4 , 0 ) ;
if ( ! V_72 )
goto V_93;
F_38 ( V_4 -> V_38 != NULL ) ;
V_4 -> V_38 = V_38 ;
V_10 -> V_46 = V_109 ;
V_10 -> V_78 = V_78 ;
V_72 = F_29 ( V_4 , V_139 | V_92 ) ;
if ( ! V_72 )
goto V_93;
F_33 ( V_72 ) ;
F_34 ( V_10 -> V_77 ) ;
return;
V_93:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_1 , V_94 ) ;
}
static void F_22 ( struct V_3 * V_4 ,
struct V_35 * V_36 )
{
V_4 -> V_36 = V_36 ;
switch ( F_43 ( V_36 ) ) {
case V_140 :
F_32 ( V_4 ) ;
break;
case V_141 :
F_36 ( V_4 ) ;
break;
case V_142 :
F_36 ( V_4 ) ;
break;
case V_143 :
F_39 ( V_4 ) ;
break;
default:
F_35 ( F_21 ( V_4 -> V_2 ) ,
L_2 , V_94 ) ;
break;
}
}
static void F_44 ( struct V_1 * V_2 , struct V_39 * V_40 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_38 ( V_4 -> V_40 != NULL ) ;
V_4 -> V_40 = V_40 ;
F_22 ( V_4 , V_40 -> V_36 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_144 * V_145 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_145 -> V_122 == V_146 )
V_4 -> V_122 = 2 ;
else if ( V_145 -> V_122 == V_147 )
V_4 -> V_122 = 1 ;
else
V_4 -> V_122 = 0 ;
if ( V_145 -> clock )
F_46 ( & V_4 -> V_10 , V_145 -> clock ) ;
}
static void F_47 ( struct V_1 * V_2 , int V_148 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
unsigned long V_71 ;
F_48 ( & V_4 -> V_55 , V_71 ) ;
V_4 -> V_31 = V_148 ;
if ( V_148 ) {
F_11 ( V_32 ,
V_10 -> V_13 + V_34 + V_149 ) ;
F_11 ( V_33 ,
V_10 -> V_13 + F_13 ( V_10 ) + V_149 ) ;
} else {
F_11 ( V_32 ,
V_10 -> V_13 + V_34 + V_57 ) ;
F_11 ( V_33 ,
V_10 -> V_13 + F_13 ( V_10 ) + V_57 ) ;
}
F_49 ( & V_4 -> V_55 , V_71 ) ;
if ( V_148 && F_6 ( V_10 -> V_13 + F_7 ( V_10 ) ) &
V_150 )
F_28 ( V_4 -> V_2 ) ;
}
static int F_50 ( struct V_151 * V_152 )
{
const struct V_153 * V_154 =
F_51 ( V_155 , & V_152 -> V_156 ) ;
struct V_157 * V_158 = V_152 -> V_156 . V_159 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_160 * V_161 ;
int V_5 = 0 , V_162 ;
struct V_163 * V_164 ;
enum V_165 V_71 ;
struct V_9 * V_10 ;
T_1 V_122 = 0 ;
V_161 = F_52 ( V_152 , V_166 , 0 ) ;
V_162 = F_53 ( V_152 , 0 ) ;
if ( ! V_161 || V_162 < 0 )
return - V_7 ;
V_2 = F_54 ( sizeof( struct V_3 ) , & V_152 -> V_156 ) ;
if ( ! V_2 )
return - V_167 ;
V_4 = F_2 ( V_2 ) ;
V_10 = & V_4 -> V_10 ;
V_10 -> V_156 = & V_152 -> V_156 ;
V_10 -> V_13 = F_55 ( & V_152 -> V_156 , V_161 ) ;
if ( F_56 ( V_10 -> V_13 ) ) {
V_5 = F_57 ( V_10 -> V_13 ) ;
goto V_168;
}
V_10 -> V_169 = (enum V_170 ) V_154 -> V_38 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_31 = 0 ;
V_164 = F_58 ( & V_152 -> V_156 , L_3 ) ;
if ( ! F_56 ( V_164 ) ) {
V_5 = F_59 ( V_164 ) ;
if ( V_5 ) {
F_60 ( & V_152 -> V_156 ,
L_4 , V_5 ) ;
goto V_168;
}
}
V_10 -> V_171 = F_61 ( & V_152 -> V_156 , NULL ) ;
if ( F_56 ( V_10 -> V_171 ) ) {
V_5 = F_57 ( V_10 -> V_171 ) ;
goto V_168;
}
F_62 ( V_10 -> V_171 ) ;
V_5 = F_8 ( V_4 ) ;
if ( V_5 ) {
F_60 ( & V_152 -> V_156 , L_5 , V_5 ) ;
goto V_172;
}
V_10 -> V_77 = F_63 ( & V_152 -> V_156 , L_6 ) ;
if ( ! V_10 -> V_77 ) {
F_60 ( F_21 ( V_4 -> V_2 ) ,
L_7 , V_94 ) ;
V_5 = - V_173 ;
goto V_172;
}
V_2 -> V_174 = & V_175 ;
V_2 -> V_176 = V_177 | V_178 |
V_179 | V_180 ;
F_64 ( V_158 , L_8 , & V_122 ) ;
if ( V_122 == 4 )
V_2 -> V_176 |= V_181 ;
else if ( V_122 == 8 )
V_2 -> V_176 |= V_181 | V_182 ;
V_4 -> V_12 = F_65 ( V_158 , L_9 ) ;
V_4 -> V_11 = F_65 ( V_158 , L_10 ) ;
if ( V_4 -> V_11 )
V_2 -> V_176 |= V_183 ;
V_4 -> V_6 = F_66 ( V_158 , L_11 , 0 , & V_71 ) ;
if ( V_71 & V_184 )
V_4 -> V_8 = 1 ;
V_4 -> V_15 = F_65 ( V_158 , L_12 ) ;
V_2 -> V_185 = 400000 ;
V_2 -> V_186 = 288000000 ;
V_2 -> V_187 = V_188 | V_189 ;
V_2 -> V_190 = 52 ;
V_2 -> V_191 = 1 << 0xf ;
V_2 -> V_192 = ( F_42 ( V_10 ) ) ? 0xff : 0xffffff ;
V_2 -> V_193 = ( F_42 ( V_10 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_194 = F_67 ( V_10 -> V_77 -> V_195 -> V_156 ) ;
F_68 ( V_152 , V_2 ) ;
V_5 = F_69 ( & V_152 -> V_156 , V_162 , F_25 , 0 ,
V_196 , V_4 ) ;
if ( V_5 )
goto V_197;
F_70 ( & V_4 -> V_55 ) ;
V_5 = F_71 ( V_2 ) ;
if ( V_5 )
goto V_197;
F_72 ( F_21 ( V_4 -> V_2 ) , L_13 ) ;
return 0 ;
V_197:
if ( V_10 -> V_77 )
F_73 ( V_10 -> V_77 ) ;
V_172:
F_74 ( V_10 -> V_171 ) ;
V_168:
F_75 ( V_2 ) ;
return V_5 ;
}
static int F_76 ( struct V_151 * V_152 )
{
struct V_1 * V_2 = F_77 ( V_152 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
F_78 ( V_2 ) ;
if ( V_10 -> V_77 )
F_73 ( V_10 -> V_77 ) ;
F_74 ( V_10 -> V_171 ) ;
F_75 ( V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_195 * V_156 )
{
struct V_1 * V_2 = F_80 ( V_156 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
int V_5 = 0 ;
V_5 = F_81 ( V_2 ) ;
F_74 ( V_10 -> V_171 ) ;
return V_5 ;
}
static int F_82 ( struct V_195 * V_156 )
{
struct V_1 * V_2 = F_80 ( V_156 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = & V_4 -> V_10 ;
int V_5 = 0 ;
F_62 ( V_10 -> V_171 ) ;
V_5 = F_83 ( V_2 ) ;
return V_5 ;
}
