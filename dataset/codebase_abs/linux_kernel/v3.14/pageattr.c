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
static T_1 * F_35 ( T_3 * V_53 , unsigned long V_39 ,
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
static bool F_78 ( T_5 * V_55 , unsigned long V_19 , unsigned long V_20 )
{
T_1 * V_32 = F_45 ( V_55 , V_19 ) ;
while ( V_19 < V_20 ) {
F_66 ( V_32 , F_79 ( 0 ) ) ;
V_19 += V_31 ;
V_32 ++ ;
}
if ( F_74 ( ( T_1 * ) F_80 ( * V_55 ) ) ) {
F_81 ( V_55 ) ;
return true ;
}
return false ;
}
static void F_82 ( T_4 * V_54 , T_5 * V_55 ,
unsigned long V_19 , unsigned long V_20 )
{
if ( F_78 ( V_55 , V_19 , V_20 ) )
if ( F_77 ( ( T_5 * ) F_83 ( * V_54 ) ) )
F_84 ( V_54 ) ;
}
static void F_85 ( T_4 * V_54 , unsigned long V_19 , unsigned long V_20 )
{
T_5 * V_55 = F_41 ( V_54 , V_19 ) ;
if ( V_19 & ( V_17 - 1 ) ) {
unsigned long V_100 = ( V_19 + V_17 ) & V_101 ;
unsigned long V_102 = F_86 (unsigned long, end, next_page) ;
F_82 ( V_54 , V_55 , V_19 , V_102 ) ;
V_19 = V_102 ;
V_55 ++ ;
}
while ( V_20 - V_19 >= V_17 ) {
if ( F_43 ( * V_55 ) )
F_81 ( V_55 ) ;
else
F_82 ( V_54 , V_55 , V_19 , V_19 + V_17 ) ;
V_19 += V_17 ;
V_55 ++ ;
}
if ( V_19 < V_20 )
return F_82 ( V_54 , V_55 , V_19 , V_20 ) ;
if ( ! F_38 ( * V_54 ) )
if ( F_77 ( ( T_5 * ) F_83 ( * V_54 ) ) )
F_84 ( V_54 ) ;
}
static void F_87 ( T_3 * V_53 , unsigned long V_19 , unsigned long V_20 )
{
T_4 * V_54 = F_37 ( V_53 , V_19 ) ;
if ( V_19 & ( V_103 - 1 ) ) {
unsigned long V_100 = ( V_19 + V_103 ) & V_104 ;
unsigned long V_102 = F_86 (unsigned long, end, next_page) ;
F_85 ( V_54 , V_19 , V_102 ) ;
V_19 = V_102 ;
V_54 ++ ;
}
while ( V_20 - V_19 >= V_103 ) {
if ( F_39 ( * V_54 ) )
F_84 ( V_54 ) ;
else
F_85 ( V_54 , V_19 , V_19 + V_103 ) ;
V_19 += V_103 ;
V_54 ++ ;
}
if ( V_19 < V_20 )
F_85 ( V_54 , V_19 , V_20 ) ;
}
static int F_88 ( T_5 * V_55 )
{
T_1 * V_32 = ( T_1 * ) F_89 ( V_96 | V_97 ) ;
if ( ! V_32 )
return - 1 ;
F_90 ( V_55 , F_91 ( F_69 ( V_32 ) | V_93 ) ) ;
return 0 ;
}
static int F_92 ( T_4 * V_54 )
{
T_5 * V_55 = ( T_5 * ) F_89 ( V_96 | V_97 ) ;
if ( ! V_55 )
return - 1 ;
F_93 ( V_54 , F_94 ( F_69 ( V_55 ) | V_93 ) ) ;
return 0 ;
}
static void F_95 ( struct V_57 * V_58 ,
unsigned long V_19 , unsigned long V_20 ,
unsigned V_105 , T_5 * V_55 , T_2 V_106 )
{
T_1 * V_32 ;
V_32 = F_45 ( V_55 , V_19 ) ;
while ( V_105 -- && V_19 < V_20 ) {
if ( ! ( F_34 ( V_106 ) & V_45 ) )
V_58 -> V_40 &= ~ V_45 ;
F_66 ( V_32 , F_60 ( V_58 -> V_40 >> V_15 , V_106 ) ) ;
V_19 += V_31 ;
V_58 -> V_40 += V_31 ;
V_32 ++ ;
}
}
static int F_96 ( struct V_57 * V_58 ,
unsigned long V_19 , unsigned long V_20 ,
unsigned V_105 , T_4 * V_54 , T_2 V_106 )
{
unsigned int V_107 = 0 ;
T_5 * V_55 ;
if ( V_19 & ( V_17 - 1 ) ) {
unsigned long V_102 = V_19 + ( V_105 << V_15 ) ;
unsigned long V_100 = ( V_19 + V_17 ) & V_101 ;
V_102 = F_86 (unsigned long, pre_end, next_page) ;
V_107 = ( V_102 - V_19 ) >> V_15 ;
V_107 = F_86 (unsigned int, num_pages, cur_pages) ;
V_55 = F_41 ( V_54 , V_19 ) ;
if ( F_42 ( * V_55 ) )
if ( F_88 ( V_55 ) )
return - 1 ;
F_95 ( V_58 , V_19 , V_102 , V_107 , V_55 , V_106 ) ;
V_19 = V_102 ;
}
if ( V_105 == V_107 )
return V_107 ;
while ( V_20 - V_19 >= V_17 ) {
if ( F_38 ( * V_54 ) )
if ( F_92 ( V_54 ) )
return - 1 ;
V_55 = F_41 ( V_54 , V_19 ) ;
F_90 ( V_55 , F_91 ( V_58 -> V_40 | V_81 | F_97 ( V_106 ) ) ) ;
V_19 += V_17 ;
V_58 -> V_40 += V_17 ;
V_107 += V_17 >> V_15 ;
}
if ( V_19 < V_20 ) {
V_55 = F_41 ( V_54 , V_19 ) ;
if ( F_42 ( * V_55 ) )
if ( F_88 ( V_55 ) )
return - 1 ;
F_95 ( V_58 , V_19 , V_20 , V_105 - V_107 ,
V_55 , V_106 ) ;
}
return V_105 ;
}
static int F_98 ( struct V_57 * V_58 , unsigned long V_19 , T_3 * V_53 ,
T_2 V_106 )
{
T_4 * V_54 ;
unsigned long V_20 ;
int V_107 = 0 ;
V_20 = V_19 + ( V_58 -> V_29 << V_15 ) ;
if ( V_19 & ( V_103 - 1 ) ) {
unsigned long V_102 ;
unsigned long V_100 = ( V_19 + V_103 ) & V_104 ;
V_102 = F_86 (unsigned long, end, next_page) ;
V_107 = ( V_102 - V_19 ) >> V_15 ;
V_107 = F_86 ( int , ( int ) V_58 -> V_29 , V_107 ) ;
V_54 = F_37 ( V_53 , V_19 ) ;
if ( F_38 ( * V_54 ) )
if ( F_92 ( V_54 ) )
return - 1 ;
V_107 = F_96 ( V_58 , V_19 , V_102 , V_107 ,
V_54 , V_106 ) ;
if ( V_107 < 0 )
return V_107 ;
V_19 = V_102 ;
}
if ( V_58 -> V_29 == V_107 )
return V_107 ;
V_54 = F_37 ( V_53 , V_19 ) ;
while ( V_20 - V_19 >= V_103 ) {
F_93 ( V_54 , F_94 ( V_58 -> V_40 | V_81 | F_97 ( V_106 ) ) ) ;
V_19 += V_103 ;
V_58 -> V_40 += V_103 ;
V_107 += V_103 >> V_15 ;
V_54 ++ ;
}
if ( V_19 < V_20 ) {
int V_71 ;
V_54 = F_37 ( V_53 , V_19 ) ;
if ( F_38 ( * V_54 ) )
if ( F_92 ( V_54 ) )
return - 1 ;
V_71 = F_96 ( V_58 , V_19 , V_20 , V_58 -> V_29 - V_107 ,
V_54 , V_106 ) ;
if ( V_71 < 0 )
return V_107 ;
V_107 += V_71 ;
}
return V_107 ;
}
static int F_99 ( struct V_57 * V_58 , unsigned long V_18 )
{
T_2 V_106 = F_32 ( V_93 ) ;
bool V_108 = false ;
T_3 * V_109 ;
T_4 * V_54 = NULL ;
int V_110 ;
V_109 = V_58 -> V_53 + F_48 ( V_18 ) ;
if ( F_36 ( * V_109 ) ) {
V_54 = ( T_4 * ) F_89 ( V_96 | V_97 ) ;
if ( ! V_54 )
return - 1 ;
F_100 ( V_109 , F_101 ( F_69 ( V_54 ) | V_93 ) ) ;
V_108 = true ;
}
F_34 ( V_106 ) &= ~ F_34 ( V_58 -> V_79 ) ;
F_34 ( V_106 ) |= F_34 ( V_58 -> V_80 ) ;
V_110 = F_98 ( V_58 , V_18 , V_109 , V_106 ) ;
if ( V_110 < 0 ) {
F_87 ( V_109 , V_18 ,
V_18 + ( V_58 -> V_29 << V_15 ) ) ;
if ( V_108 ) {
F_102 ( V_109 ) ;
F_76 ( ( unsigned long ) V_54 ) ;
}
return V_110 ;
}
V_58 -> V_29 = V_110 ;
return 0 ;
}
static int F_103 ( struct V_57 * V_58 , unsigned long V_21 ,
int V_111 )
{
if ( V_58 -> V_53 )
return F_99 ( V_58 , V_21 ) ;
if ( ! V_111 )
return 0 ;
if ( F_12 ( V_21 , V_112 ,
V_112 + ( V_113 << V_15 ) ) ) {
V_58 -> V_29 = 1 ;
V_58 -> V_40 = F_69 ( V_21 ) >> V_15 ;
return 0 ;
} else {
F_104 ( 1 , V_114 L_5
L_6 , V_21 ,
* V_58 -> V_21 ) ;
return - V_115 ;
}
}
static int F_105 ( struct V_57 * V_58 , int V_111 )
{
unsigned long V_39 ;
int V_75 , V_116 ;
unsigned int V_1 ;
T_1 * V_66 , V_70 ;
if ( V_58 -> V_84 & V_37 ) {
struct V_35 * V_35 = V_58 -> V_2 [ V_58 -> V_117 ] ;
if ( F_106 ( F_107 ( V_35 ) ) )
return 0 ;
V_39 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_58 -> V_84 & V_118 )
V_39 = V_58 -> V_21 [ V_58 -> V_117 ] ;
else
V_39 = * V_58 -> V_21 ;
V_119:
V_66 = F_47 ( V_58 , V_39 , & V_1 ) ;
if ( ! V_66 )
return F_103 ( V_58 , V_39 , V_111 ) ;
V_70 = * V_66 ;
if ( ! F_28 ( V_70 ) )
return F_103 ( V_58 , V_39 , V_111 ) ;
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
V_116 = F_71 ( V_58 , V_66 , V_39 ) ;
if ( ! V_116 ) {
F_108 () ;
goto V_119;
}
return V_116 ;
}
static int F_109 ( struct V_57 * V_58 )
{
struct V_57 V_120 ;
unsigned long V_121 = ( unsigned long ) F_110 ( V_58 -> V_40 << V_15 ) ;
unsigned long V_21 ;
int V_110 ;
if ( ! F_67 ( V_58 -> V_40 , V_58 -> V_40 + 1 ) )
return 0 ;
if ( V_58 -> V_84 & V_37 ) {
struct V_35 * V_35 = V_58 -> V_2 [ V_58 -> V_117 ] ;
if ( F_106 ( F_107 ( V_35 ) ) )
return 0 ;
V_21 = ( unsigned long ) F_30 ( V_35 ) ;
} else if ( V_58 -> V_84 & V_118 )
V_21 = V_58 -> V_21 [ V_58 -> V_117 ] ;
else
V_21 = * V_58 -> V_21 ;
if ( ! ( F_12 ( V_21 , V_112 ,
V_112 + ( V_113 << V_15 ) ) ) ) {
V_120 = * V_58 ;
V_120 . V_21 = & V_121 ;
V_120 . V_84 &= ~ ( V_37 | V_118 ) ;
V_110 = F_111 ( & V_120 , 0 ) ;
if ( V_110 )
return V_110 ;
}
#ifdef V_9
if ( ! F_12 ( V_21 , ( unsigned long ) V_14 , V_16 ) &&
F_12 ( V_58 -> V_40 , F_8 () , F_10 () ) ) {
unsigned long V_122 = ( V_58 -> V_40 << V_15 ) +
V_123 - V_124 ;
V_120 = * V_58 ;
V_120 . V_21 = & V_122 ;
V_120 . V_84 &= ~ ( V_37 | V_118 ) ;
F_111 ( & V_120 , 0 ) ;
}
#endif
return 0 ;
}
static int F_111 ( struct V_57 * V_58 , int V_125 )
{
int V_110 , V_29 = V_58 -> V_29 ;
while ( V_29 ) {
V_58 -> V_29 = V_29 ;
if ( V_58 -> V_84 & ( V_118 | V_37 ) )
V_58 -> V_29 = 1 ;
if ( ! V_94 )
F_2 ( & V_95 ) ;
V_110 = F_105 ( V_58 , V_125 ) ;
if ( ! V_94 )
F_3 ( & V_95 ) ;
if ( V_110 )
return V_110 ;
if ( V_125 ) {
V_110 = F_109 ( V_58 ) ;
if ( V_110 )
return V_110 ;
}
F_20 ( V_58 -> V_29 > V_29 ) ;
V_29 -= V_58 -> V_29 ;
if ( V_58 -> V_84 & ( V_37 | V_118 ) )
V_58 -> V_117 ++ ;
else
* V_58 -> V_21 += V_58 -> V_29 * V_31 ;
}
return 0 ;
}
static inline int F_112 ( T_2 V_126 )
{
return F_34 ( V_126 ) &
( V_127 | V_91 | V_128 | V_129 ) ;
}
static int F_113 ( unsigned long * V_18 , int V_29 ,
T_2 V_80 , T_2 V_79 ,
int V_76 , int V_130 ,
struct V_35 * * V_2 )
{
struct V_57 V_58 ;
int V_110 , V_27 , V_125 ;
unsigned long V_131 = 0 ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_80 = F_59 ( V_80 ) ;
V_79 = F_59 ( V_79 ) ;
if ( ! F_34 ( V_80 ) && ! F_34 ( V_79 ) && ! V_76 )
return 0 ;
if ( V_130 & V_118 ) {
int V_30 ;
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ ) {
if ( V_18 [ V_30 ] & ~ V_132 ) {
V_18 [ V_30 ] &= V_132 ;
F_65 ( 1 ) ;
}
}
} else if ( ! ( V_130 & V_37 ) ) {
if ( * V_18 & ~ V_132 ) {
* V_18 &= V_132 ;
F_65 ( 1 ) ;
}
V_131 = * V_18 ;
}
F_114 () ;
F_115 () ;
V_58 . V_21 = V_18 ;
V_58 . V_2 = V_2 ;
V_58 . V_29 = V_29 ;
V_58 . V_80 = V_80 ;
V_58 . V_79 = V_79 ;
V_58 . V_84 = 0 ;
V_58 . V_117 = 0 ;
V_58 . V_76 = V_76 ;
if ( V_130 & ( V_118 | V_37 ) )
V_58 . V_84 |= V_130 ;
V_125 = ( F_34 ( V_80 ) | F_34 ( V_79 ) ) != V_45 ;
V_110 = F_111 ( & V_58 , V_125 ) ;
if ( ! ( V_58 . V_84 & V_85 ) )
goto V_133;
V_27 = F_112 ( V_80 ) ;
if ( ! V_110 && V_134 ) {
if ( V_58 . V_84 & ( V_37 | V_118 ) ) {
F_29 ( V_18 , V_29 , V_27 ,
V_58 . V_84 , V_2 ) ;
} else
F_24 ( V_131 , V_29 , V_27 ) ;
} else
F_19 ( V_27 ) ;
V_133:
return V_110 ;
}
static inline int F_116 ( unsigned long * V_18 , int V_29 ,
T_2 V_135 , int V_136 )
{
return F_113 ( V_18 , V_29 , V_135 , F_32 ( 0 ) , 0 ,
( V_136 ? V_118 : 0 ) , NULL ) ;
}
static inline int F_117 ( unsigned long * V_18 , int V_29 ,
T_2 V_135 , int V_136 )
{
return F_113 ( V_18 , V_29 , F_32 ( 0 ) , V_135 , 0 ,
( V_136 ? V_118 : 0 ) , NULL ) ;
}
static inline int F_118 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_135 )
{
return F_113 ( NULL , V_29 , V_135 , F_32 ( 0 ) , 0 ,
V_37 , V_2 ) ;
}
static inline int F_119 ( struct V_35 * * V_2 , int V_29 ,
T_2 V_135 )
{
return F_113 ( NULL , V_29 , F_32 ( 0 ) , V_135 , 0 ,
V_37 , V_2 ) ;
}
int F_120 ( unsigned long V_18 , int V_29 )
{
return F_116 ( & V_18 , V_29 ,
F_32 ( V_137 ) , 0 ) ;
}
int F_121 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
V_110 = F_122 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ,
V_137 , NULL ) ;
if ( V_110 )
goto V_138;
V_110 = F_120 ( V_18 , V_29 ) ;
if ( V_110 )
goto V_139;
return 0 ;
V_139:
F_123 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ) ;
V_138:
return V_110 ;
}
static int F_124 ( unsigned long * V_18 , int V_140 ,
unsigned long V_141 )
{
int V_30 , V_142 ;
int V_110 ;
for ( V_30 = 0 ; V_30 < V_140 ; V_30 ++ ) {
V_110 = F_122 ( F_69 ( V_18 [ V_30 ] ) , F_69 ( V_18 [ V_30 ] ) + V_31 ,
V_141 , NULL ) ;
if ( V_110 )
goto V_139;
}
V_110 = F_116 ( V_18 , V_140 ,
F_32 ( V_137 ) , 1 ) ;
if ( ! V_110 && V_141 == V_143 )
V_110 = F_113 ( V_18 , V_140 ,
F_32 ( V_143 ) ,
F_32 ( V_144 ) ,
0 , V_118 , NULL ) ;
if ( V_110 )
goto V_139;
return 0 ;
V_139:
for ( V_142 = 0 ; V_142 < V_30 ; V_142 ++ )
F_123 ( F_69 ( V_18 [ V_142 ] ) , F_69 ( V_18 [ V_142 ] ) + V_31 ) ;
return V_110 ;
}
int F_125 ( unsigned long * V_18 , int V_140 )
{
return F_124 ( V_18 , V_140 , V_137 ) ;
}
int F_126 ( unsigned long * V_18 , int V_140 )
{
return F_124 ( V_18 , V_140 , V_143 ) ;
}
int F_127 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
unsigned long V_145 = V_18 ;
V_110 = F_116 ( & V_18 , V_29 ,
F_32 ( V_137 ) , 0 ) ;
if ( ! V_110 ) {
V_110 = F_113 ( & V_145 , V_29 ,
F_32 ( V_143 ) ,
F_32 ( V_144 ) ,
0 , 0 , NULL ) ;
}
return V_110 ;
}
int F_128 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
if ( ! V_146 )
return F_121 ( V_18 , V_29 ) ;
V_110 = F_122 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ,
V_143 , NULL ) ;
if ( V_110 )
goto V_138;
V_110 = F_127 ( V_18 , V_29 ) ;
if ( V_110 )
goto V_139;
return 0 ;
V_139:
F_123 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ) ;
V_138:
return V_110 ;
}
int F_129 ( unsigned long V_18 , int V_29 )
{
return F_117 ( & V_18 , V_29 ,
F_32 ( V_144 ) , 0 ) ;
}
int F_130 ( unsigned long V_18 , int V_29 )
{
int V_110 ;
V_110 = F_129 ( V_18 , V_29 ) ;
if ( V_110 )
return V_110 ;
F_123 ( F_69 ( V_18 ) , F_69 ( V_18 ) + V_29 * V_31 ) ;
return 0 ;
}
int F_131 ( unsigned long * V_18 , int V_140 )
{
int V_30 ;
int V_110 ;
V_110 = F_117 ( V_18 , V_140 ,
F_32 ( V_144 ) , 1 ) ;
if ( V_110 )
return V_110 ;
for ( V_30 = 0 ; V_30 < V_140 ; V_30 ++ )
F_123 ( F_69 ( V_18 [ V_30 ] ) , F_69 ( V_18 [ V_30 ] ) + V_31 ) ;
return 0 ;
}
int F_132 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_147 & V_45 ) )
return 0 ;
return F_117 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_133 ( unsigned long V_18 , int V_29 )
{
if ( ! ( V_147 & V_45 ) )
return 0 ;
return F_116 ( & V_18 , V_29 , F_32 ( V_45 ) , 0 ) ;
}
int F_134 ( unsigned long V_18 , int V_29 )
{
return F_117 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_135 ( unsigned long V_18 , int V_29 )
{
return F_116 ( & V_18 , V_29 , F_32 ( V_49 ) , 0 ) ;
}
int F_136 ( unsigned long V_18 , int V_29 )
{
return F_117 ( & V_18 , V_29 , F_32 ( V_33 ) , 0 ) ;
}
int F_137 ( unsigned long V_18 , int V_29 )
{
return F_113 ( & V_18 , V_29 , F_32 ( 0 ) ,
F_32 ( 0 ) , 1 , 0 , NULL ) ;
}
int F_138 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_121 ( V_18 , V_29 ) ;
}
static int F_139 ( struct V_35 * * V_2 , int V_140 ,
unsigned long V_141 )
{
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
int V_148 ;
int V_110 ;
for ( V_30 = 0 ; V_30 < V_140 ; V_30 ++ ) {
if ( F_107 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_63 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
if ( F_122 ( V_19 , V_20 , V_141 , NULL ) )
goto V_149;
}
V_110 = F_118 ( V_2 , V_140 ,
F_32 ( V_137 ) ) ;
if ( ! V_110 && V_141 == V_143 )
V_110 = F_113 ( NULL , V_140 ,
F_32 ( V_143 ) ,
F_32 ( V_144 ) ,
0 , V_37 , V_2 ) ;
if ( V_110 )
goto V_149;
return 0 ;
V_149:
V_148 = V_30 ;
for ( V_30 = 0 ; V_30 < V_148 ; V_30 ++ ) {
if ( F_107 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_63 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_123 ( V_19 , V_20 ) ;
}
return - V_78 ;
}
int F_140 ( struct V_35 * * V_2 , int V_140 )
{
return F_139 ( V_2 , V_140 , V_137 ) ;
}
int F_141 ( struct V_35 * * V_2 , int V_140 )
{
return F_139 ( V_2 , V_140 , V_143 ) ;
}
int F_142 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_130 ( V_18 , V_29 ) ;
}
int F_143 ( struct V_35 * * V_2 , int V_140 )
{
int V_150 ;
unsigned long V_19 ;
unsigned long V_20 ;
int V_30 ;
V_150 = F_119 ( V_2 , V_140 ,
F_32 ( V_144 ) ) ;
if ( V_150 )
return V_150 ;
for ( V_30 = 0 ; V_30 < V_140 ; V_30 ++ ) {
if ( F_107 ( V_2 [ V_30 ] ) )
continue;
V_19 = F_63 ( V_2 [ V_30 ] ) << V_15 ;
V_20 = V_19 + V_31 ;
F_123 ( V_19 , V_20 ) ;
}
return 0 ;
}
int F_144 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_132 ( V_18 , V_29 ) ;
}
int F_145 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_133 ( V_18 , V_29 ) ;
}
int F_146 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_134 ( V_18 , V_29 ) ;
}
int F_147 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_18 = ( unsigned long ) F_30 ( V_35 ) ;
return F_135 ( V_18 , V_29 ) ;
}
static int F_148 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_151 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_57 V_58 = { . V_21 = & V_151 ,
. V_53 = NULL ,
. V_29 = V_29 ,
. V_80 = F_32 ( V_33 | V_49 ) ,
. V_79 = F_32 ( 0 ) ,
. V_84 = 0 } ;
return F_111 ( & V_58 , 0 ) ;
}
static int F_149 ( struct V_35 * V_35 , int V_29 )
{
unsigned long V_151 = ( unsigned long ) F_30 ( V_35 ) ;
struct V_57 V_58 = { . V_21 = & V_151 ,
. V_53 = NULL ,
. V_29 = V_29 ,
. V_80 = F_32 ( 0 ) ,
. V_79 = F_32 ( V_33 | V_49 ) ,
. V_84 = 0 } ;
return F_111 ( & V_58 , 0 ) ;
}
void F_150 ( struct V_35 * V_35 , int V_29 , int V_152 )
{
if ( F_107 ( V_35 ) )
return;
if ( ! V_152 ) {
F_151 ( F_30 ( V_35 ) ,
V_29 * V_31 ) ;
}
if ( V_152 )
F_148 ( V_35 , V_29 ) ;
else
F_149 ( V_35 , V_29 ) ;
F_17 () ;
F_152 () ;
}
bool F_153 ( struct V_35 * V_35 )
{
unsigned int V_1 ;
T_1 * V_32 ;
if ( F_107 ( V_35 ) )
return false ;
V_32 = F_27 ( ( unsigned long ) F_30 ( V_35 ) , & V_1 ) ;
return ( F_28 ( * V_32 ) & V_33 ) ;
}
int F_154 ( T_3 * V_53 , T_7 V_40 , unsigned long V_39 ,
unsigned V_29 , unsigned long V_153 )
{
int V_150 = - V_78 ;
struct V_57 V_58 = {
. V_21 = & V_39 ,
. V_40 = V_40 ,
. V_53 = V_53 ,
. V_29 = V_29 ,
. V_80 = F_32 ( 0 ) ,
. V_79 = F_32 ( 0 ) ,
. V_84 = 0 ,
} ;
if ( ! ( V_147 & V_45 ) )
goto V_133;
if ( ! ( V_153 & V_45 ) )
V_58 . V_79 = F_32 ( V_45 ) ;
V_58 . V_80 = F_32 ( V_33 | V_153 ) ;
V_150 = F_111 ( & V_58 , 0 ) ;
F_17 () ;
V_133:
return V_150 ;
}
