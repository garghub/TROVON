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
static int F_11 ( struct V_24 * V_25 ,
unsigned long V_10 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
struct V_1 * V_2 = F_13 ( F_14 ( V_25 ) ) ;
int V_5 ;
V_10 = F_15 ( V_27 , V_10 ) ;
if ( V_10 & V_28 )
V_5 = F_6 ( V_2 , V_29 , V_30 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_29 , 0 , V_30 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_31 )
V_5 = F_6 ( V_2 , V_32 , V_33 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_32 , 0 , V_33 ) ;
if ( V_5 )
return V_5 ;
if ( V_10 & V_34 )
V_5 = F_6 ( V_2 , V_29 , V_35 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_29 , 0 , V_35 ) ;
return V_5 ;
}
static unsigned long F_16 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_12 ( V_25 ) ;
unsigned long V_10 = V_36 |
V_28 | V_37 |
V_38 | V_31 |
V_34 | V_39 |
V_40 | V_41 ;
return F_15 ( V_27 , V_10 ) ;
}
static int F_17 ( struct V_21 * V_22 , struct V_42 * V_43 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
T_2 V_3 ;
int V_5 = 0 ;
switch ( V_43 -> V_45 ) {
case V_46 :
V_43 -> V_47 = V_44 -> V_48 ;
break;
case V_49 :
if ( V_44 -> V_48 ) {
V_5 = F_1 ( V_2 , V_50 , & V_3 ) ;
V_43 -> V_47 = V_3 ;
} else {
V_43 -> V_47 = V_44 -> V_51 ;
}
break;
case V_52 :
V_43 -> V_47 = V_44 -> V_53 ;
break;
case V_54 :
if ( V_44 -> V_53 ) {
V_5 = F_1 ( V_2 , V_55 , & V_3 ) ;
V_43 -> V_47 = V_3 ;
} else {
V_43 -> V_47 = V_44 -> V_56 ;
}
break;
case V_57 :
if ( V_44 -> V_53 ) {
V_5 = F_1 ( V_2 , V_58 , & V_3 ) ;
V_43 -> V_47 = V_3 ;
} else {
V_43 -> V_47 = V_44 -> V_59 ;
}
break;
case V_60 :
V_43 -> V_47 = V_44 -> V_61 ;
break;
case V_62 :
V_43 -> V_47 = V_44 -> V_63 ;
break;
case V_64 :
V_43 -> V_47 = V_44 -> V_65 ;
break;
case V_66 :
V_43 -> V_47 = V_44 -> V_67 ;
break;
case V_68 :
if ( V_44 -> V_67 ) {
V_5 = F_1 ( V_2 , V_69 , & V_3 ) ;
V_43 -> V_47 = V_3 ;
} else {
V_43 -> V_47 = V_44 -> V_70 ;
}
break;
case V_71 :
V_43 -> V_47 = V_44 -> gamma ;
break;
case V_72 :
V_43 -> V_47 = V_44 -> V_73 ;
break;
case V_74 :
V_43 -> V_47 = V_44 -> V_75 ;
break;
}
return V_5 ;
}
static int F_19 ( struct V_21 * V_22 , struct V_42 * V_43 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
int V_5 = 0 ;
switch ( V_43 -> V_45 ) {
case V_46 :
V_5 = F_6 ( V_2 , V_76 ,
V_43 -> V_47 ? V_77 : 0 , V_77 ) ;
if ( ! V_5 )
V_44 -> V_48 = V_43 -> V_47 ;
break;
case V_49 :
V_5 = F_4 ( V_2 , V_50 , V_43 -> V_47 ) ;
if ( ! V_5 )
V_44 -> V_51 = V_43 -> V_47 ;
break;
case V_52 :
V_5 = F_6 ( V_2 , V_76 ,
V_43 -> V_47 ? V_78 : 0 , V_78 ) ;
if ( ! V_5 )
V_44 -> V_53 = V_43 -> V_47 ;
break;
case V_54 :
V_5 = F_4 ( V_2 , V_55 , V_43 -> V_47 ) ;
if ( ! V_5 )
V_44 -> V_56 = V_43 -> V_47 ;
break;
case V_57 :
V_5 = F_4 ( V_2 , V_58 , V_43 -> V_47 ) ;
if ( ! V_5 )
V_44 -> V_59 = V_43 -> V_47 ;
break;
case V_60 :
V_5 = F_6 ( V_2 , V_79 , F_20 ( V_43 -> V_47 ) ,
V_80 ) ;
if ( ! V_5 )
V_44 -> V_61 = V_43 -> V_47 ;
break;
case V_62 :
V_5 = F_6 ( V_2 , V_81 , F_21 ( V_43 -> V_47 ) ,
V_82 ) ;
if ( ! V_5 )
V_44 -> V_63 = V_43 -> V_47 ;
break;
case V_64 :
V_5 = F_4 ( V_2 , V_83 , V_43 -> V_47 ) ;
if ( ! V_5 )
V_44 -> V_65 = V_43 -> V_47 ;
break;
case V_66 :
switch ( V_43 -> V_47 ) {
case V_84 :
V_5 = F_6 ( V_2 , V_76 , V_85 , 0 ) ;
break;
default:
V_5 = F_6 ( V_2 , V_76 , 0 , V_85 ) ;
break;
}
if ( ! V_5 )
V_44 -> V_67 = V_43 -> V_47 ;
break;
case V_68 :
V_5 = F_4 ( V_2 , V_69 , V_43 -> V_47 ) ;
if ( ! V_5 )
V_44 -> V_70 = V_43 -> V_47 ;
break;
case V_71 :
V_5 = F_4 ( V_2 , V_86 , V_43 -> V_47 ) ;
if ( ! V_5 )
V_44 -> gamma = V_43 -> V_47 ;
break;
case V_72 :
V_5 = F_6 ( V_2 , V_76 ,
V_43 -> V_47 ? V_87 : 0 , V_87 ) ;
if ( ! V_5 )
V_44 -> V_73 = V_43 -> V_47 ;
break;
case V_74 :
V_5 = F_6 ( V_2 , V_76 ,
V_43 -> V_47 ? V_88 : 0 , V_88 ) ;
if ( ! V_5 )
V_44 -> V_75 = V_43 -> V_47 ;
break;
}
return V_5 ;
}
static int F_22 ( struct V_21 * V_22 ,
struct V_89 * V_45 )
{
V_45 -> V_90 = V_91 ;
V_45 -> V_92 = 0 ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 ,
struct V_93 * V_3 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
int V_5 ;
T_1 V_4 ;
if ( V_3 -> V_3 & ~ 0xff )
return - V_94 ;
V_3 -> V_95 = 1 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( ! V_5 )
V_3 -> V_4 = ( V_96 ) V_4 ;
return V_5 ;
}
static int F_24 ( struct V_21 * V_22 ,
struct V_93 * V_3 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
if ( V_3 -> V_3 & ~ 0xff || V_3 -> V_4 & ~ 0xff )
return - V_94 ;
return F_4 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static int F_25 ( struct V_21 * V_22 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
V_98 -> type = V_99 ;
V_98 -> V_100 = V_44 -> V_101 ;
return 0 ;
}
static int F_26 ( struct V_21 * V_22 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
struct V_102 * V_101 = & V_98 -> V_100 ;
int V_5 ;
if ( V_98 -> type != V_99 )
return - V_94 ;
V_101 -> V_103 = F_27 ( V_101 -> V_103 , 2 ) ;
V_101 -> V_104 = F_27 ( V_101 -> V_104 , 2 ) ;
V_101 -> V_105 = F_27 ( V_101 -> V_105 , 2 ) ;
V_101 -> V_106 = F_27 ( V_101 -> V_106 , 2 ) ;
F_28 ( & V_101 -> V_103 , & V_101 -> V_104 ,
V_107 << 1 , 2 , V_108 ) ;
F_28 ( & V_101 -> V_105 , & V_101 -> V_106 ,
V_109 << 1 , 2 , V_110 ) ;
V_5 = F_4 ( V_2 , V_111 , V_101 -> V_103 >> 1 ) ;
if ( ! V_5 ) {
V_44 -> V_101 . V_103 = V_101 -> V_103 ;
V_5 = F_4 ( V_2 , V_112 ,
( V_101 -> V_103 + V_101 -> V_104 ) >> 1 ) ;
}
if ( ! V_5 ) {
V_44 -> V_101 . V_104 = V_101 -> V_104 ;
V_5 = F_4 ( V_2 , V_113 , V_101 -> V_105 >> 1 ) ;
}
if ( ! V_5 ) {
V_44 -> V_101 . V_105 = V_101 -> V_105 ;
V_5 = F_4 ( V_2 , V_114 ,
( V_101 -> V_105 + V_101 -> V_106 ) >> 1 ) ;
}
if ( ! V_5 )
V_44 -> V_101 . V_106 = V_101 -> V_106 ;
return V_5 ;
}
static int F_29 ( struct V_21 * V_22 , struct V_115 * V_98 )
{
if ( V_98 -> type != V_99 )
return - V_94 ;
V_98 -> V_116 . V_103 = V_107 << 1 ;
V_98 -> V_116 . V_105 = V_109 << 1 ;
V_98 -> V_116 . V_104 = V_108 ;
V_98 -> V_116 . V_106 = V_110 ;
V_98 -> V_117 = V_98 -> V_116 ;
V_98 -> V_118 . V_119 = 1 ;
V_98 -> V_118 . V_120 = 1 ;
return 0 ;
}
static int F_30 ( struct V_21 * V_22 ,
struct V_121 * V_122 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
V_122 -> V_104 = V_44 -> V_101 . V_104 >> V_44 -> V_123 ;
V_122 -> V_106 = V_44 -> V_101 . V_106 >> V_44 -> V_123 ;
V_122 -> V_124 = V_44 -> V_124 ;
V_122 -> V_125 = V_44 -> V_125 ;
V_122 -> V_126 = V_127 ;
return 0 ;
}
static bool F_31 ( int V_104 , int V_106 , struct V_102 * V_101 )
{
return V_104 > V_101 -> V_104 >> 1 || V_106 > V_101 -> V_106 >> 1 ;
}
static T_1 F_32 ( struct V_128 * V_129 ,
unsigned long V_130 , unsigned long V_131 )
{
unsigned long V_132 ;
if ( V_129 -> V_119 && V_129 -> V_120 )
V_132 = V_131 * V_129 -> V_120 /
( V_133 * V_129 -> V_119 ) ;
else
V_132 = V_131 ;
if ( V_130 && V_130 < V_132 )
V_132 = V_130 ;
return ( V_131 - 1 ) / V_132 ;
}
static int F_33 ( struct V_21 * V_22 , struct V_121 * V_122 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_24 * V_25 = V_2 -> V_16 . V_134 ;
struct V_135 * V_136 = V_25 -> V_136 ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
bool V_123 = ! F_31 ( V_122 -> V_104 , V_122 -> V_106 , & V_44 -> V_101 ) ;
struct V_97 V_98 = {
. type = V_99 ,
. V_100 = {
. V_103 = V_44 -> V_101 . V_103 + ( V_44 -> V_101 . V_104 >> 1 ) -
( V_122 -> V_104 >> ( 1 - V_123 ) ) ,
. V_105 = V_44 -> V_101 . V_105 + ( V_44 -> V_101 . V_106 >> 1 ) -
( V_122 -> V_106 >> ( 1 - V_123 ) ) ,
. V_104 = V_122 -> V_104 << V_123 ,
. V_106 = V_122 -> V_106 << V_123 ,
} ,
} ;
enum V_137 V_124 = V_122 -> V_124 ;
unsigned long V_138 , V_132 ;
T_1 V_139 = 0 , V_140 = 0 , V_141 , V_142 , V_143 ;
int V_5 ;
switch ( V_124 ) {
case V_144 :
F_34 ( & V_2 -> V_16 , L_5 ) ;
V_140 |= V_145 | V_146 | V_147 ;
V_139 |= V_148 ;
break;
case V_149 :
F_34 ( & V_2 -> V_16 , L_6 ) ;
V_140 |= V_145 | V_148 | V_147 ;
V_139 |= V_146 ;
break;
case V_150 :
F_34 ( & V_2 -> V_16 , L_7 ) ;
V_140 |= V_145 | V_148 | V_146 |
V_147 ;
break;
case V_151 :
F_34 ( & V_2 -> V_16 , L_8 ) ;
if ( V_123 ) {
V_140 |= V_145 | V_148 | V_146 ;
V_139 |= V_147 ;
} else {
V_140 |= V_145 | V_148 ;
V_139 |= V_147 | V_146 ;
}
break;
case V_152 :
F_34 ( & V_2 -> V_16 , L_9 ) ;
if ( V_123 ) {
V_140 |= V_145 | V_148 ;
V_139 |= V_147 | V_146 ;
} else {
V_140 |= V_145 | V_148 | V_146 ;
V_139 |= V_147 ;
}
break;
case V_153 :
F_34 ( & V_2 -> V_16 , L_10 ) ;
V_140 |= V_148 | V_147 | V_146 ;
V_139 |= V_154 | V_145 ;
break;
default:
F_3 ( & V_2 -> V_16 , L_11 , V_124 ) ;
return - V_94 ;
}
V_44 -> V_124 = V_124 ;
if ( V_124 == V_144 ||
V_124 == V_153 ) {
V_142 = V_155 ;
V_141 = 0 ;
V_44 -> V_131 = 4000000 ;
} else {
V_142 = 0 ;
V_141 = V_155 ;
V_44 -> V_131 = 8000000 ;
}
if ( V_124 == V_153 )
V_44 -> V_125 = V_156 ;
else if ( V_124 != 0 )
V_44 -> V_125 = V_157 ;
if ( V_123 ) {
F_34 ( & V_2 -> V_16 , L_12 ) ;
V_139 |= V_158 ;
V_44 -> V_131 /= 2 ;
} else {
F_34 ( & V_2 -> V_16 , L_13 ) ;
V_140 |= V_158 ;
}
V_44 -> V_123 = V_123 ;
if ( V_136 ) {
if ( V_136 -> V_159 == 8000000 ) {
F_34 ( & V_2 -> V_16 , L_14 ) ;
V_143 = V_160 ;
} else if ( V_136 -> V_159 == 12000000 ) {
F_34 ( & V_2 -> V_16 , L_15 ) ;
V_143 = V_161 ;
} else if ( V_136 -> V_159 == 16000000 ) {
F_34 ( & V_2 -> V_16 , L_16 ) ;
V_143 = V_162 ;
} else if ( V_136 -> V_159 == 24000000 ) {
F_34 ( & V_2 -> V_16 , L_17 ) ;
V_143 = V_163 ;
} else {
F_3 ( & V_2 -> V_16 ,
L_18 ) ;
return - V_94 ;
}
V_138 = V_136 -> V_159 ;
V_44 -> V_130 = V_136 -> V_164 ;
} else {
V_143 = V_163 ;
V_138 = 24000000 ;
V_44 -> V_130 = 0 ;
F_34 ( & V_2 -> V_16 , L_19 ) ;
}
V_143 |= F_32 ( & V_44 -> V_165 , V_44 -> V_130 , V_44 -> V_131 ) ;
V_132 = V_44 -> V_131 / F_35 ( V_143 ) ;
F_34 ( & V_2 -> V_16 , L_20 ,
V_138 / V_132 , 10 * V_138 % V_132 / V_132 ) ;
V_5 = F_26 ( V_22 , & V_98 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_166 , V_139 , V_140 ) ;
if ( ! V_5 )
V_5 = F_4 ( V_2 , V_167 , V_143 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_168 , V_141 , V_142 ) ;
if ( ! V_5 ) {
V_122 -> V_125 = V_44 -> V_125 ;
V_122 -> V_104 = V_44 -> V_101 . V_104 >> V_123 ;
V_122 -> V_106 = V_44 -> V_101 . V_106 >> V_123 ;
}
return V_5 ;
}
static int F_36 ( struct V_21 * V_22 ,
struct V_121 * V_122 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
if ( F_31 ( V_122 -> V_104 , V_122 -> V_106 , & V_44 -> V_101 ) )
F_37 ( & V_122 -> V_104 , 2 , V_108 , 1 ,
& V_122 -> V_106 , 2 , V_110 , 1 , 0 ) ;
V_122 -> V_126 = V_127 ;
switch ( V_122 -> V_124 ) {
case V_169 :
V_122 -> V_124 = V_144 ;
case V_144 :
case V_150 :
case V_149 :
case V_152 :
case V_151 :
V_122 -> V_125 = V_157 ;
break;
default:
V_122 -> V_124 = V_153 ;
case V_153 :
V_122 -> V_125 = V_156 ;
break;
}
return 0 ;
}
static int F_38 ( struct V_21 * V_22 , unsigned int V_170 ,
enum V_137 * V_124 )
{
if ( V_170 >= F_39 ( V_171 ) )
return - V_94 ;
* V_124 = V_171 [ V_170 ] ;
return 0 ;
}
static int F_40 ( struct V_21 * V_22 , struct V_172 * V_173 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
struct V_174 * V_175 = & V_173 -> V_176 . V_177 ;
if ( V_173 -> type != V_99 )
return - V_94 ;
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_178 = V_179 ;
V_175 -> V_129 . V_119 = F_35 ( F_32 ( & V_44 -> V_165 ,
V_44 -> V_130 , V_44 -> V_131 ) ) ;
V_175 -> V_129 . V_120 = V_133 ;
F_34 ( & V_2 -> V_16 , L_21 ,
V_175 -> V_129 . V_119 , V_175 -> V_129 . V_120 ) ;
return 0 ;
}
static int F_41 ( struct V_21 * V_22 , struct V_172 * V_173 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
struct V_19 * V_44 = F_7 ( V_2 ) ;
struct V_174 * V_175 = & V_173 -> V_176 . V_177 ;
struct V_128 * V_165 = & V_175 -> V_129 ;
int div , V_5 ;
T_1 V_143 ;
if ( V_173 -> type != V_99 )
return - V_94 ;
if ( V_175 -> V_180 != 0 )
return - V_94 ;
if ( V_165 -> V_119 == 0 || V_165 -> V_120 == 0 )
div = 1 ;
else
div = ( V_165 -> V_119 * V_133 ) / V_165 -> V_120 ;
if ( div == 0 )
div = 1 ;
else if ( div > F_35 ( V_181 ) )
div = F_35 ( V_181 ) ;
V_44 -> V_165 . V_119 = div ;
V_44 -> V_165 . V_120 = V_133 ;
V_143 = F_32 ( & V_44 -> V_165 , V_44 -> V_130 , V_44 -> V_131 ) ;
V_5 = F_6 ( V_2 , V_167 , V_143 , V_181 ) ;
if ( ! V_5 ) {
V_165 -> V_119 = F_35 ( V_143 ) ;
V_165 -> V_120 = V_133 ;
}
return V_5 ;
}
static int F_42 ( struct V_1 * V_2 )
{
int V_5 ;
F_34 ( & V_2 -> V_16 , L_22 ) ;
V_5 = F_6 ( V_2 , V_166 , V_182 , 0 ) ;
if ( V_5 )
F_3 ( & V_2 -> V_16 ,
L_23 ) ;
return V_5 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_5 ;
F_34 ( & V_2 -> V_16 , L_24 ) ;
V_5 = F_4 ( V_2 , V_166 , 0 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_2 , V_76 , 0 , V_183 ) ;
return V_5 ;
}
static int F_44 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
T_1 V_184 , V_185 , V_186 , V_187 ;
int V_5 = 0 ;
V_5 = F_1 ( V_2 , V_188 , & V_184 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_189 , & V_185 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_190 , & V_186 ) ;
if ( ! V_5 )
V_5 = F_1 ( V_2 , V_191 , & V_187 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_184 != V_192 ) || ( V_185 != V_193 ) ) {
F_3 ( & V_2 -> V_16 , L_25 ,
V_184 , V_185 ) ;
return - V_194 ;
}
F_45 ( & V_2 -> V_16 ,
L_26 ,
V_184 , V_185 , V_186 , V_187 ) ;
V_5 = F_42 ( V_2 ) ;
if ( ! V_5 )
V_5 = F_43 ( V_2 ) ;
return V_5 ;
}
static int F_46 ( struct V_1 * V_2 ,
const struct V_195 * V_196 )
{
struct V_19 * V_44 ;
struct V_24 * V_25 = V_2 -> V_16 . V_134 ;
struct V_26 * V_27 ;
int V_5 ;
if ( ! V_25 ) {
F_3 ( & V_2 -> V_16 , L_27 ) ;
return - V_94 ;
}
V_27 = F_12 ( V_25 ) ;
if ( ! V_27 ) {
F_3 ( & V_2 -> V_16 , L_28 ) ;
return - V_94 ;
}
V_44 = F_47 ( sizeof( * V_44 ) , V_197 ) ;
if ( ! V_44 ) {
F_3 ( & V_2 -> V_16 ,
L_29 ) ;
return - V_198 ;
}
F_48 ( & V_44 -> V_20 , V_2 , & V_199 ) ;
V_25 -> V_200 = & V_201 ;
V_44 -> V_101 . V_103 = V_107 << 1 ;
V_44 -> V_101 . V_105 = V_109 << 1 ;
V_44 -> V_101 . V_104 = V_108 ;
V_44 -> V_101 . V_106 = V_110 ;
V_44 -> V_123 = false ;
V_44 -> V_124 = V_149 ;
V_44 -> V_125 = V_157 ;
V_5 = F_44 ( V_25 , V_2 ) ;
if ( V_5 ) {
V_25 -> V_200 = NULL ;
F_49 ( V_44 ) ;
}
return V_5 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_19 * V_44 = F_7 ( V_2 ) ;
F_49 ( V_44 ) ;
return 0 ;
}
static int T_3 F_51 ( void )
{
return F_52 ( & V_202 ) ;
}
static void T_4 F_53 ( void )
{
F_54 ( & V_202 ) ;
}
