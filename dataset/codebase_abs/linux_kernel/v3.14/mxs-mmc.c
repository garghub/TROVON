static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_7 , V_8 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 >= 0 )
return V_8 ;
V_7 = ! ( F_4 ( V_6 -> V_9 + F_5 ( V_6 ) ) &
V_10 ) ;
if ( V_2 -> V_11 & V_12 )
V_7 = ! V_7 ;
return V_7 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_13 , V_14 ;
int V_8 ;
V_8 = F_7 ( V_6 -> V_9 ) ;
if ( V_8 )
return V_8 ;
V_13 = V_15 ;
V_14 = F_8 ( 0x3 , V_16 ) |
F_8 ( 0x7 , V_17 ) |
V_18 |
V_19 |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 ;
F_9 ( F_8 ( 0xffff , V_25 ) |
F_8 ( 2 , V_26 ) |
F_8 ( 0 , V_27 ) ,
V_6 -> V_9 + F_10 ( V_6 ) ) ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_14 |= V_30 ;
}
F_9 ( V_13 , V_6 -> V_9 + V_31 ) ;
F_9 ( V_14 , V_6 -> V_9 + F_11 ( V_6 ) ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( F_13 ( V_33 ) & V_38 ) {
if ( F_13 ( V_33 ) & V_39 ) {
V_33 -> V_40 [ 3 ] = F_4 ( V_6 -> V_9 + F_14 ( V_6 ) ) ;
V_33 -> V_40 [ 2 ] = F_4 ( V_6 -> V_9 + F_15 ( V_6 ) ) ;
V_33 -> V_40 [ 1 ] = F_4 ( V_6 -> V_9 + F_16 ( V_6 ) ) ;
V_33 -> V_40 [ 0 ] = F_4 ( V_6 -> V_9 + F_17 ( V_6 ) ) ;
} else {
V_33 -> V_40 [ 0 ] = F_4 ( V_6 -> V_9 + F_14 ( V_6 ) ) ;
}
}
if ( V_35 ) {
F_18 ( F_19 ( V_4 -> V_2 ) , V_35 -> V_41 ,
V_35 -> V_42 , V_6 -> V_43 ) ;
if ( ! V_35 -> error )
V_35 -> V_44 = V_35 -> V_45 * V_35 -> V_46 ;
else
V_35 -> V_44 = 0 ;
V_4 -> V_35 = NULL ;
if ( V_37 -> V_47 ) {
F_20 ( V_4 , V_37 -> V_47 ) ;
return;
}
}
V_4 -> V_37 = NULL ;
F_21 ( V_4 -> V_2 , V_37 ) ;
}
static void F_22 ( void * V_48 )
{
struct V_3 * V_4 = V_48 ;
F_12 ( V_4 ) ;
}
static T_2 F_23 ( int V_49 , void * V_50 )
{
struct V_3 * V_4 = V_50 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_51 ;
F_24 ( & V_4 -> V_52 ) ;
V_51 = F_4 ( V_6 -> V_9 + F_11 ( V_6 ) ) ;
F_9 ( V_51 & V_53 ,
V_6 -> V_9 + F_11 ( V_6 ) + V_54 ) ;
F_25 ( & V_4 -> V_52 ) ;
if ( ( V_51 & V_55 ) && ( V_51 & V_30 ) )
F_26 ( V_4 -> V_2 ) ;
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
static struct V_67 * F_27 (
struct V_3 * V_4 , unsigned long V_68 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_67 * V_69 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_70 * V_71 ;
unsigned int V_42 ;
if ( V_35 ) {
F_28 ( F_19 ( V_4 -> V_2 ) , V_35 -> V_41 ,
V_35 -> V_42 , V_6 -> V_43 ) ;
V_71 = V_35 -> V_41 ;
V_42 = V_35 -> V_42 ;
} else {
V_71 = (struct V_70 * ) V_6 -> V_72 ;
V_42 = V_73 ;
}
V_69 = F_29 ( V_6 -> V_74 ,
V_71 , V_42 , V_6 -> V_75 , V_68 ) ;
if ( V_69 ) {
V_69 -> V_76 = F_22 ;
V_69 -> V_77 = V_4 ;
} else {
if ( V_35 )
F_18 ( F_19 ( V_4 -> V_2 ) , V_35 -> V_41 ,
V_35 -> V_42 , V_6 -> V_43 ) ;
}
return V_69 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_67 * V_69 ;
T_1 V_13 , V_78 , V_79 ;
V_13 = V_80 | V_15 ;
V_78 = F_8 ( V_33 -> V_81 , V_82 ) | V_83 ;
V_79 = V_33 -> V_84 ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_78 |= V_85 | V_86 ;
}
V_6 -> V_72 [ 0 ] = V_13 ;
V_6 -> V_72 [ 1 ] = V_78 ;
V_6 -> V_72 [ 2 ] = V_79 ;
V_6 -> V_43 = V_87 ;
V_6 -> V_75 = V_88 ;
V_69 = F_27 ( V_4 , V_89 ) ;
if ( ! V_69 )
goto V_90;
F_31 ( V_69 ) ;
F_32 ( V_6 -> V_74 ) ;
return;
V_90:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_91 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_32 * V_33 = V_4 -> V_33 ;
struct V_67 * V_69 ;
T_1 V_92 , V_93 , V_94 ;
T_1 V_13 , V_78 , V_79 ;
V_92 = ( F_13 ( V_33 ) & V_95 ) ?
0 : V_15 ;
V_93 = ( F_13 ( V_33 ) & V_38 ) ?
V_96 : 0 ;
V_94 = ( F_13 ( V_33 ) & V_39 ) ?
V_97 : 0 ;
V_13 = V_80 | V_92 | V_93 | V_94 ;
V_78 = F_8 ( V_33 -> V_81 , V_82 ) ;
V_79 = V_33 -> V_84 ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_78 |= V_85 | V_86 ;
}
V_6 -> V_72 [ 0 ] = V_13 ;
V_6 -> V_72 [ 1 ] = V_78 ;
V_6 -> V_72 [ 2 ] = V_79 ;
V_6 -> V_43 = V_87 ;
V_6 -> V_75 = V_88 ;
V_69 = F_27 ( V_4 , V_89 ) ;
if ( ! V_69 )
goto V_90;
F_31 ( V_69 ) ;
F_32 ( V_6 -> V_74 ) ;
return;
V_90:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_91 ) ;
}
static unsigned short F_35 ( unsigned V_98 , unsigned V_99 )
{
const unsigned int V_100 = 4096 ;
const unsigned int V_101 = V_98 / 1000 ;
const unsigned int V_102 = V_99 / 1000 ;
const unsigned int V_103 = V_102 * V_101 ;
const unsigned int V_104 = V_103 / V_100 ;
F_36 ( V_104 == 0 ) ;
return V_104 ;
}
static void F_37 ( struct V_3 * V_4 )
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
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_92 , V_93 , V_94 , V_111 ;
T_1 V_13 , V_78 , V_79 , V_112 ;
V_92 = ( F_13 ( V_33 ) & V_95 ) ?
0 : V_15 ;
V_93 = ( F_13 ( V_33 ) & V_38 ) ?
V_96 : 0 ;
V_94 = ( F_13 ( V_33 ) & V_39 ) ?
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
V_13 = F_8 ( V_4 -> V_119 , V_120 ) |
V_92 | V_93 | V_94 |
V_121 | V_111 |
V_122 |
V_80 ;
V_78 = F_8 ( V_33 -> V_81 , V_82 ) ;
V_110 = F_38 ( V_35 -> V_46 ) ;
F_39 (sgl, sg, sg_len, i)
V_109 += V_41 -> V_123 ;
if ( V_109 != V_35 -> V_45 * V_35 -> V_46 )
V_45 = 1 ;
if ( F_40 ( V_6 ) ) {
V_13 |= F_8 ( V_109 , V_124 ) ;
V_78 |= F_8 ( V_110 , V_125 ) |
F_8 ( V_45 - 1 , V_126 ) ;
} else {
F_9 ( V_109 , V_6 -> V_9 + V_127 ) ;
F_9 ( F_8 ( V_110 , V_128 ) |
F_8 ( V_45 - 1 , V_129 ) ,
V_6 -> V_9 + V_130 ) ;
}
if ( ( V_33 -> V_81 == V_131 ) ||
( V_33 -> V_81 == V_132 ) )
V_78 |= V_83 ;
V_79 = V_33 -> V_84 ;
if ( V_4 -> V_28 ) {
V_13 |= V_29 ;
V_78 |= V_85 | V_86 ;
}
V_107 = F_35 ( V_6 -> V_133 , V_35 -> V_134 ) ;
V_112 = F_4 ( V_6 -> V_9 + F_10 ( V_6 ) ) ;
V_112 &= ~ ( V_135 ) ;
V_112 |= F_8 ( V_107 , V_25 ) ;
F_9 ( V_112 , V_6 -> V_9 + F_10 ( V_6 ) ) ;
V_6 -> V_72 [ 0 ] = V_13 ;
V_6 -> V_72 [ 1 ] = V_78 ;
V_6 -> V_72 [ 2 ] = V_79 ;
V_6 -> V_43 = V_87 ;
V_6 -> V_75 = V_88 ;
V_69 = F_27 ( V_4 , 0 ) ;
if ( ! V_69 )
goto V_90;
F_36 ( V_4 -> V_35 != NULL ) ;
V_4 -> V_35 = V_35 ;
V_6 -> V_43 = V_106 ;
V_6 -> V_75 = V_75 ;
V_69 = F_27 ( V_4 , V_136 | V_89 ) ;
if ( ! V_69 )
goto V_90;
F_31 ( V_69 ) ;
F_32 ( V_6 -> V_74 ) ;
return;
V_90:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_91 ) ;
}
static void F_20 ( struct V_3 * V_4 ,
struct V_32 * V_33 )
{
V_4 -> V_33 = V_33 ;
switch ( F_41 ( V_33 ) ) {
case V_137 :
F_30 ( V_4 ) ;
break;
case V_138 :
F_34 ( V_4 ) ;
break;
case V_139 :
F_34 ( V_4 ) ;
break;
case V_140 :
F_37 ( V_4 ) ;
break;
default:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_2 , V_91 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( V_4 -> V_37 != NULL ) ;
V_4 -> V_37 = V_37 ;
F_20 ( V_4 , V_37 -> V_33 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_141 * V_142 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_142 -> V_119 == V_143 )
V_4 -> V_119 = 2 ;
else if ( V_142 -> V_119 == V_144 )
V_4 -> V_119 = 1 ;
else
V_4 -> V_119 = 0 ;
if ( V_142 -> clock )
F_44 ( & V_4 -> V_6 , V_142 -> clock ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_145 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_68 ;
F_46 ( & V_4 -> V_52 , V_68 ) ;
V_4 -> V_28 = V_145 ;
if ( V_145 ) {
F_9 ( V_29 ,
V_6 -> V_9 + V_31 + V_146 ) ;
F_9 ( V_30 ,
V_6 -> V_9 + F_11 ( V_6 ) + V_146 ) ;
} else {
F_9 ( V_29 ,
V_6 -> V_9 + V_31 + V_54 ) ;
F_9 ( V_30 ,
V_6 -> V_9 + F_11 ( V_6 ) + V_54 ) ;
}
F_47 ( & V_4 -> V_52 , V_68 ) ;
if ( V_145 && F_4 ( V_6 -> V_9 + F_5 ( V_6 ) ) &
V_147 )
F_26 ( V_4 -> V_2 ) ;
}
static int F_48 ( struct V_148 * V_149 )
{
const struct V_150 * V_151 =
F_49 ( V_152 , & V_149 -> V_153 ) ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_154 * V_155 ;
int V_8 = 0 , V_156 ;
struct V_157 * V_158 ;
struct V_5 * V_6 ;
V_155 = F_50 ( V_149 , V_159 , 0 ) ;
V_156 = F_51 ( V_149 , 0 ) ;
if ( ! V_155 || V_156 < 0 )
return - V_160 ;
V_2 = F_52 ( sizeof( struct V_3 ) , & V_149 -> V_153 ) ;
if ( ! V_2 )
return - V_161 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_153 = & V_149 -> V_153 ;
V_6 -> V_9 = F_53 ( & V_149 -> V_153 , V_155 ) ;
if ( F_54 ( V_6 -> V_9 ) ) {
V_8 = F_55 ( V_6 -> V_9 ) ;
goto V_162;
}
V_6 -> V_163 = (enum V_164 ) V_151 -> V_35 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_28 = 0 ;
V_158 = F_56 ( & V_149 -> V_153 , L_3 ) ;
if ( ! F_54 ( V_158 ) ) {
V_8 = F_57 ( V_158 ) ;
if ( V_8 ) {
F_58 ( & V_149 -> V_153 ,
L_4 , V_8 ) ;
goto V_162;
}
}
V_6 -> V_165 = F_59 ( & V_149 -> V_153 , NULL ) ;
if ( F_54 ( V_6 -> V_165 ) ) {
V_8 = F_55 ( V_6 -> V_165 ) ;
goto V_162;
}
F_60 ( V_6 -> V_165 ) ;
V_8 = F_6 ( V_4 ) ;
if ( V_8 ) {
F_58 ( & V_149 -> V_153 , L_5 , V_8 ) ;
goto V_166;
}
V_6 -> V_74 = F_61 ( & V_149 -> V_153 , L_6 ) ;
if ( ! V_6 -> V_74 ) {
F_58 ( F_19 ( V_4 -> V_2 ) ,
L_7 , V_91 ) ;
V_8 = - V_167 ;
goto V_166;
}
V_2 -> V_168 = & V_169 ;
V_2 -> V_170 = V_171 | V_172 |
V_173 | V_174 ;
V_2 -> V_175 = 400000 ;
V_2 -> V_176 = 288000000 ;
V_8 = F_62 ( V_2 ) ;
if ( V_8 )
goto V_166;
V_2 -> V_177 = V_178 | V_179 ;
V_2 -> V_180 = 52 ;
V_2 -> V_181 = 1 << 0xf ;
V_2 -> V_182 = ( F_40 ( V_6 ) ) ? 0xff : 0xffffff ;
V_2 -> V_183 = ( F_40 ( V_6 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_184 = F_63 ( V_6 -> V_74 -> V_185 -> V_153 ) ;
F_64 ( V_149 , V_2 ) ;
V_8 = F_65 ( & V_149 -> V_153 , V_156 , F_23 , 0 ,
V_186 , V_4 ) ;
if ( V_8 )
goto V_187;
F_66 ( & V_4 -> V_52 ) ;
V_8 = F_67 ( V_2 ) ;
if ( V_8 )
goto V_187;
F_68 ( F_19 ( V_4 -> V_2 ) , L_8 ) ;
return 0 ;
V_187:
if ( V_6 -> V_74 )
F_69 ( V_6 -> V_74 ) ;
V_166:
F_70 ( V_6 -> V_165 ) ;
V_162:
F_71 ( V_2 ) ;
return V_8 ;
}
static int F_72 ( struct V_148 * V_149 )
{
struct V_1 * V_2 = F_73 ( V_149 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_74 ( V_2 ) ;
if ( V_6 -> V_74 )
F_69 ( V_6 -> V_74 ) ;
F_70 ( V_6 -> V_165 ) ;
F_71 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_185 * V_153 )
{
struct V_1 * V_2 = F_76 ( V_153 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_70 ( V_6 -> V_165 ) ;
return 0 ;
}
static int F_77 ( struct V_185 * V_153 )
{
struct V_1 * V_2 = F_76 ( V_153 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_60 ( V_6 -> V_165 ) ;
return 0 ;
}
