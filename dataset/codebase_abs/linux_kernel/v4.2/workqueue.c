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
V_15 -> V_137 = V_50 ;
F_145 ( V_15 ) ;
V_15 -> V_137 = NULL ;
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
static int V_126 ( void * V_138 )
{
struct V_50 * V_50 = V_138 ;
struct V_14 * V_15 = V_50 -> V_15 ;
V_50 -> V_53 -> V_32 |= V_139 ;
V_140:
F_80 ( & V_15 -> V_67 ) ;
if ( F_57 ( V_50 -> V_32 & V_128 ) ) {
F_81 ( & V_15 -> V_67 ) ;
F_9 ( ! F_50 ( & V_50 -> V_52 ) ) ;
V_50 -> V_53 -> V_32 &= ~ V_139 ;
F_150 ( V_50 -> V_53 , L_7 ) ;
F_136 ( & V_15 -> V_124 , V_50 -> V_21 ) ;
F_129 ( V_50 , V_15 ) ;
F_137 ( V_50 ) ;
return 0 ;
}
F_121 ( V_50 ) ;
V_141:
if ( ! F_49 ( V_15 ) )
goto V_142;
if ( F_57 ( ! F_51 ( V_15 ) ) && F_146 ( V_50 ) )
goto V_141;
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
V_142:
F_118 ( V_50 ) ;
F_151 ( V_143 ) ;
F_81 ( & V_15 -> V_67 ) ;
F_152 () ;
goto V_140;
}
static int F_153 ( void * V_144 )
{
struct V_50 * V_132 = V_144 ;
struct V_23 * V_24 = V_132 -> V_145 ;
struct V_62 * V_113 = & V_132 -> V_113 ;
bool V_146 ;
F_135 ( V_58 , V_147 ) ;
V_132 -> V_53 -> V_32 |= V_139 ;
V_148:
F_154 ( V_143 ) ;
V_146 = F_155 () ;
F_80 ( & V_131 ) ;
while ( ! F_50 ( & V_24 -> V_134 ) ) {
struct V_22 * V_33 = F_58 ( & V_24 -> V_134 ,
struct V_22 , V_133 ) ;
struct V_14 * V_15 = V_33 -> V_15 ;
struct V_2 * V_6 , * V_65 ;
F_151 ( V_149 ) ;
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
if ( V_146 ) {
F_151 ( V_149 ) ;
V_132 -> V_53 -> V_32 &= ~ V_139 ;
return 0 ;
}
F_9 ( ! ( V_132 -> V_32 & V_56 ) ) ;
F_152 () ;
goto V_148;
}
static void F_157 ( struct V_2 * V_6 )
{
struct V_150 * V_151 = F_158 ( V_6 , struct V_150 , V_6 ) ;
F_87 ( & V_151 -> V_81 ) ;
}
static void F_159 ( struct V_22 * V_33 ,
struct V_150 * V_151 ,
struct V_2 * V_152 , struct V_50 * V_50 )
{
struct V_62 * V_63 ;
unsigned int V_153 = 0 ;
F_160 ( & V_151 -> V_6 , F_157 ) ;
F_161 ( V_84 , F_7 ( & V_151 -> V_6 ) ) ;
F_162 ( & V_151 -> V_81 ) ;
V_151 -> V_53 = V_58 ;
if ( V_50 )
V_63 = V_50 -> V_113 . V_107 ;
else {
unsigned long * V_154 = F_7 ( V_152 ) ;
V_63 = V_152 -> V_52 . V_107 ;
V_153 = * V_154 & V_66 ;
F_161 ( V_155 , V_154 ) ;
}
F_13 ( & V_151 -> V_6 ) ;
F_98 ( V_33 , & V_151 -> V_6 , V_63 ,
F_27 ( V_74 ) | V_153 ) ;
}
static bool F_163 ( struct V_23 * V_24 ,
int V_78 , int V_98 )
{
bool V_156 = false ;
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
V_156 = true ;
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
return V_156 ;
}
void F_166 ( struct V_23 * V_24 )
{
struct V_157 V_158 = {
. V_159 = F_167 ( V_158 . V_159 ) ,
. V_78 = - 1 ,
. V_81 = F_168 ( V_158 . V_81 ) ,
} ;
int V_160 ;
F_169 ( & V_24 -> V_161 ) ;
F_170 ( & V_24 -> V_161 ) ;
F_126 ( & V_24 -> V_162 ) ;
V_160 = F_29 ( V_24 -> V_98 ) ;
if ( V_160 != V_24 -> V_78 ) {
F_9 ( ! F_50 ( & V_24 -> V_163 ) ) ;
V_158 . V_78 = V_24 -> V_98 ;
V_24 -> V_98 = V_160 ;
if ( ! V_24 -> V_80 ) {
F_9 ( V_24 -> V_78 != V_158 . V_78 ) ;
V_24 -> V_80 = & V_158 ;
if ( ! F_163 ( V_24 , V_24 -> V_78 ,
V_24 -> V_98 ) ) {
V_24 -> V_78 = V_160 ;
V_24 -> V_80 = NULL ;
goto V_164;
}
} else {
F_9 ( V_24 -> V_78 == V_158 . V_78 ) ;
F_99 ( & V_158 . V_159 , & V_24 -> V_165 ) ;
F_163 ( V_24 , - 1 , V_24 -> V_98 ) ;
}
} else {
F_99 ( & V_158 . V_159 , & V_24 -> V_163 ) ;
}
F_128 ( & V_24 -> V_162 ) ;
F_171 ( & V_158 . V_81 ) ;
if ( V_24 -> V_80 != & V_158 )
return;
F_126 ( & V_24 -> V_162 ) ;
if ( V_24 -> V_80 != & V_158 )
goto V_164;
V_24 -> V_80 = NULL ;
F_9 ( ! F_50 ( & V_158 . V_159 ) ) ;
F_9 ( V_24 -> V_78 != V_158 . V_78 ) ;
while ( true ) {
struct V_157 * V_107 , * V_166 ;
F_156 (next, tmp, &wq->flusher_queue, list) {
if ( V_107 -> V_78 != V_24 -> V_78 )
break;
F_94 ( & V_107 -> V_159 ) ;
F_87 ( & V_107 -> V_81 ) ;
}
F_9 ( ! F_50 ( & V_24 -> V_163 ) &&
V_24 -> V_78 != F_29 ( V_24 -> V_98 ) ) ;
V_24 -> V_78 = F_29 ( V_24 -> V_78 ) ;
if ( ! F_50 ( & V_24 -> V_163 ) ) {
F_144 (tmp, &wq->flusher_overflow, list)
V_166 -> V_78 = V_24 -> V_98 ;
V_24 -> V_98 = F_29 ( V_24 -> V_98 ) ;
F_172 ( & V_24 -> V_163 ,
& V_24 -> V_165 ) ;
F_163 ( V_24 , - 1 , V_24 -> V_98 ) ;
}
if ( F_50 ( & V_24 -> V_165 ) ) {
F_9 ( V_24 -> V_78 != V_24 -> V_98 ) ;
break;
}
F_9 ( V_24 -> V_78 == V_24 -> V_98 ) ;
F_9 ( V_24 -> V_78 != V_107 -> V_78 ) ;
F_94 ( & V_107 -> V_159 ) ;
V_24 -> V_80 = V_107 ;
if ( F_163 ( V_24 , V_24 -> V_78 , - 1 ) )
break;
V_24 -> V_80 = NULL ;
}
V_164:
F_128 ( & V_24 -> V_162 ) ;
}
void F_173 ( struct V_23 * V_24 )
{
unsigned int V_167 = 0 ;
struct V_22 * V_33 ;
F_126 ( & V_24 -> V_162 ) ;
if ( ! V_24 -> V_168 ++ )
V_24 -> V_32 |= V_93 ;
F_128 ( & V_24 -> V_162 ) ;
V_169:
F_166 ( V_24 ) ;
F_126 ( & V_24 -> V_162 ) ;
F_165 (pwq, wq) {
bool V_170 ;
F_80 ( & V_33 -> V_15 -> V_67 ) ;
V_170 = ! V_33 -> V_72 && F_50 ( & V_33 -> V_73 ) ;
F_81 ( & V_33 -> V_15 -> V_67 ) ;
if ( V_170 )
continue;
if ( ++ V_167 == 10 ||
( V_167 % 100 == 0 && V_167 <= 1000 ) )
F_174 ( L_8 ,
V_24 -> V_97 , V_167 ) ;
F_128 ( & V_24 -> V_162 ) ;
goto V_169;
}
if ( ! -- V_24 -> V_168 )
V_24 -> V_32 &= ~ V_93 ;
F_128 ( & V_24 -> V_162 ) ;
}
static bool F_175 ( struct V_2 * V_6 , struct V_150 * V_151 )
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
goto V_171;
} else {
V_50 = F_71 ( V_15 , V_6 ) ;
if ( ! V_50 )
goto V_171;
V_33 = V_50 -> V_89 ;
}
F_159 ( V_33 , V_151 , V_6 , V_50 ) ;
F_81 ( & V_15 -> V_67 ) ;
if ( V_33 -> V_24 -> V_172 == 1 || V_33 -> V_24 -> V_132 )
F_169 ( & V_33 -> V_24 -> V_161 ) ;
else
F_179 ( & V_33 -> V_24 -> V_161 ) ;
F_170 ( & V_33 -> V_24 -> V_161 ) ;
return true ;
V_171:
F_81 ( & V_15 -> V_67 ) ;
return false ;
}
bool F_180 ( struct V_2 * V_6 )
{
struct V_150 V_151 ;
F_169 ( & V_6 -> V_161 ) ;
F_170 ( & V_6 -> V_161 ) ;
if ( F_175 ( V_6 , & V_151 ) ) {
F_171 ( & V_151 . V_81 ) ;
F_18 ( & V_151 . V_6 ) ;
return true ;
} else {
return false ;
}
}
static int F_181 ( T_1 * V_156 , unsigned V_173 , int V_174 , void * V_175 )
{
struct V_176 * V_177 = F_158 ( V_156 , struct V_176 , V_156 ) ;
if ( V_177 -> V_6 != V_175 )
return 0 ;
return F_182 ( V_156 , V_173 , V_174 , V_175 ) ;
}
static bool F_183 ( struct V_2 * V_6 , bool V_82 )
{
static F_184 ( V_178 ) ;
unsigned long V_32 ;
int V_16 ;
do {
V_16 = F_88 ( V_6 , V_82 , & V_32 ) ;
if ( F_57 ( V_16 == - V_87 ) ) {
struct V_176 V_177 ;
F_185 ( & V_177 . V_156 ) ;
V_177 . V_156 . V_3 = F_181 ;
V_177 . V_6 = V_6 ;
F_186 ( & V_178 , & V_177 . V_156 ,
V_179 ) ;
if ( F_46 ( V_6 ) )
F_152 () ;
F_187 ( & V_178 , & V_177 . V_156 ) ;
}
} while ( F_57 ( V_16 < 0 ) );
F_45 ( V_6 ) ;
F_96 ( V_32 ) ;
F_180 ( V_6 ) ;
F_38 ( V_6 ) ;
F_100 () ;
if ( F_188 ( & V_178 ) )
F_189 ( & V_178 , V_180 , 1 , V_6 ) ;
return V_16 ;
}
bool F_3 ( struct V_2 * V_6 )
{
return F_183 ( V_6 , false ) ;
}
bool F_190 ( struct V_12 * V_83 )
{
F_177 () ;
if ( F_191 ( & V_83 -> V_13 ) )
F_103 ( V_83 -> V_55 , V_83 -> V_24 , & V_83 -> V_6 ) ;
F_178 () ;
return F_180 ( & V_83 -> V_6 ) ;
}
bool F_192 ( struct V_12 * V_83 )
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
bool F_193 ( struct V_12 * V_83 )
{
return F_183 ( & V_83 -> V_6 , true ) ;
}
int F_194 ( T_2 V_3 )
{
int V_55 ;
struct V_2 T_3 * V_181 ;
V_181 = F_195 ( struct V_2 ) ;
if ( ! V_181 )
return - V_182 ;
F_196 () ;
F_197 (cpu) {
struct V_2 * V_6 = F_105 ( V_181 , V_55 ) ;
F_198 ( V_6 , V_3 ) ;
F_199 ( V_55 , V_6 ) ;
}
F_197 (cpu)
F_180 ( F_105 ( V_181 , V_55 ) ) ;
F_200 () ;
F_201 ( V_181 ) ;
return 0 ;
}
int F_202 ( T_2 V_183 , struct V_184 * V_185 )
{
if ( ! F_203 () ) {
V_183 ( & V_185 -> V_6 ) ;
return 0 ;
}
F_198 ( & V_185 -> V_6 , V_183 ) ;
F_78 ( & V_185 -> V_6 ) ;
return 1 ;
}
void F_204 ( struct V_186 * V_116 )
{
if ( V_116 ) {
F_205 ( V_116 -> V_117 ) ;
F_137 ( V_116 ) ;
}
}
struct V_186 * F_206 ( T_4 V_187 )
{
struct V_186 * V_116 ;
V_116 = F_207 ( sizeof( * V_116 ) , V_187 ) ;
if ( ! V_116 )
goto V_85;
if ( ! F_208 ( & V_116 -> V_117 , V_187 ) )
goto V_85;
F_209 ( V_116 -> V_117 , V_188 ) ;
return V_116 ;
V_85:
F_204 ( V_116 ) ;
return NULL ;
}
static void F_210 ( struct V_186 * V_189 ,
const struct V_186 * V_190 )
{
V_189 -> V_125 = V_190 -> V_125 ;
F_209 ( V_189 -> V_117 , V_190 -> V_117 ) ;
V_189 -> V_191 = V_190 -> V_191 ;
}
static T_5 F_211 ( const struct V_186 * V_116 )
{
T_5 V_192 = 0 ;
V_192 = F_212 ( V_116 -> V_125 , V_192 ) ;
V_192 = F_213 ( F_214 ( V_116 -> V_117 ) ,
F_215 ( V_193 ) * sizeof( long ) , V_192 ) ;
return V_192 ;
}
static bool F_216 ( const struct V_186 * V_194 ,
const struct V_186 * V_195 )
{
if ( V_194 -> V_125 != V_195 -> V_125 )
return false ;
if ( ! F_217 ( V_194 -> V_117 , V_195 -> V_117 ) )
return false ;
return true ;
}
static int F_218 ( struct V_14 * V_15 )
{
F_219 ( & V_15 -> V_67 ) ;
V_15 -> V_21 = - 1 ;
V_15 -> V_55 = - 1 ;
V_15 -> V_25 = V_196 ;
V_15 -> V_32 |= V_112 ;
F_124 ( & V_15 -> V_43 ) ;
F_124 ( & V_15 -> V_51 ) ;
F_220 ( V_15 -> V_197 ) ;
F_221 ( & V_15 -> V_110 ) ;
V_15 -> V_110 . V_102 = F_139 ;
V_15 -> V_110 . V_31 = ( unsigned long ) V_15 ;
F_222 ( & V_15 -> V_135 , F_143 ,
( unsigned long ) V_15 ) ;
F_223 ( & V_15 -> V_46 ) ;
F_223 ( & V_15 -> V_115 ) ;
F_124 ( & V_15 -> V_119 ) ;
F_224 ( & V_15 -> V_124 ) ;
F_225 ( & V_15 -> V_198 ) ;
V_15 -> V_68 = 1 ;
V_15 -> V_116 = F_206 ( V_20 ) ;
if ( ! V_15 -> V_116 )
return - V_182 ;
return 0 ;
}
static void F_226 ( struct V_199 * V_200 )
{
struct V_23 * V_24 =
F_158 ( V_200 , struct V_23 , V_200 ) ;
if ( ! ( V_24 -> V_32 & V_69 ) )
F_201 ( V_24 -> V_96 ) ;
else
F_204 ( V_24 -> V_201 ) ;
F_137 ( V_24 -> V_132 ) ;
F_137 ( V_24 ) ;
}
static void F_227 ( struct V_199 * V_200 )
{
struct V_14 * V_15 = F_158 ( V_200 , struct V_14 , V_200 ) ;
F_228 ( & V_15 -> V_124 ) ;
F_204 ( V_15 -> V_116 ) ;
F_137 ( V_15 ) ;
}
static void F_229 ( struct V_14 * V_15 )
{
F_230 ( V_121 ) ;
struct V_50 * V_50 ;
F_22 ( & V_17 ) ;
if ( -- V_15 -> V_68 )
return;
if ( F_10 ( ! ( V_15 -> V_55 < 0 ) ) ||
F_10 ( ! F_50 ( & V_15 -> V_43 ) ) )
return;
if ( V_15 -> V_21 >= 0 )
F_231 ( & V_18 , V_15 -> V_21 ) ;
F_232 ( & V_15 -> V_198 ) ;
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
F_191 ( & V_15 -> V_110 ) ;
F_191 ( & V_15 -> V_135 ) ;
F_233 ( & V_15 -> V_200 , F_227 ) ;
}
static struct V_14 * F_234 ( const struct V_186 * V_116 )
{
T_5 V_192 = F_211 ( V_116 ) ;
struct V_14 * V_15 ;
int V_25 ;
F_22 ( & V_17 ) ;
F_72 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_216 ( V_15 -> V_116 , V_116 ) ) {
V_15 -> V_68 ++ ;
return V_15 ;
}
}
V_15 = F_207 ( sizeof( * V_15 ) , V_20 ) ;
if ( ! V_15 || F_218 ( V_15 ) < 0 )
goto V_85;
F_235 ( & V_15 -> V_67 , 1 ) ;
F_210 ( V_15 -> V_116 , V_116 ) ;
V_15 -> V_116 -> V_191 = false ;
if ( V_202 ) {
F_236 (node) {
if ( F_237 ( V_15 -> V_116 -> V_117 ,
V_203 [ V_25 ] ) ) {
V_15 -> V_25 = V_25 ;
break;
}
}
}
if ( F_21 ( V_15 ) < 0 )
goto V_85;
if ( ! F_131 ( V_15 ) )
goto V_85;
F_238 ( V_204 , & V_15 -> V_198 , V_192 ) ;
return V_15 ;
V_85:
if ( V_15 )
F_229 ( V_15 ) ;
return NULL ;
}
static void F_239 ( struct V_199 * V_200 )
{
F_240 ( V_205 ,
F_158 ( V_200 , struct V_22 , V_200 ) ) ;
}
static void F_241 ( struct V_2 * V_6 )
{
struct V_22 * V_33 = F_158 ( V_6 , struct V_22 ,
V_70 ) ;
struct V_23 * V_24 = V_33 -> V_24 ;
struct V_14 * V_15 = V_33 -> V_15 ;
bool V_206 ;
if ( F_9 ( ! ( V_24 -> V_32 & V_69 ) ) )
return;
F_126 ( & V_24 -> V_162 ) ;
F_242 ( & V_33 -> V_207 ) ;
V_206 = F_50 ( & V_24 -> V_208 ) ;
F_128 ( & V_24 -> V_162 ) ;
F_126 ( & V_17 ) ;
F_229 ( V_15 ) ;
F_128 ( & V_17 ) ;
F_233 ( & V_33 -> V_200 , F_239 ) ;
if ( V_206 )
F_233 ( & V_24 -> V_200 , F_226 ) ;
}
static void F_243 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
bool V_209 = V_24 -> V_32 & V_210 ;
F_22 ( & V_24 -> V_162 ) ;
if ( ! V_209 && V_33 -> V_77 == V_24 -> V_172 )
return;
F_80 ( & V_33 -> V_15 -> V_67 ) ;
if ( ! V_209 || ! V_211 ) {
V_33 -> V_77 = V_24 -> V_172 ;
while ( ! F_50 ( & V_33 -> V_73 ) &&
V_33 -> V_72 < V_33 -> V_77 )
F_85 ( V_33 ) ;
F_59 ( V_33 -> V_15 ) ;
} else {
V_33 -> V_77 = 0 ;
}
F_81 ( & V_33 -> V_15 -> V_67 ) ;
}
static void F_244 ( struct V_22 * V_33 , struct V_23 * V_24 ,
struct V_14 * V_15 )
{
F_245 ( ( unsigned long ) V_33 & V_212 ) ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
V_33 -> V_15 = V_15 ;
V_33 -> V_24 = V_24 ;
V_33 -> V_78 = - 1 ;
V_33 -> V_68 = 1 ;
F_124 ( & V_33 -> V_73 ) ;
F_124 ( & V_33 -> V_207 ) ;
F_124 ( & V_33 -> V_133 ) ;
F_198 ( & V_33 -> V_70 , F_241 ) ;
}
static void F_246 ( struct V_22 * V_33 )
{
struct V_23 * V_24 = V_33 -> V_24 ;
F_22 ( & V_24 -> V_162 ) ;
if ( ! F_50 ( & V_33 -> V_207 ) )
return;
V_33 -> V_98 = V_24 -> V_98 ;
F_243 ( V_33 ) ;
F_247 ( & V_33 -> V_207 , & V_24 -> V_208 ) ;
}
static struct V_22 * F_248 ( struct V_23 * V_24 ,
const struct V_186 * V_116 )
{
struct V_14 * V_15 ;
struct V_22 * V_33 ;
F_22 ( & V_17 ) ;
V_15 = F_234 ( V_116 ) ;
if ( ! V_15 )
return NULL ;
V_33 = F_249 ( V_205 , V_20 , V_15 -> V_25 ) ;
if ( ! V_33 ) {
F_229 ( V_15 ) ;
return NULL ;
}
F_244 ( V_33 , V_24 , V_15 ) ;
return V_33 ;
}
static bool F_250 ( const struct V_186 * V_116 , int V_25 ,
int V_213 , T_6 * V_117 )
{
if ( ! V_202 || V_116 -> V_191 )
goto V_214;
F_251 ( V_117 , F_252 ( V_25 ) , V_116 -> V_117 ) ;
if ( V_213 >= 0 )
F_253 ( V_213 , V_117 ) ;
if ( F_254 ( V_117 ) )
goto V_214;
F_251 ( V_117 , V_116 -> V_117 , V_203 [ V_25 ] ) ;
return ! F_217 ( V_117 , V_116 -> V_117 ) ;
V_214:
F_209 ( V_117 , V_116 -> V_117 ) ;
return false ;
}
static struct V_22 * F_255 ( struct V_23 * V_24 ,
int V_25 ,
struct V_22 * V_33 )
{
struct V_22 * V_215 ;
F_22 ( & V_17 ) ;
F_22 ( & V_24 -> V_162 ) ;
F_246 ( V_33 ) ;
V_215 = F_256 ( V_24 -> V_26 [ V_25 ] ) ;
F_257 ( V_24 -> V_26 [ V_25 ] , V_33 ) ;
return V_215 ;
}
static void F_258 ( struct V_216 * V_217 )
{
if ( V_217 ) {
int V_25 ;
F_236 (node)
F_79 ( V_217 -> V_218 [ V_25 ] ) ;
F_79 ( V_217 -> V_219 ) ;
F_204 ( V_217 -> V_116 ) ;
F_137 ( V_217 ) ;
}
}
static struct V_216 *
F_259 ( struct V_23 * V_24 ,
const struct V_186 * V_116 )
{
struct V_216 * V_217 ;
struct V_186 * V_220 , * V_221 ;
int V_25 ;
F_22 ( & V_17 ) ;
V_217 = F_207 ( sizeof( * V_217 ) + V_222 * sizeof( V_217 -> V_218 [ 0 ] ) ,
V_20 ) ;
V_220 = F_206 ( V_20 ) ;
V_221 = F_206 ( V_20 ) ;
if ( ! V_217 || ! V_220 || ! V_221 )
goto V_223;
F_210 ( V_220 , V_116 ) ;
F_251 ( V_220 -> V_117 , V_220 -> V_117 , V_224 ) ;
if ( F_57 ( F_254 ( V_220 -> V_117 ) ) )
F_209 ( V_220 -> V_117 , V_224 ) ;
F_210 ( V_221 , V_220 ) ;
V_217 -> V_219 = F_248 ( V_24 , V_220 ) ;
if ( ! V_217 -> V_219 )
goto V_223;
F_236 (node) {
if ( F_250 ( V_220 , V_25 , - 1 , V_221 -> V_117 ) ) {
V_217 -> V_218 [ V_25 ] = F_248 ( V_24 , V_221 ) ;
if ( ! V_217 -> V_218 [ V_25 ] )
goto V_223;
} else {
V_217 -> V_219 -> V_68 ++ ;
V_217 -> V_218 [ V_25 ] = V_217 -> V_219 ;
}
}
F_210 ( V_220 , V_116 ) ;
F_251 ( V_220 -> V_117 , V_220 -> V_117 , V_188 ) ;
V_217 -> V_116 = V_220 ;
V_217 -> V_24 = V_24 ;
F_204 ( V_221 ) ;
return V_217 ;
V_223:
F_204 ( V_221 ) ;
F_204 ( V_220 ) ;
F_258 ( V_217 ) ;
return NULL ;
}
static void F_260 ( struct V_216 * V_217 )
{
int V_25 ;
F_126 ( & V_217 -> V_24 -> V_162 ) ;
F_210 ( V_217 -> V_24 -> V_201 , V_217 -> V_116 ) ;
F_236 (node)
V_217 -> V_218 [ V_25 ] = F_255 ( V_217 -> V_24 , V_25 ,
V_217 -> V_218 [ V_25 ] ) ;
F_246 ( V_217 -> V_219 ) ;
F_261 ( V_217 -> V_24 -> V_219 , V_217 -> V_219 ) ;
F_128 ( & V_217 -> V_24 -> V_162 ) ;
}
static void F_262 ( void )
{
F_196 () ;
F_126 ( & V_17 ) ;
}
static void F_263 ( void )
{
F_128 ( & V_17 ) ;
F_200 () ;
}
static int F_264 ( struct V_23 * V_24 ,
const struct V_186 * V_116 )
{
struct V_216 * V_217 ;
int V_16 = - V_182 ;
if ( F_10 ( ! ( V_24 -> V_32 & V_69 ) ) )
return - V_225 ;
if ( F_10 ( ( V_24 -> V_32 & V_226 ) && ! F_50 ( & V_24 -> V_208 ) ) )
return - V_225 ;
V_217 = F_259 ( V_24 , V_116 ) ;
if ( V_217 ) {
F_260 ( V_217 ) ;
V_16 = 0 ;
}
F_258 ( V_217 ) ;
return V_16 ;
}
int F_265 ( struct V_23 * V_24 ,
const struct V_186 * V_116 )
{
int V_16 ;
F_262 () ;
V_16 = F_264 ( V_24 , V_116 ) ;
F_263 () ;
return V_16 ;
}
static void F_266 ( struct V_23 * V_24 , int V_55 ,
bool V_227 )
{
int V_25 = F_106 ( V_55 ) ;
int V_228 = V_227 ? - 1 : V_55 ;
struct V_22 * V_215 = NULL , * V_33 ;
struct V_186 * V_229 ;
T_6 * V_117 ;
F_22 ( & V_17 ) ;
if ( ! V_202 || ! ( V_24 -> V_32 & V_69 ) ||
V_24 -> V_201 -> V_191 )
return;
V_229 = V_230 ;
V_117 = V_229 -> V_117 ;
F_210 ( V_229 , V_24 -> V_201 ) ;
V_33 = F_24 ( V_24 , V_25 ) ;
if ( F_250 ( V_24 -> V_219 -> V_15 -> V_116 , V_25 , V_228 , V_117 ) ) {
if ( F_217 ( V_117 , V_33 -> V_15 -> V_116 -> V_117 ) )
return;
} else {
goto V_231;
}
V_33 = F_248 ( V_24 , V_229 ) ;
if ( ! V_33 ) {
F_174 ( L_9 ,
V_24 -> V_97 ) ;
goto V_231;
}
F_126 ( & V_24 -> V_162 ) ;
V_215 = F_255 ( V_24 , V_25 , V_33 ) ;
goto V_164;
V_231:
F_126 ( & V_24 -> V_162 ) ;
F_80 ( & V_24 -> V_219 -> V_15 -> V_67 ) ;
F_76 ( V_24 -> V_219 ) ;
F_81 ( & V_24 -> V_219 -> V_15 -> V_67 ) ;
V_215 = F_255 ( V_24 , V_25 , V_24 -> V_219 ) ;
V_164:
F_128 ( & V_24 -> V_162 ) ;
F_79 ( V_215 ) ;
}
static int F_267 ( struct V_23 * V_24 )
{
bool V_232 = V_24 -> V_32 & V_233 ;
int V_55 , V_16 ;
if ( ! ( V_24 -> V_32 & V_69 ) ) {
V_24 -> V_96 = F_195 ( struct V_22 ) ;
if ( ! V_24 -> V_96 )
return - V_182 ;
F_268 (cpu) {
struct V_22 * V_33 =
F_105 ( V_24 -> V_96 , V_55 ) ;
struct V_14 * V_234 =
F_269 ( V_235 , V_55 ) ;
F_244 ( V_33 , V_24 , & V_234 [ V_232 ] ) ;
F_126 ( & V_24 -> V_162 ) ;
F_246 ( V_33 ) ;
F_128 ( & V_24 -> V_162 ) ;
}
return 0 ;
} else if ( V_24 -> V_32 & V_226 ) {
V_16 = F_265 ( V_24 , V_236 [ V_232 ] ) ;
F_270 ( ! V_16 && ( V_24 -> V_208 . V_107 != & V_24 -> V_219 -> V_207 ||
V_24 -> V_208 . V_130 != & V_24 -> V_219 -> V_207 ) ,
L_10 , V_24 -> V_97 ) ;
return V_16 ;
} else {
return F_265 ( V_24 , V_237 [ V_232 ] ) ;
}
}
static int F_271 ( int V_77 , unsigned int V_32 ,
const char * V_97 )
{
int V_238 = V_32 & V_69 ? V_239 : V_240 ;
if ( V_77 < 1 || V_77 > V_238 )
F_174 ( L_11 ,
V_77 , V_97 , 1 , V_238 ) ;
return F_272 ( V_77 , 1 , V_238 ) ;
}
struct V_23 * F_273 ( const char * V_241 ,
unsigned int V_32 ,
int V_77 ,
struct V_242 * V_175 ,
const char * V_243 , ... )
{
T_7 V_244 = 0 ;
T_8 args ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
if ( ( V_32 & V_245 ) && V_246 )
V_32 |= V_69 ;
if ( V_32 & V_69 )
V_244 = V_222 * sizeof( V_24 -> V_26 [ 0 ] ) ;
V_24 = F_207 ( sizeof( * V_24 ) + V_244 , V_20 ) ;
if ( ! V_24 )
return NULL ;
if ( V_32 & V_69 ) {
V_24 -> V_201 = F_206 ( V_20 ) ;
if ( ! V_24 -> V_201 )
goto V_247;
}
va_start ( args , V_243 ) ;
vsnprintf ( V_24 -> V_97 , sizeof( V_24 -> V_97 ) , V_241 , args ) ;
va_end ( args ) ;
V_77 = V_77 ? : V_248 ;
V_77 = F_271 ( V_77 , V_32 , V_24 -> V_97 ) ;
V_24 -> V_32 = V_32 ;
V_24 -> V_172 = V_77 ;
F_223 ( & V_24 -> V_162 ) ;
F_164 ( & V_24 -> V_79 , 0 ) ;
F_124 ( & V_24 -> V_208 ) ;
F_124 ( & V_24 -> V_165 ) ;
F_124 ( & V_24 -> V_163 ) ;
F_124 ( & V_24 -> V_134 ) ;
F_274 ( & V_24 -> V_161 , V_243 , V_175 , 0 ) ;
F_124 ( & V_24 -> V_159 ) ;
if ( F_267 ( V_24 ) < 0 )
goto V_247;
if ( V_32 & V_249 ) {
struct V_50 * V_132 ;
V_132 = F_122 ( V_196 ) ;
if ( ! V_132 )
goto V_250;
V_132 -> V_145 = V_24 ;
V_132 -> V_53 = F_275 ( F_153 , V_132 , L_12 ,
V_24 -> V_97 ) ;
if ( F_134 ( V_132 -> V_53 ) ) {
F_137 ( V_132 ) ;
goto V_250;
}
V_24 -> V_132 = V_132 ;
V_132 -> V_53 -> V_32 |= V_127 ;
F_61 ( V_132 -> V_53 ) ;
}
if ( ( V_24 -> V_32 & V_251 ) && F_276 ( V_24 ) )
goto V_250;
F_126 ( & V_17 ) ;
F_126 ( & V_24 -> V_162 ) ;
F_165 (pwq, wq)
F_243 ( V_33 ) ;
F_128 ( & V_24 -> V_162 ) ;
F_277 ( & V_24 -> V_159 , & V_252 ) ;
F_128 ( & V_17 ) ;
return V_24 ;
V_247:
F_204 ( V_24 -> V_201 ) ;
F_137 ( V_24 ) ;
return NULL ;
V_250:
F_278 ( V_24 ) ;
return NULL ;
}
void F_278 ( struct V_23 * V_24 )
{
struct V_22 * V_33 ;
int V_25 ;
F_173 ( V_24 ) ;
F_126 ( & V_24 -> V_162 ) ;
F_165 (pwq, wq) {
int V_253 ;
for ( V_253 = 0 ; V_253 < V_30 ; V_253 ++ ) {
if ( F_10 ( V_33 -> V_76 [ V_253 ] ) ) {
F_128 ( & V_24 -> V_162 ) ;
return;
}
}
if ( F_10 ( ( V_33 != V_24 -> V_219 ) && ( V_33 -> V_68 > 1 ) ) ||
F_10 ( V_33 -> V_72 ) ||
F_10 ( ! F_50 ( & V_33 -> V_73 ) ) ) {
F_128 ( & V_24 -> V_162 ) ;
return;
}
}
F_128 ( & V_24 -> V_162 ) ;
F_126 ( & V_17 ) ;
F_242 ( & V_24 -> V_159 ) ;
F_128 ( & V_17 ) ;
F_279 ( V_24 ) ;
if ( V_24 -> V_132 )
F_280 ( V_24 -> V_132 -> V_53 ) ;
if ( ! ( V_24 -> V_32 & V_69 ) ) {
F_233 ( & V_24 -> V_200 , F_226 ) ;
} else {
F_236 (node) {
V_33 = F_256 ( V_24 -> V_26 [ V_25 ] ) ;
F_281 ( V_24 -> V_26 [ V_25 ] , NULL ) ;
F_79 ( V_33 ) ;
}
V_33 = V_24 -> V_219 ;
V_24 -> V_219 = NULL ;
F_79 ( V_33 ) ;
}
}
void F_282 ( struct V_23 * V_24 , int V_77 )
{
struct V_22 * V_33 ;
if ( F_10 ( V_24 -> V_32 & V_226 ) )
return;
V_77 = F_271 ( V_77 , V_24 -> V_32 , V_24 -> V_97 ) ;
F_126 ( & V_24 -> V_162 ) ;
V_24 -> V_172 = V_77 ;
F_165 (pwq, wq)
F_243 ( V_33 ) ;
F_128 ( & V_24 -> V_162 ) ;
}
bool F_283 ( void )
{
struct V_50 * V_50 = F_102 () ;
return V_50 && V_50 -> V_145 ;
}
bool F_284 ( int V_55 , struct V_23 * V_24 )
{
struct V_22 * V_33 ;
bool V_16 ;
F_285 () ;
if ( V_55 == V_95 )
V_55 = F_286 () ;
if ( ! ( V_24 -> V_32 & V_69 ) )
V_33 = F_105 ( V_24 -> V_96 , V_55 ) ;
else
V_33 = F_24 ( V_24 , F_106 ( V_55 ) ) ;
V_16 = ! F_50 ( & V_33 -> V_73 ) ;
F_287 () ;
return V_16 ;
}
unsigned int F_288 ( struct V_2 * V_6 )
{
struct V_14 * V_15 ;
unsigned long V_32 ;
unsigned int V_16 = 0 ;
if ( F_31 ( V_6 ) )
V_16 |= V_254 ;
F_89 ( V_32 ) ;
V_15 = F_41 ( V_6 ) ;
if ( V_15 ) {
F_93 ( & V_15 -> V_67 ) ;
if ( F_71 ( V_15 , V_6 ) )
V_16 |= V_255 ;
F_95 ( & V_15 -> V_67 ) ;
}
F_96 ( V_32 ) ;
return V_16 ;
}
void F_289 ( const char * V_241 , ... )
{
struct V_50 * V_50 = F_102 () ;
T_8 args ;
if ( V_50 ) {
va_start ( args , V_241 ) ;
vsnprintf ( V_50 -> V_256 , sizeof( V_50 -> V_256 ) , V_241 , args ) ;
va_end ( args ) ;
V_50 -> V_257 = true ;
}
}
void F_290 ( const char * V_258 , struct V_54 * V_53 )
{
T_2 * V_183 = NULL ;
char V_97 [ V_259 ] = { } ;
char V_256 [ V_260 ] = { } ;
struct V_22 * V_33 = NULL ;
struct V_23 * V_24 = NULL ;
bool V_257 = false ;
struct V_50 * V_50 ;
if ( ! ( V_53 -> V_32 & V_139 ) )
return;
V_50 = F_291 ( V_53 ) ;
F_292 ( & V_183 , & V_50 -> V_61 , sizeof( V_183 ) ) ;
F_292 ( & V_33 , & V_50 -> V_89 , sizeof( V_33 ) ) ;
F_292 ( & V_24 , & V_33 -> V_24 , sizeof( V_24 ) ) ;
F_292 ( V_97 , V_24 -> V_97 , sizeof( V_97 ) - 1 ) ;
F_292 ( & V_257 , & V_50 -> V_257 , sizeof( V_257 ) ) ;
if ( V_257 )
F_292 ( V_256 , V_50 -> V_256 , sizeof( V_256 ) - 1 ) ;
if ( V_183 || V_97 [ 0 ] || V_256 [ 0 ] ) {
F_293 ( L_13 , V_258 , V_97 , V_183 ) ;
if ( V_256 [ 0 ] )
F_294 ( L_14 , V_256 ) ;
F_294 ( L_15 ) ;
}
}
static void F_295 ( struct V_14 * V_15 )
{
F_294 ( L_16 , V_193 , V_15 -> V_116 -> V_117 ) ;
if ( V_15 -> V_25 != V_196 )
F_294 ( L_17 , V_15 -> V_25 ) ;
F_294 ( L_18 , V_15 -> V_32 , V_15 -> V_116 -> V_125 ) ;
}
static void F_296 ( bool V_261 , struct V_2 * V_6 )
{
if ( V_6 -> V_3 == F_157 ) {
struct V_150 * V_151 ;
V_151 = F_158 ( V_6 , struct V_150 , V_6 ) ;
F_294 ( L_19 , V_261 ? L_20 : L_4 ,
F_297 ( V_151 -> V_53 ) ) ;
} else {
F_294 ( L_21 , V_261 ? L_20 : L_4 , V_6 -> V_3 ) ;
}
}
static void F_298 ( struct V_22 * V_33 )
{
struct V_14 * V_15 = V_33 -> V_15 ;
struct V_2 * V_6 ;
struct V_50 * V_50 ;
bool V_262 = false , V_263 = false ;
int V_264 ;
F_299 ( L_22 , V_15 -> V_21 ) ;
F_295 ( V_15 ) ;
F_294 ( L_23 , V_33 -> V_72 , V_33 -> V_77 ,
! F_50 ( & V_33 -> V_133 ) ? L_24 : L_4 ) ;
F_300 (pool->busy_hash, bkt, worker, hentry) {
if ( V_50 -> V_89 == V_33 ) {
V_262 = true ;
break;
}
}
if ( V_262 ) {
bool V_261 = false ;
F_299 ( L_25 ) ;
F_300 (pool->busy_hash, bkt, worker, hentry) {
if ( V_50 -> V_89 != V_33 )
continue;
F_294 ( L_26 , V_261 ? L_20 : L_4 ,
F_297 ( V_50 -> V_53 ) ,
V_50 == V_33 -> V_24 -> V_132 ? L_27 : L_4 ,
V_50 -> V_61 ) ;
F_144 (work, &worker->scheduled, entry)
F_296 ( false , V_6 ) ;
V_261 = true ;
}
F_294 ( L_15 ) ;
}
F_144 (work, &pool->worklist, entry) {
if ( F_39 ( V_6 ) == V_33 ) {
V_263 = true ;
break;
}
}
if ( V_263 ) {
bool V_261 = false ;
F_299 ( L_28 ) ;
F_144 (work, &pool->worklist, entry) {
if ( F_39 ( V_6 ) != V_33 )
continue;
F_296 ( V_261 , V_6 ) ;
V_261 = ! ( * F_7 ( V_6 ) & V_66 ) ;
}
F_294 ( L_15 ) ;
}
if ( ! F_50 ( & V_33 -> V_73 ) ) {
bool V_261 = false ;
F_299 ( L_29 ) ;
F_144 (work, &pwq->delayed_works, entry) {
F_296 ( V_261 , V_6 ) ;
V_261 = ! ( * F_7 ( V_6 ) & V_66 ) ;
}
F_294 ( L_15 ) ;
}
}
void F_301 ( void )
{
struct V_23 * V_24 ;
struct V_14 * V_15 ;
unsigned long V_32 ;
int V_265 ;
F_285 () ;
F_299 ( L_30 ) ;
F_302 (wq, &workqueues, list) {
struct V_22 * V_33 ;
bool V_266 = true ;
F_165 (pwq, wq) {
if ( V_33 -> V_72 || ! F_50 ( & V_33 -> V_73 ) ) {
V_266 = false ;
break;
}
}
if ( V_266 )
continue;
F_299 ( L_31 , V_24 -> V_97 , V_24 -> V_32 ) ;
F_165 (pwq, wq) {
F_303 ( & V_33 -> V_15 -> V_67 , V_32 ) ;
if ( V_33 -> V_72 || ! F_50 ( & V_33 -> V_73 ) )
F_298 ( V_33 ) ;
F_304 ( & V_33 -> V_15 -> V_67 , V_32 ) ;
}
}
F_305 (pool, pi) {
struct V_50 * V_50 ;
bool V_267 = true ;
F_303 ( & V_15 -> V_67 , V_32 ) ;
if ( V_15 -> V_48 == V_15 -> V_44 )
goto V_268;
F_299 ( L_32 , V_15 -> V_21 ) ;
F_295 ( V_15 ) ;
F_294 ( L_33 , V_15 -> V_48 ) ;
if ( V_15 -> V_137 )
F_294 ( L_34 ,
F_297 ( V_15 -> V_137 -> V_53 ) ) ;
F_144 (worker, &pool->idle_list, entry) {
F_294 ( L_35 , V_267 ? L_36 : L_4 ,
F_297 ( V_50 -> V_53 ) ) ;
V_267 = false ;
}
F_294 ( L_15 ) ;
V_268:
F_304 ( & V_15 -> V_67 , V_32 ) ;
}
F_287 () ;
}
static void F_306 ( struct V_2 * V_6 )
{
int V_55 = F_286 () ;
struct V_14 * V_15 ;
struct V_50 * V_50 ;
F_307 (pool, cpu) {
F_126 ( & V_15 -> V_115 ) ;
F_80 ( & V_15 -> V_67 ) ;
F_308 (worker, pool)
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
static void F_309 ( struct V_14 * V_15 )
{
struct V_50 * V_50 ;
F_22 ( & V_15 -> V_115 ) ;
F_308 (worker, pool)
F_9 ( F_127 ( V_50 -> V_53 ,
V_15 -> V_116 -> V_117 ) < 0 ) ;
F_80 ( & V_15 -> V_67 ) ;
V_15 -> V_32 &= ~ V_112 ;
F_308 (worker, pool) {
unsigned int V_269 = V_50 -> V_32 ;
if ( V_269 & V_105 )
F_61 ( V_50 -> V_53 ) ;
F_9 ( ! ( V_269 & V_118 ) ) ;
V_269 |= V_122 ;
V_269 &= ~ V_118 ;
F_310 ( V_50 -> V_32 ) = V_269 ;
}
F_81 ( & V_15 -> V_67 ) ;
}
static void F_311 ( struct V_14 * V_15 , int V_55 )
{
static T_6 V_117 ;
struct V_50 * V_50 ;
F_22 ( & V_15 -> V_115 ) ;
if ( ! F_312 ( V_55 , V_15 -> V_116 -> V_117 ) )
return;
F_251 ( & V_117 , V_15 -> V_116 -> V_117 , V_270 ) ;
if ( F_313 ( & V_117 ) != 1 )
return;
F_308 (worker, pool)
F_9 ( F_127 ( V_50 -> V_53 ,
V_15 -> V_116 -> V_117 ) < 0 ) ;
}
static int F_314 ( struct V_271 * V_272 ,
unsigned long V_273 ,
void * V_274 )
{
int V_55 = ( unsigned long ) V_274 ;
struct V_14 * V_15 ;
struct V_23 * V_24 ;
int V_265 ;
switch ( V_273 & ~ V_275 ) {
case V_276 :
F_307 (pool, cpu) {
if ( V_15 -> V_48 )
continue;
if ( ! F_131 ( V_15 ) )
return V_277 ;
}
break;
case V_278 :
case V_279 :
F_126 ( & V_17 ) ;
F_305 (pool, pi) {
F_126 ( & V_15 -> V_115 ) ;
if ( V_15 -> V_55 == V_55 )
F_309 ( V_15 ) ;
else if ( V_15 -> V_55 < 0 )
F_311 ( V_15 , V_55 ) ;
F_128 ( & V_15 -> V_115 ) ;
}
F_144 (wq, &workqueues, list)
F_266 ( V_24 , V_55 , true ) ;
F_128 ( & V_17 ) ;
break;
}
return V_280 ;
}
static int F_315 ( struct V_271 * V_272 ,
unsigned long V_273 ,
void * V_274 )
{
int V_55 = ( unsigned long ) V_274 ;
struct V_2 V_281 ;
struct V_23 * V_24 ;
switch ( V_273 & ~ V_275 ) {
case V_282 :
F_160 ( & V_281 , F_306 ) ;
F_109 ( V_55 , V_283 , & V_281 ) ;
F_126 ( & V_17 ) ;
F_144 (wq, &workqueues, list)
F_266 ( V_24 , V_55 , false ) ;
F_128 ( & V_17 ) ;
F_180 ( & V_281 ) ;
F_18 ( & V_281 ) ;
break;
}
return V_280 ;
}
static void F_316 ( struct V_2 * V_6 )
{
struct V_284 * V_285 = F_158 ( V_6 , struct V_284 , V_6 ) ;
V_285 -> V_16 = V_285 -> V_183 ( V_285 -> V_286 ) ;
}
long F_317 ( int V_55 , long (* V_183)( void * ) , void * V_286 )
{
struct V_284 V_285 = { . V_183 = V_183 , . V_286 = V_286 } ;
F_160 ( & V_285 . V_6 , F_316 ) ;
F_199 ( V_55 , & V_285 . V_6 ) ;
F_180 ( & V_285 . V_6 ) ;
F_18 ( & V_285 . V_6 ) ;
return V_285 . V_16 ;
}
void F_318 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
F_9 ( V_211 ) ;
V_211 = true ;
F_144 (wq, &workqueues, list) {
F_126 ( & V_24 -> V_162 ) ;
F_165 (pwq, wq)
F_243 ( V_33 ) ;
F_128 ( & V_24 -> V_162 ) ;
}
F_128 ( & V_17 ) ;
}
bool F_319 ( void )
{
bool V_287 = false ;
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
F_9 ( ! V_211 ) ;
F_144 (wq, &workqueues, list) {
if ( ! ( V_24 -> V_32 & V_210 ) )
continue;
F_285 () ;
F_165 (pwq, wq) {
F_9 ( V_33 -> V_72 < 0 ) ;
if ( V_33 -> V_72 ) {
V_287 = true ;
F_287 () ;
goto V_164;
}
}
F_287 () ;
}
V_164:
F_128 ( & V_17 ) ;
return V_287 ;
}
void F_320 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_33 ;
F_126 ( & V_17 ) ;
if ( ! V_211 )
goto V_164;
V_211 = false ;
F_144 (wq, &workqueues, list) {
F_126 ( & V_24 -> V_162 ) ;
F_165 (pwq, wq)
F_243 ( V_33 ) ;
F_128 ( & V_24 -> V_162 ) ;
}
V_164:
F_128 ( & V_17 ) ;
}
static int F_321 ( void )
{
F_322 ( V_288 ) ;
int V_16 = 0 ;
struct V_23 * V_24 ;
struct V_216 * V_217 , * V_65 ;
F_22 ( & V_17 ) ;
F_144 (wq, &workqueues, list) {
if ( ! ( V_24 -> V_32 & V_69 ) )
continue;
if ( V_24 -> V_32 & V_226 )
continue;
V_217 = F_259 ( V_24 , V_24 -> V_201 ) ;
if ( ! V_217 ) {
V_16 = - V_182 ;
break;
}
F_99 ( & V_217 -> V_159 , & V_288 ) ;
}
F_156 (ctx, n, &ctxs, list) {
if ( ! V_16 )
F_260 ( V_217 ) ;
F_258 ( V_217 ) ;
}
return V_16 ;
}
int F_323 ( T_9 V_117 )
{
int V_16 = - V_225 ;
T_9 V_289 ;
if ( ! F_324 ( & V_289 , V_20 ) )
return - V_182 ;
F_251 ( V_117 , V_117 , V_188 ) ;
if ( ! F_254 ( V_117 ) ) {
F_262 () ;
F_209 ( V_289 , V_224 ) ;
F_209 ( V_224 , V_117 ) ;
V_16 = F_321 () ;
if ( V_16 < 0 )
F_209 ( V_224 , V_289 ) ;
F_263 () ;
}
F_205 ( V_289 ) ;
return V_16 ;
}
static struct V_23 * F_325 ( struct V_290 * V_291 )
{
struct V_292 * V_293 = F_158 ( V_291 , struct V_292 , V_291 ) ;
return V_293 -> V_24 ;
}
static T_10 F_326 ( struct V_290 * V_291 , struct V_294 * V_295 ,
char * V_296 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
return F_327 ( V_296 , V_297 , L_37 , ( bool ) ! ( V_24 -> V_32 & V_69 ) ) ;
}
static T_10 F_328 ( struct V_290 * V_291 ,
struct V_294 * V_295 , char * V_296 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
return F_327 ( V_296 , V_297 , L_37 , V_24 -> V_172 ) ;
}
static T_10 F_329 ( struct V_290 * V_291 ,
struct V_294 * V_295 , const char * V_296 ,
T_7 V_298 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
int V_299 ;
if ( sscanf ( V_296 , L_38 , & V_299 ) != 1 || V_299 <= 0 )
return - V_225 ;
F_282 ( V_24 , V_299 ) ;
return V_298 ;
}
static T_10 F_330 ( struct V_290 * V_291 ,
struct V_294 * V_295 , char * V_296 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
const char * V_300 = L_4 ;
int V_25 , V_301 = 0 ;
F_285 () ;
F_236 (node) {
V_301 += F_327 ( V_296 + V_301 , V_297 - V_301 ,
L_39 , V_300 , V_25 ,
F_24 ( V_24 , V_25 ) -> V_15 -> V_21 ) ;
V_300 = L_40 ;
}
V_301 += F_327 ( V_296 + V_301 , V_297 - V_301 , L_15 ) ;
F_287 () ;
return V_301 ;
}
static T_10 F_331 ( struct V_290 * V_291 , struct V_294 * V_295 ,
char * V_296 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
int V_301 ;
F_126 ( & V_24 -> V_162 ) ;
V_301 = F_327 ( V_296 , V_297 , L_37 , V_24 -> V_201 -> V_125 ) ;
F_128 ( & V_24 -> V_162 ) ;
return V_301 ;
}
static struct V_186 * F_332 ( struct V_23 * V_24 )
{
struct V_186 * V_116 ;
F_22 ( & V_17 ) ;
V_116 = F_206 ( V_20 ) ;
if ( ! V_116 )
return NULL ;
F_210 ( V_116 , V_24 -> V_201 ) ;
return V_116 ;
}
static T_10 F_333 ( struct V_290 * V_291 , struct V_294 * V_295 ,
const char * V_296 , T_7 V_298 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
struct V_186 * V_116 ;
int V_16 = - V_182 ;
F_262 () ;
V_116 = F_332 ( V_24 ) ;
if ( ! V_116 )
goto V_164;
if ( sscanf ( V_296 , L_38 , & V_116 -> V_125 ) == 1 &&
V_116 -> V_125 >= V_302 && V_116 -> V_125 <= V_303 )
V_16 = F_264 ( V_24 , V_116 ) ;
else
V_16 = - V_225 ;
V_164:
F_263 () ;
F_204 ( V_116 ) ;
return V_16 ? : V_298 ;
}
static T_10 F_334 ( struct V_290 * V_291 ,
struct V_294 * V_295 , char * V_296 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
int V_301 ;
F_126 ( & V_24 -> V_162 ) ;
V_301 = F_327 ( V_296 , V_297 , L_41 ,
F_335 ( V_24 -> V_201 -> V_117 ) ) ;
F_128 ( & V_24 -> V_162 ) ;
return V_301 ;
}
static T_10 F_336 ( struct V_290 * V_291 ,
struct V_294 * V_295 ,
const char * V_296 , T_7 V_298 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
struct V_186 * V_116 ;
int V_16 = - V_182 ;
F_262 () ;
V_116 = F_332 ( V_24 ) ;
if ( ! V_116 )
goto V_164;
V_16 = F_337 ( V_296 , V_116 -> V_117 ) ;
if ( ! V_16 )
V_16 = F_264 ( V_24 , V_116 ) ;
V_164:
F_263 () ;
F_204 ( V_116 ) ;
return V_16 ? : V_298 ;
}
static T_10 F_338 ( struct V_290 * V_291 , struct V_294 * V_295 ,
char * V_296 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
int V_301 ;
F_126 ( & V_24 -> V_162 ) ;
V_301 = F_327 ( V_296 , V_297 , L_37 ,
! V_24 -> V_201 -> V_191 ) ;
F_128 ( & V_24 -> V_162 ) ;
return V_301 ;
}
static T_10 F_339 ( struct V_290 * V_291 , struct V_294 * V_295 ,
const char * V_296 , T_7 V_298 )
{
struct V_23 * V_24 = F_325 ( V_291 ) ;
struct V_186 * V_116 ;
int V_304 , V_16 = - V_182 ;
F_262 () ;
V_116 = F_332 ( V_24 ) ;
if ( ! V_116 )
goto V_164;
V_16 = - V_225 ;
if ( sscanf ( V_296 , L_38 , & V_304 ) == 1 ) {
V_116 -> V_191 = ! V_304 ;
V_16 = F_264 ( V_24 , V_116 ) ;
}
V_164:
F_263 () ;
F_204 ( V_116 ) ;
return V_16 ? : V_298 ;
}
static T_10 F_340 ( struct V_290 * V_291 ,
struct V_294 * V_295 , char * V_296 )
{
int V_301 ;
F_126 ( & V_17 ) ;
V_301 = F_327 ( V_296 , V_297 , L_41 ,
F_335 ( V_224 ) ) ;
F_128 ( & V_17 ) ;
return V_301 ;
}
static T_10 F_341 ( struct V_290 * V_291 ,
struct V_294 * V_295 , const char * V_296 , T_7 V_298 )
{
T_9 V_117 ;
int V_16 ;
if ( ! F_324 ( & V_117 , V_20 ) )
return - V_182 ;
V_16 = F_337 ( V_296 , V_117 ) ;
if ( ! V_16 )
V_16 = F_323 ( V_117 ) ;
F_205 ( V_117 ) ;
return V_16 ? V_16 : V_298 ;
}
static int T_11 F_342 ( void )
{
int V_305 ;
V_305 = F_343 ( & V_306 , NULL ) ;
if ( V_305 )
return V_305 ;
return F_344 ( V_306 . V_307 , & V_308 ) ;
}
static void F_345 ( struct V_290 * V_291 )
{
struct V_292 * V_293 = F_158 ( V_291 , struct V_292 , V_291 ) ;
F_137 ( V_293 ) ;
}
int F_276 ( struct V_23 * V_24 )
{
struct V_292 * V_293 ;
int V_16 ;
if ( F_10 ( V_24 -> V_32 & V_226 ) )
return - V_225 ;
V_24 -> V_293 = V_293 = F_207 ( sizeof( * V_293 ) , V_20 ) ;
if ( ! V_293 )
return - V_182 ;
V_293 -> V_24 = V_24 ;
V_293 -> V_291 . V_309 = & V_306 ;
V_293 -> V_291 . V_310 = V_24 -> V_97 ;
V_293 -> V_291 . V_311 = F_345 ;
F_346 ( & V_293 -> V_291 , true ) ;
V_16 = F_347 ( & V_293 -> V_291 ) ;
if ( V_16 ) {
F_137 ( V_293 ) ;
V_24 -> V_293 = NULL ;
return V_16 ;
}
if ( V_24 -> V_32 & V_69 ) {
struct V_294 * V_295 ;
for ( V_295 = V_312 ; V_295 -> V_295 . V_97 ; V_295 ++ ) {
V_16 = F_344 ( & V_293 -> V_291 , V_295 ) ;
if ( V_16 ) {
F_348 ( & V_293 -> V_291 ) ;
V_24 -> V_293 = NULL ;
return V_16 ;
}
}
}
F_346 ( & V_293 -> V_291 , false ) ;
F_349 ( & V_293 -> V_291 . V_313 , V_314 ) ;
return 0 ;
}
static void F_279 ( struct V_23 * V_24 )
{
struct V_292 * V_293 = V_24 -> V_293 ;
if ( ! V_24 -> V_293 )
return;
V_24 -> V_293 = NULL ;
F_348 ( & V_293 -> V_291 ) ;
}
static void F_279 ( struct V_23 * V_24 ) { }
static void T_11 F_350 ( void )
{
T_9 * V_315 ;
int V_25 , V_55 ;
if ( F_351 () <= 1 )
return;
if ( V_316 ) {
F_299 ( L_42 ) ;
return;
}
V_230 = F_206 ( V_20 ) ;
F_245 ( ! V_230 ) ;
V_315 = F_207 ( V_222 * sizeof( V_315 [ 0 ] ) , V_20 ) ;
F_245 ( ! V_315 ) ;
F_236 (node)
F_245 ( ! F_352 ( & V_315 [ V_25 ] , V_20 ,
F_353 ( V_25 ) ? V_25 : V_196 ) ) ;
F_268 (cpu) {
V_25 = F_106 ( V_55 ) ;
if ( F_10 ( V_25 == V_196 ) ) {
F_174 ( L_43 , V_55 ) ;
return;
}
F_354 ( V_55 , V_315 [ V_25 ] ) ;
}
V_203 = V_315 ;
V_202 = true ;
}
static int T_11 F_355 ( void )
{
int V_317 [ V_318 ] = { 0 , V_319 } ;
int V_253 , V_55 ;
F_10 ( F_356 ( struct V_22 ) < F_356 (long long) ) ;
F_245 ( ! F_208 ( & V_224 , V_20 ) ) ;
F_209 ( V_224 , V_188 ) ;
V_205 = F_357 ( V_22 , V_320 ) ;
F_358 ( F_314 , V_321 ) ;
F_359 ( F_315 , V_322 ) ;
F_350 () ;
F_268 (cpu) {
struct V_14 * V_15 ;
V_253 = 0 ;
F_307 (pool, cpu) {
F_245 ( F_218 ( V_15 ) ) ;
V_15 -> V_55 = V_55 ;
F_209 ( V_15 -> V_116 -> V_117 , F_360 ( V_55 ) ) ;
V_15 -> V_116 -> V_125 = V_317 [ V_253 ++ ] ;
V_15 -> V_25 = F_106 ( V_55 ) ;
F_126 ( & V_17 ) ;
F_245 ( F_21 ( V_15 ) ) ;
F_128 ( & V_17 ) ;
}
}
F_197 (cpu) {
struct V_14 * V_15 ;
F_307 (pool, cpu) {
V_15 -> V_32 &= ~ V_112 ;
F_245 ( ! F_131 ( V_15 ) ) ;
}
}
for ( V_253 = 0 ; V_253 < V_318 ; V_253 ++ ) {
struct V_186 * V_116 ;
F_245 ( ! ( V_116 = F_206 ( V_20 ) ) ) ;
V_116 -> V_125 = V_317 [ V_253 ] ;
V_237 [ V_253 ] = V_116 ;
F_245 ( ! ( V_116 = F_206 ( V_20 ) ) ) ;
V_116 -> V_125 = V_317 [ V_253 ] ;
V_116 -> V_191 = true ;
V_236 [ V_253 ] = V_116 ;
}
V_323 = F_361 ( L_44 , 0 , 0 ) ;
V_283 = F_361 ( L_45 , V_233 , 0 ) ;
V_324 = F_361 ( L_46 , 0 , 0 ) ;
V_325 = F_361 ( L_47 , V_69 ,
V_239 ) ;
V_326 = F_361 ( L_48 ,
V_210 , 0 ) ;
V_327 = F_361 ( L_49 ,
V_245 , 0 ) ;
V_328 = F_361 ( L_50 ,
V_210 | V_245 ,
0 ) ;
F_245 ( ! V_323 || ! V_283 || ! V_324 ||
! V_325 || ! V_326 ||
! V_327 ||
! V_328 ) ;
return 0 ;
}
