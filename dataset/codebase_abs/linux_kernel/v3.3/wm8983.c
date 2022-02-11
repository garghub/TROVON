static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 , V_8 ) ;
if ( V_7 & V_9 )
V_4 -> V_10 . integer . V_10 [ 0 ] = 1 ;
else
V_4 -> V_10 . integer . V_10 [ 0 ] = 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_11 , V_12 ;
unsigned int V_13 ;
if ( V_4 -> V_10 . integer . V_10 [ 0 ] != 0
&& V_4 -> V_10 . integer . V_10 [ 0 ] != 1 )
return - V_14 ;
V_13 = F_3 ( V_6 , V_8 ) ;
switch ( ( V_13 & V_9 ) >> V_15 ) {
case 0 :
if ( ! V_4 -> V_10 . integer . V_10 [ 0 ] )
return 0 ;
break;
case 1 :
if ( V_4 -> V_10 . integer . V_10 [ 0 ] )
return 0 ;
break;
}
V_11 = F_3 ( V_6 , V_16 ) ;
V_12 = F_3 ( V_6 , V_17 ) ;
F_5 ( V_6 , V_16 ,
V_18 | V_19 , 0 ) ;
F_5 ( V_6 , V_17 ,
V_20 | V_21 , 0 ) ;
F_5 ( V_6 , V_8 ,
V_22 ,
V_4 -> V_10 . integer . V_10 [ 0 ]
<< V_15 ) ;
F_6 ( V_6 , V_16 , V_11 ) ;
F_6 ( V_6 , V_17 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 , unsigned int V_7 )
{
if ( V_7 > V_23 )
return 0 ;
return V_24 [ V_7 ] . V_25 != 0 ;
}
static int F_8 ( struct V_26 * V_27 , int V_28 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
return F_5 ( V_6 , V_29 ,
V_30 ,
! ! V_28 << V_31 ) ;
}
static int F_9 ( struct V_26 * V_27 , unsigned int V_32 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
T_1 V_33 , V_34 , V_35 , V_36 ;
switch ( V_32 & V_37 ) {
case V_38 :
V_33 = 0x2 ;
break;
case V_39 :
V_33 = 0x0 ;
break;
case V_40 :
V_33 = 0x1 ;
break;
case V_41 :
case V_42 :
V_33 = 0x3 ;
break;
default:
F_10 ( V_27 -> V_43 , L_1 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_44 ,
V_45 , V_33 << V_46 ) ;
switch ( V_32 & V_47 ) {
case V_48 :
V_34 = 1 ;
break;
case V_49 :
V_34 = 0 ;
break;
default:
F_10 ( V_27 -> V_43 , L_2 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_50 ,
V_51 , V_34 << V_52 ) ;
switch ( V_32 & V_37 ) {
case V_41 :
case V_42 :
F_10 ( V_27 -> V_43 , L_3 ) ;
return - V_14 ;
default:
break;
}
V_35 = V_36 = 0 ;
switch ( V_32 & V_53 ) {
case V_54 :
break;
case V_55 :
V_35 = V_36 = 1 ;
break;
case V_56 :
V_35 = 1 ;
break;
case V_57 :
V_36 = 1 ;
break;
default:
F_10 ( V_27 -> V_43 , L_4 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_44 ,
V_58 , V_36 << V_59 ) ;
F_5 ( V_6 , V_44 ,
V_60 , V_35 << V_61 ) ;
return 0 ;
}
static int F_11 ( struct V_62 * V_63 ,
struct V_64 * V_65 ,
struct V_26 * V_27 )
{
int V_66 ;
struct V_5 * V_6 = V_27 -> V_6 ;
struct V_67 * V_68 = F_12 ( V_6 ) ;
T_1 V_69 , V_70 ;
T_2 V_71 ;
int V_72 ;
int V_73 ;
V_73 = F_13 ( V_65 ) ;
if ( V_73 < 0 ) {
F_10 ( V_6 -> V_43 , L_5 , V_73 ) ;
return V_73 ;
}
V_68 -> V_74 = V_73 ;
switch ( F_14 ( V_65 ) ) {
case V_75 :
V_69 = 0x0 ;
break;
case V_76 :
V_69 = 0x1 ;
break;
case V_77 :
V_69 = 0x2 ;
break;
case V_78 :
V_69 = 0x3 ;
break;
default:
F_10 ( V_27 -> V_43 , L_6 ,
F_14 ( V_65 ) ) ;
return - V_14 ;
}
F_5 ( V_6 , V_44 ,
V_79 , V_69 << V_80 ) ;
V_70 = 0 ;
V_72 = abs ( V_81 [ 0 ] - F_15 ( V_65 ) ) ;
for ( V_66 = 1 ; V_66 < F_16 ( V_81 ) ; ++ V_66 ) {
if ( abs ( V_81 [ V_66 ] - F_15 ( V_65 ) ) >= V_72 )
continue;
V_70 = V_66 ;
V_72 = abs ( V_81 [ V_66 ] - F_15 ( V_65 ) ) ;
}
F_17 ( V_27 -> V_43 , L_7 , V_81 [ V_70 ] ) ;
F_5 ( V_6 , V_82 ,
V_83 , V_70 << V_84 ) ;
F_17 ( V_27 -> V_43 , L_8 , V_68 -> V_74 ) ;
F_17 ( V_27 -> V_43 , L_9 , V_68 -> V_85 ) ;
for ( V_66 = 0 ; V_66 < F_16 ( V_86 ) ; ++ V_66 ) {
if ( V_68 -> V_85 / F_15 ( V_65 )
== V_86 [ V_66 ] . V_87 )
break;
}
if ( V_66 == F_16 ( V_86 ) ) {
F_10 ( V_27 -> V_43 , L_10 ,
V_68 -> V_85 , F_15 ( V_65 ) ) ;
return - V_14 ;
}
F_17 ( V_27 -> V_43 , L_11 , V_86 [ V_66 ] . V_87 ) ;
F_5 ( V_6 , V_50 ,
V_88 , V_66 << V_89 ) ;
V_71 = ( V_68 -> V_85 / V_86 [ V_66 ] . div ) * 10 ;
for ( V_66 = 0 ; V_66 < F_16 ( V_90 ) ; ++ V_66 ) {
if ( V_68 -> V_74 == V_71 / V_90 [ V_66 ] )
break;
}
if ( V_66 == F_16 ( V_90 ) ) {
F_10 ( V_27 -> V_43 , L_12 ) ;
return - V_14 ;
}
F_17 ( V_27 -> V_43 , L_13 , V_66 ) ;
F_5 ( V_6 , V_50 ,
V_91 , V_66 << V_92 ) ;
return 0 ;
}
static int F_18 ( struct V_93 * V_93 , unsigned int V_94 ,
unsigned int V_95 )
{
T_3 V_96 ;
unsigned long int V_97 , V_98 , V_99 ;
V_93 -> V_100 = 0 ;
V_98 = V_94 / V_95 ;
if ( V_98 < 6 ) {
V_95 >>= 1 ;
V_93 -> V_100 = 1 ;
V_98 = V_94 / V_95 ;
}
if ( V_98 < 6 || V_98 > 12 ) {
F_19 ( V_101 L_14
L_15 , V_102 , V_98 ) ;
return - V_14 ;
}
V_93 -> V_103 = V_98 ;
V_99 = V_94 % V_95 ;
V_96 = V_104 * ( T_3 ) V_99 ;
F_20 ( V_96 , V_95 ) ;
V_97 = V_96 & 0xffffffff ;
if ( ( V_97 % 10 ) >= 5 )
V_97 += 5 ;
V_97 /= 10 ;
V_93 -> V_105 = V_97 ;
return 0 ;
}
static int F_21 ( struct V_26 * V_27 , int V_106 ,
int V_95 , unsigned int V_107 ,
unsigned int V_108 )
{
int V_73 ;
struct V_5 * V_6 ;
struct V_93 V_93 ;
V_6 = V_27 -> V_6 ;
if ( V_107 && V_108 ) {
V_73 = F_18 ( & V_93 , V_108 * 4 * 2 , V_107 ) ;
if ( V_73 )
return V_73 ;
}
F_5 ( V_6 , V_109 ,
V_110 , 0 ) ;
if ( ! V_107 || ! V_108 )
return 0 ;
F_6 ( V_6 , V_111 ,
( V_93 . V_100 << V_112 )
| V_93 . V_103 ) ;
F_6 ( V_6 , V_113 , V_93 . V_105 & 0x1ff ) ;
F_6 ( V_6 , V_114 , ( V_93 . V_105 >> 9 ) & 0x1ff ) ;
F_6 ( V_6 , V_115 , ( V_93 . V_105 >> 18 ) ) ;
F_5 ( V_6 , V_109 ,
V_110 , V_116 ) ;
return 0 ;
}
static int F_22 ( struct V_26 * V_27 ,
int V_117 , unsigned int V_118 , int V_119 )
{
struct V_5 * V_6 = V_27 -> V_6 ;
struct V_67 * V_68 = F_12 ( V_6 ) ;
switch ( V_117 ) {
case V_120 :
F_5 ( V_6 , V_50 ,
V_121 , 0 ) ;
break;
case V_122 :
F_5 ( V_6 , V_50 ,
V_121 , V_123 ) ;
break;
default:
F_10 ( V_27 -> V_43 , L_16 , V_117 ) ;
return - V_14 ;
}
V_68 -> V_85 = V_118 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_124 V_125 )
{
int V_73 ;
switch ( V_125 ) {
case V_126 :
case V_127 :
F_5 ( V_6 , V_109 ,
V_128 ,
1 << V_129 ) ;
break;
case V_130 :
if ( V_6 -> V_131 . V_132 == V_133 ) {
V_73 = F_24 ( V_6 ) ;
if ( V_73 < 0 ) {
F_10 ( V_6 -> V_43 , L_17 , V_73 ) ;
return V_73 ;
}
F_5 ( V_6 , V_134 ,
V_135 | V_136 ,
V_137 | V_138 ) ;
F_5 ( V_6 , V_139 ,
V_140 , V_141 ) ;
F_5 ( V_6 , V_109 ,
V_142 , V_143 ) ;
F_5 ( V_6 , V_109 ,
V_128 ,
1 << V_129 ) ;
F_25 ( 250 ) ;
F_5 ( V_6 , V_134 ,
V_135 |
V_136 , 0 ) ;
}
F_5 ( V_6 , V_109 ,
V_128 ,
2 << V_129 ) ;
break;
case V_133 :
F_5 ( V_6 , V_139 ,
V_140 , 0 ) ;
F_5 ( V_6 , V_109 ,
V_128 | V_142 ,
0 ) ;
F_25 ( 100 ) ;
F_6 ( V_6 , V_109 , 0 ) ;
F_6 ( V_6 , V_16 , 0 ) ;
F_6 ( V_6 , V_17 , 0 ) ;
break;
}
V_6 -> V_131 . V_132 = V_125 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_23 ( V_6 , V_133 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
F_23 ( V_6 , V_130 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
F_23 ( V_6 , V_133 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
int V_73 ;
struct V_67 * V_68 = F_12 ( V_6 ) ;
int V_66 ;
V_73 = F_30 ( V_6 , 7 , 9 , V_68 -> V_144 ) ;
if ( V_73 < 0 ) {
F_10 ( V_6 -> V_43 , L_18 , V_73 ) ;
return V_73 ;
}
V_73 = F_6 ( V_6 , V_145 , 0 ) ;
if ( V_73 < 0 ) {
F_10 ( V_6 -> V_43 , L_19 , V_73 ) ;
return V_73 ;
}
for ( V_66 = 0 ; V_66 < F_16 ( V_146 ) ; ++ V_66 )
F_5 ( V_6 , V_146 [ V_66 ] ,
0x100 , 0x100 ) ;
for ( V_66 = V_147 ;
V_66 <= V_148 ; ++ V_66 )
F_5 ( V_6 , V_66 , 0x40 , 0x40 ) ;
F_5 ( V_6 , V_29 ,
V_30 ,
V_149 ) ;
F_5 ( V_6 , V_150 ,
V_151 , V_151 ) ;
return 0 ;
}
static int T_4 F_31 ( struct V_152 * V_153 )
{
struct V_67 * V_68 ;
int V_73 ;
V_68 = F_32 ( sizeof *V_68 , V_154 ) ;
if ( ! V_68 )
return - V_155 ;
V_68 -> V_144 = V_156 ;
F_33 ( V_153 , V_68 ) ;
V_73 = F_34 ( & V_153 -> V_43 ,
& V_157 , & V_158 , 1 ) ;
if ( V_73 < 0 )
F_35 ( V_68 ) ;
return V_73 ;
}
static int T_5 F_36 ( struct V_152 * V_153 )
{
F_37 ( & V_153 -> V_43 ) ;
F_35 ( F_38 ( V_153 ) ) ;
return 0 ;
}
static T_4 int F_39 ( struct V_159 * V_160 ,
const struct V_161 * V_162 )
{
struct V_67 * V_68 ;
int V_73 ;
V_68 = F_32 ( sizeof *V_68 , V_154 ) ;
if ( ! V_68 )
return - V_155 ;
V_68 -> V_144 = V_163 ;
F_40 ( V_160 , V_68 ) ;
V_73 = F_34 ( & V_160 -> V_43 ,
& V_157 , & V_158 , 1 ) ;
if ( V_73 < 0 )
F_35 ( V_68 ) ;
return V_73 ;
}
static T_5 int F_41 ( struct V_159 * V_164 )
{
F_37 ( & V_164 -> V_43 ) ;
F_35 ( F_42 ( V_164 ) ) ;
return 0 ;
}
static int T_6 F_43 ( void )
{
int V_73 = 0 ;
#if F_44 ( V_165 ) || F_44 ( V_166 )
V_73 = F_45 ( & V_167 ) ;
if ( V_73 ) {
F_19 ( V_101 L_20 ,
V_73 ) ;
}
#endif
#if F_44 ( V_168 )
V_73 = F_46 ( & V_169 ) ;
if ( V_73 != 0 ) {
F_19 ( V_101 L_21 ,
V_73 ) ;
}
#endif
return V_73 ;
}
static void T_7 F_47 ( void )
{
#if F_44 ( V_165 ) || F_44 ( V_166 )
F_48 ( & V_167 ) ;
#endif
#if F_44 ( V_168 )
F_49 ( & V_169 ) ;
#endif
}
