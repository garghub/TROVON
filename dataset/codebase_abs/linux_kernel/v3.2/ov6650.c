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
static int F_19 ( struct V_21 * V_22 , struct V_70 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
V_71 -> type = V_72 ;
V_71 -> V_73 = V_26 -> V_74 ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 , struct V_70 * V_71 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_75 * V_74 = & V_71 -> V_73 ;
int V_5 ;
if ( V_71 -> type != V_72 )
return - V_42 ;
V_74 -> V_76 = F_21 ( V_74 -> V_76 , 2 ) ;
V_74 -> V_77 = F_21 ( V_74 -> V_77 , 2 ) ;
V_74 -> V_78 = F_21 ( V_74 -> V_78 , 2 ) ;
V_74 -> V_79 = F_21 ( V_74 -> V_79 , 2 ) ;
F_22 ( & V_74 -> V_76 , & V_74 -> V_77 ,
V_80 << 1 , 2 , V_81 ) ;
F_22 ( & V_74 -> V_78 , & V_74 -> V_79 ,
V_82 << 1 , 2 , V_83 ) ;
V_5 = F_4 ( V_2 , V_84 , V_74 -> V_76 >> 1 ) ;
if ( ! V_5 ) {
V_26 -> V_74 . V_76 = V_74 -> V_76 ;
V_5 = F_4 ( V_2 , V_85 ,
( V_74 -> V_76 + V_74 -> V_77 ) >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_74 . V_77 = V_74 -> V_77 ;
V_5 = F_4 ( V_2 , V_86 , V_74 -> V_78 >> 1 ) ;
}
if ( ! V_5 ) {
V_26 -> V_74 . V_78 = V_74 -> V_78 ;
V_5 = F_4 ( V_2 , V_87 ,
( V_74 -> V_78 + V_74 -> V_79 ) >> 1 ) ;
}
if ( ! V_5 )
V_26 -> V_74 . V_79 = V_74 -> V_79 ;
return V_5 ;
}
static int F_23 ( struct V_21 * V_22 , struct V_88 * V_71 )
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
static int F_24 ( struct V_21 * V_22 ,
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
static bool F_25 ( int V_77 , int V_79 , struct V_75 * V_74 )
{
return V_77 > V_74 -> V_77 >> 1 || V_79 > V_74 -> V_79 >> 1 ;
}
static T_1 F_26 ( struct V_101 * V_102 ,
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
static int F_27 ( struct V_21 * V_22 , struct V_94 * V_95 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_107 * V_108 = F_28 ( V_22 ) ;
struct V_109 * V_110 = V_108 -> V_110 ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
bool V_96 = ! F_25 ( V_95 -> V_77 , V_95 -> V_79 , & V_26 -> V_74 ) ;
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
enum V_111 V_97 = V_95 -> V_97 ;
unsigned long V_112 , V_105 ;
T_1 V_113 = 0 , V_114 = 0 , V_115 , V_116 , V_117 ;
int V_5 ;
switch ( V_97 ) {
case V_118 :
F_29 ( & V_2 -> V_16 , L_5 ) ;
V_114 |= V_119 | V_120 | V_121 ;
V_113 |= V_122 ;
break;
case V_123 :
F_29 ( & V_2 -> V_16 , L_6 ) ;
V_114 |= V_119 | V_122 | V_121 ;
V_113 |= V_120 ;
break;
case V_124 :
F_29 ( & V_2 -> V_16 , L_7 ) ;
V_114 |= V_119 | V_122 | V_120 |
V_121 ;
break;
case V_125 :
F_29 ( & V_2 -> V_16 , L_8 ) ;
if ( V_96 ) {
V_114 |= V_119 | V_122 | V_120 ;
V_113 |= V_121 ;
} else {
V_114 |= V_119 | V_122 ;
V_113 |= V_121 | V_120 ;
}
break;
case V_126 :
F_29 ( & V_2 -> V_16 , L_9 ) ;
if ( V_96 ) {
V_114 |= V_119 | V_122 ;
V_113 |= V_121 | V_120 ;
} else {
V_114 |= V_119 | V_122 | V_120 ;
V_113 |= V_121 ;
}
break;
case V_127 :
F_29 ( & V_2 -> V_16 , L_10 ) ;
V_114 |= V_122 | V_121 | V_120 ;
V_113 |= V_128 | V_119 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_11 , V_97 ) ;
return - V_42 ;
}
V_26 -> V_97 = V_97 ;
if ( V_97 == V_118 ||
V_97 == V_127 ) {
V_116 = V_129 ;
V_115 = 0 ;
V_26 -> V_104 = 4000000 ;
} else {
V_116 = 0 ;
V_115 = V_129 ;
V_26 -> V_104 = 8000000 ;
}
if ( V_97 == V_127 )
V_26 -> V_98 = V_130 ;
else if ( V_97 != 0 )
V_26 -> V_98 = V_131 ;
if ( V_96 ) {
F_29 ( & V_2 -> V_16 , L_12 ) ;
V_113 |= V_132 ;
V_26 -> V_104 /= 2 ;
} else {
F_29 ( & V_2 -> V_16 , L_13 ) ;
V_114 |= V_132 ;
}
V_26 -> V_96 = V_96 ;
if ( V_110 ) {
if ( V_110 -> V_133 == 8000000 ) {
F_29 ( & V_2 -> V_16 , L_14 ) ;
V_117 = V_134 ;
} else if ( V_110 -> V_133 == 12000000 ) {
F_29 ( & V_2 -> V_16 , L_15 ) ;
V_117 = V_135 ;
} else if ( V_110 -> V_133 == 16000000 ) {
F_29 ( & V_2 -> V_16 , L_16 ) ;
V_117 = V_136 ;
} else if ( V_110 -> V_133 == 24000000 ) {
F_29 ( & V_2 -> V_16 , L_17 ) ;
V_117 = V_137 ;
} else {
F_3 ( & V_2 -> V_16 ,
L_18 ) ;
return - V_42 ;
}
V_112 = V_110 -> V_133 ;
V_26 -> V_103 = V_110 -> V_138 ;
} else {
V_117 = V_137 ;
V_112 = 24000000 ;
V_26 -> V_103 = 0 ;
F_29 ( & V_2 -> V_16 , L_19 ) ;
}
V_117 |= F_26 ( & V_26 -> V_139 , V_26 -> V_103 , V_26 -> V_104 ) ;
V_105 = V_26 -> V_104 / F_30 ( V_117 ) ;
F_29 ( & V_2 -> V_16 , L_20 ,
V_112 / V_105 , 10 * V_112 % V_105 / V_105 ) ;
V_5 = F_20 ( V_22 , & V_71 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_140 , V_113 , V_114 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_141 , V_117 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_142 , V_115 , V_116 ) ;
if ( ! V_5 ) {
V_95 -> V_98 = V_26 -> V_98 ;
V_95 -> V_77 = V_26 -> V_74 . V_77 >> V_96 ;
V_95 -> V_79 = V_26 -> V_74 . V_79 >> V_96 ;
}
return V_5 ;
}
static int F_31 ( struct V_21 * V_22 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( F_25 ( V_95 -> V_77 , V_95 -> V_79 , & V_26 -> V_74 ) )
F_32 ( & V_95 -> V_77 , 2 , V_81 , 1 ,
& V_95 -> V_79 , 2 , V_83 , 1 , 0 ) ;
V_95 -> V_99 = V_100 ;
switch ( V_95 -> V_97 ) {
case V_143 :
V_95 -> V_97 = V_118 ;
case V_118 :
case V_124 :
case V_123 :
case V_126 :
case V_125 :
V_95 -> V_98 = V_131 ;
break;
default:
V_95 -> V_97 = V_127 ;
case V_127 :
V_95 -> V_98 = V_130 ;
break;
}
return 0 ;
}
static int F_33 ( struct V_21 * V_22 , unsigned int V_144 ,
enum V_111 * V_97 )
{
if ( V_144 >= F_34 ( V_145 ) )
return - V_42 ;
* V_97 = V_145 [ V_144 ] ;
return 0 ;
}
static int F_35 ( struct V_21 * V_22 , struct V_146 * V_147 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_148 * V_149 = & V_147 -> V_150 . V_151 ;
if ( V_147 -> type != V_72 )
return - V_42 ;
memset ( V_149 , 0 , sizeof( * V_149 ) ) ;
V_149 -> V_152 = V_153 ;
V_149 -> V_102 . V_92 = F_30 ( F_26 ( & V_26 -> V_139 ,
V_26 -> V_103 , V_26 -> V_104 ) ) ;
V_149 -> V_102 . V_93 = V_106 ;
F_29 ( & V_2 -> V_16 , L_21 ,
V_149 -> V_102 . V_92 , V_149 -> V_102 . V_93 ) ;
return 0 ;
}
static int F_36 ( struct V_21 * V_22 , struct V_146 * V_147 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_148 * V_149 = & V_147 -> V_150 . V_151 ;
struct V_101 * V_139 = & V_149 -> V_102 ;
int div , V_5 ;
T_1 V_117 ;
if ( V_147 -> type != V_72 )
return - V_42 ;
if ( V_149 -> V_154 != 0 )
return - V_42 ;
if ( V_139 -> V_92 == 0 || V_139 -> V_93 == 0 )
div = 1 ;
else
div = ( V_139 -> V_92 * V_106 ) / V_139 -> V_93 ;
if ( div == 0 )
div = 1 ;
else if ( div > F_30 ( V_155 ) )
div = F_30 ( V_155 ) ;
V_26 -> V_139 . V_92 = div ;
V_26 -> V_139 . V_93 = V_106 ;
V_117 = F_26 ( & V_26 -> V_139 , V_26 -> V_103 , V_26 -> V_104 ) ;
V_5 = F_6 ( V_2 , V_141 , V_117 , V_155 ) ;
if ( ! V_5 ) {
V_139 -> V_92 = F_30 ( V_117 ) ;
V_139 -> V_93 = V_106 ;
}
return V_5 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_5 ;
F_29 ( & V_2 -> V_16 , L_22 ) ;
V_5 = F_6 ( V_2 , V_140 , V_156 , 0 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_23 ) ;
return V_5 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_5 ;
F_29 ( & V_2 -> V_16 , L_24 ) ;
V_5 = F_4 ( V_2 , V_140 , 0 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_43 , 0 , V_157 ) ;
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 )
{
T_1 V_158 , V_159 , V_160 , V_161 ;
int V_5 = 0 ;
V_5 = F_1 ( V_2 , V_162 , & V_158 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_163 , & V_159 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_164 , & V_160 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_165 , & V_161 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_158 != V_166 ) || ( V_159 != V_167 ) ) {
F_3 ( & V_2 -> V_16 , L_25 ,
V_158 , V_159 ) ;
return - V_168 ;
}
F_40 ( & V_2 -> V_16 ,
L_26 ,
V_158 , V_159 , V_160 , V_161 ) ;
V_5 = F_37 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_38 ( V_2 ) ;
return V_5 ;
}
static int F_41 ( struct V_21 * V_22 ,
struct V_169 * V_170 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_171 * V_172 = F_42 ( V_2 ) ;
V_170 -> V_10 = V_173 |
V_174 | V_175 |
V_176 | V_177 |
V_178 | V_179 |
V_180 ;
V_170 -> type = V_181 ;
V_170 -> V_10 = F_43 ( V_172 , V_170 ) ;
return 0 ;
}
static int F_44 ( struct V_21 * V_22 ,
const struct V_169 * V_170 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_171 * V_172 = F_42 ( V_2 ) ;
unsigned long V_10 = F_43 ( V_172 , V_170 ) ;
int V_5 ;
if ( V_10 & V_174 )
V_5 = F_6 ( V_2 , V_182 , V_183 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_182 , 0 , V_183 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_177 )
V_5 = F_6 ( V_2 , V_184 , V_185 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_184 , 0 , V_185 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_178 )
V_5 = F_6 ( V_2 , V_182 , V_186 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_182 , 0 , V_186 ) ;
return V_5 ;
}
static int F_45 ( struct V_1 * V_2 ,
const struct V_187 * V_188 )
{
struct V_19 * V_26 ;
struct V_171 * V_172 = F_42 ( V_2 ) ;
int V_5 ;
if ( ! V_172 ) {
F_3 ( & V_2 -> V_16 , L_27 ) ;
return - V_42 ;
}
V_26 = F_46 ( sizeof( * V_26 ) , V_189 ) ;
if ( ! V_26 ) {
F_3 ( & V_2 -> V_16 ,
L_28 ) ;
return - V_190 ;
}
F_47 ( & V_26 -> V_20 , V_2 , & V_191 ) ;
F_48 ( & V_26 -> V_28 , 13 ) ;
F_49 ( & V_26 -> V_28 , & V_192 ,
V_59 , 0 , 1 , 1 , 0 ) ;
F_49 ( & V_26 -> V_28 , & V_192 ,
V_61 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_193 = F_49 ( & V_26 -> V_28 , & V_192 ,
V_31 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_33 = F_49 ( & V_26 -> V_28 , & V_192 ,
V_194 , 0 , 0x3f , 1 , V_195 ) ;
V_26 -> V_196 = F_49 ( & V_26 -> V_28 , & V_192 ,
V_34 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_37 = F_49 ( & V_26 -> V_28 , & V_192 ,
V_197 , 0 , 0xff , 1 , V_198 ) ;
V_26 -> V_38 = F_49 ( & V_26 -> V_28 , & V_192 ,
V_199 , 0 , 0xff , 1 , V_200 ) ;
F_49 ( & V_26 -> V_28 , & V_192 ,
V_46 , 0 , 0xf , 1 , 0x8 ) ;
F_49 ( & V_26 -> V_28 , & V_192 ,
V_49 , 0 , V_51 , 1 , V_201 ) ;
F_49 ( & V_26 -> V_28 , & V_192 ,
V_52 , 0 , 0xff , 1 , 0x80 ) ;
V_26 -> V_202 = F_50 ( & V_26 -> V_28 ,
& V_192 , V_39 ,
V_56 , 0 , V_54 ) ;
V_26 -> V_41 = F_49 ( & V_26 -> V_28 , & V_192 ,
V_203 , 0 , 0xff , 1 , V_204 ) ;
F_49 ( & V_26 -> V_28 , & V_192 ,
V_57 , 0 , 0xff , 1 , 0x12 ) ;
V_26 -> V_20 . V_205 = & V_26 -> V_28 ;
if ( V_26 -> V_28 . error ) {
int V_14 = V_26 -> V_28 . error ;
F_51 ( V_26 ) ;
return V_14 ;
}
F_52 ( 2 , & V_26 -> V_193 , 0 , true ) ;
F_52 ( 3 , & V_26 -> V_196 , 0 , true ) ;
F_52 ( 2 , & V_26 -> V_202 ,
V_56 , true ) ;
V_26 -> V_74 . V_76 = V_80 << 1 ;
V_26 -> V_74 . V_78 = V_82 << 1 ;
V_26 -> V_74 . V_77 = V_81 ;
V_26 -> V_74 . V_79 = V_83 ;
V_26 -> V_96 = false ;
V_26 -> V_97 = V_123 ;
V_26 -> V_98 = V_131 ;
V_5 = F_39 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_53 ( & V_26 -> V_28 ) ;
if ( V_5 ) {
F_54 ( & V_26 -> V_28 ) ;
F_51 ( V_26 ) ;
}
return V_5 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_19 * V_26 = F_7 ( V_2 ) ;
F_56 ( & V_26 -> V_20 ) ;
F_54 ( & V_26 -> V_28 ) ;
F_51 ( V_26 ) ;
return 0 ;
}
static int T_3 F_57 ( void )
{
return F_58 ( & V_206 ) ;
}
static void T_4 F_59 ( void )
{
F_60 ( & V_206 ) ;
}
