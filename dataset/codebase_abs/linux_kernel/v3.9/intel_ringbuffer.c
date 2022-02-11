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
V_34 |= V_43 ;
F_12 ( V_2 ) ;
}
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 4 ) ) ;
F_4 ( V_2 , V_34 ) ;
F_4 ( V_2 , V_28 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
T_1 V_44 )
{
T_2 * V_45 = V_2 -> V_20 -> V_46 ;
F_15 ( V_2 , V_44 ) ;
}
T_1 F_16 ( struct V_1 * V_2 )
{
T_2 * V_45 = V_2 -> V_20 -> V_46 ;
T_1 V_47 = F_17 ( V_2 -> V_20 ) -> V_48 >= 4 ?
F_18 ( V_2 -> V_49 ) : V_50 ;
return F_19 ( V_47 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
struct V_51 * V_52 = V_2 -> V_52 ;
int V_12 = 0 ;
T_1 V_4 ;
if ( F_21 ( V_20 ) )
F_22 ( V_45 ) ;
F_23 ( V_2 , 0 ) ;
F_24 ( V_2 , 0 ) ;
V_2 -> V_53 ( V_2 , 0 ) ;
V_4 = F_25 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_26 ( L_1
L_2 ,
V_2 -> V_54 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
F_24 ( V_2 , 0 ) ;
if ( F_25 ( V_2 ) & V_5 ) {
F_30 ( L_3
L_2 ,
V_2 -> V_54 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
}
}
F_31 ( V_2 , V_52 -> V_29 ) ;
F_23 ( V_2 ,
( ( V_2 -> V_8 - V_55 ) & V_56 )
| V_57 ) ;
if ( F_32 ( ( F_27 ( V_2 ) & V_57 ) != 0 &&
F_29 ( V_2 ) == V_52 -> V_29 &&
( F_25 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_30 ( L_4
L_2 ,
V_2 -> V_54 ,
F_27 ( V_2 ) ,
F_25 ( V_2 ) ,
F_28 ( V_2 ) ,
F_29 ( V_2 ) ) ;
V_12 = - V_58 ;
goto V_59;
}
if ( ! F_33 ( V_2 -> V_20 , V_60 ) )
F_34 ( V_2 -> V_20 ) ;
else {
V_2 -> V_4 = F_25 ( V_2 ) ;
V_2 -> V_6 = F_28 ( V_2 ) & V_61 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_62 = - 1 ;
}
V_59:
if ( F_21 ( V_20 ) )
F_35 ( V_45 ) ;
return V_12 ;
}
static int
F_36 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_51 * V_52 ;
int V_12 ;
if ( V_2 -> V_27 )
return 0 ;
V_26 = F_37 ( sizeof( * V_26 ) , V_63 ) ;
if ( ! V_26 )
return - V_64 ;
V_52 = F_38 ( V_2 -> V_20 , 4096 ) ;
if ( V_52 == NULL ) {
F_30 ( L_5 ) ;
V_12 = - V_64 ;
goto V_65;
}
F_39 ( V_52 , V_66 ) ;
V_12 = F_40 ( V_52 , 4096 , true , false ) ;
if ( V_12 )
goto V_67;
V_26 -> V_29 = V_52 -> V_29 ;
V_26 -> V_68 = F_41 ( F_42 ( V_52 -> V_69 -> V_70 ) ) ;
if ( V_26 -> V_68 == NULL )
goto V_71;
F_43 ( L_6 ,
V_2 -> V_54 , V_26 -> V_29 ) ;
V_26 -> V_52 = V_52 ;
V_2 -> V_27 = V_26 ;
return 0 ;
V_71:
F_44 ( V_52 ) ;
V_67:
F_45 ( & V_52 -> V_72 ) ;
V_65:
F_46 ( V_26 ) ;
return V_12 ;
}
static void
F_47 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
struct V_51 * V_52 ;
if ( ! V_2 -> V_27 )
return;
V_52 = V_26 -> V_52 ;
F_48 ( F_42 ( V_52 -> V_69 -> V_70 ) ) ;
F_44 ( V_52 ) ;
F_45 ( & V_52 -> V_72 ) ;
F_46 ( V_26 ) ;
V_2 -> V_27 = NULL ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_73 * V_45 = V_20 -> V_46 ;
int V_12 = F_20 ( V_2 ) ;
if ( F_17 ( V_20 ) -> V_48 > 3 )
F_50 ( V_74 , F_51 ( V_75 ) ) ;
if ( F_17 ( V_20 ) -> V_48 >= 6 )
F_50 ( V_74 , F_51 ( V_76 ) ) ;
if ( F_17 ( V_20 ) -> V_48 == 6 )
F_50 ( V_77 ,
F_51 ( V_78 ) ) ;
if ( F_52 ( V_20 ) )
F_50 ( V_79 ,
F_53 ( V_78 ) |
F_51 ( V_80 ) ) ;
if ( F_17 ( V_20 ) -> V_48 >= 5 ) {
V_12 = F_36 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
if ( F_54 ( V_20 ) ) {
F_50 ( V_81 ,
F_53 ( V_82 ) ) ;
V_2 -> V_83 =
! ! ( F_19 ( V_77 ) & V_78 ) ;
}
if ( F_17 ( V_20 ) -> V_48 >= 6 )
F_50 ( V_84 , F_51 ( V_85 ) ) ;
if ( F_55 ( V_20 ) )
F_56 ( V_2 , ~ V_86 ) ;
return V_12 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
if ( ! V_2 -> V_27 )
return;
if ( F_58 ( V_20 ) )
F_45 ( F_59 ( V_2 -> V_27 ) ) ;
F_47 ( V_2 ) ;
}
static void
F_60 ( struct V_1 * V_2 ,
T_1 V_87 )
{
F_4 ( V_2 , F_61 ( 1 ) ) ;
F_4 ( V_2 , V_87 ) ;
F_4 ( V_2 , V_2 -> V_88 ) ;
}
static int
F_62 ( struct V_1 * V_2 )
{
T_1 V_89 ;
T_1 V_90 ;
int V_12 ;
V_12 = F_3 ( V_2 , 10 ) ;
if ( V_12 )
return V_12 ;
V_89 = V_2 -> V_91 [ 0 ] ;
V_90 = V_2 -> V_91 [ 1 ] ;
F_60 ( V_2 , V_89 ) ;
F_60 ( V_2 , V_90 ) ;
F_4 ( V_2 , V_92 ) ;
F_4 ( V_2 , V_93 << V_94 ) ;
F_4 ( V_2 , V_2 -> V_88 ) ;
F_4 ( V_2 , V_95 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static inline bool F_63 ( struct V_19 * V_20 ,
T_1 V_96 )
{
struct V_73 * V_45 = V_20 -> V_46 ;
return V_45 -> V_97 < V_96 ;
}
static int
F_64 ( struct V_1 * V_98 ,
struct V_1 * V_99 ,
T_1 V_96 )
{
int V_12 ;
T_1 V_100 = V_101 |
V_102 |
V_103 ;
V_96 -= 1 ;
F_65 ( V_99 -> V_104 [ V_98 -> V_105 ] ==
V_106 ) ;
V_12 = F_3 ( V_98 , 4 ) ;
if ( V_12 )
return V_12 ;
if ( F_66 ( ! F_63 ( V_98 -> V_20 , V_96 ) ) ) {
F_4 ( V_98 ,
V_100 |
V_99 -> V_104 [ V_98 -> V_105 ] ) ;
F_4 ( V_98 , V_96 ) ;
F_4 ( V_98 , 0 ) ;
F_4 ( V_98 , V_18 ) ;
} else {
F_4 ( V_98 , V_18 ) ;
F_4 ( V_98 , V_18 ) ;
F_4 ( V_98 , V_18 ) ;
F_4 ( V_98 , V_18 ) ;
}
F_5 ( V_98 ) ;
return 0 ;
}
static int
F_67 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_12 ;
V_12 = F_3 ( V_2 , 32 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 4 ) | V_33 |
V_107 |
V_39 ) ;
F_4 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_4 ( V_2 , V_2 -> V_88 ) ;
F_4 ( V_2 , 0 ) ;
F_68 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_68 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_68 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_68 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_68 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_68 ( V_2 , V_28 ) ;
F_4 ( V_2 , F_10 ( 4 ) | V_33 |
V_107 |
V_39 |
V_108 ) ;
F_4 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_4 ( V_2 , V_2 -> V_88 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static T_1
F_69 ( struct V_1 * V_2 , bool V_109 )
{
if ( ! V_109 )
F_16 ( V_2 ) ;
return F_70 ( V_2 , V_93 ) ;
}
static T_1
F_71 ( struct V_1 * V_2 , bool V_109 )
{
return F_70 ( V_2 , V_93 ) ;
}
static void
F_72 ( struct V_1 * V_2 , T_1 V_96 )
{
F_73 ( V_2 , V_93 , V_96 ) ;
}
static T_1
F_74 ( struct V_1 * V_2 , bool V_109 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
return V_26 -> V_68 [ 0 ] ;
}
static void
F_75 ( struct V_1 * V_2 , T_1 V_96 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
V_26 -> V_68 [ 0 ] = V_96 ;
}
static bool
F_76 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
if ( ! V_20 -> V_110 )
return false ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( V_2 -> V_112 ++ == 0 ) {
V_45 -> V_113 &= ~ V_2 -> V_114 ;
F_50 ( V_115 , V_45 -> V_113 ) ;
F_78 ( V_115 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( -- V_2 -> V_112 == 0 ) {
V_45 -> V_113 |= V_2 -> V_114 ;
F_50 ( V_115 , V_45 -> V_113 ) ;
F_78 ( V_115 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
}
static bool
F_81 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
if ( ! V_20 -> V_110 )
return false ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( V_2 -> V_112 ++ == 0 ) {
V_45 -> V_116 &= ~ V_2 -> V_114 ;
F_50 ( V_117 , V_45 -> V_116 ) ;
F_78 ( V_117 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
return true ;
}
static void
F_82 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( -- V_2 -> V_112 == 0 ) {
V_45 -> V_116 |= V_2 -> V_114 ;
F_50 ( V_117 , V_45 -> V_116 ) ;
F_78 ( V_117 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
}
static bool
F_83 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
if ( ! V_20 -> V_110 )
return false ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( V_2 -> V_112 ++ == 0 ) {
V_45 -> V_116 &= ~ V_2 -> V_114 ;
F_84 ( V_117 , V_45 -> V_116 ) ;
F_85 ( V_117 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
return true ;
}
static void
F_86 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( -- V_2 -> V_112 == 0 ) {
V_45 -> V_116 |= V_2 -> V_114 ;
F_84 ( V_117 , V_45 -> V_116 ) ;
F_85 ( V_117 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_2 -> V_20 -> V_46 ;
T_1 V_118 = 0 ;
if ( F_52 ( V_20 ) ) {
switch ( V_2 -> V_105 ) {
case V_119 :
V_118 = V_120 ;
break;
case V_121 :
V_118 = V_122 ;
break;
case V_123 :
V_118 = V_124 ;
break;
}
} else if ( F_54 ( V_2 -> V_20 ) ) {
V_118 = F_88 ( V_2 -> V_49 ) ;
} else {
V_118 = F_89 ( V_2 -> V_49 ) ;
}
F_50 ( V_118 , ( T_1 ) V_2 -> V_125 . V_126 ) ;
F_78 ( V_118 ) ;
}
static int
F_90 ( struct V_1 * V_2 ,
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
F_91 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_92 ) ;
F_4 ( V_2 , V_93 << V_94 ) ;
F_4 ( V_2 , V_2 -> V_88 ) ;
F_4 ( V_2 , V_95 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static bool
F_92 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
if ( ! V_20 -> V_110 )
return false ;
F_22 ( V_45 ) ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( V_2 -> V_112 ++ == 0 ) {
if ( F_55 ( V_20 ) && V_2 -> V_105 == V_119 )
F_56 ( V_2 , ~ ( V_2 -> V_114 |
V_86 ) ) ;
else
F_56 ( V_2 , ~ V_2 -> V_114 ) ;
V_45 -> V_113 &= ~ V_2 -> V_114 ;
F_50 ( V_115 , V_45 -> V_113 ) ;
F_78 ( V_115 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
return true ;
}
static void
F_93 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_45 = V_20 -> V_46 ;
unsigned long V_34 ;
F_77 ( & V_45 -> V_111 , V_34 ) ;
if ( -- V_2 -> V_112 == 0 ) {
if ( F_55 ( V_20 ) && V_2 -> V_105 == V_119 )
F_56 ( V_2 , ~ V_86 ) ;
else
F_56 ( V_2 , ~ 0 ) ;
V_45 -> V_113 |= V_2 -> V_114 ;
F_50 ( V_115 , V_45 -> V_113 ) ;
F_78 ( V_115 ) ;
}
F_79 ( & V_45 -> V_111 , V_34 ) ;
F_35 ( V_45 ) ;
}
static int
F_94 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_128 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_129 |
V_130 |
( V_34 & V_131 ? 0 : V_132 ) ) ;
F_4 ( V_2 , V_127 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_95 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_133 ,
unsigned V_34 )
{
int V_12 ;
if ( V_34 & V_134 ) {
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_135 ) ;
F_4 ( V_2 , V_127 | ( V_34 & V_131 ? 0 : V_136 ) ) ;
F_4 ( V_2 , V_127 + V_133 - 8 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
} else {
struct V_51 * V_52 = V_2 -> V_27 ;
T_1 V_137 = V_52 -> V_29 ;
if ( V_133 > V_138 )
return - V_139 ;
V_12 = F_3 ( V_2 , 9 + 3 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_140 |
V_141 |
V_142 ) ;
F_4 ( V_2 , V_143 | V_144 | 4096 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , ( F_96 ( V_133 , 4096 ) << 16 ) | 1024 ) ;
F_4 ( V_2 , V_137 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 4096 ) ;
F_4 ( V_2 , V_127 ) ;
F_4 ( V_2 , V_13 ) ;
F_4 ( V_2 , V_135 ) ;
F_4 ( V_2 , V_137 | ( V_34 & V_131 ? 0 : V_136 ) ) ;
F_4 ( V_2 , V_137 + V_133 - 8 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static int
F_97 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_133 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_129 | V_130 ) ;
F_4 ( V_2 , V_127 | ( V_34 & V_131 ? 0 : V_136 ) ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_51 * V_52 ;
V_52 = V_2 -> V_125 . V_52 ;
if ( V_52 == NULL )
return;
F_48 ( F_42 ( V_52 -> V_69 -> V_70 ) ) ;
F_44 ( V_52 ) ;
F_45 ( & V_52 -> V_72 ) ;
V_2 -> V_125 . V_52 = NULL ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_51 * V_52 ;
int V_12 ;
V_52 = F_38 ( V_20 , 4096 ) ;
if ( V_52 == NULL ) {
F_30 ( L_7 ) ;
V_12 = - V_64 ;
goto V_65;
}
F_39 ( V_52 , V_66 ) ;
V_12 = F_40 ( V_52 , 4096 , true , false ) ;
if ( V_12 != 0 ) {
goto V_67;
}
V_2 -> V_125 . V_126 = V_52 -> V_29 ;
V_2 -> V_125 . V_145 = F_41 ( F_42 ( V_52 -> V_69 -> V_70 ) ) ;
if ( V_2 -> V_125 . V_145 == NULL ) {
V_12 = - V_64 ;
goto V_71;
}
V_2 -> V_125 . V_52 = V_52 ;
memset ( V_2 -> V_125 . V_145 , 0 , V_55 ) ;
F_87 ( V_2 ) ;
F_43 ( L_8 ,
V_2 -> V_54 , V_2 -> V_125 . V_126 ) ;
return 0 ;
V_71:
F_44 ( V_52 ) ;
V_67:
F_45 ( & V_52 -> V_72 ) ;
V_65:
return V_12 ;
}
static int F_100 ( struct V_1 * V_2 )
{
struct V_73 * V_45 = V_2 -> V_20 -> V_46 ;
T_1 V_146 ;
if ( ! V_45 -> V_147 ) {
V_45 -> V_147 =
F_101 ( V_2 -> V_20 , V_55 , V_55 ) ;
if ( ! V_45 -> V_147 )
return - V_64 ;
}
V_146 = V_45 -> V_147 -> V_148 ;
if ( F_17 ( V_2 -> V_20 ) -> V_48 >= 4 )
V_146 |= ( V_45 -> V_147 -> V_148 >> 28 ) & 0xf0 ;
F_50 ( V_149 , V_146 ) ;
V_2 -> V_125 . V_145 = V_45 -> V_147 -> V_150 ;
memset ( V_2 -> V_125 . V_145 , 0 , V_55 ) ;
return 0 ;
}
static int F_102 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_51 * V_52 ;
struct V_73 * V_45 = V_20 -> V_46 ;
int V_12 ;
V_2 -> V_20 = V_20 ;
F_103 ( & V_2 -> V_151 ) ;
F_103 ( & V_2 -> V_152 ) ;
V_2 -> V_8 = 32 * V_55 ;
memset ( V_2 -> V_153 , 0 , sizeof( V_2 -> V_153 ) ) ;
F_104 ( & V_2 -> V_154 ) ;
if ( F_105 ( V_20 ) ) {
V_12 = F_99 ( V_2 ) ;
if ( V_12 )
return V_12 ;
} else {
F_106 ( V_2 -> V_105 != V_119 ) ;
V_12 = F_100 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
V_52 = NULL ;
if ( ! F_107 ( V_20 ) )
V_52 = F_108 ( V_20 , V_2 -> V_8 ) ;
if ( V_52 == NULL )
V_52 = F_38 ( V_20 , V_2 -> V_8 ) ;
if ( V_52 == NULL ) {
F_30 ( L_9 ) ;
V_12 = - V_64 ;
goto V_155;
}
V_2 -> V_52 = V_52 ;
V_12 = F_40 ( V_52 , V_55 , true , false ) ;
if ( V_12 )
goto V_67;
V_12 = F_109 ( V_52 , true ) ;
if ( V_12 )
goto V_71;
V_2 -> V_156 =
F_110 ( V_45 -> V_157 . V_158 + V_52 -> V_29 ,
V_2 -> V_8 ) ;
if ( V_2 -> V_156 == NULL ) {
F_30 ( L_10 ) ;
V_12 = - V_159 ;
goto V_71;
}
V_12 = V_2 -> V_160 ( V_2 ) ;
if ( V_12 )
goto V_161;
V_2 -> V_162 = V_2 -> V_8 ;
if ( F_111 ( V_2 -> V_20 ) || F_112 ( V_2 -> V_20 ) )
V_2 -> V_162 -= 128 ;
return 0 ;
V_161:
F_113 ( V_2 -> V_156 ) ;
V_71:
F_44 ( V_52 ) ;
V_67:
F_45 ( & V_52 -> V_72 ) ;
V_2 -> V_52 = NULL ;
V_155:
F_98 ( V_2 ) ;
return V_12 ;
}
void F_114 ( struct V_1 * V_2 )
{
struct V_73 * V_45 ;
int V_12 ;
if ( V_2 -> V_52 == NULL )
return;
V_45 = V_2 -> V_20 -> V_46 ;
V_12 = F_115 ( V_2 ) ;
if ( V_12 )
F_30 ( L_11 ,
V_2 -> V_54 , V_12 ) ;
F_23 ( V_2 , 0 ) ;
F_113 ( V_2 -> V_156 ) ;
F_44 ( V_2 -> V_52 ) ;
F_45 ( & V_2 -> V_52 -> V_72 ) ;
V_2 -> V_52 = NULL ;
if ( V_2 -> V_163 )
V_2 -> V_163 ( V_2 ) ;
F_98 ( V_2 ) ;
}
static int F_116 ( struct V_1 * V_2 , T_1 V_96 )
{
int V_12 ;
V_12 = F_117 ( V_2 , V_96 ) ;
if ( ! V_12 )
F_118 ( V_2 ) ;
return V_12 ;
}
static int F_119 ( struct V_1 * V_2 , int V_164 )
{
struct V_165 * V_166 ;
T_1 V_96 = 0 ;
int V_12 ;
F_118 ( V_2 ) ;
if ( V_2 -> V_62 != - 1 ) {
V_2 -> V_4 = V_2 -> V_62 ;
V_2 -> V_62 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_164 )
return 0 ;
}
F_120 (request, &ring->request_list, list) {
int V_3 ;
if ( V_166 -> V_6 == - 1 )
continue;
V_3 = V_166 -> V_6 - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
if ( V_3 >= V_164 ) {
V_96 = V_166 -> V_96 ;
break;
}
V_166 -> V_6 = - 1 ;
}
if ( V_96 == 0 )
return - V_139 ;
V_12 = F_116 ( V_2 , V_96 ) ;
if ( V_12 )
return V_12 ;
if ( F_65 ( V_2 -> V_62 == - 1 ) )
return - V_139 ;
V_2 -> V_4 = V_2 -> V_62 ;
V_2 -> V_62 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_65 ( V_2 -> V_3 < V_164 ) )
return - V_139 ;
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , int V_164 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_73 * V_45 = V_20 -> V_46 ;
unsigned long V_167 ;
int V_12 ;
V_12 = F_119 ( V_2 , V_164 ) ;
if ( V_12 != - V_139 )
return V_12 ;
F_122 ( V_2 ) ;
V_167 = V_168 + 60 * V_169 ;
do {
V_2 -> V_4 = F_25 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_164 ) {
F_123 ( V_2 ) ;
return 0 ;
}
if ( V_20 -> V_170 -> V_171 ) {
struct V_172 * V_173 = V_20 -> V_170 -> V_171 -> V_174 ;
if ( V_173 -> V_175 )
V_173 -> V_175 -> V_176 |= V_177 ;
}
F_124 ( 1 ) ;
V_12 = F_125 ( & V_45 -> V_178 ,
V_45 -> V_179 . V_180 ) ;
if ( V_12 )
return V_12 ;
} while ( ! F_126 ( V_168 , V_167 ) );
F_123 ( V_2 ) ;
return - V_181 ;
}
static int F_127 ( struct V_1 * V_2 )
{
T_3 T_4 * V_182 ;
int V_183 = V_2 -> V_8 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_183 ) {
int V_12 = F_121 ( V_2 , V_183 ) ;
if ( V_12 )
return V_12 ;
}
V_182 = V_2 -> V_156 + V_2 -> V_6 ;
V_183 /= 4 ;
while ( V_183 -- )
F_128 ( V_18 , V_182 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 )
{
T_1 V_96 ;
int V_12 ;
if ( V_2 -> V_88 ) {
V_12 = F_129 ( V_2 , NULL , NULL ) ;
if ( V_12 )
return V_12 ;
}
if ( F_130 ( & V_2 -> V_152 ) )
return 0 ;
V_96 = F_131 ( V_2 -> V_152 . V_184 ,
struct V_165 ,
V_185 ) -> V_96 ;
return F_117 ( V_2 , V_96 ) ;
}
static int
F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_88 )
return 0 ;
return F_133 ( V_2 -> V_20 , & V_2 -> V_88 ) ;
}
static int F_134 ( struct V_1 * V_2 ,
int V_186 )
{
int V_12 ;
if ( F_135 ( V_2 -> V_6 + V_186 > V_2 -> V_162 ) ) {
V_12 = F_127 ( V_2 ) ;
if ( F_135 ( V_12 ) )
return V_12 ;
}
if ( F_135 ( V_2 -> V_3 < V_186 ) ) {
V_12 = F_121 ( V_2 , V_186 ) ;
if ( F_135 ( V_12 ) )
return V_12 ;
}
V_2 -> V_3 -= V_186 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
int V_187 )
{
T_2 * V_45 = V_2 -> V_20 -> V_46 ;
int V_12 ;
V_12 = F_125 ( & V_45 -> V_178 ,
V_45 -> V_179 . V_180 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_132 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return F_134 ( V_2 , V_187 * sizeof( T_3 ) ) ;
}
void F_136 ( struct V_1 * V_2 , T_1 V_96 )
{
struct V_73 * V_45 = V_2 -> V_20 -> V_46 ;
F_106 ( V_2 -> V_88 ) ;
if ( F_17 ( V_2 -> V_20 ) -> V_48 >= 6 ) {
F_50 ( F_137 ( V_2 -> V_49 ) , 0 ) ;
F_50 ( F_138 ( V_2 -> V_49 ) , 0 ) ;
}
V_2 -> V_188 ( V_2 , V_96 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_73 * V_45 = V_2 -> V_20 -> V_46 ;
V_2 -> V_6 &= V_2 -> V_8 - 1 ;
if ( V_45 -> V_178 . V_189 & F_139 ( V_2 ) )
return;
V_2 -> V_53 ( V_2 , V_2 -> V_6 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
T_1 V_44 )
{
T_2 * V_45 = V_2 -> V_20 -> V_46 ;
F_50 ( V_190 ,
F_51 ( V_191 ) ) ;
F_141 ( V_192 , 0x0 ) ;
if ( F_32 ( ( F_19 ( V_190 ) &
V_193 ) == 0 ,
50 ) )
F_30 ( L_12 ) ;
F_15 ( V_2 , V_44 ) ;
F_78 ( F_142 ( V_2 -> V_49 ) ) ;
F_50 ( V_190 ,
F_53 ( V_191 ) ) ;
}
static int F_143 ( struct V_1 * V_2 ,
T_1 V_194 , T_1 V_195 )
{
T_3 V_11 ;
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
V_11 = V_196 ;
if ( V_194 & V_197 )
V_11 |= V_198 | V_199 |
V_200 | V_201 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_202 | V_203 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_144 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_133 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_129 | V_204 |
( V_34 & V_131 ? 0 : V_205 ) ) ;
F_4 ( V_2 , V_127 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_145 ( struct V_1 * V_2 ,
T_1 V_127 , T_1 V_133 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_129 |
( V_34 & V_131 ? 0 : V_132 ) ) ;
F_4 ( V_2 , V_127 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_146 ( struct V_1 * V_2 ,
T_1 V_194 , T_1 V_195 )
{
T_3 V_11 ;
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
V_11 = V_196 ;
if ( V_194 & V_14 )
V_11 |= V_198 | V_200 |
V_201 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_202 | V_203 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_147 ( struct V_19 * V_20 )
{
T_2 * V_45 = V_20 -> V_46 ;
struct V_1 * V_2 = & V_45 -> V_2 [ V_119 ] ;
V_2 -> V_54 = L_13 ;
V_2 -> V_105 = V_119 ;
V_2 -> V_49 = V_206 ;
if ( F_17 ( V_20 ) -> V_48 >= 6 ) {
V_2 -> V_207 = F_62 ;
V_2 -> V_195 = F_13 ;
if ( F_17 ( V_20 ) -> V_48 == 6 )
V_2 -> V_195 = F_11 ;
V_2 -> V_208 = F_92 ;
V_2 -> V_209 = F_93 ;
V_2 -> V_114 = V_210 ;
V_2 -> V_211 = F_69 ;
V_2 -> V_188 = F_72 ;
V_2 -> V_212 = F_64 ;
V_2 -> V_104 [ 0 ] = V_106 ;
V_2 -> V_104 [ 1 ] = V_213 ;
V_2 -> V_104 [ 2 ] = V_214 ;
V_2 -> V_91 [ 0 ] = V_215 ;
V_2 -> V_91 [ 1 ] = V_216 ;
} else if ( F_8 ( V_20 ) ) {
V_2 -> V_207 = F_67 ;
V_2 -> V_195 = F_6 ;
V_2 -> V_211 = F_74 ;
V_2 -> V_188 = F_75 ;
V_2 -> V_208 = F_76 ;
V_2 -> V_209 = F_80 ;
V_2 -> V_114 = V_210 | V_217 ;
} else {
V_2 -> V_207 = F_91 ;
if ( F_17 ( V_20 ) -> V_48 < 4 )
V_2 -> V_195 = F_2 ;
else
V_2 -> V_195 = F_6 ;
V_2 -> V_211 = F_71 ;
V_2 -> V_188 = F_72 ;
if ( F_148 ( V_20 ) ) {
V_2 -> V_208 = F_83 ;
V_2 -> V_209 = F_86 ;
} else {
V_2 -> V_208 = F_81 ;
V_2 -> V_209 = F_82 ;
}
V_2 -> V_114 = V_218 ;
}
V_2 -> V_53 = F_14 ;
if ( F_149 ( V_20 ) )
V_2 -> V_219 = F_144 ;
else if ( F_17 ( V_20 ) -> V_48 >= 6 )
V_2 -> V_219 = F_145 ;
else if ( F_17 ( V_20 ) -> V_48 >= 4 )
V_2 -> V_219 = F_94 ;
else if ( F_111 ( V_20 ) || F_112 ( V_20 ) )
V_2 -> V_219 = F_95 ;
else
V_2 -> V_219 = F_97 ;
V_2 -> V_160 = F_49 ;
V_2 -> V_163 = F_57 ;
if ( F_58 ( V_20 ) ) {
struct V_51 * V_52 ;
int V_12 ;
V_52 = F_38 ( V_20 , V_138 ) ;
if ( V_52 == NULL ) {
F_30 ( L_14 ) ;
return - V_64 ;
}
V_12 = F_40 ( V_52 , 0 , true , false ) ;
if ( V_12 != 0 ) {
F_45 ( & V_52 -> V_72 ) ;
F_30 ( L_15 ) ;
return V_12 ;
}
V_2 -> V_27 = V_52 ;
}
return F_102 ( V_20 , V_2 ) ;
}
int F_150 ( struct V_19 * V_20 , T_5 V_220 , T_1 V_8 )
{
T_2 * V_45 = V_20 -> V_46 ;
struct V_1 * V_2 = & V_45 -> V_2 [ V_119 ] ;
int V_12 ;
V_2 -> V_54 = L_13 ;
V_2 -> V_105 = V_119 ;
V_2 -> V_49 = V_206 ;
if ( F_17 ( V_20 ) -> V_48 >= 6 ) {
return - V_221 ;
}
V_2 -> V_207 = F_91 ;
if ( F_17 ( V_20 ) -> V_48 < 4 )
V_2 -> V_195 = F_2 ;
else
V_2 -> V_195 = F_6 ;
V_2 -> V_211 = F_71 ;
V_2 -> V_188 = F_72 ;
if ( F_148 ( V_20 ) ) {
V_2 -> V_208 = F_83 ;
V_2 -> V_209 = F_86 ;
} else {
V_2 -> V_208 = F_81 ;
V_2 -> V_209 = F_82 ;
}
V_2 -> V_114 = V_218 ;
V_2 -> V_53 = F_14 ;
if ( F_17 ( V_20 ) -> V_48 >= 4 )
V_2 -> V_219 = F_94 ;
else if ( F_111 ( V_20 ) || F_112 ( V_20 ) )
V_2 -> V_219 = F_95 ;
else
V_2 -> V_219 = F_97 ;
V_2 -> V_160 = F_49 ;
V_2 -> V_163 = F_57 ;
V_2 -> V_20 = V_20 ;
F_103 ( & V_2 -> V_151 ) ;
F_103 ( & V_2 -> V_152 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_162 = V_2 -> V_8 ;
if ( F_111 ( V_2 -> V_20 ) || F_112 ( V_2 -> V_20 ) )
V_2 -> V_162 -= 128 ;
V_2 -> V_156 = F_110 ( V_220 , V_8 ) ;
if ( V_2 -> V_156 == NULL ) {
F_30 ( L_16
L_17 ) ;
return - V_64 ;
}
if ( ! F_105 ( V_20 ) ) {
V_12 = F_100 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
int F_151 ( struct V_19 * V_20 )
{
T_2 * V_45 = V_20 -> V_46 ;
struct V_1 * V_2 = & V_45 -> V_2 [ V_123 ] ;
V_2 -> V_54 = L_18 ;
V_2 -> V_105 = V_123 ;
V_2 -> V_53 = F_14 ;
if ( F_54 ( V_20 ) || F_52 ( V_20 ) ) {
V_2 -> V_49 = V_222 ;
if ( F_54 ( V_20 ) )
V_2 -> V_53 = F_140 ;
V_2 -> V_195 = F_143 ;
V_2 -> V_207 = F_62 ;
V_2 -> V_211 = F_69 ;
V_2 -> V_188 = F_72 ;
V_2 -> V_114 = V_223 ;
V_2 -> V_208 = F_92 ;
V_2 -> V_209 = F_93 ;
V_2 -> V_219 = F_145 ;
V_2 -> V_212 = F_64 ;
V_2 -> V_104 [ 0 ] = V_224 ;
V_2 -> V_104 [ 1 ] = V_106 ;
V_2 -> V_104 [ 2 ] = V_225 ;
V_2 -> V_91 [ 0 ] = V_226 ;
V_2 -> V_91 [ 1 ] = V_227 ;
} else {
V_2 -> V_49 = V_228 ;
V_2 -> V_195 = F_90 ;
V_2 -> V_207 = F_91 ;
V_2 -> V_211 = F_71 ;
V_2 -> V_188 = F_72 ;
if ( F_8 ( V_20 ) ) {
V_2 -> V_114 = V_229 ;
V_2 -> V_208 = F_76 ;
V_2 -> V_209 = F_80 ;
} else {
V_2 -> V_114 = V_230 ;
V_2 -> V_208 = F_81 ;
V_2 -> V_209 = F_82 ;
}
V_2 -> V_219 = F_94 ;
}
V_2 -> V_160 = F_20 ;
return F_102 ( V_20 , V_2 ) ;
}
int F_152 ( struct V_19 * V_20 )
{
T_2 * V_45 = V_20 -> V_46 ;
struct V_1 * V_2 = & V_45 -> V_2 [ V_121 ] ;
V_2 -> V_54 = L_19 ;
V_2 -> V_105 = V_121 ;
V_2 -> V_49 = V_231 ;
V_2 -> V_53 = F_14 ;
V_2 -> V_195 = F_146 ;
V_2 -> V_207 = F_62 ;
V_2 -> V_211 = F_69 ;
V_2 -> V_188 = F_72 ;
V_2 -> V_114 = V_232 ;
V_2 -> V_208 = F_92 ;
V_2 -> V_209 = F_93 ;
V_2 -> V_219 = F_145 ;
V_2 -> V_212 = F_64 ;
V_2 -> V_104 [ 0 ] = V_233 ;
V_2 -> V_104 [ 1 ] = V_234 ;
V_2 -> V_104 [ 2 ] = V_106 ;
V_2 -> V_91 [ 0 ] = V_235 ;
V_2 -> V_91 [ 1 ] = V_236 ;
V_2 -> V_160 = F_20 ;
return F_102 ( V_20 , V_2 ) ;
}
int
F_153 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_237 )
return 0 ;
V_12 = V_2 -> V_195 ( V_2 , 0 , V_197 ) ;
if ( V_12 )
return V_12 ;
F_154 ( V_2 , 0 , V_197 ) ;
V_2 -> V_237 = false ;
return 0 ;
}
int
F_155 ( struct V_1 * V_2 )
{
T_3 V_10 ;
int V_12 ;
V_10 = 0 ;
if ( V_2 -> V_237 )
V_10 = V_197 ;
V_12 = V_2 -> V_195 ( V_2 , V_197 , V_10 ) ;
if ( V_12 )
return V_12 ;
F_154 ( V_2 , V_197 , V_10 ) ;
V_2 -> V_237 = false ;
return 0 ;
}
