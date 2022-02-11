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
struct V_8 * V_9 = V_7 -> V_10 . V_11 . V_12 ;
T_1 V_13 ;
T_4 V_14 = F_8 ( V_3 ) ;
void * V_15 = NULL ;
if ( V_3 == 1 )
V_15 = ( void * ) F_9 ( V_16 , F_10 ( V_14 ) ) ;
else if ( V_3 == 2 )
V_15 = F_11 ( V_7 -> V_17 , V_5 | V_18 ) ;
if ( V_15 && ! V_19 ) {
V_13 = F_12 ( V_9 , V_15 , V_14 , V_20 ) ;
if ( F_13 ( V_9 , V_13 ) )
goto V_21;
if ( V_13 != F_2 ( V_15 ) )
goto V_22;
}
F_14 ( V_15 ) ;
return V_15 ;
V_22:
F_15 ( V_9 , L_1 ) ;
F_16 ( V_9 , V_13 , V_14 , V_20 ) ;
V_21:
if ( V_3 == 1 )
F_17 ( ( unsigned long ) V_15 , F_10 ( V_14 ) ) ;
else
F_18 ( V_7 -> V_17 , V_15 ) ;
return NULL ;
}
static void F_19 ( void * V_15 , int V_3 ,
struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 . V_11 . V_12 ;
T_4 V_14 = F_8 ( V_3 ) ;
if ( ! V_19 )
F_16 ( V_9 , F_1 ( V_15 ) , V_14 ,
V_20 ) ;
if ( V_3 == 1 )
F_17 ( ( unsigned long ) V_15 , F_10 ( V_14 ) ) ;
else
F_18 ( V_7 -> V_17 , V_15 ) ;
}
static void F_20 ( T_2 * V_23 , int V_24 ,
struct V_25 * V_11 )
{
if ( V_19 )
return;
F_21 ( V_11 -> V_12 , F_1 ( V_23 ) ,
V_24 * sizeof( * V_23 ) , V_20 ) ;
}
static void F_22 ( T_2 * V_23 , T_2 V_2 ,
int V_24 , struct V_25 * V_11 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
V_23 [ V_26 ] = V_2 ;
F_20 ( V_23 , V_24 , V_11 ) ;
}
static T_2 F_23 ( int V_27 , int V_3 ,
struct V_25 * V_11 )
{
bool V_28 = ! ( V_11 -> V_29 & V_30 ) ;
T_2 V_2 = V_31 | V_32 ;
if ( ! ( V_27 & V_33 ) )
V_2 |= F_24 ( 1 ) ;
if ( V_28 ) {
V_2 |= V_34 | V_35 ;
if ( ! ( V_27 & V_36 ) )
V_2 |= V_37 ;
}
V_2 <<= F_25 ( V_3 ) ;
if ( ( V_27 & V_38 ) && V_28 )
V_2 |= F_26 ( V_3 ) ;
if ( V_27 & V_33 )
V_2 |= V_39 ;
else if ( V_27 & V_40 )
V_2 |= V_39 | V_41 ;
return V_2 ;
}
static int F_27 ( T_2 V_2 , int V_3 )
{
int V_27 = V_42 ;
T_2 V_43 = V_2 >> F_25 ( V_3 ) ;
if ( ! ( V_43 & V_37 ) )
V_27 |= V_36 ;
if ( ( V_43 & ( V_44 << V_45 ) ) == 0 )
V_27 |= V_33 ;
else if ( V_2 & V_41 )
V_27 |= V_40 ;
if ( V_2 & F_26 ( V_3 ) )
V_27 |= V_38 ;
return V_27 ;
}
static T_2 F_28 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 ) {
V_2 |= V_46 ;
} else if ( V_3 == 2 ) {
T_2 V_47 = V_2 & F_26 ( V_3 ) ;
T_2 V_48 = V_2 & V_49 ;
V_2 ^= V_47 | V_48 | V_50 ;
V_2 |= ( V_47 << V_51 ) |
( V_48 << V_52 ) |
V_53 ;
}
return V_2 ;
}
static T_2 F_29 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 ) {
V_2 &= ~ V_46 ;
} else if ( V_3 == 2 ) {
T_2 V_47 = V_2 & F_30 ( V_51 ) ;
T_2 V_48 = V_2 & ( V_49 <<
V_52 ) ;
V_2 ^= V_47 | V_48 | V_53 ;
V_2 |= ( V_47 >> V_51 ) |
( V_48 >> V_52 ) |
V_50 ;
}
return V_2 ;
}
static bool F_31 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 && ! F_4 ( V_2 , V_3 ) )
return V_2 & V_46 ;
else if ( V_3 == 2 )
return ! ( V_2 & V_50 ) ;
return false ;
}
static int F_32 ( struct V_6 * V_7 ,
unsigned long V_54 , T_5 V_55 , int V_27 ,
int V_3 , int V_24 , T_2 * V_23 )
{
struct V_25 * V_11 = & V_7 -> V_10 . V_11 ;
T_2 V_2 = F_23 ( V_27 , V_3 , V_11 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
if ( F_4 ( V_23 [ V_26 ] , V_3 ) ) {
T_2 * V_56 ;
T_4 V_57 = F_33 ( V_3 ) ;
V_56 = V_23 - F_34 ( V_54 , V_3 ) ;
if ( F_35 ( F_36 ( V_7 , V_54 + V_26 * V_57 ,
V_57 , V_3 , V_56 ) != V_57 ) )
return - V_58 ;
} else if ( V_23 [ V_26 ] ) {
F_35 ( ! V_19 ) ;
return - V_59 ;
}
V_2 |= V_50 ;
if ( V_3 == 1 && ( V_11 -> V_29 & V_60 ) )
V_2 |= V_61 ;
if ( V_11 -> V_29 & V_62 )
V_2 |= V_63 ;
if ( V_24 > 1 )
V_2 = F_28 ( V_2 , V_3 ) ;
V_2 |= V_55 & F_5 ( V_3 ) ;
F_22 ( V_23 , V_2 , V_24 , V_11 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 , unsigned long V_54 ,
T_5 V_55 , T_4 V_14 , int V_27 ,
int V_3 , T_2 * V_23 )
{
struct V_25 * V_11 = & V_7 -> V_10 . V_11 ;
T_2 V_2 , * V_64 ;
int V_24 = V_14 >> F_38 ( V_3 ) ;
V_23 += F_34 ( V_54 , V_3 ) ;
if ( V_24 )
return F_32 ( V_7 , V_54 , V_55 , V_27 ,
V_3 , V_24 , V_23 ) ;
if ( F_35 ( V_3 == 2 ) )
return - V_58 ;
V_2 = * V_23 ;
if ( ! V_2 ) {
V_64 = F_7 ( V_3 + 1 , V_65 , V_7 ) ;
if ( ! V_64 )
return - V_66 ;
V_2 = F_2 ( V_64 ) | V_67 ;
if ( V_11 -> V_29 & V_60 )
V_2 |= V_68 ;
F_22 ( V_23 , V_2 , 1 , V_11 ) ;
} else {
V_64 = F_3 ( V_2 , V_3 ) ;
}
return F_37 ( V_7 , V_54 , V_55 , V_14 , V_27 , V_3 + 1 , V_64 ) ;
}
static int F_39 ( struct V_69 * V_70 , unsigned long V_54 ,
T_5 V_55 , T_4 V_14 , int V_27 )
{
struct V_6 * V_7 = F_40 ( V_70 ) ;
struct V_71 * V_10 = & V_7 -> V_10 ;
int V_72 ;
if ( ! ( V_27 & ( V_42 | V_36 ) ) )
return 0 ;
V_72 = F_37 ( V_7 , V_54 , V_55 , V_14 , V_27 , 1 , V_7 -> V_73 ) ;
if ( V_10 -> V_11 . V_29 & V_74 ) {
F_41 ( V_10 , V_54 , V_14 ,
F_33 ( 2 ) , false ) ;
F_42 ( V_10 ) ;
} else {
F_43 () ;
}
return V_72 ;
}
static void F_44 ( struct V_71 * V_10 )
{
struct V_6 * V_7 = F_45 ( V_10 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < F_46 ( 1 ) ; V_26 ++ ) {
T_2 V_2 = V_7 -> V_73 [ V_26 ] ;
if ( F_4 ( V_2 , 1 ) )
F_19 ( F_3 ( V_2 , 1 ) , 2 , V_7 ) ;
}
F_19 ( V_7 -> V_73 , 1 , V_7 ) ;
F_47 ( V_7 -> V_17 ) ;
F_48 ( V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 ,
unsigned long V_54 , int V_75 , int V_3 ,
T_2 * V_23 )
{
struct V_71 * V_10 = & V_7 -> V_10 ;
T_2 V_2 ;
T_4 V_14 = F_33 ( V_3 ) ;
int V_26 ;
V_23 -= V_75 & ( V_76 - 1 ) ;
V_2 = F_29 ( * V_23 , V_3 ) ;
for ( V_26 = 0 ; V_26 < V_76 ; V_26 ++ ) {
V_23 [ V_26 ] = V_2 ;
V_2 += V_14 ;
}
F_20 ( V_23 , V_76 , & V_10 -> V_11 ) ;
V_14 *= V_76 ;
F_41 ( V_10 , V_54 , V_14 , V_14 , true ) ;
F_42 ( V_10 ) ;
}
static int F_50 ( struct V_6 * V_7 ,
unsigned long V_54 , T_4 V_14 ,
T_2 * V_23 )
{
unsigned long V_77 , V_78 , V_79 ;
T_5 V_80 ;
T_2 V_15 = 0 ;
int V_27 = F_27 ( * V_23 , 1 ) ;
V_79 = F_33 ( 1 ) ;
V_77 = V_54 & F_5 ( 1 ) ;
V_78 = V_77 + F_33 ( 1 ) ;
V_80 = * V_23 & F_5 ( 1 ) ;
for (; V_77 < V_78 ; V_77 += V_14 , V_80 += V_14 ) {
T_2 * V_81 ;
if ( V_77 == V_54 )
continue;
V_81 = & V_15 - F_34 ( V_77 , 1 ) ;
if ( F_37 ( V_7 , V_77 , V_80 , V_14 , V_27 , 1 ,
V_81 ) < 0 ) {
if ( V_15 ) {
V_81 = F_3 ( V_15 , 1 ) ;
F_19 ( V_81 , 2 , V_7 ) ;
}
return 0 ;
}
}
F_22 ( V_23 , V_15 , 1 , & V_7 -> V_10 . V_11 ) ;
V_54 &= ~ ( V_79 - 1 ) ;
F_41 ( & V_7 -> V_10 , V_54 , V_79 , V_79 , true ) ;
return V_14 ;
}
static int F_36 ( struct V_6 * V_7 ,
unsigned long V_54 , T_4 V_14 , int V_3 ,
T_2 * V_23 )
{
T_2 V_2 [ V_76 ] ;
struct V_71 * V_10 = & V_7 -> V_10 ;
int V_75 , V_26 = 0 , V_24 = V_14 >> F_38 ( V_3 ) ;
if ( F_35 ( V_3 > 2 ) )
return 0 ;
V_75 = F_34 ( V_54 , V_3 ) ;
V_23 += V_75 ;
do {
if ( F_35 ( ! F_51 ( V_23 [ V_26 ] ) ) )
return 0 ;
V_2 [ V_26 ] = V_23 [ V_26 ] ;
} while ( ++ V_26 < V_24 );
if ( V_24 <= 1 && F_31 ( V_2 [ 0 ] , V_3 ) )
F_49 ( V_7 , V_54 , V_75 , V_3 , V_23 ) ;
if ( V_24 ) {
T_4 V_79 = F_33 ( V_3 ) ;
F_22 ( V_23 , 0 , V_24 , & V_10 -> V_11 ) ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
if ( F_4 ( V_2 [ V_26 ] , V_3 ) ) {
F_41 ( V_10 , V_54 , V_79 ,
F_33 ( V_3 + 1 ) , false ) ;
F_42 ( V_10 ) ;
V_23 = F_3 ( V_2 [ V_26 ] , V_3 ) ;
F_19 ( V_23 , V_3 + 1 , V_7 ) ;
} else {
F_41 ( V_10 , V_54 , V_79 ,
V_79 , true ) ;
}
V_54 += V_79 ;
}
return V_14 ;
} else if ( V_3 == 1 && ! F_4 ( V_2 [ 0 ] , V_3 ) ) {
return F_50 ( V_7 , V_54 , V_14 , V_23 ) ;
}
V_23 = F_3 ( V_2 [ 0 ] , V_3 ) ;
return F_36 ( V_7 , V_54 , V_14 , V_3 + 1 , V_23 ) ;
}
static int F_52 ( struct V_69 * V_70 , unsigned long V_54 ,
T_4 V_14 )
{
struct V_6 * V_7 = F_40 ( V_70 ) ;
T_4 V_82 ;
V_82 = F_36 ( V_7 , V_54 , V_14 , 1 , V_7 -> V_73 ) ;
if ( V_82 )
F_42 ( & V_7 -> V_10 ) ;
return V_82 ;
}
static T_5 F_53 ( struct V_69 * V_70 ,
unsigned long V_54 )
{
struct V_6 * V_7 = F_40 ( V_70 ) ;
T_2 * V_23 = V_7 -> V_73 , V_2 ;
int V_3 = 0 ;
T_6 V_83 ;
do {
V_2 = V_23 [ F_34 ( V_54 , ++ V_3 ) ] ;
V_23 = F_3 ( V_2 , V_3 ) ;
} while ( F_4 ( V_2 , V_3 ) );
if ( ! F_51 ( V_2 ) )
return 0 ;
V_83 = F_5 ( V_3 ) ;
if ( F_31 ( V_2 , V_3 ) )
V_83 *= V_76 ;
return ( V_2 & V_83 ) | ( V_54 & ~ V_83 ) ;
}
static struct V_71 * F_54 ( struct V_25 * V_11 ,
void * V_84 )
{
struct V_6 * V_7 ;
#ifdef F_55
if ( F_56 ( F_55 ) )
return NULL ;
#endif
if ( V_11 -> V_85 > V_86 || V_11 -> V_87 > V_86 )
return NULL ;
if ( V_11 -> V_29 & ~ ( V_60 |
V_30 |
V_74 |
V_62 ) )
return NULL ;
if ( V_11 -> V_29 & V_62 &&
! ( V_11 -> V_29 & V_30 ) )
return NULL ;
V_7 = F_57 ( sizeof( * V_7 ) , V_88 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_17 = F_58 ( L_2 ,
F_8 ( 2 ) ,
F_8 ( 2 ) ,
V_89 , NULL ) ;
if ( ! V_7 -> V_17 )
goto V_90;
V_7 -> V_10 . V_70 = (struct V_69 ) {
. V_91 = F_39 ,
. V_92 = F_52 ,
. V_93 = F_53 ,
} ;
V_7 -> V_10 . V_11 = * V_11 ;
V_11 -> V_94 &= V_95 | V_96 | V_97 | V_98 ;
V_11 -> V_99 . V_100 = V_101 ;
V_11 -> V_99 . V_102 = F_59 ( 1 , V_103 ) |
F_59 ( 4 , V_104 ) |
F_59 ( 7 , V_104 ) |
V_105 | V_106 |
V_107 | F_60 ( 7 ) ;
V_11 -> V_99 . V_108 = F_61 ( 7 , V_109 ) |
F_62 ( 7 , V_109 ) ;
V_7 -> V_73 = F_7 ( 1 , V_88 , V_7 ) ;
if ( ! V_7 -> V_73 )
goto V_90;
F_43 () ;
V_11 -> V_99 . V_110 [ 0 ] = F_2 ( V_7 -> V_73 ) |
V_111 | V_112 |
F_63 ( V_109 ) |
F_64 ( V_109 ) ;
V_11 -> V_99 . V_110 [ 1 ] = 0 ;
return & V_7 -> V_10 ;
V_90:
F_47 ( V_7 -> V_17 ) ;
F_48 ( V_7 ) ;
return NULL ;
}
static void F_65 ( void * V_84 )
{
F_35 ( V_84 != V_113 ) ;
}
static void F_66 ( unsigned long V_54 , T_4 V_14 ,
T_4 V_114 , bool V_115 , void * V_84 )
{
F_35 ( V_84 != V_113 ) ;
F_35 ( ! ( V_14 & V_113 -> V_94 ) ) ;
}
static void F_67 ( void * V_84 )
{
F_35 ( V_84 != V_113 ) ;
}
static int T_7 F_68 ( void )
{
struct V_69 * V_70 ;
struct V_25 V_11 = {
. V_116 = & V_117 ,
. V_87 = 32 ,
. V_85 = 32 ,
. V_29 = V_60 ,
. V_94 = V_95 | V_96 | V_97 | V_98 ,
} ;
unsigned int V_54 , V_14 , V_118 ;
unsigned int V_26 , V_119 = 0 ;
V_19 = true ;
V_113 = & V_11 ;
V_70 = F_69 ( V_120 , & V_11 , & V_11 ) ;
if ( ! V_70 ) {
F_70 ( L_3 ) ;
return - V_58 ;
}
if ( V_70 -> V_93 ( V_70 , 42 ) )
return F_71 ( V_70 ) ;
if ( V_70 -> V_93 ( V_70 , V_121 + 42 ) )
return F_71 ( V_70 ) ;
if ( V_70 -> V_93 ( V_70 , V_122 + 42 ) )
return F_71 ( V_70 ) ;
V_54 = 0 ;
F_72 (i, &cfg.pgsize_bitmap, BITS_PER_LONG) {
V_14 = 1UL << V_26 ;
if ( V_70 -> V_91 ( V_70 , V_54 , V_54 , V_14 , V_42 |
V_36 |
V_38 |
V_40 ) )
return F_71 ( V_70 ) ;
if ( ! V_70 -> V_91 ( V_70 , V_54 , V_54 + V_14 , V_14 ,
V_42 | V_38 ) )
return F_71 ( V_70 ) ;
if ( V_70 -> V_93 ( V_70 , V_54 + 42 ) != ( V_54 + 42 ) )
return F_71 ( V_70 ) ;
V_54 += V_98 ;
V_119 ++ ;
}
V_26 = 1 ;
V_14 = 1UL << F_73 ( V_11 . V_94 ) ;
while ( V_26 < V_119 ) {
V_118 = V_26 * V_98 ;
if ( V_70 -> V_92 ( V_70 , V_118 + V_14 , V_14 ) != V_14 )
return F_71 ( V_70 ) ;
if ( V_70 -> V_91 ( V_70 , V_118 + V_14 , V_14 , V_14 , V_42 ) )
return F_71 ( V_70 ) ;
if ( V_70 -> V_93 ( V_70 , V_118 + V_14 + 42 )
!= ( V_14 + 42 ) )
return F_71 ( V_70 ) ;
V_26 ++ ;
}
V_54 = 0 ;
V_26 = F_74 ( & V_11 . V_94 , V_123 ) ;
while ( V_26 != V_123 ) {
V_14 = 1UL << V_26 ;
if ( V_70 -> V_92 ( V_70 , V_54 , V_14 ) != V_14 )
return F_71 ( V_70 ) ;
if ( V_70 -> V_93 ( V_70 , V_54 + 42 ) )
return F_71 ( V_70 ) ;
if ( V_70 -> V_91 ( V_70 , V_54 , V_54 , V_14 , V_36 ) )
return F_71 ( V_70 ) ;
if ( V_70 -> V_93 ( V_70 , V_54 + 42 ) != ( V_54 + 42 ) )
return F_71 ( V_70 ) ;
V_54 += V_98 ;
V_26 ++ ;
V_26 = F_75 ( & V_11 . V_94 , V_123 , V_26 ) ;
}
F_76 ( V_70 ) ;
V_19 = false ;
F_77 ( L_4 ) ;
return 0 ;
}
