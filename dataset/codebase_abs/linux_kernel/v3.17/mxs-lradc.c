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
V_2 -> V_52 = V_57 ;
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
static int F_42 ( struct V_71 * V_71 , int V_72 , int * V_3 )
{
struct V_1 * V_2 = F_43 ( V_71 ) ;
int V_73 ;
V_73 = F_44 ( & V_2 -> V_74 ) ;
if ( ! V_73 )
return - V_75 ;
F_45 ( & V_2 -> V_76 ) ;
if ( V_2 -> V_8 == V_77 )
F_3 ( V_2 , V_13 ,
V_33 ) ;
F_3 ( V_2 , 0xff , V_51 ) ;
if ( F_46 ( V_72 , & V_2 -> V_78 ) )
F_1 ( V_2 , 1 << V_79 ,
V_80 ) ;
else
F_3 ( V_2 ,
1 << V_79 , V_80 ) ;
F_3 ( V_2 , F_47 ( 0 ) ,
V_81 ) ;
F_1 ( V_2 , V_72 , V_81 ) ;
F_4 ( V_2 , 0 , F_16 ( 0 ) ) ;
F_1 ( V_2 , F_23 ( 0 ) , V_33 ) ;
F_1 ( V_2 , 1 << 0 , V_51 ) ;
V_73 = F_48 ( & V_2 -> V_76 , V_82 ) ;
if ( ! V_73 )
V_73 = - V_83 ;
if ( V_73 < 0 )
goto V_84;
* V_3 = F_13 ( V_2 -> V_5 + F_16 ( 0 ) ) & V_31 ;
V_73 = V_85 ;
V_84:
F_3 ( V_2 , F_23 ( 0 ) , V_33 ) ;
F_49 ( & V_2 -> V_74 ) ;
return V_73 ;
}
static int F_50 ( struct V_71 * V_71 , int * V_3 )
{
int V_73 , V_86 , V_87 ;
V_73 = F_42 ( V_71 , 8 , & V_86 ) ;
if ( V_73 != V_85 )
return V_73 ;
V_73 = F_42 ( V_71 , 9 , & V_87 ) ;
if ( V_73 != V_85 )
return V_73 ;
* V_3 = V_87 - V_86 ;
return V_85 ;
}
static int F_51 ( struct V_71 * V_71 ,
const struct V_88 * V_72 ,
int * V_3 , int * V_89 , long V_90 )
{
struct V_1 * V_2 = F_43 ( V_71 ) ;
switch ( V_90 ) {
case V_91 :
if ( V_72 -> type == V_92 )
return F_50 ( V_71 , V_3 ) ;
return F_42 ( V_71 , V_72 -> V_38 , V_3 ) ;
case V_93 :
if ( V_72 -> type == V_92 ) {
* V_3 = 0 ;
* V_89 = 253000 ;
return V_94 ;
}
* V_3 = V_2 -> V_95 [ V_72 -> V_38 ] ;
* V_89 = V_72 -> V_96 . V_97 -
F_46 ( V_72 -> V_38 , & V_2 -> V_78 ) ;
return V_98 ;
case V_99 :
if ( V_72 -> type == V_92 ) {
* V_3 = - 1075 ;
* V_89 = 691699 ;
return V_94 ;
}
return - V_100 ;
default:
break;
}
return - V_100 ;
}
static int F_52 ( struct V_71 * V_71 ,
const struct V_88 * V_72 ,
int V_3 , int V_89 , long V_90 )
{
struct V_1 * V_2 = F_43 ( V_71 ) ;
struct V_101 * V_102 =
V_2 -> V_102 [ V_72 -> V_38 ] ;
int V_73 ;
V_73 = F_44 ( & V_2 -> V_74 ) ;
if ( ! V_73 )
return - V_75 ;
switch ( V_90 ) {
case V_93 :
V_73 = - V_100 ;
if ( V_3 == V_102 [ V_103 ] . integer &&
V_89 == V_102 [ V_103 ] . V_104 ) {
F_53 ( V_72 -> V_38 , & V_2 -> V_78 ) ;
V_73 = 0 ;
} else if ( V_3 == V_102 [ V_105 ] . integer &&
V_89 == V_102 [ V_105 ] . V_104 ) {
F_54 ( V_72 -> V_38 , & V_2 -> V_78 ) ;
V_73 = 0 ;
}
break;
default:
V_73 = - V_100 ;
break;
}
F_49 ( & V_2 -> V_74 ) ;
return V_73 ;
}
static int F_55 ( struct V_71 * V_71 ,
const struct V_88 * V_72 ,
long V_90 )
{
return V_106 ;
}
static T_2 F_56 ( struct V_107 * V_45 ,
struct V_108 * V_109 ,
char * V_110 ,
int V_28 )
{
struct V_71 * V_111 = F_57 ( V_45 ) ;
struct V_1 * V_2 = F_43 ( V_111 ) ;
int V_112 , V_113 = 0 ;
for ( V_112 = 0 ; V_112 < F_58 ( V_2 -> V_102 [ V_28 ] ) ; V_112 ++ )
V_113 += sprintf ( V_110 + V_113 , L_4 ,
V_2 -> V_102 [ V_28 ] [ V_112 ] . integer ,
V_2 -> V_102 [ V_28 ] [ V_112 ] . V_104 ) ;
V_113 += sprintf ( V_110 + V_113 , L_5 ) ;
return V_113 ;
}
static T_2 F_59 ( struct V_107 * V_45 ,
struct V_108 * V_109 ,
char * V_110 )
{
struct V_114 * V_115 = F_60 ( V_109 ) ;
return F_56 ( V_45 , V_109 , V_110 ,
V_115 -> V_116 ) ;
}
static int F_61 ( struct V_117 * V_45 )
{
struct V_1 * V_2 = F_62 ( V_45 ) ;
F_34 ( V_2 ) ;
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_59 |
F_23 ( 2 ) | F_23 ( 3 ) |
F_23 ( 4 ) | F_23 ( 5 ) ,
V_33 ) ;
F_3 ( V_2 , F_5 ( V_2 ) , V_51 ) ;
}
static void F_64 ( struct V_117 * V_45 )
{
struct V_1 * V_2 = F_62 ( V_45 ) ;
F_63 ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_117 * V_118 ;
struct V_107 * V_45 = V_2 -> V_45 ;
int V_73 ;
if ( ! V_2 -> V_119 )
return 0 ;
V_118 = F_66 () ;
if ( ! V_118 )
return - V_120 ;
V_118 -> V_121 = V_122 ;
V_118 -> V_123 . V_124 = V_125 ;
V_118 -> V_45 . V_126 = V_45 ;
V_118 -> V_127 = F_61 ;
V_118 -> V_128 = F_64 ;
F_67 ( V_129 , V_118 -> V_130 ) ;
F_67 ( V_131 , V_118 -> V_130 ) ;
F_67 ( V_67 , V_118 -> V_132 ) ;
F_68 ( V_118 , V_61 , 0 , V_133 , 0 , 0 ) ;
F_68 ( V_118 , V_63 , 0 , V_133 , 0 , 0 ) ;
F_68 ( V_118 , V_65 , 0 , V_133 ,
0 , 0 ) ;
V_2 -> V_60 = V_118 ;
F_69 ( V_118 , V_2 ) ;
V_73 = F_70 ( V_118 ) ;
if ( V_73 )
F_71 ( V_2 -> V_60 ) ;
return V_73 ;
}
static void F_72 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_119 )
return;
F_63 ( V_2 ) ;
F_73 ( V_2 -> V_60 ) ;
}
static T_3 F_74 ( int V_134 , void * V_135 )
{
struct V_71 * V_111 = V_135 ;
struct V_1 * V_2 = F_43 ( V_111 ) ;
unsigned long V_4 = F_13 ( V_2 -> V_5 + V_33 ) ;
const T_4 V_136 =
V_58 |
F_22 ( 2 ) |
F_22 ( 3 ) |
F_22 ( 4 ) |
F_22 ( 5 ) ;
if ( ! ( V_4 & F_7 ( V_2 ) ) )
return V_137 ;
if ( V_2 -> V_119 && ( V_4 & V_136 ) )
F_41 ( V_2 ) ;
if ( F_75 ( V_111 ) )
F_76 ( V_111 -> V_138 ) ;
else if ( V_4 & F_22 ( 0 ) )
F_77 ( & V_2 -> V_76 ) ;
F_3 ( V_2 , V_4 & F_7 ( V_2 ) ,
V_33 ) ;
return V_139 ;
}
static T_3 F_78 ( int V_134 , void * V_140 )
{
struct V_141 * V_142 = V_140 ;
struct V_71 * V_111 = V_142 -> V_143 ;
struct V_1 * V_2 = F_43 ( V_111 ) ;
const T_4 V_144 = V_29 |
( ( V_145 - 1 ) << V_146 ) ;
unsigned int V_112 , V_147 = 0 ;
F_79 (i, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_2 -> V_148 [ V_147 ] = F_13 ( V_2 -> V_5 + F_16 ( V_147 ) ) ;
F_4 ( V_2 , V_144 , F_16 ( V_147 ) ) ;
V_2 -> V_148 [ V_147 ] &= V_31 ;
V_2 -> V_148 [ V_147 ] /= V_145 ;
V_147 ++ ;
}
F_80 ( V_111 , V_2 -> V_148 , V_142 -> V_149 ) ;
F_81 ( V_111 -> V_138 ) ;
return V_139 ;
}
static int F_82 ( struct V_150 * V_138 , bool V_151 )
{
struct V_71 * V_111 = F_83 ( V_138 ) ;
struct V_1 * V_2 = F_43 ( V_111 ) ;
const T_4 V_152 = V_151 ? V_6 : V_7 ;
F_4 ( V_2 , V_34 , F_21 ( 0 ) + V_152 ) ;
return 0 ;
}
static int F_84 ( struct V_71 * V_111 )
{
int V_73 ;
struct V_150 * V_138 ;
struct V_1 * V_2 = F_43 ( V_111 ) ;
V_138 = F_85 ( L_6 , V_111 -> V_121 , V_111 -> V_123 ) ;
if ( V_138 == NULL )
return - V_120 ;
V_138 -> V_45 . V_126 = V_2 -> V_45 ;
F_86 ( V_138 , V_111 ) ;
V_138 -> V_153 = & V_154 ;
V_73 = F_87 ( V_138 ) ;
if ( V_73 ) {
F_88 ( V_138 ) ;
return V_73 ;
}
V_2 -> V_138 = V_138 ;
return 0 ;
}
static void F_89 ( struct V_71 * V_111 )
{
struct V_1 * V_2 = F_43 ( V_111 ) ;
F_90 ( V_2 -> V_138 ) ;
F_88 ( V_2 -> V_138 ) ;
}
static int F_91 ( struct V_71 * V_111 )
{
struct V_1 * V_2 = F_43 ( V_111 ) ;
int V_73 = 0 , V_72 , V_155 = 0 ;
unsigned long V_156 = 0 ;
T_4 V_157 = 0 ;
T_4 V_158 = 0 ;
T_4 V_159 = 0 ;
const T_4 V_144 = V_29 |
( ( V_145 - 1 ) << V_146 ) ;
const int V_113 = F_92 ( V_111 -> V_160 ,
V_161 ) ;
if ( ! V_113 )
return - V_100 ;
V_73 = F_44 ( & V_2 -> V_74 ) ;
if ( ! V_73 )
return - V_75 ;
V_2 -> V_148 = F_93 ( V_113 * sizeof( * V_2 -> V_148 ) , V_162 ) ;
if ( ! V_2 -> V_148 ) {
V_73 = - V_120 ;
goto V_163;
}
if ( V_2 -> V_8 == V_77 )
F_3 ( V_2 , V_13 ,
V_33 ) ;
F_3 ( V_2 , 0xff , V_51 ) ;
F_79 (chan, iio->active_scan_mask, LRADC_MAX_TOTAL_CHANS) {
V_157 |= V_72 << F_94 ( V_155 ) ;
V_158 |= F_47 ( V_155 ) ;
V_159 |= F_23 ( V_155 ) ;
F_4 ( V_2 , V_144 , F_16 ( V_155 ) ) ;
F_95 ( & V_156 , V_155 , 1 ) ;
V_155 ++ ;
}
F_3 ( V_2 , V_164 |
V_34 , F_21 ( 0 ) ) ;
F_3 ( V_2 , V_158 , V_81 ) ;
F_1 ( V_2 , V_157 , V_81 ) ;
F_1 ( V_2 , V_159 , V_33 ) ;
F_1 ( V_2 , V_156 << V_165 ,
F_21 ( 0 ) ) ;
return 0 ;
V_163:
F_49 ( & V_2 -> V_74 ) ;
return V_73 ;
}
static int F_96 ( struct V_71 * V_111 )
{
struct V_1 * V_2 = F_43 ( V_111 ) ;
F_3 ( V_2 , V_164 |
V_34 , F_21 ( 0 ) ) ;
F_3 ( V_2 , 0xff , V_51 ) ;
if ( V_2 -> V_8 == V_77 )
F_3 ( V_2 , V_13 ,
V_33 ) ;
F_97 ( V_2 -> V_148 ) ;
F_49 ( & V_2 -> V_74 ) ;
return 0 ;
}
static bool F_98 ( struct V_71 * V_111 ,
const unsigned long * V_41 )
{
struct V_1 * V_2 = F_43 ( V_111 ) ;
const int V_166 = F_92 ( V_41 , V_161 ) ;
int V_167 = 0 ;
unsigned long V_168 = 0 ;
if ( V_2 -> V_169 )
V_168 |= V_170 ;
if ( V_2 -> V_119 == V_171 )
V_168 |= V_172 ;
if ( V_2 -> V_119 == V_173 )
V_168 |= V_174 ;
if ( V_2 -> V_169 )
V_167 ++ ;
if ( V_2 -> V_119 )
V_167 ++ ;
if ( F_99 ( V_41 , & V_168 , V_161 ) )
return false ;
if ( V_166 + V_167 > V_175 )
return false ;
return true ;
}
static int F_100 ( struct V_1 * V_2 )
{
const T_4 V_176 =
( 1 << ( V_177 + 0 ) ) |
( V_178 << V_179 ) ;
int V_73 = F_101 ( V_2 -> V_5 ) ;
if ( V_73 )
return V_73 ;
F_4 ( V_2 , V_176 , F_21 ( 0 ) ) ;
F_4 ( V_2 , 0 , F_21 ( 1 ) ) ;
F_4 ( V_2 , 0 , F_21 ( 2 ) ) ;
F_4 ( V_2 , 0 , F_21 ( 3 ) ) ;
if ( V_2 -> V_8 == V_77 ) {
F_3 ( V_2 , V_180 ,
V_51 ) ;
if ( V_2 -> V_119 == V_173 )
F_1 ( V_2 , V_180 ,
V_51 ) ;
}
F_4 ( V_2 , 0 , V_80 ) ;
return 0 ;
}
static void F_102 ( struct V_1 * V_2 )
{
int V_112 ;
F_3 ( V_2 , F_6 ( V_2 ) , V_33 ) ;
for ( V_112 = 0 ; V_112 < V_181 ; V_112 ++ )
F_4 ( V_2 , 0 , F_21 ( V_112 ) ) ;
}
static int F_103 ( struct V_1 * V_2 ,
struct V_182 * V_183 )
{
int V_73 ;
T_1 V_184 = 0 , V_185 ;
V_73 = F_104 ( V_183 , L_7 ,
& V_184 ) ;
if ( V_73 )
return - V_186 ;
switch ( V_184 ) {
case 4 :
V_2 -> V_119 = V_171 ;
break;
case 5 :
if ( V_2 -> V_8 == V_77 ) {
V_2 -> V_119 = V_173 ;
break;
}
default:
F_105 ( V_2 -> V_45 ,
L_8 ,
V_184 ) ;
return - V_100 ;
}
V_2 -> V_30 = 4 ;
V_73 = F_104 ( V_183 , L_9 , & V_185 ) ;
if ( V_73 == 0 )
V_2 -> V_30 = V_185 ;
V_2 -> V_32 = 2 ;
V_73 = F_104 ( V_183 , L_10 , & V_185 ) ;
if ( V_73 == 0 )
V_2 -> V_32 = V_185 ;
V_2 -> V_35 = 10 ;
V_73 = F_104 ( V_183 , L_11 , & V_185 ) ;
if ( V_73 == 0 )
V_2 -> V_35 = V_185 ;
return 0 ;
}
static int F_106 ( struct V_187 * V_188 )
{
const struct V_189 * V_190 =
F_107 ( V_191 , & V_188 -> V_45 ) ;
const struct V_192 * V_193 =
& V_192 [ ( enum V_194 ) V_190 -> V_135 ];
struct V_107 * V_45 = & V_188 -> V_45 ;
struct V_182 * V_195 = V_45 -> V_196 ;
struct V_1 * V_2 ;
struct V_71 * V_111 ;
struct V_197 * V_198 ;
int V_73 = 0 , V_199 ;
int V_112 , V_200 ;
T_5 V_201 ;
V_111 = F_108 ( V_45 , sizeof( * V_2 ) ) ;
if ( ! V_111 ) {
F_105 ( V_45 , L_12 ) ;
return - V_120 ;
}
V_2 = F_43 ( V_111 ) ;
V_2 -> V_8 = (enum V_194 ) V_190 -> V_135 ;
V_198 = F_109 ( V_188 , V_202 , 0 ) ;
V_2 -> V_45 = & V_188 -> V_45 ;
V_2 -> V_5 = F_110 ( V_45 , V_198 ) ;
if ( F_111 ( V_2 -> V_5 ) )
return F_112 ( V_2 -> V_5 ) ;
V_2 -> V_203 = F_113 ( & V_188 -> V_45 , NULL ) ;
if ( F_111 ( V_2 -> V_203 ) ) {
F_105 ( V_45 , L_13 ) ;
return F_112 ( V_2 -> V_203 ) ;
}
V_73 = F_114 ( V_2 -> V_203 ) ;
if ( V_73 != 0 ) {
F_105 ( V_45 , L_14 ) ;
return V_73 ;
}
V_199 = F_103 ( V_2 , V_195 ) ;
for ( V_112 = 0 ; V_112 < V_193 -> V_204 ; V_112 ++ ) {
V_2 -> V_134 [ V_112 ] = F_115 ( V_188 , V_112 ) ;
if ( V_2 -> V_134 [ V_112 ] < 0 )
return V_2 -> V_134 [ V_112 ] ;
V_73 = F_116 ( V_45 , V_2 -> V_134 [ V_112 ] ,
F_74 , 0 ,
V_193 -> V_205 [ V_112 ] , V_111 ) ;
if ( V_73 )
return V_73 ;
}
V_2 -> V_95 = V_193 -> V_95 ;
F_117 ( V_188 , V_111 ) ;
F_118 ( & V_2 -> V_76 ) ;
F_119 ( & V_2 -> V_74 ) ;
V_111 -> V_121 = V_188 -> V_121 ;
V_111 -> V_45 . V_126 = & V_188 -> V_45 ;
V_111 -> V_206 = & V_207 ;
V_111 -> V_208 = V_209 ;
V_111 -> V_210 = V_211 ;
V_111 -> V_212 = F_58 ( V_211 ) ;
V_111 -> V_213 = V_161 ;
V_73 = F_120 ( V_111 , & V_214 ,
& F_78 ,
& V_215 ) ;
if ( V_73 )
return V_73 ;
V_73 = F_84 ( V_111 ) ;
if ( V_73 )
goto V_216;
for ( V_112 = 0 ; V_112 < V_161 ; V_112 ++ ) {
for ( V_200 = 0 ; V_200 < F_58 ( V_2 -> V_102 [ V_112 ] ) ; V_200 ++ ) {
V_201 = ( ( V_217 ) V_2 -> V_95 [ V_112 ] * 100000000 ) >>
( V_46 - V_200 ) ;
V_2 -> V_102 [ V_112 ] [ V_200 ] . V_104 =
F_121 ( V_201 , 100000000 ) * 10 ;
V_2 -> V_102 [ V_112 ] [ V_200 ] . integer = V_201 ;
}
}
V_73 = F_100 ( V_2 ) ;
if ( V_73 )
goto V_218;
if ( V_199 == 0 ) {
V_73 = F_65 ( V_2 ) ;
if ( V_73 )
goto V_219;
}
V_73 = F_122 ( V_111 ) ;
if ( V_73 ) {
F_105 ( V_45 , L_15 ) ;
goto V_220;
}
return 0 ;
V_220:
F_72 ( V_2 ) ;
V_219:
F_102 ( V_2 ) ;
V_218:
F_89 ( V_111 ) ;
V_216:
F_123 ( V_111 ) ;
return V_73 ;
}
static int F_124 ( struct V_187 * V_188 )
{
struct V_71 * V_111 = F_125 ( V_188 ) ;
struct V_1 * V_2 = F_43 ( V_111 ) ;
F_126 ( V_111 ) ;
F_72 ( V_2 ) ;
F_102 ( V_2 ) ;
F_89 ( V_111 ) ;
F_123 ( V_111 ) ;
F_127 ( V_2 -> V_203 ) ;
return 0 ;
}
