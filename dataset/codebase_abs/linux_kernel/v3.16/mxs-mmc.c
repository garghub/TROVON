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
V_7 = ! ( F_4 ( V_6 -> V_11 + F_5 ( V_6 ) ) &
V_12 ) ;
if ( V_2 -> V_13 & V_14 )
V_7 = ! V_7 ;
return V_7 ;
}
static int F_6 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_15 , V_16 ;
int V_8 ;
V_8 = F_7 ( V_6 -> V_11 ) ;
if ( V_8 )
return V_8 ;
V_15 = V_17 ;
V_16 = F_8 ( 0x3 , V_18 ) |
F_8 ( 0x7 , V_19 ) |
V_20 |
V_21 |
V_22 |
V_23 |
V_24 |
V_25 |
V_26 ;
F_9 ( F_8 ( 0xffff , V_27 ) |
F_8 ( 2 , V_28 ) |
F_8 ( 0 , V_29 ) ,
V_6 -> V_11 + F_10 ( V_6 ) ) ;
if ( V_4 -> V_30 ) {
V_15 |= V_31 ;
V_16 |= V_32 ;
}
F_9 ( V_15 , V_6 -> V_11 + V_33 ) ;
F_9 ( V_16 , V_6 -> V_11 + F_11 ( V_6 ) ) ;
return 0 ;
}
static void F_12 ( struct V_3 * V_4 )
{
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_38 * V_39 = V_4 -> V_39 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( F_13 ( V_35 ) & V_40 ) {
if ( F_13 ( V_35 ) & V_41 ) {
V_35 -> V_42 [ 3 ] = F_4 ( V_6 -> V_11 + F_14 ( V_6 ) ) ;
V_35 -> V_42 [ 2 ] = F_4 ( V_6 -> V_11 + F_15 ( V_6 ) ) ;
V_35 -> V_42 [ 1 ] = F_4 ( V_6 -> V_11 + F_16 ( V_6 ) ) ;
V_35 -> V_42 [ 0 ] = F_4 ( V_6 -> V_11 + F_17 ( V_6 ) ) ;
} else {
V_35 -> V_42 [ 0 ] = F_4 ( V_6 -> V_11 + F_14 ( V_6 ) ) ;
}
}
if ( V_37 ) {
F_18 ( F_19 ( V_4 -> V_2 ) , V_37 -> V_43 ,
V_37 -> V_44 , V_6 -> V_45 ) ;
if ( ! V_37 -> error )
V_37 -> V_46 = V_37 -> V_47 * V_37 -> V_48 ;
else
V_37 -> V_46 = 0 ;
V_4 -> V_37 = NULL ;
if ( V_39 -> V_49 ) {
F_20 ( V_4 , V_39 -> V_49 ) ;
return;
}
}
V_4 -> V_39 = NULL ;
F_21 ( V_4 -> V_2 , V_39 ) ;
}
static void F_22 ( void * V_50 )
{
struct V_3 * V_4 = V_50 ;
F_12 ( V_4 ) ;
}
static T_2 F_23 ( int V_51 , void * V_52 )
{
struct V_3 * V_4 = V_52 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_53 ;
F_24 ( & V_4 -> V_54 ) ;
V_53 = F_4 ( V_6 -> V_11 + F_11 ( V_6 ) ) ;
F_9 ( V_53 & V_55 ,
V_6 -> V_11 + F_11 ( V_6 ) + V_56 ) ;
F_25 ( & V_4 -> V_54 ) ;
if ( ( V_53 & V_57 ) && ( V_53 & V_32 ) )
F_26 ( V_4 -> V_2 ) ;
if ( V_53 & V_58 )
V_35 -> error = - V_59 ;
else if ( V_53 & V_60 )
V_35 -> error = - V_61 ;
if ( V_37 ) {
if ( V_53 & ( V_62 |
V_63 ) )
V_37 -> error = - V_59 ;
else if ( V_53 & V_64 )
V_37 -> error = - V_65 ;
else if ( V_53 & ( V_66 |
V_67 ) )
V_37 -> error = - V_61 ;
}
return V_68 ;
}
static struct V_69 * F_27 (
struct V_3 * V_4 , unsigned long V_70 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_69 * V_71 ;
struct V_36 * V_37 = V_4 -> V_37 ;
struct V_72 * V_73 ;
unsigned int V_44 ;
if ( V_37 ) {
F_28 ( F_19 ( V_4 -> V_2 ) , V_37 -> V_43 ,
V_37 -> V_44 , V_6 -> V_45 ) ;
V_73 = V_37 -> V_43 ;
V_44 = V_37 -> V_44 ;
} else {
V_73 = (struct V_72 * ) V_6 -> V_74 ;
V_44 = V_75 ;
}
V_71 = F_29 ( V_6 -> V_76 ,
V_73 , V_44 , V_6 -> V_77 , V_70 ) ;
if ( V_71 ) {
V_71 -> V_78 = F_22 ;
V_71 -> V_79 = V_4 ;
} else {
if ( V_37 )
F_18 ( F_19 ( V_4 -> V_2 ) , V_37 -> V_43 ,
V_37 -> V_44 , V_6 -> V_45 ) ;
}
return V_71 ;
}
static void F_30 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_69 * V_71 ;
T_1 V_15 , V_80 , V_81 ;
V_15 = V_82 | V_17 ;
V_80 = F_8 ( V_35 -> V_83 , V_84 ) | V_85 ;
V_81 = V_35 -> V_86 ;
if ( V_4 -> V_30 ) {
V_15 |= V_31 ;
V_80 |= V_87 | V_88 ;
}
V_6 -> V_74 [ 0 ] = V_15 ;
V_6 -> V_74 [ 1 ] = V_80 ;
V_6 -> V_74 [ 2 ] = V_81 ;
V_6 -> V_45 = V_89 ;
V_6 -> V_77 = V_90 ;
V_71 = F_27 ( V_4 , V_91 ) ;
if ( ! V_71 )
goto V_92;
F_31 ( V_71 ) ;
F_32 ( V_6 -> V_76 ) ;
return;
V_92:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_93 ) ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 ;
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_69 * V_71 ;
T_1 V_94 , V_95 , V_96 ;
T_1 V_15 , V_80 , V_81 ;
V_94 = ( F_13 ( V_35 ) & V_97 ) ?
0 : V_17 ;
V_95 = ( F_13 ( V_35 ) & V_40 ) ?
V_98 : 0 ;
V_96 = ( F_13 ( V_35 ) & V_41 ) ?
V_99 : 0 ;
V_15 = V_82 | V_94 | V_95 | V_96 ;
V_80 = F_8 ( V_35 -> V_83 , V_84 ) ;
V_81 = V_35 -> V_86 ;
if ( V_4 -> V_30 ) {
V_15 |= V_31 ;
V_80 |= V_87 | V_88 ;
}
V_6 -> V_74 [ 0 ] = V_15 ;
V_6 -> V_74 [ 1 ] = V_80 ;
V_6 -> V_74 [ 2 ] = V_81 ;
V_6 -> V_45 = V_89 ;
V_6 -> V_77 = V_90 ;
V_71 = F_27 ( V_4 , V_91 ) ;
if ( ! V_71 )
goto V_92;
F_31 ( V_71 ) ;
F_32 ( V_6 -> V_76 ) ;
return;
V_92:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_93 ) ;
}
static unsigned short F_35 ( unsigned V_100 , unsigned V_101 )
{
const unsigned int V_102 = 4096 ;
const unsigned int V_103 = V_100 / 1000 ;
const unsigned int V_104 = V_101 / 1000 ;
const unsigned int V_105 = V_104 * V_103 ;
const unsigned int V_106 = V_105 / V_102 ;
F_36 ( V_106 == 0 ) ;
return V_106 ;
}
static void F_37 ( struct V_3 * V_4 )
{
struct V_34 * V_35 = V_4 -> V_35 ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_69 * V_71 ;
struct V_72 * V_73 = V_37 -> V_43 , * V_43 ;
unsigned int V_44 = V_37 -> V_44 ;
unsigned int V_107 ;
unsigned short V_108 , V_109 ;
enum V_110 V_77 ;
unsigned int V_111 = 0 , V_112 ;
unsigned int V_47 = V_37 -> V_47 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_94 , V_95 , V_96 , V_113 ;
T_1 V_15 , V_80 , V_81 , V_114 ;
V_94 = ( F_13 ( V_35 ) & V_97 ) ?
0 : V_17 ;
V_95 = ( F_13 ( V_35 ) & V_40 ) ?
V_98 : 0 ;
V_96 = ( F_13 ( V_35 ) & V_41 ) ?
V_99 : 0 ;
if ( V_37 -> V_70 & V_115 ) {
V_108 = V_116 ;
V_77 = V_117 ;
V_113 = 0 ;
} else {
V_108 = V_118 ;
V_77 = V_119 ;
V_113 = V_120 ;
}
V_15 = F_8 ( V_4 -> V_121 , V_122 ) |
V_94 | V_95 | V_96 |
V_123 | V_113 |
V_124 |
V_82 ;
V_80 = F_8 ( V_35 -> V_83 , V_84 ) ;
V_112 = F_38 ( V_37 -> V_48 ) ;
F_39 (sgl, sg, sg_len, i)
V_111 += V_43 -> V_125 ;
if ( V_111 != V_37 -> V_47 * V_37 -> V_48 )
V_47 = 1 ;
if ( F_40 ( V_6 ) ) {
V_15 |= F_8 ( V_111 , V_126 ) ;
V_80 |= F_8 ( V_112 , V_127 ) |
F_8 ( V_47 - 1 , V_128 ) ;
} else {
F_9 ( V_111 , V_6 -> V_11 + V_129 ) ;
F_9 ( F_8 ( V_112 , V_130 ) |
F_8 ( V_47 - 1 , V_131 ) ,
V_6 -> V_11 + V_132 ) ;
}
if ( ( V_35 -> V_83 == V_133 ) ||
( V_35 -> V_83 == V_134 ) )
V_80 |= V_85 ;
V_81 = V_35 -> V_86 ;
if ( V_4 -> V_30 ) {
V_15 |= V_31 ;
V_80 |= V_87 | V_88 ;
}
V_109 = F_35 ( V_6 -> V_135 , V_37 -> V_136 ) ;
V_114 = F_4 ( V_6 -> V_11 + F_10 ( V_6 ) ) ;
V_114 &= ~ ( V_137 ) ;
V_114 |= F_8 ( V_109 , V_27 ) ;
F_9 ( V_114 , V_6 -> V_11 + F_10 ( V_6 ) ) ;
V_6 -> V_74 [ 0 ] = V_15 ;
V_6 -> V_74 [ 1 ] = V_80 ;
V_6 -> V_74 [ 2 ] = V_81 ;
V_6 -> V_45 = V_89 ;
V_6 -> V_77 = V_90 ;
V_71 = F_27 ( V_4 , 0 ) ;
if ( ! V_71 )
goto V_92;
F_36 ( V_4 -> V_37 != NULL ) ;
V_4 -> V_37 = V_37 ;
V_6 -> V_45 = V_108 ;
V_6 -> V_77 = V_77 ;
V_71 = F_27 ( V_4 , V_138 | V_91 ) ;
if ( ! V_71 )
goto V_92;
F_31 ( V_71 ) ;
F_32 ( V_6 -> V_76 ) ;
return;
V_92:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_1 , V_93 ) ;
}
static void F_20 ( struct V_3 * V_4 ,
struct V_34 * V_35 )
{
V_4 -> V_35 = V_35 ;
switch ( F_41 ( V_35 ) ) {
case V_139 :
F_30 ( V_4 ) ;
break;
case V_140 :
F_34 ( V_4 ) ;
break;
case V_141 :
F_34 ( V_4 ) ;
break;
case V_142 :
F_37 ( V_4 ) ;
break;
default:
F_33 ( F_19 ( V_4 -> V_2 ) ,
L_2 , V_93 ) ;
break;
}
}
static void F_42 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_36 ( V_4 -> V_39 != NULL ) ;
V_4 -> V_39 = V_39 ;
F_20 ( V_4 , V_39 -> V_35 ) ;
}
static void F_43 ( struct V_1 * V_2 , struct V_143 * V_144 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_144 -> V_121 == V_145 )
V_4 -> V_121 = 2 ;
else if ( V_144 -> V_121 == V_146 )
V_4 -> V_121 = 1 ;
else
V_4 -> V_121 = 0 ;
if ( V_144 -> clock )
F_44 ( & V_4 -> V_6 , V_144 -> clock ) ;
}
static void F_45 ( struct V_1 * V_2 , int V_147 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_70 ;
F_46 ( & V_4 -> V_54 , V_70 ) ;
V_4 -> V_30 = V_147 ;
if ( V_147 ) {
F_9 ( V_31 ,
V_6 -> V_11 + V_33 + V_148 ) ;
F_9 ( V_32 ,
V_6 -> V_11 + F_11 ( V_6 ) + V_148 ) ;
} else {
F_9 ( V_31 ,
V_6 -> V_11 + V_33 + V_56 ) ;
F_9 ( V_32 ,
V_6 -> V_11 + F_11 ( V_6 ) + V_56 ) ;
}
F_47 ( & V_4 -> V_54 , V_70 ) ;
if ( V_147 && F_4 ( V_6 -> V_11 + F_5 ( V_6 ) ) &
V_149 )
F_26 ( V_4 -> V_2 ) ;
}
static int F_48 ( struct V_150 * V_151 )
{
const struct V_152 * V_153 =
F_49 ( V_154 , & V_151 -> V_155 ) ;
struct V_156 * V_157 = V_151 -> V_155 . V_158 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_159 * V_160 ;
int V_8 = 0 , V_161 ;
struct V_162 * V_163 ;
struct V_5 * V_6 ;
V_160 = F_50 ( V_151 , V_164 , 0 ) ;
V_161 = F_51 ( V_151 , 0 ) ;
if ( ! V_160 || V_161 < 0 )
return - V_165 ;
V_2 = F_52 ( sizeof( struct V_3 ) , & V_151 -> V_155 ) ;
if ( ! V_2 )
return - V_166 ;
V_4 = F_2 ( V_2 ) ;
V_6 = & V_4 -> V_6 ;
V_6 -> V_155 = & V_151 -> V_155 ;
V_6 -> V_11 = F_53 ( & V_151 -> V_155 , V_160 ) ;
if ( F_54 ( V_6 -> V_11 ) ) {
V_8 = F_55 ( V_6 -> V_11 ) ;
goto V_167;
}
V_6 -> V_168 = (enum V_169 ) V_153 -> V_37 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_30 = 0 ;
V_163 = F_56 ( & V_151 -> V_155 , L_3 ) ;
if ( ! F_54 ( V_163 ) ) {
V_8 = F_57 ( V_163 ) ;
if ( V_8 ) {
F_58 ( & V_151 -> V_155 ,
L_4 , V_8 ) ;
goto V_167;
}
}
V_6 -> V_170 = F_59 ( & V_151 -> V_155 , NULL ) ;
if ( F_54 ( V_6 -> V_170 ) ) {
V_8 = F_55 ( V_6 -> V_170 ) ;
goto V_167;
}
F_60 ( V_6 -> V_170 ) ;
V_8 = F_6 ( V_4 ) ;
if ( V_8 ) {
F_58 ( & V_151 -> V_155 , L_5 , V_8 ) ;
goto V_171;
}
V_6 -> V_76 = F_61 ( & V_151 -> V_155 , L_6 ) ;
if ( ! V_6 -> V_76 ) {
F_58 ( F_19 ( V_4 -> V_2 ) ,
L_7 , V_93 ) ;
V_8 = - V_172 ;
goto V_171;
}
V_2 -> V_173 = & V_174 ;
V_2 -> V_175 = V_176 | V_177 |
V_178 | V_179 ;
V_4 -> V_9 = F_62 ( V_157 , L_8 ) ;
V_2 -> V_180 = 400000 ;
V_2 -> V_181 = 288000000 ;
V_8 = F_63 ( V_2 ) ;
if ( V_8 )
goto V_171;
V_2 -> V_182 = V_183 | V_184 ;
V_2 -> V_185 = 52 ;
V_2 -> V_186 = 1 << 0xf ;
V_2 -> V_187 = ( F_40 ( V_6 ) ) ? 0xff : 0xffffff ;
V_2 -> V_188 = ( F_40 ( V_6 ) ) ? 0xffff : 0xffffffff ;
V_2 -> V_189 = F_64 ( V_6 -> V_76 -> V_190 -> V_155 ) ;
F_65 ( V_151 , V_2 ) ;
V_8 = F_66 ( & V_151 -> V_155 , V_161 , F_23 , 0 ,
V_191 , V_4 ) ;
if ( V_8 )
goto V_192;
F_67 ( & V_4 -> V_54 ) ;
V_8 = F_68 ( V_2 ) ;
if ( V_8 )
goto V_192;
F_69 ( F_19 ( V_4 -> V_2 ) , L_9 ) ;
return 0 ;
V_192:
if ( V_6 -> V_76 )
F_70 ( V_6 -> V_76 ) ;
V_171:
F_71 ( V_6 -> V_170 ) ;
V_167:
F_72 ( V_2 ) ;
return V_8 ;
}
static int F_73 ( struct V_150 * V_151 )
{
struct V_1 * V_2 = F_74 ( V_151 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_75 ( V_2 ) ;
if ( V_6 -> V_76 )
F_70 ( V_6 -> V_76 ) ;
F_71 ( V_6 -> V_170 ) ;
F_72 ( V_2 ) ;
return 0 ;
}
static int F_76 ( struct V_190 * V_155 )
{
struct V_1 * V_2 = F_77 ( V_155 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_71 ( V_6 -> V_170 ) ;
return 0 ;
}
static int F_78 ( struct V_190 * V_155 )
{
struct V_1 * V_2 = F_77 ( V_155 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
F_60 ( V_6 -> V_170 ) ;
return 0 ;
}
