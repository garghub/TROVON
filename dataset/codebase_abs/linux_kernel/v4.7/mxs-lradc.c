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
return V_16 ;
return V_17 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_18 | V_19 ;
return V_20 | V_21 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_22 | V_23 ;
return V_24 | V_25 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_22 | V_19 ;
return V_24 | V_21 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
return ! ! ( F_13 ( V_2 -> V_5 + V_26 ) &
V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_28 ,
unsigned V_29 )
{
F_3 ( V_2 , F_15 ( V_28 ) ,
V_30 ) ;
F_1 ( V_2 , F_16 ( V_28 , V_29 ) , V_30 ) ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_29 )
{
F_4 ( V_2 , V_31 |
F_18 ( V_2 -> V_32 - 1 ) ,
F_19 ( V_29 ) ) ;
F_3 ( V_2 , V_33 , F_19 ( V_29 ) ) ;
F_4 ( V_2 , F_20 ( 1 << V_29 ) |
F_21 ( 0 ) |
F_22 ( V_2 -> V_32 - 1 ) |
F_23 ( V_2 -> V_34 - 1 ) ,
F_24 ( 3 ) ) ;
F_3 ( V_2 , F_25 ( V_29 ) , V_35 ) ;
F_4 (
V_2 ,
F_20 ( 0 ) |
F_21 ( F_26 ( 3 ) ) |
V_36 |
F_23 ( V_2 -> V_37 ) ,
F_24 ( 2 ) ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned V_38 ,
unsigned V_39 )
{
T_1 V_4 ;
V_4 = V_31 |
F_18 ( V_2 -> V_32 - 1 ) ;
F_4 ( V_2 , V_4 , F_19 ( V_38 ) ) ;
F_4 ( V_2 , V_4 , F_19 ( V_39 ) ) ;
F_3 ( V_2 , V_33 , F_19 ( V_38 ) ) ;
F_3 ( V_2 , V_33 , F_19 ( V_39 ) ) ;
F_4 (
V_2 ,
F_20 ( 1 << V_38 ) |
F_20 ( 1 << V_39 ) |
F_21 ( 0 ) |
F_22 ( V_2 -> V_32 - 1 ) |
F_23 ( V_2 -> V_34 - 1 ) ,
F_24 ( 3 ) ) ;
F_3 ( V_2 , F_25 ( V_39 ) , V_35 ) ;
F_4 (
V_2 ,
F_20 ( 0 ) |
F_21 ( F_26 ( 3 ) ) |
V_36 |
F_23 ( V_2 -> V_37 ) , F_24 ( 2 ) ) ;
}
static unsigned F_28 ( struct V_1 * V_2 ,
unsigned V_40 )
{
T_1 V_4 ;
unsigned V_41 , V_3 ;
V_4 = F_13 ( V_2 -> V_5 + F_19 ( V_40 ) ) ;
if ( V_4 & V_31 )
V_41 = V_2 -> V_32 ;
else
V_41 = 1 ;
V_3 = ( V_4 & V_33 ) >> V_42 ;
return V_3 / V_41 ;
}
static unsigned F_29 ( struct V_1 * V_2 ,
unsigned V_38 , unsigned V_39 )
{
T_1 V_4 , V_43 ;
unsigned V_44 , V_45 , V_46 ;
V_43 = F_25 ( V_38 ) | F_25 ( V_39 ) ;
V_4 = F_13 ( V_2 -> V_5 + V_35 ) & V_43 ;
while ( V_4 != V_43 ) {
V_4 = F_13 ( V_2 -> V_5 + V_35 ) & V_43 ;
F_30 ( V_2 -> V_47 , L_1 , V_4 ) ;
}
V_45 = F_28 ( V_2 , V_38 ) ;
V_46 = F_28 ( V_2 , V_39 ) ;
if ( V_46 == 0 ) {
F_31 ( V_2 -> V_47 , L_2 ) ;
return 1 << ( V_48 - 1 ) ;
}
V_44 = V_45 ;
V_44 *= ( 1 << V_48 ) ;
V_44 /= V_46 ;
F_30 ( V_2 -> V_47 , L_3 , V_44 ) ;
return V_44 ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_8 ( V_2 ) ,
V_49 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_9 ( V_2 ) , V_49 ) ;
V_2 -> V_50 = V_51 ;
F_14 ( V_2 , V_52 , V_53 ) ;
F_17 ( V_2 , V_52 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_10 ( V_2 ) , V_49 ) ;
V_2 -> V_50 = V_54 ;
F_14 ( V_2 , V_52 , V_55 ) ;
F_17 ( V_2 , V_52 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_11 ( V_2 ) , V_49 ) ;
V_2 -> V_50 = V_56 ;
F_14 ( V_2 , V_52 , V_57 ) ;
F_14 ( V_2 , V_58 , V_59 ) ;
F_27 ( V_2 , V_58 ,
V_52 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_60 ) {
F_3 ( V_2 , V_61 ,
V_49 ) ;
if ( V_2 -> V_62 == V_63 )
F_1 ( V_2 ,
V_61 ,
V_49 ) ;
}
F_32 ( V_2 ) ;
V_2 -> V_50 = V_64 ;
F_3 ( V_2 , V_65 |
V_66 , V_35 ) ;
F_1 ( V_2 , V_66 , V_35 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
F_3 ( V_2 ,
V_66 ,
V_35 ) ;
F_1 ( V_2 ,
F_38 ( V_52 ) ,
V_35 ) ;
F_34 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_40 ( V_2 -> V_67 , V_68 , V_2 -> V_69 ) ;
F_40 ( V_2 -> V_67 , V_70 , V_2 -> V_71 ) ;
F_40 ( V_2 -> V_67 , V_72 , V_2 -> V_73 ) ;
F_41 ( V_2 -> V_67 , V_74 , 1 ) ;
F_42 ( V_2 -> V_67 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_32 ( V_2 ) ;
V_2 -> V_50 = V_75 ;
F_4 ( V_2 , 0 , F_19 ( V_52 ) ) ;
F_3 ( V_2 ,
F_25 ( V_52 ) |
F_25 ( V_58 ) ,
V_35 ) ;
F_4 (
V_2 ,
F_20 ( 1 << V_52 ) |
V_36 | F_23 ( 10 ) ,
F_24 ( 2 ) ) ;
}
static void F_44 ( struct V_1 * V_2 , bool V_76 )
{
if ( V_76 && F_12 ( V_2 ) ) {
V_2 -> V_77 = true ;
F_39 ( V_2 ) ;
}
if ( F_12 ( V_2 ) ) {
F_34 ( V_2 ) ;
return;
}
if ( V_2 -> V_77 ) {
V_2 -> V_77 = false ;
F_41 ( V_2 -> V_67 , V_74 , 0 ) ;
F_42 ( V_2 -> V_67 ) ;
}
V_2 -> V_50 = V_64 ;
F_4 ( V_2 , 0 , F_24 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 3 ) ) ;
F_3 ( V_2 ,
V_65 |
F_38 ( V_52 ) |
F_25 ( V_52 ) ,
V_35 ) ;
F_1 ( V_2 , V_66 , V_35 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_50 ) {
case V_64 :
if ( F_12 ( V_2 ) )
F_37 ( V_2 ) ;
F_3 ( V_2 , V_65 ,
V_35 ) ;
return;
case V_54 :
V_2 -> V_71 =
F_28 ( V_2 ,
V_52 ) ;
F_33 ( V_2 ) ;
return;
case V_51 :
V_2 -> V_69 =
F_28 ( V_2 ,
V_52 ) ;
F_35 ( V_2 ) ;
return;
case V_56 :
V_2 -> V_73 =
F_29 ( V_2 ,
V_58 ,
V_52 ) ;
F_43 ( V_2 ) ;
return;
case V_75 :
F_44 ( V_2 , 1 ) ;
break;
}
}
static int F_46 ( struct V_78 * V_78 , int V_79 , int * V_3 )
{
struct V_1 * V_2 = F_47 ( V_78 ) ;
int V_80 ;
V_80 = F_48 ( & V_2 -> V_81 ) ;
if ( ! V_80 )
return - V_82 ;
F_49 ( & V_2 -> V_83 ) ;
if ( V_2 -> V_8 == V_60 )
F_3 ( V_2 , F_38 ( 0 ) ,
V_35 ) ;
F_3 ( V_2 , 0x1 , V_49 ) ;
if ( F_50 ( V_79 , & V_2 -> V_84 ) )
F_1 ( V_2 ,
1 << V_85 ,
V_86 ) ;
else
F_3 ( V_2 ,
1 << V_85 ,
V_86 ) ;
F_3 ( V_2 , F_15 ( 0 ) ,
V_30 ) ;
F_1 ( V_2 , V_79 , V_30 ) ;
F_4 ( V_2 , 0 , F_19 ( 0 ) ) ;
F_1 ( V_2 , F_38 ( 0 ) , V_35 ) ;
F_1 ( V_2 , F_26 ( 0 ) , V_49 ) ;
V_80 = F_51 ( & V_2 -> V_83 , V_87 ) ;
if ( ! V_80 )
V_80 = - V_88 ;
if ( V_80 < 0 )
goto V_89;
* V_3 = F_13 ( V_2 -> V_5 + F_19 ( 0 ) ) & V_33 ;
V_80 = V_90 ;
V_89:
F_3 ( V_2 , F_38 ( 0 ) , V_35 ) ;
F_52 ( & V_2 -> V_81 ) ;
return V_80 ;
}
static int F_53 ( struct V_78 * V_78 , int * V_3 )
{
int V_80 , V_91 , V_92 ;
V_80 = F_46 ( V_78 , 8 , & V_91 ) ;
if ( V_80 != V_90 )
return V_80 ;
V_80 = F_46 ( V_78 , 9 , & V_92 ) ;
if ( V_80 != V_90 )
return V_80 ;
* V_3 = V_92 - V_91 ;
return V_90 ;
}
static int F_54 ( struct V_78 * V_78 ,
const struct V_93 * V_79 ,
int * V_3 , int * V_94 , long V_95 )
{
struct V_1 * V_2 = F_47 ( V_78 ) ;
switch ( V_95 ) {
case V_96 :
if ( V_79 -> type == V_97 )
return F_53 ( V_78 , V_3 ) ;
return F_46 ( V_78 , V_79 -> V_40 , V_3 ) ;
case V_98 :
if ( V_79 -> type == V_97 ) {
* V_3 = 0 ;
* V_94 = 253000 ;
return V_99 ;
}
* V_3 = V_2 -> V_100 [ V_79 -> V_40 ] ;
* V_94 = V_79 -> V_101 . V_102 -
F_50 ( V_79 -> V_40 , & V_2 -> V_84 ) ;
return V_103 ;
case V_104 :
if ( V_79 -> type == V_97 ) {
* V_3 = - 1079 ;
* V_94 = 644268 ;
return V_99 ;
}
return - V_105 ;
default:
break;
}
return - V_105 ;
}
static int F_55 ( struct V_78 * V_78 ,
const struct V_93 * V_79 ,
int V_3 , int V_94 , long V_95 )
{
struct V_1 * V_2 = F_47 ( V_78 ) ;
struct V_106 * V_107 =
V_2 -> V_107 [ V_79 -> V_40 ] ;
int V_80 ;
V_80 = F_48 ( & V_2 -> V_81 ) ;
if ( ! V_80 )
return - V_82 ;
switch ( V_95 ) {
case V_98 :
V_80 = - V_105 ;
if ( V_3 == V_107 [ V_108 ] . integer &&
V_94 == V_107 [ V_108 ] . V_109 ) {
F_56 ( V_79 -> V_40 , & V_2 -> V_84 ) ;
V_80 = 0 ;
} else if ( V_3 == V_107 [ V_110 ] . integer &&
V_94 == V_107 [ V_110 ] . V_109 ) {
F_57 ( V_79 -> V_40 , & V_2 -> V_84 ) ;
V_80 = 0 ;
}
break;
default:
V_80 = - V_105 ;
break;
}
F_52 ( & V_2 -> V_81 ) ;
return V_80 ;
}
static int F_58 ( struct V_78 * V_78 ,
const struct V_93 * V_79 ,
long V_95 )
{
return V_111 ;
}
static T_2 F_59 ( struct V_112 * V_47 ,
struct V_113 * V_114 ,
char * V_115 ,
int V_29 )
{
struct V_78 * V_116 = F_60 ( V_47 ) ;
struct V_1 * V_2 = F_47 ( V_116 ) ;
int V_117 , V_118 = 0 ;
for ( V_117 = 0 ; V_117 < F_61 ( V_2 -> V_107 [ V_29 ] ) ; V_117 ++ )
V_118 += sprintf ( V_115 + V_118 , L_4 ,
V_2 -> V_107 [ V_29 ] [ V_117 ] . integer ,
V_2 -> V_107 [ V_29 ] [ V_117 ] . V_109 ) ;
V_118 += sprintf ( V_115 + V_118 , L_5 ) ;
return V_118 ;
}
static T_2 F_62 ( struct V_112 * V_47 ,
struct V_113 * V_114 ,
char * V_115 )
{
struct V_119 * V_120 = F_63 ( V_114 ) ;
return F_59 ( V_47 , V_114 , V_115 ,
V_120 -> V_121 ) ;
}
static int F_64 ( struct V_122 * V_47 )
{
struct V_1 * V_2 = F_65 ( V_47 ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static void F_66 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_66 |
F_38 ( V_52 ) |
F_38 ( V_58 ) , V_35 ) ;
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
}
static void F_67 ( struct V_122 * V_47 )
{
struct V_1 * V_2 = F_65 ( V_47 ) ;
F_66 ( V_2 ) ;
}
static int F_68 ( struct V_1 * V_2 )
{
struct V_122 * V_123 ;
struct V_112 * V_47 = V_2 -> V_47 ;
int V_80 ;
if ( ! V_2 -> V_62 )
return 0 ;
V_123 = F_69 () ;
if ( ! V_123 )
return - V_124 ;
V_123 -> V_125 = V_126 ;
V_123 -> V_127 . V_128 = V_129 ;
V_123 -> V_47 . V_130 = V_47 ;
V_123 -> V_131 = F_64 ;
V_123 -> V_132 = F_67 ;
F_70 ( V_133 , V_123 -> V_134 ) ;
F_70 ( V_135 , V_123 -> V_134 ) ;
F_70 ( V_74 , V_123 -> V_136 ) ;
F_70 ( V_137 , V_123 -> V_138 ) ;
F_71 ( V_123 , V_68 , 0 , V_139 , 0 , 0 ) ;
F_71 ( V_123 , V_70 , 0 , V_139 , 0 , 0 ) ;
F_71 ( V_123 , V_72 , 0 , V_139 ,
0 , 0 ) ;
V_2 -> V_67 = V_123 ;
F_72 ( V_123 , V_2 ) ;
V_80 = F_73 ( V_123 ) ;
if ( V_80 )
F_74 ( V_2 -> V_67 ) ;
return V_80 ;
}
static void F_75 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_62 )
return;
F_66 ( V_2 ) ;
F_76 ( V_2 -> V_67 ) ;
}
static T_3 F_77 ( int V_140 , void * V_141 )
{
struct V_78 * V_116 = V_141 ;
struct V_1 * V_2 = F_47 ( V_116 ) ;
unsigned long V_4 = F_13 ( V_2 -> V_5 + V_35 ) ;
T_1 V_142 = F_7 ( V_2 ) ;
const T_1 V_143 =
V_65 |
F_25 ( V_52 ) |
F_25 ( V_58 ) ;
if ( ! ( V_4 & F_7 ( V_2 ) ) )
return V_144 ;
if ( V_2 -> V_62 && ( V_4 & V_143 ) ) {
F_45 ( V_2 ) ;
V_142 &= ~ ( F_25 ( V_52 ) |
F_25 ( V_58 ) ) ;
}
if ( F_78 ( V_116 ) ) {
if ( V_4 & V_2 -> V_145 )
F_79 ( V_116 -> V_146 ) ;
} else if ( V_4 & F_25 ( 0 ) ) {
F_80 ( & V_2 -> V_83 ) ;
}
F_3 ( V_2 , V_4 & V_142 , V_35 ) ;
return V_147 ;
}
static T_3 F_81 ( int V_140 , void * V_148 )
{
struct V_149 * V_150 = V_148 ;
struct V_78 * V_116 = V_150 -> V_151 ;
struct V_1 * V_2 = F_47 ( V_116 ) ;
const T_1 V_152 = V_31 |
( ( V_153 - 1 ) << V_154 ) ;
unsigned int V_117 , V_155 = 0 ;
F_82 (i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_2 -> V_156 [ V_155 ] = F_13 ( V_2 -> V_5 + F_19 ( V_155 ) ) ;
F_4 ( V_2 , V_152 , F_19 ( V_155 ) ) ;
V_2 -> V_156 [ V_155 ] &= V_33 ;
V_2 -> V_156 [ V_155 ] /= V_153 ;
V_155 ++ ;
}
F_83 ( V_116 , V_2 -> V_156 , V_150 -> V_157 ) ;
F_84 ( V_116 -> V_146 ) ;
return V_147 ;
}
static int F_85 ( struct V_158 * V_146 , bool V_159 )
{
struct V_78 * V_116 = F_86 ( V_146 ) ;
struct V_1 * V_2 = F_47 ( V_116 ) ;
const T_1 V_160 = V_159 ? V_6 : V_7 ;
F_4 ( V_2 , V_36 , F_24 ( 0 ) + V_160 ) ;
return 0 ;
}
static int F_87 ( struct V_78 * V_116 )
{
int V_80 ;
struct V_158 * V_146 ;
struct V_1 * V_2 = F_47 ( V_116 ) ;
V_146 = F_88 ( L_6 , V_116 -> V_125 , V_116 -> V_127 ) ;
if ( ! V_146 )
return - V_124 ;
V_146 -> V_47 . V_130 = V_2 -> V_47 ;
F_89 ( V_146 , V_116 ) ;
V_146 -> V_161 = & V_162 ;
V_80 = F_90 ( V_146 ) ;
if ( V_80 ) {
F_91 ( V_146 ) ;
return V_80 ;
}
V_2 -> V_146 = V_146 ;
return 0 ;
}
static void F_92 ( struct V_78 * V_116 )
{
struct V_1 * V_2 = F_47 ( V_116 ) ;
F_93 ( V_2 -> V_146 ) ;
F_91 ( V_2 -> V_146 ) ;
}
static int F_94 ( struct V_78 * V_116 )
{
struct V_1 * V_2 = F_47 ( V_116 ) ;
int V_80 = 0 , V_79 , V_163 = 0 ;
unsigned long V_164 = 0 ;
T_1 V_165 = 0 ;
T_1 V_166 = 0 ;
T_1 V_167 = 0 ;
const T_1 V_152 = V_31 |
( ( V_153 - 1 ) << V_154 ) ;
const int V_118 = F_95 ( V_116 -> V_168 ,
V_169 ) ;
if ( ! V_118 )
return - V_105 ;
V_80 = F_48 ( & V_2 -> V_81 ) ;
if ( ! V_80 )
return - V_82 ;
V_2 -> V_156 = F_96 ( V_118 , sizeof( * V_2 -> V_156 ) , V_170 ) ;
if ( ! V_2 -> V_156 ) {
V_80 = - V_124 ;
goto V_171;
}
if ( V_2 -> V_8 == V_60 )
F_3 (
V_2 ,
V_2 -> V_145 << V_172 ,
V_35 ) ;
F_3 ( V_2 , V_2 -> V_145 , V_49 ) ;
F_82 (chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_165 |= V_79 << F_97 ( V_163 ) ;
V_166 |= F_15 ( V_163 ) ;
V_167 |= F_38 ( V_163 ) ;
F_4 ( V_2 , V_152 , F_19 ( V_163 ) ) ;
F_98 ( & V_164 , V_163 , 1 ) ;
V_163 ++ ;
}
F_3 ( V_2 , V_173 |
V_36 , F_24 ( 0 ) ) ;
F_3 ( V_2 , V_166 , V_30 ) ;
F_1 ( V_2 , V_165 , V_30 ) ;
F_1 ( V_2 , V_167 , V_35 ) ;
F_1 ( V_2 , V_164 << V_174 ,
F_24 ( 0 ) ) ;
return 0 ;
V_171:
F_52 ( & V_2 -> V_81 ) ;
return V_80 ;
}
static int F_99 ( struct V_78 * V_116 )
{
struct V_1 * V_2 = F_47 ( V_116 ) ;
F_3 ( V_2 , V_173 |
V_36 , F_24 ( 0 ) ) ;
F_3 ( V_2 , V_2 -> V_145 , V_49 ) ;
if ( V_2 -> V_8 == V_60 )
F_3 (
V_2 ,
V_2 -> V_145 << V_172 ,
V_35 ) ;
F_100 ( V_2 -> V_156 ) ;
F_52 ( & V_2 -> V_81 ) ;
return 0 ;
}
static bool F_101 ( struct V_78 * V_116 ,
const unsigned long * V_43 )
{
struct V_1 * V_2 = F_47 ( V_116 ) ;
const int V_175 = F_95 ( V_43 , V_169 ) ;
int V_176 = 0 ;
unsigned long V_177 = 0 ;
if ( V_2 -> V_178 )
V_177 |= V_179 ;
if ( V_2 -> V_62 == V_180 )
V_177 |= V_181 ;
if ( V_2 -> V_62 == V_63 )
V_177 |= V_182 ;
if ( V_2 -> V_178 )
V_176 ++ ;
if ( V_2 -> V_62 )
V_176 += 2 ;
if ( F_102 ( V_43 , & V_177 , V_169 ) )
return false ;
if ( V_175 + V_176 > V_183 )
return false ;
return true ;
}
static void F_103 ( struct V_1 * V_2 )
{
const T_1 V_184 =
( 1 << ( V_185 + 0 ) ) |
( V_186 << V_187 ) ;
F_4 ( V_2 , V_184 , F_24 ( 0 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 1 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 3 ) ) ;
F_4 ( V_2 , 0 , V_86 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
int V_117 ;
F_3 ( V_2 , F_6 ( V_2 ) , V_35 ) ;
for ( V_117 = 0 ; V_117 < V_188 ; V_117 ++ )
F_4 ( V_2 , 0 , F_24 ( V_117 ) ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_189 * V_190 )
{
int V_80 ;
T_1 V_191 = 0 , V_192 ;
V_80 = F_106 ( V_190 , L_7 ,
& V_191 ) ;
if ( V_80 )
return - V_193 ;
switch ( V_191 ) {
case 4 :
V_2 -> V_62 = V_180 ;
break;
case 5 :
if ( V_2 -> V_8 == V_60 ) {
V_2 -> V_62 = V_63 ;
break;
}
default:
F_107 ( V_2 -> V_47 ,
L_8 ,
V_191 ) ;
return - V_105 ;
}
if ( F_106 ( V_190 , L_9 , & V_192 ) ) {
V_2 -> V_32 = 4 ;
} else {
if ( V_192 < 1 || V_192 > 32 ) {
F_107 ( V_2 -> V_47 , L_10 ,
V_192 ) ;
return - V_105 ;
}
V_2 -> V_32 = V_192 ;
}
if ( F_106 ( V_190 , L_11 , & V_192 ) ) {
V_2 -> V_34 = 2 ;
} else {
if ( V_192 < 2 || V_192 > V_194 + 1 ) {
F_107 ( V_2 -> V_47 , L_12 ,
V_192 ) ;
return - V_105 ;
}
V_2 -> V_34 = V_192 ;
}
if ( F_106 ( V_190 , L_13 , & V_192 ) ) {
V_2 -> V_37 = 10 ;
} else {
if ( V_192 < 1 || V_192 > V_194 ) {
F_107 ( V_2 -> V_47 , L_14 ,
V_192 ) ;
return - V_105 ;
}
V_2 -> V_37 = V_192 ;
}
return 0 ;
}
static int F_108 ( struct V_195 * V_196 )
{
const struct V_197 * V_198 =
F_109 ( V_199 , & V_196 -> V_47 ) ;
const struct V_200 * V_201 =
& V_200 [ ( enum V_202 ) V_198 -> V_141 ];
struct V_112 * V_47 = & V_196 -> V_47 ;
struct V_189 * V_203 = V_47 -> V_204 ;
struct V_1 * V_2 ;
struct V_78 * V_116 ;
struct V_205 * V_206 ;
int V_80 = 0 , V_207 ;
int V_117 , V_208 ;
T_4 V_209 ;
V_116 = F_110 ( V_47 , sizeof( * V_2 ) ) ;
if ( ! V_116 ) {
F_107 ( V_47 , L_15 ) ;
return - V_124 ;
}
V_2 = F_47 ( V_116 ) ;
V_2 -> V_8 = (enum V_202 ) V_198 -> V_141 ;
V_206 = F_111 ( V_196 , V_210 , 0 ) ;
V_2 -> V_47 = & V_196 -> V_47 ;
V_2 -> V_5 = F_112 ( V_47 , V_206 ) ;
if ( F_113 ( V_2 -> V_5 ) )
return F_114 ( V_2 -> V_5 ) ;
V_2 -> V_211 = F_115 ( & V_196 -> V_47 , NULL ) ;
if ( F_113 ( V_2 -> V_211 ) ) {
F_107 ( V_47 , L_16 ) ;
return F_114 ( V_2 -> V_211 ) ;
}
V_80 = F_116 ( V_2 -> V_211 ) ;
if ( V_80 != 0 ) {
F_107 ( V_47 , L_17 ) ;
return V_80 ;
}
V_207 = F_105 ( V_2 , V_203 ) ;
if ( V_207 == 0 )
V_2 -> V_145 = V_212 ;
else
V_2 -> V_145 = V_213 ;
for ( V_117 = 0 ; V_117 < V_201 -> V_214 ; V_117 ++ ) {
V_2 -> V_140 [ V_117 ] = F_117 ( V_196 , V_117 ) ;
if ( V_2 -> V_140 [ V_117 ] < 0 ) {
V_80 = V_2 -> V_140 [ V_117 ] ;
goto V_215;
}
V_80 = F_118 ( V_47 , V_2 -> V_140 [ V_117 ] ,
F_77 , 0 ,
V_201 -> V_216 [ V_117 ] , V_116 ) ;
if ( V_80 )
goto V_215;
}
V_2 -> V_100 = V_201 -> V_100 ;
F_119 ( V_196 , V_116 ) ;
F_120 ( & V_2 -> V_83 ) ;
F_121 ( & V_2 -> V_81 ) ;
V_116 -> V_125 = V_196 -> V_125 ;
V_116 -> V_47 . V_130 = & V_196 -> V_47 ;
V_116 -> V_217 = & V_218 ;
V_116 -> V_219 = V_220 ;
V_116 -> V_221 = V_169 ;
if ( V_2 -> V_8 == V_9 ) {
V_116 -> V_222 = V_223 ;
V_116 -> V_224 = F_61 ( V_223 ) ;
} else {
V_116 -> V_222 = V_225 ;
V_116 -> V_224 = F_61 ( V_225 ) ;
}
V_80 = F_122 ( V_116 , & V_226 ,
& F_81 ,
& V_227 ) ;
if ( V_80 )
goto V_215;
V_80 = F_87 ( V_116 ) ;
if ( V_80 )
goto V_228;
for ( V_117 = 0 ; V_117 < V_169 ; V_117 ++ ) {
for ( V_208 = 0 ; V_208 < F_61 ( V_2 -> V_107 [ V_117 ] ) ; V_208 ++ ) {
V_209 = ( ( T_4 ) V_2 -> V_100 [ V_117 ] * 100000000 ) >>
( V_48 - V_208 ) ;
V_2 -> V_107 [ V_117 ] [ V_208 ] . V_109 =
F_123 ( V_209 , 100000000 ) * 10 ;
V_2 -> V_107 [ V_117 ] [ V_208 ] . integer = V_209 ;
}
}
V_80 = F_124 ( V_2 -> V_5 ) ;
if ( V_80 )
goto V_229;
F_103 ( V_2 ) ;
if ( V_207 == 0 ) {
V_80 = F_68 ( V_2 ) ;
if ( V_80 )
goto V_230;
}
V_80 = F_125 ( V_116 ) ;
if ( V_80 ) {
F_107 ( V_47 , L_18 ) ;
goto V_231;
}
return 0 ;
V_231:
F_75 ( V_2 ) ;
V_230:
F_104 ( V_2 ) ;
V_229:
F_92 ( V_116 ) ;
V_228:
F_126 ( V_116 ) ;
V_215:
F_127 ( V_2 -> V_211 ) ;
return V_80 ;
}
static int F_128 ( struct V_195 * V_196 )
{
struct V_78 * V_116 = F_129 ( V_196 ) ;
struct V_1 * V_2 = F_47 ( V_116 ) ;
F_130 ( V_116 ) ;
F_75 ( V_2 ) ;
F_104 ( V_2 ) ;
F_92 ( V_116 ) ;
F_126 ( V_116 ) ;
F_127 ( V_2 -> V_211 ) ;
return 0 ;
}
