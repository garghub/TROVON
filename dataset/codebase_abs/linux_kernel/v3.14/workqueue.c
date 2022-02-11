static void * F_1 ( void * V_1 )
{
return ( (struct V_2 * ) V_1 ) -> V_3 ;
}
static int F_2 ( void * V_1 , enum V_4 V_5 )
{
struct V_2 * V_6 = V_1 ;
switch ( V_5 ) {
case V_7 :
F_3 ( V_6 ) ;
F_4 ( V_6 , & V_8 ) ;
return 1 ;
default:
return 0 ;
}
}
static int F_5 ( void * V_1 , enum V_4 V_5 )
{
struct V_2 * V_6 = V_1 ;
switch ( V_5 ) {
case V_9 :
if ( F_6 ( V_10 , F_7 ( V_6 ) ) ) {
F_4 ( V_6 , & V_8 ) ;
F_8 ( V_6 , & V_8 ) ;
return 0 ;
}
F_9 ( 1 ) ;
return 0 ;
case V_7 :
F_10 ( 1 ) ;
default:
return 0 ;
}
}
static int F_11 ( void * V_1 , enum V_4 V_5 )
{
struct V_2 * V_6 = V_1 ;
switch ( V_5 ) {
case V_7 :
F_3 ( V_6 ) ;
F_12 ( V_6 , & V_8 ) ;
return 1 ;
default:
return 0 ;
}
}
static inline void F_13 ( struct V_2 * V_6 )
{
F_8 ( V_6 , & V_8 ) ;
}
static inline void F_14 ( struct V_2 * V_6 )
{
F_15 ( V_6 , & V_8 ) ;
}
void F_16 ( struct V_2 * V_6 , int V_11 )
{
if ( V_11 )
F_17 ( V_6 , & V_8 ) ;
else
F_4 ( V_6 , & V_8 ) ;
}
void F_18 ( struct V_2 * V_6 )
{
F_12 ( V_6 , & V_8 ) ;
}
static inline void F_13 ( struct V_2 * V_6 ) { }
static inline void F_14 ( struct V_2 * V_6 ) { }
static int F_19 ( struct V_12 * V_13 )
{
int V_14 ;
F_20 ( & V_15 ) ;
V_14 = F_21 ( & V_16 , V_13 , 0 , V_17 ,
V_18 ) ;
if ( V_14 >= 0 ) {
V_13 -> V_19 = V_14 ;
return 0 ;
}
return V_14 ;
}
static struct V_20 * F_22 ( struct V_21 * V_22 ,
int V_23 )
{
F_23 ( V_22 ) ;
return F_24 ( V_22 -> V_24 [ V_23 ] ) ;
}
static unsigned int F_25 ( int V_25 )
{
return V_25 << V_26 ;
}
static int F_26 ( struct V_2 * V_6 )
{
return ( * F_7 ( V_6 ) >> V_26 ) &
( ( 1 << V_27 ) - 1 ) ;
}
static int F_27 ( int V_25 )
{
return ( V_25 + 1 ) % V_28 ;
}
static inline void F_28 ( struct V_2 * V_6 , unsigned long V_29 ,
unsigned long V_30 )
{
F_9 ( ! F_29 ( V_6 ) ) ;
F_30 ( & V_6 -> V_29 , V_29 | V_30 | F_31 ( V_6 ) ) ;
}
static void F_32 ( struct V_2 * V_6 , struct V_20 * V_31 ,
unsigned long V_32 )
{
F_28 ( V_6 , ( unsigned long ) V_31 ,
V_33 | V_34 | V_32 ) ;
}
static void F_33 ( struct V_2 * V_6 ,
int V_35 )
{
F_28 ( V_6 , ( unsigned long ) V_35 << V_36 ,
V_33 ) ;
}
static void F_34 ( struct V_2 * V_6 ,
int V_35 )
{
F_35 () ;
F_28 ( V_6 , ( unsigned long ) V_35 << V_36 , 0 ) ;
}
static void F_36 ( struct V_2 * V_6 )
{
F_35 () ;
F_28 ( V_6 , V_37 , 0 ) ;
}
static struct V_20 * F_37 ( struct V_2 * V_6 )
{
unsigned long V_29 = F_38 ( & V_6 -> V_29 ) ;
if ( V_29 & V_34 )
return ( void * ) ( V_29 & V_38 ) ;
else
return NULL ;
}
static struct V_12 * F_39 ( struct V_2 * V_6 )
{
unsigned long V_29 = F_38 ( & V_6 -> V_29 ) ;
int V_35 ;
F_40 () ;
if ( V_29 & V_34 )
return ( (struct V_20 * )
( V_29 & V_38 ) ) -> V_13 ;
V_35 = V_29 >> V_36 ;
if ( V_35 == V_17 )
return NULL ;
return F_41 ( & V_16 , V_35 ) ;
}
static int F_42 ( struct V_2 * V_6 )
{
unsigned long V_29 = F_38 ( & V_6 -> V_29 ) ;
if ( V_29 & V_34 )
return ( (struct V_20 * )
( V_29 & V_38 ) ) -> V_13 -> V_19 ;
return V_29 >> V_36 ;
}
static void F_43 ( struct V_2 * V_6 )
{
unsigned long V_35 = F_42 ( V_6 ) ;
V_35 <<= V_36 ;
F_28 ( V_6 , V_35 | V_39 , V_33 ) ;
}
static bool F_44 ( struct V_2 * V_6 )
{
unsigned long V_29 = F_38 ( & V_6 -> V_29 ) ;
return ! ( V_29 & V_34 ) && ( V_29 & V_39 ) ;
}
static bool F_45 ( struct V_12 * V_13 )
{
return ! F_46 ( & V_13 -> V_40 ) ;
}
static bool F_47 ( struct V_12 * V_13 )
{
return ! F_48 ( & V_13 -> V_41 ) && F_45 ( V_13 ) ;
}
static bool F_49 ( struct V_12 * V_13 )
{
return V_13 -> V_42 ;
}
static bool F_50 ( struct V_12 * V_13 )
{
return ! F_48 ( & V_13 -> V_41 ) &&
F_46 ( & V_13 -> V_40 ) <= 1 ;
}
static bool F_51 ( struct V_12 * V_13 )
{
return F_47 ( V_13 ) && ! F_49 ( V_13 ) ;
}
static bool F_52 ( struct V_12 * V_13 )
{
return F_51 ( V_13 ) ||
( V_13 -> V_30 & V_43 ) ;
}
static bool F_53 ( struct V_12 * V_13 )
{
bool V_44 = F_54 ( & V_13 -> V_45 ) ;
int V_42 = V_13 -> V_42 + V_44 ;
int V_46 = V_13 -> V_47 - V_42 ;
if ( F_48 ( & V_13 -> V_48 ) )
return false ;
return V_42 > 2 && ( V_42 - 2 ) * V_49 >= V_46 ;
}
static struct V_50 * F_55 ( struct V_12 * V_13 )
{
if ( F_56 ( F_48 ( & V_13 -> V_48 ) ) )
return NULL ;
return F_57 ( & V_13 -> V_48 , struct V_50 , V_51 ) ;
}
static void F_58 ( struct V_12 * V_13 )
{
struct V_50 * V_50 = F_55 ( V_13 ) ;
if ( F_59 ( V_50 ) )
F_60 ( V_50 -> V_52 ) ;
}
void F_61 ( struct V_53 * V_52 , int V_54 )
{
struct V_50 * V_50 = F_62 ( V_52 ) ;
if ( ! ( V_50 -> V_30 & V_55 ) ) {
F_9 ( V_50 -> V_13 -> V_54 != V_54 ) ;
F_63 ( & V_50 -> V_13 -> V_40 ) ;
}
}
struct V_53 * F_64 ( struct V_53 * V_52 , int V_54 )
{
struct V_50 * V_50 = F_62 ( V_52 ) , * V_56 = NULL ;
struct V_12 * V_13 ;
if ( V_50 -> V_30 & V_55 )
return NULL ;
V_13 = V_50 -> V_13 ;
if ( F_9 ( V_54 != F_65 () ) )
return NULL ;
if ( F_66 ( & V_13 -> V_40 ) &&
! F_48 ( & V_13 -> V_41 ) )
V_56 = F_55 ( V_13 ) ;
return V_56 ? V_56 -> V_52 : NULL ;
}
static inline void F_67 ( struct V_50 * V_50 , unsigned int V_30 ,
bool V_57 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
F_9 ( V_50 -> V_52 != V_58 ) ;
if ( ( V_30 & V_55 ) &&
! ( V_50 -> V_30 & V_55 ) ) {
if ( V_57 ) {
if ( F_66 ( & V_13 -> V_40 ) &&
! F_48 ( & V_13 -> V_41 ) )
F_58 ( V_13 ) ;
} else
F_68 ( & V_13 -> V_40 ) ;
}
V_50 -> V_30 |= V_30 ;
}
static inline void F_69 ( struct V_50 * V_50 , unsigned int V_30 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
unsigned int V_59 = V_50 -> V_30 ;
F_9 ( V_50 -> V_52 != V_58 ) ;
V_50 -> V_30 &= ~ V_30 ;
if ( ( V_30 & V_55 ) && ( V_59 & V_55 ) )
if ( ! ( V_50 -> V_30 & V_55 ) )
F_63 ( & V_13 -> V_40 ) ;
}
static struct V_50 * F_70 ( struct V_12 * V_13 ,
struct V_2 * V_6 )
{
struct V_50 * V_50 ;
F_71 (pool->busy_hash, worker, hentry,
(unsigned long)work)
if ( V_50 -> V_60 == V_6 &&
V_50 -> V_61 == V_6 -> V_3 )
return V_50 ;
return NULL ;
}
static void F_72 ( struct V_2 * V_6 , struct V_62 * V_63 ,
struct V_2 * * V_64 )
{
struct V_2 * V_65 ;
F_73 (work, n, NULL, entry) {
F_74 ( & V_6 -> V_51 , V_63 ) ;
if ( ! ( * F_7 ( V_6 ) & V_66 ) )
break;
}
if ( V_64 )
* V_64 = V_65 ;
}
static void F_75 ( struct V_20 * V_31 )
{
F_20 ( & V_31 -> V_13 -> V_67 ) ;
F_9 ( V_31 -> V_68 <= 0 ) ;
V_31 -> V_68 ++ ;
}
static void F_76 ( struct V_20 * V_31 )
{
F_20 ( & V_31 -> V_13 -> V_67 ) ;
if ( F_59 ( -- V_31 -> V_68 ) )
return;
if ( F_9 ( ! ( V_31 -> V_22 -> V_30 & V_69 ) ) )
return;
F_77 ( & V_31 -> V_70 ) ;
}
static void F_78 ( struct V_20 * V_31 )
{
if ( V_31 ) {
F_79 ( & V_31 -> V_13 -> V_67 ) ;
F_76 ( V_31 ) ;
F_80 ( & V_31 -> V_13 -> V_67 ) ;
}
}
static void F_81 ( struct V_2 * V_6 )
{
struct V_20 * V_31 = F_37 ( V_6 ) ;
F_82 ( V_6 ) ;
F_72 ( V_6 , & V_31 -> V_13 -> V_41 , NULL ) ;
F_83 ( V_71 , F_7 ( V_6 ) ) ;
V_31 -> V_72 ++ ;
}
static void F_84 ( struct V_20 * V_31 )
{
struct V_2 * V_6 = F_57 ( & V_31 -> V_73 ,
struct V_2 , V_51 ) ;
F_81 ( V_6 ) ;
}
static void F_85 ( struct V_20 * V_31 , int V_25 )
{
if ( V_25 == V_74 )
goto V_75;
V_31 -> V_76 [ V_25 ] -- ;
V_31 -> V_72 -- ;
if ( ! F_48 ( & V_31 -> V_73 ) ) {
if ( V_31 -> V_72 < V_31 -> V_77 )
F_84 ( V_31 ) ;
}
if ( F_59 ( V_31 -> V_78 != V_25 ) )
goto V_75;
if ( V_31 -> V_76 [ V_25 ] )
goto V_75;
V_31 -> V_78 = - 1 ;
if ( F_66 ( & V_31 -> V_22 -> V_79 ) )
F_86 ( & V_31 -> V_22 -> V_80 -> V_81 ) ;
V_75:
F_76 ( V_31 ) ;
}
static int F_87 ( struct V_2 * V_6 , bool V_82 ,
unsigned long * V_30 )
{
struct V_12 * V_13 ;
struct V_20 * V_31 ;
F_88 ( * V_30 ) ;
if ( V_82 ) {
struct V_83 * V_84 = F_89 ( V_6 ) ;
if ( F_59 ( F_90 ( & V_84 -> V_85 ) ) )
return 1 ;
}
if ( ! F_91 ( V_86 , F_7 ( V_6 ) ) )
return 0 ;
V_13 = F_39 ( V_6 ) ;
if ( ! V_13 )
goto V_87;
F_92 ( & V_13 -> V_67 ) ;
V_31 = F_37 ( V_6 ) ;
if ( V_31 && V_31 -> V_13 == V_13 ) {
F_14 ( V_6 ) ;
if ( * F_7 ( V_6 ) & V_88 )
F_81 ( V_6 ) ;
F_93 ( & V_6 -> V_51 ) ;
F_85 ( F_37 ( V_6 ) , F_26 ( V_6 ) ) ;
F_33 ( V_6 , V_13 -> V_19 ) ;
F_94 ( & V_13 -> V_67 ) ;
return 1 ;
}
F_94 ( & V_13 -> V_67 ) ;
V_87:
F_95 ( * V_30 ) ;
if ( F_44 ( V_6 ) )
return - V_89 ;
F_96 () ;
return - V_90 ;
}
static void F_97 ( struct V_20 * V_31 , struct V_2 * V_6 ,
struct V_62 * V_63 , unsigned int V_32 )
{
struct V_12 * V_13 = V_31 -> V_13 ;
F_32 ( V_6 , V_31 , V_32 ) ;
F_98 ( & V_6 -> V_51 , V_63 ) ;
F_75 ( V_31 ) ;
F_99 () ;
if ( F_45 ( V_13 ) )
F_58 ( V_13 ) ;
}
static bool F_100 ( struct V_21 * V_22 )
{
struct V_50 * V_50 ;
V_50 = F_101 () ;
return V_50 && V_50 -> V_91 -> V_22 == V_22 ;
}
static void F_102 ( int V_54 , struct V_21 * V_22 ,
struct V_2 * V_6 )
{
struct V_20 * V_31 ;
struct V_12 * V_92 ;
struct V_62 * V_41 ;
unsigned int V_93 ;
unsigned int V_94 = V_54 ;
F_9 ( ! F_103 () ) ;
F_13 ( V_6 ) ;
if ( F_56 ( V_22 -> V_30 & V_95 ) &&
F_9 ( ! F_100 ( V_22 ) ) )
return;
V_96:
if ( V_94 == V_97 )
V_54 = F_65 () ;
if ( ! ( V_22 -> V_30 & V_69 ) )
V_31 = F_104 ( V_22 -> V_98 , V_54 ) ;
else
V_31 = F_22 ( V_22 , F_105 ( V_54 ) ) ;
V_92 = F_39 ( V_6 ) ;
if ( V_92 && V_92 != V_31 -> V_13 ) {
struct V_50 * V_50 ;
F_92 ( & V_92 -> V_67 ) ;
V_50 = F_70 ( V_92 , V_6 ) ;
if ( V_50 && V_50 -> V_91 -> V_22 == V_22 ) {
V_31 = V_50 -> V_91 ;
} else {
F_94 ( & V_92 -> V_67 ) ;
F_92 ( & V_31 -> V_13 -> V_67 ) ;
}
} else {
F_92 ( & V_31 -> V_13 -> V_67 ) ;
}
if ( F_56 ( ! V_31 -> V_68 ) ) {
if ( V_22 -> V_30 & V_69 ) {
F_94 ( & V_31 -> V_13 -> V_67 ) ;
F_96 () ;
goto V_96;
}
F_106 ( true , L_1 ,
V_22 -> V_99 , V_54 ) ;
}
F_107 ( V_94 , V_31 , V_6 ) ;
if ( F_10 ( ! F_48 ( & V_6 -> V_51 ) ) ) {
F_94 ( & V_31 -> V_13 -> V_67 ) ;
return;
}
V_31 -> V_76 [ V_31 -> V_100 ] ++ ;
V_93 = F_25 ( V_31 -> V_100 ) ;
if ( F_59 ( V_31 -> V_72 < V_31 -> V_77 ) ) {
F_82 ( V_6 ) ;
V_31 -> V_72 ++ ;
V_41 = & V_31 -> V_13 -> V_41 ;
} else {
V_93 |= V_88 ;
V_41 = & V_31 -> V_73 ;
}
F_97 ( V_31 , V_6 , V_41 , V_93 ) ;
F_94 ( & V_31 -> V_13 -> V_67 ) ;
}
bool F_108 ( int V_54 , struct V_21 * V_22 ,
struct V_2 * V_6 )
{
bool V_14 = false ;
unsigned long V_30 ;
F_88 ( V_30 ) ;
if ( ! F_91 ( V_86 , F_7 ( V_6 ) ) ) {
F_102 ( V_54 , V_22 , V_6 ) ;
V_14 = true ;
}
F_95 ( V_30 ) ;
return V_14 ;
}
void F_109 ( unsigned long V_101 )
{
struct V_83 * V_84 = (struct V_83 * ) V_101 ;
F_102 ( V_84 -> V_54 , V_84 -> V_22 , & V_84 -> V_6 ) ;
}
static void F_110 ( int V_54 , struct V_21 * V_22 ,
struct V_83 * V_84 , unsigned long V_102 )
{
struct V_103 * V_85 = & V_84 -> V_85 ;
struct V_2 * V_6 = & V_84 -> V_6 ;
F_9 ( V_85 -> V_104 != F_109 ||
V_85 -> V_29 != ( unsigned long ) V_84 ) ;
F_9 ( F_111 ( V_85 ) ) ;
F_9 ( ! F_48 ( & V_6 -> V_51 ) ) ;
if ( ! V_102 ) {
F_102 ( V_54 , V_22 , & V_84 -> V_6 ) ;
return;
}
F_112 ( & V_84 -> V_85 ) ;
V_84 -> V_22 = V_22 ;
V_84 -> V_54 = V_54 ;
V_85 -> V_105 = V_106 + V_102 ;
if ( F_56 ( V_54 != V_97 ) )
F_113 ( V_85 , V_54 ) ;
else
F_114 ( V_85 ) ;
}
bool F_115 ( int V_54 , struct V_21 * V_22 ,
struct V_83 * V_84 , unsigned long V_102 )
{
struct V_2 * V_6 = & V_84 -> V_6 ;
bool V_14 = false ;
unsigned long V_30 ;
F_88 ( V_30 ) ;
if ( ! F_91 ( V_86 , F_7 ( V_6 ) ) ) {
F_110 ( V_54 , V_22 , V_84 , V_102 ) ;
V_14 = true ;
}
F_95 ( V_30 ) ;
return V_14 ;
}
bool F_116 ( int V_54 , struct V_21 * V_22 ,
struct V_83 * V_84 , unsigned long V_102 )
{
unsigned long V_30 ;
int V_14 ;
do {
V_14 = F_87 ( & V_84 -> V_6 , true , & V_30 ) ;
} while ( F_56 ( V_14 == - V_90 ) );
if ( F_59 ( V_14 >= 0 ) ) {
F_110 ( V_54 , V_22 , V_84 , V_102 ) ;
F_95 ( V_30 ) ;
}
return V_14 ;
}
static void F_117 ( struct V_50 * V_50 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
if ( F_9 ( V_50 -> V_30 & V_107 ) ||
F_9 ( ! F_48 ( & V_50 -> V_51 ) &&
( V_50 -> V_108 . V_109 || V_50 -> V_108 . V_110 ) ) )
return;
V_50 -> V_30 |= V_107 ;
V_13 -> V_42 ++ ;
V_50 -> V_111 = V_106 ;
F_118 ( & V_50 -> V_51 , & V_13 -> V_48 ) ;
if ( F_53 ( V_13 ) && ! F_111 ( & V_13 -> V_112 ) )
F_119 ( & V_13 -> V_112 , V_106 + V_113 ) ;
F_9 ( ! ( V_13 -> V_30 & V_114 ) &&
V_13 -> V_47 == V_13 -> V_42 &&
F_46 ( & V_13 -> V_40 ) ) ;
}
static void F_120 ( struct V_50 * V_50 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
if ( F_9 ( ! ( V_50 -> V_30 & V_107 ) ) )
return;
F_69 ( V_50 , V_107 ) ;
V_13 -> V_42 -- ;
F_93 ( & V_50 -> V_51 ) ;
}
static bool F_121 ( struct V_12 * V_13 )
__acquires( &pool->lock
static struct V_50 * F_122 ( void )
{
struct V_50 * V_50 ;
V_50 = F_123 ( sizeof( * V_50 ) , V_18 ) ;
if ( V_50 ) {
F_124 ( & V_50 -> V_51 ) ;
F_124 ( & V_50 -> V_115 ) ;
V_50 -> V_30 = V_116 ;
}
return V_50 ;
}
static struct V_50 * F_125 ( struct V_12 * V_13 )
{
struct V_50 * V_50 = NULL ;
int V_19 = - 1 ;
char V_117 [ 16 ] ;
F_20 ( & V_13 -> V_118 ) ;
F_126 ( V_18 ) ;
F_79 ( & V_13 -> V_67 ) ;
V_19 = F_21 ( & V_13 -> V_119 , NULL , 0 , 0 , V_120 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_127 () ;
if ( V_19 < 0 )
goto V_87;
V_50 = F_122 () ;
if ( ! V_50 )
goto V_87;
V_50 -> V_13 = V_13 ;
V_50 -> V_19 = V_19 ;
if ( V_13 -> V_54 >= 0 )
snprintf ( V_117 , sizeof( V_117 ) , L_2 , V_13 -> V_54 , V_19 ,
V_13 -> V_121 -> V_122 < 0 ? L_3 : L_4 ) ;
else
snprintf ( V_117 , sizeof( V_117 ) , L_5 , V_13 -> V_19 , V_19 ) ;
V_50 -> V_52 = F_128 ( V_123 , V_50 , V_13 -> V_23 ,
L_6 , V_117 ) ;
if ( F_129 ( V_50 -> V_52 ) )
goto V_87;
F_130 ( V_50 -> V_52 , V_13 -> V_121 -> V_122 ) ;
V_50 -> V_52 -> V_30 |= V_124 ;
F_131 ( V_50 -> V_52 , V_13 -> V_121 -> V_125 ) ;
if ( V_13 -> V_30 & V_114 )
V_50 -> V_30 |= V_126 ;
F_79 ( & V_13 -> V_67 ) ;
F_132 ( & V_13 -> V_119 , V_50 , V_50 -> V_19 ) ;
F_80 ( & V_13 -> V_67 ) ;
return V_50 ;
V_87:
if ( V_19 >= 0 ) {
F_79 ( & V_13 -> V_67 ) ;
F_133 ( & V_13 -> V_119 , V_19 ) ;
F_80 ( & V_13 -> V_67 ) ;
}
F_134 ( V_50 ) ;
return NULL ;
}
static void F_135 ( struct V_50 * V_50 )
{
V_50 -> V_30 |= V_127 ;
V_50 -> V_13 -> V_47 ++ ;
F_117 ( V_50 ) ;
F_60 ( V_50 -> V_52 ) ;
}
static int F_136 ( struct V_12 * V_13 )
{
struct V_50 * V_50 ;
F_137 ( & V_13 -> V_118 ) ;
V_50 = F_125 ( V_13 ) ;
if ( V_50 ) {
F_79 ( & V_13 -> V_67 ) ;
F_135 ( V_50 ) ;
F_80 ( & V_13 -> V_67 ) ;
}
F_138 ( & V_13 -> V_118 ) ;
return V_50 ? 0 : - V_128 ;
}
static void F_139 ( struct V_50 * V_50 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
F_20 ( & V_13 -> V_118 ) ;
F_20 ( & V_13 -> V_67 ) ;
if ( F_10 ( V_50 -> V_60 ) ||
F_10 ( ! F_48 ( & V_50 -> V_115 ) ) )
return;
if ( V_50 -> V_30 & V_127 )
V_13 -> V_47 -- ;
if ( V_50 -> V_30 & V_107 )
V_13 -> V_42 -- ;
F_140 ( V_50 -> V_52 ) ;
F_93 ( & V_50 -> V_51 ) ;
V_50 -> V_30 |= V_129 ;
F_133 ( & V_13 -> V_119 , V_50 -> V_19 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_141 ( V_50 -> V_52 ) ;
F_142 ( V_50 -> V_52 ) ;
F_134 ( V_50 ) ;
F_79 ( & V_13 -> V_67 ) ;
}
static void F_143 ( unsigned long V_130 )
{
struct V_12 * V_13 = ( void * ) V_130 ;
F_79 ( & V_13 -> V_67 ) ;
if ( F_53 ( V_13 ) ) {
struct V_50 * V_50 ;
unsigned long V_105 ;
V_50 = F_144 ( V_13 -> V_48 . V_131 , struct V_50 , V_51 ) ;
V_105 = V_50 -> V_111 + V_113 ;
if ( F_145 ( V_106 , V_105 ) )
F_119 ( & V_13 -> V_112 , V_105 ) ;
else {
V_13 -> V_30 |= V_43 ;
F_58 ( V_13 ) ;
}
}
F_80 ( & V_13 -> V_67 ) ;
}
static void F_146 ( struct V_2 * V_6 )
{
struct V_20 * V_31 = F_37 ( V_6 ) ;
struct V_21 * V_22 = V_31 -> V_22 ;
F_20 ( & V_132 ) ;
if ( ! V_22 -> V_133 )
return;
if ( F_48 ( & V_31 -> V_134 ) ) {
F_98 ( & V_31 -> V_134 , & V_22 -> V_135 ) ;
F_60 ( V_22 -> V_133 -> V_52 ) ;
}
}
static void F_147 ( unsigned long V_130 )
{
struct V_12 * V_13 = ( void * ) V_130 ;
struct V_2 * V_6 ;
F_79 ( & V_132 ) ;
F_92 ( & V_13 -> V_67 ) ;
if ( F_51 ( V_13 ) ) {
F_148 (work, &pool->worklist, entry)
F_146 ( V_6 ) ;
}
F_94 ( & V_13 -> V_67 ) ;
F_80 ( & V_132 ) ;
F_119 ( & V_13 -> V_136 , V_106 + V_137 ) ;
}
static bool F_149 ( struct V_12 * V_13 )
__releases( &pool->lock
static bool F_150 ( struct V_12 * V_13 )
{
bool V_14 = false ;
while ( F_53 ( V_13 ) ) {
struct V_50 * V_50 ;
unsigned long V_105 ;
V_50 = F_144 ( V_13 -> V_48 . V_131 , struct V_50 , V_51 ) ;
V_105 = V_50 -> V_111 + V_113 ;
if ( F_145 ( V_106 , V_105 ) ) {
F_119 ( & V_13 -> V_112 , V_105 ) ;
break;
}
F_139 ( V_50 ) ;
V_14 = true ;
}
return V_14 ;
}
static bool F_151 ( struct V_50 * V_50 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
bool V_14 = false ;
if ( ! F_152 ( & V_13 -> V_45 ) )
return V_14 ;
if ( F_56 ( ! F_152 ( & V_13 -> V_118 ) ) ) {
F_80 ( & V_13 -> V_67 ) ;
F_137 ( & V_13 -> V_118 ) ;
F_79 ( & V_13 -> V_67 ) ;
V_14 = true ;
}
V_13 -> V_30 &= ~ V_43 ;
V_14 |= F_150 ( V_13 ) ;
V_14 |= F_149 ( V_13 ) ;
F_138 ( & V_13 -> V_118 ) ;
F_138 ( & V_13 -> V_45 ) ;
return V_14 ;
}
static void F_153 ( struct V_50 * V_50 , struct V_2 * V_6 )
__releases( &pool->lock
static void F_154 ( struct V_50 * V_50 )
{
while ( ! F_48 ( & V_50 -> V_115 ) ) {
struct V_2 * V_6 = F_57 ( & V_50 -> V_115 ,
struct V_2 , V_51 ) ;
F_153 ( V_50 , V_6 ) ;
}
}
static int V_123 ( void * V_138 )
{
struct V_50 * V_50 = V_138 ;
struct V_12 * V_13 = V_50 -> V_13 ;
V_50 -> V_52 -> V_30 |= V_139 ;
V_140:
F_79 ( & V_13 -> V_67 ) ;
if ( F_56 ( V_50 -> V_30 & V_129 ) ) {
F_80 ( & V_13 -> V_67 ) ;
F_9 ( ! F_48 ( & V_50 -> V_51 ) ) ;
V_50 -> V_52 -> V_30 &= ~ V_139 ;
return 0 ;
}
F_120 ( V_50 ) ;
V_141:
if ( ! F_47 ( V_13 ) )
goto V_142;
if ( F_56 ( ! F_49 ( V_13 ) ) && F_151 ( V_50 ) )
goto V_141;
F_9 ( ! F_48 ( & V_50 -> V_115 ) ) ;
F_69 ( V_50 , V_116 | V_143 ) ;
do {
struct V_2 * V_6 =
F_57 ( & V_13 -> V_41 ,
struct V_2 , V_51 ) ;
if ( F_59 ( ! ( * F_7 ( V_6 ) & V_66 ) ) ) {
F_153 ( V_50 , V_6 ) ;
if ( F_56 ( ! F_48 ( & V_50 -> V_115 ) ) )
F_154 ( V_50 ) ;
} else {
F_72 ( V_6 , & V_50 -> V_115 , NULL ) ;
F_154 ( V_50 ) ;
}
} while ( F_50 ( V_13 ) );
F_67 ( V_50 , V_116 , false ) ;
V_142:
if ( F_56 ( F_52 ( V_13 ) ) && F_151 ( V_50 ) )
goto V_141;
F_117 ( V_50 ) ;
F_155 ( V_144 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_156 () ;
goto V_140;
}
static int F_157 ( void * V_145 )
{
struct V_50 * V_133 = V_145 ;
struct V_21 * V_22 = V_133 -> V_146 ;
struct V_62 * V_115 = & V_133 -> V_115 ;
F_130 ( V_58 , V_147 ) ;
V_133 -> V_52 -> V_30 |= V_139 ;
V_148:
F_158 ( V_144 ) ;
if ( F_159 () ) {
F_155 ( V_149 ) ;
V_133 -> V_52 -> V_30 &= ~ V_139 ;
return 0 ;
}
F_79 ( & V_132 ) ;
while ( ! F_48 ( & V_22 -> V_135 ) ) {
struct V_20 * V_31 = F_57 ( & V_22 -> V_135 ,
struct V_20 , V_134 ) ;
struct V_12 * V_13 = V_31 -> V_13 ;
struct V_2 * V_6 , * V_65 ;
F_155 ( V_149 ) ;
F_93 ( & V_31 -> V_134 ) ;
F_80 ( & V_132 ) ;
F_121 ( V_13 ) ;
V_133 -> V_13 = V_13 ;
F_9 ( ! F_48 ( & V_133 -> V_115 ) ) ;
F_160 (work, n, &pool->worklist, entry)
if ( F_37 ( V_6 ) == V_31 )
F_72 ( V_6 , V_115 , & V_65 ) ;
F_154 ( V_133 ) ;
if ( F_50 ( V_13 ) )
F_58 ( V_13 ) ;
V_133 -> V_13 = NULL ;
F_94 ( & V_13 -> V_67 ) ;
F_92 ( & V_132 ) ;
}
F_80 ( & V_132 ) ;
F_9 ( ! ( V_133 -> V_30 & V_55 ) ) ;
F_156 () ;
goto V_148;
}
static void F_161 ( struct V_2 * V_6 )
{
struct V_150 * V_151 = F_162 ( V_6 , struct V_150 , V_6 ) ;
F_86 ( & V_151 -> V_81 ) ;
}
static void F_163 ( struct V_20 * V_31 ,
struct V_150 * V_151 ,
struct V_2 * V_152 , struct V_50 * V_50 )
{
struct V_62 * V_63 ;
unsigned int V_153 = 0 ;
F_164 ( & V_151 -> V_6 , F_161 ) ;
F_165 ( V_86 , F_7 ( & V_151 -> V_6 ) ) ;
F_166 ( & V_151 -> V_81 ) ;
if ( V_50 )
V_63 = V_50 -> V_115 . V_109 ;
else {
unsigned long * V_154 = F_7 ( V_152 ) ;
V_63 = V_152 -> V_51 . V_109 ;
V_153 = * V_154 & V_66 ;
F_165 ( V_155 , V_154 ) ;
}
F_13 ( & V_151 -> V_6 ) ;
F_97 ( V_31 , & V_151 -> V_6 , V_63 ,
F_25 ( V_74 ) | V_153 ) ;
}
static bool F_167 ( struct V_21 * V_22 ,
int V_78 , int V_100 )
{
bool V_156 = false ;
struct V_20 * V_31 ;
if ( V_78 >= 0 ) {
F_9 ( F_46 ( & V_22 -> V_79 ) ) ;
F_168 ( & V_22 -> V_79 , 1 ) ;
}
F_169 (pwq, wq) {
struct V_12 * V_13 = V_31 -> V_13 ;
F_79 ( & V_13 -> V_67 ) ;
if ( V_78 >= 0 ) {
F_9 ( V_31 -> V_78 != - 1 ) ;
if ( V_31 -> V_76 [ V_78 ] ) {
V_31 -> V_78 = V_78 ;
F_63 ( & V_22 -> V_79 ) ;
V_156 = true ;
}
}
if ( V_100 >= 0 ) {
F_9 ( V_100 != F_27 ( V_31 -> V_100 ) ) ;
V_31 -> V_100 = V_100 ;
}
F_80 ( & V_13 -> V_67 ) ;
}
if ( V_78 >= 0 && F_66 ( & V_22 -> V_79 ) )
F_86 ( & V_22 -> V_80 -> V_81 ) ;
return V_156 ;
}
void F_170 ( struct V_21 * V_22 )
{
struct V_157 V_158 = {
. V_159 = F_171 ( V_158 . V_159 ) ,
. V_78 = - 1 ,
. V_81 = F_172 ( V_158 . V_81 ) ,
} ;
int V_160 ;
F_173 ( & V_22 -> V_161 ) ;
F_174 ( & V_22 -> V_161 ) ;
F_137 ( & V_22 -> V_162 ) ;
V_160 = F_27 ( V_22 -> V_100 ) ;
if ( V_160 != V_22 -> V_78 ) {
F_9 ( ! F_48 ( & V_22 -> V_163 ) ) ;
V_158 . V_78 = V_22 -> V_100 ;
V_22 -> V_100 = V_160 ;
if ( ! V_22 -> V_80 ) {
F_9 ( V_22 -> V_78 != V_158 . V_78 ) ;
V_22 -> V_80 = & V_158 ;
if ( ! F_167 ( V_22 , V_22 -> V_78 ,
V_22 -> V_100 ) ) {
V_22 -> V_78 = V_160 ;
V_22 -> V_80 = NULL ;
goto V_164;
}
} else {
F_9 ( V_22 -> V_78 == V_158 . V_78 ) ;
F_98 ( & V_158 . V_159 , & V_22 -> V_165 ) ;
F_167 ( V_22 , - 1 , V_22 -> V_100 ) ;
}
} else {
F_98 ( & V_158 . V_159 , & V_22 -> V_163 ) ;
}
F_138 ( & V_22 -> V_162 ) ;
F_175 ( & V_158 . V_81 ) ;
if ( V_22 -> V_80 != & V_158 )
return;
F_137 ( & V_22 -> V_162 ) ;
if ( V_22 -> V_80 != & V_158 )
goto V_164;
V_22 -> V_80 = NULL ;
F_9 ( ! F_48 ( & V_158 . V_159 ) ) ;
F_9 ( V_22 -> V_78 != V_158 . V_78 ) ;
while ( true ) {
struct V_157 * V_109 , * V_166 ;
F_160 (next, tmp, &wq->flusher_queue, list) {
if ( V_109 -> V_78 != V_22 -> V_78 )
break;
F_93 ( & V_109 -> V_159 ) ;
F_86 ( & V_109 -> V_81 ) ;
}
F_9 ( ! F_48 ( & V_22 -> V_163 ) &&
V_22 -> V_78 != F_27 ( V_22 -> V_100 ) ) ;
V_22 -> V_78 = F_27 ( V_22 -> V_78 ) ;
if ( ! F_48 ( & V_22 -> V_163 ) ) {
F_148 (tmp, &wq->flusher_overflow, list)
V_166 -> V_78 = V_22 -> V_100 ;
V_22 -> V_100 = F_27 ( V_22 -> V_100 ) ;
F_176 ( & V_22 -> V_163 ,
& V_22 -> V_165 ) ;
F_167 ( V_22 , - 1 , V_22 -> V_100 ) ;
}
if ( F_48 ( & V_22 -> V_165 ) ) {
F_9 ( V_22 -> V_78 != V_22 -> V_100 ) ;
break;
}
F_9 ( V_22 -> V_78 == V_22 -> V_100 ) ;
F_9 ( V_22 -> V_78 != V_109 -> V_78 ) ;
F_93 ( & V_109 -> V_159 ) ;
V_22 -> V_80 = V_109 ;
if ( F_167 ( V_22 , V_22 -> V_78 , - 1 ) )
break;
V_22 -> V_80 = NULL ;
}
V_164:
F_138 ( & V_22 -> V_162 ) ;
}
void F_177 ( struct V_21 * V_22 )
{
unsigned int V_167 = 0 ;
struct V_20 * V_31 ;
F_137 ( & V_22 -> V_162 ) ;
if ( ! V_22 -> V_168 ++ )
V_22 -> V_30 |= V_95 ;
F_138 ( & V_22 -> V_162 ) ;
V_169:
F_170 ( V_22 ) ;
F_137 ( & V_22 -> V_162 ) ;
F_169 (pwq, wq) {
bool V_170 ;
F_79 ( & V_31 -> V_13 -> V_67 ) ;
V_170 = ! V_31 -> V_72 && F_48 ( & V_31 -> V_73 ) ;
F_80 ( & V_31 -> V_13 -> V_67 ) ;
if ( V_170 )
continue;
if ( ++ V_167 == 10 ||
( V_167 % 100 == 0 && V_167 <= 1000 ) )
F_178 ( L_7 ,
V_22 -> V_99 , V_167 ) ;
F_138 ( & V_22 -> V_162 ) ;
goto V_169;
}
if ( ! -- V_22 -> V_168 )
V_22 -> V_30 &= ~ V_95 ;
F_138 ( & V_22 -> V_162 ) ;
}
static bool F_179 ( struct V_2 * V_6 , struct V_150 * V_151 )
{
struct V_50 * V_50 = NULL ;
struct V_12 * V_13 ;
struct V_20 * V_31 ;
F_180 () ;
F_181 () ;
V_13 = F_39 ( V_6 ) ;
if ( ! V_13 ) {
F_182 () ;
return false ;
}
F_92 ( & V_13 -> V_67 ) ;
V_31 = F_37 ( V_6 ) ;
if ( V_31 ) {
if ( F_56 ( V_31 -> V_13 != V_13 ) )
goto V_171;
} else {
V_50 = F_70 ( V_13 , V_6 ) ;
if ( ! V_50 )
goto V_171;
V_31 = V_50 -> V_91 ;
}
F_163 ( V_31 , V_151 , V_6 , V_50 ) ;
F_80 ( & V_13 -> V_67 ) ;
if ( V_31 -> V_22 -> V_172 == 1 || V_31 -> V_22 -> V_133 )
F_173 ( & V_31 -> V_22 -> V_161 ) ;
else
F_183 ( & V_31 -> V_22 -> V_161 ) ;
F_174 ( & V_31 -> V_22 -> V_161 ) ;
return true ;
V_171:
F_80 ( & V_13 -> V_67 ) ;
return false ;
}
bool F_184 ( struct V_2 * V_6 )
{
struct V_150 V_151 ;
F_173 ( & V_6 -> V_161 ) ;
F_174 ( & V_6 -> V_161 ) ;
if ( F_179 ( V_6 , & V_151 ) ) {
F_175 ( & V_151 . V_81 ) ;
F_18 ( & V_151 . V_6 ) ;
return true ;
} else {
return false ;
}
}
static bool F_185 ( struct V_2 * V_6 , bool V_82 )
{
unsigned long V_30 ;
int V_14 ;
do {
V_14 = F_87 ( V_6 , V_82 , & V_30 ) ;
if ( F_56 ( V_14 == - V_89 ) )
F_184 ( V_6 ) ;
} while ( F_56 ( V_14 < 0 ) );
F_43 ( V_6 ) ;
F_95 ( V_30 ) ;
F_184 ( V_6 ) ;
F_36 ( V_6 ) ;
return V_14 ;
}
bool F_3 ( struct V_2 * V_6 )
{
return F_185 ( V_6 , false ) ;
}
bool F_186 ( struct V_83 * V_84 )
{
F_181 () ;
if ( F_187 ( & V_84 -> V_85 ) )
F_102 ( V_84 -> V_54 , V_84 -> V_22 , & V_84 -> V_6 ) ;
F_182 () ;
return F_184 ( & V_84 -> V_6 ) ;
}
bool F_188 ( struct V_83 * V_84 )
{
unsigned long V_30 ;
int V_14 ;
do {
V_14 = F_87 ( & V_84 -> V_6 , true , & V_30 ) ;
} while ( F_56 ( V_14 == - V_90 ) );
if ( F_56 ( V_14 < 0 ) )
return false ;
F_34 ( & V_84 -> V_6 ,
F_42 ( & V_84 -> V_6 ) ) ;
F_95 ( V_30 ) ;
return V_14 ;
}
bool F_189 ( struct V_83 * V_84 )
{
return F_185 ( & V_84 -> V_6 , true ) ;
}
int F_190 ( T_1 V_3 )
{
int V_54 ;
struct V_2 T_2 * V_173 ;
V_173 = F_191 ( struct V_2 ) ;
if ( ! V_173 )
return - V_128 ;
F_192 () ;
F_193 (cpu) {
struct V_2 * V_6 = F_104 ( V_173 , V_54 ) ;
F_194 ( V_6 , V_3 ) ;
F_195 ( V_54 , V_6 ) ;
}
F_193 (cpu)
F_184 ( F_104 ( V_173 , V_54 ) ) ;
F_196 () ;
F_197 ( V_173 ) ;
return 0 ;
}
void F_198 ( void )
{
F_170 ( V_174 ) ;
}
int F_199 ( T_1 V_175 , struct V_176 * V_177 )
{
if ( ! F_200 () ) {
V_175 ( & V_177 -> V_6 ) ;
return 0 ;
}
F_194 ( & V_177 -> V_6 , V_175 ) ;
F_77 ( & V_177 -> V_6 ) ;
return 1 ;
}
static struct V_21 * F_201 ( struct V_178 * V_179 )
{
struct V_180 * V_181 = F_162 ( V_179 , struct V_180 , V_179 ) ;
return V_181 -> V_22 ;
}
static T_3 F_202 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
return F_203 ( V_184 , V_185 , L_8 , ( bool ) ! ( V_22 -> V_30 & V_69 ) ) ;
}
static T_3 F_204 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
return F_203 ( V_184 , V_185 , L_8 , V_22 -> V_172 ) ;
}
static T_3 F_205 ( struct V_178 * V_179 ,
struct V_182 * V_183 , const char * V_184 ,
T_4 V_186 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
int V_187 ;
if ( sscanf ( V_184 , L_9 , & V_187 ) != 1 || V_187 <= 0 )
return - V_188 ;
F_206 ( V_22 , V_187 ) ;
return V_186 ;
}
static T_3 F_207 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
const char * V_189 = L_4 ;
int V_23 , V_190 = 0 ;
F_208 () ;
F_209 (node) {
V_190 += F_203 ( V_184 + V_190 , V_185 - V_190 ,
L_10 , V_189 , V_23 ,
F_22 ( V_22 , V_23 ) -> V_13 -> V_19 ) ;
V_189 = L_11 ;
}
V_190 += F_203 ( V_184 + V_190 , V_185 - V_190 , L_12 ) ;
F_210 () ;
return V_190 ;
}
static T_3 F_211 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
int V_190 ;
F_137 ( & V_22 -> V_162 ) ;
V_190 = F_203 ( V_184 , V_185 , L_8 , V_22 -> V_191 -> V_122 ) ;
F_138 ( & V_22 -> V_162 ) ;
return V_190 ;
}
static struct V_192 * F_212 ( struct V_21 * V_22 )
{
struct V_192 * V_121 ;
V_121 = F_213 ( V_18 ) ;
if ( ! V_121 )
return NULL ;
F_137 ( & V_22 -> V_162 ) ;
F_214 ( V_121 , V_22 -> V_191 ) ;
F_138 ( & V_22 -> V_162 ) ;
return V_121 ;
}
static T_3 F_215 ( struct V_178 * V_179 , struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
struct V_192 * V_121 ;
int V_14 ;
V_121 = F_212 ( V_22 ) ;
if ( ! V_121 )
return - V_128 ;
if ( sscanf ( V_184 , L_9 , & V_121 -> V_122 ) == 1 &&
V_121 -> V_122 >= - 20 && V_121 -> V_122 <= 19 )
V_14 = F_216 ( V_22 , V_121 ) ;
else
V_14 = - V_188 ;
F_217 ( V_121 ) ;
return V_14 ? : V_186 ;
}
static T_3 F_218 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
int V_190 ;
F_137 ( & V_22 -> V_162 ) ;
V_190 = F_219 ( V_184 , V_185 , V_22 -> V_191 -> V_125 ) ;
F_138 ( & V_22 -> V_162 ) ;
V_190 += F_203 ( V_184 + V_190 , V_185 - V_190 , L_12 ) ;
return V_190 ;
}
static T_3 F_220 ( struct V_178 * V_179 ,
struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
struct V_192 * V_121 ;
int V_14 ;
V_121 = F_212 ( V_22 ) ;
if ( ! V_121 )
return - V_128 ;
V_14 = F_221 ( V_184 , V_121 -> V_125 ) ;
if ( ! V_14 )
V_14 = F_216 ( V_22 , V_121 ) ;
F_217 ( V_121 ) ;
return V_14 ? : V_186 ;
}
static T_3 F_222 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
int V_190 ;
F_137 ( & V_22 -> V_162 ) ;
V_190 = F_203 ( V_184 , V_185 , L_8 ,
! V_22 -> V_191 -> V_193 ) ;
F_138 ( & V_22 -> V_162 ) ;
return V_190 ;
}
static T_3 F_223 ( struct V_178 * V_179 , struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_21 * V_22 = F_201 ( V_179 ) ;
struct V_192 * V_121 ;
int V_194 , V_14 ;
V_121 = F_212 ( V_22 ) ;
if ( ! V_121 )
return - V_128 ;
V_14 = - V_188 ;
if ( sscanf ( V_184 , L_9 , & V_194 ) == 1 ) {
V_121 -> V_193 = ! V_194 ;
V_14 = F_216 ( V_22 , V_121 ) ;
}
F_217 ( V_121 ) ;
return V_14 ? : V_186 ;
}
static int T_5 F_224 ( void )
{
return F_225 ( & V_195 , NULL ) ;
}
static void F_226 ( struct V_178 * V_179 )
{
struct V_180 * V_181 = F_162 ( V_179 , struct V_180 , V_179 ) ;
F_134 ( V_181 ) ;
}
int F_227 ( struct V_21 * V_22 )
{
struct V_180 * V_181 ;
int V_14 ;
if ( F_10 ( V_22 -> V_30 & V_196 ) )
return - V_188 ;
V_22 -> V_181 = V_181 = F_123 ( sizeof( * V_181 ) , V_18 ) ;
if ( ! V_181 )
return - V_128 ;
V_181 -> V_22 = V_22 ;
V_181 -> V_179 . V_197 = & V_195 ;
V_181 -> V_179 . V_198 = V_22 -> V_99 ;
V_181 -> V_179 . V_199 = F_226 ;
F_228 ( & V_181 -> V_179 , true ) ;
V_14 = F_229 ( & V_181 -> V_179 ) ;
if ( V_14 ) {
F_134 ( V_181 ) ;
V_22 -> V_181 = NULL ;
return V_14 ;
}
if ( V_22 -> V_30 & V_69 ) {
struct V_182 * V_183 ;
for ( V_183 = V_200 ; V_183 -> V_183 . V_99 ; V_183 ++ ) {
V_14 = F_230 ( & V_181 -> V_179 , V_183 ) ;
if ( V_14 ) {
F_231 ( & V_181 -> V_179 ) ;
V_22 -> V_181 = NULL ;
return V_14 ;
}
}
}
F_232 ( & V_181 -> V_179 . V_201 , V_202 ) ;
return 0 ;
}
static void F_233 ( struct V_21 * V_22 )
{
struct V_180 * V_181 = V_22 -> V_181 ;
if ( ! V_22 -> V_181 )
return;
V_22 -> V_181 = NULL ;
F_231 ( & V_181 -> V_179 ) ;
}
static void F_233 ( struct V_21 * V_22 ) { }
void F_217 ( struct V_192 * V_121 )
{
if ( V_121 ) {
F_234 ( V_121 -> V_125 ) ;
F_134 ( V_121 ) ;
}
}
struct V_192 * F_213 ( T_6 V_203 )
{
struct V_192 * V_121 ;
V_121 = F_123 ( sizeof( * V_121 ) , V_203 ) ;
if ( ! V_121 )
goto V_87;
if ( ! F_235 ( & V_121 -> V_125 , V_203 ) )
goto V_87;
F_236 ( V_121 -> V_125 , V_204 ) ;
return V_121 ;
V_87:
F_217 ( V_121 ) ;
return NULL ;
}
static void F_214 ( struct V_192 * V_205 ,
const struct V_192 * V_206 )
{
V_205 -> V_122 = V_206 -> V_122 ;
F_236 ( V_205 -> V_125 , V_206 -> V_125 ) ;
V_205 -> V_193 = V_206 -> V_193 ;
}
static T_7 F_237 ( const struct V_192 * V_121 )
{
T_7 V_207 = 0 ;
V_207 = F_238 ( V_121 -> V_122 , V_207 ) ;
V_207 = F_239 ( F_240 ( V_121 -> V_125 ) ,
F_241 ( V_208 ) * sizeof( long ) , V_207 ) ;
return V_207 ;
}
static bool F_242 ( const struct V_192 * V_209 ,
const struct V_192 * V_210 )
{
if ( V_209 -> V_122 != V_210 -> V_122 )
return false ;
if ( ! F_243 ( V_209 -> V_125 , V_210 -> V_125 ) )
return false ;
return true ;
}
static int F_244 ( struct V_12 * V_13 )
{
F_245 ( & V_13 -> V_67 ) ;
V_13 -> V_19 = - 1 ;
V_13 -> V_54 = - 1 ;
V_13 -> V_23 = V_211 ;
V_13 -> V_30 |= V_114 ;
F_124 ( & V_13 -> V_41 ) ;
F_124 ( & V_13 -> V_48 ) ;
F_246 ( V_13 -> V_212 ) ;
F_247 ( & V_13 -> V_112 ) ;
V_13 -> V_112 . V_104 = F_143 ;
V_13 -> V_112 . V_29 = ( unsigned long ) V_13 ;
F_248 ( & V_13 -> V_136 , F_147 ,
( unsigned long ) V_13 ) ;
F_249 ( & V_13 -> V_45 ) ;
F_249 ( & V_13 -> V_118 ) ;
F_250 ( & V_13 -> V_119 ) ;
F_251 ( & V_13 -> V_213 ) ;
V_13 -> V_68 = 1 ;
V_13 -> V_121 = F_213 ( V_18 ) ;
if ( ! V_13 -> V_121 )
return - V_128 ;
return 0 ;
}
static void F_252 ( struct V_214 * V_215 )
{
struct V_12 * V_13 = F_162 ( V_215 , struct V_12 , V_215 ) ;
F_253 ( & V_13 -> V_119 ) ;
F_217 ( V_13 -> V_121 ) ;
F_134 ( V_13 ) ;
}
static void F_254 ( struct V_12 * V_13 )
{
struct V_50 * V_50 ;
F_20 ( & V_15 ) ;
if ( -- V_13 -> V_68 )
return;
if ( F_10 ( ! ( V_13 -> V_30 & V_114 ) ) ||
F_10 ( ! F_48 ( & V_13 -> V_41 ) ) )
return;
if ( V_13 -> V_19 >= 0 )
F_133 ( & V_16 , V_13 -> V_19 ) ;
F_255 ( & V_13 -> V_213 ) ;
F_137 ( & V_13 -> V_45 ) ;
F_137 ( & V_13 -> V_118 ) ;
F_79 ( & V_13 -> V_67 ) ;
while ( ( V_50 = F_55 ( V_13 ) ) )
F_139 ( V_50 ) ;
F_10 ( V_13 -> V_47 || V_13 -> V_42 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_138 ( & V_13 -> V_118 ) ;
F_138 ( & V_13 -> V_45 ) ;
F_187 ( & V_13 -> V_112 ) ;
F_187 ( & V_13 -> V_136 ) ;
F_256 ( & V_13 -> V_215 , F_252 ) ;
}
static struct V_12 * F_257 ( const struct V_192 * V_121 )
{
T_7 V_207 = F_237 ( V_121 ) ;
struct V_12 * V_13 ;
int V_23 ;
F_20 ( & V_15 ) ;
F_71 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_242 ( V_13 -> V_121 , V_121 ) ) {
V_13 -> V_68 ++ ;
goto V_164;
}
}
V_13 = F_123 ( sizeof( * V_13 ) , V_18 ) ;
if ( ! V_13 || F_244 ( V_13 ) < 0 )
goto V_87;
if ( V_216 )
V_13 -> V_30 |= V_217 ;
F_258 ( & V_13 -> V_67 , 1 ) ;
F_214 ( V_13 -> V_121 , V_121 ) ;
V_13 -> V_121 -> V_193 = false ;
if ( V_218 ) {
F_209 (node) {
if ( F_259 ( V_13 -> V_121 -> V_125 ,
V_219 [ V_23 ] ) ) {
V_13 -> V_23 = V_23 ;
break;
}
}
}
if ( F_19 ( V_13 ) < 0 )
goto V_87;
if ( F_136 ( V_13 ) < 0 )
goto V_87;
F_260 ( V_220 , & V_13 -> V_213 , V_207 ) ;
V_164:
return V_13 ;
V_87:
if ( V_13 )
F_254 ( V_13 ) ;
return NULL ;
}
static void F_261 ( struct V_214 * V_215 )
{
F_262 ( V_221 ,
F_162 ( V_215 , struct V_20 , V_215 ) ) ;
}
static void F_263 ( struct V_2 * V_6 )
{
struct V_20 * V_31 = F_162 ( V_6 , struct V_20 ,
V_70 ) ;
struct V_21 * V_22 = V_31 -> V_22 ;
struct V_12 * V_13 = V_31 -> V_13 ;
bool V_222 ;
if ( F_9 ( ! ( V_22 -> V_30 & V_69 ) ) )
return;
F_137 ( & V_22 -> V_162 ) ;
F_264 ( & V_31 -> V_223 ) ;
V_222 = F_48 ( & V_22 -> V_224 ) ;
F_138 ( & V_22 -> V_162 ) ;
F_137 ( & V_15 ) ;
F_254 ( V_13 ) ;
F_138 ( & V_15 ) ;
F_256 ( & V_31 -> V_215 , F_261 ) ;
if ( V_222 ) {
F_217 ( V_22 -> V_191 ) ;
F_134 ( V_22 ) ;
}
}
static void F_265 ( struct V_20 * V_31 )
{
struct V_21 * V_22 = V_31 -> V_22 ;
bool V_225 = V_22 -> V_30 & V_226 ;
F_20 ( & V_22 -> V_162 ) ;
if ( ! V_225 && V_31 -> V_77 == V_22 -> V_172 )
return;
F_79 ( & V_31 -> V_13 -> V_67 ) ;
if ( ! V_225 || ! ( V_31 -> V_13 -> V_30 & V_217 ) ) {
V_31 -> V_77 = V_22 -> V_172 ;
while ( ! F_48 ( & V_31 -> V_73 ) &&
V_31 -> V_72 < V_31 -> V_77 )
F_84 ( V_31 ) ;
F_58 ( V_31 -> V_13 ) ;
} else {
V_31 -> V_77 = 0 ;
}
F_80 ( & V_31 -> V_13 -> V_67 ) ;
}
static void F_266 ( struct V_20 * V_31 , struct V_21 * V_22 ,
struct V_12 * V_13 )
{
F_267 ( ( unsigned long ) V_31 & V_227 ) ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_13 = V_13 ;
V_31 -> V_22 = V_22 ;
V_31 -> V_78 = - 1 ;
V_31 -> V_68 = 1 ;
F_124 ( & V_31 -> V_73 ) ;
F_124 ( & V_31 -> V_223 ) ;
F_124 ( & V_31 -> V_134 ) ;
F_194 ( & V_31 -> V_70 , F_263 ) ;
}
static void F_268 ( struct V_20 * V_31 )
{
struct V_21 * V_22 = V_31 -> V_22 ;
F_20 ( & V_22 -> V_162 ) ;
if ( ! F_48 ( & V_31 -> V_223 ) )
return;
V_31 -> V_100 = V_22 -> V_100 ;
F_265 ( V_31 ) ;
F_269 ( & V_31 -> V_223 , & V_22 -> V_224 ) ;
}
static struct V_20 * F_270 ( struct V_21 * V_22 ,
const struct V_192 * V_121 )
{
struct V_12 * V_13 ;
struct V_20 * V_31 ;
F_20 ( & V_15 ) ;
V_13 = F_257 ( V_121 ) ;
if ( ! V_13 )
return NULL ;
V_31 = F_271 ( V_221 , V_18 , V_13 -> V_23 ) ;
if ( ! V_31 ) {
F_254 ( V_13 ) ;
return NULL ;
}
F_266 ( V_31 , V_22 , V_13 ) ;
return V_31 ;
}
static void F_272 ( struct V_20 * V_31 )
{
F_20 ( & V_15 ) ;
if ( V_31 ) {
F_254 ( V_31 -> V_13 ) ;
F_262 ( V_221 , V_31 ) ;
}
}
static bool F_273 ( const struct V_192 * V_121 , int V_23 ,
int V_228 , T_8 * V_125 )
{
if ( ! V_218 || V_121 -> V_193 )
goto V_229;
F_274 ( V_125 , F_275 ( V_23 ) , V_121 -> V_125 ) ;
if ( V_228 >= 0 )
F_276 ( V_228 , V_125 ) ;
if ( F_277 ( V_125 ) )
goto V_229;
F_274 ( V_125 , V_121 -> V_125 , V_219 [ V_23 ] ) ;
return ! F_243 ( V_125 , V_121 -> V_125 ) ;
V_229:
F_236 ( V_125 , V_121 -> V_125 ) ;
return false ;
}
static struct V_20 * F_278 ( struct V_21 * V_22 ,
int V_23 ,
struct V_20 * V_31 )
{
struct V_20 * V_230 ;
F_20 ( & V_22 -> V_162 ) ;
F_268 ( V_31 ) ;
V_230 = F_279 ( V_22 -> V_24 [ V_23 ] ) ;
F_280 ( V_22 -> V_24 [ V_23 ] , V_31 ) ;
return V_230 ;
}
int F_216 ( struct V_21 * V_22 ,
const struct V_192 * V_121 )
{
struct V_192 * V_231 , * V_232 ;
struct V_20 * * V_233 , * V_234 ;
int V_23 , V_14 ;
if ( F_10 ( ! ( V_22 -> V_30 & V_69 ) ) )
return - V_188 ;
if ( F_10 ( ( V_22 -> V_30 & V_196 ) && ! F_48 ( & V_22 -> V_224 ) ) )
return - V_188 ;
V_233 = F_123 ( V_235 * sizeof( V_233 [ 0 ] ) , V_18 ) ;
V_231 = F_213 ( V_18 ) ;
V_232 = F_213 ( V_18 ) ;
if ( ! V_233 || ! V_231 || ! V_232 )
goto V_236;
F_214 ( V_231 , V_121 ) ;
F_274 ( V_231 -> V_125 , V_231 -> V_125 , V_204 ) ;
F_214 ( V_232 , V_231 ) ;
F_192 () ;
F_137 ( & V_15 ) ;
V_234 = F_270 ( V_22 , V_231 ) ;
if ( ! V_234 )
goto V_237;
F_209 (node) {
if ( F_273 ( V_121 , V_23 , - 1 , V_232 -> V_125 ) ) {
V_233 [ V_23 ] = F_270 ( V_22 , V_232 ) ;
if ( ! V_233 [ V_23 ] )
goto V_237;
} else {
V_234 -> V_68 ++ ;
V_233 [ V_23 ] = V_234 ;
}
}
F_138 ( & V_15 ) ;
F_137 ( & V_22 -> V_162 ) ;
F_214 ( V_22 -> V_191 , V_231 ) ;
F_209 (node)
V_233 [ V_23 ] = F_278 ( V_22 , V_23 , V_233 [ V_23 ] ) ;
F_268 ( V_234 ) ;
F_281 ( V_22 -> V_234 , V_234 ) ;
F_138 ( & V_22 -> V_162 ) ;
F_209 (node)
F_78 ( V_233 [ V_23 ] ) ;
F_78 ( V_234 ) ;
F_196 () ;
V_14 = 0 ;
V_238:
F_217 ( V_232 ) ;
F_217 ( V_231 ) ;
F_134 ( V_233 ) ;
return V_14 ;
V_237:
F_272 ( V_234 ) ;
F_209 (node)
if ( V_233 && V_233 [ V_23 ] != V_234 )
F_272 ( V_233 [ V_23 ] ) ;
F_138 ( & V_15 ) ;
F_196 () ;
V_236:
V_14 = - V_128 ;
goto V_238;
}
static void F_282 ( struct V_21 * V_22 , int V_54 ,
bool V_239 )
{
int V_23 = F_105 ( V_54 ) ;
int V_240 = V_239 ? - 1 : V_54 ;
struct V_20 * V_230 = NULL , * V_31 ;
struct V_192 * V_241 ;
T_8 * V_125 ;
F_20 ( & V_15 ) ;
if ( ! V_218 || ! ( V_22 -> V_30 & V_69 ) )
return;
V_241 = V_242 ;
V_125 = V_241 -> V_125 ;
F_137 ( & V_22 -> V_162 ) ;
if ( V_22 -> V_191 -> V_193 )
goto V_164;
F_214 ( V_241 , V_22 -> V_191 ) ;
V_31 = F_22 ( V_22 , V_23 ) ;
if ( F_273 ( V_22 -> V_191 , V_23 , V_240 , V_125 ) ) {
if ( F_243 ( V_125 , V_31 -> V_13 -> V_121 -> V_125 ) )
goto V_164;
} else {
if ( V_31 == V_22 -> V_234 )
goto V_164;
else
goto V_243;
}
F_138 ( & V_22 -> V_162 ) ;
V_31 = F_270 ( V_22 , V_241 ) ;
if ( ! V_31 ) {
F_283 ( L_13 ,
V_22 -> V_99 ) ;
goto V_164;
}
F_137 ( & V_22 -> V_162 ) ;
V_230 = F_278 ( V_22 , V_23 , V_31 ) ;
goto V_164;
V_243:
F_79 ( & V_22 -> V_234 -> V_13 -> V_67 ) ;
F_75 ( V_22 -> V_234 ) ;
F_80 ( & V_22 -> V_234 -> V_13 -> V_67 ) ;
V_230 = F_278 ( V_22 , V_23 , V_22 -> V_234 ) ;
V_164:
F_138 ( & V_22 -> V_162 ) ;
F_78 ( V_230 ) ;
}
static int F_284 ( struct V_21 * V_22 )
{
bool V_244 = V_22 -> V_30 & V_245 ;
int V_54 , V_14 ;
if ( ! ( V_22 -> V_30 & V_69 ) ) {
V_22 -> V_98 = F_191 ( struct V_20 ) ;
if ( ! V_22 -> V_98 )
return - V_128 ;
F_285 (cpu) {
struct V_20 * V_31 =
F_104 ( V_22 -> V_98 , V_54 ) ;
struct V_12 * V_246 =
F_286 ( V_247 , V_54 ) ;
F_266 ( V_31 , V_22 , & V_246 [ V_244 ] ) ;
F_137 ( & V_22 -> V_162 ) ;
F_268 ( V_31 ) ;
F_138 ( & V_22 -> V_162 ) ;
}
return 0 ;
} else if ( V_22 -> V_30 & V_196 ) {
V_14 = F_216 ( V_22 , V_248 [ V_244 ] ) ;
F_287 ( ! V_14 && ( V_22 -> V_224 . V_109 != & V_22 -> V_234 -> V_223 ||
V_22 -> V_224 . V_131 != & V_22 -> V_234 -> V_223 ) ,
L_14 , V_22 -> V_99 ) ;
return V_14 ;
} else {
return F_216 ( V_22 , V_249 [ V_244 ] ) ;
}
}
static int F_288 ( int V_77 , unsigned int V_30 ,
const char * V_99 )
{
int V_250 = V_30 & V_69 ? V_251 : V_252 ;
if ( V_77 < 1 || V_77 > V_250 )
F_178 ( L_15 ,
V_77 , V_99 , 1 , V_250 ) ;
return F_289 ( V_77 , 1 , V_250 ) ;
}
struct V_21 * F_290 ( const char * V_253 ,
unsigned int V_30 ,
int V_77 ,
struct V_254 * V_255 ,
const char * V_256 , ... )
{
T_4 V_257 = 0 ;
T_9 args ;
struct V_21 * V_22 ;
struct V_20 * V_31 ;
if ( ( V_30 & V_258 ) && V_259 )
V_30 |= V_69 ;
if ( V_30 & V_69 )
V_257 = V_235 * sizeof( V_22 -> V_24 [ 0 ] ) ;
V_22 = F_123 ( sizeof( * V_22 ) + V_257 , V_18 ) ;
if ( ! V_22 )
return NULL ;
if ( V_30 & V_69 ) {
V_22 -> V_191 = F_213 ( V_18 ) ;
if ( ! V_22 -> V_191 )
goto V_260;
}
va_start ( args , V_256 ) ;
vsnprintf ( V_22 -> V_99 , sizeof( V_22 -> V_99 ) , V_253 , args ) ;
va_end ( args ) ;
V_77 = V_77 ? : V_261 ;
V_77 = F_288 ( V_77 , V_30 , V_22 -> V_99 ) ;
V_22 -> V_30 = V_30 ;
V_22 -> V_172 = V_77 ;
F_249 ( & V_22 -> V_162 ) ;
F_168 ( & V_22 -> V_79 , 0 ) ;
F_124 ( & V_22 -> V_224 ) ;
F_124 ( & V_22 -> V_165 ) ;
F_124 ( & V_22 -> V_163 ) ;
F_124 ( & V_22 -> V_135 ) ;
F_291 ( & V_22 -> V_161 , V_256 , V_255 , 0 ) ;
F_124 ( & V_22 -> V_159 ) ;
if ( F_284 ( V_22 ) < 0 )
goto V_260;
if ( V_30 & V_262 ) {
struct V_50 * V_133 ;
V_133 = F_122 () ;
if ( ! V_133 )
goto V_263;
V_133 -> V_146 = V_22 ;
V_133 -> V_52 = F_292 ( F_157 , V_133 , L_16 ,
V_22 -> V_99 ) ;
if ( F_129 ( V_133 -> V_52 ) ) {
F_134 ( V_133 ) ;
goto V_263;
}
V_22 -> V_133 = V_133 ;
V_133 -> V_52 -> V_30 |= V_124 ;
F_60 ( V_133 -> V_52 ) ;
}
if ( ( V_22 -> V_30 & V_264 ) && F_227 ( V_22 ) )
goto V_263;
F_137 ( & V_15 ) ;
F_137 ( & V_22 -> V_162 ) ;
F_169 (pwq, wq)
F_265 ( V_31 ) ;
F_138 ( & V_22 -> V_162 ) ;
F_118 ( & V_22 -> V_159 , & V_265 ) ;
F_138 ( & V_15 ) ;
return V_22 ;
V_260:
F_217 ( V_22 -> V_191 ) ;
F_134 ( V_22 ) ;
return NULL ;
V_263:
F_293 ( V_22 ) ;
return NULL ;
}
void F_293 ( struct V_21 * V_22 )
{
struct V_20 * V_31 ;
int V_23 ;
F_177 ( V_22 ) ;
F_137 ( & V_22 -> V_162 ) ;
F_169 (pwq, wq) {
int V_266 ;
for ( V_266 = 0 ; V_266 < V_28 ; V_266 ++ ) {
if ( F_10 ( V_31 -> V_76 [ V_266 ] ) ) {
F_138 ( & V_22 -> V_162 ) ;
return;
}
}
if ( F_10 ( ( V_31 != V_22 -> V_234 ) && ( V_31 -> V_68 > 1 ) ) ||
F_10 ( V_31 -> V_72 ) ||
F_10 ( ! F_48 ( & V_31 -> V_73 ) ) ) {
F_138 ( & V_22 -> V_162 ) ;
return;
}
}
F_138 ( & V_22 -> V_162 ) ;
F_137 ( & V_15 ) ;
F_93 ( & V_22 -> V_159 ) ;
F_138 ( & V_15 ) ;
F_233 ( V_22 ) ;
if ( V_22 -> V_133 ) {
F_141 ( V_22 -> V_133 -> V_52 ) ;
F_134 ( V_22 -> V_133 ) ;
V_22 -> V_133 = NULL ;
}
if ( ! ( V_22 -> V_30 & V_69 ) ) {
F_197 ( V_22 -> V_98 ) ;
F_134 ( V_22 ) ;
} else {
F_209 (node) {
V_31 = F_279 ( V_22 -> V_24 [ V_23 ] ) ;
F_294 ( V_22 -> V_24 [ V_23 ] , NULL ) ;
F_78 ( V_31 ) ;
}
V_31 = V_22 -> V_234 ;
V_22 -> V_234 = NULL ;
F_78 ( V_31 ) ;
}
}
void F_206 ( struct V_21 * V_22 , int V_77 )
{
struct V_20 * V_31 ;
if ( F_10 ( V_22 -> V_30 & V_196 ) )
return;
V_77 = F_288 ( V_77 , V_22 -> V_30 , V_22 -> V_99 ) ;
F_137 ( & V_22 -> V_162 ) ;
V_22 -> V_172 = V_77 ;
F_169 (pwq, wq)
F_265 ( V_31 ) ;
F_138 ( & V_22 -> V_162 ) ;
}
bool F_295 ( void )
{
struct V_50 * V_50 = F_101 () ;
return V_50 && V_50 -> V_146 ;
}
bool F_296 ( int V_54 , struct V_21 * V_22 )
{
struct V_20 * V_31 ;
bool V_14 ;
F_208 () ;
if ( V_54 == V_97 )
V_54 = F_297 () ;
if ( ! ( V_22 -> V_30 & V_69 ) )
V_31 = F_104 ( V_22 -> V_98 , V_54 ) ;
else
V_31 = F_22 ( V_22 , F_105 ( V_54 ) ) ;
V_14 = ! F_48 ( & V_31 -> V_73 ) ;
F_210 () ;
return V_14 ;
}
unsigned int F_298 ( struct V_2 * V_6 )
{
struct V_12 * V_13 ;
unsigned long V_30 ;
unsigned int V_14 = 0 ;
if ( F_29 ( V_6 ) )
V_14 |= V_267 ;
F_88 ( V_30 ) ;
V_13 = F_39 ( V_6 ) ;
if ( V_13 ) {
F_92 ( & V_13 -> V_67 ) ;
if ( F_70 ( V_13 , V_6 ) )
V_14 |= V_268 ;
F_94 ( & V_13 -> V_67 ) ;
}
F_95 ( V_30 ) ;
return V_14 ;
}
void F_299 ( const char * V_253 , ... )
{
struct V_50 * V_50 = F_101 () ;
T_9 args ;
if ( V_50 ) {
va_start ( args , V_253 ) ;
vsnprintf ( V_50 -> V_269 , sizeof( V_50 -> V_269 ) , V_253 , args ) ;
va_end ( args ) ;
V_50 -> V_270 = true ;
}
}
void F_300 ( const char * V_271 , struct V_53 * V_52 )
{
T_1 * V_175 = NULL ;
char V_99 [ V_272 ] = { } ;
char V_269 [ V_273 ] = { } ;
struct V_20 * V_31 = NULL ;
struct V_21 * V_22 = NULL ;
bool V_270 = false ;
struct V_50 * V_50 ;
if ( ! ( V_52 -> V_30 & V_139 ) )
return;
V_50 = F_301 ( V_52 ) ;
F_302 ( & V_175 , & V_50 -> V_61 , sizeof( V_175 ) ) ;
F_302 ( & V_31 , & V_50 -> V_91 , sizeof( V_31 ) ) ;
F_302 ( & V_22 , & V_31 -> V_22 , sizeof( V_22 ) ) ;
F_302 ( V_99 , V_22 -> V_99 , sizeof( V_99 ) - 1 ) ;
F_302 ( & V_270 , & V_50 -> V_270 , sizeof( V_270 ) ) ;
if ( V_270 )
F_302 ( V_269 , V_50 -> V_269 , sizeof( V_269 ) - 1 ) ;
if ( V_175 || V_99 [ 0 ] || V_269 [ 0 ] ) {
F_303 ( L_17 , V_271 , V_99 , V_175 ) ;
if ( V_269 [ 0 ] )
F_304 ( L_18 , V_269 ) ;
F_304 ( L_12 ) ;
}
}
static void F_305 ( struct V_2 * V_6 )
{
int V_54 = F_297 () ;
struct V_12 * V_13 ;
struct V_50 * V_50 ;
int V_274 ;
F_306 (pool, cpu) {
F_9 ( V_54 != F_297 () ) ;
F_137 ( & V_13 -> V_118 ) ;
F_79 ( & V_13 -> V_67 ) ;
F_307 (worker, wi, pool)
V_50 -> V_30 |= V_126 ;
V_13 -> V_30 |= V_114 ;
F_80 ( & V_13 -> V_67 ) ;
F_138 ( & V_13 -> V_118 ) ;
F_156 () ;
F_168 ( & V_13 -> V_40 , 0 ) ;
F_79 ( & V_13 -> V_67 ) ;
F_58 ( V_13 ) ;
F_80 ( & V_13 -> V_67 ) ;
}
}
static void F_308 ( struct V_12 * V_13 )
{
struct V_50 * V_50 ;
int V_274 ;
F_20 ( & V_13 -> V_118 ) ;
F_307 (worker, wi, pool)
F_9 ( F_131 ( V_50 -> V_52 ,
V_13 -> V_121 -> V_125 ) < 0 ) ;
F_79 ( & V_13 -> V_67 ) ;
F_307 (worker, wi, pool) {
unsigned int V_275 = V_50 -> V_30 ;
if ( V_275 & V_107 )
F_60 ( V_50 -> V_52 ) ;
F_9 ( ! ( V_275 & V_126 ) ) ;
V_275 |= V_143 ;
V_275 &= ~ V_126 ;
F_309 ( V_50 -> V_30 ) = V_275 ;
}
F_80 ( & V_13 -> V_67 ) ;
}
static void F_310 ( struct V_12 * V_13 , int V_54 )
{
static T_8 V_125 ;
struct V_50 * V_50 ;
int V_274 ;
F_20 ( & V_13 -> V_118 ) ;
if ( ! F_311 ( V_54 , V_13 -> V_121 -> V_125 ) )
return;
F_274 ( & V_125 , V_13 -> V_121 -> V_125 , V_276 ) ;
if ( F_312 ( & V_125 ) != 1 )
return;
F_307 (worker, wi, pool)
F_9 ( F_131 ( V_50 -> V_52 ,
V_13 -> V_121 -> V_125 ) < 0 ) ;
}
static int F_313 ( struct V_277 * V_278 ,
unsigned long V_279 ,
void * V_280 )
{
int V_54 = ( unsigned long ) V_280 ;
struct V_12 * V_13 ;
struct V_21 * V_22 ;
int V_281 ;
switch ( V_279 & ~ V_282 ) {
case V_283 :
F_306 (pool, cpu) {
if ( V_13 -> V_47 )
continue;
if ( F_136 ( V_13 ) < 0 )
return V_284 ;
}
break;
case V_285 :
case V_286 :
F_137 ( & V_15 ) ;
F_314 (pool, pi) {
F_137 ( & V_13 -> V_118 ) ;
if ( V_13 -> V_54 == V_54 ) {
F_79 ( & V_13 -> V_67 ) ;
V_13 -> V_30 &= ~ V_114 ;
F_80 ( & V_13 -> V_67 ) ;
F_308 ( V_13 ) ;
} else if ( V_13 -> V_54 < 0 ) {
F_310 ( V_13 , V_54 ) ;
}
F_138 ( & V_13 -> V_118 ) ;
}
F_148 (wq, &workqueues, list)
F_282 ( V_22 , V_54 , true ) ;
F_138 ( & V_15 ) ;
break;
}
return V_287 ;
}
static int F_315 ( struct V_277 * V_278 ,
unsigned long V_279 ,
void * V_280 )
{
int V_54 = ( unsigned long ) V_280 ;
struct V_2 V_288 ;
struct V_21 * V_22 ;
switch ( V_279 & ~ V_282 ) {
case V_289 :
F_164 ( & V_288 , F_305 ) ;
F_108 ( V_54 , V_290 , & V_288 ) ;
F_137 ( & V_15 ) ;
F_148 (wq, &workqueues, list)
F_282 ( V_22 , V_54 , false ) ;
F_138 ( & V_15 ) ;
F_184 ( & V_288 ) ;
F_18 ( & V_288 ) ;
break;
}
return V_287 ;
}
static void F_316 ( struct V_2 * V_6 )
{
struct V_291 * V_292 = F_162 ( V_6 , struct V_291 , V_6 ) ;
V_292 -> V_14 = V_292 -> V_175 ( V_292 -> V_293 ) ;
}
long F_317 ( int V_54 , long (* V_175)( void * ) , void * V_293 )
{
struct V_291 V_292 = { . V_175 = V_175 , . V_293 = V_293 } ;
F_164 ( & V_292 . V_6 , F_316 ) ;
F_195 ( V_54 , & V_292 . V_6 ) ;
F_184 ( & V_292 . V_6 ) ;
F_18 ( & V_292 . V_6 ) ;
return V_292 . V_14 ;
}
void F_318 ( void )
{
struct V_12 * V_13 ;
struct V_21 * V_22 ;
struct V_20 * V_31 ;
int V_281 ;
F_137 ( & V_15 ) ;
F_9 ( V_216 ) ;
V_216 = true ;
F_314 (pool, pi) {
F_79 ( & V_13 -> V_67 ) ;
F_9 ( V_13 -> V_30 & V_217 ) ;
V_13 -> V_30 |= V_217 ;
F_80 ( & V_13 -> V_67 ) ;
}
F_148 (wq, &workqueues, list) {
F_137 ( & V_22 -> V_162 ) ;
F_169 (pwq, wq)
F_265 ( V_31 ) ;
F_138 ( & V_22 -> V_162 ) ;
}
F_138 ( & V_15 ) ;
}
bool F_319 ( void )
{
bool V_294 = false ;
struct V_21 * V_22 ;
struct V_20 * V_31 ;
F_137 ( & V_15 ) ;
F_9 ( ! V_216 ) ;
F_148 (wq, &workqueues, list) {
if ( ! ( V_22 -> V_30 & V_226 ) )
continue;
F_208 () ;
F_169 (pwq, wq) {
F_9 ( V_31 -> V_72 < 0 ) ;
if ( V_31 -> V_72 ) {
V_294 = true ;
F_210 () ;
goto V_164;
}
}
F_210 () ;
}
V_164:
F_138 ( & V_15 ) ;
return V_294 ;
}
void F_320 ( void )
{
struct V_21 * V_22 ;
struct V_20 * V_31 ;
struct V_12 * V_13 ;
int V_281 ;
F_137 ( & V_15 ) ;
if ( ! V_216 )
goto V_164;
F_314 (pool, pi) {
F_79 ( & V_13 -> V_67 ) ;
F_9 ( ! ( V_13 -> V_30 & V_217 ) ) ;
V_13 -> V_30 &= ~ V_217 ;
F_80 ( & V_13 -> V_67 ) ;
}
F_148 (wq, &workqueues, list) {
F_137 ( & V_22 -> V_162 ) ;
F_169 (pwq, wq)
F_265 ( V_31 ) ;
F_138 ( & V_22 -> V_162 ) ;
}
V_216 = false ;
V_164:
F_138 ( & V_15 ) ;
}
static void T_5 F_321 ( void )
{
T_10 * V_295 ;
int V_23 , V_54 ;
F_209 (node)
V_235 = F_322 ( V_235 , V_23 + 1 ) ;
if ( F_323 () <= 1 )
return;
if ( V_296 ) {
F_324 ( L_19 ) ;
return;
}
V_242 = F_213 ( V_18 ) ;
F_267 ( ! V_242 ) ;
V_295 = F_123 ( V_235 * sizeof( V_295 [ 0 ] ) , V_18 ) ;
F_267 ( ! V_295 ) ;
F_209 (node)
F_267 ( ! F_325 ( & V_295 [ V_23 ] , V_18 ,
F_326 ( V_23 ) ? V_23 : V_211 ) ) ;
F_285 (cpu) {
V_23 = F_105 ( V_54 ) ;
if ( F_10 ( V_23 == V_211 ) ) {
F_178 ( L_20 , V_54 ) ;
return;
}
F_327 ( V_54 , V_295 [ V_23 ] ) ;
}
V_219 = V_295 ;
V_218 = true ;
}
static int T_5 F_328 ( void )
{
int V_297 [ V_298 ] = { 0 , V_299 } ;
int V_266 , V_54 ;
F_10 ( F_329 ( struct V_20 ) < F_329 (long long) ) ;
V_221 = F_330 ( V_20 , V_300 ) ;
F_331 ( F_313 , V_301 ) ;
F_332 ( F_315 , V_302 ) ;
F_321 () ;
F_285 (cpu) {
struct V_12 * V_13 ;
V_266 = 0 ;
F_306 (pool, cpu) {
F_267 ( F_244 ( V_13 ) ) ;
V_13 -> V_54 = V_54 ;
F_236 ( V_13 -> V_121 -> V_125 , F_333 ( V_54 ) ) ;
V_13 -> V_121 -> V_122 = V_297 [ V_266 ++ ] ;
V_13 -> V_23 = F_105 ( V_54 ) ;
F_137 ( & V_15 ) ;
F_267 ( F_19 ( V_13 ) ) ;
F_138 ( & V_15 ) ;
}
}
F_193 (cpu) {
struct V_12 * V_13 ;
F_306 (pool, cpu) {
V_13 -> V_30 &= ~ V_114 ;
F_267 ( F_136 ( V_13 ) < 0 ) ;
}
}
for ( V_266 = 0 ; V_266 < V_298 ; V_266 ++ ) {
struct V_192 * V_121 ;
F_267 ( ! ( V_121 = F_213 ( V_18 ) ) ) ;
V_121 -> V_122 = V_297 [ V_266 ] ;
V_249 [ V_266 ] = V_121 ;
F_267 ( ! ( V_121 = F_213 ( V_18 ) ) ) ;
V_121 -> V_122 = V_297 [ V_266 ] ;
V_121 -> V_193 = true ;
V_248 [ V_266 ] = V_121 ;
}
V_174 = F_334 ( L_21 , 0 , 0 ) ;
V_290 = F_334 ( L_22 , V_245 , 0 ) ;
V_303 = F_334 ( L_23 , 0 , 0 ) ;
V_304 = F_334 ( L_24 , V_69 ,
V_251 ) ;
V_305 = F_334 ( L_25 ,
V_226 , 0 ) ;
V_306 = F_334 ( L_26 ,
V_258 , 0 ) ;
V_307 = F_334 ( L_27 ,
V_226 | V_258 ,
0 ) ;
F_267 ( ! V_174 || ! V_290 || ! V_303 ||
! V_304 || ! V_305 ||
! V_306 ||
! V_307 ) ;
return 0 ;
}
