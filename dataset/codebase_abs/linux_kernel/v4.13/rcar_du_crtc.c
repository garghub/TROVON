static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
return F_2 ( V_5 , V_2 -> V_8 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_9 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 , V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_10 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 ,
F_2 ( V_5 , V_2 -> V_8 + V_3 ) & ~ V_10 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
F_4 ( V_5 , V_2 -> V_8 + V_3 ,
F_2 ( V_5 , V_2 -> V_8 + V_3 ) | V_11 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_10 , T_1 V_11 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_1 V_12 = F_2 ( V_5 , V_2 -> V_8 + V_3 ) ;
F_4 ( V_5 , V_2 -> V_8 + V_3 , ( V_12 & ~ V_10 ) | V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_9 ( V_2 -> clock ) ;
if ( V_13 < 0 )
return V_13 ;
V_13 = F_9 ( V_2 -> V_14 ) ;
if ( V_13 < 0 )
goto V_15;
V_13 = F_10 ( V_2 -> V_6 ) ;
if ( V_13 < 0 )
goto V_16;
return 0 ;
V_16:
F_11 ( V_2 -> V_14 ) ;
V_15:
F_11 ( V_2 -> clock ) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_6 ) ;
F_11 ( V_2 -> V_14 ) ;
F_11 ( V_2 -> clock ) ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
unsigned long V_19 ,
unsigned long V_20 )
{
unsigned long V_21 = ( unsigned long ) - 1 ;
unsigned long V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
for ( V_25 = 39 ; V_25 < 120 ; V_25 ++ ) {
for ( V_24 = 0 ; V_24 < 4 ; V_24 ++ ) {
for ( V_23 = 1 ; V_23 < 32 ; V_23 ++ ) {
unsigned long V_26 ;
V_26 = V_19 * ( V_25 + 1 ) / ( V_24 + 1 )
/ ( V_23 + 1 ) / 2 ;
if ( V_26 >= 400000000 )
continue;
V_22 = abs ( ( long ) V_26 - ( long ) V_20 ) ;
if ( V_21 > V_22 ) {
V_21 = V_22 ;
V_18 -> V_25 = V_25 ;
V_18 -> V_24 = V_24 ;
V_18 -> V_23 = V_23 ;
V_18 -> V_26 = V_26 ;
}
if ( V_22 == 0 )
goto V_27;
}
}
}
V_27:
F_15 ( V_2 -> V_6 -> V_7 -> V_7 ,
L_1 ,
V_18 -> V_26 , V_18 -> V_23 , V_18 -> V_25 , V_18 -> V_24 ,
V_21 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
const struct V_28 * V_29 = & V_2 -> V_30 . V_31 -> V_32 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
unsigned long V_33 = V_29 -> clock * 1000 ;
unsigned long V_34 ;
T_1 V_12 ;
T_1 V_35 ;
T_1 div ;
V_34 = F_17 ( V_2 -> clock ) ;
div = F_18 ( V_34 , V_33 ) ;
div = F_19 ( div , 1U , 64U ) - 1 ;
V_35 = div | V_36 ;
if ( V_2 -> V_14 ) {
struct V_17 V_18 = { 0 } ;
unsigned long V_37 ;
unsigned long V_38 ;
unsigned long V_39 ;
T_1 V_40 ;
V_37 = F_17 ( V_2 -> V_14 ) ;
if ( V_5 -> V_41 -> V_42 & ( 1 << V_2 -> V_43 ) ) {
F_14 ( V_2 , & V_18 , V_37 , V_33 ) ;
V_37 = V_18 . V_26 ;
}
V_40 = F_18 ( V_37 , V_33 ) ;
V_40 = F_19 ( V_40 , 1U , 64U ) - 1 ;
V_39 = V_34 / ( div + 1 ) ;
V_38 = V_37 / ( V_40 + 1 ) ;
if ( abs ( ( long ) V_38 - ( long ) V_33 ) <
abs ( ( long ) V_39 - ( long ) V_33 ) ) {
F_15 ( V_2 -> V_6 -> V_7 -> V_7 ,
L_2 , V_2 -> V_43 ) ;
if ( V_5 -> V_41 -> V_42 & ( 1 << V_2 -> V_43 ) ) {
T_1 V_44 = V_45 | V_46
| F_20 ( V_18 . V_23 )
| F_21 ( V_18 . V_25 ) | F_22 ( V_18 . V_24 )
| V_47 ;
if ( V_2 -> V_43 == 1 )
V_44 |= V_48
| V_49 ;
else
V_44 |= V_50
| V_51 ;
F_23 ( V_2 -> V_6 , V_52 ,
V_44 ) ;
V_35 = V_53 | 1 ;
} else {
V_35 = V_53 | V_40 ;
}
}
}
F_23 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_54 : V_55 ,
V_35 ) ;
F_23 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_56 : V_57 , 0 ) ;
V_12 = ( ( V_29 -> V_58 & V_59 ) ? V_60 : 0 )
| ( ( V_29 -> V_58 & V_61 ) ? V_62 : 0 )
| V_63 | V_64 ;
F_3 ( V_2 , V_65 , V_12 ) ;
F_3 ( V_2 , V_66 , V_29 -> V_67 - V_29 -> V_68 - 19 ) ;
F_3 ( V_2 , V_69 , V_29 -> V_67 - V_29 -> V_68 +
V_29 -> V_70 - 19 ) ;
F_3 ( V_2 , V_71 , V_29 -> V_72 -
V_29 -> V_68 - 1 ) ;
F_3 ( V_2 , V_73 , V_29 -> V_67 - 1 ) ;
F_3 ( V_2 , V_74 , V_29 -> V_75 -
V_29 -> V_76 - 2 ) ;
F_3 ( V_2 , V_77 , V_29 -> V_75 -
V_29 -> V_76 +
V_29 -> V_78 - 2 ) ;
F_3 ( V_2 , V_79 , V_29 -> V_75 -
V_29 -> V_76 +
V_29 -> V_80 - 1 ) ;
F_3 ( V_2 , V_81 , V_29 -> V_75 - 1 ) ;
F_3 ( V_2 , V_82 , V_29 -> V_67 - V_29 -> V_68 - 1 ) ;
F_3 ( V_2 , V_83 , V_29 -> V_70 ) ;
}
void F_24 ( struct V_84 * V_30 ,
enum V_85 V_26 )
{
struct V_1 * V_2 = F_25 ( V_30 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
V_2 -> V_86 |= F_26 ( V_26 ) ;
if ( V_26 == V_87 )
V_5 -> V_88 = V_2 -> V_43 ;
}
static unsigned int F_27 ( struct V_89 * V_90 )
{
return V_90 -> V_90 . V_31 -> V_91 ;
}
static const struct V_92 *
F_28 ( struct V_89 * V_90 )
{
return F_29 ( V_90 -> V_90 . V_31 ) -> V_93 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_89 * V_94 [ V_95 ] ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
unsigned int V_96 = 0 ;
unsigned int V_97 ;
unsigned int V_98 = 0 ;
unsigned int V_99 = 0 ;
unsigned int V_100 ;
T_1 V_101 = 0 ;
for ( V_100 = 0 ; V_100 < V_2 -> V_6 -> V_96 ; ++ V_100 ) {
struct V_89 * V_90 = & V_2 -> V_6 -> V_94 [ V_100 ] ;
unsigned int V_102 ;
if ( V_90 -> V_90 . V_31 -> V_30 != & V_2 -> V_30 )
continue;
for ( V_102 = V_96 ++ ; V_102 > 0 ; -- V_102 ) {
if ( F_27 ( V_94 [ V_102 - 1 ] ) <= F_27 ( V_90 ) )
break;
V_94 [ V_102 ] = V_94 [ V_102 - 1 ] ;
}
V_94 [ V_102 ] = V_90 ;
V_99 += F_28 ( V_90 ) -> V_94 * 4 ;
}
for ( V_100 = 0 ; V_100 < V_96 ; ++ V_100 ) {
struct V_89 * V_90 = V_94 [ V_100 ] ;
struct V_103 * V_31 = V_90 -> V_90 . V_31 ;
unsigned int V_43 = F_29 ( V_31 ) -> V_104 ;
V_99 -= 4 ;
V_101 |= ( V_43 + 1 ) << V_99 ;
V_98 |= 1 << V_43 ;
if ( F_28 ( V_90 ) -> V_94 == 2 ) {
V_43 = ( V_43 + 1 ) % 8 ;
V_99 -= 4 ;
V_101 |= ( V_43 + 1 ) << V_99 ;
V_98 |= 1 << V_43 ;
}
}
if ( F_31 ( V_5 , V_105 ) ) {
if ( V_5 -> V_41 -> V_106 < 3 ) {
V_101 = ( V_2 -> V_43 % 2 ) + 1 ;
V_98 = 1 << ( V_2 -> V_43 % 2 ) ;
} else {
V_101 = ( V_2 -> V_43 % 2 ) ? 3 : 1 ;
V_98 = 1 << ( ( V_2 -> V_43 % 2 ) ? 2 : 0 ) ;
}
}
F_32 ( & V_2 -> V_6 -> V_107 ) ;
V_97 = V_2 -> V_43 % 2 ? V_2 -> V_6 -> V_97 | V_98
: V_2 -> V_6 -> V_97 & ~ V_98 ;
if ( V_97 != V_2 -> V_6 -> V_97 ) {
F_23 ( V_2 -> V_6 , V_108 ,
( V_97 << 16 ) | V_97 ) ;
V_2 -> V_6 -> V_97 = V_97 ;
if ( V_2 -> V_6 -> V_109 )
F_33 ( V_2 -> V_6 ) ;
}
if ( V_2 -> V_6 -> V_110 )
F_33 ( V_2 -> V_6 ) ;
F_34 ( & V_2 -> V_6 -> V_107 ) ;
F_23 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_111 : V_112 ,
V_101 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
struct V_113 * V_114 ;
struct V_115 * V_7 = V_2 -> V_30 . V_7 ;
unsigned long V_58 ;
F_36 ( & V_7 -> V_116 , V_58 ) ;
V_114 = V_2 -> V_114 ;
V_2 -> V_114 = NULL ;
F_37 ( & V_7 -> V_116 , V_58 ) ;
if ( V_114 == NULL )
return;
F_36 ( & V_7 -> V_116 , V_58 ) ;
F_38 ( & V_2 -> V_30 , V_114 ) ;
F_39 ( & V_2 -> V_117 ) ;
F_37 ( & V_7 -> V_116 , V_58 ) ;
F_40 ( & V_2 -> V_30 ) ;
}
static bool F_41 ( struct V_1 * V_2 )
{
struct V_115 * V_7 = V_2 -> V_30 . V_7 ;
unsigned long V_58 ;
bool V_118 ;
F_36 ( & V_7 -> V_116 , V_58 ) ;
V_118 = V_2 -> V_114 != NULL ;
F_37 ( & V_7 -> V_116 , V_58 ) ;
return V_118 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_43 ( V_2 -> V_117 ,
! F_41 ( V_2 ) ,
F_44 ( 50 ) ) )
return;
F_45 ( V_5 -> V_7 , L_3 ) ;
F_35 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_84 * V_30 = & V_2 -> V_30 ;
bool V_119 ;
if ( V_2 -> V_120 )
return;
F_3 ( V_2 , V_121 , F_47 ( 0 , 0 , 0 ) ) ;
F_3 ( V_2 , V_122 , F_48 ( 0 , 0 , 0 ) ) ;
F_16 ( V_2 ) ;
F_49 ( V_2 -> V_6 ) ;
F_23 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_111 : V_112 , 0 ) ;
V_119 = V_2 -> V_30 . V_29 . V_58 & V_123 ;
F_7 ( V_2 , V_124 , V_125 | V_126 ,
( V_119 ? V_127 : 0 ) |
V_128 ) ;
F_50 ( V_2 -> V_6 , true ) ;
if ( F_31 ( V_2 -> V_6 -> V_7 , V_105 ) )
F_51 ( V_2 ) ;
F_52 ( V_30 ) ;
V_2 -> V_120 = true ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_84 * V_30 = & V_2 -> V_30 ;
if ( ! V_2 -> V_120 )
return;
F_23 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_111 : V_112 , 0 ) ;
F_54 ( V_30 ) ;
F_42 ( V_2 ) ;
F_55 ( V_30 ) ;
if ( F_31 ( V_2 -> V_6 -> V_7 , V_105 ) )
F_56 ( V_2 ) ;
F_7 ( V_2 , V_124 , V_125 , V_129 ) ;
F_50 ( V_2 -> V_6 , false ) ;
V_2 -> V_120 = false ;
}
void F_57 ( struct V_1 * V_2 )
{
if ( F_31 ( V_2 -> V_6 -> V_7 , V_105 ) )
F_56 ( V_2 ) ;
F_53 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
unsigned int V_100 ;
if ( ! V_2 -> V_30 . V_31 -> V_130 )
return;
F_8 ( V_2 ) ;
F_46 ( V_2 ) ;
if ( F_31 ( V_2 -> V_6 -> V_7 , V_105 ) ) {
F_51 ( V_2 ) ;
} else {
for ( V_100 = 0 ; V_100 < V_2 -> V_6 -> V_96 ; ++ V_100 ) {
struct V_89 * V_90 = & V_2 -> V_6 -> V_94 [ V_100 ] ;
if ( V_90 -> V_90 . V_31 -> V_30 != & V_2 -> V_30 )
continue;
F_59 ( V_90 ) ;
}
}
F_30 ( V_2 ) ;
}
static void F_60 ( struct V_84 * V_30 )
{
struct V_1 * V_2 = F_25 ( V_30 ) ;
F_8 ( V_2 ) ;
F_46 ( V_2 ) ;
}
static void F_61 ( struct V_84 * V_30 )
{
struct V_1 * V_2 = F_25 ( V_30 ) ;
F_53 ( V_2 ) ;
F_12 ( V_2 ) ;
F_62 ( & V_30 -> V_7 -> V_116 ) ;
if ( V_30 -> V_31 -> V_114 ) {
F_38 ( V_30 , V_30 -> V_31 -> V_114 ) ;
V_30 -> V_31 -> V_114 = NULL ;
}
F_63 ( & V_30 -> V_7 -> V_116 ) ;
V_2 -> V_86 = 0 ;
}
static void F_64 ( struct V_84 * V_30 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_25 ( V_30 ) ;
if ( F_31 ( V_2 -> V_6 -> V_7 , V_105 ) )
F_65 ( V_2 ) ;
}
static void F_66 ( struct V_84 * V_30 ,
struct V_131 * V_132 )
{
struct V_1 * V_2 = F_25 ( V_30 ) ;
struct V_115 * V_7 = V_2 -> V_30 . V_7 ;
unsigned long V_58 ;
F_30 ( V_2 ) ;
if ( V_30 -> V_31 -> V_114 ) {
F_67 ( F_68 ( V_30 ) != 0 ) ;
F_36 ( & V_7 -> V_116 , V_58 ) ;
V_2 -> V_114 = V_30 -> V_31 -> V_114 ;
V_30 -> V_31 -> V_114 = NULL ;
F_37 ( & V_7 -> V_116 , V_58 ) ;
}
if ( F_31 ( V_2 -> V_6 -> V_7 , V_105 ) )
F_69 ( V_2 ) ;
}
static int F_70 ( struct V_84 * V_30 )
{
struct V_1 * V_2 = F_25 ( V_30 ) ;
F_3 ( V_2 , V_133 , V_134 ) ;
F_6 ( V_2 , V_135 , V_136 ) ;
return 0 ;
}
static void F_71 ( struct V_84 * V_30 )
{
struct V_1 * V_2 = F_25 ( V_30 ) ;
F_5 ( V_2 , V_135 , V_136 ) ;
}
static T_2 F_72 ( int V_137 , void * V_138 )
{
struct V_1 * V_2 = V_138 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_2 V_13 = V_139 ;
T_1 V_140 ;
V_140 = F_1 ( V_2 , V_141 ) ;
F_3 ( V_2 , V_133 , V_140 & V_142 ) ;
if ( V_140 & V_143 ) {
F_73 ( & V_2 -> V_30 ) ;
if ( V_5 -> V_41 -> V_106 < 3 )
F_35 ( V_2 ) ;
V_13 = V_144 ;
}
return V_13 ;
}
int F_74 ( struct V_145 * V_146 , unsigned int V_43 )
{
static const unsigned int V_147 [] = {
V_148 , V_149 , V_150 , V_151
} ;
struct V_4 * V_5 = V_146 -> V_7 ;
struct V_152 * V_153 = F_75 ( V_5 -> V_7 ) ;
struct V_1 * V_2 = & V_5 -> V_154 [ V_43 ] ;
struct V_84 * V_30 = & V_2 -> V_30 ;
struct V_155 * V_156 ;
unsigned int V_157 ;
struct V_34 * V_34 ;
char V_158 [ 9 ] ;
char * V_159 ;
int V_137 ;
int V_13 ;
if ( F_31 ( V_5 , V_160 ) ) {
sprintf ( V_158 , L_4 , V_43 ) ;
V_159 = V_158 ;
} else {
V_159 = NULL ;
}
V_2 -> clock = F_76 ( V_5 -> V_7 , V_159 ) ;
if ( F_77 ( V_2 -> clock ) ) {
F_78 ( V_5 -> V_7 , L_5 , V_43 ) ;
return F_79 ( V_2 -> clock ) ;
}
sprintf ( V_158 , L_6 , V_43 ) ;
V_34 = F_76 ( V_5 -> V_7 , V_158 ) ;
if ( ! F_77 ( V_34 ) ) {
V_2 -> V_14 = V_34 ;
} else if ( F_79 ( V_2 -> clock ) == - V_161 ) {
F_80 ( V_5 -> V_7 , L_7 , V_43 ) ;
return - V_161 ;
}
F_81 ( & V_2 -> V_117 ) ;
V_2 -> V_6 = V_146 ;
V_2 -> V_8 = V_147 [ V_43 ] ;
V_2 -> V_43 = V_43 ;
if ( F_31 ( V_5 , V_105 ) )
V_156 = & V_2 -> V_162 -> V_94 [ 0 ] . V_90 ;
else
V_156 = & V_146 -> V_94 [ V_43 % 2 ] . V_90 ;
V_13 = F_82 ( V_5 -> V_163 , V_30 , V_156 ,
NULL , & V_164 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
F_83 ( V_30 , & V_165 ) ;
F_55 ( V_30 ) ;
if ( F_31 ( V_5 , V_160 ) ) {
V_137 = F_84 ( V_153 , V_43 ) ;
V_157 = 0 ;
} else {
V_137 = F_84 ( V_153 , 0 ) ;
V_157 = V_166 ;
}
if ( V_137 < 0 ) {
F_78 ( V_5 -> V_7 , L_8 , V_43 ) ;
return V_137 ;
}
V_13 = F_85 ( V_5 -> V_7 , V_137 , F_72 , V_157 ,
F_86 ( V_5 -> V_7 ) , V_2 ) ;
if ( V_13 < 0 ) {
F_78 ( V_5 -> V_7 ,
L_9 , V_43 ) ;
return V_13 ;
}
return 0 ;
}
