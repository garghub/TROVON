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
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
F_21 ( V_2 , V_47 ) ;
}
T_2 F_22 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
T_2 V_53 ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 )
V_53 = F_24 ( F_25 ( V_2 -> V_55 ) ,
F_26 ( V_2 -> V_55 ) ) ;
else if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 4 )
V_53 = F_27 ( F_25 ( V_2 -> V_55 ) ) ;
else
V_53 = F_27 ( V_56 ) ;
return V_53 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_57 ;
V_57 = V_10 -> V_58 -> V_59 ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 4 )
V_57 |= ( V_10 -> V_58 -> V_59 >> 28 ) & 0xf0 ;
F_29 ( V_60 , V_57 ) ;
}
static bool F_30 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_31 ( V_2 -> V_11 ) ;
if ( ! F_32 ( V_2 -> V_11 ) ) {
F_33 ( V_2 , F_34 ( V_61 ) ) ;
if ( F_35 ( ( F_36 ( V_2 ) & V_62 ) != 0 , 1000 ) ) {
F_37 ( L_1 , V_2 -> V_63 ) ;
return false ;
}
}
F_38 ( V_2 , 0 ) ;
F_39 ( V_2 , 0 ) ;
V_2 -> V_15 ( V_2 , 0 ) ;
if ( ! F_32 ( V_2 -> V_11 ) ) {
( void ) F_40 ( V_2 ) ;
F_33 ( V_2 , F_41 ( V_61 ) ) ;
}
return ( F_42 ( V_2 ) & V_5 ) == 0 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_64 * V_65 = V_2 -> V_65 ;
int V_19 = 0 ;
F_44 ( V_10 , V_66 ) ;
if ( ! F_30 ( V_2 ) ) {
F_45 ( L_2
L_3 ,
V_2 -> V_63 ,
F_40 ( V_2 ) ,
F_42 ( V_2 ) ,
F_46 ( V_2 ) ,
F_47 ( V_2 ) ) ;
if ( ! F_30 ( V_2 ) ) {
F_37 ( L_4
L_3 ,
V_2 -> V_63 ,
F_40 ( V_2 ) ,
F_42 ( V_2 ) ,
F_46 ( V_2 ) ,
F_47 ( V_2 ) ) ;
V_19 = - V_67 ;
goto V_68;
}
}
if ( F_48 ( V_11 ) )
F_49 ( V_2 ) ;
else
F_28 ( V_2 ) ;
F_50 ( V_2 , F_51 ( V_65 ) ) ;
F_38 ( V_2 ,
( ( V_2 -> V_8 - V_69 ) & V_70 )
| V_71 ) ;
if ( F_52 ( ( F_40 ( V_2 ) & V_71 ) != 0 &&
F_47 ( V_2 ) == F_51 ( V_65 ) &&
( F_42 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_37 ( L_5
L_3 ,
V_2 -> V_63 ,
F_40 ( V_2 ) ,
F_42 ( V_2 ) ,
F_46 ( V_2 ) ,
F_47 ( V_2 ) ) ;
V_19 = - V_67 ;
goto V_68;
}
if ( ! F_53 ( V_2 -> V_11 , V_72 ) )
F_54 ( V_2 -> V_11 ) ;
else {
V_2 -> V_4 = F_42 ( V_2 ) ;
V_2 -> V_6 = F_46 ( V_2 ) & V_73 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_74 = - 1 ;
}
memset ( & V_2 -> V_75 , 0 , sizeof( V_2 -> V_75 ) ) ;
V_68:
F_55 ( V_10 , V_66 ) ;
return V_19 ;
}
static int
F_56 ( struct V_1 * V_2 )
{
int V_19 ;
if ( V_2 -> V_32 . V_65 )
return 0 ;
V_2 -> V_32 . V_65 = F_57 ( V_2 -> V_11 , 4096 ) ;
if ( V_2 -> V_32 . V_65 == NULL ) {
F_37 ( L_6 ) ;
V_19 = - V_76 ;
goto V_77;
}
V_19 = F_58 ( V_2 -> V_32 . V_65 , V_78 ) ;
if ( V_19 )
goto V_79;
V_19 = F_59 ( V_2 -> V_32 . V_65 , 4096 , 0 ) ;
if ( V_19 )
goto V_79;
V_2 -> V_32 . V_33 = F_51 ( V_2 -> V_32 . V_65 ) ;
V_2 -> V_32 . V_80 = F_60 ( F_61 ( V_2 -> V_32 . V_65 -> V_81 -> V_82 ) ) ;
if ( V_2 -> V_32 . V_80 == NULL ) {
V_19 = - V_76 ;
goto V_83;
}
F_62 ( L_7 ,
V_2 -> V_63 , V_2 -> V_32 . V_33 ) ;
return 0 ;
V_83:
F_63 ( V_2 -> V_32 . V_65 ) ;
V_79:
F_64 ( & V_2 -> V_32 . V_65 -> V_84 ) ;
V_77:
return V_19 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
int V_19 = F_43 ( V_2 ) ;
if ( F_23 ( V_11 ) -> V_54 >= 4 && F_23 ( V_11 ) -> V_54 < 7 )
F_29 ( V_85 , F_34 ( V_86 ) ) ;
if ( F_23 ( V_11 ) -> V_54 >= 6 )
F_29 ( V_85 , F_34 ( V_87 ) ) ;
if ( F_23 ( V_11 ) -> V_54 == 6 )
F_29 ( V_88 ,
F_34 ( V_89 ) ) ;
if ( F_66 ( V_11 ) )
F_29 ( V_90 ,
F_41 ( V_89 ) |
F_34 ( V_91 ) ) ;
if ( F_23 ( V_11 ) -> V_54 >= 5 ) {
V_19 = F_56 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
if ( F_67 ( V_11 ) ) {
F_29 ( V_92 ,
F_41 ( V_93 ) ) ;
V_2 -> V_94 =
! ! ( F_27 ( V_88 ) & V_89 ) ;
}
if ( F_23 ( V_11 ) -> V_54 >= 6 )
F_29 ( V_95 , F_34 ( V_96 ) ) ;
if ( F_68 ( V_11 ) )
F_69 ( V_2 , ~ F_70 ( V_11 ) ) ;
return V_19 ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
if ( V_2 -> V_32 . V_65 == NULL )
return;
if ( F_23 ( V_11 ) -> V_54 >= 5 ) {
F_72 ( F_61 ( V_2 -> V_32 . V_65 -> V_81 -> V_82 ) ) ;
F_63 ( V_2 -> V_32 . V_65 ) ;
}
F_64 ( & V_2 -> V_32 . V_65 -> V_84 ) ;
V_2 -> V_32 . V_65 = NULL ;
}
static void
F_73 ( struct V_1 * V_2 ,
T_1 V_97 )
{
#define F_74 4
F_6 ( V_2 , F_16 ( 1 ) ) ;
F_6 ( V_2 , V_97 ) ;
F_6 ( V_2 , V_2 -> V_98 ) ;
F_6 ( V_2 , V_25 ) ;
}
static int
F_75 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_99 ;
int V_100 , V_19 , V_101 = 4 ;
if ( F_76 ( V_11 ) )
V_101 += ( ( V_102 - 1 ) * F_74 ) ;
#undef F_74
V_19 = F_5 ( V_2 , V_101 ) ;
if ( V_19 )
return V_19 ;
if ( F_76 ( V_11 ) ) {
F_77 (useless, dev_priv, i) {
T_1 V_103 = V_2 -> V_104 [ V_100 ] ;
if ( V_103 != V_105 )
F_73 ( V_2 , V_103 ) ;
}
}
F_6 ( V_2 , V_106 ) ;
F_6 ( V_2 , V_107 << V_108 ) ;
F_6 ( V_2 , V_2 -> V_98 ) ;
F_6 ( V_2 , V_109 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static inline bool F_78 ( struct V_26 * V_11 ,
T_1 V_110 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
return V_10 -> V_111 < V_110 ;
}
static int
F_79 ( struct V_1 * V_112 ,
struct V_1 * V_113 ,
T_1 V_110 )
{
int V_19 ;
T_1 V_114 = V_115 |
V_116 |
V_117 ;
V_110 -= 1 ;
F_80 ( V_113 -> V_118 [ V_112 -> V_119 ] ==
V_120 ) ;
V_19 = F_5 ( V_112 , 4 ) ;
if ( V_19 )
return V_19 ;
if ( F_81 ( ! F_78 ( V_112 -> V_11 , V_110 ) ) ) {
F_6 ( V_112 ,
V_114 |
V_113 -> V_118 [ V_112 -> V_119 ] ) ;
F_6 ( V_112 , V_110 ) ;
F_6 ( V_112 , 0 ) ;
F_6 ( V_112 , V_25 ) ;
} else {
F_6 ( V_112 , V_25 ) ;
F_6 ( V_112 , V_25 ) ;
F_6 ( V_112 , V_25 ) ;
F_6 ( V_112 , V_25 ) ;
}
F_7 ( V_112 ) ;
return 0 ;
}
static int
F_82 ( struct V_1 * V_2 )
{
T_1 V_31 = V_2 -> V_32 . V_33 + 128 ;
int V_19 ;
V_19 = F_5 ( V_2 , 32 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 4 ) | V_37 |
V_121 |
V_43 ) ;
F_6 ( V_2 , V_2 -> V_32 . V_33 | V_36 ) ;
F_6 ( V_2 , V_2 -> V_98 ) ;
F_6 ( V_2 , 0 ) ;
F_83 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_83 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_83 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_83 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_83 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_83 ( V_2 , V_31 ) ;
F_6 ( V_2 , F_12 ( 4 ) | V_37 |
V_121 |
V_43 |
V_122 ) ;
F_6 ( V_2 , V_2 -> V_32 . V_33 | V_36 ) ;
F_6 ( V_2 , V_2 -> V_98 ) ;
F_6 ( V_2 , 0 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static T_1
F_84 ( struct V_1 * V_2 , bool V_123 )
{
if ( ! V_123 ) {
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
F_85 ( F_25 ( V_2 -> V_55 ) ) ;
}
return F_86 ( V_2 , V_107 ) ;
}
static T_1
F_87 ( struct V_1 * V_2 , bool V_123 )
{
return F_86 ( V_2 , V_107 ) ;
}
static void
F_88 ( struct V_1 * V_2 , T_1 V_110 )
{
F_89 ( V_2 , V_107 , V_110 ) ;
}
static T_1
F_90 ( struct V_1 * V_2 , bool V_123 )
{
return V_2 -> V_32 . V_80 [ 0 ] ;
}
static void
F_91 ( struct V_1 * V_2 , T_1 V_110 )
{
V_2 -> V_32 . V_80 [ 0 ] = V_110 ;
}
static bool
F_92 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_124 )
return false ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( V_2 -> V_126 ++ == 0 )
F_94 ( V_10 , V_2 -> V_127 ) ;
F_95 ( & V_10 -> V_125 , V_38 ) ;
return true ;
}
static void
F_96 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( -- V_2 -> V_126 == 0 )
F_97 ( V_10 , V_2 -> V_127 ) ;
F_95 ( & V_10 -> V_125 , V_38 ) ;
}
static bool
F_98 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_124 )
return false ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( V_2 -> V_126 ++ == 0 ) {
V_10 -> V_128 &= ~ V_2 -> V_127 ;
F_29 ( V_129 , V_10 -> V_128 ) ;
F_85 ( V_129 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
return true ;
}
static void
F_99 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( -- V_2 -> V_126 == 0 ) {
V_10 -> V_128 |= V_2 -> V_127 ;
F_29 ( V_129 , V_10 -> V_128 ) ;
F_85 ( V_129 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
}
static bool
F_100 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_124 )
return false ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( V_2 -> V_126 ++ == 0 ) {
V_10 -> V_128 &= ~ V_2 -> V_127 ;
F_101 ( V_129 , V_10 -> V_128 ) ;
F_102 ( V_129 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
return true ;
}
static void
F_103 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( -- V_2 -> V_126 == 0 ) {
V_10 -> V_128 |= V_2 -> V_127 ;
F_101 ( V_129 , V_10 -> V_128 ) ;
F_102 ( V_129 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_130 = 0 ;
if ( F_66 ( V_11 ) ) {
switch ( V_2 -> V_119 ) {
case V_131 :
V_130 = V_132 ;
break;
case V_133 :
V_130 = V_134 ;
break;
case V_135 :
V_130 = V_136 ;
break;
case V_137 :
V_130 = V_138 ;
break;
}
} else if ( F_67 ( V_2 -> V_11 ) ) {
V_130 = F_104 ( V_2 -> V_55 ) ;
} else {
V_130 = F_105 ( V_2 -> V_55 ) ;
}
F_29 ( V_130 , ( T_1 ) V_2 -> V_139 . V_140 ) ;
F_85 ( V_130 ) ;
if ( F_23 ( V_11 ) -> V_54 >= 6 && F_23 ( V_11 ) -> V_54 < 8 ) {
T_1 V_141 = F_106 ( V_2 -> V_55 ) ;
F_80 ( ( F_36 ( V_2 ) & V_62 ) == 0 ) ;
F_29 ( V_141 ,
F_34 ( V_142 |
V_143 ) ) ;
if ( F_52 ( ( F_27 ( V_141 ) & V_143 ) == 0 ,
1000 ) )
F_37 ( L_8 ,
V_2 -> V_63 ) ;
}
}
static int
F_107 ( struct V_1 * V_2 ,
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
F_108 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_106 ) ;
F_6 ( V_2 , V_107 << V_108 ) ;
F_6 ( V_2 , V_2 -> V_98 ) ;
F_6 ( V_2 , V_109 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static bool
F_109 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_124 )
return false ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( V_2 -> V_126 ++ == 0 ) {
if ( F_68 ( V_11 ) && V_2 -> V_119 == V_131 )
F_69 ( V_2 ,
~ ( V_2 -> V_127 |
F_70 ( V_11 ) ) ) ;
else
F_69 ( V_2 , ~ V_2 -> V_127 ) ;
F_94 ( V_10 , V_2 -> V_127 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
return true ;
}
static void
F_110 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( -- V_2 -> V_126 == 0 ) {
if ( F_68 ( V_11 ) && V_2 -> V_119 == V_131 )
F_69 ( V_2 , ~ F_70 ( V_11 ) ) ;
else
F_69 ( V_2 , ~ 0 ) ;
F_97 ( V_10 , V_2 -> V_127 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
}
static bool
F_111 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_124 )
return false ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( V_2 -> V_126 ++ == 0 ) {
F_69 ( V_2 , ~ V_2 -> V_127 ) ;
F_112 ( V_10 , V_2 -> V_127 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
return true ;
}
static void
F_113 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_124 )
return;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( -- V_2 -> V_126 == 0 ) {
F_69 ( V_2 , ~ 0 ) ;
F_114 ( V_10 , V_2 -> V_127 ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
}
static bool
F_115 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_124 )
return false ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( V_2 -> V_126 ++ == 0 ) {
if ( F_68 ( V_11 ) && V_2 -> V_119 == V_131 ) {
F_69 ( V_2 ,
~ ( V_2 -> V_127 |
V_144 ) ) ;
} else {
F_69 ( V_2 , ~ V_2 -> V_127 ) ;
}
F_85 ( F_116 ( V_2 -> V_55 ) ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
return true ;
}
static void
F_117 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_93 ( & V_10 -> V_125 , V_38 ) ;
if ( -- V_2 -> V_126 == 0 ) {
if ( F_68 ( V_11 ) && V_2 -> V_119 == V_131 ) {
F_69 ( V_2 ,
~ V_144 ) ;
} else {
F_69 ( V_2 , ~ 0 ) ;
}
F_85 ( F_116 ( V_2 -> V_55 ) ) ;
}
F_95 ( & V_10 -> V_125 , V_38 ) ;
}
static int
F_118 ( struct V_1 * V_2 ,
T_1 V_145 , T_1 V_146 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_147 |
V_148 |
( V_38 & V_149 ? 0 : V_150 ) ) ;
F_6 ( V_2 , V_145 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_119 ( struct V_1 * V_2 ,
T_1 V_145 , T_1 V_151 ,
unsigned V_38 )
{
int V_19 ;
if ( V_38 & V_152 ) {
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_153 ) ;
F_6 ( V_2 , V_145 | ( V_38 & V_149 ? 0 : V_154 ) ) ;
F_6 ( V_2 , V_145 + V_151 - 8 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
} else {
T_1 V_155 = V_2 -> V_32 . V_33 ;
if ( V_151 > V_156 )
return - V_157 ;
V_19 = F_5 ( V_2 , 9 + 3 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_158 |
V_159 |
V_160 ) ;
F_6 ( V_2 , V_161 | V_162 | 4096 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , ( F_120 ( V_151 , 4096 ) << 16 ) | 1024 ) ;
F_6 ( V_2 , V_155 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 4096 ) ;
F_6 ( V_2 , V_145 ) ;
F_6 ( V_2 , V_20 ) ;
F_6 ( V_2 , V_153 ) ;
F_6 ( V_2 , V_155 | ( V_38 & V_149 ? 0 : V_154 ) ) ;
F_6 ( V_2 , V_155 + V_151 - 8 ) ;
F_7 ( V_2 ) ;
}
return 0 ;
}
static int
F_121 ( struct V_1 * V_2 ,
T_1 V_145 , T_1 V_151 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_147 | V_148 ) ;
F_6 ( V_2 , V_145 | ( V_38 & V_149 ? 0 : V_154 ) ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static void F_122 ( struct V_1 * V_2 )
{
struct V_64 * V_65 ;
V_65 = V_2 -> V_139 . V_65 ;
if ( V_65 == NULL )
return;
F_72 ( F_61 ( V_65 -> V_81 -> V_82 ) ) ;
F_63 ( V_65 ) ;
F_64 ( & V_65 -> V_84 ) ;
V_2 -> V_139 . V_65 = NULL ;
}
static int F_123 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_64 * V_65 ;
int V_19 ;
V_65 = F_57 ( V_11 , 4096 ) ;
if ( V_65 == NULL ) {
F_37 ( L_9 ) ;
V_19 = - V_76 ;
goto V_77;
}
V_19 = F_58 ( V_65 , V_78 ) ;
if ( V_19 )
goto V_79;
V_19 = F_59 ( V_65 , 4096 , 0 ) ;
if ( V_19 )
goto V_79;
V_2 -> V_139 . V_140 = F_51 ( V_65 ) ;
V_2 -> V_139 . V_163 = F_60 ( F_61 ( V_65 -> V_81 -> V_82 ) ) ;
if ( V_2 -> V_139 . V_163 == NULL ) {
V_19 = - V_76 ;
goto V_83;
}
V_2 -> V_139 . V_65 = V_65 ;
memset ( V_2 -> V_139 . V_163 , 0 , V_69 ) ;
F_62 ( L_10 ,
V_2 -> V_63 , V_2 -> V_139 . V_140 ) ;
return 0 ;
V_83:
F_63 ( V_65 ) ;
V_79:
F_64 ( & V_65 -> V_84 ) ;
V_77:
return V_19 ;
}
static int F_124 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
if ( ! V_10 -> V_58 ) {
V_10 -> V_58 =
F_125 ( V_2 -> V_11 , V_69 , V_69 ) ;
if ( ! V_10 -> V_58 )
return - V_76 ;
}
V_2 -> V_139 . V_163 = V_10 -> V_58 -> V_164 ;
memset ( V_2 -> V_139 . V_163 , 0 , V_69 ) ;
return 0 ;
}
static int F_126 ( struct V_26 * V_11 ,
struct V_1 * V_2 )
{
struct V_64 * V_65 ;
struct V_9 * V_10 = V_11 -> V_12 ;
int V_19 ;
V_2 -> V_11 = V_11 ;
F_127 ( & V_2 -> V_165 ) ;
F_127 ( & V_2 -> V_166 ) ;
V_2 -> V_8 = 32 * V_69 ;
memset ( V_2 -> V_167 , 0 , sizeof( V_2 -> V_167 ) ) ;
F_128 ( & V_2 -> V_168 ) ;
if ( F_48 ( V_11 ) ) {
V_19 = F_123 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else {
F_129 ( V_2 -> V_119 != V_131 ) ;
V_19 = F_124 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
V_65 = NULL ;
if ( ! F_130 ( V_11 ) )
V_65 = F_131 ( V_11 , V_2 -> V_8 ) ;
if ( V_65 == NULL )
V_65 = F_57 ( V_11 , V_2 -> V_8 ) ;
if ( V_65 == NULL ) {
F_37 ( L_11 ) ;
V_19 = - V_76 ;
goto V_169;
}
V_2 -> V_65 = V_65 ;
V_19 = F_59 ( V_65 , V_69 , V_170 ) ;
if ( V_19 )
goto V_79;
V_19 = F_132 ( V_65 , true ) ;
if ( V_19 )
goto V_83;
V_2 -> V_171 =
F_133 ( V_10 -> V_172 . V_173 + F_51 ( V_65 ) ,
V_2 -> V_8 ) ;
if ( V_2 -> V_171 == NULL ) {
F_37 ( L_12 ) ;
V_19 = - V_174 ;
goto V_83;
}
V_19 = V_2 -> V_175 ( V_2 ) ;
if ( V_19 )
goto V_176;
V_2 -> V_177 = V_2 -> V_8 ;
if ( F_134 ( V_2 -> V_11 ) || F_135 ( V_2 -> V_11 ) )
V_2 -> V_177 -= 128 ;
F_136 ( V_2 ) ;
return 0 ;
V_176:
F_137 ( V_2 -> V_171 ) ;
V_83:
F_63 ( V_65 ) ;
V_79:
F_64 ( & V_65 -> V_84 ) ;
V_2 -> V_65 = NULL ;
V_169:
F_122 ( V_2 ) ;
return V_19 ;
}
void F_138 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_19 ;
if ( V_2 -> V_65 == NULL )
return;
V_10 = V_2 -> V_11 -> V_12 ;
V_19 = F_139 ( V_2 ) ;
if ( V_19 && ! F_140 ( & V_10 -> V_13 ) )
F_37 ( L_13 ,
V_2 -> V_63 , V_19 ) ;
F_38 ( V_2 , 0 ) ;
F_137 ( V_2 -> V_171 ) ;
F_63 ( V_2 -> V_65 ) ;
F_64 ( & V_2 -> V_65 -> V_84 ) ;
V_2 -> V_65 = NULL ;
V_2 -> V_178 = NULL ;
V_2 -> V_98 = 0 ;
if ( V_2 -> V_179 )
V_2 -> V_179 ( V_2 ) ;
F_122 ( V_2 ) ;
}
static int F_141 ( struct V_1 * V_2 , int V_180 )
{
struct V_181 * V_182 ;
T_1 V_110 = 0 , V_6 ;
int V_19 ;
if ( V_2 -> V_74 != - 1 ) {
V_2 -> V_4 = V_2 -> V_74 ;
V_2 -> V_74 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_180 )
return 0 ;
}
F_142 (request, &ring->request_list, list) {
int V_3 ;
if ( V_182 -> V_6 == - 1 )
continue;
V_3 = V_182 -> V_6 - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
if ( V_3 >= V_180 ) {
V_110 = V_182 -> V_110 ;
V_6 = V_182 -> V_6 ;
break;
}
V_182 -> V_6 = - 1 ;
}
if ( V_110 == 0 )
return - V_157 ;
V_19 = F_143 ( V_2 , V_110 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_4 = V_6 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_80 ( V_2 -> V_3 < V_180 ) )
return - V_157 ;
return 0 ;
}
static int F_144 ( struct V_1 * V_2 , int V_180 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_183 ;
int V_19 ;
V_19 = F_141 ( V_2 , V_180 ) ;
if ( V_19 != - V_157 )
return V_19 ;
F_2 ( V_2 ) ;
F_145 ( V_2 ) ;
V_183 = V_184 + 60 * V_185 ;
do {
V_2 -> V_4 = F_42 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_180 ) {
F_146 ( V_2 ) ;
return 0 ;
}
if ( ! F_53 ( V_11 , V_72 ) &&
V_11 -> V_186 -> V_187 ) {
struct V_188 * V_189 = V_11 -> V_186 -> V_187 -> V_190 ;
if ( V_189 -> V_191 )
V_189 -> V_191 -> V_192 |= V_193 ;
}
F_147 ( 1 ) ;
V_19 = F_148 ( & V_10 -> V_13 ,
V_10 -> V_194 . V_195 ) ;
if ( V_19 )
return V_19 ;
} while ( ! F_149 ( V_184 , V_183 ) );
F_146 ( V_2 ) ;
return - V_196 ;
}
static int F_150 ( struct V_1 * V_2 )
{
T_3 T_4 * V_197 ;
int V_198 = V_2 -> V_8 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_198 ) {
int V_19 = F_144 ( V_2 , V_198 ) ;
if ( V_19 )
return V_19 ;
}
V_197 = V_2 -> V_171 + V_2 -> V_6 ;
V_198 /= 4 ;
while ( V_198 -- )
F_151 ( V_25 , V_197 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_139 ( struct V_1 * V_2 )
{
T_1 V_110 ;
int V_19 ;
if ( V_2 -> V_98 ) {
V_19 = F_152 ( V_2 , NULL ) ;
if ( V_19 )
return V_19 ;
}
if ( F_153 ( & V_2 -> V_166 ) )
return 0 ;
V_110 = F_154 ( V_2 -> V_166 . V_199 ,
struct V_181 ,
V_200 ) -> V_110 ;
return F_143 ( V_2 , V_110 ) ;
}
static int
F_155 ( struct V_1 * V_2 )
{
if ( V_2 -> V_98 )
return 0 ;
if ( V_2 -> V_178 == NULL ) {
struct V_181 * V_182 ;
V_182 = F_156 ( sizeof( * V_182 ) , V_201 ) ;
if ( V_182 == NULL )
return - V_76 ;
V_2 -> V_178 = V_182 ;
}
return F_157 ( V_2 -> V_11 , & V_2 -> V_98 ) ;
}
static int F_158 ( struct V_1 * V_2 ,
int V_202 )
{
int V_19 ;
if ( F_159 ( V_2 -> V_6 + V_202 > V_2 -> V_177 ) ) {
V_19 = F_150 ( V_2 ) ;
if ( F_159 ( V_19 ) )
return V_19 ;
}
if ( F_159 ( V_2 -> V_3 < V_202 ) ) {
V_19 = F_144 ( V_2 , V_202 ) ;
if ( F_159 ( V_19 ) )
return V_19 ;
}
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
int V_101 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
int V_19 ;
V_19 = F_148 ( & V_10 -> V_13 ,
V_10 -> V_194 . V_195 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_158 ( V_2 , V_101 * sizeof( T_3 ) ) ;
if ( V_19 )
return V_19 ;
V_19 = F_155 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_2 -> V_3 -= V_101 * sizeof( T_3 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 )
{
int V_101 = ( 64 - ( V_2 -> V_6 & 63 ) ) / sizeof( T_3 ) ;
int V_19 ;
if ( V_101 == 0 )
return 0 ;
V_19 = F_5 ( V_2 , V_101 ) ;
if ( V_19 )
return V_19 ;
while ( V_101 -- )
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
void F_161 ( struct V_1 * V_2 , T_1 V_110 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
F_129 ( V_2 -> V_98 ) ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 6 ) {
F_29 ( F_162 ( V_2 -> V_55 ) , 0 ) ;
F_29 ( F_163 ( V_2 -> V_55 ) , 0 ) ;
if ( F_164 ( V_2 -> V_11 ) )
F_29 ( F_165 ( V_2 -> V_55 ) , 0 ) ;
}
V_2 -> V_203 ( V_2 , V_110 ) ;
V_2 -> V_75 . V_110 = V_110 ;
}
static void F_166 ( struct V_1 * V_2 ,
T_1 V_47 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
F_29 ( V_204 ,
F_34 ( V_205 ) ) ;
F_167 ( V_206 , 0x0 ) ;
if ( F_52 ( ( F_27 ( V_204 ) &
V_207 ) == 0 ,
50 ) )
F_37 ( L_14 ) ;
F_21 ( V_2 , V_47 ) ;
F_85 ( F_168 ( V_2 -> V_55 ) ) ;
F_29 ( V_204 ,
F_41 ( V_205 ) ) ;
}
static int F_169 ( struct V_1 * V_2 ,
T_1 V_208 , T_1 V_209 )
{
T_3 V_18 ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
V_18 = V_210 ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 )
V_18 += 1 ;
if ( V_208 & V_211 )
V_18 |= V_212 | V_213 |
V_214 | V_215 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_216 | V_217 ) ;
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
F_170 ( struct V_1 * V_2 ,
T_1 V_145 , T_1 V_151 ,
unsigned V_38 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
bool V_218 = V_10 -> V_194 . V_219 != NULL &&
! ( V_38 & V_149 ) ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_220 | ( V_218 << 8 ) ) ;
F_6 ( V_2 , V_145 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_171 ( struct V_1 * V_2 ,
T_1 V_145 , T_1 V_151 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_147 | V_221 |
( V_38 & V_149 ? 0 : V_222 ) ) ;
F_6 ( V_2 , V_145 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_172 ( struct V_1 * V_2 ,
T_1 V_145 , T_1 V_151 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_147 |
( V_38 & V_149 ? 0 : V_150 ) ) ;
F_6 ( V_2 , V_145 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_173 ( struct V_1 * V_2 ,
T_1 V_208 , T_1 V_209 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_3 V_18 ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
V_18 = V_210 ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 )
V_18 += 1 ;
if ( V_208 & V_21 )
V_18 |= V_212 | V_214 |
V_215 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_216 | V_217 ) ;
if ( F_23 ( V_2 -> V_11 ) -> V_54 >= 8 ) {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
} else {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
}
F_7 ( V_2 ) ;
if ( F_66 ( V_11 ) && ! V_208 && V_209 )
return F_15 ( V_2 , V_223 ) ;
return 0 ;
}
int F_174 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_131 ] ;
V_2 -> V_63 = L_15 ;
V_2 -> V_119 = V_131 ;
V_2 -> V_55 = V_224 ;
if ( F_23 ( V_11 ) -> V_54 >= 6 ) {
V_2 -> V_225 = F_75 ;
V_2 -> V_209 = F_18 ;
if ( F_23 ( V_11 ) -> V_54 == 6 )
V_2 -> V_209 = F_13 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_209 = F_19 ;
V_2 -> V_226 = F_115 ;
V_2 -> V_227 = F_117 ;
} else {
V_2 -> V_226 = F_109 ;
V_2 -> V_227 = F_110 ;
}
V_2 -> V_127 = V_228 ;
V_2 -> V_229 = F_84 ;
V_2 -> V_203 = F_88 ;
V_2 -> V_230 = F_79 ;
V_2 -> V_118 [ V_131 ] = V_120 ;
V_2 -> V_118 [ V_135 ] = V_231 ;
V_2 -> V_118 [ V_133 ] = V_232 ;
V_2 -> V_118 [ V_137 ] = V_233 ;
V_2 -> V_104 [ V_131 ] = V_105 ;
V_2 -> V_104 [ V_135 ] = V_234 ;
V_2 -> V_104 [ V_133 ] = V_235 ;
V_2 -> V_104 [ V_137 ] = V_236 ;
} else if ( F_10 ( V_11 ) ) {
V_2 -> V_225 = F_82 ;
V_2 -> V_209 = F_8 ;
V_2 -> V_229 = F_90 ;
V_2 -> V_203 = F_91 ;
V_2 -> V_226 = F_92 ;
V_2 -> V_227 = F_96 ;
V_2 -> V_127 = V_228 |
V_237 ;
} else {
V_2 -> V_225 = F_108 ;
if ( F_23 ( V_11 ) -> V_54 < 4 )
V_2 -> V_209 = F_4 ;
else
V_2 -> V_209 = F_8 ;
V_2 -> V_229 = F_87 ;
V_2 -> V_203 = F_88 ;
if ( F_32 ( V_11 ) ) {
V_2 -> V_226 = F_100 ;
V_2 -> V_227 = F_103 ;
} else {
V_2 -> V_226 = F_98 ;
V_2 -> V_227 = F_99 ;
}
V_2 -> V_127 = V_238 ;
}
V_2 -> V_15 = F_20 ;
if ( F_175 ( V_11 ) )
V_2 -> V_239 = F_171 ;
else if ( F_176 ( V_11 ) )
V_2 -> V_239 = F_170 ;
else if ( F_23 ( V_11 ) -> V_54 >= 6 )
V_2 -> V_239 = F_172 ;
else if ( F_23 ( V_11 ) -> V_54 >= 4 )
V_2 -> V_239 = F_118 ;
else if ( F_134 ( V_11 ) || F_135 ( V_11 ) )
V_2 -> V_239 = F_119 ;
else
V_2 -> V_239 = F_121 ;
V_2 -> V_175 = F_65 ;
V_2 -> V_179 = F_71 ;
if ( F_177 ( V_11 ) ) {
struct V_64 * V_65 ;
int V_19 ;
V_65 = F_57 ( V_11 , V_156 ) ;
if ( V_65 == NULL ) {
F_37 ( L_16 ) ;
return - V_76 ;
}
V_19 = F_59 ( V_65 , 0 , 0 ) ;
if ( V_19 != 0 ) {
F_64 ( & V_65 -> V_84 ) ;
F_37 ( L_17 ) ;
return V_19 ;
}
V_2 -> V_32 . V_65 = V_65 ;
V_2 -> V_32 . V_33 = F_51 ( V_65 ) ;
}
return F_126 ( V_11 , V_2 ) ;
}
int F_178 ( struct V_26 * V_11 , T_2 V_240 , T_1 V_8 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_131 ] ;
int V_19 ;
V_2 -> V_63 = L_15 ;
V_2 -> V_119 = V_131 ;
V_2 -> V_55 = V_224 ;
if ( F_23 ( V_11 ) -> V_54 >= 6 ) {
return - V_241 ;
}
V_2 -> V_225 = F_108 ;
if ( F_23 ( V_11 ) -> V_54 < 4 )
V_2 -> V_209 = F_4 ;
else
V_2 -> V_209 = F_8 ;
V_2 -> V_229 = F_87 ;
V_2 -> V_203 = F_88 ;
if ( F_32 ( V_11 ) ) {
V_2 -> V_226 = F_100 ;
V_2 -> V_227 = F_103 ;
} else {
V_2 -> V_226 = F_98 ;
V_2 -> V_227 = F_99 ;
}
V_2 -> V_127 = V_238 ;
V_2 -> V_15 = F_20 ;
if ( F_23 ( V_11 ) -> V_54 >= 4 )
V_2 -> V_239 = F_118 ;
else if ( F_134 ( V_11 ) || F_135 ( V_11 ) )
V_2 -> V_239 = F_119 ;
else
V_2 -> V_239 = F_121 ;
V_2 -> V_175 = F_65 ;
V_2 -> V_179 = F_71 ;
V_2 -> V_11 = V_11 ;
F_127 ( & V_2 -> V_165 ) ;
F_127 ( & V_2 -> V_166 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_177 = V_2 -> V_8 ;
if ( F_134 ( V_2 -> V_11 ) || F_135 ( V_2 -> V_11 ) )
V_2 -> V_177 -= 128 ;
V_2 -> V_171 = F_133 ( V_240 , V_8 ) ;
if ( V_2 -> V_171 == NULL ) {
F_37 ( L_18
L_19 ) ;
return - V_76 ;
}
if ( ! F_48 ( V_11 ) ) {
V_19 = F_124 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
int F_179 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_135 ] ;
V_2 -> V_63 = L_20 ;
V_2 -> V_119 = V_135 ;
V_2 -> V_15 = F_20 ;
if ( F_23 ( V_11 ) -> V_54 >= 6 ) {
V_2 -> V_55 = V_242 ;
if ( F_67 ( V_11 ) )
V_2 -> V_15 = F_166 ;
V_2 -> V_209 = F_169 ;
V_2 -> V_225 = F_75 ;
V_2 -> V_229 = F_84 ;
V_2 -> V_203 = F_88 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_127 =
V_228 << V_243 ;
V_2 -> V_226 = F_115 ;
V_2 -> V_227 = F_117 ;
V_2 -> V_239 =
F_170 ;
} else {
V_2 -> V_127 = V_244 ;
V_2 -> V_226 = F_109 ;
V_2 -> V_227 = F_110 ;
V_2 -> V_239 =
F_172 ;
}
V_2 -> V_230 = F_79 ;
V_2 -> V_118 [ V_131 ] = V_245 ;
V_2 -> V_118 [ V_135 ] = V_120 ;
V_2 -> V_118 [ V_133 ] = V_246 ;
V_2 -> V_118 [ V_137 ] = V_247 ;
V_2 -> V_104 [ V_131 ] = V_248 ;
V_2 -> V_104 [ V_135 ] = V_105 ;
V_2 -> V_104 [ V_133 ] = V_249 ;
V_2 -> V_104 [ V_137 ] = V_250 ;
} else {
V_2 -> V_55 = V_251 ;
V_2 -> V_209 = F_107 ;
V_2 -> V_225 = F_108 ;
V_2 -> V_229 = F_87 ;
V_2 -> V_203 = F_88 ;
if ( F_10 ( V_11 ) ) {
V_2 -> V_127 = V_252 ;
V_2 -> V_226 = F_92 ;
V_2 -> V_227 = F_96 ;
} else {
V_2 -> V_127 = V_253 ;
V_2 -> V_226 = F_98 ;
V_2 -> V_227 = F_99 ;
}
V_2 -> V_239 = F_118 ;
}
V_2 -> V_175 = F_43 ;
return F_126 ( V_11 , V_2 ) ;
}
int F_180 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_133 ] ;
V_2 -> V_63 = L_21 ;
V_2 -> V_119 = V_133 ;
V_2 -> V_55 = V_254 ;
V_2 -> V_15 = F_20 ;
V_2 -> V_209 = F_173 ;
V_2 -> V_225 = F_75 ;
V_2 -> V_229 = F_84 ;
V_2 -> V_203 = F_88 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_127 =
V_228 << V_255 ;
V_2 -> V_226 = F_115 ;
V_2 -> V_227 = F_117 ;
V_2 -> V_239 = F_170 ;
} else {
V_2 -> V_127 = V_256 ;
V_2 -> V_226 = F_109 ;
V_2 -> V_227 = F_110 ;
V_2 -> V_239 = F_172 ;
}
V_2 -> V_230 = F_79 ;
V_2 -> V_118 [ V_131 ] = V_257 ;
V_2 -> V_118 [ V_135 ] = V_258 ;
V_2 -> V_118 [ V_133 ] = V_120 ;
V_2 -> V_118 [ V_137 ] = V_259 ;
V_2 -> V_104 [ V_131 ] = V_260 ;
V_2 -> V_104 [ V_135 ] = V_261 ;
V_2 -> V_104 [ V_133 ] = V_105 ;
V_2 -> V_104 [ V_137 ] = V_262 ;
V_2 -> V_175 = F_43 ;
return F_126 ( V_11 , V_2 ) ;
}
int F_181 ( struct V_26 * V_11 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_137 ] ;
V_2 -> V_63 = L_22 ;
V_2 -> V_119 = V_137 ;
V_2 -> V_55 = V_263 ;
V_2 -> V_15 = F_20 ;
V_2 -> V_209 = F_173 ;
V_2 -> V_225 = F_75 ;
V_2 -> V_229 = F_84 ;
V_2 -> V_203 = F_88 ;
if ( F_23 ( V_11 ) -> V_54 >= 8 ) {
V_2 -> V_127 =
V_228 << V_264 ;
V_2 -> V_226 = F_115 ;
V_2 -> V_227 = F_117 ;
V_2 -> V_239 = F_170 ;
} else {
V_2 -> V_127 = V_265 ;
V_2 -> V_226 = F_111 ;
V_2 -> V_227 = F_113 ;
V_2 -> V_239 = F_172 ;
}
V_2 -> V_230 = F_79 ;
V_2 -> V_118 [ V_131 ] = V_266 ;
V_2 -> V_118 [ V_135 ] = V_267 ;
V_2 -> V_118 [ V_133 ] = V_268 ;
V_2 -> V_118 [ V_137 ] = V_120 ;
V_2 -> V_104 [ V_131 ] = V_269 ;
V_2 -> V_104 [ V_135 ] = V_270 ;
V_2 -> V_104 [ V_133 ] = V_271 ;
V_2 -> V_104 [ V_137 ] = V_105 ;
V_2 -> V_175 = F_43 ;
return F_126 ( V_11 , V_2 ) ;
}
int
F_182 ( struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_2 -> V_272 )
return 0 ;
V_19 = V_2 -> V_209 ( V_2 , 0 , V_211 ) ;
if ( V_19 )
return V_19 ;
F_183 ( V_2 , 0 , V_211 ) ;
V_2 -> V_272 = false ;
return 0 ;
}
int
F_184 ( struct V_1 * V_2 )
{
T_3 V_17 ;
int V_19 ;
V_17 = 0 ;
if ( V_2 -> V_272 )
V_17 = V_211 ;
V_19 = V_2 -> V_209 ( V_2 , V_211 , V_17 ) ;
if ( V_19 )
return V_19 ;
F_183 ( V_2 , V_211 , V_17 ) ;
V_2 -> V_272 = false ;
return 0 ;
}
