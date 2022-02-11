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
static inline
struct V_6 * F_4 ( struct V_7 * V_8 )
{
return F_5 ( V_8 , struct V_6 , V_9 ) ;
}
void F_6 ( struct V_10 * V_11 )
{
if ( V_12 ) {
struct V_6 * V_13 ;
struct V_14 * V_14 ;
F_7 ( ! V_11 -> V_15 -> V_16 ) ;
if ( V_11 -> V_17 ) {
F_7 ( F_8 ( V_11 -> V_17 -> V_13 ) ) ;
F_9 ( V_11 -> V_17 -> V_13 ) ;
return;
}
F_10 () ;
V_13 = F_11 ( V_18 ) ;
V_14 = V_11 -> V_15 -> V_16 ( V_13 ) ;
if ( ! F_8 ( V_13 ) && F_12 ( V_14 ) ) {
F_9 ( V_13 ) ;
V_11 -> V_17 = V_14 ;
}
F_13 () ;
}
}
void F_14 ( struct V_10 * V_11 )
{
if ( V_12 && V_11 -> V_17 ) {
struct V_6 * V_13 ;
F_15 ( ! V_11 -> V_17 -> V_13 ) ;
V_13 = V_11 -> V_17 -> V_13 ;
F_16 ( V_13 ) ;
}
}
struct V_14 * F_17 ( struct V_6 * V_13 )
{
if ( ! V_13 || F_8 ( V_13 ) )
return NULL ;
return & V_13 -> V_19 . V_14 ;
}
static void F_18 ( struct V_6 * V_13 )
{
if ( ! F_19 ( & V_13 -> V_19 . V_14 ) )
return;
F_20 ( & V_20 ) ;
}
static void F_18 ( struct V_6 * V_13 )
{
}
static struct V_21 *
F_21 ( struct V_6 * V_13 , int V_22 , int V_23 )
{
return & V_13 -> V_24 . V_25 [ V_22 ] -> V_26 [ V_23 ] ;
}
struct V_7 * F_22 ( struct V_6 * V_13 )
{
return & V_13 -> V_9 ;
}
static struct V_21 *
F_23 ( struct V_6 * V_13 , struct V_27 * V_27 )
{
int V_22 = F_24 ( V_27 ) ;
int V_23 = F_25 ( V_27 ) ;
return F_21 ( V_13 , V_22 , V_23 ) ;
}
static struct V_28 *
F_26 ( int V_22 , int V_23 )
{
return & V_29 . V_30 [ V_22 ] -> V_31 [ V_23 ] ;
}
static struct V_28 *
F_27 ( struct V_27 * V_27 )
{
int V_22 = F_24 ( V_27 ) ;
int V_23 = F_25 ( V_27 ) ;
return & V_29 . V_30 [ V_22 ] -> V_31 [ V_23 ] ;
}
static void
F_28 ( struct V_6 * V_13 ,
struct V_21 * V_32 ,
struct V_28 * V_33 ,
unsigned long long V_34 )
{
struct V_35 * * V_36 = & V_33 -> V_37 . V_35 ;
struct V_35 * V_38 = NULL ;
struct V_21 * V_39 ;
if ( V_32 -> V_40 )
return;
V_32 -> V_41 = V_34 ;
if ( ! V_32 -> V_41 )
return;
while ( * V_36 ) {
V_38 = * V_36 ;
V_39 = F_29 ( V_38 , struct V_21 ,
V_42 ) ;
if ( V_32 -> V_41 < V_39 -> V_41 )
V_36 = & ( * V_36 ) -> V_43 ;
else if ( V_32 -> V_41 >= V_39 -> V_41 )
V_36 = & ( * V_36 ) -> V_44 ;
}
F_30 ( & V_32 -> V_42 , V_38 , V_36 ) ;
F_31 ( & V_32 -> V_42 , & V_33 -> V_37 ) ;
V_32 -> V_40 = true ;
}
static void
F_32 ( struct V_6 * V_13 ,
struct V_21 * V_32 ,
struct V_28 * V_33 )
{
if ( ! V_32 -> V_40 )
return;
F_33 ( & V_32 -> V_42 , & V_33 -> V_37 ) ;
V_32 -> V_40 = false ;
}
static void
F_34 ( struct V_6 * V_13 ,
struct V_21 * V_32 ,
struct V_28 * V_33 )
{
F_35 ( & V_33 -> V_45 ) ;
F_32 ( V_13 , V_32 , V_33 ) ;
F_36 ( & V_33 -> V_45 ) ;
}
static void F_37 ( struct V_6 * V_13 , struct V_27 * V_27 )
{
unsigned long long V_46 ;
struct V_21 * V_32 ;
struct V_28 * V_33 ;
int V_22 = F_24 ( V_27 ) ;
int V_23 = F_25 ( V_27 ) ;
V_33 = F_27 ( V_27 ) ;
for (; V_13 ; V_13 = F_38 ( V_13 ) ) {
V_32 = F_21 ( V_13 , V_22 , V_23 ) ;
V_46 = F_39 ( & V_13 -> V_47 ) ;
if ( V_46 || V_32 -> V_40 ) {
F_35 ( & V_33 -> V_45 ) ;
if ( V_32 -> V_40 )
F_32 ( V_13 , V_32 , V_33 ) ;
F_28 ( V_13 , V_32 , V_33 , V_46 ) ;
F_36 ( & V_33 -> V_45 ) ;
}
}
}
static void F_40 ( struct V_6 * V_13 )
{
int V_48 , V_49 ;
struct V_21 * V_32 ;
struct V_28 * V_33 ;
F_41 (node) {
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_32 = F_21 ( V_13 , V_48 , V_49 ) ;
V_33 = F_26 ( V_48 , V_49 ) ;
F_34 ( V_13 , V_32 , V_33 ) ;
}
}
}
static struct V_21 *
F_42 ( struct V_28 * V_33 )
{
struct V_35 * V_51 = NULL ;
struct V_21 * V_32 ;
V_52:
V_32 = NULL ;
V_51 = F_43 ( & V_33 -> V_37 ) ;
if ( ! V_51 )
goto V_53;
V_32 = F_29 ( V_51 , struct V_21 , V_42 ) ;
F_32 ( V_32 -> V_13 , V_32 , V_33 ) ;
if ( ! F_39 ( & V_32 -> V_13 -> V_47 ) ||
! F_44 ( & V_32 -> V_13 -> V_9 ) )
goto V_52;
V_53:
return V_32 ;
}
static struct V_21 *
F_45 ( struct V_28 * V_33 )
{
struct V_21 * V_32 ;
F_35 ( & V_33 -> V_45 ) ;
V_32 = F_42 ( V_33 ) ;
F_36 ( & V_33 -> V_45 ) ;
return V_32 ;
}
static long F_46 ( struct V_6 * V_13 ,
enum V_54 V_55 )
{
long V_56 = 0 ;
int V_57 ;
F_47 () ;
F_48 (cpu)
V_56 += F_49 ( V_13 -> V_58 -> V_59 [ V_55 ] , V_57 ) ;
#ifdef F_50
F_35 ( & V_13 -> V_60 ) ;
V_56 += V_13 -> V_61 . V_59 [ V_55 ] ;
F_36 ( & V_13 -> V_60 ) ;
#endif
F_51 () ;
return V_56 ;
}
static void F_52 ( struct V_6 * V_13 ,
bool V_62 )
{
int V_56 = ( V_62 ) ? 1 : - 1 ;
F_53 ( V_13 -> V_58 -> V_59 [ V_63 ] , V_56 ) ;
}
static unsigned long F_54 ( struct V_6 * V_13 ,
enum V_64 V_55 )
{
unsigned long V_56 = 0 ;
int V_57 ;
F_48 (cpu)
V_56 += F_49 ( V_13 -> V_58 -> V_65 [ V_55 ] , V_57 ) ;
#ifdef F_50
F_35 ( & V_13 -> V_60 ) ;
V_56 += V_13 -> V_61 . V_65 [ V_55 ] ;
F_36 ( & V_13 -> V_60 ) ;
#endif
return V_56 ;
}
static void F_55 ( struct V_6 * V_13 ,
bool V_66 , int V_67 )
{
F_56 () ;
if ( V_66 )
F_57 ( V_13 -> V_58 -> V_59 [ V_68 ] ,
V_67 ) ;
else
F_57 ( V_13 -> V_58 -> V_59 [ V_69 ] ,
V_67 ) ;
if ( V_67 > 0 )
F_58 ( V_13 -> V_58 -> V_65 [ V_70 ] ) ;
else {
F_58 ( V_13 -> V_58 -> V_65 [ V_71 ] ) ;
V_67 = - V_67 ;
}
F_57 ( V_13 -> V_58 -> V_72 , V_67 ) ;
F_59 () ;
}
unsigned long
F_60 ( struct V_73 * V_73 , enum V_74 V_75 )
{
struct V_21 * V_32 ;
V_32 = F_5 ( V_73 , struct V_21 , V_73 ) ;
return V_32 -> V_76 [ V_75 ] ;
}
static unsigned long
F_61 ( struct V_6 * V_13 , int V_22 , int V_23 ,
unsigned int V_77 )
{
struct V_21 * V_32 ;
enum V_74 V_75 ;
unsigned long V_78 = 0 ;
V_32 = F_21 ( V_13 , V_22 , V_23 ) ;
F_62 (lru) {
if ( F_63 ( V_75 ) & V_77 )
V_78 += V_32 -> V_76 [ V_75 ] ;
}
return V_78 ;
}
static unsigned long
F_64 ( struct V_6 * V_13 ,
int V_22 , unsigned int V_77 )
{
T_1 V_79 = 0 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_50 ; V_23 ++ )
V_79 += F_61 ( V_13 ,
V_22 , V_23 , V_77 ) ;
return V_79 ;
}
static unsigned long F_65 ( struct V_6 * V_13 ,
unsigned int V_77 )
{
int V_22 ;
T_1 V_79 = 0 ;
F_66 (nid, N_HIGH_MEMORY)
V_79 += F_64 ( V_13 , V_22 , V_77 ) ;
return V_79 ;
}
static bool F_67 ( struct V_6 * V_13 ,
enum V_80 V_81 )
{
unsigned long V_56 , V_82 ;
V_56 = F_68 ( V_13 -> V_58 -> V_72 ) ;
V_82 = F_68 ( V_13 -> V_58 -> V_83 [ V_81 ] ) ;
if ( ( long ) V_82 - ( long ) V_56 < 0 ) {
switch ( V_81 ) {
case V_84 :
V_82 = V_56 + V_85 ;
break;
case V_86 :
V_82 = V_56 + V_87 ;
break;
case V_88 :
V_82 = V_56 + V_89 ;
break;
default:
break;
}
F_69 ( V_13 -> V_58 -> V_83 [ V_81 ] , V_82 ) ;
return true ;
}
return false ;
}
static void F_70 ( struct V_6 * V_13 , struct V_27 * V_27 )
{
F_56 () ;
if ( F_71 ( F_67 ( V_13 ,
V_84 ) ) ) {
bool V_90 ;
bool T_2 V_91 ;
V_90 = F_67 ( V_13 ,
V_86 ) ;
#if V_92 > 1
T_2 = F_67 ( V_13 ,
V_88 ) ;
#endif
F_59 () ;
F_72 ( V_13 ) ;
if ( F_71 ( V_90 ) )
F_37 ( V_13 , V_27 ) ;
#if V_92 > 1
if ( F_71 ( T_2 ) )
F_73 ( & V_13 -> V_93 ) ;
#endif
} else
F_59 () ;
}
struct V_6 * F_74 ( struct V_94 * V_95 )
{
return F_4 (
V_7 ( V_95 , V_96 ) ) ;
}
struct V_6 * F_11 ( struct V_97 * V_36 )
{
if ( F_71 ( ! V_36 ) )
return NULL ;
return F_4 ( F_75 ( V_36 , V_96 ) ) ;
}
struct V_6 * F_76 ( struct V_98 * V_99 )
{
struct V_6 * V_13 = NULL ;
if ( ! V_99 )
return NULL ;
F_10 () ;
do {
V_13 = F_11 ( F_77 ( V_99 -> V_100 ) ) ;
if ( F_71 ( ! V_13 ) )
break;
} while ( ! F_44 ( & V_13 -> V_9 ) );
F_13 () ;
return V_13 ;
}
struct V_6 * F_78 ( struct V_6 * V_101 ,
struct V_6 * V_102 ,
struct V_103 * V_104 )
{
struct V_6 * V_13 = NULL ;
int V_105 = 0 ;
if ( F_79 () )
return NULL ;
if ( ! V_101 )
V_101 = V_106 ;
if ( V_102 && ! V_104 )
V_105 = F_80 ( & V_102 -> V_9 ) ;
if ( V_102 && V_102 != V_101 )
F_81 ( & V_102 -> V_9 ) ;
if ( ! V_101 -> V_107 && V_101 != V_106 ) {
if ( V_102 )
return NULL ;
return V_101 ;
}
while ( ! V_13 ) {
struct V_108 * V_109 ( V_110 ) ;
struct V_7 * V_9 ;
if ( V_104 ) {
int V_22 = F_82 ( V_104 -> V_49 ) ;
int V_23 = F_83 ( V_104 -> V_49 ) ;
struct V_21 * V_32 ;
V_32 = F_21 ( V_101 , V_22 , V_23 ) ;
V_110 = & V_32 -> V_111 [ V_104 -> V_112 ] ;
if ( V_102 && V_104 -> V_113 != V_110 -> V_113 )
return NULL ;
V_105 = V_110 -> V_114 ;
}
F_10 () ;
V_9 = F_84 ( & V_115 , V_105 + 1 , & V_101 -> V_9 , & V_105 ) ;
if ( V_9 ) {
if ( V_9 == & V_101 -> V_9 || F_44 ( V_9 ) )
V_13 = F_4 ( V_9 ) ;
} else
V_105 = 0 ;
F_13 () ;
if ( V_104 ) {
V_110 -> V_114 = V_105 ;
if ( ! V_9 )
V_110 -> V_113 ++ ;
else if ( ! V_102 && V_13 )
V_104 -> V_113 = V_110 -> V_113 ;
}
if ( V_102 && ! V_9 )
return NULL ;
}
return V_13 ;
}
void F_85 ( struct V_6 * V_101 ,
struct V_6 * V_102 )
{
if ( ! V_101 )
V_101 = V_106 ;
if ( V_102 && V_102 != V_101 )
F_81 ( & V_102 -> V_9 ) ;
}
static inline bool F_8 ( struct V_6 * V_13 )
{
return ( V_13 == V_106 ) ;
}
void F_86 ( struct V_98 * V_99 , enum V_116 V_55 )
{
struct V_6 * V_13 ;
if ( ! V_99 )
return;
F_10 () ;
V_13 = F_11 ( F_77 ( V_99 -> V_100 ) ) ;
if ( F_71 ( ! V_13 ) )
goto V_117;
switch ( V_55 ) {
case V_118 :
F_87 ( V_13 -> V_58 -> V_65 [ V_119 ] ) ;
break;
case V_120 :
F_87 ( V_13 -> V_58 -> V_65 [ V_121 ] ) ;
break;
default:
F_88 () ;
}
V_117:
F_13 () ;
}
struct V_73 * F_89 ( struct V_49 * V_49 ,
struct V_6 * V_13 )
{
struct V_21 * V_32 ;
if ( F_79 () )
return & V_49 -> V_73 ;
V_32 = F_21 ( V_13 , F_82 ( V_49 ) , F_83 ( V_49 ) ) ;
return & V_32 -> V_73 ;
}
struct V_73 * F_90 ( struct V_27 * V_27 , struct V_49 * V_49 )
{
struct V_21 * V_32 ;
struct V_6 * V_13 ;
struct V_122 * V_123 ;
if ( F_79 () )
return & V_49 -> V_73 ;
V_123 = F_91 ( V_27 ) ;
V_13 = V_123 -> V_6 ;
if ( ! F_92 ( V_27 ) && ! F_93 ( V_123 ) && V_13 != V_106 )
V_123 -> V_6 = V_13 = V_106 ;
V_32 = F_23 ( V_13 , V_27 ) ;
return & V_32 -> V_73 ;
}
void F_94 ( struct V_73 * V_73 , enum V_74 V_75 ,
int V_67 )
{
struct V_21 * V_32 ;
unsigned long * V_76 ;
if ( F_79 () )
return;
V_32 = F_5 ( V_73 , struct V_21 , V_73 ) ;
V_76 = V_32 -> V_76 + V_75 ;
* V_76 += V_67 ;
F_95 ( ( long ) ( * V_76 ) < 0 ) ;
}
bool F_96 ( const struct V_6 * V_124 ,
struct V_6 * V_13 )
{
if ( V_124 == V_13 )
return true ;
if ( ! V_124 -> V_107 || ! V_13 )
return false ;
return F_97 ( & V_13 -> V_9 , & V_124 -> V_9 ) ;
}
static bool F_98 ( const struct V_6 * V_124 ,
struct V_6 * V_13 )
{
bool V_78 ;
F_10 () ;
V_78 = F_96 ( V_124 , V_13 ) ;
F_13 () ;
return V_78 ;
}
int F_99 ( struct V_97 * V_125 , const struct V_6 * V_13 )
{
int V_78 ;
struct V_6 * V_126 = NULL ;
struct V_97 * V_36 ;
V_36 = F_100 ( V_125 ) ;
if ( V_36 ) {
V_126 = F_76 ( V_36 -> V_99 ) ;
F_101 ( V_36 ) ;
} else {
F_102 ( V_125 ) ;
V_126 = F_11 ( V_125 ) ;
if ( V_126 )
F_103 ( & V_126 -> V_9 ) ;
F_101 ( V_125 ) ;
}
if ( ! V_126 )
return 0 ;
V_78 = F_98 ( V_13 , V_126 ) ;
F_81 ( & V_126 -> V_9 ) ;
return V_78 ;
}
int F_104 ( struct V_73 * V_73 )
{
unsigned long V_127 ;
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_130 ;
V_128 = F_60 ( V_73 , V_131 ) ;
V_129 = F_60 ( V_73 , V_132 ) ;
V_130 = ( V_128 + V_129 ) >> ( 30 - V_133 ) ;
if ( V_130 )
V_127 = F_105 ( 10 * V_130 ) ;
else
V_127 = 1 ;
return V_128 * V_127 < V_129 ;
}
int F_106 ( struct V_73 * V_73 )
{
unsigned long V_129 ;
unsigned long V_128 ;
V_128 = F_60 ( V_73 , V_134 ) ;
V_129 = F_60 ( V_73 , V_135 ) ;
return ( V_129 > V_128 ) ;
}
static unsigned long F_107 ( struct V_6 * V_13 )
{
unsigned long long V_136 ;
V_136 = F_108 ( & V_13 -> V_47 ) ;
if ( V_137 )
V_136 = F_109 ( V_136 , F_108 ( & V_13 -> V_138 ) ) ;
return V_136 >> V_133 ;
}
int F_110 ( struct V_6 * V_13 )
{
struct V_94 * V_139 = V_13 -> V_9 . V_94 ;
if ( V_139 -> V_38 == NULL )
return V_140 ;
return V_13 -> V_141 ;
}
static void F_111 ( struct V_6 * V_13 )
{
F_73 ( & V_142 ) ;
F_73 ( & V_13 -> V_143 ) ;
F_112 () ;
}
static void F_113 ( struct V_6 * V_13 )
{
if ( V_13 ) {
F_114 ( & V_142 ) ;
F_114 ( & V_13 -> V_143 ) ;
}
}
static bool F_115 ( struct V_6 * V_13 )
{
F_95 ( ! F_116 () ) ;
return F_117 ( & V_13 -> V_143 ) > 0 ;
}
static bool F_118 ( struct V_6 * V_13 )
{
struct V_6 * V_144 ;
struct V_6 * V_3 ;
bool V_78 = false ;
F_35 ( & V_2 . V_45 ) ;
V_144 = V_2 . V_144 ;
V_3 = V_2 . V_3 ;
if ( ! V_144 )
goto V_145;
V_78 = F_98 ( V_13 , V_144 )
|| F_98 ( V_13 , V_3 ) ;
V_145:
F_36 ( & V_2 . V_45 ) ;
return V_78 ;
}
static bool F_119 ( struct V_6 * V_13 )
{
if ( V_2 . V_146 && V_18 != V_2 . V_146 ) {
if ( F_118 ( V_13 ) ) {
F_120 ( V_147 ) ;
F_121 ( & V_2 . V_148 , & V_147 , V_149 ) ;
if ( V_2 . V_146 )
F_122 () ;
F_123 ( & V_2 . V_148 , & V_147 ) ;
return true ;
}
}
return false ;
}
static void F_124 ( struct V_6 * V_13 ,
unsigned long * V_150 )
{
F_125 ( & V_13 -> V_151 , * V_150 ) ;
}
static void F_126 ( struct V_6 * V_13 ,
unsigned long * V_150 )
{
F_127 ( & V_13 -> V_151 , * V_150 ) ;
}
void F_128 ( struct V_6 * V_13 , struct V_97 * V_36 )
{
struct V_94 * V_152 ;
struct V_94 * V_153 ;
static char V_154 [ V_155 ] ;
int V_78 ;
if ( ! V_13 || ! V_36 )
return;
F_10 () ;
V_153 = V_13 -> V_9 . V_94 ;
V_152 = F_129 ( V_36 , V_96 ) ;
V_78 = F_130 ( V_152 , V_154 , V_155 ) ;
if ( V_78 < 0 ) {
F_13 () ;
goto V_53;
}
F_13 () ;
F_131 ( V_156 L_1 , V_154 ) ;
F_10 () ;
V_78 = F_130 ( V_153 , V_154 , V_155 ) ;
if ( V_78 < 0 ) {
F_13 () ;
goto V_53;
}
F_13 () ;
F_131 ( V_157 L_2 , V_154 ) ;
V_53:
F_131 ( V_156 L_3 ,
F_132 ( & V_13 -> V_47 , V_158 ) >> 10 ,
F_132 ( & V_13 -> V_47 , V_159 ) >> 10 ,
F_132 ( & V_13 -> V_47 , V_160 ) ) ;
F_131 ( V_156 L_4
L_5 ,
F_132 ( & V_13 -> V_138 , V_158 ) >> 10 ,
F_132 ( & V_13 -> V_138 , V_159 ) >> 10 ,
F_132 ( & V_13 -> V_138 , V_160 ) ) ;
}
static int F_133 ( struct V_6 * V_13 )
{
int V_161 = 0 ;
struct V_6 * V_110 ;
F_134 (iter, memcg)
V_161 ++ ;
return V_161 ;
}
static T_1 F_135 ( struct V_6 * V_13 )
{
T_1 V_162 ;
T_1 V_138 ;
V_162 = F_132 ( & V_13 -> V_47 , V_159 ) ;
V_162 += V_163 << V_133 ;
V_138 = F_132 ( & V_13 -> V_138 , V_159 ) ;
return F_109 ( V_162 , V_138 ) ;
}
void F_136 ( struct V_6 * V_13 , T_3 V_164 ,
int V_165 )
{
struct V_6 * V_110 ;
unsigned long V_166 = 0 ;
unsigned long V_167 ;
unsigned int V_168 = 0 ;
struct V_97 * V_169 = NULL ;
if ( F_137 ( V_18 ) ) {
F_138 ( V_170 ) ;
return;
}
F_139 ( V_171 , V_164 , V_165 , NULL ) ;
V_167 = F_135 ( V_13 ) >> V_133 ? : 1 ;
F_134 (iter, memcg) {
struct V_94 * V_94 = V_110 -> V_9 . V_94 ;
struct V_172 V_173 ;
struct V_97 * V_125 ;
F_140 ( V_94 , & V_173 ) ;
while ( ( V_125 = F_141 ( V_94 , & V_173 ) ) ) {
switch ( F_142 ( V_125 , V_167 , NULL ,
false ) ) {
case V_174 :
if ( V_169 )
F_143 ( V_169 ) ;
V_169 = V_125 ;
V_166 = V_175 ;
F_144 ( V_169 ) ;
case V_176 :
continue;
case V_177 :
F_145 ( V_94 , & V_173 ) ;
F_85 ( V_13 , V_110 ) ;
if ( V_169 )
F_143 ( V_169 ) ;
return;
case V_178 :
break;
} ;
V_168 = F_146 ( V_125 , V_13 , NULL , V_167 ) ;
if ( V_168 > V_166 ) {
if ( V_169 )
F_143 ( V_169 ) ;
V_169 = V_125 ;
V_166 = V_168 ;
F_144 ( V_169 ) ;
}
}
F_145 ( V_94 , & V_173 ) ;
}
if ( ! V_169 )
return;
V_168 = V_166 * 1000 / V_167 ;
F_147 ( V_169 , V_164 , V_165 , V_168 , V_167 , V_13 ,
NULL , L_6 ) ;
}
static unsigned long F_148 ( struct V_6 * V_13 ,
T_3 V_164 ,
unsigned long V_150 )
{
unsigned long V_79 = 0 ;
bool V_179 = false ;
int V_180 ;
if ( V_150 & V_181 )
V_179 = true ;
if ( ! ( V_150 & V_182 ) && V_13 -> V_183 )
V_179 = true ;
for ( V_180 = 0 ; V_180 < V_184 ; V_180 ++ ) {
if ( V_180 )
F_149 ( V_13 ) ;
V_79 += F_150 ( V_13 , V_164 , V_179 ) ;
if ( V_79 && ( V_150 & V_182 ) )
break;
if ( F_107 ( V_13 ) )
break;
if ( V_180 && ! V_79 )
break;
}
return V_79 ;
}
static bool F_151 ( struct V_6 * V_13 ,
int V_22 , bool V_179 )
{
if ( F_64 ( V_13 , V_22 , V_185 ) )
return true ;
if ( V_179 || ! V_163 )
return false ;
if ( F_64 ( V_13 , V_22 , V_186 ) )
return true ;
return false ;
}
static void F_152 ( struct V_6 * V_13 )
{
int V_22 ;
if ( ! F_117 ( & V_13 -> V_93 ) )
return;
if ( F_153 ( & V_13 -> V_187 ) > 1 )
return;
V_13 -> V_188 = V_189 [ V_190 ] ;
F_154 (nid, node_states[N_HIGH_MEMORY]) {
if ( ! F_151 ( V_13 , V_22 , false ) )
F_155 ( V_22 , V_13 -> V_188 ) ;
}
F_156 ( & V_13 -> V_93 , 0 ) ;
F_156 ( & V_13 -> V_187 , 0 ) ;
}
int F_157 ( struct V_6 * V_13 )
{
int V_48 ;
F_152 ( V_13 ) ;
V_48 = V_13 -> V_191 ;
V_48 = F_158 ( V_48 , V_13 -> V_188 ) ;
if ( V_48 == V_92 )
V_48 = F_159 ( V_13 -> V_188 ) ;
if ( F_71 ( V_48 == V_92 ) )
V_48 = F_160 () ;
V_13 -> V_191 = V_48 ;
return V_48 ;
}
static bool F_161 ( struct V_6 * V_13 , bool V_179 )
{
int V_22 ;
if ( ! F_162 ( V_13 -> V_188 ) ) {
for ( V_22 = F_159 ( V_13 -> V_188 ) ;
V_22 < V_92 ;
V_22 = F_158 ( V_22 , V_13 -> V_188 ) ) {
if ( F_151 ( V_13 , V_22 , V_179 ) )
return true ;
}
}
F_66 (nid, N_HIGH_MEMORY) {
if ( F_163 ( V_22 , V_13 -> V_188 ) )
continue;
if ( F_151 ( V_13 , V_22 , V_179 ) )
return true ;
}
return false ;
}
int F_157 ( struct V_6 * V_13 )
{
return 0 ;
}
static bool F_161 ( struct V_6 * V_13 , bool V_179 )
{
return F_151 ( V_13 , 0 , V_179 ) ;
}
static int F_164 ( struct V_6 * V_124 ,
struct V_49 * V_49 ,
T_3 V_164 ,
unsigned long * V_192 )
{
struct V_6 * V_193 = NULL ;
int V_79 = 0 ;
int V_180 = 0 ;
unsigned long V_46 ;
unsigned long V_194 ;
struct V_103 V_104 = {
. V_49 = V_49 ,
. V_112 = 0 ,
} ;
V_46 = F_39 ( & V_124 -> V_47 ) >> V_133 ;
while ( 1 ) {
V_193 = F_78 ( V_124 , V_193 , & V_104 ) ;
if ( ! V_193 ) {
V_180 ++ ;
if ( V_180 >= 2 ) {
if ( ! V_79 )
break;
if ( V_79 >= ( V_46 >> 2 ) ||
( V_180 > V_184 ) )
break;
}
continue;
}
if ( ! F_161 ( V_193 , false ) )
continue;
V_79 += F_165 ( V_193 , V_164 , false ,
V_49 , & V_194 ) ;
* V_192 += V_194 ;
if ( ! F_39 ( & V_124 -> V_47 ) )
break;
}
F_85 ( V_124 , V_193 ) ;
return V_79 ;
}
static bool F_166 ( struct V_6 * V_13 )
{
struct V_6 * V_110 , * V_195 = NULL ;
F_134 (iter, memcg) {
if ( V_110 -> V_196 ) {
V_195 = V_110 ;
F_85 ( V_13 , V_110 ) ;
break;
} else
V_110 -> V_196 = true ;
}
if ( ! V_195 )
return true ;
F_134 (iter, memcg) {
if ( V_110 == V_195 ) {
F_85 ( V_13 , V_110 ) ;
break;
}
V_110 -> V_196 = false ;
}
return false ;
}
static int F_167 ( struct V_6 * V_13 )
{
struct V_6 * V_110 ;
F_134 (iter, memcg)
V_110 -> V_196 = false ;
return 0 ;
}
static void F_168 ( struct V_6 * V_13 )
{
struct V_6 * V_110 ;
F_134 (iter, memcg)
F_73 ( & V_110 -> V_197 ) ;
}
static void F_169 ( struct V_6 * V_13 )
{
struct V_6 * V_110 ;
F_134 (iter, memcg)
F_170 ( & V_110 -> V_197 , - 1 , 0 ) ;
}
static int F_171 ( T_4 * V_147 ,
unsigned V_198 , int V_199 , void * V_200 )
{
struct V_6 * V_201 = (struct V_6 * ) V_200 ;
struct V_6 * V_202 ;
struct V_203 * V_203 ;
V_203 = F_5 ( V_147 , struct V_203 , V_147 ) ;
V_202 = V_203 -> V_13 ;
if ( ! F_98 ( V_202 , V_201 )
&& ! F_98 ( V_201 , V_202 ) )
return 0 ;
return F_172 ( V_147 , V_198 , V_199 , V_200 ) ;
}
static void F_173 ( struct V_6 * V_13 )
{
F_174 ( & V_204 , V_205 , 0 , V_13 ) ;
}
static void F_175 ( struct V_6 * V_13 )
{
if ( V_13 && F_117 ( & V_13 -> V_197 ) )
F_173 ( V_13 ) ;
}
static bool F_176 ( struct V_6 * V_13 , T_3 V_206 ,
int V_165 )
{
struct V_203 V_207 ;
bool V_208 , V_209 ;
V_207 . V_13 = V_13 ;
V_207 . V_147 . V_150 = 0 ;
V_207 . V_147 . V_210 = F_171 ;
V_207 . V_147 . V_211 = V_18 ;
F_177 ( & V_207 . V_147 . V_212 ) ;
V_209 = true ;
F_168 ( V_13 ) ;
F_35 ( & V_213 ) ;
V_208 = F_166 ( V_13 ) ;
F_121 ( & V_204 , & V_207 . V_147 , V_214 ) ;
if ( ! V_208 || V_13 -> V_215 )
V_209 = false ;
if ( V_208 )
F_178 ( V_13 ) ;
F_36 ( & V_213 ) ;
if ( V_209 ) {
F_123 ( & V_204 , & V_207 . V_147 ) ;
F_136 ( V_13 , V_206 , V_165 ) ;
} else {
F_122 () ;
F_123 ( & V_204 , & V_207 . V_147 ) ;
}
F_35 ( & V_213 ) ;
if ( V_208 )
F_167 ( V_13 ) ;
F_173 ( V_13 ) ;
F_36 ( & V_213 ) ;
F_169 ( V_13 ) ;
if ( F_179 ( V_170 ) || F_137 ( V_18 ) )
return false ;
F_180 ( 1 ) ;
return true ;
}
void F_181 ( struct V_27 * V_27 ,
bool * V_208 , unsigned long * V_150 )
{
struct V_6 * V_13 ;
struct V_122 * V_123 ;
V_123 = F_91 ( V_27 ) ;
V_216:
V_13 = V_123 -> V_6 ;
if ( F_71 ( ! V_13 || ! F_93 ( V_123 ) ) )
return;
if ( ! F_115 ( V_13 ) )
return;
F_124 ( V_13 , V_150 ) ;
if ( V_13 != V_123 -> V_6 || ! F_93 ( V_123 ) ) {
F_126 ( V_13 , V_150 ) ;
goto V_216;
}
* V_208 = true ;
}
void F_182 ( struct V_27 * V_27 , unsigned long * V_150 )
{
struct V_122 * V_123 = F_91 ( V_27 ) ;
F_126 ( V_123 -> V_6 , V_150 ) ;
}
void F_183 ( struct V_27 * V_27 ,
enum V_217 V_55 , int V_56 )
{
struct V_6 * V_13 ;
struct V_122 * V_123 = F_91 ( V_27 ) ;
unsigned long V_109 ( V_150 ) ;
if ( F_79 () )
return;
V_13 = V_123 -> V_6 ;
if ( F_71 ( ! V_13 || ! F_93 ( V_123 ) ) )
return;
switch ( V_55 ) {
case V_218 :
V_55 = V_219 ;
break;
default:
F_88 () ;
}
F_53 ( V_13 -> V_58 -> V_59 [ V_55 ] , V_56 ) ;
}
static bool F_184 ( struct V_6 * V_13 )
{
struct V_220 * V_221 ;
bool V_78 = true ;
V_221 = & F_185 ( V_222 ) ;
if ( V_13 == V_221 -> V_223 && V_221 -> V_67 )
V_221 -> V_67 -- ;
else
V_78 = false ;
F_186 ( V_222 ) ;
return V_78 ;
}
static void F_187 ( struct V_220 * V_221 )
{
struct V_6 * V_224 = V_221 -> V_223 ;
if ( V_221 -> V_67 ) {
unsigned long V_225 = V_221 -> V_67 * V_226 ;
F_188 ( & V_224 -> V_47 , V_225 ) ;
if ( V_137 )
F_188 ( & V_224 -> V_138 , V_225 ) ;
V_221 -> V_67 = 0 ;
}
V_221 -> V_223 = NULL ;
}
static void F_189 ( struct V_227 * V_228 )
{
struct V_220 * V_221 = & F_190 ( V_222 ) ;
F_187 ( V_221 ) ;
F_191 ( V_229 , & V_221 -> V_150 ) ;
}
static void F_192 ( struct V_6 * V_13 , unsigned int V_67 )
{
struct V_220 * V_221 = & F_185 ( V_222 ) ;
if ( V_221 -> V_223 != V_13 ) {
F_187 ( V_221 ) ;
V_221 -> V_223 = V_13 ;
}
V_221 -> V_67 += V_67 ;
F_186 ( V_222 ) ;
}
static void F_193 ( struct V_6 * V_124 , bool V_199 )
{
int V_57 , V_230 ;
F_47 () ;
V_230 = F_194 () ;
F_48 (cpu) {
struct V_220 * V_221 = & F_49 ( V_222 , V_57 ) ;
struct V_6 * V_13 ;
V_13 = V_221 -> V_223 ;
if ( ! V_13 || ! V_221 -> V_67 )
continue;
if ( ! F_98 ( V_124 , V_13 ) )
continue;
if ( ! F_195 ( V_229 , & V_221 -> V_150 ) ) {
if ( V_57 == V_230 )
F_189 ( & V_221 -> V_231 ) ;
else
F_196 ( V_57 , & V_221 -> V_231 ) ;
}
}
F_197 () ;
if ( ! V_199 )
goto V_117;
F_48 (cpu) {
struct V_220 * V_221 = & F_49 ( V_222 , V_57 ) ;
if ( F_2 ( V_229 , & V_221 -> V_150 ) )
F_198 ( & V_221 -> V_231 ) ;
}
V_117:
F_51 () ;
}
static void F_149 ( struct V_6 * V_124 )
{
if ( ! F_199 ( & V_232 ) )
return;
F_193 ( V_124 , false ) ;
F_200 ( & V_232 ) ;
}
static void F_201 ( struct V_6 * V_124 )
{
F_202 ( & V_232 ) ;
F_193 ( V_124 , true ) ;
F_200 ( & V_232 ) ;
}
static void F_203 ( struct V_6 * V_13 , int V_57 )
{
int V_233 ;
F_35 ( & V_13 -> V_60 ) ;
for ( V_233 = 0 ; V_233 < V_234 ; V_233 ++ ) {
long V_235 = F_49 ( V_13 -> V_58 -> V_59 [ V_233 ] , V_57 ) ;
F_49 ( V_13 -> V_58 -> V_59 [ V_233 ] , V_57 ) = 0 ;
V_13 -> V_61 . V_59 [ V_233 ] += V_235 ;
}
for ( V_233 = 0 ; V_233 < V_236 ; V_233 ++ ) {
unsigned long V_235 = F_49 ( V_13 -> V_58 -> V_65 [ V_233 ] , V_57 ) ;
F_49 ( V_13 -> V_58 -> V_65 [ V_233 ] , V_57 ) = 0 ;
V_13 -> V_61 . V_65 [ V_233 ] += V_235 ;
}
F_36 ( & V_13 -> V_60 ) ;
}
static int T_5 F_204 ( struct V_237 * V_238 ,
unsigned long V_239 ,
void * V_240 )
{
int V_57 = ( unsigned long ) V_240 ;
struct V_220 * V_221 ;
struct V_6 * V_110 ;
if ( V_239 == V_241 )
return V_242 ;
if ( V_239 != V_243 && V_239 != V_244 )
return V_242 ;
F_205 (iter)
F_203 ( V_110 , V_57 ) ;
V_221 = & F_49 ( V_222 , V_57 ) ;
F_187 ( V_221 ) ;
return V_242 ;
}
static int F_206 ( struct V_6 * V_13 , T_3 V_164 ,
unsigned int V_67 , bool V_245 )
{
unsigned long V_246 = V_67 * V_226 ;
struct V_6 * V_247 ;
struct V_248 * V_249 ;
unsigned long V_150 = 0 ;
int V_78 ;
V_78 = F_207 ( & V_13 -> V_47 , V_246 , & V_249 ) ;
if ( F_208 ( ! V_78 ) ) {
if ( ! V_137 )
return V_250 ;
V_78 = F_207 ( & V_13 -> V_138 , V_246 , & V_249 ) ;
if ( F_208 ( ! V_78 ) )
return V_250 ;
F_188 ( & V_13 -> V_47 , V_246 ) ;
V_247 = F_209 ( V_249 , V_138 ) ;
V_150 |= V_181 ;
} else
V_247 = F_209 ( V_249 , V_47 ) ;
if ( V_67 == V_251 )
return V_252 ;
if ( ! ( V_164 & V_253 ) )
return V_254 ;
V_78 = F_148 ( V_247 , V_164 , V_150 ) ;
if ( F_107 ( V_247 ) >= V_67 )
return V_252 ;
if ( V_67 == 1 && V_78 )
return V_252 ;
if ( F_119 ( V_247 ) )
return V_252 ;
if ( ! V_245 )
return V_255 ;
if ( ! F_176 ( V_247 , V_164 , F_210 ( V_246 ) ) )
return V_256 ;
return V_252 ;
}
static int F_211 ( struct V_98 * V_99 ,
T_3 V_164 ,
unsigned int V_67 ,
struct V_6 * * V_257 ,
bool V_258 )
{
unsigned int V_259 = F_212 ( V_251 , V_67 ) ;
int V_260 = V_261 ;
struct V_6 * V_13 = NULL ;
int V_78 ;
if ( F_71 ( F_179 ( V_170 )
|| F_137 ( V_18 ) ) )
goto V_262;
if ( ! * V_257 && ! V_99 )
* V_257 = V_106 ;
V_216:
if ( * V_257 ) {
V_13 = * V_257 ;
F_95 ( F_213 ( & V_13 -> V_9 ) ) ;
if ( F_8 ( V_13 ) )
goto V_53;
if ( V_67 == 1 && F_184 ( V_13 ) )
goto V_53;
F_103 ( & V_13 -> V_9 ) ;
} else {
struct V_97 * V_36 ;
F_10 () ;
V_36 = F_77 ( V_99 -> V_100 ) ;
V_13 = F_11 ( V_36 ) ;
if ( ! V_13 )
V_13 = V_106 ;
if ( F_8 ( V_13 ) ) {
F_13 () ;
goto V_53;
}
if ( V_67 == 1 && F_184 ( V_13 ) ) {
F_13 () ;
goto V_53;
}
if ( ! F_44 ( & V_13 -> V_9 ) ) {
F_13 () ;
goto V_216;
}
F_13 () ;
}
do {
bool V_245 ;
if ( F_137 ( V_18 ) ) {
F_81 ( & V_13 -> V_9 ) ;
goto V_262;
}
V_245 = false ;
if ( V_258 && ! V_260 ) {
V_245 = true ;
V_260 = V_261 ;
}
V_78 = F_206 ( V_13 , V_164 , V_259 , V_245 ) ;
switch ( V_78 ) {
case V_250 :
break;
case V_252 :
V_259 = V_67 ;
F_81 ( & V_13 -> V_9 ) ;
V_13 = NULL ;
goto V_216;
case V_254 :
F_81 ( & V_13 -> V_9 ) ;
goto V_263;
case V_255 :
if ( ! V_258 ) {
F_81 ( & V_13 -> V_9 ) ;
goto V_263;
}
V_260 -- ;
break;
case V_256 :
F_81 ( & V_13 -> V_9 ) ;
goto V_262;
}
} while ( V_78 != V_250 );
if ( V_259 > V_67 )
F_192 ( V_13 , V_259 - V_67 ) ;
F_81 ( & V_13 -> V_9 ) ;
V_53:
* V_257 = V_13 ;
return 0 ;
V_263:
* V_257 = NULL ;
return - V_264 ;
V_262:
* V_257 = V_106 ;
return - V_265 ;
}
static void F_214 ( struct V_6 * V_13 ,
unsigned int V_67 )
{
if ( ! F_8 ( V_13 ) ) {
unsigned long V_225 = V_67 * V_226 ;
F_188 ( & V_13 -> V_47 , V_225 ) ;
if ( V_137 )
F_188 ( & V_13 -> V_138 , V_225 ) ;
}
}
static void F_215 ( struct V_6 * V_13 ,
unsigned int V_67 )
{
unsigned long V_225 = V_67 * V_226 ;
if ( F_8 ( V_13 ) )
return;
F_216 ( & V_13 -> V_47 , V_13 -> V_47 . V_38 , V_225 ) ;
if ( V_137 )
F_216 ( & V_13 -> V_138 ,
V_13 -> V_138 . V_38 , V_225 ) ;
}
static struct V_6 * F_217 ( unsigned short V_105 )
{
struct V_7 * V_9 ;
if ( ! V_105 )
return NULL ;
V_9 = F_218 ( & V_115 , V_105 ) ;
if ( ! V_9 )
return NULL ;
return F_4 ( V_9 ) ;
}
struct V_6 * F_219 ( struct V_27 * V_27 )
{
struct V_6 * V_13 = NULL ;
struct V_122 * V_123 ;
unsigned short V_105 ;
T_6 V_266 ;
F_95 ( ! F_220 ( V_27 ) ) ;
V_123 = F_91 ( V_27 ) ;
F_221 ( V_123 ) ;
if ( F_93 ( V_123 ) ) {
V_13 = V_123 -> V_6 ;
if ( V_13 && ! F_44 ( & V_13 -> V_9 ) )
V_13 = NULL ;
} else if ( F_222 ( V_27 ) ) {
V_266 . V_56 = F_223 ( V_27 ) ;
V_105 = F_224 ( V_266 ) ;
F_10 () ;
V_13 = F_217 ( V_105 ) ;
if ( V_13 && ! F_44 ( & V_13 -> V_9 ) )
V_13 = NULL ;
F_13 () ;
}
F_225 ( V_123 ) ;
return V_13 ;
}
static void F_226 ( struct V_6 * V_13 ,
struct V_27 * V_27 ,
unsigned int V_67 ,
enum V_267 V_268 ,
bool V_269 )
{
struct V_122 * V_123 = F_91 ( V_27 ) ;
struct V_49 * V_109 ( V_49 ) ;
struct V_73 * V_73 ;
bool V_270 = false ;
bool V_66 ;
F_221 ( V_123 ) ;
F_95 ( F_93 ( V_123 ) ) ;
if ( V_269 ) {
V_49 = F_227 ( V_27 ) ;
F_228 ( & V_49 -> V_271 ) ;
if ( F_92 ( V_27 ) ) {
V_73 = F_89 ( V_49 , V_123 -> V_6 ) ;
F_229 ( V_27 ) ;
F_230 ( V_27 , V_73 , F_231 ( V_27 ) ) ;
V_270 = true ;
}
}
V_123 -> V_6 = V_13 ;
F_232 () ;
F_233 ( V_123 ) ;
if ( V_269 ) {
if ( V_270 ) {
V_73 = F_89 ( V_49 , V_123 -> V_6 ) ;
F_95 ( F_92 ( V_27 ) ) ;
F_234 ( V_27 ) ;
F_235 ( V_27 , V_73 , F_231 ( V_27 ) ) ;
}
F_236 ( & V_49 -> V_271 ) ;
}
if ( V_268 == V_272 )
V_66 = true ;
else
V_66 = false ;
F_55 ( V_13 , V_66 , V_67 ) ;
F_225 ( V_123 ) ;
F_70 ( V_13 , V_27 ) ;
}
void F_237 ( struct V_27 * V_273 )
{
struct V_122 * V_274 = F_91 ( V_273 ) ;
struct V_122 * V_123 ;
int V_233 ;
if ( F_79 () )
return;
for ( V_233 = 1 ; V_233 < V_275 ; V_233 ++ ) {
V_123 = V_274 + V_233 ;
V_123 -> V_6 = V_274 -> V_6 ;
F_232 () ;
V_123 -> V_150 = V_274 -> V_150 & ~ V_276 ;
}
}
static int F_238 ( struct V_27 * V_27 ,
unsigned int V_67 ,
struct V_122 * V_123 ,
struct V_6 * V_144 ,
struct V_6 * V_3 )
{
unsigned long V_150 ;
int V_78 ;
bool V_66 = F_239 ( V_27 ) ;
F_95 ( V_144 == V_3 ) ;
F_95 ( F_92 ( V_27 ) ) ;
V_78 = - V_277 ;
if ( V_67 > 1 && ! F_240 ( V_27 ) )
goto V_117;
F_221 ( V_123 ) ;
V_78 = - V_278 ;
if ( ! F_93 ( V_123 ) || V_123 -> V_6 != V_144 )
goto V_145;
F_124 ( V_144 , & V_150 ) ;
if ( ! V_66 && F_241 ( V_27 ) ) {
F_56 () ;
F_242 ( V_144 -> V_58 -> V_59 [ V_219 ] ) ;
F_58 ( V_3 -> V_58 -> V_59 [ V_219 ] ) ;
F_59 () ;
}
F_55 ( V_144 , V_66 , - V_67 ) ;
V_123 -> V_6 = V_3 ;
F_55 ( V_3 , V_66 , V_67 ) ;
F_126 ( V_144 , & V_150 ) ;
V_78 = 0 ;
V_145:
F_225 ( V_123 ) ;
F_70 ( V_3 , V_27 ) ;
F_70 ( V_144 , V_27 ) ;
V_117:
return V_78 ;
}
static int F_243 ( struct V_27 * V_27 ,
struct V_122 * V_123 ,
struct V_6 * V_279 )
{
struct V_6 * V_38 ;
unsigned int V_67 ;
unsigned long V_109 ( V_150 ) ;
int V_78 ;
if ( F_8 ( V_279 ) )
return - V_278 ;
V_78 = - V_277 ;
if ( ! F_244 ( V_27 ) )
goto V_117;
if ( F_245 ( V_27 ) )
goto V_280;
V_67 = F_246 ( V_27 ) ;
V_38 = F_38 ( V_279 ) ;
if ( ! V_38 )
V_38 = V_106 ;
if ( V_67 > 1 )
V_150 = F_247 ( V_27 ) ;
V_78 = F_238 ( V_27 , V_67 ,
V_123 , V_279 , V_38 ) ;
if ( ! V_78 )
F_215 ( V_279 , V_67 ) ;
if ( V_67 > 1 )
F_248 ( V_27 , V_150 ) ;
F_249 ( V_27 ) ;
V_280:
F_250 ( V_27 ) ;
V_117:
return V_78 ;
}
static int F_251 ( struct V_27 * V_27 , struct V_98 * V_99 ,
T_3 V_164 , enum V_267 V_268 )
{
struct V_6 * V_13 = NULL ;
unsigned int V_67 = 1 ;
bool V_258 = true ;
int V_78 ;
if ( F_240 ( V_27 ) ) {
V_67 <<= F_252 ( V_27 ) ;
F_95 ( ! F_240 ( V_27 ) ) ;
V_258 = false ;
}
V_78 = F_211 ( V_99 , V_164 , V_67 , & V_13 , V_258 ) ;
if ( V_78 == - V_264 )
return V_78 ;
F_226 ( V_13 , V_27 , V_67 , V_268 , false ) ;
return 0 ;
}
int F_253 ( struct V_27 * V_27 ,
struct V_98 * V_99 , T_3 V_164 )
{
if ( F_79 () )
return 0 ;
F_95 ( F_241 ( V_27 ) ) ;
F_95 ( V_27 -> V_281 && ! F_239 ( V_27 ) ) ;
F_95 ( ! V_99 ) ;
return F_251 ( V_27 , V_99 , V_164 ,
V_272 ) ;
}
static int F_254 ( struct V_98 * V_99 ,
struct V_27 * V_27 ,
T_3 V_206 ,
struct V_6 * * V_282 )
{
struct V_6 * V_13 ;
struct V_122 * V_123 ;
int V_78 ;
V_123 = F_91 ( V_27 ) ;
if ( F_93 ( V_123 ) )
return 0 ;
if ( ! V_137 )
goto V_283;
V_13 = F_219 ( V_27 ) ;
if ( ! V_13 )
goto V_283;
* V_282 = V_13 ;
V_78 = F_211 ( NULL , V_206 , 1 , V_282 , true ) ;
F_81 ( & V_13 -> V_9 ) ;
if ( V_78 == - V_265 )
V_78 = 0 ;
return V_78 ;
V_283:
V_78 = F_211 ( V_99 , V_206 , 1 , V_282 , true ) ;
if ( V_78 == - V_265 )
V_78 = 0 ;
return V_78 ;
}
int F_255 ( struct V_98 * V_99 , struct V_27 * V_27 ,
T_3 V_164 , struct V_6 * * V_282 )
{
* V_282 = NULL ;
if ( F_79 () )
return 0 ;
if ( ! F_222 ( V_27 ) ) {
int V_78 ;
V_78 = F_211 ( V_99 , V_164 , 1 , V_282 , true ) ;
if ( V_78 == - V_265 )
V_78 = 0 ;
return V_78 ;
}
return F_254 ( V_99 , V_27 , V_164 , V_282 ) ;
}
void F_256 ( struct V_6 * V_13 )
{
if ( F_79 () )
return;
if ( ! V_13 )
return;
F_214 ( V_13 , 1 ) ;
}
static void
F_257 ( struct V_27 * V_27 , struct V_6 * V_13 ,
enum V_267 V_268 )
{
if ( F_79 () )
return;
if ( ! V_13 )
return;
F_258 ( & V_13 -> V_9 ) ;
F_226 ( V_13 , V_27 , 1 , V_268 , true ) ;
if ( V_137 && F_222 ( V_27 ) ) {
T_6 V_266 = { . V_56 = F_223 (page) } ;
F_259 ( V_266 ) ;
}
F_260 ( & V_13 -> V_9 ) ;
}
void F_261 ( struct V_27 * V_27 ,
struct V_6 * V_13 )
{
F_257 ( V_27 , V_13 ,
V_272 ) ;
}
int F_262 ( struct V_27 * V_27 , struct V_98 * V_99 ,
T_3 V_164 )
{
struct V_6 * V_13 = NULL ;
enum V_267 type = V_284 ;
int V_78 ;
if ( F_79 () )
return 0 ;
if ( F_263 ( V_27 ) )
return 0 ;
if ( ! F_222 ( V_27 ) )
V_78 = F_251 ( V_27 , V_99 , V_164 , type ) ;
else {
V_78 = F_254 ( V_99 , V_27 ,
V_164 , & V_13 ) ;
if ( ! V_78 )
F_257 ( V_27 , V_13 , type ) ;
}
return V_78 ;
}
static void F_264 ( struct V_6 * V_13 ,
unsigned int V_67 ,
const enum V_267 V_268 )
{
struct V_285 * V_259 = NULL ;
bool V_286 = true ;
if ( ! V_137 || V_268 == V_287 )
V_286 = false ;
V_259 = & V_18 -> V_288 ;
if ( ! V_259 -> V_13 )
V_259 -> V_13 = V_13 ;
if ( ! V_259 -> V_289 || F_179 ( V_170 ) )
goto V_290;
if ( V_67 > 1 )
goto V_290;
if ( V_259 -> V_13 != V_13 )
goto V_290;
V_259 -> V_67 ++ ;
if ( V_286 )
V_259 -> V_291 ++ ;
return;
V_290:
F_188 ( & V_13 -> V_47 , V_67 * V_226 ) ;
if ( V_286 )
F_188 ( & V_13 -> V_138 , V_67 * V_226 ) ;
if ( F_71 ( V_259 -> V_13 != V_13 ) )
F_175 ( V_13 ) ;
}
static struct V_6 *
F_265 ( struct V_27 * V_27 , enum V_267 V_268 ,
bool V_292 )
{
struct V_6 * V_13 = NULL ;
unsigned int V_67 = 1 ;
struct V_122 * V_123 ;
bool V_66 ;
if ( F_79 () )
return NULL ;
F_95 ( F_222 ( V_27 ) ) ;
if ( F_240 ( V_27 ) ) {
V_67 <<= F_252 ( V_27 ) ;
F_95 ( ! F_240 ( V_27 ) ) ;
}
V_123 = F_91 ( V_27 ) ;
if ( F_71 ( ! F_93 ( V_123 ) ) )
return NULL ;
F_221 ( V_123 ) ;
V_13 = V_123 -> V_6 ;
if ( ! F_93 ( V_123 ) )
goto V_293;
V_66 = F_239 ( V_27 ) ;
switch ( V_268 ) {
case V_272 :
V_66 = true ;
case V_294 :
if ( F_241 ( V_27 ) )
goto V_293;
if ( ! V_292 && F_266 ( V_123 ) )
goto V_293;
break;
case V_287 :
if ( ! F_239 ( V_27 ) ) {
if ( V_27 -> V_281 && ! F_267 ( V_27 ) )
goto V_293;
} else if ( F_241 ( V_27 ) )
goto V_293;
break;
default:
break;
}
F_55 ( V_13 , V_66 , - V_67 ) ;
F_268 ( V_123 ) ;
F_225 ( V_123 ) ;
F_70 ( V_13 , V_27 ) ;
if ( V_137 && V_268 == V_287 ) {
F_52 ( V_13 , true ) ;
F_9 ( V_13 ) ;
}
if ( ! V_292 && ! F_8 ( V_13 ) )
F_264 ( V_13 , V_67 , V_268 ) ;
return V_13 ;
V_293:
F_225 ( V_123 ) ;
return NULL ;
}
void F_269 ( struct V_27 * V_27 )
{
if ( F_241 ( V_27 ) )
return;
F_95 ( V_27 -> V_281 && ! F_239 ( V_27 ) ) ;
if ( F_222 ( V_27 ) )
return;
F_265 ( V_27 , V_272 , false ) ;
}
void F_270 ( struct V_27 * V_27 )
{
F_95 ( F_241 ( V_27 ) ) ;
F_95 ( V_27 -> V_281 ) ;
F_265 ( V_27 , V_284 , false ) ;
}
void F_271 ( void )
{
V_18 -> V_288 . V_289 ++ ;
if ( V_18 -> V_288 . V_289 == 1 ) {
V_18 -> V_288 . V_13 = NULL ;
V_18 -> V_288 . V_67 = 0 ;
V_18 -> V_288 . V_291 = 0 ;
}
}
void F_272 ( void )
{
struct V_285 * V_259 = & V_18 -> V_288 ;
if ( ! V_259 -> V_289 )
return;
V_259 -> V_289 -- ;
if ( V_259 -> V_289 )
return;
if ( ! V_259 -> V_13 )
return;
if ( V_259 -> V_67 )
F_188 ( & V_259 -> V_13 -> V_47 ,
V_259 -> V_67 * V_226 ) ;
if ( V_259 -> V_291 )
F_188 ( & V_259 -> V_13 -> V_138 ,
V_259 -> V_291 * V_226 ) ;
F_175 ( V_259 -> V_13 ) ;
V_259 -> V_13 = NULL ;
}
void
F_273 ( struct V_27 * V_27 , T_6 V_266 , bool V_295 )
{
struct V_6 * V_13 ;
int V_268 = V_287 ;
if ( ! V_295 )
V_268 = V_294 ;
V_13 = F_265 ( V_27 , V_268 , false ) ;
if ( V_137 && V_295 && V_13 )
F_274 ( V_266 , F_80 ( & V_13 -> V_9 ) ) ;
}
void F_259 ( T_6 V_266 )
{
struct V_6 * V_13 ;
unsigned short V_105 ;
if ( ! V_137 )
return;
V_105 = F_274 ( V_266 , 0 ) ;
F_10 () ;
V_13 = F_217 ( V_105 ) ;
if ( V_13 ) {
if ( ! F_8 ( V_13 ) )
F_188 ( & V_13 -> V_138 , V_226 ) ;
F_52 ( V_13 , false ) ;
F_16 ( V_13 ) ;
}
F_13 () ;
}
static int F_275 ( T_6 V_296 ,
struct V_6 * V_144 , struct V_6 * V_3 )
{
unsigned short V_297 , V_298 ;
V_297 = F_80 ( & V_144 -> V_9 ) ;
V_298 = F_80 ( & V_3 -> V_9 ) ;
if ( F_276 ( V_296 , V_297 , V_298 ) == V_297 ) {
F_52 ( V_144 , false ) ;
F_52 ( V_3 , true ) ;
F_9 ( V_3 ) ;
return 0 ;
}
return - V_278 ;
}
static inline int F_275 ( T_6 V_296 ,
struct V_6 * V_144 , struct V_6 * V_3 )
{
return - V_278 ;
}
void F_277 ( struct V_27 * V_27 , struct V_27 * V_299 ,
struct V_6 * * V_282 )
{
struct V_6 * V_13 = NULL ;
struct V_122 * V_123 ;
enum V_267 V_268 ;
* V_282 = NULL ;
F_95 ( F_240 ( V_27 ) ) ;
if ( F_79 () )
return;
V_123 = F_91 ( V_27 ) ;
F_221 ( V_123 ) ;
if ( F_93 ( V_123 ) ) {
V_13 = V_123 -> V_6 ;
F_103 ( & V_13 -> V_9 ) ;
if ( F_239 ( V_27 ) )
F_278 ( V_123 ) ;
}
F_225 ( V_123 ) ;
if ( ! V_13 )
return;
* V_282 = V_13 ;
if ( F_239 ( V_27 ) )
V_268 = V_272 ;
else
V_268 = V_284 ;
F_226 ( V_13 , V_299 , 1 , V_268 , false ) ;
}
void F_279 ( struct V_6 * V_13 ,
struct V_27 * V_300 , struct V_27 * V_299 , bool V_301 )
{
struct V_27 * V_302 , * V_303 ;
struct V_122 * V_123 ;
bool V_66 ;
if ( ! V_13 )
return;
F_258 ( & V_13 -> V_9 ) ;
if ( ! V_301 ) {
V_302 = V_300 ;
V_303 = V_299 ;
} else {
V_302 = V_299 ;
V_303 = V_300 ;
}
V_66 = F_239 ( V_302 ) ;
F_265 ( V_303 ,
V_66 ? V_272
: V_284 ,
true ) ;
F_81 ( & V_13 -> V_9 ) ;
V_123 = F_91 ( V_300 ) ;
F_221 ( V_123 ) ;
F_280 ( V_123 ) ;
F_225 ( V_123 ) ;
if ( V_66 )
F_269 ( V_302 ) ;
F_260 ( & V_13 -> V_9 ) ;
}
void F_281 ( struct V_27 * V_300 ,
struct V_27 * V_299 )
{
struct V_6 * V_13 = NULL ;
struct V_122 * V_123 ;
enum V_267 type = V_284 ;
if ( F_79 () )
return;
V_123 = F_91 ( V_300 ) ;
F_221 ( V_123 ) ;
if ( F_93 ( V_123 ) ) {
V_13 = V_123 -> V_6 ;
F_55 ( V_13 , false , - 1 ) ;
F_268 ( V_123 ) ;
}
F_225 ( V_123 ) ;
if ( ! V_13 )
return;
F_226 ( V_13 , V_299 , 1 , type , true ) ;
}
static struct V_122 * F_282 ( struct V_27 * V_27 )
{
struct V_122 * V_123 ;
V_123 = F_91 ( V_27 ) ;
if ( F_208 ( V_123 ) && F_93 ( V_123 ) )
return V_123 ;
return NULL ;
}
bool F_283 ( struct V_27 * V_27 )
{
if ( F_79 () )
return false ;
return F_282 ( V_27 ) != NULL ;
}
void F_284 ( struct V_27 * V_27 )
{
struct V_122 * V_123 ;
V_123 = F_282 ( V_27 ) ;
if ( V_123 ) {
F_131 ( V_304 L_7 ,
V_123 , V_123 -> V_150 , V_123 -> V_6 ) ;
}
}
static int F_285 ( struct V_6 * V_13 ,
unsigned long long V_56 )
{
int V_305 ;
T_1 V_306 , V_307 ;
int V_78 = 0 ;
int V_308 = F_133 ( V_13 ) ;
T_1 V_309 , V_310 ;
int V_311 ;
V_305 = V_261 * V_308 ;
V_310 = F_132 ( & V_13 -> V_47 , V_158 ) ;
V_311 = 0 ;
while ( V_305 ) {
if ( F_286 ( V_18 ) ) {
V_78 = - V_265 ;
break;
}
F_202 ( & V_312 ) ;
V_306 = F_132 ( & V_13 -> V_138 , V_159 ) ;
if ( V_306 < V_56 ) {
V_78 = - V_278 ;
F_200 ( & V_312 ) ;
break;
}
V_307 = F_132 ( & V_13 -> V_47 , V_159 ) ;
if ( V_307 < V_56 )
V_311 = 1 ;
V_78 = F_287 ( & V_13 -> V_47 , V_56 ) ;
if ( ! V_78 ) {
if ( V_306 == V_56 )
V_13 -> V_183 = true ;
else
V_13 -> V_183 = false ;
}
F_200 ( & V_312 ) ;
if ( ! V_78 )
break;
F_148 ( V_13 , V_313 ,
V_182 ) ;
V_309 = F_132 ( & V_13 -> V_47 , V_158 ) ;
if ( V_309 >= V_310 )
V_305 -- ;
else
V_310 = V_309 ;
}
if ( ! V_78 && V_311 )
F_175 ( V_13 ) ;
return V_78 ;
}
static int F_288 ( struct V_6 * V_13 ,
unsigned long long V_56 )
{
int V_305 ;
T_1 V_307 , V_306 , V_310 , V_309 ;
int V_308 = F_133 ( V_13 ) ;
int V_78 = - V_277 ;
int V_311 = 0 ;
V_305 = V_308 * V_261 ;
V_310 = F_132 ( & V_13 -> V_138 , V_158 ) ;
while ( V_305 ) {
if ( F_286 ( V_18 ) ) {
V_78 = - V_265 ;
break;
}
F_202 ( & V_312 ) ;
V_307 = F_132 ( & V_13 -> V_47 , V_159 ) ;
if ( V_307 > V_56 ) {
V_78 = - V_278 ;
F_200 ( & V_312 ) ;
break;
}
V_306 = F_132 ( & V_13 -> V_138 , V_159 ) ;
if ( V_306 < V_56 )
V_311 = 1 ;
V_78 = F_287 ( & V_13 -> V_138 , V_56 ) ;
if ( ! V_78 ) {
if ( V_307 == V_56 )
V_13 -> V_183 = true ;
else
V_13 -> V_183 = false ;
}
F_200 ( & V_312 ) ;
if ( ! V_78 )
break;
F_148 ( V_13 , V_313 ,
V_181 |
V_182 ) ;
V_309 = F_132 ( & V_13 -> V_138 , V_158 ) ;
if ( V_309 >= V_310 )
V_305 -- ;
else
V_310 = V_309 ;
}
if ( ! V_78 && V_311 )
F_175 ( V_13 ) ;
return V_78 ;
}
unsigned long F_289 ( struct V_49 * V_49 , int V_165 ,
T_3 V_164 ,
unsigned long * V_192 )
{
unsigned long V_314 = 0 ;
struct V_21 * V_32 , * V_315 = NULL ;
unsigned long V_316 ;
int V_180 = 0 ;
struct V_28 * V_33 ;
unsigned long long V_46 ;
unsigned long V_194 ;
if ( V_165 > 0 )
return 0 ;
V_33 = F_26 ( F_82 ( V_49 ) , F_83 ( V_49 ) ) ;
do {
if ( V_315 )
V_32 = V_315 ;
else
V_32 = F_45 ( V_33 ) ;
if ( ! V_32 )
break;
V_194 = 0 ;
V_316 = F_164 ( V_32 -> V_13 , V_49 ,
V_164 , & V_194 ) ;
V_314 += V_316 ;
* V_192 += V_194 ;
F_35 ( & V_33 -> V_45 ) ;
V_315 = NULL ;
if ( ! V_316 ) {
do {
V_315 =
F_42 ( V_33 ) ;
if ( V_315 == V_32 )
F_81 ( & V_315 -> V_13 -> V_9 ) ;
else
break;
} while ( 1 );
}
F_32 ( V_32 -> V_13 , V_32 , V_33 ) ;
V_46 = F_39 ( & V_32 -> V_13 -> V_47 ) ;
F_28 ( V_32 -> V_13 , V_32 , V_33 , V_46 ) ;
F_36 ( & V_33 -> V_45 ) ;
F_81 ( & V_32 -> V_13 -> V_9 ) ;
V_180 ++ ;
if ( ! V_314 &&
( V_315 == NULL ||
V_180 > V_317 ) )
break;
} while ( ! V_314 );
if ( V_315 )
F_81 ( & V_315 -> V_13 -> V_9 ) ;
return V_314 ;
}
static bool F_290 ( struct V_6 * V_13 ,
int V_48 , int V_23 , enum V_74 V_75 )
{
struct V_21 * V_32 ;
unsigned long V_150 , V_180 ;
struct V_318 * V_319 ;
struct V_27 * V_320 ;
struct V_49 * V_49 ;
V_49 = & F_291 ( V_48 ) -> V_321 [ V_23 ] ;
V_32 = F_21 ( V_13 , V_48 , V_23 ) ;
V_319 = & V_32 -> V_73 . V_322 [ V_75 ] ;
V_180 = V_32 -> V_76 [ V_75 ] ;
V_180 += 256 ;
V_320 = NULL ;
while ( V_180 -- ) {
struct V_122 * V_123 ;
struct V_27 * V_27 ;
F_125 ( & V_49 -> V_271 , V_150 ) ;
if ( F_292 ( V_319 ) ) {
F_127 ( & V_49 -> V_271 , V_150 ) ;
break;
}
V_27 = F_293 ( V_319 -> V_102 , struct V_27 , V_75 ) ;
if ( V_320 == V_27 ) {
F_294 ( & V_27 -> V_75 , V_319 ) ;
V_320 = NULL ;
F_127 ( & V_49 -> V_271 , V_150 ) ;
continue;
}
F_127 ( & V_49 -> V_271 , V_150 ) ;
V_123 = F_91 ( V_27 ) ;
if ( F_243 ( V_27 , V_123 , V_13 ) ) {
V_320 = V_27 ;
F_295 () ;
} else
V_320 = NULL ;
}
return ! F_292 ( V_319 ) ;
}
static int F_296 ( struct V_6 * V_13 , bool V_323 )
{
int V_78 ;
int V_48 , V_23 , V_324 ;
int V_325 = V_261 ;
struct V_94 * V_139 = V_13 -> V_9 . V_94 ;
F_103 ( & V_13 -> V_9 ) ;
V_324 = 0 ;
if ( V_323 )
goto V_326;
V_327:
do {
V_78 = - V_277 ;
if ( F_297 ( V_139 ) || ! F_292 ( & V_139 -> V_308 ) )
goto V_117;
F_298 () ;
F_201 ( V_13 ) ;
V_78 = 0 ;
F_111 ( V_13 ) ;
F_66 (node, N_HIGH_MEMORY) {
for ( V_23 = 0 ; ! V_78 && V_23 < V_50 ; V_23 ++ ) {
enum V_74 V_75 ;
F_62 (lru) {
V_78 = F_290 ( V_13 ,
V_48 , V_23 , V_75 ) ;
if ( V_78 )
break;
}
}
if ( V_78 )
break;
}
F_113 ( V_13 ) ;
F_175 ( V_13 ) ;
F_295 () ;
} while ( F_132 ( & V_13 -> V_47 , V_158 ) > 0 || V_78 );
V_117:
F_81 ( & V_13 -> V_9 ) ;
return V_78 ;
V_326:
if ( F_297 ( V_139 ) || ! F_292 ( & V_139 -> V_308 ) || V_324 ) {
V_78 = - V_277 ;
goto V_117;
}
F_298 () ;
V_324 = 1 ;
while ( V_325 && F_132 ( & V_13 -> V_47 , V_158 ) > 0 ) {
int V_328 ;
if ( F_286 ( V_18 ) ) {
V_78 = - V_265 ;
goto V_117;
}
V_328 = F_150 ( V_13 , V_313 ,
false ) ;
if ( ! V_328 ) {
V_325 -- ;
F_299 ( V_329 , V_330 / 10 ) ;
}
}
F_300 () ;
goto V_327;
}
static int F_301 ( struct V_94 * V_95 , unsigned int V_331 )
{
return F_296 ( F_74 ( V_95 ) , true ) ;
}
static T_1 F_302 ( struct V_94 * V_95 , struct V_332 * V_333 )
{
return F_74 ( V_95 ) -> V_107 ;
}
static int F_303 ( struct V_94 * V_95 , struct V_332 * V_333 ,
T_1 V_56 )
{
int V_334 = 0 ;
struct V_6 * V_13 = F_74 ( V_95 ) ;
struct V_94 * V_38 = V_95 -> V_38 ;
struct V_6 * V_335 = NULL ;
if ( V_38 )
V_335 = F_74 ( V_38 ) ;
F_304 () ;
if ( V_13 -> V_107 == V_56 )
goto V_117;
if ( ( ! V_335 || ! V_335 -> V_107 ) &&
( V_56 == 1 || V_56 == 0 ) ) {
if ( F_292 ( & V_95 -> V_308 ) )
V_13 -> V_107 = V_56 ;
else
V_334 = - V_277 ;
} else
V_334 = - V_278 ;
V_117:
F_305 () ;
return V_334 ;
}
static unsigned long F_306 ( struct V_6 * V_13 ,
enum V_54 V_55 )
{
struct V_6 * V_110 ;
long V_56 = 0 ;
F_134 (iter, memcg)
V_56 += F_46 ( V_110 , V_55 ) ;
if ( V_56 < 0 )
V_56 = 0 ;
return V_56 ;
}
static inline T_1 F_307 ( struct V_6 * V_13 , bool V_336 )
{
T_1 V_56 ;
if ( ! F_8 ( V_13 ) ) {
if ( ! V_336 )
return F_132 ( & V_13 -> V_47 , V_158 ) ;
else
return F_132 ( & V_13 -> V_138 , V_158 ) ;
}
V_56 = F_306 ( V_13 , V_69 ) ;
V_56 += F_306 ( V_13 , V_68 ) ;
if ( V_336 )
V_56 += F_306 ( V_13 , V_63 ) ;
return V_56 << V_133 ;
}
static T_7 F_308 ( struct V_94 * V_95 , struct V_332 * V_333 ,
struct V_337 * V_337 , char T_8 * V_338 ,
T_9 V_339 , T_10 * V_340 )
{
struct V_6 * V_13 = F_74 ( V_95 ) ;
char V_341 [ 64 ] ;
T_1 V_56 ;
int type , V_342 , V_343 ;
type = F_309 ( V_333 -> V_211 ) ;
V_342 = F_310 ( V_333 -> V_211 ) ;
if ( ! V_137 && type == V_344 )
return - V_345 ;
switch ( type ) {
case V_346 :
if ( V_342 == V_158 )
V_56 = F_307 ( V_13 , false ) ;
else
V_56 = F_132 ( & V_13 -> V_47 , V_342 ) ;
break;
case V_344 :
if ( V_342 == V_158 )
V_56 = F_307 ( V_13 , true ) ;
else
V_56 = F_132 ( & V_13 -> V_138 , V_342 ) ;
break;
default:
F_88 () ;
}
V_343 = F_311 ( V_341 , sizeof( V_341 ) , L_8 , ( unsigned long long ) V_56 ) ;
return F_312 ( V_338 , V_339 , V_340 , V_341 , V_343 ) ;
}
static int F_313 ( struct V_94 * V_95 , struct V_332 * V_333 ,
const char * V_347 )
{
struct V_6 * V_13 = F_74 ( V_95 ) ;
int type , V_342 ;
unsigned long long V_56 ;
int V_78 ;
type = F_309 ( V_333 -> V_211 ) ;
V_342 = F_310 ( V_333 -> V_211 ) ;
if ( ! V_137 && type == V_344 )
return - V_345 ;
switch ( V_342 ) {
case V_159 :
if ( F_8 ( V_13 ) ) {
V_78 = - V_278 ;
break;
}
V_78 = F_314 ( V_347 , & V_56 ) ;
if ( V_78 )
break;
if ( type == V_346 )
V_78 = F_285 ( V_13 , V_56 ) ;
else
V_78 = F_288 ( V_13 , V_56 ) ;
break;
case V_348 :
V_78 = F_314 ( V_347 , & V_56 ) ;
if ( V_78 )
break;
if ( type == V_346 )
V_78 = F_315 ( & V_13 -> V_47 , V_56 ) ;
else
V_78 = - V_278 ;
break;
default:
V_78 = - V_278 ;
break;
}
return V_78 ;
}
static void F_316 ( struct V_6 * V_13 ,
unsigned long long * V_349 , unsigned long long * V_350 )
{
struct V_94 * V_94 ;
unsigned long long V_351 , V_352 , V_353 ;
V_351 = F_132 ( & V_13 -> V_47 , V_159 ) ;
V_352 = F_132 ( & V_13 -> V_138 , V_159 ) ;
V_94 = V_13 -> V_9 . V_94 ;
if ( ! V_13 -> V_107 )
goto V_117;
while ( V_94 -> V_38 ) {
V_94 = V_94 -> V_38 ;
V_13 = F_74 ( V_94 ) ;
if ( ! V_13 -> V_107 )
break;
V_353 = F_132 ( & V_13 -> V_47 , V_159 ) ;
V_351 = F_109 ( V_351 , V_353 ) ;
V_353 = F_132 ( & V_13 -> V_138 , V_159 ) ;
V_352 = F_109 ( V_352 , V_353 ) ;
}
V_117:
* V_349 = V_351 ;
* V_350 = V_352 ;
}
static int F_317 ( struct V_94 * V_95 , unsigned int V_331 )
{
struct V_6 * V_13 = F_74 ( V_95 ) ;
int type , V_342 ;
type = F_309 ( V_331 ) ;
V_342 = F_310 ( V_331 ) ;
if ( ! V_137 && type == V_344 )
return - V_345 ;
switch ( V_342 ) {
case V_354 :
if ( type == V_346 )
F_318 ( & V_13 -> V_47 ) ;
else
F_318 ( & V_13 -> V_138 ) ;
break;
case V_160 :
if ( type == V_346 )
F_319 ( & V_13 -> V_47 ) ;
else
F_319 ( & V_13 -> V_138 ) ;
break;
}
return 0 ;
}
static T_1 F_320 ( struct V_94 * V_139 ,
struct V_332 * V_333 )
{
return F_74 ( V_139 ) -> V_4 ;
}
static int F_321 ( struct V_94 * V_139 ,
struct V_332 * V_333 , T_1 V_56 )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
if ( V_56 >= ( 1 << V_355 ) )
return - V_278 ;
F_304 () ;
V_13 -> V_4 = V_56 ;
F_305 () ;
return 0 ;
}
static int F_321 ( struct V_94 * V_139 ,
struct V_332 * V_333 , T_1 V_56 )
{
return - V_356 ;
}
static int F_322 ( struct V_94 * V_95 , struct V_332 * V_333 ,
struct V_357 * V_358 )
{
int V_22 ;
unsigned long V_359 , V_360 , V_361 , V_362 ;
unsigned long V_363 ;
struct V_6 * V_13 = F_74 ( V_95 ) ;
V_359 = F_65 ( V_13 , V_364 ) ;
F_323 ( V_358 , L_9 , V_359 ) ;
F_66 (nid, N_HIGH_MEMORY) {
V_363 = F_64 ( V_13 , V_22 , V_364 ) ;
F_323 ( V_358 , L_10 , V_22 , V_363 ) ;
}
F_324 ( V_358 , '\n' ) ;
V_360 = F_65 ( V_13 , V_185 ) ;
F_323 ( V_358 , L_11 , V_360 ) ;
F_66 (nid, N_HIGH_MEMORY) {
V_363 = F_64 ( V_13 , V_22 ,
V_185 ) ;
F_323 ( V_358 , L_10 , V_22 , V_363 ) ;
}
F_324 ( V_358 , '\n' ) ;
V_361 = F_65 ( V_13 , V_186 ) ;
F_323 ( V_358 , L_12 , V_361 ) ;
F_66 (nid, N_HIGH_MEMORY) {
V_363 = F_64 ( V_13 , V_22 ,
V_186 ) ;
F_323 ( V_358 , L_10 , V_22 , V_363 ) ;
}
F_324 ( V_358 , '\n' ) ;
V_362 = F_65 ( V_13 , F_63 ( V_365 ) ) ;
F_323 ( V_358 , L_13 , V_362 ) ;
F_66 (nid, N_HIGH_MEMORY) {
V_363 = F_64 ( V_13 , V_22 ,
F_63 ( V_365 ) ) ;
F_323 ( V_358 , L_10 , V_22 , V_363 ) ;
}
F_324 ( V_358 , '\n' ) ;
return 0 ;
}
static inline void F_325 ( void )
{
F_326 ( F_327 ( V_366 ) != V_367 ) ;
}
static int F_328 ( struct V_94 * V_95 , struct V_332 * V_333 ,
struct V_357 * V_358 )
{
struct V_6 * V_13 = F_74 ( V_95 ) ;
struct V_6 * V_368 ;
unsigned int V_233 ;
for ( V_233 = 0 ; V_233 < V_234 ; V_233 ++ ) {
if ( V_233 == V_63 && ! V_137 )
continue;
F_323 ( V_358 , L_14 , V_369 [ V_233 ] ,
F_46 ( V_13 , V_233 ) * V_226 ) ;
}
for ( V_233 = 0 ; V_233 < V_236 ; V_233 ++ )
F_323 ( V_358 , L_15 , V_370 [ V_233 ] ,
F_54 ( V_13 , V_233 ) ) ;
for ( V_233 = 0 ; V_233 < V_367 ; V_233 ++ )
F_323 ( V_358 , L_15 , V_366 [ V_233 ] ,
F_65 ( V_13 , F_63 ( V_233 ) ) * V_226 ) ;
{
unsigned long long V_162 , V_350 ;
F_316 ( V_13 , & V_162 , & V_350 ) ;
F_323 ( V_358 , L_16 , V_162 ) ;
if ( V_137 )
F_323 ( V_358 , L_17 ,
V_350 ) ;
}
for ( V_233 = 0 ; V_233 < V_234 ; V_233 ++ ) {
long long V_56 = 0 ;
if ( V_233 == V_63 && ! V_137 )
continue;
F_134 (mi, memcg)
V_56 += F_46 ( V_368 , V_233 ) * V_226 ;
F_323 ( V_358 , L_18 , V_369 [ V_233 ] , V_56 ) ;
}
for ( V_233 = 0 ; V_233 < V_236 ; V_233 ++ ) {
unsigned long long V_56 = 0 ;
F_134 (mi, memcg)
V_56 += F_54 ( V_368 , V_233 ) ;
F_323 ( V_358 , L_19 ,
V_370 [ V_233 ] , V_56 ) ;
}
for ( V_233 = 0 ; V_233 < V_367 ; V_233 ++ ) {
unsigned long long V_56 = 0 ;
F_134 (mi, memcg)
V_56 += F_65 ( V_368 , F_63 ( V_233 ) ) * V_226 ;
F_323 ( V_358 , L_19 , V_366 [ V_233 ] , V_56 ) ;
}
#ifdef F_329
{
int V_22 , V_23 ;
struct V_21 * V_32 ;
struct V_371 * V_372 ;
unsigned long V_373 [ 2 ] = { 0 , 0 } ;
unsigned long V_374 [ 2 ] = { 0 , 0 } ;
F_330 (nid)
for ( V_23 = 0 ; V_23 < V_50 ; V_23 ++ ) {
V_32 = F_21 ( V_13 , V_22 , V_23 ) ;
V_372 = & V_32 -> V_73 . V_375 ;
V_373 [ 0 ] += V_372 -> V_373 [ 0 ] ;
V_373 [ 1 ] += V_372 -> V_373 [ 1 ] ;
V_374 [ 0 ] += V_372 -> V_374 [ 0 ] ;
V_374 [ 1 ] += V_372 -> V_374 [ 1 ] ;
}
F_323 ( V_358 , L_20 , V_373 [ 0 ] ) ;
F_323 ( V_358 , L_21 , V_373 [ 1 ] ) ;
F_323 ( V_358 , L_22 , V_374 [ 0 ] ) ;
F_323 ( V_358 , L_23 , V_374 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_331 ( struct V_94 * V_139 , struct V_332 * V_333 )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
return F_110 ( V_13 ) ;
}
static int F_332 ( struct V_94 * V_139 , struct V_332 * V_333 ,
T_1 V_56 )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
struct V_6 * V_38 ;
if ( V_56 > 100 )
return - V_278 ;
if ( V_139 -> V_38 == NULL )
return - V_278 ;
V_38 = F_74 ( V_139 -> V_38 ) ;
F_304 () ;
if ( ( V_38 -> V_107 ) ||
( V_13 -> V_107 && ! F_292 ( & V_139 -> V_308 ) ) ) {
F_305 () ;
return - V_278 ;
}
V_13 -> V_141 = V_56 ;
F_305 () ;
return 0 ;
}
static void F_333 ( struct V_6 * V_13 , bool V_336 )
{
struct V_376 * V_377 ;
T_1 V_378 ;
int V_233 ;
F_10 () ;
if ( ! V_336 )
V_377 = F_77 ( V_13 -> V_379 . V_380 ) ;
else
V_377 = F_77 ( V_13 -> V_381 . V_380 ) ;
if ( ! V_377 )
goto V_145;
V_378 = F_307 ( V_13 , V_336 ) ;
V_233 = V_377 -> V_382 ;
for (; V_233 >= 0 && F_71 ( V_377 -> V_383 [ V_233 ] . V_384 > V_378 ) ; V_233 -- )
F_334 ( V_377 -> V_383 [ V_233 ] . V_385 , 1 ) ;
V_233 ++ ;
for (; V_233 < V_377 -> V_386 && F_71 ( V_377 -> V_383 [ V_233 ] . V_384 <= V_378 ) ; V_233 ++ )
F_334 ( V_377 -> V_383 [ V_233 ] . V_385 , 1 ) ;
V_377 -> V_382 = V_233 - 1 ;
V_145:
F_13 () ;
}
static void F_72 ( struct V_6 * V_13 )
{
while ( V_13 ) {
F_333 ( V_13 , false ) ;
if ( V_137 )
F_333 ( V_13 , true ) ;
V_13 = F_38 ( V_13 ) ;
}
}
static int F_335 ( const void * V_387 , const void * V_388 )
{
const struct F_72 * V_389 = V_387 ;
const struct F_72 * V_390 = V_388 ;
return V_389 -> V_384 - V_390 -> V_384 ;
}
static int F_336 ( struct V_6 * V_13 )
{
struct V_391 * V_392 ;
F_337 (ev, &memcg->oom_notify, list)
F_334 ( V_392 -> V_385 , 1 ) ;
return 0 ;
}
static void F_178 ( struct V_6 * V_13 )
{
struct V_6 * V_110 ;
F_134 (iter, memcg)
F_336 ( V_110 ) ;
}
static int F_338 ( struct V_94 * V_139 ,
struct V_332 * V_333 , struct V_393 * V_385 , const char * args )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
struct V_394 * V_379 ;
struct V_376 * V_395 ;
int type = F_309 ( V_333 -> V_211 ) ;
T_1 V_384 , V_378 ;
int V_233 , V_386 , V_78 ;
V_78 = F_314 ( args , & V_384 ) ;
if ( V_78 )
return V_78 ;
F_202 ( & V_13 -> V_396 ) ;
if ( type == V_346 )
V_379 = & V_13 -> V_379 ;
else if ( type == V_344 )
V_379 = & V_13 -> V_381 ;
else
F_88 () ;
V_378 = F_307 ( V_13 , type == V_344 ) ;
if ( V_379 -> V_380 )
F_333 ( V_13 , type == V_344 ) ;
V_386 = V_379 -> V_380 ? V_379 -> V_380 -> V_386 + 1 : 1 ;
V_395 = F_339 ( sizeof( * V_395 ) + V_386 * sizeof( struct F_72 ) ,
V_313 ) ;
if ( ! V_395 ) {
V_78 = - V_264 ;
goto V_145;
}
V_395 -> V_386 = V_386 ;
if ( V_379 -> V_380 ) {
memcpy ( V_395 -> V_383 , V_379 -> V_380 -> V_383 , ( V_386 - 1 ) *
sizeof( struct F_72 ) ) ;
}
V_395 -> V_383 [ V_386 - 1 ] . V_385 = V_385 ;
V_395 -> V_383 [ V_386 - 1 ] . V_384 = V_384 ;
F_340 ( V_395 -> V_383 , V_386 , sizeof( struct F_72 ) ,
F_335 , NULL ) ;
V_395 -> V_382 = - 1 ;
for ( V_233 = 0 ; V_233 < V_386 ; V_233 ++ ) {
if ( V_395 -> V_383 [ V_233 ] . V_384 <= V_378 ) {
++ V_395 -> V_382 ;
} else
break;
}
F_341 ( V_379 -> V_397 ) ;
V_379 -> V_397 = V_379 -> V_380 ;
F_342 ( V_379 -> V_380 , V_395 ) ;
F_112 () ;
V_145:
F_200 ( & V_13 -> V_396 ) ;
return V_78 ;
}
static void F_343 ( struct V_94 * V_139 ,
struct V_332 * V_333 , struct V_393 * V_385 )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
struct V_394 * V_379 ;
struct V_376 * V_395 ;
int type = F_309 ( V_333 -> V_211 ) ;
T_1 V_378 ;
int V_233 , V_398 , V_386 ;
F_202 ( & V_13 -> V_396 ) ;
if ( type == V_346 )
V_379 = & V_13 -> V_379 ;
else if ( type == V_344 )
V_379 = & V_13 -> V_381 ;
else
F_88 () ;
if ( ! V_379 -> V_380 )
goto V_145;
V_378 = F_307 ( V_13 , type == V_344 ) ;
F_333 ( V_13 , type == V_344 ) ;
V_386 = 0 ;
for ( V_233 = 0 ; V_233 < V_379 -> V_380 -> V_386 ; V_233 ++ ) {
if ( V_379 -> V_380 -> V_383 [ V_233 ] . V_385 != V_385 )
V_386 ++ ;
}
V_395 = V_379 -> V_397 ;
if ( ! V_386 ) {
F_341 ( V_395 ) ;
V_395 = NULL ;
goto V_399;
}
V_395 -> V_386 = V_386 ;
V_395 -> V_382 = - 1 ;
for ( V_233 = 0 , V_398 = 0 ; V_233 < V_379 -> V_380 -> V_386 ; V_233 ++ ) {
if ( V_379 -> V_380 -> V_383 [ V_233 ] . V_385 == V_385 )
continue;
V_395 -> V_383 [ V_398 ] = V_379 -> V_380 -> V_383 [ V_233 ] ;
if ( V_395 -> V_383 [ V_398 ] . V_384 <= V_378 ) {
++ V_395 -> V_382 ;
}
V_398 ++ ;
}
V_399:
V_379 -> V_397 = V_379 -> V_380 ;
if ( ! V_395 ) {
F_341 ( V_379 -> V_397 ) ;
V_379 -> V_397 = NULL ;
}
F_342 ( V_379 -> V_380 , V_395 ) ;
F_112 () ;
V_145:
F_200 ( & V_13 -> V_396 ) ;
}
static int F_344 ( struct V_94 * V_139 ,
struct V_332 * V_333 , struct V_393 * V_385 , const char * args )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
struct V_391 * V_331 ;
int type = F_309 ( V_333 -> V_211 ) ;
F_7 ( type != V_400 ) ;
V_331 = F_339 ( sizeof( * V_331 ) , V_313 ) ;
if ( ! V_331 )
return - V_264 ;
F_35 ( & V_213 ) ;
V_331 -> V_385 = V_385 ;
F_345 ( & V_331 -> V_319 , & V_13 -> V_401 ) ;
if ( F_117 ( & V_13 -> V_197 ) )
F_334 ( V_385 , 1 ) ;
F_36 ( & V_213 ) ;
return 0 ;
}
static void F_346 ( struct V_94 * V_139 ,
struct V_332 * V_333 , struct V_393 * V_385 )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
struct V_391 * V_392 , * V_353 ;
int type = F_309 ( V_333 -> V_211 ) ;
F_7 ( type != V_400 ) ;
F_35 ( & V_213 ) ;
F_347 (ev, tmp, &memcg->oom_notify, list) {
if ( V_392 -> V_385 == V_385 ) {
F_348 ( & V_392 -> V_319 ) ;
F_341 ( V_392 ) ;
}
}
F_36 ( & V_213 ) ;
}
static int F_349 ( struct V_94 * V_139 ,
struct V_332 * V_333 , struct V_402 * V_403 )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
V_403 -> V_404 ( V_403 , L_24 , V_13 -> V_215 ) ;
if ( F_117 ( & V_13 -> V_197 ) )
V_403 -> V_404 ( V_403 , L_25 , 1 ) ;
else
V_403 -> V_404 ( V_403 , L_25 , 0 ) ;
return 0 ;
}
static int F_350 ( struct V_94 * V_139 ,
struct V_332 * V_333 , T_1 V_56 )
{
struct V_6 * V_13 = F_74 ( V_139 ) ;
struct V_6 * V_38 ;
if ( ! V_139 -> V_38 || ! ( ( V_56 == 0 ) || ( V_56 == 1 ) ) )
return - V_278 ;
V_38 = F_74 ( V_139 -> V_38 ) ;
F_304 () ;
if ( ( V_38 -> V_107 ) ||
( V_13 -> V_107 && ! F_292 ( & V_139 -> V_308 ) ) ) {
F_305 () ;
return - V_278 ;
}
V_13 -> V_215 = V_56 ;
if ( ! V_56 )
F_175 ( V_13 ) ;
F_305 () ;
return 0 ;
}
static int F_351 ( struct V_6 * V_13 , struct V_405 * V_406 )
{
return F_352 ( V_13 , V_406 ) ;
}
static void F_353 ( struct V_6 * V_13 )
{
F_354 ( V_13 ) ;
}
static int F_351 ( struct V_6 * V_13 , struct V_405 * V_406 )
{
return 0 ;
}
static void F_353 ( struct V_6 * V_13 )
{
}
static int F_355 ( struct V_6 * V_13 , int V_48 )
{
struct V_407 * V_408 ;
struct V_21 * V_32 ;
int V_49 , V_353 = V_48 ;
if ( ! F_356 ( V_48 , V_409 ) )
V_353 = - 1 ;
V_408 = F_357 ( sizeof( * V_408 ) , V_313 , V_353 ) ;
if ( ! V_408 )
return 1 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_32 = & V_408 -> V_26 [ V_49 ] ;
F_358 ( & V_32 -> V_73 , & F_291 ( V_48 ) -> V_321 [ V_49 ] ) ;
V_32 -> V_41 = 0 ;
V_32 -> V_40 = false ;
V_32 -> V_13 = V_13 ;
}
V_13 -> V_24 . V_25 [ V_48 ] = V_408 ;
return 0 ;
}
static void F_359 ( struct V_6 * V_13 , int V_48 )
{
F_341 ( V_13 -> V_24 . V_25 [ V_48 ] ) ;
}
static struct V_6 * F_360 ( void )
{
struct V_6 * V_13 ;
int V_386 = sizeof( struct V_6 ) ;
if ( V_386 < V_226 )
V_13 = F_361 ( V_386 , V_313 ) ;
else
V_13 = F_362 ( V_386 ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_58 = F_363 ( struct V_410 ) ;
if ( ! V_13 -> V_58 )
goto V_411;
F_364 ( & V_13 -> V_60 ) ;
return V_13 ;
V_411:
if ( V_386 < V_226 )
F_341 ( V_13 ) ;
else
F_365 ( V_13 ) ;
return NULL ;
}
static void F_366 ( struct V_227 * V_231 )
{
struct V_6 * V_13 ;
int V_386 = sizeof( struct V_6 ) ;
V_13 = F_5 ( V_231 , struct V_6 , V_412 ) ;
F_18 ( V_13 ) ;
if ( V_386 < V_226 )
F_341 ( V_13 ) ;
else
F_365 ( V_13 ) ;
}
static void F_367 ( struct V_413 * V_413 )
{
struct V_6 * V_13 ;
V_13 = F_5 ( V_413 , struct V_6 , V_414 ) ;
F_368 ( & V_13 -> V_412 , F_366 ) ;
F_369 ( & V_13 -> V_412 ) ;
}
static void F_370 ( struct V_6 * V_13 )
{
int V_48 ;
F_40 ( V_13 ) ;
F_371 ( & V_115 , & V_13 -> V_9 ) ;
F_41 (node)
F_359 ( V_13 , V_48 ) ;
F_372 ( V_13 -> V_58 ) ;
F_373 ( & V_13 -> V_414 , F_367 ) ;
}
static void F_9 ( struct V_6 * V_13 )
{
F_73 ( & V_13 -> V_415 ) ;
}
static void F_374 ( struct V_6 * V_13 , int V_59 )
{
if ( F_375 ( V_59 , & V_13 -> V_415 ) ) {
struct V_6 * V_38 = F_38 ( V_13 ) ;
F_370 ( V_13 ) ;
if ( V_38 )
F_16 ( V_38 ) ;
}
}
static void F_16 ( struct V_6 * V_13 )
{
F_374 ( V_13 , 1 ) ;
}
struct V_6 * F_38 ( struct V_6 * V_13 )
{
if ( ! V_13 -> V_47 . V_38 )
return NULL ;
return F_209 ( V_13 -> V_47 . V_38 , V_47 ) ;
}
static void T_11 F_376 ( void )
{
if ( ! F_79 () && V_416 )
V_137 = 1 ;
}
static void T_11 F_376 ( void )
{
}
static int F_377 ( void )
{
struct V_417 * V_418 ;
struct V_28 * V_419 ;
int V_353 , V_48 , V_49 ;
F_41 (node) {
V_353 = V_48 ;
if ( ! F_356 ( V_48 , V_409 ) )
V_353 = - 1 ;
V_418 = F_357 ( sizeof( * V_418 ) , V_313 , V_353 ) ;
if ( ! V_418 )
goto V_420;
V_29 . V_30 [ V_48 ] = V_418 ;
for ( V_49 = 0 ; V_49 < V_50 ; V_49 ++ ) {
V_419 = & V_418 -> V_31 [ V_49 ] ;
V_419 -> V_37 = V_421 ;
F_364 ( & V_419 -> V_45 ) ;
}
}
return 0 ;
V_420:
F_41 (node) {
if ( ! V_29 . V_30 [ V_48 ] )
break;
F_341 ( V_29 . V_30 [ V_48 ] ) ;
V_29 . V_30 [ V_48 ] = NULL ;
}
return 1 ;
}
static struct V_7 * T_12
F_378 ( struct V_94 * V_95 )
{
struct V_6 * V_13 , * V_38 ;
long error = - V_264 ;
int V_48 ;
V_13 = F_360 () ;
if ( ! V_13 )
return F_379 ( error ) ;
F_41 (node)
if ( F_355 ( V_13 , V_48 ) )
goto V_422;
if ( V_95 -> V_38 == NULL ) {
int V_57 ;
F_376 () ;
V_38 = NULL ;
if ( F_377 () )
goto V_422;
V_106 = V_13 ;
F_380 (cpu) {
struct V_220 * V_221 =
& F_49 ( V_222 , V_57 ) ;
F_368 ( & V_221 -> V_231 , F_189 ) ;
}
F_381 ( F_204 , 0 ) ;
} else {
V_38 = F_74 ( V_95 -> V_38 ) ;
V_13 -> V_107 = V_38 -> V_107 ;
V_13 -> V_215 = V_38 -> V_215 ;
}
if ( V_38 && V_38 -> V_107 ) {
F_382 ( & V_13 -> V_47 , & V_38 -> V_47 ) ;
F_382 ( & V_13 -> V_138 , & V_38 -> V_138 ) ;
F_9 ( V_38 ) ;
} else {
F_382 ( & V_13 -> V_47 , NULL ) ;
F_382 ( & V_13 -> V_138 , NULL ) ;
}
V_13 -> V_191 = V_92 ;
F_177 ( & V_13 -> V_401 ) ;
if ( V_38 )
V_13 -> V_141 = F_110 ( V_38 ) ;
F_156 ( & V_13 -> V_415 , 1 ) ;
V_13 -> V_4 = 0 ;
F_383 ( & V_13 -> V_396 ) ;
F_364 ( & V_13 -> V_151 ) ;
error = F_351 ( V_13 , & V_115 ) ;
if ( error ) {
F_16 ( V_13 ) ;
return F_379 ( error ) ;
}
return & V_13 -> V_9 ;
V_422:
F_370 ( V_13 ) ;
return F_379 ( error ) ;
}
static int F_384 ( struct V_94 * V_95 )
{
struct V_6 * V_13 = F_74 ( V_95 ) ;
return F_296 ( V_13 , false ) ;
}
static void F_385 ( struct V_94 * V_95 )
{
struct V_6 * V_13 = F_74 ( V_95 ) ;
F_353 ( V_13 ) ;
F_16 ( V_13 ) ;
}
static int F_386 ( unsigned long V_59 )
{
int V_78 = 0 ;
int V_423 = V_424 ;
struct V_6 * V_13 = V_2 . V_3 ;
if ( F_8 ( V_13 ) ) {
V_2 . V_425 += V_59 ;
return V_78 ;
}
if ( V_59 > 1 ) {
struct V_248 * V_228 ;
if ( F_207 ( & V_13 -> V_47 , V_226 * V_59 , & V_228 ) )
goto V_426;
if ( V_137 && F_207 ( & V_13 -> V_138 ,
V_226 * V_59 , & V_228 ) ) {
F_188 ( & V_13 -> V_47 , V_226 * V_59 ) ;
goto V_426;
}
V_2 . V_425 += V_59 ;
return V_78 ;
}
V_426:
while ( V_59 -- ) {
if ( F_286 ( V_18 ) ) {
V_78 = - V_265 ;
break;
}
if ( ! V_423 -- ) {
V_423 = V_424 ;
F_295 () ;
}
V_78 = F_211 ( NULL ,
V_313 , 1 , & V_13 , false ) ;
if ( V_78 )
return V_78 ;
V_2 . V_425 ++ ;
}
return V_78 ;
}
static struct V_27 * F_387 ( struct V_427 * V_428 ,
unsigned long V_429 , T_13 V_430 )
{
struct V_27 * V_27 = F_388 ( V_428 , V_429 , V_430 ) ;
if ( ! V_27 || ! F_241 ( V_27 ) )
return NULL ;
if ( F_239 ( V_27 ) ) {
if ( ! F_1 () )
return NULL ;
} else if ( ! F_3 () )
return NULL ;
if ( ! F_244 ( V_27 ) )
return NULL ;
return V_27 ;
}
static struct V_27 * F_389 ( struct V_427 * V_428 ,
unsigned long V_429 , T_13 V_430 , T_6 * V_296 )
{
struct V_27 * V_27 = NULL ;
T_6 V_266 = F_390 ( V_430 ) ;
if ( ! F_1 () || F_391 ( V_266 ) )
return NULL ;
V_27 = F_392 ( & V_431 , V_266 . V_56 ) ;
if ( V_137 )
V_296 -> V_56 = V_266 . V_56 ;
return V_27 ;
}
static struct V_27 * F_389 ( struct V_427 * V_428 ,
unsigned long V_429 , T_13 V_430 , T_6 * V_296 )
{
return NULL ;
}
static struct V_27 * F_393 ( struct V_427 * V_428 ,
unsigned long V_429 , T_13 V_430 , T_6 * V_296 )
{
struct V_27 * V_27 = NULL ;
struct V_432 * V_281 ;
T_14 V_433 ;
if ( ! V_428 -> V_434 )
return NULL ;
if ( ! F_3 () )
return NULL ;
V_281 = V_428 -> V_434 -> V_435 ;
if ( F_394 ( V_430 ) )
V_433 = F_395 ( V_428 , V_429 ) ;
else
V_433 = F_396 ( V_430 ) ;
V_27 = F_392 ( V_281 , V_433 ) ;
#ifdef F_397
if ( F_398 ( V_27 ) ) {
T_6 V_336 = F_399 ( V_27 ) ;
if ( V_137 )
* V_296 = V_336 ;
V_27 = F_392 ( & V_431 , V_336 . V_56 ) ;
}
#endif
return V_27 ;
}
static enum V_436 F_400 ( struct V_427 * V_428 ,
unsigned long V_429 , T_13 V_430 , union V_437 * V_81 )
{
struct V_27 * V_27 = NULL ;
struct V_122 * V_123 ;
enum V_436 V_78 = V_438 ;
T_6 V_266 = { . V_56 = 0 } ;
if ( F_401 ( V_430 ) )
V_27 = F_387 ( V_428 , V_429 , V_430 ) ;
else if ( F_402 ( V_430 ) )
V_27 = F_389 ( V_428 , V_429 , V_430 , & V_266 ) ;
else if ( F_394 ( V_430 ) || F_403 ( V_430 ) )
V_27 = F_393 ( V_428 , V_429 , V_430 , & V_266 ) ;
if ( ! V_27 && ! V_266 . V_56 )
return V_78 ;
if ( V_27 ) {
V_123 = F_91 ( V_27 ) ;
if ( F_93 ( V_123 ) && V_123 -> V_6 == V_2 . V_144 ) {
V_78 = V_439 ;
if ( V_81 )
V_81 -> V_27 = V_27 ;
}
if ( ! V_78 || ! V_81 )
F_250 ( V_27 ) ;
}
if ( V_266 . V_56 && ! V_78 &&
F_80 ( & V_2 . V_144 -> V_9 ) == F_224 ( V_266 ) ) {
V_78 = V_440 ;
if ( V_81 )
V_81 -> V_266 = V_266 ;
}
return V_78 ;
}
static enum V_436 F_404 ( struct V_427 * V_428 ,
unsigned long V_429 , T_15 V_441 , union V_437 * V_81 )
{
struct V_27 * V_27 = NULL ;
struct V_122 * V_123 ;
enum V_436 V_78 = V_438 ;
V_27 = F_405 ( V_441 ) ;
F_95 ( ! V_27 || ! F_406 ( V_27 ) ) ;
if ( ! F_1 () )
return V_78 ;
V_123 = F_91 ( V_27 ) ;
if ( F_93 ( V_123 ) && V_123 -> V_6 == V_2 . V_144 ) {
V_78 = V_439 ;
if ( V_81 ) {
F_407 ( V_27 ) ;
V_81 -> V_27 = V_27 ;
}
}
return V_78 ;
}
static inline enum V_436 F_404 ( struct V_427 * V_428 ,
unsigned long V_429 , T_15 V_441 , union V_437 * V_81 )
{
return V_438 ;
}
static int F_408 ( T_15 * V_441 ,
unsigned long V_429 , unsigned long V_442 ,
struct V_443 * V_444 )
{
struct V_427 * V_428 = V_444 -> V_211 ;
T_13 * V_445 ;
T_16 * V_446 ;
if ( F_409 ( V_441 , V_428 ) == 1 ) {
if ( F_404 ( V_428 , V_429 , * V_441 , NULL ) == V_439 )
V_2 . V_425 += V_275 ;
F_36 ( & V_428 -> V_447 -> V_448 ) ;
return 0 ;
}
if ( F_410 ( V_441 ) )
return 0 ;
V_445 = F_411 ( V_428 -> V_447 , V_441 , V_429 , & V_446 ) ;
for (; V_429 != V_442 ; V_445 ++ , V_429 += V_226 )
if ( F_400 ( V_428 , V_429 , * V_445 , NULL ) )
V_2 . V_425 ++ ;
F_412 ( V_445 - 1 , V_446 ) ;
F_295 () ;
return 0 ;
}
static unsigned long F_413 ( struct V_98 * V_99 )
{
unsigned long V_425 ;
struct V_427 * V_428 ;
F_414 ( & V_99 -> V_449 ) ;
for ( V_428 = V_99 -> V_450 ; V_428 ; V_428 = V_428 -> V_451 ) {
struct V_443 V_452 = {
. V_453 = F_408 ,
. V_99 = V_99 ,
. V_211 = V_428 ,
} ;
if ( F_415 ( V_428 ) )
continue;
F_416 ( V_428 -> V_454 , V_428 -> V_455 ,
& V_452 ) ;
}
F_417 ( & V_99 -> V_449 ) ;
V_425 = V_2 . V_425 ;
V_2 . V_425 = 0 ;
return V_425 ;
}
static int F_418 ( struct V_98 * V_99 )
{
unsigned long V_425 = F_413 ( V_99 ) ;
F_95 ( V_2 . V_146 ) ;
V_2 . V_146 = V_18 ;
return F_386 ( V_425 ) ;
}
static void F_419 ( void )
{
struct V_6 * V_144 = V_2 . V_144 ;
struct V_6 * V_3 = V_2 . V_3 ;
if ( V_2 . V_425 ) {
F_214 ( V_2 . V_3 , V_2 . V_425 ) ;
V_2 . V_425 = 0 ;
}
if ( V_2 . V_456 ) {
F_214 ( V_2 . V_144 , V_2 . V_456 ) ;
V_2 . V_456 = 0 ;
}
if ( V_2 . V_457 ) {
if ( ! F_8 ( V_2 . V_144 ) )
F_188 ( & V_2 . V_144 -> V_138 ,
V_226 * V_2 . V_457 ) ;
F_374 ( V_2 . V_144 , V_2 . V_457 ) ;
if ( ! F_8 ( V_2 . V_3 ) ) {
F_188 ( & V_2 . V_3 -> V_47 ,
V_226 * V_2 . V_457 ) ;
}
V_2 . V_457 = 0 ;
}
F_175 ( V_144 ) ;
F_175 ( V_3 ) ;
F_420 ( & V_2 . V_148 ) ;
}
static void F_421 ( void )
{
struct V_6 * V_144 = V_2 . V_144 ;
V_2 . V_146 = NULL ;
F_419 () ;
F_35 ( & V_2 . V_45 ) ;
V_2 . V_144 = NULL ;
V_2 . V_3 = NULL ;
F_36 ( & V_2 . V_45 ) ;
F_113 ( V_144 ) ;
}
static int F_422 ( struct V_94 * V_94 ,
struct V_458 * V_459 )
{
struct V_97 * V_36 = F_423 ( V_459 ) ;
int V_78 = 0 ;
struct V_6 * V_13 = F_74 ( V_94 ) ;
if ( V_13 -> V_4 ) {
struct V_98 * V_99 ;
struct V_6 * V_144 = F_11 ( V_36 ) ;
F_95 ( V_144 == V_13 ) ;
V_99 = F_424 ( V_36 ) ;
if ( ! V_99 )
return 0 ;
if ( V_99 -> V_100 == V_36 ) {
F_95 ( V_2 . V_144 ) ;
F_95 ( V_2 . V_3 ) ;
F_95 ( V_2 . V_425 ) ;
F_95 ( V_2 . V_456 ) ;
F_95 ( V_2 . V_457 ) ;
F_111 ( V_144 ) ;
F_35 ( & V_2 . V_45 ) ;
V_2 . V_144 = V_144 ;
V_2 . V_3 = V_13 ;
F_36 ( & V_2 . V_45 ) ;
V_78 = F_418 ( V_99 ) ;
if ( V_78 )
F_421 () ;
}
F_425 ( V_99 ) ;
}
return V_78 ;
}
static void F_426 ( struct V_94 * V_94 ,
struct V_458 * V_459 )
{
F_421 () ;
}
static int F_427 ( T_15 * V_441 ,
unsigned long V_429 , unsigned long V_442 ,
struct V_443 * V_444 )
{
int V_78 = 0 ;
struct V_427 * V_428 = V_444 -> V_211 ;
T_13 * V_445 ;
T_16 * V_446 ;
enum V_436 V_460 ;
union V_437 V_81 ;
struct V_27 * V_27 ;
struct V_122 * V_123 ;
if ( F_409 ( V_441 , V_428 ) == 1 ) {
if ( V_2 . V_425 < V_275 ) {
F_36 ( & V_428 -> V_447 -> V_448 ) ;
return 0 ;
}
V_460 = F_404 ( V_428 , V_429 , * V_441 , & V_81 ) ;
if ( V_460 == V_439 ) {
V_27 = V_81 . V_27 ;
if ( ! F_245 ( V_27 ) ) {
V_123 = F_91 ( V_27 ) ;
if ( ! F_238 ( V_27 , V_275 ,
V_123 , V_2 . V_144 , V_2 . V_3 ) ) {
V_2 . V_425 -= V_275 ;
V_2 . V_456 += V_275 ;
}
F_249 ( V_27 ) ;
}
F_250 ( V_27 ) ;
}
F_36 ( & V_428 -> V_447 -> V_448 ) ;
return 0 ;
}
if ( F_410 ( V_441 ) )
return 0 ;
V_52:
V_445 = F_411 ( V_428 -> V_447 , V_441 , V_429 , & V_446 ) ;
for (; V_429 != V_442 ; V_429 += V_226 ) {
T_13 V_430 = * ( V_445 ++ ) ;
T_6 V_266 ;
if ( ! V_2 . V_425 )
break;
switch ( F_400 ( V_428 , V_429 , V_430 , & V_81 ) ) {
case V_439 :
V_27 = V_81 . V_27 ;
if ( F_245 ( V_27 ) )
goto V_280;
V_123 = F_91 ( V_27 ) ;
if ( ! F_238 ( V_27 , 1 , V_123 ,
V_2 . V_144 , V_2 . V_3 ) ) {
V_2 . V_425 -- ;
V_2 . V_456 ++ ;
}
F_249 ( V_27 ) ;
V_280:
F_250 ( V_27 ) ;
break;
case V_440 :
V_266 = V_81 . V_266 ;
if ( ! F_275 ( V_266 , V_2 . V_144 , V_2 . V_3 ) ) {
V_2 . V_425 -- ;
V_2 . V_457 ++ ;
}
break;
default:
break;
}
}
F_412 ( V_445 - 1 , V_446 ) ;
F_295 () ;
if ( V_429 != V_442 ) {
V_78 = F_386 ( 1 ) ;
if ( ! V_78 )
goto V_52;
}
return V_78 ;
}
static void F_428 ( struct V_98 * V_99 )
{
struct V_427 * V_428 ;
F_298 () ;
V_52:
if ( F_71 ( ! F_429 ( & V_99 -> V_449 ) ) ) {
F_419 () ;
F_295 () ;
goto V_52;
}
for ( V_428 = V_99 -> V_450 ; V_428 ; V_428 = V_428 -> V_451 ) {
int V_78 ;
struct V_443 V_461 = {
. V_453 = F_427 ,
. V_99 = V_99 ,
. V_211 = V_428 ,
} ;
if ( F_415 ( V_428 ) )
continue;
V_78 = F_416 ( V_428 -> V_454 , V_428 -> V_455 ,
& V_461 ) ;
if ( V_78 )
break;
}
F_417 ( & V_99 -> V_449 ) ;
}
static void F_430 ( struct V_94 * V_95 ,
struct V_458 * V_459 )
{
struct V_97 * V_36 = F_423 ( V_459 ) ;
struct V_98 * V_99 = F_424 ( V_36 ) ;
if ( V_99 ) {
if ( V_2 . V_3 )
F_428 ( V_99 ) ;
F_425 ( V_99 ) ;
}
if ( V_2 . V_3 )
F_421 () ;
}
static int F_422 ( struct V_94 * V_94 ,
struct V_458 * V_459 )
{
return 0 ;
}
static void F_426 ( struct V_94 * V_94 ,
struct V_458 * V_459 )
{
}
static void F_430 ( struct V_94 * V_95 ,
struct V_458 * V_459 )
{
}
static int T_11 F_431 ( char * V_8 )
{
if ( ! strcmp ( V_8 , L_26 ) )
V_416 = 1 ;
else if ( ! strcmp ( V_8 , L_27 ) )
V_416 = 0 ;
return 1 ;
}
