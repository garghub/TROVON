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
F_4 ( V_2 ,
F_20 ( 0 ) |
F_21 ( 1 << 3 ) |
V_36 |
F_23 ( V_2 -> V_37 ) ,
F_24 ( 2 ) ) ;
}
static void F_26 ( struct V_1 * V_2 , unsigned V_38 ,
unsigned V_39 )
{
T_1 V_4 ;
V_4 = V_31 |
F_18 ( V_2 -> V_32 - 1 ) ;
F_4 ( V_2 , V_4 , F_19 ( V_38 ) ) ;
F_4 ( V_2 , V_4 , F_19 ( V_39 ) ) ;
F_3 ( V_2 , V_33 , F_19 ( V_38 ) ) ;
F_3 ( V_2 , V_33 , F_19 ( V_39 ) ) ;
F_4 ( V_2 , F_20 ( 1 << V_38 ) |
F_20 ( 1 << V_39 ) |
F_21 ( 0 ) |
F_22 ( V_2 -> V_32 - 1 ) |
F_23 ( V_2 -> V_34 - 1 ) ,
F_24 ( 3 ) ) ;
F_3 ( V_2 , F_25 ( V_39 ) , V_35 ) ;
F_4 ( V_2 ,
F_20 ( 0 ) |
F_21 ( 1 << 3 ) |
V_36 |
F_23 ( V_2 -> V_37 ) , F_24 ( 2 ) ) ;
}
static unsigned F_27 ( struct V_1 * V_2 ,
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
static unsigned F_28 ( struct V_1 * V_2 ,
unsigned V_38 , unsigned V_39 )
{
T_1 V_4 , V_43 ;
unsigned V_44 , V_45 , V_46 ;
V_43 = F_25 ( V_38 ) | F_25 ( V_39 ) ;
V_4 = F_13 ( V_2 -> V_5 + V_35 ) & V_43 ;
while ( V_4 != V_43 ) {
V_4 = F_13 ( V_2 -> V_5 + V_35 ) & V_43 ;
F_29 ( V_2 -> V_47 , L_1 , V_4 ) ;
}
V_45 = F_27 ( V_2 , V_38 ) ;
V_46 = F_27 ( V_2 , V_39 ) ;
if ( V_46 == 0 ) {
F_30 ( V_2 -> V_47 , L_2 ) ;
return 1 << ( V_48 - 1 ) ;
}
V_44 = V_45 ;
V_44 *= ( 1 << V_48 ) ;
V_44 /= V_46 ;
F_29 ( V_2 -> V_47 , L_3 , V_44 ) ;
return V_44 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_8 ( V_2 ) ,
V_49 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_9 ( V_2 ) , V_49 ) ;
V_2 -> V_50 = V_51 ;
F_14 ( V_2 , V_52 , V_53 ) ;
F_17 ( V_2 , V_52 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_10 ( V_2 ) , V_49 ) ;
V_2 -> V_50 = V_54 ;
F_14 ( V_2 , V_52 , V_55 ) ;
F_17 ( V_2 , V_52 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
F_1 ( V_2 , F_11 ( V_2 ) , V_49 ) ;
V_2 -> V_50 = V_56 ;
F_14 ( V_2 , V_52 , V_57 ) ;
F_14 ( V_2 , V_58 , V_59 ) ;
F_26 ( V_2 , V_58 ,
V_52 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
V_2 -> V_50 = V_60 ;
F_3 ( V_2 , V_61 |
V_62 , V_35 ) ;
F_1 ( V_2 , V_62 , V_35 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_62 ,
V_35 ) ;
F_1 ( V_2 ,
F_37 ( V_52 ) , V_35 ) ;
F_33 ( V_2 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_63 , V_64 , V_2 -> V_65 ) ;
F_39 ( V_2 -> V_63 , V_66 , V_2 -> V_67 ) ;
F_39 ( V_2 -> V_63 , V_68 , V_2 -> V_69 ) ;
F_40 ( V_2 -> V_63 , V_70 , 1 ) ;
F_41 ( V_2 -> V_63 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
V_2 -> V_50 = V_71 ;
F_4 ( V_2 , 0 , F_19 ( V_52 ) ) ;
F_3 ( V_2 ,
F_25 ( V_52 ) |
F_25 ( V_58 ) , V_35 ) ;
F_4 ( V_2 ,
F_20 ( 1 << V_52 ) |
V_36 | F_23 ( 10 ) ,
F_24 ( 2 ) ) ;
}
static void F_43 ( struct V_1 * V_2 , bool V_72 )
{
if ( V_72 && F_12 ( V_2 ) ) {
V_2 -> V_73 = true ;
F_38 ( V_2 ) ;
}
if ( F_12 ( V_2 ) ) {
F_33 ( V_2 ) ;
return;
}
if ( V_2 -> V_73 ) {
V_2 -> V_73 = false ;
F_40 ( V_2 -> V_63 , V_70 , 0 ) ;
F_41 ( V_2 -> V_63 ) ;
}
V_2 -> V_50 = V_60 ;
F_4 ( V_2 , 0 , F_24 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 3 ) ) ;
F_3 ( V_2 , V_61 |
F_37 ( V_52 ) |
F_25 ( V_52 ) , V_35 ) ;
F_1 ( V_2 , V_62 , V_35 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_50 ) {
case V_60 :
if ( F_12 ( V_2 ) )
F_36 ( V_2 ) ;
F_3 ( V_2 , V_61 ,
V_35 ) ;
return;
case V_54 :
V_2 -> V_67 = F_27 ( V_2 ,
V_52 ) ;
F_32 ( V_2 ) ;
return;
case V_51 :
V_2 -> V_65 = F_27 ( V_2 ,
V_52 ) ;
F_34 ( V_2 ) ;
return;
case V_56 :
V_2 -> V_69 = F_28 ( V_2 ,
V_58 ,
V_52 ) ;
F_42 ( V_2 ) ;
return;
case V_71 :
F_43 ( V_2 , 1 ) ;
break;
}
}
static int F_45 ( struct V_74 * V_74 , int V_75 , int * V_3 )
{
struct V_1 * V_2 = F_46 ( V_74 ) ;
int V_76 ;
V_76 = F_47 ( & V_2 -> V_77 ) ;
if ( ! V_76 )
return - V_78 ;
F_48 ( & V_2 -> V_79 ) ;
if ( V_2 -> V_8 == V_80 )
F_3 ( V_2 , F_37 ( 0 ) ,
V_35 ) ;
F_3 ( V_2 , 0x1 , V_49 ) ;
if ( F_49 ( V_75 , & V_2 -> V_81 ) )
F_1 ( V_2 , 1 << V_82 ,
V_83 ) ;
else
F_3 ( V_2 ,
1 << V_82 , V_83 ) ;
F_3 ( V_2 , F_15 ( 0 ) ,
V_30 ) ;
F_1 ( V_2 , V_75 , V_30 ) ;
F_4 ( V_2 , 0 , F_19 ( 0 ) ) ;
F_1 ( V_2 , F_37 ( 0 ) , V_35 ) ;
F_1 ( V_2 , 1 << 0 , V_49 ) ;
V_76 = F_50 ( & V_2 -> V_79 , V_84 ) ;
if ( ! V_76 )
V_76 = - V_85 ;
if ( V_76 < 0 )
goto V_86;
* V_3 = F_13 ( V_2 -> V_5 + F_19 ( 0 ) ) & V_33 ;
V_76 = V_87 ;
V_86:
F_3 ( V_2 , F_37 ( 0 ) , V_35 ) ;
F_51 ( & V_2 -> V_77 ) ;
return V_76 ;
}
static int F_52 ( struct V_74 * V_74 , int * V_3 )
{
int V_76 , V_88 , V_89 ;
V_76 = F_45 ( V_74 , 8 , & V_88 ) ;
if ( V_76 != V_87 )
return V_76 ;
V_76 = F_45 ( V_74 , 9 , & V_89 ) ;
if ( V_76 != V_87 )
return V_76 ;
* V_3 = V_89 - V_88 ;
return V_87 ;
}
static int F_53 ( struct V_74 * V_74 ,
const struct V_90 * V_75 ,
int * V_3 , int * V_91 , long V_92 )
{
struct V_1 * V_2 = F_46 ( V_74 ) ;
switch ( V_92 ) {
case V_93 :
if ( V_75 -> type == V_94 )
return F_52 ( V_74 , V_3 ) ;
return F_45 ( V_74 , V_75 -> V_40 , V_3 ) ;
case V_95 :
if ( V_75 -> type == V_94 ) {
* V_3 = 0 ;
* V_91 = 253000 ;
return V_96 ;
}
* V_3 = V_2 -> V_97 [ V_75 -> V_40 ] ;
* V_91 = V_75 -> V_98 . V_99 -
F_49 ( V_75 -> V_40 , & V_2 -> V_81 ) ;
return V_100 ;
case V_101 :
if ( V_75 -> type == V_94 ) {
* V_3 = - 1075 ;
* V_91 = 691699 ;
return V_96 ;
}
return - V_102 ;
default:
break;
}
return - V_102 ;
}
static int F_54 ( struct V_74 * V_74 ,
const struct V_90 * V_75 ,
int V_3 , int V_91 , long V_92 )
{
struct V_1 * V_2 = F_46 ( V_74 ) ;
struct V_103 * V_104 =
V_2 -> V_104 [ V_75 -> V_40 ] ;
int V_76 ;
V_76 = F_47 ( & V_2 -> V_77 ) ;
if ( ! V_76 )
return - V_78 ;
switch ( V_92 ) {
case V_95 :
V_76 = - V_102 ;
if ( V_3 == V_104 [ V_105 ] . integer &&
V_91 == V_104 [ V_105 ] . V_106 ) {
F_55 ( V_75 -> V_40 , & V_2 -> V_81 ) ;
V_76 = 0 ;
} else if ( V_3 == V_104 [ V_107 ] . integer &&
V_91 == V_104 [ V_107 ] . V_106 ) {
F_56 ( V_75 -> V_40 , & V_2 -> V_81 ) ;
V_76 = 0 ;
}
break;
default:
V_76 = - V_102 ;
break;
}
F_51 ( & V_2 -> V_77 ) ;
return V_76 ;
}
static int F_57 ( struct V_74 * V_74 ,
const struct V_90 * V_75 ,
long V_92 )
{
return V_108 ;
}
static T_2 F_58 ( struct V_109 * V_47 ,
struct V_110 * V_111 ,
char * V_112 ,
int V_29 )
{
struct V_74 * V_113 = F_59 ( V_47 ) ;
struct V_1 * V_2 = F_46 ( V_113 ) ;
int V_114 , V_115 = 0 ;
for ( V_114 = 0 ; V_114 < F_60 ( V_2 -> V_104 [ V_29 ] ) ; V_114 ++ )
V_115 += sprintf ( V_112 + V_115 , L_4 ,
V_2 -> V_104 [ V_29 ] [ V_114 ] . integer ,
V_2 -> V_104 [ V_29 ] [ V_114 ] . V_106 ) ;
V_115 += sprintf ( V_112 + V_115 , L_5 ) ;
return V_115 ;
}
static T_2 F_61 ( struct V_109 * V_47 ,
struct V_110 * V_111 ,
char * V_112 )
{
struct V_116 * V_117 = F_62 ( V_111 ) ;
return F_58 ( V_47 , V_111 , V_112 ,
V_117 -> V_118 ) ;
}
static int F_63 ( struct V_119 * V_47 )
{
struct V_1 * V_2 = F_64 ( V_47 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static void F_65 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_62 |
F_37 ( V_52 ) |
F_37 ( V_58 ) , V_35 ) ;
F_3 ( V_2 , F_5 ( V_2 ) , V_49 ) ;
}
static void F_66 ( struct V_119 * V_47 )
{
struct V_1 * V_2 = F_64 ( V_47 ) ;
F_65 ( V_2 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
struct V_119 * V_120 ;
struct V_109 * V_47 = V_2 -> V_47 ;
int V_76 ;
if ( ! V_2 -> V_121 )
return 0 ;
V_120 = F_68 () ;
if ( ! V_120 )
return - V_122 ;
V_120 -> V_123 = V_124 ;
V_120 -> V_125 . V_126 = V_127 ;
V_120 -> V_47 . V_128 = V_47 ;
V_120 -> V_129 = F_63 ;
V_120 -> V_130 = F_66 ;
F_69 ( V_131 , V_120 -> V_132 ) ;
F_69 ( V_133 , V_120 -> V_132 ) ;
F_69 ( V_70 , V_120 -> V_134 ) ;
F_70 ( V_120 , V_64 , 0 , V_135 , 0 , 0 ) ;
F_70 ( V_120 , V_66 , 0 , V_135 , 0 , 0 ) ;
F_70 ( V_120 , V_68 , 0 , V_135 ,
0 , 0 ) ;
V_2 -> V_63 = V_120 ;
F_71 ( V_120 , V_2 ) ;
V_76 = F_72 ( V_120 ) ;
if ( V_76 )
F_73 ( V_2 -> V_63 ) ;
return V_76 ;
}
static void F_74 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_121 )
return;
F_65 ( V_2 ) ;
F_75 ( V_2 -> V_63 ) ;
}
static T_3 F_76 ( int V_136 , void * V_137 )
{
struct V_74 * V_113 = V_137 ;
struct V_1 * V_2 = F_46 ( V_113 ) ;
unsigned long V_4 = F_13 ( V_2 -> V_5 + V_35 ) ;
T_4 V_138 = F_7 ( V_2 ) ;
const T_4 V_139 =
V_61 |
F_25 ( V_52 ) |
F_25 ( V_58 ) ;
if ( ! ( V_4 & F_7 ( V_2 ) ) )
return V_140 ;
if ( V_2 -> V_121 && ( V_4 & V_139 ) ) {
F_44 ( V_2 ) ;
V_138 &= ~ ( F_25 ( V_52 ) |
F_25 ( V_58 ) ) ;
}
if ( F_77 ( V_113 ) ) {
if ( V_4 & V_2 -> V_141 )
F_78 ( V_113 -> V_142 ) ;
} else if ( V_4 & F_25 ( 0 ) ) {
F_79 ( & V_2 -> V_79 ) ;
}
F_3 ( V_2 , V_4 & V_138 , V_35 ) ;
return V_143 ;
}
static T_3 F_80 ( int V_136 , void * V_144 )
{
struct V_145 * V_146 = V_144 ;
struct V_74 * V_113 = V_146 -> V_147 ;
struct V_1 * V_2 = F_46 ( V_113 ) ;
const T_4 V_148 = V_31 |
( ( V_149 - 1 ) << V_150 ) ;
unsigned int V_114 , V_151 = 0 ;
F_81 (i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_2 -> V_152 [ V_151 ] = F_13 ( V_2 -> V_5 + F_19 ( V_151 ) ) ;
F_4 ( V_2 , V_148 , F_19 ( V_151 ) ) ;
V_2 -> V_152 [ V_151 ] &= V_33 ;
V_2 -> V_152 [ V_151 ] /= V_149 ;
V_151 ++ ;
}
F_82 ( V_113 , V_2 -> V_152 , V_146 -> V_153 ) ;
F_83 ( V_113 -> V_142 ) ;
return V_143 ;
}
static int F_84 ( struct V_154 * V_142 , bool V_155 )
{
struct V_74 * V_113 = F_85 ( V_142 ) ;
struct V_1 * V_2 = F_46 ( V_113 ) ;
const T_4 V_156 = V_155 ? V_6 : V_7 ;
F_4 ( V_2 , V_36 , F_24 ( 0 ) + V_156 ) ;
return 0 ;
}
static int F_86 ( struct V_74 * V_113 )
{
int V_76 ;
struct V_154 * V_142 ;
struct V_1 * V_2 = F_46 ( V_113 ) ;
V_142 = F_87 ( L_6 , V_113 -> V_123 , V_113 -> V_125 ) ;
if ( V_142 == NULL )
return - V_122 ;
V_142 -> V_47 . V_128 = V_2 -> V_47 ;
F_88 ( V_142 , V_113 ) ;
V_142 -> V_157 = & V_158 ;
V_76 = F_89 ( V_142 ) ;
if ( V_76 ) {
F_90 ( V_142 ) ;
return V_76 ;
}
V_2 -> V_142 = V_142 ;
return 0 ;
}
static void F_91 ( struct V_74 * V_113 )
{
struct V_1 * V_2 = F_46 ( V_113 ) ;
F_92 ( V_2 -> V_142 ) ;
F_90 ( V_2 -> V_142 ) ;
}
static int F_93 ( struct V_74 * V_113 )
{
struct V_1 * V_2 = F_46 ( V_113 ) ;
int V_76 = 0 , V_75 , V_159 = 0 ;
unsigned long V_160 = 0 ;
T_4 V_161 = 0 ;
T_4 V_162 = 0 ;
T_4 V_163 = 0 ;
const T_4 V_148 = V_31 |
( ( V_149 - 1 ) << V_150 ) ;
const int V_115 = F_94 ( V_113 -> V_164 ,
V_165 ) ;
if ( ! V_115 )
return - V_102 ;
V_76 = F_47 ( & V_2 -> V_77 ) ;
if ( ! V_76 )
return - V_78 ;
V_2 -> V_152 = F_95 ( V_115 , sizeof( * V_2 -> V_152 ) , V_166 ) ;
if ( ! V_2 -> V_152 ) {
V_76 = - V_122 ;
goto V_167;
}
if ( V_2 -> V_8 == V_80 )
F_3 ( V_2 ,
V_2 -> V_141 << V_168 ,
V_35 ) ;
F_3 ( V_2 , V_2 -> V_141 , V_49 ) ;
F_81 (chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_161 |= V_75 << F_96 ( V_159 ) ;
V_162 |= F_15 ( V_159 ) ;
V_163 |= F_37 ( V_159 ) ;
F_4 ( V_2 , V_148 , F_19 ( V_159 ) ) ;
F_97 ( & V_160 , V_159 , 1 ) ;
V_159 ++ ;
}
F_3 ( V_2 , V_169 |
V_36 , F_24 ( 0 ) ) ;
F_3 ( V_2 , V_162 , V_30 ) ;
F_1 ( V_2 , V_161 , V_30 ) ;
F_1 ( V_2 , V_163 , V_35 ) ;
F_1 ( V_2 , V_160 << V_170 ,
F_24 ( 0 ) ) ;
return 0 ;
V_167:
F_51 ( & V_2 -> V_77 ) ;
return V_76 ;
}
static int F_98 ( struct V_74 * V_113 )
{
struct V_1 * V_2 = F_46 ( V_113 ) ;
F_3 ( V_2 , V_169 |
V_36 , F_24 ( 0 ) ) ;
F_3 ( V_2 , V_2 -> V_141 , V_49 ) ;
if ( V_2 -> V_8 == V_80 )
F_3 ( V_2 ,
V_2 -> V_141 << V_168 ,
V_35 ) ;
F_99 ( V_2 -> V_152 ) ;
F_51 ( & V_2 -> V_77 ) ;
return 0 ;
}
static bool F_100 ( struct V_74 * V_113 ,
const unsigned long * V_43 )
{
struct V_1 * V_2 = F_46 ( V_113 ) ;
const int V_171 = F_94 ( V_43 , V_165 ) ;
int V_172 = 0 ;
unsigned long V_173 = 0 ;
if ( V_2 -> V_174 )
V_173 |= V_175 ;
if ( V_2 -> V_121 == V_176 )
V_173 |= V_177 ;
if ( V_2 -> V_121 == V_178 )
V_173 |= V_179 ;
if ( V_2 -> V_174 )
V_172 ++ ;
if ( V_2 -> V_121 )
V_172 += 2 ;
if ( F_101 ( V_43 , & V_173 , V_165 ) )
return false ;
if ( V_171 + V_172 > V_180 )
return false ;
return true ;
}
static int F_102 ( struct V_1 * V_2 )
{
const T_4 V_181 =
( 1 << ( V_182 + 0 ) ) |
( V_183 << V_184 ) ;
int V_76 = F_103 ( V_2 -> V_5 ) ;
if ( V_76 )
return V_76 ;
F_4 ( V_2 , V_181 , F_24 ( 0 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 1 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_24 ( 3 ) ) ;
if ( V_2 -> V_8 == V_80 ) {
F_3 ( V_2 , V_185 ,
V_49 ) ;
if ( V_2 -> V_121 == V_178 )
F_1 ( V_2 , V_185 ,
V_49 ) ;
}
F_4 ( V_2 , 0 , V_83 ) ;
return 0 ;
}
static void F_104 ( struct V_1 * V_2 )
{
int V_114 ;
F_3 ( V_2 , F_6 ( V_2 ) , V_35 ) ;
for ( V_114 = 0 ; V_114 < V_186 ; V_114 ++ )
F_4 ( V_2 , 0 , F_24 ( V_114 ) ) ;
}
static int F_105 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
int V_76 ;
T_1 V_189 = 0 , V_190 ;
V_76 = F_106 ( V_188 , L_7 ,
& V_189 ) ;
if ( V_76 )
return - V_191 ;
switch ( V_189 ) {
case 4 :
V_2 -> V_121 = V_176 ;
break;
case 5 :
if ( V_2 -> V_8 == V_80 ) {
V_2 -> V_121 = V_178 ;
break;
}
default:
F_107 ( V_2 -> V_47 ,
L_8 ,
V_189 ) ;
return - V_102 ;
}
if ( F_106 ( V_188 , L_9 , & V_190 ) ) {
V_2 -> V_32 = 4 ;
} else {
if ( V_190 < 1 || V_190 > 32 ) {
F_107 ( V_2 -> V_47 , L_10 ,
V_190 ) ;
return - V_102 ;
}
V_2 -> V_32 = V_190 ;
}
if ( F_106 ( V_188 , L_11 , & V_190 ) ) {
V_2 -> V_34 = 2 ;
} else {
if ( V_190 < 2 || V_190 > V_192 + 1 ) {
F_107 ( V_2 -> V_47 , L_12 ,
V_190 ) ;
return - V_102 ;
}
V_2 -> V_34 = V_190 ;
}
if ( F_106 ( V_188 , L_13 , & V_190 ) ) {
V_2 -> V_37 = 10 ;
} else {
if ( V_190 < 1 || V_190 > V_192 ) {
F_107 ( V_2 -> V_47 , L_14 ,
V_190 ) ;
return - V_102 ;
}
V_2 -> V_37 = V_190 ;
}
return 0 ;
}
static int F_108 ( struct V_193 * V_194 )
{
const struct V_195 * V_196 =
F_109 ( V_197 , & V_194 -> V_47 ) ;
const struct V_198 * V_199 =
& V_198 [ ( enum V_200 ) V_196 -> V_137 ];
struct V_109 * V_47 = & V_194 -> V_47 ;
struct V_187 * V_201 = V_47 -> V_202 ;
struct V_1 * V_2 ;
struct V_74 * V_113 ;
struct V_203 * V_204 ;
int V_76 = 0 , V_205 ;
int V_114 , V_206 ;
T_5 V_207 ;
V_113 = F_110 ( V_47 , sizeof( * V_2 ) ) ;
if ( ! V_113 ) {
F_107 ( V_47 , L_15 ) ;
return - V_122 ;
}
V_2 = F_46 ( V_113 ) ;
V_2 -> V_8 = (enum V_200 ) V_196 -> V_137 ;
V_204 = F_111 ( V_194 , V_208 , 0 ) ;
V_2 -> V_47 = & V_194 -> V_47 ;
V_2 -> V_5 = F_112 ( V_47 , V_204 ) ;
if ( F_113 ( V_2 -> V_5 ) )
return F_114 ( V_2 -> V_5 ) ;
V_2 -> V_209 = F_115 ( & V_194 -> V_47 , NULL ) ;
if ( F_113 ( V_2 -> V_209 ) ) {
F_107 ( V_47 , L_16 ) ;
return F_114 ( V_2 -> V_209 ) ;
}
V_76 = F_116 ( V_2 -> V_209 ) ;
if ( V_76 != 0 ) {
F_107 ( V_47 , L_17 ) ;
return V_76 ;
}
V_205 = F_105 ( V_2 , V_201 ) ;
if ( V_205 == 0 )
V_2 -> V_141 = V_210 ;
else
V_2 -> V_141 = V_211 ;
for ( V_114 = 0 ; V_114 < V_199 -> V_212 ; V_114 ++ ) {
V_2 -> V_136 [ V_114 ] = F_117 ( V_194 , V_114 ) ;
if ( V_2 -> V_136 [ V_114 ] < 0 ) {
V_76 = V_2 -> V_136 [ V_114 ] ;
goto V_213;
}
V_76 = F_118 ( V_47 , V_2 -> V_136 [ V_114 ] ,
F_76 , 0 ,
V_199 -> V_214 [ V_114 ] , V_113 ) ;
if ( V_76 )
goto V_213;
}
V_2 -> V_97 = V_199 -> V_97 ;
F_119 ( V_194 , V_113 ) ;
F_120 ( & V_2 -> V_79 ) ;
F_121 ( & V_2 -> V_77 ) ;
V_113 -> V_123 = V_194 -> V_123 ;
V_113 -> V_47 . V_128 = & V_194 -> V_47 ;
V_113 -> V_215 = & V_216 ;
V_113 -> V_217 = V_218 ;
V_113 -> V_219 = V_220 ;
V_113 -> V_221 = F_60 ( V_220 ) ;
V_113 -> V_222 = V_165 ;
V_76 = F_122 ( V_113 , & V_223 ,
& F_80 ,
& V_224 ) ;
if ( V_76 )
goto V_213;
V_76 = F_86 ( V_113 ) ;
if ( V_76 )
goto V_225;
for ( V_114 = 0 ; V_114 < V_165 ; V_114 ++ ) {
for ( V_206 = 0 ; V_206 < F_60 ( V_2 -> V_104 [ V_114 ] ) ; V_206 ++ ) {
V_207 = ( ( V_226 ) V_2 -> V_97 [ V_114 ] * 100000000 ) >>
( V_48 - V_206 ) ;
V_2 -> V_104 [ V_114 ] [ V_206 ] . V_106 =
F_123 ( V_207 , 100000000 ) * 10 ;
V_2 -> V_104 [ V_114 ] [ V_206 ] . integer = V_207 ;
}
}
V_76 = F_102 ( V_2 ) ;
if ( V_76 )
goto V_227;
if ( V_205 == 0 ) {
V_76 = F_67 ( V_2 ) ;
if ( V_76 )
goto V_228;
}
V_76 = F_124 ( V_113 ) ;
if ( V_76 ) {
F_107 ( V_47 , L_18 ) ;
goto V_229;
}
return 0 ;
V_229:
F_74 ( V_2 ) ;
V_228:
F_104 ( V_2 ) ;
V_227:
F_91 ( V_113 ) ;
V_225:
F_125 ( V_113 ) ;
V_213:
F_126 ( V_2 -> V_209 ) ;
return V_76 ;
}
static int F_127 ( struct V_193 * V_194 )
{
struct V_74 * V_113 = F_128 ( V_194 ) ;
struct V_1 * V_2 = F_46 ( V_113 ) ;
F_129 ( V_113 ) ;
F_74 ( V_2 ) ;
F_104 ( V_2 ) ;
F_91 ( V_113 ) ;
F_125 ( V_113 ) ;
F_126 ( V_2 -> V_209 ) ;
return 0 ;
}
