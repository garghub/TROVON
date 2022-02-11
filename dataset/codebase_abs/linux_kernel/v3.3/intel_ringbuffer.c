static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 = ( V_2 -> V_4 & V_5 ) - ( V_2 -> V_6 + 8 ) ;
if ( V_3 < 0 )
V_3 += V_2 -> V_7 ;
return V_3 ;
}
static T_1 F_2 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
T_1 V_12 ;
V_12 = V_10 -> V_13 ;
if ( ++ V_10 -> V_13 == 0 )
V_10 -> V_13 = 1 ;
return V_12 ;
}
static int
F_3 ( struct V_1 * V_2 ,
T_1 V_14 ,
T_1 V_15 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_16 ;
int V_17 ;
V_16 = V_18 | V_19 ;
if ( ( V_14 | V_15 ) &
V_20 )
V_16 &= ~ V_19 ;
if ( F_4 ( V_9 ) -> V_21 < 4 ) {
if ( V_14 & V_22 )
V_16 |= V_23 ;
}
if ( V_14 & V_24 )
V_16 |= V_25 ;
if ( V_14 & V_26 &&
( F_5 ( V_9 ) || F_6 ( V_9 ) ) )
V_16 |= V_27 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
T_1 V_32 = V_30 -> V_33 + 128 ;
int V_17 ;
V_17 = F_7 ( V_2 , 6 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 5 ) ) ;
F_8 ( V_2 , V_34 |
V_35 ) ;
F_8 ( V_2 , V_32 | V_36 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
V_17 = F_7 ( V_2 , 6 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 5 ) ) ;
F_8 ( V_2 , V_37 ) ;
F_8 ( V_2 , V_32 | V_36 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 ,
T_1 V_14 , T_1 V_15 )
{
T_1 V_38 = 0 ;
struct V_29 * V_30 = V_2 -> V_31 ;
T_1 V_32 = V_30 -> V_33 + 128 ;
int V_17 ;
F_10 ( V_2 ) ;
V_38 |= V_39 ;
V_38 |= V_40 ;
V_38 |= V_41 ;
V_38 |= V_42 ;
V_38 |= V_43 ;
V_38 |= V_44 ;
V_38 |= V_45 ;
V_17 = F_7 ( V_2 , 6 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 5 ) ) ;
F_8 ( V_2 , V_38 ) ;
F_8 ( V_2 , V_32 | V_36 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_46 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
F_14 ( V_2 , V_46 ) ;
}
T_1 F_15 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
T_1 V_47 = F_4 ( V_2 -> V_9 ) -> V_21 >= 4 ?
F_16 ( V_2 -> V_48 ) : V_49 ;
return F_17 ( V_47 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
struct V_50 * V_51 = V_2 -> V_51 ;
T_1 V_4 ;
F_19 ( V_2 , 0 ) ;
F_20 ( V_2 , 0 ) ;
V_2 -> V_52 ( V_2 , 0 ) ;
F_21 ( V_2 , V_51 -> V_33 ) ;
V_4 = F_22 ( V_2 ) & V_5 ;
if ( V_4 != 0 ) {
F_23 ( L_1
L_2 ,
V_2 -> V_53 ,
F_24 ( V_2 ) ,
F_22 ( V_2 ) ,
F_25 ( V_2 ) ,
F_26 ( V_2 ) ) ;
F_20 ( V_2 , 0 ) ;
if ( F_22 ( V_2 ) & V_5 ) {
F_27 ( L_3
L_2 ,
V_2 -> V_53 ,
F_24 ( V_2 ) ,
F_22 ( V_2 ) ,
F_25 ( V_2 ) ,
F_26 ( V_2 ) ) ;
}
}
F_19 ( V_2 ,
( ( V_2 -> V_7 - V_54 ) & V_55 )
| V_56 ) ;
if ( ( F_24 ( V_2 ) & V_56 ) == 0 ||
F_26 ( V_2 ) != V_51 -> V_33 ||
( F_22 ( V_2 ) & V_5 ) != 0 ) {
F_27 ( L_4
L_2 ,
V_2 -> V_53 ,
F_24 ( V_2 ) ,
F_22 ( V_2 ) ,
F_25 ( V_2 ) ,
F_26 ( V_2 ) ) ;
return - V_57 ;
}
if ( ! F_28 ( V_2 -> V_9 , V_58 ) )
F_29 ( V_2 -> V_9 ) ;
else {
V_2 -> V_4 = F_22 ( V_2 ) ;
V_2 -> V_6 = F_25 ( V_2 ) & V_59 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
}
return 0 ;
}
static int
F_30 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
struct V_50 * V_51 ;
int V_17 ;
if ( V_2 -> V_31 )
return 0 ;
V_30 = F_31 ( sizeof( * V_30 ) , V_60 ) ;
if ( ! V_30 )
return - V_61 ;
V_51 = F_32 ( V_2 -> V_9 , 4096 ) ;
if ( V_51 == NULL ) {
F_27 ( L_5 ) ;
V_17 = - V_61 ;
goto V_62;
}
F_33 ( V_51 , V_63 ) ;
V_17 = F_34 ( V_51 , 4096 , true ) ;
if ( V_17 )
goto V_64;
V_30 -> V_33 = V_51 -> V_33 ;
V_30 -> V_65 = F_35 ( V_51 -> V_66 [ 0 ] ) ;
if ( V_30 -> V_65 == NULL )
goto V_67;
V_30 -> V_51 = V_51 ;
V_2 -> V_31 = V_30 ;
return 0 ;
V_67:
F_36 ( V_51 ) ;
V_64:
F_37 ( & V_51 -> V_68 ) ;
V_62:
F_38 ( V_30 ) ;
return V_17 ;
}
static void
F_39 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
struct V_50 * V_51 ;
if ( ! V_2 -> V_31 )
return;
V_51 = V_30 -> V_51 ;
F_40 ( V_51 -> V_66 [ 0 ] ) ;
F_36 ( V_51 ) ;
F_37 ( & V_51 -> V_68 ) ;
F_38 ( V_30 ) ;
V_2 -> V_31 = NULL ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_69 * V_10 = V_9 -> V_11 ;
int V_17 = F_18 ( V_2 ) ;
if ( F_4 ( V_9 ) -> V_21 > 3 ) {
int V_70 = V_71 << 16 | V_71 ;
if ( F_42 ( V_9 ) || F_43 ( V_9 ) )
V_70 |= V_72 << 16 | V_72 ;
F_44 ( V_73 , V_70 ) ;
if ( F_43 ( V_9 ) )
F_44 ( V_74 ,
F_45 ( V_75 ) |
F_46 ( V_76 ) ) ;
}
if ( F_4 ( V_9 ) -> V_21 >= 5 ) {
V_17 = F_30 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
F_44 ( V_77 ,
V_78 << 16 | V_78 ) ;
}
return V_17 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 )
return;
F_39 ( V_2 ) ;
}
static void
F_48 ( struct V_1 * V_2 ,
T_1 V_12 ,
T_1 V_79 )
{
F_8 ( V_2 , V_80 |
V_81 |
V_82 |
V_83 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_79 ) ;
}
static int
F_49 ( struct V_1 * V_2 ,
T_1 * V_12 )
{
T_1 V_84 ;
T_1 V_85 ;
int V_17 ;
V_17 = F_7 ( V_2 , 10 ) ;
if ( V_17 )
return V_17 ;
V_84 = V_2 -> V_86 [ 0 ] ;
V_85 = V_2 -> V_86 [ 1 ] ;
* V_12 = F_2 ( V_2 -> V_9 ) ;
F_48 ( V_2 , * V_12 , V_84 ) ;
F_48 ( V_2 , * V_12 , V_85 ) ;
F_8 ( V_2 , V_87 ) ;
F_8 ( V_2 , V_88 << V_89 ) ;
F_8 ( V_2 , * V_12 ) ;
F_8 ( V_2 , V_90 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_50 ( struct V_1 * V_91 ,
struct V_1 * V_92 ,
int V_2 ,
T_1 V_12 )
{
int V_17 ;
T_1 V_93 = V_80 |
V_94 |
V_82 ;
V_17 = F_7 ( V_91 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_91 , V_93 | V_92 -> V_95 [ V_2 ] ) ;
F_8 ( V_91 , V_12 ) ;
F_8 ( V_91 , 0 ) ;
F_8 ( V_91 , V_28 ) ;
F_9 ( V_91 ) ;
return 0 ;
}
int
F_51 ( struct V_1 * V_91 ,
struct V_1 * V_92 ,
T_1 V_12 )
{
F_52 ( V_92 -> V_95 [ V_96 ] == V_97 ) ;
return F_50 ( V_91 ,
V_92 ,
V_96 ,
V_12 ) ;
}
int
F_53 ( struct V_1 * V_91 ,
struct V_1 * V_92 ,
T_1 V_12 )
{
F_52 ( V_92 -> V_95 [ V_98 ] == V_97 ) ;
return F_50 ( V_91 ,
V_92 ,
V_98 ,
V_12 ) ;
}
int
F_54 ( struct V_1 * V_91 ,
struct V_1 * V_92 ,
T_1 V_12 )
{
F_52 ( V_92 -> V_95 [ V_99 ] == V_97 ) ;
return F_50 ( V_91 ,
V_92 ,
V_99 ,
V_12 ) ;
}
static int
F_55 ( struct V_1 * V_2 ,
T_1 * V_100 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
struct V_29 * V_30 = V_2 -> V_31 ;
T_1 V_32 = V_30 -> V_33 + 128 ;
int V_17 ;
V_17 = F_7 ( V_2 , 32 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , F_11 ( 4 ) | V_37 |
V_101 |
V_41 ) ;
F_8 ( V_2 , V_30 -> V_33 | V_36 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
V_32 += 128 ;
F_56 ( V_2 , V_32 ) ;
F_8 ( V_2 , F_11 ( 4 ) | V_37 |
V_101 |
V_41 |
V_102 ) ;
F_8 ( V_2 , V_30 -> V_33 | V_36 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , 0 ) ;
F_9 ( V_2 ) ;
* V_100 = V_12 ;
return 0 ;
}
static int
F_57 ( struct V_1 * V_2 ,
T_1 * V_100 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_1 V_12 = F_2 ( V_9 ) ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_87 ) ;
F_8 ( V_2 , V_88 << V_89 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_90 ) ;
F_9 ( V_2 ) ;
* V_100 = V_12 ;
return 0 ;
}
static T_1
F_58 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
if ( F_43 ( V_9 ) )
F_15 ( V_2 ) ;
return F_59 ( V_2 , V_88 ) ;
}
static T_1
F_60 ( struct V_1 * V_2 )
{
return F_59 ( V_2 , V_88 ) ;
}
static T_1
F_61 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_31 ;
return V_30 -> V_65 [ 0 ] ;
}
static void
F_62 ( T_2 * V_10 , T_1 V_103 )
{
V_10 -> V_104 &= ~ V_103 ;
F_44 ( V_105 , V_10 -> V_104 ) ;
F_63 ( V_105 ) ;
}
static void
F_64 ( T_2 * V_10 , T_1 V_103 )
{
V_10 -> V_104 |= V_103 ;
F_44 ( V_105 , V_10 -> V_104 ) ;
F_63 ( V_105 ) ;
}
static void
F_65 ( T_2 * V_10 , T_1 V_103 )
{
V_10 -> V_106 &= ~ V_103 ;
F_44 ( V_107 , V_10 -> V_106 ) ;
F_63 ( V_107 ) ;
}
static void
F_66 ( T_2 * V_10 , T_1 V_103 )
{
V_10 -> V_106 |= V_103 ;
F_44 ( V_107 , V_10 -> V_106 ) ;
F_63 ( V_107 ) ;
}
static bool
F_67 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_108 )
return false ;
F_68 ( & V_2 -> V_109 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
if ( F_69 ( V_9 ) )
F_62 ( V_10 ,
V_111 | V_112 ) ;
else
F_65 ( V_10 , V_113 ) ;
}
F_70 ( & V_2 -> V_109 ) ;
return true ;
}
static void
F_71 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_68 ( & V_2 -> V_109 ) ;
if ( -- V_2 -> V_110 == 0 ) {
if ( F_69 ( V_9 ) )
F_64 ( V_10 ,
V_112 |
V_111 ) ;
else
F_66 ( V_10 , V_113 ) ;
}
F_70 ( & V_2 -> V_109 ) ;
}
void F_72 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
T_1 V_114 = 0 ;
if ( F_43 ( V_9 ) ) {
switch ( V_2 -> V_115 ) {
case V_116 :
V_114 = V_117 ;
break;
case V_118 :
V_114 = V_119 ;
break;
case V_120 :
V_114 = V_121 ;
break;
}
} else if ( F_42 ( V_2 -> V_9 ) ) {
V_114 = F_73 ( V_2 -> V_48 ) ;
} else {
V_114 = F_74 ( V_2 -> V_48 ) ;
}
F_44 ( V_114 , ( T_1 ) V_2 -> V_122 . V_123 ) ;
F_63 ( V_114 ) ;
}
static int
F_75 ( struct V_1 * V_2 ,
T_1 V_14 ,
T_1 V_15 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_18 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_76 ( struct V_1 * V_2 ,
T_1 * V_100 )
{
T_1 V_12 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_12 = F_2 ( V_2 -> V_9 ) ;
F_8 ( V_2 , V_87 ) ;
F_8 ( V_2 , V_88 << V_89 ) ;
F_8 ( V_2 , V_12 ) ;
F_8 ( V_2 , V_90 ) ;
F_9 ( V_2 ) ;
* V_100 = V_12 ;
return 0 ;
}
static bool
F_77 ( struct V_1 * V_2 , T_1 V_124 , T_1 V_125 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_108 )
return false ;
if ( F_43 ( V_9 ) )
F_78 ( V_10 ) ;
F_68 ( & V_2 -> V_109 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
V_2 -> V_106 &= ~ V_125 ;
F_79 ( V_2 , V_2 -> V_106 ) ;
F_62 ( V_10 , V_124 ) ;
}
F_70 ( & V_2 -> V_109 ) ;
return true ;
}
static void
F_80 ( struct V_1 * V_2 , T_1 V_124 , T_1 V_125 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_68 ( & V_2 -> V_109 ) ;
if ( -- V_2 -> V_110 == 0 ) {
V_2 -> V_106 |= V_125 ;
F_79 ( V_2 , V_2 -> V_106 ) ;
F_64 ( V_10 , V_124 ) ;
}
F_70 ( & V_2 -> V_109 ) ;
if ( F_43 ( V_9 ) )
F_81 ( V_10 ) ;
}
static bool
F_82 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
if ( ! V_9 -> V_108 )
return false ;
F_68 ( & V_2 -> V_109 ) ;
if ( V_2 -> V_110 ++ == 0 ) {
if ( F_5 ( V_9 ) )
F_65 ( V_10 , V_126 ) ;
else
F_62 ( V_10 , V_127 ) ;
}
F_70 ( & V_2 -> V_109 ) ;
return true ;
}
static void
F_83 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
F_68 ( & V_2 -> V_109 ) ;
if ( -- V_2 -> V_110 == 0 ) {
if ( F_5 ( V_9 ) )
F_66 ( V_10 , V_126 ) ;
else
F_64 ( V_10 , V_127 ) ;
}
F_70 ( & V_2 -> V_109 ) ;
}
static int
F_84 ( struct V_1 * V_2 , T_1 V_128 , T_1 V_129 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 ,
V_130 | ( 2 << 6 ) |
V_131 ) ;
F_8 ( V_2 , V_128 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_85 ( struct V_1 * V_2 ,
T_1 V_128 , T_1 V_132 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_17 ;
if ( F_86 ( V_9 ) || F_87 ( V_9 ) ) {
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_133 ) ;
F_8 ( V_2 , V_128 | V_134 ) ;
F_8 ( V_2 , V_128 + V_132 - 8 ) ;
F_8 ( V_2 , 0 ) ;
} else {
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
if ( F_4 ( V_9 ) -> V_21 >= 4 ) {
F_8 ( V_2 ,
V_130 | ( 2 << 6 ) |
V_131 ) ;
F_8 ( V_2 , V_128 ) ;
} else {
F_8 ( V_2 ,
V_130 | ( 2 << 6 ) ) ;
F_8 ( V_2 , V_128 | V_134 ) ;
}
}
F_9 ( V_2 ) ;
return 0 ;
}
static void F_88 ( struct V_1 * V_2 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
struct V_50 * V_51 ;
V_51 = V_2 -> V_122 . V_51 ;
if ( V_51 == NULL )
return;
F_40 ( V_51 -> V_66 [ 0 ] ) ;
F_36 ( V_51 ) ;
F_37 ( & V_51 -> V_68 ) ;
V_2 -> V_122 . V_51 = NULL ;
memset ( & V_10 -> V_135 , 0 , sizeof( V_10 -> V_135 ) ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
T_2 * V_10 = V_9 -> V_11 ;
struct V_50 * V_51 ;
int V_17 ;
V_51 = F_32 ( V_9 , 4096 ) ;
if ( V_51 == NULL ) {
F_27 ( L_6 ) ;
V_17 = - V_61 ;
goto V_62;
}
F_33 ( V_51 , V_63 ) ;
V_17 = F_34 ( V_51 , 4096 , true ) ;
if ( V_17 != 0 ) {
goto V_64;
}
V_2 -> V_122 . V_123 = V_51 -> V_33 ;
V_2 -> V_122 . V_136 = F_35 ( V_51 -> V_66 [ 0 ] ) ;
if ( V_2 -> V_122 . V_136 == NULL ) {
memset ( & V_10 -> V_135 , 0 , sizeof( V_10 -> V_135 ) ) ;
goto V_67;
}
V_2 -> V_122 . V_51 = V_51 ;
memset ( V_2 -> V_122 . V_136 , 0 , V_54 ) ;
F_72 ( V_2 ) ;
F_90 ( L_7 ,
V_2 -> V_53 , V_2 -> V_122 . V_123 ) ;
return 0 ;
V_67:
F_36 ( V_51 ) ;
V_64:
F_37 ( & V_51 -> V_68 ) ;
V_62:
return V_17 ;
}
int F_91 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_50 * V_51 ;
int V_17 ;
V_2 -> V_9 = V_9 ;
F_92 ( & V_2 -> V_137 ) ;
F_92 ( & V_2 -> V_138 ) ;
F_92 ( & V_2 -> V_139 ) ;
F_93 ( & V_2 -> V_140 ) ;
F_94 ( & V_2 -> V_109 ) ;
V_2 -> V_106 = ~ 0 ;
if ( F_95 ( V_9 ) ) {
V_17 = F_89 ( V_2 ) ;
if ( V_17 )
return V_17 ;
}
V_51 = F_32 ( V_9 , V_2 -> V_7 ) ;
if ( V_51 == NULL ) {
F_27 ( L_8 ) ;
V_17 = - V_61 ;
goto V_141;
}
V_2 -> V_51 = V_51 ;
V_17 = F_34 ( V_51 , V_54 , true ) ;
if ( V_17 )
goto V_64;
V_2 -> V_142 . V_7 = V_2 -> V_7 ;
V_2 -> V_142 . V_128 = V_9 -> V_143 -> V_68 + V_51 -> V_33 ;
V_2 -> V_142 . type = 0 ;
V_2 -> V_142 . V_38 = 0 ;
V_2 -> V_142 . V_144 = 0 ;
F_96 ( & V_2 -> V_142 , V_9 ) ;
if ( V_2 -> V_142 . V_145 == NULL ) {
F_27 ( L_9 ) ;
V_17 = - V_146 ;
goto V_67;
}
V_2 -> V_147 = V_2 -> V_142 . V_145 ;
V_17 = V_2 -> V_148 ( V_2 ) ;
if ( V_17 )
goto V_149;
V_2 -> V_150 = V_2 -> V_7 ;
if ( F_86 ( V_2 -> V_9 ) )
V_2 -> V_150 -= 128 ;
return 0 ;
V_149:
F_97 ( & V_2 -> V_142 , V_9 ) ;
V_67:
F_36 ( V_51 ) ;
V_64:
F_37 ( & V_51 -> V_68 ) ;
V_2 -> V_51 = NULL ;
V_141:
F_88 ( V_2 ) ;
return V_17 ;
}
void F_98 ( struct V_1 * V_2 )
{
struct V_69 * V_10 ;
int V_17 ;
if ( V_2 -> V_51 == NULL )
return;
V_10 = V_2 -> V_9 -> V_11 ;
V_17 = F_99 ( V_2 ) ;
if ( V_17 )
F_27 ( L_10 ,
V_2 -> V_53 , V_17 ) ;
F_19 ( V_2 , 0 ) ;
F_97 ( & V_2 -> V_142 , V_2 -> V_9 ) ;
F_36 ( V_2 -> V_51 ) ;
F_37 ( & V_2 -> V_51 -> V_68 ) ;
V_2 -> V_51 = NULL ;
if ( V_2 -> V_151 )
V_2 -> V_151 ( V_2 ) ;
F_88 ( V_2 ) ;
}
static int F_100 ( struct V_1 * V_2 )
{
unsigned int * V_152 ;
int V_153 = V_2 -> V_7 - V_2 -> V_6 ;
if ( V_2 -> V_3 < V_153 ) {
int V_17 = F_101 ( V_2 , V_153 ) ;
if ( V_17 )
return V_17 ;
}
V_152 = ( unsigned int * ) ( V_2 -> V_147 + V_2 -> V_6 ) ;
V_153 /= 8 ;
while ( V_153 -- ) {
* V_152 ++ = V_28 ;
* V_152 ++ = V_28 ;
}
V_2 -> V_6 = 0 ;
V_2 -> V_3 = F_1 ( V_2 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , int V_154 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_69 * V_10 = V_9 -> V_11 ;
unsigned long V_155 ;
F_102 ( V_2 ) ;
if ( F_28 ( V_9 , V_156 ) )
V_155 = V_157 + 60 * V_158 ;
else
V_155 = V_157 + 3 * V_158 ;
do {
V_2 -> V_4 = F_22 ( V_2 ) ;
V_2 -> V_3 = F_1 ( V_2 ) ;
if ( V_2 -> V_3 >= V_154 ) {
F_103 ( V_2 ) ;
return 0 ;
}
if ( V_9 -> V_159 -> V_160 ) {
struct V_161 * V_162 = V_9 -> V_159 -> V_160 -> V_163 ;
if ( V_162 -> V_164 )
V_162 -> V_164 -> V_165 |= V_166 ;
}
F_104 ( 1 ) ;
if ( F_105 ( & V_10 -> V_167 . V_168 ) )
return - V_169 ;
} while ( ! F_106 ( V_157 , V_155 ) );
F_103 ( V_2 ) ;
return - V_170 ;
}
int F_7 ( struct V_1 * V_2 ,
int V_171 )
{
struct V_69 * V_10 = V_2 -> V_9 -> V_11 ;
int V_154 = 4 * V_171 ;
int V_17 ;
if ( F_107 ( F_105 ( & V_10 -> V_167 . V_168 ) ) )
return - V_57 ;
if ( F_107 ( V_2 -> V_6 + V_154 > V_2 -> V_150 ) ) {
V_17 = F_100 ( V_2 ) ;
if ( F_107 ( V_17 ) )
return V_17 ;
}
if ( F_107 ( V_2 -> V_3 < V_154 ) ) {
V_17 = F_101 ( V_2 , V_154 ) ;
if ( F_107 ( V_17 ) )
return V_17 ;
}
V_2 -> V_3 -= V_154 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
V_2 -> V_52 ( V_2 , V_2 -> V_6 ) ;
}
static void F_108 ( struct V_1 * V_2 ,
T_1 V_46 )
{
T_2 * V_10 = V_2 -> V_9 -> V_11 ;
F_44 ( V_172 ,
V_173 |
V_174 ) ;
F_44 ( V_175 , 0x0 ) ;
if ( F_109 ( ( F_17 ( V_172 ) &
V_176 ) == 0 ,
50 ) )
F_27 ( L_11 ) ;
F_14 ( V_2 , V_46 ) ;
F_44 ( V_172 ,
V_173 |
V_177 ) ;
}
static int F_110 ( struct V_1 * V_2 ,
T_1 V_178 , T_1 V_179 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_7 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_180 ;
if ( V_178 & V_181 )
V_16 |= V_182 | V_183 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int
F_111 ( struct V_1 * V_2 ,
T_1 V_128 , T_1 V_132 )
{
int V_17 ;
V_17 = F_7 ( V_2 , 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_130 | V_131 ) ;
F_8 ( V_2 , V_128 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static bool
F_112 ( struct V_1 * V_2 )
{
return F_77 ( V_2 ,
V_112 ,
V_184 ) ;
}
static void
F_113 ( struct V_1 * V_2 )
{
return F_80 ( V_2 ,
V_112 ,
V_184 ) ;
}
static bool
F_114 ( struct V_1 * V_2 )
{
return F_77 ( V_2 ,
V_185 ,
V_186 ) ;
}
static void
F_115 ( struct V_1 * V_2 )
{
return F_80 ( V_2 ,
V_185 ,
V_186 ) ;
}
static bool
F_116 ( struct V_1 * V_2 )
{
return F_77 ( V_2 ,
V_187 ,
V_188 ) ;
}
static void
F_117 ( struct V_1 * V_2 )
{
F_80 ( V_2 ,
V_187 ,
V_188 ) ;
}
static inline struct V_50 *
F_118 ( struct V_1 * V_2 )
{
return V_2 -> V_31 ;
}
static int F_119 ( struct V_1 * V_2 )
{
if ( F_120 ( V_2 -> V_9 ) ) {
struct V_50 * V_51 ;
T_1 * V_189 ;
int V_17 ;
V_51 = F_32 ( V_2 -> V_9 , 4096 ) ;
if ( V_51 == NULL )
return - V_61 ;
V_17 = F_34 ( V_51 , 4096 , true ) ;
if ( V_17 ) {
F_37 ( & V_51 -> V_68 ) ;
return V_17 ;
}
V_189 = F_35 ( V_51 -> V_66 [ 0 ] ) ;
* V_189 ++ = V_190 ;
* V_189 ++ = V_28 ;
F_40 ( V_51 -> V_66 [ 0 ] ) ;
V_17 = F_121 ( V_51 , false ) ;
if ( V_17 ) {
F_36 ( V_51 ) ;
F_37 ( & V_51 -> V_68 ) ;
return V_17 ;
}
V_2 -> V_31 = V_51 ;
}
return F_18 ( V_2 ) ;
}
static int F_122 ( struct V_1 * V_2 ,
int V_171 )
{
if ( V_2 -> V_31 ) {
int V_17 = F_7 ( V_2 , V_171 + 2 ) ;
if ( V_17 )
return V_17 ;
F_8 ( V_2 , V_130 ) ;
F_8 ( V_2 , F_118 ( V_2 ) -> V_33 ) ;
return 0 ;
} else
return F_7 ( V_2 , 4 ) ;
}
static int F_123 ( struct V_1 * V_2 ,
T_1 V_178 , T_1 V_179 )
{
T_3 V_16 ;
int V_17 ;
V_17 = F_122 ( V_2 , 4 ) ;
if ( V_17 )
return V_17 ;
V_16 = V_180 ;
if ( V_178 & V_20 )
V_16 |= V_182 ;
F_8 ( V_2 , V_16 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , 0 ) ;
F_8 ( V_2 , V_28 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static void F_124 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_31 )
return;
F_36 ( V_2 -> V_31 ) ;
F_37 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
}
int F_125 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_96 ] ;
* V_2 = V_191 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_192 = F_49 ;
V_2 -> V_179 = F_12 ;
V_2 -> V_193 = F_112 ;
V_2 -> V_194 = F_113 ;
V_2 -> V_195 = F_58 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_192 = F_55 ;
V_2 -> V_195 = F_61 ;
}
if ( ! F_95 ( V_9 ) ) {
V_2 -> V_122 . V_136 = V_10 -> V_196 -> V_197 ;
memset ( V_2 -> V_122 . V_136 , 0 , V_54 ) ;
}
return F_91 ( V_9 , V_2 ) ;
}
int F_126 ( struct V_8 * V_9 , T_4 V_198 , T_1 V_7 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_96 ] ;
* V_2 = V_191 ;
if ( F_4 ( V_9 ) -> V_21 >= 6 ) {
V_2 -> V_192 = F_49 ;
V_2 -> V_193 = F_112 ;
V_2 -> V_194 = F_113 ;
} else if ( F_6 ( V_9 ) ) {
V_2 -> V_192 = F_55 ;
V_2 -> V_195 = F_61 ;
}
if ( ! F_95 ( V_9 ) )
V_2 -> V_122 . V_136 = V_10 -> V_196 -> V_197 ;
V_2 -> V_9 = V_9 ;
F_92 ( & V_2 -> V_137 ) ;
F_92 ( & V_2 -> V_138 ) ;
F_92 ( & V_2 -> V_139 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_150 = V_2 -> V_7 ;
if ( F_86 ( V_2 -> V_9 ) )
V_2 -> V_150 -= 128 ;
V_2 -> V_142 . V_128 = V_198 ;
V_2 -> V_142 . V_7 = V_7 ;
V_2 -> V_142 . type = 0 ;
V_2 -> V_142 . V_38 = 0 ;
V_2 -> V_142 . V_144 = 0 ;
F_96 ( & V_2 -> V_142 , V_9 ) ;
if ( V_2 -> V_142 . V_145 == NULL ) {
F_27 ( L_12
L_13 ) ;
return - V_61 ;
}
V_2 -> V_147 = ( void V_199 V_200 * ) V_2 -> V_142 . V_145 ;
return 0 ;
}
int F_127 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_98 ] ;
if ( F_42 ( V_9 ) || F_43 ( V_9 ) )
* V_2 = V_201 ;
else
* V_2 = V_202 ;
return F_91 ( V_9 , V_2 ) ;
}
int F_128 ( struct V_8 * V_9 )
{
T_2 * V_10 = V_9 -> V_11 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_99 ] ;
* V_2 = V_203 ;
return F_91 ( V_9 , V_2 ) ;
}
