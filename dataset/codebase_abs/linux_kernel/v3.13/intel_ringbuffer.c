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
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_25 ) ;
F_6 ( V_2 , F_16 ( 1 ) ) ;
F_6 ( V_2 , V_49 ) ;
F_6 ( V_2 , V_47 ) ;
F_7 ( V_2 ) ;
V_2 -> V_48 = false ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
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
V_38 |= V_50 ;
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
if ( V_17 )
return F_15 ( V_2 , V_51 ) ;
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
V_38 |= V_50 ;
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
static void F_19 ( struct V_1 * V_2 ,
T_1 V_47 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
F_20 ( V_2 , V_47 ) ;
}
T_1 F_21 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_52 = F_22 ( V_2 -> V_11 ) -> V_53 >= 4 ?
F_23 ( V_2 -> V_54 ) : V_55 ;
return F_24 ( V_52 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_56 ;
V_56 = V_10 -> V_57 -> V_58 ;
if ( F_22 ( V_2 -> V_11 ) -> V_53 >= 4 )
V_56 |= ( V_10 -> V_57 -> V_58 >> 28 ) & 0xf0 ;
F_26 ( V_59 , V_56 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
struct V_60 * V_61 = V_2 -> V_61 ;
int V_19 = 0 ;
T_1 V_4 ;
F_28 ( V_10 ) ;
if ( F_29 ( V_11 ) )
F_30 ( V_2 ) ;
else
F_25 ( V_2 ) ;
F_31 ( V_2 , 0 ) ;
F_32 ( V_2 , 0 ) ;
V_2 -> V_15 ( V_2 , 0 ) ;
V_4 = F_33 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_34 ( L_1
L_2 ,
V_2 -> V_62 ,
F_35 ( V_2 ) ,
F_33 ( V_2 ) ,
F_36 ( V_2 ) ,
F_37 ( V_2 ) ) ;
F_32 ( V_2 , 0 ) ;
if ( F_33 ( V_2 ) & V_5 ) {
F_38 ( L_3
L_2 ,
V_2 -> V_62 ,
F_35 ( V_2 ) ,
F_33 ( V_2 ) ,
F_36 ( V_2 ) ,
F_37 ( V_2 ) ) ;
}
}
F_39 ( V_2 , F_40 ( V_61 ) ) ;
F_31 ( V_2 ,
( ( V_2 -> V_8 - V_63 ) & V_64 )
| V_65 ) ;
if ( F_41 ( ( F_35 ( V_2 ) & V_65 ) != 0 &&
F_37 ( V_2 ) == F_40 ( V_61 ) &&
( F_33 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_38 ( L_4
L_2 ,
V_2 -> V_62 ,
F_35 ( V_2 ) ,
F_33 ( V_2 ) ,
F_36 ( V_2 ) ,
F_37 ( V_2 ) ) ;
V_19 = - V_66 ;
goto V_67;
}
if ( ! F_42 ( V_2 -> V_11 , V_68 ) )
F_43 ( V_2 -> V_11 ) ;
else {
V_2 -> V_4 = F_33 ( V_2 ) ;
V_2 -> V_6 = F_36 ( V_2 ) & V_69 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_70 = - 1 ;
}
memset ( & V_2 -> V_71 , 0 , sizeof( V_2 -> V_71 ) ) ;
V_67:
F_44 ( V_10 ) ;
return V_19 ;
}
static int
F_45 ( struct V_1 * V_2 )
{
int V_19 ;
if ( V_2 -> V_32 . V_61 )
return 0 ;
V_2 -> V_32 . V_61 = F_46 ( V_2 -> V_11 , 4096 ) ;
if ( V_2 -> V_32 . V_61 == NULL ) {
F_38 ( L_5 ) ;
V_19 = - V_72 ;
goto V_73;
}
F_47 ( V_2 -> V_32 . V_61 , V_74 ) ;
V_19 = F_48 ( V_2 -> V_32 . V_61 , 4096 , true , false ) ;
if ( V_19 )
goto V_75;
V_2 -> V_32 . V_33 = F_40 ( V_2 -> V_32 . V_61 ) ;
V_2 -> V_32 . V_76 = F_49 ( F_50 ( V_2 -> V_32 . V_61 -> V_77 -> V_78 ) ) ;
if ( V_2 -> V_32 . V_76 == NULL ) {
V_19 = - V_72 ;
goto V_79;
}
F_51 ( L_6 ,
V_2 -> V_62 , V_2 -> V_32 . V_33 ) ;
return 0 ;
V_79:
F_52 ( V_2 -> V_32 . V_61 ) ;
V_75:
F_53 ( & V_2 -> V_32 . V_61 -> V_80 ) ;
V_73:
return V_19 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
int V_19 = F_27 ( V_2 ) ;
if ( F_22 ( V_11 ) -> V_53 > 3 )
F_26 ( V_81 , F_55 ( V_82 ) ) ;
if ( F_22 ( V_11 ) -> V_53 >= 6 )
F_26 ( V_81 , F_55 ( V_83 ) ) ;
if ( F_22 ( V_11 ) -> V_53 == 6 )
F_26 ( V_84 ,
F_55 ( V_85 ) ) ;
if ( F_56 ( V_11 ) )
F_26 ( V_86 ,
F_57 ( V_85 ) |
F_55 ( V_87 ) ) ;
if ( F_22 ( V_11 ) -> V_53 >= 5 ) {
V_19 = F_45 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
if ( F_58 ( V_11 ) ) {
F_26 ( V_88 ,
F_57 ( V_89 ) ) ;
V_2 -> V_90 =
! ! ( F_24 ( V_84 ) & V_85 ) ;
}
if ( F_22 ( V_11 ) -> V_53 >= 6 )
F_26 ( V_91 , F_55 ( V_92 ) ) ;
if ( F_59 ( V_11 ) )
F_60 ( V_2 , ~ F_61 ( V_11 ) ) ;
return V_19 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
if ( V_2 -> V_32 . V_61 == NULL )
return;
if ( F_22 ( V_11 ) -> V_53 >= 5 ) {
F_63 ( F_50 ( V_2 -> V_32 . V_61 -> V_77 -> V_78 ) ) ;
F_52 ( V_2 -> V_32 . V_61 ) ;
}
F_53 ( & V_2 -> V_32 . V_61 -> V_80 ) ;
V_2 -> V_32 . V_61 = NULL ;
}
static void
F_64 ( struct V_1 * V_2 ,
T_1 V_93 )
{
#define F_65 4
F_6 ( V_2 , F_16 ( 1 ) ) ;
F_6 ( V_2 , V_93 ) ;
F_6 ( V_2 , V_2 -> V_94 ) ;
F_6 ( V_2 , V_25 ) ;
}
static int
F_66 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
struct V_1 * V_95 ;
int V_96 , V_19 ;
V_19 = F_5 ( V_2 , ( ( V_97 - 1 ) *
F_65 ) +
4 ) ;
if ( V_19 )
return V_19 ;
#undef F_65
F_67 (useless, dev_priv, i) {
T_1 V_98 = V_2 -> V_99 [ V_96 ] ;
if ( V_98 != V_100 )
F_64 ( V_2 , V_98 ) ;
}
F_6 ( V_2 , V_101 ) ;
F_6 ( V_2 , V_102 << V_103 ) ;
F_6 ( V_2 , V_2 -> V_94 ) ;
F_6 ( V_2 , V_104 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static inline bool F_68 ( struct V_26 * V_11 ,
T_1 V_105 )
{
struct V_9 * V_10 = V_11 -> V_12 ;
return V_10 -> V_106 < V_105 ;
}
static int
F_69 ( struct V_1 * V_107 ,
struct V_1 * V_108 ,
T_1 V_105 )
{
int V_19 ;
T_1 V_109 = V_110 |
V_111 |
V_112 ;
V_105 -= 1 ;
F_70 ( V_108 -> V_113 [ V_107 -> V_114 ] ==
V_115 ) ;
V_19 = F_5 ( V_107 , 4 ) ;
if ( V_19 )
return V_19 ;
if ( F_71 ( ! F_68 ( V_107 -> V_11 , V_105 ) ) ) {
F_6 ( V_107 ,
V_109 |
V_108 -> V_113 [ V_107 -> V_114 ] ) ;
F_6 ( V_107 , V_105 ) ;
F_6 ( V_107 , 0 ) ;
F_6 ( V_107 , V_25 ) ;
} else {
F_6 ( V_107 , V_25 ) ;
F_6 ( V_107 , V_25 ) ;
F_6 ( V_107 , V_25 ) ;
F_6 ( V_107 , V_25 ) ;
}
F_7 ( V_107 ) ;
return 0 ;
}
static int
F_72 ( struct V_1 * V_2 )
{
T_1 V_31 = V_2 -> V_32 . V_33 + 128 ;
int V_19 ;
V_19 = F_5 ( V_2 , 32 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , F_12 ( 4 ) | V_37 |
V_116 |
V_43 ) ;
F_6 ( V_2 , V_2 -> V_32 . V_33 | V_36 ) ;
F_6 ( V_2 , V_2 -> V_94 ) ;
F_6 ( V_2 , 0 ) ;
F_73 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_73 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_73 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_73 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_73 ( V_2 , V_31 ) ;
V_31 += 128 ;
F_73 ( V_2 , V_31 ) ;
F_6 ( V_2 , F_12 ( 4 ) | V_37 |
V_116 |
V_43 |
V_117 ) ;
F_6 ( V_2 , V_2 -> V_32 . V_33 | V_36 ) ;
F_6 ( V_2 , V_2 -> V_94 ) ;
F_6 ( V_2 , 0 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static T_1
F_74 ( struct V_1 * V_2 , bool V_118 )
{
if ( ! V_118 )
F_21 ( V_2 ) ;
return F_75 ( V_2 , V_102 ) ;
}
static T_1
F_76 ( struct V_1 * V_2 , bool V_118 )
{
return F_75 ( V_2 , V_102 ) ;
}
static void
F_77 ( struct V_1 * V_2 , T_1 V_105 )
{
F_78 ( V_2 , V_102 , V_105 ) ;
}
static T_1
F_79 ( struct V_1 * V_2 , bool V_118 )
{
return V_2 -> V_32 . V_76 [ 0 ] ;
}
static void
F_80 ( struct V_1 * V_2 , T_1 V_105 )
{
V_2 -> V_32 . V_76 [ 0 ] = V_105 ;
}
static bool
F_81 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_119 )
return false ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( V_2 -> V_121 ++ == 0 )
F_83 ( V_10 , V_2 -> V_122 ) ;
F_84 ( & V_10 -> V_120 , V_38 ) ;
return true ;
}
static void
F_85 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( -- V_2 -> V_121 == 0 )
F_86 ( V_10 , V_2 -> V_122 ) ;
F_84 ( & V_10 -> V_120 , V_38 ) ;
}
static bool
F_87 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_119 )
return false ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( V_2 -> V_121 ++ == 0 ) {
V_10 -> V_123 &= ~ V_2 -> V_122 ;
F_26 ( V_124 , V_10 -> V_123 ) ;
F_88 ( V_124 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
return true ;
}
static void
F_89 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( -- V_2 -> V_121 == 0 ) {
V_10 -> V_123 |= V_2 -> V_122 ;
F_26 ( V_124 , V_10 -> V_123 ) ;
F_88 ( V_124 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
}
static bool
F_90 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_119 )
return false ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( V_2 -> V_121 ++ == 0 ) {
V_10 -> V_123 &= ~ V_2 -> V_122 ;
F_91 ( V_124 , V_10 -> V_123 ) ;
F_92 ( V_124 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
return true ;
}
static void
F_93 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( -- V_2 -> V_121 == 0 ) {
V_10 -> V_123 |= V_2 -> V_122 ;
F_91 ( V_124 , V_10 -> V_123 ) ;
F_92 ( V_124 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
T_1 V_125 = 0 ;
if ( F_56 ( V_11 ) ) {
switch ( V_2 -> V_114 ) {
case V_126 :
V_125 = V_127 ;
break;
case V_128 :
V_125 = V_129 ;
break;
case V_130 :
V_125 = V_131 ;
break;
case V_132 :
V_125 = V_133 ;
break;
}
} else if ( F_58 ( V_2 -> V_11 ) ) {
V_125 = F_94 ( V_2 -> V_54 ) ;
} else {
V_125 = F_95 ( V_2 -> V_54 ) ;
}
F_26 ( V_125 , ( T_1 ) V_2 -> V_134 . V_135 ) ;
F_88 ( V_125 ) ;
if ( F_22 ( V_11 ) -> V_53 >= 6 ) {
T_1 V_136 = F_96 ( V_2 -> V_54 ) ;
F_26 ( V_136 ,
F_55 ( V_137 |
V_138 ) ) ;
if ( F_41 ( ( F_24 ( V_136 ) & V_138 ) == 0 ,
1000 ) )
F_38 ( L_7 ,
V_2 -> V_62 ) ;
}
}
static int
F_97 ( struct V_1 * V_2 ,
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
F_98 ( struct V_1 * V_2 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_101 ) ;
F_6 ( V_2 , V_102 << V_103 ) ;
F_6 ( V_2 , V_2 -> V_94 ) ;
F_6 ( V_2 , V_104 ) ;
F_2 ( V_2 ) ;
return 0 ;
}
static bool
F_99 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_119 )
return false ;
F_28 ( V_10 ) ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( V_2 -> V_121 ++ == 0 ) {
if ( F_59 ( V_11 ) && V_2 -> V_114 == V_126 )
F_60 ( V_2 ,
~ ( V_2 -> V_122 |
F_61 ( V_11 ) ) ) ;
else
F_60 ( V_2 , ~ V_2 -> V_122 ) ;
F_83 ( V_10 , V_2 -> V_122 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
return true ;
}
static void
F_100 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_2 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( -- V_2 -> V_121 == 0 ) {
if ( F_59 ( V_11 ) && V_2 -> V_114 == V_126 )
F_60 ( V_2 , ~ F_61 ( V_11 ) ) ;
else
F_60 ( V_2 , ~ 0 ) ;
F_86 ( V_10 , V_2 -> V_122 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
F_44 ( V_10 ) ;
}
static bool
F_101 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_119 )
return false ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( V_2 -> V_121 ++ == 0 ) {
F_60 ( V_2 , ~ V_2 -> V_122 ) ;
F_102 ( V_10 , V_2 -> V_122 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
return true ;
}
static void
F_103 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_119 )
return;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( -- V_2 -> V_121 == 0 ) {
F_60 ( V_2 , ~ 0 ) ;
F_104 ( V_10 , V_2 -> V_122 ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
}
static bool
F_105 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
if ( ! V_11 -> V_119 )
return false ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( V_2 -> V_121 ++ == 0 ) {
if ( F_59 ( V_11 ) && V_2 -> V_114 == V_126 ) {
F_60 ( V_2 ,
~ ( V_2 -> V_122 |
V_139 ) ) ;
} else {
F_60 ( V_2 , ~ V_2 -> V_122 ) ;
}
F_88 ( F_106 ( V_2 -> V_54 ) ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
return true ;
}
static void
F_107 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_38 ;
F_82 ( & V_10 -> V_120 , V_38 ) ;
if ( -- V_2 -> V_121 == 0 ) {
if ( F_59 ( V_11 ) && V_2 -> V_114 == V_126 ) {
F_60 ( V_2 ,
~ V_139 ) ;
} else {
F_60 ( V_2 , ~ 0 ) ;
}
F_88 ( F_106 ( V_2 -> V_54 ) ) ;
}
F_84 ( & V_10 -> V_120 , V_38 ) ;
}
static int
F_108 ( struct V_1 * V_2 ,
T_1 V_140 , T_1 V_141 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_142 |
V_143 |
( V_38 & V_144 ? 0 : V_145 ) ) ;
F_6 ( V_2 , V_140 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_109 ( struct V_1 * V_2 ,
T_1 V_140 , T_1 V_146 ,
unsigned V_38 )
{
int V_19 ;
if ( V_38 & V_147 ) {
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_148 ) ;
F_6 ( V_2 , V_140 | ( V_38 & V_144 ? 0 : V_149 ) ) ;
F_6 ( V_2 , V_140 + V_146 - 8 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
} else {
T_1 V_150 = V_2 -> V_32 . V_33 ;
if ( V_146 > V_151 )
return - V_152 ;
V_19 = F_5 ( V_2 , 9 + 3 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_153 |
V_154 |
V_155 ) ;
F_6 ( V_2 , V_156 | V_157 | 4096 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , ( F_110 ( V_146 , 4096 ) << 16 ) | 1024 ) ;
F_6 ( V_2 , V_150 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 4096 ) ;
F_6 ( V_2 , V_140 ) ;
F_6 ( V_2 , V_20 ) ;
F_6 ( V_2 , V_148 ) ;
F_6 ( V_2 , V_150 | ( V_38 & V_144 ? 0 : V_149 ) ) ;
F_6 ( V_2 , V_150 + V_146 - 8 ) ;
F_7 ( V_2 ) ;
}
return 0 ;
}
static int
F_111 ( struct V_1 * V_2 ,
T_1 V_140 , T_1 V_146 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_142 | V_143 ) ;
F_6 ( V_2 , V_140 | ( V_38 & V_144 ? 0 : V_149 ) ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_60 * V_61 ;
V_61 = V_2 -> V_134 . V_61 ;
if ( V_61 == NULL )
return;
F_63 ( F_50 ( V_61 -> V_77 -> V_78 ) ) ;
F_52 ( V_61 ) ;
F_53 ( & V_61 -> V_80 ) ;
V_2 -> V_134 . V_61 = NULL ;
}
static int F_113 ( struct V_1 * V_2 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_60 * V_61 ;
int V_19 ;
V_61 = F_46 ( V_11 , 4096 ) ;
if ( V_61 == NULL ) {
F_38 ( L_8 ) ;
V_19 = - V_72 ;
goto V_73;
}
F_47 ( V_61 , V_74 ) ;
V_19 = F_48 ( V_61 , 4096 , true , false ) ;
if ( V_19 != 0 ) {
goto V_75;
}
V_2 -> V_134 . V_135 = F_40 ( V_61 ) ;
V_2 -> V_134 . V_158 = F_49 ( F_50 ( V_61 -> V_77 -> V_78 ) ) ;
if ( V_2 -> V_134 . V_158 == NULL ) {
V_19 = - V_72 ;
goto V_79;
}
V_2 -> V_134 . V_61 = V_61 ;
memset ( V_2 -> V_134 . V_158 , 0 , V_63 ) ;
F_51 ( L_9 ,
V_2 -> V_62 , V_2 -> V_134 . V_135 ) ;
return 0 ;
V_79:
F_52 ( V_61 ) ;
V_75:
F_53 ( & V_61 -> V_80 ) ;
V_73:
return V_19 ;
}
static int F_114 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
if ( ! V_10 -> V_57 ) {
V_10 -> V_57 =
F_115 ( V_2 -> V_11 , V_63 , V_63 ) ;
if ( ! V_10 -> V_57 )
return - V_72 ;
}
V_2 -> V_134 . V_158 = V_10 -> V_57 -> V_159 ;
memset ( V_2 -> V_134 . V_158 , 0 , V_63 ) ;
return 0 ;
}
static int F_116 ( struct V_26 * V_11 ,
struct V_1 * V_2 )
{
struct V_60 * V_61 ;
struct V_9 * V_10 = V_11 -> V_12 ;
int V_19 ;
V_2 -> V_11 = V_11 ;
F_117 ( & V_2 -> V_160 ) ;
F_117 ( & V_2 -> V_161 ) ;
V_2 -> V_8 = 32 * V_63 ;
memset ( V_2 -> V_162 , 0 , sizeof( V_2 -> V_162 ) ) ;
F_118 ( & V_2 -> V_163 ) ;
if ( F_29 ( V_11 ) ) {
V_19 = F_113 ( V_2 ) ;
if ( V_19 )
return V_19 ;
} else {
F_119 ( V_2 -> V_114 != V_126 ) ;
V_19 = F_114 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
V_61 = NULL ;
if ( ! F_120 ( V_11 ) )
V_61 = F_121 ( V_11 , V_2 -> V_8 ) ;
if ( V_61 == NULL )
V_61 = F_46 ( V_11 , V_2 -> V_8 ) ;
if ( V_61 == NULL ) {
F_38 ( L_10 ) ;
V_19 = - V_72 ;
goto V_164;
}
V_2 -> V_61 = V_61 ;
V_19 = F_48 ( V_61 , V_63 , true , false ) ;
if ( V_19 )
goto V_75;
V_19 = F_122 ( V_61 , true ) ;
if ( V_19 )
goto V_79;
V_2 -> V_165 =
F_123 ( V_10 -> V_166 . V_167 + F_40 ( V_61 ) ,
V_2 -> V_8 ) ;
if ( V_2 -> V_165 == NULL ) {
F_38 ( L_11 ) ;
V_19 = - V_168 ;
goto V_79;
}
V_19 = V_2 -> V_169 ( V_2 ) ;
if ( V_19 )
goto V_170;
V_2 -> V_171 = V_2 -> V_8 ;
if ( F_124 ( V_2 -> V_11 ) || F_125 ( V_2 -> V_11 ) )
V_2 -> V_171 -= 128 ;
return 0 ;
V_170:
F_126 ( V_2 -> V_165 ) ;
V_79:
F_52 ( V_61 ) ;
V_75:
F_53 ( & V_61 -> V_80 ) ;
V_2 -> V_61 = NULL ;
V_164:
F_112 ( V_2 ) ;
return V_19 ;
}
void F_127 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
int V_19 ;
if ( V_2 -> V_61 == NULL )
return;
V_10 = V_2 -> V_11 -> V_12 ;
V_19 = F_128 ( V_2 ) ;
if ( V_19 && ! F_129 ( & V_10 -> V_13 ) )
F_38 ( L_12 ,
V_2 -> V_62 , V_19 ) ;
F_31 ( V_2 , 0 ) ;
F_126 ( V_2 -> V_165 ) ;
F_52 ( V_2 -> V_61 ) ;
F_53 ( & V_2 -> V_61 -> V_80 ) ;
V_2 -> V_61 = NULL ;
V_2 -> V_172 = NULL ;
V_2 -> V_94 = 0 ;
if ( V_2 -> V_173 )
V_2 -> V_173 ( V_2 ) ;
F_112 ( V_2 ) ;
}
static int F_130 ( struct V_1 * V_2 , T_1 V_105 )
{
int V_19 ;
V_19 = F_131 ( V_2 , V_105 ) ;
if ( ! V_19 )
F_132 ( V_2 ) ;
return V_19 ;
}
static int F_133 ( struct V_1 * V_2 , int V_174 )
{
struct V_175 * V_176 ;
T_1 V_105 = 0 ;
int V_19 ;
F_132 ( V_2 ) ;
if ( V_2 -> V_70 != - 1 ) {
V_2 -> V_4 = V_2 -> V_70 ;
V_2 -> V_70 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_174 )
return 0 ;
}
F_134 (request, &ring->request_list, list) {
int V_3 ;
if ( V_176 -> V_6 == - 1 )
continue;
V_3 = V_176 -> V_6 - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
if ( V_3 >= V_174 ) {
V_105 = V_176 -> V_105 ;
break;
}
V_176 -> V_6 = - 1 ;
}
if ( V_105 == 0 )
return - V_152 ;
V_19 = F_130 ( V_2 , V_105 ) ;
if ( V_19 )
return V_19 ;
if ( F_70 ( V_2 -> V_70 == - 1 ) )
return - V_152 ;
V_2 -> V_4 = V_2 -> V_70 ;
V_2 -> V_70 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_70 ( V_2 -> V_3 < V_174 ) )
return - V_152 ;
return 0 ;
}
static int F_135 ( struct V_1 * V_2 , int V_174 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_12 ;
unsigned long V_177 ;
int V_19 ;
V_19 = F_133 ( V_2 , V_174 ) ;
if ( V_19 != - V_152 )
return V_19 ;
F_2 ( V_2 ) ;
F_136 ( V_2 ) ;
V_177 = V_178 + 60 * V_179 ;
do {
V_2 -> V_4 = F_33 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_174 ) {
F_137 ( V_2 ) ;
return 0 ;
}
if ( V_11 -> V_180 -> V_181 ) {
struct V_182 * V_183 = V_11 -> V_180 -> V_181 -> V_184 ;
if ( V_183 -> V_185 )
V_183 -> V_185 -> V_186 |= V_187 ;
}
F_138 ( 1 ) ;
V_19 = F_139 ( & V_10 -> V_13 ,
V_10 -> V_188 . V_189 ) ;
if ( V_19 )
return V_19 ;
} while ( ! F_140 ( V_178 , V_177 ) );
F_137 ( V_2 ) ;
return - V_190 ;
}
static int F_141 ( struct V_1 * V_2 )
{
T_3 T_4 * V_191 ;
int V_192 = V_2 -> V_8 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_192 ) {
int V_19 = F_135 ( V_2 , V_192 ) ;
if ( V_19 )
return V_19 ;
}
V_191 = V_2 -> V_165 + V_2 -> V_6 ;
V_192 /= 4 ;
while ( V_192 -- )
F_142 ( V_25 , V_191 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 )
{
T_1 V_105 ;
int V_19 ;
if ( V_2 -> V_94 ) {
V_19 = F_143 ( V_2 , NULL ) ;
if ( V_19 )
return V_19 ;
}
if ( F_144 ( & V_2 -> V_161 ) )
return 0 ;
V_105 = F_145 ( V_2 -> V_161 . V_193 ,
struct V_175 ,
V_194 ) -> V_105 ;
return F_131 ( V_2 , V_105 ) ;
}
static int
F_146 ( struct V_1 * V_2 )
{
if ( V_2 -> V_94 )
return 0 ;
if ( V_2 -> V_172 == NULL ) {
struct V_175 * V_176 ;
V_176 = F_147 ( sizeof( * V_176 ) , V_195 ) ;
if ( V_176 == NULL )
return - V_72 ;
V_2 -> V_172 = V_176 ;
}
return F_148 ( V_2 -> V_11 , & V_2 -> V_94 ) ;
}
static int F_149 ( struct V_1 * V_2 ,
int V_196 )
{
int V_19 ;
if ( F_150 ( V_2 -> V_6 + V_196 > V_2 -> V_171 ) ) {
V_19 = F_141 ( V_2 ) ;
if ( F_150 ( V_19 ) )
return V_19 ;
}
if ( F_150 ( V_2 -> V_3 < V_196 ) ) {
V_19 = F_135 ( V_2 , V_196 ) ;
if ( F_150 ( V_19 ) )
return V_19 ;
}
V_2 -> V_3 -= V_196 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 ,
int V_197 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
int V_19 ;
V_19 = F_139 ( & V_10 -> V_13 ,
V_10 -> V_188 . V_189 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_146 ( V_2 ) ;
if ( V_19 )
return V_19 ;
return F_149 ( V_2 , V_197 * sizeof( T_3 ) ) ;
}
void F_151 ( struct V_1 * V_2 , T_1 V_105 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
F_119 ( V_2 -> V_94 ) ;
if ( F_22 ( V_2 -> V_11 ) -> V_53 >= 6 ) {
F_26 ( F_152 ( V_2 -> V_54 ) , 0 ) ;
F_26 ( F_153 ( V_2 -> V_54 ) , 0 ) ;
if ( F_154 ( V_2 -> V_11 ) )
F_26 ( F_155 ( V_2 -> V_54 ) , 0 ) ;
}
V_2 -> V_198 ( V_2 , V_105 ) ;
V_2 -> V_71 . V_105 = V_105 ;
}
static void F_156 ( struct V_1 * V_2 ,
T_1 V_47 )
{
T_2 * V_10 = V_2 -> V_11 -> V_12 ;
F_26 ( V_199 ,
F_55 ( V_200 ) ) ;
F_157 ( V_201 , 0x0 ) ;
if ( F_41 ( ( F_24 ( V_199 ) &
V_202 ) == 0 ,
50 ) )
F_38 ( L_13 ) ;
F_20 ( V_2 , V_47 ) ;
F_88 ( F_158 ( V_2 -> V_54 ) ) ;
F_26 ( V_199 ,
F_57 ( V_200 ) ) ;
}
static int F_159 ( struct V_1 * V_2 ,
T_1 V_203 , T_1 V_204 )
{
T_3 V_18 ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
V_18 = V_205 ;
if ( F_22 ( V_2 -> V_11 ) -> V_53 >= 8 )
V_18 += 1 ;
if ( V_203 & V_206 )
V_18 |= V_207 | V_208 |
V_209 | V_210 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_211 | V_212 ) ;
if ( F_22 ( V_2 -> V_11 ) -> V_53 >= 8 ) {
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
F_160 ( struct V_1 * V_2 ,
T_1 V_140 , T_1 V_146 ,
unsigned V_38 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 ;
bool V_213 = V_10 -> V_188 . V_214 != NULL &&
! ( V_38 & V_144 ) ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 , V_215 | ( V_213 << 8 ) ) ;
F_6 ( V_2 , V_140 ) ;
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_161 ( struct V_1 * V_2 ,
T_1 V_140 , T_1 V_146 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_142 | V_216 |
( V_38 & V_144 ? 0 : V_217 ) ) ;
F_6 ( V_2 , V_140 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int
F_162 ( struct V_1 * V_2 ,
T_1 V_140 , T_1 V_146 ,
unsigned V_38 )
{
int V_19 ;
V_19 = F_5 ( V_2 , 2 ) ;
if ( V_19 )
return V_19 ;
F_6 ( V_2 ,
V_142 |
( V_38 & V_144 ? 0 : V_145 ) ) ;
F_6 ( V_2 , V_140 ) ;
F_7 ( V_2 ) ;
return 0 ;
}
static int F_163 ( struct V_1 * V_2 ,
T_1 V_203 , T_1 V_204 )
{
struct V_26 * V_11 = V_2 -> V_11 ;
T_3 V_18 ;
int V_19 ;
V_19 = F_5 ( V_2 , 4 ) ;
if ( V_19 )
return V_19 ;
V_18 = V_205 ;
if ( F_22 ( V_2 -> V_11 ) -> V_53 >= 8 )
V_18 += 1 ;
if ( V_203 & V_21 )
V_18 |= V_207 | V_209 |
V_210 ;
F_6 ( V_2 , V_18 ) ;
F_6 ( V_2 , V_211 | V_212 ) ;
if ( F_22 ( V_2 -> V_11 ) -> V_53 >= 8 ) {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , 0 ) ;
} else {
F_6 ( V_2 , 0 ) ;
F_6 ( V_2 , V_25 ) ;
}
F_7 ( V_2 ) ;
if ( F_56 ( V_11 ) && V_204 )
return F_15 ( V_2 , V_218 ) ;
return 0 ;
}
int F_164 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_126 ] ;
V_2 -> V_62 = L_14 ;
V_2 -> V_114 = V_126 ;
V_2 -> V_54 = V_219 ;
if ( F_22 ( V_11 ) -> V_53 >= 6 ) {
V_2 -> V_220 = F_66 ;
V_2 -> V_204 = F_17 ;
if ( F_22 ( V_11 ) -> V_53 == 6 )
V_2 -> V_204 = F_13 ;
if ( F_22 ( V_11 ) -> V_53 >= 8 ) {
V_2 -> V_204 = F_18 ;
V_2 -> V_221 = F_105 ;
V_2 -> V_222 = F_107 ;
} else {
V_2 -> V_221 = F_99 ;
V_2 -> V_222 = F_100 ;
}
V_2 -> V_122 = V_223 ;
V_2 -> V_224 = F_74 ;
V_2 -> V_198 = F_77 ;
V_2 -> V_225 = F_69 ;
V_2 -> V_113 [ V_126 ] = V_115 ;
V_2 -> V_113 [ V_130 ] = V_226 ;
V_2 -> V_113 [ V_128 ] = V_227 ;
V_2 -> V_113 [ V_132 ] = V_228 ;
V_2 -> V_99 [ V_126 ] = V_100 ;
V_2 -> V_99 [ V_130 ] = V_229 ;
V_2 -> V_99 [ V_128 ] = V_230 ;
V_2 -> V_99 [ V_132 ] = V_231 ;
} else if ( F_10 ( V_11 ) ) {
V_2 -> V_220 = F_72 ;
V_2 -> V_204 = F_8 ;
V_2 -> V_224 = F_79 ;
V_2 -> V_198 = F_80 ;
V_2 -> V_221 = F_81 ;
V_2 -> V_222 = F_85 ;
V_2 -> V_122 = V_223 |
V_232 ;
} else {
V_2 -> V_220 = F_98 ;
if ( F_22 ( V_11 ) -> V_53 < 4 )
V_2 -> V_204 = F_4 ;
else
V_2 -> V_204 = F_8 ;
V_2 -> V_224 = F_76 ;
V_2 -> V_198 = F_77 ;
if ( F_165 ( V_11 ) ) {
V_2 -> V_221 = F_90 ;
V_2 -> V_222 = F_93 ;
} else {
V_2 -> V_221 = F_87 ;
V_2 -> V_222 = F_89 ;
}
V_2 -> V_122 = V_233 ;
}
V_2 -> V_15 = F_19 ;
if ( F_166 ( V_11 ) )
V_2 -> V_234 = F_161 ;
else if ( F_167 ( V_11 ) )
V_2 -> V_234 = F_160 ;
else if ( F_22 ( V_11 ) -> V_53 >= 6 )
V_2 -> V_234 = F_162 ;
else if ( F_22 ( V_11 ) -> V_53 >= 4 )
V_2 -> V_234 = F_108 ;
else if ( F_124 ( V_11 ) || F_125 ( V_11 ) )
V_2 -> V_234 = F_109 ;
else
V_2 -> V_234 = F_111 ;
V_2 -> V_169 = F_54 ;
V_2 -> V_173 = F_62 ;
if ( F_168 ( V_11 ) ) {
struct V_60 * V_61 ;
int V_19 ;
V_61 = F_46 ( V_11 , V_151 ) ;
if ( V_61 == NULL ) {
F_38 ( L_15 ) ;
return - V_72 ;
}
V_19 = F_48 ( V_61 , 0 , true , false ) ;
if ( V_19 != 0 ) {
F_53 ( & V_61 -> V_80 ) ;
F_38 ( L_16 ) ;
return V_19 ;
}
V_2 -> V_32 . V_61 = V_61 ;
V_2 -> V_32 . V_33 = F_40 ( V_61 ) ;
}
return F_116 ( V_11 , V_2 ) ;
}
int F_169 ( struct V_26 * V_11 , T_5 V_235 , T_1 V_8 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_126 ] ;
int V_19 ;
V_2 -> V_62 = L_14 ;
V_2 -> V_114 = V_126 ;
V_2 -> V_54 = V_219 ;
if ( F_22 ( V_11 ) -> V_53 >= 6 ) {
return - V_236 ;
}
V_2 -> V_220 = F_98 ;
if ( F_22 ( V_11 ) -> V_53 < 4 )
V_2 -> V_204 = F_4 ;
else
V_2 -> V_204 = F_8 ;
V_2 -> V_224 = F_76 ;
V_2 -> V_198 = F_77 ;
if ( F_165 ( V_11 ) ) {
V_2 -> V_221 = F_90 ;
V_2 -> V_222 = F_93 ;
} else {
V_2 -> V_221 = F_87 ;
V_2 -> V_222 = F_89 ;
}
V_2 -> V_122 = V_233 ;
V_2 -> V_15 = F_19 ;
if ( F_22 ( V_11 ) -> V_53 >= 4 )
V_2 -> V_234 = F_108 ;
else if ( F_124 ( V_11 ) || F_125 ( V_11 ) )
V_2 -> V_234 = F_109 ;
else
V_2 -> V_234 = F_111 ;
V_2 -> V_169 = F_54 ;
V_2 -> V_173 = F_62 ;
V_2 -> V_11 = V_11 ;
F_117 ( & V_2 -> V_160 ) ;
F_117 ( & V_2 -> V_161 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_171 = V_2 -> V_8 ;
if ( F_124 ( V_2 -> V_11 ) || F_125 ( V_2 -> V_11 ) )
V_2 -> V_171 -= 128 ;
V_2 -> V_165 = F_123 ( V_235 , V_8 ) ;
if ( V_2 -> V_165 == NULL ) {
F_38 ( L_17
L_18 ) ;
return - V_72 ;
}
if ( ! F_29 ( V_11 ) ) {
V_19 = F_114 ( V_2 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
int F_170 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_130 ] ;
V_2 -> V_62 = L_19 ;
V_2 -> V_114 = V_130 ;
V_2 -> V_15 = F_19 ;
if ( F_22 ( V_11 ) -> V_53 >= 6 ) {
V_2 -> V_54 = V_237 ;
if ( F_58 ( V_11 ) )
V_2 -> V_15 = F_156 ;
V_2 -> V_204 = F_159 ;
V_2 -> V_220 = F_66 ;
V_2 -> V_224 = F_74 ;
V_2 -> V_198 = F_77 ;
if ( F_22 ( V_11 ) -> V_53 >= 8 ) {
V_2 -> V_122 =
V_223 << V_238 ;
V_2 -> V_221 = F_105 ;
V_2 -> V_222 = F_107 ;
V_2 -> V_234 =
F_160 ;
} else {
V_2 -> V_122 = V_239 ;
V_2 -> V_221 = F_99 ;
V_2 -> V_222 = F_100 ;
V_2 -> V_234 =
F_162 ;
}
V_2 -> V_225 = F_69 ;
V_2 -> V_113 [ V_126 ] = V_240 ;
V_2 -> V_113 [ V_130 ] = V_115 ;
V_2 -> V_113 [ V_128 ] = V_241 ;
V_2 -> V_113 [ V_132 ] = V_242 ;
V_2 -> V_99 [ V_126 ] = V_243 ;
V_2 -> V_99 [ V_130 ] = V_100 ;
V_2 -> V_99 [ V_128 ] = V_244 ;
V_2 -> V_99 [ V_132 ] = V_245 ;
} else {
V_2 -> V_54 = V_246 ;
V_2 -> V_204 = F_97 ;
V_2 -> V_220 = F_98 ;
V_2 -> V_224 = F_76 ;
V_2 -> V_198 = F_77 ;
if ( F_10 ( V_11 ) ) {
V_2 -> V_122 = V_247 ;
V_2 -> V_221 = F_81 ;
V_2 -> V_222 = F_85 ;
} else {
V_2 -> V_122 = V_248 ;
V_2 -> V_221 = F_87 ;
V_2 -> V_222 = F_89 ;
}
V_2 -> V_234 = F_108 ;
}
V_2 -> V_169 = F_27 ;
return F_116 ( V_11 , V_2 ) ;
}
int F_171 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_128 ] ;
V_2 -> V_62 = L_20 ;
V_2 -> V_114 = V_128 ;
V_2 -> V_54 = V_249 ;
V_2 -> V_15 = F_19 ;
V_2 -> V_204 = F_163 ;
V_2 -> V_220 = F_66 ;
V_2 -> V_224 = F_74 ;
V_2 -> V_198 = F_77 ;
if ( F_22 ( V_11 ) -> V_53 >= 8 ) {
V_2 -> V_122 =
V_223 << V_250 ;
V_2 -> V_221 = F_105 ;
V_2 -> V_222 = F_107 ;
V_2 -> V_234 = F_160 ;
} else {
V_2 -> V_122 = V_251 ;
V_2 -> V_221 = F_99 ;
V_2 -> V_222 = F_100 ;
V_2 -> V_234 = F_162 ;
}
V_2 -> V_225 = F_69 ;
V_2 -> V_113 [ V_126 ] = V_252 ;
V_2 -> V_113 [ V_130 ] = V_253 ;
V_2 -> V_113 [ V_128 ] = V_115 ;
V_2 -> V_113 [ V_132 ] = V_254 ;
V_2 -> V_99 [ V_126 ] = V_255 ;
V_2 -> V_99 [ V_130 ] = V_256 ;
V_2 -> V_99 [ V_128 ] = V_100 ;
V_2 -> V_99 [ V_132 ] = V_257 ;
V_2 -> V_169 = F_27 ;
return F_116 ( V_11 , V_2 ) ;
}
int F_172 ( struct V_26 * V_11 )
{
T_2 * V_10 = V_11 -> V_12 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_132 ] ;
V_2 -> V_62 = L_21 ;
V_2 -> V_114 = V_132 ;
V_2 -> V_54 = V_258 ;
V_2 -> V_15 = F_19 ;
V_2 -> V_204 = F_163 ;
V_2 -> V_220 = F_66 ;
V_2 -> V_224 = F_74 ;
V_2 -> V_198 = F_77 ;
if ( F_22 ( V_11 ) -> V_53 >= 8 ) {
V_2 -> V_122 =
V_223 << V_259 ;
V_2 -> V_221 = F_105 ;
V_2 -> V_222 = F_107 ;
V_2 -> V_234 = F_160 ;
} else {
V_2 -> V_122 = V_260 ;
V_2 -> V_221 = F_101 ;
V_2 -> V_222 = F_103 ;
V_2 -> V_234 = F_162 ;
}
V_2 -> V_225 = F_69 ;
V_2 -> V_113 [ V_126 ] = V_261 ;
V_2 -> V_113 [ V_130 ] = V_262 ;
V_2 -> V_113 [ V_128 ] = V_263 ;
V_2 -> V_113 [ V_132 ] = V_115 ;
V_2 -> V_99 [ V_126 ] = V_264 ;
V_2 -> V_99 [ V_130 ] = V_265 ;
V_2 -> V_99 [ V_128 ] = V_266 ;
V_2 -> V_99 [ V_132 ] = V_100 ;
V_2 -> V_169 = F_27 ;
return F_116 ( V_11 , V_2 ) ;
}
int
F_173 ( struct V_1 * V_2 )
{
int V_19 ;
if ( ! V_2 -> V_267 )
return 0 ;
V_19 = V_2 -> V_204 ( V_2 , 0 , V_206 ) ;
if ( V_19 )
return V_19 ;
F_174 ( V_2 , 0 , V_206 ) ;
V_2 -> V_267 = false ;
return 0 ;
}
int
F_175 ( struct V_1 * V_2 )
{
T_3 V_17 ;
int V_19 ;
V_17 = 0 ;
if ( V_2 -> V_267 )
V_17 = V_206 ;
V_19 = V_2 -> V_204 ( V_2 , V_206 , V_17 ) ;
if ( V_19 )
return V_19 ;
F_174 ( V_2 , V_206 , V_17 ) ;
V_2 -> V_267 = false ;
return 0 ;
}
