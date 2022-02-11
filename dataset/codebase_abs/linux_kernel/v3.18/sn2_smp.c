static inline unsigned long F_1 ( void )
{
volatile unsigned long * V_1 ;
unsigned long V_2 , V_3 ;
V_1 = V_4 -> V_5 ;
V_2 = V_4 -> V_6 ;
do {
F_2 () ;
} while ( ( ( V_3 = * V_1 ) & V_7 ) != V_2 );
return ( V_3 & V_8 ) != 0 ;
}
void F_3 ( struct V_9 * V_10 )
{
T_1 * V_11 = F_4 ( F_5 ( V_10 ) -> V_12 ) ;
volatile unsigned long * V_13 = V_11 -> V_5 ;
unsigned long V_14 = V_11 -> V_6 ;
while ( F_6 ( ( * V_13 & V_7 )
!= V_14 ) )
F_2 () ;
}
void F_7 ( struct V_15 * V_16 )
{
if ( V_16 == V_17 -> V_16 && V_16 && F_8 ( & V_16 -> V_18 ) == 1 )
F_9 ( V_16 ) ;
}
static void
F_10 ( struct V_15 * V_16 )
{
unsigned long V_19 ;
V_19 = F_11 () ;
F_12 ( * F_13 ( V_16 ) ) ;
V_19 = F_11 () - V_19 ;
F_14 ( V_20 . V_21 , V_19 ) ;
F_15 ( V_20 . V_22 ) ;
}
void
F_16 ( struct V_15 * V_16 , unsigned long V_23 ,
unsigned long V_24 , unsigned long V_25 )
{
int V_26 , V_27 , V_28 , V_29 , V_30 , V_31 , V_32 = 0 , V_33 ;
int V_34 = ( V_16 == V_17 -> V_35 && V_16 == V_17 -> V_16 ) ;
int V_36 ;
volatile unsigned long * V_37 , * V_38 ;
unsigned long V_19 , V_39 , V_40 , V_41 = 0 , V_42 = 0 , V_43 , V_44 = 0 ;
short V_45 [ V_46 ] , V_47 ;
T_2 V_48 ;
int V_49 , V_50 , V_51 , V_52 = V_53 ;
if ( V_52 > 2 ) {
F_10 ( V_16 ) ;
return;
}
F_17 ( V_48 ) ;
V_26 = 0 ;
F_18 (cpu, mm_cpumask(mm)) {
V_29 = F_19 ( V_31 ) ;
F_20 ( V_29 , V_48 ) ;
V_32 = V_31 ;
V_26 ++ ;
}
if ( V_26 == 0 )
return;
F_21 () ;
if ( F_22 ( V_26 == 1 && V_32 == F_23 () && V_34 ) ) {
do {
F_24 ( V_23 , V_25 << 2 ) ;
V_23 += ( 1UL << V_25 ) ;
} while ( V_23 < V_24 );
F_25 () ;
F_15 ( V_20 . V_54 ) ;
F_26 () ;
return;
}
if ( F_8 ( & V_16 -> V_18 ) == 1 && V_34 ) {
F_9 ( V_16 ) ;
F_15 ( V_20 . V_55 ) ;
F_26 () ;
return;
}
if ( V_52 == 2 ) {
F_10 ( V_16 ) ;
F_26 () ;
return;
}
V_19 = F_11 () ;
V_47 = 0 ;
F_27 (cnode, nodes_flushed)
V_45 [ V_47 ++ ] = F_28 ( V_29 ) ;
V_43 = ( V_16 -> V_56 << 3 ) | F_29 ( V_23 ) ;
V_28 = F_30 () ;
if ( V_28 ) {
V_41 = ( 1UL << V_57 ) |
( V_25 << V_58 ) |
( V_43 << V_59 ) |
( 1UL << V_60 ) ;
V_37 = ( long * ) F_31 ( 0 , V_61 ) ;
V_38 = ( long * ) F_31 ( 0 , V_62 ) ;
} else {
V_41 = ( 1UL << V_63 ) |
( V_25 << V_64 ) |
( 1UL << V_65 ) ;
V_37 = ( long * ) F_31 ( 0 , V_66 +
( V_43 << V_67 ) ) ;
V_38 = NULL ;
}
V_30 = F_32 () ;
V_36 = F_33 ( V_28 ) ;
V_50 = F_34 ( V_28 ) ;
V_19 = F_11 () ;
F_35 ( F_36 ( V_28 ) , V_40 ) ;
V_39 = F_11 () ;
F_14 ( V_20 . V_68 , V_39 - V_19 ) ;
F_15 ( V_20 . V_69 ) ;
F_14 ( V_20 . V_48 , V_47 ) ;
if ( ! V_34 )
F_15 ( V_20 . V_70 ) ;
if ( V_36 && ! V_34 ) {
V_44 = F_37 ( V_23 ) ;
F_38 ( V_23 , ( V_44 & 0xff ) | ( V_43 << 8 ) ) ;
F_39 () ;
}
F_1 () ;
do {
if ( V_28 )
V_42 = V_23 | ( 1UL << V_71 ) ;
else
V_41 = ( V_41 & ~ V_72 ) | ( V_23 & V_72 ) ;
V_51 = 0 ;
V_49 = 0 ;
for ( V_27 = 0 , V_26 = 0 ; V_26 < V_47 ; V_26 ++ ) {
V_33 = V_45 [ V_26 ] ;
if ( V_36 && F_6 ( V_33 == V_30 ) ) {
F_40 ( V_23 , V_25 << 2 ) ;
F_25 () ;
} else {
V_37 = F_41 ( V_33 , V_37 ) ;
if ( V_38 )
V_38 = F_41 ( V_33 , V_38 ) ;
F_42 ( V_37 , V_41 , V_38 , V_42 ) ;
V_49 ++ ;
}
if ( V_49 >= V_50 || V_26 == ( V_47 - 1 ) ) {
if ( ( V_51 = F_1 () ) ) {
if ( V_52 == 1 )
goto V_73;
F_43 ( V_45 , V_27 , V_26 , V_30 , V_37 , V_41 , V_38 , V_42 ) ;
if ( F_44 () )
V_50 = 1 ;
}
V_49 = 0 ;
V_27 = V_26 + 1 ;
}
}
V_23 += ( 1UL << V_25 ) ;
} while ( V_23 < V_24 );
V_73:
V_39 = F_11 () - V_39 ;
F_14 ( V_20 . V_74 , V_39 ) ;
if ( V_39 > F_45 ( V_20 . V_75 ) )
F_46 ( V_20 . V_75 , V_39 ) ;
if ( V_44 ) {
F_38 ( V_23 , V_44 ) ;
F_39 () ;
}
F_47 ( F_36 ( V_28 ) , V_40 ) ;
if ( V_52 == 1 && V_51 ) {
F_15 ( V_20 . V_76 ) ;
F_10 ( V_16 ) ;
}
F_26 () ;
}
void
F_43 ( short * V_45 , short V_77 , short V_78 , int V_30 ,
volatile unsigned long * V_37 , unsigned long V_41 ,
volatile unsigned long * V_38 , unsigned long V_42 )
{
short V_33 , V_26 ;
unsigned long * V_1 , V_2 , V_79 ;
F_15 ( V_20 . V_76 ) ;
V_1 = ( unsigned long * ) V_4 -> V_5 ;
V_2 = V_4 -> V_6 ;
for ( V_26 = V_77 ; V_26 <= V_78 ; V_26 ++ ) {
V_33 = V_45 [ V_26 ] ;
if ( F_33 ( F_30 () ) && V_33 == V_30 )
continue;
V_37 = F_41 ( V_33 , V_37 ) ;
if ( V_38 )
V_38 = F_41 ( V_33 , V_38 ) ;
V_79 = F_48 ( V_37 , V_41 , V_38 , V_42 , V_1 , V_2 ) ;
F_14 ( V_20 . V_80 , V_79 ) ;
}
}
void F_49 ( int V_33 , long V_81 , int V_82 , int V_83 )
{
long V_14 ;
unsigned long V_40 = 0 ;
volatile long * V_84 ;
V_84 = ( long * ) F_31 ( V_33 , V_85 ) ;
V_14 = ( 1UL << V_86 ) |
( V_81 << V_87 ) |
( ( long ) V_83 << V_88 ) |
( ( long ) V_82 << V_89 ) |
( 0x000feeUL << V_90 ) ;
F_50 () ;
if ( F_51 () ) {
F_35 ( & V_91 , V_40 ) ;
}
F_52 ( V_84 , V_14 ) ;
if ( F_51 () ) {
F_1 () ;
F_47 ( & V_91 , V_40 ) ;
}
}
void F_53 ( int V_92 , int V_82 , int V_83 , int V_93 )
{
long V_81 ;
int V_33 ;
V_81 = F_54 ( V_92 ) ;
V_33 = F_55 ( V_92 ) ;
if ( F_6 ( V_33 == - 1 ) )
F_56 ( V_81 , & V_33 , NULL , NULL ) ;
F_49 ( V_33 , V_81 , V_82 , V_83 ) ;
}
bool F_57 ( int V_31 )
{
if ( F_58 () && F_59 ( V_94 ) ) {
if ( V_31 != 0 )
return true ;
else
F_60 ( V_95
L_1 ) ;
} else
F_60 ( V_95
L_2 ) ;
return false ;
}
static void * F_61 ( struct V_96 * V_97 , T_3 * V_98 )
{
if ( * V_98 < V_99 )
return V_98 ;
return NULL ;
}
static void * F_62 ( struct V_96 * V_97 , void * V_100 , T_3 * V_98 )
{
( * V_98 ) ++ ;
if ( * V_98 < V_99 )
return V_98 ;
return NULL ;
}
static void F_63 ( struct V_96 * V_97 , void * V_100 )
{
}
static int F_64 ( struct V_96 * V_97 , void * V_100 )
{
struct V_101 * V_102 ;
int V_31 ;
V_31 = * ( T_3 * ) V_100 ;
if ( ! V_31 ) {
F_65 ( V_97 ,
L_3 ) ;
F_65 ( V_97 , L_4 , V_103 , V_53 ) ;
}
if ( V_31 < V_99 && F_66 ( V_31 ) ) {
V_102 = & F_67 ( V_20 , V_31 ) ;
F_65 ( V_97 , L_5 , V_31 , V_102 -> V_54 ,
V_102 -> V_55 , V_102 -> V_69 , V_102 -> V_48 ,
V_102 -> V_76 ,
1000 * V_102 -> V_68 / F_67 ( V_104 , V_31 ) . V_105 ,
1000 * V_102 -> V_74 / F_67 ( V_104 , V_31 ) . V_105 ,
1000 * V_102 -> V_75 / F_67 ( V_104 , V_31 ) . V_105 ,
V_102 -> V_70 ,
V_102 -> V_80 ,
V_102 -> V_22 ,
1000 * V_102 -> V_21 / F_67 ( V_104 , V_31 ) . V_105 ) ;
}
return 0 ;
}
static T_4 F_68 ( struct V_97 * V_97 , const char T_5 * V_106 , T_6 V_107 , T_3 * V_100 )
{
int V_31 ;
char V_108 [ 64 ] ;
if ( V_107 == 0 || V_107 > sizeof( V_108 ) )
return - V_109 ;
if ( F_69 ( V_108 , V_106 , V_107 ) )
return - V_110 ;
V_108 [ V_107 - 1 ] = '\0' ;
V_53 = F_70 ( V_108 , NULL , 0 ) ;
F_71 (cpu)
memset ( & F_67 ( V_20 , V_31 ) , 0 , sizeof( struct V_101 ) ) ;
return V_107 ;
}
static int F_72 ( struct V_111 * V_111 , struct V_97 * V_97 )
{
return F_73 ( V_97 , & V_112 ) ;
}
static int T_7 F_74 ( void )
{
if ( ! F_75 ( L_6 ) )
return 0 ;
V_113 = F_76 ( V_114 , 0444 ,
NULL , & V_115 ) ;
if ( ! V_113 ) {
F_60 ( V_116 L_7 , V_114 ) ;
return - V_109 ;
}
F_77 ( & V_91 ) ;
return 0 ;
}
static void T_8 F_78 ( void )
{
F_79 ( V_114 , NULL ) ;
}
