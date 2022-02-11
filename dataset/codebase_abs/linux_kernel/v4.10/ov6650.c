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
static int F_21 ( struct V_21 * V_22 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_73 -> V_74 != V_75 )
return - V_42 ;
switch ( V_73 -> V_76 ) {
case V_77 :
case V_78 :
V_73 -> V_79 . V_80 = V_81 << 1 ;
V_73 -> V_79 . V_82 = V_83 << 1 ;
V_73 -> V_79 . V_84 = V_85 ;
V_73 -> V_79 . V_86 = V_87 ;
return 0 ;
case V_88 :
V_73 -> V_79 = V_26 -> V_89 ;
return 0 ;
default:
return - V_42 ;
}
}
static int F_22 ( struct V_21 * V_22 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_90 V_89 = V_73 -> V_79 ;
int V_5 ;
if ( V_73 -> V_74 != V_75 ||
V_73 -> V_76 != V_88 )
return - V_42 ;
V_89 . V_80 = F_23 ( V_89 . V_80 , 2 ) ;
V_89 . V_84 = F_23 ( V_89 . V_84 , 2 ) ;
V_89 . V_82 = F_23 ( V_89 . V_82 , 2 ) ;
V_89 . V_86 = F_23 ( V_89 . V_86 , 2 ) ;
F_24 ( & V_89 . V_80 , & V_89 . V_84 ,
V_81 << 1 , 2 , V_85 ) ;
F_24 ( & V_89 . V_82 , & V_89 . V_86 ,
V_83 << 1 , 2 , V_87 ) ;
V_5 = F_4 ( V_2 , V_91 , V_89 . V_80 >> 1 ) ;
if ( ! V_5 ) {
V_26 -> V_89 . V_80 = V_89 . V_80 ;
V_5 = F_4 ( V_2 , V_92 ,
( V_89 . V_80 + V_89 . V_84 ) >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_89 . V_84 = V_89 . V_84 ;
V_5 = F_4 ( V_2 , V_93 , V_89 . V_82 >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_89 . V_82 = V_89 . V_82 ;
V_5 = F_4 ( V_2 , V_94 ,
( V_89 . V_82 + V_89 . V_86 ) >> 1 ) ;
}
if ( ! V_5 )
V_26 -> V_89 . V_86 = V_89 . V_86 ;
return V_5 ;
}
static int F_25 ( struct V_21 * V_22 ,
struct V_70 * V_71 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = & V_96 -> V_96 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_96 -> V_99 )
return - V_42 ;
V_98 -> V_84 = V_26 -> V_89 . V_84 >> V_26 -> V_100 ;
V_98 -> V_86 = V_26 -> V_89 . V_86 >> V_26 -> V_100 ;
V_98 -> V_101 = V_26 -> V_101 ;
V_98 -> V_102 = V_26 -> V_102 ;
V_98 -> V_103 = V_104 ;
return 0 ;
}
static bool F_26 ( int V_84 , int V_86 , struct V_90 * V_89 )
{
return V_84 > V_89 -> V_84 >> 1 || V_86 > V_89 -> V_86 >> 1 ;
}
static T_1 F_27 ( struct V_105 * V_106 ,
unsigned long V_107 , unsigned long V_108 )
{
unsigned long V_109 ;
if ( V_106 -> V_110 && V_106 -> V_111 )
V_109 = V_108 * V_106 -> V_111 /
( V_112 * V_106 -> V_110 ) ;
else
V_109 = V_108 ;
if ( V_107 && V_107 < V_109 )
V_109 = V_107 ;
return ( V_108 - 1 ) / V_109 ;
}
static int F_28 ( struct V_21 * V_22 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_113 * V_114 = F_29 ( V_22 ) ;
struct V_115 * V_116 = V_114 -> V_116 ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
bool V_100 = ! F_26 ( V_98 -> V_84 , V_98 -> V_86 , & V_26 -> V_89 ) ;
struct V_72 V_73 = {
. V_74 = V_75 ,
. V_76 = V_88 ,
. V_79 . V_80 = V_26 -> V_89 . V_80 + ( V_26 -> V_89 . V_84 >> 1 ) -
( V_98 -> V_84 >> ( 1 - V_100 ) ) ,
. V_79 . V_82 = V_26 -> V_89 . V_82 + ( V_26 -> V_89 . V_86 >> 1 ) -
( V_98 -> V_86 >> ( 1 - V_100 ) ) ,
. V_79 . V_84 = V_98 -> V_84 << V_100 ,
. V_79 . V_86 = V_98 -> V_86 << V_100 ,
} ;
T_3 V_101 = V_98 -> V_101 ;
unsigned long V_117 , V_109 ;
T_1 V_118 = 0 , V_119 = 0 , V_120 , V_121 , V_122 ;
int V_5 ;
switch ( V_101 ) {
case V_123 :
F_30 ( & V_2 -> V_16 , L_5 ) ;
V_119 |= V_124 | V_125 | V_126 ;
V_118 |= V_127 ;
break;
case V_128 :
F_30 ( & V_2 -> V_16 , L_6 ) ;
V_119 |= V_124 | V_127 | V_126 ;
V_118 |= V_125 ;
break;
case V_129 :
F_30 ( & V_2 -> V_16 , L_7 ) ;
V_119 |= V_124 | V_127 | V_125 |
V_126 ;
break;
case V_130 :
F_30 ( & V_2 -> V_16 , L_8 ) ;
if ( V_100 ) {
V_119 |= V_124 | V_127 | V_125 ;
V_118 |= V_126 ;
} else {
V_119 |= V_124 | V_127 ;
V_118 |= V_126 | V_125 ;
}
break;
case V_131 :
F_30 ( & V_2 -> V_16 , L_9 ) ;
if ( V_100 ) {
V_119 |= V_124 | V_127 ;
V_118 |= V_126 | V_125 ;
} else {
V_119 |= V_124 | V_127 | V_125 ;
V_118 |= V_126 ;
}
break;
case V_132 :
F_30 ( & V_2 -> V_16 , L_10 ) ;
V_119 |= V_127 | V_126 | V_125 ;
V_118 |= V_133 | V_124 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_11 , V_101 ) ;
return - V_42 ;
}
V_26 -> V_101 = V_101 ;
if ( V_101 == V_123 ||
V_101 == V_132 ) {
V_121 = V_134 ;
V_120 = 0 ;
V_26 -> V_108 = 4000000 ;
} else {
V_121 = 0 ;
V_120 = V_134 ;
V_26 -> V_108 = 8000000 ;
}
if ( V_101 == V_132 )
V_26 -> V_102 = V_135 ;
else if ( V_101 != 0 )
V_26 -> V_102 = V_136 ;
if ( V_100 ) {
F_30 ( & V_2 -> V_16 , L_12 ) ;
V_118 |= V_137 ;
V_26 -> V_108 /= 2 ;
} else {
F_30 ( & V_2 -> V_16 , L_13 ) ;
V_119 |= V_137 ;
}
V_26 -> V_100 = V_100 ;
if ( V_116 ) {
if ( V_116 -> V_138 == 8000000 ) {
F_30 ( & V_2 -> V_16 , L_14 ) ;
V_122 = V_139 ;
} else if ( V_116 -> V_138 == 12000000 ) {
F_30 ( & V_2 -> V_16 , L_15 ) ;
V_122 = V_140 ;
} else if ( V_116 -> V_138 == 16000000 ) {
F_30 ( & V_2 -> V_16 , L_16 ) ;
V_122 = V_141 ;
} else if ( V_116 -> V_138 == 24000000 ) {
F_30 ( & V_2 -> V_16 , L_17 ) ;
V_122 = V_142 ;
} else {
F_3 ( & V_2 -> V_16 ,
L_18 ) ;
return - V_42 ;
}
V_117 = V_116 -> V_138 ;
V_26 -> V_107 = V_116 -> V_143 ;
} else {
V_122 = V_142 ;
V_117 = 24000000 ;
V_26 -> V_107 = 0 ;
F_30 ( & V_2 -> V_16 , L_19 ) ;
}
V_122 |= F_27 ( & V_26 -> V_144 , V_26 -> V_107 , V_26 -> V_108 ) ;
V_109 = V_26 -> V_108 / F_31 ( V_122 ) ;
F_30 ( & V_2 -> V_16 , L_20 ,
V_117 / V_109 , 10 * V_117 % V_109 / V_109 ) ;
V_5 = F_22 ( V_22 , NULL , & V_73 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_145 , V_118 , V_119 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_146 , V_122 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_147 , V_120 , V_121 ) ;
if ( ! V_5 ) {
V_98 -> V_102 = V_26 -> V_102 ;
V_98 -> V_84 = V_26 -> V_89 . V_84 >> V_100 ;
V_98 -> V_86 = V_26 -> V_89 . V_86 >> V_100 ;
}
return V_5 ;
}
static int F_32 ( struct V_21 * V_22 ,
struct V_70 * V_71 ,
struct V_95 * V_96 )
{
struct V_97 * V_98 = & V_96 -> V_96 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_96 -> V_99 )
return - V_42 ;
if ( F_26 ( V_98 -> V_84 , V_98 -> V_86 , & V_26 -> V_89 ) )
F_33 ( & V_98 -> V_84 , 2 , V_85 , 1 ,
& V_98 -> V_86 , 2 , V_87 , 1 , 0 ) ;
V_98 -> V_103 = V_104 ;
switch ( V_98 -> V_101 ) {
case V_148 :
V_98 -> V_101 = V_123 ;
case V_123 :
case V_129 :
case V_128 :
case V_131 :
case V_130 :
V_98 -> V_102 = V_136 ;
break;
default:
V_98 -> V_101 = V_132 ;
case V_132 :
V_98 -> V_102 = V_135 ;
break;
}
if ( V_96 -> V_74 == V_75 )
return F_28 ( V_22 , V_98 ) ;
V_71 -> V_149 = * V_98 ;
return 0 ;
}
static int F_34 ( struct V_21 * V_22 ,
struct V_70 * V_71 ,
struct V_150 * V_101 )
{
if ( V_101 -> V_99 || V_101 -> V_151 >= F_35 ( V_152 ) )
return - V_42 ;
V_101 -> V_101 = V_152 [ V_101 -> V_151 ] ;
return 0 ;
}
static int F_36 ( struct V_21 * V_22 , struct V_153 * V_154 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_155 * V_156 = & V_154 -> V_157 . V_158 ;
if ( V_154 -> type != V_159 )
return - V_42 ;
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
V_156 -> V_160 = V_161 ;
V_156 -> V_106 . V_110 = F_31 ( F_27 ( & V_26 -> V_144 ,
V_26 -> V_107 , V_26 -> V_108 ) ) ;
V_156 -> V_106 . V_111 = V_112 ;
F_30 ( & V_2 -> V_16 , L_21 ,
V_156 -> V_106 . V_110 , V_156 -> V_106 . V_111 ) ;
return 0 ;
}
static int F_37 ( struct V_21 * V_22 , struct V_153 * V_154 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_155 * V_156 = & V_154 -> V_157 . V_158 ;
struct V_105 * V_144 = & V_156 -> V_106 ;
int div , V_5 ;
T_1 V_122 ;
if ( V_154 -> type != V_159 )
return - V_42 ;
if ( V_156 -> V_162 != 0 )
return - V_42 ;
if ( V_144 -> V_110 == 0 || V_144 -> V_111 == 0 )
div = 1 ;
else
div = ( V_144 -> V_110 * V_112 ) / V_144 -> V_111 ;
if ( div == 0 )
div = 1 ;
else if ( div > F_31 ( V_163 ) )
div = F_31 ( V_163 ) ;
V_26 -> V_144 . V_110 = div ;
V_26 -> V_144 . V_111 = V_112 ;
V_122 = F_27 ( & V_26 -> V_144 , V_26 -> V_107 , V_26 -> V_108 ) ;
V_5 = F_6 ( V_2 , V_146 , V_122 , V_163 ) ;
if ( ! V_5 ) {
V_144 -> V_110 = F_31 ( V_122 ) ;
V_144 -> V_111 = V_112 ;
}
return V_5 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_5 ;
F_30 ( & V_2 -> V_16 , L_22 ) ;
V_5 = F_6 ( V_2 , V_145 , V_164 , 0 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_23 ) ;
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_5 ;
F_30 ( & V_2 -> V_16 , L_24 ) ;
V_5 = F_4 ( V_2 , V_145 , 0 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_43 , 0 , V_165 ) ;
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
T_1 V_166 , V_167 , V_168 , V_169 ;
int V_5 ;
V_5 = F_18 ( & V_26 -> V_20 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_170 , & V_166 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_171 , & V_167 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_172 , & V_168 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_173 , & V_169 ) ;
if ( V_5 )
goto V_174;
if ( ( V_166 != V_175 ) || ( V_167 != V_176 ) ) {
F_3 ( & V_2 -> V_16 , L_25 ,
V_166 , V_167 ) ;
V_5 = - V_177 ;
goto V_174;
}
F_41 ( & V_2 -> V_16 ,
L_26 ,
V_166 , V_167 , V_168 , V_169 ) ;
V_5 = F_38 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_39 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_42 ( & V_26 -> V_28 ) ;
V_174:
F_18 ( & V_26 -> V_20 , 0 ) ;
return V_5 ;
}
static int F_43 ( struct V_21 * V_22 ,
struct V_178 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
V_71 -> V_10 = V_179 |
V_180 | V_181 |
V_182 | V_183 |
V_184 | V_185 |
V_186 ;
V_71 -> type = V_187 ;
V_71 -> V_10 = F_44 ( V_68 , V_71 ) ;
return 0 ;
}
static int F_45 ( struct V_21 * V_22 ,
const struct V_178 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
unsigned long V_10 = F_44 ( V_68 , V_71 ) ;
int V_5 ;
if ( V_10 & V_180 )
V_5 = F_6 ( V_2 , V_188 , V_189 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_188 , 0 , V_189 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_183 )
V_5 = F_6 ( V_2 , V_190 , V_191 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_190 , 0 , V_191 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_184 )
V_5 = F_6 ( V_2 , V_188 , V_192 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_188 , 0 , V_192 ) ;
return V_5 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_193 * V_194 )
{
struct V_19 * V_26 ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
int V_5 ;
if ( ! V_68 ) {
F_3 ( & V_2 -> V_16 , L_27 ) ;
return - V_42 ;
}
V_26 = F_47 ( & V_2 -> V_16 , sizeof( * V_26 ) , V_195 ) ;
if ( ! V_26 ) {
F_3 ( & V_2 -> V_16 ,
L_28 ) ;
return - V_196 ;
}
F_48 ( & V_26 -> V_20 , V_2 , & V_197 ) ;
F_49 ( & V_26 -> V_28 , 13 ) ;
F_50 ( & V_26 -> V_28 , & V_198 ,
V_59 , 0 , 1 , 1 , 0 ) ;
F_50 ( & V_26 -> V_28 , & V_198 ,
V_61 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_199 = F_50 ( & V_26 -> V_28 , & V_198 ,
V_31 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_33 = F_50 ( & V_26 -> V_28 , & V_198 ,
V_200 , 0 , 0x3f , 1 , V_201 ) ;
V_26 -> V_202 = F_50 ( & V_26 -> V_28 , & V_198 ,
V_34 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_37 = F_50 ( & V_26 -> V_28 , & V_198 ,
V_203 , 0 , 0xff , 1 , V_204 ) ;
V_26 -> V_38 = F_50 ( & V_26 -> V_28 , & V_198 ,
V_205 , 0 , 0xff , 1 , V_206 ) ;
F_50 ( & V_26 -> V_28 , & V_198 ,
V_46 , 0 , 0xf , 1 , 0x8 ) ;
F_50 ( & V_26 -> V_28 , & V_198 ,
V_49 , 0 , V_51 , 1 , V_207 ) ;
F_50 ( & V_26 -> V_28 , & V_198 ,
V_52 , 0 , 0xff , 1 , 0x80 ) ;
V_26 -> V_208 = F_51 ( & V_26 -> V_28 ,
& V_198 , V_39 ,
V_56 , 0 , V_54 ) ;
V_26 -> V_41 = F_50 ( & V_26 -> V_28 , & V_198 ,
V_209 , 0 , 0xff , 1 , V_210 ) ;
F_50 ( & V_26 -> V_28 , & V_198 ,
V_57 , 0 , 0xff , 1 , 0x12 ) ;
V_26 -> V_20 . V_211 = & V_26 -> V_28 ;
if ( V_26 -> V_28 . error )
return V_26 -> V_28 . error ;
F_52 ( 2 , & V_26 -> V_199 , 0 , true ) ;
F_52 ( 3 , & V_26 -> V_202 , 0 , true ) ;
F_52 ( 2 , & V_26 -> V_208 ,
V_56 , true ) ;
V_26 -> V_89 . V_80 = V_81 << 1 ;
V_26 -> V_89 . V_82 = V_83 << 1 ;
V_26 -> V_89 . V_84 = V_85 ;
V_26 -> V_89 . V_86 = V_87 ;
V_26 -> V_100 = false ;
V_26 -> V_101 = V_128 ;
V_26 -> V_102 = V_136 ;
V_26 -> V_69 = F_53 ( & V_2 -> V_16 , L_29 ) ;
if ( F_54 ( V_26 -> V_69 ) ) {
V_5 = F_55 ( V_26 -> V_69 ) ;
goto V_212;
}
V_5 = F_40 ( V_2 ) ;
if ( V_5 ) {
F_56 ( V_26 -> V_69 ) ;
V_212:
F_57 ( & V_26 -> V_28 ) ;
}
return V_5 ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
F_56 ( V_26 -> V_69 ) ;
F_59 ( & V_26 -> V_20 ) ;
F_57 ( & V_26 -> V_28 ) ;
return 0 ;
}
