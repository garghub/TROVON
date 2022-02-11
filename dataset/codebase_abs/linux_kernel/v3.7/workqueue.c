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
static int F_22 ( struct V_23 * V_24 )
{
return V_24 - V_24 -> V_25 -> V_26 ;
}
static struct V_27 * F_23 ( unsigned int V_1 )
{
if ( V_1 != V_6 )
return & F_24 ( V_27 , V_1 ) ;
else
return & V_28 ;
}
static T_1 * F_25 ( struct V_23 * V_24 )
{
int V_1 = V_24 -> V_25 -> V_1 ;
int V_29 = F_22 ( V_24 ) ;
if ( V_1 != V_6 )
return & F_24 ( V_30 , V_1 ) [ V_29 ] ;
else
return & V_31 [ V_29 ] ;
}
static struct V_32 * F_26 ( unsigned int V_1 ,
struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_10 & V_11 ) ) {
if ( F_27 ( V_1 < V_5 ) )
return F_28 ( V_9 -> V_33 . V_34 , V_1 ) ;
} else if ( F_27 ( V_1 == V_6 ) )
return V_9 -> V_33 . V_35 ;
return NULL ;
}
static unsigned int F_29 ( int V_36 )
{
return V_36 << V_37 ;
}
static int F_30 ( struct V_13 * V_17 )
{
return ( * F_10 ( V_17 ) >> V_37 ) &
( ( 1 << V_38 ) - 1 ) ;
}
static int F_31 ( int V_36 )
{
return ( V_36 + 1 ) % V_39 ;
}
static inline void F_32 ( struct V_13 * V_17 , unsigned long V_40 ,
unsigned long V_10 )
{
F_33 ( ! F_34 ( V_17 ) ) ;
F_35 ( & V_17 -> V_40 , V_40 | V_10 | F_36 ( V_17 ) ) ;
}
static void F_37 ( struct V_13 * V_17 ,
struct V_32 * V_41 ,
unsigned long V_42 )
{
F_32 ( V_17 , ( unsigned long ) V_41 ,
V_43 | V_44 | V_42 ) ;
}
static void F_38 ( struct V_13 * V_17 ,
unsigned int V_1 )
{
F_39 () ;
F_32 ( V_17 , ( unsigned long ) V_1 << V_45 , 0 ) ;
}
static void F_40 ( struct V_13 * V_17 )
{
F_39 () ;
F_32 ( V_17 , V_46 , 0 ) ;
}
static struct V_32 * F_41 ( struct V_13 * V_17 )
{
unsigned long V_40 = F_42 ( & V_17 -> V_40 ) ;
if ( V_40 & V_44 )
return ( void * ) ( V_40 & V_47 ) ;
else
return NULL ;
}
static struct V_27 * F_43 ( struct V_13 * V_17 )
{
unsigned long V_40 = F_42 ( & V_17 -> V_40 ) ;
unsigned int V_1 ;
if ( V_40 & V_44 )
return ( (struct V_32 * )
( V_40 & V_47 ) ) -> V_24 -> V_25 ;
V_1 = V_40 >> V_45 ;
if ( V_1 == V_7 )
return NULL ;
F_33 ( V_1 >= V_5 && V_1 != V_6 ) ;
return F_23 ( V_1 ) ;
}
static void F_44 ( struct V_13 * V_17 )
{
struct V_27 * V_25 = F_43 ( V_17 ) ;
unsigned long V_1 = V_25 ? V_25 -> V_1 : V_7 ;
F_32 ( V_17 , ( V_1 << V_45 ) | V_48 ,
V_43 ) ;
}
static bool F_45 ( struct V_13 * V_17 )
{
unsigned long V_40 = F_42 ( & V_17 -> V_40 ) ;
return ! ( V_40 & V_44 ) && ( V_40 & V_48 ) ;
}
static bool F_46 ( struct V_23 * V_24 )
{
return ! F_47 ( F_25 ( V_24 ) ) ;
}
static bool F_48 ( struct V_23 * V_24 )
{
return ! F_49 ( & V_24 -> V_49 ) && F_46 ( V_24 ) ;
}
static bool F_50 ( struct V_23 * V_24 )
{
return V_24 -> V_50 ;
}
static bool F_51 ( struct V_23 * V_24 )
{
T_1 * V_51 = F_25 ( V_24 ) ;
return ! F_49 ( & V_24 -> V_49 ) && F_47 ( V_51 ) <= 1 ;
}
static bool F_52 ( struct V_23 * V_24 )
{
return F_48 ( V_24 ) && ! F_50 ( V_24 ) ;
}
static bool F_53 ( struct V_23 * V_24 )
{
return F_52 ( V_24 ) ||
( V_24 -> V_10 & V_52 ) ;
}
static bool F_54 ( struct V_23 * V_24 )
{
bool V_53 = V_24 -> V_10 & V_54 ;
int V_50 = V_24 -> V_50 + V_53 ;
int V_55 = V_24 -> V_56 - V_50 ;
if ( F_49 ( & V_24 -> V_57 ) )
return false ;
return V_50 > 2 && ( V_50 - 2 ) * V_58 >= V_55 ;
}
static struct V_59 * F_55 ( struct V_23 * V_24 )
{
if ( F_56 ( F_49 ( & V_24 -> V_57 ) ) )
return NULL ;
return F_57 ( & V_24 -> V_57 , struct V_59 , V_60 ) ;
}
static void F_58 ( struct V_23 * V_24 )
{
struct V_59 * V_59 = F_55 ( V_24 ) ;
if ( F_27 ( V_59 ) )
F_59 ( V_59 -> V_61 ) ;
}
void F_60 ( struct V_62 * V_61 , unsigned int V_1 )
{
struct V_59 * V_59 = F_61 ( V_61 ) ;
if ( ! ( V_59 -> V_10 & V_63 ) )
F_62 ( F_25 ( V_59 -> V_24 ) ) ;
}
struct V_62 * F_63 ( struct V_62 * V_61 ,
unsigned int V_1 )
{
struct V_59 * V_59 = F_61 ( V_61 ) , * V_64 = NULL ;
struct V_23 * V_24 = V_59 -> V_24 ;
T_1 * V_51 = F_25 ( V_24 ) ;
if ( V_59 -> V_10 & V_63 )
return NULL ;
F_33 ( V_1 != F_64 () ) ;
if ( F_65 ( V_51 ) && ! F_49 ( & V_24 -> V_49 ) )
V_64 = F_55 ( V_24 ) ;
return V_64 ? V_64 -> V_61 : NULL ;
}
static inline void F_66 ( struct V_59 * V_59 , unsigned int V_10 ,
bool V_65 )
{
struct V_23 * V_24 = V_59 -> V_24 ;
F_12 ( V_59 -> V_61 != V_66 ) ;
if ( ( V_10 & V_63 ) &&
! ( V_59 -> V_10 & V_63 ) ) {
T_1 * V_51 = F_25 ( V_24 ) ;
if ( V_65 ) {
if ( F_65 ( V_51 ) &&
! F_49 ( & V_24 -> V_49 ) )
F_58 ( V_24 ) ;
} else
F_67 ( V_51 ) ;
}
V_59 -> V_10 |= V_10 ;
}
static inline void F_68 ( struct V_59 * V_59 , unsigned int V_10 )
{
struct V_23 * V_24 = V_59 -> V_24 ;
unsigned int V_67 = V_59 -> V_10 ;
F_12 ( V_59 -> V_61 != V_66 ) ;
V_59 -> V_10 &= ~ V_10 ;
if ( ( V_10 & V_63 ) && ( V_67 & V_63 ) )
if ( ! ( V_59 -> V_10 & V_63 ) )
F_62 ( F_25 ( V_24 ) ) ;
}
static struct V_68 * F_69 ( struct V_27 * V_25 ,
struct V_13 * V_17 )
{
const int V_69 = F_70 ( sizeof( struct V_13 ) ) ;
unsigned long V_70 = ( unsigned long ) V_17 ;
V_70 >>= V_69 ;
V_70 += V_70 >> V_71 ;
V_70 &= V_72 ;
return & V_25 -> V_73 [ V_70 ] ;
}
static struct V_59 * F_71 ( struct V_27 * V_25 ,
struct V_68 * V_74 ,
struct V_13 * V_17 )
{
struct V_59 * V_59 ;
struct V_75 * V_76 ;
F_72 (worker, tmp, bwh, hentry)
if ( V_59 -> V_77 == V_17 )
return V_59 ;
return NULL ;
}
static struct V_59 * F_73 ( struct V_27 * V_25 ,
struct V_13 * V_17 )
{
return F_71 ( V_25 , F_69 ( V_25 , V_17 ) ,
V_17 ) ;
}
static void F_74 ( struct V_13 * V_17 , struct V_78 * V_79 ,
struct V_13 * * V_80 )
{
struct V_13 * V_81 ;
F_75 (work, n, NULL, entry) {
F_76 ( & V_17 -> V_60 , V_79 ) ;
if ( ! ( * F_10 ( V_17 ) & V_82 ) )
break;
}
if ( V_80 )
* V_80 = V_81 ;
}
static void F_77 ( struct V_13 * V_17 )
{
struct V_32 * V_41 = F_41 ( V_17 ) ;
F_78 ( V_17 ) ;
F_74 ( V_17 , & V_41 -> V_24 -> V_49 , NULL ) ;
F_79 ( V_83 , F_10 ( V_17 ) ) ;
V_41 -> V_84 ++ ;
}
static void F_80 ( struct V_32 * V_41 )
{
struct V_13 * V_17 = F_57 ( & V_41 -> V_85 ,
struct V_13 , V_60 ) ;
F_77 ( V_17 ) ;
}
static void F_81 ( struct V_32 * V_41 , int V_36 )
{
if ( V_36 == V_86 )
return;
V_41 -> V_87 [ V_36 ] -- ;
V_41 -> V_84 -- ;
if ( ! F_49 ( & V_41 -> V_85 ) ) {
if ( V_41 -> V_84 < V_41 -> V_88 )
F_80 ( V_41 ) ;
}
if ( F_27 ( V_41 -> V_89 != V_36 ) )
return;
if ( V_41 -> V_87 [ V_36 ] )
return;
V_41 -> V_89 = - 1 ;
if ( F_65 ( & V_41 -> V_9 -> V_90 ) )
F_82 ( & V_41 -> V_9 -> V_91 -> V_92 ) ;
}
static int F_83 ( struct V_13 * V_17 , bool V_93 ,
unsigned long * V_10 )
{
struct V_27 * V_25 ;
F_84 ( * V_10 ) ;
if ( V_93 ) {
struct V_94 * V_95 = F_85 ( V_17 ) ;
if ( F_27 ( F_86 ( & V_95 -> V_96 ) ) )
return 1 ;
}
if ( ! F_87 ( V_97 , F_10 ( V_17 ) ) )
return 0 ;
V_25 = F_43 ( V_17 ) ;
if ( ! V_25 )
goto V_98;
F_88 ( & V_25 -> V_99 ) ;
if ( ! F_49 ( & V_17 -> V_60 ) ) {
F_89 () ;
if ( V_25 == F_43 ( V_17 ) ) {
F_17 ( V_17 ) ;
if ( * F_10 ( V_17 ) & V_100 )
F_77 ( V_17 ) ;
F_90 ( & V_17 -> V_60 ) ;
F_81 ( F_41 ( V_17 ) ,
F_30 ( V_17 ) ) ;
F_91 ( & V_25 -> V_99 ) ;
return 1 ;
}
}
F_91 ( & V_25 -> V_99 ) ;
V_98:
F_92 ( * V_10 ) ;
if ( F_45 ( V_17 ) )
return - V_101 ;
F_93 () ;
return - V_102 ;
}
static void F_94 ( struct V_32 * V_41 ,
struct V_13 * V_17 , struct V_78 * V_79 ,
unsigned int V_42 )
{
struct V_23 * V_24 = V_41 -> V_24 ;
F_37 ( V_17 , V_41 , V_42 ) ;
F_39 () ;
F_95 ( & V_17 -> V_60 , V_79 ) ;
F_96 () ;
if ( F_46 ( V_24 ) )
F_58 ( V_24 ) ;
}
static bool F_97 ( struct V_8 * V_9 )
{
unsigned long V_10 ;
unsigned int V_1 ;
F_98 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_59 * V_59 ;
struct V_75 * V_103 ;
int V_104 ;
F_99 ( & V_25 -> V_99 , V_10 ) ;
F_100 (worker, i, pos, gcwq) {
if ( V_59 -> V_61 != V_66 )
continue;
F_101 ( & V_25 -> V_99 , V_10 ) ;
return V_59 -> V_105 -> V_9 == V_9 ;
}
F_101 ( & V_25 -> V_99 , V_10 ) ;
}
return false ;
}
static void F_102 ( unsigned int V_1 , struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_27 * V_25 ;
struct V_32 * V_41 ;
struct V_78 * V_49 ;
unsigned int V_106 ;
unsigned int V_107 = V_1 ;
F_12 ( ! F_103 () ) ;
F_16 ( V_17 ) ;
if ( F_56 ( V_9 -> V_10 & V_108 ) &&
F_12 ( ! F_97 ( V_9 ) ) )
return;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_27 * V_109 ;
if ( V_1 == V_6 )
V_1 = F_64 () ;
V_25 = F_23 ( V_1 ) ;
V_109 = F_43 ( V_17 ) ;
if ( V_109 && V_109 != V_25 ) {
struct V_59 * V_59 ;
F_88 ( & V_109 -> V_99 ) ;
V_59 = F_73 ( V_109 , V_17 ) ;
if ( V_59 && V_59 -> V_105 -> V_9 == V_9 )
V_25 = V_109 ;
else {
F_91 ( & V_109 -> V_99 ) ;
F_88 ( & V_25 -> V_99 ) ;
}
} else {
F_88 ( & V_25 -> V_99 ) ;
}
} else {
V_25 = F_23 ( V_6 ) ;
F_88 ( & V_25 -> V_99 ) ;
}
V_41 = F_26 ( V_25 -> V_1 , V_9 ) ;
F_104 ( V_107 , V_41 , V_17 ) ;
if ( F_13 ( ! F_49 ( & V_17 -> V_60 ) ) ) {
F_91 ( & V_25 -> V_99 ) ;
return;
}
V_41 -> V_87 [ V_41 -> V_110 ] ++ ;
V_106 = F_29 ( V_41 -> V_110 ) ;
if ( F_27 ( V_41 -> V_84 < V_41 -> V_88 ) ) {
F_78 ( V_17 ) ;
V_41 -> V_84 ++ ;
V_49 = & V_41 -> V_24 -> V_49 ;
} else {
V_106 |= V_100 ;
V_49 = & V_41 -> V_85 ;
}
F_94 ( V_41 , V_17 , V_49 , V_106 ) ;
F_91 ( & V_25 -> V_99 ) ;
}
bool F_105 ( int V_1 , struct V_8 * V_9 ,
struct V_13 * V_17 )
{
bool V_111 = false ;
unsigned long V_10 ;
F_84 ( V_10 ) ;
if ( ! F_87 ( V_97 , F_10 ( V_17 ) ) ) {
F_102 ( V_1 , V_9 , V_17 ) ;
V_111 = true ;
}
F_92 ( V_10 ) ;
return V_111 ;
}
bool F_106 ( struct V_8 * V_9 , struct V_13 * V_17 )
{
return F_105 ( V_6 , V_9 , V_17 ) ;
}
void F_107 ( unsigned long V_112 )
{
struct V_94 * V_95 = (struct V_94 * ) V_112 ;
struct V_32 * V_41 = F_41 ( & V_95 -> V_17 ) ;
F_102 ( V_95 -> V_1 , V_41 -> V_9 , & V_95 -> V_17 ) ;
}
static void F_108 ( int V_1 , struct V_8 * V_9 ,
struct V_94 * V_95 , unsigned long V_113 )
{
struct V_114 * V_96 = & V_95 -> V_96 ;
struct V_13 * V_17 = & V_95 -> V_17 ;
unsigned int V_115 ;
F_12 ( V_96 -> V_116 != F_107 ||
V_96 -> V_40 != ( unsigned long ) V_95 ) ;
F_12 ( F_109 ( V_96 ) ) ;
F_12 ( ! F_49 ( & V_17 -> V_60 ) ) ;
if ( ! V_113 ) {
F_102 ( V_1 , V_9 , & V_95 -> V_17 ) ;
return;
}
F_110 ( & V_95 -> V_96 ) ;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_27 * V_25 = F_43 ( V_17 ) ;
V_115 = V_1 ;
if ( V_25 )
V_115 = V_25 -> V_1 ;
if ( V_115 == V_6 )
V_115 = F_64 () ;
} else {
V_115 = V_6 ;
}
F_37 ( V_17 , F_26 ( V_115 , V_9 ) , 0 ) ;
V_95 -> V_1 = V_1 ;
V_96 -> V_117 = V_118 + V_113 ;
if ( F_56 ( V_1 != V_6 ) )
F_111 ( V_96 , V_1 ) ;
else
F_112 ( V_96 ) ;
}
bool F_113 ( int V_1 , struct V_8 * V_9 ,
struct V_94 * V_95 , unsigned long V_113 )
{
struct V_13 * V_17 = & V_95 -> V_17 ;
bool V_111 = false ;
unsigned long V_10 ;
F_84 ( V_10 ) ;
if ( ! F_87 ( V_97 , F_10 ( V_17 ) ) ) {
F_108 ( V_1 , V_9 , V_95 , V_113 ) ;
V_111 = true ;
}
F_92 ( V_10 ) ;
return V_111 ;
}
bool F_114 ( struct V_8 * V_9 ,
struct V_94 * V_95 , unsigned long V_113 )
{
return F_113 ( V_6 , V_9 , V_95 , V_113 ) ;
}
bool F_115 ( int V_1 , struct V_8 * V_9 ,
struct V_94 * V_95 , unsigned long V_113 )
{
unsigned long V_10 ;
int V_111 ;
do {
V_111 = F_83 ( & V_95 -> V_17 , true , & V_10 ) ;
} while ( F_56 ( V_111 == - V_102 ) );
if ( F_27 ( V_111 >= 0 ) ) {
F_108 ( V_1 , V_9 , V_95 , V_113 ) ;
F_92 ( V_10 ) ;
}
return V_111 ;
}
bool F_116 ( struct V_8 * V_9 , struct V_94 * V_95 ,
unsigned long V_113 )
{
return F_115 ( V_6 , V_9 , V_95 , V_113 ) ;
}
static void F_117 ( struct V_59 * V_59 )
{
struct V_23 * V_24 = V_59 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
F_33 ( V_59 -> V_10 & V_119 ) ;
F_33 ( ! F_49 ( & V_59 -> V_60 ) &&
( V_59 -> V_120 . V_121 || V_59 -> V_120 . V_122 ) ) ;
V_59 -> V_10 |= V_119 ;
V_24 -> V_50 ++ ;
V_59 -> V_123 = V_118 ;
F_118 ( & V_59 -> V_60 , & V_24 -> V_57 ) ;
if ( F_54 ( V_24 ) && ! F_109 ( & V_24 -> V_124 ) )
F_119 ( & V_24 -> V_124 , V_118 + V_125 ) ;
F_12 ( ! ( V_25 -> V_10 & V_126 ) &&
V_24 -> V_56 == V_24 -> V_50 &&
F_47 ( F_25 ( V_24 ) ) ) ;
}
static void F_120 ( struct V_59 * V_59 )
{
struct V_23 * V_24 = V_59 -> V_24 ;
F_33 ( ! ( V_59 -> V_10 & V_119 ) ) ;
F_68 ( V_59 , V_119 ) ;
V_24 -> V_50 -- ;
F_90 ( & V_59 -> V_60 ) ;
}
static bool F_121 ( struct V_59 * V_59 )
__acquires( &gcwq->lock
static void F_122 ( struct V_59 * V_59 )
{
struct V_27 * V_25 = V_59 -> V_24 -> V_25 ;
if ( F_121 ( V_59 ) )
F_68 ( V_59 , V_127 ) ;
F_118 ( & V_59 -> V_60 , & V_59 -> V_24 -> V_57 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
static void F_124 ( struct V_13 * V_17 )
{
struct V_59 * V_59 = F_125 ( V_17 , struct V_59 , V_128 ) ;
struct V_27 * V_25 = V_59 -> V_24 -> V_25 ;
if ( F_121 ( V_59 ) )
F_68 ( V_59 , V_127 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
static void F_126 ( struct V_27 * V_25 )
{
struct V_23 * V_24 ;
struct V_59 * V_59 , * V_81 ;
struct V_75 * V_103 ;
int V_104 ;
F_127 ( & V_25 -> V_99 ) ;
F_128 (pool, gcwq)
F_127 ( & V_24 -> V_129 ) ;
F_128 (pool, gcwq) {
F_129 (worker, n, &pool->idle_list, entry) {
F_90 ( & V_59 -> V_60 ) ;
F_59 ( V_59 -> V_61 ) ;
}
}
F_100 (worker, i, pos, gcwq) {
struct V_13 * V_128 = & V_59 -> V_128 ;
struct V_8 * V_9 ;
if ( F_87 ( V_97 ,
F_10 ( V_128 ) ) )
continue;
F_16 ( V_128 ) ;
if ( F_22 ( V_59 -> V_24 ) )
V_9 = V_130 ;
else
V_9 = V_131 ;
F_94 ( F_26 ( V_25 -> V_1 , V_9 ) , V_128 ,
V_59 -> V_132 . V_121 ,
F_29 ( V_86 ) ) ;
}
}
static struct V_59 * F_130 ( void )
{
struct V_59 * V_59 ;
V_59 = F_131 ( sizeof( * V_59 ) , V_133 ) ;
if ( V_59 ) {
F_132 ( & V_59 -> V_60 ) ;
F_132 ( & V_59 -> V_132 ) ;
F_133 ( & V_59 -> V_128 , F_124 ) ;
V_59 -> V_10 = V_134 ;
}
return V_59 ;
}
static struct V_59 * F_134 ( struct V_23 * V_24 )
{
struct V_27 * V_25 = V_24 -> V_25 ;
const char * V_135 = F_22 ( V_24 ) ? L_1 : L_2 ;
struct V_59 * V_59 = NULL ;
int V_136 = - 1 ;
F_135 ( & V_25 -> V_99 ) ;
while ( F_136 ( & V_24 -> V_137 , & V_136 ) ) {
F_123 ( & V_25 -> V_99 ) ;
if ( ! F_137 ( & V_24 -> V_137 , V_133 ) )
goto V_98;
F_135 ( & V_25 -> V_99 ) ;
}
F_123 ( & V_25 -> V_99 ) ;
V_59 = F_130 () ;
if ( ! V_59 )
goto V_98;
V_59 -> V_24 = V_24 ;
V_59 -> V_136 = V_136 ;
if ( V_25 -> V_1 != V_6 )
V_59 -> V_61 = F_138 ( V_138 ,
V_59 , F_139 ( V_25 -> V_1 ) ,
L_3 , V_25 -> V_1 , V_136 , V_135 ) ;
else
V_59 -> V_61 = F_140 ( V_138 , V_59 ,
L_4 , V_136 , V_135 ) ;
if ( F_141 ( V_59 -> V_61 ) )
goto V_98;
if ( F_22 ( V_24 ) )
F_142 ( V_59 -> V_61 , V_139 ) ;
if ( ! ( V_25 -> V_10 & V_126 ) ) {
F_143 ( V_59 -> V_61 , V_25 -> V_1 ) ;
} else {
V_59 -> V_61 -> V_10 |= V_140 ;
V_59 -> V_10 |= V_127 ;
}
return V_59 ;
V_98:
if ( V_136 >= 0 ) {
F_135 ( & V_25 -> V_99 ) ;
F_144 ( & V_24 -> V_137 , V_136 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
F_145 ( V_59 ) ;
return NULL ;
}
static void F_146 ( struct V_59 * V_59 )
{
V_59 -> V_10 |= V_141 ;
V_59 -> V_24 -> V_56 ++ ;
F_117 ( V_59 ) ;
F_59 ( V_59 -> V_61 ) ;
}
static void F_147 ( struct V_59 * V_59 )
{
struct V_23 * V_24 = V_59 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
int V_136 = V_59 -> V_136 ;
F_33 ( V_59 -> V_77 ) ;
F_33 ( ! F_49 ( & V_59 -> V_132 ) ) ;
if ( V_59 -> V_10 & V_141 )
V_24 -> V_56 -- ;
if ( V_59 -> V_10 & V_119 )
V_24 -> V_50 -- ;
F_90 ( & V_59 -> V_60 ) ;
V_59 -> V_10 |= V_142 ;
F_123 ( & V_25 -> V_99 ) ;
F_148 ( V_59 -> V_61 ) ;
F_145 ( V_59 ) ;
F_135 ( & V_25 -> V_99 ) ;
F_144 ( & V_24 -> V_137 , V_136 ) ;
}
static void F_149 ( unsigned long V_143 )
{
struct V_23 * V_24 = ( void * ) V_143 ;
struct V_27 * V_25 = V_24 -> V_25 ;
F_135 ( & V_25 -> V_99 ) ;
if ( F_54 ( V_24 ) ) {
struct V_59 * V_59 ;
unsigned long V_117 ;
V_59 = F_150 ( V_24 -> V_57 . V_144 , struct V_59 , V_60 ) ;
V_117 = V_59 -> V_123 + V_125 ;
if ( F_151 ( V_118 , V_117 ) )
F_119 ( & V_24 -> V_124 , V_117 ) ;
else {
V_24 -> V_10 |= V_52 ;
F_58 ( V_24 ) ;
}
}
F_123 ( & V_25 -> V_99 ) ;
}
static bool F_152 ( struct V_13 * V_17 )
{
struct V_32 * V_41 = F_41 ( V_17 ) ;
struct V_8 * V_9 = V_41 -> V_9 ;
unsigned int V_1 ;
if ( ! ( V_9 -> V_10 & V_145 ) )
return false ;
V_1 = V_41 -> V_24 -> V_25 -> V_1 ;
if ( V_1 == V_6 )
V_1 = 0 ;
if ( ! F_153 ( V_1 , V_9 -> V_146 ) )
F_59 ( V_9 -> V_147 -> V_61 ) ;
return true ;
}
static void F_154 ( unsigned long V_143 )
{
struct V_23 * V_24 = ( void * ) V_143 ;
struct V_27 * V_25 = V_24 -> V_25 ;
struct V_13 * V_17 ;
F_135 ( & V_25 -> V_99 ) ;
if ( F_52 ( V_24 ) ) {
F_155 (work, &pool->worklist, entry)
F_152 ( V_17 ) ;
}
F_123 ( & V_25 -> V_99 ) ;
F_119 ( & V_24 -> V_148 , V_118 + V_149 ) ;
}
static bool F_156 ( struct V_23 * V_24 )
__releases( &gcwq->lock
static bool F_157 ( struct V_23 * V_24 )
{
bool V_111 = false ;
while ( F_54 ( V_24 ) ) {
struct V_59 * V_59 ;
unsigned long V_117 ;
V_59 = F_150 ( V_24 -> V_57 . V_144 , struct V_59 , V_60 ) ;
V_117 = V_59 -> V_123 + V_125 ;
if ( F_151 ( V_118 , V_117 ) ) {
F_119 ( & V_24 -> V_124 , V_117 ) ;
break;
}
F_147 ( V_59 ) ;
V_111 = true ;
}
return V_111 ;
}
static bool F_158 ( struct V_59 * V_59 )
{
struct V_23 * V_24 = V_59 -> V_24 ;
bool V_111 = false ;
if ( V_24 -> V_10 & V_54 )
return V_111 ;
V_24 -> V_10 |= V_54 ;
if ( F_56 ( ! F_159 ( & V_24 -> V_129 ) ) ) {
F_123 ( & V_24 -> V_25 -> V_99 ) ;
F_160 ( & V_24 -> V_129 ) ;
if ( F_121 ( V_59 ) )
V_59 -> V_10 &= ~ V_127 ;
else
V_59 -> V_10 |= V_127 ;
V_111 = true ;
}
V_24 -> V_10 &= ~ V_52 ;
V_111 |= F_157 ( V_24 ) ;
V_111 |= F_156 ( V_24 ) ;
V_24 -> V_10 &= ~ V_54 ;
F_161 ( & V_24 -> V_129 ) ;
return V_111 ;
}
static void F_162 ( struct V_59 * V_59 , struct V_13 * V_17 )
__releases( &gcwq->lock
static void F_163 ( struct V_59 * V_59 )
{
while ( ! F_49 ( & V_59 -> V_132 ) ) {
struct V_13 * V_17 = F_57 ( & V_59 -> V_132 ,
struct V_13 , V_60 ) ;
F_162 ( V_59 , V_17 ) ;
}
}
static int V_138 ( void * V_150 )
{
struct V_59 * V_59 = V_150 ;
struct V_23 * V_24 = V_59 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
V_59 -> V_61 -> V_10 |= V_151 ;
V_152:
F_135 ( & V_25 -> V_99 ) ;
if ( F_56 ( F_49 ( & V_59 -> V_60 ) ) ) {
F_123 ( & V_25 -> V_99 ) ;
if ( V_59 -> V_10 & V_142 ) {
V_59 -> V_61 -> V_10 &= ~ V_151 ;
return 0 ;
}
F_122 ( V_59 ) ;
goto V_152;
}
F_120 ( V_59 ) ;
V_153:
if ( ! F_48 ( V_24 ) )
goto V_154;
if ( F_56 ( ! F_50 ( V_24 ) ) && F_158 ( V_59 ) )
goto V_153;
F_33 ( ! F_49 ( & V_59 -> V_132 ) ) ;
F_68 ( V_59 , V_134 ) ;
do {
struct V_13 * V_17 =
F_57 ( & V_24 -> V_49 ,
struct V_13 , V_60 ) ;
if ( F_27 ( ! ( * F_10 ( V_17 ) & V_82 ) ) ) {
F_162 ( V_59 , V_17 ) ;
if ( F_56 ( ! F_49 ( & V_59 -> V_132 ) ) )
F_163 ( V_59 ) ;
} else {
F_74 ( V_17 , & V_59 -> V_132 , NULL ) ;
F_163 ( V_59 ) ;
}
} while ( F_51 ( V_24 ) );
F_66 ( V_59 , V_134 , false ) ;
V_154:
if ( F_56 ( F_53 ( V_24 ) ) && F_158 ( V_59 ) )
goto V_153;
F_117 ( V_59 ) ;
F_164 ( V_155 ) ;
F_123 ( & V_25 -> V_99 ) ;
F_165 () ;
goto V_152;
}
static int F_166 ( void * V_156 )
{
struct V_8 * V_9 = V_156 ;
struct V_59 * V_147 = V_9 -> V_147 ;
struct V_78 * V_132 = & V_147 -> V_132 ;
bool V_157 = V_9 -> V_10 & V_11 ;
unsigned int V_1 ;
F_142 ( V_66 , V_158 ) ;
V_159:
F_167 ( V_155 ) ;
if ( F_168 () ) {
F_164 ( V_160 ) ;
return 0 ;
}
F_169 (cpu, wq->mayday_mask) {
unsigned int V_161 = V_157 ? V_6 : V_1 ;
struct V_32 * V_41 = F_26 ( V_161 , V_9 ) ;
struct V_23 * V_24 = V_41 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
struct V_13 * V_17 , * V_81 ;
F_164 ( V_160 ) ;
F_170 ( V_1 , V_9 -> V_146 ) ;
V_147 -> V_24 = V_24 ;
F_121 ( V_147 ) ;
F_33 ( ! F_49 ( & V_147 -> V_132 ) ) ;
F_129 (work, n, &pool->worklist, entry)
if ( F_41 ( V_17 ) == V_41 )
F_74 ( V_17 , V_132 , & V_81 ) ;
F_163 ( V_147 ) ;
if ( F_51 ( V_24 ) )
F_58 ( V_24 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
F_165 () ;
goto V_159;
}
static void F_171 ( struct V_13 * V_17 )
{
struct V_162 * V_163 = F_125 ( V_17 , struct V_162 , V_17 ) ;
F_82 ( & V_163 -> V_92 ) ;
}
static void F_172 ( struct V_32 * V_41 ,
struct V_162 * V_163 ,
struct V_13 * V_164 , struct V_59 * V_59 )
{
struct V_78 * V_79 ;
unsigned int V_165 = 0 ;
F_173 ( & V_163 -> V_17 , F_171 ) ;
F_174 ( V_97 , F_10 ( & V_163 -> V_17 ) ) ;
F_175 ( & V_163 -> V_92 ) ;
if ( V_59 )
V_79 = V_59 -> V_132 . V_121 ;
else {
unsigned long * V_166 = F_10 ( V_164 ) ;
V_79 = V_164 -> V_60 . V_121 ;
V_165 = * V_166 & V_82 ;
F_174 ( V_167 , V_166 ) ;
}
F_16 ( & V_163 -> V_17 ) ;
F_94 ( V_41 , & V_163 -> V_17 , V_79 ,
F_29 ( V_86 ) | V_165 ) ;
}
static bool F_176 ( struct V_8 * V_9 ,
int V_89 , int V_110 )
{
bool V_168 = false ;
unsigned int V_1 ;
if ( V_89 >= 0 ) {
F_33 ( F_47 ( & V_9 -> V_90 ) ) ;
F_177 ( & V_9 -> V_90 , 1 ) ;
}
F_178 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
struct V_27 * V_25 = V_41 -> V_24 -> V_25 ;
F_135 ( & V_25 -> V_99 ) ;
if ( V_89 >= 0 ) {
F_33 ( V_41 -> V_89 != - 1 ) ;
if ( V_41 -> V_87 [ V_89 ] ) {
V_41 -> V_89 = V_89 ;
F_62 ( & V_9 -> V_90 ) ;
V_168 = true ;
}
}
if ( V_110 >= 0 ) {
F_33 ( V_110 != F_31 ( V_41 -> V_110 ) ) ;
V_41 -> V_110 = V_110 ;
}
F_123 ( & V_25 -> V_99 ) ;
}
if ( V_89 >= 0 && F_65 ( & V_9 -> V_90 ) )
F_82 ( & V_9 -> V_91 -> V_92 ) ;
return V_168 ;
}
void F_179 ( struct V_8 * V_9 )
{
struct V_169 V_170 = {
. V_171 = F_180 ( V_170 . V_171 ) ,
. V_89 = - 1 ,
. V_92 = F_181 ( V_170 . V_92 ) ,
} ;
int V_172 ;
F_182 ( & V_9 -> V_173 ) ;
F_183 ( & V_9 -> V_173 ) ;
F_160 ( & V_9 -> V_174 ) ;
V_172 = F_31 ( V_9 -> V_110 ) ;
if ( V_172 != V_9 -> V_89 ) {
F_33 ( ! F_49 ( & V_9 -> V_175 ) ) ;
V_170 . V_89 = V_9 -> V_110 ;
V_9 -> V_110 = V_172 ;
if ( ! V_9 -> V_91 ) {
F_33 ( V_9 -> V_89 != V_170 . V_89 ) ;
V_9 -> V_91 = & V_170 ;
if ( ! F_176 ( V_9 , V_9 -> V_89 ,
V_9 -> V_110 ) ) {
V_9 -> V_89 = V_172 ;
V_9 -> V_91 = NULL ;
goto V_176;
}
} else {
F_33 ( V_9 -> V_89 == V_170 . V_89 ) ;
F_95 ( & V_170 . V_171 , & V_9 -> V_177 ) ;
F_176 ( V_9 , - 1 , V_9 -> V_110 ) ;
}
} else {
F_95 ( & V_170 . V_171 , & V_9 -> V_175 ) ;
}
F_161 ( & V_9 -> V_174 ) ;
F_184 ( & V_170 . V_92 ) ;
if ( V_9 -> V_91 != & V_170 )
return;
F_160 ( & V_9 -> V_174 ) ;
if ( V_9 -> V_91 != & V_170 )
goto V_176;
V_9 -> V_91 = NULL ;
F_33 ( ! F_49 ( & V_170 . V_171 ) ) ;
F_33 ( V_9 -> V_89 != V_170 . V_89 ) ;
while ( true ) {
struct V_169 * V_121 , * V_76 ;
F_129 (next, tmp, &wq->flusher_queue, list) {
if ( V_121 -> V_89 != V_9 -> V_89 )
break;
F_90 ( & V_121 -> V_171 ) ;
F_82 ( & V_121 -> V_92 ) ;
}
F_33 ( ! F_49 ( & V_9 -> V_175 ) &&
V_9 -> V_89 != F_31 ( V_9 -> V_110 ) ) ;
V_9 -> V_89 = F_31 ( V_9 -> V_89 ) ;
if ( ! F_49 ( & V_9 -> V_175 ) ) {
F_155 (tmp, &wq->flusher_overflow, list)
V_76 -> V_89 = V_9 -> V_110 ;
V_9 -> V_110 = F_31 ( V_9 -> V_110 ) ;
F_185 ( & V_9 -> V_175 ,
& V_9 -> V_177 ) ;
F_176 ( V_9 , - 1 , V_9 -> V_110 ) ;
}
if ( F_49 ( & V_9 -> V_177 ) ) {
F_33 ( V_9 -> V_89 != V_9 -> V_110 ) ;
break;
}
F_33 ( V_9 -> V_89 == V_9 -> V_110 ) ;
F_33 ( V_9 -> V_89 != V_121 -> V_89 ) ;
F_90 ( & V_121 -> V_171 ) ;
V_9 -> V_91 = V_121 ;
if ( F_176 ( V_9 , V_9 -> V_89 , - 1 ) )
break;
V_9 -> V_91 = NULL ;
}
V_176:
F_161 ( & V_9 -> V_174 ) ;
}
void F_186 ( struct V_8 * V_9 )
{
unsigned int V_178 = 0 ;
unsigned int V_1 ;
F_88 ( & V_179 ) ;
if ( ! V_9 -> V_180 ++ )
V_9 -> V_10 |= V_108 ;
F_91 ( & V_179 ) ;
V_181:
F_179 ( V_9 ) ;
F_178 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
bool V_182 ;
F_135 ( & V_41 -> V_24 -> V_25 -> V_99 ) ;
V_182 = ! V_41 -> V_84 && F_49 ( & V_41 -> V_85 ) ;
F_123 ( & V_41 -> V_24 -> V_25 -> V_99 ) ;
if ( V_182 )
continue;
if ( ++ V_178 == 10 ||
( V_178 % 100 == 0 && V_178 <= 1000 ) )
F_187 ( L_5 ,
V_9 -> V_183 , V_178 ) ;
goto V_181;
}
F_88 ( & V_179 ) ;
if ( ! -- V_9 -> V_180 )
V_9 -> V_10 &= ~ V_108 ;
F_91 ( & V_179 ) ;
}
static bool F_188 ( struct V_13 * V_17 , struct V_162 * V_163 )
{
struct V_59 * V_59 = NULL ;
struct V_27 * V_25 ;
struct V_32 * V_41 ;
F_189 () ;
V_25 = F_43 ( V_17 ) ;
if ( ! V_25 )
return false ;
F_135 ( & V_25 -> V_99 ) ;
if ( ! F_49 ( & V_17 -> V_60 ) ) {
F_89 () ;
V_41 = F_41 ( V_17 ) ;
if ( F_56 ( ! V_41 || V_25 != V_41 -> V_24 -> V_25 ) )
goto V_184;
} else {
V_59 = F_73 ( V_25 , V_17 ) ;
if ( ! V_59 )
goto V_184;
V_41 = V_59 -> V_105 ;
}
F_172 ( V_41 , V_163 , V_17 , V_59 ) ;
F_123 ( & V_25 -> V_99 ) ;
if ( V_41 -> V_9 -> V_185 == 1 || V_41 -> V_9 -> V_10 & V_145 )
F_182 ( & V_41 -> V_9 -> V_173 ) ;
else
F_190 ( & V_41 -> V_9 -> V_173 ) ;
F_183 ( & V_41 -> V_9 -> V_173 ) ;
return true ;
V_184:
F_123 ( & V_25 -> V_99 ) ;
return false ;
}
bool F_191 ( struct V_13 * V_17 )
{
struct V_162 V_163 ;
F_182 ( & V_17 -> V_173 ) ;
F_183 ( & V_17 -> V_173 ) ;
if ( F_188 ( V_17 , & V_163 ) ) {
F_184 ( & V_163 . V_92 ) ;
F_21 ( & V_163 . V_17 ) ;
return true ;
} else {
return false ;
}
}
static bool F_192 ( struct V_13 * V_17 , bool V_93 )
{
unsigned long V_10 ;
int V_111 ;
do {
V_111 = F_83 ( V_17 , V_93 , & V_10 ) ;
if ( F_56 ( V_111 == - V_101 ) )
F_191 ( V_17 ) ;
} while ( F_56 ( V_111 < 0 ) );
F_44 ( V_17 ) ;
F_92 ( V_10 ) ;
F_191 ( V_17 ) ;
F_40 ( V_17 ) ;
return V_111 ;
}
bool F_6 ( struct V_13 * V_17 )
{
return F_192 ( V_17 , false ) ;
}
bool F_193 ( struct V_94 * V_95 )
{
F_194 () ;
if ( F_195 ( & V_95 -> V_96 ) )
F_102 ( V_95 -> V_1 ,
F_41 ( & V_95 -> V_17 ) -> V_9 , & V_95 -> V_17 ) ;
F_196 () ;
return F_191 ( & V_95 -> V_17 ) ;
}
bool F_197 ( struct V_94 * V_95 )
{
unsigned long V_10 ;
int V_111 ;
do {
V_111 = F_83 ( & V_95 -> V_17 , true , & V_10 ) ;
} while ( F_56 ( V_111 == - V_102 ) );
if ( F_56 ( V_111 < 0 ) )
return false ;
F_38 ( & V_95 -> V_17 , F_198 ( & V_95 -> V_17 ) ) ;
F_92 ( V_10 ) ;
return V_111 ;
}
bool F_199 ( struct V_94 * V_95 )
{
return F_192 ( & V_95 -> V_17 , true ) ;
}
bool F_200 ( int V_1 , struct V_13 * V_17 )
{
return F_105 ( V_1 , V_131 , V_17 ) ;
}
bool F_201 ( struct V_13 * V_17 )
{
return F_106 ( V_131 , V_17 ) ;
}
bool F_202 ( int V_1 , struct V_94 * V_95 ,
unsigned long V_113 )
{
return F_113 ( V_1 , V_131 , V_95 , V_113 ) ;
}
bool F_203 ( struct V_94 * V_95 , unsigned long V_113 )
{
return F_114 ( V_131 , V_95 , V_113 ) ;
}
int F_204 ( T_2 V_14 )
{
int V_1 ;
struct V_13 T_3 * V_186 ;
V_186 = F_205 ( struct V_13 ) ;
if ( ! V_186 )
return - V_187 ;
F_206 () ;
F_207 (cpu) {
struct V_13 * V_17 = F_28 ( V_186 , V_1 ) ;
F_133 ( V_17 , V_14 ) ;
F_200 ( V_1 , V_17 ) ;
}
F_207 (cpu)
F_191 ( F_28 ( V_186 , V_1 ) ) ;
F_208 () ;
F_209 ( V_186 ) ;
return 0 ;
}
void F_210 ( void )
{
F_179 ( V_131 ) ;
}
int F_211 ( T_2 V_188 , struct V_189 * V_190 )
{
if ( ! F_212 () ) {
V_188 ( & V_190 -> V_17 ) ;
return 0 ;
}
F_133 ( & V_190 -> V_17 , V_188 ) ;
F_201 ( & V_190 -> V_17 ) ;
return 1 ;
}
int F_213 ( void )
{
return V_131 != NULL ;
}
static int F_214 ( struct V_8 * V_9 )
{
const T_4 V_191 = sizeof( struct V_32 ) ;
const T_4 V_192 = F_215 ( T_4 , 1 << V_193 ,
F_216 (unsigned long long) ) ;
if ( ! ( V_9 -> V_10 & V_11 ) )
V_9 -> V_33 . V_34 = F_217 ( V_191 , V_192 ) ;
else {
void * V_194 ;
V_194 = F_131 ( V_191 + V_192 + sizeof( void * ) , V_133 ) ;
if ( V_194 ) {
V_9 -> V_33 . V_35 = F_218 ( V_194 , V_192 ) ;
* ( void * * ) ( V_9 -> V_33 . V_35 + 1 ) = V_194 ;
}
}
F_33 ( ! F_219 ( V_9 -> V_33 . V_70 , V_192 ) ) ;
return V_9 -> V_33 . V_70 ? 0 : - V_187 ;
}
static void F_220 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_10 & V_11 ) )
F_209 ( V_9 -> V_33 . V_34 ) ;
else if ( V_9 -> V_33 . V_35 ) {
F_145 ( * ( void * * ) ( V_9 -> V_33 . V_35 + 1 ) ) ;
}
}
static int F_221 ( int V_88 , unsigned int V_10 ,
const char * V_183 )
{
int V_195 = V_10 & V_11 ? V_196 : V_197 ;
if ( V_88 < 1 || V_88 > V_195 )
F_187 ( L_6 ,
V_88 , V_183 , 1 , V_195 ) ;
return F_222 ( V_88 , 1 , V_195 ) ;
}
struct V_8 * F_223 ( const char * V_198 ,
unsigned int V_10 ,
int V_88 ,
struct V_199 * V_200 ,
const char * V_201 , ... )
{
T_5 args , V_202 ;
struct V_8 * V_9 ;
unsigned int V_1 ;
T_4 V_203 ;
va_start ( args , V_201 ) ;
F_224 ( V_202 , args ) ;
V_203 = vsnprintf ( NULL , 0 , V_198 , args ) + 1 ;
V_9 = F_131 ( sizeof( * V_9 ) + V_203 , V_133 ) ;
if ( ! V_9 )
goto V_204;
vsnprintf ( V_9 -> V_183 , V_203 , V_198 , V_202 ) ;
va_end ( args ) ;
va_end ( V_202 ) ;
if ( V_10 & V_205 )
V_10 |= V_145 ;
V_88 = V_88 ? : V_206 ;
V_88 = F_221 ( V_88 , V_10 , V_9 -> V_183 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_185 = V_88 ;
F_225 ( & V_9 -> V_174 ) ;
F_177 ( & V_9 -> V_90 , 0 ) ;
F_132 ( & V_9 -> V_177 ) ;
F_132 ( & V_9 -> V_175 ) ;
F_226 ( & V_9 -> V_173 , V_201 , V_200 , 0 ) ;
F_132 ( & V_9 -> V_171 ) ;
if ( F_214 ( V_9 ) < 0 )
goto V_204;
F_178 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
struct V_27 * V_25 = F_23 ( V_1 ) ;
int V_207 = ( bool ) ( V_10 & V_208 ) ;
F_33 ( ( unsigned long ) V_41 & V_209 ) ;
V_41 -> V_24 = & V_25 -> V_26 [ V_207 ] ;
V_41 -> V_9 = V_9 ;
V_41 -> V_89 = - 1 ;
V_41 -> V_88 = V_88 ;
F_132 ( & V_41 -> V_85 ) ;
}
if ( V_10 & V_145 ) {
struct V_59 * V_147 ;
if ( ! F_227 ( & V_9 -> V_146 , V_133 ) )
goto V_204;
V_9 -> V_147 = V_147 = F_130 () ;
if ( ! V_147 )
goto V_204;
V_147 -> V_61 = F_140 ( F_166 , V_9 , L_7 ,
V_9 -> V_183 ) ;
if ( F_141 ( V_147 -> V_61 ) )
goto V_204;
V_147 -> V_61 -> V_10 |= V_140 ;
F_59 ( V_147 -> V_61 ) ;
}
F_88 ( & V_179 ) ;
if ( V_210 && V_9 -> V_10 & V_211 )
F_178 (cpu, wq)
F_26 ( V_1 , V_9 ) -> V_88 = 0 ;
F_118 ( & V_9 -> V_171 , & V_212 ) ;
F_91 ( & V_179 ) ;
return V_9 ;
V_204:
if ( V_9 ) {
F_220 ( V_9 ) ;
F_228 ( V_9 -> V_146 ) ;
F_145 ( V_9 -> V_147 ) ;
F_145 ( V_9 ) ;
}
return NULL ;
}
void F_229 ( struct V_8 * V_9 )
{
unsigned int V_1 ;
F_186 ( V_9 ) ;
F_88 ( & V_179 ) ;
F_230 ( & V_9 -> V_171 ) ;
F_91 ( & V_179 ) ;
F_178 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_39 ; V_104 ++ )
F_33 ( V_41 -> V_87 [ V_104 ] ) ;
F_33 ( V_41 -> V_84 ) ;
F_33 ( ! F_49 ( & V_41 -> V_85 ) ) ;
}
if ( V_9 -> V_10 & V_145 ) {
F_148 ( V_9 -> V_147 -> V_61 ) ;
F_228 ( V_9 -> V_146 ) ;
F_145 ( V_9 -> V_147 ) ;
}
F_220 ( V_9 ) ;
F_145 ( V_9 ) ;
}
static void F_231 ( struct V_32 * V_41 , int V_88 )
{
V_41 -> V_88 = V_88 ;
while ( ! F_49 ( & V_41 -> V_85 ) &&
V_41 -> V_84 < V_41 -> V_88 )
F_80 ( V_41 ) ;
}
void F_232 ( struct V_8 * V_9 , int V_88 )
{
unsigned int V_1 ;
V_88 = F_221 ( V_88 , V_9 -> V_10 , V_9 -> V_183 ) ;
F_88 ( & V_179 ) ;
V_9 -> V_185 = V_88 ;
F_178 (cpu, wq) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
F_135 ( & V_25 -> V_99 ) ;
if ( ! ( V_9 -> V_10 & V_211 ) ||
! ( V_25 -> V_10 & V_213 ) )
F_231 ( F_26 ( V_25 -> V_1 , V_9 ) , V_88 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
F_91 ( & V_179 ) ;
}
bool F_233 ( unsigned int V_1 , struct V_8 * V_9 )
{
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
return ! F_49 ( & V_41 -> V_85 ) ;
}
unsigned int F_198 ( struct V_13 * V_17 )
{
struct V_27 * V_25 = F_43 ( V_17 ) ;
return V_25 ? V_25 -> V_1 : V_7 ;
}
unsigned int F_234 ( struct V_13 * V_17 )
{
struct V_27 * V_25 = F_43 ( V_17 ) ;
unsigned long V_10 ;
unsigned int V_111 = 0 ;
if ( ! V_25 )
return false ;
F_99 ( & V_25 -> V_99 , V_10 ) ;
if ( F_34 ( V_17 ) )
V_111 |= V_214 ;
if ( F_73 ( V_25 , V_17 ) )
V_111 |= V_215 ;
F_101 ( & V_25 -> V_99 , V_10 ) ;
return V_111 ;
}
static void F_235 ( struct V_27 * V_25 )
{
struct V_23 * V_24 ;
F_128 (pool, gcwq)
F_236 ( & V_24 -> V_129 , V_24 - V_25 -> V_26 ) ;
F_135 ( & V_25 -> V_99 ) ;
}
static void F_237 ( struct V_27 * V_25 )
{
struct V_23 * V_24 ;
F_123 ( & V_25 -> V_99 ) ;
F_128 (pool, gcwq)
F_161 ( & V_24 -> V_129 ) ;
}
static void F_238 ( struct V_13 * V_17 )
{
struct V_27 * V_25 = F_23 ( F_239 () ) ;
struct V_23 * V_24 ;
struct V_59 * V_59 ;
struct V_75 * V_103 ;
int V_104 ;
F_33 ( V_25 -> V_1 != F_239 () ) ;
F_235 ( V_25 ) ;
F_128 (pool, gcwq)
F_155 (worker, &pool->idle_list, entry)
V_59 -> V_10 |= V_127 ;
F_100 (worker, i, pos, gcwq)
V_59 -> V_10 |= V_127 ;
V_25 -> V_10 |= V_126 ;
F_237 ( V_25 ) ;
F_165 () ;
F_128 (pool, gcwq)
F_177 ( F_25 ( V_24 ) , 0 ) ;
}
static int T_6 F_240 ( struct V_216 * V_217 ,
unsigned long V_218 ,
void * V_219 )
{
unsigned int V_1 = ( unsigned long ) V_219 ;
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
switch ( V_218 & ~ V_220 ) {
case V_221 :
F_128 (pool, gcwq) {
struct V_59 * V_59 ;
if ( V_24 -> V_56 )
continue;
V_59 = F_134 ( V_24 ) ;
if ( ! V_59 )
return V_222 ;
F_135 ( & V_25 -> V_99 ) ;
F_146 ( V_59 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
break;
case V_223 :
case V_224 :
F_235 ( V_25 ) ;
V_25 -> V_10 &= ~ V_126 ;
F_126 ( V_25 ) ;
F_237 ( V_25 ) ;
break;
}
return V_225 ;
}
static int T_6 F_241 ( struct V_216 * V_217 ,
unsigned long V_218 ,
void * V_219 )
{
unsigned int V_1 = ( unsigned long ) V_219 ;
struct V_13 V_226 ;
switch ( V_218 & ~ V_220 ) {
case V_227 :
F_173 ( & V_226 , F_238 ) ;
F_105 ( V_1 , V_130 , & V_226 ) ;
F_191 ( & V_226 ) ;
break;
}
return V_225 ;
}
static void F_242 ( struct V_13 * V_17 )
{
struct V_228 * V_229 = F_125 ( V_17 , struct V_228 , V_17 ) ;
V_229 -> V_111 = V_229 -> V_188 ( V_229 -> V_230 ) ;
}
long F_243 ( unsigned int V_1 , long (* V_188)( void * ) , void * V_230 )
{
struct V_228 V_229 = { . V_188 = V_188 , . V_230 = V_230 } ;
F_173 ( & V_229 . V_17 , F_242 ) ;
F_200 ( V_1 , & V_229 . V_17 ) ;
F_191 ( & V_229 . V_17 ) ;
return V_229 . V_111 ;
}
void F_244 ( void )
{
unsigned int V_1 ;
F_88 ( & V_179 ) ;
F_33 ( V_210 ) ;
V_210 = true ;
F_98 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_8 * V_9 ;
F_135 ( & V_25 -> V_99 ) ;
F_33 ( V_25 -> V_10 & V_213 ) ;
V_25 -> V_10 |= V_213 ;
F_155 (wq, &workqueues, list) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
if ( V_41 && V_9 -> V_10 & V_211 )
V_41 -> V_88 = 0 ;
}
F_123 ( & V_25 -> V_99 ) ;
}
F_91 ( & V_179 ) ;
}
bool F_245 ( void )
{
unsigned int V_1 ;
bool V_231 = false ;
F_88 ( & V_179 ) ;
F_33 ( ! V_210 ) ;
F_98 (cpu) {
struct V_8 * V_9 ;
F_155 (wq, &workqueues, list) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
if ( ! V_41 || ! ( V_9 -> V_10 & V_211 ) )
continue;
F_33 ( V_41 -> V_84 < 0 ) ;
if ( V_41 -> V_84 ) {
V_231 = true ;
goto V_176;
}
}
}
V_176:
F_91 ( & V_179 ) ;
return V_231 ;
}
void F_246 ( void )
{
unsigned int V_1 ;
F_88 ( & V_179 ) ;
if ( ! V_210 )
goto V_176;
F_98 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_135 ( & V_25 -> V_99 ) ;
F_33 ( ! ( V_25 -> V_10 & V_213 ) ) ;
V_25 -> V_10 &= ~ V_213 ;
F_155 (wq, &workqueues, list) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
if ( ! V_41 || ! ( V_9 -> V_10 & V_211 ) )
continue;
F_231 ( V_41 , V_9 -> V_185 ) ;
}
F_128 (pool, gcwq)
F_58 ( V_24 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
V_210 = false ;
V_176:
F_91 ( & V_179 ) ;
}
static int T_7 F_247 ( void )
{
unsigned int V_1 ;
int V_104 ;
F_248 ( ( 1LU << ( V_232 - V_45 ) ) <
V_233 ) ;
F_249 ( F_240 , V_234 ) ;
F_250 ( F_241 , V_235 ) ;
F_98 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
F_251 ( & V_25 -> V_99 ) ;
V_25 -> V_1 = V_1 ;
V_25 -> V_10 |= V_126 ;
for ( V_104 = 0 ; V_104 < V_236 ; V_104 ++ )
F_252 ( & V_25 -> V_73 [ V_104 ] ) ;
F_128 (pool, gcwq) {
V_24 -> V_25 = V_25 ;
F_132 ( & V_24 -> V_49 ) ;
F_132 ( & V_24 -> V_57 ) ;
F_253 ( & V_24 -> V_124 ) ;
V_24 -> V_124 . V_116 = F_149 ;
V_24 -> V_124 . V_40 = ( unsigned long ) V_24 ;
F_254 ( & V_24 -> V_148 , F_154 ,
( unsigned long ) V_24 ) ;
F_225 ( & V_24 -> V_129 ) ;
F_255 ( & V_24 -> V_137 ) ;
}
}
F_256 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
if ( V_1 != V_6 )
V_25 -> V_10 &= ~ V_126 ;
F_128 (pool, gcwq) {
struct V_59 * V_59 ;
V_59 = F_134 ( V_24 ) ;
F_33 ( ! V_59 ) ;
F_135 ( & V_25 -> V_99 ) ;
F_146 ( V_59 ) ;
F_123 ( & V_25 -> V_99 ) ;
}
}
V_131 = F_257 ( L_8 , 0 , 0 ) ;
V_130 = F_257 ( L_9 , V_208 , 0 ) ;
V_237 = F_257 ( L_10 , 0 , 0 ) ;
V_238 = F_257 ( L_11 , V_11 ,
V_196 ) ;
V_239 = F_257 ( L_12 ,
V_211 , 0 ) ;
F_33 ( ! V_131 || ! V_130 || ! V_237 ||
! V_238 || ! V_239 ) ;
return 0 ;
}
