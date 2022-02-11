static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_6 + V_3 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_7 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_8 + V_3 ) ;
}
static void F_6 ( struct V_1 * V_9 ,
T_1 V_3 , T_1 V_4 )
{
void T_2 * V_10 = V_9 -> V_11 + V_3 ;
F_2 ( V_4 , V_10 ) ;
}
static bool F_7 ( struct V_12 * V_13 ,
T_1 V_14 , T_1 V_15 )
{
int V_16 ;
F_2 ( V_14 , V_13 -> V_10 ) ;
F_2 ( V_15 , V_13 -> V_13 ) ;
F_2 ( V_17 , V_13 -> V_18 ) ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ ) {
if ( F_8 ( V_13 -> V_19 ) ) {
F_2 ( 0 , V_13 -> V_18 ) ;
return true ;
}
F_9 ( 1 ) ;
}
return false ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_14 , T_1 V_15 )
{
struct V_12 V_13 = {
. V_10 = V_2 -> V_20 + V_21 ,
. V_13 = V_2 -> V_20 + V_22 ,
. V_18 = V_2 -> V_20 + V_23 ,
. V_19 = V_2 -> V_20 + V_24
} ;
if ( ! F_7 ( & V_13 , V_14 , V_15 ) )
F_11 ( V_2 -> V_25 , L_1 , V_14 ) ;
}
static T_1 F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_8 ( V_2 -> V_5 + V_3 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_8 ( V_2 -> V_8 + V_3 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_8 ( V_2 -> V_11 + V_3 ) ;
}
static T_1 F_15 ( struct V_12 * V_13 , T_1 V_26 )
{
T_1 V_27 ;
int V_16 ;
F_2 ( V_26 , V_13 -> V_10 ) ;
F_2 ( V_28 , V_13 -> V_18 ) ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ ) {
if ( F_8 ( V_13 -> V_19 ) ) {
V_27 = F_8 ( V_13 -> V_13 ) ;
F_2 ( 0 , V_13 -> V_18 ) ;
return V_27 ;
}
F_9 ( 1 ) ;
}
F_16 ( L_2 , V_29 , V_26 ) ;
return 0 ;
}
static T_1 F_17 ( struct V_1 * V_2 , T_1 V_26 )
{
struct V_12 V_13 = {
. V_10 = V_2 -> V_20 + V_21 ,
. V_13 = V_2 -> V_20 + V_30 ,
. V_18 = V_2 -> V_20 + V_23 ,
. V_19 = V_2 -> V_20 + V_24
} ;
return F_15 ( & V_13 , V_26 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_31 * V_25 = V_2 -> V_25 ;
T_1 V_32 , V_33 ;
int V_16 = 0 ;
V_33 = F_13 ( V_2 , V_34 ) ;
V_32 = F_13 ( V_2 , V_35 ) ;
if ( ! V_33 && V_32 == ~ 0U ) {
F_19 ( V_25 , L_3 ) ;
return 0 ;
}
F_5 ( V_2 , V_34 , 0 ) ;
do {
F_20 ( 100 , 110 ) ;
V_32 = F_13 ( V_2 , V_35 ) ;
if ( V_32 == ~ 0U )
return 0 ;
} while ( ++ V_16 < 10 );
F_11 ( V_25 , L_4 ) ;
return - V_36 ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_1 V_4 ;
V_4 = ( V_2 -> V_37 == V_38 ) ? 0xffffffff : 0 ;
F_4 ( V_2 , V_39 , V_4 ) ;
F_4 ( V_2 , V_40 , V_4 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_3 V_41 ,
T_1 V_42 , T_4 V_32 )
{
T_1 V_10 , V_15 , V_43 ;
int V_16 ;
V_10 = F_23 ( V_41 ) | F_24 ( V_42 ) ;
F_10 ( V_2 , V_44 , V_10 ) ;
V_15 = F_25 ( V_32 ) ;
F_10 ( V_2 , V_45 , V_15 ) ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ ) {
V_43 = F_17 ( V_2 , V_46 ) ;
if ( ! ( V_43 & V_47 ) )
return;
F_20 ( 10 , 20 ) ;
}
F_11 ( V_2 -> V_25 , L_5 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_3 V_41 , T_1 V_42 )
{
T_1 V_10 , V_32 , V_43 ;
int V_16 ;
V_10 = F_23 ( V_41 ) | F_24 ( V_42 ) ;
F_10 ( V_2 , V_44 , V_10 ) ;
F_10 ( V_2 , V_48 , V_49 ) ;
for ( V_16 = 0 ; V_16 < 10 ; V_16 ++ ) {
V_43 = F_17 ( V_2 , V_46 ) ;
if ( ! ( V_43 & V_47 ) ) {
V_32 = F_17 ( V_2 , V_50 ) ;
F_10 ( V_2 , V_48 , 0 ) ;
return V_32 ;
}
F_20 ( 10 , 20 ) ;
}
F_11 ( V_2 -> V_25 , L_6 ) ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_10 ( V_2 , V_51 , V_52 ) ;
F_10 ( V_2 , V_51 , 0 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_53 , V_54 ;
T_3 * V_55 = V_2 -> V_25 -> V_55 ;
V_53 = ( V_55 [ 3 ] << 24 ) | ( V_55 [ 2 ] << 16 ) |
( V_55 [ 1 ] << 8 ) | V_55 [ 0 ] ;
F_10 ( V_2 , V_56 , V_53 ) ;
V_54 = F_17 ( V_2 , V_57 ) ;
V_54 |= ( V_55 [ 5 ] << 24 ) | ( V_55 [ 4 ] << 16 ) ;
F_10 ( V_2 , V_57 , V_54 ) ;
}
static T_1 F_29 ( struct V_1 * V_2 )
{
T_1 V_32 ;
V_32 = F_26 ( V_2 , V_58 ,
V_59 >> 2 ) ;
if ( F_30 ( V_32 ) == V_60 )
V_2 -> V_61 = V_62 ;
else if ( F_30 ( V_32 ) == V_63 )
V_2 -> V_61 = V_64 ;
else
V_2 -> V_61 = V_65 ;
return V_32 & V_66 ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_58 , V_67 >> 2 ,
0x8000 ) ;
F_22 ( V_2 , V_58 , V_68 >> 2 , 0x9000 ) ;
F_22 ( V_2 , V_58 , V_67 >> 2 , 0 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_58 , V_67 >> 2 ,
0x8000 ) ;
F_22 ( V_2 , V_58 , V_67 >> 2 , 0 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
T_1 V_69 ;
if ( V_2 -> V_61 == V_70 )
return;
V_69 = F_26 ( V_2 , V_58 ,
V_59 >> 2 ) ;
if ( ! ( V_69 & V_66 ) )
F_32 ( V_2 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
T_1 V_71 , V_72 , V_73 ;
T_1 V_74 , V_75 , V_76 ;
T_1 V_77 , V_69 ;
F_33 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 ) {
V_71 = V_78 + V_2 -> V_79 * V_80 ;
V_72 = V_81 + V_2 -> V_79 * V_82 ;
V_73 = V_83 ;
} else {
V_71 = V_84 ;
V_72 = V_85 ;
V_73 = V_86 ;
}
V_74 = F_14 ( V_2 , V_71 ) ;
V_75 = F_14 ( V_2 , V_72 ) ;
V_77 = F_17 ( V_2 , V_87 ) ;
V_76 = F_17 ( V_2 , V_88 ) ;
switch ( V_2 -> V_61 ) {
case V_65 :
F_35 ( & V_77 , 1 ) ;
V_76 &= ~ ( V_89 | V_90 ) ;
F_36 ( & V_74 , 0 ) ;
F_37 ( & V_75 , 500 ) ;
break;
case V_64 :
F_35 ( & V_77 , 1 ) ;
V_76 &= ~ V_90 ;
V_76 |= V_89 ;
F_36 ( & V_74 , 1 ) ;
F_37 ( & V_75 , 80 ) ;
break;
default:
F_35 ( & V_77 , 2 ) ;
V_76 &= ~ V_89 ;
V_76 |= V_90 ;
F_36 ( & V_74 , 2 ) ;
F_37 ( & V_75 , 16 ) ;
V_69 = F_12 ( V_2 , V_73 ) ;
V_69 |= V_91 | V_92 ;
F_1 ( V_2 , V_73 , V_69 ) ;
break;
}
V_77 |= V_93 | V_94 ;
F_10 ( V_2 , V_87 , V_77 ) ;
F_10 ( V_2 , V_88 , V_76 ) ;
F_6 ( V_2 , V_71 , V_74 ) ;
F_6 ( V_2 , V_72 , V_75 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_32 , V_95 = 10 ;
F_31 ( V_2 ) ;
while ( V_95 -- ) {
V_32 = F_26 ( V_2 , V_58 ,
V_96 >> 2 ) ;
if ( ( V_32 & V_97 ) && ( V_32 & V_98 ) )
break;
F_20 ( 1000 , 2000 ) ;
}
if ( ! ( V_32 & V_97 ) || ! ( V_32 & V_98 ) )
F_11 ( V_2 -> V_25 , L_7 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
T_1 V_99 , V_100 ;
T_1 V_101 , V_102 ;
T_1 V_32 , V_3 ;
if ( ! ( V_2 -> V_37 == V_103 && V_2 -> V_104 ) )
F_27 ( V_2 ) ;
F_38 ( V_2 ) ;
F_34 ( V_2 ) ;
F_28 ( V_2 ) ;
if ( V_2 -> V_37 == V_38 ) {
V_99 = V_105 ;
V_100 = V_106 ;
V_101 = V_107 ;
V_3 = V_2 -> V_79 * V_82 ;
V_102 = V_108 + V_3 ;
} else {
V_99 = V_109 ;
V_100 = V_110 ;
V_101 = V_111 ;
V_102 = V_112 ;
}
V_32 = F_12 ( V_2 , V_99 ) ;
V_32 |= V_113 ;
F_1 ( V_2 , V_99 , V_32 ) ;
V_32 = F_17 ( V_2 , V_114 ) ;
F_40 ( & V_32 , 7 ) ;
F_10 ( V_2 , V_114 , V_32 ) ;
V_32 = F_12 ( V_2 , V_100 ) ;
V_32 |= V_115 ;
F_1 ( V_2 , V_100 , V_32 ) ;
F_1 ( V_2 , V_116 , 0x84 ) ;
F_1 ( V_2 , V_101 , V_117 ) ;
F_6 ( V_2 , V_102 , V_118 ) ;
}
static void F_41 ( struct V_1 * V_2 , T_1 V_119 , bool V_120 )
{
T_1 V_32 ;
V_32 = F_17 ( V_2 , V_51 ) ;
if ( V_120 )
V_32 |= V_119 ;
else
V_32 &= ~ V_119 ;
F_10 ( V_2 , V_51 , V_32 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_41 ( V_2 , V_121 , true ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
F_41 ( V_2 , V_122 , true ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_41 ( V_2 , V_121 , false ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_41 ( V_2 , V_122 , false ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = & V_2 -> V_125 -> V_124 ;
if ( ! F_47 ( V_2 ) )
return - V_36 ;
if ( V_2 -> V_104 && V_2 -> V_37 == V_103 ) {
F_21 ( V_2 ) ;
return 0 ;
}
if ( V_2 -> V_37 == V_103 )
F_3 ( V_2 , V_126 , V_127 ) ;
if ( V_124 -> V_128 ) {
if ( ! F_48 ( V_2 -> V_129 ) ) {
F_49 ( V_2 -> V_129 ) ;
F_9 ( 5 ) ;
F_50 ( V_2 -> V_129 ) ;
F_9 ( 5 ) ;
F_49 ( V_2 -> V_129 ) ;
F_9 ( 5 ) ;
}
} else {
#ifdef F_51
if ( F_52 ( F_53 ( & V_2 -> V_125 -> V_124 ) , L_8 ) )
F_54 ( F_53 ( & V_2 -> V_125 -> V_124 ) ,
L_8 , NULL , NULL ) ;
else if ( F_52 ( F_53 ( & V_2 -> V_125 -> V_124 ) , L_9 ) )
F_54 ( F_53 ( & V_2 -> V_125 -> V_124 ) ,
L_9 , NULL , NULL ) ;
#endif
}
if ( ! V_2 -> V_79 ) {
F_18 ( V_2 ) ;
F_21 ( V_2 ) ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 ,
T_1 V_130 , T_4 V_131 )
{
T_1 V_32 , V_132 ;
T_1 V_133 , V_134 ;
T_1 V_3 = V_2 -> V_79 * V_135 ;
if ( V_2 -> V_37 == V_38 ) {
V_133 = V_136 ;
V_134 = V_137 ;
} else {
V_133 = V_138 ;
V_134 = V_139 ;
}
V_32 = V_140 ;
F_1 ( V_2 , V_133 + V_3 , V_32 ) ;
V_132 = F_56 ( V_131 ) - 0x20 ;
V_32 = F_57 ( V_130 ) | F_58 ( V_132 ) ;
F_1 ( V_2 , V_134 + V_3 , V_32 ) ;
}
static void F_59 ( struct V_1 * V_9 ,
struct V_141 * V_142 )
{
T_1 V_10 , V_4 , V_32 ;
V_4 = F_56 ( V_142 -> V_143 ) ;
if ( F_60 ( V_142 -> V_143 ) ) {
V_10 = V_144 ;
V_32 = F_61 ( V_4 - 0x20 ) ;
} else {
V_10 = V_145 ;
V_32 = F_61 ( V_4 ) ;
}
F_4 ( V_9 , V_10 , V_32 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_123 * V_124 = & V_2 -> V_125 -> V_124 ;
struct V_141 * V_142 ;
T_1 V_146 , V_4 ;
int V_16 ;
V_146 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_147 ; V_16 ++ ) {
V_142 = V_2 -> V_148 [ V_16 ] -> V_149 ;
V_4 = F_56 ( V_142 -> V_143 ) ;
V_146 |= F_61 ( V_4 - 0x20 ) ;
}
F_4 ( V_2 , V_144 , V_146 ) ;
V_146 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_150 ; V_16 ++ ) {
V_142 = V_2 -> V_151 [ V_16 ] ;
V_4 = F_56 ( V_142 -> V_143 ) ;
V_146 |= F_61 ( V_4 ) ;
}
F_4 ( V_2 , V_145 , V_146 ) ;
if ( V_124 -> V_128 ) {
if ( ! F_48 ( V_2 -> V_129 ) )
F_50 ( V_2 -> V_129 ) ;
}
}
static void F_63 ( struct V_152 * V_153 )
{
struct V_1 * V_2 = F_64 ( F_65 ( V_153 ) ,
struct V_1 , V_154 ) ;
struct V_31 * V_25 = V_2 -> V_25 ;
T_1 V_155 , V_156 ;
V_155 = F_29 ( V_2 ) ;
if ( V_155 ) {
if ( ! F_66 ( V_25 ) ) {
F_67 ( V_25 ) ;
F_34 ( V_2 ) ;
F_42 ( V_2 ) ;
F_43 ( V_2 ) ;
F_68 ( V_25 , L_10 ,
V_2 -> V_61 ) ;
}
V_156 = V_157 ;
} else {
if ( F_66 ( V_25 ) ) {
F_44 ( V_2 ) ;
F_45 ( V_2 ) ;
F_69 ( V_25 ) ;
F_68 ( V_25 , L_11 ) ;
}
V_156 = V_158 ;
}
F_70 ( & V_2 -> V_154 , V_156 ) ;
}
