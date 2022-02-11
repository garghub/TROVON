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
T_2 V_2 = V_31 | V_32 |
F_24 ( 1 ) ;
if ( V_28 ) {
V_2 |= V_33 | V_34 ;
if ( ! ( V_27 & V_35 ) )
V_2 |= V_36 ;
}
V_2 <<= F_25 ( V_3 ) ;
if ( ( V_27 & V_37 ) && V_28 )
V_2 |= F_26 ( V_3 ) ;
if ( V_27 & V_38 )
V_2 |= V_39 | V_40 ;
return V_2 ;
}
static int F_27 ( T_2 V_2 , int V_3 )
{
int V_27 = V_41 ;
if ( V_2 & ( V_36 << F_25 ( V_3 ) ) )
V_27 |= V_35 ;
if ( V_2 & V_40 )
V_27 |= V_38 ;
return V_27 ;
}
static T_2 F_28 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 ) {
V_2 |= V_42 ;
} else if ( V_3 == 2 ) {
T_2 V_43 = V_2 & F_26 ( V_3 ) ;
T_2 V_44 = V_2 & V_45 ;
V_2 ^= V_43 | V_44 | V_46 ;
V_2 |= ( V_43 << V_47 ) |
( V_44 << V_48 ) |
V_49 ;
}
return V_2 ;
}
static T_2 F_29 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 ) {
V_2 &= ~ V_42 ;
} else if ( V_3 == 2 ) {
T_2 V_43 = V_2 & F_30 ( V_47 ) ;
T_2 V_44 = V_2 & ( V_45 <<
V_48 ) ;
V_2 ^= V_43 | V_44 | V_49 ;
V_2 |= ( V_43 >> V_47 ) |
( V_44 >> V_48 ) |
V_46 ;
}
return V_2 ;
}
static bool F_31 ( T_2 V_2 , int V_3 )
{
if ( V_3 == 1 && ! F_4 ( V_2 , V_3 ) )
return V_2 & V_42 ;
else if ( V_3 == 2 )
return ! ( V_2 & V_46 ) ;
return false ;
}
static int F_32 ( struct V_6 * V_7 ,
unsigned long V_50 , T_5 V_51 , int V_27 ,
int V_3 , int V_24 , T_2 * V_23 )
{
struct V_25 * V_11 = & V_7 -> V_10 . V_11 ;
T_2 V_2 = F_23 ( V_27 , V_3 , V_11 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ )
if ( F_4 ( V_23 [ V_26 ] , V_3 ) ) {
T_2 * V_52 ;
T_4 V_53 = F_33 ( V_3 ) ;
V_52 = V_23 - F_34 ( V_50 , V_3 ) ;
if ( F_35 ( F_36 ( V_7 , V_50 + V_26 * V_53 ,
V_53 , V_3 , V_52 ) != V_53 ) )
return - V_54 ;
} else if ( V_23 [ V_26 ] ) {
F_35 ( ! V_19 ) ;
return - V_55 ;
}
V_2 |= V_46 ;
if ( V_3 == 1 && ( V_11 -> V_29 & V_56 ) )
V_2 |= V_57 ;
if ( V_24 > 1 )
V_2 = F_28 ( V_2 , V_3 ) ;
V_2 |= V_51 & F_5 ( V_3 ) ;
F_22 ( V_23 , V_2 , V_24 , V_11 ) ;
return 0 ;
}
static int F_37 ( struct V_6 * V_7 , unsigned long V_50 ,
T_5 V_51 , T_4 V_14 , int V_27 ,
int V_3 , T_2 * V_23 )
{
struct V_25 * V_11 = & V_7 -> V_10 . V_11 ;
T_2 V_2 , * V_58 ;
int V_24 = V_14 >> F_38 ( V_3 ) ;
V_23 += F_34 ( V_50 , V_3 ) ;
if ( V_24 )
return F_32 ( V_7 , V_50 , V_51 , V_27 ,
V_3 , V_24 , V_23 ) ;
if ( F_35 ( V_3 == 2 ) )
return - V_54 ;
V_2 = * V_23 ;
if ( ! V_2 ) {
V_58 = F_7 ( V_3 + 1 , V_59 , V_7 ) ;
if ( ! V_58 )
return - V_60 ;
V_2 = F_2 ( V_58 ) | V_61 ;
if ( V_11 -> V_29 & V_56 )
V_2 |= V_62 ;
F_22 ( V_23 , V_2 , 1 , V_11 ) ;
} else {
V_58 = F_3 ( V_2 , V_3 ) ;
}
return F_37 ( V_7 , V_50 , V_51 , V_14 , V_27 , V_3 + 1 , V_58 ) ;
}
static int F_39 ( struct V_63 * V_64 , unsigned long V_50 ,
T_5 V_51 , T_4 V_14 , int V_27 )
{
struct V_6 * V_7 = F_40 ( V_64 ) ;
struct V_65 * V_10 = & V_7 -> V_10 ;
int V_66 ;
if ( ! ( V_27 & ( V_41 | V_35 ) ) )
return 0 ;
V_66 = F_37 ( V_7 , V_50 , V_51 , V_14 , V_27 , 1 , V_7 -> V_67 ) ;
if ( V_10 -> V_11 . V_29 & V_68 ) {
F_41 ( V_10 , V_50 , V_14 ,
F_33 ( 2 ) , false ) ;
F_42 ( V_10 ) ;
} else {
F_43 () ;
}
return V_66 ;
}
static void F_44 ( struct V_65 * V_10 )
{
struct V_6 * V_7 = F_45 ( V_10 ) ;
int V_26 ;
for ( V_26 = 0 ; V_26 < F_46 ( 1 ) ; V_26 ++ ) {
T_2 V_2 = V_7 -> V_67 [ V_26 ] ;
if ( F_4 ( V_2 , 1 ) )
F_19 ( F_3 ( V_2 , 1 ) , 2 , V_7 ) ;
}
F_19 ( V_7 -> V_67 , 1 , V_7 ) ;
F_47 ( V_7 -> V_17 ) ;
F_48 ( V_7 ) ;
}
static void F_49 ( struct V_6 * V_7 ,
unsigned long V_50 , int V_69 , int V_3 ,
T_2 * V_23 )
{
struct V_65 * V_10 = & V_7 -> V_10 ;
T_2 V_2 ;
T_4 V_14 = F_33 ( V_3 ) ;
int V_26 ;
V_23 -= V_69 & ( V_70 - 1 ) ;
V_2 = F_29 ( * V_23 , V_3 ) ;
for ( V_26 = 0 ; V_26 < V_70 ; V_26 ++ ) {
V_23 [ V_26 ] = V_2 ;
V_2 += V_14 ;
}
F_20 ( V_23 , V_70 , & V_10 -> V_11 ) ;
V_14 *= V_70 ;
F_41 ( V_10 , V_50 , V_14 , V_14 , true ) ;
F_42 ( V_10 ) ;
}
static int F_50 ( struct V_6 * V_7 ,
unsigned long V_50 , T_4 V_14 ,
T_2 * V_23 )
{
unsigned long V_71 , V_72 , V_73 ;
T_5 V_74 ;
T_2 V_15 = 0 ;
int V_27 = F_27 ( * V_23 , 1 ) ;
V_73 = F_33 ( 1 ) ;
V_71 = V_50 & F_5 ( 1 ) ;
V_72 = V_71 + F_33 ( 1 ) ;
V_74 = * V_23 & F_5 ( 1 ) ;
for (; V_71 < V_72 ; V_71 += V_14 , V_74 += V_14 ) {
T_2 * V_75 ;
if ( V_71 == V_50 )
continue;
V_75 = & V_15 - F_34 ( V_71 , 1 ) ;
if ( F_37 ( V_7 , V_71 , V_74 , V_14 , V_27 , 1 ,
V_75 ) < 0 ) {
if ( V_15 ) {
V_75 = F_3 ( V_15 , 1 ) ;
F_19 ( V_75 , 2 , V_7 ) ;
}
return 0 ;
}
}
F_22 ( V_23 , V_15 , 1 , & V_7 -> V_10 . V_11 ) ;
V_50 &= ~ ( V_73 - 1 ) ;
F_41 ( & V_7 -> V_10 , V_50 , V_73 , V_73 , true ) ;
return V_14 ;
}
static int F_36 ( struct V_6 * V_7 ,
unsigned long V_50 , T_4 V_14 , int V_3 ,
T_2 * V_23 )
{
T_2 V_2 [ V_70 ] ;
struct V_65 * V_10 = & V_7 -> V_10 ;
int V_69 , V_26 = 0 , V_24 = V_14 >> F_38 ( V_3 ) ;
if ( F_35 ( V_3 > 2 ) )
return 0 ;
V_69 = F_34 ( V_50 , V_3 ) ;
V_23 += V_69 ;
do {
if ( F_35 ( ! F_51 ( V_23 [ V_26 ] ) ) )
return 0 ;
V_2 [ V_26 ] = V_23 [ V_26 ] ;
} while ( ++ V_26 < V_24 );
if ( V_24 <= 1 && F_31 ( V_2 [ 0 ] , V_3 ) )
F_49 ( V_7 , V_50 , V_69 , V_3 , V_23 ) ;
if ( V_24 ) {
T_4 V_73 = F_33 ( V_3 ) ;
F_22 ( V_23 , 0 , V_24 , & V_10 -> V_11 ) ;
for ( V_26 = 0 ; V_26 < V_24 ; V_26 ++ ) {
if ( F_4 ( V_2 [ V_26 ] , V_3 ) ) {
F_41 ( V_10 , V_50 , V_73 ,
F_33 ( V_3 + 1 ) , false ) ;
F_42 ( V_10 ) ;
V_23 = F_3 ( V_2 [ V_26 ] , V_3 ) ;
F_19 ( V_23 , V_3 + 1 , V_7 ) ;
} else {
F_41 ( V_10 , V_50 , V_73 ,
V_73 , true ) ;
}
V_50 += V_73 ;
}
return V_14 ;
} else if ( V_3 == 1 && ! F_4 ( V_2 [ 0 ] , V_3 ) ) {
return F_50 ( V_7 , V_50 , V_14 , V_23 ) ;
}
V_23 = F_3 ( V_2 [ 0 ] , V_3 ) ;
return F_36 ( V_7 , V_50 , V_14 , V_3 + 1 , V_23 ) ;
}
static int F_52 ( struct V_63 * V_64 , unsigned long V_50 ,
T_4 V_14 )
{
struct V_6 * V_7 = F_40 ( V_64 ) ;
T_4 V_76 ;
V_76 = F_36 ( V_7 , V_50 , V_14 , 1 , V_7 -> V_67 ) ;
if ( V_76 )
F_42 ( & V_7 -> V_10 ) ;
return V_76 ;
}
static T_5 F_53 ( struct V_63 * V_64 ,
unsigned long V_50 )
{
struct V_6 * V_7 = F_40 ( V_64 ) ;
T_2 * V_23 = V_7 -> V_67 , V_2 ;
int V_3 = 0 ;
T_6 V_77 ;
do {
V_2 = V_23 [ F_34 ( V_50 , ++ V_3 ) ] ;
V_23 = F_3 ( V_2 , V_3 ) ;
} while ( F_4 ( V_2 , V_3 ) );
if ( ! F_51 ( V_2 ) )
return 0 ;
V_77 = F_5 ( V_3 ) ;
if ( F_31 ( V_2 , V_3 ) )
V_77 *= V_70 ;
return ( V_2 & V_77 ) | ( V_50 & ~ V_77 ) ;
}
static struct V_65 * F_54 ( struct V_25 * V_11 ,
void * V_78 )
{
struct V_6 * V_7 ;
if ( V_11 -> V_79 > V_80 || V_11 -> V_81 > V_80 )
return NULL ;
if ( V_11 -> V_29 & ~ ( V_56 |
V_30 |
V_68 ) )
return NULL ;
V_7 = F_55 ( sizeof( * V_7 ) , V_82 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_17 = F_56 ( L_2 ,
F_8 ( 2 ) ,
F_8 ( 2 ) ,
V_83 , NULL ) ;
if ( ! V_7 -> V_17 )
goto V_84;
V_7 -> V_10 . V_64 = (struct V_63 ) {
. V_85 = F_39 ,
. V_86 = F_52 ,
. V_87 = F_53 ,
} ;
V_7 -> V_10 . V_11 = * V_11 ;
V_11 -> V_88 &= V_89 | V_90 | V_91 | V_92 ;
V_11 -> V_93 . V_94 = V_95 ;
V_11 -> V_93 . V_96 = F_57 ( 1 , V_97 ) |
F_57 ( 4 , V_98 ) |
F_57 ( 7 , V_98 ) |
V_99 | V_100 |
V_101 | F_58 ( 7 ) ;
V_11 -> V_93 . V_102 = F_59 ( 7 , V_103 ) |
F_60 ( 7 , V_103 ) ;
V_7 -> V_67 = F_7 ( 1 , V_82 , V_7 ) ;
if ( ! V_7 -> V_67 )
goto V_84;
F_43 () ;
V_11 -> V_93 . V_104 [ 0 ] = F_2 ( V_7 -> V_67 ) |
V_105 | V_106 |
F_61 ( V_103 ) |
F_62 ( V_103 ) ;
V_11 -> V_93 . V_104 [ 1 ] = 0 ;
return & V_7 -> V_10 ;
V_84:
F_47 ( V_7 -> V_17 ) ;
F_48 ( V_7 ) ;
return NULL ;
}
static void F_63 ( void * V_78 )
{
F_35 ( V_78 != V_107 ) ;
}
static void F_64 ( unsigned long V_50 , T_4 V_14 ,
T_4 V_108 , bool V_109 , void * V_78 )
{
F_35 ( V_78 != V_107 ) ;
F_35 ( ! ( V_14 & V_107 -> V_88 ) ) ;
}
static void F_65 ( void * V_78 )
{
F_35 ( V_78 != V_107 ) ;
}
static int T_7 F_66 ( void )
{
struct V_63 * V_64 ;
struct V_25 V_11 = {
. V_110 = & V_111 ,
. V_81 = 32 ,
. V_79 = 32 ,
. V_29 = V_56 ,
. V_88 = V_89 | V_90 | V_91 | V_92 ,
} ;
unsigned int V_50 , V_14 , V_112 ;
unsigned int V_26 , V_113 = 0 ;
V_19 = true ;
V_107 = & V_11 ;
V_64 = F_67 ( V_114 , & V_11 , & V_11 ) ;
if ( ! V_64 ) {
F_68 ( L_3 ) ;
return - V_54 ;
}
if ( V_64 -> V_87 ( V_64 , 42 ) )
return F_69 ( V_64 ) ;
if ( V_64 -> V_87 ( V_64 , V_115 + 42 ) )
return F_69 ( V_64 ) ;
if ( V_64 -> V_87 ( V_64 , V_116 + 42 ) )
return F_69 ( V_64 ) ;
V_50 = 0 ;
V_26 = F_70 ( & V_11 . V_88 , V_117 ) ;
while ( V_26 != V_117 ) {
V_14 = 1UL << V_26 ;
if ( V_64 -> V_85 ( V_64 , V_50 , V_50 , V_14 , V_41 |
V_35 |
V_37 |
V_38 ) )
return F_69 ( V_64 ) ;
if ( ! V_64 -> V_85 ( V_64 , V_50 , V_50 + V_14 , V_14 ,
V_41 | V_37 ) )
return F_69 ( V_64 ) ;
if ( V_64 -> V_87 ( V_64 , V_50 + 42 ) != ( V_50 + 42 ) )
return F_69 ( V_64 ) ;
V_50 += V_92 ;
V_26 ++ ;
V_26 = F_71 ( & V_11 . V_88 , V_117 , V_26 ) ;
V_113 ++ ;
}
V_26 = 1 ;
V_14 = 1UL << F_72 ( V_11 . V_88 ) ;
while ( V_26 < V_113 ) {
V_112 = V_26 * V_92 ;
if ( V_64 -> V_86 ( V_64 , V_112 + V_14 , V_14 ) != V_14 )
return F_69 ( V_64 ) ;
if ( V_64 -> V_85 ( V_64 , V_112 + V_14 , V_14 , V_14 , V_41 ) )
return F_69 ( V_64 ) ;
if ( V_64 -> V_87 ( V_64 , V_112 + V_14 + 42 )
!= ( V_14 + 42 ) )
return F_69 ( V_64 ) ;
V_26 ++ ;
}
V_50 = 0 ;
V_26 = F_70 ( & V_11 . V_88 , V_117 ) ;
while ( V_26 != V_117 ) {
V_14 = 1UL << V_26 ;
if ( V_64 -> V_86 ( V_64 , V_50 , V_14 ) != V_14 )
return F_69 ( V_64 ) ;
if ( V_64 -> V_87 ( V_64 , V_50 + 42 ) )
return F_69 ( V_64 ) ;
if ( V_64 -> V_85 ( V_64 , V_50 , V_50 , V_14 , V_35 ) )
return F_69 ( V_64 ) ;
if ( V_64 -> V_87 ( V_64 , V_50 + 42 ) != ( V_50 + 42 ) )
return F_69 ( V_64 ) ;
V_50 += V_92 ;
V_26 ++ ;
V_26 = F_71 ( & V_11 . V_88 , V_117 , V_26 ) ;
}
F_73 ( V_64 ) ;
V_19 = false ;
F_74 ( L_4 ) ;
return 0 ;
}
