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
F_30 ( V_12 -> V_112 != F_118 ||
V_12 -> V_32 != ( unsigned long ) V_86 ) ;
F_30 ( F_120 ( V_12 ) ) ;
F_30 ( ! F_51 ( & V_4 -> V_53 ) ) ;
if ( ! V_110 ) {
F_110 ( V_56 , V_23 , & V_86 -> V_4 ) ;
return;
}
F_121 ( & V_86 -> V_12 ) ;
V_86 -> V_23 = V_23 ;
V_86 -> V_56 = V_56 ;
V_12 -> V_113 = V_73 + V_110 ;
if ( F_24 ( V_56 != V_105 ) )
F_122 ( V_12 , V_56 ) ;
else
F_123 ( V_12 ) ;
}
bool F_124 ( int V_56 , struct V_22 * V_23 ,
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
bool F_125 ( int V_56 , struct V_22 * V_23 ,
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
static void F_126 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( F_30 ( V_51 -> V_33 & V_114 ) ||
F_30 ( ! F_51 ( & V_51 -> V_53 ) &&
( V_51 -> V_115 . V_116 || V_51 -> V_115 . V_117 ) ) )
return;
V_51 -> V_33 |= V_114 ;
V_14 -> V_45 ++ ;
V_51 -> V_118 = V_73 ;
F_127 ( & V_51 -> V_53 , & V_14 -> V_52 ) ;
if ( F_55 ( V_14 ) && ! F_120 ( & V_14 -> V_119 ) )
F_128 ( & V_14 -> V_119 , V_73 + V_120 ) ;
F_30 ( ! ( V_14 -> V_33 & V_121 ) &&
V_14 -> V_49 == V_14 -> V_45 &&
F_49 ( & V_14 -> V_43 ) ) ;
}
static void F_129 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( F_30 ( ! ( V_51 -> V_33 & V_114 ) ) )
return;
F_70 ( V_51 , V_114 ) ;
V_14 -> V_45 -- ;
F_94 ( & V_51 -> V_53 ) ;
}
static struct V_51 * F_130 ( int V_24 )
{
struct V_51 * V_51 ;
V_51 = F_131 ( sizeof( * V_51 ) , V_19 , V_24 ) ;
if ( V_51 ) {
F_132 ( & V_51 -> V_53 ) ;
F_132 ( & V_51 -> V_122 ) ;
F_132 ( & V_51 -> V_24 ) ;
V_51 -> V_33 = V_123 ;
}
return V_51 ;
}
static void F_133 ( struct V_51 * V_51 ,
struct V_13 * V_14 )
{
F_134 ( & V_14 -> V_124 ) ;
F_135 ( V_51 -> V_54 , V_14 -> V_125 -> V_126 ) ;
if ( V_14 -> V_33 & V_121 )
V_51 -> V_33 |= V_127 ;
F_99 ( & V_51 -> V_24 , & V_14 -> V_128 ) ;
F_136 ( & V_14 -> V_124 ) ;
}
static void F_137 ( struct V_51 * V_51 ,
struct V_13 * V_14 )
{
struct V_129 * V_130 = NULL ;
F_134 ( & V_14 -> V_124 ) ;
F_138 ( & V_51 -> V_24 ) ;
if ( F_51 ( & V_14 -> V_128 ) )
V_130 = V_14 -> V_130 ;
F_136 ( & V_14 -> V_124 ) ;
V_51 -> V_33 &= ~ ( V_127 | V_131 ) ;
if ( V_130 )
F_87 ( V_130 ) ;
}
static struct V_51 * F_139 ( struct V_13 * V_14 )
{
struct V_51 * V_51 = NULL ;
int V_20 = - 1 ;
char V_132 [ 16 ] ;
V_20 = F_140 ( & V_14 -> V_133 , 0 , 0 , V_19 ) ;
if ( V_20 < 0 )
goto V_88;
V_51 = F_130 ( V_14 -> V_24 ) ;
if ( ! V_51 )
goto V_88;
V_51 -> V_14 = V_14 ;
V_51 -> V_20 = V_20 ;
if ( V_14 -> V_56 >= 0 )
snprintf ( V_132 , sizeof( V_132 ) , L_3 , V_14 -> V_56 , V_20 ,
V_14 -> V_125 -> V_134 < 0 ? L_4 : L_5 ) ;
else
snprintf ( V_132 , sizeof( V_132 ) , L_6 , V_14 -> V_20 , V_20 ) ;
V_51 -> V_54 = F_141 ( V_135 , V_51 , V_14 -> V_24 ,
L_7 , V_132 ) ;
if ( F_142 ( V_51 -> V_54 ) )
goto V_88;
F_143 ( V_51 -> V_54 , V_14 -> V_125 -> V_134 ) ;
F_144 ( V_51 -> V_54 , V_14 -> V_125 -> V_126 ) ;
F_133 ( V_51 , V_14 ) ;
F_80 ( & V_14 -> V_68 ) ;
V_51 -> V_14 -> V_49 ++ ;
F_126 ( V_51 ) ;
F_61 ( V_51 -> V_54 ) ;
F_81 ( & V_14 -> V_68 ) ;
return V_51 ;
V_88:
if ( V_20 >= 0 )
F_145 ( & V_14 -> V_133 , V_20 ) ;
F_146 ( V_51 ) ;
return NULL ;
}
static void F_147 ( struct V_51 * V_51 )
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
static void F_148 ( unsigned long V_137 )
{
struct V_13 * V_14 = ( void * ) V_137 ;
F_80 ( & V_14 -> V_68 ) ;
while ( F_55 ( V_14 ) ) {
struct V_51 * V_51 ;
unsigned long V_113 ;
V_51 = F_149 ( V_14 -> V_52 . V_138 , struct V_51 , V_53 ) ;
V_113 = V_51 -> V_118 + V_120 ;
if ( F_150 ( V_73 , V_113 ) ) {
F_128 ( & V_14 -> V_119 , V_113 ) ;
break;
}
F_147 ( V_51 ) ;
}
F_81 ( & V_14 -> V_68 ) ;
}
static void F_151 ( struct V_2 * V_4 )
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
static void F_152 ( unsigned long V_137 )
{
struct V_13 * V_14 = ( void * ) V_137 ;
struct V_2 * V_4 ;
F_80 ( & V_14 -> V_68 ) ;
F_93 ( & V_139 ) ;
if ( F_54 ( V_14 ) ) {
F_153 (work, &pool->worklist, entry)
F_151 ( V_4 ) ;
}
F_95 ( & V_139 ) ;
F_81 ( & V_14 -> V_68 ) ;
F_128 ( & V_14 -> V_143 , V_73 + V_144 ) ;
}
static void F_154 ( struct V_13 * V_14 )
__releases( &pool->lock
static bool F_155 ( struct V_51 * V_51 )
{
struct V_13 * V_14 = V_51 -> V_14 ;
if ( ! F_156 ( & V_14 -> V_47 ) )
return false ;
V_14 -> V_145 = V_51 ;
F_154 ( V_14 ) ;
V_14 -> V_145 = NULL ;
F_136 ( & V_14 -> V_47 ) ;
return true ;
}
static void F_157 ( struct V_51 * V_51 , struct V_2 * V_4 )
__releases( &pool->lock
static void F_158 ( struct V_51 * V_51 )
{
while ( ! F_51 ( & V_51 -> V_122 ) ) {
struct V_2 * V_4 = F_58 ( & V_51 -> V_122 ,
struct V_2 , V_53 ) ;
F_157 ( V_51 , V_4 ) ;
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
F_159 ( V_51 -> V_54 , L_8 ) ;
F_145 ( & V_14 -> V_133 , V_51 -> V_20 ) ;
F_137 ( V_51 , V_14 ) ;
F_146 ( V_51 ) ;
return 0 ;
}
F_129 ( V_51 ) ;
V_149:
if ( ! F_50 ( V_14 ) )
goto V_150;
if ( F_24 ( ! F_52 ( V_14 ) ) && F_155 ( V_51 ) )
goto V_149;
F_30 ( ! F_51 ( & V_51 -> V_122 ) ) ;
F_70 ( V_51 , V_123 | V_131 ) ;
do {
struct V_2 * V_4 =
F_58 ( & V_14 -> V_44 ,
struct V_2 , V_53 ) ;
V_14 -> V_72 = V_73 ;
if ( F_60 ( ! ( * F_4 ( V_4 ) & V_67 ) ) ) {
F_157 ( V_51 , V_4 ) ;
if ( F_24 ( ! F_51 ( & V_51 -> V_122 ) ) )
F_158 ( V_51 ) ;
} else {
F_73 ( V_4 , & V_51 -> V_122 , NULL ) ;
F_158 ( V_51 ) ;
}
} while ( F_53 ( V_14 ) );
F_68 ( V_51 , V_123 ) ;
V_150:
F_126 ( V_51 ) ;
F_160 ( V_151 ) ;
F_81 ( & V_14 -> V_68 ) ;
F_161 () ;
goto V_148;
}
static int F_162 ( void * V_152 )
{
struct V_51 * V_140 = V_152 ;
struct V_22 * V_23 = V_140 -> V_153 ;
struct V_63 * V_122 = & V_140 -> V_122 ;
bool V_154 ;
F_143 ( V_59 , V_155 ) ;
V_140 -> V_54 -> V_33 |= V_147 ;
V_156:
F_163 ( V_151 ) ;
V_154 = F_164 () ;
F_80 ( & V_139 ) ;
while ( ! F_51 ( & V_23 -> V_142 ) ) {
struct V_21 * V_34 = F_58 ( & V_23 -> V_142 ,
struct V_21 , V_141 ) ;
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_2 * V_4 , * V_66 ;
bool V_157 = true ;
F_160 ( V_158 ) ;
F_94 ( & V_34 -> V_141 ) ;
F_81 ( & V_139 ) ;
F_133 ( V_140 , V_14 ) ;
F_80 ( & V_14 -> V_68 ) ;
V_140 -> V_14 = V_14 ;
F_30 ( ! F_51 ( V_122 ) ) ;
F_165 (work, n, &pool->worklist, entry) {
if ( F_40 ( V_4 ) == V_34 ) {
if ( V_157 )
V_14 -> V_72 = V_73 ;
F_73 ( V_4 , V_122 , & V_66 ) ;
}
V_157 = false ;
}
if ( ! F_51 ( V_122 ) ) {
F_158 ( V_140 ) ;
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
F_137 ( V_140 , V_14 ) ;
F_80 ( & V_139 ) ;
}
F_81 ( & V_139 ) ;
if ( V_154 ) {
F_160 ( V_158 ) ;
V_140 -> V_54 -> V_33 &= ~ V_147 ;
return 0 ;
}
F_30 ( ! ( V_140 -> V_33 & V_57 ) ) ;
F_161 () ;
goto V_156;
}
static void F_166 ( struct V_22 * V_159 ,
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
static void F_167 ( struct V_2 * V_4 )
{
struct V_167 * V_168 = F_168 ( V_4 , struct V_167 , V_4 ) ;
F_87 ( & V_168 -> V_84 ) ;
}
static void F_169 ( struct V_21 * V_34 ,
struct V_167 * V_168 ,
struct V_2 * V_169 , struct V_51 * V_51 )
{
struct V_63 * V_64 ;
unsigned int V_170 = 0 ;
F_170 ( & V_168 -> V_4 , F_167 ) ;
F_171 ( V_87 , F_4 ( & V_168 -> V_4 ) ) ;
F_172 ( & V_168 -> V_84 ) ;
V_168 -> V_54 = V_59 ;
if ( V_51 )
V_64 = V_51 -> V_122 . V_116 ;
else {
unsigned long * V_171 = F_4 ( V_169 ) ;
V_64 = V_169 -> V_53 . V_116 ;
V_170 = * V_171 & V_67 ;
F_171 ( V_172 , V_171 ) ;
}
F_10 ( & V_168 -> V_4 ) ;
F_98 ( V_34 , & V_168 -> V_4 , V_64 ,
F_26 ( V_77 ) | V_170 ) ;
}
static bool F_173 ( struct V_22 * V_23 ,
int V_81 , int V_108 )
{
bool V_173 = false ;
struct V_21 * V_34 ;
if ( V_81 >= 0 ) {
F_30 ( F_49 ( & V_23 -> V_82 ) ) ;
F_174 ( & V_23 -> V_82 , 1 ) ;
}
F_175 (pwq, wq) {
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
void F_176 ( struct V_22 * V_23 )
{
struct V_174 V_175 = {
. V_176 = F_177 ( V_175 . V_176 ) ,
. V_81 = - 1 ,
. V_84 = F_178 ( V_175 . V_84 ) ,
} ;
int V_177 ;
F_179 ( & V_23 -> V_178 ) ;
F_180 ( & V_23 -> V_178 ) ;
F_134 ( & V_23 -> V_179 ) ;
V_177 = F_28 ( V_23 -> V_108 ) ;
if ( V_177 != V_23 -> V_81 ) {
F_30 ( ! F_51 ( & V_23 -> V_180 ) ) ;
V_175 . V_81 = V_23 -> V_108 ;
V_23 -> V_108 = V_177 ;
if ( ! V_23 -> V_83 ) {
F_30 ( V_23 -> V_81 != V_175 . V_81 ) ;
V_23 -> V_83 = & V_175 ;
if ( ! F_173 ( V_23 , V_23 -> V_81 ,
V_23 -> V_108 ) ) {
V_23 -> V_81 = V_177 ;
V_23 -> V_83 = NULL ;
goto V_181;
}
} else {
F_30 ( V_23 -> V_81 == V_175 . V_81 ) ;
F_99 ( & V_175 . V_176 , & V_23 -> V_182 ) ;
F_173 ( V_23 , - 1 , V_23 -> V_108 ) ;
}
} else {
F_99 ( & V_175 . V_176 , & V_23 -> V_180 ) ;
}
F_166 ( V_23 , NULL ) ;
F_136 ( & V_23 -> V_179 ) ;
F_181 ( & V_175 . V_84 ) ;
if ( V_23 -> V_83 != & V_175 )
return;
F_134 ( & V_23 -> V_179 ) ;
if ( V_23 -> V_83 != & V_175 )
goto V_181;
V_23 -> V_83 = NULL ;
F_30 ( ! F_51 ( & V_175 . V_176 ) ) ;
F_30 ( V_23 -> V_81 != V_175 . V_81 ) ;
while ( true ) {
struct V_174 * V_116 , * V_183 ;
F_165 (next, tmp, &wq->flusher_queue, list) {
if ( V_116 -> V_81 != V_23 -> V_81 )
break;
F_94 ( & V_116 -> V_176 ) ;
F_87 ( & V_116 -> V_84 ) ;
}
F_30 ( ! F_51 ( & V_23 -> V_180 ) &&
V_23 -> V_81 != F_28 ( V_23 -> V_108 ) ) ;
V_23 -> V_81 = F_28 ( V_23 -> V_81 ) ;
if ( ! F_51 ( & V_23 -> V_180 ) ) {
F_153 (tmp, &wq->flusher_overflow, list)
V_183 -> V_81 = V_23 -> V_108 ;
V_23 -> V_108 = F_28 ( V_23 -> V_108 ) ;
F_182 ( & V_23 -> V_180 ,
& V_23 -> V_182 ) ;
F_173 ( V_23 , - 1 , V_23 -> V_108 ) ;
}
if ( F_51 ( & V_23 -> V_182 ) ) {
F_30 ( V_23 -> V_81 != V_23 -> V_108 ) ;
break;
}
F_30 ( V_23 -> V_81 == V_23 -> V_108 ) ;
F_30 ( V_23 -> V_81 != V_116 -> V_81 ) ;
F_94 ( & V_116 -> V_176 ) ;
V_23 -> V_83 = V_116 ;
if ( F_173 ( V_23 , V_23 -> V_81 , - 1 ) )
break;
V_23 -> V_83 = NULL ;
}
V_181:
F_136 ( & V_23 -> V_179 ) ;
}
void F_183 ( struct V_22 * V_23 )
{
unsigned int V_184 = 0 ;
struct V_21 * V_34 ;
F_134 ( & V_23 -> V_179 ) ;
if ( ! V_23 -> V_185 ++ )
V_23 -> V_33 |= V_103 ;
F_136 ( & V_23 -> V_179 ) ;
V_186:
F_176 ( V_23 ) ;
F_134 ( & V_23 -> V_179 ) ;
F_175 (pwq, wq) {
bool V_187 ;
F_80 ( & V_34 -> V_14 -> V_68 ) ;
V_187 = ! V_34 -> V_75 && F_51 ( & V_34 -> V_76 ) ;
F_81 ( & V_34 -> V_14 -> V_68 ) ;
if ( V_187 )
continue;
if ( ++ V_184 == 10 ||
( V_184 % 100 == 0 && V_184 <= 1000 ) )
F_104 ( L_11 ,
V_23 -> V_107 , V_184 ) ;
F_136 ( & V_23 -> V_179 ) ;
goto V_186;
}
if ( ! -- V_23 -> V_185 )
V_23 -> V_33 &= ~ V_103 ;
F_136 ( & V_23 -> V_179 ) ;
}
static bool F_184 ( struct V_2 * V_4 , struct V_167 * V_168 )
{
struct V_51 * V_51 = NULL ;
struct V_13 * V_14 ;
struct V_21 * V_34 ;
F_185 () ;
F_186 () ;
V_14 = F_42 ( V_4 ) ;
if ( ! V_14 ) {
F_187 () ;
return false ;
}
F_93 ( & V_14 -> V_68 ) ;
V_34 = F_40 ( V_4 ) ;
if ( V_34 ) {
if ( F_24 ( V_34 -> V_14 != V_14 ) )
goto V_188;
} else {
V_51 = F_71 ( V_14 , V_4 ) ;
if ( ! V_51 )
goto V_188;
V_34 = V_51 -> V_92 ;
}
F_166 ( V_34 -> V_23 , V_4 ) ;
F_169 ( V_34 , V_168 , V_4 , V_51 ) ;
F_81 ( & V_14 -> V_68 ) ;
if ( V_34 -> V_23 -> V_189 == 1 || V_34 -> V_23 -> V_140 )
F_179 ( & V_34 -> V_23 -> V_178 ) ;
else
F_188 ( & V_34 -> V_23 -> V_178 ) ;
F_180 ( & V_34 -> V_23 -> V_178 ) ;
return true ;
V_188:
F_81 ( & V_14 -> V_68 ) ;
return false ;
}
bool F_189 ( struct V_2 * V_4 )
{
struct V_167 V_168 ;
F_179 ( & V_4 -> V_178 ) ;
F_180 ( & V_4 -> V_178 ) ;
if ( F_184 ( V_4 , & V_168 ) ) {
F_181 ( & V_168 . V_84 ) ;
F_16 ( & V_168 . V_4 ) ;
return true ;
} else {
return false ;
}
}
static int F_190 ( T_2 * V_173 , unsigned V_190 , int V_191 , void * V_192 )
{
struct V_193 * V_194 = F_168 ( V_173 , struct V_193 , V_173 ) ;
if ( V_194 -> V_4 != V_192 )
return 0 ;
return F_191 ( V_173 , V_190 , V_191 , V_192 ) ;
}
static bool F_192 ( struct V_2 * V_4 , bool V_85 )
{
static F_193 ( V_195 ) ;
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_88 ( V_4 , V_85 , & V_33 ) ;
if ( F_24 ( V_15 == - V_90 ) ) {
struct V_193 V_194 ;
F_194 ( & V_194 . V_173 ) ;
V_194 . V_173 . V_3 = F_190 ;
V_194 . V_4 = V_4 ;
F_195 ( & V_195 , & V_194 . V_173 ,
V_196 ) ;
if ( F_47 ( V_4 ) )
F_161 () ;
F_196 ( & V_195 , & V_194 . V_173 ) ;
}
} while ( F_24 ( V_15 < 0 ) );
F_46 ( V_4 ) ;
F_96 ( V_33 ) ;
F_189 ( V_4 ) ;
F_39 ( V_4 ) ;
F_38 () ;
if ( F_197 ( & V_195 ) )
F_198 ( & V_195 , V_197 , 1 , V_4 ) ;
return V_15 ;
}
bool F_6 ( struct V_2 * V_4 )
{
return F_192 ( V_4 , false ) ;
}
bool F_199 ( struct V_11 * V_86 )
{
F_186 () ;
if ( F_200 ( & V_86 -> V_12 ) )
F_110 ( V_86 -> V_56 , V_86 -> V_23 , & V_86 -> V_4 ) ;
F_187 () ;
return F_189 ( & V_86 -> V_4 ) ;
}
bool F_201 ( struct V_11 * V_86 )
{
unsigned long V_33 ;
int V_15 ;
do {
V_15 = F_88 ( & V_86 -> V_4 , true , & V_33 ) ;
} while ( F_24 ( V_15 == - V_91 ) );
if ( F_24 ( V_15 < 0 ) )
return false ;
F_36 ( & V_86 -> V_4 ,
F_45 ( & V_86 -> V_4 ) ) ;
F_96 ( V_33 ) ;
return V_15 ;
}
bool F_202 ( struct V_11 * V_86 )
{
return F_192 ( & V_86 -> V_4 , true ) ;
}
int F_203 ( T_1 V_3 )
{
int V_56 ;
struct V_2 T_3 * V_198 ;
V_198 = F_204 ( struct V_2 ) ;
if ( ! V_198 )
return - V_199 ;
F_205 () ;
F_206 (cpu) {
struct V_2 * V_4 = F_112 ( V_198 , V_56 ) ;
F_207 ( V_4 , V_3 ) ;
F_208 ( V_56 , V_4 ) ;
}
F_206 (cpu)
F_189 ( F_112 ( V_198 , V_56 ) ) ;
F_209 () ;
F_210 ( V_198 ) ;
return 0 ;
}
int F_211 ( T_1 V_200 , struct V_201 * V_202 )
{
if ( ! F_212 () ) {
V_200 ( & V_202 -> V_4 ) ;
return 0 ;
}
F_207 ( & V_202 -> V_4 , V_200 ) ;
F_78 ( & V_202 -> V_4 ) ;
return 1 ;
}
void F_213 ( struct V_203 * V_125 )
{
if ( V_125 ) {
F_214 ( V_125 -> V_126 ) ;
F_146 ( V_125 ) ;
}
}
struct V_203 * F_215 ( T_4 V_204 )
{
struct V_203 * V_125 ;
V_125 = F_216 ( sizeof( * V_125 ) , V_204 ) ;
if ( ! V_125 )
goto V_88;
if ( ! F_217 ( & V_125 -> V_126 , V_204 ) )
goto V_88;
F_218 ( V_125 -> V_126 , V_205 ) ;
return V_125 ;
V_88:
F_213 ( V_125 ) ;
return NULL ;
}
static void F_219 ( struct V_203 * V_206 ,
const struct V_203 * V_207 )
{
V_206 -> V_134 = V_207 -> V_134 ;
F_218 ( V_206 -> V_126 , V_207 -> V_126 ) ;
V_206 -> V_208 = V_207 -> V_208 ;
}
static T_5 F_220 ( const struct V_203 * V_125 )
{
T_5 V_209 = 0 ;
V_209 = F_221 ( V_125 -> V_134 , V_209 ) ;
V_209 = F_222 ( F_223 ( V_125 -> V_126 ) ,
F_224 ( V_210 ) * sizeof( long ) , V_209 ) ;
return V_209 ;
}
static bool F_225 ( const struct V_203 * V_211 ,
const struct V_203 * V_212 )
{
if ( V_211 -> V_134 != V_212 -> V_134 )
return false ;
if ( ! F_226 ( V_211 -> V_126 , V_212 -> V_126 ) )
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
F_132 ( & V_14 -> V_44 ) ;
F_132 ( & V_14 -> V_52 ) ;
F_229 ( V_14 -> V_213 ) ;
F_230 ( & V_14 -> V_119 ) ;
V_14 -> V_119 . V_112 = F_148 ;
V_14 -> V_119 . V_32 = ( unsigned long ) V_14 ;
F_231 ( & V_14 -> V_143 , F_152 ,
( unsigned long ) V_14 ) ;
F_232 ( & V_14 -> V_47 ) ;
F_232 ( & V_14 -> V_124 ) ;
F_132 ( & V_14 -> V_128 ) ;
F_233 ( & V_14 -> V_133 ) ;
F_234 ( & V_14 -> V_214 ) ;
V_14 -> V_69 = 1 ;
V_14 -> V_125 = F_215 ( V_19 ) ;
if ( ! V_14 -> V_125 )
return - V_199 ;
return 0 ;
}
static void F_235 ( struct V_215 * V_216 )
{
struct V_22 * V_23 =
F_168 ( V_216 , struct V_22 , V_216 ) ;
if ( ! ( V_23 -> V_33 & V_70 ) )
F_210 ( V_23 -> V_106 ) ;
else
F_213 ( V_23 -> V_217 ) ;
F_146 ( V_23 -> V_140 ) ;
F_146 ( V_23 ) ;
}
static void F_236 ( struct V_215 * V_216 )
{
struct V_13 * V_14 = F_168 ( V_216 , struct V_13 , V_216 ) ;
F_237 ( & V_14 -> V_133 ) ;
F_213 ( V_14 -> V_125 ) ;
F_146 ( V_14 ) ;
}
static void F_238 ( struct V_13 * V_14 )
{
F_239 ( V_130 ) ;
struct V_51 * V_51 ;
F_20 ( & V_16 ) ;
if ( -- V_14 -> V_69 )
return;
if ( F_116 ( ! ( V_14 -> V_56 < 0 ) ) ||
F_116 ( ! F_51 ( & V_14 -> V_44 ) ) )
return;
if ( V_14 -> V_20 >= 0 )
F_240 ( & V_17 , V_14 -> V_20 ) ;
F_241 ( & V_14 -> V_214 ) ;
F_134 ( & V_14 -> V_47 ) ;
F_80 ( & V_14 -> V_68 ) ;
while ( ( V_51 = F_57 ( V_14 ) ) )
F_147 ( V_51 ) ;
F_116 ( V_14 -> V_49 || V_14 -> V_45 ) ;
F_81 ( & V_14 -> V_68 ) ;
F_134 ( & V_14 -> V_124 ) ;
if ( ! F_51 ( & V_14 -> V_128 ) )
V_14 -> V_130 = & V_130 ;
F_136 ( & V_14 -> V_124 ) ;
if ( V_14 -> V_130 )
F_181 ( V_14 -> V_130 ) ;
F_136 ( & V_14 -> V_47 ) ;
F_200 ( & V_14 -> V_119 ) ;
F_200 ( & V_14 -> V_143 ) ;
F_242 ( & V_14 -> V_216 , F_236 ) ;
}
static struct V_13 * F_243 ( const struct V_203 * V_125 )
{
T_5 V_209 = F_220 ( V_125 ) ;
struct V_13 * V_14 ;
int V_24 ;
int V_218 = V_25 ;
F_20 ( & V_16 ) ;
F_72 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_225 ( V_14 -> V_125 , V_125 ) ) {
V_14 -> V_69 ++ ;
return V_14 ;
}
}
if ( V_219 ) {
F_244 (node) {
if ( F_245 ( V_125 -> V_126 ,
V_220 [ V_24 ] ) ) {
V_218 = V_24 ;
break;
}
}
}
V_14 = F_131 ( sizeof( * V_14 ) , V_19 , V_218 ) ;
if ( ! V_14 || F_227 ( V_14 ) < 0 )
goto V_88;
F_246 ( & V_14 -> V_68 , 1 ) ;
F_219 ( V_14 -> V_125 , V_125 ) ;
V_14 -> V_24 = V_218 ;
V_14 -> V_125 -> V_208 = false ;
if ( F_19 ( V_14 ) < 0 )
goto V_88;
if ( ! F_139 ( V_14 ) )
goto V_88;
F_247 ( V_221 , & V_14 -> V_214 , V_209 ) ;
return V_14 ;
V_88:
if ( V_14 )
F_238 ( V_14 ) ;
return NULL ;
}
static void F_248 ( struct V_215 * V_216 )
{
F_249 ( V_222 ,
F_168 ( V_216 , struct V_21 , V_216 ) ) ;
}
static void F_250 ( struct V_2 * V_4 )
{
struct V_21 * V_34 = F_168 ( V_4 , struct V_21 ,
V_71 ) ;
struct V_22 * V_23 = V_34 -> V_23 ;
struct V_13 * V_14 = V_34 -> V_14 ;
bool V_223 ;
if ( F_30 ( ! ( V_23 -> V_33 & V_70 ) ) )
return;
F_134 ( & V_23 -> V_179 ) ;
F_251 ( & V_34 -> V_224 ) ;
V_223 = F_51 ( & V_23 -> V_225 ) ;
F_136 ( & V_23 -> V_179 ) ;
F_134 ( & V_16 ) ;
F_238 ( V_14 ) ;
F_136 ( & V_16 ) ;
F_242 ( & V_34 -> V_216 , F_248 ) ;
if ( V_223 )
F_242 ( & V_23 -> V_216 , F_235 ) ;
}
static void F_252 ( struct V_21 * V_34 )
{
struct V_22 * V_23 = V_34 -> V_23 ;
bool V_226 = V_23 -> V_33 & V_227 ;
F_20 ( & V_23 -> V_179 ) ;
if ( ! V_226 && V_34 -> V_80 == V_23 -> V_189 )
return;
F_80 ( & V_34 -> V_14 -> V_68 ) ;
if ( ! V_226 || ! V_228 ) {
V_34 -> V_80 = V_23 -> V_189 ;
while ( ! F_51 ( & V_34 -> V_76 ) &&
V_34 -> V_75 < V_34 -> V_80 )
F_85 ( V_34 ) ;
F_59 ( V_34 -> V_14 ) ;
} else {
V_34 -> V_80 = 0 ;
}
F_81 ( & V_34 -> V_14 -> V_68 ) ;
}
static void F_253 ( struct V_21 * V_34 , struct V_22 * V_23 ,
struct V_13 * V_14 )
{
F_254 ( ( unsigned long ) V_34 & V_229 ) ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
V_34 -> V_14 = V_14 ;
V_34 -> V_23 = V_23 ;
V_34 -> V_81 = - 1 ;
V_34 -> V_69 = 1 ;
F_132 ( & V_34 -> V_76 ) ;
F_132 ( & V_34 -> V_224 ) ;
F_132 ( & V_34 -> V_141 ) ;
F_207 ( & V_34 -> V_71 , F_250 ) ;
}
static void F_255 ( struct V_21 * V_34 )
{
struct V_22 * V_23 = V_34 -> V_23 ;
F_20 ( & V_23 -> V_179 ) ;
if ( ! F_51 ( & V_34 -> V_224 ) )
return;
V_34 -> V_108 = V_23 -> V_108 ;
F_252 ( V_34 ) ;
F_256 ( & V_34 -> V_224 , & V_23 -> V_225 ) ;
}
static struct V_21 * F_257 ( struct V_22 * V_23 ,
const struct V_203 * V_125 )
{
struct V_13 * V_14 ;
struct V_21 * V_34 ;
F_20 ( & V_16 ) ;
V_14 = F_243 ( V_125 ) ;
if ( ! V_14 )
return NULL ;
V_34 = F_258 ( V_222 , V_19 , V_14 -> V_24 ) ;
if ( ! V_34 ) {
F_238 ( V_14 ) ;
return NULL ;
}
F_253 ( V_34 , V_23 , V_14 ) ;
return V_34 ;
}
static bool F_259 ( const struct V_203 * V_125 , int V_24 ,
int V_230 , T_6 * V_126 )
{
if ( ! V_219 || V_125 -> V_208 )
goto V_231;
F_260 ( V_126 , F_261 ( V_24 ) , V_125 -> V_126 ) ;
if ( V_230 >= 0 )
F_262 ( V_230 , V_126 ) ;
if ( F_105 ( V_126 ) )
goto V_231;
F_260 ( V_126 , V_125 -> V_126 , V_220 [ V_24 ] ) ;
return ! F_226 ( V_126 , V_125 -> V_126 ) ;
V_231:
F_218 ( V_126 , V_125 -> V_126 ) ;
return false ;
}
static struct V_21 * F_263 ( struct V_22 * V_23 ,
int V_24 ,
struct V_21 * V_34 )
{
struct V_21 * V_232 ;
F_20 ( & V_16 ) ;
F_20 ( & V_23 -> V_179 ) ;
F_255 ( V_34 ) ;
V_232 = F_264 ( V_23 -> V_27 [ V_24 ] ) ;
F_265 ( V_23 -> V_27 [ V_24 ] , V_34 ) ;
return V_232 ;
}
static void F_266 ( struct V_233 * V_234 )
{
if ( V_234 ) {
int V_24 ;
F_244 (node)
F_79 ( V_234 -> V_235 [ V_24 ] ) ;
F_79 ( V_234 -> V_26 ) ;
F_213 ( V_234 -> V_125 ) ;
F_146 ( V_234 ) ;
}
}
static struct V_233 *
F_267 ( struct V_22 * V_23 ,
const struct V_203 * V_125 )
{
struct V_233 * V_234 ;
struct V_203 * V_236 , * V_237 ;
int V_24 ;
F_20 ( & V_16 ) ;
V_234 = F_216 ( sizeof( * V_234 ) + V_238 * sizeof( V_234 -> V_235 [ 0 ] ) ,
V_19 ) ;
V_236 = F_215 ( V_19 ) ;
V_237 = F_215 ( V_19 ) ;
if ( ! V_234 || ! V_236 || ! V_237 )
goto V_239;
F_219 ( V_236 , V_125 ) ;
F_260 ( V_236 -> V_126 , V_236 -> V_126 , V_96 ) ;
if ( F_24 ( F_105 ( V_236 -> V_126 ) ) )
F_218 ( V_236 -> V_126 , V_96 ) ;
F_219 ( V_237 , V_236 ) ;
V_234 -> V_26 = F_257 ( V_23 , V_236 ) ;
if ( ! V_234 -> V_26 )
goto V_239;
F_244 (node) {
if ( F_259 ( V_236 , V_24 , - 1 , V_237 -> V_126 ) ) {
V_234 -> V_235 [ V_24 ] = F_257 ( V_23 , V_237 ) ;
if ( ! V_234 -> V_235 [ V_24 ] )
goto V_239;
} else {
V_234 -> V_26 -> V_69 ++ ;
V_234 -> V_235 [ V_24 ] = V_234 -> V_26 ;
}
}
F_219 ( V_236 , V_125 ) ;
F_260 ( V_236 -> V_126 , V_236 -> V_126 , V_205 ) ;
V_234 -> V_125 = V_236 ;
V_234 -> V_23 = V_23 ;
F_213 ( V_237 ) ;
return V_234 ;
V_239:
F_213 ( V_237 ) ;
F_213 ( V_236 ) ;
F_266 ( V_234 ) ;
return NULL ;
}
static void F_268 ( struct V_233 * V_234 )
{
int V_24 ;
F_134 ( & V_234 -> V_23 -> V_179 ) ;
F_219 ( V_234 -> V_23 -> V_217 , V_234 -> V_125 ) ;
F_244 (node)
V_234 -> V_235 [ V_24 ] = F_263 ( V_234 -> V_23 , V_24 ,
V_234 -> V_235 [ V_24 ] ) ;
F_255 ( V_234 -> V_26 ) ;
F_269 ( V_234 -> V_23 -> V_26 , V_234 -> V_26 ) ;
F_136 ( & V_234 -> V_23 -> V_179 ) ;
}
static void F_270 ( void )
{
F_205 () ;
F_134 ( & V_16 ) ;
}
static void F_271 ( void )
{
F_136 ( & V_16 ) ;
F_209 () ;
}
static int F_272 ( struct V_22 * V_23 ,
const struct V_203 * V_125 )
{
struct V_233 * V_234 ;
if ( F_116 ( ! ( V_23 -> V_33 & V_70 ) ) )
return - V_240 ;
if ( F_116 ( ( V_23 -> V_33 & V_241 ) && ! F_51 ( & V_23 -> V_225 ) ) )
return - V_240 ;
V_234 = F_267 ( V_23 , V_125 ) ;
if ( ! V_234 )
return - V_199 ;
F_268 ( V_234 ) ;
F_266 ( V_234 ) ;
return 0 ;
}
int F_273 ( struct V_22 * V_23 ,
const struct V_203 * V_125 )
{
int V_15 ;
F_270 () ;
V_15 = F_272 ( V_23 , V_125 ) ;
F_271 () ;
return V_15 ;
}
static void F_274 ( struct V_22 * V_23 , int V_56 ,
bool V_242 )
{
int V_24 = F_113 ( V_56 ) ;
int V_243 = V_242 ? - 1 : V_56 ;
struct V_21 * V_232 = NULL , * V_34 ;
struct V_203 * V_244 ;
T_6 * V_126 ;
F_20 ( & V_16 ) ;
if ( ! V_219 || ! ( V_23 -> V_33 & V_70 ) ||
V_23 -> V_217 -> V_208 )
return;
V_244 = V_245 ;
V_126 = V_244 -> V_126 ;
F_219 ( V_244 , V_23 -> V_217 ) ;
V_34 = F_22 ( V_23 , V_24 ) ;
if ( F_259 ( V_23 -> V_26 -> V_14 -> V_125 , V_24 , V_243 , V_126 ) ) {
if ( F_226 ( V_126 , V_34 -> V_14 -> V_125 -> V_126 ) )
return;
} else {
goto V_246;
}
V_34 = F_257 ( V_23 , V_244 ) ;
if ( ! V_34 ) {
F_104 ( L_12 ,
V_23 -> V_107 ) ;
goto V_246;
}
F_134 ( & V_23 -> V_179 ) ;
V_232 = F_263 ( V_23 , V_24 , V_34 ) ;
goto V_181;
V_246:
F_134 ( & V_23 -> V_179 ) ;
F_80 ( & V_23 -> V_26 -> V_14 -> V_68 ) ;
F_76 ( V_23 -> V_26 ) ;
F_81 ( & V_23 -> V_26 -> V_14 -> V_68 ) ;
V_232 = F_263 ( V_23 , V_24 , V_23 -> V_26 ) ;
V_181:
F_136 ( & V_23 -> V_179 ) ;
F_79 ( V_232 ) ;
}
static int F_275 ( struct V_22 * V_23 )
{
bool V_247 = V_23 -> V_33 & V_248 ;
int V_56 , V_15 ;
if ( ! ( V_23 -> V_33 & V_70 ) ) {
V_23 -> V_106 = F_204 ( struct V_21 ) ;
if ( ! V_23 -> V_106 )
return - V_199 ;
F_276 (cpu) {
struct V_21 * V_34 =
F_112 ( V_23 -> V_106 , V_56 ) ;
struct V_13 * V_249 =
F_277 ( V_250 , V_56 ) ;
F_253 ( V_34 , V_23 , & V_249 [ V_247 ] ) ;
F_134 ( & V_23 -> V_179 ) ;
F_255 ( V_34 ) ;
F_136 ( & V_23 -> V_179 ) ;
}
return 0 ;
} else if ( V_23 -> V_33 & V_241 ) {
V_15 = F_273 ( V_23 , V_251 [ V_247 ] ) ;
F_278 ( ! V_15 && ( V_23 -> V_225 . V_116 != & V_23 -> V_26 -> V_224 ||
V_23 -> V_225 . V_138 != & V_23 -> V_26 -> V_224 ) ,
L_13 , V_23 -> V_107 ) ;
return V_15 ;
} else {
return F_273 ( V_23 , V_252 [ V_247 ] ) ;
}
}
static int F_279 ( int V_80 , unsigned int V_33 ,
const char * V_107 )
{
int V_253 = V_33 & V_70 ? V_254 : V_255 ;
if ( V_80 < 1 || V_80 > V_253 )
F_104 ( L_14 ,
V_80 , V_107 , 1 , V_253 ) ;
return F_280 ( V_80 , 1 , V_253 ) ;
}
struct V_22 * F_281 ( const char * V_256 ,
unsigned int V_33 ,
int V_80 ,
struct V_257 * V_192 ,
const char * V_258 , ... )
{
T_7 V_259 = 0 ;
T_8 args ;
struct V_22 * V_23 ;
struct V_21 * V_34 ;
if ( ( V_33 & V_260 ) && V_261 )
V_33 |= V_70 ;
if ( V_33 & V_70 )
V_259 = V_238 * sizeof( V_23 -> V_27 [ 0 ] ) ;
V_23 = F_216 ( sizeof( * V_23 ) + V_259 , V_19 ) ;
if ( ! V_23 )
return NULL ;
if ( V_33 & V_70 ) {
V_23 -> V_217 = F_215 ( V_19 ) ;
if ( ! V_23 -> V_217 )
goto V_262;
}
va_start ( args , V_258 ) ;
vsnprintf ( V_23 -> V_107 , sizeof( V_23 -> V_107 ) , V_256 , args ) ;
va_end ( args ) ;
V_80 = V_80 ? : V_263 ;
V_80 = F_279 ( V_80 , V_33 , V_23 -> V_107 ) ;
V_23 -> V_33 = V_33 ;
V_23 -> V_189 = V_80 ;
F_232 ( & V_23 -> V_179 ) ;
F_174 ( & V_23 -> V_82 , 0 ) ;
F_132 ( & V_23 -> V_225 ) ;
F_132 ( & V_23 -> V_182 ) ;
F_132 ( & V_23 -> V_180 ) ;
F_132 ( & V_23 -> V_142 ) ;
F_282 ( & V_23 -> V_178 , V_258 , V_192 , 0 ) ;
F_132 ( & V_23 -> V_176 ) ;
if ( F_275 ( V_23 ) < 0 )
goto V_262;
if ( V_33 & V_162 ) {
struct V_51 * V_140 ;
V_140 = F_130 ( V_25 ) ;
if ( ! V_140 )
goto V_264;
V_140 -> V_153 = V_23 ;
V_140 -> V_54 = F_283 ( F_162 , V_140 , L_15 ,
V_23 -> V_107 ) ;
if ( F_142 ( V_140 -> V_54 ) ) {
F_146 ( V_140 ) ;
goto V_264;
}
V_23 -> V_140 = V_140 ;
F_144 ( V_140 -> V_54 , V_205 ) ;
F_61 ( V_140 -> V_54 ) ;
}
if ( ( V_23 -> V_33 & V_265 ) && F_284 ( V_23 ) )
goto V_264;
F_134 ( & V_16 ) ;
F_134 ( & V_23 -> V_179 ) ;
F_175 (pwq, wq)
F_252 ( V_34 ) ;
F_136 ( & V_23 -> V_179 ) ;
F_285 ( & V_23 -> V_176 , & V_266 ) ;
F_136 ( & V_16 ) ;
return V_23 ;
V_262:
F_213 ( V_23 -> V_217 ) ;
F_146 ( V_23 ) ;
return NULL ;
V_264:
F_286 ( V_23 ) ;
return NULL ;
}
void F_286 ( struct V_22 * V_23 )
{
struct V_21 * V_34 ;
int V_24 ;
F_183 ( V_23 ) ;
F_134 ( & V_23 -> V_179 ) ;
F_175 (pwq, wq) {
int V_267 ;
for ( V_267 = 0 ; V_267 < V_31 ; V_267 ++ ) {
if ( F_116 ( V_34 -> V_79 [ V_267 ] ) ) {
F_136 ( & V_23 -> V_179 ) ;
return;
}
}
if ( F_116 ( ( V_34 != V_23 -> V_26 ) && ( V_34 -> V_69 > 1 ) ) ||
F_116 ( V_34 -> V_75 ) ||
F_116 ( ! F_51 ( & V_34 -> V_76 ) ) ) {
F_136 ( & V_23 -> V_179 ) ;
return;
}
}
F_136 ( & V_23 -> V_179 ) ;
F_134 ( & V_16 ) ;
F_251 ( & V_23 -> V_176 ) ;
F_136 ( & V_16 ) ;
F_287 ( V_23 ) ;
if ( V_23 -> V_140 )
F_288 ( V_23 -> V_140 -> V_54 ) ;
if ( ! ( V_23 -> V_33 & V_70 ) ) {
F_242 ( & V_23 -> V_216 , F_235 ) ;
} else {
F_244 (node) {
V_34 = F_264 ( V_23 -> V_27 [ V_24 ] ) ;
F_289 ( V_23 -> V_27 [ V_24 ] , NULL ) ;
F_79 ( V_34 ) ;
}
V_34 = V_23 -> V_26 ;
V_23 -> V_26 = NULL ;
F_79 ( V_34 ) ;
}
}
void F_290 ( struct V_22 * V_23 , int V_80 )
{
struct V_21 * V_34 ;
if ( F_116 ( V_23 -> V_33 & V_241 ) )
return;
V_80 = F_279 ( V_80 , V_23 -> V_33 , V_23 -> V_107 ) ;
F_134 ( & V_23 -> V_179 ) ;
V_23 -> V_189 = V_80 ;
F_175 (pwq, wq)
F_252 ( V_34 ) ;
F_136 ( & V_23 -> V_179 ) ;
}
bool F_291 ( void )
{
struct V_51 * V_51 = F_101 () ;
return V_51 && V_51 -> V_153 ;
}
bool F_292 ( int V_56 , struct V_22 * V_23 )
{
struct V_21 * V_34 ;
bool V_15 ;
F_293 () ;
if ( V_56 == V_105 )
V_56 = F_294 () ;
if ( ! ( V_23 -> V_33 & V_70 ) )
V_34 = F_112 ( V_23 -> V_106 , V_56 ) ;
else
V_34 = F_22 ( V_23 , F_113 ( V_56 ) ) ;
V_15 = ! F_51 ( & V_34 -> V_76 ) ;
F_295 () ;
return V_15 ;
}
unsigned int F_296 ( struct V_2 * V_4 )
{
struct V_13 * V_14 ;
unsigned long V_33 ;
unsigned int V_15 = 0 ;
if ( F_31 ( V_4 ) )
V_15 |= V_268 ;
F_89 ( V_33 ) ;
V_14 = F_42 ( V_4 ) ;
if ( V_14 ) {
F_93 ( & V_14 -> V_68 ) ;
if ( F_71 ( V_14 , V_4 ) )
V_15 |= V_269 ;
F_95 ( & V_14 -> V_68 ) ;
}
F_96 ( V_33 ) ;
return V_15 ;
}
void F_297 ( const char * V_256 , ... )
{
struct V_51 * V_51 = F_101 () ;
T_8 args ;
if ( V_51 ) {
va_start ( args , V_256 ) ;
vsnprintf ( V_51 -> V_270 , sizeof( V_51 -> V_270 ) , V_256 , args ) ;
va_end ( args ) ;
V_51 -> V_271 = true ;
}
}
void F_298 ( const char * V_272 , struct V_55 * V_54 )
{
T_1 * V_200 = NULL ;
char V_107 [ V_273 ] = { } ;
char V_270 [ V_274 ] = { } ;
struct V_21 * V_34 = NULL ;
struct V_22 * V_23 = NULL ;
bool V_271 = false ;
struct V_51 * V_51 ;
if ( ! ( V_54 -> V_33 & V_147 ) )
return;
V_51 = F_299 ( V_54 ) ;
F_300 ( & V_200 , & V_51 -> V_62 , sizeof( V_200 ) ) ;
F_300 ( & V_34 , & V_51 -> V_92 , sizeof( V_34 ) ) ;
F_300 ( & V_23 , & V_34 -> V_23 , sizeof( V_23 ) ) ;
F_300 ( V_107 , V_23 -> V_107 , sizeof( V_107 ) - 1 ) ;
F_300 ( & V_271 , & V_51 -> V_271 , sizeof( V_271 ) ) ;
if ( V_271 )
F_300 ( V_270 , V_51 -> V_270 , sizeof( V_270 ) - 1 ) ;
if ( V_200 || V_107 [ 0 ] || V_270 [ 0 ] ) {
F_301 ( L_16 , V_272 , V_107 , V_200 ) ;
if ( V_270 [ 0 ] )
F_302 ( L_17 , V_270 ) ;
F_302 ( L_18 ) ;
}
}
static void F_303 ( struct V_13 * V_14 )
{
F_302 ( L_19 , V_210 , V_14 -> V_125 -> V_126 ) ;
if ( V_14 -> V_24 != V_25 )
F_302 ( L_20 , V_14 -> V_24 ) ;
F_302 ( L_21 , V_14 -> V_33 , V_14 -> V_125 -> V_134 ) ;
}
static void F_304 ( bool V_275 , struct V_2 * V_4 )
{
if ( V_4 -> V_3 == F_167 ) {
struct V_167 * V_168 ;
V_168 = F_168 ( V_4 , struct V_167 , V_4 ) ;
F_302 ( L_22 , V_275 ? L_23 : L_5 ,
F_305 ( V_168 -> V_54 ) ) ;
} else {
F_302 ( L_24 , V_275 ? L_23 : L_5 , V_4 -> V_3 ) ;
}
}
static void F_306 ( struct V_21 * V_34 )
{
struct V_13 * V_14 = V_34 -> V_14 ;
struct V_2 * V_4 ;
struct V_51 * V_51 ;
bool V_276 = false , V_277 = false ;
int V_278 ;
F_307 ( L_25 , V_14 -> V_20 ) ;
F_303 ( V_14 ) ;
F_302 ( L_26 , V_34 -> V_75 , V_34 -> V_80 ,
! F_51 ( & V_34 -> V_141 ) ? L_27 : L_5 ) ;
F_308 (pool->busy_hash, bkt, worker, hentry) {
if ( V_51 -> V_92 == V_34 ) {
V_276 = true ;
break;
}
}
if ( V_276 ) {
bool V_275 = false ;
F_307 ( L_28 ) ;
F_308 (pool->busy_hash, bkt, worker, hentry) {
if ( V_51 -> V_92 != V_34 )
continue;
F_302 ( L_29 , V_275 ? L_23 : L_5 ,
F_305 ( V_51 -> V_54 ) ,
V_51 == V_34 -> V_23 -> V_140 ? L_30 : L_5 ,
V_51 -> V_62 ) ;
F_153 (work, &worker->scheduled, entry)
F_304 ( false , V_4 ) ;
V_275 = true ;
}
F_302 ( L_18 ) ;
}
F_153 (work, &pool->worklist, entry) {
if ( F_40 ( V_4 ) == V_34 ) {
V_277 = true ;
break;
}
}
if ( V_277 ) {
bool V_275 = false ;
F_307 ( L_31 ) ;
F_153 (work, &pool->worklist, entry) {
if ( F_40 ( V_4 ) != V_34 )
continue;
F_304 ( V_275 , V_4 ) ;
V_275 = ! ( * F_4 ( V_4 ) & V_67 ) ;
}
F_302 ( L_18 ) ;
}
if ( ! F_51 ( & V_34 -> V_76 ) ) {
bool V_275 = false ;
F_307 ( L_32 ) ;
F_153 (work, &pwq->delayed_works, entry) {
F_304 ( V_275 , V_4 ) ;
V_275 = ! ( * F_4 ( V_4 ) & V_67 ) ;
}
F_302 ( L_18 ) ;
}
}
void F_309 ( void )
{
struct V_22 * V_23 ;
struct V_13 * V_14 ;
unsigned long V_33 ;
int V_279 ;
F_293 () ;
F_307 ( L_33 ) ;
F_310 (wq, &workqueues, list) {
struct V_21 * V_34 ;
bool V_280 = true ;
F_175 (pwq, wq) {
if ( V_34 -> V_75 || ! F_51 ( & V_34 -> V_76 ) ) {
V_280 = false ;
break;
}
}
if ( V_280 )
continue;
F_307 ( L_34 , V_23 -> V_107 , V_23 -> V_33 ) ;
F_175 (pwq, wq) {
F_311 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
if ( V_34 -> V_75 || ! F_51 ( & V_34 -> V_76 ) )
F_306 ( V_34 ) ;
F_312 ( & V_34 -> V_14 -> V_68 , V_33 ) ;
}
}
F_313 (pool, pi) {
struct V_51 * V_51 ;
bool V_157 = true ;
F_311 ( & V_14 -> V_68 , V_33 ) ;
if ( V_14 -> V_49 == V_14 -> V_45 )
goto V_281;
F_307 ( L_35 , V_14 -> V_20 ) ;
F_303 ( V_14 ) ;
F_302 ( L_36 ,
F_314 ( V_73 - V_14 -> V_72 ) / 1000 ,
V_14 -> V_49 ) ;
if ( V_14 -> V_145 )
F_302 ( L_37 ,
F_305 ( V_14 -> V_145 -> V_54 ) ) ;
F_153 (worker, &pool->idle_list, entry) {
F_302 ( L_38 , V_157 ? L_39 : L_5 ,
F_305 ( V_51 -> V_54 ) ) ;
V_157 = false ;
}
F_302 ( L_18 ) ;
V_281:
F_312 ( & V_14 -> V_68 , V_33 ) ;
}
F_295 () ;
}
static void F_315 ( struct V_2 * V_4 )
{
int V_56 = F_294 () ;
struct V_13 * V_14 ;
struct V_51 * V_51 ;
F_316 (pool, cpu) {
F_134 ( & V_14 -> V_124 ) ;
F_80 ( & V_14 -> V_68 ) ;
F_317 (worker, pool)
V_51 -> V_33 |= V_127 ;
V_14 -> V_33 |= V_121 ;
F_81 ( & V_14 -> V_68 ) ;
F_136 ( & V_14 -> V_124 ) ;
F_161 () ;
F_174 ( & V_14 -> V_43 , 0 ) ;
F_80 ( & V_14 -> V_68 ) ;
F_59 ( V_14 ) ;
F_81 ( & V_14 -> V_68 ) ;
}
}
static void F_318 ( struct V_13 * V_14 )
{
struct V_51 * V_51 ;
F_20 ( & V_14 -> V_124 ) ;
F_317 (worker, pool)
F_30 ( F_135 ( V_51 -> V_54 ,
V_14 -> V_125 -> V_126 ) < 0 ) ;
F_80 ( & V_14 -> V_68 ) ;
if ( ! ( V_14 -> V_33 & V_121 ) ) {
F_81 ( & V_14 -> V_68 ) ;
return;
}
V_14 -> V_33 &= ~ V_121 ;
F_317 (worker, pool) {
unsigned int V_282 = V_51 -> V_33 ;
if ( V_282 & V_114 )
F_61 ( V_51 -> V_54 ) ;
F_30 ( ! ( V_282 & V_127 ) ) ;
V_282 |= V_131 ;
V_282 &= ~ V_127 ;
F_319 ( V_51 -> V_33 ) = V_282 ;
}
F_81 ( & V_14 -> V_68 ) ;
}
static void F_320 ( struct V_13 * V_14 , int V_56 )
{
static T_6 V_126 ;
struct V_51 * V_51 ;
F_20 ( & V_14 -> V_124 ) ;
if ( ! F_103 ( V_56 , V_14 -> V_125 -> V_126 ) )
return;
F_260 ( & V_126 , V_14 -> V_125 -> V_126 , V_98 ) ;
F_317 (worker, pool)
F_30 ( F_135 ( V_51 -> V_54 , & V_126 ) < 0 ) ;
}
int F_321 ( unsigned int V_56 )
{
struct V_13 * V_14 ;
F_316 (pool, cpu) {
if ( V_14 -> V_49 )
continue;
if ( ! F_139 ( V_14 ) )
return - V_199 ;
}
return 0 ;
}
int F_322 ( unsigned int V_56 )
{
struct V_13 * V_14 ;
struct V_22 * V_23 ;
int V_279 ;
F_134 ( & V_16 ) ;
F_313 (pool, pi) {
F_134 ( & V_14 -> V_124 ) ;
if ( V_14 -> V_56 == V_56 )
F_318 ( V_14 ) ;
else if ( V_14 -> V_56 < 0 )
F_320 ( V_14 , V_56 ) ;
F_136 ( & V_14 -> V_124 ) ;
}
F_153 (wq, &workqueues, list)
F_274 ( V_23 , V_56 , true ) ;
F_136 ( & V_16 ) ;
return 0 ;
}
int F_323 ( unsigned int V_56 )
{
struct V_2 V_283 ;
struct V_22 * V_23 ;
F_170 ( & V_283 , F_315 ) ;
F_117 ( V_56 , V_284 , & V_283 ) ;
F_134 ( & V_16 ) ;
F_153 (wq, &workqueues, list)
F_274 ( V_23 , V_56 , false ) ;
F_136 ( & V_16 ) ;
F_189 ( & V_283 ) ;
F_16 ( & V_283 ) ;
return 0 ;
}
static void F_324 ( struct V_2 * V_4 )
{
struct V_285 * V_286 = F_168 ( V_4 , struct V_285 , V_4 ) ;
V_286 -> V_15 = V_286 -> V_200 ( V_286 -> V_287 ) ;
}
long F_325 ( int V_56 , long (* V_200)( void * ) , void * V_287 )
{
struct V_285 V_286 = { . V_200 = V_200 , . V_287 = V_287 } ;
F_170 ( & V_286 . V_4 , F_324 ) ;
F_208 ( V_56 , & V_286 . V_4 ) ;
F_189 ( & V_286 . V_4 ) ;
F_16 ( & V_286 . V_4 ) ;
return V_286 . V_15 ;
}
void F_326 ( void )
{
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_134 ( & V_16 ) ;
F_30 ( V_228 ) ;
V_228 = true ;
F_153 (wq, &workqueues, list) {
F_134 ( & V_23 -> V_179 ) ;
F_175 (pwq, wq)
F_252 ( V_34 ) ;
F_136 ( & V_23 -> V_179 ) ;
}
F_136 ( & V_16 ) ;
}
bool F_327 ( void )
{
bool V_288 = false ;
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_134 ( & V_16 ) ;
F_30 ( ! V_228 ) ;
F_153 (wq, &workqueues, list) {
if ( ! ( V_23 -> V_33 & V_227 ) )
continue;
F_293 () ;
F_175 (pwq, wq) {
F_30 ( V_34 -> V_75 < 0 ) ;
if ( V_34 -> V_75 ) {
V_288 = true ;
F_295 () ;
goto V_181;
}
}
F_295 () ;
}
V_181:
F_136 ( & V_16 ) ;
return V_288 ;
}
void F_328 ( void )
{
struct V_22 * V_23 ;
struct V_21 * V_34 ;
F_134 ( & V_16 ) ;
if ( ! V_228 )
goto V_181;
V_228 = false ;
F_153 (wq, &workqueues, list) {
F_134 ( & V_23 -> V_179 ) ;
F_175 (pwq, wq)
F_252 ( V_34 ) ;
F_136 ( & V_23 -> V_179 ) ;
}
V_181:
F_136 ( & V_16 ) ;
}
static int F_329 ( void )
{
F_330 ( V_289 ) ;
int V_15 = 0 ;
struct V_22 * V_23 ;
struct V_233 * V_234 , * V_66 ;
F_20 ( & V_16 ) ;
F_153 (wq, &workqueues, list) {
if ( ! ( V_23 -> V_33 & V_70 ) )
continue;
if ( V_23 -> V_33 & V_241 )
continue;
V_234 = F_267 ( V_23 , V_23 -> V_217 ) ;
if ( ! V_234 ) {
V_15 = - V_199 ;
break;
}
F_99 ( & V_234 -> V_176 , & V_289 ) ;
}
F_165 (ctx, n, &ctxs, list) {
if ( ! V_15 )
F_268 ( V_234 ) ;
F_266 ( V_234 ) ;
}
return V_15 ;
}
int F_331 ( T_9 V_126 )
{
int V_15 = - V_240 ;
T_9 V_290 ;
if ( ! F_332 ( & V_290 , V_19 ) )
return - V_199 ;
F_260 ( V_126 , V_126 , V_205 ) ;
if ( ! F_105 ( V_126 ) ) {
F_270 () ;
F_218 ( V_290 , V_96 ) ;
F_218 ( V_96 , V_126 ) ;
V_15 = F_329 () ;
if ( V_15 < 0 )
F_218 ( V_96 , V_290 ) ;
F_271 () ;
}
F_214 ( V_290 ) ;
return V_15 ;
}
static struct V_22 * F_333 ( struct V_291 * V_292 )
{
struct V_293 * V_294 = F_168 ( V_292 , struct V_293 , V_292 ) ;
return V_294 -> V_23 ;
}
static T_10 F_334 ( struct V_291 * V_292 , struct V_295 * V_296 ,
char * V_297 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
return F_335 ( V_297 , V_298 , L_40 , ( bool ) ! ( V_23 -> V_33 & V_70 ) ) ;
}
static T_10 F_336 ( struct V_291 * V_292 ,
struct V_295 * V_296 , char * V_297 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
return F_335 ( V_297 , V_298 , L_40 , V_23 -> V_189 ) ;
}
static T_10 F_337 ( struct V_291 * V_292 ,
struct V_295 * V_296 , const char * V_297 ,
T_7 V_299 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
int V_300 ;
if ( sscanf ( V_297 , L_41 , & V_300 ) != 1 || V_300 <= 0 )
return - V_240 ;
F_290 ( V_23 , V_300 ) ;
return V_299 ;
}
static T_10 F_338 ( struct V_291 * V_292 ,
struct V_295 * V_296 , char * V_297 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
const char * V_301 = L_5 ;
int V_24 , V_302 = 0 ;
F_293 () ;
F_244 (node) {
V_302 += F_335 ( V_297 + V_302 , V_298 - V_302 ,
L_42 , V_301 , V_24 ,
F_22 ( V_23 , V_24 ) -> V_14 -> V_20 ) ;
V_301 = L_43 ;
}
V_302 += F_335 ( V_297 + V_302 , V_298 - V_302 , L_18 ) ;
F_295 () ;
return V_302 ;
}
static T_10 F_339 ( struct V_291 * V_292 , struct V_295 * V_296 ,
char * V_297 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
int V_302 ;
F_134 ( & V_23 -> V_179 ) ;
V_302 = F_335 ( V_297 , V_298 , L_40 , V_23 -> V_217 -> V_134 ) ;
F_136 ( & V_23 -> V_179 ) ;
return V_302 ;
}
static struct V_203 * F_340 ( struct V_22 * V_23 )
{
struct V_203 * V_125 ;
F_20 ( & V_16 ) ;
V_125 = F_215 ( V_19 ) ;
if ( ! V_125 )
return NULL ;
F_219 ( V_125 , V_23 -> V_217 ) ;
return V_125 ;
}
static T_10 F_341 ( struct V_291 * V_292 , struct V_295 * V_296 ,
const char * V_297 , T_7 V_299 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
struct V_203 * V_125 ;
int V_15 = - V_199 ;
F_270 () ;
V_125 = F_340 ( V_23 ) ;
if ( ! V_125 )
goto V_181;
if ( sscanf ( V_297 , L_41 , & V_125 -> V_134 ) == 1 &&
V_125 -> V_134 >= V_303 && V_125 -> V_134 <= V_304 )
V_15 = F_272 ( V_23 , V_125 ) ;
else
V_15 = - V_240 ;
V_181:
F_271 () ;
F_213 ( V_125 ) ;
return V_15 ? : V_299 ;
}
static T_10 F_342 ( struct V_291 * V_292 ,
struct V_295 * V_296 , char * V_297 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
int V_302 ;
F_134 ( & V_23 -> V_179 ) ;
V_302 = F_335 ( V_297 , V_298 , L_44 ,
F_343 ( V_23 -> V_217 -> V_126 ) ) ;
F_136 ( & V_23 -> V_179 ) ;
return V_302 ;
}
static T_10 F_344 ( struct V_291 * V_292 ,
struct V_295 * V_296 ,
const char * V_297 , T_7 V_299 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
struct V_203 * V_125 ;
int V_15 = - V_199 ;
F_270 () ;
V_125 = F_340 ( V_23 ) ;
if ( ! V_125 )
goto V_181;
V_15 = F_345 ( V_297 , V_125 -> V_126 ) ;
if ( ! V_15 )
V_15 = F_272 ( V_23 , V_125 ) ;
V_181:
F_271 () ;
F_213 ( V_125 ) ;
return V_15 ? : V_299 ;
}
static T_10 F_346 ( struct V_291 * V_292 , struct V_295 * V_296 ,
char * V_297 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
int V_302 ;
F_134 ( & V_23 -> V_179 ) ;
V_302 = F_335 ( V_297 , V_298 , L_40 ,
! V_23 -> V_217 -> V_208 ) ;
F_136 ( & V_23 -> V_179 ) ;
return V_302 ;
}
static T_10 F_347 ( struct V_291 * V_292 , struct V_295 * V_296 ,
const char * V_297 , T_7 V_299 )
{
struct V_22 * V_23 = F_333 ( V_292 ) ;
struct V_203 * V_125 ;
int V_305 , V_15 = - V_199 ;
F_270 () ;
V_125 = F_340 ( V_23 ) ;
if ( ! V_125 )
goto V_181;
V_15 = - V_240 ;
if ( sscanf ( V_297 , L_41 , & V_305 ) == 1 ) {
V_125 -> V_208 = ! V_305 ;
V_15 = F_272 ( V_23 , V_125 ) ;
}
V_181:
F_271 () ;
F_213 ( V_125 ) ;
return V_15 ? : V_299 ;
}
static T_10 F_348 ( struct V_291 * V_292 ,
struct V_295 * V_296 , char * V_297 )
{
int V_302 ;
F_134 ( & V_16 ) ;
V_302 = F_335 ( V_297 , V_298 , L_44 ,
F_343 ( V_96 ) ) ;
F_136 ( & V_16 ) ;
return V_302 ;
}
static T_10 F_349 ( struct V_291 * V_292 ,
struct V_295 * V_296 , const char * V_297 , T_7 V_299 )
{
T_9 V_126 ;
int V_15 ;
if ( ! F_332 ( & V_126 , V_19 ) )
return - V_199 ;
V_15 = F_345 ( V_297 , V_126 ) ;
if ( ! V_15 )
V_15 = F_331 ( V_126 ) ;
F_214 ( V_126 ) ;
return V_15 ? V_15 : V_299 ;
}
static int T_11 F_350 ( void )
{
int V_306 ;
V_306 = F_351 ( & V_307 , NULL ) ;
if ( V_306 )
return V_306 ;
return F_352 ( V_307 . V_308 , & V_309 ) ;
}
static void F_353 ( struct V_291 * V_292 )
{
struct V_293 * V_294 = F_168 ( V_292 , struct V_293 , V_292 ) ;
F_146 ( V_294 ) ;
}
int F_284 ( struct V_22 * V_23 )
{
struct V_293 * V_294 ;
int V_15 ;
if ( F_116 ( V_23 -> V_33 & V_241 ) )
return - V_240 ;
V_23 -> V_294 = V_294 = F_216 ( sizeof( * V_294 ) , V_19 ) ;
if ( ! V_294 )
return - V_199 ;
V_294 -> V_23 = V_23 ;
V_294 -> V_292 . V_310 = & V_307 ;
V_294 -> V_292 . V_311 = F_353 ;
F_354 ( & V_294 -> V_292 , L_15 , V_23 -> V_107 ) ;
F_355 ( & V_294 -> V_292 , true ) ;
V_15 = F_356 ( & V_294 -> V_292 ) ;
if ( V_15 ) {
F_146 ( V_294 ) ;
V_23 -> V_294 = NULL ;
return V_15 ;
}
if ( V_23 -> V_33 & V_70 ) {
struct V_295 * V_296 ;
for ( V_296 = V_312 ; V_296 -> V_296 . V_107 ; V_296 ++ ) {
V_15 = F_352 ( & V_294 -> V_292 , V_296 ) ;
if ( V_15 ) {
F_357 ( & V_294 -> V_292 ) ;
V_23 -> V_294 = NULL ;
return V_15 ;
}
}
}
F_355 ( & V_294 -> V_292 , false ) ;
F_358 ( & V_294 -> V_292 . V_313 , V_314 ) ;
return 0 ;
}
static void F_287 ( struct V_22 * V_23 )
{
struct V_293 * V_294 = V_23 -> V_294 ;
if ( ! V_23 -> V_294 )
return;
V_23 -> V_294 = NULL ;
F_357 ( & V_294 -> V_292 ) ;
}
static void F_287 ( struct V_22 * V_23 ) { }
static void F_359 ( void )
{
int V_56 ;
V_315 = V_73 ;
F_276 (cpu)
F_277 ( V_316 , V_56 ) = V_73 ;
}
static void F_360 ( unsigned long V_32 )
{
unsigned long V_317 = F_361 ( V_318 ) * V_319 ;
bool V_320 = false ;
struct V_13 * V_14 ;
int V_279 ;
if ( ! V_317 )
return;
F_362 () ;
F_313 (pool, pi) {
unsigned long V_321 , V_322 , V_323 ;
if ( F_51 ( & V_14 -> V_44 ) )
continue;
V_321 = F_361 ( V_14 -> V_72 ) ;
V_322 = F_361 ( V_315 ) ;
if ( F_363 ( V_321 , V_322 ) )
V_323 = V_321 ;
else
V_323 = V_322 ;
if ( V_14 -> V_56 >= 0 ) {
unsigned long V_324 =
F_361 ( F_277 ( V_316 ,
V_14 -> V_56 ) ) ;
if ( F_363 ( V_324 , V_323 ) )
V_323 = V_324 ;
}
if ( F_363 ( V_73 , V_323 + V_317 ) ) {
V_320 = true ;
F_364 ( L_45 ) ;
F_303 ( V_14 ) ;
F_302 ( L_46 ,
F_314 ( V_73 - V_321 ) / 1000 ) ;
}
}
F_365 () ;
if ( V_320 )
F_309 () ;
F_359 () ;
F_128 ( & V_325 , V_73 + V_317 ) ;
}
void F_366 ( int V_56 )
{
if ( V_56 >= 0 )
F_277 ( V_316 , V_56 ) = V_73 ;
else
V_315 = V_73 ;
}
static void F_367 ( unsigned long V_317 )
{
V_318 = 0 ;
F_200 ( & V_325 ) ;
if ( V_317 ) {
V_318 = V_317 ;
F_359 () ;
F_128 ( & V_325 , V_73 + V_317 * V_319 ) ;
}
}
static int F_368 ( const char * V_300 ,
const struct V_326 * V_327 )
{
unsigned long V_317 ;
int V_15 ;
V_15 = F_369 ( V_300 , 0 , & V_317 ) ;
if ( V_15 )
return V_15 ;
if ( V_328 )
F_367 ( V_317 ) ;
else
V_318 = V_317 ;
return 0 ;
}
static void F_370 ( void )
{
F_367 ( V_318 ) ;
}
static inline void F_370 ( void ) { }
static void T_11 F_371 ( void )
{
T_9 * V_329 ;
int V_24 , V_56 ;
if ( F_372 () <= 1 )
return;
if ( V_330 ) {
F_307 ( L_47 ) ;
return;
}
V_245 = F_215 ( V_19 ) ;
F_254 ( ! V_245 ) ;
V_329 = F_216 ( V_238 * sizeof( V_329 [ 0 ] ) , V_19 ) ;
F_254 ( ! V_329 ) ;
F_244 (node)
F_254 ( ! F_373 ( & V_329 [ V_24 ] , V_19 ,
F_374 ( V_24 ) ? V_24 : V_25 ) ) ;
F_276 (cpu) {
V_24 = F_113 ( V_56 ) ;
if ( F_116 ( V_24 == V_25 ) ) {
F_104 ( L_48 , V_56 ) ;
return;
}
F_375 ( V_56 , V_329 [ V_24 ] ) ;
}
V_220 = V_329 ;
V_219 = true ;
}
static int T_11 F_376 ( void )
{
int V_331 [ V_332 ] = { 0 , V_333 } ;
int V_267 , V_56 ;
F_116 ( F_377 ( struct V_21 ) < F_377 (long long) ) ;
F_254 ( ! F_217 ( & V_96 , V_19 ) ) ;
F_218 ( V_96 , V_205 ) ;
V_222 = F_378 ( V_21 , V_334 ) ;
F_371 () ;
F_276 (cpu) {
struct V_13 * V_14 ;
V_267 = 0 ;
F_316 (pool, cpu) {
F_254 ( F_227 ( V_14 ) ) ;
V_14 -> V_56 = V_56 ;
F_218 ( V_14 -> V_125 -> V_126 , F_379 ( V_56 ) ) ;
V_14 -> V_125 -> V_134 = V_331 [ V_267 ++ ] ;
V_14 -> V_24 = F_113 ( V_56 ) ;
F_134 ( & V_16 ) ;
F_254 ( F_19 ( V_14 ) ) ;
F_136 ( & V_16 ) ;
}
}
F_206 (cpu) {
struct V_13 * V_14 ;
F_316 (pool, cpu) {
V_14 -> V_33 &= ~ V_121 ;
F_254 ( ! F_139 ( V_14 ) ) ;
}
}
for ( V_267 = 0 ; V_267 < V_332 ; V_267 ++ ) {
struct V_203 * V_125 ;
F_254 ( ! ( V_125 = F_215 ( V_19 ) ) ) ;
V_125 -> V_134 = V_331 [ V_267 ] ;
V_252 [ V_267 ] = V_125 ;
F_254 ( ! ( V_125 = F_215 ( V_19 ) ) ) ;
V_125 -> V_134 = V_331 [ V_267 ] ;
V_125 -> V_208 = true ;
V_251 [ V_267 ] = V_125 ;
}
V_328 = F_380 ( L_49 , 0 , 0 ) ;
V_284 = F_380 ( L_50 , V_248 , 0 ) ;
V_335 = F_380 ( L_51 , 0 , 0 ) ;
V_336 = F_380 ( L_52 , V_70 ,
V_254 ) ;
V_337 = F_380 ( L_53 ,
V_227 , 0 ) ;
V_338 = F_380 ( L_54 ,
V_260 , 0 ) ;
V_339 = F_380 ( L_55 ,
V_227 | V_260 ,
0 ) ;
F_254 ( ! V_328 || ! V_284 || ! V_335 ||
! V_336 || ! V_337 ||
! V_338 ||
! V_339 ) ;
F_370 () ;
return 0 ;
}
