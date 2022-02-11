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
bool V_46 = F_56 ( & V_14 -> V_47 ) ;
int V_45 = V_14 -> V_45 + V_46 ;
int V_48 = V_14 -> V_49 - V_45 ;
return V_45 > 2 && ( V_45 - 2 ) * V_50 >= V_48 ;
}
static struct V_51 * F_57 ( struct V_13 * V_14 )
{
if ( F_24 ( F_51 ( & V_14 -> V_52 ) ) )
return NULL ;
return F_58 ( & V_14 -> V_52 , struct V_51 , V_53 ) ;
}
static void F_59 ( struct V_13 * V_14 )
{
struct V_51 * V_51 = F_57 ( V_14 ) ;
if ( F_60 ( V_51 ) )
F_61 ( V_51 -> V_54 ) ;
}
void F_62 ( struct V_55 * V_54 , int V_56 )
{
struct V_51 * V_51 = F_63 ( V_54 ) ;
if ( ! ( V_51 -> V_33 & V_57 ) ) {
F_30 ( V_51 -> V_14 -> V_56 != V_56 ) ;
F_64 ( & V_51 -> V_14 -> V_43 ) ;
}
}
struct V_55 * F_65 ( struct V_55 * V_54 )
{
struct V_51 * V_51 = F_63 ( V_54 ) , * V_58 = NULL ;
struct V_13 * V_14 ;
if ( V_51 -> V_33 & V_57 )
return NULL ;
V_14 = V_51 -> V_14 ;
if ( F_30 ( V_14 -> V_56 != F_66 () ) )
return NULL ;
if ( F_67 ( & V_14 -> V_43 ) &&
! F_51 ( & V_14 -> V_44 ) )
V_58 = F_57 ( V_14 ) ;
return V_58 ? V_58 -> V_54 : NULL ;
}
static inline void F_68 ( struct V_51 * V_51 , unsigned int V_33 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
F_30 ( V_51 -> V_54 != V_59 ) ;
if ( ( V_33 & V_57 ) &&
! ( V_51 -> V_33 & V_57 ) ) {
F_69 ( & V_14 -> V_43 ) ;
}
V_51 -> V_33 |= V_33 ;
}
static inline void F_70 ( struct V_51 * V_51 , unsigned int V_33 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
unsigned int V_60 = V_51 -> V_33 ;
F_30 ( V_51 -> V_54 != V_59 ) ;
V_51 -> V_33 &= ~ V_33 ;
if ( ( V_33 & V_57 ) && ( V_60 & V_57 ) )
if ( ! ( V_51 -> V_33 & V_57 ) )
F_64 ( & V_14 -> V_43 ) ;
}
static struct V_51 * F_71 ( struct V_13 * V_14 ,
struct V_2 * V_4 )
{
struct V_51 * V_51 ;
F_72 (pool->busy_hash, worker, hentry,
(unsigned long)work)
if ( V_51 -> V_61 == V_4 &&
V_51 -> V_62 == V_4 -> V_3 )
return V_51 ;
return NULL ;
}
static void F_73 ( struct V_2 * V_4 , struct V_63 * V_64 ,
struct V_2 * * V_65 )
{
struct V_2 * V_66 ;
F_74 (work, n, NULL, entry) {
F_75 ( & V_4 -> V_53 , V_64 ) ;
if ( ! ( * F_4 ( V_4 ) & V_67 ) )
break;
}
if ( V_65 )
* V_65 = V_66 ;
}
static void F_76 ( struct V_21 * V_34 )
{
F_20 ( & V_34 -> V_14 -> V_68 ) ;
F_30 ( V_34 -> V_69 <= 0 ) ;
V_34 -> V_69 ++ ;
}
static void F_77 ( struct V_21 * V_34 )
{
F_20 ( & V_34 -> V_14 -> V_68 ) ;
if ( F_60 ( -- V_34 -> V_69 ) )
return;
if ( F_30 ( ! ( V_34 -> V_23 -> V_33 & V_70 ) ) )
return;
F_78 ( & V_34 -> V_71 ) ;
}
static void F_79 ( struct V_21 * V_34 )
{
if ( V_34 ) {
F_80 ( & V_34 -> V_14 -> V_68 ) ;
F_77 ( V_34 ) ;
F_81 ( & V_34 -> V_14 -> V_68 ) ;
}
}
static void F_82 ( struct V_2 * V_4 )
{
struct V_21 * V_34 = F_40 ( V_4 ) ;
F_83 ( V_4 ) ;
if ( F_51 ( & V_34 -> V_14 -> V_44 ) )
V_34 -> V_14 -> V_72 = V_73 ;
F_73 ( V_4 , & V_34 -> V_14 -> V_44 , NULL ) ;
F_84 ( V_74 , F_4 ( V_4 ) ) ;
V_34 -> V_75 ++ ;
}
static void F_85 ( struct V_21 * V_34 )
{
struct V_2 * V_4 = F_58 ( & V_34 -> V_76 ,
struct V_2 , V_53 ) ;
F_82 ( V_4 ) ;
}
static void F_86 ( struct V_21 * V_34 , int V_28 )
{
if ( V_28 == V_77 )
goto V_78;
V_34 -> V_79 [ V_28 ] -- ;
V_34 -> V_75 -- ;
if ( ! F_51 ( & V_34 -> V_76 ) ) {
if ( V_34 -> V_75 < V_34 -> V_80 )
F_85 ( V_34 ) ;
}
if ( F_60 ( V_34 -> V_81 != V_28 ) )
goto V_78;
if ( V_34 -> V_79 [ V_28 ] )
goto V_78;
V_34 -> V_81 = - 1 ;
if ( F_67 ( & V_34 -> V_23 -> V_82 ) )
F_87 ( & V_34 -> V_23 -> V_83 -> V_84 ) ;
V_78:
F_77 ( V_34 ) ;
}
static int F_88 ( struct V_2 * V_4 , bool V_85 ,
unsigned long * V_33 )
{
struct V_13 * V_14 ;
struct V_21 * V_34 ;
F_89 ( * V_33 ) ;
if ( V_85 ) {
struct V_11 * V_86 = F_90 ( V_4 ) ;
if ( F_60 ( F_91 ( & V_86 -> V_12 ) ) )
return 1 ;
}
if ( ! F_92 ( V_87 , F_4 ( V_4 ) ) )
return 0 ;
V_14 = F_42 ( V_4 ) ;
if ( ! V_14 )
goto V_88;
F_93 ( & V_14 -> V_68 ) ;
V_34 = F_40 ( V_4 ) ;
if ( V_34 && V_34 -> V_14 == V_14 ) {
F_12 ( V_4 ) ;
if ( * F_4 ( V_4 ) & V_89 )
F_82 ( V_4 ) ;
F_94 ( & V_4 -> V_53 ) ;
F_86 ( V_34 , F_27 ( V_4 ) ) ;
F_35 ( V_4 , V_14 -> V_20 ) ;
F_95 ( & V_14 -> V_68 ) ;
return 1 ;
}
F_95 ( & V_14 -> V_68 ) ;
V_88:
F_96 ( * V_33 ) ;
if ( F_47 ( V_4 ) )
return - V_90 ;
F_97 () ;
return - V_91 ;
}
static void F_98 ( struct V_21 * V_34 , struct V_2 * V_4 ,
struct V_63 * V_64 , unsigned int V_35 )
{
struct V_13 * V_14 = V_34 -> V_14 ;
F_34 ( V_4 , V_34 , V_35 ) ;
F_99 ( & V_4 -> V_53 , V_64 ) ;
F_76 ( V_34 ) ;
F_38 () ;
if ( F_48 ( V_14 ) )
F_59 ( V_14 ) ;
}
static bool F_100 ( struct V_22 * V_23 )
{
struct V_51 * V_51 ;
V_51 = F_101 () ;
return V_51 && V_51 -> V_92 -> V_23 == V_23 ;
}
static int F_102 ( int V_56 )
{
static bool V_93 ;
int V_94 ;
if ( F_60 ( ! V_95 ) ) {
if ( F_103 ( V_56 , V_96 ) )
return V_56 ;
} else if ( ! V_93 ) {
F_104 ( L_1 ) ;
V_93 = true ;
}
if ( F_105 ( V_96 ) )
return V_56 ;
V_94 = F_106 ( V_97 ) ;
V_94 = F_107 ( V_94 , V_96 , V_98 ) ;
if ( F_24 ( V_94 >= V_99 ) ) {
V_94 = F_108 ( V_96 , V_98 ) ;
if ( F_24 ( V_94 >= V_99 ) )
return V_56 ;
}
F_109 ( V_97 , V_94 ) ;
return V_94 ;
}
static void F_110 ( int V_56 , struct V_22 * V_23 ,
struct V_2 * V_4 )
{
struct V_21 * V_34 ;
struct V_13 * V_100 ;
struct V_63 * V_44 ;
unsigned int V_101 ;
unsigned int V_102 = V_56 ;
F_30 ( ! F_111 () ) ;
F_10 ( V_4 ) ;
if ( F_24 ( V_23 -> V_33 & V_103 ) &&
F_30 ( ! F_100 ( V_23 ) ) )
return;
V_104:
if ( V_102 == V_105 )
V_56 = F_102 ( F_66 () ) ;
if ( ! ( V_23 -> V_33 & V_70 ) )
V_34 = F_112 ( V_23 -> V_106 , V_56 ) ;
else
V_34 = F_22 ( V_23 , F_113 ( V_56 ) ) ;
V_100 = F_42 ( V_4 ) ;
if ( V_100 && V_100 != V_34 -> V_14 ) {
struct V_51 * V_51 ;
F_93 ( & V_100 -> V_68 ) ;
V_51 = F_71 ( V_100 , V_4 ) ;
if ( V_51 && V_51 -> V_92 -> V_23 == V_23 ) {
V_34 = V_51 -> V_92 ;
} else {
F_95 ( & V_100 -> V_68 ) ;
F_93 ( & V_34 -> V_14 -> V_68 ) ;
}
} else {
F_93 ( & V_34 -> V_14 -> V_68 ) ;
}
if ( F_24 ( ! V_34 -> V_69 ) ) {
if ( V_23 -> V_33 & V_70 ) {
F_95 ( & V_34 -> V_14 -> V_68 ) ;
F_97 () ;
goto V_104;
}
F_114 ( true , L_2 ,
V_23 -> V_107 , V_56 ) ;
}
F_115 ( V_102 , V_34 , V_4 ) ;
if ( F_116 ( ! F_51 ( & V_4 -> V_53 ) ) ) {
F_95 ( & V_34 -> V_14 -> V_68 ) ;
return;
}
V_34 -> V_79 [ V_34 -> V_108 ] ++ ;
V_101 = F_26 ( V_34 -> V_108 ) ;
if ( F_60 ( V_34 -> V_75 < V_34 -> V_80 ) ) {
F_83 ( V_4 ) ;
V_34 -> V_75 ++ ;
V_44 = & V_34 -> V_14 -> V_44 ;
if ( F_51 ( V_44 ) )
V_34 -> V_14 -> V_72 = V_73 ;
} else {
V_101 |= V_89 ;
V_44 = & V_34 -> V_76 ;
}
F_98 ( V_34 , V_4 , V_44 , V_101 ) ;
F_95 ( & V_34 -> V_14 -> V_68 ) ;
}
bool F_117 ( int V_56 , struct V_22 * V_23 ,
struct V_2 * V_4 )
{
bool V_15 = false ;
unsigned long V_33 ;
F_89 ( V_33 ) ;
if ( ! F_92 ( V_87 , F_4 ( V_4 ) ) ) {
F_110 ( V_56 , V_23 , V_4 ) ;
V_15 = true ;
}
F_96 ( V_33 ) ;
return V_15 ;
}
void F_118 ( unsigned long V_109 )
{
struct V_11 * V_86 = (struct V_11 * ) V_109 ;
F_110 ( V_86 -> V_56 , V_86 -> V_23 , & V_86 -> V_4 ) ;
}
static void F_119 ( int V_56 , struct V_22 * V_23 ,
struct V_11 * V_86 , unsigned long V_110 )
{
struct V_111 * V_12 = & V_86 -> V_12 ;
struct V_2 * V_4 = & V_86 -> V_4 ;
F_30 ( ! V_23 ) ;
F_30 ( V_12 -> V_112 != F_118 ||
V_12 -> V_32 != ( unsigned long ) V_86 ) ;
F_30 ( F_120 ( V_12 ) ) ;
F_30 ( ! F_51 ( & V_4 -> V_53 ) ) ;
if ( ! V_110 ) {
F_110 ( V_56 , V_23 , & V_86 -> V_4 ) ;
return;
}
V_86 -> V_23 = V_23 ;
V_86 -> V_56 = V_56 ;
V_12 -> V_113 = V_73 + V_110 ;
if ( F_24 ( V_56 != V_105 ) )
F_121 ( V_12 , V_56 ) ;
else
F_122 ( V_12 ) ;
}
bool F_123 ( int V_56 , struct V_22 * V_23 ,
struct V_11 * V_86 , unsigned long V_110 )
{
struct V_2 * V_4 = & V_86 -> V_4 ;
bool V_15 = false ;
unsigned long V_33 ;
F_89 ( V_33 ) ;
if ( ! F_92 ( V_87 , F_4 ( V_4 ) ) ) {
F_119 ( V_56 , V_23 , V_86 , V_110 ) ;
V_15 = true ;
}
F_96 ( V_33 ) ;
return V_15 ;
}
bool F_124 ( int V_56 , struct V_22 * V_23 ,
struct V_11 * V_86 , unsigned long V_110 )
{
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_88 ( & V_86 -> V_4 , true , & V_33 ) ;
} while ( F_24 ( V_15 == - V_91 ) );
if ( F_60 ( V_15 >= 0 ) ) {
F_119 ( V_56 , V_23 , V_86 , V_110 ) ;
F_96 ( V_33 ) ;
}
return V_15 ;
}
static void F_125 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( F_30 ( V_51 -> V_33 & V_114 ) ||
F_30 ( ! F_51 ( & V_51 -> V_53 ) &&
( V_51 -> V_115 . V_116 || V_51 -> V_115 . V_117 ) ) )
return;
V_51 -> V_33 |= V_114 ;
V_14 -> V_45 ++ ;
V_51 -> V_118 = V_73 ;
F_126 ( & V_51 -> V_53 , & V_14 -> V_52 ) ;
if ( F_55 ( V_14 ) && ! F_120 ( & V_14 -> V_119 ) )
F_127 ( & V_14 -> V_119 , V_73 + V_120 ) ;
F_30 ( ! ( V_14 -> V_33 & V_121 ) &&
V_14 -> V_49 == V_14 -> V_45 &&
F_49 ( & V_14 -> V_43 ) ) ;
}
static void F_128 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( F_30 ( ! ( V_51 -> V_33 & V_114 ) ) )
return;
F_70 ( V_51 , V_114 ) ;
V_14 -> V_45 -- ;
F_94 ( & V_51 -> V_53 ) ;
}
static struct V_51 * F_129 ( int V_24 )
{
struct V_51 * V_51 ;
V_51 = F_130 ( sizeof( * V_51 ) , V_19 , V_24 ) ;
if ( V_51 ) {
F_131 ( & V_51 -> V_53 ) ;
F_131 ( & V_51 -> V_122 ) ;
F_131 ( & V_51 -> V_24 ) ;
V_51 -> V_33 = V_123 ;
}
return V_51 ;
}
static void F_132 ( struct V_51 * V_51 ,
struct V_13 * V_14 )
{
F_133 ( & V_14 -> V_124 ) ;
F_134 ( V_51 -> V_54 , V_14 -> V_125 -> V_126 ) ;
if ( V_14 -> V_33 & V_121 )
V_51 -> V_33 |= V_127 ;
F_99 ( & V_51 -> V_24 , & V_14 -> V_128 ) ;
F_135 ( & V_14 -> V_124 ) ;
}
static void F_136 ( struct V_51 * V_51 ,
struct V_13 * V_14 )
{
struct V_129 * V_130 = NULL ;
F_133 ( & V_14 -> V_124 ) ;
F_137 ( & V_51 -> V_24 ) ;
if ( F_51 ( & V_14 -> V_128 ) )
V_130 = V_14 -> V_130 ;
F_135 ( & V_14 -> V_124 ) ;
V_51 -> V_33 &= ~ ( V_127 | V_131 ) ;
if ( V_130 )
F_87 ( V_130 ) ;
}
static struct V_51 * F_138 ( struct V_13 * V_14 )
{
struct V_51 * V_51 = NULL ;
int V_20 = - 1 ;
char V_132 [ 16 ] ;
V_20 = F_139 ( & V_14 -> V_133 , 0 , 0 , V_19 ) ;
if ( V_20 < 0 )
goto V_88;
V_51 = F_129 ( V_14 -> V_24 ) ;
if ( ! V_51 )
goto V_88;
V_51 -> V_14 = V_14 ;
V_51 -> V_20 = V_20 ;
if ( V_14 -> V_56 >= 0 )
snprintf ( V_132 , sizeof( V_132 ) , L_3 , V_14 -> V_56 , V_20 ,
V_14 -> V_125 -> V_134 < 0 ? L_4 : L_5 ) ;
else
snprintf ( V_132 , sizeof( V_132 ) , L_6 , V_14 -> V_20 , V_20 ) ;
V_51 -> V_54 = F_140 ( V_135 , V_51 , V_14 -> V_24 ,
L_7 , V_132 ) ;
if ( F_141 ( V_51 -> V_54 ) )
goto V_88;
F_142 ( V_51 -> V_54 , V_14 -> V_125 -> V_134 ) ;
F_143 ( V_51 -> V_54 , V_14 -> V_125 -> V_126 ) ;
F_132 ( V_51 , V_14 ) ;
F_80 ( & V_14 -> V_68 ) ;
V_51 -> V_14 -> V_49 ++ ;
F_125 ( V_51 ) ;
F_61 ( V_51 -> V_54 ) ;
F_81 ( & V_14 -> V_68 ) ;
return V_51 ;
V_88:
if ( V_20 >= 0 )
F_144 ( & V_14 -> V_133 , V_20 ) ;
F_145 ( V_51 ) ;
return NULL ;
}
static void F_146 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
F_20 ( & V_14 -> V_68 ) ;
if ( F_116 ( V_51 -> V_61 ) ||
F_116 ( ! F_51 ( & V_51 -> V_122 ) ) ||
F_116 ( ! ( V_51 -> V_33 & V_114 ) ) )
return;
V_14 -> V_49 -- ;
V_14 -> V_45 -- ;
F_94 ( & V_51 -> V_53 ) ;
V_51 -> V_33 |= V_136 ;
F_61 ( V_51 -> V_54 ) ;
}
static void F_147 ( unsigned long V_137 )
{
struct V_13 * V_14 = ( void * ) V_137 ;
F_80 ( & V_14 -> V_68 ) ;
while ( F_55 ( V_14 ) ) {
struct V_51 * V_51 ;
unsigned long V_113 ;
V_51 = F_148 ( V_14 -> V_52 . V_138 , struct V_51 , V_53 ) ;
V_113 = V_51 -> V_118 + V_120 ;
if ( F_149 ( V_73 , V_113 ) ) {
F_127 ( & V_14 -> V_119 , V_113 ) ;
break;
}
F_146 ( V_51 ) ;
}
F_81 ( & V_14 -> V_68 ) ;
}
static void F_150 ( struct V_2 * V_4 )
{
struct V_21 * V_34 = F_40 ( V_4 ) ;
struct V_22 * V_23 = V_34 -> V_23 ;
F_20 ( & V_139 ) ;
if ( ! V_23 -> V_140 )
return;
if ( F_51 ( & V_34 -> V_141 ) ) {
F_76 ( V_34 ) ;
F_99 ( & V_34 -> V_141 , & V_23 -> V_142 ) ;
F_61 ( V_23 -> V_140 -> V_54 ) ;
}
}
static void F_151 ( unsigned long V_137 )
{
struct V_13 * V_14 = ( void * ) V_137 ;
struct V_2 * V_4 ;
F_80 ( & V_14 -> V_68 ) ;
F_93 ( & V_139 ) ;
if ( F_54 ( V_14 ) ) {
F_152 (work, &pool->worklist, entry)
F_150 ( V_4 ) ;
}
F_95 ( & V_139 ) ;
F_81 ( & V_14 -> V_68 ) ;
F_127 ( & V_14 -> V_143 , V_73 + V_144 ) ;
}
static void F_153 ( struct V_13 * V_14 )
__releases( &pool->lock
static bool F_154 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( ! F_155 ( & V_14 -> V_47 ) )
return false ;
V_14 -> V_145 = V_51 ;
F_153 ( V_14 ) ;
V_14 -> V_145 = NULL ;
F_135 ( & V_14 -> V_47 ) ;
return true ;
}
static void F_156 ( struct V_51 * V_51 , struct V_2 * V_4 )
__releases( &pool->lock
static void F_157 ( struct V_51 * V_51 )
{
while ( ! F_51 ( & V_51 -> V_122 ) ) {
struct V_2 * V_4 = F_58 ( & V_51 -> V_122 ,
struct V_2 , V_53 ) ;
F_156 ( V_51 , V_4 ) ;
}
}
static int V_135 ( void * V_146 )
{
struct V_51 * V_51 = V_146 ;
struct V_13 * V_14 = V_51 -> V_14 ;
V_51 -> V_54 -> V_33 |= V_147 ;
V_148:
F_80 ( & V_14 -> V_68 ) ;
if ( F_24 ( V_51 -> V_33 & V_136 ) ) {
F_81 ( & V_14 -> V_68 ) ;
F_30 ( ! F_51 ( & V_51 -> V_53 ) ) ;
V_51 -> V_54 -> V_33 &= ~ V_147 ;
F_158 ( V_51 -> V_54 , L_8 ) ;
F_144 ( & V_14 -> V_133 , V_51 -> V_20 ) ;
F_136 ( V_51 , V_14 ) ;
F_145 ( V_51 ) ;
return 0 ;
}
F_128 ( V_51 ) ;
V_149:
if ( ! F_50 ( V_14 ) )
goto V_150;
if ( F_24 ( ! F_52 ( V_14 ) ) && F_154 ( V_51 ) )
goto V_149;
F_30 ( ! F_51 ( & V_51 -> V_122 ) ) ;
F_70 ( V_51 , V_123 | V_131 ) ;
do {
struct V_2 * V_4 =
F_58 ( & V_14 -> V_44 ,
struct V_2 , V_53 ) ;
V_14 -> V_72 = V_73 ;
if ( F_60 ( ! ( * F_4 ( V_4 ) & V_67 ) ) ) {
F_156 ( V_51 , V_4 ) ;
if ( F_24 ( ! F_51 ( & V_51 -> V_122 ) ) )
F_157 ( V_51 ) ;
} else {
F_73 ( V_4 , & V_51 -> V_122 , NULL ) ;
F_157 ( V_51 ) ;
}
} while ( F_53 ( V_14 ) );
F_68 ( V_51 , V_123 ) ;
V_150:
F_125 ( V_51 ) ;
F_159 ( V_151 ) ;
F_81 ( & V_14 -> V_68 ) ;
F_160 () ;
goto V_148;
}
static int F_161 ( void * V_152 )
{
struct V_51 * V_140 = V_152 ;
struct V_22 * V_23 = V_140 -> V_153 ;
struct V_63 * V_122 = & V_140 -> V_122 ;
bool V_154 ;
F_142 ( V_59 , V_155 ) ;
V_140 -> V_54 -> V_33 |= V_147 ;
V_156:
F_162 ( V_151 ) ;
V_154 = F_163 () ;
F_80 ( & V_139 ) ;
while ( ! F_51 ( & V_23 -> V_142 ) ) {
struct V_21 * V_34 = F_58 ( & V_23 -> V_142 ,
struct V_21 , V_141 ) ;
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_2 * V_4 , * V_66 ;
bool V_157 = true ;
F_159 ( V_158 ) ;
F_94 ( & V_34 -> V_141 ) ;
F_81 ( & V_139 ) ;
F_132 ( V_140 , V_14 ) ;
F_80 ( & V_14 -> V_68 ) ;
V_140 -> V_14 = V_14 ;
F_30 ( ! F_51 ( V_122 ) ) ;
F_164 (work, n, &pool->worklist, entry) {
if ( F_40 ( V_4 ) == V_34 ) {
if ( V_157 )
V_14 -> V_72 = V_73 ;
F_73 ( V_4 , V_122 , & V_66 ) ;
}
V_157 = false ;
}
if ( ! F_51 ( V_122 ) ) {
F_157 ( V_140 ) ;
if ( F_54 ( V_14 ) ) {
F_93 ( & V_139 ) ;
F_76 ( V_34 ) ;
F_75 ( & V_34 -> V_141 , & V_23 -> V_142 ) ;
F_95 ( & V_139 ) ;
}
}
F_77 ( V_34 ) ;
if ( F_50 ( V_14 ) )
F_59 ( V_14 ) ;
V_140 -> V_14 = NULL ;
F_81 ( & V_14 -> V_68 ) ;
F_136 ( V_140 , V_14 ) ;
F_80 ( & V_139 ) ;
}
F_81 ( & V_139 ) ;
if ( V_154 ) {
F_159 ( V_158 ) ;
V_140 -> V_54 -> V_33 &= ~ V_147 ;
return 0 ;
}
F_30 ( ! ( V_140 -> V_33 & V_57 ) ) ;
F_160 () ;
goto V_156;
}
static void F_165 ( struct V_22 * V_159 ,
struct V_2 * V_160 )
{
T_1 V_161 = V_160 ? V_160 -> V_3 : NULL ;
struct V_51 * V_51 ;
if ( V_159 -> V_33 & V_162 )
return;
V_51 = F_101 () ;
F_114 ( V_59 -> V_33 & V_163 ,
L_9 ,
V_59 -> V_164 , V_59 -> V_165 , V_159 -> V_107 , V_161 ) ;
F_114 ( V_51 && ( ( V_51 -> V_92 -> V_23 -> V_33 &
( V_162 | V_166 ) ) == V_162 ) ,
L_10 ,
V_51 -> V_92 -> V_23 -> V_107 , V_51 -> V_62 ,
V_159 -> V_107 , V_161 ) ;
}
static void F_166 ( struct V_2 * V_4 )
{
struct V_167 * V_168 = F_167 ( V_4 , struct V_167 , V_4 ) ;
F_87 ( & V_168 -> V_84 ) ;
}
static void F_168 ( struct V_21 * V_34 ,
struct V_167 * V_168 ,
struct V_2 * V_169 , struct V_51 * V_51 )
{
struct V_63 * V_64 ;
unsigned int V_170 = 0 ;
F_169 ( & V_168 -> V_4 , F_166 ) ;
F_170 ( V_87 , F_4 ( & V_168 -> V_4 ) ) ;
F_171 ( & V_168 -> V_84 ) ;
V_168 -> V_54 = V_59 ;
if ( V_51 )
V_64 = V_51 -> V_122 . V_116 ;
else {
unsigned long * V_171 = F_4 ( V_169 ) ;
V_64 = V_169 -> V_53 . V_116 ;
V_170 = * V_171 & V_67 ;
F_170 ( V_172 , V_171 ) ;
}
F_10 ( & V_168 -> V_4 ) ;
F_98 ( V_34 , & V_168 -> V_4 , V_64 ,
F_26 ( V_77 ) | V_170 ) ;
}
static bool F_172 ( struct V_22 * V_23 ,
int V_81 , int V_108 )
{
bool V_173 = false ;
struct V_21 * V_34 ;
if ( V_81 >= 0 ) {
F_30 ( F_49 ( & V_23 -> V_82 ) ) ;
F_173 ( & V_23 -> V_82 , 1 ) ;
}
F_174 (pwq, wq) {
struct V_13 * V_14 = V_34 -> V_14 ;
F_80 ( & V_14 -> V_68 ) ;
if ( V_81 >= 0 ) {
F_30 ( V_34 -> V_81 != - 1 ) ;
if ( V_34 -> V_79 [ V_81 ] ) {
V_34 -> V_81 = V_81 ;
F_64 ( & V_23 -> V_82 ) ;
V_173 = true ;
}
}
if ( V_108 >= 0 ) {
F_30 ( V_108 != F_28 ( V_34 -> V_108 ) ) ;
V_34 -> V_108 = V_108 ;
}
F_81 ( & V_14 -> V_68 ) ;
}
if ( V_81 >= 0 && F_67 ( & V_23 -> V_82 ) )
F_87 ( & V_23 -> V_83 -> V_84 ) ;
return V_173 ;
}
void F_175 ( struct V_22 * V_23 )
{
struct V_174 V_175 = {
. V_176 = F_176 ( V_175 . V_176 ) ,
. V_81 = - 1 ,
. V_84 = F_177 ( V_175 . V_84 ) ,
} ;
int V_177 ;
if ( F_116 ( ! V_178 ) )
return;
F_178 ( & V_23 -> V_179 ) ;
F_179 ( & V_23 -> V_179 ) ;
F_133 ( & V_23 -> V_180 ) ;
V_177 = F_28 ( V_23 -> V_108 ) ;
if ( V_177 != V_23 -> V_81 ) {
F_30 ( ! F_51 ( & V_23 -> V_181 ) ) ;
V_175 . V_81 = V_23 -> V_108 ;
V_23 -> V_108 = V_177 ;
if ( ! V_23 -> V_83 ) {
F_30 ( V_23 -> V_81 != V_175 . V_81 ) ;
V_23 -> V_83 = & V_175 ;
if ( ! F_172 ( V_23 , V_23 -> V_81 ,
V_23 -> V_108 ) ) {
V_23 -> V_81 = V_177 ;
V_23 -> V_83 = NULL ;
goto V_182;
}
} else {
F_30 ( V_23 -> V_81 == V_175 . V_81 ) ;
F_99 ( & V_175 . V_176 , & V_23 -> V_183 ) ;
F_172 ( V_23 , - 1 , V_23 -> V_108 ) ;
}
} else {
F_99 ( & V_175 . V_176 , & V_23 -> V_181 ) ;
}
F_165 ( V_23 , NULL ) ;
F_135 ( & V_23 -> V_180 ) ;
F_180 ( & V_175 . V_84 ) ;
if ( V_23 -> V_83 != & V_175 )
return;
F_133 ( & V_23 -> V_180 ) ;
if ( V_23 -> V_83 != & V_175 )
goto V_182;
V_23 -> V_83 = NULL ;
F_30 ( ! F_51 ( & V_175 . V_176 ) ) ;
F_30 ( V_23 -> V_81 != V_175 . V_81 ) ;
while ( true ) {
struct V_174 * V_116 , * V_184 ;
F_164 (next, tmp, &wq->flusher_queue, list) {
if ( V_116 -> V_81 != V_23 -> V_81 )
break;
F_94 ( & V_116 -> V_176 ) ;
F_87 ( & V_116 -> V_84 ) ;
}
F_30 ( ! F_51 ( & V_23 -> V_181 ) &&
V_23 -> V_81 != F_28 ( V_23 -> V_108 ) ) ;
V_23 -> V_81 = F_28 ( V_23 -> V_81 ) ;
if ( ! F_51 ( & V_23 -> V_181 ) ) {
F_152 (tmp, &wq->flusher_overflow, list)
V_184 -> V_81 = V_23 -> V_108 ;
V_23 -> V_108 = F_28 ( V_23 -> V_108 ) ;
F_181 ( & V_23 -> V_181 ,
& V_23 -> V_183 ) ;
F_172 ( V_23 , - 1 , V_23 -> V_108 ) ;
}
if ( F_51 ( & V_23 -> V_183 ) ) {
F_30 ( V_23 -> V_81 != V_23 -> V_108 ) ;
break;
}
F_30 ( V_23 -> V_81 == V_23 -> V_108 ) ;
F_30 ( V_23 -> V_81 != V_116 -> V_81 ) ;
F_94 ( & V_116 -> V_176 ) ;
V_23 -> V_83 = V_116 ;
if ( F_172 ( V_23 , V_23 -> V_81 , - 1 ) )
break;
V_23 -> V_83 = NULL ;
}
V_182:
F_135 ( & V_23 -> V_180 ) ;
}
void F_182 ( struct V_22 * V_23 )
{
unsigned int V_185 = 0 ;
struct V_21 * V_34 ;
F_133 ( & V_23 -> V_180 ) ;
if ( ! V_23 -> V_186 ++ )
V_23 -> V_33 |= V_103 ;
F_135 ( & V_23 -> V_180 ) ;
V_187:
F_175 ( V_23 ) ;
F_133 ( & V_23 -> V_180 ) ;
F_174 (pwq, wq) {
bool V_188 ;
F_80 ( & V_34 -> V_14 -> V_68 ) ;
V_188 = ! V_34 -> V_75 && F_51 ( & V_34 -> V_76 ) ;
F_81 ( & V_34 -> V_14 -> V_68 ) ;
if ( V_188 )
continue;
if ( ++ V_185 == 10 ||
( V_185 % 100 == 0 && V_185 <= 1000 ) )
F_104 ( L_11 ,
V_23 -> V_107 , V_185 ) ;
F_135 ( & V_23 -> V_180 ) ;
goto V_187;
}
if ( ! -- V_23 -> V_186 )
V_23 -> V_33 &= ~ V_103 ;
F_135 ( & V_23 -> V_180 ) ;
}
static bool F_183 ( struct V_2 * V_4 , struct V_167 * V_168 )
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
F_93 ( & V_14 -> V_68 ) ;
V_34 = F_40 ( V_4 ) ;
if ( V_34 ) {
if ( F_24 ( V_34 -> V_14 != V_14 ) )
goto V_189;
} else {
V_51 = F_71 ( V_14 , V_4 ) ;
if ( ! V_51 )
goto V_189;
V_34 = V_51 -> V_92 ;
}
F_165 ( V_34 -> V_23 , V_4 ) ;
F_168 ( V_34 , V_168 , V_4 , V_51 ) ;
F_81 ( & V_14 -> V_68 ) ;
if ( V_34 -> V_23 -> V_190 == 1 || V_34 -> V_23 -> V_140 )
F_178 ( & V_34 -> V_23 -> V_179 ) ;
else
F_187 ( & V_34 -> V_23 -> V_179 ) ;
F_179 ( & V_34 -> V_23 -> V_179 ) ;
return true ;
V_189:
F_81 ( & V_14 -> V_68 ) ;
return false ;
}
bool F_188 ( struct V_2 * V_4 )
{
struct V_167 V_168 ;
if ( F_116 ( ! V_178 ) )
return false ;
F_178 ( & V_4 -> V_179 ) ;
F_179 ( & V_4 -> V_179 ) ;
if ( F_183 ( V_4 , & V_168 ) ) {
F_180 ( & V_168 . V_84 ) ;
F_16 ( & V_168 . V_4 ) ;
return true ;
} else {
return false ;
}
}
static int F_189 ( T_2 * V_173 , unsigned V_191 , int V_192 , void * V_193 )
{
struct V_194 * V_195 = F_167 ( V_173 , struct V_194 , V_173 ) ;
if ( V_195 -> V_4 != V_193 )
return 0 ;
return F_190 ( V_173 , V_191 , V_192 , V_193 ) ;
}
static bool F_191 ( struct V_2 * V_4 , bool V_85 )
{
static F_192 ( V_196 ) ;
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_88 ( V_4 , V_85 , & V_33 ) ;
if ( F_24 ( V_15 == - V_90 ) ) {
struct V_194 V_195 ;
F_193 ( & V_195 . V_173 ) ;
V_195 . V_173 . V_3 = F_189 ;
V_195 . V_4 = V_4 ;
F_194 ( & V_196 , & V_195 . V_173 ,
V_197 ) ;
if ( F_47 ( V_4 ) )
F_160 () ;
F_195 ( & V_196 , & V_195 . V_173 ) ;
}
} while ( F_24 ( V_15 < 0 ) );
F_46 ( V_4 ) ;
F_96 ( V_33 ) ;
if ( V_178 )
F_188 ( V_4 ) ;
F_39 ( V_4 ) ;
F_38 () ;
if ( F_196 ( & V_196 ) )
F_197 ( & V_196 , V_198 , 1 , V_4 ) ;
return V_15 ;
}
bool F_6 ( struct V_2 * V_4 )
{
return F_191 ( V_4 , false ) ;
}
bool F_198 ( struct V_11 * V_86 )
{
F_185 () ;
if ( F_199 ( & V_86 -> V_12 ) )
F_110 ( V_86 -> V_56 , V_86 -> V_23 , & V_86 -> V_4 ) ;
F_186 () ;
return F_188 ( & V_86 -> V_4 ) ;
}
static bool F_200 ( struct V_2 * V_4 , bool V_85 )
{
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_88 ( V_4 , V_85 , & V_33 ) ;
} while ( F_24 ( V_15 == - V_91 ) );
if ( F_24 ( V_15 < 0 ) )
return false ;
F_36 ( V_4 , F_45 ( V_4 ) ) ;
F_96 ( V_33 ) ;
return V_15 ;
}
bool F_201 ( struct V_2 * V_4 )
{
return F_200 ( V_4 , false ) ;
}
bool F_202 ( struct V_11 * V_86 )
{
return F_200 ( & V_86 -> V_4 , true ) ;
}
bool F_203 ( struct V_11 * V_86 )
{
return F_191 ( & V_86 -> V_4 , true ) ;
}
int F_204 ( T_1 V_3 )
{
int V_56 ;
struct V_2 T_3 * V_199 ;
V_199 = F_205 ( struct V_2 ) ;
if ( ! V_199 )
return - V_200 ;
F_206 () ;
F_207 (cpu) {
struct V_2 * V_4 = F_112 ( V_199 , V_56 ) ;
F_208 ( V_4 , V_3 ) ;
F_209 ( V_56 , V_4 ) ;
}
F_207 (cpu)
F_188 ( F_112 ( V_199 , V_56 ) ) ;
F_210 () ;
F_211 ( V_199 ) ;
return 0 ;
}
int F_212 ( T_1 V_201 , struct V_202 * V_203 )
{
if ( ! F_213 () ) {
V_201 ( & V_203 -> V_4 ) ;
return 0 ;
}
F_208 ( & V_203 -> V_4 , V_201 ) ;
F_78 ( & V_203 -> V_4 ) ;
return 1 ;
}
void F_214 ( struct V_204 * V_125 )
{
if ( V_125 ) {
F_215 ( V_125 -> V_126 ) ;
F_145 ( V_125 ) ;
}
}
struct V_204 * F_216 ( T_4 V_205 )
{
struct V_204 * V_125 ;
V_125 = F_217 ( sizeof( * V_125 ) , V_205 ) ;
if ( ! V_125 )
goto V_88;
if ( ! F_218 ( & V_125 -> V_126 , V_205 ) )
goto V_88;
F_219 ( V_125 -> V_126 , V_206 ) ;
return V_125 ;
V_88:
F_214 ( V_125 ) ;
return NULL ;
}
static void F_220 ( struct V_204 * V_207 ,
const struct V_204 * V_208 )
{
V_207 -> V_134 = V_208 -> V_134 ;
F_219 ( V_207 -> V_126 , V_208 -> V_126 ) ;
V_207 -> V_209 = V_208 -> V_209 ;
}
static T_5 F_221 ( const struct V_204 * V_125 )
{
T_5 V_210 = 0 ;
V_210 = F_222 ( V_125 -> V_134 , V_210 ) ;
V_210 = F_223 ( F_224 ( V_125 -> V_126 ) ,
F_225 ( V_211 ) * sizeof( long ) , V_210 ) ;
return V_210 ;
}
static bool F_226 ( const struct V_204 * V_212 ,
const struct V_204 * V_213 )
{
if ( V_212 -> V_134 != V_213 -> V_134 )
return false ;
if ( ! F_227 ( V_212 -> V_126 , V_213 -> V_126 ) )
return false ;
return true ;
}
static int F_228 ( struct V_13 * V_14 )
{
F_229 ( & V_14 -> V_68 ) ;
V_14 -> V_20 = - 1 ;
V_14 -> V_56 = - 1 ;
V_14 -> V_24 = V_25 ;
V_14 -> V_33 |= V_121 ;
V_14 -> V_72 = V_73 ;
F_131 ( & V_14 -> V_44 ) ;
F_131 ( & V_14 -> V_52 ) ;
F_230 ( V_14 -> V_214 ) ;
F_231 ( & V_14 -> V_119 , F_147 ,
( unsigned long ) V_14 ) ;
F_232 ( & V_14 -> V_143 , F_151 ,
( unsigned long ) V_14 ) ;
F_233 ( & V_14 -> V_47 ) ;
F_233 ( & V_14 -> V_124 ) ;
F_131 ( & V_14 -> V_128 ) ;
F_234 ( & V_14 -> V_133 ) ;
F_235 ( & V_14 -> V_215 ) ;
V_14 -> V_69 = 1 ;
V_14 -> V_125 = F_216 ( V_19 ) ;
if ( ! V_14 -> V_125 )
return - V_200 ;
return 0 ;
}
static void F_236 ( struct V_216 * V_217 )
{
struct V_22 * V_23 =
F_167 ( V_217 , struct V_22 , V_217 ) ;
if ( ! ( V_23 -> V_33 & V_70 ) )
F_211 ( V_23 -> V_106 ) ;
else
F_214 ( V_23 -> V_218 ) ;
F_145 ( V_23 -> V_140 ) ;
F_145 ( V_23 ) ;
}
static void F_237 ( struct V_216 * V_217 )
{
struct V_13 * V_14 = F_167 ( V_217 , struct V_13 , V_217 ) ;
F_238 ( & V_14 -> V_133 ) ;
F_214 ( V_14 -> V_125 ) ;
F_145 ( V_14 ) ;
}
static void F_239 ( struct V_13 * V_14 )
{
F_240 ( V_130 ) ;
struct V_51 * V_51 ;
F_20 ( & V_16 ) ;
if ( -- V_14 -> V_69 )
return;
if ( F_116 ( ! ( V_14 -> V_56 < 0 ) ) ||
F_116 ( ! F_51 ( & V_14 -> V_44 ) ) )
return;
if ( V_14 -> V_20 >= 0 )
F_241 ( & V_17 , V_14 -> V_20 ) ;
F_242 ( & V_14 -> V_215 ) ;
F_133 ( & V_14 -> V_47 ) ;
F_80 ( & V_14 -> V_68 ) ;
while ( ( V_51 = F_57 ( V_14 ) ) )
F_146 ( V_51 ) ;
F_116 ( V_14 -> V_49 || V_14 -> V_45 ) ;
F_81 ( & V_14 -> V_68 ) ;
F_133 ( & V_14 -> V_124 ) ;
if ( ! F_51 ( & V_14 -> V_128 ) )
V_14 -> V_130 = & V_130 ;
F_135 ( & V_14 -> V_124 ) ;
if ( V_14 -> V_130 )
F_180 ( V_14 -> V_130 ) ;
F_135 ( & V_14 -> V_47 ) ;
F_199 ( & V_14 -> V_119 ) ;
F_199 ( & V_14 -> V_143 ) ;
F_243 ( & V_14 -> V_217 , F_237 ) ;
}
static struct V_13 * F_244 ( const struct V_204 * V_125 )
{
T_5 V_210 = F_221 ( V_125 ) ;
struct V_13 * V_14 ;
int V_24 ;
int V_219 = V_25 ;
F_20 ( & V_16 ) ;
F_72 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_226 ( V_14 -> V_125 , V_125 ) ) {
V_14 -> V_69 ++ ;
return V_14 ;
}
}
if ( V_220 ) {
F_245 (node) {
if ( F_246 ( V_125 -> V_126 ,
V_221 [ V_24 ] ) ) {
V_219 = V_24 ;
break;
}
}
}
V_14 = F_130 ( sizeof( * V_14 ) , V_19 , V_219 ) ;
if ( ! V_14 || F_228 ( V_14 ) < 0 )
goto V_88;
F_247 ( & V_14 -> V_68 , 1 ) ;
F_220 ( V_14 -> V_125 , V_125 ) ;
V_14 -> V_24 = V_219 ;
V_14 -> V_125 -> V_209 = false ;
if ( F_19 ( V_14 ) < 0 )
goto V_88;
if ( V_178 && ! F_138 ( V_14 ) )
goto V_88;
F_248 ( V_222 , & V_14 -> V_215 , V_210 ) ;
return V_14 ;
V_88:
if ( V_14 )
F_239 ( V_14 ) ;
return NULL ;
}
static void F_249 ( struct V_216 * V_217 )
{
F_250 ( V_223 ,
F_167 ( V_217 , struct V_21 , V_217 ) ) ;
}
static void F_251 ( struct V_2 * V_4 )
{
struct V_21 * V_34 = F_167 ( V_4 , struct V_21 ,
V_71 ) ;
struct V_22 * V_23 = V_34 -> V_23 ;
struct V_13 * V_14 = V_34 -> V_14 ;
bool V_224 ;
if ( F_30 ( ! ( V_23 -> V_33 & V_70 ) ) )
return;
F_133 ( & V_23 -> V_180 ) ;
F_252 ( & V_34 -> V_225 ) ;
V_224 = F_51 ( & V_23 -> V_226 ) ;
F_135 ( & V_23 -> V_180 ) ;
F_133 ( & V_16 ) ;
F_239 ( V_14 ) ;
F_135 ( & V_16 ) ;
F_243 ( & V_34 -> V_217 , F_249 ) ;
if ( V_224 )
F_243 ( & V_23 -> V_217 , F_236 ) ;
}
static void F_253 ( struct V_21 * V_34 )
{
struct V_22 * V_23 = V_34 -> V_23 ;
bool V_227 = V_23 -> V_33 & V_228 ;
unsigned long V_33 ;
F_20 ( & V_23 -> V_180 ) ;
if ( ! V_227 && V_34 -> V_80 == V_23 -> V_190 )
return;
F_254 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
if ( ! V_227 || ! V_229 ) {
V_34 -> V_80 = V_23 -> V_190 ;
while ( ! F_51 ( & V_34 -> V_76 ) &&
V_34 -> V_75 < V_34 -> V_80 )
F_85 ( V_34 ) ;
F_59 ( V_34 -> V_14 ) ;
} else {
V_34 -> V_80 = 0 ;
}
F_255 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
}
static void F_256 ( struct V_21 * V_34 , struct V_22 * V_23 ,
struct V_13 * V_14 )
{
F_257 ( ( unsigned long ) V_34 & V_230 ) ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_14 = V_14 ;
V_34 -> V_23 = V_23 ;
V_34 -> V_81 = - 1 ;
V_34 -> V_69 = 1 ;
F_131 ( & V_34 -> V_76 ) ;
F_131 ( & V_34 -> V_225 ) ;
F_131 ( & V_34 -> V_141 ) ;
F_208 ( & V_34 -> V_71 , F_251 ) ;
}
static void F_258 ( struct V_21 * V_34 )
{
struct V_22 * V_23 = V_34 -> V_23 ;
F_20 ( & V_23 -> V_180 ) ;
if ( ! F_51 ( & V_34 -> V_225 ) )
return;
V_34 -> V_108 = V_23 -> V_108 ;
F_253 ( V_34 ) ;
F_259 ( & V_34 -> V_225 , & V_23 -> V_226 ) ;
}
static struct V_21 * F_260 ( struct V_22 * V_23 ,
const struct V_204 * V_125 )
{
struct V_13 * V_14 ;
struct V_21 * V_34 ;
F_20 ( & V_16 ) ;
V_14 = F_244 ( V_125 ) ;
if ( ! V_14 )
return NULL ;
V_34 = F_261 ( V_223 , V_19 , V_14 -> V_24 ) ;
if ( ! V_34 ) {
F_239 ( V_14 ) ;
return NULL ;
}
F_256 ( V_34 , V_23 , V_14 ) ;
return V_34 ;
}
static bool F_262 ( const struct V_204 * V_125 , int V_24 ,
int V_231 , T_6 * V_126 )
{
if ( ! V_220 || V_125 -> V_209 )
goto V_232;
F_263 ( V_126 , F_264 ( V_24 ) , V_125 -> V_126 ) ;
if ( V_231 >= 0 )
F_265 ( V_231 , V_126 ) ;
if ( F_105 ( V_126 ) )
goto V_232;
F_263 ( V_126 , V_125 -> V_126 , V_221 [ V_24 ] ) ;
if ( F_105 ( V_126 ) ) {
F_266 ( L_12
L_13 ) ;
return false ;
}
return ! F_227 ( V_126 , V_125 -> V_126 ) ;
V_232:
F_219 ( V_126 , V_125 -> V_126 ) ;
return false ;
}
static struct V_21 * F_267 ( struct V_22 * V_23 ,
int V_24 ,
struct V_21 * V_34 )
{
struct V_21 * V_233 ;
F_20 ( & V_16 ) ;
F_20 ( & V_23 -> V_180 ) ;
F_258 ( V_34 ) ;
V_233 = F_268 ( V_23 -> V_27 [ V_24 ] ) ;
F_269 ( V_23 -> V_27 [ V_24 ] , V_34 ) ;
return V_233 ;
}
static void F_270 ( struct V_234 * V_235 )
{
if ( V_235 ) {
int V_24 ;
F_245 (node)
F_79 ( V_235 -> V_236 [ V_24 ] ) ;
F_79 ( V_235 -> V_26 ) ;
F_214 ( V_235 -> V_125 ) ;
F_145 ( V_235 ) ;
}
}
static struct V_234 *
F_271 ( struct V_22 * V_23 ,
const struct V_204 * V_125 )
{
struct V_234 * V_235 ;
struct V_204 * V_237 , * V_238 ;
int V_24 ;
F_20 ( & V_16 ) ;
V_235 = F_217 ( sizeof( * V_235 ) + V_239 * sizeof( V_235 -> V_236 [ 0 ] ) ,
V_19 ) ;
V_237 = F_216 ( V_19 ) ;
V_238 = F_216 ( V_19 ) ;
if ( ! V_235 || ! V_237 || ! V_238 )
goto V_240;
F_220 ( V_237 , V_125 ) ;
F_263 ( V_237 -> V_126 , V_237 -> V_126 , V_96 ) ;
if ( F_24 ( F_105 ( V_237 -> V_126 ) ) )
F_219 ( V_237 -> V_126 , V_96 ) ;
F_220 ( V_238 , V_237 ) ;
V_235 -> V_26 = F_260 ( V_23 , V_237 ) ;
if ( ! V_235 -> V_26 )
goto V_240;
F_245 (node) {
if ( F_262 ( V_237 , V_24 , - 1 , V_238 -> V_126 ) ) {
V_235 -> V_236 [ V_24 ] = F_260 ( V_23 , V_238 ) ;
if ( ! V_235 -> V_236 [ V_24 ] )
goto V_240;
} else {
V_235 -> V_26 -> V_69 ++ ;
V_235 -> V_236 [ V_24 ] = V_235 -> V_26 ;
}
}
F_220 ( V_237 , V_125 ) ;
F_263 ( V_237 -> V_126 , V_237 -> V_126 , V_206 ) ;
V_235 -> V_125 = V_237 ;
V_235 -> V_23 = V_23 ;
F_214 ( V_238 ) ;
return V_235 ;
V_240:
F_214 ( V_238 ) ;
F_214 ( V_237 ) ;
F_270 ( V_235 ) ;
return NULL ;
}
static void F_272 ( struct V_234 * V_235 )
{
int V_24 ;
F_133 ( & V_235 -> V_23 -> V_180 ) ;
F_220 ( V_235 -> V_23 -> V_218 , V_235 -> V_125 ) ;
F_245 (node)
V_235 -> V_236 [ V_24 ] = F_267 ( V_235 -> V_23 , V_24 ,
V_235 -> V_236 [ V_24 ] ) ;
F_258 ( V_235 -> V_26 ) ;
F_273 ( V_235 -> V_23 -> V_26 , V_235 -> V_26 ) ;
F_135 ( & V_235 -> V_23 -> V_180 ) ;
}
static void F_274 ( void )
{
F_206 () ;
F_133 ( & V_16 ) ;
}
static void F_275 ( void )
{
F_135 ( & V_16 ) ;
F_210 () ;
}
static int F_276 ( struct V_22 * V_23 ,
const struct V_204 * V_125 )
{
struct V_234 * V_235 ;
if ( F_116 ( ! ( V_23 -> V_33 & V_70 ) ) )
return - V_241 ;
if ( ! F_51 ( & V_23 -> V_226 ) ) {
if ( F_116 ( V_23 -> V_33 & V_242 ) )
return - V_241 ;
V_23 -> V_33 &= ~ V_243 ;
}
V_235 = F_271 ( V_23 , V_125 ) ;
if ( ! V_235 )
return - V_200 ;
F_272 ( V_235 ) ;
F_270 ( V_235 ) ;
return 0 ;
}
int F_277 ( struct V_22 * V_23 ,
const struct V_204 * V_125 )
{
int V_15 ;
F_274 () ;
V_15 = F_276 ( V_23 , V_125 ) ;
F_275 () ;
return V_15 ;
}
static void F_278 ( struct V_22 * V_23 , int V_56 ,
bool V_244 )
{
int V_24 = F_113 ( V_56 ) ;
int V_245 = V_244 ? - 1 : V_56 ;
struct V_21 * V_233 = NULL , * V_34 ;
struct V_204 * V_246 ;
T_6 * V_126 ;
F_20 ( & V_16 ) ;
if ( ! V_220 || ! ( V_23 -> V_33 & V_70 ) ||
V_23 -> V_218 -> V_209 )
return;
V_246 = V_247 ;
V_126 = V_246 -> V_126 ;
F_220 ( V_246 , V_23 -> V_218 ) ;
V_34 = F_22 ( V_23 , V_24 ) ;
if ( F_262 ( V_23 -> V_26 -> V_14 -> V_125 , V_24 , V_245 , V_126 ) ) {
if ( F_227 ( V_126 , V_34 -> V_14 -> V_125 -> V_126 ) )
return;
} else {
goto V_248;
}
V_34 = F_260 ( V_23 , V_246 ) ;
if ( ! V_34 ) {
F_104 ( L_14 ,
V_23 -> V_107 ) ;
goto V_248;
}
F_133 ( & V_23 -> V_180 ) ;
V_233 = F_267 ( V_23 , V_24 , V_34 ) ;
goto V_182;
V_248:
F_133 ( & V_23 -> V_180 ) ;
F_80 ( & V_23 -> V_26 -> V_14 -> V_68 ) ;
F_76 ( V_23 -> V_26 ) ;
F_81 ( & V_23 -> V_26 -> V_14 -> V_68 ) ;
V_233 = F_267 ( V_23 , V_24 , V_23 -> V_26 ) ;
V_182:
F_135 ( & V_23 -> V_180 ) ;
F_79 ( V_233 ) ;
}
static int F_279 ( struct V_22 * V_23 )
{
bool V_249 = V_23 -> V_33 & V_250 ;
int V_56 , V_15 ;
if ( ! ( V_23 -> V_33 & V_70 ) ) {
V_23 -> V_106 = F_205 ( struct V_21 ) ;
if ( ! V_23 -> V_106 )
return - V_200 ;
F_280 (cpu) {
struct V_21 * V_34 =
F_112 ( V_23 -> V_106 , V_56 ) ;
struct V_13 * V_251 =
F_281 ( V_252 , V_56 ) ;
F_256 ( V_34 , V_23 , & V_251 [ V_249 ] ) ;
F_133 ( & V_23 -> V_180 ) ;
F_258 ( V_34 ) ;
F_135 ( & V_23 -> V_180 ) ;
}
return 0 ;
} else if ( V_23 -> V_33 & V_243 ) {
V_15 = F_277 ( V_23 , V_253 [ V_249 ] ) ;
F_282 ( ! V_15 && ( V_23 -> V_226 . V_116 != & V_23 -> V_26 -> V_225 ||
V_23 -> V_226 . V_138 != & V_23 -> V_26 -> V_225 ) ,
L_15 , V_23 -> V_107 ) ;
return V_15 ;
} else {
return F_277 ( V_23 , V_254 [ V_249 ] ) ;
}
}
static int F_283 ( int V_80 , unsigned int V_33 ,
const char * V_107 )
{
int V_255 = V_33 & V_70 ? V_256 : V_257 ;
if ( V_80 < 1 || V_80 > V_255 )
F_104 ( L_16 ,
V_80 , V_107 , 1 , V_255 ) ;
return F_284 ( V_80 , 1 , V_255 ) ;
}
struct V_22 * F_285 ( const char * V_258 ,
unsigned int V_33 ,
int V_80 ,
struct V_259 * V_193 ,
const char * V_260 , ... )
{
T_7 V_261 = 0 ;
T_8 args ;
struct V_22 * V_23 ;
struct V_21 * V_34 ;
if ( ( V_33 & V_70 ) && V_80 == 1 )
V_33 |= V_243 ;
if ( ( V_33 & V_262 ) && V_263 )
V_33 |= V_70 ;
if ( V_33 & V_70 )
V_261 = V_239 * sizeof( V_23 -> V_27 [ 0 ] ) ;
V_23 = F_217 ( sizeof( * V_23 ) + V_261 , V_19 ) ;
if ( ! V_23 )
return NULL ;
if ( V_33 & V_70 ) {
V_23 -> V_218 = F_216 ( V_19 ) ;
if ( ! V_23 -> V_218 )
goto V_264;
}
va_start ( args , V_260 ) ;
vsnprintf ( V_23 -> V_107 , sizeof( V_23 -> V_107 ) , V_258 , args ) ;
va_end ( args ) ;
V_80 = V_80 ? : V_265 ;
V_80 = F_283 ( V_80 , V_33 , V_23 -> V_107 ) ;
V_23 -> V_33 = V_33 ;
V_23 -> V_190 = V_80 ;
F_233 ( & V_23 -> V_180 ) ;
F_173 ( & V_23 -> V_82 , 0 ) ;
F_131 ( & V_23 -> V_226 ) ;
F_131 ( & V_23 -> V_183 ) ;
F_131 ( & V_23 -> V_181 ) ;
F_131 ( & V_23 -> V_142 ) ;
F_286 ( & V_23 -> V_179 , V_260 , V_193 , 0 ) ;
F_131 ( & V_23 -> V_176 ) ;
if ( F_279 ( V_23 ) < 0 )
goto V_264;
if ( V_33 & V_162 ) {
struct V_51 * V_140 ;
V_140 = F_129 ( V_25 ) ;
if ( ! V_140 )
goto V_266;
V_140 -> V_153 = V_23 ;
V_140 -> V_54 = F_287 ( F_161 , V_140 , L_17 ,
V_23 -> V_107 ) ;
if ( F_141 ( V_140 -> V_54 ) ) {
F_145 ( V_140 ) ;
goto V_266;
}
V_23 -> V_140 = V_140 ;
F_143 ( V_140 -> V_54 , V_206 ) ;
F_61 ( V_140 -> V_54 ) ;
}
if ( ( V_23 -> V_33 & V_267 ) && F_288 ( V_23 ) )
goto V_266;
F_133 ( & V_16 ) ;
F_133 ( & V_23 -> V_180 ) ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_135 ( & V_23 -> V_180 ) ;
F_289 ( & V_23 -> V_176 , & V_268 ) ;
F_135 ( & V_16 ) ;
return V_23 ;
V_264:
F_214 ( V_23 -> V_218 ) ;
F_145 ( V_23 ) ;
return NULL ;
V_266:
F_290 ( V_23 ) ;
return NULL ;
}
void F_290 ( struct V_22 * V_23 )
{
struct V_21 * V_34 ;
int V_24 ;
F_182 ( V_23 ) ;
F_133 ( & V_23 -> V_180 ) ;
F_174 (pwq, wq) {
int V_269 ;
for ( V_269 = 0 ; V_269 < V_31 ; V_269 ++ ) {
if ( F_116 ( V_34 -> V_79 [ V_269 ] ) ) {
F_135 ( & V_23 -> V_180 ) ;
F_291 () ;
return;
}
}
if ( F_116 ( ( V_34 != V_23 -> V_26 ) && ( V_34 -> V_69 > 1 ) ) ||
F_116 ( V_34 -> V_75 ) ||
F_116 ( ! F_51 ( & V_34 -> V_76 ) ) ) {
F_135 ( & V_23 -> V_180 ) ;
F_291 () ;
return;
}
}
F_135 ( & V_23 -> V_180 ) ;
F_133 ( & V_16 ) ;
F_252 ( & V_23 -> V_176 ) ;
F_135 ( & V_16 ) ;
F_292 ( V_23 ) ;
if ( V_23 -> V_140 )
F_293 ( V_23 -> V_140 -> V_54 ) ;
if ( ! ( V_23 -> V_33 & V_70 ) ) {
F_243 ( & V_23 -> V_217 , F_236 ) ;
} else {
F_245 (node) {
V_34 = F_268 ( V_23 -> V_27 [ V_24 ] ) ;
F_294 ( V_23 -> V_27 [ V_24 ] , NULL ) ;
F_79 ( V_34 ) ;
}
V_34 = V_23 -> V_26 ;
V_23 -> V_26 = NULL ;
F_79 ( V_34 ) ;
}
}
void F_295 ( struct V_22 * V_23 , int V_80 )
{
struct V_21 * V_34 ;
if ( F_116 ( V_23 -> V_33 & V_242 ) )
return;
V_80 = F_283 ( V_80 , V_23 -> V_33 , V_23 -> V_107 ) ;
F_133 ( & V_23 -> V_180 ) ;
V_23 -> V_33 &= ~ V_243 ;
V_23 -> V_190 = V_80 ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_135 ( & V_23 -> V_180 ) ;
}
bool F_296 ( void )
{
struct V_51 * V_51 = F_101 () ;
return V_51 && V_51 -> V_153 ;
}
bool F_297 ( int V_56 , struct V_22 * V_23 )
{
struct V_21 * V_34 ;
bool V_15 ;
F_298 () ;
if ( V_56 == V_105 )
V_56 = F_299 () ;
if ( ! ( V_23 -> V_33 & V_70 ) )
V_34 = F_112 ( V_23 -> V_106 , V_56 ) ;
else
V_34 = F_22 ( V_23 , F_113 ( V_56 ) ) ;
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
V_15 |= V_270 ;
F_89 ( V_33 ) ;
V_14 = F_42 ( V_4 ) ;
if ( V_14 ) {
F_93 ( & V_14 -> V_68 ) ;
if ( F_71 ( V_14 , V_4 ) )
V_15 |= V_271 ;
F_95 ( & V_14 -> V_68 ) ;
}
F_96 ( V_33 ) ;
return V_15 ;
}
void F_302 ( const char * V_258 , ... )
{
struct V_51 * V_51 = F_101 () ;
T_8 args ;
if ( V_51 ) {
va_start ( args , V_258 ) ;
vsnprintf ( V_51 -> V_272 , sizeof( V_51 -> V_272 ) , V_258 , args ) ;
va_end ( args ) ;
V_51 -> V_273 = true ;
}
}
void F_303 ( const char * V_274 , struct V_55 * V_54 )
{
T_1 * V_201 = NULL ;
char V_107 [ V_275 ] = { } ;
char V_272 [ V_276 ] = { } ;
struct V_21 * V_34 = NULL ;
struct V_22 * V_23 = NULL ;
bool V_273 = false ;
struct V_51 * V_51 ;
if ( ! ( V_54 -> V_33 & V_147 ) )
return;
V_51 = F_304 ( V_54 ) ;
F_305 ( & V_201 , & V_51 -> V_62 , sizeof( V_201 ) ) ;
F_305 ( & V_34 , & V_51 -> V_92 , sizeof( V_34 ) ) ;
F_305 ( & V_23 , & V_34 -> V_23 , sizeof( V_23 ) ) ;
F_305 ( V_107 , V_23 -> V_107 , sizeof( V_107 ) - 1 ) ;
F_305 ( & V_273 , & V_51 -> V_273 , sizeof( V_273 ) ) ;
if ( V_273 )
F_305 ( V_272 , V_51 -> V_272 , sizeof( V_272 ) - 1 ) ;
if ( V_201 || V_107 [ 0 ] || V_272 [ 0 ] ) {
F_306 ( L_18 , V_274 , V_107 , V_201 ) ;
if ( V_272 [ 0 ] )
F_307 ( L_19 , V_272 ) ;
F_307 ( L_20 ) ;
}
}
static void F_308 ( struct V_13 * V_14 )
{
F_307 ( L_21 , V_211 , V_14 -> V_125 -> V_126 ) ;
if ( V_14 -> V_24 != V_25 )
F_307 ( L_22 , V_14 -> V_24 ) ;
F_307 ( L_23 , V_14 -> V_33 , V_14 -> V_125 -> V_134 ) ;
}
static void F_309 ( bool V_277 , struct V_2 * V_4 )
{
if ( V_4 -> V_3 == F_166 ) {
struct V_167 * V_168 ;
V_168 = F_167 ( V_4 , struct V_167 , V_4 ) ;
F_307 ( L_24 , V_277 ? L_25 : L_5 ,
F_310 ( V_168 -> V_54 ) ) ;
} else {
F_307 ( L_26 , V_277 ? L_25 : L_5 , V_4 -> V_3 ) ;
}
}
static void F_311 ( struct V_21 * V_34 )
{
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_2 * V_4 ;
struct V_51 * V_51 ;
bool V_278 = false , V_279 = false ;
int V_280 ;
F_312 ( L_27 , V_14 -> V_20 ) ;
F_308 ( V_14 ) ;
F_307 ( L_28 , V_34 -> V_75 , V_34 -> V_80 ,
! F_51 ( & V_34 -> V_141 ) ? L_29 : L_5 ) ;
F_313 (pool->busy_hash, bkt, worker, hentry) {
if ( V_51 -> V_92 == V_34 ) {
V_278 = true ;
break;
}
}
if ( V_278 ) {
bool V_277 = false ;
F_312 ( L_30 ) ;
F_313 (pool->busy_hash, bkt, worker, hentry) {
if ( V_51 -> V_92 != V_34 )
continue;
F_307 ( L_31 , V_277 ? L_25 : L_5 ,
F_310 ( V_51 -> V_54 ) ,
V_51 == V_34 -> V_23 -> V_140 ? L_32 : L_5 ,
V_51 -> V_62 ) ;
F_152 (work, &worker->scheduled, entry)
F_309 ( false , V_4 ) ;
V_277 = true ;
}
F_307 ( L_20 ) ;
}
F_152 (work, &pool->worklist, entry) {
if ( F_40 ( V_4 ) == V_34 ) {
V_279 = true ;
break;
}
}
if ( V_279 ) {
bool V_277 = false ;
F_312 ( L_33 ) ;
F_152 (work, &pool->worklist, entry) {
if ( F_40 ( V_4 ) != V_34 )
continue;
F_309 ( V_277 , V_4 ) ;
V_277 = ! ( * F_4 ( V_4 ) & V_67 ) ;
}
F_307 ( L_20 ) ;
}
if ( ! F_51 ( & V_34 -> V_76 ) ) {
bool V_277 = false ;
F_312 ( L_34 ) ;
F_152 (work, &pwq->delayed_works, entry) {
F_309 ( V_277 , V_4 ) ;
V_277 = ! ( * F_4 ( V_4 ) & V_67 ) ;
}
F_307 ( L_20 ) ;
}
}
void F_291 ( void )
{
struct V_22 * V_23 ;
struct V_13 * V_14 ;
unsigned long V_33 ;
int V_281 ;
F_298 () ;
F_312 ( L_35 ) ;
F_314 (wq, &workqueues, list) {
struct V_21 * V_34 ;
bool V_282 = true ;
F_174 (pwq, wq) {
if ( V_34 -> V_75 || ! F_51 ( & V_34 -> V_76 ) ) {
V_282 = false ;
break;
}
}
if ( V_282 )
continue;
F_312 ( L_36 , V_23 -> V_107 , V_23 -> V_33 ) ;
F_174 (pwq, wq) {
F_254 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
if ( V_34 -> V_75 || ! F_51 ( & V_34 -> V_76 ) )
F_311 ( V_34 ) ;
F_255 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
}
}
F_315 (pool, pi) {
struct V_51 * V_51 ;
bool V_157 = true ;
F_254 ( & V_14 -> V_68 , V_33 ) ;
if ( V_14 -> V_49 == V_14 -> V_45 )
goto V_283;
F_312 ( L_37 , V_14 -> V_20 ) ;
F_308 ( V_14 ) ;
F_307 ( L_38 ,
F_316 ( V_73 - V_14 -> V_72 ) / 1000 ,
V_14 -> V_49 ) ;
if ( V_14 -> V_145 )
F_307 ( L_39 ,
F_310 ( V_14 -> V_145 -> V_54 ) ) ;
F_152 (worker, &pool->idle_list, entry) {
F_307 ( L_40 , V_157 ? L_41 : L_5 ,
F_310 ( V_51 -> V_54 ) ) ;
V_157 = false ;
}
F_307 ( L_20 ) ;
V_283:
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
F_133 ( & V_14 -> V_124 ) ;
F_80 ( & V_14 -> V_68 ) ;
F_319 (worker, pool)
V_51 -> V_33 |= V_127 ;
V_14 -> V_33 |= V_121 ;
F_81 ( & V_14 -> V_68 ) ;
F_135 ( & V_14 -> V_124 ) ;
F_160 () ;
F_173 ( & V_14 -> V_43 , 0 ) ;
F_80 ( & V_14 -> V_68 ) ;
F_59 ( V_14 ) ;
F_81 ( & V_14 -> V_68 ) ;
}
}
static void F_320 ( struct V_13 * V_14 )
{
struct V_51 * V_51 ;
F_20 ( & V_14 -> V_124 ) ;
F_319 (worker, pool)
F_30 ( F_134 ( V_51 -> V_54 ,
V_14 -> V_125 -> V_126 ) < 0 ) ;
F_80 ( & V_14 -> V_68 ) ;
if ( ! ( V_14 -> V_33 & V_121 ) ) {
F_81 ( & V_14 -> V_68 ) ;
return;
}
V_14 -> V_33 &= ~ V_121 ;
F_319 (worker, pool) {
unsigned int V_284 = V_51 -> V_33 ;
if ( V_284 & V_114 )
F_61 ( V_51 -> V_54 ) ;
F_30 ( ! ( V_284 & V_127 ) ) ;
V_284 |= V_131 ;
V_284 &= ~ V_127 ;
F_321 ( V_51 -> V_33 ) = V_284 ;
}
F_81 ( & V_14 -> V_68 ) ;
}
static void F_322 ( struct V_13 * V_14 , int V_56 )
{
static T_6 V_126 ;
struct V_51 * V_51 ;
F_20 ( & V_14 -> V_124 ) ;
if ( ! F_103 ( V_56 , V_14 -> V_125 -> V_126 ) )
return;
F_263 ( & V_126 , V_14 -> V_125 -> V_126 , V_98 ) ;
F_319 (worker, pool)
F_30 ( F_134 ( V_51 -> V_54 , & V_126 ) < 0 ) ;
}
int F_323 ( unsigned int V_56 )
{
struct V_13 * V_14 ;
F_318 (pool, cpu) {
if ( V_14 -> V_49 )
continue;
if ( ! F_138 ( V_14 ) )
return - V_200 ;
}
return 0 ;
}
int F_324 ( unsigned int V_56 )
{
struct V_13 * V_14 ;
struct V_22 * V_23 ;
int V_281 ;
F_133 ( & V_16 ) ;
F_315 (pool, pi) {
F_133 ( & V_14 -> V_124 ) ;
if ( V_14 -> V_56 == V_56 )
F_320 ( V_14 ) ;
else if ( V_14 -> V_56 < 0 )
F_322 ( V_14 , V_56 ) ;
F_135 ( & V_14 -> V_124 ) ;
}
F_152 (wq, &workqueues, list)
F_278 ( V_23 , V_56 , true ) ;
F_135 ( & V_16 ) ;
return 0 ;
}
int F_325 ( unsigned int V_56 )
{
struct V_2 V_285 ;
struct V_22 * V_23 ;
F_169 ( & V_285 , F_317 ) ;
F_117 ( V_56 , V_286 , & V_285 ) ;
F_133 ( & V_16 ) ;
F_152 (wq, &workqueues, list)
F_278 ( V_23 , V_56 , false ) ;
F_135 ( & V_16 ) ;
F_188 ( & V_285 ) ;
F_16 ( & V_285 ) ;
return 0 ;
}
static void F_326 ( struct V_2 * V_4 )
{
struct V_287 * V_288 = F_167 ( V_4 , struct V_287 , V_4 ) ;
V_288 -> V_15 = V_288 -> V_201 ( V_288 -> V_289 ) ;
}
long F_327 ( int V_56 , long (* V_201)( void * ) , void * V_289 )
{
struct V_287 V_288 = { . V_201 = V_201 , . V_289 = V_289 } ;
F_169 ( & V_288 . V_4 , F_326 ) ;
F_209 ( V_56 , & V_288 . V_4 ) ;
F_188 ( & V_288 . V_4 ) ;
F_16 ( & V_288 . V_4 ) ;
return V_288 . V_15 ;
}
long F_328 ( int V_56 , long (* V_201)( void * ) , void * V_289 )
{
long V_15 = - V_290 ;
F_206 () ;
if ( F_329 ( V_56 ) )
V_15 = F_327 ( V_56 , V_201 , V_289 ) ;
F_210 () ;
return V_15 ;
}
void F_330 ( void )
{
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_133 ( & V_16 ) ;
F_30 ( V_229 ) ;
V_229 = true ;
F_152 (wq, &workqueues, list) {
F_133 ( & V_23 -> V_180 ) ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_135 ( & V_23 -> V_180 ) ;
}
F_135 ( & V_16 ) ;
}
bool F_331 ( void )
{
bool V_291 = false ;
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_133 ( & V_16 ) ;
F_30 ( ! V_229 ) ;
F_152 (wq, &workqueues, list) {
if ( ! ( V_23 -> V_33 & V_228 ) )
continue;
F_298 () ;
F_174 (pwq, wq) {
F_30 ( V_34 -> V_75 < 0 ) ;
if ( V_34 -> V_75 ) {
V_291 = true ;
F_300 () ;
goto V_182;
}
}
F_300 () ;
}
V_182:
F_135 ( & V_16 ) ;
return V_291 ;
}
void F_332 ( void )
{
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_133 ( & V_16 ) ;
if ( ! V_229 )
goto V_182;
V_229 = false ;
F_152 (wq, &workqueues, list) {
F_133 ( & V_23 -> V_180 ) ;
F_174 (pwq, wq)
F_253 ( V_34 ) ;
F_135 ( & V_23 -> V_180 ) ;
}
V_182:
F_135 ( & V_16 ) ;
}
static int F_333 ( void )
{
F_334 ( V_292 ) ;
int V_15 = 0 ;
struct V_22 * V_23 ;
struct V_234 * V_235 , * V_66 ;
F_20 ( & V_16 ) ;
F_152 (wq, &workqueues, list) {
if ( ! ( V_23 -> V_33 & V_70 ) )
continue;
if ( V_23 -> V_33 & V_243 )
continue;
V_235 = F_271 ( V_23 , V_23 -> V_218 ) ;
if ( ! V_235 ) {
V_15 = - V_200 ;
break;
}
F_99 ( & V_235 -> V_176 , & V_292 ) ;
}
F_164 (ctx, n, &ctxs, list) {
if ( ! V_15 )
F_272 ( V_235 ) ;
F_270 ( V_235 ) ;
}
return V_15 ;
}
int F_335 ( T_9 V_126 )
{
int V_15 = - V_241 ;
T_9 V_293 ;
if ( ! F_336 ( & V_293 , V_19 ) )
return - V_200 ;
F_263 ( V_126 , V_126 , V_206 ) ;
if ( ! F_105 ( V_126 ) ) {
F_274 () ;
F_219 ( V_293 , V_96 ) ;
F_219 ( V_96 , V_126 ) ;
V_15 = F_333 () ;
if ( V_15 < 0 )
F_219 ( V_96 , V_293 ) ;
F_275 () ;
}
F_215 ( V_293 ) ;
return V_15 ;
}
static struct V_22 * F_337 ( struct V_294 * V_295 )
{
struct V_296 * V_297 = F_167 ( V_295 , struct V_296 , V_295 ) ;
return V_297 -> V_23 ;
}
static T_10 F_338 ( struct V_294 * V_295 , struct V_298 * V_299 ,
char * V_300 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
return F_339 ( V_300 , V_301 , L_42 , ( bool ) ! ( V_23 -> V_33 & V_70 ) ) ;
}
static T_10 F_340 ( struct V_294 * V_295 ,
struct V_298 * V_299 , char * V_300 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
return F_339 ( V_300 , V_301 , L_42 , V_23 -> V_190 ) ;
}
static T_10 F_341 ( struct V_294 * V_295 ,
struct V_298 * V_299 , const char * V_300 ,
T_7 V_302 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
int V_303 ;
if ( sscanf ( V_300 , L_43 , & V_303 ) != 1 || V_303 <= 0 )
return - V_241 ;
F_295 ( V_23 , V_303 ) ;
return V_302 ;
}
static T_10 F_342 ( struct V_294 * V_295 ,
struct V_298 * V_299 , char * V_300 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
const char * V_304 = L_5 ;
int V_24 , V_305 = 0 ;
F_298 () ;
F_245 (node) {
V_305 += F_339 ( V_300 + V_305 , V_301 - V_305 ,
L_44 , V_304 , V_24 ,
F_22 ( V_23 , V_24 ) -> V_14 -> V_20 ) ;
V_304 = L_45 ;
}
V_305 += F_339 ( V_300 + V_305 , V_301 - V_305 , L_20 ) ;
F_300 () ;
return V_305 ;
}
static T_10 F_343 ( struct V_294 * V_295 , struct V_298 * V_299 ,
char * V_300 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
int V_305 ;
F_133 ( & V_23 -> V_180 ) ;
V_305 = F_339 ( V_300 , V_301 , L_42 , V_23 -> V_218 -> V_134 ) ;
F_135 ( & V_23 -> V_180 ) ;
return V_305 ;
}
static struct V_204 * F_344 ( struct V_22 * V_23 )
{
struct V_204 * V_125 ;
F_20 ( & V_16 ) ;
V_125 = F_216 ( V_19 ) ;
if ( ! V_125 )
return NULL ;
F_220 ( V_125 , V_23 -> V_218 ) ;
return V_125 ;
}
static T_10 F_345 ( struct V_294 * V_295 , struct V_298 * V_299 ,
const char * V_300 , T_7 V_302 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
struct V_204 * V_125 ;
int V_15 = - V_200 ;
F_274 () ;
V_125 = F_344 ( V_23 ) ;
if ( ! V_125 )
goto V_182;
if ( sscanf ( V_300 , L_43 , & V_125 -> V_134 ) == 1 &&
V_125 -> V_134 >= V_306 && V_125 -> V_134 <= V_307 )
V_15 = F_276 ( V_23 , V_125 ) ;
else
V_15 = - V_241 ;
V_182:
F_275 () ;
F_214 ( V_125 ) ;
return V_15 ? : V_302 ;
}
static T_10 F_346 ( struct V_294 * V_295 ,
struct V_298 * V_299 , char * V_300 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
int V_305 ;
F_133 ( & V_23 -> V_180 ) ;
V_305 = F_339 ( V_300 , V_301 , L_46 ,
F_347 ( V_23 -> V_218 -> V_126 ) ) ;
F_135 ( & V_23 -> V_180 ) ;
return V_305 ;
}
static T_10 F_348 ( struct V_294 * V_295 ,
struct V_298 * V_299 ,
const char * V_300 , T_7 V_302 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
struct V_204 * V_125 ;
int V_15 = - V_200 ;
F_274 () ;
V_125 = F_344 ( V_23 ) ;
if ( ! V_125 )
goto V_182;
V_15 = F_349 ( V_300 , V_125 -> V_126 ) ;
if ( ! V_15 )
V_15 = F_276 ( V_23 , V_125 ) ;
V_182:
F_275 () ;
F_214 ( V_125 ) ;
return V_15 ? : V_302 ;
}
static T_10 F_350 ( struct V_294 * V_295 , struct V_298 * V_299 ,
char * V_300 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
int V_305 ;
F_133 ( & V_23 -> V_180 ) ;
V_305 = F_339 ( V_300 , V_301 , L_42 ,
! V_23 -> V_218 -> V_209 ) ;
F_135 ( & V_23 -> V_180 ) ;
return V_305 ;
}
static T_10 F_351 ( struct V_294 * V_295 , struct V_298 * V_299 ,
const char * V_300 , T_7 V_302 )
{
struct V_22 * V_23 = F_337 ( V_295 ) ;
struct V_204 * V_125 ;
int V_308 , V_15 = - V_200 ;
F_274 () ;
V_125 = F_344 ( V_23 ) ;
if ( ! V_125 )
goto V_182;
V_15 = - V_241 ;
if ( sscanf ( V_300 , L_43 , & V_308 ) == 1 ) {
V_125 -> V_209 = ! V_308 ;
V_15 = F_276 ( V_23 , V_125 ) ;
}
V_182:
F_275 () ;
F_214 ( V_125 ) ;
return V_15 ? : V_302 ;
}
static T_10 F_352 ( struct V_294 * V_295 ,
struct V_298 * V_299 , char * V_300 )
{
int V_305 ;
F_133 ( & V_16 ) ;
V_305 = F_339 ( V_300 , V_301 , L_46 ,
F_347 ( V_96 ) ) ;
F_135 ( & V_16 ) ;
return V_305 ;
}
static T_10 F_353 ( struct V_294 * V_295 ,
struct V_298 * V_299 , const char * V_300 , T_7 V_302 )
{
T_9 V_126 ;
int V_15 ;
if ( ! F_336 ( & V_126 , V_19 ) )
return - V_200 ;
V_15 = F_349 ( V_300 , V_126 ) ;
if ( ! V_15 )
V_15 = F_335 ( V_126 ) ;
F_215 ( V_126 ) ;
return V_15 ? V_15 : V_302 ;
}
static int T_11 F_354 ( void )
{
int V_309 ;
V_309 = F_355 ( & V_310 , NULL ) ;
if ( V_309 )
return V_309 ;
return F_356 ( V_310 . V_311 , & V_312 ) ;
}
static void F_357 ( struct V_294 * V_295 )
{
struct V_296 * V_297 = F_167 ( V_295 , struct V_296 , V_295 ) ;
F_145 ( V_297 ) ;
}
int F_288 ( struct V_22 * V_23 )
{
struct V_296 * V_297 ;
int V_15 ;
if ( F_116 ( V_23 -> V_33 & V_242 ) )
return - V_241 ;
V_23 -> V_297 = V_297 = F_217 ( sizeof( * V_297 ) , V_19 ) ;
if ( ! V_297 )
return - V_200 ;
V_297 -> V_23 = V_23 ;
V_297 -> V_295 . V_313 = & V_310 ;
V_297 -> V_295 . V_314 = F_357 ;
F_358 ( & V_297 -> V_295 , L_17 , V_23 -> V_107 ) ;
F_359 ( & V_297 -> V_295 , true ) ;
V_15 = F_360 ( & V_297 -> V_295 ) ;
if ( V_15 ) {
F_145 ( V_297 ) ;
V_23 -> V_297 = NULL ;
return V_15 ;
}
if ( V_23 -> V_33 & V_70 ) {
struct V_298 * V_299 ;
for ( V_299 = V_315 ; V_299 -> V_299 . V_107 ; V_299 ++ ) {
V_15 = F_356 ( & V_297 -> V_295 , V_299 ) ;
if ( V_15 ) {
F_361 ( & V_297 -> V_295 ) ;
V_23 -> V_297 = NULL ;
return V_15 ;
}
}
}
F_359 ( & V_297 -> V_295 , false ) ;
F_362 ( & V_297 -> V_295 . V_316 , V_317 ) ;
return 0 ;
}
static void F_292 ( struct V_22 * V_23 )
{
struct V_296 * V_297 = V_23 -> V_297 ;
if ( ! V_23 -> V_297 )
return;
V_23 -> V_297 = NULL ;
F_361 ( & V_297 -> V_295 ) ;
}
static void F_292 ( struct V_22 * V_23 ) { }
static void F_363 ( void )
{
int V_56 ;
V_318 = V_73 ;
F_280 (cpu)
F_281 ( V_319 , V_56 ) = V_73 ;
}
static void F_364 ( unsigned long V_32 )
{
unsigned long V_320 = F_365 ( V_321 ) * V_322 ;
bool V_323 = false ;
struct V_13 * V_14 ;
int V_281 ;
if ( ! V_320 )
return;
F_366 () ;
F_315 (pool, pi) {
unsigned long V_324 , V_325 , V_326 ;
if ( F_51 ( & V_14 -> V_44 ) )
continue;
V_324 = F_365 ( V_14 -> V_72 ) ;
V_325 = F_365 ( V_318 ) ;
if ( F_367 ( V_324 , V_325 ) )
V_326 = V_324 ;
else
V_326 = V_325 ;
if ( V_14 -> V_56 >= 0 ) {
unsigned long V_327 =
F_365 ( F_281 ( V_319 ,
V_14 -> V_56 ) ) ;
if ( F_367 ( V_327 , V_326 ) )
V_326 = V_327 ;
}
if ( F_367 ( V_73 , V_326 + V_320 ) ) {
V_323 = true ;
F_368 ( L_47 ) ;
F_308 ( V_14 ) ;
F_307 ( L_48 ,
F_316 ( V_73 - V_324 ) / 1000 ) ;
}
}
F_369 () ;
if ( V_323 )
F_291 () ;
F_363 () ;
F_127 ( & V_328 , V_73 + V_320 ) ;
}
void F_370 ( int V_56 )
{
if ( V_56 >= 0 )
F_281 ( V_319 , V_56 ) = V_73 ;
else
V_318 = V_73 ;
}
static void F_371 ( unsigned long V_320 )
{
V_321 = 0 ;
F_199 ( & V_328 ) ;
if ( V_320 ) {
V_321 = V_320 ;
F_363 () ;
F_127 ( & V_328 , V_73 + V_320 * V_322 ) ;
}
}
static int F_372 ( const char * V_303 ,
const struct V_329 * V_330 )
{
unsigned long V_320 ;
int V_15 ;
V_15 = F_373 ( V_303 , 0 , & V_320 ) ;
if ( V_15 )
return V_15 ;
if ( V_331 )
F_371 ( V_320 ) ;
else
V_321 = V_320 ;
return 0 ;
}
static void F_374 ( void )
{
F_371 ( V_321 ) ;
}
static inline void F_374 ( void ) { }
static void T_11 F_375 ( void )
{
T_9 * V_332 ;
int V_24 , V_56 ;
if ( F_376 () <= 1 )
return;
if ( V_333 ) {
F_312 ( L_49 ) ;
return;
}
V_247 = F_216 ( V_19 ) ;
F_257 ( ! V_247 ) ;
V_332 = F_217 ( V_239 * sizeof( V_332 [ 0 ] ) , V_19 ) ;
F_257 ( ! V_332 ) ;
F_245 (node)
F_257 ( ! F_377 ( & V_332 [ V_24 ] , V_19 ,
F_378 ( V_24 ) ? V_24 : V_25 ) ) ;
F_280 (cpu) {
V_24 = F_113 ( V_56 ) ;
if ( F_116 ( V_24 == V_25 ) ) {
F_104 ( L_50 , V_56 ) ;
return;
}
F_379 ( V_56 , V_332 [ V_24 ] ) ;
}
V_221 = V_332 ;
V_220 = true ;
}
int T_11 F_380 ( void )
{
int V_334 [ V_335 ] = { 0 , V_336 } ;
int V_269 , V_56 ;
F_116 ( F_381 ( struct V_21 ) < F_381 (long long) ) ;
F_257 ( ! F_218 ( & V_96 , V_19 ) ) ;
F_219 ( V_96 , V_206 ) ;
V_223 = F_382 ( V_21 , V_337 ) ;
F_280 (cpu) {
struct V_13 * V_14 ;
V_269 = 0 ;
F_318 (pool, cpu) {
F_257 ( F_228 ( V_14 ) ) ;
V_14 -> V_56 = V_56 ;
F_219 ( V_14 -> V_125 -> V_126 , F_383 ( V_56 ) ) ;
V_14 -> V_125 -> V_134 = V_334 [ V_269 ++ ] ;
V_14 -> V_24 = F_113 ( V_56 ) ;
F_133 ( & V_16 ) ;
F_257 ( F_19 ( V_14 ) ) ;
F_135 ( & V_16 ) ;
}
}
for ( V_269 = 0 ; V_269 < V_335 ; V_269 ++ ) {
struct V_204 * V_125 ;
F_257 ( ! ( V_125 = F_216 ( V_19 ) ) ) ;
V_125 -> V_134 = V_334 [ V_269 ] ;
V_254 [ V_269 ] = V_125 ;
F_257 ( ! ( V_125 = F_216 ( V_19 ) ) ) ;
V_125 -> V_134 = V_334 [ V_269 ] ;
V_125 -> V_209 = true ;
V_253 [ V_269 ] = V_125 ;
}
V_331 = F_384 ( L_51 , 0 , 0 ) ;
V_286 = F_384 ( L_52 , V_250 , 0 ) ;
V_338 = F_384 ( L_53 , 0 , 0 ) ;
V_339 = F_384 ( L_54 , V_70 ,
V_256 ) ;
V_340 = F_384 ( L_55 ,
V_228 , 0 ) ;
V_341 = F_384 ( L_56 ,
V_262 , 0 ) ;
V_342 = F_384 ( L_57 ,
V_228 | V_262 ,
0 ) ;
F_257 ( ! V_331 || ! V_286 || ! V_338 ||
! V_339 || ! V_340 ||
! V_341 ||
! V_342 ) ;
return 0 ;
}
int T_11 F_385 ( void )
{
struct V_22 * V_23 ;
struct V_13 * V_14 ;
int V_56 , V_280 ;
F_375 () ;
F_133 ( & V_16 ) ;
F_280 (cpu) {
F_318 (pool, cpu) {
V_14 -> V_24 = F_113 ( V_56 ) ;
}
}
F_152 (wq, &workqueues, list)
F_278 ( V_23 , F_299 () , true ) ;
F_135 ( & V_16 ) ;
F_207 (cpu) {
F_318 (pool, cpu) {
V_14 -> V_33 &= ~ V_121 ;
F_257 ( ! F_138 ( V_14 ) ) ;
}
}
F_313 (unbound_pool_hash, bkt, pool, hash_node)
F_257 ( ! F_138 ( V_14 ) ) ;
V_178 = true ;
F_374 () ;
return 0 ;
}
