static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 + V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 + V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_10 ;
return V_11 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_12 ;
return V_13 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_14 ;
return V_15 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_16 | V_17 ;
return V_18 | V_19 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_20 | V_21 ;
return V_22 | V_23 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_20 | V_17 ;
return V_22 | V_19 ;
}
static bool F_11 ( struct V_1 * V_2 )
{
return ! ! ( F_12 ( V_2 -> V_5 + V_24 ) &
V_25 ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned V_26 ,
unsigned V_27 )
{
F_3 ( V_2 , F_14 ( V_26 ) ,
V_28 ) ;
F_1 ( V_2 , F_15 ( V_26 , V_27 ) , V_28 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned V_27 )
{
F_4 ( V_2 , V_29 |
F_17 ( V_2 -> V_30 - 1 ) ,
F_18 ( V_27 ) ) ;
F_3 ( V_2 , V_31 , F_18 ( V_27 ) ) ;
F_4 ( V_2 , F_19 ( 1 << V_27 ) |
F_20 ( 0 ) |
F_21 ( V_2 -> V_30 - 1 ) |
F_22 ( V_2 -> V_32 - 1 ) ,
F_23 ( 3 ) ) ;
F_3 ( V_2 , F_24 ( V_27 ) , V_33 ) ;
F_4 (
V_2 ,
F_19 ( 0 ) |
F_20 ( F_25 ( 3 ) ) |
V_34 |
F_22 ( V_2 -> V_35 ) ,
F_23 ( 2 ) ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned V_36 ,
unsigned V_37 )
{
T_1 V_4 ;
V_4 = V_29 |
F_17 ( V_2 -> V_30 - 1 ) ;
F_4 ( V_2 , V_4 , F_18 ( V_36 ) ) ;
F_4 ( V_2 , V_4 , F_18 ( V_37 ) ) ;
F_3 ( V_2 , V_31 , F_18 ( V_36 ) ) ;
F_3 ( V_2 , V_31 , F_18 ( V_37 ) ) ;
F_4 (
V_2 ,
F_19 ( 1 << V_36 ) |
F_19 ( 1 << V_37 ) |
F_20 ( 0 ) |
F_21 ( V_2 -> V_30 - 1 ) |
F_22 ( V_2 -> V_32 - 1 ) ,
F_23 ( 3 ) ) ;
F_3 ( V_2 , F_24 ( V_37 ) , V_33 ) ;
F_4 (
V_2 ,
F_19 ( 0 ) |
F_20 ( F_25 ( 3 ) ) |
V_34 |
F_22 ( V_2 -> V_35 ) , F_23 ( 2 ) ) ;
}
static unsigned F_27 ( struct V_1 * V_2 ,
unsigned V_38 )
{
T_1 V_4 ;
unsigned V_39 , V_3 ;
V_4 = F_12 ( V_2 -> V_5 + F_18 ( V_38 ) ) ;
if ( V_4 & V_29 )
V_39 = V_2 -> V_30 ;
else
V_39 = 1 ;
V_3 = ( V_4 & V_31 ) >> V_40 ;
return V_3 / V_39 ;
}
static unsigned F_28 ( struct V_1 * V_2 ,
unsigned V_36 , unsigned V_37 )
{
T_1 V_4 , V_41 ;
unsigned V_42 , V_43 , V_44 ;
V_41 = F_24 ( V_36 ) | F_24 ( V_37 ) ;
V_4 = F_12 ( V_2 -> V_5 + V_33 ) & V_41 ;
while ( V_4 != V_41 ) {
V_4 = F_12 ( V_2 -> V_5 + V_33 ) & V_41 ;
F_29 ( V_2 -> V_45 , L_1 , V_4 ) ;
}
V_43 = F_27 ( V_2 , V_36 ) ;
V_44 = F_27 ( V_2 , V_37 ) ;
if ( V_44 == 0 ) {
F_30 ( V_2 -> V_45 , L_2 ) ;
return 1 << ( V_46 - 1 ) ;
}
V_42 = V_43 ;
V_42 *= ( 1 << V_46 ) ;
V_42 /= V_44 ;
F_29 ( V_2 -> V_45 , L_3 , V_42 ) ;
return V_42 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_47 ) ;
F_1 ( V_2 , F_7 ( V_2 ) ,
V_47 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_47 ) ;
F_1 ( V_2 , F_8 ( V_2 ) , V_47 ) ;
V_2 -> V_48 = V_49 ;
F_13 ( V_2 , V_50 , V_51 ) ;
F_16 ( V_2 , V_50 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_47 ) ;
F_1 ( V_2 , F_9 ( V_2 ) , V_47 ) ;
V_2 -> V_48 = V_52 ;
F_13 ( V_2 , V_50 , V_53 ) ;
F_16 ( V_2 , V_50 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_47 ) ;
F_1 ( V_2 , F_10 ( V_2 ) , V_47 ) ;
V_2 -> V_48 = V_54 ;
F_13 ( V_2 , V_50 , V_55 ) ;
F_13 ( V_2 , V_56 , V_57 ) ;
F_26 ( V_2 , V_56 ,
V_50 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_58 ) {
F_3 ( V_2 , V_59 ,
V_47 ) ;
if ( V_2 -> V_60 == V_61 )
F_1 ( V_2 ,
V_59 ,
V_47 ) ;
}
F_31 ( V_2 ) ;
V_2 -> V_48 = V_62 ;
F_3 ( V_2 , V_63 |
V_64 , V_33 ) ;
F_1 ( V_2 , V_64 , V_33 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_3 ( V_2 ,
V_64 ,
V_33 ) ;
F_1 ( V_2 ,
F_37 ( V_50 ) ,
V_33 ) ;
F_33 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_65 , V_66 , V_2 -> V_67 ) ;
F_39 ( V_2 -> V_65 , V_68 , V_2 -> V_69 ) ;
F_39 ( V_2 -> V_65 , V_70 , V_2 -> V_71 ) ;
F_40 ( V_2 -> V_65 , V_72 , 1 ) ;
F_41 ( V_2 -> V_65 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
V_2 -> V_48 = V_73 ;
F_4 ( V_2 , 0 , F_18 ( V_50 ) ) ;
F_3 ( V_2 ,
F_24 ( V_50 ) |
F_24 ( V_56 ) ,
V_33 ) ;
F_4 (
V_2 ,
F_19 ( 1 << V_50 ) |
V_34 | F_22 ( 10 ) ,
F_23 ( 2 ) ) ;
}
static void F_43 ( struct V_1 * V_2 , bool V_74 )
{
if ( V_74 && F_11 ( V_2 ) ) {
V_2 -> V_75 = true ;
F_38 ( V_2 ) ;
}
if ( F_11 ( V_2 ) ) {
F_33 ( V_2 ) ;
return;
}
if ( V_2 -> V_75 ) {
V_2 -> V_75 = false ;
F_40 ( V_2 -> V_65 , V_72 , 0 ) ;
F_41 ( V_2 -> V_65 ) ;
}
V_2 -> V_48 = V_62 ;
F_4 ( V_2 , 0 , F_23 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_23 ( 3 ) ) ;
F_3 ( V_2 ,
V_63 |
F_37 ( V_50 ) |
F_24 ( V_50 ) ,
V_33 ) ;
F_1 ( V_2 , V_64 , V_33 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_48 ) {
case V_62 :
if ( F_11 ( V_2 ) )
F_36 ( V_2 ) ;
F_3 ( V_2 , V_63 ,
V_33 ) ;
return;
case V_52 :
V_2 -> V_69 =
F_27 ( V_2 ,
V_50 ) ;
F_32 ( V_2 ) ;
return;
case V_49 :
V_2 -> V_67 =
F_27 ( V_2 ,
V_50 ) ;
F_34 ( V_2 ) ;
return;
case V_54 :
V_2 -> V_71 =
F_28 ( V_2 ,
V_56 ,
V_50 ) ;
F_42 ( V_2 ) ;
return;
case V_73 :
F_43 ( V_2 , 1 ) ;
break;
}
}
static int F_45 ( struct V_76 * V_76 , int V_77 , int * V_3 )
{
struct V_1 * V_2 = F_46 ( V_76 ) ;
int V_78 ;
V_78 = F_47 ( & V_2 -> V_79 ) ;
if ( ! V_78 )
return - V_80 ;
F_48 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_8 == V_58 )
F_3 ( V_2 , F_37 ( 0 ) ,
V_33 ) ;
F_3 ( V_2 , 0x1 , V_47 ) ;
if ( F_49 ( V_77 , & V_2 -> V_82 ) )
F_1 ( V_2 ,
1 << V_83 ,
V_84 ) ;
else
F_3 ( V_2 ,
1 << V_83 ,
V_84 ) ;
F_3 ( V_2 , F_14 ( 0 ) ,
V_28 ) ;
F_1 ( V_2 , V_77 , V_28 ) ;
F_4 ( V_2 , 0 , F_18 ( 0 ) ) ;
F_1 ( V_2 , F_37 ( 0 ) , V_33 ) ;
F_1 ( V_2 , F_25 ( 0 ) , V_47 ) ;
V_78 = F_50 ( & V_2 -> V_81 , V_85 ) ;
if ( ! V_78 )
V_78 = - V_86 ;
if ( V_78 < 0 )
goto V_87;
* V_3 = F_12 ( V_2 -> V_5 + F_18 ( 0 ) ) & V_31 ;
V_78 = V_88 ;
V_87:
F_3 ( V_2 , F_37 ( 0 ) , V_33 ) ;
F_51 ( & V_2 -> V_79 ) ;
return V_78 ;
}
static int F_52 ( struct V_76 * V_76 , int * V_3 )
{
int V_78 , V_89 , V_90 ;
V_78 = F_45 ( V_76 , 8 , & V_89 ) ;
if ( V_78 != V_88 )
return V_78 ;
V_78 = F_45 ( V_76 , 9 , & V_90 ) ;
if ( V_78 != V_88 )
return V_78 ;
* V_3 = V_90 - V_89 ;
return V_88 ;
}
static int F_53 ( struct V_76 * V_76 ,
const struct V_91 * V_77 ,
int * V_3 , int * V_92 , long V_93 )
{
struct V_1 * V_2 = F_46 ( V_76 ) ;
switch ( V_93 ) {
case V_94 :
if ( V_77 -> type == V_95 )
return F_52 ( V_76 , V_3 ) ;
return F_45 ( V_76 , V_77 -> V_38 , V_3 ) ;
case V_96 :
if ( V_77 -> type == V_95 ) {
* V_3 = 0 ;
* V_92 = 253000 ;
return V_97 ;
}
* V_3 = V_2 -> V_98 [ V_77 -> V_38 ] ;
* V_92 = V_77 -> V_99 . V_100 -
F_49 ( V_77 -> V_38 , & V_2 -> V_82 ) ;
return V_101 ;
case V_102 :
if ( V_77 -> type == V_95 ) {
* V_3 = - 1079 ;
* V_92 = 644268 ;
return V_97 ;
}
return - V_103 ;
default:
break;
}
return - V_103 ;
}
static int F_54 ( struct V_76 * V_76 ,
const struct V_91 * V_77 ,
int V_3 , int V_92 , long V_93 )
{
struct V_1 * V_2 = F_46 ( V_76 ) ;
struct V_104 * V_105 =
V_2 -> V_105 [ V_77 -> V_38 ] ;
int V_78 ;
V_78 = F_47 ( & V_2 -> V_79 ) ;
if ( ! V_78 )
return - V_80 ;
switch ( V_93 ) {
case V_96 :
V_78 = - V_103 ;
if ( V_3 == V_105 [ V_106 ] . integer &&
V_92 == V_105 [ V_106 ] . V_107 ) {
F_55 ( V_77 -> V_38 , & V_2 -> V_82 ) ;
V_78 = 0 ;
} else if ( V_3 == V_105 [ V_108 ] . integer &&
V_92 == V_105 [ V_108 ] . V_107 ) {
F_56 ( V_77 -> V_38 , & V_2 -> V_82 ) ;
V_78 = 0 ;
}
break;
default:
V_78 = - V_103 ;
break;
}
F_51 ( & V_2 -> V_79 ) ;
return V_78 ;
}
static int F_57 ( struct V_76 * V_76 ,
const struct V_91 * V_77 ,
long V_93 )
{
return V_109 ;
}
static T_2 F_58 ( struct V_110 * V_45 ,
struct V_111 * V_112 ,
char * V_113 ,
int V_27 )
{
struct V_76 * V_114 = F_59 ( V_45 ) ;
struct V_1 * V_2 = F_46 ( V_114 ) ;
int V_115 , V_116 = 0 ;
for ( V_115 = 0 ; V_115 < F_60 ( V_2 -> V_105 [ V_27 ] ) ; V_115 ++ )
V_116 += sprintf ( V_113 + V_116 , L_4 ,
V_2 -> V_105 [ V_27 ] [ V_115 ] . integer ,
V_2 -> V_105 [ V_27 ] [ V_115 ] . V_107 ) ;
V_116 += sprintf ( V_113 + V_116 , L_5 ) ;
return V_116 ;
}
static T_2 F_61 ( struct V_110 * V_45 ,
struct V_111 * V_112 ,
char * V_113 )
{
struct V_117 * V_118 = F_62 ( V_112 ) ;
return F_58 ( V_45 , V_112 , V_113 ,
V_118 -> V_119 ) ;
}
static int F_63 ( struct V_120 * V_45 )
{
struct V_1 * V_2 = F_64 ( V_45 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_64 |
F_37 ( V_50 ) |
F_37 ( V_56 ) , V_33 ) ;
F_3 ( V_2 , F_5 ( V_2 ) , V_47 ) ;
}
static void F_66 ( struct V_120 * V_45 )
{
struct V_1 * V_2 = F_64 ( V_45 ) ;
F_65 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_120 * V_121 ;
struct V_110 * V_45 = V_2 -> V_45 ;
if ( ! V_2 -> V_60 )
return 0 ;
V_121 = F_68 ( V_45 ) ;
if ( ! V_121 )
return - V_122 ;
V_121 -> V_123 = V_124 ;
V_121 -> V_125 . V_126 = V_127 ;
V_121 -> V_128 = F_63 ;
V_121 -> V_129 = F_66 ;
F_69 ( V_130 , V_121 -> V_131 ) ;
F_69 ( V_132 , V_121 -> V_131 ) ;
F_69 ( V_72 , V_121 -> V_133 ) ;
F_69 ( V_134 , V_121 -> V_135 ) ;
F_70 ( V_121 , V_66 , 0 , V_136 , 0 , 0 ) ;
F_70 ( V_121 , V_68 , 0 , V_136 , 0 , 0 ) ;
F_70 ( V_121 , V_70 , 0 , V_136 ,
0 , 0 ) ;
V_2 -> V_65 = V_121 ;
F_71 ( V_121 , V_2 ) ;
return F_72 ( V_121 ) ;
}
static T_3 F_73 ( int V_137 , void * V_138 )
{
struct V_76 * V_114 = V_138 ;
struct V_1 * V_2 = F_46 ( V_114 ) ;
unsigned long V_4 = F_12 ( V_2 -> V_5 + V_33 ) ;
T_1 V_139 = F_6 ( V_2 ) ;
const T_1 V_140 =
V_63 |
F_24 ( V_50 ) |
F_24 ( V_56 ) ;
if ( ! ( V_4 & F_6 ( V_2 ) ) )
return V_141 ;
if ( V_2 -> V_60 && ( V_4 & V_140 ) ) {
F_44 ( V_2 ) ;
V_139 &= ~ ( F_24 ( V_50 ) |
F_24 ( V_56 ) ) ;
}
if ( F_74 ( V_114 ) ) {
if ( V_4 & V_2 -> V_142 )
F_75 ( V_114 -> V_143 ) ;
} else if ( V_4 & F_24 ( 0 ) ) {
F_76 ( & V_2 -> V_81 ) ;
}
F_3 ( V_2 , V_4 & V_139 , V_33 ) ;
return V_144 ;
}
static T_3 F_77 ( int V_137 , void * V_145 )
{
struct V_146 * V_147 = V_145 ;
struct V_76 * V_114 = V_147 -> V_148 ;
struct V_1 * V_2 = F_46 ( V_114 ) ;
const T_1 V_149 = V_29 |
( ( V_150 - 1 ) << V_151 ) ;
unsigned int V_115 , V_152 = 0 ;
F_78 (i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_2 -> V_153 [ V_152 ] = F_12 ( V_2 -> V_5 + F_18 ( V_152 ) ) ;
F_4 ( V_2 , V_149 , F_18 ( V_152 ) ) ;
V_2 -> V_153 [ V_152 ] &= V_31 ;
V_2 -> V_153 [ V_152 ] /= V_150 ;
V_152 ++ ;
}
F_79 ( V_114 , V_2 -> V_153 , V_147 -> V_154 ) ;
F_80 ( V_114 -> V_143 ) ;
return V_144 ;
}
static int F_81 ( struct V_155 * V_143 , bool V_156 )
{
struct V_76 * V_114 = F_82 ( V_143 ) ;
struct V_1 * V_2 = F_46 ( V_114 ) ;
const T_1 V_157 = V_156 ? V_6 : V_7 ;
F_4 ( V_2 , V_34 , F_23 ( 0 ) + V_157 ) ;
return 0 ;
}
static int F_83 ( struct V_76 * V_114 )
{
int V_78 ;
struct V_155 * V_143 ;
struct V_1 * V_2 = F_46 ( V_114 ) ;
V_143 = F_84 ( L_6 , V_114 -> V_123 , V_114 -> V_125 ) ;
if ( ! V_143 )
return - V_122 ;
V_143 -> V_45 . V_158 = V_2 -> V_45 ;
F_85 ( V_143 , V_114 ) ;
V_143 -> V_159 = & V_160 ;
V_78 = F_86 ( V_143 ) ;
if ( V_78 ) {
F_87 ( V_143 ) ;
return V_78 ;
}
V_2 -> V_143 = V_143 ;
return 0 ;
}
static void F_88 ( struct V_76 * V_114 )
{
struct V_1 * V_2 = F_46 ( V_114 ) ;
F_89 ( V_2 -> V_143 ) ;
F_87 ( V_2 -> V_143 ) ;
}
static int F_90 ( struct V_76 * V_114 )
{
struct V_1 * V_2 = F_46 ( V_114 ) ;
int V_78 = 0 , V_77 , V_161 = 0 ;
unsigned long V_162 = 0 ;
T_1 V_163 = 0 ;
T_1 V_164 = 0 ;
T_1 V_165 = 0 ;
const T_1 V_149 = V_29 |
( ( V_150 - 1 ) << V_151 ) ;
const int V_116 = F_91 ( V_114 -> V_166 ,
V_167 ) ;
if ( ! V_116 )
return - V_103 ;
V_78 = F_47 ( & V_2 -> V_79 ) ;
if ( ! V_78 )
return - V_80 ;
V_2 -> V_153 = F_92 ( V_116 , sizeof( * V_2 -> V_153 ) , V_168 ) ;
if ( ! V_2 -> V_153 ) {
V_78 = - V_122 ;
goto V_169;
}
if ( V_2 -> V_8 == V_58 )
F_3 (
V_2 ,
V_2 -> V_142 << V_170 ,
V_33 ) ;
F_3 ( V_2 , V_2 -> V_142 , V_47 ) ;
F_78 (chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_163 |= V_77 << F_93 ( V_161 ) ;
V_164 |= F_14 ( V_161 ) ;
V_165 |= F_37 ( V_161 ) ;
F_4 ( V_2 , V_149 , F_18 ( V_161 ) ) ;
F_94 ( & V_162 , V_161 , 1 ) ;
V_161 ++ ;
}
F_3 ( V_2 , V_171 |
V_34 , F_23 ( 0 ) ) ;
F_3 ( V_2 , V_164 , V_28 ) ;
F_1 ( V_2 , V_163 , V_28 ) ;
F_1 ( V_2 , V_165 , V_33 ) ;
F_1 ( V_2 , V_162 << V_172 ,
F_23 ( 0 ) ) ;
return 0 ;
V_169:
F_51 ( & V_2 -> V_79 ) ;
return V_78 ;
}
static int F_95 ( struct V_76 * V_114 )
{
struct V_1 * V_2 = F_46 ( V_114 ) ;
F_3 ( V_2 , V_171 |
V_34 , F_23 ( 0 ) ) ;
F_3 ( V_2 , V_2 -> V_142 , V_47 ) ;
if ( V_2 -> V_8 == V_58 )
F_3 (
V_2 ,
V_2 -> V_142 << V_170 ,
V_33 ) ;
F_96 ( V_2 -> V_153 ) ;
F_51 ( & V_2 -> V_79 ) ;
return 0 ;
}
static bool F_97 ( struct V_76 * V_114 ,
const unsigned long * V_41 )
{
struct V_1 * V_2 = F_46 ( V_114 ) ;
const int V_173 = F_91 ( V_41 , V_167 ) ;
int V_174 = 0 ;
unsigned long V_175 = 0 ;
if ( V_2 -> V_176 )
V_175 |= V_177 ;
if ( V_2 -> V_60 == V_178 )
V_175 |= V_179 ;
if ( V_2 -> V_60 == V_61 )
V_175 |= V_180 ;
if ( V_2 -> V_176 )
V_174 ++ ;
if ( V_2 -> V_60 )
V_174 += 2 ;
if ( F_98 ( V_41 , & V_175 , V_167 ) )
return false ;
if ( V_173 + V_174 > V_181 )
return false ;
return true ;
}
static void F_99 ( struct V_1 * V_2 )
{
const T_1 V_182 =
( 1 << ( V_183 + 0 ) ) |
( V_184 << V_185 ) ;
F_4 ( V_2 , V_182 , F_23 ( 0 ) ) ;
F_4 ( V_2 , 0 , F_23 ( 1 ) ) ;
F_4 ( V_2 , 0 , F_23 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_23 ( 3 ) ) ;
F_4 ( V_2 , 0 , V_84 ) ;
}
static void F_100 ( struct V_1 * V_2 )
{
int V_115 ;
F_3 ( V_2 ,
V_2 -> V_142 << V_170 ,
V_33 ) ;
for ( V_115 = 0 ; V_115 < V_186 ; V_115 ++ )
F_4 ( V_2 , 0 , F_23 ( V_115 ) ) ;
}
static int F_101 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
int V_78 ;
T_1 V_189 = 0 , V_190 ;
V_78 = F_102 ( V_188 , L_7 ,
& V_189 ) ;
if ( V_78 )
return - V_191 ;
switch ( V_189 ) {
case 4 :
V_2 -> V_60 = V_178 ;
break;
case 5 :
if ( V_2 -> V_8 == V_58 ) {
V_2 -> V_60 = V_61 ;
break;
}
default:
F_103 ( V_2 -> V_45 ,
L_8 ,
V_189 ) ;
return - V_103 ;
}
if ( F_102 ( V_188 , L_9 , & V_190 ) ) {
V_2 -> V_30 = 4 ;
} else {
if ( V_190 < 1 || V_190 > 32 ) {
F_103 ( V_2 -> V_45 , L_10 ,
V_190 ) ;
return - V_103 ;
}
V_2 -> V_30 = V_190 ;
}
if ( F_102 ( V_188 , L_11 , & V_190 ) ) {
V_2 -> V_32 = 2 ;
} else {
if ( V_190 < 2 || V_190 > V_192 + 1 ) {
F_103 ( V_2 -> V_45 , L_12 ,
V_190 ) ;
return - V_103 ;
}
V_2 -> V_32 = V_190 ;
}
if ( F_102 ( V_188 , L_13 , & V_190 ) ) {
V_2 -> V_35 = 10 ;
} else {
if ( V_190 < 1 || V_190 > V_192 ) {
F_103 ( V_2 -> V_45 , L_14 ,
V_190 ) ;
return - V_103 ;
}
V_2 -> V_35 = V_190 ;
}
return 0 ;
}
static int F_104 ( struct V_193 * V_194 )
{
const struct V_195 * V_196 =
F_105 ( V_197 , & V_194 -> V_45 ) ;
const struct V_198 * V_199 =
& V_198 [ ( enum V_200 ) V_196 -> V_138 ];
struct V_110 * V_45 = & V_194 -> V_45 ;
struct V_187 * V_201 = V_45 -> V_202 ;
struct V_1 * V_2 ;
struct V_76 * V_114 ;
struct V_203 * V_204 ;
int V_78 = 0 , V_205 ;
int V_115 , V_206 ;
T_4 V_207 ;
V_114 = F_106 ( V_45 , sizeof( * V_2 ) ) ;
if ( ! V_114 ) {
F_103 ( V_45 , L_15 ) ;
return - V_122 ;
}
V_2 = F_46 ( V_114 ) ;
V_2 -> V_8 = (enum V_200 ) V_196 -> V_138 ;
V_204 = F_107 ( V_194 , V_208 , 0 ) ;
V_2 -> V_45 = & V_194 -> V_45 ;
V_2 -> V_5 = F_108 ( V_45 , V_204 ) ;
if ( F_109 ( V_2 -> V_5 ) )
return F_110 ( V_2 -> V_5 ) ;
V_2 -> V_209 = F_111 ( & V_194 -> V_45 , NULL ) ;
if ( F_109 ( V_2 -> V_209 ) ) {
F_103 ( V_45 , L_16 ) ;
return F_110 ( V_2 -> V_209 ) ;
}
V_78 = F_112 ( V_2 -> V_209 ) ;
if ( V_78 != 0 ) {
F_103 ( V_45 , L_17 ) ;
return V_78 ;
}
V_205 = F_101 ( V_2 , V_201 ) ;
if ( V_205 == 0 )
V_2 -> V_142 = V_210 ;
else
V_2 -> V_142 = V_211 ;
for ( V_115 = 0 ; V_115 < V_199 -> V_212 ; V_115 ++ ) {
V_2 -> V_137 [ V_115 ] = F_113 ( V_194 , V_115 ) ;
if ( V_2 -> V_137 [ V_115 ] < 0 ) {
V_78 = V_2 -> V_137 [ V_115 ] ;
goto V_213;
}
V_78 = F_114 ( V_45 , V_2 -> V_137 [ V_115 ] ,
F_73 , 0 ,
V_199 -> V_214 [ V_115 ] , V_114 ) ;
if ( V_78 )
goto V_213;
}
V_2 -> V_98 = V_199 -> V_98 ;
F_115 ( V_194 , V_114 ) ;
F_116 ( & V_2 -> V_81 ) ;
F_117 ( & V_2 -> V_79 ) ;
V_114 -> V_123 = V_194 -> V_123 ;
V_114 -> V_45 . V_158 = & V_194 -> V_45 ;
V_114 -> V_215 = & V_216 ;
V_114 -> V_217 = V_218 ;
V_114 -> V_219 = V_167 ;
if ( V_2 -> V_8 == V_9 ) {
V_114 -> V_220 = V_221 ;
V_114 -> V_222 = F_60 ( V_221 ) ;
} else {
V_114 -> V_220 = V_223 ;
V_114 -> V_222 = F_60 ( V_223 ) ;
}
V_78 = F_118 ( V_114 , & V_224 ,
& F_77 ,
& V_225 ) ;
if ( V_78 )
goto V_213;
V_78 = F_83 ( V_114 ) ;
if ( V_78 )
goto V_226;
for ( V_115 = 0 ; V_115 < V_167 ; V_115 ++ ) {
for ( V_206 = 0 ; V_206 < F_60 ( V_2 -> V_105 [ V_115 ] ) ; V_206 ++ ) {
V_207 = ( ( T_4 ) V_2 -> V_98 [ V_115 ] * 100000000 ) >>
( V_46 - V_206 ) ;
V_2 -> V_105 [ V_115 ] [ V_206 ] . V_107 =
F_119 ( V_207 , 100000000 ) * 10 ;
V_2 -> V_105 [ V_115 ] [ V_206 ] . integer = V_207 ;
}
}
V_78 = F_120 ( V_2 -> V_5 ) ;
if ( V_78 )
goto V_227;
F_99 ( V_2 ) ;
if ( V_205 == 0 ) {
V_78 = F_67 ( V_2 ) ;
if ( V_78 )
goto V_228;
}
V_78 = F_121 ( V_114 ) ;
if ( V_78 ) {
F_103 ( V_45 , L_18 ) ;
return V_78 ;
}
return 0 ;
V_228:
F_100 ( V_2 ) ;
V_227:
F_88 ( V_114 ) ;
V_226:
F_122 ( V_114 ) ;
V_213:
F_123 ( V_2 -> V_209 ) ;
return V_78 ;
}
static int F_124 ( struct V_193 * V_194 )
{
struct V_76 * V_114 = F_125 ( V_194 ) ;
struct V_1 * V_2 = F_46 ( V_114 ) ;
F_126 ( V_114 ) ;
F_100 ( V_2 ) ;
F_88 ( V_114 ) ;
F_122 ( V_114 ) ;
F_123 ( V_2 -> V_209 ) ;
return 0 ;
}
