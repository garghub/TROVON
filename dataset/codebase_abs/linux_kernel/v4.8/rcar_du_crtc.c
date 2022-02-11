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
static void F_14 ( struct V_1 * V_2 )
{
const struct V_17 * V_18 = & V_2 -> V_19 . V_20 -> V_21 ;
unsigned long V_22 = V_18 -> clock * 1000 ;
unsigned long V_23 ;
T_1 V_12 ;
T_1 V_24 ;
T_1 div ;
V_23 = F_15 ( V_2 -> clock ) ;
div = F_16 ( V_23 , V_22 ) ;
div = F_17 ( div , 1U , 64U ) - 1 ;
V_24 = div | V_25 ;
if ( V_2 -> V_14 ) {
unsigned long V_26 ;
unsigned long V_27 ;
unsigned long V_28 ;
T_1 V_29 ;
V_26 = F_15 ( V_2 -> V_14 ) ;
V_29 = F_16 ( V_26 , V_22 ) ;
V_29 = F_17 ( V_29 , 1U , 64U ) - 1 ;
V_28 = V_23 / ( div + 1 ) ;
V_27 = V_26 / ( V_29 + 1 ) ;
if ( abs ( ( long ) V_27 - ( long ) V_22 ) <
abs ( ( long ) V_28 - ( long ) V_22 ) ) {
F_18 ( V_2 -> V_6 -> V_7 -> V_7 ,
L_1 , V_2 -> V_30 ) ;
V_24 = V_29 | V_31 ;
}
}
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_32 : V_33 ,
V_24 ) ;
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_34 : V_35 , 0 ) ;
V_12 = ( ( V_18 -> V_36 & V_37 ) ? 0 : V_38 )
| ( ( V_18 -> V_36 & V_39 ) ? 0 : V_40 )
| V_41 | V_42 ;
F_3 ( V_2 , V_43 , V_12 ) ;
F_3 ( V_2 , V_44 , V_18 -> V_45 - V_18 -> V_46 - 19 ) ;
F_3 ( V_2 , V_47 , V_18 -> V_45 - V_18 -> V_46 +
V_18 -> V_48 - 19 ) ;
F_3 ( V_2 , V_49 , V_18 -> V_50 -
V_18 -> V_46 - 1 ) ;
F_3 ( V_2 , V_51 , V_18 -> V_45 - 1 ) ;
F_3 ( V_2 , V_52 , V_18 -> V_53 -
V_18 -> V_54 - 2 ) ;
F_3 ( V_2 , V_55 , V_18 -> V_53 -
V_18 -> V_54 +
V_18 -> V_56 - 2 ) ;
F_3 ( V_2 , V_57 , V_18 -> V_53 -
V_18 -> V_54 +
V_18 -> V_58 - 1 ) ;
F_3 ( V_2 , V_59 , V_18 -> V_53 - 1 ) ;
F_3 ( V_2 , V_60 , V_18 -> V_45 - V_18 -> V_46 ) ;
F_3 ( V_2 , V_61 , V_18 -> V_48 ) ;
}
void F_20 ( struct V_62 * V_19 ,
enum V_63 V_64 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
V_2 -> V_65 |= F_22 ( V_64 ) ;
if ( V_64 == V_66 )
V_5 -> V_67 = V_2 -> V_30 ;
}
static unsigned int F_23 ( struct V_68 * V_69 )
{
return V_69 -> V_69 . V_20 -> V_70 ;
}
static const struct V_71 *
F_24 ( struct V_68 * V_69 )
{
return F_25 ( V_69 -> V_69 . V_20 ) -> V_72 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_68 * V_73 [ V_74 ] ;
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
unsigned int V_75 = 0 ;
unsigned int V_76 ;
unsigned int V_77 = 0 ;
unsigned int V_78 = 0 ;
unsigned int V_79 ;
T_1 V_80 = 0 ;
for ( V_79 = 0 ; V_79 < V_2 -> V_6 -> V_75 ; ++ V_79 ) {
struct V_68 * V_69 = & V_2 -> V_6 -> V_73 [ V_79 ] ;
unsigned int V_81 ;
if ( V_69 -> V_69 . V_20 -> V_19 != & V_2 -> V_19 )
continue;
for ( V_81 = V_75 ++ ; V_81 > 0 ; -- V_81 ) {
if ( F_23 ( V_73 [ V_81 - 1 ] ) <= F_23 ( V_69 ) )
break;
V_73 [ V_81 ] = V_73 [ V_81 - 1 ] ;
}
V_73 [ V_81 ] = V_69 ;
V_78 += F_24 ( V_69 ) -> V_73 * 4 ;
}
for ( V_79 = 0 ; V_79 < V_75 ; ++ V_79 ) {
struct V_68 * V_69 = V_73 [ V_79 ] ;
struct V_82 * V_20 = V_69 -> V_69 . V_20 ;
unsigned int V_30 = F_25 ( V_20 ) -> V_83 ;
V_78 -= 4 ;
V_80 |= ( V_30 + 1 ) << V_78 ;
V_77 |= 1 << V_30 ;
if ( F_24 ( V_69 ) -> V_73 == 2 ) {
V_30 = ( V_30 + 1 ) % 8 ;
V_78 -= 4 ;
V_80 |= ( V_30 + 1 ) << V_78 ;
V_77 |= 1 << V_30 ;
}
}
if ( F_27 ( V_5 , V_84 ) ) {
if ( V_5 -> V_85 -> V_86 < 3 ) {
V_80 = ( V_2 -> V_30 % 2 ) + 1 ;
V_77 = 1 << ( V_2 -> V_30 % 2 ) ;
} else {
V_80 = ( V_2 -> V_30 % 2 ) ? 3 : 1 ;
V_77 = 1 << ( ( V_2 -> V_30 % 2 ) ? 2 : 0 ) ;
}
}
F_28 ( & V_2 -> V_6 -> V_87 ) ;
V_76 = V_2 -> V_30 % 2 ? V_2 -> V_6 -> V_76 | V_77
: V_2 -> V_6 -> V_76 & ~ V_77 ;
if ( V_76 != V_2 -> V_6 -> V_76 ) {
F_19 ( V_2 -> V_6 , V_88 ,
( V_76 << 16 ) | V_76 ) ;
V_2 -> V_6 -> V_76 = V_76 ;
if ( V_2 -> V_6 -> V_89 )
F_29 ( V_2 -> V_6 ) ;
}
if ( V_2 -> V_6 -> V_90 )
F_29 ( V_2 -> V_6 ) ;
F_30 ( & V_2 -> V_6 -> V_87 ) ;
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_91 : V_92 ,
V_80 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_93 * V_94 ;
struct V_95 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_36 ;
F_32 ( & V_7 -> V_96 , V_36 ) ;
V_94 = V_2 -> V_94 ;
V_2 -> V_94 = NULL ;
F_33 ( & V_7 -> V_96 , V_36 ) ;
if ( V_94 == NULL )
return;
F_32 ( & V_7 -> V_96 , V_36 ) ;
F_34 ( & V_2 -> V_19 , V_94 ) ;
F_35 ( & V_2 -> V_97 ) ;
F_33 ( & V_7 -> V_96 , V_36 ) ;
F_36 ( & V_2 -> V_19 ) ;
}
static bool F_37 ( struct V_1 * V_2 )
{
struct V_95 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_36 ;
bool V_98 ;
F_32 ( & V_7 -> V_96 , V_36 ) ;
V_98 = V_2 -> V_94 != NULL ;
F_33 ( & V_7 -> V_96 , V_36 ) ;
return V_98 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 ;
if ( F_39 ( V_2 -> V_97 ,
! F_37 ( V_2 ) ,
F_40 ( 50 ) ) )
return;
F_41 ( V_5 -> V_7 , L_2 ) ;
F_31 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_62 * V_19 = & V_2 -> V_19 ;
bool V_99 ;
if ( V_2 -> V_100 )
return;
F_3 ( V_2 , V_101 , F_43 ( 0 , 0 , 0 ) ) ;
F_3 ( V_2 , V_102 , F_44 ( 0 , 0 , 0 ) ) ;
F_14 ( V_2 ) ;
F_45 ( V_2 -> V_6 ) ;
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_91 : V_92 , 0 ) ;
V_99 = V_2 -> V_19 . V_18 . V_36 & V_103 ;
F_7 ( V_2 , V_104 , V_105 | V_106 ,
( V_99 ? V_107 : 0 ) |
V_108 ) ;
F_46 ( V_2 -> V_6 , true ) ;
if ( F_27 ( V_2 -> V_6 -> V_7 , V_84 ) )
F_47 ( V_2 ) ;
F_48 ( V_19 ) ;
V_2 -> V_100 = true ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_62 * V_19 = & V_2 -> V_19 ;
if ( ! V_2 -> V_100 )
return;
F_19 ( V_2 -> V_6 , V_2 -> V_30 % 2 ? V_91 : V_92 , 0 ) ;
F_50 ( V_19 ) ;
F_38 ( V_2 ) ;
F_51 ( V_19 ) ;
if ( F_27 ( V_2 -> V_6 -> V_7 , V_84 ) )
F_52 ( V_2 ) ;
F_7 ( V_2 , V_104 , V_105 , V_109 ) ;
F_46 ( V_2 -> V_6 , false ) ;
V_2 -> V_100 = false ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( F_27 ( V_2 -> V_6 -> V_7 , V_84 ) )
F_52 ( V_2 ) ;
F_49 ( V_2 ) ;
F_12 ( V_2 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
unsigned int V_79 ;
if ( ! V_2 -> V_19 . V_20 -> V_110 )
return;
F_8 ( V_2 ) ;
F_42 ( V_2 ) ;
if ( F_27 ( V_2 -> V_6 -> V_7 , V_84 ) ) {
F_47 ( V_2 ) ;
} else {
for ( V_79 = 0 ; V_79 < V_2 -> V_6 -> V_75 ; ++ V_79 ) {
struct V_68 * V_69 = & V_2 -> V_6 -> V_73 [ V_79 ] ;
if ( V_69 -> V_69 . V_20 -> V_19 != & V_2 -> V_19 )
continue;
F_55 ( V_69 ) ;
}
}
F_26 ( V_2 ) ;
}
static void F_56 ( struct V_62 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
F_8 ( V_2 ) ;
F_42 ( V_2 ) ;
}
static void F_57 ( struct V_62 * V_19 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
F_49 ( V_2 ) ;
F_12 ( V_2 ) ;
V_2 -> V_65 = 0 ;
}
static void F_58 ( struct V_62 * V_19 ,
struct V_111 * V_112 )
{
struct V_93 * V_94 = V_19 -> V_20 -> V_94 ;
struct V_1 * V_2 = F_21 ( V_19 ) ;
struct V_95 * V_7 = V_2 -> V_19 . V_7 ;
unsigned long V_36 ;
if ( V_94 ) {
F_59 ( F_60 ( V_19 ) != 0 ) ;
F_32 ( & V_7 -> V_96 , V_36 ) ;
V_2 -> V_94 = V_94 ;
F_33 ( & V_7 -> V_96 , V_36 ) ;
}
if ( F_27 ( V_2 -> V_6 -> V_7 , V_84 ) )
F_61 ( V_2 ) ;
}
static void F_62 ( struct V_62 * V_19 ,
struct V_111 * V_112 )
{
struct V_1 * V_2 = F_21 ( V_19 ) ;
F_26 ( V_2 ) ;
if ( F_27 ( V_2 -> V_6 -> V_7 , V_84 ) )
F_63 ( V_2 ) ;
}
static T_2 F_64 ( int V_113 , void * V_114 )
{
struct V_1 * V_2 = V_114 ;
T_2 V_13 = V_115 ;
T_1 V_116 ;
V_116 = F_1 ( V_2 , V_117 ) ;
F_3 ( V_2 , V_118 , V_116 & V_119 ) ;
if ( V_116 & V_120 ) {
F_65 ( & V_2 -> V_19 ) ;
F_31 ( V_2 ) ;
V_13 = V_121 ;
}
return V_13 ;
}
int F_66 ( struct V_122 * V_123 , unsigned int V_30 )
{
static const unsigned int V_124 [] = {
V_125 , V_126 , V_127 , V_128
} ;
struct V_4 * V_5 = V_123 -> V_7 ;
struct V_129 * V_130 = F_67 ( V_5 -> V_7 ) ;
struct V_1 * V_2 = & V_5 -> V_131 [ V_30 ] ;
struct V_62 * V_19 = & V_2 -> V_19 ;
struct V_132 * V_133 ;
unsigned int V_134 ;
struct V_23 * V_23 ;
char V_135 [ 9 ] ;
char * V_136 ;
int V_113 ;
int V_13 ;
if ( F_27 ( V_5 , V_137 ) ) {
sprintf ( V_135 , L_3 , V_30 ) ;
V_136 = V_135 ;
} else {
V_136 = NULL ;
}
V_2 -> clock = F_68 ( V_5 -> V_7 , V_136 ) ;
if ( F_69 ( V_2 -> clock ) ) {
F_70 ( V_5 -> V_7 , L_4 , V_30 ) ;
return F_71 ( V_2 -> clock ) ;
}
sprintf ( V_135 , L_5 , V_30 ) ;
V_23 = F_68 ( V_5 -> V_7 , V_135 ) ;
if ( ! F_69 ( V_23 ) ) {
V_2 -> V_14 = V_23 ;
} else if ( F_71 ( V_2 -> clock ) == - V_138 ) {
F_72 ( V_5 -> V_7 , L_6 , V_30 ) ;
return - V_138 ;
}
F_73 ( & V_2 -> V_97 ) ;
V_2 -> V_6 = V_123 ;
V_2 -> V_8 = V_124 [ V_30 ] ;
V_2 -> V_30 = V_30 ;
if ( F_27 ( V_5 , V_84 ) )
V_133 = & V_2 -> V_139 -> V_73 [ 0 ] . V_69 ;
else
V_133 = & V_123 -> V_73 [ V_30 % 2 ] . V_69 ;
V_13 = F_74 ( V_5 -> V_140 , V_19 , V_133 ,
NULL , & V_141 , NULL ) ;
if ( V_13 < 0 )
return V_13 ;
F_75 ( V_19 , & V_142 ) ;
F_51 ( V_19 ) ;
if ( F_27 ( V_5 , V_137 ) ) {
V_113 = F_76 ( V_130 , V_30 ) ;
V_134 = 0 ;
} else {
V_113 = F_76 ( V_130 , 0 ) ;
V_134 = V_143 ;
}
if ( V_113 < 0 ) {
F_70 ( V_5 -> V_7 , L_7 , V_30 ) ;
return V_113 ;
}
V_13 = F_77 ( V_5 -> V_7 , V_113 , F_64 , V_134 ,
F_78 ( V_5 -> V_7 ) , V_2 ) ;
if ( V_13 < 0 ) {
F_70 ( V_5 -> V_7 ,
L_8 , V_30 ) ;
return V_13 ;
}
return 0 ;
}
void F_79 ( struct V_1 * V_2 , bool V_144 )
{
if ( V_144 ) {
F_3 ( V_2 , V_118 , V_145 ) ;
F_6 ( V_2 , V_146 , V_147 ) ;
} else {
F_5 ( V_2 , V_146 , V_147 ) ;
}
}
