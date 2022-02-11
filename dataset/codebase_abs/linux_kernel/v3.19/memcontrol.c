static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 >= 0 ;
}
static bool F_2 ( void )
{
return F_3 ( V_4 , & V_5 . V_6 ) ;
}
static bool F_4 ( void )
{
return F_3 ( V_7 , & V_5 . V_6 ) ;
}
struct V_1 * F_5 ( struct V_8 * V_9 )
{
return V_9 ? F_6 ( V_9 , struct V_1 , V_10 ) : NULL ;
}
struct V_11 * F_7 ( struct V_1 * V_2 )
{
if ( ! V_2 )
V_2 = V_12 ;
return & V_2 -> V_11 ;
}
struct V_8 * F_8 ( struct V_11 * V_13 )
{
return & F_6 ( V_13 , struct V_1 , V_11 ) -> V_10 ;
}
static inline bool F_9 ( struct V_1 * V_2 )
{
return ( V_2 == V_12 ) ;
}
static inline unsigned short F_10 ( struct V_1 * V_2 )
{
return V_2 -> V_10 . V_14 ;
}
static inline struct V_1 * F_11 ( unsigned short V_14 )
{
struct V_8 * V_10 ;
V_10 = F_12 ( V_14 , & V_15 ) ;
return F_5 ( V_10 ) ;
}
void F_13 ( struct V_16 * V_17 )
{
if ( V_18 ) {
struct V_1 * V_2 ;
struct V_19 * V_19 ;
F_14 ( ! V_17 -> V_20 -> V_21 ) ;
if ( V_17 -> V_22 ) {
F_14 ( F_9 ( V_17 -> V_22 -> V_2 ) ) ;
F_15 ( & V_17 -> V_22 -> V_2 -> V_10 ) ;
return;
}
F_16 () ;
V_2 = F_17 ( V_23 ) ;
V_19 = V_17 -> V_20 -> V_21 ( V_2 ) ;
if ( ! F_9 ( V_2 ) &&
F_18 ( V_19 ) &&
F_19 ( & V_2 -> V_10 ) ) {
V_17 -> V_22 = V_19 ;
}
F_20 () ;
}
}
void F_21 ( struct V_16 * V_17 )
{
if ( V_18 && V_17 -> V_22 ) {
struct V_1 * V_2 ;
F_22 ( ! V_17 -> V_22 -> V_2 ) ;
V_2 = V_17 -> V_22 -> V_2 ;
F_23 ( & V_17 -> V_22 -> V_2 -> V_10 ) ;
}
}
struct V_19 * F_24 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_9 ( V_2 ) )
return NULL ;
return & V_2 -> V_24 ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( ! F_26 ( & V_2 -> V_24 ) )
return;
F_27 ( & V_25 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_28 ( struct V_1 * V_2 )
{
if ( F_1 ( V_2 ) ) {
F_27 ( & V_26 ) ;
F_29 ( V_2 -> V_3 ) ;
}
F_22 ( F_30 ( & V_2 -> V_27 ) ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
}
static void F_31 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_28 ( V_2 ) ;
}
static struct V_28 *
F_32 ( struct V_1 * V_2 , struct V_29 * V_29 )
{
int V_30 = F_33 ( V_29 ) ;
int V_31 = F_34 ( V_29 ) ;
return & V_2 -> V_32 [ V_30 ] -> V_33 [ V_31 ] ;
}
struct V_8 * F_35 ( struct V_1 * V_2 )
{
return & V_2 -> V_10 ;
}
static struct V_28 *
F_36 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
int V_30 = F_37 ( V_34 ) ;
int V_31 = F_38 ( V_34 ) ;
return & V_2 -> V_32 [ V_30 ] -> V_33 [ V_31 ] ;
}
static struct V_35 *
F_39 ( int V_30 , int V_31 )
{
return & V_36 . V_37 [ V_30 ] -> V_38 [ V_31 ] ;
}
static struct V_35 *
F_40 ( struct V_34 * V_34 )
{
int V_30 = F_37 ( V_34 ) ;
int V_31 = F_38 ( V_34 ) ;
return & V_36 . V_37 [ V_30 ] -> V_38 [ V_31 ] ;
}
static void F_41 ( struct V_28 * V_39 ,
struct V_35 * V_40 ,
unsigned long V_41 )
{
struct V_42 * * V_43 = & V_40 -> V_44 . V_42 ;
struct V_42 * V_45 = NULL ;
struct V_28 * V_46 ;
if ( V_39 -> V_47 )
return;
V_39 -> V_48 = V_41 ;
if ( ! V_39 -> V_48 )
return;
while ( * V_43 ) {
V_45 = * V_43 ;
V_46 = F_42 ( V_45 , struct V_28 ,
V_49 ) ;
if ( V_39 -> V_48 < V_46 -> V_48 )
V_43 = & ( * V_43 ) -> V_50 ;
else if ( V_39 -> V_48 >= V_46 -> V_48 )
V_43 = & ( * V_43 ) -> V_51 ;
}
F_43 ( & V_39 -> V_49 , V_45 , V_43 ) ;
F_44 ( & V_39 -> V_49 , & V_40 -> V_44 ) ;
V_39 -> V_47 = true ;
}
static void F_45 ( struct V_28 * V_39 ,
struct V_35 * V_40 )
{
if ( ! V_39 -> V_47 )
return;
F_46 ( & V_39 -> V_49 , & V_40 -> V_44 ) ;
V_39 -> V_47 = false ;
}
static void F_47 ( struct V_28 * V_39 ,
struct V_35 * V_40 )
{
unsigned long V_52 ;
F_48 ( & V_40 -> V_53 , V_52 ) ;
F_45 ( V_39 , V_40 ) ;
F_49 ( & V_40 -> V_53 , V_52 ) ;
}
static unsigned long F_50 ( struct V_1 * V_2 )
{
unsigned long V_54 = F_30 ( & V_2 -> V_55 ) ;
unsigned long V_56 = F_51 ( V_2 -> V_56 ) ;
unsigned long V_57 = 0 ;
if ( V_54 > V_56 )
V_57 = V_54 - V_56 ;
return V_57 ;
}
static void F_52 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
unsigned long V_57 ;
struct V_28 * V_39 ;
struct V_35 * V_40 ;
V_40 = F_40 ( V_34 ) ;
for (; V_2 ; V_2 = F_53 ( V_2 ) ) {
V_39 = F_36 ( V_2 , V_34 ) ;
V_57 = F_50 ( V_2 ) ;
if ( V_57 || V_39 -> V_47 ) {
unsigned long V_52 ;
F_48 ( & V_40 -> V_53 , V_52 ) ;
if ( V_39 -> V_47 )
F_45 ( V_39 , V_40 ) ;
F_41 ( V_39 , V_40 , V_57 ) ;
F_49 ( & V_40 -> V_53 , V_52 ) ;
}
}
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_35 * V_40 ;
struct V_28 * V_39 ;
int V_30 , V_31 ;
F_55 (nid) {
for ( V_31 = 0 ; V_31 < V_58 ; V_31 ++ ) {
V_39 = & V_2 -> V_32 [ V_30 ] -> V_33 [ V_31 ] ;
V_40 = F_39 ( V_30 , V_31 ) ;
F_47 ( V_39 , V_40 ) ;
}
}
}
static struct V_28 *
F_56 ( struct V_35 * V_40 )
{
struct V_42 * V_59 = NULL ;
struct V_28 * V_39 ;
V_60:
V_39 = NULL ;
V_59 = F_57 ( & V_40 -> V_44 ) ;
if ( ! V_59 )
goto V_61;
V_39 = F_42 ( V_59 , struct V_28 , V_49 ) ;
F_45 ( V_39 , V_40 ) ;
if ( ! F_50 ( V_39 -> V_2 ) ||
! F_19 ( & V_39 -> V_2 -> V_10 ) )
goto V_60;
V_61:
return V_39 ;
}
static struct V_28 *
F_58 ( struct V_35 * V_40 )
{
struct V_28 * V_39 ;
F_59 ( & V_40 -> V_53 ) ;
V_39 = F_56 ( V_40 ) ;
F_60 ( & V_40 -> V_53 ) ;
return V_39 ;
}
static long F_61 ( struct V_1 * V_2 ,
enum V_62 V_63 )
{
long V_64 = 0 ;
int V_65 ;
F_62 () ;
F_63 (cpu)
V_64 += F_64 ( V_2 -> V_66 -> V_67 [ V_63 ] , V_65 ) ;
#ifdef F_65
F_66 ( & V_2 -> V_68 ) ;
V_64 += V_2 -> V_69 . V_67 [ V_63 ] ;
F_67 ( & V_2 -> V_68 ) ;
#endif
F_68 () ;
return V_64 ;
}
static unsigned long F_69 ( struct V_1 * V_2 ,
enum V_70 V_63 )
{
unsigned long V_64 = 0 ;
int V_65 ;
F_62 () ;
F_63 (cpu)
V_64 += F_64 ( V_2 -> V_66 -> V_71 [ V_63 ] , V_65 ) ;
#ifdef F_65
F_66 ( & V_2 -> V_68 ) ;
V_64 += V_2 -> V_69 . V_71 [ V_63 ] ;
F_67 ( & V_2 -> V_68 ) ;
#endif
F_68 () ;
return V_64 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_34 * V_34 ,
int V_54 )
{
if ( F_71 ( V_34 ) )
F_72 ( V_2 -> V_66 -> V_67 [ V_72 ] ,
V_54 ) ;
else
F_72 ( V_2 -> V_66 -> V_67 [ V_73 ] ,
V_54 ) ;
if ( F_73 ( V_34 ) )
F_72 ( V_2 -> V_66 -> V_67 [ V_74 ] ,
V_54 ) ;
if ( V_54 > 0 )
F_74 ( V_2 -> V_66 -> V_71 [ V_75 ] ) ;
else {
F_74 ( V_2 -> V_66 -> V_71 [ V_76 ] ) ;
V_54 = - V_54 ;
}
F_72 ( V_2 -> V_66 -> V_77 , V_54 ) ;
}
unsigned long F_75 ( struct V_78 * V_78 , enum V_79 V_80 )
{
struct V_28 * V_39 ;
V_39 = F_6 ( V_78 , struct V_28 , V_78 ) ;
return V_39 -> V_81 [ V_80 ] ;
}
static unsigned long F_76 ( struct V_1 * V_2 ,
int V_30 ,
unsigned int V_82 )
{
unsigned long V_83 = 0 ;
int V_31 ;
F_77 ( ( unsigned ) V_30 >= V_84 ) ;
for ( V_31 = 0 ; V_31 < V_58 ; V_31 ++ ) {
struct V_28 * V_39 ;
enum V_79 V_80 ;
F_78 (lru) {
if ( ! ( F_79 ( V_80 ) & V_82 ) )
continue;
V_39 = & V_2 -> V_32 [ V_30 ] -> V_33 [ V_31 ] ;
V_83 += V_39 -> V_81 [ V_80 ] ;
}
}
return V_83 ;
}
static unsigned long F_80 ( struct V_1 * V_2 ,
unsigned int V_82 )
{
unsigned long V_83 = 0 ;
int V_30 ;
F_81 (nid, N_MEMORY)
V_83 += F_76 ( V_2 , V_30 , V_82 ) ;
return V_83 ;
}
static bool F_82 ( struct V_1 * V_2 ,
enum V_85 V_86 )
{
unsigned long V_64 , V_87 ;
V_64 = F_83 ( V_2 -> V_66 -> V_77 ) ;
V_87 = F_83 ( V_2 -> V_66 -> V_88 [ V_86 ] ) ;
if ( ( long ) V_87 - ( long ) V_64 < 0 ) {
switch ( V_86 ) {
case V_89 :
V_87 = V_64 + V_90 ;
break;
case V_91 :
V_87 = V_64 + V_92 ;
break;
case V_93 :
V_87 = V_64 + V_94 ;
break;
default:
break;
}
F_84 ( V_2 -> V_66 -> V_88 [ V_86 ] , V_87 ) ;
return true ;
}
return false ;
}
static void F_85 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
if ( F_86 ( F_82 ( V_2 ,
V_89 ) ) ) {
bool V_95 ;
bool T_1 V_96 ;
V_95 = F_82 ( V_2 ,
V_91 ) ;
#if V_97 > 1
T_1 = F_82 ( V_2 ,
V_93 ) ;
#endif
F_87 ( V_2 ) ;
if ( F_86 ( V_95 ) )
F_52 ( V_2 , V_34 ) ;
#if V_97 > 1
if ( F_86 ( T_1 ) )
F_88 ( & V_2 -> V_98 ) ;
#endif
}
}
struct V_1 * F_17 ( struct V_99 * V_43 )
{
if ( F_86 ( ! V_43 ) )
return NULL ;
return F_5 ( F_89 ( V_43 , V_100 ) ) ;
}
static struct V_1 * F_90 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = NULL ;
F_16 () ;
do {
if ( F_86 ( ! V_102 ) )
V_2 = V_12 ;
else {
V_2 = F_17 ( F_91 ( V_102 -> V_103 ) ) ;
if ( F_86 ( ! V_2 ) )
V_2 = V_12 ;
}
} while ( ! F_19 ( & V_2 -> V_10 ) );
F_20 () ;
return V_2 ;
}
struct V_1 * F_92 ( struct V_1 * V_104 ,
struct V_1 * V_105 ,
struct V_106 * V_107 )
{
struct V_108 * V_109 ( V_110 ) ;
struct V_8 * V_10 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_111 = NULL ;
if ( F_93 () )
return NULL ;
if ( ! V_104 )
V_104 = V_12 ;
if ( V_105 && ! V_107 )
V_111 = V_105 ;
if ( ! V_104 -> V_112 && V_104 != V_12 ) {
if ( V_105 )
goto V_113;
return V_104 ;
}
F_16 () ;
if ( V_107 ) {
struct V_28 * V_39 ;
V_39 = F_32 ( V_104 , V_107 -> V_29 ) ;
V_110 = & V_39 -> V_110 [ V_107 -> V_114 ] ;
if ( V_105 && V_107 -> V_115 != V_110 -> V_115 )
goto V_116;
do {
V_111 = F_51 ( V_110 -> V_117 ) ;
} while ( V_111 && ! F_94 ( & V_111 -> V_10 ) );
}
if ( V_111 )
V_10 = & V_111 -> V_10 ;
for (; ; ) {
V_10 = F_95 ( V_10 , & V_104 -> V_10 ) ;
if ( ! V_10 ) {
if ( ! V_105 )
continue;
break;
}
V_2 = F_5 ( V_10 ) ;
if ( V_10 == & V_104 -> V_10 )
break;
if ( F_94 ( V_10 ) ) {
if ( F_96 ( & V_2 -> V_118 ) )
break;
F_23 ( V_10 ) ;
}
V_2 = NULL ;
}
if ( V_107 ) {
if ( F_97 ( & V_110 -> V_117 , V_111 , V_2 ) == V_111 ) {
if ( V_2 )
F_15 ( & V_2 -> V_10 ) ;
if ( V_111 )
F_23 ( & V_111 -> V_10 ) ;
}
if ( V_111 )
F_23 ( & V_111 -> V_10 ) ;
if ( ! V_2 )
V_110 -> V_115 ++ ;
else if ( ! V_105 )
V_107 -> V_115 = V_110 -> V_115 ;
}
V_116:
F_20 () ;
V_113:
if ( V_105 && V_105 != V_104 )
F_23 ( & V_105 -> V_10 ) ;
return V_2 ;
}
void F_98 ( struct V_1 * V_104 ,
struct V_1 * V_105 )
{
if ( ! V_104 )
V_104 = V_12 ;
if ( V_105 && V_105 != V_104 )
F_23 ( & V_105 -> V_10 ) ;
}
void F_99 ( struct V_101 * V_102 , enum V_119 V_63 )
{
struct V_1 * V_2 ;
F_16 () ;
V_2 = F_17 ( F_91 ( V_102 -> V_103 ) ) ;
if ( F_86 ( ! V_2 ) )
goto V_113;
switch ( V_63 ) {
case V_120 :
F_100 ( V_2 -> V_66 -> V_71 [ V_121 ] ) ;
break;
case V_122 :
F_100 ( V_2 -> V_66 -> V_71 [ V_123 ] ) ;
break;
default:
F_101 () ;
}
V_113:
F_20 () ;
}
struct V_78 * F_102 ( struct V_29 * V_29 ,
struct V_1 * V_2 )
{
struct V_28 * V_39 ;
struct V_78 * V_78 ;
if ( F_93 () ) {
V_78 = & V_29 -> V_78 ;
goto V_113;
}
V_39 = F_32 ( V_2 , V_29 ) ;
V_78 = & V_39 -> V_78 ;
V_113:
if ( F_86 ( V_78 -> V_29 != V_29 ) )
V_78 -> V_29 = V_29 ;
return V_78 ;
}
struct V_78 * F_103 ( struct V_34 * V_34 , struct V_29 * V_29 )
{
struct V_28 * V_39 ;
struct V_1 * V_2 ;
struct V_78 * V_78 ;
if ( F_93 () ) {
V_78 = & V_29 -> V_78 ;
goto V_113;
}
V_2 = V_34 -> V_1 ;
if ( ! V_2 )
V_2 = V_12 ;
V_39 = F_36 ( V_2 , V_34 ) ;
V_78 = & V_39 -> V_78 ;
V_113:
if ( F_86 ( V_78 -> V_29 != V_29 ) )
V_78 -> V_29 = V_29 ;
return V_78 ;
}
void F_104 ( struct V_78 * V_78 , enum V_79 V_80 ,
int V_54 )
{
struct V_28 * V_39 ;
unsigned long * V_81 ;
if ( F_93 () )
return;
V_39 = F_6 ( V_78 , struct V_28 , V_78 ) ;
V_81 = V_39 -> V_81 + V_80 ;
* V_81 += V_54 ;
F_77 ( ( long ) ( * V_81 ) < 0 ) ;
}
bool F_105 ( struct V_1 * V_2 , struct V_1 * V_104 )
{
if ( V_104 == V_2 )
return true ;
if ( ! V_104 -> V_112 )
return false ;
return F_106 ( V_2 -> V_10 . V_124 , V_104 -> V_10 . V_124 ) ;
}
bool F_107 ( struct V_99 * V_125 , struct V_1 * V_2 )
{
struct V_1 * V_126 ;
struct V_99 * V_43 ;
bool V_127 ;
V_43 = F_108 ( V_125 ) ;
if ( V_43 ) {
V_126 = F_90 ( V_43 -> V_102 ) ;
F_109 ( V_43 ) ;
} else {
F_16 () ;
V_126 = F_17 ( V_125 ) ;
F_15 ( & V_126 -> V_10 ) ;
F_20 () ;
}
V_127 = F_105 ( V_126 , V_2 ) ;
F_23 ( & V_126 -> V_10 ) ;
return V_127 ;
}
int F_110 ( struct V_78 * V_78 )
{
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_130 ;
unsigned long V_131 ;
V_129 = F_75 ( V_78 , V_132 ) ;
V_130 = F_75 ( V_78 , V_133 ) ;
V_131 = ( V_129 + V_130 ) >> ( 30 - V_134 ) ;
if ( V_131 )
V_128 = F_111 ( 10 * V_131 ) ;
else
V_128 = 1 ;
return V_129 * V_128 < V_130 ;
}
static unsigned long F_112 ( struct V_1 * V_2 )
{
unsigned long V_135 = 0 ;
unsigned long V_67 ;
unsigned long V_136 ;
V_67 = F_30 ( & V_2 -> V_55 ) ;
V_136 = F_51 ( V_2 -> V_55 . V_136 ) ;
if ( V_67 < V_136 )
V_135 = V_136 - V_67 ;
if ( V_137 ) {
V_67 = F_30 ( & V_2 -> V_138 ) ;
V_136 = F_51 ( V_2 -> V_138 . V_136 ) ;
if ( V_67 <= V_136 )
V_135 = F_113 ( V_135 , V_136 - V_67 ) ;
}
return V_135 ;
}
int F_114 ( struct V_1 * V_2 )
{
if ( F_93 () || ! V_2 -> V_10 . V_45 )
return V_139 ;
return V_2 -> V_140 ;
}
static bool F_115 ( struct V_1 * V_2 )
{
struct V_1 * V_141 ;
struct V_1 * V_142 ;
bool V_127 = false ;
F_66 ( & V_5 . V_53 ) ;
V_141 = V_5 . V_141 ;
V_142 = V_5 . V_142 ;
if ( ! V_141 )
goto V_143;
V_127 = F_105 ( V_141 , V_2 ) ||
F_105 ( V_142 , V_2 ) ;
V_143:
F_67 ( & V_5 . V_53 ) ;
return V_127 ;
}
static bool F_116 ( struct V_1 * V_2 )
{
if ( V_5 . V_144 && V_23 != V_5 . V_144 ) {
if ( F_115 ( V_2 ) ) {
F_117 ( V_145 ) ;
F_118 ( & V_5 . V_146 , & V_145 , V_147 ) ;
if ( V_5 . V_144 )
F_119 () ;
F_120 ( & V_5 . V_146 , & V_145 ) ;
return true ;
}
}
return false ;
}
void F_121 ( struct V_1 * V_2 , struct V_99 * V_43 )
{
static F_122 ( V_148 ) ;
struct V_1 * V_110 ;
unsigned int V_149 ;
if ( ! V_43 )
return;
F_123 ( & V_148 ) ;
F_16 () ;
F_124 ( L_1 ) ;
F_125 ( F_126 ( V_43 , V_100 ) ) ;
F_127 ( L_2 ) ;
F_125 ( V_2 -> V_10 . V_124 ) ;
F_127 ( L_3 ) ;
F_20 () ;
F_124 ( L_4 ,
F_128 ( ( V_150 ) F_30 ( & V_2 -> V_55 ) ) ,
F_128 ( ( V_150 ) V_2 -> V_55 . V_136 ) , V_2 -> V_55 . V_151 ) ;
F_124 ( L_5 ,
F_128 ( ( V_150 ) F_30 ( & V_2 -> V_138 ) ) ,
F_128 ( ( V_150 ) V_2 -> V_138 . V_136 ) , V_2 -> V_138 . V_151 ) ;
F_124 ( L_6 ,
F_128 ( ( V_150 ) F_30 ( & V_2 -> V_27 ) ) ,
F_128 ( ( V_150 ) V_2 -> V_27 . V_136 ) , V_2 -> V_27 . V_151 ) ;
F_129 (iter, memcg) {
F_124 ( L_7 ) ;
F_125 ( V_110 -> V_10 . V_124 ) ;
F_127 ( L_8 ) ;
for ( V_149 = 0 ; V_149 < V_152 ; V_149 ++ ) {
if ( V_149 == V_153 && ! V_137 )
continue;
F_127 ( L_9 , V_154 [ V_149 ] ,
F_128 ( F_61 ( V_110 , V_149 ) ) ) ;
}
for ( V_149 = 0 ; V_149 < V_155 ; V_149 ++ )
F_127 ( L_10 , V_156 [ V_149 ] ,
F_128 ( F_80 ( V_110 , F_79 ( V_149 ) ) ) ) ;
F_127 ( L_3 ) ;
}
F_130 ( & V_148 ) ;
}
static int F_131 ( struct V_1 * V_2 )
{
int V_157 = 0 ;
struct V_1 * V_110 ;
F_129 (iter, memcg)
V_157 ++ ;
return V_157 ;
}
static unsigned long F_132 ( struct V_1 * V_2 )
{
unsigned long V_136 ;
V_136 = V_2 -> V_55 . V_136 ;
if ( F_114 ( V_2 ) ) {
unsigned long V_158 ;
V_158 = V_2 -> V_138 . V_136 ;
V_136 = F_113 ( V_136 + V_159 , V_158 ) ;
}
return V_136 ;
}
static void F_133 ( struct V_1 * V_2 , T_2 V_160 ,
int V_161 )
{
struct V_1 * V_110 ;
unsigned long V_162 = 0 ;
unsigned long V_163 ;
unsigned int V_164 = 0 ;
struct V_99 * V_165 = NULL ;
if ( F_134 ( V_23 ) || F_135 ( V_23 ) ) {
F_136 ( V_166 ) ;
return;
}
F_137 ( V_167 , V_160 , V_161 , NULL ) ;
V_163 = F_132 ( V_2 ) ? : 1 ;
F_129 (iter, memcg) {
struct V_168 V_169 ;
struct V_99 * V_125 ;
F_138 ( & V_110 -> V_10 , & V_169 ) ;
while ( ( V_125 = F_139 ( & V_169 ) ) ) {
switch ( F_140 ( V_125 , V_163 , NULL ,
false ) ) {
case V_170 :
if ( V_165 )
F_141 ( V_165 ) ;
V_165 = V_125 ;
V_162 = V_171 ;
F_142 ( V_165 ) ;
case V_172 :
continue;
case V_173 :
F_143 ( & V_169 ) ;
F_98 ( V_2 , V_110 ) ;
if ( V_165 )
F_141 ( V_165 ) ;
return;
case V_174 :
break;
} ;
V_164 = F_144 ( V_125 , V_2 , NULL , V_163 ) ;
if ( ! V_164 || V_164 < V_162 )
continue;
if ( V_164 == V_162 &&
F_145 ( V_165 ) )
continue;
if ( V_165 )
F_141 ( V_165 ) ;
V_165 = V_125 ;
V_162 = V_164 ;
F_142 ( V_165 ) ;
}
F_143 ( & V_169 ) ;
}
if ( ! V_165 )
return;
V_164 = V_162 * 1000 / V_163 ;
F_146 ( V_165 , V_160 , V_161 , V_164 , V_163 , V_2 ,
NULL , L_11 ) ;
}
static bool F_147 ( struct V_1 * V_2 ,
int V_30 , bool V_175 )
{
if ( F_76 ( V_2 , V_30 , V_176 ) )
return true ;
if ( V_175 || ! V_159 )
return false ;
if ( F_76 ( V_2 , V_30 , V_177 ) )
return true ;
return false ;
}
static void F_148 ( struct V_1 * V_2 )
{
int V_30 ;
if ( ! F_149 ( & V_2 -> V_98 ) )
return;
if ( F_150 ( & V_2 -> V_178 ) > 1 )
return;
V_2 -> V_179 = V_180 [ V_181 ] ;
F_151 (nid, node_states[N_MEMORY]) {
if ( ! F_147 ( V_2 , V_30 , false ) )
F_152 ( V_30 , V_2 -> V_179 ) ;
}
F_153 ( & V_2 -> V_98 , 0 ) ;
F_153 ( & V_2 -> V_178 , 0 ) ;
}
int F_154 ( struct V_1 * V_2 )
{
int V_182 ;
F_148 ( V_2 ) ;
V_182 = V_2 -> V_183 ;
V_182 = F_155 ( V_182 , V_2 -> V_179 ) ;
if ( V_182 == V_97 )
V_182 = F_156 ( V_2 -> V_179 ) ;
if ( F_86 ( V_182 == V_97 ) )
V_182 = F_157 () ;
V_2 -> V_183 = V_182 ;
return V_182 ;
}
int F_154 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_158 ( struct V_1 * V_184 ,
struct V_29 * V_29 ,
T_2 V_160 ,
unsigned long * V_185 )
{
struct V_1 * V_186 = NULL ;
int V_187 = 0 ;
int V_188 = 0 ;
unsigned long V_57 ;
unsigned long V_189 ;
struct V_106 V_107 = {
. V_29 = V_29 ,
. V_114 = 0 ,
} ;
V_57 = F_50 ( V_184 ) ;
while ( 1 ) {
V_186 = F_92 ( V_184 , V_186 , & V_107 ) ;
if ( ! V_186 ) {
V_188 ++ ;
if ( V_188 >= 2 ) {
if ( ! V_187 )
break;
if ( V_187 >= ( V_57 >> 2 ) ||
( V_188 > V_190 ) )
break;
}
continue;
}
V_187 += F_159 ( V_186 , V_160 , false ,
V_29 , & V_189 ) ;
* V_185 += V_189 ;
if ( ! F_50 ( V_184 ) )
break;
}
F_98 ( V_184 , V_186 ) ;
return V_187 ;
}
static bool F_160 ( struct V_1 * V_2 )
{
struct V_1 * V_110 , * V_191 = NULL ;
F_66 ( & V_192 ) ;
F_129 (iter, memcg) {
if ( V_110 -> V_193 ) {
V_191 = V_110 ;
F_98 ( V_2 , V_110 ) ;
break;
} else
V_110 -> V_193 = true ;
}
if ( V_191 ) {
F_129 (iter, memcg) {
if ( V_110 == V_191 ) {
F_98 ( V_2 , V_110 ) ;
break;
}
V_110 -> V_193 = false ;
}
} else
F_161 ( & V_194 , 0 , 1 , V_195 ) ;
F_67 ( & V_192 ) ;
return ! V_191 ;
}
static void F_162 ( struct V_1 * V_2 )
{
struct V_1 * V_110 ;
F_66 ( & V_192 ) ;
F_163 ( & V_194 , 1 , V_195 ) ;
F_129 (iter, memcg)
V_110 -> V_193 = false ;
F_67 ( & V_192 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
struct V_1 * V_110 ;
F_129 (iter, memcg)
F_88 ( & V_110 -> V_196 ) ;
}
static void F_165 ( struct V_1 * V_2 )
{
struct V_1 * V_110 ;
F_129 (iter, memcg)
F_166 ( & V_110 -> V_196 , - 1 , 0 ) ;
}
static int F_167 ( T_3 * V_145 ,
unsigned V_197 , int V_198 , void * V_199 )
{
struct V_1 * V_200 = (struct V_1 * ) V_199 ;
struct V_1 * V_201 ;
struct V_202 * V_202 ;
V_202 = F_6 ( V_145 , struct V_202 , V_145 ) ;
V_201 = V_202 -> V_2 ;
if ( ! F_105 ( V_200 , V_201 ) &&
! F_105 ( V_201 , V_200 ) )
return 0 ;
return F_168 ( V_145 , V_197 , V_198 , V_199 ) ;
}
static void F_169 ( struct V_1 * V_2 )
{
F_88 ( & V_2 -> V_203 ) ;
F_170 ( & V_204 , V_205 , 0 , V_2 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
if ( V_2 && F_149 ( & V_2 -> V_196 ) )
F_169 ( V_2 ) ;
}
static void F_172 ( struct V_1 * V_2 , T_2 V_206 , int V_161 )
{
if ( ! V_23 -> V_207 . V_208 )
return;
F_15 ( & V_2 -> V_10 ) ;
V_23 -> V_207 . V_2 = V_2 ;
V_23 -> V_207 . V_160 = V_206 ;
V_23 -> V_207 . V_161 = V_161 ;
}
bool F_173 ( bool V_209 )
{
struct V_1 * V_2 = V_23 -> V_207 . V_2 ;
struct V_202 V_210 ;
bool V_211 ;
if ( ! V_2 )
return false ;
if ( ! V_209 )
goto V_212;
V_210 . V_2 = V_2 ;
V_210 . V_145 . V_52 = 0 ;
V_210 . V_145 . V_213 = F_167 ;
V_210 . V_145 . V_214 = V_23 ;
F_174 ( & V_210 . V_145 . V_215 ) ;
F_118 ( & V_204 , & V_210 . V_145 , V_216 ) ;
F_164 ( V_2 ) ;
V_211 = F_160 ( V_2 ) ;
if ( V_211 )
F_175 ( V_2 ) ;
if ( V_211 && ! V_2 -> V_217 ) {
F_165 ( V_2 ) ;
F_120 ( & V_204 , & V_210 . V_145 ) ;
F_133 ( V_2 , V_23 -> V_207 . V_160 ,
V_23 -> V_207 . V_161 ) ;
} else {
F_119 () ;
F_165 ( V_2 ) ;
F_120 ( & V_204 , & V_210 . V_145 ) ;
}
if ( V_211 ) {
F_162 ( V_2 ) ;
F_171 ( V_2 ) ;
}
V_212:
V_23 -> V_207 . V_2 = NULL ;
F_23 ( & V_2 -> V_10 ) ;
return true ;
}
struct V_1 * F_176 ( struct V_34 * V_34 ,
bool * V_211 ,
unsigned long * V_52 )
{
struct V_1 * V_2 ;
F_16 () ;
if ( F_93 () )
return NULL ;
V_218:
V_2 = V_34 -> V_1 ;
if ( F_86 ( ! V_2 ) )
return NULL ;
* V_211 = false ;
if ( F_149 ( & V_2 -> V_219 ) <= 0 )
return V_2 ;
F_48 ( & V_2 -> V_220 , * V_52 ) ;
if ( V_2 != V_34 -> V_1 ) {
F_49 ( & V_2 -> V_220 , * V_52 ) ;
goto V_218;
}
* V_211 = true ;
return V_2 ;
}
void F_177 ( struct V_1 * V_2 , bool * V_211 ,
unsigned long * V_52 )
{
if ( V_2 && * V_211 )
F_49 ( & V_2 -> V_220 , * V_52 ) ;
F_20 () ;
}
void F_178 ( struct V_1 * V_2 ,
enum V_62 V_63 , int V_64 )
{
F_77 ( ! F_179 () ) ;
if ( V_2 )
F_180 ( V_2 -> V_66 -> V_67 [ V_63 ] , V_64 ) ;
}
static bool F_181 ( struct V_1 * V_2 , unsigned int V_54 )
{
struct V_221 * V_222 ;
bool V_127 = false ;
if ( V_54 > V_223 )
return V_127 ;
V_222 = & F_182 ( V_224 ) ;
if ( V_2 == V_222 -> V_225 && V_222 -> V_54 >= V_54 ) {
V_222 -> V_54 -= V_54 ;
V_127 = true ;
}
F_183 ( V_224 ) ;
return V_127 ;
}
static void F_184 ( struct V_221 * V_222 )
{
struct V_1 * V_226 = V_222 -> V_225 ;
if ( V_222 -> V_54 ) {
F_185 ( & V_226 -> V_55 , V_222 -> V_54 ) ;
if ( V_137 )
F_185 ( & V_226 -> V_138 , V_222 -> V_54 ) ;
F_186 ( & V_226 -> V_10 , V_222 -> V_54 ) ;
V_222 -> V_54 = 0 ;
}
V_222 -> V_225 = NULL ;
}
static void F_187 ( struct V_227 * V_228 )
{
struct V_221 * V_222 = F_188 ( & V_224 ) ;
F_184 ( V_222 ) ;
F_189 ( V_229 , & V_222 -> V_52 ) ;
}
static void T_4 F_190 ( void )
{
int V_65 ;
F_191 (cpu) {
struct V_221 * V_222 =
& F_64 ( V_224 , V_65 ) ;
F_192 ( & V_222 -> V_230 , F_187 ) ;
}
}
static void F_193 ( struct V_1 * V_2 , unsigned int V_54 )
{
struct V_221 * V_222 = & F_182 ( V_224 ) ;
if ( V_222 -> V_225 != V_2 ) {
F_184 ( V_222 ) ;
V_222 -> V_225 = V_2 ;
}
V_222 -> V_54 += V_54 ;
F_183 ( V_224 ) ;
}
static void F_194 ( struct V_1 * V_184 )
{
int V_65 , V_231 ;
if ( ! F_195 ( & V_232 ) )
return;
F_62 () ;
V_231 = F_196 () ;
F_63 (cpu) {
struct V_221 * V_222 = & F_64 ( V_224 , V_65 ) ;
struct V_1 * V_2 ;
V_2 = V_222 -> V_225 ;
if ( ! V_2 || ! V_222 -> V_54 )
continue;
if ( ! F_105 ( V_2 , V_184 ) )
continue;
if ( ! F_197 ( V_229 , & V_222 -> V_52 ) ) {
if ( V_65 == V_231 )
F_187 ( & V_222 -> V_230 ) ;
else
F_198 ( V_65 , & V_222 -> V_230 ) ;
}
}
F_199 () ;
F_68 () ;
F_130 ( & V_232 ) ;
}
static void F_200 ( struct V_1 * V_2 , int V_65 )
{
int V_149 ;
F_66 ( & V_2 -> V_68 ) ;
for ( V_149 = 0 ; V_149 < V_152 ; V_149 ++ ) {
long V_233 = F_64 ( V_2 -> V_66 -> V_67 [ V_149 ] , V_65 ) ;
F_64 ( V_2 -> V_66 -> V_67 [ V_149 ] , V_65 ) = 0 ;
V_2 -> V_69 . V_67 [ V_149 ] += V_233 ;
}
for ( V_149 = 0 ; V_149 < V_234 ; V_149 ++ ) {
unsigned long V_233 = F_64 ( V_2 -> V_66 -> V_71 [ V_149 ] , V_65 ) ;
F_64 ( V_2 -> V_66 -> V_71 [ V_149 ] , V_65 ) = 0 ;
V_2 -> V_69 . V_71 [ V_149 ] += V_233 ;
}
F_67 ( & V_2 -> V_68 ) ;
}
static int F_201 ( struct V_235 * V_236 ,
unsigned long V_237 ,
void * V_238 )
{
int V_65 = ( unsigned long ) V_238 ;
struct V_221 * V_222 ;
struct V_1 * V_110 ;
if ( V_237 == V_239 )
return V_240 ;
if ( V_237 != V_241 && V_237 != V_242 )
return V_240 ;
F_202 (iter)
F_200 ( V_110 , V_65 ) ;
V_222 = & F_64 ( V_224 , V_65 ) ;
F_184 ( V_222 ) ;
return V_240 ;
}
static int F_203 ( struct V_1 * V_2 , T_2 V_160 ,
unsigned int V_54 )
{
unsigned int V_243 = F_204 ( V_223 , V_54 ) ;
int V_244 = V_245 ;
struct V_1 * V_246 ;
struct V_247 * V_248 ;
unsigned long V_249 ;
bool V_250 = true ;
bool V_251 = false ;
int V_127 = 0 ;
if ( F_9 ( V_2 ) )
goto V_61;
V_60:
if ( F_181 ( V_2 , V_54 ) )
goto V_61;
if ( ! V_137 ||
! F_205 ( & V_2 -> V_138 , V_243 , & V_248 ) ) {
if ( ! F_205 ( & V_2 -> V_55 , V_243 , & V_248 ) )
goto V_252;
if ( V_137 )
F_185 ( & V_2 -> V_138 , V_243 ) ;
V_246 = F_206 ( V_248 , V_55 ) ;
} else {
V_246 = F_206 ( V_248 , V_138 ) ;
V_250 = false ;
}
if ( V_243 > V_54 ) {
V_243 = V_54 ;
goto V_60;
}
if ( F_86 ( F_207 ( V_166 ) ||
F_134 ( V_23 ) ||
V_23 -> V_52 & V_253 ) )
goto V_254;
if ( F_86 ( F_208 ( V_23 ) ) )
goto V_255;
if ( ! ( V_160 & V_256 ) )
goto V_255;
V_249 = F_209 ( V_246 , V_54 ,
V_160 , V_250 ) ;
if ( F_112 ( V_246 ) >= V_54 )
goto V_60;
if ( ! V_251 ) {
F_194 ( V_246 ) ;
V_251 = true ;
goto V_60;
}
if ( V_160 & V_257 )
goto V_255;
if ( V_249 && V_54 <= ( 1 << V_258 ) )
goto V_60;
if ( F_116 ( V_246 ) )
goto V_60;
if ( V_244 -- )
goto V_60;
if ( V_160 & V_259 )
goto V_254;
if ( F_134 ( V_23 ) )
goto V_254;
F_172 ( V_246 , V_160 , F_210 ( V_54 ) ) ;
V_255:
if ( ! ( V_160 & V_259 ) )
return - V_260 ;
V_254:
return - V_261 ;
V_252:
F_211 ( & V_2 -> V_10 , V_243 ) ;
if ( V_243 > V_54 )
F_193 ( V_2 , V_243 - V_54 ) ;
V_61:
return V_127 ;
}
static void F_212 ( struct V_1 * V_2 , unsigned int V_54 )
{
if ( F_9 ( V_2 ) )
return;
F_185 ( & V_2 -> V_55 , V_54 ) ;
if ( V_137 )
F_185 ( & V_2 -> V_138 , V_54 ) ;
F_186 ( & V_2 -> V_10 , V_54 ) ;
}
static struct V_1 * F_213 ( unsigned short V_14 )
{
if ( ! V_14 )
return NULL ;
return F_11 ( V_14 ) ;
}
struct V_1 * F_214 ( struct V_34 * V_34 )
{
struct V_1 * V_2 ;
unsigned short V_14 ;
T_5 V_262 ;
F_215 ( ! F_216 ( V_34 ) , V_34 ) ;
V_2 = V_34 -> V_1 ;
if ( V_2 ) {
if ( ! F_19 ( & V_2 -> V_10 ) )
V_2 = NULL ;
} else if ( F_217 ( V_34 ) ) {
V_262 . V_64 = F_218 ( V_34 ) ;
V_14 = F_219 ( V_262 ) ;
F_16 () ;
V_2 = F_213 ( V_14 ) ;
if ( V_2 && ! F_19 ( & V_2 -> V_10 ) )
V_2 = NULL ;
F_20 () ;
}
return V_2 ;
}
static void F_220 ( struct V_34 * V_34 , int * V_263 )
{
struct V_29 * V_29 = F_221 ( V_34 ) ;
F_59 ( & V_29 -> V_264 ) ;
if ( F_222 ( V_34 ) ) {
struct V_78 * V_78 ;
V_78 = F_103 ( V_34 , V_29 ) ;
F_223 ( V_34 ) ;
F_224 ( V_34 , V_78 , F_225 ( V_34 ) ) ;
* V_263 = 1 ;
} else
* V_263 = 0 ;
}
static void F_226 ( struct V_34 * V_34 , int V_263 )
{
struct V_29 * V_29 = F_221 ( V_34 ) ;
if ( V_263 ) {
struct V_78 * V_78 ;
V_78 = F_103 ( V_34 , V_29 ) ;
F_215 ( F_222 ( V_34 ) , V_34 ) ;
F_227 ( V_34 ) ;
F_228 ( V_34 , V_78 , F_225 ( V_34 ) ) ;
}
F_60 ( & V_29 -> V_264 ) ;
}
static void F_229 ( struct V_34 * V_34 , struct V_1 * V_2 ,
bool V_265 )
{
int V_263 ;
F_215 ( V_34 -> V_1 , V_34 ) ;
if ( V_265 )
F_220 ( V_34 , & V_263 ) ;
V_34 -> V_1 = V_2 ;
if ( V_265 )
F_226 ( V_34 , V_263 ) ;
}
static struct V_266 * F_230 ( struct V_267 * V_43 )
{
struct V_266 * V_268 ;
F_77 ( V_43 -> V_269 ) ;
V_268 = V_43 -> V_270 ;
return F_231 ( V_268 , F_232 ( V_43 -> V_2 ) ) ;
}
static int F_233 ( struct V_1 * V_2 , T_2 V_271 ,
unsigned long V_54 )
{
struct V_247 * V_248 ;
int V_127 = 0 ;
V_127 = F_205 ( & V_2 -> V_27 , V_54 , & V_248 ) ;
if ( V_127 < 0 )
return V_127 ;
V_127 = F_203 ( V_2 , V_271 , V_54 ) ;
if ( V_127 == - V_261 ) {
F_234 ( & V_2 -> V_55 , V_54 ) ;
if ( V_137 )
F_234 ( & V_2 -> V_138 , V_54 ) ;
F_211 ( & V_2 -> V_10 , V_54 ) ;
V_127 = 0 ;
} else if ( V_127 )
F_185 ( & V_2 -> V_27 , V_54 ) ;
return V_127 ;
}
static void F_235 ( struct V_1 * V_2 ,
unsigned long V_54 )
{
F_185 ( & V_2 -> V_55 , V_54 ) ;
if ( V_137 )
F_185 ( & V_2 -> V_138 , V_54 ) ;
F_185 ( & V_2 -> V_27 , V_54 ) ;
F_186 ( & V_2 -> V_10 , V_54 ) ;
}
int F_232 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_3 : - 1 ;
}
static int F_236 ( void )
{
int V_14 , V_272 ;
int V_273 ;
V_14 = F_237 ( & V_274 ,
0 , V_275 , V_276 ) ;
if ( V_14 < 0 )
return V_14 ;
if ( V_14 < V_277 )
return V_14 ;
V_272 = 2 * ( V_14 + 1 ) ;
if ( V_272 < V_278 )
V_272 = V_278 ;
else if ( V_272 > V_275 )
V_272 = V_275 ;
F_123 ( & V_279 ) ;
V_273 = F_238 ( V_272 ) ;
F_130 ( & V_279 ) ;
if ( V_273 ) {
F_239 ( & V_274 , V_14 ) ;
return V_273 ;
}
return V_14 ;
}
static void F_29 ( int V_14 )
{
F_239 ( & V_274 , V_14 ) ;
}
void F_240 ( int V_157 )
{
V_277 = V_157 ;
}
static void F_241 ( struct V_1 * V_2 ,
struct V_266 * V_270 )
{
static char V_280 [ V_281 + 1 ] ;
struct V_266 * V_268 ;
int V_14 ;
F_242 ( & V_279 ) ;
V_14 = F_232 ( V_2 ) ;
if ( F_231 ( V_270 , V_14 ) )
return;
F_243 ( V_2 -> V_10 . V_124 , V_280 , V_281 + 1 ) ;
V_268 = F_244 ( V_2 , V_270 , V_280 ) ;
if ( ! V_268 )
return;
F_245 ( & V_268 -> V_282 -> V_283 , & V_2 -> V_284 ) ;
F_246 () ;
F_14 ( V_270 -> V_282 -> V_285 [ V_14 ] ) ;
V_270 -> V_282 -> V_285 [ V_14 ] = V_268 ;
}
static void F_247 ( struct V_266 * V_268 )
{
struct V_266 * V_270 ;
struct V_1 * V_2 ;
int V_14 ;
F_242 ( & V_279 ) ;
F_14 ( V_269 ( V_268 ) ) ;
V_270 = V_268 -> V_282 -> V_270 ;
V_2 = V_268 -> V_282 -> V_2 ;
V_14 = F_232 ( V_2 ) ;
F_14 ( V_270 -> V_282 -> V_285 [ V_14 ] != V_268 ) ;
V_270 -> V_282 -> V_285 [ V_14 ] = NULL ;
F_248 ( & V_268 -> V_282 -> V_283 ) ;
F_249 ( V_268 ) ;
}
int F_250 ( struct V_266 * V_9 )
{
struct V_266 * V_286 ;
int V_149 , V_191 = 0 ;
F_123 ( & V_279 ) ;
F_251 (i) {
V_286 = F_231 ( V_9 , V_149 ) ;
if ( ! V_286 )
continue;
F_247 ( V_286 ) ;
if ( F_231 ( V_9 , V_149 ) )
V_191 ++ ;
}
F_130 ( & V_279 ) ;
return V_191 ;
}
static void F_252 ( struct V_1 * V_2 )
{
struct V_266 * V_268 ;
struct V_267 * V_287 , * V_288 ;
if ( ! F_1 ( V_2 ) )
return;
F_123 ( & V_279 ) ;
F_253 (params, tmp, &memcg->memcg_slab_caches, list) {
V_268 = F_230 ( V_287 ) ;
F_247 ( V_268 ) ;
}
F_130 ( & V_279 ) ;
}
static void F_254 ( struct V_227 * V_289 )
{
struct V_290 * V_291 =
F_6 ( V_289 , struct V_290 , V_230 ) ;
struct V_1 * V_2 = V_291 -> V_2 ;
struct V_266 * V_268 = V_291 -> V_268 ;
F_123 ( & V_279 ) ;
F_241 ( V_2 , V_268 ) ;
F_130 ( & V_279 ) ;
F_23 ( & V_2 -> V_10 ) ;
F_255 ( V_291 ) ;
}
static void F_256 ( struct V_1 * V_2 ,
struct V_266 * V_268 )
{
struct V_290 * V_291 ;
V_291 = F_257 ( sizeof( * V_291 ) , V_292 ) ;
if ( ! V_291 )
return;
F_15 ( & V_2 -> V_10 ) ;
V_291 -> V_2 = V_2 ;
V_291 -> V_268 = V_268 ;
F_192 ( & V_291 -> V_230 , F_254 ) ;
F_258 ( & V_291 -> V_230 ) ;
}
static void F_259 ( struct V_1 * V_2 ,
struct V_266 * V_268 )
{
V_23 -> V_293 = 1 ;
F_256 ( V_2 , V_268 ) ;
V_23 -> V_293 = 0 ;
}
int F_260 ( struct V_266 * V_268 , T_2 V_271 , int V_161 )
{
unsigned int V_54 = 1 << V_161 ;
return F_233 ( V_268 -> V_282 -> V_2 , V_271 , V_54 ) ;
}
void F_261 ( struct V_266 * V_268 , int V_161 )
{
unsigned int V_54 = 1 << V_161 ;
F_235 ( V_268 -> V_282 -> V_2 , V_54 ) ;
}
struct V_266 * F_262 ( struct V_266 * V_268 )
{
struct V_1 * V_2 ;
struct V_266 * V_294 ;
F_77 ( ! V_268 -> V_282 ) ;
F_77 ( ! V_268 -> V_282 -> V_269 ) ;
if ( V_23 -> V_293 )
return V_268 ;
V_2 = F_90 ( V_23 -> V_102 ) ;
if ( ! F_1 ( V_2 ) )
goto V_113;
V_294 = F_231 ( V_268 , F_232 ( V_2 ) ) ;
if ( F_263 ( V_294 ) )
return V_294 ;
F_259 ( V_2 , V_268 ) ;
V_113:
F_23 ( & V_2 -> V_10 ) ;
return V_268 ;
}
void F_264 ( struct V_266 * V_268 )
{
if ( ! V_269 ( V_268 ) )
F_23 ( & V_268 -> V_282 -> V_2 -> V_10 ) ;
}
bool
F_265 ( T_2 V_271 , struct V_1 * * V_295 , int V_161 )
{
struct V_1 * V_2 ;
int V_127 ;
* V_295 = NULL ;
V_2 = F_90 ( V_23 -> V_102 ) ;
if ( ! F_1 ( V_2 ) ) {
F_23 ( & V_2 -> V_10 ) ;
return true ;
}
V_127 = F_233 ( V_2 , V_271 , 1 << V_161 ) ;
if ( ! V_127 )
* V_295 = V_2 ;
F_23 ( & V_2 -> V_10 ) ;
return ( V_127 == 0 ) ;
}
void F_266 ( struct V_34 * V_34 , struct V_1 * V_2 ,
int V_161 )
{
F_77 ( F_9 ( V_2 ) ) ;
if ( ! V_34 ) {
F_235 ( V_2 , 1 << V_161 ) ;
return;
}
V_34 -> V_1 = V_2 ;
}
void F_267 ( struct V_34 * V_34 , int V_161 )
{
struct V_1 * V_2 = V_34 -> V_1 ;
if ( ! V_2 )
return;
F_215 ( F_9 ( V_2 ) , V_34 ) ;
F_235 ( V_2 , 1 << V_161 ) ;
V_34 -> V_1 = NULL ;
}
void F_268 ( struct V_34 * V_296 )
{
int V_149 ;
if ( F_93 () )
return;
for ( V_149 = 1 ; V_149 < V_297 ; V_149 ++ )
V_296 [ V_149 ] . V_1 = V_296 -> V_1 ;
F_269 ( V_296 -> V_1 -> V_66 -> V_67 [ V_74 ] ,
V_297 ) ;
}
static int F_270 ( struct V_34 * V_34 ,
unsigned int V_54 ,
struct V_1 * V_141 ,
struct V_1 * V_142 )
{
unsigned long V_52 ;
int V_127 ;
F_77 ( V_141 == V_142 ) ;
F_215 ( F_222 ( V_34 ) , V_34 ) ;
V_127 = - V_298 ;
if ( V_54 > 1 && ! F_73 ( V_34 ) )
goto V_113;
if ( ! F_271 ( V_34 ) )
goto V_113;
V_127 = - V_299 ;
if ( V_34 -> V_1 != V_141 )
goto V_116;
F_48 ( & V_141 -> V_220 , V_52 ) ;
if ( ! F_71 ( V_34 ) && F_272 ( V_34 ) ) {
F_269 ( V_141 -> V_66 -> V_67 [ V_300 ] ,
V_54 ) ;
F_72 ( V_142 -> V_66 -> V_67 [ V_300 ] ,
V_54 ) ;
}
if ( F_273 ( V_34 ) ) {
F_269 ( V_141 -> V_66 -> V_67 [ V_301 ] ,
V_54 ) ;
F_72 ( V_142 -> V_66 -> V_67 [ V_301 ] ,
V_54 ) ;
}
V_34 -> V_1 = V_142 ;
F_49 ( & V_141 -> V_220 , V_52 ) ;
V_127 = 0 ;
F_274 () ;
F_70 ( V_142 , V_34 , V_54 ) ;
F_85 ( V_142 , V_34 ) ;
F_70 ( V_141 , V_34 , - V_54 ) ;
F_85 ( V_141 , V_34 ) ;
F_275 () ;
V_116:
F_276 ( V_34 ) ;
V_113:
return V_127 ;
}
static void F_277 ( struct V_1 * V_2 ,
bool V_302 )
{
int V_64 = ( V_302 ) ? 1 : - 1 ;
F_180 ( V_2 -> V_66 -> V_67 [ V_153 ] , V_64 ) ;
}
static int F_278 ( T_5 V_303 ,
struct V_1 * V_141 , struct V_1 * V_142 )
{
unsigned short V_304 , V_305 ;
V_304 = F_10 ( V_141 ) ;
V_305 = F_10 ( V_142 ) ;
if ( F_279 ( V_303 , V_304 , V_305 ) == V_304 ) {
F_277 ( V_141 , false ) ;
F_277 ( V_142 , true ) ;
return 0 ;
}
return - V_299 ;
}
static inline int F_278 ( T_5 V_303 ,
struct V_1 * V_141 , struct V_1 * V_142 )
{
return - V_299 ;
}
static int F_280 ( struct V_1 * V_2 ,
unsigned long V_136 )
{
unsigned long V_306 ;
unsigned long V_307 ;
bool V_308 = false ;
int V_309 ;
int V_127 ;
V_309 = V_245 *
F_131 ( V_2 ) ;
V_307 = F_30 ( & V_2 -> V_55 ) ;
do {
if ( F_281 ( V_23 ) ) {
V_127 = - V_261 ;
break;
}
F_123 ( & V_310 ) ;
if ( V_136 > V_2 -> V_138 . V_136 ) {
F_130 ( & V_310 ) ;
V_127 = - V_299 ;
break;
}
if ( V_136 > V_2 -> V_55 . V_136 )
V_308 = true ;
V_127 = F_282 ( & V_2 -> V_55 , V_136 ) ;
F_130 ( & V_310 ) ;
if ( ! V_127 )
break;
F_209 ( V_2 , 1 , V_276 , true ) ;
V_306 = F_30 ( & V_2 -> V_55 ) ;
if ( V_306 >= V_307 )
V_309 -- ;
else
V_307 = V_306 ;
} while ( V_309 );
if ( ! V_127 && V_308 )
F_171 ( V_2 ) ;
return V_127 ;
}
static int F_283 ( struct V_1 * V_2 ,
unsigned long V_136 )
{
unsigned long V_306 ;
unsigned long V_307 ;
bool V_308 = false ;
int V_309 ;
int V_127 ;
V_309 = V_245 *
F_131 ( V_2 ) ;
V_307 = F_30 ( & V_2 -> V_138 ) ;
do {
if ( F_281 ( V_23 ) ) {
V_127 = - V_261 ;
break;
}
F_123 ( & V_310 ) ;
if ( V_136 < V_2 -> V_55 . V_136 ) {
F_130 ( & V_310 ) ;
V_127 = - V_299 ;
break;
}
if ( V_136 > V_2 -> V_138 . V_136 )
V_308 = true ;
V_127 = F_282 ( & V_2 -> V_138 , V_136 ) ;
F_130 ( & V_310 ) ;
if ( ! V_127 )
break;
F_209 ( V_2 , 1 , V_276 , false ) ;
V_306 = F_30 ( & V_2 -> V_138 ) ;
if ( V_306 >= V_307 )
V_309 -- ;
else
V_307 = V_306 ;
} while ( V_309 );
if ( ! V_127 && V_308 )
F_171 ( V_2 ) ;
return V_127 ;
}
unsigned long F_284 ( struct V_29 * V_29 , int V_161 ,
T_2 V_160 ,
unsigned long * V_185 )
{
unsigned long V_249 = 0 ;
struct V_28 * V_39 , * V_311 = NULL ;
unsigned long V_312 ;
int V_188 = 0 ;
struct V_35 * V_40 ;
unsigned long V_57 ;
unsigned long V_189 ;
if ( V_161 > 0 )
return 0 ;
V_40 = F_39 ( F_33 ( V_29 ) , F_34 ( V_29 ) ) ;
do {
if ( V_311 )
V_39 = V_311 ;
else
V_39 = F_58 ( V_40 ) ;
if ( ! V_39 )
break;
V_189 = 0 ;
V_312 = F_158 ( V_39 -> V_2 , V_29 ,
V_160 , & V_189 ) ;
V_249 += V_312 ;
* V_185 += V_189 ;
F_59 ( & V_40 -> V_53 ) ;
F_45 ( V_39 , V_40 ) ;
V_311 = NULL ;
if ( ! V_312 )
V_311 = F_56 ( V_40 ) ;
V_57 = F_50 ( V_39 -> V_2 ) ;
F_41 ( V_39 , V_40 , V_57 ) ;
F_60 ( & V_40 -> V_53 ) ;
F_23 ( & V_39 -> V_2 -> V_10 ) ;
V_188 ++ ;
if ( ! V_249 &&
( V_311 == NULL ||
V_188 > V_313 ) )
break;
} while ( ! V_249 );
if ( V_311 )
F_23 ( & V_311 -> V_2 -> V_10 ) ;
return V_249 ;
}
static inline bool F_285 ( struct V_1 * V_2 )
{
bool V_127 ;
F_242 ( & V_314 ) ;
F_16 () ;
V_127 = F_286 ( NULL , & V_2 -> V_10 ) ;
F_20 () ;
return V_127 ;
}
static int F_287 ( struct V_1 * V_2 )
{
int V_244 = V_245 ;
F_288 () ;
while ( V_244 && F_30 ( & V_2 -> V_55 ) ) {
int V_315 ;
if ( F_281 ( V_23 ) )
return - V_261 ;
V_315 = F_209 ( V_2 , 1 ,
V_276 , true ) ;
if ( ! V_315 ) {
V_244 -- ;
F_289 ( V_316 , V_317 / 10 ) ;
}
}
return 0 ;
}
static T_6 F_290 ( struct V_318 * V_319 ,
char * V_320 , T_7 V_321 ,
T_8 V_322 )
{
struct V_1 * V_2 = F_5 ( F_291 ( V_319 ) ) ;
if ( F_9 ( V_2 ) )
return - V_299 ;
return F_287 ( V_2 ) ? : V_321 ;
}
static V_150 F_292 ( struct V_8 * V_10 ,
struct V_323 * V_324 )
{
return F_5 ( V_10 ) -> V_112 ;
}
static int F_293 ( struct V_8 * V_10 ,
struct V_323 * V_324 , V_150 V_64 )
{
int V_325 = 0 ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_1 * V_326 = F_5 ( V_2 -> V_10 . V_45 ) ;
F_123 ( & V_314 ) ;
if ( V_2 -> V_112 == V_64 )
goto V_113;
if ( ( ! V_326 || ! V_326 -> V_112 ) &&
( V_64 == 1 || V_64 == 0 ) ) {
if ( ! F_285 ( V_2 ) )
V_2 -> V_112 = V_64 ;
else
V_325 = - V_298 ;
} else
V_325 = - V_299 ;
V_113:
F_130 ( & V_314 ) ;
return V_325 ;
}
static unsigned long F_294 ( struct V_1 * V_2 ,
enum V_62 V_63 )
{
struct V_1 * V_110 ;
long V_64 = 0 ;
F_129 (iter, memcg)
V_64 += F_61 ( V_110 , V_63 ) ;
if ( V_64 < 0 )
V_64 = 0 ;
return V_64 ;
}
static inline V_150 F_295 ( struct V_1 * V_2 , bool V_327 )
{
V_150 V_64 ;
if ( F_9 ( V_2 ) ) {
V_64 = F_294 ( V_2 , V_73 ) ;
V_64 += F_294 ( V_2 , V_72 ) ;
if ( V_327 )
V_64 += F_294 ( V_2 , V_153 ) ;
} else {
if ( ! V_327 )
V_64 = F_30 ( & V_2 -> V_55 ) ;
else
V_64 = F_30 ( & V_2 -> V_138 ) ;
}
return V_64 << V_134 ;
}
static V_150 F_296 ( struct V_8 * V_10 ,
struct V_323 * V_324 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_247 * V_248 ;
switch ( F_297 ( V_324 -> V_214 ) ) {
case V_328 :
V_248 = & V_2 -> V_55 ;
break;
case V_329 :
V_248 = & V_2 -> V_138 ;
break;
case V_330 :
V_248 = & V_2 -> V_27 ;
break;
default:
F_101 () ;
}
switch ( F_298 ( V_324 -> V_214 ) ) {
case V_331 :
if ( V_248 == & V_2 -> V_55 )
return F_295 ( V_2 , false ) ;
if ( V_248 == & V_2 -> V_138 )
return F_295 ( V_2 , true ) ;
return ( V_150 ) F_30 ( V_248 ) * V_332 ;
case V_333 :
return ( V_150 ) V_248 -> V_136 * V_332 ;
case V_334 :
return ( V_150 ) V_248 -> V_335 * V_332 ;
case V_336 :
return V_248 -> V_151 ;
case V_337 :
return ( V_150 ) V_2 -> V_56 * V_332 ;
default:
F_101 () ;
}
}
static int F_299 ( struct V_1 * V_2 ,
unsigned long V_54 )
{
int V_273 = 0 ;
int V_338 ;
if ( F_1 ( V_2 ) )
return 0 ;
F_123 ( & V_314 ) ;
if ( F_300 ( V_2 -> V_10 . V_124 ) ||
( V_2 -> V_112 && F_285 ( V_2 ) ) )
V_273 = - V_298 ;
F_130 ( & V_314 ) ;
if ( V_273 )
goto V_113;
V_338 = F_236 () ;
if ( V_338 < 0 ) {
V_273 = V_338 ;
goto V_113;
}
V_273 = F_282 ( & V_2 -> V_27 , V_54 ) ;
F_77 ( V_273 ) ;
F_301 ( & V_26 ) ;
V_2 -> V_3 = V_338 ;
V_113:
return V_273 ;
}
static int F_302 ( struct V_1 * V_2 ,
unsigned long V_136 )
{
int V_127 ;
F_123 ( & V_310 ) ;
if ( ! F_1 ( V_2 ) )
V_127 = F_299 ( V_2 , V_136 ) ;
else
V_127 = F_282 ( & V_2 -> V_27 , V_136 ) ;
F_130 ( & V_310 ) ;
return V_127 ;
}
static int F_303 ( struct V_1 * V_2 )
{
int V_127 = 0 ;
struct V_1 * V_45 = F_53 ( V_2 ) ;
if ( ! V_45 )
return 0 ;
F_123 ( & V_310 ) ;
if ( F_1 ( V_45 ) )
V_127 = F_299 ( V_2 , V_339 ) ;
F_130 ( & V_310 ) ;
return V_127 ;
}
static int F_302 ( struct V_1 * V_2 ,
unsigned long V_136 )
{
return - V_299 ;
}
static T_6 F_304 ( struct V_318 * V_319 ,
char * V_320 , T_7 V_321 , T_8 V_322 )
{
struct V_1 * V_2 = F_5 ( F_291 ( V_319 ) ) ;
unsigned long V_54 ;
int V_127 ;
V_320 = F_305 ( V_320 ) ;
V_127 = F_306 ( V_320 , & V_54 ) ;
if ( V_127 )
return V_127 ;
switch ( F_298 ( F_307 ( V_319 ) -> V_214 ) ) {
case V_333 :
if ( F_9 ( V_2 ) ) {
V_127 = - V_299 ;
break;
}
switch ( F_297 ( F_307 ( V_319 ) -> V_214 ) ) {
case V_328 :
V_127 = F_280 ( V_2 , V_54 ) ;
break;
case V_329 :
V_127 = F_283 ( V_2 , V_54 ) ;
break;
case V_330 :
V_127 = F_302 ( V_2 , V_54 ) ;
break;
}
break;
case V_337 :
V_2 -> V_56 = V_54 ;
V_127 = 0 ;
break;
}
return V_127 ? : V_321 ;
}
static T_6 F_308 ( struct V_318 * V_319 , char * V_320 ,
T_7 V_321 , T_8 V_322 )
{
struct V_1 * V_2 = F_5 ( F_291 ( V_319 ) ) ;
struct V_247 * V_248 ;
switch ( F_297 ( F_307 ( V_319 ) -> V_214 ) ) {
case V_328 :
V_248 = & V_2 -> V_55 ;
break;
case V_329 :
V_248 = & V_2 -> V_138 ;
break;
case V_330 :
V_248 = & V_2 -> V_27 ;
break;
default:
F_101 () ;
}
switch ( F_298 ( F_307 ( V_319 ) -> V_214 ) ) {
case V_334 :
F_309 ( V_248 ) ;
break;
case V_336 :
V_248 -> V_151 = 0 ;
break;
default:
F_101 () ;
}
return V_321 ;
}
static V_150 F_310 ( struct V_8 * V_10 ,
struct V_323 * V_324 )
{
return F_5 ( V_10 ) -> V_340 ;
}
static int F_311 ( struct V_8 * V_10 ,
struct V_323 * V_324 , V_150 V_64 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
if ( V_64 >= ( 1 << V_341 ) )
return - V_299 ;
V_2 -> V_340 = V_64 ;
return 0 ;
}
static int F_311 ( struct V_8 * V_10 ,
struct V_323 * V_324 , V_150 V_64 )
{
return - V_342 ;
}
static int F_312 ( struct V_343 * V_344 , void * V_345 )
{
struct V_346 {
const char * V_347 ;
unsigned int V_82 ;
};
static const struct V_346 V_348 [] = {
{ L_12 , V_349 } ,
{ L_13 , V_176 } ,
{ L_14 , V_177 } ,
{ L_15 , F_79 (LRU_UNEVICTABLE) } ,
} ;
const struct V_346 * V_66 ;
int V_30 ;
unsigned long V_83 ;
struct V_1 * V_2 = F_5 ( F_313 ( V_344 ) ) ;
for ( V_66 = V_348 ; V_66 < V_348 + F_314 ( V_348 ) ; V_66 ++ ) {
V_83 = F_80 ( V_2 , V_66 -> V_82 ) ;
F_315 ( V_344 , L_16 , V_66 -> V_347 , V_83 ) ;
F_81 (nid, N_MEMORY) {
V_83 = F_76 ( V_2 , V_30 ,
V_66 -> V_82 ) ;
F_315 ( V_344 , L_17 , V_30 , V_83 ) ;
}
F_316 ( V_344 , '\n' ) ;
}
for ( V_66 = V_348 ; V_66 < V_348 + F_314 ( V_348 ) ; V_66 ++ ) {
struct V_1 * V_110 ;
V_83 = 0 ;
F_129 (iter, memcg)
V_83 += F_80 ( V_110 , V_66 -> V_82 ) ;
F_315 ( V_344 , L_18 , V_66 -> V_347 , V_83 ) ;
F_81 (nid, N_MEMORY) {
V_83 = 0 ;
F_129 (iter, memcg)
V_83 += F_76 (
V_110 , V_30 , V_66 -> V_82 ) ;
F_315 ( V_344 , L_17 , V_30 , V_83 ) ;
}
F_316 ( V_344 , '\n' ) ;
}
return 0 ;
}
static int F_317 ( struct V_343 * V_344 , void * V_345 )
{
struct V_1 * V_2 = F_5 ( F_313 ( V_344 ) ) ;
unsigned long V_55 , V_138 ;
struct V_1 * V_350 ;
unsigned int V_149 ;
F_318 ( F_314 ( V_156 ) != V_155 ) ;
for ( V_149 = 0 ; V_149 < V_152 ; V_149 ++ ) {
if ( V_149 == V_153 && ! V_137 )
continue;
F_315 ( V_344 , L_19 , V_154 [ V_149 ] ,
F_61 ( V_2 , V_149 ) * V_332 ) ;
}
for ( V_149 = 0 ; V_149 < V_234 ; V_149 ++ )
F_315 ( V_344 , L_20 , V_351 [ V_149 ] ,
F_69 ( V_2 , V_149 ) ) ;
for ( V_149 = 0 ; V_149 < V_155 ; V_149 ++ )
F_315 ( V_344 , L_20 , V_156 [ V_149 ] ,
F_80 ( V_2 , F_79 ( V_149 ) ) * V_332 ) ;
V_55 = V_138 = V_339 ;
for ( V_350 = V_2 ; V_350 ; V_350 = F_53 ( V_350 ) ) {
V_55 = F_113 ( V_55 , V_350 -> V_55 . V_136 ) ;
V_138 = F_113 ( V_138 , V_350 -> V_138 . V_136 ) ;
}
F_315 ( V_344 , L_21 ,
( V_150 ) V_55 * V_332 ) ;
if ( V_137 )
F_315 ( V_344 , L_22 ,
( V_150 ) V_138 * V_332 ) ;
for ( V_149 = 0 ; V_149 < V_152 ; V_149 ++ ) {
long long V_64 = 0 ;
if ( V_149 == V_153 && ! V_137 )
continue;
F_129 (mi, memcg)
V_64 += F_61 ( V_350 , V_149 ) * V_332 ;
F_315 ( V_344 , L_23 , V_154 [ V_149 ] , V_64 ) ;
}
for ( V_149 = 0 ; V_149 < V_234 ; V_149 ++ ) {
unsigned long long V_64 = 0 ;
F_129 (mi, memcg)
V_64 += F_69 ( V_350 , V_149 ) ;
F_315 ( V_344 , L_24 ,
V_351 [ V_149 ] , V_64 ) ;
}
for ( V_149 = 0 ; V_149 < V_155 ; V_149 ++ ) {
unsigned long long V_64 = 0 ;
F_129 (mi, memcg)
V_64 += F_80 ( V_350 , F_79 ( V_149 ) ) * V_332 ;
F_315 ( V_344 , L_24 , V_156 [ V_149 ] , V_64 ) ;
}
#ifdef F_319
{
int V_30 , V_31 ;
struct V_28 * V_39 ;
struct V_352 * V_353 ;
unsigned long V_354 [ 2 ] = { 0 , 0 } ;
unsigned long V_355 [ 2 ] = { 0 , 0 } ;
F_320 (nid)
for ( V_31 = 0 ; V_31 < V_58 ; V_31 ++ ) {
V_39 = & V_2 -> V_32 [ V_30 ] -> V_33 [ V_31 ] ;
V_353 = & V_39 -> V_78 . V_356 ;
V_354 [ 0 ] += V_353 -> V_354 [ 0 ] ;
V_354 [ 1 ] += V_353 -> V_354 [ 1 ] ;
V_355 [ 0 ] += V_353 -> V_355 [ 0 ] ;
V_355 [ 1 ] += V_353 -> V_355 [ 1 ] ;
}
F_315 ( V_344 , L_25 , V_354 [ 0 ] ) ;
F_315 ( V_344 , L_26 , V_354 [ 1 ] ) ;
F_315 ( V_344 , L_27 , V_355 [ 0 ] ) ;
F_315 ( V_344 , L_28 , V_355 [ 1 ] ) ;
}
#endif
return 0 ;
}
static V_150 F_321 ( struct V_8 * V_10 ,
struct V_323 * V_324 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
return F_114 ( V_2 ) ;
}
static int F_322 ( struct V_8 * V_10 ,
struct V_323 * V_324 , V_150 V_64 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
if ( V_64 > 100 )
return - V_299 ;
if ( V_10 -> V_45 )
V_2 -> V_140 = V_64 ;
else
V_139 = V_64 ;
return 0 ;
}
static void F_323 ( struct V_1 * V_2 , bool V_327 )
{
struct V_357 * V_358 ;
unsigned long V_359 ;
int V_149 ;
F_16 () ;
if ( ! V_327 )
V_358 = F_91 ( V_2 -> V_360 . V_361 ) ;
else
V_358 = F_91 ( V_2 -> V_362 . V_361 ) ;
if ( ! V_358 )
goto V_143;
V_359 = F_295 ( V_2 , V_327 ) ;
V_149 = V_358 -> V_363 ;
for (; V_149 >= 0 && F_86 ( V_358 -> V_364 [ V_149 ] . V_365 > V_359 ) ; V_149 -- )
F_324 ( V_358 -> V_364 [ V_149 ] . V_366 , 1 ) ;
V_149 ++ ;
for (; V_149 < V_358 -> V_272 && F_86 ( V_358 -> V_364 [ V_149 ] . V_365 <= V_359 ) ; V_149 ++ )
F_324 ( V_358 -> V_364 [ V_149 ] . V_366 , 1 ) ;
V_358 -> V_363 = V_149 - 1 ;
V_143:
F_20 () ;
}
static void F_87 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_323 ( V_2 , false ) ;
if ( V_137 )
F_323 ( V_2 , true ) ;
V_2 = F_53 ( V_2 ) ;
}
}
static int F_325 ( const void * V_367 , const void * V_368 )
{
const struct F_87 * V_369 = V_367 ;
const struct F_87 * V_370 = V_368 ;
if ( V_369 -> V_365 > V_370 -> V_365 )
return 1 ;
if ( V_369 -> V_365 < V_370 -> V_365 )
return - 1 ;
return 0 ;
}
static int F_326 ( struct V_1 * V_2 )
{
struct V_371 * V_372 ;
F_66 ( & V_192 ) ;
F_327 (ev, &memcg->oom_notify, list)
F_324 ( V_372 -> V_366 , 1 ) ;
F_67 ( & V_192 ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 )
{
struct V_1 * V_110 ;
F_129 (iter, memcg)
F_326 ( V_110 ) ;
}
static int F_328 ( struct V_1 * V_2 ,
struct V_373 * V_366 , const char * args , enum V_374 type )
{
struct V_375 * V_360 ;
struct V_357 * V_376 ;
unsigned long V_365 ;
unsigned long V_359 ;
int V_149 , V_272 , V_127 ;
V_127 = F_306 ( args , & V_365 ) ;
if ( V_127 )
return V_127 ;
F_123 ( & V_2 -> V_377 ) ;
if ( type == V_328 ) {
V_360 = & V_2 -> V_360 ;
V_359 = F_295 ( V_2 , false ) ;
} else if ( type == V_329 ) {
V_360 = & V_2 -> V_362 ;
V_359 = F_295 ( V_2 , true ) ;
} else
F_101 () ;
if ( V_360 -> V_361 )
F_323 ( V_2 , type == V_329 ) ;
V_272 = V_360 -> V_361 ? V_360 -> V_361 -> V_272 + 1 : 1 ;
V_376 = F_257 ( sizeof( * V_376 ) + V_272 * sizeof( struct F_87 ) ,
V_276 ) ;
if ( ! V_376 ) {
V_127 = - V_260 ;
goto V_143;
}
V_376 -> V_272 = V_272 ;
if ( V_360 -> V_361 ) {
memcpy ( V_376 -> V_364 , V_360 -> V_361 -> V_364 , ( V_272 - 1 ) *
sizeof( struct F_87 ) ) ;
}
V_376 -> V_364 [ V_272 - 1 ] . V_366 = V_366 ;
V_376 -> V_364 [ V_272 - 1 ] . V_365 = V_365 ;
F_329 ( V_376 -> V_364 , V_272 , sizeof( struct F_87 ) ,
F_325 , NULL ) ;
V_376 -> V_363 = - 1 ;
for ( V_149 = 0 ; V_149 < V_272 ; V_149 ++ ) {
if ( V_376 -> V_364 [ V_149 ] . V_365 <= V_359 ) {
++ V_376 -> V_363 ;
} else
break;
}
F_255 ( V_360 -> V_378 ) ;
V_360 -> V_378 = V_360 -> V_361 ;
F_330 ( V_360 -> V_361 , V_376 ) ;
F_331 () ;
V_143:
F_130 ( & V_2 -> V_377 ) ;
return V_127 ;
}
static int F_332 ( struct V_1 * V_2 ,
struct V_373 * V_366 , const char * args )
{
return F_328 ( V_2 , V_366 , args , V_328 ) ;
}
static int F_333 ( struct V_1 * V_2 ,
struct V_373 * V_366 , const char * args )
{
return F_328 ( V_2 , V_366 , args , V_329 ) ;
}
static void F_334 ( struct V_1 * V_2 ,
struct V_373 * V_366 , enum V_374 type )
{
struct V_375 * V_360 ;
struct V_357 * V_376 ;
unsigned long V_359 ;
int V_149 , V_379 , V_272 ;
F_123 ( & V_2 -> V_377 ) ;
if ( type == V_328 ) {
V_360 = & V_2 -> V_360 ;
V_359 = F_295 ( V_2 , false ) ;
} else if ( type == V_329 ) {
V_360 = & V_2 -> V_362 ;
V_359 = F_295 ( V_2 , true ) ;
} else
F_101 () ;
if ( ! V_360 -> V_361 )
goto V_143;
F_323 ( V_2 , type == V_329 ) ;
V_272 = 0 ;
for ( V_149 = 0 ; V_149 < V_360 -> V_361 -> V_272 ; V_149 ++ ) {
if ( V_360 -> V_361 -> V_364 [ V_149 ] . V_366 != V_366 )
V_272 ++ ;
}
V_376 = V_360 -> V_378 ;
if ( ! V_272 ) {
F_255 ( V_376 ) ;
V_376 = NULL ;
goto V_380;
}
V_376 -> V_272 = V_272 ;
V_376 -> V_363 = - 1 ;
for ( V_149 = 0 , V_379 = 0 ; V_149 < V_360 -> V_361 -> V_272 ; V_149 ++ ) {
if ( V_360 -> V_361 -> V_364 [ V_149 ] . V_366 == V_366 )
continue;
V_376 -> V_364 [ V_379 ] = V_360 -> V_361 -> V_364 [ V_149 ] ;
if ( V_376 -> V_364 [ V_379 ] . V_365 <= V_359 ) {
++ V_376 -> V_363 ;
}
V_379 ++ ;
}
V_380:
V_360 -> V_378 = V_360 -> V_361 ;
if ( ! V_376 ) {
F_255 ( V_360 -> V_378 ) ;
V_360 -> V_378 = NULL ;
}
F_330 ( V_360 -> V_361 , V_376 ) ;
F_331 () ;
V_143:
F_130 ( & V_2 -> V_377 ) ;
}
static void F_335 ( struct V_1 * V_2 ,
struct V_373 * V_366 )
{
return F_334 ( V_2 , V_366 , V_328 ) ;
}
static void F_336 ( struct V_1 * V_2 ,
struct V_373 * V_366 )
{
return F_334 ( V_2 , V_366 , V_329 ) ;
}
static int F_337 ( struct V_1 * V_2 ,
struct V_373 * V_366 , const char * args )
{
struct V_371 * V_381 ;
V_381 = F_257 ( sizeof( * V_381 ) , V_276 ) ;
if ( ! V_381 )
return - V_260 ;
F_66 ( & V_192 ) ;
V_381 -> V_366 = V_366 ;
F_245 ( & V_381 -> V_283 , & V_2 -> V_382 ) ;
if ( F_149 ( & V_2 -> V_196 ) )
F_324 ( V_366 , 1 ) ;
F_67 ( & V_192 ) ;
return 0 ;
}
static void F_338 ( struct V_1 * V_2 ,
struct V_373 * V_366 )
{
struct V_371 * V_372 , * V_288 ;
F_66 ( & V_192 ) ;
F_253 (ev, tmp, &memcg->oom_notify, list) {
if ( V_372 -> V_366 == V_366 ) {
F_248 ( & V_372 -> V_283 ) ;
F_255 ( V_372 ) ;
}
}
F_67 ( & V_192 ) ;
}
static int F_339 ( struct V_343 * V_383 , void * V_345 )
{
struct V_1 * V_2 = F_5 ( F_313 ( V_383 ) ) ;
F_315 ( V_383 , L_29 , V_2 -> V_217 ) ;
F_315 ( V_383 , L_30 , ( bool ) F_149 ( & V_2 -> V_196 ) ) ;
return 0 ;
}
static int F_340 ( struct V_8 * V_10 ,
struct V_323 * V_324 , V_150 V_64 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
if ( ! V_10 -> V_45 || ! ( ( V_64 == 0 ) || ( V_64 == 1 ) ) )
return - V_299 ;
V_2 -> V_217 = V_64 ;
if ( ! V_64 )
F_171 ( V_2 ) ;
return 0 ;
}
static int F_341 ( struct V_1 * V_2 , struct V_384 * V_385 )
{
int V_127 ;
V_127 = F_303 ( V_2 ) ;
if ( V_127 )
return V_127 ;
return F_342 ( V_2 , V_385 ) ;
}
static void F_343 ( struct V_1 * V_2 )
{
F_252 ( V_2 ) ;
F_344 ( V_2 ) ;
}
static int F_341 ( struct V_1 * V_2 , struct V_384 * V_385 )
{
return 0 ;
}
static void F_343 ( struct V_1 * V_2 )
{
}
static void F_345 ( struct V_227 * V_230 )
{
struct V_386 * V_381 =
F_6 ( V_230 , struct V_386 , remove ) ;
struct V_1 * V_2 = V_381 -> V_2 ;
F_346 ( V_381 -> V_387 , & V_381 -> V_145 ) ;
V_381 -> V_388 ( V_2 , V_381 -> V_366 ) ;
F_324 ( V_381 -> V_366 , 1 ) ;
F_347 ( V_381 -> V_366 ) ;
F_255 ( V_381 ) ;
F_23 ( & V_2 -> V_10 ) ;
}
static int F_348 ( T_3 * V_145 , unsigned V_197 ,
int V_198 , void * V_389 )
{
struct V_386 * V_381 =
F_6 ( V_145 , struct V_386 , V_145 ) ;
struct V_1 * V_2 = V_381 -> V_2 ;
unsigned long V_52 = ( unsigned long ) V_389 ;
if ( V_52 & V_390 ) {
F_66 ( & V_2 -> V_391 ) ;
if ( ! F_349 ( & V_381 -> V_283 ) ) {
F_350 ( & V_381 -> V_283 ) ;
F_258 ( & V_381 -> remove ) ;
}
F_67 ( & V_2 -> V_391 ) ;
}
return 0 ;
}
static void F_351 ( struct V_392 * V_392 ,
T_9 * V_387 , T_10 * V_393 )
{
struct V_386 * V_381 =
F_6 ( V_393 , struct V_386 , V_393 ) ;
V_381 -> V_387 = V_387 ;
F_352 ( V_387 , & V_381 -> V_145 ) ;
}
static T_6 F_353 ( struct V_318 * V_319 ,
char * V_320 , T_7 V_321 , T_8 V_322 )
{
struct V_8 * V_10 = F_291 ( V_319 ) ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_386 * V_381 ;
struct V_8 * V_394 ;
unsigned int V_395 , V_396 ;
struct V_397 V_398 ;
struct V_397 V_399 ;
const char * V_347 ;
char * V_400 ;
int V_127 ;
V_320 = F_305 ( V_320 ) ;
V_395 = F_354 ( V_320 , & V_400 , 10 ) ;
if ( * V_400 != ' ' )
return - V_299 ;
V_320 = V_400 + 1 ;
V_396 = F_354 ( V_320 , & V_400 , 10 ) ;
if ( ( * V_400 != ' ' ) && ( * V_400 != '\0' ) )
return - V_299 ;
V_320 = V_400 + 1 ;
V_381 = F_355 ( sizeof( * V_381 ) , V_276 ) ;
if ( ! V_381 )
return - V_260 ;
V_381 -> V_2 = V_2 ;
F_174 ( & V_381 -> V_283 ) ;
F_356 ( & V_381 -> V_393 , F_351 ) ;
F_357 ( & V_381 -> V_145 , F_348 ) ;
F_192 ( & V_381 -> remove , F_345 ) ;
V_398 = F_358 ( V_395 ) ;
if ( ! V_398 . V_392 ) {
V_127 = - V_401 ;
goto V_402;
}
V_381 -> V_366 = F_359 ( V_398 . V_392 ) ;
if ( F_360 ( V_381 -> V_366 ) ) {
V_127 = F_361 ( V_381 -> V_366 ) ;
goto V_403;
}
V_399 = F_358 ( V_396 ) ;
if ( ! V_399 . V_392 ) {
V_127 = - V_401 ;
goto V_404;
}
V_127 = F_362 ( F_363 ( V_399 . V_392 ) , V_405 ) ;
if ( V_127 < 0 )
goto V_406;
V_347 = V_399 . V_392 -> V_407 . V_408 -> V_409 . V_347 ;
if ( ! strcmp ( V_347 , L_31 ) ) {
V_381 -> V_410 = F_332 ;
V_381 -> V_388 = F_335 ;
} else if ( ! strcmp ( V_347 , L_32 ) ) {
V_381 -> V_410 = F_337 ;
V_381 -> V_388 = F_338 ;
} else if ( ! strcmp ( V_347 , L_33 ) ) {
V_381 -> V_410 = V_411 ;
V_381 -> V_388 = V_412 ;
} else if ( ! strcmp ( V_347 , L_34 ) ) {
V_381 -> V_410 = F_333 ;
V_381 -> V_388 = F_336 ;
} else {
V_127 = - V_299 ;
goto V_406;
}
V_394 = F_364 ( V_399 . V_392 -> V_407 . V_408 -> V_413 ,
& V_15 ) ;
V_127 = - V_299 ;
if ( F_360 ( V_394 ) )
goto V_406;
if ( V_394 != V_10 ) {
F_23 ( V_394 ) ;
goto V_406;
}
V_127 = V_381 -> V_410 ( V_2 , V_381 -> V_366 , V_320 ) ;
if ( V_127 )
goto V_414;
V_398 . V_392 -> V_415 -> V_416 ( V_398 . V_392 , & V_381 -> V_393 ) ;
F_66 ( & V_2 -> V_391 ) ;
F_245 ( & V_381 -> V_283 , & V_2 -> V_417 ) ;
F_67 ( & V_2 -> V_391 ) ;
F_365 ( V_399 ) ;
F_365 ( V_398 ) ;
return V_321 ;
V_414:
F_23 ( V_10 ) ;
V_406:
F_365 ( V_399 ) ;
V_404:
F_347 ( V_381 -> V_366 ) ;
V_403:
F_365 ( V_398 ) ;
V_402:
F_255 ( V_381 ) ;
return V_127 ;
}
static int F_366 ( struct V_1 * V_2 , int V_182 )
{
struct V_418 * V_419 ;
struct V_28 * V_39 ;
int V_29 , V_288 = V_182 ;
if ( ! F_367 ( V_182 , V_420 ) )
V_288 = - 1 ;
V_419 = F_368 ( sizeof( * V_419 ) , V_276 , V_288 ) ;
if ( ! V_419 )
return 1 ;
for ( V_29 = 0 ; V_29 < V_58 ; V_29 ++ ) {
V_39 = & V_419 -> V_33 [ V_29 ] ;
F_369 ( & V_39 -> V_78 ) ;
V_39 -> V_48 = 0 ;
V_39 -> V_47 = false ;
V_39 -> V_2 = V_2 ;
}
V_2 -> V_32 [ V_182 ] = V_419 ;
return 0 ;
}
static void F_370 ( struct V_1 * V_2 , int V_182 )
{
F_255 ( V_2 -> V_32 [ V_182 ] ) ;
}
static struct V_1 * F_371 ( void )
{
struct V_1 * V_2 ;
T_7 V_272 ;
V_272 = sizeof( struct V_1 ) ;
V_272 += V_84 * sizeof( struct V_418 * ) ;
V_2 = F_355 ( V_272 , V_276 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_66 = F_372 ( struct V_421 ) ;
if ( ! V_2 -> V_66 )
goto V_422;
F_373 ( & V_2 -> V_68 ) ;
return V_2 ;
V_422:
F_255 ( V_2 ) ;
return NULL ;
}
static void F_374 ( struct V_1 * V_2 )
{
int V_182 ;
F_54 ( V_2 ) ;
F_55 (node)
F_370 ( V_2 , V_182 ) ;
F_375 ( V_2 -> V_66 ) ;
F_31 ( V_2 ) ;
F_255 ( V_2 ) ;
}
struct V_1 * F_53 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_55 . V_45 )
return NULL ;
return F_206 ( V_2 -> V_55 . V_45 , V_55 ) ;
}
static void T_4 F_376 ( void )
{
struct V_423 * V_424 ;
struct V_35 * V_425 ;
int V_288 , V_182 , V_29 ;
F_55 (node) {
V_288 = V_182 ;
if ( ! F_367 ( V_182 , V_420 ) )
V_288 = - 1 ;
V_424 = F_368 ( sizeof( * V_424 ) , V_276 , V_288 ) ;
F_14 ( ! V_424 ) ;
V_36 . V_37 [ V_182 ] = V_424 ;
for ( V_29 = 0 ; V_29 < V_58 ; V_29 ++ ) {
V_425 = & V_424 -> V_38 [ V_29 ] ;
V_425 -> V_44 = V_426 ;
F_373 ( & V_425 -> V_53 ) ;
}
}
}
static struct V_8 * T_11
F_377 ( struct V_8 * V_427 )
{
struct V_1 * V_2 ;
long error = - V_260 ;
int V_182 ;
V_2 = F_371 () ;
if ( ! V_2 )
return F_378 ( error ) ;
F_55 (node)
if ( F_366 ( V_2 , V_182 ) )
goto V_428;
if ( V_427 == NULL ) {
V_12 = V_2 ;
F_379 ( & V_2 -> V_55 , NULL ) ;
V_2 -> V_56 = V_339 ;
F_379 ( & V_2 -> V_138 , NULL ) ;
F_379 ( & V_2 -> V_27 , NULL ) ;
}
V_2 -> V_183 = V_97 ;
F_174 ( & V_2 -> V_382 ) ;
V_2 -> V_340 = 0 ;
F_380 ( & V_2 -> V_377 ) ;
F_373 ( & V_2 -> V_220 ) ;
F_381 ( & V_2 -> V_11 ) ;
F_174 ( & V_2 -> V_417 ) ;
F_373 ( & V_2 -> V_391 ) ;
#ifdef F_382
V_2 -> V_3 = - 1 ;
F_174 ( & V_2 -> V_284 ) ;
#endif
return & V_2 -> V_10 ;
V_428:
F_374 ( V_2 ) ;
return F_378 ( error ) ;
}
static int
F_383 ( struct V_8 * V_10 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_1 * V_45 = F_5 ( V_10 -> V_45 ) ;
int V_127 ;
if ( V_10 -> V_14 > V_429 )
return - V_430 ;
if ( ! V_45 )
return 0 ;
F_123 ( & V_314 ) ;
V_2 -> V_112 = V_45 -> V_112 ;
V_2 -> V_217 = V_45 -> V_217 ;
V_2 -> V_140 = F_114 ( V_45 ) ;
if ( V_45 -> V_112 ) {
F_379 ( & V_2 -> V_55 , & V_45 -> V_55 ) ;
V_2 -> V_56 = V_339 ;
F_379 ( & V_2 -> V_138 , & V_45 -> V_138 ) ;
F_379 ( & V_2 -> V_27 , & V_45 -> V_27 ) ;
} else {
F_379 ( & V_2 -> V_55 , NULL ) ;
V_2 -> V_56 = V_339 ;
F_379 ( & V_2 -> V_138 , NULL ) ;
F_379 ( & V_2 -> V_27 , NULL ) ;
if ( V_45 != V_12 )
V_15 . V_431 = true ;
}
F_130 ( & V_314 ) ;
V_127 = F_341 ( V_2 , & V_15 ) ;
if ( V_127 )
return V_127 ;
F_384 ( & V_2 -> V_118 , 1 ) ;
return 0 ;
}
static void F_385 ( struct V_8 * V_10 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
struct V_386 * V_381 , * V_288 ;
F_66 ( & V_2 -> V_391 ) ;
F_253 (event, tmp, &memcg->event_list, list) {
F_350 ( & V_381 -> V_283 ) ;
F_258 ( & V_381 -> remove ) ;
}
F_67 ( & V_2 -> V_391 ) ;
F_386 ( & V_2 -> V_11 ) ;
}
static void F_387 ( struct V_8 * V_10 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
F_343 ( V_2 ) ;
F_374 ( V_2 ) ;
}
static void F_388 ( struct V_8 * V_10 )
{
struct V_1 * V_2 = F_5 ( V_10 ) ;
F_280 ( V_2 , V_339 ) ;
F_283 ( V_2 , V_339 ) ;
F_302 ( V_2 , V_339 ) ;
V_2 -> V_56 = V_339 ;
}
static int F_389 ( unsigned long V_67 )
{
int V_127 ;
V_127 = F_203 ( V_5 . V_142 , V_276 & ~ V_256 , V_67 ) ;
if ( ! V_127 ) {
V_5 . V_432 += V_67 ;
return V_127 ;
}
if ( V_127 == - V_261 ) {
F_212 ( V_12 , V_67 ) ;
return V_127 ;
}
while ( V_67 -- ) {
V_127 = F_203 ( V_5 . V_142 , V_276 & ~ V_257 , 1 ) ;
if ( V_127 == - V_261 )
F_212 ( V_12 , 1 ) ;
if ( V_127 )
return V_127 ;
V_5 . V_432 ++ ;
F_390 () ;
}
return 0 ;
}
static struct V_34 * F_391 ( struct V_433 * V_434 ,
unsigned long V_435 , T_12 V_436 )
{
struct V_34 * V_34 = F_392 ( V_434 , V_435 , V_436 ) ;
if ( ! V_34 || ! F_272 ( V_34 ) )
return NULL ;
if ( F_71 ( V_34 ) ) {
if ( ! F_2 () )
return NULL ;
} else if ( ! F_4 () )
return NULL ;
if ( ! F_393 ( V_34 ) )
return NULL ;
return V_34 ;
}
static struct V_34 * F_394 ( struct V_433 * V_434 ,
unsigned long V_435 , T_12 V_436 , T_5 * V_303 )
{
struct V_34 * V_34 = NULL ;
T_5 V_262 = F_395 ( V_436 ) ;
if ( ! F_2 () || F_396 ( V_262 ) )
return NULL ;
V_34 = F_397 ( F_398 ( V_262 ) , V_262 . V_64 ) ;
if ( V_137 )
V_303 -> V_64 = V_262 . V_64 ;
return V_34 ;
}
static struct V_34 * F_394 ( struct V_433 * V_434 ,
unsigned long V_435 , T_12 V_436 , T_5 * V_303 )
{
return NULL ;
}
static struct V_34 * F_399 ( struct V_433 * V_434 ,
unsigned long V_435 , T_12 V_436 , T_5 * V_303 )
{
struct V_34 * V_34 = NULL ;
struct V_437 * V_438 ;
T_13 V_439 ;
if ( ! V_434 -> V_440 )
return NULL ;
if ( ! F_4 () )
return NULL ;
V_438 = V_434 -> V_440 -> V_441 ;
if ( F_400 ( V_436 ) )
V_439 = F_401 ( V_434 , V_435 ) ;
else
V_439 = F_402 ( V_436 ) ;
#ifdef F_403
if ( F_404 ( V_438 ) ) {
V_34 = F_405 ( V_438 , V_439 ) ;
if ( F_406 ( V_34 ) ) {
T_5 V_442 = F_407 ( V_34 ) ;
if ( V_137 )
* V_303 = V_442 ;
V_34 = F_397 ( F_398 ( V_442 ) , V_442 . V_64 ) ;
}
} else
V_34 = F_397 ( V_438 , V_439 ) ;
#else
V_34 = F_397 ( V_438 , V_439 ) ;
#endif
return V_34 ;
}
static enum V_443 F_408 ( struct V_433 * V_434 ,
unsigned long V_435 , T_12 V_436 , union V_444 * V_86 )
{
struct V_34 * V_34 = NULL ;
enum V_443 V_127 = V_445 ;
T_5 V_262 = { . V_64 = 0 } ;
if ( F_409 ( V_436 ) )
V_34 = F_391 ( V_434 , V_435 , V_436 ) ;
else if ( F_410 ( V_436 ) )
V_34 = F_394 ( V_434 , V_435 , V_436 , & V_262 ) ;
else if ( F_400 ( V_436 ) || F_411 ( V_436 ) )
V_34 = F_399 ( V_434 , V_435 , V_436 , & V_262 ) ;
if ( ! V_34 && ! V_262 . V_64 )
return V_127 ;
if ( V_34 ) {
if ( V_34 -> V_1 == V_5 . V_141 ) {
V_127 = V_446 ;
if ( V_86 )
V_86 -> V_34 = V_34 ;
}
if ( ! V_127 || ! V_86 )
F_412 ( V_34 ) ;
}
if ( V_262 . V_64 && ! V_127 &&
F_10 ( V_5 . V_141 ) == F_219 ( V_262 ) ) {
V_127 = V_447 ;
if ( V_86 )
V_86 -> V_262 = V_262 ;
}
return V_127 ;
}
static enum V_443 F_413 ( struct V_433 * V_434 ,
unsigned long V_435 , T_14 V_448 , union V_444 * V_86 )
{
struct V_34 * V_34 = NULL ;
enum V_443 V_127 = V_445 ;
V_34 = F_414 ( V_448 ) ;
F_215 ( ! V_34 || ! F_415 ( V_34 ) , V_34 ) ;
if ( ! F_2 () )
return V_127 ;
if ( V_34 -> V_1 == V_5 . V_141 ) {
V_127 = V_446 ;
if ( V_86 ) {
F_416 ( V_34 ) ;
V_86 -> V_34 = V_34 ;
}
}
return V_127 ;
}
static inline enum V_443 F_413 ( struct V_433 * V_434 ,
unsigned long V_435 , T_14 V_448 , union V_444 * V_86 )
{
return V_445 ;
}
static int F_417 ( T_14 * V_448 ,
unsigned long V_435 , unsigned long V_449 ,
struct V_450 * V_451 )
{
struct V_433 * V_434 = V_451 -> V_214 ;
T_12 * V_452 ;
T_15 * V_453 ;
if ( F_418 ( V_448 , V_434 , & V_453 ) == 1 ) {
if ( F_413 ( V_434 , V_435 , * V_448 , NULL ) == V_446 )
V_5 . V_432 += V_297 ;
F_67 ( V_453 ) ;
return 0 ;
}
if ( F_419 ( V_448 ) )
return 0 ;
V_452 = F_420 ( V_434 -> V_454 , V_448 , V_435 , & V_453 ) ;
for (; V_435 != V_449 ; V_452 ++ , V_435 += V_332 )
if ( F_408 ( V_434 , V_435 , * V_452 , NULL ) )
V_5 . V_432 ++ ;
F_421 ( V_452 - 1 , V_453 ) ;
F_390 () ;
return 0 ;
}
static unsigned long F_422 ( struct V_101 * V_102 )
{
unsigned long V_432 ;
struct V_433 * V_434 ;
F_423 ( & V_102 -> V_455 ) ;
for ( V_434 = V_102 -> V_456 ; V_434 ; V_434 = V_434 -> V_457 ) {
struct V_450 V_458 = {
. V_459 = F_417 ,
. V_102 = V_102 ,
. V_214 = V_434 ,
} ;
if ( F_424 ( V_434 ) )
continue;
F_425 ( V_434 -> V_460 , V_434 -> V_461 ,
& V_458 ) ;
}
F_426 ( & V_102 -> V_455 ) ;
V_432 = V_5 . V_432 ;
V_5 . V_432 = 0 ;
return V_432 ;
}
static int F_427 ( struct V_101 * V_102 )
{
unsigned long V_432 = F_422 ( V_102 ) ;
F_77 ( V_5 . V_144 ) ;
V_5 . V_144 = V_23 ;
return F_389 ( V_432 ) ;
}
static void F_428 ( void )
{
struct V_1 * V_141 = V_5 . V_141 ;
struct V_1 * V_142 = V_5 . V_142 ;
if ( V_5 . V_432 ) {
F_212 ( V_5 . V_142 , V_5 . V_432 ) ;
V_5 . V_432 = 0 ;
}
if ( V_5 . V_462 ) {
F_212 ( V_5 . V_141 , V_5 . V_462 ) ;
V_5 . V_462 = 0 ;
}
if ( V_5 . V_463 ) {
if ( ! F_9 ( V_5 . V_141 ) )
F_185 ( & V_5 . V_141 -> V_138 , V_5 . V_463 ) ;
if ( ! F_9 ( V_5 . V_142 ) )
F_185 ( & V_5 . V_142 -> V_55 , V_5 . V_463 ) ;
F_186 ( & V_5 . V_141 -> V_10 , V_5 . V_463 ) ;
V_5 . V_463 = 0 ;
}
F_171 ( V_141 ) ;
F_171 ( V_142 ) ;
F_429 ( & V_5 . V_146 ) ;
}
static void F_430 ( void )
{
V_5 . V_144 = NULL ;
F_428 () ;
F_66 ( & V_5 . V_53 ) ;
V_5 . V_141 = NULL ;
V_5 . V_142 = NULL ;
F_67 ( & V_5 . V_53 ) ;
}
static int F_431 ( struct V_8 * V_10 ,
struct V_464 * V_465 )
{
struct V_99 * V_43 = F_432 ( V_465 ) ;
int V_127 = 0 ;
struct V_1 * V_2 = F_5 ( V_10 ) ;
unsigned long V_340 ;
V_340 = V_2 -> V_340 ;
if ( V_340 ) {
struct V_101 * V_102 ;
struct V_1 * V_141 = F_17 ( V_43 ) ;
F_77 ( V_141 == V_2 ) ;
V_102 = F_433 ( V_43 ) ;
if ( ! V_102 )
return 0 ;
if ( V_102 -> V_103 == V_43 ) {
F_77 ( V_5 . V_141 ) ;
F_77 ( V_5 . V_142 ) ;
F_77 ( V_5 . V_432 ) ;
F_77 ( V_5 . V_462 ) ;
F_77 ( V_5 . V_463 ) ;
F_66 ( & V_5 . V_53 ) ;
V_5 . V_141 = V_141 ;
V_5 . V_142 = V_2 ;
V_5 . V_6 = V_340 ;
F_67 ( & V_5 . V_53 ) ;
V_127 = F_427 ( V_102 ) ;
if ( V_127 )
F_430 () ;
}
F_434 ( V_102 ) ;
}
return V_127 ;
}
static void F_435 ( struct V_8 * V_10 ,
struct V_464 * V_465 )
{
if ( V_5 . V_142 )
F_430 () ;
}
static int F_436 ( T_14 * V_448 ,
unsigned long V_435 , unsigned long V_449 ,
struct V_450 * V_451 )
{
int V_127 = 0 ;
struct V_433 * V_434 = V_451 -> V_214 ;
T_12 * V_452 ;
T_15 * V_453 ;
enum V_443 V_466 ;
union V_444 V_86 ;
struct V_34 * V_34 ;
if ( F_418 ( V_448 , V_434 , & V_453 ) == 1 ) {
if ( V_5 . V_432 < V_297 ) {
F_67 ( V_453 ) ;
return 0 ;
}
V_466 = F_413 ( V_434 , V_435 , * V_448 , & V_86 ) ;
if ( V_466 == V_446 ) {
V_34 = V_86 . V_34 ;
if ( ! F_437 ( V_34 ) ) {
if ( ! F_270 ( V_34 , V_297 ,
V_5 . V_141 , V_5 . V_142 ) ) {
V_5 . V_432 -= V_297 ;
V_5 . V_462 += V_297 ;
}
F_438 ( V_34 ) ;
}
F_412 ( V_34 ) ;
}
F_67 ( V_453 ) ;
return 0 ;
}
if ( F_419 ( V_448 ) )
return 0 ;
V_60:
V_452 = F_420 ( V_434 -> V_454 , V_448 , V_435 , & V_453 ) ;
for (; V_435 != V_449 ; V_435 += V_332 ) {
T_12 V_436 = * ( V_452 ++ ) ;
T_5 V_262 ;
if ( ! V_5 . V_432 )
break;
switch ( F_408 ( V_434 , V_435 , V_436 , & V_86 ) ) {
case V_446 :
V_34 = V_86 . V_34 ;
if ( F_437 ( V_34 ) )
goto V_467;
if ( ! F_270 ( V_34 , 1 , V_5 . V_141 , V_5 . V_142 ) ) {
V_5 . V_432 -- ;
V_5 . V_462 ++ ;
}
F_438 ( V_34 ) ;
V_467:
F_412 ( V_34 ) ;
break;
case V_447 :
V_262 = V_86 . V_262 ;
if ( ! F_278 ( V_262 , V_5 . V_141 , V_5 . V_142 ) ) {
V_5 . V_432 -- ;
V_5 . V_463 ++ ;
}
break;
default:
break;
}
}
F_421 ( V_452 - 1 , V_453 ) ;
F_390 () ;
if ( V_435 != V_449 ) {
V_127 = F_389 ( 1 ) ;
if ( ! V_127 )
goto V_60;
}
return V_127 ;
}
static void F_439 ( struct V_101 * V_102 )
{
struct V_433 * V_434 ;
F_288 () ;
F_88 ( & V_5 . V_141 -> V_219 ) ;
F_331 () ;
V_60:
if ( F_86 ( ! F_440 ( & V_102 -> V_455 ) ) ) {
F_428 () ;
F_390 () ;
goto V_60;
}
for ( V_434 = V_102 -> V_456 ; V_434 ; V_434 = V_434 -> V_457 ) {
int V_127 ;
struct V_450 V_468 = {
. V_459 = F_436 ,
. V_102 = V_102 ,
. V_214 = V_434 ,
} ;
if ( F_424 ( V_434 ) )
continue;
V_127 = F_425 ( V_434 -> V_460 , V_434 -> V_461 ,
& V_468 ) ;
if ( V_127 )
break;
}
F_426 ( & V_102 -> V_455 ) ;
F_441 ( & V_5 . V_141 -> V_219 ) ;
}
static void F_442 ( struct V_8 * V_10 ,
struct V_464 * V_465 )
{
struct V_99 * V_43 = F_432 ( V_465 ) ;
struct V_101 * V_102 = F_433 ( V_43 ) ;
if ( V_102 ) {
if ( V_5 . V_142 )
F_439 ( V_102 ) ;
F_434 ( V_102 ) ;
}
if ( V_5 . V_142 )
F_430 () ;
}
static int F_431 ( struct V_8 * V_10 ,
struct V_464 * V_465 )
{
return 0 ;
}
static void F_435 ( struct V_8 * V_10 ,
struct V_464 * V_465 )
{
}
static void F_442 ( struct V_8 * V_10 ,
struct V_464 * V_465 )
{
}
static void F_443 ( struct V_8 * V_469 )
{
if ( F_444 ( V_469 -> V_124 ) )
F_5 ( V_469 ) -> V_112 = true ;
}
static int T_4 F_445 ( char * V_9 )
{
if ( ! strcmp ( V_9 , L_35 ) )
V_470 = 1 ;
else if ( ! strcmp ( V_9 , L_36 ) )
V_470 = 0 ;
return 1 ;
}
static void T_4 F_446 ( void )
{
F_22 ( F_447 ( & V_15 ,
V_471 ) ) ;
}
static void T_4 F_448 ( void )
{
if ( ! F_93 () && V_470 ) {
V_137 = 1 ;
F_446 () ;
}
}
static void T_4 F_448 ( void )
{
}
void F_449 ( struct V_34 * V_34 , T_5 V_303 )
{
struct V_1 * V_2 ;
unsigned short V_472 ;
F_215 ( F_222 ( V_34 ) , V_34 ) ;
F_215 ( F_450 ( V_34 ) , V_34 ) ;
if ( ! V_137 )
return;
V_2 = V_34 -> V_1 ;
if ( ! V_2 )
return;
V_472 = F_451 ( V_303 , F_10 ( V_2 ) ) ;
F_215 ( V_472 , V_34 ) ;
F_277 ( V_2 , true ) ;
V_34 -> V_1 = NULL ;
if ( ! F_9 ( V_2 ) )
F_185 ( & V_2 -> V_55 , 1 ) ;
F_77 ( ! F_452 () ) ;
F_70 ( V_2 , V_34 , - 1 ) ;
F_85 ( V_2 , V_34 ) ;
}
void F_453 ( T_5 V_303 )
{
struct V_1 * V_2 ;
unsigned short V_14 ;
if ( ! V_137 )
return;
V_14 = F_451 ( V_303 , 0 ) ;
F_16 () ;
V_2 = F_213 ( V_14 ) ;
if ( V_2 ) {
if ( ! F_9 ( V_2 ) )
F_185 ( & V_2 -> V_138 , 1 ) ;
F_277 ( V_2 , false ) ;
F_23 ( & V_2 -> V_10 ) ;
}
F_20 () ;
}
int F_454 ( struct V_34 * V_34 , struct V_101 * V_102 ,
T_2 V_160 , struct V_1 * * V_473 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_54 = 1 ;
int V_127 = 0 ;
if ( F_93 () )
goto V_113;
if ( F_217 ( V_34 ) ) {
if ( V_34 -> V_1 )
goto V_113;
}
if ( F_73 ( V_34 ) ) {
V_54 <<= F_455 ( V_34 ) ;
F_215 ( ! F_73 ( V_34 ) , V_34 ) ;
}
if ( V_137 && F_217 ( V_34 ) )
V_2 = F_214 ( V_34 ) ;
if ( ! V_2 )
V_2 = F_90 ( V_102 ) ;
V_127 = F_203 ( V_2 , V_160 , V_54 ) ;
F_23 ( & V_2 -> V_10 ) ;
if ( V_127 == - V_261 ) {
V_2 = V_12 ;
V_127 = 0 ;
}
V_113:
* V_473 = V_2 ;
return V_127 ;
}
void F_456 ( struct V_34 * V_34 , struct V_1 * V_2 ,
bool V_265 )
{
unsigned int V_54 = 1 ;
F_215 ( ! V_34 -> V_438 , V_34 ) ;
F_215 ( F_222 ( V_34 ) && ! V_265 , V_34 ) ;
if ( F_93 () )
return;
if ( ! V_2 )
return;
F_229 ( V_34 , V_2 , V_265 ) ;
if ( F_73 ( V_34 ) ) {
V_54 <<= F_455 ( V_34 ) ;
F_215 ( ! F_73 ( V_34 ) , V_34 ) ;
}
F_274 () ;
F_70 ( V_2 , V_34 , V_54 ) ;
F_85 ( V_2 , V_34 ) ;
F_275 () ;
if ( V_137 && F_217 ( V_34 ) ) {
T_5 V_303 = { . V_64 = F_218 (page) } ;
F_453 ( V_303 ) ;
}
}
void F_457 ( struct V_34 * V_34 , struct V_1 * V_2 )
{
unsigned int V_54 = 1 ;
if ( F_93 () )
return;
if ( ! V_2 )
return;
if ( F_73 ( V_34 ) ) {
V_54 <<= F_455 ( V_34 ) ;
F_215 ( ! F_73 ( V_34 ) , V_34 ) ;
}
F_212 ( V_2 , V_54 ) ;
}
static void F_458 ( struct V_1 * V_2 , unsigned long V_474 ,
unsigned long V_475 , unsigned long V_476 ,
unsigned long V_477 , struct V_34 * V_478 )
{
unsigned long V_54 = V_475 + V_476 ;
unsigned long V_52 ;
if ( ! F_9 ( V_2 ) ) {
F_185 ( & V_2 -> V_55 , V_54 ) ;
if ( V_137 )
F_185 ( & V_2 -> V_138 , V_54 ) ;
F_171 ( V_2 ) ;
}
F_459 ( V_52 ) ;
F_269 ( V_2 -> V_66 -> V_67 [ V_72 ] , V_475 ) ;
F_269 ( V_2 -> V_66 -> V_67 [ V_73 ] , V_476 ) ;
F_269 ( V_2 -> V_66 -> V_67 [ V_74 ] , V_477 ) ;
F_72 ( V_2 -> V_66 -> V_71 [ V_76 ] , V_474 ) ;
F_72 ( V_2 -> V_66 -> V_77 , V_54 ) ;
F_85 ( V_2 , V_478 ) ;
F_460 ( V_52 ) ;
if ( ! F_9 ( V_2 ) )
F_186 ( & V_2 -> V_10 , V_54 ) ;
}
static void F_461 ( struct V_479 * V_480 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_475 = 0 ;
unsigned long V_476 = 0 ;
unsigned long V_477 = 0 ;
unsigned long V_474 = 0 ;
struct V_479 * V_87 ;
struct V_34 * V_34 ;
V_87 = V_480 -> V_87 ;
do {
unsigned int V_54 = 1 ;
V_34 = F_462 ( V_87 , struct V_34 , V_80 ) ;
V_87 = V_34 -> V_80 . V_87 ;
F_215 ( F_222 ( V_34 ) , V_34 ) ;
F_215 ( F_450 ( V_34 ) , V_34 ) ;
if ( ! V_34 -> V_1 )
continue;
if ( V_2 != V_34 -> V_1 ) {
if ( V_2 ) {
F_458 ( V_2 , V_474 , V_475 , V_476 ,
V_477 , V_34 ) ;
V_474 = V_475 = V_476 = V_477 = 0 ;
}
V_2 = V_34 -> V_1 ;
}
if ( F_73 ( V_34 ) ) {
V_54 <<= F_455 ( V_34 ) ;
F_215 ( ! F_73 ( V_34 ) , V_34 ) ;
V_477 += V_54 ;
}
if ( F_71 ( V_34 ) )
V_475 += V_54 ;
else
V_476 += V_54 ;
V_34 -> V_1 = NULL ;
V_474 ++ ;
} while ( V_87 != V_480 );
if ( V_2 )
F_458 ( V_2 , V_474 , V_475 , V_476 ,
V_477 , V_34 ) ;
}
void F_463 ( struct V_34 * V_34 )
{
if ( F_93 () )
return;
if ( ! V_34 -> V_1 )
return;
F_174 ( & V_34 -> V_80 ) ;
F_461 ( & V_34 -> V_80 ) ;
}
void F_464 ( struct V_479 * V_480 )
{
if ( F_93 () )
return;
if ( ! F_349 ( V_480 ) )
F_461 ( V_480 ) ;
}
void F_465 ( struct V_34 * V_481 , struct V_34 * V_482 ,
bool V_265 )
{
struct V_1 * V_2 ;
int V_263 ;
F_215 ( ! F_216 ( V_481 ) , V_481 ) ;
F_215 ( ! F_216 ( V_482 ) , V_482 ) ;
F_215 ( ! V_265 && F_222 ( V_481 ) , V_481 ) ;
F_215 ( ! V_265 && F_222 ( V_482 ) , V_482 ) ;
F_215 ( F_71 ( V_481 ) != F_71 ( V_482 ) , V_482 ) ;
F_215 ( F_73 ( V_481 ) != F_73 ( V_482 ) ,
V_482 ) ;
if ( F_93 () )
return;
if ( V_482 -> V_1 )
return;
V_2 = V_481 -> V_1 ;
if ( ! V_2 )
return;
if ( V_265 )
F_220 ( V_481 , & V_263 ) ;
V_481 -> V_1 = NULL ;
if ( V_265 )
F_226 ( V_481 , V_263 ) ;
F_229 ( V_482 , V_2 , V_265 ) ;
}
static int T_4 F_466 ( void )
{
F_467 ( F_201 , 0 ) ;
F_448 () ;
F_376 () ;
F_190 () ;
return 0 ;
}
