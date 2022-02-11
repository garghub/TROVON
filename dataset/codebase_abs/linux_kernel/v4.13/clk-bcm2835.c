static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
F_2 ( V_5 | V_4 , V_2 -> V_6 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_4 ( V_2 -> V_6 + V_3 ) ;
}
static unsigned long F_5 ( struct V_1 * V_2 ,
T_1 V_7 )
{
T_1 V_8 = 19200 ;
T_1 V_9 ;
T_2 V_10 ;
F_6 ( & V_2 -> V_11 ) ;
F_1 ( V_2 , V_12 , V_13 ) ;
F_1 ( V_2 , V_12 ,
( V_7 & V_14 ) |
( V_7 >> V_15 ) << V_16 ) ;
F_1 ( V_2 , V_17 , V_8 ) ;
F_7 ( 1 ) ;
V_10 = F_8 ( F_9 () , V_18 ) ;
while ( F_3 ( V_2 , V_17 ) ) {
if ( F_10 ( F_9 () , V_10 ) ) {
F_11 ( V_2 -> V_19 , L_1 ) ;
V_9 = 0 ;
goto V_20;
}
F_12 () ;
}
V_10 = F_8 ( F_9 () , V_18 ) ;
while ( F_3 ( V_2 , V_12 ) & V_21 ) {
if ( F_10 ( F_9 () , V_10 ) ) {
F_11 ( V_2 -> V_19 , L_2 ) ;
V_9 = 0 ;
goto V_20;
}
F_12 () ;
}
V_9 = F_3 ( V_2 , V_22 ) ;
F_1 ( V_2 , V_12 , 0 ) ;
V_20:
F_13 ( & V_2 -> V_11 ) ;
return V_9 * 1000 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_23 ,
struct V_24 * V_6 , T_3 V_25 ,
struct V_26 * V_26 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
V_29 = F_15 ( V_2 -> V_19 , sizeof( * V_29 ) , V_30 ) ;
if ( ! V_29 )
return - V_31 ;
V_29 -> V_6 = V_6 ;
V_29 -> V_25 = V_25 ;
V_29 -> V_23 = V_2 -> V_6 + V_23 ;
V_27 = F_16 ( L_3 , V_32 , V_26 ,
V_29 ) ;
return V_27 ? 0 : - V_31 ;
}
void T_4 F_17 ( void )
{
struct V_33 * V_34 ;
int V_35 ;
V_34 = F_18 ( NULL , L_4 , NULL , 0 , 126000000 ) ;
if ( F_19 ( V_34 ) )
F_20 ( L_5 ) ;
V_34 = F_18 ( NULL , L_6 , NULL , 0 , 3000000 ) ;
if ( F_19 ( V_34 ) )
F_20 ( L_7 ) ;
V_35 = F_21 ( V_34 , NULL , L_8 ) ;
if ( V_35 )
F_20 ( L_9 ) ;
V_34 = F_18 ( NULL , L_10 , NULL , 0 , 125000000 ) ;
if ( F_19 ( V_34 ) )
F_20 ( L_11 ) ;
V_35 = F_21 ( V_34 , NULL , L_12 ) ;
if ( V_35 )
F_20 ( L_13 ) ;
}
static int F_22 ( struct V_33 * V_34 )
{
struct V_36 * V_37 = F_23 ( V_34 , struct V_36 , V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
const struct V_38 * V_39 = V_37 -> V_39 ;
return F_3 ( V_2 , V_39 -> V_40 ) &
V_41 ;
}
static void F_24 ( unsigned long V_42 ,
unsigned long V_43 ,
T_1 * V_44 , T_1 * V_45 )
{
T_5 div ;
div = ( T_5 ) V_42 << V_46 ;
F_25 ( div , V_43 ) ;
* V_44 = div >> V_46 ;
* V_45 = div & ( ( 1 << V_46 ) - 1 ) ;
}
static long F_26 ( unsigned long V_43 ,
T_1 V_44 , T_1 V_45 , T_1 V_47 )
{
T_5 V_42 ;
if ( V_47 == 0 )
return 0 ;
V_42 = ( T_5 ) V_43 * ( ( V_44 << V_46 ) + V_45 ) ;
F_25 ( V_42 , V_47 ) ;
return V_42 >> V_46 ;
}
static long F_27 ( struct V_33 * V_34 , unsigned long V_42 ,
unsigned long * V_43 )
{
struct V_36 * V_37 = F_23 ( V_34 , struct V_36 , V_34 ) ;
const struct V_38 * V_39 = V_37 -> V_39 ;
T_1 V_44 , V_45 ;
V_42 = F_28 ( V_42 , V_39 -> V_48 , V_39 -> V_49 ) ;
F_24 ( V_42 , * V_43 , & V_44 , & V_45 ) ;
return F_26 ( * V_43 , V_44 , V_45 , 1 ) ;
}
static unsigned long F_29 ( struct V_33 * V_34 ,
unsigned long V_43 )
{
struct V_36 * V_37 = F_23 ( V_34 , struct V_36 , V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
const struct V_38 * V_39 = V_37 -> V_39 ;
T_1 V_50 = F_3 ( V_2 , V_39 -> V_40 ) ;
T_1 V_44 , V_47 , V_45 ;
bool V_51 ;
if ( V_43 == 0 )
return 0 ;
V_45 = F_3 ( V_2 , V_39 -> V_52 ) & V_53 ;
V_44 = ( V_50 & V_54 ) >> V_55 ;
V_47 = ( V_50 & V_56 ) >> V_57 ;
V_51 = F_3 ( V_2 , V_39 -> V_58 + 4 ) &
V_39 -> V_59 -> V_60 ;
if ( V_51 ) {
V_44 *= 2 ;
V_45 *= 2 ;
}
return F_26 ( V_43 , V_44 , V_45 , V_47 ) ;
}
static void F_30 ( struct V_33 * V_34 )
{
struct V_36 * V_37 = F_23 ( V_34 , struct V_36 , V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
const struct V_38 * V_39 = V_37 -> V_39 ;
F_6 ( & V_2 -> V_11 ) ;
F_1 ( V_2 , V_39 -> V_61 ,
F_3 ( V_2 , V_39 -> V_61 ) |
V_62 ) ;
F_1 ( V_2 , V_39 -> V_40 ,
F_3 ( V_2 , V_39 -> V_40 ) |
V_63 ) ;
F_13 ( & V_2 -> V_11 ) ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_36 * V_37 = F_23 ( V_34 , struct V_36 , V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
const struct V_38 * V_39 = V_37 -> V_39 ;
T_2 V_10 ;
F_1 ( V_2 , V_39 -> V_40 ,
F_3 ( V_2 , V_39 -> V_40 ) &
~ V_63 ) ;
F_1 ( V_2 , V_39 -> V_61 ,
F_3 ( V_2 , V_39 -> V_61 ) & ~ V_62 ) ;
V_10 = F_8 ( F_9 () , V_18 ) ;
while ( ! ( F_3 ( V_2 , V_64 ) & V_39 -> V_65 ) ) {
if ( F_10 ( F_9 () , V_10 ) ) {
F_11 ( V_2 -> V_19 , L_14 ,
F_32 ( V_34 ) ) ;
return - V_66 ;
}
F_12 () ;
}
return 0 ;
}
static void
F_33 ( struct V_1 * V_2 , T_1 V_58 , T_1 * V_59 )
{
int V_67 ;
for ( V_67 = 3 ; V_67 >= 0 ; V_67 -- )
F_1 ( V_2 , V_58 + V_67 * 4 , V_59 [ V_67 ] ) ;
}
static int F_34 ( struct V_33 * V_34 ,
unsigned long V_42 , unsigned long V_43 )
{
struct V_36 * V_37 = F_23 ( V_34 , struct V_36 , V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
const struct V_38 * V_39 = V_37 -> V_39 ;
bool V_68 , V_69 , V_70 ;
T_1 V_44 , V_45 , V_71 ;
T_1 V_59 [ 4 ] ;
int V_67 ;
if ( V_42 > V_39 -> V_72 ) {
V_69 = true ;
V_42 /= 2 ;
} else {
V_69 = false ;
}
F_24 ( V_42 , V_43 , & V_44 , & V_45 ) ;
for ( V_67 = 3 ; V_67 >= 0 ; V_67 -- )
V_59 [ V_67 ] = F_3 ( V_2 , V_39 -> V_58 + V_67 * 4 ) ;
V_68 = V_59 [ 1 ] & V_39 -> V_59 -> V_60 ;
V_59 [ 0 ] &= ~ V_39 -> V_59 -> V_73 ;
V_59 [ 0 ] |= V_39 -> V_59 -> V_74 ;
V_59 [ 1 ] &= ~ V_39 -> V_59 -> V_75 ;
V_59 [ 1 ] |= V_39 -> V_59 -> V_76 ;
V_59 [ 3 ] &= ~ V_39 -> V_59 -> V_77 ;
V_59 [ 3 ] |= V_39 -> V_59 -> V_78 ;
if ( V_68 && ! V_69 ) {
V_59 [ 1 ] &= ~ V_39 -> V_59 -> V_60 ;
V_70 = true ;
} else if ( ! V_68 && V_69 ) {
V_59 [ 1 ] |= V_39 -> V_59 -> V_60 ;
V_70 = false ;
} else {
V_70 = true ;
}
F_1 ( V_2 , V_79 ,
F_3 ( V_2 , V_79 ) |
V_39 -> V_80 ) ;
if ( V_70 )
F_33 ( V_2 , V_39 -> V_58 , V_59 ) ;
F_1 ( V_2 , V_39 -> V_52 , V_45 ) ;
V_71 = F_3 ( V_2 , V_39 -> V_40 ) ;
V_71 &= ~ V_54 ;
V_71 |= V_44 << V_55 ;
V_71 &= ~ V_56 ;
V_71 |= 1 << V_57 ;
F_1 ( V_2 , V_39 -> V_40 , V_71 ) ;
if ( ! V_70 )
F_33 ( V_2 , V_39 -> V_58 , V_59 ) ;
return 0 ;
}
static int F_35 ( struct V_33 * V_34 ,
struct V_26 * V_26 )
{
struct V_36 * V_37 = F_23 ( V_34 , struct V_36 , V_34 ) ;
struct V_1 * V_2 = V_37 -> V_2 ;
const struct V_38 * V_39 = V_37 -> V_39 ;
struct V_24 * V_6 ;
V_6 = F_15 ( V_2 -> V_19 , 7 * sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 )
return - V_31 ;
V_6 [ 0 ] . V_81 = L_15 ;
V_6 [ 0 ] . V_82 = V_39 -> V_61 ;
V_6 [ 1 ] . V_81 = L_16 ;
V_6 [ 1 ] . V_82 = V_39 -> V_40 ;
V_6 [ 2 ] . V_81 = L_17 ;
V_6 [ 2 ] . V_82 = V_39 -> V_52 ;
V_6 [ 3 ] . V_81 = L_18 ;
V_6 [ 3 ] . V_82 = V_39 -> V_58 + 0 * 4 ;
V_6 [ 4 ] . V_81 = L_19 ;
V_6 [ 4 ] . V_82 = V_39 -> V_58 + 1 * 4 ;
V_6 [ 5 ] . V_81 = L_20 ;
V_6 [ 5 ] . V_82 = V_39 -> V_58 + 2 * 4 ;
V_6 [ 6 ] . V_81 = L_21 ;
V_6 [ 6 ] . V_82 = V_39 -> V_58 + 3 * 4 ;
return F_14 ( V_2 , 0 , V_6 , 7 , V_26 ) ;
}
static struct V_83 *
F_36 ( struct V_33 * V_34 )
{
return F_23 ( V_34 , struct V_83 , div . V_34 ) ;
}
static int F_37 ( struct V_33 * V_34 )
{
struct V_83 * V_84 = F_36 ( V_34 ) ;
struct V_1 * V_2 = V_84 -> V_2 ;
const struct V_85 * V_39 = V_84 -> V_39 ;
return ! ( F_3 ( V_2 , V_39 -> V_86 ) & V_87 ) ;
}
static long F_38 ( struct V_33 * V_34 ,
unsigned long V_42 ,
unsigned long * V_43 )
{
return V_88 . V_89 ( V_34 , V_42 , V_43 ) ;
}
static unsigned long F_39 ( struct V_33 * V_34 ,
unsigned long V_43 )
{
return V_88 . V_90 ( V_34 , V_43 ) ;
}
static void F_40 ( struct V_33 * V_34 )
{
struct V_83 * V_84 = F_36 ( V_34 ) ;
struct V_1 * V_2 = V_84 -> V_2 ;
const struct V_85 * V_39 = V_84 -> V_39 ;
F_6 ( & V_2 -> V_11 ) ;
F_1 ( V_2 , V_39 -> V_91 ,
( F_3 ( V_2 , V_39 -> V_91 ) &
~ V_39 -> V_92 ) | V_39 -> V_93 ) ;
F_1 ( V_2 , V_39 -> V_86 ,
F_3 ( V_2 , V_39 -> V_86 ) |
V_87 ) ;
F_13 ( & V_2 -> V_11 ) ;
}
static int F_41 ( struct V_33 * V_34 )
{
struct V_83 * V_84 = F_36 ( V_34 ) ;
struct V_1 * V_2 = V_84 -> V_2 ;
const struct V_85 * V_39 = V_84 -> V_39 ;
F_6 ( & V_2 -> V_11 ) ;
F_1 ( V_2 , V_39 -> V_86 ,
F_3 ( V_2 , V_39 -> V_86 ) &
~ V_87 ) ;
F_1 ( V_2 , V_39 -> V_91 ,
F_3 ( V_2 , V_39 -> V_91 ) & ~ V_39 -> V_93 ) ;
F_13 ( & V_2 -> V_11 ) ;
return 0 ;
}
static int F_42 ( struct V_33 * V_34 ,
unsigned long V_42 ,
unsigned long V_43 )
{
struct V_83 * V_84 = F_36 ( V_34 ) ;
struct V_1 * V_2 = V_84 -> V_2 ;
const struct V_85 * V_39 = V_84 -> V_39 ;
T_1 V_94 , div , V_95 = 1 << V_96 ;
div = F_43 ( V_43 , V_42 ) ;
div = F_44 ( div , V_95 ) ;
if ( div == V_95 )
div = 0 ;
F_1 ( V_2 , V_39 -> V_86 , div ) ;
V_94 = F_3 ( V_2 , V_39 -> V_91 ) ;
F_1 ( V_2 , V_39 -> V_91 , V_94 | V_39 -> V_92 ) ;
F_1 ( V_2 , V_39 -> V_91 , V_94 & ~ V_39 -> V_92 ) ;
return 0 ;
}
static int F_45 ( struct V_33 * V_34 ,
struct V_26 * V_26 )
{
struct V_83 * V_84 = F_36 ( V_34 ) ;
struct V_1 * V_2 = V_84 -> V_2 ;
const struct V_85 * V_39 = V_84 -> V_39 ;
struct V_24 * V_6 ;
V_6 = F_15 ( V_2 -> V_19 , 7 * sizeof( * V_6 ) , V_30 ) ;
if ( ! V_6 )
return - V_31 ;
V_6 [ 0 ] . V_81 = L_22 ;
V_6 [ 0 ] . V_82 = V_39 -> V_91 ;
V_6 [ 1 ] . V_81 = L_23 ;
V_6 [ 1 ] . V_82 = V_39 -> V_86 ;
return F_14 ( V_2 , 0 , V_6 , 2 , V_26 ) ;
}
static struct V_97 * F_46 ( struct V_33 * V_34 )
{
return F_23 ( V_34 , struct V_97 , V_34 ) ;
}
static int F_47 ( struct V_33 * V_34 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
return ( F_3 ( V_2 , V_39 -> V_99 ) & V_100 ) != 0 ;
}
static T_1 F_48 ( struct V_33 * V_34 ,
unsigned long V_42 ,
unsigned long V_43 ,
bool V_101 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
const struct V_98 * V_39 = clock -> V_39 ;
T_1 V_102 =
F_49 ( V_103 - V_39 -> V_104 , 0 ) >> 1 ;
T_5 V_105 = ( T_5 ) V_43 << V_103 ;
T_5 V_106 ;
T_1 div , V_107 , V_108 ;
V_106 = F_25 ( V_105 , V_42 ) ;
div = V_105 ;
if ( V_101 && ( ( div & V_102 ) != 0 || V_106 != 0 ) )
div += V_102 + 1 ;
div &= ~ V_102 ;
if ( V_39 -> V_109 ) {
V_107 = 2 << V_103 ;
V_108 = ( F_50 ( V_39 -> V_110 ) - 1 ) << V_103 ;
} else {
V_107 = 1 << V_103 ;
V_108 = F_49 ( V_39 -> V_110 + V_103 - 1 ,
V_103 - V_39 -> V_104 ) ;
}
div = F_51 ( T_1 , div , V_107 ) ;
div = F_52 ( T_1 , div , V_108 ) ;
return div ;
}
static long F_53 ( struct V_97 * clock ,
unsigned long V_43 ,
T_1 div )
{
const struct V_98 * V_39 = clock -> V_39 ;
T_5 V_105 ;
if ( V_39 -> V_110 == 0 && V_39 -> V_104 == 0 )
return V_43 ;
div >>= V_103 - V_39 -> V_104 ;
div &= ( 1 << ( V_39 -> V_110 + V_39 -> V_104 ) ) - 1 ;
if ( div == 0 )
return 0 ;
V_105 = ( T_5 ) V_43 << V_39 -> V_104 ;
F_25 ( V_105 , div ) ;
return V_105 ;
}
static unsigned long F_54 ( struct V_33 * V_34 ,
unsigned long V_43 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
T_1 div ;
if ( V_39 -> V_110 == 0 && V_39 -> V_104 == 0 )
return V_43 ;
div = F_3 ( V_2 , V_39 -> V_111 ) ;
return F_53 ( clock , V_43 , div ) ;
}
static void F_55 ( struct V_97 * clock )
{
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
T_2 V_10 = F_8 ( F_9 () , V_18 ) ;
while ( F_3 ( V_2 , V_39 -> V_99 ) & V_21 ) {
if ( F_10 ( F_9 () , V_10 ) ) {
F_11 ( V_2 -> V_19 , L_14 ,
F_32 ( & clock -> V_34 ) ) ;
return;
}
F_12 () ;
}
}
static void F_56 ( struct V_33 * V_34 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
F_6 ( & V_2 -> V_11 ) ;
F_1 ( V_2 , V_39 -> V_99 ,
F_3 ( V_2 , V_39 -> V_99 ) & ~ V_100 ) ;
F_13 ( & V_2 -> V_11 ) ;
F_55 ( clock ) ;
}
static int F_57 ( struct V_33 * V_34 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
F_6 ( & V_2 -> V_11 ) ;
F_1 ( V_2 , V_39 -> V_99 ,
F_3 ( V_2 , V_39 -> V_99 ) |
V_100 |
V_112 ) ;
F_13 ( & V_2 -> V_11 ) ;
if ( V_39 -> V_7 && false ) {
F_58 ( V_2 -> V_19 ,
L_24 ,
V_39 -> V_81 ,
F_59 ( V_34 ) ,
F_5 ( V_2 , V_39 -> V_7 ) ) ;
}
return 0 ;
}
static int F_60 ( struct V_33 * V_34 ,
unsigned long V_42 , unsigned long V_43 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
T_1 div = F_48 ( V_34 , V_42 , V_43 , false ) ;
T_1 V_113 ;
F_6 ( & V_2 -> V_11 ) ;
V_113 = F_3 ( V_2 , V_39 -> V_99 ) & ~ V_114 ;
V_113 |= ( div & V_115 ) ? V_114 : 0 ;
F_1 ( V_2 , V_39 -> V_99 , V_113 ) ;
F_1 ( V_2 , V_39 -> V_111 , div ) ;
F_13 ( & V_2 -> V_11 ) ;
return 0 ;
}
static bool
F_61 ( struct V_33 * V_34 )
{
if ( ! V_34 )
return false ;
return strncmp ( F_32 ( V_34 ) , L_25 , 4 ) == 0 ;
}
static unsigned long F_62 ( struct V_33 * V_34 ,
int V_116 ,
unsigned long V_42 ,
T_1 * div ,
unsigned long * V_117 ,
unsigned long * V_118 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
unsigned long V_119 = 0 ;
T_1 V_120 , V_107 , V_108 ;
struct V_33 * V_121 ;
V_121 = F_63 ( V_34 , V_116 ) ;
if ( ! ( F_50 ( V_116 ) & V_39 -> V_122 ) ) {
* V_117 = F_59 ( V_121 ) ;
* div = F_48 ( V_34 , V_42 , * V_117 , true ) ;
* V_118 = F_53 ( clock , * V_117 , * div ) ;
if ( V_39 -> V_123 && ( * div & V_115 ) ) {
unsigned long V_124 , V_125 ;
T_1 V_126 = * div & ~ V_115 ;
V_124 = F_53 ( clock , * V_117 ,
V_126 ) ;
V_126 += V_115 + 1 ;
V_125 = F_53 ( clock , * V_117 ,
V_126 ) ;
return * V_118 - F_64 ( * V_118 - V_125 , V_124 - * V_118 ) ;
}
return * V_118 ;
}
if ( V_39 -> V_104 )
F_65 ( V_2 -> V_19 ,
L_26 ) ;
V_107 = V_39 -> V_109 ? 2 : 1 ;
V_108 = F_50 ( V_39 -> V_110 ) - 1 ;
for ( V_120 = V_107 ; V_120 <= V_108 ; V_120 ++ ) {
unsigned long V_127 ;
V_127 = F_66 ( V_121 , V_42 * V_120 ) ;
V_127 /= V_120 ;
if ( V_120 == V_107 ||
( V_127 > V_119 && V_127 <= V_42 ) )
V_119 = V_127 ;
if ( V_119 == V_42 )
break;
}
* div = V_120 << V_103 ;
* V_117 = V_120 * V_119 ;
* V_118 = V_119 ;
return V_119 ;
}
static int F_67 ( struct V_33 * V_34 ,
struct V_128 * V_129 )
{
struct V_33 * V_121 , * V_130 = NULL ;
bool V_131 ;
unsigned long V_42 , V_119 = 0 ;
unsigned long V_117 , V_132 = 0 ;
unsigned long V_118 , V_133 = 0 ;
T_3 V_67 ;
T_1 div ;
V_131 = F_61 ( F_68 ( V_34 ) ) ;
for ( V_67 = 0 ; V_67 < F_69 ( V_34 ) ; ++ V_67 ) {
V_121 = F_63 ( V_34 , V_67 ) ;
if ( ! V_121 )
continue;
if ( F_61 ( V_121 ) && ! V_131 )
continue;
V_42 = F_62 ( V_34 , V_67 , V_129 -> V_42 ,
& div , & V_117 ,
& V_118 ) ;
if ( V_42 > V_119 && V_42 <= V_129 -> V_42 ) {
V_130 = V_121 ;
V_132 = V_117 ;
V_119 = V_42 ;
V_133 = V_118 ;
}
}
if ( ! V_130 )
return - V_134 ;
V_129 -> V_135 = V_130 ;
V_129 -> V_136 = V_132 ;
V_129 -> V_42 = V_133 ;
return 0 ;
}
static int F_70 ( struct V_33 * V_34 , T_6 V_137 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
T_6 V_138 = ( V_137 << V_139 ) & V_14 ;
F_1 ( V_2 , V_39 -> V_99 , V_138 ) ;
return 0 ;
}
static T_6 F_71 ( struct V_33 * V_34 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
T_1 V_138 = F_3 ( V_2 , V_39 -> V_99 ) ;
return ( V_138 & V_14 ) >> V_139 ;
}
static int F_72 ( struct V_33 * V_34 ,
struct V_26 * V_26 )
{
struct V_97 * clock = F_46 ( V_34 ) ;
struct V_1 * V_2 = clock -> V_2 ;
const struct V_98 * V_39 = clock -> V_39 ;
return F_14 (
V_2 , V_39 -> V_99 ,
V_140 ,
F_73 ( V_140 ) ,
V_26 ) ;
}
static int F_74 ( struct V_33 * V_34 )
{
return true ;
}
static struct V_33 * F_75 ( struct V_1 * V_2 ,
const struct V_38 * V_39 )
{
struct V_36 * V_37 ;
struct V_141 V_142 ;
int V_35 ;
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_143 = & V_2 -> V_144 [ 0 ] ;
V_142 . V_145 = 1 ;
V_142 . V_81 = V_39 -> V_81 ;
V_142 . V_146 = & V_147 ;
V_142 . V_148 = V_149 ;
V_37 = F_76 ( sizeof( * V_37 ) , V_30 ) ;
if ( ! V_37 )
return NULL ;
V_37 -> V_2 = V_2 ;
V_37 -> V_39 = V_39 ;
V_37 -> V_34 . V_142 = & V_142 ;
V_35 = F_77 ( V_2 -> V_19 , & V_37 -> V_34 ) ;
if ( V_35 )
return NULL ;
return & V_37 -> V_34 ;
}
static struct V_33 *
F_78 ( struct V_1 * V_2 ,
const struct V_85 * V_39 )
{
struct V_83 * V_84 ;
struct V_141 V_142 ;
const char * V_150 ;
int V_35 ;
if ( V_39 -> V_151 != 1 ) {
V_150 = F_79 ( V_2 -> V_19 , V_30 ,
L_27 , V_39 -> V_81 ) ;
if ( ! V_150 )
return NULL ;
} else {
V_150 = V_39 -> V_81 ;
}
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_143 = & V_39 -> V_152 ;
V_142 . V_145 = 1 ;
V_142 . V_81 = V_150 ;
V_142 . V_146 = & V_153 ;
V_142 . V_148 = V_39 -> V_148 | V_149 ;
V_84 = F_15 ( V_2 -> V_19 , sizeof( * V_84 ) , V_30 ) ;
if ( ! V_84 )
return NULL ;
V_84 -> div . V_3 = V_2 -> V_6 + V_39 -> V_86 ;
V_84 -> div . V_154 = V_155 ;
V_84 -> div . V_156 = V_96 ;
V_84 -> div . V_148 = V_157 ;
V_84 -> div . V_158 = & V_2 -> V_11 ;
V_84 -> div . V_34 . V_142 = & V_142 ;
V_84 -> div . V_159 = NULL ;
V_84 -> V_2 = V_2 ;
V_84 -> V_39 = V_39 ;
V_35 = F_77 ( V_2 -> V_19 , & V_84 -> div . V_34 ) ;
if ( V_35 )
return F_80 ( V_35 ) ;
if ( V_39 -> V_151 != 1 ) {
return F_81 ( V_2 -> V_19 , V_39 -> V_81 ,
V_150 ,
V_160 ,
1 ,
V_39 -> V_151 ) ;
}
return & V_84 -> div . V_34 ;
}
static struct V_33 * F_82 ( struct V_1 * V_2 ,
const struct V_98 * V_39 )
{
struct V_97 * clock ;
struct V_141 V_142 ;
const char * V_161 [ 1 << V_15 ] ;
T_3 V_67 , V_162 ;
int V_35 ;
for ( V_67 = 0 ; V_67 < V_39 -> V_163 ; V_67 ++ ) {
V_161 [ V_67 ] = V_39 -> V_161 [ V_67 ] ;
for ( V_162 = 0 ; V_162 < F_73 ( V_164 ) ; V_162 ++ ) {
if ( strcmp ( V_161 [ V_67 ] , V_164 [ V_162 ] ) == 0 ) {
V_161 [ V_67 ] = V_2 -> V_144 [ V_162 ] ;
break;
}
}
}
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
V_142 . V_143 = V_161 ;
V_142 . V_145 = V_39 -> V_163 ;
V_142 . V_81 = V_39 -> V_81 ;
V_142 . V_148 = V_39 -> V_148 | V_149 ;
if ( V_39 -> V_122 )
V_142 . V_148 |= V_160 ;
if ( V_39 -> V_165 ) {
V_142 . V_146 = & V_166 ;
} else {
V_142 . V_146 = & V_167 ;
V_142 . V_148 |= V_168 | V_169 ;
if ( ! ( F_3 ( V_2 , V_39 -> V_99 ) & V_100 ) )
V_142 . V_148 &= ~ V_170 ;
}
clock = F_15 ( V_2 -> V_19 , sizeof( * clock ) , V_30 ) ;
if ( ! clock )
return NULL ;
clock -> V_2 = V_2 ;
clock -> V_39 = V_39 ;
clock -> V_34 . V_142 = & V_142 ;
V_35 = F_77 ( V_2 -> V_19 , & clock -> V_34 ) ;
if ( V_35 )
return F_80 ( V_35 ) ;
return & clock -> V_34 ;
}
static struct V_171 * F_83 ( struct V_1 * V_2 ,
const struct V_172 * V_39 )
{
return F_84 ( V_2 -> V_19 , V_39 -> V_81 , V_39 -> V_121 ,
V_149 | V_168 ,
V_2 -> V_6 + V_39 -> V_99 ,
V_173 , 0 , & V_2 -> V_11 ) ;
}
static int F_85 ( struct V_171 * V_174 )
{
struct V_171 * V_121 = F_86 ( V_174 ) ;
if ( F_19 ( V_121 ) )
return F_87 ( V_121 ) ;
return F_88 ( V_121 ) ;
}
static int F_89 ( struct V_175 * V_176 )
{
struct V_177 * V_19 = & V_176 -> V_19 ;
struct V_33 * * V_178 ;
struct V_1 * V_2 ;
struct V_179 * V_180 ;
const struct V_181 * V_182 ;
const T_3 V_183 = F_73 ( V_184 ) ;
T_3 V_67 ;
int V_35 ;
V_2 = F_15 ( V_19 , sizeof( * V_2 ) +
sizeof( * V_2 -> V_185 . V_178 ) * V_183 ,
V_30 ) ;
if ( ! V_2 )
return - V_31 ;
F_90 ( & V_2 -> V_11 ) ;
V_2 -> V_19 = V_19 ;
V_180 = F_91 ( V_176 , V_186 , 0 ) ;
V_2 -> V_6 = F_92 ( V_19 , V_180 ) ;
if ( F_19 ( V_2 -> V_6 ) )
return F_87 ( V_2 -> V_6 ) ;
memcpy ( V_2 -> V_144 , V_164 ,
sizeof( V_164 ) ) ;
F_93 ( V_19 -> V_187 , V_2 -> V_144 ,
F_73 ( V_164 ) ) ;
if ( ! V_2 -> V_144 [ 0 ] )
return - V_188 ;
F_94 ( V_176 , V_2 ) ;
V_2 -> V_185 . V_189 = V_183 ;
V_178 = V_2 -> V_185 . V_178 ;
for ( V_67 = 0 ; V_67 < V_183 ; V_67 ++ ) {
V_182 = & V_184 [ V_67 ] ;
if ( V_182 -> V_190 && V_182 -> V_39 )
V_178 [ V_67 ] = V_182 -> V_190 ( V_2 , V_182 -> V_39 ) ;
}
V_35 = F_85 ( V_178 [ V_191 ] -> V_171 ) ;
if ( V_35 )
return V_35 ;
return F_95 ( V_19 -> V_187 , V_192 ,
& V_2 -> V_185 ) ;
}
