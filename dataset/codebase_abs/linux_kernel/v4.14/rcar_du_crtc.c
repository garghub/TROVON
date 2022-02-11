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
/ ( V_23 + 1 ) ;
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
unsigned long V_20 = V_33 ;
if ( F_20 ( V_44 ) )
V_20 *= 2 ;
F_14 ( V_2 , & V_18 , V_37 , V_20 ) ;
V_37 = V_18 . V_26 ;
}
V_40 = F_18 ( V_37 , V_33 ) ;
V_40 = F_19 ( V_40 , 1U , 64U ) - 1 ;
V_39 = V_34 / ( div + 1 ) ;
V_38 = V_37 / ( V_40 + 1 ) ;
if ( abs ( ( long ) V_38 - ( long ) V_33 ) <
abs ( ( long ) V_39 - ( long ) V_33 ) ) {
if ( V_5 -> V_41 -> V_42 & ( 1 << V_2 -> V_43 ) ) {
T_1 V_45 = V_46 | V_47
| F_21 ( V_18 . V_23 )
| F_22 ( V_18 . V_25 ) | F_23 ( V_18 . V_24 )
| V_48 ;
if ( V_2 -> V_43 == 1 )
V_45 |= V_49
| V_50 ;
else
V_45 |= V_51
| V_52 ;
F_24 ( V_2 -> V_6 , V_53 ,
V_45 ) ;
}
V_35 = V_54 | V_40 ;
}
F_15 ( V_2 -> V_6 -> V_7 -> V_7 ,
L_2 ,
V_33 , V_38 , V_39 , V_35 ) ;
}
F_24 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_55 : V_56 ,
V_35 ) ;
F_24 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_57 : V_58 , 0 ) ;
V_12 = ( ( V_29 -> V_59 & V_60 ) ? V_61 : 0 )
| ( ( V_29 -> V_59 & V_62 ) ? V_63 : 0 )
| V_64 | V_65 ;
F_3 ( V_2 , V_66 , V_12 ) ;
F_3 ( V_2 , V_67 , V_29 -> V_68 - V_29 -> V_69 - 19 ) ;
F_3 ( V_2 , V_70 , V_29 -> V_68 - V_29 -> V_69 +
V_29 -> V_71 - 19 ) ;
F_3 ( V_2 , V_72 , V_29 -> V_73 -
V_29 -> V_69 - 1 ) ;
F_3 ( V_2 , V_74 , V_29 -> V_68 - 1 ) ;
F_3 ( V_2 , V_75 , V_29 -> V_76 -
V_29 -> V_77 - 2 ) ;
F_3 ( V_2 , V_78 , V_29 -> V_76 -
V_29 -> V_77 +
V_29 -> V_79 - 2 ) ;
F_3 ( V_2 , V_80 , V_29 -> V_76 -
V_29 -> V_77 +
V_29 -> V_81 - 1 ) ;
F_3 ( V_2 , V_82 , V_29 -> V_76 - 1 ) ;
F_3 ( V_2 , V_83 , V_29 -> V_68 - V_29 -> V_69 - 1 ) ;
F_3 ( V_2 , V_84 , V_29 -> V_71 ) ;
}
void F_25 ( struct V_85 * V_30 ,
enum V_86 V_26 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
V_2 -> V_87 |= F_27 ( V_26 ) ;
if ( V_26 == V_88 )
V_5 -> V_89 = V_2 -> V_43 ;
}
static unsigned int F_28 ( struct V_90 * V_91 )
{
return V_91 -> V_91 . V_31 -> V_92 ;
}
static const struct V_93 *
F_29 ( struct V_90 * V_91 )
{
return F_30 ( V_91 -> V_91 . V_31 ) -> V_94 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_90 * V_95 [ V_96 ] ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
unsigned int V_97 = 0 ;
unsigned int V_98 ;
unsigned int V_99 = 0 ;
unsigned int V_100 = 0 ;
unsigned int V_101 ;
T_1 V_102 = 0 ;
for ( V_101 = 0 ; V_101 < V_2 -> V_6 -> V_97 ; ++ V_101 ) {
struct V_90 * V_91 = & V_2 -> V_6 -> V_95 [ V_101 ] ;
unsigned int V_103 ;
if ( V_91 -> V_91 . V_31 -> V_30 != & V_2 -> V_30 )
continue;
for ( V_103 = V_97 ++ ; V_103 > 0 ; -- V_103 ) {
if ( F_28 ( V_95 [ V_103 - 1 ] ) <= F_28 ( V_91 ) )
break;
V_95 [ V_103 ] = V_95 [ V_103 - 1 ] ;
}
V_95 [ V_103 ] = V_91 ;
V_100 += F_29 ( V_91 ) -> V_95 * 4 ;
}
for ( V_101 = 0 ; V_101 < V_97 ; ++ V_101 ) {
struct V_90 * V_91 = V_95 [ V_101 ] ;
struct V_104 * V_31 = V_91 -> V_91 . V_31 ;
unsigned int V_43 = F_30 ( V_31 ) -> V_105 ;
V_100 -= 4 ;
V_102 |= ( V_43 + 1 ) << V_100 ;
V_99 |= 1 << V_43 ;
if ( F_29 ( V_91 ) -> V_95 == 2 ) {
V_43 = ( V_43 + 1 ) % 8 ;
V_100 -= 4 ;
V_102 |= ( V_43 + 1 ) << V_100 ;
V_99 |= 1 << V_43 ;
}
}
if ( F_32 ( V_5 , V_106 ) ) {
if ( V_5 -> V_41 -> V_107 < 3 ) {
V_102 = ( V_2 -> V_43 % 2 ) + 1 ;
V_99 = 1 << ( V_2 -> V_43 % 2 ) ;
} else {
V_102 = ( V_2 -> V_43 % 2 ) ? 3 : 1 ;
V_99 = 1 << ( ( V_2 -> V_43 % 2 ) ? 2 : 0 ) ;
}
}
F_33 ( & V_2 -> V_6 -> V_108 ) ;
V_98 = V_2 -> V_43 % 2 ? V_2 -> V_6 -> V_98 | V_99
: V_2 -> V_6 -> V_98 & ~ V_99 ;
if ( V_98 != V_2 -> V_6 -> V_98 ) {
F_24 ( V_2 -> V_6 , V_109 ,
( V_98 << 16 ) | V_98 ) ;
V_2 -> V_6 -> V_98 = V_98 ;
if ( V_2 -> V_6 -> V_110 )
F_34 ( V_2 -> V_6 ) ;
}
if ( V_2 -> V_6 -> V_111 )
F_34 ( V_2 -> V_6 ) ;
F_35 ( & V_2 -> V_6 -> V_108 ) ;
F_24 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_112 : V_113 ,
V_102 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_114 * V_115 ;
struct V_116 * V_7 = V_2 -> V_30 . V_7 ;
unsigned long V_59 ;
F_37 ( & V_7 -> V_117 , V_59 ) ;
V_115 = V_2 -> V_115 ;
V_2 -> V_115 = NULL ;
F_38 ( & V_7 -> V_117 , V_59 ) ;
if ( V_115 == NULL )
return;
F_37 ( & V_7 -> V_117 , V_59 ) ;
F_39 ( & V_2 -> V_30 , V_115 ) ;
F_40 ( & V_2 -> V_118 ) ;
F_38 ( & V_7 -> V_117 , V_59 ) ;
F_41 ( & V_2 -> V_30 ) ;
}
static bool F_42 ( struct V_1 * V_2 )
{
struct V_116 * V_7 = V_2 -> V_30 . V_7 ;
unsigned long V_59 ;
bool V_119 ;
F_37 ( & V_7 -> V_117 , V_59 ) ;
V_119 = V_2 -> V_115 != NULL ;
F_38 ( & V_7 -> V_117 , V_59 ) ;
return V_119 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_44 ( V_2 -> V_118 ,
! F_42 ( V_2 ) ,
F_45 ( 50 ) ) )
return;
F_46 ( V_5 -> V_7 , L_3 ) ;
F_36 ( V_2 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_120 , F_48 ( 0 , 0 , 0 ) ) ;
F_3 ( V_2 , V_121 , F_49 ( 0 , 0 , 0 ) ) ;
F_16 ( V_2 ) ;
F_50 ( V_2 -> V_6 ) ;
F_24 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_112 : V_113 , 0 ) ;
if ( F_32 ( V_2 -> V_6 -> V_7 , V_106 ) )
F_51 ( V_2 ) ;
F_52 ( & V_2 -> V_30 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
bool V_122 ;
V_122 = V_2 -> V_30 . V_29 . V_59 & V_123 ;
F_7 ( V_2 , V_124 , V_125 | V_126 ,
( V_122 ? V_127 : 0 ) |
V_128 ) ;
F_54 ( V_2 -> V_6 , true ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_85 * V_30 = & V_2 -> V_30 ;
T_1 V_129 ;
F_56 ( V_30 ) ;
F_57 ( & V_2 -> V_130 ) ;
F_24 ( V_2 -> V_6 , V_2 -> V_43 % 2 ? V_112 : V_113 , 0 ) ;
V_129 = F_1 ( V_2 , V_131 ) ;
V_2 -> V_132 = V_129 & V_133 ? 2 : 1 ;
F_58 ( & V_2 -> V_130 ) ;
if ( ! F_44 ( V_2 -> V_134 , V_2 -> V_132 == 0 ,
F_45 ( 100 ) ) )
F_46 ( V_5 -> V_7 , L_4 ) ;
F_41 ( V_30 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_85 * V_30 = & V_2 -> V_30 ;
F_55 ( V_2 ) ;
F_43 ( V_2 ) ;
F_60 ( V_30 ) ;
if ( F_32 ( V_2 -> V_6 -> V_7 , V_106 ) )
F_61 ( V_2 ) ;
F_7 ( V_2 , V_124 , V_125 , V_135 ) ;
F_54 ( V_2 -> V_6 , false ) ;
}
void F_62 ( struct V_1 * V_2 )
{
if ( F_32 ( V_2 -> V_6 -> V_7 , V_106 ) )
F_61 ( V_2 ) ;
F_59 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
unsigned int V_101 ;
if ( ! V_2 -> V_30 . V_31 -> V_136 )
return;
F_8 ( V_2 ) ;
F_47 ( V_2 ) ;
if ( ! F_32 ( V_2 -> V_6 -> V_7 , V_106 ) ) {
for ( V_101 = 0 ; V_101 < V_2 -> V_6 -> V_97 ; ++ V_101 ) {
struct V_90 * V_91 = & V_2 -> V_6 -> V_95 [ V_101 ] ;
if ( V_91 -> V_91 . V_31 -> V_30 != & V_2 -> V_30 )
continue;
F_64 ( V_91 ) ;
}
}
F_31 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static void F_65 ( struct V_85 * V_30 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
if ( ! V_2 -> V_139 ) {
F_8 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_139 = true ;
}
F_53 ( V_2 ) ;
}
static void F_66 ( struct V_85 * V_30 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
F_59 ( V_2 ) ;
F_12 ( V_2 ) ;
F_57 ( & V_30 -> V_7 -> V_117 ) ;
if ( V_30 -> V_31 -> V_115 ) {
F_39 ( V_30 , V_30 -> V_31 -> V_115 ) ;
V_30 -> V_31 -> V_115 = NULL ;
}
F_58 ( & V_30 -> V_7 -> V_117 ) ;
V_2 -> V_139 = false ;
V_2 -> V_87 = 0 ;
}
static void F_67 ( struct V_85 * V_30 ,
struct V_137 * V_140 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
F_68 ( ! V_30 -> V_31 -> V_141 ) ;
if ( ! V_2 -> V_139 ) {
F_8 ( V_2 ) ;
F_47 ( V_2 ) ;
V_2 -> V_139 = true ;
}
if ( F_32 ( V_2 -> V_6 -> V_7 , V_106 ) )
F_69 ( V_2 ) ;
}
static void F_70 ( struct V_85 * V_30 ,
struct V_137 * V_140 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
struct V_116 * V_7 = V_2 -> V_30 . V_7 ;
unsigned long V_59 ;
F_31 ( V_2 ) ;
if ( V_30 -> V_31 -> V_115 ) {
F_68 ( F_56 ( V_30 ) != 0 ) ;
F_37 ( & V_7 -> V_117 , V_59 ) ;
V_2 -> V_115 = V_30 -> V_31 -> V_115 ;
V_30 -> V_31 -> V_115 = NULL ;
F_38 ( & V_7 -> V_117 , V_59 ) ;
}
if ( F_32 ( V_2 -> V_6 -> V_7 , V_106 ) )
F_71 ( V_2 ) ;
}
static int F_72 ( struct V_85 * V_30 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
F_3 ( V_2 , V_142 , V_143 ) ;
F_6 ( V_2 , V_144 , V_145 ) ;
V_2 -> V_146 = true ;
return 0 ;
}
static void F_73 ( struct V_85 * V_30 )
{
struct V_1 * V_2 = F_26 ( V_30 ) ;
F_5 ( V_2 , V_144 , V_145 ) ;
V_2 -> V_146 = false ;
}
static T_2 F_74 ( int V_147 , void * V_148 )
{
struct V_1 * V_2 = V_148 ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
T_2 V_13 = V_149 ;
T_1 V_129 ;
F_75 ( & V_2 -> V_130 ) ;
V_129 = F_1 ( V_2 , V_131 ) ;
F_3 ( V_2 , V_142 , V_129 & V_150 ) ;
if ( V_129 & V_133 ) {
if ( V_2 -> V_132 ) {
if ( -- V_2 -> V_132 == 0 )
F_40 ( & V_2 -> V_134 ) ;
}
}
F_76 ( & V_2 -> V_130 ) ;
if ( V_129 & V_133 ) {
if ( V_5 -> V_41 -> V_107 < 3 ) {
F_77 ( & V_2 -> V_30 ) ;
F_36 ( V_2 ) ;
}
V_13 = V_151 ;
}
return V_13 ;
}
int F_78 ( struct V_152 * V_153 , unsigned int V_43 )
{
static const unsigned int V_154 [] = {
V_155 , V_156 , V_157 , V_158
} ;
struct V_4 * V_5 = V_153 -> V_7 ;
struct V_159 * V_160 = F_79 ( V_5 -> V_7 ) ;
struct V_1 * V_2 = & V_5 -> V_161 [ V_43 ] ;
struct V_85 * V_30 = & V_2 -> V_30 ;
struct V_162 * V_163 ;
unsigned int V_164 ;
struct V_34 * V_34 ;
char V_165 [ 9 ] ;
char * V_166 ;
int V_147 ;
int V_13 ;
if ( F_32 ( V_5 , V_167 ) ) {
sprintf ( V_165 , L_5 , V_43 ) ;
V_166 = V_165 ;
} else {
V_166 = NULL ;
}
V_2 -> clock = F_80 ( V_5 -> V_7 , V_166 ) ;
if ( F_81 ( V_2 -> clock ) ) {
F_82 ( V_5 -> V_7 , L_6 , V_43 ) ;
return F_83 ( V_2 -> clock ) ;
}
sprintf ( V_165 , L_7 , V_43 ) ;
V_34 = F_80 ( V_5 -> V_7 , V_165 ) ;
if ( ! F_81 ( V_34 ) ) {
V_2 -> V_14 = V_34 ;
} else if ( F_83 ( V_2 -> clock ) == - V_168 ) {
F_84 ( V_5 -> V_7 , L_8 , V_43 ) ;
return - V_168 ;
}
F_85 ( & V_2 -> V_118 ) ;
F_85 ( & V_2 -> V_134 ) ;
F_86 ( & V_2 -> V_130 ) ;
V_2 -> V_6 = V_153 ;
V_2 -> V_8 = V_154 [ V_43 ] ;
V_2 -> V_43 = V_43 ;
if ( F_32 ( V_5 , V_106 ) )
V_163 = & V_2 -> V_169 -> V_95 [ V_2 -> V_170 ] . V_91 ;
else
V_163 = & V_153 -> V_95 [ V_43 % 2 ] . V_91 ;
V_13 = F_87 ( V_5 -> V_171 , V_30 , V_163 ,
NULL , & V_172 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
F_88 ( V_30 , & V_173 ) ;
F_60 ( V_30 ) ;
if ( F_32 ( V_5 , V_167 ) ) {
V_147 = F_89 ( V_160 , V_43 ) ;
V_164 = 0 ;
} else {
V_147 = F_89 ( V_160 , 0 ) ;
V_164 = V_174 ;
}
if ( V_147 < 0 ) {
F_82 ( V_5 -> V_7 , L_9 , V_43 ) ;
return V_147 ;
}
V_13 = F_90 ( V_5 -> V_7 , V_147 , F_74 , V_164 ,
F_91 ( V_5 -> V_7 ) , V_2 ) ;
if ( V_13 < 0 ) {
F_82 ( V_5 -> V_7 ,
L_10 , V_43 ) ;
return V_13 ;
}
return 0 ;
}
