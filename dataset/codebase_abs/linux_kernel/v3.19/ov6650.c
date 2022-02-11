static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
int V_5 ;
T_1 V_6 = V_3 ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = 1 ,
. V_12 = & V_6 ,
} ;
V_5 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_5 < 0 )
goto V_14;
V_8 . V_10 = V_15 ;
V_5 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_5 < 0 )
goto V_14;
* V_4 = V_6 ;
return 0 ;
V_14:
F_3 ( & V_2 -> V_16 , L_1 , V_3 ) ;
return V_5 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_5 ;
unsigned char V_6 [ 2 ] = { V_3 , V_4 } ;
struct V_7 V_8 = {
. V_9 = V_2 -> V_9 ,
. V_10 = 0 ,
. V_11 = 2 ,
. V_12 = V_6 ,
} ;
V_5 = F_2 ( V_2 -> V_13 , & V_8 , 1 ) ;
F_5 ( 100 ) ;
if ( V_5 < 0 ) {
F_3 ( & V_2 -> V_16 , L_2 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_17 , T_1 V_18 )
{
T_1 V_4 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 ) {
F_3 ( & V_2 -> V_16 ,
L_3 ,
V_3 ) ;
return V_5 ;
}
V_4 &= ~ V_18 ;
V_4 |= V_17 ;
V_5 = F_4 ( V_2 , V_3 , V_4 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_4 ,
V_3 ) ;
return V_5 ;
}
static struct V_19 * F_7 ( const struct V_1 * V_2 )
{
return F_8 ( F_9 ( V_2 ) , struct V_19 , V_20 ) ;
}
static int F_10 ( struct V_21 * V_22 , int V_23 )
{
return 0 ;
}
static int F_11 ( struct V_24 * V_25 )
{
struct V_19 * V_26 = F_8 ( V_25 -> V_27 , struct V_19 , V_28 ) ;
struct V_21 * V_22 = & V_26 -> V_20 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
T_2 V_3 , V_29 ;
int V_5 ;
switch ( V_25 -> V_30 ) {
case V_31 :
V_5 = F_1 ( V_2 , V_32 , & V_3 ) ;
if ( ! V_5 )
V_26 -> V_33 -> V_4 = V_3 ;
return V_5 ;
case V_34 :
V_5 = F_1 ( V_2 , V_35 , & V_3 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_36 , & V_29 ) ;
if ( ! V_5 ) {
V_26 -> V_37 -> V_4 = V_3 ;
V_26 -> V_38 -> V_4 = V_29 ;
}
return V_5 ;
case V_39 :
V_5 = F_1 ( V_2 , V_40 , & V_3 ) ;
if ( ! V_5 )
V_26 -> V_41 -> V_4 = V_3 ;
return V_5 ;
}
return - V_42 ;
}
static int F_13 ( struct V_24 * V_25 )
{
struct V_19 * V_26 = F_8 ( V_25 -> V_27 , struct V_19 , V_28 ) ;
struct V_21 * V_22 = & V_26 -> V_20 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_5 ;
switch ( V_25 -> V_30 ) {
case V_31 :
V_5 = F_6 ( V_2 , V_43 ,
V_25 -> V_4 ? V_44 : 0 , V_44 ) ;
if ( ! V_5 && ! V_25 -> V_4 )
V_5 = F_4 ( V_2 , V_32 , V_26 -> V_33 -> V_4 ) ;
return V_5 ;
case V_34 :
V_5 = F_6 ( V_2 , V_43 ,
V_25 -> V_4 ? V_45 : 0 , V_45 ) ;
if ( ! V_5 && ! V_25 -> V_4 ) {
V_5 = F_4 ( V_2 , V_35 , V_26 -> V_37 -> V_4 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_36 ,
V_26 -> V_38 -> V_4 ) ;
}
return V_5 ;
case V_46 :
return F_6 ( V_2 , V_47 , F_14 ( V_25 -> V_4 ) ,
V_48 ) ;
case V_49 :
return F_6 ( V_2 , V_50 , F_15 ( V_25 -> V_4 ) ,
V_51 ) ;
case V_52 :
return F_4 ( V_2 , V_53 , V_25 -> V_4 ) ;
case V_39 :
V_5 = F_6 ( V_2 , V_43 , V_25 -> V_4 ==
V_54 ? V_55 : 0 , V_55 ) ;
if ( ! V_5 && V_25 -> V_4 == V_56 )
V_5 = F_4 ( V_2 , V_40 ,
V_26 -> V_41 -> V_4 ) ;
return V_5 ;
case V_57 :
return F_4 ( V_2 , V_58 , V_25 -> V_4 ) ;
case V_59 :
return F_6 ( V_2 , V_43 ,
V_25 -> V_4 ? V_60 : 0 , V_60 ) ;
case V_61 :
return F_6 ( V_2 , V_43 ,
V_25 -> V_4 ? V_62 : 0 , V_62 ) ;
}
return - V_42 ;
}
static int F_16 ( struct V_21 * V_22 ,
struct V_63 * V_3 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_5 ;
T_1 V_4 ;
if ( V_3 -> V_3 & ~ 0xff )
return - V_42 ;
V_3 -> V_64 = 1 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( ! V_5 )
V_3 -> V_4 = ( V_65 ) V_4 ;
return V_5 ;
}
static int F_17 ( struct V_21 * V_22 ,
const struct V_63 * V_3 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
if ( V_3 -> V_3 & ~ 0xff || V_3 -> V_4 & ~ 0xff )
return - V_42 ;
return F_4 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static int F_18 ( struct V_21 * V_22 , int V_66 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
return F_20 ( & V_2 -> V_16 , V_68 , V_26 -> V_69 , V_66 ) ;
}
static int F_21 ( struct V_21 * V_22 , struct V_70 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
V_71 -> type = V_72 ;
V_71 -> V_73 = V_26 -> V_74 ;
return 0 ;
}
static int F_22 ( struct V_21 * V_22 , const struct V_70 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_75 V_74 = V_71 -> V_73 ;
int V_5 ;
if ( V_71 -> type != V_72 )
return - V_42 ;
V_74 . V_76 = F_23 ( V_74 . V_76 , 2 ) ;
V_74 . V_77 = F_23 ( V_74 . V_77 , 2 ) ;
V_74 . V_78 = F_23 ( V_74 . V_78 , 2 ) ;
V_74 . V_79 = F_23 ( V_74 . V_79 , 2 ) ;
F_24 ( & V_74 . V_76 , & V_74 . V_77 ,
V_80 << 1 , 2 , V_81 ) ;
F_24 ( & V_74 . V_78 , & V_74 . V_79 ,
V_82 << 1 , 2 , V_83 ) ;
V_5 = F_4 ( V_2 , V_84 , V_74 . V_76 >> 1 ) ;
if ( ! V_5 ) {
V_26 -> V_74 . V_76 = V_74 . V_76 ;
V_5 = F_4 ( V_2 , V_85 ,
( V_74 . V_76 + V_74 . V_77 ) >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_74 . V_77 = V_74 . V_77 ;
V_5 = F_4 ( V_2 , V_86 , V_74 . V_78 >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_74 . V_78 = V_74 . V_78 ;
V_5 = F_4 ( V_2 , V_87 ,
( V_74 . V_78 + V_74 . V_79 ) >> 1 ) ;
}
if ( ! V_5 )
V_26 -> V_74 . V_79 = V_74 . V_79 ;
return V_5 ;
}
static int F_25 ( struct V_21 * V_22 , struct V_88 * V_71 )
{
if ( V_71 -> type != V_72 )
return - V_42 ;
V_71 -> V_89 . V_76 = V_80 << 1 ;
V_71 -> V_89 . V_78 = V_82 << 1 ;
V_71 -> V_89 . V_77 = V_81 ;
V_71 -> V_89 . V_79 = V_83 ;
V_71 -> V_90 = V_71 -> V_89 ;
V_71 -> V_91 . V_92 = 1 ;
V_71 -> V_91 . V_93 = 1 ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
V_95 -> V_77 = V_26 -> V_74 . V_77 >> V_26 -> V_96 ;
V_95 -> V_79 = V_26 -> V_74 . V_79 >> V_26 -> V_96 ;
V_95 -> V_97 = V_26 -> V_97 ;
V_95 -> V_98 = V_26 -> V_98 ;
V_95 -> V_99 = V_100 ;
return 0 ;
}
static bool F_27 ( int V_77 , int V_79 , struct V_75 * V_74 )
{
return V_77 > V_74 -> V_77 >> 1 || V_79 > V_74 -> V_79 >> 1 ;
}
static T_1 F_28 ( struct V_101 * V_102 ,
unsigned long V_103 , unsigned long V_104 )
{
unsigned long V_105 ;
if ( V_102 -> V_92 && V_102 -> V_93 )
V_105 = V_104 * V_102 -> V_93 /
( V_106 * V_102 -> V_92 ) ;
else
V_105 = V_104 ;
if ( V_103 && V_103 < V_105 )
V_105 = V_103 ;
return ( V_104 - 1 ) / V_105 ;
}
static int F_29 ( struct V_21 * V_22 , struct V_94 * V_95 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_107 * V_108 = F_30 ( V_22 ) ;
struct V_109 * V_110 = V_108 -> V_110 ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
bool V_96 = ! F_27 ( V_95 -> V_77 , V_95 -> V_79 , & V_26 -> V_74 ) ;
struct V_70 V_71 = {
. type = V_72 ,
. V_73 = {
. V_76 = V_26 -> V_74 . V_76 + ( V_26 -> V_74 . V_77 >> 1 ) -
( V_95 -> V_77 >> ( 1 - V_96 ) ) ,
. V_78 = V_26 -> V_74 . V_78 + ( V_26 -> V_74 . V_79 >> 1 ) -
( V_95 -> V_79 >> ( 1 - V_96 ) ) ,
. V_77 = V_95 -> V_77 << V_96 ,
. V_79 = V_95 -> V_79 << V_96 ,
} ,
} ;
T_3 V_97 = V_95 -> V_97 ;
unsigned long V_111 , V_105 ;
T_1 V_112 = 0 , V_113 = 0 , V_114 , V_115 , V_116 ;
int V_5 ;
switch ( V_97 ) {
case V_117 :
F_31 ( & V_2 -> V_16 , L_5 ) ;
V_113 |= V_118 | V_119 | V_120 ;
V_112 |= V_121 ;
break;
case V_122 :
F_31 ( & V_2 -> V_16 , L_6 ) ;
V_113 |= V_118 | V_121 | V_120 ;
V_112 |= V_119 ;
break;
case V_123 :
F_31 ( & V_2 -> V_16 , L_7 ) ;
V_113 |= V_118 | V_121 | V_119 |
V_120 ;
break;
case V_124 :
F_31 ( & V_2 -> V_16 , L_8 ) ;
if ( V_96 ) {
V_113 |= V_118 | V_121 | V_119 ;
V_112 |= V_120 ;
} else {
V_113 |= V_118 | V_121 ;
V_112 |= V_120 | V_119 ;
}
break;
case V_125 :
F_31 ( & V_2 -> V_16 , L_9 ) ;
if ( V_96 ) {
V_113 |= V_118 | V_121 ;
V_112 |= V_120 | V_119 ;
} else {
V_113 |= V_118 | V_121 | V_119 ;
V_112 |= V_120 ;
}
break;
case V_126 :
F_31 ( & V_2 -> V_16 , L_10 ) ;
V_113 |= V_121 | V_120 | V_119 ;
V_112 |= V_127 | V_118 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_11 , V_97 ) ;
return - V_42 ;
}
V_26 -> V_97 = V_97 ;
if ( V_97 == V_117 ||
V_97 == V_126 ) {
V_115 = V_128 ;
V_114 = 0 ;
V_26 -> V_104 = 4000000 ;
} else {
V_115 = 0 ;
V_114 = V_128 ;
V_26 -> V_104 = 8000000 ;
}
if ( V_97 == V_126 )
V_26 -> V_98 = V_129 ;
else if ( V_97 != 0 )
V_26 -> V_98 = V_130 ;
if ( V_96 ) {
F_31 ( & V_2 -> V_16 , L_12 ) ;
V_112 |= V_131 ;
V_26 -> V_104 /= 2 ;
} else {
F_31 ( & V_2 -> V_16 , L_13 ) ;
V_113 |= V_131 ;
}
V_26 -> V_96 = V_96 ;
if ( V_110 ) {
if ( V_110 -> V_132 == 8000000 ) {
F_31 ( & V_2 -> V_16 , L_14 ) ;
V_116 = V_133 ;
} else if ( V_110 -> V_132 == 12000000 ) {
F_31 ( & V_2 -> V_16 , L_15 ) ;
V_116 = V_134 ;
} else if ( V_110 -> V_132 == 16000000 ) {
F_31 ( & V_2 -> V_16 , L_16 ) ;
V_116 = V_135 ;
} else if ( V_110 -> V_132 == 24000000 ) {
F_31 ( & V_2 -> V_16 , L_17 ) ;
V_116 = V_136 ;
} else {
F_3 ( & V_2 -> V_16 ,
L_18 ) ;
return - V_42 ;
}
V_111 = V_110 -> V_132 ;
V_26 -> V_103 = V_110 -> V_137 ;
} else {
V_116 = V_136 ;
V_111 = 24000000 ;
V_26 -> V_103 = 0 ;
F_31 ( & V_2 -> V_16 , L_19 ) ;
}
V_116 |= F_28 ( & V_26 -> V_138 , V_26 -> V_103 , V_26 -> V_104 ) ;
V_105 = V_26 -> V_104 / F_32 ( V_116 ) ;
F_31 ( & V_2 -> V_16 , L_20 ,
V_111 / V_105 , 10 * V_111 % V_105 / V_105 ) ;
V_5 = F_22 ( V_22 , & V_71 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_139 , V_112 , V_113 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_140 , V_116 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_141 , V_114 , V_115 ) ;
if ( ! V_5 ) {
V_95 -> V_98 = V_26 -> V_98 ;
V_95 -> V_77 = V_26 -> V_74 . V_77 >> V_96 ;
V_95 -> V_79 = V_26 -> V_74 . V_79 >> V_96 ;
}
return V_5 ;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( F_27 ( V_95 -> V_77 , V_95 -> V_79 , & V_26 -> V_74 ) )
F_34 ( & V_95 -> V_77 , 2 , V_81 , 1 ,
& V_95 -> V_79 , 2 , V_83 , 1 , 0 ) ;
V_95 -> V_99 = V_100 ;
switch ( V_95 -> V_97 ) {
case V_142 :
V_95 -> V_97 = V_117 ;
case V_117 :
case V_123 :
case V_122 :
case V_125 :
case V_124 :
V_95 -> V_98 = V_130 ;
break;
default:
V_95 -> V_97 = V_126 ;
case V_126 :
V_95 -> V_98 = V_129 ;
break;
}
return 0 ;
}
static int F_35 ( struct V_21 * V_22 , unsigned int V_143 ,
T_3 * V_97 )
{
if ( V_143 >= F_36 ( V_144 ) )
return - V_42 ;
* V_97 = V_144 [ V_143 ] ;
return 0 ;
}
static int F_37 ( struct V_21 * V_22 , struct V_145 * V_146 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_147 * V_148 = & V_146 -> V_149 . V_150 ;
if ( V_146 -> type != V_72 )
return - V_42 ;
memset ( V_148 , 0 , sizeof( * V_148 ) ) ;
V_148 -> V_151 = V_152 ;
V_148 -> V_102 . V_92 = F_32 ( F_28 ( & V_26 -> V_138 ,
V_26 -> V_103 , V_26 -> V_104 ) ) ;
V_148 -> V_102 . V_93 = V_106 ;
F_31 ( & V_2 -> V_16 , L_21 ,
V_148 -> V_102 . V_92 , V_148 -> V_102 . V_93 ) ;
return 0 ;
}
static int F_38 ( struct V_21 * V_22 , struct V_145 * V_146 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_147 * V_148 = & V_146 -> V_149 . V_150 ;
struct V_101 * V_138 = & V_148 -> V_102 ;
int div , V_5 ;
T_1 V_116 ;
if ( V_146 -> type != V_72 )
return - V_42 ;
if ( V_148 -> V_153 != 0 )
return - V_42 ;
if ( V_138 -> V_92 == 0 || V_138 -> V_93 == 0 )
div = 1 ;
else
div = ( V_138 -> V_92 * V_106 ) / V_138 -> V_93 ;
if ( div == 0 )
div = 1 ;
else if ( div > F_32 ( V_154 ) )
div = F_32 ( V_154 ) ;
V_26 -> V_138 . V_92 = div ;
V_26 -> V_138 . V_93 = V_106 ;
V_116 = F_28 ( & V_26 -> V_138 , V_26 -> V_103 , V_26 -> V_104 ) ;
V_5 = F_6 ( V_2 , V_140 , V_116 , V_154 ) ;
if ( ! V_5 ) {
V_138 -> V_92 = F_32 ( V_116 ) ;
V_138 -> V_93 = V_106 ;
}
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_5 ;
F_31 ( & V_2 -> V_16 , L_22 ) ;
V_5 = F_6 ( V_2 , V_139 , V_155 , 0 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_23 ) ;
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_5 ;
F_31 ( & V_2 -> V_16 , L_24 ) ;
V_5 = F_4 ( V_2 , V_139 , 0 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_43 , 0 , V_156 ) ;
return V_5 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
T_1 V_157 , V_158 , V_159 , V_160 ;
int V_5 ;
V_5 = F_18 ( & V_26 -> V_20 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_161 , & V_157 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_162 , & V_158 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_163 , & V_159 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_164 , & V_160 ) ;
if ( V_5 )
goto V_165;
if ( ( V_157 != V_166 ) || ( V_158 != V_167 ) ) {
F_3 ( & V_2 -> V_16 , L_25 ,
V_157 , V_158 ) ;
V_5 = - V_168 ;
goto V_165;
}
F_42 ( & V_2 -> V_16 ,
L_26 ,
V_157 , V_158 , V_159 , V_160 ) ;
V_5 = F_39 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_40 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_43 ( & V_26 -> V_28 ) ;
V_165:
F_18 ( & V_26 -> V_20 , 0 ) ;
return V_5 ;
}
static int F_44 ( struct V_21 * V_22 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
V_170 -> V_10 = V_171 |
V_172 | V_173 |
V_174 | V_175 |
V_176 | V_177 |
V_178 ;
V_170 -> type = V_179 ;
V_170 -> V_10 = F_45 ( V_68 , V_170 ) ;
return 0 ;
}
static int F_46 ( struct V_21 * V_22 ,
const struct V_169 * V_170 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
unsigned long V_10 = F_45 ( V_68 , V_170 ) ;
int V_5 ;
if ( V_10 & V_172 )
V_5 = F_6 ( V_2 , V_180 , V_181 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_180 , 0 , V_181 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_175 )
V_5 = F_6 ( V_2 , V_182 , V_183 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_182 , 0 , V_183 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_176 )
V_5 = F_6 ( V_2 , V_180 , V_184 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_180 , 0 , V_184 ) ;
return V_5 ;
}
static int F_47 ( struct V_1 * V_2 ,
const struct V_185 * V_186 )
{
struct V_19 * V_26 ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
int V_5 ;
if ( ! V_68 ) {
F_3 ( & V_2 -> V_16 , L_27 ) ;
return - V_42 ;
}
V_26 = F_48 ( & V_2 -> V_16 , sizeof( * V_26 ) , V_187 ) ;
if ( ! V_26 ) {
F_3 ( & V_2 -> V_16 ,
L_28 ) ;
return - V_188 ;
}
F_49 ( & V_26 -> V_20 , V_2 , & V_189 ) ;
F_50 ( & V_26 -> V_28 , 13 ) ;
F_51 ( & V_26 -> V_28 , & V_190 ,
V_59 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_26 -> V_28 , & V_190 ,
V_61 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_191 = F_51 ( & V_26 -> V_28 , & V_190 ,
V_31 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_33 = F_51 ( & V_26 -> V_28 , & V_190 ,
V_192 , 0 , 0x3f , 1 , V_193 ) ;
V_26 -> V_194 = F_51 ( & V_26 -> V_28 , & V_190 ,
V_34 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_37 = F_51 ( & V_26 -> V_28 , & V_190 ,
V_195 , 0 , 0xff , 1 , V_196 ) ;
V_26 -> V_38 = F_51 ( & V_26 -> V_28 , & V_190 ,
V_197 , 0 , 0xff , 1 , V_198 ) ;
F_51 ( & V_26 -> V_28 , & V_190 ,
V_46 , 0 , 0xf , 1 , 0x8 ) ;
F_51 ( & V_26 -> V_28 , & V_190 ,
V_49 , 0 , V_51 , 1 , V_199 ) ;
F_51 ( & V_26 -> V_28 , & V_190 ,
V_52 , 0 , 0xff , 1 , 0x80 ) ;
V_26 -> V_200 = F_52 ( & V_26 -> V_28 ,
& V_190 , V_39 ,
V_56 , 0 , V_54 ) ;
V_26 -> V_41 = F_51 ( & V_26 -> V_28 , & V_190 ,
V_201 , 0 , 0xff , 1 , V_202 ) ;
F_51 ( & V_26 -> V_28 , & V_190 ,
V_57 , 0 , 0xff , 1 , 0x12 ) ;
V_26 -> V_20 . V_203 = & V_26 -> V_28 ;
if ( V_26 -> V_28 . error )
return V_26 -> V_28 . error ;
F_53 ( 2 , & V_26 -> V_191 , 0 , true ) ;
F_53 ( 3 , & V_26 -> V_194 , 0 , true ) ;
F_53 ( 2 , & V_26 -> V_200 ,
V_56 , true ) ;
V_26 -> V_74 . V_76 = V_80 << 1 ;
V_26 -> V_74 . V_78 = V_82 << 1 ;
V_26 -> V_74 . V_77 = V_81 ;
V_26 -> V_74 . V_79 = V_83 ;
V_26 -> V_96 = false ;
V_26 -> V_97 = V_122 ;
V_26 -> V_98 = V_130 ;
V_26 -> V_69 = F_54 ( & V_2 -> V_16 , L_29 ) ;
if ( F_55 ( V_26 -> V_69 ) ) {
V_5 = F_56 ( V_26 -> V_69 ) ;
goto V_204;
}
V_5 = F_41 ( V_2 ) ;
if ( V_5 ) {
F_57 ( V_26 -> V_69 ) ;
V_204:
F_58 ( & V_26 -> V_28 ) ;
}
return V_5 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
F_57 ( V_26 -> V_69 ) ;
F_60 ( & V_26 -> V_20 ) ;
F_58 ( & V_26 -> V_28 ) ;
return 0 ;
}
