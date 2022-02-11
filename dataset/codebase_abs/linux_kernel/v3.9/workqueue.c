static inline int F_1 ( int V_1 , const struct V_2 * V_3 ,
unsigned int V_4 )
{
if ( V_1 < V_5 ) {
if ( V_4 & 1 ) {
V_1 = F_2 ( V_1 , V_3 ) ;
if ( V_1 < V_5 )
return V_1 ;
}
if ( V_4 & 2 )
return V_6 ;
}
return V_7 ;
}
static inline int F_3 ( int V_1 , const struct V_2 * V_3 ,
struct V_8 * V_9 )
{
return F_1 ( V_1 , V_3 , ! ( V_9 -> V_10 & V_11 ) ? 1 : 2 ) ;
}
static void * F_4 ( void * V_12 )
{
return ( (struct V_13 * ) V_12 ) -> V_14 ;
}
static int F_5 ( void * V_12 , enum V_15 V_16 )
{
struct V_13 * V_17 = V_12 ;
switch ( V_16 ) {
case V_18 :
F_6 ( V_17 ) ;
F_7 ( V_17 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_8 ( void * V_12 , enum V_15 V_16 )
{
struct V_13 * V_17 = V_12 ;
switch ( V_16 ) {
case V_20 :
if ( F_9 ( V_21 , F_10 ( V_17 ) ) ) {
F_7 ( V_17 , & V_19 ) ;
F_11 ( V_17 , & V_19 ) ;
return 0 ;
}
F_12 ( 1 ) ;
return 0 ;
case V_18 :
F_13 ( 1 ) ;
default:
return 0 ;
}
}
static int F_14 ( void * V_12 , enum V_15 V_16 )
{
struct V_13 * V_17 = V_12 ;
switch ( V_16 ) {
case V_18 :
F_6 ( V_17 ) ;
F_15 ( V_17 , & V_19 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_16 ( struct V_13 * V_17 )
{
F_11 ( V_17 , & V_19 ) ;
}
static inline void F_17 ( struct V_13 * V_17 )
{
F_18 ( V_17 , & V_19 ) ;
}
void F_19 ( struct V_13 * V_17 , int V_22 )
{
if ( V_22 )
F_20 ( V_17 , & V_19 ) ;
else
F_7 ( V_17 , & V_19 ) ;
}
void F_21 ( struct V_13 * V_17 )
{
F_15 ( V_17 , & V_19 ) ;
}
static inline void F_16 ( struct V_13 * V_17 ) { }
static inline void F_17 ( struct V_13 * V_17 ) { }
static struct V_23 * F_22 ( int V_1 )
{
if ( V_1 != V_6 )
return F_23 ( V_24 , V_1 ) ;
else
return V_25 ;
}
static int F_24 ( struct V_23 * V_26 )
{
return V_26 - F_22 ( V_26 -> V_1 ) ;
}
static int F_25 ( struct V_23 * V_26 )
{
int V_27 ;
F_26 ( & V_28 ) ;
V_27 = F_27 ( & V_29 , V_26 , 0 , 0 , V_30 ) ;
if ( V_27 >= 0 )
V_26 -> V_31 = V_27 ;
F_28 ( & V_28 ) ;
return V_27 < 0 ? V_27 : 0 ;
}
static struct V_23 * F_29 ( int V_32 )
{
return F_30 ( & V_29 , V_32 ) ;
}
static struct V_23 * F_31 ( int V_1 , bool V_33 )
{
struct V_23 * V_34 = F_22 ( V_1 ) ;
return & V_34 [ V_33 ] ;
}
static struct V_35 * F_32 ( unsigned int V_1 ,
struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_10 & V_11 ) ) {
if ( F_33 ( V_1 < V_5 ) )
return F_34 ( V_9 -> V_36 . V_37 , V_1 ) ;
} else if ( F_33 ( V_1 == V_6 ) )
return V_9 -> V_36 . V_38 ;
return NULL ;
}
static unsigned int F_35 ( int V_39 )
{
return V_39 << V_40 ;
}
static int F_36 ( struct V_13 * V_17 )
{
return ( * F_10 ( V_17 ) >> V_40 ) &
( ( 1 << V_41 ) - 1 ) ;
}
static int F_37 ( int V_39 )
{
return ( V_39 + 1 ) % V_42 ;
}
static inline void F_38 ( struct V_13 * V_17 , unsigned long V_43 ,
unsigned long V_10 )
{
F_39 ( ! F_40 ( V_17 ) ) ;
F_41 ( & V_17 -> V_43 , V_43 | V_10 | F_42 ( V_17 ) ) ;
}
static void F_43 ( struct V_13 * V_17 , struct V_35 * V_44 ,
unsigned long V_45 )
{
F_38 ( V_17 , ( unsigned long ) V_44 ,
V_46 | V_47 | V_45 ) ;
}
static void F_44 ( struct V_13 * V_17 ,
int V_32 )
{
F_38 ( V_17 , ( unsigned long ) V_32 << V_48 ,
V_46 ) ;
}
static void F_45 ( struct V_13 * V_17 ,
int V_32 )
{
F_46 () ;
F_38 ( V_17 , ( unsigned long ) V_32 << V_48 , 0 ) ;
}
static void F_47 ( struct V_13 * V_17 )
{
F_46 () ;
F_38 ( V_17 , V_49 , 0 ) ;
}
static struct V_35 * F_48 ( struct V_13 * V_17 )
{
unsigned long V_43 = F_49 ( & V_17 -> V_43 ) ;
if ( V_43 & V_47 )
return ( void * ) ( V_43 & V_50 ) ;
else
return NULL ;
}
static struct V_23 * F_50 ( struct V_13 * V_17 )
{
unsigned long V_43 = F_49 ( & V_17 -> V_43 ) ;
struct V_23 * V_26 ;
int V_32 ;
if ( V_43 & V_47 )
return ( (struct V_35 * )
( V_43 & V_50 ) ) -> V_26 ;
V_32 = V_43 >> V_48 ;
if ( V_32 == V_51 )
return NULL ;
V_26 = F_29 ( V_32 ) ;
F_12 ( ! V_26 ) ;
return V_26 ;
}
static int F_51 ( struct V_13 * V_17 )
{
unsigned long V_43 = F_49 ( & V_17 -> V_43 ) ;
if ( V_43 & V_47 )
return ( (struct V_35 * )
( V_43 & V_50 ) ) -> V_26 -> V_31 ;
return V_43 >> V_48 ;
}
static void F_52 ( struct V_13 * V_17 )
{
unsigned long V_32 = F_51 ( V_17 ) ;
V_32 <<= V_48 ;
F_38 ( V_17 , V_32 | V_52 , V_46 ) ;
}
static bool F_53 ( struct V_13 * V_17 )
{
unsigned long V_43 = F_49 ( & V_17 -> V_43 ) ;
return ! ( V_43 & V_47 ) && ( V_43 & V_52 ) ;
}
static bool F_54 ( struct V_23 * V_26 )
{
return ! F_55 ( & V_26 -> V_53 ) ;
}
static bool F_56 ( struct V_23 * V_26 )
{
return ! F_57 ( & V_26 -> V_54 ) && F_54 ( V_26 ) ;
}
static bool F_58 ( struct V_23 * V_26 )
{
return V_26 -> V_55 ;
}
static bool F_59 ( struct V_23 * V_26 )
{
return ! F_57 ( & V_26 -> V_54 ) &&
F_55 ( & V_26 -> V_53 ) <= 1 ;
}
static bool F_60 ( struct V_23 * V_26 )
{
return F_56 ( V_26 ) && ! F_58 ( V_26 ) ;
}
static bool F_61 ( struct V_23 * V_26 )
{
return F_60 ( V_26 ) ||
( V_26 -> V_10 & V_56 ) ;
}
static bool F_62 ( struct V_23 * V_26 )
{
bool V_57 = V_26 -> V_10 & V_58 ;
int V_55 = V_26 -> V_55 + V_57 ;
int V_59 = V_26 -> V_60 - V_55 ;
if ( F_57 ( & V_26 -> V_61 ) )
return false ;
return V_55 > 2 && ( V_55 - 2 ) * V_62 >= V_59 ;
}
static struct V_63 * F_63 ( struct V_23 * V_26 )
{
if ( F_64 ( F_57 ( & V_26 -> V_61 ) ) )
return NULL ;
return F_65 ( & V_26 -> V_61 , struct V_63 , V_64 ) ;
}
static void F_66 ( struct V_23 * V_26 )
{
struct V_63 * V_63 = F_63 ( V_26 ) ;
if ( F_33 ( V_63 ) )
F_67 ( V_63 -> V_65 ) ;
}
void F_68 ( struct V_66 * V_65 , unsigned int V_1 )
{
struct V_63 * V_63 = F_69 ( V_65 ) ;
if ( ! ( V_63 -> V_10 & V_67 ) ) {
F_12 ( V_63 -> V_26 -> V_1 != V_1 ) ;
F_70 ( & V_63 -> V_26 -> V_53 ) ;
}
}
struct V_66 * F_71 ( struct V_66 * V_65 ,
unsigned int V_1 )
{
struct V_63 * V_63 = F_69 ( V_65 ) , * V_68 = NULL ;
struct V_23 * V_26 ;
if ( V_63 -> V_10 & V_67 )
return NULL ;
V_26 = V_63 -> V_26 ;
F_39 ( V_1 != F_72 () ) ;
if ( F_73 ( & V_26 -> V_53 ) &&
! F_57 ( & V_26 -> V_54 ) )
V_68 = F_63 ( V_26 ) ;
return V_68 ? V_68 -> V_65 : NULL ;
}
static inline void F_74 ( struct V_63 * V_63 , unsigned int V_10 ,
bool V_69 )
{
struct V_23 * V_26 = V_63 -> V_26 ;
F_12 ( V_63 -> V_65 != V_70 ) ;
if ( ( V_10 & V_67 ) &&
! ( V_63 -> V_10 & V_67 ) ) {
if ( V_69 ) {
if ( F_73 ( & V_26 -> V_53 ) &&
! F_57 ( & V_26 -> V_54 ) )
F_66 ( V_26 ) ;
} else
F_75 ( & V_26 -> V_53 ) ;
}
V_63 -> V_10 |= V_10 ;
}
static inline void F_76 ( struct V_63 * V_63 , unsigned int V_10 )
{
struct V_23 * V_26 = V_63 -> V_26 ;
unsigned int V_71 = V_63 -> V_10 ;
F_12 ( V_63 -> V_65 != V_70 ) ;
V_63 -> V_10 &= ~ V_10 ;
if ( ( V_10 & V_67 ) && ( V_71 & V_67 ) )
if ( ! ( V_63 -> V_10 & V_67 ) )
F_70 ( & V_26 -> V_53 ) ;
}
static struct V_63 * F_77 ( struct V_23 * V_26 ,
struct V_13 * V_17 )
{
struct V_63 * V_63 ;
F_78 (pool->busy_hash, worker, hentry,
(unsigned long)work)
if ( V_63 -> V_72 == V_17 &&
V_63 -> V_73 == V_17 -> V_14 )
return V_63 ;
return NULL ;
}
static void F_79 ( struct V_13 * V_17 , struct V_74 * V_75 ,
struct V_13 * * V_76 )
{
struct V_13 * V_77 ;
F_80 (work, n, NULL, entry) {
F_81 ( & V_17 -> V_64 , V_75 ) ;
if ( ! ( * F_10 ( V_17 ) & V_78 ) )
break;
}
if ( V_76 )
* V_76 = V_77 ;
}
static void F_82 ( struct V_13 * V_17 )
{
struct V_35 * V_44 = F_48 ( V_17 ) ;
F_83 ( V_17 ) ;
F_79 ( V_17 , & V_44 -> V_26 -> V_54 , NULL ) ;
F_84 ( V_79 , F_10 ( V_17 ) ) ;
V_44 -> V_80 ++ ;
}
static void F_85 ( struct V_35 * V_44 )
{
struct V_13 * V_17 = F_65 ( & V_44 -> V_81 ,
struct V_13 , V_64 ) ;
F_82 ( V_17 ) ;
}
static void F_86 ( struct V_35 * V_44 , int V_39 )
{
if ( V_39 == V_82 )
return;
V_44 -> V_83 [ V_39 ] -- ;
V_44 -> V_80 -- ;
if ( ! F_57 ( & V_44 -> V_81 ) ) {
if ( V_44 -> V_80 < V_44 -> V_84 )
F_85 ( V_44 ) ;
}
if ( F_33 ( V_44 -> V_85 != V_39 ) )
return;
if ( V_44 -> V_83 [ V_39 ] )
return;
V_44 -> V_85 = - 1 ;
if ( F_73 ( & V_44 -> V_9 -> V_86 ) )
F_87 ( & V_44 -> V_9 -> V_87 -> V_88 ) ;
}
static int F_88 ( struct V_13 * V_17 , bool V_89 ,
unsigned long * V_10 )
{
struct V_23 * V_26 ;
struct V_35 * V_44 ;
F_89 ( * V_10 ) ;
if ( V_89 ) {
struct V_90 * V_91 = F_90 ( V_17 ) ;
if ( F_33 ( F_91 ( & V_91 -> V_92 ) ) )
return 1 ;
}
if ( ! F_92 ( V_93 , F_10 ( V_17 ) ) )
return 0 ;
V_26 = F_50 ( V_17 ) ;
if ( ! V_26 )
goto V_94;
F_93 ( & V_26 -> V_95 ) ;
V_44 = F_48 ( V_17 ) ;
if ( V_44 && V_44 -> V_26 == V_26 ) {
F_17 ( V_17 ) ;
if ( * F_10 ( V_17 ) & V_96 )
F_82 ( V_17 ) ;
F_94 ( & V_17 -> V_64 ) ;
F_86 ( F_48 ( V_17 ) , F_36 ( V_17 ) ) ;
F_44 ( V_17 , V_26 -> V_31 ) ;
F_95 ( & V_26 -> V_95 ) ;
return 1 ;
}
F_95 ( & V_26 -> V_95 ) ;
V_94:
F_96 ( * V_10 ) ;
if ( F_53 ( V_17 ) )
return - V_97 ;
F_97 () ;
return - V_98 ;
}
static void F_98 ( struct V_35 * V_44 , struct V_13 * V_17 ,
struct V_74 * V_75 , unsigned int V_45 )
{
struct V_23 * V_26 = V_44 -> V_26 ;
F_43 ( V_17 , V_44 , V_45 ) ;
F_99 ( & V_17 -> V_64 , V_75 ) ;
F_100 () ;
if ( F_54 ( V_26 ) )
F_66 ( V_26 ) ;
}
static bool F_101 ( struct V_8 * V_9 )
{
struct V_63 * V_63 ;
V_63 = F_102 () ;
return V_63 && V_63 -> V_99 -> V_9 == V_9 ;
}
static void F_103 ( unsigned int V_1 , struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_35 * V_44 ;
struct V_74 * V_54 ;
unsigned int V_100 ;
unsigned int V_101 = V_1 ;
F_12 ( ! F_104 () ) ;
F_16 ( V_17 ) ;
if ( F_64 ( V_9 -> V_10 & V_102 ) &&
F_12 ( ! F_101 ( V_9 ) ) )
return;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_23 * V_103 ;
if ( V_1 == V_6 )
V_1 = F_72 () ;
V_44 = F_32 ( V_1 , V_9 ) ;
V_103 = F_50 ( V_17 ) ;
if ( V_103 && V_103 != V_44 -> V_26 ) {
struct V_63 * V_63 ;
F_93 ( & V_103 -> V_95 ) ;
V_63 = F_77 ( V_103 , V_17 ) ;
if ( V_63 && V_63 -> V_99 -> V_9 == V_9 ) {
V_44 = F_32 ( V_103 -> V_1 , V_9 ) ;
} else {
F_95 ( & V_103 -> V_95 ) ;
F_93 ( & V_44 -> V_26 -> V_95 ) ;
}
} else {
F_93 ( & V_44 -> V_26 -> V_95 ) ;
}
} else {
V_44 = F_32 ( V_6 , V_9 ) ;
F_93 ( & V_44 -> V_26 -> V_95 ) ;
}
F_105 ( V_101 , V_44 , V_17 ) ;
if ( F_13 ( ! F_57 ( & V_17 -> V_64 ) ) ) {
F_95 ( & V_44 -> V_26 -> V_95 ) ;
return;
}
V_44 -> V_83 [ V_44 -> V_104 ] ++ ;
V_100 = F_35 ( V_44 -> V_104 ) ;
if ( F_33 ( V_44 -> V_80 < V_44 -> V_84 ) ) {
F_83 ( V_17 ) ;
V_44 -> V_80 ++ ;
V_54 = & V_44 -> V_26 -> V_54 ;
} else {
V_100 |= V_96 ;
V_54 = & V_44 -> V_81 ;
}
F_98 ( V_44 , V_17 , V_54 , V_100 ) ;
F_95 ( & V_44 -> V_26 -> V_95 ) ;
}
bool F_106 ( int V_1 , struct V_8 * V_9 ,
struct V_13 * V_17 )
{
bool V_27 = false ;
unsigned long V_10 ;
F_89 ( V_10 ) ;
if ( ! F_92 ( V_93 , F_10 ( V_17 ) ) ) {
F_103 ( V_1 , V_9 , V_17 ) ;
V_27 = true ;
}
F_96 ( V_10 ) ;
return V_27 ;
}
bool F_107 ( struct V_8 * V_9 , struct V_13 * V_17 )
{
return F_106 ( V_6 , V_9 , V_17 ) ;
}
void F_108 ( unsigned long V_105 )
{
struct V_90 * V_91 = (struct V_90 * ) V_105 ;
F_103 ( V_91 -> V_1 , V_91 -> V_9 , & V_91 -> V_17 ) ;
}
static void F_109 ( int V_1 , struct V_8 * V_9 ,
struct V_90 * V_91 , unsigned long V_106 )
{
struct V_107 * V_92 = & V_91 -> V_92 ;
struct V_13 * V_17 = & V_91 -> V_17 ;
F_12 ( V_92 -> V_108 != F_108 ||
V_92 -> V_43 != ( unsigned long ) V_91 ) ;
F_12 ( F_110 ( V_92 ) ) ;
F_12 ( ! F_57 ( & V_17 -> V_64 ) ) ;
if ( ! V_106 ) {
F_103 ( V_1 , V_9 , & V_91 -> V_17 ) ;
return;
}
F_111 ( & V_91 -> V_92 ) ;
V_91 -> V_9 = V_9 ;
V_91 -> V_1 = V_1 ;
V_92 -> V_109 = V_110 + V_106 ;
if ( F_64 ( V_1 != V_6 ) )
F_112 ( V_92 , V_1 ) ;
else
F_113 ( V_92 ) ;
}
bool F_114 ( int V_1 , struct V_8 * V_9 ,
struct V_90 * V_91 , unsigned long V_106 )
{
struct V_13 * V_17 = & V_91 -> V_17 ;
bool V_27 = false ;
unsigned long V_10 ;
F_89 ( V_10 ) ;
if ( ! F_92 ( V_93 , F_10 ( V_17 ) ) ) {
F_109 ( V_1 , V_9 , V_91 , V_106 ) ;
V_27 = true ;
}
F_96 ( V_10 ) ;
return V_27 ;
}
bool F_115 ( struct V_8 * V_9 ,
struct V_90 * V_91 , unsigned long V_106 )
{
return F_114 ( V_6 , V_9 , V_91 , V_106 ) ;
}
bool F_116 ( int V_1 , struct V_8 * V_9 ,
struct V_90 * V_91 , unsigned long V_106 )
{
unsigned long V_10 ;
int V_27 ;
do {
V_27 = F_88 ( & V_91 -> V_17 , true , & V_10 ) ;
} while ( F_64 ( V_27 == - V_98 ) );
if ( F_33 ( V_27 >= 0 ) ) {
F_109 ( V_1 , V_9 , V_91 , V_106 ) ;
F_96 ( V_10 ) ;
}
return V_27 ;
}
bool F_117 ( struct V_8 * V_9 , struct V_90 * V_91 ,
unsigned long V_106 )
{
return F_116 ( V_6 , V_9 , V_91 , V_106 ) ;
}
static void F_118 ( struct V_63 * V_63 )
{
struct V_23 * V_26 = V_63 -> V_26 ;
F_39 ( V_63 -> V_10 & V_111 ) ;
F_39 ( ! F_57 ( & V_63 -> V_64 ) &&
( V_63 -> V_112 . V_113 || V_63 -> V_112 . V_114 ) ) ;
V_63 -> V_10 |= V_111 ;
V_26 -> V_55 ++ ;
V_63 -> V_115 = V_110 ;
F_119 ( & V_63 -> V_64 , & V_26 -> V_61 ) ;
if ( F_62 ( V_26 ) && ! F_110 ( & V_26 -> V_116 ) )
F_120 ( & V_26 -> V_116 , V_110 + V_117 ) ;
F_12 ( ! ( V_26 -> V_10 & V_118 ) &&
V_26 -> V_60 == V_26 -> V_55 &&
F_55 ( & V_26 -> V_53 ) ) ;
}
static void F_121 ( struct V_63 * V_63 )
{
struct V_23 * V_26 = V_63 -> V_26 ;
F_39 ( ! ( V_63 -> V_10 & V_111 ) ) ;
F_76 ( V_63 , V_111 ) ;
V_26 -> V_55 -- ;
F_94 ( & V_63 -> V_64 ) ;
}
static bool F_122 ( struct V_63 * V_63 )
__acquires( &pool->lock
static void F_123 ( struct V_63 * V_63 )
{
if ( F_122 ( V_63 ) )
F_76 ( V_63 , V_119 ) ;
F_119 ( & V_63 -> V_64 , & V_63 -> V_26 -> V_61 ) ;
F_124 ( & V_63 -> V_26 -> V_95 ) ;
}
static void F_125 ( struct V_13 * V_17 )
{
struct V_63 * V_63 = F_126 ( V_17 , struct V_63 , V_120 ) ;
if ( F_122 ( V_63 ) )
F_76 ( V_63 , V_119 ) ;
F_124 ( & V_63 -> V_26 -> V_95 ) ;
}
static void F_127 ( struct V_23 * V_26 )
{
struct V_63 * V_63 , * V_77 ;
int V_121 ;
F_128 ( & V_26 -> V_122 ) ;
F_128 ( & V_26 -> V_95 ) ;
F_129 (worker, n, &pool->idle_list, entry) {
F_94 ( & V_63 -> V_64 ) ;
F_67 ( V_63 -> V_65 ) ;
}
F_130 (worker, i, pool) {
struct V_13 * V_120 = & V_63 -> V_120 ;
struct V_8 * V_9 ;
if ( F_92 ( V_93 ,
F_10 ( V_120 ) ) )
continue;
F_16 ( V_120 ) ;
if ( F_24 ( V_63 -> V_26 ) )
V_9 = V_123 ;
else
V_9 = V_124 ;
F_98 ( F_32 ( V_26 -> V_1 , V_9 ) , V_120 ,
V_63 -> V_125 . V_113 ,
F_35 ( V_82 ) ) ;
}
}
static struct V_63 * F_131 ( void )
{
struct V_63 * V_63 ;
V_63 = F_132 ( sizeof( * V_63 ) , V_30 ) ;
if ( V_63 ) {
F_133 ( & V_63 -> V_64 ) ;
F_133 ( & V_63 -> V_125 ) ;
F_134 ( & V_63 -> V_120 , F_125 ) ;
V_63 -> V_10 = V_126 ;
}
return V_63 ;
}
static struct V_63 * F_135 ( struct V_23 * V_26 )
{
const char * V_127 = F_24 ( V_26 ) ? L_1 : L_2 ;
struct V_63 * V_63 = NULL ;
int V_31 = - 1 ;
F_136 ( & V_26 -> V_95 ) ;
while ( F_137 ( & V_26 -> V_128 , & V_31 ) ) {
F_124 ( & V_26 -> V_95 ) ;
if ( ! F_138 ( & V_26 -> V_128 , V_30 ) )
goto V_94;
F_136 ( & V_26 -> V_95 ) ;
}
F_124 ( & V_26 -> V_95 ) ;
V_63 = F_131 () ;
if ( ! V_63 )
goto V_94;
V_63 -> V_26 = V_26 ;
V_63 -> V_31 = V_31 ;
if ( V_26 -> V_1 != V_6 )
V_63 -> V_65 = F_139 ( V_129 ,
V_63 , F_140 ( V_26 -> V_1 ) ,
L_3 , V_26 -> V_1 , V_31 , V_127 ) ;
else
V_63 -> V_65 = F_141 ( V_129 , V_63 ,
L_4 , V_31 , V_127 ) ;
if ( F_142 ( V_63 -> V_65 ) )
goto V_94;
if ( F_24 ( V_26 ) )
F_143 ( V_63 -> V_65 , V_130 ) ;
if ( ! ( V_26 -> V_10 & V_118 ) ) {
F_144 ( V_63 -> V_65 , V_26 -> V_1 ) ;
} else {
V_63 -> V_65 -> V_10 |= V_131 ;
V_63 -> V_10 |= V_119 ;
}
return V_63 ;
V_94:
if ( V_31 >= 0 ) {
F_136 ( & V_26 -> V_95 ) ;
F_145 ( & V_26 -> V_128 , V_31 ) ;
F_124 ( & V_26 -> V_95 ) ;
}
F_146 ( V_63 ) ;
return NULL ;
}
static void F_147 ( struct V_63 * V_63 )
{
V_63 -> V_10 |= V_132 ;
V_63 -> V_26 -> V_60 ++ ;
F_118 ( V_63 ) ;
F_67 ( V_63 -> V_65 ) ;
}
static void F_148 ( struct V_63 * V_63 )
{
struct V_23 * V_26 = V_63 -> V_26 ;
int V_31 = V_63 -> V_31 ;
F_39 ( V_63 -> V_72 ) ;
F_39 ( ! F_57 ( & V_63 -> V_125 ) ) ;
if ( V_63 -> V_10 & V_132 )
V_26 -> V_60 -- ;
if ( V_63 -> V_10 & V_111 )
V_26 -> V_55 -- ;
F_94 ( & V_63 -> V_64 ) ;
V_63 -> V_10 |= V_133 ;
F_124 ( & V_26 -> V_95 ) ;
F_149 ( V_63 -> V_65 ) ;
F_146 ( V_63 ) ;
F_136 ( & V_26 -> V_95 ) ;
F_145 ( & V_26 -> V_128 , V_31 ) ;
}
static void F_150 ( unsigned long V_134 )
{
struct V_23 * V_26 = ( void * ) V_134 ;
F_136 ( & V_26 -> V_95 ) ;
if ( F_62 ( V_26 ) ) {
struct V_63 * V_63 ;
unsigned long V_109 ;
V_63 = F_151 ( V_26 -> V_61 . V_135 , struct V_63 , V_64 ) ;
V_109 = V_63 -> V_115 + V_117 ;
if ( F_152 ( V_110 , V_109 ) )
F_120 ( & V_26 -> V_116 , V_109 ) ;
else {
V_26 -> V_10 |= V_56 ;
F_66 ( V_26 ) ;
}
}
F_124 ( & V_26 -> V_95 ) ;
}
static bool F_153 ( struct V_13 * V_17 )
{
struct V_35 * V_44 = F_48 ( V_17 ) ;
struct V_8 * V_9 = V_44 -> V_9 ;
unsigned int V_1 ;
if ( ! ( V_9 -> V_10 & V_136 ) )
return false ;
V_1 = V_44 -> V_26 -> V_1 ;
if ( V_1 == V_6 )
V_1 = 0 ;
if ( ! F_154 ( V_1 , V_9 -> V_137 ) )
F_67 ( V_9 -> V_138 -> V_65 ) ;
return true ;
}
static void F_155 ( unsigned long V_134 )
{
struct V_23 * V_26 = ( void * ) V_134 ;
struct V_13 * V_17 ;
F_136 ( & V_26 -> V_95 ) ;
if ( F_60 ( V_26 ) ) {
F_156 (work, &pool->worklist, entry)
F_153 ( V_17 ) ;
}
F_124 ( & V_26 -> V_95 ) ;
F_120 ( & V_26 -> V_139 , V_110 + V_140 ) ;
}
static bool F_157 ( struct V_23 * V_26 )
__releases( &pool->lock
static bool F_158 ( struct V_23 * V_26 )
{
bool V_27 = false ;
while ( F_62 ( V_26 ) ) {
struct V_63 * V_63 ;
unsigned long V_109 ;
V_63 = F_151 ( V_26 -> V_61 . V_135 , struct V_63 , V_64 ) ;
V_109 = V_63 -> V_115 + V_117 ;
if ( F_152 ( V_110 , V_109 ) ) {
F_120 ( & V_26 -> V_116 , V_109 ) ;
break;
}
F_148 ( V_63 ) ;
V_27 = true ;
}
return V_27 ;
}
static bool F_159 ( struct V_63 * V_63 )
{
struct V_23 * V_26 = V_63 -> V_26 ;
bool V_27 = false ;
if ( V_26 -> V_10 & V_58 )
return V_27 ;
V_26 -> V_10 |= V_58 ;
if ( F_64 ( ! F_160 ( & V_26 -> V_122 ) ) ) {
F_124 ( & V_26 -> V_95 ) ;
F_26 ( & V_26 -> V_122 ) ;
if ( F_122 ( V_63 ) )
V_63 -> V_10 &= ~ V_119 ;
else
V_63 -> V_10 |= V_119 ;
V_27 = true ;
}
V_26 -> V_10 &= ~ V_56 ;
V_27 |= F_158 ( V_26 ) ;
V_27 |= F_157 ( V_26 ) ;
V_26 -> V_10 &= ~ V_58 ;
F_28 ( & V_26 -> V_122 ) ;
return V_27 ;
}
static void F_161 ( struct V_63 * V_63 , struct V_13 * V_17 )
__releases( &pool->lock
static void F_162 ( struct V_63 * V_63 )
{
while ( ! F_57 ( & V_63 -> V_125 ) ) {
struct V_13 * V_17 = F_65 ( & V_63 -> V_125 ,
struct V_13 , V_64 ) ;
F_161 ( V_63 , V_17 ) ;
}
}
static int V_129 ( void * V_141 )
{
struct V_63 * V_63 = V_141 ;
struct V_23 * V_26 = V_63 -> V_26 ;
V_63 -> V_65 -> V_10 |= V_142 ;
V_143:
F_136 ( & V_26 -> V_95 ) ;
if ( F_64 ( F_57 ( & V_63 -> V_64 ) ) ) {
F_124 ( & V_26 -> V_95 ) ;
if ( V_63 -> V_10 & V_133 ) {
V_63 -> V_65 -> V_10 &= ~ V_142 ;
return 0 ;
}
F_123 ( V_63 ) ;
goto V_143;
}
F_121 ( V_63 ) ;
V_144:
if ( ! F_56 ( V_26 ) )
goto V_145;
if ( F_64 ( ! F_58 ( V_26 ) ) && F_159 ( V_63 ) )
goto V_144;
F_39 ( ! F_57 ( & V_63 -> V_125 ) ) ;
F_76 ( V_63 , V_126 ) ;
do {
struct V_13 * V_17 =
F_65 ( & V_26 -> V_54 ,
struct V_13 , V_64 ) ;
if ( F_33 ( ! ( * F_10 ( V_17 ) & V_78 ) ) ) {
F_161 ( V_63 , V_17 ) ;
if ( F_64 ( ! F_57 ( & V_63 -> V_125 ) ) )
F_162 ( V_63 ) ;
} else {
F_79 ( V_17 , & V_63 -> V_125 , NULL ) ;
F_162 ( V_63 ) ;
}
} while ( F_59 ( V_26 ) );
F_74 ( V_63 , V_126 , false ) ;
V_145:
if ( F_64 ( F_61 ( V_26 ) ) && F_159 ( V_63 ) )
goto V_144;
F_118 ( V_63 ) ;
F_163 ( V_146 ) ;
F_124 ( & V_26 -> V_95 ) ;
F_164 () ;
goto V_143;
}
static int F_165 ( void * V_147 )
{
struct V_63 * V_138 = V_147 ;
struct V_8 * V_9 = V_138 -> V_148 ;
struct V_74 * V_125 = & V_138 -> V_125 ;
bool V_149 = V_9 -> V_10 & V_11 ;
unsigned int V_1 ;
F_143 ( V_70 , V_150 ) ;
V_138 -> V_65 -> V_10 |= V_142 ;
V_151:
F_166 ( V_146 ) ;
if ( F_167 () ) {
F_163 ( V_152 ) ;
V_138 -> V_65 -> V_10 &= ~ V_142 ;
return 0 ;
}
F_168 (cpu, wq->mayday_mask) {
unsigned int V_153 = V_149 ? V_6 : V_1 ;
struct V_35 * V_44 = F_32 ( V_153 , V_9 ) ;
struct V_23 * V_26 = V_44 -> V_26 ;
struct V_13 * V_17 , * V_77 ;
F_163 ( V_152 ) ;
F_169 ( V_1 , V_9 -> V_137 ) ;
V_138 -> V_26 = V_26 ;
F_122 ( V_138 ) ;
F_39 ( ! F_57 ( & V_138 -> V_125 ) ) ;
F_129 (work, n, &pool->worklist, entry)
if ( F_48 ( V_17 ) == V_44 )
F_79 ( V_17 , V_125 , & V_77 ) ;
F_162 ( V_138 ) ;
if ( F_59 ( V_26 ) )
F_66 ( V_26 ) ;
F_124 ( & V_26 -> V_95 ) ;
}
F_12 ( ! ( V_138 -> V_10 & V_67 ) ) ;
F_164 () ;
goto V_151;
}
static void F_170 ( struct V_13 * V_17 )
{
struct V_154 * V_155 = F_126 ( V_17 , struct V_154 , V_17 ) ;
F_87 ( & V_155 -> V_88 ) ;
}
static void F_171 ( struct V_35 * V_44 ,
struct V_154 * V_155 ,
struct V_13 * V_156 , struct V_63 * V_63 )
{
struct V_74 * V_75 ;
unsigned int V_157 = 0 ;
F_172 ( & V_155 -> V_17 , F_170 ) ;
F_173 ( V_93 , F_10 ( & V_155 -> V_17 ) ) ;
F_174 ( & V_155 -> V_88 ) ;
if ( V_63 )
V_75 = V_63 -> V_125 . V_113 ;
else {
unsigned long * V_158 = F_10 ( V_156 ) ;
V_75 = V_156 -> V_64 . V_113 ;
V_157 = * V_158 & V_78 ;
F_173 ( V_159 , V_158 ) ;
}
F_16 ( & V_155 -> V_17 ) ;
F_98 ( V_44 , & V_155 -> V_17 , V_75 ,
F_35 ( V_82 ) | V_157 ) ;
}
static bool F_175 ( struct V_8 * V_9 ,
int V_85 , int V_104 )
{
bool V_160 = false ;
unsigned int V_1 ;
if ( V_85 >= 0 ) {
F_39 ( F_55 ( & V_9 -> V_86 ) ) ;
F_176 ( & V_9 -> V_86 , 1 ) ;
}
F_177 (cpu, wq) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
struct V_23 * V_26 = V_44 -> V_26 ;
F_136 ( & V_26 -> V_95 ) ;
if ( V_85 >= 0 ) {
F_39 ( V_44 -> V_85 != - 1 ) ;
if ( V_44 -> V_83 [ V_85 ] ) {
V_44 -> V_85 = V_85 ;
F_70 ( & V_9 -> V_86 ) ;
V_160 = true ;
}
}
if ( V_104 >= 0 ) {
F_39 ( V_104 != F_37 ( V_44 -> V_104 ) ) ;
V_44 -> V_104 = V_104 ;
}
F_124 ( & V_26 -> V_95 ) ;
}
if ( V_85 >= 0 && F_73 ( & V_9 -> V_86 ) )
F_87 ( & V_9 -> V_87 -> V_88 ) ;
return V_160 ;
}
void F_178 ( struct V_8 * V_9 )
{
struct V_161 V_162 = {
. V_163 = F_179 ( V_162 . V_163 ) ,
. V_85 = - 1 ,
. V_88 = F_180 ( V_162 . V_88 ) ,
} ;
int V_164 ;
F_181 ( & V_9 -> V_165 ) ;
F_182 ( & V_9 -> V_165 ) ;
F_26 ( & V_9 -> V_166 ) ;
V_164 = F_37 ( V_9 -> V_104 ) ;
if ( V_164 != V_9 -> V_85 ) {
F_39 ( ! F_57 ( & V_9 -> V_167 ) ) ;
V_162 . V_85 = V_9 -> V_104 ;
V_9 -> V_104 = V_164 ;
if ( ! V_9 -> V_87 ) {
F_39 ( V_9 -> V_85 != V_162 . V_85 ) ;
V_9 -> V_87 = & V_162 ;
if ( ! F_175 ( V_9 , V_9 -> V_85 ,
V_9 -> V_104 ) ) {
V_9 -> V_85 = V_164 ;
V_9 -> V_87 = NULL ;
goto V_168;
}
} else {
F_39 ( V_9 -> V_85 == V_162 . V_85 ) ;
F_99 ( & V_162 . V_163 , & V_9 -> V_169 ) ;
F_175 ( V_9 , - 1 , V_9 -> V_104 ) ;
}
} else {
F_99 ( & V_162 . V_163 , & V_9 -> V_167 ) ;
}
F_28 ( & V_9 -> V_166 ) ;
F_183 ( & V_162 . V_88 ) ;
if ( V_9 -> V_87 != & V_162 )
return;
F_26 ( & V_9 -> V_166 ) ;
if ( V_9 -> V_87 != & V_162 )
goto V_168;
V_9 -> V_87 = NULL ;
F_39 ( ! F_57 ( & V_162 . V_163 ) ) ;
F_39 ( V_9 -> V_85 != V_162 . V_85 ) ;
while ( true ) {
struct V_161 * V_113 , * V_170 ;
F_129 (next, tmp, &wq->flusher_queue, list) {
if ( V_113 -> V_85 != V_9 -> V_85 )
break;
F_94 ( & V_113 -> V_163 ) ;
F_87 ( & V_113 -> V_88 ) ;
}
F_39 ( ! F_57 ( & V_9 -> V_167 ) &&
V_9 -> V_85 != F_37 ( V_9 -> V_104 ) ) ;
V_9 -> V_85 = F_37 ( V_9 -> V_85 ) ;
if ( ! F_57 ( & V_9 -> V_167 ) ) {
F_156 (tmp, &wq->flusher_overflow, list)
V_170 -> V_85 = V_9 -> V_104 ;
V_9 -> V_104 = F_37 ( V_9 -> V_104 ) ;
F_184 ( & V_9 -> V_167 ,
& V_9 -> V_169 ) ;
F_175 ( V_9 , - 1 , V_9 -> V_104 ) ;
}
if ( F_57 ( & V_9 -> V_169 ) ) {
F_39 ( V_9 -> V_85 != V_9 -> V_104 ) ;
break;
}
F_39 ( V_9 -> V_85 == V_9 -> V_104 ) ;
F_39 ( V_9 -> V_85 != V_113 -> V_85 ) ;
F_94 ( & V_113 -> V_163 ) ;
V_9 -> V_87 = V_113 ;
if ( F_175 ( V_9 , V_9 -> V_85 , - 1 ) )
break;
V_9 -> V_87 = NULL ;
}
V_168:
F_28 ( & V_9 -> V_166 ) ;
}
void F_185 ( struct V_8 * V_9 )
{
unsigned int V_171 = 0 ;
unsigned int V_1 ;
F_93 ( & V_172 ) ;
if ( ! V_9 -> V_173 ++ )
V_9 -> V_10 |= V_102 ;
F_95 ( & V_172 ) ;
V_174:
F_178 ( V_9 ) ;
F_177 (cpu, wq) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
bool V_175 ;
F_136 ( & V_44 -> V_26 -> V_95 ) ;
V_175 = ! V_44 -> V_80 && F_57 ( & V_44 -> V_81 ) ;
F_124 ( & V_44 -> V_26 -> V_95 ) ;
if ( V_175 )
continue;
if ( ++ V_171 == 10 ||
( V_171 % 100 == 0 && V_171 <= 1000 ) )
F_186 ( L_5 ,
V_9 -> V_176 , V_171 ) ;
goto V_174;
}
F_93 ( & V_172 ) ;
if ( ! -- V_9 -> V_173 )
V_9 -> V_10 &= ~ V_102 ;
F_95 ( & V_172 ) ;
}
static bool F_187 ( struct V_13 * V_17 , struct V_154 * V_155 )
{
struct V_63 * V_63 = NULL ;
struct V_23 * V_26 ;
struct V_35 * V_44 ;
F_188 () ;
V_26 = F_50 ( V_17 ) ;
if ( ! V_26 )
return false ;
F_136 ( & V_26 -> V_95 ) ;
V_44 = F_48 ( V_17 ) ;
if ( V_44 ) {
if ( F_64 ( V_44 -> V_26 != V_26 ) )
goto V_177;
} else {
V_63 = F_77 ( V_26 , V_17 ) ;
if ( ! V_63 )
goto V_177;
V_44 = V_63 -> V_99 ;
}
F_171 ( V_44 , V_155 , V_17 , V_63 ) ;
F_124 ( & V_26 -> V_95 ) ;
if ( V_44 -> V_9 -> V_178 == 1 || V_44 -> V_9 -> V_10 & V_136 )
F_181 ( & V_44 -> V_9 -> V_165 ) ;
else
F_189 ( & V_44 -> V_9 -> V_165 ) ;
F_182 ( & V_44 -> V_9 -> V_165 ) ;
return true ;
V_177:
F_124 ( & V_26 -> V_95 ) ;
return false ;
}
bool F_190 ( struct V_13 * V_17 )
{
struct V_154 V_155 ;
F_181 ( & V_17 -> V_165 ) ;
F_182 ( & V_17 -> V_165 ) ;
if ( F_187 ( V_17 , & V_155 ) ) {
F_183 ( & V_155 . V_88 ) ;
F_21 ( & V_155 . V_17 ) ;
return true ;
} else {
return false ;
}
}
static bool F_191 ( struct V_13 * V_17 , bool V_89 )
{
unsigned long V_10 ;
int V_27 ;
do {
V_27 = F_88 ( V_17 , V_89 , & V_10 ) ;
if ( F_64 ( V_27 == - V_97 ) )
F_190 ( V_17 ) ;
} while ( F_64 ( V_27 < 0 ) );
F_52 ( V_17 ) ;
F_96 ( V_10 ) ;
F_190 ( V_17 ) ;
F_47 ( V_17 ) ;
return V_27 ;
}
bool F_6 ( struct V_13 * V_17 )
{
return F_191 ( V_17 , false ) ;
}
bool F_192 ( struct V_90 * V_91 )
{
F_193 () ;
if ( F_194 ( & V_91 -> V_92 ) )
F_103 ( V_91 -> V_1 , V_91 -> V_9 , & V_91 -> V_17 ) ;
F_195 () ;
return F_190 ( & V_91 -> V_17 ) ;
}
bool F_196 ( struct V_90 * V_91 )
{
unsigned long V_10 ;
int V_27 ;
do {
V_27 = F_88 ( & V_91 -> V_17 , true , & V_10 ) ;
} while ( F_64 ( V_27 == - V_98 ) );
if ( F_64 ( V_27 < 0 ) )
return false ;
F_45 ( & V_91 -> V_17 ,
F_51 ( & V_91 -> V_17 ) ) ;
F_96 ( V_10 ) ;
return V_27 ;
}
bool F_197 ( struct V_90 * V_91 )
{
return F_191 ( & V_91 -> V_17 , true ) ;
}
bool F_198 ( int V_1 , struct V_13 * V_17 )
{
return F_106 ( V_1 , V_124 , V_17 ) ;
}
bool F_199 ( struct V_13 * V_17 )
{
return F_107 ( V_124 , V_17 ) ;
}
bool F_200 ( int V_1 , struct V_90 * V_91 ,
unsigned long V_106 )
{
return F_114 ( V_1 , V_124 , V_91 , V_106 ) ;
}
bool F_201 ( struct V_90 * V_91 , unsigned long V_106 )
{
return F_115 ( V_124 , V_91 , V_106 ) ;
}
int F_202 ( T_1 V_14 )
{
int V_1 ;
struct V_13 T_2 * V_179 ;
V_179 = F_203 ( struct V_13 ) ;
if ( ! V_179 )
return - V_180 ;
F_204 () ;
F_205 (cpu) {
struct V_13 * V_17 = F_34 ( V_179 , V_1 ) ;
F_134 ( V_17 , V_14 ) ;
F_198 ( V_1 , V_17 ) ;
}
F_205 (cpu)
F_190 ( F_34 ( V_179 , V_1 ) ) ;
F_206 () ;
F_207 ( V_179 ) ;
return 0 ;
}
void F_208 ( void )
{
F_178 ( V_124 ) ;
}
int F_209 ( T_1 V_181 , struct V_182 * V_183 )
{
if ( ! F_210 () ) {
V_181 ( & V_183 -> V_17 ) ;
return 0 ;
}
F_134 ( & V_183 -> V_17 , V_181 ) ;
F_199 ( & V_183 -> V_17 ) ;
return 1 ;
}
int F_211 ( void )
{
return V_124 != NULL ;
}
static int F_212 ( struct V_8 * V_9 )
{
const T_3 V_184 = sizeof( struct V_35 ) ;
const T_3 V_185 = F_213 ( T_3 , 1 << V_186 ,
F_214 (unsigned long long) ) ;
if ( ! ( V_9 -> V_10 & V_11 ) )
V_9 -> V_36 . V_37 = F_215 ( V_184 , V_185 ) ;
else {
void * V_187 ;
V_187 = F_132 ( V_184 + V_185 + sizeof( void * ) , V_30 ) ;
if ( V_187 ) {
V_9 -> V_36 . V_38 = F_216 ( V_187 , V_185 ) ;
* ( void * * ) ( V_9 -> V_36 . V_38 + 1 ) = V_187 ;
}
}
F_39 ( ! F_217 ( V_9 -> V_36 . V_188 , V_185 ) ) ;
return V_9 -> V_36 . V_188 ? 0 : - V_180 ;
}
static void F_218 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_10 & V_11 ) )
F_207 ( V_9 -> V_36 . V_37 ) ;
else if ( V_9 -> V_36 . V_38 ) {
F_146 ( * ( void * * ) ( V_9 -> V_36 . V_38 + 1 ) ) ;
}
}
static int F_219 ( int V_84 , unsigned int V_10 ,
const char * V_176 )
{
int V_189 = V_10 & V_11 ? V_190 : V_191 ;
if ( V_84 < 1 || V_84 > V_189 )
F_186 ( L_6 ,
V_84 , V_176 , 1 , V_189 ) ;
return F_220 ( V_84 , 1 , V_189 ) ;
}
struct V_8 * F_221 ( const char * V_192 ,
unsigned int V_10 ,
int V_84 ,
struct V_193 * V_194 ,
const char * V_195 , ... )
{
T_4 args , V_196 ;
struct V_8 * V_9 ;
unsigned int V_1 ;
T_3 V_197 ;
va_start ( args , V_195 ) ;
F_222 ( V_196 , args ) ;
V_197 = vsnprintf ( NULL , 0 , V_192 , args ) + 1 ;
V_9 = F_132 ( sizeof( * V_9 ) + V_197 , V_30 ) ;
if ( ! V_9 )
goto V_198;
vsnprintf ( V_9 -> V_176 , V_197 , V_192 , V_196 ) ;
va_end ( args ) ;
va_end ( V_196 ) ;
if ( V_10 & V_199 )
V_10 |= V_136 ;
V_84 = V_84 ? : V_200 ;
V_84 = F_219 ( V_84 , V_10 , V_9 -> V_176 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_178 = V_84 ;
F_223 ( & V_9 -> V_166 ) ;
F_176 ( & V_9 -> V_86 , 0 ) ;
F_133 ( & V_9 -> V_169 ) ;
F_133 ( & V_9 -> V_167 ) ;
F_224 ( & V_9 -> V_165 , V_195 , V_194 , 0 ) ;
F_133 ( & V_9 -> V_163 ) ;
if ( F_212 ( V_9 ) < 0 )
goto V_198;
F_177 (cpu, wq) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
F_39 ( ( unsigned long ) V_44 & V_201 ) ;
V_44 -> V_26 = F_31 ( V_1 , V_10 & V_202 ) ;
V_44 -> V_9 = V_9 ;
V_44 -> V_85 = - 1 ;
V_44 -> V_84 = V_84 ;
F_133 ( & V_44 -> V_81 ) ;
}
if ( V_10 & V_136 ) {
struct V_63 * V_138 ;
if ( ! F_225 ( & V_9 -> V_137 , V_30 ) )
goto V_198;
V_9 -> V_138 = V_138 = F_131 () ;
if ( ! V_138 )
goto V_198;
V_138 -> V_148 = V_9 ;
V_138 -> V_65 = F_141 ( F_165 , V_138 , L_7 ,
V_9 -> V_176 ) ;
if ( F_142 ( V_138 -> V_65 ) )
goto V_198;
V_138 -> V_65 -> V_10 |= V_131 ;
F_67 ( V_138 -> V_65 ) ;
}
F_93 ( & V_172 ) ;
if ( V_203 && V_9 -> V_10 & V_204 )
F_177 (cpu, wq)
F_32 ( V_1 , V_9 ) -> V_84 = 0 ;
F_119 ( & V_9 -> V_163 , & V_205 ) ;
F_95 ( & V_172 ) ;
return V_9 ;
V_198:
if ( V_9 ) {
F_218 ( V_9 ) ;
F_226 ( V_9 -> V_137 ) ;
F_146 ( V_9 -> V_138 ) ;
F_146 ( V_9 ) ;
}
return NULL ;
}
void F_227 ( struct V_8 * V_9 )
{
unsigned int V_1 ;
F_185 ( V_9 ) ;
F_93 ( & V_172 ) ;
F_228 ( & V_9 -> V_163 ) ;
F_95 ( & V_172 ) ;
F_177 (cpu, wq) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
int V_121 ;
for ( V_121 = 0 ; V_121 < V_42 ; V_121 ++ )
F_39 ( V_44 -> V_83 [ V_121 ] ) ;
F_39 ( V_44 -> V_80 ) ;
F_39 ( ! F_57 ( & V_44 -> V_81 ) ) ;
}
if ( V_9 -> V_10 & V_136 ) {
F_149 ( V_9 -> V_138 -> V_65 ) ;
F_226 ( V_9 -> V_137 ) ;
F_146 ( V_9 -> V_138 ) ;
}
F_218 ( V_9 ) ;
F_146 ( V_9 ) ;
}
static void F_229 ( struct V_35 * V_44 , int V_84 )
{
V_44 -> V_84 = V_84 ;
while ( ! F_57 ( & V_44 -> V_81 ) &&
V_44 -> V_80 < V_44 -> V_84 )
F_85 ( V_44 ) ;
}
void F_230 ( struct V_8 * V_9 , int V_84 )
{
unsigned int V_1 ;
V_84 = F_219 ( V_84 , V_9 -> V_10 , V_9 -> V_176 ) ;
F_93 ( & V_172 ) ;
V_9 -> V_178 = V_84 ;
F_177 (cpu, wq) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
struct V_23 * V_26 = V_44 -> V_26 ;
F_136 ( & V_26 -> V_95 ) ;
if ( ! ( V_9 -> V_10 & V_204 ) ||
! ( V_26 -> V_10 & V_206 ) )
F_229 ( V_44 , V_84 ) ;
F_124 ( & V_26 -> V_95 ) ;
}
F_95 ( & V_172 ) ;
}
bool F_231 ( unsigned int V_1 , struct V_8 * V_9 )
{
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
return ! F_57 ( & V_44 -> V_81 ) ;
}
unsigned int F_232 ( struct V_13 * V_17 )
{
struct V_23 * V_26 = F_50 ( V_17 ) ;
unsigned long V_10 ;
unsigned int V_27 = 0 ;
if ( F_40 ( V_17 ) )
V_27 |= V_207 ;
if ( V_26 ) {
F_233 ( & V_26 -> V_95 , V_10 ) ;
if ( F_77 ( V_26 , V_17 ) )
V_27 |= V_208 ;
F_234 ( & V_26 -> V_95 , V_10 ) ;
}
return V_27 ;
}
static void F_235 ( struct V_13 * V_17 )
{
int V_1 = F_236 () ;
struct V_23 * V_26 ;
struct V_63 * V_63 ;
int V_121 ;
F_237 (pool, cpu) {
F_39 ( V_1 != F_236 () ) ;
F_26 ( & V_26 -> V_122 ) ;
F_136 ( & V_26 -> V_95 ) ;
F_156 (worker, &pool->idle_list, entry)
V_63 -> V_10 |= V_119 ;
F_130 (worker, i, pool)
V_63 -> V_10 |= V_119 ;
V_26 -> V_10 |= V_118 ;
F_124 ( & V_26 -> V_95 ) ;
F_28 ( & V_26 -> V_122 ) ;
F_164 () ;
F_176 ( & V_26 -> V_53 , 0 ) ;
F_136 ( & V_26 -> V_95 ) ;
F_66 ( V_26 ) ;
F_124 ( & V_26 -> V_95 ) ;
}
}
static int T_5 F_238 ( struct V_209 * V_210 ,
unsigned long V_211 ,
void * V_212 )
{
unsigned int V_1 = ( unsigned long ) V_212 ;
struct V_23 * V_26 ;
switch ( V_211 & ~ V_213 ) {
case V_214 :
F_237 (pool, cpu) {
struct V_63 * V_63 ;
if ( V_26 -> V_60 )
continue;
V_63 = F_135 ( V_26 ) ;
if ( ! V_63 )
return V_215 ;
F_136 ( & V_26 -> V_95 ) ;
F_147 ( V_63 ) ;
F_124 ( & V_26 -> V_95 ) ;
}
break;
case V_216 :
case V_217 :
F_237 (pool, cpu) {
F_26 ( & V_26 -> V_122 ) ;
F_136 ( & V_26 -> V_95 ) ;
V_26 -> V_10 &= ~ V_118 ;
F_127 ( V_26 ) ;
F_124 ( & V_26 -> V_95 ) ;
F_28 ( & V_26 -> V_122 ) ;
}
break;
}
return V_218 ;
}
static int T_5 F_239 ( struct V_209 * V_210 ,
unsigned long V_211 ,
void * V_212 )
{
unsigned int V_1 = ( unsigned long ) V_212 ;
struct V_13 V_219 ;
switch ( V_211 & ~ V_213 ) {
case V_220 :
F_172 ( & V_219 , F_235 ) ;
F_106 ( V_1 , V_123 , & V_219 ) ;
F_190 ( & V_219 ) ;
break;
}
return V_218 ;
}
static void F_240 ( struct V_13 * V_17 )
{
struct V_221 * V_222 = F_126 ( V_17 , struct V_221 , V_17 ) ;
V_222 -> V_27 = V_222 -> V_181 ( V_222 -> V_223 ) ;
}
long F_241 ( unsigned int V_1 , long (* V_181)( void * ) , void * V_223 )
{
struct V_221 V_222 = { . V_181 = V_181 , . V_223 = V_223 } ;
F_172 ( & V_222 . V_17 , F_240 ) ;
F_198 ( V_1 , & V_222 . V_17 ) ;
F_190 ( & V_222 . V_17 ) ;
return V_222 . V_27 ;
}
void F_242 ( void )
{
unsigned int V_1 ;
F_93 ( & V_172 ) ;
F_39 ( V_203 ) ;
V_203 = true ;
F_243 (cpu) {
struct V_23 * V_26 ;
struct V_8 * V_9 ;
F_237 (pool, cpu) {
F_136 ( & V_26 -> V_95 ) ;
F_12 ( V_26 -> V_10 & V_206 ) ;
V_26 -> V_10 |= V_206 ;
F_156 (wq, &workqueues, list) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
if ( V_44 && V_44 -> V_26 == V_26 &&
( V_9 -> V_10 & V_204 ) )
V_44 -> V_84 = 0 ;
}
F_124 ( & V_26 -> V_95 ) ;
}
}
F_95 ( & V_172 ) ;
}
bool F_244 ( void )
{
unsigned int V_1 ;
bool V_224 = false ;
F_93 ( & V_172 ) ;
F_39 ( ! V_203 ) ;
F_243 (cpu) {
struct V_8 * V_9 ;
F_156 (wq, &workqueues, list) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
if ( ! V_44 || ! ( V_9 -> V_10 & V_204 ) )
continue;
F_39 ( V_44 -> V_80 < 0 ) ;
if ( V_44 -> V_80 ) {
V_224 = true ;
goto V_168;
}
}
}
V_168:
F_95 ( & V_172 ) ;
return V_224 ;
}
void F_245 ( void )
{
unsigned int V_1 ;
F_93 ( & V_172 ) ;
if ( ! V_203 )
goto V_168;
F_243 (cpu) {
struct V_23 * V_26 ;
struct V_8 * V_9 ;
F_237 (pool, cpu) {
F_136 ( & V_26 -> V_95 ) ;
F_12 ( ! ( V_26 -> V_10 & V_206 ) ) ;
V_26 -> V_10 &= ~ V_206 ;
F_156 (wq, &workqueues, list) {
struct V_35 * V_44 = F_32 ( V_1 , V_9 ) ;
if ( ! V_44 || V_44 -> V_26 != V_26 ||
! ( V_9 -> V_10 & V_204 ) )
continue;
F_229 ( V_44 , V_9 -> V_178 ) ;
}
F_66 ( V_26 ) ;
F_124 ( & V_26 -> V_95 ) ;
}
}
V_203 = false ;
V_168:
F_95 ( & V_172 ) ;
}
static int T_6 F_246 ( void )
{
unsigned int V_1 ;
F_247 ( ( 1LU << ( V_225 - V_48 ) ) <
V_7 * V_226 ) ;
F_248 ( F_238 , V_227 ) ;
F_249 ( F_239 , V_228 ) ;
F_243 (cpu) {
struct V_23 * V_26 ;
F_237 (pool, cpu) {
F_250 ( & V_26 -> V_95 ) ;
V_26 -> V_1 = V_1 ;
V_26 -> V_10 |= V_118 ;
F_133 ( & V_26 -> V_54 ) ;
F_133 ( & V_26 -> V_61 ) ;
F_251 ( V_26 -> V_229 ) ;
F_252 ( & V_26 -> V_116 ) ;
V_26 -> V_116 . V_108 = F_150 ;
V_26 -> V_116 . V_43 = ( unsigned long ) V_26 ;
F_253 ( & V_26 -> V_139 , F_155 ,
( unsigned long ) V_26 ) ;
F_223 ( & V_26 -> V_122 ) ;
F_254 ( & V_26 -> V_128 ) ;
F_39 ( F_25 ( V_26 ) ) ;
}
}
F_255 (cpu) {
struct V_23 * V_26 ;
F_237 (pool, cpu) {
struct V_63 * V_63 ;
if ( V_1 != V_6 )
V_26 -> V_10 &= ~ V_118 ;
V_63 = F_135 ( V_26 ) ;
F_39 ( ! V_63 ) ;
F_136 ( & V_26 -> V_95 ) ;
F_147 ( V_63 ) ;
F_124 ( & V_26 -> V_95 ) ;
}
}
V_124 = F_256 ( L_8 , 0 , 0 ) ;
V_123 = F_256 ( L_9 , V_202 , 0 ) ;
V_230 = F_256 ( L_10 , 0 , 0 ) ;
V_231 = F_256 ( L_11 , V_11 ,
V_190 ) ;
V_232 = F_256 ( L_12 ,
V_204 , 0 ) ;
F_39 ( ! V_124 || ! V_123 || ! V_230 ||
! V_231 || ! V_232 ) ;
return 0 ;
}
