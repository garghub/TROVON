static bool F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_4 >= V_5 ;
}
static T_1 F_3 ( const struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return F_4 ( & V_3 -> V_6 ) ;
}
static T_1 F_5 ( const struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_7 ? V_3 -> V_8 : F_3 ( V_2 ) ;
}
static T_2 F_6 ( struct V_1 * V_2 , T_2 V_9 , int V_10 )
{
V_9 *= F_7 ( V_2 , F_8 ( V_2 ) -> V_11 ) ;
V_9 *= V_10 ;
V_9 >>= V_12 ;
V_9 *= V_13 ;
return V_9 >> V_14 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_1 V_6 , int V_10 )
{
T_2 V_9 = V_6 ;
V_9 = F_6 ( V_2 , V_9 , V_10 ) ;
V_9 = F_10 ( T_2 , V_9 , V_2 -> V_15 ) ;
return V_9 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_6 ;
T_1 V_18 ;
if ( V_17 -> V_19 ) {
V_18 = F_12 ( V_17 -> V_19 >> 3 , 1U ) ;
V_3 -> V_20 = 1 ;
} else {
V_18 = V_21 ;
}
V_6 = ( T_2 ) V_17 -> V_22 * V_23 ;
F_13 ( V_6 , V_18 ) ;
V_2 -> V_24 = F_9 ( V_2 , V_6 , V_25 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_6 , int V_10 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_9 = F_9 ( V_2 , V_6 , V_10 ) ;
if ( F_15 ( ! V_3 -> V_20 && V_17 -> V_19 ) )
F_11 ( V_2 ) ;
if ( F_1 ( V_2 ) || V_9 > V_2 -> V_24 )
V_2 -> V_24 = V_9 ;
}
static T_1 F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_26 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_27 ;
V_27 = V_2 -> V_24 < ( V_28 >> 3 ) ? 1 : 2 ;
V_3 -> V_26 = F_18 ( F_19 ( V_2 , V_17 -> V_11 , V_27 ) ,
0x7FU ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_29 < V_30 && V_3 -> V_31 != V_32 )
V_3 -> V_33 = V_17 -> V_22 ;
else
V_3 -> V_33 = F_12 ( V_3 -> V_33 , V_17 -> V_22 ) ;
}
static void F_21 ( struct V_1 * V_2 , enum V_34 V_35 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_35 == V_36 && V_17 -> V_37 ) {
V_3 -> V_38 = 1 ;
if ( V_3 -> V_31 == V_39 )
F_14 ( V_2 , F_5 ( V_2 ) , V_40 ) ;
}
}
static T_1 F_22 ( struct V_1 * V_2 , T_1 V_6 , int V_10 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_41 ;
T_2 V_42 ;
if ( F_15 ( V_3 -> V_43 == ~ 0U ) )
return V_44 ;
V_42 = ( T_2 ) V_6 * V_3 -> V_43 ;
V_41 = ( ( ( V_42 * V_10 ) >> V_12 ) + V_23 - 1 ) / V_23 ;
V_41 += 3 * V_3 -> V_26 ;
V_41 = ( V_41 + 1 ) & ~ 1U ;
return V_41 ;
}
static bool F_23 (
struct V_1 * V_2 , const struct V_45 * V_46 , T_1 V_47 , T_1 * V_48 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_3 V_49 = V_3 -> V_29 , V_50 = F_24 ( V_2 ) -> V_51 ;
T_1 V_41 = V_17 -> V_22 ;
if ( V_46 -> V_52 > 0 )
V_41 = F_25 ( V_53 , V_41 - V_46 -> V_52 , 1 ) ;
if ( V_50 == V_30 && V_49 != V_30 ) {
V_3 -> V_54 = 1 ;
V_3 -> V_55 = V_17 -> V_56 ;
V_41 = F_26 ( V_17 ) + V_47 ;
} else if ( V_49 >= V_30 && V_50 < V_30 ) {
V_3 -> V_57 = 1 ;
V_3 -> V_54 = 0 ;
}
V_3 -> V_29 = V_50 ;
if ( V_3 -> V_57 ) {
V_41 = F_12 ( V_41 , V_3 -> V_33 ) ;
V_3 -> V_57 = 0 ;
}
if ( V_3 -> V_54 ) {
* V_48 = F_12 ( V_41 , F_26 ( V_17 ) + V_47 ) ;
return true ;
}
* V_48 = V_41 ;
return false ;
}
static void F_27 ( struct V_1 * V_2 , const struct V_45 * V_46 ,
T_1 V_47 , T_1 V_6 , int V_10 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_41 = 0 , V_58 = 0 ;
if ( ! V_47 )
return;
if ( F_23 ( V_2 , V_46 , V_47 , & V_41 ) )
goto V_59;
V_58 = F_22 ( V_2 , V_6 , V_10 ) ;
if ( F_1 ( V_2 ) )
V_41 = F_18 ( V_41 + V_47 , V_58 ) ;
else if ( V_41 < V_58 || V_17 -> V_56 < V_44 )
V_41 = V_41 + V_47 ;
V_41 = F_12 ( V_41 , V_60 ) ;
V_59:
V_17 -> V_22 = F_18 ( V_41 , V_17 -> V_61 ) ;
if ( V_3 -> V_31 == V_32 )
V_17 -> V_22 = F_18 ( V_17 -> V_22 , V_60 ) ;
}
static bool F_28 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_62 =
F_29 ( V_17 -> V_63 , V_3 -> V_64 ) >
V_3 -> V_43 ;
T_1 V_65 , V_6 ;
if ( V_3 -> V_66 == V_40 )
return V_62 ;
V_65 = V_46 -> V_67 ;
V_6 = F_3 ( V_2 ) ;
if ( V_3 -> V_66 > V_40 )
return V_62 &&
( V_46 -> V_52 ||
V_65 >= F_22 ( V_2 , V_6 , V_3 -> V_66 ) ) ;
return V_62 ||
V_65 <= F_22 ( V_2 , V_6 , V_40 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_68 = ( V_3 -> V_68 + 1 ) & ( V_69 - 1 ) ;
V_3 -> V_64 = V_17 -> V_63 ;
V_3 -> V_66 = V_70 [ V_3 -> V_68 ] ;
}
static void F_31 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ( V_3 -> V_31 == V_39 ) && ! V_3 -> V_7 &&
F_28 ( V_2 , V_46 ) )
F_30 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_31 = V_71 ;
V_3 -> V_66 = V_25 ;
V_3 -> V_72 = V_25 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_31 = V_39 ;
V_3 -> V_66 = V_40 ;
V_3 -> V_72 = V_73 ;
V_3 -> V_68 = V_69 - 1 - F_34 ( V_74 ) ;
F_30 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
F_32 ( V_2 ) ;
else
F_33 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_75 = F_37 ( V_17 -> V_63 , V_21 ) ;
V_3 -> V_76 = V_17 -> V_56 ;
V_3 -> V_77 = V_17 -> V_78 ;
V_3 -> V_79 = 0 ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_8 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_80 = false ;
F_36 ( V_2 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_81 ;
if ( V_3 -> V_8 ) {
V_81 = abs ( V_6 - V_3 -> V_8 ) ;
if ( ( V_81 * V_40 <= V_82 * V_3 -> V_8 ) ||
( F_6 ( V_2 , V_81 , V_40 ) <=
V_83 ) ) {
V_3 -> V_8 = ( V_6 + V_3 -> V_8 ) >> 1 ;
V_3 -> V_7 = 1 ;
V_3 -> V_66 = V_40 ;
V_3 -> V_79 = 0 ;
return;
}
}
V_3 -> V_8 = V_6 ;
F_36 ( V_2 ) ;
}
static void F_40 ( struct V_1 * V_2 , const struct V_45 * V_46 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_78 , V_56 ;
T_2 V_6 ;
T_1 V_84 ;
if ( V_3 -> V_7 ) {
if ( V_3 -> V_31 == V_39 && V_3 -> V_85 &&
++ V_3 -> V_79 >= V_86 ) {
F_38 ( V_2 ) ;
F_33 ( V_2 ) ;
}
return;
}
if ( ! V_3 -> V_80 ) {
if ( ! V_46 -> V_52 )
return;
F_36 ( V_2 ) ;
V_3 -> V_80 = true ;
}
if ( V_46 -> V_87 ) {
F_38 ( V_2 ) ;
return;
}
if ( V_3 -> V_85 )
V_3 -> V_79 ++ ;
if ( V_3 -> V_79 < V_88 )
return;
if ( V_3 -> V_79 > 4 * V_88 ) {
F_38 ( V_2 ) ;
return;
}
if ( ! V_46 -> V_52 )
return;
V_78 = V_17 -> V_78 - V_3 -> V_77 ;
V_56 = V_17 -> V_56 - V_3 -> V_76 ;
if ( ! V_56 || ( V_78 << V_12 ) < V_89 * V_56 )
return;
V_84 = F_37 ( V_17 -> V_63 , V_21 ) - V_3 -> V_75 ;
if ( ( V_53 ) V_84 < 1 )
return;
if ( V_84 >= ~ 0U / V_21 ) {
F_38 ( V_2 ) ;
return;
}
V_84 *= V_21 ;
V_6 = ( T_2 ) V_56 * V_23 ;
F_13 ( V_6 , V_84 ) ;
F_39 ( V_2 , V_6 ) ;
}
static void F_41 ( struct V_1 * V_2 , const struct V_45 * V_46 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_3 -> V_85 = 0 ;
if ( V_46 -> V_56 < 0 || V_46 -> V_90 <= 0 )
return;
if ( ! F_42 ( V_46 -> V_91 , V_3 -> V_55 ) ) {
V_3 -> V_55 = V_17 -> V_56 ;
V_3 -> V_92 ++ ;
V_3 -> V_85 = 1 ;
V_3 -> V_54 = 0 ;
}
F_40 ( V_2 , V_46 ) ;
V_6 = ( T_2 ) V_46 -> V_56 * V_23 ;
F_13 ( V_6 , V_46 -> V_90 ) ;
if ( ! V_46 -> V_87 || V_6 >= F_3 ( V_2 ) ) {
F_43 ( & V_3 -> V_6 , V_93 , V_3 -> V_92 , V_6 ) ;
}
}
static void F_44 ( struct V_1 * V_2 ,
const struct V_45 * V_46 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_94 ;
if ( F_1 ( V_2 ) || ! V_3 -> V_85 || V_46 -> V_87 )
return;
V_94 = ( T_2 ) V_3 -> V_95 * V_96 >> V_12 ;
if ( F_3 ( V_2 ) >= V_94 ) {
V_3 -> V_95 = F_3 ( V_2 ) ;
V_3 -> V_4 = 0 ;
return;
}
++ V_3 -> V_4 ;
}
static void F_45 ( struct V_1 * V_2 , const struct V_45 * V_46 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_31 == V_71 && F_1 ( V_2 ) ) {
V_3 -> V_31 = V_97 ;
V_3 -> V_66 = V_98 ;
V_3 -> V_72 = V_25 ;
}
if ( V_3 -> V_31 == V_97 &&
F_26 ( F_8 ( V_2 ) ) <=
F_22 ( V_2 , F_3 ( V_2 ) , V_40 ) )
F_33 ( V_2 ) ;
}
static void F_46 ( struct V_1 * V_2 , const struct V_45 * V_46 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_99 ;
V_99 = F_47 ( V_100 ,
V_3 -> V_101 + V_102 * V_103 ) ;
if ( V_46 -> V_18 >= 0 &&
( V_46 -> V_18 <= V_3 -> V_43 || V_99 ) ) {
V_3 -> V_43 = V_46 -> V_18 ;
V_3 -> V_101 = V_100 ;
}
if ( V_104 > 0 && V_99 &&
! V_3 -> V_38 && V_3 -> V_31 != V_32 ) {
V_3 -> V_31 = V_32 ;
V_3 -> V_66 = V_40 ;
V_3 -> V_72 = V_40 ;
F_20 ( V_2 ) ;
V_3 -> V_105 = 0 ;
}
if ( V_3 -> V_31 == V_32 ) {
V_17 -> V_37 =
( V_17 -> V_56 + F_26 ( V_17 ) ) ? : 1 ;
if ( ! V_3 -> V_105 &&
F_26 ( V_17 ) <= V_60 ) {
V_3 -> V_105 = V_100 +
F_48 ( V_104 ) ;
V_3 -> V_106 = 0 ;
V_3 -> V_55 = V_17 -> V_56 ;
} else if ( V_3 -> V_105 ) {
if ( V_3 -> V_85 )
V_3 -> V_106 = 1 ;
if ( V_3 -> V_106 &&
F_47 ( V_100 , V_3 -> V_105 ) ) {
V_3 -> V_101 = V_100 ;
V_3 -> V_57 = 1 ;
F_35 ( V_2 ) ;
}
}
}
V_3 -> V_38 = 0 ;
}
static void F_49 ( struct V_1 * V_2 , const struct V_45 * V_46 )
{
F_41 ( V_2 , V_46 ) ;
F_31 ( V_2 , V_46 ) ;
F_44 ( V_2 , V_46 ) ;
F_45 ( V_2 , V_46 ) ;
F_46 ( V_2 , V_46 ) ;
}
static void F_50 ( struct V_1 * V_2 , const struct V_45 * V_46 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_6 ;
F_49 ( V_2 , V_46 ) ;
V_6 = F_5 ( V_2 ) ;
F_14 ( V_2 , V_6 , V_3 -> V_66 ) ;
F_17 ( V_2 ) ;
F_27 ( V_2 , V_46 , V_46 -> V_107 , V_6 , V_3 -> V_72 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_33 = 0 ;
V_3 -> V_26 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_55 = 0 ;
V_3 -> V_29 = V_108 ;
V_3 -> V_54 = 0 ;
V_3 -> V_105 = 0 ;
V_3 -> V_106 = 0 ;
V_3 -> V_43 = F_52 ( V_17 ) ;
V_3 -> V_101 = V_100 ;
F_53 ( & V_3 -> V_6 , V_3 -> V_92 , 0 ) ;
V_3 -> V_20 = 0 ;
F_11 ( V_2 ) ;
V_3 -> V_57 = 0 ;
V_3 -> V_85 = 0 ;
V_3 -> V_38 = 0 ;
V_3 -> V_95 = 0 ;
V_3 -> V_4 = 0 ;
V_3 -> V_64 = 0 ;
V_3 -> V_68 = 0 ;
F_38 ( V_2 ) ;
F_32 ( V_2 ) ;
F_54 ( & V_2 -> V_109 , V_110 , V_111 ) ;
}
static T_1 F_55 ( struct V_1 * V_2 )
{
return 3 ;
}
static T_1 F_56 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) -> V_22 ;
}
static T_1 F_57 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
return V_112 ;
}
static T_4 F_58 ( struct V_1 * V_2 , T_1 V_113 , int * V_114 ,
union V_115 * V_116 )
{
if ( V_113 & ( 1 << ( V_117 - 1 ) ) ||
V_113 & ( 1 << ( V_118 - 1 ) ) ) {
struct V_16 * V_17 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_6 = F_5 ( V_2 ) ;
V_6 = V_6 * V_17 -> V_11 * V_13 >> V_14 ;
memset ( & V_116 -> V_3 , 0 , sizeof( V_116 -> V_3 ) ) ;
V_116 -> V_3 . V_119 = ( T_1 ) V_6 ;
V_116 -> V_3 . V_120 = ( T_1 ) ( V_6 >> 32 ) ;
V_116 -> V_3 . V_121 = V_3 -> V_43 ;
V_116 -> V_3 . V_70 = V_3 -> V_66 ;
V_116 -> V_3 . V_73 = V_3 -> V_72 ;
* V_114 = V_117 ;
return sizeof( V_116 -> V_3 ) ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , T_3 V_122 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_122 == V_123 ) {
struct V_45 V_46 = { . V_52 = 1 } ;
V_3 -> V_29 = V_123 ;
V_3 -> V_95 = 0 ;
V_3 -> V_85 = 1 ;
F_40 ( V_2 , & V_46 ) ;
}
}
static int T_5 F_60 ( void )
{
F_61 ( sizeof( struct V_3 ) > V_124 ) ;
return F_62 ( & V_125 ) ;
}
static void T_6 F_63 ( void )
{
F_64 ( & V_125 ) ;
}
