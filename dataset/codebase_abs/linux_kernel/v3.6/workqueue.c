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
static void F_38 ( struct V_13 * V_17 , unsigned int V_1 )
{
F_32 ( V_17 , V_1 << V_45 , V_43 ) ;
}
static void F_39 ( struct V_13 * V_17 )
{
F_32 ( V_17 , V_46 , 0 ) ;
}
static struct V_32 * F_40 ( struct V_13 * V_17 )
{
unsigned long V_40 = F_41 ( & V_17 -> V_40 ) ;
if ( V_40 & V_44 )
return ( void * ) ( V_40 & V_47 ) ;
else
return NULL ;
}
static struct V_27 * F_42 ( struct V_13 * V_17 )
{
unsigned long V_40 = F_41 ( & V_17 -> V_40 ) ;
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
static bool F_43 ( struct V_23 * V_24 )
{
return ! F_44 ( F_25 ( V_24 ) ) ;
}
static bool F_45 ( struct V_23 * V_24 )
{
return ! F_46 ( & V_24 -> V_48 ) && F_43 ( V_24 ) ;
}
static bool F_47 ( struct V_23 * V_24 )
{
return V_24 -> V_49 ;
}
static bool F_48 ( struct V_23 * V_24 )
{
T_1 * V_50 = F_25 ( V_24 ) ;
return ! F_46 ( & V_24 -> V_48 ) && F_44 ( V_50 ) <= 1 ;
}
static bool F_49 ( struct V_23 * V_24 )
{
return F_45 ( V_24 ) && ! F_47 ( V_24 ) ;
}
static bool F_50 ( struct V_23 * V_24 )
{
return F_49 ( V_24 ) ||
( V_24 -> V_10 & V_51 ) ;
}
static bool F_51 ( struct V_23 * V_24 )
{
bool V_52 = V_24 -> V_10 & V_53 ;
int V_49 = V_24 -> V_49 + V_52 ;
int V_54 = V_24 -> V_55 - V_49 ;
return V_49 > 2 && ( V_49 - 2 ) * V_56 >= V_54 ;
}
static struct V_57 * F_52 ( struct V_23 * V_24 )
{
if ( F_53 ( F_46 ( & V_24 -> V_58 ) ) )
return NULL ;
return F_54 ( & V_24 -> V_58 , struct V_57 , V_59 ) ;
}
static void F_55 ( struct V_23 * V_24 )
{
struct V_57 * V_57 = F_52 ( V_24 ) ;
if ( F_27 ( V_57 ) )
F_56 ( V_57 -> V_60 ) ;
}
void F_57 ( struct V_61 * V_60 , unsigned int V_1 )
{
struct V_57 * V_57 = F_58 ( V_60 ) ;
if ( ! ( V_57 -> V_10 & V_62 ) )
F_59 ( F_25 ( V_57 -> V_24 ) ) ;
}
struct V_61 * F_60 ( struct V_61 * V_60 ,
unsigned int V_1 )
{
struct V_57 * V_57 = F_58 ( V_60 ) , * V_63 = NULL ;
struct V_23 * V_24 = V_57 -> V_24 ;
T_1 * V_50 = F_25 ( V_24 ) ;
if ( V_57 -> V_10 & V_62 )
return NULL ;
F_33 ( V_1 != F_61 () ) ;
if ( F_62 ( V_50 ) && ! F_46 ( & V_24 -> V_48 ) )
V_63 = F_52 ( V_24 ) ;
return V_63 ? V_63 -> V_60 : NULL ;
}
static inline void F_63 ( struct V_57 * V_57 , unsigned int V_10 ,
bool V_64 )
{
struct V_23 * V_24 = V_57 -> V_24 ;
F_12 ( V_57 -> V_60 != V_65 ) ;
if ( ( V_10 & V_62 ) &&
! ( V_57 -> V_10 & V_62 ) ) {
T_1 * V_50 = F_25 ( V_24 ) ;
if ( V_64 ) {
if ( F_62 ( V_50 ) &&
! F_46 ( & V_24 -> V_48 ) )
F_55 ( V_24 ) ;
} else
F_64 ( V_50 ) ;
}
V_57 -> V_10 |= V_10 ;
}
static inline void F_65 ( struct V_57 * V_57 , unsigned int V_10 )
{
struct V_23 * V_24 = V_57 -> V_24 ;
unsigned int V_66 = V_57 -> V_10 ;
F_12 ( V_57 -> V_60 != V_65 ) ;
V_57 -> V_10 &= ~ V_10 ;
if ( ( V_10 & V_62 ) && ( V_66 & V_62 ) )
if ( ! ( V_57 -> V_10 & V_62 ) )
F_59 ( F_25 ( V_24 ) ) ;
}
static struct V_67 * F_66 ( struct V_27 * V_25 ,
struct V_13 * V_17 )
{
const int V_68 = F_67 ( sizeof( struct V_13 ) ) ;
unsigned long V_69 = ( unsigned long ) V_17 ;
V_69 >>= V_68 ;
V_69 += V_69 >> V_70 ;
V_69 &= V_71 ;
return & V_25 -> V_72 [ V_69 ] ;
}
static struct V_57 * F_68 ( struct V_27 * V_25 ,
struct V_67 * V_73 ,
struct V_13 * V_17 )
{
struct V_57 * V_57 ;
struct V_74 * V_75 ;
F_69 (worker, tmp, bwh, hentry)
if ( V_57 -> V_76 == V_17 )
return V_57 ;
return NULL ;
}
static struct V_57 * F_70 ( struct V_27 * V_25 ,
struct V_13 * V_17 )
{
return F_68 ( V_25 , F_66 ( V_25 , V_17 ) ,
V_17 ) ;
}
static void F_71 ( struct V_32 * V_41 ,
struct V_13 * V_17 , struct V_77 * V_78 ,
unsigned int V_42 )
{
struct V_23 * V_24 = V_41 -> V_24 ;
F_37 ( V_17 , V_41 , V_42 ) ;
F_72 () ;
F_73 ( & V_17 -> V_59 , V_78 ) ;
F_74 () ;
if ( F_43 ( V_24 ) )
F_55 ( V_24 ) ;
}
static bool F_75 ( struct V_8 * V_9 )
{
unsigned long V_10 ;
unsigned int V_1 ;
F_76 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_57 * V_57 ;
struct V_74 * V_79 ;
int V_80 ;
F_77 ( & V_25 -> V_81 , V_10 ) ;
F_78 (worker, i, pos, gcwq) {
if ( V_57 -> V_60 != V_65 )
continue;
F_79 ( & V_25 -> V_81 , V_10 ) ;
return V_57 -> V_82 -> V_9 == V_9 ;
}
F_79 ( & V_25 -> V_81 , V_10 ) ;
}
return false ;
}
static void F_80 ( unsigned int V_1 , struct V_8 * V_9 ,
struct V_13 * V_17 )
{
struct V_27 * V_25 ;
struct V_32 * V_41 ;
struct V_77 * V_48 ;
unsigned int V_83 ;
unsigned long V_10 ;
F_16 ( V_17 ) ;
if ( F_53 ( V_9 -> V_10 & V_84 ) &&
F_12 ( ! F_75 ( V_9 ) ) )
return;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_27 * V_85 ;
if ( F_53 ( V_1 == V_6 ) )
V_1 = F_61 () ;
V_25 = F_23 ( V_1 ) ;
if ( V_9 -> V_10 & V_86 &&
( V_85 = F_42 ( V_17 ) ) && V_85 != V_25 ) {
struct V_57 * V_57 ;
F_77 ( & V_85 -> V_81 , V_10 ) ;
V_57 = F_70 ( V_85 , V_17 ) ;
if ( V_57 && V_57 -> V_82 -> V_9 == V_9 )
V_25 = V_85 ;
else {
F_79 ( & V_85 -> V_81 , V_10 ) ;
F_77 ( & V_25 -> V_81 , V_10 ) ;
}
} else
F_77 ( & V_25 -> V_81 , V_10 ) ;
} else {
V_25 = F_23 ( V_6 ) ;
F_77 ( & V_25 -> V_81 , V_10 ) ;
}
V_41 = F_26 ( V_25 -> V_1 , V_9 ) ;
F_81 ( V_1 , V_41 , V_17 ) ;
if ( F_13 ( ! F_46 ( & V_17 -> V_59 ) ) ) {
F_79 ( & V_25 -> V_81 , V_10 ) ;
return;
}
V_41 -> V_87 [ V_41 -> V_88 ] ++ ;
V_83 = F_29 ( V_41 -> V_88 ) ;
if ( F_27 ( V_41 -> V_89 < V_41 -> V_90 ) ) {
F_82 ( V_17 ) ;
V_41 -> V_89 ++ ;
V_48 = & V_41 -> V_24 -> V_48 ;
} else {
V_83 |= V_91 ;
V_48 = & V_41 -> V_92 ;
}
F_71 ( V_41 , V_17 , V_48 , V_83 ) ;
F_79 ( & V_25 -> V_81 , V_10 ) ;
}
int F_83 ( struct V_8 * V_9 , struct V_13 * V_17 )
{
int V_93 ;
V_93 = F_84 ( F_85 () , V_9 , V_17 ) ;
F_86 () ;
return V_93 ;
}
int
F_84 ( int V_1 , struct V_8 * V_9 , struct V_13 * V_17 )
{
int V_93 = 0 ;
if ( ! F_87 ( V_94 , F_10 ( V_17 ) ) ) {
F_80 ( V_1 , V_9 , V_17 ) ;
V_93 = 1 ;
}
return V_93 ;
}
static void F_88 ( unsigned long V_95 )
{
struct V_96 * V_97 = (struct V_96 * ) V_95 ;
struct V_32 * V_41 = F_40 ( & V_97 -> V_17 ) ;
F_80 ( F_89 () , V_41 -> V_9 , & V_97 -> V_17 ) ;
}
int F_90 ( struct V_8 * V_9 ,
struct V_96 * V_97 , unsigned long V_98 )
{
if ( V_98 == 0 )
return F_83 ( V_9 , & V_97 -> V_17 ) ;
return F_91 ( - 1 , V_9 , V_97 , V_98 ) ;
}
int F_91 ( int V_1 , struct V_8 * V_9 ,
struct V_96 * V_97 , unsigned long V_98 )
{
int V_93 = 0 ;
struct V_99 * V_100 = & V_97 -> V_100 ;
struct V_13 * V_17 = & V_97 -> V_17 ;
if ( ! F_87 ( V_94 , F_10 ( V_17 ) ) ) {
unsigned int V_101 ;
F_33 ( F_92 ( V_100 ) ) ;
F_33 ( ! F_46 ( & V_17 -> V_59 ) ) ;
F_93 ( & V_97 -> V_100 ) ;
if ( ! ( V_9 -> V_10 & V_11 ) ) {
struct V_27 * V_25 = F_42 ( V_17 ) ;
if ( V_25 && V_25 -> V_1 != V_6 )
V_101 = V_25 -> V_1 ;
else
V_101 = F_61 () ;
} else
V_101 = V_6 ;
F_37 ( V_17 , F_26 ( V_101 , V_9 ) , 0 ) ;
V_100 -> V_102 = V_103 + V_98 ;
V_100 -> V_40 = ( unsigned long ) V_97 ;
V_100 -> V_104 = F_88 ;
if ( F_53 ( V_1 >= 0 ) )
F_94 ( V_100 , V_1 ) ;
else
F_95 ( V_100 ) ;
V_93 = 1 ;
}
return V_93 ;
}
static void F_96 ( struct V_57 * V_57 )
{
struct V_23 * V_24 = V_57 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
F_33 ( V_57 -> V_10 & V_105 ) ;
F_33 ( ! F_46 ( & V_57 -> V_59 ) &&
( V_57 -> V_106 . V_107 || V_57 -> V_106 . V_108 ) ) ;
V_57 -> V_10 |= V_105 ;
V_24 -> V_49 ++ ;
V_57 -> V_109 = V_103 ;
F_97 ( & V_57 -> V_59 , & V_24 -> V_58 ) ;
if ( F_51 ( V_24 ) && ! F_92 ( & V_24 -> V_110 ) )
F_98 ( & V_24 -> V_110 , V_103 + V_111 ) ;
F_12 ( ! ( V_25 -> V_10 & V_112 ) &&
V_24 -> V_55 == V_24 -> V_49 &&
F_44 ( F_25 ( V_24 ) ) ) ;
}
static void F_99 ( struct V_57 * V_57 )
{
struct V_23 * V_24 = V_57 -> V_24 ;
F_33 ( ! ( V_57 -> V_10 & V_105 ) ) ;
F_65 ( V_57 , V_105 ) ;
V_24 -> V_49 -- ;
F_100 ( & V_57 -> V_59 ) ;
}
static bool F_101 ( struct V_57 * V_57 )
__acquires( &gcwq->lock
static void F_102 ( struct V_57 * V_57 )
{
struct V_27 * V_25 = V_57 -> V_24 -> V_25 ;
F_13 ( ! F_101 ( V_57 ) ) ;
if ( ! -- V_57 -> V_113 -> V_114 )
F_103 ( & V_57 -> V_113 -> V_115 ) ;
F_104 ( & V_57 -> V_24 -> V_25 -> V_81 ) ;
F_105 ( V_25 -> V_116 , ! ( V_57 -> V_10 & V_117 ) ) ;
F_106 ( & V_57 -> V_24 -> V_25 -> V_81 ) ;
if ( ! -- V_57 -> V_113 -> V_114 )
F_103 ( & V_57 -> V_113 -> V_115 ) ;
F_104 ( & V_57 -> V_24 -> V_25 -> V_81 ) ;
}
static void F_107 ( struct V_13 * V_17 )
{
struct V_57 * V_57 = F_108 ( V_17 , struct V_57 , V_118 ) ;
struct V_27 * V_25 = V_57 -> V_24 -> V_25 ;
F_101 ( V_57 ) ;
F_65 ( V_57 , V_117 ) ;
F_104 ( & V_25 -> V_81 ) ;
}
static void F_109 ( struct V_27 * V_25 )
__releases( &gcwq->lock
static struct V_57 * F_110 ( void )
{
struct V_57 * V_57 ;
V_57 = F_111 ( sizeof( * V_57 ) , V_119 ) ;
if ( V_57 ) {
F_112 ( & V_57 -> V_59 ) ;
F_112 ( & V_57 -> V_120 ) ;
F_113 ( & V_57 -> V_118 , F_107 ) ;
V_57 -> V_10 = V_121 ;
}
return V_57 ;
}
static struct V_57 * F_114 ( struct V_23 * V_24 )
{
struct V_27 * V_25 = V_24 -> V_25 ;
const char * V_122 = F_22 ( V_24 ) ? L_1 : L_2 ;
struct V_57 * V_57 = NULL ;
int V_123 = - 1 ;
F_106 ( & V_25 -> V_81 ) ;
while ( F_115 ( & V_24 -> V_124 , & V_123 ) ) {
F_104 ( & V_25 -> V_81 ) ;
if ( ! F_116 ( & V_24 -> V_124 , V_119 ) )
goto V_125;
F_106 ( & V_25 -> V_81 ) ;
}
F_104 ( & V_25 -> V_81 ) ;
V_57 = F_110 () ;
if ( ! V_57 )
goto V_125;
V_57 -> V_24 = V_24 ;
V_57 -> V_123 = V_123 ;
if ( V_25 -> V_1 != V_6 )
V_57 -> V_60 = F_117 ( V_126 ,
V_57 , F_118 ( V_25 -> V_1 ) ,
L_3 , V_25 -> V_1 , V_123 , V_122 ) ;
else
V_57 -> V_60 = F_119 ( V_126 , V_57 ,
L_4 , V_123 , V_122 ) ;
if ( F_120 ( V_57 -> V_60 ) )
goto V_125;
if ( F_22 ( V_24 ) )
F_121 ( V_57 -> V_60 , V_127 ) ;
if ( ! ( V_25 -> V_10 & V_112 ) ) {
F_122 ( V_57 -> V_60 , V_25 -> V_1 ) ;
} else {
V_57 -> V_60 -> V_10 |= V_128 ;
V_57 -> V_10 |= V_129 ;
}
return V_57 ;
V_125:
if ( V_123 >= 0 ) {
F_106 ( & V_25 -> V_81 ) ;
F_123 ( & V_24 -> V_124 , V_123 ) ;
F_104 ( & V_25 -> V_81 ) ;
}
F_124 ( V_57 ) ;
return NULL ;
}
static void F_125 ( struct V_57 * V_57 )
{
V_57 -> V_10 |= V_130 ;
V_57 -> V_24 -> V_55 ++ ;
F_96 ( V_57 ) ;
F_56 ( V_57 -> V_60 ) ;
}
static void F_126 ( struct V_57 * V_57 )
{
struct V_23 * V_24 = V_57 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
int V_123 = V_57 -> V_123 ;
F_33 ( V_57 -> V_76 ) ;
F_33 ( ! F_46 ( & V_57 -> V_120 ) ) ;
if ( V_57 -> V_10 & V_130 )
V_24 -> V_55 -- ;
if ( V_57 -> V_10 & V_105 )
V_24 -> V_49 -- ;
F_100 ( & V_57 -> V_59 ) ;
V_57 -> V_10 |= V_131 ;
F_104 ( & V_25 -> V_81 ) ;
F_127 ( V_57 -> V_60 ) ;
F_124 ( V_57 ) ;
F_106 ( & V_25 -> V_81 ) ;
F_123 ( & V_24 -> V_124 , V_123 ) ;
}
static void F_128 ( unsigned long V_132 )
{
struct V_23 * V_24 = ( void * ) V_132 ;
struct V_27 * V_25 = V_24 -> V_25 ;
F_106 ( & V_25 -> V_81 ) ;
if ( F_51 ( V_24 ) ) {
struct V_57 * V_57 ;
unsigned long V_102 ;
V_57 = F_129 ( V_24 -> V_58 . V_133 , struct V_57 , V_59 ) ;
V_102 = V_57 -> V_109 + V_111 ;
if ( F_130 ( V_103 , V_102 ) )
F_98 ( & V_24 -> V_110 , V_102 ) ;
else {
V_24 -> V_10 |= V_51 ;
F_55 ( V_24 ) ;
}
}
F_104 ( & V_25 -> V_81 ) ;
}
static bool F_131 ( struct V_13 * V_17 )
{
struct V_32 * V_41 = F_40 ( V_17 ) ;
struct V_8 * V_9 = V_41 -> V_9 ;
unsigned int V_1 ;
if ( ! ( V_9 -> V_10 & V_134 ) )
return false ;
V_1 = V_41 -> V_24 -> V_25 -> V_1 ;
if ( V_1 == V_6 )
V_1 = 0 ;
if ( ! F_132 ( V_1 , V_9 -> V_135 ) )
F_56 ( V_9 -> V_136 -> V_60 ) ;
return true ;
}
static void F_133 ( unsigned long V_132 )
{
struct V_23 * V_24 = ( void * ) V_132 ;
struct V_27 * V_25 = V_24 -> V_25 ;
struct V_13 * V_17 ;
F_106 ( & V_25 -> V_81 ) ;
if ( F_49 ( V_24 ) ) {
F_134 (work, &pool->worklist, entry)
F_131 ( V_17 ) ;
}
F_104 ( & V_25 -> V_81 ) ;
F_98 ( & V_24 -> V_137 , V_103 + V_138 ) ;
}
static bool F_135 ( struct V_23 * V_24 )
__releases( &gcwq->lock
static bool F_136 ( struct V_23 * V_24 )
{
bool V_93 = false ;
while ( F_51 ( V_24 ) ) {
struct V_57 * V_57 ;
unsigned long V_102 ;
V_57 = F_129 ( V_24 -> V_58 . V_133 , struct V_57 , V_59 ) ;
V_102 = V_57 -> V_109 + V_111 ;
if ( F_130 ( V_103 , V_102 ) ) {
F_98 ( & V_24 -> V_110 , V_102 ) ;
break;
}
F_126 ( V_57 ) ;
V_93 = true ;
}
return V_93 ;
}
static bool F_137 ( struct V_57 * V_57 )
{
struct V_23 * V_24 = V_57 -> V_24 ;
bool V_93 = false ;
if ( V_24 -> V_10 & V_53 )
return V_93 ;
V_24 -> V_10 |= V_53 ;
if ( F_53 ( ! F_138 ( & V_24 -> V_139 ) ) ) {
F_104 ( & V_24 -> V_25 -> V_81 ) ;
F_139 ( & V_24 -> V_139 ) ;
if ( F_101 ( V_57 ) )
V_57 -> V_10 &= ~ V_129 ;
else
V_57 -> V_10 |= V_129 ;
V_93 = true ;
}
V_24 -> V_10 &= ~ V_51 ;
V_93 |= F_136 ( V_24 ) ;
V_93 |= F_135 ( V_24 ) ;
V_24 -> V_10 &= ~ V_53 ;
F_140 ( & V_24 -> V_139 ) ;
return V_93 ;
}
static void F_141 ( struct V_13 * V_17 , struct V_77 * V_78 ,
struct V_13 * * V_140 )
{
struct V_13 * V_141 ;
F_142 (work, n, NULL, entry) {
F_143 ( & V_17 -> V_59 , V_78 ) ;
if ( ! ( * F_10 ( V_17 ) & V_142 ) )
break;
}
if ( V_140 )
* V_140 = V_141 ;
}
static void F_144 ( struct V_32 * V_41 )
{
struct V_13 * V_17 = F_54 ( & V_41 -> V_92 ,
struct V_13 , V_59 ) ;
F_82 ( V_17 ) ;
F_141 ( V_17 , & V_41 -> V_24 -> V_48 , NULL ) ;
F_145 ( V_143 , F_10 ( V_17 ) ) ;
V_41 -> V_89 ++ ;
}
static void F_146 ( struct V_32 * V_41 , int V_36 ,
bool V_144 )
{
if ( V_36 == V_145 )
return;
V_41 -> V_87 [ V_36 ] -- ;
if ( ! V_144 ) {
V_41 -> V_89 -- ;
if ( ! F_46 ( & V_41 -> V_92 ) ) {
if ( V_41 -> V_89 < V_41 -> V_90 )
F_144 ( V_41 ) ;
}
}
if ( F_27 ( V_41 -> V_146 != V_36 ) )
return;
if ( V_41 -> V_87 [ V_36 ] )
return;
V_41 -> V_146 = - 1 ;
if ( F_62 ( & V_41 -> V_9 -> V_147 ) )
F_103 ( & V_41 -> V_9 -> V_148 -> V_115 ) ;
}
static void F_147 ( struct V_57 * V_57 , struct V_13 * V_17 )
__releases( &gcwq->lock
static void F_148 ( struct V_57 * V_57 )
{
while ( ! F_46 ( & V_57 -> V_120 ) ) {
struct V_13 * V_17 = F_54 ( & V_57 -> V_120 ,
struct V_13 , V_59 ) ;
F_147 ( V_57 , V_17 ) ;
}
}
static int V_126 ( void * V_149 )
{
struct V_57 * V_57 = V_149 ;
struct V_23 * V_24 = V_57 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
V_57 -> V_60 -> V_10 |= V_150 ;
V_151:
F_106 ( & V_25 -> V_81 ) ;
if ( F_53 ( V_57 -> V_10 & ( V_117 | V_131 ) ) ) {
F_104 ( & V_25 -> V_81 ) ;
if ( V_57 -> V_10 & V_131 ) {
V_57 -> V_60 -> V_10 &= ~ V_150 ;
return 0 ;
}
F_102 ( V_57 ) ;
goto V_151;
}
F_99 ( V_57 ) ;
V_152:
if ( ! F_45 ( V_24 ) )
goto V_153;
if ( F_53 ( ! F_47 ( V_24 ) ) && F_137 ( V_57 ) )
goto V_152;
F_33 ( ! F_46 ( & V_57 -> V_120 ) ) ;
F_65 ( V_57 , V_121 ) ;
do {
struct V_13 * V_17 =
F_54 ( & V_24 -> V_48 ,
struct V_13 , V_59 ) ;
if ( F_27 ( ! ( * F_10 ( V_17 ) & V_142 ) ) ) {
F_147 ( V_57 , V_17 ) ;
if ( F_53 ( ! F_46 ( & V_57 -> V_120 ) ) )
F_148 ( V_57 ) ;
} else {
F_141 ( V_17 , & V_57 -> V_120 , NULL ) ;
F_148 ( V_57 ) ;
}
} while ( F_48 ( V_24 ) );
F_63 ( V_57 , V_121 , false ) ;
V_153:
if ( F_53 ( F_50 ( V_24 ) ) && F_137 ( V_57 ) )
goto V_152;
F_96 ( V_57 ) ;
F_149 ( V_154 ) ;
F_104 ( & V_25 -> V_81 ) ;
F_150 () ;
goto V_151;
}
static int F_151 ( void * V_155 )
{
struct V_8 * V_9 = V_155 ;
struct V_57 * V_136 = V_9 -> V_136 ;
struct V_77 * V_120 = & V_136 -> V_120 ;
bool V_156 = V_9 -> V_10 & V_11 ;
unsigned int V_1 ;
F_121 ( V_65 , V_157 ) ;
V_158:
F_152 ( V_154 ) ;
if ( F_153 () )
return 0 ;
F_154 (cpu, wq->mayday_mask) {
unsigned int V_159 = V_156 ? V_6 : V_1 ;
struct V_32 * V_41 = F_26 ( V_159 , V_9 ) ;
struct V_23 * V_24 = V_41 -> V_24 ;
struct V_27 * V_25 = V_24 -> V_25 ;
struct V_13 * V_17 , * V_141 ;
F_149 ( V_160 ) ;
F_155 ( V_1 , V_9 -> V_135 ) ;
V_136 -> V_24 = V_24 ;
F_101 ( V_136 ) ;
F_33 ( ! F_46 ( & V_136 -> V_120 ) ) ;
F_156 (work, n, &pool->worklist, entry)
if ( F_40 ( V_17 ) == V_41 )
F_141 ( V_17 , V_120 , & V_141 ) ;
F_148 ( V_136 ) ;
if ( F_48 ( V_24 ) )
F_55 ( V_24 ) ;
F_104 ( & V_25 -> V_81 ) ;
}
F_150 () ;
goto V_158;
}
static void F_157 ( struct V_13 * V_17 )
{
struct V_161 * V_162 = F_108 ( V_17 , struct V_161 , V_17 ) ;
F_103 ( & V_162 -> V_115 ) ;
}
static void F_158 ( struct V_32 * V_41 ,
struct V_161 * V_162 ,
struct V_13 * V_163 , struct V_57 * V_57 )
{
struct V_77 * V_78 ;
unsigned int V_164 = 0 ;
F_159 ( & V_162 -> V_17 , F_157 ) ;
F_160 ( V_94 , F_10 ( & V_162 -> V_17 ) ) ;
F_161 ( & V_162 -> V_115 ) ;
if ( V_57 )
V_78 = V_57 -> V_120 . V_107 ;
else {
unsigned long * V_165 = F_10 ( V_163 ) ;
V_78 = V_163 -> V_59 . V_107 ;
V_164 = * V_165 & V_142 ;
F_160 ( V_166 , V_165 ) ;
}
F_16 ( & V_162 -> V_17 ) ;
F_71 ( V_41 , & V_162 -> V_17 , V_78 ,
F_29 ( V_145 ) | V_164 ) ;
}
static bool F_162 ( struct V_8 * V_9 ,
int V_146 , int V_88 )
{
bool V_167 = false ;
unsigned int V_1 ;
if ( V_146 >= 0 ) {
F_33 ( F_44 ( & V_9 -> V_147 ) ) ;
F_163 ( & V_9 -> V_147 , 1 ) ;
}
F_164 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
struct V_27 * V_25 = V_41 -> V_24 -> V_25 ;
F_106 ( & V_25 -> V_81 ) ;
if ( V_146 >= 0 ) {
F_33 ( V_41 -> V_146 != - 1 ) ;
if ( V_41 -> V_87 [ V_146 ] ) {
V_41 -> V_146 = V_146 ;
F_59 ( & V_9 -> V_147 ) ;
V_167 = true ;
}
}
if ( V_88 >= 0 ) {
F_33 ( V_88 != F_31 ( V_41 -> V_88 ) ) ;
V_41 -> V_88 = V_88 ;
}
F_104 ( & V_25 -> V_81 ) ;
}
if ( V_146 >= 0 && F_62 ( & V_9 -> V_147 ) )
F_103 ( & V_9 -> V_148 -> V_115 ) ;
return V_167 ;
}
void F_165 ( struct V_8 * V_9 )
{
struct V_168 V_169 = {
. V_170 = F_166 ( V_169 . V_170 ) ,
. V_146 = - 1 ,
. V_115 = F_167 ( V_169 . V_115 ) ,
} ;
int V_171 ;
F_168 ( & V_9 -> V_172 ) ;
F_169 ( & V_9 -> V_172 ) ;
F_139 ( & V_9 -> V_173 ) ;
V_171 = F_31 ( V_9 -> V_88 ) ;
if ( V_171 != V_9 -> V_146 ) {
F_33 ( ! F_46 ( & V_9 -> V_174 ) ) ;
V_169 . V_146 = V_9 -> V_88 ;
V_9 -> V_88 = V_171 ;
if ( ! V_9 -> V_148 ) {
F_33 ( V_9 -> V_146 != V_169 . V_146 ) ;
V_9 -> V_148 = & V_169 ;
if ( ! F_162 ( V_9 , V_9 -> V_146 ,
V_9 -> V_88 ) ) {
V_9 -> V_146 = V_171 ;
V_9 -> V_148 = NULL ;
goto V_175;
}
} else {
F_33 ( V_9 -> V_146 == V_169 . V_146 ) ;
F_73 ( & V_169 . V_170 , & V_9 -> V_176 ) ;
F_162 ( V_9 , - 1 , V_9 -> V_88 ) ;
}
} else {
F_73 ( & V_169 . V_170 , & V_9 -> V_174 ) ;
}
F_140 ( & V_9 -> V_173 ) ;
F_170 ( & V_169 . V_115 ) ;
if ( V_9 -> V_148 != & V_169 )
return;
F_139 ( & V_9 -> V_173 ) ;
if ( V_9 -> V_148 != & V_169 )
goto V_175;
V_9 -> V_148 = NULL ;
F_33 ( ! F_46 ( & V_169 . V_170 ) ) ;
F_33 ( V_9 -> V_146 != V_169 . V_146 ) ;
while ( true ) {
struct V_168 * V_107 , * V_75 ;
F_156 (next, tmp, &wq->flusher_queue, list) {
if ( V_107 -> V_146 != V_9 -> V_146 )
break;
F_100 ( & V_107 -> V_170 ) ;
F_103 ( & V_107 -> V_115 ) ;
}
F_33 ( ! F_46 ( & V_9 -> V_174 ) &&
V_9 -> V_146 != F_31 ( V_9 -> V_88 ) ) ;
V_9 -> V_146 = F_31 ( V_9 -> V_146 ) ;
if ( ! F_46 ( & V_9 -> V_174 ) ) {
F_134 (tmp, &wq->flusher_overflow, list)
V_75 -> V_146 = V_9 -> V_88 ;
V_9 -> V_88 = F_31 ( V_9 -> V_88 ) ;
F_171 ( & V_9 -> V_174 ,
& V_9 -> V_176 ) ;
F_162 ( V_9 , - 1 , V_9 -> V_88 ) ;
}
if ( F_46 ( & V_9 -> V_176 ) ) {
F_33 ( V_9 -> V_146 != V_9 -> V_88 ) ;
break;
}
F_33 ( V_9 -> V_146 == V_9 -> V_88 ) ;
F_33 ( V_9 -> V_146 != V_107 -> V_146 ) ;
F_100 ( & V_107 -> V_170 ) ;
V_9 -> V_148 = V_107 ;
if ( F_162 ( V_9 , V_9 -> V_146 , - 1 ) )
break;
V_9 -> V_148 = NULL ;
}
V_175:
F_140 ( & V_9 -> V_173 ) ;
}
void F_172 ( struct V_8 * V_9 )
{
unsigned int V_177 = 0 ;
unsigned int V_1 ;
F_173 ( & V_178 ) ;
if ( ! V_9 -> V_179 ++ )
V_9 -> V_10 |= V_84 ;
F_174 ( & V_178 ) ;
V_180:
F_165 ( V_9 ) ;
F_164 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
bool V_181 ;
F_106 ( & V_41 -> V_24 -> V_25 -> V_81 ) ;
V_181 = ! V_41 -> V_89 && F_46 ( & V_41 -> V_92 ) ;
F_104 ( & V_41 -> V_24 -> V_25 -> V_81 ) ;
if ( V_181 )
continue;
if ( ++ V_177 == 10 ||
( V_177 % 100 == 0 && V_177 <= 1000 ) )
F_175 ( L_5 ,
V_9 -> V_182 , V_177 ) ;
goto V_180;
}
F_173 ( & V_178 ) ;
if ( ! -- V_9 -> V_179 )
V_9 -> V_10 &= ~ V_84 ;
F_174 ( & V_178 ) ;
}
static bool F_176 ( struct V_13 * V_17 , struct V_161 * V_162 ,
bool V_183 )
{
struct V_57 * V_57 = NULL ;
struct V_27 * V_25 ;
struct V_32 * V_41 ;
F_177 () ;
V_25 = F_42 ( V_17 ) ;
if ( ! V_25 )
return false ;
F_106 ( & V_25 -> V_81 ) ;
if ( ! F_46 ( & V_17 -> V_59 ) ) {
F_178 () ;
V_41 = F_40 ( V_17 ) ;
if ( F_53 ( ! V_41 || V_25 != V_41 -> V_24 -> V_25 ) )
goto V_184;
} else if ( V_183 ) {
V_57 = F_70 ( V_25 , V_17 ) ;
if ( ! V_57 )
goto V_184;
V_41 = V_57 -> V_82 ;
} else
goto V_184;
F_158 ( V_41 , V_162 , V_17 , V_57 ) ;
F_104 ( & V_25 -> V_81 ) ;
if ( V_41 -> V_9 -> V_185 == 1 || V_41 -> V_9 -> V_10 & V_134 )
F_168 ( & V_41 -> V_9 -> V_172 ) ;
else
F_179 ( & V_41 -> V_9 -> V_172 ) ;
F_169 ( & V_41 -> V_9 -> V_172 ) ;
return true ;
V_184:
F_104 ( & V_25 -> V_81 ) ;
return false ;
}
bool F_180 ( struct V_13 * V_17 )
{
struct V_161 V_162 ;
F_168 ( & V_17 -> V_172 ) ;
F_169 ( & V_17 -> V_172 ) ;
if ( F_176 ( V_17 , & V_162 , true ) ) {
F_170 ( & V_162 . V_115 ) ;
F_21 ( & V_162 . V_17 ) ;
return true ;
} else
return false ;
}
static bool F_181 ( struct V_27 * V_25 , struct V_13 * V_17 )
{
struct V_161 V_162 ;
struct V_57 * V_57 ;
F_106 ( & V_25 -> V_81 ) ;
V_57 = F_70 ( V_25 , V_17 ) ;
if ( F_53 ( V_57 ) )
F_158 ( V_57 -> V_82 , & V_162 , V_17 , V_57 ) ;
F_104 ( & V_25 -> V_81 ) ;
if ( F_53 ( V_57 ) ) {
F_170 ( & V_162 . V_115 ) ;
F_21 ( & V_162 . V_17 ) ;
return true ;
} else
return false ;
}
static bool F_182 ( struct V_13 * V_17 )
{
bool V_93 = false ;
int V_1 ;
F_177 () ;
F_168 ( & V_17 -> V_172 ) ;
F_169 ( & V_17 -> V_172 ) ;
F_76 (cpu)
V_93 |= F_181 ( F_23 ( V_1 ) , V_17 ) ;
return V_93 ;
}
bool F_183 ( struct V_13 * V_17 )
{
struct V_161 V_162 ;
bool V_186 , V_187 ;
V_186 = F_176 ( V_17 , & V_162 , false ) ;
V_187 = F_182 ( V_17 ) ;
if ( V_186 ) {
F_170 ( & V_162 . V_115 ) ;
F_21 ( & V_162 . V_17 ) ;
}
return V_186 || V_187 ;
}
static int F_184 ( struct V_13 * V_17 )
{
struct V_27 * V_25 ;
int V_93 = - 1 ;
if ( ! F_87 ( V_94 , F_10 ( V_17 ) ) )
return 0 ;
V_25 = F_42 ( V_17 ) ;
if ( ! V_25 )
return V_93 ;
F_106 ( & V_25 -> V_81 ) ;
if ( ! F_46 ( & V_17 -> V_59 ) ) {
F_178 () ;
if ( V_25 == F_42 ( V_17 ) ) {
F_17 ( V_17 ) ;
F_100 ( & V_17 -> V_59 ) ;
F_146 ( F_40 ( V_17 ) ,
F_30 ( V_17 ) ,
* F_10 ( V_17 ) & V_91 ) ;
V_93 = 1 ;
}
}
F_104 ( & V_25 -> V_81 ) ;
return V_93 ;
}
static bool F_185 ( struct V_13 * V_17 ,
struct V_99 * V_100 )
{
int V_93 ;
do {
V_93 = ( V_100 && F_27 ( F_186 ( V_100 ) ) ) ;
if ( ! V_93 )
V_93 = F_184 ( V_17 ) ;
F_182 ( V_17 ) ;
} while ( F_53 ( V_93 < 0 ) );
F_39 ( V_17 ) ;
return V_93 ;
}
bool F_6 ( struct V_13 * V_17 )
{
return F_185 ( V_17 , NULL ) ;
}
bool F_187 ( struct V_96 * V_97 )
{
if ( F_188 ( & V_97 -> V_100 ) )
F_80 ( F_61 () ,
F_40 ( & V_97 -> V_17 ) -> V_9 , & V_97 -> V_17 ) ;
return F_180 ( & V_97 -> V_17 ) ;
}
bool F_189 ( struct V_96 * V_97 )
{
if ( F_188 ( & V_97 -> V_100 ) )
F_80 ( F_61 () ,
F_40 ( & V_97 -> V_17 ) -> V_9 , & V_97 -> V_17 ) ;
return F_183 ( & V_97 -> V_17 ) ;
}
bool F_190 ( struct V_96 * V_97 )
{
return F_185 ( & V_97 -> V_17 , & V_97 -> V_100 ) ;
}
int F_191 ( struct V_13 * V_17 )
{
return F_83 ( V_188 , V_17 ) ;
}
int F_192 ( int V_1 , struct V_13 * V_17 )
{
return F_84 ( V_1 , V_188 , V_17 ) ;
}
int F_193 ( struct V_96 * V_97 ,
unsigned long V_98 )
{
return F_90 ( V_188 , V_97 , V_98 ) ;
}
int F_194 ( int V_1 ,
struct V_96 * V_97 , unsigned long V_98 )
{
return F_91 ( V_1 , V_188 , V_97 , V_98 ) ;
}
int F_195 ( T_2 V_14 )
{
int V_1 ;
struct V_13 T_3 * V_189 ;
V_189 = F_196 ( struct V_13 ) ;
if ( ! V_189 )
return - V_190 ;
F_197 () ;
F_198 (cpu) {
struct V_13 * V_17 = F_28 ( V_189 , V_1 ) ;
F_113 ( V_17 , V_14 ) ;
F_192 ( V_1 , V_17 ) ;
}
F_198 (cpu)
F_180 ( F_28 ( V_189 , V_1 ) ) ;
F_199 () ;
F_200 ( V_189 ) ;
return 0 ;
}
void F_201 ( void )
{
F_165 ( V_188 ) ;
}
int F_202 ( T_2 V_191 , struct V_192 * V_193 )
{
if ( ! F_203 () ) {
V_191 ( & V_193 -> V_17 ) ;
return 0 ;
}
F_113 ( & V_193 -> V_17 , V_191 ) ;
F_191 ( & V_193 -> V_17 ) ;
return 1 ;
}
int F_204 ( void )
{
return V_188 != NULL ;
}
static int F_205 ( struct V_8 * V_9 )
{
const T_4 V_194 = sizeof( struct V_32 ) ;
const T_4 V_195 = F_206 ( T_4 , 1 << V_45 ,
F_207 (unsigned long long) ) ;
if ( ! ( V_9 -> V_10 & V_11 ) )
V_9 -> V_33 . V_34 = F_208 ( V_194 , V_195 ) ;
else {
void * V_196 ;
V_196 = F_111 ( V_194 + V_195 + sizeof( void * ) , V_119 ) ;
if ( V_196 ) {
V_9 -> V_33 . V_35 = F_209 ( V_196 , V_195 ) ;
* ( void * * ) ( V_9 -> V_33 . V_35 + 1 ) = V_196 ;
}
}
F_33 ( ! F_210 ( V_9 -> V_33 . V_69 , V_195 ) ) ;
return V_9 -> V_33 . V_69 ? 0 : - V_190 ;
}
static void F_211 ( struct V_8 * V_9 )
{
if ( ! ( V_9 -> V_10 & V_11 ) )
F_200 ( V_9 -> V_33 . V_34 ) ;
else if ( V_9 -> V_33 . V_35 ) {
F_124 ( * ( void * * ) ( V_9 -> V_33 . V_35 + 1 ) ) ;
}
}
static int F_212 ( int V_90 , unsigned int V_10 ,
const char * V_182 )
{
int V_197 = V_10 & V_11 ? V_198 : V_199 ;
if ( V_90 < 1 || V_90 > V_197 )
F_213 ( V_200 L_6
L_7 ,
V_90 , V_182 , 1 , V_197 ) ;
return F_214 ( V_90 , 1 , V_197 ) ;
}
struct V_8 * F_215 ( const char * V_201 ,
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
F_216 ( V_205 , args ) ;
V_206 = vsnprintf ( NULL , 0 , V_201 , args ) + 1 ;
V_9 = F_111 ( sizeof( * V_9 ) + V_206 , V_119 ) ;
if ( ! V_9 )
goto V_207;
vsnprintf ( V_9 -> V_182 , V_206 , V_201 , V_205 ) ;
va_end ( args ) ;
va_end ( V_205 ) ;
if ( V_10 & V_208 )
V_10 |= V_134 ;
V_90 = V_90 ? : V_209 ;
V_90 = F_212 ( V_90 , V_10 , V_9 -> V_182 ) ;
V_9 -> V_10 = V_10 ;
V_9 -> V_185 = V_90 ;
F_217 ( & V_9 -> V_173 ) ;
F_163 ( & V_9 -> V_147 , 0 ) ;
F_112 ( & V_9 -> V_176 ) ;
F_112 ( & V_9 -> V_174 ) ;
F_218 ( & V_9 -> V_172 , V_204 , V_203 , 0 ) ;
F_112 ( & V_9 -> V_170 ) ;
if ( F_205 ( V_9 ) < 0 )
goto V_207;
F_164 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
struct V_27 * V_25 = F_23 ( V_1 ) ;
int V_210 = ( bool ) ( V_10 & V_211 ) ;
F_33 ( ( unsigned long ) V_41 & V_212 ) ;
V_41 -> V_24 = & V_25 -> V_26 [ V_210 ] ;
V_41 -> V_9 = V_9 ;
V_41 -> V_146 = - 1 ;
V_41 -> V_90 = V_90 ;
F_112 ( & V_41 -> V_92 ) ;
}
if ( V_10 & V_134 ) {
struct V_57 * V_136 ;
if ( ! F_219 ( & V_9 -> V_135 , V_119 ) )
goto V_207;
V_9 -> V_136 = V_136 = F_110 () ;
if ( ! V_136 )
goto V_207;
V_136 -> V_60 = F_119 ( F_151 , V_9 , L_8 ,
V_9 -> V_182 ) ;
if ( F_120 ( V_136 -> V_60 ) )
goto V_207;
V_136 -> V_60 -> V_10 |= V_128 ;
F_56 ( V_136 -> V_60 ) ;
}
F_173 ( & V_178 ) ;
if ( V_213 && V_9 -> V_10 & V_214 )
F_164 (cpu, wq)
F_26 ( V_1 , V_9 ) -> V_90 = 0 ;
F_97 ( & V_9 -> V_170 , & V_215 ) ;
F_174 ( & V_178 ) ;
return V_9 ;
V_207:
if ( V_9 ) {
F_211 ( V_9 ) ;
F_220 ( V_9 -> V_135 ) ;
F_124 ( V_9 -> V_136 ) ;
F_124 ( V_9 ) ;
}
return NULL ;
}
void F_221 ( struct V_8 * V_9 )
{
unsigned int V_1 ;
F_172 ( V_9 ) ;
F_173 ( & V_178 ) ;
F_222 ( & V_9 -> V_170 ) ;
F_174 ( & V_178 ) ;
F_164 (cpu, wq) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
int V_80 ;
for ( V_80 = 0 ; V_80 < V_39 ; V_80 ++ )
F_33 ( V_41 -> V_87 [ V_80 ] ) ;
F_33 ( V_41 -> V_89 ) ;
F_33 ( ! F_46 ( & V_41 -> V_92 ) ) ;
}
if ( V_9 -> V_10 & V_134 ) {
F_127 ( V_9 -> V_136 -> V_60 ) ;
F_220 ( V_9 -> V_135 ) ;
F_124 ( V_9 -> V_136 ) ;
}
F_211 ( V_9 ) ;
F_124 ( V_9 ) ;
}
void F_223 ( struct V_8 * V_9 , int V_90 )
{
unsigned int V_1 ;
V_90 = F_212 ( V_90 , V_9 -> V_10 , V_9 -> V_182 ) ;
F_173 ( & V_178 ) ;
V_9 -> V_185 = V_90 ;
F_164 (cpu, wq) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
F_106 ( & V_25 -> V_81 ) ;
if ( ! ( V_9 -> V_10 & V_214 ) ||
! ( V_25 -> V_10 & V_216 ) )
F_26 ( V_25 -> V_1 , V_9 ) -> V_90 = V_90 ;
F_104 ( & V_25 -> V_81 ) ;
}
F_174 ( & V_178 ) ;
}
bool F_224 ( unsigned int V_1 , struct V_8 * V_9 )
{
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
return ! F_46 ( & V_41 -> V_92 ) ;
}
unsigned int F_225 ( struct V_13 * V_17 )
{
struct V_27 * V_25 = F_42 ( V_17 ) ;
return V_25 ? V_25 -> V_1 : V_7 ;
}
unsigned int F_226 ( struct V_13 * V_17 )
{
struct V_27 * V_25 = F_42 ( V_17 ) ;
unsigned long V_10 ;
unsigned int V_93 = 0 ;
if ( ! V_25 )
return false ;
F_77 ( & V_25 -> V_81 , V_10 ) ;
if ( F_34 ( V_17 ) )
V_93 |= V_217 ;
if ( F_70 ( V_25 , V_17 ) )
V_93 |= V_218 ;
F_79 ( & V_25 -> V_81 , V_10 ) ;
return V_93 ;
}
static void F_227 ( struct V_27 * V_25 )
{
struct V_23 * V_24 ;
F_228 (pool, gcwq)
F_229 ( & V_24 -> V_139 , V_24 - V_25 -> V_26 ) ;
F_106 ( & V_25 -> V_81 ) ;
}
static void F_230 ( struct V_27 * V_25 )
{
struct V_23 * V_24 ;
F_104 ( & V_25 -> V_81 ) ;
F_228 (pool, gcwq)
F_140 ( & V_24 -> V_139 ) ;
}
static void F_231 ( struct V_13 * V_17 )
{
struct V_27 * V_25 = F_23 ( F_89 () ) ;
struct V_23 * V_24 ;
struct V_57 * V_57 ;
struct V_74 * V_79 ;
int V_80 ;
F_33 ( V_25 -> V_1 != F_89 () ) ;
F_227 ( V_25 ) ;
F_228 (pool, gcwq)
F_134 (worker, &pool->idle_list, entry)
V_57 -> V_10 |= V_129 ;
F_78 (worker, i, pos, gcwq)
V_57 -> V_10 |= V_129 ;
V_25 -> V_10 |= V_112 ;
F_230 ( V_25 ) ;
F_150 () ;
F_228 (pool, gcwq)
F_163 ( F_25 ( V_24 ) , 0 ) ;
}
static int T_6 F_232 ( struct V_219 * V_220 ,
unsigned long V_221 ,
void * V_222 )
{
unsigned int V_1 = ( unsigned long ) V_222 ;
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
switch ( V_221 & ~ V_223 ) {
case V_224 :
F_228 (pool, gcwq) {
struct V_57 * V_57 ;
if ( V_24 -> V_55 )
continue;
V_57 = F_114 ( V_24 ) ;
if ( ! V_57 )
return V_225 ;
F_106 ( & V_25 -> V_81 ) ;
F_125 ( V_57 ) ;
F_104 ( & V_25 -> V_81 ) ;
}
break;
case V_226 :
case V_227 :
F_227 ( V_25 ) ;
V_25 -> V_10 &= ~ V_112 ;
F_109 ( V_25 ) ;
F_230 ( V_25 ) ;
break;
}
return V_228 ;
}
static int T_6 F_233 ( struct V_219 * V_220 ,
unsigned long V_221 ,
void * V_222 )
{
unsigned int V_1 = ( unsigned long ) V_222 ;
struct V_13 V_229 ;
switch ( V_221 & ~ V_223 ) {
case V_230 :
F_159 ( & V_229 , F_231 ) ;
F_192 ( V_1 , & V_229 ) ;
F_180 ( & V_229 ) ;
break;
}
return V_228 ;
}
static void F_234 ( struct V_13 * V_17 )
{
struct V_231 * V_232 = F_108 ( V_17 , struct V_231 , V_17 ) ;
V_232 -> V_93 = V_232 -> V_191 ( V_232 -> V_233 ) ;
}
long F_235 ( unsigned int V_1 , long (* V_191)( void * ) , void * V_233 )
{
struct V_231 V_232 = { . V_191 = V_191 , . V_233 = V_233 } ;
F_159 ( & V_232 . V_17 , F_234 ) ;
F_192 ( V_1 , & V_232 . V_17 ) ;
F_180 ( & V_232 . V_17 ) ;
return V_232 . V_93 ;
}
void F_236 ( void )
{
unsigned int V_1 ;
F_173 ( & V_178 ) ;
F_33 ( V_213 ) ;
V_213 = true ;
F_76 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_8 * V_9 ;
F_106 ( & V_25 -> V_81 ) ;
F_33 ( V_25 -> V_10 & V_216 ) ;
V_25 -> V_10 |= V_216 ;
F_134 (wq, &workqueues, list) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
if ( V_41 && V_9 -> V_10 & V_214 )
V_41 -> V_90 = 0 ;
}
F_104 ( & V_25 -> V_81 ) ;
}
F_174 ( & V_178 ) ;
}
bool F_237 ( void )
{
unsigned int V_1 ;
bool V_234 = false ;
F_173 ( & V_178 ) ;
F_33 ( ! V_213 ) ;
F_76 (cpu) {
struct V_8 * V_9 ;
F_134 (wq, &workqueues, list) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
if ( ! V_41 || ! ( V_9 -> V_10 & V_214 ) )
continue;
F_33 ( V_41 -> V_89 < 0 ) ;
if ( V_41 -> V_89 ) {
V_234 = true ;
goto V_175;
}
}
}
V_175:
F_174 ( & V_178 ) ;
return V_234 ;
}
void F_238 ( void )
{
unsigned int V_1 ;
F_173 ( & V_178 ) ;
if ( ! V_213 )
goto V_175;
F_76 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
struct V_8 * V_9 ;
F_106 ( & V_25 -> V_81 ) ;
F_33 ( ! ( V_25 -> V_10 & V_216 ) ) ;
V_25 -> V_10 &= ~ V_216 ;
F_134 (wq, &workqueues, list) {
struct V_32 * V_41 = F_26 ( V_1 , V_9 ) ;
if ( ! V_41 || ! ( V_9 -> V_10 & V_214 ) )
continue;
V_41 -> V_90 = V_9 -> V_185 ;
while ( ! F_46 ( & V_41 -> V_92 ) &&
V_41 -> V_89 < V_41 -> V_90 )
F_144 ( V_41 ) ;
}
F_228 (pool, gcwq)
F_55 ( V_24 ) ;
F_104 ( & V_25 -> V_81 ) ;
}
V_213 = false ;
V_175:
F_174 ( & V_178 ) ;
}
static int T_7 F_239 ( void )
{
unsigned int V_1 ;
int V_80 ;
F_240 ( F_232 , V_235 ) ;
F_240 ( F_233 , V_236 ) ;
F_76 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
F_241 ( & V_25 -> V_81 ) ;
V_25 -> V_1 = V_1 ;
V_25 -> V_10 |= V_112 ;
for ( V_80 = 0 ; V_80 < V_237 ; V_80 ++ )
F_242 ( & V_25 -> V_72 [ V_80 ] ) ;
F_228 (pool, gcwq) {
V_24 -> V_25 = V_25 ;
F_112 ( & V_24 -> V_48 ) ;
F_112 ( & V_24 -> V_58 ) ;
F_243 ( & V_24 -> V_110 ) ;
V_24 -> V_110 . V_104 = F_128 ;
V_24 -> V_110 . V_40 = ( unsigned long ) V_24 ;
F_244 ( & V_24 -> V_137 , F_133 ,
( unsigned long ) V_24 ) ;
F_217 ( & V_24 -> V_139 ) ;
F_245 ( & V_24 -> V_124 ) ;
}
F_246 ( & V_25 -> V_116 ) ;
}
F_247 (cpu) {
struct V_27 * V_25 = F_23 ( V_1 ) ;
struct V_23 * V_24 ;
if ( V_1 != V_6 )
V_25 -> V_10 &= ~ V_112 ;
F_228 (pool, gcwq) {
struct V_57 * V_57 ;
V_57 = F_114 ( V_24 ) ;
F_33 ( ! V_57 ) ;
F_106 ( & V_25 -> V_81 ) ;
F_125 ( V_57 ) ;
F_104 ( & V_25 -> V_81 ) ;
}
}
V_188 = F_248 ( L_9 , 0 , 0 ) ;
V_238 = F_248 ( L_10 , 0 , 0 ) ;
V_239 = F_248 ( L_11 , V_86 , 0 ) ;
V_240 = F_248 ( L_12 , V_11 ,
V_198 ) ;
V_241 = F_248 ( L_13 ,
V_214 , 0 ) ;
V_242 = F_248 ( L_14 ,
V_86 | V_214 , 0 ) ;
F_33 ( ! V_188 || ! V_238 || ! V_239 ||
! V_240 || ! V_241 ||
! V_242 ) ;
return 0 ;
}
