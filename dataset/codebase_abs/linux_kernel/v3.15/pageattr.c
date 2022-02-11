void F_1 ( int V_1 , unsigned long V_2 )
{
F_2 ( & V_3 ) ;
V_4 [ V_1 ] += V_2 ;
F_3 ( & V_3 ) ;
}
static void F_4 ( int V_1 )
{
V_4 [ V_1 ] -- ;
V_4 [ V_1 - 1 ] += V_5 ;
}
void F_5 ( struct V_6 * V_7 )
{
F_6 ( V_7 , L_1 ,
V_4 [ V_8 ] << 2 ) ;
#if F_7 ( V_9 ) || F_7 ( V_10 )
F_6 ( V_7 , L_2 ,
V_4 [ V_11 ] << 11 ) ;
#else
F_6 ( V_7 , L_3 ,
V_4 [ V_11 ] << 12 ) ;
#endif
#ifdef V_9
if ( V_12 )
F_6 ( V_7 , L_4 ,
V_4 [ V_13 ] << 20 ) ;
#endif
}
static inline void F_4 ( int V_1 ) { }
static inline unsigned long F_8 ( void )
{
return F_9 ( V_14 ) >> V_15 ;
}
static inline unsigned long F_10 ( void )
{
return F_9 ( F_11 ( V_16 , V_17 ) ) >> V_15 ;
}
static inline int
F_12 ( unsigned long V_18 , unsigned long V_19 , unsigned long V_20 )
{
return V_18 >= V_19 && V_18 < V_20 ;
}
void F_13 ( void * V_21 , unsigned int V_22 )
{
void * V_23 = V_21 + V_22 - 1 ;
F_14 () ;
for (; V_21 < V_23 ; V_21 += V_24 . V_25 )
F_15 ( V_21 ) ;
F_15 ( V_23 ) ;
F_14 () ;
}
static void F_16 ( void * V_26 )
{
unsigned long V_27 = ( unsigned long ) V_26 ;
F_17 () ;
if ( V_27 && V_24 . V_28 >= 4 )
F_18 () ;
}
static void F_19 ( unsigned long V_27 )
{
F_20 ( F_21 () ) ;
F_22 ( F_16 , ( void * ) V_27 , 1 ) ;
}
static void F_23 ( void * V_26 )
{
F_17 () ;
}
static void F_24 ( unsigned long V_19 , int V_29 , int V_27 )
{
unsigned int V_30 , V_1 ;
unsigned long V_18 ;
F_20 ( F_21 () ) ;
F_25 ( F_26 ( V_19 ) != V_19 ) ;
F_22 ( F_23 , NULL , 1 ) ;
if ( ! V_27 )
return;
for ( V_30 = 0 , V_18 = V_19 ; V_30 < V_29 ; V_30 ++ , V_18 += V_31 ) {
T_1 * V_32 = F_27 ( V_18 , & V_1 ) ;
if ( V_32 && ( F_28 ( * V_32 ) & V_33 ) )
F_13 ( ( void * ) V_18 , V_31 ) ;
}
}
static void F_29 ( unsigned long * V_19 , int V_29 , int V_27 ,
int V_34 , struct V_35 * * V_2 )
{
unsigned int V_30 , V_1 ;
unsigned long V_36 = V_27 && V_29 >= 1024 ;
F_20 ( F_21 () ) ;
F_22 ( F_16 , ( void * ) V_36 , 1 ) ;
if ( ! V_27 || V_36 )
return;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
unsigned long V_18 ;
T_1 * V_32 ;
if ( V_34 & V_37 )
V_18 = ( unsigned long ) F_30 ( V_2 [ V_30 ] ) ;
else
V_18 = V_19 [ V_30 ] ;
V_32 = F_27 ( V_18 , & V_1 ) ;
if ( V_32 && ( F_28 ( * V_32 ) & V_33 ) )
F_13 ( ( void * ) V_18 , V_31 ) ;
}
}
static inline T_2 F_31 ( T_2 V_38 , unsigned long V_39 ,
unsigned long V_40 )
{
T_2 V_41 = F_32 ( 0 ) ;
#ifdef F_33
if ( V_42 && F_12 ( V_40 , V_43 >> V_15 , V_44 >> V_15 ) )
F_34 ( V_41 ) |= V_45 ;
#endif
if ( F_12 ( V_39 , ( unsigned long ) V_14 , ( unsigned long ) V_46 ) )
F_34 ( V_41 ) |= V_45 ;
if ( F_12 ( V_40 , F_9 ( V_47 ) >> V_15 ,
F_9 ( V_48 ) >> V_15 ) )
F_34 ( V_41 ) |= V_49 ;
#if F_7 ( V_9 ) && F_7 ( V_50 )
if ( V_51 &&
F_12 ( V_39 , ( unsigned long ) V_14 ,
( unsigned long ) V_52 ) ) {
unsigned int V_1 ;
if ( F_27 ( V_39 , & V_1 ) && ( V_1 != V_8 ) )
F_34 ( V_41 ) |= V_49 ;
}
#endif
V_38 = F_32 ( F_34 ( V_38 ) & ~ F_34 ( V_41 ) ) ;
return V_38 ;
}
T_1 * F_35 ( T_3 * V_53 , unsigned long V_39 ,
unsigned int * V_1 )
{
T_4 * V_54 ;
T_5 * V_55 ;
* V_1 = V_56 ;
if ( F_36 ( * V_53 ) )
return NULL ;
V_54 = F_37 ( V_53 , V_39 ) ;
if ( F_38 ( * V_54 ) )
return NULL ;
* V_1 = V_13 ;
if ( F_39 ( * V_54 ) || ! F_40 ( * V_54 ) )
return ( T_1 * ) V_54 ;
V_55 = F_41 ( V_54 , V_39 ) ;
if ( F_42 ( * V_55 ) )
return NULL ;
* V_1 = V_11 ;
if ( F_43 ( * V_55 ) || ! F_44 ( * V_55 ) )
return ( T_1 * ) V_55 ;
* V_1 = V_8 ;
return F_45 ( V_55 , V_39 ) ;
}
T_1 * F_27 ( unsigned long V_39 , unsigned int * V_1 )
{
return F_35 ( F_46 ( V_39 ) , V_39 , V_1 ) ;
}
static T_1 * F_47 ( struct V_57 * V_58 , unsigned long V_39 ,
unsigned int * V_1 )
{
if ( V_58 -> V_53 )
return F_35 ( V_58 -> V_53 + F_48 ( V_39 ) ,
V_39 , V_1 ) ;
return F_27 ( V_39 , V_1 ) ;
}
T_6 F_49 ( void * V_59 )
{
unsigned long V_60 = ( unsigned long ) V_59 ;
T_6 V_61 ;
unsigned long V_62 ;
enum V_63 V_1 ;
unsigned long V_64 ;
unsigned long V_65 ;
T_1 * V_32 ;
V_32 = F_27 ( V_60 , & V_1 ) ;
F_20 ( ! V_32 ) ;
V_64 = F_50 ( V_1 ) ;
V_65 = F_51 ( V_1 ) ;
V_62 = V_60 & ~ V_65 ;
V_61 = F_52 ( * V_32 ) << V_15 ;
return ( V_61 | V_62 ) ;
}
static void F_53 ( T_1 * V_66 , unsigned long V_39 , T_1 V_32 )
{
F_54 ( V_66 , V_32 ) ;
#ifdef F_55
if ( ! V_67 ) {
struct V_35 * V_35 ;
F_56 (page, &pgd_list, lru) {
T_3 * V_53 ;
T_4 * V_54 ;
T_5 * V_55 ;
V_53 = ( T_3 * ) F_30 ( V_35 ) + F_48 ( V_39 ) ;
V_54 = F_37 ( V_53 , V_39 ) ;
V_55 = F_41 ( V_54 , V_39 ) ;
F_54 ( ( T_1 * ) V_55 , V_32 ) ;
}
}
#endif
}
static int
F_57 ( T_1 * V_66 , unsigned long V_39 ,
struct V_57 * V_58 )
{
unsigned long V_68 , V_29 , V_65 , V_64 , V_18 , V_40 ;
T_1 V_69 , V_70 , * V_71 ;
T_2 V_72 , V_73 , V_74 ;
int V_30 , V_75 = 1 ;
enum V_63 V_1 ;
if ( V_58 -> V_76 )
return 1 ;
F_2 ( & V_3 ) ;
V_71 = F_47 ( V_58 , V_39 , & V_1 ) ;
if ( V_71 != V_66 )
goto V_77;
switch ( V_1 ) {
case V_11 :
#ifdef V_9
case V_13 :
#endif
V_64 = F_50 ( V_1 ) ;
V_65 = F_51 ( V_1 ) ;
break;
default:
V_75 = - V_78 ;
goto V_77;
}
V_68 = ( V_39 + V_64 ) & V_65 ;
V_29 = ( V_68 - V_39 ) >> V_15 ;
if ( V_29 < V_58 -> V_29 )
V_58 -> V_29 = V_29 ;
V_70 = * V_66 ;
V_72 = V_74 = F_58 ( V_70 ) ;
F_34 ( V_74 ) &= ~ F_34 ( V_58 -> V_79 ) ;
F_34 ( V_74 ) |= F_34 ( V_58 -> V_80 ) ;
if ( F_34 ( V_74 ) & V_33 )
F_34 ( V_74 ) |= V_81 | V_82 ;
else
F_34 ( V_74 ) &= ~ ( V_81 | V_82 ) ;
V_74 = F_59 ( V_74 ) ;
V_40 = F_52 ( V_70 ) + ( ( V_39 & ( V_64 - 1 ) ) >> V_15 ) ;
V_58 -> V_40 = V_40 ;
V_73 = F_31 ( V_74 , V_39 , V_40 ) ;
V_18 = V_39 & V_65 ;
V_40 = F_52 ( V_70 ) ;
for ( V_30 = 0 ; V_30 < ( V_64 >> V_15 ) ; V_30 ++ , V_18 += V_31 , V_40 ++ ) {
T_2 V_83 = F_31 ( V_74 , V_18 , V_40 ) ;
if ( F_34 ( V_83 ) != F_34 ( V_73 ) )
goto V_77;
}
if ( F_34 ( V_73 ) == F_34 ( V_72 ) ) {
V_75 = 0 ;
goto V_77;
}
if ( V_39 == ( V_39 & V_65 ) && V_58 -> V_29 == ( V_64 >> V_15 ) ) {
V_69 = F_60 ( F_52 ( V_70 ) , V_73 ) ;
F_53 ( V_66 , V_39 , V_69 ) ;
V_58 -> V_84 |= V_85 ;
V_75 = 0 ;
}
V_77:
F_3 ( & V_3 ) ;
return V_75 ;
}
static int
F_61 ( struct V_57 * V_58 , T_1 * V_66 , unsigned long V_39 ,
struct V_35 * V_86 )
{
T_1 * V_87 = ( T_1 * ) F_30 ( V_86 ) ;
unsigned long V_40 , V_88 = 1 ;
unsigned int V_30 , V_1 ;
T_1 * V_71 ;
T_2 V_89 ;
F_2 ( & V_3 ) ;
V_71 = F_47 ( V_58 , V_39 , & V_1 ) ;
if ( V_71 != V_66 ) {
F_3 ( & V_3 ) ;
return 1 ;
}
F_62 ( & V_90 , F_63 ( V_86 ) ) ;
V_89 = F_58 ( F_64 ( * V_66 ) ) ;
F_65 ( F_34 ( V_89 ) & V_91 ) ;
#ifdef V_9
if ( V_1 == V_13 ) {
V_88 = V_92 >> V_15 ;
if ( F_34 ( V_89 ) & V_33 )
F_34 ( V_89 ) |= V_81 ;
else
F_34 ( V_89 ) &= ~ V_81 ;
}
#endif
if ( F_34 ( V_89 ) & V_33 )
F_34 ( V_89 ) |= V_82 ;
else
F_34 ( V_89 ) &= ~ V_82 ;
V_40 = F_52 ( * V_66 ) ;
for ( V_30 = 0 ; V_30 < V_5 ; V_30 ++ , V_40 += V_88 )
F_66 ( & V_87 [ V_30 ] , F_60 ( V_40 , F_59 ( V_89 ) ) ) ;
if ( F_67 ( F_68 ( F_69 ( V_39 ) ) ,
F_68 ( F_69 ( V_39 ) ) + 1 ) )
F_4 ( V_1 ) ;
F_53 ( V_66 , V_39 , F_70 ( V_86 , F_32 ( V_93 ) ) ) ;
F_17 () ;
F_3 ( & V_3 ) ;
return 0 ;
}
static int F_71 ( struct V_57 * V_58 , T_1 * V_66 ,
unsigned long V_39 )
{
struct V_35 * V_86 ;
if ( ! V_94 )
F_3 ( & V_95 ) ;
V_86 = F_72 ( V_96 | V_97 , 0 ) ;
if ( ! V_94 )
F_2 ( & V_95 ) ;
if ( ! V_86 )
return - V_98 ;
if ( F_61 ( V_58 , V_66 , V_39 , V_86 ) )
F_73 ( V_86 ) ;
return 0 ;
}
static bool F_74 ( T_1 * V_32 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_5 ; V_30 ++ )
if ( ! F_75 ( V_32 [ V_30 ] ) )
return false ;
F_76 ( ( unsigned long ) V_32 ) ;
return true ;
}
static bool F_77 ( T_5 * V_55 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_99 ; V_30 ++ )
if ( ! F_42 ( V_55 [ V_30 ] ) )
return false ;
F_76 ( ( unsigned long ) V_55 ) ;
return true ;
}
static bool F_78 ( T_4 * V_54 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_100 ; V_30 ++ )
if ( ! F_38 ( V_54 [ V_30 ] ) )
return false ;
F_76 ( ( unsigned long ) V_54 ) ;
return true ;
}
static bool F_79 ( T_5 * V_55 , unsigned long V_19 , unsigned long V_20 )
{
T_1 * V_32 = F_45 ( V_55 , V_19 ) ;
while ( V_19 < V_20 ) {
F_66 ( V_32 , F_80 ( 0 ) ) ;
V_19 += V_31 ;
V_32 ++ ;
}
if ( F_74 ( ( T_1 * ) F_81 ( * V_55 ) ) ) {
F_82 ( V_55 ) ;
return true ;
}
return false ;
}
static void F_83 ( T_4 * V_54 , T_5 * V_55 ,
unsigned long V_19 , unsigned long V_20 )
{
if ( F_79 ( V_55 , V_19 , V_20 ) )
if ( F_77 ( ( T_5 * ) F_84 ( * V_54 ) ) )
F_85 ( V_54 ) ;
}
static void F_86 ( T_4 * V_54 , unsigned long V_19 , unsigned long V_20 )
{
T_5 * V_55 = F_41 ( V_54 , V_19 ) ;
if ( V_19 & ( V_17 - 1 ) ) {
unsigned long V_101 = ( V_19 + V_17 ) & V_102 ;
unsigned long V_103 = F_87 (unsigned long, end, next_page) ;
F_83 ( V_54 , V_55 , V_19 , V_103 ) ;
V_19 = V_103 ;
V_55 ++ ;
}
while ( V_20 - V_19 >= V_17 ) {
if ( F_43 ( * V_55 ) )
F_82 ( V_55 ) ;
else
F_83 ( V_54 , V_55 , V_19 , V_19 + V_17 ) ;
V_19 += V_17 ;
V_55 ++ ;
}
if ( V_19 < V_20 )
return F_83 ( V_54 , V_55 , V_19 , V_20 ) ;
if ( ! F_38 ( * V_54 ) )
if ( F_77 ( ( T_5 * ) F_84 ( * V_54 ) ) )
F_85 ( V_54 ) ;
}
static void F_88 ( T_3 * V_53 , unsigned long V_19 , unsigned long V_20 )
{
T_4 * V_54 = F_37 ( V_53 , V_19 ) ;
if ( V_19 & ( V_104 - 1 ) ) {
unsigned long V_101 = ( V_19 + V_104 ) & V_105 ;
unsigned long V_103 = F_87 (unsigned long, end, next_page) ;
F_86 ( V_54 , V_19 , V_103 ) ;
V_19 = V_103 ;
V_54 ++ ;
}
while ( V_20 - V_19 >= V_104 ) {
if ( F_39 ( * V_54 ) )
F_85 ( V_54 ) ;
else
F_86 ( V_54 , V_19 , V_19 + V_104 ) ;
V_19 += V_104 ;
V_54 ++ ;
}
if ( V_19 < V_20 )
F_86 ( V_54 , V_19 , V_20 ) ;
}
static void F_89 ( T_3 * V_106 , unsigned long V_18 , unsigned long V_20 )
{
T_3 * V_107 = V_106 + F_48 ( V_18 ) ;
F_88 ( V_107 , V_18 , V_20 ) ;
if ( F_78 ( ( T_4 * ) F_90 ( * V_107 ) ) )
F_91 ( V_107 ) ;
}
static int F_92 ( T_5 * V_55 )
{
T_1 * V_32 = ( T_1 * ) F_93 ( V_96 | V_97 ) ;
if ( ! V_32 )
return - 1 ;
F_94 ( V_55 , F_95 ( F_69 ( V_32 ) | V_93 ) ) ;
return 0 ;
}
static int F_96 ( T_4 * V_54 )
{
T_5 * V_55 = ( T_5 * ) F_93 ( V_96 | V_97 ) ;
if ( ! V_55 )
return - 1 ;
F_97 ( V_54 , F_98 ( F_69 ( V_55 ) | V_93 ) ) ;
return 0 ;
}
static void F_99 ( struct V_57 * V_58 ,
unsigned long V_19 , unsigned long V_20 ,
unsigned V_108 , T_5 * V_55 , T_2 V_109 )
{
T_1 * V_32 ;
V_32 = F_45 ( V_55 , V_19 ) ;
while ( V_108 -- && V_19 < V_20 ) {
if ( ! ( F_34 ( V_109 ) & V_45 ) )
V_58 -> V_40 &= ~ V_45 ;
F_66 ( V_32 , F_60 ( V_58 -> V_40 >> V_15 , V_109 ) ) ;
V_19 += V_31 ;
V_58 -> V_40 += V_31 ;
V_32 ++ ;
}
}
static int F_100 ( struct V_57 * V_58 ,
unsigned long V_19 , unsigned long V_20 ,
unsigned V_108 , T_4 * V_54 , T_2 V_109 )
{
unsigned int V_110 = 0 ;
T_5 * V_55 ;
if ( V_19 & ( V_17 - 1 ) ) {
unsigned long V_103 = V_19 + ( V_108 << V_15 ) ;
unsigned long V_101 = ( V_19 + V_17 ) & V_102 ;
V_103 = F_87 (unsigned long, pre_end, next_page) ;
V_110 = ( V_103 - V_19 ) >> V_15 ;
V_110 = F_87 (unsigned int, num_pages, cur_pages) ;
V_55 = F_41 ( V_54 , V_19 ) ;
if ( F_42 ( * V_55 ) )
if ( F_92 ( V_55 ) )
return - 1 ;
F_99 ( V_58 , V_19 , V_103 , V_110 , V_55 , V_109 ) ;
V_19 = V_103 ;
}
if ( V_108 == V_110 )
return V_110 ;
while ( V_20 - V_19 >= V_17 ) {
if ( F_38 ( * V_54 ) )
if ( F_96 ( V_54 ) )
return - 1 ;
V_55 = F_41 ( V_54 , V_19 ) ;
F_94 ( V_55 , F_95 ( V_58 -> V_40 | V_81 | F_101 ( V_109 ) ) ) ;
V_19 += V_17 ;
V_58 -> V_40 += V_17 ;
V_110 += V_17 >> V_15 ;
}
if ( V_19 < V_20 ) {
V_55 = F_41 ( V_54 , V_19 ) ;
if ( F_42 ( * V_55 ) )
if ( F_92 ( V_55 ) )
return - 1 ;
F_99 ( V_58 , V_19 , V_20 , V_108 - V_110 ,
V_55 , V_109 ) ;
}
return V_108 ;
}
static int F_102 ( struct V_57 * V_58 , unsigned long V_19 , T_3 * V_53 ,
T_2 V_109 )
{
T_4 * V_54 ;
unsigned long V_20 ;
int V_110 = 0 ;
V_20 = V_19 + ( V_58 -> V_29 << V_15 ) ;
if ( V_19 & ( V_104 - 1 ) ) {
unsigned long V_103 ;
unsigned long V_101 = ( V_19 + V_104 ) & V_105 ;
V_103 = F_87 (unsigned long, end, next_page) ;
V_110 = ( V_103 - V_19 ) >> V_15 ;
V_110 = F_87 ( int , ( int ) V_58 -> V_29 , V_110 ) ;
V_54 = F_37 ( V_53 , V_19 ) ;
if ( F_38 ( * V_54 ) )
if ( F_96 ( V_54 ) )
return - 1 ;
V_110 = F_100 ( V_58 , V_19 , V_103 , V_110 ,
V_54 , V_109 ) ;
if ( V_110 < 0 )
return V_110 ;
V_19 = V_103 ;
}
if ( V_58 -> V_29 == V_110 )
return V_110 ;
V_54 = F_37 ( V_53 , V_19 ) ;
while ( V_20 - V_19 >= V_104 ) {
F_97 ( V_54 , F_98 ( V_58 -> V_40 | V_81 | F_101 ( V_109 ) ) ) ;
V_19 += V_104 ;
V_58 -> V_40 += V_104 ;
V_110 += V_104 >> V_15 ;
V_54 ++ ;
}
if ( V_19 < V_20 ) {
int V_71 ;
V_54 = F_37 ( V_53 , V_19 ) ;
if ( F_38 ( * V_54 ) )
if ( F_96 ( V_54 ) )
return - 1 ;
V_71 = F_100 ( V_58 , V_19 , V_20 , V_58 -> V_29 - V_110 ,
V_54 , V_109 ) ;
if ( V_71 < 0 )
return V_110 ;
V_110 += V_71 ;
}
return V_110 ;
}
static int F_103 ( struct V_57 * V_58 , unsigned long V_18 )
{
T_2 V_109 = F_32 ( V_93 ) ;
T_4 * V_54 = NULL ;
T_3 * V_107 ;
int V_111 ;
V_107 = V_58 -> V_53 + F_48 ( V_18 ) ;
if ( F_36 ( * V_107 ) ) {
V_54 = ( T_4 * ) F_93 ( V_96 | V_97 ) ;
if ( ! V_54 )
return - 1 ;
F_104 ( V_107 , F_105 ( F_69 ( V_54 ) | V_93 ) ) ;
}
F_34 ( V_109 ) &= ~ F_34 ( V_58 -> V_79 ) ;
F_34 ( V_109 ) |= F_34 ( V_58 -> V_80 ) ;
V_111 = F_102 ( V_58 , V_18 , V_107 , V_109 ) ;
if ( V_111 < 0 ) {
F_89 ( V_58 -> V_53 , V_18 ,
V_18 + ( V_58 -> V_29 << V_15 ) ) ;
return V_111 ;
}
V_58 -> V_29 = V_111 ;
return 0 ;
}
static int F_106 ( struct V_57 * V_58 , unsigned long V_21 ,
int V_112 )
{
if ( V_58 -> V_53 )
return F_103 ( V_58 , V_21 ) ;
if ( ! V_112 )
return 0 ;
if ( F_12 ( V_21 , V_113 ,
V_113 + ( V_114 << V_15 ) ) ) {
V_58 -> V_29 = 1 ;
V_58 -> V_40 = F_69 ( V_21 ) >> V_15 ;
return 0 ;
} else {
F_107 ( 1 , V_115 L_5
L_6 , V_21 ,
* V_58 -> V_21 ) ;
return - V_116 ;
}
}
static int F_108 ( struct V_57 * V_58 , int V_112 )
{
unsigned long V_39 ;
int V_75 , V_117 ;
unsigned int V_1 ;
T_1 * V_66 , V_70 ;
if ( V_58 -> V_84 & V_37 ) {
struct V_35 * V_35 = V_58 -> V_2 [ V_58 -> V_118 ] ;
if ( F_109 ( F_110 ( V_35 ) ) )
return 0 ;
V_39 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_58 -> V_84 & V_119 )
V_39 = V_58 -> V_21 [ V_58 -> V_118 ] ;
else
V_39 = * V_58 -> V_21 ;
V_120:
V_66 = F_47 ( V_58 , V_39 , & V_1 ) ;
if ( ! V_66 )
return F_106 ( V_58 , V_39 , V_112 ) ;
V_70 = * V_66 ;
if ( ! F_28 ( V_70 ) )
return F_106 ( V_58 , V_39 , V_112 ) ;
if ( V_1 == V_8 ) {
T_1 V_69 ;
T_2 V_73 = F_58 ( V_70 ) ;
unsigned long V_40 = F_52 ( V_70 ) ;
F_34 ( V_73 ) &= ~ F_34 ( V_58 -> V_79 ) ;
F_34 ( V_73 ) |= F_34 ( V_58 -> V_80 ) ;
V_73 = F_31 ( V_73 , V_39 , V_40 ) ;
if ( F_34 ( V_73 ) & V_33 )
F_34 ( V_73 ) |= V_82 ;
else
F_34 ( V_73 ) &= ~ V_82 ;
V_69 = F_60 ( V_40 , F_59 ( V_73 ) ) ;
V_58 -> V_40 = V_40 ;
if ( F_28 ( V_70 ) != F_28 ( V_69 ) ) {
F_54 ( V_66 , V_69 ) ;
V_58 -> V_84 |= V_85 ;
}
V_58 -> V_29 = 1 ;
return 0 ;
}
V_75 = F_57 ( V_66 , V_39 , V_58 ) ;
if ( V_75 <= 0 )
return V_75 ;
V_117 = F_71 ( V_58 , V_66 , V_39 ) ;
if ( ! V_117 ) {
F_111 () ;
goto V_120;
}
return V_117 ;
}
static int F_112 ( struct V_57 * V_58 )
{
struct V_57 V_121 ;
unsigned long V_122 = ( unsigned long ) F_113 ( V_58 -> V_40 << V_15 ) ;
unsigned long V_21 ;
int V_111 ;
if ( ! F_67 ( V_58 -> V_40 , V_58 -> V_40 + 1 ) )
return 0 ;
if ( V_58 -> V_84 & V_37 ) {
struct V_35 * V_35 = V_58 -> V_2 [ V_58 -> V_118 ] ;
if ( F_109 ( F_110 ( V_35 ) ) )
return 0 ;
V_21 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_58 -> V_84 & V_119 )
V_21 = V_58 -> V_21 [ V_58 -> V_118 ] ;
else
V_21 = * V_58 -> V_21 ;
if ( ! ( F_12 ( V_21 , V_113 ,
V_113 + ( V_114 << V_15 ) ) ) ) {
V_121 = * V_58 ;
V_121 . V_21 = & V_122 ;
V_121 . V_84 &= ~ ( V_37 | V_119 ) ;
V_111 = F_114 ( & V_121 , 0 ) ;
if ( V_111 )
return V_111 ;
}
#ifdef V_9
if ( ! F_12 ( V_21 , ( unsigned long ) V_14 , V_16 ) &&
F_12 ( V_58 -> V_40 , F_8 () , F_10 () ) ) {
unsigned long V_123 = ( V_58 -> V_40 << V_15 ) +
V_124 - V_125 ;
V_121 = * V_58 ;
V_121 . V_21 = & V_123 ;
V_121 . V_84 &= ~ ( V_37 | V_119 ) ;
F_114 ( & V_121 , 0 ) ;
}
#endif
return 0 ;
}
static int F_114 ( struct V_57 * V_58 , int V_126 )
{
int V_111 , V_29 = V_58 -> V_29 ;
while ( V_29 ) {
V_58 -> V_29 = V_29 ;
if ( V_58 -> V_84 & ( V_119 | V_37 ) )
V_58 -> V_29 = 1 ;
if ( ! V_94 )
F_2 ( & V_95 ) ;
V_111 = F_108 ( V_58 , V_126 ) ;
if ( ! V_94 )
F_3 ( & V_95 ) ;
if ( V_111 )
return V_111 ;
if ( V_126 ) {
V_111 = F_112 ( V_58 ) ;
if ( V_111 )
return V_111 ;
}
F_20 ( V_58 -> V_29 > V_29 ) ;
V_29 -= V_58 -> V_29 ;
if ( V_58 -> V_84 & ( V_37 | V_119 ) )
V_58 -> V_118 ++ ;
else
* V_58 -> V_21 += V_58 -> V_29 * V_31 ;
}
return 0 ;
}
static inline int F_115 ( T_2 V_127 )
{
return F_34 ( V_127 ) &
( V_128 | V_91 | V_129 | V_130 ) ;
}
static int F_116 ( unsigned long * V_18 , int V_29 ,
T_2 V_80 , T_2 V_79 ,
int V_76 , int V_131 ,
struct V_35 * * V_2 )
{
struct V_57 V_58 ;
int V_111 , V_27 , V_126 ;
unsigned long V_132 = 0 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_80 = F_59 ( V_80 ) ;
V_79 = F_59 ( V_79 ) ;
if ( ! F_34 ( V_80 ) && ! F_34 ( V_79 ) && ! V_76 )
return 0 ;
if ( V_131 & V_119 ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
if ( V_18 [ V_30 ] & ~ V_133 ) {
V_18 [ V_30 ] &= V_133 ;
F_65 ( 1 ) ;
}
}
} else if ( ! ( V_131 & V_37 ) ) {
if ( * V_18 & ~ V_133 ) {
* V_18 &= V_133 ;
F_65 ( 1 ) ;
}
V_132 = * V_18 ;
}
F_117 () ;
F_118 () ;
V_58 . V_21 = V_18 ;
V_58 . V_2 = V_2 ;
V_58 . V_29 = V_29 ;
V_58 . V_80 = V_80 ;
V_58 . V_79 = V_79 ;
V_58 . V_84 = 0 ;
V_58 . V_118 = 0 ;
V_58 . V_76 = V_76 ;
if ( V_131 & ( V_119 | V_37 ) )
V_58 . V_84 |= V_131 ;
V_126 = ( F_34 ( V_80 ) | F_34 ( V_79 ) ) != V_45 ;
V_111 = F_114 ( & V_58 , V_126 ) ;
if ( ! ( V_58 . V_84 & V_85 ) )
goto V_134;
V_27 = F_115 ( V_80 ) ;
if ( ! V_111 && V_135 ) {
if ( V_58 . V_84 & ( V_37 | V_119 ) ) {
F_29 ( V_18 , V_29 , V_27 ,
V_58 . V_84 , V_2 ) ;
} else
F_24 ( V_132 , V_29 , V_27 ) ;
} else
F_19 ( V_27 ) ;
V_134:
return V_111 ;
}
static inline int F_119 ( unsigned long * V_18 , int V_29 ,
T_2 V_136 , int V_137 )
{
return F_116 ( V_18 , V_29 , V_136 , F_32 ( 0 ) , 0 ,
( V_137 ? V_119 : 0 ) , NULL ) ;
}
static inline int F_120 ( unsigned long * V_18 , int V_29 ,
T_2 V_136 , int V_137 )
{
return F_116 ( V_18 , V_29 , F_32 ( 0 ) , V_136 , 0 ,
( V_137 ? V_119 : 0 ) , NULL ) ;
}
static inline int F_121 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_136 )
{
return F_116 ( NULL , V_29 , V_136 , F_32 ( 0 ) , 0 ,
V_37 , V_2 ) ;
}
static inline int F_122 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_136 )
{
return F_116 ( NULL , V_29 , F_32 ( 0 ) , V_136 , 0 ,
V_37 , V_2 ) ;
}
int F_123 ( unsigned long V_18 , int V_29 )
{
return F_119 ( & V_18 , V_29 ,
F_32 ( V_138 ) , 0 ) ;
}
int F_124 ( unsigned long V_18 , int V_29 )
{
int V_111 ;
V_111 = F_125 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ,
V_138 , NULL ) ;
if ( V_111 )
goto V_139;
V_111 = F_123 ( V_18 , V_29 ) ;
if ( V_111 )
goto V_140;
return 0 ;
V_140:
F_126 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ) ;
V_139:
return V_111 ;
}
static int F_127 ( unsigned long * V_18 , int V_141 ,
unsigned long V_142 )
{
int V_30 , V_143 ;
int V_111 ;
for ( V_30 = 0 ; V_30 < V_141 ; V_30 ++ ) {
V_111 = F_125 ( F_69 ( V_18 [ V_30 ] ) , F_69 ( V_18 [ V_30 ] ) + V_31 ,
V_142 , NULL ) ;
if ( V_111 )
goto V_140;
}
V_111 = F_119 ( V_18 , V_141 ,
F_32 ( V_138 ) , 1 ) ;
if ( ! V_111 && V_142 == V_144 )
V_111 = F_116 ( V_18 , V_141 ,
F_32 ( V_144 ) ,
F_32 ( V_145 ) ,
0 , V_119 , NULL ) ;
if ( V_111 )
goto V_140;
return 0 ;
V_140:
for ( V_143 = 0 ; V_143 < V_30 ; V_143 ++ )
F_126 ( F_69 ( V_18 [ V_143 ] ) , F_69 ( V_18 [ V_143 ] ) + V_31 ) ;
return V_111 ;
}
int F_128 ( unsigned long * V_18 , int V_141 )
{
return F_127 ( V_18 , V_141 , V_138 ) ;
}
int F_129 ( unsigned long * V_18 , int V_141 )
{
return F_127 ( V_18 , V_141 , V_144 ) ;
}
int F_130 ( unsigned long V_18 , int V_29 )
{
int V_111 ;
unsigned long V_146 = V_18 ;
V_111 = F_119 ( & V_18 , V_29 ,
F_32 ( V_138 ) , 0 ) ;
if ( ! V_111 ) {
V_111 = F_116 ( & V_146 , V_29 ,
F_32 ( V_144 ) ,
F_32 ( V_145 ) ,
0 , 0 , NULL ) ;
}
return V_111 ;
}
int F_131 ( unsigned long V_18 , int V_29 )
{
int V_111 ;
if ( ! V_147 )
return F_124 ( V_18 , V_29 ) ;
V_111 = F_125 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ,
V_144 , NULL ) ;
if ( V_111 )
goto V_139;
V_111 = F_130 ( V_18 , V_29 ) ;
if ( V_111 )
goto V_140;
return 0 ;
V_140:
F_126 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ) ;
V_139:
return V_111 ;
}
int F_132 ( unsigned long V_18 , int V_29 )
{
return F_120 ( & V_18 , V_29 ,
F_32 ( V_145 ) , 0 ) ;
}
int F_133 ( unsigned long V_18 , int V_29 )
{
int V_111 ;
V_111 = F_132 ( V_18 , V_29 ) ;
if ( V_111 )
return V_111 ;
F_126 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ) ;
return 0 ;
}
int F_134 ( unsigned long * V_18 , int V_141 )
{
int V_30 ;
int V_111 ;
V_111 = F_120 ( V_18 , V_141 ,
F_32 ( V_145 ) , 1 ) ;
if ( V_111 )
return V_111 ;
for ( V_30 = 0 ; V_30 < V_141 ; V_30 ++ )
F_126 ( F_69 ( V_18 [ V_30 ] ) , F_69 ( V_18 [ V_30 ] ) + V_31 ) ;
return 0 ;
}
int F_135 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_148 & V_45 ) )
return 0 ;
return F_120 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_136 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_148 & V_45 ) )
return 0 ;
return F_119 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_137 ( unsigned long V_18 , int V_29 )
{
return F_120 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_138 ( unsigned long V_18 , int V_29 )
{
return F_119 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_139 ( unsigned long V_18 , int V_29 )
{
return F_120 ( & V_18 , V_29 , F_32 ( V_33 ) , 0 ) ;
}
int F_140 ( unsigned long V_18 , int V_29 )
{
return F_116 ( & V_18 , V_29 , F_32 ( 0 ) ,
F_32 ( 0 ) , 1 , 0 , NULL ) ;
}
int F_141 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_124 ( V_18 , V_29 ) ;
}
static int F_142 ( struct V_35 * * V_2 , int V_141 ,
unsigned long V_142 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
int V_149 ;
int V_111 ;
for ( V_30 = 0 ; V_30 < V_141 ; V_30 ++ ) {
if ( F_110 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_63 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
if ( F_125 ( V_19 , V_20 , V_142 , NULL ) )
goto V_150;
}
V_111 = F_121 ( V_2 , V_141 ,
F_32 ( V_138 ) ) ;
if ( ! V_111 && V_142 == V_144 )
V_111 = F_116 ( NULL , V_141 ,
F_32 ( V_144 ) ,
F_32 ( V_145 ) ,
0 , V_37 , V_2 ) ;
if ( V_111 )
goto V_150;
return 0 ;
V_150:
V_149 = V_30 ;
for ( V_30 = 0 ; V_30 < V_149 ; V_30 ++ ) {
if ( F_110 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_63 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_126 ( V_19 , V_20 ) ;
}
return - V_78 ;
}
int F_143 ( struct V_35 * * V_2 , int V_141 )
{
return F_142 ( V_2 , V_141 , V_138 ) ;
}
int F_144 ( struct V_35 * * V_2 , int V_141 )
{
return F_142 ( V_2 , V_141 , V_144 ) ;
}
int F_145 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_133 ( V_18 , V_29 ) ;
}
int F_146 ( struct V_35 * * V_2 , int V_141 )
{
int V_151 ;
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
V_151 = F_122 ( V_2 , V_141 ,
F_32 ( V_145 ) ) ;
if ( V_151 )
return V_151 ;
for ( V_30 = 0 ; V_30 < V_141 ; V_30 ++ ) {
if ( F_110 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_63 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_126 ( V_19 , V_20 ) ;
}
return 0 ;
}
int F_147 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_135 ( V_18 , V_29 ) ;
}
int F_148 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_136 ( V_18 , V_29 ) ;
}
int F_149 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_137 ( V_18 , V_29 ) ;
}
int F_150 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_138 ( V_18 , V_29 ) ;
}
static int F_151 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_152 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_57 V_58 = { . V_21 = & V_152 ,
. V_53 = NULL ,
. V_29 = V_29 ,
. V_80 = F_32 ( V_33 | V_49 ) ,
. V_79 = F_32 ( 0 ) ,
. V_84 = 0 } ;
return F_114 ( & V_58 , 0 ) ;
}
static int F_152 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_152 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_57 V_58 = { . V_21 = & V_152 ,
. V_53 = NULL ,
. V_29 = V_29 ,
. V_80 = F_32 ( 0 ) ,
. V_79 = F_32 ( V_33 | V_49 ) ,
. V_84 = 0 } ;
return F_114 ( & V_58 , 0 ) ;
}
void F_153 ( struct V_35 * V_35 , int V_29 , int V_153 )
{
if ( F_110 ( V_35 ) )
return;
if ( ! V_153 ) {
F_154 ( F_30 ( V_35 ) ,
V_29 * V_31 ) ;
}
if ( V_153 )
F_151 ( V_35 , V_29 ) ;
else
F_152 ( V_35 , V_29 ) ;
F_17 () ;
F_155 () ;
}
bool F_156 ( struct V_35 * V_35 )
{
unsigned int V_1 ;
T_1 * V_32 ;
if ( F_110 ( V_35 ) )
return false ;
V_32 = F_27 ( ( unsigned long ) F_30 ( V_35 ) , & V_1 ) ;
return ( F_28 ( * V_32 ) & V_33 ) ;
}
int F_157 ( T_3 * V_53 , T_7 V_40 , unsigned long V_39 ,
unsigned V_29 , unsigned long V_154 )
{
int V_151 = - V_78 ;
struct V_57 V_58 = {
. V_21 = & V_39 ,
. V_40 = V_40 ,
. V_53 = V_53 ,
. V_29 = V_29 ,
. V_80 = F_32 ( 0 ) ,
. V_79 = F_32 ( 0 ) ,
. V_84 = 0 ,
} ;
if ( ! ( V_148 & V_45 ) )
goto V_134;
if ( ! ( V_154 & V_45 ) )
V_58 . V_79 = F_32 ( V_45 ) ;
V_58 . V_80 = F_32 ( V_33 | V_154 ) ;
V_151 = F_114 ( & V_58 , 0 ) ;
F_17 () ;
V_134:
return V_151 ;
}
void F_158 ( T_3 * V_106 , unsigned long V_39 ,
unsigned V_29 )
{
F_89 ( V_106 , V_39 , V_39 + ( V_29 << V_15 ) ) ;
}
