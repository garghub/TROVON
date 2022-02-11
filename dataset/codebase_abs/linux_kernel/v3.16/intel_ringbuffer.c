static inline int F_1 ( int V_1 , int V_2 , int V_3 )
{
int V_4 = V_1 - ( V_2 + V_5 ) ;
if ( V_4 < 0 )
V_4 += V_3 ;
return V_4 ;
}
static inline int F_2 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
return F_1 ( V_9 -> V_1 & V_11 , V_9 -> V_2 , V_9 -> V_3 ) ;
}
static bool F_3 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
return V_13 -> V_16 . V_17 & F_4 ( V_7 ) ;
}
void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
V_9 -> V_2 &= V_9 -> V_3 - 1 ;
if ( F_3 ( V_7 ) )
return;
V_7 -> V_18 ( V_7 , V_9 -> V_2 ) ;
}
static int
F_6 ( struct V_6 * V_7 ,
T_1 V_19 ,
T_1 V_20 )
{
T_1 V_21 ;
int V_22 ;
V_21 = V_23 ;
if ( ( ( V_19 | V_20 ) & V_24 ) == 0 )
V_21 |= V_25 ;
if ( V_19 & V_26 )
V_21 |= V_27 ;
V_22 = F_7 ( V_7 , 2 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_21 ) ;
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_10 ( struct V_6 * V_7 ,
T_1 V_19 ,
T_1 V_20 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
T_1 V_21 ;
int V_22 ;
V_21 = V_23 | V_25 ;
if ( ( V_19 | V_20 ) & V_24 )
V_21 &= ~ V_25 ;
if ( V_19 & V_30 )
V_21 |= V_31 ;
if ( V_19 & V_32 &&
( F_11 ( V_14 ) || F_12 ( V_14 ) ) )
V_21 |= V_33 ;
V_22 = F_7 ( V_7 , 2 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_21 ) ;
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_13 ( struct V_6 * V_7 )
{
T_1 V_34 = V_7 -> V_35 . V_36 + 2 * V_37 ;
int V_22 ;
V_22 = F_7 ( V_7 , 6 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_14 ( 5 ) ) ;
F_8 ( V_7 , V_38 |
V_39 ) ;
F_8 ( V_7 , V_34 | V_40 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
V_22 = F_7 ( V_7 , 6 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_14 ( 5 ) ) ;
F_8 ( V_7 , V_41 ) ;
F_8 ( V_7 , V_34 | V_40 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_15 ( struct V_6 * V_7 ,
T_1 V_19 , T_1 V_20 )
{
T_1 V_42 = 0 ;
T_1 V_34 = V_7 -> V_35 . V_36 + 2 * V_37 ;
int V_22 ;
V_22 = F_13 ( V_7 ) ;
if ( V_22 )
return V_22 ;
if ( V_20 ) {
V_42 |= V_43 ;
V_42 |= V_44 ;
V_42 |= V_38 ;
}
if ( V_19 ) {
V_42 |= V_45 ;
V_42 |= V_46 ;
V_42 |= V_47 ;
V_42 |= V_48 ;
V_42 |= V_49 ;
V_42 |= V_50 ;
V_42 |= V_41 | V_38 ;
}
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_14 ( 4 ) ) ;
F_8 ( V_7 , V_42 ) ;
F_8 ( V_7 , V_34 | V_40 ) ;
F_8 ( V_7 , 0 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_16 ( struct V_6 * V_7 )
{
int V_22 ;
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_14 ( 4 ) ) ;
F_8 ( V_7 , V_38 |
V_39 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 0 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , T_1 V_51 )
{
int V_22 ;
if ( ! V_7 -> V_52 )
return 0 ;
V_22 = F_7 ( V_7 , 6 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_18 ( 1 ) ) ;
F_8 ( V_7 , V_53 ) ;
F_8 ( V_7 , V_51 ) ;
F_8 ( V_7 , F_19 ( 1 ) | V_54 ) ;
F_8 ( V_7 , V_53 ) ;
F_8 ( V_7 , V_7 -> V_35 . V_36 + 256 ) ;
F_9 ( V_7 ) ;
V_7 -> V_52 = false ;
return 0 ;
}
static int
F_20 ( struct V_6 * V_7 ,
T_1 V_19 , T_1 V_20 )
{
T_1 V_42 = 0 ;
T_1 V_34 = V_7 -> V_35 . V_36 + 2 * V_37 ;
int V_22 ;
V_42 |= V_38 ;
if ( V_20 ) {
V_42 |= V_43 ;
V_42 |= V_44 ;
}
if ( V_19 ) {
V_42 |= V_45 ;
V_42 |= V_46 ;
V_42 |= V_47 ;
V_42 |= V_48 ;
V_42 |= V_49 ;
V_42 |= V_50 ;
V_42 |= V_41 ;
V_42 |= V_55 ;
F_16 ( V_7 ) ;
}
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_14 ( 4 ) ) ;
F_8 ( V_7 , V_42 ) ;
F_8 ( V_7 , V_34 ) ;
F_8 ( V_7 , 0 ) ;
F_9 ( V_7 ) ;
if ( ! V_19 && V_20 )
return F_17 ( V_7 , V_56 ) ;
return 0 ;
}
static int
F_21 ( struct V_6 * V_7 ,
T_1 V_19 , T_1 V_20 )
{
T_1 V_42 = 0 ;
T_1 V_34 = V_7 -> V_35 . V_36 + 2 * V_37 ;
int V_22 ;
V_42 |= V_38 ;
if ( V_20 ) {
V_42 |= V_43 ;
V_42 |= V_44 ;
}
if ( V_19 ) {
V_42 |= V_45 ;
V_42 |= V_46 ;
V_42 |= V_47 ;
V_42 |= V_48 ;
V_42 |= V_49 ;
V_42 |= V_50 ;
V_42 |= V_41 ;
V_42 |= V_55 ;
}
V_22 = F_7 ( V_7 , 6 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_14 ( 6 ) ) ;
F_8 ( V_7 , V_42 ) ;
F_8 ( V_7 , V_34 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 0 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static void F_22 ( struct V_6 * V_7 ,
T_1 V_51 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
F_23 ( V_7 , V_51 ) ;
}
T_2 F_24 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
T_2 V_57 ;
if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 8 )
V_57 = F_26 ( F_27 ( V_7 -> V_59 ) ,
F_28 ( V_7 -> V_59 ) ) ;
else if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 4 )
V_57 = F_29 ( F_27 ( V_7 -> V_59 ) ) ;
else
V_57 = F_29 ( V_60 ) ;
return V_57 ;
}
static void F_30 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
T_1 V_61 ;
V_61 = V_13 -> V_62 -> V_63 ;
if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 4 )
V_61 |= ( V_13 -> V_62 -> V_63 >> 28 ) & 0xf0 ;
F_31 ( V_64 , V_61 ) ;
}
static bool F_32 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_33 ( V_7 -> V_14 ) ;
if ( ! F_34 ( V_7 -> V_14 ) ) {
F_35 ( V_7 , F_36 ( V_65 ) ) ;
if ( F_37 ( ( F_38 ( V_7 ) & V_66 ) != 0 , 1000 ) ) {
F_39 ( L_1 , V_7 -> V_67 ) ;
return false ;
}
}
F_40 ( V_7 , 0 ) ;
F_41 ( V_7 , 0 ) ;
V_7 -> V_18 ( V_7 , 0 ) ;
if ( ! F_34 ( V_7 -> V_14 ) ) {
( void ) F_42 ( V_7 ) ;
F_35 ( V_7 , F_43 ( V_65 ) ) ;
}
return ( F_44 ( V_7 ) & V_11 ) == 0 ;
}
static int F_45 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_68 * V_69 = V_9 -> V_69 ;
int V_22 = 0 ;
F_46 ( V_13 , V_70 ) ;
if ( ! F_32 ( V_7 ) ) {
F_47 ( L_2
L_3 ,
V_7 -> V_67 ,
F_42 ( V_7 ) ,
F_44 ( V_7 ) ,
F_48 ( V_7 ) ,
F_49 ( V_7 ) ) ;
if ( ! F_32 ( V_7 ) ) {
F_39 ( L_4
L_3 ,
V_7 -> V_67 ,
F_42 ( V_7 ) ,
F_44 ( V_7 ) ,
F_48 ( V_7 ) ,
F_49 ( V_7 ) ) ;
V_22 = - V_71 ;
goto V_72;
}
}
if ( F_50 ( V_14 ) )
F_51 ( V_7 ) ;
else
F_30 ( V_7 ) ;
F_52 ( V_7 , F_53 ( V_69 ) ) ;
F_40 ( V_7 ,
( ( V_9 -> V_3 - V_73 ) & V_74 )
| V_75 ) ;
if ( F_54 ( ( F_42 ( V_7 ) & V_75 ) != 0 &&
F_49 ( V_7 ) == F_53 ( V_69 ) &&
( F_44 ( V_7 ) & V_11 ) == 0 , 50 ) ) {
F_39 ( L_5
L_6 ,
V_7 -> V_67 ,
F_42 ( V_7 ) , F_42 ( V_7 ) & V_75 ,
F_44 ( V_7 ) , F_48 ( V_7 ) ,
F_49 ( V_7 ) , ( unsigned long ) F_53 ( V_69 ) ) ;
V_22 = - V_71 ;
goto V_72;
}
if ( ! F_55 ( V_7 -> V_14 , V_76 ) )
F_56 ( V_7 -> V_14 ) ;
else {
V_9 -> V_1 = F_44 ( V_7 ) ;
V_9 -> V_2 = F_48 ( V_7 ) & V_77 ;
V_9 -> V_4 = F_2 ( V_7 ) ;
V_9 -> V_78 = - 1 ;
}
memset ( & V_7 -> V_79 , 0 , sizeof( V_7 -> V_79 ) ) ;
V_72:
F_57 ( V_13 , V_70 ) ;
return V_22 ;
}
static int
F_58 ( struct V_6 * V_7 )
{
int V_22 ;
if ( V_7 -> V_35 . V_69 )
return 0 ;
V_7 -> V_35 . V_69 = F_59 ( V_7 -> V_14 , 4096 ) ;
if ( V_7 -> V_35 . V_69 == NULL ) {
F_39 ( L_7 ) ;
V_22 = - V_80 ;
goto V_81;
}
V_22 = F_60 ( V_7 -> V_35 . V_69 , V_82 ) ;
if ( V_22 )
goto V_83;
V_22 = F_61 ( V_7 -> V_35 . V_69 , 4096 , 0 ) ;
if ( V_22 )
goto V_83;
V_7 -> V_35 . V_36 = F_53 ( V_7 -> V_35 . V_69 ) ;
V_7 -> V_35 . V_84 = F_62 ( F_63 ( V_7 -> V_35 . V_69 -> V_85 -> V_86 ) ) ;
if ( V_7 -> V_35 . V_84 == NULL ) {
V_22 = - V_80 ;
goto V_87;
}
F_64 ( L_8 ,
V_7 -> V_67 , V_7 -> V_35 . V_36 ) ;
return 0 ;
V_87:
F_65 ( V_7 -> V_35 . V_69 ) ;
V_83:
F_66 ( & V_7 -> V_35 . V_69 -> V_88 ) ;
V_81:
return V_22 ;
}
static int F_67 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
int V_22 = F_45 ( V_7 ) ;
if ( F_25 ( V_14 ) -> V_58 >= 4 && F_25 ( V_14 ) -> V_58 < 7 )
F_31 ( V_89 , F_36 ( V_90 ) ) ;
if ( F_25 ( V_14 ) -> V_58 >= 6 )
F_31 ( V_89 , F_36 ( V_91 ) ) ;
if ( F_25 ( V_14 ) -> V_58 == 6 )
F_31 ( V_92 ,
F_36 ( V_93 ) ) ;
if ( F_68 ( V_14 ) )
F_31 ( V_94 ,
F_36 ( V_93 ) |
F_36 ( V_95 ) ) ;
if ( F_25 ( V_14 ) -> V_58 >= 5 ) {
V_22 = F_58 ( V_7 ) ;
if ( V_22 )
return V_22 ;
}
if ( F_69 ( V_14 ) ) {
F_31 ( V_96 ,
F_43 ( V_97 ) ) ;
}
if ( F_25 ( V_14 ) -> V_58 >= 6 )
F_31 ( V_98 , F_36 ( V_99 ) ) ;
if ( F_70 ( V_14 ) )
F_71 ( V_7 , ~ F_72 ( V_14 ) ) ;
return V_22 ;
}
static void F_73 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
if ( V_7 -> V_35 . V_69 == NULL )
return;
if ( F_25 ( V_14 ) -> V_58 >= 5 ) {
F_74 ( F_63 ( V_7 -> V_35 . V_69 -> V_85 -> V_86 ) ) ;
F_65 ( V_7 -> V_35 . V_69 ) ;
}
F_66 ( & V_7 -> V_35 . V_69 -> V_88 ) ;
V_7 -> V_35 . V_69 = NULL ;
}
static int F_75 ( struct V_6 * V_100 ,
unsigned int V_101 )
{
struct V_29 * V_14 = V_100 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_102 ;
int V_103 , V_22 ;
#define F_76 4
if ( F_77 ( V_14 ) )
V_101 += ( ( V_104 - 1 ) * F_76 ) ;
else
return F_7 ( V_100 , V_101 ) ;
V_22 = F_7 ( V_100 , V_101 ) ;
if ( V_22 )
return V_22 ;
#undef F_76
F_78 (useless, dev_priv, i) {
T_1 V_105 = V_100 -> V_106 . V_107 . signal [ V_103 ] ;
if ( V_105 != V_108 ) {
F_8 ( V_100 , F_18 ( 1 ) ) ;
F_8 ( V_100 , V_105 ) ;
F_8 ( V_100 , V_100 -> V_109 ) ;
F_8 ( V_100 , V_28 ) ;
} else {
F_8 ( V_100 , V_28 ) ;
F_8 ( V_100 , V_28 ) ;
F_8 ( V_100 , V_28 ) ;
F_8 ( V_100 , V_28 ) ;
}
}
return 0 ;
}
static int
F_79 ( struct V_6 * V_7 )
{
int V_22 ;
V_22 = V_7 -> V_106 . signal ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_110 ) ;
F_8 ( V_7 , V_111 << V_112 ) ;
F_8 ( V_7 , V_7 -> V_109 ) ;
F_8 ( V_7 , V_113 ) ;
F_5 ( V_7 ) ;
return 0 ;
}
static inline bool F_80 ( struct V_29 * V_14 ,
T_1 V_114 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
return V_13 -> V_115 < V_114 ;
}
static int
F_81 ( struct V_6 * V_116 ,
struct V_6 * V_100 ,
T_1 V_114 )
{
T_1 V_117 = V_118 |
V_119 |
V_120 ;
T_1 V_121 = V_100 -> V_106 . V_107 . V_122 [ V_116 -> V_123 ] ;
int V_22 ;
V_114 -= 1 ;
F_82 ( V_121 == V_124 ) ;
V_22 = F_7 ( V_116 , 4 ) ;
if ( V_22 )
return V_22 ;
if ( F_83 ( ! F_80 ( V_116 -> V_14 , V_114 ) ) ) {
F_8 ( V_116 , V_117 | V_121 ) ;
F_8 ( V_116 , V_114 ) ;
F_8 ( V_116 , 0 ) ;
F_8 ( V_116 , V_28 ) ;
} else {
F_8 ( V_116 , V_28 ) ;
F_8 ( V_116 , V_28 ) ;
F_8 ( V_116 , V_28 ) ;
F_8 ( V_116 , V_28 ) ;
}
F_9 ( V_116 ) ;
return 0 ;
}
static int
F_84 ( struct V_6 * V_7 )
{
T_1 V_34 = V_7 -> V_35 . V_36 + 2 * V_37 ;
int V_22 ;
V_22 = F_7 ( V_7 , 32 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , F_14 ( 4 ) | V_41 |
V_125 |
V_47 ) ;
F_8 ( V_7 , V_7 -> V_35 . V_36 | V_40 ) ;
F_8 ( V_7 , V_7 -> V_109 ) ;
F_8 ( V_7 , 0 ) ;
F_85 ( V_7 , V_34 ) ;
V_34 += 2 * V_37 ;
F_85 ( V_7 , V_34 ) ;
V_34 += 2 * V_37 ;
F_85 ( V_7 , V_34 ) ;
V_34 += 2 * V_37 ;
F_85 ( V_7 , V_34 ) ;
V_34 += 2 * V_37 ;
F_85 ( V_7 , V_34 ) ;
V_34 += 2 * V_37 ;
F_85 ( V_7 , V_34 ) ;
F_8 ( V_7 , F_14 ( 4 ) | V_41 |
V_125 |
V_47 |
V_126 ) ;
F_8 ( V_7 , V_7 -> V_35 . V_36 | V_40 ) ;
F_8 ( V_7 , V_7 -> V_109 ) ;
F_8 ( V_7 , 0 ) ;
F_5 ( V_7 ) ;
return 0 ;
}
static T_1
F_86 ( struct V_6 * V_7 , bool V_127 )
{
if ( ! V_127 ) {
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
F_87 ( F_27 ( V_7 -> V_59 ) ) ;
}
return F_88 ( V_7 , V_111 ) ;
}
static T_1
F_89 ( struct V_6 * V_7 , bool V_127 )
{
return F_88 ( V_7 , V_111 ) ;
}
static void
F_90 ( struct V_6 * V_7 , T_1 V_114 )
{
F_91 ( V_7 , V_111 , V_114 ) ;
}
static T_1
F_92 ( struct V_6 * V_7 , bool V_127 )
{
return V_7 -> V_35 . V_84 [ 0 ] ;
}
static void
F_93 ( struct V_6 * V_7 , T_1 V_114 )
{
V_7 -> V_35 . V_84 [ 0 ] = V_114 ;
}
static bool
F_94 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
if ( ! V_14 -> V_128 )
return false ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( V_7 -> V_130 ++ == 0 )
F_96 ( V_13 , V_7 -> V_131 ) ;
F_97 ( & V_13 -> V_129 , V_42 ) ;
return true ;
}
static void
F_98 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( -- V_7 -> V_130 == 0 )
F_99 ( V_13 , V_7 -> V_131 ) ;
F_97 ( & V_13 -> V_129 , V_42 ) ;
}
static bool
F_100 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
if ( ! V_14 -> V_128 )
return false ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( V_7 -> V_130 ++ == 0 ) {
V_13 -> V_132 &= ~ V_7 -> V_131 ;
F_31 ( V_133 , V_13 -> V_132 ) ;
F_87 ( V_133 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
return true ;
}
static void
F_101 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( -- V_7 -> V_130 == 0 ) {
V_13 -> V_132 |= V_7 -> V_131 ;
F_31 ( V_133 , V_13 -> V_132 ) ;
F_87 ( V_133 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
}
static bool
F_102 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
if ( ! V_14 -> V_128 )
return false ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( V_7 -> V_130 ++ == 0 ) {
V_13 -> V_132 &= ~ V_7 -> V_131 ;
F_103 ( V_133 , V_13 -> V_132 ) ;
F_104 ( V_133 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
return true ;
}
static void
F_105 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( -- V_7 -> V_130 == 0 ) {
V_13 -> V_132 |= V_7 -> V_131 ;
F_103 ( V_133 , V_13 -> V_132 ) ;
F_104 ( V_133 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
}
void F_51 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
T_1 V_134 = 0 ;
if ( F_68 ( V_14 ) ) {
switch ( V_7 -> V_123 ) {
case V_135 :
V_134 = V_136 ;
break;
case V_137 :
V_134 = V_138 ;
break;
case V_139 :
case V_140 :
V_134 = V_141 ;
break;
case V_142 :
V_134 = V_143 ;
break;
}
} else if ( F_69 ( V_7 -> V_14 ) ) {
V_134 = F_106 ( V_7 -> V_59 ) ;
} else {
V_134 = F_107 ( V_7 -> V_59 ) ;
}
F_31 ( V_134 , ( T_1 ) V_7 -> V_144 . V_145 ) ;
F_87 ( V_134 ) ;
if ( F_25 ( V_14 ) -> V_58 >= 6 && F_25 ( V_14 ) -> V_58 < 8 ) {
T_1 V_146 = F_108 ( V_7 -> V_59 ) ;
F_82 ( ( F_38 ( V_7 ) & V_66 ) == 0 ) ;
F_31 ( V_146 ,
F_36 ( V_147 |
V_148 ) ) ;
if ( F_54 ( ( F_29 ( V_146 ) & V_148 ) == 0 ,
1000 ) )
F_39 ( L_9 ,
V_7 -> V_67 ) ;
}
}
static int
F_109 ( struct V_6 * V_7 ,
T_1 V_19 ,
T_1 V_20 )
{
int V_22 ;
V_22 = F_7 ( V_7 , 2 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_23 ) ;
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_110 ( struct V_6 * V_7 )
{
int V_22 ;
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_110 ) ;
F_8 ( V_7 , V_111 << V_112 ) ;
F_8 ( V_7 , V_7 -> V_109 ) ;
F_8 ( V_7 , V_113 ) ;
F_5 ( V_7 ) ;
return 0 ;
}
static bool
F_111 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
if ( ! V_14 -> V_128 )
return false ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( V_7 -> V_130 ++ == 0 ) {
if ( F_70 ( V_14 ) && V_7 -> V_123 == V_135 )
F_71 ( V_7 ,
~ ( V_7 -> V_131 |
F_72 ( V_14 ) ) ) ;
else
F_71 ( V_7 , ~ V_7 -> V_131 ) ;
F_96 ( V_13 , V_7 -> V_131 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
return true ;
}
static void
F_112 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( -- V_7 -> V_130 == 0 ) {
if ( F_70 ( V_14 ) && V_7 -> V_123 == V_135 )
F_71 ( V_7 , ~ F_72 ( V_14 ) ) ;
else
F_71 ( V_7 , ~ 0 ) ;
F_99 ( V_13 , V_7 -> V_131 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
}
static bool
F_113 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
if ( ! V_14 -> V_128 )
return false ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( V_7 -> V_130 ++ == 0 ) {
F_71 ( V_7 , ~ V_7 -> V_131 ) ;
F_114 ( V_13 , V_7 -> V_131 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
return true ;
}
static void
F_115 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
if ( ! V_14 -> V_128 )
return;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( -- V_7 -> V_130 == 0 ) {
F_71 ( V_7 , ~ 0 ) ;
F_116 ( V_13 , V_7 -> V_131 ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
}
static bool
F_117 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
if ( ! V_14 -> V_128 )
return false ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( V_7 -> V_130 ++ == 0 ) {
if ( F_70 ( V_14 ) && V_7 -> V_123 == V_135 ) {
F_71 ( V_7 ,
~ ( V_7 -> V_131 |
V_149 ) ) ;
} else {
F_71 ( V_7 , ~ V_7 -> V_131 ) ;
}
F_87 ( F_118 ( V_7 -> V_59 ) ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
return true ;
}
static void
F_119 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
unsigned long V_42 ;
F_95 ( & V_13 -> V_129 , V_42 ) ;
if ( -- V_7 -> V_130 == 0 ) {
if ( F_70 ( V_14 ) && V_7 -> V_123 == V_135 ) {
F_71 ( V_7 ,
~ V_149 ) ;
} else {
F_71 ( V_7 , ~ 0 ) ;
}
F_87 ( F_118 ( V_7 -> V_59 ) ) ;
}
F_97 ( & V_13 -> V_129 , V_42 ) ;
}
static int
F_120 ( struct V_6 * V_7 ,
T_2 V_150 , T_1 V_151 ,
unsigned V_42 )
{
int V_22 ;
V_22 = F_7 ( V_7 , 2 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 ,
V_152 |
V_153 |
( V_42 & V_154 ? 0 : V_155 ) ) ;
F_8 ( V_7 , V_150 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_121 ( struct V_6 * V_7 ,
T_2 V_150 , T_1 V_156 ,
unsigned V_42 )
{
int V_22 ;
if ( V_42 & V_157 ) {
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_158 ) ;
F_8 ( V_7 , V_150 | ( V_42 & V_154 ? 0 : V_159 ) ) ;
F_8 ( V_7 , V_150 + V_156 - 8 ) ;
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
} else {
T_1 V_160 = V_7 -> V_35 . V_36 ;
if ( V_156 > V_161 )
return - V_162 ;
V_22 = F_7 ( V_7 , 9 + 3 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_163 |
V_164 |
V_165 ) ;
F_8 ( V_7 , V_166 | V_167 | 4096 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , ( F_122 ( V_156 , 4096 ) << 16 ) | 1024 ) ;
F_8 ( V_7 , V_160 ) ;
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 4096 ) ;
F_8 ( V_7 , V_150 ) ;
F_8 ( V_7 , V_23 ) ;
F_8 ( V_7 , V_158 ) ;
F_8 ( V_7 , V_160 | ( V_42 & V_154 ? 0 : V_159 ) ) ;
F_8 ( V_7 , V_160 + V_156 - 8 ) ;
F_9 ( V_7 ) ;
}
return 0 ;
}
static int
F_123 ( struct V_6 * V_7 ,
T_2 V_150 , T_1 V_156 ,
unsigned V_42 )
{
int V_22 ;
V_22 = F_7 ( V_7 , 2 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_152 | V_153 ) ;
F_8 ( V_7 , V_150 | ( V_42 & V_154 ? 0 : V_159 ) ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static void F_124 ( struct V_6 * V_7 )
{
struct V_68 * V_69 ;
V_69 = V_7 -> V_144 . V_69 ;
if ( V_69 == NULL )
return;
F_74 ( F_63 ( V_69 -> V_85 -> V_86 ) ) ;
F_65 ( V_69 ) ;
F_66 ( & V_69 -> V_88 ) ;
V_7 -> V_144 . V_69 = NULL ;
}
static int F_125 ( struct V_6 * V_7 )
{
struct V_68 * V_69 ;
if ( ( V_69 = V_7 -> V_144 . V_69 ) == NULL ) {
int V_22 ;
V_69 = F_59 ( V_7 -> V_14 , 4096 ) ;
if ( V_69 == NULL ) {
F_39 ( L_10 ) ;
return - V_80 ;
}
V_22 = F_60 ( V_69 , V_82 ) ;
if ( V_22 )
goto V_83;
V_22 = F_61 ( V_69 , 4096 , 0 ) ;
if ( V_22 ) {
V_83:
F_66 ( & V_69 -> V_88 ) ;
return V_22 ;
}
V_7 -> V_144 . V_69 = V_69 ;
}
V_7 -> V_144 . V_145 = F_53 ( V_69 ) ;
V_7 -> V_144 . V_168 = F_62 ( F_63 ( V_69 -> V_85 -> V_86 ) ) ;
memset ( V_7 -> V_144 . V_168 , 0 , V_73 ) ;
F_64 ( L_11 ,
V_7 -> V_67 , V_7 -> V_144 . V_145 ) ;
return 0 ;
}
static int F_126 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
if ( ! V_13 -> V_62 ) {
V_13 -> V_62 =
F_127 ( V_7 -> V_14 , V_73 , V_73 ) ;
if ( ! V_13 -> V_62 )
return - V_80 ;
}
V_7 -> V_144 . V_168 = V_13 -> V_62 -> V_169 ;
memset ( V_7 -> V_144 . V_168 , 0 , V_73 ) ;
return 0 ;
}
static int F_128 ( struct V_6 * V_7 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = F_33 ( V_14 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_68 * V_69 ;
int V_22 ;
if ( F_129 ( V_7 ) )
return 0 ;
V_69 = NULL ;
if ( ! F_130 ( V_14 ) )
V_69 = F_131 ( V_14 , V_9 -> V_3 ) ;
if ( V_69 == NULL )
V_69 = F_59 ( V_14 , V_9 -> V_3 ) ;
if ( V_69 == NULL )
return - V_80 ;
V_22 = F_61 ( V_69 , V_73 , V_170 ) ;
if ( V_22 )
goto V_83;
V_22 = F_132 ( V_69 , true ) ;
if ( V_22 )
goto V_87;
V_9 -> V_171 =
F_133 ( V_13 -> V_172 . V_173 + F_53 ( V_69 ) ,
V_9 -> V_3 ) ;
if ( V_9 -> V_171 == NULL ) {
V_22 = - V_174 ;
goto V_87;
}
V_9 -> V_69 = V_69 ;
return 0 ;
V_87:
F_65 ( V_69 ) ;
V_83:
F_66 ( & V_69 -> V_88 ) ;
return V_22 ;
}
static int F_134 ( struct V_29 * V_14 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
int V_22 ;
if ( V_9 == NULL ) {
V_9 = F_135 ( sizeof( * V_9 ) , V_175 ) ;
if ( ! V_9 )
return - V_80 ;
V_7 -> V_10 = V_9 ;
}
V_7 -> V_14 = V_14 ;
F_136 ( & V_7 -> V_176 ) ;
F_136 ( & V_7 -> V_177 ) ;
V_9 -> V_3 = 32 * V_73 ;
memset ( V_7 -> V_106 . V_178 , 0 , sizeof( V_7 -> V_106 . V_178 ) ) ;
F_137 ( & V_7 -> V_179 ) ;
if ( F_50 ( V_14 ) ) {
V_22 = F_125 ( V_7 ) ;
if ( V_22 )
goto error;
} else {
F_138 ( V_7 -> V_123 != V_135 ) ;
V_22 = F_126 ( V_7 ) ;
if ( V_22 )
goto error;
}
V_22 = F_128 ( V_7 ) ;
if ( V_22 ) {
F_39 ( L_12 , V_7 -> V_67 , V_22 ) ;
goto error;
}
V_9 -> V_180 = V_9 -> V_3 ;
if ( F_139 ( V_14 ) || F_140 ( V_14 ) )
V_9 -> V_180 -= 2 * V_37 ;
V_22 = F_141 ( V_7 ) ;
if ( V_22 )
goto error;
V_22 = V_7 -> V_181 ( V_7 ) ;
if ( V_22 )
goto error;
return 0 ;
error:
F_142 ( V_9 ) ;
V_7 -> V_10 = NULL ;
return V_22 ;
}
void F_143 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_33 ( V_7 -> V_14 ) ;
struct V_8 * V_9 = V_7 -> V_10 ;
if ( ! F_129 ( V_7 ) )
return;
F_144 ( V_7 ) ;
F_82 ( ! F_34 ( V_7 -> V_14 ) && ( F_38 ( V_7 ) & V_66 ) == 0 ) ;
F_145 ( V_9 -> V_171 ) ;
F_65 ( V_9 -> V_69 ) ;
F_66 ( & V_9 -> V_69 -> V_88 ) ;
V_9 -> V_69 = NULL ;
V_7 -> V_182 = NULL ;
V_7 -> V_109 = 0 ;
if ( V_7 -> V_183 )
V_7 -> V_183 ( V_7 ) ;
F_124 ( V_7 ) ;
F_146 ( V_7 ) ;
F_142 ( V_9 ) ;
V_7 -> V_10 = NULL ;
}
static int F_147 ( struct V_6 * V_7 , int V_184 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_185 * V_186 ;
T_1 V_114 = 0 ;
int V_22 ;
if ( V_9 -> V_78 != - 1 ) {
V_9 -> V_1 = V_9 -> V_78 ;
V_9 -> V_78 = - 1 ;
V_9 -> V_4 = F_2 ( V_7 ) ;
if ( V_9 -> V_4 >= V_184 )
return 0 ;
}
F_148 (request, &ring->request_list, list) {
if ( F_1 ( V_186 -> V_2 , V_9 -> V_2 , V_9 -> V_3 ) >= V_184 ) {
V_114 = V_186 -> V_114 ;
break;
}
}
if ( V_114 == 0 )
return - V_162 ;
V_22 = F_149 ( V_7 , V_114 ) ;
if ( V_22 )
return V_22 ;
F_150 ( V_7 ) ;
V_9 -> V_1 = V_9 -> V_78 ;
V_9 -> V_78 = - 1 ;
V_9 -> V_4 = F_2 ( V_7 ) ;
return 0 ;
}
static int F_151 ( struct V_6 * V_7 , int V_184 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_8 * V_9 = V_7 -> V_10 ;
unsigned long V_187 ;
int V_22 ;
V_22 = F_147 ( V_7 , V_184 ) ;
if ( V_22 != - V_162 )
return V_22 ;
F_5 ( V_7 ) ;
V_187 = V_188 + 60 * V_189 ;
F_152 ( V_7 ) ;
do {
V_9 -> V_1 = F_44 ( V_7 ) ;
V_9 -> V_4 = F_2 ( V_7 ) ;
if ( V_9 -> V_4 >= V_184 ) {
V_22 = 0 ;
break;
}
if ( ! F_55 ( V_14 , V_76 ) &&
V_14 -> V_190 -> V_191 ) {
struct V_192 * V_193 = V_14 -> V_190 -> V_191 -> V_194 ;
if ( V_193 -> V_195 )
V_193 -> V_195 -> V_196 |= V_197 ;
}
F_153 ( 1 ) ;
if ( V_13 -> V_198 . V_199 && F_154 ( V_200 ) ) {
V_22 = - V_201 ;
break;
}
V_22 = F_155 ( & V_13 -> V_16 ,
V_13 -> V_198 . V_199 ) ;
if ( V_22 )
break;
if ( F_156 ( V_188 , V_187 ) ) {
V_22 = - V_202 ;
break;
}
} while ( 1 );
F_157 ( V_7 ) ;
return V_22 ;
}
static int F_158 ( struct V_6 * V_7 )
{
T_3 T_4 * V_203 ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_204 = V_9 -> V_3 - V_9 -> V_2 ;
if ( V_9 -> V_4 < V_204 ) {
int V_22 = F_151 ( V_7 , V_204 ) ;
if ( V_22 )
return V_22 ;
}
V_203 = V_9 -> V_171 + V_9 -> V_2 ;
V_204 /= 4 ;
while ( V_204 -- )
F_159 ( V_28 , V_203 ++ ) ;
V_9 -> V_2 = 0 ;
V_9 -> V_4 = F_2 ( V_7 ) ;
return 0 ;
}
int F_160 ( struct V_6 * V_7 )
{
T_1 V_114 ;
int V_22 ;
if ( V_7 -> V_109 ) {
V_22 = F_161 ( V_7 , NULL ) ;
if ( V_22 )
return V_22 ;
}
if ( F_162 ( & V_7 -> V_177 ) )
return 0 ;
V_114 = F_163 ( V_7 -> V_177 . V_205 ,
struct V_185 ,
V_206 ) -> V_114 ;
return F_149 ( V_7 , V_114 ) ;
}
static int
F_164 ( struct V_6 * V_7 )
{
if ( V_7 -> V_109 )
return 0 ;
if ( V_7 -> V_182 == NULL ) {
struct V_185 * V_186 ;
V_186 = F_165 ( sizeof( * V_186 ) , V_175 ) ;
if ( V_186 == NULL )
return - V_80 ;
V_7 -> V_182 = V_186 ;
}
return F_166 ( V_7 -> V_14 , & V_7 -> V_109 ) ;
}
static int F_167 ( struct V_6 * V_7 ,
int V_207 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
int V_22 ;
if ( F_168 ( V_9 -> V_2 + V_207 > V_9 -> V_180 ) ) {
V_22 = F_158 ( V_7 ) ;
if ( F_168 ( V_22 ) )
return V_22 ;
}
if ( F_168 ( V_9 -> V_4 < V_207 ) ) {
V_22 = F_151 ( V_7 , V_207 ) ;
if ( F_168 ( V_22 ) )
return V_22 ;
}
return 0 ;
}
int F_7 ( struct V_6 * V_7 ,
int V_101 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
int V_22 ;
V_22 = F_155 ( & V_13 -> V_16 ,
V_13 -> V_198 . V_199 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_167 ( V_7 , V_101 * sizeof( T_3 ) ) ;
if ( V_22 )
return V_22 ;
V_22 = F_164 ( V_7 ) ;
if ( V_22 )
return V_22 ;
V_7 -> V_10 -> V_4 -= V_101 * sizeof( T_3 ) ;
return 0 ;
}
int F_169 ( struct V_6 * V_7 )
{
int V_101 = ( V_7 -> V_10 -> V_2 & ( V_37 - 1 ) ) / sizeof( T_3 ) ;
int V_22 ;
if ( V_101 == 0 )
return 0 ;
V_101 = V_37 / sizeof( T_3 ) - V_101 ;
V_22 = F_7 ( V_7 , V_101 ) ;
if ( V_22 )
return V_22 ;
while ( V_101 -- )
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
void F_170 ( struct V_6 * V_7 , T_1 V_114 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
F_138 ( V_7 -> V_109 ) ;
if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 6 ) {
F_31 ( F_171 ( V_7 -> V_59 ) , 0 ) ;
F_31 ( F_172 ( V_7 -> V_59 ) , 0 ) ;
if ( F_173 ( V_7 -> V_14 ) )
F_31 ( F_174 ( V_7 -> V_59 ) , 0 ) ;
}
V_7 -> V_208 ( V_7 , V_114 ) ;
V_7 -> V_79 . V_114 = V_114 ;
}
static void F_175 ( struct V_6 * V_7 ,
T_1 V_51 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
F_31 ( V_209 ,
F_36 ( V_210 ) ) ;
F_176 ( V_211 , 0x0 ) ;
if ( F_54 ( ( F_29 ( V_209 ) &
V_212 ) == 0 ,
50 ) )
F_39 ( L_13 ) ;
F_23 ( V_7 , V_51 ) ;
F_87 ( F_177 ( V_7 -> V_59 ) ) ;
F_31 ( V_209 ,
F_43 ( V_210 ) ) ;
}
static int F_178 ( struct V_6 * V_7 ,
T_1 V_213 , T_1 V_214 )
{
T_3 V_21 ;
int V_22 ;
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
V_21 = V_215 ;
if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 8 )
V_21 += 1 ;
if ( V_213 & V_216 )
V_21 |= V_217 | V_218 |
V_219 | V_220 ;
F_8 ( V_7 , V_21 ) ;
F_8 ( V_7 , V_221 | V_222 ) ;
if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 8 ) {
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 0 ) ;
} else {
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , V_28 ) ;
}
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_179 ( struct V_6 * V_7 ,
T_2 V_150 , T_1 V_156 ,
unsigned V_42 )
{
struct V_12 * V_13 = V_7 -> V_14 -> V_15 ;
bool V_223 = V_13 -> V_198 . V_224 != NULL &&
! ( V_42 & V_154 ) ;
int V_22 ;
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 , V_225 | ( V_223 << 8 ) ) ;
F_8 ( V_7 , F_180 ( V_150 ) ) ;
F_8 ( V_7 , F_181 ( V_150 ) ) ;
F_8 ( V_7 , V_28 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_182 ( struct V_6 * V_7 ,
T_2 V_150 , T_1 V_156 ,
unsigned V_42 )
{
int V_22 ;
V_22 = F_7 ( V_7 , 2 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 ,
V_152 | V_226 |
( V_42 & V_154 ? 0 : V_227 ) ) ;
F_8 ( V_7 , V_150 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int
F_183 ( struct V_6 * V_7 ,
T_2 V_150 , T_1 V_156 ,
unsigned V_42 )
{
int V_22 ;
V_22 = F_7 ( V_7 , 2 ) ;
if ( V_22 )
return V_22 ;
F_8 ( V_7 ,
V_152 |
( V_42 & V_154 ? 0 : V_155 ) ) ;
F_8 ( V_7 , V_150 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_184 ( struct V_6 * V_7 ,
T_1 V_213 , T_1 V_214 )
{
struct V_29 * V_14 = V_7 -> V_14 ;
T_3 V_21 ;
int V_22 ;
V_22 = F_7 ( V_7 , 4 ) ;
if ( V_22 )
return V_22 ;
V_21 = V_215 ;
if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 8 )
V_21 += 1 ;
if ( V_213 & V_24 )
V_21 |= V_217 | V_219 |
V_220 ;
F_8 ( V_7 , V_21 ) ;
F_8 ( V_7 , V_221 | V_222 ) ;
if ( F_25 ( V_7 -> V_14 ) -> V_58 >= 8 ) {
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , 0 ) ;
} else {
F_8 ( V_7 , 0 ) ;
F_8 ( V_7 , V_28 ) ;
}
F_9 ( V_7 ) ;
if ( F_68 ( V_14 ) && ! V_213 && V_214 )
return F_17 ( V_7 , V_228 ) ;
return 0 ;
}
int F_185 ( struct V_29 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = & V_13 -> V_7 [ V_135 ] ;
V_7 -> V_67 = L_14 ;
V_7 -> V_123 = V_135 ;
V_7 -> V_59 = V_229 ;
if ( F_25 ( V_14 ) -> V_58 >= 6 ) {
V_7 -> V_230 = F_79 ;
V_7 -> V_214 = F_20 ;
if ( F_25 ( V_14 ) -> V_58 == 6 )
V_7 -> V_214 = F_15 ;
if ( F_25 ( V_14 ) -> V_58 >= 8 ) {
V_7 -> V_214 = F_21 ;
V_7 -> V_231 = F_117 ;
V_7 -> V_232 = F_119 ;
} else {
V_7 -> V_231 = F_111 ;
V_7 -> V_232 = F_112 ;
}
V_7 -> V_131 = V_233 ;
V_7 -> V_234 = F_86 ;
V_7 -> V_208 = F_90 ;
V_7 -> V_106 . V_235 = F_81 ;
V_7 -> V_106 . signal = F_75 ;
V_7 -> V_106 . V_107 . V_122 [ V_135 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_140 ] = V_236 ;
V_7 -> V_106 . V_107 . V_122 [ V_137 ] = V_237 ;
V_7 -> V_106 . V_107 . V_122 [ V_142 ] = V_238 ;
V_7 -> V_106 . V_107 . V_122 [ V_139 ] = V_124 ;
V_7 -> V_106 . V_107 . signal [ V_135 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_140 ] = V_239 ;
V_7 -> V_106 . V_107 . signal [ V_137 ] = V_240 ;
V_7 -> V_106 . V_107 . signal [ V_142 ] = V_241 ;
V_7 -> V_106 . V_107 . signal [ V_139 ] = V_108 ;
} else if ( F_12 ( V_14 ) ) {
V_7 -> V_230 = F_84 ;
V_7 -> V_214 = F_10 ;
V_7 -> V_234 = F_92 ;
V_7 -> V_208 = F_93 ;
V_7 -> V_231 = F_94 ;
V_7 -> V_232 = F_98 ;
V_7 -> V_131 = V_233 |
V_242 ;
} else {
V_7 -> V_230 = F_110 ;
if ( F_25 ( V_14 ) -> V_58 < 4 )
V_7 -> V_214 = F_6 ;
else
V_7 -> V_214 = F_10 ;
V_7 -> V_234 = F_89 ;
V_7 -> V_208 = F_90 ;
if ( F_34 ( V_14 ) ) {
V_7 -> V_231 = F_102 ;
V_7 -> V_232 = F_105 ;
} else {
V_7 -> V_231 = F_100 ;
V_7 -> V_232 = F_101 ;
}
V_7 -> V_131 = V_243 ;
}
V_7 -> V_18 = F_22 ;
if ( F_186 ( V_14 ) )
V_7 -> V_244 = F_182 ;
else if ( F_187 ( V_14 ) )
V_7 -> V_244 = F_179 ;
else if ( F_25 ( V_14 ) -> V_58 >= 6 )
V_7 -> V_244 = F_183 ;
else if ( F_25 ( V_14 ) -> V_58 >= 4 )
V_7 -> V_244 = F_120 ;
else if ( F_139 ( V_14 ) || F_140 ( V_14 ) )
V_7 -> V_244 = F_121 ;
else
V_7 -> V_244 = F_123 ;
V_7 -> V_181 = F_67 ;
V_7 -> V_183 = F_73 ;
if ( F_188 ( V_14 ) ) {
struct V_68 * V_69 ;
int V_22 ;
V_69 = F_59 ( V_14 , V_161 ) ;
if ( V_69 == NULL ) {
F_39 ( L_15 ) ;
return - V_80 ;
}
V_22 = F_61 ( V_69 , 0 , 0 ) ;
if ( V_22 != 0 ) {
F_66 ( & V_69 -> V_88 ) ;
F_39 ( L_16 ) ;
return V_22 ;
}
V_7 -> V_35 . V_69 = V_69 ;
V_7 -> V_35 . V_36 = F_53 ( V_69 ) ;
}
return F_134 ( V_14 , V_7 ) ;
}
int F_189 ( struct V_29 * V_14 , T_2 V_245 , T_1 V_3 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = & V_13 -> V_7 [ V_135 ] ;
struct V_8 * V_9 = V_7 -> V_10 ;
int V_22 ;
if ( V_9 == NULL ) {
V_9 = F_135 ( sizeof( * V_9 ) , V_175 ) ;
if ( ! V_9 )
return - V_80 ;
V_7 -> V_10 = V_9 ;
}
V_7 -> V_67 = L_14 ;
V_7 -> V_123 = V_135 ;
V_7 -> V_59 = V_229 ;
if ( F_25 ( V_14 ) -> V_58 >= 6 ) {
V_22 = - V_246 ;
goto V_247;
}
V_7 -> V_230 = F_110 ;
if ( F_25 ( V_14 ) -> V_58 < 4 )
V_7 -> V_214 = F_6 ;
else
V_7 -> V_214 = F_10 ;
V_7 -> V_234 = F_89 ;
V_7 -> V_208 = F_90 ;
if ( F_34 ( V_14 ) ) {
V_7 -> V_231 = F_102 ;
V_7 -> V_232 = F_105 ;
} else {
V_7 -> V_231 = F_100 ;
V_7 -> V_232 = F_101 ;
}
V_7 -> V_131 = V_243 ;
V_7 -> V_18 = F_22 ;
if ( F_25 ( V_14 ) -> V_58 >= 4 )
V_7 -> V_244 = F_120 ;
else if ( F_139 ( V_14 ) || F_140 ( V_14 ) )
V_7 -> V_244 = F_121 ;
else
V_7 -> V_244 = F_123 ;
V_7 -> V_181 = F_67 ;
V_7 -> V_183 = F_73 ;
V_7 -> V_14 = V_14 ;
F_136 ( & V_7 -> V_176 ) ;
F_136 ( & V_7 -> V_177 ) ;
V_9 -> V_3 = V_3 ;
V_9 -> V_180 = V_9 -> V_3 ;
if ( F_139 ( V_7 -> V_14 ) || F_140 ( V_7 -> V_14 ) )
V_9 -> V_180 -= 2 * V_37 ;
V_9 -> V_171 = F_133 ( V_245 , V_3 ) ;
if ( V_9 -> V_171 == NULL ) {
F_39 ( L_17
L_18 ) ;
V_22 = - V_80 ;
goto V_247;
}
if ( ! F_50 ( V_14 ) ) {
V_22 = F_126 ( V_7 ) ;
if ( V_22 )
goto V_248;
}
return 0 ;
V_248:
F_145 ( V_9 -> V_171 ) ;
V_247:
F_142 ( V_9 ) ;
V_7 -> V_10 = NULL ;
return V_22 ;
}
int F_190 ( struct V_29 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = & V_13 -> V_7 [ V_140 ] ;
V_7 -> V_67 = L_19 ;
V_7 -> V_123 = V_140 ;
V_7 -> V_18 = F_22 ;
if ( F_25 ( V_14 ) -> V_58 >= 6 ) {
V_7 -> V_59 = V_249 ;
if ( F_69 ( V_14 ) )
V_7 -> V_18 = F_175 ;
V_7 -> V_214 = F_178 ;
V_7 -> V_230 = F_79 ;
V_7 -> V_234 = F_86 ;
V_7 -> V_208 = F_90 ;
if ( F_25 ( V_14 ) -> V_58 >= 8 ) {
V_7 -> V_131 =
V_233 << V_250 ;
V_7 -> V_231 = F_117 ;
V_7 -> V_232 = F_119 ;
V_7 -> V_244 =
F_179 ;
} else {
V_7 -> V_131 = V_251 ;
V_7 -> V_231 = F_111 ;
V_7 -> V_232 = F_112 ;
V_7 -> V_244 =
F_183 ;
}
V_7 -> V_106 . V_235 = F_81 ;
V_7 -> V_106 . signal = F_75 ;
V_7 -> V_106 . V_107 . V_122 [ V_135 ] = V_252 ;
V_7 -> V_106 . V_107 . V_122 [ V_140 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_137 ] = V_253 ;
V_7 -> V_106 . V_107 . V_122 [ V_142 ] = V_254 ;
V_7 -> V_106 . V_107 . V_122 [ V_139 ] = V_124 ;
V_7 -> V_106 . V_107 . signal [ V_135 ] = V_255 ;
V_7 -> V_106 . V_107 . signal [ V_140 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_137 ] = V_256 ;
V_7 -> V_106 . V_107 . signal [ V_142 ] = V_257 ;
V_7 -> V_106 . V_107 . signal [ V_139 ] = V_108 ;
} else {
V_7 -> V_59 = V_258 ;
V_7 -> V_214 = F_109 ;
V_7 -> V_230 = F_110 ;
V_7 -> V_234 = F_89 ;
V_7 -> V_208 = F_90 ;
if ( F_12 ( V_14 ) ) {
V_7 -> V_131 = V_259 ;
V_7 -> V_231 = F_94 ;
V_7 -> V_232 = F_98 ;
} else {
V_7 -> V_131 = V_260 ;
V_7 -> V_231 = F_100 ;
V_7 -> V_232 = F_101 ;
}
V_7 -> V_244 = F_120 ;
}
V_7 -> V_181 = F_45 ;
return F_134 ( V_14 , V_7 ) ;
}
int F_191 ( struct V_29 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = & V_13 -> V_7 [ V_139 ] ;
if ( ( F_25 ( V_14 ) -> V_58 != 8 ) ) {
F_39 ( L_20 ) ;
return - V_174 ;
}
V_7 -> V_67 = L_21 ;
V_7 -> V_123 = V_139 ;
V_7 -> V_18 = F_22 ;
V_7 -> V_59 = V_261 ;
V_7 -> V_214 = F_178 ;
V_7 -> V_230 = F_79 ;
V_7 -> V_234 = F_86 ;
V_7 -> V_208 = F_90 ;
V_7 -> V_131 =
V_233 << V_262 ;
V_7 -> V_231 = F_117 ;
V_7 -> V_232 = F_119 ;
V_7 -> V_244 =
F_179 ;
V_7 -> V_106 . V_235 = F_81 ;
V_7 -> V_106 . signal = F_75 ;
V_7 -> V_106 . V_107 . V_122 [ V_135 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_140 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_137 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_142 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_139 ] = V_124 ;
V_7 -> V_106 . V_107 . signal [ V_135 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_140 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_137 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_142 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_139 ] = V_108 ;
V_7 -> V_181 = F_45 ;
return F_134 ( V_14 , V_7 ) ;
}
int F_192 ( struct V_29 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = & V_13 -> V_7 [ V_137 ] ;
V_7 -> V_67 = L_22 ;
V_7 -> V_123 = V_137 ;
V_7 -> V_59 = V_263 ;
V_7 -> V_18 = F_22 ;
V_7 -> V_214 = F_184 ;
V_7 -> V_230 = F_79 ;
V_7 -> V_234 = F_86 ;
V_7 -> V_208 = F_90 ;
if ( F_25 ( V_14 ) -> V_58 >= 8 ) {
V_7 -> V_131 =
V_233 << V_264 ;
V_7 -> V_231 = F_117 ;
V_7 -> V_232 = F_119 ;
V_7 -> V_244 = F_179 ;
} else {
V_7 -> V_131 = V_265 ;
V_7 -> V_231 = F_111 ;
V_7 -> V_232 = F_112 ;
V_7 -> V_244 = F_183 ;
}
V_7 -> V_106 . V_235 = F_81 ;
V_7 -> V_106 . signal = F_75 ;
V_7 -> V_106 . V_107 . V_122 [ V_135 ] = V_266 ;
V_7 -> V_106 . V_107 . V_122 [ V_140 ] = V_267 ;
V_7 -> V_106 . V_107 . V_122 [ V_137 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_142 ] = V_268 ;
V_7 -> V_106 . V_107 . V_122 [ V_139 ] = V_124 ;
V_7 -> V_106 . V_107 . signal [ V_135 ] = V_269 ;
V_7 -> V_106 . V_107 . signal [ V_140 ] = V_270 ;
V_7 -> V_106 . V_107 . signal [ V_137 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_142 ] = V_271 ;
V_7 -> V_106 . V_107 . signal [ V_139 ] = V_108 ;
V_7 -> V_181 = F_45 ;
return F_134 ( V_14 , V_7 ) ;
}
int F_193 ( struct V_29 * V_14 )
{
struct V_12 * V_13 = V_14 -> V_15 ;
struct V_6 * V_7 = & V_13 -> V_7 [ V_142 ] ;
V_7 -> V_67 = L_23 ;
V_7 -> V_123 = V_142 ;
V_7 -> V_59 = V_272 ;
V_7 -> V_18 = F_22 ;
V_7 -> V_214 = F_184 ;
V_7 -> V_230 = F_79 ;
V_7 -> V_234 = F_86 ;
V_7 -> V_208 = F_90 ;
if ( F_25 ( V_14 ) -> V_58 >= 8 ) {
V_7 -> V_131 =
V_233 << V_273 ;
V_7 -> V_231 = F_117 ;
V_7 -> V_232 = F_119 ;
V_7 -> V_244 = F_179 ;
} else {
V_7 -> V_131 = V_274 ;
V_7 -> V_231 = F_113 ;
V_7 -> V_232 = F_115 ;
V_7 -> V_244 = F_183 ;
}
V_7 -> V_106 . V_235 = F_81 ;
V_7 -> V_106 . signal = F_75 ;
V_7 -> V_106 . V_107 . V_122 [ V_135 ] = V_275 ;
V_7 -> V_106 . V_107 . V_122 [ V_140 ] = V_276 ;
V_7 -> V_106 . V_107 . V_122 [ V_137 ] = V_277 ;
V_7 -> V_106 . V_107 . V_122 [ V_142 ] = V_124 ;
V_7 -> V_106 . V_107 . V_122 [ V_139 ] = V_124 ;
V_7 -> V_106 . V_107 . signal [ V_135 ] = V_278 ;
V_7 -> V_106 . V_107 . signal [ V_140 ] = V_279 ;
V_7 -> V_106 . V_107 . signal [ V_137 ] = V_280 ;
V_7 -> V_106 . V_107 . signal [ V_142 ] = V_108 ;
V_7 -> V_106 . V_107 . signal [ V_139 ] = V_108 ;
V_7 -> V_181 = F_45 ;
return F_134 ( V_14 , V_7 ) ;
}
int
F_194 ( struct V_6 * V_7 )
{
int V_22 ;
if ( ! V_7 -> V_281 )
return 0 ;
V_22 = V_7 -> V_214 ( V_7 , 0 , V_216 ) ;
if ( V_22 )
return V_22 ;
F_195 ( V_7 , 0 , V_216 ) ;
V_7 -> V_281 = false ;
return 0 ;
}
int
F_196 ( struct V_6 * V_7 )
{
T_3 V_20 ;
int V_22 ;
V_20 = 0 ;
if ( V_7 -> V_281 )
V_20 = V_216 ;
V_22 = V_7 -> V_214 ( V_7 , V_216 , V_20 ) ;
if ( V_22 )
return V_22 ;
F_195 ( V_7 , V_216 , V_20 ) ;
V_7 -> V_281 = false ;
return 0 ;
}
void
F_144 ( struct V_6 * V_7 )
{
int V_22 ;
if ( ! F_129 ( V_7 ) )
return;
V_22 = F_160 ( V_7 ) ;
if ( V_22 && ! F_197 ( & F_33 ( V_7 -> V_14 ) -> V_16 ) )
F_39 ( L_24 ,
V_7 -> V_67 , V_22 ) ;
F_32 ( V_7 ) ;
}
