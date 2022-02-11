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
F_15 ( V_21 -> V_43 , V_21 , V_22 ) ;
if ( ! F_22 ( & V_21 -> V_43 -> V_36 ) ||
! F_27 ( & V_21 -> V_43 -> V_15 ) )
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
enum V_44 V_45 )
{
long V_46 = 0 ;
int V_47 ;
F_30 () ;
F_31 (cpu)
V_46 += F_32 ( V_8 -> V_48 -> V_49 [ V_45 ] , V_47 ) ;
#ifdef F_33
F_18 ( & V_8 -> V_50 ) ;
V_46 += V_8 -> V_51 . V_49 [ V_45 ] ;
F_19 ( & V_8 -> V_50 ) ;
#endif
F_34 () ;
return V_46 ;
}
static void F_35 ( struct V_7 * V_8 ,
bool V_52 )
{
int V_46 = ( V_52 ) ? 1 : - 1 ;
F_36 ( V_8 -> V_48 -> V_49 [ V_53 ] , V_46 ) ;
}
void F_37 ( struct V_7 * V_8 , int V_46 )
{
F_36 ( V_8 -> V_48 -> V_54 [ V_55 ] , V_46 ) ;
}
void F_38 ( struct V_7 * V_8 , int V_46 )
{
F_36 ( V_8 -> V_48 -> V_54 [ V_56 ] , V_46 ) ;
}
static unsigned long F_39 ( struct V_7 * V_8 ,
enum V_57 V_45 )
{
unsigned long V_46 = 0 ;
int V_47 ;
F_31 (cpu)
V_46 += F_32 ( V_8 -> V_48 -> V_54 [ V_45 ] , V_47 ) ;
#ifdef F_33
F_18 ( & V_8 -> V_50 ) ;
V_46 += V_8 -> V_51 . V_54 [ V_45 ] ;
F_19 ( & V_8 -> V_50 ) ;
#endif
return V_46 ;
}
static void F_40 ( struct V_7 * V_8 ,
bool V_58 , int V_59 )
{
F_41 () ;
if ( V_58 )
F_42 ( V_8 -> V_48 -> V_49 [ V_60 ] ,
V_59 ) ;
else
F_42 ( V_8 -> V_48 -> V_49 [ V_61 ] ,
V_59 ) ;
if ( V_59 > 0 )
F_43 ( V_8 -> V_48 -> V_54 [ V_62 ] ) ;
else {
F_43 ( V_8 -> V_48 -> V_54 [ V_63 ] ) ;
V_59 = - V_59 ;
}
F_42 ( V_8 -> V_48 -> V_54 [ V_64 ] , V_59 ) ;
F_44 () ;
}
unsigned long
F_45 ( struct V_7 * V_8 , int V_9 , int V_10 ,
unsigned int V_65 )
{
struct V_6 * V_21 ;
enum V_66 V_67 ;
unsigned long V_68 = 0 ;
V_21 = F_4 ( V_8 , V_9 , V_10 ) ;
F_46 (l) {
if ( F_47 ( V_67 ) & V_65 )
V_68 += F_48 ( V_21 , V_67 ) ;
}
return V_68 ;
}
static unsigned long
F_49 ( struct V_7 * V_8 ,
int V_9 , unsigned int V_65 )
{
T_1 V_69 = 0 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ )
V_69 += F_45 ( V_8 ,
V_9 , V_10 , V_65 ) ;
return V_69 ;
}
static unsigned long F_50 ( struct V_7 * V_8 ,
unsigned int V_65 )
{
int V_9 ;
T_1 V_69 = 0 ;
F_24 (nid, N_HIGH_MEMORY)
V_69 += F_49 ( V_8 , V_9 , V_65 ) ;
return V_69 ;
}
static bool F_51 ( struct V_7 * V_8 , int V_70 )
{
unsigned long V_46 , V_71 ;
V_46 = F_52 ( V_8 -> V_48 -> V_54 [ V_64 ] ) ;
V_71 = F_52 ( V_8 -> V_48 -> V_72 [ V_70 ] ) ;
return ( ( long ) V_71 - ( long ) V_46 < 0 ) ;
}
static void F_53 ( struct V_7 * V_8 , int V_70 )
{
unsigned long V_46 , V_71 ;
V_46 = F_52 ( V_8 -> V_48 -> V_54 [ V_64 ] ) ;
switch ( V_70 ) {
case V_73 :
V_71 = V_46 + V_74 ;
break;
case V_75 :
V_71 = V_46 + V_76 ;
break;
case V_77 :
V_71 = V_46 + V_78 ;
break;
default:
return;
}
F_54 ( V_8 -> V_48 -> V_72 [ V_70 ] , V_71 ) ;
}
static void F_55 ( struct V_7 * V_8 , struct V_16 * V_16 )
{
F_41 () ;
if ( F_56 ( F_51 ( V_8 , V_73 ) ) ) {
F_57 ( V_8 ) ;
F_53 ( V_8 , V_73 ) ;
if ( F_56 ( F_51 ( V_8 ,
V_75 ) ) ) {
F_20 ( V_8 , V_16 ) ;
F_53 ( V_8 ,
V_75 ) ;
}
#if V_79 > 1
if ( F_56 ( F_51 ( V_8 ,
V_77 ) ) ) {
F_58 ( & V_8 -> V_80 ) ;
F_53 ( V_8 ,
V_77 ) ;
}
#endif
}
F_44 () ;
}
static struct V_7 * F_59 ( struct V_81 * V_82 )
{
return F_60 ( V_14 ( V_82 ,
V_83 ) , struct V_7 ,
V_15 ) ;
}
struct V_7 * F_61 ( struct V_84 * V_25 )
{
if ( F_56 ( ! V_25 ) )
return NULL ;
return F_60 ( F_62 ( V_25 , V_83 ) ,
struct V_7 , V_15 ) ;
}
struct V_7 * F_63 ( struct V_85 * V_86 )
{
struct V_7 * V_8 = NULL ;
if ( ! V_86 )
return NULL ;
F_64 () ;
do {
V_8 = F_61 ( F_65 ( V_86 -> V_87 ) ) ;
if ( F_56 ( ! V_8 ) )
break;
} while ( ! F_27 ( & V_8 -> V_15 ) );
F_66 () ;
return V_8 ;
}
static struct V_7 * F_67 ( struct V_7 * V_8 )
{
struct V_14 * V_15 ;
int V_88 ;
if ( ! V_8 )
return V_89 ;
if ( ! V_8 -> V_90 ) {
if ( F_27 ( & V_8 -> V_15 ) )
return V_8 ;
return NULL ;
}
F_64 () ;
V_15 = F_68 ( & V_91 , 1 , & V_8 -> V_15 , & V_88 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_8 = F_60 ( V_15 , struct V_7 , V_15 ) ;
else
V_8 = NULL ;
F_66 () ;
return V_8 ;
}
static struct V_7 * F_69 ( struct V_7 * V_92 ,
struct V_7 * V_93 ,
bool V_94 )
{
int V_95 = F_70 ( & V_92 -> V_15 ) + 1 ;
int V_88 ;
int V_96 ;
struct V_14 * V_15 ;
V_96 = V_92 -> V_90 ;
F_71 ( & V_92 -> V_15 ) ;
if ( ! V_94 || ( V_93 && ! V_96 ) )
return NULL ;
if ( ! V_93 )
V_93 = V_89 ;
do {
V_92 = NULL ;
F_64 () ;
V_15 = F_68 ( & V_91 , V_95 ,
& V_93 -> V_15 , & V_88 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_92 = F_60 ( V_15 , struct V_7 , V_15 ) ;
F_66 () ;
V_95 = V_88 + 1 ;
} while ( V_15 && ! V_92 );
return V_92 ;
}
static inline bool F_72 ( struct V_7 * V_8 )
{
return ( V_8 == V_89 ) ;
}
void F_73 ( struct V_85 * V_86 , enum V_97 V_45 )
{
struct V_7 * V_8 ;
if ( ! V_86 )
return;
F_64 () ;
V_8 = F_61 ( F_65 ( V_86 -> V_87 ) ) ;
if ( F_56 ( ! V_8 ) )
goto V_98;
switch ( V_45 ) {
case V_99 :
F_38 ( V_8 , 1 ) ;
break;
case V_100 :
F_37 ( V_8 , 1 ) ;
break;
default:
F_74 () ;
}
V_98:
F_66 () ;
}
void F_75 ( struct V_16 * V_16 , enum V_66 V_101 )
{
struct V_102 * V_103 ;
struct V_6 * V_21 ;
if ( F_76 () )
return;
V_103 = F_77 ( V_16 ) ;
if ( ! F_78 ( V_103 ) )
return;
F_79 ( ! V_103 -> V_7 ) ;
V_21 = F_6 ( V_103 -> V_7 , V_16 ) ;
F_48 ( V_21 , V_101 ) -= 1 << F_80 ( V_16 ) ;
if ( F_72 ( V_103 -> V_7 ) )
return;
F_79 ( F_81 ( & V_103 -> V_101 ) ) ;
F_82 ( & V_103 -> V_101 ) ;
}
void F_83 ( struct V_16 * V_16 )
{
F_75 ( V_16 , F_84 ( V_16 ) ) ;
}
void F_85 ( struct V_16 * V_16 )
{
struct V_6 * V_21 ;
struct V_102 * V_103 ;
enum V_66 V_101 = F_84 ( V_16 ) ;
if ( F_76 () )
return;
V_103 = F_77 ( V_16 ) ;
if ( ! F_86 ( V_103 ) )
return;
F_87 () ;
if ( F_72 ( V_103 -> V_7 ) )
return;
V_21 = F_6 ( V_103 -> V_7 , V_16 ) ;
F_88 ( & V_103 -> V_101 , & V_21 -> V_104 [ V_101 ] ) ;
}
void F_89 ( struct V_16 * V_16 , enum V_66 V_101 )
{
struct V_6 * V_21 ;
struct V_102 * V_103 ;
if ( F_76 () )
return;
V_103 = F_77 ( V_16 ) ;
if ( ! F_86 ( V_103 ) )
return;
F_87 () ;
if ( F_72 ( V_103 -> V_7 ) )
return;
V_21 = F_6 ( V_103 -> V_7 , V_16 ) ;
F_90 ( & V_103 -> V_101 , & V_21 -> V_104 [ V_101 ] ) ;
}
void F_91 ( struct V_16 * V_16 , enum V_66 V_101 )
{
struct V_102 * V_103 ;
struct V_6 * V_21 ;
if ( F_76 () )
return;
V_103 = F_77 ( V_16 ) ;
F_79 ( F_92 ( V_103 ) ) ;
F_93 () ;
if ( ! F_86 ( V_103 ) )
return;
F_87 () ;
V_21 = F_6 ( V_103 -> V_7 , V_16 ) ;
F_48 ( V_21 , V_101 ) += 1 << F_80 ( V_16 ) ;
F_94 ( V_103 ) ;
if ( F_72 ( V_103 -> V_7 ) )
return;
F_95 ( & V_103 -> V_101 , & V_21 -> V_104 [ V_101 ] ) ;
}
static void F_96 ( struct V_16 * V_16 )
{
unsigned long V_105 ;
struct V_38 * V_38 = F_97 ( V_16 ) ;
struct V_102 * V_103 = F_77 ( V_16 ) ;
if ( F_98 ( ! F_99 ( V_16 ) ) )
return;
F_100 ( & V_38 -> V_106 , V_105 ) ;
if ( ! F_86 ( V_103 ) )
F_75 ( V_16 , F_84 ( V_16 ) ) ;
F_101 ( & V_38 -> V_106 , V_105 ) ;
}
static void F_102 ( struct V_16 * V_16 )
{
unsigned long V_105 ;
struct V_38 * V_38 = F_97 ( V_16 ) ;
struct V_102 * V_103 = F_77 ( V_16 ) ;
F_93 () ;
if ( F_98 ( ! F_99 ( V_16 ) ) )
return;
F_100 ( & V_38 -> V_106 , V_105 ) ;
if ( F_99 ( V_16 ) && ! F_92 ( V_103 ) )
F_91 ( V_16 , F_84 ( V_16 ) ) ;
F_101 ( & V_38 -> V_106 , V_105 ) ;
}
void F_103 ( struct V_16 * V_16 ,
enum V_66 V_107 , enum V_66 V_3 )
{
if ( F_76 () )
return;
F_75 ( V_16 , V_107 ) ;
F_91 ( V_16 , V_3 ) ;
}
static bool F_104 ( const struct V_7 * V_108 ,
struct V_7 * V_8 )
{
if ( V_108 != V_8 ) {
return ( V_108 -> V_90 &&
F_105 ( & V_8 -> V_15 , & V_108 -> V_15 ) ) ;
}
return true ;
}
int F_106 ( struct V_84 * V_109 , const struct V_7 * V_8 )
{
int V_68 ;
struct V_7 * V_110 = NULL ;
struct V_84 * V_25 ;
V_25 = F_107 ( V_109 ) ;
if ( ! V_25 )
return 0 ;
V_110 = F_63 ( V_25 -> V_86 ) ;
F_108 ( V_25 ) ;
if ( ! V_110 )
return 0 ;
V_68 = F_104 ( V_8 , V_110 ) ;
F_71 ( & V_110 -> V_15 ) ;
return V_68 ;
}
int F_109 ( struct V_7 * V_8 , struct V_38 * V_38 )
{
unsigned long V_111 ;
int V_9 = F_110 ( V_38 ) ;
int V_10 = F_111 ( V_38 ) ;
unsigned long V_112 ;
unsigned long V_113 ;
unsigned long V_114 ;
V_112 = F_45 ( V_8 , V_9 , V_10 ,
F_47 ( V_115 ) ) ;
V_113 = F_45 ( V_8 , V_9 , V_10 ,
F_47 ( V_116 ) ) ;
V_114 = ( V_112 + V_113 ) >> ( 30 - V_117 ) ;
if ( V_114 )
V_111 = F_112 ( 10 * V_114 ) ;
else
V_111 = 1 ;
return V_112 * V_111 < V_113 ;
}
int F_113 ( struct V_7 * V_8 , struct V_38 * V_38 )
{
unsigned long V_113 ;
unsigned long V_112 ;
int V_10 = F_111 ( V_38 ) ;
int V_9 = F_110 ( V_38 ) ;
V_112 = F_45 ( V_8 , V_9 , V_10 ,
F_47 ( V_118 ) ) ;
V_113 = F_45 ( V_8 , V_9 , V_10 ,
F_47 ( V_119 ) ) ;
return ( V_113 > V_112 ) ;
}
struct V_120 * F_114 ( struct V_7 * V_8 ,
struct V_38 * V_38 )
{
int V_9 = F_110 ( V_38 ) ;
int V_10 = F_111 ( V_38 ) ;
struct V_6 * V_21 = F_4 ( V_8 , V_9 , V_10 ) ;
return & V_21 -> V_121 ;
}
struct V_120 *
F_115 ( struct V_16 * V_16 )
{
struct V_102 * V_103 ;
struct V_6 * V_21 ;
if ( F_76 () )
return NULL ;
V_103 = F_77 ( V_16 ) ;
if ( ! F_86 ( V_103 ) )
return NULL ;
F_87 () ;
V_21 = F_6 ( V_103 -> V_7 , V_16 ) ;
return & V_21 -> V_121 ;
}
unsigned long F_116 ( unsigned long V_122 ,
struct V_123 * V_124 ,
unsigned long * V_125 , int V_126 ,
T_2 V_127 ,
struct V_38 * V_128 ,
struct V_7 * V_129 ,
int V_113 , int V_58 )
{
unsigned long V_130 = 0 ;
struct V_16 * V_16 ;
unsigned long V_131 ;
F_117 ( V_132 ) ;
struct V_123 * V_133 ;
struct V_102 * V_103 , * V_134 ;
int V_9 = F_110 ( V_128 ) ;
int V_10 = F_111 ( V_128 ) ;
struct V_6 * V_21 ;
int V_101 = V_135 * V_58 + V_113 ;
int V_68 ;
F_118 ( ! V_129 ) ;
V_21 = F_4 ( V_129 , V_9 , V_10 ) ;
V_133 = & V_21 -> V_104 [ V_101 ] ;
V_131 = 0 ;
F_119 (pc, tmp, src, lru) {
if ( V_131 >= V_122 )
break;
if ( F_56 ( ! F_86 ( V_103 ) ) )
continue;
V_16 = F_120 ( V_103 ) ;
if ( F_56 ( ! F_99 ( V_16 ) ) )
continue;
V_131 ++ ;
V_68 = F_121 ( V_16 , V_127 , V_58 ) ;
switch ( V_68 ) {
case 0 :
F_90 ( & V_16 -> V_101 , V_124 ) ;
F_83 ( V_16 ) ;
V_130 += F_122 ( V_16 ) ;
break;
case - V_136 :
F_89 ( V_16 , F_84 ( V_16 ) ) ;
break;
default:
break;
}
}
* V_125 = V_131 ;
F_123 ( 0 , V_122 , V_131 , V_130 ,
0 , 0 , 0 , V_127 ) ;
return V_130 ;
}
static unsigned long F_124 ( struct V_7 * V_8 )
{
unsigned long long V_137 ;
V_137 = F_125 ( & V_8 -> V_36 ) ;
if ( V_138 )
V_137 = F_126 ( V_137 , F_125 ( & V_8 -> V_139 ) ) ;
return V_137 >> V_117 ;
}
int F_127 ( struct V_7 * V_8 )
{
struct V_81 * V_140 = V_8 -> V_15 . V_81 ;
if ( V_140 -> V_27 == NULL )
return V_141 ;
return V_8 -> V_142 ;
}
static void F_128 ( struct V_7 * V_8 )
{
int V_47 ;
F_30 () ;
F_18 ( & V_8 -> V_50 ) ;
F_31 (cpu)
F_32 ( V_8 -> V_48 -> V_49 [ V_143 ] , V_47 ) += 1 ;
V_8 -> V_51 . V_49 [ V_143 ] += 1 ;
F_19 ( & V_8 -> V_50 ) ;
F_34 () ;
F_129 () ;
}
static void F_130 ( struct V_7 * V_8 )
{
int V_47 ;
if ( ! V_8 )
return;
F_30 () ;
F_18 ( & V_8 -> V_50 ) ;
F_31 (cpu)
F_32 ( V_8 -> V_48 -> V_49 [ V_143 ] , V_47 ) -= 1 ;
V_8 -> V_51 . V_49 [ V_143 ] -= 1 ;
F_19 ( & V_8 -> V_50 ) ;
F_34 () ;
}
static bool F_131 ( struct V_7 * V_8 )
{
F_79 ( ! F_132 () ) ;
return F_133 ( V_8 -> V_48 -> V_49 [ V_143 ] ) > 0 ;
}
static bool F_134 ( struct V_7 * V_8 )
{
struct V_7 * V_107 ;
struct V_7 * V_3 ;
bool V_68 = false ;
F_18 ( & V_2 . V_34 ) ;
V_107 = V_2 . V_107 ;
V_3 = V_2 . V_3 ;
if ( ! V_107 )
goto V_144;
V_68 = F_104 ( V_8 , V_107 )
|| F_104 ( V_8 , V_3 ) ;
V_144:
F_19 ( & V_2 . V_34 ) ;
return V_68 ;
}
static bool F_135 ( struct V_7 * V_8 )
{
if ( V_2 . V_145 && V_146 != V_2 . V_145 ) {
if ( F_134 ( V_8 ) ) {
F_136 ( V_147 ) ;
F_137 ( & V_2 . V_148 , & V_147 , V_149 ) ;
if ( V_2 . V_145 )
F_138 () ;
F_139 ( & V_2 . V_148 , & V_147 ) ;
return true ;
}
}
return false ;
}
void F_140 ( struct V_7 * V_8 , struct V_84 * V_25 )
{
struct V_81 * V_150 ;
struct V_81 * V_151 ;
static char V_152 [ V_153 ] ;
int V_68 ;
if ( ! V_8 || ! V_25 )
return;
F_64 () ;
V_151 = V_8 -> V_15 . V_81 ;
V_150 = F_141 ( V_25 , V_83 ) ;
V_68 = F_142 ( V_150 , V_152 , V_153 ) ;
if ( V_68 < 0 ) {
F_66 () ;
goto V_42;
}
F_66 () ;
F_143 ( V_154 L_1 , V_152 ) ;
F_64 () ;
V_68 = F_142 ( V_151 , V_152 , V_153 ) ;
if ( V_68 < 0 ) {
F_66 () ;
goto V_42;
}
F_66 () ;
F_143 ( V_155 L_2 , V_152 ) ;
V_42:
F_143 ( V_154 L_3 ,
F_144 ( & V_8 -> V_36 , V_156 ) >> 10 ,
F_144 ( & V_8 -> V_36 , V_157 ) >> 10 ,
F_144 ( & V_8 -> V_36 , V_158 ) ) ;
F_143 ( V_154 L_4
L_5 ,
F_144 ( & V_8 -> V_139 , V_156 ) >> 10 ,
F_144 ( & V_8 -> V_139 , V_157 ) >> 10 ,
F_144 ( & V_8 -> V_139 , V_158 ) ) ;
}
static int F_145 ( struct V_7 * V_8 )
{
int V_159 = 0 ;
struct V_7 * V_92 ;
F_146 (iter, memcg)
V_159 ++ ;
return V_159 ;
}
T_1 F_147 ( struct V_7 * V_8 )
{
T_1 V_160 ;
T_1 V_139 ;
V_160 = F_144 ( & V_8 -> V_36 , V_157 ) ;
V_160 += V_161 << V_117 ;
V_139 = F_144 ( & V_8 -> V_139 , V_157 ) ;
return F_126 ( V_160 , V_139 ) ;
}
static struct V_7 *
F_148 ( struct V_7 * V_108 )
{
struct V_7 * V_68 = NULL ;
struct V_14 * V_15 ;
int V_95 , V_88 ;
if ( ! V_108 -> V_90 ) {
F_149 ( & V_108 -> V_15 ) ;
V_68 = V_108 ;
}
while ( ! V_68 ) {
F_64 () ;
V_95 = V_108 -> V_162 + 1 ;
V_15 = F_68 ( & V_91 , V_95 , & V_108 -> V_15 ,
& V_88 ) ;
if ( V_15 && F_27 ( V_15 ) )
V_68 = F_60 ( V_15 , struct V_7 , V_15 ) ;
F_66 () ;
if ( ! V_15 ) {
V_108 -> V_162 = 0 ;
} else
V_108 -> V_162 = V_88 ;
}
return V_68 ;
}
static bool F_150 ( struct V_7 * V_8 ,
int V_9 , bool V_163 )
{
if ( F_49 ( V_8 , V_9 , V_164 ) )
return true ;
if ( V_163 || ! V_161 )
return false ;
if ( F_49 ( V_8 , V_9 , V_165 ) )
return true ;
return false ;
}
static void F_151 ( struct V_7 * V_8 )
{
int V_9 ;
if ( ! F_152 ( & V_8 -> V_80 ) )
return;
if ( F_153 ( & V_8 -> V_166 ) > 1 )
return;
V_8 -> V_167 = V_168 [ V_169 ] ;
F_154 (nid, node_states[N_HIGH_MEMORY]) {
if ( ! F_150 ( V_8 , V_9 , false ) )
F_155 ( V_9 , V_8 -> V_167 ) ;
}
F_156 ( & V_8 -> V_80 , 0 ) ;
F_156 ( & V_8 -> V_166 , 0 ) ;
}
int F_157 ( struct V_7 * V_8 )
{
int V_37 ;
F_151 ( V_8 ) ;
V_37 = V_8 -> V_170 ;
V_37 = F_158 ( V_37 , V_8 -> V_167 ) ;
if ( V_37 == V_79 )
V_37 = F_159 ( V_8 -> V_167 ) ;
if ( F_56 ( V_37 == V_79 ) )
V_37 = F_160 () ;
V_8 -> V_170 = V_37 ;
return V_37 ;
}
bool F_161 ( struct V_7 * V_8 , bool V_163 )
{
int V_9 ;
if ( ! F_162 ( V_8 -> V_167 ) ) {
for ( V_9 = F_159 ( V_8 -> V_167 ) ;
V_9 < V_79 ;
V_9 = F_158 ( V_9 , V_8 -> V_167 ) ) {
if ( F_150 ( V_8 , V_9 , V_163 ) )
return true ;
}
}
F_24 (nid, N_HIGH_MEMORY) {
if ( F_163 ( V_9 , V_8 -> V_167 ) )
continue;
if ( F_150 ( V_8 , V_9 , V_163 ) )
return true ;
}
return false ;
}
int F_157 ( struct V_7 * V_8 )
{
return 0 ;
}
bool F_161 ( struct V_7 * V_8 , bool V_163 )
{
return F_150 ( V_8 , 0 , V_163 ) ;
}
static int F_164 ( struct V_7 * V_108 ,
struct V_38 * V_38 ,
T_3 V_171 ,
unsigned long V_172 ,
unsigned long * V_173 )
{
struct V_7 * V_174 ;
int V_68 , V_69 = 0 ;
int V_175 = 0 ;
bool V_163 = V_172 & V_176 ;
bool V_177 = V_172 & V_178 ;
bool V_179 = V_172 & V_180 ;
unsigned long V_35 ;
unsigned long V_181 ;
V_35 = F_22 ( & V_108 -> V_36 ) >> V_117 ;
if ( ! V_179 && ! V_177 && V_108 -> V_182 )
V_163 = true ;
while ( 1 ) {
V_174 = F_148 ( V_108 ) ;
if ( V_174 == V_108 ) {
V_175 ++ ;
if ( ! V_179 && V_175 >= 1 )
F_165 ( V_108 ) ;
if ( V_175 >= 2 ) {
if ( ! V_179 || ! V_69 ) {
F_71 ( & V_174 -> V_15 ) ;
break;
}
if ( V_69 >= ( V_35 >> 2 ) ||
( V_175 > V_183 ) ) {
F_71 ( & V_174 -> V_15 ) ;
break;
}
}
}
if ( ! F_161 ( V_174 , V_163 ) ) {
F_71 ( & V_174 -> V_15 ) ;
continue;
}
if ( V_179 ) {
V_68 = F_166 ( V_174 , V_171 ,
V_163 , V_38 , & V_181 ) ;
* V_173 += V_181 ;
} else
V_68 = F_167 ( V_174 , V_171 ,
V_163 ) ;
F_71 ( & V_174 -> V_15 ) ;
if ( V_177 )
return V_68 ;
V_69 += V_68 ;
if ( V_179 ) {
if ( ! F_22 ( & V_108 -> V_36 ) )
return V_69 ;
} else if ( F_124 ( V_108 ) )
return V_69 ;
}
return V_69 ;
}
static bool F_168 ( struct V_7 * V_8 )
{
struct V_7 * V_92 , * V_184 = NULL ;
bool V_94 = true ;
F_169 (iter, memcg, cond) {
if ( V_92 -> V_185 ) {
V_184 = V_92 ;
V_94 = false ;
} else
V_92 -> V_185 = true ;
}
if ( ! V_184 )
return true ;
V_94 = true ;
F_169 (iter, memcg, cond) {
if ( V_92 == V_184 ) {
V_94 = false ;
continue;
}
V_92 -> V_185 = false ;
}
return false ;
}
static int F_170 ( struct V_7 * V_8 )
{
struct V_7 * V_92 ;
F_146 (iter, memcg)
V_92 -> V_185 = false ;
return 0 ;
}
static void F_171 ( struct V_7 * V_8 )
{
struct V_7 * V_92 ;
F_146 (iter, memcg)
F_58 ( & V_92 -> V_186 ) ;
}
static void F_172 ( struct V_7 * V_8 )
{
struct V_7 * V_92 ;
F_146 (iter, memcg)
F_173 ( & V_92 -> V_186 , - 1 , 0 ) ;
}
static int F_174 ( T_4 * V_147 ,
unsigned V_127 , int V_187 , void * V_188 )
{
struct V_7 * V_189 = (struct V_7 * ) V_188 ,
* V_190 ;
struct V_191 * V_191 ;
V_191 = F_60 ( V_147 , struct V_191 , V_147 ) ;
V_190 = V_191 -> V_43 ;
if ( ! F_104 ( V_190 , V_189 )
&& ! F_104 ( V_189 , V_190 ) )
return 0 ;
return F_175 ( V_147 , V_127 , V_187 , V_188 ) ;
}
static void F_176 ( struct V_7 * V_8 )
{
F_177 ( & V_192 , V_193 , 0 , V_8 ) ;
}
static void F_178 ( struct V_7 * V_8 )
{
if ( V_8 && F_152 ( & V_8 -> V_186 ) )
F_176 ( V_8 ) ;
}
bool F_179 ( struct V_7 * V_8 , T_3 V_194 )
{
struct V_191 V_195 ;
bool V_196 , V_197 ;
V_195 . V_43 = V_8 ;
V_195 . V_147 . V_105 = 0 ;
V_195 . V_147 . V_198 = F_174 ;
V_195 . V_147 . V_199 = V_146 ;
F_180 ( & V_195 . V_147 . V_200 ) ;
V_197 = true ;
F_171 ( V_8 ) ;
F_18 ( & V_201 ) ;
V_196 = F_168 ( V_8 ) ;
F_137 ( & V_192 , & V_195 . V_147 , V_202 ) ;
if ( ! V_196 || V_8 -> V_203 )
V_197 = false ;
if ( V_196 )
F_181 ( V_8 ) ;
F_19 ( & V_201 ) ;
if ( V_197 ) {
F_139 ( & V_192 , & V_195 . V_147 ) ;
F_182 ( V_8 , V_194 ) ;
} else {
F_138 () ;
F_139 ( & V_192 , & V_195 . V_147 ) ;
}
F_18 ( & V_201 ) ;
if ( V_196 )
F_170 ( V_8 ) ;
F_176 ( V_8 ) ;
F_19 ( & V_201 ) ;
F_172 ( V_8 ) ;
if ( F_183 ( V_204 ) || F_184 ( V_146 ) )
return false ;
F_185 ( 1 ) ;
return true ;
}
void F_186 ( struct V_16 * V_16 ,
enum V_205 V_45 , int V_46 )
{
struct V_7 * V_8 ;
struct V_102 * V_103 = F_77 ( V_16 ) ;
bool V_206 = false ;
unsigned long V_207 ( V_105 ) ;
if ( F_56 ( ! V_103 ) )
return;
F_64 () ;
V_8 = V_103 -> V_7 ;
if ( F_56 ( ! V_8 || ! F_86 ( V_103 ) ) )
goto V_98;
if ( F_56 ( F_131 ( V_8 ) ) || F_187 ( V_16 ) ) {
F_188 ( V_103 , & V_105 ) ;
V_206 = true ;
V_8 = V_103 -> V_7 ;
if ( ! V_8 || ! F_86 ( V_103 ) )
goto V_98;
}
switch ( V_45 ) {
case V_208 :
if ( V_46 > 0 )
F_189 ( V_103 ) ;
else if ( ! F_190 ( V_16 ) )
F_191 ( V_103 ) ;
V_45 = V_209 ;
break;
default:
F_74 () ;
}
F_36 ( V_8 -> V_48 -> V_49 [ V_45 ] , V_46 ) ;
V_98:
if ( F_56 ( V_206 ) )
F_192 ( V_103 , & V_105 ) ;
F_66 () ;
return;
}
static bool F_193 ( struct V_7 * V_8 )
{
struct V_210 * V_211 ;
bool V_68 = true ;
V_211 = & F_194 ( V_212 ) ;
if ( V_8 == V_211 -> V_213 && V_211 -> V_59 )
V_211 -> V_59 -- ;
else
V_68 = false ;
F_195 ( V_212 ) ;
return V_68 ;
}
static void F_196 ( struct V_210 * V_211 )
{
struct V_7 * V_214 = V_211 -> V_213 ;
if ( V_211 -> V_59 ) {
unsigned long V_215 = V_211 -> V_59 * V_216 ;
F_197 ( & V_214 -> V_36 , V_215 ) ;
if ( V_138 )
F_197 ( & V_214 -> V_139 , V_215 ) ;
V_211 -> V_59 = 0 ;
}
V_211 -> V_213 = NULL ;
}
static void F_198 ( struct V_217 * V_218 )
{
struct V_210 * V_211 = & F_199 ( V_212 ) ;
F_196 ( V_211 ) ;
F_200 ( V_219 , & V_211 -> V_105 ) ;
}
static void F_201 ( struct V_7 * V_8 , unsigned int V_59 )
{
struct V_210 * V_211 = & F_194 ( V_212 ) ;
if ( V_211 -> V_213 != V_8 ) {
F_196 ( V_211 ) ;
V_211 -> V_213 = V_8 ;
}
V_211 -> V_59 += V_59 ;
F_195 ( V_212 ) ;
}
static void F_202 ( struct V_7 * V_108 , bool V_187 )
{
int V_47 , V_220 ;
F_30 () ;
V_220 = F_203 () ;
F_31 (cpu) {
struct V_210 * V_211 = & F_32 ( V_212 , V_47 ) ;
struct V_7 * V_8 ;
V_8 = V_211 -> V_213 ;
if ( ! V_8 || ! V_211 -> V_59 )
continue;
if ( ! F_104 ( V_108 , V_8 ) )
continue;
if ( ! F_204 ( V_219 , & V_211 -> V_105 ) ) {
if ( V_47 == V_220 )
F_198 ( & V_211 -> V_221 ) ;
else
F_205 ( V_47 , & V_211 -> V_221 ) ;
}
}
F_206 () ;
if ( ! V_187 )
goto V_98;
F_31 (cpu) {
struct V_210 * V_211 = & F_32 ( V_212 , V_47 ) ;
if ( F_2 ( V_219 , & V_211 -> V_105 ) )
F_207 ( & V_211 -> V_221 ) ;
}
V_98:
F_34 () ;
}
static void F_165 ( struct V_7 * V_108 )
{
if ( ! F_208 ( & V_222 ) )
return;
F_202 ( V_108 , false ) ;
F_209 ( & V_222 ) ;
}
static void F_210 ( struct V_7 * V_108 )
{
F_211 ( & V_222 ) ;
F_202 ( V_108 , true ) ;
F_209 ( & V_222 ) ;
}
static void F_212 ( struct V_7 * V_8 , int V_47 )
{
int V_223 ;
F_18 ( & V_8 -> V_50 ) ;
for ( V_223 = 0 ; V_223 < V_224 ; V_223 ++ ) {
long V_225 = F_32 ( V_8 -> V_48 -> V_49 [ V_223 ] , V_47 ) ;
F_32 ( V_8 -> V_48 -> V_49 [ V_223 ] , V_47 ) = 0 ;
V_8 -> V_51 . V_49 [ V_223 ] += V_225 ;
}
for ( V_223 = 0 ; V_223 < V_226 ; V_223 ++ ) {
unsigned long V_225 = F_32 ( V_8 -> V_48 -> V_54 [ V_223 ] , V_47 ) ;
F_32 ( V_8 -> V_48 -> V_54 [ V_223 ] , V_47 ) = 0 ;
V_8 -> V_51 . V_54 [ V_223 ] += V_225 ;
}
F_32 ( V_8 -> V_48 -> V_49 [ V_143 ] , V_47 ) = 0 ;
F_19 ( & V_8 -> V_50 ) ;
}
static void F_213 ( struct V_7 * V_8 , int V_47 )
{
int V_45 = V_143 ;
F_18 ( & V_8 -> V_50 ) ;
F_32 ( V_8 -> V_48 -> V_49 [ V_45 ] , V_47 ) = V_8 -> V_51 . V_49 [ V_45 ] ;
F_19 ( & V_8 -> V_50 ) ;
}
static int T_5 F_214 ( struct V_227 * V_228 ,
unsigned long V_229 ,
void * V_230 )
{
int V_47 = ( unsigned long ) V_230 ;
struct V_210 * V_211 ;
struct V_7 * V_92 ;
if ( ( V_229 == V_231 ) ) {
F_215 (iter)
F_213 ( V_92 , V_47 ) ;
return V_232 ;
}
if ( ( V_229 != V_233 ) || V_229 != V_234 )
return V_232 ;
F_215 (iter)
F_212 ( V_92 , V_47 ) ;
V_211 = & F_32 ( V_212 , V_47 ) ;
F_196 ( V_211 ) ;
return V_232 ;
}
static int F_216 ( struct V_7 * V_8 , T_3 V_171 ,
unsigned int V_59 , bool V_235 )
{
unsigned long V_236 = V_59 * V_216 ;
struct V_7 * V_237 ;
struct V_238 * V_239 ;
unsigned long V_105 = 0 ;
int V_68 ;
V_68 = F_217 ( & V_8 -> V_36 , V_236 , & V_239 ) ;
if ( F_98 ( ! V_68 ) ) {
if ( ! V_138 )
return V_240 ;
V_68 = F_217 ( & V_8 -> V_139 , V_236 , & V_239 ) ;
if ( F_98 ( ! V_68 ) )
return V_240 ;
F_197 ( & V_8 -> V_36 , V_236 ) ;
V_237 = F_218 ( V_239 , V_139 ) ;
V_105 |= V_176 ;
} else
V_237 = F_218 ( V_239 , V_36 ) ;
if ( V_59 == V_241 )
return V_242 ;
if ( ! ( V_171 & V_243 ) )
return V_244 ;
V_68 = F_164 ( V_237 , NULL ,
V_171 , V_105 , NULL ) ;
if ( F_124 ( V_237 ) >= V_59 )
return V_242 ;
if ( V_59 == 1 && V_68 )
return V_242 ;
if ( F_135 ( V_237 ) )
return V_242 ;
if ( ! V_235 )
return V_245 ;
if ( ! F_179 ( V_237 , V_171 ) )
return V_246 ;
return V_242 ;
}
static int F_219 ( struct V_85 * V_86 ,
T_3 V_171 ,
unsigned int V_59 ,
struct V_7 * * V_247 ,
bool V_248 )
{
unsigned int V_249 = F_220 ( V_241 , V_59 ) ;
int V_250 = V_251 ;
struct V_7 * V_8 = NULL ;
int V_68 ;
if ( F_56 ( F_183 ( V_204 )
|| F_184 ( V_146 ) ) )
goto V_252;
if ( ! * V_247 && ! V_86 )
goto V_252;
V_253:
if ( * V_247 ) {
V_8 = * V_247 ;
F_79 ( F_221 ( & V_8 -> V_15 ) ) ;
if ( F_72 ( V_8 ) )
goto V_42;
if ( V_59 == 1 && F_193 ( V_8 ) )
goto V_42;
F_149 ( & V_8 -> V_15 ) ;
} else {
struct V_84 * V_25 ;
F_64 () ;
V_25 = F_65 ( V_86 -> V_87 ) ;
V_8 = F_61 ( V_25 ) ;
if ( ! V_8 || F_72 ( V_8 ) ) {
F_66 () ;
goto V_42;
}
if ( V_59 == 1 && F_193 ( V_8 ) ) {
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
bool V_235 ;
if ( F_184 ( V_146 ) ) {
F_71 ( & V_8 -> V_15 ) ;
goto V_252;
}
V_235 = false ;
if ( V_248 && ! V_250 ) {
V_235 = true ;
V_250 = V_251 ;
}
V_68 = F_216 ( V_8 , V_171 , V_249 , V_235 ) ;
switch ( V_68 ) {
case V_240 :
break;
case V_242 :
V_249 = V_59 ;
F_71 ( & V_8 -> V_15 ) ;
V_8 = NULL ;
goto V_253;
case V_244 :
F_71 ( & V_8 -> V_15 ) ;
goto V_254;
case V_245 :
if ( ! V_248 ) {
F_71 ( & V_8 -> V_15 ) ;
goto V_254;
}
V_250 -- ;
break;
case V_246 :
F_71 ( & V_8 -> V_15 ) ;
goto V_252;
}
} while ( V_68 != V_240 );
if ( V_249 > V_59 )
F_201 ( V_8 , V_249 - V_59 ) ;
F_71 ( & V_8 -> V_15 ) ;
V_42:
* V_247 = V_8 ;
return 0 ;
V_254:
* V_247 = NULL ;
return - V_255 ;
V_252:
* V_247 = NULL ;
return 0 ;
}
static void F_222 ( struct V_7 * V_8 ,
unsigned int V_59 )
{
if ( ! F_72 ( V_8 ) ) {
unsigned long V_215 = V_59 * V_216 ;
F_197 ( & V_8 -> V_36 , V_215 ) ;
if ( V_138 )
F_197 ( & V_8 -> V_139 , V_215 ) ;
}
}
static struct V_7 * F_223 ( unsigned short V_256 )
{
struct V_14 * V_15 ;
if ( ! V_256 )
return NULL ;
V_15 = F_224 ( & V_91 , V_256 ) ;
if ( ! V_15 )
return NULL ;
return F_60 ( V_15 , struct V_7 , V_15 ) ;
}
struct V_7 * F_225 ( struct V_16 * V_16 )
{
struct V_7 * V_8 = NULL ;
struct V_102 * V_103 ;
unsigned short V_256 ;
T_6 V_257 ;
F_79 ( ! F_226 ( V_16 ) ) ;
V_103 = F_77 ( V_16 ) ;
F_227 ( V_103 ) ;
if ( F_86 ( V_103 ) ) {
V_8 = V_103 -> V_7 ;
if ( V_8 && ! F_27 ( & V_8 -> V_15 ) )
V_8 = NULL ;
} else if ( F_228 ( V_16 ) ) {
V_257 . V_46 = F_229 ( V_16 ) ;
V_256 = F_230 ( V_257 ) ;
F_64 () ;
V_8 = F_223 ( V_256 ) ;
if ( V_8 && ! F_27 ( & V_8 -> V_15 ) )
V_8 = NULL ;
F_66 () ;
}
F_231 ( V_103 ) ;
return V_8 ;
}
static void F_232 ( struct V_7 * V_8 ,
struct V_16 * V_16 ,
unsigned int V_59 ,
struct V_102 * V_103 ,
enum V_258 V_259 )
{
F_227 ( V_103 ) ;
if ( F_56 ( F_86 ( V_103 ) ) ) {
F_231 ( V_103 ) ;
F_222 ( V_8 , V_59 ) ;
return;
}
V_103 -> V_7 = V_8 ;
F_233 () ;
switch ( V_259 ) {
case V_260 :
case V_261 :
F_234 ( V_103 ) ;
F_235 ( V_103 ) ;
break;
case V_262 :
F_236 ( V_103 ) ;
F_235 ( V_103 ) ;
break;
default:
break;
}
F_40 ( V_8 , F_237 ( V_103 ) , V_59 ) ;
F_231 ( V_103 ) ;
F_55 ( V_8 , V_16 ) ;
}
void F_238 ( struct V_16 * V_263 , struct V_16 * V_264 )
{
struct V_102 * V_265 = F_77 ( V_263 ) ;
struct V_102 * V_266 = F_77 ( V_264 ) ;
unsigned long V_105 ;
if ( F_76 () )
return;
F_188 ( V_265 , & V_105 ) ;
V_266 -> V_7 = V_265 -> V_7 ;
F_233 () ;
if ( F_92 ( V_265 ) ) {
enum V_66 V_101 ;
struct V_6 * V_21 ;
V_101 = F_84 ( V_263 ) ;
V_21 = F_6 ( V_265 -> V_7 , V_263 ) ;
F_48 ( V_21 , V_101 ) -= 1 ;
}
V_266 -> V_105 = V_265 -> V_105 & ~ V_267 ;
F_192 ( V_265 , & V_105 ) ;
}
static int F_239 ( struct V_16 * V_16 ,
unsigned int V_59 ,
struct V_102 * V_103 ,
struct V_7 * V_107 ,
struct V_7 * V_3 ,
bool V_268 )
{
unsigned long V_105 ;
int V_68 ;
F_79 ( V_107 == V_3 ) ;
F_79 ( F_99 ( V_16 ) ) ;
V_68 = - V_136 ;
if ( V_59 > 1 && ! F_187 ( V_16 ) )
goto V_98;
F_227 ( V_103 ) ;
V_68 = - V_269 ;
if ( ! F_86 ( V_103 ) || V_103 -> V_7 != V_107 )
goto V_144;
F_188 ( V_103 , & V_105 ) ;
if ( F_240 ( V_103 ) ) {
F_41 () ;
F_241 ( V_107 -> V_48 -> V_49 [ V_209 ] ) ;
F_43 ( V_3 -> V_48 -> V_49 [ V_209 ] ) ;
F_44 () ;
}
F_40 ( V_107 , F_237 ( V_103 ) , - V_59 ) ;
if ( V_268 )
F_222 ( V_107 , V_59 ) ;
V_103 -> V_7 = V_3 ;
F_40 ( V_3 , F_237 ( V_103 ) , V_59 ) ;
F_192 ( V_103 , & V_105 ) ;
V_68 = 0 ;
V_144:
F_231 ( V_103 ) ;
F_55 ( V_3 , V_16 ) ;
F_55 ( V_107 , V_16 ) ;
V_98:
return V_68 ;
}
static int F_242 ( struct V_16 * V_16 ,
struct V_102 * V_103 ,
struct V_7 * V_270 ,
T_3 V_171 )
{
struct V_81 * V_271 = V_270 -> V_15 . V_81 ;
struct V_81 * V_272 = V_271 -> V_27 ;
struct V_7 * V_27 ;
unsigned int V_59 ;
unsigned long V_207 ( V_105 ) ;
int V_68 ;
if ( ! V_272 )
return - V_269 ;
V_68 = - V_136 ;
if ( ! F_243 ( V_16 ) )
goto V_98;
if ( F_244 ( V_16 ) )
goto V_273;
V_59 = F_122 ( V_16 ) ;
V_27 = F_59 ( V_272 ) ;
V_68 = F_219 ( NULL , V_171 , V_59 , & V_27 , false ) ;
if ( V_68 || ! V_27 )
goto V_274;
if ( V_59 > 1 )
V_105 = F_245 ( V_16 ) ;
V_68 = F_239 ( V_16 , V_59 , V_103 , V_270 , V_27 , true ) ;
if ( V_68 )
F_222 ( V_27 , V_59 ) ;
if ( V_59 > 1 )
F_246 ( V_16 , V_105 ) ;
V_274:
F_247 ( V_16 ) ;
V_273:
F_248 ( V_16 ) ;
V_98:
return V_68 ;
}
static int F_249 ( struct V_16 * V_16 , struct V_85 * V_86 ,
T_3 V_171 , enum V_258 V_259 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_59 = 1 ;
struct V_102 * V_103 ;
bool V_248 = true ;
int V_68 ;
if ( F_187 ( V_16 ) ) {
V_59 <<= F_80 ( V_16 ) ;
F_79 ( ! F_187 ( V_16 ) ) ;
V_248 = false ;
}
V_103 = F_77 ( V_16 ) ;
F_118 ( ! V_103 ) ;
V_68 = F_219 ( V_86 , V_171 , V_59 , & V_8 , V_248 ) ;
if ( V_68 || ! V_8 )
return V_68 ;
F_232 ( V_8 , V_16 , V_59 , V_103 , V_259 ) ;
return 0 ;
}
int F_250 ( struct V_16 * V_16 ,
struct V_85 * V_86 , T_3 V_171 )
{
if ( F_76 () )
return 0 ;
if ( F_190 ( V_16 ) || ( V_16 -> V_275 && ! F_251 ( V_16 ) ) )
return 0 ;
if ( F_56 ( ! V_86 ) )
V_86 = & V_276 ;
return F_249 ( V_16 , V_86 , V_171 ,
V_262 ) ;
}
static void
F_252 ( struct V_16 * V_16 , struct V_7 * V_8 ,
enum V_258 V_259 )
{
struct V_102 * V_103 = F_77 ( V_16 ) ;
F_96 ( V_16 ) ;
F_232 ( V_8 , V_16 , 1 , V_103 , V_259 ) ;
F_102 ( V_16 ) ;
return;
}
int F_253 ( struct V_16 * V_16 , struct V_85 * V_86 ,
T_3 V_171 )
{
struct V_7 * V_8 = NULL ;
int V_68 ;
if ( F_76 () )
return 0 ;
if ( F_254 ( V_16 ) )
return 0 ;
if ( F_56 ( ! V_86 ) )
V_86 = & V_276 ;
if ( F_255 ( V_16 ) ) {
V_68 = F_219 ( V_86 , V_171 , 1 , & V_8 , true ) ;
if ( V_68 || ! V_8 )
return V_68 ;
F_252 ( V_16 , V_8 ,
V_260 ) ;
return V_68 ;
}
if ( F_228 ( V_16 ) ) {
V_68 = F_256 ( V_86 , V_16 , V_171 , & V_8 ) ;
if ( ! V_68 )
F_257 ( V_16 , V_8 ,
V_261 ) ;
} else
V_68 = F_249 ( V_16 , V_86 , V_171 ,
V_261 ) ;
return V_68 ;
}
int F_256 ( struct V_85 * V_86 ,
struct V_16 * V_16 ,
T_3 V_194 , struct V_7 * * V_247 )
{
struct V_7 * V_8 ;
int V_68 ;
* V_247 = NULL ;
if ( F_76 () )
return 0 ;
if ( ! V_138 )
goto V_277;
if ( ! F_228 ( V_16 ) )
goto V_277;
V_8 = F_225 ( V_16 ) ;
if ( ! V_8 )
goto V_277;
* V_247 = V_8 ;
V_68 = F_219 ( NULL , V_194 , 1 , V_247 , true ) ;
F_71 ( & V_8 -> V_15 ) ;
return V_68 ;
V_277:
if ( F_56 ( ! V_86 ) )
V_86 = & V_276 ;
return F_219 ( V_86 , V_194 , 1 , V_247 , true ) ;
}
static void
F_257 ( struct V_16 * V_16 , struct V_7 * V_247 ,
enum V_258 V_259 )
{
if ( F_76 () )
return;
if ( ! V_247 )
return;
F_258 ( & V_247 -> V_15 ) ;
F_252 ( V_16 , V_247 , V_259 ) ;
if ( V_138 && F_228 ( V_16 ) ) {
T_6 V_257 = { . V_46 = F_229 (page) } ;
unsigned short V_256 ;
struct V_7 * V_8 ;
V_256 = F_259 ( V_257 , 0 ) ;
F_64 () ;
V_8 = F_223 ( V_256 ) ;
if ( V_8 ) {
if ( ! F_72 ( V_8 ) )
F_197 ( & V_8 -> V_139 , V_216 ) ;
F_35 ( V_8 , false ) ;
F_260 ( V_8 ) ;
}
F_66 () ;
}
F_261 ( & V_247 -> V_15 ) ;
}
void F_262 ( struct V_16 * V_16 , struct V_7 * V_247 )
{
F_257 ( V_16 , V_247 ,
V_262 ) ;
}
void F_263 ( struct V_7 * V_8 )
{
if ( F_76 () )
return;
if ( ! V_8 )
return;
F_222 ( V_8 , 1 ) ;
}
static void F_264 ( struct V_7 * V_8 ,
unsigned int V_59 ,
const enum V_258 V_259 )
{
struct V_278 * V_249 = NULL ;
bool V_279 = true ;
if ( ! V_138 || V_259 == V_280 )
V_279 = false ;
V_249 = & V_146 -> V_281 ;
if ( ! V_249 -> V_8 )
V_249 -> V_8 = V_8 ;
if ( ! V_249 -> V_282 || F_183 ( V_204 ) )
goto V_283;
if ( V_59 > 1 )
goto V_283;
if ( V_249 -> V_8 != V_8 )
goto V_283;
V_249 -> V_59 ++ ;
if ( V_279 )
V_249 -> V_284 ++ ;
return;
V_283:
F_197 ( & V_8 -> V_36 , V_59 * V_216 ) ;
if ( V_279 )
F_197 ( & V_8 -> V_139 , V_59 * V_216 ) ;
if ( F_56 ( V_249 -> V_8 != V_8 ) )
F_178 ( V_8 ) ;
return;
}
static struct V_7 *
F_265 ( struct V_16 * V_16 , enum V_258 V_259 )
{
struct V_7 * V_8 = NULL ;
unsigned int V_59 = 1 ;
struct V_102 * V_103 ;
if ( F_76 () )
return NULL ;
if ( F_228 ( V_16 ) )
return NULL ;
if ( F_187 ( V_16 ) ) {
V_59 <<= F_80 ( V_16 ) ;
F_79 ( ! F_187 ( V_16 ) ) ;
}
V_103 = F_77 ( V_16 ) ;
if ( F_56 ( ! V_103 || ! F_86 ( V_103 ) ) )
return NULL ;
F_227 ( V_103 ) ;
V_8 = V_103 -> V_7 ;
if ( ! F_86 ( V_103 ) )
goto V_285;
switch ( V_259 ) {
case V_262 :
case V_286 :
if ( F_190 ( V_16 ) || F_266 ( V_103 ) )
goto V_285;
break;
case V_280 :
if ( ! F_251 ( V_16 ) ) {
if ( V_16 -> V_275 && ! F_255 ( V_16 ) )
goto V_285;
} else if ( F_190 ( V_16 ) )
goto V_285;
break;
default:
break;
}
F_40 ( V_8 , F_237 ( V_103 ) , - V_59 ) ;
F_267 ( V_103 ) ;
F_231 ( V_103 ) ;
F_55 ( V_8 , V_16 ) ;
if ( V_138 && V_259 == V_280 ) {
F_35 ( V_8 , true ) ;
F_268 ( V_8 ) ;
}
if ( ! F_72 ( V_8 ) )
F_264 ( V_8 , V_59 , V_259 ) ;
return V_8 ;
V_285:
F_231 ( V_103 ) ;
return NULL ;
}
void F_269 ( struct V_16 * V_16 )
{
if ( F_190 ( V_16 ) )
return;
if ( V_16 -> V_275 && ! F_251 ( V_16 ) )
return;
F_265 ( V_16 , V_262 ) ;
}
void F_270 ( struct V_16 * V_16 )
{
F_79 ( F_190 ( V_16 ) ) ;
F_79 ( V_16 -> V_275 ) ;
F_265 ( V_16 , V_260 ) ;
}
void F_271 ( void )
{
V_146 -> V_281 . V_282 ++ ;
if ( V_146 -> V_281 . V_282 == 1 ) {
V_146 -> V_281 . V_8 = NULL ;
V_146 -> V_281 . V_59 = 0 ;
V_146 -> V_281 . V_284 = 0 ;
}
}
void F_272 ( void )
{
struct V_278 * V_249 = & V_146 -> V_281 ;
if ( ! V_249 -> V_282 )
return;
V_249 -> V_282 -- ;
if ( V_249 -> V_282 )
return;
if ( ! V_249 -> V_8 )
return;
if ( V_249 -> V_59 )
F_197 ( & V_249 -> V_8 -> V_36 ,
V_249 -> V_59 * V_216 ) ;
if ( V_249 -> V_284 )
F_197 ( & V_249 -> V_8 -> V_139 ,
V_249 -> V_284 * V_216 ) ;
F_178 ( V_249 -> V_8 ) ;
V_249 -> V_8 = NULL ;
}
void
F_273 ( struct V_16 * V_16 , T_6 V_257 , bool V_287 )
{
struct V_7 * V_8 ;
int V_259 = V_280 ;
if ( ! V_287 )
V_259 = V_286 ;
V_8 = F_265 ( V_16 , V_259 ) ;
if ( V_138 && V_287 && V_8 )
F_259 ( V_257 , F_70 ( & V_8 -> V_15 ) ) ;
}
void F_274 ( T_6 V_257 )
{
struct V_7 * V_8 ;
unsigned short V_256 ;
if ( ! V_138 )
return;
V_256 = F_259 ( V_257 , 0 ) ;
F_64 () ;
V_8 = F_223 ( V_256 ) ;
if ( V_8 ) {
if ( ! F_72 ( V_8 ) )
F_197 ( & V_8 -> V_139 , V_216 ) ;
F_35 ( V_8 , false ) ;
F_260 ( V_8 ) ;
}
F_66 () ;
}
static int F_275 ( T_6 V_288 ,
struct V_7 * V_107 , struct V_7 * V_3 , bool V_289 )
{
unsigned short V_290 , V_291 ;
V_290 = F_70 ( & V_107 -> V_15 ) ;
V_291 = F_70 ( & V_3 -> V_15 ) ;
if ( F_276 ( V_288 , V_290 , V_291 ) == V_290 ) {
F_35 ( V_107 , false ) ;
F_35 ( V_3 , true ) ;
F_268 ( V_3 ) ;
if ( V_289 ) {
if ( ! F_72 ( V_107 ) )
F_197 ( & V_107 -> V_139 , V_216 ) ;
F_260 ( V_107 ) ;
if ( ! F_72 ( V_3 ) )
F_197 ( & V_3 -> V_36 , V_216 ) ;
}
return 0 ;
}
return - V_269 ;
}
static inline int F_275 ( T_6 V_288 ,
struct V_7 * V_107 , struct V_7 * V_3 , bool V_289 )
{
return - V_269 ;
}
int F_277 ( struct V_16 * V_16 ,
struct V_16 * V_292 , struct V_7 * * V_247 , T_3 V_171 )
{
struct V_7 * V_8 = NULL ;
struct V_102 * V_103 ;
enum V_258 V_259 ;
int V_68 = 0 ;
* V_247 = NULL ;
F_79 ( F_187 ( V_16 ) ) ;
if ( F_76 () )
return 0 ;
V_103 = F_77 ( V_16 ) ;
F_227 ( V_103 ) ;
if ( F_86 ( V_103 ) ) {
V_8 = V_103 -> V_7 ;
F_149 ( & V_8 -> V_15 ) ;
if ( F_251 ( V_16 ) )
F_278 ( V_103 ) ;
}
F_231 ( V_103 ) ;
if ( ! V_8 )
return 0 ;
* V_247 = V_8 ;
V_68 = F_219 ( NULL , V_171 , 1 , V_247 , false ) ;
F_71 ( & V_8 -> V_15 ) ;
if ( V_68 || * V_247 == NULL ) {
if ( F_251 ( V_16 ) ) {
F_227 ( V_103 ) ;
F_279 ( V_103 ) ;
F_231 ( V_103 ) ;
F_269 ( V_16 ) ;
}
return - V_255 ;
}
V_103 = F_77 ( V_292 ) ;
if ( F_251 ( V_16 ) )
V_259 = V_262 ;
else if ( F_255 ( V_16 ) )
V_259 = V_260 ;
else
V_259 = V_261 ;
F_232 ( V_8 , V_16 , 1 , V_103 , V_259 ) ;
return V_68 ;
}
void F_280 ( struct V_7 * V_8 ,
struct V_16 * V_293 , struct V_16 * V_292 , bool V_294 )
{
struct V_16 * V_295 , * V_296 ;
struct V_102 * V_103 ;
if ( ! V_8 )
return;
F_258 ( & V_8 -> V_15 ) ;
if ( ! V_294 ) {
V_295 = V_293 ;
V_296 = V_292 ;
} else {
V_295 = V_292 ;
V_296 = V_293 ;
}
V_103 = F_77 ( V_293 ) ;
F_227 ( V_103 ) ;
F_279 ( V_103 ) ;
F_231 ( V_103 ) ;
F_265 ( V_296 , V_297 ) ;
if ( F_251 ( V_295 ) )
F_269 ( V_295 ) ;
F_261 ( & V_8 -> V_15 ) ;
}
static struct V_102 * F_281 ( struct V_16 * V_16 )
{
struct V_102 * V_103 ;
V_103 = F_77 ( V_16 ) ;
if ( F_98 ( V_103 ) && F_86 ( V_103 ) )
return V_103 ;
return NULL ;
}
bool F_282 ( struct V_16 * V_16 )
{
if ( F_76 () )
return false ;
return F_281 ( V_16 ) != NULL ;
}
void F_283 ( struct V_16 * V_16 )
{
struct V_102 * V_103 ;
V_103 = F_281 ( V_16 ) ;
if ( V_103 ) {
int V_68 = - 1 ;
char * V_298 ;
F_143 ( V_299 L_6 ,
V_103 , V_103 -> V_105 , V_103 -> V_7 ) ;
V_298 = F_284 ( V_153 , V_300 ) ;
if ( V_298 ) {
F_64 () ;
V_68 = F_142 ( V_103 -> V_7 -> V_15 . V_81 ,
V_298 , V_153 ) ;
F_66 () ;
}
F_143 ( V_155 L_7 ,
( V_68 < 0 ) ? L_8 : V_298 ) ;
F_285 ( V_298 ) ;
}
}
static int F_286 ( struct V_7 * V_8 ,
unsigned long long V_46 )
{
int V_301 ;
T_1 V_302 , V_303 ;
int V_68 = 0 ;
int V_304 = F_145 ( V_8 ) ;
T_1 V_305 , V_306 ;
int V_307 ;
V_301 = V_251 * V_304 ;
V_306 = F_144 ( & V_8 -> V_36 , V_156 ) ;
V_307 = 0 ;
while ( V_301 ) {
if ( F_287 ( V_146 ) ) {
V_68 = - V_308 ;
break;
}
F_211 ( & V_309 ) ;
V_302 = F_144 ( & V_8 -> V_139 , V_157 ) ;
if ( V_302 < V_46 ) {
V_68 = - V_269 ;
F_209 ( & V_309 ) ;
break;
}
V_303 = F_144 ( & V_8 -> V_36 , V_157 ) ;
if ( V_303 < V_46 )
V_307 = 1 ;
V_68 = F_288 ( & V_8 -> V_36 , V_46 ) ;
if ( ! V_68 ) {
if ( V_302 == V_46 )
V_8 -> V_182 = true ;
else
V_8 -> V_182 = false ;
}
F_209 ( & V_309 ) ;
if ( ! V_68 )
break;
F_164 ( V_8 , NULL , V_300 ,
V_178 ,
NULL ) ;
V_305 = F_144 ( & V_8 -> V_36 , V_156 ) ;
if ( V_305 >= V_306 )
V_301 -- ;
else
V_306 = V_305 ;
}
if ( ! V_68 && V_307 )
F_178 ( V_8 ) ;
return V_68 ;
}
static int F_289 ( struct V_7 * V_8 ,
unsigned long long V_46 )
{
int V_301 ;
T_1 V_303 , V_302 , V_306 , V_305 ;
int V_304 = F_145 ( V_8 ) ;
int V_68 = - V_136 ;
int V_307 = 0 ;
V_301 = V_304 * V_251 ;
V_306 = F_144 ( & V_8 -> V_139 , V_156 ) ;
while ( V_301 ) {
if ( F_287 ( V_146 ) ) {
V_68 = - V_308 ;
break;
}
F_211 ( & V_309 ) ;
V_303 = F_144 ( & V_8 -> V_36 , V_157 ) ;
if ( V_303 > V_46 ) {
V_68 = - V_269 ;
F_209 ( & V_309 ) ;
break;
}
V_302 = F_144 ( & V_8 -> V_139 , V_157 ) ;
if ( V_302 < V_46 )
V_307 = 1 ;
V_68 = F_288 ( & V_8 -> V_139 , V_46 ) ;
if ( ! V_68 ) {
if ( V_303 == V_46 )
V_8 -> V_182 = true ;
else
V_8 -> V_182 = false ;
}
F_209 ( & V_309 ) ;
if ( ! V_68 )
break;
F_164 ( V_8 , NULL , V_300 ,
V_176 |
V_178 ,
NULL ) ;
V_305 = F_144 ( & V_8 -> V_139 , V_156 ) ;
if ( V_305 >= V_306 )
V_301 -- ;
else
V_306 = V_305 ;
}
if ( ! V_68 && V_307 )
F_178 ( V_8 ) ;
return V_68 ;
}
unsigned long F_290 ( struct V_38 * V_38 , int V_126 ,
T_3 V_171 ,
unsigned long * V_173 )
{
unsigned long V_310 = 0 ;
struct V_6 * V_21 , * V_311 = NULL ;
unsigned long V_312 ;
int V_175 = 0 ;
struct V_17 * V_22 ;
unsigned long long V_35 ;
unsigned long V_181 ;
if ( V_126 > 0 )
return 0 ;
V_22 = F_9 ( F_110 ( V_38 ) , F_111 ( V_38 ) ) ;
do {
if ( V_311 )
V_21 = V_311 ;
else
V_21 = F_28 ( V_22 ) ;
if ( ! V_21 )
break;
V_181 = 0 ;
V_312 = F_164 ( V_21 -> V_43 , V_38 ,
V_171 ,
V_180 ,
& V_181 ) ;
V_310 += V_312 ;
* V_173 += V_181 ;
F_18 ( & V_22 -> V_34 ) ;
V_311 = NULL ;
if ( ! V_312 ) {
do {
V_311 =
F_25 ( V_22 ) ;
if ( V_311 == V_21 )
F_71 ( & V_311 -> V_43 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_15 ( V_21 -> V_43 , V_21 , V_22 ) ;
V_35 = F_22 ( & V_21 -> V_43 -> V_36 ) ;
F_11 ( V_21 -> V_43 , V_21 , V_22 , V_35 ) ;
F_19 ( & V_22 -> V_34 ) ;
F_71 ( & V_21 -> V_43 -> V_15 ) ;
V_175 ++ ;
if ( ! V_310 &&
( V_311 == NULL ||
V_175 > V_313 ) )
break;
} while ( ! V_310 );
if ( V_311 )
F_71 ( & V_311 -> V_43 -> V_15 ) ;
return V_310 ;
}
static int F_291 ( struct V_7 * V_8 ,
int V_37 , int V_10 , enum V_66 V_101 )
{
struct V_38 * V_38 ;
struct V_6 * V_21 ;
struct V_102 * V_103 , * V_314 ;
unsigned long V_105 , V_175 ;
struct V_123 * V_315 ;
int V_68 = 0 ;
V_38 = & F_292 ( V_37 ) -> V_316 [ V_10 ] ;
V_21 = F_4 ( V_8 , V_37 , V_10 ) ;
V_315 = & V_21 -> V_104 [ V_101 ] ;
V_175 = F_48 ( V_21 , V_101 ) ;
V_175 += 256 ;
V_314 = NULL ;
while ( V_175 -- ) {
struct V_16 * V_16 ;
V_68 = 0 ;
F_100 ( & V_38 -> V_106 , V_105 ) ;
if ( F_81 ( V_315 ) ) {
F_101 ( & V_38 -> V_106 , V_105 ) ;
break;
}
V_103 = F_293 ( V_315 -> V_317 , struct V_102 , V_101 ) ;
if ( V_314 == V_103 ) {
F_90 ( & V_103 -> V_101 , V_315 ) ;
V_314 = NULL ;
F_101 ( & V_38 -> V_106 , V_105 ) ;
continue;
}
F_101 ( & V_38 -> V_106 , V_105 ) ;
V_16 = F_120 ( V_103 ) ;
V_68 = F_242 ( V_16 , V_103 , V_8 , V_300 ) ;
if ( V_68 == - V_255 )
break;
if ( V_68 == - V_136 || V_68 == - V_269 ) {
V_314 = V_103 ;
F_294 () ;
} else
V_314 = NULL ;
}
if ( ! V_68 && ! F_81 ( V_315 ) )
return - V_136 ;
return V_68 ;
}
static int F_295 ( struct V_7 * V_8 , bool V_318 )
{
int V_68 ;
int V_37 , V_10 , V_177 ;
int V_319 = V_251 ;
struct V_81 * V_140 = V_8 -> V_15 . V_81 ;
F_149 ( & V_8 -> V_15 ) ;
V_177 = 0 ;
if ( V_318 )
goto V_320;
V_321:
do {
V_68 = - V_136 ;
if ( F_296 ( V_140 ) || ! F_81 ( & V_140 -> V_304 ) )
goto V_98;
V_68 = - V_308 ;
if ( F_287 ( V_146 ) )
goto V_98;
F_297 () ;
F_210 ( V_8 ) ;
V_68 = 0 ;
F_128 ( V_8 ) ;
F_24 (node, N_HIGH_MEMORY) {
for ( V_10 = 0 ; ! V_68 && V_10 < V_39 ; V_10 ++ ) {
enum V_66 V_67 ;
F_46 (l) {
V_68 = F_291 ( V_8 ,
V_37 , V_10 , V_67 ) ;
if ( V_68 )
break;
}
}
if ( V_68 )
break;
}
F_130 ( V_8 ) ;
F_178 ( V_8 ) ;
if ( V_68 == - V_255 )
goto V_320;
F_294 () ;
} while ( V_8 -> V_36 . V_322 > 0 || V_68 );
V_98:
F_71 ( & V_8 -> V_15 ) ;
return V_68 ;
V_320:
if ( F_296 ( V_140 ) || ! F_81 ( & V_140 -> V_304 ) || V_177 ) {
V_68 = - V_136 ;
goto V_98;
}
F_297 () ;
V_177 = 1 ;
while ( V_319 && V_8 -> V_36 . V_322 > 0 ) {
int V_323 ;
if ( F_287 ( V_146 ) ) {
V_68 = - V_308 ;
goto V_98;
}
V_323 = F_167 ( V_8 , V_300 ,
false ) ;
if ( ! V_323 ) {
V_319 -- ;
F_298 ( V_324 , V_325 / 10 ) ;
}
}
F_299 () ;
goto V_321;
}
int F_300 ( struct V_81 * V_82 , unsigned int V_326 )
{
return F_295 ( F_59 ( V_82 ) , true ) ;
}
static T_1 F_301 ( struct V_81 * V_82 , struct V_327 * V_328 )
{
return F_59 ( V_82 ) -> V_90 ;
}
static int F_302 ( struct V_81 * V_82 , struct V_327 * V_328 ,
T_1 V_46 )
{
int V_329 = 0 ;
struct V_7 * V_8 = F_59 ( V_82 ) ;
struct V_81 * V_27 = V_82 -> V_27 ;
struct V_7 * V_330 = NULL ;
if ( V_27 )
V_330 = F_59 ( V_27 ) ;
F_303 () ;
if ( ( ! V_330 || ! V_330 -> V_90 ) &&
( V_46 == 1 || V_46 == 0 ) ) {
if ( F_81 ( & V_82 -> V_304 ) )
V_8 -> V_90 = V_46 ;
else
V_329 = - V_136 ;
} else
V_329 = - V_269 ;
F_304 () ;
return V_329 ;
}
static unsigned long F_305 ( struct V_7 * V_8 ,
enum V_44 V_45 )
{
struct V_7 * V_92 ;
long V_46 = 0 ;
F_146 (iter, memcg)
V_46 += F_29 ( V_92 , V_45 ) ;
if ( V_46 < 0 )
V_46 = 0 ;
return V_46 ;
}
static inline T_1 F_306 ( struct V_7 * V_8 , bool V_331 )
{
T_1 V_46 ;
if ( ! F_72 ( V_8 ) ) {
if ( ! V_331 )
return F_144 ( & V_8 -> V_36 , V_156 ) ;
else
return F_144 ( & V_8 -> V_139 , V_156 ) ;
}
V_46 = F_305 ( V_8 , V_60 ) ;
V_46 += F_305 ( V_8 , V_61 ) ;
if ( V_331 )
V_46 += F_305 ( V_8 , V_53 ) ;
return V_46 << V_117 ;
}
static T_1 F_307 ( struct V_81 * V_82 , struct V_327 * V_328 )
{
struct V_7 * V_8 = F_59 ( V_82 ) ;
T_1 V_46 ;
int type , V_332 ;
type = F_308 ( V_328 -> V_199 ) ;
V_332 = F_309 ( V_328 -> V_199 ) ;
switch ( type ) {
case V_333 :
if ( V_332 == V_156 )
V_46 = F_306 ( V_8 , false ) ;
else
V_46 = F_144 ( & V_8 -> V_36 , V_332 ) ;
break;
case V_334 :
if ( V_332 == V_156 )
V_46 = F_306 ( V_8 , true ) ;
else
V_46 = F_144 ( & V_8 -> V_139 , V_332 ) ;
break;
default:
F_74 () ;
break;
}
return V_46 ;
}
static int F_310 ( struct V_81 * V_82 , struct V_327 * V_328 ,
const char * V_335 )
{
struct V_7 * V_8 = F_59 ( V_82 ) ;
int type , V_332 ;
unsigned long long V_46 ;
int V_68 ;
type = F_308 ( V_328 -> V_199 ) ;
V_332 = F_309 ( V_328 -> V_199 ) ;
switch ( V_332 ) {
case V_157 :
if ( F_72 ( V_8 ) ) {
V_68 = - V_269 ;
break;
}
V_68 = F_311 ( V_335 , & V_46 ) ;
if ( V_68 )
break;
if ( type == V_333 )
V_68 = F_286 ( V_8 , V_46 ) ;
else
V_68 = F_289 ( V_8 , V_46 ) ;
break;
case V_336 :
V_68 = F_311 ( V_335 , & V_46 ) ;
if ( V_68 )
break;
if ( type == V_333 )
V_68 = F_312 ( & V_8 -> V_36 , V_46 ) ;
else
V_68 = - V_269 ;
break;
default:
V_68 = - V_269 ;
break;
}
return V_68 ;
}
static void F_313 ( struct V_7 * V_8 ,
unsigned long long * V_337 , unsigned long long * V_338 )
{
struct V_81 * V_81 ;
unsigned long long V_339 , V_340 , V_134 ;
V_339 = F_144 ( & V_8 -> V_36 , V_157 ) ;
V_340 = F_144 ( & V_8 -> V_139 , V_157 ) ;
V_81 = V_8 -> V_15 . V_81 ;
if ( ! V_8 -> V_90 )
goto V_98;
while ( V_81 -> V_27 ) {
V_81 = V_81 -> V_27 ;
V_8 = F_59 ( V_81 ) ;
if ( ! V_8 -> V_90 )
break;
V_134 = F_144 ( & V_8 -> V_36 , V_157 ) ;
V_339 = F_126 ( V_339 , V_134 ) ;
V_134 = F_144 ( & V_8 -> V_139 , V_157 ) ;
V_340 = F_126 ( V_340 , V_134 ) ;
}
V_98:
* V_337 = V_339 ;
* V_338 = V_340 ;
return;
}
static int F_314 ( struct V_81 * V_82 , unsigned int V_326 )
{
struct V_7 * V_8 ;
int type , V_332 ;
V_8 = F_59 ( V_82 ) ;
type = F_308 ( V_326 ) ;
V_332 = F_309 ( V_326 ) ;
switch ( V_332 ) {
case V_341 :
if ( type == V_333 )
F_315 ( & V_8 -> V_36 ) ;
else
F_315 ( & V_8 -> V_139 ) ;
break;
case V_158 :
if ( type == V_333 )
F_316 ( & V_8 -> V_36 ) ;
else
F_316 ( & V_8 -> V_139 ) ;
break;
}
return 0 ;
}
static T_1 F_317 ( struct V_81 * V_140 ,
struct V_327 * V_328 )
{
return F_59 ( V_140 ) -> V_4 ;
}
static int F_318 ( struct V_81 * V_140 ,
struct V_327 * V_328 , T_1 V_46 )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
if ( V_46 >= ( 1 << V_342 ) )
return - V_269 ;
F_303 () ;
V_8 -> V_4 = V_46 ;
F_304 () ;
return 0 ;
}
static int F_318 ( struct V_81 * V_140 ,
struct V_327 * V_328 , T_1 V_46 )
{
return - V_343 ;
}
static void
F_319 ( struct V_7 * V_8 , struct V_344 * V_345 )
{
T_7 V_46 ;
V_46 = F_29 ( V_8 , V_60 ) ;
V_345 -> V_48 [ V_346 ] += V_46 * V_216 ;
V_46 = F_29 ( V_8 , V_61 ) ;
V_345 -> V_48 [ V_347 ] += V_46 * V_216 ;
V_46 = F_29 ( V_8 , V_209 ) ;
V_345 -> V_48 [ V_348 ] += V_46 * V_216 ;
V_46 = F_39 ( V_8 , V_62 ) ;
V_345 -> V_48 [ V_349 ] += V_46 ;
V_46 = F_39 ( V_8 , V_63 ) ;
V_345 -> V_48 [ V_350 ] += V_46 ;
if ( V_138 ) {
V_46 = F_29 ( V_8 , V_53 ) ;
V_345 -> V_48 [ V_351 ] += V_46 * V_216 ;
}
V_46 = F_39 ( V_8 , V_55 ) ;
V_345 -> V_48 [ V_352 ] += V_46 ;
V_46 = F_39 ( V_8 , V_56 ) ;
V_345 -> V_48 [ V_353 ] += V_46 ;
V_46 = F_50 ( V_8 , F_47 ( V_115 ) ) ;
V_345 -> V_48 [ V_354 ] += V_46 * V_216 ;
V_46 = F_50 ( V_8 , F_47 ( V_116 ) ) ;
V_345 -> V_48 [ V_355 ] += V_46 * V_216 ;
V_46 = F_50 ( V_8 , F_47 ( V_118 ) ) ;
V_345 -> V_48 [ V_356 ] += V_46 * V_216 ;
V_46 = F_50 ( V_8 , F_47 ( V_119 ) ) ;
V_345 -> V_48 [ V_357 ] += V_46 * V_216 ;
V_46 = F_50 ( V_8 , F_47 ( V_358 ) ) ;
V_345 -> V_48 [ V_359 ] += V_46 * V_216 ;
}
static void
F_320 ( struct V_7 * V_8 , struct V_344 * V_345 )
{
struct V_7 * V_92 ;
F_146 (iter, memcg)
F_319 ( V_92 , V_345 ) ;
}
static int F_321 ( struct V_360 * V_361 , void * V_188 )
{
int V_9 ;
unsigned long V_362 , V_363 , V_364 , V_365 ;
unsigned long V_366 ;
struct V_81 * V_82 = V_361 -> V_199 ;
struct V_7 * V_129 = F_59 ( V_82 ) ;
V_362 = F_50 ( V_129 , V_367 ) ;
F_322 ( V_361 , L_9 , V_362 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_366 = F_49 ( V_129 , V_9 , V_367 ) ;
F_322 ( V_361 , L_10 , V_9 , V_366 ) ;
}
F_323 ( V_361 , '\n' ) ;
V_363 = F_50 ( V_129 , V_164 ) ;
F_322 ( V_361 , L_11 , V_363 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_366 = F_49 ( V_129 , V_9 ,
V_164 ) ;
F_322 ( V_361 , L_10 , V_9 , V_366 ) ;
}
F_323 ( V_361 , '\n' ) ;
V_364 = F_50 ( V_129 , V_165 ) ;
F_322 ( V_361 , L_12 , V_364 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_366 = F_49 ( V_129 , V_9 ,
V_165 ) ;
F_322 ( V_361 , L_10 , V_9 , V_366 ) ;
}
F_323 ( V_361 , '\n' ) ;
V_365 = F_50 ( V_129 , F_47 ( V_358 ) ) ;
F_322 ( V_361 , L_13 , V_365 ) ;
F_24 (nid, N_HIGH_MEMORY) {
V_366 = F_49 ( V_129 , V_9 ,
F_47 ( V_358 ) ) ;
F_322 ( V_361 , L_10 , V_9 , V_366 ) ;
}
F_323 ( V_361 , '\n' ) ;
return 0 ;
}
static int F_324 ( struct V_81 * V_82 , struct V_327 * V_328 ,
struct V_368 * V_369 )
{
struct V_7 * V_129 = F_59 ( V_82 ) ;
struct V_344 V_370 ;
int V_223 ;
memset ( & V_370 , 0 , sizeof( V_370 ) ) ;
F_319 ( V_129 , & V_370 ) ;
for ( V_223 = 0 ; V_223 < V_371 ; V_223 ++ ) {
if ( V_223 == V_351 && ! V_138 )
continue;
V_369 -> V_372 ( V_369 , V_373 [ V_223 ] . V_374 , V_370 . V_48 [ V_223 ] ) ;
}
{
unsigned long long V_160 , V_338 ;
F_313 ( V_129 , & V_160 , & V_338 ) ;
V_369 -> V_372 ( V_369 , L_14 , V_160 ) ;
if ( V_138 )
V_369 -> V_372 ( V_369 , L_15 , V_338 ) ;
}
memset ( & V_370 , 0 , sizeof( V_370 ) ) ;
F_320 ( V_129 , & V_370 ) ;
for ( V_223 = 0 ; V_223 < V_371 ; V_223 ++ ) {
if ( V_223 == V_351 && ! V_138 )
continue;
V_369 -> V_372 ( V_369 , V_373 [ V_223 ] . V_375 , V_370 . V_48 [ V_223 ] ) ;
}
#ifdef F_325
{
int V_9 , V_10 ;
struct V_6 * V_21 ;
unsigned long V_376 [ 2 ] = { 0 , 0 } ;
unsigned long V_377 [ 2 ] = { 0 , 0 } ;
F_326 (nid)
for ( V_10 = 0 ; V_10 < V_39 ; V_10 ++ ) {
V_21 = F_4 ( V_129 , V_9 , V_10 ) ;
V_376 [ 0 ] +=
V_21 -> V_121 . V_376 [ 0 ] ;
V_376 [ 1 ] +=
V_21 -> V_121 . V_376 [ 1 ] ;
V_377 [ 0 ] +=
V_21 -> V_121 . V_377 [ 0 ] ;
V_377 [ 1 ] +=
V_21 -> V_121 . V_377 [ 1 ] ;
}
V_369 -> V_372 ( V_369 , L_16 , V_376 [ 0 ] ) ;
V_369 -> V_372 ( V_369 , L_17 , V_376 [ 1 ] ) ;
V_369 -> V_372 ( V_369 , L_18 , V_377 [ 0 ] ) ;
V_369 -> V_372 ( V_369 , L_19 , V_377 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_327 ( struct V_81 * V_140 , struct V_327 * V_328 )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
return F_127 ( V_8 ) ;
}
static int F_328 ( struct V_81 * V_140 , struct V_327 * V_328 ,
T_1 V_46 )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
struct V_7 * V_27 ;
if ( V_46 > 100 )
return - V_269 ;
if ( V_140 -> V_27 == NULL )
return - V_269 ;
V_27 = F_59 ( V_140 -> V_27 ) ;
F_303 () ;
if ( ( V_27 -> V_90 ) ||
( V_8 -> V_90 && ! F_81 ( & V_140 -> V_304 ) ) ) {
F_304 () ;
return - V_269 ;
}
V_8 -> V_142 = V_46 ;
F_304 () ;
return 0 ;
}
static void F_329 ( struct V_7 * V_8 , bool V_331 )
{
struct V_378 * V_379 ;
T_1 V_322 ;
int V_223 ;
F_64 () ;
if ( ! V_331 )
V_379 = F_65 ( V_8 -> V_380 . V_381 ) ;
else
V_379 = F_65 ( V_8 -> V_382 . V_381 ) ;
if ( ! V_379 )
goto V_144;
V_322 = F_306 ( V_8 , V_331 ) ;
V_223 = V_379 -> V_383 ;
for (; V_223 >= 0 && F_56 ( V_379 -> V_384 [ V_223 ] . V_385 > V_322 ) ; V_223 -- )
F_330 ( V_379 -> V_384 [ V_223 ] . V_386 , 1 ) ;
V_223 ++ ;
for (; V_223 < V_379 -> V_387 && F_56 ( V_379 -> V_384 [ V_223 ] . V_385 <= V_322 ) ; V_223 ++ )
F_330 ( V_379 -> V_384 [ V_223 ] . V_386 , 1 ) ;
V_379 -> V_383 = V_223 - 1 ;
V_144:
F_66 () ;
}
static void F_57 ( struct V_7 * V_8 )
{
while ( V_8 ) {
F_329 ( V_8 , false ) ;
if ( V_138 )
F_329 ( V_8 , true ) ;
V_8 = F_21 ( V_8 ) ;
}
}
static int F_331 ( const void * V_388 , const void * V_389 )
{
const struct F_57 * V_390 = V_388 ;
const struct F_57 * V_391 = V_389 ;
return V_390 -> V_385 - V_391 -> V_385 ;
}
static int F_332 ( struct V_7 * V_8 )
{
struct V_392 * V_393 ;
F_333 (ev, &memcg->oom_notify, list)
F_330 ( V_393 -> V_386 , 1 ) ;
return 0 ;
}
static void F_181 ( struct V_7 * V_8 )
{
struct V_7 * V_92 ;
F_146 (iter, memcg)
F_332 ( V_92 ) ;
}
static int F_334 ( struct V_81 * V_140 ,
struct V_327 * V_328 , struct V_394 * V_386 , const char * args )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
struct V_395 * V_380 ;
struct V_378 * V_396 ;
int type = F_308 ( V_328 -> V_199 ) ;
T_1 V_385 , V_322 ;
int V_223 , V_387 , V_68 ;
V_68 = F_311 ( args , & V_385 ) ;
if ( V_68 )
return V_68 ;
F_211 ( & V_8 -> V_397 ) ;
if ( type == V_333 )
V_380 = & V_8 -> V_380 ;
else if ( type == V_334 )
V_380 = & V_8 -> V_382 ;
else
F_74 () ;
V_322 = F_306 ( V_8 , type == V_334 ) ;
if ( V_380 -> V_381 )
F_329 ( V_8 , type == V_334 ) ;
V_387 = V_380 -> V_381 ? V_380 -> V_381 -> V_387 + 1 : 1 ;
V_396 = F_284 ( sizeof( * V_396 ) + V_387 * sizeof( struct F_57 ) ,
V_300 ) ;
if ( ! V_396 ) {
V_68 = - V_255 ;
goto V_144;
}
V_396 -> V_387 = V_387 ;
if ( V_380 -> V_381 ) {
memcpy ( V_396 -> V_384 , V_380 -> V_381 -> V_384 , ( V_387 - 1 ) *
sizeof( struct F_57 ) ) ;
}
V_396 -> V_384 [ V_387 - 1 ] . V_386 = V_386 ;
V_396 -> V_384 [ V_387 - 1 ] . V_385 = V_385 ;
F_335 ( V_396 -> V_384 , V_387 , sizeof( struct F_57 ) ,
F_331 , NULL ) ;
V_396 -> V_383 = - 1 ;
for ( V_223 = 0 ; V_223 < V_387 ; V_223 ++ ) {
if ( V_396 -> V_384 [ V_223 ] . V_385 < V_322 ) {
++ V_396 -> V_383 ;
}
}
F_285 ( V_380 -> V_398 ) ;
V_380 -> V_398 = V_380 -> V_381 ;
F_336 ( V_380 -> V_381 , V_396 ) ;
F_129 () ;
V_144:
F_209 ( & V_8 -> V_397 ) ;
return V_68 ;
}
static void F_337 ( struct V_81 * V_140 ,
struct V_327 * V_328 , struct V_394 * V_386 )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
struct V_395 * V_380 ;
struct V_378 * V_396 ;
int type = F_308 ( V_328 -> V_199 ) ;
T_1 V_322 ;
int V_223 , V_399 , V_387 ;
F_211 ( & V_8 -> V_397 ) ;
if ( type == V_333 )
V_380 = & V_8 -> V_380 ;
else if ( type == V_334 )
V_380 = & V_8 -> V_382 ;
else
F_74 () ;
F_118 ( ! V_380 ) ;
V_322 = F_306 ( V_8 , type == V_334 ) ;
F_329 ( V_8 , type == V_334 ) ;
V_387 = 0 ;
for ( V_223 = 0 ; V_223 < V_380 -> V_381 -> V_387 ; V_223 ++ ) {
if ( V_380 -> V_381 -> V_384 [ V_223 ] . V_386 != V_386 )
V_387 ++ ;
}
V_396 = V_380 -> V_398 ;
if ( ! V_387 ) {
F_285 ( V_396 ) ;
V_396 = NULL ;
goto V_400;
}
V_396 -> V_387 = V_387 ;
V_396 -> V_383 = - 1 ;
for ( V_223 = 0 , V_399 = 0 ; V_223 < V_380 -> V_381 -> V_387 ; V_223 ++ ) {
if ( V_380 -> V_381 -> V_384 [ V_223 ] . V_386 == V_386 )
continue;
V_396 -> V_384 [ V_399 ] = V_380 -> V_381 -> V_384 [ V_223 ] ;
if ( V_396 -> V_384 [ V_399 ] . V_385 < V_322 ) {
++ V_396 -> V_383 ;
}
V_399 ++ ;
}
V_400:
V_380 -> V_398 = V_380 -> V_381 ;
F_336 ( V_380 -> V_381 , V_396 ) ;
F_129 () ;
F_209 ( & V_8 -> V_397 ) ;
}
static int F_338 ( struct V_81 * V_140 ,
struct V_327 * V_328 , struct V_394 * V_386 , const char * args )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
struct V_392 * V_326 ;
int type = F_308 ( V_328 -> V_199 ) ;
F_118 ( type != V_401 ) ;
V_326 = F_284 ( sizeof( * V_326 ) , V_300 ) ;
if ( ! V_326 )
return - V_255 ;
F_18 ( & V_201 ) ;
V_326 -> V_386 = V_386 ;
F_95 ( & V_326 -> V_315 , & V_8 -> V_402 ) ;
if ( F_152 ( & V_8 -> V_186 ) )
F_330 ( V_386 , 1 ) ;
F_19 ( & V_201 ) ;
return 0 ;
}
static void F_339 ( struct V_81 * V_140 ,
struct V_327 * V_328 , struct V_394 * V_386 )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
struct V_392 * V_393 , * V_134 ;
int type = F_308 ( V_328 -> V_199 ) ;
F_118 ( type != V_401 ) ;
F_18 ( & V_201 ) ;
F_340 (ev, tmp, &memcg->oom_notify, list) {
if ( V_393 -> V_386 == V_386 ) {
F_341 ( & V_393 -> V_315 ) ;
F_285 ( V_393 ) ;
}
}
F_19 ( & V_201 ) ;
}
static int F_342 ( struct V_81 * V_140 ,
struct V_327 * V_328 , struct V_368 * V_369 )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
V_369 -> V_372 ( V_369 , L_20 , V_8 -> V_203 ) ;
if ( F_152 ( & V_8 -> V_186 ) )
V_369 -> V_372 ( V_369 , L_21 , 1 ) ;
else
V_369 -> V_372 ( V_369 , L_21 , 0 ) ;
return 0 ;
}
static int F_343 ( struct V_81 * V_140 ,
struct V_327 * V_328 , T_1 V_46 )
{
struct V_7 * V_8 = F_59 ( V_140 ) ;
struct V_7 * V_27 ;
if ( ! V_140 -> V_27 || ! ( ( V_46 == 0 ) || ( V_46 == 1 ) ) )
return - V_269 ;
V_27 = F_59 ( V_140 -> V_27 ) ;
F_303 () ;
if ( ( V_27 -> V_90 ) ||
( V_8 -> V_90 && ! F_81 ( & V_140 -> V_304 ) ) ) {
F_304 () ;
return - V_269 ;
}
V_8 -> V_203 = V_46 ;
if ( ! V_46 )
F_178 ( V_8 ) ;
F_304 () ;
return 0 ;
}
static int F_344 ( struct V_403 * V_296 , struct V_58 * V_58 )
{
struct V_81 * V_82 = V_58 -> V_404 -> V_405 -> V_406 ;
V_58 -> V_407 = & V_408 ;
return F_345 ( V_58 , F_321 , V_82 ) ;
}
static int F_346 ( struct V_81 * V_82 , struct V_409 * V_410 )
{
if ( ! V_138 )
return 0 ;
return F_347 ( V_82 , V_410 , V_411 ,
F_348 ( V_411 ) ) ;
}
static int F_346 ( struct V_81 * V_82 , struct V_409 * V_410 )
{
return 0 ;
}
static int F_349 ( struct V_7 * V_8 , int V_37 )
{
struct V_412 * V_413 ;
struct V_6 * V_21 ;
enum V_66 V_67 ;
int V_38 , V_134 = V_37 ;
if ( ! F_350 ( V_37 , V_414 ) )
V_134 = - 1 ;
V_413 = F_351 ( sizeof( * V_413 ) , V_300 , V_134 ) ;
if ( ! V_413 )
return 1 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_21 = & V_413 -> V_13 [ V_38 ] ;
F_46 (l)
F_180 ( & V_21 -> V_104 [ V_67 ] ) ;
V_21 -> V_30 = 0 ;
V_21 -> V_29 = false ;
V_21 -> V_43 = V_8 ;
}
V_8 -> V_11 . V_12 [ V_37 ] = V_413 ;
return 0 ;
}
static void F_352 ( struct V_7 * V_8 , int V_37 )
{
F_285 ( V_8 -> V_11 . V_12 [ V_37 ] ) ;
}
static struct V_7 * F_353 ( void )
{
struct V_7 * V_43 ;
int V_387 = sizeof( struct V_7 ) ;
if ( V_387 < V_216 )
V_43 = F_354 ( V_387 , V_300 ) ;
else
V_43 = F_355 ( V_387 ) ;
if ( ! V_43 )
return NULL ;
V_43 -> V_48 = F_356 ( struct V_415 ) ;
if ( ! V_43 -> V_48 )
goto V_416;
F_357 ( & V_43 -> V_50 ) ;
return V_43 ;
V_416:
if ( V_387 < V_216 )
F_285 ( V_43 ) ;
else
F_358 ( V_43 ) ;
return NULL ;
}
static void F_359 ( struct V_7 * V_8 )
{
int V_37 ;
F_23 ( V_8 ) ;
F_360 ( & V_91 , & V_8 -> V_15 ) ;
F_24 (node, N_POSSIBLE)
F_352 ( V_8 , V_37 ) ;
F_361 ( V_8 -> V_48 ) ;
if ( sizeof( struct V_7 ) < V_216 )
F_285 ( V_8 ) ;
else
F_358 ( V_8 ) ;
}
static void F_268 ( struct V_7 * V_8 )
{
F_58 ( & V_8 -> V_417 ) ;
}
static void F_362 ( struct V_7 * V_8 , int V_49 )
{
if ( F_363 ( V_49 , & V_8 -> V_417 ) ) {
struct V_7 * V_27 = F_21 ( V_8 ) ;
F_359 ( V_8 ) ;
if ( V_27 )
F_260 ( V_27 ) ;
}
}
static void F_260 ( struct V_7 * V_8 )
{
F_362 ( V_8 , 1 ) ;
}
static struct V_7 * F_21 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_36 . V_27 )
return NULL ;
return F_218 ( V_8 -> V_36 . V_27 , V_36 ) ;
}
static void T_8 F_364 ( void )
{
if ( ! F_76 () && V_418 )
V_138 = 1 ;
}
static void T_8 F_364 ( void )
{
}
static int F_365 ( void )
{
struct V_419 * V_420 ;
struct V_17 * V_421 ;
int V_134 , V_37 , V_38 ;
F_24 (node, N_POSSIBLE) {
V_134 = V_37 ;
if ( ! F_350 ( V_37 , V_414 ) )
V_134 = - 1 ;
V_420 = F_351 ( sizeof( * V_420 ) , V_300 , V_134 ) ;
if ( ! V_420 )
return 1 ;
V_18 . V_19 [ V_37 ] = V_420 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
V_421 = & V_420 -> V_20 [ V_38 ] ;
V_421 -> V_26 = V_422 ;
F_357 ( & V_421 -> V_34 ) ;
}
}
return 0 ;
}
static struct V_14 * T_9
F_366 ( struct V_409 * V_410 , struct V_81 * V_82 )
{
struct V_7 * V_8 , * V_27 ;
long error = - V_255 ;
int V_37 ;
V_8 = F_353 () ;
if ( ! V_8 )
return F_367 ( error ) ;
F_24 (node, N_POSSIBLE)
if ( F_349 ( V_8 , V_37 ) )
goto V_423;
if ( V_82 -> V_27 == NULL ) {
int V_47 ;
F_364 () ;
V_27 = NULL ;
if ( F_365 () )
goto V_423;
V_89 = V_8 ;
F_368 (cpu) {
struct V_210 * V_211 =
& F_32 ( V_212 , V_47 ) ;
F_369 ( & V_211 -> V_221 , F_198 ) ;
}
F_370 ( F_214 , 0 ) ;
} else {
V_27 = F_59 ( V_82 -> V_27 ) ;
V_8 -> V_90 = V_27 -> V_90 ;
V_8 -> V_203 = V_27 -> V_203 ;
}
if ( V_27 && V_27 -> V_90 ) {
F_371 ( & V_8 -> V_36 , & V_27 -> V_36 ) ;
F_371 ( & V_8 -> V_139 , & V_27 -> V_139 ) ;
F_268 ( V_27 ) ;
} else {
F_371 ( & V_8 -> V_36 , NULL ) ;
F_371 ( & V_8 -> V_139 , NULL ) ;
}
V_8 -> V_162 = 0 ;
V_8 -> V_170 = V_79 ;
F_180 ( & V_8 -> V_402 ) ;
if ( V_27 )
V_8 -> V_142 = F_127 ( V_27 ) ;
F_156 ( & V_8 -> V_417 , 1 ) ;
V_8 -> V_4 = 0 ;
F_372 ( & V_8 -> V_397 ) ;
return & V_8 -> V_15 ;
V_423:
F_359 ( V_8 ) ;
return F_367 ( error ) ;
}
static int F_373 ( struct V_409 * V_410 ,
struct V_81 * V_82 )
{
struct V_7 * V_8 = F_59 ( V_82 ) ;
return F_295 ( V_8 , false ) ;
}
static void F_374 ( struct V_409 * V_410 ,
struct V_81 * V_82 )
{
struct V_7 * V_8 = F_59 ( V_82 ) ;
F_260 ( V_8 ) ;
}
static int F_375 ( struct V_409 * V_410 ,
struct V_81 * V_82 )
{
int V_68 ;
V_68 = F_347 ( V_82 , V_410 , V_424 ,
F_348 ( V_424 ) ) ;
if ( ! V_68 )
V_68 = F_346 ( V_82 , V_410 ) ;
return V_68 ;
}
static int F_376 ( unsigned long V_49 )
{
int V_68 = 0 ;
int V_425 = V_426 ;
struct V_7 * V_8 = V_2 . V_3 ;
if ( F_72 ( V_8 ) ) {
V_2 . V_427 += V_49 ;
return V_68 ;
}
if ( V_49 > 1 ) {
struct V_238 * V_218 ;
if ( F_217 ( & V_8 -> V_36 , V_216 * V_49 , & V_218 ) )
goto V_428;
if ( V_138 && F_217 ( & V_8 -> V_139 ,
V_216 * V_49 , & V_218 ) ) {
F_197 ( & V_8 -> V_36 , V_216 * V_49 ) ;
goto V_428;
}
V_2 . V_427 += V_49 ;
return V_68 ;
}
V_428:
while ( V_49 -- ) {
if ( F_287 ( V_146 ) ) {
V_68 = - V_308 ;
break;
}
if ( ! V_425 -- ) {
V_425 = V_426 ;
F_294 () ;
}
V_68 = F_219 ( NULL ,
V_300 , 1 , & V_8 , false ) ;
if ( V_68 || ! V_8 )
return - V_255 ;
V_2 . V_427 ++ ;
}
return V_68 ;
}
static struct V_16 * F_377 ( struct V_429 * V_430 ,
unsigned long V_431 , T_10 V_432 )
{
struct V_16 * V_16 = F_378 ( V_430 , V_431 , V_432 ) ;
if ( ! V_16 || ! F_190 ( V_16 ) )
return NULL ;
if ( F_251 ( V_16 ) ) {
if ( ! F_1 () || F_379 ( V_16 ) > 2 )
return NULL ;
} else if ( ! F_3 () )
return NULL ;
if ( ! F_243 ( V_16 ) )
return NULL ;
return V_16 ;
}
static struct V_16 * F_380 ( struct V_429 * V_430 ,
unsigned long V_431 , T_10 V_432 , T_6 * V_288 )
{
int V_433 ;
struct V_16 * V_16 = NULL ;
T_6 V_257 = F_381 ( V_432 ) ;
if ( ! F_1 () || F_382 ( V_257 ) )
return NULL ;
V_433 = F_383 ( V_257 , & V_16 ) ;
if ( V_433 > 1 ) {
if ( V_16 )
F_248 ( V_16 ) ;
return NULL ;
}
if ( V_138 )
V_288 -> V_46 = V_257 . V_46 ;
return V_16 ;
}
static struct V_16 * F_384 ( struct V_429 * V_430 ,
unsigned long V_431 , T_10 V_432 , T_6 * V_288 )
{
struct V_16 * V_16 = NULL ;
struct V_403 * V_403 ;
struct V_434 * V_275 ;
T_11 V_435 ;
if ( ! V_430 -> V_436 )
return NULL ;
if ( ! F_3 () )
return NULL ;
V_403 = V_430 -> V_436 -> V_437 . V_438 -> V_439 ;
V_275 = V_430 -> V_436 -> V_440 ;
if ( F_385 ( V_432 ) )
V_435 = F_386 ( V_430 , V_431 ) ;
else
V_435 = F_387 ( V_432 ) ;
V_16 = F_388 ( V_275 , V_435 ) ;
#ifdef F_389
if ( F_390 ( V_16 ) ) {
T_6 V_331 = F_391 ( V_16 ) ;
if ( V_138 )
* V_288 = V_331 ;
V_16 = F_388 ( & V_441 , V_331 . V_46 ) ;
}
#endif
return V_16 ;
}
static int F_392 ( struct V_429 * V_430 ,
unsigned long V_431 , T_10 V_432 , union V_442 * V_70 )
{
struct V_16 * V_16 = NULL ;
struct V_102 * V_103 ;
int V_68 = 0 ;
T_6 V_257 = { . V_46 = 0 } ;
if ( F_393 ( V_432 ) )
V_16 = F_377 ( V_430 , V_431 , V_432 ) ;
else if ( F_394 ( V_432 ) )
V_16 = F_380 ( V_430 , V_431 , V_432 , & V_257 ) ;
else if ( F_385 ( V_432 ) || F_395 ( V_432 ) )
V_16 = F_384 ( V_430 , V_431 , V_432 , & V_257 ) ;
if ( ! V_16 && ! V_257 . V_46 )
return 0 ;
if ( V_16 ) {
V_103 = F_77 ( V_16 ) ;
if ( F_86 ( V_103 ) && V_103 -> V_7 == V_2 . V_107 ) {
V_68 = V_443 ;
if ( V_70 )
V_70 -> V_16 = V_16 ;
}
if ( ! V_68 || ! V_70 )
F_248 ( V_16 ) ;
}
if ( V_257 . V_46 && ! V_68 &&
F_70 ( & V_2 . V_107 -> V_15 ) == F_230 ( V_257 ) ) {
V_68 = V_444 ;
if ( V_70 )
V_70 -> V_257 = V_257 ;
}
return V_68 ;
}
static int F_396 ( T_12 * V_445 ,
unsigned long V_431 , unsigned long V_446 ,
struct V_447 * V_448 )
{
struct V_429 * V_430 = V_448 -> V_199 ;
T_10 * V_449 ;
T_13 * V_450 ;
F_397 ( V_448 -> V_86 , V_445 ) ;
V_449 = F_398 ( V_430 -> V_451 , V_445 , V_431 , & V_450 ) ;
for (; V_431 != V_446 ; V_449 ++ , V_431 += V_216 )
if ( F_392 ( V_430 , V_431 , * V_449 , NULL ) )
V_2 . V_427 ++ ;
F_399 ( V_449 - 1 , V_450 ) ;
F_294 () ;
return 0 ;
}
static unsigned long F_400 ( struct V_85 * V_86 )
{
unsigned long V_427 ;
struct V_429 * V_430 ;
F_401 ( & V_86 -> V_452 ) ;
for ( V_430 = V_86 -> V_453 ; V_430 ; V_430 = V_430 -> V_454 ) {
struct V_447 V_455 = {
. V_456 = F_396 ,
. V_86 = V_86 ,
. V_199 = V_430 ,
} ;
if ( F_402 ( V_430 ) )
continue;
F_403 ( V_430 -> V_457 , V_430 -> V_458 ,
& V_455 ) ;
}
F_404 ( & V_86 -> V_452 ) ;
V_427 = V_2 . V_427 ;
V_2 . V_427 = 0 ;
return V_427 ;
}
static int F_405 ( struct V_85 * V_86 )
{
unsigned long V_427 = F_400 ( V_86 ) ;
F_79 ( V_2 . V_145 ) ;
V_2 . V_145 = V_146 ;
return F_376 ( V_427 ) ;
}
static void F_406 ( void )
{
struct V_7 * V_107 = V_2 . V_107 ;
struct V_7 * V_3 = V_2 . V_3 ;
if ( V_2 . V_427 ) {
F_222 ( V_2 . V_3 , V_2 . V_427 ) ;
V_2 . V_427 = 0 ;
}
if ( V_2 . V_459 ) {
F_222 ( V_2 . V_107 , V_2 . V_459 ) ;
V_2 . V_459 = 0 ;
}
if ( V_2 . V_460 ) {
if ( ! F_72 ( V_2 . V_107 ) )
F_197 ( & V_2 . V_107 -> V_139 ,
V_216 * V_2 . V_460 ) ;
F_362 ( V_2 . V_107 , V_2 . V_460 ) ;
if ( ! F_72 ( V_2 . V_3 ) ) {
F_197 ( & V_2 . V_3 -> V_36 ,
V_216 * V_2 . V_460 ) ;
}
V_2 . V_460 = 0 ;
}
F_178 ( V_107 ) ;
F_178 ( V_3 ) ;
F_407 ( & V_2 . V_148 ) ;
}
static void F_408 ( void )
{
struct V_7 * V_107 = V_2 . V_107 ;
V_2 . V_145 = NULL ;
F_406 () ;
F_18 ( & V_2 . V_34 ) ;
V_2 . V_107 = NULL ;
V_2 . V_3 = NULL ;
F_19 ( & V_2 . V_34 ) ;
F_130 ( V_107 ) ;
}
static int F_409 ( struct V_409 * V_410 ,
struct V_81 * V_81 ,
struct V_84 * V_25 )
{
int V_68 = 0 ;
struct V_7 * V_8 = F_59 ( V_81 ) ;
if ( V_8 -> V_4 ) {
struct V_85 * V_86 ;
struct V_7 * V_107 = F_61 ( V_25 ) ;
F_79 ( V_107 == V_8 ) ;
V_86 = F_410 ( V_25 ) ;
if ( ! V_86 )
return 0 ;
if ( V_86 -> V_87 == V_25 ) {
F_79 ( V_2 . V_107 ) ;
F_79 ( V_2 . V_3 ) ;
F_79 ( V_2 . V_427 ) ;
F_79 ( V_2 . V_459 ) ;
F_79 ( V_2 . V_460 ) ;
F_128 ( V_107 ) ;
F_18 ( & V_2 . V_34 ) ;
V_2 . V_107 = V_107 ;
V_2 . V_3 = V_8 ;
F_19 ( & V_2 . V_34 ) ;
V_68 = F_405 ( V_86 ) ;
if ( V_68 )
F_408 () ;
}
F_411 ( V_86 ) ;
}
return V_68 ;
}
static void F_412 ( struct V_409 * V_410 ,
struct V_81 * V_81 ,
struct V_84 * V_25 )
{
F_408 () ;
}
static int F_413 ( T_12 * V_445 ,
unsigned long V_431 , unsigned long V_446 ,
struct V_447 * V_448 )
{
int V_68 = 0 ;
struct V_429 * V_430 = V_448 -> V_199 ;
T_10 * V_449 ;
T_13 * V_450 ;
F_397 ( V_448 -> V_86 , V_445 ) ;
V_41:
V_449 = F_398 ( V_430 -> V_451 , V_445 , V_431 , & V_450 ) ;
for (; V_431 != V_446 ; V_431 += V_216 ) {
T_10 V_432 = * ( V_449 ++ ) ;
union V_442 V_70 ;
int type ;
struct V_16 * V_16 ;
struct V_102 * V_103 ;
T_6 V_257 ;
if ( ! V_2 . V_427 )
break;
type = F_392 ( V_430 , V_431 , V_432 , & V_70 ) ;
switch ( type ) {
case V_443 :
V_16 = V_70 . V_16 ;
if ( F_244 ( V_16 ) )
goto V_273;
V_103 = F_77 ( V_16 ) ;
if ( ! F_239 ( V_16 , 1 , V_103 ,
V_2 . V_107 , V_2 . V_3 , false ) ) {
V_2 . V_427 -- ;
V_2 . V_459 ++ ;
}
F_247 ( V_16 ) ;
V_273:
F_248 ( V_16 ) ;
break;
case V_444 :
V_257 = V_70 . V_257 ;
if ( ! F_275 ( V_257 ,
V_2 . V_107 , V_2 . V_3 , false ) ) {
V_2 . V_427 -- ;
V_2 . V_460 ++ ;
}
break;
default:
break;
}
}
F_399 ( V_449 - 1 , V_450 ) ;
F_294 () ;
if ( V_431 != V_446 ) {
V_68 = F_376 ( 1 ) ;
if ( ! V_68 )
goto V_41;
}
return V_68 ;
}
static void F_414 ( struct V_85 * V_86 )
{
struct V_429 * V_430 ;
F_297 () ;
V_41:
if ( F_56 ( ! F_415 ( & V_86 -> V_452 ) ) ) {
F_406 () ;
F_294 () ;
goto V_41;
}
for ( V_430 = V_86 -> V_453 ; V_430 ; V_430 = V_430 -> V_454 ) {
int V_68 ;
struct V_447 V_461 = {
. V_456 = F_413 ,
. V_86 = V_86 ,
. V_199 = V_430 ,
} ;
if ( F_402 ( V_430 ) )
continue;
V_68 = F_403 ( V_430 -> V_457 , V_430 -> V_458 ,
& V_461 ) ;
if ( V_68 )
break;
}
F_404 ( & V_86 -> V_452 ) ;
}
static void F_416 ( struct V_409 * V_410 ,
struct V_81 * V_82 ,
struct V_81 * V_462 ,
struct V_84 * V_25 )
{
struct V_85 * V_86 = F_410 ( V_25 ) ;
if ( V_86 ) {
if ( V_2 . V_3 )
F_414 ( V_86 ) ;
F_417 ( V_86 ) ;
F_411 ( V_86 ) ;
}
if ( V_2 . V_3 )
F_408 () ;
}
static int F_409 ( struct V_409 * V_410 ,
struct V_81 * V_81 ,
struct V_84 * V_25 )
{
return 0 ;
}
static void F_412 ( struct V_409 * V_410 ,
struct V_81 * V_81 ,
struct V_84 * V_25 )
{
}
static void F_416 ( struct V_409 * V_410 ,
struct V_81 * V_82 ,
struct V_81 * V_462 ,
struct V_84 * V_25 )
{
}
static int T_8 F_418 ( char * V_345 )
{
if ( ! strcmp ( V_345 , L_22 ) )
V_418 = 1 ;
else if ( ! strcmp ( V_345 , L_23 ) )
V_418 = 0 ;
return 1 ;
}
