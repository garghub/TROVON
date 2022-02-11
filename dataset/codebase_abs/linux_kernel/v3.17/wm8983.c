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
if ( V_7 > V_25 )
return 0 ;
return V_26 [ V_7 ] . V_27 != 0 ;
}
static int F_8 ( struct V_28 * V_29 , int V_30 )
{
struct V_5 * V_6 = V_29 -> V_6 ;
return F_5 ( V_6 , V_31 ,
V_32 ,
! ! V_30 << V_33 ) ;
}
static int F_9 ( struct V_28 * V_29 , unsigned int V_34 )
{
struct V_5 * V_6 = V_29 -> V_6 ;
T_1 V_35 , V_36 , V_37 , V_38 ;
switch ( V_34 & V_39 ) {
case V_40 :
V_35 = 0x2 ;
break;
case V_41 :
V_35 = 0x0 ;
break;
case V_42 :
V_35 = 0x1 ;
break;
case V_43 :
case V_44 :
V_35 = 0x3 ;
break;
default:
F_10 ( V_29 -> V_24 , L_1 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_45 ,
V_46 , V_35 << V_47 ) ;
switch ( V_34 & V_48 ) {
case V_49 :
V_36 = 1 ;
break;
case V_50 :
V_36 = 0 ;
break;
default:
F_10 ( V_29 -> V_24 , L_2 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_51 ,
V_52 , V_36 << V_53 ) ;
switch ( V_34 & V_39 ) {
case V_43 :
case V_44 :
F_10 ( V_29 -> V_24 , L_3 ) ;
return - V_14 ;
default:
break;
}
V_37 = V_38 = 0 ;
switch ( V_34 & V_54 ) {
case V_55 :
break;
case V_56 :
V_37 = V_38 = 1 ;
break;
case V_57 :
V_37 = 1 ;
break;
case V_58 :
V_38 = 1 ;
break;
default:
F_10 ( V_29 -> V_24 , L_4 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_45 ,
V_59 , V_38 << V_60 ) ;
F_5 ( V_6 , V_45 ,
V_61 , V_37 << V_62 ) ;
return 0 ;
}
static int F_11 ( struct V_63 * V_64 ,
struct V_65 * V_66 ,
struct V_28 * V_29 )
{
int V_67 ;
struct V_5 * V_6 = V_29 -> V_6 ;
struct V_68 * V_69 = F_12 ( V_6 ) ;
T_1 V_70 , V_71 ;
T_2 V_72 ;
int V_73 ;
int V_74 ;
V_74 = F_13 ( V_66 ) ;
if ( V_74 < 0 ) {
F_10 ( V_6 -> V_24 , L_5 , V_74 ) ;
return V_74 ;
}
V_69 -> V_75 = V_74 ;
switch ( F_14 ( V_66 ) ) {
case 16 :
V_70 = 0x0 ;
break;
case 20 :
V_70 = 0x1 ;
break;
case 24 :
V_70 = 0x2 ;
break;
case 32 :
V_70 = 0x3 ;
break;
default:
F_10 ( V_29 -> V_24 , L_6 ,
F_14 ( V_66 ) ) ;
return - V_14 ;
}
F_5 ( V_6 , V_45 ,
V_76 , V_70 << V_77 ) ;
V_71 = 0 ;
V_73 = abs ( V_78 [ 0 ] - F_15 ( V_66 ) ) ;
for ( V_67 = 1 ; V_67 < F_16 ( V_78 ) ; ++ V_67 ) {
if ( abs ( V_78 [ V_67 ] - F_15 ( V_66 ) ) >= V_73 )
continue;
V_71 = V_67 ;
V_73 = abs ( V_78 [ V_67 ] - F_15 ( V_66 ) ) ;
}
F_17 ( V_29 -> V_24 , L_7 , V_78 [ V_71 ] ) ;
F_5 ( V_6 , V_79 ,
V_80 , V_71 << V_81 ) ;
F_17 ( V_29 -> V_24 , L_8 , V_69 -> V_75 ) ;
F_17 ( V_29 -> V_24 , L_9 , V_69 -> V_82 ) ;
for ( V_67 = 0 ; V_67 < F_16 ( V_83 ) ; ++ V_67 ) {
if ( V_69 -> V_82 / F_15 ( V_66 )
== V_83 [ V_67 ] . V_84 )
break;
}
if ( V_67 == F_16 ( V_83 ) ) {
F_10 ( V_29 -> V_24 , L_10 ,
V_69 -> V_82 , F_15 ( V_66 ) ) ;
return - V_14 ;
}
F_17 ( V_29 -> V_24 , L_11 , V_83 [ V_67 ] . V_84 ) ;
F_5 ( V_6 , V_51 ,
V_85 , V_67 << V_86 ) ;
V_72 = ( V_69 -> V_82 / V_83 [ V_67 ] . div ) * 10 ;
for ( V_67 = 0 ; V_67 < F_16 ( V_87 ) ; ++ V_67 ) {
if ( V_69 -> V_75 == V_72 / V_87 [ V_67 ] )
break;
}
if ( V_67 == F_16 ( V_87 ) ) {
F_10 ( V_29 -> V_24 , L_12 ) ;
return - V_14 ;
}
F_17 ( V_29 -> V_24 , L_13 , V_67 ) ;
F_5 ( V_6 , V_51 ,
V_88 , V_67 << V_89 ) ;
return 0 ;
}
static int F_18 ( struct V_90 * V_90 , unsigned int V_91 ,
unsigned int V_92 )
{
T_3 V_93 ;
unsigned long int V_94 , V_95 , V_96 ;
V_90 -> V_97 = 0 ;
V_95 = V_91 / V_92 ;
if ( V_95 < 6 ) {
V_92 >>= 1 ;
V_90 -> V_97 = 1 ;
V_95 = V_91 / V_92 ;
}
if ( V_95 < 6 || V_95 > 12 ) {
F_19 ( V_98 L_14
L_15 , V_99 , V_95 ) ;
return - V_14 ;
}
V_90 -> V_100 = V_95 ;
V_96 = V_91 % V_92 ;
V_93 = V_101 * ( T_3 ) V_96 ;
F_20 ( V_93 , V_92 ) ;
V_94 = V_93 & 0xffffffff ;
if ( ( V_94 % 10 ) >= 5 )
V_94 += 5 ;
V_94 /= 10 ;
V_90 -> V_102 = V_94 ;
return 0 ;
}
static int F_21 ( struct V_28 * V_29 , int V_103 ,
int V_92 , unsigned int V_104 ,
unsigned int V_105 )
{
int V_74 ;
struct V_5 * V_6 ;
struct V_90 V_90 ;
V_6 = V_29 -> V_6 ;
if ( ! V_104 || ! V_105 ) {
F_5 ( V_6 , V_106 ,
V_107 , 0 ) ;
return 0 ;
} else {
V_74 = F_18 ( & V_90 , V_105 * 4 * 2 , V_104 ) ;
if ( V_74 )
return V_74 ;
F_5 ( V_6 , V_106 ,
V_107 , 0 ) ;
F_6 ( V_6 , V_108 ,
( V_90 . V_97 << V_109 )
| V_90 . V_100 ) ;
F_6 ( V_6 , V_110 , V_90 . V_102 & 0x1ff ) ;
F_6 ( V_6 , V_111 , ( V_90 . V_102 >> 9 ) & 0x1ff ) ;
F_6 ( V_6 , V_112 , ( V_90 . V_102 >> 18 ) ) ;
F_5 ( V_6 , V_106 ,
V_107 , V_113 ) ;
}
return 0 ;
}
static int F_22 ( struct V_28 * V_29 ,
int V_114 , unsigned int V_115 , int V_116 )
{
struct V_5 * V_6 = V_29 -> V_6 ;
struct V_68 * V_69 = F_12 ( V_6 ) ;
switch ( V_114 ) {
case V_117 :
F_5 ( V_6 , V_51 ,
V_118 , 0 ) ;
break;
case V_119 :
F_5 ( V_6 , V_51 ,
V_118 , V_120 ) ;
break;
default:
F_10 ( V_29 -> V_24 , L_16 , V_114 ) ;
return - V_14 ;
}
V_69 -> V_82 = V_115 ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
enum V_121 V_122 )
{
struct V_68 * V_69 = F_12 ( V_6 ) ;
int V_74 ;
switch ( V_122 ) {
case V_123 :
case V_124 :
F_5 ( V_6 , V_106 ,
V_125 ,
1 << V_126 ) ;
break;
case V_127 :
if ( V_6 -> V_128 . V_129 == V_130 ) {
V_74 = F_24 ( V_69 -> V_131 ) ;
if ( V_74 < 0 ) {
F_10 ( V_6 -> V_24 , L_17 , V_74 ) ;
return V_74 ;
}
F_5 ( V_6 , V_132 ,
V_133 | V_134 ,
V_135 | V_136 ) ;
F_5 ( V_6 , V_137 ,
V_138 , V_139 ) ;
F_5 ( V_6 , V_106 ,
V_140 , V_141 ) ;
F_5 ( V_6 , V_106 ,
V_125 ,
1 << V_126 ) ;
F_25 ( 250 ) ;
F_5 ( V_6 , V_132 ,
V_133 |
V_134 , 0 ) ;
}
F_5 ( V_6 , V_106 ,
V_125 ,
2 << V_126 ) ;
break;
case V_130 :
F_5 ( V_6 , V_137 ,
V_138 , 0 ) ;
F_5 ( V_6 , V_106 ,
V_125 | V_140 ,
0 ) ;
F_25 ( 100 ) ;
F_6 ( V_6 , V_106 , 0 ) ;
F_6 ( V_6 , V_16 , 0 ) ;
F_6 ( V_6 , V_17 , 0 ) ;
break;
}
V_6 -> V_128 . V_129 = V_122 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 )
{
F_23 ( V_6 , V_130 ) ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 )
{
F_23 ( V_6 , V_127 ) ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 )
{
F_23 ( V_6 , V_130 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
int V_74 ;
int V_67 ;
V_74 = F_6 ( V_6 , V_142 , 0 ) ;
if ( V_74 < 0 ) {
F_10 ( V_6 -> V_24 , L_18 , V_74 ) ;
return V_74 ;
}
for ( V_67 = 0 ; V_67 < F_16 ( V_143 ) ; ++ V_67 )
F_5 ( V_6 , V_143 [ V_67 ] ,
0x100 , 0x100 ) ;
for ( V_67 = V_144 ;
V_67 <= V_145 ; ++ V_67 )
F_5 ( V_6 , V_67 , 0x40 , 0x40 ) ;
F_5 ( V_6 , V_31 ,
V_32 ,
V_146 ) ;
F_5 ( V_6 , V_147 ,
V_148 , V_148 ) ;
return 0 ;
}
static int F_30 ( struct V_149 * V_150 )
{
struct V_68 * V_69 ;
int V_74 ;
V_69 = F_31 ( & V_150 -> V_24 , sizeof *V_69 , V_151 ) ;
if ( ! V_69 )
return - V_152 ;
V_69 -> V_131 = F_32 ( V_150 , & V_153 ) ;
if ( F_33 ( V_69 -> V_131 ) ) {
V_74 = F_34 ( V_69 -> V_131 ) ;
F_10 ( & V_150 -> V_24 , L_19 , V_74 ) ;
return V_74 ;
}
F_35 ( V_150 , V_69 ) ;
V_74 = F_36 ( & V_150 -> V_24 ,
& V_154 , & V_155 , 1 ) ;
return V_74 ;
}
static int F_37 ( struct V_149 * V_150 )
{
F_38 ( & V_150 -> V_24 ) ;
return 0 ;
}
static int F_39 ( struct V_156 * V_157 ,
const struct V_158 * V_159 )
{
struct V_68 * V_69 ;
int V_74 ;
V_69 = F_31 ( & V_157 -> V_24 , sizeof *V_69 , V_151 ) ;
if ( ! V_69 )
return - V_152 ;
V_69 -> V_131 = F_40 ( V_157 , & V_153 ) ;
if ( F_33 ( V_69 -> V_131 ) ) {
V_74 = F_34 ( V_69 -> V_131 ) ;
F_10 ( & V_157 -> V_24 , L_19 , V_74 ) ;
return V_74 ;
}
F_41 ( V_157 , V_69 ) ;
V_74 = F_36 ( & V_157 -> V_24 ,
& V_154 , & V_155 , 1 ) ;
return V_74 ;
}
static int F_42 ( struct V_156 * V_160 )
{
F_38 ( & V_160 -> V_24 ) ;
return 0 ;
}
static int T_4 F_43 ( void )
{
int V_74 = 0 ;
#if F_44 ( V_161 )
V_74 = F_45 ( & V_162 ) ;
if ( V_74 ) {
F_19 ( V_98 L_20 ,
V_74 ) ;
}
#endif
#if F_46 ( V_163 )
V_74 = F_47 ( & V_164 ) ;
if ( V_74 != 0 ) {
F_19 ( V_98 L_21 ,
V_74 ) ;
}
#endif
return V_74 ;
}
static void T_5 F_48 ( void )
{
#if F_44 ( V_161 )
F_49 ( & V_162 ) ;
#endif
#if F_46 ( V_163 )
F_50 ( & V_164 ) ;
#endif
}
