static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_7 ;
V_7 = F_3 ( V_6 , V_8 ) ;
if ( V_7 & V_9 )
V_4 -> V_10 . V_11 . V_12 [ 0 ] = 1 ;
else
V_4 -> V_10 . V_11 . V_12 [ 0 ] = 0 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_13 , V_14 ;
unsigned int V_15 ;
if ( V_4 -> V_10 . V_11 . V_12 [ 0 ] != 0
&& V_4 -> V_10 . V_11 . V_12 [ 0 ] != 1 )
return - V_16 ;
V_15 = F_3 ( V_6 , V_8 ) ;
switch ( ( V_15 & V_9 ) >> V_17 ) {
case 0 :
if ( ! V_4 -> V_10 . V_11 . V_12 [ 0 ] )
return 0 ;
break;
case 1 :
if ( V_4 -> V_10 . V_11 . V_12 [ 0 ] )
return 0 ;
break;
}
V_13 = F_3 ( V_6 , V_18 ) ;
V_14 = F_3 ( V_6 , V_19 ) ;
F_5 ( V_6 , V_18 ,
V_20 | V_21 , 0 ) ;
F_5 ( V_6 , V_19 ,
V_22 | V_23 , 0 ) ;
F_5 ( V_6 , V_8 ,
V_24 ,
V_4 -> V_10 . V_11 . V_12 [ 0 ]
<< V_17 ) ;
F_6 ( V_6 , V_18 , V_13 ) ;
F_6 ( V_6 , V_19 , V_14 ) ;
return 0 ;
}
static bool F_7 ( struct V_25 * V_26 , unsigned int V_7 )
{
switch ( V_7 ) {
case V_27 ... V_28 :
case V_8 ... V_29 :
case V_30 ... V_31 :
case V_32 ... V_33 :
case V_34 ... V_35 :
case V_36 :
return true ;
default:
return false ;
}
}
static int F_8 ( struct V_37 * V_38 , int V_39 )
{
struct V_5 * V_6 = V_38 -> V_6 ;
return F_5 ( V_6 , V_40 ,
V_41 ,
! ! V_39 << V_42 ) ;
}
static int F_9 ( struct V_37 * V_38 , unsigned int V_43 )
{
struct V_5 * V_6 = V_38 -> V_6 ;
T_1 V_44 , V_45 , V_46 , V_47 ;
switch ( V_43 & V_48 ) {
case V_49 :
V_44 = 0x2 ;
break;
case V_50 :
V_44 = 0x0 ;
break;
case V_51 :
V_44 = 0x1 ;
break;
case V_52 :
case V_53 :
V_44 = 0x3 ;
break;
default:
F_10 ( V_38 -> V_26 , L_1 ) ;
return - V_16 ;
}
F_5 ( V_6 , V_54 ,
V_55 , V_44 << V_56 ) ;
switch ( V_43 & V_57 ) {
case V_58 :
V_45 = 1 ;
break;
case V_59 :
V_45 = 0 ;
break;
default:
F_10 ( V_38 -> V_26 , L_2 ) ;
return - V_16 ;
}
F_5 ( V_6 , V_60 ,
V_61 , V_45 << V_62 ) ;
switch ( V_43 & V_48 ) {
case V_52 :
case V_53 :
F_10 ( V_38 -> V_26 , L_3 ) ;
return - V_16 ;
default:
break;
}
V_46 = V_47 = 0 ;
switch ( V_43 & V_63 ) {
case V_64 :
break;
case V_65 :
V_46 = V_47 = 1 ;
break;
case V_66 :
V_46 = 1 ;
break;
case V_67 :
V_47 = 1 ;
break;
default:
F_10 ( V_38 -> V_26 , L_4 ) ;
return - V_16 ;
}
F_5 ( V_6 , V_54 ,
V_68 , V_47 << V_69 ) ;
F_5 ( V_6 , V_54 ,
V_70 , V_46 << V_71 ) ;
return 0 ;
}
static int F_11 ( struct V_72 * V_73 ,
struct V_74 * V_75 ,
struct V_37 * V_38 )
{
int V_76 ;
struct V_5 * V_6 = V_38 -> V_6 ;
struct V_77 * V_78 = F_12 ( V_6 ) ;
T_1 V_79 , V_80 ;
T_2 V_81 ;
int V_82 ;
int V_83 ;
V_83 = F_13 ( V_75 ) ;
if ( V_83 < 0 ) {
F_10 ( V_6 -> V_26 , L_5 , V_83 ) ;
return V_83 ;
}
V_78 -> V_84 = V_83 ;
switch ( F_14 ( V_75 ) ) {
case 16 :
V_79 = 0x0 ;
break;
case 20 :
V_79 = 0x1 ;
break;
case 24 :
V_79 = 0x2 ;
break;
case 32 :
V_79 = 0x3 ;
break;
default:
F_10 ( V_38 -> V_26 , L_6 ,
F_14 ( V_75 ) ) ;
return - V_16 ;
}
F_5 ( V_6 , V_54 ,
V_85 , V_79 << V_86 ) ;
V_80 = 0 ;
V_82 = abs ( V_87 [ 0 ] - F_15 ( V_75 ) ) ;
for ( V_76 = 1 ; V_76 < F_16 ( V_87 ) ; ++ V_76 ) {
if ( abs ( V_87 [ V_76 ] - F_15 ( V_75 ) ) >= V_82 )
continue;
V_80 = V_76 ;
V_82 = abs ( V_87 [ V_76 ] - F_15 ( V_75 ) ) ;
}
F_17 ( V_38 -> V_26 , L_7 , V_87 [ V_80 ] ) ;
F_5 ( V_6 , V_88 ,
V_89 , V_80 << V_90 ) ;
F_17 ( V_38 -> V_26 , L_8 , V_78 -> V_84 ) ;
F_17 ( V_38 -> V_26 , L_9 , V_78 -> V_91 ) ;
for ( V_76 = 0 ; V_76 < F_16 ( V_92 ) ; ++ V_76 ) {
if ( V_78 -> V_91 / F_15 ( V_75 )
== V_92 [ V_76 ] . V_93 )
break;
}
if ( V_76 == F_16 ( V_92 ) ) {
F_10 ( V_38 -> V_26 , L_10 ,
V_78 -> V_91 , F_15 ( V_75 ) ) ;
return - V_16 ;
}
F_17 ( V_38 -> V_26 , L_11 , V_92 [ V_76 ] . V_93 ) ;
F_5 ( V_6 , V_60 ,
V_94 , V_76 << V_95 ) ;
V_81 = ( V_78 -> V_91 / V_92 [ V_76 ] . div ) * 10 ;
for ( V_76 = 0 ; V_76 < F_16 ( V_96 ) ; ++ V_76 ) {
if ( V_78 -> V_84 == V_81 / V_96 [ V_76 ] )
break;
}
if ( V_76 == F_16 ( V_96 ) ) {
F_10 ( V_38 -> V_26 , L_12 ) ;
return - V_16 ;
}
F_17 ( V_38 -> V_26 , L_13 , V_76 ) ;
F_5 ( V_6 , V_60 ,
V_97 , V_76 << V_98 ) ;
return 0 ;
}
static int F_18 ( struct V_99 * V_99 , unsigned int V_100 ,
unsigned int V_101 )
{
T_3 V_102 ;
unsigned long int V_103 , V_104 , V_105 ;
V_99 -> V_106 = 0 ;
V_104 = V_100 / V_101 ;
if ( V_104 < 6 ) {
V_101 >>= 1 ;
V_99 -> V_106 = 1 ;
V_104 = V_100 / V_101 ;
}
if ( V_104 < 6 || V_104 > 12 ) {
F_19 ( V_107 L_14
L_15 , V_108 , V_104 ) ;
return - V_16 ;
}
V_99 -> V_109 = V_104 ;
V_105 = V_100 % V_101 ;
V_102 = V_110 * ( T_3 ) V_105 ;
F_20 ( V_102 , V_101 ) ;
V_103 = V_102 & 0xffffffff ;
if ( ( V_103 % 10 ) >= 5 )
V_103 += 5 ;
V_103 /= 10 ;
V_99 -> V_111 = V_103 ;
return 0 ;
}
static int F_21 ( struct V_37 * V_38 , int V_112 ,
int V_101 , unsigned int V_113 ,
unsigned int V_114 )
{
int V_83 ;
struct V_5 * V_6 ;
struct V_99 V_99 ;
V_6 = V_38 -> V_6 ;
if ( ! V_113 || ! V_114 ) {
F_5 ( V_6 , V_115 ,
V_116 , 0 ) ;
return 0 ;
} else {
V_83 = F_18 ( & V_99 , V_114 * 4 * 2 , V_113 ) ;
if ( V_83 )
return V_83 ;
F_5 ( V_6 , V_115 ,
V_116 , 0 ) ;
F_6 ( V_6 , V_117 ,
( V_99 . V_106 << V_118 )
| V_99 . V_109 ) ;
F_6 ( V_6 , V_33 , V_99 . V_111 & 0x1ff ) ;
F_6 ( V_6 , V_119 , ( V_99 . V_111 >> 9 ) & 0x1ff ) ;
F_6 ( V_6 , V_120 , ( V_99 . V_111 >> 18 ) ) ;
F_5 ( V_6 , V_115 ,
V_116 , V_121 ) ;
}
return 0 ;
}
static int F_22 ( struct V_37 * V_38 ,
int V_122 , unsigned int V_123 , int V_124 )
{
struct V_5 * V_6 = V_38 -> V_6 ;
struct V_77 * V_78 = F_12 ( V_6 ) ;
switch ( V_122 ) {
case V_125 :
F_5 ( V_6 , V_60 ,
V_126 , 0 ) ;
break;
case V_127 :
F_5 ( V_6 , V_60 ,
V_126 , V_128 ) ;
break;
default:
F_10 ( V_38 -> V_26 , L_16 , V_122 ) ;
return - V_16 ;
}
V_78 -> V_91 = V_123 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_129 V_130 )
{
struct V_77 * V_78 = F_12 ( V_6 ) ;
int V_83 ;
switch ( V_130 ) {
case V_131 :
case V_132 :
F_5 ( V_6 , V_115 ,
V_133 ,
1 << V_134 ) ;
break;
case V_135 :
if ( F_24 ( V_6 ) == V_136 ) {
V_83 = F_25 ( V_78 -> V_137 ) ;
if ( V_83 < 0 ) {
F_10 ( V_6 -> V_26 , L_17 , V_83 ) ;
return V_83 ;
}
F_5 ( V_6 , V_138 ,
V_139 | V_140 ,
V_141 | V_142 ) ;
F_5 ( V_6 , V_143 ,
V_144 , V_145 ) ;
F_5 ( V_6 , V_115 ,
V_146 , V_147 ) ;
F_5 ( V_6 , V_115 ,
V_133 ,
1 << V_134 ) ;
F_26 ( 250 ) ;
F_5 ( V_6 , V_138 ,
V_139 |
V_140 , 0 ) ;
}
F_5 ( V_6 , V_115 ,
V_133 ,
2 << V_134 ) ;
break;
case V_136 :
F_5 ( V_6 , V_143 ,
V_144 , 0 ) ;
F_5 ( V_6 , V_115 ,
V_133 | V_146 ,
0 ) ;
F_26 ( 100 ) ;
F_6 ( V_6 , V_115 , 0 ) ;
F_6 ( V_6 , V_18 , 0 ) ;
F_6 ( V_6 , V_19 , 0 ) ;
break;
}
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
int V_83 ;
int V_76 ;
V_83 = F_6 ( V_6 , V_27 , 0 ) ;
if ( V_83 < 0 ) {
F_10 ( V_6 -> V_26 , L_18 , V_83 ) ;
return V_83 ;
}
for ( V_76 = 0 ; V_76 < F_16 ( V_148 ) ; ++ V_76 )
F_5 ( V_6 , V_148 [ V_76 ] ,
0x100 , 0x100 ) ;
for ( V_76 = V_149 ;
V_76 <= V_35 ; ++ V_76 )
F_5 ( V_6 , V_76 , 0x40 , 0x40 ) ;
F_5 ( V_6 , V_40 ,
V_41 ,
V_150 ) ;
F_5 ( V_6 , V_36 ,
V_151 , V_151 ) ;
return 0 ;
}
static int F_28 ( struct V_152 * V_153 )
{
struct V_77 * V_78 ;
int V_83 ;
V_78 = F_29 ( & V_153 -> V_26 , sizeof *V_78 , V_154 ) ;
if ( ! V_78 )
return - V_155 ;
V_78 -> V_137 = F_30 ( V_153 , & V_156 ) ;
if ( F_31 ( V_78 -> V_137 ) ) {
V_83 = F_32 ( V_78 -> V_137 ) ;
F_10 ( & V_153 -> V_26 , L_19 , V_83 ) ;
return V_83 ;
}
F_33 ( V_153 , V_78 ) ;
V_83 = F_34 ( & V_153 -> V_26 ,
& V_157 , & V_158 , 1 ) ;
return V_83 ;
}
static int F_35 ( struct V_152 * V_153 )
{
F_36 ( & V_153 -> V_26 ) ;
return 0 ;
}
static int F_37 ( struct V_159 * V_160 ,
const struct V_161 * V_162 )
{
struct V_77 * V_78 ;
int V_83 ;
V_78 = F_29 ( & V_160 -> V_26 , sizeof *V_78 , V_154 ) ;
if ( ! V_78 )
return - V_155 ;
V_78 -> V_137 = F_38 ( V_160 , & V_156 ) ;
if ( F_31 ( V_78 -> V_137 ) ) {
V_83 = F_32 ( V_78 -> V_137 ) ;
F_10 ( & V_160 -> V_26 , L_19 , V_83 ) ;
return V_83 ;
}
F_39 ( V_160 , V_78 ) ;
V_83 = F_34 ( & V_160 -> V_26 ,
& V_157 , & V_158 , 1 ) ;
return V_83 ;
}
static int F_40 ( struct V_159 * V_163 )
{
F_36 ( & V_163 -> V_26 ) ;
return 0 ;
}
static int T_4 F_41 ( void )
{
int V_83 = 0 ;
#if F_42 ( V_164 )
V_83 = F_43 ( & V_165 ) ;
if ( V_83 ) {
F_19 ( V_107 L_20 ,
V_83 ) ;
}
#endif
#if F_44 ( V_166 )
V_83 = F_45 ( & V_167 ) ;
if ( V_83 != 0 ) {
F_19 ( V_107 L_21 ,
V_83 ) ;
}
#endif
return V_83 ;
}
static void T_5 F_46 ( void )
{
#if F_42 ( V_164 )
F_47 ( & V_165 ) ;
#endif
#if F_44 ( V_166 )
F_48 ( & V_167 ) ;
#endif
}
