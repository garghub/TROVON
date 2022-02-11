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
static int F_13 ( struct V_1 * V_2 , T_1 V_43 )
{
int V_12 ;
if ( ! V_2 -> V_44 )
return 0 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_18 ) ;
F_4 ( V_2 , F_14 ( 1 ) ) ;
F_4 ( V_2 , V_45 ) ;
F_4 ( V_2 , V_43 ) ;
F_5 ( V_2 ) ;
V_2 -> V_44 = false ;
return 0 ;
}
static int
F_15 ( struct V_1 * V_2 ,
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
V_34 |= V_46 ;
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
if ( V_10 )
return F_13 ( V_2 , V_47 ) ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_43 )
{
T_2 * V_48 = V_2 -> V_20 -> V_49 ;
F_17 ( V_2 , V_43 ) ;
}
T_1 F_18 ( struct V_1 * V_2 )
{
T_2 * V_48 = V_2 -> V_20 -> V_49 ;
T_1 V_50 = F_19 ( V_2 -> V_20 ) -> V_51 >= 4 ?
F_20 ( V_2 -> V_52 ) : V_53 ;
return F_21 ( V_50 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_54 * V_48 = V_2 -> V_20 -> V_49 ;
T_1 V_55 ;
V_55 = V_48 -> V_56 -> V_57 ;
if ( F_19 ( V_2 -> V_20 ) -> V_51 >= 4 )
V_55 |= ( V_48 -> V_56 -> V_57 >> 28 ) & 0xf0 ;
F_23 ( V_58 , V_55 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
struct V_59 * V_60 = V_2 -> V_60 ;
int V_12 = 0 ;
T_1 V_4 ;
if ( F_25 ( V_20 ) )
F_26 ( V_48 ) ;
if ( F_27 ( V_20 ) )
F_28 ( V_2 ) ;
else
F_22 ( V_2 ) ;
F_29 ( V_2 , 0 ) ;
F_30 ( V_2 , 0 ) ;
V_2 -> V_61 ( V_2 , 0 ) ;
V_4 = F_31 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_32 ( L_1
L_2 ,
V_2 -> V_62 ,
F_33 ( V_2 ) ,
F_31 ( V_2 ) ,
F_34 ( V_2 ) ,
F_35 ( V_2 ) ) ;
F_30 ( V_2 , 0 ) ;
if ( F_31 ( V_2 ) & V_5 ) {
F_36 ( L_3
L_2 ,
V_2 -> V_62 ,
F_33 ( V_2 ) ,
F_31 ( V_2 ) ,
F_34 ( V_2 ) ,
F_35 ( V_2 ) ) ;
}
}
F_37 ( V_2 , V_60 -> V_29 ) ;
F_29 ( V_2 ,
( ( V_2 -> V_8 - V_63 ) & V_64 )
| V_65 ) ;
if ( F_38 ( ( F_33 ( V_2 ) & V_65 ) != 0 &&
F_35 ( V_2 ) == V_60 -> V_29 &&
( F_31 ( V_2 ) & V_5 ) == 0 , 50 ) ) {
F_36 ( L_4
L_2 ,
V_2 -> V_62 ,
F_33 ( V_2 ) ,
F_31 ( V_2 ) ,
F_34 ( V_2 ) ,
F_35 ( V_2 ) ) ;
V_12 = - V_66 ;
goto V_67;
}
if ( ! F_39 ( V_2 -> V_20 , V_68 ) )
F_40 ( V_2 -> V_20 ) ;
else {
V_2 -> V_4 = F_31 ( V_2 ) ;
V_2 -> V_6 = F_34 ( V_2 ) & V_69 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
V_2 -> V_70 = - 1 ;
}
memset ( & V_2 -> V_71 , 0 , sizeof( V_2 -> V_71 ) ) ;
V_67:
if ( F_25 ( V_20 ) )
F_41 ( V_48 ) ;
return V_12 ;
}
static int
F_42 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_59 * V_60 ;
int V_12 ;
if ( V_2 -> V_27 )
return 0 ;
V_26 = F_43 ( sizeof( * V_26 ) , V_72 ) ;
if ( ! V_26 )
return - V_73 ;
V_60 = F_44 ( V_2 -> V_20 , 4096 ) ;
if ( V_60 == NULL ) {
F_36 ( L_5 ) ;
V_12 = - V_73 ;
goto V_74;
}
F_45 ( V_60 , V_75 ) ;
V_12 = F_46 ( V_60 , 4096 , true , false ) ;
if ( V_12 )
goto V_76;
V_26 -> V_29 = V_60 -> V_29 ;
V_26 -> V_77 = F_47 ( F_48 ( V_60 -> V_78 -> V_79 ) ) ;
if ( V_26 -> V_77 == NULL ) {
V_12 = - V_73 ;
goto V_80;
}
F_49 ( L_6 ,
V_2 -> V_62 , V_26 -> V_29 ) ;
V_26 -> V_60 = V_60 ;
V_2 -> V_27 = V_26 ;
return 0 ;
V_80:
F_50 ( V_60 ) ;
V_76:
F_51 ( & V_60 -> V_81 ) ;
V_74:
F_52 ( V_26 ) ;
return V_12 ;
}
static void
F_53 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
struct V_59 * V_60 ;
V_60 = V_26 -> V_60 ;
F_54 ( F_48 ( V_60 -> V_78 -> V_79 ) ) ;
F_50 ( V_60 ) ;
F_51 ( & V_60 -> V_81 ) ;
F_52 ( V_26 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_54 * V_48 = V_20 -> V_49 ;
int V_12 = F_24 ( V_2 ) ;
if ( F_19 ( V_20 ) -> V_51 > 3 )
F_23 ( V_82 , F_56 ( V_83 ) ) ;
if ( F_19 ( V_20 ) -> V_51 >= 6 )
F_23 ( V_82 , F_56 ( V_84 ) ) ;
if ( F_19 ( V_20 ) -> V_51 == 6 )
F_23 ( V_85 ,
F_56 ( V_86 ) ) ;
if ( F_57 ( V_20 ) )
F_23 ( V_87 ,
F_58 ( V_86 ) |
F_56 ( V_88 ) ) ;
if ( F_19 ( V_20 ) -> V_51 >= 5 ) {
V_12 = F_42 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
if ( F_59 ( V_20 ) ) {
F_23 ( V_89 ,
F_58 ( V_90 ) ) ;
V_2 -> V_91 =
! ! ( F_21 ( V_85 ) & V_86 ) ;
}
if ( F_19 ( V_20 ) -> V_51 >= 6 )
F_23 ( V_92 , F_56 ( V_93 ) ) ;
if ( F_60 ( V_20 ) )
F_61 ( V_2 , ~ V_94 ) ;
return V_12 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
if ( ! V_2 -> V_27 )
return;
if ( F_63 ( V_20 ) )
F_51 ( F_64 ( V_2 -> V_27 ) ) ;
if ( F_19 ( V_20 ) -> V_51 >= 5 )
F_53 ( V_2 ) ;
V_2 -> V_27 = NULL ;
}
static void
F_65 ( struct V_1 * V_2 ,
T_1 V_95 )
{
#define F_66 4
F_4 ( V_2 , F_14 ( 1 ) ) ;
F_4 ( V_2 , V_95 ) ;
F_4 ( V_2 , V_2 -> V_96 ) ;
F_4 ( V_2 , V_18 ) ;
}
static int
F_67 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_54 * V_48 = V_20 -> V_49 ;
struct V_1 * V_97 ;
int V_98 , V_12 ;
V_12 = F_3 ( V_2 , ( ( V_99 - 1 ) *
F_66 ) +
4 ) ;
if ( V_12 )
return V_12 ;
#undef F_66
F_68 (useless, dev_priv, i) {
T_1 V_100 = V_2 -> V_101 [ V_98 ] ;
if ( V_100 != V_102 )
F_65 ( V_2 , V_100 ) ;
}
F_4 ( V_2 , V_103 ) ;
F_4 ( V_2 , V_104 << V_105 ) ;
F_4 ( V_2 , V_2 -> V_96 ) ;
F_4 ( V_2 , V_106 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static inline bool F_69 ( struct V_19 * V_20 ,
T_1 V_107 )
{
struct V_54 * V_48 = V_20 -> V_49 ;
return V_48 -> V_108 < V_107 ;
}
static int
F_70 ( struct V_1 * V_109 ,
struct V_1 * V_110 ,
T_1 V_107 )
{
int V_12 ;
T_1 V_111 = V_112 |
V_113 |
V_114 ;
V_107 -= 1 ;
F_71 ( V_110 -> V_115 [ V_109 -> V_116 ] ==
V_117 ) ;
V_12 = F_3 ( V_109 , 4 ) ;
if ( V_12 )
return V_12 ;
if ( F_72 ( ! F_69 ( V_109 -> V_20 , V_107 ) ) ) {
F_4 ( V_109 ,
V_111 |
V_110 -> V_115 [ V_109 -> V_116 ] ) ;
F_4 ( V_109 , V_107 ) ;
F_4 ( V_109 , 0 ) ;
F_4 ( V_109 , V_18 ) ;
} else {
F_4 ( V_109 , V_18 ) ;
F_4 ( V_109 , V_18 ) ;
F_4 ( V_109 , V_18 ) ;
F_4 ( V_109 , V_18 ) ;
}
F_5 ( V_109 ) ;
return 0 ;
}
static int
F_73 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_12 ;
V_12 = F_3 ( V_2 , 32 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , F_10 ( 4 ) | V_33 |
V_118 |
V_39 ) ;
F_4 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_4 ( V_2 , V_2 -> V_96 ) ;
F_4 ( V_2 , 0 ) ;
F_74 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_74 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_74 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_74 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_74 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_74 ( V_2 , V_28 ) ;
F_4 ( V_2 , F_10 ( 4 ) | V_33 |
V_118 |
V_39 |
V_119 ) ;
F_4 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_4 ( V_2 , V_2 -> V_96 ) ;
F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static T_1
F_75 ( struct V_1 * V_2 , bool V_120 )
{
if ( ! V_120 )
F_18 ( V_2 ) ;
return F_76 ( V_2 , V_104 ) ;
}
static T_1
F_77 ( struct V_1 * V_2 , bool V_120 )
{
return F_76 ( V_2 , V_104 ) ;
}
static void
F_78 ( struct V_1 * V_2 , T_1 V_107 )
{
F_79 ( V_2 , V_104 , V_107 ) ;
}
static T_1
F_80 ( struct V_1 * V_2 , bool V_120 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
return V_26 -> V_77 [ 0 ] ;
}
static void
F_81 ( struct V_1 * V_2 , T_1 V_107 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
V_26 -> V_77 [ 0 ] = V_107 ;
}
static bool
F_82 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
if ( ! V_20 -> V_121 )
return false ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( V_2 -> V_123 . V_124 ++ == 0 ) {
V_48 -> V_125 &= ~ V_2 -> V_126 ;
F_23 ( V_127 , V_48 -> V_125 ) ;
F_84 ( V_127 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
return true ;
}
static void
F_86 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( -- V_2 -> V_123 . V_124 == 0 ) {
V_48 -> V_125 |= V_2 -> V_126 ;
F_23 ( V_127 , V_48 -> V_125 ) ;
F_84 ( V_127 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
}
static bool
F_87 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
if ( ! V_20 -> V_121 )
return false ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( V_2 -> V_123 . V_124 ++ == 0 ) {
V_48 -> V_128 &= ~ V_2 -> V_126 ;
F_23 ( V_129 , V_48 -> V_128 ) ;
F_84 ( V_129 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
return true ;
}
static void
F_88 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( -- V_2 -> V_123 . V_124 == 0 ) {
V_48 -> V_128 |= V_2 -> V_126 ;
F_23 ( V_129 , V_48 -> V_128 ) ;
F_84 ( V_129 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
}
static bool
F_89 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
if ( ! V_20 -> V_121 )
return false ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( V_2 -> V_123 . V_124 ++ == 0 ) {
V_48 -> V_128 &= ~ V_2 -> V_126 ;
F_90 ( V_129 , V_48 -> V_128 ) ;
F_91 ( V_129 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
return true ;
}
static void
F_92 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( -- V_2 -> V_123 . V_124 == 0 ) {
V_48 -> V_128 |= V_2 -> V_126 ;
F_90 ( V_129 , V_48 -> V_128 ) ;
F_91 ( V_129 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_2 -> V_20 -> V_49 ;
T_1 V_130 = 0 ;
if ( F_57 ( V_20 ) ) {
switch ( V_2 -> V_116 ) {
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
} else if ( F_59 ( V_2 -> V_20 ) ) {
V_130 = F_93 ( V_2 -> V_52 ) ;
} else {
V_130 = F_94 ( V_2 -> V_52 ) ;
}
F_23 ( V_130 , ( T_1 ) V_2 -> V_139 . V_140 ) ;
F_84 ( V_130 ) ;
if ( F_19 ( V_20 ) -> V_51 >= 6 ) {
T_1 V_141 = F_95 ( V_2 -> V_52 ) ;
F_23 ( V_141 ,
F_56 ( V_142 |
V_143 ) ) ;
if ( F_38 ( ( F_21 ( V_141 ) & V_143 ) == 0 ,
1000 ) )
F_36 ( L_7 ,
V_2 -> V_62 ) ;
}
}
static int
F_96 ( struct V_1 * V_2 ,
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
F_97 ( struct V_1 * V_2 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_103 ) ;
F_4 ( V_2 , V_104 << V_105 ) ;
F_4 ( V_2 , V_2 -> V_96 ) ;
F_4 ( V_2 , V_106 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static bool
F_98 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
if ( ! V_20 -> V_121 )
return false ;
F_26 ( V_48 ) ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( V_2 -> V_123 . V_124 ++ == 0 ) {
if ( F_60 ( V_20 ) && V_2 -> V_116 == V_131 )
F_61 ( V_2 ,
~ ( V_2 -> V_126 |
V_94 ) ) ;
else
F_61 ( V_2 , ~ V_2 -> V_126 ) ;
V_48 -> V_125 &= ~ V_2 -> V_126 ;
F_23 ( V_127 , V_48 -> V_125 ) ;
F_84 ( V_127 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
return true ;
}
static void
F_99 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_2 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
F_83 ( & V_48 -> V_122 , V_34 ) ;
if ( -- V_2 -> V_123 . V_124 == 0 ) {
if ( F_60 ( V_20 ) && V_2 -> V_116 == V_131 )
F_61 ( V_2 ,
~ V_94 ) ;
else
F_61 ( V_2 , ~ 0 ) ;
V_48 -> V_125 |= V_2 -> V_126 ;
F_23 ( V_127 , V_48 -> V_125 ) ;
F_84 ( V_127 ) ;
}
F_85 ( & V_48 -> V_122 , V_34 ) ;
F_41 ( V_48 ) ;
}
static bool
F_100 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_54 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
if ( ! V_20 -> V_121 )
return false ;
F_83 ( & V_48 -> V_144 . V_145 , V_34 ) ;
if ( V_2 -> V_123 . V_146 ++ == 0 ) {
T_1 V_147 = F_21 ( V_148 ) ;
F_61 ( V_2 , ~ V_2 -> V_126 ) ;
F_23 ( V_148 , V_147 & ~ V_2 -> V_126 ) ;
F_84 ( V_148 ) ;
}
F_85 ( & V_48 -> V_144 . V_145 , V_34 ) ;
return true ;
}
static void
F_101 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_54 * V_48 = V_20 -> V_49 ;
unsigned long V_34 ;
if ( ! V_20 -> V_121 )
return;
F_83 ( & V_48 -> V_144 . V_145 , V_34 ) ;
if ( -- V_2 -> V_123 . V_146 == 0 ) {
T_1 V_147 = F_21 ( V_148 ) ;
F_61 ( V_2 , ~ 0 ) ;
F_23 ( V_148 , V_147 | V_2 -> V_126 ) ;
F_84 ( V_148 ) ;
}
F_85 ( & V_48 -> V_144 . V_145 , V_34 ) ;
}
static int
F_102 ( struct V_1 * V_2 ,
T_1 V_149 , T_1 V_150 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_151 |
V_152 |
( V_34 & V_153 ? 0 : V_154 ) ) ;
F_4 ( V_2 , V_149 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_103 ( struct V_1 * V_2 ,
T_1 V_149 , T_1 V_155 ,
unsigned V_34 )
{
int V_12 ;
if ( V_34 & V_156 ) {
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_157 ) ;
F_4 ( V_2 , V_149 | ( V_34 & V_153 ? 0 : V_158 ) ) ;
F_4 ( V_2 , V_149 + V_155 - 8 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
} else {
struct V_59 * V_60 = V_2 -> V_27 ;
T_1 V_159 = V_60 -> V_29 ;
if ( V_155 > V_160 )
return - V_161 ;
V_12 = F_3 ( V_2 , 9 + 3 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_162 |
V_163 |
V_164 ) ;
F_4 ( V_2 , V_165 | V_166 | 4096 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , ( F_104 ( V_155 , 4096 ) << 16 ) | 1024 ) ;
F_4 ( V_2 , V_159 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , 4096 ) ;
F_4 ( V_2 , V_149 ) ;
F_4 ( V_2 , V_13 ) ;
F_4 ( V_2 , V_157 ) ;
F_4 ( V_2 , V_159 | ( V_34 & V_153 ? 0 : V_158 ) ) ;
F_4 ( V_2 , V_159 + V_155 - 8 ) ;
F_5 ( V_2 ) ;
}
return 0 ;
}
static int
F_105 ( struct V_1 * V_2 ,
T_1 V_149 , T_1 V_155 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 , V_151 | V_152 ) ;
F_4 ( V_2 , V_149 | ( V_34 & V_153 ? 0 : V_158 ) ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static void F_106 ( struct V_1 * V_2 )
{
struct V_59 * V_60 ;
V_60 = V_2 -> V_139 . V_60 ;
if ( V_60 == NULL )
return;
F_54 ( F_48 ( V_60 -> V_78 -> V_79 ) ) ;
F_50 ( V_60 ) ;
F_51 ( & V_60 -> V_81 ) ;
V_2 -> V_139 . V_60 = NULL ;
}
static int F_107 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_59 * V_60 ;
int V_12 ;
V_60 = F_44 ( V_20 , 4096 ) ;
if ( V_60 == NULL ) {
F_36 ( L_8 ) ;
V_12 = - V_73 ;
goto V_74;
}
F_45 ( V_60 , V_75 ) ;
V_12 = F_46 ( V_60 , 4096 , true , false ) ;
if ( V_12 != 0 ) {
goto V_76;
}
V_2 -> V_139 . V_140 = V_60 -> V_29 ;
V_2 -> V_139 . V_167 = F_47 ( F_48 ( V_60 -> V_78 -> V_79 ) ) ;
if ( V_2 -> V_139 . V_167 == NULL ) {
V_12 = - V_73 ;
goto V_80;
}
V_2 -> V_139 . V_60 = V_60 ;
memset ( V_2 -> V_139 . V_167 , 0 , V_63 ) ;
F_49 ( L_9 ,
V_2 -> V_62 , V_2 -> V_139 . V_140 ) ;
return 0 ;
V_80:
F_50 ( V_60 ) ;
V_76:
F_51 ( & V_60 -> V_81 ) ;
V_74:
return V_12 ;
}
static int F_108 ( struct V_1 * V_2 )
{
struct V_54 * V_48 = V_2 -> V_20 -> V_49 ;
if ( ! V_48 -> V_56 ) {
V_48 -> V_56 =
F_109 ( V_2 -> V_20 , V_63 , V_63 ) ;
if ( ! V_48 -> V_56 )
return - V_73 ;
}
V_2 -> V_139 . V_167 = V_48 -> V_56 -> V_168 ;
memset ( V_2 -> V_139 . V_167 , 0 , V_63 ) ;
return 0 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_1 * V_2 )
{
struct V_59 * V_60 ;
struct V_54 * V_48 = V_20 -> V_49 ;
int V_12 ;
V_2 -> V_20 = V_20 ;
F_111 ( & V_2 -> V_169 ) ;
F_111 ( & V_2 -> V_170 ) ;
V_2 -> V_8 = 32 * V_63 ;
memset ( V_2 -> V_171 , 0 , sizeof( V_2 -> V_171 ) ) ;
F_112 ( & V_2 -> V_172 ) ;
if ( F_27 ( V_20 ) ) {
V_12 = F_107 ( V_2 ) ;
if ( V_12 )
return V_12 ;
} else {
F_113 ( V_2 -> V_116 != V_131 ) ;
V_12 = F_108 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
V_60 = NULL ;
if ( ! F_114 ( V_20 ) )
V_60 = F_115 ( V_20 , V_2 -> V_8 ) ;
if ( V_60 == NULL )
V_60 = F_44 ( V_20 , V_2 -> V_8 ) ;
if ( V_60 == NULL ) {
F_36 ( L_10 ) ;
V_12 = - V_73 ;
goto V_173;
}
V_2 -> V_60 = V_60 ;
V_12 = F_46 ( V_60 , V_63 , true , false ) ;
if ( V_12 )
goto V_76;
V_12 = F_116 ( V_60 , true ) ;
if ( V_12 )
goto V_80;
V_2 -> V_174 =
F_117 ( V_48 -> V_175 . V_176 + V_60 -> V_29 ,
V_2 -> V_8 ) ;
if ( V_2 -> V_174 == NULL ) {
F_36 ( L_11 ) ;
V_12 = - V_177 ;
goto V_80;
}
V_12 = V_2 -> V_178 ( V_2 ) ;
if ( V_12 )
goto V_179;
V_2 -> V_180 = V_2 -> V_8 ;
if ( F_118 ( V_2 -> V_20 ) || F_119 ( V_2 -> V_20 ) )
V_2 -> V_180 -= 128 ;
return 0 ;
V_179:
F_120 ( V_2 -> V_174 ) ;
V_80:
F_50 ( V_60 ) ;
V_76:
F_51 ( & V_60 -> V_81 ) ;
V_2 -> V_60 = NULL ;
V_173:
F_106 ( V_2 ) ;
return V_12 ;
}
void F_121 ( struct V_1 * V_2 )
{
struct V_54 * V_48 ;
int V_12 ;
if ( V_2 -> V_60 == NULL )
return;
V_48 = V_2 -> V_20 -> V_49 ;
V_12 = F_122 ( V_2 ) ;
if ( V_12 )
F_36 ( L_12 ,
V_2 -> V_62 , V_12 ) ;
F_29 ( V_2 , 0 ) ;
F_120 ( V_2 -> V_174 ) ;
F_50 ( V_2 -> V_60 ) ;
F_51 ( & V_2 -> V_60 -> V_81 ) ;
V_2 -> V_60 = NULL ;
if ( V_2 -> V_181 )
V_2 -> V_181 ( V_2 ) ;
F_106 ( V_2 ) ;
}
static int F_123 ( struct V_1 * V_2 , T_1 V_107 )
{
int V_12 ;
V_12 = F_124 ( V_2 , V_107 ) ;
if ( ! V_12 )
F_125 ( V_2 ) ;
return V_12 ;
}
static int F_126 ( struct V_1 * V_2 , int V_182 )
{
struct V_183 * V_184 ;
T_1 V_107 = 0 ;
int V_12 ;
F_125 ( V_2 ) ;
if ( V_2 -> V_70 != - 1 ) {
V_2 -> V_4 = V_2 -> V_70 ;
V_2 -> V_70 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_182 )
return 0 ;
}
F_127 (request, &ring->request_list, list) {
int V_3 ;
if ( V_184 -> V_6 == - 1 )
continue;
V_3 = V_184 -> V_6 - ( V_2 -> V_6 + V_7 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_8 ;
if ( V_3 >= V_182 ) {
V_107 = V_184 -> V_107 ;
break;
}
V_184 -> V_6 = - 1 ;
}
if ( V_107 == 0 )
return - V_161 ;
V_12 = F_123 ( V_2 , V_107 ) ;
if ( V_12 )
return V_12 ;
if ( F_71 ( V_2 -> V_70 == - 1 ) )
return - V_161 ;
V_2 -> V_4 = V_2 -> V_70 ;
V_2 -> V_70 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_71 ( V_2 -> V_3 < V_182 ) )
return - V_161 ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 , int V_182 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_54 * V_48 = V_20 -> V_49 ;
unsigned long V_185 ;
int V_12 ;
V_12 = F_126 ( V_2 , V_182 ) ;
if ( V_12 != - V_161 )
return V_12 ;
F_129 ( V_2 ) ;
V_185 = V_186 + 60 * V_187 ;
do {
V_2 -> V_4 = F_31 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_182 ) {
F_130 ( V_2 ) ;
return 0 ;
}
if ( V_20 -> V_188 -> V_189 ) {
struct V_190 * V_191 = V_20 -> V_188 -> V_189 -> V_192 ;
if ( V_191 -> V_193 )
V_191 -> V_193 -> V_194 |= V_195 ;
}
F_131 ( 1 ) ;
V_12 = F_132 ( & V_48 -> V_196 ,
V_48 -> V_197 . V_198 ) ;
if ( V_12 )
return V_12 ;
} while ( ! F_133 ( V_186 , V_185 ) );
F_130 ( V_2 ) ;
return - V_199 ;
}
static int F_134 ( struct V_1 * V_2 )
{
T_3 T_4 * V_200 ;
int V_201 = V_2 -> V_8 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_201 ) {
int V_12 = F_128 ( V_2 , V_201 ) ;
if ( V_12 )
return V_12 ;
}
V_200 = V_2 -> V_174 + V_2 -> V_6 ;
V_201 /= 4 ;
while ( V_201 -- )
F_135 ( V_18 , V_200 ++ ) ;
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_122 ( struct V_1 * V_2 )
{
T_1 V_107 ;
int V_12 ;
if ( V_2 -> V_96 ) {
V_12 = F_136 ( V_2 , NULL ) ;
if ( V_12 )
return V_12 ;
}
if ( F_137 ( & V_2 -> V_170 ) )
return 0 ;
V_107 = F_138 ( V_2 -> V_170 . V_202 ,
struct V_183 ,
V_203 ) -> V_107 ;
return F_124 ( V_2 , V_107 ) ;
}
static int
F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_96 )
return 0 ;
return F_140 ( V_2 -> V_20 , & V_2 -> V_96 ) ;
}
static int F_141 ( struct V_1 * V_2 ,
int V_204 )
{
int V_12 ;
if ( F_142 ( V_2 -> V_6 + V_204 > V_2 -> V_180 ) ) {
V_12 = F_134 ( V_2 ) ;
if ( F_142 ( V_12 ) )
return V_12 ;
}
if ( F_142 ( V_2 -> V_3 < V_204 ) ) {
V_12 = F_128 ( V_2 , V_204 ) ;
if ( F_142 ( V_12 ) )
return V_12 ;
}
V_2 -> V_3 -= V_204 ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 ,
int V_205 )
{
T_2 * V_48 = V_2 -> V_20 -> V_49 ;
int V_12 ;
V_12 = F_132 ( & V_48 -> V_196 ,
V_48 -> V_197 . V_198 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_139 ( V_2 ) ;
if ( V_12 )
return V_12 ;
return F_141 ( V_2 , V_205 * sizeof( T_3 ) ) ;
}
void F_143 ( struct V_1 * V_2 , T_1 V_107 )
{
struct V_54 * V_48 = V_2 -> V_20 -> V_49 ;
F_113 ( V_2 -> V_96 ) ;
if ( F_19 ( V_2 -> V_20 ) -> V_51 >= 6 ) {
F_23 ( F_144 ( V_2 -> V_52 ) , 0 ) ;
F_23 ( F_145 ( V_2 -> V_52 ) , 0 ) ;
}
V_2 -> V_206 ( V_2 , V_107 ) ;
V_2 -> V_71 . V_107 = V_107 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_54 * V_48 = V_2 -> V_20 -> V_49 ;
V_2 -> V_6 &= V_2 -> V_8 - 1 ;
if ( V_48 -> V_196 . V_207 & F_146 ( V_2 ) )
return;
V_2 -> V_61 ( V_2 , V_2 -> V_6 ) ;
}
static void F_147 ( struct V_1 * V_2 ,
T_1 V_43 )
{
T_2 * V_48 = V_2 -> V_20 -> V_49 ;
F_23 ( V_208 ,
F_56 ( V_209 ) ) ;
F_148 ( V_210 , 0x0 ) ;
if ( F_38 ( ( F_21 ( V_208 ) &
V_211 ) == 0 ,
50 ) )
F_36 ( L_13 ) ;
F_17 ( V_2 , V_43 ) ;
F_84 ( F_149 ( V_2 -> V_52 ) ) ;
F_23 ( V_208 ,
F_58 ( V_209 ) ) ;
}
static int F_150 ( struct V_1 * V_2 ,
T_1 V_212 , T_1 V_213 )
{
T_3 V_11 ;
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
V_11 = V_214 ;
if ( V_212 & V_215 )
V_11 |= V_216 | V_217 |
V_218 | V_219 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_220 | V_221 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_151 ( struct V_1 * V_2 ,
T_1 V_149 , T_1 V_155 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_151 | V_222 |
( V_34 & V_153 ? 0 : V_223 ) ) ;
F_4 ( V_2 , V_149 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int
F_152 ( struct V_1 * V_2 ,
T_1 V_149 , T_1 V_155 ,
unsigned V_34 )
{
int V_12 ;
V_12 = F_3 ( V_2 , 2 ) ;
if ( V_12 )
return V_12 ;
F_4 ( V_2 ,
V_151 |
( V_34 & V_153 ? 0 : V_154 ) ) ;
F_4 ( V_2 , V_149 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 ,
T_1 V_212 , T_1 V_213 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
T_3 V_11 ;
int V_12 ;
V_12 = F_3 ( V_2 , 4 ) ;
if ( V_12 )
return V_12 ;
V_11 = V_214 ;
if ( V_212 & V_14 )
V_11 |= V_216 | V_218 |
V_219 ;
F_4 ( V_2 , V_11 ) ;
F_4 ( V_2 , V_220 | V_221 ) ;
F_4 ( V_2 , 0 ) ;
F_4 ( V_2 , V_18 ) ;
F_5 ( V_2 ) ;
if ( F_57 ( V_20 ) && V_213 )
return F_13 ( V_2 , V_224 ) ;
return 0 ;
}
int F_154 ( struct V_19 * V_20 )
{
T_2 * V_48 = V_20 -> V_49 ;
struct V_1 * V_2 = & V_48 -> V_2 [ V_131 ] ;
V_2 -> V_62 = L_14 ;
V_2 -> V_116 = V_131 ;
V_2 -> V_52 = V_225 ;
if ( F_19 ( V_20 ) -> V_51 >= 6 ) {
V_2 -> V_226 = F_67 ;
V_2 -> V_213 = F_15 ;
if ( F_19 ( V_20 ) -> V_51 == 6 )
V_2 -> V_213 = F_11 ;
V_2 -> V_227 = F_98 ;
V_2 -> V_228 = F_99 ;
V_2 -> V_126 = V_229 ;
V_2 -> V_230 = F_75 ;
V_2 -> V_206 = F_78 ;
V_2 -> V_231 = F_70 ;
V_2 -> V_115 [ V_131 ] = V_117 ;
V_2 -> V_115 [ V_135 ] = V_232 ;
V_2 -> V_115 [ V_133 ] = V_233 ;
V_2 -> V_115 [ V_137 ] = V_234 ;
V_2 -> V_101 [ V_131 ] = V_102 ;
V_2 -> V_101 [ V_135 ] = V_235 ;
V_2 -> V_101 [ V_133 ] = V_236 ;
V_2 -> V_101 [ V_137 ] = V_237 ;
} else if ( F_8 ( V_20 ) ) {
V_2 -> V_226 = F_73 ;
V_2 -> V_213 = F_6 ;
V_2 -> V_230 = F_80 ;
V_2 -> V_206 = F_81 ;
V_2 -> V_227 = F_82 ;
V_2 -> V_228 = F_86 ;
V_2 -> V_126 = V_229 |
V_238 ;
} else {
V_2 -> V_226 = F_97 ;
if ( F_19 ( V_20 ) -> V_51 < 4 )
V_2 -> V_213 = F_2 ;
else
V_2 -> V_213 = F_6 ;
V_2 -> V_230 = F_77 ;
V_2 -> V_206 = F_78 ;
if ( F_155 ( V_20 ) ) {
V_2 -> V_227 = F_89 ;
V_2 -> V_228 = F_92 ;
} else {
V_2 -> V_227 = F_87 ;
V_2 -> V_228 = F_88 ;
}
V_2 -> V_126 = V_239 ;
}
V_2 -> V_61 = F_16 ;
if ( F_156 ( V_20 ) )
V_2 -> V_240 = F_151 ;
else if ( F_19 ( V_20 ) -> V_51 >= 6 )
V_2 -> V_240 = F_152 ;
else if ( F_19 ( V_20 ) -> V_51 >= 4 )
V_2 -> V_240 = F_102 ;
else if ( F_118 ( V_20 ) || F_119 ( V_20 ) )
V_2 -> V_240 = F_103 ;
else
V_2 -> V_240 = F_105 ;
V_2 -> V_178 = F_55 ;
V_2 -> V_181 = F_62 ;
if ( F_63 ( V_20 ) ) {
struct V_59 * V_60 ;
int V_12 ;
V_60 = F_44 ( V_20 , V_160 ) ;
if ( V_60 == NULL ) {
F_36 ( L_15 ) ;
return - V_73 ;
}
V_12 = F_46 ( V_60 , 0 , true , false ) ;
if ( V_12 != 0 ) {
F_51 ( & V_60 -> V_81 ) ;
F_36 ( L_16 ) ;
return V_12 ;
}
V_2 -> V_27 = V_60 ;
}
return F_110 ( V_20 , V_2 ) ;
}
int F_157 ( struct V_19 * V_20 , T_5 V_241 , T_1 V_8 )
{
T_2 * V_48 = V_20 -> V_49 ;
struct V_1 * V_2 = & V_48 -> V_2 [ V_131 ] ;
int V_12 ;
V_2 -> V_62 = L_14 ;
V_2 -> V_116 = V_131 ;
V_2 -> V_52 = V_225 ;
if ( F_19 ( V_20 ) -> V_51 >= 6 ) {
return - V_242 ;
}
V_2 -> V_226 = F_97 ;
if ( F_19 ( V_20 ) -> V_51 < 4 )
V_2 -> V_213 = F_2 ;
else
V_2 -> V_213 = F_6 ;
V_2 -> V_230 = F_77 ;
V_2 -> V_206 = F_78 ;
if ( F_155 ( V_20 ) ) {
V_2 -> V_227 = F_89 ;
V_2 -> V_228 = F_92 ;
} else {
V_2 -> V_227 = F_87 ;
V_2 -> V_228 = F_88 ;
}
V_2 -> V_126 = V_239 ;
V_2 -> V_61 = F_16 ;
if ( F_19 ( V_20 ) -> V_51 >= 4 )
V_2 -> V_240 = F_102 ;
else if ( F_118 ( V_20 ) || F_119 ( V_20 ) )
V_2 -> V_240 = F_103 ;
else
V_2 -> V_240 = F_105 ;
V_2 -> V_178 = F_55 ;
V_2 -> V_181 = F_62 ;
V_2 -> V_20 = V_20 ;
F_111 ( & V_2 -> V_169 ) ;
F_111 ( & V_2 -> V_170 ) ;
V_2 -> V_8 = V_8 ;
V_2 -> V_180 = V_2 -> V_8 ;
if ( F_118 ( V_2 -> V_20 ) || F_119 ( V_2 -> V_20 ) )
V_2 -> V_180 -= 128 ;
V_2 -> V_174 = F_117 ( V_241 , V_8 ) ;
if ( V_2 -> V_174 == NULL ) {
F_36 ( L_17
L_18 ) ;
return - V_73 ;
}
if ( ! F_27 ( V_20 ) ) {
V_12 = F_108 ( V_2 ) ;
if ( V_12 )
return V_12 ;
}
return 0 ;
}
int F_158 ( struct V_19 * V_20 )
{
T_2 * V_48 = V_20 -> V_49 ;
struct V_1 * V_2 = & V_48 -> V_2 [ V_135 ] ;
V_2 -> V_62 = L_19 ;
V_2 -> V_116 = V_135 ;
V_2 -> V_61 = F_16 ;
if ( F_59 ( V_20 ) || F_57 ( V_20 ) ) {
V_2 -> V_52 = V_243 ;
if ( F_59 ( V_20 ) )
V_2 -> V_61 = F_147 ;
V_2 -> V_213 = F_150 ;
V_2 -> V_226 = F_67 ;
V_2 -> V_230 = F_75 ;
V_2 -> V_206 = F_78 ;
V_2 -> V_126 = V_244 ;
V_2 -> V_227 = F_98 ;
V_2 -> V_228 = F_99 ;
V_2 -> V_240 = F_152 ;
V_2 -> V_231 = F_70 ;
V_2 -> V_115 [ V_131 ] = V_245 ;
V_2 -> V_115 [ V_135 ] = V_117 ;
V_2 -> V_115 [ V_133 ] = V_246 ;
V_2 -> V_115 [ V_137 ] = V_247 ;
V_2 -> V_101 [ V_131 ] = V_248 ;
V_2 -> V_101 [ V_135 ] = V_102 ;
V_2 -> V_101 [ V_133 ] = V_249 ;
V_2 -> V_101 [ V_137 ] = V_250 ;
} else {
V_2 -> V_52 = V_251 ;
V_2 -> V_213 = F_96 ;
V_2 -> V_226 = F_97 ;
V_2 -> V_230 = F_77 ;
V_2 -> V_206 = F_78 ;
if ( F_8 ( V_20 ) ) {
V_2 -> V_126 = V_252 ;
V_2 -> V_227 = F_82 ;
V_2 -> V_228 = F_86 ;
} else {
V_2 -> V_126 = V_253 ;
V_2 -> V_227 = F_87 ;
V_2 -> V_228 = F_88 ;
}
V_2 -> V_240 = F_102 ;
}
V_2 -> V_178 = F_24 ;
return F_110 ( V_20 , V_2 ) ;
}
int F_159 ( struct V_19 * V_20 )
{
T_2 * V_48 = V_20 -> V_49 ;
struct V_1 * V_2 = & V_48 -> V_2 [ V_133 ] ;
V_2 -> V_62 = L_20 ;
V_2 -> V_116 = V_133 ;
V_2 -> V_52 = V_254 ;
V_2 -> V_61 = F_16 ;
V_2 -> V_213 = F_153 ;
V_2 -> V_226 = F_67 ;
V_2 -> V_230 = F_75 ;
V_2 -> V_206 = F_78 ;
V_2 -> V_126 = V_255 ;
V_2 -> V_227 = F_98 ;
V_2 -> V_228 = F_99 ;
V_2 -> V_240 = F_152 ;
V_2 -> V_231 = F_70 ;
V_2 -> V_115 [ V_131 ] = V_256 ;
V_2 -> V_115 [ V_135 ] = V_257 ;
V_2 -> V_115 [ V_133 ] = V_117 ;
V_2 -> V_115 [ V_137 ] = V_258 ;
V_2 -> V_101 [ V_131 ] = V_259 ;
V_2 -> V_101 [ V_135 ] = V_260 ;
V_2 -> V_101 [ V_133 ] = V_102 ;
V_2 -> V_101 [ V_137 ] = V_261 ;
V_2 -> V_178 = F_24 ;
return F_110 ( V_20 , V_2 ) ;
}
int F_160 ( struct V_19 * V_20 )
{
T_2 * V_48 = V_20 -> V_49 ;
struct V_1 * V_2 = & V_48 -> V_2 [ V_137 ] ;
V_2 -> V_62 = L_21 ;
V_2 -> V_116 = V_137 ;
V_2 -> V_52 = V_262 ;
V_2 -> V_61 = F_16 ;
V_2 -> V_213 = F_153 ;
V_2 -> V_226 = F_67 ;
V_2 -> V_230 = F_75 ;
V_2 -> V_206 = F_78 ;
V_2 -> V_126 = V_263 |
V_264 ;
V_2 -> V_227 = F_100 ;
V_2 -> V_228 = F_101 ;
V_2 -> V_240 = F_152 ;
V_2 -> V_231 = F_70 ;
V_2 -> V_115 [ V_131 ] = V_265 ;
V_2 -> V_115 [ V_135 ] = V_266 ;
V_2 -> V_115 [ V_133 ] = V_267 ;
V_2 -> V_115 [ V_137 ] = V_117 ;
V_2 -> V_101 [ V_131 ] = V_268 ;
V_2 -> V_101 [ V_135 ] = V_269 ;
V_2 -> V_101 [ V_133 ] = V_270 ;
V_2 -> V_101 [ V_137 ] = V_102 ;
V_2 -> V_178 = F_24 ;
return F_110 ( V_20 , V_2 ) ;
}
int
F_161 ( struct V_1 * V_2 )
{
int V_12 ;
if ( ! V_2 -> V_271 )
return 0 ;
V_12 = V_2 -> V_213 ( V_2 , 0 , V_215 ) ;
if ( V_12 )
return V_12 ;
F_162 ( V_2 , 0 , V_215 ) ;
V_2 -> V_271 = false ;
return 0 ;
}
int
F_163 ( struct V_1 * V_2 )
{
T_3 V_10 ;
int V_12 ;
V_10 = 0 ;
if ( V_2 -> V_271 )
V_10 = V_215 ;
V_12 = V_2 -> V_213 ( V_2 , V_215 , V_10 ) ;
if ( V_12 )
return V_12 ;
F_162 ( V_2 , V_215 , V_10 ) ;
V_2 -> V_271 = false ;
return 0 ;
}
