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
struct V_18 * V_19 ;
int V_20 ;
V_19 = F_9 ( NULL , L_2 , NULL , 0 , 126000000 ) ;
if ( F_10 ( V_19 ) )
F_11 ( L_3 ) ;
V_19 = F_9 ( NULL , L_4 , NULL , 0 , 3000000 ) ;
if ( F_10 ( V_19 ) )
F_11 ( L_5 ) ;
V_20 = F_12 ( V_19 , NULL , L_6 ) ;
if ( V_20 )
F_11 ( L_7 ) ;
V_19 = F_9 ( NULL , L_8 , NULL , 0 , 125000000 ) ;
if ( F_10 ( V_19 ) )
F_11 ( L_9 ) ;
V_20 = F_12 ( V_19 , NULL , L_10 ) ;
if ( V_20 )
F_11 ( L_11 ) ;
}
static int F_13 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_14 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
const struct V_23 * V_24 = V_22 -> V_24 ;
return F_3 ( V_2 , V_24 -> V_25 ) &
V_26 ;
}
static void F_15 ( unsigned long V_27 ,
unsigned long V_28 ,
T_1 * V_29 , T_1 * V_30 )
{
T_4 div ;
div = ( T_4 ) V_27 << V_31 ;
F_16 ( div , V_28 ) ;
* V_29 = div >> V_31 ;
* V_30 = div & ( ( 1 << V_31 ) - 1 ) ;
}
static long F_17 ( unsigned long V_28 ,
T_1 V_29 , T_1 V_30 , T_1 V_32 )
{
T_4 V_27 ;
if ( V_32 == 0 )
return 0 ;
V_27 = ( T_4 ) V_28 * ( ( V_29 << V_31 ) + V_30 ) ;
F_16 ( V_27 , V_32 ) ;
return V_27 >> V_31 ;
}
static long F_18 ( struct V_18 * V_19 , unsigned long V_27 ,
unsigned long * V_28 )
{
struct V_21 * V_22 = F_14 ( V_19 , struct V_21 , V_19 ) ;
const struct V_23 * V_24 = V_22 -> V_24 ;
T_1 V_29 , V_30 ;
V_27 = F_19 ( V_27 , V_24 -> V_33 , V_24 -> V_34 ) ;
F_15 ( V_27 , * V_28 , & V_29 , & V_30 ) ;
return F_17 ( * V_28 , V_29 , V_30 , 1 ) ;
}
static unsigned long F_20 ( struct V_18 * V_19 ,
unsigned long V_28 )
{
struct V_21 * V_22 = F_14 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
const struct V_23 * V_24 = V_22 -> V_24 ;
T_1 V_35 = F_3 ( V_2 , V_24 -> V_25 ) ;
T_1 V_29 , V_32 , V_30 ;
bool V_36 ;
if ( V_28 == 0 )
return 0 ;
V_30 = F_3 ( V_2 , V_24 -> V_37 ) & V_38 ;
V_29 = ( V_35 & V_39 ) >> V_40 ;
V_32 = ( V_35 & V_41 ) >> V_42 ;
V_36 = F_3 ( V_2 , V_24 -> V_43 + 4 ) &
V_24 -> V_44 -> V_45 ;
if ( V_36 )
V_29 *= 2 ;
return F_17 ( V_28 , V_29 , V_30 , V_32 ) ;
}
static void F_21 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_14 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
const struct V_23 * V_24 = V_22 -> V_24 ;
F_22 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_24 -> V_47 ,
F_3 ( V_2 , V_24 -> V_47 ) |
V_48 ) ;
F_1 ( V_2 , V_24 -> V_25 ,
F_3 ( V_2 , V_24 -> V_25 ) |
V_49 ) ;
F_23 ( & V_2 -> V_46 ) ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_21 * V_22 = F_14 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
const struct V_23 * V_24 = V_22 -> V_24 ;
T_5 V_50 ;
F_1 ( V_2 , V_24 -> V_25 ,
F_3 ( V_2 , V_24 -> V_25 ) &
~ V_49 ) ;
F_1 ( V_2 , V_24 -> V_47 ,
F_3 ( V_2 , V_24 -> V_47 ) & ~ V_48 ) ;
V_50 = F_25 ( F_26 () , V_51 ) ;
while ( ! ( F_3 ( V_2 , V_52 ) & V_24 -> V_53 ) ) {
if ( F_27 ( F_26 () , V_50 ) ) {
F_28 ( V_2 -> V_14 , L_12 ,
F_29 ( V_19 ) ) ;
return - V_54 ;
}
F_30 () ;
}
return 0 ;
}
static void
F_31 ( struct V_1 * V_2 , T_1 V_43 , T_1 * V_44 )
{
int V_55 ;
for ( V_55 = 3 ; V_55 >= 0 ; V_55 -- )
F_1 ( V_2 , V_43 + V_55 * 4 , V_44 [ V_55 ] ) ;
}
static int F_32 ( struct V_18 * V_19 ,
unsigned long V_27 , unsigned long V_28 )
{
struct V_21 * V_22 = F_14 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
const struct V_23 * V_24 = V_22 -> V_24 ;
bool V_56 , V_57 , V_58 ;
T_1 V_29 , V_30 , V_59 ;
T_1 V_44 [ 4 ] ;
int V_55 ;
if ( V_27 > V_24 -> V_60 ) {
V_57 = true ;
V_27 /= 2 ;
} else {
V_57 = false ;
}
F_15 ( V_27 , V_28 , & V_29 , & V_30 ) ;
for ( V_55 = 3 ; V_55 >= 0 ; V_55 -- )
V_44 [ V_55 ] = F_3 ( V_2 , V_24 -> V_43 + V_55 * 4 ) ;
V_56 = V_44 [ 1 ] & V_24 -> V_44 -> V_45 ;
V_44 [ 0 ] &= ~ V_24 -> V_44 -> V_61 ;
V_44 [ 0 ] |= V_24 -> V_44 -> V_62 ;
V_44 [ 1 ] &= ~ V_24 -> V_44 -> V_63 ;
V_44 [ 1 ] |= V_24 -> V_44 -> V_64 ;
V_44 [ 3 ] &= ~ V_24 -> V_44 -> V_65 ;
V_44 [ 3 ] |= V_24 -> V_44 -> V_66 ;
if ( V_56 && ! V_57 ) {
V_44 [ 1 ] &= ~ V_24 -> V_44 -> V_45 ;
V_58 = true ;
} else if ( ! V_56 && V_57 ) {
V_44 [ 1 ] |= V_24 -> V_44 -> V_45 ;
V_58 = false ;
} else {
V_58 = true ;
}
F_1 ( V_2 , V_67 ,
F_3 ( V_2 , V_67 ) |
V_24 -> V_68 ) ;
if ( V_58 )
F_31 ( V_2 , V_24 -> V_43 , V_44 ) ;
F_1 ( V_2 , V_24 -> V_37 , V_30 ) ;
V_59 = F_3 ( V_2 , V_24 -> V_25 ) ;
V_59 &= ~ V_39 ;
V_59 |= V_29 << V_40 ;
V_59 &= ~ V_41 ;
V_59 |= 1 << V_42 ;
F_1 ( V_2 , V_24 -> V_25 , V_59 ) ;
if ( ! V_58 )
F_31 ( V_2 , V_24 -> V_43 , V_44 ) ;
return 0 ;
}
static int F_33 ( struct V_18 * V_19 ,
struct V_10 * V_10 )
{
struct V_21 * V_22 = F_14 ( V_19 , struct V_21 , V_19 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
const struct V_23 * V_24 = V_22 -> V_24 ;
struct V_8 * V_6 ;
V_6 = F_6 ( V_2 -> V_14 , 7 * sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_6 [ 0 ] . V_69 = L_13 ;
V_6 [ 0 ] . V_70 = V_24 -> V_47 ;
V_6 [ 1 ] . V_69 = L_14 ;
V_6 [ 1 ] . V_70 = V_24 -> V_25 ;
V_6 [ 2 ] . V_69 = L_15 ;
V_6 [ 2 ] . V_70 = V_24 -> V_37 ;
V_6 [ 3 ] . V_69 = L_16 ;
V_6 [ 3 ] . V_70 = V_24 -> V_43 + 0 * 4 ;
V_6 [ 4 ] . V_69 = L_17 ;
V_6 [ 4 ] . V_70 = V_24 -> V_43 + 1 * 4 ;
V_6 [ 5 ] . V_69 = L_18 ;
V_6 [ 5 ] . V_70 = V_24 -> V_43 + 2 * 4 ;
V_6 [ 6 ] . V_69 = L_19 ;
V_6 [ 6 ] . V_70 = V_24 -> V_43 + 3 * 4 ;
return F_5 ( V_2 , 0 , V_6 , 7 , V_10 ) ;
}
static struct V_71 *
F_34 ( struct V_18 * V_19 )
{
return F_14 ( V_19 , struct V_71 , div . V_19 ) ;
}
static int F_35 ( struct V_18 * V_19 )
{
struct V_71 * V_72 = F_34 ( V_19 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
const struct V_73 * V_24 = V_72 -> V_24 ;
return ! ( F_3 ( V_2 , V_24 -> V_74 ) & V_75 ) ;
}
static long F_36 ( struct V_18 * V_19 ,
unsigned long V_27 ,
unsigned long * V_28 )
{
return V_76 . V_77 ( V_19 , V_27 , V_28 ) ;
}
static unsigned long F_37 ( struct V_18 * V_19 ,
unsigned long V_28 )
{
return V_76 . V_78 ( V_19 , V_28 ) ;
}
static void F_38 ( struct V_18 * V_19 )
{
struct V_71 * V_72 = F_34 ( V_19 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
const struct V_73 * V_24 = V_72 -> V_24 ;
F_22 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_24 -> V_79 ,
( F_3 ( V_2 , V_24 -> V_79 ) &
~ V_24 -> V_80 ) | V_24 -> V_81 ) ;
F_1 ( V_2 , V_24 -> V_74 , V_75 ) ;
F_23 ( & V_2 -> V_46 ) ;
}
static int F_39 ( struct V_18 * V_19 )
{
struct V_71 * V_72 = F_34 ( V_19 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
const struct V_73 * V_24 = V_72 -> V_24 ;
F_22 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_24 -> V_74 ,
F_3 ( V_2 , V_24 -> V_74 ) &
~ V_75 ) ;
F_1 ( V_2 , V_24 -> V_79 ,
F_3 ( V_2 , V_24 -> V_79 ) & ~ V_24 -> V_81 ) ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_40 ( struct V_18 * V_19 ,
unsigned long V_27 ,
unsigned long V_28 )
{
struct V_71 * V_72 = F_34 ( V_19 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
const struct V_73 * V_24 = V_72 -> V_24 ;
T_1 V_82 , div , V_83 = 1 << V_84 ;
div = F_41 ( V_28 , V_27 ) ;
div = F_42 ( div , V_83 ) ;
if ( div == V_83 )
div = 0 ;
F_1 ( V_2 , V_24 -> V_74 , div ) ;
V_82 = F_3 ( V_2 , V_24 -> V_79 ) ;
F_1 ( V_2 , V_24 -> V_79 , V_82 | V_24 -> V_80 ) ;
F_1 ( V_2 , V_24 -> V_79 , V_82 & ~ V_24 -> V_80 ) ;
return 0 ;
}
static int F_43 ( struct V_18 * V_19 ,
struct V_10 * V_10 )
{
struct V_71 * V_72 = F_34 ( V_19 ) ;
struct V_1 * V_2 = V_72 -> V_2 ;
const struct V_73 * V_24 = V_72 -> V_24 ;
struct V_8 * V_6 ;
V_6 = F_6 ( V_2 -> V_14 , 7 * sizeof( * V_6 ) , V_15 ) ;
if ( ! V_6 )
return - V_16 ;
V_6 [ 0 ] . V_69 = L_20 ;
V_6 [ 0 ] . V_70 = V_24 -> V_79 ;
V_6 [ 1 ] . V_69 = L_21 ;
V_6 [ 1 ] . V_70 = V_24 -> V_74 ;
return F_5 ( V_2 , 0 , V_6 , 2 , V_10 ) ;
}
static struct V_85 * F_44 ( struct V_18 * V_19 )
{
return F_14 ( V_19 , struct V_85 , V_19 ) ;
}
static int F_45 ( struct V_18 * V_19 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
return ( F_3 ( V_2 , V_24 -> V_87 ) & V_88 ) != 0 ;
}
static T_1 F_46 ( struct V_18 * V_19 ,
unsigned long V_27 ,
unsigned long V_28 ,
bool V_89 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
const struct V_86 * V_24 = clock -> V_24 ;
T_1 V_90 =
F_47 ( V_91 - V_24 -> V_92 , 0 ) >> 1 ;
T_4 V_93 = ( T_4 ) V_28 << V_91 ;
T_4 V_94 ;
T_1 div , V_95 , V_96 ;
V_94 = F_16 ( V_93 , V_27 ) ;
div = V_93 ;
if ( V_89 && ( ( div & V_90 ) != 0 || V_94 != 0 ) )
div += V_90 + 1 ;
div &= ~ V_90 ;
if ( V_24 -> V_97 ) {
V_95 = 2 << V_91 ;
V_96 = ( F_48 ( V_24 -> V_98 ) - 1 ) << V_91 ;
} else {
V_95 = 1 << V_91 ;
V_96 = F_47 ( V_24 -> V_98 + V_91 - 1 ,
V_91 - V_24 -> V_92 ) ;
}
div = F_49 ( T_1 , div , V_95 ) ;
div = F_50 ( T_1 , div , V_96 ) ;
return div ;
}
static long F_51 ( struct V_85 * clock ,
unsigned long V_28 ,
T_1 div )
{
const struct V_86 * V_24 = clock -> V_24 ;
T_4 V_93 ;
div >>= V_91 - V_24 -> V_92 ;
div &= ( 1 << ( V_24 -> V_98 + V_24 -> V_92 ) ) - 1 ;
if ( div == 0 )
return 0 ;
V_93 = ( T_4 ) V_28 << V_24 -> V_92 ;
F_16 ( V_93 , div ) ;
return V_93 ;
}
static unsigned long F_52 ( struct V_18 * V_19 ,
unsigned long V_28 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
T_1 div = F_3 ( V_2 , V_24 -> V_99 ) ;
return F_51 ( clock , V_28 , div ) ;
}
static void F_53 ( struct V_85 * clock )
{
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
T_5 V_50 = F_25 ( F_26 () , V_51 ) ;
while ( F_3 ( V_2 , V_24 -> V_87 ) & V_100 ) {
if ( F_27 ( F_26 () , V_50 ) ) {
F_28 ( V_2 -> V_14 , L_12 ,
F_29 ( & clock -> V_19 ) ) ;
return;
}
F_30 () ;
}
}
static void F_54 ( struct V_18 * V_19 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
F_22 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_24 -> V_87 ,
F_3 ( V_2 , V_24 -> V_87 ) & ~ V_88 ) ;
F_23 ( & V_2 -> V_46 ) ;
F_53 ( clock ) ;
}
static int F_55 ( struct V_18 * V_19 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
F_22 ( & V_2 -> V_46 ) ;
F_1 ( V_2 , V_24 -> V_87 ,
F_3 ( V_2 , V_24 -> V_87 ) |
V_88 |
V_101 ) ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static int F_56 ( struct V_18 * V_19 ,
unsigned long V_27 , unsigned long V_28 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
T_1 div = F_46 ( V_19 , V_27 , V_28 , false ) ;
T_1 V_102 ;
F_22 ( & V_2 -> V_46 ) ;
V_102 = F_3 ( V_2 , V_24 -> V_87 ) & ~ V_103 ;
V_102 |= ( div & V_104 ) ? V_103 : 0 ;
F_1 ( V_2 , V_24 -> V_87 , V_102 ) ;
F_1 ( V_2 , V_24 -> V_99 , div ) ;
F_23 ( & V_2 -> V_46 ) ;
return 0 ;
}
static bool
F_57 ( struct V_18 * V_19 )
{
if ( ! V_19 )
return false ;
return strncmp ( F_29 ( V_19 ) , L_22 , 4 ) == 0 ;
}
static int F_58 ( struct V_18 * V_19 ,
struct V_105 * V_106 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_18 * V_107 , * V_108 = NULL ;
bool V_109 ;
unsigned long V_27 , V_110 = 0 ;
unsigned long V_111 , V_112 = 0 ;
T_2 V_55 ;
T_1 div ;
V_109 = F_57 ( F_59 ( V_19 ) ) ;
for ( V_55 = 0 ; V_55 < F_60 ( V_19 ) ; ++ V_55 ) {
V_107 = F_61 ( V_19 , V_55 ) ;
if ( ! V_107 )
continue;
if ( F_57 ( V_107 ) && ! V_109 )
continue;
V_111 = F_62 ( V_107 ) ;
div = F_46 ( V_19 , V_106 -> V_27 , V_111 , true ) ;
V_27 = F_51 ( clock , V_111 , div ) ;
if ( V_27 > V_110 && V_27 <= V_106 -> V_27 ) {
V_108 = V_107 ;
V_112 = V_111 ;
V_110 = V_27 ;
}
}
if ( ! V_108 )
return - V_113 ;
V_106 -> V_114 = V_108 ;
V_106 -> V_115 = V_112 ;
V_106 -> V_27 = V_110 ;
return 0 ;
}
static int F_63 ( struct V_18 * V_19 , T_6 V_116 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
T_6 V_117 = ( V_116 << V_118 ) & V_119 ;
F_1 ( V_2 , V_24 -> V_87 , V_117 ) ;
return 0 ;
}
static T_6 F_64 ( struct V_18 * V_19 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
T_1 V_117 = F_3 ( V_2 , V_24 -> V_87 ) ;
return ( V_117 & V_119 ) >> V_118 ;
}
static int F_65 ( struct V_18 * V_19 ,
struct V_10 * V_10 )
{
struct V_85 * clock = F_44 ( V_19 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_86 * V_24 = clock -> V_24 ;
return F_5 (
V_2 , V_24 -> V_87 ,
V_120 ,
F_66 ( V_120 ) ,
V_10 ) ;
}
static int F_67 ( struct V_18 * V_19 )
{
return true ;
}
static struct V_18 * F_68 ( struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_21 * V_22 ;
struct V_121 V_122 ;
int V_20 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_123 = & V_2 -> V_124 ;
V_122 . V_125 = 1 ;
V_122 . V_69 = V_24 -> V_69 ;
V_122 . V_126 = & V_127 ;
V_122 . V_128 = V_129 ;
V_22 = F_69 ( sizeof( * V_22 ) , V_15 ) ;
if ( ! V_22 )
return NULL ;
V_22 -> V_2 = V_2 ;
V_22 -> V_24 = V_24 ;
V_22 -> V_19 . V_122 = & V_122 ;
V_20 = F_70 ( V_2 -> V_14 , & V_22 -> V_19 ) ;
if ( V_20 )
return NULL ;
return & V_22 -> V_19 ;
}
static struct V_18 *
F_71 ( struct V_1 * V_2 ,
const struct V_73 * V_24 )
{
struct V_71 * V_72 ;
struct V_121 V_122 ;
const char * V_130 ;
int V_20 ;
if ( V_24 -> V_131 != 1 ) {
V_130 = F_72 ( V_2 -> V_14 , V_15 ,
L_23 , V_24 -> V_69 ) ;
if ( ! V_130 )
return NULL ;
} else {
V_130 = V_24 -> V_69 ;
}
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_123 = & V_24 -> V_132 ;
V_122 . V_125 = 1 ;
V_122 . V_69 = V_130 ;
V_122 . V_126 = & V_133 ;
V_122 . V_128 = V_134 | V_129 ;
V_72 = F_6 ( V_2 -> V_14 , sizeof( * V_72 ) , V_15 ) ;
if ( ! V_72 )
return NULL ;
V_72 -> div . V_3 = V_2 -> V_6 + V_24 -> V_74 ;
V_72 -> div . V_135 = V_136 ;
V_72 -> div . V_137 = V_84 ;
V_72 -> div . V_128 = V_138 ;
V_72 -> div . V_139 = & V_2 -> V_46 ;
V_72 -> div . V_19 . V_122 = & V_122 ;
V_72 -> div . V_140 = NULL ;
V_72 -> V_2 = V_2 ;
V_72 -> V_24 = V_24 ;
V_20 = F_70 ( V_2 -> V_14 , & V_72 -> div . V_19 ) ;
if ( V_20 )
return F_73 ( V_20 ) ;
if ( V_24 -> V_131 != 1 ) {
return F_74 ( V_2 -> V_14 , V_24 -> V_69 ,
V_130 ,
V_134 ,
1 ,
V_24 -> V_131 ) ;
}
return & V_72 -> div . V_19 ;
}
static struct V_18 * F_75 ( struct V_1 * V_2 ,
const struct V_86 * V_24 )
{
struct V_85 * clock ;
struct V_121 V_122 ;
const char * V_141 [ 1 << V_142 ] ;
T_2 V_55 ;
int V_20 ;
for ( V_55 = 0 ; V_55 < V_24 -> V_143 ; V_55 ++ ) {
if ( strcmp ( V_24 -> V_141 [ V_55 ] , L_24 ) == 0 )
V_141 [ V_55 ] = V_2 -> V_124 ;
else
V_141 [ V_55 ] = V_24 -> V_141 [ V_55 ] ;
}
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
V_122 . V_123 = V_141 ;
V_122 . V_125 = V_24 -> V_143 ;
V_122 . V_69 = V_24 -> V_69 ;
V_122 . V_128 = V_24 -> V_128 | V_129 ;
if ( V_24 -> V_144 ) {
V_122 . V_126 = & V_145 ;
} else {
V_122 . V_126 = & V_146 ;
V_122 . V_128 |= V_147 | V_148 ;
if ( ! ( F_3 ( V_2 , V_24 -> V_87 ) & V_88 ) )
V_122 . V_128 &= ~ V_149 ;
}
clock = F_6 ( V_2 -> V_14 , sizeof( * clock ) , V_15 ) ;
if ( ! clock )
return NULL ;
clock -> V_2 = V_2 ;
clock -> V_24 = V_24 ;
clock -> V_19 . V_122 = & V_122 ;
V_20 = F_70 ( V_2 -> V_14 , & clock -> V_19 ) ;
if ( V_20 )
return F_73 ( V_20 ) ;
return & clock -> V_19 ;
}
static struct V_150 * F_76 ( struct V_1 * V_2 ,
const struct V_151 * V_24 )
{
return F_77 ( V_2 -> V_14 , V_24 -> V_69 , V_24 -> V_107 ,
V_129 | V_147 ,
V_2 -> V_6 + V_24 -> V_87 ,
V_152 , 0 , & V_2 -> V_46 ) ;
}
static int F_78 ( struct V_150 * V_153 )
{
struct V_150 * V_107 = F_79 ( V_153 ) ;
if ( F_10 ( V_107 ) )
return F_80 ( V_107 ) ;
return F_81 ( V_107 ) ;
}
static int F_82 ( struct V_154 * V_155 )
{
struct V_156 * V_14 = & V_155 -> V_14 ;
struct V_18 * * V_157 ;
struct V_1 * V_2 ;
struct V_158 * V_159 ;
const struct V_160 * V_161 ;
const T_2 V_162 = F_66 ( V_163 ) ;
T_2 V_55 ;
int V_20 ;
V_2 = F_6 ( V_14 , sizeof( * V_2 ) +
sizeof( * V_2 -> V_164 . V_157 ) * V_162 ,
V_15 ) ;
if ( ! V_2 )
return - V_16 ;
F_83 ( & V_2 -> V_46 ) ;
V_2 -> V_14 = V_14 ;
V_159 = F_84 ( V_155 , V_165 , 0 ) ;
V_2 -> V_6 = F_85 ( V_14 , V_159 ) ;
if ( F_10 ( V_2 -> V_6 ) )
return F_80 ( V_2 -> V_6 ) ;
V_2 -> V_124 = F_86 ( V_14 -> V_166 , 0 ) ;
if ( ! V_2 -> V_124 )
return - V_167 ;
F_87 ( V_155 , V_2 ) ;
V_2 -> V_164 . V_168 = V_162 ;
V_157 = V_2 -> V_164 . V_157 ;
for ( V_55 = 0 ; V_55 < V_162 ; V_55 ++ ) {
V_161 = & V_163 [ V_55 ] ;
if ( V_161 -> V_169 && V_161 -> V_24 )
V_157 [ V_55 ] = V_161 -> V_169 ( V_2 , V_161 -> V_24 ) ;
}
V_20 = F_78 ( V_157 [ V_170 ] -> V_150 ) ;
if ( V_20 )
return V_20 ;
return F_88 ( V_14 -> V_166 , V_171 ,
& V_2 -> V_164 ) ;
}
