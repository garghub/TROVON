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
unsigned long
F_45 ( struct V_7 * V_8 , int V_9 , int V_10 ,
unsigned int V_64 )
{
struct V_6 * V_21 ;
enum V_65 V_66 ;
unsigned long V_67 = 0 ;
V_21 = F_4 ( V_8 , V_9 , V_10 ) ;
F_46 (l) {
if ( F_47 ( V_66 ) & V_64 )
V_67 += F_48 ( V_21 , V_66 ) ;
}
return V_67 ;
}
static unsigned long
F_49 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_64 )
{
T_1 V_68 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ )
V_68 += F_45 ( V_8 , V_9 , V_10 , V_64 ) ;
return V_68 ;
}
static unsigned long F_50 ( struct V_7 * V_8 ,
unsigned int V_64 )
{
int V_9 ;
T_1 V_68 = 0 ;
F_24 (nid, N_HIGH_MEMORY)
V_68 += F_49 ( V_8 , V_9 , V_64 ) ;
return V_68 ;
}
static bool F_51 ( struct V_7 * V_8 , int V_69 )
{
unsigned long V_45 , V_70 ;
V_45 = F_52 ( V_8 -> V_47 -> V_53 [ V_63 ] ) ;
V_70 = F_52 ( V_8 -> V_47 -> V_71 [ V_69 ] ) ;
return ( ( long ) V_70 - ( long ) V_45 < 0 ) ;
}
static void F_53 ( struct V_7 * V_8 , int V_69 )
{
unsigned long V_45 , V_70 ;
V_45 = F_52 ( V_8 -> V_47 -> V_53 [ V_63 ] ) ;
switch ( V_69 ) {
case V_72 :
V_70 = V_45 + V_73 ;
break;
case V_74 :
V_70 = V_45 + V_75 ;
break;
case V_76 :
V_70 = V_45 + V_77 ;
break;
default:
return;
}
F_54 ( V_8 -> V_47 -> V_71 [ V_69 ] , V_70 ) ;
}
static void F_55 ( struct V_7 * V_8 , struct V_16 * V_16 )
{
if ( F_56 ( F_51 ( V_8 , V_72 ) ) ) {
F_57 ( V_8 ) ;
F_53 ( V_8 , V_72 ) ;
if ( F_56 ( F_51 ( V_8 ,
V_74 ) ) ) {
F_20 ( V_8 , V_16 ) ;
F_53 ( V_8 ,
V_74 ) ;
}
#if V_78 > 1
if ( F_56 ( F_51 ( V_8 ,
V_76 ) ) ) {
F_58 ( & V_8 -> V_79 ) ;
F_53 ( V_8 ,
V_76 ) ;
}
#endif
}
}
static struct V_7 * F_59 ( struct V_80 * V_81 )
{
return F_60 ( V_14 ( V_81 ,
V_82 ) , struct V_7 ,
V_15 ) ;
}
struct V_7 * F_61 ( struct V_83 * V_25 )
{
if ( F_56 ( ! V_25 ) )
return NULL ;
return F_60 ( F_62 ( V_25 , V_82 ) ,
struct V_7 , V_15 ) ;
}
struct V_7 * F_63 ( struct V_84 * V_85 )
{
struct V_7 * V_8 = NULL ;
if ( ! V_85 )
return NULL ;
F_64 () ;
do {
V_8 = F_61 ( F_65 ( V_85 -> V_86 ) ) ;
if ( F_56 ( ! V_8 ) )
break;
} while ( ! F_27 ( & V_8 -> V_15 ) );
F_66 () ;
return V_8 ;
}
static struct V_7 * F_67 ( struct V_7 * V_8 )
{
struct V_14 * V_15 ;
int V_87 ;
if ( ! V_8 )
return V_88 ;
if ( ! V_8 -> V_89 ) {
if ( F_27 ( & V_8 -> V_15 ) )
return V_8 ;
return NULL ;
}
F_64 () ;
V_15 = F_68 ( & V_90 , 1 , & V_8 -> V_15 , & V_87 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_8 = F_60 ( V_15 , struct V_7 , V_15 ) ;
else
V_8 = NULL ;
F_66 () ;
return V_8 ;
}
static struct V_7 * F_69 ( struct V_7 * V_91 ,
struct V_7 * V_92 ,
bool V_93 )
{
int V_94 = F_70 ( & V_91 -> V_15 ) + 1 ;
int V_87 ;
int V_95 ;
struct V_14 * V_15 ;
V_95 = V_91 -> V_89 ;
F_71 ( & V_91 -> V_15 ) ;
if ( ! V_93 || ( V_92 && ! V_95 ) )
return NULL ;
if ( ! V_92 )
V_92 = V_88 ;
do {
V_91 = NULL ;
F_64 () ;
V_15 = F_68 ( & V_90 , V_94 ,
& V_92 -> V_15 , & V_87 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_91 = F_60 ( V_15 , struct V_7 , V_15 ) ;
F_66 () ;
V_94 = V_87 + 1 ;
} while ( V_15 && ! V_91 );
return V_91 ;
}
static inline bool F_72 ( struct V_7 * V_8 )
{
return ( V_8 == V_88 ) ;
}
void F_73 ( struct V_84 * V_85 , enum V_96 V_44 )
{
struct V_7 * V_8 ;
if ( ! V_85 )
return;
F_64 () ;
V_8 = F_61 ( F_65 ( V_85 -> V_86 ) ) ;
if ( F_56 ( ! V_8 ) )
goto V_97;
switch ( V_44 ) {
case V_98 :
F_38 ( V_8 , 1 ) ;
break;
case V_99 :
F_37 ( V_8 , 1 ) ;
break;
default:
F_74 () ;
}
V_97:
F_66 () ;
}
void F_75 ( struct V_16 * V_16 , enum V_65 V_100 )
{
struct V_101 * V_102 ;
struct V_6 * V_21 ;
if ( F_76 () )
return;
V_102 = F_77 ( V_16 ) ;
if ( ! F_78 ( V_102 ) )
return;
F_79 ( ! V_102 -> V_7 ) ;
V_21 = F_6 ( V_102 -> V_7 , V_16 ) ;
F_48 ( V_21 , V_100 ) -= 1 << F_80 ( V_16 ) ;
if ( F_72 ( V_102 -> V_7 ) )
return;
F_79 ( F_81 ( & V_102 -> V_100 ) ) ;
F_82 ( & V_102 -> V_100 ) ;
}
void F_83 ( struct V_16 * V_16 )
{
F_75 ( V_16 , F_84 ( V_16 ) ) ;
}
void F_85 ( struct V_16 * V_16 )
{
struct V_6 * V_21 ;
struct V_101 * V_102 ;
enum V_65 V_100 = F_84 ( V_16 ) ;
if ( F_76 () )
return;
V_102 = F_77 ( V_16 ) ;
if ( ! F_86 ( V_102 ) )
return;
F_87 () ;
if ( F_72 ( V_102 -> V_7 ) )
return;
V_21 = F_6 ( V_102 -> V_7 , V_16 ) ;
F_88 ( & V_102 -> V_100 , & V_21 -> V_103 [ V_100 ] ) ;
}
void F_89 ( struct V_16 * V_16 , enum V_65 V_100 )
{
struct V_6 * V_21 ;
struct V_101 * V_102 ;
if ( F_76 () )
return;
V_102 = F_77 ( V_16 ) ;
if ( ! F_86 ( V_102 ) )
return;
F_87 () ;
if ( F_72 ( V_102 -> V_7 ) )
return;
V_21 = F_6 ( V_102 -> V_7 , V_16 ) ;
F_90 ( & V_102 -> V_100 , & V_21 -> V_103 [ V_100 ] ) ;
}
void F_91 ( struct V_16 * V_16 , enum V_65 V_100 )
{
struct V_101 * V_102 ;
struct V_6 * V_21 ;
if ( F_76 () )
return;
V_102 = F_77 ( V_16 ) ;
F_79 ( F_92 ( V_102 ) ) ;
if ( ! F_86 ( V_102 ) )
return;
F_87 () ;
V_21 = F_6 ( V_102 -> V_7 , V_16 ) ;
F_48 ( V_21 , V_100 ) += 1 << F_80 ( V_16 ) ;
F_93 ( V_102 ) ;
if ( F_72 ( V_102 -> V_7 ) )
return;
F_94 ( & V_102 -> V_100 , & V_21 -> V_103 [ V_100 ] ) ;
}
static void F_95 ( struct V_16 * V_16 )
{
unsigned long V_104 ;
struct V_38 * V_38 = F_96 ( V_16 ) ;
struct V_101 * V_102 = F_77 ( V_16 ) ;
if ( F_97 ( ! F_98 ( V_16 ) ) )
return;
F_99 ( & V_38 -> V_105 , V_104 ) ;
if ( ! F_86 ( V_102 ) )
F_75 ( V_16 , F_84 ( V_16 ) ) ;
F_100 ( & V_38 -> V_105 , V_104 ) ;
}
static void F_101 ( struct V_16 * V_16 )
{
unsigned long V_104 ;
struct V_38 * V_38 = F_96 ( V_16 ) ;
struct V_101 * V_102 = F_77 ( V_16 ) ;
if ( F_97 ( ! F_98 ( V_16 ) ) )
return;
F_99 ( & V_38 -> V_105 , V_104 ) ;
if ( F_98 ( V_16 ) && ! F_92 ( V_102 ) )
F_91 ( V_16 , F_84 ( V_16 ) ) ;
F_100 ( & V_38 -> V_105 , V_104 ) ;
}
void F_102 ( struct V_16 * V_16 ,
enum V_65 V_106 , enum V_65 V_3 )
{
if ( F_76 () )
return;
F_75 ( V_16 , V_106 ) ;
F_91 ( V_16 , V_3 ) ;
}
static bool F_103 ( const struct V_7 * V_107 ,
struct V_7 * V_8 )
{
if ( V_107 != V_8 ) {
return ( V_107 -> V_89 &&
F_104 ( & V_8 -> V_15 , & V_107 -> V_15 ) ) ;
}
return true ;
}
int F_105 ( struct V_83 * V_108 , const struct V_7 * V_8 )
{
int V_67 ;
struct V_7 * V_109 = NULL ;
struct V_83 * V_25 ;
V_25 = F_106 ( V_108 ) ;
if ( ! V_25 )
return 0 ;
V_109 = F_63 ( V_25 -> V_85 ) ;
F_107 ( V_25 ) ;
if ( ! V_109 )
return 0 ;
V_67 = F_103 ( V_8 , V_109 ) ;
F_71 ( & V_109 -> V_15 ) ;
return V_67 ;
}
static int F_108 ( struct V_7 * V_110 , unsigned long * V_111 )
{
unsigned long V_112 ;
unsigned long V_113 ;
unsigned long V_114 ;
unsigned long V_115 ;
V_113 = F_50 ( V_110 , F_47 ( V_116 ) ) ;
V_112 = F_50 ( V_110 , F_47 ( V_117 ) ) ;
V_114 = ( V_113 + V_112 ) >> ( 30 - V_118 ) ;
if ( V_114 )
V_115 = F_109 ( 10 * V_114 ) ;
else
V_115 = 1 ;
if ( V_111 ) {
V_111 [ 0 ] = V_113 ;
V_111 [ 1 ] = V_112 ;
}
return V_115 ;
}
int F_110 ( struct V_7 * V_110 )
{
unsigned long V_112 ;
unsigned long V_113 ;
unsigned long V_111 [ 2 ] ;
unsigned long V_115 ;
V_115 = F_108 ( V_110 , V_111 ) ;
V_113 = V_111 [ 0 ] ;
V_112 = V_111 [ 1 ] ;
if ( V_113 * V_115 < V_112 )
return 1 ;
return 0 ;
}
int F_111 ( struct V_7 * V_110 )
{
unsigned long V_112 ;
unsigned long V_113 ;
V_113 = F_50 ( V_110 , F_47 ( V_119 ) ) ;
V_112 = F_50 ( V_110 , F_47 ( V_120 ) ) ;
return ( V_112 > V_113 ) ;
}
struct V_121 * F_112 ( struct V_7 * V_110 ,
struct V_38 * V_38 )
{
int V_9 = F_113 ( V_38 ) ;
int V_10 = F_114 ( V_38 ) ;
struct V_6 * V_21 = F_4 ( V_110 , V_9 , V_10 ) ;
return & V_21 -> V_122 ;
}
struct V_121 *
F_115 ( struct V_16 * V_16 )
{
struct V_101 * V_102 ;
struct V_6 * V_21 ;
if ( F_76 () )
return NULL ;
V_102 = F_77 ( V_16 ) ;
if ( ! F_86 ( V_102 ) )
return NULL ;
F_87 () ;
V_21 = F_6 ( V_102 -> V_7 , V_16 ) ;
return & V_21 -> V_122 ;
}
unsigned long F_116 ( unsigned long V_123 ,
struct V_124 * V_125 ,
unsigned long * V_126 , int V_127 ,
int V_128 , struct V_38 * V_129 ,
struct V_7 * V_130 ,
int V_112 , int V_57 )
{
unsigned long V_131 = 0 ;
struct V_16 * V_16 ;
unsigned long V_132 ;
F_117 ( V_133 ) ;
struct V_124 * V_134 ;
struct V_101 * V_102 , * V_135 ;
int V_9 = F_113 ( V_129 ) ;
int V_10 = F_114 ( V_129 ) ;
struct V_6 * V_21 ;
int V_100 = V_136 * V_57 + V_112 ;
int V_67 ;
F_118 ( ! V_130 ) ;
V_21 = F_4 ( V_130 , V_9 , V_10 ) ;
V_134 = & V_21 -> V_103 [ V_100 ] ;
V_132 = 0 ;
F_119 (pc, tmp, src, lru) {
if ( V_132 >= V_123 )
break;
if ( F_56 ( ! F_86 ( V_102 ) ) )
continue;
V_16 = F_120 ( V_102 ) ;
if ( F_56 ( ! F_98 ( V_16 ) ) )
continue;
V_132 ++ ;
V_67 = F_121 ( V_16 , V_128 , V_57 ) ;
switch ( V_67 ) {
case 0 :
F_90 ( & V_16 -> V_100 , V_125 ) ;
F_83 ( V_16 ) ;
V_131 += F_122 ( V_16 ) ;
break;
case - V_137 :
F_89 ( V_16 , F_84 ( V_16 ) ) ;
break;
default:
break;
}
}
* V_126 = V_132 ;
F_123 ( 0 , V_123 , V_132 , V_131 ,
0 , 0 , 0 , V_128 ) ;
return V_131 ;
}
static unsigned long F_124 ( struct V_7 * V_8 )
{
unsigned long long V_138 ;
V_138 = F_125 ( & V_8 -> V_36 ) ;
if ( V_139 )
V_138 = F_126 ( V_138 , F_125 ( & V_8 -> V_140 ) ) ;
return V_138 >> V_118 ;
}
int F_127 ( struct V_7 * V_110 )
{
struct V_80 * V_141 = V_110 -> V_15 . V_80 ;
if ( V_141 -> V_27 == NULL )
return V_142 ;
return V_110 -> V_143 ;
}
static void F_128 ( struct V_7 * V_8 )
{
int V_46 ;
F_30 () ;
F_18 ( & V_8 -> V_49 ) ;
F_31 (cpu)
F_32 ( V_8 -> V_47 -> V_48 [ V_144 ] , V_46 ) += 1 ;
V_8 -> V_50 . V_48 [ V_144 ] += 1 ;
F_19 ( & V_8 -> V_49 ) ;
F_34 () ;
F_129 () ;
}
static void F_130 ( struct V_7 * V_8 )
{
int V_46 ;
if ( ! V_8 )
return;
F_30 () ;
F_18 ( & V_8 -> V_49 ) ;
F_31 (cpu)
F_32 ( V_8 -> V_47 -> V_48 [ V_144 ] , V_46 ) -= 1 ;
V_8 -> V_50 . V_48 [ V_144 ] -= 1 ;
F_19 ( & V_8 -> V_49 ) ;
F_34 () ;
}
static bool F_131 ( struct V_7 * V_8 )
{
F_79 ( ! F_132 () ) ;
return F_52 ( V_8 -> V_47 -> V_48 [ V_144 ] ) > 0 ;
}
static bool F_133 ( struct V_7 * V_8 )
{
struct V_7 * V_106 ;
struct V_7 * V_3 ;
bool V_67 = false ;
F_18 ( & V_2 . V_34 ) ;
V_106 = V_2 . V_106 ;
V_3 = V_2 . V_3 ;
if ( ! V_106 )
goto V_145;
V_67 = F_103 ( V_8 , V_106 )
|| F_103 ( V_8 , V_3 ) ;
V_145:
F_19 ( & V_2 . V_34 ) ;
return V_67 ;
}
static bool F_134 ( struct V_7 * V_8 )
{
if ( V_2 . V_146 && V_147 != V_2 . V_146 ) {
if ( F_133 ( V_8 ) ) {
F_135 ( V_148 ) ;
F_136 ( & V_2 . V_149 , & V_148 , V_150 ) ;
if ( V_2 . V_146 )
F_137 () ;
F_138 ( & V_2 . V_149 , & V_148 ) ;
return true ;
}
}
return false ;
}
void F_139 ( struct V_7 * V_110 , struct V_83 * V_25 )
{
struct V_80 * V_151 ;
struct V_80 * V_152 ;
static char V_153 [ V_154 ] ;
int V_67 ;
if ( ! V_110 || ! V_25 )
return;
F_64 () ;
V_152 = V_110 -> V_15 . V_80 ;
V_151 = F_140 ( V_25 , V_82 ) ;
V_67 = F_141 ( V_151 , V_153 , V_154 ) ;
if ( V_67 < 0 ) {
F_66 () ;
goto V_42;
}
F_66 () ;
F_142 ( V_155 L_1 , V_153 ) ;
F_64 () ;
V_67 = F_141 ( V_152 , V_153 , V_154 ) ;
if ( V_67 < 0 ) {
F_66 () ;
goto V_42;
}
F_66 () ;
F_142 ( V_156 L_2 , V_153 ) ;
V_42:
F_142 ( V_155 L_3 ,
F_143 ( & V_110 -> V_36 , V_157 ) >> 10 ,
F_143 ( & V_110 -> V_36 , V_158 ) >> 10 ,
F_143 ( & V_110 -> V_36 , V_159 ) ) ;
F_142 ( V_155 L_4
L_5 ,
F_143 ( & V_110 -> V_140 , V_157 ) >> 10 ,
F_143 ( & V_110 -> V_140 , V_158 ) >> 10 ,
F_143 ( & V_110 -> V_140 , V_159 ) ) ;
}
static int F_144 ( struct V_7 * V_8 )
{
int V_160 = 0 ;
struct V_7 * V_91 ;
F_145 (iter, mem)
V_160 ++ ;
return V_160 ;
}
T_1 F_146 ( struct V_7 * V_110 )
{
T_1 V_161 ;
T_1 V_140 ;
V_161 = F_143 ( & V_110 -> V_36 , V_158 ) ;
V_161 += V_162 << V_118 ;
V_140 = F_143 ( & V_110 -> V_140 , V_158 ) ;
return F_126 ( V_161 , V_140 ) ;
}
static struct V_7 *
F_147 ( struct V_7 * V_107 )
{
struct V_7 * V_67 = NULL ;
struct V_14 * V_15 ;
int V_94 , V_87 ;
if ( ! V_107 -> V_89 ) {
F_148 ( & V_107 -> V_15 ) ;
V_67 = V_107 ;
}
while ( ! V_67 ) {
F_64 () ;
V_94 = V_107 -> V_163 + 1 ;
V_15 = F_68 ( & V_90 , V_94 , & V_107 -> V_15 ,
& V_87 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_67 = F_60 ( V_15 , struct V_7 , V_15 ) ;
F_66 () ;
if ( ! V_15 ) {
V_107 -> V_163 = 0 ;
} else
V_107 -> V_163 = V_87 ;
}
return V_67 ;
}
static bool F_149 ( struct V_7 * V_8 ,
int V_9 , bool V_164 )
{
if ( F_49 ( V_8 , V_9 , V_165 ) )
return true ;
if ( V_164 || ! V_162 )
return false ;
if ( F_49 ( V_8 , V_9 , V_166 ) )
return true ;
return false ;
}
static void F_150 ( struct V_7 * V_8 )
{
int V_9 ;
if ( ! F_151 ( & V_8 -> V_79 ) )
return;
if ( F_152 ( & V_8 -> V_167 ) > 1 )
return;
V_8 -> V_168 = V_169 [ V_170 ] ;
F_153 (nid, node_states[N_HIGH_MEMORY]) {
if ( ! F_149 ( V_8 , V_9 , false ) )
F_154 ( V_9 , V_8 -> V_168 ) ;
}
F_155 ( & V_8 -> V_79 , 0 ) ;
F_155 ( & V_8 -> V_167 , 0 ) ;
}
int F_156 ( struct V_7 * V_8 )
{
int V_37 ;
F_150 ( V_8 ) ;
V_37 = V_8 -> V_171 ;
V_37 = F_157 ( V_37 , V_8 -> V_168 ) ;
if ( V_37 == V_78 )
V_37 = F_158 ( V_8 -> V_168 ) ;
if ( F_56 ( V_37 == V_78 ) )
V_37 = F_159 () ;
V_8 -> V_171 = V_37 ;
return V_37 ;
}
bool F_160 ( struct V_7 * V_8 , bool V_164 )
{
int V_9 ;
if ( ! F_161 ( V_8 -> V_168 ) ) {
for ( V_9 = F_158 ( V_8 -> V_168 ) ;
V_9 < V_78 ;
V_9 = F_157 ( V_9 , V_8 -> V_168 ) ) {
if ( F_149 ( V_8 , V_9 , V_164 ) )
return true ;
}
}
F_24 (nid, N_HIGH_MEMORY) {
if ( F_162 ( V_9 , V_8 -> V_168 ) )
continue;
if ( F_149 ( V_8 , V_9 , V_164 ) )
return true ;
}
return false ;
}
int F_156 ( struct V_7 * V_8 )
{
return 0 ;
}
bool F_160 ( struct V_7 * V_8 , bool V_164 )
{
return F_149 ( V_8 , 0 , V_164 ) ;
}
static int F_163 ( struct V_7 * V_107 ,
struct V_38 * V_38 ,
T_2 V_172 ,
unsigned long V_173 ,
unsigned long * V_174 )
{
struct V_7 * V_175 ;
int V_67 , V_68 = 0 ;
int V_176 = 0 ;
bool V_164 = V_173 & V_177 ;
bool V_178 = V_173 & V_179 ;
bool V_180 = V_173 & V_181 ;
unsigned long V_35 ;
unsigned long V_182 ;
V_35 = F_22 ( & V_107 -> V_36 ) >> V_118 ;
if ( ! V_180 && ! V_178 && V_107 -> V_183 )
V_164 = true ;
while ( 1 ) {
V_175 = F_147 ( V_107 ) ;
if ( V_175 == V_107 ) {
V_176 ++ ;
if ( ! V_180 && V_176 >= 1 )
F_164 ( V_107 ) ;
if ( V_176 >= 2 ) {
if ( ! V_180 || ! V_68 ) {
F_71 ( & V_175 -> V_15 ) ;
break;
}
if ( V_68 >= ( V_35 >> 2 ) ||
( V_176 > V_184 ) ) {
F_71 ( & V_175 -> V_15 ) ;
break;
}
}
}
if ( ! F_160 ( V_175 , V_164 ) ) {
F_71 ( & V_175 -> V_15 ) ;
continue;
}
if ( V_180 ) {
V_67 = F_165 ( V_175 , V_172 ,
V_164 , V_38 , & V_182 ) ;
* V_174 += V_182 ;
} else
V_67 = F_166 ( V_175 , V_172 ,
V_164 ) ;
F_71 ( & V_175 -> V_15 ) ;
if ( V_178 )
return V_67 ;
V_68 += V_67 ;
if ( V_180 ) {
if ( ! F_22 ( & V_107 -> V_36 ) )
return V_68 ;
} else if ( F_124 ( V_107 ) )
return V_68 ;
}
return V_68 ;
}
static bool F_167 ( struct V_7 * V_8 )
{
struct V_7 * V_91 , * V_185 = NULL ;
bool V_93 = true ;
F_168 (iter, mem, cond) {
if ( V_91 -> V_186 ) {
V_185 = V_91 ;
V_93 = false ;
} else
V_91 -> V_186 = true ;
}
if ( ! V_185 )
return true ;
V_93 = true ;
F_168 (iter, mem, cond) {
if ( V_91 == V_185 ) {
V_93 = false ;
continue;
}
V_91 -> V_186 = false ;
}
return false ;
}
static int F_169 ( struct V_7 * V_8 )
{
struct V_7 * V_91 ;
F_145 (iter, mem)
V_91 -> V_186 = false ;
return 0 ;
}
static void F_170 ( struct V_7 * V_8 )
{
struct V_7 * V_91 ;
F_145 (iter, mem)
F_58 ( & V_91 -> V_187 ) ;
}
static void F_171 ( struct V_7 * V_8 )
{
struct V_7 * V_91 ;
F_145 (iter, mem)
F_172 ( & V_91 -> V_187 , - 1 , 0 ) ;
}
static int F_173 ( T_3 * V_148 ,
unsigned V_128 , int V_188 , void * V_189 )
{
struct V_7 * V_190 = (struct V_7 * ) V_189 ,
* V_191 ;
struct V_192 * V_192 ;
V_192 = F_60 ( V_148 , struct V_192 , V_148 ) ;
V_191 = V_192 -> V_8 ;
if ( ! F_103 ( V_191 , V_190 )
&& ! F_103 ( V_190 , V_191 ) )
return 0 ;
return F_174 ( V_148 , V_128 , V_188 , V_189 ) ;
}
static void F_175 ( struct V_7 * V_8 )
{
F_176 ( & V_193 , V_194 , 0 , V_8 ) ;
}
static void F_177 ( struct V_7 * V_8 )
{
if ( V_8 && F_151 ( & V_8 -> V_187 ) )
F_175 ( V_8 ) ;
}
bool F_178 ( struct V_7 * V_8 , T_2 V_195 )
{
struct V_192 V_196 ;
bool V_197 , V_198 ;
V_196 . V_8 = V_8 ;
V_196 . V_148 . V_104 = 0 ;
V_196 . V_148 . V_199 = F_173 ;
V_196 . V_148 . V_200 = V_147 ;
F_179 ( & V_196 . V_148 . V_201 ) ;
V_198 = true ;
F_170 ( V_8 ) ;
F_18 ( & V_202 ) ;
V_197 = F_167 ( V_8 ) ;
F_136 ( & V_193 , & V_196 . V_148 , V_203 ) ;
if ( ! V_197 || V_8 -> V_204 )
V_198 = false ;
if ( V_197 )
F_180 ( V_8 ) ;
F_19 ( & V_202 ) ;
if ( V_198 ) {
F_138 ( & V_193 , & V_196 . V_148 ) ;
F_181 ( V_8 , V_195 ) ;
} else {
F_137 () ;
F_138 ( & V_193 , & V_196 . V_148 ) ;
}
F_18 ( & V_202 ) ;
if ( V_197 )
F_169 ( V_8 ) ;
F_175 ( V_8 ) ;
F_19 ( & V_202 ) ;
F_171 ( V_8 ) ;
if ( F_182 ( V_205 ) || F_183 ( V_147 ) )
return false ;
F_184 ( 1 ) ;
return true ;
}
void F_185 ( struct V_16 * V_16 ,
enum V_206 V_44 , int V_45 )
{
struct V_7 * V_8 ;
struct V_101 * V_102 = F_77 ( V_16 ) ;
bool V_207 = false ;
unsigned long V_208 ( V_104 ) ;
if ( F_56 ( ! V_102 ) )
return;
F_64 () ;
V_8 = V_102 -> V_7 ;
if ( F_56 ( ! V_8 || ! F_86 ( V_102 ) ) )
goto V_97;
if ( F_56 ( F_131 ( V_8 ) ) || F_186 ( V_16 ) ) {
F_187 ( V_102 , & V_104 ) ;
V_207 = true ;
V_8 = V_102 -> V_7 ;
if ( ! V_8 || ! F_86 ( V_102 ) )
goto V_97;
}
switch ( V_44 ) {
case V_209 :
if ( V_45 > 0 )
F_188 ( V_102 ) ;
else if ( ! F_189 ( V_16 ) )
F_190 ( V_102 ) ;
V_44 = V_210 ;
break;
default:
F_74 () ;
}
F_36 ( V_8 -> V_47 -> V_48 [ V_44 ] , V_45 ) ;
V_97:
if ( F_56 ( V_207 ) )
F_191 ( V_102 , & V_104 ) ;
F_66 () ;
return;
}
static bool F_192 ( struct V_7 * V_8 )
{
struct V_211 * V_212 ;
bool V_67 = true ;
V_212 = & F_193 ( V_213 ) ;
if ( V_8 == V_212 -> V_214 && V_212 -> V_58 )
V_212 -> V_58 -- ;
else
V_67 = false ;
F_194 ( V_213 ) ;
return V_67 ;
}
static void F_195 ( struct V_211 * V_212 )
{
struct V_7 * V_215 = V_212 -> V_214 ;
if ( V_212 -> V_58 ) {
unsigned long V_216 = V_212 -> V_58 * V_217 ;
F_196 ( & V_215 -> V_36 , V_216 ) ;
if ( V_139 )
F_196 ( & V_215 -> V_140 , V_216 ) ;
V_212 -> V_58 = 0 ;
}
V_212 -> V_214 = NULL ;
}
static void F_197 ( struct V_218 * V_219 )
{
struct V_211 * V_212 = & F_198 ( V_213 ) ;
F_195 ( V_212 ) ;
F_199 ( V_220 , & V_212 -> V_104 ) ;
}
static void F_200 ( struct V_7 * V_8 , unsigned int V_58 )
{
struct V_211 * V_212 = & F_193 ( V_213 ) ;
if ( V_212 -> V_214 != V_8 ) {
F_195 ( V_212 ) ;
V_212 -> V_214 = V_8 ;
}
V_212 -> V_58 += V_58 ;
F_194 ( V_213 ) ;
}
static void F_201 ( struct V_7 * V_107 , bool V_188 )
{
int V_46 , V_221 ;
F_30 () ;
V_221 = F_202 () ;
F_31 (cpu) {
struct V_211 * V_212 = & F_32 ( V_213 , V_46 ) ;
struct V_7 * V_8 ;
V_8 = V_212 -> V_214 ;
if ( ! V_8 || ! V_212 -> V_58 )
continue;
if ( ! F_103 ( V_107 , V_8 ) )
continue;
if ( ! F_203 ( V_220 , & V_212 -> V_104 ) ) {
if ( V_46 == V_221 )
F_197 ( & V_212 -> V_222 ) ;
else
F_204 ( V_46 , & V_212 -> V_222 ) ;
}
}
F_205 () ;
if ( ! V_188 )
goto V_97;
F_31 (cpu) {
struct V_211 * V_212 = & F_32 ( V_213 , V_46 ) ;
if ( F_2 ( V_220 , & V_212 -> V_104 ) )
F_206 ( & V_212 -> V_222 ) ;
}
V_97:
F_34 () ;
}
static void F_164 ( struct V_7 * V_107 )
{
if ( ! F_207 ( & V_223 ) )
return;
F_201 ( V_107 , false ) ;
F_208 ( & V_223 ) ;
}
static void F_209 ( struct V_7 * V_107 )
{
F_210 ( & V_223 ) ;
F_201 ( V_107 , true ) ;
F_208 ( & V_223 ) ;
}
static void F_211 ( struct V_7 * V_8 , int V_46 )
{
int V_224 ;
F_18 ( & V_8 -> V_49 ) ;
for ( V_224 = 0 ; V_224 < V_225 ; V_224 ++ ) {
long V_226 = F_32 ( V_8 -> V_47 -> V_48 [ V_224 ] , V_46 ) ;
F_32 ( V_8 -> V_47 -> V_48 [ V_224 ] , V_46 ) = 0 ;
V_8 -> V_50 . V_48 [ V_224 ] += V_226 ;
}
for ( V_224 = 0 ; V_224 < V_227 ; V_224 ++ ) {
unsigned long V_226 = F_32 ( V_8 -> V_47 -> V_53 [ V_224 ] , V_46 ) ;
F_32 ( V_8 -> V_47 -> V_53 [ V_224 ] , V_46 ) = 0 ;
V_8 -> V_50 . V_53 [ V_224 ] += V_226 ;
}
F_32 ( V_8 -> V_47 -> V_48 [ V_144 ] , V_46 ) = 0 ;
F_19 ( & V_8 -> V_49 ) ;
}
static void F_212 ( struct V_7 * V_8 , int V_46 )
{
int V_44 = V_144 ;
F_18 ( & V_8 -> V_49 ) ;
F_32 ( V_8 -> V_47 -> V_48 [ V_44 ] , V_46 ) = V_8 -> V_50 . V_48 [ V_44 ] ;
F_19 ( & V_8 -> V_49 ) ;
}
static int T_4 F_213 ( struct V_228 * V_229 ,
unsigned long V_230 ,
void * V_231 )
{
int V_46 = ( unsigned long ) V_231 ;
struct V_211 * V_212 ;
struct V_7 * V_91 ;
if ( ( V_230 == V_232 ) ) {
F_214 (iter)
F_212 ( V_91 , V_46 ) ;
return V_233 ;
}
if ( ( V_230 != V_234 ) || V_230 != V_235 )
return V_233 ;
F_214 (iter)
F_211 ( V_91 , V_46 ) ;
V_212 = & F_32 ( V_213 , V_46 ) ;
F_195 ( V_212 ) ;
return V_233 ;
}
static int F_215 ( struct V_7 * V_8 , T_2 V_172 ,
unsigned int V_58 , bool V_236 )
{
unsigned long V_237 = V_58 * V_217 ;
struct V_7 * V_238 ;
struct V_239 * V_240 ;
unsigned long V_104 = 0 ;
int V_67 ;
V_67 = F_216 ( & V_8 -> V_36 , V_237 , & V_240 ) ;
if ( F_97 ( ! V_67 ) ) {
if ( ! V_139 )
return V_241 ;
V_67 = F_216 ( & V_8 -> V_140 , V_237 , & V_240 ) ;
if ( F_97 ( ! V_67 ) )
return V_241 ;
F_196 ( & V_8 -> V_36 , V_237 ) ;
V_238 = F_217 ( V_240 , V_140 ) ;
V_104 |= V_177 ;
} else
V_238 = F_217 ( V_240 , V_36 ) ;
if ( V_58 == V_242 )
return V_243 ;
if ( ! ( V_172 & V_244 ) )
return V_245 ;
V_67 = F_163 ( V_238 , NULL ,
V_172 , V_104 , NULL ) ;
if ( F_124 ( V_238 ) >= V_58 )
return V_243 ;
if ( V_58 == 1 && V_67 )
return V_243 ;
if ( F_134 ( V_238 ) )
return V_243 ;
if ( ! V_236 )
return V_246 ;
if ( ! F_178 ( V_238 , V_172 ) )
return V_247 ;
return V_243 ;
}
static int F_218 ( struct V_84 * V_85 ,
T_2 V_172 ,
unsigned int V_58 ,
struct V_7 * * V_110 ,
bool V_248 )
{
unsigned int V_249 = F_219 ( V_242 , V_58 ) ;
int V_250 = V_251 ;
struct V_7 * V_8 = NULL ;
int V_67 ;
if ( F_56 ( F_182 ( V_205 )
|| F_183 ( V_147 ) ) )
goto V_252;
if ( ! * V_110 && ! V_85 )
goto V_252;
V_253:
if ( * V_110 ) {
V_8 = * V_110 ;
F_79 ( F_220 ( & V_8 -> V_15 ) ) ;
if ( F_72 ( V_8 ) )
goto V_42;
if ( V_58 == 1 && F_192 ( V_8 ) )
goto V_42;
F_148 ( & V_8 -> V_15 ) ;
} else {
struct V_83 * V_25 ;
F_64 () ;
V_25 = F_65 ( V_85 -> V_86 ) ;
V_8 = F_61 ( V_25 ) ;
if ( ! V_8 || F_72 ( V_8 ) ) {
F_66 () ;
goto V_42;
}
if ( V_58 == 1 && F_192 ( V_8 ) ) {
F_66 () ;
goto V_42;
}
if ( ! F_27 ( & V_8 -> V_15 ) ) {
F_66 () ;
goto V_253;
}
F_66 () ;
}
do {
bool V_236 ;
if ( F_183 ( V_147 ) ) {
F_71 ( & V_8 -> V_15 ) ;
goto V_252;
}
V_236 = false ;
if ( V_248 && ! V_250 ) {
V_236 = true ;
V_250 = V_251 ;
}
V_67 = F_215 ( V_8 , V_172 , V_249 , V_236 ) ;
switch ( V_67 ) {
case V_241 :
break;
case V_243 :
V_249 = V_58 ;
F_71 ( & V_8 -> V_15 ) ;
V_8 = NULL ;
goto V_253;
case V_245 :
F_71 ( & V_8 -> V_15 ) ;
goto V_254;
case V_246 :
if ( ! V_248 ) {
F_71 ( & V_8 -> V_15 ) ;
goto V_254;
}
V_250 -- ;
break;
case V_247 :
F_71 ( & V_8 -> V_15 ) ;
goto V_252;
}
} while ( V_67 != V_241 );
if ( V_249 > V_58 )
F_200 ( V_8 , V_249 - V_58 ) ;
F_71 ( & V_8 -> V_15 ) ;
V_42:
* V_110 = V_8 ;
return 0 ;
V_254:
* V_110 = NULL ;
return - V_255 ;
V_252:
* V_110 = NULL ;
return 0 ;
}
static void F_221 ( struct V_7 * V_8 ,
unsigned int V_58 )
{
if ( ! F_72 ( V_8 ) ) {
unsigned long V_216 = V_58 * V_217 ;
F_196 ( & V_8 -> V_36 , V_216 ) ;
if ( V_139 )
F_196 ( & V_8 -> V_140 , V_216 ) ;
}
}
static struct V_7 * F_222 ( unsigned short V_256 )
{
struct V_14 * V_15 ;
if ( ! V_256 )
return NULL ;
V_15 = F_223 ( & V_90 , V_256 ) ;
if ( ! V_15 )
return NULL ;
return F_60 ( V_15 , struct V_7 , V_15 ) ;
}
struct V_7 * F_224 ( struct V_16 * V_16 )
{
struct V_7 * V_8 = NULL ;
struct V_101 * V_102 ;
unsigned short V_256 ;
T_5 V_257 ;
F_79 ( ! F_225 ( V_16 ) ) ;
V_102 = F_77 ( V_16 ) ;
F_226 ( V_102 ) ;
if ( F_86 ( V_102 ) ) {
V_8 = V_102 -> V_7 ;
if ( V_8 && ! F_27 ( & V_8 -> V_15 ) )
V_8 = NULL ;
} else if ( F_227 ( V_16 ) ) {
V_257 . V_45 = F_228 ( V_16 ) ;
V_256 = F_229 ( V_257 ) ;
F_64 () ;
V_8 = F_222 ( V_256 ) ;
if ( V_8 && ! F_27 ( & V_8 -> V_15 ) )
V_8 = NULL ;
F_66 () ;
}
F_230 ( V_102 ) ;
return V_8 ;
}
static void F_231 ( struct V_7 * V_8 ,
struct V_16 * V_16 ,
unsigned int V_58 ,
struct V_101 * V_102 ,
enum V_258 V_259 )
{
F_226 ( V_102 ) ;
if ( F_56 ( F_86 ( V_102 ) ) ) {
F_230 ( V_102 ) ;
F_221 ( V_8 , V_58 ) ;
return;
}
V_102 -> V_7 = V_8 ;
F_232 () ;
switch ( V_259 ) {
case V_260 :
case V_261 :
F_233 ( V_102 ) ;
F_234 ( V_102 ) ;
break;
case V_262 :
F_235 ( V_102 ) ;
F_234 ( V_102 ) ;
break;
default:
break;
}
F_40 ( V_8 , F_236 ( V_102 ) , V_58 ) ;
F_230 ( V_102 ) ;
F_55 ( V_8 , V_16 ) ;
}
void F_237 ( struct V_16 * V_263 , struct V_16 * V_264 )
{
struct V_101 * V_265 = F_77 ( V_263 ) ;
struct V_101 * V_266 = F_77 ( V_264 ) ;
unsigned long V_104 ;
if ( F_76 () )
return;
F_187 ( V_265 , & V_104 ) ;
V_266 -> V_7 = V_265 -> V_7 ;
F_232 () ;
if ( F_92 ( V_265 ) ) {
enum V_65 V_100 ;
struct V_6 * V_21 ;
V_100 = F_84 ( V_263 ) ;
V_21 = F_6 ( V_265 -> V_7 , V_263 ) ;
F_48 ( V_21 , V_100 ) -= 1 ;
}
V_266 -> V_104 = V_265 -> V_104 & ~ V_267 ;
F_191 ( V_265 , & V_104 ) ;
}
static int F_238 ( struct V_16 * V_16 ,
unsigned int V_58 ,
struct V_101 * V_102 ,
struct V_7 * V_106 ,
struct V_7 * V_3 ,
bool V_268 )
{
unsigned long V_104 ;
int V_67 ;
F_79 ( V_106 == V_3 ) ;
F_79 ( F_98 ( V_16 ) ) ;
V_67 = - V_137 ;
if ( V_58 > 1 && ! F_186 ( V_16 ) )
goto V_97;
F_226 ( V_102 ) ;
V_67 = - V_269 ;
if ( ! F_86 ( V_102 ) || V_102 -> V_7 != V_106 )
goto V_145;
F_187 ( V_102 , & V_104 ) ;
if ( F_239 ( V_102 ) ) {
F_41 () ;
F_240 ( V_106 -> V_47 -> V_48 [ V_210 ] ) ;
F_43 ( V_3 -> V_47 -> V_48 [ V_210 ] ) ;
F_44 () ;
}
F_40 ( V_106 , F_236 ( V_102 ) , - V_58 ) ;
if ( V_268 )
F_221 ( V_106 , V_58 ) ;
V_102 -> V_7 = V_3 ;
F_40 ( V_3 , F_236 ( V_102 ) , V_58 ) ;
F_191 ( V_102 , & V_104 ) ;
V_67 = 0 ;
V_145:
F_230 ( V_102 ) ;
F_55 ( V_3 , V_16 ) ;
F_55 ( V_106 , V_16 ) ;
V_97:
return V_67 ;
}
static int F_241 ( struct V_16 * V_16 ,
struct V_101 * V_102 ,
struct V_7 * V_270 ,
T_2 V_172 )
{
struct V_80 * V_271 = V_270 -> V_15 . V_80 ;
struct V_80 * V_272 = V_271 -> V_27 ;
struct V_7 * V_27 ;
unsigned int V_58 ;
unsigned long V_208 ( V_104 ) ;
int V_67 ;
if ( ! V_272 )
return - V_269 ;
V_67 = - V_137 ;
if ( ! F_242 ( V_16 ) )
goto V_97;
if ( F_243 ( V_16 ) )
goto V_273;
V_58 = F_122 ( V_16 ) ;
V_27 = F_59 ( V_272 ) ;
V_67 = F_218 ( NULL , V_172 , V_58 , & V_27 , false ) ;
if ( V_67 || ! V_27 )
goto V_274;
if ( V_58 > 1 )
V_104 = F_244 ( V_16 ) ;
V_67 = F_238 ( V_16 , V_58 , V_102 , V_270 , V_27 , true ) ;
if ( V_67 )
F_221 ( V_27 , V_58 ) ;
if ( V_58 > 1 )
F_245 ( V_16 , V_104 ) ;
V_274:
F_246 ( V_16 ) ;
V_273:
F_247 ( V_16 ) ;
V_97:
return V_67 ;
}
static int F_248 ( struct V_16 * V_16 , struct V_84 * V_85 ,
T_2 V_172 , enum V_258 V_259 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_58 = 1 ;
struct V_101 * V_102 ;
bool V_248 = true ;
int V_67 ;
if ( F_186 ( V_16 ) ) {
V_58 <<= F_80 ( V_16 ) ;
F_79 ( ! F_186 ( V_16 ) ) ;
V_248 = false ;
}
V_102 = F_77 ( V_16 ) ;
F_118 ( ! V_102 ) ;
V_67 = F_218 ( V_85 , V_172 , V_58 , & V_8 , V_248 ) ;
if ( V_67 || ! V_8 )
return V_67 ;
F_231 ( V_8 , V_16 , V_58 , V_102 , V_259 ) ;
return 0 ;
}
int F_249 ( struct V_16 * V_16 ,
struct V_84 * V_85 , T_2 V_172 )
{
if ( F_76 () )
return 0 ;
if ( F_189 ( V_16 ) || ( V_16 -> V_275 && ! F_250 ( V_16 ) ) )
return 0 ;
if ( F_56 ( ! V_85 ) )
V_85 = & V_276 ;
return F_248 ( V_16 , V_85 , V_172 ,
V_262 ) ;
}
static void
F_251 ( struct V_16 * V_16 , struct V_7 * V_8 ,
enum V_258 V_259 )
{
struct V_101 * V_102 = F_77 ( V_16 ) ;
F_95 ( V_16 ) ;
F_231 ( V_8 , V_16 , 1 , V_102 , V_259 ) ;
F_101 ( V_16 ) ;
return;
}
int F_252 ( struct V_16 * V_16 , struct V_84 * V_85 ,
T_2 V_172 )
{
struct V_7 * V_8 = NULL ;
int V_67 ;
if ( F_76 () )
return 0 ;
if ( F_253 ( V_16 ) )
return 0 ;
if ( F_56 ( ! V_85 ) )
V_85 = & V_276 ;
if ( F_254 ( V_16 ) ) {
V_67 = F_218 ( V_85 , V_172 , 1 , & V_8 , true ) ;
if ( V_67 || ! V_8 )
return V_67 ;
F_251 ( V_16 , V_8 ,
V_260 ) ;
return V_67 ;
}
if ( F_227 ( V_16 ) ) {
V_67 = F_255 ( V_85 , V_16 , V_172 , & V_8 ) ;
if ( ! V_67 )
F_256 ( V_16 , V_8 ,
V_261 ) ;
} else
V_67 = F_248 ( V_16 , V_85 , V_172 ,
V_261 ) ;
return V_67 ;
}
int F_255 ( struct V_84 * V_85 ,
struct V_16 * V_16 ,
T_2 V_195 , struct V_7 * * V_277 )
{
struct V_7 * V_8 ;
int V_67 ;
* V_277 = NULL ;
if ( F_76 () )
return 0 ;
if ( ! V_139 )
goto V_278;
if ( ! F_227 ( V_16 ) )
goto V_278;
V_8 = F_224 ( V_16 ) ;
if ( ! V_8 )
goto V_278;
* V_277 = V_8 ;
V_67 = F_218 ( NULL , V_195 , 1 , V_277 , true ) ;
F_71 ( & V_8 -> V_15 ) ;
return V_67 ;
V_278:
if ( F_56 ( ! V_85 ) )
V_85 = & V_276 ;
return F_218 ( V_85 , V_195 , 1 , V_277 , true ) ;
}
static void
F_256 ( struct V_16 * V_16 , struct V_7 * V_277 ,
enum V_258 V_259 )
{
if ( F_76 () )
return;
if ( ! V_277 )
return;
F_257 ( & V_277 -> V_15 ) ;
F_251 ( V_16 , V_277 , V_259 ) ;
if ( V_139 && F_227 ( V_16 ) ) {
T_5 V_257 = { . V_45 = F_228 (page) } ;
unsigned short V_256 ;
struct V_7 * V_110 ;
V_256 = F_258 ( V_257 , 0 ) ;
F_64 () ;
V_110 = F_222 ( V_256 ) ;
if ( V_110 ) {
if ( ! F_72 ( V_110 ) )
F_196 ( & V_110 -> V_140 , V_217 ) ;
F_35 ( V_110 , false ) ;
F_259 ( V_110 ) ;
}
F_66 () ;
}
F_260 ( & V_277 -> V_15 ) ;
}
void F_261 ( struct V_16 * V_16 , struct V_7 * V_277 )
{
F_256 ( V_16 , V_277 ,
V_262 ) ;
}
void F_262 ( struct V_7 * V_8 )
{
if ( F_76 () )
return;
if ( ! V_8 )
return;
F_221 ( V_8 , 1 ) ;
}
static void F_263 ( struct V_7 * V_8 ,
unsigned int V_58 ,
const enum V_258 V_259 )
{
struct V_279 * V_249 = NULL ;
bool V_280 = true ;
if ( ! V_139 || V_259 == V_281 )
V_280 = false ;
V_249 = & V_147 -> V_282 ;
if ( ! V_249 -> V_110 )
V_249 -> V_110 = V_8 ;
if ( ! V_249 -> V_283 || F_182 ( V_205 ) )
goto V_284;
if ( V_58 > 1 )
goto V_284;
if ( V_249 -> V_110 != V_8 )
goto V_284;
V_249 -> V_58 ++ ;
if ( V_280 )
V_249 -> V_285 ++ ;
return;
V_284:
F_196 ( & V_8 -> V_36 , V_58 * V_217 ) ;
if ( V_280 )
F_196 ( & V_8 -> V_140 , V_58 * V_217 ) ;
if ( F_56 ( V_249 -> V_110 != V_8 ) )
F_177 ( V_8 ) ;
return;
}
static struct V_7 *
F_264 ( struct V_16 * V_16 , enum V_258 V_259 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_58 = 1 ;
struct V_101 * V_102 ;
if ( F_76 () )
return NULL ;
if ( F_227 ( V_16 ) )
return NULL ;
if ( F_186 ( V_16 ) ) {
V_58 <<= F_80 ( V_16 ) ;
F_79 ( ! F_186 ( V_16 ) ) ;
}
V_102 = F_77 ( V_16 ) ;
if ( F_56 ( ! V_102 || ! F_86 ( V_102 ) ) )
return NULL ;
F_226 ( V_102 ) ;
V_8 = V_102 -> V_7 ;
if ( ! F_86 ( V_102 ) )
goto V_286;
switch ( V_259 ) {
case V_262 :
case V_287 :
if ( F_189 ( V_16 ) || F_265 ( V_102 ) )
goto V_286;
break;
case V_281 :
if ( ! F_250 ( V_16 ) ) {
if ( V_16 -> V_275 && ! F_254 ( V_16 ) )
goto V_286;
} else if ( F_189 ( V_16 ) )
goto V_286;
break;
default:
break;
}
F_40 ( V_8 , F_236 ( V_102 ) , - V_58 ) ;
F_266 ( V_102 ) ;
F_230 ( V_102 ) ;
F_55 ( V_8 , V_16 ) ;
if ( V_139 && V_259 == V_281 ) {
F_35 ( V_8 , true ) ;
F_267 ( V_8 ) ;
}
if ( ! F_72 ( V_8 ) )
F_263 ( V_8 , V_58 , V_259 ) ;
return V_8 ;
V_286:
F_230 ( V_102 ) ;
return NULL ;
}
void F_268 ( struct V_16 * V_16 )
{
if ( F_189 ( V_16 ) )
return;
if ( V_16 -> V_275 && ! F_250 ( V_16 ) )
return;
F_264 ( V_16 , V_262 ) ;
}
void F_269 ( struct V_16 * V_16 )
{
F_79 ( F_189 ( V_16 ) ) ;
F_79 ( V_16 -> V_275 ) ;
F_264 ( V_16 , V_260 ) ;
}
void F_270 ( void )
{
V_147 -> V_282 . V_283 ++ ;
if ( V_147 -> V_282 . V_283 == 1 ) {
V_147 -> V_282 . V_110 = NULL ;
V_147 -> V_282 . V_58 = 0 ;
V_147 -> V_282 . V_285 = 0 ;
}
}
void F_271 ( void )
{
struct V_279 * V_249 = & V_147 -> V_282 ;
if ( ! V_249 -> V_283 )
return;
V_249 -> V_283 -- ;
if ( V_249 -> V_283 )
return;
if ( ! V_249 -> V_110 )
return;
if ( V_249 -> V_58 )
F_196 ( & V_249 -> V_110 -> V_36 ,
V_249 -> V_58 * V_217 ) ;
if ( V_249 -> V_285 )
F_196 ( & V_249 -> V_110 -> V_140 ,
V_249 -> V_285 * V_217 ) ;
F_177 ( V_249 -> V_110 ) ;
V_249 -> V_110 = NULL ;
}
void
F_272 ( struct V_16 * V_16 , T_5 V_257 , bool V_288 )
{
struct V_7 * V_110 ;
int V_259 = V_281 ;
if ( ! V_288 )
V_259 = V_287 ;
V_110 = F_264 ( V_16 , V_259 ) ;
if ( V_139 && V_288 && V_110 )
F_258 ( V_257 , F_70 ( & V_110 -> V_15 ) ) ;
}
void F_273 ( T_5 V_257 )
{
struct V_7 * V_110 ;
unsigned short V_256 ;
if ( ! V_139 )
return;
V_256 = F_258 ( V_257 , 0 ) ;
F_64 () ;
V_110 = F_222 ( V_256 ) ;
if ( V_110 ) {
if ( ! F_72 ( V_110 ) )
F_196 ( & V_110 -> V_140 , V_217 ) ;
F_35 ( V_110 , false ) ;
F_259 ( V_110 ) ;
}
F_66 () ;
}
static int F_274 ( T_5 V_289 ,
struct V_7 * V_106 , struct V_7 * V_3 , bool V_290 )
{
unsigned short V_291 , V_292 ;
V_291 = F_70 ( & V_106 -> V_15 ) ;
V_292 = F_70 ( & V_3 -> V_15 ) ;
if ( F_275 ( V_289 , V_291 , V_292 ) == V_291 ) {
F_35 ( V_106 , false ) ;
F_35 ( V_3 , true ) ;
F_267 ( V_3 ) ;
if ( V_290 ) {
if ( ! F_72 ( V_106 ) )
F_196 ( & V_106 -> V_140 , V_217 ) ;
F_259 ( V_106 ) ;
if ( ! F_72 ( V_3 ) )
F_196 ( & V_3 -> V_36 , V_217 ) ;
}
return 0 ;
}
return - V_269 ;
}
static inline int F_274 ( T_5 V_289 ,
struct V_7 * V_106 , struct V_7 * V_3 , bool V_290 )
{
return - V_269 ;
}
int F_276 ( struct V_16 * V_16 ,
struct V_16 * V_293 , struct V_7 * * V_277 , T_2 V_172 )
{
struct V_7 * V_8 = NULL ;
struct V_101 * V_102 ;
enum V_258 V_259 ;
int V_67 = 0 ;
* V_277 = NULL ;
F_79 ( F_186 ( V_16 ) ) ;
if ( F_76 () )
return 0 ;
V_102 = F_77 ( V_16 ) ;
F_226 ( V_102 ) ;
if ( F_86 ( V_102 ) ) {
V_8 = V_102 -> V_7 ;
F_148 ( & V_8 -> V_15 ) ;
if ( F_250 ( V_16 ) )
F_277 ( V_102 ) ;
}
F_230 ( V_102 ) ;
if ( ! V_8 )
return 0 ;
* V_277 = V_8 ;
V_67 = F_218 ( NULL , V_172 , 1 , V_277 , false ) ;
F_71 ( & V_8 -> V_15 ) ;
if ( V_67 || * V_277 == NULL ) {
if ( F_250 ( V_16 ) ) {
F_226 ( V_102 ) ;
F_278 ( V_102 ) ;
F_230 ( V_102 ) ;
F_268 ( V_16 ) ;
}
return - V_255 ;
}
V_102 = F_77 ( V_293 ) ;
if ( F_250 ( V_16 ) )
V_259 = V_262 ;
else if ( F_254 ( V_16 ) )
V_259 = V_260 ;
else
V_259 = V_261 ;
F_231 ( V_8 , V_16 , 1 , V_102 , V_259 ) ;
return V_67 ;
}
void F_279 ( struct V_7 * V_8 ,
struct V_16 * V_294 , struct V_16 * V_293 , bool V_295 )
{
struct V_16 * V_296 , * V_297 ;
struct V_101 * V_102 ;
if ( ! V_8 )
return;
F_257 ( & V_8 -> V_15 ) ;
if ( ! V_295 ) {
V_296 = V_294 ;
V_297 = V_293 ;
} else {
V_296 = V_293 ;
V_297 = V_294 ;
}
V_102 = F_77 ( V_294 ) ;
F_226 ( V_102 ) ;
F_278 ( V_102 ) ;
F_230 ( V_102 ) ;
F_264 ( V_297 , V_298 ) ;
if ( F_250 ( V_296 ) )
F_268 ( V_296 ) ;
F_260 ( & V_8 -> V_15 ) ;
}
static struct V_101 * F_280 ( struct V_16 * V_16 )
{
struct V_101 * V_102 ;
V_102 = F_77 ( V_16 ) ;
if ( F_97 ( V_102 ) && F_86 ( V_102 ) )
return V_102 ;
return NULL ;
}
bool F_281 ( struct V_16 * V_16 )
{
if ( F_76 () )
return false ;
return F_280 ( V_16 ) != NULL ;
}
void F_282 ( struct V_16 * V_16 )
{
struct V_101 * V_102 ;
V_102 = F_280 ( V_16 ) ;
if ( V_102 ) {
int V_67 = - 1 ;
char * V_299 ;
F_142 ( V_300 L_6 ,
V_102 , V_102 -> V_104 , V_102 -> V_7 ) ;
V_299 = F_283 ( V_154 , V_301 ) ;
if ( V_299 ) {
F_64 () ;
V_67 = F_141 ( V_102 -> V_7 -> V_15 . V_80 ,
V_299 , V_154 ) ;
F_66 () ;
}
F_142 ( V_156 L_7 ,
( V_67 < 0 ) ? L_8 : V_299 ) ;
F_284 ( V_299 ) ;
}
}
static int F_285 ( struct V_7 * V_110 ,
unsigned long long V_45 )
{
int V_302 ;
T_1 V_303 , V_304 ;
int V_67 = 0 ;
int V_305 = F_144 ( V_110 ) ;
T_1 V_306 , V_307 ;
int V_308 ;
V_302 = V_251 * V_305 ;
V_307 = F_143 ( & V_110 -> V_36 , V_157 ) ;
V_308 = 0 ;
while ( V_302 ) {
if ( F_286 ( V_147 ) ) {
V_67 = - V_309 ;
break;
}
F_210 ( & V_310 ) ;
V_303 = F_143 ( & V_110 -> V_140 , V_158 ) ;
if ( V_303 < V_45 ) {
V_67 = - V_269 ;
F_208 ( & V_310 ) ;
break;
}
V_304 = F_143 ( & V_110 -> V_36 , V_158 ) ;
if ( V_304 < V_45 )
V_308 = 1 ;
V_67 = F_287 ( & V_110 -> V_36 , V_45 ) ;
if ( ! V_67 ) {
if ( V_303 == V_45 )
V_110 -> V_183 = true ;
else
V_110 -> V_183 = false ;
}
F_208 ( & V_310 ) ;
if ( ! V_67 )
break;
F_163 ( V_110 , NULL , V_301 ,
V_179 ,
NULL ) ;
V_306 = F_143 ( & V_110 -> V_36 , V_157 ) ;
if ( V_306 >= V_307 )
V_302 -- ;
else
V_307 = V_306 ;
}
if ( ! V_67 && V_308 )
F_177 ( V_110 ) ;
return V_67 ;
}
static int F_288 ( struct V_7 * V_110 ,
unsigned long long V_45 )
{
int V_302 ;
T_1 V_304 , V_303 , V_307 , V_306 ;
int V_305 = F_144 ( V_110 ) ;
int V_67 = - V_137 ;
int V_308 = 0 ;
V_302 = V_305 * V_251 ;
V_307 = F_143 ( & V_110 -> V_140 , V_157 ) ;
while ( V_302 ) {
if ( F_286 ( V_147 ) ) {
V_67 = - V_309 ;
break;
}
F_210 ( & V_310 ) ;
V_304 = F_143 ( & V_110 -> V_36 , V_158 ) ;
if ( V_304 > V_45 ) {
V_67 = - V_269 ;
F_208 ( & V_310 ) ;
break;
}
V_303 = F_143 ( & V_110 -> V_140 , V_158 ) ;
if ( V_303 < V_45 )
V_308 = 1 ;
V_67 = F_287 ( & V_110 -> V_140 , V_45 ) ;
if ( ! V_67 ) {
if ( V_304 == V_45 )
V_110 -> V_183 = true ;
else
V_110 -> V_183 = false ;
}
F_208 ( & V_310 ) ;
if ( ! V_67 )
break;
F_163 ( V_110 , NULL , V_301 ,
V_177 |
V_179 ,
NULL ) ;
V_306 = F_143 ( & V_110 -> V_140 , V_157 ) ;
if ( V_306 >= V_307 )
V_302 -- ;
else
V_307 = V_306 ;
}
if ( ! V_67 && V_308 )
F_177 ( V_110 ) ;
return V_67 ;
}
unsigned long F_289 ( struct V_38 * V_38 , int V_127 ,
T_2 V_172 ,
unsigned long * V_174 )
{
unsigned long V_311 = 0 ;
struct V_6 * V_21 , * V_312 = NULL ;
unsigned long V_313 ;
int V_176 = 0 ;
struct V_17 * V_22 ;
unsigned long long V_35 ;
unsigned long V_182 ;
if ( V_127 > 0 )
return 0 ;
V_22 = F_9 ( F_113 ( V_38 ) , F_114 ( V_38 ) ) ;
do {
if ( V_312 )
V_21 = V_312 ;
else
V_21 = F_28 ( V_22 ) ;
if ( ! V_21 )
break;
V_182 = 0 ;
V_313 = F_163 ( V_21 -> V_8 , V_38 ,
V_172 ,
V_181 ,
& V_182 ) ;
V_311 += V_313 ;
* V_174 += V_182 ;
F_18 ( & V_22 -> V_34 ) ;
V_312 = NULL ;
if ( ! V_313 ) {
do {
V_312 =
F_25 ( V_22 ) ;
if ( V_312 == V_21 )
F_71 ( & V_312 -> V_8 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_15 ( V_21 -> V_8 , V_21 , V_22 ) ;
V_35 = F_22 ( & V_21 -> V_8 -> V_36 ) ;
F_11 ( V_21 -> V_8 , V_21 , V_22 , V_35 ) ;
F_19 ( & V_22 -> V_34 ) ;
F_71 ( & V_21 -> V_8 -> V_15 ) ;
V_176 ++ ;
if ( ! V_311 &&
( V_312 == NULL ||
V_176 > V_314 ) )
break;
} while ( ! V_311 );
if ( V_312 )
F_71 ( & V_312 -> V_8 -> V_15 ) ;
return V_311 ;
}
static int F_290 ( struct V_7 * V_8 ,
int V_37 , int V_10 , enum V_65 V_100 )
{
struct V_38 * V_38 ;
struct V_6 * V_21 ;
struct V_101 * V_102 , * V_315 ;
unsigned long V_104 , V_176 ;
struct V_124 * V_316 ;
int V_67 = 0 ;
V_38 = & F_291 ( V_37 ) -> V_317 [ V_10 ] ;
V_21 = F_4 ( V_8 , V_37 , V_10 ) ;
V_316 = & V_21 -> V_103 [ V_100 ] ;
V_176 = F_48 ( V_21 , V_100 ) ;
V_176 += 256 ;
V_315 = NULL ;
while ( V_176 -- ) {
struct V_16 * V_16 ;
V_67 = 0 ;
F_99 ( & V_38 -> V_105 , V_104 ) ;
if ( F_81 ( V_316 ) ) {
F_100 ( & V_38 -> V_105 , V_104 ) ;
break;
}
V_102 = F_292 ( V_316 -> V_318 , struct V_101 , V_100 ) ;
if ( V_315 == V_102 ) {
F_90 ( & V_102 -> V_100 , V_316 ) ;
V_315 = NULL ;
F_100 ( & V_38 -> V_105 , V_104 ) ;
continue;
}
F_100 ( & V_38 -> V_105 , V_104 ) ;
V_16 = F_120 ( V_102 ) ;
V_67 = F_241 ( V_16 , V_102 , V_8 , V_301 ) ;
if ( V_67 == - V_255 )
break;
if ( V_67 == - V_137 || V_67 == - V_269 ) {
V_315 = V_102 ;
F_293 () ;
} else
V_315 = NULL ;
}
if ( ! V_67 && ! F_81 ( V_316 ) )
return - V_137 ;
return V_67 ;
}
static int F_294 ( struct V_7 * V_8 , bool V_319 )
{
int V_67 ;
int V_37 , V_10 , V_178 ;
int V_320 = V_251 ;
struct V_80 * V_141 = V_8 -> V_15 . V_80 ;
F_148 ( & V_8 -> V_15 ) ;
V_178 = 0 ;
if ( V_319 )
goto V_321;
V_322:
do {
V_67 = - V_137 ;
if ( F_295 ( V_141 ) || ! F_81 ( & V_141 -> V_305 ) )
goto V_97;
V_67 = - V_309 ;
if ( F_286 ( V_147 ) )
goto V_97;
F_296 () ;
F_209 ( V_8 ) ;
V_67 = 0 ;
F_128 ( V_8 ) ;
F_24 (node, N_HIGH_MEMORY) {
for ( V_10 = 0 ; ! V_67 && V_10 < V_39 ; V_10 ++ ) {
enum V_65 V_66 ;
F_46 (l) {
V_67 = F_290 ( V_8 ,
V_37 , V_10 , V_66 ) ;
if ( V_67 )
break;
}
}
if ( V_67 )
break;
}
F_130 ( V_8 ) ;
F_177 ( V_8 ) ;
if ( V_67 == - V_255 )
goto V_321;
F_293 () ;
} while ( V_8 -> V_36 . V_323 > 0 || V_67 );
V_97:
F_71 ( & V_8 -> V_15 ) ;
return V_67 ;
V_321:
if ( F_295 ( V_141 ) || ! F_81 ( & V_141 -> V_305 ) || V_178 ) {
V_67 = - V_137 ;
goto V_97;
}
F_296 () ;
V_178 = 1 ;
while ( V_320 && V_8 -> V_36 . V_323 > 0 ) {
int V_324 ;
if ( F_286 ( V_147 ) ) {
V_67 = - V_309 ;
goto V_97;
}
V_324 = F_166 ( V_8 , V_301 ,
false ) ;
if ( ! V_324 ) {
V_320 -- ;
F_297 ( V_325 , V_326 / 10 ) ;
}
}
F_298 () ;
goto V_322;
}
int F_299 ( struct V_80 * V_81 , unsigned int V_327 )
{
return F_294 ( F_59 ( V_81 ) , true ) ;
}
static T_1 F_300 ( struct V_80 * V_81 , struct V_328 * V_329 )
{
return F_59 ( V_81 ) -> V_89 ;
}
static int F_301 ( struct V_80 * V_81 , struct V_328 * V_329 ,
T_1 V_45 )
{
int V_330 = 0 ;
struct V_7 * V_8 = F_59 ( V_81 ) ;
struct V_80 * V_27 = V_81 -> V_27 ;
struct V_7 * V_331 = NULL ;
if ( V_27 )
V_331 = F_59 ( V_27 ) ;
F_302 () ;
if ( ( ! V_331 || ! V_331 -> V_89 ) &&
( V_45 == 1 || V_45 == 0 ) ) {
if ( F_81 ( & V_81 -> V_305 ) )
V_8 -> V_89 = V_45 ;
else
V_330 = - V_137 ;
} else
V_330 = - V_269 ;
F_303 () ;
return V_330 ;
}
static unsigned long F_304 ( struct V_7 * V_8 ,
enum V_43 V_44 )
{
struct V_7 * V_91 ;
long V_45 = 0 ;
F_145 (iter, mem)
V_45 += F_29 ( V_91 , V_44 ) ;
if ( V_45 < 0 )
V_45 = 0 ;
return V_45 ;
}
static inline T_1 F_305 ( struct V_7 * V_8 , bool V_332 )
{
T_1 V_45 ;
if ( ! F_72 ( V_8 ) ) {
if ( ! V_332 )
return F_143 ( & V_8 -> V_36 , V_157 ) ;
else
return F_143 ( & V_8 -> V_140 , V_157 ) ;
}
V_45 = F_304 ( V_8 , V_59 ) ;
V_45 += F_304 ( V_8 , V_60 ) ;
if ( V_332 )
V_45 += F_304 ( V_8 , V_52 ) ;
return V_45 << V_118 ;
}
static T_1 F_306 ( struct V_80 * V_81 , struct V_328 * V_329 )
{
struct V_7 * V_8 = F_59 ( V_81 ) ;
T_1 V_45 ;
int type , V_333 ;
type = F_307 ( V_329 -> V_200 ) ;
V_333 = F_308 ( V_329 -> V_200 ) ;
switch ( type ) {
case V_334 :
if ( V_333 == V_157 )
V_45 = F_305 ( V_8 , false ) ;
else
V_45 = F_143 ( & V_8 -> V_36 , V_333 ) ;
break;
case V_335 :
if ( V_333 == V_157 )
V_45 = F_305 ( V_8 , true ) ;
else
V_45 = F_143 ( & V_8 -> V_140 , V_333 ) ;
break;
default:
F_74 () ;
break;
}
return V_45 ;
}
static int F_309 ( struct V_80 * V_81 , struct V_328 * V_329 ,
const char * V_336 )
{
struct V_7 * V_110 = F_59 ( V_81 ) ;
int type , V_333 ;
unsigned long long V_45 ;
int V_67 ;
type = F_307 ( V_329 -> V_200 ) ;
V_333 = F_308 ( V_329 -> V_200 ) ;
switch ( V_333 ) {
case V_158 :
if ( F_72 ( V_110 ) ) {
V_67 = - V_269 ;
break;
}
V_67 = F_310 ( V_336 , & V_45 ) ;
if ( V_67 )
break;
if ( type == V_334 )
V_67 = F_285 ( V_110 , V_45 ) ;
else
V_67 = F_288 ( V_110 , V_45 ) ;
break;
case V_337 :
V_67 = F_310 ( V_336 , & V_45 ) ;
if ( V_67 )
break;
if ( type == V_334 )
V_67 = F_311 ( & V_110 -> V_36 , V_45 ) ;
else
V_67 = - V_269 ;
break;
default:
V_67 = - V_269 ;
break;
}
return V_67 ;
}
static void F_312 ( struct V_7 * V_110 ,
unsigned long long * V_338 , unsigned long long * V_339 )
{
struct V_80 * V_80 ;
unsigned long long V_340 , V_341 , V_135 ;
V_340 = F_143 ( & V_110 -> V_36 , V_158 ) ;
V_341 = F_143 ( & V_110 -> V_140 , V_158 ) ;
V_80 = V_110 -> V_15 . V_80 ;
if ( ! V_110 -> V_89 )
goto V_97;
while ( V_80 -> V_27 ) {
V_80 = V_80 -> V_27 ;
V_110 = F_59 ( V_80 ) ;
if ( ! V_110 -> V_89 )
break;
V_135 = F_143 ( & V_110 -> V_36 , V_158 ) ;
V_340 = F_126 ( V_340 , V_135 ) ;
V_135 = F_143 ( & V_110 -> V_140 , V_158 ) ;
V_341 = F_126 ( V_341 , V_135 ) ;
}
V_97:
* V_338 = V_340 ;
* V_339 = V_341 ;
return;
}
static int F_313 ( struct V_80 * V_81 , unsigned int V_327 )
{
struct V_7 * V_8 ;
int type , V_333 ;
V_8 = F_59 ( V_81 ) ;
type = F_307 ( V_327 ) ;
V_333 = F_308 ( V_327 ) ;
switch ( V_333 ) {
case V_342 :
if ( type == V_334 )
F_314 ( & V_8 -> V_36 ) ;
else
F_314 ( & V_8 -> V_140 ) ;
break;
case V_159 :
if ( type == V_334 )
F_315 ( & V_8 -> V_36 ) ;
else
F_315 ( & V_8 -> V_140 ) ;
break;
}
return 0 ;
}
static T_1 F_316 ( struct V_80 * V_141 ,
struct V_328 * V_329 )
{
return F_59 ( V_141 ) -> V_4 ;
}
static int F_317 ( struct V_80 * V_141 ,
struct V_328 * V_329 , T_1 V_45 )
{
struct V_7 * V_8 = F_59 ( V_141 ) ;
if ( V_45 >= ( 1 << V_343 ) )
return - V_269 ;
F_302 () ;
V_8 -> V_4 = V_45 ;
F_303 () ;
return 0 ;
}
static int F_317 ( struct V_80 * V_141 ,
struct V_328 * V_329 , T_1 V_45 )
{
return - V_344 ;
}
static void
F_318 ( struct V_7 * V_8 , struct V_345 * V_346 )
{
T_6 V_45 ;
V_45 = F_29 ( V_8 , V_59 ) ;
V_346 -> V_47 [ V_347 ] += V_45 * V_217 ;
V_45 = F_29 ( V_8 , V_60 ) ;
V_346 -> V_47 [ V_348 ] += V_45 * V_217 ;
V_45 = F_29 ( V_8 , V_210 ) ;
V_346 -> V_47 [ V_349 ] += V_45 * V_217 ;
V_45 = F_39 ( V_8 , V_61 ) ;
V_346 -> V_47 [ V_350 ] += V_45 ;
V_45 = F_39 ( V_8 , V_62 ) ;
V_346 -> V_47 [ V_351 ] += V_45 ;
if ( V_139 ) {
V_45 = F_29 ( V_8 , V_52 ) ;
V_346 -> V_47 [ V_352 ] += V_45 * V_217 ;
}
V_45 = F_39 ( V_8 , V_54 ) ;
V_346 -> V_47 [ V_353 ] += V_45 ;
V_45 = F_39 ( V_8 , V_55 ) ;
V_346 -> V_47 [ V_354 ] += V_45 ;
V_45 = F_50 ( V_8 , F_47 ( V_116 ) ) ;
V_346 -> V_47 [ V_355 ] += V_45 * V_217 ;
V_45 = F_50 ( V_8 , F_47 ( V_117 ) ) ;
V_346 -> V_47 [ V_356 ] += V_45 * V_217 ;
V_45 = F_50 ( V_8 , F_47 ( V_119 ) ) ;
V_346 -> V_47 [ V_357 ] += V_45 * V_217 ;
V_45 = F_50 ( V_8 , F_47 ( V_120 ) ) ;
V_346 -> V_47 [ V_358 ] += V_45 * V_217 ;
V_45 = F_50 ( V_8 , F_47 ( V_359 ) ) ;
V_346 -> V_47 [ V_360 ] += V_45 * V_217 ;
}
static void
F_319 ( struct V_7 * V_8 , struct V_345 * V_346 )
{
struct V_7 * V_91 ;
F_145 (iter, mem)
F_318 ( V_91 , V_346 ) ;
}
static int F_320 ( struct V_361 * V_362 , void * V_189 )
{
int V_9 ;
unsigned long V_363 , V_364 , V_365 , V_366 ;
unsigned long V_367 ;
struct V_80 * V_81 = V_362 -> V_200 ;
struct V_7 * V_130 = F_59 ( V_81 ) ;
V_363 = F_50 ( V_130 , V_368 ) ;
F_321 ( V_362 , L_9 , V_363 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_367 = F_49 ( V_130 , V_9 , V_368 ) ;
F_321 ( V_362 , L_10 , V_9 , V_367 ) ;
}
F_322 ( V_362 , '\n' ) ;
V_364 = F_50 ( V_130 , V_165 ) ;
F_321 ( V_362 , L_11 , V_364 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_367 = F_49 ( V_130 , V_9 ,
V_165 ) ;
F_321 ( V_362 , L_10 , V_9 , V_367 ) ;
}
F_322 ( V_362 , '\n' ) ;
V_365 = F_50 ( V_130 , V_166 ) ;
F_321 ( V_362 , L_12 , V_365 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_367 = F_49 ( V_130 , V_9 ,
V_166 ) ;
F_321 ( V_362 , L_10 , V_9 , V_367 ) ;
}
F_322 ( V_362 , '\n' ) ;
V_366 = F_50 ( V_130 , F_47 ( V_359 ) ) ;
F_321 ( V_362 , L_13 , V_366 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_367 = F_49 ( V_130 , V_9 ,
F_47 ( V_359 ) ) ;
F_321 ( V_362 , L_10 , V_9 , V_367 ) ;
}
F_322 ( V_362 , '\n' ) ;
return 0 ;
}
static int F_323 ( struct V_80 * V_81 , struct V_328 * V_329 ,
struct V_369 * V_370 )
{
struct V_7 * V_130 = F_59 ( V_81 ) ;
struct V_345 V_371 ;
int V_224 ;
memset ( & V_371 , 0 , sizeof( V_371 ) ) ;
F_318 ( V_130 , & V_371 ) ;
for ( V_224 = 0 ; V_224 < V_372 ; V_224 ++ ) {
if ( V_224 == V_352 && ! V_139 )
continue;
V_370 -> V_373 ( V_370 , V_374 [ V_224 ] . V_375 , V_371 . V_47 [ V_224 ] ) ;
}
{
unsigned long long V_161 , V_339 ;
F_312 ( V_130 , & V_161 , & V_339 ) ;
V_370 -> V_373 ( V_370 , L_14 , V_161 ) ;
if ( V_139 )
V_370 -> V_373 ( V_370 , L_15 , V_339 ) ;
}
memset ( & V_371 , 0 , sizeof( V_371 ) ) ;
F_319 ( V_130 , & V_371 ) ;
for ( V_224 = 0 ; V_224 < V_372 ; V_224 ++ ) {
if ( V_224 == V_352 && ! V_139 )
continue;
V_370 -> V_373 ( V_370 , V_374 [ V_224 ] . V_376 , V_371 . V_47 [ V_224 ] ) ;
}
#ifdef F_324
V_370 -> V_373 ( V_370 , L_16 , F_108 ( V_130 , NULL ) ) ;
{
int V_9 , V_10 ;
struct V_6 * V_21 ;
unsigned long V_377 [ 2 ] = { 0 , 0 } ;
unsigned long V_378 [ 2 ] = { 0 , 0 } ;
F_325 (nid)
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ ) {
V_21 = F_4 ( V_130 , V_9 , V_10 ) ;
V_377 [ 0 ] +=
V_21 -> V_122 . V_377 [ 0 ] ;
V_377 [ 1 ] +=
V_21 -> V_122 . V_377 [ 1 ] ;
V_378 [ 0 ] +=
V_21 -> V_122 . V_378 [ 0 ] ;
V_378 [ 1 ] +=
V_21 -> V_122 . V_378 [ 1 ] ;
}
V_370 -> V_373 ( V_370 , L_17 , V_377 [ 0 ] ) ;
V_370 -> V_373 ( V_370 , L_18 , V_377 [ 1 ] ) ;
V_370 -> V_373 ( V_370 , L_19 , V_378 [ 0 ] ) ;
V_370 -> V_373 ( V_370 , L_20 , V_378 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_326 ( struct V_80 * V_141 , struct V_328 * V_329 )
{
struct V_7 * V_110 = F_59 ( V_141 ) ;
return F_127 ( V_110 ) ;
}
static int F_327 ( struct V_80 * V_141 , struct V_328 * V_329 ,
T_1 V_45 )
{
struct V_7 * V_110 = F_59 ( V_141 ) ;
struct V_7 * V_27 ;
if ( V_45 > 100 )
return - V_269 ;
if ( V_141 -> V_27 == NULL )
return - V_269 ;
V_27 = F_59 ( V_141 -> V_27 ) ;
F_302 () ;
if ( ( V_27 -> V_89 ) ||
( V_110 -> V_89 && ! F_81 ( & V_141 -> V_305 ) ) ) {
F_303 () ;
return - V_269 ;
}
V_110 -> V_143 = V_45 ;
F_303 () ;
return 0 ;
}
static void F_328 ( struct V_7 * V_110 , bool V_332 )
{
struct V_379 * V_380 ;
T_1 V_323 ;
int V_224 ;
F_64 () ;
if ( ! V_332 )
V_380 = F_65 ( V_110 -> V_381 . V_382 ) ;
else
V_380 = F_65 ( V_110 -> V_383 . V_382 ) ;
if ( ! V_380 )
goto V_145;
V_323 = F_305 ( V_110 , V_332 ) ;
V_224 = V_380 -> V_384 ;
for (; V_224 >= 0 && F_56 ( V_380 -> V_385 [ V_224 ] . V_386 > V_323 ) ; V_224 -- )
F_329 ( V_380 -> V_385 [ V_224 ] . V_387 , 1 ) ;
V_224 ++ ;
for (; V_224 < V_380 -> V_388 && F_56 ( V_380 -> V_385 [ V_224 ] . V_386 <= V_323 ) ; V_224 ++ )
F_329 ( V_380 -> V_385 [ V_224 ] . V_387 , 1 ) ;
V_380 -> V_384 = V_224 - 1 ;
V_145:
F_66 () ;
}
static void F_57 ( struct V_7 * V_110 )
{
while ( V_110 ) {
F_328 ( V_110 , false ) ;
if ( V_139 )
F_328 ( V_110 , true ) ;
V_110 = F_21 ( V_110 ) ;
}
}
static int F_330 ( const void * V_389 , const void * V_390 )
{
const struct F_57 * V_391 = V_389 ;
const struct F_57 * V_392 = V_390 ;
return V_391 -> V_386 - V_392 -> V_386 ;
}
static int F_331 ( struct V_7 * V_8 )
{
struct V_393 * V_394 ;
F_332 (ev, &mem->oom_notify, list)
F_329 ( V_394 -> V_387 , 1 ) ;
return 0 ;
}
static void F_180 ( struct V_7 * V_8 )
{
struct V_7 * V_91 ;
F_145 (iter, mem)
F_331 ( V_91 ) ;
}
static int F_333 ( struct V_80 * V_141 ,
struct V_328 * V_329 , struct V_395 * V_387 , const char * args )
{
struct V_7 * V_110 = F_59 ( V_141 ) ;
struct V_396 * V_381 ;
struct V_379 * V_397 ;
int type = F_307 ( V_329 -> V_200 ) ;
T_1 V_386 , V_323 ;
int V_224 , V_388 , V_67 ;
V_67 = F_310 ( args , & V_386 ) ;
if ( V_67 )
return V_67 ;
F_210 ( & V_110 -> V_398 ) ;
if ( type == V_334 )
V_381 = & V_110 -> V_381 ;
else if ( type == V_335 )
V_381 = & V_110 -> V_383 ;
else
F_74 () ;
V_323 = F_305 ( V_110 , type == V_335 ) ;
if ( V_381 -> V_382 )
F_328 ( V_110 , type == V_335 ) ;
V_388 = V_381 -> V_382 ? V_381 -> V_382 -> V_388 + 1 : 1 ;
V_397 = F_283 ( sizeof( * V_397 ) + V_388 * sizeof( struct F_57 ) ,
V_301 ) ;
if ( ! V_397 ) {
V_67 = - V_255 ;
goto V_145;
}
V_397 -> V_388 = V_388 ;
if ( V_381 -> V_382 ) {
memcpy ( V_397 -> V_385 , V_381 -> V_382 -> V_385 , ( V_388 - 1 ) *
sizeof( struct F_57 ) ) ;
}
V_397 -> V_385 [ V_388 - 1 ] . V_387 = V_387 ;
V_397 -> V_385 [ V_388 - 1 ] . V_386 = V_386 ;
F_334 ( V_397 -> V_385 , V_388 , sizeof( struct F_57 ) ,
F_330 , NULL ) ;
V_397 -> V_384 = - 1 ;
for ( V_224 = 0 ; V_224 < V_388 ; V_224 ++ ) {
if ( V_397 -> V_385 [ V_224 ] . V_386 < V_323 ) {
++ V_397 -> V_384 ;
}
}
F_284 ( V_381 -> V_399 ) ;
V_381 -> V_399 = V_381 -> V_382 ;
F_335 ( V_381 -> V_382 , V_397 ) ;
F_129 () ;
V_145:
F_208 ( & V_110 -> V_398 ) ;
return V_67 ;
}
static void F_336 ( struct V_80 * V_141 ,
struct V_328 * V_329 , struct V_395 * V_387 )
{
struct V_7 * V_110 = F_59 ( V_141 ) ;
struct V_396 * V_381 ;
struct V_379 * V_397 ;
int type = F_307 ( V_329 -> V_200 ) ;
T_1 V_323 ;
int V_224 , V_400 , V_388 ;
F_210 ( & V_110 -> V_398 ) ;
if ( type == V_334 )
V_381 = & V_110 -> V_381 ;
else if ( type == V_335 )
V_381 = & V_110 -> V_383 ;
else
F_74 () ;
F_118 ( ! V_381 ) ;
V_323 = F_305 ( V_110 , type == V_335 ) ;
F_328 ( V_110 , type == V_335 ) ;
V_388 = 0 ;
for ( V_224 = 0 ; V_224 < V_381 -> V_382 -> V_388 ; V_224 ++ ) {
if ( V_381 -> V_382 -> V_385 [ V_224 ] . V_387 != V_387 )
V_388 ++ ;
}
V_397 = V_381 -> V_399 ;
if ( ! V_388 ) {
F_284 ( V_397 ) ;
V_397 = NULL ;
goto V_401;
}
V_397 -> V_388 = V_388 ;
V_397 -> V_384 = - 1 ;
for ( V_224 = 0 , V_400 = 0 ; V_224 < V_381 -> V_382 -> V_388 ; V_224 ++ ) {
if ( V_381 -> V_382 -> V_385 [ V_224 ] . V_387 == V_387 )
continue;
V_397 -> V_385 [ V_400 ] = V_381 -> V_382 -> V_385 [ V_224 ] ;
if ( V_397 -> V_385 [ V_400 ] . V_386 < V_323 ) {
++ V_397 -> V_384 ;
}
V_400 ++ ;
}
V_401:
V_381 -> V_399 = V_381 -> V_382 ;
F_335 ( V_381 -> V_382 , V_397 ) ;
F_129 () ;
F_208 ( & V_110 -> V_398 ) ;
}
static int F_337 ( struct V_80 * V_141 ,
struct V_328 * V_329 , struct V_395 * V_387 , const char * args )
{
struct V_7 * V_110 = F_59 ( V_141 ) ;
struct V_393 * V_327 ;
int type = F_307 ( V_329 -> V_200 ) ;
F_118 ( type != V_402 ) ;
V_327 = F_283 ( sizeof( * V_327 ) , V_301 ) ;
if ( ! V_327 )
return - V_255 ;
F_18 ( & V_202 ) ;
V_327 -> V_387 = V_387 ;
F_94 ( & V_327 -> V_316 , & V_110 -> V_403 ) ;
if ( F_151 ( & V_110 -> V_187 ) )
F_329 ( V_387 , 1 ) ;
F_19 ( & V_202 ) ;
return 0 ;
}
static void F_338 ( struct V_80 * V_141 ,
struct V_328 * V_329 , struct V_395 * V_387 )
{
struct V_7 * V_8 = F_59 ( V_141 ) ;
struct V_393 * V_394 , * V_135 ;
int type = F_307 ( V_329 -> V_200 ) ;
F_118 ( type != V_402 ) ;
F_18 ( & V_202 ) ;
F_339 (ev, tmp, &mem->oom_notify, list) {
if ( V_394 -> V_387 == V_387 ) {
F_340 ( & V_394 -> V_316 ) ;
F_284 ( V_394 ) ;
}
}
F_19 ( & V_202 ) ;
}
static int F_341 ( struct V_80 * V_141 ,
struct V_328 * V_329 , struct V_369 * V_370 )
{
struct V_7 * V_8 = F_59 ( V_141 ) ;
V_370 -> V_373 ( V_370 , L_21 , V_8 -> V_204 ) ;
if ( F_151 ( & V_8 -> V_187 ) )
V_370 -> V_373 ( V_370 , L_22 , 1 ) ;
else
V_370 -> V_373 ( V_370 , L_22 , 0 ) ;
return 0 ;
}
static int F_342 ( struct V_80 * V_141 ,
struct V_328 * V_329 , T_1 V_45 )
{
struct V_7 * V_8 = F_59 ( V_141 ) ;
struct V_7 * V_27 ;
if ( ! V_141 -> V_27 || ! ( ( V_45 == 0 ) || ( V_45 == 1 ) ) )
return - V_269 ;
V_27 = F_59 ( V_141 -> V_27 ) ;
F_302 () ;
if ( ( V_27 -> V_89 ) ||
( V_8 -> V_89 && ! F_81 ( & V_141 -> V_305 ) ) ) {
F_303 () ;
return - V_269 ;
}
V_8 -> V_204 = V_45 ;
if ( ! V_45 )
F_177 ( V_8 ) ;
F_303 () ;
return 0 ;
}
static int F_343 ( struct V_404 * V_297 , struct V_57 * V_57 )
{
struct V_80 * V_81 = V_57 -> V_405 -> V_406 -> V_407 ;
V_57 -> V_408 = & V_409 ;
return F_344 ( V_57 , F_320 , V_81 ) ;
}
static int F_345 ( struct V_80 * V_81 , struct V_410 * V_411 )
{
if ( ! V_139 )
return 0 ;
return F_346 ( V_81 , V_411 , V_412 ,
F_347 ( V_412 ) ) ;
}
static int F_345 ( struct V_80 * V_81 , struct V_410 * V_411 )
{
return 0 ;
}
static int F_348 ( struct V_7 * V_8 , int V_37 )
{
struct V_413 * V_414 ;
struct V_6 * V_21 ;
enum V_65 V_66 ;
int V_38 , V_135 = V_37 ;
if ( ! F_349 ( V_37 , V_415 ) )
V_135 = - 1 ;
V_414 = F_350 ( sizeof( * V_414 ) , V_301 , V_135 ) ;
if ( ! V_414 )
return 1 ;
V_8 -> V_11 . V_12 [ V_37 ] = V_414 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_21 = & V_414 -> V_13 [ V_38 ] ;
F_46 (l)
F_179 ( & V_21 -> V_103 [ V_66 ] ) ;
V_21 -> V_30 = 0 ;
V_21 -> V_29 = false ;
V_21 -> V_8 = V_8 ;
}
return 0 ;
}
static void F_351 ( struct V_7 * V_8 , int V_37 )
{
F_284 ( V_8 -> V_11 . V_12 [ V_37 ] ) ;
}
static struct V_7 * F_352 ( void )
{
struct V_7 * V_8 ;
int V_388 = sizeof( struct V_7 ) ;
if ( V_388 < V_217 )
V_8 = F_353 ( V_388 , V_301 ) ;
else
V_8 = F_354 ( V_388 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_47 = F_355 ( struct V_416 ) ;
if ( ! V_8 -> V_47 )
goto V_417;
F_356 ( & V_8 -> V_49 ) ;
return V_8 ;
V_417:
if ( V_388 < V_217 )
F_284 ( V_8 ) ;
else
F_357 ( V_8 ) ;
return NULL ;
}
static void F_358 ( struct V_7 * V_8 )
{
int V_37 ;
F_23 ( V_8 ) ;
F_359 ( & V_90 , & V_8 -> V_15 ) ;
F_24 (node, N_POSSIBLE)
F_351 ( V_8 , V_37 ) ;
F_360 ( V_8 -> V_47 ) ;
if ( sizeof( struct V_7 ) < V_217 )
F_284 ( V_8 ) ;
else
F_357 ( V_8 ) ;
}
static void F_267 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_418 ) ;
}
static void F_361 ( struct V_7 * V_8 , int V_48 )
{
if ( F_362 ( V_48 , & V_8 -> V_418 ) ) {
struct V_7 * V_27 = F_21 ( V_8 ) ;
F_358 ( V_8 ) ;
if ( V_27 )
F_259 ( V_27 ) ;
}
}
static void F_259 ( struct V_7 * V_8 )
{
F_361 ( V_8 , 1 ) ;
}
static struct V_7 * F_21 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_36 . V_27 )
return NULL ;
return F_217 ( V_8 -> V_36 . V_27 , V_36 ) ;
}
static void T_7 F_363 ( void )
{
if ( ! F_76 () && V_419 )
V_139 = 1 ;
}
static void T_7 F_363 ( void )
{
}
static int F_364 ( void )
{
struct V_420 * V_421 ;
struct V_17 * V_422 ;
int V_135 , V_37 , V_38 ;
F_24 (node, N_POSSIBLE) {
V_135 = V_37 ;
if ( ! F_349 ( V_37 , V_415 ) )
V_135 = - 1 ;
V_421 = F_350 ( sizeof( * V_421 ) , V_301 , V_135 ) ;
if ( ! V_421 )
return 1 ;
V_18 . V_19 [ V_37 ] = V_421 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_422 = & V_421 -> V_20 [ V_38 ] ;
V_422 -> V_26 = V_423 ;
F_356 ( & V_422 -> V_34 ) ;
}
}
return 0 ;
}
static struct V_14 * T_8
F_365 ( struct V_410 * V_411 , struct V_80 * V_81 )
{
struct V_7 * V_8 , * V_27 ;
long error = - V_255 ;
int V_37 ;
V_8 = F_352 () ;
if ( ! V_8 )
return F_366 ( error ) ;
F_24 (node, N_POSSIBLE)
if ( F_348 ( V_8 , V_37 ) )
goto V_424;
if ( V_81 -> V_27 == NULL ) {
int V_46 ;
F_363 () ;
V_27 = NULL ;
V_88 = V_8 ;
if ( F_364 () )
goto V_424;
F_367 (cpu) {
struct V_211 * V_212 =
& F_32 ( V_213 , V_46 ) ;
F_368 ( & V_212 -> V_222 , F_197 ) ;
}
F_369 ( F_213 , 0 ) ;
} else {
V_27 = F_59 ( V_81 -> V_27 ) ;
V_8 -> V_89 = V_27 -> V_89 ;
V_8 -> V_204 = V_27 -> V_204 ;
}
if ( V_27 && V_27 -> V_89 ) {
F_370 ( & V_8 -> V_36 , & V_27 -> V_36 ) ;
F_370 ( & V_8 -> V_140 , & V_27 -> V_140 ) ;
F_267 ( V_27 ) ;
} else {
F_370 ( & V_8 -> V_36 , NULL ) ;
F_370 ( & V_8 -> V_140 , NULL ) ;
}
V_8 -> V_163 = 0 ;
V_8 -> V_171 = V_78 ;
F_179 ( & V_8 -> V_403 ) ;
if ( V_27 )
V_8 -> V_143 = F_127 ( V_27 ) ;
F_155 ( & V_8 -> V_418 , 1 ) ;
V_8 -> V_4 = 0 ;
F_371 ( & V_8 -> V_398 ) ;
return & V_8 -> V_15 ;
V_424:
F_358 ( V_8 ) ;
V_88 = NULL ;
return F_366 ( error ) ;
}
static int F_372 ( struct V_410 * V_411 ,
struct V_80 * V_81 )
{
struct V_7 * V_8 = F_59 ( V_81 ) ;
return F_294 ( V_8 , false ) ;
}
static void F_373 ( struct V_410 * V_411 ,
struct V_80 * V_81 )
{
struct V_7 * V_8 = F_59 ( V_81 ) ;
F_259 ( V_8 ) ;
}
static int F_374 ( struct V_410 * V_411 ,
struct V_80 * V_81 )
{
int V_67 ;
V_67 = F_346 ( V_81 , V_411 , V_425 ,
F_347 ( V_425 ) ) ;
if ( ! V_67 )
V_67 = F_345 ( V_81 , V_411 ) ;
return V_67 ;
}
static int F_375 ( unsigned long V_48 )
{
int V_67 = 0 ;
int V_426 = V_427 ;
struct V_7 * V_8 = V_2 . V_3 ;
if ( F_72 ( V_8 ) ) {
V_2 . V_428 += V_48 ;
return V_67 ;
}
if ( V_48 > 1 ) {
struct V_239 * V_219 ;
if ( F_216 ( & V_8 -> V_36 , V_217 * V_48 , & V_219 ) )
goto V_429;
if ( V_139 && F_216 ( & V_8 -> V_140 ,
V_217 * V_48 , & V_219 ) ) {
F_196 ( & V_8 -> V_36 , V_217 * V_48 ) ;
goto V_429;
}
V_2 . V_428 += V_48 ;
return V_67 ;
}
V_429:
while ( V_48 -- ) {
if ( F_286 ( V_147 ) ) {
V_67 = - V_309 ;
break;
}
if ( ! V_426 -- ) {
V_426 = V_427 ;
F_293 () ;
}
V_67 = F_218 ( NULL , V_301 , 1 , & V_8 , false ) ;
if ( V_67 || ! V_8 )
return - V_255 ;
V_2 . V_428 ++ ;
}
return V_67 ;
}
static struct V_16 * F_376 ( struct V_430 * V_431 ,
unsigned long V_432 , T_9 V_433 )
{
struct V_16 * V_16 = F_377 ( V_431 , V_432 , V_433 ) ;
if ( ! V_16 || ! F_189 ( V_16 ) )
return NULL ;
if ( F_250 ( V_16 ) ) {
if ( ! F_1 () || F_378 ( V_16 ) > 2 )
return NULL ;
} else if ( ! F_3 () )
return NULL ;
if ( ! F_242 ( V_16 ) )
return NULL ;
return V_16 ;
}
static struct V_16 * F_379 ( struct V_430 * V_431 ,
unsigned long V_432 , T_9 V_433 , T_5 * V_289 )
{
int V_434 ;
struct V_16 * V_16 = NULL ;
T_5 V_257 = F_380 ( V_433 ) ;
if ( ! F_1 () || F_381 ( V_257 ) )
return NULL ;
V_434 = F_382 ( V_257 , & V_16 ) ;
if ( V_434 > 1 ) {
if ( V_16 )
F_247 ( V_16 ) ;
return NULL ;
}
if ( V_139 )
V_289 -> V_45 = V_257 . V_45 ;
return V_16 ;
}
static struct V_16 * F_383 ( struct V_430 * V_431 ,
unsigned long V_432 , T_9 V_433 , T_5 * V_289 )
{
struct V_16 * V_16 = NULL ;
struct V_404 * V_404 ;
struct V_435 * V_275 ;
T_10 V_436 ;
if ( ! V_431 -> V_437 )
return NULL ;
if ( ! F_3 () )
return NULL ;
V_404 = V_431 -> V_437 -> V_438 . V_439 -> V_440 ;
V_275 = V_431 -> V_437 -> V_441 ;
if ( F_384 ( V_433 ) )
V_436 = F_385 ( V_431 , V_432 ) ;
else
V_436 = F_386 ( V_433 ) ;
V_16 = F_387 ( V_275 , V_436 ) ;
#ifdef F_388
if ( F_389 ( V_16 ) ) {
T_5 V_332 = F_390 ( V_16 ) ;
if ( V_139 )
* V_289 = V_332 ;
V_16 = F_387 ( & V_442 , V_332 . V_45 ) ;
}
#endif
return V_16 ;
}
static int F_391 ( struct V_430 * V_431 ,
unsigned long V_432 , T_9 V_433 , union V_443 * V_69 )
{
struct V_16 * V_16 = NULL ;
struct V_101 * V_102 ;
int V_67 = 0 ;
T_5 V_257 = { . V_45 = 0 } ;
if ( F_392 ( V_433 ) )
V_16 = F_376 ( V_431 , V_432 , V_433 ) ;
else if ( F_393 ( V_433 ) )
V_16 = F_379 ( V_431 , V_432 , V_433 , & V_257 ) ;
else if ( F_384 ( V_433 ) || F_394 ( V_433 ) )
V_16 = F_383 ( V_431 , V_432 , V_433 , & V_257 ) ;
if ( ! V_16 && ! V_257 . V_45 )
return 0 ;
if ( V_16 ) {
V_102 = F_77 ( V_16 ) ;
if ( F_86 ( V_102 ) && V_102 -> V_7 == V_2 . V_106 ) {
V_67 = V_444 ;
if ( V_69 )
V_69 -> V_16 = V_16 ;
}
if ( ! V_67 || ! V_69 )
F_247 ( V_16 ) ;
}
if ( V_257 . V_45 && ! V_67 &&
F_70 ( & V_2 . V_106 -> V_15 ) == F_229 ( V_257 ) ) {
V_67 = V_445 ;
if ( V_69 )
V_69 -> V_257 = V_257 ;
}
return V_67 ;
}
static int F_395 ( T_11 * V_446 ,
unsigned long V_432 , unsigned long V_447 ,
struct V_448 * V_449 )
{
struct V_430 * V_431 = V_449 -> V_200 ;
T_9 * V_450 ;
T_12 * V_451 ;
F_396 ( V_449 -> V_85 , V_446 ) ;
V_450 = F_397 ( V_431 -> V_452 , V_446 , V_432 , & V_451 ) ;
for (; V_432 != V_447 ; V_450 ++ , V_432 += V_217 )
if ( F_391 ( V_431 , V_432 , * V_450 , NULL ) )
V_2 . V_428 ++ ;
F_398 ( V_450 - 1 , V_451 ) ;
F_293 () ;
return 0 ;
}
static unsigned long F_399 ( struct V_84 * V_85 )
{
unsigned long V_428 ;
struct V_430 * V_431 ;
F_400 ( & V_85 -> V_453 ) ;
for ( V_431 = V_85 -> V_454 ; V_431 ; V_431 = V_431 -> V_455 ) {
struct V_448 V_456 = {
. V_457 = F_395 ,
. V_85 = V_85 ,
. V_200 = V_431 ,
} ;
if ( F_401 ( V_431 ) )
continue;
F_402 ( V_431 -> V_458 , V_431 -> V_459 ,
& V_456 ) ;
}
F_403 ( & V_85 -> V_453 ) ;
V_428 = V_2 . V_428 ;
V_2 . V_428 = 0 ;
return V_428 ;
}
static int F_404 ( struct V_84 * V_85 )
{
unsigned long V_428 = F_399 ( V_85 ) ;
F_79 ( V_2 . V_146 ) ;
V_2 . V_146 = V_147 ;
return F_375 ( V_428 ) ;
}
static void F_405 ( void )
{
struct V_7 * V_106 = V_2 . V_106 ;
struct V_7 * V_3 = V_2 . V_3 ;
if ( V_2 . V_428 ) {
F_221 ( V_2 . V_3 , V_2 . V_428 ) ;
V_2 . V_428 = 0 ;
}
if ( V_2 . V_460 ) {
F_221 ( V_2 . V_106 , V_2 . V_460 ) ;
V_2 . V_460 = 0 ;
}
if ( V_2 . V_461 ) {
if ( ! F_72 ( V_2 . V_106 ) )
F_196 ( & V_2 . V_106 -> V_140 ,
V_217 * V_2 . V_461 ) ;
F_361 ( V_2 . V_106 , V_2 . V_461 ) ;
if ( ! F_72 ( V_2 . V_3 ) ) {
F_196 ( & V_2 . V_3 -> V_36 ,
V_217 * V_2 . V_461 ) ;
}
V_2 . V_461 = 0 ;
}
F_177 ( V_106 ) ;
F_177 ( V_3 ) ;
F_406 ( & V_2 . V_149 ) ;
}
static void F_407 ( void )
{
struct V_7 * V_106 = V_2 . V_106 ;
V_2 . V_146 = NULL ;
F_405 () ;
F_18 ( & V_2 . V_34 ) ;
V_2 . V_106 = NULL ;
V_2 . V_3 = NULL ;
F_19 ( & V_2 . V_34 ) ;
F_130 ( V_106 ) ;
}
static int F_408 ( struct V_410 * V_411 ,
struct V_80 * V_80 ,
struct V_83 * V_25 )
{
int V_67 = 0 ;
struct V_7 * V_8 = F_59 ( V_80 ) ;
if ( V_8 -> V_4 ) {
struct V_84 * V_85 ;
struct V_7 * V_106 = F_61 ( V_25 ) ;
F_79 ( V_106 == V_8 ) ;
V_85 = F_409 ( V_25 ) ;
if ( ! V_85 )
return 0 ;
if ( V_85 -> V_86 == V_25 ) {
F_79 ( V_2 . V_106 ) ;
F_79 ( V_2 . V_3 ) ;
F_79 ( V_2 . V_428 ) ;
F_79 ( V_2 . V_460 ) ;
F_79 ( V_2 . V_461 ) ;
F_128 ( V_106 ) ;
F_18 ( & V_2 . V_34 ) ;
V_2 . V_106 = V_106 ;
V_2 . V_3 = V_8 ;
F_19 ( & V_2 . V_34 ) ;
V_67 = F_404 ( V_85 ) ;
if ( V_67 )
F_407 () ;
}
F_410 ( V_85 ) ;
}
return V_67 ;
}
static void F_411 ( struct V_410 * V_411 ,
struct V_80 * V_80 ,
struct V_83 * V_25 )
{
F_407 () ;
}
static int F_412 ( T_11 * V_446 ,
unsigned long V_432 , unsigned long V_447 ,
struct V_448 * V_449 )
{
int V_67 = 0 ;
struct V_430 * V_431 = V_449 -> V_200 ;
T_9 * V_450 ;
T_12 * V_451 ;
F_396 ( V_449 -> V_85 , V_446 ) ;
V_41:
V_450 = F_397 ( V_431 -> V_452 , V_446 , V_432 , & V_451 ) ;
for (; V_432 != V_447 ; V_432 += V_217 ) {
T_9 V_433 = * ( V_450 ++ ) ;
union V_443 V_69 ;
int type ;
struct V_16 * V_16 ;
struct V_101 * V_102 ;
T_5 V_257 ;
if ( ! V_2 . V_428 )
break;
type = F_391 ( V_431 , V_432 , V_433 , & V_69 ) ;
switch ( type ) {
case V_444 :
V_16 = V_69 . V_16 ;
if ( F_243 ( V_16 ) )
goto V_273;
V_102 = F_77 ( V_16 ) ;
if ( ! F_238 ( V_16 , 1 , V_102 ,
V_2 . V_106 , V_2 . V_3 , false ) ) {
V_2 . V_428 -- ;
V_2 . V_460 ++ ;
}
F_246 ( V_16 ) ;
V_273:
F_247 ( V_16 ) ;
break;
case V_445 :
V_257 = V_69 . V_257 ;
if ( ! F_274 ( V_257 ,
V_2 . V_106 , V_2 . V_3 , false ) ) {
V_2 . V_428 -- ;
V_2 . V_461 ++ ;
}
break;
default:
break;
}
}
F_398 ( V_450 - 1 , V_451 ) ;
F_293 () ;
if ( V_432 != V_447 ) {
V_67 = F_375 ( 1 ) ;
if ( ! V_67 )
goto V_41;
}
return V_67 ;
}
static void F_413 ( struct V_84 * V_85 )
{
struct V_430 * V_431 ;
F_296 () ;
V_41:
if ( F_56 ( ! F_414 ( & V_85 -> V_453 ) ) ) {
F_405 () ;
F_293 () ;
goto V_41;
}
for ( V_431 = V_85 -> V_454 ; V_431 ; V_431 = V_431 -> V_455 ) {
int V_67 ;
struct V_448 V_462 = {
. V_457 = F_412 ,
. V_85 = V_85 ,
. V_200 = V_431 ,
} ;
if ( F_401 ( V_431 ) )
continue;
V_67 = F_402 ( V_431 -> V_458 , V_431 -> V_459 ,
& V_462 ) ;
if ( V_67 )
break;
}
F_403 ( & V_85 -> V_453 ) ;
}
static void F_415 ( struct V_410 * V_411 ,
struct V_80 * V_81 ,
struct V_80 * V_463 ,
struct V_83 * V_25 )
{
struct V_84 * V_85 = F_409 ( V_25 ) ;
if ( V_85 ) {
if ( V_2 . V_3 )
F_413 ( V_85 ) ;
F_416 ( V_85 ) ;
F_410 ( V_85 ) ;
}
if ( V_2 . V_3 )
F_407 () ;
}
static int F_408 ( struct V_410 * V_411 ,
struct V_80 * V_80 ,
struct V_83 * V_25 )
{
return 0 ;
}
static void F_411 ( struct V_410 * V_411 ,
struct V_80 * V_80 ,
struct V_83 * V_25 )
{
}
static void F_415 ( struct V_410 * V_411 ,
struct V_80 * V_81 ,
struct V_80 * V_463 ,
struct V_83 * V_25 )
{
}
static int T_7 F_417 ( char * V_346 )
{
if ( ! strcmp ( V_346 , L_23 ) )
V_419 = 1 ;
else if ( ! strcmp ( V_346 , L_24 ) )
V_419 = 0 ;
return 1 ;
}
