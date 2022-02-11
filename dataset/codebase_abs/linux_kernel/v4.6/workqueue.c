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
if ( F_26 ( V_25 == V_26 ) )
return V_24 -> V_27 ;
return F_27 ( V_24 -> V_28 [ V_25 ] ) ;
}
static unsigned int F_28 ( int V_29 )
{
return V_29 << V_30 ;
}
static int F_29 ( struct V_2 * V_6 )
{
return ( * F_7 ( V_6 ) >> V_30 ) &
( ( 1 << V_31 ) - 1 ) ;
}
static int F_30 ( int V_29 )
{
return ( V_29 + 1 ) % V_32 ;
}
static inline void F_31 ( struct V_2 * V_6 , unsigned long V_33 ,
unsigned long V_34 )
{
F_9 ( ! F_32 ( V_6 ) ) ;
F_33 ( & V_6 -> V_33 , V_33 | V_34 | F_34 ( V_6 ) ) ;
}
static void F_35 ( struct V_2 * V_6 , struct V_22 * V_35 ,
unsigned long V_36 )
{
F_31 ( V_6 , ( unsigned long ) V_35 ,
V_37 | V_38 | V_36 ) ;
}
static void F_36 ( struct V_2 * V_6 ,
int V_39 )
{
F_31 ( V_6 , ( unsigned long ) V_39 << V_40 ,
V_37 ) ;
}
static void F_37 ( struct V_2 * V_6 ,
int V_39 )
{
F_38 () ;
F_31 ( V_6 , ( unsigned long ) V_39 << V_40 , 0 ) ;
F_39 () ;
}
static void F_40 ( struct V_2 * V_6 )
{
F_38 () ;
F_31 ( V_6 , V_41 , 0 ) ;
}
static struct V_22 * F_41 ( struct V_2 * V_6 )
{
unsigned long V_33 = F_42 ( & V_6 -> V_33 ) ;
if ( V_33 & V_38 )
return ( void * ) ( V_33 & V_42 ) ;
else
return NULL ;
}
static struct V_14 * F_43 ( struct V_2 * V_6 )
{
unsigned long V_33 = F_42 ( & V_6 -> V_33 ) ;
int V_39 ;
F_44 () ;
if ( V_33 & V_38 )
return ( (struct V_22 * )
( V_33 & V_42 ) ) -> V_15 ;
V_39 = V_33 >> V_40 ;
if ( V_39 == V_19 )
return NULL ;
return F_45 ( & V_18 , V_39 ) ;
}
static int F_46 ( struct V_2 * V_6 )
{
unsigned long V_33 = F_42 ( & V_6 -> V_33 ) ;
if ( V_33 & V_38 )
return ( (struct V_22 * )
( V_33 & V_42 ) ) -> V_15 -> V_21 ;
return V_33 >> V_40 ;
}
static void F_47 ( struct V_2 * V_6 )
{
unsigned long V_39 = F_46 ( V_6 ) ;
V_39 <<= V_40 ;
F_31 ( V_6 , V_39 | V_43 , V_37 ) ;
}
static bool F_48 ( struct V_2 * V_6 )
{
unsigned long V_33 = F_42 ( & V_6 -> V_33 ) ;
return ! ( V_33 & V_38 ) && ( V_33 & V_43 ) ;
}
static bool F_49 ( struct V_14 * V_15 )
{
return ! F_50 ( & V_15 -> V_44 ) ;
}
static bool F_51 ( struct V_14 * V_15 )
{
return ! F_52 ( & V_15 -> V_45 ) && F_49 ( V_15 ) ;
}
static bool F_53 ( struct V_14 * V_15 )
{
return V_15 -> V_46 ;
}
static bool F_54 ( struct V_14 * V_15 )
{
return ! F_52 ( & V_15 -> V_45 ) &&
F_50 ( & V_15 -> V_44 ) <= 1 ;
}
static bool F_55 ( struct V_14 * V_15 )
{
return F_51 ( V_15 ) && ! F_53 ( V_15 ) ;
}
static bool F_56 ( struct V_14 * V_15 )
{
bool V_47 = F_57 ( & V_15 -> V_48 ) ;
int V_46 = V_15 -> V_46 + V_47 ;
int V_49 = V_15 -> V_50 - V_46 ;
return V_46 > 2 && ( V_46 - 2 ) * V_51 >= V_49 ;
}
static struct V_52 * F_58 ( struct V_14 * V_15 )
{
if ( F_26 ( F_52 ( & V_15 -> V_53 ) ) )
return NULL ;
return F_59 ( & V_15 -> V_53 , struct V_52 , V_54 ) ;
}
static void F_60 ( struct V_14 * V_15 )
{
struct V_52 * V_52 = F_58 ( V_15 ) ;
if ( F_61 ( V_52 ) )
F_62 ( V_52 -> V_55 ) ;
}
void F_63 ( struct V_56 * V_55 , int V_57 )
{
struct V_52 * V_52 = F_64 ( V_55 ) ;
if ( ! ( V_52 -> V_34 & V_58 ) ) {
F_9 ( V_52 -> V_15 -> V_57 != V_57 ) ;
F_65 ( & V_52 -> V_15 -> V_44 ) ;
}
}
struct V_56 * F_66 ( struct V_56 * V_55 )
{
struct V_52 * V_52 = F_64 ( V_55 ) , * V_59 = NULL ;
struct V_14 * V_15 ;
if ( V_52 -> V_34 & V_58 )
return NULL ;
V_15 = V_52 -> V_15 ;
if ( F_9 ( V_15 -> V_57 != F_67 () ) )
return NULL ;
if ( F_68 ( & V_15 -> V_44 ) &&
! F_52 ( & V_15 -> V_45 ) )
V_59 = F_58 ( V_15 ) ;
return V_59 ? V_59 -> V_55 : NULL ;
}
static inline void F_69 ( struct V_52 * V_52 , unsigned int V_34 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
F_9 ( V_52 -> V_55 != V_60 ) ;
if ( ( V_34 & V_58 ) &&
! ( V_52 -> V_34 & V_58 ) ) {
F_70 ( & V_15 -> V_44 ) ;
}
V_52 -> V_34 |= V_34 ;
}
static inline void F_71 ( struct V_52 * V_52 , unsigned int V_34 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
unsigned int V_61 = V_52 -> V_34 ;
F_9 ( V_52 -> V_55 != V_60 ) ;
V_52 -> V_34 &= ~ V_34 ;
if ( ( V_34 & V_58 ) && ( V_61 & V_58 ) )
if ( ! ( V_52 -> V_34 & V_58 ) )
F_65 ( & V_15 -> V_44 ) ;
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
F_76 ( & V_6 -> V_54 , V_65 ) ;
if ( ! ( * F_7 ( V_6 ) & V_68 ) )
break;
}
if ( V_66 )
* V_66 = V_67 ;
}
static void F_77 ( struct V_22 * V_35 )
{
F_22 ( & V_35 -> V_15 -> V_69 ) ;
F_9 ( V_35 -> V_70 <= 0 ) ;
V_35 -> V_70 ++ ;
}
static void F_78 ( struct V_22 * V_35 )
{
F_22 ( & V_35 -> V_15 -> V_69 ) ;
if ( F_61 ( -- V_35 -> V_70 ) )
return;
if ( F_9 ( ! ( V_35 -> V_24 -> V_34 & V_71 ) ) )
return;
F_79 ( & V_35 -> V_72 ) ;
}
static void F_80 ( struct V_22 * V_35 )
{
if ( V_35 ) {
F_81 ( & V_35 -> V_15 -> V_69 ) ;
F_78 ( V_35 ) ;
F_82 ( & V_35 -> V_15 -> V_69 ) ;
}
}
static void F_83 ( struct V_2 * V_6 )
{
struct V_22 * V_35 = F_41 ( V_6 ) ;
F_84 ( V_6 ) ;
if ( F_52 ( & V_35 -> V_15 -> V_45 ) )
V_35 -> V_15 -> V_73 = V_74 ;
F_74 ( V_6 , & V_35 -> V_15 -> V_45 , NULL ) ;
F_85 ( V_75 , F_7 ( V_6 ) ) ;
V_35 -> V_76 ++ ;
}
static void F_86 ( struct V_22 * V_35 )
{
struct V_2 * V_6 = F_59 ( & V_35 -> V_77 ,
struct V_2 , V_54 ) ;
F_83 ( V_6 ) ;
}
static void F_87 ( struct V_22 * V_35 , int V_29 )
{
if ( V_29 == V_78 )
goto V_79;
V_35 -> V_80 [ V_29 ] -- ;
V_35 -> V_76 -- ;
if ( ! F_52 ( & V_35 -> V_77 ) ) {
if ( V_35 -> V_76 < V_35 -> V_81 )
F_86 ( V_35 ) ;
}
if ( F_61 ( V_35 -> V_82 != V_29 ) )
goto V_79;
if ( V_35 -> V_80 [ V_29 ] )
goto V_79;
V_35 -> V_82 = - 1 ;
if ( F_68 ( & V_35 -> V_24 -> V_83 ) )
F_88 ( & V_35 -> V_24 -> V_84 -> V_85 ) ;
V_79:
F_78 ( V_35 ) ;
}
static int F_89 ( struct V_2 * V_6 , bool V_86 ,
unsigned long * V_34 )
{
struct V_14 * V_15 ;
struct V_22 * V_35 ;
F_90 ( * V_34 ) ;
if ( V_86 ) {
struct V_12 * V_87 = F_91 ( V_6 ) ;
if ( F_61 ( F_92 ( & V_87 -> V_13 ) ) )
return 1 ;
}
if ( ! F_93 ( V_88 , F_7 ( V_6 ) ) )
return 0 ;
V_15 = F_43 ( V_6 ) ;
if ( ! V_15 )
goto V_89;
F_94 ( & V_15 -> V_69 ) ;
V_35 = F_41 ( V_6 ) ;
if ( V_35 && V_35 -> V_15 == V_15 ) {
F_14 ( V_6 ) ;
if ( * F_7 ( V_6 ) & V_90 )
F_83 ( V_6 ) ;
F_95 ( & V_6 -> V_54 ) ;
F_87 ( V_35 , F_29 ( V_6 ) ) ;
F_36 ( V_6 , V_15 -> V_21 ) ;
F_96 ( & V_15 -> V_69 ) ;
return 1 ;
}
F_96 ( & V_15 -> V_69 ) ;
V_89:
F_97 ( * V_34 ) ;
if ( F_48 ( V_6 ) )
return - V_91 ;
F_98 () ;
return - V_92 ;
}
static void F_99 ( struct V_22 * V_35 , struct V_2 * V_6 ,
struct V_64 * V_65 , unsigned int V_36 )
{
struct V_14 * V_15 = V_35 -> V_15 ;
F_35 ( V_6 , V_35 , V_36 ) ;
F_100 ( & V_6 -> V_54 , V_65 ) ;
F_77 ( V_35 ) ;
F_39 () ;
if ( F_49 ( V_15 ) )
F_60 ( V_15 ) ;
}
static bool F_101 ( struct V_23 * V_24 )
{
struct V_52 * V_52 ;
V_52 = F_102 () ;
return V_52 && V_52 -> V_93 -> V_24 == V_24 ;
}
static int F_103 ( int V_57 )
{
static bool V_94 ;
int V_95 ;
if ( F_61 ( ! V_96 ) ) {
if ( F_104 ( V_57 , V_97 ) )
return V_57 ;
} else if ( ! V_94 ) {
F_105 ( L_1 ) ;
V_94 = true ;
}
if ( F_106 ( V_97 ) )
return V_57 ;
V_95 = F_107 ( V_98 ) ;
V_95 = F_108 ( V_95 , V_97 , V_99 ) ;
if ( F_26 ( V_95 >= V_100 ) ) {
V_95 = F_109 ( V_97 , V_99 ) ;
if ( F_26 ( V_95 >= V_100 ) )
return V_57 ;
}
F_110 ( V_98 , V_95 ) ;
return V_95 ;
}
static void F_111 ( int V_57 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
struct V_22 * V_35 ;
struct V_14 * V_101 ;
struct V_64 * V_45 ;
unsigned int V_102 ;
unsigned int V_103 = V_57 ;
F_9 ( ! F_112 () ) ;
F_13 ( V_6 ) ;
if ( F_26 ( V_24 -> V_34 & V_104 ) &&
F_9 ( ! F_101 ( V_24 ) ) )
return;
V_105:
if ( V_103 == V_106 )
V_57 = F_103 ( F_67 () ) ;
if ( ! ( V_24 -> V_34 & V_71 ) )
V_35 = F_113 ( V_24 -> V_107 , V_57 ) ;
else
V_35 = F_24 ( V_24 , F_114 ( V_57 ) ) ;
V_101 = F_43 ( V_6 ) ;
if ( V_101 && V_101 != V_35 -> V_15 ) {
struct V_52 * V_52 ;
F_94 ( & V_101 -> V_69 ) ;
V_52 = F_72 ( V_101 , V_6 ) ;
if ( V_52 && V_52 -> V_93 -> V_24 == V_24 ) {
V_35 = V_52 -> V_93 ;
} else {
F_96 ( & V_101 -> V_69 ) ;
F_94 ( & V_35 -> V_15 -> V_69 ) ;
}
} else {
F_94 ( & V_35 -> V_15 -> V_69 ) ;
}
if ( F_26 ( ! V_35 -> V_70 ) ) {
if ( V_24 -> V_34 & V_71 ) {
F_96 ( & V_35 -> V_15 -> V_69 ) ;
F_98 () ;
goto V_105;
}
F_115 ( true , L_2 ,
V_24 -> V_108 , V_57 ) ;
}
F_116 ( V_103 , V_35 , V_6 ) ;
if ( F_10 ( ! F_52 ( & V_6 -> V_54 ) ) ) {
F_96 ( & V_35 -> V_15 -> V_69 ) ;
return;
}
V_35 -> V_80 [ V_35 -> V_109 ] ++ ;
V_102 = F_28 ( V_35 -> V_109 ) ;
if ( F_61 ( V_35 -> V_76 < V_35 -> V_81 ) ) {
F_84 ( V_6 ) ;
V_35 -> V_76 ++ ;
V_45 = & V_35 -> V_15 -> V_45 ;
if ( F_52 ( V_45 ) )
V_35 -> V_15 -> V_73 = V_74 ;
} else {
V_102 |= V_90 ;
V_45 = & V_35 -> V_77 ;
}
F_99 ( V_35 , V_6 , V_45 , V_102 ) ;
F_96 ( & V_35 -> V_15 -> V_69 ) ;
}
bool F_117 ( int V_57 , struct V_23 * V_24 ,
struct V_2 * V_6 )
{
bool V_16 = false ;
unsigned long V_34 ;
F_90 ( V_34 ) ;
if ( ! F_93 ( V_88 , F_7 ( V_6 ) ) ) {
F_111 ( V_57 , V_24 , V_6 ) ;
V_16 = true ;
}
F_97 ( V_34 ) ;
return V_16 ;
}
void F_118 ( unsigned long V_110 )
{
struct V_12 * V_87 = (struct V_12 * ) V_110 ;
F_111 ( V_87 -> V_57 , V_87 -> V_24 , & V_87 -> V_6 ) ;
}
static void F_119 ( int V_57 , struct V_23 * V_24 ,
struct V_12 * V_87 , unsigned long V_111 )
{
struct V_112 * V_13 = & V_87 -> V_13 ;
struct V_2 * V_6 = & V_87 -> V_6 ;
F_9 ( V_13 -> V_113 != F_118 ||
V_13 -> V_33 != ( unsigned long ) V_87 ) ;
F_9 ( F_120 ( V_13 ) ) ;
F_9 ( ! F_52 ( & V_6 -> V_54 ) ) ;
if ( ! V_111 ) {
F_111 ( V_57 , V_24 , & V_87 -> V_6 ) ;
return;
}
F_121 ( & V_87 -> V_13 ) ;
V_87 -> V_24 = V_24 ;
V_87 -> V_57 = V_57 ;
V_13 -> V_114 = V_74 + V_111 ;
if ( F_26 ( V_57 != V_106 ) )
F_122 ( V_13 , V_57 ) ;
else
F_123 ( V_13 ) ;
}
bool F_124 ( int V_57 , struct V_23 * V_24 ,
struct V_12 * V_87 , unsigned long V_111 )
{
struct V_2 * V_6 = & V_87 -> V_6 ;
bool V_16 = false ;
unsigned long V_34 ;
F_90 ( V_34 ) ;
if ( ! F_93 ( V_88 , F_7 ( V_6 ) ) ) {
F_119 ( V_57 , V_24 , V_87 , V_111 ) ;
V_16 = true ;
}
F_97 ( V_34 ) ;
return V_16 ;
}
bool F_125 ( int V_57 , struct V_23 * V_24 ,
struct V_12 * V_87 , unsigned long V_111 )
{
unsigned long V_34 ;
int V_16 ;
do {
V_16 = F_89 ( & V_87 -> V_6 , true , & V_34 ) ;
} while ( F_26 ( V_16 == - V_92 ) );
if ( F_61 ( V_16 >= 0 ) ) {
F_119 ( V_57 , V_24 , V_87 , V_111 ) ;
F_97 ( V_34 ) ;
}
return V_16 ;
}
static void F_126 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
if ( F_9 ( V_52 -> V_34 & V_115 ) ||
F_9 ( ! F_52 ( & V_52 -> V_54 ) &&
( V_52 -> V_116 . V_117 || V_52 -> V_116 . V_118 ) ) )
return;
V_52 -> V_34 |= V_115 ;
V_15 -> V_46 ++ ;
V_52 -> V_119 = V_74 ;
F_127 ( & V_52 -> V_54 , & V_15 -> V_53 ) ;
if ( F_56 ( V_15 ) && ! F_120 ( & V_15 -> V_120 ) )
F_128 ( & V_15 -> V_120 , V_74 + V_121 ) ;
F_9 ( ! ( V_15 -> V_34 & V_122 ) &&
V_15 -> V_50 == V_15 -> V_46 &&
F_50 ( & V_15 -> V_44 ) ) ;
}
static void F_129 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
if ( F_9 ( ! ( V_52 -> V_34 & V_115 ) ) )
return;
F_71 ( V_52 , V_115 ) ;
V_15 -> V_46 -- ;
F_95 ( & V_52 -> V_54 ) ;
}
static struct V_52 * F_130 ( int V_25 )
{
struct V_52 * V_52 ;
V_52 = F_131 ( sizeof( * V_52 ) , V_20 , V_25 ) ;
if ( V_52 ) {
F_132 ( & V_52 -> V_54 ) ;
F_132 ( & V_52 -> V_123 ) ;
F_132 ( & V_52 -> V_25 ) ;
V_52 -> V_34 = V_124 ;
}
return V_52 ;
}
static void F_133 ( struct V_52 * V_52 ,
struct V_14 * V_15 )
{
F_134 ( & V_15 -> V_125 ) ;
F_135 ( V_52 -> V_55 , V_15 -> V_126 -> V_127 ) ;
if ( V_15 -> V_34 & V_122 )
V_52 -> V_34 |= V_128 ;
F_100 ( & V_52 -> V_25 , & V_15 -> V_129 ) ;
F_136 ( & V_15 -> V_125 ) ;
}
static void F_137 ( struct V_52 * V_52 ,
struct V_14 * V_15 )
{
struct V_130 * V_131 = NULL ;
F_134 ( & V_15 -> V_125 ) ;
F_138 ( & V_52 -> V_25 ) ;
if ( F_52 ( & V_15 -> V_129 ) )
V_131 = V_15 -> V_131 ;
F_136 ( & V_15 -> V_125 ) ;
V_52 -> V_34 &= ~ ( V_128 | V_132 ) ;
if ( V_131 )
F_88 ( V_131 ) ;
}
static struct V_52 * F_139 ( struct V_14 * V_15 )
{
struct V_52 * V_52 = NULL ;
int V_21 = - 1 ;
char V_133 [ 16 ] ;
V_21 = F_140 ( & V_15 -> V_134 , 0 , 0 , V_20 ) ;
if ( V_21 < 0 )
goto V_89;
V_52 = F_130 ( V_15 -> V_25 ) ;
if ( ! V_52 )
goto V_89;
V_52 -> V_15 = V_15 ;
V_52 -> V_21 = V_21 ;
if ( V_15 -> V_57 >= 0 )
snprintf ( V_133 , sizeof( V_133 ) , L_3 , V_15 -> V_57 , V_21 ,
V_15 -> V_126 -> V_135 < 0 ? L_4 : L_5 ) ;
else
snprintf ( V_133 , sizeof( V_133 ) , L_6 , V_15 -> V_21 , V_21 ) ;
V_52 -> V_55 = F_141 ( V_136 , V_52 , V_15 -> V_25 ,
L_7 , V_133 ) ;
if ( F_142 ( V_52 -> V_55 ) )
goto V_89;
F_143 ( V_52 -> V_55 , V_15 -> V_126 -> V_135 ) ;
F_144 ( V_52 -> V_55 , V_15 -> V_126 -> V_127 ) ;
F_133 ( V_52 , V_15 ) ;
F_81 ( & V_15 -> V_69 ) ;
V_52 -> V_15 -> V_50 ++ ;
F_126 ( V_52 ) ;
F_62 ( V_52 -> V_55 ) ;
F_82 ( & V_15 -> V_69 ) ;
return V_52 ;
V_89:
if ( V_21 >= 0 )
F_145 ( & V_15 -> V_134 , V_21 ) ;
F_146 ( V_52 ) ;
return NULL ;
}
static void F_147 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
F_22 ( & V_15 -> V_69 ) ;
if ( F_10 ( V_52 -> V_62 ) ||
F_10 ( ! F_52 ( & V_52 -> V_123 ) ) ||
F_10 ( ! ( V_52 -> V_34 & V_115 ) ) )
return;
V_15 -> V_50 -- ;
V_15 -> V_46 -- ;
F_95 ( & V_52 -> V_54 ) ;
V_52 -> V_34 |= V_137 ;
F_62 ( V_52 -> V_55 ) ;
}
static void F_148 ( unsigned long V_138 )
{
struct V_14 * V_15 = ( void * ) V_138 ;
F_81 ( & V_15 -> V_69 ) ;
while ( F_56 ( V_15 ) ) {
struct V_52 * V_52 ;
unsigned long V_114 ;
V_52 = F_149 ( V_15 -> V_53 . V_139 , struct V_52 , V_54 ) ;
V_114 = V_52 -> V_119 + V_121 ;
if ( F_150 ( V_74 , V_114 ) ) {
F_128 ( & V_15 -> V_120 , V_114 ) ;
break;
}
F_147 ( V_52 ) ;
}
F_82 ( & V_15 -> V_69 ) ;
}
static void F_151 ( struct V_2 * V_6 )
{
struct V_22 * V_35 = F_41 ( V_6 ) ;
struct V_23 * V_24 = V_35 -> V_24 ;
F_22 ( & V_140 ) ;
if ( ! V_24 -> V_141 )
return;
if ( F_52 ( & V_35 -> V_142 ) ) {
F_77 ( V_35 ) ;
F_100 ( & V_35 -> V_142 , & V_24 -> V_143 ) ;
F_62 ( V_24 -> V_141 -> V_55 ) ;
}
}
static void F_152 ( unsigned long V_138 )
{
struct V_14 * V_15 = ( void * ) V_138 ;
struct V_2 * V_6 ;
F_81 ( & V_15 -> V_69 ) ;
F_94 ( & V_140 ) ;
if ( F_55 ( V_15 ) ) {
F_153 (work, &pool->worklist, entry)
F_151 ( V_6 ) ;
}
F_96 ( & V_140 ) ;
F_82 ( & V_15 -> V_69 ) ;
F_128 ( & V_15 -> V_144 , V_74 + V_145 ) ;
}
static void F_154 ( struct V_14 * V_15 )
__releases( &pool->lock
static bool F_155 ( struct V_52 * V_52 )
{
struct V_14 * V_15 = V_52 -> V_15 ;
if ( ! F_156 ( & V_15 -> V_48 ) )
return false ;
V_15 -> V_146 = V_52 ;
F_154 ( V_15 ) ;
V_15 -> V_146 = NULL ;
F_136 ( & V_15 -> V_48 ) ;
return true ;
}
static void F_157 ( struct V_52 * V_52 , struct V_2 * V_6 )
__releases( &pool->lock
static void F_158 ( struct V_52 * V_52 )
{
while ( ! F_52 ( & V_52 -> V_123 ) ) {
struct V_2 * V_6 = F_59 ( & V_52 -> V_123 ,
struct V_2 , V_54 ) ;
F_157 ( V_52 , V_6 ) ;
}
}
static int V_136 ( void * V_147 )
{
struct V_52 * V_52 = V_147 ;
struct V_14 * V_15 = V_52 -> V_15 ;
V_52 -> V_55 -> V_34 |= V_148 ;
V_149:
F_81 ( & V_15 -> V_69 ) ;
if ( F_26 ( V_52 -> V_34 & V_137 ) ) {
F_82 ( & V_15 -> V_69 ) ;
F_9 ( ! F_52 ( & V_52 -> V_54 ) ) ;
V_52 -> V_55 -> V_34 &= ~ V_148 ;
F_159 ( V_52 -> V_55 , L_8 ) ;
F_145 ( & V_15 -> V_134 , V_52 -> V_21 ) ;
F_137 ( V_52 , V_15 ) ;
F_146 ( V_52 ) ;
return 0 ;
}
F_129 ( V_52 ) ;
V_150:
if ( ! F_51 ( V_15 ) )
goto V_151;
if ( F_26 ( ! F_53 ( V_15 ) ) && F_155 ( V_52 ) )
goto V_150;
F_9 ( ! F_52 ( & V_52 -> V_123 ) ) ;
F_71 ( V_52 , V_124 | V_132 ) ;
do {
struct V_2 * V_6 =
F_59 ( & V_15 -> V_45 ,
struct V_2 , V_54 ) ;
V_15 -> V_73 = V_74 ;
if ( F_61 ( ! ( * F_7 ( V_6 ) & V_68 ) ) ) {
F_157 ( V_52 , V_6 ) ;
if ( F_26 ( ! F_52 ( & V_52 -> V_123 ) ) )
F_158 ( V_52 ) ;
} else {
F_74 ( V_6 , & V_52 -> V_123 , NULL ) ;
F_158 ( V_52 ) ;
}
} while ( F_54 ( V_15 ) );
F_69 ( V_52 , V_124 ) ;
V_151:
F_126 ( V_52 ) ;
F_160 ( V_152 ) ;
F_82 ( & V_15 -> V_69 ) ;
F_161 () ;
goto V_149;
}
static int F_162 ( void * V_153 )
{
struct V_52 * V_141 = V_153 ;
struct V_23 * V_24 = V_141 -> V_154 ;
struct V_64 * V_123 = & V_141 -> V_123 ;
bool V_155 ;
F_143 ( V_60 , V_156 ) ;
V_141 -> V_55 -> V_34 |= V_148 ;
V_157:
F_163 ( V_152 ) ;
V_155 = F_164 () ;
F_81 ( & V_140 ) ;
while ( ! F_52 ( & V_24 -> V_143 ) ) {
struct V_22 * V_35 = F_59 ( & V_24 -> V_143 ,
struct V_22 , V_142 ) ;
struct V_14 * V_15 = V_35 -> V_15 ;
struct V_2 * V_6 , * V_67 ;
bool V_158 = true ;
F_160 ( V_159 ) ;
F_95 ( & V_35 -> V_142 ) ;
F_82 ( & V_140 ) ;
F_133 ( V_141 , V_15 ) ;
F_81 ( & V_15 -> V_69 ) ;
V_141 -> V_15 = V_15 ;
F_9 ( ! F_52 ( V_123 ) ) ;
F_165 (work, n, &pool->worklist, entry) {
if ( F_41 ( V_6 ) == V_35 ) {
if ( V_158 )
V_15 -> V_73 = V_74 ;
F_74 ( V_6 , V_123 , & V_67 ) ;
}
V_158 = false ;
}
if ( ! F_52 ( V_123 ) ) {
F_158 ( V_141 ) ;
if ( F_55 ( V_15 ) ) {
F_94 ( & V_140 ) ;
F_77 ( V_35 ) ;
F_76 ( & V_35 -> V_142 , & V_24 -> V_143 ) ;
F_96 ( & V_140 ) ;
}
}
F_78 ( V_35 ) ;
if ( F_51 ( V_15 ) )
F_60 ( V_15 ) ;
V_141 -> V_15 = NULL ;
F_82 ( & V_15 -> V_69 ) ;
F_137 ( V_141 , V_15 ) ;
F_81 ( & V_140 ) ;
}
F_82 ( & V_140 ) ;
if ( V_155 ) {
F_160 ( V_159 ) ;
V_141 -> V_55 -> V_34 &= ~ V_148 ;
return 0 ;
}
F_9 ( ! ( V_141 -> V_34 & V_58 ) ) ;
F_161 () ;
goto V_157;
}
static void F_166 ( struct V_23 * V_160 ,
struct V_2 * V_161 )
{
T_1 V_162 = V_161 ? V_161 -> V_3 : NULL ;
struct V_52 * V_52 ;
if ( V_160 -> V_34 & V_163 )
return;
V_52 = F_102 () ;
F_115 ( V_60 -> V_34 & V_164 ,
L_9 ,
V_60 -> V_165 , V_60 -> V_166 , V_160 -> V_108 , V_162 ) ;
F_115 ( V_52 && ( ( V_52 -> V_93 -> V_24 -> V_34 &
( V_163 | V_167 ) ) == V_163 ) ,
L_10 ,
V_52 -> V_93 -> V_24 -> V_108 , V_52 -> V_63 ,
V_160 -> V_108 , V_162 ) ;
}
static void F_167 ( struct V_2 * V_6 )
{
struct V_168 * V_169 = F_168 ( V_6 , struct V_168 , V_6 ) ;
F_88 ( & V_169 -> V_85 ) ;
}
static void F_169 ( struct V_22 * V_35 ,
struct V_168 * V_169 ,
struct V_2 * V_170 , struct V_52 * V_52 )
{
struct V_64 * V_65 ;
unsigned int V_171 = 0 ;
F_170 ( & V_169 -> V_6 , F_167 ) ;
F_171 ( V_88 , F_7 ( & V_169 -> V_6 ) ) ;
F_172 ( & V_169 -> V_85 ) ;
V_169 -> V_55 = V_60 ;
if ( V_52 )
V_65 = V_52 -> V_123 . V_117 ;
else {
unsigned long * V_172 = F_7 ( V_170 ) ;
V_65 = V_170 -> V_54 . V_117 ;
V_171 = * V_172 & V_68 ;
F_171 ( V_173 , V_172 ) ;
}
F_13 ( & V_169 -> V_6 ) ;
F_99 ( V_35 , & V_169 -> V_6 , V_65 ,
F_28 ( V_78 ) | V_171 ) ;
}
static bool F_173 ( struct V_23 * V_24 ,
int V_82 , int V_109 )
{
bool V_174 = false ;
struct V_22 * V_35 ;
if ( V_82 >= 0 ) {
F_9 ( F_50 ( & V_24 -> V_83 ) ) ;
F_174 ( & V_24 -> V_83 , 1 ) ;
}
F_175 (pwq, wq) {
struct V_14 * V_15 = V_35 -> V_15 ;
F_81 ( & V_15 -> V_69 ) ;
if ( V_82 >= 0 ) {
F_9 ( V_35 -> V_82 != - 1 ) ;
if ( V_35 -> V_80 [ V_82 ] ) {
V_35 -> V_82 = V_82 ;
F_65 ( & V_24 -> V_83 ) ;
V_174 = true ;
}
}
if ( V_109 >= 0 ) {
F_9 ( V_109 != F_30 ( V_35 -> V_109 ) ) ;
V_35 -> V_109 = V_109 ;
}
F_82 ( & V_15 -> V_69 ) ;
}
if ( V_82 >= 0 && F_68 ( & V_24 -> V_83 ) )
F_88 ( & V_24 -> V_84 -> V_85 ) ;
return V_174 ;
}
void F_176 ( struct V_23 * V_24 )
{
struct V_175 V_176 = {
. V_177 = F_177 ( V_176 . V_177 ) ,
. V_82 = - 1 ,
. V_85 = F_178 ( V_176 . V_85 ) ,
} ;
int V_178 ;
F_179 ( & V_24 -> V_179 ) ;
F_180 ( & V_24 -> V_179 ) ;
F_134 ( & V_24 -> V_180 ) ;
V_178 = F_30 ( V_24 -> V_109 ) ;
if ( V_178 != V_24 -> V_82 ) {
F_9 ( ! F_52 ( & V_24 -> V_181 ) ) ;
V_176 . V_82 = V_24 -> V_109 ;
V_24 -> V_109 = V_178 ;
if ( ! V_24 -> V_84 ) {
F_9 ( V_24 -> V_82 != V_176 . V_82 ) ;
V_24 -> V_84 = & V_176 ;
if ( ! F_173 ( V_24 , V_24 -> V_82 ,
V_24 -> V_109 ) ) {
V_24 -> V_82 = V_178 ;
V_24 -> V_84 = NULL ;
goto V_182;
}
} else {
F_9 ( V_24 -> V_82 == V_176 . V_82 ) ;
F_100 ( & V_176 . V_177 , & V_24 -> V_183 ) ;
F_173 ( V_24 , - 1 , V_24 -> V_109 ) ;
}
} else {
F_100 ( & V_176 . V_177 , & V_24 -> V_181 ) ;
}
F_166 ( V_24 , NULL ) ;
F_136 ( & V_24 -> V_180 ) ;
F_181 ( & V_176 . V_85 ) ;
if ( V_24 -> V_84 != & V_176 )
return;
F_134 ( & V_24 -> V_180 ) ;
if ( V_24 -> V_84 != & V_176 )
goto V_182;
V_24 -> V_84 = NULL ;
F_9 ( ! F_52 ( & V_176 . V_177 ) ) ;
F_9 ( V_24 -> V_82 != V_176 . V_82 ) ;
while ( true ) {
struct V_175 * V_117 , * V_184 ;
F_165 (next, tmp, &wq->flusher_queue, list) {
if ( V_117 -> V_82 != V_24 -> V_82 )
break;
F_95 ( & V_117 -> V_177 ) ;
F_88 ( & V_117 -> V_85 ) ;
}
F_9 ( ! F_52 ( & V_24 -> V_181 ) &&
V_24 -> V_82 != F_30 ( V_24 -> V_109 ) ) ;
V_24 -> V_82 = F_30 ( V_24 -> V_82 ) ;
if ( ! F_52 ( & V_24 -> V_181 ) ) {
F_153 (tmp, &wq->flusher_overflow, list)
V_184 -> V_82 = V_24 -> V_109 ;
V_24 -> V_109 = F_30 ( V_24 -> V_109 ) ;
F_182 ( & V_24 -> V_181 ,
& V_24 -> V_183 ) ;
F_173 ( V_24 , - 1 , V_24 -> V_109 ) ;
}
if ( F_52 ( & V_24 -> V_183 ) ) {
F_9 ( V_24 -> V_82 != V_24 -> V_109 ) ;
break;
}
F_9 ( V_24 -> V_82 == V_24 -> V_109 ) ;
F_9 ( V_24 -> V_82 != V_117 -> V_82 ) ;
F_95 ( & V_117 -> V_177 ) ;
V_24 -> V_84 = V_117 ;
if ( F_173 ( V_24 , V_24 -> V_82 , - 1 ) )
break;
V_24 -> V_84 = NULL ;
}
V_182:
F_136 ( & V_24 -> V_180 ) ;
}
void F_183 ( struct V_23 * V_24 )
{
unsigned int V_185 = 0 ;
struct V_22 * V_35 ;
F_134 ( & V_24 -> V_180 ) ;
if ( ! V_24 -> V_186 ++ )
V_24 -> V_34 |= V_104 ;
F_136 ( & V_24 -> V_180 ) ;
V_187:
F_176 ( V_24 ) ;
F_134 ( & V_24 -> V_180 ) ;
F_175 (pwq, wq) {
bool V_188 ;
F_81 ( & V_35 -> V_15 -> V_69 ) ;
V_188 = ! V_35 -> V_76 && F_52 ( & V_35 -> V_77 ) ;
F_82 ( & V_35 -> V_15 -> V_69 ) ;
if ( V_188 )
continue;
if ( ++ V_185 == 10 ||
( V_185 % 100 == 0 && V_185 <= 1000 ) )
F_105 ( L_11 ,
V_24 -> V_108 , V_185 ) ;
F_136 ( & V_24 -> V_180 ) ;
goto V_187;
}
if ( ! -- V_24 -> V_186 )
V_24 -> V_34 &= ~ V_104 ;
F_136 ( & V_24 -> V_180 ) ;
}
static bool F_184 ( struct V_2 * V_6 , struct V_168 * V_169 )
{
struct V_52 * V_52 = NULL ;
struct V_14 * V_15 ;
struct V_22 * V_35 ;
F_185 () ;
F_186 () ;
V_15 = F_43 ( V_6 ) ;
if ( ! V_15 ) {
F_187 () ;
return false ;
}
F_94 ( & V_15 -> V_69 ) ;
V_35 = F_41 ( V_6 ) ;
if ( V_35 ) {
if ( F_26 ( V_35 -> V_15 != V_15 ) )
goto V_189;
} else {
V_52 = F_72 ( V_15 , V_6 ) ;
if ( ! V_52 )
goto V_189;
V_35 = V_52 -> V_93 ;
}
F_166 ( V_35 -> V_24 , V_6 ) ;
F_169 ( V_35 , V_169 , V_6 , V_52 ) ;
F_82 ( & V_15 -> V_69 ) ;
if ( V_35 -> V_24 -> V_190 == 1 || V_35 -> V_24 -> V_141 )
F_179 ( & V_35 -> V_24 -> V_179 ) ;
else
F_188 ( & V_35 -> V_24 -> V_179 ) ;
F_180 ( & V_35 -> V_24 -> V_179 ) ;
return true ;
V_189:
F_82 ( & V_15 -> V_69 ) ;
return false ;
}
bool F_189 ( struct V_2 * V_6 )
{
struct V_168 V_169 ;
F_179 ( & V_6 -> V_179 ) ;
F_180 ( & V_6 -> V_179 ) ;
if ( F_184 ( V_6 , & V_169 ) ) {
F_181 ( & V_169 . V_85 ) ;
F_18 ( & V_169 . V_6 ) ;
return true ;
} else {
return false ;
}
}
static int F_190 ( T_2 * V_174 , unsigned V_191 , int V_192 , void * V_193 )
{
struct V_194 * V_195 = F_168 ( V_174 , struct V_194 , V_174 ) ;
if ( V_195 -> V_6 != V_193 )
return 0 ;
return F_191 ( V_174 , V_191 , V_192 , V_193 ) ;
}
static bool F_192 ( struct V_2 * V_6 , bool V_86 )
{
static F_193 ( V_196 ) ;
unsigned long V_34 ;
int V_16 ;
do {
V_16 = F_89 ( V_6 , V_86 , & V_34 ) ;
if ( F_26 ( V_16 == - V_91 ) ) {
struct V_194 V_195 ;
F_194 ( & V_195 . V_174 ) ;
V_195 . V_174 . V_3 = F_190 ;
V_195 . V_6 = V_6 ;
F_195 ( & V_196 , & V_195 . V_174 ,
V_197 ) ;
if ( F_48 ( V_6 ) )
F_161 () ;
F_196 ( & V_196 , & V_195 . V_174 ) ;
}
} while ( F_26 ( V_16 < 0 ) );
F_47 ( V_6 ) ;
F_97 ( V_34 ) ;
F_189 ( V_6 ) ;
F_40 ( V_6 ) ;
F_39 () ;
if ( F_197 ( & V_196 ) )
F_198 ( & V_196 , V_198 , 1 , V_6 ) ;
return V_16 ;
}
bool F_3 ( struct V_2 * V_6 )
{
return F_192 ( V_6 , false ) ;
}
bool F_199 ( struct V_12 * V_87 )
{
F_186 () ;
if ( F_200 ( & V_87 -> V_13 ) )
F_111 ( V_87 -> V_57 , V_87 -> V_24 , & V_87 -> V_6 ) ;
F_187 () ;
return F_189 ( & V_87 -> V_6 ) ;
}
bool F_201 ( struct V_12 * V_87 )
{
unsigned long V_34 ;
int V_16 ;
do {
V_16 = F_89 ( & V_87 -> V_6 , true , & V_34 ) ;
} while ( F_26 ( V_16 == - V_92 ) );
if ( F_26 ( V_16 < 0 ) )
return false ;
F_37 ( & V_87 -> V_6 ,
F_46 ( & V_87 -> V_6 ) ) ;
F_97 ( V_34 ) ;
return V_16 ;
}
bool F_202 ( struct V_12 * V_87 )
{
return F_192 ( & V_87 -> V_6 , true ) ;
}
int F_203 ( T_1 V_3 )
{
int V_57 ;
struct V_2 T_3 * V_199 ;
V_199 = F_204 ( struct V_2 ) ;
if ( ! V_199 )
return - V_200 ;
F_205 () ;
F_206 (cpu) {
struct V_2 * V_6 = F_113 ( V_199 , V_57 ) ;
F_207 ( V_6 , V_3 ) ;
F_208 ( V_57 , V_6 ) ;
}
F_206 (cpu)
F_189 ( F_113 ( V_199 , V_57 ) ) ;
F_209 () ;
F_210 ( V_199 ) ;
return 0 ;
}
int F_211 ( T_1 V_201 , struct V_202 * V_203 )
{
if ( ! F_212 () ) {
V_201 ( & V_203 -> V_6 ) ;
return 0 ;
}
F_207 ( & V_203 -> V_6 , V_201 ) ;
F_79 ( & V_203 -> V_6 ) ;
return 1 ;
}
void F_213 ( struct V_204 * V_126 )
{
if ( V_126 ) {
F_214 ( V_126 -> V_127 ) ;
F_146 ( V_126 ) ;
}
}
struct V_204 * F_215 ( T_4 V_205 )
{
struct V_204 * V_126 ;
V_126 = F_216 ( sizeof( * V_126 ) , V_205 ) ;
if ( ! V_126 )
goto V_89;
if ( ! F_217 ( & V_126 -> V_127 , V_205 ) )
goto V_89;
F_218 ( V_126 -> V_127 , V_206 ) ;
return V_126 ;
V_89:
F_213 ( V_126 ) ;
return NULL ;
}
static void F_219 ( struct V_204 * V_207 ,
const struct V_204 * V_208 )
{
V_207 -> V_135 = V_208 -> V_135 ;
F_218 ( V_207 -> V_127 , V_208 -> V_127 ) ;
V_207 -> V_209 = V_208 -> V_209 ;
}
static T_5 F_220 ( const struct V_204 * V_126 )
{
T_5 V_210 = 0 ;
V_210 = F_221 ( V_126 -> V_135 , V_210 ) ;
V_210 = F_222 ( F_223 ( V_126 -> V_127 ) ,
F_224 ( V_211 ) * sizeof( long ) , V_210 ) ;
return V_210 ;
}
static bool F_225 ( const struct V_204 * V_212 ,
const struct V_204 * V_213 )
{
if ( V_212 -> V_135 != V_213 -> V_135 )
return false ;
if ( ! F_226 ( V_212 -> V_127 , V_213 -> V_127 ) )
return false ;
return true ;
}
static int F_227 ( struct V_14 * V_15 )
{
F_228 ( & V_15 -> V_69 ) ;
V_15 -> V_21 = - 1 ;
V_15 -> V_57 = - 1 ;
V_15 -> V_25 = V_26 ;
V_15 -> V_34 |= V_122 ;
V_15 -> V_73 = V_74 ;
F_132 ( & V_15 -> V_45 ) ;
F_132 ( & V_15 -> V_53 ) ;
F_229 ( V_15 -> V_214 ) ;
F_230 ( & V_15 -> V_120 ) ;
V_15 -> V_120 . V_113 = F_148 ;
V_15 -> V_120 . V_33 = ( unsigned long ) V_15 ;
F_231 ( & V_15 -> V_144 , F_152 ,
( unsigned long ) V_15 ) ;
F_232 ( & V_15 -> V_48 ) ;
F_232 ( & V_15 -> V_125 ) ;
F_132 ( & V_15 -> V_129 ) ;
F_233 ( & V_15 -> V_134 ) ;
F_234 ( & V_15 -> V_215 ) ;
V_15 -> V_70 = 1 ;
V_15 -> V_126 = F_215 ( V_20 ) ;
if ( ! V_15 -> V_126 )
return - V_200 ;
return 0 ;
}
static void F_235 ( struct V_216 * V_217 )
{
struct V_23 * V_24 =
F_168 ( V_217 , struct V_23 , V_217 ) ;
if ( ! ( V_24 -> V_34 & V_71 ) )
F_210 ( V_24 -> V_107 ) ;
else
F_213 ( V_24 -> V_218 ) ;
F_146 ( V_24 -> V_141 ) ;
F_146 ( V_24 ) ;
}
static void F_236 ( struct V_216 * V_217 )
{
struct V_14 * V_15 = F_168 ( V_217 , struct V_14 , V_217 ) ;
F_237 ( & V_15 -> V_134 ) ;
F_213 ( V_15 -> V_126 ) ;
F_146 ( V_15 ) ;
}
static void F_238 ( struct V_14 * V_15 )
{
F_239 ( V_131 ) ;
struct V_52 * V_52 ;
F_22 ( & V_17 ) ;
if ( -- V_15 -> V_70 )
return;
if ( F_10 ( ! ( V_15 -> V_57 < 0 ) ) ||
F_10 ( ! F_52 ( & V_15 -> V_45 ) ) )
return;
if ( V_15 -> V_21 >= 0 )
F_240 ( & V_18 , V_15 -> V_21 ) ;
F_241 ( & V_15 -> V_215 ) ;
F_134 ( & V_15 -> V_48 ) ;
F_81 ( & V_15 -> V_69 ) ;
while ( ( V_52 = F_58 ( V_15 ) ) )
F_147 ( V_52 ) ;
F_10 ( V_15 -> V_50 || V_15 -> V_46 ) ;
F_82 ( & V_15 -> V_69 ) ;
F_134 ( & V_15 -> V_125 ) ;
if ( ! F_52 ( & V_15 -> V_129 ) )
V_15 -> V_131 = & V_131 ;
F_136 ( & V_15 -> V_125 ) ;
if ( V_15 -> V_131 )
F_181 ( V_15 -> V_131 ) ;
F_136 ( & V_15 -> V_48 ) ;
F_200 ( & V_15 -> V_120 ) ;
F_200 ( & V_15 -> V_144 ) ;
F_242 ( & V_15 -> V_217 , F_236 ) ;
}
static struct V_14 * F_243 ( const struct V_204 * V_126 )
{
T_5 V_210 = F_220 ( V_126 ) ;
struct V_14 * V_15 ;
int V_25 ;
int V_219 = V_26 ;
F_22 ( & V_17 ) ;
F_73 (unbound_pool_hash, pool, hash_node, hash) {
if ( F_225 ( V_15 -> V_126 , V_126 ) ) {
V_15 -> V_70 ++ ;
return V_15 ;
}
}
if ( V_220 ) {
F_244 (node) {
if ( F_245 ( V_126 -> V_127 ,
V_221 [ V_25 ] ) ) {
V_219 = V_25 ;
break;
}
}
}
V_15 = F_131 ( sizeof( * V_15 ) , V_20 , V_219 ) ;
if ( ! V_15 || F_227 ( V_15 ) < 0 )
goto V_89;
F_246 ( & V_15 -> V_69 , 1 ) ;
F_219 ( V_15 -> V_126 , V_126 ) ;
V_15 -> V_25 = V_219 ;
V_15 -> V_126 -> V_209 = false ;
if ( F_21 ( V_15 ) < 0 )
goto V_89;
if ( ! F_139 ( V_15 ) )
goto V_89;
F_247 ( V_222 , & V_15 -> V_215 , V_210 ) ;
return V_15 ;
V_89:
if ( V_15 )
F_238 ( V_15 ) ;
return NULL ;
}
static void F_248 ( struct V_216 * V_217 )
{
F_249 ( V_223 ,
F_168 ( V_217 , struct V_22 , V_217 ) ) ;
}
static void F_250 ( struct V_2 * V_6 )
{
struct V_22 * V_35 = F_168 ( V_6 , struct V_22 ,
V_72 ) ;
struct V_23 * V_24 = V_35 -> V_24 ;
struct V_14 * V_15 = V_35 -> V_15 ;
bool V_224 ;
if ( F_9 ( ! ( V_24 -> V_34 & V_71 ) ) )
return;
F_134 ( & V_24 -> V_180 ) ;
F_251 ( & V_35 -> V_225 ) ;
V_224 = F_52 ( & V_24 -> V_226 ) ;
F_136 ( & V_24 -> V_180 ) ;
F_134 ( & V_17 ) ;
F_238 ( V_15 ) ;
F_136 ( & V_17 ) ;
F_242 ( & V_35 -> V_217 , F_248 ) ;
if ( V_224 )
F_242 ( & V_24 -> V_217 , F_235 ) ;
}
static void F_252 ( struct V_22 * V_35 )
{
struct V_23 * V_24 = V_35 -> V_24 ;
bool V_227 = V_24 -> V_34 & V_228 ;
F_22 ( & V_24 -> V_180 ) ;
if ( ! V_227 && V_35 -> V_81 == V_24 -> V_190 )
return;
F_81 ( & V_35 -> V_15 -> V_69 ) ;
if ( ! V_227 || ! V_229 ) {
V_35 -> V_81 = V_24 -> V_190 ;
while ( ! F_52 ( & V_35 -> V_77 ) &&
V_35 -> V_76 < V_35 -> V_81 )
F_86 ( V_35 ) ;
F_60 ( V_35 -> V_15 ) ;
} else {
V_35 -> V_81 = 0 ;
}
F_82 ( & V_35 -> V_15 -> V_69 ) ;
}
static void F_253 ( struct V_22 * V_35 , struct V_23 * V_24 ,
struct V_14 * V_15 )
{
F_254 ( ( unsigned long ) V_35 & V_230 ) ;
memset ( V_35 , 0 , sizeof( * V_35 ) ) ;
V_35 -> V_15 = V_15 ;
V_35 -> V_24 = V_24 ;
V_35 -> V_82 = - 1 ;
V_35 -> V_70 = 1 ;
F_132 ( & V_35 -> V_77 ) ;
F_132 ( & V_35 -> V_225 ) ;
F_132 ( & V_35 -> V_142 ) ;
F_207 ( & V_35 -> V_72 , F_250 ) ;
}
static void F_255 ( struct V_22 * V_35 )
{
struct V_23 * V_24 = V_35 -> V_24 ;
F_22 ( & V_24 -> V_180 ) ;
if ( ! F_52 ( & V_35 -> V_225 ) )
return;
V_35 -> V_109 = V_24 -> V_109 ;
F_252 ( V_35 ) ;
F_256 ( & V_35 -> V_225 , & V_24 -> V_226 ) ;
}
static struct V_22 * F_257 ( struct V_23 * V_24 ,
const struct V_204 * V_126 )
{
struct V_14 * V_15 ;
struct V_22 * V_35 ;
F_22 ( & V_17 ) ;
V_15 = F_243 ( V_126 ) ;
if ( ! V_15 )
return NULL ;
V_35 = F_258 ( V_223 , V_20 , V_15 -> V_25 ) ;
if ( ! V_35 ) {
F_238 ( V_15 ) ;
return NULL ;
}
F_253 ( V_35 , V_24 , V_15 ) ;
return V_35 ;
}
static bool F_259 ( const struct V_204 * V_126 , int V_25 ,
int V_231 , T_6 * V_127 )
{
if ( ! V_220 || V_126 -> V_209 )
goto V_232;
F_260 ( V_127 , F_261 ( V_25 ) , V_126 -> V_127 ) ;
if ( V_231 >= 0 )
F_262 ( V_231 , V_127 ) ;
if ( F_106 ( V_127 ) )
goto V_232;
F_260 ( V_127 , V_126 -> V_127 , V_221 [ V_25 ] ) ;
return ! F_226 ( V_127 , V_126 -> V_127 ) ;
V_232:
F_218 ( V_127 , V_126 -> V_127 ) ;
return false ;
}
static struct V_22 * F_263 ( struct V_23 * V_24 ,
int V_25 ,
struct V_22 * V_35 )
{
struct V_22 * V_233 ;
F_22 ( & V_17 ) ;
F_22 ( & V_24 -> V_180 ) ;
F_255 ( V_35 ) ;
V_233 = F_264 ( V_24 -> V_28 [ V_25 ] ) ;
F_265 ( V_24 -> V_28 [ V_25 ] , V_35 ) ;
return V_233 ;
}
static void F_266 ( struct V_234 * V_235 )
{
if ( V_235 ) {
int V_25 ;
F_244 (node)
F_80 ( V_235 -> V_236 [ V_25 ] ) ;
F_80 ( V_235 -> V_27 ) ;
F_213 ( V_235 -> V_126 ) ;
F_146 ( V_235 ) ;
}
}
static struct V_234 *
F_267 ( struct V_23 * V_24 ,
const struct V_204 * V_126 )
{
struct V_234 * V_235 ;
struct V_204 * V_237 , * V_238 ;
int V_25 ;
F_22 ( & V_17 ) ;
V_235 = F_216 ( sizeof( * V_235 ) + V_239 * sizeof( V_235 -> V_236 [ 0 ] ) ,
V_20 ) ;
V_237 = F_215 ( V_20 ) ;
V_238 = F_215 ( V_20 ) ;
if ( ! V_235 || ! V_237 || ! V_238 )
goto V_240;
F_219 ( V_237 , V_126 ) ;
F_260 ( V_237 -> V_127 , V_237 -> V_127 , V_97 ) ;
if ( F_26 ( F_106 ( V_237 -> V_127 ) ) )
F_218 ( V_237 -> V_127 , V_97 ) ;
F_219 ( V_238 , V_237 ) ;
V_235 -> V_27 = F_257 ( V_24 , V_237 ) ;
if ( ! V_235 -> V_27 )
goto V_240;
F_244 (node) {
if ( F_259 ( V_237 , V_25 , - 1 , V_238 -> V_127 ) ) {
V_235 -> V_236 [ V_25 ] = F_257 ( V_24 , V_238 ) ;
if ( ! V_235 -> V_236 [ V_25 ] )
goto V_240;
} else {
V_235 -> V_27 -> V_70 ++ ;
V_235 -> V_236 [ V_25 ] = V_235 -> V_27 ;
}
}
F_219 ( V_237 , V_126 ) ;
F_260 ( V_237 -> V_127 , V_237 -> V_127 , V_206 ) ;
V_235 -> V_126 = V_237 ;
V_235 -> V_24 = V_24 ;
F_213 ( V_238 ) ;
return V_235 ;
V_240:
F_213 ( V_238 ) ;
F_213 ( V_237 ) ;
F_266 ( V_235 ) ;
return NULL ;
}
static void F_268 ( struct V_234 * V_235 )
{
int V_25 ;
F_134 ( & V_235 -> V_24 -> V_180 ) ;
F_219 ( V_235 -> V_24 -> V_218 , V_235 -> V_126 ) ;
F_244 (node)
V_235 -> V_236 [ V_25 ] = F_263 ( V_235 -> V_24 , V_25 ,
V_235 -> V_236 [ V_25 ] ) ;
F_255 ( V_235 -> V_27 ) ;
F_269 ( V_235 -> V_24 -> V_27 , V_235 -> V_27 ) ;
F_136 ( & V_235 -> V_24 -> V_180 ) ;
}
static void F_270 ( void )
{
F_205 () ;
F_134 ( & V_17 ) ;
}
static void F_271 ( void )
{
F_136 ( & V_17 ) ;
F_209 () ;
}
static int F_272 ( struct V_23 * V_24 ,
const struct V_204 * V_126 )
{
struct V_234 * V_235 ;
if ( F_10 ( ! ( V_24 -> V_34 & V_71 ) ) )
return - V_241 ;
if ( F_10 ( ( V_24 -> V_34 & V_242 ) && ! F_52 ( & V_24 -> V_226 ) ) )
return - V_241 ;
V_235 = F_267 ( V_24 , V_126 ) ;
if ( ! V_235 )
return - V_200 ;
F_268 ( V_235 ) ;
F_266 ( V_235 ) ;
return 0 ;
}
int F_273 ( struct V_23 * V_24 ,
const struct V_204 * V_126 )
{
int V_16 ;
F_270 () ;
V_16 = F_272 ( V_24 , V_126 ) ;
F_271 () ;
return V_16 ;
}
static void F_274 ( struct V_23 * V_24 , int V_57 ,
bool V_243 )
{
int V_25 = F_114 ( V_57 ) ;
int V_244 = V_243 ? - 1 : V_57 ;
struct V_22 * V_233 = NULL , * V_35 ;
struct V_204 * V_245 ;
T_6 * V_127 ;
F_22 ( & V_17 ) ;
if ( ! V_220 || ! ( V_24 -> V_34 & V_71 ) ||
V_24 -> V_218 -> V_209 )
return;
V_245 = V_246 ;
V_127 = V_245 -> V_127 ;
F_219 ( V_245 , V_24 -> V_218 ) ;
V_35 = F_24 ( V_24 , V_25 ) ;
if ( F_259 ( V_24 -> V_27 -> V_15 -> V_126 , V_25 , V_244 , V_127 ) ) {
if ( F_226 ( V_127 , V_35 -> V_15 -> V_126 -> V_127 ) )
return;
} else {
goto V_247;
}
V_35 = F_257 ( V_24 , V_245 ) ;
if ( ! V_35 ) {
F_105 ( L_12 ,
V_24 -> V_108 ) ;
goto V_247;
}
F_134 ( & V_24 -> V_180 ) ;
V_233 = F_263 ( V_24 , V_25 , V_35 ) ;
goto V_182;
V_247:
F_134 ( & V_24 -> V_180 ) ;
F_81 ( & V_24 -> V_27 -> V_15 -> V_69 ) ;
F_77 ( V_24 -> V_27 ) ;
F_82 ( & V_24 -> V_27 -> V_15 -> V_69 ) ;
V_233 = F_263 ( V_24 , V_25 , V_24 -> V_27 ) ;
V_182:
F_136 ( & V_24 -> V_180 ) ;
F_80 ( V_233 ) ;
}
static int F_275 ( struct V_23 * V_24 )
{
bool V_248 = V_24 -> V_34 & V_249 ;
int V_57 , V_16 ;
if ( ! ( V_24 -> V_34 & V_71 ) ) {
V_24 -> V_107 = F_204 ( struct V_22 ) ;
if ( ! V_24 -> V_107 )
return - V_200 ;
F_276 (cpu) {
struct V_22 * V_35 =
F_113 ( V_24 -> V_107 , V_57 ) ;
struct V_14 * V_250 =
F_277 ( V_251 , V_57 ) ;
F_253 ( V_35 , V_24 , & V_250 [ V_248 ] ) ;
F_134 ( & V_24 -> V_180 ) ;
F_255 ( V_35 ) ;
F_136 ( & V_24 -> V_180 ) ;
}
return 0 ;
} else if ( V_24 -> V_34 & V_242 ) {
V_16 = F_273 ( V_24 , V_252 [ V_248 ] ) ;
F_278 ( ! V_16 && ( V_24 -> V_226 . V_117 != & V_24 -> V_27 -> V_225 ||
V_24 -> V_226 . V_139 != & V_24 -> V_27 -> V_225 ) ,
L_13 , V_24 -> V_108 ) ;
return V_16 ;
} else {
return F_273 ( V_24 , V_253 [ V_248 ] ) ;
}
}
static int F_279 ( int V_81 , unsigned int V_34 ,
const char * V_108 )
{
int V_254 = V_34 & V_71 ? V_255 : V_256 ;
if ( V_81 < 1 || V_81 > V_254 )
F_105 ( L_14 ,
V_81 , V_108 , 1 , V_254 ) ;
return F_280 ( V_81 , 1 , V_254 ) ;
}
struct V_23 * F_281 ( const char * V_257 ,
unsigned int V_34 ,
int V_81 ,
struct V_258 * V_193 ,
const char * V_259 , ... )
{
T_7 V_260 = 0 ;
T_8 args ;
struct V_23 * V_24 ;
struct V_22 * V_35 ;
if ( ( V_34 & V_261 ) && V_262 )
V_34 |= V_71 ;
if ( V_34 & V_71 )
V_260 = V_239 * sizeof( V_24 -> V_28 [ 0 ] ) ;
V_24 = F_216 ( sizeof( * V_24 ) + V_260 , V_20 ) ;
if ( ! V_24 )
return NULL ;
if ( V_34 & V_71 ) {
V_24 -> V_218 = F_215 ( V_20 ) ;
if ( ! V_24 -> V_218 )
goto V_263;
}
va_start ( args , V_259 ) ;
vsnprintf ( V_24 -> V_108 , sizeof( V_24 -> V_108 ) , V_257 , args ) ;
va_end ( args ) ;
V_81 = V_81 ? : V_264 ;
V_81 = F_279 ( V_81 , V_34 , V_24 -> V_108 ) ;
V_24 -> V_34 = V_34 ;
V_24 -> V_190 = V_81 ;
F_232 ( & V_24 -> V_180 ) ;
F_174 ( & V_24 -> V_83 , 0 ) ;
F_132 ( & V_24 -> V_226 ) ;
F_132 ( & V_24 -> V_183 ) ;
F_132 ( & V_24 -> V_181 ) ;
F_132 ( & V_24 -> V_143 ) ;
F_282 ( & V_24 -> V_179 , V_259 , V_193 , 0 ) ;
F_132 ( & V_24 -> V_177 ) ;
if ( F_275 ( V_24 ) < 0 )
goto V_263;
if ( V_34 & V_163 ) {
struct V_52 * V_141 ;
V_141 = F_130 ( V_26 ) ;
if ( ! V_141 )
goto V_265;
V_141 -> V_154 = V_24 ;
V_141 -> V_55 = F_283 ( F_162 , V_141 , L_15 ,
V_24 -> V_108 ) ;
if ( F_142 ( V_141 -> V_55 ) ) {
F_146 ( V_141 ) ;
goto V_265;
}
V_24 -> V_141 = V_141 ;
F_144 ( V_141 -> V_55 , V_206 ) ;
F_62 ( V_141 -> V_55 ) ;
}
if ( ( V_24 -> V_34 & V_266 ) && F_284 ( V_24 ) )
goto V_265;
F_134 ( & V_17 ) ;
F_134 ( & V_24 -> V_180 ) ;
F_175 (pwq, wq)
F_252 ( V_35 ) ;
F_136 ( & V_24 -> V_180 ) ;
F_285 ( & V_24 -> V_177 , & V_267 ) ;
F_136 ( & V_17 ) ;
return V_24 ;
V_263:
F_213 ( V_24 -> V_218 ) ;
F_146 ( V_24 ) ;
return NULL ;
V_265:
F_286 ( V_24 ) ;
return NULL ;
}
void F_286 ( struct V_23 * V_24 )
{
struct V_22 * V_35 ;
int V_25 ;
F_183 ( V_24 ) ;
F_134 ( & V_24 -> V_180 ) ;
F_175 (pwq, wq) {
int V_268 ;
for ( V_268 = 0 ; V_268 < V_32 ; V_268 ++ ) {
if ( F_10 ( V_35 -> V_80 [ V_268 ] ) ) {
F_136 ( & V_24 -> V_180 ) ;
return;
}
}
if ( F_10 ( ( V_35 != V_24 -> V_27 ) && ( V_35 -> V_70 > 1 ) ) ||
F_10 ( V_35 -> V_76 ) ||
F_10 ( ! F_52 ( & V_35 -> V_77 ) ) ) {
F_136 ( & V_24 -> V_180 ) ;
return;
}
}
F_136 ( & V_24 -> V_180 ) ;
F_134 ( & V_17 ) ;
F_251 ( & V_24 -> V_177 ) ;
F_136 ( & V_17 ) ;
F_287 ( V_24 ) ;
if ( V_24 -> V_141 )
F_288 ( V_24 -> V_141 -> V_55 ) ;
if ( ! ( V_24 -> V_34 & V_71 ) ) {
F_242 ( & V_24 -> V_217 , F_235 ) ;
} else {
F_244 (node) {
V_35 = F_264 ( V_24 -> V_28 [ V_25 ] ) ;
F_289 ( V_24 -> V_28 [ V_25 ] , NULL ) ;
F_80 ( V_35 ) ;
}
V_35 = V_24 -> V_27 ;
V_24 -> V_27 = NULL ;
F_80 ( V_35 ) ;
}
}
void F_290 ( struct V_23 * V_24 , int V_81 )
{
struct V_22 * V_35 ;
if ( F_10 ( V_24 -> V_34 & V_242 ) )
return;
V_81 = F_279 ( V_81 , V_24 -> V_34 , V_24 -> V_108 ) ;
F_134 ( & V_24 -> V_180 ) ;
V_24 -> V_190 = V_81 ;
F_175 (pwq, wq)
F_252 ( V_35 ) ;
F_136 ( & V_24 -> V_180 ) ;
}
bool F_291 ( void )
{
struct V_52 * V_52 = F_102 () ;
return V_52 && V_52 -> V_154 ;
}
bool F_292 ( int V_57 , struct V_23 * V_24 )
{
struct V_22 * V_35 ;
bool V_16 ;
F_293 () ;
if ( V_57 == V_106 )
V_57 = F_294 () ;
if ( ! ( V_24 -> V_34 & V_71 ) )
V_35 = F_113 ( V_24 -> V_107 , V_57 ) ;
else
V_35 = F_24 ( V_24 , F_114 ( V_57 ) ) ;
V_16 = ! F_52 ( & V_35 -> V_77 ) ;
F_295 () ;
return V_16 ;
}
unsigned int F_296 ( struct V_2 * V_6 )
{
struct V_14 * V_15 ;
unsigned long V_34 ;
unsigned int V_16 = 0 ;
if ( F_32 ( V_6 ) )
V_16 |= V_269 ;
F_90 ( V_34 ) ;
V_15 = F_43 ( V_6 ) ;
if ( V_15 ) {
F_94 ( & V_15 -> V_69 ) ;
if ( F_72 ( V_15 , V_6 ) )
V_16 |= V_270 ;
F_96 ( & V_15 -> V_69 ) ;
}
F_97 ( V_34 ) ;
return V_16 ;
}
void F_297 ( const char * V_257 , ... )
{
struct V_52 * V_52 = F_102 () ;
T_8 args ;
if ( V_52 ) {
va_start ( args , V_257 ) ;
vsnprintf ( V_52 -> V_271 , sizeof( V_52 -> V_271 ) , V_257 , args ) ;
va_end ( args ) ;
V_52 -> V_272 = true ;
}
}
void F_298 ( const char * V_273 , struct V_56 * V_55 )
{
T_1 * V_201 = NULL ;
char V_108 [ V_274 ] = { } ;
char V_271 [ V_275 ] = { } ;
struct V_22 * V_35 = NULL ;
struct V_23 * V_24 = NULL ;
bool V_272 = false ;
struct V_52 * V_52 ;
if ( ! ( V_55 -> V_34 & V_148 ) )
return;
V_52 = F_299 ( V_55 ) ;
F_300 ( & V_201 , & V_52 -> V_63 , sizeof( V_201 ) ) ;
F_300 ( & V_35 , & V_52 -> V_93 , sizeof( V_35 ) ) ;
F_300 ( & V_24 , & V_35 -> V_24 , sizeof( V_24 ) ) ;
F_300 ( V_108 , V_24 -> V_108 , sizeof( V_108 ) - 1 ) ;
F_300 ( & V_272 , & V_52 -> V_272 , sizeof( V_272 ) ) ;
if ( V_272 )
F_300 ( V_271 , V_52 -> V_271 , sizeof( V_271 ) - 1 ) ;
if ( V_201 || V_108 [ 0 ] || V_271 [ 0 ] ) {
F_301 ( L_16 , V_273 , V_108 , V_201 ) ;
if ( V_271 [ 0 ] )
F_302 ( L_17 , V_271 ) ;
F_302 ( L_18 ) ;
}
}
static void F_303 ( struct V_14 * V_15 )
{
F_302 ( L_19 , V_211 , V_15 -> V_126 -> V_127 ) ;
if ( V_15 -> V_25 != V_26 )
F_302 ( L_20 , V_15 -> V_25 ) ;
F_302 ( L_21 , V_15 -> V_34 , V_15 -> V_126 -> V_135 ) ;
}
static void F_304 ( bool V_276 , struct V_2 * V_6 )
{
if ( V_6 -> V_3 == F_167 ) {
struct V_168 * V_169 ;
V_169 = F_168 ( V_6 , struct V_168 , V_6 ) ;
F_302 ( L_22 , V_276 ? L_23 : L_5 ,
F_305 ( V_169 -> V_55 ) ) ;
} else {
F_302 ( L_24 , V_276 ? L_23 : L_5 , V_6 -> V_3 ) ;
}
}
static void F_306 ( struct V_22 * V_35 )
{
struct V_14 * V_15 = V_35 -> V_15 ;
struct V_2 * V_6 ;
struct V_52 * V_52 ;
bool V_277 = false , V_278 = false ;
int V_279 ;
F_307 ( L_25 , V_15 -> V_21 ) ;
F_303 ( V_15 ) ;
F_302 ( L_26 , V_35 -> V_76 , V_35 -> V_81 ,
! F_52 ( & V_35 -> V_142 ) ? L_27 : L_5 ) ;
F_308 (pool->busy_hash, bkt, worker, hentry) {
if ( V_52 -> V_93 == V_35 ) {
V_277 = true ;
break;
}
}
if ( V_277 ) {
bool V_276 = false ;
F_307 ( L_28 ) ;
F_308 (pool->busy_hash, bkt, worker, hentry) {
if ( V_52 -> V_93 != V_35 )
continue;
F_302 ( L_29 , V_276 ? L_23 : L_5 ,
F_305 ( V_52 -> V_55 ) ,
V_52 == V_35 -> V_24 -> V_141 ? L_30 : L_5 ,
V_52 -> V_63 ) ;
F_153 (work, &worker->scheduled, entry)
F_304 ( false , V_6 ) ;
V_276 = true ;
}
F_302 ( L_18 ) ;
}
F_153 (work, &pool->worklist, entry) {
if ( F_41 ( V_6 ) == V_35 ) {
V_278 = true ;
break;
}
}
if ( V_278 ) {
bool V_276 = false ;
F_307 ( L_31 ) ;
F_153 (work, &pool->worklist, entry) {
if ( F_41 ( V_6 ) != V_35 )
continue;
F_304 ( V_276 , V_6 ) ;
V_276 = ! ( * F_7 ( V_6 ) & V_68 ) ;
}
F_302 ( L_18 ) ;
}
if ( ! F_52 ( & V_35 -> V_77 ) ) {
bool V_276 = false ;
F_307 ( L_32 ) ;
F_153 (work, &pwq->delayed_works, entry) {
F_304 ( V_276 , V_6 ) ;
V_276 = ! ( * F_7 ( V_6 ) & V_68 ) ;
}
F_302 ( L_18 ) ;
}
}
void F_309 ( void )
{
struct V_23 * V_24 ;
struct V_14 * V_15 ;
unsigned long V_34 ;
int V_280 ;
F_293 () ;
F_307 ( L_33 ) ;
F_310 (wq, &workqueues, list) {
struct V_22 * V_35 ;
bool V_281 = true ;
F_175 (pwq, wq) {
if ( V_35 -> V_76 || ! F_52 ( & V_35 -> V_77 ) ) {
V_281 = false ;
break;
}
}
if ( V_281 )
continue;
F_307 ( L_34 , V_24 -> V_108 , V_24 -> V_34 ) ;
F_175 (pwq, wq) {
F_311 ( & V_35 -> V_15 -> V_69 , V_34 ) ;
if ( V_35 -> V_76 || ! F_52 ( & V_35 -> V_77 ) )
F_306 ( V_35 ) ;
F_312 ( & V_35 -> V_15 -> V_69 , V_34 ) ;
}
}
F_313 (pool, pi) {
struct V_52 * V_52 ;
bool V_158 = true ;
F_311 ( & V_15 -> V_69 , V_34 ) ;
if ( V_15 -> V_50 == V_15 -> V_46 )
goto V_282;
F_307 ( L_35 , V_15 -> V_21 ) ;
F_303 ( V_15 ) ;
F_302 ( L_36 ,
F_314 ( V_74 - V_15 -> V_73 ) / 1000 ,
V_15 -> V_50 ) ;
if ( V_15 -> V_146 )
F_302 ( L_37 ,
F_305 ( V_15 -> V_146 -> V_55 ) ) ;
F_153 (worker, &pool->idle_list, entry) {
F_302 ( L_38 , V_158 ? L_39 : L_5 ,
F_305 ( V_52 -> V_55 ) ) ;
V_158 = false ;
}
F_302 ( L_18 ) ;
V_282:
F_312 ( & V_15 -> V_69 , V_34 ) ;
}
F_295 () ;
}
static void F_315 ( struct V_2 * V_6 )
{
int V_57 = F_294 () ;
struct V_14 * V_15 ;
struct V_52 * V_52 ;
F_316 (pool, cpu) {
F_134 ( & V_15 -> V_125 ) ;
F_81 ( & V_15 -> V_69 ) ;
F_317 (worker, pool)
V_52 -> V_34 |= V_128 ;
V_15 -> V_34 |= V_122 ;
F_82 ( & V_15 -> V_69 ) ;
F_136 ( & V_15 -> V_125 ) ;
F_161 () ;
F_174 ( & V_15 -> V_44 , 0 ) ;
F_81 ( & V_15 -> V_69 ) ;
F_60 ( V_15 ) ;
F_82 ( & V_15 -> V_69 ) ;
}
}
static void F_318 ( struct V_14 * V_15 )
{
struct V_52 * V_52 ;
F_22 ( & V_15 -> V_125 ) ;
F_317 (worker, pool)
F_9 ( F_135 ( V_52 -> V_55 ,
V_15 -> V_126 -> V_127 ) < 0 ) ;
F_81 ( & V_15 -> V_69 ) ;
if ( ! ( V_15 -> V_34 & V_122 ) ) {
F_82 ( & V_15 -> V_69 ) ;
return;
}
V_15 -> V_34 &= ~ V_122 ;
F_317 (worker, pool) {
unsigned int V_283 = V_52 -> V_34 ;
if ( V_283 & V_115 )
F_62 ( V_52 -> V_55 ) ;
F_9 ( ! ( V_283 & V_128 ) ) ;
V_283 |= V_132 ;
V_283 &= ~ V_128 ;
F_319 ( V_52 -> V_34 ) = V_283 ;
}
F_82 ( & V_15 -> V_69 ) ;
}
static void F_320 ( struct V_14 * V_15 , int V_57 )
{
static T_6 V_127 ;
struct V_52 * V_52 ;
F_22 ( & V_15 -> V_125 ) ;
if ( ! F_104 ( V_57 , V_15 -> V_126 -> V_127 ) )
return;
F_260 ( & V_127 , V_15 -> V_126 -> V_127 , V_99 ) ;
if ( F_321 ( & V_127 ) != 1 )
return;
F_317 (worker, pool)
F_9 ( F_135 ( V_52 -> V_55 ,
V_15 -> V_126 -> V_127 ) < 0 ) ;
}
static int F_322 ( struct V_284 * V_285 ,
unsigned long V_286 ,
void * V_287 )
{
int V_57 = ( unsigned long ) V_287 ;
struct V_14 * V_15 ;
struct V_23 * V_24 ;
int V_280 ;
switch ( V_286 & ~ V_288 ) {
case V_289 :
F_316 (pool, cpu) {
if ( V_15 -> V_50 )
continue;
if ( ! F_139 ( V_15 ) )
return V_290 ;
}
break;
case V_291 :
case V_292 :
F_134 ( & V_17 ) ;
F_313 (pool, pi) {
F_134 ( & V_15 -> V_125 ) ;
if ( V_15 -> V_57 == V_57 )
F_318 ( V_15 ) ;
else if ( V_15 -> V_57 < 0 )
F_320 ( V_15 , V_57 ) ;
F_136 ( & V_15 -> V_125 ) ;
}
F_153 (wq, &workqueues, list)
F_274 ( V_24 , V_57 , true ) ;
F_136 ( & V_17 ) ;
break;
}
return V_293 ;
}
static int F_323 ( struct V_284 * V_285 ,
unsigned long V_286 ,
void * V_287 )
{
int V_57 = ( unsigned long ) V_287 ;
struct V_2 V_294 ;
struct V_23 * V_24 ;
switch ( V_286 & ~ V_288 ) {
case V_295 :
F_170 ( & V_294 , F_315 ) ;
F_117 ( V_57 , V_296 , & V_294 ) ;
F_134 ( & V_17 ) ;
F_153 (wq, &workqueues, list)
F_274 ( V_24 , V_57 , false ) ;
F_136 ( & V_17 ) ;
F_189 ( & V_294 ) ;
F_18 ( & V_294 ) ;
break;
}
return V_293 ;
}
static void F_324 ( struct V_2 * V_6 )
{
struct V_297 * V_298 = F_168 ( V_6 , struct V_297 , V_6 ) ;
V_298 -> V_16 = V_298 -> V_201 ( V_298 -> V_299 ) ;
}
long F_325 ( int V_57 , long (* V_201)( void * ) , void * V_299 )
{
struct V_297 V_298 = { . V_201 = V_201 , . V_299 = V_299 } ;
F_170 ( & V_298 . V_6 , F_324 ) ;
F_208 ( V_57 , & V_298 . V_6 ) ;
F_189 ( & V_298 . V_6 ) ;
F_18 ( & V_298 . V_6 ) ;
return V_298 . V_16 ;
}
void F_326 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_35 ;
F_134 ( & V_17 ) ;
F_9 ( V_229 ) ;
V_229 = true ;
F_153 (wq, &workqueues, list) {
F_134 ( & V_24 -> V_180 ) ;
F_175 (pwq, wq)
F_252 ( V_35 ) ;
F_136 ( & V_24 -> V_180 ) ;
}
F_136 ( & V_17 ) ;
}
bool F_327 ( void )
{
bool V_300 = false ;
struct V_23 * V_24 ;
struct V_22 * V_35 ;
F_134 ( & V_17 ) ;
F_9 ( ! V_229 ) ;
F_153 (wq, &workqueues, list) {
if ( ! ( V_24 -> V_34 & V_228 ) )
continue;
F_293 () ;
F_175 (pwq, wq) {
F_9 ( V_35 -> V_76 < 0 ) ;
if ( V_35 -> V_76 ) {
V_300 = true ;
F_295 () ;
goto V_182;
}
}
F_295 () ;
}
V_182:
F_136 ( & V_17 ) ;
return V_300 ;
}
void F_328 ( void )
{
struct V_23 * V_24 ;
struct V_22 * V_35 ;
F_134 ( & V_17 ) ;
if ( ! V_229 )
goto V_182;
V_229 = false ;
F_153 (wq, &workqueues, list) {
F_134 ( & V_24 -> V_180 ) ;
F_175 (pwq, wq)
F_252 ( V_35 ) ;
F_136 ( & V_24 -> V_180 ) ;
}
V_182:
F_136 ( & V_17 ) ;
}
static int F_329 ( void )
{
F_330 ( V_301 ) ;
int V_16 = 0 ;
struct V_23 * V_24 ;
struct V_234 * V_235 , * V_67 ;
F_22 ( & V_17 ) ;
F_153 (wq, &workqueues, list) {
if ( ! ( V_24 -> V_34 & V_71 ) )
continue;
if ( V_24 -> V_34 & V_242 )
continue;
V_235 = F_267 ( V_24 , V_24 -> V_218 ) ;
if ( ! V_235 ) {
V_16 = - V_200 ;
break;
}
F_100 ( & V_235 -> V_177 , & V_301 ) ;
}
F_165 (ctx, n, &ctxs, list) {
if ( ! V_16 )
F_268 ( V_235 ) ;
F_266 ( V_235 ) ;
}
return V_16 ;
}
int F_331 ( T_9 V_127 )
{
int V_16 = - V_241 ;
T_9 V_302 ;
if ( ! F_332 ( & V_302 , V_20 ) )
return - V_200 ;
F_260 ( V_127 , V_127 , V_206 ) ;
if ( ! F_106 ( V_127 ) ) {
F_270 () ;
F_218 ( V_302 , V_97 ) ;
F_218 ( V_97 , V_127 ) ;
V_16 = F_329 () ;
if ( V_16 < 0 )
F_218 ( V_97 , V_302 ) ;
F_271 () ;
}
F_214 ( V_302 ) ;
return V_16 ;
}
static struct V_23 * F_333 ( struct V_303 * V_304 )
{
struct V_305 * V_306 = F_168 ( V_304 , struct V_305 , V_304 ) ;
return V_306 -> V_24 ;
}
static T_10 F_334 ( struct V_303 * V_304 , struct V_307 * V_308 ,
char * V_309 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
return F_335 ( V_309 , V_310 , L_40 , ( bool ) ! ( V_24 -> V_34 & V_71 ) ) ;
}
static T_10 F_336 ( struct V_303 * V_304 ,
struct V_307 * V_308 , char * V_309 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
return F_335 ( V_309 , V_310 , L_40 , V_24 -> V_190 ) ;
}
static T_10 F_337 ( struct V_303 * V_304 ,
struct V_307 * V_308 , const char * V_309 ,
T_7 V_311 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
int V_312 ;
if ( sscanf ( V_309 , L_41 , & V_312 ) != 1 || V_312 <= 0 )
return - V_241 ;
F_290 ( V_24 , V_312 ) ;
return V_311 ;
}
static T_10 F_338 ( struct V_303 * V_304 ,
struct V_307 * V_308 , char * V_309 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
const char * V_313 = L_5 ;
int V_25 , V_314 = 0 ;
F_293 () ;
F_244 (node) {
V_314 += F_335 ( V_309 + V_314 , V_310 - V_314 ,
L_42 , V_313 , V_25 ,
F_24 ( V_24 , V_25 ) -> V_15 -> V_21 ) ;
V_313 = L_43 ;
}
V_314 += F_335 ( V_309 + V_314 , V_310 - V_314 , L_18 ) ;
F_295 () ;
return V_314 ;
}
static T_10 F_339 ( struct V_303 * V_304 , struct V_307 * V_308 ,
char * V_309 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
int V_314 ;
F_134 ( & V_24 -> V_180 ) ;
V_314 = F_335 ( V_309 , V_310 , L_40 , V_24 -> V_218 -> V_135 ) ;
F_136 ( & V_24 -> V_180 ) ;
return V_314 ;
}
static struct V_204 * F_340 ( struct V_23 * V_24 )
{
struct V_204 * V_126 ;
F_22 ( & V_17 ) ;
V_126 = F_215 ( V_20 ) ;
if ( ! V_126 )
return NULL ;
F_219 ( V_126 , V_24 -> V_218 ) ;
return V_126 ;
}
static T_10 F_341 ( struct V_303 * V_304 , struct V_307 * V_308 ,
const char * V_309 , T_7 V_311 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
struct V_204 * V_126 ;
int V_16 = - V_200 ;
F_270 () ;
V_126 = F_340 ( V_24 ) ;
if ( ! V_126 )
goto V_182;
if ( sscanf ( V_309 , L_41 , & V_126 -> V_135 ) == 1 &&
V_126 -> V_135 >= V_315 && V_126 -> V_135 <= V_316 )
V_16 = F_272 ( V_24 , V_126 ) ;
else
V_16 = - V_241 ;
V_182:
F_271 () ;
F_213 ( V_126 ) ;
return V_16 ? : V_311 ;
}
static T_10 F_342 ( struct V_303 * V_304 ,
struct V_307 * V_308 , char * V_309 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
int V_314 ;
F_134 ( & V_24 -> V_180 ) ;
V_314 = F_335 ( V_309 , V_310 , L_44 ,
F_343 ( V_24 -> V_218 -> V_127 ) ) ;
F_136 ( & V_24 -> V_180 ) ;
return V_314 ;
}
static T_10 F_344 ( struct V_303 * V_304 ,
struct V_307 * V_308 ,
const char * V_309 , T_7 V_311 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
struct V_204 * V_126 ;
int V_16 = - V_200 ;
F_270 () ;
V_126 = F_340 ( V_24 ) ;
if ( ! V_126 )
goto V_182;
V_16 = F_345 ( V_309 , V_126 -> V_127 ) ;
if ( ! V_16 )
V_16 = F_272 ( V_24 , V_126 ) ;
V_182:
F_271 () ;
F_213 ( V_126 ) ;
return V_16 ? : V_311 ;
}
static T_10 F_346 ( struct V_303 * V_304 , struct V_307 * V_308 ,
char * V_309 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
int V_314 ;
F_134 ( & V_24 -> V_180 ) ;
V_314 = F_335 ( V_309 , V_310 , L_40 ,
! V_24 -> V_218 -> V_209 ) ;
F_136 ( & V_24 -> V_180 ) ;
return V_314 ;
}
static T_10 F_347 ( struct V_303 * V_304 , struct V_307 * V_308 ,
const char * V_309 , T_7 V_311 )
{
struct V_23 * V_24 = F_333 ( V_304 ) ;
struct V_204 * V_126 ;
int V_317 , V_16 = - V_200 ;
F_270 () ;
V_126 = F_340 ( V_24 ) ;
if ( ! V_126 )
goto V_182;
V_16 = - V_241 ;
if ( sscanf ( V_309 , L_41 , & V_317 ) == 1 ) {
V_126 -> V_209 = ! V_317 ;
V_16 = F_272 ( V_24 , V_126 ) ;
}
V_182:
F_271 () ;
F_213 ( V_126 ) ;
return V_16 ? : V_311 ;
}
static T_10 F_348 ( struct V_303 * V_304 ,
struct V_307 * V_308 , char * V_309 )
{
int V_314 ;
F_134 ( & V_17 ) ;
V_314 = F_335 ( V_309 , V_310 , L_44 ,
F_343 ( V_97 ) ) ;
F_136 ( & V_17 ) ;
return V_314 ;
}
static T_10 F_349 ( struct V_303 * V_304 ,
struct V_307 * V_308 , const char * V_309 , T_7 V_311 )
{
T_9 V_127 ;
int V_16 ;
if ( ! F_332 ( & V_127 , V_20 ) )
return - V_200 ;
V_16 = F_345 ( V_309 , V_127 ) ;
if ( ! V_16 )
V_16 = F_331 ( V_127 ) ;
F_214 ( V_127 ) ;
return V_16 ? V_16 : V_311 ;
}
static int T_11 F_350 ( void )
{
int V_318 ;
V_318 = F_351 ( & V_319 , NULL ) ;
if ( V_318 )
return V_318 ;
return F_352 ( V_319 . V_320 , & V_321 ) ;
}
static void F_353 ( struct V_303 * V_304 )
{
struct V_305 * V_306 = F_168 ( V_304 , struct V_305 , V_304 ) ;
F_146 ( V_306 ) ;
}
int F_284 ( struct V_23 * V_24 )
{
struct V_305 * V_306 ;
int V_16 ;
if ( F_10 ( V_24 -> V_34 & V_242 ) )
return - V_241 ;
V_24 -> V_306 = V_306 = F_216 ( sizeof( * V_306 ) , V_20 ) ;
if ( ! V_306 )
return - V_200 ;
V_306 -> V_24 = V_24 ;
V_306 -> V_304 . V_322 = & V_319 ;
V_306 -> V_304 . V_323 = F_353 ;
F_354 ( & V_306 -> V_304 , L_15 , V_24 -> V_108 ) ;
F_355 ( & V_306 -> V_304 , true ) ;
V_16 = F_356 ( & V_306 -> V_304 ) ;
if ( V_16 ) {
F_146 ( V_306 ) ;
V_24 -> V_306 = NULL ;
return V_16 ;
}
if ( V_24 -> V_34 & V_71 ) {
struct V_307 * V_308 ;
for ( V_308 = V_324 ; V_308 -> V_308 . V_108 ; V_308 ++ ) {
V_16 = F_352 ( & V_306 -> V_304 , V_308 ) ;
if ( V_16 ) {
F_357 ( & V_306 -> V_304 ) ;
V_24 -> V_306 = NULL ;
return V_16 ;
}
}
}
F_355 ( & V_306 -> V_304 , false ) ;
F_358 ( & V_306 -> V_304 . V_325 , V_326 ) ;
return 0 ;
}
static void F_287 ( struct V_23 * V_24 )
{
struct V_305 * V_306 = V_24 -> V_306 ;
if ( ! V_24 -> V_306 )
return;
V_24 -> V_306 = NULL ;
F_357 ( & V_306 -> V_304 ) ;
}
static void F_287 ( struct V_23 * V_24 ) { }
static void F_359 ( void )
{
int V_57 ;
V_327 = V_74 ;
F_276 (cpu)
F_277 ( V_328 , V_57 ) = V_74 ;
}
static void F_360 ( unsigned long V_33 )
{
unsigned long V_329 = F_361 ( V_330 ) * V_331 ;
bool V_332 = false ;
struct V_14 * V_15 ;
int V_280 ;
if ( ! V_329 )
return;
F_362 () ;
F_313 (pool, pi) {
unsigned long V_333 , V_334 , V_335 ;
if ( F_52 ( & V_15 -> V_45 ) )
continue;
V_333 = F_361 ( V_15 -> V_73 ) ;
V_334 = F_361 ( V_327 ) ;
if ( F_363 ( V_333 , V_334 ) )
V_335 = V_333 ;
else
V_335 = V_334 ;
if ( V_15 -> V_57 >= 0 ) {
unsigned long V_336 =
F_361 ( F_277 ( V_328 ,
V_15 -> V_57 ) ) ;
if ( F_363 ( V_336 , V_335 ) )
V_335 = V_336 ;
}
if ( F_363 ( V_74 , V_335 + V_329 ) ) {
V_332 = true ;
F_364 ( L_45 ) ;
F_303 ( V_15 ) ;
F_302 ( L_46 ,
F_314 ( V_74 - V_333 ) / 1000 ) ;
}
}
F_365 () ;
if ( V_332 )
F_309 () ;
F_359 () ;
F_128 ( & V_337 , V_74 + V_329 ) ;
}
void F_366 ( int V_57 )
{
if ( V_57 >= 0 )
F_277 ( V_328 , V_57 ) = V_74 ;
else
V_327 = V_74 ;
}
static void F_367 ( unsigned long V_329 )
{
V_330 = 0 ;
F_200 ( & V_337 ) ;
if ( V_329 ) {
V_330 = V_329 ;
F_359 () ;
F_128 ( & V_337 , V_74 + V_329 * V_331 ) ;
}
}
static int F_368 ( const char * V_312 ,
const struct V_338 * V_339 )
{
unsigned long V_329 ;
int V_16 ;
V_16 = F_369 ( V_312 , 0 , & V_329 ) ;
if ( V_16 )
return V_16 ;
if ( V_340 )
F_367 ( V_329 ) ;
else
V_330 = V_329 ;
return 0 ;
}
static void F_370 ( void )
{
F_367 ( V_330 ) ;
}
static inline void F_370 ( void ) { }
static void T_11 F_371 ( void )
{
T_9 * V_341 ;
int V_25 , V_57 ;
if ( F_372 () <= 1 )
return;
if ( V_342 ) {
F_307 ( L_47 ) ;
return;
}
V_246 = F_215 ( V_20 ) ;
F_254 ( ! V_246 ) ;
V_341 = F_216 ( V_239 * sizeof( V_341 [ 0 ] ) , V_20 ) ;
F_254 ( ! V_341 ) ;
F_244 (node)
F_254 ( ! F_373 ( & V_341 [ V_25 ] , V_20 ,
F_374 ( V_25 ) ? V_25 : V_26 ) ) ;
F_276 (cpu) {
V_25 = F_114 ( V_57 ) ;
if ( F_10 ( V_25 == V_26 ) ) {
F_105 ( L_48 , V_57 ) ;
return;
}
F_375 ( V_57 , V_341 [ V_25 ] ) ;
}
V_221 = V_341 ;
V_220 = true ;
}
static int T_11 F_376 ( void )
{
int V_343 [ V_344 ] = { 0 , V_345 } ;
int V_268 , V_57 ;
F_10 ( F_377 ( struct V_22 ) < F_377 (long long) ) ;
F_254 ( ! F_217 ( & V_97 , V_20 ) ) ;
F_218 ( V_97 , V_206 ) ;
V_223 = F_378 ( V_22 , V_346 ) ;
F_379 ( F_322 , V_347 ) ;
F_380 ( F_323 , V_348 ) ;
F_371 () ;
F_276 (cpu) {
struct V_14 * V_15 ;
V_268 = 0 ;
F_316 (pool, cpu) {
F_254 ( F_227 ( V_15 ) ) ;
V_15 -> V_57 = V_57 ;
F_218 ( V_15 -> V_126 -> V_127 , F_381 ( V_57 ) ) ;
V_15 -> V_126 -> V_135 = V_343 [ V_268 ++ ] ;
V_15 -> V_25 = F_114 ( V_57 ) ;
F_134 ( & V_17 ) ;
F_254 ( F_21 ( V_15 ) ) ;
F_136 ( & V_17 ) ;
}
}
F_206 (cpu) {
struct V_14 * V_15 ;
F_316 (pool, cpu) {
V_15 -> V_34 &= ~ V_122 ;
F_254 ( ! F_139 ( V_15 ) ) ;
}
}
for ( V_268 = 0 ; V_268 < V_344 ; V_268 ++ ) {
struct V_204 * V_126 ;
F_254 ( ! ( V_126 = F_215 ( V_20 ) ) ) ;
V_126 -> V_135 = V_343 [ V_268 ] ;
V_253 [ V_268 ] = V_126 ;
F_254 ( ! ( V_126 = F_215 ( V_20 ) ) ) ;
V_126 -> V_135 = V_343 [ V_268 ] ;
V_126 -> V_209 = true ;
V_252 [ V_268 ] = V_126 ;
}
V_340 = F_382 ( L_49 , 0 , 0 ) ;
V_296 = F_382 ( L_50 , V_249 , 0 ) ;
V_349 = F_382 ( L_51 , 0 , 0 ) ;
V_350 = F_382 ( L_52 , V_71 ,
V_255 ) ;
V_351 = F_382 ( L_53 ,
V_228 , 0 ) ;
V_352 = F_382 ( L_54 ,
V_261 , 0 ) ;
V_353 = F_382 ( L_55 ,
V_228 | V_261 ,
0 ) ;
F_254 ( ! V_340 || ! V_296 || ! V_349 ||
! V_350 || ! V_351 ||
! V_352 ||
! V_353 ) ;
F_370 () ;
return 0 ;
}
