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
struct V_10 * V_11 = V_2 -> V_11 ;
T_1 V_12 ;
int V_13 ;
V_12 = V_14 | V_15 ;
if ( ( V_8 | V_9 ) &
V_16 )
V_12 &= ~ V_15 ;
if ( F_3 ( V_11 ) -> V_17 < 4 ) {
if ( V_8 & V_18 )
V_12 |= V_19 ;
}
if ( V_8 & V_20 )
V_12 |= V_21 ;
if ( V_8 & V_22 &&
( F_4 ( V_11 ) || F_5 ( V_11 ) ) )
V_12 |= V_23 ;
V_13 = F_6 ( V_2 , 2 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , V_12 ) ;
F_7 ( V_2 , V_24 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_13 ;
V_13 = F_6 ( V_2 , 6 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , F_10 ( 5 ) ) ;
F_7 ( V_2 , V_30 |
V_31 ) ;
F_7 ( V_2 , V_28 | V_32 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , V_24 ) ;
F_8 ( V_2 ) ;
V_13 = F_6 ( V_2 , 6 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , F_10 ( 5 ) ) ;
F_7 ( V_2 , V_33 ) ;
F_7 ( V_2 , V_28 | V_32 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , V_24 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 ,
T_1 V_8 , T_1 V_9 )
{
T_1 V_34 = 0 ;
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_13 ;
F_9 ( V_2 ) ;
V_34 |= V_35 ;
V_34 |= V_36 ;
V_34 |= V_37 ;
V_34 |= V_38 ;
V_34 |= V_39 ;
V_34 |= V_40 ;
V_34 |= V_41 ;
V_13 = F_6 ( V_2 , 6 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , F_10 ( 5 ) ) ;
F_7 ( V_2 , V_34 ) ;
F_7 ( V_2 , V_28 | V_32 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , V_24 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 V_42 )
{
T_2 * V_43 = V_2 -> V_11 -> V_44 ;
F_13 ( V_2 , V_42 ) ;
}
T_1 F_14 ( struct V_1 * V_2 )
{
T_2 * V_43 = V_2 -> V_11 -> V_44 ;
T_1 V_45 = F_3 ( V_2 -> V_11 ) -> V_17 >= 4 ?
F_15 ( V_2 -> V_46 ) : V_47 ;
return F_16 ( V_45 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_2 * V_43 = V_2 -> V_11 -> V_44 ;
struct V_48 * V_49 = V_2 -> V_49 ;
T_1 V_4 ;
F_18 ( V_2 , 0 ) ;
F_19 ( V_2 , 0 ) ;
V_2 -> V_50 ( V_2 , 0 ) ;
F_20 ( V_2 , V_49 -> V_29 ) ;
V_4 = F_21 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_22 ( L_1
L_2 ,
V_2 -> V_51 ,
F_23 ( V_2 ) ,
F_21 ( V_2 ) ,
F_24 ( V_2 ) ,
F_25 ( V_2 ) ) ;
F_19 ( V_2 , 0 ) ;
if ( F_21 ( V_2 ) & V_5 ) {
F_26 ( L_3
L_2 ,
V_2 -> V_51 ,
F_23 ( V_2 ) ,
F_21 ( V_2 ) ,
F_24 ( V_2 ) ,
F_25 ( V_2 ) ) ;
}
}
F_18 ( V_2 ,
( ( V_2 -> V_7 - V_52 ) & V_53 )
| V_54 ) ;
if ( ( F_23 ( V_2 ) & V_54 ) == 0 ||
F_25 ( V_2 ) != V_49 -> V_29 ||
( F_21 ( V_2 ) & V_5 ) != 0 ) {
F_26 ( L_4
L_2 ,
V_2 -> V_51 ,
F_23 ( V_2 ) ,
F_21 ( V_2 ) ,
F_24 ( V_2 ) ,
F_25 ( V_2 ) ) ;
return - V_55 ;
}
if ( ! F_27 ( V_2 -> V_11 , V_56 ) )
F_28 ( V_2 -> V_11 ) ;
else {
V_2 -> V_4 = F_21 ( V_2 ) ;
V_2 -> V_6 = F_24 ( V_2 ) & V_57 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
}
return 0 ;
}
static int
F_29 ( struct V_1 * V_2 )
{
struct V_25 * V_26 ;
struct V_48 * V_49 ;
int V_13 ;
if ( V_2 -> V_27 )
return 0 ;
V_26 = F_30 ( sizeof( * V_26 ) , V_58 ) ;
if ( ! V_26 )
return - V_59 ;
V_49 = F_31 ( V_2 -> V_11 , 4096 ) ;
if ( V_49 == NULL ) {
F_26 ( L_5 ) ;
V_13 = - V_59 ;
goto V_60;
}
F_32 ( V_49 , V_61 ) ;
V_13 = F_33 ( V_49 , 4096 , true ) ;
if ( V_13 )
goto V_62;
V_26 -> V_29 = V_49 -> V_29 ;
V_26 -> V_63 = F_34 ( V_49 -> V_64 [ 0 ] ) ;
if ( V_26 -> V_63 == NULL )
goto V_65;
V_26 -> V_49 = V_49 ;
V_2 -> V_27 = V_26 ;
return 0 ;
V_65:
F_35 ( V_49 ) ;
V_62:
F_36 ( & V_49 -> V_66 ) ;
V_60:
F_37 ( V_26 ) ;
return V_13 ;
}
static void
F_38 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
struct V_48 * V_49 ;
if ( ! V_2 -> V_27 )
return;
V_49 = V_26 -> V_49 ;
F_39 ( V_49 -> V_64 [ 0 ] ) ;
F_35 ( V_49 ) ;
F_36 ( & V_49 -> V_66 ) ;
F_37 ( V_26 ) ;
V_2 -> V_27 = NULL ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_67 * V_43 = V_11 -> V_44 ;
int V_13 = F_17 ( V_2 ) ;
if ( F_3 ( V_11 ) -> V_17 > 3 ) {
int V_68 = V_69 << 16 | V_69 ;
F_41 ( V_70 , V_68 ) ;
if ( F_42 ( V_11 ) )
F_41 ( V_71 ,
F_43 ( V_72 ) |
F_44 ( V_73 ) ) ;
}
if ( F_3 ( V_11 ) -> V_17 >= 5 ) {
V_13 = F_29 ( V_2 ) ;
if ( V_13 )
return V_13 ;
}
if ( F_45 ( V_11 ) ) {
F_41 ( V_74 ,
V_75 << V_76 ) ;
}
if ( F_3 ( V_11 ) -> V_17 >= 6 ) {
F_41 ( V_77 ,
V_78 << 16 | V_78 ) ;
}
return V_13 ;
}
static void F_46 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_27 )
return;
F_38 ( V_2 ) ;
}
static void
F_47 ( struct V_1 * V_2 ,
T_1 V_79 ,
T_1 V_80 )
{
F_7 ( V_2 , V_81 |
V_82 |
V_83 |
V_84 ) ;
F_7 ( V_2 , V_79 ) ;
F_7 ( V_2 , V_80 ) ;
}
static int
F_48 ( struct V_1 * V_2 ,
T_1 * V_79 )
{
T_1 V_85 ;
T_1 V_86 ;
int V_13 ;
V_13 = F_6 ( V_2 , 10 ) ;
if ( V_13 )
return V_13 ;
V_85 = V_2 -> V_87 [ 0 ] ;
V_86 = V_2 -> V_87 [ 1 ] ;
* V_79 = F_49 ( V_2 ) ;
F_47 ( V_2 , * V_79 , V_85 ) ;
F_47 ( V_2 , * V_79 , V_86 ) ;
F_7 ( V_2 , V_88 ) ;
F_7 ( V_2 , V_89 << V_90 ) ;
F_7 ( V_2 , * V_79 ) ;
F_7 ( V_2 , V_91 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_92 ,
struct V_1 * V_93 ,
int V_2 ,
T_1 V_79 )
{
int V_13 ;
T_1 V_94 = V_81 |
V_95 |
V_83 ;
V_13 = F_6 ( V_92 , 4 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_92 , V_94 | V_93 -> V_96 [ V_2 ] ) ;
F_7 ( V_92 , V_79 ) ;
F_7 ( V_92 , 0 ) ;
F_7 ( V_92 , V_24 ) ;
F_8 ( V_92 ) ;
return 0 ;
}
int
F_51 ( struct V_1 * V_92 ,
struct V_1 * V_93 ,
T_1 V_79 )
{
F_52 ( V_93 -> V_96 [ V_97 ] == V_98 ) ;
return F_50 ( V_92 ,
V_93 ,
V_97 ,
V_79 ) ;
}
int
F_53 ( struct V_1 * V_92 ,
struct V_1 * V_93 ,
T_1 V_79 )
{
F_52 ( V_93 -> V_96 [ V_99 ] == V_98 ) ;
return F_50 ( V_92 ,
V_93 ,
V_99 ,
V_79 ) ;
}
int
F_54 ( struct V_1 * V_92 ,
struct V_1 * V_93 ,
T_1 V_79 )
{
F_52 ( V_93 -> V_96 [ V_100 ] == V_98 ) ;
return F_50 ( V_92 ,
V_93 ,
V_100 ,
V_79 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
T_1 * V_101 )
{
T_1 V_79 = F_49 ( V_2 ) ;
struct V_25 * V_26 = V_2 -> V_27 ;
T_1 V_28 = V_26 -> V_29 + 128 ;
int V_13 ;
V_13 = F_6 ( V_2 , 32 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , F_10 ( 4 ) | V_33 |
V_102 |
V_37 ) ;
F_7 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_7 ( V_2 , V_79 ) ;
F_7 ( V_2 , 0 ) ;
F_56 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_56 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_56 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_56 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_56 ( V_2 , V_28 ) ;
V_28 += 128 ;
F_56 ( V_2 , V_28 ) ;
F_7 ( V_2 , F_10 ( 4 ) | V_33 |
V_102 |
V_37 |
V_103 ) ;
F_7 ( V_2 , V_26 -> V_29 | V_32 ) ;
F_7 ( V_2 , V_79 ) ;
F_7 ( V_2 , 0 ) ;
F_8 ( V_2 ) ;
* V_101 = V_79 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 ,
T_1 * V_101 )
{
T_1 V_79 = F_49 ( V_2 ) ;
int V_13 ;
V_13 = F_6 ( V_2 , 4 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , V_88 ) ;
F_7 ( V_2 , V_89 << V_90 ) ;
F_7 ( V_2 , V_79 ) ;
F_7 ( V_2 , V_91 ) ;
F_8 ( V_2 ) ;
* V_101 = V_79 ;
return 0 ;
}
static T_1
F_58 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
if ( F_45 ( V_11 ) || F_42 ( V_11 ) )
F_14 ( V_2 ) ;
return F_59 ( V_2 , V_89 ) ;
}
static T_1
F_60 ( struct V_1 * V_2 )
{
return F_59 ( V_2 , V_89 ) ;
}
static T_1
F_61 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
return V_26 -> V_63 [ 0 ] ;
}
static void
F_62 ( T_2 * V_43 , T_1 V_104 )
{
V_43 -> V_105 &= ~ V_104 ;
F_41 ( V_106 , V_43 -> V_105 ) ;
F_63 ( V_106 ) ;
}
static void
F_64 ( T_2 * V_43 , T_1 V_104 )
{
V_43 -> V_105 |= V_104 ;
F_41 ( V_106 , V_43 -> V_105 ) ;
F_63 ( V_106 ) ;
}
static void
F_65 ( T_2 * V_43 , T_1 V_104 )
{
V_43 -> V_107 &= ~ V_104 ;
F_41 ( V_108 , V_43 -> V_107 ) ;
F_63 ( V_108 ) ;
}
static void
F_66 ( T_2 * V_43 , T_1 V_104 )
{
V_43 -> V_107 |= V_104 ;
F_41 ( V_108 , V_43 -> V_107 ) ;
F_63 ( V_108 ) ;
}
static bool
F_67 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_11 -> V_44 ;
if ( ! V_11 -> V_109 )
return false ;
F_68 ( & V_2 -> V_110 ) ;
if ( V_2 -> V_111 ++ == 0 ) {
if ( F_69 ( V_11 ) )
F_62 ( V_43 ,
V_112 | V_113 ) ;
else
F_65 ( V_43 , V_114 ) ;
}
F_70 ( & V_2 -> V_110 ) ;
return true ;
}
static void
F_71 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_11 -> V_44 ;
F_68 ( & V_2 -> V_110 ) ;
if ( -- V_2 -> V_111 == 0 ) {
if ( F_69 ( V_11 ) )
F_64 ( V_43 ,
V_113 |
V_112 ) ;
else
F_66 ( V_43 , V_114 ) ;
}
F_70 ( & V_2 -> V_110 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_2 -> V_11 -> V_44 ;
T_1 V_115 = 0 ;
if ( F_42 ( V_11 ) ) {
switch ( V_2 -> V_116 ) {
case V_97 :
V_115 = V_117 ;
break;
case V_100 :
V_115 = V_118 ;
break;
case V_99 :
V_115 = V_119 ;
break;
}
} else if ( F_45 ( V_2 -> V_11 ) ) {
V_115 = F_73 ( V_2 -> V_46 ) ;
} else {
V_115 = F_74 ( V_2 -> V_46 ) ;
}
F_41 ( V_115 , ( T_1 ) V_2 -> V_120 . V_121 ) ;
F_63 ( V_115 ) ;
}
static int
F_75 ( struct V_1 * V_2 ,
T_1 V_8 ,
T_1 V_9 )
{
int V_13 ;
V_13 = F_6 ( V_2 , 2 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , V_14 ) ;
F_7 ( V_2 , V_24 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_76 ( struct V_1 * V_2 ,
T_1 * V_101 )
{
T_1 V_79 ;
int V_13 ;
V_13 = F_6 ( V_2 , 4 ) ;
if ( V_13 )
return V_13 ;
V_79 = F_49 ( V_2 ) ;
F_7 ( V_2 , V_88 ) ;
F_7 ( V_2 , V_89 << V_90 ) ;
F_7 ( V_2 , V_79 ) ;
F_7 ( V_2 , V_91 ) ;
F_8 ( V_2 ) ;
* V_101 = V_79 ;
return 0 ;
}
static bool
F_77 ( struct V_1 * V_2 , T_1 V_122 , T_1 V_123 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_11 -> V_44 ;
if ( ! V_11 -> V_109 )
return false ;
F_78 ( V_43 ) ;
F_68 ( & V_2 -> V_110 ) ;
if ( V_2 -> V_111 ++ == 0 ) {
V_2 -> V_107 &= ~ V_123 ;
F_79 ( V_2 , V_2 -> V_107 ) ;
F_62 ( V_43 , V_122 ) ;
}
F_70 ( & V_2 -> V_110 ) ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 , T_1 V_122 , T_1 V_123 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_11 -> V_44 ;
F_68 ( & V_2 -> V_110 ) ;
if ( -- V_2 -> V_111 == 0 ) {
V_2 -> V_107 |= V_123 ;
F_79 ( V_2 , V_2 -> V_107 ) ;
F_64 ( V_43 , V_122 ) ;
}
F_70 ( & V_2 -> V_110 ) ;
F_81 ( V_43 ) ;
}
static bool
F_82 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_11 -> V_44 ;
if ( ! V_11 -> V_109 )
return false ;
F_68 ( & V_2 -> V_110 ) ;
if ( V_2 -> V_111 ++ == 0 ) {
if ( F_4 ( V_11 ) )
F_65 ( V_43 , V_124 ) ;
else
F_62 ( V_43 , V_125 ) ;
}
F_70 ( & V_2 -> V_110 ) ;
return true ;
}
static void
F_83 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_11 -> V_44 ;
F_68 ( & V_2 -> V_110 ) ;
if ( -- V_2 -> V_111 == 0 ) {
if ( F_4 ( V_11 ) )
F_66 ( V_43 , V_124 ) ;
else
F_64 ( V_43 , V_125 ) ;
}
F_70 ( & V_2 -> V_110 ) ;
}
static int
F_84 ( struct V_1 * V_2 , T_1 V_126 , T_1 V_127 )
{
int V_13 ;
V_13 = F_6 ( V_2 , 2 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 ,
V_128 | ( 2 << 6 ) |
V_129 ) ;
F_7 ( V_2 , V_126 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_85 ( struct V_1 * V_2 ,
T_1 V_126 , T_1 V_130 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
int V_13 ;
if ( F_86 ( V_11 ) || F_87 ( V_11 ) ) {
V_13 = F_6 ( V_2 , 4 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , V_131 ) ;
F_7 ( V_2 , V_126 | V_132 ) ;
F_7 ( V_2 , V_126 + V_130 - 8 ) ;
F_7 ( V_2 , 0 ) ;
} else {
V_13 = F_6 ( V_2 , 2 ) ;
if ( V_13 )
return V_13 ;
if ( F_3 ( V_11 ) -> V_17 >= 4 ) {
F_7 ( V_2 ,
V_128 | ( 2 << 6 ) |
V_129 ) ;
F_7 ( V_2 , V_126 ) ;
} else {
F_7 ( V_2 ,
V_128 | ( 2 << 6 ) ) ;
F_7 ( V_2 , V_126 | V_132 ) ;
}
}
F_8 ( V_2 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
T_2 * V_43 = V_2 -> V_11 -> V_44 ;
struct V_48 * V_49 ;
V_49 = V_2 -> V_120 . V_49 ;
if ( V_49 == NULL )
return;
F_39 ( V_49 -> V_64 [ 0 ] ) ;
F_35 ( V_49 ) ;
F_36 ( & V_49 -> V_66 ) ;
V_2 -> V_120 . V_49 = NULL ;
memset ( & V_43 -> V_133 , 0 , sizeof( V_43 -> V_133 ) ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
T_2 * V_43 = V_11 -> V_44 ;
struct V_48 * V_49 ;
int V_13 ;
V_49 = F_31 ( V_11 , 4096 ) ;
if ( V_49 == NULL ) {
F_26 ( L_6 ) ;
V_13 = - V_59 ;
goto V_60;
}
F_32 ( V_49 , V_61 ) ;
V_13 = F_33 ( V_49 , 4096 , true ) ;
if ( V_13 != 0 ) {
goto V_62;
}
V_2 -> V_120 . V_121 = V_49 -> V_29 ;
V_2 -> V_120 . V_134 = F_34 ( V_49 -> V_64 [ 0 ] ) ;
if ( V_2 -> V_120 . V_134 == NULL ) {
memset ( & V_43 -> V_133 , 0 , sizeof( V_43 -> V_133 ) ) ;
goto V_65;
}
V_2 -> V_120 . V_49 = V_49 ;
memset ( V_2 -> V_120 . V_134 , 0 , V_52 ) ;
F_72 ( V_2 ) ;
F_90 ( L_7 ,
V_2 -> V_51 , V_2 -> V_120 . V_121 ) ;
return 0 ;
V_65:
F_35 ( V_49 ) ;
V_62:
F_36 ( & V_49 -> V_66 ) ;
V_60:
return V_13 ;
}
int F_91 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_48 * V_49 ;
int V_13 ;
V_2 -> V_11 = V_11 ;
F_92 ( & V_2 -> V_135 ) ;
F_92 ( & V_2 -> V_136 ) ;
F_92 ( & V_2 -> V_137 ) ;
F_93 ( & V_2 -> V_138 ) ;
F_94 ( & V_2 -> V_110 ) ;
V_2 -> V_107 = ~ 0 ;
if ( F_95 ( V_11 ) ) {
V_13 = F_89 ( V_2 ) ;
if ( V_13 )
return V_13 ;
}
V_49 = F_31 ( V_11 , V_2 -> V_7 ) ;
if ( V_49 == NULL ) {
F_26 ( L_8 ) ;
V_13 = - V_59 ;
goto V_139;
}
V_2 -> V_49 = V_49 ;
V_13 = F_33 ( V_49 , V_52 , true ) ;
if ( V_13 )
goto V_62;
V_2 -> V_140 . V_7 = V_2 -> V_7 ;
V_2 -> V_140 . V_126 = V_11 -> V_141 -> V_66 + V_49 -> V_29 ;
V_2 -> V_140 . type = 0 ;
V_2 -> V_140 . V_34 = 0 ;
V_2 -> V_140 . V_142 = 0 ;
F_96 ( & V_2 -> V_140 , V_11 ) ;
if ( V_2 -> V_140 . V_143 == NULL ) {
F_26 ( L_9 ) ;
V_13 = - V_144 ;
goto V_65;
}
V_2 -> V_145 = V_2 -> V_140 . V_143 ;
V_13 = V_2 -> V_146 ( V_2 ) ;
if ( V_13 )
goto V_147;
V_2 -> V_148 = V_2 -> V_7 ;
if ( F_86 ( V_2 -> V_11 ) || F_87 ( V_2 -> V_11 ) )
V_2 -> V_148 -= 128 ;
return 0 ;
V_147:
F_97 ( & V_2 -> V_140 , V_11 ) ;
V_65:
F_35 ( V_49 ) ;
V_62:
F_36 ( & V_49 -> V_66 ) ;
V_2 -> V_49 = NULL ;
V_139:
F_88 ( V_2 ) ;
return V_13 ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_67 * V_43 ;
int V_13 ;
if ( V_2 -> V_49 == NULL )
return;
V_43 = V_2 -> V_11 -> V_44 ;
V_13 = F_99 ( V_2 ) ;
if ( V_13 )
F_26 ( L_10 ,
V_2 -> V_51 , V_13 ) ;
F_18 ( V_2 , 0 ) ;
F_97 ( & V_2 -> V_140 , V_2 -> V_11 ) ;
F_35 ( V_2 -> V_49 ) ;
F_36 ( & V_2 -> V_49 -> V_66 ) ;
V_2 -> V_49 = NULL ;
if ( V_2 -> V_149 )
V_2 -> V_149 ( V_2 ) ;
F_88 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
unsigned int * V_150 ;
int V_151 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_151 ) {
int V_13 = F_101 ( V_2 , V_151 ) ;
if ( V_13 )
return V_13 ;
}
V_150 = ( unsigned int * ) ( V_2 -> V_145 + V_2 -> V_6 ) ;
V_151 /= 8 ;
while ( V_151 -- ) {
* V_150 ++ = V_24 ;
* V_150 ++ = V_24 ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
static int F_102 ( struct V_1 * V_2 , T_1 V_79 )
{
struct V_67 * V_43 = V_2 -> V_11 -> V_44 ;
bool V_152 ;
int V_13 ;
V_152 = V_43 -> V_153 . V_154 ;
V_43 -> V_153 . V_154 = false ;
V_13 = F_103 ( V_2 , V_79 , true ) ;
V_43 -> V_153 . V_154 = V_152 ;
return V_13 ;
}
static int F_104 ( struct V_1 * V_2 , int V_155 )
{
struct V_156 * V_157 ;
T_1 V_79 = 0 ;
int V_13 ;
F_105 ( V_2 ) ;
if ( V_2 -> V_158 != - 1 ) {
V_2 -> V_4 = V_2 -> V_158 ;
V_2 -> V_158 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_155 )
return 0 ;
}
F_106 (request, &ring->request_list, list) {
int V_3 ;
if ( V_157 -> V_6 == - 1 )
continue;
V_3 = V_157 -> V_6 - ( V_2 -> V_6 + 8 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_7 ;
if ( V_3 >= V_155 ) {
V_79 = V_157 -> V_79 ;
break;
}
V_157 -> V_6 = - 1 ;
}
if ( V_79 == 0 )
return - V_159 ;
V_13 = F_102 ( V_2 , V_79 ) ;
if ( V_13 )
return V_13 ;
if ( F_52 ( V_2 -> V_158 == - 1 ) )
return - V_159 ;
V_2 -> V_4 = V_2 -> V_158 ;
V_2 -> V_158 = - 1 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( F_52 ( V_2 -> V_3 < V_155 ) )
return - V_159 ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_155 )
{
struct V_10 * V_11 = V_2 -> V_11 ;
struct V_67 * V_43 = V_11 -> V_44 ;
unsigned long V_160 ;
int V_13 ;
V_13 = F_104 ( V_2 , V_155 ) ;
if ( V_13 != - V_159 )
return V_13 ;
F_107 ( V_2 ) ;
if ( F_27 ( V_11 , V_161 ) )
V_160 = V_162 + 60 * V_163 ;
else
V_160 = V_162 + 3 * V_163 ;
do {
V_2 -> V_4 = F_21 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_155 ) {
F_108 ( V_2 ) ;
return 0 ;
}
if ( V_11 -> V_164 -> V_165 ) {
struct V_166 * V_167 = V_11 -> V_164 -> V_165 -> V_168 ;
if ( V_167 -> V_169 )
V_167 -> V_169 -> V_170 |= V_171 ;
}
F_109 ( 1 ) ;
if ( F_110 ( & V_43 -> V_153 . V_172 ) )
return - V_173 ;
} while ( ! F_111 ( V_162 , V_160 ) );
F_108 ( V_2 ) ;
return - V_174 ;
}
int F_6 ( struct V_1 * V_2 ,
int V_175 )
{
struct V_67 * V_43 = V_2 -> V_11 -> V_44 ;
int V_155 = 4 * V_175 ;
int V_13 ;
if ( F_112 ( F_110 ( & V_43 -> V_153 . V_172 ) ) )
return - V_55 ;
if ( F_112 ( V_2 -> V_6 + V_155 > V_2 -> V_148 ) ) {
V_13 = F_100 ( V_2 ) ;
if ( F_112 ( V_13 ) )
return V_13 ;
}
if ( F_112 ( V_2 -> V_3 < V_155 ) ) {
V_13 = F_101 ( V_2 , V_155 ) ;
if ( F_112 ( V_13 ) )
return V_13 ;
}
V_2 -> V_3 -= V_155 ;
return 0 ;
}
void F_8 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
V_2 -> V_50 ( V_2 , V_2 -> V_6 ) ;
}
static void F_113 ( struct V_1 * V_2 ,
T_1 V_42 )
{
T_2 * V_43 = V_2 -> V_11 -> V_44 ;
F_41 ( V_176 ,
V_177 |
V_178 ) ;
F_41 ( V_179 , 0x0 ) ;
if ( F_114 ( ( F_16 ( V_176 ) &
V_180 ) == 0 ,
50 ) )
F_26 ( L_11 ) ;
F_13 ( V_2 , V_42 ) ;
F_41 ( V_176 ,
V_177 |
V_181 ) ;
}
static int F_115 ( struct V_1 * V_2 ,
T_1 V_182 , T_1 V_183 )
{
T_3 V_12 ;
int V_13 ;
V_13 = F_6 ( V_2 , 4 ) ;
if ( V_13 )
return V_13 ;
V_12 = V_184 ;
if ( V_182 & V_185 )
V_12 |= V_186 | V_187 ;
F_7 ( V_2 , V_12 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , V_24 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static int
F_116 ( struct V_1 * V_2 ,
T_1 V_126 , T_1 V_130 )
{
int V_13 ;
V_13 = F_6 ( V_2 , 2 ) ;
if ( V_13 )
return V_13 ;
F_7 ( V_2 , V_128 | V_129 ) ;
F_7 ( V_2 , V_126 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
static bool
F_117 ( struct V_1 * V_2 )
{
return F_77 ( V_2 ,
V_113 ,
V_188 ) ;
}
static void
F_118 ( struct V_1 * V_2 )
{
return F_80 ( V_2 ,
V_113 ,
V_188 ) ;
}
static bool
F_119 ( struct V_1 * V_2 )
{
return F_77 ( V_2 ,
V_189 ,
V_190 ) ;
}
static void
F_120 ( struct V_1 * V_2 )
{
return F_80 ( V_2 ,
V_189 ,
V_190 ) ;
}
static bool
F_121 ( struct V_1 * V_2 )
{
return F_77 ( V_2 ,
V_191 ,
V_192 ) ;
}
static void
F_122 ( struct V_1 * V_2 )
{
F_80 ( V_2 ,
V_191 ,
V_192 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
T_1 V_182 , T_1 V_183 )
{
T_3 V_12 ;
int V_13 ;
V_13 = F_6 ( V_2 , 4 ) ;
if ( V_13 )
return V_13 ;
V_12 = V_184 ;
if ( V_182 & V_16 )
V_12 |= V_186 ;
F_7 ( V_2 , V_12 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , 0 ) ;
F_7 ( V_2 , V_24 ) ;
F_8 ( V_2 ) ;
return 0 ;
}
int F_124 ( struct V_10 * V_11 )
{
T_2 * V_43 = V_11 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_97 ] ;
* V_2 = V_193 ;
if ( F_3 ( V_11 ) -> V_17 >= 6 ) {
V_2 -> V_194 = F_48 ;
V_2 -> V_183 = F_11 ;
V_2 -> V_195 = F_117 ;
V_2 -> V_196 = F_118 ;
V_2 -> V_197 = F_58 ;
} else if ( F_5 ( V_11 ) ) {
V_2 -> V_194 = F_55 ;
V_2 -> V_197 = F_61 ;
}
if ( ! F_95 ( V_11 ) ) {
V_2 -> V_120 . V_134 = V_43 -> V_198 -> V_199 ;
memset ( V_2 -> V_120 . V_134 , 0 , V_52 ) ;
}
return F_91 ( V_11 , V_2 ) ;
}
int F_125 ( struct V_10 * V_11 , T_4 V_200 , T_1 V_7 )
{
T_2 * V_43 = V_11 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_97 ] ;
* V_2 = V_193 ;
if ( F_3 ( V_11 ) -> V_17 >= 6 ) {
V_2 -> V_194 = F_48 ;
V_2 -> V_195 = F_117 ;
V_2 -> V_196 = F_118 ;
} else if ( F_5 ( V_11 ) ) {
V_2 -> V_194 = F_55 ;
V_2 -> V_197 = F_61 ;
}
if ( ! F_95 ( V_11 ) )
V_2 -> V_120 . V_134 = V_43 -> V_198 -> V_199 ;
V_2 -> V_11 = V_11 ;
F_92 ( & V_2 -> V_135 ) ;
F_92 ( & V_2 -> V_136 ) ;
F_92 ( & V_2 -> V_137 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_148 = V_2 -> V_7 ;
if ( F_86 ( V_2 -> V_11 ) )
V_2 -> V_148 -= 128 ;
V_2 -> V_140 . V_126 = V_200 ;
V_2 -> V_140 . V_7 = V_7 ;
V_2 -> V_140 . type = 0 ;
V_2 -> V_140 . V_34 = 0 ;
V_2 -> V_140 . V_142 = 0 ;
F_96 ( & V_2 -> V_140 , V_11 ) ;
if ( V_2 -> V_140 . V_143 == NULL ) {
F_26 ( L_12
L_13 ) ;
return - V_59 ;
}
V_2 -> V_145 = ( void V_201 V_202 * ) V_2 -> V_140 . V_143 ;
return 0 ;
}
int F_126 ( struct V_10 * V_11 )
{
T_2 * V_43 = V_11 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_99 ] ;
if ( F_45 ( V_11 ) || F_42 ( V_11 ) )
* V_2 = V_203 ;
else
* V_2 = V_204 ;
return F_91 ( V_11 , V_2 ) ;
}
int F_127 ( struct V_10 * V_11 )
{
T_2 * V_43 = V_11 -> V_44 ;
struct V_1 * V_2 = & V_43 -> V_2 [ V_100 ] ;
* V_2 = V_205 ;
return F_91 ( V_11 , V_2 ) ;
}
