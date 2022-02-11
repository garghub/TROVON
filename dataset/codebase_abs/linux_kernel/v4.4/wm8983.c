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
static bool F_7 ( struct V_23 * V_24 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_25 ... V_26 :
case V_8 ... V_27 :
case V_28 ... V_29 :
case V_30 ... V_31 :
case V_32 ... V_33 :
case V_34 :
return true ;
default:
return false ;
}
}
static int F_8 ( struct V_35 * V_36 , int V_37 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
return F_5 ( V_6 , V_38 ,
V_39 ,
! ! V_37 << V_40 ) ;
}
static int F_9 ( struct V_35 * V_36 , unsigned int V_41 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
T_1 V_42 , V_43 , V_44 , V_45 ;
switch ( V_41 & V_46 ) {
case V_47 :
V_42 = 0x2 ;
break;
case V_48 :
V_42 = 0x0 ;
break;
case V_49 :
V_42 = 0x1 ;
break;
case V_50 :
case V_51 :
V_42 = 0x3 ;
break;
default:
F_10 ( V_36 -> V_24 , L_1 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_52 ,
V_53 , V_42 << V_54 ) ;
switch ( V_41 & V_55 ) {
case V_56 :
V_43 = 1 ;
break;
case V_57 :
V_43 = 0 ;
break;
default:
F_10 ( V_36 -> V_24 , L_2 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_58 ,
V_59 , V_43 << V_60 ) ;
switch ( V_41 & V_46 ) {
case V_50 :
case V_51 :
F_10 ( V_36 -> V_24 , L_3 ) ;
return - V_14 ;
default:
break;
}
V_44 = V_45 = 0 ;
switch ( V_41 & V_61 ) {
case V_62 :
break;
case V_63 :
V_44 = V_45 = 1 ;
break;
case V_64 :
V_44 = 1 ;
break;
case V_65 :
V_45 = 1 ;
break;
default:
F_10 ( V_36 -> V_24 , L_4 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_52 ,
V_66 , V_45 << V_67 ) ;
F_5 ( V_6 , V_52 ,
V_68 , V_44 << V_69 ) ;
return 0 ;
}
static int F_11 ( struct V_70 * V_71 ,
struct V_72 * V_73 ,
struct V_35 * V_36 )
{
int V_74 ;
struct V_5 * V_6 = V_36 -> V_6 ;
struct V_75 * V_76 = F_12 ( V_6 ) ;
T_1 V_77 , V_78 ;
T_2 V_79 ;
int V_80 ;
int V_81 ;
V_81 = F_13 ( V_73 ) ;
if ( V_81 < 0 ) {
F_10 ( V_6 -> V_24 , L_5 , V_81 ) ;
return V_81 ;
}
V_76 -> V_82 = V_81 ;
switch ( F_14 ( V_73 ) ) {
case 16 :
V_77 = 0x0 ;
break;
case 20 :
V_77 = 0x1 ;
break;
case 24 :
V_77 = 0x2 ;
break;
case 32 :
V_77 = 0x3 ;
break;
default:
F_10 ( V_36 -> V_24 , L_6 ,
F_14 ( V_73 ) ) ;
return - V_14 ;
}
F_5 ( V_6 , V_52 ,
V_83 , V_77 << V_84 ) ;
V_78 = 0 ;
V_80 = abs ( V_85 [ 0 ] - F_15 ( V_73 ) ) ;
for ( V_74 = 1 ; V_74 < F_16 ( V_85 ) ; ++ V_74 ) {
if ( abs ( V_85 [ V_74 ] - F_15 ( V_73 ) ) >= V_80 )
continue;
V_78 = V_74 ;
V_80 = abs ( V_85 [ V_74 ] - F_15 ( V_73 ) ) ;
}
F_17 ( V_36 -> V_24 , L_7 , V_85 [ V_78 ] ) ;
F_5 ( V_6 , V_86 ,
V_87 , V_78 << V_88 ) ;
F_17 ( V_36 -> V_24 , L_8 , V_76 -> V_82 ) ;
F_17 ( V_36 -> V_24 , L_9 , V_76 -> V_89 ) ;
for ( V_74 = 0 ; V_74 < F_16 ( V_90 ) ; ++ V_74 ) {
if ( V_76 -> V_89 / F_15 ( V_73 )
== V_90 [ V_74 ] . V_91 )
break;
}
if ( V_74 == F_16 ( V_90 ) ) {
F_10 ( V_36 -> V_24 , L_10 ,
V_76 -> V_89 , F_15 ( V_73 ) ) ;
return - V_14 ;
}
F_17 ( V_36 -> V_24 , L_11 , V_90 [ V_74 ] . V_91 ) ;
F_5 ( V_6 , V_58 ,
V_92 , V_74 << V_93 ) ;
V_79 = ( V_76 -> V_89 / V_90 [ V_74 ] . div ) * 10 ;
for ( V_74 = 0 ; V_74 < F_16 ( V_94 ) ; ++ V_74 ) {
if ( V_76 -> V_82 == V_79 / V_94 [ V_74 ] )
break;
}
if ( V_74 == F_16 ( V_94 ) ) {
F_10 ( V_36 -> V_24 , L_12 ) ;
return - V_14 ;
}
F_17 ( V_36 -> V_24 , L_13 , V_74 ) ;
F_5 ( V_6 , V_58 ,
V_95 , V_74 << V_96 ) ;
return 0 ;
}
static int F_18 ( struct V_97 * V_97 , unsigned int V_98 ,
unsigned int V_99 )
{
T_3 V_100 ;
unsigned long int V_101 , V_102 , V_103 ;
V_97 -> V_104 = 0 ;
V_102 = V_98 / V_99 ;
if ( V_102 < 6 ) {
V_99 >>= 1 ;
V_97 -> V_104 = 1 ;
V_102 = V_98 / V_99 ;
}
if ( V_102 < 6 || V_102 > 12 ) {
F_19 ( V_105 L_14
L_15 , V_106 , V_102 ) ;
return - V_14 ;
}
V_97 -> V_107 = V_102 ;
V_103 = V_98 % V_99 ;
V_100 = V_108 * ( T_3 ) V_103 ;
F_20 ( V_100 , V_99 ) ;
V_101 = V_100 & 0xffffffff ;
if ( ( V_101 % 10 ) >= 5 )
V_101 += 5 ;
V_101 /= 10 ;
V_97 -> V_109 = V_101 ;
return 0 ;
}
static int F_21 ( struct V_35 * V_36 , int V_110 ,
int V_99 , unsigned int V_111 ,
unsigned int V_112 )
{
int V_81 ;
struct V_5 * V_6 ;
struct V_97 V_97 ;
V_6 = V_36 -> V_6 ;
if ( ! V_111 || ! V_112 ) {
F_5 ( V_6 , V_113 ,
V_114 , 0 ) ;
return 0 ;
} else {
V_81 = F_18 ( & V_97 , V_112 * 4 * 2 , V_111 ) ;
if ( V_81 )
return V_81 ;
F_5 ( V_6 , V_113 ,
V_114 , 0 ) ;
F_6 ( V_6 , V_115 ,
( V_97 . V_104 << V_116 )
| V_97 . V_107 ) ;
F_6 ( V_6 , V_31 , V_97 . V_109 & 0x1ff ) ;
F_6 ( V_6 , V_117 , ( V_97 . V_109 >> 9 ) & 0x1ff ) ;
F_6 ( V_6 , V_118 , ( V_97 . V_109 >> 18 ) ) ;
F_5 ( V_6 , V_113 ,
V_114 , V_119 ) ;
}
return 0 ;
}
static int F_22 ( struct V_35 * V_36 ,
int V_120 , unsigned int V_121 , int V_122 )
{
struct V_5 * V_6 = V_36 -> V_6 ;
struct V_75 * V_76 = F_12 ( V_6 ) ;
switch ( V_120 ) {
case V_123 :
F_5 ( V_6 , V_58 ,
V_124 , 0 ) ;
break;
case V_125 :
F_5 ( V_6 , V_58 ,
V_124 , V_126 ) ;
break;
default:
F_10 ( V_36 -> V_24 , L_16 , V_120 ) ;
return - V_14 ;
}
V_76 -> V_89 = V_121 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_127 V_128 )
{
struct V_75 * V_76 = F_12 ( V_6 ) ;
int V_81 ;
switch ( V_128 ) {
case V_129 :
case V_130 :
F_5 ( V_6 , V_113 ,
V_131 ,
1 << V_132 ) ;
break;
case V_133 :
if ( F_24 ( V_6 ) == V_134 ) {
V_81 = F_25 ( V_76 -> V_135 ) ;
if ( V_81 < 0 ) {
F_10 ( V_6 -> V_24 , L_17 , V_81 ) ;
return V_81 ;
}
F_5 ( V_6 , V_136 ,
V_137 | V_138 ,
V_139 | V_140 ) ;
F_5 ( V_6 , V_141 ,
V_142 , V_143 ) ;
F_5 ( V_6 , V_113 ,
V_144 , V_145 ) ;
F_5 ( V_6 , V_113 ,
V_131 ,
1 << V_132 ) ;
F_26 ( 250 ) ;
F_5 ( V_6 , V_136 ,
V_137 |
V_138 , 0 ) ;
}
F_5 ( V_6 , V_113 ,
V_131 ,
2 << V_132 ) ;
break;
case V_134 :
F_5 ( V_6 , V_141 ,
V_142 , 0 ) ;
F_5 ( V_6 , V_113 ,
V_131 | V_144 ,
0 ) ;
F_26 ( 100 ) ;
F_6 ( V_6 , V_113 , 0 ) ;
F_6 ( V_6 , V_16 , 0 ) ;
F_6 ( V_6 , V_17 , 0 ) ;
break;
}
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
int V_81 ;
int V_74 ;
V_81 = F_6 ( V_6 , V_25 , 0 ) ;
if ( V_81 < 0 ) {
F_10 ( V_6 -> V_24 , L_18 , V_81 ) ;
return V_81 ;
}
for ( V_74 = 0 ; V_74 < F_16 ( V_146 ) ; ++ V_74 )
F_5 ( V_6 , V_146 [ V_74 ] ,
0x100 , 0x100 ) ;
for ( V_74 = V_147 ;
V_74 <= V_33 ; ++ V_74 )
F_5 ( V_6 , V_74 , 0x40 , 0x40 ) ;
F_5 ( V_6 , V_38 ,
V_39 ,
V_148 ) ;
F_5 ( V_6 , V_34 ,
V_149 , V_149 ) ;
return 0 ;
}
static int F_28 ( struct V_150 * V_151 )
{
struct V_75 * V_76 ;
int V_81 ;
V_76 = F_29 ( & V_151 -> V_24 , sizeof *V_76 , V_152 ) ;
if ( ! V_76 )
return - V_153 ;
V_76 -> V_135 = F_30 ( V_151 , & V_154 ) ;
if ( F_31 ( V_76 -> V_135 ) ) {
V_81 = F_32 ( V_76 -> V_135 ) ;
F_10 ( & V_151 -> V_24 , L_19 , V_81 ) ;
return V_81 ;
}
F_33 ( V_151 , V_76 ) ;
V_81 = F_34 ( & V_151 -> V_24 ,
& V_155 , & V_156 , 1 ) ;
return V_81 ;
}
static int F_35 ( struct V_150 * V_151 )
{
F_36 ( & V_151 -> V_24 ) ;
return 0 ;
}
static int F_37 ( struct V_157 * V_158 ,
const struct V_159 * V_160 )
{
struct V_75 * V_76 ;
int V_81 ;
V_76 = F_29 ( & V_158 -> V_24 , sizeof *V_76 , V_152 ) ;
if ( ! V_76 )
return - V_153 ;
V_76 -> V_135 = F_38 ( V_158 , & V_154 ) ;
if ( F_31 ( V_76 -> V_135 ) ) {
V_81 = F_32 ( V_76 -> V_135 ) ;
F_10 ( & V_158 -> V_24 , L_19 , V_81 ) ;
return V_81 ;
}
F_39 ( V_158 , V_76 ) ;
V_81 = F_34 ( & V_158 -> V_24 ,
& V_155 , & V_156 , 1 ) ;
return V_81 ;
}
static int F_40 ( struct V_157 * V_161 )
{
F_36 ( & V_161 -> V_24 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
int V_81 = 0 ;
#if F_42 ( V_162 )
V_81 = F_43 ( & V_163 ) ;
if ( V_81 ) {
F_19 ( V_105 L_20 ,
V_81 ) ;
}
#endif
#if F_44 ( V_164 )
V_81 = F_45 ( & V_165 ) ;
if ( V_81 != 0 ) {
F_19 ( V_105 L_21 ,
V_81 ) ;
}
#endif
return V_81 ;
}
static void T_5 F_46 ( void )
{
#if F_42 ( V_162 )
F_47 ( & V_163 ) ;
#endif
#if F_44 ( V_164 )
F_48 ( & V_165 ) ;
#endif
}
