static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 & V_5 ) - ( V_2 -> V_6 + 8 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_7 ;
return V_3 ;
}
static int
F_2 ( struct V_1 * V_2 ,
T_1 V_8 ,
T_1 V_9 )
{
T_1 V_10 ;
int V_11 ;
V_10 = V_12 ;
if ( ( ( V_8 | V_9 ) & V_13 ) == 0 )
V_10 |= V_14 ;
if ( V_8 & V_15 )
V_10 |= V_16 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 ,
T_1 V_8 ,
T_1 V_9 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_1 V_10 ;
int V_11 ;
V_10 = V_12 | V_14 ;
if ( ( V_8 | V_9 ) & V_13 )
V_10 &= ~ V_14 ;
if ( V_8 & V_20 )
V_10 |= V_21 ;
if ( V_8 & V_22 &&
( F_7 ( V_19 ) || F_8 ( V_19 ) ) )
V_10 |= V_23 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
T_1 V_27 = V_25 -> V_28 + 128 ;
int V_11 ;
V_11 = F_3 ( V_2 , 6 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 5 ) ) ;
F_4 ( V_2 , V_29 |
V_30 ) ;
F_4 ( V_2 , V_27 | V_31 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
V_11 = F_3 ( V_2 , 6 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 5 ) ) ;
F_4 ( V_2 , V_32 ) ;
F_4 ( V_2 , V_27 | V_31 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_33 = 0 ;
struct V_24 * V_25 = V_2 -> V_26 ;
T_1 V_27 = V_25 -> V_28 + 128 ;
int V_11 ;
V_11 = F_9 ( V_2 ) ;
if ( V_11 )
return V_11 ;
if ( V_9 ) {
V_33 |= V_34 ;
V_33 |= V_35 ;
V_33 |= V_29 ;
}
if ( V_8 ) {
V_33 |= V_36 ;
V_33 |= V_37 ;
V_33 |= V_38 ;
V_33 |= V_39 ;
V_33 |= V_40 ;
V_33 |= V_41 ;
V_33 |= V_32 ;
}
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 4 ) ) ;
F_4 ( V_2 , V_33 ) ;
F_4 ( V_2 , V_27 | V_31 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 4 ) ) ;
F_4 ( V_2 , V_29 |
V_30 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_33 = 0 ;
struct V_24 * V_25 = V_2 -> V_26 ;
T_1 V_27 = V_25 -> V_28 + 128 ;
int V_11 ;
V_33 |= V_29 ;
if ( V_9 ) {
V_33 |= V_34 ;
V_33 |= V_35 ;
}
if ( V_8 ) {
V_33 |= V_36 ;
V_33 |= V_37 ;
V_33 |= V_38 ;
V_33 |= V_39 ;
V_33 |= V_40 ;
V_33 |= V_41 ;
V_33 |= V_32 ;
F_12 ( V_2 ) ;
}
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 4 ) ) ;
F_4 ( V_2 , V_33 ) ;
F_4 ( V_2 , V_27 | V_31 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_42 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
F_15 ( V_2 , V_42 ) ;
}
T_1 F_16 ( struct V_1 * V_2 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
T_1 V_45 = F_17 ( V_2 -> V_19 ) -> V_46 >= 4 ?
F_18 ( V_2 -> V_47 ) : V_48 ;
return F_19 ( V_45 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
struct V_49 * V_50 = V_2 -> V_50 ;
int V_11 = 0 ;
T_1 V_4 ;
if ( F_21 ( V_19 ) )
F_22 ( V_43 ) ;
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
V_2 -> V_51 ( V_2 , 0 ) ;
V_4 = F_25 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_26 ( L_1
L_2 ,
V_2 -> V_52 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
F_24 ( V_2 , 0 ) ;
if ( F_25 ( V_2 ) & V_5 ) {
F_30 ( L_3
L_2 ,
V_2 -> V_52 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
}
}
F_31 ( V_2 , V_50 -> V_28 ) ;
F_23 ( V_2 ,
( ( V_2 -> V_7 - V_53 ) & V_54 )
| V_55 ) ;
if ( F_32 ( ( F_27 ( V_2 ) & V_55 ) != 0 &&
F_29 ( V_2 ) == V_50 -> V_28 &&
( F_25 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_30 ( L_4
L_2 ,
V_2 -> V_52 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
V_11 = - V_56 ;
goto V_57;
}
if ( ! F_33 ( V_2 -> V_19 , V_58 ) )
F_34 ( V_2 -> V_19 ) ;
else {
V_2 -> V_4 = F_25 ( V_2 ) ;
V_2 -> V_6 = F_28 ( V_2 ) & V_59 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_60 = - 1 ;
}
V_57:
if ( F_21 ( V_19 ) )
F_35 ( V_43 ) ;
return V_11 ;
}
static int
F_36 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_49 * V_50 ;
int V_11 ;
if ( V_2 -> V_26 )
return 0 ;
V_25 = F_37 ( sizeof( * V_25 ) , V_61 ) ;
if ( ! V_25 )
return - V_62 ;
V_50 = F_38 ( V_2 -> V_19 , 4096 ) ;
if ( V_50 == NULL ) {
F_30 ( L_5 ) ;
V_11 = - V_62 ;
goto V_63;
}
F_39 ( V_50 , V_64 ) ;
V_11 = F_40 ( V_50 , 4096 , true , false ) ;
if ( V_11 )
goto V_65;
V_25 -> V_28 = V_50 -> V_28 ;
V_25 -> V_66 = F_41 ( F_42 ( V_50 -> V_67 -> V_68 ) ) ;
if ( V_25 -> V_66 == NULL )
goto V_69;
V_25 -> V_50 = V_50 ;
V_2 -> V_26 = V_25 ;
return 0 ;
V_69:
F_43 ( V_50 ) ;
V_65:
F_44 ( & V_50 -> V_70 ) ;
V_63:
F_45 ( V_25 ) ;
return V_11 ;
}
static void
F_46 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_49 * V_50 ;
if ( ! V_2 -> V_26 )
return;
V_50 = V_25 -> V_50 ;
F_47 ( F_42 ( V_50 -> V_67 -> V_68 ) ) ;
F_43 ( V_50 ) ;
F_44 ( & V_50 -> V_70 ) ;
F_45 ( V_25 ) ;
V_2 -> V_26 = NULL ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_71 * V_43 = V_19 -> V_44 ;
int V_11 = F_20 ( V_2 ) ;
if ( F_17 ( V_19 ) -> V_46 > 3 ) {
F_49 ( V_72 , F_50 ( V_73 ) ) ;
if ( F_51 ( V_19 ) )
F_49 ( V_74 ,
F_52 ( V_75 ) |
F_50 ( V_76 ) ) ;
}
if ( F_17 ( V_19 ) -> V_46 >= 5 ) {
V_11 = F_36 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_53 ( V_19 ) ) {
F_49 ( V_77 ,
F_52 ( V_78 ) ) ;
V_2 -> V_79 =
! ! ( F_19 ( V_80 ) & V_75 ) ;
}
if ( F_17 ( V_19 ) -> V_46 >= 6 )
F_49 ( V_81 , F_50 ( V_82 ) ) ;
if ( F_54 ( V_19 ) )
F_55 ( V_2 , ~ V_83 ) ;
return V_11 ;
}
static void F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_26 )
return;
F_46 ( V_2 ) ;
}
static void
F_57 ( struct V_1 * V_2 ,
T_1 V_84 ,
T_1 V_85 )
{
F_4 ( V_2 , V_86 |
V_87 |
V_88 |
V_89 ) ;
F_4 ( V_2 , V_84 ) ;
F_4 ( V_2 , V_85 ) ;
}
static int
F_58 ( struct V_1 * V_2 ,
T_1 * V_84 )
{
T_1 V_90 ;
T_1 V_91 ;
int V_11 ;
V_11 = F_3 ( V_2 , 10 ) ;
if ( V_11 )
return V_11 ;
V_90 = V_2 -> V_92 [ 0 ] ;
V_91 = V_2 -> V_92 [ 1 ] ;
* V_84 = F_59 ( V_2 ) ;
F_57 ( V_2 , * V_84 , V_90 ) ;
F_57 ( V_2 , * V_84 , V_91 ) ;
F_4 ( V_2 , V_93 ) ;
F_4 ( V_2 , V_94 << V_95 ) ;
F_4 ( V_2 , * V_84 ) ;
F_4 ( V_2 , V_96 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_60 ( struct V_1 * V_97 ,
struct V_1 * V_98 ,
T_1 V_84 )
{
int V_11 ;
T_1 V_99 = V_86 |
V_100 |
V_88 ;
V_84 -= 1 ;
F_61 ( V_98 -> V_101 [ V_97 -> V_102 ] ==
V_103 ) ;
V_11 = F_3 ( V_97 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_97 ,
V_99 | V_98 -> V_101 [ V_97 -> V_102 ] ) ;
F_4 ( V_97 , V_84 ) ;
F_4 ( V_97 , 0 ) ;
F_4 ( V_97 , V_17 ) ;
F_5 ( V_97 ) ;
return 0 ;
}
static int
F_62 ( struct V_1 * V_2 ,
T_1 * V_104 )
{
T_1 V_84 = F_59 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_26 ;
T_1 V_27 = V_25 -> V_28 + 128 ;
int V_11 ;
V_11 = F_3 ( V_2 , 32 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 4 ) | V_32 |
V_105 |
V_38 ) ;
F_4 ( V_2 , V_25 -> V_28 | V_31 ) ;
F_4 ( V_2 , V_84 ) ;
F_4 ( V_2 , 0 ) ;
F_63 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_63 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_63 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_63 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_63 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_63 ( V_2 , V_27 ) ;
F_4 ( V_2 , F_10 ( 4 ) | V_32 |
V_105 |
V_38 |
V_106 ) ;
F_4 ( V_2 , V_25 -> V_28 | V_31 ) ;
F_4 ( V_2 , V_84 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
* V_104 = V_84 ;
return 0 ;
}
static T_1
F_64 ( struct V_1 * V_2 , bool V_107 )
{
if ( ! V_107 )
F_16 ( V_2 ) ;
return F_65 ( V_2 , V_94 ) ;
}
static T_1
F_66 ( struct V_1 * V_2 , bool V_107 )
{
return F_65 ( V_2 , V_94 ) ;
}
static T_1
F_67 ( struct V_1 * V_2 , bool V_107 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
return V_25 -> V_66 [ 0 ] ;
}
static bool
F_68 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_108 )
return false ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
V_43 -> V_111 &= ~ V_2 -> V_112 ;
F_49 ( V_113 , V_43 -> V_111 ) ;
F_70 ( V_113 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
return true ;
}
static void
F_72 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( -- V_2 -> V_110 == 0 ) {
V_43 -> V_111 |= V_2 -> V_112 ;
F_49 ( V_113 , V_43 -> V_111 ) ;
F_70 ( V_113 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
}
static bool
F_73 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_108 )
return false ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
V_43 -> V_114 &= ~ V_2 -> V_112 ;
F_49 ( V_115 , V_43 -> V_114 ) ;
F_70 ( V_115 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
return true ;
}
static void
F_74 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( -- V_2 -> V_110 == 0 ) {
V_43 -> V_114 |= V_2 -> V_112 ;
F_49 ( V_115 , V_43 -> V_114 ) ;
F_70 ( V_115 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
}
static bool
F_75 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_108 )
return false ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
V_43 -> V_114 &= ~ V_2 -> V_112 ;
F_76 ( V_115 , V_43 -> V_114 ) ;
F_77 ( V_115 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
return true ;
}
static void
F_78 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( -- V_2 -> V_110 == 0 ) {
V_43 -> V_114 |= V_2 -> V_112 ;
F_76 ( V_115 , V_43 -> V_114 ) ;
F_77 ( V_115 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
T_1 V_116 = 0 ;
if ( F_51 ( V_19 ) ) {
switch ( V_2 -> V_102 ) {
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
} else if ( F_53 ( V_2 -> V_19 ) ) {
V_116 = F_80 ( V_2 -> V_47 ) ;
} else {
V_116 = F_81 ( V_2 -> V_47 ) ;
}
F_49 ( V_116 , ( T_1 ) V_2 -> V_123 . V_124 ) ;
F_70 ( V_116 ) ;
}
static int
F_82 ( struct V_1 * V_2 ,
T_1 V_8 ,
T_1 V_9 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_12 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_83 ( struct V_1 * V_2 ,
T_1 * V_104 )
{
T_1 V_84 ;
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_84 = F_59 ( V_2 ) ;
F_4 ( V_2 , V_93 ) ;
F_4 ( V_2 , V_94 << V_95 ) ;
F_4 ( V_2 , V_84 ) ;
F_4 ( V_2 , V_96 ) ;
F_5 ( V_2 ) ;
* V_104 = V_84 ;
return 0 ;
}
static bool
F_84 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_108 )
return false ;
F_22 ( V_43 ) ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
if ( F_54 ( V_19 ) && V_2 -> V_102 == V_117 )
F_55 ( V_2 , ~ ( V_2 -> V_112 |
V_83 ) ) ;
else
F_55 ( V_2 , ~ V_2 -> V_112 ) ;
V_43 -> V_111 &= ~ V_2 -> V_112 ;
F_49 ( V_113 , V_43 -> V_111 ) ;
F_70 ( V_113 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
return true ;
}
static void
F_85 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_69 ( & V_43 -> V_109 , V_33 ) ;
if ( -- V_2 -> V_110 == 0 ) {
if ( F_54 ( V_19 ) && V_2 -> V_102 == V_117 )
F_55 ( V_2 , ~ V_83 ) ;
else
F_55 ( V_2 , ~ 0 ) ;
V_43 -> V_111 |= V_2 -> V_112 ;
F_49 ( V_113 , V_43 -> V_111 ) ;
F_70 ( V_113 ) ;
}
F_71 ( & V_43 -> V_109 , V_33 ) ;
F_35 ( V_43 ) ;
}
static int
F_86 ( struct V_1 * V_2 , T_1 V_125 , T_1 V_126 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 ,
V_127 |
V_128 |
V_129 ) ;
F_4 ( V_2 , V_125 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_87 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_130 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_131 ) ;
F_4 ( V_2 , V_125 | V_132 ) ;
F_4 ( V_2 , V_125 + V_130 - 8 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_88 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_130 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_127 | V_128 ) ;
F_4 ( V_2 , V_125 | V_132 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
V_50 = V_2 -> V_123 . V_50 ;
if ( V_50 == NULL )
return;
F_47 ( F_42 ( V_50 -> V_67 -> V_68 ) ) ;
F_43 ( V_50 ) ;
F_44 ( & V_50 -> V_70 ) ;
V_2 -> V_123 . V_50 = NULL ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_49 * V_50 ;
int V_11 ;
V_50 = F_38 ( V_19 , 4096 ) ;
if ( V_50 == NULL ) {
F_30 ( L_6 ) ;
V_11 = - V_62 ;
goto V_63;
}
F_39 ( V_50 , V_64 ) ;
V_11 = F_40 ( V_50 , 4096 , true , false ) ;
if ( V_11 != 0 ) {
goto V_65;
}
V_2 -> V_123 . V_124 = V_50 -> V_28 ;
V_2 -> V_123 . V_133 = F_41 ( F_42 ( V_50 -> V_67 -> V_68 ) ) ;
if ( V_2 -> V_123 . V_133 == NULL ) {
V_11 = - V_62 ;
goto V_69;
}
V_2 -> V_123 . V_50 = V_50 ;
memset ( V_2 -> V_123 . V_133 , 0 , V_53 ) ;
F_79 ( V_2 ) ;
F_91 ( L_7 ,
V_2 -> V_52 , V_2 -> V_123 . V_124 ) ;
return 0 ;
V_69:
F_43 ( V_50 ) ;
V_65:
F_44 ( & V_50 -> V_70 ) ;
V_63:
return V_11 ;
}
static int F_92 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_71 * V_43 = V_19 -> V_44 ;
int V_11 ;
V_2 -> V_19 = V_19 ;
F_93 ( & V_2 -> V_134 ) ;
F_93 ( & V_2 -> V_135 ) ;
V_2 -> V_7 = 32 * V_53 ;
F_94 ( & V_2 -> V_136 ) ;
if ( F_95 ( V_19 ) ) {
V_11 = F_90 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
V_50 = F_38 ( V_19 , V_2 -> V_7 ) ;
if ( V_50 == NULL ) {
F_30 ( L_8 ) ;
V_11 = - V_62 ;
goto V_137;
}
V_2 -> V_50 = V_50 ;
V_11 = F_40 ( V_50 , V_53 , true , false ) ;
if ( V_11 )
goto V_65;
V_11 = F_96 ( V_50 , true ) ;
if ( V_11 )
goto V_69;
V_2 -> V_138 =
F_97 ( V_43 -> V_139 . V_140 -> V_141 + V_50 -> V_28 ,
V_2 -> V_7 ) ;
if ( V_2 -> V_138 == NULL ) {
F_30 ( L_9 ) ;
V_11 = - V_142 ;
goto V_69;
}
V_11 = V_2 -> V_143 ( V_2 ) ;
if ( V_11 )
goto V_144;
V_2 -> V_145 = V_2 -> V_7 ;
if ( F_98 ( V_2 -> V_19 ) || F_99 ( V_2 -> V_19 ) )
V_2 -> V_145 -= 128 ;
return 0 ;
V_144:
F_100 ( V_2 -> V_138 ) ;
V_69:
F_43 ( V_50 ) ;
V_65:
F_44 ( & V_50 -> V_70 ) ;
V_2 -> V_50 = NULL ;
V_137:
F_89 ( V_2 ) ;
return V_11 ;
}
void F_101 ( struct V_1 * V_2 )
{
struct V_71 * V_43 ;
int V_11 ;
if ( V_2 -> V_50 == NULL )
return;
V_43 = V_2 -> V_19 -> V_44 ;
V_11 = F_102 ( V_2 ) ;
if ( V_11 )
F_30 ( L_10 ,
V_2 -> V_52 , V_11 ) ;
F_23 ( V_2 , 0 ) ;
F_100 ( V_2 -> V_138 ) ;
F_43 ( V_2 -> V_50 ) ;
F_44 ( & V_2 -> V_50 -> V_70 ) ;
V_2 -> V_50 = NULL ;
if ( V_2 -> V_146 )
V_2 -> V_146 ( V_2 ) ;
F_89 ( V_2 ) ;
}
static int F_103 ( struct V_1 * V_2 )
{
T_3 T_4 * V_147 ;
int V_148 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_148 ) {
int V_11 = F_104 ( V_2 , V_148 ) ;
if ( V_11 )
return V_11 ;
}
V_147 = V_2 -> V_138 + V_2 -> V_6 ;
V_148 /= 4 ;
while ( V_148 -- )
F_105 ( V_17 , V_147 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 , T_1 V_84 )
{
int V_11 ;
V_11 = F_107 ( V_2 , V_84 ) ;
if ( ! V_11 )
F_108 ( V_2 ) ;
return V_11 ;
}
static int F_109 ( struct V_1 * V_2 , int V_149 )
{
struct V_150 * V_151 ;
T_1 V_84 = 0 ;
int V_11 ;
F_108 ( V_2 ) ;
if ( V_2 -> V_60 != - 1 ) {
V_2 -> V_4 = V_2 -> V_60 ;
V_2 -> V_60 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_149 )
return 0 ;
}
F_110 (request, &ring->request_list, list) {
int V_3 ;
if ( V_151 -> V_6 == - 1 )
continue;
V_3 = V_151 -> V_6 - ( V_2 -> V_6 + 8 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_7 ;
if ( V_3 >= V_149 ) {
V_84 = V_151 -> V_84 ;
break;
}
V_151 -> V_6 = - 1 ;
}
if ( V_84 == 0 )
return - V_152 ;
V_11 = F_106 ( V_2 , V_84 ) ;
if ( V_11 )
return V_11 ;
if ( F_61 ( V_2 -> V_60 == - 1 ) )
return - V_152 ;
V_2 -> V_4 = V_2 -> V_60 ;
V_2 -> V_60 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_61 ( V_2 -> V_3 < V_149 ) )
return - V_152 ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 , int V_149 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_71 * V_43 = V_19 -> V_44 ;
unsigned long V_153 ;
int V_11 ;
V_11 = F_109 ( V_2 , V_149 ) ;
if ( V_11 != - V_152 )
return V_11 ;
F_111 ( V_2 ) ;
V_153 = V_154 + 60 * V_155 ;
do {
V_2 -> V_4 = F_25 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_149 ) {
F_112 ( V_2 ) ;
return 0 ;
}
if ( V_19 -> V_156 -> V_157 ) {
struct V_158 * V_159 = V_19 -> V_156 -> V_157 -> V_160 ;
if ( V_159 -> V_161 )
V_159 -> V_161 -> V_162 |= V_163 ;
}
F_113 ( 1 ) ;
V_11 = F_114 ( V_43 , V_43 -> V_139 . V_164 ) ;
if ( V_11 )
return V_11 ;
} while ( ! F_115 ( V_154 , V_153 ) );
F_112 ( V_2 ) ;
return - V_165 ;
}
int F_3 ( struct V_1 * V_2 ,
int V_166 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
int V_149 = 4 * V_166 ;
int V_11 ;
V_11 = F_114 ( V_43 , V_43 -> V_139 . V_164 ) ;
if ( V_11 )
return V_11 ;
if ( F_116 ( V_2 -> V_6 + V_149 > V_2 -> V_145 ) ) {
V_11 = F_103 ( V_2 ) ;
if ( F_116 ( V_11 ) )
return V_11 ;
}
if ( F_116 ( V_2 -> V_3 < V_149 ) ) {
V_11 = F_104 ( V_2 , V_149 ) ;
if ( F_116 ( V_11 ) )
return V_11 ;
}
V_2 -> V_3 -= V_149 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_71 * V_43 = V_2 -> V_19 -> V_44 ;
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
if ( V_43 -> V_167 & F_117 ( V_2 ) )
return;
V_2 -> V_51 ( V_2 , V_2 -> V_6 ) ;
}
static void F_118 ( struct V_1 * V_2 ,
T_1 V_42 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
F_49 ( V_168 ,
F_50 ( V_169 ) ) ;
F_119 ( V_170 , 0x0 ) ;
if ( F_32 ( ( F_19 ( V_168 ) &
V_171 ) == 0 ,
50 ) )
F_30 ( L_11 ) ;
F_15 ( V_2 , V_42 ) ;
F_70 ( F_120 ( V_2 -> V_47 ) ) ;
F_49 ( V_168 ,
F_52 ( V_169 ) ) ;
}
static int F_121 ( struct V_1 * V_2 ,
T_1 V_172 , T_1 V_173 )
{
T_3 V_10 ;
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_10 = V_174 ;
if ( V_172 & V_175 )
V_10 |= V_176 | V_177 ;
F_4 ( V_2 , V_10 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_122 ( struct V_1 * V_2 ,
T_1 V_125 , T_1 V_130 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_127 | V_129 ) ;
F_4 ( V_2 , V_125 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
T_1 V_172 , T_1 V_173 )
{
T_3 V_10 ;
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_10 = V_174 ;
if ( V_172 & V_13 )
V_10 |= V_176 ;
F_4 ( V_2 , V_10 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_124 ( struct V_18 * V_19 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_117 ] ;
V_2 -> V_52 = L_12 ;
V_2 -> V_102 = V_117 ;
V_2 -> V_47 = V_178 ;
if ( F_17 ( V_19 ) -> V_46 >= 6 ) {
V_2 -> V_179 = F_58 ;
V_2 -> V_173 = F_13 ;
if ( F_17 ( V_19 ) -> V_46 == 6 )
V_2 -> V_173 = F_11 ;
V_2 -> V_180 = F_84 ;
V_2 -> V_181 = F_85 ;
V_2 -> V_112 = V_182 ;
V_2 -> V_183 = F_64 ;
V_2 -> V_184 = F_60 ;
V_2 -> V_101 [ 0 ] = V_103 ;
V_2 -> V_101 [ 1 ] = V_185 ;
V_2 -> V_101 [ 2 ] = V_186 ;
V_2 -> V_92 [ 0 ] = V_187 ;
V_2 -> V_92 [ 1 ] = V_188 ;
} else if ( F_8 ( V_19 ) ) {
V_2 -> V_179 = F_62 ;
V_2 -> V_173 = F_6 ;
V_2 -> V_183 = F_67 ;
V_2 -> V_180 = F_68 ;
V_2 -> V_181 = F_72 ;
V_2 -> V_112 = V_182 | V_189 ;
} else {
V_2 -> V_179 = F_83 ;
if ( F_17 ( V_19 ) -> V_46 < 4 )
V_2 -> V_173 = F_2 ;
else
V_2 -> V_173 = F_6 ;
V_2 -> V_183 = F_66 ;
if ( F_125 ( V_19 ) ) {
V_2 -> V_180 = F_75 ;
V_2 -> V_181 = F_78 ;
} else {
V_2 -> V_180 = F_73 ;
V_2 -> V_181 = F_74 ;
}
V_2 -> V_112 = V_190 ;
}
V_2 -> V_51 = F_14 ;
if ( F_17 ( V_19 ) -> V_46 >= 6 )
V_2 -> V_191 = F_122 ;
else if ( F_17 ( V_19 ) -> V_46 >= 4 )
V_2 -> V_191 = F_86 ;
else if ( F_98 ( V_19 ) || F_99 ( V_19 ) )
V_2 -> V_191 = F_87 ;
else
V_2 -> V_191 = F_88 ;
V_2 -> V_143 = F_48 ;
V_2 -> V_146 = F_56 ;
if ( ! F_95 ( V_19 ) ) {
V_2 -> V_123 . V_133 = V_43 -> V_192 -> V_193 ;
memset ( V_2 -> V_123 . V_133 , 0 , V_53 ) ;
}
return F_92 ( V_19 , V_2 ) ;
}
int F_126 ( struct V_18 * V_19 , T_5 V_194 , T_1 V_7 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_117 ] ;
V_2 -> V_52 = L_12 ;
V_2 -> V_102 = V_117 ;
V_2 -> V_47 = V_178 ;
if ( F_17 ( V_19 ) -> V_46 >= 6 ) {
return - V_195 ;
}
V_2 -> V_179 = F_83 ;
if ( F_17 ( V_19 ) -> V_46 < 4 )
V_2 -> V_173 = F_2 ;
else
V_2 -> V_173 = F_6 ;
V_2 -> V_183 = F_66 ;
if ( F_125 ( V_19 ) ) {
V_2 -> V_180 = F_75 ;
V_2 -> V_181 = F_78 ;
} else {
V_2 -> V_180 = F_73 ;
V_2 -> V_181 = F_74 ;
}
V_2 -> V_112 = V_190 ;
V_2 -> V_51 = F_14 ;
if ( F_17 ( V_19 ) -> V_46 >= 4 )
V_2 -> V_191 = F_86 ;
else if ( F_98 ( V_19 ) || F_99 ( V_19 ) )
V_2 -> V_191 = F_87 ;
else
V_2 -> V_191 = F_88 ;
V_2 -> V_143 = F_48 ;
V_2 -> V_146 = F_56 ;
if ( ! F_95 ( V_19 ) )
V_2 -> V_123 . V_133 = V_43 -> V_192 -> V_193 ;
V_2 -> V_19 = V_19 ;
F_93 ( & V_2 -> V_134 ) ;
F_93 ( & V_2 -> V_135 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_145 = V_2 -> V_7 ;
if ( F_98 ( V_2 -> V_19 ) )
V_2 -> V_145 -= 128 ;
V_2 -> V_138 = F_97 ( V_194 , V_7 ) ;
if ( V_2 -> V_138 == NULL ) {
F_30 ( L_13
L_14 ) ;
return - V_62 ;
}
return 0 ;
}
int F_127 ( struct V_18 * V_19 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_121 ] ;
V_2 -> V_52 = L_15 ;
V_2 -> V_102 = V_121 ;
V_2 -> V_51 = F_14 ;
if ( F_53 ( V_19 ) || F_51 ( V_19 ) ) {
V_2 -> V_47 = V_196 ;
if ( F_53 ( V_19 ) )
V_2 -> V_51 = F_118 ;
V_2 -> V_173 = F_121 ;
V_2 -> V_179 = F_58 ;
V_2 -> V_183 = F_64 ;
V_2 -> V_112 = V_197 ;
V_2 -> V_180 = F_84 ;
V_2 -> V_181 = F_85 ;
V_2 -> V_191 = F_122 ;
V_2 -> V_184 = F_60 ;
V_2 -> V_101 [ 0 ] = V_198 ;
V_2 -> V_101 [ 1 ] = V_103 ;
V_2 -> V_101 [ 2 ] = V_199 ;
V_2 -> V_92 [ 0 ] = V_200 ;
V_2 -> V_92 [ 1 ] = V_201 ;
} else {
V_2 -> V_47 = V_202 ;
V_2 -> V_173 = F_82 ;
V_2 -> V_179 = F_83 ;
V_2 -> V_183 = F_66 ;
if ( F_8 ( V_19 ) ) {
V_2 -> V_112 = V_203 ;
V_2 -> V_180 = F_68 ;
V_2 -> V_181 = F_72 ;
} else {
V_2 -> V_112 = V_204 ;
V_2 -> V_180 = F_73 ;
V_2 -> V_181 = F_74 ;
}
V_2 -> V_191 = F_86 ;
}
V_2 -> V_143 = F_20 ;
return F_92 ( V_19 , V_2 ) ;
}
int F_128 ( struct V_18 * V_19 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_119 ] ;
V_2 -> V_52 = L_16 ;
V_2 -> V_102 = V_119 ;
V_2 -> V_47 = V_205 ;
V_2 -> V_51 = F_14 ;
V_2 -> V_173 = F_123 ;
V_2 -> V_179 = F_58 ;
V_2 -> V_183 = F_64 ;
V_2 -> V_112 = V_206 ;
V_2 -> V_180 = F_84 ;
V_2 -> V_181 = F_85 ;
V_2 -> V_191 = F_122 ;
V_2 -> V_184 = F_60 ;
V_2 -> V_101 [ 0 ] = V_207 ;
V_2 -> V_101 [ 1 ] = V_208 ;
V_2 -> V_101 [ 2 ] = V_103 ;
V_2 -> V_92 [ 0 ] = V_209 ;
V_2 -> V_92 [ 1 ] = V_210 ;
V_2 -> V_143 = F_20 ;
return F_92 ( V_19 , V_2 ) ;
}
int
F_129 ( struct V_1 * V_2 )
{
int V_11 ;
if ( ! V_2 -> V_211 )
return 0 ;
V_11 = V_2 -> V_173 ( V_2 , 0 , V_175 ) ;
if ( V_11 )
return V_11 ;
F_130 ( V_2 , 0 , V_175 ) ;
V_2 -> V_211 = false ;
return 0 ;
}
int
F_131 ( struct V_1 * V_2 )
{
T_3 V_9 ;
int V_11 ;
V_9 = 0 ;
if ( V_2 -> V_211 )
V_9 = V_175 ;
V_11 = V_2 -> V_173 ( V_2 , V_175 , V_9 ) ;
if ( V_11 )
return V_11 ;
F_130 ( V_2 , V_175 , V_9 ) ;
V_2 -> V_211 = false ;
return 0 ;
}
