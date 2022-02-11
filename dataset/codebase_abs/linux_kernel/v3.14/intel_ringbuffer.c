static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 & V_5 ) - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
return V_3 ;
}
void F_2 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
V_2 -> V_6 &= V_2 -> V_8 - 1 ;
if ( V_10 -> V_13 . V_14 & F_3 ( V_2 ) )
return;
V_2 -> V_15 ( V_2 , V_2 -> V_6 ) ;
}
static int
F_4 ( struct V_1 * V_2 ,
T_1 V_16 ,
T_1 V_17 )
{
T_1 V_18 ;
int V_19 ;
V_18 = V_20 ;
if ( ( ( V_16 | V_17 ) & V_21 ) == 0 )
V_18 |= V_22 ;
if ( V_16 & V_23 )
V_18 |= V_24 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 ,
T_1 V_16 ,
T_1 V_17 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_1 V_18 ;
int V_19 ;
V_18 = V_20 | V_22 ;
if ( ( V_16 | V_17 ) & V_21 )
V_18 &= ~ V_22 ;
if ( V_16 & V_27 )
V_18 |= V_28 ;
if ( V_16 & V_29 &&
( F_9 ( V_11 ) || F_10 ( V_11 ) ) )
V_18 |= V_30 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 )
{
T_1 V_31 = V_2 -> V_32 . V_33 + 128 ;
int V_19 ;
V_19 = F_5 ( V_2 , 6 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 5 ) ) ;
F_6 ( V_2 , V_34 |
V_35 ) ;
F_6 ( V_2 , V_31 | V_36 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
V_19 = F_5 ( V_2 , 6 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 5 ) ) ;
F_6 ( V_2 , V_37 ) ;
F_6 ( V_2 , V_31 | V_36 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 )
{
T_1 V_38 = 0 ;
T_1 V_31 = V_2 -> V_32 . V_33 + 128 ;
int V_19 ;
V_19 = F_11 ( V_2 ) ;
if ( V_19 )
return V_19 ;
if ( V_17 ) {
V_38 |= V_39 ;
V_38 |= V_40 ;
V_38 |= V_34 ;
}
if ( V_16 ) {
V_38 |= V_41 ;
V_38 |= V_42 ;
V_38 |= V_43 ;
V_38 |= V_44 ;
V_38 |= V_45 ;
V_38 |= V_46 ;
V_38 |= V_37 | V_34 ;
}
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 4 ) ) ;
F_6 ( V_2 , V_38 ) ;
F_6 ( V_2 , V_31 | V_36 ) ;
F_6 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_14 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 4 ) ) ;
F_6 ( V_2 , V_34 |
V_35 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_1 V_47 )
{
int V_19 ;
if ( ! V_2 -> V_48 )
return 0 ;
V_19 = F_5 ( V_2 , 6 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_16 ( 1 ) ) ;
F_6 ( V_2 , V_49 ) ;
F_6 ( V_2 , V_47 ) ;
F_6 ( V_2 , F_17 ( 1 ) | V_50 ) ;
F_6 ( V_2 , V_49 ) ;
F_6 ( V_2 , V_2 -> V_32 . V_33 + 256 ) ;
F_7 ( V_2 ) ;
V_2 -> V_48 = false ;
return 0 ;
}
static int
F_18 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 )
{
T_1 V_38 = 0 ;
T_1 V_31 = V_2 -> V_32 . V_33 + 128 ;
int V_19 ;
V_38 |= V_34 ;
if ( V_17 ) {
V_38 |= V_39 ;
V_38 |= V_40 ;
}
if ( V_16 ) {
V_38 |= V_41 ;
V_38 |= V_42 ;
V_38 |= V_43 ;
V_38 |= V_44 ;
V_38 |= V_45 ;
V_38 |= V_46 ;
V_38 |= V_37 ;
V_38 |= V_51 ;
F_14 ( V_2 ) ;
}
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 4 ) ) ;
F_6 ( V_2 , V_38 ) ;
F_6 ( V_2 , V_31 ) ;
F_6 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
if ( ! V_16 && V_17 )
return F_15 ( V_2 , V_52 ) ;
return 0 ;
}
static int
F_19 ( struct V_1 * V_2 ,
T_1 V_16 , T_1 V_17 )
{
T_1 V_38 = 0 ;
T_1 V_31 = V_2 -> V_32 . V_33 + 128 ;
int V_19 ;
V_38 |= V_34 ;
if ( V_17 ) {
V_38 |= V_39 ;
V_38 |= V_40 ;
}
if ( V_16 ) {
V_38 |= V_41 ;
V_38 |= V_42 ;
V_38 |= V_43 ;
V_38 |= V_44 ;
V_38 |= V_45 ;
V_38 |= V_46 ;
V_38 |= V_37 ;
V_38 |= V_51 ;
}
V_19 = F_5 ( V_2 , 6 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 6 ) ) ;
F_6 ( V_2 , V_38 ) ;
F_6 ( V_2 , V_31 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 ,
T_1 V_47 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
F_21 ( V_2 , V_47 ) ;
}
T_1 F_22 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_53 = F_23 ( V_2 -> V_11 ) -> V_54 >= 4 ?
F_24 ( V_2 -> V_55 ) : V_56 ;
return F_25 ( V_53 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_57 ;
V_57 = V_10 -> V_58 -> V_59 ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 4 )
V_57 |= ( V_10 -> V_58 -> V_59 >> 28 ) & 0xf0 ;
F_27 ( V_60 , V_57 ) ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
struct V_61 * V_62 = V_2 -> V_62 ;
int V_19 = 0 ;
T_1 V_4 ;
F_29 ( V_10 , V_63 ) ;
if ( F_30 ( V_11 ) )
F_31 ( V_2 ) ;
else
F_26 ( V_2 ) ;
F_32 ( V_2 , 0 ) ;
F_33 ( V_2 , 0 ) ;
V_2 -> V_15 ( V_2 , 0 ) ;
V_4 = F_34 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_35 ( L_1
L_2 ,
V_2 -> V_64 ,
F_36 ( V_2 ) ,
F_34 ( V_2 ) ,
F_37 ( V_2 ) ,
F_38 ( V_2 ) ) ;
F_33 ( V_2 , 0 ) ;
if ( F_34 ( V_2 ) & V_5 ) {
F_39 ( L_3
L_2 ,
V_2 -> V_64 ,
F_36 ( V_2 ) ,
F_34 ( V_2 ) ,
F_37 ( V_2 ) ,
F_38 ( V_2 ) ) ;
}
}
F_40 ( V_2 , F_41 ( V_62 ) ) ;
F_32 ( V_2 ,
( ( V_2 -> V_8 - V_65 ) & V_66 )
| V_67 ) ;
if ( F_42 ( ( F_36 ( V_2 ) & V_67 ) != 0 &&
F_38 ( V_2 ) == F_41 ( V_62 ) &&
( F_34 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_39 ( L_4
L_2 ,
V_2 -> V_64 ,
F_36 ( V_2 ) ,
F_34 ( V_2 ) ,
F_37 ( V_2 ) ,
F_38 ( V_2 ) ) ;
V_19 = - V_68 ;
goto V_69;
}
if ( ! F_43 ( V_2 -> V_11 , V_70 ) )
F_44 ( V_2 -> V_11 ) ;
else {
V_2 -> V_4 = F_34 ( V_2 ) ;
V_2 -> V_6 = F_37 ( V_2 ) & V_71 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_72 = - 1 ;
}
memset ( & V_2 -> V_73 , 0 , sizeof( V_2 -> V_73 ) ) ;
V_69:
F_45 ( V_10 , V_63 ) ;
return V_19 ;
}
static int
F_46 ( struct V_1 * V_2 )
{
int V_19 ;
if ( V_2 -> V_32 . V_62 )
return 0 ;
V_2 -> V_32 . V_62 = F_47 ( V_2 -> V_11 , 4096 ) ;
if ( V_2 -> V_32 . V_62 == NULL ) {
F_39 ( L_5 ) ;
V_19 = - V_74 ;
goto V_75;
}
F_48 ( V_2 -> V_32 . V_62 , V_76 ) ;
V_19 = F_49 ( V_2 -> V_32 . V_62 , 4096 , true , false ) ;
if ( V_19 )
goto V_77;
V_2 -> V_32 . V_33 = F_41 ( V_2 -> V_32 . V_62 ) ;
V_2 -> V_32 . V_78 = F_50 ( F_51 ( V_2 -> V_32 . V_62 -> V_79 -> V_80 ) ) ;
if ( V_2 -> V_32 . V_78 == NULL ) {
V_19 = - V_74 ;
goto V_81;
}
F_52 ( L_6 ,
V_2 -> V_64 , V_2 -> V_32 . V_33 ) ;
return 0 ;
V_81:
F_53 ( V_2 -> V_32 . V_62 ) ;
V_77:
F_54 ( & V_2 -> V_32 . V_62 -> V_82 ) ;
V_75:
return V_19 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
int V_19 = F_28 ( V_2 ) ;
if ( F_23 ( V_11 ) -> V_54 > 3 )
F_27 ( V_83 , F_56 ( V_84 ) ) ;
if ( F_23 ( V_11 ) -> V_54 >= 6 )
F_27 ( V_83 , F_56 ( V_85 ) ) ;
if ( F_23 ( V_11 ) -> V_54 == 6 )
F_27 ( V_86 ,
F_56 ( V_87 ) ) ;
if ( F_57 ( V_11 ) )
F_27 ( V_88 ,
F_58 ( V_87 ) |
F_56 ( V_89 ) ) ;
if ( F_23 ( V_11 ) -> V_54 >= 5 ) {
V_19 = F_46 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
if ( F_59 ( V_11 ) ) {
F_27 ( V_90 ,
F_58 ( V_91 ) ) ;
V_2 -> V_92 =
! ! ( F_25 ( V_86 ) & V_87 ) ;
}
if ( F_23 ( V_11 ) -> V_54 >= 6 )
F_27 ( V_93 , F_56 ( V_94 ) ) ;
if ( F_60 ( V_11 ) )
F_61 ( V_2 , ~ F_62 ( V_11 ) ) ;
return V_19 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
if ( V_2 -> V_32 . V_62 == NULL )
return;
if ( F_23 ( V_11 ) -> V_54 >= 5 ) {
F_64 ( F_51 ( V_2 -> V_32 . V_62 -> V_79 -> V_80 ) ) ;
F_53 ( V_2 -> V_32 . V_62 ) ;
}
F_54 ( & V_2 -> V_32 . V_62 -> V_82 ) ;
V_2 -> V_32 . V_62 = NULL ;
}
static void
F_65 ( struct V_1 * V_2 ,
T_1 V_95 )
{
#define F_66 4
F_6 ( V_2 , F_16 ( 1 ) ) ;
F_6 ( V_2 , V_95 ) ;
F_6 ( V_2 , V_2 -> V_96 ) ;
F_6 ( V_2 , V_25 ) ;
}
static int
F_67 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_97 ;
int V_98 , V_19 , V_99 = 4 ;
if ( F_68 ( V_11 ) )
V_99 += ( ( V_100 - 1 ) * F_66 ) ;
#undef F_66
V_19 = F_5 ( V_2 , V_99 ) ;
if ( V_19 )
return V_19 ;
if ( F_68 ( V_11 ) ) {
F_69 (useless, dev_priv, i) {
T_1 V_101 = V_2 -> V_102 [ V_98 ] ;
if ( V_101 != V_103 )
F_65 ( V_2 , V_101 ) ;
}
}
F_6 ( V_2 , V_104 ) ;
F_6 ( V_2 , V_105 << V_106 ) ;
F_6 ( V_2 , V_2 -> V_96 ) ;
F_6 ( V_2 , V_107 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static inline bool F_70 ( struct V_26 * V_11 ,
T_1 V_108 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
return V_10 -> V_109 < V_108 ;
}
static int
F_71 ( struct V_1 * V_110 ,
struct V_1 * V_111 ,
T_1 V_108 )
{
int V_19 ;
T_1 V_112 = V_113 |
V_114 |
V_115 ;
V_108 -= 1 ;
F_72 ( V_111 -> V_116 [ V_110 -> V_117 ] ==
V_118 ) ;
V_19 = F_5 ( V_110 , 4 ) ;
if ( V_19 )
return V_19 ;
if ( F_73 ( ! F_70 ( V_110 -> V_11 , V_108 ) ) ) {
F_6 ( V_110 ,
V_112 |
V_111 -> V_116 [ V_110 -> V_117 ] ) ;
F_6 ( V_110 , V_108 ) ;
F_6 ( V_110 , 0 ) ;
F_6 ( V_110 , V_25 ) ;
} else {
F_6 ( V_110 , V_25 ) ;
F_6 ( V_110 , V_25 ) ;
F_6 ( V_110 , V_25 ) ;
F_6 ( V_110 , V_25 ) ;
}
F_7 ( V_110 ) ;
return 0 ;
}
static int
F_74 ( struct V_1 * V_2 )
{
T_1 V_31 = V_2 -> V_32 . V_33 + 128 ;
int V_19 ;
V_19 = F_5 ( V_2 , 32 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 4 ) | V_37 |
V_119 |
V_43 ) ;
F_6 ( V_2 , V_2 -> V_32 . V_33 | V_36 ) ;
F_6 ( V_2 , V_2 -> V_96 ) ;
F_6 ( V_2 , 0 ) ;
F_75 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_75 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_75 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_75 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_75 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_75 ( V_2 , V_31 ) ;
F_6 ( V_2 , F_12 ( 4 ) | V_37 |
V_119 |
V_43 |
V_120 ) ;
F_6 ( V_2 , V_2 -> V_32 . V_33 | V_36 ) ;
F_6 ( V_2 , V_2 -> V_96 ) ;
F_6 ( V_2 , 0 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static T_1
F_76 ( struct V_1 * V_2 , bool V_121 )
{
if ( ! V_121 )
F_22 ( V_2 ) ;
return F_77 ( V_2 , V_105 ) ;
}
static T_1
F_78 ( struct V_1 * V_2 , bool V_121 )
{
return F_77 ( V_2 , V_105 ) ;
}
static void
F_79 ( struct V_1 * V_2 , T_1 V_108 )
{
F_80 ( V_2 , V_105 , V_108 ) ;
}
static T_1
F_81 ( struct V_1 * V_2 , bool V_121 )
{
return V_2 -> V_32 . V_78 [ 0 ] ;
}
static void
F_82 ( struct V_1 * V_2 , T_1 V_108 )
{
V_2 -> V_32 . V_78 [ 0 ] = V_108 ;
}
static bool
F_83 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_122 )
return false ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( V_2 -> V_124 ++ == 0 )
F_85 ( V_10 , V_2 -> V_125 ) ;
F_86 ( & V_10 -> V_123 , V_38 ) ;
return true ;
}
static void
F_87 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( -- V_2 -> V_124 == 0 )
F_88 ( V_10 , V_2 -> V_125 ) ;
F_86 ( & V_10 -> V_123 , V_38 ) ;
}
static bool
F_89 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_122 )
return false ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( V_2 -> V_124 ++ == 0 ) {
V_10 -> V_126 &= ~ V_2 -> V_125 ;
F_27 ( V_127 , V_10 -> V_126 ) ;
F_90 ( V_127 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
return true ;
}
static void
F_91 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( -- V_2 -> V_124 == 0 ) {
V_10 -> V_126 |= V_2 -> V_125 ;
F_27 ( V_127 , V_10 -> V_126 ) ;
F_90 ( V_127 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
}
static bool
F_92 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_122 )
return false ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( V_2 -> V_124 ++ == 0 ) {
V_10 -> V_126 &= ~ V_2 -> V_125 ;
F_93 ( V_127 , V_10 -> V_126 ) ;
F_94 ( V_127 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
return true ;
}
static void
F_95 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( -- V_2 -> V_124 == 0 ) {
V_10 -> V_126 |= V_2 -> V_125 ;
F_93 ( V_127 , V_10 -> V_126 ) ;
F_94 ( V_127 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_128 = 0 ;
if ( F_57 ( V_11 ) ) {
switch ( V_2 -> V_117 ) {
case V_129 :
V_128 = V_130 ;
break;
case V_131 :
V_128 = V_132 ;
break;
case V_133 :
V_128 = V_134 ;
break;
case V_135 :
V_128 = V_136 ;
break;
}
} else if ( F_59 ( V_2 -> V_11 ) ) {
V_128 = F_96 ( V_2 -> V_55 ) ;
} else {
V_128 = F_97 ( V_2 -> V_55 ) ;
}
F_27 ( V_128 , ( T_1 ) V_2 -> V_137 . V_138 ) ;
F_90 ( V_128 ) ;
if ( F_23 ( V_11 ) -> V_54 >= 6 ) {
T_1 V_139 = F_98 ( V_2 -> V_55 ) ;
F_27 ( V_139 ,
F_56 ( V_140 |
V_141 ) ) ;
if ( F_42 ( ( F_25 ( V_139 ) & V_141 ) == 0 ,
1000 ) )
F_39 ( L_7 ,
V_2 -> V_64 ) ;
}
}
static int
F_99 ( struct V_1 * V_2 ,
T_1 V_16 ,
T_1 V_17 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_20 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_100 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_104 ) ;
F_6 ( V_2 , V_105 << V_106 ) ;
F_6 ( V_2 , V_2 -> V_96 ) ;
F_6 ( V_2 , V_107 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static bool
F_101 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_122 )
return false ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( V_2 -> V_124 ++ == 0 ) {
if ( F_60 ( V_11 ) && V_2 -> V_117 == V_129 )
F_61 ( V_2 ,
~ ( V_2 -> V_125 |
F_62 ( V_11 ) ) ) ;
else
F_61 ( V_2 , ~ V_2 -> V_125 ) ;
F_85 ( V_10 , V_2 -> V_125 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
return true ;
}
static void
F_102 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( -- V_2 -> V_124 == 0 ) {
if ( F_60 ( V_11 ) && V_2 -> V_117 == V_129 )
F_61 ( V_2 , ~ F_62 ( V_11 ) ) ;
else
F_61 ( V_2 , ~ 0 ) ;
F_88 ( V_10 , V_2 -> V_125 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
}
static bool
F_103 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_122 )
return false ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( V_2 -> V_124 ++ == 0 ) {
F_61 ( V_2 , ~ V_2 -> V_125 ) ;
F_104 ( V_10 , V_2 -> V_125 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
return true ;
}
static void
F_105 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_122 )
return;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( -- V_2 -> V_124 == 0 ) {
F_61 ( V_2 , ~ 0 ) ;
F_106 ( V_10 , V_2 -> V_125 ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
}
static bool
F_107 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_122 )
return false ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( V_2 -> V_124 ++ == 0 ) {
if ( F_60 ( V_11 ) && V_2 -> V_117 == V_129 ) {
F_61 ( V_2 ,
~ ( V_2 -> V_125 |
V_142 ) ) ;
} else {
F_61 ( V_2 , ~ V_2 -> V_125 ) ;
}
F_90 ( F_108 ( V_2 -> V_55 ) ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
return true ;
}
static void
F_109 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_84 ( & V_10 -> V_123 , V_38 ) ;
if ( -- V_2 -> V_124 == 0 ) {
if ( F_60 ( V_11 ) && V_2 -> V_117 == V_129 ) {
F_61 ( V_2 ,
~ V_142 ) ;
} else {
F_61 ( V_2 , ~ 0 ) ;
}
F_90 ( F_108 ( V_2 -> V_55 ) ) ;
}
F_86 ( & V_10 -> V_123 , V_38 ) ;
}
static int
F_110 ( struct V_1 * V_2 ,
T_1 V_143 , T_1 V_144 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_145 |
V_146 |
( V_38 & V_147 ? 0 : V_148 ) ) ;
F_6 ( V_2 , V_143 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_111 ( struct V_1 * V_2 ,
T_1 V_143 , T_1 V_149 ,
unsigned V_38 )
{
int V_19 ;
if ( V_38 & V_150 ) {
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_151 ) ;
F_6 ( V_2 , V_143 | ( V_38 & V_147 ? 0 : V_152 ) ) ;
F_6 ( V_2 , V_143 + V_149 - 8 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
} else {
T_1 V_153 = V_2 -> V_32 . V_33 ;
if ( V_149 > V_154 )
return - V_155 ;
V_19 = F_5 ( V_2 , 9 + 3 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_156 |
V_157 |
V_158 ) ;
F_6 ( V_2 , V_159 | V_160 | 4096 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , ( F_112 ( V_149 , 4096 ) << 16 ) | 1024 ) ;
F_6 ( V_2 , V_153 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 4096 ) ;
F_6 ( V_2 , V_143 ) ;
F_6 ( V_2 , V_20 ) ;
F_6 ( V_2 , V_151 ) ;
F_6 ( V_2 , V_153 | ( V_38 & V_147 ? 0 : V_152 ) ) ;
F_6 ( V_2 , V_153 + V_149 - 8 ) ;
F_7 ( V_2 ) ;
}
return 0 ;
}
static int
F_113 ( struct V_1 * V_2 ,
T_1 V_143 , T_1 V_149 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_145 | V_146 ) ;
F_6 ( V_2 , V_143 | ( V_38 & V_147 ? 0 : V_152 ) ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_2 )
{
struct V_61 * V_62 ;
V_62 = V_2 -> V_137 . V_62 ;
if ( V_62 == NULL )
return;
F_64 ( F_51 ( V_62 -> V_79 -> V_80 ) ) ;
F_53 ( V_62 ) ;
F_54 ( & V_62 -> V_82 ) ;
V_2 -> V_137 . V_62 = NULL ;
}
static int F_115 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_61 * V_62 ;
int V_19 ;
V_62 = F_47 ( V_11 , 4096 ) ;
if ( V_62 == NULL ) {
F_39 ( L_8 ) ;
V_19 = - V_74 ;
goto V_75;
}
F_48 ( V_62 , V_76 ) ;
V_19 = F_49 ( V_62 , 4096 , true , false ) ;
if ( V_19 != 0 ) {
goto V_77;
}
V_2 -> V_137 . V_138 = F_41 ( V_62 ) ;
V_2 -> V_137 . V_161 = F_50 ( F_51 ( V_62 -> V_79 -> V_80 ) ) ;
if ( V_2 -> V_137 . V_161 == NULL ) {
V_19 = - V_74 ;
goto V_81;
}
V_2 -> V_137 . V_62 = V_62 ;
memset ( V_2 -> V_137 . V_161 , 0 , V_65 ) ;
F_52 ( L_9 ,
V_2 -> V_64 , V_2 -> V_137 . V_138 ) ;
return 0 ;
V_81:
F_53 ( V_62 ) ;
V_77:
F_54 ( & V_62 -> V_82 ) ;
V_75:
return V_19 ;
}
static int F_116 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
if ( ! V_10 -> V_58 ) {
V_10 -> V_58 =
F_117 ( V_2 -> V_11 , V_65 , V_65 ) ;
if ( ! V_10 -> V_58 )
return - V_74 ;
}
V_2 -> V_137 . V_161 = V_10 -> V_58 -> V_162 ;
memset ( V_2 -> V_137 . V_161 , 0 , V_65 ) ;
return 0 ;
}
static int F_118 ( struct V_26 * V_11 ,
struct V_1 * V_2 )
{
struct V_61 * V_62 ;
struct V_9 * V_10 = V_11 -> V_12 ;
int V_19 ;
V_2 -> V_11 = V_11 ;
F_119 ( & V_2 -> V_163 ) ;
F_119 ( & V_2 -> V_164 ) ;
V_2 -> V_8 = 32 * V_65 ;
memset ( V_2 -> V_165 , 0 , sizeof( V_2 -> V_165 ) ) ;
F_120 ( & V_2 -> V_166 ) ;
if ( F_30 ( V_11 ) ) {
V_19 = F_115 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else {
F_121 ( V_2 -> V_117 != V_129 ) ;
V_19 = F_116 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
V_62 = NULL ;
if ( ! F_122 ( V_11 ) )
V_62 = F_123 ( V_11 , V_2 -> V_8 ) ;
if ( V_62 == NULL )
V_62 = F_47 ( V_11 , V_2 -> V_8 ) ;
if ( V_62 == NULL ) {
F_39 ( L_10 ) ;
V_19 = - V_74 ;
goto V_167;
}
V_2 -> V_62 = V_62 ;
V_19 = F_49 ( V_62 , V_65 , true , false ) ;
if ( V_19 )
goto V_77;
V_19 = F_124 ( V_62 , true ) ;
if ( V_19 )
goto V_81;
V_2 -> V_168 =
F_125 ( V_10 -> V_169 . V_170 + F_41 ( V_62 ) ,
V_2 -> V_8 ) ;
if ( V_2 -> V_168 == NULL ) {
F_39 ( L_11 ) ;
V_19 = - V_171 ;
goto V_81;
}
V_19 = V_2 -> V_172 ( V_2 ) ;
if ( V_19 )
goto V_173;
V_2 -> V_174 = V_2 -> V_8 ;
if ( F_126 ( V_2 -> V_11 ) || F_127 ( V_2 -> V_11 ) )
V_2 -> V_174 -= 128 ;
return 0 ;
V_173:
F_128 ( V_2 -> V_168 ) ;
V_81:
F_53 ( V_62 ) ;
V_77:
F_54 ( & V_62 -> V_82 ) ;
V_2 -> V_62 = NULL ;
V_167:
F_114 ( V_2 ) ;
return V_19 ;
}
void F_129 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_19 ;
if ( V_2 -> V_62 == NULL )
return;
V_10 = V_2 -> V_11 -> V_12 ;
V_19 = F_130 ( V_2 ) ;
if ( V_19 && ! F_131 ( & V_10 -> V_13 ) )
F_39 ( L_12 ,
V_2 -> V_64 , V_19 ) ;
F_32 ( V_2 , 0 ) ;
F_128 ( V_2 -> V_168 ) ;
F_53 ( V_2 -> V_62 ) ;
F_54 ( & V_2 -> V_62 -> V_82 ) ;
V_2 -> V_62 = NULL ;
V_2 -> V_175 = NULL ;
V_2 -> V_96 = 0 ;
if ( V_2 -> V_176 )
V_2 -> V_176 ( V_2 ) ;
F_114 ( V_2 ) ;
}
static int F_132 ( struct V_1 * V_2 , T_1 V_108 )
{
int V_19 ;
V_19 = F_133 ( V_2 , V_108 ) ;
if ( ! V_19 )
F_134 ( V_2 ) ;
return V_19 ;
}
static int F_135 ( struct V_1 * V_2 , int V_177 )
{
struct V_178 * V_179 ;
T_1 V_108 = 0 ;
int V_19 ;
F_134 ( V_2 ) ;
if ( V_2 -> V_72 != - 1 ) {
V_2 -> V_4 = V_2 -> V_72 ;
V_2 -> V_72 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_177 )
return 0 ;
}
F_136 (request, &ring->request_list, list) {
int V_3 ;
if ( V_179 -> V_6 == - 1 )
continue;
V_3 = V_179 -> V_6 - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
if ( V_3 >= V_177 ) {
V_108 = V_179 -> V_108 ;
break;
}
V_179 -> V_6 = - 1 ;
}
if ( V_108 == 0 )
return - V_155 ;
V_19 = F_132 ( V_2 , V_108 ) ;
if ( V_19 )
return V_19 ;
if ( F_72 ( V_2 -> V_72 == - 1 ) )
return - V_155 ;
V_2 -> V_4 = V_2 -> V_72 ;
V_2 -> V_72 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_72 ( V_2 -> V_3 < V_177 ) )
return - V_155 ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , int V_177 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_180 ;
int V_19 ;
V_19 = F_135 ( V_2 , V_177 ) ;
if ( V_19 != - V_155 )
return V_19 ;
F_2 ( V_2 ) ;
F_138 ( V_2 ) ;
V_180 = V_181 + 60 * V_182 ;
do {
V_2 -> V_4 = F_34 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_177 ) {
F_139 ( V_2 ) ;
return 0 ;
}
if ( V_11 -> V_183 -> V_184 ) {
struct V_185 * V_186 = V_11 -> V_183 -> V_184 -> V_187 ;
if ( V_186 -> V_188 )
V_186 -> V_188 -> V_189 |= V_190 ;
}
F_140 ( 1 ) ;
V_19 = F_141 ( & V_10 -> V_13 ,
V_10 -> V_191 . V_192 ) ;
if ( V_19 )
return V_19 ;
} while ( ! F_142 ( V_181 , V_180 ) );
F_139 ( V_2 ) ;
return - V_193 ;
}
static int F_143 ( struct V_1 * V_2 )
{
T_3 T_4 * V_194 ;
int V_195 = V_2 -> V_8 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_195 ) {
int V_19 = F_137 ( V_2 , V_195 ) ;
if ( V_19 )
return V_19 ;
}
V_194 = V_2 -> V_168 + V_2 -> V_6 ;
V_195 /= 4 ;
while ( V_195 -- )
F_144 ( V_25 , V_194 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_130 ( struct V_1 * V_2 )
{
T_1 V_108 ;
int V_19 ;
if ( V_2 -> V_96 ) {
V_19 = F_145 ( V_2 , NULL ) ;
if ( V_19 )
return V_19 ;
}
if ( F_146 ( & V_2 -> V_164 ) )
return 0 ;
V_108 = F_147 ( V_2 -> V_164 . V_196 ,
struct V_178 ,
V_197 ) -> V_108 ;
return F_133 ( V_2 , V_108 ) ;
}
static int
F_148 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 )
return 0 ;
if ( V_2 -> V_175 == NULL ) {
struct V_178 * V_179 ;
V_179 = F_149 ( sizeof( * V_179 ) , V_198 ) ;
if ( V_179 == NULL )
return - V_74 ;
V_2 -> V_175 = V_179 ;
}
return F_150 ( V_2 -> V_11 , & V_2 -> V_96 ) ;
}
static int F_151 ( struct V_1 * V_2 ,
int V_199 )
{
int V_19 ;
if ( F_152 ( V_2 -> V_6 + V_199 > V_2 -> V_174 ) ) {
V_19 = F_143 ( V_2 ) ;
if ( F_152 ( V_19 ) )
return V_19 ;
}
if ( F_152 ( V_2 -> V_3 < V_199 ) ) {
V_19 = F_137 ( V_2 , V_199 ) ;
if ( F_152 ( V_19 ) )
return V_19 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
int V_99 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
int V_19 ;
V_19 = F_141 ( & V_10 -> V_13 ,
V_10 -> V_191 . V_192 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_151 ( V_2 , V_99 * sizeof( T_3 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_148 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_3 -= V_99 * sizeof( T_3 ) ;
return 0 ;
}
int F_153 ( struct V_1 * V_2 )
{
int V_99 = ( 64 - ( V_2 -> V_6 & 63 ) ) / sizeof( T_3 ) ;
int V_19 ;
if ( V_99 == 0 )
return 0 ;
V_19 = F_5 ( V_2 , V_99 ) ;
if ( V_19 )
return V_19 ;
while ( V_99 -- )
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
void F_154 ( struct V_1 * V_2 , T_1 V_108 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
F_121 ( V_2 -> V_96 ) ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 6 ) {
F_27 ( F_155 ( V_2 -> V_55 ) , 0 ) ;
F_27 ( F_156 ( V_2 -> V_55 ) , 0 ) ;
if ( F_157 ( V_2 -> V_11 ) )
F_27 ( F_158 ( V_2 -> V_55 ) , 0 ) ;
}
V_2 -> V_200 ( V_2 , V_108 ) ;
V_2 -> V_73 . V_108 = V_108 ;
}
static void F_159 ( struct V_1 * V_2 ,
T_1 V_47 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
F_27 ( V_201 ,
F_56 ( V_202 ) ) ;
F_160 ( V_203 , 0x0 ) ;
if ( F_42 ( ( F_25 ( V_201 ) &
V_204 ) == 0 ,
50 ) )
F_39 ( L_13 ) ;
F_21 ( V_2 , V_47 ) ;
F_90 ( F_161 ( V_2 -> V_55 ) ) ;
F_27 ( V_201 ,
F_58 ( V_202 ) ) ;
}
static int F_162 ( struct V_1 * V_2 ,
T_1 V_205 , T_1 V_206 )
{
T_3 V_18 ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
V_18 = V_207 ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 )
V_18 += 1 ;
if ( V_205 & V_208 )
V_18 |= V_209 | V_210 |
V_211 | V_212 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_213 | V_214 ) ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 ) {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
} else {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
}
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_163 ( struct V_1 * V_2 ,
T_1 V_143 , T_1 V_149 ,
unsigned V_38 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
bool V_215 = V_10 -> V_191 . V_216 != NULL &&
! ( V_38 & V_147 ) ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_217 | ( V_215 << 8 ) ) ;
F_6 ( V_2 , V_143 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_164 ( struct V_1 * V_2 ,
T_1 V_143 , T_1 V_149 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_145 | V_218 |
( V_38 & V_147 ? 0 : V_219 ) ) ;
F_6 ( V_2 , V_143 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_165 ( struct V_1 * V_2 ,
T_1 V_143 , T_1 V_149 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_145 |
( V_38 & V_147 ? 0 : V_148 ) ) ;
F_6 ( V_2 , V_143 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_166 ( struct V_1 * V_2 ,
T_1 V_205 , T_1 V_206 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_3 V_18 ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
V_18 = V_207 ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 )
V_18 += 1 ;
if ( V_205 & V_21 )
V_18 |= V_209 | V_211 |
V_212 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_213 | V_214 ) ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 ) {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
} else {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
}
F_7 ( V_2 ) ;
if ( F_57 ( V_11 ) && ! V_205 && V_206 )
return F_15 ( V_2 , V_220 ) ;
return 0 ;
}
int F_167 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_129 ] ;
V_2 -> V_64 = L_14 ;
V_2 -> V_117 = V_129 ;
V_2 -> V_55 = V_221 ;
if ( F_23 ( V_11 ) -> V_54 >= 6 ) {
V_2 -> V_222 = F_67 ;
V_2 -> V_206 = F_18 ;
if ( F_23 ( V_11 ) -> V_54 == 6 )
V_2 -> V_206 = F_13 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_206 = F_19 ;
V_2 -> V_223 = F_107 ;
V_2 -> V_224 = F_109 ;
} else {
V_2 -> V_223 = F_101 ;
V_2 -> V_224 = F_102 ;
}
V_2 -> V_125 = V_225 ;
V_2 -> V_226 = F_76 ;
V_2 -> V_200 = F_79 ;
V_2 -> V_227 = F_71 ;
V_2 -> V_116 [ V_129 ] = V_118 ;
V_2 -> V_116 [ V_133 ] = V_228 ;
V_2 -> V_116 [ V_131 ] = V_229 ;
V_2 -> V_116 [ V_135 ] = V_230 ;
V_2 -> V_102 [ V_129 ] = V_103 ;
V_2 -> V_102 [ V_133 ] = V_231 ;
V_2 -> V_102 [ V_131 ] = V_232 ;
V_2 -> V_102 [ V_135 ] = V_233 ;
} else if ( F_10 ( V_11 ) ) {
V_2 -> V_222 = F_74 ;
V_2 -> V_206 = F_8 ;
V_2 -> V_226 = F_81 ;
V_2 -> V_200 = F_82 ;
V_2 -> V_223 = F_83 ;
V_2 -> V_224 = F_87 ;
V_2 -> V_125 = V_225 |
V_234 ;
} else {
V_2 -> V_222 = F_100 ;
if ( F_23 ( V_11 ) -> V_54 < 4 )
V_2 -> V_206 = F_4 ;
else
V_2 -> V_206 = F_8 ;
V_2 -> V_226 = F_78 ;
V_2 -> V_200 = F_79 ;
if ( F_168 ( V_11 ) ) {
V_2 -> V_223 = F_92 ;
V_2 -> V_224 = F_95 ;
} else {
V_2 -> V_223 = F_89 ;
V_2 -> V_224 = F_91 ;
}
V_2 -> V_125 = V_235 ;
}
V_2 -> V_15 = F_20 ;
if ( F_169 ( V_11 ) )
V_2 -> V_236 = F_164 ;
else if ( F_170 ( V_11 ) )
V_2 -> V_236 = F_163 ;
else if ( F_23 ( V_11 ) -> V_54 >= 6 )
V_2 -> V_236 = F_165 ;
else if ( F_23 ( V_11 ) -> V_54 >= 4 )
V_2 -> V_236 = F_110 ;
else if ( F_126 ( V_11 ) || F_127 ( V_11 ) )
V_2 -> V_236 = F_111 ;
else
V_2 -> V_236 = F_113 ;
V_2 -> V_172 = F_55 ;
V_2 -> V_176 = F_63 ;
if ( F_171 ( V_11 ) ) {
struct V_61 * V_62 ;
int V_19 ;
V_62 = F_47 ( V_11 , V_154 ) ;
if ( V_62 == NULL ) {
F_39 ( L_15 ) ;
return - V_74 ;
}
V_19 = F_49 ( V_62 , 0 , true , false ) ;
if ( V_19 != 0 ) {
F_54 ( & V_62 -> V_82 ) ;
F_39 ( L_16 ) ;
return V_19 ;
}
V_2 -> V_32 . V_62 = V_62 ;
V_2 -> V_32 . V_33 = F_41 ( V_62 ) ;
}
return F_118 ( V_11 , V_2 ) ;
}
int F_172 ( struct V_26 * V_11 , T_5 V_237 , T_1 V_8 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_129 ] ;
int V_19 ;
V_2 -> V_64 = L_14 ;
V_2 -> V_117 = V_129 ;
V_2 -> V_55 = V_221 ;
if ( F_23 ( V_11 ) -> V_54 >= 6 ) {
return - V_238 ;
}
V_2 -> V_222 = F_100 ;
if ( F_23 ( V_11 ) -> V_54 < 4 )
V_2 -> V_206 = F_4 ;
else
V_2 -> V_206 = F_8 ;
V_2 -> V_226 = F_78 ;
V_2 -> V_200 = F_79 ;
if ( F_168 ( V_11 ) ) {
V_2 -> V_223 = F_92 ;
V_2 -> V_224 = F_95 ;
} else {
V_2 -> V_223 = F_89 ;
V_2 -> V_224 = F_91 ;
}
V_2 -> V_125 = V_235 ;
V_2 -> V_15 = F_20 ;
if ( F_23 ( V_11 ) -> V_54 >= 4 )
V_2 -> V_236 = F_110 ;
else if ( F_126 ( V_11 ) || F_127 ( V_11 ) )
V_2 -> V_236 = F_111 ;
else
V_2 -> V_236 = F_113 ;
V_2 -> V_172 = F_55 ;
V_2 -> V_176 = F_63 ;
V_2 -> V_11 = V_11 ;
F_119 ( & V_2 -> V_163 ) ;
F_119 ( & V_2 -> V_164 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_174 = V_2 -> V_8 ;
if ( F_126 ( V_2 -> V_11 ) || F_127 ( V_2 -> V_11 ) )
V_2 -> V_174 -= 128 ;
V_2 -> V_168 = F_125 ( V_237 , V_8 ) ;
if ( V_2 -> V_168 == NULL ) {
F_39 ( L_17
L_18 ) ;
return - V_74 ;
}
if ( ! F_30 ( V_11 ) ) {
V_19 = F_116 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
int F_173 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_133 ] ;
V_2 -> V_64 = L_19 ;
V_2 -> V_117 = V_133 ;
V_2 -> V_15 = F_20 ;
if ( F_23 ( V_11 ) -> V_54 >= 6 ) {
V_2 -> V_55 = V_239 ;
if ( F_59 ( V_11 ) )
V_2 -> V_15 = F_159 ;
V_2 -> V_206 = F_162 ;
V_2 -> V_222 = F_67 ;
V_2 -> V_226 = F_76 ;
V_2 -> V_200 = F_79 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_125 =
V_225 << V_240 ;
V_2 -> V_223 = F_107 ;
V_2 -> V_224 = F_109 ;
V_2 -> V_236 =
F_163 ;
} else {
V_2 -> V_125 = V_241 ;
V_2 -> V_223 = F_101 ;
V_2 -> V_224 = F_102 ;
V_2 -> V_236 =
F_165 ;
}
V_2 -> V_227 = F_71 ;
V_2 -> V_116 [ V_129 ] = V_242 ;
V_2 -> V_116 [ V_133 ] = V_118 ;
V_2 -> V_116 [ V_131 ] = V_243 ;
V_2 -> V_116 [ V_135 ] = V_244 ;
V_2 -> V_102 [ V_129 ] = V_245 ;
V_2 -> V_102 [ V_133 ] = V_103 ;
V_2 -> V_102 [ V_131 ] = V_246 ;
V_2 -> V_102 [ V_135 ] = V_247 ;
} else {
V_2 -> V_55 = V_248 ;
V_2 -> V_206 = F_99 ;
V_2 -> V_222 = F_100 ;
V_2 -> V_226 = F_78 ;
V_2 -> V_200 = F_79 ;
if ( F_10 ( V_11 ) ) {
V_2 -> V_125 = V_249 ;
V_2 -> V_223 = F_83 ;
V_2 -> V_224 = F_87 ;
} else {
V_2 -> V_125 = V_250 ;
V_2 -> V_223 = F_89 ;
V_2 -> V_224 = F_91 ;
}
V_2 -> V_236 = F_110 ;
}
V_2 -> V_172 = F_28 ;
return F_118 ( V_11 , V_2 ) ;
}
int F_174 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_131 ] ;
V_2 -> V_64 = L_20 ;
V_2 -> V_117 = V_131 ;
V_2 -> V_55 = V_251 ;
V_2 -> V_15 = F_20 ;
V_2 -> V_206 = F_166 ;
V_2 -> V_222 = F_67 ;
V_2 -> V_226 = F_76 ;
V_2 -> V_200 = F_79 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_125 =
V_225 << V_252 ;
V_2 -> V_223 = F_107 ;
V_2 -> V_224 = F_109 ;
V_2 -> V_236 = F_163 ;
} else {
V_2 -> V_125 = V_253 ;
V_2 -> V_223 = F_101 ;
V_2 -> V_224 = F_102 ;
V_2 -> V_236 = F_165 ;
}
V_2 -> V_227 = F_71 ;
V_2 -> V_116 [ V_129 ] = V_254 ;
V_2 -> V_116 [ V_133 ] = V_255 ;
V_2 -> V_116 [ V_131 ] = V_118 ;
V_2 -> V_116 [ V_135 ] = V_256 ;
V_2 -> V_102 [ V_129 ] = V_257 ;
V_2 -> V_102 [ V_133 ] = V_258 ;
V_2 -> V_102 [ V_131 ] = V_103 ;
V_2 -> V_102 [ V_135 ] = V_259 ;
V_2 -> V_172 = F_28 ;
return F_118 ( V_11 , V_2 ) ;
}
int F_175 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_135 ] ;
V_2 -> V_64 = L_21 ;
V_2 -> V_117 = V_135 ;
V_2 -> V_55 = V_260 ;
V_2 -> V_15 = F_20 ;
V_2 -> V_206 = F_166 ;
V_2 -> V_222 = F_67 ;
V_2 -> V_226 = F_76 ;
V_2 -> V_200 = F_79 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_125 =
V_225 << V_261 ;
V_2 -> V_223 = F_107 ;
V_2 -> V_224 = F_109 ;
V_2 -> V_236 = F_163 ;
} else {
V_2 -> V_125 = V_262 ;
V_2 -> V_223 = F_103 ;
V_2 -> V_224 = F_105 ;
V_2 -> V_236 = F_165 ;
}
V_2 -> V_227 = F_71 ;
V_2 -> V_116 [ V_129 ] = V_263 ;
V_2 -> V_116 [ V_133 ] = V_264 ;
V_2 -> V_116 [ V_131 ] = V_265 ;
V_2 -> V_116 [ V_135 ] = V_118 ;
V_2 -> V_102 [ V_129 ] = V_266 ;
V_2 -> V_102 [ V_133 ] = V_267 ;
V_2 -> V_102 [ V_131 ] = V_268 ;
V_2 -> V_102 [ V_135 ] = V_103 ;
V_2 -> V_172 = F_28 ;
return F_118 ( V_11 , V_2 ) ;
}
int
F_176 ( struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_2 -> V_269 )
return 0 ;
V_19 = V_2 -> V_206 ( V_2 , 0 , V_208 ) ;
if ( V_19 )
return V_19 ;
F_177 ( V_2 , 0 , V_208 ) ;
V_2 -> V_269 = false ;
return 0 ;
}
int
F_178 ( struct V_1 * V_2 )
{
T_3 V_17 ;
int V_19 ;
V_17 = 0 ;
if ( V_2 -> V_269 )
V_17 = V_208 ;
V_19 = V_2 -> V_206 ( V_2 , V_208 , V_17 ) ;
if ( V_19 )
return V_19 ;
F_177 ( V_2 , V_208 , V_17 ) ;
V_2 -> V_269 = false ;
return 0 ;
}
