int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
if ( F_4 ( V_6 ) & V_7 )
return V_8 ;
if ( F_4 ( V_6 ) & V_9 )
return V_10 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_11 = 0 ;
if ( ! F_6 ( V_4 ) )
return 0 ;
if ( ! ( F_4 ( V_6 ) & V_12 ) )
V_11 = 1 ;
if ( F_7 ( V_2 ) )
V_11 = 1 ;
return V_11 ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_9 ( V_4 , V_13 , 0 ) ;
}
static T_1 F_10 ( struct V_3 * V_4 )
{
return F_11 ( V_4 , V_13 ) ;
}
static void F_12 ( struct V_3 * V_4 ,
T_1 V_14 )
{
struct V_15 * V_16 = F_13 ( V_4 ) ;
struct V_17 * V_18 = F_14 ( V_16 ) ;
T_1 V_19 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < 1024 ; V_20 ++ ) {
V_19 = F_10 ( V_4 ) ;
if ( V_19 & V_14 )
return;
F_15 ( 50 ) ;
}
F_16 ( V_18 , L_1 ,
F_17 ( V_4 ) , F_18 ( V_4 ) ) ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_21 V_22 [] = {
V_23 ,
V_24 ,
V_25 ,
} ;
int V_20 , V_26 ;
V_26 = 0 ;
for ( V_20 = 0 ; V_20 < F_20 ( V_22 ) ; V_20 ++ ) {
V_4 = F_21 ( V_2 , V_22 [ V_20 ] ) ;
if ( ! V_4 )
continue;
V_26 |= 1 << F_18 ( V_4 ) ;
}
return V_26 ;
}
static T_1 F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_27 = F_2 ( V_2 ) ;
struct V_3 * V_28 = F_23 ( V_2 ) ;
return F_24 ( V_2 ) |
1 << F_18 ( V_27 ) |
1 << F_18 ( V_28 ) ;
}
T_1 F_24 ( struct V_1 * V_2 )
{
if ( F_25 ( V_2 ) )
return F_19 ( V_2 ) ;
return 0 ;
}
unsigned int F_26 ( struct V_15 * V_16 ,
int V_29 , int V_30 , int * V_31 )
{
int V_32 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
int V_33 , V_34 ;
unsigned int V_35 ;
for ( V_33 = 0 ; V_33 < F_20 ( V_32 ) ; V_33 ++ ) {
if ( V_33 == 0 )
continue;
V_35 = 32 * V_29 * V_30 * V_32 [ V_33 ] ;
V_34 = F_27 ( V_16 , V_35 ) ;
if ( V_34 < 0 )
continue;
if ( V_31 )
* V_31 = V_33 ;
return V_35 ;
}
return 0 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 = F_29 ( V_2 ) ;
struct V_17 * V_18 = F_14 ( V_16 ) ;
struct V_36 * V_37 = F_30 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_3 * V_28 = F_23 ( V_2 ) ;
int V_38 = F_31 ( V_2 ) ;
int V_31 , V_34 ;
unsigned int V_35 ;
unsigned int V_39 = F_32 ( V_2 ) ?
F_33 ( V_16 , V_2 ) :
F_34 ( V_16 , V_2 ) ;
if ( ! F_35 ( V_37 ) )
return 0 ;
if ( V_28 && ! F_36 ( V_4 , V_2 ) )
return 0 ;
if ( F_37 ( V_4 , V_2 ) )
return 0 ;
if ( V_6 -> V_40 > 1 ) {
if ( V_6 -> V_39 != V_39 ) {
F_38 ( V_18 , L_2 ) ;
return - V_41 ;
}
return 0 ;
}
V_35 = F_26 ( V_16 , V_39 , V_38 , & V_31 ) ;
if ( ! V_35 ) {
F_38 ( V_18 , L_3 ) ;
return - V_42 ;
}
V_34 = F_39 ( V_4 , V_35 ) ;
if ( V_34 < 0 )
return V_34 ;
V_6 -> V_43 = V_44 | V_45 | V_46 | V_47 | F_40 ( V_31 ) ;
V_6 -> V_48 = V_49 ;
V_6 -> V_39 = V_39 ;
F_41 ( V_18 , L_4 ,
F_17 ( V_4 ) ,
F_18 ( V_4 ) , V_39 ) ;
return 0 ;
}
static void F_42 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_36 * V_37 = F_30 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_3 * V_28 = F_23 ( V_2 ) ;
if ( ! F_35 ( V_37 ) )
return;
if ( V_28 && ! F_36 ( V_4 , V_2 ) )
return;
if ( V_6 -> V_40 > 1 )
return;
V_6 -> V_43 = 0 ;
V_6 -> V_39 = 0 ;
F_43 ( V_4 ) ;
}
static void F_44 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_36 * V_37 = F_30 ( V_2 ) ;
struct V_50 * V_51 = F_45 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_52 ;
T_1 V_53 ;
T_1 V_48 ;
int V_54 ;
V_54 = F_46 ( V_2 ) ;
V_52 = V_44 | V_45 ;
if ( V_37 -> V_55 )
V_52 |= V_56 ;
if ( V_37 -> V_57 ^ V_54 )
V_52 |= V_58 ;
if ( V_37 -> V_59 )
V_52 |= V_60 ;
if ( V_37 -> V_61 )
V_52 |= V_62 ;
if ( F_32 ( V_2 ) )
V_52 |= V_63 ;
switch ( V_51 -> V_64 ) {
case 16 :
V_52 |= V_65 ;
break;
case 32 :
V_52 |= V_66 ;
break;
}
if ( F_6 ( V_4 ) ) {
V_53 = V_67 | V_68 |
V_69 ;
} else {
V_53 = V_70 ;
}
V_48 = V_6 -> V_48 ;
if ( V_54 ) {
V_48 |= V_71 ;
V_52 |= V_72 ;
}
V_6 -> V_52 = V_52 ;
V_6 -> V_53 = V_53 ;
V_6 -> V_48 = V_48 ;
}
static void F_47 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_9 ( V_4 , V_73 , V_6 -> V_48 ) ;
F_9 ( V_4 , V_74 , V_6 -> V_52 |
V_6 -> V_43 |
V_6 -> V_53 ) ;
}
static void F_48 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_50 * V_51 = F_45 ( V_2 ) ;
V_6 -> V_75 = 0 ;
V_6 -> V_76 = 0 ;
V_6 -> V_77 = V_51 -> V_78 *
V_51 -> V_79 *
F_49 ( V_51 , 1 ) ;
V_6 -> V_80 = V_6 -> V_77 ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_81 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_50 * V_51 = F_45 ( V_2 ) ;
int V_82 = V_6 -> V_75 + V_81 ;
V_82 %= ( V_51 -> V_83 * V_6 -> V_77 ) ;
return V_82 ;
}
static bool F_51 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
int V_84 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
V_6 -> V_75 += V_84 ;
if ( V_6 -> V_75 >= V_6 -> V_80 ) {
struct V_50 * V_51 = F_45 ( V_2 ) ;
V_6 -> V_76 ++ ;
V_6 -> V_80 += V_6 -> V_77 ;
if ( V_6 -> V_76 >= V_51 -> V_83 ) {
V_6 -> V_75 = 0 ;
V_6 -> V_76 = 0 ;
V_6 -> V_80 = V_6 -> V_77 ;
}
return true ;
}
return false ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_34 ;
if ( ! F_53 ( V_4 , V_2 ) )
return 0 ;
F_48 ( V_4 , V_2 ) ;
V_6 -> V_40 ++ ;
F_54 ( V_4 ) ;
V_34 = F_28 ( V_4 , V_2 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( ! F_36 ( V_4 , V_2 ) )
F_44 ( V_4 , V_2 ) ;
F_47 ( V_4 ) ;
F_8 ( V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_17 * V_18 = F_14 ( V_16 ) ;
if ( ! F_53 ( V_4 , V_2 ) )
return 0 ;
if ( ! V_6 -> V_40 ) {
F_38 ( V_18 , L_5 ,
F_17 ( V_4 ) , F_18 ( V_4 ) ) ;
return - V_42 ;
}
if ( ! F_36 ( V_4 , V_2 ) )
V_6 -> V_52 = 0 ;
F_42 ( V_4 , V_2 ) ;
F_56 ( V_4 ) ;
V_6 -> V_40 -- ;
return 0 ;
}
static int F_57 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_85 * V_86 ,
struct V_87 * V_88 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_38 = F_58 ( V_88 ) ;
if ( V_6 -> V_40 ) {
if ( V_6 -> V_38 != V_38 )
return - V_42 ;
}
V_6 -> V_38 = V_38 ;
return 0 ;
}
static int F_59 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
if ( ! F_53 ( V_4 , V_2 ) )
return 0 ;
if ( F_24 ( V_2 ) )
return 0 ;
F_60 ( V_4 , V_74 , V_89 , V_89 ) ;
return 0 ;
}
static int F_61 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_90 ;
if ( ! F_53 ( V_4 , V_2 ) )
return 0 ;
if ( V_6 -> V_40 > 1 )
return 0 ;
V_90 = V_6 -> V_52 |
V_6 -> V_43 ;
F_9 ( V_4 , V_74 , V_90 | V_89 ) ;
F_12 ( V_4 , V_91 ) ;
F_9 ( V_4 , V_74 , V_90 ) ;
F_12 ( V_4 , V_92 ) ;
return 0 ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 ,
int V_93 )
{
T_1 V_94 = 0 ;
if ( F_63 ( V_16 ) )
return 0 ;
if ( F_36 ( V_4 , V_2 ) )
return 0 ;
if ( ! F_53 ( V_4 , V_2 ) )
return 0 ;
if ( V_93 )
V_94 = F_6 ( V_4 ) ? 0x0e000000 : 0x0f000000 ;
F_9 ( V_4 , V_95 , V_94 ) ;
return 0 ;
}
static void F_64 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 = F_13 ( V_4 ) ;
int V_96 = F_6 ( V_4 ) ;
T_1 V_19 ;
bool V_97 = false ;
bool V_98 = false ;
F_65 ( & V_16 -> V_99 ) ;
if ( ! F_66 ( V_2 ) )
goto V_100;
V_19 = F_10 ( V_4 ) ;
if ( ! V_96 && ( V_19 & V_91 ) ) {
struct V_50 * V_51 = F_45 ( V_2 ) ;
T_1 * V_101 = ( T_1 * ) ( V_51 -> V_102 +
F_50 ( V_4 , V_2 , 0 ) ) ;
int V_103 = 0 ;
switch ( V_51 -> V_64 ) {
case 32 :
V_103 = 8 ;
break;
}
if ( F_32 ( V_2 ) )
F_9 ( V_4 , V_104 , ( * V_101 ) << V_103 ) ;
else
* V_101 = ( F_11 ( V_4 , V_105 ) >> V_103 ) ;
V_97 = F_51 ( V_4 , V_2 , sizeof( * V_101 ) ) ;
}
if ( V_96 && ( V_19 & ( V_106 | V_107 ) ) )
V_98 = true ;
F_8 ( V_4 ) ;
V_100:
F_67 ( & V_16 -> V_99 ) ;
if ( V_97 )
F_68 ( V_2 ) ;
if ( V_98 )
F_69 ( V_2 -> V_86 ) ;
}
static T_2 F_70 ( int V_108 , void * V_109 )
{
struct V_3 * V_4 = V_109 ;
F_71 ( V_4 , F_64 ) ;
return V_110 ;
}
static void F_72 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_36 * V_37 = F_30 ( V_2 ) ;
struct V_15 * V_16 = F_13 ( V_4 ) ;
if ( ! F_73 ( V_4 ) )
return;
if ( ! F_35 ( V_37 ) )
return;
switch ( F_18 ( V_4 ) ) {
case 1 :
case 2 :
F_74 ( F_75 ( V_16 , 0 ) , V_2 , V_111 ) ;
break;
case 4 :
F_74 ( F_75 ( V_16 , 3 ) , V_2 , V_111 ) ;
break;
case 8 :
F_74 ( F_75 ( V_16 , 7 ) , V_2 , V_111 ) ;
break;
}
}
static int F_76 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_112 * V_113 )
{
F_72 ( V_4 , V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_14 ( V_16 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_34 ;
if ( F_37 ( V_4 , V_2 ) )
return 0 ;
V_34 = F_78 ( V_2 , V_4 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = F_79 ( V_6 -> V_108 ,
F_70 ,
V_114 ,
F_80 ( V_18 ) , V_4 ) ;
return V_34 ;
}
static int F_81 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
T_3 * V_115 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_50 * V_51 = F_45 ( V_2 ) ;
* V_115 = F_82 ( V_51 , V_6 -> V_75 ) ;
return 0 ;
}
static int F_83 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_34 ;
if ( F_37 ( V_4 , V_2 ) )
return 0 ;
V_34 = F_77 ( V_4 , V_2 , V_16 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_84 ( V_2 , V_4 , & V_6 -> V_116 ) ;
return V_34 ;
}
static int F_85 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_3 * V_28 = F_23 ( V_2 ) ;
if ( V_28 == V_4 )
return 0 ;
F_86 ( V_6 -> V_108 , V_4 ) ;
return 0 ;
}
static int F_87 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_14 ( V_16 ) ;
V_4 -> V_117 = & V_118 ;
F_88 ( V_18 , L_6 ,
F_17 ( V_4 ) , F_18 ( V_4 ) ) ;
return 0 ;
}
static struct V_119 * F_89 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_15 * V_16 = F_13 ( V_4 ) ;
int V_120 = F_32 ( V_2 ) ;
char * V_121 ;
if ( F_5 ( V_2 ) )
V_121 = V_120 ? L_7 : L_8 ;
else
V_121 = V_120 ? L_9 : L_10 ;
return F_90 ( F_91 ( V_16 ) ,
V_4 , V_121 ) ;
}
int F_6 ( struct V_3 * V_4 )
{
return V_4 -> V_117 == & V_122 ;
}
static void F_92 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_36 * V_37 = F_30 ( V_2 ) ;
enum V_21 V_22 [] = {
V_123 ,
V_23 ,
V_24 ,
V_25 ,
} ;
enum V_21 type ;
int V_20 ;
for ( V_20 = 0 ; V_20 < F_20 ( V_22 ) ; V_20 ++ ) {
type = V_22 [ V_20 ] ;
if ( ! F_21 ( V_2 , type ) ) {
F_74 ( V_4 , V_2 , type ) ;
F_93 ( V_37 , ( V_20 + 1 ) * 2 ) ;
F_94 ( V_37 , ( V_20 + 1 ) ) ;
return;
}
}
}
void F_95 ( struct V_36 * V_37 ,
struct V_124 * V_125 ,
struct V_124 * V_126 )
{
struct V_15 * V_16 = F_96 ( V_37 ) ;
struct V_124 * V_127 ;
struct V_124 * V_128 ;
struct V_3 * V_4 ;
int V_20 ;
V_127 = F_91 ( V_16 ) ;
if ( ! V_127 )
return;
V_20 = 0 ;
F_97 (node, np) {
V_4 = F_75 ( V_16 , V_20 ) ;
if ( V_128 == V_125 )
F_92 ( V_4 , & V_37 -> V_125 ) ;
if ( V_128 == V_126 )
F_92 ( V_4 , & V_37 -> V_126 ) ;
V_20 ++ ;
}
F_98 ( V_127 ) ;
}
static void F_99 ( struct V_15 * V_16 ,
struct V_1 * V_2 ,
struct V_124 * V_129 )
{
struct V_17 * V_18 = F_14 ( V_16 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
if ( ! V_4 )
return;
V_6 = F_3 ( V_4 ) ;
if ( strstr ( V_129 -> V_130 , L_11 ) ) {
V_6 -> V_131 |= V_7 ;
F_41 ( V_18 , L_12 ,
F_17 ( V_4 ) , F_18 ( V_4 ) ) ;
}
if ( strstr ( V_129 -> V_130 , L_13 ) ) {
V_6 -> V_131 |= V_9 ;
F_41 ( V_18 , L_14 ,
F_17 ( V_4 ) , F_18 ( V_4 ) ) ;
}
}
void F_100 ( struct V_15 * V_16 ,
struct V_124 * V_132 ,
int V_133 )
{
struct V_36 * V_37 = F_101 ( V_16 , V_133 ) ;
struct V_124 * V_129 ;
V_129 = F_102 ( V_132 ) ;
if ( ! V_129 )
return;
F_99 ( V_16 , & V_37 -> V_125 , V_129 ) ;
F_99 ( V_16 , & V_37 -> V_126 , V_129 ) ;
}
struct V_3 * F_75 ( struct V_15 * V_16 , int V_134 )
{
if ( F_103 ( V_134 < 0 || V_134 >= F_104 ( V_16 ) ) )
V_134 = 0 ;
return F_105 ( F_106 ( V_16 , V_134 ) ) ;
}
int F_73 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return ! ! ( F_4 ( V_6 ) & V_135 ) ;
}
static T_1 * F_107 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_21 type )
{
if ( type == V_111 )
return & V_2 -> V_136 ;
return F_108 ( V_2 , V_4 , type ) ;
}
int F_109 ( struct V_15 * V_16 )
{
struct V_124 * V_127 ;
struct V_124 * V_128 ;
struct V_17 * V_18 = F_14 ( V_16 ) ;
struct V_137 * V_117 ;
struct V_138 * V_138 ;
struct V_5 * V_6 ;
char V_121 [ V_139 ] ;
int V_20 , V_140 , V_34 ;
V_127 = F_91 ( V_16 ) ;
if ( ! V_127 )
return - V_41 ;
V_140 = F_110 ( V_127 ) ;
if ( ! V_140 ) {
V_34 = - V_41 ;
goto V_141;
}
V_6 = F_111 ( V_18 , sizeof( * V_6 ) * V_140 , V_142 ) ;
if ( ! V_6 ) {
V_34 = - V_143 ;
goto V_141;
}
V_16 -> V_6 = V_6 ;
V_16 -> V_144 = V_140 ;
V_20 = 0 ;
F_97 (node, np) {
V_6 = F_106 ( V_16 , V_20 ) ;
snprintf ( V_121 , V_139 , L_15 ,
V_145 , V_20 ) ;
V_138 = F_112 ( V_18 , V_121 ) ;
if ( F_113 ( V_138 ) ) {
V_34 = F_114 ( V_138 ) ;
goto V_141;
}
if ( F_115 ( V_128 , L_16 , NULL ) )
V_6 -> V_131 |= V_135 ;
if ( F_115 ( V_128 , L_17 , NULL ) )
V_6 -> V_131 |= V_12 ;
V_6 -> V_108 = F_116 ( V_128 , 0 ) ;
if ( ! V_6 -> V_108 ) {
V_34 = - V_41 ;
goto V_141;
}
if ( F_117 ( V_128 , L_18 ) )
V_117 = & V_118 ;
else
V_117 = & V_122 ;
V_34 = F_118 ( V_16 , F_105 ( V_6 ) , V_117 , V_138 ,
F_107 , V_123 , V_20 ) ;
if ( V_34 )
goto V_141;
V_20 ++ ;
}
V_34 = 0 ;
V_141:
F_98 ( V_127 ) ;
return V_34 ;
}
void F_119 ( struct V_15 * V_16 )
{
struct V_5 * V_6 ;
int V_20 ;
F_120 (ssi, priv, i) {
F_121 ( F_105 ( V_6 ) ) ;
}
}
