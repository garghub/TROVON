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
int V_19 = V_16 - ( V_17 + V_20 ) ;
if ( V_19 < 0 )
V_19 += V_18 ;
return V_19 ;
}
int F_3 ( struct V_10 * V_11 )
{
return F_2 ( V_11 -> V_16 & V_21 ,
V_11 -> V_17 , V_11 -> V_18 ) ;
}
bool F_4 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
return V_23 -> V_25 . V_26 & F_5 ( V_2 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
V_11 -> V_17 &= V_11 -> V_18 - 1 ;
if ( F_4 ( V_2 ) )
return;
V_2 -> V_27 ( V_2 , V_11 -> V_17 ) ;
}
static int
F_7 ( struct V_1 * V_2 ,
T_1 V_28 ,
T_1 V_29 )
{
T_1 V_30 ;
int V_31 ;
V_30 = V_32 ;
if ( ( ( V_28 | V_29 ) & V_33 ) == 0 )
V_30 |= V_34 ;
if ( V_28 & V_35 )
V_30 |= V_36 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_30 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 ,
T_1 V_28 ,
T_1 V_29 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_30 ;
int V_31 ;
V_30 = V_32 | V_34 ;
if ( ( V_28 | V_29 ) & V_33 )
V_30 &= ~ V_34 ;
if ( V_28 & V_38 )
V_30 |= V_39 ;
if ( V_28 & V_40 &&
( F_12 ( V_4 ) || F_13 ( V_4 ) ) )
V_30 |= V_41 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_30 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
T_1 V_42 = V_2 -> V_43 . V_44 + 2 * V_45 ;
int V_31 ;
V_31 = F_8 ( V_2 , 6 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 5 ) ) ;
F_9 ( V_2 , V_46 |
V_47 ) ;
F_9 ( V_2 , V_42 | V_48 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
V_31 = F_8 ( V_2 , 6 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 5 ) ) ;
F_9 ( V_2 , V_49 ) ;
F_9 ( V_2 , V_42 | V_48 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_2 ,
T_1 V_28 , T_1 V_29 )
{
T_1 V_50 = 0 ;
T_1 V_42 = V_2 -> V_43 . V_44 + 2 * V_45 ;
int V_31 ;
V_31 = F_14 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_29 ) {
V_50 |= V_51 ;
V_50 |= V_52 ;
V_50 |= V_46 ;
}
if ( V_28 ) {
V_50 |= V_53 ;
V_50 |= V_54 ;
V_50 |= V_55 ;
V_50 |= V_56 ;
V_50 |= V_57 ;
V_50 |= V_58 ;
V_50 |= V_49 | V_46 ;
}
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 4 ) ) ;
F_9 ( V_2 , V_50 ) ;
F_9 ( V_2 , V_42 | V_48 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 4 ) ) ;
F_9 ( V_2 , V_46 |
V_47 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , T_1 V_59 )
{
int V_31 ;
if ( ! V_2 -> V_60 )
return 0 ;
V_31 = F_8 ( V_2 , 6 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_19 ( 1 ) ) ;
F_9 ( V_2 , V_61 ) ;
F_9 ( V_2 , V_59 ) ;
F_9 ( V_2 , F_20 ( 1 ) | V_62 ) ;
F_9 ( V_2 , V_61 ) ;
F_9 ( V_2 , V_2 -> V_43 . V_44 + 256 ) ;
F_10 ( V_2 ) ;
V_2 -> V_60 = false ;
return 0 ;
}
static int
F_21 ( struct V_1 * V_2 ,
T_1 V_28 , T_1 V_29 )
{
T_1 V_50 = 0 ;
T_1 V_42 = V_2 -> V_43 . V_44 + 2 * V_45 ;
int V_31 ;
V_50 |= V_46 ;
if ( V_29 ) {
V_50 |= V_51 ;
V_50 |= V_52 ;
}
if ( V_28 ) {
V_50 |= V_53 ;
V_50 |= V_54 ;
V_50 |= V_55 ;
V_50 |= V_56 ;
V_50 |= V_57 ;
V_50 |= V_58 ;
V_50 |= V_63 ;
V_50 |= V_49 ;
V_50 |= V_64 ;
V_50 |= V_47 ;
F_17 ( V_2 ) ;
}
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 4 ) ) ;
F_9 ( V_2 , V_50 ) ;
F_9 ( V_2 , V_42 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 ) ;
if ( ! V_28 && V_29 )
return F_18 ( V_2 , V_65 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 ,
T_1 V_50 , T_1 V_42 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 6 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 6 ) ) ;
F_9 ( V_2 , V_50 ) ;
F_9 ( V_2 , V_42 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 ,
T_1 V_28 , T_1 V_29 )
{
T_1 V_50 = 0 ;
T_1 V_42 = V_2 -> V_43 . V_44 + 2 * V_45 ;
int V_31 ;
V_50 |= V_46 ;
if ( V_29 ) {
V_50 |= V_51 ;
V_50 |= V_52 ;
}
if ( V_28 ) {
V_50 |= V_53 ;
V_50 |= V_54 ;
V_50 |= V_55 ;
V_50 |= V_56 ;
V_50 |= V_57 ;
V_50 |= V_58 ;
V_50 |= V_49 ;
V_50 |= V_64 ;
V_31 = F_22 ( V_2 ,
V_46 |
V_47 ,
0 ) ;
if ( V_31 )
return V_31 ;
}
V_31 = F_22 ( V_2 , V_50 , V_42 ) ;
if ( V_31 )
return V_31 ;
if ( ! V_28 && V_29 )
return F_18 ( V_2 , V_65 ) ;
return 0 ;
}
static void F_24 ( struct V_1 * V_2 ,
T_1 V_59 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
F_25 ( V_2 , V_59 ) ;
}
T_2 F_26 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
T_2 V_66 ;
if ( F_27 ( V_2 -> V_4 ) -> V_67 >= 8 )
V_66 = F_28 ( F_29 ( V_2 -> V_68 ) ,
F_30 ( V_2 -> V_68 ) ) ;
else if ( F_27 ( V_2 -> V_4 ) -> V_67 >= 4 )
V_66 = F_31 ( F_29 ( V_2 -> V_68 ) ) ;
else
V_66 = F_31 ( V_69 ) ;
return V_66 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
T_1 V_70 ;
V_70 = V_23 -> V_71 -> V_72 ;
if ( F_27 ( V_2 -> V_4 ) -> V_67 >= 4 )
V_70 |= ( V_23 -> V_71 -> V_72 >> 28 ) & 0xf0 ;
F_33 ( V_73 , V_70 ) ;
}
static bool F_34 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_35 ( V_2 -> V_4 ) ;
if ( ! F_36 ( V_2 -> V_4 ) ) {
F_37 ( V_2 , F_38 ( V_74 ) ) ;
if ( F_39 ( ( F_40 ( V_2 ) & V_75 ) != 0 , 1000 ) ) {
F_41 ( L_1 , V_2 -> V_76 ) ;
if ( F_42 ( V_2 ) != F_43 ( V_2 ) )
return false ;
}
}
F_44 ( V_2 , 0 ) ;
F_45 ( V_2 , 0 ) ;
V_2 -> V_27 ( V_2 , 0 ) ;
if ( ! F_36 ( V_2 -> V_4 ) ) {
( void ) F_46 ( V_2 ) ;
F_37 ( V_2 , F_47 ( V_74 ) ) ;
}
return ( F_42 ( V_2 ) & V_21 ) == 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_77 * V_14 = V_11 -> V_14 ;
int V_31 = 0 ;
F_49 ( V_23 , V_78 ) ;
if ( ! F_34 ( V_2 ) ) {
F_50 ( L_2
L_3 ,
V_2 -> V_76 ,
F_46 ( V_2 ) ,
F_42 ( V_2 ) ,
F_43 ( V_2 ) ,
F_51 ( V_2 ) ) ;
if ( ! F_34 ( V_2 ) ) {
F_41 ( L_4
L_3 ,
V_2 -> V_76 ,
F_46 ( V_2 ) ,
F_42 ( V_2 ) ,
F_43 ( V_2 ) ,
F_51 ( V_2 ) ) ;
V_31 = - V_79 ;
goto V_80;
}
}
if ( F_52 ( V_4 ) )
F_53 ( V_2 ) ;
else
F_32 ( V_2 ) ;
F_42 ( V_2 ) ;
F_54 ( V_2 , F_55 ( V_14 ) ) ;
if ( F_42 ( V_2 ) )
F_56 ( L_5 ,
V_2 -> V_76 , F_42 ( V_2 ) ) ;
F_45 ( V_2 , 0 ) ;
( void ) F_42 ( V_2 ) ;
F_44 ( V_2 ,
( ( V_11 -> V_18 - V_81 ) & V_82 )
| V_83 ) ;
if ( F_39 ( ( F_46 ( V_2 ) & V_83 ) != 0 &&
F_51 ( V_2 ) == F_55 ( V_14 ) &&
( F_42 ( V_2 ) & V_21 ) == 0 , 50 ) ) {
F_41 ( L_6
L_7 ,
V_2 -> V_76 ,
F_46 ( V_2 ) , F_46 ( V_2 ) & V_83 ,
F_42 ( V_2 ) , F_43 ( V_2 ) ,
F_51 ( V_2 ) , ( unsigned long ) F_55 ( V_14 ) ) ;
V_31 = - V_79 ;
goto V_80;
}
V_11 -> V_16 = F_42 ( V_2 ) ;
V_11 -> V_17 = F_43 ( V_2 ) & V_84 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
V_11 -> V_85 = - 1 ;
memset ( & V_2 -> V_86 , 0 , sizeof( V_2 -> V_86 ) ) ;
V_80:
F_57 ( V_23 , V_78 ) ;
return V_31 ;
}
void
F_58 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_43 . V_14 == NULL )
return;
if ( F_27 ( V_4 ) -> V_67 >= 5 ) {
F_59 ( F_60 ( V_2 -> V_43 . V_14 -> V_87 -> V_88 ) ) ;
F_61 ( V_2 -> V_43 . V_14 ) ;
}
F_62 ( & V_2 -> V_43 . V_14 -> V_89 ) ;
V_2 -> V_43 . V_14 = NULL ;
}
int
F_63 ( struct V_1 * V_2 )
{
int V_31 ;
if ( V_2 -> V_43 . V_14 )
return 0 ;
V_2 -> V_43 . V_14 = F_64 ( V_2 -> V_4 , 4096 ) ;
if ( V_2 -> V_43 . V_14 == NULL ) {
F_41 ( L_8 ) ;
V_31 = - V_90 ;
goto V_91;
}
V_31 = F_65 ( V_2 -> V_43 . V_14 , V_92 ) ;
if ( V_31 )
goto V_93;
V_31 = F_66 ( V_2 -> V_43 . V_14 , 4096 , 0 ) ;
if ( V_31 )
goto V_93;
V_2 -> V_43 . V_44 = F_55 ( V_2 -> V_43 . V_14 ) ;
V_2 -> V_43 . V_94 = F_67 ( F_60 ( V_2 -> V_43 . V_14 -> V_87 -> V_88 ) ) ;
if ( V_2 -> V_43 . V_94 == NULL ) {
V_31 = - V_90 ;
goto V_95;
}
F_68 ( L_9 ,
V_2 -> V_76 , V_2 -> V_43 . V_44 ) ;
return 0 ;
V_95:
F_61 ( V_2 -> V_43 . V_14 ) ;
V_93:
F_62 ( & V_2 -> V_43 . V_14 -> V_89 ) ;
V_91:
return V_31 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_7 * V_96 )
{
int V_31 , V_97 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_98 * V_99 = & V_23 -> V_100 ;
if ( F_70 ( V_99 -> V_101 == 0 ) )
return 0 ;
V_2 -> V_102 = true ;
V_31 = F_71 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_8 ( V_2 , ( V_99 -> V_101 * 2 + 2 ) ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_19 ( V_99 -> V_101 ) ) ;
for ( V_97 = 0 ; V_97 < V_99 -> V_101 ; V_97 ++ ) {
F_9 ( V_2 , V_99 -> V_103 [ V_97 ] . V_70 ) ;
F_9 ( V_2 , V_99 -> V_103 [ V_97 ] . V_59 ) ;
}
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
V_2 -> V_102 = true ;
V_31 = F_71 ( V_2 ) ;
if ( V_31 )
return V_31 ;
F_68 ( L_10 , V_99 -> V_101 ) ;
return 0 ;
}
static int F_72 ( struct V_22 * V_23 ,
const T_1 V_70 , const T_1 V_104 , const T_1 V_105 )
{
const T_1 V_106 = V_23 -> V_100 . V_101 ;
if ( F_70 ( V_106 >= V_107 ) )
return - V_108 ;
V_23 -> V_100 . V_103 [ V_106 ] . V_70 = V_70 ;
V_23 -> V_100 . V_103 [ V_106 ] . V_59 = V_105 ;
V_23 -> V_100 . V_103 [ V_106 ] . V_104 = V_104 ;
V_23 -> V_100 . V_101 ++ ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
F_74 ( V_109 ,
V_110 |
V_111 ) ;
F_74 ( V_112 ,
V_113 ) ;
F_74 ( V_114 ,
V_115 ) ;
F_74 ( V_116 ,
V_117 |
( F_75 ( V_4 ) ? V_118 : 0 ) ) ;
F_74 ( V_119 ,
V_120 ) ;
F_76 ( V_121 ,
V_122 ,
V_123 ) ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
F_74 ( V_109 ,
V_110 |
V_111 ) ;
F_74 ( V_116 ,
V_117 |
V_124 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
F_70 ( V_2 -> V_13 != V_125 ) ;
V_23 -> V_100 . V_101 = 0 ;
if ( F_79 ( V_4 ) )
return F_73 ( V_2 ) ;
if ( F_80 ( V_4 ) )
return F_77 ( V_2 ) ;
return 0 ;
}
static int F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
int V_31 = F_48 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( F_27 ( V_4 ) -> V_67 >= 4 && F_27 ( V_4 ) -> V_67 < 7 )
F_33 ( V_126 , F_38 ( V_127 ) ) ;
if ( F_27 ( V_4 ) -> V_67 >= 6 && F_27 ( V_4 ) -> V_67 < 9 )
F_33 ( V_126 , F_38 ( V_128 ) ) ;
if ( F_27 ( V_4 ) -> V_67 == 6 )
F_33 ( V_129 ,
F_38 ( V_130 ) ) ;
if ( F_82 ( V_4 ) )
F_33 ( V_131 ,
F_38 ( V_130 ) |
F_38 ( V_132 ) ) ;
if ( F_27 ( V_4 ) -> V_67 >= 5 ) {
V_31 = F_63 ( V_2 ) ;
if ( V_31 )
return V_31 ;
}
if ( F_83 ( V_4 ) ) {
F_33 ( V_133 ,
F_47 ( V_134 ) ) ;
}
if ( F_27 ( V_4 ) -> V_67 >= 6 )
F_33 ( V_135 , F_38 ( V_136 ) ) ;
if ( F_84 ( V_4 ) )
F_85 ( V_2 , ~ F_86 ( V_4 ) ) ;
return F_78 ( V_2 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
if ( V_23 -> V_137 ) {
F_61 ( V_23 -> V_137 ) ;
F_62 ( & V_23 -> V_137 -> V_89 ) ;
V_23 -> V_137 = NULL ;
}
F_58 ( V_2 ) ;
}
static int F_88 ( struct V_1 * V_138 ,
unsigned int V_139 )
{
#define F_89 8
struct V_3 * V_4 = V_138 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_140 ;
int V_97 , V_31 , V_141 ;
V_141 = F_90 ( F_27 ( V_4 ) -> V_142 ) ;
V_139 += ( V_141 - 1 ) * F_89 ;
#undef F_89
V_31 = F_8 ( V_138 , V_139 ) ;
if ( V_31 )
return V_31 ;
F_91 (waiter, dev_priv, i) {
T_2 V_44 = V_138 -> V_143 . V_144 [ V_97 ] ;
if ( V_44 == V_145 )
continue;
F_9 ( V_138 , F_15 ( 6 ) ) ;
F_9 ( V_138 , V_64 |
V_49 |
V_146 ) ;
F_9 ( V_138 , F_92 ( V_44 ) ) ;
F_9 ( V_138 , F_93 ( V_44 ) ) ;
F_9 ( V_138 , V_138 -> V_147 ) ;
F_9 ( V_138 , 0 ) ;
F_9 ( V_138 , V_148 |
F_94 ( V_140 -> V_13 ) ) ;
F_9 ( V_138 , 0 ) ;
}
return 0 ;
}
static int F_95 ( struct V_1 * V_138 ,
unsigned int V_139 )
{
#define F_89 6
struct V_3 * V_4 = V_138 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_140 ;
int V_97 , V_31 , V_141 ;
V_141 = F_90 ( F_27 ( V_4 ) -> V_142 ) ;
V_139 += ( V_141 - 1 ) * F_89 ;
#undef F_89
V_31 = F_8 ( V_138 , V_139 ) ;
if ( V_31 )
return V_31 ;
F_91 (waiter, dev_priv, i) {
T_2 V_44 = V_138 -> V_143 . V_144 [ V_97 ] ;
if ( V_44 == V_145 )
continue;
F_9 ( V_138 , ( V_149 + 1 ) |
V_150 ) ;
F_9 ( V_138 , F_92 ( V_44 ) |
V_151 ) ;
F_9 ( V_138 , F_93 ( V_44 ) ) ;
F_9 ( V_138 , V_138 -> V_147 ) ;
F_9 ( V_138 , V_148 |
F_94 ( V_140 -> V_13 ) ) ;
F_9 ( V_138 , 0 ) ;
}
return 0 ;
}
static int F_96 ( struct V_1 * V_138 ,
unsigned int V_139 )
{
struct V_3 * V_4 = V_138 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_152 ;
int V_97 , V_31 , V_141 ;
#define F_89 3
V_141 = F_90 ( F_27 ( V_4 ) -> V_142 ) ;
V_139 += F_97 ( ( V_141 - 1 ) * F_89 , 2 ) ;
#undef F_89
V_31 = F_8 ( V_138 , V_139 ) ;
if ( V_31 )
return V_31 ;
F_91 (useless, dev_priv, i) {
T_1 V_153 = V_138 -> V_143 . V_154 . signal [ V_97 ] ;
if ( V_153 != V_155 ) {
F_9 ( V_138 , F_19 ( 1 ) ) ;
F_9 ( V_138 , V_153 ) ;
F_9 ( V_138 , V_138 -> V_147 ) ;
}
}
if ( V_141 % 2 == 0 )
F_9 ( V_138 , V_37 ) ;
return 0 ;
}
static int
F_98 ( struct V_1 * V_2 )
{
int V_31 ;
if ( V_2 -> V_143 . signal )
V_31 = V_2 -> V_143 . signal ( V_2 , 4 ) ;
else
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_156 ) ;
F_9 ( V_2 , V_157 << V_158 ) ;
F_9 ( V_2 , V_2 -> V_147 ) ;
F_9 ( V_2 , V_159 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static inline bool F_99 ( struct V_3 * V_4 ,
T_1 V_160 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
return V_23 -> V_161 < V_160 ;
}
static int
F_100 ( struct V_1 * V_140 ,
struct V_1 * V_138 ,
T_1 V_160 )
{
struct V_22 * V_23 = V_140 -> V_4 -> V_24 ;
int V_31 ;
V_31 = F_8 ( V_140 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_140 , V_162 |
V_163 |
V_164 |
V_165 ) ;
F_9 ( V_140 , V_160 ) ;
F_9 ( V_140 ,
F_92 ( F_101 ( V_140 , V_138 -> V_13 ) ) ) ;
F_9 ( V_140 ,
F_93 ( F_101 ( V_140 , V_138 -> V_13 ) ) ) ;
F_10 ( V_140 ) ;
return 0 ;
}
static int
F_102 ( struct V_1 * V_140 ,
struct V_1 * V_138 ,
T_1 V_160 )
{
T_1 V_166 = V_167 |
V_168 |
V_169 ;
T_1 V_170 = V_138 -> V_143 . V_154 . V_171 [ V_140 -> V_13 ] ;
int V_31 ;
V_160 -= 1 ;
F_70 ( V_170 == V_145 ) ;
V_31 = F_8 ( V_140 , 4 ) ;
if ( V_31 )
return V_31 ;
if ( F_103 ( ! F_99 ( V_140 -> V_4 , V_160 ) ) ) {
F_9 ( V_140 , V_166 | V_170 ) ;
F_9 ( V_140 , V_160 ) ;
F_9 ( V_140 , 0 ) ;
F_9 ( V_140 , V_37 ) ;
} else {
F_9 ( V_140 , V_37 ) ;
F_9 ( V_140 , V_37 ) ;
F_9 ( V_140 , V_37 ) ;
F_9 ( V_140 , V_37 ) ;
}
F_10 ( V_140 ) ;
return 0 ;
}
static int
F_104 ( struct V_1 * V_2 )
{
T_1 V_42 = V_2 -> V_43 . V_44 + 2 * V_45 ;
int V_31 ;
V_31 = F_8 ( V_2 , 32 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 4 ) | V_49 |
V_172 |
V_55 ) ;
F_9 ( V_2 , V_2 -> V_43 . V_44 | V_48 ) ;
F_9 ( V_2 , V_2 -> V_147 ) ;
F_9 ( V_2 , 0 ) ;
F_105 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_105 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_105 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_105 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_105 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_105 ( V_2 , V_42 ) ;
F_9 ( V_2 , F_15 ( 4 ) | V_49 |
V_172 |
V_55 |
V_173 ) ;
F_9 ( V_2 , V_2 -> V_43 . V_44 | V_48 ) ;
F_9 ( V_2 , V_2 -> V_147 ) ;
F_9 ( V_2 , 0 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static T_1
F_106 ( struct V_1 * V_2 , bool V_174 )
{
if ( ! V_174 ) {
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
F_107 ( F_29 ( V_2 -> V_68 ) ) ;
}
return F_108 ( V_2 , V_157 ) ;
}
static T_1
F_109 ( struct V_1 * V_2 , bool V_174 )
{
return F_108 ( V_2 , V_157 ) ;
}
static void
F_110 ( struct V_1 * V_2 , T_1 V_160 )
{
F_111 ( V_2 , V_157 , V_160 ) ;
}
static T_1
F_112 ( struct V_1 * V_2 , bool V_174 )
{
return V_2 -> V_43 . V_94 [ 0 ] ;
}
static void
F_113 ( struct V_1 * V_2 , T_1 V_160 )
{
V_2 -> V_43 . V_94 [ 0 ] = V_160 ;
}
static bool
F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( F_70 ( ! F_115 ( V_23 ) ) )
return false ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( V_2 -> V_176 ++ == 0 )
F_117 ( V_23 , V_2 -> V_177 ) ;
F_118 ( & V_23 -> V_175 , V_50 ) ;
return true ;
}
static void
F_119 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( -- V_2 -> V_176 == 0 )
F_120 ( V_23 , V_2 -> V_177 ) ;
F_118 ( & V_23 -> V_175 , V_50 ) ;
}
static bool
F_121 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! F_115 ( V_23 ) )
return false ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( V_2 -> V_176 ++ == 0 ) {
V_23 -> V_178 &= ~ V_2 -> V_177 ;
F_33 ( V_179 , V_23 -> V_178 ) ;
F_107 ( V_179 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
return true ;
}
static void
F_122 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( -- V_2 -> V_176 == 0 ) {
V_23 -> V_178 |= V_2 -> V_177 ;
F_33 ( V_179 , V_23 -> V_178 ) ;
F_107 ( V_179 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
}
static bool
F_123 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! F_115 ( V_23 ) )
return false ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( V_2 -> V_176 ++ == 0 ) {
V_23 -> V_178 &= ~ V_2 -> V_177 ;
F_124 ( V_179 , V_23 -> V_178 ) ;
F_125 ( V_179 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
return true ;
}
static void
F_126 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( -- V_2 -> V_176 == 0 ) {
V_23 -> V_178 |= V_2 -> V_177 ;
F_124 ( V_179 , V_23 -> V_178 ) ;
F_125 ( V_179 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
T_1 V_180 = 0 ;
if ( F_82 ( V_4 ) ) {
switch ( V_2 -> V_13 ) {
case V_125 :
V_180 = V_181 ;
break;
case V_182 :
V_180 = V_183 ;
break;
case V_184 :
case V_185 :
V_180 = V_186 ;
break;
case V_187 :
V_180 = V_188 ;
break;
}
} else if ( F_83 ( V_2 -> V_4 ) ) {
V_180 = F_127 ( V_2 -> V_68 ) ;
} else {
V_180 = F_128 ( V_2 -> V_68 ) ;
}
F_33 ( V_180 , ( T_1 ) V_2 -> V_189 . V_190 ) ;
F_107 ( V_180 ) ;
if ( F_27 ( V_4 ) -> V_67 >= 6 && F_27 ( V_4 ) -> V_67 < 8 ) {
T_1 V_103 = F_129 ( V_2 -> V_68 ) ;
F_70 ( ( F_40 ( V_2 ) & V_75 ) == 0 ) ;
F_33 ( V_103 ,
F_38 ( V_191 |
V_192 ) ) ;
if ( F_39 ( ( F_31 ( V_103 ) & V_192 ) == 0 ,
1000 ) )
F_41 ( L_11 ,
V_2 -> V_76 ) ;
}
}
static int
F_130 ( struct V_1 * V_2 ,
T_1 V_28 ,
T_1 V_29 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_32 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_131 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_156 ) ;
F_9 ( V_2 , V_157 << V_158 ) ;
F_9 ( V_2 , V_2 -> V_147 ) ;
F_9 ( V_2 , V_159 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool
F_132 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( F_70 ( ! F_115 ( V_23 ) ) )
return false ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( V_2 -> V_176 ++ == 0 ) {
if ( F_84 ( V_4 ) && V_2 -> V_13 == V_125 )
F_85 ( V_2 ,
~ ( V_2 -> V_177 |
F_86 ( V_4 ) ) ) ;
else
F_85 ( V_2 , ~ V_2 -> V_177 ) ;
F_117 ( V_23 , V_2 -> V_177 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
return true ;
}
static void
F_133 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( -- V_2 -> V_176 == 0 ) {
if ( F_84 ( V_4 ) && V_2 -> V_13 == V_125 )
F_85 ( V_2 , ~ F_86 ( V_4 ) ) ;
else
F_85 ( V_2 , ~ 0 ) ;
F_120 ( V_23 , V_2 -> V_177 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
}
static bool
F_134 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( F_70 ( ! F_115 ( V_23 ) ) )
return false ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( V_2 -> V_176 ++ == 0 ) {
F_85 ( V_2 , ~ V_2 -> V_177 ) ;
F_135 ( V_23 , V_2 -> V_177 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
return true ;
}
static void
F_136 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( -- V_2 -> V_176 == 0 ) {
F_85 ( V_2 , ~ 0 ) ;
F_137 ( V_23 , V_2 -> V_177 ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
}
static bool
F_138 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( F_70 ( ! F_115 ( V_23 ) ) )
return false ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( V_2 -> V_176 ++ == 0 ) {
if ( F_84 ( V_4 ) && V_2 -> V_13 == V_125 ) {
F_85 ( V_2 ,
~ ( V_2 -> V_177 |
V_193 ) ) ;
} else {
F_85 ( V_2 , ~ V_2 -> V_177 ) ;
}
F_107 ( F_139 ( V_2 -> V_68 ) ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
return true ;
}
static void
F_140 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_116 ( & V_23 -> V_175 , V_50 ) ;
if ( -- V_2 -> V_176 == 0 ) {
if ( F_84 ( V_4 ) && V_2 -> V_13 == V_125 ) {
F_85 ( V_2 ,
~ V_193 ) ;
} else {
F_85 ( V_2 , ~ 0 ) ;
}
F_107 ( F_139 ( V_2 -> V_68 ) ) ;
}
F_118 ( & V_23 -> V_175 , V_50 ) ;
}
static int
F_141 ( struct V_1 * V_2 ,
T_2 V_194 , T_1 V_195 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 ,
V_196 |
V_197 |
( V_50 & V_198 ? 0 : V_199 ) ) ;
F_9 ( V_2 , V_194 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_142 ( struct V_1 * V_2 ,
T_2 V_194 , T_1 V_200 ,
unsigned V_50 )
{
T_1 V_201 = V_2 -> V_43 . V_44 ;
int V_31 ;
V_31 = F_8 ( V_2 , 6 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_202 | V_203 ) ;
F_9 ( V_2 , V_204 | V_205 | 4096 ) ;
F_9 ( V_2 , V_206 << 16 | 4 ) ;
F_9 ( V_2 , V_201 ) ;
F_9 ( V_2 , 0xdeadbeef ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
if ( ( V_50 & V_207 ) == 0 ) {
if ( V_200 > V_208 )
return - V_108 ;
V_31 = F_8 ( V_2 , 6 + 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_209 | V_203 ) ;
F_9 ( V_2 , V_204 | V_210 | 4096 ) ;
F_9 ( V_2 , F_143 ( V_200 , 4096 ) << 16 | 4096 ) ;
F_9 ( V_2 , V_201 ) ;
F_9 ( V_2 , 4096 ) ;
F_9 ( V_2 , V_194 ) ;
F_9 ( V_2 , V_32 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
V_194 = V_201 ;
}
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_211 ) ;
F_9 ( V_2 , V_194 | ( V_50 & V_198 ? 0 : V_212 ) ) ;
F_9 ( V_2 , V_194 + V_200 - 8 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_144 ( struct V_1 * V_2 ,
T_2 V_194 , T_1 V_200 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_196 | V_197 ) ;
F_9 ( V_2 , V_194 | ( V_50 & V_198 ? 0 : V_212 ) ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static void F_145 ( struct V_1 * V_2 )
{
struct V_77 * V_14 ;
V_14 = V_2 -> V_189 . V_14 ;
if ( V_14 == NULL )
return;
F_59 ( F_60 ( V_14 -> V_87 -> V_88 ) ) ;
F_61 ( V_14 ) ;
F_62 ( & V_14 -> V_89 ) ;
V_2 -> V_189 . V_14 = NULL ;
}
static int F_146 ( struct V_1 * V_2 )
{
struct V_77 * V_14 ;
if ( ( V_14 = V_2 -> V_189 . V_14 ) == NULL ) {
unsigned V_50 ;
int V_31 ;
V_14 = F_64 ( V_2 -> V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_41 ( L_12 ) ;
return - V_90 ;
}
V_31 = F_65 ( V_14 , V_92 ) ;
if ( V_31 )
goto V_93;
V_50 = 0 ;
if ( ! F_147 ( V_2 -> V_4 ) )
V_50 |= V_213 ;
V_31 = F_66 ( V_14 , 4096 , V_50 ) ;
if ( V_31 ) {
V_93:
F_62 ( & V_14 -> V_89 ) ;
return V_31 ;
}
V_2 -> V_189 . V_14 = V_14 ;
}
V_2 -> V_189 . V_190 = F_55 ( V_14 ) ;
V_2 -> V_189 . V_214 = F_67 ( F_60 ( V_14 -> V_87 -> V_88 ) ) ;
memset ( V_2 -> V_189 . V_214 , 0 , V_81 ) ;
F_68 ( L_13 ,
V_2 -> V_76 , V_2 -> V_189 . V_190 ) ;
return 0 ;
}
static int F_148 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
if ( ! V_23 -> V_71 ) {
V_23 -> V_71 =
F_149 ( V_2 -> V_4 , V_81 , V_81 ) ;
if ( ! V_23 -> V_71 )
return - V_90 ;
}
V_2 -> V_189 . V_214 = V_23 -> V_71 -> V_215 ;
memset ( V_2 -> V_189 . V_214 , 0 , V_81 ) ;
return 0 ;
}
void F_150 ( struct V_10 * V_11 )
{
F_151 ( V_11 -> V_216 ) ;
V_11 -> V_216 = NULL ;
F_61 ( V_11 -> V_14 ) ;
}
int F_152 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_22 * V_23 = F_35 ( V_4 ) ;
struct V_77 * V_14 = V_11 -> V_14 ;
int V_31 ;
V_31 = F_66 ( V_14 , V_81 , V_213 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_153 ( V_14 , true ) ;
if ( V_31 ) {
F_61 ( V_14 ) ;
return V_31 ;
}
V_11 -> V_216 = F_154 ( V_23 -> V_217 . V_218 +
F_55 ( V_14 ) , V_11 -> V_18 ) ;
if ( V_11 -> V_216 == NULL ) {
F_61 ( V_14 ) ;
return - V_219 ;
}
return 0 ;
}
void F_155 ( struct V_10 * V_11 )
{
F_62 ( & V_11 -> V_14 -> V_89 ) ;
V_11 -> V_14 = NULL ;
}
int F_156 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_77 * V_14 ;
V_14 = NULL ;
if ( ! F_147 ( V_4 ) )
V_14 = F_157 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
V_14 = F_64 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
return - V_90 ;
V_14 -> V_220 = 1 ;
V_11 -> V_14 = V_14 ;
return 0 ;
}
static int F_158 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_31 ;
if ( V_11 == NULL ) {
V_11 = F_159 ( sizeof( * V_11 ) , V_221 ) ;
if ( ! V_11 )
return - V_90 ;
V_2 -> V_15 = V_11 ;
}
V_2 -> V_4 = V_4 ;
F_160 ( & V_2 -> V_222 ) ;
F_160 ( & V_2 -> V_223 ) ;
F_160 ( & V_2 -> V_224 ) ;
V_11 -> V_18 = 32 * V_81 ;
V_11 -> V_2 = V_2 ;
memset ( V_2 -> V_143 . V_225 , 0 , sizeof( V_2 -> V_143 . V_225 ) ) ;
F_161 ( & V_2 -> V_226 ) ;
if ( F_52 ( V_4 ) ) {
V_31 = F_146 ( V_2 ) ;
if ( V_31 )
goto error;
} else {
F_162 ( V_2 -> V_13 != V_125 ) ;
V_31 = F_148 ( V_2 ) ;
if ( V_31 )
goto error;
}
if ( V_11 -> V_14 == NULL ) {
V_31 = F_156 ( V_4 , V_11 ) ;
if ( V_31 ) {
F_41 ( L_14 ,
V_2 -> V_76 , V_31 ) ;
goto error;
}
V_31 = F_152 ( V_4 , V_11 ) ;
if ( V_31 ) {
F_41 ( L_15 ,
V_2 -> V_76 , V_31 ) ;
F_155 ( V_11 ) ;
goto error;
}
}
V_11 -> V_227 = V_11 -> V_18 ;
if ( F_163 ( V_4 ) || F_164 ( V_4 ) )
V_11 -> V_227 -= 2 * V_45 ;
V_31 = F_165 ( V_2 ) ;
if ( V_31 )
goto error;
V_31 = V_2 -> V_228 ( V_2 ) ;
if ( V_31 )
goto error;
return 0 ;
error:
F_166 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_31 ;
}
void F_167 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_10 * V_11 ;
if ( ! F_1 ( V_2 ) )
return;
V_23 = F_35 ( V_2 -> V_4 ) ;
V_11 = V_2 -> V_15 ;
F_168 ( V_2 ) ;
F_70 ( ! F_36 ( V_2 -> V_4 ) && ( F_40 ( V_2 ) & V_75 ) == 0 ) ;
F_150 ( V_11 ) ;
F_155 ( V_11 ) ;
V_2 -> V_229 = NULL ;
V_2 -> V_147 = 0 ;
if ( V_2 -> V_230 )
V_2 -> V_230 ( V_2 ) ;
F_145 ( V_2 ) ;
F_169 ( V_2 ) ;
F_166 ( V_11 ) ;
V_2 -> V_15 = NULL ;
}
static int F_170 ( struct V_1 * V_2 , int V_231 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_232 * V_233 ;
T_1 V_160 = 0 ;
int V_31 ;
if ( V_11 -> V_85 != - 1 ) {
V_11 -> V_16 = V_11 -> V_85 ;
V_11 -> V_85 = - 1 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
if ( V_11 -> V_19 >= V_231 )
return 0 ;
}
F_171 (request, &ring->request_list, list) {
if ( F_2 ( V_233 -> V_17 , V_11 -> V_17 ,
V_11 -> V_18 ) >= V_231 ) {
V_160 = V_233 -> V_160 ;
break;
}
}
if ( V_160 == 0 )
return - V_108 ;
V_31 = F_172 ( V_2 , V_160 ) ;
if ( V_31 )
return V_31 ;
F_173 ( V_2 ) ;
V_11 -> V_16 = V_11 -> V_85 ;
V_11 -> V_85 = - 1 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
return 0 ;
}
static int F_174 ( struct V_1 * V_2 , int V_231 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_10 * V_11 = V_2 -> V_15 ;
unsigned long V_234 ;
int V_31 ;
V_31 = F_170 ( V_2 , V_231 ) ;
if ( V_31 != - V_108 )
return V_31 ;
F_6 ( V_2 ) ;
V_234 = V_235 + 60 * V_236 ;
F_175 ( V_2 ) ;
do {
V_11 -> V_16 = F_42 ( V_2 ) ;
V_11 -> V_19 = F_3 ( V_11 ) ;
if ( V_11 -> V_19 >= V_231 ) {
V_31 = 0 ;
break;
}
F_176 ( 1 ) ;
if ( V_23 -> V_237 . V_238 && F_177 ( V_239 ) ) {
V_31 = - V_240 ;
break;
}
V_31 = F_178 ( & V_23 -> V_25 ,
V_23 -> V_237 . V_238 ) ;
if ( V_31 )
break;
if ( F_179 ( V_235 , V_234 ) ) {
V_31 = - V_241 ;
break;
}
} while ( 1 );
F_180 ( V_2 ) ;
return V_31 ;
}
static int F_181 ( struct V_1 * V_2 )
{
T_3 T_4 * V_242 ;
struct V_10 * V_11 = V_2 -> V_15 ;
int V_243 = V_11 -> V_18 - V_11 -> V_17 ;
if ( V_11 -> V_19 < V_243 ) {
int V_31 = F_174 ( V_2 , V_243 ) ;
if ( V_31 )
return V_31 ;
}
V_242 = V_11 -> V_216 + V_11 -> V_17 ;
V_243 /= 4 ;
while ( V_243 -- )
F_182 ( V_37 , V_242 ++ ) ;
V_11 -> V_17 = 0 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
return 0 ;
}
int F_183 ( struct V_1 * V_2 )
{
T_1 V_160 ;
int V_31 ;
if ( V_2 -> V_147 ) {
V_31 = F_184 ( V_2 , NULL ) ;
if ( V_31 )
return V_31 ;
}
if ( F_185 ( & V_2 -> V_223 ) )
return 0 ;
V_160 = F_186 ( V_2 -> V_223 . V_244 ,
struct V_232 ,
V_245 ) -> V_160 ;
return F_172 ( V_2 , V_160 ) ;
}
static int
F_187 ( struct V_1 * V_2 )
{
if ( V_2 -> V_147 )
return 0 ;
if ( V_2 -> V_229 == NULL ) {
struct V_232 * V_233 ;
V_233 = F_188 ( sizeof( * V_233 ) , V_221 ) ;
if ( V_233 == NULL )
return - V_90 ;
V_2 -> V_229 = V_233 ;
}
return F_189 ( V_2 -> V_4 , & V_2 -> V_147 ) ;
}
static int F_190 ( struct V_1 * V_2 ,
int V_246 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_31 ;
if ( F_191 ( V_11 -> V_17 + V_246 > V_11 -> V_227 ) ) {
V_31 = F_181 ( V_2 ) ;
if ( F_191 ( V_31 ) )
return V_31 ;
}
if ( F_191 ( V_11 -> V_19 < V_246 ) ) {
V_31 = F_174 ( V_2 , V_246 ) ;
if ( F_191 ( V_31 ) )
return V_31 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
int V_139 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
int V_31 ;
V_31 = F_178 ( & V_23 -> V_25 ,
V_23 -> V_237 . V_238 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_190 ( V_2 , V_139 * sizeof( T_3 ) ) ;
if ( V_31 )
return V_31 ;
V_31 = F_187 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_15 -> V_19 -= V_139 * sizeof( T_3 ) ;
return 0 ;
}
int F_192 ( struct V_1 * V_2 )
{
int V_139 = ( V_2 -> V_15 -> V_17 & ( V_45 - 1 ) ) / sizeof( T_3 ) ;
int V_31 ;
if ( V_139 == 0 )
return 0 ;
V_139 = V_45 / sizeof( T_3 ) - V_139 ;
V_31 = F_8 ( V_2 , V_139 ) ;
if ( V_31 )
return V_31 ;
while ( V_139 -- )
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
void F_193 ( struct V_1 * V_2 , T_1 V_160 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
F_162 ( V_2 -> V_147 ) ;
if ( F_27 ( V_4 ) -> V_67 == 6 || F_27 ( V_4 ) -> V_67 == 7 ) {
F_33 ( F_194 ( V_2 -> V_68 ) , 0 ) ;
F_33 ( F_195 ( V_2 -> V_68 ) , 0 ) ;
if ( F_196 ( V_4 ) )
F_33 ( F_197 ( V_2 -> V_68 ) , 0 ) ;
}
V_2 -> V_247 ( V_2 , V_160 ) ;
V_2 -> V_86 . V_160 = V_160 ;
}
static void F_198 ( struct V_1 * V_2 ,
T_1 V_59 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
F_33 ( V_248 ,
F_38 ( V_249 ) ) ;
F_199 ( V_250 , 0x0 ) ;
if ( F_39 ( ( F_31 ( V_248 ) &
V_251 ) == 0 ,
50 ) )
F_41 ( L_16 ) ;
F_25 ( V_2 , V_59 ) ;
F_107 ( F_200 ( V_2 -> V_68 ) ) ;
F_33 ( V_248 ,
F_47 ( V_249 ) ) ;
}
static int F_201 ( struct V_1 * V_2 ,
T_1 V_252 , T_1 V_253 )
{
T_3 V_30 ;
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
V_30 = V_149 ;
if ( F_27 ( V_2 -> V_4 ) -> V_67 >= 8 )
V_30 += 1 ;
if ( V_252 & V_254 )
V_30 |= V_255 | V_256 |
V_257 | V_150 ;
F_9 ( V_2 , V_30 ) ;
F_9 ( V_2 , V_258 | V_151 ) ;
if ( F_27 ( V_2 -> V_4 ) -> V_67 >= 8 ) {
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
} else {
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , V_37 ) ;
}
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_202 ( struct V_1 * V_2 ,
T_2 V_194 , T_1 V_200 ,
unsigned V_50 )
{
bool V_259 = F_203 ( V_2 -> V_4 ) && ! ( V_50 & V_198 ) ;
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_260 | ( V_259 << 8 ) ) ;
F_9 ( V_2 , F_92 ( V_194 ) ) ;
F_9 ( V_2 , F_93 ( V_194 ) ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_204 ( struct V_1 * V_2 ,
T_2 V_194 , T_1 V_200 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 ,
V_196 |
( V_50 & V_198 ?
0 : V_261 | V_262 ) ) ;
F_9 ( V_2 , V_194 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_205 ( struct V_1 * V_2 ,
T_2 V_194 , T_1 V_200 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 ,
V_196 |
( V_50 & V_198 ? 0 : V_199 ) ) ;
F_9 ( V_2 , V_194 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_206 ( struct V_1 * V_2 ,
T_1 V_252 , T_1 V_253 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
T_3 V_30 ;
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
V_30 = V_149 ;
if ( F_27 ( V_2 -> V_4 ) -> V_67 >= 8 )
V_30 += 1 ;
if ( V_252 & V_33 )
V_30 |= V_255 | V_257 |
V_150 ;
F_9 ( V_2 , V_30 ) ;
F_9 ( V_2 , V_258 | V_151 ) ;
if ( F_27 ( V_2 -> V_4 ) -> V_67 >= 8 ) {
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
} else {
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , V_37 ) ;
}
F_10 ( V_2 ) ;
if ( ! V_252 && V_253 ) {
if ( F_82 ( V_4 ) )
return F_18 ( V_2 , V_263 ) ;
else if ( F_79 ( V_4 ) )
V_23 -> V_264 . V_265 = true ;
}
return 0 ;
}
int F_207 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_125 ] ;
struct V_77 * V_14 ;
int V_31 ;
V_2 -> V_76 = L_17 ;
V_2 -> V_13 = V_125 ;
V_2 -> V_68 = V_266 ;
if ( F_27 ( V_4 ) -> V_67 >= 8 ) {
if ( F_208 ( V_4 ) ) {
V_14 = F_64 ( V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_41 ( L_18 ) ;
V_5 . V_267 = 0 ;
} else {
F_65 ( V_14 , V_92 ) ;
V_31 = F_66 ( V_14 , 0 , V_268 ) ;
if ( V_31 != 0 ) {
F_62 ( & V_14 -> V_89 ) ;
F_41 ( L_19 ) ;
V_5 . V_267 = 0 ;
} else
V_23 -> V_137 = V_14 ;
}
}
V_2 -> V_269 = F_69 ;
V_2 -> V_270 = F_98 ;
V_2 -> V_253 = F_23 ;
V_2 -> V_271 = F_138 ;
V_2 -> V_272 = F_140 ;
V_2 -> V_177 = V_273 ;
V_2 -> V_274 = F_106 ;
V_2 -> V_247 = F_110 ;
if ( F_208 ( V_4 ) ) {
F_70 ( ! V_23 -> V_137 ) ;
V_2 -> V_143 . V_275 = F_100 ;
V_2 -> V_143 . signal = F_88 ;
V_276 ;
}
} else if ( F_27 ( V_4 ) -> V_67 >= 6 ) {
V_2 -> V_270 = F_98 ;
V_2 -> V_253 = F_21 ;
if ( F_27 ( V_4 ) -> V_67 == 6 )
V_2 -> V_253 = F_16 ;
V_2 -> V_271 = F_132 ;
V_2 -> V_272 = F_133 ;
V_2 -> V_177 = V_273 ;
V_2 -> V_274 = F_106 ;
V_2 -> V_247 = F_110 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . V_275 = F_102 ;
V_2 -> V_143 . signal = F_96 ;
V_2 -> V_143 . V_154 . V_171 [ V_125 ] = V_145 ;
V_2 -> V_143 . V_154 . V_171 [ V_185 ] = V_277 ;
V_2 -> V_143 . V_154 . V_171 [ V_182 ] = V_278 ;
V_2 -> V_143 . V_154 . V_171 [ V_187 ] = V_279 ;
V_2 -> V_143 . V_154 . V_171 [ V_184 ] = V_145 ;
V_2 -> V_143 . V_154 . signal [ V_125 ] = V_155 ;
V_2 -> V_143 . V_154 . signal [ V_185 ] = V_280 ;
V_2 -> V_143 . V_154 . signal [ V_182 ] = V_281 ;
V_2 -> V_143 . V_154 . signal [ V_187 ] = V_282 ;
V_2 -> V_143 . V_154 . signal [ V_184 ] = V_155 ;
}
} else if ( F_13 ( V_4 ) ) {
V_2 -> V_270 = F_104 ;
V_2 -> V_253 = F_11 ;
V_2 -> V_274 = F_112 ;
V_2 -> V_247 = F_113 ;
V_2 -> V_271 = F_114 ;
V_2 -> V_272 = F_119 ;
V_2 -> V_177 = V_273 |
V_283 ;
} else {
V_2 -> V_270 = F_131 ;
if ( F_27 ( V_4 ) -> V_67 < 4 )
V_2 -> V_253 = F_7 ;
else
V_2 -> V_253 = F_11 ;
V_2 -> V_274 = F_109 ;
V_2 -> V_247 = F_110 ;
if ( F_36 ( V_4 ) ) {
V_2 -> V_271 = F_123 ;
V_2 -> V_272 = F_126 ;
} else {
V_2 -> V_271 = F_121 ;
V_2 -> V_272 = F_122 ;
}
V_2 -> V_177 = V_284 ;
}
V_2 -> V_27 = F_24 ;
if ( F_209 ( V_4 ) )
V_2 -> V_285 = F_204 ;
else if ( F_210 ( V_4 ) )
V_2 -> V_285 = F_202 ;
else if ( F_27 ( V_4 ) -> V_67 >= 6 )
V_2 -> V_285 = F_205 ;
else if ( F_27 ( V_4 ) -> V_67 >= 4 )
V_2 -> V_285 = F_141 ;
else if ( F_163 ( V_4 ) || F_164 ( V_4 ) )
V_2 -> V_285 = F_142 ;
else
V_2 -> V_285 = F_144 ;
V_2 -> V_228 = F_81 ;
V_2 -> V_230 = F_87 ;
if ( F_211 ( V_4 ) ) {
V_14 = F_64 ( V_4 , V_286 ) ;
if ( V_14 == NULL ) {
F_41 ( L_20 ) ;
return - V_90 ;
}
V_31 = F_66 ( V_14 , 0 , 0 ) ;
if ( V_31 != 0 ) {
F_62 ( & V_14 -> V_89 ) ;
F_41 ( L_21 ) ;
return V_31 ;
}
V_2 -> V_43 . V_14 = V_14 ;
V_2 -> V_43 . V_44 = F_55 ( V_14 ) ;
}
return F_158 ( V_4 , V_2 ) ;
}
int F_212 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_185 ] ;
V_2 -> V_76 = L_22 ;
V_2 -> V_13 = V_185 ;
V_2 -> V_27 = F_24 ;
if ( F_27 ( V_4 ) -> V_67 >= 6 ) {
V_2 -> V_68 = V_287 ;
if ( F_83 ( V_4 ) )
V_2 -> V_27 = F_198 ;
V_2 -> V_253 = F_201 ;
V_2 -> V_270 = F_98 ;
V_2 -> V_274 = F_106 ;
V_2 -> V_247 = F_110 ;
if ( F_27 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_177 =
V_273 << V_288 ;
V_2 -> V_271 = F_138 ;
V_2 -> V_272 = F_140 ;
V_2 -> V_285 =
F_202 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . V_275 = F_100 ;
V_2 -> V_143 . signal = F_95 ;
V_276 ;
}
} else {
V_2 -> V_177 = V_289 ;
V_2 -> V_271 = F_132 ;
V_2 -> V_272 = F_133 ;
V_2 -> V_285 =
F_205 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . V_275 = F_102 ;
V_2 -> V_143 . signal = F_96 ;
V_2 -> V_143 . V_154 . V_171 [ V_125 ] = V_290 ;
V_2 -> V_143 . V_154 . V_171 [ V_185 ] = V_145 ;
V_2 -> V_143 . V_154 . V_171 [ V_182 ] = V_291 ;
V_2 -> V_143 . V_154 . V_171 [ V_187 ] = V_292 ;
V_2 -> V_143 . V_154 . V_171 [ V_184 ] = V_145 ;
V_2 -> V_143 . V_154 . signal [ V_125 ] = V_293 ;
V_2 -> V_143 . V_154 . signal [ V_185 ] = V_155 ;
V_2 -> V_143 . V_154 . signal [ V_182 ] = V_294 ;
V_2 -> V_143 . V_154 . signal [ V_187 ] = V_295 ;
V_2 -> V_143 . V_154 . signal [ V_184 ] = V_155 ;
}
}
} else {
V_2 -> V_68 = V_296 ;
V_2 -> V_253 = F_130 ;
V_2 -> V_270 = F_131 ;
V_2 -> V_274 = F_109 ;
V_2 -> V_247 = F_110 ;
if ( F_13 ( V_4 ) ) {
V_2 -> V_177 = V_297 ;
V_2 -> V_271 = F_114 ;
V_2 -> V_272 = F_119 ;
} else {
V_2 -> V_177 = V_298 ;
V_2 -> V_271 = F_121 ;
V_2 -> V_272 = F_122 ;
}
V_2 -> V_285 = F_141 ;
}
V_2 -> V_228 = F_48 ;
return F_158 ( V_4 , V_2 ) ;
}
int F_213 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_184 ] ;
if ( ( F_27 ( V_4 ) -> V_67 != 8 ) ) {
F_41 ( L_23 ) ;
return - V_219 ;
}
V_2 -> V_76 = L_24 ;
V_2 -> V_13 = V_184 ;
V_2 -> V_27 = F_24 ;
V_2 -> V_68 = V_299 ;
V_2 -> V_253 = F_201 ;
V_2 -> V_270 = F_98 ;
V_2 -> V_274 = F_106 ;
V_2 -> V_247 = F_110 ;
V_2 -> V_177 =
V_273 << V_300 ;
V_2 -> V_271 = F_138 ;
V_2 -> V_272 = F_140 ;
V_2 -> V_285 =
F_202 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . V_275 = F_100 ;
V_2 -> V_143 . signal = F_95 ;
V_276 ;
}
V_2 -> V_228 = F_48 ;
return F_158 ( V_4 , V_2 ) ;
}
int F_214 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_182 ] ;
V_2 -> V_76 = L_25 ;
V_2 -> V_13 = V_182 ;
V_2 -> V_68 = V_301 ;
V_2 -> V_27 = F_24 ;
V_2 -> V_253 = F_206 ;
V_2 -> V_270 = F_98 ;
V_2 -> V_274 = F_106 ;
V_2 -> V_247 = F_110 ;
if ( F_27 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_177 =
V_273 << V_302 ;
V_2 -> V_271 = F_138 ;
V_2 -> V_272 = F_140 ;
V_2 -> V_285 = F_202 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . V_275 = F_100 ;
V_2 -> V_143 . signal = F_95 ;
V_276 ;
}
} else {
V_2 -> V_177 = V_303 ;
V_2 -> V_271 = F_132 ;
V_2 -> V_272 = F_133 ;
V_2 -> V_285 = F_205 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . signal = F_96 ;
V_2 -> V_143 . V_275 = F_102 ;
V_2 -> V_143 . V_154 . V_171 [ V_125 ] = V_304 ;
V_2 -> V_143 . V_154 . V_171 [ V_185 ] = V_305 ;
V_2 -> V_143 . V_154 . V_171 [ V_182 ] = V_145 ;
V_2 -> V_143 . V_154 . V_171 [ V_187 ] = V_306 ;
V_2 -> V_143 . V_154 . V_171 [ V_184 ] = V_145 ;
V_2 -> V_143 . V_154 . signal [ V_125 ] = V_307 ;
V_2 -> V_143 . V_154 . signal [ V_185 ] = V_308 ;
V_2 -> V_143 . V_154 . signal [ V_182 ] = V_155 ;
V_2 -> V_143 . V_154 . signal [ V_187 ] = V_309 ;
V_2 -> V_143 . V_154 . signal [ V_184 ] = V_155 ;
}
}
V_2 -> V_228 = F_48 ;
return F_158 ( V_4 , V_2 ) ;
}
int F_215 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_187 ] ;
V_2 -> V_76 = L_26 ;
V_2 -> V_13 = V_187 ;
V_2 -> V_68 = V_310 ;
V_2 -> V_27 = F_24 ;
V_2 -> V_253 = F_206 ;
V_2 -> V_270 = F_98 ;
V_2 -> V_274 = F_106 ;
V_2 -> V_247 = F_110 ;
if ( F_27 ( V_4 ) -> V_67 >= 8 ) {
V_2 -> V_177 =
V_273 << V_311 ;
V_2 -> V_271 = F_138 ;
V_2 -> V_272 = F_140 ;
V_2 -> V_285 = F_202 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . V_275 = F_100 ;
V_2 -> V_143 . signal = F_95 ;
V_276 ;
}
} else {
V_2 -> V_177 = V_312 ;
V_2 -> V_271 = F_134 ;
V_2 -> V_272 = F_136 ;
V_2 -> V_285 = F_205 ;
if ( F_208 ( V_4 ) ) {
V_2 -> V_143 . V_275 = F_102 ;
V_2 -> V_143 . signal = F_96 ;
V_2 -> V_143 . V_154 . V_171 [ V_125 ] = V_313 ;
V_2 -> V_143 . V_154 . V_171 [ V_185 ] = V_314 ;
V_2 -> V_143 . V_154 . V_171 [ V_182 ] = V_315 ;
V_2 -> V_143 . V_154 . V_171 [ V_187 ] = V_145 ;
V_2 -> V_143 . V_154 . V_171 [ V_184 ] = V_145 ;
V_2 -> V_143 . V_154 . signal [ V_125 ] = V_316 ;
V_2 -> V_143 . V_154 . signal [ V_185 ] = V_317 ;
V_2 -> V_143 . V_154 . signal [ V_182 ] = V_318 ;
V_2 -> V_143 . V_154 . signal [ V_187 ] = V_155 ;
V_2 -> V_143 . V_154 . signal [ V_184 ] = V_155 ;
}
}
V_2 -> V_228 = F_48 ;
return F_158 ( V_4 , V_2 ) ;
}
int
F_71 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! V_2 -> V_102 )
return 0 ;
V_31 = V_2 -> V_253 ( V_2 , 0 , V_254 ) ;
if ( V_31 )
return V_31 ;
F_216 ( V_2 , 0 , V_254 ) ;
V_2 -> V_102 = false ;
return 0 ;
}
int
F_217 ( struct V_1 * V_2 )
{
T_3 V_29 ;
int V_31 ;
V_29 = 0 ;
if ( V_2 -> V_102 )
V_29 = V_254 ;
V_31 = V_2 -> V_253 ( V_2 , V_254 , V_29 ) ;
if ( V_31 )
return V_31 ;
F_216 ( V_2 , V_254 , V_29 ) ;
V_2 -> V_102 = false ;
return 0 ;
}
void
F_168 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! F_1 ( V_2 ) )
return;
V_31 = F_183 ( V_2 ) ;
if ( V_31 && ! F_218 ( & F_35 ( V_2 -> V_4 ) -> V_25 ) )
F_41 ( L_27 ,
V_2 -> V_76 , V_31 ) ;
F_34 ( V_2 ) ;
}
