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
static void F_16 ( struct V_3 * V_4 , unsigned int V_48 )
{
struct V_49 * V_50 = & V_4 -> V_51 [ V_48 ] ;
unsigned long V_5 ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 &= ~ V_52 ;
switch ( V_50 -> V_53 ) {
case V_54 :
V_5 |= V_55 ;
V_5 |= V_56 ;
V_5 |= V_57 ;
break;
case V_58 :
V_5 |= V_59 ;
V_5 |= V_56 ;
V_5 |= V_57 ;
break;
case V_60 :
V_5 |= V_61 ;
V_5 |= V_62 ;
V_5 |= V_57 ;
break;
case V_63 :
V_5 |= V_64 ;
V_5 |= V_62 | V_65 | V_66 ;
V_5 |= V_57 ;
break;
default:
F_19 ( L_1 ) ;
return;
}
F_20 ( L_2 , V_50 -> V_67 ) ;
if ( V_50 -> V_68 < V_69 ) {
V_5 &= ~ V_70 ;
V_5 |= V_71 ;
}
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
}
static void F_21 ( struct V_3 * V_4 , int V_48 ,
bool V_72 )
{
T_1 V_5 ;
V_5 = F_17 ( V_4 -> V_13 + V_73 ) ;
if ( V_72 )
V_5 |= F_22 ( V_48 ) ;
else
V_5 &= ~ F_22 ( V_48 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_73 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int V_48 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_50 ;
T_1 V_5 ;
if ( V_48 < 0 || V_48 >= V_74 )
return;
V_50 = & V_4 -> V_51 [ V_48 ] ;
if ( V_4 -> V_6 )
return;
F_21 ( V_4 , V_48 , true ) ;
V_5 = F_24 ( V_50 -> V_75 ) | F_25 ( V_50 -> V_76 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_26 ( V_48 ) ) ;
V_5 = F_24 ( V_50 -> V_75 + V_50 -> V_77 - 1 ) |
F_25 ( V_50 -> V_76 + V_50 -> V_78 - 1 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_27 ( V_48 ) ) ;
V_5 = F_28 ( 0x0 ) | F_29 ( 0x0 ) |
F_30 ( 0x0 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_31 ( V_48 ) ) ;
V_5 = F_28 ( 0x0 ) | F_29 ( 0x0 ) |
F_30 ( 0x0 ) ;
F_3 ( V_5 , V_4 -> V_13 + F_32 ( V_48 ) ) ;
F_3 ( V_50 -> V_79 [ 0 ] , V_4 -> V_13 + F_33 ( V_48 ) ) ;
V_5 = V_50 -> V_79 [ 0 ] + V_50 -> V_80 * V_50 -> V_78 ;
F_3 ( V_5 , V_4 -> V_13 + F_34 ( V_48 ) ) ;
V_5 = F_35 ( V_50 -> V_80 - V_50 -> V_77 * ( V_50 -> V_67 >> 3 ) )
| F_36 ( V_50 -> V_77 * ( V_50 -> V_67 >> 3 ) ) ;
F_3 ( V_5 , V_4 -> V_13 + F_37 ( V_48 ) ) ;
F_16 ( V_4 , V_48 ) ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 |= V_81 ;
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
F_21 ( V_4 , V_48 , false ) ;
V_5 = F_17 ( V_4 -> V_13 + V_82 ) ;
V_5 |= V_83 ;
F_3 ( V_5 , V_4 -> V_13 + V_82 ) ;
if ( V_4 -> V_10 )
F_38 ( & V_4 -> V_84 , 1 ) ;
}
static void F_39 ( struct V_1 * V_2 , unsigned int V_48 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_49 * V_50 ;
T_1 V_5 ;
if ( V_48 < 0 || V_48 >= V_74 )
return;
V_50 = & V_4 -> V_51 [ V_48 ] ;
if ( V_4 -> V_6 )
return;
F_21 ( V_4 , V_48 , true ) ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 &= ~ V_81 ;
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
F_21 ( V_4 , V_48 , false ) ;
V_5 = F_17 ( V_4 -> V_13 + V_82 ) ;
V_5 |= V_83 ;
F_3 ( V_5 , V_4 -> V_13 + V_82 ) ;
}
static void F_40 ( struct V_3 * V_4 )
{
unsigned int V_85 ;
F_3 ( 0 , V_4 -> V_13 + V_47 ) ;
for ( V_85 = 2000 ; V_85 ; -- V_85 ) {
if ( ~ F_17 ( V_4 -> V_13 + V_47 ) & V_86 )
break;
F_41 ( 10 ) ;
}
F_42 ( V_85 == 0 , L_3 ) ;
F_3 ( V_87 , V_4 -> V_13 + V_47 ) ;
for ( V_85 = 2000 ; V_85 ; -- V_85 ) {
if ( ~ F_17 ( V_4 -> V_13 + V_47 ) & V_87 )
break;
F_41 ( 10 ) ;
}
F_42 ( V_85 == 0 , L_4 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_88 ;
int V_89 ;
if ( ! V_4 -> V_6 )
return;
V_4 -> V_6 = false ;
F_44 ( V_4 -> V_90 ) ;
for ( V_89 = 0 ; V_89 < F_45 ( V_91 ) ; V_89 ++ ) {
V_88 = F_46 ( V_4 -> V_92 [ V_89 ] ) ;
if ( V_88 < 0 )
goto V_93;
}
F_47 ( V_94 , & V_4 -> V_95 ) ;
if ( F_5 ( 0 , & V_4 -> V_8 ) )
F_1 ( V_4 -> V_2 ) ;
F_7 ( V_4 -> V_2 ) ;
return;
V_93:
while ( -- V_89 >= 0 )
F_48 ( V_4 -> V_92 [ V_89 ] ) ;
V_4 -> V_6 = true ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_89 ;
if ( V_4 -> V_6 )
return;
for ( V_89 = 0 ; V_89 < V_74 ; V_89 ++ )
F_39 ( V_2 , V_89 ) ;
F_40 ( V_4 ) ;
for ( V_89 = 0 ; V_89 < F_45 ( V_91 ) ; V_89 ++ )
F_48 ( V_4 -> V_92 [ V_89 ] ) ;
F_50 ( V_94 , & V_4 -> V_95 ) ;
F_51 ( V_4 -> V_90 ) ;
V_4 -> V_6 = true ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_5 ;
if ( ! F_53 ( V_94 , & V_4 -> V_95 ) )
return;
if ( F_54 ( & V_4 -> V_84 , - 1 , 0 ) ) {
V_5 = F_17 ( V_4 -> V_13 + V_19 ) ;
V_5 |= V_96 ;
F_3 ( V_5 , V_4 -> V_13 + V_19 ) ;
}
F_55 ( V_4 -> V_97 , V_4 -> V_98 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_48 , V_89 , V_88 ;
T_1 V_5 ;
F_20 ( L_5 , __FILE__ ) ;
for ( V_89 = 0 ; V_89 < F_45 ( V_91 ) ; V_89 ++ ) {
V_88 = F_46 ( V_4 -> V_92 [ V_89 ] ) ;
if ( V_88 < 0 )
goto V_93;
}
for ( V_48 = 0 ; V_48 < V_74 ; V_48 ++ ) {
V_5 = F_17 ( V_4 -> V_13 + V_73 ) ;
V_5 |= F_22 ( V_48 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_73 ) ;
V_5 = F_17 ( V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 &= ~ V_81 ;
F_3 ( V_5 , V_4 -> V_13 + F_18 ( V_48 ) ) ;
V_5 = F_17 ( V_4 -> V_13 + V_73 ) ;
V_5 &= ~ F_22 ( V_48 ) ;
F_3 ( V_5 , V_4 -> V_13 + V_73 ) ;
V_5 = F_17 ( V_4 -> V_13 + V_82 ) ;
V_5 |= V_83 ;
F_3 ( V_5 , V_4 -> V_13 + V_82 ) ;
}
F_57 ( 50 ) ;
V_93:
while ( -- V_89 >= 0 )
F_48 ( V_4 -> V_92 [ V_89 ] ) ;
}
static int F_58 ( struct V_99 * V_90 , struct V_99 * V_100 , void * V_101 )
{
struct V_3 * V_4 = F_59 ( V_90 ) ;
struct V_102 * V_97 = V_101 ;
struct V_103 * V_104 = V_97 -> V_105 ;
struct V_49 * V_106 ;
enum V_107 type ;
unsigned int V_108 ;
int V_88 ;
V_4 -> V_97 = V_97 ;
V_4 -> V_98 = V_104 -> V_98 ++ ;
for ( V_108 = 0 ; V_108 < V_74 ; V_108 ++ ) {
type = ( V_108 == V_4 -> V_109 ) ? V_110 :
V_111 ;
V_88 = F_60 ( V_97 , & V_4 -> V_51 [ V_108 ] ,
1 << V_4 -> V_98 , type , V_108 ) ;
if ( V_88 )
return V_88 ;
}
V_106 = & V_4 -> V_51 [ V_4 -> V_109 ] ;
V_4 -> V_2 = F_61 ( V_97 , & V_106 -> V_22 ,
V_4 -> V_98 , V_112 ,
& V_113 , V_4 ) ;
if ( F_62 ( V_4 -> V_2 ) ) {
V_88 = F_63 ( V_4 -> V_2 ) ;
goto V_93;
}
V_88 = F_64 ( V_4 -> V_2 , V_97 , V_90 ) ;
if ( V_88 )
goto V_93;
return V_88 ;
V_93:
V_104 -> V_98 -- ;
return V_88 ;
}
static void F_65 ( struct V_99 * V_90 , struct V_99 * V_100 , void * V_101 )
{
struct V_3 * V_4 = F_59 ( V_90 ) ;
F_49 ( V_4 -> V_2 ) ;
if ( F_66 ( V_4 -> V_97 ) )
F_67 ( V_4 -> V_97 , V_4 -> V_90 ) ;
}
static T_2 F_68 ( int V_114 , void * V_115 )
{
struct V_3 * V_4 = V_115 ;
T_1 V_5 ;
if ( ! F_53 ( V_94 , & V_4 -> V_95 ) )
goto V_116;
V_5 = F_17 ( V_4 -> V_13 + V_117 ) ;
if ( V_5 & V_118 ) {
F_55 ( V_4 -> V_97 , V_4 -> V_98 ) ;
F_3 ( V_118 , V_4 -> V_13 + V_117 ) ;
}
V_116:
return V_119 ;
}
static T_2 F_69 ( int V_114 , void * V_115 )
{
struct V_3 * V_4 = V_115 ;
T_1 V_5 ;
if ( ! F_53 ( V_94 , & V_4 -> V_95 ) )
goto V_116;
V_5 = F_17 ( V_4 -> V_13 + V_117 ) ;
if ( V_5 & V_120 ) {
F_70 ( V_4 -> V_97 , V_4 -> V_98 ) ;
F_3 ( V_120 ,
V_4 -> V_13 + V_117 ) ;
}
V_116:
return V_119 ;
}
static int F_71 ( struct V_121 * V_122 )
{
struct V_99 * V_90 = & V_122 -> V_90 ;
struct V_3 * V_4 ;
struct V_123 * V_124 ;
int V_88 ;
int V_89 ;
V_4 = F_72 ( V_90 , sizeof( * V_4 ) , V_125 ) ;
if ( ! V_4 )
return - V_126 ;
V_4 -> V_109 = 0 ;
V_4 -> V_6 = true ;
V_4 -> V_90 = V_90 ;
if ( F_73 ( V_90 -> V_127 , L_6 ) )
V_4 -> V_10 = true ;
for ( V_89 = 0 ; V_89 < F_45 ( V_91 ) ; V_89 ++ ) {
struct V_128 * V_128 ;
V_128 = F_74 ( V_4 -> V_90 , V_91 [ V_89 ] ) ;
if ( F_62 ( V_128 ) )
return F_63 ( V_128 ) ;
V_4 -> V_92 [ V_89 ] = V_128 ;
}
V_124 = F_75 ( V_122 , V_129 , 0 ) ;
if ( ! V_124 ) {
F_76 ( V_90 , L_7 ) ;
return - V_130 ;
}
V_4 -> V_13 = F_77 ( V_90 , V_124 ) ;
if ( F_62 ( V_4 -> V_13 ) ) {
F_76 ( V_90 , L_8 ) ;
return F_63 ( V_4 -> V_13 ) ;
}
V_124 = F_78 ( V_122 , V_131 ,
V_4 -> V_10 ? L_9 : L_10 ) ;
if ( ! V_124 ) {
F_76 ( V_90 , L_11 ) ;
return - V_130 ;
}
V_88 = F_79 ( V_90 , V_124 -> V_132 , V_4 -> V_10 ?
F_69 : F_68 , 0 ,
L_12 , V_4 ) ;
if ( V_88 < 0 ) {
F_76 ( V_90 , L_13 ) ;
return V_88 ;
}
F_80 ( V_122 , V_4 ) ;
F_81 ( V_90 ) ;
V_88 = F_82 ( V_90 , & V_133 ) ;
if ( V_88 )
goto V_134;
return 0 ;
V_134:
F_83 ( V_90 ) ;
return V_88 ;
}
static int F_84 ( struct V_121 * V_122 )
{
F_83 ( & V_122 -> V_90 ) ;
F_85 ( & V_122 -> V_90 , & V_133 ) ;
return 0 ;
}
