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
F_5 ( V_6 , V_22 ,
V_23 , V_24 ) ;
F_5 ( V_6 , V_8 ,
V_25 ,
V_4 -> V_10 . integer . V_10 [ 0 ]
<< V_15 ) ;
F_6 ( V_6 , V_16 , V_11 ) ;
F_6 ( V_6 , V_17 , V_12 ) ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_26 * V_27 = & V_6 -> V_27 ;
F_8 ( V_27 , V_28 ,
F_9 ( V_28 ) ) ;
F_10 ( V_27 , V_29 ,
F_9 ( V_29 ) ) ;
return 0 ;
}
static int F_11 ( struct V_5 * V_6 )
{
return F_6 ( V_6 , V_30 , 0x0 ) ;
}
static int F_12 ( struct V_31 * V_32 , int V_33 )
{
struct V_5 * V_6 = V_32 -> V_6 ;
return F_5 ( V_6 , V_34 ,
V_35 ,
! ! V_33 << V_36 ) ;
}
static int F_13 ( struct V_31 * V_32 , unsigned int V_37 )
{
struct V_5 * V_6 ;
T_1 V_38 , V_39 , V_40 , V_41 ;
V_6 = V_32 -> V_6 ;
switch ( V_37 & V_42 ) {
case V_43 :
V_38 = 0x2 ;
break;
case V_44 :
V_38 = 0x0 ;
break;
case V_45 :
V_38 = 0x1 ;
break;
case V_46 :
case V_47 :
V_38 = 0x3 ;
break;
default:
F_14 ( V_32 -> V_48 , L_1 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_49 ,
V_50 , V_38 << V_51 ) ;
switch ( V_37 & V_52 ) {
case V_53 :
V_39 = 1 ;
break;
case V_54 :
V_39 = 0 ;
break;
default:
F_14 ( V_32 -> V_48 , L_2 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_55 ,
V_56 , V_39 << V_57 ) ;
switch ( V_37 & V_42 ) {
case V_46 :
case V_47 :
switch ( V_37 & V_58 ) {
case V_59 :
case V_60 :
return - V_14 ;
default:
break;
}
break;
default:
break;
}
V_40 = V_41 = 0 ;
switch ( V_37 & V_58 ) {
case V_61 :
break;
case V_59 :
V_40 = V_41 = 1 ;
break;
case V_62 :
V_40 = 1 ;
break;
case V_60 :
V_41 = 1 ;
break;
default:
F_14 ( V_32 -> V_48 , L_3 ) ;
return - V_14 ;
}
F_5 ( V_6 , V_49 ,
V_63 , V_41 << V_64 ) ;
F_5 ( V_6 , V_49 ,
V_65 , V_40 << V_66 ) ;
return 0 ;
}
static int F_15 ( struct V_67 * V_68 ,
struct V_69 * V_70 ,
struct V_31 * V_32 )
{
int V_71 ;
struct V_5 * V_6 ;
struct V_72 * V_73 ;
T_1 V_74 , V_75 ;
unsigned int V_76 ;
int V_77 ;
V_6 = V_32 -> V_6 ;
V_73 = F_16 ( V_6 ) ;
V_73 -> V_78 = F_17 ( V_70 ) ;
if ( ( int ) V_73 -> V_78 < 0 )
return V_73 -> V_78 ;
switch ( F_18 ( V_70 ) ) {
case V_79 :
V_74 = 0x0 ;
break;
case V_80 :
V_74 = 0x1 ;
break;
case V_81 :
V_74 = 0x2 ;
break;
case V_82 :
V_74 = 0x3 ;
break;
default:
F_14 ( V_32 -> V_48 , L_4 ,
F_18 ( V_70 ) ) ;
return - V_14 ;
}
F_5 ( V_6 , V_49 ,
V_83 , V_74 << V_84 ) ;
V_75 = 0 ;
V_77 = abs ( V_85 [ 0 ] - F_19 ( V_70 ) ) ;
for ( V_71 = 1 ; V_71 < F_9 ( V_85 ) ; ++ V_71 ) {
if ( abs ( V_85 [ V_71 ] - F_19 ( V_70 ) ) >= V_77 )
continue;
V_75 = V_71 ;
V_77 = abs ( V_85 [ V_71 ] - F_19 ( V_70 ) ) ;
}
F_20 ( V_32 -> V_48 , L_5 , V_85 [ V_75 ] ) ;
F_5 ( V_6 , V_22 ,
V_86 , V_75 << V_87 ) ;
F_20 ( V_32 -> V_48 , L_6 , V_73 -> V_78 ) ;
F_20 ( V_32 -> V_48 , L_7 , V_73 -> V_88 ) ;
for ( V_71 = 0 ; V_71 < F_9 ( V_89 ) ; ++ V_71 ) {
if ( V_73 -> V_88 / F_19 ( V_70 )
== V_89 [ V_71 ] . V_90 )
break;
}
if ( V_71 == F_9 ( V_89 ) ) {
F_14 ( V_32 -> V_48 , L_8 ,
V_73 -> V_88 , F_19 ( V_70 ) ) ;
return - V_14 ;
}
F_20 ( V_32 -> V_48 , L_9 , V_89 [ V_71 ] . V_90 ) ;
F_5 ( V_6 , V_55 ,
V_91 , V_71 << V_92 ) ;
V_76 = ( V_73 -> V_88 / V_89 [ V_71 ] . div ) * 10 ;
for ( V_71 = 0 ; V_71 < F_9 ( V_93 ) ; ++ V_71 ) {
if ( V_73 -> V_78 == V_76 / V_93 [ V_71 ] )
break;
}
if ( V_71 == F_9 ( V_93 ) ) {
F_14 ( V_32 -> V_48 , L_10 ) ;
return - V_14 ;
}
F_20 ( V_32 -> V_48 , L_11 , V_71 ) ;
F_5 ( V_6 , V_55 ,
V_94 , V_71 << V_95 ) ;
return 0 ;
}
static int F_21 ( struct V_96 * V_96 , unsigned int V_97 ,
unsigned int V_98 )
{
T_2 V_99 ;
unsigned long int V_100 , V_101 , V_102 ;
V_96 -> V_103 = 0 ;
V_101 = V_97 / V_98 ;
if ( V_101 < 6 ) {
V_98 >>= 1 ;
V_96 -> V_103 = 1 ;
V_101 = V_97 / V_98 ;
}
if ( V_101 < 6 || V_101 > 12 ) {
F_22 ( V_104 L_12
L_13 , V_105 , V_101 ) ;
return - V_14 ;
}
V_96 -> V_106 = V_101 ;
V_102 = V_97 % V_98 ;
V_99 = V_107 * ( T_2 ) V_102 ;
F_23 ( V_99 , V_98 ) ;
V_100 = V_99 & 0xffffffff ;
if ( ( V_100 % 10 ) >= 5 )
V_100 += 5 ;
V_100 /= 10 ;
V_96 -> V_108 = V_100 ;
return 0 ;
}
static int F_24 ( struct V_31 * V_32 , int V_109 ,
int V_98 , unsigned int V_110 ,
unsigned int V_111 )
{
int V_112 ;
struct V_5 * V_6 ;
struct V_96 V_96 ;
V_6 = V_32 -> V_6 ;
if ( V_110 && V_111 ) {
V_112 = F_21 ( & V_96 , V_111 * 4 * 2 , V_110 ) ;
if ( V_112 )
return V_112 ;
}
F_5 ( V_6 , V_113 ,
V_114 , 0 ) ;
if ( ! V_110 || ! V_111 )
return 0 ;
F_6 ( V_6 , V_115 ,
( V_96 . V_103 << V_116 )
| V_96 . V_106 ) ;
F_6 ( V_6 , V_117 , V_96 . V_108 & 0x1ff ) ;
F_6 ( V_6 , V_118 , ( V_96 . V_108 >> 9 ) & 0x1ff ) ;
F_6 ( V_6 , V_119 , ( V_96 . V_108 >> 18 ) ) ;
F_5 ( V_6 , V_55 ,
V_120 , V_121 ) ;
F_5 ( V_6 , V_113 ,
V_114 , V_122 ) ;
return 0 ;
}
static int F_25 ( struct V_31 * V_32 ,
int V_123 , unsigned int V_124 , int V_125 )
{
struct V_5 * V_6 ;
struct V_72 * V_73 ;
V_6 = V_32 -> V_6 ;
V_73 = F_16 ( V_6 ) ;
switch ( V_123 ) {
case V_126 :
F_5 ( V_6 , V_55 ,
V_120 , 0 ) ;
F_5 ( V_6 , V_113 ,
V_114 , 0 ) ;
break;
case V_127 :
F_5 ( V_6 , V_55 ,
V_120 , V_121 ) ;
break;
default:
F_14 ( V_32 -> V_48 , L_14 , V_123 ) ;
return - V_14 ;
}
V_73 -> V_88 = V_124 ;
return 0 ;
}
static void F_26 ( struct V_5 * V_6 )
{
short V_71 ;
T_1 * V_128 ;
if ( ! V_6 -> V_129 )
return;
V_6 -> V_130 = 0 ;
V_128 = V_6 -> V_131 ;
for ( V_71 = 0 ; V_71 < V_6 -> V_132 -> V_133 ; V_71 ++ ) {
if ( V_71 == V_30
|| V_128 [ V_71 ] == V_134 [ V_71 ] )
continue;
F_6 ( V_6 , V_71 , V_128 [ V_71 ] ) ;
}
V_6 -> V_129 = 0 ;
}
static int F_27 ( struct V_5 * V_6 ,
enum V_135 V_136 )
{
int V_112 ;
struct V_72 * V_73 ;
V_73 = F_16 ( V_6 ) ;
switch ( V_136 ) {
case V_137 :
case V_138 :
F_5 ( V_6 , V_113 ,
V_139 ,
1 << V_140 ) ;
break;
case V_141 :
if ( V_6 -> V_27 . V_142 == V_143 ) {
V_112 = F_28 ( F_9 ( V_73 -> V_144 ) ,
V_73 -> V_144 ) ;
if ( V_112 ) {
F_14 ( V_6 -> V_48 ,
L_15 ,
V_112 ) ;
return V_112 ;
}
F_26 ( V_6 ) ;
F_5 ( V_6 , V_145 ,
V_146 ,
V_147 ) ;
F_5 ( V_6 , V_148 ,
V_149 , V_150 ) ;
F_5 ( V_6 , V_148 ,
V_151 ,
V_152 ) ;
F_5 ( V_6 , V_113 ,
V_153 , V_154 ) ;
F_5 ( V_6 , V_113 ,
V_139 ,
1 << V_140 ) ;
F_29 ( 500 ) ;
F_5 ( V_6 , V_145 ,
V_146 , 0 ) ;
}
F_5 ( V_6 , V_113 ,
V_139 ,
2 << V_140 ) ;
break;
case V_143 :
F_5 ( V_6 , V_148 ,
V_151 , 0 ) ;
F_5 ( V_6 , V_148 ,
V_149 , 0 ) ;
F_5 ( V_6 , V_113 ,
V_139 | V_153 ,
0 ) ;
F_6 ( V_6 , V_113 , 0 ) ;
F_6 ( V_6 , V_16 , 0 ) ;
F_6 ( V_6 , V_17 , 0 ) ;
V_6 -> V_129 = 1 ;
F_30 ( F_9 ( V_73 -> V_144 ) ,
V_73 -> V_144 ) ;
break;
}
V_6 -> V_27 . V_142 = V_136 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
F_27 ( V_6 , V_143 ) ;
return 0 ;
}
static int F_32 ( struct V_5 * V_6 )
{
F_27 ( V_6 , V_141 ) ;
return 0 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_72 * V_73 ;
V_73 = F_16 ( V_6 ) ;
F_27 ( V_6 , V_143 ) ;
F_34 ( F_9 ( V_73 -> V_144 ) , V_73 -> V_144 ) ;
return 0 ;
}
static int F_35 ( struct V_5 * V_6 )
{
T_3 V_71 ;
struct V_72 * V_73 ;
int V_112 ;
T_1 * V_128 ;
V_73 = F_16 ( V_6 ) ;
V_112 = F_36 ( V_6 , 7 , 9 , V_73 -> V_155 ) ;
if ( V_112 < 0 ) {
F_14 ( V_6 -> V_48 , L_16 , V_112 ) ;
return V_112 ;
}
for ( V_71 = 0 ; V_71 < F_9 ( V_73 -> V_144 ) ; V_71 ++ )
V_73 -> V_144 [ V_71 ] . V_156 = V_157 [ V_71 ] ;
V_112 = F_37 ( V_6 -> V_48 , F_9 ( V_73 -> V_144 ) ,
V_73 -> V_144 ) ;
if ( V_112 ) {
F_14 ( V_6 -> V_48 , L_17 , V_112 ) ;
return V_112 ;
}
V_112 = F_28 ( F_9 ( V_73 -> V_144 ) ,
V_73 -> V_144 ) ;
if ( V_112 ) {
F_14 ( V_6 -> V_48 , L_15 , V_112 ) ;
goto V_158;
}
V_112 = F_11 ( V_6 ) ;
if ( V_112 < 0 ) {
F_14 ( V_6 -> V_48 , L_18 , V_112 ) ;
goto V_159;
}
V_128 = V_6 -> V_131 ;
for ( V_71 = 0 ; V_71 < F_9 ( V_160 ) ; ++ V_71 )
V_128 [ V_160 [ V_71 ] ] |= 0x100 ;
V_128 [ V_161 ] |= V_162 ;
V_6 -> V_129 = 1 ;
F_38 ( V_6 , V_163 ,
F_9 ( V_163 ) ) ;
F_7 ( V_6 ) ;
F_27 ( V_6 , V_141 ) ;
return 0 ;
V_159:
F_30 ( F_9 ( V_73 -> V_144 ) , V_73 -> V_144 ) ;
V_158:
F_34 ( F_9 ( V_73 -> V_144 ) , V_73 -> V_144 ) ;
return V_112 ;
}
static int T_4 F_39 ( struct V_164 * V_165 )
{
struct V_72 * V_73 ;
int V_112 ;
V_73 = F_40 ( sizeof *V_73 , V_166 ) ;
if ( ! V_73 )
return - V_167 ;
V_73 -> V_155 = V_168 ;
F_41 ( V_165 , V_73 ) ;
V_112 = F_42 ( & V_165 -> V_48 ,
& V_169 , & V_170 , 1 ) ;
if ( V_112 < 0 )
F_43 ( V_73 ) ;
return V_112 ;
}
static int T_5 F_44 ( struct V_164 * V_165 )
{
F_45 ( & V_165 -> V_48 ) ;
F_43 ( F_46 ( V_165 ) ) ;
return 0 ;
}
static T_4 int F_47 ( struct V_171 * V_172 ,
const struct V_173 * V_174 )
{
struct V_72 * V_73 ;
int V_112 ;
V_73 = F_40 ( sizeof *V_73 , V_166 ) ;
if ( ! V_73 )
return - V_167 ;
V_73 -> V_155 = V_175 ;
F_48 ( V_172 , V_73 ) ;
V_112 = F_42 ( & V_172 -> V_48 ,
& V_169 , & V_170 , 1 ) ;
if ( V_112 < 0 )
F_43 ( V_73 ) ;
return V_112 ;
}
static T_5 int F_49 ( struct V_171 * V_176 )
{
F_45 ( & V_176 -> V_48 ) ;
F_43 ( F_50 ( V_176 ) ) ;
return 0 ;
}
static int T_6 F_51 ( void )
{
int V_112 = 0 ;
#if F_52 ( V_177 ) || F_52 ( V_178 )
V_112 = F_53 ( & V_179 ) ;
if ( V_112 ) {
F_22 ( V_104 L_19 ,
V_112 ) ;
}
#endif
#if F_52 ( V_180 )
V_112 = F_54 ( & V_181 ) ;
if ( V_112 != 0 ) {
F_22 ( V_104 L_20 ,
V_112 ) ;
}
#endif
return V_112 ;
}
static void T_7 F_55 ( void )
{
#if F_52 ( V_177 ) || F_52 ( V_178 )
F_56 ( & V_179 ) ;
#endif
#if F_52 ( V_180 )
F_57 ( & V_181 ) ;
#endif
}
