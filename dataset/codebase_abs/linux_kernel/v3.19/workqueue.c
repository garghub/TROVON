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
return V_44 > 2 && ( V_44 - 2 ) * V_49 >= V_47 ;
}
static struct V_50 * F_56 ( struct V_14 * V_15 )
{
if ( F_57 ( F_50 ( & V_15 -> V_51 ) ) )
return NULL ;
return F_58 ( & V_15 -> V_51 , struct V_50 , V_52 ) ;
}
static void F_59 ( struct V_14 * V_15 )
{
struct V_50 * V_50 = F_56 ( V_15 ) ;
if ( F_60 ( V_50 ) )
F_61 ( V_50 -> V_53 ) ;
}
void F_62 ( struct V_54 * V_53 , int V_55 )
{
struct V_50 * V_50 = F_63 ( V_53 ) ;
if ( ! ( V_50 -> V_32 & V_56 ) ) {
F_9 ( V_50 -> V_15 -> V_55 != V_55 ) ;
F_64 ( & V_50 -> V_15 -> V_42 ) ;
}
}
struct V_54 * F_65 ( struct V_54 * V_53 , int V_55 )
{
struct V_50 * V_50 = F_63 ( V_53 ) , * V_57 = NULL ;
struct V_14 * V_15 ;
if ( V_50 -> V_32 & V_56 )
return NULL ;
V_15 = V_50 -> V_15 ;
if ( F_9 ( V_55 != F_66 () || V_15 -> V_55 != V_55 ) )
return NULL ;
if ( F_67 ( & V_15 -> V_42 ) &&
! F_50 ( & V_15 -> V_43 ) )
V_57 = F_56 ( V_15 ) ;
return V_57 ? V_57 -> V_53 : NULL ;
}
static inline void F_68 ( struct V_50 * V_50 , unsigned int V_32 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
F_9 ( V_50 -> V_53 != V_58 ) ;
if ( ( V_32 & V_56 ) &&
! ( V_50 -> V_32 & V_56 ) ) {
F_69 ( & V_15 -> V_42 ) ;
}
V_50 -> V_32 |= V_32 ;
}
static inline void F_70 ( struct V_50 * V_50 , unsigned int V_32 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
unsigned int V_59 = V_50 -> V_32 ;
F_9 ( V_50 -> V_53 != V_58 ) ;
V_50 -> V_32 &= ~ V_32 ;
if ( ( V_32 & V_56 ) && ( V_59 & V_56 ) )
if ( ! ( V_50 -> V_32 & V_56 ) )
F_64 ( & V_15 -> V_42 ) ;
}
static struct V_50 * F_71 ( struct V_14 * V_15 ,
struct V_2 * V_6 )
{
struct V_50 * V_50 ;
F_72 (pool->busy_hash, worker, hentry,
(unsigned long)work)
if ( V_50 -> V_60 == V_6 &&
V_50 -> V_61 == V_6 -> V_3 )
return V_50 ;
return NULL ;
}
static void F_73 ( struct V_2 * V_6 , struct V_62 * V_63 ,
struct V_2 * * V_64 )
{
struct V_2 * V_65 ;
F_74 (work, n, NULL, entry) {
F_75 ( & V_6 -> V_52 , V_63 ) ;
if ( ! ( * F_7 ( V_6 ) & V_66 ) )
break;
}
if ( V_64 )
* V_64 = V_65 ;
}
static void F_76 ( struct V_22 * V_33 )
{
F_22 ( & V_33 -> V_15 -> V_67 ) ;
F_9 ( V_33 -> V_68 <= 0 ) ;
V_33 -> V_68 ++ ;
}
static void F_77 ( struct V_22 * V_33 )
{
F_22 ( & V_33 -> V_15 -> V_67 ) ;
if ( F_60 ( -- V_33 -> V_68 ) )
return;
if ( F_9 ( ! ( V_33 -> V_24 -> V_32 & V_69 ) ) )
return;
F_78 ( & V_33 -> V_70 ) ;
}
static void F_79 ( struct V_22 * V_33 )
{
if ( V_33 ) {
F_80 ( & V_33 -> V_15 -> V_67 ) ;
F_77 ( V_33 ) ;
F_81 ( & V_33 -> V_15 -> V_67 ) ;
}
}
static void F_82 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_39 ( V_6 ) ;
F_83 ( V_6 ) ;
F_73 ( V_6 , & V_33 -> V_15 -> V_43 , NULL ) ;
F_84 ( V_71 , F_7 ( V_6 ) ) ;
V_33 -> V_72 ++ ;
}
static void F_85 ( struct V_22 * V_33 )
{
struct V_2 * V_6 = F_58 ( & V_33 -> V_73 ,
struct V_2 , V_52 ) ;
F_82 ( V_6 ) ;
}
static void F_86 ( struct V_22 * V_33 , int V_27 )
{
if ( V_27 == V_74 )
goto V_75;
V_33 -> V_76 [ V_27 ] -- ;
V_33 -> V_72 -- ;
if ( ! F_50 ( & V_33 -> V_73 ) ) {
if ( V_33 -> V_72 < V_33 -> V_77 )
F_85 ( V_33 ) ;
}
if ( F_60 ( V_33 -> V_78 != V_27 ) )
goto V_75;
if ( V_33 -> V_76 [ V_27 ] )
goto V_75;
V_33 -> V_78 = - 1 ;
if ( F_67 ( & V_33 -> V_24 -> V_79 ) )
F_87 ( & V_33 -> V_24 -> V_80 -> V_81 ) ;
V_75:
F_77 ( V_33 ) ;
}
static int F_88 ( struct V_2 * V_6 , bool V_82 ,
unsigned long * V_32 )
{
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_89 ( * V_32 ) ;
if ( V_82 ) {
struct V_12 * V_83 = F_90 ( V_6 ) ;
if ( F_60 ( F_91 ( & V_83 -> V_13 ) ) )
return 1 ;
}
if ( ! F_92 ( V_84 , F_7 ( V_6 ) ) )
return 0 ;
V_15 = F_41 ( V_6 ) ;
if ( ! V_15 )
goto V_85;
F_93 ( & V_15 -> V_67 ) ;
V_33 = F_39 ( V_6 ) ;
if ( V_33 && V_33 -> V_15 == V_15 ) {
F_14 ( V_6 ) ;
if ( * F_7 ( V_6 ) & V_86 )
F_82 ( V_6 ) ;
F_94 ( & V_6 -> V_52 ) ;
F_86 ( V_33 , F_28 ( V_6 ) ) ;
F_35 ( V_6 , V_15 -> V_21 ) ;
F_95 ( & V_15 -> V_67 ) ;
return 1 ;
}
F_95 ( & V_15 -> V_67 ) ;
V_85:
F_96 ( * V_32 ) ;
if ( F_46 ( V_6 ) )
return - V_87 ;
F_97 () ;
return - V_88 ;
}
static void F_98 ( struct V_22 * V_33 , struct V_2 * V_6 ,
struct V_62 * V_63 , unsigned int V_34 )
{
struct V_14 * V_15 = V_33 -> V_15 ;
F_34 ( V_6 , V_33 , V_34 ) ;
F_99 ( & V_6 -> V_52 , V_63 ) ;
F_76 ( V_33 ) ;
F_100 () ;
if ( F_47 ( V_15 ) )
F_59 ( V_15 ) ;
}
static bool F_101 ( struct V_23 * V_24 )
{
struct V_50 * V_50 ;
V_50 = F_102 () ;
return V_50 && V_50 -> V_89 -> V_24 == V_24 ;
}
static void F_103 ( int V_55 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
struct V_22 * V_33 ;
struct V_14 * V_90 ;
struct V_62 * V_43 ;
unsigned int V_91 ;
unsigned int V_92 = V_55 ;
F_9 ( ! F_104 () ) ;
F_13 ( V_6 ) ;
if ( F_57 ( V_24 -> V_32 & V_93 ) &&
F_9 ( ! F_101 ( V_24 ) ) )
return;
V_94:
if ( V_92 == V_95 )
V_55 = F_66 () ;
if ( ! ( V_24 -> V_32 & V_69 ) )
V_33 = F_105 ( V_24 -> V_96 , V_55 ) ;
else
V_33 = F_24 ( V_24 , F_106 ( V_55 ) ) ;
V_90 = F_41 ( V_6 ) ;
if ( V_90 && V_90 != V_33 -> V_15 ) {
struct V_50 * V_50 ;
F_93 ( & V_90 -> V_67 ) ;
V_50 = F_71 ( V_90 , V_6 ) ;
if ( V_50 && V_50 -> V_89 -> V_24 == V_24 ) {
V_33 = V_50 -> V_89 ;
} else {
F_95 ( & V_90 -> V_67 ) ;
F_93 ( & V_33 -> V_15 -> V_67 ) ;
}
} else {
F_93 ( & V_33 -> V_15 -> V_67 ) ;
}
if ( F_57 ( ! V_33 -> V_68 ) ) {
if ( V_24 -> V_32 & V_69 ) {
F_95 ( & V_33 -> V_15 -> V_67 ) ;
F_97 () ;
goto V_94;
}
F_107 ( true , L_1 ,
V_24 -> V_97 , V_55 ) ;
}
F_108 ( V_92 , V_33 , V_6 ) ;
if ( F_10 ( ! F_50 ( & V_6 -> V_52 ) ) ) {
F_95 ( & V_33 -> V_15 -> V_67 ) ;
return;
}
V_33 -> V_76 [ V_33 -> V_98 ] ++ ;
V_91 = F_27 ( V_33 -> V_98 ) ;
if ( F_60 ( V_33 -> V_72 < V_33 -> V_77 ) ) {
F_83 ( V_6 ) ;
V_33 -> V_72 ++ ;
V_43 = & V_33 -> V_15 -> V_43 ;
} else {
V_91 |= V_86 ;
V_43 = & V_33 -> V_73 ;
}
F_98 ( V_33 , V_6 , V_43 , V_91 ) ;
F_95 ( & V_33 -> V_15 -> V_67 ) ;
}
bool F_109 ( int V_55 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
bool V_16 = false ;
unsigned long V_32 ;
F_89 ( V_32 ) ;
if ( ! F_92 ( V_84 , F_7 ( V_6 ) ) ) {
F_103 ( V_55 , V_24 , V_6 ) ;
V_16 = true ;
}
F_96 ( V_32 ) ;
return V_16 ;
}
void F_110 ( unsigned long V_99 )
{
struct V_12 * V_83 = (struct V_12 * ) V_99 ;
F_103 ( V_83 -> V_55 , V_83 -> V_24 , & V_83 -> V_6 ) ;
}
static void F_111 ( int V_55 , struct V_23 * V_24 ,
struct V_12 * V_83 , unsigned long V_100 )
{
struct V_101 * V_13 = & V_83 -> V_13 ;
struct V_2 * V_6 = & V_83 -> V_6 ;
F_9 ( V_13 -> V_102 != F_110 ||
V_13 -> V_31 != ( unsigned long ) V_83 ) ;
F_9 ( F_112 ( V_13 ) ) ;
F_9 ( ! F_50 ( & V_6 -> V_52 ) ) ;
if ( ! V_100 ) {
F_103 ( V_55 , V_24 , & V_83 -> V_6 ) ;
return;
}
F_113 ( & V_83 -> V_13 ) ;
V_83 -> V_24 = V_24 ;
V_83 -> V_55 = V_55 ;
V_13 -> V_103 = V_104 + V_100 ;
if ( F_57 ( V_55 != V_95 ) )
F_114 ( V_13 , V_55 ) ;
else
F_115 ( V_13 ) ;
}
bool F_116 ( int V_55 , struct V_23 * V_24 ,
struct V_12 * V_83 , unsigned long V_100 )
{
struct V_2 * V_6 = & V_83 -> V_6 ;
bool V_16 = false ;
unsigned long V_32 ;
F_89 ( V_32 ) ;
if ( ! F_92 ( V_84 , F_7 ( V_6 ) ) ) {
F_111 ( V_55 , V_24 , V_83 , V_100 ) ;
V_16 = true ;
}
F_96 ( V_32 ) ;
return V_16 ;
}
bool F_117 ( int V_55 , struct V_23 * V_24 ,
struct V_12 * V_83 , unsigned long V_100 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_88 ( & V_83 -> V_6 , true , & V_32 ) ;
} while ( F_57 ( V_16 == - V_88 ) );
if ( F_60 ( V_16 >= 0 ) ) {
F_111 ( V_55 , V_24 , V_83 , V_100 ) ;
F_96 ( V_32 ) ;
}
return V_16 ;
}
static void F_118 ( struct V_50 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
if ( F_9 ( V_50 -> V_32 & V_105 ) ||
F_9 ( ! F_50 ( & V_50 -> V_52 ) &&
( V_50 -> V_106 . V_107 || V_50 -> V_106 . V_108 ) ) )
return;
V_50 -> V_32 |= V_105 ;
V_15 -> V_44 ++ ;
V_50 -> V_109 = V_104 ;
F_119 ( & V_50 -> V_52 , & V_15 -> V_51 ) ;
if ( F_54 ( V_15 ) && ! F_112 ( & V_15 -> V_110 ) )
F_120 ( & V_15 -> V_110 , V_104 + V_111 ) ;
F_9 ( ! ( V_15 -> V_32 & V_112 ) &&
V_15 -> V_48 == V_15 -> V_44 &&
F_48 ( & V_15 -> V_42 ) ) ;
}
static void F_121 ( struct V_50 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
if ( F_9 ( ! ( V_50 -> V_32 & V_105 ) ) )
return;
F_70 ( V_50 , V_105 ) ;
V_15 -> V_44 -- ;
F_94 ( & V_50 -> V_52 ) ;
}
static struct V_50 * F_122 ( int V_25 )
{
struct V_50 * V_50 ;
V_50 = F_123 ( sizeof( * V_50 ) , V_20 , V_25 ) ;
if ( V_50 ) {
F_124 ( & V_50 -> V_52 ) ;
F_124 ( & V_50 -> V_113 ) ;
F_124 ( & V_50 -> V_25 ) ;
V_50 -> V_32 = V_114 ;
}
return V_50 ;
}
static void F_125 ( struct V_50 * V_50 ,
struct V_14 * V_15 )
{
F_126 ( & V_15 -> V_115 ) ;
F_127 ( V_50 -> V_53 , V_15 -> V_116 -> V_117 ) ;
if ( V_15 -> V_32 & V_112 )
V_50 -> V_32 |= V_118 ;
F_99 ( & V_50 -> V_25 , & V_15 -> V_119 ) ;
F_128 ( & V_15 -> V_115 ) ;
}
static void F_129 ( struct V_50 * V_50 ,
struct V_14 * V_15 )
{
struct V_120 * V_121 = NULL ;
F_126 ( & V_15 -> V_115 ) ;
F_130 ( & V_50 -> V_25 ) ;
if ( F_50 ( & V_15 -> V_119 ) )
V_121 = V_15 -> V_121 ;
F_128 ( & V_15 -> V_115 ) ;
V_50 -> V_32 &= ~ ( V_118 | V_122 ) ;
if ( V_121 )
F_87 ( V_121 ) ;
}
static struct V_50 * F_131 ( struct V_14 * V_15 )
{
struct V_50 * V_50 = NULL ;
int V_21 = - 1 ;
char V_123 [ 16 ] ;
V_21 = F_132 ( & V_15 -> V_124 , 0 , 0 , V_20 ) ;
if ( V_21 < 0 )
goto V_85;
V_50 = F_122 ( V_15 -> V_25 ) ;
if ( ! V_50 )
goto V_85;
V_50 -> V_15 = V_15 ;
V_50 -> V_21 = V_21 ;
if ( V_15 -> V_55 >= 0 )
snprintf ( V_123 , sizeof( V_123 ) , L_2 , V_15 -> V_55 , V_21 ,
V_15 -> V_116 -> V_125 < 0 ? L_3 : L_4 ) ;
else
snprintf ( V_123 , sizeof( V_123 ) , L_5 , V_15 -> V_21 , V_21 ) ;
V_50 -> V_53 = F_133 ( V_126 , V_50 , V_15 -> V_25 ,
L_6 , V_123 ) ;
if ( F_134 ( V_50 -> V_53 ) )
goto V_85;
F_135 ( V_50 -> V_53 , V_15 -> V_116 -> V_125 ) ;
V_50 -> V_53 -> V_32 |= V_127 ;
F_125 ( V_50 , V_15 ) ;
F_80 ( & V_15 -> V_67 ) ;
V_50 -> V_15 -> V_48 ++ ;
F_118 ( V_50 ) ;
F_61 ( V_50 -> V_53 ) ;
F_81 ( & V_15 -> V_67 ) ;
return V_50 ;
V_85:
if ( V_21 >= 0 )
F_136 ( & V_15 -> V_124 , V_21 ) ;
F_137 ( V_50 ) ;
return NULL ;
}
static void F_138 ( struct V_50 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
F_22 ( & V_15 -> V_67 ) ;
if ( F_10 ( V_50 -> V_60 ) ||
F_10 ( ! F_50 ( & V_50 -> V_113 ) ) ||
F_10 ( ! ( V_50 -> V_32 & V_105 ) ) )
return;
V_15 -> V_48 -- ;
V_15 -> V_44 -- ;
F_94 ( & V_50 -> V_52 ) ;
V_50 -> V_32 |= V_128 ;
F_61 ( V_50 -> V_53 ) ;
}
static void F_139 ( unsigned long V_129 )
{
struct V_14 * V_15 = ( void * ) V_129 ;
F_80 ( & V_15 -> V_67 ) ;
while ( F_54 ( V_15 ) ) {
struct V_50 * V_50 ;
unsigned long V_103 ;
V_50 = F_140 ( V_15 -> V_51 . V_130 , struct V_50 , V_52 ) ;
V_103 = V_50 -> V_109 + V_111 ;
if ( F_141 ( V_104 , V_103 ) ) {
F_120 ( & V_15 -> V_110 , V_103 ) ;
break;
}
F_138 ( V_50 ) ;
}
F_81 ( & V_15 -> V_67 ) ;
}
static void F_142 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_39 ( V_6 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
F_22 ( & V_131 ) ;
if ( ! V_24 -> V_132 )
return;
if ( F_50 ( & V_33 -> V_133 ) ) {
F_76 ( V_33 ) ;
F_99 ( & V_33 -> V_133 , & V_24 -> V_134 ) ;
F_61 ( V_24 -> V_132 -> V_53 ) ;
}
}
static void F_143 ( unsigned long V_129 )
{
struct V_14 * V_15 = ( void * ) V_129 ;
struct V_2 * V_6 ;
F_80 ( & V_15 -> V_67 ) ;
F_93 ( & V_131 ) ;
if ( F_53 ( V_15 ) ) {
F_144 (work, &pool->worklist, entry)
F_142 ( V_6 ) ;
}
F_95 ( & V_131 ) ;
F_81 ( & V_15 -> V_67 ) ;
F_120 ( & V_15 -> V_135 , V_104 + V_136 ) ;
}
static void F_145 ( struct V_14 * V_15 )
__releases( &pool->lock
static bool F_146 ( struct V_50 * V_50 )
{
struct V_14 * V_15 = V_50 -> V_15 ;
if ( ! F_147 ( & V_15 -> V_46 ) )
return false ;
F_145 ( V_15 ) ;
F_128 ( & V_15 -> V_46 ) ;
return true ;
}
static void F_148 ( struct V_50 * V_50 , struct V_2 * V_6 )
__releases( &pool->lock
static void F_149 ( struct V_50 * V_50 )
{
while ( ! F_50 ( & V_50 -> V_113 ) ) {
struct V_2 * V_6 = F_58 ( & V_50 -> V_113 ,
struct V_2 , V_52 ) ;
F_148 ( V_50 , V_6 ) ;
}
}
static int V_126 ( void * V_137 )
{
struct V_50 * V_50 = V_137 ;
struct V_14 * V_15 = V_50 -> V_15 ;
V_50 -> V_53 -> V_32 |= V_138 ;
V_139:
F_80 ( & V_15 -> V_67 ) ;
if ( F_57 ( V_50 -> V_32 & V_128 ) ) {
F_81 ( & V_15 -> V_67 ) ;
F_9 ( ! F_50 ( & V_50 -> V_52 ) ) ;
V_50 -> V_53 -> V_32 &= ~ V_138 ;
F_150 ( V_50 -> V_53 , L_7 ) ;
F_136 ( & V_15 -> V_124 , V_50 -> V_21 ) ;
F_129 ( V_50 , V_15 ) ;
F_137 ( V_50 ) ;
return 0 ;
}
F_121 ( V_50 ) ;
V_140:
if ( ! F_49 ( V_15 ) )
goto V_141;
if ( F_57 ( ! F_51 ( V_15 ) ) && F_146 ( V_50 ) )
goto V_140;
F_9 ( ! F_50 ( & V_50 -> V_113 ) ) ;
F_70 ( V_50 , V_114 | V_122 ) ;
do {
struct V_2 * V_6 =
F_58 ( & V_15 -> V_43 ,
struct V_2 , V_52 ) ;
if ( F_60 ( ! ( * F_7 ( V_6 ) & V_66 ) ) ) {
F_148 ( V_50 , V_6 ) ;
if ( F_57 ( ! F_50 ( & V_50 -> V_113 ) ) )
F_149 ( V_50 ) ;
} else {
F_73 ( V_6 , & V_50 -> V_113 , NULL ) ;
F_149 ( V_50 ) ;
}
} while ( F_52 ( V_15 ) );
F_68 ( V_50 , V_114 ) ;
V_141:
F_118 ( V_50 ) ;
F_151 ( V_142 ) ;
F_81 ( & V_15 -> V_67 ) ;
F_152 () ;
goto V_139;
}
static int F_153 ( void * V_143 )
{
struct V_50 * V_132 = V_143 ;
struct V_23 * V_24 = V_132 -> V_144 ;
struct V_62 * V_113 = & V_132 -> V_113 ;
bool V_145 ;
F_135 ( V_58 , V_146 ) ;
V_132 -> V_53 -> V_32 |= V_138 ;
V_147:
F_154 ( V_142 ) ;
V_145 = F_155 () ;
F_80 ( & V_131 ) ;
while ( ! F_50 ( & V_24 -> V_134 ) ) {
struct V_22 * V_33 = F_58 ( & V_24 -> V_134 ,
struct V_22 , V_133 ) ;
struct V_14 * V_15 = V_33 -> V_15 ;
struct V_2 * V_6 , * V_65 ;
F_151 ( V_148 ) ;
F_94 ( & V_33 -> V_133 ) ;
F_81 ( & V_131 ) ;
F_125 ( V_132 , V_15 ) ;
F_80 ( & V_15 -> V_67 ) ;
V_132 -> V_15 = V_15 ;
F_9 ( ! F_50 ( V_113 ) ) ;
F_156 (work, n, &pool->worklist, entry)
if ( F_39 ( V_6 ) == V_33 )
F_73 ( V_6 , V_113 , & V_65 ) ;
if ( ! F_50 ( V_113 ) ) {
F_149 ( V_132 ) ;
if ( F_53 ( V_15 ) ) {
F_93 ( & V_131 ) ;
F_76 ( V_33 ) ;
F_75 ( & V_33 -> V_133 , & V_24 -> V_134 ) ;
F_95 ( & V_131 ) ;
}
}
F_77 ( V_33 ) ;
if ( F_49 ( V_15 ) )
F_59 ( V_15 ) ;
V_132 -> V_15 = NULL ;
F_81 ( & V_15 -> V_67 ) ;
F_129 ( V_132 , V_15 ) ;
F_80 ( & V_131 ) ;
}
F_81 ( & V_131 ) ;
if ( V_145 ) {
F_151 ( V_148 ) ;
V_132 -> V_53 -> V_32 &= ~ V_138 ;
return 0 ;
}
F_9 ( ! ( V_132 -> V_32 & V_56 ) ) ;
F_152 () ;
goto V_147;
}
static void F_157 ( struct V_2 * V_6 )
{
struct V_149 * V_150 = F_158 ( V_6 , struct V_149 , V_6 ) ;
F_87 ( & V_150 -> V_81 ) ;
}
static void F_159 ( struct V_22 * V_33 ,
struct V_149 * V_150 ,
struct V_2 * V_151 , struct V_50 * V_50 )
{
struct V_62 * V_63 ;
unsigned int V_152 = 0 ;
F_160 ( & V_150 -> V_6 , F_157 ) ;
F_161 ( V_84 , F_7 ( & V_150 -> V_6 ) ) ;
F_162 ( & V_150 -> V_81 ) ;
if ( V_50 )
V_63 = V_50 -> V_113 . V_107 ;
else {
unsigned long * V_153 = F_7 ( V_151 ) ;
V_63 = V_151 -> V_52 . V_107 ;
V_152 = * V_153 & V_66 ;
F_161 ( V_154 , V_153 ) ;
}
F_13 ( & V_150 -> V_6 ) ;
F_98 ( V_33 , & V_150 -> V_6 , V_63 ,
F_27 ( V_74 ) | V_152 ) ;
}
static bool F_163 ( struct V_23 * V_24 ,
int V_78 , int V_98 )
{
bool V_155 = false ;
struct V_22 * V_33 ;
if ( V_78 >= 0 ) {
F_9 ( F_48 ( & V_24 -> V_79 ) ) ;
F_164 ( & V_24 -> V_79 , 1 ) ;
}
F_165 (pwq, wq) {
struct V_14 * V_15 = V_33 -> V_15 ;
F_80 ( & V_15 -> V_67 ) ;
if ( V_78 >= 0 ) {
F_9 ( V_33 -> V_78 != - 1 ) ;
if ( V_33 -> V_76 [ V_78 ] ) {
V_33 -> V_78 = V_78 ;
F_64 ( & V_24 -> V_79 ) ;
V_155 = true ;
}
}
if ( V_98 >= 0 ) {
F_9 ( V_98 != F_29 ( V_33 -> V_98 ) ) ;
V_33 -> V_98 = V_98 ;
}
F_81 ( & V_15 -> V_67 ) ;
}
if ( V_78 >= 0 && F_67 ( & V_24 -> V_79 ) )
F_87 ( & V_24 -> V_80 -> V_81 ) ;
return V_155 ;
}
void F_166 ( struct V_23 * V_24 )
{
struct V_156 V_157 = {
. V_158 = F_167 ( V_157 . V_158 ) ,
. V_78 = - 1 ,
. V_81 = F_168 ( V_157 . V_81 ) ,
} ;
int V_159 ;
F_169 ( & V_24 -> V_160 ) ;
F_170 ( & V_24 -> V_160 ) ;
F_126 ( & V_24 -> V_161 ) ;
V_159 = F_29 ( V_24 -> V_98 ) ;
if ( V_159 != V_24 -> V_78 ) {
F_9 ( ! F_50 ( & V_24 -> V_162 ) ) ;
V_157 . V_78 = V_24 -> V_98 ;
V_24 -> V_98 = V_159 ;
if ( ! V_24 -> V_80 ) {
F_9 ( V_24 -> V_78 != V_157 . V_78 ) ;
V_24 -> V_80 = & V_157 ;
if ( ! F_163 ( V_24 , V_24 -> V_78 ,
V_24 -> V_98 ) ) {
V_24 -> V_78 = V_159 ;
V_24 -> V_80 = NULL ;
goto V_163;
}
} else {
F_9 ( V_24 -> V_78 == V_157 . V_78 ) ;
F_99 ( & V_157 . V_158 , & V_24 -> V_164 ) ;
F_163 ( V_24 , - 1 , V_24 -> V_98 ) ;
}
} else {
F_99 ( & V_157 . V_158 , & V_24 -> V_162 ) ;
}
F_128 ( & V_24 -> V_161 ) ;
F_171 ( & V_157 . V_81 ) ;
if ( V_24 -> V_80 != & V_157 )
return;
F_126 ( & V_24 -> V_161 ) ;
if ( V_24 -> V_80 != & V_157 )
goto V_163;
V_24 -> V_80 = NULL ;
F_9 ( ! F_50 ( & V_157 . V_158 ) ) ;
F_9 ( V_24 -> V_78 != V_157 . V_78 ) ;
while ( true ) {
struct V_156 * V_107 , * V_165 ;
F_156 (next, tmp, &wq->flusher_queue, list) {
if ( V_107 -> V_78 != V_24 -> V_78 )
break;
F_94 ( & V_107 -> V_158 ) ;
F_87 ( & V_107 -> V_81 ) ;
}
F_9 ( ! F_50 ( & V_24 -> V_162 ) &&
V_24 -> V_78 != F_29 ( V_24 -> V_98 ) ) ;
V_24 -> V_78 = F_29 ( V_24 -> V_78 ) ;
if ( ! F_50 ( & V_24 -> V_162 ) ) {
F_144 (tmp, &wq->flusher_overflow, list)
V_165 -> V_78 = V_24 -> V_98 ;
V_24 -> V_98 = F_29 ( V_24 -> V_98 ) ;
F_172 ( & V_24 -> V_162 ,
& V_24 -> V_164 ) ;
F_163 ( V_24 , - 1 , V_24 -> V_98 ) ;
}
if ( F_50 ( & V_24 -> V_164 ) ) {
F_9 ( V_24 -> V_78 != V_24 -> V_98 ) ;
break;
}
F_9 ( V_24 -> V_78 == V_24 -> V_98 ) ;
F_9 ( V_24 -> V_78 != V_107 -> V_78 ) ;
F_94 ( & V_107 -> V_158 ) ;
V_24 -> V_80 = V_107 ;
if ( F_163 ( V_24 , V_24 -> V_78 , - 1 ) )
break;
V_24 -> V_80 = NULL ;
}
V_163:
F_128 ( & V_24 -> V_161 ) ;
}
void F_173 ( struct V_23 * V_24 )
{
unsigned int V_166 = 0 ;
struct V_22 * V_33 ;
F_126 ( & V_24 -> V_161 ) ;
if ( ! V_24 -> V_167 ++ )
V_24 -> V_32 |= V_93 ;
F_128 ( & V_24 -> V_161 ) ;
V_168:
F_166 ( V_24 ) ;
F_126 ( & V_24 -> V_161 ) ;
F_165 (pwq, wq) {
bool V_169 ;
F_80 ( & V_33 -> V_15 -> V_67 ) ;
V_169 = ! V_33 -> V_72 && F_50 ( & V_33 -> V_73 ) ;
F_81 ( & V_33 -> V_15 -> V_67 ) ;
if ( V_169 )
continue;
if ( ++ V_166 == 10 ||
( V_166 % 100 == 0 && V_166 <= 1000 ) )
F_174 ( L_8 ,
V_24 -> V_97 , V_166 ) ;
F_128 ( & V_24 -> V_161 ) ;
goto V_168;
}
if ( ! -- V_24 -> V_167 )
V_24 -> V_32 &= ~ V_93 ;
F_128 ( & V_24 -> V_161 ) ;
}
static bool F_175 ( struct V_2 * V_6 , struct V_149 * V_150 )
{
struct V_50 * V_50 = NULL ;
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_176 () ;
F_177 () ;
V_15 = F_41 ( V_6 ) ;
if ( ! V_15 ) {
F_178 () ;
return false ;
}
F_93 ( & V_15 -> V_67 ) ;
V_33 = F_39 ( V_6 ) ;
if ( V_33 ) {
if ( F_57 ( V_33 -> V_15 != V_15 ) )
goto V_170;
} else {
V_50 = F_71 ( V_15 , V_6 ) ;
if ( ! V_50 )
goto V_170;
V_33 = V_50 -> V_89 ;
}
F_159 ( V_33 , V_150 , V_6 , V_50 ) ;
F_81 ( & V_15 -> V_67 ) ;
if ( V_33 -> V_24 -> V_171 == 1 || V_33 -> V_24 -> V_132 )
F_169 ( & V_33 -> V_24 -> V_160 ) ;
else
F_179 ( & V_33 -> V_24 -> V_160 ) ;
F_170 ( & V_33 -> V_24 -> V_160 ) ;
return true ;
V_170:
F_81 ( & V_15 -> V_67 ) ;
return false ;
}
bool F_180 ( struct V_2 * V_6 )
{
struct V_149 V_150 ;
F_169 ( & V_6 -> V_160 ) ;
F_170 ( & V_6 -> V_160 ) ;
if ( F_175 ( V_6 , & V_150 ) ) {
F_171 ( & V_150 . V_81 ) ;
F_18 ( & V_150 . V_6 ) ;
return true ;
} else {
return false ;
}
}
static bool F_181 ( struct V_2 * V_6 , bool V_82 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_88 ( V_6 , V_82 , & V_32 ) ;
if ( F_57 ( V_16 == - V_87 ) )
F_180 ( V_6 ) ;
} while ( F_57 ( V_16 < 0 ) );
F_45 ( V_6 ) ;
F_96 ( V_32 ) ;
F_180 ( V_6 ) ;
F_38 ( V_6 ) ;
return V_16 ;
}
bool F_3 ( struct V_2 * V_6 )
{
return F_181 ( V_6 , false ) ;
}
bool F_182 ( struct V_12 * V_83 )
{
F_177 () ;
if ( F_183 ( & V_83 -> V_13 ) )
F_103 ( V_83 -> V_55 , V_83 -> V_24 , & V_83 -> V_6 ) ;
F_178 () ;
return F_180 ( & V_83 -> V_6 ) ;
}
bool F_184 ( struct V_12 * V_83 )
{
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_88 ( & V_83 -> V_6 , true , & V_32 ) ;
} while ( F_57 ( V_16 == - V_88 ) );
if ( F_57 ( V_16 < 0 ) )
return false ;
F_36 ( & V_83 -> V_6 ,
F_44 ( & V_83 -> V_6 ) ) ;
F_96 ( V_32 ) ;
return V_16 ;
}
bool F_185 ( struct V_12 * V_83 )
{
return F_181 ( & V_83 -> V_6 , true ) ;
}
int F_186 ( T_1 V_3 )
{
int V_55 ;
struct V_2 T_2 * V_172 ;
V_172 = F_187 ( struct V_2 ) ;
if ( ! V_172 )
return - V_173 ;
F_188 () ;
F_189 (cpu) {
struct V_2 * V_6 = F_105 ( V_172 , V_55 ) ;
F_190 ( V_6 , V_3 ) ;
F_191 ( V_55 , V_6 ) ;
}
F_189 (cpu)
F_180 ( F_105 ( V_172 , V_55 ) ) ;
F_192 () ;
F_193 ( V_172 ) ;
return 0 ;
}
void F_194 ( void )
{
F_166 ( V_174 ) ;
}
int F_195 ( T_1 V_175 , struct V_176 * V_177 )
{
if ( ! F_196 () ) {
V_175 ( & V_177 -> V_6 ) ;
return 0 ;
}
F_190 ( & V_177 -> V_6 , V_175 ) ;
F_78 ( & V_177 -> V_6 ) ;
return 1 ;
}
static struct V_23 * F_197 ( struct V_178 * V_179 )
{
struct V_180 * V_181 = F_158 ( V_179 , struct V_180 , V_179 ) ;
return V_181 -> V_24 ;
}
static T_3 F_198 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
return F_199 ( V_184 , V_185 , L_9 , ( bool ) ! ( V_24 -> V_32 & V_69 ) ) ;
}
static T_3 F_200 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
return F_199 ( V_184 , V_185 , L_9 , V_24 -> V_171 ) ;
}
static T_3 F_201 ( struct V_178 * V_179 ,
struct V_182 * V_183 , const char * V_184 ,
T_4 V_186 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
int V_187 ;
if ( sscanf ( V_184 , L_10 , & V_187 ) != 1 || V_187 <= 0 )
return - V_188 ;
F_202 ( V_24 , V_187 ) ;
return V_186 ;
}
static T_3 F_203 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
const char * V_189 = L_4 ;
int V_25 , V_190 = 0 ;
F_204 () ;
F_205 (node) {
V_190 += F_199 ( V_184 + V_190 , V_185 - V_190 ,
L_11 , V_189 , V_25 ,
F_24 ( V_24 , V_25 ) -> V_15 -> V_21 ) ;
V_189 = L_12 ;
}
V_190 += F_199 ( V_184 + V_190 , V_185 - V_190 , L_13 ) ;
F_206 () ;
return V_190 ;
}
static T_3 F_207 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
int V_190 ;
F_126 ( & V_24 -> V_161 ) ;
V_190 = F_199 ( V_184 , V_185 , L_9 , V_24 -> V_191 -> V_125 ) ;
F_128 ( & V_24 -> V_161 ) ;
return V_190 ;
}
static struct V_192 * F_208 ( struct V_23 * V_24 )
{
struct V_192 * V_116 ;
V_116 = F_209 ( V_20 ) ;
if ( ! V_116 )
return NULL ;
F_126 ( & V_24 -> V_161 ) ;
F_210 ( V_116 , V_24 -> V_191 ) ;
F_128 ( & V_24 -> V_161 ) ;
return V_116 ;
}
static T_3 F_211 ( struct V_178 * V_179 , struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
struct V_192 * V_116 ;
int V_16 ;
V_116 = F_208 ( V_24 ) ;
if ( ! V_116 )
return - V_173 ;
if ( sscanf ( V_184 , L_10 , & V_116 -> V_125 ) == 1 &&
V_116 -> V_125 >= V_193 && V_116 -> V_125 <= V_194 )
V_16 = F_212 ( V_24 , V_116 ) ;
else
V_16 = - V_188 ;
F_213 ( V_116 ) ;
return V_16 ? : V_186 ;
}
static T_3 F_214 ( struct V_178 * V_179 ,
struct V_182 * V_183 , char * V_184 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
int V_190 ;
F_126 ( & V_24 -> V_161 ) ;
V_190 = F_215 ( V_184 , V_185 , V_24 -> V_191 -> V_117 ) ;
F_128 ( & V_24 -> V_161 ) ;
V_190 += F_199 ( V_184 + V_190 , V_185 - V_190 , L_13 ) ;
return V_190 ;
}
static T_3 F_216 ( struct V_178 * V_179 ,
struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
struct V_192 * V_116 ;
int V_16 ;
V_116 = F_208 ( V_24 ) ;
if ( ! V_116 )
return - V_173 ;
V_16 = F_217 ( V_184 , V_116 -> V_117 ) ;
if ( ! V_16 )
V_16 = F_212 ( V_24 , V_116 ) ;
F_213 ( V_116 ) ;
return V_16 ? : V_186 ;
}
static T_3 F_218 ( struct V_178 * V_179 , struct V_182 * V_183 ,
char * V_184 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
int V_190 ;
F_126 ( & V_24 -> V_161 ) ;
V_190 = F_199 ( V_184 , V_185 , L_9 ,
! V_24 -> V_191 -> V_195 ) ;
F_128 ( & V_24 -> V_161 ) ;
return V_190 ;
}
static T_3 F_219 ( struct V_178 * V_179 , struct V_182 * V_183 ,
const char * V_184 , T_4 V_186 )
{
struct V_23 * V_24 = F_197 ( V_179 ) ;
struct V_192 * V_116 ;
int V_196 , V_16 ;
V_116 = F_208 ( V_24 ) ;
if ( ! V_116 )
return - V_173 ;
V_16 = - V_188 ;
if ( sscanf ( V_184 , L_10 , & V_196 ) == 1 ) {
V_116 -> V_195 = ! V_196 ;
V_16 = F_212 ( V_24 , V_116 ) ;
}
F_213 ( V_116 ) ;
return V_16 ? : V_186 ;
}
static int T_5 F_220 ( void )
{
return F_221 ( & V_197 , NULL ) ;
}
static void F_222 ( struct V_178 * V_179 )
{
struct V_180 * V_181 = F_158 ( V_179 , struct V_180 , V_179 ) ;
F_137 ( V_181 ) ;
}
int F_223 ( struct V_23 * V_24 )
{
struct V_180 * V_181 ;
int V_16 ;
if ( F_10 ( V_24 -> V_32 & V_198 ) )
return - V_188 ;
V_24 -> V_181 = V_181 = F_224 ( sizeof( * V_181 ) , V_20 ) ;
if ( ! V_181 )
return - V_173 ;
V_181 -> V_24 = V_24 ;
V_181 -> V_179 . V_199 = & V_197 ;
V_181 -> V_179 . V_200 = V_24 -> V_97 ;
V_181 -> V_179 . V_201 = F_222 ;
F_225 ( & V_181 -> V_179 , true ) ;
V_16 = F_226 ( & V_181 -> V_179 ) ;
if ( V_16 ) {
F_137 ( V_181 ) ;
V_24 -> V_181 = NULL ;
return V_16 ;
}
if ( V_24 -> V_32 & V_69 ) {
struct V_182 * V_183 ;
for ( V_183 = V_202 ; V_183 -> V_183 . V_97 ; V_183 ++ ) {
V_16 = F_227 ( & V_181 -> V_179 , V_183 ) ;
if ( V_16 ) {
F_228 ( & V_181 -> V_179 ) ;
V_24 -> V_181 = NULL ;
return V_16 ;
}
}
}
F_225 ( & V_181 -> V_179 , false ) ;
F_229 ( & V_181 -> V_179 . V_203 , V_204 ) ;
return 0 ;
}
static void F_230 ( struct V_23 * V_24 )
{
struct V_180 * V_181 = V_24 -> V_181 ;
if ( ! V_24 -> V_181 )
return;
V_24 -> V_181 = NULL ;
F_228 ( & V_181 -> V_179 ) ;
}
static void F_230 ( struct V_23 * V_24 ) { }
void F_213 ( struct V_192 * V_116 )
{
if ( V_116 ) {
F_231 ( V_116 -> V_117 ) ;
F_137 ( V_116 ) ;
}
}
struct V_192 * F_209 ( T_6 V_205 )
{
struct V_192 * V_116 ;
V_116 = F_224 ( sizeof( * V_116 ) , V_205 ) ;
if ( ! V_116 )
goto V_85;
if ( ! F_232 ( & V_116 -> V_117 , V_205 ) )
goto V_85;
F_233 ( V_116 -> V_117 , V_206 ) ;
return V_116 ;
V_85:
F_213 ( V_116 ) ;
return NULL ;
}
static void F_210 ( struct V_192 * V_207 ,
const struct V_192 * V_208 )
{
V_207 -> V_125 = V_208 -> V_125 ;
F_233 ( V_207 -> V_117 , V_208 -> V_117 ) ;
V_207 -> V_195 = V_208 -> V_195 ;
}
static T_7 F_234 ( const struct V_192 * V_116 )
{
T_7 V_209 = 0 ;
V_209 = F_235 ( V_116 -> V_125 , V_209 ) ;
V_209 = F_236 ( F_237 ( V_116 -> V_117 ) ,
F_238 ( V_210 ) * sizeof( long ) , V_209 ) ;
return V_209 ;
}
static bool F_239 ( const struct V_192 * V_211 ,
const struct V_192 * V_212 )
{
if ( V_211 -> V_125 != V_212 -> V_125 )
return false ;
if ( ! F_240 ( V_211 -> V_117 , V_212 -> V_117 ) )
return false ;
return true ;
}
static int F_241 ( struct V_14 * V_15 )
{
F_242 ( & V_15 -> V_67 ) ;
V_15 -> V_21 = - 1 ;
V_15 -> V_55 = - 1 ;
V_15 -> V_25 = V_213 ;
V_15 -> V_32 |= V_112 ;
F_124 ( & V_15 -> V_43 ) ;
F_124 ( & V_15 -> V_51 ) ;
F_243 ( V_15 -> V_214 ) ;
F_244 ( & V_15 -> V_110 ) ;
V_15 -> V_110 . V_102 = F_139 ;
V_15 -> V_110 . V_31 = ( unsigned long ) V_15 ;
F_245 ( & V_15 -> V_135 , F_143 ,
( unsigned long ) V_15 ) ;
F_246 ( & V_15 -> V_46 ) ;
F_246 ( & V_15 -> V_115 ) ;
F_124 ( & V_15 -> V_119 ) ;
F_247 ( & V_15 -> V_124 ) ;
F_248 ( & V_15 -> V_215 ) ;
V_15 -> V_68 = 1 ;
V_15 -> V_116 = F_209 ( V_20 ) ;
if ( ! V_15 -> V_116 )
return - V_173 ;
return 0 ;
}
static void F_249 ( struct V_216 * V_217 )
{
struct V_14 * V_15 = F_158 ( V_217 , struct V_14 , V_217 ) ;
F_250 ( & V_15 -> V_124 ) ;
F_213 ( V_15 -> V_116 ) ;
F_137 ( V_15 ) ;
}
static void F_251 ( struct V_14 * V_15 )
{
F_252 ( V_121 ) ;
struct V_50 * V_50 ;
F_22 ( & V_17 ) ;
if ( -- V_15 -> V_68 )
return;
if ( F_10 ( ! ( V_15 -> V_55 < 0 ) ) ||
F_10 ( ! F_50 ( & V_15 -> V_43 ) ) )
return;
if ( V_15 -> V_21 >= 0 )
F_253 ( & V_18 , V_15 -> V_21 ) ;
F_254 ( & V_15 -> V_215 ) ;
F_126 ( & V_15 -> V_46 ) ;
F_80 ( & V_15 -> V_67 ) ;
while ( ( V_50 = F_56 ( V_15 ) ) )
F_138 ( V_50 ) ;
F_10 ( V_15 -> V_48 || V_15 -> V_44 ) ;
F_81 ( & V_15 -> V_67 ) ;
F_126 ( & V_15 -> V_115 ) ;
if ( ! F_50 ( & V_15 -> V_119 ) )
V_15 -> V_121 = & V_121 ;
F_128 ( & V_15 -> V_115 ) ;
if ( V_15 -> V_121 )
F_171 ( V_15 -> V_121 ) ;
F_128 ( & V_15 -> V_46 ) ;
F_183 ( & V_15 -> V_110 ) ;
F_183 ( & V_15 -> V_135 ) ;
F_255 ( & V_15 -> V_217 , F_249 ) ;
}
static struct V_14 * F_256 ( const struct V_192 * V_116 )
{
T_7 V_209 = F_234 ( V_116 ) ;
struct V_14 * V_15 ;
int V_25 ;
F_22 ( & V_17 ) ;
F_72 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_239 ( V_15 -> V_116 , V_116 ) ) {
V_15 -> V_68 ++ ;
return V_15 ;
}
}
V_15 = F_224 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 || F_241 ( V_15 ) < 0 )
goto V_85;
F_257 ( & V_15 -> V_67 , 1 ) ;
F_210 ( V_15 -> V_116 , V_116 ) ;
V_15 -> V_116 -> V_195 = false ;
if ( V_218 ) {
F_205 (node) {
if ( F_258 ( V_15 -> V_116 -> V_117 ,
V_219 [ V_25 ] ) ) {
V_15 -> V_25 = V_25 ;
break;
}
}
}
if ( F_21 ( V_15 ) < 0 )
goto V_85;
if ( ! F_131 ( V_15 ) )
goto V_85;
F_259 ( V_220 , & V_15 -> V_215 , V_209 ) ;
return V_15 ;
V_85:
if ( V_15 )
F_251 ( V_15 ) ;
return NULL ;
}
static void F_260 ( struct V_216 * V_217 )
{
F_261 ( V_221 ,
F_158 ( V_217 , struct V_22 , V_217 ) ) ;
}
static void F_262 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_158 ( V_6 , struct V_22 ,
V_70 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
struct V_14 * V_15 = V_33 -> V_15 ;
bool V_222 ;
if ( F_9 ( ! ( V_24 -> V_32 & V_69 ) ) )
return;
F_126 ( & V_24 -> V_161 ) ;
F_263 ( & V_33 -> V_223 ) ;
V_222 = F_50 ( & V_24 -> V_224 ) ;
F_128 ( & V_24 -> V_161 ) ;
F_126 ( & V_17 ) ;
F_251 ( V_15 ) ;
F_128 ( & V_17 ) ;
F_255 ( & V_33 -> V_217 , F_260 ) ;
if ( V_222 ) {
F_213 ( V_24 -> V_191 ) ;
F_137 ( V_24 ) ;
}
}
static void F_264 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
bool V_225 = V_24 -> V_32 & V_226 ;
F_22 ( & V_24 -> V_161 ) ;
if ( ! V_225 && V_33 -> V_77 == V_24 -> V_171 )
return;
F_80 ( & V_33 -> V_15 -> V_67 ) ;
if ( ! V_225 || ! V_227 ) {
V_33 -> V_77 = V_24 -> V_171 ;
while ( ! F_50 ( & V_33 -> V_73 ) &&
V_33 -> V_72 < V_33 -> V_77 )
F_85 ( V_33 ) ;
F_59 ( V_33 -> V_15 ) ;
} else {
V_33 -> V_77 = 0 ;
}
F_81 ( & V_33 -> V_15 -> V_67 ) ;
}
static void F_265 ( struct V_22 * V_33 , struct V_23 * V_24 ,
struct V_14 * V_15 )
{
F_266 ( ( unsigned long ) V_33 & V_228 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_15 = V_15 ;
V_33 -> V_24 = V_24 ;
V_33 -> V_78 = - 1 ;
V_33 -> V_68 = 1 ;
F_124 ( & V_33 -> V_73 ) ;
F_124 ( & V_33 -> V_223 ) ;
F_124 ( & V_33 -> V_133 ) ;
F_190 ( & V_33 -> V_70 , F_262 ) ;
}
static void F_267 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
F_22 ( & V_24 -> V_161 ) ;
if ( ! F_50 ( & V_33 -> V_223 ) )
return;
V_33 -> V_98 = V_24 -> V_98 ;
F_264 ( V_33 ) ;
F_268 ( & V_33 -> V_223 , & V_24 -> V_224 ) ;
}
static struct V_22 * F_269 ( struct V_23 * V_24 ,
const struct V_192 * V_116 )
{
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_22 ( & V_17 ) ;
V_15 = F_256 ( V_116 ) ;
if ( ! V_15 )
return NULL ;
V_33 = F_270 ( V_221 , V_20 , V_15 -> V_25 ) ;
if ( ! V_33 ) {
F_251 ( V_15 ) ;
return NULL ;
}
F_265 ( V_33 , V_24 , V_15 ) ;
return V_33 ;
}
static void F_271 ( struct V_22 * V_33 )
{
F_22 ( & V_17 ) ;
if ( V_33 ) {
F_251 ( V_33 -> V_15 ) ;
F_261 ( V_221 , V_33 ) ;
}
}
static bool F_272 ( const struct V_192 * V_116 , int V_25 ,
int V_229 , T_8 * V_117 )
{
if ( ! V_218 || V_116 -> V_195 )
goto V_230;
F_273 ( V_117 , F_274 ( V_25 ) , V_116 -> V_117 ) ;
if ( V_229 >= 0 )
F_275 ( V_229 , V_117 ) ;
if ( F_276 ( V_117 ) )
goto V_230;
F_273 ( V_117 , V_116 -> V_117 , V_219 [ V_25 ] ) ;
return ! F_240 ( V_117 , V_116 -> V_117 ) ;
V_230:
F_233 ( V_117 , V_116 -> V_117 ) ;
return false ;
}
static struct V_22 * F_277 ( struct V_23 * V_24 ,
int V_25 ,
struct V_22 * V_33 )
{
struct V_22 * V_231 ;
F_22 ( & V_24 -> V_161 ) ;
F_267 ( V_33 ) ;
V_231 = F_278 ( V_24 -> V_26 [ V_25 ] ) ;
F_279 ( V_24 -> V_26 [ V_25 ] , V_33 ) ;
return V_231 ;
}
int F_212 ( struct V_23 * V_24 ,
const struct V_192 * V_116 )
{
struct V_192 * V_232 , * V_233 ;
struct V_22 * * V_234 , * V_235 ;
int V_25 , V_16 ;
if ( F_10 ( ! ( V_24 -> V_32 & V_69 ) ) )
return - V_188 ;
if ( F_10 ( ( V_24 -> V_32 & V_198 ) && ! F_50 ( & V_24 -> V_224 ) ) )
return - V_188 ;
V_234 = F_224 ( V_236 * sizeof( V_234 [ 0 ] ) , V_20 ) ;
V_232 = F_209 ( V_20 ) ;
V_233 = F_209 ( V_20 ) ;
if ( ! V_234 || ! V_232 || ! V_233 )
goto V_237;
F_210 ( V_232 , V_116 ) ;
F_273 ( V_232 -> V_117 , V_232 -> V_117 , V_206 ) ;
F_210 ( V_233 , V_232 ) ;
F_188 () ;
F_126 ( & V_17 ) ;
V_235 = F_269 ( V_24 , V_232 ) ;
if ( ! V_235 )
goto V_238;
F_205 (node) {
if ( F_272 ( V_116 , V_25 , - 1 , V_233 -> V_117 ) ) {
V_234 [ V_25 ] = F_269 ( V_24 , V_233 ) ;
if ( ! V_234 [ V_25 ] )
goto V_238;
} else {
V_235 -> V_68 ++ ;
V_234 [ V_25 ] = V_235 ;
}
}
F_128 ( & V_17 ) ;
F_126 ( & V_24 -> V_161 ) ;
F_210 ( V_24 -> V_191 , V_232 ) ;
F_205 (node)
V_234 [ V_25 ] = F_277 ( V_24 , V_25 , V_234 [ V_25 ] ) ;
F_267 ( V_235 ) ;
F_280 ( V_24 -> V_235 , V_235 ) ;
F_128 ( & V_24 -> V_161 ) ;
F_205 (node)
F_79 ( V_234 [ V_25 ] ) ;
F_79 ( V_235 ) ;
F_192 () ;
V_16 = 0 ;
V_239:
F_213 ( V_233 ) ;
F_213 ( V_232 ) ;
F_137 ( V_234 ) ;
return V_16 ;
V_238:
F_271 ( V_235 ) ;
F_205 (node)
if ( V_234 && V_234 [ V_25 ] != V_235 )
F_271 ( V_234 [ V_25 ] ) ;
F_128 ( & V_17 ) ;
F_192 () ;
V_237:
V_16 = - V_173 ;
goto V_239;
}
static void F_281 ( struct V_23 * V_24 , int V_55 ,
bool V_240 )
{
int V_25 = F_106 ( V_55 ) ;
int V_241 = V_240 ? - 1 : V_55 ;
struct V_22 * V_231 = NULL , * V_33 ;
struct V_192 * V_242 ;
T_8 * V_117 ;
F_22 ( & V_17 ) ;
if ( ! V_218 || ! ( V_24 -> V_32 & V_69 ) )
return;
V_242 = V_243 ;
V_117 = V_242 -> V_117 ;
F_126 ( & V_24 -> V_161 ) ;
if ( V_24 -> V_191 -> V_195 )
goto V_163;
F_210 ( V_242 , V_24 -> V_191 ) ;
V_33 = F_24 ( V_24 , V_25 ) ;
if ( F_272 ( V_24 -> V_191 , V_25 , V_241 , V_117 ) ) {
if ( F_240 ( V_117 , V_33 -> V_15 -> V_116 -> V_117 ) )
goto V_163;
} else {
goto V_244;
}
F_128 ( & V_24 -> V_161 ) ;
V_33 = F_269 ( V_24 , V_242 ) ;
if ( ! V_33 ) {
F_174 ( L_14 ,
V_24 -> V_97 ) ;
F_126 ( & V_24 -> V_161 ) ;
goto V_244;
}
F_126 ( & V_24 -> V_161 ) ;
V_231 = F_277 ( V_24 , V_25 , V_33 ) ;
goto V_163;
V_244:
F_80 ( & V_24 -> V_235 -> V_15 -> V_67 ) ;
F_76 ( V_24 -> V_235 ) ;
F_81 ( & V_24 -> V_235 -> V_15 -> V_67 ) ;
V_231 = F_277 ( V_24 , V_25 , V_24 -> V_235 ) ;
V_163:
F_128 ( & V_24 -> V_161 ) ;
F_79 ( V_231 ) ;
}
static int F_282 ( struct V_23 * V_24 )
{
bool V_245 = V_24 -> V_32 & V_246 ;
int V_55 , V_16 ;
if ( ! ( V_24 -> V_32 & V_69 ) ) {
V_24 -> V_96 = F_187 ( struct V_22 ) ;
if ( ! V_24 -> V_96 )
return - V_173 ;
F_283 (cpu) {
struct V_22 * V_33 =
F_105 ( V_24 -> V_96 , V_55 ) ;
struct V_14 * V_247 =
F_284 ( V_248 , V_55 ) ;
F_265 ( V_33 , V_24 , & V_247 [ V_245 ] ) ;
F_126 ( & V_24 -> V_161 ) ;
F_267 ( V_33 ) ;
F_128 ( & V_24 -> V_161 ) ;
}
return 0 ;
} else if ( V_24 -> V_32 & V_198 ) {
V_16 = F_212 ( V_24 , V_249 [ V_245 ] ) ;
F_285 ( ! V_16 && ( V_24 -> V_224 . V_107 != & V_24 -> V_235 -> V_223 ||
V_24 -> V_224 . V_130 != & V_24 -> V_235 -> V_223 ) ,
L_15 , V_24 -> V_97 ) ;
return V_16 ;
} else {
return F_212 ( V_24 , V_250 [ V_245 ] ) ;
}
}
static int F_286 ( int V_77 , unsigned int V_32 ,
const char * V_97 )
{
int V_251 = V_32 & V_69 ? V_252 : V_253 ;
if ( V_77 < 1 || V_77 > V_251 )
F_174 ( L_16 ,
V_77 , V_97 , 1 , V_251 ) ;
return F_287 ( V_77 , 1 , V_251 ) ;
}
struct V_23 * F_288 ( const char * V_254 ,
unsigned int V_32 ,
int V_77 ,
struct V_255 * V_256 ,
const char * V_257 , ... )
{
T_4 V_258 = 0 ;
T_9 args ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
if ( ( V_32 & V_259 ) && V_260 )
V_32 |= V_69 ;
if ( V_32 & V_69 )
V_258 = V_236 * sizeof( V_24 -> V_26 [ 0 ] ) ;
V_24 = F_224 ( sizeof( * V_24 ) + V_258 , V_20 ) ;
if ( ! V_24 )
return NULL ;
if ( V_32 & V_69 ) {
V_24 -> V_191 = F_209 ( V_20 ) ;
if ( ! V_24 -> V_191 )
goto V_261;
}
va_start ( args , V_257 ) ;
vsnprintf ( V_24 -> V_97 , sizeof( V_24 -> V_97 ) , V_254 , args ) ;
va_end ( args ) ;
V_77 = V_77 ? : V_262 ;
V_77 = F_286 ( V_77 , V_32 , V_24 -> V_97 ) ;
V_24 -> V_32 = V_32 ;
V_24 -> V_171 = V_77 ;
F_246 ( & V_24 -> V_161 ) ;
F_164 ( & V_24 -> V_79 , 0 ) ;
F_124 ( & V_24 -> V_224 ) ;
F_124 ( & V_24 -> V_164 ) ;
F_124 ( & V_24 -> V_162 ) ;
F_124 ( & V_24 -> V_134 ) ;
F_289 ( & V_24 -> V_160 , V_257 , V_256 , 0 ) ;
F_124 ( & V_24 -> V_158 ) ;
if ( F_282 ( V_24 ) < 0 )
goto V_261;
if ( V_32 & V_263 ) {
struct V_50 * V_132 ;
V_132 = F_122 ( V_213 ) ;
if ( ! V_132 )
goto V_264;
V_132 -> V_144 = V_24 ;
V_132 -> V_53 = F_290 ( F_153 , V_132 , L_17 ,
V_24 -> V_97 ) ;
if ( F_134 ( V_132 -> V_53 ) ) {
F_137 ( V_132 ) ;
goto V_264;
}
V_24 -> V_132 = V_132 ;
V_132 -> V_53 -> V_32 |= V_127 ;
F_61 ( V_132 -> V_53 ) ;
}
if ( ( V_24 -> V_32 & V_265 ) && F_223 ( V_24 ) )
goto V_264;
F_126 ( & V_17 ) ;
F_126 ( & V_24 -> V_161 ) ;
F_165 (pwq, wq)
F_264 ( V_33 ) ;
F_128 ( & V_24 -> V_161 ) ;
F_119 ( & V_24 -> V_158 , & V_266 ) ;
F_128 ( & V_17 ) ;
return V_24 ;
V_261:
F_213 ( V_24 -> V_191 ) ;
F_137 ( V_24 ) ;
return NULL ;
V_264:
F_291 ( V_24 ) ;
return NULL ;
}
void F_291 ( struct V_23 * V_24 )
{
struct V_22 * V_33 ;
int V_25 ;
F_173 ( V_24 ) ;
F_126 ( & V_24 -> V_161 ) ;
F_165 (pwq, wq) {
int V_267 ;
for ( V_267 = 0 ; V_267 < V_30 ; V_267 ++ ) {
if ( F_10 ( V_33 -> V_76 [ V_267 ] ) ) {
F_128 ( & V_24 -> V_161 ) ;
return;
}
}
if ( F_10 ( ( V_33 != V_24 -> V_235 ) && ( V_33 -> V_68 > 1 ) ) ||
F_10 ( V_33 -> V_72 ) ||
F_10 ( ! F_50 ( & V_33 -> V_73 ) ) ) {
F_128 ( & V_24 -> V_161 ) ;
return;
}
}
F_128 ( & V_24 -> V_161 ) ;
F_126 ( & V_17 ) ;
F_94 ( & V_24 -> V_158 ) ;
F_128 ( & V_17 ) ;
F_230 ( V_24 ) ;
if ( V_24 -> V_132 ) {
F_292 ( V_24 -> V_132 -> V_53 ) ;
F_137 ( V_24 -> V_132 ) ;
V_24 -> V_132 = NULL ;
}
if ( ! ( V_24 -> V_32 & V_69 ) ) {
F_193 ( V_24 -> V_96 ) ;
F_137 ( V_24 ) ;
} else {
F_205 (node) {
V_33 = F_278 ( V_24 -> V_26 [ V_25 ] ) ;
F_293 ( V_24 -> V_26 [ V_25 ] , NULL ) ;
F_79 ( V_33 ) ;
}
V_33 = V_24 -> V_235 ;
V_24 -> V_235 = NULL ;
F_79 ( V_33 ) ;
}
}
void F_202 ( struct V_23 * V_24 , int V_77 )
{
struct V_22 * V_33 ;
if ( F_10 ( V_24 -> V_32 & V_198 ) )
return;
V_77 = F_286 ( V_77 , V_24 -> V_32 , V_24 -> V_97 ) ;
F_126 ( & V_24 -> V_161 ) ;
V_24 -> V_171 = V_77 ;
F_165 (pwq, wq)
F_264 ( V_33 ) ;
F_128 ( & V_24 -> V_161 ) ;
}
bool F_294 ( void )
{
struct V_50 * V_50 = F_102 () ;
return V_50 && V_50 -> V_144 ;
}
bool F_295 ( int V_55 , struct V_23 * V_24 )
{
struct V_22 * V_33 ;
bool V_16 ;
F_204 () ;
if ( V_55 == V_95 )
V_55 = F_296 () ;
if ( ! ( V_24 -> V_32 & V_69 ) )
V_33 = F_105 ( V_24 -> V_96 , V_55 ) ;
else
V_33 = F_24 ( V_24 , F_106 ( V_55 ) ) ;
V_16 = ! F_50 ( & V_33 -> V_73 ) ;
F_206 () ;
return V_16 ;
}
unsigned int F_297 ( struct V_2 * V_6 )
{
struct V_14 * V_15 ;
unsigned long V_32 ;
unsigned int V_16 = 0 ;
if ( F_31 ( V_6 ) )
V_16 |= V_268 ;
F_89 ( V_32 ) ;
V_15 = F_41 ( V_6 ) ;
if ( V_15 ) {
F_93 ( & V_15 -> V_67 ) ;
if ( F_71 ( V_15 , V_6 ) )
V_16 |= V_269 ;
F_95 ( & V_15 -> V_67 ) ;
}
F_96 ( V_32 ) ;
return V_16 ;
}
void F_298 ( const char * V_254 , ... )
{
struct V_50 * V_50 = F_102 () ;
T_9 args ;
if ( V_50 ) {
va_start ( args , V_254 ) ;
vsnprintf ( V_50 -> V_270 , sizeof( V_50 -> V_270 ) , V_254 , args ) ;
va_end ( args ) ;
V_50 -> V_271 = true ;
}
}
void F_299 ( const char * V_272 , struct V_54 * V_53 )
{
T_1 * V_175 = NULL ;
char V_97 [ V_273 ] = { } ;
char V_270 [ V_274 ] = { } ;
struct V_22 * V_33 = NULL ;
struct V_23 * V_24 = NULL ;
bool V_271 = false ;
struct V_50 * V_50 ;
if ( ! ( V_53 -> V_32 & V_138 ) )
return;
V_50 = F_300 ( V_53 ) ;
F_301 ( & V_175 , & V_50 -> V_61 , sizeof( V_175 ) ) ;
F_301 ( & V_33 , & V_50 -> V_89 , sizeof( V_33 ) ) ;
F_301 ( & V_24 , & V_33 -> V_24 , sizeof( V_24 ) ) ;
F_301 ( V_97 , V_24 -> V_97 , sizeof( V_97 ) - 1 ) ;
F_301 ( & V_271 , & V_50 -> V_271 , sizeof( V_271 ) ) ;
if ( V_271 )
F_301 ( V_270 , V_50 -> V_270 , sizeof( V_270 ) - 1 ) ;
if ( V_175 || V_97 [ 0 ] || V_270 [ 0 ] ) {
F_302 ( L_18 , V_272 , V_97 , V_175 ) ;
if ( V_270 [ 0 ] )
F_303 ( L_19 , V_270 ) ;
F_303 ( L_13 ) ;
}
}
static void F_304 ( struct V_2 * V_6 )
{
int V_55 = F_296 () ;
struct V_14 * V_15 ;
struct V_50 * V_50 ;
F_305 (pool, cpu) {
F_126 ( & V_15 -> V_115 ) ;
F_80 ( & V_15 -> V_67 ) ;
F_306 (worker, pool)
V_50 -> V_32 |= V_118 ;
V_15 -> V_32 |= V_112 ;
F_81 ( & V_15 -> V_67 ) ;
F_128 ( & V_15 -> V_115 ) ;
F_152 () ;
F_164 ( & V_15 -> V_42 , 0 ) ;
F_80 ( & V_15 -> V_67 ) ;
F_59 ( V_15 ) ;
F_81 ( & V_15 -> V_67 ) ;
}
}
static void F_307 ( struct V_14 * V_15 )
{
struct V_50 * V_50 ;
F_22 ( & V_15 -> V_115 ) ;
F_306 (worker, pool)
F_9 ( F_127 ( V_50 -> V_53 ,
V_15 -> V_116 -> V_117 ) < 0 ) ;
F_80 ( & V_15 -> V_67 ) ;
V_15 -> V_32 &= ~ V_112 ;
F_306 (worker, pool) {
unsigned int V_275 = V_50 -> V_32 ;
if ( V_275 & V_105 )
F_61 ( V_50 -> V_53 ) ;
F_9 ( ! ( V_275 & V_118 ) ) ;
V_275 |= V_122 ;
V_275 &= ~ V_118 ;
F_308 ( V_50 -> V_32 ) = V_275 ;
}
F_81 ( & V_15 -> V_67 ) ;
}
static void F_309 ( struct V_14 * V_15 , int V_55 )
{
static T_8 V_117 ;
struct V_50 * V_50 ;
F_22 ( & V_15 -> V_115 ) ;
if ( ! F_310 ( V_55 , V_15 -> V_116 -> V_117 ) )
return;
F_273 ( & V_117 , V_15 -> V_116 -> V_117 , V_276 ) ;
if ( F_311 ( & V_117 ) != 1 )
return;
F_306 (worker, pool)
F_9 ( F_127 ( V_50 -> V_53 ,
V_15 -> V_116 -> V_117 ) < 0 ) ;
}
static int F_312 ( struct V_277 * V_278 ,
unsigned long V_279 ,
void * V_280 )
{
int V_55 = ( unsigned long ) V_280 ;
struct V_14 * V_15 ;
struct V_23 * V_24 ;
int V_281 ;
switch ( V_279 & ~ V_282 ) {
case V_283 :
F_305 (pool, cpu) {
if ( V_15 -> V_48 )
continue;
if ( ! F_131 ( V_15 ) )
return V_284 ;
}
break;
case V_285 :
case V_286 :
F_126 ( & V_17 ) ;
F_313 (pool, pi) {
F_126 ( & V_15 -> V_115 ) ;
if ( V_15 -> V_55 == V_55 )
F_307 ( V_15 ) ;
else if ( V_15 -> V_55 < 0 )
F_309 ( V_15 , V_55 ) ;
F_128 ( & V_15 -> V_115 ) ;
}
F_144 (wq, &workqueues, list)
F_281 ( V_24 , V_55 , true ) ;
F_128 ( & V_17 ) ;
break;
}
return V_287 ;
}
static int F_314 ( struct V_277 * V_278 ,
unsigned long V_279 ,
void * V_280 )
{
int V_55 = ( unsigned long ) V_280 ;
struct V_2 V_288 ;
struct V_23 * V_24 ;
switch ( V_279 & ~ V_282 ) {
case V_289 :
F_160 ( & V_288 , F_304 ) ;
F_109 ( V_55 , V_290 , & V_288 ) ;
F_126 ( & V_17 ) ;
F_144 (wq, &workqueues, list)
F_281 ( V_24 , V_55 , false ) ;
F_128 ( & V_17 ) ;
F_180 ( & V_288 ) ;
F_18 ( & V_288 ) ;
break;
}
return V_287 ;
}
static void F_315 ( struct V_2 * V_6 )
{
struct V_291 * V_292 = F_158 ( V_6 , struct V_291 , V_6 ) ;
V_292 -> V_16 = V_292 -> V_175 ( V_292 -> V_293 ) ;
}
long F_316 ( int V_55 , long (* V_175)( void * ) , void * V_293 )
{
struct V_291 V_292 = { . V_175 = V_175 , . V_293 = V_293 } ;
F_160 ( & V_292 . V_6 , F_315 ) ;
F_191 ( V_55 , & V_292 . V_6 ) ;
F_180 ( & V_292 . V_6 ) ;
F_18 ( & V_292 . V_6 ) ;
return V_292 . V_16 ;
}
void F_317 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
F_9 ( V_227 ) ;
V_227 = true ;
F_144 (wq, &workqueues, list) {
F_126 ( & V_24 -> V_161 ) ;
F_165 (pwq, wq)
F_264 ( V_33 ) ;
F_128 ( & V_24 -> V_161 ) ;
}
F_128 ( & V_17 ) ;
}
bool F_318 ( void )
{
bool V_294 = false ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
F_9 ( ! V_227 ) ;
F_144 (wq, &workqueues, list) {
if ( ! ( V_24 -> V_32 & V_226 ) )
continue;
F_204 () ;
F_165 (pwq, wq) {
F_9 ( V_33 -> V_72 < 0 ) ;
if ( V_33 -> V_72 ) {
V_294 = true ;
F_206 () ;
goto V_163;
}
}
F_206 () ;
}
V_163:
F_128 ( & V_17 ) ;
return V_294 ;
}
void F_319 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
if ( ! V_227 )
goto V_163;
V_227 = false ;
F_144 (wq, &workqueues, list) {
F_126 ( & V_24 -> V_161 ) ;
F_165 (pwq, wq)
F_264 ( V_33 ) ;
F_128 ( & V_24 -> V_161 ) ;
}
V_163:
F_128 ( & V_17 ) ;
}
static void T_5 F_320 ( void )
{
T_10 * V_295 ;
int V_25 , V_55 ;
if ( F_321 () <= 1 )
return;
if ( V_296 ) {
F_322 ( L_20 ) ;
return;
}
V_243 = F_209 ( V_20 ) ;
F_266 ( ! V_243 ) ;
V_295 = F_224 ( V_236 * sizeof( V_295 [ 0 ] ) , V_20 ) ;
F_266 ( ! V_295 ) ;
F_205 (node)
F_266 ( ! F_323 ( & V_295 [ V_25 ] , V_20 ,
F_324 ( V_25 ) ? V_25 : V_213 ) ) ;
F_283 (cpu) {
V_25 = F_106 ( V_55 ) ;
if ( F_10 ( V_25 == V_213 ) ) {
F_174 ( L_21 , V_55 ) ;
return;
}
F_325 ( V_55 , V_295 [ V_25 ] ) ;
}
V_219 = V_295 ;
V_218 = true ;
}
static int T_5 F_326 ( void )
{
int V_297 [ V_298 ] = { 0 , V_299 } ;
int V_267 , V_55 ;
F_10 ( F_327 ( struct V_22 ) < F_327 (long long) ) ;
V_221 = F_328 ( V_22 , V_300 ) ;
F_329 ( F_312 , V_301 ) ;
F_330 ( F_314 , V_302 ) ;
F_320 () ;
F_283 (cpu) {
struct V_14 * V_15 ;
V_267 = 0 ;
F_305 (pool, cpu) {
F_266 ( F_241 ( V_15 ) ) ;
V_15 -> V_55 = V_55 ;
F_233 ( V_15 -> V_116 -> V_117 , F_331 ( V_55 ) ) ;
V_15 -> V_116 -> V_125 = V_297 [ V_267 ++ ] ;
V_15 -> V_25 = F_106 ( V_55 ) ;
F_126 ( & V_17 ) ;
F_266 ( F_21 ( V_15 ) ) ;
F_128 ( & V_17 ) ;
}
}
F_189 (cpu) {
struct V_14 * V_15 ;
F_305 (pool, cpu) {
V_15 -> V_32 &= ~ V_112 ;
F_266 ( ! F_131 ( V_15 ) ) ;
}
}
for ( V_267 = 0 ; V_267 < V_298 ; V_267 ++ ) {
struct V_192 * V_116 ;
F_266 ( ! ( V_116 = F_209 ( V_20 ) ) ) ;
V_116 -> V_125 = V_297 [ V_267 ] ;
V_250 [ V_267 ] = V_116 ;
F_266 ( ! ( V_116 = F_209 ( V_20 ) ) ) ;
V_116 -> V_125 = V_297 [ V_267 ] ;
V_116 -> V_195 = true ;
V_249 [ V_267 ] = V_116 ;
}
V_174 = F_332 ( L_22 , 0 , 0 ) ;
V_290 = F_332 ( L_23 , V_246 , 0 ) ;
V_303 = F_332 ( L_24 , 0 , 0 ) ;
V_304 = F_332 ( L_25 , V_69 ,
V_252 ) ;
V_305 = F_332 ( L_26 ,
V_226 , 0 ) ;
V_306 = F_332 ( L_27 ,
V_259 , 0 ) ;
V_307 = F_332 ( L_28 ,
V_226 | V_259 ,
0 ) ;
F_266 ( ! V_174 || ! V_290 || ! V_303 ||
! V_304 || ! V_305 ||
! V_306 ||
! V_307 ) ;
return 0 ;
}
