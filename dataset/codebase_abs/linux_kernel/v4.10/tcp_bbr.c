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
static void F_9 ( struct V_1 * V_2 , T_1 V_6 , int V_10 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_9 = V_6 ;
V_9 = F_6 ( V_2 , V_9 , V_10 ) ;
V_9 = F_10 ( T_2 , V_9 , V_2 -> V_15 ) ;
if ( V_3 -> V_16 != V_17 || V_9 > V_2 -> V_18 )
V_2 -> V_18 = V_9 ;
}
static T_1 F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
return V_3 -> V_19 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_22 ;
V_22 = V_2 -> V_18 < ( V_23 >> 3 ) ? 1 : 2 ;
V_3 -> V_19 = F_13 ( F_14 ( V_2 , V_21 -> V_11 , V_22 ) ,
0x7FU ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_24 < V_25 && V_3 -> V_16 != V_26 )
V_3 -> V_27 = V_21 -> V_28 ;
else
V_3 -> V_27 = F_16 ( V_3 -> V_27 , V_21 -> V_28 ) ;
}
static void F_17 ( struct V_1 * V_2 , enum V_29 V_30 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_30 == V_31 && V_21 -> V_32 ) {
V_3 -> V_33 = 1 ;
if ( V_3 -> V_16 == V_34 )
F_9 ( V_2 , F_5 ( V_2 ) , V_35 ) ;
}
}
static T_1 F_18 ( struct V_1 * V_2 , T_1 V_6 , int V_10 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_36 ;
T_2 V_37 ;
if ( F_19 ( V_3 -> V_38 == ~ 0U ) )
return V_39 ;
V_37 = ( T_2 ) V_6 * V_3 -> V_38 ;
V_36 = ( ( ( V_37 * V_10 ) >> V_12 ) + V_40 - 1 ) / V_40 ;
V_36 += 3 * V_3 -> V_19 ;
V_36 = ( V_36 + 1 ) & ~ 1U ;
return V_36 ;
}
static bool F_20 (
struct V_1 * V_2 , const struct V_41 * V_42 , T_1 V_43 , T_1 * V_44 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_3 V_45 = V_3 -> V_24 , V_46 = F_21 ( V_2 ) -> V_47 ;
T_1 V_36 = V_21 -> V_28 ;
if ( V_42 -> V_48 > 0 )
V_36 = F_22 ( V_49 , V_36 - V_42 -> V_48 , 1 ) ;
if ( V_46 == V_25 && V_45 != V_25 ) {
V_3 -> V_50 = 1 ;
V_3 -> V_51 = V_21 -> V_52 ;
V_36 = F_23 ( V_21 ) + V_43 ;
} else if ( V_45 >= V_25 && V_46 < V_25 ) {
V_3 -> V_53 = 1 ;
V_3 -> V_50 = 0 ;
}
V_3 -> V_24 = V_46 ;
if ( V_3 -> V_53 ) {
V_36 = F_16 ( V_36 , V_3 -> V_27 ) ;
V_3 -> V_53 = 0 ;
}
if ( V_3 -> V_50 ) {
* V_44 = F_16 ( V_36 , F_23 ( V_21 ) + V_43 ) ;
return true ;
}
* V_44 = V_36 ;
return false ;
}
static void F_24 ( struct V_1 * V_2 , const struct V_41 * V_42 ,
T_1 V_43 , T_1 V_6 , int V_10 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_36 = 0 , V_54 = 0 ;
if ( ! V_43 )
return;
if ( F_20 ( V_2 , V_42 , V_43 , & V_36 ) )
goto V_55;
V_54 = F_18 ( V_2 , V_6 , V_10 ) ;
if ( F_1 ( V_2 ) )
V_36 = F_13 ( V_36 + V_43 , V_54 ) ;
else if ( V_36 < V_54 || V_21 -> V_52 < V_39 )
V_36 = V_36 + V_43 ;
V_36 = F_16 ( V_36 , V_56 ) ;
V_55:
V_21 -> V_28 = F_13 ( V_36 , V_21 -> V_57 ) ;
if ( V_3 -> V_16 == V_26 )
V_21 -> V_28 = F_13 ( V_21 -> V_28 , V_56 ) ;
}
static bool F_25 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_58 =
F_26 ( & V_21 -> V_59 , & V_3 -> V_60 ) >
V_3 -> V_38 ;
T_1 V_61 , V_6 ;
if ( V_3 -> V_62 == V_35 )
return V_58 ;
V_61 = V_42 -> V_63 ;
V_6 = F_3 ( V_2 ) ;
if ( V_3 -> V_62 > V_35 )
return V_58 &&
( V_42 -> V_48 ||
V_61 >= F_18 ( V_2 , V_6 , V_3 -> V_62 ) ) ;
return V_58 ||
V_61 <= F_18 ( V_2 , V_6 , V_35 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_64 = ( V_3 -> V_64 + 1 ) & ( V_65 - 1 ) ;
V_3 -> V_60 = V_21 -> V_59 ;
V_3 -> V_62 = V_66 [ V_3 -> V_64 ] ;
}
static void F_28 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( ( V_3 -> V_16 == V_34 ) && ! V_3 -> V_7 &&
F_25 ( V_2 , V_42 ) )
F_27 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_16 = V_17 ;
V_3 -> V_62 = V_67 ;
V_3 -> V_68 = V_67 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_16 = V_34 ;
V_3 -> V_62 = V_35 ;
V_3 -> V_68 = V_69 ;
V_3 -> V_64 = V_65 - 1 - F_31 ( V_70 ) ;
F_27 ( V_2 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
if ( ! F_1 ( V_2 ) )
F_29 ( V_2 ) ;
else
F_30 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_71 = V_21 -> V_59 . V_72 ;
V_3 -> V_73 = V_21 -> V_52 ;
V_3 -> V_74 = V_21 -> V_75 ;
V_3 -> V_76 = 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
V_3 -> V_8 = 0 ;
V_3 -> V_7 = 0 ;
V_3 -> V_77 = false ;
F_33 ( V_2 ) ;
}
static void F_35 ( struct V_1 * V_2 , T_1 V_6 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_78 ;
if ( V_3 -> V_8 ) {
V_78 = abs ( V_6 - V_3 -> V_8 ) ;
if ( ( V_78 * V_35 <= V_79 * V_3 -> V_8 ) ||
( F_6 ( V_2 , V_78 , V_35 ) <=
V_80 ) ) {
V_3 -> V_8 = ( V_6 + V_3 -> V_8 ) >> 1 ;
V_3 -> V_7 = 1 ;
V_3 -> V_62 = V_35 ;
V_3 -> V_76 = 0 ;
return;
}
}
V_3 -> V_8 = V_6 ;
F_33 ( V_2 ) ;
}
static void F_36 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_75 , V_52 ;
T_2 V_6 ;
V_49 V_81 ;
if ( V_3 -> V_7 ) {
if ( V_3 -> V_16 == V_34 && V_3 -> V_82 &&
++ V_3 -> V_76 >= V_83 ) {
F_34 ( V_2 ) ;
F_30 ( V_2 ) ;
}
return;
}
if ( ! V_3 -> V_77 ) {
if ( ! V_42 -> V_48 )
return;
F_33 ( V_2 ) ;
V_3 -> V_77 = true ;
}
if ( V_42 -> V_84 ) {
F_34 ( V_2 ) ;
return;
}
if ( V_3 -> V_82 )
V_3 -> V_76 ++ ;
if ( V_3 -> V_76 < V_85 )
return;
if ( V_3 -> V_76 > 4 * V_85 ) {
F_34 ( V_2 ) ;
return;
}
if ( ! V_42 -> V_48 )
return;
V_75 = V_21 -> V_75 - V_3 -> V_74 ;
V_52 = V_21 -> V_52 - V_3 -> V_73 ;
if ( ! V_52 || ( V_75 << V_12 ) < V_86 * V_52 )
return;
V_81 = ( V_49 ) ( V_21 -> V_59 . V_72 - V_3 -> V_71 ) ;
if ( V_81 < 1 )
return;
V_81 = F_37 ( V_81 ) ;
if ( V_81 < 1 ) {
F_34 ( V_2 ) ;
return;
}
V_6 = ( T_2 ) V_52 * V_40 ;
F_38 ( V_6 , V_81 ) ;
F_35 ( V_2 , V_6 ) ;
}
static void F_39 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_3 -> V_82 = 0 ;
if ( V_42 -> V_52 < 0 || V_42 -> V_87 <= 0 )
return;
if ( ! F_40 ( V_42 -> V_88 , V_3 -> V_51 ) ) {
V_3 -> V_51 = V_21 -> V_52 ;
V_3 -> V_89 ++ ;
V_3 -> V_82 = 1 ;
V_3 -> V_50 = 0 ;
}
F_36 ( V_2 , V_42 ) ;
V_6 = ( T_2 ) V_42 -> V_52 * V_40 ;
F_38 ( V_6 , V_42 -> V_87 ) ;
if ( ! V_42 -> V_84 || V_6 >= F_3 ( V_2 ) ) {
F_41 ( & V_3 -> V_6 , V_90 , V_3 -> V_89 , V_6 ) ;
}
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_41 * V_42 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_91 ;
if ( F_1 ( V_2 ) || ! V_3 -> V_82 || V_42 -> V_84 )
return;
V_91 = ( T_2 ) V_3 -> V_92 * V_93 >> V_12 ;
if ( F_3 ( V_2 ) >= V_91 ) {
V_3 -> V_92 = F_3 ( V_2 ) ;
V_3 -> V_4 = 0 ;
return;
}
++ V_3 -> V_4 ;
}
static void F_43 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_3 -> V_16 == V_17 && F_1 ( V_2 ) ) {
V_3 -> V_16 = V_94 ;
V_3 -> V_62 = V_95 ;
V_3 -> V_68 = V_67 ;
}
if ( V_3 -> V_16 == V_94 &&
F_23 ( F_8 ( V_2 ) ) <=
F_18 ( V_2 , F_3 ( V_2 ) , V_35 ) )
F_30 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
bool V_96 ;
V_96 = F_45 ( V_97 ,
V_3 -> V_98 + V_99 * V_100 ) ;
if ( V_42 -> V_101 >= 0 &&
( V_42 -> V_101 <= V_3 -> V_38 || V_96 ) ) {
V_3 -> V_38 = V_42 -> V_101 ;
V_3 -> V_98 = V_97 ;
}
if ( V_102 > 0 && V_96 &&
! V_3 -> V_33 && V_3 -> V_16 != V_26 ) {
V_3 -> V_16 = V_26 ;
V_3 -> V_62 = V_35 ;
V_3 -> V_68 = V_35 ;
F_15 ( V_2 ) ;
V_3 -> V_103 = 0 ;
}
if ( V_3 -> V_16 == V_26 ) {
V_21 -> V_32 =
( V_21 -> V_52 + F_23 ( V_21 ) ) ? : 1 ;
if ( ! V_3 -> V_103 &&
F_23 ( V_21 ) <= V_56 ) {
V_3 -> V_103 = V_97 +
F_46 ( V_102 ) ;
V_3 -> V_104 = 0 ;
V_3 -> V_51 = V_21 -> V_52 ;
} else if ( V_3 -> V_103 ) {
if ( V_3 -> V_82 )
V_3 -> V_104 = 1 ;
if ( V_3 -> V_104 &&
F_45 ( V_97 , V_3 -> V_103 ) ) {
V_3 -> V_98 = V_97 ;
V_3 -> V_53 = 1 ;
F_32 ( V_2 ) ;
}
}
}
V_3 -> V_33 = 0 ;
}
static void F_47 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
F_39 ( V_2 , V_42 ) ;
F_28 ( V_2 , V_42 ) ;
F_42 ( V_2 , V_42 ) ;
F_43 ( V_2 , V_42 ) ;
F_44 ( V_2 , V_42 ) ;
}
static void F_48 ( struct V_1 * V_2 , const struct V_41 * V_42 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_1 V_6 ;
F_47 ( V_2 , V_42 ) ;
V_6 = F_5 ( V_2 ) ;
F_9 ( V_2 , V_6 , V_3 -> V_62 ) ;
F_12 ( V_2 ) ;
F_24 ( V_2 , V_42 , V_42 -> V_105 , V_6 , V_3 -> V_68 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_6 ;
V_3 -> V_27 = 0 ;
V_3 -> V_19 = 0 ;
V_3 -> V_89 = 0 ;
V_3 -> V_51 = 0 ;
V_3 -> V_24 = V_106 ;
V_3 -> V_50 = 0 ;
V_3 -> V_103 = 0 ;
V_3 -> V_104 = 0 ;
V_3 -> V_38 = F_50 ( V_21 ) ;
V_3 -> V_98 = V_97 ;
F_51 ( & V_3 -> V_6 , V_3 -> V_89 , 0 ) ;
V_6 = ( T_2 ) V_21 -> V_28 * V_40 ;
F_38 ( V_6 , ( V_21 -> V_107 >> 3 ) ? : V_108 ) ;
V_2 -> V_18 = 0 ;
F_9 ( V_2 , V_6 , V_67 ) ;
V_3 -> V_53 = 0 ;
V_3 -> V_82 = 0 ;
V_3 -> V_33 = 0 ;
V_3 -> V_92 = 0 ;
V_3 -> V_4 = 0 ;
V_3 -> V_60 . V_109 = 0 ;
V_3 -> V_64 = 0 ;
F_34 ( V_2 ) ;
F_29 ( V_2 ) ;
}
static T_1 F_52 ( struct V_1 * V_2 )
{
return 3 ;
}
static T_1 F_53 ( struct V_1 * V_2 )
{
return F_8 ( V_2 ) -> V_28 ;
}
static T_1 F_54 ( struct V_1 * V_2 )
{
F_15 ( V_2 ) ;
return V_110 ;
}
static T_4 F_55 ( struct V_1 * V_2 , T_1 V_111 , int * V_112 ,
union V_113 * V_114 )
{
if ( V_111 & ( 1 << ( V_115 - 1 ) ) ||
V_111 & ( 1 << ( V_116 - 1 ) ) ) {
struct V_20 * V_21 = F_8 ( V_2 ) ;
struct V_3 * V_3 = F_2 ( V_2 ) ;
T_2 V_6 = F_5 ( V_2 ) ;
V_6 = V_6 * V_21 -> V_11 * V_13 >> V_14 ;
memset ( & V_114 -> V_3 , 0 , sizeof( V_114 -> V_3 ) ) ;
V_114 -> V_3 . V_117 = ( T_1 ) V_6 ;
V_114 -> V_3 . V_118 = ( T_1 ) ( V_6 >> 32 ) ;
V_114 -> V_3 . V_119 = V_3 -> V_38 ;
V_114 -> V_3 . V_66 = V_3 -> V_62 ;
V_114 -> V_3 . V_69 = V_3 -> V_68 ;
* V_112 = V_115 ;
return sizeof( V_114 -> V_3 ) ;
}
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , T_3 V_120 )
{
struct V_3 * V_3 = F_2 ( V_2 ) ;
if ( V_120 == V_121 ) {
struct V_41 V_42 = { . V_48 = 1 } ;
V_3 -> V_24 = V_121 ;
V_3 -> V_92 = 0 ;
V_3 -> V_82 = 1 ;
F_36 ( V_2 , & V_42 ) ;
}
}
static int T_5 F_57 ( void )
{
F_58 ( sizeof( struct V_3 ) > V_122 ) ;
return F_59 ( & V_123 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_123 ) ;
}
