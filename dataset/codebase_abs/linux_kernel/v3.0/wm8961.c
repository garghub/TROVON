static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
return 1 ;
default:
return 0 ;
}
}
static int F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 , V_4 , 0 ) ;
}
static int F_4 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_12 = F_5 ( V_2 , V_13 ) ;
T_1 V_14 = F_5 ( V_2 , V_15 ) ;
T_1 V_16 = F_5 ( V_2 , V_17 ) ;
T_1 V_18 = F_5 ( V_2 , V_6 ) ;
int V_19 = 500 ;
if ( V_11 & V_20 ) {
V_12 &= ~ ( V_21 | V_22 ) ;
F_3 ( V_2 , V_13 , V_12 ) ;
V_14 |= V_23 ;
F_3 ( V_2 , V_15 , V_14 ) ;
F_6 ( 5 ) ;
V_16 |= V_24 | V_25 ;
F_3 ( V_2 , V_17 , V_16 ) ;
V_12 |= V_26 | V_27 ;
F_3 ( V_2 , V_13 , V_12 ) ;
V_12 |= V_28 | V_29 ;
F_3 ( V_2 , V_13 , V_12 ) ;
V_18 |=
V_30 | V_31 |
V_32 | V_33 ;
F_7 ( V_2 -> V_34 , L_1 ) ;
F_3 ( V_2 , V_6 , V_18 ) ;
do {
F_8 ( 1 ) ;
V_18 = F_5 ( V_2 , V_6 ) ;
} while ( -- V_19 &&
V_18 & ( V_31 |
V_33 ) );
if ( V_18 & ( V_31 |
V_33 ) )
F_9 ( V_2 -> V_34 , L_2 ) ;
else
F_7 ( V_2 -> V_34 , L_3 ) ;
V_12 |= V_35 | V_36 ;
F_3 ( V_2 , V_13 , V_12 ) ;
V_12 |= V_21 | V_22 ;
F_3 ( V_2 , V_13 , V_12 ) ;
}
if ( V_11 & V_37 ) {
V_12 &= ~ ( V_21 | V_22 ) ;
F_3 ( V_2 , V_13 , V_12 ) ;
V_12 &= ~ ( V_35 | V_36 ) ;
F_3 ( V_2 , V_13 , V_12 ) ;
V_18 &= ~ ( V_30 |
V_32 ) ;
F_3 ( V_2 , V_6 , V_18 ) ;
V_12 &= ~ ( V_28 | V_26 |
V_29 | V_27 ) ;
F_3 ( V_2 , V_13 , V_12 ) ;
V_16 &= ~ ( V_24 | V_25 ) ;
F_3 ( V_2 , V_17 , V_16 ) ;
F_7 ( V_2 -> V_34 , L_4 ) ;
F_3 ( V_2 , V_15 ,
V_14 & ~ V_23 ) ;
}
return 0 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_9 * V_10 , int V_11 )
{
struct V_1 * V_2 = V_8 -> V_2 ;
T_1 V_16 = F_5 ( V_2 , V_17 ) ;
T_1 V_38 = F_5 ( V_2 , V_39 ) ;
if ( V_11 & V_20 ) {
V_16 |= V_40 | V_41 ;
F_3 ( V_2 , V_17 , V_16 ) ;
V_38 |= V_42 | V_43 ;
F_3 ( V_2 , V_39 , V_38 ) ;
}
if ( V_11 & V_37 ) {
V_38 &= ~ ( V_42 | V_43 ) ;
F_3 ( V_2 , V_39 , V_38 ) ;
V_16 &= ~ ( V_40 | V_41 ) ;
F_3 ( V_2 , V_17 , V_16 ) ;
}
return 0 ;
}
static int F_11 ( struct V_44 * V_45 ,
struct V_46 * V_47 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_50 * V_51 = F_12 ( V_2 ) ;
int V_52 , V_53 , V_54 , V_55 ;
T_1 V_3 ;
V_55 = F_13 ( V_47 ) ;
if ( ! V_51 -> V_56 ) {
F_9 ( V_2 -> V_34 , L_5 ) ;
return - V_57 ;
}
V_53 = 0 ;
for ( V_52 = 0 ; V_52 < F_14 ( V_58 ) ; V_52 ++ ) {
if ( abs ( V_58 [ V_52 ] . V_59 - V_55 ) <
abs ( V_58 [ V_53 ] . V_59 - V_55 ) )
V_53 = V_52 ;
}
V_3 = F_5 ( V_2 , V_60 ) ;
V_3 &= ~ V_61 ;
V_3 |= V_58 [ V_53 ] . V_62 ;
F_3 ( V_2 , V_60 , V_3 ) ;
F_7 ( V_2 -> V_34 , L_6 ,
V_58 [ V_53 ] . V_59 , V_55 ) ;
V_54 = V_51 -> V_56 / V_55 ;
if ( V_45 -> V_63 == V_64 && V_54 < 64 ) {
F_9 ( V_2 -> V_34 ,
L_7 ) ;
return - V_57 ;
}
if ( V_45 -> V_63 == V_65 && V_54 < 256 ) {
F_9 ( V_2 -> V_34 ,
L_8 ) ;
return - V_57 ;
}
for ( V_52 = 0 ; V_52 < F_14 ( V_66 ) ; V_52 ++ ) {
if ( V_66 [ V_52 ] . V_67 >= V_54 )
break;
}
if ( V_52 == F_14 ( V_66 ) ) {
F_9 ( V_2 -> V_34 , L_9 ) ;
return - V_57 ;
}
F_7 ( V_2 -> V_34 , L_10 ,
V_66 [ V_52 ] . V_67 , V_51 -> V_56 , V_55 ,
V_51 -> V_56 / V_55 ) ;
V_3 = F_5 ( V_2 , V_68 ) ;
V_3 &= ~ V_69 ;
V_3 |= V_66 [ V_52 ] . V_62 << V_70 ;
F_3 ( V_2 , V_68 , V_3 ) ;
V_3 = F_5 ( V_2 , V_71 ) ;
V_3 &= ~ V_72 ;
switch ( F_15 ( V_47 ) ) {
case V_73 :
break;
case V_74 :
V_3 |= 1 << V_75 ;
break;
case V_76 :
V_3 |= 2 << V_75 ;
break;
case V_77 :
V_3 |= 3 << V_75 ;
break;
default:
return - V_57 ;
}
F_3 ( V_2 , V_71 , V_3 ) ;
V_3 = F_5 ( V_2 , V_78 ) ;
if ( V_55 <= 24000 )
V_3 |= V_79 ;
else
V_3 &= ~ V_79 ;
F_3 ( V_2 , V_78 , V_3 ) ;
return 0 ;
}
static int F_16 ( struct V_48 * V_49 , int V_80 ,
unsigned int V_81 ,
int V_82 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
struct V_50 * V_51 = F_12 ( V_2 ) ;
T_1 V_3 = F_5 ( V_2 , V_83 ) ;
if ( V_81 > 33000000 ) {
F_9 ( V_2 -> V_34 , L_11 ) ;
return - V_57 ;
}
if ( V_81 > 16500000 ) {
F_7 ( V_2 -> V_34 , L_12 , V_81 ) ;
V_3 |= V_84 ;
V_81 /= 2 ;
} else {
F_7 ( V_2 -> V_34 , L_13 , V_81 ) ;
V_3 &= ~ V_84 ;
}
F_3 ( V_2 , V_83 , V_3 ) ;
V_51 -> V_56 = V_81 ;
return 0 ;
}
static int F_17 ( struct V_48 * V_49 , unsigned int V_85 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_86 = F_5 ( V_2 , V_71 ) ;
V_86 &= ~ ( V_87 | V_88 |
V_89 | V_90 ) ;
switch ( V_85 & V_91 ) {
case V_92 :
V_86 |= V_89 ;
break;
case V_93 :
break;
default:
return - V_57 ;
}
switch ( V_85 & V_94 ) {
case V_95 :
break;
case V_96 :
V_86 |= 1 ;
break;
case V_97 :
V_86 |= 2 ;
break;
case V_98 :
V_86 |= V_88 ;
case V_99 :
V_86 |= 3 ;
switch ( V_85 & V_100 ) {
case V_101 :
case V_102 :
break;
default:
return - V_57 ;
}
break;
default:
return - V_57 ;
}
switch ( V_85 & V_100 ) {
case V_101 :
break;
case V_103 :
V_86 |= V_88 ;
break;
case V_102 :
V_86 |= V_87 ;
break;
case V_104 :
V_86 |= V_87 | V_88 ;
break;
default:
return - V_57 ;
}
return F_3 ( V_2 , V_71 , V_86 ) ;
}
static int F_18 ( struct V_48 * V_49 , int V_105 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_3 = F_5 ( V_2 , V_106 ) ;
if ( V_105 )
V_3 |= V_107 ;
else
V_3 &= ~ V_107 ;
return F_3 ( V_2 , V_106 , V_3 ) ;
}
static int F_19 ( struct V_48 * V_49 , int V_108 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_3 = F_5 ( V_2 , V_109 ) ;
if ( V_108 )
V_3 |= V_110 ;
else
V_3 &= ~ V_110 ;
F_8 ( 17 ) ;
return F_3 ( V_2 , V_109 , V_3 ) ;
}
static int F_20 ( struct V_48 * V_49 , int V_111 , int div )
{
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_3 ;
switch ( V_111 ) {
case V_112 :
V_3 = F_5 ( V_2 , V_113 ) ;
V_3 &= ~ V_114 ;
V_3 |= div ;
F_3 ( V_2 , V_113 , V_3 ) ;
break;
case V_115 :
V_3 = F_5 ( V_2 , V_116 ) ;
V_3 &= ~ V_117 ;
V_3 |= div ;
F_3 ( V_2 , V_116 , V_3 ) ;
break;
default:
return - V_57 ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
enum V_118 V_119 )
{
T_1 V_3 ;
switch ( V_119 ) {
case V_120 :
break;
case V_121 :
if ( V_2 -> V_122 . V_123 == V_124 ) {
V_3 = F_5 ( V_2 , V_125 ) ;
V_3 |= V_126 | V_127 ;
F_3 ( V_2 , V_125 , V_3 ) ;
V_3 = F_5 ( V_2 , V_128 ) ;
V_3 &= ~ V_129 ;
V_3 |= ( 1 << V_130 ) | V_131 ;
F_3 ( V_2 , V_128 , V_3 ) ;
}
break;
case V_124 :
if ( V_2 -> V_122 . V_123 == V_121 ) {
V_3 = F_5 ( V_2 , V_128 ) ;
V_3 &= ~ V_131 ;
F_3 ( V_2 , V_128 , V_3 ) ;
V_3 = F_5 ( V_2 , V_125 ) ;
V_3 &= ~ ( V_126 | V_127 ) ;
F_3 ( V_2 , V_125 , V_3 ) ;
V_3 = F_5 ( V_2 , V_128 ) ;
V_3 &= ~ V_129 ;
F_3 ( V_2 , V_128 , V_3 ) ;
}
break;
case V_132 :
break;
}
V_2 -> V_122 . V_123 = V_119 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_133 * V_122 = & V_2 -> V_122 ;
int V_134 = 0 ;
T_1 V_3 ;
V_134 = F_23 ( V_2 , 8 , 16 , V_135 ) ;
if ( V_134 != 0 ) {
F_9 ( V_2 -> V_34 , L_14 , V_134 ) ;
return V_134 ;
}
V_3 = F_5 ( V_2 , V_4 ) ;
if ( V_3 != 0x1801 ) {
F_9 ( V_2 -> V_34 , L_15 , V_3 ) ;
return - V_57 ;
}
V_3 = V_2 -> V_136 ( V_2 , V_137 ) ;
F_24 ( V_2 -> V_34 , L_16 ,
( V_3 & V_138 ) >> V_139 ,
( ( V_3 & V_140 ) >> V_141 )
+ 'A' ) ;
V_134 = F_2 ( V_2 ) ;
if ( V_134 < 0 ) {
F_9 ( V_2 -> V_34 , L_17 ) ;
return V_134 ;
}
V_3 = F_5 ( V_2 , V_142 ) ;
V_3 |= V_143 ;
F_3 ( V_2 , V_142 , V_3 ) ;
V_3 = F_5 ( V_2 , V_144 ) ;
F_3 ( V_2 , V_144 ,
V_3 | V_145 | V_146 ) ;
F_3 ( V_2 , V_147 , V_3 | V_145 ) ;
V_3 = F_5 ( V_2 , V_148 ) ;
F_3 ( V_2 , V_148 ,
V_3 | V_149 | V_150 ) ;
F_3 ( V_2 , V_151 , V_3 | V_152 ) ;
V_3 = F_5 ( V_2 , V_153 ) ;
F_3 ( V_2 , V_153 , V_3 | V_154 ) ;
V_3 = F_5 ( V_2 , V_137 ) ;
F_3 ( V_2 , V_137 , V_3 | V_155 ) ;
V_3 = F_5 ( V_2 , V_78 ) ;
V_3 |= V_156 ;
F_3 ( V_2 , V_78 , V_3 ) ;
V_3 = F_5 ( V_2 , V_157 ) ;
V_3 &= ~ V_158 ;
F_3 ( V_2 , V_157 , V_3 ) ;
F_21 ( V_2 , V_124 ) ;
F_25 ( V_2 , V_159 ,
F_14 ( V_159 ) ) ;
F_26 ( V_122 , V_160 ,
F_14 ( V_160 ) ) ;
F_27 ( V_122 , V_161 , F_14 ( V_161 ) ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_21 ( V_2 , V_132 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , T_2 V_162 )
{
F_21 ( V_2 , V_132 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 * V_163 = V_2 -> V_163 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < V_2 -> V_164 -> V_165 ; V_52 ++ ) {
if ( V_163 [ V_52 ] == V_166 [ V_52 ] )
continue;
if ( V_52 == V_4 )
continue;
F_3 ( V_2 , V_52 , V_163 [ V_52 ] ) ;
}
F_21 ( V_2 , V_124 ) ;
return 0 ;
}
static T_3 int F_31 ( struct V_167 * V_168 ,
const struct V_169 * V_170 )
{
struct V_50 * V_51 ;
int V_134 ;
V_51 = F_32 ( sizeof( struct V_50 ) , V_171 ) ;
if ( V_51 == NULL )
return - V_172 ;
F_33 ( V_168 , V_51 ) ;
V_134 = F_34 ( & V_168 -> V_34 ,
& V_173 , & V_174 , 1 ) ;
if ( V_134 < 0 )
F_35 ( V_51 ) ;
return V_134 ;
}
static T_4 int F_36 ( struct V_167 * V_175 )
{
F_37 ( & V_175 -> V_34 ) ;
F_35 ( F_38 ( V_175 ) ) ;
return 0 ;
}
static int T_5 F_39 ( void )
{
int V_134 = 0 ;
#if F_40 ( V_176 ) || F_40 ( V_177 )
V_134 = F_41 ( & V_178 ) ;
if ( V_134 != 0 ) {
F_42 ( V_179 L_18 ,
V_134 ) ;
}
#endif
return V_134 ;
}
static void T_6 F_43 ( void )
{
#if F_40 ( V_176 ) || F_40 ( V_177 )
F_44 ( & V_178 ) ;
#endif
}
