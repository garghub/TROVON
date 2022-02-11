static bool F_1 ( void )
{
return F_2 ( V_1 ,
& V_2 . V_3 -> V_4 ) ;
}
static bool F_3 ( void )
{
return F_2 ( V_5 ,
& V_2 . V_3 -> V_4 ) ;
}
static struct V_6 *
F_4 ( struct V_7 * V_8 , int V_9 , int V_10 )
{
return & V_8 -> V_11 . V_12 [ V_9 ] -> V_13 [ V_10 ] ;
}
struct V_14 * F_5 ( struct V_7 * V_8 )
{
return & V_8 -> V_15 ;
}
static struct V_6 *
F_6 ( struct V_7 * V_8 , struct V_16 * V_16 )
{
int V_9 = F_7 ( V_16 ) ;
int V_10 = F_8 ( V_16 ) ;
return F_4 ( V_8 , V_9 , V_10 ) ;
}
static struct V_17 *
F_9 ( int V_9 , int V_10 )
{
return & V_18 . V_19 [ V_9 ] -> V_20 [ V_10 ] ;
}
static struct V_17 *
F_10 ( struct V_16 * V_16 )
{
int V_9 = F_7 ( V_16 ) ;
int V_10 = F_8 ( V_16 ) ;
return & V_18 . V_19 [ V_9 ] -> V_20 [ V_10 ] ;
}
static void
F_11 ( struct V_7 * V_8 ,
struct V_6 * V_21 ,
struct V_17 * V_22 ,
unsigned long long V_23 )
{
struct V_24 * * V_25 = & V_22 -> V_26 . V_24 ;
struct V_24 * V_27 = NULL ;
struct V_6 * V_28 ;
if ( V_21 -> V_29 )
return;
V_21 -> V_30 = V_23 ;
if ( ! V_21 -> V_30 )
return;
while ( * V_25 ) {
V_27 = * V_25 ;
V_28 = F_12 ( V_27 , struct V_6 ,
V_31 ) ;
if ( V_21 -> V_30 < V_28 -> V_30 )
V_25 = & ( * V_25 ) -> V_32 ;
else if ( V_21 -> V_30 >= V_28 -> V_30 )
V_25 = & ( * V_25 ) -> V_33 ;
}
F_13 ( & V_21 -> V_31 , V_27 , V_25 ) ;
F_14 ( & V_21 -> V_31 , & V_22 -> V_26 ) ;
V_21 -> V_29 = true ;
}
static void
F_15 ( struct V_7 * V_8 ,
struct V_6 * V_21 ,
struct V_17 * V_22 )
{
if ( ! V_21 -> V_29 )
return;
F_16 ( & V_21 -> V_31 , & V_22 -> V_26 ) ;
V_21 -> V_29 = false ;
}
static void
F_17 ( struct V_7 * V_8 ,
struct V_6 * V_21 ,
struct V_17 * V_22 )
{
F_18 ( & V_22 -> V_34 ) ;
F_15 ( V_8 , V_21 , V_22 ) ;
F_19 ( & V_22 -> V_34 ) ;
}
static void F_20 ( struct V_7 * V_8 , struct V_16 * V_16 )
{
unsigned long long V_35 ;
struct V_6 * V_21 ;
struct V_17 * V_22 ;
int V_9 = F_7 ( V_16 ) ;
int V_10 = F_8 ( V_16 ) ;
V_22 = F_10 ( V_16 ) ;
for (; V_8 ; V_8 = F_21 ( V_8 ) ) {
V_21 = F_4 ( V_8 , V_9 , V_10 ) ;
V_35 = F_22 ( & V_8 -> V_36 ) ;
if ( V_35 || V_21 -> V_29 ) {
F_18 ( & V_22 -> V_34 ) ;
if ( V_21 -> V_29 )
F_15 ( V_8 , V_21 , V_22 ) ;
F_11 ( V_8 , V_21 , V_22 , V_35 ) ;
F_19 ( & V_22 -> V_34 ) ;
}
}
}
static void F_23 ( struct V_7 * V_8 )
{
int V_37 , V_38 ;
struct V_6 * V_21 ;
struct V_17 * V_22 ;
F_24 (node, N_POSSIBLE) {
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_21 = F_4 ( V_8 , V_37 , V_38 ) ;
V_22 = F_9 ( V_37 , V_38 ) ;
F_17 ( V_8 , V_21 , V_22 ) ;
}
}
}
static struct V_6 *
F_25 ( struct V_17 * V_22 )
{
struct V_24 * V_40 = NULL ;
struct V_6 * V_21 ;
V_41:
V_21 = NULL ;
V_40 = F_26 ( & V_22 -> V_26 ) ;
if ( ! V_40 )
goto V_42;
V_21 = F_12 ( V_40 , struct V_6 , V_31 ) ;
F_15 ( V_21 -> V_8 , V_21 , V_22 ) ;
if ( ! F_22 ( & V_21 -> V_8 -> V_36 ) ||
! F_27 ( & V_21 -> V_8 -> V_15 ) )
goto V_41;
V_42:
return V_21 ;
}
static struct V_6 *
F_28 ( struct V_17 * V_22 )
{
struct V_6 * V_21 ;
F_18 ( & V_22 -> V_34 ) ;
V_21 = F_25 ( V_22 ) ;
F_19 ( & V_22 -> V_34 ) ;
return V_21 ;
}
static long F_29 ( struct V_7 * V_8 ,
enum V_43 V_44 )
{
long V_45 = 0 ;
int V_46 ;
F_30 () ;
F_31 (cpu)
V_45 += F_32 ( V_8 -> V_47 -> V_48 [ V_44 ] , V_46 ) ;
#ifdef F_33
F_18 ( & V_8 -> V_49 ) ;
V_45 += V_8 -> V_50 . V_48 [ V_44 ] ;
F_19 ( & V_8 -> V_49 ) ;
#endif
F_34 () ;
return V_45 ;
}
static void F_35 ( struct V_7 * V_8 ,
bool V_51 )
{
int V_45 = ( V_51 ) ? 1 : - 1 ;
F_36 ( V_8 -> V_47 -> V_48 [ V_52 ] , V_45 ) ;
}
void F_37 ( struct V_7 * V_8 , int V_45 )
{
F_36 ( V_8 -> V_47 -> V_53 [ V_54 ] , V_45 ) ;
}
void F_38 ( struct V_7 * V_8 , int V_45 )
{
F_36 ( V_8 -> V_47 -> V_53 [ V_55 ] , V_45 ) ;
}
static unsigned long F_39 ( struct V_7 * V_8 ,
enum V_56 V_44 )
{
unsigned long V_45 = 0 ;
int V_46 ;
F_31 (cpu)
V_45 += F_32 ( V_8 -> V_47 -> V_53 [ V_44 ] , V_46 ) ;
#ifdef F_33
F_18 ( & V_8 -> V_49 ) ;
V_45 += V_8 -> V_50 . V_53 [ V_44 ] ;
F_19 ( & V_8 -> V_49 ) ;
#endif
return V_45 ;
}
static void F_40 ( struct V_7 * V_8 ,
bool V_57 , int V_58 )
{
F_41 () ;
if ( V_57 )
F_42 ( V_8 -> V_47 -> V_48 [ V_59 ] , V_58 ) ;
else
F_42 ( V_8 -> V_47 -> V_48 [ V_60 ] , V_58 ) ;
if ( V_58 > 0 )
F_43 ( V_8 -> V_47 -> V_53 [ V_61 ] ) ;
else {
F_43 ( V_8 -> V_47 -> V_53 [ V_62 ] ) ;
V_58 = - V_58 ;
}
F_42 ( V_8 -> V_47 -> V_53 [ V_63 ] , V_58 ) ;
F_44 () ;
}
static unsigned long
F_45 ( struct V_7 * V_8 , int V_9 , enum V_64 V_44 )
{
struct V_6 * V_21 ;
T_1 V_65 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ ) {
V_21 = F_4 ( V_8 , V_9 , V_10 ) ;
V_65 += F_46 ( V_21 , V_44 ) ;
}
return V_65 ;
}
static unsigned long F_47 ( struct V_7 * V_8 ,
enum V_64 V_44 )
{
int V_9 ;
T_1 V_65 = 0 ;
F_48 (nid)
V_65 += F_45 ( V_8 , V_9 , V_44 ) ;
return V_65 ;
}
static bool F_49 ( struct V_7 * V_8 , int V_66 )
{
unsigned long V_45 , V_67 ;
V_45 = F_50 ( V_8 -> V_47 -> V_53 [ V_63 ] ) ;
V_67 = F_50 ( V_8 -> V_47 -> V_68 [ V_66 ] ) ;
return ( ( long ) V_67 - ( long ) V_45 < 0 ) ;
}
static void F_51 ( struct V_7 * V_8 , int V_66 )
{
unsigned long V_45 , V_67 ;
V_45 = F_50 ( V_8 -> V_47 -> V_53 [ V_63 ] ) ;
switch ( V_66 ) {
case V_69 :
V_67 = V_45 + V_70 ;
break;
case V_71 :
V_67 = V_45 + V_72 ;
break;
case V_73 :
V_67 = V_45 + V_74 ;
break;
default:
return;
}
F_52 ( V_8 -> V_47 -> V_68 [ V_66 ] , V_67 ) ;
}
static void F_53 ( struct V_7 * V_8 , struct V_16 * V_16 )
{
if ( F_54 ( F_49 ( V_8 , V_69 ) ) ) {
F_55 ( V_8 ) ;
F_51 ( V_8 , V_69 ) ;
if ( F_54 ( F_49 ( V_8 ,
V_71 ) ) ) {
F_20 ( V_8 , V_16 ) ;
F_51 ( V_8 ,
V_71 ) ;
}
#if V_75 > 1
if ( F_54 ( F_49 ( V_8 ,
V_73 ) ) ) {
F_56 ( & V_8 -> V_76 ) ;
F_51 ( V_8 ,
V_73 ) ;
}
#endif
}
}
static struct V_7 * F_57 ( struct V_77 * V_78 )
{
return F_58 ( V_14 ( V_78 ,
V_79 ) , struct V_7 ,
V_15 ) ;
}
struct V_7 * F_59 ( struct V_80 * V_25 )
{
if ( F_54 ( ! V_25 ) )
return NULL ;
return F_58 ( F_60 ( V_25 , V_79 ) ,
struct V_7 , V_15 ) ;
}
struct V_7 * F_61 ( struct V_81 * V_82 )
{
struct V_7 * V_8 = NULL ;
if ( ! V_82 )
return NULL ;
F_62 () ;
do {
V_8 = F_59 ( F_63 ( V_82 -> V_83 ) ) ;
if ( F_54 ( ! V_8 ) )
break;
} while ( ! F_27 ( & V_8 -> V_15 ) );
F_64 () ;
return V_8 ;
}
static struct V_7 * F_65 ( struct V_7 * V_8 )
{
struct V_14 * V_15 ;
int V_84 ;
if ( ! V_8 )
return V_85 ;
if ( ! V_8 -> V_86 ) {
if ( F_27 ( & V_8 -> V_15 ) )
return V_8 ;
return NULL ;
}
F_62 () ;
V_15 = F_66 ( & V_87 , 1 , & V_8 -> V_15 , & V_84 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_8 = F_58 ( V_15 , struct V_7 , V_15 ) ;
else
V_8 = NULL ;
F_64 () ;
return V_8 ;
}
static struct V_7 * F_67 ( struct V_7 * V_88 ,
struct V_7 * V_89 ,
bool V_90 )
{
int V_91 = F_68 ( & V_88 -> V_15 ) + 1 ;
int V_84 ;
int V_92 ;
struct V_14 * V_15 ;
V_92 = V_88 -> V_86 ;
F_69 ( & V_88 -> V_15 ) ;
if ( ! V_90 || ( V_89 && ! V_92 ) )
return NULL ;
if ( ! V_89 )
V_89 = V_85 ;
do {
V_88 = NULL ;
F_62 () ;
V_15 = F_66 ( & V_87 , V_91 ,
& V_89 -> V_15 , & V_84 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_88 = F_58 ( V_15 , struct V_7 , V_15 ) ;
F_64 () ;
V_91 = V_84 + 1 ;
} while ( V_15 && ! V_88 );
return V_88 ;
}
static inline bool F_70 ( struct V_7 * V_8 )
{
return ( V_8 == V_85 ) ;
}
void F_71 ( struct V_81 * V_82 , enum V_93 V_44 )
{
struct V_7 * V_8 ;
if ( ! V_82 )
return;
F_62 () ;
V_8 = F_59 ( F_63 ( V_82 -> V_83 ) ) ;
if ( F_54 ( ! V_8 ) )
goto V_94;
switch ( V_44 ) {
case V_95 :
F_38 ( V_8 , 1 ) ;
break;
case V_96 :
F_37 ( V_8 , 1 ) ;
break;
default:
F_72 () ;
}
V_94:
F_64 () ;
}
void F_73 ( struct V_16 * V_16 , enum V_64 V_97 )
{
struct V_98 * V_99 ;
struct V_6 * V_21 ;
if ( F_74 () )
return;
V_99 = F_75 ( V_16 ) ;
if ( ! F_76 ( V_99 ) )
return;
F_77 ( ! V_99 -> V_7 ) ;
V_21 = F_6 ( V_99 -> V_7 , V_16 ) ;
F_46 ( V_21 , V_97 ) -= 1 << F_78 ( V_16 ) ;
if ( F_70 ( V_99 -> V_7 ) )
return;
F_77 ( F_79 ( & V_99 -> V_97 ) ) ;
F_80 ( & V_99 -> V_97 ) ;
}
void F_81 ( struct V_16 * V_16 )
{
F_73 ( V_16 , F_82 ( V_16 ) ) ;
}
void F_83 ( struct V_16 * V_16 )
{
struct V_6 * V_21 ;
struct V_98 * V_99 ;
enum V_64 V_97 = F_82 ( V_16 ) ;
if ( F_74 () )
return;
V_99 = F_75 ( V_16 ) ;
if ( ! F_84 ( V_99 ) )
return;
F_85 () ;
if ( F_70 ( V_99 -> V_7 ) )
return;
V_21 = F_6 ( V_99 -> V_7 , V_16 ) ;
F_86 ( & V_99 -> V_97 , & V_21 -> V_100 [ V_97 ] ) ;
}
void F_87 ( struct V_16 * V_16 , enum V_64 V_97 )
{
struct V_6 * V_21 ;
struct V_98 * V_99 ;
if ( F_74 () )
return;
V_99 = F_75 ( V_16 ) ;
if ( ! F_84 ( V_99 ) )
return;
F_85 () ;
if ( F_70 ( V_99 -> V_7 ) )
return;
V_21 = F_6 ( V_99 -> V_7 , V_16 ) ;
F_88 ( & V_99 -> V_97 , & V_21 -> V_100 [ V_97 ] ) ;
}
void F_89 ( struct V_16 * V_16 , enum V_64 V_97 )
{
struct V_98 * V_99 ;
struct V_6 * V_21 ;
if ( F_74 () )
return;
V_99 = F_75 ( V_16 ) ;
F_77 ( F_90 ( V_99 ) ) ;
if ( ! F_84 ( V_99 ) )
return;
F_85 () ;
V_21 = F_6 ( V_99 -> V_7 , V_16 ) ;
F_46 ( V_21 , V_97 ) += 1 << F_78 ( V_16 ) ;
F_91 ( V_99 ) ;
if ( F_70 ( V_99 -> V_7 ) )
return;
F_92 ( & V_99 -> V_97 , & V_21 -> V_100 [ V_97 ] ) ;
}
static void F_93 ( struct V_16 * V_16 )
{
unsigned long V_101 ;
struct V_38 * V_38 = F_94 ( V_16 ) ;
struct V_98 * V_99 = F_75 ( V_16 ) ;
if ( F_95 ( ! F_96 ( V_16 ) ) )
return;
F_97 ( & V_38 -> V_102 , V_101 ) ;
if ( ! F_84 ( V_99 ) )
F_73 ( V_16 , F_82 ( V_16 ) ) ;
F_98 ( & V_38 -> V_102 , V_101 ) ;
}
static void F_99 ( struct V_16 * V_16 )
{
unsigned long V_101 ;
struct V_38 * V_38 = F_94 ( V_16 ) ;
struct V_98 * V_99 = F_75 ( V_16 ) ;
if ( F_95 ( ! F_96 ( V_16 ) ) )
return;
F_97 ( & V_38 -> V_102 , V_101 ) ;
if ( F_96 ( V_16 ) && ! F_90 ( V_99 ) )
F_89 ( V_16 , F_82 ( V_16 ) ) ;
F_98 ( & V_38 -> V_102 , V_101 ) ;
}
void F_100 ( struct V_16 * V_16 ,
enum V_64 V_103 , enum V_64 V_3 )
{
if ( F_74 () )
return;
F_73 ( V_16 , V_103 ) ;
F_89 ( V_16 , V_3 ) ;
}
int F_101 ( struct V_80 * V_104 , const struct V_7 * V_8 )
{
int V_105 ;
struct V_7 * V_106 = NULL ;
struct V_80 * V_25 ;
V_25 = F_102 ( V_104 ) ;
if ( ! V_25 )
return 0 ;
V_106 = F_61 ( V_25 -> V_82 ) ;
F_103 ( V_25 ) ;
if ( ! V_106 )
return 0 ;
if ( V_8 -> V_86 )
V_105 = F_104 ( & V_106 -> V_15 , & V_8 -> V_15 ) ;
else
V_105 = ( V_106 == V_8 ) ;
F_69 ( & V_106 -> V_15 ) ;
return V_105 ;
}
static int F_105 ( struct V_7 * V_107 , unsigned long * V_108 )
{
unsigned long V_109 ;
unsigned long V_110 ;
unsigned long V_111 ;
unsigned long V_112 ;
V_110 = F_47 ( V_107 , V_113 ) ;
V_109 = F_47 ( V_107 , V_114 ) ;
V_111 = ( V_110 + V_109 ) >> ( 30 - V_115 ) ;
if ( V_111 )
V_112 = F_106 ( 10 * V_111 ) ;
else
V_112 = 1 ;
if ( V_108 ) {
V_108 [ 0 ] = V_110 ;
V_108 [ 1 ] = V_109 ;
}
return V_112 ;
}
int F_107 ( struct V_7 * V_107 )
{
unsigned long V_109 ;
unsigned long V_110 ;
unsigned long V_108 [ 2 ] ;
unsigned long V_112 ;
V_112 = F_105 ( V_107 , V_108 ) ;
V_110 = V_108 [ 0 ] ;
V_109 = V_108 [ 1 ] ;
if ( V_110 * V_112 < V_109 )
return 1 ;
return 0 ;
}
int F_108 ( struct V_7 * V_107 )
{
unsigned long V_109 ;
unsigned long V_110 ;
V_110 = F_47 ( V_107 , V_116 ) ;
V_109 = F_47 ( V_107 , V_117 ) ;
return ( V_109 > V_110 ) ;
}
unsigned long F_109 ( struct V_7 * V_107 ,
struct V_38 * V_38 ,
enum V_64 V_97 )
{
int V_9 = F_110 ( V_38 ) ;
int V_10 = F_111 ( V_38 ) ;
struct V_6 * V_21 = F_4 ( V_107 , V_9 , V_10 ) ;
return F_46 ( V_21 , V_97 ) ;
}
static unsigned long F_112 ( struct V_7 * V_107 ,
int V_9 )
{
unsigned long V_105 ;
V_105 = F_45 ( V_107 , V_9 , V_116 ) +
F_45 ( V_107 , V_9 , V_117 ) ;
return V_105 ;
}
static unsigned long F_113 ( struct V_7 * V_107 ,
int V_9 )
{
unsigned long V_105 ;
V_105 = F_45 ( V_107 , V_9 , V_113 ) +
F_45 ( V_107 , V_9 , V_114 ) ;
return V_105 ;
}
static unsigned long F_114 ( struct V_7 * V_107 )
{
T_1 V_65 = 0 ;
int V_9 ;
F_24 (nid, N_HIGH_MEMORY)
V_65 += F_112 ( V_107 , V_9 ) ;
return V_65 ;
}
static unsigned long F_115 ( struct V_7 * V_107 )
{
T_1 V_65 = 0 ;
int V_9 ;
F_24 (nid, N_HIGH_MEMORY)
V_65 += F_113 ( V_107 , V_9 ) ;
return V_65 ;
}
static unsigned long
F_116 ( struct V_7 * V_107 , int V_9 )
{
return F_45 ( V_107 , V_9 , V_118 ) ;
}
static unsigned long
F_117 ( struct V_7 * V_107 )
{
T_1 V_65 = 0 ;
int V_9 ;
F_24 (nid, N_HIGH_MEMORY)
V_65 += F_116 ( V_107 , V_9 ) ;
return V_65 ;
}
static unsigned long F_118 ( struct V_7 * V_107 ,
int V_9 )
{
enum V_64 V_119 ;
T_1 V_65 = 0 ;
F_119 (l)
V_65 += F_45 ( V_107 , V_9 , V_119 ) ;
return V_65 ;
}
static unsigned long F_120 ( struct V_7 * V_107 )
{
T_1 V_65 = 0 ;
int V_9 ;
F_24 (nid, N_HIGH_MEMORY)
V_65 += F_118 ( V_107 , V_9 ) ;
return V_65 ;
}
struct V_120 * F_121 ( struct V_7 * V_107 ,
struct V_38 * V_38 )
{
int V_9 = F_110 ( V_38 ) ;
int V_10 = F_111 ( V_38 ) ;
struct V_6 * V_21 = F_4 ( V_107 , V_9 , V_10 ) ;
return & V_21 -> V_121 ;
}
struct V_120 *
F_122 ( struct V_16 * V_16 )
{
struct V_98 * V_99 ;
struct V_6 * V_21 ;
if ( F_74 () )
return NULL ;
V_99 = F_75 ( V_16 ) ;
if ( ! F_84 ( V_99 ) )
return NULL ;
F_85 () ;
V_21 = F_6 ( V_99 -> V_7 , V_16 ) ;
return & V_21 -> V_121 ;
}
unsigned long F_123 ( unsigned long V_122 ,
struct V_123 * V_124 ,
unsigned long * V_125 , int V_126 ,
int V_127 , struct V_38 * V_128 ,
struct V_7 * V_129 ,
int V_109 , int V_57 )
{
unsigned long V_130 = 0 ;
struct V_16 * V_16 ;
unsigned long V_131 ;
F_124 ( V_132 ) ;
struct V_123 * V_133 ;
struct V_98 * V_99 , * V_134 ;
int V_9 = F_110 ( V_128 ) ;
int V_10 = F_111 ( V_128 ) ;
struct V_6 * V_21 ;
int V_97 = V_135 * V_57 + V_109 ;
int V_105 ;
F_125 ( ! V_129 ) ;
V_21 = F_4 ( V_129 , V_9 , V_10 ) ;
V_133 = & V_21 -> V_100 [ V_97 ] ;
V_131 = 0 ;
F_126 (pc, tmp, src, lru) {
if ( V_131 >= V_122 )
break;
if ( F_54 ( ! F_84 ( V_99 ) ) )
continue;
V_16 = F_127 ( V_99 ) ;
if ( F_54 ( ! F_96 ( V_16 ) ) )
continue;
V_131 ++ ;
V_105 = F_128 ( V_16 , V_127 , V_57 ) ;
switch ( V_105 ) {
case 0 :
F_88 ( & V_16 -> V_97 , V_124 ) ;
F_81 ( V_16 ) ;
V_130 += F_129 ( V_16 ) ;
break;
case - V_136 :
F_87 ( V_16 , F_82 ( V_16 ) ) ;
break;
default:
break;
}
}
* V_125 = V_131 ;
F_130 ( 0 , V_122 , V_131 , V_130 ,
0 , 0 , 0 , V_127 ) ;
return V_130 ;
}
static unsigned long F_131 ( struct V_7 * V_8 )
{
unsigned long long V_137 ;
V_137 = F_132 ( & V_8 -> V_36 ) ;
if ( V_138 )
V_137 = F_133 ( V_137 , F_132 ( & V_8 -> V_139 ) ) ;
return V_137 >> V_115 ;
}
static unsigned int F_134 ( struct V_7 * V_107 )
{
struct V_77 * V_140 = V_107 -> V_15 . V_77 ;
if ( V_140 -> V_27 == NULL )
return V_141 ;
return V_107 -> V_142 ;
}
static void F_135 ( struct V_7 * V_8 )
{
int V_46 ;
F_30 () ;
F_18 ( & V_8 -> V_49 ) ;
F_31 (cpu)
F_32 ( V_8 -> V_47 -> V_48 [ V_143 ] , V_46 ) += 1 ;
V_8 -> V_50 . V_48 [ V_143 ] += 1 ;
F_19 ( & V_8 -> V_49 ) ;
F_34 () ;
F_136 () ;
}
static void F_137 ( struct V_7 * V_8 )
{
int V_46 ;
if ( ! V_8 )
return;
F_30 () ;
F_18 ( & V_8 -> V_49 ) ;
F_31 (cpu)
F_32 ( V_8 -> V_47 -> V_48 [ V_143 ] , V_46 ) -= 1 ;
V_8 -> V_50 . V_48 [ V_143 ] -= 1 ;
F_19 ( & V_8 -> V_49 ) ;
F_34 () ;
}
static bool F_138 ( struct V_7 * V_8 )
{
F_77 ( ! F_139 () ) ;
return F_50 ( V_8 -> V_47 -> V_48 [ V_143 ] ) > 0 ;
}
static bool F_140 ( struct V_7 * V_8 )
{
struct V_7 * V_103 ;
struct V_7 * V_3 ;
bool V_105 = false ;
F_18 ( & V_2 . V_34 ) ;
V_103 = V_2 . V_103 ;
V_3 = V_2 . V_3 ;
if ( ! V_103 )
goto V_144;
if ( V_103 == V_8 || V_3 == V_8
|| ( V_8 -> V_86 && F_104 ( & V_103 -> V_15 , & V_8 -> V_15 ) )
|| ( V_8 -> V_86 && F_104 ( & V_3 -> V_15 , & V_8 -> V_15 ) ) )
V_105 = true ;
V_144:
F_19 ( & V_2 . V_34 ) ;
return V_105 ;
}
static bool F_141 ( struct V_7 * V_8 )
{
if ( V_2 . V_145 && V_146 != V_2 . V_145 ) {
if ( F_140 ( V_8 ) ) {
F_142 ( V_147 ) ;
F_143 ( & V_2 . V_148 , & V_147 , V_149 ) ;
if ( V_2 . V_145 )
F_144 () ;
F_145 ( & V_2 . V_148 , & V_147 ) ;
return true ;
}
}
return false ;
}
void F_146 ( struct V_7 * V_107 , struct V_80 * V_25 )
{
struct V_77 * V_150 ;
struct V_77 * V_151 ;
static char V_152 [ V_153 ] ;
int V_105 ;
if ( ! V_107 || ! V_25 )
return;
F_62 () ;
V_151 = V_107 -> V_15 . V_77 ;
V_150 = F_147 ( V_25 , V_79 ) ;
V_105 = F_148 ( V_150 , V_152 , V_153 ) ;
if ( V_105 < 0 ) {
F_64 () ;
goto V_42;
}
F_64 () ;
F_149 ( V_154 L_1 , V_152 ) ;
F_62 () ;
V_105 = F_148 ( V_151 , V_152 , V_153 ) ;
if ( V_105 < 0 ) {
F_64 () ;
goto V_42;
}
F_64 () ;
F_149 ( V_155 L_2 , V_152 ) ;
V_42:
F_149 ( V_154 L_3 ,
F_150 ( & V_107 -> V_36 , V_156 ) >> 10 ,
F_150 ( & V_107 -> V_36 , V_157 ) >> 10 ,
F_150 ( & V_107 -> V_36 , V_158 ) ) ;
F_149 ( V_154 L_4
L_5 ,
F_150 ( & V_107 -> V_139 , V_156 ) >> 10 ,
F_150 ( & V_107 -> V_139 , V_157 ) >> 10 ,
F_150 ( & V_107 -> V_139 , V_158 ) ) ;
}
static int F_151 ( struct V_7 * V_8 )
{
int V_159 = 0 ;
struct V_7 * V_88 ;
F_152 (iter, mem)
V_159 ++ ;
return V_159 ;
}
T_1 F_153 ( struct V_7 * V_107 )
{
T_1 V_160 ;
T_1 V_139 ;
V_160 = F_150 ( & V_107 -> V_36 , V_157 ) ;
V_160 += V_161 << V_115 ;
V_139 = F_150 ( & V_107 -> V_139 , V_157 ) ;
return F_133 ( V_160 , V_139 ) ;
}
static struct V_7 *
F_154 ( struct V_7 * V_162 )
{
struct V_7 * V_105 = NULL ;
struct V_14 * V_15 ;
int V_91 , V_84 ;
if ( ! V_162 -> V_86 ) {
F_155 ( & V_162 -> V_15 ) ;
V_105 = V_162 ;
}
while ( ! V_105 ) {
F_62 () ;
V_91 = V_162 -> V_163 + 1 ;
V_15 = F_66 ( & V_87 , V_91 , & V_162 -> V_15 ,
& V_84 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_105 = F_58 ( V_15 , struct V_7 , V_15 ) ;
F_64 () ;
if ( ! V_15 ) {
V_162 -> V_163 = 0 ;
} else
V_162 -> V_163 = V_84 ;
}
return V_105 ;
}
static bool F_156 ( struct V_7 * V_8 ,
int V_9 , bool V_164 )
{
if ( F_112 ( V_8 , V_9 ) )
return true ;
if ( V_164 || ! V_161 )
return false ;
if ( F_113 ( V_8 , V_9 ) )
return true ;
return false ;
}
static void F_157 ( struct V_7 * V_8 )
{
int V_9 ;
if ( ! F_158 ( & V_8 -> V_76 ) )
return;
if ( F_159 ( & V_8 -> V_165 ) > 1 )
return;
V_8 -> V_166 = V_167 [ V_168 ] ;
F_160 (nid, node_states[N_HIGH_MEMORY]) {
if ( ! F_156 ( V_8 , V_9 , false ) )
F_161 ( V_9 , V_8 -> V_166 ) ;
}
F_162 ( & V_8 -> V_76 , 0 ) ;
F_162 ( & V_8 -> V_165 , 0 ) ;
}
int F_163 ( struct V_7 * V_8 )
{
int V_37 ;
F_157 ( V_8 ) ;
V_37 = V_8 -> V_169 ;
V_37 = F_164 ( V_37 , V_8 -> V_166 ) ;
if ( V_37 == V_75 )
V_37 = F_165 ( V_8 -> V_166 ) ;
if ( F_54 ( V_37 == V_75 ) )
V_37 = F_166 () ;
V_8 -> V_169 = V_37 ;
return V_37 ;
}
bool F_167 ( struct V_7 * V_8 , bool V_164 )
{
int V_9 ;
if ( ! F_168 ( V_8 -> V_166 ) ) {
for ( V_9 = F_165 ( V_8 -> V_166 ) ;
V_9 < V_75 ;
V_9 = F_164 ( V_9 , V_8 -> V_166 ) ) {
if ( F_156 ( V_8 , V_9 , V_164 ) )
return true ;
}
}
F_24 (nid, N_HIGH_MEMORY) {
if ( F_169 ( V_9 , V_8 -> V_166 ) )
continue;
if ( F_156 ( V_8 , V_9 , V_164 ) )
return true ;
}
return false ;
}
int F_163 ( struct V_7 * V_8 )
{
return 0 ;
}
bool F_167 ( struct V_7 * V_8 , bool V_164 )
{
return F_156 ( V_8 , 0 , V_164 ) ;
}
static int F_170 ( struct V_7 * V_162 ,
struct V_38 * V_38 ,
T_2 V_170 ,
unsigned long V_171 ,
unsigned long * V_172 )
{
struct V_7 * V_173 ;
int V_105 , V_65 = 0 ;
int V_174 = 0 ;
bool V_164 = V_171 & V_175 ;
bool V_176 = V_171 & V_177 ;
bool V_178 = V_171 & V_179 ;
unsigned long V_35 ;
unsigned long V_180 ;
V_35 = F_22 ( & V_162 -> V_36 ) >> V_115 ;
if ( ! V_178 && V_162 -> V_181 )
V_164 = true ;
while ( 1 ) {
V_173 = F_154 ( V_162 ) ;
if ( V_173 == V_162 ) {
V_174 ++ ;
if ( ! V_178 && V_174 >= 1 )
F_171 ( V_162 ) ;
if ( V_174 >= 2 ) {
if ( ! V_178 || ! V_65 ) {
F_69 ( & V_173 -> V_15 ) ;
break;
}
if ( V_65 >= ( V_35 >> 2 ) ||
( V_174 > V_182 ) ) {
F_69 ( & V_173 -> V_15 ) ;
break;
}
}
}
if ( ! F_167 ( V_173 , V_164 ) ) {
F_69 ( & V_173 -> V_15 ) ;
continue;
}
if ( V_178 ) {
V_105 = F_172 ( V_173 , V_170 ,
V_164 , F_134 ( V_173 ) , V_38 ,
& V_180 ) ;
* V_172 += V_180 ;
} else
V_105 = F_173 ( V_173 , V_170 ,
V_164 , F_134 ( V_173 ) ) ;
F_69 ( & V_173 -> V_15 ) ;
if ( V_176 )
return V_105 ;
V_65 += V_105 ;
if ( V_178 ) {
if ( ! F_22 ( & V_162 -> V_36 ) )
return V_65 ;
} else if ( F_131 ( V_162 ) )
return V_65 ;
}
return V_65 ;
}
static bool F_174 ( struct V_7 * V_8 )
{
int V_183 , V_184 = 0 ;
struct V_7 * V_88 ;
F_152 (iter, mem) {
V_183 = F_159 ( & V_88 -> V_185 ) ;
V_184 = F_175 ( V_183 , V_184 ) ;
}
if ( V_184 == 1 )
return true ;
return false ;
}
static int F_176 ( struct V_7 * V_8 )
{
struct V_7 * V_88 ;
F_152 (iter, mem)
F_177 ( & V_88 -> V_185 , - 1 , 0 ) ;
return 0 ;
}
static int F_178 ( T_3 * V_147 ,
unsigned V_127 , int V_186 , void * V_187 )
{
struct V_7 * V_188 = (struct V_7 * ) V_187 ;
struct V_189 * V_189 ;
V_189 = F_58 ( V_147 , struct V_189 , V_147 ) ;
if ( V_189 -> V_8 == V_188 )
goto V_190;
if ( ! V_189 -> V_8 -> V_86 || ! V_188 -> V_86 )
return 0 ;
if ( ! F_104 ( & V_189 -> V_8 -> V_15 , & V_188 -> V_15 ) &&
! F_104 ( & V_188 -> V_15 , & V_189 -> V_8 -> V_15 ) )
return 0 ;
V_190:
return F_179 ( V_147 , V_127 , V_186 , V_187 ) ;
}
static void F_180 ( struct V_7 * V_8 )
{
F_181 ( & V_191 , V_192 , 0 , V_8 ) ;
}
static void F_182 ( struct V_7 * V_8 )
{
if ( V_8 && F_158 ( & V_8 -> V_185 ) )
F_180 ( V_8 ) ;
}
bool F_183 ( struct V_7 * V_8 , T_2 V_193 )
{
struct V_189 V_194 ;
bool V_195 , V_196 ;
V_194 . V_8 = V_8 ;
V_194 . V_147 . V_101 = 0 ;
V_194 . V_147 . V_197 = F_178 ;
V_194 . V_147 . V_198 = V_146 ;
F_184 ( & V_194 . V_147 . V_199 ) ;
V_196 = true ;
F_185 ( & V_200 ) ;
V_195 = F_174 ( V_8 ) ;
F_143 ( & V_191 , & V_194 . V_147 , V_201 ) ;
if ( ! V_195 || V_8 -> V_202 )
V_196 = false ;
if ( V_195 )
F_186 ( V_8 ) ;
F_187 ( & V_200 ) ;
if ( V_196 ) {
F_145 ( & V_191 , & V_194 . V_147 ) ;
F_188 ( V_8 , V_193 ) ;
} else {
F_144 () ;
F_145 ( & V_191 , & V_194 . V_147 ) ;
}
F_185 ( & V_200 ) ;
F_176 ( V_8 ) ;
F_180 ( V_8 ) ;
F_187 ( & V_200 ) ;
if ( F_189 ( V_203 ) || F_190 ( V_146 ) )
return false ;
F_191 ( 1 ) ;
return true ;
}
void F_192 ( struct V_16 * V_16 ,
enum V_204 V_44 , int V_45 )
{
struct V_7 * V_8 ;
struct V_98 * V_99 = F_75 ( V_16 ) ;
bool V_205 = false ;
unsigned long V_206 ( V_101 ) ;
if ( F_54 ( ! V_99 ) )
return;
F_62 () ;
V_8 = V_99 -> V_7 ;
if ( F_54 ( ! V_8 || ! F_84 ( V_99 ) ) )
goto V_94;
if ( F_54 ( F_138 ( V_8 ) ) || F_193 ( V_16 ) ) {
F_194 ( V_99 , & V_101 ) ;
V_205 = true ;
V_8 = V_99 -> V_7 ;
if ( ! V_8 || ! F_84 ( V_99 ) )
goto V_94;
}
switch ( V_44 ) {
case V_207 :
if ( V_45 > 0 )
F_195 ( V_99 ) ;
else if ( ! F_196 ( V_16 ) )
F_197 ( V_99 ) ;
V_44 = V_208 ;
break;
default:
F_72 () ;
}
F_36 ( V_8 -> V_47 -> V_48 [ V_44 ] , V_45 ) ;
V_94:
if ( F_54 ( V_205 ) )
F_198 ( V_99 , & V_101 ) ;
F_64 () ;
return;
}
static bool F_199 ( struct V_7 * V_8 )
{
struct V_209 * V_210 ;
bool V_105 = true ;
V_210 = & F_200 ( V_211 ) ;
if ( V_8 == V_210 -> V_212 && V_210 -> V_58 )
V_210 -> V_58 -- ;
else
V_105 = false ;
F_201 ( V_211 ) ;
return V_105 ;
}
static void F_202 ( struct V_209 * V_210 )
{
struct V_7 * V_213 = V_210 -> V_212 ;
if ( V_210 -> V_58 ) {
unsigned long V_214 = V_210 -> V_58 * V_215 ;
F_203 ( & V_213 -> V_36 , V_214 ) ;
if ( V_138 )
F_203 ( & V_213 -> V_139 , V_214 ) ;
V_210 -> V_58 = 0 ;
}
V_210 -> V_212 = NULL ;
}
static void F_204 ( struct V_216 * V_217 )
{
struct V_209 * V_210 = & F_205 ( V_211 ) ;
F_202 ( V_210 ) ;
F_206 ( V_218 , & V_210 -> V_101 ) ;
}
static void F_207 ( struct V_7 * V_8 , unsigned int V_58 )
{
struct V_209 * V_210 = & F_200 ( V_211 ) ;
if ( V_210 -> V_212 != V_8 ) {
F_202 ( V_210 ) ;
V_210 -> V_212 = V_8 ;
}
V_210 -> V_58 += V_58 ;
F_201 ( V_211 ) ;
}
static void F_171 ( struct V_7 * V_162 )
{
int V_46 , V_219 ;
if ( ! F_208 ( & V_220 ) )
return;
F_30 () ;
V_219 = F_209 () ;
F_31 (cpu) {
struct V_209 * V_210 = & F_32 ( V_211 , V_46 ) ;
struct V_7 * V_8 ;
if ( V_46 == V_219 )
continue;
V_8 = V_210 -> V_212 ;
if ( ! V_8 )
continue;
if ( V_8 != V_162 ) {
if ( ! V_162 -> V_86 )
continue;
if ( ! F_104 ( & V_8 -> V_15 , & V_162 -> V_15 ) )
continue;
}
if ( ! F_210 ( V_218 , & V_210 -> V_101 ) )
F_211 ( V_46 , & V_210 -> V_221 ) ;
}
F_34 () ;
F_187 ( & V_220 ) ;
}
static void F_212 ( void )
{
F_185 ( & V_220 ) ;
F_213 ( F_204 ) ;
F_187 ( & V_220 ) ;
}
static void F_214 ( struct V_7 * V_8 , int V_46 )
{
int V_222 ;
F_18 ( & V_8 -> V_49 ) ;
for ( V_222 = 0 ; V_222 < V_223 ; V_222 ++ ) {
long V_183 = F_32 ( V_8 -> V_47 -> V_48 [ V_222 ] , V_46 ) ;
F_32 ( V_8 -> V_47 -> V_48 [ V_222 ] , V_46 ) = 0 ;
V_8 -> V_50 . V_48 [ V_222 ] += V_183 ;
}
for ( V_222 = 0 ; V_222 < V_224 ; V_222 ++ ) {
unsigned long V_183 = F_32 ( V_8 -> V_47 -> V_53 [ V_222 ] , V_46 ) ;
F_32 ( V_8 -> V_47 -> V_53 [ V_222 ] , V_46 ) = 0 ;
V_8 -> V_50 . V_53 [ V_222 ] += V_183 ;
}
F_32 ( V_8 -> V_47 -> V_48 [ V_143 ] , V_46 ) = 0 ;
F_19 ( & V_8 -> V_49 ) ;
}
static void F_215 ( struct V_7 * V_8 , int V_46 )
{
int V_44 = V_143 ;
F_18 ( & V_8 -> V_49 ) ;
F_32 ( V_8 -> V_47 -> V_48 [ V_44 ] , V_46 ) = V_8 -> V_50 . V_48 [ V_44 ] ;
F_19 ( & V_8 -> V_49 ) ;
}
static int T_4 F_216 ( struct V_225 * V_226 ,
unsigned long V_227 ,
void * V_228 )
{
int V_46 = ( unsigned long ) V_228 ;
struct V_209 * V_210 ;
struct V_7 * V_88 ;
if ( ( V_227 == V_229 ) ) {
F_217 (iter)
F_215 ( V_88 , V_46 ) ;
return V_230 ;
}
if ( ( V_227 != V_231 ) || V_227 != V_232 )
return V_230 ;
F_217 (iter)
F_214 ( V_88 , V_46 ) ;
V_210 = & F_32 ( V_211 , V_46 ) ;
F_202 ( V_210 ) ;
return V_230 ;
}
static int F_218 ( struct V_7 * V_8 , T_2 V_170 ,
unsigned int V_58 , bool V_233 )
{
unsigned long V_234 = V_58 * V_215 ;
struct V_7 * V_235 ;
struct V_236 * V_237 ;
unsigned long V_101 = 0 ;
int V_105 ;
V_105 = F_219 ( & V_8 -> V_36 , V_234 , & V_237 ) ;
if ( F_95 ( ! V_105 ) ) {
if ( ! V_138 )
return V_238 ;
V_105 = F_219 ( & V_8 -> V_139 , V_234 , & V_237 ) ;
if ( F_95 ( ! V_105 ) )
return V_238 ;
F_203 ( & V_8 -> V_36 , V_234 ) ;
V_235 = F_220 ( V_237 , V_139 ) ;
V_101 |= V_175 ;
} else
V_235 = F_220 ( V_237 , V_36 ) ;
if ( V_58 == V_239 )
return V_240 ;
if ( ! ( V_170 & V_241 ) )
return V_242 ;
V_105 = F_170 ( V_235 , NULL ,
V_170 , V_101 , NULL ) ;
if ( F_131 ( V_235 ) >= V_58 )
return V_240 ;
if ( V_58 == 1 && V_105 )
return V_240 ;
if ( F_141 ( V_235 ) )
return V_240 ;
if ( ! V_233 )
return V_243 ;
if ( ! F_183 ( V_235 , V_170 ) )
return V_244 ;
return V_240 ;
}
static int F_221 ( struct V_81 * V_82 ,
T_2 V_170 ,
unsigned int V_58 ,
struct V_7 * * V_107 ,
bool V_245 )
{
unsigned int V_246 = F_175 ( V_239 , V_58 ) ;
int V_247 = V_248 ;
struct V_7 * V_8 = NULL ;
int V_105 ;
if ( F_54 ( F_189 ( V_203 )
|| F_190 ( V_146 ) ) )
goto V_249;
if ( ! * V_107 && ! V_82 )
goto V_249;
V_250:
if ( * V_107 ) {
V_8 = * V_107 ;
F_77 ( F_222 ( & V_8 -> V_15 ) ) ;
if ( F_70 ( V_8 ) )
goto V_42;
if ( V_58 == 1 && F_199 ( V_8 ) )
goto V_42;
F_155 ( & V_8 -> V_15 ) ;
} else {
struct V_80 * V_25 ;
F_62 () ;
V_25 = F_63 ( V_82 -> V_83 ) ;
V_8 = F_59 ( V_25 ) ;
if ( ! V_8 || F_70 ( V_8 ) ) {
F_64 () ;
goto V_42;
}
if ( V_58 == 1 && F_199 ( V_8 ) ) {
F_64 () ;
goto V_42;
}
if ( ! F_27 ( & V_8 -> V_15 ) ) {
F_64 () ;
goto V_250;
}
F_64 () ;
}
do {
bool V_233 ;
if ( F_190 ( V_146 ) ) {
F_69 ( & V_8 -> V_15 ) ;
goto V_249;
}
V_233 = false ;
if ( V_245 && ! V_247 ) {
V_233 = true ;
V_247 = V_248 ;
}
V_105 = F_218 ( V_8 , V_170 , V_246 , V_233 ) ;
switch ( V_105 ) {
case V_238 :
break;
case V_240 :
V_246 = V_58 ;
F_69 ( & V_8 -> V_15 ) ;
V_8 = NULL ;
goto V_250;
case V_242 :
F_69 ( & V_8 -> V_15 ) ;
goto V_251;
case V_243 :
if ( ! V_245 ) {
F_69 ( & V_8 -> V_15 ) ;
goto V_251;
}
V_247 -- ;
break;
case V_244 :
F_69 ( & V_8 -> V_15 ) ;
goto V_249;
}
} while ( V_105 != V_238 );
if ( V_246 > V_58 )
F_207 ( V_8 , V_246 - V_58 ) ;
F_69 ( & V_8 -> V_15 ) ;
V_42:
* V_107 = V_8 ;
return 0 ;
V_251:
* V_107 = NULL ;
return - V_252 ;
V_249:
* V_107 = NULL ;
return 0 ;
}
static void F_223 ( struct V_7 * V_8 ,
unsigned int V_58 )
{
if ( ! F_70 ( V_8 ) ) {
unsigned long V_214 = V_58 * V_215 ;
F_203 ( & V_8 -> V_36 , V_214 ) ;
if ( V_138 )
F_203 ( & V_8 -> V_139 , V_214 ) ;
}
}
static struct V_7 * F_224 ( unsigned short V_253 )
{
struct V_14 * V_15 ;
if ( ! V_253 )
return NULL ;
V_15 = F_225 ( & V_87 , V_253 ) ;
if ( ! V_15 )
return NULL ;
return F_58 ( V_15 , struct V_7 , V_15 ) ;
}
struct V_7 * F_226 ( struct V_16 * V_16 )
{
struct V_7 * V_8 = NULL ;
struct V_98 * V_99 ;
unsigned short V_253 ;
T_5 V_254 ;
F_77 ( ! F_227 ( V_16 ) ) ;
V_99 = F_75 ( V_16 ) ;
F_228 ( V_99 ) ;
if ( F_84 ( V_99 ) ) {
V_8 = V_99 -> V_7 ;
if ( V_8 && ! F_27 ( & V_8 -> V_15 ) )
V_8 = NULL ;
} else if ( F_229 ( V_16 ) ) {
V_254 . V_45 = F_230 ( V_16 ) ;
V_253 = F_231 ( V_254 ) ;
F_62 () ;
V_8 = F_224 ( V_253 ) ;
if ( V_8 && ! F_27 ( & V_8 -> V_15 ) )
V_8 = NULL ;
F_64 () ;
}
F_232 ( V_99 ) ;
return V_8 ;
}
static void F_233 ( struct V_7 * V_8 ,
struct V_16 * V_16 ,
unsigned int V_58 ,
struct V_98 * V_99 ,
enum V_255 V_256 )
{
F_228 ( V_99 ) ;
if ( F_54 ( F_84 ( V_99 ) ) ) {
F_232 ( V_99 ) ;
F_223 ( V_8 , V_58 ) ;
return;
}
V_99 -> V_7 = V_8 ;
F_234 () ;
switch ( V_256 ) {
case V_257 :
case V_258 :
F_235 ( V_99 ) ;
F_236 ( V_99 ) ;
break;
case V_259 :
F_237 ( V_99 ) ;
F_236 ( V_99 ) ;
break;
default:
break;
}
F_40 ( V_8 , F_238 ( V_99 ) , V_58 ) ;
F_232 ( V_99 ) ;
F_53 ( V_8 , V_16 ) ;
}
void F_239 ( struct V_16 * V_260 , struct V_16 * V_261 )
{
struct V_98 * V_262 = F_75 ( V_260 ) ;
struct V_98 * V_263 = F_75 ( V_261 ) ;
unsigned long V_101 ;
if ( F_74 () )
return;
F_194 ( V_262 , & V_101 ) ;
V_263 -> V_7 = V_262 -> V_7 ;
F_234 () ;
if ( F_90 ( V_262 ) ) {
enum V_64 V_97 ;
struct V_6 * V_21 ;
V_97 = F_82 ( V_260 ) ;
V_21 = F_6 ( V_262 -> V_7 , V_260 ) ;
F_46 ( V_21 , V_97 ) -= 1 ;
}
V_263 -> V_101 = V_262 -> V_101 & ~ V_264 ;
F_198 ( V_262 , & V_101 ) ;
}
static int F_240 ( struct V_16 * V_16 ,
unsigned int V_58 ,
struct V_98 * V_99 ,
struct V_7 * V_103 ,
struct V_7 * V_3 ,
bool V_265 )
{
unsigned long V_101 ;
int V_105 ;
F_77 ( V_103 == V_3 ) ;
F_77 ( F_96 ( V_16 ) ) ;
V_105 = - V_136 ;
if ( V_58 > 1 && ! F_193 ( V_16 ) )
goto V_94;
F_228 ( V_99 ) ;
V_105 = - V_266 ;
if ( ! F_84 ( V_99 ) || V_99 -> V_7 != V_103 )
goto V_144;
F_194 ( V_99 , & V_101 ) ;
if ( F_241 ( V_99 ) ) {
F_41 () ;
F_242 ( V_103 -> V_47 -> V_48 [ V_208 ] ) ;
F_43 ( V_3 -> V_47 -> V_48 [ V_208 ] ) ;
F_44 () ;
}
F_40 ( V_103 , F_238 ( V_99 ) , - V_58 ) ;
if ( V_265 )
F_223 ( V_103 , V_58 ) ;
V_99 -> V_7 = V_3 ;
F_40 ( V_3 , F_238 ( V_99 ) , V_58 ) ;
F_198 ( V_99 , & V_101 ) ;
V_105 = 0 ;
V_144:
F_232 ( V_99 ) ;
F_53 ( V_3 , V_16 ) ;
F_53 ( V_103 , V_16 ) ;
V_94:
return V_105 ;
}
static int F_243 ( struct V_16 * V_16 ,
struct V_98 * V_99 ,
struct V_7 * V_267 ,
T_2 V_170 )
{
struct V_77 * V_268 = V_267 -> V_15 . V_77 ;
struct V_77 * V_269 = V_268 -> V_27 ;
struct V_7 * V_27 ;
unsigned int V_58 ;
unsigned long V_206 ( V_101 ) ;
int V_105 ;
if ( ! V_269 )
return - V_266 ;
V_105 = - V_136 ;
if ( ! F_244 ( V_16 ) )
goto V_94;
if ( F_245 ( V_16 ) )
goto V_270;
V_58 = F_129 ( V_16 ) ;
V_27 = F_57 ( V_269 ) ;
V_105 = F_221 ( NULL , V_170 , V_58 , & V_27 , false ) ;
if ( V_105 || ! V_27 )
goto V_271;
if ( V_58 > 1 )
V_101 = F_246 ( V_16 ) ;
V_105 = F_240 ( V_16 , V_58 , V_99 , V_267 , V_27 , true ) ;
if ( V_105 )
F_223 ( V_27 , V_58 ) ;
if ( V_58 > 1 )
F_247 ( V_16 , V_101 ) ;
V_271:
F_248 ( V_16 ) ;
V_270:
F_249 ( V_16 ) ;
V_94:
return V_105 ;
}
static int F_250 ( struct V_16 * V_16 , struct V_81 * V_82 ,
T_2 V_170 , enum V_255 V_256 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_58 = 1 ;
struct V_98 * V_99 ;
bool V_245 = true ;
int V_105 ;
if ( F_193 ( V_16 ) ) {
V_58 <<= F_78 ( V_16 ) ;
F_77 ( ! F_193 ( V_16 ) ) ;
V_245 = false ;
}
V_99 = F_75 ( V_16 ) ;
F_125 ( ! V_99 ) ;
V_105 = F_221 ( V_82 , V_170 , V_58 , & V_8 , V_245 ) ;
if ( V_105 || ! V_8 )
return V_105 ;
F_233 ( V_8 , V_16 , V_58 , V_99 , V_256 ) ;
return 0 ;
}
int F_251 ( struct V_16 * V_16 ,
struct V_81 * V_82 , T_2 V_170 )
{
if ( F_74 () )
return 0 ;
if ( F_196 ( V_16 ) || ( V_16 -> V_272 && ! F_252 ( V_16 ) ) )
return 0 ;
if ( F_54 ( ! V_82 ) )
V_82 = & V_273 ;
return F_250 ( V_16 , V_82 , V_170 ,
V_259 ) ;
}
static void
F_253 ( struct V_16 * V_16 , struct V_7 * V_8 ,
enum V_255 V_256 )
{
struct V_98 * V_99 = F_75 ( V_16 ) ;
F_93 ( V_16 ) ;
F_233 ( V_8 , V_16 , 1 , V_99 , V_256 ) ;
F_99 ( V_16 ) ;
return;
}
int F_254 ( struct V_16 * V_16 , struct V_81 * V_82 ,
T_2 V_170 )
{
struct V_7 * V_8 = NULL ;
int V_105 ;
if ( F_74 () )
return 0 ;
if ( F_255 ( V_16 ) )
return 0 ;
if ( ! ( V_170 & V_241 ) ) {
struct V_98 * V_99 ;
V_99 = F_75 ( V_16 ) ;
if ( ! V_99 )
return 0 ;
F_228 ( V_99 ) ;
if ( F_84 ( V_99 ) ) {
F_232 ( V_99 ) ;
return 0 ;
}
F_232 ( V_99 ) ;
}
if ( F_54 ( ! V_82 ) )
V_82 = & V_273 ;
if ( F_256 ( V_16 ) ) {
V_105 = F_221 ( V_82 , V_170 , 1 , & V_8 , true ) ;
if ( V_105 || ! V_8 )
return V_105 ;
F_253 ( V_16 , V_8 ,
V_257 ) ;
return V_105 ;
}
if ( F_229 ( V_16 ) ) {
V_105 = F_257 ( V_82 , V_16 , V_170 , & V_8 ) ;
if ( ! V_105 )
F_258 ( V_16 , V_8 ,
V_258 ) ;
} else
V_105 = F_250 ( V_16 , V_82 , V_170 ,
V_258 ) ;
return V_105 ;
}
int F_257 ( struct V_81 * V_82 ,
struct V_16 * V_16 ,
T_2 V_193 , struct V_7 * * V_274 )
{
struct V_7 * V_8 ;
int V_105 ;
* V_274 = NULL ;
if ( F_74 () )
return 0 ;
if ( ! V_138 )
goto V_275;
if ( ! F_229 ( V_16 ) )
goto V_275;
V_8 = F_226 ( V_16 ) ;
if ( ! V_8 )
goto V_275;
* V_274 = V_8 ;
V_105 = F_221 ( NULL , V_193 , 1 , V_274 , true ) ;
F_69 ( & V_8 -> V_15 ) ;
return V_105 ;
V_275:
if ( F_54 ( ! V_82 ) )
V_82 = & V_273 ;
return F_221 ( V_82 , V_193 , 1 , V_274 , true ) ;
}
static void
F_258 ( struct V_16 * V_16 , struct V_7 * V_274 ,
enum V_255 V_256 )
{
if ( F_74 () )
return;
if ( ! V_274 )
return;
F_259 ( & V_274 -> V_15 ) ;
F_253 ( V_16 , V_274 , V_256 ) ;
if ( V_138 && F_229 ( V_16 ) ) {
T_5 V_254 = { . V_45 = F_230 (page) } ;
unsigned short V_253 ;
struct V_7 * V_107 ;
V_253 = F_260 ( V_254 , 0 ) ;
F_62 () ;
V_107 = F_224 ( V_253 ) ;
if ( V_107 ) {
if ( ! F_70 ( V_107 ) )
F_203 ( & V_107 -> V_139 , V_215 ) ;
F_35 ( V_107 , false ) ;
F_261 ( V_107 ) ;
}
F_64 () ;
}
F_262 ( & V_274 -> V_15 ) ;
}
void F_263 ( struct V_16 * V_16 , struct V_7 * V_274 )
{
F_258 ( V_16 , V_274 ,
V_259 ) ;
}
void F_264 ( struct V_7 * V_8 )
{
if ( F_74 () )
return;
if ( ! V_8 )
return;
F_223 ( V_8 , 1 ) ;
}
static void F_265 ( struct V_7 * V_8 ,
unsigned int V_58 ,
const enum V_255 V_256 )
{
struct V_276 * V_246 = NULL ;
bool V_277 = true ;
if ( ! V_138 || V_256 == V_278 )
V_277 = false ;
V_246 = & V_146 -> V_279 ;
if ( ! V_246 -> V_107 )
V_246 -> V_107 = V_8 ;
if ( ! V_246 -> V_280 || F_189 ( V_203 ) )
goto V_281;
if ( V_58 > 1 )
goto V_281;
if ( V_246 -> V_107 != V_8 )
goto V_281;
V_246 -> V_58 ++ ;
if ( V_277 )
V_246 -> V_282 ++ ;
return;
V_281:
F_203 ( & V_8 -> V_36 , V_58 * V_215 ) ;
if ( V_277 )
F_203 ( & V_8 -> V_139 , V_58 * V_215 ) ;
if ( F_54 ( V_246 -> V_107 != V_8 ) )
F_182 ( V_8 ) ;
return;
}
static struct V_7 *
F_266 ( struct V_16 * V_16 , enum V_255 V_256 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_58 = 1 ;
struct V_98 * V_99 ;
if ( F_74 () )
return NULL ;
if ( F_229 ( V_16 ) )
return NULL ;
if ( F_193 ( V_16 ) ) {
V_58 <<= F_78 ( V_16 ) ;
F_77 ( ! F_193 ( V_16 ) ) ;
}
V_99 = F_75 ( V_16 ) ;
if ( F_54 ( ! V_99 || ! F_84 ( V_99 ) ) )
return NULL ;
F_228 ( V_99 ) ;
V_8 = V_99 -> V_7 ;
if ( ! F_84 ( V_99 ) )
goto V_283;
switch ( V_256 ) {
case V_259 :
case V_284 :
if ( F_196 ( V_16 ) || F_267 ( V_99 ) )
goto V_283;
break;
case V_278 :
if ( ! F_252 ( V_16 ) ) {
if ( V_16 -> V_272 && ! F_256 ( V_16 ) )
goto V_283;
} else if ( F_196 ( V_16 ) )
goto V_283;
break;
default:
break;
}
F_40 ( V_8 , F_238 ( V_99 ) , - V_58 ) ;
F_268 ( V_99 ) ;
F_232 ( V_99 ) ;
F_53 ( V_8 , V_16 ) ;
if ( V_138 && V_256 == V_278 ) {
F_35 ( V_8 , true ) ;
F_269 ( V_8 ) ;
}
if ( ! F_70 ( V_8 ) )
F_265 ( V_8 , V_58 , V_256 ) ;
return V_8 ;
V_283:
F_232 ( V_99 ) ;
return NULL ;
}
void F_270 ( struct V_16 * V_16 )
{
if ( F_196 ( V_16 ) )
return;
if ( V_16 -> V_272 && ! F_252 ( V_16 ) )
return;
F_266 ( V_16 , V_259 ) ;
}
void F_271 ( struct V_16 * V_16 )
{
F_77 ( F_196 ( V_16 ) ) ;
F_77 ( V_16 -> V_272 ) ;
F_266 ( V_16 , V_257 ) ;
}
void F_272 ( void )
{
V_146 -> V_279 . V_280 ++ ;
if ( V_146 -> V_279 . V_280 == 1 ) {
V_146 -> V_279 . V_107 = NULL ;
V_146 -> V_279 . V_58 = 0 ;
V_146 -> V_279 . V_282 = 0 ;
}
}
void F_273 ( void )
{
struct V_276 * V_246 = & V_146 -> V_279 ;
if ( ! V_246 -> V_280 )
return;
V_246 -> V_280 -- ;
if ( V_246 -> V_280 )
return;
if ( ! V_246 -> V_107 )
return;
if ( V_246 -> V_58 )
F_203 ( & V_246 -> V_107 -> V_36 ,
V_246 -> V_58 * V_215 ) ;
if ( V_246 -> V_282 )
F_203 ( & V_246 -> V_107 -> V_139 ,
V_246 -> V_282 * V_215 ) ;
F_182 ( V_246 -> V_107 ) ;
V_246 -> V_107 = NULL ;
}
void
F_274 ( struct V_16 * V_16 , T_5 V_254 , bool V_285 )
{
struct V_7 * V_107 ;
int V_256 = V_278 ;
if ( ! V_285 )
V_256 = V_284 ;
V_107 = F_266 ( V_16 , V_256 ) ;
if ( V_138 && V_285 && V_107 )
F_260 ( V_254 , F_68 ( & V_107 -> V_15 ) ) ;
}
void F_275 ( T_5 V_254 )
{
struct V_7 * V_107 ;
unsigned short V_253 ;
if ( ! V_138 )
return;
V_253 = F_260 ( V_254 , 0 ) ;
F_62 () ;
V_107 = F_224 ( V_253 ) ;
if ( V_107 ) {
if ( ! F_70 ( V_107 ) )
F_203 ( & V_107 -> V_139 , V_215 ) ;
F_35 ( V_107 , false ) ;
F_261 ( V_107 ) ;
}
F_64 () ;
}
static int F_276 ( T_5 V_286 ,
struct V_7 * V_103 , struct V_7 * V_3 , bool V_287 )
{
unsigned short V_288 , V_289 ;
V_288 = F_68 ( & V_103 -> V_15 ) ;
V_289 = F_68 ( & V_3 -> V_15 ) ;
if ( F_277 ( V_286 , V_288 , V_289 ) == V_288 ) {
F_35 ( V_103 , false ) ;
F_35 ( V_3 , true ) ;
F_269 ( V_3 ) ;
if ( V_287 ) {
if ( ! F_70 ( V_103 ) )
F_203 ( & V_103 -> V_139 , V_215 ) ;
F_261 ( V_103 ) ;
if ( ! F_70 ( V_3 ) )
F_203 ( & V_3 -> V_36 , V_215 ) ;
}
return 0 ;
}
return - V_266 ;
}
static inline int F_276 ( T_5 V_286 ,
struct V_7 * V_103 , struct V_7 * V_3 , bool V_287 )
{
return - V_266 ;
}
int F_278 ( struct V_16 * V_16 ,
struct V_16 * V_290 , struct V_7 * * V_274 , T_2 V_170 )
{
struct V_7 * V_8 = NULL ;
struct V_98 * V_99 ;
enum V_255 V_256 ;
int V_105 = 0 ;
* V_274 = NULL ;
F_77 ( F_193 ( V_16 ) ) ;
if ( F_74 () )
return 0 ;
V_99 = F_75 ( V_16 ) ;
F_228 ( V_99 ) ;
if ( F_84 ( V_99 ) ) {
V_8 = V_99 -> V_7 ;
F_155 ( & V_8 -> V_15 ) ;
if ( F_252 ( V_16 ) )
F_279 ( V_99 ) ;
}
F_232 ( V_99 ) ;
if ( ! V_8 )
return 0 ;
* V_274 = V_8 ;
V_105 = F_221 ( NULL , V_170 , 1 , V_274 , false ) ;
F_69 ( & V_8 -> V_15 ) ;
if ( V_105 || * V_274 == NULL ) {
if ( F_252 ( V_16 ) ) {
F_228 ( V_99 ) ;
F_280 ( V_99 ) ;
F_232 ( V_99 ) ;
F_270 ( V_16 ) ;
}
return - V_252 ;
}
V_99 = F_75 ( V_290 ) ;
if ( F_252 ( V_16 ) )
V_256 = V_259 ;
else if ( F_256 ( V_16 ) )
V_256 = V_257 ;
else
V_256 = V_258 ;
F_233 ( V_8 , V_16 , 1 , V_99 , V_256 ) ;
return V_105 ;
}
void F_281 ( struct V_7 * V_8 ,
struct V_16 * V_291 , struct V_16 * V_290 , bool V_292 )
{
struct V_16 * V_293 , * V_294 ;
struct V_98 * V_99 ;
if ( ! V_8 )
return;
F_259 ( & V_8 -> V_15 ) ;
if ( ! V_292 ) {
V_293 = V_291 ;
V_294 = V_290 ;
} else {
V_293 = V_290 ;
V_294 = V_291 ;
}
V_99 = F_75 ( V_291 ) ;
F_228 ( V_99 ) ;
F_280 ( V_99 ) ;
F_232 ( V_99 ) ;
F_266 ( V_294 , V_295 ) ;
if ( F_252 ( V_293 ) )
F_270 ( V_293 ) ;
F_262 ( & V_8 -> V_15 ) ;
}
int F_282 ( struct V_16 * V_16 ,
struct V_81 * V_82 ,
T_2 V_170 )
{
struct V_7 * V_8 ;
int V_105 ;
if ( F_74 () )
return 0 ;
V_105 = F_257 ( V_82 , V_16 , V_170 , & V_8 ) ;
if ( ! V_105 )
F_264 ( V_8 ) ;
return V_105 ;
}
static struct V_98 * F_283 ( struct V_16 * V_16 )
{
struct V_98 * V_99 ;
V_99 = F_75 ( V_16 ) ;
if ( F_95 ( V_99 ) && F_84 ( V_99 ) )
return V_99 ;
return NULL ;
}
bool F_284 ( struct V_16 * V_16 )
{
if ( F_74 () )
return false ;
return F_283 ( V_16 ) != NULL ;
}
void F_285 ( struct V_16 * V_16 )
{
struct V_98 * V_99 ;
V_99 = F_283 ( V_16 ) ;
if ( V_99 ) {
int V_105 = - 1 ;
char * V_296 ;
F_149 ( V_297 L_6 ,
V_99 , V_99 -> V_101 , V_99 -> V_7 ) ;
V_296 = F_286 ( V_153 , V_298 ) ;
if ( V_296 ) {
F_62 () ;
V_105 = F_148 ( V_99 -> V_7 -> V_15 . V_77 ,
V_296 , V_153 ) ;
F_64 () ;
}
F_149 ( V_155 L_7 ,
( V_105 < 0 ) ? L_8 : V_296 ) ;
F_287 ( V_296 ) ;
}
}
static int F_288 ( struct V_7 * V_107 ,
unsigned long long V_45 )
{
int V_299 ;
T_1 V_300 , V_301 ;
int V_105 = 0 ;
int V_302 = F_151 ( V_107 ) ;
T_1 V_303 , V_304 ;
int V_305 ;
V_299 = V_248 * V_302 ;
V_304 = F_150 ( & V_107 -> V_36 , V_156 ) ;
V_305 = 0 ;
while ( V_299 ) {
if ( F_289 ( V_146 ) ) {
V_105 = - V_306 ;
break;
}
F_185 ( & V_307 ) ;
V_300 = F_150 ( & V_107 -> V_139 , V_157 ) ;
if ( V_300 < V_45 ) {
V_105 = - V_266 ;
F_187 ( & V_307 ) ;
break;
}
V_301 = F_150 ( & V_107 -> V_36 , V_157 ) ;
if ( V_301 < V_45 )
V_305 = 1 ;
V_105 = F_290 ( & V_107 -> V_36 , V_45 ) ;
if ( ! V_105 ) {
if ( V_300 == V_45 )
V_107 -> V_181 = true ;
else
V_107 -> V_181 = false ;
}
F_187 ( & V_307 ) ;
if ( ! V_105 )
break;
F_170 ( V_107 , NULL , V_298 ,
V_177 ,
NULL ) ;
V_303 = F_150 ( & V_107 -> V_36 , V_156 ) ;
if ( V_303 >= V_304 )
V_299 -- ;
else
V_304 = V_303 ;
}
if ( ! V_105 && V_305 )
F_182 ( V_107 ) ;
return V_105 ;
}
static int F_291 ( struct V_7 * V_107 ,
unsigned long long V_45 )
{
int V_299 ;
T_1 V_301 , V_300 , V_304 , V_303 ;
int V_302 = F_151 ( V_107 ) ;
int V_105 = - V_136 ;
int V_305 = 0 ;
V_299 = V_302 * V_248 ;
V_304 = F_150 ( & V_107 -> V_139 , V_156 ) ;
while ( V_299 ) {
if ( F_289 ( V_146 ) ) {
V_105 = - V_306 ;
break;
}
F_185 ( & V_307 ) ;
V_301 = F_150 ( & V_107 -> V_36 , V_157 ) ;
if ( V_301 > V_45 ) {
V_105 = - V_266 ;
F_187 ( & V_307 ) ;
break;
}
V_300 = F_150 ( & V_107 -> V_139 , V_157 ) ;
if ( V_300 < V_45 )
V_305 = 1 ;
V_105 = F_290 ( & V_107 -> V_139 , V_45 ) ;
if ( ! V_105 ) {
if ( V_301 == V_45 )
V_107 -> V_181 = true ;
else
V_107 -> V_181 = false ;
}
F_187 ( & V_307 ) ;
if ( ! V_105 )
break;
F_170 ( V_107 , NULL , V_298 ,
V_175 |
V_177 ,
NULL ) ;
V_303 = F_150 ( & V_107 -> V_139 , V_156 ) ;
if ( V_303 >= V_304 )
V_299 -- ;
else
V_304 = V_303 ;
}
if ( ! V_105 && V_305 )
F_182 ( V_107 ) ;
return V_105 ;
}
unsigned long F_292 ( struct V_38 * V_38 , int V_126 ,
T_2 V_170 ,
unsigned long * V_172 )
{
unsigned long V_308 = 0 ;
struct V_6 * V_21 , * V_309 = NULL ;
unsigned long V_310 ;
int V_174 = 0 ;
struct V_17 * V_22 ;
unsigned long long V_35 ;
unsigned long V_180 ;
if ( V_126 > 0 )
return 0 ;
V_22 = F_9 ( F_110 ( V_38 ) , F_111 ( V_38 ) ) ;
do {
if ( V_309 )
V_21 = V_309 ;
else
V_21 = F_28 ( V_22 ) ;
if ( ! V_21 )
break;
V_180 = 0 ;
V_310 = F_170 ( V_21 -> V_8 , V_38 ,
V_170 ,
V_179 ,
& V_180 ) ;
V_308 += V_310 ;
* V_172 += V_180 ;
F_18 ( & V_22 -> V_34 ) ;
V_309 = NULL ;
if ( ! V_310 ) {
do {
V_309 =
F_25 ( V_22 ) ;
if ( V_309 == V_21 )
F_69 ( & V_309 -> V_8 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_15 ( V_21 -> V_8 , V_21 , V_22 ) ;
V_35 = F_22 ( & V_21 -> V_8 -> V_36 ) ;
F_11 ( V_21 -> V_8 , V_21 , V_22 , V_35 ) ;
F_19 ( & V_22 -> V_34 ) ;
F_69 ( & V_21 -> V_8 -> V_15 ) ;
V_174 ++ ;
if ( ! V_308 &&
( V_309 == NULL ||
V_174 > V_311 ) )
break;
} while ( ! V_308 );
if ( V_309 )
F_69 ( & V_309 -> V_8 -> V_15 ) ;
return V_308 ;
}
static int F_293 ( struct V_7 * V_8 ,
int V_37 , int V_10 , enum V_64 V_97 )
{
struct V_38 * V_38 ;
struct V_6 * V_21 ;
struct V_98 * V_99 , * V_312 ;
unsigned long V_101 , V_174 ;
struct V_123 * V_313 ;
int V_105 = 0 ;
V_38 = & F_294 ( V_37 ) -> V_314 [ V_10 ] ;
V_21 = F_4 ( V_8 , V_37 , V_10 ) ;
V_313 = & V_21 -> V_100 [ V_97 ] ;
V_174 = F_46 ( V_21 , V_97 ) ;
V_174 += 256 ;
V_312 = NULL ;
while ( V_174 -- ) {
struct V_16 * V_16 ;
V_105 = 0 ;
F_97 ( & V_38 -> V_102 , V_101 ) ;
if ( F_79 ( V_313 ) ) {
F_98 ( & V_38 -> V_102 , V_101 ) ;
break;
}
V_99 = F_295 ( V_313 -> V_315 , struct V_98 , V_97 ) ;
if ( V_312 == V_99 ) {
F_88 ( & V_99 -> V_97 , V_313 ) ;
V_312 = NULL ;
F_98 ( & V_38 -> V_102 , V_101 ) ;
continue;
}
F_98 ( & V_38 -> V_102 , V_101 ) ;
V_16 = F_127 ( V_99 ) ;
V_105 = F_243 ( V_16 , V_99 , V_8 , V_298 ) ;
if ( V_105 == - V_252 )
break;
if ( V_105 == - V_136 || V_105 == - V_266 ) {
V_312 = V_99 ;
F_296 () ;
} else
V_312 = NULL ;
}
if ( ! V_105 && ! F_79 ( V_313 ) )
return - V_136 ;
return V_105 ;
}
static int F_297 ( struct V_7 * V_8 , bool V_316 )
{
int V_105 ;
int V_37 , V_10 , V_176 ;
int V_317 = V_248 ;
struct V_77 * V_140 = V_8 -> V_15 . V_77 ;
F_155 ( & V_8 -> V_15 ) ;
V_176 = 0 ;
if ( V_316 )
goto V_318;
V_319:
do {
V_105 = - V_136 ;
if ( F_298 ( V_140 ) || ! F_79 ( & V_140 -> V_302 ) )
goto V_94;
V_105 = - V_306 ;
if ( F_289 ( V_146 ) )
goto V_94;
F_299 () ;
F_212 () ;
V_105 = 0 ;
F_135 ( V_8 ) ;
F_24 (node, N_HIGH_MEMORY) {
for ( V_10 = 0 ; ! V_105 && V_10 < V_39 ; V_10 ++ ) {
enum V_64 V_119 ;
F_119 (l) {
V_105 = F_293 ( V_8 ,
V_37 , V_10 , V_119 ) ;
if ( V_105 )
break;
}
}
if ( V_105 )
break;
}
F_137 ( V_8 ) ;
F_182 ( V_8 ) ;
if ( V_105 == - V_252 )
goto V_318;
F_296 () ;
} while ( V_8 -> V_36 . V_320 > 0 || V_105 );
V_94:
F_69 ( & V_8 -> V_15 ) ;
return V_105 ;
V_318:
if ( F_298 ( V_140 ) || ! F_79 ( & V_140 -> V_302 ) || V_176 ) {
V_105 = - V_136 ;
goto V_94;
}
F_299 () ;
V_176 = 1 ;
while ( V_317 && V_8 -> V_36 . V_320 > 0 ) {
int V_321 ;
if ( F_289 ( V_146 ) ) {
V_105 = - V_306 ;
goto V_94;
}
V_321 = F_173 ( V_8 , V_298 ,
false , F_134 ( V_8 ) ) ;
if ( ! V_321 ) {
V_317 -- ;
F_300 ( V_322 , V_323 / 10 ) ;
}
}
F_301 () ;
goto V_319;
}
int F_302 ( struct V_77 * V_78 , unsigned int V_324 )
{
return F_297 ( F_57 ( V_78 ) , true ) ;
}
static T_1 F_303 ( struct V_77 * V_78 , struct V_325 * V_326 )
{
return F_57 ( V_78 ) -> V_86 ;
}
static int F_304 ( struct V_77 * V_78 , struct V_325 * V_326 ,
T_1 V_45 )
{
int V_327 = 0 ;
struct V_7 * V_8 = F_57 ( V_78 ) ;
struct V_77 * V_27 = V_78 -> V_27 ;
struct V_7 * V_328 = NULL ;
if ( V_27 )
V_328 = F_57 ( V_27 ) ;
F_305 () ;
if ( ( ! V_328 || ! V_328 -> V_86 ) &&
( V_45 == 1 || V_45 == 0 ) ) {
if ( F_79 ( & V_78 -> V_302 ) )
V_8 -> V_86 = V_45 ;
else
V_327 = - V_136 ;
} else
V_327 = - V_266 ;
F_306 () ;
return V_327 ;
}
static unsigned long F_307 ( struct V_7 * V_8 ,
enum V_43 V_44 )
{
struct V_7 * V_88 ;
long V_45 = 0 ;
F_152 (iter, mem)
V_45 += F_29 ( V_88 , V_44 ) ;
if ( V_45 < 0 )
V_45 = 0 ;
return V_45 ;
}
static inline T_1 F_308 ( struct V_7 * V_8 , bool V_329 )
{
T_1 V_45 ;
if ( ! F_70 ( V_8 ) ) {
if ( ! V_329 )
return F_150 ( & V_8 -> V_36 , V_156 ) ;
else
return F_150 ( & V_8 -> V_139 , V_156 ) ;
}
V_45 = F_307 ( V_8 , V_59 ) ;
V_45 += F_307 ( V_8 , V_60 ) ;
if ( V_329 )
V_45 += F_307 ( V_8 , V_52 ) ;
return V_45 << V_115 ;
}
static T_1 F_309 ( struct V_77 * V_78 , struct V_325 * V_326 )
{
struct V_7 * V_8 = F_57 ( V_78 ) ;
T_1 V_45 ;
int type , V_330 ;
type = F_310 ( V_326 -> V_198 ) ;
V_330 = F_311 ( V_326 -> V_198 ) ;
switch ( type ) {
case V_331 :
if ( V_330 == V_156 )
V_45 = F_308 ( V_8 , false ) ;
else
V_45 = F_150 ( & V_8 -> V_36 , V_330 ) ;
break;
case V_332 :
if ( V_330 == V_156 )
V_45 = F_308 ( V_8 , true ) ;
else
V_45 = F_150 ( & V_8 -> V_139 , V_330 ) ;
break;
default:
F_72 () ;
break;
}
return V_45 ;
}
static int F_312 ( struct V_77 * V_78 , struct V_325 * V_326 ,
const char * V_333 )
{
struct V_7 * V_107 = F_57 ( V_78 ) ;
int type , V_330 ;
unsigned long long V_45 ;
int V_105 ;
type = F_310 ( V_326 -> V_198 ) ;
V_330 = F_311 ( V_326 -> V_198 ) ;
switch ( V_330 ) {
case V_157 :
if ( F_70 ( V_107 ) ) {
V_105 = - V_266 ;
break;
}
V_105 = F_313 ( V_333 , & V_45 ) ;
if ( V_105 )
break;
if ( type == V_331 )
V_105 = F_288 ( V_107 , V_45 ) ;
else
V_105 = F_291 ( V_107 , V_45 ) ;
break;
case V_334 :
V_105 = F_313 ( V_333 , & V_45 ) ;
if ( V_105 )
break;
if ( type == V_331 )
V_105 = F_314 ( & V_107 -> V_36 , V_45 ) ;
else
V_105 = - V_266 ;
break;
default:
V_105 = - V_266 ;
break;
}
return V_105 ;
}
static void F_315 ( struct V_7 * V_107 ,
unsigned long long * V_335 , unsigned long long * V_336 )
{
struct V_77 * V_77 ;
unsigned long long V_337 , V_338 , V_134 ;
V_337 = F_150 ( & V_107 -> V_36 , V_157 ) ;
V_338 = F_150 ( & V_107 -> V_139 , V_157 ) ;
V_77 = V_107 -> V_15 . V_77 ;
if ( ! V_107 -> V_86 )
goto V_94;
while ( V_77 -> V_27 ) {
V_77 = V_77 -> V_27 ;
V_107 = F_57 ( V_77 ) ;
if ( ! V_107 -> V_86 )
break;
V_134 = F_150 ( & V_107 -> V_36 , V_157 ) ;
V_337 = F_133 ( V_337 , V_134 ) ;
V_134 = F_150 ( & V_107 -> V_139 , V_157 ) ;
V_338 = F_133 ( V_338 , V_134 ) ;
}
V_94:
* V_335 = V_337 ;
* V_336 = V_338 ;
return;
}
static int F_316 ( struct V_77 * V_78 , unsigned int V_324 )
{
struct V_7 * V_8 ;
int type , V_330 ;
V_8 = F_57 ( V_78 ) ;
type = F_310 ( V_324 ) ;
V_330 = F_311 ( V_324 ) ;
switch ( V_330 ) {
case V_339 :
if ( type == V_331 )
F_317 ( & V_8 -> V_36 ) ;
else
F_317 ( & V_8 -> V_139 ) ;
break;
case V_158 :
if ( type == V_331 )
F_318 ( & V_8 -> V_36 ) ;
else
F_318 ( & V_8 -> V_139 ) ;
break;
}
return 0 ;
}
static T_1 F_319 ( struct V_77 * V_140 ,
struct V_325 * V_326 )
{
return F_57 ( V_140 ) -> V_4 ;
}
static int F_320 ( struct V_77 * V_140 ,
struct V_325 * V_326 , T_1 V_45 )
{
struct V_7 * V_8 = F_57 ( V_140 ) ;
if ( V_45 >= ( 1 << V_340 ) )
return - V_266 ;
F_305 () ;
V_8 -> V_4 = V_45 ;
F_306 () ;
return 0 ;
}
static int F_320 ( struct V_77 * V_140 ,
struct V_325 * V_326 , T_1 V_45 )
{
return - V_341 ;
}
static void
F_321 ( struct V_7 * V_8 , struct V_342 * V_343 )
{
T_6 V_45 ;
V_45 = F_29 ( V_8 , V_59 ) ;
V_343 -> V_47 [ V_344 ] += V_45 * V_215 ;
V_45 = F_29 ( V_8 , V_60 ) ;
V_343 -> V_47 [ V_345 ] += V_45 * V_215 ;
V_45 = F_29 ( V_8 , V_208 ) ;
V_343 -> V_47 [ V_346 ] += V_45 * V_215 ;
V_45 = F_39 ( V_8 , V_61 ) ;
V_343 -> V_47 [ V_347 ] += V_45 ;
V_45 = F_39 ( V_8 , V_62 ) ;
V_343 -> V_47 [ V_348 ] += V_45 ;
if ( V_138 ) {
V_45 = F_29 ( V_8 , V_52 ) ;
V_343 -> V_47 [ V_349 ] += V_45 * V_215 ;
}
V_45 = F_39 ( V_8 , V_54 ) ;
V_343 -> V_47 [ V_350 ] += V_45 ;
V_45 = F_39 ( V_8 , V_55 ) ;
V_343 -> V_47 [ V_351 ] += V_45 ;
V_45 = F_47 ( V_8 , V_113 ) ;
V_343 -> V_47 [ V_352 ] += V_45 * V_215 ;
V_45 = F_47 ( V_8 , V_114 ) ;
V_343 -> V_47 [ V_353 ] += V_45 * V_215 ;
V_45 = F_47 ( V_8 , V_116 ) ;
V_343 -> V_47 [ V_354 ] += V_45 * V_215 ;
V_45 = F_47 ( V_8 , V_117 ) ;
V_343 -> V_47 [ V_355 ] += V_45 * V_215 ;
V_45 = F_47 ( V_8 , V_118 ) ;
V_343 -> V_47 [ V_356 ] += V_45 * V_215 ;
}
static void
F_322 ( struct V_7 * V_8 , struct V_342 * V_343 )
{
struct V_7 * V_88 ;
F_152 (iter, mem)
F_321 ( V_88 , V_343 ) ;
}
static int F_323 ( struct V_357 * V_358 , void * V_187 )
{
int V_9 ;
unsigned long V_359 , V_360 , V_361 , V_362 ;
unsigned long V_363 ;
struct V_77 * V_78 = V_358 -> V_198 ;
struct V_7 * V_129 = F_57 ( V_78 ) ;
V_359 = F_120 ( V_129 ) ;
F_324 ( V_358 , L_9 , V_359 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_363 = F_118 ( V_129 , V_9 ) ;
F_324 ( V_358 , L_10 , V_9 , V_363 ) ;
}
F_325 ( V_358 , '\n' ) ;
V_360 = F_114 ( V_129 ) ;
F_324 ( V_358 , L_11 , V_360 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_363 = F_112 ( V_129 , V_9 ) ;
F_324 ( V_358 , L_10 , V_9 , V_363 ) ;
}
F_325 ( V_358 , '\n' ) ;
V_361 = F_115 ( V_129 ) ;
F_324 ( V_358 , L_12 , V_361 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_363 = F_113 ( V_129 , V_9 ) ;
F_324 ( V_358 , L_10 , V_9 , V_363 ) ;
}
F_325 ( V_358 , '\n' ) ;
V_362 = F_117 ( V_129 ) ;
F_324 ( V_358 , L_13 , V_362 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_363 = F_116 ( V_129 ,
V_9 ) ;
F_324 ( V_358 , L_10 , V_9 , V_363 ) ;
}
F_325 ( V_358 , '\n' ) ;
return 0 ;
}
static int F_326 ( struct V_77 * V_78 , struct V_325 * V_326 ,
struct V_364 * V_365 )
{
struct V_7 * V_129 = F_57 ( V_78 ) ;
struct V_342 V_366 ;
int V_222 ;
memset ( & V_366 , 0 , sizeof( V_366 ) ) ;
F_321 ( V_129 , & V_366 ) ;
for ( V_222 = 0 ; V_222 < V_367 ; V_222 ++ ) {
if ( V_222 == V_349 && ! V_138 )
continue;
V_365 -> V_368 ( V_365 , V_369 [ V_222 ] . V_370 , V_366 . V_47 [ V_222 ] ) ;
}
{
unsigned long long V_160 , V_336 ;
F_315 ( V_129 , & V_160 , & V_336 ) ;
V_365 -> V_368 ( V_365 , L_14 , V_160 ) ;
if ( V_138 )
V_365 -> V_368 ( V_365 , L_15 , V_336 ) ;
}
memset ( & V_366 , 0 , sizeof( V_366 ) ) ;
F_322 ( V_129 , & V_366 ) ;
for ( V_222 = 0 ; V_222 < V_367 ; V_222 ++ ) {
if ( V_222 == V_349 && ! V_138 )
continue;
V_365 -> V_368 ( V_365 , V_369 [ V_222 ] . V_371 , V_366 . V_47 [ V_222 ] ) ;
}
#ifdef F_327
V_365 -> V_368 ( V_365 , L_16 , F_105 ( V_129 , NULL ) ) ;
{
int V_9 , V_10 ;
struct V_6 * V_21 ;
unsigned long V_372 [ 2 ] = { 0 , 0 } ;
unsigned long V_373 [ 2 ] = { 0 , 0 } ;
F_48 (nid)
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ ) {
V_21 = F_4 ( V_129 , V_9 , V_10 ) ;
V_372 [ 0 ] +=
V_21 -> V_121 . V_372 [ 0 ] ;
V_372 [ 1 ] +=
V_21 -> V_121 . V_372 [ 1 ] ;
V_373 [ 0 ] +=
V_21 -> V_121 . V_373 [ 0 ] ;
V_373 [ 1 ] +=
V_21 -> V_121 . V_373 [ 1 ] ;
}
V_365 -> V_368 ( V_365 , L_17 , V_372 [ 0 ] ) ;
V_365 -> V_368 ( V_365 , L_18 , V_372 [ 1 ] ) ;
V_365 -> V_368 ( V_365 , L_19 , V_373 [ 0 ] ) ;
V_365 -> V_368 ( V_365 , L_20 , V_373 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_328 ( struct V_77 * V_140 , struct V_325 * V_326 )
{
struct V_7 * V_107 = F_57 ( V_140 ) ;
return F_134 ( V_107 ) ;
}
static int F_329 ( struct V_77 * V_140 , struct V_325 * V_326 ,
T_1 V_45 )
{
struct V_7 * V_107 = F_57 ( V_140 ) ;
struct V_7 * V_27 ;
if ( V_45 > 100 )
return - V_266 ;
if ( V_140 -> V_27 == NULL )
return - V_266 ;
V_27 = F_57 ( V_140 -> V_27 ) ;
F_305 () ;
if ( ( V_27 -> V_86 ) ||
( V_107 -> V_86 && ! F_79 ( & V_140 -> V_302 ) ) ) {
F_306 () ;
return - V_266 ;
}
V_107 -> V_142 = V_45 ;
F_306 () ;
return 0 ;
}
static void F_330 ( struct V_7 * V_107 , bool V_329 )
{
struct V_374 * V_375 ;
T_1 V_320 ;
int V_222 ;
F_62 () ;
if ( ! V_329 )
V_375 = F_63 ( V_107 -> V_376 . V_377 ) ;
else
V_375 = F_63 ( V_107 -> V_378 . V_377 ) ;
if ( ! V_375 )
goto V_144;
V_320 = F_308 ( V_107 , V_329 ) ;
V_222 = V_375 -> V_379 ;
for (; V_222 >= 0 && F_54 ( V_375 -> V_380 [ V_222 ] . V_381 > V_320 ) ; V_222 -- )
F_331 ( V_375 -> V_380 [ V_222 ] . V_382 , 1 ) ;
V_222 ++ ;
for (; V_222 < V_375 -> V_383 && F_54 ( V_375 -> V_380 [ V_222 ] . V_381 <= V_320 ) ; V_222 ++ )
F_331 ( V_375 -> V_380 [ V_222 ] . V_382 , 1 ) ;
V_375 -> V_379 = V_222 - 1 ;
V_144:
F_64 () ;
}
static void F_55 ( struct V_7 * V_107 )
{
while ( V_107 ) {
F_330 ( V_107 , false ) ;
if ( V_138 )
F_330 ( V_107 , true ) ;
V_107 = F_21 ( V_107 ) ;
}
}
static int F_332 ( const void * V_384 , const void * V_385 )
{
const struct F_55 * V_386 = V_384 ;
const struct F_55 * V_387 = V_385 ;
return V_386 -> V_381 - V_387 -> V_381 ;
}
static int F_333 ( struct V_7 * V_8 )
{
struct V_388 * V_389 ;
F_334 (ev, &mem->oom_notify, list)
F_331 ( V_389 -> V_382 , 1 ) ;
return 0 ;
}
static void F_186 ( struct V_7 * V_8 )
{
struct V_7 * V_88 ;
F_152 (iter, mem)
F_333 ( V_88 ) ;
}
static int F_335 ( struct V_77 * V_140 ,
struct V_325 * V_326 , struct V_390 * V_382 , const char * args )
{
struct V_7 * V_107 = F_57 ( V_140 ) ;
struct V_391 * V_376 ;
struct V_374 * V_392 ;
int type = F_310 ( V_326 -> V_198 ) ;
T_1 V_381 , V_320 ;
int V_222 , V_383 , V_105 ;
V_105 = F_313 ( args , & V_381 ) ;
if ( V_105 )
return V_105 ;
F_185 ( & V_107 -> V_393 ) ;
if ( type == V_331 )
V_376 = & V_107 -> V_376 ;
else if ( type == V_332 )
V_376 = & V_107 -> V_378 ;
else
F_72 () ;
V_320 = F_308 ( V_107 , type == V_332 ) ;
if ( V_376 -> V_377 )
F_330 ( V_107 , type == V_332 ) ;
V_383 = V_376 -> V_377 ? V_376 -> V_377 -> V_383 + 1 : 1 ;
V_392 = F_286 ( sizeof( * V_392 ) + V_383 * sizeof( struct F_55 ) ,
V_298 ) ;
if ( ! V_392 ) {
V_105 = - V_252 ;
goto V_144;
}
V_392 -> V_383 = V_383 ;
if ( V_376 -> V_377 ) {
memcpy ( V_392 -> V_380 , V_376 -> V_377 -> V_380 , ( V_383 - 1 ) *
sizeof( struct F_55 ) ) ;
}
V_392 -> V_380 [ V_383 - 1 ] . V_382 = V_382 ;
V_392 -> V_380 [ V_383 - 1 ] . V_381 = V_381 ;
F_336 ( V_392 -> V_380 , V_383 , sizeof( struct F_55 ) ,
F_332 , NULL ) ;
V_392 -> V_379 = - 1 ;
for ( V_222 = 0 ; V_222 < V_383 ; V_222 ++ ) {
if ( V_392 -> V_380 [ V_222 ] . V_381 < V_320 ) {
++ V_392 -> V_379 ;
}
}
F_287 ( V_376 -> V_394 ) ;
V_376 -> V_394 = V_376 -> V_377 ;
F_337 ( V_376 -> V_377 , V_392 ) ;
F_136 () ;
V_144:
F_187 ( & V_107 -> V_393 ) ;
return V_105 ;
}
static void F_338 ( struct V_77 * V_140 ,
struct V_325 * V_326 , struct V_390 * V_382 )
{
struct V_7 * V_107 = F_57 ( V_140 ) ;
struct V_391 * V_376 ;
struct V_374 * V_392 ;
int type = F_310 ( V_326 -> V_198 ) ;
T_1 V_320 ;
int V_222 , V_395 , V_383 ;
F_185 ( & V_107 -> V_393 ) ;
if ( type == V_331 )
V_376 = & V_107 -> V_376 ;
else if ( type == V_332 )
V_376 = & V_107 -> V_378 ;
else
F_72 () ;
F_125 ( ! V_376 ) ;
V_320 = F_308 ( V_107 , type == V_332 ) ;
F_330 ( V_107 , type == V_332 ) ;
V_383 = 0 ;
for ( V_222 = 0 ; V_222 < V_376 -> V_377 -> V_383 ; V_222 ++ ) {
if ( V_376 -> V_377 -> V_380 [ V_222 ] . V_382 != V_382 )
V_383 ++ ;
}
V_392 = V_376 -> V_394 ;
if ( ! V_383 ) {
F_287 ( V_392 ) ;
V_392 = NULL ;
goto V_396;
}
V_392 -> V_383 = V_383 ;
V_392 -> V_379 = - 1 ;
for ( V_222 = 0 , V_395 = 0 ; V_222 < V_376 -> V_377 -> V_383 ; V_222 ++ ) {
if ( V_376 -> V_377 -> V_380 [ V_222 ] . V_382 == V_382 )
continue;
V_392 -> V_380 [ V_395 ] = V_376 -> V_377 -> V_380 [ V_222 ] ;
if ( V_392 -> V_380 [ V_395 ] . V_381 < V_320 ) {
++ V_392 -> V_379 ;
}
V_395 ++ ;
}
V_396:
V_376 -> V_394 = V_376 -> V_377 ;
F_337 ( V_376 -> V_377 , V_392 ) ;
F_136 () ;
F_187 ( & V_107 -> V_393 ) ;
}
static int F_339 ( struct V_77 * V_140 ,
struct V_325 * V_326 , struct V_390 * V_382 , const char * args )
{
struct V_7 * V_107 = F_57 ( V_140 ) ;
struct V_388 * V_324 ;
int type = F_310 ( V_326 -> V_198 ) ;
F_125 ( type != V_397 ) ;
V_324 = F_286 ( sizeof( * V_324 ) , V_298 ) ;
if ( ! V_324 )
return - V_252 ;
F_185 ( & V_200 ) ;
V_324 -> V_382 = V_382 ;
F_92 ( & V_324 -> V_313 , & V_107 -> V_398 ) ;
if ( F_158 ( & V_107 -> V_185 ) )
F_331 ( V_382 , 1 ) ;
F_187 ( & V_200 ) ;
return 0 ;
}
static void F_340 ( struct V_77 * V_140 ,
struct V_325 * V_326 , struct V_390 * V_382 )
{
struct V_7 * V_8 = F_57 ( V_140 ) ;
struct V_388 * V_389 , * V_134 ;
int type = F_310 ( V_326 -> V_198 ) ;
F_125 ( type != V_397 ) ;
F_185 ( & V_200 ) ;
F_341 (ev, tmp, &mem->oom_notify, list) {
if ( V_389 -> V_382 == V_382 ) {
F_342 ( & V_389 -> V_313 ) ;
F_287 ( V_389 ) ;
}
}
F_187 ( & V_200 ) ;
}
static int F_343 ( struct V_77 * V_140 ,
struct V_325 * V_326 , struct V_364 * V_365 )
{
struct V_7 * V_8 = F_57 ( V_140 ) ;
V_365 -> V_368 ( V_365 , L_21 , V_8 -> V_202 ) ;
if ( F_158 ( & V_8 -> V_185 ) )
V_365 -> V_368 ( V_365 , L_22 , 1 ) ;
else
V_365 -> V_368 ( V_365 , L_22 , 0 ) ;
return 0 ;
}
static int F_344 ( struct V_77 * V_140 ,
struct V_325 * V_326 , T_1 V_45 )
{
struct V_7 * V_8 = F_57 ( V_140 ) ;
struct V_7 * V_27 ;
if ( ! V_140 -> V_27 || ! ( ( V_45 == 0 ) || ( V_45 == 1 ) ) )
return - V_266 ;
V_27 = F_57 ( V_140 -> V_27 ) ;
F_305 () ;
if ( ( V_27 -> V_86 ) ||
( V_8 -> V_86 && ! F_79 ( & V_140 -> V_302 ) ) ) {
F_306 () ;
return - V_266 ;
}
V_8 -> V_202 = V_45 ;
if ( ! V_45 )
F_182 ( V_8 ) ;
F_306 () ;
return 0 ;
}
static int F_345 ( struct V_399 * V_294 , struct V_57 * V_57 )
{
struct V_77 * V_78 = V_57 -> V_400 -> V_401 -> V_402 ;
V_57 -> V_403 = & V_404 ;
return F_346 ( V_57 , F_323 , V_78 ) ;
}
static int F_347 ( struct V_77 * V_78 , struct V_405 * V_406 )
{
if ( ! V_138 )
return 0 ;
return F_348 ( V_78 , V_406 , V_407 ,
F_349 ( V_407 ) ) ;
}
static int F_347 ( struct V_77 * V_78 , struct V_405 * V_406 )
{
return 0 ;
}
static int F_350 ( struct V_7 * V_8 , int V_37 )
{
struct V_408 * V_409 ;
struct V_6 * V_21 ;
enum V_64 V_119 ;
int V_38 , V_134 = V_37 ;
if ( ! F_351 ( V_37 , V_410 ) )
V_134 = - 1 ;
V_409 = F_352 ( sizeof( * V_409 ) , V_298 , V_134 ) ;
if ( ! V_409 )
return 1 ;
V_8 -> V_11 . V_12 [ V_37 ] = V_409 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_21 = & V_409 -> V_13 [ V_38 ] ;
F_119 (l)
F_184 ( & V_21 -> V_100 [ V_119 ] ) ;
V_21 -> V_30 = 0 ;
V_21 -> V_29 = false ;
V_21 -> V_8 = V_8 ;
}
return 0 ;
}
static void F_353 ( struct V_7 * V_8 , int V_37 )
{
F_287 ( V_8 -> V_11 . V_12 [ V_37 ] ) ;
}
static struct V_7 * F_354 ( void )
{
struct V_7 * V_8 ;
int V_383 = sizeof( struct V_7 ) ;
if ( V_383 < V_215 )
V_8 = F_355 ( V_383 , V_298 ) ;
else
V_8 = F_356 ( V_383 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_47 = F_357 ( struct V_411 ) ;
if ( ! V_8 -> V_47 )
goto V_412;
F_358 ( & V_8 -> V_49 ) ;
return V_8 ;
V_412:
if ( V_383 < V_215 )
F_287 ( V_8 ) ;
else
F_359 ( V_8 ) ;
return NULL ;
}
static void F_360 ( struct V_7 * V_8 )
{
int V_37 ;
F_23 ( V_8 ) ;
F_361 ( & V_87 , & V_8 -> V_15 ) ;
F_24 (node, N_POSSIBLE)
F_353 ( V_8 , V_37 ) ;
F_362 ( V_8 -> V_47 ) ;
if ( sizeof( struct V_7 ) < V_215 )
F_287 ( V_8 ) ;
else
F_359 ( V_8 ) ;
}
static void F_269 ( struct V_7 * V_8 )
{
F_56 ( & V_8 -> V_413 ) ;
}
static void F_363 ( struct V_7 * V_8 , int V_48 )
{
if ( F_364 ( V_48 , & V_8 -> V_413 ) ) {
struct V_7 * V_27 = F_21 ( V_8 ) ;
F_360 ( V_8 ) ;
if ( V_27 )
F_261 ( V_27 ) ;
}
}
static void F_261 ( struct V_7 * V_8 )
{
F_363 ( V_8 , 1 ) ;
}
static struct V_7 * F_21 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_36 . V_27 )
return NULL ;
return F_220 ( V_8 -> V_36 . V_27 , V_36 ) ;
}
static void T_7 F_365 ( void )
{
if ( ! F_74 () && V_414 )
V_138 = 1 ;
}
static void T_7 F_365 ( void )
{
}
static int F_366 ( void )
{
struct V_415 * V_416 ;
struct V_17 * V_417 ;
int V_134 , V_37 , V_38 ;
F_24 (node, N_POSSIBLE) {
V_134 = V_37 ;
if ( ! F_351 ( V_37 , V_410 ) )
V_134 = - 1 ;
V_416 = F_352 ( sizeof( * V_416 ) , V_298 , V_134 ) ;
if ( ! V_416 )
return 1 ;
V_18 . V_19 [ V_37 ] = V_416 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_417 = & V_416 -> V_20 [ V_38 ] ;
V_417 -> V_26 = V_418 ;
F_358 ( & V_417 -> V_34 ) ;
}
}
return 0 ;
}
static struct V_14 * T_8
F_367 ( struct V_405 * V_406 , struct V_77 * V_78 )
{
struct V_7 * V_8 , * V_27 ;
long error = - V_252 ;
int V_37 ;
V_8 = F_354 () ;
if ( ! V_8 )
return F_368 ( error ) ;
F_24 (node, N_POSSIBLE)
if ( F_350 ( V_8 , V_37 ) )
goto V_419;
if ( V_78 -> V_27 == NULL ) {
int V_46 ;
F_365 () ;
V_27 = NULL ;
V_85 = V_8 ;
if ( F_366 () )
goto V_419;
F_369 (cpu) {
struct V_209 * V_210 =
& F_32 ( V_211 , V_46 ) ;
F_370 ( & V_210 -> V_221 , F_204 ) ;
}
F_371 ( F_216 , 0 ) ;
} else {
V_27 = F_57 ( V_78 -> V_27 ) ;
V_8 -> V_86 = V_27 -> V_86 ;
V_8 -> V_202 = V_27 -> V_202 ;
}
if ( V_27 && V_27 -> V_86 ) {
F_372 ( & V_8 -> V_36 , & V_27 -> V_36 ) ;
F_372 ( & V_8 -> V_139 , & V_27 -> V_139 ) ;
F_269 ( V_27 ) ;
} else {
F_372 ( & V_8 -> V_36 , NULL ) ;
F_372 ( & V_8 -> V_139 , NULL ) ;
}
V_8 -> V_163 = 0 ;
V_8 -> V_169 = V_75 ;
F_184 ( & V_8 -> V_398 ) ;
if ( V_27 )
V_8 -> V_142 = F_134 ( V_27 ) ;
F_162 ( & V_8 -> V_413 , 1 ) ;
V_8 -> V_4 = 0 ;
F_373 ( & V_8 -> V_393 ) ;
return & V_8 -> V_15 ;
V_419:
F_360 ( V_8 ) ;
V_85 = NULL ;
return F_368 ( error ) ;
}
static int F_374 ( struct V_405 * V_406 ,
struct V_77 * V_78 )
{
struct V_7 * V_8 = F_57 ( V_78 ) ;
return F_297 ( V_8 , false ) ;
}
static void F_375 ( struct V_405 * V_406 ,
struct V_77 * V_78 )
{
struct V_7 * V_8 = F_57 ( V_78 ) ;
F_261 ( V_8 ) ;
}
static int F_376 ( struct V_405 * V_406 ,
struct V_77 * V_78 )
{
int V_105 ;
V_105 = F_348 ( V_78 , V_406 , V_420 ,
F_349 ( V_420 ) ) ;
if ( ! V_105 )
V_105 = F_347 ( V_78 , V_406 ) ;
return V_105 ;
}
static int F_377 ( unsigned long V_48 )
{
int V_105 = 0 ;
int V_421 = V_422 ;
struct V_7 * V_8 = V_2 . V_3 ;
if ( F_70 ( V_8 ) ) {
V_2 . V_423 += V_48 ;
return V_105 ;
}
if ( V_48 > 1 ) {
struct V_236 * V_217 ;
if ( F_219 ( & V_8 -> V_36 , V_215 * V_48 , & V_217 ) )
goto V_424;
if ( V_138 && F_219 ( & V_8 -> V_139 ,
V_215 * V_48 , & V_217 ) ) {
F_203 ( & V_8 -> V_36 , V_215 * V_48 ) ;
goto V_424;
}
V_2 . V_423 += V_48 ;
return V_105 ;
}
V_424:
while ( V_48 -- ) {
if ( F_289 ( V_146 ) ) {
V_105 = - V_306 ;
break;
}
if ( ! V_421 -- ) {
V_421 = V_422 ;
F_296 () ;
}
V_105 = F_221 ( NULL , V_298 , 1 , & V_8 , false ) ;
if ( V_105 || ! V_8 )
return - V_252 ;
V_2 . V_423 ++ ;
}
return V_105 ;
}
static struct V_16 * F_378 ( struct V_425 * V_426 ,
unsigned long V_427 , T_9 V_428 )
{
struct V_16 * V_16 = F_379 ( V_426 , V_427 , V_428 ) ;
if ( ! V_16 || ! F_196 ( V_16 ) )
return NULL ;
if ( F_252 ( V_16 ) ) {
if ( ! F_1 () || F_380 ( V_16 ) > 2 )
return NULL ;
} else if ( ! F_3 () )
return NULL ;
if ( ! F_244 ( V_16 ) )
return NULL ;
return V_16 ;
}
static struct V_16 * F_381 ( struct V_425 * V_426 ,
unsigned long V_427 , T_9 V_428 , T_5 * V_286 )
{
int V_429 ;
struct V_16 * V_16 = NULL ;
T_5 V_254 = F_382 ( V_428 ) ;
if ( ! F_1 () || F_383 ( V_254 ) )
return NULL ;
V_429 = F_384 ( V_254 , & V_16 ) ;
if ( V_429 > 1 ) {
if ( V_16 )
F_249 ( V_16 ) ;
return NULL ;
}
if ( V_138 )
V_286 -> V_45 = V_254 . V_45 ;
return V_16 ;
}
static struct V_16 * F_385 ( struct V_425 * V_426 ,
unsigned long V_427 , T_9 V_428 , T_5 * V_286 )
{
struct V_16 * V_16 = NULL ;
struct V_399 * V_399 ;
struct V_430 * V_272 ;
T_10 V_431 ;
if ( ! V_426 -> V_432 )
return NULL ;
if ( ! F_3 () )
return NULL ;
V_399 = V_426 -> V_432 -> V_433 . V_434 -> V_435 ;
V_272 = V_426 -> V_432 -> V_436 ;
if ( F_386 ( V_428 ) )
V_431 = F_387 ( V_426 , V_427 ) ;
else
V_431 = F_388 ( V_428 ) ;
if ( ! F_389 ( V_272 ) ) {
V_16 = F_390 ( V_272 , V_431 ) ;
} else {
T_5 V_254 ;
F_391 ( V_399 , V_431 , & V_16 , & V_254 ) ;
if ( V_138 )
V_286 -> V_45 = V_254 . V_45 ;
}
return V_16 ;
}
static int F_392 ( struct V_425 * V_426 ,
unsigned long V_427 , T_9 V_428 , union V_437 * V_66 )
{
struct V_16 * V_16 = NULL ;
struct V_98 * V_99 ;
int V_105 = 0 ;
T_5 V_254 = { . V_45 = 0 } ;
if ( F_393 ( V_428 ) )
V_16 = F_378 ( V_426 , V_427 , V_428 ) ;
else if ( F_394 ( V_428 ) )
V_16 = F_381 ( V_426 , V_427 , V_428 , & V_254 ) ;
else if ( F_386 ( V_428 ) || F_395 ( V_428 ) )
V_16 = F_385 ( V_426 , V_427 , V_428 , & V_254 ) ;
if ( ! V_16 && ! V_254 . V_45 )
return 0 ;
if ( V_16 ) {
V_99 = F_75 ( V_16 ) ;
if ( F_84 ( V_99 ) && V_99 -> V_7 == V_2 . V_103 ) {
V_105 = V_438 ;
if ( V_66 )
V_66 -> V_16 = V_16 ;
}
if ( ! V_105 || ! V_66 )
F_249 ( V_16 ) ;
}
if ( V_254 . V_45 && ! V_105 &&
F_68 ( & V_2 . V_103 -> V_15 ) == F_231 ( V_254 ) ) {
V_105 = V_439 ;
if ( V_66 )
V_66 -> V_254 = V_254 ;
}
return V_105 ;
}
static int F_396 ( T_11 * V_440 ,
unsigned long V_427 , unsigned long V_441 ,
struct V_442 * V_443 )
{
struct V_425 * V_426 = V_443 -> V_198 ;
T_9 * V_444 ;
T_12 * V_445 ;
F_397 ( V_443 -> V_82 , V_440 ) ;
V_444 = F_398 ( V_426 -> V_446 , V_440 , V_427 , & V_445 ) ;
for (; V_427 != V_441 ; V_444 ++ , V_427 += V_215 )
if ( F_392 ( V_426 , V_427 , * V_444 , NULL ) )
V_2 . V_423 ++ ;
F_399 ( V_444 - 1 , V_445 ) ;
F_296 () ;
return 0 ;
}
static unsigned long F_400 ( struct V_81 * V_82 )
{
unsigned long V_423 ;
struct V_425 * V_426 ;
F_401 ( & V_82 -> V_447 ) ;
for ( V_426 = V_82 -> V_448 ; V_426 ; V_426 = V_426 -> V_449 ) {
struct V_442 V_450 = {
. V_451 = F_396 ,
. V_82 = V_82 ,
. V_198 = V_426 ,
} ;
if ( F_402 ( V_426 ) )
continue;
F_403 ( V_426 -> V_452 , V_426 -> V_453 ,
& V_450 ) ;
}
F_404 ( & V_82 -> V_447 ) ;
V_423 = V_2 . V_423 ;
V_2 . V_423 = 0 ;
return V_423 ;
}
static int F_405 ( struct V_81 * V_82 )
{
unsigned long V_423 = F_400 ( V_82 ) ;
F_77 ( V_2 . V_145 ) ;
V_2 . V_145 = V_146 ;
return F_377 ( V_423 ) ;
}
static void F_406 ( void )
{
struct V_7 * V_103 = V_2 . V_103 ;
struct V_7 * V_3 = V_2 . V_3 ;
if ( V_2 . V_423 ) {
F_223 ( V_2 . V_3 , V_2 . V_423 ) ;
V_2 . V_423 = 0 ;
}
if ( V_2 . V_454 ) {
F_223 ( V_2 . V_103 , V_2 . V_454 ) ;
V_2 . V_454 = 0 ;
}
if ( V_2 . V_455 ) {
if ( ! F_70 ( V_2 . V_103 ) )
F_203 ( & V_2 . V_103 -> V_139 ,
V_215 * V_2 . V_455 ) ;
F_363 ( V_2 . V_103 , V_2 . V_455 ) ;
if ( ! F_70 ( V_2 . V_3 ) ) {
F_203 ( & V_2 . V_3 -> V_36 ,
V_215 * V_2 . V_455 ) ;
}
V_2 . V_455 = 0 ;
}
F_182 ( V_103 ) ;
F_182 ( V_3 ) ;
F_407 ( & V_2 . V_148 ) ;
}
static void F_408 ( void )
{
struct V_7 * V_103 = V_2 . V_103 ;
V_2 . V_145 = NULL ;
F_406 () ;
F_18 ( & V_2 . V_34 ) ;
V_2 . V_103 = NULL ;
V_2 . V_3 = NULL ;
F_19 ( & V_2 . V_34 ) ;
F_137 ( V_103 ) ;
}
static int F_409 ( struct V_405 * V_406 ,
struct V_77 * V_77 ,
struct V_80 * V_25 )
{
int V_105 = 0 ;
struct V_7 * V_8 = F_57 ( V_77 ) ;
if ( V_8 -> V_4 ) {
struct V_81 * V_82 ;
struct V_7 * V_103 = F_59 ( V_25 ) ;
F_77 ( V_103 == V_8 ) ;
V_82 = F_410 ( V_25 ) ;
if ( ! V_82 )
return 0 ;
if ( V_82 -> V_83 == V_25 ) {
F_77 ( V_2 . V_103 ) ;
F_77 ( V_2 . V_3 ) ;
F_77 ( V_2 . V_423 ) ;
F_77 ( V_2 . V_454 ) ;
F_77 ( V_2 . V_455 ) ;
F_135 ( V_103 ) ;
F_18 ( & V_2 . V_34 ) ;
V_2 . V_103 = V_103 ;
V_2 . V_3 = V_8 ;
F_19 ( & V_2 . V_34 ) ;
V_105 = F_405 ( V_82 ) ;
if ( V_105 )
F_408 () ;
}
F_411 ( V_82 ) ;
}
return V_105 ;
}
static void F_412 ( struct V_405 * V_406 ,
struct V_77 * V_77 ,
struct V_80 * V_25 )
{
F_408 () ;
}
static int F_413 ( T_11 * V_440 ,
unsigned long V_427 , unsigned long V_441 ,
struct V_442 * V_443 )
{
int V_105 = 0 ;
struct V_425 * V_426 = V_443 -> V_198 ;
T_9 * V_444 ;
T_12 * V_445 ;
F_397 ( V_443 -> V_82 , V_440 ) ;
V_41:
V_444 = F_398 ( V_426 -> V_446 , V_440 , V_427 , & V_445 ) ;
for (; V_427 != V_441 ; V_427 += V_215 ) {
T_9 V_428 = * ( V_444 ++ ) ;
union V_437 V_66 ;
int type ;
struct V_16 * V_16 ;
struct V_98 * V_99 ;
T_5 V_254 ;
if ( ! V_2 . V_423 )
break;
type = F_392 ( V_426 , V_427 , V_428 , & V_66 ) ;
switch ( type ) {
case V_438 :
V_16 = V_66 . V_16 ;
if ( F_245 ( V_16 ) )
goto V_270;
V_99 = F_75 ( V_16 ) ;
if ( ! F_240 ( V_16 , 1 , V_99 ,
V_2 . V_103 , V_2 . V_3 , false ) ) {
V_2 . V_423 -- ;
V_2 . V_454 ++ ;
}
F_248 ( V_16 ) ;
V_270:
F_249 ( V_16 ) ;
break;
case V_439 :
V_254 = V_66 . V_254 ;
if ( ! F_276 ( V_254 ,
V_2 . V_103 , V_2 . V_3 , false ) ) {
V_2 . V_423 -- ;
V_2 . V_455 ++ ;
}
break;
default:
break;
}
}
F_399 ( V_444 - 1 , V_445 ) ;
F_296 () ;
if ( V_427 != V_441 ) {
V_105 = F_377 ( 1 ) ;
if ( ! V_105 )
goto V_41;
}
return V_105 ;
}
static void F_414 ( struct V_81 * V_82 )
{
struct V_425 * V_426 ;
F_299 () ;
V_41:
if ( F_54 ( ! F_415 ( & V_82 -> V_447 ) ) ) {
F_406 () ;
F_296 () ;
goto V_41;
}
for ( V_426 = V_82 -> V_448 ; V_426 ; V_426 = V_426 -> V_449 ) {
int V_105 ;
struct V_442 V_456 = {
. V_451 = F_413 ,
. V_82 = V_82 ,
. V_198 = V_426 ,
} ;
if ( F_402 ( V_426 ) )
continue;
V_105 = F_403 ( V_426 -> V_452 , V_426 -> V_453 ,
& V_456 ) ;
if ( V_105 )
break;
}
F_404 ( & V_82 -> V_447 ) ;
}
static void F_416 ( struct V_405 * V_406 ,
struct V_77 * V_78 ,
struct V_77 * V_457 ,
struct V_80 * V_25 )
{
struct V_81 * V_82 = F_410 ( V_25 ) ;
if ( V_82 ) {
if ( V_2 . V_3 )
F_414 ( V_82 ) ;
F_417 ( V_82 ) ;
F_411 ( V_82 ) ;
}
if ( V_2 . V_3 )
F_408 () ;
}
static int F_409 ( struct V_405 * V_406 ,
struct V_77 * V_77 ,
struct V_80 * V_25 )
{
return 0 ;
}
static void F_412 ( struct V_405 * V_406 ,
struct V_77 * V_77 ,
struct V_80 * V_25 )
{
}
static void F_416 ( struct V_405 * V_406 ,
struct V_77 * V_78 ,
struct V_77 * V_457 ,
struct V_80 * V_25 )
{
}
static int T_7 F_418 ( char * V_343 )
{
if ( ! strcmp ( V_343 , L_23 ) )
V_414 = 1 ;
else if ( ! strcmp ( V_343 , L_24 ) )
V_414 = 0 ;
return 1 ;
}
