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
struct V_63 * V_30 )
{
V_30 -> V_64 = V_65 ;
V_30 -> V_66 = 0 ;
return 0 ;
}
static int F_17 ( struct V_21 * V_22 ,
struct V_67 * V_3 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
int V_5 ;
T_1 V_4 ;
if ( V_3 -> V_3 & ~ 0xff )
return - V_42 ;
V_3 -> V_68 = 1 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( ! V_5 )
V_3 -> V_4 = ( V_69 ) V_4 ;
return V_5 ;
}
static int F_18 ( struct V_21 * V_22 ,
struct V_67 * V_3 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
if ( V_3 -> V_3 & ~ 0xff || V_3 -> V_4 & ~ 0xff )
return - V_42 ;
return F_4 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static int F_19 ( struct V_21 * V_22 , int V_70 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_71 * V_72 = F_20 ( V_2 ) ;
return F_21 ( & V_2 -> V_16 , V_72 , V_70 ) ;
}
static int F_22 ( struct V_21 * V_22 , struct V_73 * V_74 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
V_74 -> type = V_75 ;
V_74 -> V_76 = V_26 -> V_77 ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 , const struct V_73 * V_74 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_78 V_77 = V_74 -> V_76 ;
int V_5 ;
if ( V_74 -> type != V_75 )
return - V_42 ;
V_77 . V_79 = F_24 ( V_77 . V_79 , 2 ) ;
V_77 . V_80 = F_24 ( V_77 . V_80 , 2 ) ;
V_77 . V_81 = F_24 ( V_77 . V_81 , 2 ) ;
V_77 . V_82 = F_24 ( V_77 . V_82 , 2 ) ;
F_25 ( & V_77 . V_79 , & V_77 . V_80 ,
V_83 << 1 , 2 , V_84 ) ;
F_25 ( & V_77 . V_81 , & V_77 . V_82 ,
V_85 << 1 , 2 , V_86 ) ;
V_5 = F_4 ( V_2 , V_87 , V_77 . V_79 >> 1 ) ;
if ( ! V_5 ) {
V_26 -> V_77 . V_79 = V_77 . V_79 ;
V_5 = F_4 ( V_2 , V_88 ,
( V_77 . V_79 + V_77 . V_80 ) >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_77 . V_80 = V_77 . V_80 ;
V_5 = F_4 ( V_2 , V_89 , V_77 . V_81 >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_77 . V_81 = V_77 . V_81 ;
V_5 = F_4 ( V_2 , V_90 ,
( V_77 . V_81 + V_77 . V_82 ) >> 1 ) ;
}
if ( ! V_5 )
V_26 -> V_77 . V_82 = V_77 . V_82 ;
return V_5 ;
}
static int F_26 ( struct V_21 * V_22 , struct V_91 * V_74 )
{
if ( V_74 -> type != V_75 )
return - V_42 ;
V_74 -> V_92 . V_79 = V_83 << 1 ;
V_74 -> V_92 . V_81 = V_85 << 1 ;
V_74 -> V_92 . V_80 = V_84 ;
V_74 -> V_92 . V_82 = V_86 ;
V_74 -> V_93 = V_74 -> V_92 ;
V_74 -> V_94 . V_95 = 1 ;
V_74 -> V_94 . V_96 = 1 ;
return 0 ;
}
static int F_27 ( struct V_21 * V_22 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
V_98 -> V_80 = V_26 -> V_77 . V_80 >> V_26 -> V_99 ;
V_98 -> V_82 = V_26 -> V_77 . V_82 >> V_26 -> V_99 ;
V_98 -> V_100 = V_26 -> V_100 ;
V_98 -> V_101 = V_26 -> V_101 ;
V_98 -> V_102 = V_103 ;
return 0 ;
}
static bool F_28 ( int V_80 , int V_82 , struct V_78 * V_77 )
{
return V_80 > V_77 -> V_80 >> 1 || V_82 > V_77 -> V_82 >> 1 ;
}
static T_1 F_29 ( struct V_104 * V_105 ,
unsigned long V_106 , unsigned long V_107 )
{
unsigned long V_108 ;
if ( V_105 -> V_95 && V_105 -> V_96 )
V_108 = V_107 * V_105 -> V_96 /
( V_109 * V_105 -> V_95 ) ;
else
V_108 = V_107 ;
if ( V_106 && V_106 < V_108 )
V_108 = V_106 ;
return ( V_107 - 1 ) / V_108 ;
}
static int F_30 ( struct V_21 * V_22 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_110 * V_111 = F_31 ( V_22 ) ;
struct V_112 * V_113 = V_111 -> V_113 ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
bool V_99 = ! F_28 ( V_98 -> V_80 , V_98 -> V_82 , & V_26 -> V_77 ) ;
struct V_73 V_74 = {
. type = V_75 ,
. V_76 = {
. V_79 = V_26 -> V_77 . V_79 + ( V_26 -> V_77 . V_80 >> 1 ) -
( V_98 -> V_80 >> ( 1 - V_99 ) ) ,
. V_81 = V_26 -> V_77 . V_81 + ( V_26 -> V_77 . V_82 >> 1 ) -
( V_98 -> V_82 >> ( 1 - V_99 ) ) ,
. V_80 = V_98 -> V_80 << V_99 ,
. V_82 = V_98 -> V_82 << V_99 ,
} ,
} ;
enum V_114 V_100 = V_98 -> V_100 ;
unsigned long V_115 , V_108 ;
T_1 V_116 = 0 , V_117 = 0 , V_118 , V_119 , V_120 ;
int V_5 ;
switch ( V_100 ) {
case V_121 :
F_32 ( & V_2 -> V_16 , L_5 ) ;
V_117 |= V_122 | V_123 | V_124 ;
V_116 |= V_125 ;
break;
case V_126 :
F_32 ( & V_2 -> V_16 , L_6 ) ;
V_117 |= V_122 | V_125 | V_124 ;
V_116 |= V_123 ;
break;
case V_127 :
F_32 ( & V_2 -> V_16 , L_7 ) ;
V_117 |= V_122 | V_125 | V_123 |
V_124 ;
break;
case V_128 :
F_32 ( & V_2 -> V_16 , L_8 ) ;
if ( V_99 ) {
V_117 |= V_122 | V_125 | V_123 ;
V_116 |= V_124 ;
} else {
V_117 |= V_122 | V_125 ;
V_116 |= V_124 | V_123 ;
}
break;
case V_129 :
F_32 ( & V_2 -> V_16 , L_9 ) ;
if ( V_99 ) {
V_117 |= V_122 | V_125 ;
V_116 |= V_124 | V_123 ;
} else {
V_117 |= V_122 | V_125 | V_123 ;
V_116 |= V_124 ;
}
break;
case V_130 :
F_32 ( & V_2 -> V_16 , L_10 ) ;
V_117 |= V_125 | V_124 | V_123 ;
V_116 |= V_131 | V_122 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_11 , V_100 ) ;
return - V_42 ;
}
V_26 -> V_100 = V_100 ;
if ( V_100 == V_121 ||
V_100 == V_130 ) {
V_119 = V_132 ;
V_118 = 0 ;
V_26 -> V_107 = 4000000 ;
} else {
V_119 = 0 ;
V_118 = V_132 ;
V_26 -> V_107 = 8000000 ;
}
if ( V_100 == V_130 )
V_26 -> V_101 = V_133 ;
else if ( V_100 != 0 )
V_26 -> V_101 = V_134 ;
if ( V_99 ) {
F_32 ( & V_2 -> V_16 , L_12 ) ;
V_116 |= V_135 ;
V_26 -> V_107 /= 2 ;
} else {
F_32 ( & V_2 -> V_16 , L_13 ) ;
V_117 |= V_135 ;
}
V_26 -> V_99 = V_99 ;
if ( V_113 ) {
if ( V_113 -> V_136 == 8000000 ) {
F_32 ( & V_2 -> V_16 , L_14 ) ;
V_120 = V_137 ;
} else if ( V_113 -> V_136 == 12000000 ) {
F_32 ( & V_2 -> V_16 , L_15 ) ;
V_120 = V_138 ;
} else if ( V_113 -> V_136 == 16000000 ) {
F_32 ( & V_2 -> V_16 , L_16 ) ;
V_120 = V_139 ;
} else if ( V_113 -> V_136 == 24000000 ) {
F_32 ( & V_2 -> V_16 , L_17 ) ;
V_120 = V_140 ;
} else {
F_3 ( & V_2 -> V_16 ,
L_18 ) ;
return - V_42 ;
}
V_115 = V_113 -> V_136 ;
V_26 -> V_106 = V_113 -> V_141 ;
} else {
V_120 = V_140 ;
V_115 = 24000000 ;
V_26 -> V_106 = 0 ;
F_32 ( & V_2 -> V_16 , L_19 ) ;
}
V_120 |= F_29 ( & V_26 -> V_142 , V_26 -> V_106 , V_26 -> V_107 ) ;
V_108 = V_26 -> V_107 / F_33 ( V_120 ) ;
F_32 ( & V_2 -> V_16 , L_20 ,
V_115 / V_108 , 10 * V_115 % V_108 / V_108 ) ;
V_5 = F_23 ( V_22 , & V_74 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_143 , V_116 , V_117 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_144 , V_120 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_145 , V_118 , V_119 ) ;
if ( ! V_5 ) {
V_98 -> V_101 = V_26 -> V_101 ;
V_98 -> V_80 = V_26 -> V_77 . V_80 >> V_99 ;
V_98 -> V_82 = V_26 -> V_77 . V_82 >> V_99 ;
}
return V_5 ;
}
static int F_34 ( struct V_21 * V_22 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( F_28 ( V_98 -> V_80 , V_98 -> V_82 , & V_26 -> V_77 ) )
F_35 ( & V_98 -> V_80 , 2 , V_84 , 1 ,
& V_98 -> V_82 , 2 , V_86 , 1 , 0 ) ;
V_98 -> V_102 = V_103 ;
switch ( V_98 -> V_100 ) {
case V_146 :
V_98 -> V_100 = V_121 ;
case V_121 :
case V_127 :
case V_126 :
case V_129 :
case V_128 :
V_98 -> V_101 = V_134 ;
break;
default:
V_98 -> V_100 = V_130 ;
case V_130 :
V_98 -> V_101 = V_133 ;
break;
}
return 0 ;
}
static int F_36 ( struct V_21 * V_22 , unsigned int V_147 ,
enum V_114 * V_100 )
{
if ( V_147 >= F_37 ( V_148 ) )
return - V_42 ;
* V_100 = V_148 [ V_147 ] ;
return 0 ;
}
static int F_38 ( struct V_21 * V_22 , struct V_149 * V_150 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_151 * V_152 = & V_150 -> V_153 . V_154 ;
if ( V_150 -> type != V_75 )
return - V_42 ;
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_152 -> V_155 = V_156 ;
V_152 -> V_105 . V_95 = F_33 ( F_29 ( & V_26 -> V_142 ,
V_26 -> V_106 , V_26 -> V_107 ) ) ;
V_152 -> V_105 . V_96 = V_109 ;
F_32 ( & V_2 -> V_16 , L_21 ,
V_152 -> V_105 . V_95 , V_152 -> V_105 . V_96 ) ;
return 0 ;
}
static int F_39 ( struct V_21 * V_22 , struct V_149 * V_150 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_151 * V_152 = & V_150 -> V_153 . V_154 ;
struct V_104 * V_142 = & V_152 -> V_105 ;
int div , V_5 ;
T_1 V_120 ;
if ( V_150 -> type != V_75 )
return - V_42 ;
if ( V_152 -> V_157 != 0 )
return - V_42 ;
if ( V_142 -> V_95 == 0 || V_142 -> V_96 == 0 )
div = 1 ;
else
div = ( V_142 -> V_95 * V_109 ) / V_142 -> V_96 ;
if ( div == 0 )
div = 1 ;
else if ( div > F_33 ( V_158 ) )
div = F_33 ( V_158 ) ;
V_26 -> V_142 . V_95 = div ;
V_26 -> V_142 . V_96 = V_109 ;
V_120 = F_29 ( & V_26 -> V_142 , V_26 -> V_106 , V_26 -> V_107 ) ;
V_5 = F_6 ( V_2 , V_144 , V_120 , V_158 ) ;
if ( ! V_5 ) {
V_142 -> V_95 = F_33 ( V_120 ) ;
V_142 -> V_96 = V_109 ;
}
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_5 ;
F_32 ( & V_2 -> V_16 , L_22 ) ;
V_5 = F_6 ( V_2 , V_143 , V_159 , 0 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_23 ) ;
return V_5 ;
}
static int F_41 ( struct V_1 * V_2 )
{
int V_5 ;
F_32 ( & V_2 -> V_16 , L_24 ) ;
V_5 = F_4 ( V_2 , V_143 , 0 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_43 , 0 , V_160 ) ;
return V_5 ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
T_1 V_161 , V_162 , V_163 , V_164 ;
int V_5 ;
V_5 = F_19 ( & V_26 -> V_20 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_1 ( V_2 , V_165 , & V_161 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_166 , & V_162 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_167 , & V_163 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_168 , & V_164 ) ;
if ( V_5 )
goto V_169;
if ( ( V_161 != V_170 ) || ( V_162 != V_171 ) ) {
F_3 ( & V_2 -> V_16 , L_25 ,
V_161 , V_162 ) ;
V_5 = - V_172 ;
goto V_169;
}
F_43 ( & V_2 -> V_16 ,
L_26 ,
V_161 , V_162 , V_163 , V_164 ) ;
V_5 = F_40 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_41 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_44 ( & V_26 -> V_28 ) ;
V_169:
F_19 ( & V_26 -> V_20 , 0 ) ;
return V_5 ;
}
static int F_45 ( struct V_21 * V_22 ,
struct V_173 * V_174 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_71 * V_72 = F_20 ( V_2 ) ;
V_174 -> V_10 = V_175 |
V_176 | V_177 |
V_178 | V_179 |
V_180 | V_181 |
V_182 ;
V_174 -> type = V_183 ;
V_174 -> V_10 = F_46 ( V_72 , V_174 ) ;
return 0 ;
}
static int F_47 ( struct V_21 * V_22 ,
const struct V_173 * V_174 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_71 * V_72 = F_20 ( V_2 ) ;
unsigned long V_10 = F_46 ( V_72 , V_174 ) ;
int V_5 ;
if ( V_10 & V_176 )
V_5 = F_6 ( V_2 , V_184 , V_185 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_184 , 0 , V_185 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_179 )
V_5 = F_6 ( V_2 , V_186 , V_187 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_186 , 0 , V_187 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_180 )
V_5 = F_6 ( V_2 , V_184 , V_188 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_184 , 0 , V_188 ) ;
return V_5 ;
}
static int F_48 ( struct V_1 * V_2 ,
const struct V_189 * V_190 )
{
struct V_19 * V_26 ;
struct V_71 * V_72 = F_20 ( V_2 ) ;
int V_5 ;
if ( ! V_72 ) {
F_3 ( & V_2 -> V_16 , L_27 ) ;
return - V_42 ;
}
V_26 = F_49 ( sizeof( * V_26 ) , V_191 ) ;
if ( ! V_26 ) {
F_3 ( & V_2 -> V_16 ,
L_28 ) ;
return - V_192 ;
}
F_50 ( & V_26 -> V_20 , V_2 , & V_193 ) ;
F_51 ( & V_26 -> V_28 , 13 ) ;
F_52 ( & V_26 -> V_28 , & V_194 ,
V_59 , 0 , 1 , 1 , 0 ) ;
F_52 ( & V_26 -> V_28 , & V_194 ,
V_61 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_195 = F_52 ( & V_26 -> V_28 , & V_194 ,
V_31 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_33 = F_52 ( & V_26 -> V_28 , & V_194 ,
V_196 , 0 , 0x3f , 1 , V_197 ) ;
V_26 -> V_198 = F_52 ( & V_26 -> V_28 , & V_194 ,
V_34 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_37 = F_52 ( & V_26 -> V_28 , & V_194 ,
V_199 , 0 , 0xff , 1 , V_200 ) ;
V_26 -> V_38 = F_52 ( & V_26 -> V_28 , & V_194 ,
V_201 , 0 , 0xff , 1 , V_202 ) ;
F_52 ( & V_26 -> V_28 , & V_194 ,
V_46 , 0 , 0xf , 1 , 0x8 ) ;
F_52 ( & V_26 -> V_28 , & V_194 ,
V_49 , 0 , V_51 , 1 , V_203 ) ;
F_52 ( & V_26 -> V_28 , & V_194 ,
V_52 , 0 , 0xff , 1 , 0x80 ) ;
V_26 -> V_204 = F_53 ( & V_26 -> V_28 ,
& V_194 , V_39 ,
V_56 , 0 , V_54 ) ;
V_26 -> V_41 = F_52 ( & V_26 -> V_28 , & V_194 ,
V_205 , 0 , 0xff , 1 , V_206 ) ;
F_52 ( & V_26 -> V_28 , & V_194 ,
V_57 , 0 , 0xff , 1 , 0x12 ) ;
V_26 -> V_20 . V_207 = & V_26 -> V_28 ;
if ( V_26 -> V_28 . error ) {
int V_14 = V_26 -> V_28 . error ;
F_54 ( V_26 ) ;
return V_14 ;
}
F_55 ( 2 , & V_26 -> V_195 , 0 , true ) ;
F_55 ( 3 , & V_26 -> V_198 , 0 , true ) ;
F_55 ( 2 , & V_26 -> V_204 ,
V_56 , true ) ;
V_26 -> V_77 . V_79 = V_83 << 1 ;
V_26 -> V_77 . V_81 = V_85 << 1 ;
V_26 -> V_77 . V_80 = V_84 ;
V_26 -> V_77 . V_82 = V_86 ;
V_26 -> V_99 = false ;
V_26 -> V_100 = V_126 ;
V_26 -> V_101 = V_134 ;
V_5 = F_42 ( V_2 ) ;
if ( V_5 ) {
F_56 ( & V_26 -> V_28 ) ;
F_54 ( V_26 ) ;
}
return V_5 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
F_58 ( & V_26 -> V_20 ) ;
F_56 ( & V_26 -> V_28 ) ;
F_54 ( V_26 ) ;
return 0 ;
}
