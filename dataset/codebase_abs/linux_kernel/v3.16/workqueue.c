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
bool V_45 = F_55 ( & V_15 -> V_46 ) ;
int V_44 = V_15 -> V_44 + V_45 ;
int V_47 = V_15 -> V_48 - V_44 ;
if ( F_50 ( & V_15 -> V_49 ) )
return false ;
return V_44 > 2 && ( V_44 - 2 ) * V_50 >= V_47 ;
}
static struct V_51 * F_56 ( struct V_14 * V_15 )
{
if ( F_57 ( F_50 ( & V_15 -> V_49 ) ) )
return NULL ;
return F_58 ( & V_15 -> V_49 , struct V_51 , V_52 ) ;
}
static void F_59 ( struct V_14 * V_15 )
{
struct V_51 * V_51 = F_56 ( V_15 ) ;
if ( F_60 ( V_51 ) )
F_61 ( V_51 -> V_53 ) ;
}
void F_62 ( struct V_54 * V_53 , int V_55 )
{
struct V_51 * V_51 = F_63 ( V_53 ) ;
if ( ! ( V_51 -> V_32 & V_56 ) ) {
F_9 ( V_51 -> V_15 -> V_55 != V_55 ) ;
F_64 ( & V_51 -> V_15 -> V_42 ) ;
}
}
struct V_54 * F_65 ( struct V_54 * V_53 , int V_55 )
{
struct V_51 * V_51 = F_63 ( V_53 ) , * V_57 = NULL ;
struct V_14 * V_15 ;
if ( V_51 -> V_32 & V_56 )
return NULL ;
V_15 = V_51 -> V_15 ;
if ( F_9 ( V_55 != F_66 () ) )
return NULL ;
if ( F_67 ( & V_15 -> V_42 ) &&
! F_50 ( & V_15 -> V_43 ) )
V_57 = F_56 ( V_15 ) ;
return V_57 ? V_57 -> V_53 : NULL ;
}
static inline void F_68 ( struct V_51 * V_51 , unsigned int V_32 ,
bool V_58 )
{
struct V_14 * V_15 = V_51 -> V_15 ;
F_9 ( V_51 -> V_53 != V_59 ) ;
if ( ( V_32 & V_56 ) &&
! ( V_51 -> V_32 & V_56 ) ) {
if ( V_58 ) {
if ( F_67 ( & V_15 -> V_42 ) &&
! F_50 ( & V_15 -> V_43 ) )
F_59 ( V_15 ) ;
} else
F_69 ( & V_15 -> V_42 ) ;
}
V_51 -> V_32 |= V_32 ;
}
static inline void F_70 ( struct V_51 * V_51 , unsigned int V_32 )
{
struct V_14 * V_15 = V_51 -> V_15 ;
unsigned int V_60 = V_51 -> V_32 ;
F_9 ( V_51 -> V_53 != V_59 ) ;
V_51 -> V_32 &= ~ V_32 ;
if ( ( V_32 & V_56 ) && ( V_60 & V_56 ) )
if ( ! ( V_51 -> V_32 & V_56 ) )
F_64 ( & V_15 -> V_42 ) ;
}
static struct V_51 * F_71 ( struct V_14 * V_15 ,
struct V_2 * V_6 )
{
struct V_51 * V_51 ;
F_72 (pool->busy_hash, worker, hentry,
(unsigned long)work)
if ( V_51 -> V_61 == V_6 &&
V_51 -> V_62 == V_6 -> V_3 )
return V_51 ;
return NULL ;
}
static void F_73 ( struct V_2 * V_6 , struct V_63 * V_64 ,
struct V_2 * * V_65 )
{
struct V_2 * V_66 ;
F_74 (work, n, NULL, entry) {
F_75 ( & V_6 -> V_52 , V_64 ) ;
if ( ! ( * F_7 ( V_6 ) & V_67 ) )
break;
}
if ( V_65 )
* V_65 = V_66 ;
}
static void F_76 ( struct V_22 * V_33 )
{
F_22 ( & V_33 -> V_15 -> V_68 ) ;
F_9 ( V_33 -> V_69 <= 0 ) ;
V_33 -> V_69 ++ ;
}
static void F_77 ( struct V_22 * V_33 )
{
F_22 ( & V_33 -> V_15 -> V_68 ) ;
if ( F_60 ( -- V_33 -> V_69 ) )
return;
if ( F_9 ( ! ( V_33 -> V_24 -> V_32 & V_70 ) ) )
return;
F_78 ( & V_33 -> V_71 ) ;
}
static void F_79 ( struct V_22 * V_33 )
{
if ( V_33 ) {
F_80 ( & V_33 -> V_15 -> V_68 ) ;
F_77 ( V_33 ) ;
F_81 ( & V_33 -> V_15 -> V_68 ) ;
}
}
static void F_82 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_39 ( V_6 ) ;
F_83 ( V_6 ) ;
F_73 ( V_6 , & V_33 -> V_15 -> V_43 , NULL ) ;
F_84 ( V_72 , F_7 ( V_6 ) ) ;
V_33 -> V_73 ++ ;
}
static void F_85 ( struct V_22 * V_33 )
{
struct V_2 * V_6 = F_58 ( & V_33 -> V_74 ,
struct V_2 , V_52 ) ;
F_82 ( V_6 ) ;
}
static void F_86 ( struct V_22 * V_33 , int V_27 )
{
if ( V_27 == V_75 )
goto V_76;
V_33 -> V_77 [ V_27 ] -- ;
V_33 -> V_73 -- ;
if ( ! F_50 ( & V_33 -> V_74 ) ) {
if ( V_33 -> V_73 < V_33 -> V_78 )
F_85 ( V_33 ) ;
}
if ( F_60 ( V_33 -> V_79 != V_27 ) )
goto V_76;
if ( V_33 -> V_77 [ V_27 ] )
goto V_76;
V_33 -> V_79 = - 1 ;
if ( F_67 ( & V_33 -> V_24 -> V_80 ) )
F_87 ( & V_33 -> V_24 -> V_81 -> V_82 ) ;
V_76:
F_77 ( V_33 ) ;
}
static int F_88 ( struct V_2 * V_6 , bool V_83 ,
unsigned long * V_32 )
{
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_89 ( * V_32 ) ;
if ( V_83 ) {
struct V_12 * V_84 = F_90 ( V_6 ) ;
if ( F_60 ( F_91 ( & V_84 -> V_13 ) ) )
return 1 ;
}
if ( ! F_92 ( V_85 , F_7 ( V_6 ) ) )
return 0 ;
V_15 = F_41 ( V_6 ) ;
if ( ! V_15 )
goto V_86;
F_93 ( & V_15 -> V_68 ) ;
V_33 = F_39 ( V_6 ) ;
if ( V_33 && V_33 -> V_15 == V_15 ) {
F_14 ( V_6 ) ;
if ( * F_7 ( V_6 ) & V_87 )
F_82 ( V_6 ) ;
F_94 ( & V_6 -> V_52 ) ;
F_86 ( F_39 ( V_6 ) , F_28 ( V_6 ) ) ;
F_35 ( V_6 , V_15 -> V_21 ) ;
F_95 ( & V_15 -> V_68 ) ;
return 1 ;
}
F_95 ( & V_15 -> V_68 ) ;
V_86:
F_96 ( * V_32 ) ;
if ( F_46 ( V_6 ) )
return - V_88 ;
F_97 () ;
return - V_89 ;
}
static void F_98 ( struct V_22 * V_33 , struct V_2 * V_6 ,
struct V_63 * V_64 , unsigned int V_34 )
{
struct V_14 * V_15 = V_33 -> V_15 ;
F_34 ( V_6 , V_33 , V_34 ) ;
F_99 ( & V_6 -> V_52 , V_64 ) ;
F_76 ( V_33 ) ;
F_100 () ;
if ( F_47 ( V_15 ) )
F_59 ( V_15 ) ;
}
static bool F_101 ( struct V_23 * V_24 )
{
struct V_51 * V_51 ;
V_51 = F_102 () ;
return V_51 && V_51 -> V_90 -> V_24 == V_24 ;
}
static void F_103 ( int V_55 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
struct V_22 * V_33 ;
struct V_14 * V_91 ;
struct V_63 * V_43 ;
unsigned int V_92 ;
unsigned int V_93 = V_55 ;
F_9 ( ! F_104 () ) ;
F_13 ( V_6 ) ;
if ( F_57 ( V_24 -> V_32 & V_94 ) &&
F_9 ( ! F_101 ( V_24 ) ) )
return;
V_95:
if ( V_93 == V_96 )
V_55 = F_66 () ;
if ( ! ( V_24 -> V_32 & V_70 ) )
V_33 = F_105 ( V_24 -> V_97 , V_55 ) ;
else
V_33 = F_24 ( V_24 , F_106 ( V_55 ) ) ;
V_91 = F_41 ( V_6 ) ;
if ( V_91 && V_91 != V_33 -> V_15 ) {
struct V_51 * V_51 ;
F_93 ( & V_91 -> V_68 ) ;
V_51 = F_71 ( V_91 , V_6 ) ;
if ( V_51 && V_51 -> V_90 -> V_24 == V_24 ) {
V_33 = V_51 -> V_90 ;
} else {
F_95 ( & V_91 -> V_68 ) ;
F_93 ( & V_33 -> V_15 -> V_68 ) ;
}
} else {
F_93 ( & V_33 -> V_15 -> V_68 ) ;
}
if ( F_57 ( ! V_33 -> V_69 ) ) {
if ( V_24 -> V_32 & V_70 ) {
F_95 ( & V_33 -> V_15 -> V_68 ) ;
F_97 () ;
goto V_95;
}
F_107 ( true , L_1 ,
V_24 -> V_98 , V_55 ) ;
}
F_108 ( V_93 , V_33 , V_6 ) ;
if ( F_10 ( ! F_50 ( & V_6 -> V_52 ) ) ) {
F_95 ( & V_33 -> V_15 -> V_68 ) ;
return;
}
V_33 -> V_77 [ V_33 -> V_99 ] ++ ;
V_92 = F_27 ( V_33 -> V_99 ) ;
if ( F_60 ( V_33 -> V_73 < V_33 -> V_78 ) ) {
F_83 ( V_6 ) ;
V_33 -> V_73 ++ ;
V_43 = & V_33 -> V_15 -> V_43 ;
} else {
V_92 |= V_87 ;
V_43 = & V_33 -> V_74 ;
}
F_98 ( V_33 , V_6 , V_43 , V_92 ) ;
F_95 ( & V_33 -> V_15 -> V_68 ) ;
}
bool F_109 ( int V_55 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
bool V_16 = false ;
unsigned long V_32 ;
F_89 ( V_32 ) ;
if ( ! F_92 ( V_85 , F_7 ( V_6 ) ) ) {
F_103 ( V_55 , V_24 , V_6 ) ;
V_16 = true ;
}
F_96 ( V_32 ) ;
return V_16 ;
}
void F_110 ( unsigned long V_100 )
{
struct V_12 * V_84 = (struct V_12 * ) V_100 ;
F_103 ( V_84 -> V_55 , V_84 -> V_24 , & V_84 -> V_6 ) ;
}
static void F_111 ( int V_55 , struct V_23 * V_24 ,
struct V_12 * V_84 , unsigned long V_101 )
{
struct V_102 * V_13 = & V_84 -> V_13 ;
struct V_2 * V_6 = & V_84 -> V_6 ;
F_9 ( V_13 -> V_103 != F_110 ||
V_13 -> V_31 != ( unsigned long ) V_84 ) ;
F_9 ( F_112 ( V_13 ) ) ;
F_9 ( ! F_50 ( & V_6 -> V_52 ) ) ;
if ( ! V_101 ) {
F_103 ( V_55 , V_24 , & V_84 -> V_6 ) ;
return;
}
F_113 ( & V_84 -> V_13 ) ;
V_84 -> V_24 = V_24 ;
V_84 -> V_55 = V_55 ;
V_13 -> V_104 = V_105 + V_101 ;
if ( F_57 ( V_55 != V_96 ) )
F_114 ( V_13 , V_55 ) ;
else
F_115 ( V_13 ) ;
}
bool F_116 ( int V_55 , struct V_23 * V_24 ,
struct V_12 * V_84 , unsigned long V_101 )
{
struct V_2 * V_6 = & V_84 -> V_6 ;
bool V_16 = false ;
unsigned long V_32 ;
F_89 ( V_32 ) ;
if ( ! F_92 ( V_85 , F_7 ( V_6 ) ) ) {
F_111 ( V_55 , V_24 , V_84 , V_101 ) ;
V_16 = true ;
}
F_96 ( V_32 ) ;
return V_16 ;
}
bool F_117 ( int V_55 , struct V_23 * V_24 ,
struct V_12 * V_84 , unsigned long V_101 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_88 ( & V_84 -> V_6 , true , & V_32 ) ;
} while ( F_57 ( V_16 == - V_89 ) );
if ( F_60 ( V_16 >= 0 ) ) {
F_111 ( V_55 , V_24 , V_84 , V_101 ) ;
F_96 ( V_32 ) ;
}
return V_16 ;
}
static void F_118 ( struct V_51 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_15 ;
if ( F_9 ( V_51 -> V_32 & V_106 ) ||
F_9 ( ! F_50 ( & V_51 -> V_52 ) &&
( V_51 -> V_107 . V_108 || V_51 -> V_107 . V_109 ) ) )
return;
V_51 -> V_32 |= V_106 ;
V_15 -> V_44 ++ ;
V_51 -> V_110 = V_105 ;
F_119 ( & V_51 -> V_52 , & V_15 -> V_49 ) ;
if ( F_54 ( V_15 ) && ! F_112 ( & V_15 -> V_111 ) )
F_120 ( & V_15 -> V_111 , V_105 + V_112 ) ;
F_9 ( ! ( V_15 -> V_32 & V_113 ) &&
V_15 -> V_48 == V_15 -> V_44 &&
F_48 ( & V_15 -> V_42 ) ) ;
}
static void F_121 ( struct V_51 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_15 ;
if ( F_9 ( ! ( V_51 -> V_32 & V_106 ) ) )
return;
F_70 ( V_51 , V_106 ) ;
V_15 -> V_44 -- ;
F_94 ( & V_51 -> V_52 ) ;
}
static struct V_51 * F_122 ( void )
{
struct V_51 * V_51 ;
V_51 = F_123 ( sizeof( * V_51 ) , V_20 ) ;
if ( V_51 ) {
F_124 ( & V_51 -> V_52 ) ;
F_124 ( & V_51 -> V_114 ) ;
F_124 ( & V_51 -> V_25 ) ;
V_51 -> V_32 = V_115 ;
}
return V_51 ;
}
static void F_125 ( struct V_51 * V_51 ,
struct V_14 * V_15 )
{
F_126 ( & V_15 -> V_116 ) ;
F_127 ( V_51 -> V_53 , V_15 -> V_117 -> V_118 ) ;
if ( V_15 -> V_32 & V_113 )
V_51 -> V_32 |= V_119 ;
F_99 ( & V_51 -> V_25 , & V_15 -> V_120 ) ;
F_128 ( & V_15 -> V_116 ) ;
}
static void F_129 ( struct V_51 * V_51 ,
struct V_14 * V_15 )
{
struct V_121 * V_122 = NULL ;
F_126 ( & V_15 -> V_116 ) ;
F_130 ( & V_51 -> V_25 ) ;
if ( F_50 ( & V_15 -> V_120 ) )
V_122 = V_15 -> V_122 ;
F_128 ( & V_15 -> V_116 ) ;
if ( V_122 )
F_87 ( V_122 ) ;
}
static struct V_51 * F_131 ( struct V_14 * V_15 )
{
struct V_51 * V_51 = NULL ;
int V_21 = - 1 ;
char V_123 [ 16 ] ;
V_21 = F_132 ( & V_15 -> V_124 , 0 , 0 , V_20 ) ;
if ( V_21 < 0 )
goto V_86;
V_51 = F_122 () ;
if ( ! V_51 )
goto V_86;
V_51 -> V_15 = V_15 ;
V_51 -> V_21 = V_21 ;
if ( V_15 -> V_55 >= 0 )
snprintf ( V_123 , sizeof( V_123 ) , L_2 , V_15 -> V_55 , V_21 ,
V_15 -> V_117 -> V_125 < 0 ? L_3 : L_4 ) ;
else
snprintf ( V_123 , sizeof( V_123 ) , L_5 , V_15 -> V_21 , V_21 ) ;
V_51 -> V_53 = F_133 ( V_126 , V_51 , V_15 -> V_25 ,
L_6 , V_123 ) ;
if ( F_134 ( V_51 -> V_53 ) )
goto V_86;
F_135 ( V_51 -> V_53 , V_15 -> V_117 -> V_125 ) ;
V_51 -> V_53 -> V_32 |= V_127 ;
F_125 ( V_51 , V_15 ) ;
return V_51 ;
V_86:
if ( V_21 >= 0 )
F_136 ( & V_15 -> V_124 , V_21 ) ;
F_137 ( V_51 ) ;
return NULL ;
}
static void F_138 ( struct V_51 * V_51 )
{
V_51 -> V_15 -> V_48 ++ ;
F_118 ( V_51 ) ;
F_61 ( V_51 -> V_53 ) ;
}
static int F_139 ( struct V_14 * V_15 )
{
struct V_51 * V_51 ;
V_51 = F_131 ( V_15 ) ;
if ( V_51 ) {
F_80 ( & V_15 -> V_68 ) ;
F_138 ( V_51 ) ;
F_81 ( & V_15 -> V_68 ) ;
}
return V_51 ? 0 : - V_128 ;
}
static void F_140 ( struct V_51 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_15 ;
F_22 ( & V_15 -> V_68 ) ;
if ( F_10 ( V_51 -> V_61 ) ||
F_10 ( ! F_50 ( & V_51 -> V_114 ) ) ||
F_10 ( ! ( V_51 -> V_32 & V_106 ) ) )
return;
V_15 -> V_48 -- ;
V_15 -> V_44 -- ;
F_94 ( & V_51 -> V_52 ) ;
V_51 -> V_32 |= V_129 ;
F_61 ( V_51 -> V_53 ) ;
}
static void F_141 ( unsigned long V_130 )
{
struct V_14 * V_15 = ( void * ) V_130 ;
F_80 ( & V_15 -> V_68 ) ;
while ( F_54 ( V_15 ) ) {
struct V_51 * V_51 ;
unsigned long V_104 ;
V_51 = F_142 ( V_15 -> V_49 . V_131 , struct V_51 , V_52 ) ;
V_104 = V_51 -> V_110 + V_112 ;
if ( F_143 ( V_105 , V_104 ) ) {
F_120 ( & V_15 -> V_111 , V_104 ) ;
break;
}
F_140 ( V_51 ) ;
}
F_81 ( & V_15 -> V_68 ) ;
}
static void F_144 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_39 ( V_6 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_22 ( & V_132 ) ;
if ( ! V_24 -> V_133 )
return;
if ( F_50 ( & V_33 -> V_134 ) ) {
F_76 ( V_33 ) ;
F_99 ( & V_33 -> V_134 , & V_24 -> V_135 ) ;
F_61 ( V_24 -> V_133 -> V_53 ) ;
}
}
static void F_145 ( unsigned long V_130 )
{
struct V_14 * V_15 = ( void * ) V_130 ;
struct V_2 * V_6 ;
F_80 ( & V_132 ) ;
F_93 ( & V_15 -> V_68 ) ;
if ( F_53 ( V_15 ) ) {
F_146 (work, &pool->worklist, entry)
F_144 ( V_6 ) ;
}
F_95 ( & V_15 -> V_68 ) ;
F_81 ( & V_132 ) ;
F_120 ( & V_15 -> V_136 , V_105 + V_137 ) ;
}
static bool F_147 ( struct V_14 * V_15 )
__releases( &pool->lock
static bool F_148 ( struct V_51 * V_51 )
{
struct V_14 * V_15 = V_51 -> V_15 ;
bool V_16 = false ;
if ( ! F_149 ( & V_15 -> V_46 ) )
return V_16 ;
V_16 |= F_147 ( V_15 ) ;
F_128 ( & V_15 -> V_46 ) ;
return V_16 ;
}
static void F_150 ( struct V_51 * V_51 , struct V_2 * V_6 )
__releases( &pool->lock
static void F_151 ( struct V_51 * V_51 )
{
while ( ! F_50 ( & V_51 -> V_114 ) ) {
struct V_2 * V_6 = F_58 ( & V_51 -> V_114 ,
struct V_2 , V_52 ) ;
F_150 ( V_51 , V_6 ) ;
}
}
static int V_126 ( void * V_138 )
{
struct V_51 * V_51 = V_138 ;
struct V_14 * V_15 = V_51 -> V_15 ;
V_51 -> V_53 -> V_32 |= V_139 ;
V_140:
F_80 ( & V_15 -> V_68 ) ;
if ( F_57 ( V_51 -> V_32 & V_129 ) ) {
F_81 ( & V_15 -> V_68 ) ;
F_9 ( ! F_50 ( & V_51 -> V_52 ) ) ;
V_51 -> V_53 -> V_32 &= ~ V_139 ;
F_152 ( V_51 -> V_53 , L_7 ) ;
F_136 ( & V_15 -> V_124 , V_51 -> V_21 ) ;
F_129 ( V_51 , V_15 ) ;
F_137 ( V_51 ) ;
return 0 ;
}
F_121 ( V_51 ) ;
V_141:
if ( ! F_49 ( V_15 ) )
goto V_142;
if ( F_57 ( ! F_51 ( V_15 ) ) && F_148 ( V_51 ) )
goto V_141;
F_9 ( ! F_50 ( & V_51 -> V_114 ) ) ;
F_70 ( V_51 , V_115 | V_143 ) ;
do {
struct V_2 * V_6 =
F_58 ( & V_15 -> V_43 ,
struct V_2 , V_52 ) ;
if ( F_60 ( ! ( * F_7 ( V_6 ) & V_67 ) ) ) {
F_150 ( V_51 , V_6 ) ;
if ( F_57 ( ! F_50 ( & V_51 -> V_114 ) ) )
F_151 ( V_51 ) ;
} else {
F_73 ( V_6 , & V_51 -> V_114 , NULL ) ;
F_151 ( V_51 ) ;
}
} while ( F_52 ( V_15 ) );
F_68 ( V_51 , V_115 , false ) ;
V_142:
F_118 ( V_51 ) ;
F_153 ( V_144 ) ;
F_81 ( & V_15 -> V_68 ) ;
F_154 () ;
goto V_140;
}
static int F_155 ( void * V_145 )
{
struct V_51 * V_133 = V_145 ;
struct V_23 * V_24 = V_133 -> V_146 ;
struct V_63 * V_114 = & V_133 -> V_114 ;
bool V_147 ;
F_135 ( V_59 , V_148 ) ;
V_133 -> V_53 -> V_32 |= V_139 ;
V_149:
F_156 ( V_144 ) ;
V_147 = F_157 () ;
F_80 ( & V_132 ) ;
while ( ! F_50 ( & V_24 -> V_135 ) ) {
struct V_22 * V_33 = F_58 ( & V_24 -> V_135 ,
struct V_22 , V_134 ) ;
struct V_14 * V_15 = V_33 -> V_15 ;
struct V_2 * V_6 , * V_66 ;
F_153 ( V_150 ) ;
F_94 ( & V_33 -> V_134 ) ;
F_81 ( & V_132 ) ;
F_125 ( V_133 , V_15 ) ;
F_80 ( & V_15 -> V_68 ) ;
V_133 -> V_15 = V_15 ;
F_9 ( ! F_50 ( & V_133 -> V_114 ) ) ;
F_158 (work, n, &pool->worklist, entry)
if ( F_39 ( V_6 ) == V_33 )
F_73 ( V_6 , V_114 , & V_66 ) ;
F_151 ( V_133 ) ;
F_81 ( & V_15 -> V_68 ) ;
F_129 ( V_133 , V_15 ) ;
F_80 ( & V_15 -> V_68 ) ;
F_77 ( V_33 ) ;
if ( F_52 ( V_15 ) )
F_59 ( V_15 ) ;
V_133 -> V_15 = NULL ;
F_95 ( & V_15 -> V_68 ) ;
F_93 ( & V_132 ) ;
}
F_81 ( & V_132 ) ;
if ( V_147 ) {
F_153 ( V_150 ) ;
V_133 -> V_53 -> V_32 &= ~ V_139 ;
return 0 ;
}
F_9 ( ! ( V_133 -> V_32 & V_56 ) ) ;
F_154 () ;
goto V_149;
}
static void F_159 ( struct V_2 * V_6 )
{
struct V_151 * V_152 = F_160 ( V_6 , struct V_151 , V_6 ) ;
F_87 ( & V_152 -> V_82 ) ;
}
static void F_161 ( struct V_22 * V_33 ,
struct V_151 * V_152 ,
struct V_2 * V_153 , struct V_51 * V_51 )
{
struct V_63 * V_64 ;
unsigned int V_154 = 0 ;
F_162 ( & V_152 -> V_6 , F_159 ) ;
F_163 ( V_85 , F_7 ( & V_152 -> V_6 ) ) ;
F_164 ( & V_152 -> V_82 ) ;
if ( V_51 )
V_64 = V_51 -> V_114 . V_108 ;
else {
unsigned long * V_155 = F_7 ( V_153 ) ;
V_64 = V_153 -> V_52 . V_108 ;
V_154 = * V_155 & V_67 ;
F_163 ( V_156 , V_155 ) ;
}
F_13 ( & V_152 -> V_6 ) ;
F_98 ( V_33 , & V_152 -> V_6 , V_64 ,
F_27 ( V_75 ) | V_154 ) ;
}
static bool F_165 ( struct V_23 * V_24 ,
int V_79 , int V_99 )
{
bool V_157 = false ;
struct V_22 * V_33 ;
if ( V_79 >= 0 ) {
F_9 ( F_48 ( & V_24 -> V_80 ) ) ;
F_166 ( & V_24 -> V_80 , 1 ) ;
}
F_167 (pwq, wq) {
struct V_14 * V_15 = V_33 -> V_15 ;
F_80 ( & V_15 -> V_68 ) ;
if ( V_79 >= 0 ) {
F_9 ( V_33 -> V_79 != - 1 ) ;
if ( V_33 -> V_77 [ V_79 ] ) {
V_33 -> V_79 = V_79 ;
F_64 ( & V_24 -> V_80 ) ;
V_157 = true ;
}
}
if ( V_99 >= 0 ) {
F_9 ( V_99 != F_29 ( V_33 -> V_99 ) ) ;
V_33 -> V_99 = V_99 ;
}
F_81 ( & V_15 -> V_68 ) ;
}
if ( V_79 >= 0 && F_67 ( & V_24 -> V_80 ) )
F_87 ( & V_24 -> V_81 -> V_82 ) ;
return V_157 ;
}
void F_168 ( struct V_23 * V_24 )
{
struct V_158 V_159 = {
. V_160 = F_169 ( V_159 . V_160 ) ,
. V_79 = - 1 ,
. V_82 = F_170 ( V_159 . V_82 ) ,
} ;
int V_161 ;
F_171 ( & V_24 -> V_162 ) ;
F_172 ( & V_24 -> V_162 ) ;
F_126 ( & V_24 -> V_163 ) ;
V_161 = F_29 ( V_24 -> V_99 ) ;
if ( V_161 != V_24 -> V_79 ) {
F_9 ( ! F_50 ( & V_24 -> V_164 ) ) ;
V_159 . V_79 = V_24 -> V_99 ;
V_24 -> V_99 = V_161 ;
if ( ! V_24 -> V_81 ) {
F_9 ( V_24 -> V_79 != V_159 . V_79 ) ;
V_24 -> V_81 = & V_159 ;
if ( ! F_165 ( V_24 , V_24 -> V_79 ,
V_24 -> V_99 ) ) {
V_24 -> V_79 = V_161 ;
V_24 -> V_81 = NULL ;
goto V_165;
}
} else {
F_9 ( V_24 -> V_79 == V_159 . V_79 ) ;
F_99 ( & V_159 . V_160 , & V_24 -> V_166 ) ;
F_165 ( V_24 , - 1 , V_24 -> V_99 ) ;
}
} else {
F_99 ( & V_159 . V_160 , & V_24 -> V_164 ) ;
}
F_128 ( & V_24 -> V_163 ) ;
F_173 ( & V_159 . V_82 ) ;
if ( V_24 -> V_81 != & V_159 )
return;
F_126 ( & V_24 -> V_163 ) ;
if ( V_24 -> V_81 != & V_159 )
goto V_165;
V_24 -> V_81 = NULL ;
F_9 ( ! F_50 ( & V_159 . V_160 ) ) ;
F_9 ( V_24 -> V_79 != V_159 . V_79 ) ;
while ( true ) {
struct V_158 * V_108 , * V_167 ;
F_158 (next, tmp, &wq->flusher_queue, list) {
if ( V_108 -> V_79 != V_24 -> V_79 )
break;
F_94 ( & V_108 -> V_160 ) ;
F_87 ( & V_108 -> V_82 ) ;
}
F_9 ( ! F_50 ( & V_24 -> V_164 ) &&
V_24 -> V_79 != F_29 ( V_24 -> V_99 ) ) ;
V_24 -> V_79 = F_29 ( V_24 -> V_79 ) ;
if ( ! F_50 ( & V_24 -> V_164 ) ) {
F_146 (tmp, &wq->flusher_overflow, list)
V_167 -> V_79 = V_24 -> V_99 ;
V_24 -> V_99 = F_29 ( V_24 -> V_99 ) ;
F_174 ( & V_24 -> V_164 ,
& V_24 -> V_166 ) ;
F_165 ( V_24 , - 1 , V_24 -> V_99 ) ;
}
if ( F_50 ( & V_24 -> V_166 ) ) {
F_9 ( V_24 -> V_79 != V_24 -> V_99 ) ;
break;
}
F_9 ( V_24 -> V_79 == V_24 -> V_99 ) ;
F_9 ( V_24 -> V_79 != V_108 -> V_79 ) ;
F_94 ( & V_108 -> V_160 ) ;
V_24 -> V_81 = V_108 ;
if ( F_165 ( V_24 , V_24 -> V_79 , - 1 ) )
break;
V_24 -> V_81 = NULL ;
}
V_165:
F_128 ( & V_24 -> V_163 ) ;
}
void F_175 ( struct V_23 * V_24 )
{
unsigned int V_168 = 0 ;
struct V_22 * V_33 ;
F_126 ( & V_24 -> V_163 ) ;
if ( ! V_24 -> V_169 ++ )
V_24 -> V_32 |= V_94 ;
F_128 ( & V_24 -> V_163 ) ;
V_170:
F_168 ( V_24 ) ;
F_126 ( & V_24 -> V_163 ) ;
F_167 (pwq, wq) {
bool V_171 ;
F_80 ( & V_33 -> V_15 -> V_68 ) ;
V_171 = ! V_33 -> V_73 && F_50 ( & V_33 -> V_74 ) ;
F_81 ( & V_33 -> V_15 -> V_68 ) ;
if ( V_171 )
continue;
if ( ++ V_168 == 10 ||
( V_168 % 100 == 0 && V_168 <= 1000 ) )
F_176 ( L_8 ,
V_24 -> V_98 , V_168 ) ;
F_128 ( & V_24 -> V_163 ) ;
goto V_170;
}
if ( ! -- V_24 -> V_169 )
V_24 -> V_32 &= ~ V_94 ;
F_128 ( & V_24 -> V_163 ) ;
}
static bool F_177 ( struct V_2 * V_6 , struct V_151 * V_152 )
{
struct V_51 * V_51 = NULL ;
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_178 () ;
F_179 () ;
V_15 = F_41 ( V_6 ) ;
if ( ! V_15 ) {
F_180 () ;
return false ;
}
F_93 ( & V_15 -> V_68 ) ;
V_33 = F_39 ( V_6 ) ;
if ( V_33 ) {
if ( F_57 ( V_33 -> V_15 != V_15 ) )
goto V_172;
} else {
V_51 = F_71 ( V_15 , V_6 ) ;
if ( ! V_51 )
goto V_172;
V_33 = V_51 -> V_90 ;
}
F_161 ( V_33 , V_152 , V_6 , V_51 ) ;
F_81 ( & V_15 -> V_68 ) ;
if ( V_33 -> V_24 -> V_173 == 1 || V_33 -> V_24 -> V_133 )
F_171 ( & V_33 -> V_24 -> V_162 ) ;
else
F_181 ( & V_33 -> V_24 -> V_162 ) ;
F_172 ( & V_33 -> V_24 -> V_162 ) ;
return true ;
V_172:
F_81 ( & V_15 -> V_68 ) ;
return false ;
}
bool F_182 ( struct V_2 * V_6 )
{
struct V_151 V_152 ;
F_171 ( & V_6 -> V_162 ) ;
F_172 ( & V_6 -> V_162 ) ;
if ( F_177 ( V_6 , & V_152 ) ) {
F_173 ( & V_152 . V_82 ) ;
F_18 ( & V_152 . V_6 ) ;
return true ;
} else {
return false ;
}
}
static bool F_183 ( struct V_2 * V_6 , bool V_83 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_88 ( V_6 , V_83 , & V_32 ) ;
if ( F_57 ( V_16 == - V_88 ) )
F_182 ( V_6 ) ;
} while ( F_57 ( V_16 < 0 ) );
F_45 ( V_6 ) ;
F_96 ( V_32 ) ;
F_182 ( V_6 ) ;
F_38 ( V_6 ) ;
return V_16 ;
}
bool F_3 ( struct V_2 * V_6 )
{
return F_183 ( V_6 , false ) ;
}
bool F_184 ( struct V_12 * V_84 )
{
F_179 () ;
if ( F_185 ( & V_84 -> V_13 ) )
F_103 ( V_84 -> V_55 , V_84 -> V_24 , & V_84 -> V_6 ) ;
F_180 () ;
return F_182 ( & V_84 -> V_6 ) ;
}
bool F_186 ( struct V_12 * V_84 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_88 ( & V_84 -> V_6 , true , & V_32 ) ;
} while ( F_57 ( V_16 == - V_89 ) );
if ( F_57 ( V_16 < 0 ) )
return false ;
F_36 ( & V_84 -> V_6 ,
F_44 ( & V_84 -> V_6 ) ) ;
F_96 ( V_32 ) ;
return V_16 ;
}
bool F_187 ( struct V_12 * V_84 )
{
return F_183 ( & V_84 -> V_6 , true ) ;
}
int F_188 ( T_1 V_3 )
{
int V_55 ;
struct V_2 T_2 * V_174 ;
V_174 = F_189 ( struct V_2 ) ;
if ( ! V_174 )
return - V_128 ;
F_190 () ;
F_191 (cpu) {
struct V_2 * V_6 = F_105 ( V_174 , V_55 ) ;
F_192 ( V_6 , V_3 ) ;
F_193 ( V_55 , V_6 ) ;
}
F_191 (cpu)
F_182 ( F_105 ( V_174 , V_55 ) ) ;
F_194 () ;
F_195 ( V_174 ) ;
return 0 ;
}
void F_196 ( void )
{
F_168 ( V_175 ) ;
}
int F_197 ( T_1 V_176 , struct V_177 * V_178 )
{
if ( ! F_198 () ) {
V_176 ( & V_178 -> V_6 ) ;
return 0 ;
}
F_192 ( & V_178 -> V_6 , V_176 ) ;
F_78 ( & V_178 -> V_6 ) ;
return 1 ;
}
static struct V_23 * F_199 ( struct V_179 * V_180 )
{
struct V_181 * V_182 = F_160 ( V_180 , struct V_181 , V_180 ) ;
return V_182 -> V_24 ;
}
static T_3 F_200 ( struct V_179 * V_180 , struct V_183 * V_184 ,
char * V_185 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
return F_201 ( V_185 , V_186 , L_9 , ( bool ) ! ( V_24 -> V_32 & V_70 ) ) ;
}
static T_3 F_202 ( struct V_179 * V_180 ,
struct V_183 * V_184 , char * V_185 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
return F_201 ( V_185 , V_186 , L_9 , V_24 -> V_173 ) ;
}
static T_3 F_203 ( struct V_179 * V_180 ,
struct V_183 * V_184 , const char * V_185 ,
T_4 V_187 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
int V_188 ;
if ( sscanf ( V_185 , L_10 , & V_188 ) != 1 || V_188 <= 0 )
return - V_189 ;
F_204 ( V_24 , V_188 ) ;
return V_187 ;
}
static T_3 F_205 ( struct V_179 * V_180 ,
struct V_183 * V_184 , char * V_185 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
const char * V_190 = L_4 ;
int V_25 , V_191 = 0 ;
F_206 () ;
F_207 (node) {
V_191 += F_201 ( V_185 + V_191 , V_186 - V_191 ,
L_11 , V_190 , V_25 ,
F_24 ( V_24 , V_25 ) -> V_15 -> V_21 ) ;
V_190 = L_12 ;
}
V_191 += F_201 ( V_185 + V_191 , V_186 - V_191 , L_13 ) ;
F_208 () ;
return V_191 ;
}
static T_3 F_209 ( struct V_179 * V_180 , struct V_183 * V_184 ,
char * V_185 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
int V_191 ;
F_126 ( & V_24 -> V_163 ) ;
V_191 = F_201 ( V_185 , V_186 , L_9 , V_24 -> V_192 -> V_125 ) ;
F_128 ( & V_24 -> V_163 ) ;
return V_191 ;
}
static struct V_193 * F_210 ( struct V_23 * V_24 )
{
struct V_193 * V_117 ;
V_117 = F_211 ( V_20 ) ;
if ( ! V_117 )
return NULL ;
F_126 ( & V_24 -> V_163 ) ;
F_212 ( V_117 , V_24 -> V_192 ) ;
F_128 ( & V_24 -> V_163 ) ;
return V_117 ;
}
static T_3 F_213 ( struct V_179 * V_180 , struct V_183 * V_184 ,
const char * V_185 , T_4 V_187 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
struct V_193 * V_117 ;
int V_16 ;
V_117 = F_210 ( V_24 ) ;
if ( ! V_117 )
return - V_128 ;
if ( sscanf ( V_185 , L_10 , & V_117 -> V_125 ) == 1 &&
V_117 -> V_125 >= V_194 && V_117 -> V_125 <= V_195 )
V_16 = F_214 ( V_24 , V_117 ) ;
else
V_16 = - V_189 ;
F_215 ( V_117 ) ;
return V_16 ? : V_187 ;
}
static T_3 F_216 ( struct V_179 * V_180 ,
struct V_183 * V_184 , char * V_185 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
int V_191 ;
F_126 ( & V_24 -> V_163 ) ;
V_191 = F_217 ( V_185 , V_186 , V_24 -> V_192 -> V_118 ) ;
F_128 ( & V_24 -> V_163 ) ;
V_191 += F_201 ( V_185 + V_191 , V_186 - V_191 , L_13 ) ;
return V_191 ;
}
static T_3 F_218 ( struct V_179 * V_180 ,
struct V_183 * V_184 ,
const char * V_185 , T_4 V_187 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
struct V_193 * V_117 ;
int V_16 ;
V_117 = F_210 ( V_24 ) ;
if ( ! V_117 )
return - V_128 ;
V_16 = F_219 ( V_185 , V_117 -> V_118 ) ;
if ( ! V_16 )
V_16 = F_214 ( V_24 , V_117 ) ;
F_215 ( V_117 ) ;
return V_16 ? : V_187 ;
}
static T_3 F_220 ( struct V_179 * V_180 , struct V_183 * V_184 ,
char * V_185 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
int V_191 ;
F_126 ( & V_24 -> V_163 ) ;
V_191 = F_201 ( V_185 , V_186 , L_9 ,
! V_24 -> V_192 -> V_196 ) ;
F_128 ( & V_24 -> V_163 ) ;
return V_191 ;
}
static T_3 F_221 ( struct V_179 * V_180 , struct V_183 * V_184 ,
const char * V_185 , T_4 V_187 )
{
struct V_23 * V_24 = F_199 ( V_180 ) ;
struct V_193 * V_117 ;
int V_197 , V_16 ;
V_117 = F_210 ( V_24 ) ;
if ( ! V_117 )
return - V_128 ;
V_16 = - V_189 ;
if ( sscanf ( V_185 , L_10 , & V_197 ) == 1 ) {
V_117 -> V_196 = ! V_197 ;
V_16 = F_214 ( V_24 , V_117 ) ;
}
F_215 ( V_117 ) ;
return V_16 ? : V_187 ;
}
static int T_5 F_222 ( void )
{
return F_223 ( & V_198 , NULL ) ;
}
static void F_224 ( struct V_179 * V_180 )
{
struct V_181 * V_182 = F_160 ( V_180 , struct V_181 , V_180 ) ;
F_137 ( V_182 ) ;
}
int F_225 ( struct V_23 * V_24 )
{
struct V_181 * V_182 ;
int V_16 ;
if ( F_10 ( V_24 -> V_32 & V_199 ) )
return - V_189 ;
V_24 -> V_182 = V_182 = F_123 ( sizeof( * V_182 ) , V_20 ) ;
if ( ! V_182 )
return - V_128 ;
V_182 -> V_24 = V_24 ;
V_182 -> V_180 . V_200 = & V_198 ;
V_182 -> V_180 . V_201 = V_24 -> V_98 ;
V_182 -> V_180 . V_202 = F_224 ;
F_226 ( & V_182 -> V_180 , true ) ;
V_16 = F_227 ( & V_182 -> V_180 ) ;
if ( V_16 ) {
F_137 ( V_182 ) ;
V_24 -> V_182 = NULL ;
return V_16 ;
}
if ( V_24 -> V_32 & V_70 ) {
struct V_183 * V_184 ;
for ( V_184 = V_203 ; V_184 -> V_184 . V_98 ; V_184 ++ ) {
V_16 = F_228 ( & V_182 -> V_180 , V_184 ) ;
if ( V_16 ) {
F_229 ( & V_182 -> V_180 ) ;
V_24 -> V_182 = NULL ;
return V_16 ;
}
}
}
F_226 ( & V_182 -> V_180 , false ) ;
F_230 ( & V_182 -> V_180 . V_204 , V_205 ) ;
return 0 ;
}
static void F_231 ( struct V_23 * V_24 )
{
struct V_181 * V_182 = V_24 -> V_182 ;
if ( ! V_24 -> V_182 )
return;
V_24 -> V_182 = NULL ;
F_229 ( & V_182 -> V_180 ) ;
}
static void F_231 ( struct V_23 * V_24 ) { }
void F_215 ( struct V_193 * V_117 )
{
if ( V_117 ) {
F_232 ( V_117 -> V_118 ) ;
F_137 ( V_117 ) ;
}
}
struct V_193 * F_211 ( T_6 V_206 )
{
struct V_193 * V_117 ;
V_117 = F_123 ( sizeof( * V_117 ) , V_206 ) ;
if ( ! V_117 )
goto V_86;
if ( ! F_233 ( & V_117 -> V_118 , V_206 ) )
goto V_86;
F_234 ( V_117 -> V_118 , V_207 ) ;
return V_117 ;
V_86:
F_215 ( V_117 ) ;
return NULL ;
}
static void F_212 ( struct V_193 * V_208 ,
const struct V_193 * V_209 )
{
V_208 -> V_125 = V_209 -> V_125 ;
F_234 ( V_208 -> V_118 , V_209 -> V_118 ) ;
V_208 -> V_196 = V_209 -> V_196 ;
}
static T_7 F_235 ( const struct V_193 * V_117 )
{
T_7 V_210 = 0 ;
V_210 = F_236 ( V_117 -> V_125 , V_210 ) ;
V_210 = F_237 ( F_238 ( V_117 -> V_118 ) ,
F_239 ( V_211 ) * sizeof( long ) , V_210 ) ;
return V_210 ;
}
static bool F_240 ( const struct V_193 * V_212 ,
const struct V_193 * V_213 )
{
if ( V_212 -> V_125 != V_213 -> V_125 )
return false ;
if ( ! F_241 ( V_212 -> V_118 , V_213 -> V_118 ) )
return false ;
return true ;
}
static int F_242 ( struct V_14 * V_15 )
{
F_243 ( & V_15 -> V_68 ) ;
V_15 -> V_21 = - 1 ;
V_15 -> V_55 = - 1 ;
V_15 -> V_25 = V_214 ;
V_15 -> V_32 |= V_113 ;
F_124 ( & V_15 -> V_43 ) ;
F_124 ( & V_15 -> V_49 ) ;
F_244 ( V_15 -> V_215 ) ;
F_245 ( & V_15 -> V_111 ) ;
V_15 -> V_111 . V_103 = F_141 ;
V_15 -> V_111 . V_31 = ( unsigned long ) V_15 ;
F_246 ( & V_15 -> V_136 , F_145 ,
( unsigned long ) V_15 ) ;
F_247 ( & V_15 -> V_46 ) ;
F_247 ( & V_15 -> V_116 ) ;
F_124 ( & V_15 -> V_120 ) ;
F_248 ( & V_15 -> V_124 ) ;
F_249 ( & V_15 -> V_216 ) ;
V_15 -> V_69 = 1 ;
V_15 -> V_117 = F_211 ( V_20 ) ;
if ( ! V_15 -> V_117 )
return - V_128 ;
return 0 ;
}
static void F_250 ( struct V_217 * V_218 )
{
struct V_14 * V_15 = F_160 ( V_218 , struct V_14 , V_218 ) ;
F_251 ( & V_15 -> V_124 ) ;
F_215 ( V_15 -> V_117 ) ;
F_137 ( V_15 ) ;
}
static void F_252 ( struct V_14 * V_15 )
{
F_253 ( V_122 ) ;
struct V_51 * V_51 ;
F_22 ( & V_17 ) ;
if ( -- V_15 -> V_69 )
return;
if ( F_10 ( ! ( V_15 -> V_32 & V_113 ) ) ||
F_10 ( ! F_50 ( & V_15 -> V_43 ) ) )
return;
if ( V_15 -> V_21 >= 0 )
F_254 ( & V_18 , V_15 -> V_21 ) ;
F_255 ( & V_15 -> V_216 ) ;
F_126 ( & V_15 -> V_46 ) ;
F_80 ( & V_15 -> V_68 ) ;
while ( ( V_51 = F_56 ( V_15 ) ) )
F_140 ( V_51 ) ;
F_10 ( V_15 -> V_48 || V_15 -> V_44 ) ;
F_81 ( & V_15 -> V_68 ) ;
F_126 ( & V_15 -> V_116 ) ;
if ( ! F_50 ( & V_15 -> V_120 ) )
V_15 -> V_122 = & V_122 ;
F_128 ( & V_15 -> V_116 ) ;
if ( V_15 -> V_122 )
F_173 ( V_15 -> V_122 ) ;
F_128 ( & V_15 -> V_46 ) ;
F_185 ( & V_15 -> V_111 ) ;
F_185 ( & V_15 -> V_136 ) ;
F_256 ( & V_15 -> V_218 , F_250 ) ;
}
static struct V_14 * F_257 ( const struct V_193 * V_117 )
{
T_7 V_210 = F_235 ( V_117 ) ;
struct V_14 * V_15 ;
int V_25 ;
F_22 ( & V_17 ) ;
F_72 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_240 ( V_15 -> V_117 , V_117 ) ) {
V_15 -> V_69 ++ ;
goto V_165;
}
}
V_15 = F_123 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 || F_242 ( V_15 ) < 0 )
goto V_86;
F_258 ( & V_15 -> V_68 , 1 ) ;
F_212 ( V_15 -> V_117 , V_117 ) ;
V_15 -> V_117 -> V_196 = false ;
if ( V_219 ) {
F_207 (node) {
if ( F_259 ( V_15 -> V_117 -> V_118 ,
V_220 [ V_25 ] ) ) {
V_15 -> V_25 = V_25 ;
break;
}
}
}
if ( F_21 ( V_15 ) < 0 )
goto V_86;
if ( F_139 ( V_15 ) < 0 )
goto V_86;
F_260 ( V_221 , & V_15 -> V_216 , V_210 ) ;
V_165:
return V_15 ;
V_86:
if ( V_15 )
F_252 ( V_15 ) ;
return NULL ;
}
static void F_261 ( struct V_217 * V_218 )
{
F_262 ( V_222 ,
F_160 ( V_218 , struct V_22 , V_218 ) ) ;
}
static void F_263 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_160 ( V_6 , struct V_22 ,
V_71 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
struct V_14 * V_15 = V_33 -> V_15 ;
bool V_223 ;
if ( F_9 ( ! ( V_24 -> V_32 & V_70 ) ) )
return;
F_126 ( & V_24 -> V_163 ) ;
F_264 ( & V_33 -> V_224 ) ;
V_223 = F_50 ( & V_24 -> V_225 ) ;
F_128 ( & V_24 -> V_163 ) ;
F_126 ( & V_17 ) ;
F_252 ( V_15 ) ;
F_128 ( & V_17 ) ;
F_256 ( & V_33 -> V_218 , F_261 ) ;
if ( V_223 ) {
F_215 ( V_24 -> V_192 ) ;
F_137 ( V_24 ) ;
}
}
static void F_265 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
bool V_226 = V_24 -> V_32 & V_227 ;
F_22 ( & V_24 -> V_163 ) ;
if ( ! V_226 && V_33 -> V_78 == V_24 -> V_173 )
return;
F_80 ( & V_33 -> V_15 -> V_68 ) ;
if ( ! V_226 || ! V_228 ) {
V_33 -> V_78 = V_24 -> V_173 ;
while ( ! F_50 ( & V_33 -> V_74 ) &&
V_33 -> V_73 < V_33 -> V_78 )
F_85 ( V_33 ) ;
F_59 ( V_33 -> V_15 ) ;
} else {
V_33 -> V_78 = 0 ;
}
F_81 ( & V_33 -> V_15 -> V_68 ) ;
}
static void F_266 ( struct V_22 * V_33 , struct V_23 * V_24 ,
struct V_14 * V_15 )
{
F_267 ( ( unsigned long ) V_33 & V_229 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_15 = V_15 ;
V_33 -> V_24 = V_24 ;
V_33 -> V_79 = - 1 ;
V_33 -> V_69 = 1 ;
F_124 ( & V_33 -> V_74 ) ;
F_124 ( & V_33 -> V_224 ) ;
F_124 ( & V_33 -> V_134 ) ;
F_192 ( & V_33 -> V_71 , F_263 ) ;
}
static void F_268 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
F_22 ( & V_24 -> V_163 ) ;
if ( ! F_50 ( & V_33 -> V_224 ) )
return;
V_33 -> V_99 = V_24 -> V_99 ;
F_265 ( V_33 ) ;
F_269 ( & V_33 -> V_224 , & V_24 -> V_225 ) ;
}
static struct V_22 * F_270 ( struct V_23 * V_24 ,
const struct V_193 * V_117 )
{
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_22 ( & V_17 ) ;
V_15 = F_257 ( V_117 ) ;
if ( ! V_15 )
return NULL ;
V_33 = F_271 ( V_222 , V_20 , V_15 -> V_25 ) ;
if ( ! V_33 ) {
F_252 ( V_15 ) ;
return NULL ;
}
F_266 ( V_33 , V_24 , V_15 ) ;
return V_33 ;
}
static void F_272 ( struct V_22 * V_33 )
{
F_22 ( & V_17 ) ;
if ( V_33 ) {
F_252 ( V_33 -> V_15 ) ;
F_262 ( V_222 , V_33 ) ;
}
}
static bool F_273 ( const struct V_193 * V_117 , int V_25 ,
int V_230 , T_8 * V_118 )
{
if ( ! V_219 || V_117 -> V_196 )
goto V_231;
F_274 ( V_118 , F_275 ( V_25 ) , V_117 -> V_118 ) ;
if ( V_230 >= 0 )
F_276 ( V_230 , V_118 ) ;
if ( F_277 ( V_118 ) )
goto V_231;
F_274 ( V_118 , V_117 -> V_118 , V_220 [ V_25 ] ) ;
return ! F_241 ( V_118 , V_117 -> V_118 ) ;
V_231:
F_234 ( V_118 , V_117 -> V_118 ) ;
return false ;
}
static struct V_22 * F_278 ( struct V_23 * V_24 ,
int V_25 ,
struct V_22 * V_33 )
{
struct V_22 * V_232 ;
F_22 ( & V_24 -> V_163 ) ;
F_268 ( V_33 ) ;
V_232 = F_279 ( V_24 -> V_26 [ V_25 ] ) ;
F_280 ( V_24 -> V_26 [ V_25 ] , V_33 ) ;
return V_232 ;
}
int F_214 ( struct V_23 * V_24 ,
const struct V_193 * V_117 )
{
struct V_193 * V_233 , * V_234 ;
struct V_22 * * V_235 , * V_236 ;
int V_25 , V_16 ;
if ( F_10 ( ! ( V_24 -> V_32 & V_70 ) ) )
return - V_189 ;
if ( F_10 ( ( V_24 -> V_32 & V_199 ) && ! F_50 ( & V_24 -> V_225 ) ) )
return - V_189 ;
V_235 = F_123 ( V_237 * sizeof( V_235 [ 0 ] ) , V_20 ) ;
V_233 = F_211 ( V_20 ) ;
V_234 = F_211 ( V_20 ) ;
if ( ! V_235 || ! V_233 || ! V_234 )
goto V_238;
F_212 ( V_233 , V_117 ) ;
F_274 ( V_233 -> V_118 , V_233 -> V_118 , V_207 ) ;
F_212 ( V_234 , V_233 ) ;
F_190 () ;
F_126 ( & V_17 ) ;
V_236 = F_270 ( V_24 , V_233 ) ;
if ( ! V_236 )
goto V_239;
F_207 (node) {
if ( F_273 ( V_117 , V_25 , - 1 , V_234 -> V_118 ) ) {
V_235 [ V_25 ] = F_270 ( V_24 , V_234 ) ;
if ( ! V_235 [ V_25 ] )
goto V_239;
} else {
V_236 -> V_69 ++ ;
V_235 [ V_25 ] = V_236 ;
}
}
F_128 ( & V_17 ) ;
F_126 ( & V_24 -> V_163 ) ;
F_212 ( V_24 -> V_192 , V_233 ) ;
F_207 (node)
V_235 [ V_25 ] = F_278 ( V_24 , V_25 , V_235 [ V_25 ] ) ;
F_268 ( V_236 ) ;
F_281 ( V_24 -> V_236 , V_236 ) ;
F_128 ( & V_24 -> V_163 ) ;
F_207 (node)
F_79 ( V_235 [ V_25 ] ) ;
F_79 ( V_236 ) ;
F_194 () ;
V_16 = 0 ;
V_240:
F_215 ( V_234 ) ;
F_215 ( V_233 ) ;
F_137 ( V_235 ) ;
return V_16 ;
V_239:
F_272 ( V_236 ) ;
F_207 (node)
if ( V_235 && V_235 [ V_25 ] != V_236 )
F_272 ( V_235 [ V_25 ] ) ;
F_128 ( & V_17 ) ;
F_194 () ;
V_238:
V_16 = - V_128 ;
goto V_240;
}
static void F_282 ( struct V_23 * V_24 , int V_55 ,
bool V_241 )
{
int V_25 = F_106 ( V_55 ) ;
int V_242 = V_241 ? - 1 : V_55 ;
struct V_22 * V_232 = NULL , * V_33 ;
struct V_193 * V_243 ;
T_8 * V_118 ;
F_22 ( & V_17 ) ;
if ( ! V_219 || ! ( V_24 -> V_32 & V_70 ) )
return;
V_243 = V_244 ;
V_118 = V_243 -> V_118 ;
F_126 ( & V_24 -> V_163 ) ;
if ( V_24 -> V_192 -> V_196 )
goto V_165;
F_212 ( V_243 , V_24 -> V_192 ) ;
V_33 = F_24 ( V_24 , V_25 ) ;
if ( F_273 ( V_24 -> V_192 , V_25 , V_242 , V_118 ) ) {
if ( F_241 ( V_118 , V_33 -> V_15 -> V_117 -> V_118 ) )
goto V_165;
} else {
goto V_245;
}
F_128 ( & V_24 -> V_163 ) ;
V_33 = F_270 ( V_24 , V_243 ) ;
if ( ! V_33 ) {
F_176 ( L_14 ,
V_24 -> V_98 ) ;
F_126 ( & V_24 -> V_163 ) ;
goto V_245;
}
F_126 ( & V_24 -> V_163 ) ;
V_232 = F_278 ( V_24 , V_25 , V_33 ) ;
goto V_165;
V_245:
F_80 ( & V_24 -> V_236 -> V_15 -> V_68 ) ;
F_76 ( V_24 -> V_236 ) ;
F_81 ( & V_24 -> V_236 -> V_15 -> V_68 ) ;
V_232 = F_278 ( V_24 , V_25 , V_24 -> V_236 ) ;
V_165:
F_128 ( & V_24 -> V_163 ) ;
F_79 ( V_232 ) ;
}
static int F_283 ( struct V_23 * V_24 )
{
bool V_246 = V_24 -> V_32 & V_247 ;
int V_55 , V_16 ;
if ( ! ( V_24 -> V_32 & V_70 ) ) {
V_24 -> V_97 = F_189 ( struct V_22 ) ;
if ( ! V_24 -> V_97 )
return - V_128 ;
F_284 (cpu) {
struct V_22 * V_33 =
F_105 ( V_24 -> V_97 , V_55 ) ;
struct V_14 * V_248 =
F_285 ( V_249 , V_55 ) ;
F_266 ( V_33 , V_24 , & V_248 [ V_246 ] ) ;
F_126 ( & V_24 -> V_163 ) ;
F_268 ( V_33 ) ;
F_128 ( & V_24 -> V_163 ) ;
}
return 0 ;
} else if ( V_24 -> V_32 & V_199 ) {
V_16 = F_214 ( V_24 , V_250 [ V_246 ] ) ;
F_286 ( ! V_16 && ( V_24 -> V_225 . V_108 != & V_24 -> V_236 -> V_224 ||
V_24 -> V_225 . V_131 != & V_24 -> V_236 -> V_224 ) ,
L_15 , V_24 -> V_98 ) ;
return V_16 ;
} else {
return F_214 ( V_24 , V_251 [ V_246 ] ) ;
}
}
static int F_287 ( int V_78 , unsigned int V_32 ,
const char * V_98 )
{
int V_252 = V_32 & V_70 ? V_253 : V_254 ;
if ( V_78 < 1 || V_78 > V_252 )
F_176 ( L_16 ,
V_78 , V_98 , 1 , V_252 ) ;
return F_288 ( V_78 , 1 , V_252 ) ;
}
struct V_23 * F_289 ( const char * V_255 ,
unsigned int V_32 ,
int V_78 ,
struct V_256 * V_257 ,
const char * V_258 , ... )
{
T_4 V_259 = 0 ;
T_9 args ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
if ( ( V_32 & V_260 ) && V_261 )
V_32 |= V_70 ;
if ( V_32 & V_70 )
V_259 = V_237 * sizeof( V_24 -> V_26 [ 0 ] ) ;
V_24 = F_123 ( sizeof( * V_24 ) + V_259 , V_20 ) ;
if ( ! V_24 )
return NULL ;
if ( V_32 & V_70 ) {
V_24 -> V_192 = F_211 ( V_20 ) ;
if ( ! V_24 -> V_192 )
goto V_262;
}
va_start ( args , V_258 ) ;
vsnprintf ( V_24 -> V_98 , sizeof( V_24 -> V_98 ) , V_255 , args ) ;
va_end ( args ) ;
V_78 = V_78 ? : V_263 ;
V_78 = F_287 ( V_78 , V_32 , V_24 -> V_98 ) ;
V_24 -> V_32 = V_32 ;
V_24 -> V_173 = V_78 ;
F_247 ( & V_24 -> V_163 ) ;
F_166 ( & V_24 -> V_80 , 0 ) ;
F_124 ( & V_24 -> V_225 ) ;
F_124 ( & V_24 -> V_166 ) ;
F_124 ( & V_24 -> V_164 ) ;
F_124 ( & V_24 -> V_135 ) ;
F_290 ( & V_24 -> V_162 , V_258 , V_257 , 0 ) ;
F_124 ( & V_24 -> V_160 ) ;
if ( F_283 ( V_24 ) < 0 )
goto V_262;
if ( V_32 & V_264 ) {
struct V_51 * V_133 ;
V_133 = F_122 () ;
if ( ! V_133 )
goto V_265;
V_133 -> V_146 = V_24 ;
V_133 -> V_53 = F_291 ( F_155 , V_133 , L_17 ,
V_24 -> V_98 ) ;
if ( F_134 ( V_133 -> V_53 ) ) {
F_137 ( V_133 ) ;
goto V_265;
}
V_24 -> V_133 = V_133 ;
V_133 -> V_53 -> V_32 |= V_127 ;
F_61 ( V_133 -> V_53 ) ;
}
if ( ( V_24 -> V_32 & V_266 ) && F_225 ( V_24 ) )
goto V_265;
F_126 ( & V_17 ) ;
F_126 ( & V_24 -> V_163 ) ;
F_167 (pwq, wq)
F_265 ( V_33 ) ;
F_128 ( & V_24 -> V_163 ) ;
F_119 ( & V_24 -> V_160 , & V_267 ) ;
F_128 ( & V_17 ) ;
return V_24 ;
V_262:
F_215 ( V_24 -> V_192 ) ;
F_137 ( V_24 ) ;
return NULL ;
V_265:
F_292 ( V_24 ) ;
return NULL ;
}
void F_292 ( struct V_23 * V_24 )
{
struct V_22 * V_33 ;
int V_25 ;
F_175 ( V_24 ) ;
F_126 ( & V_24 -> V_163 ) ;
F_167 (pwq, wq) {
int V_268 ;
for ( V_268 = 0 ; V_268 < V_30 ; V_268 ++ ) {
if ( F_10 ( V_33 -> V_77 [ V_268 ] ) ) {
F_128 ( & V_24 -> V_163 ) ;
return;
}
}
if ( F_10 ( ( V_33 != V_24 -> V_236 ) && ( V_33 -> V_69 > 1 ) ) ||
F_10 ( V_33 -> V_73 ) ||
F_10 ( ! F_50 ( & V_33 -> V_74 ) ) ) {
F_128 ( & V_24 -> V_163 ) ;
return;
}
}
F_128 ( & V_24 -> V_163 ) ;
F_126 ( & V_17 ) ;
F_94 ( & V_24 -> V_160 ) ;
F_128 ( & V_17 ) ;
F_231 ( V_24 ) ;
if ( V_24 -> V_133 ) {
F_293 ( V_24 -> V_133 -> V_53 ) ;
F_137 ( V_24 -> V_133 ) ;
V_24 -> V_133 = NULL ;
}
if ( ! ( V_24 -> V_32 & V_70 ) ) {
F_195 ( V_24 -> V_97 ) ;
F_137 ( V_24 ) ;
} else {
F_207 (node) {
V_33 = F_279 ( V_24 -> V_26 [ V_25 ] ) ;
F_294 ( V_24 -> V_26 [ V_25 ] , NULL ) ;
F_79 ( V_33 ) ;
}
V_33 = V_24 -> V_236 ;
V_24 -> V_236 = NULL ;
F_79 ( V_33 ) ;
}
}
void F_204 ( struct V_23 * V_24 , int V_78 )
{
struct V_22 * V_33 ;
if ( F_10 ( V_24 -> V_32 & V_199 ) )
return;
V_78 = F_287 ( V_78 , V_24 -> V_32 , V_24 -> V_98 ) ;
F_126 ( & V_24 -> V_163 ) ;
V_24 -> V_173 = V_78 ;
F_167 (pwq, wq)
F_265 ( V_33 ) ;
F_128 ( & V_24 -> V_163 ) ;
}
bool F_295 ( void )
{
struct V_51 * V_51 = F_102 () ;
return V_51 && V_51 -> V_146 ;
}
bool F_296 ( int V_55 , struct V_23 * V_24 )
{
struct V_22 * V_33 ;
bool V_16 ;
F_206 () ;
if ( V_55 == V_96 )
V_55 = F_297 () ;
if ( ! ( V_24 -> V_32 & V_70 ) )
V_33 = F_105 ( V_24 -> V_97 , V_55 ) ;
else
V_33 = F_24 ( V_24 , F_106 ( V_55 ) ) ;
V_16 = ! F_50 ( & V_33 -> V_74 ) ;
F_208 () ;
return V_16 ;
}
unsigned int F_298 ( struct V_2 * V_6 )
{
struct V_14 * V_15 ;
unsigned long V_32 ;
unsigned int V_16 = 0 ;
if ( F_31 ( V_6 ) )
V_16 |= V_269 ;
F_89 ( V_32 ) ;
V_15 = F_41 ( V_6 ) ;
if ( V_15 ) {
F_93 ( & V_15 -> V_68 ) ;
if ( F_71 ( V_15 , V_6 ) )
V_16 |= V_270 ;
F_95 ( & V_15 -> V_68 ) ;
}
F_96 ( V_32 ) ;
return V_16 ;
}
void F_299 ( const char * V_255 , ... )
{
struct V_51 * V_51 = F_102 () ;
T_9 args ;
if ( V_51 ) {
va_start ( args , V_255 ) ;
vsnprintf ( V_51 -> V_271 , sizeof( V_51 -> V_271 ) , V_255 , args ) ;
va_end ( args ) ;
V_51 -> V_272 = true ;
}
}
void F_300 ( const char * V_273 , struct V_54 * V_53 )
{
T_1 * V_176 = NULL ;
char V_98 [ V_274 ] = { } ;
char V_271 [ V_275 ] = { } ;
struct V_22 * V_33 = NULL ;
struct V_23 * V_24 = NULL ;
bool V_272 = false ;
struct V_51 * V_51 ;
if ( ! ( V_53 -> V_32 & V_139 ) )
return;
V_51 = F_301 ( V_53 ) ;
F_302 ( & V_176 , & V_51 -> V_62 , sizeof( V_176 ) ) ;
F_302 ( & V_33 , & V_51 -> V_90 , sizeof( V_33 ) ) ;
F_302 ( & V_24 , & V_33 -> V_24 , sizeof( V_24 ) ) ;
F_302 ( V_98 , V_24 -> V_98 , sizeof( V_98 ) - 1 ) ;
F_302 ( & V_272 , & V_51 -> V_272 , sizeof( V_272 ) ) ;
if ( V_272 )
F_302 ( V_271 , V_51 -> V_271 , sizeof( V_271 ) - 1 ) ;
if ( V_176 || V_98 [ 0 ] || V_271 [ 0 ] ) {
F_303 ( L_18 , V_273 , V_98 , V_176 ) ;
if ( V_271 [ 0 ] )
F_304 ( L_19 , V_271 ) ;
F_304 ( L_13 ) ;
}
}
static void F_305 ( struct V_2 * V_6 )
{
int V_55 = F_297 () ;
struct V_14 * V_15 ;
struct V_51 * V_51 ;
F_306 (pool, cpu) {
F_9 ( V_55 != F_297 () ) ;
F_126 ( & V_15 -> V_116 ) ;
F_80 ( & V_15 -> V_68 ) ;
F_307 (worker, pool)
V_51 -> V_32 |= V_119 ;
V_15 -> V_32 |= V_113 ;
F_81 ( & V_15 -> V_68 ) ;
F_128 ( & V_15 -> V_116 ) ;
F_154 () ;
F_166 ( & V_15 -> V_42 , 0 ) ;
F_80 ( & V_15 -> V_68 ) ;
F_59 ( V_15 ) ;
F_81 ( & V_15 -> V_68 ) ;
}
}
static void F_308 ( struct V_14 * V_15 )
{
struct V_51 * V_51 ;
F_22 ( & V_15 -> V_116 ) ;
F_307 (worker, pool)
F_9 ( F_127 ( V_51 -> V_53 ,
V_15 -> V_117 -> V_118 ) < 0 ) ;
F_80 ( & V_15 -> V_68 ) ;
F_307 (worker, pool) {
unsigned int V_276 = V_51 -> V_32 ;
if ( V_276 & V_106 )
F_61 ( V_51 -> V_53 ) ;
F_9 ( ! ( V_276 & V_119 ) ) ;
V_276 |= V_143 ;
V_276 &= ~ V_119 ;
F_309 ( V_51 -> V_32 ) = V_276 ;
}
F_81 ( & V_15 -> V_68 ) ;
}
static void F_310 ( struct V_14 * V_15 , int V_55 )
{
static T_8 V_118 ;
struct V_51 * V_51 ;
F_22 ( & V_15 -> V_116 ) ;
if ( ! F_311 ( V_55 , V_15 -> V_117 -> V_118 ) )
return;
F_274 ( & V_118 , V_15 -> V_117 -> V_118 , V_277 ) ;
if ( F_312 ( & V_118 ) != 1 )
return;
F_307 (worker, pool)
F_9 ( F_127 ( V_51 -> V_53 ,
V_15 -> V_117 -> V_118 ) < 0 ) ;
}
static int F_313 ( struct V_278 * V_279 ,
unsigned long V_280 ,
void * V_281 )
{
int V_55 = ( unsigned long ) V_281 ;
struct V_14 * V_15 ;
struct V_23 * V_24 ;
int V_282 ;
switch ( V_280 & ~ V_283 ) {
case V_284 :
F_306 (pool, cpu) {
if ( V_15 -> V_48 )
continue;
if ( F_139 ( V_15 ) < 0 )
return V_285 ;
}
break;
case V_286 :
case V_287 :
F_126 ( & V_17 ) ;
F_314 (pool, pi) {
F_126 ( & V_15 -> V_116 ) ;
if ( V_15 -> V_55 == V_55 ) {
F_80 ( & V_15 -> V_68 ) ;
V_15 -> V_32 &= ~ V_113 ;
F_81 ( & V_15 -> V_68 ) ;
F_308 ( V_15 ) ;
} else if ( V_15 -> V_55 < 0 ) {
F_310 ( V_15 , V_55 ) ;
}
F_128 ( & V_15 -> V_116 ) ;
}
F_146 (wq, &workqueues, list)
F_282 ( V_24 , V_55 , true ) ;
F_128 ( & V_17 ) ;
break;
}
return V_288 ;
}
static int F_315 ( struct V_278 * V_279 ,
unsigned long V_280 ,
void * V_281 )
{
int V_55 = ( unsigned long ) V_281 ;
struct V_2 V_289 ;
struct V_23 * V_24 ;
switch ( V_280 & ~ V_283 ) {
case V_290 :
F_162 ( & V_289 , F_305 ) ;
F_109 ( V_55 , V_291 , & V_289 ) ;
F_126 ( & V_17 ) ;
F_146 (wq, &workqueues, list)
F_282 ( V_24 , V_55 , false ) ;
F_128 ( & V_17 ) ;
F_182 ( & V_289 ) ;
F_18 ( & V_289 ) ;
break;
}
return V_288 ;
}
static void F_316 ( struct V_2 * V_6 )
{
struct V_292 * V_293 = F_160 ( V_6 , struct V_292 , V_6 ) ;
V_293 -> V_16 = V_293 -> V_176 ( V_293 -> V_294 ) ;
}
long F_317 ( int V_55 , long (* V_176)( void * ) , void * V_294 )
{
struct V_292 V_293 = { . V_176 = V_176 , . V_294 = V_294 } ;
F_162 ( & V_293 . V_6 , F_316 ) ;
F_193 ( V_55 , & V_293 . V_6 ) ;
F_182 ( & V_293 . V_6 ) ;
F_18 ( & V_293 . V_6 ) ;
return V_293 . V_16 ;
}
void F_318 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
F_9 ( V_228 ) ;
V_228 = true ;
F_146 (wq, &workqueues, list) {
F_126 ( & V_24 -> V_163 ) ;
F_167 (pwq, wq)
F_265 ( V_33 ) ;
F_128 ( & V_24 -> V_163 ) ;
}
F_128 ( & V_17 ) ;
}
bool F_319 ( void )
{
bool V_295 = false ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
F_9 ( ! V_228 ) ;
F_146 (wq, &workqueues, list) {
if ( ! ( V_24 -> V_32 & V_227 ) )
continue;
F_206 () ;
F_167 (pwq, wq) {
F_9 ( V_33 -> V_73 < 0 ) ;
if ( V_33 -> V_73 ) {
V_295 = true ;
F_208 () ;
goto V_165;
}
}
F_208 () ;
}
V_165:
F_128 ( & V_17 ) ;
return V_295 ;
}
void F_320 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
if ( ! V_228 )
goto V_165;
V_228 = false ;
F_146 (wq, &workqueues, list) {
F_126 ( & V_24 -> V_163 ) ;
F_167 (pwq, wq)
F_265 ( V_33 ) ;
F_128 ( & V_24 -> V_163 ) ;
}
V_165:
F_128 ( & V_17 ) ;
}
static void T_5 F_321 ( void )
{
T_10 * V_296 ;
int V_25 , V_55 ;
F_207 (node)
V_237 = F_322 ( V_237 , V_25 + 1 ) ;
if ( F_323 () <= 1 )
return;
if ( V_297 ) {
F_324 ( L_20 ) ;
return;
}
V_244 = F_211 ( V_20 ) ;
F_267 ( ! V_244 ) ;
V_296 = F_123 ( V_237 * sizeof( V_296 [ 0 ] ) , V_20 ) ;
F_267 ( ! V_296 ) ;
F_207 (node)
F_267 ( ! F_325 ( & V_296 [ V_25 ] , V_20 ,
F_326 ( V_25 ) ? V_25 : V_214 ) ) ;
F_284 (cpu) {
V_25 = F_106 ( V_55 ) ;
if ( F_10 ( V_25 == V_214 ) ) {
F_176 ( L_21 , V_55 ) ;
return;
}
F_327 ( V_55 , V_296 [ V_25 ] ) ;
}
V_220 = V_296 ;
V_219 = true ;
}
static int T_5 F_328 ( void )
{
int V_298 [ V_299 ] = { 0 , V_300 } ;
int V_268 , V_55 ;
F_10 ( F_329 ( struct V_22 ) < F_329 (long long) ) ;
V_222 = F_330 ( V_22 , V_301 ) ;
F_331 ( F_313 , V_302 ) ;
F_332 ( F_315 , V_303 ) ;
F_321 () ;
F_284 (cpu) {
struct V_14 * V_15 ;
V_268 = 0 ;
F_306 (pool, cpu) {
F_267 ( F_242 ( V_15 ) ) ;
V_15 -> V_55 = V_55 ;
F_234 ( V_15 -> V_117 -> V_118 , F_333 ( V_55 ) ) ;
V_15 -> V_117 -> V_125 = V_298 [ V_268 ++ ] ;
V_15 -> V_25 = F_106 ( V_55 ) ;
F_126 ( & V_17 ) ;
F_267 ( F_21 ( V_15 ) ) ;
F_128 ( & V_17 ) ;
}
}
F_191 (cpu) {
struct V_14 * V_15 ;
F_306 (pool, cpu) {
V_15 -> V_32 &= ~ V_113 ;
F_267 ( F_139 ( V_15 ) < 0 ) ;
}
}
for ( V_268 = 0 ; V_268 < V_299 ; V_268 ++ ) {
struct V_193 * V_117 ;
F_267 ( ! ( V_117 = F_211 ( V_20 ) ) ) ;
V_117 -> V_125 = V_298 [ V_268 ] ;
V_251 [ V_268 ] = V_117 ;
F_267 ( ! ( V_117 = F_211 ( V_20 ) ) ) ;
V_117 -> V_125 = V_298 [ V_268 ] ;
V_117 -> V_196 = true ;
V_250 [ V_268 ] = V_117 ;
}
V_175 = F_334 ( L_22 , 0 , 0 ) ;
V_291 = F_334 ( L_23 , V_247 , 0 ) ;
V_304 = F_334 ( L_24 , 0 , 0 ) ;
V_305 = F_334 ( L_25 , V_70 ,
V_253 ) ;
V_306 = F_334 ( L_26 ,
V_227 , 0 ) ;
V_307 = F_334 ( L_27 ,
V_260 , 0 ) ;
V_308 = F_334 ( L_28 ,
V_227 | V_260 ,
0 ) ;
F_267 ( ! V_175 || ! V_291 || ! V_304 ||
! V_305 || ! V_306 ||
! V_307 ||
! V_308 ) ;
return 0 ;
}
