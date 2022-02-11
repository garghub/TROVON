static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_13 :
return true ;
default:
return false ;
}
}
static int F_3 ( struct V_33 * V_34 )
{
return F_4 ( V_34 , V_13 , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
int V_35 , int V_36 , struct V_37 * V_38 )
{
T_1 V_39 ;
unsigned int V_40 , V_41 , V_42 , V_43 ;
F_6 ( V_2 , L_1 , V_35 , V_36 ) ;
V_43 = V_36 * 4 ;
if ( V_43 < 90000000 ) {
V_38 -> V_44 = 1 ;
V_43 *= 2 ;
} else {
V_38 -> V_44 = 0 ;
}
F_7 ( V_43 < 90000000 || V_43 > 100000000 ) ;
F_6 ( V_2 , L_2 , V_43 ) ;
V_41 = V_43 / V_35 ;
V_38 -> V_45 = V_41 ;
V_42 = V_43 % V_35 ;
F_6 ( V_2 , L_3 , V_42 ) ;
V_39 = V_46 * ( long long ) V_42 ;
F_8 ( V_39 , V_35 ) ;
V_40 = V_39 & 0xFFFFFFFF ;
if ( ( V_40 % 10 ) >= 5 )
V_40 += 5 ;
V_38 -> V_47 = V_40 / 10 ;
F_6 ( V_2 , L_4 , V_38 -> V_45 , V_38 -> V_47 , V_38 -> V_44 ) ;
return 0 ;
}
static int F_9 ( struct V_33 * V_34 )
{
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_50 , V_51 , V_52 ;
int V_53 = 0 ;
int V_54 = 0 ;
int V_55 = - 1 ;
struct V_37 V_38 ;
if ( V_49 -> V_56 == 0 )
V_49 -> V_56 = 8000 ;
for ( V_50 = 0 ; V_50 < F_11 ( V_57 ) ; V_50 ++ ) {
if ( V_49 -> V_56 != V_57 [ V_50 ] . V_56 )
continue;
V_55 = V_50 ;
if ( V_49 -> V_58 == V_57 [ V_50 ] . V_59 )
break;
}
if ( V_55 == - 1 ) {
F_12 ( V_34 -> V_2 , L_5 ,
V_49 -> V_56 ) ;
F_7 ( V_55 == - 1 ) ;
return - V_60 ;
}
if ( V_50 == F_11 ( V_57 ) ) {
V_53 |= V_61 ;
V_51 = F_5 ( V_34 -> V_2 , V_49 -> V_58 ,
V_57 [ V_55 ] . V_59 , & V_38 ) ;
if ( V_51 != 0 ) {
F_12 ( V_34 -> V_2 ,
L_6 ,
V_49 -> V_56 , V_49 -> V_58 ) ;
return - V_60 ;
}
F_13 ( V_34 , V_29 ,
V_62 | V_63 ,
( V_38 . V_45 << V_64 ) |
V_38 . V_47 >> 18 ) ;
F_13 ( V_34 , V_30 ,
V_65 ,
( V_38 . V_47 >> 9 ) & V_65 ) ;
F_13 ( V_34 , V_30 ,
V_66 ,
V_38 . V_47 & V_66 ) ;
if ( V_38 . V_47 )
F_13 ( V_34 , V_32 ,
V_67 , V_67 ) ;
else
F_13 ( V_34 , V_32 ,
V_67 , 0 ) ;
if ( V_38 . V_44 )
V_52 = V_68 | V_69 ;
else
V_52 = V_68 ;
F_13 ( V_34 , V_28 ,
V_68 | V_69 , V_52 ) ;
F_13 ( V_34 , V_28 ,
V_70 , V_70 ) ;
}
V_54 = V_57 [ V_55 ] . V_71 | ( V_57 [ V_55 ] . V_55 << V_72 ) ;
F_13 ( V_34 , V_8 ,
V_73 | V_74 , V_54 ) ;
F_13 ( V_34 , V_28 ,
V_61 , V_53 ) ;
return 0 ;
}
static int F_14 ( struct V_75 * V_76 ,
struct V_77 * V_78 , int V_79 )
{
struct V_33 * V_34 = V_76 -> V_34 ;
int V_51 = 0 ;
F_13 ( V_34 , V_16 ,
V_80 , 0 ) ;
F_13 ( V_34 , V_28 ,
V_68 | V_70 , 0 ) ;
switch ( V_79 ) {
case V_81 :
break;
case V_82 :
V_51 = F_9 ( V_34 ) ;
break;
default:
V_51 = - V_60 ;
break;
}
return V_51 ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_52 , V_50 , V_83 ;
if ( V_49 -> V_84 ) {
V_83 = 1 ;
for ( V_50 = 2 ; V_50 < F_11 ( V_85 ) ; V_50 ++ ) {
if ( abs ( V_85 [ V_50 ] - V_49 -> V_56 ) <
abs ( V_85 [ V_83 ] - V_49 -> V_56 ) )
V_83 = V_50 ;
}
V_52 = V_83 << V_86 ;
} else {
V_52 = 0 ;
}
F_6 ( V_34 -> V_2 , L_7 , V_52 ) ;
return F_13 ( V_34 , V_6 ,
V_87 , V_52 ) ;
}
static int F_16 ( struct V_77 * V_78 ,
struct V_88 * V_89 )
{
struct V_33 * V_34 = F_17 ( V_78 ) ;
struct V_48 * V_49 = F_10 ( V_34 ) ;
V_89 -> V_90 . V_91 . V_92 [ 0 ] = V_49 -> V_84 ;
return 0 ;
}
static int F_18 ( struct V_77 * V_78 ,
struct V_88 * V_89 )
{
struct V_33 * V_34 = F_17 ( V_78 ) ;
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_84 = V_89 -> V_90 . V_91 . V_92 [ 0 ] ;
if ( V_84 > 1 )
return - V_60 ;
V_49 -> V_84 = V_84 ;
return F_15 ( V_34 ) ;
}
static int F_19 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
struct V_97 * V_98 )
{
struct V_33 * V_34 = V_98 -> V_34 ;
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_51 ;
int V_99 ;
switch ( F_20 ( V_96 ) ) {
case 16 :
V_99 = 0 ;
break;
case 20 :
V_99 = 0x4 ;
break;
case 24 :
V_99 = 0x8 ;
break;
case 32 :
V_99 = 0xc ;
break;
default:
return - V_60 ;
}
F_13 ( V_34 , V_7 ,
V_100 , V_99 ) ;
V_49 -> V_56 = F_21 ( V_96 ) ;
F_15 ( V_34 ) ;
V_51 = F_22 ( V_34 , V_16 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_51 & V_80 ) {
F_13 ( V_34 , V_16 ,
V_80 , 0 ) ;
F_13 ( V_34 , V_28 ,
V_68 | V_70 , 0 ) ;
F_9 ( V_34 ) ;
}
return 0 ;
}
static int F_23 ( struct V_97 * V_98 , int V_101 ,
unsigned int V_102 , int V_103 )
{
struct V_33 * V_34 = V_98 -> V_34 ;
struct V_48 * V_104 = F_10 ( V_34 ) ;
int div ;
switch ( V_101 ) {
case V_105 :
if ( V_102 > 15000000 ) {
V_104 -> V_58 = V_102 /= 2 ;
div = V_106 ;
} else {
V_104 -> V_58 = V_102 ;
div = 0 ;
}
F_13 ( V_34 , V_8 ,
V_106 , div ) ;
break;
default:
return - V_60 ;
}
F_6 ( V_98 -> V_2 , L_8 , V_101 , V_102 ) ;
return 0 ;
}
static int F_24 ( struct V_97 * V_98 , unsigned int V_107 )
{
struct V_33 * V_34 = V_98 -> V_34 ;
T_2 V_108 = 0 ;
switch ( V_107 & V_109 ) {
case V_110 :
break;
case V_111 :
V_108 |= V_112 ;
break;
default:
return - V_60 ;
}
switch ( V_107 & V_113 ) {
case V_114 :
V_108 |= V_115 ;
case V_116 :
V_108 |= 0x3 ;
break;
case V_117 :
V_108 |= 0x2 ;
break;
case V_118 :
break;
case V_119 :
V_108 |= 0x1 ;
break;
default:
return - V_60 ;
}
switch ( V_107 & V_113 ) {
case V_116 :
case V_114 :
switch ( V_107 & V_120 ) {
case V_121 :
break;
case V_122 :
V_108 |= V_123 ;
break;
default:
return - V_60 ;
}
break;
case V_117 :
case V_118 :
case V_119 :
switch ( V_107 & V_120 ) {
case V_121 :
break;
case V_124 :
V_108 |= V_123 | V_115 ;
break;
case V_122 :
V_108 |= V_123 ;
break;
case V_125 :
V_108 |= V_115 ;
break;
default:
return - V_60 ;
}
break;
default:
return - V_60 ;
}
F_13 ( V_34 , V_7 ,
V_112 | V_126 | V_123 |
V_115 , V_108 ) ;
return 0 ;
}
static int F_25 ( struct V_97 * V_127 , int V_128 )
{
struct V_33 * V_34 = V_127 -> V_34 ;
int V_52 ;
if ( V_128 )
V_52 = V_129 ;
else
V_52 = 0 ;
F_13 ( V_34 , V_6 , V_129 , V_52 ) ;
return 0 ;
}
static int F_26 ( struct V_33 * V_34 ,
enum V_130 V_131 )
{
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_51 ;
switch ( V_131 ) {
case V_132 :
break;
case V_133 :
F_13 ( V_34 , V_16 ,
V_134 ,
0x1 << V_135 ) ;
F_13 ( V_34 , V_14 ,
V_136 ,
0x2 << V_137 ) ;
break;
case V_138 :
if ( V_34 -> V_139 . V_140 == V_141 ) {
V_51 = F_27 ( F_11 ( V_49 -> V_142 ) ,
V_49 -> V_142 ) ;
if ( V_51 != 0 ) {
F_12 ( V_34 -> V_2 ,
L_9 ,
V_51 ) ;
return V_51 ;
}
F_28 ( V_49 -> V_143 ) ;
F_13 ( V_34 , V_16 ,
V_144 |
V_134 ,
V_144 |
0x3 << V_145 ) ;
F_29 ( 500 ) ;
F_13 ( V_34 ,
V_18 ,
V_146 , V_146 ) ;
}
F_13 ( V_34 , V_16 ,
V_134 ,
0x2 << V_135 ) ;
F_13 ( V_34 , V_14 ,
V_136 , 0 ) ;
break;
case V_141 :
F_13 ( V_34 ,
V_18 ,
V_146 , 0 ) ;
F_13 ( V_34 , V_16 ,
V_144 |
V_134 , 0 ) ;
F_30 ( F_11 ( V_49 -> V_142 ) ,
V_49 -> V_142 ) ;
break;
}
V_34 -> V_139 . V_140 = V_131 ;
return 0 ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_48 * V_49 = F_10 ( V_34 ) ;
struct V_147 * V_148 = F_32 ( V_34 -> V_2 ) ;
int V_51 , V_50 ;
for ( V_50 = 0 ; V_50 < F_11 ( V_49 -> V_142 ) ; V_50 ++ )
V_49 -> V_142 [ V_50 ] . V_149 = V_150 [ V_50 ] ;
V_51 = F_33 ( V_34 -> V_2 , F_11 ( V_49 -> V_142 ) ,
V_49 -> V_142 ) ;
if ( V_51 != 0 ) {
F_12 ( V_34 -> V_2 , L_10 , V_51 ) ;
return V_51 ;
}
V_51 = F_27 ( F_11 ( V_49 -> V_142 ) ,
V_49 -> V_142 ) ;
if ( V_51 != 0 ) {
F_12 ( V_34 -> V_2 , L_9 , V_51 ) ;
return V_51 ;
}
V_51 = F_3 ( V_34 ) ;
if ( V_51 < 0 ) {
F_12 ( V_34 -> V_2 , L_11 , V_51 ) ;
goto V_151;
}
F_13 ( V_34 , V_9 ,
V_152 , V_152 ) ;
F_13 ( V_34 , V_10 ,
V_153 , V_153 ) ;
F_13 ( V_34 , V_4 ,
V_154 | V_155 ,
V_154 | V_155 ) ;
F_13 ( V_34 , V_5 ,
V_156 | V_157 ,
V_156 | V_157 ) ;
F_13 ( V_34 , V_25 ,
V_158 | V_159 ,
V_158 | V_159 ) ;
F_13 ( V_34 , V_26 ,
V_160 | V_161 ,
V_160 | V_161 ) ;
F_13 ( V_34 , V_27 ,
V_162 , V_162 ) ;
F_13 ( V_34 , V_11 , V_163 , V_163 ) ;
if ( V_148 ) {
if ( V_148 -> V_164 )
F_13 ( V_34 , V_15 ,
V_165 , V_165 ) ;
if ( V_148 -> V_166 )
F_13 ( V_34 , V_23 ,
V_167 , V_167 ) ;
}
F_26 ( V_34 , V_138 ) ;
F_30 ( F_11 ( V_49 -> V_142 ) , V_49 -> V_142 ) ;
return 0 ;
V_151:
F_30 ( F_11 ( V_49 -> V_142 ) , V_49 -> V_142 ) ;
return V_51 ;
}
static int F_34 ( struct V_168 * V_169 ,
const struct V_170 * V_171 )
{
struct V_48 * V_49 ;
int V_51 ;
V_49 = F_35 ( & V_169 -> V_2 , sizeof( struct V_48 ) ,
V_172 ) ;
if ( V_49 == NULL )
return - V_173 ;
V_49 -> V_143 = F_36 ( V_169 , & V_174 ) ;
if ( F_37 ( V_49 -> V_143 ) ) {
V_51 = F_38 ( V_49 -> V_143 ) ;
F_12 ( & V_169 -> V_2 , L_12 ,
V_51 ) ;
return V_51 ;
}
F_39 ( V_169 , V_49 ) ;
V_51 = F_40 ( & V_169 -> V_2 ,
& V_175 , & V_176 , 1 ) ;
return V_51 ;
}
static int F_41 ( struct V_168 * V_177 )
{
F_42 ( & V_177 -> V_2 ) ;
return 0 ;
}
