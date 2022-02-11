static T_1 F_1 ( void * V_1 )
{
return ( T_1 ) F_2 ( V_1 ) ;
}
static T_2 * F_3 ( T_2 V_2 , int V_3 )
{
if ( F_4 ( V_2 , V_3 ) )
V_2 &= V_4 ;
else
V_2 &= F_5 ( V_3 ) ;
return F_6 ( V_2 ) ;
}
static void * F_7 ( int V_3 , T_3 V_5 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
struct V_11 * V_12 = V_9 -> V_13 ;
T_1 V_14 ;
T_4 V_15 = F_8 ( V_3 ) ;
void * V_16 = NULL ;
if ( V_3 == 1 )
V_16 = ( void * ) F_9 ( V_17 , F_10 ( V_15 ) ) ;
else if ( V_3 == 2 )
V_16 = F_11 ( V_7 -> V_18 , V_5 | V_19 ) ;
if ( V_16 && ! ( V_9 -> V_20 & V_21 ) ) {
V_14 = F_12 ( V_12 , V_16 , V_15 , V_22 ) ;
if ( F_13 ( V_12 , V_14 ) )
goto V_23;
if ( V_14 != F_2 ( V_16 ) )
goto V_24;
}
F_14 ( V_16 ) ;
return V_16 ;
V_24:
F_15 ( V_12 , L_1 ) ;
F_16 ( V_12 , V_14 , V_15 , V_22 ) ;
V_23:
if ( V_3 == 1 )
F_17 ( ( unsigned long ) V_16 , F_10 ( V_15 ) ) ;
else
F_18 ( V_7 -> V_18 , V_16 ) ;
return NULL ;
}
static void F_19 ( void * V_16 , int V_3 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
struct V_11 * V_12 = V_9 -> V_13 ;
T_4 V_15 = F_8 ( V_3 ) ;
if ( ! ( V_9 -> V_20 & V_21 ) )
F_16 ( V_12 , F_1 ( V_16 ) , V_15 ,
V_22 ) ;
if ( V_3 == 1 )
F_17 ( ( unsigned long ) V_16 , F_10 ( V_15 ) ) ;
else
F_18 ( V_7 -> V_18 , V_16 ) ;
}
static void F_20 ( T_2 * V_25 , int V_26 ,
struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_20 & V_21 ) )
return;
F_21 ( V_9 -> V_13 , F_1 ( V_25 ) ,
V_26 * sizeof( * V_25 ) , V_22 ) ;
}
static void F_22 ( T_2 * V_25 , T_2 V_2 ,
int V_26 , struct V_8 * V_9 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
V_25 [ V_27 ] = V_2 ;
F_20 ( V_25 , V_26 , V_9 ) ;
}
static T_2 F_23 ( int V_28 , int V_3 ,
struct V_8 * V_9 )
{
bool V_29 = ! ( V_9 -> V_20 & V_30 ) ;
T_2 V_2 = V_31 | V_32 ;
if ( ! ( V_28 & V_33 ) )
V_2 |= F_24 ( 1 ) ;
if ( V_29 ) {
V_2 |= V_34 ;
if ( ! ( V_28 & V_35 ) )
V_2 |= V_36 ;
if ( ! ( V_28 & V_37 ) )
V_2 |= V_38 ;
}
V_2 <<= F_25 ( V_3 ) ;
if ( ( V_28 & V_39 ) && V_29 )
V_2 |= F_26 ( V_3 ) ;
if ( V_28 & V_33 )
V_2 |= V_40 ;
else if ( V_28 & V_41 )
V_2 |= V_40 | V_42 ;
V_2 |= V_43 ;
if ( V_3 == 1 && ( V_9 -> V_20 & V_44 ) )
V_2 |= V_45 ;
if ( V_9 -> V_20 & V_46 )
V_2 |= V_47 ;
return V_2 ;
}
static int F_27 ( T_2 V_2 , int V_3 )
{
int V_28 = V_48 ;
T_2 V_49 = V_2 >> F_25 ( V_3 ) ;
if ( ! ( V_49 & V_38 ) )
V_28 |= V_37 ;
if ( ! ( V_49 & V_36 ) )
V_28 |= V_35 ;
if ( ( V_49 & ( V_50 << V_51 ) ) == 0 )
V_28 |= V_33 ;
else if ( V_2 & V_42 )
V_28 |= V_41 ;
if ( V_2 & F_26 ( V_3 ) )
V_28 |= V_39 ;
return V_28 ;
}
static T_2 F_28 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 ) {
V_2 |= V_52 ;
} else if ( V_3 == 2 ) {
T_2 V_53 = V_2 & F_26 ( V_3 ) ;
T_2 V_54 = V_2 & V_55 ;
V_2 ^= V_53 | V_54 | V_43 ;
V_2 |= ( V_53 << V_56 ) |
( V_54 << V_57 ) |
V_58 ;
}
return V_2 ;
}
static T_2 F_29 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 ) {
V_2 &= ~ V_52 ;
} else if ( V_3 == 2 ) {
T_2 V_53 = V_2 & F_30 ( V_56 ) ;
T_2 V_54 = V_2 & ( V_55 <<
V_57 ) ;
V_2 ^= V_53 | V_54 | V_58 ;
V_2 |= ( V_53 >> V_56 ) |
( V_54 >> V_57 ) |
V_43 ;
}
return V_2 ;
}
static bool F_31 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 && ! F_4 ( V_2 , V_3 ) )
return V_2 & V_52 ;
else if ( V_3 == 2 )
return ! ( V_2 & V_43 ) ;
return false ;
}
static int F_32 ( struct V_6 * V_7 ,
unsigned long V_59 , T_5 V_60 , int V_28 ,
int V_3 , int V_26 , T_2 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
T_2 V_2 ;
int V_27 ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ )
if ( F_4 ( V_25 [ V_27 ] , V_3 ) ) {
T_2 * V_61 ;
T_4 V_62 = F_33 ( V_3 ) ;
V_61 = V_25 - F_34 ( V_59 , V_3 ) ;
if ( F_35 ( F_36 ( V_7 , V_59 + V_27 * V_62 ,
V_62 , V_3 , V_61 ) != V_62 ) )
return - V_63 ;
} else if ( V_25 [ V_27 ] ) {
F_35 ( ! V_64 ) ;
return - V_65 ;
}
V_2 = F_23 ( V_28 , V_3 , V_9 ) ;
if ( V_26 > 1 )
V_2 = F_28 ( V_2 , V_3 ) ;
V_2 |= V_60 & F_5 ( V_3 ) ;
F_22 ( V_25 , V_2 , V_26 , V_9 ) ;
return 0 ;
}
static T_2 F_37 ( T_2 * V_16 ,
T_2 * V_25 ,
T_2 V_66 ,
struct V_8 * V_9 )
{
T_2 V_67 , V_68 ;
V_68 = F_2 ( V_16 ) | V_69 ;
if ( V_9 -> V_20 & V_44 )
V_68 |= V_70 ;
F_38 () ;
V_67 = F_39 ( V_25 , V_66 , V_68 ) ;
F_20 ( V_25 , 1 , V_9 ) ;
return V_67 ;
}
static int F_40 ( struct V_6 * V_7 , unsigned long V_59 ,
T_5 V_60 , T_4 V_15 , int V_28 ,
int V_3 , T_2 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
T_2 V_2 , * V_71 ;
int V_26 = V_15 >> F_41 ( V_3 ) ;
V_25 += F_34 ( V_59 , V_3 ) ;
if ( V_26 )
return F_32 ( V_7 , V_59 , V_60 , V_28 ,
V_3 , V_26 , V_25 ) ;
if ( F_35 ( V_3 == 2 ) )
return - V_63 ;
V_2 = F_42 ( * V_25 ) ;
if ( ! V_2 ) {
V_71 = F_7 ( V_3 + 1 , V_72 , V_7 ) ;
if ( ! V_71 )
return - V_73 ;
V_2 = F_37 ( V_71 , V_25 , 0 , V_9 ) ;
if ( V_2 )
F_19 ( V_71 , V_3 + 1 , V_7 ) ;
} else {
F_20 ( V_25 , 1 , V_9 ) ;
}
if ( F_4 ( V_2 , V_3 ) ) {
V_71 = F_3 ( V_2 , V_3 ) ;
} else if ( V_2 ) {
F_35 ( ! V_64 ) ;
return - V_65 ;
}
return F_40 ( V_7 , V_59 , V_60 , V_15 , V_28 , V_3 + 1 , V_71 ) ;
}
static int F_43 ( struct V_74 * V_75 , unsigned long V_59 ,
T_5 V_60 , T_4 V_15 , int V_28 )
{
struct V_6 * V_7 = F_44 ( V_75 ) ;
struct V_76 * V_10 = & V_7 -> V_10 ;
int V_77 ;
if ( ! ( V_28 & ( V_48 | V_37 ) ) )
return 0 ;
if ( F_35 ( F_45 ( V_59 ) || F_45 ( V_60 ) ) )
return - V_78 ;
V_77 = F_40 ( V_7 , V_59 , V_60 , V_15 , V_28 , 1 , V_7 -> V_79 ) ;
if ( V_10 -> V_9 . V_20 & V_80 ) {
F_46 ( V_10 , V_59 , V_15 ,
F_33 ( 2 ) , false ) ;
F_47 ( V_10 ) ;
} else {
F_48 () ;
}
return V_77 ;
}
static void F_49 ( struct V_76 * V_10 )
{
struct V_6 * V_7 = F_50 ( V_10 ) ;
int V_27 ;
for ( V_27 = 0 ; V_27 < F_51 ( 1 ) ; V_27 ++ ) {
T_2 V_2 = V_7 -> V_79 [ V_27 ] ;
if ( F_4 ( V_2 , 1 ) )
F_19 ( F_3 ( V_2 , 1 ) , 2 , V_7 ) ;
}
F_19 ( V_7 -> V_79 , 1 , V_7 ) ;
F_52 ( V_7 -> V_18 ) ;
F_53 ( V_7 ) ;
}
static T_2 F_54 ( struct V_6 * V_7 ,
unsigned long V_59 , int V_81 , int V_3 ,
T_2 * V_25 )
{
struct V_76 * V_10 = & V_7 -> V_10 ;
T_2 V_2 ;
T_4 V_15 = F_33 ( V_3 ) ;
int V_27 ;
V_2 = * V_25 ;
if ( ! F_31 ( V_2 , V_3 ) )
return V_2 ;
V_25 -= V_81 & ( V_82 - 1 ) ;
V_2 = F_29 ( V_2 , V_3 ) ;
for ( V_27 = 0 ; V_27 < V_82 ; V_27 ++ )
V_25 [ V_27 ] = V_2 + V_27 * V_15 ;
F_20 ( V_25 , V_82 , & V_10 -> V_9 ) ;
V_15 *= V_82 ;
F_46 ( V_10 , V_59 , V_15 , V_15 , true ) ;
F_47 ( V_10 ) ;
return V_2 ;
}
static int F_55 ( struct V_6 * V_7 ,
unsigned long V_59 , T_4 V_15 ,
T_2 V_83 , T_2 * V_25 )
{
struct V_8 * V_9 = & V_7 -> V_10 . V_9 ;
T_2 V_2 , * V_84 ;
int V_27 , V_85 , V_26 , V_86 ;
V_84 = F_7 ( 2 , V_72 , V_7 ) ;
if ( ! V_84 )
return 0 ;
V_86 = F_51 ( 2 ) ;
V_26 = V_15 >> F_41 ( 2 ) ;
V_85 = F_34 ( V_59 , 2 ) ;
V_2 = F_23 ( F_27 ( V_83 , 1 ) , 2 , V_9 ) ;
if ( V_26 > 1 )
V_2 = F_28 ( V_2 , 2 ) ;
for ( V_27 = 0 ; V_27 < V_86 ; V_27 += V_26 , V_2 += V_15 ) {
if ( V_27 == V_85 )
continue;
F_22 ( & V_84 [ V_27 ] , V_2 , V_26 , V_9 ) ;
}
V_2 = F_37 ( V_84 , V_25 , V_83 , V_9 ) ;
if ( V_2 != V_83 ) {
F_19 ( V_84 , 2 , V_7 ) ;
if ( ! F_4 ( V_2 , 1 ) )
return 0 ;
V_84 = F_3 ( V_2 , 1 ) ;
return F_36 ( V_7 , V_59 , V_15 , 2 , V_84 ) ;
}
F_46 ( & V_7 -> V_10 , V_59 , V_15 , V_15 , true ) ;
return V_15 ;
}
static int F_36 ( struct V_6 * V_7 ,
unsigned long V_59 , T_4 V_15 , int V_3 ,
T_2 * V_25 )
{
T_2 V_2 [ V_82 ] ;
struct V_76 * V_10 = & V_7 -> V_10 ;
int V_81 , V_27 = 0 , V_26 = V_15 >> F_41 ( V_3 ) ;
if ( F_35 ( V_3 > 2 ) )
return 0 ;
V_81 = F_34 ( V_59 , V_3 ) ;
V_25 += V_81 ;
do {
V_2 [ V_27 ] = F_42 ( V_25 [ V_27 ] ) ;
if ( F_35 ( ! F_56 ( V_2 [ V_27 ] ) ) )
return 0 ;
} while ( ++ V_27 < V_26 );
if ( V_26 <= 1 && F_31 ( V_2 [ 0 ] , V_3 ) ) {
unsigned long V_87 ;
F_57 ( & V_7 -> V_88 , V_87 ) ;
V_2 [ 0 ] = F_54 ( V_7 , V_59 , V_81 , V_3 , V_25 ) ;
F_58 ( & V_7 -> V_88 , V_87 ) ;
}
if ( V_26 ) {
T_4 V_89 = F_33 ( V_3 ) ;
F_22 ( V_25 , 0 , V_26 , & V_10 -> V_9 ) ;
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
if ( F_4 ( V_2 [ V_27 ] , V_3 ) ) {
F_46 ( V_10 , V_59 , V_89 ,
F_33 ( V_3 + 1 ) , false ) ;
F_47 ( V_10 ) ;
V_25 = F_3 ( V_2 [ V_27 ] , V_3 ) ;
F_19 ( V_25 , V_3 + 1 , V_7 ) ;
} else {
F_46 ( V_10 , V_59 , V_89 ,
V_89 , true ) ;
}
V_59 += V_89 ;
}
return V_15 ;
} else if ( V_3 == 1 && ! F_4 ( V_2 [ 0 ] , V_3 ) ) {
return F_55 ( V_7 , V_59 , V_15 , V_2 [ 0 ] , V_25 ) ;
}
V_25 = F_3 ( V_2 [ 0 ] , V_3 ) ;
return F_36 ( V_7 , V_59 , V_15 , V_3 + 1 , V_25 ) ;
}
static int F_59 ( struct V_74 * V_75 , unsigned long V_59 ,
T_4 V_15 )
{
struct V_6 * V_7 = F_44 ( V_75 ) ;
T_4 V_90 ;
if ( F_35 ( F_45 ( V_59 ) ) )
return 0 ;
V_90 = F_36 ( V_7 , V_59 , V_15 , 1 , V_7 -> V_79 ) ;
if ( V_90 )
F_47 ( & V_7 -> V_10 ) ;
return V_90 ;
}
static T_5 F_60 ( struct V_74 * V_75 ,
unsigned long V_59 )
{
struct V_6 * V_7 = F_44 ( V_75 ) ;
T_2 * V_25 = V_7 -> V_79 , V_2 ;
int V_3 = 0 ;
T_6 V_91 ;
do {
V_25 += F_34 ( V_59 , ++ V_3 ) ;
V_2 = F_42 ( * V_25 ) ;
V_25 = F_3 ( V_2 , V_3 ) ;
} while ( F_4 ( V_2 , V_3 ) );
if ( ! F_56 ( V_2 ) )
return 0 ;
V_91 = F_5 ( V_3 ) ;
if ( F_31 ( V_2 , V_3 ) )
V_91 *= V_82 ;
return ( V_2 & V_91 ) | ( V_59 & ~ V_91 ) ;
}
static struct V_76 * F_61 ( struct V_8 * V_9 ,
void * V_92 )
{
struct V_6 * V_7 ;
#ifdef F_62
if ( F_45 ( F_62 ) )
return NULL ;
#endif
if ( V_9 -> V_93 > V_94 || V_9 -> V_95 > V_94 )
return NULL ;
if ( V_9 -> V_20 & ~ ( V_44 |
V_30 |
V_80 |
V_46 |
V_21 ) )
return NULL ;
if ( V_9 -> V_20 & V_46 &&
! ( V_9 -> V_20 & V_30 ) )
return NULL ;
V_7 = F_63 ( sizeof( * V_7 ) , V_96 ) ;
if ( ! V_7 )
return NULL ;
F_64 ( & V_7 -> V_88 ) ;
V_7 -> V_18 = F_65 ( L_2 ,
F_8 ( 2 ) ,
F_8 ( 2 ) ,
V_97 , NULL ) ;
if ( ! V_7 -> V_18 )
goto V_98;
V_7 -> V_10 . V_75 = (struct V_74 ) {
. V_99 = F_43 ,
. V_100 = F_59 ,
. V_101 = F_60 ,
} ;
V_7 -> V_10 . V_9 = * V_9 ;
V_9 -> V_102 &= V_103 | V_104 | V_105 | V_106 ;
V_9 -> V_107 . V_108 = V_109 ;
V_9 -> V_107 . V_110 = F_66 ( 1 , V_111 ) |
F_66 ( 4 , V_112 ) |
F_66 ( 7 , V_112 ) |
V_113 | V_114 |
V_115 | F_67 ( 7 ) ;
V_9 -> V_107 . V_116 = F_68 ( 7 , V_117 ) |
F_69 ( 7 , V_117 ) ;
V_7 -> V_79 = F_7 ( 1 , V_96 , V_7 ) ;
if ( ! V_7 -> V_79 )
goto V_98;
F_48 () ;
V_9 -> V_107 . V_118 [ 0 ] = F_2 ( V_7 -> V_79 ) |
V_119 | V_120 |
F_70 ( V_117 ) |
F_71 ( V_117 ) ;
V_9 -> V_107 . V_118 [ 1 ] = 0 ;
return & V_7 -> V_10 ;
V_98:
F_52 ( V_7 -> V_18 ) ;
F_53 ( V_7 ) ;
return NULL ;
}
static void F_72 ( void * V_92 )
{
F_35 ( V_92 != V_121 ) ;
}
static void F_73 ( unsigned long V_59 , T_4 V_15 ,
T_4 V_122 , bool V_123 , void * V_92 )
{
F_35 ( V_92 != V_121 ) ;
F_35 ( ! ( V_15 & V_121 -> V_102 ) ) ;
}
static void F_74 ( void * V_92 )
{
F_35 ( V_92 != V_121 ) ;
}
static int T_7 F_75 ( void )
{
struct V_74 * V_75 ;
struct V_8 V_9 = {
. V_124 = & V_125 ,
. V_95 = 32 ,
. V_93 = 32 ,
. V_20 = V_44 | V_21 ,
. V_102 = V_103 | V_104 | V_105 | V_106 ,
} ;
unsigned int V_59 , V_15 , V_126 ;
unsigned int V_27 , V_127 = 0 ;
V_64 = true ;
V_121 = & V_9 ;
V_75 = F_76 ( V_128 , & V_9 , & V_9 ) ;
if ( ! V_75 ) {
F_77 ( L_3 ) ;
return - V_63 ;
}
if ( V_75 -> V_101 ( V_75 , 42 ) )
return F_78 ( V_75 ) ;
if ( V_75 -> V_101 ( V_75 , V_129 + 42 ) )
return F_78 ( V_75 ) ;
if ( V_75 -> V_101 ( V_75 , V_130 + 42 ) )
return F_78 ( V_75 ) ;
V_59 = 0 ;
F_79 (i, &cfg.pgsize_bitmap, BITS_PER_LONG) {
V_15 = 1UL << V_27 ;
if ( V_75 -> V_99 ( V_75 , V_59 , V_59 , V_15 , V_48 |
V_37 |
V_39 |
V_41 ) )
return F_78 ( V_75 ) ;
if ( ! V_75 -> V_99 ( V_75 , V_59 , V_59 + V_15 , V_15 ,
V_48 | V_39 ) )
return F_78 ( V_75 ) ;
if ( V_75 -> V_101 ( V_75 , V_59 + 42 ) != ( V_59 + 42 ) )
return F_78 ( V_75 ) ;
V_59 += V_106 ;
V_127 ++ ;
}
V_27 = 1 ;
V_15 = 1UL << F_80 ( V_9 . V_102 ) ;
while ( V_27 < V_127 ) {
V_126 = V_27 * V_106 ;
if ( V_75 -> V_100 ( V_75 , V_126 + V_15 , V_15 ) != V_15 )
return F_78 ( V_75 ) ;
if ( V_75 -> V_99 ( V_75 , V_126 + V_15 , V_15 , V_15 , V_48 ) )
return F_78 ( V_75 ) ;
if ( V_75 -> V_101 ( V_75 , V_126 + V_15 + 42 )
!= ( V_15 + 42 ) )
return F_78 ( V_75 ) ;
V_27 ++ ;
}
V_59 = 0 ;
V_27 = F_81 ( & V_9 . V_102 , V_131 ) ;
while ( V_27 != V_131 ) {
V_15 = 1UL << V_27 ;
if ( V_75 -> V_100 ( V_75 , V_59 , V_15 ) != V_15 )
return F_78 ( V_75 ) ;
if ( V_75 -> V_101 ( V_75 , V_59 + 42 ) )
return F_78 ( V_75 ) ;
if ( V_75 -> V_99 ( V_75 , V_59 , V_59 , V_15 , V_37 ) )
return F_78 ( V_75 ) ;
if ( V_75 -> V_101 ( V_75 , V_59 + 42 ) != ( V_59 + 42 ) )
return F_78 ( V_75 ) ;
V_59 += V_106 ;
V_27 ++ ;
V_27 = F_82 ( & V_9 . V_102 , V_131 , V_27 ) ;
}
F_83 ( V_75 ) ;
V_64 = false ;
F_84 ( L_4 ) ;
return 0 ;
}
