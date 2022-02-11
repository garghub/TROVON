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
T_2 F_18 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_2 V_47 ;
if ( F_19 ( V_46 ) >= 8 )
V_47 = F_20 ( F_21 ( V_23 -> V_48 ) ,
F_22 ( V_23 -> V_48 ) ) ;
else if ( F_19 ( V_46 ) >= 4 )
V_47 = F_23 ( F_21 ( V_23 -> V_48 ) ) ;
else
V_47 = F_23 ( V_49 ) ;
return V_47 ;
}
static void F_24 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_1 V_50 ;
V_50 = V_46 -> V_51 -> V_52 ;
if ( F_19 ( V_46 ) >= 4 )
V_50 |= ( V_46 -> V_51 -> V_52 >> 28 ) & 0xf0 ;
F_25 ( V_53 , V_50 ) ;
}
static void F_26 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_3 V_54 ;
if ( F_27 ( V_46 ) ) {
switch ( V_23 -> V_55 ) {
case V_56 :
V_54 = V_57 ;
break;
case V_58 :
V_54 = V_59 ;
break;
case V_60 :
case V_61 :
V_54 = V_62 ;
break;
case V_63 :
V_54 = V_64 ;
break;
}
} else if ( F_28 ( V_46 ) ) {
V_54 = F_29 ( V_23 -> V_48 ) ;
} else {
V_54 = F_30 ( V_23 -> V_48 ) ;
}
F_25 ( V_54 , V_23 -> V_65 . V_66 ) ;
F_31 ( V_54 ) ;
if ( F_32 ( V_46 , 6 , 7 ) ) {
T_3 V_67 = F_33 ( V_23 -> V_48 ) ;
F_34 ( ( F_35 ( V_23 ) & V_68 ) == 0 ) ;
F_25 ( V_67 ,
F_36 ( V_69 |
V_70 ) ) ;
if ( F_37 ( V_46 ,
V_67 , V_70 , 0 ,
1000 ) )
F_38 ( L_1 ,
V_23 -> V_71 ) ;
}
}
static bool F_39 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
if ( F_19 ( V_46 ) > 2 ) {
F_40 ( V_23 , F_36 ( V_72 ) ) ;
if ( F_37 ( V_46 ,
F_41 ( V_23 -> V_48 ) ,
V_68 ,
V_68 ,
1000 ) ) {
F_38 ( L_2 ,
V_23 -> V_71 ) ;
if ( F_42 ( V_23 ) != F_43 ( V_23 ) )
return false ;
}
}
F_44 ( V_23 , 0 ) ;
F_45 ( V_23 , 0 ) ;
F_46 ( V_23 , 0 ) ;
if ( F_19 ( V_46 ) > 2 ) {
( void ) F_47 ( V_23 ) ;
F_40 ( V_23 , F_48 ( V_72 ) ) ;
}
return ( F_42 ( V_23 ) & V_9 ) == 0 ;
}
static int F_49 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_6 * V_7 = V_23 -> V_73 ;
int V_14 = 0 ;
F_50 ( V_46 , V_74 ) ;
if ( ! F_39 ( V_23 ) ) {
F_51 ( L_3
L_4 ,
V_23 -> V_71 ,
F_47 ( V_23 ) ,
F_42 ( V_23 ) ,
F_43 ( V_23 ) ,
F_52 ( V_23 ) ) ;
if ( ! F_39 ( V_23 ) ) {
F_38 ( L_5
L_4 ,
V_23 -> V_71 ,
F_47 ( V_23 ) ,
F_42 ( V_23 ) ,
F_43 ( V_23 ) ,
F_52 ( V_23 ) ) ;
V_14 = - V_75 ;
goto V_76;
}
}
if ( F_53 ( V_46 ) )
F_24 ( V_23 ) ;
else
F_26 ( V_23 ) ;
F_54 ( V_23 ) ;
F_42 ( V_23 ) ;
F_55 ( V_23 , F_11 ( V_7 -> V_77 ) ) ;
if ( F_42 ( V_23 ) )
F_56 ( L_6 ,
V_23 -> V_71 , F_42 ( V_23 ) ) ;
F_2 ( V_7 ) ;
F_45 ( V_23 , V_7 -> V_1 ) ;
F_46 ( V_23 , V_7 -> V_2 ) ;
( void ) F_43 ( V_23 ) ;
F_44 ( V_23 ,
( ( V_7 -> V_3 - V_78 ) & V_79 )
| V_80 ) ;
if ( F_57 ( V_46 , F_58 ( V_23 -> V_48 ) ,
V_80 , V_80 ,
50 ) ) {
F_38 ( L_7
L_8 ,
V_23 -> V_71 ,
F_47 ( V_23 ) ,
F_47 ( V_23 ) & V_80 ,
F_42 ( V_23 ) , V_7 -> V_1 ,
F_43 ( V_23 ) , V_7 -> V_2 ,
F_52 ( V_23 ) ,
F_11 ( V_7 -> V_77 ) ) ;
V_14 = - V_75 ;
goto V_76;
}
F_59 ( V_23 ) ;
V_76:
F_60 ( V_46 , V_74 ) ;
return V_14 ;
}
static void F_61 ( struct V_44 * V_23 ,
struct V_10 * V_81 )
{
struct V_6 * V_7 = V_81 -> V_7 ;
V_7 -> V_1 = V_81 -> V_82 ;
V_7 -> V_8 = - 1 ;
}
static int F_62 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_83 * V_84 = & V_11 -> V_20 -> V_85 ;
int V_14 , V_86 ;
if ( V_84 -> V_87 == 0 )
return 0 ;
V_14 = V_11 -> V_23 -> V_88 ( V_11 , V_89 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_4 ( V_11 , ( V_84 -> V_87 * 2 + 2 ) ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_63 ( V_84 -> V_87 ) ) ;
for ( V_86 = 0 ; V_86 < V_84 -> V_87 ; V_86 ++ ) {
F_64 ( V_7 , V_84 -> V_67 [ V_86 ] . V_50 ) ;
F_5 ( V_7 , V_84 -> V_67 [ V_86 ] . V_90 ) ;
}
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_14 = V_11 -> V_23 -> V_88 ( V_11 , V_89 ) ;
if ( V_14 )
return V_14 ;
F_65 ( L_9 , V_84 -> V_87 ) ;
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
T_3 V_50 ,
const T_1 V_91 , const T_1 V_92 )
{
const T_1 V_93 = V_46 -> V_85 . V_87 ;
if ( F_34 ( V_93 >= V_94 ) )
return - V_95 ;
V_46 -> V_85 . V_67 [ V_93 ] . V_50 = V_50 ;
V_46 -> V_85 . V_67 [ V_93 ] . V_90 = V_92 ;
V_46 -> V_85 . V_67 [ V_93 ] . V_91 = V_91 ;
V_46 -> V_85 . V_87 ++ ;
return 0 ;
}
static int F_69 ( struct V_44 * V_23 ,
T_3 V_67 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_83 * V_96 = & V_46 -> V_85 ;
const T_4 V_97 = V_96 -> V_98 [ V_23 -> V_55 ] ;
if ( F_34 ( V_97 >= V_99 ) )
return - V_100 ;
F_70 ( F_71 ( V_23 -> V_48 , V_97 ) ,
F_72 ( V_67 ) ) ;
V_96 -> V_98 [ V_23 -> V_55 ] ++ ;
return 0 ;
}
static int F_73 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_74 ( V_101 , V_102 ) ;
F_74 ( V_103 , V_104 ) ;
F_74 ( V_105 ,
V_106 ) ;
F_74 ( V_107 ,
V_108 |
V_109 ) ;
F_75 ( V_110 , V_111 ) ;
F_74 ( V_112 , V_113 ) ;
F_76 ( V_114 ,
V_115 ,
V_116 ) ;
return 0 ;
}
static int F_77 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_73 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_74 ( V_105 , V_117 ) ;
F_74 ( V_118 ,
V_119 ) ;
F_74 ( V_120 ,
V_121 ) ;
F_74 ( V_107 ,
V_122 |
( F_78 ( V_46 ) ? V_123 : 0 ) ) ;
return 0 ;
}
static int F_79 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_73 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_74 ( V_105 , V_117 ) ;
F_74 ( V_124 , V_125 ) ;
return 0 ;
}
static int F_80 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
F_25 ( V_126 , F_36 ( V_127 ) ) ;
F_25 ( V_128 , F_23 ( V_128 ) |
V_129 ) ;
F_25 ( V_130 , F_23 ( V_130 ) |
V_131 ) ;
F_74 ( V_105 ,
V_132 |
V_106 ) ;
F_74 ( V_120 ,
V_133 ) ;
if ( F_81 ( V_46 , 0 , V_134 ) ||
F_82 ( V_46 , 0 , V_135 ) )
F_75 ( V_136 ,
V_137 ) ;
if ( F_81 ( V_46 , 0 , V_134 ) ||
F_82 ( V_46 , 0 , V_135 ) ) {
F_74 ( V_138 ,
V_139 ) ;
}
F_74 ( V_140 ,
V_141 |
V_142 ) ;
F_74 ( V_112 , ( V_113 |
V_143 ) ) ;
F_75 ( V_136 ,
V_144 ) ;
if ( F_81 ( V_46 , V_145 , V_145 ) ||
F_82 ( V_46 , 0 , V_135 ) )
F_74 ( V_146 ,
V_147 ) ;
F_74 ( V_107 ,
V_122 |
V_148 ) ;
F_74 ( V_107 ,
V_109 ) ;
F_25 ( V_130 , F_23 ( V_130 ) |
V_149 ) ;
if ( F_83 ( V_46 ) ||
F_84 ( V_46 ) ||
F_82 ( V_46 , 0 , V_150 ) )
F_74 ( V_120 ,
V_121 ) ;
F_74 ( V_151 , V_152 ) ;
F_25 ( V_153 , ( F_23 ( V_153 ) |
V_154 ) ) ;
V_14 = F_69 ( V_23 , V_155 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_23 , V_156 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_23 , V_157 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
static int F_85 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
T_5 V_158 [ 3 ] = { 0 , 0 , 0 } ;
unsigned int V_86 ;
for ( V_86 = 0 ; V_86 < 3 ; V_86 ++ ) {
T_5 V_159 ;
if ( ! F_86 ( F_87 ( V_46 ) -> V_160 . V_161 [ V_86 ] ) )
continue;
V_159 = F_88 ( F_87 ( V_46 ) -> V_160 . V_161 [ V_86 ] ) - 1 ;
V_158 [ V_86 ] = 3 - V_159 ;
}
if ( V_158 [ 0 ] == 0 && V_158 [ 1 ] == 0 && V_158 [ 2 ] == 0 )
return 0 ;
F_76 ( V_114 ,
F_89 ( 2 ) |
F_89 ( 1 ) |
F_89 ( 0 ) ,
F_90 ( 2 , V_158 [ 2 ] ) |
F_90 ( 1 , V_158 [ 1 ] ) |
F_90 ( 0 , V_158 [ 0 ] ) ) ;
return 0 ;
}
static int F_91 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_80 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_81 ( V_46 , V_162 , V_163 ) ) {
F_25 ( V_164 ,
F_36 ( V_165 ) ) ;
}
if ( F_81 ( V_46 , 0 , V_162 ) ) {
F_25 ( V_166 ,
F_36 ( V_167 ) ) ;
}
if ( F_81 ( V_46 , 0 , V_162 ) )
F_25 ( V_153 , F_23 ( V_153 ) |
V_168 ) ;
if ( F_81 ( V_46 , V_145 , V_163 ) ) {
F_25 ( V_169 , ( F_23 ( V_169 ) |
V_170 ) ) ;
}
if ( F_81 ( V_46 , V_134 , V_134 ) )
F_74 ( V_124 ,
V_171 ) ;
if ( F_81 ( V_46 , V_145 , V_172 ) )
F_74 ( V_107 ,
V_123 |
V_173 ) ;
if ( F_81 ( V_46 , 0 , V_174 ) )
F_74 (
V_175 ,
V_176 ) ;
F_92 ( V_177 , V_178 ) ;
if ( F_81 ( V_46 , V_179 , V_163 ) )
F_92 ( V_180 ,
V_181 ) ;
V_14 = F_69 ( V_23 , V_153 ) ;
if ( V_14 )
return V_14 ;
return F_85 ( V_23 ) ;
}
static int F_93 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_80 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_82 ( V_46 , 0 , V_135 ) )
F_25 ( V_182 , F_23 ( V_182 ) | V_183 ) ;
if ( F_82 ( V_46 , 0 , V_135 ) ) {
F_25 ( V_184 , ( F_23 ( V_184 ) &
~ V_185 ) ) ;
}
F_74 ( V_105 ,
V_117 ) ;
if ( F_82 ( V_46 , V_150 , V_163 ) ) {
F_74 ( V_166 ,
V_186 ) ;
}
if ( F_82 ( V_46 , 0 , V_150 ) ) {
F_74 (
V_175 ,
V_176 ) ;
}
if ( F_82 ( V_46 , 0 , V_135 ) ) {
V_14 = F_69 ( V_23 , V_187 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_69 ( V_23 , V_153 ) ;
if ( V_14 )
return V_14 ;
}
if ( F_82 ( V_46 , V_150 , V_163 ) )
F_25 ( V_188 , F_94 ( 62 ) |
F_95 ( 2 ) ) ;
if ( F_82 ( V_46 , V_189 , V_163 ) )
F_74 ( V_190 ,
V_191 ) ;
if ( F_82 ( V_46 , V_189 , V_163 ) )
F_92 ( V_180 ,
V_181 ) ;
return 0 ;
}
static int F_96 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
V_14 = F_80 ( V_23 ) ;
if ( V_14 )
return V_14 ;
F_25 ( V_169 , ( F_23 ( V_169 ) |
V_170 ) ) ;
if ( F_97 ( V_46 , 0 , V_192 ) )
F_92 ( V_193 ,
V_194 ) ;
if ( F_97 ( V_46 , V_195 , V_195 ) )
F_74 ( V_107 ,
V_123 ) ;
if ( F_97 ( V_46 , 0 , V_196 ) )
F_25 ( V_153 , F_23 ( V_153 ) |
V_168 ) ;
if ( F_97 ( V_46 , V_197 , V_163 ) )
F_74 ( V_190 ,
V_191 ) ;
F_92 ( V_177 , V_178 ) ;
F_74 (
V_175 ,
V_176 ) ;
F_92 ( V_180 ,
V_181 ) ;
V_14 = F_69 ( V_23 , V_153 ) ;
if ( V_14 )
return V_14 ;
return 0 ;
}
int F_98 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_34 ( V_23 -> V_55 != V_56 ) ;
V_46 -> V_85 . V_87 = 0 ;
V_46 -> V_85 . V_98 [ V_56 ] = 0 ;
if ( F_99 ( V_46 ) )
return F_77 ( V_23 ) ;
if ( F_100 ( V_46 ) )
return F_79 ( V_23 ) ;
if ( F_83 ( V_46 ) )
return F_91 ( V_23 ) ;
if ( F_101 ( V_46 ) )
return F_93 ( V_23 ) ;
if ( F_84 ( V_46 ) )
return F_96 ( V_23 ) ;
return 0 ;
}
static int F_102 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 = F_49 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_32 ( V_46 , 4 , 6 ) )
F_25 ( V_103 , F_36 ( V_198 ) ) ;
if ( F_32 ( V_46 , 6 , 7 ) )
F_25 ( V_103 , F_36 ( V_104 ) ) ;
if ( F_28 ( V_46 ) )
F_25 ( V_199 ,
F_36 ( V_200 ) ) ;
if ( F_27 ( V_46 ) )
F_25 ( V_201 ,
F_36 ( V_200 ) |
F_36 ( V_202 ) ) ;
if ( F_28 ( V_46 ) ) {
F_25 ( V_203 ,
F_48 ( V_204 ) ) ;
}
if ( F_32 ( V_46 , 6 , 7 ) )
F_25 ( V_101 , F_36 ( V_102 ) ) ;
if ( F_87 ( V_46 ) -> V_205 >= 6 )
F_103 ( V_23 , ~ V_23 -> V_206 ) ;
return F_98 ( V_23 ) ;
}
static void F_104 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_105 ( & V_46 -> V_207 ) ;
}
static int F_106 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_208 ;
enum V_209 V_55 ;
int V_14 , V_210 ;
V_210 = F_87 ( V_46 ) -> V_210 ;
V_14 = F_4 ( V_11 , ( V_210 - 1 ) * 8 ) ;
if ( V_14 )
return V_14 ;
F_107 (waiter, dev_priv, id) {
T_2 V_211 = V_11 -> V_23 -> V_207 . V_212 [ V_55 ] ;
if ( V_211 == V_213 )
continue;
F_5 ( V_7 , F_12 ( 6 ) ) ;
F_5 ( V_7 ,
V_43 |
V_29 |
V_26 ) ;
F_5 ( V_7 , F_108 ( V_211 ) ) ;
F_5 ( V_7 , F_109 ( V_211 ) ) ;
F_5 ( V_7 , V_11 -> V_214 . V_215 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 ,
V_216 |
F_110 ( V_208 -> V_217 ) ) ;
F_5 ( V_7 , 0 ) ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int F_111 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_208 ;
enum V_209 V_55 ;
int V_14 , V_210 ;
V_210 = F_87 ( V_46 ) -> V_210 ;
V_14 = F_4 ( V_11 , ( V_210 - 1 ) * 6 ) ;
if ( V_14 )
return V_14 ;
F_107 (waiter, dev_priv, id) {
T_2 V_211 = V_11 -> V_23 -> V_207 . V_212 [ V_55 ] ;
if ( V_211 == V_213 )
continue;
F_5 ( V_7 ,
( V_218 + 1 ) | V_219 ) ;
F_5 ( V_7 ,
F_108 ( V_211 ) |
V_220 ) ;
F_5 ( V_7 , F_109 ( V_211 ) ) ;
F_5 ( V_7 , V_11 -> V_214 . V_215 ) ;
F_5 ( V_7 ,
V_216 |
F_110 ( V_208 -> V_217 ) ) ;
F_5 ( V_7 , 0 ) ;
}
F_6 ( V_7 ) ;
return 0 ;
}
static int F_112 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_45 * V_46 = V_11 -> V_20 ;
struct V_44 * V_23 ;
int V_14 , V_210 ;
V_210 = F_87 ( V_46 ) -> V_210 ;
V_14 = F_4 ( V_11 , F_113 ( ( V_210 - 1 ) * 3 , 2 ) ) ;
if ( V_14 )
return V_14 ;
F_114 (engine, dev_priv) {
T_3 V_221 ;
if ( ! ( F_115 ( V_23 -> V_217 ) & V_222 ) )
continue;
V_221 = V_11 -> V_23 -> V_207 . V_223 . signal [ V_23 -> V_217 ] ;
if ( F_116 ( V_221 ) ) {
F_5 ( V_7 , F_63 ( 1 ) ) ;
F_64 ( V_7 , V_221 ) ;
F_5 ( V_7 , V_11 -> V_214 . V_215 ) ;
}
}
if ( V_210 % 2 == 0 )
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void F_117 ( struct V_10 * V_81 )
{
struct V_45 * V_46 = V_81 -> V_20 ;
F_46 ( V_81 -> V_23 ,
F_118 ( V_81 -> V_7 , V_81 -> V_2 ) ) ;
}
static int F_119 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_224 ) ;
F_5 ( V_7 , V_225 << V_226 ) ;
F_5 ( V_7 , V_11 -> V_214 . V_215 ) ;
F_5 ( V_7 , V_227 ) ;
F_6 ( V_7 ) ;
V_11 -> V_2 = V_7 -> V_2 ;
return 0 ;
}
static int F_120 ( struct V_10 * V_11 )
{
int V_14 ;
V_14 = V_11 -> V_23 -> V_207 . signal ( V_11 ) ;
if ( V_14 )
return V_14 ;
return F_119 ( V_11 ) ;
}
static int F_121 ( struct V_10 * V_11 )
{
struct V_44 * V_23 = V_11 -> V_23 ;
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
if ( V_23 -> V_207 . signal ) {
V_14 = V_23 -> V_207 . signal ( V_11 ) ;
if ( V_14 )
return V_14 ;
}
V_14 = F_4 ( V_11 , 8 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , F_12 ( 6 ) ) ;
F_5 ( V_7 , ( V_43 |
V_26 |
V_29 ) ) ;
F_5 ( V_7 , F_122 ( V_23 ) ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , F_123 ( V_11 ) ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_227 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_11 -> V_2 = V_7 -> V_2 ;
return 0 ;
}
static int
F_124 ( struct V_10 * V_11 ,
struct V_10 * signal )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_45 * V_46 = V_11 -> V_20 ;
T_2 V_228 = F_125 ( V_11 -> V_23 , signal -> V_23 -> V_55 ) ;
struct V_229 * V_230 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_231 |
V_232 |
V_233 ) ;
F_5 ( V_7 , signal -> V_214 . V_215 ) ;
F_5 ( V_7 , F_108 ( V_228 ) ) ;
F_5 ( V_7 , F_109 ( V_228 ) ) ;
F_6 ( V_7 ) ;
V_230 = V_11 -> V_234 -> V_230 ;
if ( V_230 && V_11 -> V_23 -> V_55 != V_56 )
V_230 -> V_235 |= F_126 ( V_11 -> V_23 ) ;
return 0 ;
}
static int
F_127 ( struct V_10 * V_11 ,
struct V_10 * signal )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_236 = V_237 |
V_238 |
V_239 ;
T_1 V_240 = signal -> V_23 -> V_207 . V_223 . V_241 [ V_11 -> V_23 -> V_217 ] ;
int V_14 ;
F_34 ( V_240 == V_213 ) ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_236 | V_240 ) ;
F_5 ( V_7 , signal -> V_214 . V_215 - 1 ) ;
F_5 ( V_7 , 0 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void
F_128 ( struct V_44 * V_23 )
{
F_129 ( 125 , 250 ) ;
}
static void
F_130 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_131 ( & V_46 -> V_242 . V_243 ) ;
F_132 ( F_21 ( V_23 -> V_48 ) ) ;
F_133 ( & V_46 -> V_242 . V_243 ) ;
}
static void
F_134 ( struct V_44 * V_23 )
{
F_135 ( V_23 -> V_20 , V_23 -> V_244 ) ;
}
static void
F_136 ( struct V_44 * V_23 )
{
F_137 ( V_23 -> V_20 , V_23 -> V_244 ) ;
}
static void
F_138 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_245 &= ~ V_23 -> V_244 ;
F_25 ( V_246 , V_46 -> V_245 ) ;
F_132 ( F_139 ( V_23 -> V_48 ) ) ;
}
static void
F_140 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_245 |= V_23 -> V_244 ;
F_25 ( V_246 , V_46 -> V_245 ) ;
}
static void
F_141 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_245 &= ~ V_23 -> V_244 ;
F_142 ( V_246 , V_46 -> V_245 ) ;
F_143 ( F_139 ( V_23 -> V_48 ) ) ;
}
static void
F_144 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_245 |= V_23 -> V_244 ;
F_142 ( V_246 , V_46 -> V_245 ) ;
}
static int
F_145 ( struct V_10 * V_11 , T_1 V_12 )
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
F_146 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_103 ( V_23 ,
~ ( V_23 -> V_244 |
V_23 -> V_206 ) ) ;
F_135 ( V_46 , V_23 -> V_244 ) ;
}
static void
F_147 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_103 ( V_23 , ~ V_23 -> V_206 ) ;
F_137 ( V_46 , V_23 -> V_244 ) ;
}
static void
F_148 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_103 ( V_23 , ~ V_23 -> V_244 ) ;
F_149 ( V_46 , V_23 -> V_244 ) ;
}
static void
F_150 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_103 ( V_23 , ~ 0 ) ;
F_151 ( V_46 , V_23 -> V_244 ) ;
}
static void
F_152 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_103 ( V_23 ,
~ ( V_23 -> V_244 |
V_23 -> V_206 ) ) ;
F_132 ( F_139 ( V_23 -> V_48 ) ) ;
}
static void
F_153 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_103 ( V_23 , ~ V_23 -> V_206 ) ;
}
static int
F_154 ( struct V_10 * V_11 ,
T_2 V_228 , T_1 V_247 ,
unsigned int V_248 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_249 |
V_250 |
( V_248 & V_251 ?
0 : V_252 ) ) ;
F_5 ( V_7 , V_228 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_155 ( struct V_10 * V_11 ,
T_2 V_228 , T_1 V_253 ,
unsigned int V_248 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_1 V_254 = F_11 ( V_11 -> V_23 -> V_24 ) ;
int V_14 ;
V_14 = F_4 ( V_11 , 6 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_255 | V_256 ) ;
F_5 ( V_7 , V_257 | V_258 | 4096 ) ;
F_5 ( V_7 , V_259 << 16 | 4 ) ;
F_5 ( V_7 , V_254 ) ;
F_5 ( V_7 , 0xdeadbeef ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
if ( ( V_248 & V_260 ) == 0 ) {
if ( V_253 > V_261 )
return - V_95 ;
V_14 = F_4 ( V_11 , 6 + 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_262 | V_256 ) ;
F_5 ( V_7 ,
V_257 | V_263 | 4096 ) ;
F_5 ( V_7 , F_156 ( V_253 , 4096 ) << 16 | 4096 ) ;
F_5 ( V_7 , V_254 ) ;
F_5 ( V_7 , 4096 ) ;
F_5 ( V_7 , V_228 ) ;
F_5 ( V_7 , V_15 ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
V_228 = V_254 ;
}
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_249 | V_250 ) ;
F_5 ( V_7 , V_228 | ( V_248 & V_251 ?
0 : V_264 ) ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_157 ( struct V_10 * V_11 ,
T_2 V_228 , T_1 V_253 ,
unsigned int V_248 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_249 | V_250 ) ;
F_5 ( V_7 , V_228 | ( V_248 & V_251 ?
0 : V_264 ) ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void F_158 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
if ( ! V_46 -> V_51 )
return;
F_159 ( & V_46 -> V_265 , V_46 -> V_51 ) ;
V_23 -> V_65 . V_266 = NULL ;
}
static void F_160 ( struct V_44 * V_23 )
{
struct V_267 * V_77 ;
V_77 = F_161 ( & V_23 -> V_65 . V_77 ) ;
if ( ! V_77 )
return;
F_162 ( V_77 ) ;
F_163 ( V_77 -> V_268 ) ;
F_164 ( V_77 ) ;
}
static int F_165 ( struct V_44 * V_23 )
{
struct V_269 * V_268 ;
struct V_267 * V_77 ;
unsigned int V_30 ;
int V_14 ;
V_268 = F_166 ( & V_23 -> V_20 -> V_265 , 4096 ) ;
if ( F_167 ( V_268 ) ) {
F_38 ( L_10 ) ;
return F_168 ( V_268 ) ;
}
V_14 = F_169 ( V_268 , V_270 ) ;
if ( V_14 )
goto V_271;
V_77 = F_170 ( V_268 , & V_23 -> V_20 -> V_272 . V_273 , NULL ) ;
if ( F_167 ( V_77 ) ) {
V_14 = F_168 ( V_77 ) ;
goto V_271;
}
V_30 = V_274 ;
if ( ! F_171 ( V_23 -> V_20 ) )
V_30 |= V_275 ;
V_14 = F_172 ( V_77 , 0 , 4096 , V_30 ) ;
if ( V_14 )
goto V_271;
V_23 -> V_65 . V_77 = V_77 ;
V_23 -> V_65 . V_66 = F_11 ( V_77 ) ;
V_23 -> V_65 . V_266 =
F_173 ( V_268 , V_276 ) ;
F_65 ( L_11 ,
V_23 -> V_71 , F_11 ( V_77 ) ) ;
return 0 ;
V_271:
F_174 ( V_268 ) ;
return V_14 ;
}
static int F_175 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
V_46 -> V_51 =
F_176 ( & V_46 -> V_265 , V_78 , V_78 ) ;
if ( ! V_46 -> V_51 )
return - V_277 ;
V_23 -> V_65 . V_266 = V_46 -> V_51 -> V_278 ;
memset ( V_23 -> V_65 . V_266 , 0 , V_78 ) ;
return 0 ;
}
int F_177 ( struct V_6 * V_7 )
{
unsigned int V_30 = V_274 | V_279 | 4096 ;
enum V_280 V_281 ;
struct V_267 * V_77 = V_7 -> V_77 ;
void * V_50 ;
int V_14 ;
F_178 ( V_7 -> V_278 ) ;
V_281 = F_171 ( V_7 -> V_23 -> V_20 ) ? V_276 : V_282 ;
if ( V_77 -> V_268 -> V_283 )
V_30 |= V_275 ;
if ( ! ( V_77 -> V_30 & V_284 ) ) {
if ( V_30 & V_275 || V_281 == V_282 )
V_14 = F_179 ( V_77 -> V_268 , true ) ;
else
V_14 = F_180 ( V_77 -> V_268 , true ) ;
if ( F_181 ( V_14 ) )
return V_14 ;
}
V_14 = F_172 ( V_77 , 0 , V_78 , V_30 ) ;
if ( F_181 ( V_14 ) )
return V_14 ;
if ( F_182 ( V_77 ) )
V_50 = ( void V_285 * ) F_183 ( V_77 ) ;
else
V_50 = F_173 ( V_77 -> V_268 , V_281 ) ;
if ( F_167 ( V_50 ) )
goto V_271;
V_7 -> V_278 = V_50 ;
return 0 ;
V_271:
F_162 ( V_77 ) ;
return F_168 ( V_50 ) ;
}
void F_184 ( struct V_6 * V_7 )
{
F_178 ( ! V_7 -> V_77 ) ;
F_178 ( ! V_7 -> V_278 ) ;
if ( F_182 ( V_7 -> V_77 ) )
F_185 ( V_7 -> V_77 ) ;
else
F_163 ( V_7 -> V_77 -> V_268 ) ;
V_7 -> V_278 = NULL ;
F_162 ( V_7 -> V_77 ) ;
}
static struct V_267 *
F_186 ( struct V_45 * V_46 , int V_3 )
{
struct V_269 * V_268 ;
struct V_267 * V_77 ;
V_268 = F_187 ( & V_46 -> V_265 , V_3 ) ;
if ( ! V_268 )
V_268 = F_166 ( & V_46 -> V_265 , V_3 ) ;
if ( F_167 ( V_268 ) )
return F_188 ( V_268 ) ;
V_268 -> V_286 = 1 ;
V_77 = F_170 ( V_268 , & V_46 -> V_272 . V_273 , NULL ) ;
if ( F_167 ( V_77 ) )
goto V_271;
return V_77 ;
V_271:
F_174 ( V_268 ) ;
return V_77 ;
}
struct V_6 *
F_189 ( struct V_44 * V_23 , int V_3 )
{
struct V_6 * V_7 ;
struct V_267 * V_77 ;
F_178 ( ! F_86 ( V_3 ) ) ;
V_7 = F_190 ( sizeof( * V_7 ) , V_287 ) ;
if ( ! V_7 )
return F_191 ( - V_277 ) ;
V_7 -> V_23 = V_23 ;
F_192 ( & V_7 -> V_288 ) ;
V_7 -> V_3 = V_3 ;
V_7 -> V_289 = V_3 ;
if ( F_193 ( V_23 -> V_20 ) || F_194 ( V_23 -> V_20 ) )
V_7 -> V_289 -= 2 * V_25 ;
V_7 -> V_8 = - 1 ;
F_2 ( V_7 ) ;
V_77 = F_186 ( V_23 -> V_20 , V_3 ) ;
if ( F_167 ( V_77 ) ) {
F_195 ( V_7 ) ;
return F_188 ( V_77 ) ;
}
V_7 -> V_77 = V_77 ;
return V_7 ;
}
void
F_196 ( struct V_6 * V_7 )
{
F_164 ( V_7 -> V_77 ) ;
F_195 ( V_7 ) ;
}
static int F_197 ( struct V_290 * V_234 ,
struct V_44 * V_23 )
{
struct V_291 * V_292 = & V_234 -> V_23 [ V_23 -> V_55 ] ;
int V_14 ;
F_198 ( & V_234 -> V_20 -> V_265 . V_293 ) ;
if ( V_292 -> V_294 ++ )
return 0 ;
if ( V_292 -> V_295 ) {
V_14 = F_179 ( V_292 -> V_295 -> V_268 , false ) ;
if ( V_14 )
goto error;
V_14 = F_172 ( V_292 -> V_295 , 0 , V_234 -> V_296 ,
V_274 | V_297 ) ;
if ( V_14 )
goto error;
}
if ( V_234 == V_234 -> V_20 -> V_298 )
V_292 -> V_299 = true ;
F_199 ( V_234 ) ;
return 0 ;
error:
V_292 -> V_294 = 0 ;
return V_14 ;
}
static void F_200 ( struct V_290 * V_234 ,
struct V_44 * V_23 )
{
struct V_291 * V_292 = & V_234 -> V_23 [ V_23 -> V_55 ] ;
F_198 ( & V_234 -> V_20 -> V_265 . V_293 ) ;
if ( -- V_292 -> V_294 )
return;
if ( V_292 -> V_295 )
F_162 ( V_292 -> V_295 ) ;
F_201 ( V_234 ) ;
}
static int F_202 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
struct V_6 * V_7 ;
int V_14 ;
F_34 ( V_23 -> V_73 ) ;
F_203 ( V_23 ) ;
memset ( V_23 -> V_207 . V_300 , 0 ,
sizeof( V_23 -> V_207 . V_300 ) ) ;
V_14 = F_204 ( V_23 ) ;
if ( V_14 )
goto error;
V_14 = F_197 ( V_46 -> V_298 , V_23 ) ;
if ( V_14 )
goto error;
V_7 = F_189 ( V_23 , 32 * V_78 ) ;
if ( F_167 ( V_7 ) ) {
V_14 = F_168 ( V_7 ) ;
goto error;
}
if ( F_53 ( V_46 ) ) {
F_34 ( V_23 -> V_55 != V_56 ) ;
V_14 = F_175 ( V_23 ) ;
if ( V_14 )
goto error;
} else {
V_14 = F_165 ( V_23 ) ;
if ( V_14 )
goto error;
}
V_14 = F_177 ( V_7 ) ;
if ( V_14 ) {
F_196 ( V_7 ) ;
goto error;
}
V_23 -> V_73 = V_7 ;
return 0 ;
error:
F_205 ( V_23 ) ;
return V_14 ;
}
void F_205 ( struct V_44 * V_23 )
{
struct V_45 * V_46 ;
if ( ! F_206 ( V_23 ) )
return;
V_46 = V_23 -> V_20 ;
if ( V_23 -> V_73 ) {
F_34 ( F_19 ( V_46 ) > 2 &&
( F_35 ( V_23 ) & V_68 ) == 0 ) ;
F_184 ( V_23 -> V_73 ) ;
F_196 ( V_23 -> V_73 ) ;
V_23 -> V_73 = NULL ;
}
if ( V_23 -> V_301 )
V_23 -> V_301 ( V_23 ) ;
if ( F_53 ( V_46 ) ) {
F_34 ( V_23 -> V_55 != V_56 ) ;
F_158 ( V_23 ) ;
} else {
F_160 ( V_23 ) ;
}
F_207 ( V_23 ) ;
F_200 ( V_46 -> V_298 , V_23 ) ;
V_23 -> V_20 = NULL ;
}
void F_208 ( struct V_45 * V_46 )
{
struct V_44 * V_23 ;
F_114 (engine, dev_priv) {
V_23 -> V_73 -> V_1 = V_23 -> V_73 -> V_2 ;
V_23 -> V_73 -> V_8 = - 1 ;
}
}
int F_209 ( struct V_10 * V_81 )
{
int V_14 ;
V_81 -> V_302 += V_303 ;
V_81 -> V_7 = V_81 -> V_23 -> V_73 ;
V_14 = F_4 ( V_81 , 0 ) ;
if ( V_14 )
return V_14 ;
V_81 -> V_302 -= V_303 ;
return 0 ;
}
static int F_210 ( struct V_10 * V_11 , int V_304 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
struct V_10 * V_305 ;
int V_14 ;
F_2 ( V_7 ) ;
if ( V_7 -> V_4 >= V_304 )
return 0 ;
F_178 ( ! V_11 -> V_302 ) ;
F_211 (target, &ring->request_list, ring_link) {
unsigned V_4 ;
V_4 = F_1 ( V_305 -> V_82 , V_7 -> V_2 ,
V_7 -> V_3 ) ;
if ( V_4 >= V_304 )
break;
}
if ( F_34 ( & V_305 -> V_306 == & V_7 -> V_288 ) )
return - V_95 ;
V_14 = F_212 ( V_305 ,
V_307 | V_308 ,
NULL , V_309 ) ;
if ( V_14 )
return V_14 ;
F_213 ( V_305 ) ;
F_2 ( V_7 ) ;
F_178 ( V_7 -> V_4 < V_304 ) ;
return 0 ;
}
int F_4 ( struct V_10 * V_11 , int V_310 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_311 = V_7 -> V_3 - V_7 -> V_2 ;
int V_312 = V_7 -> V_289 - V_7 -> V_2 ;
int V_304 = V_310 * sizeof( T_1 ) ;
int V_313 , V_314 ;
bool V_315 = false ;
V_313 = V_304 + V_11 -> V_302 ;
if ( F_181 ( V_304 > V_312 ) ) {
V_314 = V_311 + V_313 ;
V_315 = true ;
} else if ( F_181 ( V_313 > V_312 ) ) {
V_314 = V_311 + V_11 -> V_302 ;
} else {
V_314 = V_313 ;
}
if ( V_314 > V_7 -> V_4 ) {
int V_14 = F_210 ( V_11 , V_314 ) ;
if ( F_181 ( V_14 ) )
return V_14 ;
}
if ( F_181 ( V_315 ) ) {
F_178 ( V_311 > V_7 -> V_4 ) ;
F_178 ( V_7 -> V_2 + V_311 > V_7 -> V_3 ) ;
memset ( V_7 -> V_278 + V_7 -> V_2 , 0 , V_311 ) ;
V_7 -> V_2 = 0 ;
V_7 -> V_4 -= V_311 ;
}
V_7 -> V_4 -= V_304 ;
F_178 ( V_7 -> V_4 < 0 ) ;
return 0 ;
}
int F_214 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_310 =
( V_7 -> V_2 & ( V_25 - 1 ) ) / sizeof( T_4 ) ;
int V_14 ;
if ( V_310 == 0 )
return 0 ;
V_310 = V_25 / sizeof( T_4 ) - V_310 ;
V_14 = F_4 ( V_11 , V_310 ) ;
if ( V_14 )
return V_14 ;
while ( V_310 -- )
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static void F_215 ( struct V_10 * V_81 )
{
struct V_45 * V_46 = V_81 -> V_20 ;
F_50 ( V_46 , V_74 ) ;
F_216 ( V_316 ,
F_36 ( V_317 ) ) ;
F_217 ( V_318 , 0x0 ) ;
if ( F_57 ( V_46 ,
V_316 ,
V_319 ,
0 ,
50 ) )
F_38 ( L_12 ) ;
F_117 ( V_81 ) ;
F_216 ( V_316 ,
F_48 ( V_317 ) ) ;
F_60 ( V_46 , V_74 ) ;
}
static int F_218 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_4 V_13 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
V_13 = V_218 ;
if ( F_19 ( V_11 -> V_20 ) >= 8 )
V_13 += 1 ;
V_13 |= V_320 | V_219 ;
if ( V_12 & V_16 )
V_13 |= V_321 | V_322 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 , V_323 | V_220 ) ;
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
F_219 ( struct V_10 * V_11 ,
T_2 V_228 , T_1 V_253 ,
unsigned int V_248 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
bool V_230 = F_220 ( V_11 -> V_20 ) &&
! ( V_248 & V_251 ) ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 , V_324 | ( V_230 << 8 ) |
( V_248 & V_325 ?
V_326 : 0 ) ) ;
F_5 ( V_7 , F_108 ( V_228 ) ) ;
F_5 ( V_7 , F_109 ( V_228 ) ) ;
F_5 ( V_7 , V_18 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_221 ( struct V_10 * V_11 ,
T_2 V_228 , T_1 V_253 ,
unsigned int V_248 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_249 |
( V_248 & V_251 ?
0 : V_327 | V_328 ) |
( V_248 & V_325 ?
V_326 : 0 ) ) ;
F_5 ( V_7 , V_228 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int
F_222 ( struct V_10 * V_11 ,
T_2 V_228 , T_1 V_253 ,
unsigned int V_248 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
int V_14 ;
V_14 = F_4 ( V_11 , 2 ) ;
if ( V_14 )
return V_14 ;
F_5 ( V_7 ,
V_249 |
( V_248 & V_251 ?
0 : V_252 ) ) ;
F_5 ( V_7 , V_228 ) ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_223 ( struct V_10 * V_11 , T_1 V_12 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
T_4 V_13 ;
int V_14 ;
V_14 = F_4 ( V_11 , 4 ) ;
if ( V_14 )
return V_14 ;
V_13 = V_218 ;
if ( F_19 ( V_11 -> V_20 ) >= 8 )
V_13 += 1 ;
V_13 |= V_320 | V_219 ;
if ( V_12 & V_16 )
V_13 |= V_321 ;
F_5 ( V_7 , V_13 ) ;
F_5 ( V_7 ,
V_323 | V_220 ) ;
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
static void F_224 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
struct V_269 * V_268 ;
int V_14 , V_86 ;
if ( ! V_20 . V_329 )
return;
if ( F_19 ( V_46 ) >= 8 && ! V_46 -> V_207 ) {
struct V_267 * V_77 ;
V_268 = F_166 ( & V_46 -> V_265 , 4096 ) ;
if ( F_167 ( V_268 ) )
goto V_271;
V_77 = F_170 ( V_268 , & V_46 -> V_272 . V_273 , NULL ) ;
if ( F_167 ( V_77 ) )
goto V_330;
V_14 = F_179 ( V_268 , false ) ;
if ( V_14 )
goto V_330;
V_14 = F_172 ( V_77 , 0 , 0 , V_274 | V_297 ) ;
if ( V_14 )
goto V_330;
V_46 -> V_207 = V_77 ;
}
if ( F_19 ( V_46 ) >= 8 ) {
T_1 V_228 = F_11 ( V_46 -> V_207 ) ;
V_23 -> V_207 . V_331 = F_124 ;
V_23 -> V_207 . signal = F_111 ;
for ( V_86 = 0 ; V_86 < V_332 ; V_86 ++ ) {
T_1 V_333 ;
if ( V_86 != V_23 -> V_55 )
V_333 = V_228 + F_225 ( V_23 -> V_55 , V_86 ) ;
else
V_333 = V_213 ;
V_23 -> V_207 . V_212 [ V_86 ] = V_333 ;
}
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_207 . V_331 = F_127 ;
V_23 -> V_207 . signal = F_112 ;
for ( V_86 = 0 ; V_86 < V_334 ; V_86 ++ ) {
static const struct {
T_1 V_240 ;
T_3 V_221 ;
} V_335 [ V_334 ] [ V_334 ] = {
[ V_336 ] = {
[ V_337 ] = { . V_240 = V_338 , . V_221 = V_339 } ,
[ V_340 ] = { . V_240 = V_341 , . V_221 = V_342 } ,
[ V_343 ] = { . V_240 = V_344 , . V_221 = V_345 } ,
} ,
[ V_337 ] = {
[ V_336 ] = { . V_240 = V_346 , . V_221 = V_347 } ,
[ V_340 ] = { . V_240 = V_348 , . V_221 = V_349 } ,
[ V_343 ] = { . V_240 = V_350 , . V_221 = V_351 } ,
} ,
[ V_340 ] = {
[ V_336 ] = { . V_240 = V_352 , . V_221 = V_353 } ,
[ V_337 ] = { . V_240 = V_354 , . V_221 = V_355 } ,
[ V_343 ] = { . V_240 = V_356 , . V_221 = V_357 } ,
} ,
[ V_343 ] = {
[ V_336 ] = { . V_240 = V_358 , . V_221 = V_359 } ,
[ V_337 ] = { . V_240 = V_360 , . V_221 = V_361 } ,
[ V_340 ] = { . V_240 = V_362 , . V_221 = V_363 } ,
} ,
} ;
T_1 V_240 ;
T_3 V_221 ;
if ( V_86 == V_23 -> V_217 ) {
V_240 = V_213 ;
V_221 = V_364 ;
} else {
V_240 = V_335 [ V_23 -> V_217 ] [ V_86 ] . V_240 ;
V_221 = V_335 [ V_23 -> V_217 ] [ V_86 ] . V_221 ;
}
V_23 -> V_207 . V_223 . V_241 [ V_86 ] = V_240 ;
V_23 -> V_207 . V_223 . signal [ V_86 ] = V_221 ;
}
}
return;
V_330:
F_174 ( V_268 ) ;
V_271:
F_65 ( L_13 ) ;
V_20 . V_329 = 0 ;
}
static void F_226 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
V_23 -> V_244 = V_365 << V_23 -> V_366 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_367 = F_152 ;
V_23 -> V_368 = F_153 ;
V_23 -> V_369 = F_130 ;
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_367 = F_146 ;
V_23 -> V_368 = F_147 ;
V_23 -> V_369 = F_130 ;
} else if ( F_19 ( V_46 ) >= 5 ) {
V_23 -> V_367 = F_134 ;
V_23 -> V_368 = F_136 ;
V_23 -> V_369 = F_128 ;
} else if ( F_19 ( V_46 ) >= 3 ) {
V_23 -> V_367 = F_138 ;
V_23 -> V_368 = F_140 ;
} else {
V_23 -> V_367 = F_141 ;
V_23 -> V_368 = F_144 ;
}
}
static void F_227 ( struct V_45 * V_46 ,
struct V_44 * V_23 )
{
F_226 ( V_46 , V_23 ) ;
F_224 ( V_46 , V_23 ) ;
V_23 -> V_370 = F_49 ;
V_23 -> V_371 = F_61 ;
V_23 -> V_372 = F_119 ;
if ( V_20 . V_329 )
V_23 -> V_372 = F_120 ;
V_23 -> V_373 = F_117 ;
if ( F_19 ( V_46 ) >= 8 )
V_23 -> V_374 = F_219 ;
else if ( F_19 ( V_46 ) >= 6 )
V_23 -> V_374 = F_222 ;
else if ( F_19 ( V_46 ) >= 4 )
V_23 -> V_374 = F_154 ;
else if ( F_193 ( V_46 ) || F_194 ( V_46 ) )
V_23 -> V_374 = F_155 ;
else
V_23 -> V_374 = F_157 ;
}
int F_228 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
int V_14 ;
F_227 ( V_46 , V_23 ) ;
if ( F_229 ( V_46 ) )
V_23 -> V_206 = V_375 ;
if ( F_19 ( V_46 ) >= 8 ) {
V_23 -> V_376 = F_66 ;
V_23 -> V_372 = F_121 ;
V_23 -> V_88 = F_17 ;
if ( V_20 . V_329 )
V_23 -> V_207 . signal = F_106 ;
} else if ( F_19 ( V_46 ) >= 6 ) {
V_23 -> V_376 = F_66 ;
V_23 -> V_88 = F_15 ;
if ( F_28 ( V_46 ) )
V_23 -> V_88 = F_13 ;
} else if ( F_9 ( V_46 ) ) {
V_23 -> V_88 = F_7 ;
} else {
if ( F_19 ( V_46 ) < 4 )
V_23 -> V_88 = F_3 ;
else
V_23 -> V_88 = F_7 ;
V_23 -> V_244 = V_377 ;
}
if ( F_230 ( V_46 ) )
V_23 -> V_374 = F_221 ;
V_23 -> V_370 = F_102 ;
V_23 -> V_301 = F_104 ;
V_14 = F_202 ( V_23 ) ;
if ( V_14 )
return V_14 ;
if ( F_19 ( V_46 ) >= 6 ) {
V_14 = F_231 ( V_23 , 4096 ) ;
if ( V_14 )
return V_14 ;
} else if ( F_232 ( V_46 ) ) {
V_14 = F_231 ( V_23 , V_378 ) ;
if ( V_14 )
return V_14 ;
}
return 0 ;
}
int F_233 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_227 ( V_46 , V_23 ) ;
if ( F_19 ( V_46 ) >= 6 ) {
if ( F_28 ( V_46 ) )
V_23 -> V_373 = F_215 ;
V_23 -> V_88 = F_218 ;
if ( F_19 ( V_46 ) < 8 )
V_23 -> V_244 = V_379 ;
} else {
V_23 -> V_48 = V_380 ;
V_23 -> V_88 = F_145 ;
if ( F_9 ( V_46 ) )
V_23 -> V_244 = V_381 ;
else
V_23 -> V_244 = V_382 ;
}
return F_202 ( V_23 ) ;
}
int F_234 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_227 ( V_46 , V_23 ) ;
V_23 -> V_88 = F_218 ;
return F_202 ( V_23 ) ;
}
int F_235 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_227 ( V_46 , V_23 ) ;
V_23 -> V_88 = F_223 ;
if ( F_19 ( V_46 ) < 8 )
V_23 -> V_244 = V_383 ;
return F_202 ( V_23 ) ;
}
int F_236 ( struct V_44 * V_23 )
{
struct V_45 * V_46 = V_23 -> V_20 ;
F_227 ( V_46 , V_23 ) ;
V_23 -> V_88 = F_223 ;
if ( F_19 ( V_46 ) < 8 ) {
V_23 -> V_244 = V_384 ;
V_23 -> V_367 = F_148 ;
V_23 -> V_368 = F_150 ;
}
return F_202 ( V_23 ) ;
}
