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
struct V_94 * V_95 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = & V_97 -> V_97 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_97 -> V_100 )
return - V_42 ;
V_99 -> V_77 = V_26 -> V_74 . V_77 >> V_26 -> V_101 ;
V_99 -> V_79 = V_26 -> V_74 . V_79 >> V_26 -> V_101 ;
V_99 -> V_102 = V_26 -> V_102 ;
V_99 -> V_103 = V_26 -> V_103 ;
V_99 -> V_104 = V_105 ;
return 0 ;
}
static bool F_27 ( int V_77 , int V_79 , struct V_75 * V_74 )
{
return V_77 > V_74 -> V_77 >> 1 || V_79 > V_74 -> V_79 >> 1 ;
}
static T_1 F_28 ( struct V_106 * V_107 ,
unsigned long V_108 , unsigned long V_109 )
{
unsigned long V_110 ;
if ( V_107 -> V_92 && V_107 -> V_93 )
V_110 = V_109 * V_107 -> V_93 /
( V_111 * V_107 -> V_92 ) ;
else
V_110 = V_109 ;
if ( V_108 && V_108 < V_110 )
V_110 = V_108 ;
return ( V_109 - 1 ) / V_110 ;
}
static int F_29 ( struct V_21 * V_22 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_112 * V_113 = F_30 ( V_22 ) ;
struct V_114 * V_115 = V_113 -> V_115 ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
bool V_101 = ! F_27 ( V_99 -> V_77 , V_99 -> V_79 , & V_26 -> V_74 ) ;
struct V_70 V_71 = {
. type = V_72 ,
. V_73 = {
. V_76 = V_26 -> V_74 . V_76 + ( V_26 -> V_74 . V_77 >> 1 ) -
( V_99 -> V_77 >> ( 1 - V_101 ) ) ,
. V_78 = V_26 -> V_74 . V_78 + ( V_26 -> V_74 . V_79 >> 1 ) -
( V_99 -> V_79 >> ( 1 - V_101 ) ) ,
. V_77 = V_99 -> V_77 << V_101 ,
. V_79 = V_99 -> V_79 << V_101 ,
} ,
} ;
T_3 V_102 = V_99 -> V_102 ;
unsigned long V_116 , V_110 ;
T_1 V_117 = 0 , V_118 = 0 , V_119 , V_120 , V_121 ;
int V_5 ;
switch ( V_102 ) {
case V_122 :
F_31 ( & V_2 -> V_16 , L_5 ) ;
V_118 |= V_123 | V_124 | V_125 ;
V_117 |= V_126 ;
break;
case V_127 :
F_31 ( & V_2 -> V_16 , L_6 ) ;
V_118 |= V_123 | V_126 | V_125 ;
V_117 |= V_124 ;
break;
case V_128 :
F_31 ( & V_2 -> V_16 , L_7 ) ;
V_118 |= V_123 | V_126 | V_124 |
V_125 ;
break;
case V_129 :
F_31 ( & V_2 -> V_16 , L_8 ) ;
if ( V_101 ) {
V_118 |= V_123 | V_126 | V_124 ;
V_117 |= V_125 ;
} else {
V_118 |= V_123 | V_126 ;
V_117 |= V_125 | V_124 ;
}
break;
case V_130 :
F_31 ( & V_2 -> V_16 , L_9 ) ;
if ( V_101 ) {
V_118 |= V_123 | V_126 ;
V_117 |= V_125 | V_124 ;
} else {
V_118 |= V_123 | V_126 | V_124 ;
V_117 |= V_125 ;
}
break;
case V_131 :
F_31 ( & V_2 -> V_16 , L_10 ) ;
V_118 |= V_126 | V_125 | V_124 ;
V_117 |= V_132 | V_123 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_11 , V_102 ) ;
return - V_42 ;
}
V_26 -> V_102 = V_102 ;
if ( V_102 == V_122 ||
V_102 == V_131 ) {
V_120 = V_133 ;
V_119 = 0 ;
V_26 -> V_109 = 4000000 ;
} else {
V_120 = 0 ;
V_119 = V_133 ;
V_26 -> V_109 = 8000000 ;
}
if ( V_102 == V_131 )
V_26 -> V_103 = V_134 ;
else if ( V_102 != 0 )
V_26 -> V_103 = V_135 ;
if ( V_101 ) {
F_31 ( & V_2 -> V_16 , L_12 ) ;
V_117 |= V_136 ;
V_26 -> V_109 /= 2 ;
} else {
F_31 ( & V_2 -> V_16 , L_13 ) ;
V_118 |= V_136 ;
}
V_26 -> V_101 = V_101 ;
if ( V_115 ) {
if ( V_115 -> V_137 == 8000000 ) {
F_31 ( & V_2 -> V_16 , L_14 ) ;
V_121 = V_138 ;
} else if ( V_115 -> V_137 == 12000000 ) {
F_31 ( & V_2 -> V_16 , L_15 ) ;
V_121 = V_139 ;
} else if ( V_115 -> V_137 == 16000000 ) {
F_31 ( & V_2 -> V_16 , L_16 ) ;
V_121 = V_140 ;
} else if ( V_115 -> V_137 == 24000000 ) {
F_31 ( & V_2 -> V_16 , L_17 ) ;
V_121 = V_141 ;
} else {
F_3 ( & V_2 -> V_16 ,
L_18 ) ;
return - V_42 ;
}
V_116 = V_115 -> V_137 ;
V_26 -> V_108 = V_115 -> V_142 ;
} else {
V_121 = V_141 ;
V_116 = 24000000 ;
V_26 -> V_108 = 0 ;
F_31 ( & V_2 -> V_16 , L_19 ) ;
}
V_121 |= F_28 ( & V_26 -> V_143 , V_26 -> V_108 , V_26 -> V_109 ) ;
V_110 = V_26 -> V_109 / F_32 ( V_121 ) ;
F_31 ( & V_2 -> V_16 , L_20 ,
V_116 / V_110 , 10 * V_116 % V_110 / V_110 ) ;
V_5 = F_22 ( V_22 , & V_71 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_144 , V_117 , V_118 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_145 , V_121 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_146 , V_119 , V_120 ) ;
if ( ! V_5 ) {
V_99 -> V_103 = V_26 -> V_103 ;
V_99 -> V_77 = V_26 -> V_74 . V_77 >> V_101 ;
V_99 -> V_79 = V_26 -> V_74 . V_79 >> V_101 ;
}
return V_5 ;
}
static int F_33 ( struct V_21 * V_22 ,
struct V_94 * V_95 ,
struct V_96 * V_97 )
{
struct V_98 * V_99 = & V_97 -> V_97 ;
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
if ( V_97 -> V_100 )
return - V_42 ;
if ( F_27 ( V_99 -> V_77 , V_99 -> V_79 , & V_26 -> V_74 ) )
F_34 ( & V_99 -> V_77 , 2 , V_81 , 1 ,
& V_99 -> V_79 , 2 , V_83 , 1 , 0 ) ;
V_99 -> V_104 = V_105 ;
switch ( V_99 -> V_102 ) {
case V_147 :
V_99 -> V_102 = V_122 ;
case V_122 :
case V_128 :
case V_127 :
case V_130 :
case V_129 :
V_99 -> V_103 = V_135 ;
break;
default:
V_99 -> V_102 = V_131 ;
case V_131 :
V_99 -> V_103 = V_134 ;
break;
}
if ( V_97 -> V_148 == V_149 )
return F_29 ( V_22 , V_99 ) ;
V_95 -> V_150 = * V_99 ;
return 0 ;
}
static int F_35 ( struct V_21 * V_22 ,
struct V_94 * V_95 ,
struct V_151 * V_102 )
{
if ( V_102 -> V_100 || V_102 -> V_152 >= F_36 ( V_153 ) )
return - V_42 ;
V_102 -> V_102 = V_153 [ V_102 -> V_152 ] ;
return 0 ;
}
static int F_37 ( struct V_21 * V_22 , struct V_154 * V_155 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_156 * V_157 = & V_155 -> V_158 . V_159 ;
if ( V_155 -> type != V_72 )
return - V_42 ;
memset ( V_157 , 0 , sizeof( * V_157 ) ) ;
V_157 -> V_160 = V_161 ;
V_157 -> V_107 . V_92 = F_32 ( F_28 ( & V_26 -> V_143 ,
V_26 -> V_108 , V_26 -> V_109 ) ) ;
V_157 -> V_107 . V_93 = V_111 ;
F_31 ( & V_2 -> V_16 , L_21 ,
V_157 -> V_107 . V_92 , V_157 -> V_107 . V_93 ) ;
return 0 ;
}
static int F_38 ( struct V_21 * V_22 , struct V_154 * V_155 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_19 * V_26 = F_7 ( V_2 ) ;
struct V_156 * V_157 = & V_155 -> V_158 . V_159 ;
struct V_106 * V_143 = & V_157 -> V_107 ;
int div , V_5 ;
T_1 V_121 ;
if ( V_155 -> type != V_72 )
return - V_42 ;
if ( V_157 -> V_162 != 0 )
return - V_42 ;
if ( V_143 -> V_92 == 0 || V_143 -> V_93 == 0 )
div = 1 ;
else
div = ( V_143 -> V_92 * V_111 ) / V_143 -> V_93 ;
if ( div == 0 )
div = 1 ;
else if ( div > F_32 ( V_163 ) )
div = F_32 ( V_163 ) ;
V_26 -> V_143 . V_92 = div ;
V_26 -> V_143 . V_93 = V_111 ;
V_121 = F_28 ( & V_26 -> V_143 , V_26 -> V_108 , V_26 -> V_109 ) ;
V_5 = F_6 ( V_2 , V_145 , V_121 , V_163 ) ;
if ( ! V_5 ) {
V_143 -> V_92 = F_32 ( V_121 ) ;
V_143 -> V_93 = V_111 ;
}
return V_5 ;
}
static int F_39 ( struct V_1 * V_2 )
{
int V_5 ;
F_31 ( & V_2 -> V_16 , L_22 ) ;
V_5 = F_6 ( V_2 , V_144 , V_164 , 0 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_23 ) ;
return V_5 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_5 ;
F_31 ( & V_2 -> V_16 , L_24 ) ;
V_5 = F_4 ( V_2 , V_144 , 0 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_43 , 0 , V_165 ) ;
return V_5 ;
}
static int F_41 ( struct V_1 * V_2 )
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
F_42 ( & V_2 -> V_16 ,
L_26 ,
V_166 , V_167 , V_168 , V_169 ) ;
V_5 = F_39 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_40 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_43 ( & V_26 -> V_28 ) ;
V_174:
F_18 ( & V_26 -> V_20 , 0 ) ;
return V_5 ;
}
static int F_44 ( struct V_21 * V_22 ,
struct V_178 * V_95 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
V_95 -> V_10 = V_179 |
V_180 | V_181 |
V_182 | V_183 |
V_184 | V_185 |
V_186 ;
V_95 -> type = V_187 ;
V_95 -> V_10 = F_45 ( V_68 , V_95 ) ;
return 0 ;
}
static int F_46 ( struct V_21 * V_22 ,
const struct V_178 * V_95 )
{
struct V_1 * V_2 = F_12 ( V_22 ) ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
unsigned long V_10 = F_45 ( V_68 , V_95 ) ;
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
static int F_47 ( struct V_1 * V_2 ,
const struct V_193 * V_194 )
{
struct V_19 * V_26 ;
struct V_67 * V_68 = F_19 ( V_2 ) ;
int V_5 ;
if ( ! V_68 ) {
F_3 ( & V_2 -> V_16 , L_27 ) ;
return - V_42 ;
}
V_26 = F_48 ( & V_2 -> V_16 , sizeof( * V_26 ) , V_195 ) ;
if ( ! V_26 ) {
F_3 ( & V_2 -> V_16 ,
L_28 ) ;
return - V_196 ;
}
F_49 ( & V_26 -> V_20 , V_2 , & V_197 ) ;
F_50 ( & V_26 -> V_28 , 13 ) ;
F_51 ( & V_26 -> V_28 , & V_198 ,
V_59 , 0 , 1 , 1 , 0 ) ;
F_51 ( & V_26 -> V_28 , & V_198 ,
V_61 , 0 , 1 , 1 , 0 ) ;
V_26 -> V_199 = F_51 ( & V_26 -> V_28 , & V_198 ,
V_31 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_33 = F_51 ( & V_26 -> V_28 , & V_198 ,
V_200 , 0 , 0x3f , 1 , V_201 ) ;
V_26 -> V_202 = F_51 ( & V_26 -> V_28 , & V_198 ,
V_34 , 0 , 1 , 1 , 1 ) ;
V_26 -> V_37 = F_51 ( & V_26 -> V_28 , & V_198 ,
V_203 , 0 , 0xff , 1 , V_204 ) ;
V_26 -> V_38 = F_51 ( & V_26 -> V_28 , & V_198 ,
V_205 , 0 , 0xff , 1 , V_206 ) ;
F_51 ( & V_26 -> V_28 , & V_198 ,
V_46 , 0 , 0xf , 1 , 0x8 ) ;
F_51 ( & V_26 -> V_28 , & V_198 ,
V_49 , 0 , V_51 , 1 , V_207 ) ;
F_51 ( & V_26 -> V_28 , & V_198 ,
V_52 , 0 , 0xff , 1 , 0x80 ) ;
V_26 -> V_208 = F_52 ( & V_26 -> V_28 ,
& V_198 , V_39 ,
V_56 , 0 , V_54 ) ;
V_26 -> V_41 = F_51 ( & V_26 -> V_28 , & V_198 ,
V_209 , 0 , 0xff , 1 , V_210 ) ;
F_51 ( & V_26 -> V_28 , & V_198 ,
V_57 , 0 , 0xff , 1 , 0x12 ) ;
V_26 -> V_20 . V_211 = & V_26 -> V_28 ;
if ( V_26 -> V_28 . error )
return V_26 -> V_28 . error ;
F_53 ( 2 , & V_26 -> V_199 , 0 , true ) ;
F_53 ( 3 , & V_26 -> V_202 , 0 , true ) ;
F_53 ( 2 , & V_26 -> V_208 ,
V_56 , true ) ;
V_26 -> V_74 . V_76 = V_80 << 1 ;
V_26 -> V_74 . V_78 = V_82 << 1 ;
V_26 -> V_74 . V_77 = V_81 ;
V_26 -> V_74 . V_79 = V_83 ;
V_26 -> V_101 = false ;
V_26 -> V_102 = V_127 ;
V_26 -> V_103 = V_135 ;
V_26 -> V_69 = F_54 ( & V_2 -> V_16 , L_29 ) ;
if ( F_55 ( V_26 -> V_69 ) ) {
V_5 = F_56 ( V_26 -> V_69 ) ;
goto V_212;
}
V_5 = F_41 ( V_2 ) ;
if ( V_5 ) {
F_57 ( V_26 -> V_69 ) ;
V_212:
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
