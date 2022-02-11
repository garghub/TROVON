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
F_9 ( V_2 ) ;
V_33 |= V_34 ;
V_33 |= V_35 ;
V_33 |= V_36 ;
V_33 |= V_37 ;
V_33 |= V_38 ;
V_33 |= V_39 ;
V_33 |= V_40 ;
V_11 = F_3 ( V_2 , 6 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 5 ) ) ;
F_4 ( V_2 , V_33 ) ;
F_4 ( V_2 , V_27 | V_31 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_17 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 V_41 )
{
T_2 * V_42 = V_2 -> V_19 -> V_43 ;
F_13 ( V_2 , V_41 ) ;
}
T_1 F_14 ( struct V_1 * V_2 )
{
T_2 * V_42 = V_2 -> V_19 -> V_43 ;
T_1 V_44 = F_15 ( V_2 -> V_19 ) -> V_45 >= 4 ?
F_16 ( V_2 -> V_46 ) : V_47 ;
return F_17 ( V_44 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
struct V_48 * V_49 = V_2 -> V_49 ;
int V_11 = 0 ;
T_1 V_4 ;
if ( F_19 ( V_19 ) )
F_20 ( V_42 ) ;
F_21 ( V_2 , 0 ) ;
F_22 ( V_2 , 0 ) ;
V_2 -> V_50 ( V_2 , 0 ) ;
F_23 ( V_2 , V_49 -> V_28 ) ;
V_4 = F_24 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_25 ( L_1
L_2 ,
V_2 -> V_51 ,
F_26 ( V_2 ) ,
F_24 ( V_2 ) ,
F_27 ( V_2 ) ,
F_28 ( V_2 ) ) ;
F_22 ( V_2 , 0 ) ;
if ( F_24 ( V_2 ) & V_5 ) {
F_29 ( L_3
L_2 ,
V_2 -> V_51 ,
F_26 ( V_2 ) ,
F_24 ( V_2 ) ,
F_27 ( V_2 ) ,
F_28 ( V_2 ) ) ;
}
}
F_21 ( V_2 ,
( ( V_2 -> V_7 - V_52 ) & V_53 )
| V_54 ) ;
if ( F_30 ( ( F_26 ( V_2 ) & V_54 ) != 0 &&
F_28 ( V_2 ) == V_49 -> V_28 &&
( F_24 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_29 ( L_4
L_2 ,
V_2 -> V_51 ,
F_26 ( V_2 ) ,
F_24 ( V_2 ) ,
F_27 ( V_2 ) ,
F_28 ( V_2 ) ) ;
V_11 = - V_55 ;
goto V_56;
}
if ( ! F_31 ( V_2 -> V_19 , V_57 ) )
F_32 ( V_2 -> V_19 ) ;
else {
V_2 -> V_4 = F_24 ( V_2 ) ;
V_2 -> V_6 = F_27 ( V_2 ) & V_58 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_59 = - 1 ;
}
V_56:
if ( F_19 ( V_19 ) )
F_33 ( V_42 ) ;
return V_11 ;
}
static int
F_34 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_48 * V_49 ;
int V_11 ;
if ( V_2 -> V_26 )
return 0 ;
V_25 = F_35 ( sizeof( * V_25 ) , V_60 ) ;
if ( ! V_25 )
return - V_61 ;
V_49 = F_36 ( V_2 -> V_19 , 4096 ) ;
if ( V_49 == NULL ) {
F_29 ( L_5 ) ;
V_11 = - V_61 ;
goto V_62;
}
F_37 ( V_49 , V_63 ) ;
V_11 = F_38 ( V_49 , 4096 , true ) ;
if ( V_11 )
goto V_64;
V_25 -> V_28 = V_49 -> V_28 ;
V_25 -> V_65 = F_39 ( V_49 -> V_66 [ 0 ] ) ;
if ( V_25 -> V_65 == NULL )
goto V_67;
V_25 -> V_49 = V_49 ;
V_2 -> V_26 = V_25 ;
return 0 ;
V_67:
F_40 ( V_49 ) ;
V_64:
F_41 ( & V_49 -> V_68 ) ;
V_62:
F_42 ( V_25 ) ;
return V_11 ;
}
static void
F_43 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
struct V_48 * V_49 ;
if ( ! V_2 -> V_26 )
return;
V_49 = V_25 -> V_49 ;
F_44 ( V_49 -> V_66 [ 0 ] ) ;
F_40 ( V_49 ) ;
F_41 ( & V_49 -> V_68 ) ;
F_42 ( V_25 ) ;
V_2 -> V_26 = NULL ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_69 * V_42 = V_19 -> V_43 ;
int V_11 = F_18 ( V_2 ) ;
if ( F_15 ( V_19 ) -> V_45 > 3 ) {
F_46 ( V_70 , F_47 ( V_71 ) ) ;
if ( F_48 ( V_19 ) )
F_46 ( V_72 ,
F_49 ( V_73 ) |
F_47 ( V_74 ) ) ;
}
if ( F_15 ( V_19 ) -> V_45 >= 5 ) {
V_11 = F_34 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
if ( F_50 ( V_19 ) ) {
F_46 ( V_75 ,
F_49 ( V_76 ) ) ;
}
if ( F_15 ( V_19 ) -> V_45 >= 6 )
F_46 ( V_77 , F_47 ( V_78 ) ) ;
return V_11 ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_26 )
return;
F_43 ( V_2 ) ;
}
static void
F_52 ( struct V_1 * V_2 ,
T_1 V_79 ,
T_1 V_80 )
{
F_4 ( V_2 , V_81 |
V_82 |
V_83 |
V_84 ) ;
F_4 ( V_2 , V_79 ) ;
F_4 ( V_2 , V_80 ) ;
}
static int
F_53 ( struct V_1 * V_2 ,
T_1 * V_79 )
{
T_1 V_85 ;
T_1 V_86 ;
int V_11 ;
V_11 = F_3 ( V_2 , 10 ) ;
if ( V_11 )
return V_11 ;
V_85 = V_2 -> V_87 [ 0 ] ;
V_86 = V_2 -> V_87 [ 1 ] ;
* V_79 = F_54 ( V_2 ) ;
F_52 ( V_2 , * V_79 , V_85 ) ;
F_52 ( V_2 , * V_79 , V_86 ) ;
F_4 ( V_2 , V_88 ) ;
F_4 ( V_2 , V_89 << V_90 ) ;
F_4 ( V_2 , * V_79 ) ;
F_4 ( V_2 , V_91 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_55 ( struct V_1 * V_92 ,
struct V_1 * V_93 ,
T_1 V_79 )
{
int V_11 ;
T_1 V_94 = V_81 |
V_95 |
V_83 ;
V_79 -= 1 ;
F_56 ( V_93 -> V_96 [ V_92 -> V_97 ] ==
V_98 ) ;
V_11 = F_3 ( V_92 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_92 ,
V_94 | V_93 -> V_96 [ V_92 -> V_97 ] ) ;
F_4 ( V_92 , V_79 ) ;
F_4 ( V_92 , 0 ) ;
F_4 ( V_92 , V_17 ) ;
F_5 ( V_92 ) ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 ,
T_1 * V_99 )
{
T_1 V_79 = F_54 ( V_2 ) ;
struct V_24 * V_25 = V_2 -> V_26 ;
T_1 V_27 = V_25 -> V_28 + 128 ;
int V_11 ;
V_11 = F_3 ( V_2 , 32 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , F_10 ( 4 ) | V_32 |
V_100 |
V_36 ) ;
F_4 ( V_2 , V_25 -> V_28 | V_31 ) ;
F_4 ( V_2 , V_79 ) ;
F_4 ( V_2 , 0 ) ;
F_58 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_58 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_58 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_58 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_58 ( V_2 , V_27 ) ;
V_27 += 128 ;
F_58 ( V_2 , V_27 ) ;
F_4 ( V_2 , F_10 ( 4 ) | V_32 |
V_100 |
V_36 |
V_101 ) ;
F_4 ( V_2 , V_25 -> V_28 | V_31 ) ;
F_4 ( V_2 , V_79 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
* V_99 = V_79 ;
return 0 ;
}
static T_1
F_59 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
if ( F_50 ( V_19 ) || F_48 ( V_19 ) )
F_14 ( V_2 ) ;
return F_60 ( V_2 , V_89 ) ;
}
static T_1
F_61 ( struct V_1 * V_2 )
{
return F_60 ( V_2 , V_89 ) ;
}
static T_1
F_62 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = V_2 -> V_26 ;
return V_25 -> V_65 [ 0 ] ;
}
static bool
F_63 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
if ( ! V_19 -> V_102 )
return false ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( V_2 -> V_104 ++ == 0 ) {
V_42 -> V_105 &= ~ V_2 -> V_106 ;
F_46 ( V_107 , V_42 -> V_105 ) ;
F_65 ( V_107 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
return true ;
}
static void
F_67 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( -- V_2 -> V_104 == 0 ) {
V_42 -> V_105 |= V_2 -> V_106 ;
F_46 ( V_107 , V_42 -> V_105 ) ;
F_65 ( V_107 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
}
static bool
F_68 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
if ( ! V_19 -> V_102 )
return false ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( V_2 -> V_104 ++ == 0 ) {
V_42 -> V_108 &= ~ V_2 -> V_106 ;
F_46 ( V_109 , V_42 -> V_108 ) ;
F_65 ( V_109 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
return true ;
}
static void
F_69 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( -- V_2 -> V_104 == 0 ) {
V_42 -> V_108 |= V_2 -> V_106 ;
F_46 ( V_109 , V_42 -> V_108 ) ;
F_65 ( V_109 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
}
static bool
F_70 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
if ( ! V_19 -> V_102 )
return false ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( V_2 -> V_104 ++ == 0 ) {
V_42 -> V_108 &= ~ V_2 -> V_106 ;
F_71 ( V_109 , V_42 -> V_108 ) ;
F_72 ( V_109 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
return true ;
}
static void
F_73 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( -- V_2 -> V_104 == 0 ) {
V_42 -> V_108 |= V_2 -> V_106 ;
F_71 ( V_109 , V_42 -> V_108 ) ;
F_72 ( V_109 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_2 -> V_19 -> V_43 ;
T_1 V_110 = 0 ;
if ( F_48 ( V_19 ) ) {
switch ( V_2 -> V_97 ) {
case V_111 :
V_110 = V_112 ;
break;
case V_113 :
V_110 = V_114 ;
break;
case V_115 :
V_110 = V_116 ;
break;
}
} else if ( F_50 ( V_2 -> V_19 ) ) {
V_110 = F_75 ( V_2 -> V_46 ) ;
} else {
V_110 = F_76 ( V_2 -> V_46 ) ;
}
F_46 ( V_110 , ( T_1 ) V_2 -> V_117 . V_118 ) ;
F_65 ( V_110 ) ;
}
static int
F_77 ( struct V_1 * V_2 ,
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
F_78 ( struct V_1 * V_2 ,
T_1 * V_99 )
{
T_1 V_79 ;
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
V_79 = F_54 ( V_2 ) ;
F_4 ( V_2 , V_88 ) ;
F_4 ( V_2 , V_89 << V_90 ) ;
F_4 ( V_2 , V_79 ) ;
F_4 ( V_2 , V_91 ) ;
F_5 ( V_2 ) ;
* V_99 = V_79 ;
return 0 ;
}
static bool
F_79 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
if ( ! V_19 -> V_102 )
return false ;
F_20 ( V_42 ) ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( V_2 -> V_104 ++ == 0 ) {
F_80 ( V_2 , ~ V_2 -> V_106 ) ;
V_42 -> V_105 &= ~ V_2 -> V_106 ;
F_46 ( V_107 , V_42 -> V_105 ) ;
F_65 ( V_107 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
return true ;
}
static void
F_81 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
T_2 * V_42 = V_19 -> V_43 ;
unsigned long V_33 ;
F_64 ( & V_42 -> V_103 , V_33 ) ;
if ( -- V_2 -> V_104 == 0 ) {
F_80 ( V_2 , ~ 0 ) ;
V_42 -> V_105 |= V_2 -> V_106 ;
F_46 ( V_107 , V_42 -> V_105 ) ;
F_65 ( V_107 ) ;
}
F_66 ( & V_42 -> V_103 , V_33 ) ;
F_33 ( V_42 ) ;
}
static int
F_82 ( struct V_1 * V_2 , T_1 V_119 , T_1 V_120 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 ,
V_121 |
V_122 |
V_123 ) ;
F_4 ( V_2 , V_119 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_83 ( struct V_1 * V_2 ,
T_1 V_119 , T_1 V_124 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 4 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_125 ) ;
F_4 ( V_2 , V_119 | V_126 ) ;
F_4 ( V_2 , V_119 + V_124 - 8 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_84 ( struct V_1 * V_2 ,
T_1 V_119 , T_1 V_124 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_121 | V_122 ) ;
F_4 ( V_2 , V_119 | V_126 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_85 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
V_49 = V_2 -> V_117 . V_49 ;
if ( V_49 == NULL )
return;
F_44 ( V_49 -> V_66 [ 0 ] ) ;
F_40 ( V_49 ) ;
F_41 ( & V_49 -> V_68 ) ;
V_2 -> V_117 . V_49 = NULL ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_48 * V_49 ;
int V_11 ;
V_49 = F_36 ( V_19 , 4096 ) ;
if ( V_49 == NULL ) {
F_29 ( L_6 ) ;
V_11 = - V_61 ;
goto V_62;
}
F_37 ( V_49 , V_63 ) ;
V_11 = F_38 ( V_49 , 4096 , true ) ;
if ( V_11 != 0 ) {
goto V_64;
}
V_2 -> V_117 . V_118 = V_49 -> V_28 ;
V_2 -> V_117 . V_127 = F_39 ( V_49 -> V_66 [ 0 ] ) ;
if ( V_2 -> V_117 . V_127 == NULL ) {
goto V_67;
}
V_2 -> V_117 . V_49 = V_49 ;
memset ( V_2 -> V_117 . V_127 , 0 , V_52 ) ;
F_74 ( V_2 ) ;
F_87 ( L_7 ,
V_2 -> V_51 , V_2 -> V_117 . V_118 ) ;
return 0 ;
V_67:
F_40 ( V_49 ) ;
V_64:
F_41 ( & V_49 -> V_68 ) ;
V_62:
return V_11 ;
}
static int F_88 ( struct V_18 * V_19 ,
struct V_1 * V_2 )
{
struct V_48 * V_49 ;
int V_11 ;
V_2 -> V_19 = V_19 ;
F_89 ( & V_2 -> V_128 ) ;
F_89 ( & V_2 -> V_129 ) ;
F_89 ( & V_2 -> V_130 ) ;
V_2 -> V_7 = 32 * V_52 ;
F_90 ( & V_2 -> V_131 ) ;
if ( F_91 ( V_19 ) ) {
V_11 = F_86 ( V_2 ) ;
if ( V_11 )
return V_11 ;
}
V_49 = F_36 ( V_19 , V_2 -> V_7 ) ;
if ( V_49 == NULL ) {
F_29 ( L_8 ) ;
V_11 = - V_61 ;
goto V_132;
}
V_2 -> V_49 = V_49 ;
V_11 = F_38 ( V_49 , V_52 , true ) ;
if ( V_11 )
goto V_64;
V_11 = F_92 ( V_49 , true ) ;
if ( V_11 )
goto V_67;
V_2 -> V_133 = F_93 ( V_19 -> V_134 -> V_68 + V_49 -> V_28 ,
V_2 -> V_7 ) ;
if ( V_2 -> V_133 == NULL ) {
F_29 ( L_9 ) ;
V_11 = - V_135 ;
goto V_67;
}
V_11 = V_2 -> V_136 ( V_2 ) ;
if ( V_11 )
goto V_137;
V_2 -> V_138 = V_2 -> V_7 ;
if ( F_94 ( V_2 -> V_19 ) || F_95 ( V_2 -> V_19 ) )
V_2 -> V_138 -= 128 ;
return 0 ;
V_137:
F_96 ( V_2 -> V_133 ) ;
V_67:
F_40 ( V_49 ) ;
V_64:
F_41 ( & V_49 -> V_68 ) ;
V_2 -> V_49 = NULL ;
V_132:
F_85 ( V_2 ) ;
return V_11 ;
}
void F_97 ( struct V_1 * V_2 )
{
struct V_69 * V_42 ;
int V_11 ;
if ( V_2 -> V_49 == NULL )
return;
V_42 = V_2 -> V_19 -> V_43 ;
V_11 = F_98 ( V_2 ) ;
if ( V_11 )
F_29 ( L_10 ,
V_2 -> V_51 , V_11 ) ;
F_21 ( V_2 , 0 ) ;
F_96 ( V_2 -> V_133 ) ;
F_40 ( V_2 -> V_49 ) ;
F_41 ( & V_2 -> V_49 -> V_68 ) ;
V_2 -> V_49 = NULL ;
if ( V_2 -> V_139 )
V_2 -> V_139 ( V_2 ) ;
F_85 ( V_2 ) ;
}
static int F_99 ( struct V_1 * V_2 )
{
T_3 T_4 * V_140 ;
int V_141 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_141 ) {
int V_11 = F_100 ( V_2 , V_141 ) ;
if ( V_11 )
return V_11 ;
}
V_140 = V_2 -> V_133 + V_2 -> V_6 ;
V_141 /= 4 ;
while ( V_141 -- )
F_101 ( V_17 , V_140 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_69 * V_42 = V_2 -> V_19 -> V_43 ;
bool V_142 ;
int V_11 ;
V_142 = V_42 -> V_143 . V_144 ;
V_42 -> V_143 . V_144 = false ;
V_11 = F_103 ( V_2 , V_79 ) ;
V_42 -> V_143 . V_144 = V_142 ;
if ( ! V_11 )
F_104 ( V_2 ) ;
return V_11 ;
}
static int F_105 ( struct V_1 * V_2 , int V_145 )
{
struct V_146 * V_147 ;
T_1 V_79 = 0 ;
int V_11 ;
F_104 ( V_2 ) ;
if ( V_2 -> V_59 != - 1 ) {
V_2 -> V_4 = V_2 -> V_59 ;
V_2 -> V_59 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_145 )
return 0 ;
}
F_106 (request, &ring->request_list, list) {
int V_3 ;
if ( V_147 -> V_6 == - 1 )
continue;
V_3 = V_147 -> V_6 - ( V_2 -> V_6 + 8 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_7 ;
if ( V_3 >= V_145 ) {
V_79 = V_147 -> V_79 ;
break;
}
V_147 -> V_6 = - 1 ;
}
if ( V_79 == 0 )
return - V_148 ;
V_11 = F_102 ( V_2 , V_79 ) ;
if ( V_11 )
return V_11 ;
if ( F_56 ( V_2 -> V_59 == - 1 ) )
return - V_148 ;
V_2 -> V_4 = V_2 -> V_59 ;
V_2 -> V_59 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_56 ( V_2 -> V_3 < V_145 ) )
return - V_148 ;
return 0 ;
}
int F_100 ( struct V_1 * V_2 , int V_145 )
{
struct V_18 * V_19 = V_2 -> V_19 ;
struct V_69 * V_42 = V_19 -> V_43 ;
unsigned long V_149 ;
int V_11 ;
V_11 = F_105 ( V_2 , V_145 ) ;
if ( V_11 != - V_148 )
return V_11 ;
F_107 ( V_2 ) ;
V_149 = V_150 + 60 * V_151 ;
do {
V_2 -> V_4 = F_24 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_145 ) {
F_108 ( V_2 ) ;
return 0 ;
}
if ( V_19 -> V_152 -> V_153 ) {
struct V_154 * V_155 = V_19 -> V_152 -> V_153 -> V_156 ;
if ( V_155 -> V_157 )
V_155 -> V_157 -> V_158 |= V_159 ;
}
F_109 ( 1 ) ;
if ( F_110 ( & V_42 -> V_143 . V_160 ) )
return - V_161 ;
} while ( ! F_111 ( V_150 , V_149 ) );
F_108 ( V_2 ) ;
return - V_162 ;
}
int F_3 ( struct V_1 * V_2 ,
int V_163 )
{
struct V_69 * V_42 = V_2 -> V_19 -> V_43 ;
int V_145 = 4 * V_163 ;
int V_11 ;
if ( F_112 ( F_110 ( & V_42 -> V_143 . V_160 ) ) )
return - V_55 ;
if ( F_112 ( V_2 -> V_6 + V_145 > V_2 -> V_138 ) ) {
V_11 = F_99 ( V_2 ) ;
if ( F_112 ( V_11 ) )
return V_11 ;
}
if ( F_112 ( V_2 -> V_3 < V_145 ) ) {
V_11 = F_100 ( V_2 , V_145 ) ;
if ( F_112 ( V_11 ) )
return V_11 ;
}
V_2 -> V_3 -= V_145 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_69 * V_42 = V_2 -> V_19 -> V_43 ;
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
if ( V_42 -> V_164 & F_113 ( V_2 ) )
return;
V_2 -> V_50 ( V_2 , V_2 -> V_6 ) ;
}
static void F_114 ( struct V_1 * V_2 ,
T_1 V_41 )
{
T_2 * V_42 = V_2 -> V_19 -> V_43 ;
F_46 ( V_165 ,
V_166 |
V_167 ) ;
F_46 ( V_168 , 0x0 ) ;
if ( F_30 ( ( F_17 ( V_165 ) &
V_169 ) == 0 ,
50 ) )
F_29 ( L_11 ) ;
F_13 ( V_2 , V_41 ) ;
F_46 ( V_165 ,
V_166 |
V_170 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
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
F_116 ( struct V_1 * V_2 ,
T_1 V_119 , T_1 V_124 )
{
int V_11 ;
V_11 = F_3 ( V_2 , 2 ) ;
if ( V_11 )
return V_11 ;
F_4 ( V_2 , V_121 | V_123 ) ;
F_4 ( V_2 , V_119 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_117 ( struct V_1 * V_2 ,
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
int F_118 ( struct V_18 * V_19 )
{
T_2 * V_42 = V_19 -> V_43 ;
struct V_1 * V_2 = & V_42 -> V_2 [ V_111 ] ;
V_2 -> V_51 = L_12 ;
V_2 -> V_97 = V_111 ;
V_2 -> V_46 = V_177 ;
if ( F_15 ( V_19 ) -> V_45 >= 6 ) {
V_2 -> V_178 = F_53 ;
V_2 -> V_172 = F_11 ;
V_2 -> V_179 = F_79 ;
V_2 -> V_180 = F_81 ;
V_2 -> V_106 = V_181 ;
V_2 -> V_182 = F_59 ;
V_2 -> V_183 = F_55 ;
V_2 -> V_96 [ 0 ] = V_98 ;
V_2 -> V_96 [ 1 ] = V_184 ;
V_2 -> V_96 [ 2 ] = V_185 ;
V_2 -> V_87 [ 0 ] = V_186 ;
V_2 -> V_87 [ 1 ] = V_187 ;
} else if ( F_8 ( V_19 ) ) {
V_2 -> V_178 = F_57 ;
V_2 -> V_172 = F_6 ;
V_2 -> V_182 = F_62 ;
V_2 -> V_179 = F_63 ;
V_2 -> V_180 = F_67 ;
V_2 -> V_106 = V_181 | V_188 ;
} else {
V_2 -> V_178 = F_78 ;
if ( F_15 ( V_19 ) -> V_45 < 4 )
V_2 -> V_172 = F_2 ;
else
V_2 -> V_172 = F_6 ;
V_2 -> V_182 = F_61 ;
if ( F_119 ( V_19 ) ) {
V_2 -> V_179 = F_70 ;
V_2 -> V_180 = F_73 ;
} else {
V_2 -> V_179 = F_68 ;
V_2 -> V_180 = F_69 ;
}
V_2 -> V_106 = V_189 ;
}
V_2 -> V_50 = F_12 ;
if ( F_15 ( V_19 ) -> V_45 >= 6 )
V_2 -> V_190 = F_116 ;
else if ( F_15 ( V_19 ) -> V_45 >= 4 )
V_2 -> V_190 = F_82 ;
else if ( F_94 ( V_19 ) || F_95 ( V_19 ) )
V_2 -> V_190 = F_83 ;
else
V_2 -> V_190 = F_84 ;
V_2 -> V_136 = F_45 ;
V_2 -> V_139 = F_51 ;
if ( ! F_91 ( V_19 ) ) {
V_2 -> V_117 . V_127 = V_42 -> V_191 -> V_192 ;
memset ( V_2 -> V_117 . V_127 , 0 , V_52 ) ;
}
return F_88 ( V_19 , V_2 ) ;
}
int F_120 ( struct V_18 * V_19 , T_5 V_193 , T_1 V_7 )
{
T_2 * V_42 = V_19 -> V_43 ;
struct V_1 * V_2 = & V_42 -> V_2 [ V_111 ] ;
V_2 -> V_51 = L_12 ;
V_2 -> V_97 = V_111 ;
V_2 -> V_46 = V_177 ;
if ( F_15 ( V_19 ) -> V_45 >= 6 ) {
return - V_194 ;
}
V_2 -> V_178 = F_78 ;
if ( F_15 ( V_19 ) -> V_45 < 4 )
V_2 -> V_172 = F_2 ;
else
V_2 -> V_172 = F_6 ;
V_2 -> V_182 = F_61 ;
if ( F_119 ( V_19 ) ) {
V_2 -> V_179 = F_70 ;
V_2 -> V_180 = F_73 ;
} else {
V_2 -> V_179 = F_68 ;
V_2 -> V_180 = F_69 ;
}
V_2 -> V_106 = V_189 ;
V_2 -> V_50 = F_12 ;
if ( F_15 ( V_19 ) -> V_45 >= 4 )
V_2 -> V_190 = F_82 ;
else if ( F_94 ( V_19 ) || F_95 ( V_19 ) )
V_2 -> V_190 = F_83 ;
else
V_2 -> V_190 = F_84 ;
V_2 -> V_136 = F_45 ;
V_2 -> V_139 = F_51 ;
if ( ! F_91 ( V_19 ) )
V_2 -> V_117 . V_127 = V_42 -> V_191 -> V_192 ;
V_2 -> V_19 = V_19 ;
F_89 ( & V_2 -> V_128 ) ;
F_89 ( & V_2 -> V_129 ) ;
F_89 ( & V_2 -> V_130 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_138 = V_2 -> V_7 ;
if ( F_94 ( V_2 -> V_19 ) )
V_2 -> V_138 -= 128 ;
V_2 -> V_133 = F_93 ( V_193 , V_7 ) ;
if ( V_2 -> V_133 == NULL ) {
F_29 ( L_13
L_14 ) ;
return - V_61 ;
}
return 0 ;
}
int F_121 ( struct V_18 * V_19 )
{
T_2 * V_42 = V_19 -> V_43 ;
struct V_1 * V_2 = & V_42 -> V_2 [ V_115 ] ;
V_2 -> V_51 = L_15 ;
V_2 -> V_97 = V_115 ;
V_2 -> V_50 = F_12 ;
if ( F_50 ( V_19 ) || F_48 ( V_19 ) ) {
V_2 -> V_46 = V_195 ;
if ( F_50 ( V_19 ) )
V_2 -> V_50 = F_114 ;
V_2 -> V_172 = F_115 ;
V_2 -> V_178 = F_53 ;
V_2 -> V_182 = F_59 ;
V_2 -> V_106 = V_196 ;
V_2 -> V_179 = F_79 ;
V_2 -> V_180 = F_81 ;
V_2 -> V_190 = F_116 ;
V_2 -> V_183 = F_55 ;
V_2 -> V_96 [ 0 ] = V_197 ;
V_2 -> V_96 [ 1 ] = V_98 ;
V_2 -> V_96 [ 2 ] = V_198 ;
V_2 -> V_87 [ 0 ] = V_199 ;
V_2 -> V_87 [ 1 ] = V_200 ;
} else {
V_2 -> V_46 = V_201 ;
V_2 -> V_172 = F_77 ;
V_2 -> V_178 = F_78 ;
V_2 -> V_182 = F_61 ;
if ( F_8 ( V_19 ) ) {
V_2 -> V_106 = V_202 ;
V_2 -> V_179 = F_63 ;
V_2 -> V_180 = F_67 ;
} else {
V_2 -> V_106 = V_203 ;
V_2 -> V_179 = F_68 ;
V_2 -> V_180 = F_69 ;
}
V_2 -> V_190 = F_82 ;
}
V_2 -> V_136 = F_18 ;
return F_88 ( V_19 , V_2 ) ;
}
int F_122 ( struct V_18 * V_19 )
{
T_2 * V_42 = V_19 -> V_43 ;
struct V_1 * V_2 = & V_42 -> V_2 [ V_113 ] ;
V_2 -> V_51 = L_16 ;
V_2 -> V_97 = V_113 ;
V_2 -> V_46 = V_204 ;
V_2 -> V_50 = F_12 ;
V_2 -> V_172 = F_117 ;
V_2 -> V_178 = F_53 ;
V_2 -> V_182 = F_59 ;
V_2 -> V_106 = V_205 ;
V_2 -> V_179 = F_79 ;
V_2 -> V_180 = F_81 ;
V_2 -> V_190 = F_116 ;
V_2 -> V_183 = F_55 ;
V_2 -> V_96 [ 0 ] = V_206 ;
V_2 -> V_96 [ 1 ] = V_207 ;
V_2 -> V_96 [ 2 ] = V_98 ;
V_2 -> V_87 [ 0 ] = V_208 ;
V_2 -> V_87 [ 1 ] = V_209 ;
V_2 -> V_136 = F_18 ;
return F_88 ( V_19 , V_2 ) ;
}
