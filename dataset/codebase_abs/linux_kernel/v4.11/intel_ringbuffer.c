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
if ( V_77 ) {
struct V_45 * V_46 = V_77 -> V_20 ;
struct V_78 * V_79 = & V_77 -> V_80 -> V_23 [ V_23 -> V_52 ] ;
struct V_81 * V_82 ;
if ( V_79 -> V_83 ) {
F_20 ( V_84 ,
F_11 ( V_79 -> V_83 ) |
F_58 ( 8 ) |
V_85 |
V_86 |
V_87 ) ;
}
V_82 = V_77 -> V_80 -> V_82 ? : V_23 -> V_20 -> V_88 . V_89 ;
if ( V_82 ) {
T_1 V_90 = V_82 -> V_91 . V_92 . V_64 << 10 ;
F_20 ( F_59 ( V_23 ) , V_93 ) ;
F_20 ( F_60 ( V_23 ) , V_90 ) ;
if ( F_32 ( V_46 ,
F_60 ( V_23 ) ,
F_58 ( 0 ) , 0 ,
10 ) )
F_33 ( L_9 ) ;
V_82 -> V_94 &= ~ F_61 ( V_23 ) ;
}
if ( V_77 -> V_95 . error == - V_73 ) {
struct V_6 * V_7 = V_77 -> V_7 ;
V_7 -> V_1 = V_77 -> V_96 ;
V_7 -> V_8 = - 1 ;
}
} else {
V_23 -> V_97 = NULL ;
}
}
static int F_62 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_98 * V_99 = & V_11 -> V_20 -> V_100 ;
int V_14 , V_101 ;
if ( V_99 -> V_102 == 0 )
return 0 ;
V_14 = V_11 -> V_23 -> V_103 ( V_11 , V_104 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_11 , ( V_99 -> V_102 * 2 + 2 ) ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_63 ( V_99 -> V_102 ) ) ;
for ( V_101 = 0 ; V_101 < V_99 -> V_102 ; V_101 ++ ) {
F_64 ( V_7 , V_99 -> V_65 [ V_101 ] . V_47 ) ;
F_5 ( V_7 , V_99 -> V_65 [ V_101 ] . V_105 ) ;
}
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_14 = V_11 -> V_23 -> V_103 ( V_11 , V_104 ) ;
if ( V_14 )
return V_14 ;
F_65 ( L_10 , V_99 -> V_102 ) ;
return 0 ;
}
static int F_66 ( struct V_10 * V_11 )
{
int V_14 ;
V_14 = F_62 ( V_11 ) ;
if ( V_14 != 0 )
return V_14 ;
V_14 = F_67 ( V_11 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_68 ( struct V_45 * V_46 ,
T_2 V_47 ,
const T_1 V_106 , const T_1 V_107 )
{
const T_1 V_108 = V_46 -> V_100 . V_102 ;
if ( F_29 ( V_108 >= V_109 ) )
return - V_110 ;
V_46 -> V_100 . V_65 [ V_108 ] . V_47 = V_47 ;
V_46 -> V_100 . V_65 [ V_108 ] . V_105 = V_107 ;
V_46 -> V_100 . V_65 [ V_108 ] . V_106 = V_106 ;
V_46 -> V_100 . V_102 ++ ;
return 0 ;
}
static int F_69 ( struct V_44 * V_23 ,
T_2 V_65 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_98 * V_111 = & V_46 -> V_100 ;
const T_3 V_112 = V_111 -> V_113 [ V_23 -> V_52 ] ;
if ( F_29 ( V_112 >= V_114 ) )
return - V_115 ;
F_70 ( F_71 ( V_23 -> V_62 , V_112 ) ,
F_72 ( V_65 ) ) ;
V_111 -> V_113 [ V_23 -> V_52 ] ++ ;
return 0 ;
}
static int F_73 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_74 ( V_116 , V_117 ) ;
F_74 ( V_118 , V_119 ) ;
F_74 ( V_120 ,
V_121 ) ;
F_74 ( V_122 ,
V_123 |
V_124 ) ;
F_75 ( V_125 , V_126 ) ;
F_74 ( V_127 , V_128 ) ;
F_76 ( V_129 ,
V_130 ,
V_131 ) ;
return 0 ;
}
static int F_77 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_73 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_74 ( V_120 , V_132 ) ;
F_74 ( V_133 ,
V_134 ) ;
F_74 ( V_135 ,
V_136 ) ;
F_74 ( V_122 ,
V_137 |
( F_78 ( V_46 ) ? V_138 : 0 ) ) ;
return 0 ;
}
static int F_79 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_73 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_74 ( V_120 , V_132 ) ;
F_74 ( V_139 , V_140 ) ;
return 0 ;
}
static int F_80 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
F_20 ( V_141 , F_31 ( V_142 ) ) ;
F_20 ( V_143 , F_81 ( V_143 ) |
V_144 ) ;
F_20 ( V_145 , F_81 ( V_145 ) |
V_146 ) ;
F_74 ( V_120 ,
V_147 |
V_121 ) ;
F_74 ( V_135 ,
V_148 ) ;
if ( F_82 ( V_46 , 0 , V_149 ) )
F_75 ( V_150 ,
V_151 ) ;
if ( F_82 ( V_46 , 0 , V_149 ) ) {
F_74 ( V_152 ,
V_153 ) ;
}
F_74 ( V_154 ,
V_155 ) ;
F_74 ( V_127 , ( V_128 |
V_156 ) ) ;
F_75 ( V_150 ,
V_157 ) ;
if ( F_82 ( V_46 , 0 , V_149 ) )
F_74 ( V_158 ,
V_159 ) ;
F_74 ( V_122 ,
V_137 |
V_160 ) ;
F_74 ( V_122 ,
V_124 ) ;
F_20 ( V_145 , F_81 ( V_145 ) |
V_161 ) ;
if ( F_83 ( V_46 ) ||
F_84 ( V_46 ) ||
F_82 ( V_46 , 0 , V_162 ) )
F_74 ( V_135 ,
V_136 ) ;
F_74 ( V_163 , V_164 ) ;
F_20 ( V_165 , ( F_81 ( V_165 ) |
V_166 ) ) ;
V_14 = F_69 ( V_23 , V_167 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_23 , V_168 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_23 , V_169 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_85 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_4 V_170 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_101 ;
for ( V_101 = 0 ; V_101 < 3 ; V_101 ++ ) {
T_4 V_171 ;
if ( ! F_86 ( F_87 ( V_46 ) -> V_172 . V_173 [ V_101 ] ) )
continue;
V_171 = F_88 ( F_87 ( V_46 ) -> V_172 . V_173 [ V_101 ] ) - 1 ;
V_170 [ V_101 ] = 3 - V_171 ;
}
if ( V_170 [ 0 ] == 0 && V_170 [ 1 ] == 0 && V_170 [ 2 ] == 0 )
return 0 ;
F_76 ( V_129 ,
F_89 ( 2 ) |
F_89 ( 1 ) |
F_89 ( 0 ) ,
F_90 ( 2 , V_170 [ 2 ] ) |
F_90 ( 1 , V_170 [ 1 ] ) |
F_90 ( 0 , V_170 [ 0 ] ) ) ;
return 0 ;
}
static int F_91 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_80 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_20 ( V_174 ,
F_31 ( V_175 ) ) ;
F_20 ( V_176 , ( F_81 ( V_176 ) |
V_177 ) ) ;
F_92 ( V_178 , V_179 ) ;
if ( F_93 ( V_46 , V_180 , V_181 ) )
F_92 ( V_182 ,
V_183 ) ;
V_14 = F_69 ( V_23 , V_165 ) ;
if ( V_14 )
return V_14 ;
return F_85 ( V_23 ) ;
}
static int F_94 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_80 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_82 ( V_46 , 0 , V_149 ) )
F_20 ( V_184 , F_81 ( V_184 ) | V_185 ) ;
if ( F_82 ( V_46 , 0 , V_149 ) ) {
F_20 ( V_186 , ( F_81 ( V_186 ) &
~ V_187 ) ) ;
}
F_74 ( V_120 ,
V_132 ) ;
if ( F_82 ( V_46 , V_162 , V_181 ) ) {
F_74 ( V_188 ,
V_189 ) ;
}
if ( F_82 ( V_46 , 0 , V_162 ) ) {
F_74 (
V_190 ,
V_191 ) ;
}
if ( F_82 ( V_46 , 0 , V_149 ) ) {
V_14 = F_69 ( V_23 , V_192 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_23 , V_165 ) ;
if ( V_14 )
return V_14 ;
}
if ( F_82 ( V_46 , V_162 , V_181 ) )
F_20 ( V_193 , F_95 ( 62 ) |
F_96 ( 2 ) ) ;
if ( F_82 ( V_46 , V_194 , V_181 ) )
F_74 ( V_195 ,
V_196 ) ;
if ( F_82 ( V_46 , V_194 , V_181 ) )
F_92 ( V_182 ,
V_183 ) ;
return 0 ;
}
static int F_97 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_80 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_20 ( V_176 , ( F_81 ( V_176 ) |
V_177 ) ) ;
if ( F_98 ( V_46 , 0 , V_197 ) )
F_92 ( V_198 ,
V_199 ) ;
if ( F_98 ( V_46 , V_200 , V_200 ) )
F_74 ( V_122 ,
V_138 ) ;
if ( F_98 ( V_46 , V_201 , V_181 ) )
F_74 ( V_195 ,
V_196 ) ;
F_92 ( V_178 , V_179 ) ;
F_74 (
V_190 ,
V_191 ) ;
F_92 ( V_182 ,
V_183 ) ;
V_14 = F_69 ( V_23 , V_165 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
int F_99 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_29 ( V_23 -> V_52 != V_53 ) ;
V_46 -> V_100 . V_102 = 0 ;
V_46 -> V_100 . V_113 [ V_53 ] = 0 ;
if ( F_100 ( V_46 ) )
return F_77 ( V_23 ) ;
if ( F_101 ( V_46 ) )
return F_79 ( V_23 ) ;
if ( F_83 ( V_46 ) )
return F_91 ( V_23 ) ;
if ( F_102 ( V_46 ) )
return F_94 ( V_23 ) ;
if ( F_84 ( V_46 ) )
return F_97 ( V_23 ) ;
return 0 ;
}
static int F_103 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 = F_44 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_27 ( V_46 , 4 , 6 ) )
F_20 ( V_118 , F_31 ( V_202 ) ) ;
if ( F_27 ( V_46 , 6 , 7 ) )
F_20 ( V_118 , F_31 ( V_119 ) ) ;
if ( F_23 ( V_46 ) )
F_20 ( V_203 ,
F_31 ( V_204 ) ) ;
if ( F_22 ( V_46 ) )
F_20 ( V_205 ,
F_31 ( V_204 ) |
F_31 ( V_206 ) ) ;
if ( F_23 ( V_46 ) ) {
F_20 ( V_207 ,
F_43 ( V_208 ) ) ;
}
if ( F_27 ( V_46 , 6 , 7 ) )
F_20 ( V_116 , F_31 ( V_117 ) ) ;
if ( F_87 ( V_46 ) -> V_209 >= 6 )
F_104 ( V_23 , ~ V_23 -> V_210 ) ;
return F_99 ( V_23 ) ;
}
static void F_105 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_106 ( & V_46 -> V_211 ) ;
}
static T_1 * F_107 ( struct V_10 * V_11 , T_1 * V_74 )
{
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_212 ;
enum V_213 V_52 ;
F_108 (waiter, dev_priv, id) {
T_5 V_214 = V_11 -> V_23 -> V_211 . V_215 [ V_52 ] ;
if ( V_214 == V_216 )
continue;
* V_74 ++ = F_12 ( 6 ) ;
* V_74 ++ = ( V_43 |
V_29 |
V_26 ) ;
* V_74 ++ = F_109 ( V_214 ) ;
* V_74 ++ = F_110 ( V_214 ) ;
* V_74 ++ = V_11 -> V_217 ;
* V_74 ++ = 0 ;
* V_74 ++ = ( V_218 |
F_111 ( V_212 -> V_219 ) ) ;
* V_74 ++ = 0 ;
}
return V_74 ;
}
static T_1 * F_112 ( struct V_10 * V_11 , T_1 * V_74 )
{
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_212 ;
enum V_213 V_52 ;
F_108 (waiter, dev_priv, id) {
T_5 V_214 = V_11 -> V_23 -> V_211 . V_215 [ V_52 ] ;
if ( V_214 == V_216 )
continue;
* V_74 ++ = ( V_220 + 1 ) | V_221 ;
* V_74 ++ = F_109 ( V_214 ) | V_222 ;
* V_74 ++ = F_110 ( V_214 ) ;
* V_74 ++ = V_11 -> V_217 ;
* V_74 ++ = ( V_218 |
F_111 ( V_212 -> V_219 ) ) ;
* V_74 ++ = 0 ;
}
return V_74 ;
}
static T_1 * F_113 ( struct V_10 * V_11 , T_1 * V_74 )
{
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_23 ;
enum V_213 V_52 ;
int V_223 = 0 ;
F_108 (engine, dev_priv, id) {
T_2 V_224 ;
if ( ! ( F_58 ( V_23 -> V_219 ) & V_225 ) )
continue;
V_224 = V_11 -> V_23 -> V_211 . V_226 . signal [ V_23 -> V_219 ] ;
if ( F_114 ( V_224 ) ) {
* V_74 ++ = F_63 ( 1 ) ;
* V_74 ++ = F_72 ( V_224 ) ;
* V_74 ++ = V_11 -> V_217 ;
V_223 ++ ;
}
}
if ( V_223 & 1 )
* V_74 ++ = V_18 ;
return V_74 ;
}
static void F_115 ( struct V_10 * V_77 )
{
struct V_45 * V_46 = V_77 -> V_20 ;
F_116 ( V_77 ) ;
F_41 ( V_77 -> V_23 , V_77 -> V_2 ) ;
}
static void F_117 ( struct V_10 * V_11 ,
T_1 * V_74 )
{
* V_74 ++ = V_227 ;
* V_74 ++ = V_228 << V_229 ;
* V_74 ++ = V_11 -> V_217 ;
* V_74 ++ = V_230 ;
V_11 -> V_2 = F_118 ( V_11 -> V_7 , V_74 ) ;
}
static void F_119 ( struct V_10 * V_11 ,
T_1 * V_74 )
{
return F_117 ( V_11 ,
V_11 -> V_23 -> V_211 . signal ( V_11 , V_74 ) ) ;
}
static void F_120 ( struct V_10 * V_11 ,
T_1 * V_74 )
{
struct V_44 * V_23 = V_11 -> V_23 ;
if ( V_23 -> V_211 . signal )
V_74 = V_23 -> V_211 . signal ( V_11 , V_74 ) ;
* V_74 ++ = F_12 ( 6 ) ;
* V_74 ++ = ( V_43 |
V_26 |
V_29 ) ;
* V_74 ++ = F_121 ( V_23 ) ;
* V_74 ++ = 0 ;
* V_74 ++ = V_11 -> V_217 ;
* V_74 ++ = 0 ;
* V_74 ++ = V_230 ;
* V_74 ++ = V_18 ;
V_11 -> V_2 = F_118 ( V_11 -> V_7 , V_74 ) ;
}
static int
F_122 ( struct V_10 * V_11 ,
struct V_10 * signal )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_45 * V_46 = V_11 -> V_20 ;
T_5 V_231 = F_123 ( V_11 -> V_23 , signal -> V_23 -> V_52 ) ;
struct V_81 * V_82 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_232 |
V_233 |
V_234 ) ;
F_5 ( V_7 , signal -> V_217 ) ;
F_5 ( V_7 , F_109 ( V_231 ) ) ;
F_5 ( V_7 , F_110 ( V_231 ) ) ;
F_6 ( V_7 ) ;
V_82 = V_11 -> V_80 -> V_82 ;
if ( V_82 && V_11 -> V_23 -> V_52 != V_53 )
V_82 -> V_94 |= F_61 ( V_11 -> V_23 ) ;
return 0 ;
}
static int
F_124 ( struct V_10 * V_11 ,
struct V_10 * signal )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_235 = V_236 |
V_237 |
V_238 ;
T_1 V_239 = signal -> V_23 -> V_211 . V_226 . V_240 [ V_11 -> V_23 -> V_219 ] ;
int V_14 ;
F_29 ( V_239 == V_216 ) ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_235 | V_239 ) ;
F_5 ( V_7 , signal -> V_217 - 1 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void
F_125 ( struct V_44 * V_23 )
{
F_126 ( 125 , 250 ) ;
}
static void
F_127 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_128 ( & V_46 -> V_241 . V_242 ) ;
F_129 ( F_130 ( V_23 -> V_62 ) ) ;
F_131 ( & V_46 -> V_241 . V_242 ) ;
}
static void
F_132 ( struct V_44 * V_23 )
{
F_133 ( V_23 -> V_20 , V_23 -> V_243 ) ;
}
static void
F_134 ( struct V_44 * V_23 )
{
F_135 ( V_23 -> V_20 , V_23 -> V_243 ) ;
}
static void
F_136 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_244 &= ~ V_23 -> V_243 ;
F_20 ( V_245 , V_46 -> V_244 ) ;
F_129 ( F_137 ( V_23 -> V_62 ) ) ;
}
static void
F_138 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_244 |= V_23 -> V_243 ;
F_20 ( V_245 , V_46 -> V_244 ) ;
}
static void
F_139 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_244 &= ~ V_23 -> V_243 ;
F_140 ( V_245 , V_46 -> V_244 ) ;
F_141 ( F_137 ( V_23 -> V_62 ) ) ;
}
static void
F_142 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_244 |= V_23 -> V_243 ;
F_140 ( V_245 , V_46 -> V_244 ) ;
}
static int
F_143 ( struct V_10 * V_11 , T_1 V_12 )
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
F_144 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_104 ( V_23 ,
~ ( V_23 -> V_243 |
V_23 -> V_210 ) ) ;
F_133 ( V_46 , V_23 -> V_243 ) ;
}
static void
F_145 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_104 ( V_23 , ~ V_23 -> V_210 ) ;
F_135 ( V_46 , V_23 -> V_243 ) ;
}
static void
F_146 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_104 ( V_23 , ~ V_23 -> V_243 ) ;
F_147 ( V_46 , V_23 -> V_243 ) ;
}
static void
F_148 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_104 ( V_23 , ~ 0 ) ;
F_149 ( V_46 , V_23 -> V_243 ) ;
}
static void
F_150 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_104 ( V_23 ,
~ ( V_23 -> V_243 |
V_23 -> V_210 ) ) ;
F_129 ( F_137 ( V_23 -> V_62 ) ) ;
}
static void
F_151 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_104 ( V_23 , ~ V_23 -> V_210 ) ;
}
static int
F_152 ( struct V_10 * V_11 ,
T_5 V_231 , T_1 V_246 ,
unsigned int V_247 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_248 |
V_249 |
( V_247 & V_250 ?
0 : V_251 ) ) ;
F_5 ( V_7 , V_231 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_153 ( struct V_10 * V_11 ,
T_5 V_231 , T_1 V_252 ,
unsigned int V_247 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_253 = F_11 ( V_11 -> V_23 -> V_24 ) ;
int V_14 ;
V_14 = F_4 ( V_11 , 6 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_254 | V_255 ) ;
F_5 ( V_7 , V_256 | V_257 | 4096 ) ;
F_5 ( V_7 , V_258 << 16 | 4 ) ;
F_5 ( V_7 , V_253 ) ;
F_5 ( V_7 , 0xdeadbeef ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
if ( ( V_247 & V_259 ) == 0 ) {
if ( V_252 > V_260 )
return - V_110 ;
V_14 = F_4 ( V_11 , 6 + 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_261 | V_255 ) ;
F_5 ( V_7 ,
V_256 | V_262 | 4096 ) ;
F_5 ( V_7 , F_154 ( V_252 , 4096 ) << 16 | 4096 ) ;
F_5 ( V_7 , V_253 ) ;
F_5 ( V_7 , 4096 ) ;
F_5 ( V_7 , V_231 ) ;
F_5 ( V_7 , V_15 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_231 = V_253 ;
}
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_248 | V_249 ) ;
F_5 ( V_7 , V_231 | ( V_247 & V_250 ?
0 : V_263 ) ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_155 ( struct V_10 * V_11 ,
T_5 V_231 , T_1 V_252 ,
unsigned int V_247 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_248 | V_249 ) ;
F_5 ( V_7 , V_231 | ( V_247 & V_250 ?
0 : V_263 ) ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void F_156 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
if ( ! V_46 -> V_48 )
return;
F_157 ( & V_46 -> V_264 , V_46 -> V_48 ) ;
V_23 -> V_63 . V_265 = NULL ;
}
static void F_158 ( struct V_44 * V_23 )
{
struct V_266 * V_75 ;
struct V_267 * V_268 ;
V_75 = F_159 ( & V_23 -> V_63 . V_75 ) ;
if ( ! V_75 )
return;
V_268 = V_75 -> V_268 ;
F_160 ( V_75 ) ;
F_161 ( V_75 ) ;
F_162 ( V_268 ) ;
F_163 ( V_268 ) ;
}
static int F_164 ( struct V_44 * V_23 )
{
struct V_267 * V_268 ;
struct V_266 * V_75 ;
unsigned int V_30 ;
void * V_269 ;
int V_14 ;
V_268 = F_165 ( V_23 -> V_20 , V_270 ) ;
if ( F_166 ( V_268 ) ) {
F_33 ( L_11 ) ;
return F_167 ( V_268 ) ;
}
V_14 = F_168 ( V_268 , V_271 ) ;
if ( V_14 )
goto V_272;
V_75 = F_169 ( V_268 , & V_23 -> V_20 -> V_273 . V_92 , NULL ) ;
if ( F_166 ( V_75 ) ) {
V_14 = F_167 ( V_75 ) ;
goto V_272;
}
V_30 = V_274 ;
if ( ! F_170 ( V_23 -> V_20 ) )
V_30 |= V_275 ;
V_14 = F_171 ( V_75 , 0 , 4096 , V_30 ) ;
if ( V_14 )
goto V_272;
V_269 = F_172 ( V_268 , V_276 ) ;
if ( F_166 ( V_269 ) ) {
V_14 = F_167 ( V_269 ) ;
goto V_277;
}
V_23 -> V_63 . V_75 = V_75 ;
V_23 -> V_63 . V_64 = F_11 ( V_75 ) ;
V_23 -> V_63 . V_265 = memset ( V_269 , 0 , V_270 ) ;
F_65 ( L_12 ,
V_23 -> V_69 , F_11 ( V_75 ) ) ;
return 0 ;
V_277:
F_160 ( V_75 ) ;
V_272:
F_173 ( V_268 ) ;
return V_14 ;
}
static int F_174 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_48 =
F_175 ( & V_46 -> V_264 , V_270 , V_270 ) ;
if ( ! V_46 -> V_48 )
return - V_278 ;
V_23 -> V_63 . V_265 = V_46 -> V_48 -> V_269 ;
memset ( V_23 -> V_63 . V_265 , 0 , V_270 ) ;
return 0 ;
}
int F_176 ( struct V_6 * V_7 , unsigned int V_279 )
{
unsigned int V_30 ;
enum V_280 V_281 ;
struct V_266 * V_75 = V_7 -> V_75 ;
void * V_47 ;
int V_14 ;
F_177 ( V_7 -> V_269 ) ;
V_281 = F_170 ( V_7 -> V_23 -> V_20 ) ? V_276 : V_282 ;
V_30 = V_274 ;
if ( V_279 )
V_30 |= V_283 | V_279 ;
if ( V_75 -> V_268 -> V_284 )
V_30 |= V_275 ;
if ( ! ( V_75 -> V_30 & V_285 ) ) {
if ( V_30 & V_275 || V_281 == V_282 )
V_14 = F_178 ( V_75 -> V_268 , true ) ;
else
V_14 = F_179 ( V_75 -> V_268 , true ) ;
if ( F_180 ( V_14 ) )
return V_14 ;
}
V_14 = F_171 ( V_75 , 0 , V_270 , V_30 ) ;
if ( F_180 ( V_14 ) )
return V_14 ;
if ( F_181 ( V_75 ) )
V_47 = ( void V_286 * ) F_182 ( V_75 ) ;
else
V_47 = F_172 ( V_75 -> V_268 , V_281 ) ;
if ( F_166 ( V_47 ) )
goto V_272;
V_7 -> V_269 = V_47 ;
return 0 ;
V_272:
F_160 ( V_75 ) ;
return F_167 ( V_47 ) ;
}
void F_183 ( struct V_6 * V_7 )
{
F_177 ( ! V_7 -> V_75 ) ;
F_177 ( ! V_7 -> V_269 ) ;
if ( F_181 ( V_7 -> V_75 ) )
F_184 ( V_7 -> V_75 ) ;
else
F_162 ( V_7 -> V_75 -> V_268 ) ;
V_7 -> V_269 = NULL ;
F_160 ( V_7 -> V_75 ) ;
}
static struct V_266 *
F_185 ( struct V_45 * V_46 , int V_3 )
{
struct V_267 * V_268 ;
struct V_266 * V_75 ;
V_268 = F_186 ( V_46 , V_3 ) ;
if ( ! V_268 )
V_268 = F_187 ( V_46 , V_3 ) ;
if ( F_166 ( V_268 ) )
return F_188 ( V_268 ) ;
V_268 -> V_287 = 1 ;
V_75 = F_169 ( V_268 , & V_46 -> V_273 . V_92 , NULL ) ;
if ( F_166 ( V_75 ) )
goto V_272;
return V_75 ;
V_272:
F_173 ( V_268 ) ;
return V_75 ;
}
struct V_6 *
F_189 ( struct V_44 * V_23 , int V_3 )
{
struct V_6 * V_7 ;
struct V_266 * V_75 ;
F_177 ( ! F_86 ( V_3 ) ) ;
F_177 ( F_52 ( V_3 ) & ~ V_288 ) ;
V_7 = F_190 ( sizeof( * V_7 ) , V_289 ) ;
if ( ! V_7 )
return F_191 ( - V_278 ) ;
V_7 -> V_23 = V_23 ;
F_192 ( & V_7 -> V_290 ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_291 = V_3 ;
if ( F_193 ( V_23 -> V_20 ) || F_194 ( V_23 -> V_20 ) )
V_7 -> V_291 -= 2 * V_25 ;
V_7 -> V_8 = - 1 ;
F_2 ( V_7 ) ;
V_75 = F_185 ( V_23 -> V_20 , V_3 ) ;
if ( F_166 ( V_75 ) ) {
F_195 ( V_7 ) ;
return F_188 ( V_75 ) ;
}
V_7 -> V_75 = V_75 ;
return V_7 ;
}
void
F_196 ( struct V_6 * V_7 )
{
struct V_267 * V_268 = V_7 -> V_75 -> V_268 ;
F_161 ( V_7 -> V_75 ) ;
F_163 ( V_268 ) ;
F_195 ( V_7 ) ;
}
static int F_197 ( struct V_292 * V_80 , unsigned int V_30 )
{
struct V_266 * V_75 = V_80 -> V_23 [ V_53 ] . V_83 ;
int V_14 ;
if ( ! ( V_75 -> V_30 & V_285 ) ) {
V_14 = F_178 ( V_75 -> V_268 , false ) ;
if ( V_14 )
return V_14 ;
}
return F_171 ( V_75 , 0 , V_80 -> V_293 , V_274 | V_30 ) ;
}
static int F_198 ( struct V_44 * V_23 ,
struct V_292 * V_80 )
{
struct V_78 * V_79 = & V_80 -> V_23 [ V_23 -> V_52 ] ;
int V_14 ;
F_199 ( & V_80 -> V_20 -> V_264 . V_294 ) ;
if ( V_79 -> V_295 ++ )
return 0 ;
if ( V_79 -> V_83 ) {
unsigned int V_30 ;
V_30 = 0 ;
if ( F_200 ( V_80 ) )
V_30 = V_296 ;
V_14 = F_197 ( V_80 , V_30 ) ;
if ( V_14 )
goto error;
V_79 -> V_83 -> V_268 -> V_88 . V_297 = true ;
}
if ( F_200 ( V_80 ) )
V_79 -> V_298 = true ;
F_201 ( V_80 ) ;
return 0 ;
error:
V_79 -> V_295 = 0 ;
return V_14 ;
}
static void F_202 ( struct V_44 * V_23 ,
struct V_292 * V_80 )
{
struct V_78 * V_79 = & V_80 -> V_23 [ V_23 -> V_52 ] ;
F_199 ( & V_80 -> V_20 -> V_264 . V_294 ) ;
F_177 ( V_79 -> V_295 == 0 ) ;
if ( -- V_79 -> V_295 )
return;
if ( V_79 -> V_83 )
F_160 ( V_79 -> V_83 ) ;
F_203 ( V_80 ) ;
}
static int F_204 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_6 * V_7 ;
int V_14 ;
F_29 ( V_23 -> V_71 ) ;
F_205 ( V_23 ) ;
V_14 = F_206 ( V_23 ) ;
if ( V_14 )
goto error;
V_7 = F_189 ( V_23 , 32 * V_270 ) ;
if ( F_166 ( V_7 ) ) {
V_14 = F_167 ( V_7 ) ;
goto error;
}
if ( F_48 ( V_46 ) ) {
F_29 ( V_23 -> V_52 != V_53 ) ;
V_14 = F_174 ( V_23 ) ;
if ( V_14 )
goto error;
} else {
V_14 = F_164 ( V_23 ) ;
if ( V_14 )
goto error;
}
V_14 = F_176 ( V_7 , V_299 ) ;
if ( V_14 ) {
F_196 ( V_7 ) ;
goto error;
}
V_23 -> V_71 = V_7 ;
return 0 ;
error:
F_207 ( V_23 ) ;
return V_14 ;
}
void F_207 ( struct V_44 * V_23 )
{
struct V_45 * V_46 ;
V_46 = V_23 -> V_20 ;
if ( V_23 -> V_71 ) {
F_29 ( F_19 ( V_46 ) > 2 &&
( F_30 ( V_23 ) & V_66 ) == 0 ) ;
F_183 ( V_23 -> V_71 ) ;
F_196 ( V_23 -> V_71 ) ;
V_23 -> V_71 = NULL ;
}
if ( V_23 -> V_300 )
V_23 -> V_300 ( V_23 ) ;
if ( F_48 ( V_46 ) ) {
F_29 ( V_23 -> V_52 != V_53 ) ;
F_156 ( V_23 ) ;
} else {
F_158 ( V_23 ) ;
}
F_208 ( V_23 ) ;
V_23 -> V_20 = NULL ;
V_46 -> V_23 [ V_23 -> V_52 ] = NULL ;
F_195 ( V_23 ) ;
}
void F_209 ( struct V_45 * V_46 )
{
struct V_44 * V_23 ;
enum V_213 V_52 ;
F_108 (engine, dev_priv, id) {
V_23 -> V_71 -> V_1 = V_23 -> V_71 -> V_2 ;
V_23 -> V_71 -> V_8 = - 1 ;
}
}
static int F_210 ( struct V_10 * V_77 )
{
int V_14 ;
F_177 ( ! V_77 -> V_80 -> V_23 [ V_77 -> V_23 -> V_52 ] . V_295 ) ;
V_77 -> V_301 += V_302 ;
F_177 ( ! V_77 -> V_23 -> V_71 ) ;
V_77 -> V_7 = V_77 -> V_23 -> V_71 ;
V_14 = F_4 ( V_77 , 0 ) ;
if ( V_14 )
return V_14 ;
V_77 -> V_301 -= V_302 ;
return 0 ;
}
static int F_211 ( struct V_10 * V_11 , int V_303 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_10 * V_304 ;
long V_305 ;
F_199 ( & V_11 -> V_20 -> V_264 . V_294 ) ;
F_2 ( V_7 ) ;
if ( V_7 -> V_4 >= V_303 )
return 0 ;
F_177 ( ! V_11 -> V_301 ) ;
F_212 (target, &ring->request_list, ring_link) {
unsigned V_4 ;
V_4 = F_1 ( V_304 -> V_96 , V_7 -> V_2 ,
V_7 -> V_3 ) ;
if ( V_4 >= V_303 )
break;
}
if ( F_29 ( & V_304 -> V_306 == & V_7 -> V_290 ) )
return - V_110 ;
V_305 = F_213 ( V_304 ,
V_307 | V_308 ,
V_309 ) ;
if ( V_305 < 0 )
return V_305 ;
F_214 ( V_304 ) ;
F_2 ( V_7 ) ;
F_177 ( V_7 -> V_4 < V_303 ) ;
return 0 ;
}
int F_4 ( struct V_10 * V_11 , int V_310 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_311 = V_7 -> V_3 - V_7 -> V_2 ;
int V_312 = V_7 -> V_291 - V_7 -> V_2 ;
int V_303 = V_310 * sizeof( T_1 ) ;
int V_313 , V_314 ;
bool V_315 = false ;
V_313 = V_303 + V_11 -> V_301 ;
if ( F_180 ( V_303 > V_312 ) ) {
V_314 = V_311 + V_313 ;
V_315 = true ;
} else if ( F_180 ( V_313 > V_312 ) ) {
V_314 = V_311 + V_11 -> V_301 ;
} else {
V_314 = V_313 ;
}
if ( V_314 > V_7 -> V_4 ) {
int V_14 = F_211 ( V_11 , V_314 ) ;
if ( F_180 ( V_14 ) )
return V_14 ;
}
if ( F_180 ( V_315 ) ) {
F_177 ( V_311 > V_7 -> V_4 ) ;
F_177 ( V_7 -> V_2 + V_311 > V_7 -> V_3 ) ;
memset ( V_7 -> V_269 + V_7 -> V_2 , 0 , V_311 ) ;
V_7 -> V_2 = 0 ;
V_7 -> V_4 -= V_311 ;
}
V_7 -> V_4 -= V_303 ;
F_177 ( V_7 -> V_4 < 0 ) ;
return 0 ;
}
int F_215 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_310 =
( V_7 -> V_2 & ( V_25 - 1 ) ) / sizeof( T_3 ) ;
int V_14 ;
if ( V_310 == 0 )
return 0 ;
V_310 = V_25 / sizeof( T_3 ) - V_310 ;
V_14 = F_4 ( V_11 , V_310 ) ;
if ( V_14 )
return V_14 ;
while ( V_310 -- )
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void F_216 ( struct V_10 * V_77 )
{
struct V_45 * V_46 = V_77 -> V_20 ;
F_45 ( V_46 , V_72 ) ;
F_217 ( V_316 ,
F_31 ( V_317 ) ) ;
F_218 ( V_318 , 0x0 ) ;
if ( F_53 ( V_46 ,
V_316 ,
V_319 ,
0 ,
50 ) )
F_33 ( L_13 ) ;
F_115 ( V_77 ) ;
F_217 ( V_316 ,
F_43 ( V_317 ) ) ;
F_56 ( V_46 , V_72 ) ;
}
static int F_219 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_3 V_13 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
V_13 = V_220 ;
if ( F_19 ( V_11 -> V_20 ) >= 8 )
V_13 += 1 ;
V_13 |= V_320 | V_221 ;
if ( V_12 & V_16 )
V_13 |= V_321 | V_322 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 , V_323 | V_222 ) ;
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
F_220 ( struct V_10 * V_11 ,
T_5 V_231 , T_1 V_252 ,
unsigned int V_247 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
bool V_82 = F_221 ( V_11 -> V_20 ) &&
! ( V_247 & V_250 ) ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_324 | ( V_82 << 8 ) |
( V_247 & V_325 ?
V_326 : 0 ) ) ;
F_5 ( V_7 , F_109 ( V_231 ) ) ;
F_5 ( V_7 , F_110 ( V_231 ) ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_222 ( struct V_10 * V_11 ,
T_5 V_231 , T_1 V_252 ,
unsigned int V_247 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_248 |
( V_247 & V_250 ?
0 : V_327 | V_328 ) |
( V_247 & V_325 ?
V_326 : 0 ) ) ;
F_5 ( V_7 , V_231 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_223 ( struct V_10 * V_11 ,
T_5 V_231 , T_1 V_252 ,
unsigned int V_247 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_248 |
( V_247 & V_250 ?
0 : V_251 ) ) ;
F_5 ( V_7 , V_231 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_224 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_3 V_13 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
V_13 = V_220 ;
if ( F_19 ( V_11 -> V_20 ) >= 8 )
V_13 += 1 ;
V_13 |= V_320 | V_221 ;
if ( V_12 & V_16 )
V_13 |= V_321 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 ,
V_323 | V_222 ) ;
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
static void F_225 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
struct V_267 * V_268 ;
int V_14 , V_101 ;
if ( ! V_20 . V_329 )
return;
if ( F_19 ( V_46 ) >= 8 && ! V_46 -> V_211 ) {
struct V_266 * V_75 ;
V_268 = F_187 ( V_46 , V_270 ) ;
if ( F_166 ( V_268 ) )
goto V_272;
V_75 = F_169 ( V_268 , & V_46 -> V_273 . V_92 , NULL ) ;
if ( F_166 ( V_75 ) )
goto V_330;
V_14 = F_178 ( V_268 , false ) ;
if ( V_14 )
goto V_330;
V_14 = F_171 ( V_75 , 0 , 0 , V_274 | V_296 ) ;
if ( V_14 )
goto V_330;
V_46 -> V_211 = V_75 ;
}
if ( F_19 ( V_46 ) >= 8 ) {
T_1 V_231 = F_11 ( V_46 -> V_211 ) ;
V_23 -> V_211 . V_331 = F_122 ;
V_23 -> V_211 . signal = F_112 ;
for ( V_101 = 0 ; V_101 < V_332 ; V_101 ++ ) {
T_1 V_333 ;
if ( V_101 != V_23 -> V_52 )
V_333 = V_231 + F_226 ( V_23 -> V_52 , V_101 ) ;
else
V_333 = V_216 ;
V_23 -> V_211 . V_215 [ V_101 ] = V_333 ;
}
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_211 . V_331 = F_124 ;
V_23 -> V_211 . signal = F_113 ;
for ( V_101 = 0 ; V_101 < V_334 ; V_101 ++ ) {
static const struct {
T_1 V_239 ;
T_2 V_224 ;
} V_335 [ V_334 ] [ V_334 ] = {
[ V_336 ] = {
[ V_337 ] = { . V_239 = V_338 , . V_224 = V_339 } ,
[ V_340 ] = { . V_239 = V_341 , . V_224 = V_342 } ,
[ V_343 ] = { . V_239 = V_344 , . V_224 = V_345 } ,
} ,
[ V_337 ] = {
[ V_336 ] = { . V_239 = V_346 , . V_224 = V_347 } ,
[ V_340 ] = { . V_239 = V_348 , . V_224 = V_349 } ,
[ V_343 ] = { . V_239 = V_350 , . V_224 = V_351 } ,
} ,
[ V_340 ] = {
[ V_336 ] = { . V_239 = V_352 , . V_224 = V_353 } ,
[ V_337 ] = { . V_239 = V_354 , . V_224 = V_355 } ,
[ V_343 ] = { . V_239 = V_356 , . V_224 = V_357 } ,
} ,
[ V_343 ] = {
[ V_336 ] = { . V_239 = V_358 , . V_224 = V_359 } ,
[ V_337 ] = { . V_239 = V_360 , . V_224 = V_361 } ,
[ V_340 ] = { . V_239 = V_362 , . V_224 = V_363 } ,
} ,
} ;
T_1 V_239 ;
T_2 V_224 ;
if ( V_101 == V_23 -> V_219 ) {
V_239 = V_216 ;
V_224 = V_364 ;
} else {
V_239 = V_335 [ V_23 -> V_219 ] [ V_101 ] . V_239 ;
V_224 = V_335 [ V_23 -> V_219 ] [ V_101 ] . V_224 ;
}
V_23 -> V_211 . V_226 . V_240 [ V_101 ] = V_239 ;
V_23 -> V_211 . V_226 . signal [ V_101 ] = V_224 ;
}
}
return;
V_330:
F_173 ( V_268 ) ;
V_272:
F_65 ( L_14 ) ;
V_20 . V_329 = 0 ;
}
static void F_227 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
V_23 -> V_243 = V_365 << V_23 -> V_366 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_367 = F_150 ;
V_23 -> V_368 = F_151 ;
V_23 -> V_369 = F_127 ;
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_367 = F_144 ;
V_23 -> V_368 = F_145 ;
V_23 -> V_369 = F_127 ;
} else if ( F_19 ( V_46 ) >= 5 ) {
V_23 -> V_367 = F_132 ;
V_23 -> V_368 = F_134 ;
V_23 -> V_369 = F_125 ;
} else if ( F_19 ( V_46 ) >= 3 ) {
V_23 -> V_367 = F_136 ;
V_23 -> V_368 = F_138 ;
} else {
V_23 -> V_367 = F_139 ;
V_23 -> V_368 = F_142 ;
}
}
static void F_228 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
F_227 ( V_46 , V_23 ) ;
F_225 ( V_46 , V_23 ) ;
V_23 -> V_370 = F_44 ;
V_23 -> V_371 = F_57 ;
V_23 -> F_197 = F_198 ;
V_23 -> V_372 = F_202 ;
V_23 -> V_373 = F_210 ;
V_23 -> V_374 = F_117 ;
V_23 -> V_375 = V_376 ;
if ( V_20 . V_329 ) {
int V_223 ;
V_23 -> V_374 = F_119 ;
V_223 = F_229 ( F_87 ( V_46 ) -> V_377 ) - 1 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_375 += V_223 * 6 ;
} else {
V_23 -> V_375 += V_223 * 3 ;
if ( V_223 & 1 )
V_23 -> V_375 ++ ;
}
}
V_23 -> V_378 = F_115 ;
if ( F_19 ( V_46 ) >= 8 )
V_23 -> V_379 = F_220 ;
else if ( F_19 ( V_46 ) >= 6 )
V_23 -> V_379 = F_223 ;
else if ( F_19 ( V_46 ) >= 4 )
V_23 -> V_379 = F_152 ;
else if ( F_193 ( V_46 ) || F_194 ( V_46 ) )
V_23 -> V_379 = F_153 ;
else
V_23 -> V_379 = F_155 ;
}
int F_230 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
F_228 ( V_46 , V_23 ) ;
if ( F_231 ( V_46 ) )
V_23 -> V_210 = V_380 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_381 = F_66 ;
V_23 -> V_374 = F_120 ;
V_23 -> V_375 = V_382 ;
V_23 -> V_103 = F_17 ;
if ( V_20 . V_329 ) {
int V_223 ;
V_23 -> V_211 . signal = F_107 ;
V_223 =
F_229 ( F_87 ( V_46 ) -> V_377 ) - 1 ;
V_23 -> V_375 += V_223 * 6 ;
}
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_381 = F_66 ;
V_23 -> V_103 = F_15 ;
if ( F_23 ( V_46 ) )
V_23 -> V_103 = F_13 ;
} else if ( F_9 ( V_46 ) ) {
V_23 -> V_103 = F_7 ;
} else {
if ( F_19 ( V_46 ) < 4 )
V_23 -> V_103 = F_3 ;
else
V_23 -> V_103 = F_7 ;
V_23 -> V_243 = V_383 ;
}
if ( F_232 ( V_46 ) )
V_23 -> V_379 = F_222 ;
V_23 -> V_370 = F_103 ;
V_23 -> V_300 = F_105 ;
V_14 = F_204 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_19 ( V_46 ) >= 6 ) {
V_14 = F_233 ( V_23 , V_270 ) ;
if ( V_14 )
return V_14 ;
} else if ( F_234 ( V_46 ) ) {
V_14 = F_233 ( V_23 , V_384 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
int F_235 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_228 ( V_46 , V_23 ) ;
if ( F_19 ( V_46 ) >= 6 ) {
if ( F_23 ( V_46 ) )
V_23 -> V_378 = F_216 ;
V_23 -> V_103 = F_219 ;
if ( F_19 ( V_46 ) < 8 )
V_23 -> V_243 = V_385 ;
} else {
V_23 -> V_62 = V_386 ;
V_23 -> V_103 = F_143 ;
if ( F_9 ( V_46 ) )
V_23 -> V_243 = V_387 ;
else
V_23 -> V_243 = V_388 ;
}
return F_204 ( V_23 ) ;
}
int F_236 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_228 ( V_46 , V_23 ) ;
V_23 -> V_103 = F_219 ;
return F_204 ( V_23 ) ;
}
int F_237 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_228 ( V_46 , V_23 ) ;
V_23 -> V_103 = F_224 ;
if ( F_19 ( V_46 ) < 8 )
V_23 -> V_243 = V_389 ;
return F_204 ( V_23 ) ;
}
int F_238 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_228 ( V_46 , V_23 ) ;
V_23 -> V_103 = F_224 ;
if ( F_19 ( V_46 ) < 8 ) {
V_23 -> V_243 = V_390 ;
V_23 -> V_367 = F_146 ;
V_23 -> V_368 = F_148 ;
}
return F_204 ( V_23 ) ;
}
