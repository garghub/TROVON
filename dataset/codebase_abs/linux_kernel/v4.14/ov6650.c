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
struct V_19 * V_26 = F_7 ( V_2 ) ;
int V_5 = 0 ;
if ( V_66 )
V_5 = F_19 ( V_26 -> V_67 ) ;
else
F_20 ( V_26 -> V_67 ) ;
return V_5 ;
}
static int F_21 ( struct V_21 * V_22 ,
struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_71 -> V_72 != V_73 )
return - V_42 ;
switch ( V_71 -> V_74 ) {
case V_75 :
case V_76 :
V_71 -> V_77 . V_78 = V_79 << 1 ;
V_71 -> V_77 . V_80 = V_81 << 1 ;
V_71 -> V_77 . V_82 = V_83 ;
V_71 -> V_77 . V_84 = V_85 ;
return 0 ;
case V_86 :
V_71 -> V_77 = V_26 -> V_87 ;
return 0 ;
default:
return - V_42 ;
}
}
static int F_22 ( struct V_21 * V_22 ,
struct V_68 * V_69 ,
struct V_70 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_88 V_87 = V_71 -> V_77 ;
int V_5 ;
if ( V_71 -> V_72 != V_73 ||
V_71 -> V_74 != V_86 )
return - V_42 ;
F_23 ( & V_87 . V_82 , 2 , V_83 , 1 ,
& V_87 . V_84 , 2 , V_85 , 1 , 0 ) ;
F_23 ( & V_87 . V_78 , V_79 << 1 ,
( V_79 << 1 ) + V_83 - ( V_89 ) V_87 . V_82 , 1 ,
& V_87 . V_80 , V_81 << 1 ,
( V_81 << 1 ) + V_85 - ( V_89 ) V_87 . V_84 , 1 ,
0 ) ;
V_5 = F_4 ( V_2 , V_90 , V_87 . V_78 >> 1 ) ;
if ( ! V_5 ) {
V_26 -> V_87 . V_78 = V_87 . V_78 ;
V_5 = F_4 ( V_2 , V_91 ,
( V_87 . V_78 + V_87 . V_82 ) >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_87 . V_82 = V_87 . V_82 ;
V_5 = F_4 ( V_2 , V_92 , V_87 . V_80 >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_87 . V_80 = V_87 . V_80 ;
V_5 = F_4 ( V_2 , V_93 ,
( V_87 . V_80 + V_87 . V_84 ) >> 1 ) ;
}
if ( ! V_5 )
V_26 -> V_87 . V_84 = V_87 . V_84 ;
return V_5 ;
}
static int F_24 ( struct V_21 * V_22 ,
struct V_68 * V_69 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_95 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_95 -> V_98 )
return - V_42 ;
V_97 -> V_82 = V_26 -> V_87 . V_82 >> V_26 -> V_99 ;
V_97 -> V_84 = V_26 -> V_87 . V_84 >> V_26 -> V_99 ;
V_97 -> V_100 = V_26 -> V_100 ;
V_97 -> V_101 = V_26 -> V_101 ;
V_97 -> V_102 = V_103 ;
return 0 ;
}
static bool F_25 ( int V_82 , int V_84 , struct V_88 * V_87 )
{
return V_82 > V_87 -> V_82 >> 1 || V_84 > V_87 -> V_84 >> 1 ;
}
static T_1 F_26 ( struct V_104 * V_105 ,
unsigned long V_106 , unsigned long V_107 )
{
unsigned long V_108 ;
if ( V_105 -> V_109 && V_105 -> V_110 )
V_108 = V_107 * V_105 -> V_110 /
( V_111 * V_105 -> V_109 ) ;
else
V_108 = V_107 ;
if ( V_106 && V_106 < V_108 )
V_108 = V_106 ;
return ( V_107 - 1 ) / V_108 ;
}
static int F_27 ( struct V_21 * V_22 , struct V_96 * V_97 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
bool V_99 = ! F_25 ( V_97 -> V_82 , V_97 -> V_84 , & V_26 -> V_87 ) ;
struct V_70 V_71 = {
. V_72 = V_73 ,
. V_74 = V_86 ,
. V_77 . V_78 = V_26 -> V_87 . V_78 + ( V_26 -> V_87 . V_82 >> 1 ) -
( V_97 -> V_82 >> ( 1 - V_99 ) ) ,
. V_77 . V_80 = V_26 -> V_87 . V_80 + ( V_26 -> V_87 . V_84 >> 1 ) -
( V_97 -> V_84 >> ( 1 - V_99 ) ) ,
. V_77 . V_82 = V_97 -> V_82 << V_99 ,
. V_77 . V_84 = V_97 -> V_84 << V_99 ,
} ;
T_3 V_100 = V_97 -> V_100 ;
unsigned long V_112 , V_108 ;
T_1 V_113 = 0 , V_114 = 0 , V_115 , V_116 , V_117 ;
int V_5 ;
switch ( V_100 ) {
case V_118 :
F_28 ( & V_2 -> V_16 , L_5 ) ;
V_114 |= V_119 | V_120 | V_121 ;
V_113 |= V_122 ;
break;
case V_123 :
F_28 ( & V_2 -> V_16 , L_6 ) ;
V_114 |= V_119 | V_122 | V_121 ;
V_113 |= V_120 ;
break;
case V_124 :
F_28 ( & V_2 -> V_16 , L_7 ) ;
V_114 |= V_119 | V_122 | V_120 |
V_121 ;
break;
case V_125 :
F_28 ( & V_2 -> V_16 , L_8 ) ;
if ( V_99 ) {
V_114 |= V_119 | V_122 | V_120 ;
V_113 |= V_121 ;
} else {
V_114 |= V_119 | V_122 ;
V_113 |= V_121 | V_120 ;
}
break;
case V_126 :
F_28 ( & V_2 -> V_16 , L_9 ) ;
if ( V_99 ) {
V_114 |= V_119 | V_122 ;
V_113 |= V_121 | V_120 ;
} else {
V_114 |= V_119 | V_122 | V_120 ;
V_113 |= V_121 ;
}
break;
case V_127 :
F_28 ( & V_2 -> V_16 , L_10 ) ;
V_114 |= V_122 | V_121 | V_120 ;
V_113 |= V_128 | V_119 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_11 , V_100 ) ;
return - V_42 ;
}
V_26 -> V_100 = V_100 ;
if ( V_100 == V_118 ||
V_100 == V_127 ) {
V_116 = V_129 ;
V_115 = 0 ;
V_26 -> V_107 = 4000000 ;
} else {
V_116 = 0 ;
V_115 = V_129 ;
V_26 -> V_107 = 8000000 ;
}
if ( V_100 == V_127 )
V_26 -> V_101 = V_130 ;
else if ( V_100 != 0 )
V_26 -> V_101 = V_131 ;
if ( V_99 ) {
F_28 ( & V_2 -> V_16 , L_12 ) ;
V_113 |= V_132 ;
V_26 -> V_107 /= 2 ;
} else {
F_28 ( & V_2 -> V_16 , L_13 ) ;
V_114 |= V_132 ;
}
V_26 -> V_99 = V_99 ;
V_117 = V_133 ;
V_112 = 12000000 ;
V_26 -> V_106 = 1334000 ;
F_28 ( & V_2 -> V_16 , L_14 ) ;
V_117 |= F_26 ( & V_26 -> V_134 , V_26 -> V_106 , V_26 -> V_107 ) ;
V_108 = V_26 -> V_107 / F_29 ( V_117 ) ;
F_28 ( & V_2 -> V_16 , L_15 ,
V_112 / V_108 , 10 * V_112 % V_108 / V_108 ) ;
V_5 = F_22 ( V_22 , NULL , & V_71 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_135 , V_113 , V_114 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_136 , V_117 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_137 , V_115 , V_116 ) ;
if ( ! V_5 ) {
V_97 -> V_101 = V_26 -> V_101 ;
V_97 -> V_82 = V_26 -> V_87 . V_82 >> V_99 ;
V_97 -> V_84 = V_26 -> V_87 . V_84 >> V_99 ;
}
return V_5 ;
}
static int F_30 ( struct V_21 * V_22 ,
struct V_68 * V_69 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = & V_95 -> V_95 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_95 -> V_98 )
return - V_42 ;
if ( F_25 ( V_97 -> V_82 , V_97 -> V_84 , & V_26 -> V_87 ) )
F_23 ( & V_97 -> V_82 , 2 , V_83 , 1 ,
& V_97 -> V_84 , 2 , V_85 , 1 , 0 ) ;
V_97 -> V_102 = V_103 ;
switch ( V_97 -> V_100 ) {
case V_138 :
V_97 -> V_100 = V_118 ;
case V_118 :
case V_124 :
case V_123 :
case V_126 :
case V_125 :
V_97 -> V_101 = V_131 ;
break;
default:
V_97 -> V_100 = V_127 ;
case V_127 :
V_97 -> V_101 = V_130 ;
break;
}
if ( V_95 -> V_72 == V_73 )
return F_27 ( V_22 , V_97 ) ;
V_69 -> V_139 = * V_97 ;
return 0 ;
}
static int F_31 ( struct V_21 * V_22 ,
struct V_68 * V_69 ,
struct V_140 * V_100 )
{
if ( V_100 -> V_98 || V_100 -> V_141 >= F_32 ( V_142 ) )
return - V_42 ;
V_100 -> V_100 = V_142 [ V_100 -> V_141 ] ;
return 0 ;
}
static int F_33 ( struct V_21 * V_22 , struct V_143 * V_144 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_145 * V_146 = & V_144 -> V_147 . V_148 ;
if ( V_144 -> type != V_149 )
return - V_42 ;
memset ( V_146 , 0 , sizeof( * V_146 ) ) ;
V_146 -> V_150 = V_151 ;
V_146 -> V_105 . V_109 = F_29 ( F_26 ( & V_26 -> V_134 ,
V_26 -> V_106 , V_26 -> V_107 ) ) ;
V_146 -> V_105 . V_110 = V_111 ;
F_28 ( & V_2 -> V_16 , L_16 ,
V_146 -> V_105 . V_109 , V_146 -> V_105 . V_110 ) ;
return 0 ;
}
static int F_34 ( struct V_21 * V_22 , struct V_143 * V_144 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_145 * V_146 = & V_144 -> V_147 . V_148 ;
struct V_104 * V_134 = & V_146 -> V_105 ;
int div , V_5 ;
T_1 V_117 ;
if ( V_144 -> type != V_149 )
return - V_42 ;
if ( V_146 -> V_152 != 0 )
return - V_42 ;
if ( V_134 -> V_109 == 0 || V_134 -> V_110 == 0 )
div = 1 ;
else
div = ( V_134 -> V_109 * V_111 ) / V_134 -> V_110 ;
if ( div == 0 )
div = 1 ;
else if ( div > F_29 ( V_153 ) )
div = F_29 ( V_153 ) ;
V_26 -> V_134 . V_109 = div ;
V_26 -> V_134 . V_110 = V_111 ;
V_117 = F_26 ( & V_26 -> V_134 , V_26 -> V_106 , V_26 -> V_107 ) ;
V_5 = F_6 ( V_2 , V_136 , V_117 , V_153 ) ;
if ( ! V_5 ) {
V_134 -> V_109 = F_29 ( V_117 ) ;
V_134 -> V_110 = V_111 ;
}
return V_5 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_5 ;
F_28 ( & V_2 -> V_16 , L_17 ) ;
V_5 = F_6 ( V_2 , V_135 , V_154 , 0 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_18 ) ;
return V_5 ;
}
static int F_36 ( struct V_1 * V_2 )
{
int V_5 ;
F_28 ( & V_2 -> V_16 , L_19 ) ;
V_5 = F_4 ( V_2 , V_135 , 0 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_43 , 0 , V_155 ) ;
return V_5 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
T_1 V_156 , V_157 , V_158 , V_159 ;
int V_5 ;
V_5 = F_18 ( & V_26 -> V_20 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_160 , & V_156 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_161 , & V_157 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_162 , & V_158 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_163 , & V_159 ) ;
if ( V_5 )
goto V_164;
if ( ( V_156 != V_165 ) || ( V_157 != V_166 ) ) {
F_3 ( & V_2 -> V_16 , L_20 ,
V_156 , V_157 ) ;
V_5 = - V_167 ;
goto V_164;
}
F_38 ( & V_2 -> V_16 ,
L_21 ,
V_156 , V_157 , V_158 , V_159 ) ;
V_5 = F_35 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_36 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_39 ( & V_26 -> V_28 ) ;
V_164:
F_18 ( & V_26 -> V_20 , 0 ) ;
return V_5 ;
}
static int F_40 ( struct V_21 * V_22 ,
struct V_168 * V_69 )
{
V_69 -> V_10 = V_169 |
V_170 | V_171 |
V_172 | V_173 |
V_174 | V_175 |
V_176 ;
V_69 -> type = V_177 ;
return 0 ;
}
static int F_41 ( struct V_21 * V_22 ,
const struct V_168 * V_69 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_5 ;
if ( V_69 -> V_10 & V_170 )
V_5 = F_6 ( V_2 , V_178 , V_179 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_178 , 0 , V_179 ) ;
if ( V_5 )
return V_5 ;
if ( V_69 -> V_10 & V_173 )
V_5 = F_6 ( V_2 , V_180 , V_181 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_180 , 0 , V_181 ) ;
if ( V_5 )
return V_5 ;
if ( V_69 -> V_10 & V_174 )
V_5 = F_6 ( V_2 , V_178 , V_182 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_178 , 0 , V_182 ) ;
return V_5 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_183 * V_184 )
{
struct V_19 * V_26 ;
int V_5 ;
V_26 = F_43 ( & V_2 -> V_16 , sizeof( * V_26 ) , V_185 ) ;
if ( ! V_26 ) {
F_3 ( & V_2 -> V_16 ,
L_22 ) ;
return - V_186 ;
}
F_44 ( & V_26 -> V_20 , V_2 , & V_187 ) ;
F_45 ( & V_26 -> V_28 , 13 ) ;
F_46 ( & V_26 -> V_28 , & V_188 ,
V_59 , 0 , 1 , 1 , 0 ) ;
F_46 ( & V_26 -> V_28 , & V_188 ,
V_61 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_189 = F_46 ( & V_26 -> V_28 , & V_188 ,
V_31 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_33 = F_46 ( & V_26 -> V_28 , & V_188 ,
V_190 , 0 , 0x3f , 1 , V_191 ) ;
V_26 -> V_192 = F_46 ( & V_26 -> V_28 , & V_188 ,
V_34 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_37 = F_46 ( & V_26 -> V_28 , & V_188 ,
V_193 , 0 , 0xff , 1 , V_194 ) ;
V_26 -> V_38 = F_46 ( & V_26 -> V_28 , & V_188 ,
V_195 , 0 , 0xff , 1 , V_196 ) ;
F_46 ( & V_26 -> V_28 , & V_188 ,
V_46 , 0 , 0xf , 1 , 0x8 ) ;
F_46 ( & V_26 -> V_28 , & V_188 ,
V_49 , 0 , V_51 , 1 , V_197 ) ;
F_46 ( & V_26 -> V_28 , & V_188 ,
V_52 , 0 , 0xff , 1 , 0x80 ) ;
V_26 -> V_198 = F_47 ( & V_26 -> V_28 ,
& V_188 , V_39 ,
V_56 , 0 , V_54 ) ;
V_26 -> V_41 = F_46 ( & V_26 -> V_28 , & V_188 ,
V_199 , 0 , 0xff , 1 , V_200 ) ;
F_46 ( & V_26 -> V_28 , & V_188 ,
V_57 , 0 , 0xff , 1 , 0x12 ) ;
V_26 -> V_20 . V_201 = & V_26 -> V_28 ;
if ( V_26 -> V_28 . error )
return V_26 -> V_28 . error ;
F_48 ( 2 , & V_26 -> V_189 , 0 , true ) ;
F_48 ( 3 , & V_26 -> V_192 , 0 , true ) ;
F_48 ( 2 , & V_26 -> V_198 ,
V_56 , true ) ;
V_26 -> V_87 . V_78 = V_79 << 1 ;
V_26 -> V_87 . V_80 = V_81 << 1 ;
V_26 -> V_87 . V_82 = V_83 ;
V_26 -> V_87 . V_84 = V_85 ;
V_26 -> V_99 = false ;
V_26 -> V_100 = V_123 ;
V_26 -> V_101 = V_131 ;
V_26 -> V_67 = F_49 ( & V_2 -> V_16 , NULL ) ;
if ( F_50 ( V_26 -> V_67 ) ) {
V_5 = F_51 ( V_26 -> V_67 ) ;
goto V_202;
}
V_5 = F_37 ( V_2 ) ;
if ( V_5 ) {
F_52 ( V_26 -> V_67 ) ;
V_202:
F_53 ( & V_26 -> V_28 ) ;
}
return V_5 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
F_52 ( V_26 -> V_67 ) ;
F_55 ( & V_26 -> V_20 ) ;
F_53 ( & V_26 -> V_28 ) ;
return 0 ;
}
