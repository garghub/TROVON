int F_1 ( int V_1 , int V_2 , int V_3 )
{
int V_4 = V_1 - V_2 ;
if ( V_4 <= 0 )
V_4 += V_3 ;
return V_4 - V_5 ;
}
void F_2 ( struct V_6 * V_7 )
{
if ( V_7 -> V_8 != - 1 ) {
V_7 -> V_1 = V_7 -> V_8 ;
V_7 -> V_8 = - 1 ;
}
V_7 -> V_4 = F_1 ( V_7 -> V_1 & V_9 ,
V_7 -> V_2 , V_7 -> V_3 ) ;
}
static int
F_3 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_13 ;
int V_14 ;
V_13 = V_15 ;
if ( V_12 & V_16 )
V_13 |= V_17 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_7 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_13 ;
int V_14 ;
V_13 = V_15 ;
if ( V_12 & V_16 ) {
V_13 |= V_19 ;
if ( F_8 ( V_11 -> V_20 ) || F_9 ( V_11 -> V_20 ) )
V_13 |= V_21 ;
}
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_10 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_22 =
F_11 ( V_11 -> V_23 -> V_24 ) + 2 * V_25 ;
int V_14 ;
V_14 = F_4 ( V_11 , 6 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_12 ( 5 ) ) ;
F_5 ( V_7 , V_26 |
V_27 ) ;
F_5 ( V_7 , V_22 | V_28 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_14 = F_4 ( V_11 , 6 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_12 ( 5 ) ) ;
F_5 ( V_7 , V_29 ) ;
F_5 ( V_7 , V_22 | V_28 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_13 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_22 =
F_11 ( V_11 -> V_23 -> V_24 ) + 2 * V_25 ;
T_1 V_30 = 0 ;
int V_14 ;
V_14 = F_10 ( V_11 ) ;
if ( V_14 )
return V_14 ;
if ( V_12 & V_31 ) {
V_30 |= V_32 ;
V_30 |= V_33 ;
V_30 |= V_26 ;
}
if ( V_12 & V_16 ) {
V_30 |= V_34 ;
V_30 |= V_35 ;
V_30 |= V_36 ;
V_30 |= V_37 ;
V_30 |= V_38 ;
V_30 |= V_39 ;
V_30 |= V_29 | V_26 ;
}
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_12 ( 4 ) ) ;
F_5 ( V_7 , V_30 ) ;
F_5 ( V_7 , V_22 | V_28 ) ;
F_5 ( V_7 , 0 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_14 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_12 ( 4 ) ) ;
F_5 ( V_7 ,
V_26 |
V_27 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , 0 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_15 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_22 =
F_11 ( V_11 -> V_23 -> V_24 ) + 2 * V_25 ;
T_1 V_30 = 0 ;
int V_14 ;
V_30 |= V_26 ;
if ( V_12 & V_31 ) {
V_30 |= V_32 ;
V_30 |= V_33 ;
V_30 |= V_40 ;
V_30 |= V_41 ;
}
if ( V_12 & V_16 ) {
V_30 |= V_34 ;
V_30 |= V_35 ;
V_30 |= V_36 ;
V_30 |= V_37 ;
V_30 |= V_38 ;
V_30 |= V_39 ;
V_30 |= V_42 ;
V_30 |= V_29 ;
V_30 |= V_43 ;
V_30 |= V_27 ;
F_14 ( V_11 ) ;
}
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_12 ( 4 ) ) ;
F_5 ( V_7 , V_30 ) ;
F_5 ( V_7 , V_22 ) ;
F_5 ( V_7 , 0 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_16 ( struct V_10 * V_11 ,
T_1 V_30 , T_1 V_22 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 6 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_12 ( 6 ) ) ;
F_5 ( V_7 , V_30 ) ;
F_5 ( V_7 , V_22 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , 0 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_17 ( struct V_10 * V_11 , T_1 V_12 )
{
T_1 V_22 =
F_11 ( V_11 -> V_23 -> V_24 ) + 2 * V_25 ;
T_1 V_30 = 0 ;
int V_14 ;
V_30 |= V_26 ;
if ( V_12 & V_31 ) {
V_30 |= V_32 ;
V_30 |= V_33 ;
V_30 |= V_40 ;
V_30 |= V_41 ;
}
if ( V_12 & V_16 ) {
V_30 |= V_34 ;
V_30 |= V_35 ;
V_30 |= V_36 ;
V_30 |= V_37 ;
V_30 |= V_38 ;
V_30 |= V_39 ;
V_30 |= V_29 ;
V_30 |= V_43 ;
V_14 = F_16 ( V_11 ,
V_26 |
V_27 ,
0 ) ;
if ( V_14 )
return V_14 ;
}
return F_16 ( V_11 , V_30 , V_22 ) ;
}
static void F_18 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_1 V_47 ;
V_47 = V_46 -> V_48 -> V_49 ;
if ( F_19 ( V_46 ) >= 4 )
V_47 |= ( V_46 -> V_48 -> V_49 >> 28 ) & 0xf0 ;
F_20 ( V_50 , V_47 ) ;
}
static void F_21 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_2 V_51 ;
if ( F_22 ( V_46 ) ) {
switch ( V_23 -> V_52 ) {
case V_53 :
V_51 = V_54 ;
break;
case V_55 :
V_51 = V_56 ;
break;
case V_57 :
case V_58 :
V_51 = V_59 ;
break;
case V_60 :
V_51 = V_61 ;
break;
}
} else if ( F_23 ( V_46 ) ) {
V_51 = F_24 ( V_23 -> V_62 ) ;
} else {
V_51 = F_25 ( V_23 -> V_62 ) ;
}
F_20 ( V_51 , V_23 -> V_63 . V_64 ) ;
F_26 ( V_51 ) ;
if ( F_27 ( V_46 , 6 , 7 ) ) {
T_2 V_65 = F_28 ( V_23 -> V_62 ) ;
F_29 ( ( F_30 ( V_23 ) & V_66 ) == 0 ) ;
F_20 ( V_65 ,
F_31 ( V_67 |
V_68 ) ) ;
if ( F_32 ( V_46 ,
V_65 , V_68 , 0 ,
1000 ) )
F_33 ( L_1 ,
V_23 -> V_69 ) ;
}
}
static bool F_34 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
if ( F_19 ( V_46 ) > 2 ) {
F_35 ( V_23 , F_31 ( V_70 ) ) ;
if ( F_32 ( V_46 ,
F_36 ( V_23 -> V_62 ) ,
V_66 ,
V_66 ,
1000 ) ) {
F_33 ( L_2 ,
V_23 -> V_69 ) ;
if ( F_37 ( V_23 ) != F_38 ( V_23 ) )
return false ;
}
}
F_39 ( V_23 , 0 ) ;
F_40 ( V_23 , 0 ) ;
F_41 ( V_23 , 0 ) ;
if ( F_19 ( V_46 ) > 2 ) {
( void ) F_42 ( V_23 ) ;
F_35 ( V_23 , F_43 ( V_70 ) ) ;
}
return ( F_37 ( V_23 ) & V_9 ) == 0 ;
}
static int F_44 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_6 * V_7 = V_23 -> V_71 ;
int V_14 = 0 ;
F_45 ( V_46 , V_72 ) ;
if ( ! F_34 ( V_23 ) ) {
F_46 ( L_3
L_4 ,
V_23 -> V_69 ,
F_42 ( V_23 ) ,
F_37 ( V_23 ) ,
F_38 ( V_23 ) ,
F_47 ( V_23 ) ) ;
if ( ! F_34 ( V_23 ) ) {
F_33 ( L_5
L_4 ,
V_23 -> V_69 ,
F_42 ( V_23 ) ,
F_37 ( V_23 ) ,
F_38 ( V_23 ) ,
F_47 ( V_23 ) ) ;
V_14 = - V_73 ;
goto V_74;
}
}
if ( F_48 ( V_46 ) )
F_18 ( V_23 ) ;
else
F_21 ( V_23 ) ;
F_49 ( V_23 ) ;
F_37 ( V_23 ) ;
F_50 ( V_23 , F_11 ( V_7 -> V_75 ) ) ;
if ( F_37 ( V_23 ) )
F_51 ( L_6 ,
V_23 -> V_69 , F_37 ( V_23 ) ) ;
F_2 ( V_7 ) ;
F_40 ( V_23 , V_7 -> V_1 ) ;
F_41 ( V_23 , V_7 -> V_2 ) ;
( void ) F_38 ( V_23 ) ;
F_39 ( V_23 , F_52 ( V_7 -> V_3 ) | V_76 ) ;
if ( F_53 ( V_46 , F_54 ( V_23 -> V_62 ) ,
V_76 , V_76 ,
50 ) ) {
F_33 ( L_7
L_8 ,
V_23 -> V_69 ,
F_42 ( V_23 ) ,
F_42 ( V_23 ) & V_76 ,
F_37 ( V_23 ) , V_7 -> V_1 ,
F_38 ( V_23 ) , V_7 -> V_2 ,
F_47 ( V_23 ) ,
F_11 ( V_7 -> V_75 ) ) ;
V_14 = - V_73 ;
goto V_74;
}
F_55 ( V_23 ) ;
V_74:
F_56 ( V_46 , V_72 ) ;
return V_14 ;
}
static void F_57 ( struct V_44 * V_23 ,
struct V_10 * V_77 )
{
struct V_6 * V_7 = V_77 -> V_7 ;
V_7 -> V_1 = V_77 -> V_78 ;
V_7 -> V_8 = - 1 ;
}
static int F_58 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_79 * V_80 = & V_11 -> V_20 -> V_81 ;
int V_14 , V_82 ;
if ( V_80 -> V_83 == 0 )
return 0 ;
V_14 = V_11 -> V_23 -> V_84 ( V_11 , V_85 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_11 , ( V_80 -> V_83 * 2 + 2 ) ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_59 ( V_80 -> V_83 ) ) ;
for ( V_82 = 0 ; V_82 < V_80 -> V_83 ; V_82 ++ ) {
F_60 ( V_7 , V_80 -> V_65 [ V_82 ] . V_47 ) ;
F_5 ( V_7 , V_80 -> V_65 [ V_82 ] . V_86 ) ;
}
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_14 = V_11 -> V_23 -> V_84 ( V_11 , V_85 ) ;
if ( V_14 )
return V_14 ;
F_61 ( L_9 , V_80 -> V_83 ) ;
return 0 ;
}
static int F_62 ( struct V_10 * V_11 )
{
int V_14 ;
V_14 = F_58 ( V_11 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_63 ( V_11 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_64 ( struct V_45 * V_46 ,
T_2 V_47 ,
const T_1 V_87 , const T_1 V_88 )
{
const T_1 V_89 = V_46 -> V_81 . V_83 ;
if ( F_29 ( V_89 >= V_90 ) )
return - V_91 ;
V_46 -> V_81 . V_65 [ V_89 ] . V_47 = V_47 ;
V_46 -> V_81 . V_65 [ V_89 ] . V_86 = V_88 ;
V_46 -> V_81 . V_65 [ V_89 ] . V_87 = V_87 ;
V_46 -> V_81 . V_83 ++ ;
return 0 ;
}
static int F_65 ( struct V_44 * V_23 ,
T_2 V_65 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_79 * V_92 = & V_46 -> V_81 ;
const T_3 V_93 = V_92 -> V_94 [ V_23 -> V_52 ] ;
if ( F_29 ( V_93 >= V_95 ) )
return - V_96 ;
F_66 ( F_67 ( V_23 -> V_62 , V_93 ) ,
F_68 ( V_65 ) ) ;
V_92 -> V_94 [ V_23 -> V_52 ] ++ ;
return 0 ;
}
static int F_69 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_70 ( V_97 , V_98 ) ;
F_70 ( V_99 , V_100 ) ;
F_70 ( V_101 ,
V_102 ) ;
F_70 ( V_103 ,
V_104 |
V_105 ) ;
F_71 ( V_106 , V_107 ) ;
F_70 ( V_108 , V_109 ) ;
F_72 ( V_110 ,
V_111 ,
V_112 ) ;
return 0 ;
}
static int F_73 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_69 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_70 ( V_101 , V_113 ) ;
F_70 ( V_114 ,
V_115 ) ;
F_70 ( V_116 ,
V_117 ) ;
F_70 ( V_103 ,
V_118 |
( F_74 ( V_46 ) ? V_119 : 0 ) ) ;
return 0 ;
}
static int F_75 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_69 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_70 ( V_101 , V_113 ) ;
F_70 ( V_120 , V_121 ) ;
return 0 ;
}
static int F_76 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
F_20 ( V_122 , F_31 ( V_123 ) ) ;
F_20 ( V_124 , F_77 ( V_124 ) |
V_125 ) ;
F_20 ( V_126 , F_77 ( V_126 ) |
V_127 ) ;
F_70 ( V_101 ,
V_128 |
V_102 ) ;
F_70 ( V_116 ,
V_129 ) ;
if ( F_78 ( V_46 , 0 , V_130 ) )
F_71 ( V_131 ,
V_132 ) ;
if ( F_78 ( V_46 , 0 , V_130 ) ) {
F_70 ( V_133 ,
V_134 ) ;
}
F_70 ( V_135 ,
V_136 ) ;
F_70 ( V_108 , ( V_109 |
V_137 ) ) ;
F_71 ( V_131 ,
V_138 ) ;
if ( F_78 ( V_46 , 0 , V_130 ) )
F_70 ( V_139 ,
V_140 ) ;
F_70 ( V_103 ,
V_118 |
V_141 ) ;
F_70 ( V_103 ,
V_105 ) ;
F_20 ( V_126 , F_77 ( V_126 ) |
V_142 ) ;
if ( F_79 ( V_46 ) ||
F_80 ( V_46 ) ||
F_78 ( V_46 , 0 , V_143 ) )
F_70 ( V_116 ,
V_117 ) ;
F_70 ( V_144 , V_145 ) ;
F_20 ( V_146 , ( F_77 ( V_146 ) |
V_147 ) ) ;
V_14 = F_65 ( V_23 , V_148 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_65 ( V_23 , V_149 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_65 ( V_23 , V_150 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_81 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_4 V_151 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_82 ;
for ( V_82 = 0 ; V_82 < 3 ; V_82 ++ ) {
T_4 V_152 ;
if ( ! F_82 ( F_83 ( V_46 ) -> V_153 . V_154 [ V_82 ] ) )
continue;
V_152 = F_84 ( F_83 ( V_46 ) -> V_153 . V_154 [ V_82 ] ) - 1 ;
V_151 [ V_82 ] = 3 - V_152 ;
}
if ( V_151 [ 0 ] == 0 && V_151 [ 1 ] == 0 && V_151 [ 2 ] == 0 )
return 0 ;
F_72 ( V_110 ,
F_85 ( 2 ) |
F_85 ( 1 ) |
F_85 ( 0 ) ,
F_86 ( 2 , V_151 [ 2 ] ) |
F_86 ( 1 , V_151 [ 1 ] ) |
F_86 ( 0 , V_151 [ 0 ] ) ) ;
return 0 ;
}
static int F_87 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_76 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_20 ( V_155 ,
F_31 ( V_156 ) ) ;
F_20 ( V_157 , ( F_77 ( V_157 ) |
V_158 ) ) ;
F_88 ( V_159 , V_160 ) ;
if ( F_89 ( V_46 , V_161 , V_162 ) )
F_88 ( V_163 ,
V_164 ) ;
V_14 = F_65 ( V_23 , V_146 ) ;
if ( V_14 )
return V_14 ;
return F_81 ( V_23 ) ;
}
static int F_90 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_76 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_78 ( V_46 , 0 , V_130 ) )
F_20 ( V_165 , F_77 ( V_165 ) | V_166 ) ;
if ( F_78 ( V_46 , 0 , V_130 ) ) {
F_20 ( V_167 , ( F_77 ( V_167 ) &
~ V_168 ) ) ;
}
F_70 ( V_101 ,
V_113 ) ;
if ( F_78 ( V_46 , V_143 , V_162 ) ) {
F_70 ( V_169 ,
V_170 ) ;
}
if ( F_78 ( V_46 , 0 , V_143 ) ) {
F_70 (
V_171 ,
V_172 ) ;
}
if ( F_78 ( V_46 , 0 , V_130 ) ) {
V_14 = F_65 ( V_23 , V_173 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_65 ( V_23 , V_146 ) ;
if ( V_14 )
return V_14 ;
}
if ( F_78 ( V_46 , V_143 , V_162 ) )
F_20 ( V_174 , F_91 ( 62 ) |
F_92 ( 2 ) ) ;
if ( F_78 ( V_46 , V_175 , V_162 ) )
F_70 ( V_176 ,
V_177 ) ;
if ( F_78 ( V_46 , V_175 , V_162 ) )
F_88 ( V_163 ,
V_164 ) ;
return 0 ;
}
static int F_93 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_76 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_20 ( V_157 , ( F_77 ( V_157 ) |
V_158 ) ) ;
if ( F_94 ( V_46 , 0 , V_178 ) )
F_88 ( V_179 ,
V_180 ) ;
if ( F_94 ( V_46 , V_181 , V_181 ) )
F_70 ( V_103 ,
V_119 ) ;
if ( F_94 ( V_46 , V_182 , V_162 ) )
F_70 ( V_176 ,
V_177 ) ;
F_88 ( V_159 , V_160 ) ;
F_70 (
V_171 ,
V_172 ) ;
F_88 ( V_163 ,
V_164 ) ;
V_14 = F_65 ( V_23 , V_146 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
int F_95 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_29 ( V_23 -> V_52 != V_53 ) ;
V_46 -> V_81 . V_83 = 0 ;
V_46 -> V_81 . V_94 [ V_53 ] = 0 ;
if ( F_96 ( V_46 ) )
return F_73 ( V_23 ) ;
if ( F_97 ( V_46 ) )
return F_75 ( V_23 ) ;
if ( F_79 ( V_46 ) )
return F_87 ( V_23 ) ;
if ( F_98 ( V_46 ) )
return F_90 ( V_23 ) ;
if ( F_80 ( V_46 ) )
return F_93 ( V_23 ) ;
return 0 ;
}
static int F_99 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 = F_44 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_27 ( V_46 , 4 , 6 ) )
F_20 ( V_99 , F_31 ( V_183 ) ) ;
if ( F_27 ( V_46 , 6 , 7 ) )
F_20 ( V_99 , F_31 ( V_100 ) ) ;
if ( F_23 ( V_46 ) )
F_20 ( V_184 ,
F_31 ( V_185 ) ) ;
if ( F_22 ( V_46 ) )
F_20 ( V_186 ,
F_31 ( V_185 ) |
F_31 ( V_187 ) ) ;
if ( F_23 ( V_46 ) ) {
F_20 ( V_188 ,
F_43 ( V_189 ) ) ;
}
if ( F_27 ( V_46 , 6 , 7 ) )
F_20 ( V_97 , F_31 ( V_98 ) ) ;
if ( F_83 ( V_46 ) -> V_190 >= 6 )
F_100 ( V_23 , ~ V_23 -> V_191 ) ;
return F_95 ( V_23 ) ;
}
static void F_101 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_102 ( & V_46 -> V_192 ) ;
}
static T_1 * F_103 ( struct V_10 * V_11 , T_1 * V_74 )
{
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_193 ;
enum V_194 V_52 ;
F_104 (waiter, dev_priv, id) {
T_5 V_195 = V_11 -> V_23 -> V_192 . V_196 [ V_52 ] ;
if ( V_195 == V_197 )
continue;
* V_74 ++ = F_12 ( 6 ) ;
* V_74 ++ = ( V_43 |
V_29 |
V_26 ) ;
* V_74 ++ = F_105 ( V_195 ) ;
* V_74 ++ = F_106 ( V_195 ) ;
* V_74 ++ = V_11 -> V_198 ;
* V_74 ++ = 0 ;
* V_74 ++ = ( V_199 |
F_107 ( V_193 -> V_200 ) ) ;
* V_74 ++ = 0 ;
}
return V_74 ;
}
static T_1 * F_108 ( struct V_10 * V_11 , T_1 * V_74 )
{
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_193 ;
enum V_194 V_52 ;
F_104 (waiter, dev_priv, id) {
T_5 V_195 = V_11 -> V_23 -> V_192 . V_196 [ V_52 ] ;
if ( V_195 == V_197 )
continue;
* V_74 ++ = ( V_201 + 1 ) | V_202 ;
* V_74 ++ = F_105 ( V_195 ) | V_203 ;
* V_74 ++ = F_106 ( V_195 ) ;
* V_74 ++ = V_11 -> V_198 ;
* V_74 ++ = ( V_199 |
F_107 ( V_193 -> V_200 ) ) ;
* V_74 ++ = 0 ;
}
return V_74 ;
}
static T_1 * F_109 ( struct V_10 * V_11 , T_1 * V_74 )
{
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_23 ;
enum V_194 V_52 ;
int V_204 = 0 ;
F_104 (engine, dev_priv, id) {
T_2 V_205 ;
if ( ! ( F_110 ( V_23 -> V_200 ) & V_206 ) )
continue;
V_205 = V_11 -> V_23 -> V_192 . V_207 . signal [ V_23 -> V_200 ] ;
if ( F_111 ( V_205 ) ) {
* V_74 ++ = F_59 ( 1 ) ;
* V_74 ++ = F_68 ( V_205 ) ;
* V_74 ++ = V_11 -> V_198 ;
V_204 ++ ;
}
}
if ( V_204 & 1 )
* V_74 ++ = V_18 ;
return V_74 ;
}
static void F_112 ( struct V_10 * V_77 )
{
struct V_45 * V_46 = V_77 -> V_20 ;
F_113 ( V_77 ) ;
F_41 ( V_77 -> V_23 , V_77 -> V_2 ) ;
}
static void F_114 ( struct V_10 * V_11 ,
T_1 * V_74 )
{
* V_74 ++ = V_208 ;
* V_74 ++ = V_209 << V_210 ;
* V_74 ++ = V_11 -> V_198 ;
* V_74 ++ = V_211 ;
V_11 -> V_2 = F_115 ( V_11 -> V_7 , V_74 ) ;
}
static void F_116 ( struct V_10 * V_11 ,
T_1 * V_74 )
{
return F_114 ( V_11 ,
V_11 -> V_23 -> V_192 . signal ( V_11 , V_74 ) ) ;
}
static void F_117 ( struct V_10 * V_11 ,
T_1 * V_74 )
{
struct V_44 * V_23 = V_11 -> V_23 ;
if ( V_23 -> V_192 . signal )
V_74 = V_23 -> V_192 . signal ( V_11 , V_74 ) ;
* V_74 ++ = F_12 ( 6 ) ;
* V_74 ++ = ( V_43 |
V_26 |
V_29 ) ;
* V_74 ++ = F_118 ( V_23 ) ;
* V_74 ++ = 0 ;
* V_74 ++ = V_11 -> V_198 ;
* V_74 ++ = 0 ;
* V_74 ++ = V_211 ;
* V_74 ++ = V_18 ;
V_11 -> V_2 = F_115 ( V_11 -> V_7 , V_74 ) ;
}
static int
F_119 ( struct V_10 * V_11 ,
struct V_10 * signal )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_45 * V_46 = V_11 -> V_20 ;
T_5 V_212 = F_120 ( V_11 -> V_23 , signal -> V_23 -> V_52 ) ;
struct V_213 * V_214 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_215 |
V_216 |
V_217 ) ;
F_5 ( V_7 , signal -> V_198 ) ;
F_5 ( V_7 , F_105 ( V_212 ) ) ;
F_5 ( V_7 , F_106 ( V_212 ) ) ;
F_6 ( V_7 ) ;
V_214 = V_11 -> V_218 -> V_214 ;
if ( V_214 && V_11 -> V_23 -> V_52 != V_53 )
V_214 -> V_219 |= F_121 ( V_11 -> V_23 ) ;
return 0 ;
}
static int
F_122 ( struct V_10 * V_11 ,
struct V_10 * signal )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_220 = V_221 |
V_222 |
V_223 ;
T_1 V_224 = signal -> V_23 -> V_192 . V_207 . V_225 [ V_11 -> V_23 -> V_200 ] ;
int V_14 ;
F_29 ( V_224 == V_197 ) ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_220 | V_224 ) ;
F_5 ( V_7 , signal -> V_198 - 1 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void
F_123 ( struct V_44 * V_23 )
{
F_124 ( 125 , 250 ) ;
}
static void
F_125 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_126 ( & V_46 -> V_226 . V_227 ) ;
F_127 ( F_128 ( V_23 -> V_62 ) ) ;
F_129 ( & V_46 -> V_226 . V_227 ) ;
}
static void
F_130 ( struct V_44 * V_23 )
{
F_131 ( V_23 -> V_20 , V_23 -> V_228 ) ;
}
static void
F_132 ( struct V_44 * V_23 )
{
F_133 ( V_23 -> V_20 , V_23 -> V_228 ) ;
}
static void
F_134 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_229 &= ~ V_23 -> V_228 ;
F_20 ( V_230 , V_46 -> V_229 ) ;
F_127 ( F_135 ( V_23 -> V_62 ) ) ;
}
static void
F_136 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_229 |= V_23 -> V_228 ;
F_20 ( V_230 , V_46 -> V_229 ) ;
}
static void
F_137 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_229 &= ~ V_23 -> V_228 ;
F_138 ( V_230 , V_46 -> V_229 ) ;
F_139 ( F_135 ( V_23 -> V_62 ) ) ;
}
static void
F_140 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_229 |= V_23 -> V_228 ;
F_138 ( V_230 , V_46 -> V_229 ) ;
}
static int
F_141 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_15 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void
F_142 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_100 ( V_23 ,
~ ( V_23 -> V_228 |
V_23 -> V_191 ) ) ;
F_131 ( V_46 , V_23 -> V_228 ) ;
}
static void
F_143 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_100 ( V_23 , ~ V_23 -> V_191 ) ;
F_133 ( V_46 , V_23 -> V_228 ) ;
}
static void
F_144 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_100 ( V_23 , ~ V_23 -> V_228 ) ;
F_145 ( V_46 , V_23 -> V_228 ) ;
}
static void
F_146 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_100 ( V_23 , ~ 0 ) ;
F_147 ( V_46 , V_23 -> V_228 ) ;
}
static void
F_148 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_100 ( V_23 ,
~ ( V_23 -> V_228 |
V_23 -> V_191 ) ) ;
F_127 ( F_135 ( V_23 -> V_62 ) ) ;
}
static void
F_149 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_100 ( V_23 , ~ V_23 -> V_191 ) ;
}
static int
F_150 ( struct V_10 * V_11 ,
T_5 V_212 , T_1 V_231 ,
unsigned int V_232 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_233 |
V_234 |
( V_232 & V_235 ?
0 : V_236 ) ) ;
F_5 ( V_7 , V_212 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_151 ( struct V_10 * V_11 ,
T_5 V_212 , T_1 V_237 ,
unsigned int V_232 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_238 = F_11 ( V_11 -> V_23 -> V_24 ) ;
int V_14 ;
V_14 = F_4 ( V_11 , 6 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_239 | V_240 ) ;
F_5 ( V_7 , V_241 | V_242 | 4096 ) ;
F_5 ( V_7 , V_243 << 16 | 4 ) ;
F_5 ( V_7 , V_238 ) ;
F_5 ( V_7 , 0xdeadbeef ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
if ( ( V_232 & V_244 ) == 0 ) {
if ( V_237 > V_245 )
return - V_91 ;
V_14 = F_4 ( V_11 , 6 + 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_246 | V_240 ) ;
F_5 ( V_7 ,
V_241 | V_247 | 4096 ) ;
F_5 ( V_7 , F_152 ( V_237 , 4096 ) << 16 | 4096 ) ;
F_5 ( V_7 , V_238 ) ;
F_5 ( V_7 , 4096 ) ;
F_5 ( V_7 , V_212 ) ;
F_5 ( V_7 , V_15 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_212 = V_238 ;
}
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_233 | V_234 ) ;
F_5 ( V_7 , V_212 | ( V_232 & V_235 ?
0 : V_248 ) ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_153 ( struct V_10 * V_11 ,
T_5 V_212 , T_1 V_237 ,
unsigned int V_232 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_233 | V_234 ) ;
F_5 ( V_7 , V_212 | ( V_232 & V_235 ?
0 : V_248 ) ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void F_154 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
if ( ! V_46 -> V_48 )
return;
F_155 ( & V_46 -> V_249 , V_46 -> V_48 ) ;
V_23 -> V_63 . V_250 = NULL ;
}
static void F_156 ( struct V_44 * V_23 )
{
struct V_251 * V_75 ;
struct V_252 * V_253 ;
V_75 = F_157 ( & V_23 -> V_63 . V_75 ) ;
if ( ! V_75 )
return;
V_253 = V_75 -> V_253 ;
F_158 ( V_75 ) ;
F_159 ( V_75 ) ;
F_160 ( V_253 ) ;
F_161 ( V_253 ) ;
}
static int F_162 ( struct V_44 * V_23 )
{
struct V_252 * V_253 ;
struct V_251 * V_75 ;
unsigned int V_30 ;
void * V_254 ;
int V_14 ;
V_253 = F_163 ( V_23 -> V_20 , 4096 ) ;
if ( F_164 ( V_253 ) ) {
F_33 ( L_10 ) ;
return F_165 ( V_253 ) ;
}
V_14 = F_166 ( V_253 , V_255 ) ;
if ( V_14 )
goto V_256;
V_75 = F_167 ( V_253 , & V_23 -> V_20 -> V_257 . V_258 , NULL ) ;
if ( F_164 ( V_75 ) ) {
V_14 = F_165 ( V_75 ) ;
goto V_256;
}
V_30 = V_259 ;
if ( ! F_168 ( V_23 -> V_20 ) )
V_30 |= V_260 ;
V_14 = F_169 ( V_75 , 0 , 4096 , V_30 ) ;
if ( V_14 )
goto V_256;
V_254 = F_170 ( V_253 , V_261 ) ;
if ( F_164 ( V_254 ) ) {
V_14 = F_165 ( V_254 ) ;
goto V_262;
}
V_23 -> V_63 . V_75 = V_75 ;
V_23 -> V_63 . V_64 = F_11 ( V_75 ) ;
V_23 -> V_63 . V_250 = memset ( V_254 , 0 , 4096 ) ;
F_61 ( L_11 ,
V_23 -> V_69 , F_11 ( V_75 ) ) ;
return 0 ;
V_262:
F_158 ( V_75 ) ;
V_256:
F_171 ( V_253 ) ;
return V_14 ;
}
static int F_172 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_48 =
F_173 ( & V_46 -> V_249 , V_263 , V_263 ) ;
if ( ! V_46 -> V_48 )
return - V_264 ;
V_23 -> V_63 . V_250 = V_46 -> V_48 -> V_254 ;
memset ( V_23 -> V_63 . V_250 , 0 , V_263 ) ;
return 0 ;
}
int F_174 ( struct V_6 * V_7 )
{
unsigned int V_30 = V_259 | V_265 | 4096 ;
enum V_266 V_267 ;
struct V_251 * V_75 = V_7 -> V_75 ;
void * V_47 ;
int V_14 ;
F_175 ( V_7 -> V_254 ) ;
V_267 = F_168 ( V_7 -> V_23 -> V_20 ) ? V_261 : V_268 ;
if ( V_75 -> V_253 -> V_269 )
V_30 |= V_260 ;
if ( ! ( V_75 -> V_30 & V_270 ) ) {
if ( V_30 & V_260 || V_267 == V_268 )
V_14 = F_176 ( V_75 -> V_253 , true ) ;
else
V_14 = F_177 ( V_75 -> V_253 , true ) ;
if ( F_178 ( V_14 ) )
return V_14 ;
}
V_14 = F_169 ( V_75 , 0 , V_263 , V_30 ) ;
if ( F_178 ( V_14 ) )
return V_14 ;
if ( F_179 ( V_75 ) )
V_47 = ( void V_271 * ) F_180 ( V_75 ) ;
else
V_47 = F_170 ( V_75 -> V_253 , V_267 ) ;
if ( F_164 ( V_47 ) )
goto V_256;
V_7 -> V_254 = V_47 ;
return 0 ;
V_256:
F_158 ( V_75 ) ;
return F_165 ( V_47 ) ;
}
void F_181 ( struct V_6 * V_7 )
{
F_175 ( ! V_7 -> V_75 ) ;
F_175 ( ! V_7 -> V_254 ) ;
if ( F_179 ( V_7 -> V_75 ) )
F_182 ( V_7 -> V_75 ) ;
else
F_160 ( V_7 -> V_75 -> V_253 ) ;
V_7 -> V_254 = NULL ;
F_158 ( V_7 -> V_75 ) ;
}
static struct V_251 *
F_183 ( struct V_45 * V_46 , int V_3 )
{
struct V_252 * V_253 ;
struct V_251 * V_75 ;
V_253 = F_184 ( & V_46 -> V_249 , V_3 ) ;
if ( ! V_253 )
V_253 = F_185 ( & V_46 -> V_249 , V_3 ) ;
if ( F_164 ( V_253 ) )
return F_186 ( V_253 ) ;
V_253 -> V_272 = 1 ;
V_75 = F_167 ( V_253 , & V_46 -> V_257 . V_258 , NULL ) ;
if ( F_164 ( V_75 ) )
goto V_256;
return V_75 ;
V_256:
F_171 ( V_253 ) ;
return V_75 ;
}
struct V_6 *
F_187 ( struct V_44 * V_23 , int V_3 )
{
struct V_6 * V_7 ;
struct V_251 * V_75 ;
F_175 ( ! F_82 ( V_3 ) ) ;
F_175 ( F_52 ( V_3 ) & ~ V_273 ) ;
V_7 = F_188 ( sizeof( * V_7 ) , V_274 ) ;
if ( ! V_7 )
return F_189 ( - V_264 ) ;
V_7 -> V_23 = V_23 ;
F_190 ( & V_7 -> V_275 ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_276 = V_3 ;
if ( F_191 ( V_23 -> V_20 ) || F_192 ( V_23 -> V_20 ) )
V_7 -> V_276 -= 2 * V_25 ;
V_7 -> V_8 = - 1 ;
F_2 ( V_7 ) ;
V_75 = F_183 ( V_23 -> V_20 , V_3 ) ;
if ( F_164 ( V_75 ) ) {
F_193 ( V_7 ) ;
return F_186 ( V_75 ) ;
}
V_7 -> V_75 = V_75 ;
return V_7 ;
}
void
F_194 ( struct V_6 * V_7 )
{
struct V_252 * V_253 = V_7 -> V_75 -> V_253 ;
F_159 ( V_7 -> V_75 ) ;
F_161 ( V_253 ) ;
F_193 ( V_7 ) ;
}
static int F_195 ( struct V_277 * V_218 ,
struct V_44 * V_23 )
{
struct V_278 * V_279 = & V_218 -> V_23 [ V_23 -> V_52 ] ;
int V_14 ;
F_196 ( & V_218 -> V_20 -> V_249 . V_280 ) ;
if ( V_279 -> V_281 ++ )
return 0 ;
if ( V_279 -> V_282 ) {
struct V_251 * V_75 ;
V_75 = F_197 ( V_218 , V_283 ) ;
if ( F_164 ( V_75 ) ) {
V_14 = F_165 ( V_75 ) ;
goto error;
}
}
if ( V_218 == V_218 -> V_20 -> V_284 )
V_279 -> V_285 = true ;
F_198 ( V_218 ) ;
return 0 ;
error:
V_279 -> V_281 = 0 ;
return V_14 ;
}
static void F_199 ( struct V_277 * V_218 ,
struct V_44 * V_23 )
{
struct V_278 * V_279 = & V_218 -> V_23 [ V_23 -> V_52 ] ;
F_196 ( & V_218 -> V_20 -> V_249 . V_280 ) ;
if ( -- V_279 -> V_281 )
return;
if ( V_279 -> V_282 )
F_158 ( V_279 -> V_282 ) ;
F_200 ( V_218 ) ;
}
static int F_201 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_6 * V_7 ;
int V_14 ;
F_29 ( V_23 -> V_71 ) ;
F_202 ( V_23 ) ;
V_14 = F_203 ( V_23 ) ;
if ( V_14 )
goto error;
V_14 = F_195 ( V_46 -> V_284 , V_23 ) ;
if ( V_14 )
goto error;
V_7 = F_187 ( V_23 , 32 * V_263 ) ;
if ( F_164 ( V_7 ) ) {
V_14 = F_165 ( V_7 ) ;
goto error;
}
if ( F_48 ( V_46 ) ) {
F_29 ( V_23 -> V_52 != V_53 ) ;
V_14 = F_172 ( V_23 ) ;
if ( V_14 )
goto error;
} else {
V_14 = F_162 ( V_23 ) ;
if ( V_14 )
goto error;
}
V_14 = F_174 ( V_7 ) ;
if ( V_14 ) {
F_194 ( V_7 ) ;
goto error;
}
V_23 -> V_71 = V_7 ;
return 0 ;
error:
F_204 ( V_23 ) ;
return V_14 ;
}
void F_204 ( struct V_44 * V_23 )
{
struct V_45 * V_46 ;
V_46 = V_23 -> V_20 ;
if ( V_23 -> V_71 ) {
F_29 ( F_19 ( V_46 ) > 2 &&
( F_30 ( V_23 ) & V_66 ) == 0 ) ;
F_181 ( V_23 -> V_71 ) ;
F_194 ( V_23 -> V_71 ) ;
V_23 -> V_71 = NULL ;
}
if ( V_23 -> V_286 )
V_23 -> V_286 ( V_23 ) ;
if ( F_48 ( V_46 ) ) {
F_29 ( V_23 -> V_52 != V_53 ) ;
F_154 ( V_23 ) ;
} else {
F_156 ( V_23 ) ;
}
F_205 ( V_23 ) ;
F_199 ( V_46 -> V_284 , V_23 ) ;
V_23 -> V_20 = NULL ;
V_46 -> V_23 [ V_23 -> V_52 ] = NULL ;
F_193 ( V_23 ) ;
}
void F_206 ( struct V_45 * V_46 )
{
struct V_44 * V_23 ;
enum V_194 V_52 ;
F_104 (engine, dev_priv, id) {
V_23 -> V_71 -> V_1 = V_23 -> V_71 -> V_2 ;
V_23 -> V_71 -> V_8 = - 1 ;
}
}
int F_207 ( struct V_10 * V_77 )
{
int V_14 ;
V_77 -> V_287 += V_288 ;
V_77 -> V_7 = V_77 -> V_23 -> V_71 ;
V_14 = F_4 ( V_77 , 0 ) ;
if ( V_14 )
return V_14 ;
V_77 -> V_287 -= V_288 ;
return 0 ;
}
static int F_208 ( struct V_10 * V_11 , int V_289 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_10 * V_290 ;
long V_291 ;
F_196 ( & V_11 -> V_20 -> V_249 . V_280 ) ;
F_2 ( V_7 ) ;
if ( V_7 -> V_4 >= V_289 )
return 0 ;
F_175 ( ! V_11 -> V_287 ) ;
F_209 (target, &ring->request_list, ring_link) {
unsigned V_4 ;
V_4 = F_1 ( V_290 -> V_78 , V_7 -> V_2 ,
V_7 -> V_3 ) ;
if ( V_4 >= V_289 )
break;
}
if ( F_29 ( & V_290 -> V_292 == & V_7 -> V_275 ) )
return - V_91 ;
V_291 = F_210 ( V_290 ,
V_293 | V_294 ,
V_295 ) ;
if ( V_291 < 0 )
return V_291 ;
F_211 ( V_290 ) ;
F_2 ( V_7 ) ;
F_175 ( V_7 -> V_4 < V_289 ) ;
return 0 ;
}
int F_4 ( struct V_10 * V_11 , int V_296 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_297 = V_7 -> V_3 - V_7 -> V_2 ;
int V_298 = V_7 -> V_276 - V_7 -> V_2 ;
int V_289 = V_296 * sizeof( T_1 ) ;
int V_299 , V_300 ;
bool V_301 = false ;
V_299 = V_289 + V_11 -> V_287 ;
if ( F_178 ( V_289 > V_298 ) ) {
V_300 = V_297 + V_299 ;
V_301 = true ;
} else if ( F_178 ( V_299 > V_298 ) ) {
V_300 = V_297 + V_11 -> V_287 ;
} else {
V_300 = V_299 ;
}
if ( V_300 > V_7 -> V_4 ) {
int V_14 = F_208 ( V_11 , V_300 ) ;
if ( F_178 ( V_14 ) )
return V_14 ;
}
if ( F_178 ( V_301 ) ) {
F_175 ( V_297 > V_7 -> V_4 ) ;
F_175 ( V_7 -> V_2 + V_297 > V_7 -> V_3 ) ;
memset ( V_7 -> V_254 + V_7 -> V_2 , 0 , V_297 ) ;
V_7 -> V_2 = 0 ;
V_7 -> V_4 -= V_297 ;
}
V_7 -> V_4 -= V_289 ;
F_175 ( V_7 -> V_4 < 0 ) ;
return 0 ;
}
int F_212 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_296 =
( V_7 -> V_2 & ( V_25 - 1 ) ) / sizeof( T_3 ) ;
int V_14 ;
if ( V_296 == 0 )
return 0 ;
V_296 = V_25 / sizeof( T_3 ) - V_296 ;
V_14 = F_4 ( V_11 , V_296 ) ;
if ( V_14 )
return V_14 ;
while ( V_296 -- )
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void F_213 ( struct V_10 * V_77 )
{
struct V_45 * V_46 = V_77 -> V_20 ;
F_45 ( V_46 , V_72 ) ;
F_214 ( V_302 ,
F_31 ( V_303 ) ) ;
F_215 ( V_304 , 0x0 ) ;
if ( F_53 ( V_46 ,
V_302 ,
V_305 ,
0 ,
50 ) )
F_33 ( L_12 ) ;
F_112 ( V_77 ) ;
F_214 ( V_302 ,
F_43 ( V_303 ) ) ;
F_56 ( V_46 , V_72 ) ;
}
static int F_216 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_3 V_13 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
V_13 = V_201 ;
if ( F_19 ( V_11 -> V_20 ) >= 8 )
V_13 += 1 ;
V_13 |= V_306 | V_202 ;
if ( V_12 & V_16 )
V_13 |= V_307 | V_308 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 , V_309 | V_203 ) ;
if ( F_19 ( V_11 -> V_20 ) >= 8 ) {
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , 0 ) ;
} else {
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_18 ) ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_217 ( struct V_10 * V_11 ,
T_5 V_212 , T_1 V_237 ,
unsigned int V_232 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
bool V_214 = F_218 ( V_11 -> V_20 ) &&
! ( V_232 & V_235 ) ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_310 | ( V_214 << 8 ) |
( V_232 & V_311 ?
V_312 : 0 ) ) ;
F_5 ( V_7 , F_105 ( V_212 ) ) ;
F_5 ( V_7 , F_106 ( V_212 ) ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_219 ( struct V_10 * V_11 ,
T_5 V_212 , T_1 V_237 ,
unsigned int V_232 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_233 |
( V_232 & V_235 ?
0 : V_313 | V_314 ) |
( V_232 & V_311 ?
V_312 : 0 ) ) ;
F_5 ( V_7 , V_212 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_220 ( struct V_10 * V_11 ,
T_5 V_212 , T_1 V_237 ,
unsigned int V_232 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_233 |
( V_232 & V_235 ?
0 : V_236 ) ) ;
F_5 ( V_7 , V_212 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_221 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_3 V_13 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
V_13 = V_201 ;
if ( F_19 ( V_11 -> V_20 ) >= 8 )
V_13 += 1 ;
V_13 |= V_306 | V_202 ;
if ( V_12 & V_16 )
V_13 |= V_307 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 ,
V_309 | V_203 ) ;
if ( F_19 ( V_11 -> V_20 ) >= 8 ) {
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , 0 ) ;
} else {
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_18 ) ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static void F_222 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
struct V_252 * V_253 ;
int V_14 , V_82 ;
if ( ! V_20 . V_315 )
return;
if ( F_19 ( V_46 ) >= 8 && ! V_46 -> V_192 ) {
struct V_251 * V_75 ;
V_253 = F_185 ( & V_46 -> V_249 , 4096 ) ;
if ( F_164 ( V_253 ) )
goto V_256;
V_75 = F_167 ( V_253 , & V_46 -> V_257 . V_258 , NULL ) ;
if ( F_164 ( V_75 ) )
goto V_316;
V_14 = F_176 ( V_253 , false ) ;
if ( V_14 )
goto V_316;
V_14 = F_169 ( V_75 , 0 , 0 , V_259 | V_283 ) ;
if ( V_14 )
goto V_316;
V_46 -> V_192 = V_75 ;
}
if ( F_19 ( V_46 ) >= 8 ) {
T_1 V_212 = F_11 ( V_46 -> V_192 ) ;
V_23 -> V_192 . V_317 = F_119 ;
V_23 -> V_192 . signal = F_108 ;
for ( V_82 = 0 ; V_82 < V_318 ; V_82 ++ ) {
T_1 V_319 ;
if ( V_82 != V_23 -> V_52 )
V_319 = V_212 + F_223 ( V_23 -> V_52 , V_82 ) ;
else
V_319 = V_197 ;
V_23 -> V_192 . V_196 [ V_82 ] = V_319 ;
}
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_192 . V_317 = F_122 ;
V_23 -> V_192 . signal = F_109 ;
for ( V_82 = 0 ; V_82 < V_320 ; V_82 ++ ) {
static const struct {
T_1 V_224 ;
T_2 V_205 ;
} V_321 [ V_320 ] [ V_320 ] = {
[ V_322 ] = {
[ V_323 ] = { . V_224 = V_324 , . V_205 = V_325 } ,
[ V_326 ] = { . V_224 = V_327 , . V_205 = V_328 } ,
[ V_329 ] = { . V_224 = V_330 , . V_205 = V_331 } ,
} ,
[ V_323 ] = {
[ V_322 ] = { . V_224 = V_332 , . V_205 = V_333 } ,
[ V_326 ] = { . V_224 = V_334 , . V_205 = V_335 } ,
[ V_329 ] = { . V_224 = V_336 , . V_205 = V_337 } ,
} ,
[ V_326 ] = {
[ V_322 ] = { . V_224 = V_338 , . V_205 = V_339 } ,
[ V_323 ] = { . V_224 = V_340 , . V_205 = V_341 } ,
[ V_329 ] = { . V_224 = V_342 , . V_205 = V_343 } ,
} ,
[ V_329 ] = {
[ V_322 ] = { . V_224 = V_344 , . V_205 = V_345 } ,
[ V_323 ] = { . V_224 = V_346 , . V_205 = V_347 } ,
[ V_326 ] = { . V_224 = V_348 , . V_205 = V_349 } ,
} ,
} ;
T_1 V_224 ;
T_2 V_205 ;
if ( V_82 == V_23 -> V_200 ) {
V_224 = V_197 ;
V_205 = V_350 ;
} else {
V_224 = V_321 [ V_23 -> V_200 ] [ V_82 ] . V_224 ;
V_205 = V_321 [ V_23 -> V_200 ] [ V_82 ] . V_205 ;
}
V_23 -> V_192 . V_207 . V_225 [ V_82 ] = V_224 ;
V_23 -> V_192 . V_207 . signal [ V_82 ] = V_205 ;
}
}
return;
V_316:
F_171 ( V_253 ) ;
V_256:
F_61 ( L_13 ) ;
V_20 . V_315 = 0 ;
}
static void F_224 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
V_23 -> V_228 = V_351 << V_23 -> V_352 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_353 = F_148 ;
V_23 -> V_354 = F_149 ;
V_23 -> V_355 = F_125 ;
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_353 = F_142 ;
V_23 -> V_354 = F_143 ;
V_23 -> V_355 = F_125 ;
} else if ( F_19 ( V_46 ) >= 5 ) {
V_23 -> V_353 = F_130 ;
V_23 -> V_354 = F_132 ;
V_23 -> V_355 = F_123 ;
} else if ( F_19 ( V_46 ) >= 3 ) {
V_23 -> V_353 = F_134 ;
V_23 -> V_354 = F_136 ;
} else {
V_23 -> V_353 = F_137 ;
V_23 -> V_354 = F_140 ;
}
}
static void F_225 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
F_224 ( V_46 , V_23 ) ;
F_222 ( V_46 , V_23 ) ;
V_23 -> V_356 = F_44 ;
V_23 -> V_357 = F_57 ;
V_23 -> V_358 = F_114 ;
V_23 -> V_359 = V_360 ;
if ( V_20 . V_315 ) {
int V_204 ;
V_23 -> V_358 = F_116 ;
V_204 = F_226 ( F_83 ( V_46 ) -> V_361 ) - 1 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_359 += V_204 * 6 ;
} else {
V_23 -> V_359 += V_204 * 3 ;
if ( V_204 & 1 )
V_23 -> V_359 ++ ;
}
}
V_23 -> V_362 = F_112 ;
if ( F_19 ( V_46 ) >= 8 )
V_23 -> V_363 = F_217 ;
else if ( F_19 ( V_46 ) >= 6 )
V_23 -> V_363 = F_220 ;
else if ( F_19 ( V_46 ) >= 4 )
V_23 -> V_363 = F_150 ;
else if ( F_191 ( V_46 ) || F_192 ( V_46 ) )
V_23 -> V_363 = F_151 ;
else
V_23 -> V_363 = F_153 ;
}
int F_227 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
F_225 ( V_46 , V_23 ) ;
if ( F_228 ( V_46 ) )
V_23 -> V_191 = V_364 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_365 = F_62 ;
V_23 -> V_358 = F_117 ;
V_23 -> V_359 = V_366 ;
V_23 -> V_84 = F_17 ;
if ( V_20 . V_315 ) {
int V_204 ;
V_23 -> V_192 . signal = F_103 ;
V_204 =
F_226 ( F_83 ( V_46 ) -> V_361 ) - 1 ;
V_23 -> V_359 += V_204 * 6 ;
}
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_365 = F_62 ;
V_23 -> V_84 = F_15 ;
if ( F_23 ( V_46 ) )
V_23 -> V_84 = F_13 ;
} else if ( F_9 ( V_46 ) ) {
V_23 -> V_84 = F_7 ;
} else {
if ( F_19 ( V_46 ) < 4 )
V_23 -> V_84 = F_3 ;
else
V_23 -> V_84 = F_7 ;
V_23 -> V_228 = V_367 ;
}
if ( F_229 ( V_46 ) )
V_23 -> V_363 = F_219 ;
V_23 -> V_356 = F_99 ;
V_23 -> V_286 = F_101 ;
V_14 = F_201 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_19 ( V_46 ) >= 6 ) {
V_14 = F_230 ( V_23 , 4096 ) ;
if ( V_14 )
return V_14 ;
} else if ( F_231 ( V_46 ) ) {
V_14 = F_230 ( V_23 , V_368 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
int F_232 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_225 ( V_46 , V_23 ) ;
if ( F_19 ( V_46 ) >= 6 ) {
if ( F_23 ( V_46 ) )
V_23 -> V_362 = F_213 ;
V_23 -> V_84 = F_216 ;
if ( F_19 ( V_46 ) < 8 )
V_23 -> V_228 = V_369 ;
} else {
V_23 -> V_62 = V_370 ;
V_23 -> V_84 = F_141 ;
if ( F_9 ( V_46 ) )
V_23 -> V_228 = V_371 ;
else
V_23 -> V_228 = V_372 ;
}
return F_201 ( V_23 ) ;
}
int F_233 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_225 ( V_46 , V_23 ) ;
V_23 -> V_84 = F_216 ;
return F_201 ( V_23 ) ;
}
int F_234 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_225 ( V_46 , V_23 ) ;
V_23 -> V_84 = F_221 ;
if ( F_19 ( V_46 ) < 8 )
V_23 -> V_228 = V_373 ;
return F_201 ( V_23 ) ;
}
int F_235 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_225 ( V_46 , V_23 ) ;
V_23 -> V_84 = F_221 ;
if ( F_19 ( V_46 ) < 8 ) {
V_23 -> V_228 = V_374 ;
V_23 -> V_353 = F_144 ;
V_23 -> V_354 = F_146 ;
}
return F_201 ( V_23 ) ;
}
