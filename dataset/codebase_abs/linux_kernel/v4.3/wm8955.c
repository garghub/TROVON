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
F_13 ( V_34 , V_31 ,
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
struct V_33 * V_34 = F_15 ( V_76 -> V_80 ) ;
int V_51 = 0 ;
F_13 ( V_34 , V_16 ,
V_81 , 0 ) ;
F_13 ( V_34 , V_28 ,
V_68 | V_70 , 0 ) ;
switch ( V_79 ) {
case V_82 :
break;
case V_83 :
V_51 = F_9 ( V_34 ) ;
break;
default:
V_51 = - V_60 ;
break;
}
return V_51 ;
}
static int F_16 ( struct V_33 * V_34 )
{
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_52 , V_50 , V_84 ;
if ( V_49 -> V_85 ) {
V_84 = 1 ;
for ( V_50 = 2 ; V_50 < F_11 ( V_86 ) ; V_50 ++ ) {
if ( abs ( V_86 [ V_50 ] - V_49 -> V_56 ) <
abs ( V_86 [ V_84 ] - V_49 -> V_56 ) )
V_84 = V_50 ;
}
V_52 = V_84 << V_87 ;
} else {
V_52 = 0 ;
}
F_6 ( V_34 -> V_2 , L_7 , V_52 ) ;
return F_13 ( V_34 , V_6 ,
V_88 , V_52 ) ;
}
static int F_17 ( struct V_77 * V_78 ,
struct V_89 * V_90 )
{
struct V_33 * V_34 = F_18 ( V_78 ) ;
struct V_48 * V_49 = F_10 ( V_34 ) ;
V_90 -> V_91 . integer . V_91 [ 0 ] = V_49 -> V_85 ;
return 0 ;
}
static int F_19 ( struct V_77 * V_78 ,
struct V_89 * V_90 )
{
struct V_33 * V_34 = F_18 ( V_78 ) ;
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_85 = V_90 -> V_91 . integer . V_91 [ 0 ] ;
if ( V_85 > 1 )
return - V_60 ;
V_49 -> V_85 = V_85 ;
return F_16 ( V_34 ) ;
}
static int F_20 ( struct V_92 * V_93 ,
struct V_94 * V_95 ,
struct V_96 * V_97 )
{
struct V_33 * V_34 = V_97 -> V_34 ;
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_51 ;
int V_98 ;
switch ( F_21 ( V_95 ) ) {
case 16 :
V_98 = 0 ;
break;
case 20 :
V_98 = 0x4 ;
break;
case 24 :
V_98 = 0x8 ;
break;
case 32 :
V_98 = 0xc ;
break;
default:
return - V_60 ;
}
F_13 ( V_34 , V_7 ,
V_99 , V_98 ) ;
V_49 -> V_56 = F_22 ( V_95 ) ;
F_16 ( V_34 ) ;
V_51 = F_23 ( V_34 , V_16 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_51 & V_81 ) {
F_13 ( V_34 , V_16 ,
V_81 , 0 ) ;
F_13 ( V_34 , V_28 ,
V_68 | V_70 , 0 ) ;
F_9 ( V_34 ) ;
}
return 0 ;
}
static int F_24 ( struct V_96 * V_97 , int V_100 ,
unsigned int V_101 , int V_102 )
{
struct V_33 * V_34 = V_97 -> V_34 ;
struct V_48 * V_103 = F_10 ( V_34 ) ;
int div ;
switch ( V_100 ) {
case V_104 :
if ( V_101 > 15000000 ) {
V_103 -> V_58 = V_101 /= 2 ;
div = V_105 ;
} else {
V_103 -> V_58 = V_101 ;
div = 0 ;
}
F_13 ( V_34 , V_8 ,
V_105 , div ) ;
break;
default:
return - V_60 ;
}
F_6 ( V_97 -> V_2 , L_8 , V_100 , V_101 ) ;
return 0 ;
}
static int F_25 ( struct V_96 * V_97 , unsigned int V_106 )
{
struct V_33 * V_34 = V_97 -> V_34 ;
T_2 V_107 = 0 ;
switch ( V_106 & V_108 ) {
case V_109 :
break;
case V_110 :
V_107 |= V_111 ;
break;
default:
return - V_60 ;
}
switch ( V_106 & V_112 ) {
case V_113 :
V_107 |= V_114 ;
case V_115 :
V_107 |= 0x3 ;
break;
case V_116 :
V_107 |= 0x2 ;
break;
case V_117 :
break;
case V_118 :
V_107 |= 0x1 ;
break;
default:
return - V_60 ;
}
switch ( V_106 & V_112 ) {
case V_115 :
case V_113 :
switch ( V_106 & V_119 ) {
case V_120 :
break;
case V_121 :
V_107 |= V_122 ;
break;
default:
return - V_60 ;
}
break;
case V_116 :
case V_117 :
case V_118 :
switch ( V_106 & V_119 ) {
case V_120 :
break;
case V_123 :
V_107 |= V_122 | V_114 ;
break;
case V_121 :
V_107 |= V_122 ;
break;
case V_124 :
V_107 |= V_114 ;
break;
default:
return - V_60 ;
}
break;
default:
return - V_60 ;
}
F_13 ( V_34 , V_7 ,
V_111 | V_125 | V_122 |
V_114 , V_107 ) ;
return 0 ;
}
static int F_26 ( struct V_96 * V_126 , int V_127 )
{
struct V_33 * V_34 = V_126 -> V_34 ;
int V_52 ;
if ( V_127 )
V_52 = V_128 ;
else
V_52 = 0 ;
F_13 ( V_34 , V_6 , V_128 , V_52 ) ;
return 0 ;
}
static int F_27 ( struct V_33 * V_34 ,
enum V_129 V_130 )
{
struct V_48 * V_49 = F_10 ( V_34 ) ;
int V_51 ;
switch ( V_130 ) {
case V_131 :
break;
case V_132 :
F_13 ( V_34 , V_16 ,
V_133 ,
0x1 << V_134 ) ;
F_13 ( V_34 , V_14 ,
V_135 ,
0x2 << V_136 ) ;
break;
case V_137 :
if ( F_28 ( V_34 ) == V_138 ) {
V_51 = F_29 ( F_11 ( V_49 -> V_139 ) ,
V_49 -> V_139 ) ;
if ( V_51 != 0 ) {
F_12 ( V_34 -> V_2 ,
L_9 ,
V_51 ) ;
return V_51 ;
}
F_30 ( V_49 -> V_140 ) ;
F_13 ( V_34 , V_16 ,
V_141 |
V_133 ,
V_141 |
0x3 << V_142 ) ;
F_31 ( 500 ) ;
F_13 ( V_34 ,
V_18 ,
V_143 , V_143 ) ;
}
F_13 ( V_34 , V_16 ,
V_133 ,
0x2 << V_134 ) ;
F_13 ( V_34 , V_14 ,
V_135 , 0 ) ;
break;
case V_138 :
F_13 ( V_34 ,
V_18 ,
V_143 , 0 ) ;
F_13 ( V_34 , V_16 ,
V_141 |
V_133 , 0 ) ;
F_32 ( F_11 ( V_49 -> V_139 ) ,
V_49 -> V_139 ) ;
break;
}
return 0 ;
}
static int F_33 ( struct V_33 * V_34 )
{
struct V_48 * V_49 = F_10 ( V_34 ) ;
struct V_144 * V_145 = F_34 ( V_34 -> V_2 ) ;
int V_51 , V_50 ;
for ( V_50 = 0 ; V_50 < F_11 ( V_49 -> V_139 ) ; V_50 ++ )
V_49 -> V_139 [ V_50 ] . V_146 = V_147 [ V_50 ] ;
V_51 = F_35 ( V_34 -> V_2 , F_11 ( V_49 -> V_139 ) ,
V_49 -> V_139 ) ;
if ( V_51 != 0 ) {
F_12 ( V_34 -> V_2 , L_10 , V_51 ) ;
return V_51 ;
}
V_51 = F_29 ( F_11 ( V_49 -> V_139 ) ,
V_49 -> V_139 ) ;
if ( V_51 != 0 ) {
F_12 ( V_34 -> V_2 , L_9 , V_51 ) ;
return V_51 ;
}
V_51 = F_3 ( V_34 ) ;
if ( V_51 < 0 ) {
F_12 ( V_34 -> V_2 , L_11 , V_51 ) ;
goto V_148;
}
F_13 ( V_34 , V_9 ,
V_149 , V_149 ) ;
F_13 ( V_34 , V_10 ,
V_150 , V_150 ) ;
F_13 ( V_34 , V_4 ,
V_151 | V_152 ,
V_151 | V_152 ) ;
F_13 ( V_34 , V_5 ,
V_153 | V_154 ,
V_153 | V_154 ) ;
F_13 ( V_34 , V_25 ,
V_155 | V_156 ,
V_155 | V_156 ) ;
F_13 ( V_34 , V_26 ,
V_157 | V_158 ,
V_157 | V_158 ) ;
F_13 ( V_34 , V_27 ,
V_159 , V_159 ) ;
F_13 ( V_34 , V_11 , V_160 , V_160 ) ;
if ( V_145 ) {
if ( V_145 -> V_161 )
F_13 ( V_34 , V_15 ,
V_162 , V_162 ) ;
if ( V_145 -> V_163 )
F_13 ( V_34 , V_23 ,
V_164 , V_164 ) ;
}
F_36 ( V_34 , V_137 ) ;
F_32 ( F_11 ( V_49 -> V_139 ) , V_49 -> V_139 ) ;
return 0 ;
V_148:
F_32 ( F_11 ( V_49 -> V_139 ) , V_49 -> V_139 ) ;
return V_51 ;
}
static int F_37 ( struct V_165 * V_166 ,
const struct V_167 * V_168 )
{
struct V_48 * V_49 ;
int V_51 ;
V_49 = F_38 ( & V_166 -> V_2 , sizeof( struct V_48 ) ,
V_169 ) ;
if ( V_49 == NULL )
return - V_170 ;
V_49 -> V_140 = F_39 ( V_166 , & V_171 ) ;
if ( F_40 ( V_49 -> V_140 ) ) {
V_51 = F_41 ( V_49 -> V_140 ) ;
F_12 ( & V_166 -> V_2 , L_12 ,
V_51 ) ;
return V_51 ;
}
F_42 ( V_166 , V_49 ) ;
V_51 = F_43 ( & V_166 -> V_2 ,
& V_172 , & V_173 , 1 ) ;
return V_51 ;
}
static int F_44 ( struct V_165 * V_174 )
{
F_45 ( & V_174 -> V_2 ) ;
return 0 ;
}
