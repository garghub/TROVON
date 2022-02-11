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
else
return V_11 ;
}
static T_1 F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_12 ;
else
return V_13 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_14 ;
else
return V_15 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_16 ;
else
return V_17 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_18 | V_19 ;
else
return V_20 | V_21 ;
}
static T_1 F_10 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_22 | V_23 ;
else
return V_24 | V_25 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 == V_9 )
return V_22 | V_19 ;
else
return V_24 | V_21 ;
}
static bool F_12 ( struct V_1 * V_2 )
{
return ! ! ( F_13 ( V_2 -> V_5 + V_26 ) &
V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned V_28 )
{
F_4 ( V_2 , V_29 |
F_15 ( V_2 -> V_30 - 1 ) ,
F_16 ( V_28 ) ) ;
F_3 ( V_2 , V_31 , F_16 ( V_28 ) ) ;
F_4 ( V_2 , F_17 ( 1 << V_28 ) |
F_18 ( 0 ) |
F_19 ( V_2 -> V_30 - 1 ) |
F_20 ( V_2 -> V_32 - 1 ) ,
F_21 ( 3 ) ) ;
F_3 ( V_2 , F_22 ( 2 ) |
F_22 ( 3 ) | F_22 ( 4 ) |
F_22 ( 5 ) , V_33 ) ;
F_1 ( V_2 , F_23 ( V_28 ) , V_33 ) ;
F_4 ( V_2 , F_17 ( 0 ) |
F_18 ( 1 << 3 ) |
V_34 |
F_20 ( V_2 -> V_35 ) ,
F_21 ( 2 ) ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned V_36 ,
unsigned V_37 )
{
T_1 V_4 ;
V_4 = V_29 |
F_15 ( V_2 -> V_30 - 1 ) ;
F_4 ( V_2 , V_4 , F_16 ( V_36 ) ) ;
F_4 ( V_2 , V_4 , F_16 ( V_37 ) ) ;
F_3 ( V_2 , V_31 , F_16 ( V_36 ) ) ;
F_3 ( V_2 , V_31 , F_16 ( V_37 ) ) ;
F_4 ( V_2 , F_17 ( 1 << V_36 ) |
F_17 ( 1 << V_37 ) |
F_18 ( 0 ) |
F_19 ( V_2 -> V_30 - 1 ) |
F_20 ( V_2 -> V_32 - 1 ) ,
F_21 ( 3 ) ) ;
F_3 ( V_2 , F_22 ( 2 ) |
F_22 ( 3 ) | F_22 ( 4 ) |
F_22 ( 5 ) , V_33 ) ;
F_1 ( V_2 , F_23 ( V_37 ) , V_33 ) ;
F_4 ( V_2 , F_17 ( 0 ) |
F_18 ( 1 << 3 ) |
V_34 |
F_20 ( V_2 -> V_35 ) , F_21 ( 2 ) ) ;
}
static unsigned F_25 ( struct V_1 * V_2 ,
unsigned V_38 )
{
T_1 V_4 ;
unsigned V_39 , V_3 ;
V_4 = F_13 ( V_2 -> V_5 + F_16 ( V_38 ) ) ;
if ( V_4 & V_29 )
V_39 = V_2 -> V_30 ;
else
V_39 = 1 ;
V_3 = ( V_4 & V_31 ) >> V_40 ;
return V_3 / V_39 ;
}
static unsigned F_26 ( struct V_1 * V_2 ,
unsigned V_36 , unsigned V_37 )
{
T_1 V_4 , V_41 ;
unsigned V_42 , V_43 , V_44 ;
V_41 = F_22 ( V_36 ) | F_22 ( V_37 ) ;
V_4 = F_13 ( V_2 -> V_5 + V_33 ) & V_41 ;
while ( V_4 != V_41 ) {
V_4 = F_13 ( V_2 -> V_5 + V_33 ) & V_41 ;
F_27 ( V_2 -> V_45 , L_1 , V_4 ) ;
}
V_43 = F_25 ( V_2 , V_36 ) ;
V_44 = F_25 ( V_2 , V_37 ) ;
if ( V_44 == 0 ) {
F_28 ( V_2 -> V_45 , L_2 ) ;
return 1 << ( V_46 - 1 ) ;
}
V_42 = V_43 ;
V_42 *= ( 1 << V_46 ) ;
V_42 /= V_44 ;
F_27 ( V_2 -> V_45 , L_3 , V_42 ) ;
return V_42 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_4 ;
int V_3 ;
V_4 = F_13 ( V_2 -> V_5 + V_33 ) ;
if ( V_4 & F_22 ( V_47 ) ) {
F_3 ( V_2 , F_23 ( V_47 ) |
F_22 ( V_47 ) , V_33 ) ;
V_3 = F_25 ( V_2 , V_47 ) ;
} else if ( V_4 & F_22 ( V_48 ) ) {
F_3 ( V_2 , F_23 ( V_48 ) |
F_22 ( V_48 ) , V_33 ) ;
V_3 = F_25 ( V_2 , V_48 ) ;
} else if ( V_4 & F_22 ( V_49 ) ) {
F_3 ( V_2 , F_23 ( V_49 ) |
F_22 ( V_49 ) , V_33 ) ;
V_3 = F_25 ( V_2 , V_49 ) ;
} else {
return - V_50 ;
}
F_4 ( V_2 , 0 , F_21 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_21 ( 3 ) ) ;
return V_3 ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_51 ) ;
F_1 ( V_2 , F_8 ( V_2 ) ,
V_51 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_51 ) ;
F_1 ( V_2 , F_9 ( V_2 ) , V_51 ) ;
V_2 -> V_52 = V_53 ;
F_14 ( V_2 , V_47 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_51 ) ;
F_1 ( V_2 , F_10 ( V_2 ) , V_51 ) ;
V_2 -> V_52 = V_54 ;
F_14 ( V_2 , V_48 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_3 ( V_2 , F_5 ( V_2 ) , V_51 ) ;
F_1 ( V_2 , F_11 ( V_2 ) , V_51 ) ;
V_2 -> V_52 = V_55 ;
F_24 ( V_2 , V_56 , V_49 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
V_2 -> V_52 = V_57 ;
F_3 ( V_2 , V_58 |
V_59 , V_33 ) ;
F_1 ( V_2 , V_59 , V_33 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_36 ( V_2 -> V_60 , V_61 , V_2 -> V_62 ) ;
F_36 ( V_2 -> V_60 , V_63 , V_2 -> V_64 ) ;
F_36 ( V_2 -> V_60 , V_65 , V_2 -> V_66 ) ;
F_37 ( V_2 -> V_60 , V_67 , 1 ) ;
F_38 ( V_2 -> V_60 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
V_2 -> V_52 = V_68 ;
F_4 ( V_2 , 0 , F_16 ( 5 ) ) ;
F_3 ( V_2 , F_22 ( 5 ) , V_33 ) ;
F_1 ( V_2 , F_23 ( 5 ) , V_33 ) ;
F_4 ( V_2 , F_17 ( 1 << 5 ) |
V_34 | F_20 ( 10 ) ,
F_21 ( 2 ) ) ;
}
static void F_40 ( struct V_1 * V_2 , bool V_69 )
{
if ( V_69 && F_12 ( V_2 ) ) {
V_2 -> V_70 = true ;
F_35 ( V_2 ) ;
}
if ( F_12 ( V_2 ) ) {
F_32 ( V_2 ) ;
return;
}
if ( V_2 -> V_70 ) {
V_2 -> V_70 = false ;
F_37 ( V_2 -> V_60 , V_67 , 0 ) ;
F_38 ( V_2 -> V_60 ) ;
}
F_3 ( V_2 , V_58 , V_33 ) ;
F_1 ( V_2 , V_59 , V_33 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_3 ;
switch ( V_2 -> V_52 ) {
case V_57 :
if ( F_12 ( V_2 ) ) {
F_3 ( V_2 ,
V_59 ,
V_33 ) ;
F_32 ( V_2 ) ;
}
F_3 ( V_2 , V_58 ,
V_33 ) ;
return;
case V_54 :
V_3 = F_29 ( V_2 ) ;
if ( V_3 < 0 ) {
F_34 ( V_2 ) ;
return;
}
V_2 -> V_64 = V_3 ;
F_31 ( V_2 ) ;
return;
case V_53 :
V_3 = F_29 ( V_2 ) ;
if ( V_3 < 0 ) {
F_34 ( V_2 ) ;
return;
}
V_2 -> V_62 = V_3 ;
F_33 ( V_2 ) ;
return;
case V_55 :
V_2 -> V_66 =
F_26 ( V_2 , V_56 , V_49 ) ;
F_39 ( V_2 ) ;
return;
case V_68 :
V_3 = F_29 ( V_2 ) ;
F_40 ( V_2 , 1 ) ;
break;
}
}
static int F_42 ( struct V_71 * V_71 ,
const struct V_72 * V_73 ,
int * V_3 , int * V_74 , long V_75 )
{
struct V_1 * V_2 = F_43 ( V_71 ) ;
int V_76 ;
if ( V_75 != V_77 )
return - V_78 ;
if ( V_73 -> V_38 > V_79 )
return - V_78 ;
V_76 = F_44 ( & V_2 -> V_80 ) ;
if ( ! V_76 )
return - V_81 ;
F_45 ( & V_2 -> V_82 ) ;
if ( V_2 -> V_8 == V_83 )
F_3 ( V_2 , V_13 ,
V_33 ) ;
F_3 ( V_2 , 0xff , V_51 ) ;
F_3 ( V_2 , F_46 ( 0 ) , V_84 ) ;
F_1 ( V_2 , V_73 -> V_38 , V_84 ) ;
F_4 ( V_2 , 0 , F_16 ( 0 ) ) ;
F_1 ( V_2 , F_23 ( 0 ) , V_33 ) ;
F_1 ( V_2 , 1 << 0 , V_51 ) ;
V_76 = F_47 ( & V_2 -> V_82 , V_85 ) ;
if ( ! V_76 )
V_76 = - V_86 ;
if ( V_76 < 0 )
goto V_87;
* V_3 = F_13 ( V_2 -> V_5 + F_16 ( 0 ) ) & V_31 ;
V_76 = V_88 ;
V_87:
F_3 ( V_2 , F_23 ( 0 ) , V_33 ) ;
F_48 ( & V_2 -> V_80 ) ;
return V_76 ;
}
static int F_49 ( struct V_89 * V_45 )
{
struct V_1 * V_2 = F_50 ( V_45 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_59 |
F_23 ( 2 ) | F_23 ( 3 ) |
F_23 ( 4 ) | F_23 ( 5 ) ,
V_33 ) ;
F_3 ( V_2 , F_5 ( V_2 ) , V_51 ) ;
}
static void F_52 ( struct V_89 * V_45 )
{
struct V_1 * V_2 = F_50 ( V_45 ) ;
F_51 ( V_2 ) ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_89 * V_90 ;
struct V_91 * V_45 = V_2 -> V_45 ;
int V_76 ;
if ( ! V_2 -> V_92 )
return 0 ;
V_90 = F_54 () ;
if ( ! V_90 )
return - V_93 ;
V_90 -> V_94 = V_95 ;
V_90 -> V_96 . V_97 = V_98 ;
V_90 -> V_45 . V_99 = V_45 ;
V_90 -> V_100 = F_49 ;
V_90 -> V_101 = F_52 ;
F_55 ( V_102 , V_90 -> V_103 ) ;
F_55 ( V_104 , V_90 -> V_103 ) ;
F_55 ( V_67 , V_90 -> V_105 ) ;
F_56 ( V_90 , V_61 , 0 , V_106 , 0 , 0 ) ;
F_56 ( V_90 , V_63 , 0 , V_106 , 0 , 0 ) ;
F_56 ( V_90 , V_65 , 0 , V_106 ,
0 , 0 ) ;
V_2 -> V_60 = V_90 ;
F_57 ( V_90 , V_2 ) ;
V_76 = F_58 ( V_90 ) ;
if ( V_76 )
F_59 ( V_2 -> V_60 ) ;
return V_76 ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_92 )
return;
F_51 ( V_2 ) ;
F_61 ( V_2 -> V_60 ) ;
}
static T_2 F_62 ( int V_107 , void * V_108 )
{
struct V_71 * V_109 = V_108 ;
struct V_1 * V_2 = F_43 ( V_109 ) ;
unsigned long V_4 = F_13 ( V_2 -> V_5 + V_33 ) ;
const T_3 V_110 =
V_58 |
F_22 ( 2 ) |
F_22 ( 3 ) |
F_22 ( 4 ) |
F_22 ( 5 ) ;
if ( ! ( V_4 & F_7 ( V_2 ) ) )
return V_111 ;
if ( V_2 -> V_92 && ( V_4 & V_110 ) )
F_41 ( V_2 ) ;
if ( F_63 ( V_109 ) )
F_64 ( V_109 -> V_112 , F_65 () ) ;
else if ( V_4 & F_22 ( 0 ) )
F_66 ( & V_2 -> V_82 ) ;
F_3 ( V_2 , V_4 & F_7 ( V_2 ) , V_33 ) ;
return V_113 ;
}
static T_2 F_67 ( int V_107 , void * V_114 )
{
struct V_115 * V_116 = V_114 ;
struct V_71 * V_109 = V_116 -> V_117 ;
struct V_1 * V_2 = F_43 ( V_109 ) ;
const T_3 V_118 = V_29 |
( ( V_119 - 1 ) << V_120 ) ;
unsigned int V_121 , V_122 = 0 ;
F_68 (i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_2 -> V_123 [ V_122 ] = F_13 ( V_2 -> V_5 + F_16 ( V_122 ) ) ;
F_4 ( V_2 , V_118 , F_16 ( V_122 ) ) ;
V_2 -> V_123 [ V_122 ] &= V_31 ;
V_2 -> V_123 [ V_122 ] /= V_119 ;
V_122 ++ ;
}
F_69 ( V_109 , V_2 -> V_123 , V_116 -> V_124 ) ;
F_70 ( V_109 -> V_112 ) ;
return V_113 ;
}
static int F_71 ( struct V_125 * V_112 , bool V_126 )
{
struct V_71 * V_109 = F_72 ( V_112 ) ;
struct V_1 * V_2 = F_43 ( V_109 ) ;
const T_3 V_127 = V_126 ? V_6 : V_7 ;
F_4 ( V_2 , V_34 , F_21 ( 0 ) + V_127 ) ;
return 0 ;
}
static int F_73 ( struct V_71 * V_109 )
{
int V_76 ;
struct V_125 * V_112 ;
struct V_1 * V_2 = F_43 ( V_109 ) ;
V_112 = F_74 ( L_4 , V_109 -> V_94 , V_109 -> V_96 ) ;
if ( V_112 == NULL )
return - V_93 ;
V_112 -> V_45 . V_99 = V_2 -> V_45 ;
F_75 ( V_112 , V_109 ) ;
V_112 -> V_128 = & V_129 ;
V_76 = F_76 ( V_112 ) ;
if ( V_76 ) {
F_77 ( V_112 ) ;
return V_76 ;
}
V_2 -> V_112 = V_112 ;
return 0 ;
}
static void F_78 ( struct V_71 * V_109 )
{
struct V_1 * V_2 = F_43 ( V_109 ) ;
F_79 ( V_2 -> V_112 ) ;
F_77 ( V_2 -> V_112 ) ;
}
static int F_80 ( struct V_71 * V_109 )
{
struct V_1 * V_2 = F_43 ( V_109 ) ;
int V_76 = 0 , V_73 , V_130 = 0 ;
unsigned long V_131 = 0 ;
T_3 V_132 = 0 ;
T_3 V_133 = 0 ;
T_3 V_134 = 0 ;
const T_3 V_118 = V_29 |
( ( V_119 - 1 ) << V_120 ) ;
const int V_135 = F_81 ( V_109 -> V_136 , V_79 ) ;
if ( ! V_135 )
return - V_78 ;
V_76 = F_44 ( & V_2 -> V_80 ) ;
if ( ! V_76 )
return - V_81 ;
V_2 -> V_123 = F_82 ( V_135 * sizeof( * V_2 -> V_123 ) , V_137 ) ;
if ( ! V_2 -> V_123 ) {
V_76 = - V_93 ;
goto V_138;
}
if ( V_2 -> V_8 == V_83 )
F_3 ( V_2 , V_13 ,
V_33 ) ;
F_3 ( V_2 , 0xff , V_51 ) ;
F_68 (chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_132 |= V_73 << F_83 ( V_130 ) ;
V_133 |= F_46 ( V_130 ) ;
V_134 |= F_23 ( V_130 ) ;
F_4 ( V_2 , V_118 , F_16 ( V_130 ) ) ;
F_84 ( & V_131 , V_130 , 1 ) ;
V_130 ++ ;
}
F_3 ( V_2 , V_139 |
V_34 , F_21 ( 0 ) ) ;
F_3 ( V_2 , V_133 , V_84 ) ;
F_1 ( V_2 , V_132 , V_84 ) ;
F_1 ( V_2 , V_134 , V_33 ) ;
F_1 ( V_2 , V_131 << V_140 ,
F_21 ( 0 ) ) ;
return 0 ;
V_138:
F_48 ( & V_2 -> V_80 ) ;
return V_76 ;
}
static int F_85 ( struct V_71 * V_109 )
{
struct V_1 * V_2 = F_43 ( V_109 ) ;
F_3 ( V_2 , V_139 |
V_34 , F_21 ( 0 ) ) ;
F_3 ( V_2 , 0xff , V_51 ) ;
if ( V_2 -> V_8 == V_83 )
F_3 ( V_2 , V_13 ,
V_33 ) ;
F_86 ( V_2 -> V_123 ) ;
F_48 ( & V_2 -> V_80 ) ;
return 0 ;
}
static bool F_87 ( struct V_71 * V_109 ,
const unsigned long * V_41 )
{
struct V_1 * V_2 = F_43 ( V_109 ) ;
const int V_141 = F_81 ( V_41 , V_79 ) ;
int V_142 = 0 ;
unsigned long V_143 = 0 ;
if ( V_2 -> V_144 )
V_143 |= V_145 ;
if ( V_2 -> V_92 == V_146 )
V_143 |= V_147 ;
if ( V_2 -> V_92 == V_148 )
V_143 |= V_149 ;
if ( V_2 -> V_144 )
V_142 ++ ;
if ( V_2 -> V_92 )
V_142 ++ ;
if ( F_88 ( V_41 , & V_143 , V_79 ) )
return false ;
if ( V_141 + V_142 > V_150 )
return false ;
return true ;
}
static int F_89 ( struct V_1 * V_2 )
{
const T_3 V_151 =
( 1 << ( V_152 + 0 ) ) |
( V_153 << V_154 ) ;
int V_76 = F_90 ( V_2 -> V_5 ) ;
if ( V_76 )
return V_76 ;
F_4 ( V_2 , V_151 , F_21 ( 0 ) ) ;
F_4 ( V_2 , 0 , F_21 ( 1 ) ) ;
F_4 ( V_2 , 0 , F_21 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_21 ( 3 ) ) ;
if ( V_2 -> V_8 == V_83 ) {
F_3 ( V_2 , V_155 ,
V_51 ) ;
if ( V_2 -> V_92 == V_148 )
F_1 ( V_2 , V_155 ,
V_51 ) ;
}
F_4 ( V_2 , 0 , V_156 ) ;
return 0 ;
}
static void F_91 ( struct V_1 * V_2 )
{
int V_121 ;
F_3 ( V_2 , F_6 ( V_2 ) , V_33 ) ;
for ( V_121 = 0 ; V_121 < V_157 ; V_121 ++ )
F_4 ( V_2 , 0 , F_21 ( V_121 ) ) ;
}
static int F_92 ( struct V_1 * V_2 ,
struct V_158 * V_159 )
{
int V_76 ;
T_1 V_160 = 0 , V_161 ;
V_76 = F_93 ( V_159 , L_5 ,
& V_160 ) ;
if ( V_76 )
return - V_162 ;
switch ( V_160 ) {
case 4 :
V_2 -> V_92 = V_146 ;
break;
case 5 :
if ( V_2 -> V_8 == V_83 ) {
V_2 -> V_92 = V_148 ;
break;
}
default:
F_94 ( V_2 -> V_45 ,
L_6 ,
V_160 ) ;
return - V_78 ;
}
V_2 -> V_30 = 4 ;
V_76 = F_93 ( V_159 , L_7 , & V_161 ) ;
if ( V_76 == 0 )
V_2 -> V_30 = V_161 ;
V_2 -> V_32 = 2 ;
V_76 = F_93 ( V_159 , L_8 , & V_161 ) ;
if ( V_76 == 0 )
V_2 -> V_32 = V_161 ;
V_2 -> V_35 = 10 ;
V_76 = F_93 ( V_159 , L_9 , & V_161 ) ;
if ( V_76 == 0 )
V_2 -> V_35 = V_161 ;
return 0 ;
}
static int F_95 ( struct V_163 * V_164 )
{
const struct V_165 * V_166 =
F_96 ( V_167 , & V_164 -> V_45 ) ;
const struct V_168 * V_169 =
& V_168 [ ( enum V_170 ) V_166 -> V_108 ];
struct V_91 * V_45 = & V_164 -> V_45 ;
struct V_158 * V_171 = V_45 -> V_172 ;
struct V_1 * V_2 ;
struct V_71 * V_109 ;
struct V_173 * V_174 ;
int V_76 = 0 , V_175 ;
int V_121 ;
V_109 = F_97 ( V_45 , sizeof( * V_2 ) ) ;
if ( ! V_109 ) {
F_94 ( V_45 , L_10 ) ;
return - V_93 ;
}
V_2 = F_43 ( V_109 ) ;
V_2 -> V_8 = (enum V_170 ) V_166 -> V_108 ;
V_174 = F_98 ( V_164 , V_176 , 0 ) ;
V_2 -> V_45 = & V_164 -> V_45 ;
V_2 -> V_5 = F_99 ( V_45 , V_174 ) ;
if ( F_100 ( V_2 -> V_5 ) )
return F_101 ( V_2 -> V_5 ) ;
V_2 -> V_177 = F_102 ( & V_164 -> V_45 , NULL ) ;
if ( F_100 ( V_2 -> V_177 ) ) {
F_94 ( V_45 , L_11 ) ;
return F_101 ( V_2 -> V_177 ) ;
}
V_76 = F_103 ( V_2 -> V_177 ) ;
if ( V_76 != 0 ) {
F_94 ( V_45 , L_12 ) ;
return V_76 ;
}
V_175 = F_92 ( V_2 , V_171 ) ;
for ( V_121 = 0 ; V_121 < V_169 -> V_178 ; V_121 ++ ) {
V_2 -> V_107 [ V_121 ] = F_104 ( V_164 , V_121 ) ;
if ( V_2 -> V_107 [ V_121 ] < 0 )
return - V_78 ;
V_76 = F_105 ( V_45 , V_2 -> V_107 [ V_121 ] ,
F_62 , 0 ,
V_169 -> V_179 [ V_121 ] , V_109 ) ;
if ( V_76 )
return V_76 ;
}
F_106 ( V_164 , V_109 ) ;
F_107 ( & V_2 -> V_82 ) ;
F_108 ( & V_2 -> V_80 ) ;
V_109 -> V_94 = V_164 -> V_94 ;
V_109 -> V_45 . V_99 = & V_164 -> V_45 ;
V_109 -> V_180 = & V_181 ;
V_109 -> V_182 = V_183 ;
V_109 -> V_184 = V_185 ;
V_109 -> V_186 = F_109 ( V_185 ) ;
V_109 -> V_187 = V_79 ;
V_76 = F_110 ( V_109 , & V_188 ,
& F_67 ,
& V_189 ) ;
if ( V_76 )
return V_76 ;
V_76 = F_73 ( V_109 ) ;
if ( V_76 )
goto V_190;
V_76 = F_89 ( V_2 ) ;
if ( V_76 )
goto V_191;
if ( V_175 == 0 ) {
V_76 = F_53 ( V_2 ) ;
if ( V_76 )
goto V_192;
}
V_76 = F_111 ( V_109 ) ;
if ( V_76 ) {
F_94 ( V_45 , L_13 ) ;
goto V_193;
}
return 0 ;
V_193:
F_60 ( V_2 ) ;
V_192:
F_91 ( V_2 ) ;
V_191:
F_78 ( V_109 ) ;
V_190:
F_112 ( V_109 ) ;
return V_76 ;
}
static int F_113 ( struct V_163 * V_164 )
{
struct V_71 * V_109 = F_114 ( V_164 ) ;
struct V_1 * V_2 = F_43 ( V_109 ) ;
F_115 ( V_109 ) ;
F_60 ( V_2 ) ;
F_91 ( V_2 ) ;
F_78 ( V_109 ) ;
F_112 ( V_109 ) ;
F_116 ( V_2 -> V_177 ) ;
return 0 ;
}
