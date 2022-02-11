bool
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! V_4 )
return false ;
if ( V_5 . V_6 ) {
struct V_7 * V_8 = V_2 -> V_9 ;
struct V_10 * V_11 = V_8 -> V_12 [ V_2 -> V_13 ] . V_11 ;
return V_11 -> V_14 ;
} else
return V_2 -> V_15 && V_2 -> V_15 -> V_14 ;
}
int F_2 ( int V_16 , int V_17 , int V_18 )
{
int V_19 = V_16 - V_17 ;
if ( V_19 <= 0 )
V_19 += V_18 ;
return V_19 - V_20 ;
}
void F_3 ( struct V_10 * V_11 )
{
if ( V_11 -> V_21 != - 1 ) {
V_11 -> V_16 = V_11 -> V_21 ;
V_11 -> V_21 = - 1 ;
}
V_11 -> V_19 = F_2 ( V_11 -> V_16 & V_22 ,
V_11 -> V_17 , V_11 -> V_18 ) ;
}
int F_4 ( struct V_10 * V_11 )
{
F_3 ( V_11 ) ;
return V_11 -> V_19 ;
}
bool F_5 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
return V_24 -> V_26 . V_27 & F_6 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
V_11 -> V_17 &= V_11 -> V_18 - 1 ;
if ( F_5 ( V_2 ) )
return;
V_2 -> V_28 ( V_2 , V_11 -> V_17 ) ;
}
static int
F_8 ( struct V_1 * V_2 ,
T_1 V_29 ,
T_1 V_30 )
{
T_1 V_31 ;
int V_32 ;
V_31 = V_33 ;
if ( ( ( V_29 | V_30 ) & V_34 ) == 0 )
V_31 |= V_35 ;
if ( V_29 & V_36 )
V_31 |= V_37 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 ,
T_1 V_29 ,
T_1 V_30 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_31 ;
int V_32 ;
V_31 = V_33 | V_35 ;
if ( ( V_29 | V_30 ) & V_34 )
V_31 &= ~ V_35 ;
if ( V_29 & V_39 )
V_31 |= V_40 ;
if ( V_29 & V_41 &&
( F_13 ( V_4 ) || F_14 ( V_4 ) ) )
V_31 |= V_42 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 )
{
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 5 ) ) ;
F_10 ( V_2 , V_47 |
V_48 ) ;
F_10 ( V_2 , V_43 | V_49 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 5 ) ) ;
F_10 ( V_2 , V_50 ) ;
F_10 ( V_2 , V_43 | V_49 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_51 = 0 ;
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_32 = F_15 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( V_30 ) {
V_51 |= V_52 ;
V_51 |= V_53 ;
V_51 |= V_47 ;
}
if ( V_29 ) {
V_51 |= V_54 ;
V_51 |= V_55 ;
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
V_51 |= V_50 | V_47 ;
}
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_51 ) ;
F_10 ( V_2 , V_43 | V_49 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_47 |
V_48 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_1 V_60 )
{
int V_32 ;
if ( ! V_2 -> V_61 )
return 0 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_20 ( 1 ) ) ;
F_10 ( V_2 , V_62 ) ;
F_10 ( V_2 , V_60 ) ;
F_10 ( V_2 , F_21 ( 1 ) | V_63 ) ;
F_10 ( V_2 , V_62 ) ;
F_10 ( V_2 , V_2 -> V_44 . V_45 + 256 ) ;
F_11 ( V_2 ) ;
V_2 -> V_61 = false ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_51 = 0 ;
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_51 |= V_47 ;
if ( V_30 ) {
V_51 |= V_52 ;
V_51 |= V_53 ;
}
if ( V_29 ) {
V_51 |= V_54 ;
V_51 |= V_55 ;
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
V_51 |= V_64 ;
V_51 |= V_50 ;
V_51 |= V_65 ;
V_51 |= V_48 ;
F_18 ( V_2 ) ;
}
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) ) ;
F_10 ( V_2 , V_51 ) ;
F_10 ( V_2 , V_43 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
if ( ! V_29 && V_30 )
return F_19 ( V_2 , V_66 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 ,
T_1 V_51 , T_1 V_43 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 6 ) ) ;
F_10 ( V_2 , V_51 ) ;
F_10 ( V_2 , V_43 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 ,
T_1 V_29 , T_1 V_30 )
{
T_1 V_51 = 0 ;
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_51 |= V_47 ;
if ( V_30 ) {
V_51 |= V_52 ;
V_51 |= V_53 ;
}
if ( V_29 ) {
V_51 |= V_54 ;
V_51 |= V_55 ;
V_51 |= V_56 ;
V_51 |= V_57 ;
V_51 |= V_58 ;
V_51 |= V_59 ;
V_51 |= V_50 ;
V_51 |= V_65 ;
V_32 = F_23 ( V_2 ,
V_47 |
V_48 ,
0 ) ;
if ( V_32 )
return V_32 ;
}
V_32 = F_23 ( V_2 , V_51 , V_43 ) ;
if ( V_32 )
return V_32 ;
if ( ! V_29 && V_30 )
return F_19 ( V_2 , V_66 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 ,
T_1 V_60 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_26 ( V_2 , V_60 ) ;
}
T_2 F_27 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_2 V_67 ;
if ( F_28 ( V_2 -> V_4 ) -> V_68 >= 8 )
V_67 = F_29 ( F_30 ( V_2 -> V_69 ) ,
F_31 ( V_2 -> V_69 ) ) ;
else if ( F_28 ( V_2 -> V_4 ) -> V_68 >= 4 )
V_67 = F_32 ( F_30 ( V_2 -> V_69 ) ) ;
else
V_67 = F_32 ( V_70 ) ;
return V_67 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_1 V_71 ;
V_71 = V_24 -> V_72 -> V_73 ;
if ( F_28 ( V_2 -> V_4 ) -> V_68 >= 4 )
V_71 |= ( V_24 -> V_72 -> V_73 >> 28 ) & 0xf0 ;
F_34 ( V_74 , V_71 ) ;
}
static bool F_35 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = F_36 ( V_2 -> V_4 ) ;
if ( ! F_37 ( V_2 -> V_4 ) ) {
F_38 ( V_2 , F_39 ( V_75 ) ) ;
if ( F_40 ( ( F_41 ( V_2 ) & V_76 ) != 0 , 1000 ) ) {
F_42 ( L_1 , V_2 -> V_77 ) ;
if ( F_43 ( V_2 ) != F_44 ( V_2 ) )
return false ;
}
}
F_45 ( V_2 , 0 ) ;
F_46 ( V_2 , 0 ) ;
V_2 -> V_28 ( V_2 , 0 ) ;
if ( ! F_37 ( V_2 -> V_4 ) ) {
( void ) F_47 ( V_2 ) ;
F_38 ( V_2 , F_48 ( V_75 ) ) ;
}
return ( F_43 ( V_2 ) & V_22 ) == 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_78 * V_14 = V_11 -> V_14 ;
int V_32 = 0 ;
F_50 ( V_24 , V_79 ) ;
if ( ! F_35 ( V_2 ) ) {
F_51 ( L_2
L_3 ,
V_2 -> V_77 ,
F_47 ( V_2 ) ,
F_43 ( V_2 ) ,
F_44 ( V_2 ) ,
F_52 ( V_2 ) ) ;
if ( ! F_35 ( V_2 ) ) {
F_42 ( L_4
L_3 ,
V_2 -> V_77 ,
F_47 ( V_2 ) ,
F_43 ( V_2 ) ,
F_44 ( V_2 ) ,
F_52 ( V_2 ) ) ;
V_32 = - V_80 ;
goto V_81;
}
}
if ( F_53 ( V_4 ) )
F_54 ( V_2 ) ;
else
F_33 ( V_2 ) ;
F_43 ( V_2 ) ;
F_55 ( V_2 , F_56 ( V_14 ) ) ;
if ( F_43 ( V_2 ) )
F_57 ( L_5 ,
V_2 -> V_77 , F_43 ( V_2 ) ) ;
F_46 ( V_2 , 0 ) ;
( void ) F_43 ( V_2 ) ;
F_45 ( V_2 ,
( ( V_11 -> V_18 - V_82 ) & V_83 )
| V_84 ) ;
if ( F_40 ( ( F_47 ( V_2 ) & V_84 ) != 0 &&
F_52 ( V_2 ) == F_56 ( V_14 ) &&
( F_43 ( V_2 ) & V_22 ) == 0 , 50 ) ) {
F_42 ( L_6
L_7 ,
V_2 -> V_77 ,
F_47 ( V_2 ) , F_47 ( V_2 ) & V_84 ,
F_43 ( V_2 ) , F_44 ( V_2 ) ,
F_52 ( V_2 ) , ( unsigned long ) F_56 ( V_14 ) ) ;
V_32 = - V_80 ;
goto V_81;
}
V_11 -> V_21 = - 1 ;
V_11 -> V_16 = F_43 ( V_2 ) ;
V_11 -> V_17 = F_44 ( V_2 ) & V_85 ;
F_3 ( V_11 ) ;
memset ( & V_2 -> V_86 , 0 , sizeof( V_2 -> V_86 ) ) ;
V_81:
F_58 ( V_24 , V_79 ) ;
return V_32 ;
}
void
F_59 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_44 . V_14 == NULL )
return;
if ( F_28 ( V_4 ) -> V_68 >= 5 ) {
F_60 ( F_61 ( V_2 -> V_44 . V_14 -> V_87 -> V_88 ) ) ;
F_62 ( V_2 -> V_44 . V_14 ) ;
}
F_63 ( & V_2 -> V_44 . V_14 -> V_89 ) ;
V_2 -> V_44 . V_14 = NULL ;
}
int
F_64 ( struct V_1 * V_2 )
{
int V_32 ;
F_65 ( V_2 -> V_44 . V_14 ) ;
V_2 -> V_44 . V_14 = F_66 ( V_2 -> V_4 , 4096 ) ;
if ( V_2 -> V_44 . V_14 == NULL ) {
F_42 ( L_8 ) ;
V_32 = - V_90 ;
goto V_91;
}
V_32 = F_67 ( V_2 -> V_44 . V_14 , V_92 ) ;
if ( V_32 )
goto V_93;
V_32 = F_68 ( V_2 -> V_44 . V_14 , 4096 , 0 ) ;
if ( V_32 )
goto V_93;
V_2 -> V_44 . V_45 = F_56 ( V_2 -> V_44 . V_14 ) ;
V_2 -> V_44 . V_94 = F_69 ( F_61 ( V_2 -> V_44 . V_14 -> V_87 -> V_88 ) ) ;
if ( V_2 -> V_44 . V_94 == NULL ) {
V_32 = - V_90 ;
goto V_95;
}
F_70 ( L_9 ,
V_2 -> V_77 , V_2 -> V_44 . V_45 ) ;
return 0 ;
V_95:
F_62 ( V_2 -> V_44 . V_14 ) ;
V_93:
F_63 ( & V_2 -> V_44 . V_14 -> V_89 ) ;
V_91:
return V_32 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_7 * V_96 )
{
int V_32 , V_97 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_98 * V_99 = & V_24 -> V_100 ;
if ( F_72 ( V_99 -> V_101 == 0 ) )
return 0 ;
V_2 -> V_102 = true ;
V_32 = F_73 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_9 ( V_2 , ( V_99 -> V_101 * 2 + 2 ) ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_20 ( V_99 -> V_101 ) ) ;
for ( V_97 = 0 ; V_97 < V_99 -> V_101 ; V_97 ++ ) {
F_10 ( V_2 , V_99 -> V_103 [ V_97 ] . V_71 ) ;
F_10 ( V_2 , V_99 -> V_103 [ V_97 ] . V_60 ) ;
}
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
V_2 -> V_102 = true ;
V_32 = F_73 ( V_2 ) ;
if ( V_32 )
return V_32 ;
F_70 ( L_10 , V_99 -> V_101 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_7 * V_96 )
{
int V_32 ;
V_32 = F_71 ( V_2 , V_96 ) ;
if ( V_32 != 0 )
return V_32 ;
V_32 = F_75 ( V_2 ) ;
if ( V_32 )
F_42 ( L_11 , V_32 ) ;
return V_32 ;
}
static int F_76 ( struct V_23 * V_24 ,
const T_1 V_71 , const T_1 V_104 , const T_1 V_105 )
{
const T_1 V_106 = V_24 -> V_100 . V_101 ;
if ( F_65 ( V_106 >= V_107 ) )
return - V_108 ;
V_24 -> V_100 . V_103 [ V_106 ] . V_71 = V_71 ;
V_24 -> V_100 . V_103 [ V_106 ] . V_60 = V_105 ;
V_24 -> V_100 . V_103 [ V_106 ] . V_104 = V_104 ;
V_24 -> V_100 . V_101 ++ ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_78 ( V_109 ,
V_110 |
V_111 ) ;
F_78 ( V_112 ,
V_113 ) ;
F_78 ( V_114 ,
V_115 ) ;
F_78 ( V_116 ,
V_117 |
V_118 |
( F_79 ( V_4 ) ? V_119 : 0 ) ) ;
F_80 ( V_120 , V_121 ) ;
F_78 ( V_122 ,
V_123 ) ;
F_81 ( V_124 ,
V_125 ,
V_126 ) ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_78 ( V_109 ,
V_110 |
V_111 ) ;
F_78 ( V_116 ,
V_117 |
V_118 ) ;
F_80 ( V_120 , V_121 ) ;
F_78 ( V_122 ,
V_123 ) ;
F_78 ( V_127 , V_128 ) ;
F_81 ( V_124 ,
V_125 ,
V_126 ) ;
return 0 ;
}
int F_83 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_65 ( V_2 -> V_13 != V_129 ) ;
V_24 -> V_100 . V_101 = 0 ;
if ( F_84 ( V_4 ) )
return F_77 ( V_2 ) ;
if ( F_85 ( V_4 ) )
return F_82 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
int V_32 = F_49 ( V_2 ) ;
if ( V_32 )
return V_32 ;
if ( F_28 ( V_4 ) -> V_68 >= 4 && F_28 ( V_4 ) -> V_68 < 7 )
F_34 ( V_130 , F_39 ( V_131 ) ) ;
if ( F_28 ( V_4 ) -> V_68 >= 6 && F_28 ( V_4 ) -> V_68 < 9 )
F_34 ( V_130 , F_39 ( V_132 ) ) ;
if ( F_28 ( V_4 ) -> V_68 == 6 )
F_34 ( V_133 ,
F_39 ( V_134 ) ) ;
if ( F_87 ( V_4 ) )
F_34 ( V_135 ,
F_39 ( V_134 ) |
F_39 ( V_136 ) ) ;
if ( F_88 ( V_4 ) ) {
F_34 ( V_137 ,
F_48 ( V_138 ) ) ;
}
if ( F_28 ( V_4 ) -> V_68 >= 6 )
F_34 ( V_139 , F_39 ( V_140 ) ) ;
if ( F_89 ( V_4 ) )
F_90 ( V_2 , ~ F_91 ( V_4 ) ) ;
return F_83 ( V_2 ) ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
if ( V_24 -> V_141 ) {
F_62 ( V_24 -> V_141 ) ;
F_63 ( & V_24 -> V_141 -> V_89 ) ;
V_24 -> V_141 = NULL ;
}
F_59 ( V_2 ) ;
}
static int F_93 ( struct V_1 * V_142 ,
unsigned int V_143 )
{
#define F_94 8
struct V_3 * V_4 = V_142 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_144 ;
int V_97 , V_32 , V_145 ;
V_145 = F_95 ( F_28 ( V_4 ) -> V_146 ) ;
V_143 += ( V_145 - 1 ) * F_94 ;
#undef F_94
V_32 = F_9 ( V_142 , V_143 ) ;
if ( V_32 )
return V_32 ;
F_96 (waiter, dev_priv, i) {
T_1 V_147 ;
T_2 V_45 = V_142 -> V_148 . V_149 [ V_97 ] ;
if ( V_45 == V_150 )
continue;
V_147 = F_97 (
V_142 -> V_151 ) ;
F_10 ( V_142 , F_16 ( 6 ) ) ;
F_10 ( V_142 , V_65 |
V_50 |
V_152 ) ;
F_10 ( V_142 , F_98 ( V_45 ) ) ;
F_10 ( V_142 , F_99 ( V_45 ) ) ;
F_10 ( V_142 , V_147 ) ;
F_10 ( V_142 , 0 ) ;
F_10 ( V_142 , V_153 |
F_100 ( V_144 -> V_13 ) ) ;
F_10 ( V_142 , 0 ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_142 ,
unsigned int V_143 )
{
#define F_94 6
struct V_3 * V_4 = V_142 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_144 ;
int V_97 , V_32 , V_145 ;
V_145 = F_95 ( F_28 ( V_4 ) -> V_146 ) ;
V_143 += ( V_145 - 1 ) * F_94 ;
#undef F_94
V_32 = F_9 ( V_142 , V_143 ) ;
if ( V_32 )
return V_32 ;
F_96 (waiter, dev_priv, i) {
T_1 V_147 ;
T_2 V_45 = V_142 -> V_148 . V_149 [ V_97 ] ;
if ( V_45 == V_150 )
continue;
V_147 = F_97 (
V_142 -> V_151 ) ;
F_10 ( V_142 , ( V_154 + 1 ) |
V_155 ) ;
F_10 ( V_142 , F_98 ( V_45 ) |
V_156 ) ;
F_10 ( V_142 , F_99 ( V_45 ) ) ;
F_10 ( V_142 , V_147 ) ;
F_10 ( V_142 , V_153 |
F_100 ( V_144 -> V_13 ) ) ;
F_10 ( V_142 , 0 ) ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_142 ,
unsigned int V_143 )
{
struct V_3 * V_4 = V_142 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_157 ;
int V_97 , V_32 , V_145 ;
#define F_94 3
V_145 = F_95 ( F_28 ( V_4 ) -> V_146 ) ;
V_143 += F_103 ( ( V_145 - 1 ) * F_94 , 2 ) ;
#undef F_94
V_32 = F_9 ( V_142 , V_143 ) ;
if ( V_32 )
return V_32 ;
F_96 (useless, dev_priv, i) {
T_1 V_158 = V_142 -> V_148 . V_159 . signal [ V_97 ] ;
if ( V_158 != V_160 ) {
T_1 V_147 = F_97 (
V_142 -> V_151 ) ;
F_10 ( V_142 , F_20 ( 1 ) ) ;
F_10 ( V_142 , V_158 ) ;
F_10 ( V_142 , V_147 ) ;
}
}
if ( V_145 % 2 == 0 )
F_10 ( V_142 , V_38 ) ;
return 0 ;
}
static int
F_104 ( struct V_1 * V_2 )
{
int V_32 ;
if ( V_2 -> V_148 . signal )
V_32 = V_2 -> V_148 . signal ( V_2 , 4 ) ;
else
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_161 ) ;
F_10 ( V_2 , V_162 << V_163 ) ;
F_10 ( V_2 ,
F_97 ( V_2 -> V_151 ) ) ;
F_10 ( V_2 , V_164 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static inline bool F_105 ( struct V_3 * V_4 ,
T_1 V_147 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
return V_24 -> V_165 < V_147 ;
}
static int
F_106 ( struct V_1 * V_144 ,
struct V_1 * V_142 ,
T_1 V_147 )
{
struct V_23 * V_24 = V_144 -> V_4 -> V_25 ;
int V_32 ;
V_32 = F_9 ( V_144 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_144 , V_166 |
V_167 |
V_168 |
V_169 ) ;
F_10 ( V_144 , V_147 ) ;
F_10 ( V_144 ,
F_98 ( F_107 ( V_144 , V_142 -> V_13 ) ) ) ;
F_10 ( V_144 ,
F_99 ( F_107 ( V_144 , V_142 -> V_13 ) ) ) ;
F_11 ( V_144 ) ;
return 0 ;
}
static int
F_108 ( struct V_1 * V_144 ,
struct V_1 * V_142 ,
T_1 V_147 )
{
T_1 V_170 = V_171 |
V_172 |
V_173 ;
T_1 V_174 = V_142 -> V_148 . V_159 . V_175 [ V_144 -> V_13 ] ;
int V_32 ;
V_147 -= 1 ;
F_65 ( V_174 == V_150 ) ;
V_32 = F_9 ( V_144 , 4 ) ;
if ( V_32 )
return V_32 ;
if ( F_109 ( ! F_105 ( V_144 -> V_4 , V_147 ) ) ) {
F_10 ( V_144 , V_170 | V_174 ) ;
F_10 ( V_144 , V_147 ) ;
F_10 ( V_144 , 0 ) ;
F_10 ( V_144 , V_38 ) ;
} else {
F_10 ( V_144 , V_38 ) ;
F_10 ( V_144 , V_38 ) ;
F_10 ( V_144 , V_38 ) ;
F_10 ( V_144 , V_38 ) ;
}
F_11 ( V_144 ) ;
return 0 ;
}
static int
F_110 ( struct V_1 * V_2 )
{
T_1 V_43 = V_2 -> V_44 . V_45 + 2 * V_46 ;
int V_32 ;
V_32 = F_9 ( V_2 , 32 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , F_16 ( 4 ) | V_50 |
V_176 |
V_56 ) ;
F_10 ( V_2 , V_2 -> V_44 . V_45 | V_49 ) ;
F_10 ( V_2 ,
F_97 ( V_2 -> V_151 ) ) ;
F_10 ( V_2 , 0 ) ;
F_111 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_111 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_111 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_111 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_111 ( V_2 , V_43 ) ;
V_43 += 2 * V_46 ;
F_111 ( V_2 , V_43 ) ;
F_10 ( V_2 , F_16 ( 4 ) | V_50 |
V_176 |
V_56 |
V_177 ) ;
F_10 ( V_2 , V_2 -> V_44 . V_45 | V_49 ) ;
F_10 ( V_2 ,
F_97 ( V_2 -> V_151 ) ) ;
F_10 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static T_1
F_112 ( struct V_1 * V_2 , bool V_178 )
{
if ( ! V_178 ) {
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_113 ( F_30 ( V_2 -> V_69 ) ) ;
}
return F_114 ( V_2 , V_162 ) ;
}
static T_1
F_115 ( struct V_1 * V_2 , bool V_178 )
{
return F_114 ( V_2 , V_162 ) ;
}
static void
F_116 ( struct V_1 * V_2 , T_1 V_147 )
{
F_117 ( V_2 , V_162 , V_147 ) ;
}
static T_1
F_118 ( struct V_1 * V_2 , bool V_178 )
{
return V_2 -> V_44 . V_94 [ 0 ] ;
}
static void
F_119 ( struct V_1 * V_2 , T_1 V_147 )
{
V_2 -> V_44 . V_94 [ 0 ] = V_147 ;
}
static bool
F_120 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_65 ( ! F_121 ( V_24 ) ) )
return false ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( V_2 -> V_180 ++ == 0 )
F_123 ( V_24 , V_2 -> V_181 ) ;
F_124 ( & V_24 -> V_179 , V_51 ) ;
return true ;
}
static void
F_125 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( -- V_2 -> V_180 == 0 )
F_126 ( V_24 , V_2 -> V_181 ) ;
F_124 ( & V_24 -> V_179 , V_51 ) ;
}
static bool
F_127 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( ! F_121 ( V_24 ) )
return false ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( V_2 -> V_180 ++ == 0 ) {
V_24 -> V_182 &= ~ V_2 -> V_181 ;
F_34 ( V_183 , V_24 -> V_182 ) ;
F_113 ( V_183 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
return true ;
}
static void
F_128 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( -- V_2 -> V_180 == 0 ) {
V_24 -> V_182 |= V_2 -> V_181 ;
F_34 ( V_183 , V_24 -> V_182 ) ;
F_113 ( V_183 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
}
static bool
F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( ! F_121 ( V_24 ) )
return false ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( V_2 -> V_180 ++ == 0 ) {
V_24 -> V_182 &= ~ V_2 -> V_181 ;
F_130 ( V_183 , V_24 -> V_182 ) ;
F_131 ( V_183 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
return true ;
}
static void
F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( -- V_2 -> V_180 == 0 ) {
V_24 -> V_182 |= V_2 -> V_181 ;
F_130 ( V_183 , V_24 -> V_182 ) ;
F_131 ( V_183 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
T_1 V_184 = 0 ;
if ( F_87 ( V_4 ) ) {
switch ( V_2 -> V_13 ) {
case V_129 :
V_184 = V_185 ;
break;
case V_186 :
V_184 = V_187 ;
break;
case V_188 :
case V_189 :
V_184 = V_190 ;
break;
case V_191 :
V_184 = V_192 ;
break;
}
} else if ( F_88 ( V_2 -> V_4 ) ) {
V_184 = F_133 ( V_2 -> V_69 ) ;
} else {
V_184 = F_134 ( V_2 -> V_69 ) ;
}
F_34 ( V_184 , ( T_1 ) V_2 -> V_193 . V_194 ) ;
F_113 ( V_184 ) ;
if ( F_28 ( V_4 ) -> V_68 >= 6 && F_28 ( V_4 ) -> V_68 < 8 ) {
T_1 V_103 = F_135 ( V_2 -> V_69 ) ;
F_65 ( ( F_41 ( V_2 ) & V_76 ) == 0 ) ;
F_34 ( V_103 ,
F_39 ( V_195 |
V_196 ) ) ;
if ( F_40 ( ( F_32 ( V_103 ) & V_196 ) == 0 ,
1000 ) )
F_42 ( L_12 ,
V_2 -> V_77 ) ;
}
}
static int
F_136 ( struct V_1 * V_2 ,
T_1 V_29 ,
T_1 V_30 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_137 ( struct V_1 * V_2 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_161 ) ;
F_10 ( V_2 , V_162 << V_163 ) ;
F_10 ( V_2 ,
F_97 ( V_2 -> V_151 ) ) ;
F_10 ( V_2 , V_164 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static bool
F_138 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_65 ( ! F_121 ( V_24 ) ) )
return false ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( V_2 -> V_180 ++ == 0 ) {
if ( F_89 ( V_4 ) && V_2 -> V_13 == V_129 )
F_90 ( V_2 ,
~ ( V_2 -> V_181 |
F_91 ( V_4 ) ) ) ;
else
F_90 ( V_2 , ~ V_2 -> V_181 ) ;
F_123 ( V_24 , V_2 -> V_181 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
return true ;
}
static void
F_139 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( -- V_2 -> V_180 == 0 ) {
if ( F_89 ( V_4 ) && V_2 -> V_13 == V_129 )
F_90 ( V_2 , ~ F_91 ( V_4 ) ) ;
else
F_90 ( V_2 , ~ 0 ) ;
F_126 ( V_24 , V_2 -> V_181 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
}
static bool
F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_65 ( ! F_121 ( V_24 ) ) )
return false ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( V_2 -> V_180 ++ == 0 ) {
F_90 ( V_2 , ~ V_2 -> V_181 ) ;
F_141 ( V_24 , V_2 -> V_181 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
return true ;
}
static void
F_142 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( -- V_2 -> V_180 == 0 ) {
F_90 ( V_2 , ~ 0 ) ;
F_143 ( V_24 , V_2 -> V_181 ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
}
static bool
F_144 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
if ( F_65 ( ! F_121 ( V_24 ) ) )
return false ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( V_2 -> V_180 ++ == 0 ) {
if ( F_89 ( V_4 ) && V_2 -> V_13 == V_129 ) {
F_90 ( V_2 ,
~ ( V_2 -> V_181 |
V_197 ) ) ;
} else {
F_90 ( V_2 , ~ V_2 -> V_181 ) ;
}
F_113 ( F_145 ( V_2 -> V_69 ) ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
return true ;
}
static void
F_146 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
unsigned long V_51 ;
F_122 ( & V_24 -> V_179 , V_51 ) ;
if ( -- V_2 -> V_180 == 0 ) {
if ( F_89 ( V_4 ) && V_2 -> V_13 == V_129 ) {
F_90 ( V_2 ,
~ V_197 ) ;
} else {
F_90 ( V_2 , ~ 0 ) ;
}
F_113 ( F_145 ( V_2 -> V_69 ) ) ;
}
F_124 ( & V_24 -> V_179 , V_51 ) ;
}
static int
F_147 ( struct V_1 * V_2 ,
T_2 V_198 , T_1 V_199 ,
unsigned V_51 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_200 |
V_201 |
( V_51 & V_202 ? 0 : V_203 ) ) ;
F_10 ( V_2 , V_198 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_148 ( struct V_1 * V_2 ,
T_2 V_198 , T_1 V_204 ,
unsigned V_51 )
{
T_1 V_205 = V_2 -> V_44 . V_45 ;
int V_32 ;
V_32 = F_9 ( V_2 , 6 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_206 | V_207 ) ;
F_10 ( V_2 , V_208 | V_209 | 4096 ) ;
F_10 ( V_2 , V_210 << 16 | 4 ) ;
F_10 ( V_2 , V_205 ) ;
F_10 ( V_2 , 0xdeadbeef ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
if ( ( V_51 & V_211 ) == 0 ) {
if ( V_204 > V_212 )
return - V_108 ;
V_32 = F_9 ( V_2 , 6 + 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_213 | V_207 ) ;
F_10 ( V_2 , V_208 | V_214 | 4096 ) ;
F_10 ( V_2 , F_149 ( V_204 , 4096 ) << 16 | 4096 ) ;
F_10 ( V_2 , V_205 ) ;
F_10 ( V_2 , 4096 ) ;
F_10 ( V_2 , V_198 ) ;
F_10 ( V_2 , V_33 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
V_198 = V_205 ;
}
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_215 ) ;
F_10 ( V_2 , V_198 | ( V_51 & V_202 ? 0 : V_216 ) ) ;
F_10 ( V_2 , V_198 + V_204 - 8 ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_150 ( struct V_1 * V_2 ,
T_2 V_198 , T_1 V_204 ,
unsigned V_51 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_200 | V_201 ) ;
F_10 ( V_2 , V_198 | ( V_51 & V_202 ? 0 : V_216 ) ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static void F_151 ( struct V_1 * V_2 )
{
struct V_78 * V_14 ;
V_14 = V_2 -> V_193 . V_14 ;
if ( V_14 == NULL )
return;
F_60 ( F_61 ( V_14 -> V_87 -> V_88 ) ) ;
F_62 ( V_14 ) ;
F_63 ( & V_14 -> V_89 ) ;
V_2 -> V_193 . V_14 = NULL ;
}
static int F_152 ( struct V_1 * V_2 )
{
struct V_78 * V_14 ;
if ( ( V_14 = V_2 -> V_193 . V_14 ) == NULL ) {
unsigned V_51 ;
int V_32 ;
V_14 = F_66 ( V_2 -> V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_42 ( L_13 ) ;
return - V_90 ;
}
V_32 = F_67 ( V_14 , V_92 ) ;
if ( V_32 )
goto V_93;
V_51 = 0 ;
if ( ! F_153 ( V_2 -> V_4 ) )
V_51 |= V_217 ;
V_32 = F_68 ( V_14 , 4096 , V_51 ) ;
if ( V_32 ) {
V_93:
F_63 ( & V_14 -> V_89 ) ;
return V_32 ;
}
V_2 -> V_193 . V_14 = V_14 ;
}
V_2 -> V_193 . V_194 = F_56 ( V_14 ) ;
V_2 -> V_193 . V_218 = F_69 ( F_61 ( V_14 -> V_87 -> V_88 ) ) ;
memset ( V_2 -> V_193 . V_218 , 0 , V_82 ) ;
F_70 ( L_14 ,
V_2 -> V_77 , V_2 -> V_193 . V_194 ) ;
return 0 ;
}
static int F_154 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
if ( ! V_24 -> V_72 ) {
V_24 -> V_72 =
F_155 ( V_2 -> V_4 , V_82 , V_82 ) ;
if ( ! V_24 -> V_72 )
return - V_90 ;
}
V_2 -> V_193 . V_218 = V_24 -> V_72 -> V_219 ;
memset ( V_2 -> V_193 . V_218 , 0 , V_82 ) ;
return 0 ;
}
void F_156 ( struct V_10 * V_11 )
{
F_157 ( V_11 -> V_220 ) ;
V_11 -> V_220 = NULL ;
F_62 ( V_11 -> V_14 ) ;
}
int F_158 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_23 * V_24 = F_36 ( V_4 ) ;
struct V_78 * V_14 = V_11 -> V_14 ;
int V_32 ;
V_32 = F_68 ( V_14 , V_82 , V_217 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_159 ( V_14 , true ) ;
if ( V_32 ) {
F_62 ( V_14 ) ;
return V_32 ;
}
V_11 -> V_220 = F_160 ( V_24 -> V_221 . V_222 +
F_56 ( V_14 ) , V_11 -> V_18 ) ;
if ( V_11 -> V_220 == NULL ) {
F_62 ( V_14 ) ;
return - V_223 ;
}
return 0 ;
}
void F_161 ( struct V_10 * V_11 )
{
F_63 ( & V_11 -> V_14 -> V_89 ) ;
V_11 -> V_14 = NULL ;
}
int F_162 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_78 * V_14 ;
V_14 = NULL ;
if ( ! F_153 ( V_4 ) )
V_14 = F_163 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
V_14 = F_66 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
return - V_90 ;
V_14 -> V_224 = 1 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
static int F_164 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 ;
int V_32 ;
F_65 ( V_2 -> V_15 ) ;
V_11 = F_165 ( sizeof( * V_11 ) , V_225 ) ;
if ( ! V_11 )
return - V_90 ;
V_2 -> V_15 = V_11 ;
V_2 -> V_4 = V_4 ;
F_166 ( & V_2 -> V_226 ) ;
F_166 ( & V_2 -> V_227 ) ;
F_166 ( & V_2 -> V_228 ) ;
V_11 -> V_18 = 32 * V_82 ;
V_11 -> V_2 = V_2 ;
memset ( V_2 -> V_148 . V_229 , 0 , sizeof( V_2 -> V_148 . V_229 ) ) ;
F_167 ( & V_2 -> V_230 ) ;
if ( F_53 ( V_4 ) ) {
V_32 = F_152 ( V_2 ) ;
if ( V_32 )
goto error;
} else {
F_168 ( V_2 -> V_13 != V_129 ) ;
V_32 = F_154 ( V_2 ) ;
if ( V_32 )
goto error;
}
F_65 ( V_11 -> V_14 ) ;
V_32 = F_162 ( V_4 , V_11 ) ;
if ( V_32 ) {
F_42 ( L_15 ,
V_2 -> V_77 , V_32 ) ;
goto error;
}
V_32 = F_158 ( V_4 , V_11 ) ;
if ( V_32 ) {
F_42 ( L_16 ,
V_2 -> V_77 , V_32 ) ;
F_161 ( V_11 ) ;
goto error;
}
V_11 -> V_231 = V_11 -> V_18 ;
if ( F_169 ( V_4 ) || F_170 ( V_4 ) )
V_11 -> V_231 -= 2 * V_46 ;
V_32 = F_171 ( V_2 ) ;
if ( V_32 )
goto error;
return 0 ;
error:
F_172 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_32 ;
}
void F_173 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_10 * V_11 ;
if ( ! F_1 ( V_2 ) )
return;
V_24 = F_36 ( V_2 -> V_4 ) ;
V_11 = V_2 -> V_15 ;
F_174 ( V_2 ) ;
F_65 ( ! F_37 ( V_2 -> V_4 ) && ( F_41 ( V_2 ) & V_76 ) == 0 ) ;
F_156 ( V_11 ) ;
F_161 ( V_11 ) ;
F_175 ( & V_2 -> V_151 , NULL ) ;
if ( V_2 -> V_232 )
V_2 -> V_232 ( V_2 ) ;
F_151 ( V_2 ) ;
F_176 ( V_2 ) ;
F_172 ( V_11 ) ;
V_2 -> V_15 = NULL ;
}
static int F_177 ( struct V_1 * V_2 , int V_233 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_234 * V_235 ;
int V_32 ;
if ( F_4 ( V_11 ) >= V_233 )
return 0 ;
F_178 (request, &ring->request_list, list) {
if ( F_2 ( V_235 -> V_236 , V_11 -> V_17 ,
V_11 -> V_18 ) >= V_233 ) {
break;
}
}
if ( & V_235 -> V_237 == & V_2 -> V_227 )
return - V_108 ;
V_32 = F_179 ( V_235 ) ;
if ( V_32 )
return V_32 ;
F_180 ( V_2 ) ;
return 0 ;
}
static int F_181 ( struct V_1 * V_2 , int V_233 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_10 * V_11 = V_2 -> V_15 ;
unsigned long V_238 ;
int V_32 ;
V_32 = F_177 ( V_2 , V_233 ) ;
if ( V_32 != - V_108 )
return V_32 ;
F_7 ( V_2 ) ;
V_238 = V_239 + 60 * V_240 ;
V_32 = 0 ;
F_182 ( V_2 ) ;
do {
if ( F_4 ( V_11 ) >= V_233 )
break;
V_11 -> V_16 = F_43 ( V_2 ) ;
if ( F_4 ( V_11 ) >= V_233 )
break;
F_183 ( 1 ) ;
if ( V_24 -> V_241 . V_242 && F_184 ( V_243 ) ) {
V_32 = - V_244 ;
break;
}
V_32 = F_185 ( & V_24 -> V_26 ,
V_24 -> V_241 . V_242 ) ;
if ( V_32 )
break;
if ( F_186 ( V_239 , V_238 ) ) {
V_32 = - V_245 ;
break;
}
} while ( 1 );
F_187 ( V_2 ) ;
return V_32 ;
}
static int F_188 ( struct V_1 * V_2 )
{
T_3 T_4 * V_246 ;
struct V_10 * V_11 = V_2 -> V_15 ;
int V_247 = V_11 -> V_18 - V_11 -> V_17 ;
if ( V_11 -> V_19 < V_247 ) {
int V_32 = F_181 ( V_2 , V_247 ) ;
if ( V_32 )
return V_32 ;
}
V_246 = V_11 -> V_220 + V_11 -> V_17 ;
V_247 /= 4 ;
while ( V_247 -- )
F_189 ( V_38 , V_246 ++ ) ;
V_11 -> V_17 = 0 ;
F_3 ( V_11 ) ;
return 0 ;
}
int F_190 ( struct V_1 * V_2 )
{
struct V_234 * V_248 ;
int V_32 ;
if ( V_2 -> V_151 ) {
V_32 = F_191 ( V_2 ) ;
if ( V_32 )
return V_32 ;
}
if ( F_192 ( & V_2 -> V_227 ) )
return 0 ;
V_248 = F_193 ( V_2 -> V_227 . V_249 ,
struct V_234 ,
V_237 ) ;
return F_179 ( V_248 ) ;
}
static int
F_194 ( struct V_1 * V_2 )
{
int V_32 ;
struct V_234 * V_235 ;
struct V_23 * V_25 = V_2 -> V_4 -> V_25 ;
if ( V_2 -> V_151 )
return 0 ;
V_235 = F_165 ( sizeof( * V_235 ) , V_225 ) ;
if ( V_235 == NULL )
return - V_90 ;
F_195 ( & V_235 -> V_250 ) ;
V_235 -> V_2 = V_2 ;
V_235 -> V_251 = V_25 -> V_252 ++ ;
V_32 = F_196 ( V_2 -> V_4 , & V_235 -> V_147 ) ;
if ( V_32 ) {
F_172 ( V_235 ) ;
return V_32 ;
}
V_2 -> V_151 = V_235 ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
int V_253 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_32 ;
if ( F_198 ( V_11 -> V_17 + V_253 > V_11 -> V_231 ) ) {
V_32 = F_188 ( V_2 ) ;
if ( F_198 ( V_32 ) )
return V_32 ;
}
if ( F_198 ( V_11 -> V_19 < V_253 ) ) {
V_32 = F_181 ( V_2 , V_253 ) ;
if ( F_198 ( V_32 ) )
return V_32 ;
}
return 0 ;
}
int F_9 ( struct V_1 * V_2 ,
int V_143 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
int V_32 ;
V_32 = F_185 ( & V_24 -> V_26 ,
V_24 -> V_241 . V_242 ) ;
if ( V_32 )
return V_32 ;
V_32 = F_197 ( V_2 , V_143 * sizeof( T_3 ) ) ;
if ( V_32 )
return V_32 ;
V_32 = F_194 ( V_2 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_15 -> V_19 -= V_143 * sizeof( T_3 ) ;
return 0 ;
}
int F_199 ( struct V_1 * V_2 )
{
int V_143 = ( V_2 -> V_15 -> V_17 & ( V_46 - 1 ) ) / sizeof( T_3 ) ;
int V_32 ;
if ( V_143 == 0 )
return 0 ;
V_143 = V_46 / sizeof( T_3 ) - V_143 ;
V_32 = F_9 ( V_2 , V_143 ) ;
if ( V_32 )
return V_32 ;
while ( V_143 -- )
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
void F_200 ( struct V_1 * V_2 , T_1 V_147 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
F_168 ( V_2 -> V_151 ) ;
if ( F_28 ( V_4 ) -> V_68 == 6 || F_28 ( V_4 ) -> V_68 == 7 ) {
F_34 ( F_201 ( V_2 -> V_69 ) , 0 ) ;
F_34 ( F_202 ( V_2 -> V_69 ) , 0 ) ;
if ( F_203 ( V_4 ) )
F_34 ( F_204 ( V_2 -> V_69 ) , 0 ) ;
}
V_2 -> V_254 ( V_2 , V_147 ) ;
V_2 -> V_86 . V_147 = V_147 ;
}
static void F_205 ( struct V_1 * V_2 ,
T_1 V_60 )
{
struct V_23 * V_24 = V_2 -> V_4 -> V_25 ;
F_34 ( V_255 ,
F_39 ( V_256 ) ) ;
F_206 ( V_257 , 0x0 ) ;
if ( F_40 ( ( F_32 ( V_255 ) &
V_258 ) == 0 ,
50 ) )
F_42 ( L_17 ) ;
F_26 ( V_2 , V_60 ) ;
F_113 ( F_207 ( V_2 -> V_69 ) ) ;
F_34 ( V_255 ,
F_48 ( V_256 ) ) ;
}
static int F_208 ( struct V_1 * V_2 ,
T_1 V_259 , T_1 V_260 )
{
T_3 V_31 ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_154 ;
if ( F_28 ( V_2 -> V_4 ) -> V_68 >= 8 )
V_31 += 1 ;
V_31 |= V_261 | V_155 ;
if ( V_259 & V_262 )
V_31 |= V_263 | V_264 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_265 | V_156 ) ;
if ( F_28 ( V_2 -> V_4 ) -> V_68 >= 8 ) {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
} else {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
}
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_209 ( struct V_1 * V_2 ,
T_2 V_198 , T_1 V_204 ,
unsigned V_51 )
{
bool V_266 = F_210 ( V_2 -> V_4 ) && ! ( V_51 & V_202 ) ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 , V_267 | ( V_266 << 8 ) ) ;
F_10 ( V_2 , F_98 ( V_198 ) ) ;
F_10 ( V_2 , F_99 ( V_198 ) ) ;
F_10 ( V_2 , V_38 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_211 ( struct V_1 * V_2 ,
T_2 V_198 , T_1 V_204 ,
unsigned V_51 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_200 |
( V_51 & V_202 ?
0 : V_268 | V_269 ) ) ;
F_10 ( V_2 , V_198 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int
F_212 ( struct V_1 * V_2 ,
T_2 V_198 , T_1 V_204 ,
unsigned V_51 )
{
int V_32 ;
V_32 = F_9 ( V_2 , 2 ) ;
if ( V_32 )
return V_32 ;
F_10 ( V_2 ,
V_200 |
( V_51 & V_202 ? 0 : V_203 ) ) ;
F_10 ( V_2 , V_198 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_213 ( struct V_1 * V_2 ,
T_1 V_259 , T_1 V_260 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_23 * V_24 = V_4 -> V_25 ;
T_3 V_31 ;
int V_32 ;
V_32 = F_9 ( V_2 , 4 ) ;
if ( V_32 )
return V_32 ;
V_31 = V_154 ;
if ( F_28 ( V_2 -> V_4 ) -> V_68 >= 8 )
V_31 += 1 ;
V_31 |= V_261 | V_155 ;
if ( V_259 & V_34 )
V_31 |= V_263 ;
F_10 ( V_2 , V_31 ) ;
F_10 ( V_2 , V_265 | V_156 ) ;
if ( F_28 ( V_2 -> V_4 ) -> V_68 >= 8 ) {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , 0 ) ;
} else {
F_10 ( V_2 , 0 ) ;
F_10 ( V_2 , V_38 ) ;
}
F_11 ( V_2 ) ;
if ( ! V_259 && V_260 ) {
if ( F_87 ( V_4 ) )
return F_19 ( V_2 , V_270 ) ;
else if ( F_84 ( V_4 ) )
V_24 -> V_271 . V_272 = true ;
}
return 0 ;
}
int F_214 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_129 ] ;
struct V_78 * V_14 ;
int V_32 ;
V_2 -> V_77 = L_18 ;
V_2 -> V_13 = V_129 ;
V_2 -> V_69 = V_273 ;
if ( F_28 ( V_4 ) -> V_68 >= 8 ) {
if ( F_215 ( V_4 ) ) {
V_14 = F_66 ( V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_42 ( L_19 ) ;
V_5 . V_274 = 0 ;
} else {
F_67 ( V_14 , V_92 ) ;
V_32 = F_68 ( V_14 , 0 , V_275 ) ;
if ( V_32 != 0 ) {
F_63 ( & V_14 -> V_89 ) ;
F_42 ( L_20 ) ;
V_5 . V_274 = 0 ;
} else
V_24 -> V_141 = V_14 ;
}
}
V_2 -> V_276 = F_74 ;
V_2 -> V_277 = F_104 ;
V_2 -> V_260 = F_24 ;
V_2 -> V_278 = F_144 ;
V_2 -> V_279 = F_146 ;
V_2 -> V_181 = V_280 ;
V_2 -> V_281 = F_112 ;
V_2 -> V_254 = F_116 ;
if ( F_215 ( V_4 ) ) {
F_65 ( ! V_24 -> V_141 ) ;
V_2 -> V_148 . V_282 = F_106 ;
V_2 -> V_148 . signal = F_93 ;
V_283 ;
}
} else if ( F_28 ( V_4 ) -> V_68 >= 6 ) {
V_2 -> V_277 = F_104 ;
V_2 -> V_260 = F_22 ;
if ( F_28 ( V_4 ) -> V_68 == 6 )
V_2 -> V_260 = F_17 ;
V_2 -> V_278 = F_138 ;
V_2 -> V_279 = F_139 ;
V_2 -> V_181 = V_280 ;
V_2 -> V_281 = F_112 ;
V_2 -> V_254 = F_116 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . V_282 = F_108 ;
V_2 -> V_148 . signal = F_102 ;
V_2 -> V_148 . V_159 . V_175 [ V_129 ] = V_150 ;
V_2 -> V_148 . V_159 . V_175 [ V_189 ] = V_284 ;
V_2 -> V_148 . V_159 . V_175 [ V_186 ] = V_285 ;
V_2 -> V_148 . V_159 . V_175 [ V_191 ] = V_286 ;
V_2 -> V_148 . V_159 . V_175 [ V_188 ] = V_150 ;
V_2 -> V_148 . V_159 . signal [ V_129 ] = V_160 ;
V_2 -> V_148 . V_159 . signal [ V_189 ] = V_287 ;
V_2 -> V_148 . V_159 . signal [ V_186 ] = V_288 ;
V_2 -> V_148 . V_159 . signal [ V_191 ] = V_289 ;
V_2 -> V_148 . V_159 . signal [ V_188 ] = V_160 ;
}
} else if ( F_14 ( V_4 ) ) {
V_2 -> V_277 = F_110 ;
V_2 -> V_260 = F_12 ;
V_2 -> V_281 = F_118 ;
V_2 -> V_254 = F_119 ;
V_2 -> V_278 = F_120 ;
V_2 -> V_279 = F_125 ;
V_2 -> V_181 = V_280 |
V_290 ;
} else {
V_2 -> V_277 = F_137 ;
if ( F_28 ( V_4 ) -> V_68 < 4 )
V_2 -> V_260 = F_8 ;
else
V_2 -> V_260 = F_12 ;
V_2 -> V_281 = F_115 ;
V_2 -> V_254 = F_116 ;
if ( F_37 ( V_4 ) ) {
V_2 -> V_278 = F_129 ;
V_2 -> V_279 = F_132 ;
} else {
V_2 -> V_278 = F_127 ;
V_2 -> V_279 = F_128 ;
}
V_2 -> V_181 = V_291 ;
}
V_2 -> V_28 = F_25 ;
if ( F_216 ( V_4 ) )
V_2 -> V_292 = F_211 ;
else if ( F_217 ( V_4 ) )
V_2 -> V_292 = F_209 ;
else if ( F_28 ( V_4 ) -> V_68 >= 6 )
V_2 -> V_292 = F_212 ;
else if ( F_28 ( V_4 ) -> V_68 >= 4 )
V_2 -> V_292 = F_147 ;
else if ( F_169 ( V_4 ) || F_170 ( V_4 ) )
V_2 -> V_292 = F_148 ;
else
V_2 -> V_292 = F_150 ;
V_2 -> V_293 = F_86 ;
V_2 -> V_232 = F_92 ;
if ( F_218 ( V_4 ) ) {
V_14 = F_66 ( V_4 , V_294 ) ;
if ( V_14 == NULL ) {
F_42 ( L_21 ) ;
return - V_90 ;
}
V_32 = F_68 ( V_14 , 0 , 0 ) ;
if ( V_32 != 0 ) {
F_63 ( & V_14 -> V_89 ) ;
F_42 ( L_22 ) ;
return V_32 ;
}
V_2 -> V_44 . V_14 = V_14 ;
V_2 -> V_44 . V_45 = F_56 ( V_14 ) ;
}
V_32 = F_164 ( V_4 , V_2 ) ;
if ( V_32 )
return V_32 ;
if ( F_28 ( V_4 ) -> V_68 >= 5 ) {
V_32 = F_64 ( V_2 ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
int F_219 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_189 ] ;
V_2 -> V_77 = L_23 ;
V_2 -> V_13 = V_189 ;
V_2 -> V_28 = F_25 ;
if ( F_28 ( V_4 ) -> V_68 >= 6 ) {
V_2 -> V_69 = V_295 ;
if ( F_88 ( V_4 ) )
V_2 -> V_28 = F_205 ;
V_2 -> V_260 = F_208 ;
V_2 -> V_277 = F_104 ;
V_2 -> V_281 = F_112 ;
V_2 -> V_254 = F_116 ;
if ( F_28 ( V_4 ) -> V_68 >= 8 ) {
V_2 -> V_181 =
V_280 << V_296 ;
V_2 -> V_278 = F_144 ;
V_2 -> V_279 = F_146 ;
V_2 -> V_292 =
F_209 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . V_282 = F_106 ;
V_2 -> V_148 . signal = F_101 ;
V_283 ;
}
} else {
V_2 -> V_181 = V_297 ;
V_2 -> V_278 = F_138 ;
V_2 -> V_279 = F_139 ;
V_2 -> V_292 =
F_212 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . V_282 = F_108 ;
V_2 -> V_148 . signal = F_102 ;
V_2 -> V_148 . V_159 . V_175 [ V_129 ] = V_298 ;
V_2 -> V_148 . V_159 . V_175 [ V_189 ] = V_150 ;
V_2 -> V_148 . V_159 . V_175 [ V_186 ] = V_299 ;
V_2 -> V_148 . V_159 . V_175 [ V_191 ] = V_300 ;
V_2 -> V_148 . V_159 . V_175 [ V_188 ] = V_150 ;
V_2 -> V_148 . V_159 . signal [ V_129 ] = V_301 ;
V_2 -> V_148 . V_159 . signal [ V_189 ] = V_160 ;
V_2 -> V_148 . V_159 . signal [ V_186 ] = V_302 ;
V_2 -> V_148 . V_159 . signal [ V_191 ] = V_303 ;
V_2 -> V_148 . V_159 . signal [ V_188 ] = V_160 ;
}
}
} else {
V_2 -> V_69 = V_304 ;
V_2 -> V_260 = F_136 ;
V_2 -> V_277 = F_137 ;
V_2 -> V_281 = F_115 ;
V_2 -> V_254 = F_116 ;
if ( F_14 ( V_4 ) ) {
V_2 -> V_181 = V_305 ;
V_2 -> V_278 = F_120 ;
V_2 -> V_279 = F_125 ;
} else {
V_2 -> V_181 = V_306 ;
V_2 -> V_278 = F_127 ;
V_2 -> V_279 = F_128 ;
}
V_2 -> V_292 = F_147 ;
}
V_2 -> V_293 = F_49 ;
return F_164 ( V_4 , V_2 ) ;
}
int F_220 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_188 ] ;
if ( ( F_28 ( V_4 ) -> V_68 != 8 ) ) {
F_42 ( L_24 ) ;
return - V_223 ;
}
V_2 -> V_77 = L_25 ;
V_2 -> V_13 = V_188 ;
V_2 -> V_28 = F_25 ;
V_2 -> V_69 = V_307 ;
V_2 -> V_260 = F_208 ;
V_2 -> V_277 = F_104 ;
V_2 -> V_281 = F_112 ;
V_2 -> V_254 = F_116 ;
V_2 -> V_181 =
V_280 << V_308 ;
V_2 -> V_278 = F_144 ;
V_2 -> V_279 = F_146 ;
V_2 -> V_292 =
F_209 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . V_282 = F_106 ;
V_2 -> V_148 . signal = F_101 ;
V_283 ;
}
V_2 -> V_293 = F_49 ;
return F_164 ( V_4 , V_2 ) ;
}
int F_221 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_186 ] ;
V_2 -> V_77 = L_26 ;
V_2 -> V_13 = V_186 ;
V_2 -> V_69 = V_309 ;
V_2 -> V_28 = F_25 ;
V_2 -> V_260 = F_213 ;
V_2 -> V_277 = F_104 ;
V_2 -> V_281 = F_112 ;
V_2 -> V_254 = F_116 ;
if ( F_28 ( V_4 ) -> V_68 >= 8 ) {
V_2 -> V_181 =
V_280 << V_310 ;
V_2 -> V_278 = F_144 ;
V_2 -> V_279 = F_146 ;
V_2 -> V_292 = F_209 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . V_282 = F_106 ;
V_2 -> V_148 . signal = F_101 ;
V_283 ;
}
} else {
V_2 -> V_181 = V_311 ;
V_2 -> V_278 = F_138 ;
V_2 -> V_279 = F_139 ;
V_2 -> V_292 = F_212 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . signal = F_102 ;
V_2 -> V_148 . V_282 = F_108 ;
V_2 -> V_148 . V_159 . V_175 [ V_129 ] = V_312 ;
V_2 -> V_148 . V_159 . V_175 [ V_189 ] = V_313 ;
V_2 -> V_148 . V_159 . V_175 [ V_186 ] = V_150 ;
V_2 -> V_148 . V_159 . V_175 [ V_191 ] = V_314 ;
V_2 -> V_148 . V_159 . V_175 [ V_188 ] = V_150 ;
V_2 -> V_148 . V_159 . signal [ V_129 ] = V_315 ;
V_2 -> V_148 . V_159 . signal [ V_189 ] = V_316 ;
V_2 -> V_148 . V_159 . signal [ V_186 ] = V_160 ;
V_2 -> V_148 . V_159 . signal [ V_191 ] = V_317 ;
V_2 -> V_148 . V_159 . signal [ V_188 ] = V_160 ;
}
}
V_2 -> V_293 = F_49 ;
return F_164 ( V_4 , V_2 ) ;
}
int F_222 ( struct V_3 * V_4 )
{
struct V_23 * V_24 = V_4 -> V_25 ;
struct V_1 * V_2 = & V_24 -> V_2 [ V_191 ] ;
V_2 -> V_77 = L_27 ;
V_2 -> V_13 = V_191 ;
V_2 -> V_69 = V_318 ;
V_2 -> V_28 = F_25 ;
V_2 -> V_260 = F_213 ;
V_2 -> V_277 = F_104 ;
V_2 -> V_281 = F_112 ;
V_2 -> V_254 = F_116 ;
if ( F_28 ( V_4 ) -> V_68 >= 8 ) {
V_2 -> V_181 =
V_280 << V_319 ;
V_2 -> V_278 = F_144 ;
V_2 -> V_279 = F_146 ;
V_2 -> V_292 = F_209 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . V_282 = F_106 ;
V_2 -> V_148 . signal = F_101 ;
V_283 ;
}
} else {
V_2 -> V_181 = V_320 ;
V_2 -> V_278 = F_140 ;
V_2 -> V_279 = F_142 ;
V_2 -> V_292 = F_212 ;
if ( F_215 ( V_4 ) ) {
V_2 -> V_148 . V_282 = F_108 ;
V_2 -> V_148 . signal = F_102 ;
V_2 -> V_148 . V_159 . V_175 [ V_129 ] = V_321 ;
V_2 -> V_148 . V_159 . V_175 [ V_189 ] = V_322 ;
V_2 -> V_148 . V_159 . V_175 [ V_186 ] = V_323 ;
V_2 -> V_148 . V_159 . V_175 [ V_191 ] = V_150 ;
V_2 -> V_148 . V_159 . V_175 [ V_188 ] = V_150 ;
V_2 -> V_148 . V_159 . signal [ V_129 ] = V_324 ;
V_2 -> V_148 . V_159 . signal [ V_189 ] = V_325 ;
V_2 -> V_148 . V_159 . signal [ V_186 ] = V_326 ;
V_2 -> V_148 . V_159 . signal [ V_191 ] = V_160 ;
V_2 -> V_148 . V_159 . signal [ V_188 ] = V_160 ;
}
}
V_2 -> V_293 = F_49 ;
return F_164 ( V_4 , V_2 ) ;
}
int
F_73 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! V_2 -> V_102 )
return 0 ;
V_32 = V_2 -> V_260 ( V_2 , 0 , V_262 ) ;
if ( V_32 )
return V_32 ;
F_223 ( V_2 , 0 , V_262 ) ;
V_2 -> V_102 = false ;
return 0 ;
}
int
F_224 ( struct V_1 * V_2 )
{
T_3 V_30 ;
int V_32 ;
V_30 = 0 ;
if ( V_2 -> V_102 )
V_30 = V_262 ;
V_32 = V_2 -> V_260 ( V_2 , V_262 , V_30 ) ;
if ( V_32 )
return V_32 ;
F_223 ( V_2 , V_262 , V_30 ) ;
V_2 -> V_102 = false ;
return 0 ;
}
void
F_174 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_1 ( V_2 ) )
return;
V_32 = F_190 ( V_2 ) ;
if ( V_32 && ! F_225 ( & F_36 ( V_2 -> V_4 ) -> V_26 ) )
F_42 ( L_28 ,
V_2 -> V_77 , V_32 ) ;
F_35 ( V_2 ) ;
}
