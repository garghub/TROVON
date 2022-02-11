static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
int V_7 , V_8 ;
if ( V_4 -> V_9 )
return - V_10 ;
V_8 = F_3 ( V_2 ) ;
if ( V_8 >= 0 )
return V_8 ;
V_7 = V_2 -> V_11 & V_12 ||
! ( F_4 ( V_6 -> V_13 + F_5 ( V_6 ) ) &
V_14 ) ;
if ( V_2 -> V_15 & V_16 )
V_7 = ! V_7 ;
return V_7 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_17 , V_18 ;
int V_8 ;
V_8 = F_7 ( V_6 -> V_13 ) ;
if ( V_8 )
return V_8 ;
V_17 = V_19 ;
V_18 = F_8 ( 0x3 , V_20 ) |
F_8 ( 0x7 , V_21 ) |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 ;
F_9 ( F_8 ( 0xffff , V_29 ) |
F_8 ( 2 , V_30 ) |
F_8 ( 0 , V_31 ) ,
V_6 -> V_13 + F_10 ( V_6 ) ) ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_18 |= V_34 ;
}
F_9 ( V_17 , V_6 -> V_13 + V_35 ) ;
F_9 ( V_18 , V_6 -> V_13 + F_11 ( V_6 ) ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_40 * V_41 = V_4 -> V_41 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( F_13 ( V_37 ) & V_42 ) {
if ( F_13 ( V_37 ) & V_43 ) {
V_37 -> V_44 [ 3 ] = F_4 ( V_6 -> V_13 + F_14 ( V_6 ) ) ;
V_37 -> V_44 [ 2 ] = F_4 ( V_6 -> V_13 + F_15 ( V_6 ) ) ;
V_37 -> V_44 [ 1 ] = F_4 ( V_6 -> V_13 + F_16 ( V_6 ) ) ;
V_37 -> V_44 [ 0 ] = F_4 ( V_6 -> V_13 + F_17 ( V_6 ) ) ;
} else {
V_37 -> V_44 [ 0 ] = F_4 ( V_6 -> V_13 + F_14 ( V_6 ) ) ;
}
}
if ( V_37 == V_41 -> V_45 ) {
F_18 ( V_4 , V_41 -> V_37 ) ;
return;
} else if ( V_39 ) {
F_19 ( F_20 ( V_4 -> V_2 ) , V_39 -> V_46 ,
V_39 -> V_47 , V_6 -> V_48 ) ;
if ( ! V_39 -> error )
V_39 -> V_49 = V_39 -> V_50 * V_39 -> V_51 ;
else
V_39 -> V_49 = 0 ;
V_4 -> V_39 = NULL ;
if ( V_39 -> V_52 && ( V_39 -> error || ! V_41 -> V_45 ) ) {
F_18 ( V_4 , V_41 -> V_52 ) ;
return;
}
}
V_4 -> V_41 = NULL ;
F_21 ( V_4 -> V_2 , V_41 ) ;
}
static void F_22 ( void * V_53 )
{
struct V_3 * V_4 = V_53 ;
F_12 ( V_4 ) ;
}
static T_2 F_23 ( int V_54 , void * V_55 )
{
struct V_3 * V_4 = V_55 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_56 ;
F_24 ( & V_4 -> V_57 ) ;
V_56 = F_4 ( V_6 -> V_13 + F_11 ( V_6 ) ) ;
F_9 ( V_56 & V_58 ,
V_6 -> V_13 + F_11 ( V_6 ) + V_59 ) ;
F_25 ( & V_4 -> V_57 ) ;
if ( ( V_56 & V_60 ) && ( V_56 & V_34 ) )
F_26 ( V_4 -> V_2 ) ;
if ( V_56 & V_61 )
V_37 -> error = - V_62 ;
else if ( V_56 & V_63 )
V_37 -> error = - V_64 ;
if ( V_39 ) {
if ( V_56 & ( V_65 |
V_66 ) )
V_39 -> error = - V_62 ;
else if ( V_56 & V_67 )
V_39 -> error = - V_68 ;
else if ( V_56 & ( V_69 |
V_70 ) )
V_39 -> error = - V_64 ;
}
return V_71 ;
}
static struct V_72 * F_27 (
struct V_3 * V_4 , unsigned long V_73 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_72 * V_74 ;
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_75 * V_76 ;
unsigned int V_47 ;
if ( V_39 ) {
F_28 ( F_20 ( V_4 -> V_2 ) , V_39 -> V_46 ,
V_39 -> V_47 , V_6 -> V_48 ) ;
V_76 = V_39 -> V_46 ;
V_47 = V_39 -> V_47 ;
} else {
V_76 = (struct V_75 * ) V_6 -> V_77 ;
V_47 = V_78 ;
}
V_74 = F_29 ( V_6 -> V_79 ,
V_76 , V_47 , V_6 -> V_80 , V_73 ) ;
if ( V_74 ) {
V_74 -> V_81 = F_22 ;
V_74 -> V_82 = V_4 ;
} else {
if ( V_39 )
F_19 ( F_20 ( V_4 -> V_2 ) , V_39 -> V_46 ,
V_39 -> V_47 , V_6 -> V_48 ) ;
}
return V_74 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_72 * V_74 ;
T_1 V_17 , V_83 , V_84 ;
V_17 = V_85 | V_19 ;
V_83 = F_8 ( V_37 -> V_86 , V_87 ) | V_88 ;
V_84 = V_37 -> V_89 ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_83 |= V_90 | V_91 ;
}
V_6 -> V_77 [ 0 ] = V_17 ;
V_6 -> V_77 [ 1 ] = V_83 ;
V_6 -> V_77 [ 2 ] = V_84 ;
V_6 -> V_48 = V_92 ;
V_6 -> V_80 = V_93 ;
V_74 = F_27 ( V_4 , V_94 ) ;
if ( ! V_74 )
goto V_95;
F_31 ( V_74 ) ;
F_32 ( V_6 -> V_79 ) ;
return;
V_95:
F_33 ( F_20 ( V_4 -> V_2 ) ,
L_1 , V_96 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_72 * V_74 ;
T_1 V_97 , V_98 , V_99 ;
T_1 V_17 , V_83 , V_84 ;
V_97 = ( F_13 ( V_37 ) & V_100 ) ?
0 : V_19 ;
V_98 = ( F_13 ( V_37 ) & V_42 ) ?
V_101 : 0 ;
V_99 = ( F_13 ( V_37 ) & V_43 ) ?
V_102 : 0 ;
V_17 = V_85 | V_97 | V_98 | V_99 ;
V_83 = F_8 ( V_37 -> V_86 , V_87 ) ;
V_84 = V_37 -> V_89 ;
if ( V_37 -> V_86 == V_103 )
V_83 |= V_88 ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_83 |= V_90 | V_91 ;
}
V_6 -> V_77 [ 0 ] = V_17 ;
V_6 -> V_77 [ 1 ] = V_83 ;
V_6 -> V_77 [ 2 ] = V_84 ;
V_6 -> V_48 = V_92 ;
V_6 -> V_80 = V_93 ;
V_74 = F_27 ( V_4 , V_94 ) ;
if ( ! V_74 )
goto V_95;
F_31 ( V_74 ) ;
F_32 ( V_6 -> V_79 ) ;
return;
V_95:
F_33 ( F_20 ( V_4 -> V_2 ) ,
L_1 , V_96 ) ;
}
static unsigned short F_35 ( unsigned V_104 , unsigned V_105 )
{
const unsigned int V_106 = 4096 ;
const unsigned int V_107 = V_104 / 1000 ;
const unsigned int V_108 = V_105 / 1000 ;
const unsigned int V_109 = V_108 * V_107 ;
const unsigned int V_110 = V_109 / V_106 ;
F_36 ( V_110 == 0 ) ;
return V_110 ;
}
static void F_37 ( struct V_3 * V_4 )
{
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_38 * V_39 = V_37 -> V_39 ;
struct V_72 * V_74 ;
struct V_75 * V_76 = V_39 -> V_46 , * V_46 ;
unsigned int V_47 = V_39 -> V_47 ;
unsigned int V_111 ;
unsigned short V_112 , V_113 ;
enum V_114 V_80 ;
unsigned int V_115 = 0 , V_116 ;
unsigned int V_50 = V_39 -> V_50 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_97 , V_98 , V_99 , V_117 ;
T_1 V_17 , V_83 , V_84 , V_118 ;
V_97 = ( F_13 ( V_37 ) & V_100 ) ?
0 : V_19 ;
V_98 = ( F_13 ( V_37 ) & V_42 ) ?
V_101 : 0 ;
V_99 = ( F_13 ( V_37 ) & V_43 ) ?
V_102 : 0 ;
if ( V_39 -> V_73 & V_119 ) {
V_112 = V_120 ;
V_80 = V_121 ;
V_117 = 0 ;
} else {
V_112 = V_122 ;
V_80 = V_123 ;
V_117 = V_124 ;
}
V_17 = F_8 ( V_4 -> V_125 , V_126 ) |
V_97 | V_98 | V_99 |
V_127 | V_117 |
V_128 |
V_85 ;
V_83 = F_8 ( V_37 -> V_86 , V_87 ) ;
V_116 = F_38 ( V_39 -> V_51 ) ;
F_39 (sgl, sg, sg_len, i)
V_115 += V_46 -> V_129 ;
if ( V_115 != V_39 -> V_50 * V_39 -> V_51 )
V_50 = 1 ;
if ( F_40 ( V_6 ) ) {
V_17 |= F_8 ( V_115 , V_130 ) ;
V_83 |= F_8 ( V_116 , V_131 ) |
F_8 ( V_50 - 1 , V_132 ) ;
} else {
F_9 ( V_115 , V_6 -> V_13 + V_133 ) ;
F_9 ( F_8 ( V_116 , V_134 ) |
F_8 ( V_50 - 1 , V_135 ) ,
V_6 -> V_13 + V_136 ) ;
}
if ( V_37 -> V_86 == V_137 )
V_83 |= V_88 ;
V_84 = V_37 -> V_89 ;
if ( V_4 -> V_32 ) {
V_17 |= V_33 ;
V_83 |= V_90 | V_91 ;
}
V_113 = F_35 ( V_6 -> V_138 , V_39 -> V_139 ) ;
V_118 = F_4 ( V_6 -> V_13 + F_10 ( V_6 ) ) ;
V_118 &= ~ ( V_140 ) ;
V_118 |= F_8 ( V_113 , V_29 ) ;
F_9 ( V_118 , V_6 -> V_13 + F_10 ( V_6 ) ) ;
V_6 -> V_77 [ 0 ] = V_17 ;
V_6 -> V_77 [ 1 ] = V_83 ;
V_6 -> V_77 [ 2 ] = V_84 ;
V_6 -> V_48 = V_92 ;
V_6 -> V_80 = V_93 ;
V_74 = F_27 ( V_4 , 0 ) ;
if ( ! V_74 )
goto V_95;
F_36 ( V_4 -> V_39 != NULL ) ;
V_4 -> V_39 = V_39 ;
V_6 -> V_48 = V_112 ;
V_6 -> V_80 = V_80 ;
V_74 = F_27 ( V_4 , V_141 | V_94 ) ;
if ( ! V_74 )
goto V_95;
F_31 ( V_74 ) ;
F_32 ( V_6 -> V_79 ) ;
return;
V_95:
F_33 ( F_20 ( V_4 -> V_2 ) ,
L_1 , V_96 ) ;
}
static void F_18 ( struct V_3 * V_4 ,
struct V_36 * V_37 )
{
V_4 -> V_37 = V_37 ;
switch ( F_41 ( V_37 ) ) {
case V_142 :
F_30 ( V_4 ) ;
break;
case V_143 :
F_34 ( V_4 ) ;
break;
case V_144 :
F_34 ( V_4 ) ;
break;
case V_145 :
F_37 ( V_4 ) ;
break;
default:
F_33 ( F_20 ( V_4 -> V_2 ) ,
L_2 , V_96 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , struct V_40 * V_41 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( V_4 -> V_41 != NULL ) ;
V_4 -> V_41 = V_41 ;
if ( V_41 -> V_45 )
F_18 ( V_4 , V_41 -> V_45 ) ;
else
F_18 ( V_4 , V_41 -> V_37 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_146 * V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_147 -> V_125 == V_148 )
V_4 -> V_125 = 2 ;
else if ( V_147 -> V_125 == V_149 )
V_4 -> V_125 = 1 ;
else
V_4 -> V_125 = 0 ;
if ( V_147 -> clock )
F_44 ( & V_4 -> V_6 , V_147 -> clock ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_150 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_73 ;
F_46 ( & V_4 -> V_57 , V_73 ) ;
V_4 -> V_32 = V_150 ;
if ( V_150 ) {
F_9 ( V_33 ,
V_6 -> V_13 + V_35 + V_151 ) ;
F_9 ( V_34 ,
V_6 -> V_13 + F_11 ( V_6 ) + V_151 ) ;
} else {
F_9 ( V_33 ,
V_6 -> V_13 + V_35 + V_59 ) ;
F_9 ( V_34 ,
V_6 -> V_13 + F_11 ( V_6 ) + V_59 ) ;
}
F_47 ( & V_4 -> V_57 , V_73 ) ;
if ( V_150 && F_4 ( V_6 -> V_13 + F_5 ( V_6 ) ) &
V_152 )
F_26 ( V_4 -> V_2 ) ;
}
static int F_48 ( struct V_153 * V_154 )
{
const struct V_155 * V_156 =
F_49 ( V_157 , & V_154 -> V_158 ) ;
struct V_159 * V_160 = V_154 -> V_158 . V_161 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_162 * V_163 ;
int V_8 = 0 , V_164 ;
struct V_165 * V_166 ;
struct V_5 * V_6 ;
V_164 = F_50 ( V_154 , 0 ) ;
if ( V_164 < 0 )
return V_164 ;
V_2 = F_51 ( sizeof( struct V_3 ) , & V_154 -> V_158 ) ;
if ( ! V_2 )
return - V_167 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_158 = & V_154 -> V_158 ;
V_163 = F_52 ( V_154 , V_168 , 0 ) ;
V_6 -> V_13 = F_53 ( & V_154 -> V_158 , V_163 ) ;
if ( F_54 ( V_6 -> V_13 ) ) {
V_8 = F_55 ( V_6 -> V_13 ) ;
goto V_169;
}
V_6 -> V_170 = (enum V_171 ) V_156 -> V_39 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_32 = 0 ;
V_166 = F_56 ( & V_154 -> V_158 , L_3 ) ;
if ( ! F_54 ( V_166 ) ) {
V_8 = F_57 ( V_166 ) ;
if ( V_8 ) {
F_58 ( & V_154 -> V_158 ,
L_4 , V_8 ) ;
goto V_169;
}
}
V_6 -> V_172 = F_59 ( & V_154 -> V_158 , NULL ) ;
if ( F_54 ( V_6 -> V_172 ) ) {
V_8 = F_55 ( V_6 -> V_172 ) ;
goto V_169;
}
V_8 = F_60 ( V_6 -> V_172 ) ;
if ( V_8 )
goto V_169;
V_8 = F_6 ( V_4 ) ;
if ( V_8 ) {
F_58 ( & V_154 -> V_158 , L_5 , V_8 ) ;
goto V_173;
}
V_6 -> V_79 = F_61 ( & V_154 -> V_158 , L_6 ) ;
if ( ! V_6 -> V_79 ) {
F_58 ( F_20 ( V_4 -> V_2 ) ,
L_7 , V_96 ) ;
V_8 = - V_174 ;
goto V_173;
}
V_2 -> V_175 = & V_176 ;
V_2 -> V_11 = V_177 | V_178 |
V_179 | V_12 | V_180 ;
V_4 -> V_9 = F_62 ( V_160 , L_8 ) ;
V_2 -> V_181 = 400000 ;
V_2 -> V_182 = 288000000 ;
V_8 = F_63 ( V_2 ) ;
if ( V_8 )
goto V_173;
V_2 -> V_183 = V_184 | V_185 ;
V_2 -> V_186 = 52 ;
V_2 -> V_187 = 1 << 0xf ;
V_2 -> V_188 = ( F_40 ( V_6 ) ) ? 0xff : 0xffffff ;
V_2 -> V_189 = ( F_40 ( V_6 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_190 = F_64 ( V_6 -> V_79 -> V_191 -> V_158 ) ;
F_65 ( V_154 , V_2 ) ;
F_66 ( & V_4 -> V_57 ) ;
V_8 = F_67 ( & V_154 -> V_158 , V_164 , F_23 , 0 ,
F_68 ( & V_154 -> V_158 ) , V_4 ) ;
if ( V_8 )
goto V_192;
V_8 = F_69 ( V_2 ) ;
if ( V_8 )
goto V_192;
F_70 ( F_20 ( V_4 -> V_2 ) , L_9 ) ;
return 0 ;
V_192:
F_71 ( V_6 -> V_79 ) ;
V_173:
F_72 ( V_6 -> V_172 ) ;
V_169:
F_73 ( V_2 ) ;
return V_8 ;
}
static int F_74 ( struct V_153 * V_154 )
{
struct V_1 * V_2 = F_75 ( V_154 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_76 ( V_2 ) ;
if ( V_6 -> V_79 )
F_71 ( V_6 -> V_79 ) ;
F_72 ( V_6 -> V_172 ) ;
F_73 ( V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_191 * V_158 )
{
struct V_1 * V_2 = F_78 ( V_158 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_72 ( V_6 -> V_172 ) ;
return 0 ;
}
static int F_79 ( struct V_191 * V_158 )
{
struct V_1 * V_2 = F_78 ( V_158 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
return F_60 ( V_6 -> V_172 ) ;
}
