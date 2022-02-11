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
static void F_12 ( struct V_1 * V_2 ,
T_1 V_42 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
F_13 ( V_2 , V_42 ) ;
}
T_1 F_14 ( struct V_1 * V_2 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
T_1 V_45 = F_15 ( V_2 -> V_19 ) -> V_46 >= 4 ?
F_16 ( V_2 -> V_47 ) : V_48 ;
return F_17 ( V_45 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
struct V_49 * V_50 = V_2 -> V_50 ;
int V_11 = 0 ;
T_1 V_4 ;
if ( F_19 ( V_19 ) )
F_20 ( V_43 ) ;
F_21 ( V_2 , 0 ) ;
F_22 ( V_2 , 0 ) ;
V_2 -> V_51 ( V_2 , 0 ) ;
V_4 = F_23 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_24 ( L_1
L_2 ,
V_2 -> V_52 ,
F_25 ( V_2 ) ,
F_23 ( V_2 ) ,
F_26 ( V_2 ) ,
F_27 ( V_2 ) ) ;
F_22 ( V_2 , 0 ) ;
if ( F_23 ( V_2 ) & V_5 ) {
F_28 ( L_3
L_2 ,
V_2 -> V_52 ,
F_25 ( V_2 ) ,
F_23 ( V_2 ) ,
F_26 ( V_2 ) ,
F_27 ( V_2 ) ) ;
}
}
F_29 ( V_2 , V_50 -> V_28 ) ;
F_21 ( V_2 ,
( ( V_2 -> V_7 - V_53 ) & V_54 )
| V_55 ) ;
if ( F_30 ( ( F_25 ( V_2 ) & V_55 ) != 0 &&
F_27 ( V_2 ) == V_50 -> V_28 &&
( F_23 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_28 ( L_4
L_2 ,
V_2 -> V_52 ,
F_25 ( V_2 ) ,
F_23 ( V_2 ) ,
F_26 ( V_2 ) ,
F_27 ( V_2 ) ) ;
V_11 = - V_56 ;
goto V_57;
}
if ( ! F_31 ( V_2 -> V_19 , V_58 ) )
F_32 ( V_2 -> V_19 ) ;
else {
V_2 -> V_4 = F_23 ( V_2 ) ;
V_2 -> V_6 = F_26 ( V_2 ) & V_59 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_60 = - 1 ;
}
V_57:
if ( F_19 ( V_19 ) )
F_33 ( V_43 ) ;
return V_11 ;
}
static int
F_34 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_49 * V_50 ;
int V_11 ;
if ( V_2 -> V_26 )
return 0 ;
V_25 = F_35 ( sizeof( * V_25 ) , V_61 ) ;
if ( ! V_25 )
return - V_62 ;
V_50 = F_36 ( V_2 -> V_19 , 4096 ) ;
if ( V_50 == NULL ) {
F_28 ( L_5 ) ;
V_11 = - V_62 ;
goto V_63;
}
F_37 ( V_50 , V_64 ) ;
V_11 = F_38 ( V_50 , 4096 , true ) ;
if ( V_11 )
goto V_65;
V_25 -> V_28 = V_50 -> V_28 ;
V_25 -> V_66 = F_39 ( V_50 -> V_67 [ 0 ] ) ;
if ( V_25 -> V_66 == NULL )
goto V_68;
V_25 -> V_50 = V_50 ;
V_2 -> V_26 = V_25 ;
return 0 ;
V_68:
F_40 ( V_50 ) ;
V_65:
F_41 ( & V_50 -> V_69 ) ;
V_63:
F_42 ( V_25 ) ;
return V_11 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_49 * V_50 ;
if ( ! V_2 -> V_26 )
return;
V_50 = V_25 -> V_50 ;
F_44 ( V_50 -> V_67 [ 0 ] ) ;
F_40 ( V_50 ) ;
F_41 ( & V_50 -> V_69 ) ;
F_42 ( V_25 ) ;
V_2 -> V_26 = NULL ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_70 * V_43 = V_19 -> V_44 ;
int V_11 = F_18 ( V_2 ) ;
if ( F_15 ( V_19 ) -> V_46 > 3 ) {
F_46 ( V_71 , F_47 ( V_72 ) ) ;
if ( F_48 ( V_19 ) )
F_46 ( V_73 ,
F_49 ( V_74 ) |
F_47 ( V_75 ) ) ;
}
if ( F_15 ( V_19 ) -> V_46 >= 5 ) {
V_11 = F_34 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_50 ( V_19 ) ) {
F_46 ( V_76 ,
F_49 ( V_77 ) ) ;
V_2 -> V_78 =
! ! ( F_17 ( V_79 ) & V_74 ) ;
}
if ( F_15 ( V_19 ) -> V_46 >= 6 )
F_46 ( V_80 , F_47 ( V_81 ) ) ;
if ( F_51 ( V_19 ) )
F_52 ( V_2 , ~ V_82 ) ;
return V_11 ;
}
static void F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_26 )
return;
F_43 ( V_2 ) ;
}
static void
F_54 ( struct V_1 * V_2 ,
T_1 V_83 ,
T_1 V_84 )
{
F_4 ( V_2 , V_85 |
V_86 |
V_87 |
V_88 ) ;
F_4 ( V_2 , V_83 ) ;
F_4 ( V_2 , V_84 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
T_1 * V_83 )
{
T_1 V_89 ;
T_1 V_90 ;
int V_11 ;
V_11 = F_3 ( V_2 , 10 ) ;
if ( V_11 )
return V_11 ;
V_89 = V_2 -> V_91 [ 0 ] ;
V_90 = V_2 -> V_91 [ 1 ] ;
* V_83 = F_56 ( V_2 ) ;
F_54 ( V_2 , * V_83 , V_89 ) ;
F_54 ( V_2 , * V_83 , V_90 ) ;
F_4 ( V_2 , V_92 ) ;
F_4 ( V_2 , V_93 << V_94 ) ;
F_4 ( V_2 , * V_83 ) ;
F_4 ( V_2 , V_95 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_96 ,
struct V_1 * V_97 ,
T_1 V_83 )
{
int V_11 ;
T_1 V_98 = V_85 |
V_99 |
V_87 ;
V_83 -= 1 ;
F_58 ( V_97 -> V_100 [ V_96 -> V_101 ] ==
V_102 ) ;
V_11 = F_3 ( V_96 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_96 ,
V_98 | V_97 -> V_100 [ V_96 -> V_101 ] ) ;
F_4 ( V_96 , V_83 ) ;
F_4 ( V_96 , 0 ) ;
F_4 ( V_96 , V_17 ) ;
F_5 ( V_96 ) ;
return 0 ;
}
static int
F_59 ( struct V_1 * V_2 ,
T_1 * V_103 )
{
T_1 V_83 = F_56 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_26 ;
T_1 V_27 = V_25 -> V_28 + 128 ;
int V_11 ;
V_11 = F_3 ( V_2 , 32 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 4 ) | V_32 |
V_104 |
V_38 ) ;
F_4 ( V_2 , V_25 -> V_28 | V_31 ) ;
F_4 ( V_2 , V_83 ) ;
F_4 ( V_2 , 0 ) ;
F_60 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_60 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_60 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_60 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_60 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_60 ( V_2 , V_27 ) ;
F_4 ( V_2 , F_10 ( 4 ) | V_32 |
V_104 |
V_38 |
V_105 ) ;
F_4 ( V_2 , V_25 -> V_28 | V_31 ) ;
F_4 ( V_2 , V_83 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
* V_103 = V_83 ;
return 0 ;
}
static T_1
F_61 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
if ( F_50 ( V_19 ) || F_48 ( V_19 ) )
F_14 ( V_2 ) ;
return F_62 ( V_2 , V_93 ) ;
}
static T_1
F_63 ( struct V_1 * V_2 )
{
return F_62 ( V_2 , V_93 ) ;
}
static T_1
F_64 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
return V_25 -> V_66 [ 0 ] ;
}
static bool
F_65 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_106 )
return false ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( V_2 -> V_108 ++ == 0 ) {
V_43 -> V_109 &= ~ V_2 -> V_110 ;
F_46 ( V_111 , V_43 -> V_109 ) ;
F_67 ( V_111 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
return true ;
}
static void
F_69 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( -- V_2 -> V_108 == 0 ) {
V_43 -> V_109 |= V_2 -> V_110 ;
F_46 ( V_111 , V_43 -> V_109 ) ;
F_67 ( V_111 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
}
static bool
F_70 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_106 )
return false ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( V_2 -> V_108 ++ == 0 ) {
V_43 -> V_112 &= ~ V_2 -> V_110 ;
F_46 ( V_113 , V_43 -> V_112 ) ;
F_67 ( V_113 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
return true ;
}
static void
F_71 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( -- V_2 -> V_108 == 0 ) {
V_43 -> V_112 |= V_2 -> V_110 ;
F_46 ( V_113 , V_43 -> V_112 ) ;
F_67 ( V_113 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
}
static bool
F_72 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_106 )
return false ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( V_2 -> V_108 ++ == 0 ) {
V_43 -> V_112 &= ~ V_2 -> V_110 ;
F_73 ( V_113 , V_43 -> V_112 ) ;
F_74 ( V_113 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
return true ;
}
static void
F_75 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( -- V_2 -> V_108 == 0 ) {
V_43 -> V_112 |= V_2 -> V_110 ;
F_73 ( V_113 , V_43 -> V_112 ) ;
F_74 ( V_113 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
}
void F_76 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
T_1 V_114 = 0 ;
if ( F_48 ( V_19 ) ) {
switch ( V_2 -> V_101 ) {
case V_115 :
V_114 = V_116 ;
break;
case V_117 :
V_114 = V_118 ;
break;
case V_119 :
V_114 = V_120 ;
break;
}
} else if ( F_50 ( V_2 -> V_19 ) ) {
V_114 = F_77 ( V_2 -> V_47 ) ;
} else {
V_114 = F_78 ( V_2 -> V_47 ) ;
}
F_46 ( V_114 , ( T_1 ) V_2 -> V_121 . V_122 ) ;
F_67 ( V_114 ) ;
}
static int
F_79 ( struct V_1 * V_2 ,
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
F_80 ( struct V_1 * V_2 ,
T_1 * V_103 )
{
T_1 V_83 ;
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_83 = F_56 ( V_2 ) ;
F_4 ( V_2 , V_92 ) ;
F_4 ( V_2 , V_93 << V_94 ) ;
F_4 ( V_2 , V_83 ) ;
F_4 ( V_2 , V_95 ) ;
F_5 ( V_2 ) ;
* V_103 = V_83 ;
return 0 ;
}
static bool
F_81 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
if ( ! V_19 -> V_106 )
return false ;
F_20 ( V_43 ) ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( V_2 -> V_108 ++ == 0 ) {
if ( F_51 ( V_19 ) && V_2 -> V_101 == V_115 )
F_52 ( V_2 , ~ ( V_2 -> V_110 |
V_82 ) ) ;
else
F_52 ( V_2 , ~ V_2 -> V_110 ) ;
V_43 -> V_109 &= ~ V_2 -> V_110 ;
F_46 ( V_111 , V_43 -> V_109 ) ;
F_67 ( V_111 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
return true ;
}
static void
F_82 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_43 = V_19 -> V_44 ;
unsigned long V_33 ;
F_66 ( & V_43 -> V_107 , V_33 ) ;
if ( -- V_2 -> V_108 == 0 ) {
if ( F_51 ( V_19 ) && V_2 -> V_101 == V_115 )
F_52 ( V_2 , ~ V_82 ) ;
else
F_52 ( V_2 , ~ 0 ) ;
V_43 -> V_109 |= V_2 -> V_110 ;
F_46 ( V_111 , V_43 -> V_109 ) ;
F_67 ( V_111 ) ;
}
F_68 ( & V_43 -> V_107 , V_33 ) ;
F_33 ( V_43 ) ;
}
static int
F_83 ( struct V_1 * V_2 , T_1 V_123 , T_1 V_124 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 ,
V_125 |
V_126 |
V_127 ) ;
F_4 ( V_2 , V_123 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_84 ( struct V_1 * V_2 ,
T_1 V_123 , T_1 V_128 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_129 ) ;
F_4 ( V_2 , V_123 | V_130 ) ;
F_4 ( V_2 , V_123 + V_128 - 8 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_85 ( struct V_1 * V_2 ,
T_1 V_123 , T_1 V_128 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_125 | V_126 ) ;
F_4 ( V_2 , V_123 | V_130 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_49 * V_50 ;
V_50 = V_2 -> V_121 . V_50 ;
if ( V_50 == NULL )
return;
F_44 ( V_50 -> V_67 [ 0 ] ) ;
F_40 ( V_50 ) ;
F_41 ( & V_50 -> V_69 ) ;
V_2 -> V_121 . V_50 = NULL ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_49 * V_50 ;
int V_11 ;
V_50 = F_36 ( V_19 , 4096 ) ;
if ( V_50 == NULL ) {
F_28 ( L_6 ) ;
V_11 = - V_62 ;
goto V_63;
}
F_37 ( V_50 , V_64 ) ;
V_11 = F_38 ( V_50 , 4096 , true ) ;
if ( V_11 != 0 ) {
goto V_65;
}
V_2 -> V_121 . V_122 = V_50 -> V_28 ;
V_2 -> V_121 . V_131 = F_39 ( V_50 -> V_67 [ 0 ] ) ;
if ( V_2 -> V_121 . V_131 == NULL ) {
V_11 = - V_62 ;
goto V_68;
}
V_2 -> V_121 . V_50 = V_50 ;
memset ( V_2 -> V_121 . V_131 , 0 , V_53 ) ;
F_76 ( V_2 ) ;
F_88 ( L_7 ,
V_2 -> V_52 , V_2 -> V_121 . V_122 ) ;
return 0 ;
V_68:
F_40 ( V_50 ) ;
V_65:
F_41 ( & V_50 -> V_69 ) ;
V_63:
return V_11 ;
}
static int F_89 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_49 * V_50 ;
struct V_70 * V_43 = V_19 -> V_44 ;
int V_11 ;
V_2 -> V_19 = V_19 ;
F_90 ( & V_2 -> V_132 ) ;
F_90 ( & V_2 -> V_133 ) ;
F_90 ( & V_2 -> V_134 ) ;
V_2 -> V_7 = 32 * V_53 ;
F_91 ( & V_2 -> V_135 ) ;
if ( F_92 ( V_19 ) ) {
V_11 = F_87 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
V_50 = F_36 ( V_19 , V_2 -> V_7 ) ;
if ( V_50 == NULL ) {
F_28 ( L_8 ) ;
V_11 = - V_62 ;
goto V_136;
}
V_2 -> V_50 = V_50 ;
V_11 = F_38 ( V_50 , V_53 , true ) ;
if ( V_11 )
goto V_65;
V_11 = F_93 ( V_50 , true ) ;
if ( V_11 )
goto V_68;
V_2 -> V_137 =
F_94 ( V_43 -> V_138 . V_139 -> V_140 + V_50 -> V_28 ,
V_2 -> V_7 ) ;
if ( V_2 -> V_137 == NULL ) {
F_28 ( L_9 ) ;
V_11 = - V_141 ;
goto V_68;
}
V_11 = V_2 -> V_142 ( V_2 ) ;
if ( V_11 )
goto V_143;
V_2 -> V_144 = V_2 -> V_7 ;
if ( F_95 ( V_2 -> V_19 ) || F_96 ( V_2 -> V_19 ) )
V_2 -> V_144 -= 128 ;
return 0 ;
V_143:
F_97 ( V_2 -> V_137 ) ;
V_68:
F_40 ( V_50 ) ;
V_65:
F_41 ( & V_50 -> V_69 ) ;
V_2 -> V_50 = NULL ;
V_136:
F_86 ( V_2 ) ;
return V_11 ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_70 * V_43 ;
int V_11 ;
if ( V_2 -> V_50 == NULL )
return;
V_43 = V_2 -> V_19 -> V_44 ;
V_11 = F_99 ( V_2 ) ;
if ( V_11 )
F_28 ( L_10 ,
V_2 -> V_52 , V_11 ) ;
F_21 ( V_2 , 0 ) ;
F_97 ( V_2 -> V_137 ) ;
F_40 ( V_2 -> V_50 ) ;
F_41 ( & V_2 -> V_50 -> V_69 ) ;
V_2 -> V_50 = NULL ;
if ( V_2 -> V_145 )
V_2 -> V_145 ( V_2 ) ;
F_86 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
T_3 T_4 * V_146 ;
int V_147 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_147 ) {
int V_11 = F_101 ( V_2 , V_147 ) ;
if ( V_11 )
return V_11 ;
}
V_146 = V_2 -> V_137 + V_2 -> V_6 ;
V_147 /= 4 ;
while ( V_147 -- )
F_102 ( V_17 , V_146 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
static int F_103 ( struct V_1 * V_2 , T_1 V_83 )
{
int V_11 ;
V_11 = F_104 ( V_2 , V_83 ) ;
if ( ! V_11 )
F_105 ( V_2 ) ;
return V_11 ;
}
static int F_106 ( struct V_1 * V_2 , int V_148 )
{
struct V_149 * V_150 ;
T_1 V_83 = 0 ;
int V_11 ;
F_105 ( V_2 ) ;
if ( V_2 -> V_60 != - 1 ) {
V_2 -> V_4 = V_2 -> V_60 ;
V_2 -> V_60 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_148 )
return 0 ;
}
F_107 (request, &ring->request_list, list) {
int V_3 ;
if ( V_150 -> V_6 == - 1 )
continue;
V_3 = V_150 -> V_6 - ( V_2 -> V_6 + 8 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_7 ;
if ( V_3 >= V_148 ) {
V_83 = V_150 -> V_83 ;
break;
}
V_150 -> V_6 = - 1 ;
}
if ( V_83 == 0 )
return - V_151 ;
V_11 = F_103 ( V_2 , V_83 ) ;
if ( V_11 )
return V_11 ;
if ( F_58 ( V_2 -> V_60 == - 1 ) )
return - V_151 ;
V_2 -> V_4 = V_2 -> V_60 ;
V_2 -> V_60 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_58 ( V_2 -> V_3 < V_148 ) )
return - V_151 ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_148 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_70 * V_43 = V_19 -> V_44 ;
unsigned long V_152 ;
int V_11 ;
V_11 = F_106 ( V_2 , V_148 ) ;
if ( V_11 != - V_151 )
return V_11 ;
F_108 ( V_2 ) ;
V_152 = V_153 + 60 * V_154 ;
do {
V_2 -> V_4 = F_23 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_148 ) {
F_109 ( V_2 ) ;
return 0 ;
}
if ( V_19 -> V_155 -> V_156 ) {
struct V_157 * V_158 = V_19 -> V_155 -> V_156 -> V_159 ;
if ( V_158 -> V_160 )
V_158 -> V_160 -> V_161 |= V_162 ;
}
F_110 ( 1 ) ;
V_11 = F_111 ( V_43 , V_43 -> V_138 . V_163 ) ;
if ( V_11 )
return V_11 ;
} while ( ! F_112 ( V_153 , V_152 ) );
F_109 ( V_2 ) ;
return - V_164 ;
}
int F_3 ( struct V_1 * V_2 ,
int V_165 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
int V_148 = 4 * V_165 ;
int V_11 ;
V_11 = F_111 ( V_43 , V_43 -> V_138 . V_163 ) ;
if ( V_11 )
return V_11 ;
if ( F_113 ( V_2 -> V_6 + V_148 > V_2 -> V_144 ) ) {
V_11 = F_100 ( V_2 ) ;
if ( F_113 ( V_11 ) )
return V_11 ;
}
if ( F_113 ( V_2 -> V_3 < V_148 ) ) {
V_11 = F_101 ( V_2 , V_148 ) ;
if ( F_113 ( V_11 ) )
return V_11 ;
}
V_2 -> V_3 -= V_148 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_70 * V_43 = V_2 -> V_19 -> V_44 ;
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
if ( V_43 -> V_166 & F_114 ( V_2 ) )
return;
V_2 -> V_51 ( V_2 , V_2 -> V_6 ) ;
}
static void F_115 ( struct V_1 * V_2 ,
T_1 V_42 )
{
T_2 * V_43 = V_2 -> V_19 -> V_44 ;
F_46 ( V_167 ,
F_47 ( V_168 ) ) ;
F_116 ( V_169 , 0x0 ) ;
if ( F_30 ( ( F_17 ( V_167 ) &
V_170 ) == 0 ,
50 ) )
F_28 ( L_11 ) ;
F_13 ( V_2 , V_42 ) ;
F_67 ( F_117 ( V_2 -> V_47 ) ) ;
F_46 ( V_167 ,
F_49 ( V_168 ) ) ;
}
static int F_118 ( struct V_1 * V_2 ,
T_1 V_171 , T_1 V_172 )
{
T_3 V_10 ;
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_10 = V_173 ;
if ( V_171 & V_174 )
V_10 |= V_175 | V_176 ;
F_4 ( V_2 , V_10 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_119 ( struct V_1 * V_2 ,
T_1 V_123 , T_1 V_128 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_125 | V_127 ) ;
F_4 ( V_2 , V_123 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 ,
T_1 V_171 , T_1 V_172 )
{
T_3 V_10 ;
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_10 = V_173 ;
if ( V_171 & V_13 )
V_10 |= V_175 ;
F_4 ( V_2 , V_10 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_121 ( struct V_18 * V_19 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_115 ] ;
V_2 -> V_52 = L_12 ;
V_2 -> V_101 = V_115 ;
V_2 -> V_47 = V_177 ;
if ( F_15 ( V_19 ) -> V_46 >= 6 ) {
V_2 -> V_178 = F_55 ;
V_2 -> V_172 = F_11 ;
V_2 -> V_179 = F_81 ;
V_2 -> V_180 = F_82 ;
V_2 -> V_110 = V_181 ;
V_2 -> V_182 = F_61 ;
V_2 -> V_183 = F_57 ;
V_2 -> V_100 [ 0 ] = V_102 ;
V_2 -> V_100 [ 1 ] = V_184 ;
V_2 -> V_100 [ 2 ] = V_185 ;
V_2 -> V_91 [ 0 ] = V_186 ;
V_2 -> V_91 [ 1 ] = V_187 ;
} else if ( F_8 ( V_19 ) ) {
V_2 -> V_178 = F_59 ;
V_2 -> V_172 = F_6 ;
V_2 -> V_182 = F_64 ;
V_2 -> V_179 = F_65 ;
V_2 -> V_180 = F_69 ;
V_2 -> V_110 = V_181 | V_188 ;
} else {
V_2 -> V_178 = F_80 ;
if ( F_15 ( V_19 ) -> V_46 < 4 )
V_2 -> V_172 = F_2 ;
else
V_2 -> V_172 = F_6 ;
V_2 -> V_182 = F_63 ;
if ( F_122 ( V_19 ) ) {
V_2 -> V_179 = F_72 ;
V_2 -> V_180 = F_75 ;
} else {
V_2 -> V_179 = F_70 ;
V_2 -> V_180 = F_71 ;
}
V_2 -> V_110 = V_189 ;
}
V_2 -> V_51 = F_12 ;
if ( F_15 ( V_19 ) -> V_46 >= 6 )
V_2 -> V_190 = F_119 ;
else if ( F_15 ( V_19 ) -> V_46 >= 4 )
V_2 -> V_190 = F_83 ;
else if ( F_95 ( V_19 ) || F_96 ( V_19 ) )
V_2 -> V_190 = F_84 ;
else
V_2 -> V_190 = F_85 ;
V_2 -> V_142 = F_45 ;
V_2 -> V_145 = F_53 ;
if ( ! F_92 ( V_19 ) ) {
V_2 -> V_121 . V_131 = V_43 -> V_191 -> V_192 ;
memset ( V_2 -> V_121 . V_131 , 0 , V_53 ) ;
}
return F_89 ( V_19 , V_2 ) ;
}
int F_123 ( struct V_18 * V_19 , T_5 V_193 , T_1 V_7 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_115 ] ;
V_2 -> V_52 = L_12 ;
V_2 -> V_101 = V_115 ;
V_2 -> V_47 = V_177 ;
if ( F_15 ( V_19 ) -> V_46 >= 6 ) {
return - V_194 ;
}
V_2 -> V_178 = F_80 ;
if ( F_15 ( V_19 ) -> V_46 < 4 )
V_2 -> V_172 = F_2 ;
else
V_2 -> V_172 = F_6 ;
V_2 -> V_182 = F_63 ;
if ( F_122 ( V_19 ) ) {
V_2 -> V_179 = F_72 ;
V_2 -> V_180 = F_75 ;
} else {
V_2 -> V_179 = F_70 ;
V_2 -> V_180 = F_71 ;
}
V_2 -> V_110 = V_189 ;
V_2 -> V_51 = F_12 ;
if ( F_15 ( V_19 ) -> V_46 >= 4 )
V_2 -> V_190 = F_83 ;
else if ( F_95 ( V_19 ) || F_96 ( V_19 ) )
V_2 -> V_190 = F_84 ;
else
V_2 -> V_190 = F_85 ;
V_2 -> V_142 = F_45 ;
V_2 -> V_145 = F_53 ;
if ( ! F_92 ( V_19 ) )
V_2 -> V_121 . V_131 = V_43 -> V_191 -> V_192 ;
V_2 -> V_19 = V_19 ;
F_90 ( & V_2 -> V_132 ) ;
F_90 ( & V_2 -> V_133 ) ;
F_90 ( & V_2 -> V_134 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_144 = V_2 -> V_7 ;
if ( F_95 ( V_2 -> V_19 ) )
V_2 -> V_144 -= 128 ;
V_2 -> V_137 = F_94 ( V_193 , V_7 ) ;
if ( V_2 -> V_137 == NULL ) {
F_28 ( L_13
L_14 ) ;
return - V_62 ;
}
return 0 ;
}
int F_124 ( struct V_18 * V_19 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_119 ] ;
V_2 -> V_52 = L_15 ;
V_2 -> V_101 = V_119 ;
V_2 -> V_51 = F_12 ;
if ( F_50 ( V_19 ) || F_48 ( V_19 ) ) {
V_2 -> V_47 = V_195 ;
if ( F_50 ( V_19 ) )
V_2 -> V_51 = F_115 ;
V_2 -> V_172 = F_118 ;
V_2 -> V_178 = F_55 ;
V_2 -> V_182 = F_61 ;
V_2 -> V_110 = V_196 ;
V_2 -> V_179 = F_81 ;
V_2 -> V_180 = F_82 ;
V_2 -> V_190 = F_119 ;
V_2 -> V_183 = F_57 ;
V_2 -> V_100 [ 0 ] = V_197 ;
V_2 -> V_100 [ 1 ] = V_102 ;
V_2 -> V_100 [ 2 ] = V_198 ;
V_2 -> V_91 [ 0 ] = V_199 ;
V_2 -> V_91 [ 1 ] = V_200 ;
} else {
V_2 -> V_47 = V_201 ;
V_2 -> V_172 = F_79 ;
V_2 -> V_178 = F_80 ;
V_2 -> V_182 = F_63 ;
if ( F_8 ( V_19 ) ) {
V_2 -> V_110 = V_202 ;
V_2 -> V_179 = F_65 ;
V_2 -> V_180 = F_69 ;
} else {
V_2 -> V_110 = V_203 ;
V_2 -> V_179 = F_70 ;
V_2 -> V_180 = F_71 ;
}
V_2 -> V_190 = F_83 ;
}
V_2 -> V_142 = F_18 ;
return F_89 ( V_19 , V_2 ) ;
}
int F_125 ( struct V_18 * V_19 )
{
T_2 * V_43 = V_19 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_117 ] ;
V_2 -> V_52 = L_16 ;
V_2 -> V_101 = V_117 ;
V_2 -> V_47 = V_204 ;
V_2 -> V_51 = F_12 ;
V_2 -> V_172 = F_120 ;
V_2 -> V_178 = F_55 ;
V_2 -> V_182 = F_61 ;
V_2 -> V_110 = V_205 ;
V_2 -> V_179 = F_81 ;
V_2 -> V_180 = F_82 ;
V_2 -> V_190 = F_119 ;
V_2 -> V_183 = F_57 ;
V_2 -> V_100 [ 0 ] = V_206 ;
V_2 -> V_100 [ 1 ] = V_207 ;
V_2 -> V_100 [ 2 ] = V_102 ;
V_2 -> V_91 [ 0 ] = V_208 ;
V_2 -> V_91 [ 1 ] = V_209 ;
V_2 -> V_142 = F_18 ;
return F_89 ( V_19 , V_2 ) ;
}
