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
if ( F_26 ( V_1 < V_5 ) )
return F_27 ( V_9 -> V_28 . V_29 , V_1 ) ;
} else if ( F_26 ( V_1 == V_6 ) )
return V_9 -> V_28 . V_30 ;
return NULL ;
}
static unsigned int F_28 ( int V_31 )
{
return V_31 << V_32 ;
}
static int F_29 ( struct V_13 * V_17 )
{
return ( * F_10 ( V_17 ) >> V_32 ) &
( ( 1 << V_33 ) - 1 ) ;
}
static int F_30 ( int V_31 )
{
return ( V_31 + 1 ) % V_34 ;
}
static inline void F_31 ( struct V_13 * V_17 , unsigned long V_35 ,
unsigned long V_10 )
{
F_32 ( ! F_33 ( V_17 ) ) ;
F_34 ( & V_17 -> V_35 , V_35 | V_10 | F_35 ( V_17 ) ) ;
}
static void F_36 ( struct V_13 * V_17 ,
struct V_27 * V_36 ,
unsigned long V_37 )
{
F_31 ( V_17 , ( unsigned long ) V_36 ,
V_38 | V_39 | V_37 ) ;
}
static void F_37 ( struct V_13 * V_17 , unsigned int V_1 )
{
F_31 ( V_17 , V_1 << V_40 , V_38 ) ;
}
static void F_38 ( struct V_13 * V_17 )
{
F_31 ( V_17 , V_41 , 0 ) ;
}
static struct V_27 * F_39 ( struct V_13 * V_17 )
{
unsigned long V_35 = F_40 ( & V_17 -> V_35 ) ;
if ( V_35 & V_39 )
return ( void * ) ( V_35 & V_42 ) ;
else
return NULL ;
}
static struct V_23 * F_41 ( struct V_13 * V_17 )
{
unsigned long V_35 = F_40 ( & V_17 -> V_35 ) ;
unsigned int V_1 ;
if ( V_35 & V_39 )
return ( (struct V_27 * )
( V_35 & V_42 ) ) -> V_43 ;
V_1 = V_35 >> V_40 ;
if ( V_1 == V_7 )
return NULL ;
F_32 ( V_1 >= V_5 && V_1 != V_6 ) ;
return F_22 ( V_1 ) ;
}
static bool F_42 ( struct V_23 * V_43 )
{
return ! F_43 ( F_24 ( V_43 -> V_1 ) ) ||
V_43 -> V_10 & V_44 ;
}
static bool F_44 ( struct V_23 * V_43 )
{
return ! F_45 ( & V_43 -> V_45 ) && F_42 ( V_43 ) ;
}
static bool F_46 ( struct V_23 * V_43 )
{
return V_43 -> V_46 ;
}
static bool F_47 ( struct V_23 * V_43 )
{
T_1 * V_47 = F_24 ( V_43 -> V_1 ) ;
return ! F_45 ( & V_43 -> V_45 ) &&
( F_43 ( V_47 ) <= 1 ||
V_43 -> V_10 & V_44 ) ;
}
static bool F_48 ( struct V_23 * V_43 )
{
return F_44 ( V_43 ) && ! F_46 ( V_43 ) ;
}
static bool F_49 ( struct V_23 * V_43 )
{
return F_48 ( V_43 ) || V_43 -> V_10 & V_48 ;
}
static bool F_50 ( struct V_23 * V_43 )
{
bool V_49 = V_43 -> V_10 & V_50 ;
int V_46 = V_43 -> V_46 + V_49 ;
int V_51 = V_43 -> V_52 - V_46 ;
return V_46 > 2 && ( V_46 - 2 ) * V_53 >= V_51 ;
}
static struct V_54 * F_51 ( struct V_23 * V_43 )
{
if ( F_52 ( F_45 ( & V_43 -> V_55 ) ) )
return NULL ;
return F_53 ( & V_43 -> V_55 , struct V_54 , V_56 ) ;
}
static void F_54 ( struct V_23 * V_43 )
{
struct V_54 * V_54 = F_51 ( V_43 ) ;
if ( F_26 ( V_54 ) )
F_55 ( V_54 -> V_57 ) ;
}
void F_56 ( struct V_58 * V_57 , unsigned int V_1 )
{
struct V_54 * V_54 = F_57 ( V_57 ) ;
if ( ! ( V_54 -> V_10 & V_59 ) )
F_58 ( F_24 ( V_1 ) ) ;
}
struct V_58 * F_59 ( struct V_58 * V_57 ,
unsigned int V_1 )
{
struct V_54 * V_54 = F_57 ( V_57 ) , * V_60 = NULL ;
struct V_23 * V_43 = F_22 ( V_1 ) ;
T_1 * V_47 = F_24 ( V_1 ) ;
if ( V_54 -> V_10 & V_59 )
return NULL ;
F_32 ( V_1 != F_60 () ) ;
if ( F_61 ( V_47 ) && ! F_45 ( & V_43 -> V_45 ) )
V_60 = F_51 ( V_43 ) ;
return V_60 ? V_60 -> V_57 : NULL ;
}
static inline void F_62 ( struct V_54 * V_54 , unsigned int V_10 ,
bool V_61 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
F_12 ( V_54 -> V_57 != V_62 ) ;
if ( ( V_10 & V_59 ) &&
! ( V_54 -> V_10 & V_59 ) ) {
T_1 * V_47 = F_24 ( V_43 -> V_1 ) ;
if ( V_61 ) {
if ( F_61 ( V_47 ) &&
! F_45 ( & V_43 -> V_45 ) )
F_54 ( V_43 ) ;
} else
F_63 ( V_47 ) ;
}
V_54 -> V_10 |= V_10 ;
}
static inline void F_64 ( struct V_54 * V_54 , unsigned int V_10 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
unsigned int V_63 = V_54 -> V_10 ;
F_12 ( V_54 -> V_57 != V_62 ) ;
V_54 -> V_10 &= ~ V_10 ;
if ( ( V_10 & V_59 ) && ( V_63 & V_59 ) )
if ( ! ( V_54 -> V_10 & V_59 ) )
F_58 ( F_24 ( V_43 -> V_1 ) ) ;
}
static struct V_64 * F_65 ( struct V_23 * V_43 ,
struct V_13 * V_17 )
{
const int V_65 = F_66 ( sizeof( struct V_13 ) ) ;
unsigned long V_66 = ( unsigned long ) V_17 ;
V_66 >>= V_65 ;
V_66 += V_66 >> V_67 ;
V_66 &= V_68 ;
return & V_43 -> V_69 [ V_66 ] ;
}
static struct V_54 * F_67 ( struct V_23 * V_43 ,
struct V_64 * V_70 ,
struct V_13 * V_17 )
{
struct V_54 * V_54 ;
struct V_71 * V_72 ;
F_68 (worker, tmp, bwh, hentry)
if ( V_54 -> V_73 == V_17 )
return V_54 ;
return NULL ;
}
static struct V_54 * F_69 ( struct V_23 * V_43 ,
struct V_13 * V_17 )
{
return F_67 ( V_43 , F_65 ( V_43 , V_17 ) ,
V_17 ) ;
}
static inline struct V_74 * F_70 ( struct V_23 * V_43 ,
struct V_27 * V_36 )
{
struct V_13 * V_75 ;
if ( F_26 ( ! ( V_36 -> V_9 -> V_10 & V_76 ) ) )
return & V_43 -> V_45 ;
F_71 (twork, &gcwq->worklist, entry) {
struct V_27 * V_77 = F_39 ( V_75 ) ;
if ( ! ( V_77 -> V_9 -> V_10 & V_76 ) )
break;
}
V_43 -> V_10 |= V_44 ;
return & V_75 -> V_56 ;
}
static void F_72 ( struct V_27 * V_36 ,
struct V_13 * V_17 , struct V_74 * V_78 ,
unsigned int V_37 )
{
struct V_23 * V_43 = V_36 -> V_43 ;
F_36 ( V_17 , V_36 , V_37 ) ;
F_73 () ;
F_74 ( & V_17 -> V_56 , V_78 ) ;
F_75 () ;
if ( F_42 ( V_43 ) )
F_54 ( V_43 ) ;
}
static bool F_76 ( struct V_8 * V_9 )
{
unsigned long V_10 ;
unsigned int V_1 ;
F_77 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_54 * V_54 ;
struct V_71 * V_79 ;
int V_80 ;
F_78 ( & V_43 -> V_81 , V_10 ) ;
F_79 (worker, i, pos, gcwq) {
if ( V_54 -> V_57 != V_62 )
continue;
F_80 ( & V_43 -> V_81 , V_10 ) ;
return V_54 -> V_82 -> V_9 == V_9 ;
}
F_80 ( & V_43 -> V_81 , V_10 ) ;
}
return false ;
}
static void F_81 ( unsigned int V_1 , struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_23 * V_43 ;
struct V_27 * V_36 ;
struct V_74 * V_45 ;
unsigned int V_83 ;
unsigned long V_10 ;
F_16 ( V_17 ) ;
if ( F_52 ( V_9 -> V_10 & V_84 ) &&
F_12 ( ! F_76 ( V_9 ) ) )
return;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_23 * V_85 ;
if ( F_52 ( V_1 == V_6 ) )
V_1 = F_60 () ;
V_43 = F_22 ( V_1 ) ;
if ( V_9 -> V_10 & V_86 &&
( V_85 = F_41 ( V_17 ) ) && V_85 != V_43 ) {
struct V_54 * V_54 ;
F_78 ( & V_85 -> V_81 , V_10 ) ;
V_54 = F_69 ( V_85 , V_17 ) ;
if ( V_54 && V_54 -> V_82 -> V_9 == V_9 )
V_43 = V_85 ;
else {
F_80 ( & V_85 -> V_81 , V_10 ) ;
F_78 ( & V_43 -> V_81 , V_10 ) ;
}
} else
F_78 ( & V_43 -> V_81 , V_10 ) ;
} else {
V_43 = F_22 ( V_6 ) ;
F_78 ( & V_43 -> V_81 , V_10 ) ;
}
V_36 = F_25 ( V_43 -> V_1 , V_9 ) ;
F_82 ( V_1 , V_36 , V_17 ) ;
if ( F_13 ( ! F_45 ( & V_17 -> V_56 ) ) ) {
F_80 ( & V_43 -> V_81 , V_10 ) ;
return;
}
V_36 -> V_87 [ V_36 -> V_88 ] ++ ;
V_83 = F_28 ( V_36 -> V_88 ) ;
if ( F_26 ( V_36 -> V_89 < V_36 -> V_90 ) ) {
F_83 ( V_17 ) ;
V_36 -> V_89 ++ ;
V_45 = F_70 ( V_43 , V_36 ) ;
} else {
V_83 |= V_91 ;
V_45 = & V_36 -> V_92 ;
}
F_72 ( V_36 , V_17 , V_45 , V_83 ) ;
F_80 ( & V_43 -> V_81 , V_10 ) ;
}
int F_84 ( struct V_8 * V_9 , struct V_13 * V_17 )
{
int V_93 ;
V_93 = F_85 ( F_86 () , V_9 , V_17 ) ;
F_87 () ;
return V_93 ;
}
int
F_85 ( int V_1 , struct V_8 * V_9 , struct V_13 * V_17 )
{
int V_93 = 0 ;
if ( ! F_88 ( V_94 , F_10 ( V_17 ) ) ) {
F_81 ( V_1 , V_9 , V_17 ) ;
V_93 = 1 ;
}
return V_93 ;
}
static void F_89 ( unsigned long V_95 )
{
struct V_96 * V_97 = (struct V_96 * ) V_95 ;
struct V_27 * V_36 = F_39 ( & V_97 -> V_17 ) ;
F_81 ( F_90 () , V_36 -> V_9 , & V_97 -> V_17 ) ;
}
int F_91 ( struct V_8 * V_9 ,
struct V_96 * V_97 , unsigned long V_98 )
{
if ( V_98 == 0 )
return F_84 ( V_9 , & V_97 -> V_17 ) ;
return F_92 ( - 1 , V_9 , V_97 , V_98 ) ;
}
int F_92 ( int V_1 , struct V_8 * V_9 ,
struct V_96 * V_97 , unsigned long V_98 )
{
int V_93 = 0 ;
struct V_99 * V_100 = & V_97 -> V_100 ;
struct V_13 * V_17 = & V_97 -> V_17 ;
if ( ! F_88 ( V_94 , F_10 ( V_17 ) ) ) {
unsigned int V_101 ;
F_32 ( F_93 ( V_100 ) ) ;
F_32 ( ! F_45 ( & V_17 -> V_56 ) ) ;
F_94 ( & V_97 -> V_100 ) ;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_23 * V_43 = F_41 ( V_17 ) ;
if ( V_43 && V_43 -> V_1 != V_6 )
V_101 = V_43 -> V_1 ;
else
V_101 = F_60 () ;
} else
V_101 = V_6 ;
F_36 ( V_17 , F_25 ( V_101 , V_9 ) , 0 ) ;
V_100 -> V_102 = V_103 + V_98 ;
V_100 -> V_35 = ( unsigned long ) V_97 ;
V_100 -> V_104 = F_89 ;
if ( F_52 ( V_1 >= 0 ) )
F_95 ( V_100 , V_1 ) ;
else
F_96 ( V_100 ) ;
V_93 = 1 ;
}
return V_93 ;
}
static void F_97 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
F_32 ( V_54 -> V_10 & V_105 ) ;
F_32 ( ! F_45 ( & V_54 -> V_56 ) &&
( V_54 -> V_106 . V_107 || V_54 -> V_106 . V_108 ) ) ;
V_54 -> V_10 |= V_105 ;
V_43 -> V_46 ++ ;
V_54 -> V_109 = V_103 ;
F_98 ( & V_54 -> V_56 , & V_43 -> V_55 ) ;
if ( F_26 ( ! ( V_54 -> V_10 & V_110 ) ) ) {
if ( F_50 ( V_43 ) && ! F_93 ( & V_43 -> V_111 ) )
F_99 ( & V_43 -> V_111 ,
V_103 + V_112 ) ;
} else
F_100 ( & V_43 -> V_113 ) ;
F_12 ( V_43 -> V_114 == V_115 &&
V_43 -> V_52 == V_43 -> V_46 &&
F_43 ( F_24 ( V_43 -> V_1 ) ) ) ;
}
static void F_101 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
F_32 ( ! ( V_54 -> V_10 & V_105 ) ) ;
F_64 ( V_54 , V_105 ) ;
V_43 -> V_46 -- ;
F_102 ( & V_54 -> V_56 ) ;
}
static bool F_103 ( struct V_54 * V_54 )
__acquires( &gcwq->lock
static void F_104 ( struct V_13 * V_17 )
{
struct V_54 * V_54 = F_105 ( V_17 , struct V_54 , V_116 ) ;
struct V_23 * V_43 = V_54 -> V_43 ;
if ( F_103 ( V_54 ) )
F_64 ( V_54 , V_117 ) ;
F_106 ( & V_43 -> V_81 ) ;
}
static struct V_54 * F_107 ( void )
{
struct V_54 * V_54 ;
V_54 = F_108 ( sizeof( * V_54 ) , V_118 ) ;
if ( V_54 ) {
F_109 ( & V_54 -> V_56 ) ;
F_109 ( & V_54 -> V_119 ) ;
F_110 ( & V_54 -> V_116 , F_104 ) ;
V_54 -> V_10 = V_120 ;
}
return V_54 ;
}
static struct V_54 * F_111 ( struct V_23 * V_43 , bool V_121 )
{
bool V_122 = V_43 -> V_1 == V_6 ;
struct V_54 * V_54 = NULL ;
int V_123 = - 1 ;
F_112 ( & V_43 -> V_81 ) ;
while ( F_113 ( & V_43 -> V_124 , & V_123 ) ) {
F_106 ( & V_43 -> V_81 ) ;
if ( ! F_114 ( & V_43 -> V_124 , V_118 ) )
goto V_125;
F_112 ( & V_43 -> V_81 ) ;
}
F_106 ( & V_43 -> V_81 ) ;
V_54 = F_107 () ;
if ( ! V_54 )
goto V_125;
V_54 -> V_43 = V_43 ;
V_54 -> V_123 = V_123 ;
if ( ! V_122 )
V_54 -> V_57 = F_115 ( V_126 ,
V_54 ,
F_116 ( V_43 -> V_1 ) ,
L_1 , V_43 -> V_1 , V_123 ) ;
else
V_54 -> V_57 = F_117 ( V_126 , V_54 ,
L_2 , V_123 ) ;
if ( F_118 ( V_54 -> V_57 ) )
goto V_125;
if ( V_121 && ! V_122 )
F_119 ( V_54 -> V_57 , V_43 -> V_1 ) ;
else {
V_54 -> V_57 -> V_10 |= V_127 ;
if ( V_122 )
V_54 -> V_10 |= V_128 ;
}
return V_54 ;
V_125:
if ( V_123 >= 0 ) {
F_112 ( & V_43 -> V_81 ) ;
F_120 ( & V_43 -> V_124 , V_123 ) ;
F_106 ( & V_43 -> V_81 ) ;
}
F_121 ( V_54 ) ;
return NULL ;
}
static void F_122 ( struct V_54 * V_54 )
{
V_54 -> V_10 |= V_129 ;
V_54 -> V_43 -> V_52 ++ ;
F_97 ( V_54 ) ;
F_55 ( V_54 -> V_57 ) ;
}
static void F_123 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
int V_123 = V_54 -> V_123 ;
F_32 ( V_54 -> V_73 ) ;
F_32 ( ! F_45 ( & V_54 -> V_119 ) ) ;
if ( V_54 -> V_10 & V_129 )
V_43 -> V_52 -- ;
if ( V_54 -> V_10 & V_105 )
V_43 -> V_46 -- ;
F_102 ( & V_54 -> V_56 ) ;
V_54 -> V_10 |= V_130 ;
F_106 ( & V_43 -> V_81 ) ;
F_124 ( V_54 -> V_57 ) ;
F_121 ( V_54 ) ;
F_112 ( & V_43 -> V_81 ) ;
F_120 ( & V_43 -> V_124 , V_123 ) ;
}
static void F_125 ( unsigned long V_131 )
{
struct V_23 * V_43 = ( void * ) V_131 ;
F_112 ( & V_43 -> V_81 ) ;
if ( F_50 ( V_43 ) ) {
struct V_54 * V_54 ;
unsigned long V_102 ;
V_54 = F_126 ( V_43 -> V_55 . V_132 , struct V_54 , V_56 ) ;
V_102 = V_54 -> V_109 + V_112 ;
if ( F_127 ( V_103 , V_102 ) )
F_99 ( & V_43 -> V_111 , V_102 ) ;
else {
V_43 -> V_10 |= V_48 ;
F_54 ( V_43 ) ;
}
}
F_106 ( & V_43 -> V_81 ) ;
}
static bool F_128 ( struct V_13 * V_17 )
{
struct V_27 * V_36 = F_39 ( V_17 ) ;
struct V_8 * V_9 = V_36 -> V_9 ;
unsigned int V_1 ;
if ( ! ( V_9 -> V_10 & V_133 ) )
return false ;
V_1 = V_36 -> V_43 -> V_1 ;
if ( V_1 == V_6 )
V_1 = 0 ;
if ( ! F_129 ( V_1 , V_9 -> V_134 ) )
F_55 ( V_9 -> V_135 -> V_57 ) ;
return true ;
}
static void F_130 ( unsigned long V_131 )
{
struct V_23 * V_43 = ( void * ) V_131 ;
struct V_13 * V_17 ;
F_112 ( & V_43 -> V_81 ) ;
if ( F_48 ( V_43 ) ) {
F_71 (work, &gcwq->worklist, entry)
F_128 ( V_17 ) ;
}
F_106 ( & V_43 -> V_81 ) ;
F_99 ( & V_43 -> V_136 , V_103 + V_137 ) ;
}
static bool F_131 ( struct V_23 * V_43 )
__releases( &gcwq->lock
static bool F_132 ( struct V_23 * V_43 )
{
bool V_93 = false ;
while ( F_50 ( V_43 ) ) {
struct V_54 * V_54 ;
unsigned long V_102 ;
V_54 = F_126 ( V_43 -> V_55 . V_132 , struct V_54 , V_56 ) ;
V_102 = V_54 -> V_109 + V_112 ;
if ( F_127 ( V_103 , V_102 ) ) {
F_99 ( & V_43 -> V_111 , V_102 ) ;
break;
}
F_123 ( V_54 ) ;
V_93 = true ;
}
return V_93 ;
}
static bool F_133 ( struct V_54 * V_54 )
{
struct V_23 * V_43 = V_54 -> V_43 ;
bool V_93 = false ;
if ( V_43 -> V_10 & V_50 )
return V_93 ;
V_43 -> V_10 &= ~ V_48 ;
V_43 -> V_10 |= V_50 ;
V_93 |= F_132 ( V_43 ) ;
V_93 |= F_131 ( V_43 ) ;
V_43 -> V_10 &= ~ V_50 ;
if ( F_52 ( V_43 -> V_138 ) )
F_100 ( & V_43 -> V_113 ) ;
return V_93 ;
}
static void F_134 ( struct V_13 * V_17 , struct V_74 * V_78 ,
struct V_13 * * V_139 )
{
struct V_13 * V_140 ;
F_135 (work, n, NULL, entry) {
F_136 ( & V_17 -> V_56 , V_78 ) ;
if ( ! ( * F_10 ( V_17 ) & V_141 ) )
break;
}
if ( V_139 )
* V_139 = V_140 ;
}
static void F_137 ( struct V_27 * V_36 )
{
struct V_13 * V_17 = F_53 ( & V_36 -> V_92 ,
struct V_13 , V_56 ) ;
struct V_74 * V_79 = F_70 ( V_36 -> V_43 , V_36 ) ;
F_83 ( V_17 ) ;
F_134 ( V_17 , V_79 , NULL ) ;
F_138 ( V_142 , F_10 ( V_17 ) ) ;
V_36 -> V_89 ++ ;
}
static void F_139 ( struct V_27 * V_36 , int V_31 ,
bool V_143 )
{
if ( V_31 == V_144 )
return;
V_36 -> V_87 [ V_31 ] -- ;
if ( ! V_143 ) {
V_36 -> V_89 -- ;
if ( ! F_45 ( & V_36 -> V_92 ) ) {
if ( V_36 -> V_89 < V_36 -> V_90 )
F_137 ( V_36 ) ;
}
}
if ( F_26 ( V_36 -> V_145 != V_31 ) )
return;
if ( V_36 -> V_87 [ V_31 ] )
return;
V_36 -> V_145 = - 1 ;
if ( F_61 ( & V_36 -> V_9 -> V_146 ) )
F_140 ( & V_36 -> V_9 -> V_147 -> V_148 ) ;
}
static void F_141 ( struct V_54 * V_54 , struct V_13 * V_17 )
__releases( &gcwq->lock
static void F_142 ( struct V_54 * V_54 )
{
while ( ! F_45 ( & V_54 -> V_119 ) ) {
struct V_13 * V_17 = F_53 ( & V_54 -> V_119 ,
struct V_13 , V_56 ) ;
F_141 ( V_54 , V_17 ) ;
}
}
static int V_126 ( void * V_149 )
{
struct V_54 * V_54 = V_149 ;
struct V_23 * V_43 = V_54 -> V_43 ;
V_54 -> V_57 -> V_10 |= V_150 ;
V_151:
F_112 ( & V_43 -> V_81 ) ;
if ( V_54 -> V_10 & V_130 ) {
F_106 ( & V_43 -> V_81 ) ;
V_54 -> V_57 -> V_10 &= ~ V_150 ;
return 0 ;
}
F_101 ( V_54 ) ;
V_152:
if ( ! F_44 ( V_43 ) )
goto V_153;
if ( F_52 ( ! F_46 ( V_43 ) ) && F_133 ( V_54 ) )
goto V_152;
F_32 ( ! F_45 ( & V_54 -> V_119 ) ) ;
F_64 ( V_54 , V_120 ) ;
do {
struct V_13 * V_17 =
F_53 ( & V_43 -> V_45 ,
struct V_13 , V_56 ) ;
if ( F_26 ( ! ( * F_10 ( V_17 ) & V_141 ) ) ) {
F_141 ( V_54 , V_17 ) ;
if ( F_52 ( ! F_45 ( & V_54 -> V_119 ) ) )
F_142 ( V_54 ) ;
} else {
F_134 ( V_17 , & V_54 -> V_119 , NULL ) ;
F_142 ( V_54 ) ;
}
} while ( F_47 ( V_43 ) );
F_62 ( V_54 , V_120 , false ) ;
V_153:
if ( F_52 ( F_49 ( V_43 ) ) && F_133 ( V_54 ) )
goto V_152;
F_97 ( V_54 ) ;
F_143 ( V_154 ) ;
F_106 ( & V_43 -> V_81 ) ;
F_144 () ;
goto V_151;
}
static int F_145 ( void * V_155 )
{
struct V_8 * V_9 = V_155 ;
struct V_54 * V_135 = V_9 -> V_135 ;
struct V_74 * V_119 = & V_135 -> V_119 ;
bool V_156 = V_9 -> V_10 & V_11 ;
unsigned int V_1 ;
F_146 ( V_62 , V_157 ) ;
V_158:
F_147 ( V_154 ) ;
if ( F_148 () )
return 0 ;
F_149 (cpu, wq->mayday_mask) {
unsigned int V_159 = V_156 ? V_6 : V_1 ;
struct V_27 * V_36 = F_25 ( V_159 , V_9 ) ;
struct V_23 * V_43 = V_36 -> V_43 ;
struct V_13 * V_17 , * V_140 ;
F_143 ( V_160 ) ;
F_150 ( V_1 , V_9 -> V_134 ) ;
V_135 -> V_43 = V_43 ;
F_103 ( V_135 ) ;
F_32 ( ! F_45 ( & V_135 -> V_119 ) ) ;
F_151 (work, n, &gcwq->worklist, entry)
if ( F_39 ( V_17 ) == V_36 )
F_134 ( V_17 , V_119 , & V_140 ) ;
F_142 ( V_135 ) ;
if ( F_47 ( V_43 ) )
F_54 ( V_43 ) ;
F_106 ( & V_43 -> V_81 ) ;
}
F_144 () ;
goto V_158;
}
static void F_152 ( struct V_13 * V_17 )
{
struct V_161 * V_162 = F_105 ( V_17 , struct V_161 , V_17 ) ;
F_140 ( & V_162 -> V_148 ) ;
}
static void F_153 ( struct V_27 * V_36 ,
struct V_161 * V_162 ,
struct V_13 * V_163 , struct V_54 * V_54 )
{
struct V_74 * V_78 ;
unsigned int V_164 = 0 ;
F_154 ( & V_162 -> V_17 , F_152 ) ;
F_155 ( V_94 , F_10 ( & V_162 -> V_17 ) ) ;
F_156 ( & V_162 -> V_148 ) ;
if ( V_54 )
V_78 = V_54 -> V_119 . V_107 ;
else {
unsigned long * V_165 = F_10 ( V_163 ) ;
V_78 = V_163 -> V_56 . V_107 ;
V_164 = * V_165 & V_141 ;
F_155 ( V_166 , V_165 ) ;
}
F_16 ( & V_162 -> V_17 ) ;
F_72 ( V_36 , & V_162 -> V_17 , V_78 ,
F_28 ( V_144 ) | V_164 ) ;
}
static bool F_157 ( struct V_8 * V_9 ,
int V_145 , int V_88 )
{
bool V_167 = false ;
unsigned int V_1 ;
if ( V_145 >= 0 ) {
F_32 ( F_43 ( & V_9 -> V_146 ) ) ;
F_158 ( & V_9 -> V_146 , 1 ) ;
}
F_159 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
struct V_23 * V_43 = V_36 -> V_43 ;
F_112 ( & V_43 -> V_81 ) ;
if ( V_145 >= 0 ) {
F_32 ( V_36 -> V_145 != - 1 ) ;
if ( V_36 -> V_87 [ V_145 ] ) {
V_36 -> V_145 = V_145 ;
F_58 ( & V_9 -> V_146 ) ;
V_167 = true ;
}
}
if ( V_88 >= 0 ) {
F_32 ( V_88 != F_30 ( V_36 -> V_88 ) ) ;
V_36 -> V_88 = V_88 ;
}
F_106 ( & V_43 -> V_81 ) ;
}
if ( V_145 >= 0 && F_61 ( & V_9 -> V_146 ) )
F_140 ( & V_9 -> V_147 -> V_148 ) ;
return V_167 ;
}
void F_160 ( struct V_8 * V_9 )
{
struct V_168 V_169 = {
. V_170 = F_161 ( V_169 . V_170 ) ,
. V_145 = - 1 ,
. V_148 = F_162 ( V_169 . V_148 ) ,
} ;
int V_171 ;
F_163 ( & V_9 -> V_172 ) ;
F_164 ( & V_9 -> V_172 ) ;
F_165 ( & V_9 -> V_173 ) ;
V_171 = F_30 ( V_9 -> V_88 ) ;
if ( V_171 != V_9 -> V_145 ) {
F_32 ( ! F_45 ( & V_9 -> V_174 ) ) ;
V_169 . V_145 = V_9 -> V_88 ;
V_9 -> V_88 = V_171 ;
if ( ! V_9 -> V_147 ) {
F_32 ( V_9 -> V_145 != V_169 . V_145 ) ;
V_9 -> V_147 = & V_169 ;
if ( ! F_157 ( V_9 , V_9 -> V_145 ,
V_9 -> V_88 ) ) {
V_9 -> V_145 = V_171 ;
V_9 -> V_147 = NULL ;
goto V_175;
}
} else {
F_32 ( V_9 -> V_145 == V_169 . V_145 ) ;
F_74 ( & V_169 . V_170 , & V_9 -> V_176 ) ;
F_157 ( V_9 , - 1 , V_9 -> V_88 ) ;
}
} else {
F_74 ( & V_169 . V_170 , & V_9 -> V_174 ) ;
}
F_166 ( & V_9 -> V_173 ) ;
F_167 ( & V_169 . V_148 ) ;
if ( V_9 -> V_147 != & V_169 )
return;
F_165 ( & V_9 -> V_173 ) ;
if ( V_9 -> V_147 != & V_169 )
goto V_175;
V_9 -> V_147 = NULL ;
F_32 ( ! F_45 ( & V_169 . V_170 ) ) ;
F_32 ( V_9 -> V_145 != V_169 . V_145 ) ;
while ( true ) {
struct V_168 * V_107 , * V_72 ;
F_151 (next, tmp, &wq->flusher_queue, list) {
if ( V_107 -> V_145 != V_9 -> V_145 )
break;
F_102 ( & V_107 -> V_170 ) ;
F_140 ( & V_107 -> V_148 ) ;
}
F_32 ( ! F_45 ( & V_9 -> V_174 ) &&
V_9 -> V_145 != F_30 ( V_9 -> V_88 ) ) ;
V_9 -> V_145 = F_30 ( V_9 -> V_145 ) ;
if ( ! F_45 ( & V_9 -> V_174 ) ) {
F_71 (tmp, &wq->flusher_overflow, list)
V_72 -> V_145 = V_9 -> V_88 ;
V_9 -> V_88 = F_30 ( V_9 -> V_88 ) ;
F_168 ( & V_9 -> V_174 ,
& V_9 -> V_176 ) ;
F_157 ( V_9 , - 1 , V_9 -> V_88 ) ;
}
if ( F_45 ( & V_9 -> V_176 ) ) {
F_32 ( V_9 -> V_145 != V_9 -> V_88 ) ;
break;
}
F_32 ( V_9 -> V_145 == V_9 -> V_88 ) ;
F_32 ( V_9 -> V_145 != V_107 -> V_145 ) ;
F_102 ( & V_107 -> V_170 ) ;
V_9 -> V_147 = V_107 ;
if ( F_157 ( V_9 , V_9 -> V_145 , - 1 ) )
break;
V_9 -> V_147 = NULL ;
}
V_175:
F_166 ( & V_9 -> V_173 ) ;
}
void F_169 ( struct V_8 * V_9 )
{
unsigned int V_177 = 0 ;
unsigned int V_1 ;
F_170 ( & V_178 ) ;
if ( ! V_9 -> V_179 ++ )
V_9 -> V_10 |= V_84 ;
F_171 ( & V_178 ) ;
V_180:
F_160 ( V_9 ) ;
F_159 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
bool V_181 ;
F_112 ( & V_36 -> V_43 -> V_81 ) ;
V_181 = ! V_36 -> V_89 && F_45 ( & V_36 -> V_92 ) ;
F_106 ( & V_36 -> V_43 -> V_81 ) ;
if ( V_181 )
continue;
if ( ++ V_177 == 10 ||
( V_177 % 100 == 0 && V_177 <= 1000 ) )
F_172 ( L_3 ,
V_9 -> V_182 , V_177 ) ;
goto V_180;
}
F_170 ( & V_178 ) ;
if ( ! -- V_9 -> V_179 )
V_9 -> V_10 &= ~ V_84 ;
F_171 ( & V_178 ) ;
}
static bool F_173 ( struct V_13 * V_17 , struct V_161 * V_162 ,
bool V_183 )
{
struct V_54 * V_54 = NULL ;
struct V_23 * V_43 ;
struct V_27 * V_36 ;
F_174 () ;
V_43 = F_41 ( V_17 ) ;
if ( ! V_43 )
return false ;
F_112 ( & V_43 -> V_81 ) ;
if ( ! F_45 ( & V_17 -> V_56 ) ) {
F_175 () ;
V_36 = F_39 ( V_17 ) ;
if ( F_52 ( ! V_36 || V_43 != V_36 -> V_43 ) )
goto V_184;
} else if ( V_183 ) {
V_54 = F_69 ( V_43 , V_17 ) ;
if ( ! V_54 )
goto V_184;
V_36 = V_54 -> V_82 ;
} else
goto V_184;
F_153 ( V_36 , V_162 , V_17 , V_54 ) ;
F_106 ( & V_43 -> V_81 ) ;
if ( V_36 -> V_9 -> V_185 == 1 || V_36 -> V_9 -> V_10 & V_133 )
F_163 ( & V_36 -> V_9 -> V_172 ) ;
else
F_176 ( & V_36 -> V_9 -> V_172 ) ;
F_164 ( & V_36 -> V_9 -> V_172 ) ;
return true ;
V_184:
F_106 ( & V_43 -> V_81 ) ;
return false ;
}
bool F_177 ( struct V_13 * V_17 )
{
struct V_161 V_162 ;
F_163 ( & V_17 -> V_172 ) ;
F_164 ( & V_17 -> V_172 ) ;
if ( F_173 ( V_17 , & V_162 , true ) ) {
F_167 ( & V_162 . V_148 ) ;
F_21 ( & V_162 . V_17 ) ;
return true ;
} else
return false ;
}
static bool F_178 ( struct V_23 * V_43 , struct V_13 * V_17 )
{
struct V_161 V_162 ;
struct V_54 * V_54 ;
F_112 ( & V_43 -> V_81 ) ;
V_54 = F_69 ( V_43 , V_17 ) ;
if ( F_52 ( V_54 ) )
F_153 ( V_54 -> V_82 , & V_162 , V_17 , V_54 ) ;
F_106 ( & V_43 -> V_81 ) ;
if ( F_52 ( V_54 ) ) {
F_167 ( & V_162 . V_148 ) ;
F_21 ( & V_162 . V_17 ) ;
return true ;
} else
return false ;
}
static bool F_179 ( struct V_13 * V_17 )
{
bool V_93 = false ;
int V_1 ;
F_174 () ;
F_163 ( & V_17 -> V_172 ) ;
F_164 ( & V_17 -> V_172 ) ;
F_77 (cpu)
V_93 |= F_178 ( F_22 ( V_1 ) , V_17 ) ;
return V_93 ;
}
bool F_180 ( struct V_13 * V_17 )
{
struct V_161 V_162 ;
bool V_186 , V_187 ;
V_186 = F_173 ( V_17 , & V_162 , false ) ;
V_187 = F_179 ( V_17 ) ;
if ( V_186 ) {
F_167 ( & V_162 . V_148 ) ;
F_21 ( & V_162 . V_17 ) ;
}
return V_186 || V_187 ;
}
static int F_181 ( struct V_13 * V_17 )
{
struct V_23 * V_43 ;
int V_93 = - 1 ;
if ( ! F_88 ( V_94 , F_10 ( V_17 ) ) )
return 0 ;
V_43 = F_41 ( V_17 ) ;
if ( ! V_43 )
return V_93 ;
F_112 ( & V_43 -> V_81 ) ;
if ( ! F_45 ( & V_17 -> V_56 ) ) {
F_175 () ;
if ( V_43 == F_41 ( V_17 ) ) {
F_17 ( V_17 ) ;
F_102 ( & V_17 -> V_56 ) ;
F_139 ( F_39 ( V_17 ) ,
F_29 ( V_17 ) ,
* F_10 ( V_17 ) & V_91 ) ;
V_93 = 1 ;
}
}
F_106 ( & V_43 -> V_81 ) ;
return V_93 ;
}
static bool F_182 ( struct V_13 * V_17 ,
struct V_99 * V_100 )
{
int V_93 ;
do {
V_93 = ( V_100 && F_26 ( F_183 ( V_100 ) ) ) ;
if ( ! V_93 )
V_93 = F_181 ( V_17 ) ;
F_179 ( V_17 ) ;
} while ( F_52 ( V_93 < 0 ) );
F_38 ( V_17 ) ;
return V_93 ;
}
bool F_6 ( struct V_13 * V_17 )
{
return F_182 ( V_17 , NULL ) ;
}
bool F_184 ( struct V_96 * V_97 )
{
if ( F_185 ( & V_97 -> V_100 ) )
F_81 ( F_60 () ,
F_39 ( & V_97 -> V_17 ) -> V_9 , & V_97 -> V_17 ) ;
return F_177 ( & V_97 -> V_17 ) ;
}
bool F_186 ( struct V_96 * V_97 )
{
if ( F_185 ( & V_97 -> V_100 ) )
F_81 ( F_60 () ,
F_39 ( & V_97 -> V_17 ) -> V_9 , & V_97 -> V_17 ) ;
return F_180 ( & V_97 -> V_17 ) ;
}
bool F_187 ( struct V_96 * V_97 )
{
return F_182 ( & V_97 -> V_17 , & V_97 -> V_100 ) ;
}
int F_188 ( struct V_13 * V_17 )
{
return F_84 ( V_188 , V_17 ) ;
}
int F_189 ( int V_1 , struct V_13 * V_17 )
{
return F_85 ( V_1 , V_188 , V_17 ) ;
}
int F_190 ( struct V_96 * V_97 ,
unsigned long V_98 )
{
return F_91 ( V_188 , V_97 , V_98 ) ;
}
int F_191 ( int V_1 ,
struct V_96 * V_97 , unsigned long V_98 )
{
return F_92 ( V_1 , V_188 , V_97 , V_98 ) ;
}
int F_192 ( T_2 V_14 )
{
int V_1 ;
struct V_13 T_3 * V_189 ;
V_189 = F_193 ( struct V_13 ) ;
if ( ! V_189 )
return - V_190 ;
F_194 () ;
F_195 (cpu) {
struct V_13 * V_17 = F_27 ( V_189 , V_1 ) ;
F_110 ( V_17 , V_14 ) ;
F_189 ( V_1 , V_17 ) ;
}
F_195 (cpu)
F_177 ( F_27 ( V_189 , V_1 ) ) ;
F_196 () ;
F_197 ( V_189 ) ;
return 0 ;
}
void F_198 ( void )
{
F_160 ( V_188 ) ;
}
int F_199 ( T_2 V_191 , struct V_192 * V_193 )
{
if ( ! F_200 () ) {
V_191 ( & V_193 -> V_17 ) ;
return 0 ;
}
F_110 ( & V_193 -> V_17 , V_191 ) ;
F_188 ( & V_193 -> V_17 ) ;
return 1 ;
}
int F_201 ( void )
{
return V_188 != NULL ;
}
static int F_202 ( struct V_8 * V_9 )
{
const T_4 V_194 = sizeof( struct V_27 ) ;
const T_4 V_195 = F_203 ( T_4 , 1 << V_40 ,
F_204 (unsigned long long) ) ;
if ( ! ( V_9 -> V_10 & V_11 ) )
V_9 -> V_28 . V_29 = F_205 ( V_194 , V_195 ) ;
else {
void * V_196 ;
V_196 = F_108 ( V_194 + V_195 + sizeof( void * ) , V_118 ) ;
if ( V_196 ) {
V_9 -> V_28 . V_30 = F_206 ( V_196 , V_195 ) ;
* ( void * * ) ( V_9 -> V_28 . V_30 + 1 ) = V_196 ;
}
}
F_32 ( ! F_207 ( V_9 -> V_28 . V_66 , V_195 ) ) ;
return V_9 -> V_28 . V_66 ? 0 : - V_190 ;
}
static void F_208 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_10 & V_11 ) )
F_197 ( V_9 -> V_28 . V_29 ) ;
else if ( V_9 -> V_28 . V_30 ) {
F_121 ( * ( void * * ) ( V_9 -> V_28 . V_30 + 1 ) ) ;
}
}
static int F_209 ( int V_90 , unsigned int V_10 ,
const char * V_182 )
{
int V_197 = V_10 & V_11 ? V_198 : V_199 ;
if ( V_90 < 1 || V_90 > V_197 )
F_210 ( V_200 L_4
L_5 ,
V_90 , V_182 , 1 , V_197 ) ;
return F_211 ( V_90 , 1 , V_197 ) ;
}
struct V_8 * F_212 ( const char * V_201 ,
unsigned int V_10 ,
int V_90 ,
struct V_202 * V_203 ,
const char * V_204 , ... )
{
T_5 args , V_205 ;
struct V_8 * V_9 ;
unsigned int V_1 ;
T_4 V_206 ;
va_start ( args , V_204 ) ;
F_213 ( V_205 , args ) ;
V_206 = vsnprintf ( NULL , 0 , V_201 , args ) + 1 ;
V_9 = F_108 ( sizeof( * V_9 ) + V_206 , V_118 ) ;
if ( ! V_9 )
goto V_207;
vsnprintf ( V_9 -> V_182 , V_206 , V_201 , V_205 ) ;
va_end ( args ) ;
va_end ( V_205 ) ;
if ( V_10 & V_208 )
V_10 |= V_133 ;
if ( V_10 & V_11 )
V_10 |= V_76 ;
V_90 = V_90 ? : V_209 ;
V_90 = F_209 ( V_90 , V_10 , V_9 -> V_182 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_185 = V_90 ;
F_214 ( & V_9 -> V_173 ) ;
F_158 ( & V_9 -> V_146 , 0 ) ;
F_109 ( & V_9 -> V_176 ) ;
F_109 ( & V_9 -> V_174 ) ;
F_215 ( & V_9 -> V_172 , V_204 , V_203 , 0 ) ;
F_109 ( & V_9 -> V_170 ) ;
if ( F_202 ( V_9 ) < 0 )
goto V_207;
F_159 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
struct V_23 * V_43 = F_22 ( V_1 ) ;
F_32 ( ( unsigned long ) V_36 & V_210 ) ;
V_36 -> V_43 = V_43 ;
V_36 -> V_9 = V_9 ;
V_36 -> V_145 = - 1 ;
V_36 -> V_90 = V_90 ;
F_109 ( & V_36 -> V_92 ) ;
}
if ( V_10 & V_133 ) {
struct V_54 * V_135 ;
if ( ! F_216 ( & V_9 -> V_134 , V_118 ) )
goto V_207;
V_9 -> V_135 = V_135 = F_107 () ;
if ( ! V_135 )
goto V_207;
V_135 -> V_57 = F_117 ( F_145 , V_9 , L_6 ,
V_9 -> V_182 ) ;
if ( F_118 ( V_135 -> V_57 ) )
goto V_207;
V_135 -> V_57 -> V_10 |= V_127 ;
F_55 ( V_135 -> V_57 ) ;
}
F_170 ( & V_178 ) ;
if ( V_211 && V_9 -> V_10 & V_212 )
F_159 (cpu, wq)
F_25 ( V_1 , V_9 ) -> V_90 = 0 ;
F_98 ( & V_9 -> V_170 , & V_213 ) ;
F_171 ( & V_178 ) ;
return V_9 ;
V_207:
if ( V_9 ) {
F_208 ( V_9 ) ;
F_217 ( V_9 -> V_134 ) ;
F_121 ( V_9 -> V_135 ) ;
F_121 ( V_9 ) ;
}
return NULL ;
}
void F_218 ( struct V_8 * V_9 )
{
unsigned int V_1 ;
F_169 ( V_9 ) ;
F_170 ( & V_178 ) ;
F_219 ( & V_9 -> V_170 ) ;
F_171 ( & V_178 ) ;
F_159 (cpu, wq) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_34 ; V_80 ++ )
F_32 ( V_36 -> V_87 [ V_80 ] ) ;
F_32 ( V_36 -> V_89 ) ;
F_32 ( ! F_45 ( & V_36 -> V_92 ) ) ;
}
if ( V_9 -> V_10 & V_133 ) {
F_124 ( V_9 -> V_135 -> V_57 ) ;
F_217 ( V_9 -> V_134 ) ;
F_121 ( V_9 -> V_135 ) ;
}
F_208 ( V_9 ) ;
F_121 ( V_9 ) ;
}
void F_220 ( struct V_8 * V_9 , int V_90 )
{
unsigned int V_1 ;
V_90 = F_209 ( V_90 , V_9 -> V_10 , V_9 -> V_182 ) ;
F_170 ( & V_178 ) ;
V_9 -> V_185 = V_90 ;
F_159 (cpu, wq) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
F_112 ( & V_43 -> V_81 ) ;
if ( ! ( V_9 -> V_10 & V_212 ) ||
! ( V_43 -> V_10 & V_214 ) )
F_25 ( V_43 -> V_1 , V_9 ) -> V_90 = V_90 ;
F_106 ( & V_43 -> V_81 ) ;
}
F_171 ( & V_178 ) ;
}
bool F_221 ( unsigned int V_1 , struct V_8 * V_9 )
{
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
return ! F_45 ( & V_36 -> V_92 ) ;
}
unsigned int F_222 ( struct V_13 * V_17 )
{
struct V_23 * V_43 = F_41 ( V_17 ) ;
return V_43 ? V_43 -> V_1 : V_7 ;
}
unsigned int F_223 ( struct V_13 * V_17 )
{
struct V_23 * V_43 = F_41 ( V_17 ) ;
unsigned long V_10 ;
unsigned int V_93 = 0 ;
if ( ! V_43 )
return false ;
F_78 ( & V_43 -> V_81 , V_10 ) ;
if ( F_33 ( V_17 ) )
V_93 |= V_215 ;
if ( F_69 ( V_43 , V_17 ) )
V_93 |= V_216 ;
F_80 ( & V_43 -> V_81 , V_10 ) ;
return V_93 ;
}
static int T_6 F_224 ( void * V_131 )
{
struct V_23 * V_43 = V_131 ;
struct V_54 * V_54 ;
struct V_13 * V_17 ;
struct V_71 * V_79 ;
long V_217 ;
int V_80 ;
F_32 ( V_43 -> V_1 != F_90 () ) ;
F_112 ( & V_43 -> V_81 ) ;
F_32 ( V_43 -> V_1 != F_90 () ) ;
V_217 = F_225 ( ! ( V_43 -> V_10 & V_50 ) ) ;
F_32 ( V_217 < 0 ) ;
V_43 -> V_10 |= V_50 ;
F_71 (worker, &gcwq->idle_list, entry)
V_54 -> V_10 |= V_110 ;
F_79 (worker, i, pos, gcwq)
V_54 -> V_10 |= V_110 ;
F_106 ( & V_43 -> V_81 ) ;
F_144 () ;
F_112 ( & V_43 -> V_81 ) ;
F_158 ( F_24 ( V_43 -> V_1 ) , 0 ) ;
F_106 ( & V_43 -> V_81 ) ;
F_185 ( & V_43 -> V_111 ) ;
F_112 ( & V_43 -> V_81 ) ;
V_43 -> V_114 = V_218 ;
F_100 ( & V_43 -> V_113 ) ;
while ( V_43 -> V_52 != V_43 -> V_46 ||
V_43 -> V_10 & V_214 ||
V_43 -> V_114 == V_218 ) {
int V_219 = 0 ;
F_71 (work, &gcwq->worklist, entry) {
F_128 ( V_17 ) ;
V_219 ++ ;
}
F_71 (worker, &gcwq->idle_list, entry) {
if ( ! V_219 -- )
break;
F_55 ( V_54 -> V_57 ) ;
}
if ( F_48 ( V_43 ) ) {
F_106 ( & V_43 -> V_81 ) ;
V_54 = F_111 ( V_43 , false ) ;
F_112 ( & V_43 -> V_81 ) ;
if ( V_54 ) {
V_54 -> V_10 |= V_110 ;
F_122 ( V_54 ) ;
}
}
if ( F_226 ( false , V_220 ) < 0 )
break;
}
do {
V_217 = F_225 ( ! F_45 ( & V_43 -> V_55 ) ) ;
while ( ! F_45 ( & V_43 -> V_55 ) )
F_123 ( F_53 ( & V_43 -> V_55 ,
struct V_54 , V_56 ) ) ;
} while ( V_43 -> V_52 && V_217 >= 0 );
F_13 ( ! F_45 ( & V_43 -> V_55 ) ) ;
F_79 (worker, i, pos, gcwq) {
struct V_13 * V_116 = & V_54 -> V_116 ;
V_54 -> V_10 |= V_117 ;
V_54 -> V_10 &= ~ V_110 ;
if ( F_88 ( V_94 ,
F_10 ( V_116 ) ) )
continue;
F_16 ( V_116 ) ;
F_72 ( F_25 ( V_43 -> V_1 , V_188 ) , V_116 ,
V_54 -> V_119 . V_107 ,
F_28 ( V_144 ) ) ;
}
V_43 -> V_10 &= ~ V_50 ;
V_43 -> V_138 = NULL ;
V_43 -> V_114 = V_115 ;
F_100 ( & V_43 -> V_113 ) ;
F_106 ( & V_43 -> V_81 ) ;
return 0 ;
}
static void T_6 F_227 ( struct V_23 * V_43 , int V_16 )
__releases( &gcwq->lock
static int T_7 F_228 ( struct V_221 * V_222 ,
unsigned long V_223 ,
void * V_224 )
{
unsigned int V_1 = ( unsigned long ) V_224 ;
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_58 * V_225 = NULL ;
struct V_54 * V_226 ( V_227 ) ;
unsigned long V_10 ;
V_223 &= ~ V_228 ;
switch ( V_223 ) {
case V_229 :
V_225 = F_117 ( F_224 , V_43 ,
L_7 , V_1 ) ;
if ( F_118 ( V_225 ) )
return F_229 ( F_230 ( V_225 ) ) ;
F_119 ( V_225 , V_1 ) ;
case V_230 :
F_32 ( V_43 -> V_231 ) ;
V_227 = F_111 ( V_43 , false ) ;
if ( ! V_227 ) {
if ( V_225 )
F_124 ( V_225 ) ;
return V_232 ;
}
}
F_78 ( & V_43 -> V_81 , V_10 ) ;
switch ( V_223 ) {
case V_229 :
F_32 ( V_43 -> V_138 || V_43 -> V_114 != V_115 ) ;
V_43 -> V_138 = V_225 ;
V_43 -> V_114 = V_233 ;
F_55 ( V_43 -> V_138 ) ;
F_227 ( V_43 , V_218 ) ;
case V_230 :
F_32 ( V_43 -> V_231 ) ;
V_43 -> V_231 = V_227 ;
break;
case V_234 :
V_43 -> V_10 |= V_235 ;
break;
case V_236 :
V_43 -> V_114 = V_237 ;
case V_238 :
F_123 ( V_43 -> V_231 ) ;
V_43 -> V_231 = NULL ;
break;
case V_239 :
case V_240 :
V_43 -> V_10 &= ~ V_235 ;
if ( V_43 -> V_114 != V_115 ) {
V_43 -> V_114 = V_241 ;
F_55 ( V_43 -> V_138 ) ;
F_227 ( V_43 , V_115 ) ;
}
F_106 ( & V_43 -> V_81 ) ;
F_119 ( V_43 -> V_231 -> V_57 , V_1 ) ;
F_112 ( & V_43 -> V_81 ) ;
V_43 -> V_10 |= V_48 ;
F_122 ( V_43 -> V_231 ) ;
V_43 -> V_231 = NULL ;
break;
}
F_80 ( & V_43 -> V_81 , V_10 ) ;
return F_229 ( 0 ) ;
}
static int F_231 ( void * V_242 )
{
struct V_243 * V_244 = V_242 ;
V_244 -> V_93 = V_244 -> V_191 ( V_244 -> V_245 ) ;
F_140 ( & V_244 -> V_246 ) ;
return 0 ;
}
long F_232 ( unsigned int V_1 , long (* V_191)( void * ) , void * V_245 )
{
struct V_58 * V_247 ;
struct V_243 V_244 = {
. V_246 = F_162 ( V_244 . V_246 ) ,
. V_191 = V_191 ,
. V_245 = V_245 ,
} ;
V_247 = F_117 ( F_231 , & V_244 , L_8 ) ;
if ( F_118 ( V_247 ) )
return F_230 ( V_247 ) ;
F_119 ( V_247 , V_1 ) ;
F_55 ( V_247 ) ;
F_167 ( & V_244 . V_246 ) ;
return V_244 . V_93 ;
}
void F_233 ( void )
{
unsigned int V_1 ;
F_170 ( & V_178 ) ;
F_32 ( V_211 ) ;
V_211 = true ;
F_77 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_8 * V_9 ;
F_112 ( & V_43 -> V_81 ) ;
F_32 ( V_43 -> V_10 & V_214 ) ;
V_43 -> V_10 |= V_214 ;
F_71 (wq, &workqueues, list) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
if ( V_36 && V_9 -> V_10 & V_212 )
V_36 -> V_90 = 0 ;
}
F_106 ( & V_43 -> V_81 ) ;
}
F_171 ( & V_178 ) ;
}
bool F_234 ( void )
{
unsigned int V_1 ;
bool V_248 = false ;
F_170 ( & V_178 ) ;
F_32 ( ! V_211 ) ;
F_77 (cpu) {
struct V_8 * V_9 ;
F_71 (wq, &workqueues, list) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
if ( ! V_36 || ! ( V_9 -> V_10 & V_212 ) )
continue;
F_32 ( V_36 -> V_89 < 0 ) ;
if ( V_36 -> V_89 ) {
V_248 = true ;
goto V_175;
}
}
}
V_175:
F_171 ( & V_178 ) ;
return V_248 ;
}
void F_235 ( void )
{
unsigned int V_1 ;
F_170 ( & V_178 ) ;
if ( ! V_211 )
goto V_175;
F_77 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_8 * V_9 ;
F_112 ( & V_43 -> V_81 ) ;
F_32 ( ! ( V_43 -> V_10 & V_214 ) ) ;
V_43 -> V_10 &= ~ V_214 ;
F_71 (wq, &workqueues, list) {
struct V_27 * V_36 = F_25 ( V_1 , V_9 ) ;
if ( ! V_36 || ! ( V_9 -> V_10 & V_212 ) )
continue;
V_36 -> V_90 = V_9 -> V_185 ;
while ( ! F_45 ( & V_36 -> V_92 ) &&
V_36 -> V_89 < V_36 -> V_90 )
F_137 ( V_36 ) ;
}
F_54 ( V_43 ) ;
F_106 ( & V_43 -> V_81 ) ;
}
V_211 = false ;
V_175:
F_171 ( & V_178 ) ;
}
static int T_8 F_236 ( void )
{
unsigned int V_1 ;
int V_80 ;
F_237 ( F_228 , V_249 ) ;
F_77 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
F_238 ( & V_43 -> V_81 ) ;
F_109 ( & V_43 -> V_45 ) ;
V_43 -> V_1 = V_1 ;
V_43 -> V_10 |= V_235 ;
F_109 ( & V_43 -> V_55 ) ;
for ( V_80 = 0 ; V_80 < V_250 ; V_80 ++ )
F_239 ( & V_43 -> V_69 [ V_80 ] ) ;
F_240 ( & V_43 -> V_111 ) ;
V_43 -> V_111 . V_104 = F_125 ;
V_43 -> V_111 . V_35 = ( unsigned long ) V_43 ;
F_241 ( & V_43 -> V_136 , F_130 ,
( unsigned long ) V_43 ) ;
F_242 ( & V_43 -> V_124 ) ;
V_43 -> V_114 = V_115 ;
F_243 ( & V_43 -> V_113 ) ;
}
F_244 (cpu) {
struct V_23 * V_43 = F_22 ( V_1 ) ;
struct V_54 * V_54 ;
if ( V_1 != V_6 )
V_43 -> V_10 &= ~ V_235 ;
V_54 = F_111 ( V_43 , true ) ;
F_32 ( ! V_54 ) ;
F_112 ( & V_43 -> V_81 ) ;
F_122 ( V_54 ) ;
F_106 ( & V_43 -> V_81 ) ;
}
V_188 = F_245 ( L_9 , 0 , 0 ) ;
V_251 = F_245 ( L_10 , 0 , 0 ) ;
V_252 = F_245 ( L_11 , V_86 , 0 ) ;
V_253 = F_245 ( L_12 , V_11 ,
V_198 ) ;
V_254 = F_245 ( L_13 ,
V_212 , 0 ) ;
V_255 = F_245 ( L_14 ,
V_86 | V_212 , 0 ) ;
F_32 ( ! V_188 || ! V_251 || ! V_252 ||
! V_253 || ! V_254 ||
! V_255 ) ;
return 0 ;
}
