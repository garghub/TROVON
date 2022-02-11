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
static struct V_23 * F_22 ( unsigned int V_1 )
{
if ( V_1 != V_6 )
return & F_23 ( V_23 , V_1 ) ;
else
return & V_24 ;
}
static T_1 * F_24 ( unsigned int V_1 )
{
if ( V_1 != V_6 )
return & F_23 ( V_25 , V_1 ) ;
else
return & V_26 ;
}
static struct V_27 * F_25 ( unsigned int V_1 ,
struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_10 & V_11 ) ) {
if ( F_26 ( V_1 < V_5 ) ) {
#ifdef F_27
return F_28 ( V_9 -> V_28 . V_29 , V_1 ) ;
#else
return V_9 -> V_28 . V_30 ;
#endif
}
} else if ( F_26 ( V_1 == V_6 ) )
return V_9 -> V_28 . V_30 ;
return NULL ;
}
static unsigned int F_29 ( int V_31 )
{
return V_31 << V_32 ;
}
static int F_30 ( struct V_13 * V_17 )
{
return ( * F_10 ( V_17 ) >> V_32 ) &
( ( 1 << V_33 ) - 1 ) ;
}
static int F_31 ( int V_31 )
{
return ( V_31 + 1 ) % V_34 ;
}
static inline void F_32 ( struct V_13 * V_17 , unsigned long V_35 ,
unsigned long V_10 )
{
F_33 ( ! F_34 ( V_17 ) ) ;
F_35 ( & V_17 -> V_35 , V_35 | V_10 | F_36 ( V_17 ) ) ;
}
static void F_37 ( struct V_13 * V_17 ,
struct V_27 * V_36 ,
unsigned long V_37 )
{
F_32 ( V_17 , ( unsigned long ) V_36 ,
V_38 | V_39 | V_37 ) ;
}
static void F_38 ( struct V_13 * V_17 , unsigned int V_1 )
{
F_32 ( V_17 , V_1 << V_40 , V_38 ) ;
}
static void F_39 ( struct V_13 * V_17 )
{
F_32 ( V_17 , V_41 , 0 ) ;
}
static struct V_27 * F_40 ( struct V_13 * V_17 )
{
unsigned long V_35 = F_41 ( & V_17 -> V_35 ) ;
if ( V_35 & V_39 )
return ( void * ) ( V_35 & V_42 ) ;
else
return NULL ;
}
static struct V_23 * F_42 ( struct V_13 * V_17 )
{
unsigned long V_35 = F_41 ( & V_17 -> V_35 ) ;
unsigned int V_1 ;
if ( V_35 & V_39 )
return ( (struct V_27 * )
( V_35 & V_42 ) ) -> V_43 ;
V_1 = V_35 >> V_40 ;
if ( V_1 == V_7 )
return NULL ;
F_33 ( V_1 >= V_5 && V_1 != V_6 ) ;
return F_22 ( V_1 ) ;
}
static bool F_43 ( struct V_23 * V_43 )
{
return ! F_44 ( F_24 ( V_43 -> V_1 ) ) ||
V_43 -> V_10 & V_44 ;
}
static bool F_45 ( struct V_23 * V_43 )
{
return ! F_46 ( & V_43 -> V_45 ) && F_43 ( V_43 ) ;
}
static bool F_47 ( struct V_23 * V_43 )
{
return V_43 -> V_46 ;
}
static bool F_48 ( struct V_23 * V_43 )
{
T_1 * V_47 = F_24 ( V_43 -> V_1 ) ;
return ! F_46 ( & V_43 -> V_45 ) &&
( F_44 ( V_47 ) <= 1 ||
V_43 -> V_10 & V_44 ) ;
}
static bool F_49 ( struct V_23 * V_43 )
{
return F_45 ( V_43 ) && ! F_47 ( V_43 ) ;
}
static bool F_50 ( struct V_23 * V_43 )
{
return F_49 ( V_43 ) || V_43 -> V_10 & V_48 ;
}
static bool F_51 ( struct V_23 * V_43 )
{
bool V_49 = V_43 -> V_10 & V_50 ;
int V_46 = V_43 -> V_46 + V_49 ;
int V_51 = V_43 -> V_52 - V_46 ;
return V_46 > 2 && ( V_46 - 2 ) * V_53 >= V_51 ;
}
static struct V_54 * F_52 ( struct V_23 * V_43 )
{
if ( F_53 ( F_46 ( & V_43 -> V_55 ) ) )
return NULL ;
return F_54 ( & V_43 -> V_55 , struct V_54 , V_56 ) ;
}
static void F_55 ( struct V_23 * V_43 )
{
struct V_54 * V_54 = F_52 ( V_43 ) ;
if ( F_26 ( V_54 ) )
F_56 ( V_54 -> V_57 ) ;
}
void F_57 ( struct V_58 * V_57 , unsigned int V_1 )
{
struct V_54 * V_54 = F_58 ( V_57 ) ;
if ( ! ( V_54 -> V_10 & V_59 ) )
F_59 ( F_24 ( V_1 ) ) ;
}
struct V_58 * F_60 ( struct V_58 * V_57 ,
unsigned int V_1 )
{
struct V_54 * V_54 = F_58 ( V_57 ) , * V_60 = NULL ;
struct V_23 * V_43 = F_22 ( V_1 ) ;
T_1 * V_47 = F_24 ( V_1 ) ;
if ( V_54 -> V_10 & V_59 )
return NULL ;
F_33 ( V_1 != F_61 () ) ;
if ( F_62 ( V_47 ) && ! F_46 ( & V_43 -> V_45 ) )
V_60 = F_52 ( V_43 ) ;
return V_60 ? V_60 -> V_57 : NULL ;
}
static inline void F_63 ( struct V_54 * V_54 , unsigned int V_10 ,
bool V_61 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
F_12 ( V_54 -> V_57 != V_62 ) ;
if ( ( V_10 & V_59 ) &&
! ( V_54 -> V_10 & V_59 ) ) {
T_1 * V_47 = F_24 ( V_43 -> V_1 ) ;
if ( V_61 ) {
if ( F_62 ( V_47 ) &&
! F_46 ( & V_43 -> V_45 ) )
F_55 ( V_43 ) ;
} else
F_64 ( V_47 ) ;
}
V_54 -> V_10 |= V_10 ;
}
static inline void F_65 ( struct V_54 * V_54 , unsigned int V_10 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
unsigned int V_63 = V_54 -> V_10 ;
F_12 ( V_54 -> V_57 != V_62 ) ;
V_54 -> V_10 &= ~ V_10 ;
if ( ( V_10 & V_59 ) && ( V_63 & V_59 ) )
if ( ! ( V_54 -> V_10 & V_59 ) )
F_59 ( F_24 ( V_43 -> V_1 ) ) ;
}
static struct V_64 * F_66 ( struct V_23 * V_43 ,
struct V_13 * V_17 )
{
const int V_65 = F_67 ( sizeof( struct V_13 ) ) ;
unsigned long V_66 = ( unsigned long ) V_17 ;
V_66 >>= V_65 ;
V_66 += V_66 >> V_67 ;
V_66 &= V_68 ;
return & V_43 -> V_69 [ V_66 ] ;
}
static struct V_54 * F_68 ( struct V_23 * V_43 ,
struct V_64 * V_70 ,
struct V_13 * V_17 )
{
struct V_54 * V_54 ;
struct V_71 * V_72 ;
F_69 (worker, tmp, bwh, hentry)
if ( V_54 -> V_73 == V_17 )
return V_54 ;
return NULL ;
}
static struct V_54 * F_70 ( struct V_23 * V_43 ,
struct V_13 * V_17 )
{
return F_68 ( V_43 , F_66 ( V_43 , V_17 ) ,
V_17 ) ;
}
static inline struct V_74 * F_71 ( struct V_23 * V_43 ,
struct V_27 * V_36 )
{
struct V_13 * V_75 ;
if ( F_26 ( ! ( V_36 -> V_9 -> V_10 & V_76 ) ) )
return & V_43 -> V_45 ;
F_72 (twork, &gcwq->worklist, entry) {
struct V_27 * V_77 = F_40 ( V_75 ) ;
if ( ! ( V_77 -> V_9 -> V_10 & V_76 ) )
break;
}
V_43 -> V_10 |= V_44 ;
return & V_75 -> V_56 ;
}
static void F_73 ( struct V_27 * V_36 ,
struct V_13 * V_17 , struct V_74 * V_78 ,
unsigned int V_37 )
{
struct V_23 * V_43 = V_36 -> V_43 ;
F_37 ( V_17 , V_36 , V_37 ) ;
F_74 () ;
F_75 ( & V_17 -> V_56 , V_78 ) ;
F_76 () ;
if ( F_43 ( V_43 ) )
F_55 ( V_43 ) ;
}
static bool F_77 ( struct V_8 * V_9 )
{
unsigned long V_10 ;
unsigned int V_1 ;
F_78 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_54 * V_54 ;
struct V_71 * V_79 ;
int V_80 ;
F_79 ( & V_43 -> V_81 , V_10 ) ;
F_80 (worker, i, pos, gcwq) {
if ( V_54 -> V_57 != V_62 )
continue;
F_81 ( & V_43 -> V_81 , V_10 ) ;
return V_54 -> V_82 -> V_9 == V_9 ;
}
F_81 ( & V_43 -> V_81 , V_10 ) ;
}
return false ;
}
static void F_82 ( unsigned int V_1 , struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_23 * V_43 ;
struct V_27 * V_36 ;
struct V_74 * V_45 ;
unsigned int V_83 ;
unsigned long V_10 ;
F_16 ( V_17 ) ;
if ( F_53 ( V_9 -> V_10 & V_84 ) &&
F_12 ( ! F_77 ( V_9 ) ) )
return;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_23 * V_85 ;
if ( F_53 ( V_1 == V_6 ) )
V_1 = F_61 () ;
V_43 = F_22 ( V_1 ) ;
if ( V_9 -> V_10 & V_86 &&
( V_85 = F_42 ( V_17 ) ) && V_85 != V_43 ) {
struct V_54 * V_54 ;
F_79 ( & V_85 -> V_81 , V_10 ) ;
V_54 = F_70 ( V_85 , V_17 ) ;
if ( V_54 && V_54 -> V_82 -> V_9 == V_9 )
V_43 = V_85 ;
else {
F_81 ( & V_85 -> V_81 , V_10 ) ;
F_79 ( & V_43 -> V_81 , V_10 ) ;
}
} else
F_79 ( & V_43 -> V_81 , V_10 ) ;
} else {
V_43 = F_22 ( V_6 ) ;
F_79 ( & V_43 -> V_81 , V_10 ) ;
}
V_36 = F_25 ( V_43 -> V_1 , V_9 ) ;
F_83 ( V_1 , V_36 , V_17 ) ;
F_33 ( ! F_46 ( & V_17 -> V_56 ) ) ;
V_36 -> V_87 [ V_36 -> V_88 ] ++ ;
V_83 = F_29 ( V_36 -> V_88 ) ;
if ( F_26 ( V_36 -> V_89 < V_36 -> V_90 ) ) {
F_84 ( V_17 ) ;
V_36 -> V_89 ++ ;
V_45 = F_71 ( V_43 , V_36 ) ;
} else {
V_83 |= V_91 ;
V_45 = & V_36 -> V_92 ;
}
F_73 ( V_36 , V_17 , V_45 , V_83 ) ;
F_81 ( & V_43 -> V_81 , V_10 ) ;
}
int F_85 ( struct V_8 * V_9 , struct V_13 * V_17 )
{
int V_93 ;
V_93 = F_86 ( F_87 () , V_9 , V_17 ) ;
F_88 () ;
return V_93 ;
}
int
F_86 ( int V_1 , struct V_8 * V_9 , struct V_13 * V_17 )
{
int V_93 = 0 ;
if ( ! F_89 ( V_94 , F_10 ( V_17 ) ) ) {
F_82 ( V_1 , V_9 , V_17 ) ;
V_93 = 1 ;
}
return V_93 ;
}
static void F_90 ( unsigned long V_95 )
{
struct V_96 * V_97 = (struct V_96 * ) V_95 ;
struct V_27 * V_36 = F_40 ( & V_97 -> V_17 ) ;
F_82 ( F_91 () , V_36 -> V_9 , & V_97 -> V_17 ) ;
}
int F_92 ( struct V_8 * V_9 ,
struct V_96 * V_97 , unsigned long V_98 )
{
if ( V_98 == 0 )
return F_85 ( V_9 , & V_97 -> V_17 ) ;
return F_93 ( - 1 , V_9 , V_97 , V_98 ) ;
}
int F_93 ( int V_1 , struct V_8 * V_9 ,
struct V_96 * V_97 , unsigned long V_98 )
{
int V_93 = 0 ;
struct V_99 * V_100 = & V_97 -> V_100 ;
struct V_13 * V_17 = & V_97 -> V_17 ;
if ( ! F_89 ( V_94 , F_10 ( V_17 ) ) ) {
unsigned int V_101 ;
F_33 ( F_94 ( V_100 ) ) ;
F_33 ( ! F_46 ( & V_17 -> V_56 ) ) ;
F_95 ( & V_97 -> V_100 ) ;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_23 * V_43 = F_42 ( V_17 ) ;
if ( V_43 && V_43 -> V_1 != V_6 )
V_101 = V_43 -> V_1 ;
else
V_101 = F_61 () ;
} else
V_101 = V_6 ;
F_37 ( V_17 , F_25 ( V_101 , V_9 ) , 0 ) ;
V_100 -> V_102 = V_103 + V_98 ;
V_100 -> V_35 = ( unsigned long ) V_97 ;
V_100 -> V_104 = F_90 ;
if ( F_53 ( V_1 >= 0 ) )
F_96 ( V_100 , V_1 ) ;
else
F_97 ( V_100 ) ;
V_93 = 1 ;
}
return V_93 ;
}
static void F_98 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
F_33 ( V_54 -> V_10 & V_105 ) ;
F_33 ( ! F_46 ( & V_54 -> V_56 ) &&
( V_54 -> V_106 . V_107 || V_54 -> V_106 . V_108 ) ) ;
V_54 -> V_10 |= V_105 ;
V_43 -> V_46 ++ ;
V_54 -> V_109 = V_103 ;
F_99 ( & V_54 -> V_56 , & V_43 -> V_55 ) ;
if ( F_26 ( ! ( V_54 -> V_10 & V_110 ) ) ) {
if ( F_51 ( V_43 ) && ! F_94 ( & V_43 -> V_111 ) )
F_100 ( & V_43 -> V_111 ,
V_103 + V_112 ) ;
} else
F_101 ( & V_43 -> V_113 ) ;
F_12 ( V_43 -> V_52 == V_43 -> V_46 &&
F_44 ( F_24 ( V_43 -> V_1 ) ) ) ;
}
static void F_102 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
F_33 ( ! ( V_54 -> V_10 & V_105 ) ) ;
F_65 ( V_54 , V_105 ) ;
V_43 -> V_46 -- ;
F_103 ( & V_54 -> V_56 ) ;
}
static bool F_104 ( struct V_54 * V_54 )
__acquires( &gcwq->lock
static void F_105 ( struct V_13 * V_17 )
{
struct V_54 * V_54 = F_106 ( V_17 , struct V_54 , V_114 ) ;
struct V_23 * V_43 = V_54 -> V_43 ;
if ( F_104 ( V_54 ) )
F_65 ( V_54 , V_115 ) ;
F_107 ( & V_43 -> V_81 ) ;
}
static struct V_54 * F_108 ( void )
{
struct V_54 * V_54 ;
V_54 = F_109 ( sizeof( * V_54 ) , V_116 ) ;
if ( V_54 ) {
F_110 ( & V_54 -> V_56 ) ;
F_110 ( & V_54 -> V_117 ) ;
F_111 ( & V_54 -> V_114 , F_105 ) ;
V_54 -> V_10 = V_118 ;
}
return V_54 ;
}
static struct V_54 * F_112 ( struct V_23 * V_43 , bool V_119 )
{
bool V_120 = V_43 -> V_1 == V_6 ;
struct V_54 * V_54 = NULL ;
int V_121 = - 1 ;
F_113 ( & V_43 -> V_81 ) ;
while ( F_114 ( & V_43 -> V_122 , & V_121 ) ) {
F_107 ( & V_43 -> V_81 ) ;
if ( ! F_115 ( & V_43 -> V_122 , V_116 ) )
goto V_123;
F_113 ( & V_43 -> V_81 ) ;
}
F_107 ( & V_43 -> V_81 ) ;
V_54 = F_108 () ;
if ( ! V_54 )
goto V_123;
V_54 -> V_43 = V_43 ;
V_54 -> V_121 = V_121 ;
if ( ! V_120 )
V_54 -> V_57 = F_116 ( V_124 ,
V_54 ,
F_117 ( V_43 -> V_1 ) ,
L_1 , V_43 -> V_1 , V_121 ) ;
else
V_54 -> V_57 = F_118 ( V_124 , V_54 ,
L_2 , V_121 ) ;
if ( F_119 ( V_54 -> V_57 ) )
goto V_123;
if ( V_119 && ! V_120 )
F_120 ( V_54 -> V_57 , V_43 -> V_1 ) ;
else {
V_54 -> V_57 -> V_10 |= V_125 ;
if ( V_120 )
V_54 -> V_10 |= V_126 ;
}
return V_54 ;
V_123:
if ( V_121 >= 0 ) {
F_113 ( & V_43 -> V_81 ) ;
F_121 ( & V_43 -> V_122 , V_121 ) ;
F_107 ( & V_43 -> V_81 ) ;
}
F_122 ( V_54 ) ;
return NULL ;
}
static void F_123 ( struct V_54 * V_54 )
{
V_54 -> V_10 |= V_127 ;
V_54 -> V_43 -> V_52 ++ ;
F_98 ( V_54 ) ;
F_56 ( V_54 -> V_57 ) ;
}
static void F_124 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
int V_121 = V_54 -> V_121 ;
F_33 ( V_54 -> V_73 ) ;
F_33 ( ! F_46 ( & V_54 -> V_117 ) ) ;
if ( V_54 -> V_10 & V_127 )
V_43 -> V_52 -- ;
if ( V_54 -> V_10 & V_105 )
V_43 -> V_46 -- ;
F_103 ( & V_54 -> V_56 ) ;
V_54 -> V_10 |= V_128 ;
F_107 ( & V_43 -> V_81 ) ;
F_125 ( V_54 -> V_57 ) ;
F_122 ( V_54 ) ;
F_113 ( & V_43 -> V_81 ) ;
F_121 ( & V_43 -> V_122 , V_121 ) ;
}
static void F_126 ( unsigned long V_129 )
{
struct V_23 * V_43 = ( void * ) V_129 ;
F_113 ( & V_43 -> V_81 ) ;
if ( F_51 ( V_43 ) ) {
struct V_54 * V_54 ;
unsigned long V_102 ;
V_54 = F_127 ( V_43 -> V_55 . V_130 , struct V_54 , V_56 ) ;
V_102 = V_54 -> V_109 + V_112 ;
if ( F_128 ( V_103 , V_102 ) )
F_100 ( & V_43 -> V_111 , V_102 ) ;
else {
V_43 -> V_10 |= V_48 ;
F_55 ( V_43 ) ;
}
}
F_107 ( & V_43 -> V_81 ) ;
}
static bool F_129 ( struct V_13 * V_17 )
{
struct V_27 * V_36 = F_40 ( V_17 ) ;
struct V_8 * V_9 = V_36 -> V_9 ;
unsigned int V_1 ;
if ( ! ( V_9 -> V_10 & V_131 ) )
return false ;
V_1 = V_36 -> V_43 -> V_1 ;
if ( V_1 == V_6 )
V_1 = 0 ;
if ( ! F_130 ( V_1 , V_9 -> V_132 ) )
F_56 ( V_9 -> V_133 -> V_57 ) ;
return true ;
}
static void F_131 ( unsigned long V_129 )
{
struct V_23 * V_43 = ( void * ) V_129 ;
struct V_13 * V_17 ;
F_113 ( & V_43 -> V_81 ) ;
if ( F_49 ( V_43 ) ) {
F_72 (work, &gcwq->worklist, entry)
F_129 ( V_17 ) ;
}
F_107 ( & V_43 -> V_81 ) ;
F_100 ( & V_43 -> V_134 , V_103 + V_135 ) ;
}
static bool F_132 ( struct V_23 * V_43 )
__releases( &gcwq->lock
static bool F_133 ( struct V_23 * V_43 )
{
bool V_93 = false ;
while ( F_51 ( V_43 ) ) {
struct V_54 * V_54 ;
unsigned long V_102 ;
V_54 = F_127 ( V_43 -> V_55 . V_130 , struct V_54 , V_56 ) ;
V_102 = V_54 -> V_109 + V_112 ;
if ( F_128 ( V_103 , V_102 ) ) {
F_100 ( & V_43 -> V_111 , V_102 ) ;
break;
}
F_124 ( V_54 ) ;
V_93 = true ;
}
return V_93 ;
}
static bool F_134 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
bool V_93 = false ;
if ( V_43 -> V_10 & V_50 )
return V_93 ;
V_43 -> V_10 &= ~ V_48 ;
V_43 -> V_10 |= V_50 ;
V_93 |= F_133 ( V_43 ) ;
V_93 |= F_132 ( V_43 ) ;
V_43 -> V_10 &= ~ V_50 ;
if ( F_53 ( V_43 -> V_136 ) )
F_101 ( & V_43 -> V_113 ) ;
return V_93 ;
}
static void F_135 ( struct V_13 * V_17 , struct V_74 * V_78 ,
struct V_13 * * V_137 )
{
struct V_13 * V_138 ;
F_136 (work, n, NULL, entry) {
F_137 ( & V_17 -> V_56 , V_78 ) ;
if ( ! ( * F_10 ( V_17 ) & V_139 ) )
break;
}
if ( V_137 )
* V_137 = V_138 ;
}
static void F_138 ( struct V_27 * V_36 )
{
struct V_13 * V_17 = F_54 ( & V_36 -> V_92 ,
struct V_13 , V_56 ) ;
struct V_74 * V_79 = F_71 ( V_36 -> V_43 , V_36 ) ;
F_84 ( V_17 ) ;
F_135 ( V_17 , V_79 , NULL ) ;
F_139 ( V_140 , F_10 ( V_17 ) ) ;
V_36 -> V_89 ++ ;
}
static void F_140 ( struct V_27 * V_36 , int V_31 ,
bool V_141 )
{
if ( V_31 == V_142 )
return;
V_36 -> V_87 [ V_31 ] -- ;
if ( ! V_141 ) {
V_36 -> V_89 -- ;
if ( ! F_46 ( & V_36 -> V_92 ) ) {
if ( V_36 -> V_89 < V_36 -> V_90 )
F_138 ( V_36 ) ;
}
}
if ( F_26 ( V_36 -> V_143 != V_31 ) )
return;
if ( V_36 -> V_87 [ V_31 ] )
return;
V_36 -> V_143 = - 1 ;
if ( F_62 ( & V_36 -> V_9 -> V_144 ) )
F_141 ( & V_36 -> V_9 -> V_145 -> V_146 ) ;
}
static void F_142 ( struct V_54 * V_54 , struct V_13 * V_17 )
__releases( &gcwq->lock
static void F_143 ( struct V_54 * V_54 )
{
while ( ! F_46 ( & V_54 -> V_117 ) ) {
struct V_13 * V_17 = F_54 ( & V_54 -> V_117 ,
struct V_13 , V_56 ) ;
F_142 ( V_54 , V_17 ) ;
}
}
static int V_124 ( void * V_147 )
{
struct V_54 * V_54 = V_147 ;
struct V_23 * V_43 = V_54 -> V_43 ;
V_54 -> V_57 -> V_10 |= V_148 ;
V_149:
F_113 ( & V_43 -> V_81 ) ;
if ( V_54 -> V_10 & V_128 ) {
F_107 ( & V_43 -> V_81 ) ;
V_54 -> V_57 -> V_10 &= ~ V_148 ;
return 0 ;
}
F_102 ( V_54 ) ;
V_150:
if ( ! F_45 ( V_43 ) )
goto V_151;
if ( F_53 ( ! F_47 ( V_43 ) ) && F_134 ( V_54 ) )
goto V_150;
F_33 ( ! F_46 ( & V_54 -> V_117 ) ) ;
F_65 ( V_54 , V_118 ) ;
do {
struct V_13 * V_17 =
F_54 ( & V_43 -> V_45 ,
struct V_13 , V_56 ) ;
if ( F_26 ( ! ( * F_10 ( V_17 ) & V_139 ) ) ) {
F_142 ( V_54 , V_17 ) ;
if ( F_53 ( ! F_46 ( & V_54 -> V_117 ) ) )
F_143 ( V_54 ) ;
} else {
F_135 ( V_17 , & V_54 -> V_117 , NULL ) ;
F_143 ( V_54 ) ;
}
} while ( F_48 ( V_43 ) );
F_63 ( V_54 , V_118 , false ) ;
V_151:
if ( F_53 ( F_50 ( V_43 ) ) && F_134 ( V_54 ) )
goto V_150;
F_98 ( V_54 ) ;
F_144 ( V_152 ) ;
F_107 ( & V_43 -> V_81 ) ;
F_145 () ;
goto V_149;
}
static int F_146 ( void * V_153 )
{
struct V_8 * V_9 = V_153 ;
struct V_54 * V_133 = V_9 -> V_133 ;
struct V_74 * V_117 = & V_133 -> V_117 ;
bool V_154 = V_9 -> V_10 & V_11 ;
unsigned int V_1 ;
F_147 ( V_62 , V_155 ) ;
V_156:
F_148 ( V_152 ) ;
if ( F_149 () )
return 0 ;
F_150 (cpu, wq->mayday_mask) {
unsigned int V_157 = V_154 ? V_6 : V_1 ;
struct V_27 * V_36 = F_25 ( V_157 , V_9 ) ;
struct V_23 * V_43 = V_36 -> V_43 ;
struct V_13 * V_17 , * V_138 ;
F_144 ( V_158 ) ;
F_151 ( V_1 , V_9 -> V_132 ) ;
V_133 -> V_43 = V_43 ;
F_104 ( V_133 ) ;
F_33 ( ! F_46 ( & V_133 -> V_117 ) ) ;
F_152 (work, n, &gcwq->worklist, entry)
if ( F_40 ( V_17 ) == V_36 )
F_135 ( V_17 , V_117 , & V_138 ) ;
F_143 ( V_133 ) ;
if ( F_48 ( V_43 ) )
F_55 ( V_43 ) ;
F_107 ( & V_43 -> V_81 ) ;
}
F_145 () ;
goto V_156;
}
static void F_153 ( struct V_13 * V_17 )
{
struct V_159 * V_160 = F_106 ( V_17 , struct V_159 , V_17 ) ;
F_141 ( & V_160 -> V_146 ) ;
}
static void F_154 ( struct V_27 * V_36 ,
struct V_159 * V_160 ,
struct V_13 * V_161 , struct V_54 * V_54 )
{
struct V_74 * V_78 ;
unsigned int V_162 = 0 ;
F_155 ( & V_160 -> V_17 , F_153 ) ;
F_156 ( V_94 , F_10 ( & V_160 -> V_17 ) ) ;
F_157 ( & V_160 -> V_146 ) ;
if ( V_54 )
V_78 = V_54 -> V_117 . V_107 ;
else {
unsigned long * V_163 = F_10 ( V_161 ) ;
V_78 = V_161 -> V_56 . V_107 ;
V_162 = * V_163 & V_139 ;
F_156 ( V_164 , V_163 ) ;
}
F_16 ( & V_160 -> V_17 ) ;
F_73 ( V_36 , & V_160 -> V_17 , V_78 ,
F_29 ( V_142 ) | V_162 ) ;
}
static bool F_158 ( struct V_8 * V_9 ,
int V_143 , int V_88 )
{
bool V_165 = false ;
unsigned int V_1 ;
if ( V_143 >= 0 ) {
F_33 ( F_44 ( & V_9 -> V_144 ) ) ;
F_159 ( & V_9 -> V_144 , 1 ) ;
}
F_160 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
struct V_23 * V_43 = V_36 -> V_43 ;
F_113 ( & V_43 -> V_81 ) ;
if ( V_143 >= 0 ) {
F_33 ( V_36 -> V_143 != - 1 ) ;
if ( V_36 -> V_87 [ V_143 ] ) {
V_36 -> V_143 = V_143 ;
F_59 ( & V_9 -> V_144 ) ;
V_165 = true ;
}
}
if ( V_88 >= 0 ) {
F_33 ( V_88 != F_31 ( V_36 -> V_88 ) ) ;
V_36 -> V_88 = V_88 ;
}
F_107 ( & V_43 -> V_81 ) ;
}
if ( V_143 >= 0 && F_62 ( & V_9 -> V_144 ) )
F_141 ( & V_9 -> V_145 -> V_146 ) ;
return V_165 ;
}
void F_161 ( struct V_8 * V_9 )
{
struct V_166 V_167 = {
. V_168 = F_162 ( V_167 . V_168 ) ,
. V_143 = - 1 ,
. V_146 = F_163 ( V_167 . V_146 ) ,
} ;
int V_169 ;
F_164 ( & V_9 -> V_170 ) ;
F_165 ( & V_9 -> V_170 ) ;
F_166 ( & V_9 -> V_171 ) ;
V_169 = F_31 ( V_9 -> V_88 ) ;
if ( V_169 != V_9 -> V_143 ) {
F_33 ( ! F_46 ( & V_9 -> V_172 ) ) ;
V_167 . V_143 = V_9 -> V_88 ;
V_9 -> V_88 = V_169 ;
if ( ! V_9 -> V_145 ) {
F_33 ( V_9 -> V_143 != V_167 . V_143 ) ;
V_9 -> V_145 = & V_167 ;
if ( ! F_158 ( V_9 , V_9 -> V_143 ,
V_9 -> V_88 ) ) {
V_9 -> V_143 = V_169 ;
V_9 -> V_145 = NULL ;
goto V_173;
}
} else {
F_33 ( V_9 -> V_143 == V_167 . V_143 ) ;
F_75 ( & V_167 . V_168 , & V_9 -> V_174 ) ;
F_158 ( V_9 , - 1 , V_9 -> V_88 ) ;
}
} else {
F_75 ( & V_167 . V_168 , & V_9 -> V_172 ) ;
}
F_167 ( & V_9 -> V_171 ) ;
F_168 ( & V_167 . V_146 ) ;
if ( V_9 -> V_145 != & V_167 )
return;
F_166 ( & V_9 -> V_171 ) ;
if ( V_9 -> V_145 != & V_167 )
goto V_173;
V_9 -> V_145 = NULL ;
F_33 ( ! F_46 ( & V_167 . V_168 ) ) ;
F_33 ( V_9 -> V_143 != V_167 . V_143 ) ;
while ( true ) {
struct V_166 * V_107 , * V_72 ;
F_152 (next, tmp, &wq->flusher_queue, list) {
if ( V_107 -> V_143 != V_9 -> V_143 )
break;
F_103 ( & V_107 -> V_168 ) ;
F_141 ( & V_107 -> V_146 ) ;
}
F_33 ( ! F_46 ( & V_9 -> V_172 ) &&
V_9 -> V_143 != F_31 ( V_9 -> V_88 ) ) ;
V_9 -> V_143 = F_31 ( V_9 -> V_143 ) ;
if ( ! F_46 ( & V_9 -> V_172 ) ) {
F_72 (tmp, &wq->flusher_overflow, list)
V_72 -> V_143 = V_9 -> V_88 ;
V_9 -> V_88 = F_31 ( V_9 -> V_88 ) ;
F_169 ( & V_9 -> V_172 ,
& V_9 -> V_174 ) ;
F_158 ( V_9 , - 1 , V_9 -> V_88 ) ;
}
if ( F_46 ( & V_9 -> V_174 ) ) {
F_33 ( V_9 -> V_143 != V_9 -> V_88 ) ;
break;
}
F_33 ( V_9 -> V_143 == V_9 -> V_88 ) ;
F_33 ( V_9 -> V_143 != V_107 -> V_143 ) ;
F_103 ( & V_107 -> V_168 ) ;
V_9 -> V_145 = V_107 ;
if ( F_158 ( V_9 , V_9 -> V_143 , - 1 ) )
break;
V_9 -> V_145 = NULL ;
}
V_173:
F_167 ( & V_9 -> V_171 ) ;
}
void F_170 ( struct V_8 * V_9 )
{
unsigned int V_175 = 0 ;
unsigned int V_1 ;
F_171 ( & V_176 ) ;
if ( ! V_9 -> V_177 ++ )
V_9 -> V_10 |= V_84 ;
F_172 ( & V_176 ) ;
V_178:
F_161 ( V_9 ) ;
F_160 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
bool V_179 ;
F_113 ( & V_36 -> V_43 -> V_81 ) ;
V_179 = ! V_36 -> V_89 && F_46 ( & V_36 -> V_92 ) ;
F_107 ( & V_36 -> V_43 -> V_81 ) ;
if ( V_179 )
continue;
if ( ++ V_175 == 10 ||
( V_175 % 100 == 0 && V_175 <= 1000 ) )
F_173 ( L_3 ,
V_9 -> V_180 , V_175 ) ;
goto V_178;
}
F_171 ( & V_176 ) ;
if ( ! -- V_9 -> V_177 )
V_9 -> V_10 &= ~ V_84 ;
F_172 ( & V_176 ) ;
}
static bool F_174 ( struct V_13 * V_17 , struct V_159 * V_160 ,
bool V_181 )
{
struct V_54 * V_54 = NULL ;
struct V_23 * V_43 ;
struct V_27 * V_36 ;
F_175 () ;
V_43 = F_42 ( V_17 ) ;
if ( ! V_43 )
return false ;
F_113 ( & V_43 -> V_81 ) ;
if ( ! F_46 ( & V_17 -> V_56 ) ) {
F_176 () ;
V_36 = F_40 ( V_17 ) ;
if ( F_53 ( ! V_36 || V_43 != V_36 -> V_43 ) )
goto V_182;
} else if ( V_181 ) {
V_54 = F_70 ( V_43 , V_17 ) ;
if ( ! V_54 )
goto V_182;
V_36 = V_54 -> V_82 ;
} else
goto V_182;
F_154 ( V_36 , V_160 , V_17 , V_54 ) ;
F_107 ( & V_43 -> V_81 ) ;
if ( V_36 -> V_9 -> V_183 == 1 || V_36 -> V_9 -> V_10 & V_131 )
F_164 ( & V_36 -> V_9 -> V_170 ) ;
else
F_177 ( & V_36 -> V_9 -> V_170 ) ;
F_165 ( & V_36 -> V_9 -> V_170 ) ;
return true ;
V_182:
F_107 ( & V_43 -> V_81 ) ;
return false ;
}
bool F_178 ( struct V_13 * V_17 )
{
struct V_159 V_160 ;
if ( F_174 ( V_17 , & V_160 , true ) ) {
F_168 ( & V_160 . V_146 ) ;
F_21 ( & V_160 . V_17 ) ;
return true ;
} else
return false ;
}
static bool F_179 ( struct V_23 * V_43 , struct V_13 * V_17 )
{
struct V_159 V_160 ;
struct V_54 * V_54 ;
F_113 ( & V_43 -> V_81 ) ;
V_54 = F_70 ( V_43 , V_17 ) ;
if ( F_53 ( V_54 ) )
F_154 ( V_54 -> V_82 , & V_160 , V_17 , V_54 ) ;
F_107 ( & V_43 -> V_81 ) ;
if ( F_53 ( V_54 ) ) {
F_168 ( & V_160 . V_146 ) ;
F_21 ( & V_160 . V_17 ) ;
return true ;
} else
return false ;
}
static bool F_180 ( struct V_13 * V_17 )
{
bool V_93 = false ;
int V_1 ;
F_175 () ;
F_164 ( & V_17 -> V_170 ) ;
F_165 ( & V_17 -> V_170 ) ;
F_78 (cpu)
V_93 |= F_179 ( F_22 ( V_1 ) , V_17 ) ;
return V_93 ;
}
bool F_181 ( struct V_13 * V_17 )
{
struct V_159 V_160 ;
bool V_184 , V_185 ;
V_184 = F_174 ( V_17 , & V_160 , false ) ;
V_185 = F_180 ( V_17 ) ;
if ( V_184 ) {
F_168 ( & V_160 . V_146 ) ;
F_21 ( & V_160 . V_17 ) ;
}
return V_184 || V_185 ;
}
static int F_182 ( struct V_13 * V_17 )
{
struct V_23 * V_43 ;
int V_93 = - 1 ;
if ( ! F_89 ( V_94 , F_10 ( V_17 ) ) )
return 0 ;
V_43 = F_42 ( V_17 ) ;
if ( ! V_43 )
return V_93 ;
F_113 ( & V_43 -> V_81 ) ;
if ( ! F_46 ( & V_17 -> V_56 ) ) {
F_176 () ;
if ( V_43 == F_42 ( V_17 ) ) {
F_17 ( V_17 ) ;
F_103 ( & V_17 -> V_56 ) ;
F_140 ( F_40 ( V_17 ) ,
F_30 ( V_17 ) ,
* F_10 ( V_17 ) & V_91 ) ;
V_93 = 1 ;
}
}
F_107 ( & V_43 -> V_81 ) ;
return V_93 ;
}
static bool F_183 ( struct V_13 * V_17 ,
struct V_99 * V_100 )
{
int V_93 ;
do {
V_93 = ( V_100 && F_26 ( F_184 ( V_100 ) ) ) ;
if ( ! V_93 )
V_93 = F_182 ( V_17 ) ;
F_180 ( V_17 ) ;
} while ( F_53 ( V_93 < 0 ) );
F_39 ( V_17 ) ;
return V_93 ;
}
bool F_6 ( struct V_13 * V_17 )
{
return F_183 ( V_17 , NULL ) ;
}
bool F_185 ( struct V_96 * V_97 )
{
if ( F_186 ( & V_97 -> V_100 ) )
F_82 ( F_61 () ,
F_40 ( & V_97 -> V_17 ) -> V_9 , & V_97 -> V_17 ) ;
return F_178 ( & V_97 -> V_17 ) ;
}
bool F_187 ( struct V_96 * V_97 )
{
if ( F_186 ( & V_97 -> V_100 ) )
F_82 ( F_61 () ,
F_40 ( & V_97 -> V_17 ) -> V_9 , & V_97 -> V_17 ) ;
return F_181 ( & V_97 -> V_17 ) ;
}
bool F_188 ( struct V_96 * V_97 )
{
return F_183 ( & V_97 -> V_17 , & V_97 -> V_100 ) ;
}
int F_189 ( struct V_13 * V_17 )
{
return F_85 ( V_186 , V_17 ) ;
}
int F_190 ( int V_1 , struct V_13 * V_17 )
{
return F_86 ( V_1 , V_186 , V_17 ) ;
}
int F_191 ( struct V_96 * V_97 ,
unsigned long V_98 )
{
return F_92 ( V_186 , V_97 , V_98 ) ;
}
int F_192 ( int V_1 ,
struct V_96 * V_97 , unsigned long V_98 )
{
return F_93 ( V_1 , V_186 , V_97 , V_98 ) ;
}
int F_193 ( T_2 V_14 )
{
int V_1 ;
struct V_13 T_3 * V_187 ;
V_187 = F_194 ( struct V_13 ) ;
if ( ! V_187 )
return - V_188 ;
F_195 () ;
F_196 (cpu) {
struct V_13 * V_17 = F_28 ( V_187 , V_1 ) ;
F_111 ( V_17 , V_14 ) ;
F_190 ( V_1 , V_17 ) ;
}
F_196 (cpu)
F_178 ( F_28 ( V_187 , V_1 ) ) ;
F_197 () ;
F_198 ( V_187 ) ;
return 0 ;
}
void F_199 ( void )
{
F_161 ( V_186 ) ;
}
int F_200 ( T_2 V_189 , struct V_190 * V_191 )
{
if ( ! F_201 () ) {
V_189 ( & V_191 -> V_17 ) ;
return 0 ;
}
F_111 ( & V_191 -> V_17 , V_189 ) ;
F_189 ( & V_191 -> V_17 ) ;
return 1 ;
}
int F_202 ( void )
{
return V_186 != NULL ;
}
static int F_203 ( struct V_8 * V_9 )
{
const T_4 V_192 = sizeof( struct V_27 ) ;
const T_4 V_193 = F_204 ( T_4 , 1 << V_40 ,
F_205 (unsigned long long) ) ;
#ifdef F_27
bool V_194 = ! ( V_9 -> V_10 & V_11 ) ;
#else
bool V_194 = false ;
#endif
if ( V_194 )
V_9 -> V_28 . V_29 = F_206 ( V_192 , V_193 ) ;
else {
void * V_195 ;
V_195 = F_109 ( V_192 + V_193 + sizeof( void * ) , V_116 ) ;
if ( V_195 ) {
V_9 -> V_28 . V_30 = F_207 ( V_195 , V_193 ) ;
* ( void * * ) ( V_9 -> V_28 . V_30 + 1 ) = V_195 ;
}
}
F_33 ( ! F_208 ( V_9 -> V_28 . V_66 , V_193 ) ) ;
return V_9 -> V_28 . V_66 ? 0 : - V_188 ;
}
static void F_209 ( struct V_8 * V_9 )
{
#ifdef F_27
bool V_194 = ! ( V_9 -> V_10 & V_11 ) ;
#else
bool V_194 = false ;
#endif
if ( V_194 )
F_198 ( V_9 -> V_28 . V_29 ) ;
else if ( V_9 -> V_28 . V_30 ) {
F_122 ( * ( void * * ) ( V_9 -> V_28 . V_30 + 1 ) ) ;
}
}
static int F_210 ( int V_90 , unsigned int V_10 ,
const char * V_180 )
{
int V_196 = V_10 & V_11 ? V_197 : V_198 ;
if ( V_90 < 1 || V_90 > V_196 )
F_211 ( V_199 L_4
L_5 ,
V_90 , V_180 , 1 , V_196 ) ;
return F_212 ( V_90 , 1 , V_196 ) ;
}
struct V_8 * F_213 ( const char * V_180 ,
unsigned int V_10 ,
int V_90 ,
struct V_200 * V_201 ,
const char * V_202 )
{
struct V_8 * V_9 ;
unsigned int V_1 ;
if ( V_10 & V_203 )
V_10 |= V_131 ;
if ( V_10 & V_11 )
V_10 |= V_76 ;
V_90 = V_90 ? : V_204 ;
V_90 = F_210 ( V_90 , V_10 , V_180 ) ;
V_9 = F_109 ( sizeof( * V_9 ) , V_116 ) ;
if ( ! V_9 )
goto V_205;
V_9 -> V_10 = V_10 ;
V_9 -> V_183 = V_90 ;
F_214 ( & V_9 -> V_171 ) ;
F_159 ( & V_9 -> V_144 , 0 ) ;
F_110 ( & V_9 -> V_174 ) ;
F_110 ( & V_9 -> V_172 ) ;
V_9 -> V_180 = V_180 ;
F_215 ( & V_9 -> V_170 , V_202 , V_201 , 0 ) ;
F_110 ( & V_9 -> V_168 ) ;
if ( F_203 ( V_9 ) < 0 )
goto V_205;
F_160 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
struct V_23 * V_43 = F_22 ( V_1 ) ;
F_33 ( ( unsigned long ) V_36 & V_206 ) ;
V_36 -> V_43 = V_43 ;
V_36 -> V_9 = V_9 ;
V_36 -> V_143 = - 1 ;
V_36 -> V_90 = V_90 ;
F_110 ( & V_36 -> V_92 ) ;
}
if ( V_10 & V_131 ) {
struct V_54 * V_133 ;
if ( ! F_216 ( & V_9 -> V_132 , V_116 ) )
goto V_205;
V_9 -> V_133 = V_133 = F_108 () ;
if ( ! V_133 )
goto V_205;
V_133 -> V_57 = F_118 ( F_146 , V_9 , L_6 , V_180 ) ;
if ( F_119 ( V_133 -> V_57 ) )
goto V_205;
V_133 -> V_57 -> V_10 |= V_125 ;
F_56 ( V_133 -> V_57 ) ;
}
F_171 ( & V_176 ) ;
if ( V_207 && V_9 -> V_10 & V_208 )
F_160 (cpu, wq)
F_25 ( V_1 , V_9 ) -> V_90 = 0 ;
F_99 ( & V_9 -> V_168 , & V_209 ) ;
F_172 ( & V_176 ) ;
return V_9 ;
V_205:
if ( V_9 ) {
F_209 ( V_9 ) ;
F_217 ( V_9 -> V_132 ) ;
F_122 ( V_9 -> V_133 ) ;
F_122 ( V_9 ) ;
}
return NULL ;
}
void F_218 ( struct V_8 * V_9 )
{
unsigned int V_1 ;
F_170 ( V_9 ) ;
F_171 ( & V_176 ) ;
F_219 ( & V_9 -> V_168 ) ;
F_172 ( & V_176 ) ;
F_160 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_34 ; V_80 ++ )
F_33 ( V_36 -> V_87 [ V_80 ] ) ;
F_33 ( V_36 -> V_89 ) ;
F_33 ( ! F_46 ( & V_36 -> V_92 ) ) ;
}
if ( V_9 -> V_10 & V_131 ) {
F_125 ( V_9 -> V_133 -> V_57 ) ;
F_217 ( V_9 -> V_132 ) ;
F_122 ( V_9 -> V_133 ) ;
}
F_209 ( V_9 ) ;
F_122 ( V_9 ) ;
}
void F_220 ( struct V_8 * V_9 , int V_90 )
{
unsigned int V_1 ;
V_90 = F_210 ( V_90 , V_9 -> V_10 , V_9 -> V_180 ) ;
F_171 ( & V_176 ) ;
V_9 -> V_183 = V_90 ;
F_160 (cpu, wq) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
F_113 ( & V_43 -> V_81 ) ;
if ( ! ( V_9 -> V_10 & V_208 ) ||
! ( V_43 -> V_10 & V_210 ) )
F_25 ( V_43 -> V_1 , V_9 ) -> V_90 = V_90 ;
F_107 ( & V_43 -> V_81 ) ;
}
F_172 ( & V_176 ) ;
}
bool F_221 ( unsigned int V_1 , struct V_8 * V_9 )
{
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
return ! F_46 ( & V_36 -> V_92 ) ;
}
unsigned int F_222 ( struct V_13 * V_17 )
{
struct V_23 * V_43 = F_42 ( V_17 ) ;
return V_43 ? V_43 -> V_1 : V_7 ;
}
unsigned int F_223 ( struct V_13 * V_17 )
{
struct V_23 * V_43 = F_42 ( V_17 ) ;
unsigned long V_10 ;
unsigned int V_93 = 0 ;
if ( ! V_43 )
return false ;
F_79 ( & V_43 -> V_81 , V_10 ) ;
if ( F_34 ( V_17 ) )
V_93 |= V_211 ;
if ( F_70 ( V_43 , V_17 ) )
V_93 |= V_212 ;
F_81 ( & V_43 -> V_81 , V_10 ) ;
return V_93 ;
}
static int T_5 F_224 ( void * V_129 )
{
struct V_23 * V_43 = V_129 ;
struct V_54 * V_54 ;
struct V_13 * V_17 ;
struct V_71 * V_79 ;
long V_213 ;
int V_80 ;
F_33 ( V_43 -> V_1 != F_91 () ) ;
F_113 ( & V_43 -> V_81 ) ;
F_33 ( V_43 -> V_1 != F_91 () ) ;
V_213 = F_225 ( ! ( V_43 -> V_10 & V_50 ) ) ;
F_33 ( V_213 < 0 ) ;
V_43 -> V_10 |= V_50 ;
F_72 (worker, &gcwq->idle_list, entry)
V_54 -> V_10 |= V_110 ;
F_80 (worker, i, pos, gcwq)
V_54 -> V_10 |= V_110 ;
F_107 ( & V_43 -> V_81 ) ;
F_145 () ;
F_113 ( & V_43 -> V_81 ) ;
F_159 ( F_24 ( V_43 -> V_1 ) , 0 ) ;
F_107 ( & V_43 -> V_81 ) ;
F_186 ( & V_43 -> V_111 ) ;
F_113 ( & V_43 -> V_81 ) ;
V_43 -> V_214 = V_215 ;
F_101 ( & V_43 -> V_113 ) ;
while ( V_43 -> V_52 != V_43 -> V_46 ||
V_43 -> V_10 & V_210 ||
V_43 -> V_214 == V_215 ) {
int V_216 = 0 ;
F_72 (work, &gcwq->worklist, entry) {
F_129 ( V_17 ) ;
V_216 ++ ;
}
F_72 (worker, &gcwq->idle_list, entry) {
if ( ! V_216 -- )
break;
F_56 ( V_54 -> V_57 ) ;
}
if ( F_49 ( V_43 ) ) {
F_107 ( & V_43 -> V_81 ) ;
V_54 = F_112 ( V_43 , false ) ;
F_113 ( & V_43 -> V_81 ) ;
if ( V_54 ) {
V_54 -> V_10 |= V_110 ;
F_123 ( V_54 ) ;
}
}
if ( F_226 ( false , V_217 ) < 0 )
break;
}
do {
V_213 = F_225 ( ! F_46 ( & V_43 -> V_55 ) ) ;
while ( ! F_46 ( & V_43 -> V_55 ) )
F_124 ( F_54 ( & V_43 -> V_55 ,
struct V_54 , V_56 ) ) ;
} while ( V_43 -> V_52 && V_213 >= 0 );
F_13 ( ! F_46 ( & V_43 -> V_55 ) ) ;
F_80 (worker, i, pos, gcwq) {
struct V_13 * V_114 = & V_54 -> V_114 ;
V_54 -> V_10 |= V_115 ;
V_54 -> V_10 &= ~ V_110 ;
if ( F_89 ( V_94 ,
F_10 ( V_114 ) ) )
continue;
F_16 ( V_114 ) ;
F_73 ( F_25 ( V_43 -> V_1 , V_186 ) , V_114 ,
V_54 -> V_117 . V_107 ,
F_29 ( V_142 ) ) ;
}
V_43 -> V_10 &= ~ V_50 ;
V_43 -> V_136 = NULL ;
V_43 -> V_214 = V_218 ;
F_101 ( & V_43 -> V_113 ) ;
F_107 ( & V_43 -> V_81 ) ;
return 0 ;
}
static void T_5 F_227 ( struct V_23 * V_43 , int V_16 )
__releases( &gcwq->lock
static int T_6 F_228 ( struct V_219 * V_220 ,
unsigned long V_221 ,
void * V_222 )
{
unsigned int V_1 = ( unsigned long ) V_222 ;
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_58 * V_223 = NULL ;
struct V_54 * V_224 ( V_225 ) ;
unsigned long V_10 ;
V_221 &= ~ V_226 ;
switch ( V_221 ) {
case V_227 :
V_223 = F_118 ( F_224 , V_43 ,
L_7 , V_1 ) ;
if ( F_119 ( V_223 ) )
return F_229 ( F_230 ( V_223 ) ) ;
F_120 ( V_223 , V_1 ) ;
case V_228 :
F_33 ( V_43 -> V_229 ) ;
V_225 = F_112 ( V_43 , false ) ;
if ( ! V_225 ) {
if ( V_223 )
F_125 ( V_223 ) ;
return V_230 ;
}
}
F_79 ( & V_43 -> V_81 , V_10 ) ;
switch ( V_221 ) {
case V_227 :
F_33 ( V_43 -> V_136 || V_43 -> V_214 != V_218 ) ;
V_43 -> V_136 = V_223 ;
V_43 -> V_214 = V_231 ;
F_56 ( V_43 -> V_136 ) ;
F_227 ( V_43 , V_215 ) ;
case V_228 :
F_33 ( V_43 -> V_229 ) ;
V_43 -> V_229 = V_225 ;
break;
case V_232 :
V_43 -> V_10 |= V_233 ;
break;
case V_234 :
V_43 -> V_214 = V_235 ;
case V_236 :
F_124 ( V_43 -> V_229 ) ;
V_43 -> V_229 = NULL ;
break;
case V_237 :
case V_238 :
V_43 -> V_10 &= ~ V_233 ;
if ( V_43 -> V_214 != V_218 ) {
V_43 -> V_214 = V_239 ;
F_56 ( V_43 -> V_136 ) ;
F_227 ( V_43 , V_218 ) ;
}
F_107 ( & V_43 -> V_81 ) ;
F_120 ( V_43 -> V_229 -> V_57 , V_1 ) ;
F_113 ( & V_43 -> V_81 ) ;
V_43 -> V_10 |= V_48 ;
F_123 ( V_43 -> V_229 ) ;
V_43 -> V_229 = NULL ;
break;
}
F_81 ( & V_43 -> V_81 , V_10 ) ;
return F_229 ( 0 ) ;
}
static int F_231 ( void * V_240 )
{
struct V_241 * V_242 = V_240 ;
V_242 -> V_93 = V_242 -> V_189 ( V_242 -> V_243 ) ;
F_141 ( & V_242 -> V_244 ) ;
return 0 ;
}
long F_232 ( unsigned int V_1 , long (* V_189)( void * ) , void * V_243 )
{
struct V_58 * V_245 ;
struct V_241 V_242 = {
. V_244 = F_163 ( V_242 . V_244 ) ,
. V_189 = V_189 ,
. V_243 = V_243 ,
} ;
V_245 = F_118 ( F_231 , & V_242 , L_8 ) ;
if ( F_119 ( V_245 ) )
return F_230 ( V_245 ) ;
F_120 ( V_245 , V_1 ) ;
F_56 ( V_245 ) ;
F_168 ( & V_242 . V_244 ) ;
return V_242 . V_93 ;
}
void F_233 ( void )
{
unsigned int V_1 ;
F_171 ( & V_176 ) ;
F_33 ( V_207 ) ;
V_207 = true ;
F_78 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_8 * V_9 ;
F_113 ( & V_43 -> V_81 ) ;
F_33 ( V_43 -> V_10 & V_210 ) ;
V_43 -> V_10 |= V_210 ;
F_72 (wq, &workqueues, list) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
if ( V_36 && V_9 -> V_10 & V_208 )
V_36 -> V_90 = 0 ;
}
F_107 ( & V_43 -> V_81 ) ;
}
F_172 ( & V_176 ) ;
}
bool F_234 ( void )
{
unsigned int V_1 ;
bool V_246 = false ;
F_171 ( & V_176 ) ;
F_33 ( ! V_207 ) ;
F_78 (cpu) {
struct V_8 * V_9 ;
F_72 (wq, &workqueues, list) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
if ( ! V_36 || ! ( V_9 -> V_10 & V_208 ) )
continue;
F_33 ( V_36 -> V_89 < 0 ) ;
if ( V_36 -> V_89 ) {
V_246 = true ;
goto V_173;
}
}
}
V_173:
F_172 ( & V_176 ) ;
return V_246 ;
}
void F_235 ( void )
{
unsigned int V_1 ;
F_171 ( & V_176 ) ;
if ( ! V_207 )
goto V_173;
F_78 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_8 * V_9 ;
F_113 ( & V_43 -> V_81 ) ;
F_33 ( ! ( V_43 -> V_10 & V_210 ) ) ;
V_43 -> V_10 &= ~ V_210 ;
F_72 (wq, &workqueues, list) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
if ( ! V_36 || ! ( V_9 -> V_10 & V_208 ) )
continue;
V_36 -> V_90 = V_9 -> V_183 ;
while ( ! F_46 ( & V_36 -> V_92 ) &&
V_36 -> V_89 < V_36 -> V_90 )
F_138 ( V_36 ) ;
}
F_55 ( V_43 ) ;
F_107 ( & V_43 -> V_81 ) ;
}
V_207 = false ;
V_173:
F_172 ( & V_176 ) ;
}
static int T_7 F_236 ( void )
{
unsigned int V_1 ;
int V_80 ;
F_237 ( F_228 , V_247 ) ;
F_78 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
F_238 ( & V_43 -> V_81 ) ;
F_110 ( & V_43 -> V_45 ) ;
V_43 -> V_1 = V_1 ;
V_43 -> V_10 |= V_233 ;
F_110 ( & V_43 -> V_55 ) ;
for ( V_80 = 0 ; V_80 < V_248 ; V_80 ++ )
F_239 ( & V_43 -> V_69 [ V_80 ] ) ;
F_240 ( & V_43 -> V_111 ) ;
V_43 -> V_111 . V_104 = F_126 ;
V_43 -> V_111 . V_35 = ( unsigned long ) V_43 ;
F_241 ( & V_43 -> V_134 , F_131 ,
( unsigned long ) V_43 ) ;
F_242 ( & V_43 -> V_122 ) ;
V_43 -> V_214 = V_218 ;
F_243 ( & V_43 -> V_113 ) ;
}
F_244 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_54 * V_54 ;
if ( V_1 != V_6 )
V_43 -> V_10 &= ~ V_233 ;
V_54 = F_112 ( V_43 , true ) ;
F_33 ( ! V_54 ) ;
F_113 ( & V_43 -> V_81 ) ;
F_123 ( V_54 ) ;
F_107 ( & V_43 -> V_81 ) ;
}
V_186 = F_245 ( L_9 , 0 , 0 ) ;
V_249 = F_245 ( L_10 , 0 , 0 ) ;
V_250 = F_245 ( L_11 , V_86 , 0 ) ;
V_251 = F_245 ( L_12 , V_11 ,
V_197 ) ;
V_252 = F_245 ( L_13 ,
V_208 , 0 ) ;
F_33 ( ! V_186 || ! V_249 || ! V_250 ||
! V_251 || ! V_252 ) ;
return 0 ;
}
