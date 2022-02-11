static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_5 | V_4 , V_2 -> V_6 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_6 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_7 ,
struct V_8 * V_6 , T_2 V_9 ,
struct V_10 * V_10 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
V_13 = F_6 ( V_2 -> V_14 , sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 )
return - V_16 ;
V_13 -> V_6 = V_6 ;
V_13 -> V_9 = V_9 ;
V_13 -> V_7 = V_2 -> V_6 + V_7 ;
V_11 = F_7 ( L_1 , V_17 , V_10 ,
V_13 ) ;
return V_11 ? 0 : - V_16 ;
}
void T_3 F_8 ( void )
{
struct V_18 * V_18 ;
int V_19 ;
V_18 = F_9 ( NULL , L_2 , NULL , 0 , 126000000 ) ;
if ( F_10 ( V_18 ) )
F_11 ( L_3 ) ;
V_18 = F_9 ( NULL , L_4 , NULL , 0 , 3000000 ) ;
if ( F_10 ( V_18 ) )
F_11 ( L_5 ) ;
V_19 = F_12 ( V_18 , NULL , L_6 ) ;
if ( V_19 )
F_11 ( L_7 ) ;
V_18 = F_9 ( NULL , L_8 , NULL , 0 , 125000000 ) ;
if ( F_10 ( V_18 ) )
F_11 ( L_9 ) ;
V_19 = F_12 ( V_18 , NULL , L_10 ) ;
if ( V_19 )
F_11 ( L_11 ) ;
}
static int F_13 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_14 ( V_21 , struct V_22 , V_21 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
const struct V_24 * V_25 = V_23 -> V_25 ;
return F_3 ( V_2 , V_25 -> V_26 ) &
V_27 ;
}
static void F_15 ( unsigned long V_28 ,
unsigned long V_29 ,
T_1 * V_30 , T_1 * V_31 )
{
T_4 div ;
div = ( T_4 ) V_28 << V_32 ;
F_16 ( div , V_29 ) ;
* V_30 = div >> V_32 ;
* V_31 = div & ( ( 1 << V_32 ) - 1 ) ;
}
static long F_17 ( unsigned long V_29 ,
T_1 V_30 , T_1 V_31 , T_1 V_33 )
{
T_4 V_28 ;
if ( V_33 == 0 )
return 0 ;
V_28 = ( T_4 ) V_29 * ( ( V_30 << V_32 ) + V_31 ) ;
F_16 ( V_28 , V_33 ) ;
return V_28 >> V_32 ;
}
static long F_18 ( struct V_20 * V_21 , unsigned long V_28 ,
unsigned long * V_29 )
{
T_1 V_30 , V_31 ;
F_15 ( V_28 , * V_29 , & V_30 , & V_31 ) ;
return F_17 ( * V_29 , V_30 , V_31 , 1 ) ;
}
static unsigned long F_19 ( struct V_20 * V_21 ,
unsigned long V_29 )
{
struct V_22 * V_23 = F_14 ( V_21 , struct V_22 , V_21 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
const struct V_24 * V_25 = V_23 -> V_25 ;
T_1 V_34 = F_3 ( V_2 , V_25 -> V_26 ) ;
T_1 V_30 , V_33 , V_31 ;
bool V_35 ;
if ( V_29 == 0 )
return 0 ;
V_31 = F_3 ( V_2 , V_25 -> V_36 ) & V_37 ;
V_30 = ( V_34 & V_38 ) >> V_39 ;
V_33 = ( V_34 & V_40 ) >> V_41 ;
V_35 = F_3 ( V_2 , V_25 -> V_42 + 4 ) &
V_25 -> V_43 -> V_44 ;
if ( V_35 )
V_30 *= 2 ;
return F_17 ( V_29 , V_30 , V_31 , V_33 ) ;
}
static void F_20 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_14 ( V_21 , struct V_22 , V_21 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
const struct V_24 * V_25 = V_23 -> V_25 ;
F_21 ( & V_2 -> V_45 ) ;
F_1 ( V_2 , V_25 -> V_46 ,
F_3 ( V_2 , V_25 -> V_46 ) |
V_47 ) ;
F_1 ( V_2 , V_25 -> V_26 ,
F_3 ( V_2 , V_25 -> V_26 ) |
V_48 ) ;
F_22 ( & V_2 -> V_45 ) ;
}
static int F_23 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_14 ( V_21 , struct V_22 , V_21 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
const struct V_24 * V_25 = V_23 -> V_25 ;
T_5 V_49 ;
F_1 ( V_2 , V_25 -> V_26 ,
F_3 ( V_2 , V_25 -> V_26 ) &
~ V_48 ) ;
F_1 ( V_2 , V_25 -> V_46 ,
F_3 ( V_2 , V_25 -> V_46 ) & ~ V_47 ) ;
V_49 = F_24 ( F_25 () , V_50 ) ;
while ( ! ( F_3 ( V_2 , V_51 ) & V_25 -> V_52 ) ) {
if ( F_26 ( F_25 () , V_49 ) ) {
F_27 ( V_2 -> V_14 , L_12 ,
F_28 ( V_21 ) ) ;
return - V_53 ;
}
F_29 () ;
}
return 0 ;
}
static void
F_30 ( struct V_1 * V_2 , T_1 V_42 , T_1 * V_43 )
{
int V_54 ;
for ( V_54 = 3 ; V_54 >= 0 ; V_54 -- )
F_1 ( V_2 , V_42 + V_54 * 4 , V_43 [ V_54 ] ) ;
}
static int F_31 ( struct V_20 * V_21 ,
unsigned long V_28 , unsigned long V_29 )
{
struct V_22 * V_23 = F_14 ( V_21 , struct V_22 , V_21 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
const struct V_24 * V_25 = V_23 -> V_25 ;
bool V_55 , V_56 , V_57 ;
T_1 V_30 , V_31 , V_58 ;
T_1 V_43 [ 4 ] ;
int V_54 ;
if ( V_28 < V_25 -> V_59 || V_28 > V_25 -> V_60 ) {
F_27 ( V_2 -> V_14 , L_13 ,
F_28 ( V_21 ) , V_28 ,
V_25 -> V_59 , V_25 -> V_60 ) ;
return - V_61 ;
}
if ( V_28 > V_25 -> V_62 ) {
V_56 = true ;
V_28 /= 2 ;
} else {
V_56 = false ;
}
F_15 ( V_28 , V_29 , & V_30 , & V_31 ) ;
for ( V_54 = 3 ; V_54 >= 0 ; V_54 -- )
V_43 [ V_54 ] = F_3 ( V_2 , V_25 -> V_42 + V_54 * 4 ) ;
V_55 = V_43 [ 1 ] & V_25 -> V_43 -> V_44 ;
V_43 [ 0 ] &= ~ V_25 -> V_43 -> V_63 ;
V_43 [ 0 ] |= V_25 -> V_43 -> V_64 ;
V_43 [ 1 ] &= ~ V_25 -> V_43 -> V_65 ;
V_43 [ 1 ] |= V_25 -> V_43 -> V_66 ;
V_43 [ 3 ] &= ~ V_25 -> V_43 -> V_67 ;
V_43 [ 3 ] |= V_25 -> V_43 -> V_68 ;
if ( V_55 && ! V_56 ) {
V_43 [ 1 ] &= ~ V_25 -> V_43 -> V_44 ;
V_57 = true ;
} else if ( ! V_55 && V_56 ) {
V_43 [ 1 ] |= V_25 -> V_43 -> V_44 ;
V_57 = false ;
} else {
V_57 = true ;
}
F_1 ( V_2 , V_69 ,
F_3 ( V_2 , V_69 ) |
V_25 -> V_70 ) ;
if ( V_57 )
F_30 ( V_2 , V_25 -> V_42 , V_43 ) ;
F_1 ( V_2 , V_25 -> V_36 , V_31 ) ;
V_58 = F_3 ( V_2 , V_25 -> V_26 ) ;
V_58 &= ~ V_38 ;
V_58 |= V_30 << V_39 ;
V_58 &= ~ V_40 ;
V_58 |= 1 << V_41 ;
F_1 ( V_2 , V_25 -> V_26 , V_58 ) ;
if ( ! V_57 )
F_30 ( V_2 , V_25 -> V_42 , V_43 ) ;
return 0 ;
}
static int F_32 ( struct V_20 * V_21 ,
struct V_10 * V_10 )
{
struct V_22 * V_23 = F_14 ( V_21 , struct V_22 , V_21 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
const struct V_24 * V_25 = V_23 -> V_25 ;
struct V_8 * V_6 ;
V_6 = F_6 ( V_2 -> V_14 , 7 * sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_6 [ 0 ] . V_71 = L_14 ;
V_6 [ 0 ] . V_72 = V_25 -> V_46 ;
V_6 [ 1 ] . V_71 = L_15 ;
V_6 [ 1 ] . V_72 = V_25 -> V_26 ;
V_6 [ 2 ] . V_71 = L_16 ;
V_6 [ 2 ] . V_72 = V_25 -> V_36 ;
V_6 [ 3 ] . V_71 = L_17 ;
V_6 [ 3 ] . V_72 = V_25 -> V_42 + 0 * 4 ;
V_6 [ 4 ] . V_71 = L_18 ;
V_6 [ 4 ] . V_72 = V_25 -> V_42 + 1 * 4 ;
V_6 [ 5 ] . V_71 = L_19 ;
V_6 [ 5 ] . V_72 = V_25 -> V_42 + 2 * 4 ;
V_6 [ 6 ] . V_71 = L_20 ;
V_6 [ 6 ] . V_72 = V_25 -> V_42 + 3 * 4 ;
return F_5 ( V_2 , 0 , V_6 , 7 , V_10 ) ;
}
static struct V_73 *
F_33 ( struct V_20 * V_21 )
{
return F_14 ( V_21 , struct V_73 , div . V_21 ) ;
}
static int F_34 ( struct V_20 * V_21 )
{
struct V_73 * V_74 = F_33 ( V_21 ) ;
struct V_1 * V_2 = V_74 -> V_2 ;
const struct V_75 * V_25 = V_74 -> V_25 ;
return ! ( F_3 ( V_2 , V_25 -> V_76 ) & V_77 ) ;
}
static long F_35 ( struct V_20 * V_21 ,
unsigned long V_28 ,
unsigned long * V_29 )
{
return V_78 . V_79 ( V_21 , V_28 , V_29 ) ;
}
static unsigned long F_36 ( struct V_20 * V_21 ,
unsigned long V_29 )
{
return V_78 . V_80 ( V_21 , V_29 ) ;
}
static void F_37 ( struct V_20 * V_21 )
{
struct V_73 * V_74 = F_33 ( V_21 ) ;
struct V_1 * V_2 = V_74 -> V_2 ;
const struct V_75 * V_25 = V_74 -> V_25 ;
F_21 ( & V_2 -> V_45 ) ;
F_1 ( V_2 , V_25 -> V_81 ,
( F_3 ( V_2 , V_25 -> V_81 ) &
~ V_25 -> V_82 ) | V_25 -> V_83 ) ;
F_1 ( V_2 , V_25 -> V_76 , V_77 ) ;
F_22 ( & V_2 -> V_45 ) ;
}
static int F_38 ( struct V_20 * V_21 )
{
struct V_73 * V_74 = F_33 ( V_21 ) ;
struct V_1 * V_2 = V_74 -> V_2 ;
const struct V_75 * V_25 = V_74 -> V_25 ;
F_21 ( & V_2 -> V_45 ) ;
F_1 ( V_2 , V_25 -> V_76 ,
F_3 ( V_2 , V_25 -> V_76 ) &
~ V_77 ) ;
F_1 ( V_2 , V_25 -> V_81 ,
F_3 ( V_2 , V_25 -> V_81 ) & ~ V_25 -> V_83 ) ;
F_22 ( & V_2 -> V_45 ) ;
return 0 ;
}
static int F_39 ( struct V_20 * V_21 ,
unsigned long V_28 ,
unsigned long V_29 )
{
struct V_73 * V_74 = F_33 ( V_21 ) ;
struct V_1 * V_2 = V_74 -> V_2 ;
const struct V_75 * V_25 = V_74 -> V_25 ;
T_1 V_84 , div , V_85 = 1 << V_86 ;
div = F_40 ( V_29 , V_28 ) ;
div = F_41 ( div , V_85 ) ;
if ( div == V_85 )
div = 0 ;
F_1 ( V_2 , V_25 -> V_76 , div ) ;
V_84 = F_3 ( V_2 , V_25 -> V_81 ) ;
F_1 ( V_2 , V_25 -> V_81 , V_84 | V_25 -> V_82 ) ;
F_1 ( V_2 , V_25 -> V_81 , V_84 & ~ V_25 -> V_82 ) ;
return 0 ;
}
static int F_42 ( struct V_20 * V_21 ,
struct V_10 * V_10 )
{
struct V_73 * V_74 = F_33 ( V_21 ) ;
struct V_1 * V_2 = V_74 -> V_2 ;
const struct V_75 * V_25 = V_74 -> V_25 ;
struct V_8 * V_6 ;
V_6 = F_6 ( V_2 -> V_14 , 7 * sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_6 [ 0 ] . V_71 = L_21 ;
V_6 [ 0 ] . V_72 = V_25 -> V_81 ;
V_6 [ 1 ] . V_71 = L_22 ;
V_6 [ 1 ] . V_72 = V_25 -> V_76 ;
return F_5 ( V_2 , 0 , V_6 , 2 , V_10 ) ;
}
static struct V_87 * F_43 ( struct V_20 * V_21 )
{
return F_14 ( V_21 , struct V_87 , V_21 ) ;
}
static int F_44 ( struct V_20 * V_21 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
return ( F_3 ( V_2 , V_25 -> V_89 ) & V_90 ) != 0 ;
}
static T_1 F_45 ( struct V_20 * V_21 ,
unsigned long V_28 ,
unsigned long V_29 ,
bool V_91 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
const struct V_88 * V_25 = clock -> V_25 ;
T_1 V_92 =
F_46 ( V_93 - V_25 -> V_94 , 0 ) >> 1 ;
T_4 V_95 = ( T_4 ) V_29 << V_93 ;
T_4 V_96 ;
T_1 div , V_97 , V_98 ;
V_96 = F_16 ( V_95 , V_28 ) ;
div = V_95 ;
if ( V_91 && ( ( div & V_92 ) != 0 || V_96 != 0 ) )
div += V_92 + 1 ;
div &= ~ V_92 ;
if ( V_25 -> V_99 ) {
V_97 = 2 << V_93 ;
V_98 = ( F_47 ( V_25 -> V_100 ) - 1 ) << V_93 ;
} else {
V_97 = 1 << V_93 ;
V_98 = F_46 ( V_25 -> V_100 + V_93 - 1 ,
V_93 - V_25 -> V_94 ) ;
}
div = F_48 ( T_1 , div , V_97 ) ;
div = F_49 ( T_1 , div , V_98 ) ;
return div ;
}
static long F_50 ( struct V_87 * clock ,
unsigned long V_29 ,
T_1 div )
{
const struct V_88 * V_25 = clock -> V_25 ;
T_4 V_95 ;
div >>= V_93 - V_25 -> V_94 ;
div &= ( 1 << ( V_25 -> V_100 + V_25 -> V_94 ) ) - 1 ;
if ( div == 0 )
return 0 ;
V_95 = ( T_4 ) V_29 << V_25 -> V_94 ;
F_16 ( V_95 , div ) ;
return V_95 ;
}
static unsigned long F_51 ( struct V_20 * V_21 ,
unsigned long V_29 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
T_1 div = F_3 ( V_2 , V_25 -> V_101 ) ;
return F_50 ( clock , V_29 , div ) ;
}
static void F_52 ( struct V_87 * clock )
{
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
T_5 V_49 = F_24 ( F_25 () , V_50 ) ;
while ( F_3 ( V_2 , V_25 -> V_89 ) & V_102 ) {
if ( F_26 ( F_25 () , V_49 ) ) {
F_27 ( V_2 -> V_14 , L_12 ,
F_28 ( & clock -> V_21 ) ) ;
return;
}
F_29 () ;
}
}
static void F_53 ( struct V_20 * V_21 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
F_21 ( & V_2 -> V_45 ) ;
F_1 ( V_2 , V_25 -> V_89 ,
F_3 ( V_2 , V_25 -> V_89 ) & ~ V_90 ) ;
F_22 ( & V_2 -> V_45 ) ;
F_52 ( clock ) ;
}
static int F_54 ( struct V_20 * V_21 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
F_21 ( & V_2 -> V_45 ) ;
F_1 ( V_2 , V_25 -> V_89 ,
F_3 ( V_2 , V_25 -> V_89 ) |
V_90 |
V_103 ) ;
F_22 ( & V_2 -> V_45 ) ;
return 0 ;
}
static int F_55 ( struct V_20 * V_21 ,
unsigned long V_28 , unsigned long V_29 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
T_1 div = F_45 ( V_21 , V_28 , V_29 , false ) ;
T_1 V_104 ;
F_21 ( & V_2 -> V_45 ) ;
V_104 = F_3 ( V_2 , V_25 -> V_89 ) & ~ V_105 ;
V_104 |= ( div & V_106 ) ? V_105 : 0 ;
F_1 ( V_2 , V_25 -> V_89 , V_104 ) ;
F_1 ( V_2 , V_25 -> V_101 , div ) ;
F_22 ( & V_2 -> V_45 ) ;
return 0 ;
}
static int F_56 ( struct V_20 * V_21 ,
struct V_107 * V_108 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_20 * V_109 , * V_110 = NULL ;
unsigned long V_28 , V_111 = 0 ;
unsigned long V_112 , V_113 = 0 ;
T_2 V_54 ;
T_1 div ;
for ( V_54 = 0 ; V_54 < F_57 ( V_21 ) ; ++ V_54 ) {
V_109 = F_58 ( V_21 , V_54 ) ;
if ( ! V_109 )
continue;
V_112 = F_59 ( V_109 ) ;
div = F_45 ( V_21 , V_108 -> V_28 , V_112 , true ) ;
V_28 = F_50 ( clock , V_112 , div ) ;
if ( V_28 > V_111 && V_28 <= V_108 -> V_28 ) {
V_110 = V_109 ;
V_113 = V_112 ;
V_111 = V_28 ;
}
}
if ( ! V_110 )
return - V_61 ;
V_108 -> V_114 = V_110 ;
V_108 -> V_115 = V_113 ;
V_108 -> V_28 = V_111 ;
return 0 ;
}
static int F_60 ( struct V_20 * V_21 , T_6 V_116 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
T_6 V_117 = ( V_116 << V_118 ) & V_119 ;
F_1 ( V_2 , V_25 -> V_89 , V_117 ) ;
return 0 ;
}
static T_6 F_61 ( struct V_20 * V_21 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
T_1 V_117 = F_3 ( V_2 , V_25 -> V_89 ) ;
return ( V_117 & V_119 ) >> V_118 ;
}
static int F_62 ( struct V_20 * V_21 ,
struct V_10 * V_10 )
{
struct V_87 * clock = F_43 ( V_21 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_88 * V_25 = clock -> V_25 ;
return F_5 (
V_2 , V_25 -> V_89 ,
V_120 ,
F_63 ( V_120 ) ,
V_10 ) ;
}
static int F_64 ( struct V_20 * V_21 )
{
return true ;
}
static struct V_18 * F_65 ( struct V_1 * V_2 ,
const struct V_24 * V_25 )
{
struct V_22 * V_23 ;
struct V_121 V_122 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_123 = & V_2 -> V_124 ;
V_122 . V_125 = 1 ;
V_122 . V_71 = V_25 -> V_71 ;
V_122 . V_126 = & V_127 ;
V_122 . V_128 = V_129 ;
V_23 = F_66 ( sizeof( * V_23 ) , V_15 ) ;
if ( ! V_23 )
return NULL ;
V_23 -> V_2 = V_2 ;
V_23 -> V_25 = V_25 ;
V_23 -> V_21 . V_122 = & V_122 ;
return F_67 ( V_2 -> V_14 , & V_23 -> V_21 ) ;
}
static struct V_18 *
F_68 ( struct V_1 * V_2 ,
const struct V_75 * V_25 )
{
struct V_73 * V_74 ;
struct V_121 V_122 ;
struct V_18 * V_18 ;
const char * V_130 ;
if ( V_25 -> V_131 != 1 ) {
V_130 = F_69 ( V_2 -> V_14 , V_15 ,
L_23 , V_25 -> V_71 ) ;
if ( ! V_130 )
return NULL ;
} else {
V_130 = V_25 -> V_71 ;
}
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_123 = & V_25 -> V_132 ;
V_122 . V_125 = 1 ;
V_122 . V_71 = V_130 ;
V_122 . V_126 = & V_133 ;
V_122 . V_128 = V_134 | V_129 ;
V_74 = F_6 ( V_2 -> V_14 , sizeof( * V_74 ) , V_15 ) ;
if ( ! V_74 )
return NULL ;
V_74 -> div . V_3 = V_2 -> V_6 + V_25 -> V_76 ;
V_74 -> div . V_135 = V_136 ;
V_74 -> div . V_137 = V_86 ;
V_74 -> div . V_128 = V_138 ;
V_74 -> div . V_139 = & V_2 -> V_45 ;
V_74 -> div . V_21 . V_122 = & V_122 ;
V_74 -> div . V_140 = NULL ;
V_74 -> V_2 = V_2 ;
V_74 -> V_25 = V_25 ;
V_18 = F_67 ( V_2 -> V_14 , & V_74 -> div . V_21 ) ;
if ( F_10 ( V_18 ) )
return V_18 ;
if ( V_25 -> V_131 != 1 ) {
return F_70 ( V_2 -> V_14 , V_25 -> V_71 ,
V_130 ,
V_134 ,
1 ,
V_25 -> V_131 ) ;
}
return V_18 ;
}
static struct V_18 * F_71 ( struct V_1 * V_2 ,
const struct V_88 * V_25 )
{
struct V_87 * clock ;
struct V_121 V_122 ;
const char * V_141 [ 1 << V_142 ] ;
T_2 V_54 ;
for ( V_54 = 0 ; V_54 < V_25 -> V_143 ; V_54 ++ ) {
if ( strcmp ( V_25 -> V_141 [ V_54 ] , L_24 ) == 0 )
V_141 [ V_54 ] = V_2 -> V_124 ;
else
V_141 [ V_54 ] = V_25 -> V_141 [ V_54 ] ;
}
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_123 = V_141 ;
V_122 . V_125 = V_25 -> V_143 ;
V_122 . V_71 = V_25 -> V_71 ;
V_122 . V_128 = V_129 ;
if ( V_25 -> V_144 ) {
V_122 . V_126 = & V_145 ;
} else {
V_122 . V_126 = & V_146 ;
V_122 . V_128 |= V_147 | V_148 ;
}
clock = F_6 ( V_2 -> V_14 , sizeof( * clock ) , V_15 ) ;
if ( ! clock )
return NULL ;
clock -> V_2 = V_2 ;
clock -> V_25 = V_25 ;
clock -> V_21 . V_122 = & V_122 ;
return F_67 ( V_2 -> V_14 , & clock -> V_21 ) ;
}
static struct V_18 * F_72 ( struct V_1 * V_2 ,
const struct V_149 * V_25 )
{
return F_73 ( V_2 -> V_14 , V_25 -> V_71 , V_25 -> V_109 ,
V_129 | V_147 ,
V_2 -> V_6 + V_25 -> V_89 ,
V_150 , 0 , & V_2 -> V_45 ) ;
}
static int F_74 ( struct V_151 * V_152 )
{
struct V_153 * V_14 = & V_152 -> V_14 ;
struct V_18 * * V_154 ;
struct V_1 * V_2 ;
struct V_155 * V_156 ;
const struct V_157 * V_158 ;
const T_2 V_159 = F_63 ( V_160 ) ;
T_2 V_54 ;
V_2 = F_6 ( V_14 ,
sizeof( * V_2 ) + V_159 * sizeof( * V_154 ) ,
V_15 ) ;
if ( ! V_2 )
return - V_16 ;
F_75 ( & V_2 -> V_45 ) ;
V_2 -> V_14 = V_14 ;
V_156 = F_76 ( V_152 , V_161 , 0 ) ;
V_2 -> V_6 = F_77 ( V_14 , V_156 ) ;
if ( F_10 ( V_2 -> V_6 ) )
return F_78 ( V_2 -> V_6 ) ;
V_2 -> V_124 = F_79 ( V_14 -> V_162 , 0 ) ;
if ( ! V_2 -> V_124 )
return - V_163 ;
F_80 ( V_152 , V_2 ) ;
V_2 -> V_164 . V_165 = V_159 ;
V_2 -> V_164 . V_154 = V_2 -> V_154 ;
V_154 = V_2 -> V_154 ;
for ( V_54 = 0 ; V_54 < V_159 ; V_54 ++ ) {
V_158 = & V_160 [ V_54 ] ;
if ( V_158 -> V_166 && V_158 -> V_25 )
V_154 [ V_54 ] = V_158 -> V_166 ( V_2 , V_158 -> V_25 ) ;
}
return F_81 ( V_14 -> V_162 , V_167 ,
& V_2 -> V_164 ) ;
}
