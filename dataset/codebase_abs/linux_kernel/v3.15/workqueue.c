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
void F_19 ( struct V_12 * V_6 )
{
F_20 ( & V_6 -> V_13 ) ;
F_12 ( & V_6 -> V_6 , & V_8 ) ;
}
static inline void F_13 ( struct V_2 * V_6 ) { }
static inline void F_14 ( struct V_2 * V_6 ) { }
static int F_21 ( struct V_14 * V_15 )
{
int V_16 ;
F_22 ( & V_17 ) ;
V_16 = F_23 ( & V_18 , V_15 , 0 , V_19 ,
V_20 ) ;
if ( V_16 >= 0 ) {
V_15 -> V_21 = V_16 ;
return 0 ;
}
return V_16 ;
}
static struct V_22 * F_24 ( struct V_23 * V_24 ,
int V_25 )
{
F_25 ( V_24 ) ;
return F_26 ( V_24 -> V_26 [ V_25 ] ) ;
}
static unsigned int F_27 ( int V_27 )
{
return V_27 << V_28 ;
}
static int F_28 ( struct V_2 * V_6 )
{
return ( * F_7 ( V_6 ) >> V_28 ) &
( ( 1 << V_29 ) - 1 ) ;
}
static int F_29 ( int V_27 )
{
return ( V_27 + 1 ) % V_30 ;
}
static inline void F_30 ( struct V_2 * V_6 , unsigned long V_31 ,
unsigned long V_32 )
{
F_9 ( ! F_31 ( V_6 ) ) ;
F_32 ( & V_6 -> V_31 , V_31 | V_32 | F_33 ( V_6 ) ) ;
}
static void F_34 ( struct V_2 * V_6 , struct V_22 * V_33 ,
unsigned long V_34 )
{
F_30 ( V_6 , ( unsigned long ) V_33 ,
V_35 | V_36 | V_34 ) ;
}
static void F_35 ( struct V_2 * V_6 ,
int V_37 )
{
F_30 ( V_6 , ( unsigned long ) V_37 << V_38 ,
V_35 ) ;
}
static void F_36 ( struct V_2 * V_6 ,
int V_37 )
{
F_37 () ;
F_30 ( V_6 , ( unsigned long ) V_37 << V_38 , 0 ) ;
}
static void F_38 ( struct V_2 * V_6 )
{
F_37 () ;
F_30 ( V_6 , V_39 , 0 ) ;
}
static struct V_22 * F_39 ( struct V_2 * V_6 )
{
unsigned long V_31 = F_40 ( & V_6 -> V_31 ) ;
if ( V_31 & V_36 )
return ( void * ) ( V_31 & V_40 ) ;
else
return NULL ;
}
static struct V_14 * F_41 ( struct V_2 * V_6 )
{
unsigned long V_31 = F_40 ( & V_6 -> V_31 ) ;
int V_37 ;
F_42 () ;
if ( V_31 & V_36 )
return ( (struct V_22 * )
( V_31 & V_40 ) ) -> V_15 ;
V_37 = V_31 >> V_38 ;
if ( V_37 == V_19 )
return NULL ;
return F_43 ( & V_18 , V_37 ) ;
}
static int F_44 ( struct V_2 * V_6 )
{
unsigned long V_31 = F_40 ( & V_6 -> V_31 ) ;
if ( V_31 & V_36 )
return ( (struct V_22 * )
( V_31 & V_40 ) ) -> V_15 -> V_21 ;
return V_31 >> V_38 ;
}
static void F_45 ( struct V_2 * V_6 )
{
unsigned long V_37 = F_44 ( V_6 ) ;
V_37 <<= V_38 ;
F_30 ( V_6 , V_37 | V_41 , V_35 ) ;
}
static bool F_46 ( struct V_2 * V_6 )
{
unsigned long V_31 = F_40 ( & V_6 -> V_31 ) ;
return ! ( V_31 & V_36 ) && ( V_31 & V_41 ) ;
}
static bool F_47 ( struct V_14 * V_15 )
{
return ! F_48 ( & V_15 -> V_42 ) ;
}
static bool F_49 ( struct V_14 * V_15 )
{
return ! F_50 ( & V_15 -> V_43 ) && F_47 ( V_15 ) ;
}
static bool F_51 ( struct V_14 * V_15 )
{
return V_15 -> V_44 ;
}
static bool F_52 ( struct V_14 * V_15 )
{
return ! F_50 ( & V_15 -> V_43 ) &&
F_48 ( & V_15 -> V_42 ) <= 1 ;
}
static bool F_53 ( struct V_14 * V_15 )
{
return F_49 ( V_15 ) && ! F_51 ( V_15 ) ;
}
static bool F_54 ( struct V_14 * V_15 )
{
return F_53 ( V_15 ) ||
( V_15 -> V_32 & V_45 ) ;
}
static bool F_55 ( struct V_14 * V_15 )
{
bool V_46 = F_56 ( & V_15 -> V_47 ) ;
int V_44 = V_15 -> V_44 + V_46 ;
int V_48 = V_15 -> V_49 - V_44 ;
if ( F_50 ( & V_15 -> V_50 ) )
return false ;
return V_44 > 2 && ( V_44 - 2 ) * V_51 >= V_48 ;
}
static struct V_52 * F_57 ( struct V_14 * V_15 )
{
if ( F_58 ( F_50 ( & V_15 -> V_50 ) ) )
return NULL ;
return F_59 ( & V_15 -> V_50 , struct V_52 , V_53 ) ;
}
static void F_60 ( struct V_14 * V_15 )
{
struct V_52 * V_52 = F_57 ( V_15 ) ;
if ( F_61 ( V_52 ) )
F_62 ( V_52 -> V_54 ) ;
}
void F_63 ( struct V_55 * V_54 , int V_56 )
{
struct V_52 * V_52 = F_64 ( V_54 ) ;
if ( ! ( V_52 -> V_32 & V_57 ) ) {
F_9 ( V_52 -> V_15 -> V_56 != V_56 ) ;
F_65 ( & V_52 -> V_15 -> V_42 ) ;
}
}
struct V_55 * F_66 ( struct V_55 * V_54 , int V_56 )
{
struct V_52 * V_52 = F_64 ( V_54 ) , * V_58 = NULL ;
struct V_14 * V_15 ;
if ( V_52 -> V_32 & V_57 )
return NULL ;
V_15 = V_52 -> V_15 ;
if ( F_9 ( V_56 != F_67 () ) )
return NULL ;
if ( F_68 ( & V_15 -> V_42 ) &&
! F_50 ( & V_15 -> V_43 ) )
V_58 = F_57 ( V_15 ) ;
return V_58 ? V_58 -> V_54 : NULL ;
}
static inline void F_69 ( struct V_52 * V_52 , unsigned int V_32 ,
bool V_59 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
F_9 ( V_52 -> V_54 != V_60 ) ;
if ( ( V_32 & V_57 ) &&
! ( V_52 -> V_32 & V_57 ) ) {
if ( V_59 ) {
if ( F_68 ( & V_15 -> V_42 ) &&
! F_50 ( & V_15 -> V_43 ) )
F_60 ( V_15 ) ;
} else
F_70 ( & V_15 -> V_42 ) ;
}
V_52 -> V_32 |= V_32 ;
}
static inline void F_71 ( struct V_52 * V_52 , unsigned int V_32 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
unsigned int V_61 = V_52 -> V_32 ;
F_9 ( V_52 -> V_54 != V_60 ) ;
V_52 -> V_32 &= ~ V_32 ;
if ( ( V_32 & V_57 ) && ( V_61 & V_57 ) )
if ( ! ( V_52 -> V_32 & V_57 ) )
F_65 ( & V_15 -> V_42 ) ;
}
static struct V_52 * F_72 ( struct V_14 * V_15 ,
struct V_2 * V_6 )
{
struct V_52 * V_52 ;
F_73 (pool->busy_hash, worker, hentry,
(unsigned long)work)
if ( V_52 -> V_62 == V_6 &&
V_52 -> V_63 == V_6 -> V_3 )
return V_52 ;
return NULL ;
}
static void F_74 ( struct V_2 * V_6 , struct V_64 * V_65 ,
struct V_2 * * V_66 )
{
struct V_2 * V_67 ;
F_75 (work, n, NULL, entry) {
F_76 ( & V_6 -> V_53 , V_65 ) ;
if ( ! ( * F_7 ( V_6 ) & V_68 ) )
break;
}
if ( V_66 )
* V_66 = V_67 ;
}
static void F_77 ( struct V_22 * V_33 )
{
F_22 ( & V_33 -> V_15 -> V_69 ) ;
F_9 ( V_33 -> V_70 <= 0 ) ;
V_33 -> V_70 ++ ;
}
static void F_78 ( struct V_22 * V_33 )
{
F_22 ( & V_33 -> V_15 -> V_69 ) ;
if ( F_61 ( -- V_33 -> V_70 ) )
return;
if ( F_9 ( ! ( V_33 -> V_24 -> V_32 & V_71 ) ) )
return;
F_79 ( & V_33 -> V_72 ) ;
}
static void F_80 ( struct V_22 * V_33 )
{
if ( V_33 ) {
F_81 ( & V_33 -> V_15 -> V_69 ) ;
F_78 ( V_33 ) ;
F_82 ( & V_33 -> V_15 -> V_69 ) ;
}
}
static void F_83 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_39 ( V_6 ) ;
F_84 ( V_6 ) ;
F_74 ( V_6 , & V_33 -> V_15 -> V_43 , NULL ) ;
F_85 ( V_73 , F_7 ( V_6 ) ) ;
V_33 -> V_74 ++ ;
}
static void F_86 ( struct V_22 * V_33 )
{
struct V_2 * V_6 = F_59 ( & V_33 -> V_75 ,
struct V_2 , V_53 ) ;
F_83 ( V_6 ) ;
}
static void F_87 ( struct V_22 * V_33 , int V_27 )
{
if ( V_27 == V_76 )
goto V_77;
V_33 -> V_78 [ V_27 ] -- ;
V_33 -> V_74 -- ;
if ( ! F_50 ( & V_33 -> V_75 ) ) {
if ( V_33 -> V_74 < V_33 -> V_79 )
F_86 ( V_33 ) ;
}
if ( F_61 ( V_33 -> V_80 != V_27 ) )
goto V_77;
if ( V_33 -> V_78 [ V_27 ] )
goto V_77;
V_33 -> V_80 = - 1 ;
if ( F_68 ( & V_33 -> V_24 -> V_81 ) )
F_88 ( & V_33 -> V_24 -> V_82 -> V_83 ) ;
V_77:
F_78 ( V_33 ) ;
}
static int F_89 ( struct V_2 * V_6 , bool V_84 ,
unsigned long * V_32 )
{
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_90 ( * V_32 ) ;
if ( V_84 ) {
struct V_12 * V_85 = F_91 ( V_6 ) ;
if ( F_61 ( F_92 ( & V_85 -> V_13 ) ) )
return 1 ;
}
if ( ! F_93 ( V_86 , F_7 ( V_6 ) ) )
return 0 ;
V_15 = F_41 ( V_6 ) ;
if ( ! V_15 )
goto V_87;
F_94 ( & V_15 -> V_69 ) ;
V_33 = F_39 ( V_6 ) ;
if ( V_33 && V_33 -> V_15 == V_15 ) {
F_14 ( V_6 ) ;
if ( * F_7 ( V_6 ) & V_88 )
F_83 ( V_6 ) ;
F_95 ( & V_6 -> V_53 ) ;
F_87 ( F_39 ( V_6 ) , F_28 ( V_6 ) ) ;
F_35 ( V_6 , V_15 -> V_21 ) ;
F_96 ( & V_15 -> V_69 ) ;
return 1 ;
}
F_96 ( & V_15 -> V_69 ) ;
V_87:
F_97 ( * V_32 ) ;
if ( F_46 ( V_6 ) )
return - V_89 ;
F_98 () ;
return - V_90 ;
}
static void F_99 ( struct V_22 * V_33 , struct V_2 * V_6 ,
struct V_64 * V_65 , unsigned int V_34 )
{
struct V_14 * V_15 = V_33 -> V_15 ;
F_34 ( V_6 , V_33 , V_34 ) ;
F_100 ( & V_6 -> V_53 , V_65 ) ;
F_77 ( V_33 ) ;
F_101 () ;
if ( F_47 ( V_15 ) )
F_60 ( V_15 ) ;
}
static bool F_102 ( struct V_23 * V_24 )
{
struct V_52 * V_52 ;
V_52 = F_103 () ;
return V_52 && V_52 -> V_91 -> V_24 == V_24 ;
}
static void F_104 ( int V_56 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
struct V_22 * V_33 ;
struct V_14 * V_92 ;
struct V_64 * V_43 ;
unsigned int V_93 ;
unsigned int V_94 = V_56 ;
F_9 ( ! F_105 () ) ;
F_13 ( V_6 ) ;
if ( F_58 ( V_24 -> V_32 & V_95 ) &&
F_9 ( ! F_102 ( V_24 ) ) )
return;
V_96:
if ( V_94 == V_97 )
V_56 = F_67 () ;
if ( ! ( V_24 -> V_32 & V_71 ) )
V_33 = F_106 ( V_24 -> V_98 , V_56 ) ;
else
V_33 = F_24 ( V_24 , F_107 ( V_56 ) ) ;
V_92 = F_41 ( V_6 ) ;
if ( V_92 && V_92 != V_33 -> V_15 ) {
struct V_52 * V_52 ;
F_94 ( & V_92 -> V_69 ) ;
V_52 = F_72 ( V_92 , V_6 ) ;
if ( V_52 && V_52 -> V_91 -> V_24 == V_24 ) {
V_33 = V_52 -> V_91 ;
} else {
F_96 ( & V_92 -> V_69 ) ;
F_94 ( & V_33 -> V_15 -> V_69 ) ;
}
} else {
F_94 ( & V_33 -> V_15 -> V_69 ) ;
}
if ( F_58 ( ! V_33 -> V_70 ) ) {
if ( V_24 -> V_32 & V_71 ) {
F_96 ( & V_33 -> V_15 -> V_69 ) ;
F_98 () ;
goto V_96;
}
F_108 ( true , L_1 ,
V_24 -> V_99 , V_56 ) ;
}
F_109 ( V_94 , V_33 , V_6 ) ;
if ( F_10 ( ! F_50 ( & V_6 -> V_53 ) ) ) {
F_96 ( & V_33 -> V_15 -> V_69 ) ;
return;
}
V_33 -> V_78 [ V_33 -> V_100 ] ++ ;
V_93 = F_27 ( V_33 -> V_100 ) ;
if ( F_61 ( V_33 -> V_74 < V_33 -> V_79 ) ) {
F_84 ( V_6 ) ;
V_33 -> V_74 ++ ;
V_43 = & V_33 -> V_15 -> V_43 ;
} else {
V_93 |= V_88 ;
V_43 = & V_33 -> V_75 ;
}
F_99 ( V_33 , V_6 , V_43 , V_93 ) ;
F_96 ( & V_33 -> V_15 -> V_69 ) ;
}
bool F_110 ( int V_56 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
bool V_16 = false ;
unsigned long V_32 ;
F_90 ( V_32 ) ;
if ( ! F_93 ( V_86 , F_7 ( V_6 ) ) ) {
F_104 ( V_56 , V_24 , V_6 ) ;
V_16 = true ;
}
F_97 ( V_32 ) ;
return V_16 ;
}
void F_111 ( unsigned long V_101 )
{
struct V_12 * V_85 = (struct V_12 * ) V_101 ;
F_104 ( V_85 -> V_56 , V_85 -> V_24 , & V_85 -> V_6 ) ;
}
static void F_112 ( int V_56 , struct V_23 * V_24 ,
struct V_12 * V_85 , unsigned long V_102 )
{
struct V_103 * V_13 = & V_85 -> V_13 ;
struct V_2 * V_6 = & V_85 -> V_6 ;
F_9 ( V_13 -> V_104 != F_111 ||
V_13 -> V_31 != ( unsigned long ) V_85 ) ;
F_9 ( F_113 ( V_13 ) ) ;
F_9 ( ! F_50 ( & V_6 -> V_53 ) ) ;
if ( ! V_102 ) {
F_104 ( V_56 , V_24 , & V_85 -> V_6 ) ;
return;
}
F_114 ( & V_85 -> V_13 ) ;
V_85 -> V_24 = V_24 ;
V_85 -> V_56 = V_56 ;
V_13 -> V_105 = V_106 + V_102 ;
if ( F_58 ( V_56 != V_97 ) )
F_115 ( V_13 , V_56 ) ;
else
F_116 ( V_13 ) ;
}
bool F_117 ( int V_56 , struct V_23 * V_24 ,
struct V_12 * V_85 , unsigned long V_102 )
{
struct V_2 * V_6 = & V_85 -> V_6 ;
bool V_16 = false ;
unsigned long V_32 ;
F_90 ( V_32 ) ;
if ( ! F_93 ( V_86 , F_7 ( V_6 ) ) ) {
F_112 ( V_56 , V_24 , V_85 , V_102 ) ;
V_16 = true ;
}
F_97 ( V_32 ) ;
return V_16 ;
}
bool F_118 ( int V_56 , struct V_23 * V_24 ,
struct V_12 * V_85 , unsigned long V_102 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_89 ( & V_85 -> V_6 , true , & V_32 ) ;
} while ( F_58 ( V_16 == - V_90 ) );
if ( F_61 ( V_16 >= 0 ) ) {
F_112 ( V_56 , V_24 , V_85 , V_102 ) ;
F_97 ( V_32 ) ;
}
return V_16 ;
}
static void F_119 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
if ( F_9 ( V_52 -> V_32 & V_107 ) ||
F_9 ( ! F_50 ( & V_52 -> V_53 ) &&
( V_52 -> V_108 . V_109 || V_52 -> V_108 . V_110 ) ) )
return;
V_52 -> V_32 |= V_107 ;
V_15 -> V_44 ++ ;
V_52 -> V_111 = V_106 ;
F_120 ( & V_52 -> V_53 , & V_15 -> V_50 ) ;
if ( F_55 ( V_15 ) && ! F_113 ( & V_15 -> V_112 ) )
F_121 ( & V_15 -> V_112 , V_106 + V_113 ) ;
F_9 ( ! ( V_15 -> V_32 & V_114 ) &&
V_15 -> V_49 == V_15 -> V_44 &&
F_48 ( & V_15 -> V_42 ) ) ;
}
static void F_122 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
if ( F_9 ( ! ( V_52 -> V_32 & V_107 ) ) )
return;
F_71 ( V_52 , V_107 ) ;
V_15 -> V_44 -- ;
F_95 ( & V_52 -> V_53 ) ;
}
static bool F_123 ( struct V_14 * V_15 )
__acquires( &pool->lock
static struct V_52 * F_124 ( void )
{
struct V_52 * V_52 ;
V_52 = F_125 ( sizeof( * V_52 ) , V_20 ) ;
if ( V_52 ) {
F_126 ( & V_52 -> V_53 ) ;
F_126 ( & V_52 -> V_115 ) ;
V_52 -> V_32 = V_116 ;
}
return V_52 ;
}
static struct V_52 * F_127 ( struct V_14 * V_15 )
{
struct V_52 * V_52 = NULL ;
int V_21 = - 1 ;
char V_117 [ 16 ] ;
F_22 ( & V_15 -> V_118 ) ;
F_128 ( V_20 ) ;
F_81 ( & V_15 -> V_69 ) ;
V_21 = F_23 ( & V_15 -> V_119 , NULL , 0 , 0 , V_120 ) ;
F_82 ( & V_15 -> V_69 ) ;
F_129 () ;
if ( V_21 < 0 )
goto V_87;
V_52 = F_124 () ;
if ( ! V_52 )
goto V_87;
V_52 -> V_15 = V_15 ;
V_52 -> V_21 = V_21 ;
if ( V_15 -> V_56 >= 0 )
snprintf ( V_117 , sizeof( V_117 ) , L_2 , V_15 -> V_56 , V_21 ,
V_15 -> V_121 -> V_122 < 0 ? L_3 : L_4 ) ;
else
snprintf ( V_117 , sizeof( V_117 ) , L_5 , V_15 -> V_21 , V_21 ) ;
V_52 -> V_54 = F_130 ( V_123 , V_52 , V_15 -> V_25 ,
L_6 , V_117 ) ;
if ( F_131 ( V_52 -> V_54 ) )
goto V_87;
F_132 ( V_52 -> V_54 , V_15 -> V_121 -> V_122 ) ;
V_52 -> V_54 -> V_32 |= V_124 ;
F_133 ( V_52 -> V_54 , V_15 -> V_121 -> V_125 ) ;
if ( V_15 -> V_32 & V_114 )
V_52 -> V_32 |= V_126 ;
F_81 ( & V_15 -> V_69 ) ;
F_134 ( & V_15 -> V_119 , V_52 , V_52 -> V_21 ) ;
F_82 ( & V_15 -> V_69 ) ;
return V_52 ;
V_87:
if ( V_21 >= 0 ) {
F_81 ( & V_15 -> V_69 ) ;
F_135 ( & V_15 -> V_119 , V_21 ) ;
F_82 ( & V_15 -> V_69 ) ;
}
F_136 ( V_52 ) ;
return NULL ;
}
static void F_137 ( struct V_52 * V_52 )
{
V_52 -> V_32 |= V_127 ;
V_52 -> V_15 -> V_49 ++ ;
F_119 ( V_52 ) ;
F_62 ( V_52 -> V_54 ) ;
}
static int F_138 ( struct V_14 * V_15 )
{
struct V_52 * V_52 ;
F_139 ( & V_15 -> V_118 ) ;
V_52 = F_127 ( V_15 ) ;
if ( V_52 ) {
F_81 ( & V_15 -> V_69 ) ;
F_137 ( V_52 ) ;
F_82 ( & V_15 -> V_69 ) ;
}
F_140 ( & V_15 -> V_118 ) ;
return V_52 ? 0 : - V_128 ;
}
static void F_141 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
F_22 ( & V_15 -> V_118 ) ;
F_22 ( & V_15 -> V_69 ) ;
if ( F_10 ( V_52 -> V_62 ) ||
F_10 ( ! F_50 ( & V_52 -> V_115 ) ) )
return;
if ( V_52 -> V_32 & V_127 )
V_15 -> V_49 -- ;
if ( V_52 -> V_32 & V_107 )
V_15 -> V_44 -- ;
F_142 ( V_52 -> V_54 ) ;
F_95 ( & V_52 -> V_53 ) ;
V_52 -> V_32 |= V_129 ;
F_135 ( & V_15 -> V_119 , V_52 -> V_21 ) ;
F_82 ( & V_15 -> V_69 ) ;
F_143 ( V_52 -> V_54 ) ;
F_144 ( V_52 -> V_54 ) ;
F_136 ( V_52 ) ;
F_81 ( & V_15 -> V_69 ) ;
}
static void F_145 ( unsigned long V_130 )
{
struct V_14 * V_15 = ( void * ) V_130 ;
F_81 ( & V_15 -> V_69 ) ;
if ( F_55 ( V_15 ) ) {
struct V_52 * V_52 ;
unsigned long V_105 ;
V_52 = F_146 ( V_15 -> V_50 . V_131 , struct V_52 , V_53 ) ;
V_105 = V_52 -> V_111 + V_113 ;
if ( F_147 ( V_106 , V_105 ) )
F_121 ( & V_15 -> V_112 , V_105 ) ;
else {
V_15 -> V_32 |= V_45 ;
F_60 ( V_15 ) ;
}
}
F_82 ( & V_15 -> V_69 ) ;
}
static void F_148 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_39 ( V_6 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_22 ( & V_132 ) ;
if ( ! V_24 -> V_133 )
return;
if ( F_50 ( & V_33 -> V_134 ) ) {
F_77 ( V_33 ) ;
F_100 ( & V_33 -> V_134 , & V_24 -> V_135 ) ;
F_62 ( V_24 -> V_133 -> V_54 ) ;
}
}
static void F_149 ( unsigned long V_130 )
{
struct V_14 * V_15 = ( void * ) V_130 ;
struct V_2 * V_6 ;
F_81 ( & V_132 ) ;
F_94 ( & V_15 -> V_69 ) ;
if ( F_53 ( V_15 ) ) {
F_150 (work, &pool->worklist, entry)
F_148 ( V_6 ) ;
}
F_96 ( & V_15 -> V_69 ) ;
F_82 ( & V_132 ) ;
F_121 ( & V_15 -> V_136 , V_106 + V_137 ) ;
}
static bool F_151 ( struct V_14 * V_15 )
__releases( &pool->lock
static bool F_152 ( struct V_14 * V_15 )
{
bool V_16 = false ;
while ( F_55 ( V_15 ) ) {
struct V_52 * V_52 ;
unsigned long V_105 ;
V_52 = F_146 ( V_15 -> V_50 . V_131 , struct V_52 , V_53 ) ;
V_105 = V_52 -> V_111 + V_113 ;
if ( F_147 ( V_106 , V_105 ) ) {
F_121 ( & V_15 -> V_112 , V_105 ) ;
break;
}
F_141 ( V_52 ) ;
V_16 = true ;
}
return V_16 ;
}
static bool F_153 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
bool V_16 = false ;
if ( ! F_154 ( & V_15 -> V_47 ) )
return V_16 ;
if ( F_58 ( ! F_154 ( & V_15 -> V_118 ) ) ) {
F_82 ( & V_15 -> V_69 ) ;
F_139 ( & V_15 -> V_118 ) ;
F_81 ( & V_15 -> V_69 ) ;
V_16 = true ;
}
V_15 -> V_32 &= ~ V_45 ;
V_16 |= F_152 ( V_15 ) ;
V_16 |= F_151 ( V_15 ) ;
F_140 ( & V_15 -> V_118 ) ;
F_140 ( & V_15 -> V_47 ) ;
return V_16 ;
}
static void F_155 ( struct V_52 * V_52 , struct V_2 * V_6 )
__releases( &pool->lock
static void F_156 ( struct V_52 * V_52 )
{
while ( ! F_50 ( & V_52 -> V_115 ) ) {
struct V_2 * V_6 = F_59 ( & V_52 -> V_115 ,
struct V_2 , V_53 ) ;
F_155 ( V_52 , V_6 ) ;
}
}
static int V_123 ( void * V_138 )
{
struct V_52 * V_52 = V_138 ;
struct V_14 * V_15 = V_52 -> V_15 ;
V_52 -> V_54 -> V_32 |= V_139 ;
V_140:
F_81 ( & V_15 -> V_69 ) ;
if ( F_58 ( V_52 -> V_32 & V_129 ) ) {
F_82 ( & V_15 -> V_69 ) ;
F_9 ( ! F_50 ( & V_52 -> V_53 ) ) ;
V_52 -> V_54 -> V_32 &= ~ V_139 ;
return 0 ;
}
F_122 ( V_52 ) ;
V_141:
if ( ! F_49 ( V_15 ) )
goto V_142;
if ( F_58 ( ! F_51 ( V_15 ) ) && F_153 ( V_52 ) )
goto V_141;
F_9 ( ! F_50 ( & V_52 -> V_115 ) ) ;
F_71 ( V_52 , V_116 | V_143 ) ;
do {
struct V_2 * V_6 =
F_59 ( & V_15 -> V_43 ,
struct V_2 , V_53 ) ;
if ( F_61 ( ! ( * F_7 ( V_6 ) & V_68 ) ) ) {
F_155 ( V_52 , V_6 ) ;
if ( F_58 ( ! F_50 ( & V_52 -> V_115 ) ) )
F_156 ( V_52 ) ;
} else {
F_74 ( V_6 , & V_52 -> V_115 , NULL ) ;
F_156 ( V_52 ) ;
}
} while ( F_52 ( V_15 ) );
F_69 ( V_52 , V_116 , false ) ;
V_142:
if ( F_58 ( F_54 ( V_15 ) ) && F_153 ( V_52 ) )
goto V_141;
F_119 ( V_52 ) ;
F_157 ( V_144 ) ;
F_82 ( & V_15 -> V_69 ) ;
F_158 () ;
goto V_140;
}
static int F_159 ( void * V_145 )
{
struct V_52 * V_133 = V_145 ;
struct V_23 * V_24 = V_133 -> V_146 ;
struct V_64 * V_115 = & V_133 -> V_115 ;
bool V_147 ;
F_132 ( V_60 , V_148 ) ;
V_133 -> V_54 -> V_32 |= V_139 ;
V_149:
F_160 ( V_144 ) ;
V_147 = F_161 () ;
F_81 ( & V_132 ) ;
while ( ! F_50 ( & V_24 -> V_135 ) ) {
struct V_22 * V_33 = F_59 ( & V_24 -> V_135 ,
struct V_22 , V_134 ) ;
struct V_14 * V_15 = V_33 -> V_15 ;
struct V_2 * V_6 , * V_67 ;
F_157 ( V_150 ) ;
F_95 ( & V_33 -> V_134 ) ;
F_82 ( & V_132 ) ;
F_123 ( V_15 ) ;
V_133 -> V_15 = V_15 ;
F_9 ( ! F_50 ( & V_133 -> V_115 ) ) ;
F_162 (work, n, &pool->worklist, entry)
if ( F_39 ( V_6 ) == V_33 )
F_74 ( V_6 , V_115 , & V_67 ) ;
F_156 ( V_133 ) ;
F_78 ( V_33 ) ;
if ( F_52 ( V_15 ) )
F_60 ( V_15 ) ;
V_133 -> V_15 = NULL ;
F_96 ( & V_15 -> V_69 ) ;
F_94 ( & V_132 ) ;
}
F_82 ( & V_132 ) ;
if ( V_147 ) {
F_157 ( V_150 ) ;
V_133 -> V_54 -> V_32 &= ~ V_139 ;
return 0 ;
}
F_9 ( ! ( V_133 -> V_32 & V_57 ) ) ;
F_158 () ;
goto V_149;
}
static void F_163 ( struct V_2 * V_6 )
{
struct V_151 * V_152 = F_164 ( V_6 , struct V_151 , V_6 ) ;
F_88 ( & V_152 -> V_83 ) ;
}
static void F_165 ( struct V_22 * V_33 ,
struct V_151 * V_152 ,
struct V_2 * V_153 , struct V_52 * V_52 )
{
struct V_64 * V_65 ;
unsigned int V_154 = 0 ;
F_166 ( & V_152 -> V_6 , F_163 ) ;
F_167 ( V_86 , F_7 ( & V_152 -> V_6 ) ) ;
F_168 ( & V_152 -> V_83 ) ;
if ( V_52 )
V_65 = V_52 -> V_115 . V_109 ;
else {
unsigned long * V_155 = F_7 ( V_153 ) ;
V_65 = V_153 -> V_53 . V_109 ;
V_154 = * V_155 & V_68 ;
F_167 ( V_156 , V_155 ) ;
}
F_13 ( & V_152 -> V_6 ) ;
F_99 ( V_33 , & V_152 -> V_6 , V_65 ,
F_27 ( V_76 ) | V_154 ) ;
}
static bool F_169 ( struct V_23 * V_24 ,
int V_80 , int V_100 )
{
bool V_157 = false ;
struct V_22 * V_33 ;
if ( V_80 >= 0 ) {
F_9 ( F_48 ( & V_24 -> V_81 ) ) ;
F_170 ( & V_24 -> V_81 , 1 ) ;
}
F_171 (pwq, wq) {
struct V_14 * V_15 = V_33 -> V_15 ;
F_81 ( & V_15 -> V_69 ) ;
if ( V_80 >= 0 ) {
F_9 ( V_33 -> V_80 != - 1 ) ;
if ( V_33 -> V_78 [ V_80 ] ) {
V_33 -> V_80 = V_80 ;
F_65 ( & V_24 -> V_81 ) ;
V_157 = true ;
}
}
if ( V_100 >= 0 ) {
F_9 ( V_100 != F_29 ( V_33 -> V_100 ) ) ;
V_33 -> V_100 = V_100 ;
}
F_82 ( & V_15 -> V_69 ) ;
}
if ( V_80 >= 0 && F_68 ( & V_24 -> V_81 ) )
F_88 ( & V_24 -> V_82 -> V_83 ) ;
return V_157 ;
}
void F_172 ( struct V_23 * V_24 )
{
struct V_158 V_159 = {
. V_160 = F_173 ( V_159 . V_160 ) ,
. V_80 = - 1 ,
. V_83 = F_174 ( V_159 . V_83 ) ,
} ;
int V_161 ;
F_175 ( & V_24 -> V_162 ) ;
F_176 ( & V_24 -> V_162 ) ;
F_139 ( & V_24 -> V_163 ) ;
V_161 = F_29 ( V_24 -> V_100 ) ;
if ( V_161 != V_24 -> V_80 ) {
F_9 ( ! F_50 ( & V_24 -> V_164 ) ) ;
V_159 . V_80 = V_24 -> V_100 ;
V_24 -> V_100 = V_161 ;
if ( ! V_24 -> V_82 ) {
F_9 ( V_24 -> V_80 != V_159 . V_80 ) ;
V_24 -> V_82 = & V_159 ;
if ( ! F_169 ( V_24 , V_24 -> V_80 ,
V_24 -> V_100 ) ) {
V_24 -> V_80 = V_161 ;
V_24 -> V_82 = NULL ;
goto V_165;
}
} else {
F_9 ( V_24 -> V_80 == V_159 . V_80 ) ;
F_100 ( & V_159 . V_160 , & V_24 -> V_166 ) ;
F_169 ( V_24 , - 1 , V_24 -> V_100 ) ;
}
} else {
F_100 ( & V_159 . V_160 , & V_24 -> V_164 ) ;
}
F_140 ( & V_24 -> V_163 ) ;
F_177 ( & V_159 . V_83 ) ;
if ( V_24 -> V_82 != & V_159 )
return;
F_139 ( & V_24 -> V_163 ) ;
if ( V_24 -> V_82 != & V_159 )
goto V_165;
V_24 -> V_82 = NULL ;
F_9 ( ! F_50 ( & V_159 . V_160 ) ) ;
F_9 ( V_24 -> V_80 != V_159 . V_80 ) ;
while ( true ) {
struct V_158 * V_109 , * V_167 ;
F_162 (next, tmp, &wq->flusher_queue, list) {
if ( V_109 -> V_80 != V_24 -> V_80 )
break;
F_95 ( & V_109 -> V_160 ) ;
F_88 ( & V_109 -> V_83 ) ;
}
F_9 ( ! F_50 ( & V_24 -> V_164 ) &&
V_24 -> V_80 != F_29 ( V_24 -> V_100 ) ) ;
V_24 -> V_80 = F_29 ( V_24 -> V_80 ) ;
if ( ! F_50 ( & V_24 -> V_164 ) ) {
F_150 (tmp, &wq->flusher_overflow, list)
V_167 -> V_80 = V_24 -> V_100 ;
V_24 -> V_100 = F_29 ( V_24 -> V_100 ) ;
F_178 ( & V_24 -> V_164 ,
& V_24 -> V_166 ) ;
F_169 ( V_24 , - 1 , V_24 -> V_100 ) ;
}
if ( F_50 ( & V_24 -> V_166 ) ) {
F_9 ( V_24 -> V_80 != V_24 -> V_100 ) ;
break;
}
F_9 ( V_24 -> V_80 == V_24 -> V_100 ) ;
F_9 ( V_24 -> V_80 != V_109 -> V_80 ) ;
F_95 ( & V_109 -> V_160 ) ;
V_24 -> V_82 = V_109 ;
if ( F_169 ( V_24 , V_24 -> V_80 , - 1 ) )
break;
V_24 -> V_82 = NULL ;
}
V_165:
F_140 ( & V_24 -> V_163 ) ;
}
void F_179 ( struct V_23 * V_24 )
{
unsigned int V_168 = 0 ;
struct V_22 * V_33 ;
F_139 ( & V_24 -> V_163 ) ;
if ( ! V_24 -> V_169 ++ )
V_24 -> V_32 |= V_95 ;
F_140 ( & V_24 -> V_163 ) ;
V_170:
F_172 ( V_24 ) ;
F_139 ( & V_24 -> V_163 ) ;
F_171 (pwq, wq) {
bool V_171 ;
F_81 ( & V_33 -> V_15 -> V_69 ) ;
V_171 = ! V_33 -> V_74 && F_50 ( & V_33 -> V_75 ) ;
F_82 ( & V_33 -> V_15 -> V_69 ) ;
if ( V_171 )
continue;
if ( ++ V_168 == 10 ||
( V_168 % 100 == 0 && V_168 <= 1000 ) )
F_180 ( L_7 ,
V_24 -> V_99 , V_168 ) ;
F_140 ( & V_24 -> V_163 ) ;
goto V_170;
}
if ( ! -- V_24 -> V_169 )
V_24 -> V_32 &= ~ V_95 ;
F_140 ( & V_24 -> V_163 ) ;
}
static bool F_181 ( struct V_2 * V_6 , struct V_151 * V_152 )
{
struct V_52 * V_52 = NULL ;
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_182 () ;
F_183 () ;
V_15 = F_41 ( V_6 ) ;
if ( ! V_15 ) {
F_184 () ;
return false ;
}
F_94 ( & V_15 -> V_69 ) ;
V_33 = F_39 ( V_6 ) ;
if ( V_33 ) {
if ( F_58 ( V_33 -> V_15 != V_15 ) )
goto V_172;
} else {
V_52 = F_72 ( V_15 , V_6 ) ;
if ( ! V_52 )
goto V_172;
V_33 = V_52 -> V_91 ;
}
F_165 ( V_33 , V_152 , V_6 , V_52 ) ;
F_82 ( & V_15 -> V_69 ) ;
if ( V_33 -> V_24 -> V_173 == 1 || V_33 -> V_24 -> V_133 )
F_175 ( & V_33 -> V_24 -> V_162 ) ;
else
F_185 ( & V_33 -> V_24 -> V_162 ) ;
F_176 ( & V_33 -> V_24 -> V_162 ) ;
return true ;
V_172:
F_82 ( & V_15 -> V_69 ) ;
return false ;
}
bool F_186 ( struct V_2 * V_6 )
{
struct V_151 V_152 ;
F_175 ( & V_6 -> V_162 ) ;
F_176 ( & V_6 -> V_162 ) ;
if ( F_181 ( V_6 , & V_152 ) ) {
F_177 ( & V_152 . V_83 ) ;
F_18 ( & V_152 . V_6 ) ;
return true ;
} else {
return false ;
}
}
static bool F_187 ( struct V_2 * V_6 , bool V_84 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_89 ( V_6 , V_84 , & V_32 ) ;
if ( F_58 ( V_16 == - V_89 ) )
F_186 ( V_6 ) ;
} while ( F_58 ( V_16 < 0 ) );
F_45 ( V_6 ) ;
F_97 ( V_32 ) ;
F_186 ( V_6 ) ;
F_38 ( V_6 ) ;
return V_16 ;
}
bool F_3 ( struct V_2 * V_6 )
{
return F_187 ( V_6 , false ) ;
}
bool F_188 ( struct V_12 * V_85 )
{
F_183 () ;
if ( F_189 ( & V_85 -> V_13 ) )
F_104 ( V_85 -> V_56 , V_85 -> V_24 , & V_85 -> V_6 ) ;
F_184 () ;
return F_186 ( & V_85 -> V_6 ) ;
}
bool F_190 ( struct V_12 * V_85 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_89 ( & V_85 -> V_6 , true , & V_32 ) ;
} while ( F_58 ( V_16 == - V_90 ) );
if ( F_58 ( V_16 < 0 ) )
return false ;
F_36 ( & V_85 -> V_6 ,
F_44 ( & V_85 -> V_6 ) ) ;
F_97 ( V_32 ) ;
return V_16 ;
}
bool F_191 ( struct V_12 * V_85 )
{
return F_187 ( & V_85 -> V_6 , true ) ;
}
int F_192 ( T_1 V_3 )
{
int V_56 ;
struct V_2 T_2 * V_174 ;
V_174 = F_193 ( struct V_2 ) ;
if ( ! V_174 )
return - V_128 ;
F_194 () ;
F_195 (cpu) {
struct V_2 * V_6 = F_106 ( V_174 , V_56 ) ;
F_196 ( V_6 , V_3 ) ;
F_197 ( V_56 , V_6 ) ;
}
F_195 (cpu)
F_186 ( F_106 ( V_174 , V_56 ) ) ;
F_198 () ;
F_199 ( V_174 ) ;
return 0 ;
}
void F_200 ( void )
{
F_172 ( V_175 ) ;
}
int F_201 ( T_1 V_176 , struct V_177 * V_178 )
{
if ( ! F_202 () ) {
V_176 ( & V_178 -> V_6 ) ;
return 0 ;
}
F_196 ( & V_178 -> V_6 , V_176 ) ;
F_79 ( & V_178 -> V_6 ) ;
return 1 ;
}
static struct V_23 * F_203 ( struct V_179 * V_180 )
{
struct V_181 * V_182 = F_164 ( V_180 , struct V_181 , V_180 ) ;
return V_182 -> V_24 ;
}
static T_3 F_204 ( struct V_179 * V_180 , struct V_183 * V_184 ,
char * V_185 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
return F_205 ( V_185 , V_186 , L_8 , ( bool ) ! ( V_24 -> V_32 & V_71 ) ) ;
}
static T_3 F_206 ( struct V_179 * V_180 ,
struct V_183 * V_184 , char * V_185 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
return F_205 ( V_185 , V_186 , L_8 , V_24 -> V_173 ) ;
}
static T_3 F_207 ( struct V_179 * V_180 ,
struct V_183 * V_184 , const char * V_185 ,
T_4 V_187 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
int V_188 ;
if ( sscanf ( V_185 , L_9 , & V_188 ) != 1 || V_188 <= 0 )
return - V_189 ;
F_208 ( V_24 , V_188 ) ;
return V_187 ;
}
static T_3 F_209 ( struct V_179 * V_180 ,
struct V_183 * V_184 , char * V_185 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
const char * V_190 = L_4 ;
int V_25 , V_191 = 0 ;
F_210 () ;
F_211 (node) {
V_191 += F_205 ( V_185 + V_191 , V_186 - V_191 ,
L_10 , V_190 , V_25 ,
F_24 ( V_24 , V_25 ) -> V_15 -> V_21 ) ;
V_190 = L_11 ;
}
V_191 += F_205 ( V_185 + V_191 , V_186 - V_191 , L_12 ) ;
F_212 () ;
return V_191 ;
}
static T_3 F_213 ( struct V_179 * V_180 , struct V_183 * V_184 ,
char * V_185 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
int V_191 ;
F_139 ( & V_24 -> V_163 ) ;
V_191 = F_205 ( V_185 , V_186 , L_8 , V_24 -> V_192 -> V_122 ) ;
F_140 ( & V_24 -> V_163 ) ;
return V_191 ;
}
static struct V_193 * F_214 ( struct V_23 * V_24 )
{
struct V_193 * V_121 ;
V_121 = F_215 ( V_20 ) ;
if ( ! V_121 )
return NULL ;
F_139 ( & V_24 -> V_163 ) ;
F_216 ( V_121 , V_24 -> V_192 ) ;
F_140 ( & V_24 -> V_163 ) ;
return V_121 ;
}
static T_3 F_217 ( struct V_179 * V_180 , struct V_183 * V_184 ,
const char * V_185 , T_4 V_187 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
struct V_193 * V_121 ;
int V_16 ;
V_121 = F_214 ( V_24 ) ;
if ( ! V_121 )
return - V_128 ;
if ( sscanf ( V_185 , L_9 , & V_121 -> V_122 ) == 1 &&
V_121 -> V_122 >= V_194 && V_121 -> V_122 <= V_195 )
V_16 = F_218 ( V_24 , V_121 ) ;
else
V_16 = - V_189 ;
F_219 ( V_121 ) ;
return V_16 ? : V_187 ;
}
static T_3 F_220 ( struct V_179 * V_180 ,
struct V_183 * V_184 , char * V_185 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
int V_191 ;
F_139 ( & V_24 -> V_163 ) ;
V_191 = F_221 ( V_185 , V_186 , V_24 -> V_192 -> V_125 ) ;
F_140 ( & V_24 -> V_163 ) ;
V_191 += F_205 ( V_185 + V_191 , V_186 - V_191 , L_12 ) ;
return V_191 ;
}
static T_3 F_222 ( struct V_179 * V_180 ,
struct V_183 * V_184 ,
const char * V_185 , T_4 V_187 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
struct V_193 * V_121 ;
int V_16 ;
V_121 = F_214 ( V_24 ) ;
if ( ! V_121 )
return - V_128 ;
V_16 = F_223 ( V_185 , V_121 -> V_125 ) ;
if ( ! V_16 )
V_16 = F_218 ( V_24 , V_121 ) ;
F_219 ( V_121 ) ;
return V_16 ? : V_187 ;
}
static T_3 F_224 ( struct V_179 * V_180 , struct V_183 * V_184 ,
char * V_185 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
int V_191 ;
F_139 ( & V_24 -> V_163 ) ;
V_191 = F_205 ( V_185 , V_186 , L_8 ,
! V_24 -> V_192 -> V_196 ) ;
F_140 ( & V_24 -> V_163 ) ;
return V_191 ;
}
static T_3 F_225 ( struct V_179 * V_180 , struct V_183 * V_184 ,
const char * V_185 , T_4 V_187 )
{
struct V_23 * V_24 = F_203 ( V_180 ) ;
struct V_193 * V_121 ;
int V_197 , V_16 ;
V_121 = F_214 ( V_24 ) ;
if ( ! V_121 )
return - V_128 ;
V_16 = - V_189 ;
if ( sscanf ( V_185 , L_9 , & V_197 ) == 1 ) {
V_121 -> V_196 = ! V_197 ;
V_16 = F_218 ( V_24 , V_121 ) ;
}
F_219 ( V_121 ) ;
return V_16 ? : V_187 ;
}
static int T_5 F_226 ( void )
{
return F_227 ( & V_198 , NULL ) ;
}
static void F_228 ( struct V_179 * V_180 )
{
struct V_181 * V_182 = F_164 ( V_180 , struct V_181 , V_180 ) ;
F_136 ( V_182 ) ;
}
int F_229 ( struct V_23 * V_24 )
{
struct V_181 * V_182 ;
int V_16 ;
if ( F_10 ( V_24 -> V_32 & V_199 ) )
return - V_189 ;
V_24 -> V_182 = V_182 = F_125 ( sizeof( * V_182 ) , V_20 ) ;
if ( ! V_182 )
return - V_128 ;
V_182 -> V_24 = V_24 ;
V_182 -> V_180 . V_200 = & V_198 ;
V_182 -> V_180 . V_201 = V_24 -> V_99 ;
V_182 -> V_180 . V_202 = F_228 ;
F_230 ( & V_182 -> V_180 , true ) ;
V_16 = F_231 ( & V_182 -> V_180 ) ;
if ( V_16 ) {
F_136 ( V_182 ) ;
V_24 -> V_182 = NULL ;
return V_16 ;
}
if ( V_24 -> V_32 & V_71 ) {
struct V_183 * V_184 ;
for ( V_184 = V_203 ; V_184 -> V_184 . V_99 ; V_184 ++ ) {
V_16 = F_232 ( & V_182 -> V_180 , V_184 ) ;
if ( V_16 ) {
F_233 ( & V_182 -> V_180 ) ;
V_24 -> V_182 = NULL ;
return V_16 ;
}
}
}
F_234 ( & V_182 -> V_180 . V_204 , V_205 ) ;
return 0 ;
}
static void F_235 ( struct V_23 * V_24 )
{
struct V_181 * V_182 = V_24 -> V_182 ;
if ( ! V_24 -> V_182 )
return;
V_24 -> V_182 = NULL ;
F_233 ( & V_182 -> V_180 ) ;
}
static void F_235 ( struct V_23 * V_24 ) { }
void F_219 ( struct V_193 * V_121 )
{
if ( V_121 ) {
F_236 ( V_121 -> V_125 ) ;
F_136 ( V_121 ) ;
}
}
struct V_193 * F_215 ( T_6 V_206 )
{
struct V_193 * V_121 ;
V_121 = F_125 ( sizeof( * V_121 ) , V_206 ) ;
if ( ! V_121 )
goto V_87;
if ( ! F_237 ( & V_121 -> V_125 , V_206 ) )
goto V_87;
F_238 ( V_121 -> V_125 , V_207 ) ;
return V_121 ;
V_87:
F_219 ( V_121 ) ;
return NULL ;
}
static void F_216 ( struct V_193 * V_208 ,
const struct V_193 * V_209 )
{
V_208 -> V_122 = V_209 -> V_122 ;
F_238 ( V_208 -> V_125 , V_209 -> V_125 ) ;
V_208 -> V_196 = V_209 -> V_196 ;
}
static T_7 F_239 ( const struct V_193 * V_121 )
{
T_7 V_210 = 0 ;
V_210 = F_240 ( V_121 -> V_122 , V_210 ) ;
V_210 = F_241 ( F_242 ( V_121 -> V_125 ) ,
F_243 ( V_211 ) * sizeof( long ) , V_210 ) ;
return V_210 ;
}
static bool F_244 ( const struct V_193 * V_212 ,
const struct V_193 * V_213 )
{
if ( V_212 -> V_122 != V_213 -> V_122 )
return false ;
if ( ! F_245 ( V_212 -> V_125 , V_213 -> V_125 ) )
return false ;
return true ;
}
static int F_246 ( struct V_14 * V_15 )
{
F_247 ( & V_15 -> V_69 ) ;
V_15 -> V_21 = - 1 ;
V_15 -> V_56 = - 1 ;
V_15 -> V_25 = V_214 ;
V_15 -> V_32 |= V_114 ;
F_126 ( & V_15 -> V_43 ) ;
F_126 ( & V_15 -> V_50 ) ;
F_248 ( V_15 -> V_215 ) ;
F_249 ( & V_15 -> V_112 ) ;
V_15 -> V_112 . V_104 = F_145 ;
V_15 -> V_112 . V_31 = ( unsigned long ) V_15 ;
F_250 ( & V_15 -> V_136 , F_149 ,
( unsigned long ) V_15 ) ;
F_251 ( & V_15 -> V_47 ) ;
F_251 ( & V_15 -> V_118 ) ;
F_252 ( & V_15 -> V_119 ) ;
F_253 ( & V_15 -> V_216 ) ;
V_15 -> V_70 = 1 ;
V_15 -> V_121 = F_215 ( V_20 ) ;
if ( ! V_15 -> V_121 )
return - V_128 ;
return 0 ;
}
static void F_254 ( struct V_217 * V_218 )
{
struct V_14 * V_15 = F_164 ( V_218 , struct V_14 , V_218 ) ;
F_255 ( & V_15 -> V_119 ) ;
F_219 ( V_15 -> V_121 ) ;
F_136 ( V_15 ) ;
}
static void F_256 ( struct V_14 * V_15 )
{
struct V_52 * V_52 ;
F_22 ( & V_17 ) ;
if ( -- V_15 -> V_70 )
return;
if ( F_10 ( ! ( V_15 -> V_32 & V_114 ) ) ||
F_10 ( ! F_50 ( & V_15 -> V_43 ) ) )
return;
if ( V_15 -> V_21 >= 0 )
F_135 ( & V_18 , V_15 -> V_21 ) ;
F_257 ( & V_15 -> V_216 ) ;
F_139 ( & V_15 -> V_47 ) ;
F_139 ( & V_15 -> V_118 ) ;
F_81 ( & V_15 -> V_69 ) ;
while ( ( V_52 = F_57 ( V_15 ) ) )
F_141 ( V_52 ) ;
F_10 ( V_15 -> V_49 || V_15 -> V_44 ) ;
F_82 ( & V_15 -> V_69 ) ;
F_140 ( & V_15 -> V_118 ) ;
F_140 ( & V_15 -> V_47 ) ;
F_189 ( & V_15 -> V_112 ) ;
F_189 ( & V_15 -> V_136 ) ;
F_258 ( & V_15 -> V_218 , F_254 ) ;
}
static struct V_14 * F_259 ( const struct V_193 * V_121 )
{
T_7 V_210 = F_239 ( V_121 ) ;
struct V_14 * V_15 ;
int V_25 ;
F_22 ( & V_17 ) ;
F_73 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_244 ( V_15 -> V_121 , V_121 ) ) {
V_15 -> V_70 ++ ;
goto V_165;
}
}
V_15 = F_125 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 || F_246 ( V_15 ) < 0 )
goto V_87;
if ( V_219 )
V_15 -> V_32 |= V_220 ;
F_260 ( & V_15 -> V_69 , 1 ) ;
F_216 ( V_15 -> V_121 , V_121 ) ;
V_15 -> V_121 -> V_196 = false ;
if ( V_221 ) {
F_211 (node) {
if ( F_261 ( V_15 -> V_121 -> V_125 ,
V_222 [ V_25 ] ) ) {
V_15 -> V_25 = V_25 ;
break;
}
}
}
if ( F_21 ( V_15 ) < 0 )
goto V_87;
if ( F_138 ( V_15 ) < 0 )
goto V_87;
F_262 ( V_223 , & V_15 -> V_216 , V_210 ) ;
V_165:
return V_15 ;
V_87:
if ( V_15 )
F_256 ( V_15 ) ;
return NULL ;
}
static void F_263 ( struct V_217 * V_218 )
{
F_264 ( V_224 ,
F_164 ( V_218 , struct V_22 , V_218 ) ) ;
}
static void F_265 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_164 ( V_6 , struct V_22 ,
V_72 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
struct V_14 * V_15 = V_33 -> V_15 ;
bool V_225 ;
if ( F_9 ( ! ( V_24 -> V_32 & V_71 ) ) )
return;
F_139 ( & V_24 -> V_163 ) ;
F_266 ( & V_33 -> V_226 ) ;
V_225 = F_50 ( & V_24 -> V_227 ) ;
F_140 ( & V_24 -> V_163 ) ;
F_139 ( & V_17 ) ;
F_256 ( V_15 ) ;
F_140 ( & V_17 ) ;
F_258 ( & V_33 -> V_218 , F_263 ) ;
if ( V_225 ) {
F_219 ( V_24 -> V_192 ) ;
F_136 ( V_24 ) ;
}
}
static void F_267 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
bool V_228 = V_24 -> V_32 & V_229 ;
F_22 ( & V_24 -> V_163 ) ;
if ( ! V_228 && V_33 -> V_79 == V_24 -> V_173 )
return;
F_81 ( & V_33 -> V_15 -> V_69 ) ;
if ( ! V_228 || ! ( V_33 -> V_15 -> V_32 & V_220 ) ) {
V_33 -> V_79 = V_24 -> V_173 ;
while ( ! F_50 ( & V_33 -> V_75 ) &&
V_33 -> V_74 < V_33 -> V_79 )
F_86 ( V_33 ) ;
F_60 ( V_33 -> V_15 ) ;
} else {
V_33 -> V_79 = 0 ;
}
F_82 ( & V_33 -> V_15 -> V_69 ) ;
}
static void F_268 ( struct V_22 * V_33 , struct V_23 * V_24 ,
struct V_14 * V_15 )
{
F_269 ( ( unsigned long ) V_33 & V_230 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_15 = V_15 ;
V_33 -> V_24 = V_24 ;
V_33 -> V_80 = - 1 ;
V_33 -> V_70 = 1 ;
F_126 ( & V_33 -> V_75 ) ;
F_126 ( & V_33 -> V_226 ) ;
F_126 ( & V_33 -> V_134 ) ;
F_196 ( & V_33 -> V_72 , F_265 ) ;
}
static void F_270 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
F_22 ( & V_24 -> V_163 ) ;
if ( ! F_50 ( & V_33 -> V_226 ) )
return;
V_33 -> V_100 = V_24 -> V_100 ;
F_267 ( V_33 ) ;
F_271 ( & V_33 -> V_226 , & V_24 -> V_227 ) ;
}
static struct V_22 * F_272 ( struct V_23 * V_24 ,
const struct V_193 * V_121 )
{
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_22 ( & V_17 ) ;
V_15 = F_259 ( V_121 ) ;
if ( ! V_15 )
return NULL ;
V_33 = F_273 ( V_224 , V_20 , V_15 -> V_25 ) ;
if ( ! V_33 ) {
F_256 ( V_15 ) ;
return NULL ;
}
F_268 ( V_33 , V_24 , V_15 ) ;
return V_33 ;
}
static void F_274 ( struct V_22 * V_33 )
{
F_22 ( & V_17 ) ;
if ( V_33 ) {
F_256 ( V_33 -> V_15 ) ;
F_264 ( V_224 , V_33 ) ;
}
}
static bool F_275 ( const struct V_193 * V_121 , int V_25 ,
int V_231 , T_8 * V_125 )
{
if ( ! V_221 || V_121 -> V_196 )
goto V_232;
F_276 ( V_125 , F_277 ( V_25 ) , V_121 -> V_125 ) ;
if ( V_231 >= 0 )
F_278 ( V_231 , V_125 ) ;
if ( F_279 ( V_125 ) )
goto V_232;
F_276 ( V_125 , V_121 -> V_125 , V_222 [ V_25 ] ) ;
return ! F_245 ( V_125 , V_121 -> V_125 ) ;
V_232:
F_238 ( V_125 , V_121 -> V_125 ) ;
return false ;
}
static struct V_22 * F_280 ( struct V_23 * V_24 ,
int V_25 ,
struct V_22 * V_33 )
{
struct V_22 * V_233 ;
F_22 ( & V_24 -> V_163 ) ;
F_270 ( V_33 ) ;
V_233 = F_281 ( V_24 -> V_26 [ V_25 ] ) ;
F_282 ( V_24 -> V_26 [ V_25 ] , V_33 ) ;
return V_233 ;
}
int F_218 ( struct V_23 * V_24 ,
const struct V_193 * V_121 )
{
struct V_193 * V_234 , * V_235 ;
struct V_22 * * V_236 , * V_237 ;
int V_25 , V_16 ;
if ( F_10 ( ! ( V_24 -> V_32 & V_71 ) ) )
return - V_189 ;
if ( F_10 ( ( V_24 -> V_32 & V_199 ) && ! F_50 ( & V_24 -> V_227 ) ) )
return - V_189 ;
V_236 = F_125 ( V_238 * sizeof( V_236 [ 0 ] ) , V_20 ) ;
V_234 = F_215 ( V_20 ) ;
V_235 = F_215 ( V_20 ) ;
if ( ! V_236 || ! V_234 || ! V_235 )
goto V_239;
F_216 ( V_234 , V_121 ) ;
F_276 ( V_234 -> V_125 , V_234 -> V_125 , V_207 ) ;
F_216 ( V_235 , V_234 ) ;
F_194 () ;
F_139 ( & V_17 ) ;
V_237 = F_272 ( V_24 , V_234 ) ;
if ( ! V_237 )
goto V_240;
F_211 (node) {
if ( F_275 ( V_121 , V_25 , - 1 , V_235 -> V_125 ) ) {
V_236 [ V_25 ] = F_272 ( V_24 , V_235 ) ;
if ( ! V_236 [ V_25 ] )
goto V_240;
} else {
V_237 -> V_70 ++ ;
V_236 [ V_25 ] = V_237 ;
}
}
F_140 ( & V_17 ) ;
F_139 ( & V_24 -> V_163 ) ;
F_216 ( V_24 -> V_192 , V_234 ) ;
F_211 (node)
V_236 [ V_25 ] = F_280 ( V_24 , V_25 , V_236 [ V_25 ] ) ;
F_270 ( V_237 ) ;
F_283 ( V_24 -> V_237 , V_237 ) ;
F_140 ( & V_24 -> V_163 ) ;
F_211 (node)
F_80 ( V_236 [ V_25 ] ) ;
F_80 ( V_237 ) ;
F_198 () ;
V_16 = 0 ;
V_241:
F_219 ( V_235 ) ;
F_219 ( V_234 ) ;
F_136 ( V_236 ) ;
return V_16 ;
V_240:
F_274 ( V_237 ) ;
F_211 (node)
if ( V_236 && V_236 [ V_25 ] != V_237 )
F_274 ( V_236 [ V_25 ] ) ;
F_140 ( & V_17 ) ;
F_198 () ;
V_239:
V_16 = - V_128 ;
goto V_241;
}
static void F_284 ( struct V_23 * V_24 , int V_56 ,
bool V_242 )
{
int V_25 = F_107 ( V_56 ) ;
int V_243 = V_242 ? - 1 : V_56 ;
struct V_22 * V_233 = NULL , * V_33 ;
struct V_193 * V_244 ;
T_8 * V_125 ;
F_22 ( & V_17 ) ;
if ( ! V_221 || ! ( V_24 -> V_32 & V_71 ) )
return;
V_244 = V_245 ;
V_125 = V_244 -> V_125 ;
F_139 ( & V_24 -> V_163 ) ;
if ( V_24 -> V_192 -> V_196 )
goto V_165;
F_216 ( V_244 , V_24 -> V_192 ) ;
V_33 = F_24 ( V_24 , V_25 ) ;
if ( F_275 ( V_24 -> V_192 , V_25 , V_243 , V_125 ) ) {
if ( F_245 ( V_125 , V_33 -> V_15 -> V_121 -> V_125 ) )
goto V_165;
} else {
if ( V_33 == V_24 -> V_237 )
goto V_165;
else
goto V_246;
}
F_140 ( & V_24 -> V_163 ) ;
V_33 = F_272 ( V_24 , V_244 ) ;
if ( ! V_33 ) {
F_285 ( L_13 ,
V_24 -> V_99 ) ;
F_139 ( & V_24 -> V_163 ) ;
goto V_246;
}
F_139 ( & V_24 -> V_163 ) ;
V_233 = F_280 ( V_24 , V_25 , V_33 ) ;
goto V_165;
V_246:
F_81 ( & V_24 -> V_237 -> V_15 -> V_69 ) ;
F_77 ( V_24 -> V_237 ) ;
F_82 ( & V_24 -> V_237 -> V_15 -> V_69 ) ;
V_233 = F_280 ( V_24 , V_25 , V_24 -> V_237 ) ;
V_165:
F_140 ( & V_24 -> V_163 ) ;
F_80 ( V_233 ) ;
}
static int F_286 ( struct V_23 * V_24 )
{
bool V_247 = V_24 -> V_32 & V_248 ;
int V_56 , V_16 ;
if ( ! ( V_24 -> V_32 & V_71 ) ) {
V_24 -> V_98 = F_193 ( struct V_22 ) ;
if ( ! V_24 -> V_98 )
return - V_128 ;
F_287 (cpu) {
struct V_22 * V_33 =
F_106 ( V_24 -> V_98 , V_56 ) ;
struct V_14 * V_249 =
F_288 ( V_250 , V_56 ) ;
F_268 ( V_33 , V_24 , & V_249 [ V_247 ] ) ;
F_139 ( & V_24 -> V_163 ) ;
F_270 ( V_33 ) ;
F_140 ( & V_24 -> V_163 ) ;
}
return 0 ;
} else if ( V_24 -> V_32 & V_199 ) {
V_16 = F_218 ( V_24 , V_251 [ V_247 ] ) ;
F_289 ( ! V_16 && ( V_24 -> V_227 . V_109 != & V_24 -> V_237 -> V_226 ||
V_24 -> V_227 . V_131 != & V_24 -> V_237 -> V_226 ) ,
L_14 , V_24 -> V_99 ) ;
return V_16 ;
} else {
return F_218 ( V_24 , V_252 [ V_247 ] ) ;
}
}
static int F_290 ( int V_79 , unsigned int V_32 ,
const char * V_99 )
{
int V_253 = V_32 & V_71 ? V_254 : V_255 ;
if ( V_79 < 1 || V_79 > V_253 )
F_180 ( L_15 ,
V_79 , V_99 , 1 , V_253 ) ;
return F_291 ( V_79 , 1 , V_253 ) ;
}
struct V_23 * F_292 ( const char * V_256 ,
unsigned int V_32 ,
int V_79 ,
struct V_257 * V_258 ,
const char * V_259 , ... )
{
T_4 V_260 = 0 ;
T_9 args ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
if ( ( V_32 & V_261 ) && V_262 )
V_32 |= V_71 ;
if ( V_32 & V_71 )
V_260 = V_238 * sizeof( V_24 -> V_26 [ 0 ] ) ;
V_24 = F_125 ( sizeof( * V_24 ) + V_260 , V_20 ) ;
if ( ! V_24 )
return NULL ;
if ( V_32 & V_71 ) {
V_24 -> V_192 = F_215 ( V_20 ) ;
if ( ! V_24 -> V_192 )
goto V_263;
}
va_start ( args , V_259 ) ;
vsnprintf ( V_24 -> V_99 , sizeof( V_24 -> V_99 ) , V_256 , args ) ;
va_end ( args ) ;
V_79 = V_79 ? : V_264 ;
V_79 = F_290 ( V_79 , V_32 , V_24 -> V_99 ) ;
V_24 -> V_32 = V_32 ;
V_24 -> V_173 = V_79 ;
F_251 ( & V_24 -> V_163 ) ;
F_170 ( & V_24 -> V_81 , 0 ) ;
F_126 ( & V_24 -> V_227 ) ;
F_126 ( & V_24 -> V_166 ) ;
F_126 ( & V_24 -> V_164 ) ;
F_126 ( & V_24 -> V_135 ) ;
F_293 ( & V_24 -> V_162 , V_259 , V_258 , 0 ) ;
F_126 ( & V_24 -> V_160 ) ;
if ( F_286 ( V_24 ) < 0 )
goto V_263;
if ( V_32 & V_265 ) {
struct V_52 * V_133 ;
V_133 = F_124 () ;
if ( ! V_133 )
goto V_266;
V_133 -> V_146 = V_24 ;
V_133 -> V_54 = F_294 ( F_159 , V_133 , L_16 ,
V_24 -> V_99 ) ;
if ( F_131 ( V_133 -> V_54 ) ) {
F_136 ( V_133 ) ;
goto V_266;
}
V_24 -> V_133 = V_133 ;
V_133 -> V_54 -> V_32 |= V_124 ;
F_62 ( V_133 -> V_54 ) ;
}
if ( ( V_24 -> V_32 & V_267 ) && F_229 ( V_24 ) )
goto V_266;
F_139 ( & V_17 ) ;
F_139 ( & V_24 -> V_163 ) ;
F_171 (pwq, wq)
F_267 ( V_33 ) ;
F_140 ( & V_24 -> V_163 ) ;
F_120 ( & V_24 -> V_160 , & V_268 ) ;
F_140 ( & V_17 ) ;
return V_24 ;
V_263:
F_219 ( V_24 -> V_192 ) ;
F_136 ( V_24 ) ;
return NULL ;
V_266:
F_295 ( V_24 ) ;
return NULL ;
}
void F_295 ( struct V_23 * V_24 )
{
struct V_22 * V_33 ;
int V_25 ;
F_179 ( V_24 ) ;
F_139 ( & V_24 -> V_163 ) ;
F_171 (pwq, wq) {
int V_269 ;
for ( V_269 = 0 ; V_269 < V_30 ; V_269 ++ ) {
if ( F_10 ( V_33 -> V_78 [ V_269 ] ) ) {
F_140 ( & V_24 -> V_163 ) ;
return;
}
}
if ( F_10 ( ( V_33 != V_24 -> V_237 ) && ( V_33 -> V_70 > 1 ) ) ||
F_10 ( V_33 -> V_74 ) ||
F_10 ( ! F_50 ( & V_33 -> V_75 ) ) ) {
F_140 ( & V_24 -> V_163 ) ;
return;
}
}
F_140 ( & V_24 -> V_163 ) ;
F_139 ( & V_17 ) ;
F_95 ( & V_24 -> V_160 ) ;
F_140 ( & V_17 ) ;
F_235 ( V_24 ) ;
if ( V_24 -> V_133 ) {
F_143 ( V_24 -> V_133 -> V_54 ) ;
F_136 ( V_24 -> V_133 ) ;
V_24 -> V_133 = NULL ;
}
if ( ! ( V_24 -> V_32 & V_71 ) ) {
F_199 ( V_24 -> V_98 ) ;
F_136 ( V_24 ) ;
} else {
F_211 (node) {
V_33 = F_281 ( V_24 -> V_26 [ V_25 ] ) ;
F_296 ( V_24 -> V_26 [ V_25 ] , NULL ) ;
F_80 ( V_33 ) ;
}
V_33 = V_24 -> V_237 ;
V_24 -> V_237 = NULL ;
F_80 ( V_33 ) ;
}
}
void F_208 ( struct V_23 * V_24 , int V_79 )
{
struct V_22 * V_33 ;
if ( F_10 ( V_24 -> V_32 & V_199 ) )
return;
V_79 = F_290 ( V_79 , V_24 -> V_32 , V_24 -> V_99 ) ;
F_139 ( & V_24 -> V_163 ) ;
V_24 -> V_173 = V_79 ;
F_171 (pwq, wq)
F_267 ( V_33 ) ;
F_140 ( & V_24 -> V_163 ) ;
}
bool F_297 ( void )
{
struct V_52 * V_52 = F_103 () ;
return V_52 && V_52 -> V_146 ;
}
bool F_298 ( int V_56 , struct V_23 * V_24 )
{
struct V_22 * V_33 ;
bool V_16 ;
F_210 () ;
if ( V_56 == V_97 )
V_56 = F_299 () ;
if ( ! ( V_24 -> V_32 & V_71 ) )
V_33 = F_106 ( V_24 -> V_98 , V_56 ) ;
else
V_33 = F_24 ( V_24 , F_107 ( V_56 ) ) ;
V_16 = ! F_50 ( & V_33 -> V_75 ) ;
F_212 () ;
return V_16 ;
}
unsigned int F_300 ( struct V_2 * V_6 )
{
struct V_14 * V_15 ;
unsigned long V_32 ;
unsigned int V_16 = 0 ;
if ( F_31 ( V_6 ) )
V_16 |= V_270 ;
F_90 ( V_32 ) ;
V_15 = F_41 ( V_6 ) ;
if ( V_15 ) {
F_94 ( & V_15 -> V_69 ) ;
if ( F_72 ( V_15 , V_6 ) )
V_16 |= V_271 ;
F_96 ( & V_15 -> V_69 ) ;
}
F_97 ( V_32 ) ;
return V_16 ;
}
void F_301 ( const char * V_256 , ... )
{
struct V_52 * V_52 = F_103 () ;
T_9 args ;
if ( V_52 ) {
va_start ( args , V_256 ) ;
vsnprintf ( V_52 -> V_272 , sizeof( V_52 -> V_272 ) , V_256 , args ) ;
va_end ( args ) ;
V_52 -> V_273 = true ;
}
}
void F_302 ( const char * V_274 , struct V_55 * V_54 )
{
T_1 * V_176 = NULL ;
char V_99 [ V_275 ] = { } ;
char V_272 [ V_276 ] = { } ;
struct V_22 * V_33 = NULL ;
struct V_23 * V_24 = NULL ;
bool V_273 = false ;
struct V_52 * V_52 ;
if ( ! ( V_54 -> V_32 & V_139 ) )
return;
V_52 = F_303 ( V_54 ) ;
F_304 ( & V_176 , & V_52 -> V_63 , sizeof( V_176 ) ) ;
F_304 ( & V_33 , & V_52 -> V_91 , sizeof( V_33 ) ) ;
F_304 ( & V_24 , & V_33 -> V_24 , sizeof( V_24 ) ) ;
F_304 ( V_99 , V_24 -> V_99 , sizeof( V_99 ) - 1 ) ;
F_304 ( & V_273 , & V_52 -> V_273 , sizeof( V_273 ) ) ;
if ( V_273 )
F_304 ( V_272 , V_52 -> V_272 , sizeof( V_272 ) - 1 ) ;
if ( V_176 || V_99 [ 0 ] || V_272 [ 0 ] ) {
F_305 ( L_17 , V_274 , V_99 , V_176 ) ;
if ( V_272 [ 0 ] )
F_306 ( L_18 , V_272 ) ;
F_306 ( L_12 ) ;
}
}
static void F_307 ( struct V_2 * V_6 )
{
int V_56 = F_299 () ;
struct V_14 * V_15 ;
struct V_52 * V_52 ;
int V_277 ;
F_308 (pool, cpu) {
F_9 ( V_56 != F_299 () ) ;
F_139 ( & V_15 -> V_118 ) ;
F_81 ( & V_15 -> V_69 ) ;
F_309 (worker, wi, pool)
V_52 -> V_32 |= V_126 ;
V_15 -> V_32 |= V_114 ;
F_82 ( & V_15 -> V_69 ) ;
F_140 ( & V_15 -> V_118 ) ;
F_158 () ;
F_170 ( & V_15 -> V_42 , 0 ) ;
F_81 ( & V_15 -> V_69 ) ;
F_60 ( V_15 ) ;
F_82 ( & V_15 -> V_69 ) ;
}
}
static void F_310 ( struct V_14 * V_15 )
{
struct V_52 * V_52 ;
int V_277 ;
F_22 ( & V_15 -> V_118 ) ;
F_309 (worker, wi, pool)
F_9 ( F_133 ( V_52 -> V_54 ,
V_15 -> V_121 -> V_125 ) < 0 ) ;
F_81 ( & V_15 -> V_69 ) ;
F_309 (worker, wi, pool) {
unsigned int V_278 = V_52 -> V_32 ;
if ( V_278 & V_107 )
F_62 ( V_52 -> V_54 ) ;
F_9 ( ! ( V_278 & V_126 ) ) ;
V_278 |= V_143 ;
V_278 &= ~ V_126 ;
F_311 ( V_52 -> V_32 ) = V_278 ;
}
F_82 ( & V_15 -> V_69 ) ;
}
static void F_312 ( struct V_14 * V_15 , int V_56 )
{
static T_8 V_125 ;
struct V_52 * V_52 ;
int V_277 ;
F_22 ( & V_15 -> V_118 ) ;
if ( ! F_313 ( V_56 , V_15 -> V_121 -> V_125 ) )
return;
F_276 ( & V_125 , V_15 -> V_121 -> V_125 , V_279 ) ;
if ( F_314 ( & V_125 ) != 1 )
return;
F_309 (worker, wi, pool)
F_9 ( F_133 ( V_52 -> V_54 ,
V_15 -> V_121 -> V_125 ) < 0 ) ;
}
static int F_315 ( struct V_280 * V_281 ,
unsigned long V_282 ,
void * V_283 )
{
int V_56 = ( unsigned long ) V_283 ;
struct V_14 * V_15 ;
struct V_23 * V_24 ;
int V_284 ;
switch ( V_282 & ~ V_285 ) {
case V_286 :
F_308 (pool, cpu) {
if ( V_15 -> V_49 )
continue;
if ( F_138 ( V_15 ) < 0 )
return V_287 ;
}
break;
case V_288 :
case V_289 :
F_139 ( & V_17 ) ;
F_316 (pool, pi) {
F_139 ( & V_15 -> V_118 ) ;
if ( V_15 -> V_56 == V_56 ) {
F_81 ( & V_15 -> V_69 ) ;
V_15 -> V_32 &= ~ V_114 ;
F_82 ( & V_15 -> V_69 ) ;
F_310 ( V_15 ) ;
} else if ( V_15 -> V_56 < 0 ) {
F_312 ( V_15 , V_56 ) ;
}
F_140 ( & V_15 -> V_118 ) ;
}
F_150 (wq, &workqueues, list)
F_284 ( V_24 , V_56 , true ) ;
F_140 ( & V_17 ) ;
break;
}
return V_290 ;
}
static int F_317 ( struct V_280 * V_281 ,
unsigned long V_282 ,
void * V_283 )
{
int V_56 = ( unsigned long ) V_283 ;
struct V_2 V_291 ;
struct V_23 * V_24 ;
switch ( V_282 & ~ V_285 ) {
case V_292 :
F_166 ( & V_291 , F_307 ) ;
F_110 ( V_56 , V_293 , & V_291 ) ;
F_139 ( & V_17 ) ;
F_150 (wq, &workqueues, list)
F_284 ( V_24 , V_56 , false ) ;
F_140 ( & V_17 ) ;
F_186 ( & V_291 ) ;
F_18 ( & V_291 ) ;
break;
}
return V_290 ;
}
static void F_318 ( struct V_2 * V_6 )
{
struct V_294 * V_295 = F_164 ( V_6 , struct V_294 , V_6 ) ;
V_295 -> V_16 = V_295 -> V_176 ( V_295 -> V_296 ) ;
}
long F_319 ( int V_56 , long (* V_176)( void * ) , void * V_296 )
{
struct V_294 V_295 = { . V_176 = V_176 , . V_296 = V_296 } ;
F_166 ( & V_295 . V_6 , F_318 ) ;
F_197 ( V_56 , & V_295 . V_6 ) ;
F_186 ( & V_295 . V_6 ) ;
F_18 ( & V_295 . V_6 ) ;
return V_295 . V_16 ;
}
void F_320 ( void )
{
struct V_14 * V_15 ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
int V_284 ;
F_139 ( & V_17 ) ;
F_9 ( V_219 ) ;
V_219 = true ;
F_316 (pool, pi) {
F_81 ( & V_15 -> V_69 ) ;
F_9 ( V_15 -> V_32 & V_220 ) ;
V_15 -> V_32 |= V_220 ;
F_82 ( & V_15 -> V_69 ) ;
}
F_150 (wq, &workqueues, list) {
F_139 ( & V_24 -> V_163 ) ;
F_171 (pwq, wq)
F_267 ( V_33 ) ;
F_140 ( & V_24 -> V_163 ) ;
}
F_140 ( & V_17 ) ;
}
bool F_321 ( void )
{
bool V_297 = false ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_139 ( & V_17 ) ;
F_9 ( ! V_219 ) ;
F_150 (wq, &workqueues, list) {
if ( ! ( V_24 -> V_32 & V_229 ) )
continue;
F_210 () ;
F_171 (pwq, wq) {
F_9 ( V_33 -> V_74 < 0 ) ;
if ( V_33 -> V_74 ) {
V_297 = true ;
F_212 () ;
goto V_165;
}
}
F_212 () ;
}
V_165:
F_140 ( & V_17 ) ;
return V_297 ;
}
void F_322 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_33 ;
struct V_14 * V_15 ;
int V_284 ;
F_139 ( & V_17 ) ;
if ( ! V_219 )
goto V_165;
F_316 (pool, pi) {
F_81 ( & V_15 -> V_69 ) ;
F_9 ( ! ( V_15 -> V_32 & V_220 ) ) ;
V_15 -> V_32 &= ~ V_220 ;
F_82 ( & V_15 -> V_69 ) ;
}
F_150 (wq, &workqueues, list) {
F_139 ( & V_24 -> V_163 ) ;
F_171 (pwq, wq)
F_267 ( V_33 ) ;
F_140 ( & V_24 -> V_163 ) ;
}
V_219 = false ;
V_165:
F_140 ( & V_17 ) ;
}
static void T_5 F_323 ( void )
{
T_10 * V_298 ;
int V_25 , V_56 ;
F_211 (node)
V_238 = F_324 ( V_238 , V_25 + 1 ) ;
if ( F_325 () <= 1 )
return;
if ( V_299 ) {
F_326 ( L_19 ) ;
return;
}
V_245 = F_215 ( V_20 ) ;
F_269 ( ! V_245 ) ;
V_298 = F_125 ( V_238 * sizeof( V_298 [ 0 ] ) , V_20 ) ;
F_269 ( ! V_298 ) ;
F_211 (node)
F_269 ( ! F_327 ( & V_298 [ V_25 ] , V_20 ,
F_328 ( V_25 ) ? V_25 : V_214 ) ) ;
F_287 (cpu) {
V_25 = F_107 ( V_56 ) ;
if ( F_10 ( V_25 == V_214 ) ) {
F_180 ( L_20 , V_56 ) ;
return;
}
F_329 ( V_56 , V_298 [ V_25 ] ) ;
}
V_222 = V_298 ;
V_221 = true ;
}
static int T_5 F_330 ( void )
{
int V_300 [ V_301 ] = { 0 , V_302 } ;
int V_269 , V_56 ;
F_10 ( F_331 ( struct V_22 ) < F_331 (long long) ) ;
V_224 = F_332 ( V_22 , V_303 ) ;
F_333 ( F_315 , V_304 ) ;
F_334 ( F_317 , V_305 ) ;
F_323 () ;
F_287 (cpu) {
struct V_14 * V_15 ;
V_269 = 0 ;
F_308 (pool, cpu) {
F_269 ( F_246 ( V_15 ) ) ;
V_15 -> V_56 = V_56 ;
F_238 ( V_15 -> V_121 -> V_125 , F_335 ( V_56 ) ) ;
V_15 -> V_121 -> V_122 = V_300 [ V_269 ++ ] ;
V_15 -> V_25 = F_107 ( V_56 ) ;
F_139 ( & V_17 ) ;
F_269 ( F_21 ( V_15 ) ) ;
F_140 ( & V_17 ) ;
}
}
F_195 (cpu) {
struct V_14 * V_15 ;
F_308 (pool, cpu) {
V_15 -> V_32 &= ~ V_114 ;
F_269 ( F_138 ( V_15 ) < 0 ) ;
}
}
for ( V_269 = 0 ; V_269 < V_301 ; V_269 ++ ) {
struct V_193 * V_121 ;
F_269 ( ! ( V_121 = F_215 ( V_20 ) ) ) ;
V_121 -> V_122 = V_300 [ V_269 ] ;
V_252 [ V_269 ] = V_121 ;
F_269 ( ! ( V_121 = F_215 ( V_20 ) ) ) ;
V_121 -> V_122 = V_300 [ V_269 ] ;
V_121 -> V_196 = true ;
V_251 [ V_269 ] = V_121 ;
}
V_175 = F_336 ( L_21 , 0 , 0 ) ;
V_293 = F_336 ( L_22 , V_248 , 0 ) ;
V_306 = F_336 ( L_23 , 0 , 0 ) ;
V_307 = F_336 ( L_24 , V_71 ,
V_254 ) ;
V_308 = F_336 ( L_25 ,
V_229 , 0 ) ;
V_309 = F_336 ( L_26 ,
V_261 , 0 ) ;
V_310 = F_336 ( L_27 ,
V_229 | V_261 ,
0 ) ;
F_269 ( ! V_175 || ! V_293 || ! V_306 ||
! V_307 || ! V_308 ||
! V_309 ||
! V_310 ) ;
return 0 ;
}
