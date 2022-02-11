static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
if ( V_4 -> V_6 )
return - V_7 ;
if ( F_2 ( 0 , & V_4 -> V_8 ) ) {
V_5 = V_9 ;
if ( V_4 -> V_10 )
V_5 |= V_11 ;
else
V_5 |= V_12 ;
F_3 ( V_5 , V_4 -> V_13 + V_14 ) ;
}
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_6 )
return;
if ( F_5 ( 0 , & V_4 -> V_8 ) )
F_3 ( 0 , V_4 -> V_13 + V_14 ) ;
}
static void F_6 ( struct V_3 * V_4 )
{
T_1 V_5 = V_15 | V_16 |
V_17 | V_18 ;
F_3 ( V_5 , V_4 -> V_13 + V_19 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_20 * V_21 = & V_2 -> V_22 . V_21 ;
T_1 V_5 ;
if ( V_4 -> V_6 )
return;
V_5 = V_23 | V_24 ;
F_3 ( V_5 , V_4 -> V_13 + V_25 ) ;
V_5 = V_26 ;
if ( V_4 -> V_10 )
V_5 |= V_27 ;
else
V_5 |= V_28 ;
F_3 ( V_5 , V_4 -> V_13 + V_29 ) ;
V_5 = F_8 ( V_21 -> V_30 - 1 ) |
F_9 ( V_21 -> V_31 - 1 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_32 ) ;
if ( ! V_4 -> V_10 ) {
V_5 = F_10 (
V_21 -> V_33 - V_21 -> V_34 ) |
F_11 (
V_21 -> V_35 - V_21 -> V_36 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_37 ) ;
V_5 = F_12 (
V_21 -> V_34 - V_21 -> V_35 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_38 ) ;
V_5 = F_13 (
V_21 -> V_39 - V_21 -> V_40 ) |
F_14 (
V_21 -> V_41 - V_21 -> V_42 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_43 ) ;
V_5 = F_15 (
V_21 -> V_40 - V_21 -> V_41 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_44 ) ;
}
F_6 ( V_4 ) ;
V_5 = V_45 | V_46 ;
F_3 ( V_5 , V_4 -> V_13 + V_47 ) ;
}
static void F_16 ( struct V_3 * V_4 , unsigned int V_48 ,
struct V_49 * V_50 )
{
unsigned long V_5 ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 &= ~ V_51 ;
switch ( V_50 -> V_52 ) {
case V_53 :
V_5 |= V_54 ;
V_5 |= V_55 ;
V_5 |= V_56 ;
break;
case V_57 :
V_5 |= V_58 ;
V_5 |= V_55 ;
V_5 |= V_56 ;
break;
case V_59 :
V_5 |= V_60 ;
V_5 |= V_61 ;
V_5 |= V_56 ;
break;
case V_62 :
V_5 |= V_63 ;
V_5 |= V_61 | V_64 | V_65 ;
V_5 |= V_56 ;
break;
default:
F_19 ( L_1 ) ;
return;
}
F_20 ( L_2 , V_50 -> V_66 ) ;
if ( V_50 -> V_67 < V_68 ) {
V_5 &= ~ V_69 ;
V_5 |= V_70 ;
}
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
}
static void F_21 ( struct V_3 * V_4 , int V_48 ,
bool V_71 )
{
T_1 V_5 ;
V_5 = F_17 ( V_4 -> V_13 + V_72 ) ;
if ( V_71 )
V_5 |= F_22 ( V_48 ) ;
else
V_5 &= ~ F_22 ( V_48 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_72 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_6 )
return;
F_21 ( V_4 , V_74 -> V_75 , true ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_76 * V_77 = V_74 -> V_22 . V_77 ;
unsigned int V_48 = V_74 -> V_75 ;
unsigned int V_78 = V_77 -> V_50 -> V_66 >> 3 ;
unsigned int V_79 = V_77 -> V_50 -> V_80 [ 0 ] ;
T_1 V_5 ;
if ( V_4 -> V_6 )
return;
V_5 = F_25 ( V_74 -> V_81 ) | F_26 ( V_74 -> V_82 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_27 ( V_48 ) ) ;
V_5 = F_25 ( V_74 -> V_81 + V_74 -> V_83 - 1 ) |
F_26 ( V_74 -> V_82 + V_74 -> V_84 - 1 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_28 ( V_48 ) ) ;
V_5 = F_29 ( 0x0 ) | F_30 ( 0x0 ) |
F_31 ( 0x0 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_32 ( V_48 ) ) ;
V_5 = F_29 ( 0x0 ) | F_30 ( 0x0 ) |
F_31 ( 0x0 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_33 ( V_48 ) ) ;
F_3 ( V_74 -> V_85 [ 0 ] , V_4 -> V_13 + F_34 ( V_48 ) ) ;
V_5 = V_74 -> V_85 [ 0 ] + V_79 * V_74 -> V_84 ;
F_3 ( V_5 , V_4 -> V_13 + F_35 ( V_48 ) ) ;
V_5 = F_36 ( V_79 - V_74 -> V_83 * V_78 )
| F_37 ( V_74 -> V_83 * V_78 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_38 ( V_48 ) ) ;
F_16 ( V_4 , V_48 , V_77 -> V_50 ) ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 |= V_86 ;
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 = F_17 ( V_4 -> V_13 + V_87 ) ;
V_5 |= V_88 ;
F_3 ( V_5 , V_4 -> V_13 + V_87 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_48 = V_74 -> V_75 ;
T_1 V_5 ;
if ( V_4 -> V_6 )
return;
F_21 ( V_4 , V_48 , true ) ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 &= ~ V_86 ;
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
F_21 ( V_4 , V_48 , false ) ;
V_5 = F_17 ( V_4 -> V_13 + V_87 ) ;
V_5 |= V_88 ;
F_3 ( V_5 , V_4 -> V_13 + V_87 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_73 * V_74 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_6 )
return;
F_21 ( V_4 , V_74 -> V_75 , false ) ;
if ( V_4 -> V_10 )
F_41 ( & V_4 -> V_89 , 1 ) ;
}
static void F_42 ( struct V_3 * V_4 )
{
unsigned int V_90 ;
F_3 ( 0 , V_4 -> V_13 + V_47 ) ;
for ( V_90 = 2000 ; V_90 ; -- V_90 ) {
if ( ~ F_17 ( V_4 -> V_13 + V_47 ) & V_91 )
break;
F_43 ( 10 ) ;
}
F_44 ( V_90 == 0 , L_3 ) ;
F_3 ( V_92 , V_4 -> V_13 + V_47 ) ;
for ( V_90 = 2000 ; V_90 ; -- V_90 ) {
if ( ~ F_17 ( V_4 -> V_13 + V_47 ) & V_92 )
break;
F_43 ( 10 ) ;
}
F_44 ( V_90 == 0 , L_4 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_93 ;
int V_94 ;
if ( ! V_4 -> V_6 )
return;
V_4 -> V_6 = false ;
F_46 ( V_4 -> V_95 ) ;
for ( V_94 = 0 ; V_94 < F_47 ( V_96 ) ; V_94 ++ ) {
V_93 = F_48 ( V_4 -> V_97 [ V_94 ] ) ;
if ( V_93 < 0 )
goto V_98;
}
F_49 ( V_99 , & V_4 -> V_100 ) ;
if ( F_5 ( 0 , & V_4 -> V_8 ) )
F_1 ( V_4 -> V_2 ) ;
F_7 ( V_4 -> V_2 ) ;
return;
V_98:
while ( -- V_94 >= 0 )
F_50 ( V_4 -> V_97 [ V_94 ] ) ;
V_4 -> V_6 = true ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_94 ;
if ( V_4 -> V_6 )
return;
for ( V_94 = 0 ; V_94 < V_101 ; V_94 ++ )
F_39 ( V_2 , & V_4 -> V_102 [ V_94 ] ) ;
F_42 ( V_4 ) ;
for ( V_94 = 0 ; V_94 < F_47 ( V_96 ) ; V_94 ++ )
F_50 ( V_4 -> V_97 [ V_94 ] ) ;
F_52 ( V_99 , & V_4 -> V_100 ) ;
F_53 ( V_4 -> V_95 ) ;
V_4 -> V_6 = true ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
if ( ! F_55 ( V_99 , & V_4 -> V_100 ) )
return;
if ( F_56 ( & V_4 -> V_89 , - 1 , 0 ) ) {
V_5 = F_17 ( V_4 -> V_13 + V_19 ) ;
V_5 |= V_103 ;
F_3 ( V_5 , V_4 -> V_13 + V_19 ) ;
}
F_57 ( & V_4 -> V_2 -> V_22 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_48 , V_94 , V_93 ;
T_1 V_5 ;
F_20 ( L_5 , __FILE__ ) ;
for ( V_94 = 0 ; V_94 < F_47 ( V_96 ) ; V_94 ++ ) {
V_93 = F_48 ( V_4 -> V_97 [ V_94 ] ) ;
if ( V_93 < 0 )
goto V_98;
}
for ( V_48 = 0 ; V_48 < V_101 ; V_48 ++ ) {
V_5 = F_17 ( V_4 -> V_13 + V_72 ) ;
V_5 |= F_22 ( V_48 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_72 ) ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 &= ~ V_86 ;
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 = F_17 ( V_4 -> V_13 + V_72 ) ;
V_5 &= ~ F_22 ( V_48 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_72 ) ;
V_5 = F_17 ( V_4 -> V_13 + V_87 ) ;
V_5 |= V_88 ;
F_3 ( V_5 , V_4 -> V_13 + V_87 ) ;
}
F_59 ( 50 ) ;
V_98:
while ( -- V_94 >= 0 )
F_50 ( V_4 -> V_97 [ V_94 ] ) ;
}
static int F_60 ( struct V_104 * V_95 , struct V_104 * V_105 , void * V_106 )
{
struct V_3 * V_4 = F_61 ( V_95 ) ;
struct V_107 * V_108 = V_106 ;
struct V_109 * V_110 = V_108 -> V_111 ;
struct V_73 * V_112 ;
enum V_113 type ;
unsigned int V_75 ;
int V_93 ;
V_4 -> V_108 = V_108 ;
V_4 -> V_114 = V_110 -> V_114 ++ ;
for ( V_75 = 0 ; V_75 < V_101 ; V_75 ++ ) {
type = ( V_75 == V_4 -> V_115 ) ? V_116 :
V_117 ;
V_93 = F_62 ( V_108 , & V_4 -> V_102 [ V_75 ] ,
1 << V_4 -> V_114 , type , V_118 ,
F_47 ( V_118 ) , V_75 ) ;
if ( V_93 )
return V_93 ;
}
V_112 = & V_4 -> V_102 [ V_4 -> V_115 ] ;
V_4 -> V_2 = F_63 ( V_108 , & V_112 -> V_22 ,
V_4 -> V_114 , V_119 ,
& V_120 , V_4 ) ;
if ( F_64 ( V_4 -> V_2 ) ) {
V_93 = F_65 ( V_4 -> V_2 ) ;
goto V_98;
}
F_58 ( V_4 -> V_2 ) ;
V_93 = F_66 ( V_108 , V_95 ) ;
if ( V_93 )
goto V_98;
return V_93 ;
V_98:
V_110 -> V_114 -- ;
return V_93 ;
}
static void F_67 ( struct V_104 * V_95 , struct V_104 * V_105 , void * V_106 )
{
struct V_3 * V_4 = F_61 ( V_95 ) ;
F_51 ( V_4 -> V_2 ) ;
F_68 ( V_4 -> V_108 , V_4 -> V_95 ) ;
}
static T_2 F_69 ( int V_121 , void * V_122 )
{
struct V_3 * V_4 = V_122 ;
T_1 V_5 ;
if ( ! F_55 ( V_99 , & V_4 -> V_100 ) )
goto V_123;
V_5 = F_17 ( V_4 -> V_13 + V_124 ) ;
if ( V_5 & V_125 ) {
F_57 ( & V_4 -> V_2 -> V_22 ) ;
F_3 ( V_125 , V_4 -> V_13 + V_124 ) ;
}
V_123:
return V_126 ;
}
static T_2 F_70 ( int V_121 , void * V_122 )
{
struct V_3 * V_4 = V_122 ;
T_1 V_5 ;
int V_48 ;
if ( ! F_55 ( V_99 , & V_4 -> V_100 ) )
goto V_123;
V_5 = F_17 ( V_4 -> V_13 + V_124 ) ;
if ( V_5 & V_127 ) {
for ( V_48 = 0 ; V_48 < V_101 ; V_48 ++ ) {
struct V_73 * V_74 = & V_4 -> V_102 [ V_48 ] ;
if ( ! V_74 -> V_128 )
continue;
F_71 ( V_4 -> V_2 , V_74 ) ;
}
F_3 ( V_127 ,
V_4 -> V_13 + V_124 ) ;
}
V_123:
return V_126 ;
}
static int F_72 ( struct V_129 * V_130 )
{
struct V_104 * V_95 = & V_130 -> V_95 ;
struct V_3 * V_4 ;
struct V_131 * V_132 ;
int V_93 ;
int V_94 ;
V_4 = F_73 ( V_95 , sizeof( * V_4 ) , V_133 ) ;
if ( ! V_4 )
return - V_134 ;
V_4 -> V_115 = 0 ;
V_4 -> V_6 = true ;
V_4 -> V_95 = V_95 ;
if ( F_74 ( V_95 -> V_135 , L_6 ) )
V_4 -> V_10 = true ;
for ( V_94 = 0 ; V_94 < F_47 ( V_96 ) ; V_94 ++ ) {
struct V_136 * V_136 ;
V_136 = F_75 ( V_4 -> V_95 , V_96 [ V_94 ] ) ;
if ( F_64 ( V_136 ) )
return F_65 ( V_136 ) ;
V_4 -> V_97 [ V_94 ] = V_136 ;
}
V_132 = F_76 ( V_130 , V_137 , 0 ) ;
if ( ! V_132 ) {
F_77 ( V_95 , L_7 ) ;
return - V_138 ;
}
V_4 -> V_13 = F_78 ( V_95 , V_132 ) ;
if ( F_64 ( V_4 -> V_13 ) ) {
F_77 ( V_95 , L_8 ) ;
return F_65 ( V_4 -> V_13 ) ;
}
V_132 = F_79 ( V_130 , V_139 ,
V_4 -> V_10 ? L_9 : L_10 ) ;
if ( ! V_132 ) {
F_77 ( V_95 , L_11 ) ;
return - V_138 ;
}
V_93 = F_80 ( V_95 , V_132 -> V_140 , V_4 -> V_10 ?
F_70 : F_69 , 0 ,
L_12 , V_4 ) ;
if ( V_93 < 0 ) {
F_77 ( V_95 , L_13 ) ;
return V_93 ;
}
F_81 ( V_130 , V_4 ) ;
F_82 ( V_95 ) ;
V_93 = F_83 ( V_95 , & V_141 ) ;
if ( V_93 )
goto V_142;
return 0 ;
V_142:
F_84 ( V_95 ) ;
return V_93 ;
}
static int F_85 ( struct V_129 * V_130 )
{
F_84 ( & V_130 -> V_95 ) ;
F_86 ( & V_130 -> V_95 , & V_141 ) ;
return 0 ;
}
