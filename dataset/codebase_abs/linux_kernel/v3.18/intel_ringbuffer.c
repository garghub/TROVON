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
V_50 |= V_49 ;
V_50 |= V_63 ;
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
return F_18 ( V_2 , V_64 ) ;
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
V_50 |= V_63 ;
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
return F_18 ( V_2 , V_64 ) ;
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
T_2 V_65 ;
if ( F_27 ( V_2 -> V_4 ) -> V_66 >= 8 )
V_65 = F_28 ( F_29 ( V_2 -> V_67 ) ,
F_30 ( V_2 -> V_67 ) ) ;
else if ( F_27 ( V_2 -> V_4 ) -> V_66 >= 4 )
V_65 = F_31 ( F_29 ( V_2 -> V_67 ) ) ;
else
V_65 = F_31 ( V_68 ) ;
return V_65 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
T_1 V_69 ;
V_69 = V_23 -> V_70 -> V_71 ;
if ( F_27 ( V_2 -> V_4 ) -> V_66 >= 4 )
V_69 |= ( V_23 -> V_70 -> V_71 >> 28 ) & 0xf0 ;
F_33 ( V_72 , V_69 ) ;
}
static bool F_34 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_35 ( V_2 -> V_4 ) ;
if ( ! F_36 ( V_2 -> V_4 ) ) {
F_37 ( V_2 , F_38 ( V_73 ) ) ;
if ( F_39 ( ( F_40 ( V_2 ) & V_74 ) != 0 , 1000 ) ) {
F_41 ( L_1 , V_2 -> V_75 ) ;
if ( F_42 ( V_2 ) != F_43 ( V_2 ) )
return false ;
}
}
F_44 ( V_2 , 0 ) ;
F_45 ( V_2 , 0 ) ;
V_2 -> V_27 ( V_2 , 0 ) ;
if ( ! F_36 ( V_2 -> V_4 ) ) {
( void ) F_46 ( V_2 ) ;
F_37 ( V_2 , F_47 ( V_73 ) ) ;
}
return ( F_42 ( V_2 ) & V_21 ) == 0 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_76 * V_14 = V_11 -> V_14 ;
int V_31 = 0 ;
F_49 ( V_23 , V_77 ) ;
if ( ! F_34 ( V_2 ) ) {
F_50 ( L_2
L_3 ,
V_2 -> V_75 ,
F_46 ( V_2 ) ,
F_42 ( V_2 ) ,
F_43 ( V_2 ) ,
F_51 ( V_2 ) ) ;
if ( ! F_34 ( V_2 ) ) {
F_41 ( L_4
L_3 ,
V_2 -> V_75 ,
F_46 ( V_2 ) ,
F_42 ( V_2 ) ,
F_43 ( V_2 ) ,
F_51 ( V_2 ) ) ;
V_31 = - V_78 ;
goto V_79;
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
V_2 -> V_75 , F_42 ( V_2 ) ) ;
F_45 ( V_2 , 0 ) ;
( void ) F_42 ( V_2 ) ;
F_44 ( V_2 ,
( ( V_11 -> V_18 - V_80 ) & V_81 )
| V_82 ) ;
if ( F_39 ( ( F_46 ( V_2 ) & V_82 ) != 0 &&
F_51 ( V_2 ) == F_55 ( V_14 ) &&
( F_42 ( V_2 ) & V_21 ) == 0 , 50 ) ) {
F_41 ( L_6
L_7 ,
V_2 -> V_75 ,
F_46 ( V_2 ) , F_46 ( V_2 ) & V_82 ,
F_42 ( V_2 ) , F_43 ( V_2 ) ,
F_51 ( V_2 ) , ( unsigned long ) F_55 ( V_14 ) ) ;
V_31 = - V_78 ;
goto V_79;
}
if ( ! F_57 ( V_2 -> V_4 , V_83 ) )
F_58 ( V_2 -> V_4 ) ;
else {
V_11 -> V_16 = F_42 ( V_2 ) ;
V_11 -> V_17 = F_43 ( V_2 ) & V_84 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
V_11 -> V_85 = - 1 ;
}
memset ( & V_2 -> V_86 , 0 , sizeof( V_2 -> V_86 ) ) ;
V_79:
F_59 ( V_23 , V_77 ) ;
return V_31 ;
}
void
F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_43 . V_14 == NULL )
return;
if ( F_27 ( V_4 ) -> V_66 >= 5 ) {
F_61 ( F_62 ( V_2 -> V_43 . V_14 -> V_87 -> V_88 ) ) ;
F_63 ( V_2 -> V_43 . V_14 ) ;
}
F_64 ( & V_2 -> V_43 . V_14 -> V_89 ) ;
V_2 -> V_43 . V_14 = NULL ;
}
int
F_65 ( struct V_1 * V_2 )
{
int V_31 ;
if ( V_2 -> V_43 . V_14 )
return 0 ;
V_2 -> V_43 . V_14 = F_66 ( V_2 -> V_4 , 4096 ) ;
if ( V_2 -> V_43 . V_14 == NULL ) {
F_41 ( L_8 ) ;
V_31 = - V_90 ;
goto V_91;
}
V_31 = F_67 ( V_2 -> V_43 . V_14 , V_92 ) ;
if ( V_31 )
goto V_93;
V_31 = F_68 ( V_2 -> V_43 . V_14 , 4096 , 0 ) ;
if ( V_31 )
goto V_93;
V_2 -> V_43 . V_44 = F_55 ( V_2 -> V_43 . V_14 ) ;
V_2 -> V_43 . V_94 = F_69 ( F_62 ( V_2 -> V_43 . V_14 -> V_87 -> V_88 ) ) ;
if ( V_2 -> V_43 . V_94 == NULL ) {
V_31 = - V_90 ;
goto V_95;
}
F_70 ( L_9 ,
V_2 -> V_75 , V_2 -> V_43 . V_44 ) ;
return 0 ;
V_95:
F_63 ( V_2 -> V_43 . V_14 ) ;
V_93:
F_64 ( & V_2 -> V_43 . V_14 -> V_89 ) ;
V_91:
return V_31 ;
}
static inline void F_71 ( struct V_1 * V_2 ,
T_1 V_69 , T_1 V_59 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
if ( F_72 ( V_23 -> V_96 >= V_97 ) )
return;
F_9 ( V_2 , F_19 ( 1 ) ) ;
F_9 ( V_2 , V_69 ) ;
F_9 ( V_2 , V_59 ) ;
V_23 -> V_98 [ V_23 -> V_96 ] . V_69 = V_69 ;
V_23 -> V_98 [ V_23 -> V_96 ] . V_99 = V_59 & 0xFFFF ;
V_23 -> V_98 [ V_23 -> V_96 ] . V_59 = V_59 ;
V_23 -> V_96 ++ ;
return;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_31 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
V_23 -> V_96 = 0 ;
memset ( V_23 -> V_98 , 0 , sizeof( V_23 -> V_98 ) ) ;
V_31 = F_8 ( V_2 , 18 ) ;
if ( V_31 )
return V_31 ;
F_71 ( V_2 , V_100 ,
F_38 ( V_101
| V_102 ) ) ;
F_71 ( V_2 , V_103 ,
F_38 ( V_104 ) ) ;
F_71 ( V_2 , V_105 ,
F_38 ( V_106 ) ) ;
F_71 ( V_2 , V_107 ,
F_38 ( V_108 ) ) ;
F_71 ( V_2 , V_109 ,
F_38 ( V_110 ) ) ;
F_71 ( V_2 , V_111 ,
V_112 | V_113 ) ;
F_10 ( V_2 ) ;
F_70 ( L_10 ,
V_23 -> V_96 ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_31 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
V_23 -> V_96 = 0 ;
memset ( V_23 -> V_98 , 0 , sizeof( V_23 -> V_98 ) ) ;
V_31 = F_8 ( V_2 , 12 ) ;
if ( V_31 )
return V_31 ;
F_71 ( V_2 , V_100 ,
F_38 ( V_101 ) ) ;
F_71 ( V_2 , V_100 ,
F_38 ( V_102 ) ) ;
F_71 ( V_2 , V_103 ,
F_38 ( V_104 ) ) ;
F_71 ( V_2 , V_105 ,
F_38 ( V_106 ) ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
int V_31 = F_48 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( F_27 ( V_4 ) -> V_66 >= 4 && F_27 ( V_4 ) -> V_66 < 7 )
F_33 ( V_114 , F_38 ( V_115 ) ) ;
if ( F_27 ( V_4 ) -> V_66 >= 6 )
F_33 ( V_114 , F_38 ( V_116 ) ) ;
if ( F_27 ( V_4 ) -> V_66 == 6 )
F_33 ( V_117 ,
F_38 ( V_118 ) ) ;
if ( F_76 ( V_4 ) )
F_33 ( V_119 ,
F_38 ( V_118 ) |
F_38 ( V_120 ) ) ;
if ( F_27 ( V_4 ) -> V_66 >= 5 ) {
V_31 = F_65 ( V_2 ) ;
if ( V_31 )
return V_31 ;
}
if ( F_77 ( V_4 ) ) {
F_33 ( V_121 ,
F_47 ( V_122 ) ) ;
}
if ( F_27 ( V_4 ) -> V_66 >= 6 )
F_33 ( V_123 , F_38 ( V_124 ) ) ;
if ( F_78 ( V_4 ) )
F_79 ( V_2 , ~ F_80 ( V_4 ) ) ;
return V_31 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
if ( V_23 -> V_125 ) {
F_63 ( V_23 -> V_125 ) ;
F_64 ( & V_23 -> V_125 -> V_89 ) ;
V_23 -> V_125 = NULL ;
}
F_60 ( V_2 ) ;
}
static int F_82 ( struct V_1 * V_126 ,
unsigned int V_127 )
{
#define F_83 8
struct V_3 * V_4 = V_126 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_128 ;
int V_129 , V_31 , V_130 ;
V_130 = F_84 ( F_27 ( V_4 ) -> V_131 ) ;
V_127 += ( V_130 - 1 ) * F_83 ;
#undef F_83
V_31 = F_8 ( V_126 , V_127 ) ;
if ( V_31 )
return V_31 ;
F_85 (waiter, dev_priv, i) {
T_2 V_44 = V_126 -> V_132 . V_133 [ V_129 ] ;
if ( V_44 == V_134 )
continue;
F_9 ( V_126 , F_15 ( 6 ) ) ;
F_9 ( V_126 , V_63 |
V_49 |
V_135 ) ;
F_9 ( V_126 , F_86 ( V_44 ) ) ;
F_9 ( V_126 , F_87 ( V_44 ) ) ;
F_9 ( V_126 , V_126 -> V_136 ) ;
F_9 ( V_126 , 0 ) ;
F_9 ( V_126 , V_137 |
F_88 ( V_128 -> V_13 ) ) ;
F_9 ( V_126 , 0 ) ;
}
return 0 ;
}
static int F_89 ( struct V_1 * V_126 ,
unsigned int V_127 )
{
#define F_83 6
struct V_3 * V_4 = V_126 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_128 ;
int V_129 , V_31 , V_130 ;
V_130 = F_84 ( F_27 ( V_4 ) -> V_131 ) ;
V_127 += ( V_130 - 1 ) * F_83 ;
#undef F_83
V_31 = F_8 ( V_126 , V_127 ) ;
if ( V_31 )
return V_31 ;
F_85 (waiter, dev_priv, i) {
T_2 V_44 = V_126 -> V_132 . V_133 [ V_129 ] ;
if ( V_44 == V_134 )
continue;
F_9 ( V_126 , ( V_138 + 1 ) |
V_139 ) ;
F_9 ( V_126 , F_86 ( V_44 ) |
V_140 ) ;
F_9 ( V_126 , F_87 ( V_44 ) ) ;
F_9 ( V_126 , V_126 -> V_136 ) ;
F_9 ( V_126 , V_137 |
F_88 ( V_128 -> V_13 ) ) ;
F_9 ( V_126 , 0 ) ;
}
return 0 ;
}
static int F_90 ( struct V_1 * V_126 ,
unsigned int V_127 )
{
struct V_3 * V_4 = V_126 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_141 ;
int V_129 , V_31 , V_130 ;
#define F_83 3
V_130 = F_84 ( F_27 ( V_4 ) -> V_131 ) ;
V_127 += F_91 ( ( V_130 - 1 ) * F_83 , 2 ) ;
#undef F_83
V_31 = F_8 ( V_126 , V_127 ) ;
if ( V_31 )
return V_31 ;
F_85 (useless, dev_priv, i) {
T_1 V_142 = V_126 -> V_132 . V_143 . signal [ V_129 ] ;
if ( V_142 != V_144 ) {
F_9 ( V_126 , F_19 ( 1 ) ) ;
F_9 ( V_126 , V_142 ) ;
F_9 ( V_126 , V_126 -> V_136 ) ;
}
}
if ( V_130 % 2 == 0 )
F_9 ( V_126 , V_37 ) ;
return 0 ;
}
static int
F_92 ( struct V_1 * V_2 )
{
int V_31 ;
if ( V_2 -> V_132 . signal )
V_31 = V_2 -> V_132 . signal ( V_2 , 4 ) ;
else
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_145 ) ;
F_9 ( V_2 , V_146 << V_147 ) ;
F_9 ( V_2 , V_2 -> V_136 ) ;
F_9 ( V_2 , V_148 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static inline bool F_93 ( struct V_3 * V_4 ,
T_1 V_149 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
return V_23 -> V_150 < V_149 ;
}
static int
F_94 ( struct V_1 * V_128 ,
struct V_1 * V_126 ,
T_1 V_149 )
{
struct V_22 * V_23 = V_128 -> V_4 -> V_24 ;
int V_31 ;
V_31 = F_8 ( V_128 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_128 , V_151 |
V_152 |
V_153 |
V_154 ) ;
F_9 ( V_128 , V_149 ) ;
F_9 ( V_128 ,
F_86 ( F_95 ( V_128 , V_126 -> V_13 ) ) ) ;
F_9 ( V_128 ,
F_87 ( F_95 ( V_128 , V_126 -> V_13 ) ) ) ;
F_10 ( V_128 ) ;
return 0 ;
}
static int
F_96 ( struct V_1 * V_128 ,
struct V_1 * V_126 ,
T_1 V_149 )
{
T_1 V_155 = V_156 |
V_157 |
V_158 ;
T_1 V_159 = V_126 -> V_132 . V_143 . V_160 [ V_128 -> V_13 ] ;
int V_31 ;
V_149 -= 1 ;
F_72 ( V_159 == V_134 ) ;
V_31 = F_8 ( V_128 , 4 ) ;
if ( V_31 )
return V_31 ;
if ( F_97 ( ! F_93 ( V_128 -> V_4 , V_149 ) ) ) {
F_9 ( V_128 , V_155 | V_159 ) ;
F_9 ( V_128 , V_149 ) ;
F_9 ( V_128 , 0 ) ;
F_9 ( V_128 , V_37 ) ;
} else {
F_9 ( V_128 , V_37 ) ;
F_9 ( V_128 , V_37 ) ;
F_9 ( V_128 , V_37 ) ;
F_9 ( V_128 , V_37 ) ;
}
F_10 ( V_128 ) ;
return 0 ;
}
static int
F_98 ( struct V_1 * V_2 )
{
T_1 V_42 = V_2 -> V_43 . V_44 + 2 * V_45 ;
int V_31 ;
V_31 = F_8 ( V_2 , 32 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , F_15 ( 4 ) | V_49 |
V_161 |
V_55 ) ;
F_9 ( V_2 , V_2 -> V_43 . V_44 | V_48 ) ;
F_9 ( V_2 , V_2 -> V_136 ) ;
F_9 ( V_2 , 0 ) ;
F_99 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_99 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_99 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_99 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_99 ( V_2 , V_42 ) ;
V_42 += 2 * V_45 ;
F_99 ( V_2 , V_42 ) ;
F_9 ( V_2 , F_15 ( 4 ) | V_49 |
V_161 |
V_55 |
V_162 ) ;
F_9 ( V_2 , V_2 -> V_43 . V_44 | V_48 ) ;
F_9 ( V_2 , V_2 -> V_136 ) ;
F_9 ( V_2 , 0 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static T_1
F_100 ( struct V_1 * V_2 , bool V_163 )
{
if ( ! V_163 ) {
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
F_101 ( F_29 ( V_2 -> V_67 ) ) ;
}
return F_102 ( V_2 , V_146 ) ;
}
static T_1
F_103 ( struct V_1 * V_2 , bool V_163 )
{
return F_102 ( V_2 , V_146 ) ;
}
static void
F_104 ( struct V_1 * V_2 , T_1 V_149 )
{
F_105 ( V_2 , V_146 , V_149 ) ;
}
static T_1
F_106 ( struct V_1 * V_2 , bool V_163 )
{
return V_2 -> V_43 . V_94 [ 0 ] ;
}
static void
F_107 ( struct V_1 * V_2 , T_1 V_149 )
{
V_2 -> V_43 . V_94 [ 0 ] = V_149 ;
}
static bool
F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! V_4 -> V_164 )
return false ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( V_2 -> V_166 ++ == 0 )
F_110 ( V_23 , V_2 -> V_167 ) ;
F_111 ( & V_23 -> V_165 , V_50 ) ;
return true ;
}
static void
F_112 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( -- V_2 -> V_166 == 0 )
F_113 ( V_23 , V_2 -> V_167 ) ;
F_111 ( & V_23 -> V_165 , V_50 ) ;
}
static bool
F_114 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! V_4 -> V_164 )
return false ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( V_2 -> V_166 ++ == 0 ) {
V_23 -> V_168 &= ~ V_2 -> V_167 ;
F_33 ( V_169 , V_23 -> V_168 ) ;
F_101 ( V_169 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
return true ;
}
static void
F_115 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( -- V_2 -> V_166 == 0 ) {
V_23 -> V_168 |= V_2 -> V_167 ;
F_33 ( V_169 , V_23 -> V_168 ) ;
F_101 ( V_169 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
}
static bool
F_116 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! V_4 -> V_164 )
return false ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( V_2 -> V_166 ++ == 0 ) {
V_23 -> V_168 &= ~ V_2 -> V_167 ;
F_117 ( V_169 , V_23 -> V_168 ) ;
F_118 ( V_169 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
return true ;
}
static void
F_119 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( -- V_2 -> V_166 == 0 ) {
V_23 -> V_168 |= V_2 -> V_167 ;
F_117 ( V_169 , V_23 -> V_168 ) ;
F_118 ( V_169 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
T_1 V_170 = 0 ;
if ( F_76 ( V_4 ) ) {
switch ( V_2 -> V_13 ) {
case V_171 :
V_170 = V_172 ;
break;
case V_173 :
V_170 = V_174 ;
break;
case V_175 :
case V_176 :
V_170 = V_177 ;
break;
case V_178 :
V_170 = V_179 ;
break;
}
} else if ( F_77 ( V_2 -> V_4 ) ) {
V_170 = F_120 ( V_2 -> V_67 ) ;
} else {
V_170 = F_121 ( V_2 -> V_67 ) ;
}
F_33 ( V_170 , ( T_1 ) V_2 -> V_180 . V_181 ) ;
F_101 ( V_170 ) ;
if ( F_27 ( V_4 ) -> V_66 >= 6 && F_27 ( V_4 ) -> V_66 < 8 ) {
T_1 V_182 = F_122 ( V_2 -> V_67 ) ;
F_72 ( ( F_40 ( V_2 ) & V_74 ) == 0 ) ;
F_33 ( V_182 ,
F_38 ( V_183 |
V_184 ) ) ;
if ( F_39 ( ( F_31 ( V_182 ) & V_184 ) == 0 ,
1000 ) )
F_41 ( L_11 ,
V_2 -> V_75 ) ;
}
}
static int
F_123 ( struct V_1 * V_2 ,
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
F_124 ( struct V_1 * V_2 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_145 ) ;
F_9 ( V_2 , V_146 << V_147 ) ;
F_9 ( V_2 , V_2 -> V_136 ) ;
F_9 ( V_2 , V_148 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static bool
F_125 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! V_4 -> V_164 )
return false ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( V_2 -> V_166 ++ == 0 ) {
if ( F_78 ( V_4 ) && V_2 -> V_13 == V_171 )
F_79 ( V_2 ,
~ ( V_2 -> V_167 |
F_80 ( V_4 ) ) ) ;
else
F_79 ( V_2 , ~ V_2 -> V_167 ) ;
F_110 ( V_23 , V_2 -> V_167 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
return true ;
}
static void
F_126 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( -- V_2 -> V_166 == 0 ) {
if ( F_78 ( V_4 ) && V_2 -> V_13 == V_171 )
F_79 ( V_2 , ~ F_80 ( V_4 ) ) ;
else
F_79 ( V_2 , ~ 0 ) ;
F_113 ( V_23 , V_2 -> V_167 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
}
static bool
F_127 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! V_4 -> V_164 )
return false ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( V_2 -> V_166 ++ == 0 ) {
F_79 ( V_2 , ~ V_2 -> V_167 ) ;
F_128 ( V_23 , V_2 -> V_167 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
return true ;
}
static void
F_129 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! V_4 -> V_164 )
return;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( -- V_2 -> V_166 == 0 ) {
F_79 ( V_2 , ~ 0 ) ;
F_130 ( V_23 , V_2 -> V_167 ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
}
static bool
F_131 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
if ( ! V_4 -> V_164 )
return false ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( V_2 -> V_166 ++ == 0 ) {
if ( F_78 ( V_4 ) && V_2 -> V_13 == V_171 ) {
F_79 ( V_2 ,
~ ( V_2 -> V_167 |
V_185 ) ) ;
} else {
F_79 ( V_2 , ~ V_2 -> V_167 ) ;
}
F_101 ( F_132 ( V_2 -> V_67 ) ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
return true ;
}
static void
F_133 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
unsigned long V_50 ;
F_109 ( & V_23 -> V_165 , V_50 ) ;
if ( -- V_2 -> V_166 == 0 ) {
if ( F_78 ( V_4 ) && V_2 -> V_13 == V_171 ) {
F_79 ( V_2 ,
~ V_185 ) ;
} else {
F_79 ( V_2 , ~ 0 ) ;
}
F_101 ( F_132 ( V_2 -> V_67 ) ) ;
}
F_111 ( & V_23 -> V_165 , V_50 ) ;
}
static int
F_134 ( struct V_1 * V_2 ,
T_2 V_186 , T_1 V_187 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 ,
V_188 |
V_189 |
( V_50 & V_190 ? 0 : V_191 ) ) ;
F_9 ( V_2 , V_186 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_135 ( struct V_1 * V_2 ,
T_2 V_186 , T_1 V_192 ,
unsigned V_50 )
{
T_1 V_193 = V_2 -> V_43 . V_44 ;
int V_31 ;
V_31 = F_8 ( V_2 , 6 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_194 | V_195 ) ;
F_9 ( V_2 , V_196 | V_197 | 4096 ) ;
F_9 ( V_2 , V_198 << 16 | 4 ) ;
F_9 ( V_2 , V_193 ) ;
F_9 ( V_2 , 0xdeadbeef ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
if ( ( V_50 & V_199 ) == 0 ) {
if ( V_192 > V_200 )
return - V_201 ;
V_31 = F_8 ( V_2 , 6 + 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_202 | V_195 ) ;
F_9 ( V_2 , V_196 | V_203 | 4096 ) ;
F_9 ( V_2 , F_136 ( V_192 , 4096 ) << 16 | 4096 ) ;
F_9 ( V_2 , V_193 ) ;
F_9 ( V_2 , 4096 ) ;
F_9 ( V_2 , V_186 ) ;
F_9 ( V_2 , V_32 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
V_186 = V_193 ;
}
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_204 ) ;
F_9 ( V_2 , V_186 | ( V_50 & V_190 ? 0 : V_205 ) ) ;
F_9 ( V_2 , V_186 + V_192 - 8 ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_137 ( struct V_1 * V_2 ,
T_2 V_186 , T_1 V_192 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_188 | V_189 ) ;
F_9 ( V_2 , V_186 | ( V_50 & V_190 ? 0 : V_205 ) ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static void F_138 ( struct V_1 * V_2 )
{
struct V_76 * V_14 ;
V_14 = V_2 -> V_180 . V_14 ;
if ( V_14 == NULL )
return;
F_61 ( F_62 ( V_14 -> V_87 -> V_88 ) ) ;
F_63 ( V_14 ) ;
F_64 ( & V_14 -> V_89 ) ;
V_2 -> V_180 . V_14 = NULL ;
}
static int F_139 ( struct V_1 * V_2 )
{
struct V_76 * V_14 ;
if ( ( V_14 = V_2 -> V_180 . V_14 ) == NULL ) {
unsigned V_50 ;
int V_31 ;
V_14 = F_66 ( V_2 -> V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_41 ( L_12 ) ;
return - V_90 ;
}
V_31 = F_67 ( V_14 , V_92 ) ;
if ( V_31 )
goto V_93;
V_50 = 0 ;
if ( ! F_140 ( V_2 -> V_4 ) )
V_50 |= V_206 ;
V_31 = F_68 ( V_14 , 4096 , V_50 ) ;
if ( V_31 ) {
V_93:
F_64 ( & V_14 -> V_89 ) ;
return V_31 ;
}
V_2 -> V_180 . V_14 = V_14 ;
}
V_2 -> V_180 . V_181 = F_55 ( V_14 ) ;
V_2 -> V_180 . V_207 = F_69 ( F_62 ( V_14 -> V_87 -> V_88 ) ) ;
memset ( V_2 -> V_180 . V_207 , 0 , V_80 ) ;
F_70 ( L_13 ,
V_2 -> V_75 , V_2 -> V_180 . V_181 ) ;
return 0 ;
}
static int F_141 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
if ( ! V_23 -> V_70 ) {
V_23 -> V_70 =
F_142 ( V_2 -> V_4 , V_80 , V_80 ) ;
if ( ! V_23 -> V_70 )
return - V_90 ;
}
V_2 -> V_180 . V_207 = V_23 -> V_70 -> V_208 ;
memset ( V_2 -> V_180 . V_207 , 0 , V_80 ) ;
return 0 ;
}
void F_143 ( struct V_10 * V_11 )
{
if ( ! V_11 -> V_14 )
return;
F_144 ( V_11 -> V_209 ) ;
F_63 ( V_11 -> V_14 ) ;
F_64 ( & V_11 -> V_14 -> V_89 ) ;
V_11 -> V_14 = NULL ;
}
int F_145 ( struct V_3 * V_4 ,
struct V_10 * V_11 )
{
struct V_22 * V_23 = F_35 ( V_4 ) ;
struct V_76 * V_14 ;
int V_31 ;
if ( V_11 -> V_14 )
return 0 ;
V_14 = NULL ;
if ( ! F_140 ( V_4 ) )
V_14 = F_146 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
V_14 = F_66 ( V_4 , V_11 -> V_18 ) ;
if ( V_14 == NULL )
return - V_90 ;
V_14 -> V_210 = 1 ;
V_31 = F_68 ( V_14 , V_80 , V_206 ) ;
if ( V_31 )
goto V_93;
V_31 = F_147 ( V_14 , true ) ;
if ( V_31 )
goto V_95;
V_11 -> V_209 =
F_148 ( V_23 -> V_211 . V_212 + F_55 ( V_14 ) ,
V_11 -> V_18 ) ;
if ( V_11 -> V_209 == NULL ) {
V_31 = - V_213 ;
goto V_95;
}
V_11 -> V_14 = V_14 ;
return 0 ;
V_95:
F_63 ( V_14 ) ;
V_93:
F_64 ( & V_14 -> V_89 ) ;
return V_31 ;
}
static int F_149 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_31 ;
if ( V_11 == NULL ) {
V_11 = F_150 ( sizeof( * V_11 ) , V_214 ) ;
if ( ! V_11 )
return - V_90 ;
V_2 -> V_15 = V_11 ;
}
V_2 -> V_4 = V_4 ;
F_151 ( & V_2 -> V_215 ) ;
F_151 ( & V_2 -> V_216 ) ;
F_151 ( & V_2 -> V_217 ) ;
V_11 -> V_18 = 32 * V_80 ;
V_11 -> V_2 = V_2 ;
memset ( V_2 -> V_132 . V_218 , 0 , sizeof( V_2 -> V_132 . V_218 ) ) ;
F_152 ( & V_2 -> V_219 ) ;
if ( F_52 ( V_4 ) ) {
V_31 = F_139 ( V_2 ) ;
if ( V_31 )
goto error;
} else {
F_153 ( V_2 -> V_13 != V_171 ) ;
V_31 = F_141 ( V_2 ) ;
if ( V_31 )
goto error;
}
V_31 = F_145 ( V_4 , V_11 ) ;
if ( V_31 ) {
F_41 ( L_14 , V_2 -> V_75 , V_31 ) ;
goto error;
}
V_11 -> V_220 = V_11 -> V_18 ;
if ( F_154 ( V_4 ) || F_155 ( V_4 ) )
V_11 -> V_220 -= 2 * V_45 ;
V_31 = F_156 ( V_2 ) ;
if ( V_31 )
goto error;
V_31 = V_2 -> V_221 ( V_2 ) ;
if ( V_31 )
goto error;
return 0 ;
error:
F_157 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_31 ;
}
void F_158 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = F_35 ( V_2 -> V_4 ) ;
struct V_10 * V_11 = V_2 -> V_15 ;
if ( ! F_1 ( V_2 ) )
return;
F_159 ( V_2 ) ;
F_72 ( ! F_36 ( V_2 -> V_4 ) && ( F_40 ( V_2 ) & V_74 ) == 0 ) ;
F_143 ( V_11 ) ;
V_2 -> V_222 = NULL ;
V_2 -> V_136 = 0 ;
if ( V_2 -> V_223 )
V_2 -> V_223 ( V_2 ) ;
F_138 ( V_2 ) ;
F_160 ( V_2 ) ;
F_157 ( V_11 ) ;
V_2 -> V_15 = NULL ;
}
static int F_161 ( struct V_1 * V_2 , int V_224 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
struct V_225 * V_226 ;
T_1 V_149 = 0 ;
int V_31 ;
if ( V_11 -> V_85 != - 1 ) {
V_11 -> V_16 = V_11 -> V_85 ;
V_11 -> V_85 = - 1 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
if ( V_11 -> V_19 >= V_224 )
return 0 ;
}
F_162 (request, &ring->request_list, list) {
if ( F_2 ( V_226 -> V_17 , V_11 -> V_17 ,
V_11 -> V_18 ) >= V_224 ) {
V_149 = V_226 -> V_149 ;
break;
}
}
if ( V_149 == 0 )
return - V_201 ;
V_31 = F_163 ( V_2 , V_149 ) ;
if ( V_31 )
return V_31 ;
F_164 ( V_2 ) ;
V_11 -> V_16 = V_11 -> V_85 ;
V_11 -> V_85 = - 1 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
return 0 ;
}
static int F_165 ( struct V_1 * V_2 , int V_224 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_10 * V_11 = V_2 -> V_15 ;
unsigned long V_227 ;
int V_31 ;
V_31 = F_161 ( V_2 , V_224 ) ;
if ( V_31 != - V_201 )
return V_31 ;
F_6 ( V_2 ) ;
V_227 = V_228 + 60 * V_229 ;
F_166 ( V_2 ) ;
do {
V_11 -> V_16 = F_42 ( V_2 ) ;
V_11 -> V_19 = F_3 ( V_11 ) ;
if ( V_11 -> V_19 >= V_224 ) {
V_31 = 0 ;
break;
}
if ( ! F_57 ( V_4 , V_83 ) &&
V_4 -> V_230 -> V_231 ) {
struct V_232 * V_233 = V_4 -> V_230 -> V_231 -> V_234 ;
if ( V_233 -> V_235 )
V_233 -> V_235 -> V_236 |= V_237 ;
}
F_167 ( 1 ) ;
if ( V_23 -> V_238 . V_239 && F_168 ( V_240 ) ) {
V_31 = - V_241 ;
break;
}
V_31 = F_169 ( & V_23 -> V_25 ,
V_23 -> V_238 . V_239 ) ;
if ( V_31 )
break;
if ( F_170 ( V_228 , V_227 ) ) {
V_31 = - V_242 ;
break;
}
} while ( 1 );
F_171 ( V_2 ) ;
return V_31 ;
}
static int F_172 ( struct V_1 * V_2 )
{
T_3 T_4 * V_243 ;
struct V_10 * V_11 = V_2 -> V_15 ;
int V_244 = V_11 -> V_18 - V_11 -> V_17 ;
if ( V_11 -> V_19 < V_244 ) {
int V_31 = F_165 ( V_2 , V_244 ) ;
if ( V_31 )
return V_31 ;
}
V_243 = V_11 -> V_209 + V_11 -> V_17 ;
V_244 /= 4 ;
while ( V_244 -- )
F_173 ( V_37 , V_243 ++ ) ;
V_11 -> V_17 = 0 ;
V_11 -> V_19 = F_3 ( V_11 ) ;
return 0 ;
}
int F_174 ( struct V_1 * V_2 )
{
T_1 V_149 ;
int V_31 ;
if ( V_2 -> V_136 ) {
V_31 = F_175 ( V_2 , NULL ) ;
if ( V_31 )
return V_31 ;
}
if ( F_176 ( & V_2 -> V_216 ) )
return 0 ;
V_149 = F_177 ( V_2 -> V_216 . V_245 ,
struct V_225 ,
V_246 ) -> V_149 ;
return F_163 ( V_2 , V_149 ) ;
}
static int
F_178 ( struct V_1 * V_2 )
{
if ( V_2 -> V_136 )
return 0 ;
if ( V_2 -> V_222 == NULL ) {
struct V_225 * V_226 ;
V_226 = F_179 ( sizeof( * V_226 ) , V_214 ) ;
if ( V_226 == NULL )
return - V_90 ;
V_2 -> V_222 = V_226 ;
}
return F_180 ( V_2 -> V_4 , & V_2 -> V_136 ) ;
}
static int F_181 ( struct V_1 * V_2 ,
int V_247 )
{
struct V_10 * V_11 = V_2 -> V_15 ;
int V_31 ;
if ( F_182 ( V_11 -> V_17 + V_247 > V_11 -> V_220 ) ) {
V_31 = F_172 ( V_2 ) ;
if ( F_182 ( V_31 ) )
return V_31 ;
}
if ( F_182 ( V_11 -> V_19 < V_247 ) ) {
V_31 = F_165 ( V_2 , V_247 ) ;
if ( F_182 ( V_31 ) )
return V_31 ;
}
return 0 ;
}
int F_8 ( struct V_1 * V_2 ,
int V_127 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
int V_31 ;
V_31 = F_169 ( & V_23 -> V_25 ,
V_23 -> V_238 . V_239 ) ;
if ( V_31 )
return V_31 ;
V_31 = F_181 ( V_2 , V_127 * sizeof( T_3 ) ) ;
if ( V_31 )
return V_31 ;
V_31 = F_178 ( V_2 ) ;
if ( V_31 )
return V_31 ;
V_2 -> V_15 -> V_19 -= V_127 * sizeof( T_3 ) ;
return 0 ;
}
int F_183 ( struct V_1 * V_2 )
{
int V_127 = ( V_2 -> V_15 -> V_17 & ( V_45 - 1 ) ) / sizeof( T_3 ) ;
int V_31 ;
if ( V_127 == 0 )
return 0 ;
V_127 = V_45 / sizeof( T_3 ) - V_127 ;
V_31 = F_8 ( V_2 , V_127 ) ;
if ( V_31 )
return V_31 ;
while ( V_127 -- )
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
void F_184 ( struct V_1 * V_2 , T_1 V_149 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_24 ;
F_153 ( V_2 -> V_136 ) ;
if ( F_27 ( V_4 ) -> V_66 == 6 || F_27 ( V_4 ) -> V_66 == 7 ) {
F_33 ( F_185 ( V_2 -> V_67 ) , 0 ) ;
F_33 ( F_186 ( V_2 -> V_67 ) , 0 ) ;
if ( F_187 ( V_4 ) )
F_33 ( F_188 ( V_2 -> V_67 ) , 0 ) ;
}
V_2 -> V_248 ( V_2 , V_149 ) ;
V_2 -> V_86 . V_149 = V_149 ;
}
static void F_189 ( struct V_1 * V_2 ,
T_1 V_59 )
{
struct V_22 * V_23 = V_2 -> V_4 -> V_24 ;
F_33 ( V_249 ,
F_38 ( V_250 ) ) ;
F_190 ( V_251 , 0x0 ) ;
if ( F_39 ( ( F_31 ( V_249 ) &
V_252 ) == 0 ,
50 ) )
F_41 ( L_15 ) ;
F_25 ( V_2 , V_59 ) ;
F_101 ( F_191 ( V_2 -> V_67 ) ) ;
F_33 ( V_249 ,
F_47 ( V_250 ) ) ;
}
static int F_192 ( struct V_1 * V_2 ,
T_1 V_253 , T_1 V_254 )
{
T_3 V_30 ;
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
V_30 = V_138 ;
if ( F_27 ( V_2 -> V_4 ) -> V_66 >= 8 )
V_30 += 1 ;
if ( V_253 & V_255 )
V_30 |= V_256 | V_257 |
V_258 | V_139 ;
F_9 ( V_2 , V_30 ) ;
F_9 ( V_2 , V_259 | V_140 ) ;
if ( F_27 ( V_2 -> V_4 ) -> V_66 >= 8 ) {
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
F_193 ( struct V_1 * V_2 ,
T_2 V_186 , T_1 V_192 ,
unsigned V_50 )
{
bool V_260 = F_194 ( V_2 -> V_4 ) && ! ( V_50 & V_190 ) ;
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 , V_261 | ( V_260 << 8 ) ) ;
F_9 ( V_2 , F_86 ( V_186 ) ) ;
F_9 ( V_2 , F_87 ( V_186 ) ) ;
F_9 ( V_2 , V_37 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_195 ( struct V_1 * V_2 ,
T_2 V_186 , T_1 V_192 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 ,
V_188 |
( V_50 & V_190 ?
0 : V_262 | V_263 ) ) ;
F_9 ( V_2 , V_186 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int
F_196 ( struct V_1 * V_2 ,
T_2 V_186 , T_1 V_192 ,
unsigned V_50 )
{
int V_31 ;
V_31 = F_8 ( V_2 , 2 ) ;
if ( V_31 )
return V_31 ;
F_9 ( V_2 ,
V_188 |
( V_50 & V_190 ? 0 : V_191 ) ) ;
F_9 ( V_2 , V_186 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
static int F_197 ( struct V_1 * V_2 ,
T_1 V_253 , T_1 V_254 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_3 V_30 ;
int V_31 ;
V_31 = F_8 ( V_2 , 4 ) ;
if ( V_31 )
return V_31 ;
V_30 = V_138 ;
if ( F_27 ( V_2 -> V_4 ) -> V_66 >= 8 )
V_30 += 1 ;
if ( V_253 & V_33 )
V_30 |= V_256 | V_258 |
V_139 ;
F_9 ( V_2 , V_30 ) ;
F_9 ( V_2 , V_259 | V_140 ) ;
if ( F_27 ( V_2 -> V_4 ) -> V_66 >= 8 ) {
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , 0 ) ;
} else {
F_9 ( V_2 , 0 ) ;
F_9 ( V_2 , V_37 ) ;
}
F_10 ( V_2 ) ;
if ( F_76 ( V_4 ) && ! V_253 && V_254 )
return F_18 ( V_2 , V_264 ) ;
return 0 ;
}
int F_198 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_171 ] ;
struct V_76 * V_14 ;
int V_31 ;
V_2 -> V_75 = L_16 ;
V_2 -> V_13 = V_171 ;
V_2 -> V_67 = V_265 ;
if ( F_27 ( V_4 ) -> V_66 >= 8 ) {
if ( F_199 ( V_4 ) ) {
V_14 = F_66 ( V_4 , 4096 ) ;
if ( V_14 == NULL ) {
F_41 ( L_17 ) ;
V_5 . V_266 = 0 ;
} else {
F_67 ( V_14 , V_92 ) ;
V_31 = F_68 ( V_14 , 0 , V_267 ) ;
if ( V_31 != 0 ) {
F_64 ( & V_14 -> V_89 ) ;
F_41 ( L_18 ) ;
V_5 . V_266 = 0 ;
} else
V_23 -> V_125 = V_14 ;
}
}
if ( F_200 ( V_4 ) )
V_2 -> V_268 = F_74 ;
else
V_2 -> V_268 = F_73 ;
V_2 -> V_269 = F_92 ;
V_2 -> V_254 = F_23 ;
V_2 -> V_270 = F_131 ;
V_2 -> V_271 = F_133 ;
V_2 -> V_167 = V_272 ;
V_2 -> V_273 = F_100 ;
V_2 -> V_248 = F_104 ;
if ( F_199 ( V_4 ) ) {
F_72 ( ! V_23 -> V_125 ) ;
V_2 -> V_132 . V_274 = F_94 ;
V_2 -> V_132 . signal = F_82 ;
V_275 ;
}
} else if ( F_27 ( V_4 ) -> V_66 >= 6 ) {
V_2 -> V_269 = F_92 ;
V_2 -> V_254 = F_21 ;
if ( F_27 ( V_4 ) -> V_66 == 6 )
V_2 -> V_254 = F_16 ;
V_2 -> V_270 = F_125 ;
V_2 -> V_271 = F_126 ;
V_2 -> V_167 = V_272 ;
V_2 -> V_273 = F_100 ;
V_2 -> V_248 = F_104 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . V_274 = F_96 ;
V_2 -> V_132 . signal = F_90 ;
V_2 -> V_132 . V_143 . V_160 [ V_171 ] = V_134 ;
V_2 -> V_132 . V_143 . V_160 [ V_176 ] = V_276 ;
V_2 -> V_132 . V_143 . V_160 [ V_173 ] = V_277 ;
V_2 -> V_132 . V_143 . V_160 [ V_178 ] = V_278 ;
V_2 -> V_132 . V_143 . V_160 [ V_175 ] = V_134 ;
V_2 -> V_132 . V_143 . signal [ V_171 ] = V_144 ;
V_2 -> V_132 . V_143 . signal [ V_176 ] = V_279 ;
V_2 -> V_132 . V_143 . signal [ V_173 ] = V_280 ;
V_2 -> V_132 . V_143 . signal [ V_178 ] = V_281 ;
V_2 -> V_132 . V_143 . signal [ V_175 ] = V_144 ;
}
} else if ( F_13 ( V_4 ) ) {
V_2 -> V_269 = F_98 ;
V_2 -> V_254 = F_11 ;
V_2 -> V_273 = F_106 ;
V_2 -> V_248 = F_107 ;
V_2 -> V_270 = F_108 ;
V_2 -> V_271 = F_112 ;
V_2 -> V_167 = V_272 |
V_282 ;
} else {
V_2 -> V_269 = F_124 ;
if ( F_27 ( V_4 ) -> V_66 < 4 )
V_2 -> V_254 = F_7 ;
else
V_2 -> V_254 = F_11 ;
V_2 -> V_273 = F_103 ;
V_2 -> V_248 = F_104 ;
if ( F_36 ( V_4 ) ) {
V_2 -> V_270 = F_116 ;
V_2 -> V_271 = F_119 ;
} else {
V_2 -> V_270 = F_114 ;
V_2 -> V_271 = F_115 ;
}
V_2 -> V_167 = V_283 ;
}
V_2 -> V_27 = F_24 ;
if ( F_201 ( V_4 ) )
V_2 -> V_284 = F_195 ;
else if ( F_202 ( V_4 ) )
V_2 -> V_284 = F_193 ;
else if ( F_27 ( V_4 ) -> V_66 >= 6 )
V_2 -> V_284 = F_196 ;
else if ( F_27 ( V_4 ) -> V_66 >= 4 )
V_2 -> V_284 = F_134 ;
else if ( F_154 ( V_4 ) || F_155 ( V_4 ) )
V_2 -> V_284 = F_135 ;
else
V_2 -> V_284 = F_137 ;
V_2 -> V_221 = F_75 ;
V_2 -> V_223 = F_81 ;
if ( F_203 ( V_4 ) ) {
V_14 = F_66 ( V_4 , V_285 ) ;
if ( V_14 == NULL ) {
F_41 ( L_19 ) ;
return - V_90 ;
}
V_31 = F_68 ( V_14 , 0 , 0 ) ;
if ( V_31 != 0 ) {
F_64 ( & V_14 -> V_89 ) ;
F_41 ( L_20 ) ;
return V_31 ;
}
V_2 -> V_43 . V_14 = V_14 ;
V_2 -> V_43 . V_44 = F_55 ( V_14 ) ;
}
return F_149 ( V_4 , V_2 ) ;
}
int F_204 ( struct V_3 * V_4 , T_2 V_286 , T_1 V_18 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_171 ] ;
struct V_10 * V_11 = V_2 -> V_15 ;
int V_31 ;
if ( V_11 == NULL ) {
V_11 = F_150 ( sizeof( * V_11 ) , V_214 ) ;
if ( ! V_11 )
return - V_90 ;
V_2 -> V_15 = V_11 ;
}
V_2 -> V_75 = L_16 ;
V_2 -> V_13 = V_171 ;
V_2 -> V_67 = V_265 ;
if ( F_27 ( V_4 ) -> V_66 >= 6 ) {
V_31 = - V_287 ;
goto V_288;
}
V_2 -> V_269 = F_124 ;
if ( F_27 ( V_4 ) -> V_66 < 4 )
V_2 -> V_254 = F_7 ;
else
V_2 -> V_254 = F_11 ;
V_2 -> V_273 = F_103 ;
V_2 -> V_248 = F_104 ;
if ( F_36 ( V_4 ) ) {
V_2 -> V_270 = F_116 ;
V_2 -> V_271 = F_119 ;
} else {
V_2 -> V_270 = F_114 ;
V_2 -> V_271 = F_115 ;
}
V_2 -> V_167 = V_283 ;
V_2 -> V_27 = F_24 ;
if ( F_27 ( V_4 ) -> V_66 >= 4 )
V_2 -> V_284 = F_134 ;
else if ( F_154 ( V_4 ) || F_155 ( V_4 ) )
V_2 -> V_284 = F_135 ;
else
V_2 -> V_284 = F_137 ;
V_2 -> V_221 = F_75 ;
V_2 -> V_223 = F_81 ;
V_2 -> V_4 = V_4 ;
F_151 ( & V_2 -> V_215 ) ;
F_151 ( & V_2 -> V_216 ) ;
V_11 -> V_18 = V_18 ;
V_11 -> V_220 = V_11 -> V_18 ;
if ( F_154 ( V_2 -> V_4 ) || F_155 ( V_2 -> V_4 ) )
V_11 -> V_220 -= 2 * V_45 ;
V_11 -> V_209 = F_148 ( V_286 , V_18 ) ;
if ( V_11 -> V_209 == NULL ) {
F_41 ( L_21
L_22 ) ;
V_31 = - V_90 ;
goto V_288;
}
if ( ! F_52 ( V_4 ) ) {
V_31 = F_141 ( V_2 ) ;
if ( V_31 )
goto V_289;
}
return 0 ;
V_289:
F_144 ( V_11 -> V_209 ) ;
V_288:
F_157 ( V_11 ) ;
V_2 -> V_15 = NULL ;
return V_31 ;
}
int F_205 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_176 ] ;
V_2 -> V_75 = L_23 ;
V_2 -> V_13 = V_176 ;
V_2 -> V_27 = F_24 ;
if ( F_27 ( V_4 ) -> V_66 >= 6 ) {
V_2 -> V_67 = V_290 ;
if ( F_77 ( V_4 ) )
V_2 -> V_27 = F_189 ;
V_2 -> V_254 = F_192 ;
V_2 -> V_269 = F_92 ;
V_2 -> V_273 = F_100 ;
V_2 -> V_248 = F_104 ;
if ( F_27 ( V_4 ) -> V_66 >= 8 ) {
V_2 -> V_167 =
V_272 << V_291 ;
V_2 -> V_270 = F_131 ;
V_2 -> V_271 = F_133 ;
V_2 -> V_284 =
F_193 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . V_274 = F_94 ;
V_2 -> V_132 . signal = F_89 ;
V_275 ;
}
} else {
V_2 -> V_167 = V_292 ;
V_2 -> V_270 = F_125 ;
V_2 -> V_271 = F_126 ;
V_2 -> V_284 =
F_196 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . V_274 = F_96 ;
V_2 -> V_132 . signal = F_90 ;
V_2 -> V_132 . V_143 . V_160 [ V_171 ] = V_293 ;
V_2 -> V_132 . V_143 . V_160 [ V_176 ] = V_134 ;
V_2 -> V_132 . V_143 . V_160 [ V_173 ] = V_294 ;
V_2 -> V_132 . V_143 . V_160 [ V_178 ] = V_295 ;
V_2 -> V_132 . V_143 . V_160 [ V_175 ] = V_134 ;
V_2 -> V_132 . V_143 . signal [ V_171 ] = V_296 ;
V_2 -> V_132 . V_143 . signal [ V_176 ] = V_144 ;
V_2 -> V_132 . V_143 . signal [ V_173 ] = V_297 ;
V_2 -> V_132 . V_143 . signal [ V_178 ] = V_298 ;
V_2 -> V_132 . V_143 . signal [ V_175 ] = V_144 ;
}
}
} else {
V_2 -> V_67 = V_299 ;
V_2 -> V_254 = F_123 ;
V_2 -> V_269 = F_124 ;
V_2 -> V_273 = F_103 ;
V_2 -> V_248 = F_104 ;
if ( F_13 ( V_4 ) ) {
V_2 -> V_167 = V_300 ;
V_2 -> V_270 = F_108 ;
V_2 -> V_271 = F_112 ;
} else {
V_2 -> V_167 = V_301 ;
V_2 -> V_270 = F_114 ;
V_2 -> V_271 = F_115 ;
}
V_2 -> V_284 = F_134 ;
}
V_2 -> V_221 = F_48 ;
return F_149 ( V_4 , V_2 ) ;
}
int F_206 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_175 ] ;
if ( ( F_27 ( V_4 ) -> V_66 != 8 ) ) {
F_41 ( L_24 ) ;
return - V_213 ;
}
V_2 -> V_75 = L_25 ;
V_2 -> V_13 = V_175 ;
V_2 -> V_27 = F_24 ;
V_2 -> V_67 = V_302 ;
V_2 -> V_254 = F_192 ;
V_2 -> V_269 = F_92 ;
V_2 -> V_273 = F_100 ;
V_2 -> V_248 = F_104 ;
V_2 -> V_167 =
V_272 << V_303 ;
V_2 -> V_270 = F_131 ;
V_2 -> V_271 = F_133 ;
V_2 -> V_284 =
F_193 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . V_274 = F_94 ;
V_2 -> V_132 . signal = F_89 ;
V_275 ;
}
V_2 -> V_221 = F_48 ;
return F_149 ( V_4 , V_2 ) ;
}
int F_207 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_173 ] ;
V_2 -> V_75 = L_26 ;
V_2 -> V_13 = V_173 ;
V_2 -> V_67 = V_304 ;
V_2 -> V_27 = F_24 ;
V_2 -> V_254 = F_197 ;
V_2 -> V_269 = F_92 ;
V_2 -> V_273 = F_100 ;
V_2 -> V_248 = F_104 ;
if ( F_27 ( V_4 ) -> V_66 >= 8 ) {
V_2 -> V_167 =
V_272 << V_305 ;
V_2 -> V_270 = F_131 ;
V_2 -> V_271 = F_133 ;
V_2 -> V_284 = F_193 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . V_274 = F_94 ;
V_2 -> V_132 . signal = F_89 ;
V_275 ;
}
} else {
V_2 -> V_167 = V_306 ;
V_2 -> V_270 = F_125 ;
V_2 -> V_271 = F_126 ;
V_2 -> V_284 = F_196 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . signal = F_90 ;
V_2 -> V_132 . V_274 = F_96 ;
V_2 -> V_132 . V_143 . V_160 [ V_171 ] = V_307 ;
V_2 -> V_132 . V_143 . V_160 [ V_176 ] = V_308 ;
V_2 -> V_132 . V_143 . V_160 [ V_173 ] = V_134 ;
V_2 -> V_132 . V_143 . V_160 [ V_178 ] = V_309 ;
V_2 -> V_132 . V_143 . V_160 [ V_175 ] = V_134 ;
V_2 -> V_132 . V_143 . signal [ V_171 ] = V_310 ;
V_2 -> V_132 . V_143 . signal [ V_176 ] = V_311 ;
V_2 -> V_132 . V_143 . signal [ V_173 ] = V_144 ;
V_2 -> V_132 . V_143 . signal [ V_178 ] = V_312 ;
V_2 -> V_132 . V_143 . signal [ V_175 ] = V_144 ;
}
}
V_2 -> V_221 = F_48 ;
return F_149 ( V_4 , V_2 ) ;
}
int F_208 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_24 ;
struct V_1 * V_2 = & V_23 -> V_2 [ V_178 ] ;
V_2 -> V_75 = L_27 ;
V_2 -> V_13 = V_178 ;
V_2 -> V_67 = V_313 ;
V_2 -> V_27 = F_24 ;
V_2 -> V_254 = F_197 ;
V_2 -> V_269 = F_92 ;
V_2 -> V_273 = F_100 ;
V_2 -> V_248 = F_104 ;
if ( F_27 ( V_4 ) -> V_66 >= 8 ) {
V_2 -> V_167 =
V_272 << V_314 ;
V_2 -> V_270 = F_131 ;
V_2 -> V_271 = F_133 ;
V_2 -> V_284 = F_193 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . V_274 = F_94 ;
V_2 -> V_132 . signal = F_89 ;
V_275 ;
}
} else {
V_2 -> V_167 = V_315 ;
V_2 -> V_270 = F_127 ;
V_2 -> V_271 = F_129 ;
V_2 -> V_284 = F_196 ;
if ( F_199 ( V_4 ) ) {
V_2 -> V_132 . V_274 = F_96 ;
V_2 -> V_132 . signal = F_90 ;
V_2 -> V_132 . V_143 . V_160 [ V_171 ] = V_316 ;
V_2 -> V_132 . V_143 . V_160 [ V_176 ] = V_317 ;
V_2 -> V_132 . V_143 . V_160 [ V_173 ] = V_318 ;
V_2 -> V_132 . V_143 . V_160 [ V_178 ] = V_134 ;
V_2 -> V_132 . V_143 . V_160 [ V_175 ] = V_134 ;
V_2 -> V_132 . V_143 . signal [ V_171 ] = V_319 ;
V_2 -> V_132 . V_143 . signal [ V_176 ] = V_320 ;
V_2 -> V_132 . V_143 . signal [ V_173 ] = V_321 ;
V_2 -> V_132 . V_143 . signal [ V_178 ] = V_144 ;
V_2 -> V_132 . V_143 . signal [ V_175 ] = V_144 ;
}
}
V_2 -> V_221 = F_48 ;
return F_149 ( V_4 , V_2 ) ;
}
int
F_209 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! V_2 -> V_322 )
return 0 ;
V_31 = V_2 -> V_254 ( V_2 , 0 , V_255 ) ;
if ( V_31 )
return V_31 ;
F_210 ( V_2 , 0 , V_255 ) ;
V_2 -> V_322 = false ;
return 0 ;
}
int
F_211 ( struct V_1 * V_2 )
{
T_3 V_29 ;
int V_31 ;
V_29 = 0 ;
if ( V_2 -> V_322 )
V_29 = V_255 ;
V_31 = V_2 -> V_254 ( V_2 , V_255 , V_29 ) ;
if ( V_31 )
return V_31 ;
F_210 ( V_2 , V_255 , V_29 ) ;
V_2 -> V_322 = false ;
return 0 ;
}
void
F_159 ( struct V_1 * V_2 )
{
int V_31 ;
if ( ! F_1 ( V_2 ) )
return;
V_31 = F_174 ( V_2 ) ;
if ( V_31 && ! F_212 ( & F_35 ( V_2 -> V_4 ) -> V_25 ) )
F_41 ( L_28 ,
V_2 -> V_75 , V_31 ) ;
F_34 ( V_2 ) ;
}
