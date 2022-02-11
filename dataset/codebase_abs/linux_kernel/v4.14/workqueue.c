static void * F_1 ( void * V_1 )
{
return ( (struct V_2 * ) V_1 ) -> V_3 ;
}
static bool F_2 ( void * V_1 )
{
struct V_2 * V_4 = V_1 ;
return F_3 ( V_5 , F_4 ( V_4 ) ) ;
}
static bool F_5 ( void * V_1 , enum V_6 V_7 )
{
struct V_2 * V_4 = V_1 ;
switch ( V_7 ) {
case V_8 :
F_6 ( V_4 ) ;
F_7 ( V_4 , & V_9 ) ;
return true ;
default:
return false ;
}
}
static bool F_8 ( void * V_1 , enum V_6 V_7 )
{
struct V_2 * V_4 = V_1 ;
switch ( V_7 ) {
case V_8 :
F_6 ( V_4 ) ;
F_9 ( V_4 , & V_9 ) ;
return true ;
default:
return false ;
}
}
static inline void F_10 ( struct V_2 * V_4 )
{
F_11 ( V_4 , & V_9 ) ;
}
static inline void F_12 ( struct V_2 * V_4 )
{
F_13 ( V_4 , & V_9 ) ;
}
void F_14 ( struct V_2 * V_4 , int V_10 )
{
if ( V_10 )
F_15 ( V_4 , & V_9 ) ;
else
F_7 ( V_4 , & V_9 ) ;
}
void F_16 ( struct V_2 * V_4 )
{
F_9 ( V_4 , & V_9 ) ;
}
void F_17 ( struct V_11 * V_4 )
{
F_18 ( & V_4 -> V_12 ) ;
F_9 ( & V_4 -> V_4 , & V_9 ) ;
}
static inline void F_10 ( struct V_2 * V_4 ) { }
static inline void F_12 ( struct V_2 * V_4 ) { }
static int F_19 ( struct V_13 * V_14 )
{
int V_15 ;
F_20 ( & V_16 ) ;
V_15 = F_21 ( & V_17 , V_14 , 0 , V_18 ,
V_19 ) ;
if ( V_15 >= 0 ) {
V_14 -> V_20 = V_15 ;
return 0 ;
}
return V_15 ;
}
static struct V_21 * F_22 ( struct V_22 * V_23 ,
int V_24 )
{
F_23 ( V_23 ) ;
if ( F_24 ( V_24 == V_25 ) )
return V_23 -> V_26 ;
return F_25 ( V_23 -> V_27 [ V_24 ] ) ;
}
static unsigned int F_26 ( int V_28 )
{
return V_28 << V_29 ;
}
static int F_27 ( struct V_2 * V_4 )
{
return ( * F_4 ( V_4 ) >> V_29 ) &
( ( 1 << V_30 ) - 1 ) ;
}
static int F_28 ( int V_28 )
{
return ( V_28 + 1 ) % V_31 ;
}
static inline void F_29 ( struct V_2 * V_4 , unsigned long V_32 ,
unsigned long V_33 )
{
F_30 ( ! F_31 ( V_4 ) ) ;
F_32 ( & V_4 -> V_32 , V_32 | V_33 | F_33 ( V_4 ) ) ;
}
static void F_34 ( struct V_2 * V_4 , struct V_21 * V_34 ,
unsigned long V_35 )
{
F_29 ( V_4 , ( unsigned long ) V_34 ,
V_36 | V_37 | V_35 ) ;
}
static void F_35 ( struct V_2 * V_4 ,
int V_38 )
{
F_29 ( V_4 , ( unsigned long ) V_38 << V_39 ,
V_36 ) ;
}
static void F_36 ( struct V_2 * V_4 ,
int V_38 )
{
F_37 () ;
F_29 ( V_4 , ( unsigned long ) V_38 << V_39 , 0 ) ;
F_38 () ;
}
static void F_39 ( struct V_2 * V_4 )
{
F_37 () ;
F_29 ( V_4 , V_40 , 0 ) ;
}
static struct V_21 * F_40 ( struct V_2 * V_4 )
{
unsigned long V_32 = F_41 ( & V_4 -> V_32 ) ;
if ( V_32 & V_37 )
return ( void * ) ( V_32 & V_41 ) ;
else
return NULL ;
}
static struct V_13 * F_42 ( struct V_2 * V_4 )
{
unsigned long V_32 = F_41 ( & V_4 -> V_32 ) ;
int V_38 ;
F_43 () ;
if ( V_32 & V_37 )
return ( (struct V_21 * )
( V_32 & V_41 ) ) -> V_14 ;
V_38 = V_32 >> V_39 ;
if ( V_38 == V_18 )
return NULL ;
return F_44 ( & V_17 , V_38 ) ;
}
static int F_45 ( struct V_2 * V_4 )
{
unsigned long V_32 = F_41 ( & V_4 -> V_32 ) ;
if ( V_32 & V_37 )
return ( (struct V_21 * )
( V_32 & V_41 ) ) -> V_14 -> V_20 ;
return V_32 >> V_39 ;
}
static void F_46 ( struct V_2 * V_4 )
{
unsigned long V_38 = F_45 ( V_4 ) ;
V_38 <<= V_39 ;
F_29 ( V_4 , V_38 | V_42 , V_36 ) ;
}
static bool F_47 ( struct V_2 * V_4 )
{
unsigned long V_32 = F_41 ( & V_4 -> V_32 ) ;
return ! ( V_32 & V_37 ) && ( V_32 & V_42 ) ;
}
static bool F_48 ( struct V_13 * V_14 )
{
return ! F_49 ( & V_14 -> V_43 ) ;
}
static bool F_50 ( struct V_13 * V_14 )
{
return ! F_51 ( & V_14 -> V_44 ) && F_48 ( V_14 ) ;
}
static bool F_52 ( struct V_13 * V_14 )
{
return V_14 -> V_45 ;
}
static bool F_53 ( struct V_13 * V_14 )
{
return ! F_51 ( & V_14 -> V_44 ) &&
F_49 ( & V_14 -> V_43 ) <= 1 ;
}
static bool F_54 ( struct V_13 * V_14 )
{
return F_50 ( V_14 ) && ! F_52 ( V_14 ) ;
}
static bool F_55 ( struct V_13 * V_14 )
{
bool V_46 = V_14 -> V_33 & V_47 ;
int V_45 = V_14 -> V_45 + V_46 ;
int V_48 = V_14 -> V_49 - V_45 ;
return V_45 > 2 && ( V_45 - 2 ) * V_50 >= V_48 ;
}
static struct V_51 * F_56 ( struct V_13 * V_14 )
{
if ( F_24 ( F_51 ( & V_14 -> V_52 ) ) )
return NULL ;
return F_57 ( & V_14 -> V_52 , struct V_51 , V_53 ) ;
}
static void F_58 ( struct V_13 * V_14 )
{
struct V_51 * V_51 = F_56 ( V_14 ) ;
if ( F_59 ( V_51 ) )
F_60 ( V_51 -> V_54 ) ;
}
void F_61 ( struct V_55 * V_54 , int V_56 )
{
struct V_51 * V_51 = F_62 ( V_54 ) ;
if ( ! ( V_51 -> V_33 & V_57 ) ) {
F_30 ( V_51 -> V_14 -> V_56 != V_56 ) ;
F_63 ( & V_51 -> V_14 -> V_43 ) ;
}
}
struct V_55 * F_64 ( struct V_55 * V_54 )
{
struct V_51 * V_51 = F_62 ( V_54 ) , * V_58 = NULL ;
struct V_13 * V_14 ;
if ( V_51 -> V_33 & V_57 )
return NULL ;
V_14 = V_51 -> V_14 ;
if ( F_30 ( V_14 -> V_56 != F_65 () ) )
return NULL ;
if ( F_66 ( & V_14 -> V_43 ) &&
! F_51 ( & V_14 -> V_44 ) )
V_58 = F_56 ( V_14 ) ;
return V_58 ? V_58 -> V_54 : NULL ;
}
static inline void F_67 ( struct V_51 * V_51 , unsigned int V_33 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
F_30 ( V_51 -> V_54 != V_59 ) ;
if ( ( V_33 & V_57 ) &&
! ( V_51 -> V_33 & V_57 ) ) {
F_68 ( & V_14 -> V_43 ) ;
}
V_51 -> V_33 |= V_33 ;
}
static inline void F_69 ( struct V_51 * V_51 , unsigned int V_33 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
unsigned int V_60 = V_51 -> V_33 ;
F_30 ( V_51 -> V_54 != V_59 ) ;
V_51 -> V_33 &= ~ V_33 ;
if ( ( V_33 & V_57 ) && ( V_60 & V_57 ) )
if ( ! ( V_51 -> V_33 & V_57 ) )
F_63 ( & V_14 -> V_43 ) ;
}
static struct V_51 * F_70 ( struct V_13 * V_14 ,
struct V_2 * V_4 )
{
struct V_51 * V_51 ;
F_71 (pool->busy_hash, worker, hentry,
(unsigned long)work)
if ( V_51 -> V_61 == V_4 &&
V_51 -> V_62 == V_4 -> V_3 )
return V_51 ;
return NULL ;
}
static void F_72 ( struct V_2 * V_4 , struct V_63 * V_64 ,
struct V_2 * * V_65 )
{
struct V_2 * V_66 ;
F_73 (work, n, NULL, entry) {
F_74 ( & V_4 -> V_53 , V_64 ) ;
if ( ! ( * F_4 ( V_4 ) & V_67 ) )
break;
}
if ( V_65 )
* V_65 = V_66 ;
}
static void F_75 ( struct V_21 * V_34 )
{
F_20 ( & V_34 -> V_14 -> V_68 ) ;
F_30 ( V_34 -> V_69 <= 0 ) ;
V_34 -> V_69 ++ ;
}
static void F_76 ( struct V_21 * V_34 )
{
F_20 ( & V_34 -> V_14 -> V_68 ) ;
if ( F_59 ( -- V_34 -> V_69 ) )
return;
if ( F_30 ( ! ( V_34 -> V_23 -> V_33 & V_70 ) ) )
return;
F_77 ( & V_34 -> V_71 ) ;
}
static void F_78 ( struct V_21 * V_34 )
{
if ( V_34 ) {
F_79 ( & V_34 -> V_14 -> V_68 ) ;
F_76 ( V_34 ) ;
F_80 ( & V_34 -> V_14 -> V_68 ) ;
}
}
static void F_81 ( struct V_2 * V_4 )
{
struct V_21 * V_34 = F_40 ( V_4 ) ;
F_82 ( V_4 ) ;
if ( F_51 ( & V_34 -> V_14 -> V_44 ) )
V_34 -> V_14 -> V_72 = V_73 ;
F_72 ( V_4 , & V_34 -> V_14 -> V_44 , NULL ) ;
F_83 ( V_74 , F_4 ( V_4 ) ) ;
V_34 -> V_75 ++ ;
}
static void F_84 ( struct V_21 * V_34 )
{
struct V_2 * V_4 = F_57 ( & V_34 -> V_76 ,
struct V_2 , V_53 ) ;
F_81 ( V_4 ) ;
}
static void F_85 ( struct V_21 * V_34 , int V_28 )
{
if ( V_28 == V_77 )
goto V_78;
V_34 -> V_79 [ V_28 ] -- ;
V_34 -> V_75 -- ;
if ( ! F_51 ( & V_34 -> V_76 ) ) {
if ( V_34 -> V_75 < V_34 -> V_80 )
F_84 ( V_34 ) ;
}
if ( F_59 ( V_34 -> V_81 != V_28 ) )
goto V_78;
if ( V_34 -> V_79 [ V_28 ] )
goto V_78;
V_34 -> V_81 = - 1 ;
if ( F_66 ( & V_34 -> V_23 -> V_82 ) )
F_86 ( & V_34 -> V_23 -> V_83 -> V_84 ) ;
V_78:
F_76 ( V_34 ) ;
}
static int F_87 ( struct V_2 * V_4 , bool V_85 ,
unsigned long * V_33 )
{
struct V_13 * V_14 ;
struct V_21 * V_34 ;
F_88 ( * V_33 ) ;
if ( V_85 ) {
struct V_11 * V_86 = F_89 ( V_4 ) ;
if ( F_59 ( F_90 ( & V_86 -> V_12 ) ) )
return 1 ;
}
if ( ! F_91 ( V_87 , F_4 ( V_4 ) ) )
return 0 ;
V_14 = F_42 ( V_4 ) ;
if ( ! V_14 )
goto V_88;
F_92 ( & V_14 -> V_68 ) ;
V_34 = F_40 ( V_4 ) ;
if ( V_34 && V_34 -> V_14 == V_14 ) {
F_12 ( V_4 ) ;
if ( * F_4 ( V_4 ) & V_89 )
F_81 ( V_4 ) ;
F_93 ( & V_4 -> V_53 ) ;
F_85 ( V_34 , F_27 ( V_4 ) ) ;
F_35 ( V_4 , V_14 -> V_20 ) ;
F_94 ( & V_14 -> V_68 ) ;
return 1 ;
}
F_94 ( & V_14 -> V_68 ) ;
V_88:
F_95 ( * V_33 ) ;
if ( F_47 ( V_4 ) )
return - V_90 ;
F_96 () ;
return - V_91 ;
}
static void F_97 ( struct V_21 * V_34 , struct V_2 * V_4 ,
struct V_63 * V_64 , unsigned int V_35 )
{
struct V_13 * V_14 = V_34 -> V_14 ;
F_34 ( V_4 , V_34 , V_35 ) ;
F_98 ( & V_4 -> V_53 , V_64 ) ;
F_75 ( V_34 ) ;
F_38 () ;
if ( F_48 ( V_14 ) )
F_58 ( V_14 ) ;
}
static bool F_99 ( struct V_22 * V_23 )
{
struct V_51 * V_51 ;
V_51 = F_100 () ;
return V_51 && V_51 -> V_92 -> V_23 == V_23 ;
}
static int F_101 ( int V_56 )
{
static bool V_93 ;
int V_94 ;
if ( F_59 ( ! V_95 ) ) {
if ( F_102 ( V_56 , V_96 ) )
return V_56 ;
} else if ( ! V_93 ) {
F_103 ( L_1 ) ;
V_93 = true ;
}
if ( F_104 ( V_96 ) )
return V_56 ;
V_94 = F_105 ( V_97 ) ;
V_94 = F_106 ( V_94 , V_96 , V_98 ) ;
if ( F_24 ( V_94 >= V_99 ) ) {
V_94 = F_107 ( V_96 , V_98 ) ;
if ( F_24 ( V_94 >= V_99 ) )
return V_56 ;
}
F_108 ( V_97 , V_94 ) ;
return V_94 ;
}
static void F_109 ( int V_56 , struct V_22 * V_23 ,
struct V_2 * V_4 )
{
struct V_21 * V_34 ;
struct V_13 * V_100 ;
struct V_63 * V_44 ;
unsigned int V_101 ;
unsigned int V_102 = V_56 ;
F_30 ( ! F_110 () ) ;
F_10 ( V_4 ) ;
if ( F_24 ( V_23 -> V_33 & V_103 ) &&
F_30 ( ! F_99 ( V_23 ) ) )
return;
V_104:
if ( V_102 == V_105 )
V_56 = F_101 ( F_65 () ) ;
if ( ! ( V_23 -> V_33 & V_70 ) )
V_34 = F_111 ( V_23 -> V_106 , V_56 ) ;
else
V_34 = F_22 ( V_23 , F_112 ( V_56 ) ) ;
V_100 = F_42 ( V_4 ) ;
if ( V_100 && V_100 != V_34 -> V_14 ) {
struct V_51 * V_51 ;
F_92 ( & V_100 -> V_68 ) ;
V_51 = F_70 ( V_100 , V_4 ) ;
if ( V_51 && V_51 -> V_92 -> V_23 == V_23 ) {
V_34 = V_51 -> V_92 ;
} else {
F_94 ( & V_100 -> V_68 ) ;
F_92 ( & V_34 -> V_14 -> V_68 ) ;
}
} else {
F_92 ( & V_34 -> V_14 -> V_68 ) ;
}
if ( F_24 ( ! V_34 -> V_69 ) ) {
if ( V_23 -> V_33 & V_70 ) {
F_94 ( & V_34 -> V_14 -> V_68 ) ;
F_96 () ;
goto V_104;
}
F_113 ( true , L_2 ,
V_23 -> V_107 , V_56 ) ;
}
F_114 ( V_102 , V_34 , V_4 ) ;
if ( F_115 ( ! F_51 ( & V_4 -> V_53 ) ) ) {
F_94 ( & V_34 -> V_14 -> V_68 ) ;
return;
}
V_34 -> V_79 [ V_34 -> V_108 ] ++ ;
V_101 = F_26 ( V_34 -> V_108 ) ;
if ( F_59 ( V_34 -> V_75 < V_34 -> V_80 ) ) {
F_82 ( V_4 ) ;
V_34 -> V_75 ++ ;
V_44 = & V_34 -> V_14 -> V_44 ;
if ( F_51 ( V_44 ) )
V_34 -> V_14 -> V_72 = V_73 ;
} else {
V_101 |= V_89 ;
V_44 = & V_34 -> V_76 ;
}
F_97 ( V_34 , V_4 , V_44 , V_101 ) ;
F_94 ( & V_34 -> V_14 -> V_68 ) ;
}
bool F_116 ( int V_56 , struct V_22 * V_23 ,
struct V_2 * V_4 )
{
bool V_15 = false ;
unsigned long V_33 ;
F_88 ( V_33 ) ;
if ( ! F_91 ( V_87 , F_4 ( V_4 ) ) ) {
F_109 ( V_56 , V_23 , V_4 ) ;
V_15 = true ;
}
F_95 ( V_33 ) ;
return V_15 ;
}
void F_117 ( unsigned long V_109 )
{
struct V_11 * V_86 = (struct V_11 * ) V_109 ;
F_109 ( V_86 -> V_56 , V_86 -> V_23 , & V_86 -> V_4 ) ;
}
static void F_118 ( int V_56 , struct V_22 * V_23 ,
struct V_11 * V_86 , unsigned long V_110 )
{
struct V_111 * V_12 = & V_86 -> V_12 ;
struct V_2 * V_4 = & V_86 -> V_4 ;
F_30 ( ! V_23 ) ;
F_30 ( V_12 -> V_112 != F_117 ||
V_12 -> V_32 != ( unsigned long ) V_86 ) ;
F_30 ( F_119 ( V_12 ) ) ;
F_30 ( ! F_51 ( & V_4 -> V_53 ) ) ;
if ( ! V_110 ) {
F_109 ( V_56 , V_23 , & V_86 -> V_4 ) ;
return;
}
V_86 -> V_23 = V_23 ;
V_86 -> V_56 = V_56 ;
V_12 -> V_113 = V_73 + V_110 ;
if ( F_24 ( V_56 != V_105 ) )
F_120 ( V_12 , V_56 ) ;
else
F_121 ( V_12 ) ;
}
bool F_122 ( int V_56 , struct V_22 * V_23 ,
struct V_11 * V_86 , unsigned long V_110 )
{
struct V_2 * V_4 = & V_86 -> V_4 ;
bool V_15 = false ;
unsigned long V_33 ;
F_88 ( V_33 ) ;
if ( ! F_91 ( V_87 , F_4 ( V_4 ) ) ) {
F_118 ( V_56 , V_23 , V_86 , V_110 ) ;
V_15 = true ;
}
F_95 ( V_33 ) ;
return V_15 ;
}
bool F_123 ( int V_56 , struct V_22 * V_23 ,
struct V_11 * V_86 , unsigned long V_110 )
{
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_87 ( & V_86 -> V_4 , true , & V_33 ) ;
} while ( F_24 ( V_15 == - V_91 ) );
if ( F_59 ( V_15 >= 0 ) ) {
F_118 ( V_56 , V_23 , V_86 , V_110 ) ;
F_95 ( V_33 ) ;
}
return V_15 ;
}
static void F_124 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( F_30 ( V_51 -> V_33 & V_114 ) ||
F_30 ( ! F_51 ( & V_51 -> V_53 ) &&
( V_51 -> V_115 . V_116 || V_51 -> V_115 . V_117 ) ) )
return;
V_51 -> V_33 |= V_114 ;
V_14 -> V_45 ++ ;
V_51 -> V_118 = V_73 ;
F_125 ( & V_51 -> V_53 , & V_14 -> V_52 ) ;
if ( F_55 ( V_14 ) && ! F_119 ( & V_14 -> V_119 ) )
F_126 ( & V_14 -> V_119 , V_73 + V_120 ) ;
F_30 ( ! ( V_14 -> V_33 & V_121 ) &&
V_14 -> V_49 == V_14 -> V_45 &&
F_49 ( & V_14 -> V_43 ) ) ;
}
static void F_127 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( F_30 ( ! ( V_51 -> V_33 & V_114 ) ) )
return;
F_69 ( V_51 , V_114 ) ;
V_14 -> V_45 -- ;
F_93 ( & V_51 -> V_53 ) ;
}
static struct V_51 * F_128 ( int V_24 )
{
struct V_51 * V_51 ;
V_51 = F_129 ( sizeof( * V_51 ) , V_19 , V_24 ) ;
if ( V_51 ) {
F_130 ( & V_51 -> V_53 ) ;
F_130 ( & V_51 -> V_122 ) ;
F_130 ( & V_51 -> V_24 ) ;
V_51 -> V_33 = V_123 ;
}
return V_51 ;
}
static void F_131 ( struct V_51 * V_51 ,
struct V_13 * V_14 )
{
F_132 ( & V_14 -> V_124 ) ;
F_133 ( V_51 -> V_54 , V_14 -> V_125 -> V_126 ) ;
if ( V_14 -> V_33 & V_121 )
V_51 -> V_33 |= V_127 ;
F_98 ( & V_51 -> V_24 , & V_14 -> V_128 ) ;
F_134 ( & V_14 -> V_124 ) ;
}
static void F_135 ( struct V_51 * V_51 ,
struct V_13 * V_14 )
{
struct V_129 * V_130 = NULL ;
F_132 ( & V_14 -> V_124 ) ;
F_136 ( & V_51 -> V_24 ) ;
if ( F_51 ( & V_14 -> V_128 ) )
V_130 = V_14 -> V_130 ;
F_134 ( & V_14 -> V_124 ) ;
V_51 -> V_33 &= ~ ( V_127 | V_131 ) ;
if ( V_130 )
F_86 ( V_130 ) ;
}
static struct V_51 * F_137 ( struct V_13 * V_14 )
{
struct V_51 * V_51 = NULL ;
int V_20 = - 1 ;
char V_132 [ 16 ] ;
V_20 = F_138 ( & V_14 -> V_133 , 0 , 0 , V_19 ) ;
if ( V_20 < 0 )
goto V_88;
V_51 = F_128 ( V_14 -> V_24 ) ;
if ( ! V_51 )
goto V_88;
V_51 -> V_14 = V_14 ;
V_51 -> V_20 = V_20 ;
if ( V_14 -> V_56 >= 0 )
snprintf ( V_132 , sizeof( V_132 ) , L_3 , V_14 -> V_56 , V_20 ,
V_14 -> V_125 -> V_134 < 0 ? L_4 : L_5 ) ;
else
snprintf ( V_132 , sizeof( V_132 ) , L_6 , V_14 -> V_20 , V_20 ) ;
V_51 -> V_54 = F_139 ( V_135 , V_51 , V_14 -> V_24 ,
L_7 , V_132 ) ;
if ( F_140 ( V_51 -> V_54 ) )
goto V_88;
F_141 ( V_51 -> V_54 , V_14 -> V_125 -> V_134 ) ;
F_142 ( V_51 -> V_54 , V_14 -> V_125 -> V_126 ) ;
F_131 ( V_51 , V_14 ) ;
F_79 ( & V_14 -> V_68 ) ;
V_51 -> V_14 -> V_49 ++ ;
F_124 ( V_51 ) ;
F_60 ( V_51 -> V_54 ) ;
F_80 ( & V_14 -> V_68 ) ;
return V_51 ;
V_88:
if ( V_20 >= 0 )
F_143 ( & V_14 -> V_133 , V_20 ) ;
F_144 ( V_51 ) ;
return NULL ;
}
static void F_145 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
F_20 ( & V_14 -> V_68 ) ;
if ( F_115 ( V_51 -> V_61 ) ||
F_115 ( ! F_51 ( & V_51 -> V_122 ) ) ||
F_115 ( ! ( V_51 -> V_33 & V_114 ) ) )
return;
V_14 -> V_49 -- ;
V_14 -> V_45 -- ;
F_93 ( & V_51 -> V_53 ) ;
V_51 -> V_33 |= V_136 ;
F_60 ( V_51 -> V_54 ) ;
}
static void F_146 ( unsigned long V_137 )
{
struct V_13 * V_14 = ( void * ) V_137 ;
F_79 ( & V_14 -> V_68 ) ;
while ( F_55 ( V_14 ) ) {
struct V_51 * V_51 ;
unsigned long V_113 ;
V_51 = F_147 ( V_14 -> V_52 . V_138 , struct V_51 , V_53 ) ;
V_113 = V_51 -> V_118 + V_120 ;
if ( F_148 ( V_73 , V_113 ) ) {
F_126 ( & V_14 -> V_119 , V_113 ) ;
break;
}
F_145 ( V_51 ) ;
}
F_80 ( & V_14 -> V_68 ) ;
}
static void F_149 ( struct V_2 * V_4 )
{
struct V_21 * V_34 = F_40 ( V_4 ) ;
struct V_22 * V_23 = V_34 -> V_23 ;
F_20 ( & V_139 ) ;
if ( ! V_23 -> V_140 )
return;
if ( F_51 ( & V_34 -> V_141 ) ) {
F_75 ( V_34 ) ;
F_98 ( & V_34 -> V_141 , & V_23 -> V_142 ) ;
F_60 ( V_23 -> V_140 -> V_54 ) ;
}
}
static void F_150 ( unsigned long V_137 )
{
struct V_13 * V_14 = ( void * ) V_137 ;
struct V_2 * V_4 ;
F_79 ( & V_14 -> V_68 ) ;
F_92 ( & V_139 ) ;
if ( F_54 ( V_14 ) ) {
F_151 (work, &pool->worklist, entry)
F_149 ( V_4 ) ;
}
F_94 ( & V_139 ) ;
F_80 ( & V_14 -> V_68 ) ;
F_126 ( & V_14 -> V_143 , V_73 + V_144 ) ;
}
static void F_152 ( struct V_13 * V_14 )
__releases( &pool->lock
static bool F_153 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( V_14 -> V_33 & V_47 )
return false ;
V_14 -> V_33 |= V_47 ;
V_14 -> V_145 = V_51 ;
F_152 ( V_14 ) ;
V_14 -> V_145 = NULL ;
V_14 -> V_33 &= ~ V_47 ;
F_154 ( & V_146 ) ;
return true ;
}
static void F_155 ( struct V_51 * V_51 , struct V_2 * V_4 )
__releases( &pool->lock
static void F_156 ( struct V_51 * V_51 )
{
while ( ! F_51 ( & V_51 -> V_122 ) ) {
struct V_2 * V_4 = F_57 ( & V_51 -> V_122 ,
struct V_2 , V_53 ) ;
F_155 ( V_51 , V_4 ) ;
}
}
static int V_135 ( void * V_147 )
{
struct V_51 * V_51 = V_147 ;
struct V_13 * V_14 = V_51 -> V_14 ;
V_51 -> V_54 -> V_33 |= V_148 ;
V_149:
F_79 ( & V_14 -> V_68 ) ;
if ( F_24 ( V_51 -> V_33 & V_136 ) ) {
F_80 ( & V_14 -> V_68 ) ;
F_30 ( ! F_51 ( & V_51 -> V_53 ) ) ;
V_51 -> V_54 -> V_33 &= ~ V_148 ;
F_157 ( V_51 -> V_54 , L_8 ) ;
F_143 ( & V_14 -> V_133 , V_51 -> V_20 ) ;
F_135 ( V_51 , V_14 ) ;
F_144 ( V_51 ) ;
return 0 ;
}
F_127 ( V_51 ) ;
V_150:
if ( ! F_50 ( V_14 ) )
goto V_151;
if ( F_24 ( ! F_52 ( V_14 ) ) && F_153 ( V_51 ) )
goto V_150;
F_30 ( ! F_51 ( & V_51 -> V_122 ) ) ;
F_69 ( V_51 , V_123 | V_131 ) ;
do {
struct V_2 * V_4 =
F_57 ( & V_14 -> V_44 ,
struct V_2 , V_53 ) ;
V_14 -> V_72 = V_73 ;
if ( F_59 ( ! ( * F_4 ( V_4 ) & V_67 ) ) ) {
F_155 ( V_51 , V_4 ) ;
if ( F_24 ( ! F_51 ( & V_51 -> V_122 ) ) )
F_156 ( V_51 ) ;
} else {
F_72 ( V_4 , & V_51 -> V_122 , NULL ) ;
F_156 ( V_51 ) ;
}
} while ( F_53 ( V_14 ) );
F_67 ( V_51 , V_123 ) ;
V_151:
F_124 ( V_51 ) ;
F_158 ( V_152 ) ;
F_80 ( & V_14 -> V_68 ) ;
F_159 () ;
goto V_149;
}
static int F_160 ( void * V_153 )
{
struct V_51 * V_140 = V_153 ;
struct V_22 * V_23 = V_140 -> V_154 ;
struct V_63 * V_122 = & V_140 -> V_122 ;
bool V_155 ;
F_141 ( V_59 , V_156 ) ;
V_140 -> V_54 -> V_33 |= V_148 ;
V_157:
F_161 ( V_152 ) ;
V_155 = F_162 () ;
F_79 ( & V_139 ) ;
while ( ! F_51 ( & V_23 -> V_142 ) ) {
struct V_21 * V_34 = F_57 ( & V_23 -> V_142 ,
struct V_21 , V_141 ) ;
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_2 * V_4 , * V_66 ;
bool V_158 = true ;
F_158 ( V_159 ) ;
F_93 ( & V_34 -> V_141 ) ;
F_80 ( & V_139 ) ;
F_131 ( V_140 , V_14 ) ;
F_79 ( & V_14 -> V_68 ) ;
V_140 -> V_14 = V_14 ;
F_30 ( ! F_51 ( V_122 ) ) ;
F_163 (work, n, &pool->worklist, entry) {
if ( F_40 ( V_4 ) == V_34 ) {
if ( V_158 )
V_14 -> V_72 = V_73 ;
F_72 ( V_4 , V_122 , & V_66 ) ;
}
V_158 = false ;
}
if ( ! F_51 ( V_122 ) ) {
F_156 ( V_140 ) ;
if ( F_54 ( V_14 ) ) {
F_92 ( & V_139 ) ;
F_75 ( V_34 ) ;
F_74 ( & V_34 -> V_141 , & V_23 -> V_142 ) ;
F_94 ( & V_139 ) ;
}
}
F_76 ( V_34 ) ;
if ( F_50 ( V_14 ) )
F_58 ( V_14 ) ;
V_140 -> V_14 = NULL ;
F_80 ( & V_14 -> V_68 ) ;
F_135 ( V_140 , V_14 ) ;
F_79 ( & V_139 ) ;
}
F_80 ( & V_139 ) ;
if ( V_155 ) {
F_158 ( V_159 ) ;
V_140 -> V_54 -> V_33 &= ~ V_148 ;
return 0 ;
}
F_30 ( ! ( V_140 -> V_33 & V_57 ) ) ;
F_159 () ;
goto V_157;
}
static void F_164 ( struct V_22 * V_160 ,
struct V_2 * V_161 )
{
T_1 V_162 = V_161 ? V_161 -> V_3 : NULL ;
struct V_51 * V_51 ;
if ( V_160 -> V_33 & V_163 )
return;
V_51 = F_100 () ;
F_113 ( V_59 -> V_33 & V_164 ,
L_9 ,
V_59 -> V_165 , V_59 -> V_166 , V_160 -> V_107 , V_162 ) ;
F_113 ( V_51 && ( ( V_51 -> V_92 -> V_23 -> V_33 &
( V_163 | V_167 ) ) == V_163 ) ,
L_10 ,
V_51 -> V_92 -> V_23 -> V_107 , V_51 -> V_62 ,
V_160 -> V_107 , V_162 ) ;
}
static void F_165 ( struct V_2 * V_4 )
{
struct V_168 * V_169 = F_166 ( V_4 , struct V_168 , V_4 ) ;
F_86 ( & V_169 -> V_84 ) ;
}
static void F_167 ( struct V_21 * V_34 ,
struct V_168 * V_169 ,
struct V_2 * V_170 , struct V_51 * V_51 )
{
struct V_63 * V_64 ;
unsigned int V_171 = 0 ;
F_168 ( & V_169 -> V_4 , F_165 ) ;
F_169 ( V_87 , F_4 ( & V_169 -> V_4 ) ) ;
F_170 ( (struct V_172 * ) & V_169 -> V_84 . V_173 ,
L_11 ,
V_170 -> V_172 . V_174 , 1 ) ;
F_171 ( & V_169 -> V_84 ) ;
V_169 -> V_54 = V_59 ;
if ( V_51 )
V_64 = V_51 -> V_122 . V_116 ;
else {
unsigned long * V_175 = F_4 ( V_170 ) ;
V_64 = V_170 -> V_53 . V_116 ;
V_171 = * V_175 & V_67 ;
F_169 ( V_176 , V_175 ) ;
}
F_10 ( & V_169 -> V_4 ) ;
F_97 ( V_34 , & V_169 -> V_4 , V_64 ,
F_26 ( V_77 ) | V_171 ) ;
}
static bool F_172 ( struct V_22 * V_23 ,
int V_81 , int V_108 )
{
bool V_177 = false ;
struct V_21 * V_34 ;
if ( V_81 >= 0 ) {
F_30 ( F_49 ( & V_23 -> V_82 ) ) ;
F_173 ( & V_23 -> V_82 , 1 ) ;
}
F_174 (pwq, wq) {
struct V_13 * V_14 = V_34 -> V_14 ;
F_79 ( & V_14 -> V_68 ) ;
if ( V_81 >= 0 ) {
F_30 ( V_34 -> V_81 != - 1 ) ;
if ( V_34 -> V_79 [ V_81 ] ) {
V_34 -> V_81 = V_81 ;
F_63 ( & V_23 -> V_82 ) ;
V_177 = true ;
}
}
if ( V_108 >= 0 ) {
F_30 ( V_108 != F_28 ( V_34 -> V_108 ) ) ;
V_34 -> V_108 = V_108 ;
}
F_80 ( & V_14 -> V_68 ) ;
}
if ( V_81 >= 0 && F_66 ( & V_23 -> V_82 ) )
F_86 ( & V_23 -> V_83 -> V_84 ) ;
return V_177 ;
}
void F_175 ( struct V_22 * V_23 )
{
struct V_178 V_179 = {
. V_180 = F_176 ( V_179 . V_180 ) ,
. V_81 = - 1 ,
. V_84 = F_177 ( V_179 . V_84 ) ,
} ;
int V_181 ;
if ( F_115 ( ! V_182 ) )
return;
F_178 ( & V_23 -> V_172 ) ;
F_179 ( & V_23 -> V_172 ) ;
F_132 ( & V_23 -> V_183 ) ;
V_181 = F_28 ( V_23 -> V_108 ) ;
if ( V_181 != V_23 -> V_81 ) {
F_30 ( ! F_51 ( & V_23 -> V_184 ) ) ;
V_179 . V_81 = V_23 -> V_108 ;
V_23 -> V_108 = V_181 ;
if ( ! V_23 -> V_83 ) {
F_30 ( V_23 -> V_81 != V_179 . V_81 ) ;
V_23 -> V_83 = & V_179 ;
if ( ! F_172 ( V_23 , V_23 -> V_81 ,
V_23 -> V_108 ) ) {
V_23 -> V_81 = V_181 ;
V_23 -> V_83 = NULL ;
goto V_185;
}
} else {
F_30 ( V_23 -> V_81 == V_179 . V_81 ) ;
F_98 ( & V_179 . V_180 , & V_23 -> V_186 ) ;
F_172 ( V_23 , - 1 , V_23 -> V_108 ) ;
}
} else {
F_98 ( & V_179 . V_180 , & V_23 -> V_184 ) ;
}
F_164 ( V_23 , NULL ) ;
F_134 ( & V_23 -> V_183 ) ;
F_180 ( & V_179 . V_84 ) ;
if ( V_23 -> V_83 != & V_179 )
return;
F_132 ( & V_23 -> V_183 ) ;
if ( V_23 -> V_83 != & V_179 )
goto V_185;
V_23 -> V_83 = NULL ;
F_30 ( ! F_51 ( & V_179 . V_180 ) ) ;
F_30 ( V_23 -> V_81 != V_179 . V_81 ) ;
while ( true ) {
struct V_178 * V_116 , * V_187 ;
F_163 (next, tmp, &wq->flusher_queue, list) {
if ( V_116 -> V_81 != V_23 -> V_81 )
break;
F_93 ( & V_116 -> V_180 ) ;
F_86 ( & V_116 -> V_84 ) ;
}
F_30 ( ! F_51 ( & V_23 -> V_184 ) &&
V_23 -> V_81 != F_28 ( V_23 -> V_108 ) ) ;
V_23 -> V_81 = F_28 ( V_23 -> V_81 ) ;
if ( ! F_51 ( & V_23 -> V_184 ) ) {
F_151 (tmp, &wq->flusher_overflow, list)
V_187 -> V_81 = V_23 -> V_108 ;
V_23 -> V_108 = F_28 ( V_23 -> V_108 ) ;
F_181 ( & V_23 -> V_184 ,
& V_23 -> V_186 ) ;
F_172 ( V_23 , - 1 , V_23 -> V_108 ) ;
}
if ( F_51 ( & V_23 -> V_186 ) ) {
F_30 ( V_23 -> V_81 != V_23 -> V_108 ) ;
break;
}
F_30 ( V_23 -> V_81 == V_23 -> V_108 ) ;
F_30 ( V_23 -> V_81 != V_116 -> V_81 ) ;
F_93 ( & V_116 -> V_180 ) ;
V_23 -> V_83 = V_116 ;
if ( F_172 ( V_23 , V_23 -> V_81 , - 1 ) )
break;
V_23 -> V_83 = NULL ;
}
V_185:
F_134 ( & V_23 -> V_183 ) ;
}
void F_182 ( struct V_22 * V_23 )
{
unsigned int V_188 = 0 ;
struct V_21 * V_34 ;
F_132 ( & V_23 -> V_183 ) ;
if ( ! V_23 -> V_189 ++ )
V_23 -> V_33 |= V_103 ;
F_134 ( & V_23 -> V_183 ) ;
V_190:
F_175 ( V_23 ) ;
F_132 ( & V_23 -> V_183 ) ;
F_174 (pwq, wq) {
bool V_191 ;
F_79 ( & V_34 -> V_14 -> V_68 ) ;
V_191 = ! V_34 -> V_75 && F_51 ( & V_34 -> V_76 ) ;
F_80 ( & V_34 -> V_14 -> V_68 ) ;
if ( V_191 )
continue;
if ( ++ V_188 == 10 ||
( V_188 % 100 == 0 && V_188 <= 1000 ) )
F_103 ( L_12 ,
V_23 -> V_107 , V_188 ) ;
F_134 ( & V_23 -> V_183 ) ;
goto V_190;
}
if ( ! -- V_23 -> V_189 )
V_23 -> V_33 &= ~ V_103 ;
F_134 ( & V_23 -> V_183 ) ;
}
static bool F_183 ( struct V_2 * V_4 , struct V_168 * V_169 )
{
struct V_51 * V_51 = NULL ;
struct V_13 * V_14 ;
struct V_21 * V_34 ;
F_184 () ;
F_185 () ;
V_14 = F_42 ( V_4 ) ;
if ( ! V_14 ) {
F_186 () ;
return false ;
}
F_92 ( & V_14 -> V_68 ) ;
V_34 = F_40 ( V_4 ) ;
if ( V_34 ) {
if ( F_24 ( V_34 -> V_14 != V_14 ) )
goto V_192;
} else {
V_51 = F_70 ( V_14 , V_4 ) ;
if ( ! V_51 )
goto V_192;
V_34 = V_51 -> V_92 ;
}
F_164 ( V_34 -> V_23 , V_4 ) ;
F_167 ( V_34 , V_169 , V_4 , V_51 ) ;
F_80 ( & V_14 -> V_68 ) ;
if ( V_34 -> V_23 -> V_193 == 1 || V_34 -> V_23 -> V_140 ) {
F_178 ( & V_34 -> V_23 -> V_172 ) ;
F_179 ( & V_34 -> V_23 -> V_172 ) ;
}
return true ;
V_192:
F_80 ( & V_14 -> V_68 ) ;
return false ;
}
bool F_187 ( struct V_2 * V_4 )
{
struct V_168 V_169 ;
if ( F_115 ( ! V_182 ) )
return false ;
F_178 ( & V_4 -> V_172 ) ;
F_179 ( & V_4 -> V_172 ) ;
if ( F_183 ( V_4 , & V_169 ) ) {
F_180 ( & V_169 . V_84 ) ;
F_16 ( & V_169 . V_4 ) ;
return true ;
} else {
return false ;
}
}
static int F_188 ( T_2 * V_177 , unsigned V_194 , int V_195 , void * V_174 )
{
struct V_196 * V_197 = F_166 ( V_177 , struct V_196 , V_177 ) ;
if ( V_197 -> V_4 != V_174 )
return 0 ;
return F_189 ( V_177 , V_194 , V_195 , V_174 ) ;
}
static bool F_190 ( struct V_2 * V_4 , bool V_85 )
{
static F_191 ( V_198 ) ;
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_87 ( V_4 , V_85 , & V_33 ) ;
if ( F_24 ( V_15 == - V_90 ) ) {
struct V_196 V_197 ;
F_192 ( & V_197 . V_177 ) ;
V_197 . V_177 . V_3 = F_188 ;
V_197 . V_4 = V_4 ;
F_193 ( & V_198 , & V_197 . V_177 ,
V_199 ) ;
if ( F_47 ( V_4 ) )
F_159 () ;
F_194 ( & V_198 , & V_197 . V_177 ) ;
}
} while ( F_24 ( V_15 < 0 ) );
F_46 ( V_4 ) ;
F_95 ( V_33 ) ;
if ( V_182 )
F_187 ( V_4 ) ;
F_39 ( V_4 ) ;
F_38 () ;
if ( F_195 ( & V_198 ) )
F_196 ( & V_198 , V_200 , 1 , V_4 ) ;
return V_15 ;
}
bool F_6 ( struct V_2 * V_4 )
{
return F_190 ( V_4 , false ) ;
}
bool F_197 ( struct V_11 * V_86 )
{
F_185 () ;
if ( F_198 ( & V_86 -> V_12 ) )
F_109 ( V_86 -> V_56 , V_86 -> V_23 , & V_86 -> V_4 ) ;
F_186 () ;
return F_187 ( & V_86 -> V_4 ) ;
}
static bool F_199 ( struct V_2 * V_4 , bool V_85 )
{
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_87 ( V_4 , V_85 , & V_33 ) ;
} while ( F_24 ( V_15 == - V_91 ) );
if ( F_24 ( V_15 < 0 ) )
return false ;
F_36 ( V_4 , F_45 ( V_4 ) ) ;
F_95 ( V_33 ) ;
return V_15 ;
}
bool F_200 ( struct V_2 * V_4 )
{
return F_199 ( V_4 , false ) ;
}
bool F_201 ( struct V_11 * V_86 )
{
return F_199 ( & V_86 -> V_4 , true ) ;
}
bool F_202 ( struct V_11 * V_86 )
{
return F_190 ( & V_86 -> V_4 , true ) ;
}
int F_203 ( T_1 V_3 )
{
int V_56 ;
struct V_2 T_3 * V_201 ;
V_201 = F_204 ( struct V_2 ) ;
if ( ! V_201 )
return - V_202 ;
F_205 () ;
F_206 (cpu) {
struct V_2 * V_4 = F_111 ( V_201 , V_56 ) ;
F_207 ( V_4 , V_3 ) ;
F_208 ( V_56 , V_4 ) ;
}
F_206 (cpu)
F_187 ( F_111 ( V_201 , V_56 ) ) ;
F_209 () ;
F_210 ( V_201 ) ;
return 0 ;
}
int F_211 ( T_1 V_203 , struct V_204 * V_205 )
{
if ( ! F_212 () ) {
V_203 ( & V_205 -> V_4 ) ;
return 0 ;
}
F_207 ( & V_205 -> V_4 , V_203 ) ;
F_77 ( & V_205 -> V_4 ) ;
return 1 ;
}
void F_213 ( struct V_206 * V_125 )
{
if ( V_125 ) {
F_214 ( V_125 -> V_126 ) ;
F_144 ( V_125 ) ;
}
}
struct V_206 * F_215 ( T_4 V_207 )
{
struct V_206 * V_125 ;
V_125 = F_216 ( sizeof( * V_125 ) , V_207 ) ;
if ( ! V_125 )
goto V_88;
if ( ! F_217 ( & V_125 -> V_126 , V_207 ) )
goto V_88;
F_218 ( V_125 -> V_126 , V_208 ) ;
return V_125 ;
V_88:
F_213 ( V_125 ) ;
return NULL ;
}
static void F_219 ( struct V_206 * V_209 ,
const struct V_206 * V_210 )
{
V_209 -> V_134 = V_210 -> V_134 ;
F_218 ( V_209 -> V_126 , V_210 -> V_126 ) ;
V_209 -> V_211 = V_210 -> V_211 ;
}
static T_5 F_220 ( const struct V_206 * V_125 )
{
T_5 V_212 = 0 ;
V_212 = F_221 ( V_125 -> V_134 , V_212 ) ;
V_212 = F_222 ( F_223 ( V_125 -> V_126 ) ,
F_224 ( V_213 ) * sizeof( long ) , V_212 ) ;
return V_212 ;
}
static bool F_225 ( const struct V_206 * V_214 ,
const struct V_206 * V_215 )
{
if ( V_214 -> V_134 != V_215 -> V_134 )
return false ;
if ( ! F_226 ( V_214 -> V_126 , V_215 -> V_126 ) )
return false ;
return true ;
}
static int F_227 ( struct V_13 * V_14 )
{
F_228 ( & V_14 -> V_68 ) ;
V_14 -> V_20 = - 1 ;
V_14 -> V_56 = - 1 ;
V_14 -> V_24 = V_25 ;
V_14 -> V_33 |= V_121 ;
V_14 -> V_72 = V_73 ;
F_130 ( & V_14 -> V_44 ) ;
F_130 ( & V_14 -> V_52 ) ;
F_229 ( V_14 -> V_216 ) ;
F_230 ( & V_14 -> V_119 , F_146 ,
( unsigned long ) V_14 ) ;
F_231 ( & V_14 -> V_143 , F_150 ,
( unsigned long ) V_14 ) ;
F_232 ( & V_14 -> V_124 ) ;
F_130 ( & V_14 -> V_128 ) ;
F_233 ( & V_14 -> V_133 ) ;
F_234 ( & V_14 -> V_217 ) ;
V_14 -> V_69 = 1 ;
V_14 -> V_125 = F_215 ( V_19 ) ;
if ( ! V_14 -> V_125 )
return - V_202 ;
return 0 ;
}
static void F_235 ( struct V_218 * V_219 )
{
struct V_22 * V_23 =
F_166 ( V_219 , struct V_22 , V_219 ) ;
if ( ! ( V_23 -> V_33 & V_70 ) )
F_210 ( V_23 -> V_106 ) ;
else
F_213 ( V_23 -> V_220 ) ;
F_144 ( V_23 -> V_140 ) ;
F_144 ( V_23 ) ;
}
static void F_236 ( struct V_218 * V_219 )
{
struct V_13 * V_14 = F_166 ( V_219 , struct V_13 , V_219 ) ;
F_237 ( & V_14 -> V_133 ) ;
F_213 ( V_14 -> V_125 ) ;
F_144 ( V_14 ) ;
}
static void F_238 ( struct V_13 * V_14 )
{
F_239 ( V_130 ) ;
struct V_51 * V_51 ;
F_20 ( & V_16 ) ;
if ( -- V_14 -> V_69 )
return;
if ( F_115 ( ! ( V_14 -> V_56 < 0 ) ) ||
F_115 ( ! F_51 ( & V_14 -> V_44 ) ) )
return;
if ( V_14 -> V_20 >= 0 )
F_240 ( & V_17 , V_14 -> V_20 ) ;
F_241 ( & V_14 -> V_217 ) ;
F_79 ( & V_14 -> V_68 ) ;
F_242 ( V_146 ,
! ( V_14 -> V_33 & V_47 ) , V_14 -> V_68 ) ;
V_14 -> V_33 |= V_47 ;
while ( ( V_51 = F_56 ( V_14 ) ) )
F_145 ( V_51 ) ;
F_115 ( V_14 -> V_49 || V_14 -> V_45 ) ;
F_80 ( & V_14 -> V_68 ) ;
F_132 ( & V_14 -> V_124 ) ;
if ( ! F_51 ( & V_14 -> V_128 ) )
V_14 -> V_130 = & V_130 ;
F_134 ( & V_14 -> V_124 ) ;
if ( V_14 -> V_130 )
F_180 ( V_14 -> V_130 ) ;
F_198 ( & V_14 -> V_119 ) ;
F_198 ( & V_14 -> V_143 ) ;
F_243 ( & V_14 -> V_219 , F_236 ) ;
}
static struct V_13 * F_244 ( const struct V_206 * V_125 )
{
T_5 V_212 = F_220 ( V_125 ) ;
struct V_13 * V_14 ;
int V_24 ;
int V_221 = V_25 ;
F_20 ( & V_16 ) ;
F_71 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_225 ( V_14 -> V_125 , V_125 ) ) {
V_14 -> V_69 ++ ;
return V_14 ;
}
}
if ( V_222 ) {
F_245 (node) {
if ( F_246 ( V_125 -> V_126 ,
V_223 [ V_24 ] ) ) {
V_221 = V_24 ;
break;
}
}
}
V_14 = F_129 ( sizeof( * V_14 ) , V_19 , V_221 ) ;
if ( ! V_14 || F_227 ( V_14 ) < 0 )
goto V_88;
F_247 ( & V_14 -> V_68 , 1 ) ;
F_219 ( V_14 -> V_125 , V_125 ) ;
V_14 -> V_24 = V_221 ;
V_14 -> V_125 -> V_211 = false ;
if ( F_19 ( V_14 ) < 0 )
goto V_88;
if ( V_182 && ! F_137 ( V_14 ) )
goto V_88;
F_248 ( V_224 , & V_14 -> V_217 , V_212 ) ;
return V_14 ;
V_88:
if ( V_14 )
F_238 ( V_14 ) ;
return NULL ;
}
static void F_249 ( struct V_218 * V_219 )
{
F_250 ( V_225 ,
F_166 ( V_219 , struct V_21 , V_219 ) ) ;
}
static void F_251 ( struct V_2 * V_4 )
{
struct V_21 * V_34 = F_166 ( V_4 , struct V_21 ,
V_71 ) ;
struct V_22 * V_23 = V_34 -> V_23 ;
struct V_13 * V_14 = V_34 -> V_14 ;
bool V_226 ;
if ( F_30 ( ! ( V_23 -> V_33 & V_70 ) ) )
return;
F_132 ( & V_23 -> V_183 ) ;
F_252 ( & V_34 -> V_227 ) ;
V_226 = F_51 ( & V_23 -> V_228 ) ;
F_134 ( & V_23 -> V_183 ) ;
F_132 ( & V_16 ) ;
F_238 ( V_14 ) ;
F_134 ( & V_16 ) ;
F_243 ( & V_34 -> V_219 , F_249 ) ;
if ( V_226 )
F_243 ( & V_23 -> V_219 , F_235 ) ;
}
static void F_253 ( struct V_21 * V_34 )
{
struct V_22 * V_23 = V_34 -> V_23 ;
bool V_229 = V_23 -> V_33 & V_230 ;
unsigned long V_33 ;
F_20 ( & V_23 -> V_183 ) ;
if ( ! V_229 && V_34 -> V_80 == V_23 -> V_193 )
return;
F_254 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
if ( ! V_229 || ! V_231 ) {
V_34 -> V_80 = V_23 -> V_193 ;
while ( ! F_51 ( & V_34 -> V_76 ) &&
V_34 -> V_75 < V_34 -> V_80 )
F_84 ( V_34 ) ;
F_58 ( V_34 -> V_14 ) ;
} else {
V_34 -> V_80 = 0 ;
}
F_255 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
}
static void F_256 ( struct V_21 * V_34 , struct V_22 * V_23 ,
struct V_13 * V_14 )
{
F_257 ( ( unsigned long ) V_34 & V_232 ) ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_14 = V_14 ;
V_34 -> V_23 = V_23 ;
V_34 -> V_81 = - 1 ;
V_34 -> V_69 = 1 ;
F_130 ( & V_34 -> V_76 ) ;
F_130 ( & V_34 -> V_227 ) ;
F_130 ( & V_34 -> V_141 ) ;
F_207 ( & V_34 -> V_71 , F_251 ) ;
}
static void F_258 ( struct V_21 * V_34 )
{
struct V_22 * V_23 = V_34 -> V_23 ;
F_20 ( & V_23 -> V_183 ) ;
if ( ! F_51 ( & V_34 -> V_227 ) )
return;
V_34 -> V_108 = V_23 -> V_108 ;
F_253 ( V_34 ) ;
F_259 ( & V_34 -> V_227 , & V_23 -> V_228 ) ;
}
static struct V_21 * F_260 ( struct V_22 * V_23 ,
const struct V_206 * V_125 )
{
struct V_13 * V_14 ;
struct V_21 * V_34 ;
F_20 ( & V_16 ) ;
V_14 = F_244 ( V_125 ) ;
if ( ! V_14 )
return NULL ;
V_34 = F_261 ( V_225 , V_19 , V_14 -> V_24 ) ;
if ( ! V_34 ) {
F_238 ( V_14 ) ;
return NULL ;
}
F_256 ( V_34 , V_23 , V_14 ) ;
return V_34 ;
}
static bool F_262 ( const struct V_206 * V_125 , int V_24 ,
int V_233 , T_6 * V_126 )
{
if ( ! V_222 || V_125 -> V_211 )
goto V_234;
F_263 ( V_126 , F_264 ( V_24 ) , V_125 -> V_126 ) ;
if ( V_233 >= 0 )
F_265 ( V_233 , V_126 ) ;
if ( F_104 ( V_126 ) )
goto V_234;
F_263 ( V_126 , V_125 -> V_126 , V_223 [ V_24 ] ) ;
if ( F_104 ( V_126 ) ) {
F_266 ( L_13
L_14 ) ;
return false ;
}
return ! F_226 ( V_126 , V_125 -> V_126 ) ;
V_234:
F_218 ( V_126 , V_125 -> V_126 ) ;
return false ;
}
static struct V_21 * F_267 ( struct V_22 * V_23 ,
int V_24 ,
struct V_21 * V_34 )
{
struct V_21 * V_235 ;
F_20 ( & V_16 ) ;
F_20 ( & V_23 -> V_183 ) ;
F_258 ( V_34 ) ;
V_235 = F_268 ( V_23 -> V_27 [ V_24 ] ) ;
F_269 ( V_23 -> V_27 [ V_24 ] , V_34 ) ;
return V_235 ;
}
static void F_270 ( struct V_236 * V_237 )
{
if ( V_237 ) {
int V_24 ;
F_245 (node)
F_78 ( V_237 -> V_238 [ V_24 ] ) ;
F_78 ( V_237 -> V_26 ) ;
F_213 ( V_237 -> V_125 ) ;
F_144 ( V_237 ) ;
}
}
static struct V_236 *
F_271 ( struct V_22 * V_23 ,
const struct V_206 * V_125 )
{
struct V_236 * V_237 ;
struct V_206 * V_239 , * V_240 ;
int V_24 ;
F_20 ( & V_16 ) ;
V_237 = F_216 ( sizeof( * V_237 ) + V_241 * sizeof( V_237 -> V_238 [ 0 ] ) ,
V_19 ) ;
V_239 = F_215 ( V_19 ) ;
V_240 = F_215 ( V_19 ) ;
if ( ! V_237 || ! V_239 || ! V_240 )
goto V_242;
F_219 ( V_239 , V_125 ) ;
F_263 ( V_239 -> V_126 , V_239 -> V_126 , V_96 ) ;
if ( F_24 ( F_104 ( V_239 -> V_126 ) ) )
F_218 ( V_239 -> V_126 , V_96 ) ;
F_219 ( V_240 , V_239 ) ;
V_237 -> V_26 = F_260 ( V_23 , V_239 ) ;
if ( ! V_237 -> V_26 )
goto V_242;
F_245 (node) {
if ( F_262 ( V_239 , V_24 , - 1 , V_240 -> V_126 ) ) {
V_237 -> V_238 [ V_24 ] = F_260 ( V_23 , V_240 ) ;
if ( ! V_237 -> V_238 [ V_24 ] )
goto V_242;
} else {
V_237 -> V_26 -> V_69 ++ ;
V_237 -> V_238 [ V_24 ] = V_237 -> V_26 ;
}
}
F_219 ( V_239 , V_125 ) ;
F_263 ( V_239 -> V_126 , V_239 -> V_126 , V_208 ) ;
V_237 -> V_125 = V_239 ;
V_237 -> V_23 = V_23 ;
F_213 ( V_240 ) ;
return V_237 ;
V_242:
F_213 ( V_240 ) ;
F_213 ( V_239 ) ;
F_270 ( V_237 ) ;
return NULL ;
}
static void F_272 ( struct V_236 * V_237 )
{
int V_24 ;
F_132 ( & V_237 -> V_23 -> V_183 ) ;
F_219 ( V_237 -> V_23 -> V_220 , V_237 -> V_125 ) ;
F_245 (node)
V_237 -> V_238 [ V_24 ] = F_267 ( V_237 -> V_23 , V_24 ,
V_237 -> V_238 [ V_24 ] ) ;
F_258 ( V_237 -> V_26 ) ;
F_273 ( V_237 -> V_23 -> V_26 , V_237 -> V_26 ) ;
F_134 ( & V_237 -> V_23 -> V_183 ) ;
}
static void F_274 ( void )
{
F_205 () ;
F_132 ( & V_16 ) ;
}
static void F_275 ( void )
{
F_134 ( & V_16 ) ;
F_209 () ;
}
static int F_276 ( struct V_22 * V_23 ,
const struct V_206 * V_125 )
{
struct V_236 * V_237 ;
if ( F_115 ( ! ( V_23 -> V_33 & V_70 ) ) )
return - V_243 ;
if ( ! F_51 ( & V_23 -> V_228 ) ) {
if ( F_115 ( V_23 -> V_33 & V_244 ) )
return - V_243 ;
V_23 -> V_33 &= ~ V_245 ;
}
V_237 = F_271 ( V_23 , V_125 ) ;
if ( ! V_237 )
return - V_202 ;
F_272 ( V_237 ) ;
F_270 ( V_237 ) ;
return 0 ;
}
int F_277 ( struct V_22 * V_23 ,
const struct V_206 * V_125 )
{
int V_15 ;
F_274 () ;
V_15 = F_276 ( V_23 , V_125 ) ;
F_275 () ;
return V_15 ;
}
static void F_278 ( struct V_22 * V_23 , int V_56 ,
bool V_246 )
{
int V_24 = F_112 ( V_56 ) ;
int V_247 = V_246 ? - 1 : V_56 ;
struct V_21 * V_235 = NULL , * V_34 ;
struct V_206 * V_248 ;
T_6 * V_126 ;
F_20 ( & V_16 ) ;
if ( ! V_222 || ! ( V_23 -> V_33 & V_70 ) ||
V_23 -> V_220 -> V_211 )
return;
V_248 = V_249 ;
V_126 = V_248 -> V_126 ;
F_219 ( V_248 , V_23 -> V_220 ) ;
V_34 = F_22 ( V_23 , V_24 ) ;
if ( F_262 ( V_23 -> V_26 -> V_14 -> V_125 , V_24 , V_247 , V_126 ) ) {
if ( F_226 ( V_126 , V_34 -> V_14 -> V_125 -> V_126 ) )
return;
} else {
goto V_250;
}
V_34 = F_260 ( V_23 , V_248 ) ;
if ( ! V_34 ) {
F_103 ( L_15 ,
V_23 -> V_107 ) ;
goto V_250;
}
F_132 ( & V_23 -> V_183 ) ;
V_235 = F_267 ( V_23 , V_24 , V_34 ) ;
goto V_185;
V_250:
F_132 ( & V_23 -> V_183 ) ;
F_79 ( & V_23 -> V_26 -> V_14 -> V_68 ) ;
F_75 ( V_23 -> V_26 ) ;
F_80 ( & V_23 -> V_26 -> V_14 -> V_68 ) ;
V_235 = F_267 ( V_23 , V_24 , V_23 -> V_26 ) ;
V_185:
F_134 ( & V_23 -> V_183 ) ;
F_78 ( V_235 ) ;
}
static int F_279 ( struct V_22 * V_23 )
{
bool V_251 = V_23 -> V_33 & V_252 ;
int V_56 , V_15 ;
if ( ! ( V_23 -> V_33 & V_70 ) ) {
V_23 -> V_106 = F_204 ( struct V_21 ) ;
if ( ! V_23 -> V_106 )
return - V_202 ;
F_280 (cpu) {
struct V_21 * V_34 =
F_111 ( V_23 -> V_106 , V_56 ) ;
struct V_13 * V_253 =
F_281 ( V_254 , V_56 ) ;
F_256 ( V_34 , V_23 , & V_253 [ V_251 ] ) ;
F_132 ( & V_23 -> V_183 ) ;
F_258 ( V_34 ) ;
F_134 ( & V_23 -> V_183 ) ;
}
return 0 ;
} else if ( V_23 -> V_33 & V_245 ) {
V_15 = F_277 ( V_23 , V_255 [ V_251 ] ) ;
F_282 ( ! V_15 && ( V_23 -> V_228 . V_116 != & V_23 -> V_26 -> V_227 ||
V_23 -> V_228 . V_138 != & V_23 -> V_26 -> V_227 ) ,
L_16 , V_23 -> V_107 ) ;
return V_15 ;
} else {
return F_277 ( V_23 , V_256 [ V_251 ] ) ;
}
}
static int F_283 ( int V_80 , unsigned int V_33 ,
const char * V_107 )
{
int V_257 = V_33 & V_70 ? V_258 : V_259 ;
if ( V_80 < 1 || V_80 > V_257 )
F_103 ( L_17 ,
V_80 , V_107 , 1 , V_257 ) ;
return F_284 ( V_80 , 1 , V_257 ) ;
}
struct V_22 * F_285 ( const char * V_260 ,
unsigned int V_33 ,
int V_80 ,
struct V_261 * V_174 ,
const char * V_262 , ... )
{
T_7 V_263 = 0 ;
T_8 args ;
struct V_22 * V_23 ;
struct V_21 * V_34 ;
if ( ( V_33 & V_70 ) && V_80 == 1 )
V_33 |= V_245 ;
if ( ( V_33 & V_264 ) && V_265 )
V_33 |= V_70 ;
if ( V_33 & V_70 )
V_263 = V_241 * sizeof( V_23 -> V_27 [ 0 ] ) ;
V_23 = F_216 ( sizeof( * V_23 ) + V_263 , V_19 ) ;
if ( ! V_23 )
return NULL ;
if ( V_33 & V_70 ) {
V_23 -> V_220 = F_215 ( V_19 ) ;
if ( ! V_23 -> V_220 )
goto V_266;
}
va_start ( args , V_262 ) ;
vsnprintf ( V_23 -> V_107 , sizeof( V_23 -> V_107 ) , V_260 , args ) ;
va_end ( args ) ;
V_80 = V_80 ? : V_267 ;
V_80 = F_283 ( V_80 , V_33 , V_23 -> V_107 ) ;
V_23 -> V_33 = V_33 ;
V_23 -> V_193 = V_80 ;
F_232 ( & V_23 -> V_183 ) ;
F_173 ( & V_23 -> V_82 , 0 ) ;
F_130 ( & V_23 -> V_228 ) ;
F_130 ( & V_23 -> V_186 ) ;
F_130 ( & V_23 -> V_184 ) ;
F_130 ( & V_23 -> V_142 ) ;
F_286 ( & V_23 -> V_172 , V_262 , V_174 , 0 ) ;
F_130 ( & V_23 -> V_180 ) ;
if ( F_279 ( V_23 ) < 0 )
goto V_266;
if ( V_33 & V_163 ) {
struct V_51 * V_140 ;
V_140 = F_128 ( V_25 ) ;
if ( ! V_140 )
goto V_268;
V_140 -> V_154 = V_23 ;
V_140 -> V_54 = F_287 ( F_160 , V_140 , L_18 ,
V_23 -> V_107 ) ;
if ( F_140 ( V_140 -> V_54 ) ) {
F_144 ( V_140 ) ;
goto V_268;
}
V_23 -> V_140 = V_140 ;
F_142 ( V_140 -> V_54 , V_208 ) ;
F_60 ( V_140 -> V_54 ) ;
}
if ( ( V_23 -> V_33 & V_269 ) && F_288 ( V_23 ) )
goto V_268;
F_132 ( & V_16 ) ;
F_132 ( & V_23 -> V_183 ) ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_134 ( & V_23 -> V_183 ) ;
F_289 ( & V_23 -> V_180 , & V_270 ) ;
F_134 ( & V_16 ) ;
return V_23 ;
V_266:
F_213 ( V_23 -> V_220 ) ;
F_144 ( V_23 ) ;
return NULL ;
V_268:
F_290 ( V_23 ) ;
return NULL ;
}
void F_290 ( struct V_22 * V_23 )
{
struct V_21 * V_34 ;
int V_24 ;
F_182 ( V_23 ) ;
F_132 ( & V_23 -> V_183 ) ;
F_174 (pwq, wq) {
int V_271 ;
for ( V_271 = 0 ; V_271 < V_31 ; V_271 ++ ) {
if ( F_115 ( V_34 -> V_79 [ V_271 ] ) ) {
F_134 ( & V_23 -> V_183 ) ;
F_291 () ;
return;
}
}
if ( F_115 ( ( V_34 != V_23 -> V_26 ) && ( V_34 -> V_69 > 1 ) ) ||
F_115 ( V_34 -> V_75 ) ||
F_115 ( ! F_51 ( & V_34 -> V_76 ) ) ) {
F_134 ( & V_23 -> V_183 ) ;
F_291 () ;
return;
}
}
F_134 ( & V_23 -> V_183 ) ;
F_132 ( & V_16 ) ;
F_252 ( & V_23 -> V_180 ) ;
F_134 ( & V_16 ) ;
F_292 ( V_23 ) ;
if ( V_23 -> V_140 )
F_293 ( V_23 -> V_140 -> V_54 ) ;
if ( ! ( V_23 -> V_33 & V_70 ) ) {
F_243 ( & V_23 -> V_219 , F_235 ) ;
} else {
F_245 (node) {
V_34 = F_268 ( V_23 -> V_27 [ V_24 ] ) ;
F_294 ( V_23 -> V_27 [ V_24 ] , NULL ) ;
F_78 ( V_34 ) ;
}
V_34 = V_23 -> V_26 ;
V_23 -> V_26 = NULL ;
F_78 ( V_34 ) ;
}
}
void F_295 ( struct V_22 * V_23 , int V_80 )
{
struct V_21 * V_34 ;
if ( F_115 ( V_23 -> V_33 & V_244 ) )
return;
V_80 = F_283 ( V_80 , V_23 -> V_33 , V_23 -> V_107 ) ;
F_132 ( & V_23 -> V_183 ) ;
V_23 -> V_33 &= ~ V_245 ;
V_23 -> V_193 = V_80 ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_134 ( & V_23 -> V_183 ) ;
}
bool F_296 ( void )
{
struct V_51 * V_51 = F_100 () ;
return V_51 && V_51 -> V_154 ;
}
bool F_297 ( int V_56 , struct V_22 * V_23 )
{
struct V_21 * V_34 ;
bool V_15 ;
F_298 () ;
if ( V_56 == V_105 )
V_56 = F_299 () ;
if ( ! ( V_23 -> V_33 & V_70 ) )
V_34 = F_111 ( V_23 -> V_106 , V_56 ) ;
else
V_34 = F_22 ( V_23 , F_112 ( V_56 ) ) ;
V_15 = ! F_51 ( & V_34 -> V_76 ) ;
F_300 () ;
return V_15 ;
}
unsigned int F_301 ( struct V_2 * V_4 )
{
struct V_13 * V_14 ;
unsigned long V_33 ;
unsigned int V_15 = 0 ;
if ( F_31 ( V_4 ) )
V_15 |= V_272 ;
F_88 ( V_33 ) ;
V_14 = F_42 ( V_4 ) ;
if ( V_14 ) {
F_92 ( & V_14 -> V_68 ) ;
if ( F_70 ( V_14 , V_4 ) )
V_15 |= V_273 ;
F_94 ( & V_14 -> V_68 ) ;
}
F_95 ( V_33 ) ;
return V_15 ;
}
void F_302 ( const char * V_260 , ... )
{
struct V_51 * V_51 = F_100 () ;
T_8 args ;
if ( V_51 ) {
va_start ( args , V_260 ) ;
vsnprintf ( V_51 -> V_274 , sizeof( V_51 -> V_274 ) , V_260 , args ) ;
va_end ( args ) ;
V_51 -> V_275 = true ;
}
}
void F_303 ( const char * V_276 , struct V_55 * V_54 )
{
T_1 * V_203 = NULL ;
char V_107 [ V_277 ] = { } ;
char V_274 [ V_278 ] = { } ;
struct V_21 * V_34 = NULL ;
struct V_22 * V_23 = NULL ;
bool V_275 = false ;
struct V_51 * V_51 ;
if ( ! ( V_54 -> V_33 & V_148 ) )
return;
V_51 = F_304 ( V_54 ) ;
F_305 ( & V_203 , & V_51 -> V_62 , sizeof( V_203 ) ) ;
F_305 ( & V_34 , & V_51 -> V_92 , sizeof( V_34 ) ) ;
F_305 ( & V_23 , & V_34 -> V_23 , sizeof( V_23 ) ) ;
F_305 ( V_107 , V_23 -> V_107 , sizeof( V_107 ) - 1 ) ;
F_305 ( & V_275 , & V_51 -> V_275 , sizeof( V_275 ) ) ;
if ( V_275 )
F_305 ( V_274 , V_51 -> V_274 , sizeof( V_274 ) - 1 ) ;
if ( V_203 || V_107 [ 0 ] || V_274 [ 0 ] ) {
F_306 ( L_19 , V_276 , V_107 , V_203 ) ;
if ( V_274 [ 0 ] )
F_307 ( L_20 , V_274 ) ;
F_307 ( L_21 ) ;
}
}
static void F_308 ( struct V_13 * V_14 )
{
F_307 ( L_22 , V_213 , V_14 -> V_125 -> V_126 ) ;
if ( V_14 -> V_24 != V_25 )
F_307 ( L_23 , V_14 -> V_24 ) ;
F_307 ( L_24 , V_14 -> V_33 , V_14 -> V_125 -> V_134 ) ;
}
static void F_309 ( bool V_279 , struct V_2 * V_4 )
{
if ( V_4 -> V_3 == F_165 ) {
struct V_168 * V_169 ;
V_169 = F_166 ( V_4 , struct V_168 , V_4 ) ;
F_307 ( L_25 , V_279 ? L_26 : L_5 ,
F_310 ( V_169 -> V_54 ) ) ;
} else {
F_307 ( L_27 , V_279 ? L_26 : L_5 , V_4 -> V_3 ) ;
}
}
static void F_311 ( struct V_21 * V_34 )
{
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_2 * V_4 ;
struct V_51 * V_51 ;
bool V_280 = false , V_281 = false ;
int V_282 ;
F_312 ( L_28 , V_14 -> V_20 ) ;
F_308 ( V_14 ) ;
F_307 ( L_29 , V_34 -> V_75 , V_34 -> V_80 ,
! F_51 ( & V_34 -> V_141 ) ? L_30 : L_5 ) ;
F_313 (pool->busy_hash, bkt, worker, hentry) {
if ( V_51 -> V_92 == V_34 ) {
V_280 = true ;
break;
}
}
if ( V_280 ) {
bool V_279 = false ;
F_312 ( L_31 ) ;
F_313 (pool->busy_hash, bkt, worker, hentry) {
if ( V_51 -> V_92 != V_34 )
continue;
F_307 ( L_32 , V_279 ? L_26 : L_5 ,
F_310 ( V_51 -> V_54 ) ,
V_51 == V_34 -> V_23 -> V_140 ? L_33 : L_5 ,
V_51 -> V_62 ) ;
F_151 (work, &worker->scheduled, entry)
F_309 ( false , V_4 ) ;
V_279 = true ;
}
F_307 ( L_21 ) ;
}
F_151 (work, &pool->worklist, entry) {
if ( F_40 ( V_4 ) == V_34 ) {
V_281 = true ;
break;
}
}
if ( V_281 ) {
bool V_279 = false ;
F_312 ( L_34 ) ;
F_151 (work, &pool->worklist, entry) {
if ( F_40 ( V_4 ) != V_34 )
continue;
F_309 ( V_279 , V_4 ) ;
V_279 = ! ( * F_4 ( V_4 ) & V_67 ) ;
}
F_307 ( L_21 ) ;
}
if ( ! F_51 ( & V_34 -> V_76 ) ) {
bool V_279 = false ;
F_312 ( L_35 ) ;
F_151 (work, &pwq->delayed_works, entry) {
F_309 ( V_279 , V_4 ) ;
V_279 = ! ( * F_4 ( V_4 ) & V_67 ) ;
}
F_307 ( L_21 ) ;
}
}
void F_291 ( void )
{
struct V_22 * V_23 ;
struct V_13 * V_14 ;
unsigned long V_33 ;
int V_283 ;
F_298 () ;
F_312 ( L_36 ) ;
F_314 (wq, &workqueues, list) {
struct V_21 * V_34 ;
bool V_284 = true ;
F_174 (pwq, wq) {
if ( V_34 -> V_75 || ! F_51 ( & V_34 -> V_76 ) ) {
V_284 = false ;
break;
}
}
if ( V_284 )
continue;
F_312 ( L_37 , V_23 -> V_107 , V_23 -> V_33 ) ;
F_174 (pwq, wq) {
F_254 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
if ( V_34 -> V_75 || ! F_51 ( & V_34 -> V_76 ) )
F_311 ( V_34 ) ;
F_255 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
}
}
F_315 (pool, pi) {
struct V_51 * V_51 ;
bool V_158 = true ;
F_254 ( & V_14 -> V_68 , V_33 ) ;
if ( V_14 -> V_49 == V_14 -> V_45 )
goto V_285;
F_312 ( L_38 , V_14 -> V_20 ) ;
F_308 ( V_14 ) ;
F_307 ( L_39 ,
F_316 ( V_73 - V_14 -> V_72 ) / 1000 ,
V_14 -> V_49 ) ;
if ( V_14 -> V_145 )
F_307 ( L_40 ,
F_310 ( V_14 -> V_145 -> V_54 ) ) ;
F_151 (worker, &pool->idle_list, entry) {
F_307 ( L_41 , V_158 ? L_42 : L_5 ,
F_310 ( V_51 -> V_54 ) ) ;
V_158 = false ;
}
F_307 ( L_21 ) ;
V_285:
F_255 ( & V_14 -> V_68 , V_33 ) ;
}
F_300 () ;
}
static void F_317 ( struct V_2 * V_4 )
{
int V_56 = F_299 () ;
struct V_13 * V_14 ;
struct V_51 * V_51 ;
F_318 (pool, cpu) {
F_132 ( & V_14 -> V_124 ) ;
F_79 ( & V_14 -> V_68 ) ;
F_319 (worker, pool)
V_51 -> V_33 |= V_127 ;
V_14 -> V_33 |= V_121 ;
F_80 ( & V_14 -> V_68 ) ;
F_134 ( & V_14 -> V_124 ) ;
F_159 () ;
F_173 ( & V_14 -> V_43 , 0 ) ;
F_79 ( & V_14 -> V_68 ) ;
F_58 ( V_14 ) ;
F_80 ( & V_14 -> V_68 ) ;
}
}
static void F_320 ( struct V_13 * V_14 )
{
struct V_51 * V_51 ;
F_20 ( & V_14 -> V_124 ) ;
F_319 (worker, pool)
F_30 ( F_133 ( V_51 -> V_54 ,
V_14 -> V_125 -> V_126 ) < 0 ) ;
F_79 ( & V_14 -> V_68 ) ;
if ( ! ( V_14 -> V_33 & V_121 ) ) {
F_80 ( & V_14 -> V_68 ) ;
return;
}
V_14 -> V_33 &= ~ V_121 ;
F_319 (worker, pool) {
unsigned int V_286 = V_51 -> V_33 ;
if ( V_286 & V_114 )
F_60 ( V_51 -> V_54 ) ;
F_30 ( ! ( V_286 & V_127 ) ) ;
V_286 |= V_131 ;
V_286 &= ~ V_127 ;
F_321 ( V_51 -> V_33 ) = V_286 ;
}
F_80 ( & V_14 -> V_68 ) ;
}
static void F_322 ( struct V_13 * V_14 , int V_56 )
{
static T_6 V_126 ;
struct V_51 * V_51 ;
F_20 ( & V_14 -> V_124 ) ;
if ( ! F_102 ( V_56 , V_14 -> V_125 -> V_126 ) )
return;
F_263 ( & V_126 , V_14 -> V_125 -> V_126 , V_98 ) ;
F_319 (worker, pool)
F_30 ( F_133 ( V_51 -> V_54 , & V_126 ) < 0 ) ;
}
int F_323 ( unsigned int V_56 )
{
struct V_13 * V_14 ;
F_318 (pool, cpu) {
if ( V_14 -> V_49 )
continue;
if ( ! F_137 ( V_14 ) )
return - V_202 ;
}
return 0 ;
}
int F_324 ( unsigned int V_56 )
{
struct V_13 * V_14 ;
struct V_22 * V_23 ;
int V_283 ;
F_132 ( & V_16 ) ;
F_315 (pool, pi) {
F_132 ( & V_14 -> V_124 ) ;
if ( V_14 -> V_56 == V_56 )
F_320 ( V_14 ) ;
else if ( V_14 -> V_56 < 0 )
F_322 ( V_14 , V_56 ) ;
F_134 ( & V_14 -> V_124 ) ;
}
F_151 (wq, &workqueues, list)
F_278 ( V_23 , V_56 , true ) ;
F_134 ( & V_16 ) ;
return 0 ;
}
int F_325 ( unsigned int V_56 )
{
struct V_2 V_287 ;
struct V_22 * V_23 ;
F_168 ( & V_287 , F_317 ) ;
F_116 ( V_56 , V_288 , & V_287 ) ;
F_132 ( & V_16 ) ;
F_151 (wq, &workqueues, list)
F_278 ( V_23 , V_56 , false ) ;
F_134 ( & V_16 ) ;
F_187 ( & V_287 ) ;
F_16 ( & V_287 ) ;
return 0 ;
}
static void F_326 ( struct V_2 * V_4 )
{
struct V_289 * V_290 = F_166 ( V_4 , struct V_289 , V_4 ) ;
V_290 -> V_15 = V_290 -> V_203 ( V_290 -> V_291 ) ;
}
long F_327 ( int V_56 , long (* V_203)( void * ) , void * V_291 )
{
struct V_289 V_290 = { . V_203 = V_203 , . V_291 = V_291 } ;
F_168 ( & V_290 . V_4 , F_326 ) ;
F_208 ( V_56 , & V_290 . V_4 ) ;
F_187 ( & V_290 . V_4 ) ;
F_16 ( & V_290 . V_4 ) ;
return V_290 . V_15 ;
}
long F_328 ( int V_56 , long (* V_203)( void * ) , void * V_291 )
{
long V_15 = - V_292 ;
F_205 () ;
if ( F_329 ( V_56 ) )
V_15 = F_327 ( V_56 , V_203 , V_291 ) ;
F_209 () ;
return V_15 ;
}
void F_330 ( void )
{
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_132 ( & V_16 ) ;
F_30 ( V_231 ) ;
V_231 = true ;
F_151 (wq, &workqueues, list) {
F_132 ( & V_23 -> V_183 ) ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_134 ( & V_23 -> V_183 ) ;
}
F_134 ( & V_16 ) ;
}
bool F_331 ( void )
{
bool V_293 = false ;
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_132 ( & V_16 ) ;
F_30 ( ! V_231 ) ;
F_151 (wq, &workqueues, list) {
if ( ! ( V_23 -> V_33 & V_230 ) )
continue;
F_298 () ;
F_174 (pwq, wq) {
F_30 ( V_34 -> V_75 < 0 ) ;
if ( V_34 -> V_75 ) {
V_293 = true ;
F_300 () ;
goto V_185;
}
}
F_300 () ;
}
V_185:
F_134 ( & V_16 ) ;
return V_293 ;
}
void F_332 ( void )
{
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_132 ( & V_16 ) ;
if ( ! V_231 )
goto V_185;
V_231 = false ;
F_151 (wq, &workqueues, list) {
F_132 ( & V_23 -> V_183 ) ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_134 ( & V_23 -> V_183 ) ;
}
V_185:
F_134 ( & V_16 ) ;
}
static int F_333 ( void )
{
F_334 ( V_294 ) ;
int V_15 = 0 ;
struct V_22 * V_23 ;
struct V_236 * V_237 , * V_66 ;
F_20 ( & V_16 ) ;
F_151 (wq, &workqueues, list) {
if ( ! ( V_23 -> V_33 & V_70 ) )
continue;
if ( V_23 -> V_33 & V_245 )
continue;
V_237 = F_271 ( V_23 , V_23 -> V_220 ) ;
if ( ! V_237 ) {
V_15 = - V_202 ;
break;
}
F_98 ( & V_237 -> V_180 , & V_294 ) ;
}
F_163 (ctx, n, &ctxs, list) {
if ( ! V_15 )
F_272 ( V_237 ) ;
F_270 ( V_237 ) ;
}
return V_15 ;
}
int F_335 ( T_9 V_126 )
{
int V_15 = - V_243 ;
T_9 V_295 ;
if ( ! F_336 ( & V_295 , V_19 ) )
return - V_202 ;
F_263 ( V_126 , V_126 , V_208 ) ;
if ( ! F_104 ( V_126 ) ) {
F_274 () ;
F_218 ( V_295 , V_96 ) ;
F_218 ( V_96 , V_126 ) ;
V_15 = F_333 () ;
if ( V_15 < 0 )
F_218 ( V_96 , V_295 ) ;
F_275 () ;
}
F_214 ( V_295 ) ;
return V_15 ;
}
static struct V_22 * F_337 ( struct V_296 * V_297 )
{
struct V_298 * V_299 = F_166 ( V_297 , struct V_298 , V_297 ) ;
return V_299 -> V_23 ;
}
static T_10 F_338 ( struct V_296 * V_297 , struct V_300 * V_301 ,
char * V_302 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
return F_339 ( V_302 , V_303 , L_43 , ( bool ) ! ( V_23 -> V_33 & V_70 ) ) ;
}
static T_10 F_340 ( struct V_296 * V_297 ,
struct V_300 * V_301 , char * V_302 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
return F_339 ( V_302 , V_303 , L_43 , V_23 -> V_193 ) ;
}
static T_10 F_341 ( struct V_296 * V_297 ,
struct V_300 * V_301 , const char * V_302 ,
T_7 V_304 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
int V_305 ;
if ( sscanf ( V_302 , L_44 , & V_305 ) != 1 || V_305 <= 0 )
return - V_243 ;
F_295 ( V_23 , V_305 ) ;
return V_304 ;
}
static T_10 F_342 ( struct V_296 * V_297 ,
struct V_300 * V_301 , char * V_302 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
const char * V_306 = L_5 ;
int V_24 , V_307 = 0 ;
F_298 () ;
F_245 (node) {
V_307 += F_339 ( V_302 + V_307 , V_303 - V_307 ,
L_45 , V_306 , V_24 ,
F_22 ( V_23 , V_24 ) -> V_14 -> V_20 ) ;
V_306 = L_46 ;
}
V_307 += F_339 ( V_302 + V_307 , V_303 - V_307 , L_21 ) ;
F_300 () ;
return V_307 ;
}
static T_10 F_343 ( struct V_296 * V_297 , struct V_300 * V_301 ,
char * V_302 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
int V_307 ;
F_132 ( & V_23 -> V_183 ) ;
V_307 = F_339 ( V_302 , V_303 , L_43 , V_23 -> V_220 -> V_134 ) ;
F_134 ( & V_23 -> V_183 ) ;
return V_307 ;
}
static struct V_206 * F_344 ( struct V_22 * V_23 )
{
struct V_206 * V_125 ;
F_20 ( & V_16 ) ;
V_125 = F_215 ( V_19 ) ;
if ( ! V_125 )
return NULL ;
F_219 ( V_125 , V_23 -> V_220 ) ;
return V_125 ;
}
static T_10 F_345 ( struct V_296 * V_297 , struct V_300 * V_301 ,
const char * V_302 , T_7 V_304 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
struct V_206 * V_125 ;
int V_15 = - V_202 ;
F_274 () ;
V_125 = F_344 ( V_23 ) ;
if ( ! V_125 )
goto V_185;
if ( sscanf ( V_302 , L_44 , & V_125 -> V_134 ) == 1 &&
V_125 -> V_134 >= V_308 && V_125 -> V_134 <= V_309 )
V_15 = F_276 ( V_23 , V_125 ) ;
else
V_15 = - V_243 ;
V_185:
F_275 () ;
F_213 ( V_125 ) ;
return V_15 ? : V_304 ;
}
static T_10 F_346 ( struct V_296 * V_297 ,
struct V_300 * V_301 , char * V_302 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
int V_307 ;
F_132 ( & V_23 -> V_183 ) ;
V_307 = F_339 ( V_302 , V_303 , L_47 ,
F_347 ( V_23 -> V_220 -> V_126 ) ) ;
F_134 ( & V_23 -> V_183 ) ;
return V_307 ;
}
static T_10 F_348 ( struct V_296 * V_297 ,
struct V_300 * V_301 ,
const char * V_302 , T_7 V_304 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
struct V_206 * V_125 ;
int V_15 = - V_202 ;
F_274 () ;
V_125 = F_344 ( V_23 ) ;
if ( ! V_125 )
goto V_185;
V_15 = F_349 ( V_302 , V_125 -> V_126 ) ;
if ( ! V_15 )
V_15 = F_276 ( V_23 , V_125 ) ;
V_185:
F_275 () ;
F_213 ( V_125 ) ;
return V_15 ? : V_304 ;
}
static T_10 F_350 ( struct V_296 * V_297 , struct V_300 * V_301 ,
char * V_302 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
int V_307 ;
F_132 ( & V_23 -> V_183 ) ;
V_307 = F_339 ( V_302 , V_303 , L_43 ,
! V_23 -> V_220 -> V_211 ) ;
F_134 ( & V_23 -> V_183 ) ;
return V_307 ;
}
static T_10 F_351 ( struct V_296 * V_297 , struct V_300 * V_301 ,
const char * V_302 , T_7 V_304 )
{
struct V_22 * V_23 = F_337 ( V_297 ) ;
struct V_206 * V_125 ;
int V_310 , V_15 = - V_202 ;
F_274 () ;
V_125 = F_344 ( V_23 ) ;
if ( ! V_125 )
goto V_185;
V_15 = - V_243 ;
if ( sscanf ( V_302 , L_44 , & V_310 ) == 1 ) {
V_125 -> V_211 = ! V_310 ;
V_15 = F_276 ( V_23 , V_125 ) ;
}
V_185:
F_275 () ;
F_213 ( V_125 ) ;
return V_15 ? : V_304 ;
}
static T_10 F_352 ( struct V_296 * V_297 ,
struct V_300 * V_301 , char * V_302 )
{
int V_307 ;
F_132 ( & V_16 ) ;
V_307 = F_339 ( V_302 , V_303 , L_47 ,
F_347 ( V_96 ) ) ;
F_134 ( & V_16 ) ;
return V_307 ;
}
static T_10 F_353 ( struct V_296 * V_297 ,
struct V_300 * V_301 , const char * V_302 , T_7 V_304 )
{
T_9 V_126 ;
int V_15 ;
if ( ! F_336 ( & V_126 , V_19 ) )
return - V_202 ;
V_15 = F_349 ( V_302 , V_126 ) ;
if ( ! V_15 )
V_15 = F_335 ( V_126 ) ;
F_214 ( V_126 ) ;
return V_15 ? V_15 : V_304 ;
}
static int T_11 F_354 ( void )
{
int V_311 ;
V_311 = F_355 ( & V_312 , NULL ) ;
if ( V_311 )
return V_311 ;
return F_356 ( V_312 . V_313 , & V_314 ) ;
}
static void F_357 ( struct V_296 * V_297 )
{
struct V_298 * V_299 = F_166 ( V_297 , struct V_298 , V_297 ) ;
F_144 ( V_299 ) ;
}
int F_288 ( struct V_22 * V_23 )
{
struct V_298 * V_299 ;
int V_15 ;
if ( F_115 ( V_23 -> V_33 & V_244 ) )
return - V_243 ;
V_23 -> V_299 = V_299 = F_216 ( sizeof( * V_299 ) , V_19 ) ;
if ( ! V_299 )
return - V_202 ;
V_299 -> V_23 = V_23 ;
V_299 -> V_297 . V_315 = & V_312 ;
V_299 -> V_297 . V_316 = F_357 ;
F_358 ( & V_299 -> V_297 , L_18 , V_23 -> V_107 ) ;
F_359 ( & V_299 -> V_297 , true ) ;
V_15 = F_360 ( & V_299 -> V_297 ) ;
if ( V_15 ) {
F_144 ( V_299 ) ;
V_23 -> V_299 = NULL ;
return V_15 ;
}
if ( V_23 -> V_33 & V_70 ) {
struct V_300 * V_301 ;
for ( V_301 = V_317 ; V_301 -> V_301 . V_107 ; V_301 ++ ) {
V_15 = F_356 ( & V_299 -> V_297 , V_301 ) ;
if ( V_15 ) {
F_361 ( & V_299 -> V_297 ) ;
V_23 -> V_299 = NULL ;
return V_15 ;
}
}
}
F_359 ( & V_299 -> V_297 , false ) ;
F_362 ( & V_299 -> V_297 . V_318 , V_319 ) ;
return 0 ;
}
static void F_292 ( struct V_22 * V_23 )
{
struct V_298 * V_299 = V_23 -> V_299 ;
if ( ! V_23 -> V_299 )
return;
V_23 -> V_299 = NULL ;
F_361 ( & V_299 -> V_297 ) ;
}
static void F_292 ( struct V_22 * V_23 ) { }
static void F_363 ( void )
{
int V_56 ;
V_320 = V_73 ;
F_280 (cpu)
F_281 ( V_321 , V_56 ) = V_73 ;
}
static void F_364 ( unsigned long V_32 )
{
unsigned long V_322 = F_365 ( V_323 ) * V_324 ;
bool V_325 = false ;
struct V_13 * V_14 ;
int V_283 ;
if ( ! V_322 )
return;
F_366 () ;
F_315 (pool, pi) {
unsigned long V_326 , V_327 , V_328 ;
if ( F_51 ( & V_14 -> V_44 ) )
continue;
V_326 = F_365 ( V_14 -> V_72 ) ;
V_327 = F_365 ( V_320 ) ;
if ( F_367 ( V_326 , V_327 ) )
V_328 = V_326 ;
else
V_328 = V_327 ;
if ( V_14 -> V_56 >= 0 ) {
unsigned long V_329 =
F_365 ( F_281 ( V_321 ,
V_14 -> V_56 ) ) ;
if ( F_367 ( V_329 , V_328 ) )
V_328 = V_329 ;
}
if ( F_367 ( V_73 , V_328 + V_322 ) ) {
V_325 = true ;
F_368 ( L_48 ) ;
F_308 ( V_14 ) ;
F_307 ( L_49 ,
F_316 ( V_73 - V_326 ) / 1000 ) ;
}
}
F_369 () ;
if ( V_325 )
F_291 () ;
F_363 () ;
F_126 ( & V_330 , V_73 + V_322 ) ;
}
void F_370 ( int V_56 )
{
if ( V_56 >= 0 )
F_281 ( V_321 , V_56 ) = V_73 ;
else
V_320 = V_73 ;
}
static void F_371 ( unsigned long V_322 )
{
V_323 = 0 ;
F_198 ( & V_330 ) ;
if ( V_322 ) {
V_323 = V_322 ;
F_363 () ;
F_126 ( & V_330 , V_73 + V_322 * V_324 ) ;
}
}
static int F_372 ( const char * V_305 ,
const struct V_331 * V_332 )
{
unsigned long V_322 ;
int V_15 ;
V_15 = F_373 ( V_305 , 0 , & V_322 ) ;
if ( V_15 )
return V_15 ;
if ( V_333 )
F_371 ( V_322 ) ;
else
V_323 = V_322 ;
return 0 ;
}
static void F_374 ( void )
{
F_371 ( V_323 ) ;
}
static inline void F_374 ( void ) { }
static void T_11 F_375 ( void )
{
T_9 * V_334 ;
int V_24 , V_56 ;
if ( F_376 () <= 1 )
return;
if ( V_335 ) {
F_312 ( L_50 ) ;
return;
}
V_249 = F_215 ( V_19 ) ;
F_257 ( ! V_249 ) ;
V_334 = F_216 ( V_241 * sizeof( V_334 [ 0 ] ) , V_19 ) ;
F_257 ( ! V_334 ) ;
F_245 (node)
F_257 ( ! F_377 ( & V_334 [ V_24 ] , V_19 ,
F_378 ( V_24 ) ? V_24 : V_25 ) ) ;
F_280 (cpu) {
V_24 = F_112 ( V_56 ) ;
if ( F_115 ( V_24 == V_25 ) ) {
F_103 ( L_51 , V_56 ) ;
return;
}
F_379 ( V_56 , V_334 [ V_24 ] ) ;
}
V_223 = V_334 ;
V_222 = true ;
}
int T_11 F_380 ( void )
{
int V_336 [ V_337 ] = { 0 , V_338 } ;
int V_271 , V_56 ;
F_115 ( F_381 ( struct V_21 ) < F_381 (long long) ) ;
F_257 ( ! F_217 ( & V_96 , V_19 ) ) ;
F_218 ( V_96 , V_208 ) ;
V_225 = F_382 ( V_21 , V_339 ) ;
F_280 (cpu) {
struct V_13 * V_14 ;
V_271 = 0 ;
F_318 (pool, cpu) {
F_257 ( F_227 ( V_14 ) ) ;
V_14 -> V_56 = V_56 ;
F_218 ( V_14 -> V_125 -> V_126 , F_383 ( V_56 ) ) ;
V_14 -> V_125 -> V_134 = V_336 [ V_271 ++ ] ;
V_14 -> V_24 = F_112 ( V_56 ) ;
F_132 ( & V_16 ) ;
F_257 ( F_19 ( V_14 ) ) ;
F_134 ( & V_16 ) ;
}
}
for ( V_271 = 0 ; V_271 < V_337 ; V_271 ++ ) {
struct V_206 * V_125 ;
F_257 ( ! ( V_125 = F_215 ( V_19 ) ) ) ;
V_125 -> V_134 = V_336 [ V_271 ] ;
V_256 [ V_271 ] = V_125 ;
F_257 ( ! ( V_125 = F_215 ( V_19 ) ) ) ;
V_125 -> V_134 = V_336 [ V_271 ] ;
V_125 -> V_211 = true ;
V_255 [ V_271 ] = V_125 ;
}
V_333 = F_384 ( L_52 , 0 , 0 ) ;
V_288 = F_384 ( L_53 , V_252 , 0 ) ;
V_340 = F_384 ( L_54 , 0 , 0 ) ;
V_341 = F_384 ( L_55 , V_70 ,
V_258 ) ;
V_342 = F_384 ( L_56 ,
V_230 , 0 ) ;
V_343 = F_384 ( L_57 ,
V_264 , 0 ) ;
V_344 = F_384 ( L_58 ,
V_230 | V_264 ,
0 ) ;
F_257 ( ! V_333 || ! V_288 || ! V_340 ||
! V_341 || ! V_342 ||
! V_343 ||
! V_344 ) ;
return 0 ;
}
int T_11 F_385 ( void )
{
struct V_22 * V_23 ;
struct V_13 * V_14 ;
int V_56 , V_282 ;
F_375 () ;
F_132 ( & V_16 ) ;
F_280 (cpu) {
F_318 (pool, cpu) {
V_14 -> V_24 = F_112 ( V_56 ) ;
}
}
F_151 (wq, &workqueues, list)
F_278 ( V_23 , F_299 () , true ) ;
F_134 ( & V_16 ) ;
F_206 (cpu) {
F_318 (pool, cpu) {
V_14 -> V_33 &= ~ V_121 ;
F_257 ( ! F_137 ( V_14 ) ) ;
}
}
F_313 (unbound_pool_hash, bkt, pool, hash_node)
F_257 ( ! F_137 ( V_14 ) ) ;
V_182 = true ;
F_374 () ;
return 0 ;
}
