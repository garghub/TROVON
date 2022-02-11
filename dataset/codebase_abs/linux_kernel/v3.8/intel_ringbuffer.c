static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 & V_5 ) - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
return V_3 ;
}
static int
F_2 ( struct V_1 * V_2 ,
T_1 V_9 ,
T_1 V_10 )
{
T_1 V_11 ;
int V_12 ;
V_11 = V_13 ;
if ( ( ( V_9 | V_10 ) & V_14 ) == 0 )
V_11 |= V_15 ;
if ( V_9 & V_16 )
V_11 |= V_17 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 ,
T_1 V_9 ,
T_1 V_10 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_1 V_11 ;
int V_12 ;
V_11 = V_13 | V_15 ;
if ( ( V_9 | V_10 ) & V_14 )
V_11 &= ~ V_15 ;
if ( V_9 & V_21 )
V_11 |= V_22 ;
if ( V_9 & V_23 &&
( F_7 ( V_20 ) || F_8 ( V_20 ) ) )
V_11 |= V_24 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_12 ;
V_12 = F_3 ( V_2 , 6 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 5 ) ) ;
F_4 ( V_2 , V_30 |
V_31 ) ;
F_4 ( V_2 , V_28 | V_32 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
V_12 = F_3 ( V_2 , 6 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 5 ) ) ;
F_4 ( V_2 , V_33 ) ;
F_4 ( V_2 , V_28 | V_32 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 ,
T_1 V_9 , T_1 V_10 )
{
T_1 V_34 = 0 ;
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_12 ;
V_12 = F_9 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( V_10 ) {
V_34 |= V_35 ;
V_34 |= V_36 ;
V_34 |= V_30 ;
}
if ( V_9 ) {
V_34 |= V_37 ;
V_34 |= V_38 ;
V_34 |= V_39 ;
V_34 |= V_40 ;
V_34 |= V_41 ;
V_34 |= V_42 ;
V_34 |= V_33 | V_30 ;
}
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 4 ) ) ;
F_4 ( V_2 , V_34 ) ;
F_4 ( V_2 , V_28 | V_32 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 4 ) ) ;
F_4 ( V_2 , V_30 |
V_31 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 ,
T_1 V_9 , T_1 V_10 )
{
T_1 V_34 = 0 ;
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_12 ;
V_34 |= V_30 ;
if ( V_10 ) {
V_34 |= V_35 ;
V_34 |= V_36 ;
}
if ( V_9 ) {
V_34 |= V_37 ;
V_34 |= V_38 ;
V_34 |= V_39 ;
V_34 |= V_40 ;
V_34 |= V_41 ;
V_34 |= V_42 ;
V_34 |= V_33 ;
F_12 ( V_2 ) ;
}
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 4 ) ) ;
F_4 ( V_2 , V_34 ) ;
F_4 ( V_2 , V_28 | V_32 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_43 )
{
T_2 * V_44 = V_2 -> V_20 -> V_45 ;
F_15 ( V_2 , V_43 ) ;
}
T_1 F_16 ( struct V_1 * V_2 )
{
T_2 * V_44 = V_2 -> V_20 -> V_45 ;
T_1 V_46 = F_17 ( V_2 -> V_20 ) -> V_47 >= 4 ?
F_18 ( V_2 -> V_48 ) : V_49 ;
return F_19 ( V_46 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
struct V_50 * V_51 = V_2 -> V_51 ;
int V_12 = 0 ;
T_1 V_4 ;
if ( F_21 ( V_20 ) )
F_22 ( V_44 ) ;
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
V_2 -> V_52 ( V_2 , 0 ) ;
V_4 = F_25 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_26 ( L_1
L_2 ,
V_2 -> V_53 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
F_24 ( V_2 , 0 ) ;
if ( F_25 ( V_2 ) & V_5 ) {
F_30 ( L_3
L_2 ,
V_2 -> V_53 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
}
}
F_31 ( V_2 , V_51 -> V_29 ) ;
F_23 ( V_2 ,
( ( V_2 -> V_8 - V_54 ) & V_55 )
| V_56 ) ;
if ( F_32 ( ( F_27 ( V_2 ) & V_56 ) != 0 &&
F_29 ( V_2 ) == V_51 -> V_29 &&
( F_25 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_30 ( L_4
L_2 ,
V_2 -> V_53 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
V_12 = - V_57 ;
goto V_58;
}
if ( ! F_33 ( V_2 -> V_20 , V_59 ) )
F_34 ( V_2 -> V_20 ) ;
else {
V_2 -> V_4 = F_25 ( V_2 ) ;
V_2 -> V_6 = F_28 ( V_2 ) & V_60 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_61 = - 1 ;
}
V_58:
if ( F_21 ( V_20 ) )
F_35 ( V_44 ) ;
return V_12 ;
}
static int
F_36 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_50 * V_51 ;
int V_12 ;
if ( V_2 -> V_27 )
return 0 ;
V_26 = F_37 ( sizeof( * V_26 ) , V_62 ) ;
if ( ! V_26 )
return - V_63 ;
V_51 = F_38 ( V_2 -> V_20 , 4096 ) ;
if ( V_51 == NULL ) {
F_30 ( L_5 ) ;
V_12 = - V_63 ;
goto V_64;
}
F_39 ( V_51 , V_65 ) ;
V_12 = F_40 ( V_51 , 4096 , true , false ) ;
if ( V_12 )
goto V_66;
V_26 -> V_29 = V_51 -> V_29 ;
V_26 -> V_67 = F_41 ( F_42 ( V_51 -> V_68 -> V_69 ) ) ;
if ( V_26 -> V_67 == NULL )
goto V_70;
V_26 -> V_51 = V_51 ;
V_2 -> V_27 = V_26 ;
return 0 ;
V_70:
F_43 ( V_51 ) ;
V_66:
F_44 ( & V_51 -> V_71 ) ;
V_64:
F_45 ( V_26 ) ;
return V_12 ;
}
static void
F_46 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
struct V_50 * V_51 ;
if ( ! V_2 -> V_27 )
return;
V_51 = V_26 -> V_51 ;
F_47 ( F_42 ( V_51 -> V_68 -> V_69 ) ) ;
F_43 ( V_51 ) ;
F_44 ( & V_51 -> V_71 ) ;
F_45 ( V_26 ) ;
V_2 -> V_27 = NULL ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_72 * V_44 = V_20 -> V_45 ;
int V_12 = F_20 ( V_2 ) ;
if ( F_17 ( V_20 ) -> V_47 > 3 )
F_49 ( V_73 , F_50 ( V_74 ) ) ;
if ( F_17 ( V_20 ) -> V_47 >= 6 )
F_49 ( V_73 , F_50 ( V_75 ) ) ;
if ( F_17 ( V_20 ) -> V_47 == 6 )
F_49 ( V_76 ,
F_50 ( V_77 ) ) ;
if ( F_51 ( V_20 ) )
F_49 ( V_78 ,
F_52 ( V_77 ) |
F_50 ( V_79 ) ) ;
if ( F_17 ( V_20 ) -> V_47 >= 5 ) {
V_12 = F_36 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
if ( F_53 ( V_20 ) ) {
F_49 ( V_80 ,
F_52 ( V_81 ) ) ;
V_2 -> V_82 =
! ! ( F_19 ( V_76 ) & V_77 ) ;
}
if ( F_17 ( V_20 ) -> V_47 >= 6 )
F_49 ( V_83 , F_50 ( V_84 ) ) ;
if ( F_54 ( V_20 ) )
F_55 ( V_2 , ~ V_85 ) ;
return V_12 ;
}
static void F_56 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
if ( ! V_2 -> V_27 )
return;
if ( F_57 ( V_20 ) )
F_44 ( F_58 ( V_2 -> V_27 ) ) ;
F_46 ( V_2 ) ;
}
static void
F_59 ( struct V_1 * V_2 ,
T_1 V_86 )
{
F_4 ( V_2 , F_60 ( 1 ) ) ;
F_4 ( V_2 , V_86 ) ;
F_4 ( V_2 , V_2 -> V_87 ) ;
}
static int
F_61 ( struct V_1 * V_2 )
{
T_1 V_88 ;
T_1 V_89 ;
int V_12 ;
V_12 = F_3 ( V_2 , 10 ) ;
if ( V_12 )
return V_12 ;
V_88 = V_2 -> V_90 [ 0 ] ;
V_89 = V_2 -> V_90 [ 1 ] ;
F_59 ( V_2 , V_88 ) ;
F_59 ( V_2 , V_89 ) ;
F_4 ( V_2 , V_91 ) ;
F_4 ( V_2 , V_92 << V_93 ) ;
F_4 ( V_2 , V_2 -> V_87 ) ;
F_4 ( V_2 , V_94 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_62 ( struct V_1 * V_95 ,
struct V_1 * V_96 ,
T_1 V_97 )
{
int V_12 ;
T_1 V_98 = V_99 |
V_100 |
V_101 ;
V_97 -= 1 ;
F_63 ( V_96 -> V_102 [ V_95 -> V_103 ] ==
V_104 ) ;
V_12 = F_3 ( V_95 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_95 ,
V_98 | V_96 -> V_102 [ V_95 -> V_103 ] ) ;
F_4 ( V_95 , V_97 ) ;
F_4 ( V_95 , 0 ) ;
F_4 ( V_95 , V_18 ) ;
F_5 ( V_95 ) ;
return 0 ;
}
static int
F_64 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_12 ;
V_12 = F_3 ( V_2 , 32 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 4 ) | V_33 |
V_105 |
V_39 ) ;
F_4 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_4 ( V_2 , V_2 -> V_87 ) ;
F_4 ( V_2 , 0 ) ;
F_65 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_65 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_65 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_65 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_65 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_65 ( V_2 , V_28 ) ;
F_4 ( V_2 , F_10 ( 4 ) | V_33 |
V_105 |
V_39 |
V_106 ) ;
F_4 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_4 ( V_2 , V_2 -> V_87 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static T_1
F_66 ( struct V_1 * V_2 , bool V_107 )
{
if ( ! V_107 )
F_16 ( V_2 ) ;
return F_67 ( V_2 , V_92 ) ;
}
static T_1
F_68 ( struct V_1 * V_2 , bool V_107 )
{
return F_67 ( V_2 , V_92 ) ;
}
static T_1
F_69 ( struct V_1 * V_2 , bool V_107 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
return V_26 -> V_67 [ 0 ] ;
}
static bool
F_70 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
if ( ! V_20 -> V_108 )
return false ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
V_44 -> V_111 &= ~ V_2 -> V_112 ;
F_49 ( V_113 , V_44 -> V_111 ) ;
F_72 ( V_113 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
return true ;
}
static void
F_74 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( -- V_2 -> V_110 == 0 ) {
V_44 -> V_111 |= V_2 -> V_112 ;
F_49 ( V_113 , V_44 -> V_111 ) ;
F_72 ( V_113 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
}
static bool
F_75 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
if ( ! V_20 -> V_108 )
return false ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
V_44 -> V_114 &= ~ V_2 -> V_112 ;
F_49 ( V_115 , V_44 -> V_114 ) ;
F_72 ( V_115 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
return true ;
}
static void
F_76 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( -- V_2 -> V_110 == 0 ) {
V_44 -> V_114 |= V_2 -> V_112 ;
F_49 ( V_115 , V_44 -> V_114 ) ;
F_72 ( V_115 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
}
static bool
F_77 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
if ( ! V_20 -> V_108 )
return false ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
V_44 -> V_114 &= ~ V_2 -> V_112 ;
F_78 ( V_115 , V_44 -> V_114 ) ;
F_79 ( V_115 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( -- V_2 -> V_110 == 0 ) {
V_44 -> V_114 |= V_2 -> V_112 ;
F_78 ( V_115 , V_44 -> V_114 ) ;
F_79 ( V_115 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
}
void F_81 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_2 -> V_20 -> V_45 ;
T_1 V_116 = 0 ;
if ( F_51 ( V_20 ) ) {
switch ( V_2 -> V_103 ) {
case V_117 :
V_116 = V_118 ;
break;
case V_119 :
V_116 = V_120 ;
break;
case V_121 :
V_116 = V_122 ;
break;
}
} else if ( F_53 ( V_2 -> V_20 ) ) {
V_116 = F_82 ( V_2 -> V_48 ) ;
} else {
V_116 = F_83 ( V_2 -> V_48 ) ;
}
F_49 ( V_116 , ( T_1 ) V_2 -> V_123 . V_124 ) ;
F_72 ( V_116 ) ;
}
static int
F_84 ( struct V_1 * V_2 ,
T_1 V_9 ,
T_1 V_10 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_13 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_85 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_91 ) ;
F_4 ( V_2 , V_92 << V_93 ) ;
F_4 ( V_2 , V_2 -> V_87 ) ;
F_4 ( V_2 , V_94 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static bool
F_86 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
if ( ! V_20 -> V_108 )
return false ;
F_22 ( V_44 ) ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
if ( F_54 ( V_20 ) && V_2 -> V_103 == V_117 )
F_55 ( V_2 , ~ ( V_2 -> V_112 |
V_85 ) ) ;
else
F_55 ( V_2 , ~ V_2 -> V_112 ) ;
V_44 -> V_111 &= ~ V_2 -> V_112 ;
F_49 ( V_113 , V_44 -> V_111 ) ;
F_72 ( V_113 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
return true ;
}
static void
F_87 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_44 = V_20 -> V_45 ;
unsigned long V_34 ;
F_71 ( & V_44 -> V_109 , V_34 ) ;
if ( -- V_2 -> V_110 == 0 ) {
if ( F_54 ( V_20 ) && V_2 -> V_103 == V_117 )
F_55 ( V_2 , ~ V_85 ) ;
else
F_55 ( V_2 , ~ 0 ) ;
V_44 -> V_111 |= V_2 -> V_112 ;
F_49 ( V_113 , V_44 -> V_111 ) ;
F_72 ( V_113 ) ;
}
F_73 ( & V_44 -> V_109 , V_34 ) ;
F_35 ( V_44 ) ;
}
static int
F_88 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_126 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_127 |
V_128 |
( V_34 & V_129 ? 0 : V_130 ) ) ;
F_4 ( V_2 , V_125 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_89 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_131 ,
unsigned V_34 )
{
int V_12 ;
if ( V_34 & V_132 ) {
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_133 ) ;
F_4 ( V_2 , V_125 | ( V_34 & V_129 ? 0 : V_134 ) ) ;
F_4 ( V_2 , V_125 + V_131 - 8 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
} else {
struct V_50 * V_51 = V_2 -> V_27 ;
T_1 V_135 = V_51 -> V_29 ;
if ( V_131 > V_136 )
return - V_137 ;
V_12 = F_3 ( V_2 , 9 + 3 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_138 |
V_139 |
V_140 ) ;
F_4 ( V_2 , V_141 | V_142 | 4096 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , ( F_90 ( V_131 , 4096 ) << 16 ) | 1024 ) ;
F_4 ( V_2 , V_135 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 4096 ) ;
F_4 ( V_2 , V_125 ) ;
F_4 ( V_2 , V_13 ) ;
F_4 ( V_2 , V_133 ) ;
F_4 ( V_2 , V_135 | ( V_34 & V_129 ? 0 : V_134 ) ) ;
F_4 ( V_2 , V_135 + V_131 - 8 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static int
F_91 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_131 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_127 | V_128 ) ;
F_4 ( V_2 , V_125 | ( V_34 & V_129 ? 0 : V_134 ) ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
V_51 = V_2 -> V_123 . V_51 ;
if ( V_51 == NULL )
return;
F_47 ( F_42 ( V_51 -> V_68 -> V_69 ) ) ;
F_43 ( V_51 ) ;
F_44 ( & V_51 -> V_71 ) ;
V_2 -> V_123 . V_51 = NULL ;
}
static int F_93 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_50 * V_51 ;
int V_12 ;
V_51 = F_38 ( V_20 , 4096 ) ;
if ( V_51 == NULL ) {
F_30 ( L_6 ) ;
V_12 = - V_63 ;
goto V_64;
}
F_39 ( V_51 , V_65 ) ;
V_12 = F_40 ( V_51 , 4096 , true , false ) ;
if ( V_12 != 0 ) {
goto V_66;
}
V_2 -> V_123 . V_124 = V_51 -> V_29 ;
V_2 -> V_123 . V_143 = F_41 ( F_42 ( V_51 -> V_68 -> V_69 ) ) ;
if ( V_2 -> V_123 . V_143 == NULL ) {
V_12 = - V_63 ;
goto V_70;
}
V_2 -> V_123 . V_51 = V_51 ;
memset ( V_2 -> V_123 . V_143 , 0 , V_54 ) ;
F_81 ( V_2 ) ;
F_94 ( L_7 ,
V_2 -> V_53 , V_2 -> V_123 . V_124 ) ;
return 0 ;
V_70:
F_43 ( V_51 ) ;
V_66:
F_44 ( & V_51 -> V_71 ) ;
V_64:
return V_12 ;
}
static int F_95 ( struct V_1 * V_2 )
{
struct V_72 * V_44 = V_2 -> V_20 -> V_45 ;
T_1 V_144 ;
if ( ! V_44 -> V_145 ) {
V_44 -> V_145 =
F_96 ( V_2 -> V_20 , V_54 , V_54 ) ;
if ( ! V_44 -> V_145 )
return - V_63 ;
}
V_144 = V_44 -> V_145 -> V_146 ;
if ( F_17 ( V_2 -> V_20 ) -> V_47 >= 4 )
V_144 |= ( V_44 -> V_145 -> V_146 >> 28 ) & 0xf0 ;
F_49 ( V_147 , V_144 ) ;
V_2 -> V_123 . V_143 = V_44 -> V_145 -> V_148 ;
memset ( V_2 -> V_123 . V_143 , 0 , V_54 ) ;
return 0 ;
}
static int F_97 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 ;
struct V_72 * V_44 = V_20 -> V_45 ;
int V_12 ;
V_2 -> V_20 = V_20 ;
F_98 ( & V_2 -> V_149 ) ;
F_98 ( & V_2 -> V_150 ) ;
V_2 -> V_8 = 32 * V_54 ;
memset ( V_2 -> V_151 , 0 , sizeof( V_2 -> V_151 ) ) ;
F_99 ( & V_2 -> V_152 ) ;
if ( F_100 ( V_20 ) ) {
V_12 = F_93 ( V_2 ) ;
if ( V_12 )
return V_12 ;
} else {
F_101 ( V_2 -> V_103 != V_117 ) ;
V_12 = F_95 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
V_51 = F_38 ( V_20 , V_2 -> V_8 ) ;
if ( V_51 == NULL ) {
F_30 ( L_8 ) ;
V_12 = - V_63 ;
goto V_153;
}
V_2 -> V_51 = V_51 ;
V_12 = F_40 ( V_51 , V_54 , true , false ) ;
if ( V_12 )
goto V_66;
V_12 = F_102 ( V_51 , true ) ;
if ( V_12 )
goto V_70;
V_2 -> V_154 =
F_103 ( V_44 -> V_155 . V_156 -> V_157 + V_51 -> V_29 ,
V_2 -> V_8 ) ;
if ( V_2 -> V_154 == NULL ) {
F_30 ( L_9 ) ;
V_12 = - V_158 ;
goto V_70;
}
V_12 = V_2 -> V_159 ( V_2 ) ;
if ( V_12 )
goto V_160;
V_2 -> V_161 = V_2 -> V_8 ;
if ( F_104 ( V_2 -> V_20 ) || F_105 ( V_2 -> V_20 ) )
V_2 -> V_161 -= 128 ;
return 0 ;
V_160:
F_106 ( V_2 -> V_154 ) ;
V_70:
F_43 ( V_51 ) ;
V_66:
F_44 ( & V_51 -> V_71 ) ;
V_2 -> V_51 = NULL ;
V_153:
F_92 ( V_2 ) ;
return V_12 ;
}
void F_107 ( struct V_1 * V_2 )
{
struct V_72 * V_44 ;
int V_12 ;
if ( V_2 -> V_51 == NULL )
return;
V_44 = V_2 -> V_20 -> V_45 ;
V_12 = F_108 ( V_2 ) ;
if ( V_12 )
F_30 ( L_10 ,
V_2 -> V_53 , V_12 ) ;
F_23 ( V_2 , 0 ) ;
F_106 ( V_2 -> V_154 ) ;
F_43 ( V_2 -> V_51 ) ;
F_44 ( & V_2 -> V_51 -> V_71 ) ;
V_2 -> V_51 = NULL ;
if ( V_2 -> V_162 )
V_2 -> V_162 ( V_2 ) ;
F_92 ( V_2 ) ;
}
static int F_109 ( struct V_1 * V_2 , T_1 V_97 )
{
int V_12 ;
V_12 = F_110 ( V_2 , V_97 ) ;
if ( ! V_12 )
F_111 ( V_2 ) ;
return V_12 ;
}
static int F_112 ( struct V_1 * V_2 , int V_163 )
{
struct V_164 * V_165 ;
T_1 V_97 = 0 ;
int V_12 ;
F_111 ( V_2 ) ;
if ( V_2 -> V_61 != - 1 ) {
V_2 -> V_4 = V_2 -> V_61 ;
V_2 -> V_61 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_163 )
return 0 ;
}
F_113 (request, &ring->request_list, list) {
int V_3 ;
if ( V_165 -> V_6 == - 1 )
continue;
V_3 = V_165 -> V_6 - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
if ( V_3 >= V_163 ) {
V_97 = V_165 -> V_97 ;
break;
}
V_165 -> V_6 = - 1 ;
}
if ( V_97 == 0 )
return - V_137 ;
V_12 = F_109 ( V_2 , V_97 ) ;
if ( V_12 )
return V_12 ;
if ( F_63 ( V_2 -> V_61 == - 1 ) )
return - V_137 ;
V_2 -> V_4 = V_2 -> V_61 ;
V_2 -> V_61 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_63 ( V_2 -> V_3 < V_163 ) )
return - V_137 ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , int V_163 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_72 * V_44 = V_20 -> V_45 ;
unsigned long V_166 ;
int V_12 ;
V_12 = F_112 ( V_2 , V_163 ) ;
if ( V_12 != - V_137 )
return V_12 ;
F_115 ( V_2 ) ;
V_166 = V_167 + 60 * V_168 ;
do {
V_2 -> V_4 = F_25 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_163 ) {
F_116 ( V_2 ) ;
return 0 ;
}
if ( V_20 -> V_169 -> V_170 ) {
struct V_171 * V_172 = V_20 -> V_169 -> V_170 -> V_173 ;
if ( V_172 -> V_174 )
V_172 -> V_174 -> V_175 |= V_176 ;
}
F_117 ( 1 ) ;
V_12 = F_118 ( V_44 , V_44 -> V_155 . V_177 ) ;
if ( V_12 )
return V_12 ;
} while ( ! F_119 ( V_167 , V_166 ) );
F_116 ( V_2 ) ;
return - V_178 ;
}
static int F_120 ( struct V_1 * V_2 )
{
T_3 T_4 * V_179 ;
int V_180 = V_2 -> V_8 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_180 ) {
int V_12 = F_114 ( V_2 , V_180 ) ;
if ( V_12 )
return V_12 ;
}
V_179 = V_2 -> V_154 + V_2 -> V_6 ;
V_180 /= 4 ;
while ( V_180 -- )
F_121 ( V_18 , V_179 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 )
{
T_1 V_97 ;
int V_12 ;
if ( V_2 -> V_87 ) {
V_12 = F_122 ( V_2 , NULL , NULL ) ;
if ( V_12 )
return V_12 ;
}
if ( F_123 ( & V_2 -> V_150 ) )
return 0 ;
V_97 = F_124 ( V_2 -> V_150 . V_181 ,
struct V_164 ,
V_182 ) -> V_97 ;
return F_110 ( V_2 , V_97 ) ;
}
static int
F_125 ( struct V_1 * V_2 )
{
if ( V_2 -> V_87 )
return 0 ;
return F_126 ( V_2 -> V_20 , & V_2 -> V_87 ) ;
}
int F_3 ( struct V_1 * V_2 ,
int V_183 )
{
T_2 * V_44 = V_2 -> V_20 -> V_45 ;
int V_163 = 4 * V_183 ;
int V_12 ;
V_12 = F_118 ( V_44 , V_44 -> V_155 . V_177 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_125 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( F_127 ( V_2 -> V_6 + V_163 > V_2 -> V_161 ) ) {
V_12 = F_120 ( V_2 ) ;
if ( F_127 ( V_12 ) )
return V_12 ;
}
if ( F_127 ( V_2 -> V_3 < V_163 ) ) {
V_12 = F_114 ( V_2 , V_163 ) ;
if ( F_127 ( V_12 ) )
return V_12 ;
}
V_2 -> V_3 -= V_163 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_72 * V_44 = V_2 -> V_20 -> V_45 ;
V_2 -> V_6 &= V_2 -> V_8 - 1 ;
if ( V_44 -> V_184 & F_128 ( V_2 ) )
return;
V_2 -> V_52 ( V_2 , V_2 -> V_6 ) ;
}
static void F_129 ( struct V_1 * V_2 ,
T_1 V_43 )
{
T_2 * V_44 = V_2 -> V_20 -> V_45 ;
F_49 ( V_185 ,
F_50 ( V_186 ) ) ;
F_130 ( V_187 , 0x0 ) ;
if ( F_32 ( ( F_19 ( V_185 ) &
V_188 ) == 0 ,
50 ) )
F_30 ( L_11 ) ;
F_15 ( V_2 , V_43 ) ;
F_72 ( F_131 ( V_2 -> V_48 ) ) ;
F_49 ( V_185 ,
F_52 ( V_186 ) ) ;
}
static int F_132 ( struct V_1 * V_2 ,
T_1 V_189 , T_1 V_190 )
{
T_3 V_11 ;
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
V_11 = V_191 ;
if ( V_189 & V_192 )
V_11 |= V_193 | V_194 |
V_195 | V_196 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_197 | V_198 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_133 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_131 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_127 | V_199 |
( V_34 & V_129 ? 0 : V_200 ) ) ;
F_4 ( V_2 , V_125 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_134 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_131 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_127 |
( V_34 & V_129 ? 0 : V_130 ) ) ;
F_4 ( V_2 , V_125 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_135 ( struct V_1 * V_2 ,
T_1 V_189 , T_1 V_190 )
{
T_3 V_11 ;
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
V_11 = V_191 ;
if ( V_189 & V_14 )
V_11 |= V_193 | V_195 |
V_196 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_197 | V_198 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_136 ( struct V_19 * V_20 )
{
T_2 * V_44 = V_20 -> V_45 ;
struct V_1 * V_2 = & V_44 -> V_2 [ V_117 ] ;
V_2 -> V_53 = L_12 ;
V_2 -> V_103 = V_117 ;
V_2 -> V_48 = V_201 ;
if ( F_17 ( V_20 ) -> V_47 >= 6 ) {
V_2 -> V_202 = F_61 ;
V_2 -> V_190 = F_13 ;
if ( F_17 ( V_20 ) -> V_47 == 6 )
V_2 -> V_190 = F_11 ;
V_2 -> V_203 = F_86 ;
V_2 -> V_204 = F_87 ;
V_2 -> V_112 = V_205 ;
V_2 -> V_206 = F_66 ;
V_2 -> V_207 = F_62 ;
V_2 -> V_102 [ 0 ] = V_104 ;
V_2 -> V_102 [ 1 ] = V_208 ;
V_2 -> V_102 [ 2 ] = V_209 ;
V_2 -> V_90 [ 0 ] = V_210 ;
V_2 -> V_90 [ 1 ] = V_211 ;
} else if ( F_8 ( V_20 ) ) {
V_2 -> V_202 = F_64 ;
V_2 -> V_190 = F_6 ;
V_2 -> V_206 = F_69 ;
V_2 -> V_203 = F_70 ;
V_2 -> V_204 = F_74 ;
V_2 -> V_112 = V_205 | V_212 ;
} else {
V_2 -> V_202 = F_85 ;
if ( F_17 ( V_20 ) -> V_47 < 4 )
V_2 -> V_190 = F_2 ;
else
V_2 -> V_190 = F_6 ;
V_2 -> V_206 = F_68 ;
if ( F_137 ( V_20 ) ) {
V_2 -> V_203 = F_77 ;
V_2 -> V_204 = F_80 ;
} else {
V_2 -> V_203 = F_75 ;
V_2 -> V_204 = F_76 ;
}
V_2 -> V_112 = V_213 ;
}
V_2 -> V_52 = F_14 ;
if ( F_138 ( V_20 ) )
V_2 -> V_214 = F_133 ;
else if ( F_17 ( V_20 ) -> V_47 >= 6 )
V_2 -> V_214 = F_134 ;
else if ( F_17 ( V_20 ) -> V_47 >= 4 )
V_2 -> V_214 = F_88 ;
else if ( F_104 ( V_20 ) || F_105 ( V_20 ) )
V_2 -> V_214 = F_89 ;
else
V_2 -> V_214 = F_91 ;
V_2 -> V_159 = F_48 ;
V_2 -> V_162 = F_56 ;
if ( F_57 ( V_20 ) ) {
struct V_50 * V_51 ;
int V_12 ;
V_51 = F_38 ( V_20 , V_136 ) ;
if ( V_51 == NULL ) {
F_30 ( L_13 ) ;
return - V_63 ;
}
V_12 = F_40 ( V_51 , 0 , true , false ) ;
if ( V_12 != 0 ) {
F_44 ( & V_51 -> V_71 ) ;
F_30 ( L_14 ) ;
return V_12 ;
}
V_2 -> V_27 = V_51 ;
}
return F_97 ( V_20 , V_2 ) ;
}
int F_139 ( struct V_19 * V_20 , T_5 V_215 , T_1 V_8 )
{
T_2 * V_44 = V_20 -> V_45 ;
struct V_1 * V_2 = & V_44 -> V_2 [ V_117 ] ;
int V_12 ;
V_2 -> V_53 = L_12 ;
V_2 -> V_103 = V_117 ;
V_2 -> V_48 = V_201 ;
if ( F_17 ( V_20 ) -> V_47 >= 6 ) {
return - V_216 ;
}
V_2 -> V_202 = F_85 ;
if ( F_17 ( V_20 ) -> V_47 < 4 )
V_2 -> V_190 = F_2 ;
else
V_2 -> V_190 = F_6 ;
V_2 -> V_206 = F_68 ;
if ( F_137 ( V_20 ) ) {
V_2 -> V_203 = F_77 ;
V_2 -> V_204 = F_80 ;
} else {
V_2 -> V_203 = F_75 ;
V_2 -> V_204 = F_76 ;
}
V_2 -> V_112 = V_213 ;
V_2 -> V_52 = F_14 ;
if ( F_17 ( V_20 ) -> V_47 >= 4 )
V_2 -> V_214 = F_88 ;
else if ( F_104 ( V_20 ) || F_105 ( V_20 ) )
V_2 -> V_214 = F_89 ;
else
V_2 -> V_214 = F_91 ;
V_2 -> V_159 = F_48 ;
V_2 -> V_162 = F_56 ;
V_2 -> V_20 = V_20 ;
F_98 ( & V_2 -> V_149 ) ;
F_98 ( & V_2 -> V_150 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_161 = V_2 -> V_8 ;
if ( F_104 ( V_2 -> V_20 ) || F_105 ( V_2 -> V_20 ) )
V_2 -> V_161 -= 128 ;
V_2 -> V_154 = F_103 ( V_215 , V_8 ) ;
if ( V_2 -> V_154 == NULL ) {
F_30 ( L_15
L_16 ) ;
return - V_63 ;
}
if ( ! F_100 ( V_20 ) ) {
V_12 = F_95 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
int F_140 ( struct V_19 * V_20 )
{
T_2 * V_44 = V_20 -> V_45 ;
struct V_1 * V_2 = & V_44 -> V_2 [ V_121 ] ;
V_2 -> V_53 = L_17 ;
V_2 -> V_103 = V_121 ;
V_2 -> V_52 = F_14 ;
if ( F_53 ( V_20 ) || F_51 ( V_20 ) ) {
V_2 -> V_48 = V_217 ;
if ( F_53 ( V_20 ) )
V_2 -> V_52 = F_129 ;
V_2 -> V_190 = F_132 ;
V_2 -> V_202 = F_61 ;
V_2 -> V_206 = F_66 ;
V_2 -> V_112 = V_218 ;
V_2 -> V_203 = F_86 ;
V_2 -> V_204 = F_87 ;
V_2 -> V_214 = F_134 ;
V_2 -> V_207 = F_62 ;
V_2 -> V_102 [ 0 ] = V_219 ;
V_2 -> V_102 [ 1 ] = V_104 ;
V_2 -> V_102 [ 2 ] = V_220 ;
V_2 -> V_90 [ 0 ] = V_221 ;
V_2 -> V_90 [ 1 ] = V_222 ;
} else {
V_2 -> V_48 = V_223 ;
V_2 -> V_190 = F_84 ;
V_2 -> V_202 = F_85 ;
V_2 -> V_206 = F_68 ;
if ( F_8 ( V_20 ) ) {
V_2 -> V_112 = V_224 ;
V_2 -> V_203 = F_70 ;
V_2 -> V_204 = F_74 ;
} else {
V_2 -> V_112 = V_225 ;
V_2 -> V_203 = F_75 ;
V_2 -> V_204 = F_76 ;
}
V_2 -> V_214 = F_88 ;
}
V_2 -> V_159 = F_20 ;
return F_97 ( V_20 , V_2 ) ;
}
int F_141 ( struct V_19 * V_20 )
{
T_2 * V_44 = V_20 -> V_45 ;
struct V_1 * V_2 = & V_44 -> V_2 [ V_119 ] ;
V_2 -> V_53 = L_18 ;
V_2 -> V_103 = V_119 ;
V_2 -> V_48 = V_226 ;
V_2 -> V_52 = F_14 ;
V_2 -> V_190 = F_135 ;
V_2 -> V_202 = F_61 ;
V_2 -> V_206 = F_66 ;
V_2 -> V_112 = V_227 ;
V_2 -> V_203 = F_86 ;
V_2 -> V_204 = F_87 ;
V_2 -> V_214 = F_134 ;
V_2 -> V_207 = F_62 ;
V_2 -> V_102 [ 0 ] = V_228 ;
V_2 -> V_102 [ 1 ] = V_229 ;
V_2 -> V_102 [ 2 ] = V_104 ;
V_2 -> V_90 [ 0 ] = V_230 ;
V_2 -> V_90 [ 1 ] = V_231 ;
V_2 -> V_159 = F_20 ;
return F_97 ( V_20 , V_2 ) ;
}
int
F_142 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_232 )
return 0 ;
V_12 = V_2 -> V_190 ( V_2 , 0 , V_192 ) ;
if ( V_12 )
return V_12 ;
F_143 ( V_2 , 0 , V_192 ) ;
V_2 -> V_232 = false ;
return 0 ;
}
int
F_144 ( struct V_1 * V_2 )
{
T_3 V_10 ;
int V_12 ;
V_10 = 0 ;
if ( V_2 -> V_232 )
V_10 = V_192 ;
V_12 = V_2 -> V_190 ( V_2 , V_192 , V_10 ) ;
if ( V_12 )
return V_12 ;
F_143 ( V_2 , V_192 , V_10 ) ;
V_2 -> V_232 = false ;
return 0 ;
}
