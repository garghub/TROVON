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
V_14 = F_21 ( & V_16 , V_13 , 0 , 0 , V_17 ) ;
if ( V_14 >= 0 ) {
V_13 -> V_18 = V_14 ;
return 0 ;
}
return V_14 ;
}
static struct V_19 * F_22 ( struct V_20 * V_21 ,
int V_22 )
{
F_23 ( V_21 ) ;
return F_24 ( V_21 -> V_23 [ V_22 ] ) ;
}
static unsigned int F_25 ( int V_24 )
{
return V_24 << V_25 ;
}
static int F_26 ( struct V_2 * V_6 )
{
return ( * F_7 ( V_6 ) >> V_25 ) &
( ( 1 << V_26 ) - 1 ) ;
}
static int F_27 ( int V_24 )
{
return ( V_24 + 1 ) % V_27 ;
}
static inline void F_28 ( struct V_2 * V_6 , unsigned long V_28 ,
unsigned long V_29 )
{
F_9 ( ! F_29 ( V_6 ) ) ;
F_30 ( & V_6 -> V_28 , V_28 | V_29 | F_31 ( V_6 ) ) ;
}
static void F_32 ( struct V_2 * V_6 , struct V_19 * V_30 ,
unsigned long V_31 )
{
F_28 ( V_6 , ( unsigned long ) V_30 ,
V_32 | V_33 | V_31 ) ;
}
static void F_33 ( struct V_2 * V_6 ,
int V_34 )
{
F_28 ( V_6 , ( unsigned long ) V_34 << V_35 ,
V_32 ) ;
}
static void F_34 ( struct V_2 * V_6 ,
int V_34 )
{
F_35 () ;
F_28 ( V_6 , ( unsigned long ) V_34 << V_35 , 0 ) ;
}
static void F_36 ( struct V_2 * V_6 )
{
F_35 () ;
F_28 ( V_6 , V_36 , 0 ) ;
}
static struct V_19 * F_37 ( struct V_2 * V_6 )
{
unsigned long V_28 = F_38 ( & V_6 -> V_28 ) ;
if ( V_28 & V_33 )
return ( void * ) ( V_28 & V_37 ) ;
else
return NULL ;
}
static struct V_12 * F_39 ( struct V_2 * V_6 )
{
unsigned long V_28 = F_38 ( & V_6 -> V_28 ) ;
int V_34 ;
F_40 () ;
if ( V_28 & V_33 )
return ( (struct V_19 * )
( V_28 & V_37 ) ) -> V_13 ;
V_34 = V_28 >> V_35 ;
if ( V_34 == V_38 )
return NULL ;
return F_41 ( & V_16 , V_34 ) ;
}
static int F_42 ( struct V_2 * V_6 )
{
unsigned long V_28 = F_38 ( & V_6 -> V_28 ) ;
if ( V_28 & V_33 )
return ( (struct V_19 * )
( V_28 & V_37 ) ) -> V_13 -> V_18 ;
return V_28 >> V_35 ;
}
static void F_43 ( struct V_2 * V_6 )
{
unsigned long V_34 = F_42 ( V_6 ) ;
V_34 <<= V_35 ;
F_28 ( V_6 , V_34 | V_39 , V_32 ) ;
}
static bool F_44 ( struct V_2 * V_6 )
{
unsigned long V_28 = F_38 ( & V_6 -> V_28 ) ;
return ! ( V_28 & V_33 ) && ( V_28 & V_39 ) ;
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
( V_13 -> V_29 & V_43 ) ;
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
if ( ! ( V_50 -> V_29 & V_55 ) ) {
F_9 ( V_50 -> V_13 -> V_54 != V_54 ) ;
F_63 ( & V_50 -> V_13 -> V_40 ) ;
}
}
struct V_53 * F_64 ( struct V_53 * V_52 , int V_54 )
{
struct V_50 * V_50 = F_62 ( V_52 ) , * V_56 = NULL ;
struct V_12 * V_13 ;
if ( V_50 -> V_29 & V_55 )
return NULL ;
V_13 = V_50 -> V_13 ;
if ( F_9 ( V_54 != F_65 () ) )
return NULL ;
if ( F_66 ( & V_13 -> V_40 ) &&
! F_48 ( & V_13 -> V_41 ) )
V_56 = F_55 ( V_13 ) ;
return V_56 ? V_56 -> V_52 : NULL ;
}
static inline void F_67 ( struct V_50 * V_50 , unsigned int V_29 ,
bool V_57 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
F_9 ( V_50 -> V_52 != V_58 ) ;
if ( ( V_29 & V_55 ) &&
! ( V_50 -> V_29 & V_55 ) ) {
if ( V_57 ) {
if ( F_66 ( & V_13 -> V_40 ) &&
! F_48 ( & V_13 -> V_41 ) )
F_58 ( V_13 ) ;
} else
F_68 ( & V_13 -> V_40 ) ;
}
V_50 -> V_29 |= V_29 ;
}
static inline void F_69 ( struct V_50 * V_50 , unsigned int V_29 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
unsigned int V_59 = V_50 -> V_29 ;
F_9 ( V_50 -> V_52 != V_58 ) ;
V_50 -> V_29 &= ~ V_29 ;
if ( ( V_29 & V_55 ) && ( V_59 & V_55 ) )
if ( ! ( V_50 -> V_29 & V_55 ) )
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
static void F_75 ( struct V_19 * V_30 )
{
F_20 ( & V_30 -> V_13 -> V_67 ) ;
F_9 ( V_30 -> V_68 <= 0 ) ;
V_30 -> V_68 ++ ;
}
static void F_76 ( struct V_19 * V_30 )
{
F_20 ( & V_30 -> V_13 -> V_67 ) ;
if ( F_59 ( -- V_30 -> V_68 ) )
return;
if ( F_9 ( ! ( V_30 -> V_21 -> V_29 & V_69 ) ) )
return;
F_77 ( & V_30 -> V_70 ) ;
}
static void F_78 ( struct V_19 * V_30 )
{
if ( V_30 ) {
F_79 ( & V_30 -> V_13 -> V_67 ) ;
F_76 ( V_30 ) ;
F_80 ( & V_30 -> V_13 -> V_67 ) ;
}
}
static void F_81 ( struct V_2 * V_6 )
{
struct V_19 * V_30 = F_37 ( V_6 ) ;
F_82 ( V_6 ) ;
F_72 ( V_6 , & V_30 -> V_13 -> V_41 , NULL ) ;
F_83 ( V_71 , F_7 ( V_6 ) ) ;
V_30 -> V_72 ++ ;
}
static void F_84 ( struct V_19 * V_30 )
{
struct V_2 * V_6 = F_57 ( & V_30 -> V_73 ,
struct V_2 , V_51 ) ;
F_81 ( V_6 ) ;
}
static void F_85 ( struct V_19 * V_30 , int V_24 )
{
if ( V_24 == V_74 )
goto V_75;
V_30 -> V_76 [ V_24 ] -- ;
V_30 -> V_72 -- ;
if ( ! F_48 ( & V_30 -> V_73 ) ) {
if ( V_30 -> V_72 < V_30 -> V_77 )
F_84 ( V_30 ) ;
}
if ( F_59 ( V_30 -> V_78 != V_24 ) )
goto V_75;
if ( V_30 -> V_76 [ V_24 ] )
goto V_75;
V_30 -> V_78 = - 1 ;
if ( F_66 ( & V_30 -> V_21 -> V_79 ) )
F_86 ( & V_30 -> V_21 -> V_80 -> V_81 ) ;
V_75:
F_76 ( V_30 ) ;
}
static int F_87 ( struct V_2 * V_6 , bool V_82 ,
unsigned long * V_29 )
{
struct V_12 * V_13 ;
struct V_19 * V_30 ;
F_88 ( * V_29 ) ;
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
V_30 = F_37 ( V_6 ) ;
if ( V_30 && V_30 -> V_13 == V_13 ) {
F_14 ( V_6 ) ;
if ( * F_7 ( V_6 ) & V_88 )
F_81 ( V_6 ) ;
F_93 ( & V_6 -> V_51 ) ;
F_85 ( F_37 ( V_6 ) , F_26 ( V_6 ) ) ;
F_33 ( V_6 , V_13 -> V_18 ) ;
F_94 ( & V_13 -> V_67 ) ;
return 1 ;
}
F_94 ( & V_13 -> V_67 ) ;
V_87:
F_95 ( * V_29 ) ;
if ( F_44 ( V_6 ) )
return - V_89 ;
F_96 () ;
return - V_90 ;
}
static void F_97 ( struct V_19 * V_30 , struct V_2 * V_6 ,
struct V_62 * V_63 , unsigned int V_31 )
{
struct V_12 * V_13 = V_30 -> V_13 ;
F_32 ( V_6 , V_30 , V_31 ) ;
F_98 ( & V_6 -> V_51 , V_63 ) ;
F_75 ( V_30 ) ;
F_99 () ;
if ( F_45 ( V_13 ) )
F_58 ( V_13 ) ;
}
static bool F_100 ( struct V_20 * V_21 )
{
struct V_50 * V_50 ;
V_50 = F_101 () ;
return V_50 && V_50 -> V_91 -> V_21 == V_21 ;
}
static void F_102 ( int V_54 , struct V_20 * V_21 ,
struct V_2 * V_6 )
{
struct V_19 * V_30 ;
struct V_12 * V_92 ;
struct V_62 * V_41 ;
unsigned int V_93 ;
unsigned int V_94 = V_54 ;
F_9 ( ! F_103 () ) ;
F_13 ( V_6 ) ;
if ( F_56 ( V_21 -> V_29 & V_95 ) &&
F_9 ( ! F_100 ( V_21 ) ) )
return;
V_96:
if ( V_94 == V_97 )
V_54 = F_65 () ;
if ( ! ( V_21 -> V_29 & V_69 ) )
V_30 = F_104 ( V_21 -> V_98 , V_54 ) ;
else
V_30 = F_22 ( V_21 , F_105 ( V_54 ) ) ;
V_92 = F_39 ( V_6 ) ;
if ( V_92 && V_92 != V_30 -> V_13 ) {
struct V_50 * V_50 ;
F_92 ( & V_92 -> V_67 ) ;
V_50 = F_70 ( V_92 , V_6 ) ;
if ( V_50 && V_50 -> V_91 -> V_21 == V_21 ) {
V_30 = V_50 -> V_91 ;
} else {
F_94 ( & V_92 -> V_67 ) ;
F_92 ( & V_30 -> V_13 -> V_67 ) ;
}
} else {
F_92 ( & V_30 -> V_13 -> V_67 ) ;
}
if ( F_56 ( ! V_30 -> V_68 ) ) {
if ( V_21 -> V_29 & V_69 ) {
F_94 ( & V_30 -> V_13 -> V_67 ) ;
F_96 () ;
goto V_96;
}
F_106 ( true , L_1 ,
V_21 -> V_99 , V_54 ) ;
}
F_107 ( V_94 , V_30 , V_6 ) ;
if ( F_10 ( ! F_48 ( & V_6 -> V_51 ) ) ) {
F_94 ( & V_30 -> V_13 -> V_67 ) ;
return;
}
V_30 -> V_76 [ V_30 -> V_100 ] ++ ;
V_93 = F_25 ( V_30 -> V_100 ) ;
if ( F_59 ( V_30 -> V_72 < V_30 -> V_77 ) ) {
F_82 ( V_6 ) ;
V_30 -> V_72 ++ ;
V_41 = & V_30 -> V_13 -> V_41 ;
} else {
V_93 |= V_88 ;
V_41 = & V_30 -> V_73 ;
}
F_97 ( V_30 , V_6 , V_41 , V_93 ) ;
F_94 ( & V_30 -> V_13 -> V_67 ) ;
}
bool F_108 ( int V_54 , struct V_20 * V_21 ,
struct V_2 * V_6 )
{
bool V_14 = false ;
unsigned long V_29 ;
F_88 ( V_29 ) ;
if ( ! F_91 ( V_86 , F_7 ( V_6 ) ) ) {
F_102 ( V_54 , V_21 , V_6 ) ;
V_14 = true ;
}
F_95 ( V_29 ) ;
return V_14 ;
}
void F_109 ( unsigned long V_101 )
{
struct V_83 * V_84 = (struct V_83 * ) V_101 ;
F_102 ( V_84 -> V_54 , V_84 -> V_21 , & V_84 -> V_6 ) ;
}
static void F_110 ( int V_54 , struct V_20 * V_21 ,
struct V_83 * V_84 , unsigned long V_102 )
{
struct V_103 * V_85 = & V_84 -> V_85 ;
struct V_2 * V_6 = & V_84 -> V_6 ;
F_9 ( V_85 -> V_104 != F_109 ||
V_85 -> V_28 != ( unsigned long ) V_84 ) ;
F_9 ( F_111 ( V_85 ) ) ;
F_9 ( ! F_48 ( & V_6 -> V_51 ) ) ;
if ( ! V_102 ) {
F_102 ( V_54 , V_21 , & V_84 -> V_6 ) ;
return;
}
F_112 ( & V_84 -> V_85 ) ;
V_84 -> V_21 = V_21 ;
V_84 -> V_54 = V_54 ;
V_85 -> V_105 = V_106 + V_102 ;
if ( F_56 ( V_54 != V_97 ) )
F_113 ( V_85 , V_54 ) ;
else
F_114 ( V_85 ) ;
}
bool F_115 ( int V_54 , struct V_20 * V_21 ,
struct V_83 * V_84 , unsigned long V_102 )
{
struct V_2 * V_6 = & V_84 -> V_6 ;
bool V_14 = false ;
unsigned long V_29 ;
F_88 ( V_29 ) ;
if ( ! F_91 ( V_86 , F_7 ( V_6 ) ) ) {
F_110 ( V_54 , V_21 , V_84 , V_102 ) ;
V_14 = true ;
}
F_95 ( V_29 ) ;
return V_14 ;
}
bool F_116 ( int V_54 , struct V_20 * V_21 ,
struct V_83 * V_84 , unsigned long V_102 )
{
unsigned long V_29 ;
int V_14 ;
do {
V_14 = F_87 ( & V_84 -> V_6 , true , & V_29 ) ;
} while ( F_56 ( V_14 == - V_90 ) );
if ( F_59 ( V_14 >= 0 ) ) {
F_110 ( V_54 , V_21 , V_84 , V_102 ) ;
F_95 ( V_29 ) ;
}
return V_14 ;
}
static void F_117 ( struct V_50 * V_50 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
if ( F_9 ( V_50 -> V_29 & V_107 ) ||
F_9 ( ! F_48 ( & V_50 -> V_51 ) &&
( V_50 -> V_108 . V_109 || V_50 -> V_108 . V_110 ) ) )
return;
V_50 -> V_29 |= V_107 ;
V_13 -> V_42 ++ ;
V_50 -> V_111 = V_106 ;
F_118 ( & V_50 -> V_51 , & V_13 -> V_48 ) ;
if ( F_53 ( V_13 ) && ! F_111 ( & V_13 -> V_112 ) )
F_119 ( & V_13 -> V_112 , V_106 + V_113 ) ;
F_9 ( ! ( V_13 -> V_29 & V_114 ) &&
V_13 -> V_47 == V_13 -> V_42 &&
F_46 ( & V_13 -> V_40 ) ) ;
}
static void F_120 ( struct V_50 * V_50 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
if ( F_9 ( ! ( V_50 -> V_29 & V_107 ) ) )
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
V_50 = F_123 ( sizeof( * V_50 ) , V_17 ) ;
if ( V_50 ) {
F_124 ( & V_50 -> V_51 ) ;
F_124 ( & V_50 -> V_115 ) ;
V_50 -> V_29 = V_116 ;
}
return V_50 ;
}
static struct V_50 * F_125 ( struct V_12 * V_13 )
{
struct V_50 * V_50 = NULL ;
int V_18 = - 1 ;
char V_117 [ 16 ] ;
F_20 ( & V_13 -> V_118 ) ;
F_126 ( V_17 ) ;
F_79 ( & V_13 -> V_67 ) ;
V_18 = F_21 ( & V_13 -> V_119 , NULL , 0 , 0 , V_120 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_127 () ;
if ( V_18 < 0 )
goto V_87;
V_50 = F_122 () ;
if ( ! V_50 )
goto V_87;
V_50 -> V_13 = V_13 ;
V_50 -> V_18 = V_18 ;
if ( V_13 -> V_54 >= 0 )
snprintf ( V_117 , sizeof( V_117 ) , L_2 , V_13 -> V_54 , V_18 ,
V_13 -> V_121 -> V_122 < 0 ? L_3 : L_4 ) ;
else
snprintf ( V_117 , sizeof( V_117 ) , L_5 , V_13 -> V_18 , V_18 ) ;
V_50 -> V_52 = F_128 ( V_123 , V_50 , V_13 -> V_22 ,
L_6 , V_117 ) ;
if ( F_129 ( V_50 -> V_52 ) )
goto V_87;
F_130 ( V_50 -> V_52 , V_13 -> V_121 -> V_122 ) ;
F_131 ( V_50 -> V_52 , V_13 -> V_121 -> V_124 ) ;
V_50 -> V_52 -> V_29 |= V_125 ;
if ( V_13 -> V_29 & V_114 )
V_50 -> V_29 |= V_126 ;
F_79 ( & V_13 -> V_67 ) ;
F_132 ( & V_13 -> V_119 , V_50 , V_50 -> V_18 ) ;
F_80 ( & V_13 -> V_67 ) ;
return V_50 ;
V_87:
if ( V_18 >= 0 ) {
F_79 ( & V_13 -> V_67 ) ;
F_133 ( & V_13 -> V_119 , V_18 ) ;
F_80 ( & V_13 -> V_67 ) ;
}
F_134 ( V_50 ) ;
return NULL ;
}
static void F_135 ( struct V_50 * V_50 )
{
V_50 -> V_29 |= V_127 ;
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
if ( V_50 -> V_29 & V_127 )
V_13 -> V_47 -- ;
if ( V_50 -> V_29 & V_107 )
V_13 -> V_42 -- ;
F_93 ( & V_50 -> V_51 ) ;
V_50 -> V_29 |= V_129 ;
F_133 ( & V_13 -> V_119 , V_50 -> V_18 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_140 ( V_50 -> V_52 ) ;
F_134 ( V_50 ) ;
F_79 ( & V_13 -> V_67 ) ;
}
static void F_141 ( unsigned long V_130 )
{
struct V_12 * V_13 = ( void * ) V_130 ;
F_79 ( & V_13 -> V_67 ) ;
if ( F_53 ( V_13 ) ) {
struct V_50 * V_50 ;
unsigned long V_105 ;
V_50 = F_142 ( V_13 -> V_48 . V_131 , struct V_50 , V_51 ) ;
V_105 = V_50 -> V_111 + V_113 ;
if ( F_143 ( V_106 , V_105 ) )
F_119 ( & V_13 -> V_112 , V_105 ) ;
else {
V_13 -> V_29 |= V_43 ;
F_58 ( V_13 ) ;
}
}
F_80 ( & V_13 -> V_67 ) ;
}
static void F_144 ( struct V_2 * V_6 )
{
struct V_19 * V_30 = F_37 ( V_6 ) ;
struct V_20 * V_21 = V_30 -> V_21 ;
F_20 ( & V_132 ) ;
if ( ! V_21 -> V_133 )
return;
if ( F_48 ( & V_30 -> V_134 ) ) {
F_98 ( & V_30 -> V_134 , & V_21 -> V_135 ) ;
F_60 ( V_21 -> V_133 -> V_52 ) ;
}
}
static void F_145 ( unsigned long V_130 )
{
struct V_12 * V_13 = ( void * ) V_130 ;
struct V_2 * V_6 ;
F_79 ( & V_132 ) ;
F_92 ( & V_13 -> V_67 ) ;
if ( F_51 ( V_13 ) ) {
F_146 (work, &pool->worklist, entry)
F_144 ( V_6 ) ;
}
F_94 ( & V_13 -> V_67 ) ;
F_80 ( & V_132 ) ;
F_119 ( & V_13 -> V_136 , V_106 + V_137 ) ;
}
static bool F_147 ( struct V_12 * V_13 )
__releases( &pool->lock
static bool F_148 ( struct V_12 * V_13 )
{
bool V_14 = false ;
while ( F_53 ( V_13 ) ) {
struct V_50 * V_50 ;
unsigned long V_105 ;
V_50 = F_142 ( V_13 -> V_48 . V_131 , struct V_50 , V_51 ) ;
V_105 = V_50 -> V_111 + V_113 ;
if ( F_143 ( V_106 , V_105 ) ) {
F_119 ( & V_13 -> V_112 , V_105 ) ;
break;
}
F_139 ( V_50 ) ;
V_14 = true ;
}
return V_14 ;
}
static bool F_149 ( struct V_50 * V_50 )
{
struct V_12 * V_13 = V_50 -> V_13 ;
bool V_14 = false ;
if ( ! F_150 ( & V_13 -> V_45 ) )
return V_14 ;
if ( F_56 ( ! F_150 ( & V_13 -> V_118 ) ) ) {
F_80 ( & V_13 -> V_67 ) ;
F_137 ( & V_13 -> V_118 ) ;
F_79 ( & V_13 -> V_67 ) ;
V_14 = true ;
}
V_13 -> V_29 &= ~ V_43 ;
V_14 |= F_148 ( V_13 ) ;
V_14 |= F_147 ( V_13 ) ;
F_138 ( & V_13 -> V_118 ) ;
F_138 ( & V_13 -> V_45 ) ;
return V_14 ;
}
static void F_151 ( struct V_50 * V_50 , struct V_2 * V_6 )
__releases( &pool->lock
static void F_152 ( struct V_50 * V_50 )
{
while ( ! F_48 ( & V_50 -> V_115 ) ) {
struct V_2 * V_6 = F_57 ( & V_50 -> V_115 ,
struct V_2 , V_51 ) ;
F_151 ( V_50 , V_6 ) ;
}
}
static int V_123 ( void * V_138 )
{
struct V_50 * V_50 = V_138 ;
struct V_12 * V_13 = V_50 -> V_13 ;
V_50 -> V_52 -> V_29 |= V_139 ;
V_140:
F_79 ( & V_13 -> V_67 ) ;
if ( F_56 ( V_50 -> V_29 & V_129 ) ) {
F_80 ( & V_13 -> V_67 ) ;
F_9 ( ! F_48 ( & V_50 -> V_51 ) ) ;
V_50 -> V_52 -> V_29 &= ~ V_139 ;
return 0 ;
}
F_120 ( V_50 ) ;
V_141:
if ( ! F_47 ( V_13 ) )
goto V_142;
if ( F_56 ( ! F_49 ( V_13 ) ) && F_149 ( V_50 ) )
goto V_141;
F_9 ( ! F_48 ( & V_50 -> V_115 ) ) ;
F_69 ( V_50 , V_116 | V_143 ) ;
do {
struct V_2 * V_6 =
F_57 ( & V_13 -> V_41 ,
struct V_2 , V_51 ) ;
if ( F_59 ( ! ( * F_7 ( V_6 ) & V_66 ) ) ) {
F_151 ( V_50 , V_6 ) ;
if ( F_56 ( ! F_48 ( & V_50 -> V_115 ) ) )
F_152 ( V_50 ) ;
} else {
F_72 ( V_6 , & V_50 -> V_115 , NULL ) ;
F_152 ( V_50 ) ;
}
} while ( F_50 ( V_13 ) );
F_67 ( V_50 , V_116 , false ) ;
V_142:
if ( F_56 ( F_52 ( V_13 ) ) && F_149 ( V_50 ) )
goto V_141;
F_117 ( V_50 ) ;
F_153 ( V_144 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_154 () ;
goto V_140;
}
static int F_155 ( void * V_145 )
{
struct V_50 * V_133 = V_145 ;
struct V_20 * V_21 = V_133 -> V_146 ;
struct V_62 * V_115 = & V_133 -> V_115 ;
F_130 ( V_58 , V_147 ) ;
V_133 -> V_52 -> V_29 |= V_139 ;
V_148:
F_156 ( V_144 ) ;
if ( F_157 () ) {
F_153 ( V_149 ) ;
V_133 -> V_52 -> V_29 &= ~ V_139 ;
return 0 ;
}
F_79 ( & V_132 ) ;
while ( ! F_48 ( & V_21 -> V_135 ) ) {
struct V_19 * V_30 = F_57 ( & V_21 -> V_135 ,
struct V_19 , V_134 ) ;
struct V_12 * V_13 = V_30 -> V_13 ;
struct V_2 * V_6 , * V_65 ;
F_153 ( V_149 ) ;
F_93 ( & V_30 -> V_134 ) ;
F_80 ( & V_132 ) ;
F_121 ( V_13 ) ;
V_133 -> V_13 = V_13 ;
F_9 ( ! F_48 ( & V_133 -> V_115 ) ) ;
F_158 (work, n, &pool->worklist, entry)
if ( F_37 ( V_6 ) == V_30 )
F_72 ( V_6 , V_115 , & V_65 ) ;
F_152 ( V_133 ) ;
if ( F_50 ( V_13 ) )
F_58 ( V_13 ) ;
V_133 -> V_13 = NULL ;
F_94 ( & V_13 -> V_67 ) ;
F_92 ( & V_132 ) ;
}
F_80 ( & V_132 ) ;
F_9 ( ! ( V_133 -> V_29 & V_55 ) ) ;
F_154 () ;
goto V_148;
}
static void F_159 ( struct V_2 * V_6 )
{
struct V_150 * V_151 = F_160 ( V_6 , struct V_150 , V_6 ) ;
F_86 ( & V_151 -> V_81 ) ;
}
static void F_161 ( struct V_19 * V_30 ,
struct V_150 * V_151 ,
struct V_2 * V_152 , struct V_50 * V_50 )
{
struct V_62 * V_63 ;
unsigned int V_153 = 0 ;
F_162 ( & V_151 -> V_6 , F_159 ) ;
F_163 ( V_86 , F_7 ( & V_151 -> V_6 ) ) ;
F_164 ( & V_151 -> V_81 ) ;
if ( V_50 )
V_63 = V_50 -> V_115 . V_109 ;
else {
unsigned long * V_154 = F_7 ( V_152 ) ;
V_63 = V_152 -> V_51 . V_109 ;
V_153 = * V_154 & V_66 ;
F_163 ( V_155 , V_154 ) ;
}
F_13 ( & V_151 -> V_6 ) ;
F_97 ( V_30 , & V_151 -> V_6 , V_63 ,
F_25 ( V_74 ) | V_153 ) ;
}
static bool F_165 ( struct V_20 * V_21 ,
int V_78 , int V_100 )
{
bool V_156 = false ;
struct V_19 * V_30 ;
if ( V_78 >= 0 ) {
F_9 ( F_46 ( & V_21 -> V_79 ) ) ;
F_166 ( & V_21 -> V_79 , 1 ) ;
}
F_167 (pwq, wq) {
struct V_12 * V_13 = V_30 -> V_13 ;
F_79 ( & V_13 -> V_67 ) ;
if ( V_78 >= 0 ) {
F_9 ( V_30 -> V_78 != - 1 ) ;
if ( V_30 -> V_76 [ V_78 ] ) {
V_30 -> V_78 = V_78 ;
F_63 ( & V_21 -> V_79 ) ;
V_156 = true ;
}
}
if ( V_100 >= 0 ) {
F_9 ( V_100 != F_27 ( V_30 -> V_100 ) ) ;
V_30 -> V_100 = V_100 ;
}
F_80 ( & V_13 -> V_67 ) ;
}
if ( V_78 >= 0 && F_66 ( & V_21 -> V_79 ) )
F_86 ( & V_21 -> V_80 -> V_81 ) ;
return V_156 ;
}
void F_168 ( struct V_20 * V_21 )
{
struct V_157 V_158 = {
. V_159 = F_169 ( V_158 . V_159 ) ,
. V_78 = - 1 ,
. V_81 = F_170 ( V_158 . V_81 ) ,
} ;
int V_160 ;
F_171 ( & V_21 -> V_161 ) ;
F_172 ( & V_21 -> V_161 ) ;
F_137 ( & V_21 -> V_162 ) ;
V_160 = F_27 ( V_21 -> V_100 ) ;
if ( V_160 != V_21 -> V_78 ) {
F_9 ( ! F_48 ( & V_21 -> V_163 ) ) ;
V_158 . V_78 = V_21 -> V_100 ;
V_21 -> V_100 = V_160 ;
if ( ! V_21 -> V_80 ) {
F_9 ( V_21 -> V_78 != V_158 . V_78 ) ;
V_21 -> V_80 = & V_158 ;
if ( ! F_165 ( V_21 , V_21 -> V_78 ,
V_21 -> V_100 ) ) {
V_21 -> V_78 = V_160 ;
V_21 -> V_80 = NULL ;
goto V_164;
}
} else {
F_9 ( V_21 -> V_78 == V_158 . V_78 ) ;
F_98 ( & V_158 . V_159 , & V_21 -> V_165 ) ;
F_165 ( V_21 , - 1 , V_21 -> V_100 ) ;
}
} else {
F_98 ( & V_158 . V_159 , & V_21 -> V_163 ) ;
}
F_138 ( & V_21 -> V_162 ) ;
F_173 ( & V_158 . V_81 ) ;
if ( V_21 -> V_80 != & V_158 )
return;
F_137 ( & V_21 -> V_162 ) ;
if ( V_21 -> V_80 != & V_158 )
goto V_164;
V_21 -> V_80 = NULL ;
F_9 ( ! F_48 ( & V_158 . V_159 ) ) ;
F_9 ( V_21 -> V_78 != V_158 . V_78 ) ;
while ( true ) {
struct V_157 * V_109 , * V_166 ;
F_158 (next, tmp, &wq->flusher_queue, list) {
if ( V_109 -> V_78 != V_21 -> V_78 )
break;
F_93 ( & V_109 -> V_159 ) ;
F_86 ( & V_109 -> V_81 ) ;
}
F_9 ( ! F_48 ( & V_21 -> V_163 ) &&
V_21 -> V_78 != F_27 ( V_21 -> V_100 ) ) ;
V_21 -> V_78 = F_27 ( V_21 -> V_78 ) ;
if ( ! F_48 ( & V_21 -> V_163 ) ) {
F_146 (tmp, &wq->flusher_overflow, list)
V_166 -> V_78 = V_21 -> V_100 ;
V_21 -> V_100 = F_27 ( V_21 -> V_100 ) ;
F_174 ( & V_21 -> V_163 ,
& V_21 -> V_165 ) ;
F_165 ( V_21 , - 1 , V_21 -> V_100 ) ;
}
if ( F_48 ( & V_21 -> V_165 ) ) {
F_9 ( V_21 -> V_78 != V_21 -> V_100 ) ;
break;
}
F_9 ( V_21 -> V_78 == V_21 -> V_100 ) ;
F_9 ( V_21 -> V_78 != V_109 -> V_78 ) ;
F_93 ( & V_109 -> V_159 ) ;
V_21 -> V_80 = V_109 ;
if ( F_165 ( V_21 , V_21 -> V_78 , - 1 ) )
break;
V_21 -> V_80 = NULL ;
}
V_164:
F_138 ( & V_21 -> V_162 ) ;
}
void F_175 ( struct V_20 * V_21 )
{
unsigned int V_167 = 0 ;
struct V_19 * V_30 ;
F_137 ( & V_21 -> V_162 ) ;
if ( ! V_21 -> V_168 ++ )
V_21 -> V_29 |= V_95 ;
F_138 ( & V_21 -> V_162 ) ;
V_169:
F_168 ( V_21 ) ;
F_137 ( & V_21 -> V_162 ) ;
F_167 (pwq, wq) {
bool V_170 ;
F_79 ( & V_30 -> V_13 -> V_67 ) ;
V_170 = ! V_30 -> V_72 && F_48 ( & V_30 -> V_73 ) ;
F_80 ( & V_30 -> V_13 -> V_67 ) ;
if ( V_170 )
continue;
if ( ++ V_167 == 10 ||
( V_167 % 100 == 0 && V_167 <= 1000 ) )
F_176 ( L_7 ,
V_21 -> V_99 , V_167 ) ;
F_138 ( & V_21 -> V_162 ) ;
goto V_169;
}
if ( ! -- V_21 -> V_168 )
V_21 -> V_29 &= ~ V_95 ;
F_138 ( & V_21 -> V_162 ) ;
}
static bool F_177 ( struct V_2 * V_6 , struct V_150 * V_151 )
{
struct V_50 * V_50 = NULL ;
struct V_12 * V_13 ;
struct V_19 * V_30 ;
F_178 () ;
F_179 () ;
V_13 = F_39 ( V_6 ) ;
if ( ! V_13 ) {
F_180 () ;
return false ;
}
F_92 ( & V_13 -> V_67 ) ;
V_30 = F_37 ( V_6 ) ;
if ( V_30 ) {
if ( F_56 ( V_30 -> V_13 != V_13 ) )
goto V_171;
} else {
V_50 = F_70 ( V_13 , V_6 ) ;
if ( ! V_50 )
goto V_171;
V_30 = V_50 -> V_91 ;
}
F_161 ( V_30 , V_151 , V_6 , V_50 ) ;
F_80 ( & V_13 -> V_67 ) ;
if ( V_30 -> V_21 -> V_172 == 1 || V_30 -> V_21 -> V_133 )
F_171 ( & V_30 -> V_21 -> V_161 ) ;
else
F_181 ( & V_30 -> V_21 -> V_161 ) ;
F_172 ( & V_30 -> V_21 -> V_161 ) ;
return true ;
V_171:
F_80 ( & V_13 -> V_67 ) ;
return false ;
}
static bool F_182 ( struct V_2 * V_6 )
{
struct V_150 V_151 ;
if ( F_177 ( V_6 , & V_151 ) ) {
F_173 ( & V_151 . V_81 ) ;
F_18 ( & V_151 . V_6 ) ;
return true ;
} else {
return false ;
}
}
bool F_183 ( struct V_2 * V_6 )
{
F_171 ( & V_6 -> V_161 ) ;
F_172 ( & V_6 -> V_161 ) ;
return F_182 ( V_6 ) ;
}
static bool F_184 ( struct V_2 * V_6 , bool V_82 )
{
unsigned long V_29 ;
int V_14 ;
do {
V_14 = F_87 ( V_6 , V_82 , & V_29 ) ;
if ( F_56 ( V_14 == - V_89 ) )
F_183 ( V_6 ) ;
} while ( F_56 ( V_14 < 0 ) );
F_43 ( V_6 ) ;
F_95 ( V_29 ) ;
F_183 ( V_6 ) ;
F_36 ( V_6 ) ;
return V_14 ;
}
bool F_3 ( struct V_2 * V_6 )
{
return F_184 ( V_6 , false ) ;
}
bool F_185 ( struct V_83 * V_84 )
{
F_179 () ;
if ( F_186 ( & V_84 -> V_85 ) )
F_102 ( V_84 -> V_54 , V_84 -> V_21 , & V_84 -> V_6 ) ;
F_180 () ;
return F_183 ( & V_84 -> V_6 ) ;
}
bool F_187 ( struct V_83 * V_84 )
{
unsigned long V_29 ;
int V_14 ;
do {
V_14 = F_87 ( & V_84 -> V_6 , true , & V_29 ) ;
} while ( F_56 ( V_14 == - V_90 ) );
if ( F_56 ( V_14 < 0 ) )
return false ;
F_34 ( & V_84 -> V_6 ,
F_42 ( & V_84 -> V_6 ) ) ;
F_95 ( V_29 ) ;
return V_14 ;
}
bool F_188 ( struct V_83 * V_84 )
{
return F_184 ( & V_84 -> V_6 , true ) ;
}
int F_189 ( T_1 V_3 )
{
int V_54 ;
struct V_2 T_2 * V_173 ;
V_173 = F_190 ( struct V_2 ) ;
if ( ! V_173 )
return - V_128 ;
F_191 () ;
F_192 (cpu) {
struct V_2 * V_6 = F_104 ( V_173 , V_54 ) ;
F_193 ( V_6 , V_3 ) ;
F_194 ( V_54 , V_6 ) ;
}
F_192 (cpu)
F_183 ( F_104 ( V_173 , V_54 ) ) ;
F_195 () ;
F_196 ( V_173 ) ;
return 0 ;
}
void F_197 ( void )
{
F_168 ( V_174 ) ;
}
int F_198 ( T_1 V_175 , struct V_176 * V_177 )
{
if ( ! F_199 () ) {
V_175 ( & V_177 -> V_6 ) ;
return 0 ;
}
F_193 ( & V_177 -> V_6 , V_175 ) ;
F_77 ( & V_177 -> V_6 ) ;
return 1 ;
}
static struct V_20 * F_200 ( struct V_178 * V_179 )
{
struct V_180 * V_181 = F_160 ( V_179 , struct V_180 , V_179 ) ;
return V_181 -> V_21 ;
}
static T_3 F_201 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
return F_202 ( V_184 , V_185 , L_8 , ( bool ) ! ( V_21 -> V_29 & V_69 ) ) ;
}
static T_3 F_203 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
return F_202 ( V_184 , V_185 , L_8 , V_21 -> V_172 ) ;
}
static T_3 F_204 ( struct V_178 * V_179 ,
struct V_182 * V_183 , const char * V_184 ,
T_4 V_186 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
int V_187 ;
if ( sscanf ( V_184 , L_9 , & V_187 ) != 1 || V_187 <= 0 )
return - V_188 ;
F_205 ( V_21 , V_187 ) ;
return V_186 ;
}
static T_3 F_206 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
const char * V_189 = L_4 ;
int V_22 , V_190 = 0 ;
F_207 () ;
F_208 (node) {
V_190 += F_202 ( V_184 + V_190 , V_185 - V_190 ,
L_10 , V_189 , V_22 ,
F_22 ( V_21 , V_22 ) -> V_13 -> V_18 ) ;
V_189 = L_11 ;
}
V_190 += F_202 ( V_184 + V_190 , V_185 - V_190 , L_12 ) ;
F_209 () ;
return V_190 ;
}
static T_3 F_210 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
int V_190 ;
F_137 ( & V_21 -> V_162 ) ;
V_190 = F_202 ( V_184 , V_185 , L_8 , V_21 -> V_191 -> V_122 ) ;
F_138 ( & V_21 -> V_162 ) ;
return V_190 ;
}
static struct V_192 * F_211 ( struct V_20 * V_21 )
{
struct V_192 * V_121 ;
V_121 = F_212 ( V_17 ) ;
if ( ! V_121 )
return NULL ;
F_137 ( & V_21 -> V_162 ) ;
F_213 ( V_121 , V_21 -> V_191 ) ;
F_138 ( & V_21 -> V_162 ) ;
return V_121 ;
}
static T_3 F_214 ( struct V_178 * V_179 , struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
struct V_192 * V_121 ;
int V_14 ;
V_121 = F_211 ( V_21 ) ;
if ( ! V_121 )
return - V_128 ;
if ( sscanf ( V_184 , L_9 , & V_121 -> V_122 ) == 1 &&
V_121 -> V_122 >= - 20 && V_121 -> V_122 <= 19 )
V_14 = F_215 ( V_21 , V_121 ) ;
else
V_14 = - V_188 ;
F_216 ( V_121 ) ;
return V_14 ? : V_186 ;
}
static T_3 F_217 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
int V_190 ;
F_137 ( & V_21 -> V_162 ) ;
V_190 = F_218 ( V_184 , V_185 , V_21 -> V_191 -> V_124 ) ;
F_138 ( & V_21 -> V_162 ) ;
V_190 += F_202 ( V_184 + V_190 , V_185 - V_190 , L_12 ) ;
return V_190 ;
}
static T_3 F_219 ( struct V_178 * V_179 ,
struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
struct V_192 * V_121 ;
int V_14 ;
V_121 = F_211 ( V_21 ) ;
if ( ! V_121 )
return - V_128 ;
V_14 = F_220 ( V_184 , V_121 -> V_124 ) ;
if ( ! V_14 )
V_14 = F_215 ( V_21 , V_121 ) ;
F_216 ( V_121 ) ;
return V_14 ? : V_186 ;
}
static T_3 F_221 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
int V_190 ;
F_137 ( & V_21 -> V_162 ) ;
V_190 = F_202 ( V_184 , V_185 , L_8 ,
! V_21 -> V_191 -> V_193 ) ;
F_138 ( & V_21 -> V_162 ) ;
return V_190 ;
}
static T_3 F_222 ( struct V_178 * V_179 , struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_20 * V_21 = F_200 ( V_179 ) ;
struct V_192 * V_121 ;
int V_194 , V_14 ;
V_121 = F_211 ( V_21 ) ;
if ( ! V_121 )
return - V_128 ;
V_14 = - V_188 ;
if ( sscanf ( V_184 , L_9 , & V_194 ) == 1 ) {
V_121 -> V_193 = ! V_194 ;
V_14 = F_215 ( V_21 , V_121 ) ;
}
F_216 ( V_121 ) ;
return V_14 ? : V_186 ;
}
static int T_5 F_223 ( void )
{
return F_224 ( & V_195 , NULL ) ;
}
static void F_225 ( struct V_178 * V_179 )
{
struct V_180 * V_181 = F_160 ( V_179 , struct V_180 , V_179 ) ;
F_134 ( V_181 ) ;
}
int F_226 ( struct V_20 * V_21 )
{
struct V_180 * V_181 ;
int V_14 ;
if ( F_10 ( V_21 -> V_29 & V_196 ) )
return - V_188 ;
V_21 -> V_181 = V_181 = F_123 ( sizeof( * V_181 ) , V_17 ) ;
if ( ! V_181 )
return - V_128 ;
V_181 -> V_21 = V_21 ;
V_181 -> V_179 . V_197 = & V_195 ;
V_181 -> V_179 . V_198 = V_21 -> V_99 ;
V_181 -> V_179 . V_199 = F_225 ;
F_227 ( & V_181 -> V_179 , true ) ;
V_14 = F_228 ( & V_181 -> V_179 ) ;
if ( V_14 ) {
F_134 ( V_181 ) ;
V_21 -> V_181 = NULL ;
return V_14 ;
}
if ( V_21 -> V_29 & V_69 ) {
struct V_182 * V_183 ;
for ( V_183 = V_200 ; V_183 -> V_183 . V_99 ; V_183 ++ ) {
V_14 = F_229 ( & V_181 -> V_179 , V_183 ) ;
if ( V_14 ) {
F_230 ( & V_181 -> V_179 ) ;
V_21 -> V_181 = NULL ;
return V_14 ;
}
}
}
F_231 ( & V_181 -> V_179 . V_201 , V_202 ) ;
return 0 ;
}
static void F_232 ( struct V_20 * V_21 )
{
struct V_180 * V_181 = V_21 -> V_181 ;
if ( ! V_21 -> V_181 )
return;
V_21 -> V_181 = NULL ;
F_230 ( & V_181 -> V_179 ) ;
}
static void F_232 ( struct V_20 * V_21 ) { }
void F_216 ( struct V_192 * V_121 )
{
if ( V_121 ) {
F_233 ( V_121 -> V_124 ) ;
F_134 ( V_121 ) ;
}
}
struct V_192 * F_212 ( T_6 V_203 )
{
struct V_192 * V_121 ;
V_121 = F_123 ( sizeof( * V_121 ) , V_203 ) ;
if ( ! V_121 )
goto V_87;
if ( ! F_234 ( & V_121 -> V_124 , V_203 ) )
goto V_87;
F_235 ( V_121 -> V_124 , V_204 ) ;
return V_121 ;
V_87:
F_216 ( V_121 ) ;
return NULL ;
}
static void F_213 ( struct V_192 * V_205 ,
const struct V_192 * V_206 )
{
V_205 -> V_122 = V_206 -> V_122 ;
F_235 ( V_205 -> V_124 , V_206 -> V_124 ) ;
V_205 -> V_193 = V_206 -> V_193 ;
}
static T_7 F_236 ( const struct V_192 * V_121 )
{
T_7 V_207 = 0 ;
V_207 = F_237 ( V_121 -> V_122 , V_207 ) ;
V_207 = F_238 ( F_239 ( V_121 -> V_124 ) ,
F_240 ( V_208 ) * sizeof( long ) , V_207 ) ;
return V_207 ;
}
static bool F_241 ( const struct V_192 * V_209 ,
const struct V_192 * V_210 )
{
if ( V_209 -> V_122 != V_210 -> V_122 )
return false ;
if ( ! F_242 ( V_209 -> V_124 , V_210 -> V_124 ) )
return false ;
return true ;
}
static int F_243 ( struct V_12 * V_13 )
{
F_244 ( & V_13 -> V_67 ) ;
V_13 -> V_18 = - 1 ;
V_13 -> V_54 = - 1 ;
V_13 -> V_22 = V_211 ;
V_13 -> V_29 |= V_114 ;
F_124 ( & V_13 -> V_41 ) ;
F_124 ( & V_13 -> V_48 ) ;
F_245 ( V_13 -> V_212 ) ;
F_246 ( & V_13 -> V_112 ) ;
V_13 -> V_112 . V_104 = F_141 ;
V_13 -> V_112 . V_28 = ( unsigned long ) V_13 ;
F_247 ( & V_13 -> V_136 , F_145 ,
( unsigned long ) V_13 ) ;
F_248 ( & V_13 -> V_45 ) ;
F_248 ( & V_13 -> V_118 ) ;
F_249 ( & V_13 -> V_119 ) ;
F_250 ( & V_13 -> V_213 ) ;
V_13 -> V_68 = 1 ;
V_13 -> V_121 = F_212 ( V_17 ) ;
if ( ! V_13 -> V_121 )
return - V_128 ;
return 0 ;
}
static void F_251 ( struct V_214 * V_215 )
{
struct V_12 * V_13 = F_160 ( V_215 , struct V_12 , V_215 ) ;
F_252 ( & V_13 -> V_119 ) ;
F_216 ( V_13 -> V_121 ) ;
F_134 ( V_13 ) ;
}
static void F_253 ( struct V_12 * V_13 )
{
struct V_50 * V_50 ;
F_20 ( & V_15 ) ;
if ( -- V_13 -> V_68 )
return;
if ( F_10 ( ! ( V_13 -> V_29 & V_114 ) ) ||
F_10 ( ! F_48 ( & V_13 -> V_41 ) ) )
return;
if ( V_13 -> V_18 >= 0 )
F_133 ( & V_16 , V_13 -> V_18 ) ;
F_254 ( & V_13 -> V_213 ) ;
F_137 ( & V_13 -> V_45 ) ;
F_137 ( & V_13 -> V_118 ) ;
F_79 ( & V_13 -> V_67 ) ;
while ( ( V_50 = F_55 ( V_13 ) ) )
F_139 ( V_50 ) ;
F_10 ( V_13 -> V_47 || V_13 -> V_42 ) ;
F_80 ( & V_13 -> V_67 ) ;
F_138 ( & V_13 -> V_118 ) ;
F_138 ( & V_13 -> V_45 ) ;
F_186 ( & V_13 -> V_112 ) ;
F_186 ( & V_13 -> V_136 ) ;
F_255 ( & V_13 -> V_215 , F_251 ) ;
}
static struct V_12 * F_256 ( const struct V_192 * V_121 )
{
T_7 V_207 = F_236 ( V_121 ) ;
struct V_12 * V_13 ;
int V_22 ;
F_20 ( & V_15 ) ;
F_71 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_241 ( V_13 -> V_121 , V_121 ) ) {
V_13 -> V_68 ++ ;
goto V_164;
}
}
V_13 = F_123 ( sizeof( * V_13 ) , V_17 ) ;
if ( ! V_13 || F_243 ( V_13 ) < 0 )
goto V_87;
if ( V_216 )
V_13 -> V_29 |= V_217 ;
F_257 ( & V_13 -> V_67 , 1 ) ;
F_213 ( V_13 -> V_121 , V_121 ) ;
V_13 -> V_121 -> V_193 = false ;
if ( V_218 ) {
F_208 (node) {
if ( F_258 ( V_13 -> V_121 -> V_124 ,
V_219 [ V_22 ] ) ) {
V_13 -> V_22 = V_22 ;
break;
}
}
}
if ( F_19 ( V_13 ) < 0 )
goto V_87;
if ( F_136 ( V_13 ) < 0 )
goto V_87;
F_259 ( V_220 , & V_13 -> V_213 , V_207 ) ;
V_164:
return V_13 ;
V_87:
if ( V_13 )
F_253 ( V_13 ) ;
return NULL ;
}
static void F_260 ( struct V_214 * V_215 )
{
F_261 ( V_221 ,
F_160 ( V_215 , struct V_19 , V_215 ) ) ;
}
static void F_262 ( struct V_2 * V_6 )
{
struct V_19 * V_30 = F_160 ( V_6 , struct V_19 ,
V_70 ) ;
struct V_20 * V_21 = V_30 -> V_21 ;
struct V_12 * V_13 = V_30 -> V_13 ;
bool V_222 ;
if ( F_9 ( ! ( V_21 -> V_29 & V_69 ) ) )
return;
F_137 ( & V_21 -> V_162 ) ;
F_263 ( & V_30 -> V_223 ) ;
V_222 = F_48 ( & V_21 -> V_224 ) ;
F_138 ( & V_21 -> V_162 ) ;
F_137 ( & V_15 ) ;
F_253 ( V_13 ) ;
F_138 ( & V_15 ) ;
F_255 ( & V_30 -> V_215 , F_260 ) ;
if ( V_222 ) {
F_216 ( V_21 -> V_191 ) ;
F_134 ( V_21 ) ;
}
}
static void F_264 ( struct V_19 * V_30 )
{
struct V_20 * V_21 = V_30 -> V_21 ;
bool V_225 = V_21 -> V_29 & V_226 ;
F_20 ( & V_21 -> V_162 ) ;
if ( ! V_225 && V_30 -> V_77 == V_21 -> V_172 )
return;
F_79 ( & V_30 -> V_13 -> V_67 ) ;
if ( ! V_225 || ! ( V_30 -> V_13 -> V_29 & V_217 ) ) {
V_30 -> V_77 = V_21 -> V_172 ;
while ( ! F_48 ( & V_30 -> V_73 ) &&
V_30 -> V_72 < V_30 -> V_77 )
F_84 ( V_30 ) ;
F_58 ( V_30 -> V_13 ) ;
} else {
V_30 -> V_77 = 0 ;
}
F_80 ( & V_30 -> V_13 -> V_67 ) ;
}
static void F_265 ( struct V_19 * V_30 , struct V_20 * V_21 ,
struct V_12 * V_13 )
{
F_266 ( ( unsigned long ) V_30 & V_227 ) ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_13 = V_13 ;
V_30 -> V_21 = V_21 ;
V_30 -> V_78 = - 1 ;
V_30 -> V_68 = 1 ;
F_124 ( & V_30 -> V_73 ) ;
F_124 ( & V_30 -> V_223 ) ;
F_124 ( & V_30 -> V_134 ) ;
F_193 ( & V_30 -> V_70 , F_262 ) ;
}
static void F_267 ( struct V_19 * V_30 )
{
struct V_20 * V_21 = V_30 -> V_21 ;
F_20 ( & V_21 -> V_162 ) ;
if ( ! F_48 ( & V_30 -> V_223 ) )
return;
V_30 -> V_100 = V_21 -> V_100 ;
F_264 ( V_30 ) ;
F_268 ( & V_30 -> V_223 , & V_21 -> V_224 ) ;
}
static struct V_19 * F_269 ( struct V_20 * V_21 ,
const struct V_192 * V_121 )
{
struct V_12 * V_13 ;
struct V_19 * V_30 ;
F_20 ( & V_15 ) ;
V_13 = F_256 ( V_121 ) ;
if ( ! V_13 )
return NULL ;
V_30 = F_270 ( V_221 , V_17 , V_13 -> V_22 ) ;
if ( ! V_30 ) {
F_253 ( V_13 ) ;
return NULL ;
}
F_265 ( V_30 , V_21 , V_13 ) ;
return V_30 ;
}
static void F_271 ( struct V_19 * V_30 )
{
F_20 ( & V_15 ) ;
if ( V_30 ) {
F_253 ( V_30 -> V_13 ) ;
F_261 ( V_221 , V_30 ) ;
}
}
static bool F_272 ( const struct V_192 * V_121 , int V_22 ,
int V_228 , T_8 * V_124 )
{
if ( ! V_218 || V_121 -> V_193 )
goto V_229;
F_273 ( V_124 , F_274 ( V_22 ) , V_121 -> V_124 ) ;
if ( V_228 >= 0 )
F_275 ( V_228 , V_124 ) ;
if ( F_276 ( V_124 ) )
goto V_229;
F_273 ( V_124 , V_121 -> V_124 , V_219 [ V_22 ] ) ;
return ! F_242 ( V_124 , V_121 -> V_124 ) ;
V_229:
F_235 ( V_124 , V_121 -> V_124 ) ;
return false ;
}
static struct V_19 * F_277 ( struct V_20 * V_21 ,
int V_22 ,
struct V_19 * V_30 )
{
struct V_19 * V_230 ;
F_20 ( & V_21 -> V_162 ) ;
F_267 ( V_30 ) ;
V_230 = F_278 ( V_21 -> V_23 [ V_22 ] ) ;
F_279 ( V_21 -> V_23 [ V_22 ] , V_30 ) ;
return V_230 ;
}
int F_215 ( struct V_20 * V_21 ,
const struct V_192 * V_121 )
{
struct V_192 * V_231 , * V_232 ;
struct V_19 * * V_233 , * V_234 ;
int V_22 , V_14 ;
if ( F_10 ( ! ( V_21 -> V_29 & V_69 ) ) )
return - V_188 ;
if ( F_10 ( ( V_21 -> V_29 & V_196 ) && ! F_48 ( & V_21 -> V_224 ) ) )
return - V_188 ;
V_233 = F_123 ( V_235 * sizeof( V_233 [ 0 ] ) , V_17 ) ;
V_231 = F_212 ( V_17 ) ;
V_232 = F_212 ( V_17 ) ;
if ( ! V_233 || ! V_231 || ! V_232 )
goto V_236;
F_213 ( V_231 , V_121 ) ;
F_273 ( V_231 -> V_124 , V_231 -> V_124 , V_204 ) ;
F_213 ( V_232 , V_231 ) ;
F_191 () ;
F_137 ( & V_15 ) ;
V_234 = F_269 ( V_21 , V_231 ) ;
if ( ! V_234 )
goto V_237;
F_208 (node) {
if ( F_272 ( V_121 , V_22 , - 1 , V_232 -> V_124 ) ) {
V_233 [ V_22 ] = F_269 ( V_21 , V_232 ) ;
if ( ! V_233 [ V_22 ] )
goto V_237;
} else {
V_234 -> V_68 ++ ;
V_233 [ V_22 ] = V_234 ;
}
}
F_138 ( & V_15 ) ;
F_137 ( & V_21 -> V_162 ) ;
F_213 ( V_21 -> V_191 , V_231 ) ;
F_208 (node)
V_233 [ V_22 ] = F_277 ( V_21 , V_22 , V_233 [ V_22 ] ) ;
F_267 ( V_234 ) ;
F_280 ( V_21 -> V_234 , V_234 ) ;
F_138 ( & V_21 -> V_162 ) ;
F_208 (node)
F_78 ( V_233 [ V_22 ] ) ;
F_78 ( V_234 ) ;
F_195 () ;
V_14 = 0 ;
V_238:
F_216 ( V_232 ) ;
F_216 ( V_231 ) ;
F_134 ( V_233 ) ;
return V_14 ;
V_237:
F_271 ( V_234 ) ;
F_208 (node)
if ( V_233 && V_233 [ V_22 ] != V_234 )
F_271 ( V_233 [ V_22 ] ) ;
F_138 ( & V_15 ) ;
F_195 () ;
V_236:
V_14 = - V_128 ;
goto V_238;
}
static void F_281 ( struct V_20 * V_21 , int V_54 ,
bool V_239 )
{
int V_22 = F_105 ( V_54 ) ;
int V_240 = V_239 ? - 1 : V_54 ;
struct V_19 * V_230 = NULL , * V_30 ;
struct V_192 * V_241 ;
T_8 * V_124 ;
F_20 ( & V_15 ) ;
if ( ! V_218 || ! ( V_21 -> V_29 & V_69 ) )
return;
V_241 = V_242 ;
V_124 = V_241 -> V_124 ;
F_137 ( & V_21 -> V_162 ) ;
if ( V_21 -> V_191 -> V_193 )
goto V_164;
F_213 ( V_241 , V_21 -> V_191 ) ;
V_30 = F_22 ( V_21 , V_22 ) ;
if ( F_272 ( V_21 -> V_191 , V_22 , V_240 , V_124 ) ) {
if ( F_242 ( V_124 , V_30 -> V_13 -> V_121 -> V_124 ) )
goto V_164;
} else {
if ( V_30 == V_21 -> V_234 )
goto V_164;
else
goto V_243;
}
F_138 ( & V_21 -> V_162 ) ;
V_30 = F_269 ( V_21 , V_241 ) ;
if ( ! V_30 ) {
F_282 ( L_13 ,
V_21 -> V_99 ) ;
goto V_164;
}
F_137 ( & V_21 -> V_162 ) ;
V_230 = F_277 ( V_21 , V_22 , V_30 ) ;
goto V_164;
V_243:
F_79 ( & V_21 -> V_234 -> V_13 -> V_67 ) ;
F_75 ( V_21 -> V_234 ) ;
F_80 ( & V_21 -> V_234 -> V_13 -> V_67 ) ;
V_230 = F_277 ( V_21 , V_22 , V_21 -> V_234 ) ;
V_164:
F_138 ( & V_21 -> V_162 ) ;
F_78 ( V_230 ) ;
}
static int F_283 ( struct V_20 * V_21 )
{
bool V_244 = V_21 -> V_29 & V_245 ;
int V_54 ;
if ( ! ( V_21 -> V_29 & V_69 ) ) {
V_21 -> V_98 = F_190 ( struct V_19 ) ;
if ( ! V_21 -> V_98 )
return - V_128 ;
F_284 (cpu) {
struct V_19 * V_30 =
F_104 ( V_21 -> V_98 , V_54 ) ;
struct V_12 * V_246 =
F_285 ( V_247 , V_54 ) ;
F_265 ( V_30 , V_21 , & V_246 [ V_244 ] ) ;
F_137 ( & V_21 -> V_162 ) ;
F_267 ( V_30 ) ;
F_138 ( & V_21 -> V_162 ) ;
}
return 0 ;
} else {
return F_215 ( V_21 , V_248 [ V_244 ] ) ;
}
}
static int F_286 ( int V_77 , unsigned int V_29 ,
const char * V_99 )
{
int V_249 = V_29 & V_69 ? V_250 : V_251 ;
if ( V_77 < 1 || V_77 > V_249 )
F_176 ( L_14 ,
V_77 , V_99 , 1 , V_249 ) ;
return F_287 ( V_77 , 1 , V_249 ) ;
}
struct V_20 * F_288 ( const char * V_252 ,
unsigned int V_29 ,
int V_77 ,
struct V_253 * V_254 ,
const char * V_255 , ... )
{
T_4 V_256 = 0 ;
T_9 args ;
struct V_20 * V_21 ;
struct V_19 * V_30 ;
if ( ( V_29 & V_257 ) && V_258 )
V_29 |= V_69 ;
if ( V_29 & V_69 )
V_256 = V_235 * sizeof( V_21 -> V_23 [ 0 ] ) ;
V_21 = F_123 ( sizeof( * V_21 ) + V_256 , V_17 ) ;
if ( ! V_21 )
return NULL ;
if ( V_29 & V_69 ) {
V_21 -> V_191 = F_212 ( V_17 ) ;
if ( ! V_21 -> V_191 )
goto V_259;
}
va_start ( args , V_255 ) ;
vsnprintf ( V_21 -> V_99 , sizeof( V_21 -> V_99 ) , V_252 , args ) ;
va_end ( args ) ;
V_77 = V_77 ? : V_260 ;
V_77 = F_286 ( V_77 , V_29 , V_21 -> V_99 ) ;
V_21 -> V_29 = V_29 ;
V_21 -> V_172 = V_77 ;
F_248 ( & V_21 -> V_162 ) ;
F_166 ( & V_21 -> V_79 , 0 ) ;
F_124 ( & V_21 -> V_224 ) ;
F_124 ( & V_21 -> V_165 ) ;
F_124 ( & V_21 -> V_163 ) ;
F_124 ( & V_21 -> V_135 ) ;
F_289 ( & V_21 -> V_161 , V_255 , V_254 , 0 ) ;
F_124 ( & V_21 -> V_159 ) ;
if ( F_283 ( V_21 ) < 0 )
goto V_259;
if ( V_29 & V_261 ) {
struct V_50 * V_133 ;
V_133 = F_122 () ;
if ( ! V_133 )
goto V_262;
V_133 -> V_146 = V_21 ;
V_133 -> V_52 = F_290 ( F_155 , V_133 , L_15 ,
V_21 -> V_99 ) ;
if ( F_129 ( V_133 -> V_52 ) ) {
F_134 ( V_133 ) ;
goto V_262;
}
V_21 -> V_133 = V_133 ;
V_133 -> V_52 -> V_29 |= V_125 ;
F_60 ( V_133 -> V_52 ) ;
}
if ( ( V_21 -> V_29 & V_263 ) && F_226 ( V_21 ) )
goto V_262;
F_137 ( & V_15 ) ;
F_137 ( & V_21 -> V_162 ) ;
F_167 (pwq, wq)
F_264 ( V_30 ) ;
F_138 ( & V_21 -> V_162 ) ;
F_118 ( & V_21 -> V_159 , & V_264 ) ;
F_138 ( & V_15 ) ;
return V_21 ;
V_259:
F_216 ( V_21 -> V_191 ) ;
F_134 ( V_21 ) ;
return NULL ;
V_262:
F_291 ( V_21 ) ;
return NULL ;
}
void F_291 ( struct V_20 * V_21 )
{
struct V_19 * V_30 ;
int V_22 ;
F_175 ( V_21 ) ;
F_137 ( & V_21 -> V_162 ) ;
F_167 (pwq, wq) {
int V_265 ;
for ( V_265 = 0 ; V_265 < V_27 ; V_265 ++ ) {
if ( F_10 ( V_30 -> V_76 [ V_265 ] ) ) {
F_138 ( & V_21 -> V_162 ) ;
return;
}
}
if ( F_10 ( ( V_30 != V_21 -> V_234 ) && ( V_30 -> V_68 > 1 ) ) ||
F_10 ( V_30 -> V_72 ) ||
F_10 ( ! F_48 ( & V_30 -> V_73 ) ) ) {
F_138 ( & V_21 -> V_162 ) ;
return;
}
}
F_138 ( & V_21 -> V_162 ) ;
F_137 ( & V_15 ) ;
F_93 ( & V_21 -> V_159 ) ;
F_138 ( & V_15 ) ;
F_232 ( V_21 ) ;
if ( V_21 -> V_133 ) {
F_140 ( V_21 -> V_133 -> V_52 ) ;
F_134 ( V_21 -> V_133 ) ;
V_21 -> V_133 = NULL ;
}
if ( ! ( V_21 -> V_29 & V_69 ) ) {
F_196 ( V_21 -> V_98 ) ;
F_134 ( V_21 ) ;
} else {
F_208 (node) {
V_30 = F_278 ( V_21 -> V_23 [ V_22 ] ) ;
F_292 ( V_21 -> V_23 [ V_22 ] , NULL ) ;
F_78 ( V_30 ) ;
}
V_30 = V_21 -> V_234 ;
V_21 -> V_234 = NULL ;
F_78 ( V_30 ) ;
}
}
void F_205 ( struct V_20 * V_21 , int V_77 )
{
struct V_19 * V_30 ;
if ( F_10 ( V_21 -> V_29 & V_196 ) )
return;
V_77 = F_286 ( V_77 , V_21 -> V_29 , V_21 -> V_99 ) ;
F_137 ( & V_21 -> V_162 ) ;
V_21 -> V_172 = V_77 ;
F_167 (pwq, wq)
F_264 ( V_30 ) ;
F_138 ( & V_21 -> V_162 ) ;
}
bool F_293 ( void )
{
struct V_50 * V_50 = F_101 () ;
return V_50 && V_50 -> V_146 ;
}
bool F_294 ( int V_54 , struct V_20 * V_21 )
{
struct V_19 * V_30 ;
bool V_14 ;
F_207 () ;
if ( V_54 == V_97 )
V_54 = F_295 () ;
if ( ! ( V_21 -> V_29 & V_69 ) )
V_30 = F_104 ( V_21 -> V_98 , V_54 ) ;
else
V_30 = F_22 ( V_21 , F_105 ( V_54 ) ) ;
V_14 = ! F_48 ( & V_30 -> V_73 ) ;
F_209 () ;
return V_14 ;
}
unsigned int F_296 ( struct V_2 * V_6 )
{
struct V_12 * V_13 ;
unsigned long V_29 ;
unsigned int V_14 = 0 ;
if ( F_29 ( V_6 ) )
V_14 |= V_266 ;
F_88 ( V_29 ) ;
V_13 = F_39 ( V_6 ) ;
if ( V_13 ) {
F_92 ( & V_13 -> V_67 ) ;
if ( F_70 ( V_13 , V_6 ) )
V_14 |= V_267 ;
F_94 ( & V_13 -> V_67 ) ;
}
F_95 ( V_29 ) ;
return V_14 ;
}
void F_297 ( const char * V_252 , ... )
{
struct V_50 * V_50 = F_101 () ;
T_9 args ;
if ( V_50 ) {
va_start ( args , V_252 ) ;
vsnprintf ( V_50 -> V_268 , sizeof( V_50 -> V_268 ) , V_252 , args ) ;
va_end ( args ) ;
V_50 -> V_269 = true ;
}
}
void F_298 ( const char * V_270 , struct V_53 * V_52 )
{
T_1 * V_175 = NULL ;
char V_99 [ V_271 ] = { } ;
char V_268 [ V_272 ] = { } ;
struct V_19 * V_30 = NULL ;
struct V_20 * V_21 = NULL ;
bool V_269 = false ;
struct V_50 * V_50 ;
if ( ! ( V_52 -> V_29 & V_139 ) )
return;
V_50 = F_299 ( V_52 ) ;
F_300 ( & V_175 , & V_50 -> V_61 , sizeof( V_175 ) ) ;
F_300 ( & V_30 , & V_50 -> V_91 , sizeof( V_30 ) ) ;
F_300 ( & V_21 , & V_30 -> V_21 , sizeof( V_21 ) ) ;
F_300 ( V_99 , V_21 -> V_99 , sizeof( V_99 ) - 1 ) ;
F_300 ( & V_269 , & V_50 -> V_269 , sizeof( V_269 ) ) ;
if ( V_269 )
F_300 ( V_268 , V_50 -> V_268 , sizeof( V_268 ) - 1 ) ;
if ( V_175 || V_99 [ 0 ] || V_268 [ 0 ] ) {
F_301 ( L_16 , V_270 , V_99 , V_175 ) ;
if ( V_268 [ 0 ] )
F_302 ( L_17 , V_268 ) ;
F_302 ( L_12 ) ;
}
}
static void F_303 ( struct V_2 * V_6 )
{
int V_54 = F_295 () ;
struct V_12 * V_13 ;
struct V_50 * V_50 ;
int V_273 ;
F_304 (pool, cpu) {
F_9 ( V_54 != F_295 () ) ;
F_137 ( & V_13 -> V_118 ) ;
F_79 ( & V_13 -> V_67 ) ;
F_305 (worker, wi, pool)
V_50 -> V_29 |= V_126 ;
V_13 -> V_29 |= V_114 ;
F_80 ( & V_13 -> V_67 ) ;
F_138 ( & V_13 -> V_118 ) ;
F_154 () ;
F_166 ( & V_13 -> V_40 , 0 ) ;
F_79 ( & V_13 -> V_67 ) ;
F_58 ( V_13 ) ;
F_80 ( & V_13 -> V_67 ) ;
}
}
static void F_306 ( struct V_12 * V_13 )
{
struct V_50 * V_50 ;
int V_273 ;
F_20 ( & V_13 -> V_118 ) ;
F_305 (worker, wi, pool)
F_9 ( F_131 ( V_50 -> V_52 ,
V_13 -> V_121 -> V_124 ) < 0 ) ;
F_79 ( & V_13 -> V_67 ) ;
F_305 (worker, wi, pool) {
unsigned int V_274 = V_50 -> V_29 ;
if ( V_274 & V_107 )
F_60 ( V_50 -> V_52 ) ;
F_9 ( ! ( V_274 & V_126 ) ) ;
V_274 |= V_143 ;
V_274 &= ~ V_126 ;
F_307 ( V_50 -> V_29 ) = V_274 ;
}
F_80 ( & V_13 -> V_67 ) ;
}
static void F_308 ( struct V_12 * V_13 , int V_54 )
{
static T_8 V_124 ;
struct V_50 * V_50 ;
int V_273 ;
F_20 ( & V_13 -> V_118 ) ;
if ( ! F_309 ( V_54 , V_13 -> V_121 -> V_124 ) )
return;
F_273 ( & V_124 , V_13 -> V_121 -> V_124 , V_275 ) ;
if ( F_310 ( & V_124 ) != 1 )
return;
F_305 (worker, wi, pool)
F_9 ( F_131 ( V_50 -> V_52 ,
V_13 -> V_121 -> V_124 ) < 0 ) ;
}
static int F_311 ( struct V_276 * V_277 ,
unsigned long V_278 ,
void * V_279 )
{
int V_54 = ( unsigned long ) V_279 ;
struct V_12 * V_13 ;
struct V_20 * V_21 ;
int V_280 ;
switch ( V_278 & ~ V_281 ) {
case V_282 :
F_304 (pool, cpu) {
if ( V_13 -> V_47 )
continue;
if ( F_136 ( V_13 ) < 0 )
return V_283 ;
}
break;
case V_284 :
case V_285 :
F_137 ( & V_15 ) ;
F_312 (pool, pi) {
F_137 ( & V_13 -> V_118 ) ;
if ( V_13 -> V_54 == V_54 ) {
F_79 ( & V_13 -> V_67 ) ;
V_13 -> V_29 &= ~ V_114 ;
F_80 ( & V_13 -> V_67 ) ;
F_306 ( V_13 ) ;
} else if ( V_13 -> V_54 < 0 ) {
F_308 ( V_13 , V_54 ) ;
}
F_138 ( & V_13 -> V_118 ) ;
}
F_146 (wq, &workqueues, list)
F_281 ( V_21 , V_54 , true ) ;
F_138 ( & V_15 ) ;
break;
}
return V_286 ;
}
static int F_313 ( struct V_276 * V_277 ,
unsigned long V_278 ,
void * V_279 )
{
int V_54 = ( unsigned long ) V_279 ;
struct V_2 V_287 ;
struct V_20 * V_21 ;
switch ( V_278 & ~ V_281 ) {
case V_288 :
F_162 ( & V_287 , F_303 ) ;
F_108 ( V_54 , V_289 , & V_287 ) ;
F_137 ( & V_15 ) ;
F_146 (wq, &workqueues, list)
F_281 ( V_21 , V_54 , false ) ;
F_138 ( & V_15 ) ;
F_183 ( & V_287 ) ;
break;
}
return V_286 ;
}
static void F_314 ( struct V_2 * V_6 )
{
struct V_290 * V_291 = F_160 ( V_6 , struct V_290 , V_6 ) ;
V_291 -> V_14 = V_291 -> V_175 ( V_291 -> V_292 ) ;
}
long F_315 ( int V_54 , long (* V_175)( void * ) , void * V_292 )
{
struct V_290 V_291 = { . V_175 = V_175 , . V_292 = V_292 } ;
F_162 ( & V_291 . V_6 , F_314 ) ;
F_194 ( V_54 , & V_291 . V_6 ) ;
F_182 ( & V_291 . V_6 ) ;
return V_291 . V_14 ;
}
void F_316 ( void )
{
struct V_12 * V_13 ;
struct V_20 * V_21 ;
struct V_19 * V_30 ;
int V_280 ;
F_137 ( & V_15 ) ;
F_9 ( V_216 ) ;
V_216 = true ;
F_312 (pool, pi) {
F_79 ( & V_13 -> V_67 ) ;
F_9 ( V_13 -> V_29 & V_217 ) ;
V_13 -> V_29 |= V_217 ;
F_80 ( & V_13 -> V_67 ) ;
}
F_146 (wq, &workqueues, list) {
F_137 ( & V_21 -> V_162 ) ;
F_167 (pwq, wq)
F_264 ( V_30 ) ;
F_138 ( & V_21 -> V_162 ) ;
}
F_138 ( & V_15 ) ;
}
bool F_317 ( void )
{
bool V_293 = false ;
struct V_20 * V_21 ;
struct V_19 * V_30 ;
F_137 ( & V_15 ) ;
F_9 ( ! V_216 ) ;
F_146 (wq, &workqueues, list) {
if ( ! ( V_21 -> V_29 & V_226 ) )
continue;
F_207 () ;
F_167 (pwq, wq) {
F_9 ( V_30 -> V_72 < 0 ) ;
if ( V_30 -> V_72 ) {
V_293 = true ;
F_209 () ;
goto V_164;
}
}
F_209 () ;
}
V_164:
F_138 ( & V_15 ) ;
return V_293 ;
}
void F_318 ( void )
{
struct V_20 * V_21 ;
struct V_19 * V_30 ;
struct V_12 * V_13 ;
int V_280 ;
F_137 ( & V_15 ) ;
if ( ! V_216 )
goto V_164;
F_312 (pool, pi) {
F_79 ( & V_13 -> V_67 ) ;
F_9 ( ! ( V_13 -> V_29 & V_217 ) ) ;
V_13 -> V_29 &= ~ V_217 ;
F_80 ( & V_13 -> V_67 ) ;
}
F_146 (wq, &workqueues, list) {
F_137 ( & V_21 -> V_162 ) ;
F_167 (pwq, wq)
F_264 ( V_30 ) ;
F_138 ( & V_21 -> V_162 ) ;
}
V_216 = false ;
V_164:
F_138 ( & V_15 ) ;
}
static void T_5 F_319 ( void )
{
T_10 * V_294 ;
int V_22 , V_54 ;
F_208 (node)
V_235 = F_320 ( V_235 , V_22 + 1 ) ;
if ( F_321 () <= 1 )
return;
if ( V_295 ) {
F_322 ( L_18 ) ;
return;
}
V_242 = F_212 ( V_17 ) ;
F_266 ( ! V_242 ) ;
V_294 = F_123 ( V_235 * sizeof( V_294 [ 0 ] ) , V_17 ) ;
F_266 ( ! V_294 ) ;
F_208 (node)
F_266 ( ! F_323 ( & V_294 [ V_22 ] , V_17 ,
F_324 ( V_22 ) ? V_22 : V_211 ) ) ;
F_284 (cpu) {
V_22 = F_105 ( V_54 ) ;
if ( F_10 ( V_22 == V_211 ) ) {
F_176 ( L_19 , V_54 ) ;
return;
}
F_325 ( V_54 , V_294 [ V_22 ] ) ;
}
V_219 = V_294 ;
V_218 = true ;
}
static int T_5 F_326 ( void )
{
int V_296 [ V_297 ] = { 0 , V_298 } ;
int V_265 , V_54 ;
F_327 ( ( 1LU << ( V_299 - V_35 ) ) <
V_300 * V_297 ) ;
F_10 ( F_328 ( struct V_19 ) < F_328 (long long) ) ;
V_221 = F_329 ( V_19 , V_301 ) ;
F_330 ( F_311 , V_302 ) ;
F_331 ( F_313 , V_303 ) ;
F_319 () ;
F_284 (cpu) {
struct V_12 * V_13 ;
V_265 = 0 ;
F_304 (pool, cpu) {
F_266 ( F_243 ( V_13 ) ) ;
V_13 -> V_54 = V_54 ;
F_235 ( V_13 -> V_121 -> V_124 , F_332 ( V_54 ) ) ;
V_13 -> V_121 -> V_122 = V_296 [ V_265 ++ ] ;
V_13 -> V_22 = F_105 ( V_54 ) ;
F_137 ( & V_15 ) ;
F_266 ( F_19 ( V_13 ) ) ;
F_138 ( & V_15 ) ;
}
}
F_192 (cpu) {
struct V_12 * V_13 ;
F_304 (pool, cpu) {
V_13 -> V_29 &= ~ V_114 ;
F_266 ( F_136 ( V_13 ) < 0 ) ;
}
}
for ( V_265 = 0 ; V_265 < V_297 ; V_265 ++ ) {
struct V_192 * V_121 ;
F_266 ( ! ( V_121 = F_212 ( V_17 ) ) ) ;
V_121 -> V_122 = V_296 [ V_265 ] ;
V_248 [ V_265 ] = V_121 ;
}
V_174 = F_333 ( L_20 , 0 , 0 ) ;
V_289 = F_333 ( L_21 , V_245 , 0 ) ;
V_304 = F_333 ( L_22 , 0 , 0 ) ;
V_305 = F_333 ( L_23 , V_69 ,
V_250 ) ;
V_306 = F_333 ( L_24 ,
V_226 , 0 ) ;
V_307 = F_333 ( L_25 ,
V_257 , 0 ) ;
V_308 = F_333 ( L_26 ,
V_226 | V_257 ,
0 ) ;
F_266 ( ! V_174 || ! V_289 || ! V_304 ||
! V_305 || ! V_306 ||
! V_307 ||
! V_308 ) ;
return 0 ;
}
