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
void F_4 ( struct V_6 * V_7 )
{
if ( V_8 ) {
struct V_9 * V_10 ;
struct V_11 * V_11 ;
F_5 ( ! V_7 -> V_12 -> V_13 ) ;
if ( V_7 -> V_14 ) {
F_5 ( F_6 ( V_7 -> V_14 -> V_10 ) ) ;
F_7 ( V_7 -> V_14 -> V_10 ) ;
return;
}
F_8 () ;
V_10 = F_9 ( V_15 ) ;
V_11 = V_7 -> V_12 -> V_13 ( V_10 ) ;
if ( ! F_6 ( V_10 ) && F_10 ( V_11 ) ) {
F_7 ( V_10 ) ;
V_7 -> V_14 = V_11 ;
}
F_11 () ;
}
}
void F_12 ( struct V_6 * V_7 )
{
if ( V_8 && V_7 -> V_14 ) {
struct V_9 * V_10 ;
F_13 ( ! V_7 -> V_14 -> V_10 ) ;
V_10 = V_7 -> V_14 -> V_10 ;
F_14 ( V_10 ) ;
}
}
struct V_11 * F_15 ( struct V_9 * V_10 )
{
if ( ! V_10 || F_6 ( V_10 ) )
return NULL ;
return & V_10 -> V_16 . V_11 ;
}
static void F_16 ( struct V_9 * V_10 )
{
if ( ! F_17 ( & V_10 -> V_16 . V_11 ) )
return;
F_18 ( & V_17 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
}
static struct V_18 *
F_19 ( struct V_9 * V_10 , int V_19 , int V_20 )
{
return & V_10 -> V_21 . V_22 [ V_19 ] -> V_23 [ V_20 ] ;
}
struct V_24 * F_20 ( struct V_9 * V_10 )
{
return & V_10 -> V_25 ;
}
static struct V_18 *
F_21 ( struct V_9 * V_10 , struct V_26 * V_26 )
{
int V_19 = F_22 ( V_26 ) ;
int V_20 = F_23 ( V_26 ) ;
return F_19 ( V_10 , V_19 , V_20 ) ;
}
static struct V_27 *
F_24 ( int V_19 , int V_20 )
{
return & V_28 . V_29 [ V_19 ] -> V_30 [ V_20 ] ;
}
static struct V_27 *
F_25 ( struct V_26 * V_26 )
{
int V_19 = F_22 ( V_26 ) ;
int V_20 = F_23 ( V_26 ) ;
return & V_28 . V_29 [ V_19 ] -> V_30 [ V_20 ] ;
}
static void
F_26 ( struct V_9 * V_10 ,
struct V_18 * V_31 ,
struct V_27 * V_32 ,
unsigned long long V_33 )
{
struct V_34 * * V_35 = & V_32 -> V_36 . V_34 ;
struct V_34 * V_37 = NULL ;
struct V_18 * V_38 ;
if ( V_31 -> V_39 )
return;
V_31 -> V_40 = V_33 ;
if ( ! V_31 -> V_40 )
return;
while ( * V_35 ) {
V_37 = * V_35 ;
V_38 = F_27 ( V_37 , struct V_18 ,
V_41 ) ;
if ( V_31 -> V_40 < V_38 -> V_40 )
V_35 = & ( * V_35 ) -> V_42 ;
else if ( V_31 -> V_40 >= V_38 -> V_40 )
V_35 = & ( * V_35 ) -> V_43 ;
}
F_28 ( & V_31 -> V_41 , V_37 , V_35 ) ;
F_29 ( & V_31 -> V_41 , & V_32 -> V_36 ) ;
V_31 -> V_39 = true ;
}
static void
F_30 ( struct V_9 * V_10 ,
struct V_18 * V_31 ,
struct V_27 * V_32 )
{
if ( ! V_31 -> V_39 )
return;
F_31 ( & V_31 -> V_41 , & V_32 -> V_36 ) ;
V_31 -> V_39 = false ;
}
static void
F_32 ( struct V_9 * V_10 ,
struct V_18 * V_31 ,
struct V_27 * V_32 )
{
F_33 ( & V_32 -> V_44 ) ;
F_30 ( V_10 , V_31 , V_32 ) ;
F_34 ( & V_32 -> V_44 ) ;
}
static void F_35 ( struct V_9 * V_10 , struct V_26 * V_26 )
{
unsigned long long V_45 ;
struct V_18 * V_31 ;
struct V_27 * V_32 ;
int V_19 = F_22 ( V_26 ) ;
int V_20 = F_23 ( V_26 ) ;
V_32 = F_25 ( V_26 ) ;
for (; V_10 ; V_10 = F_36 ( V_10 ) ) {
V_31 = F_19 ( V_10 , V_19 , V_20 ) ;
V_45 = F_37 ( & V_10 -> V_46 ) ;
if ( V_45 || V_31 -> V_39 ) {
F_33 ( & V_32 -> V_44 ) ;
if ( V_31 -> V_39 )
F_30 ( V_10 , V_31 , V_32 ) ;
F_26 ( V_10 , V_31 , V_32 , V_45 ) ;
F_34 ( & V_32 -> V_44 ) ;
}
}
}
static void F_38 ( struct V_9 * V_10 )
{
int V_47 , V_48 ;
struct V_18 * V_31 ;
struct V_27 * V_32 ;
F_39 (node) {
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_31 = F_19 ( V_10 , V_47 , V_48 ) ;
V_32 = F_24 ( V_47 , V_48 ) ;
F_32 ( V_10 , V_31 , V_32 ) ;
}
}
}
static struct V_18 *
F_40 ( struct V_27 * V_32 )
{
struct V_34 * V_50 = NULL ;
struct V_18 * V_31 ;
V_51:
V_31 = NULL ;
V_50 = F_41 ( & V_32 -> V_36 ) ;
if ( ! V_50 )
goto V_52;
V_31 = F_27 ( V_50 , struct V_18 , V_41 ) ;
F_30 ( V_31 -> V_10 , V_31 , V_32 ) ;
if ( ! F_37 ( & V_31 -> V_10 -> V_46 ) ||
! F_42 ( & V_31 -> V_10 -> V_25 ) )
goto V_51;
V_52:
return V_31 ;
}
static struct V_18 *
F_43 ( struct V_27 * V_32 )
{
struct V_18 * V_31 ;
F_33 ( & V_32 -> V_44 ) ;
V_31 = F_40 ( V_32 ) ;
F_34 ( & V_32 -> V_44 ) ;
return V_31 ;
}
static long F_44 ( struct V_9 * V_10 ,
enum V_53 V_54 )
{
long V_55 = 0 ;
int V_56 ;
F_45 () ;
F_46 (cpu)
V_55 += F_47 ( V_10 -> V_57 -> V_58 [ V_54 ] , V_56 ) ;
#ifdef F_48
F_33 ( & V_10 -> V_59 ) ;
V_55 += V_10 -> V_60 . V_58 [ V_54 ] ;
F_34 ( & V_10 -> V_59 ) ;
#endif
F_49 () ;
return V_55 ;
}
static void F_50 ( struct V_9 * V_10 ,
bool V_61 )
{
int V_55 = ( V_61 ) ? 1 : - 1 ;
F_51 ( V_10 -> V_57 -> V_58 [ V_62 ] , V_55 ) ;
}
static unsigned long F_52 ( struct V_9 * V_10 ,
enum V_63 V_54 )
{
unsigned long V_55 = 0 ;
int V_56 ;
F_46 (cpu)
V_55 += F_47 ( V_10 -> V_57 -> V_64 [ V_54 ] , V_56 ) ;
#ifdef F_48
F_33 ( & V_10 -> V_59 ) ;
V_55 += V_10 -> V_60 . V_64 [ V_54 ] ;
F_34 ( & V_10 -> V_59 ) ;
#endif
return V_55 ;
}
static void F_53 ( struct V_9 * V_10 ,
bool V_65 , int V_66 )
{
F_54 () ;
if ( V_65 )
F_55 ( V_10 -> V_57 -> V_58 [ V_67 ] ,
V_66 ) ;
else
F_55 ( V_10 -> V_57 -> V_58 [ V_68 ] ,
V_66 ) ;
if ( V_66 > 0 )
F_56 ( V_10 -> V_57 -> V_64 [ V_69 ] ) ;
else {
F_56 ( V_10 -> V_57 -> V_64 [ V_70 ] ) ;
V_66 = - V_66 ;
}
F_55 ( V_10 -> V_57 -> V_71 , V_66 ) ;
F_57 () ;
}
unsigned long
F_58 ( struct V_72 * V_72 , enum V_73 V_74 )
{
struct V_18 * V_31 ;
V_31 = F_59 ( V_72 , struct V_18 , V_72 ) ;
return V_31 -> V_75 [ V_74 ] ;
}
static unsigned long
F_60 ( struct V_9 * V_10 , int V_19 , int V_20 ,
unsigned int V_76 )
{
struct V_18 * V_31 ;
enum V_73 V_74 ;
unsigned long V_77 = 0 ;
V_31 = F_19 ( V_10 , V_19 , V_20 ) ;
F_61 (lru) {
if ( F_62 ( V_74 ) & V_76 )
V_77 += V_31 -> V_75 [ V_74 ] ;
}
return V_77 ;
}
static unsigned long
F_63 ( struct V_9 * V_10 ,
int V_19 , unsigned int V_76 )
{
T_1 V_78 = 0 ;
int V_20 ;
for ( V_20 = 0 ; V_20 < V_49 ; V_20 ++ )
V_78 += F_60 ( V_10 ,
V_19 , V_20 , V_76 ) ;
return V_78 ;
}
static unsigned long F_64 ( struct V_9 * V_10 ,
unsigned int V_76 )
{
int V_19 ;
T_1 V_78 = 0 ;
F_65 (nid, N_HIGH_MEMORY)
V_78 += F_63 ( V_10 , V_19 , V_76 ) ;
return V_78 ;
}
static bool F_66 ( struct V_9 * V_10 ,
enum V_79 V_80 )
{
unsigned long V_55 , V_81 ;
V_55 = F_67 ( V_10 -> V_57 -> V_71 ) ;
V_81 = F_67 ( V_10 -> V_57 -> V_82 [ V_80 ] ) ;
if ( ( long ) V_81 - ( long ) V_55 < 0 ) {
switch ( V_80 ) {
case V_83 :
V_81 = V_55 + V_84 ;
break;
case V_85 :
V_81 = V_55 + V_86 ;
break;
case V_87 :
V_81 = V_55 + V_88 ;
break;
default:
break;
}
F_68 ( V_10 -> V_57 -> V_82 [ V_80 ] , V_81 ) ;
return true ;
}
return false ;
}
static void F_69 ( struct V_9 * V_10 , struct V_26 * V_26 )
{
F_54 () ;
if ( F_70 ( F_66 ( V_10 ,
V_83 ) ) ) {
bool V_89 ;
bool T_2 V_90 ;
V_89 = F_66 ( V_10 ,
V_85 ) ;
#if V_91 > 1
T_2 = F_66 ( V_10 ,
V_87 ) ;
#endif
F_57 () ;
F_71 ( V_10 ) ;
if ( F_70 ( V_89 ) )
F_35 ( V_10 , V_26 ) ;
#if V_91 > 1
if ( F_70 ( T_2 ) )
F_72 ( & V_10 -> V_92 ) ;
#endif
} else
F_57 () ;
}
struct V_9 * F_73 ( struct V_93 * V_94 )
{
return F_59 ( V_24 ( V_94 ,
V_95 ) , struct V_9 ,
V_25 ) ;
}
struct V_9 * F_9 ( struct V_96 * V_35 )
{
if ( F_70 ( ! V_35 ) )
return NULL ;
return F_59 ( F_74 ( V_35 , V_95 ) ,
struct V_9 , V_25 ) ;
}
struct V_9 * F_75 ( struct V_97 * V_98 )
{
struct V_9 * V_10 = NULL ;
if ( ! V_98 )
return NULL ;
F_8 () ;
do {
V_10 = F_9 ( F_76 ( V_98 -> V_99 ) ) ;
if ( F_70 ( ! V_10 ) )
break;
} while ( ! F_42 ( & V_10 -> V_25 ) );
F_11 () ;
return V_10 ;
}
struct V_9 * F_77 ( struct V_9 * V_100 ,
struct V_9 * V_101 ,
struct V_102 * V_103 )
{
struct V_9 * V_10 = NULL ;
int V_104 = 0 ;
if ( F_78 () )
return NULL ;
if ( ! V_100 )
V_100 = V_105 ;
if ( V_101 && ! V_103 )
V_104 = F_79 ( & V_101 -> V_25 ) ;
if ( V_101 && V_101 != V_100 )
F_80 ( & V_101 -> V_25 ) ;
if ( ! V_100 -> V_106 && V_100 != V_105 ) {
if ( V_101 )
return NULL ;
return V_100 ;
}
while ( ! V_10 ) {
struct V_107 * V_108 ( V_109 ) ;
struct V_24 * V_25 ;
if ( V_103 ) {
int V_19 = F_81 ( V_103 -> V_48 ) ;
int V_20 = F_82 ( V_103 -> V_48 ) ;
struct V_18 * V_31 ;
V_31 = F_19 ( V_100 , V_19 , V_20 ) ;
V_109 = & V_31 -> V_110 [ V_103 -> V_111 ] ;
if ( V_101 && V_103 -> V_112 != V_109 -> V_112 )
return NULL ;
V_104 = V_109 -> V_113 ;
}
F_8 () ;
V_25 = F_83 ( & V_114 , V_104 + 1 , & V_100 -> V_25 , & V_104 ) ;
if ( V_25 ) {
if ( V_25 == & V_100 -> V_25 || F_42 ( V_25 ) )
V_10 = F_59 ( V_25 ,
struct V_9 , V_25 ) ;
} else
V_104 = 0 ;
F_11 () ;
if ( V_103 ) {
V_109 -> V_113 = V_104 ;
if ( ! V_25 )
V_109 -> V_112 ++ ;
else if ( ! V_101 && V_10 )
V_103 -> V_112 = V_109 -> V_112 ;
}
if ( V_101 && ! V_25 )
return NULL ;
}
return V_10 ;
}
void F_84 ( struct V_9 * V_100 ,
struct V_9 * V_101 )
{
if ( ! V_100 )
V_100 = V_105 ;
if ( V_101 && V_101 != V_100 )
F_80 ( & V_101 -> V_25 ) ;
}
static inline bool F_6 ( struct V_9 * V_10 )
{
return ( V_10 == V_105 ) ;
}
void F_85 ( struct V_97 * V_98 , enum V_115 V_54 )
{
struct V_9 * V_10 ;
if ( ! V_98 )
return;
F_8 () ;
V_10 = F_9 ( F_76 ( V_98 -> V_99 ) ) ;
if ( F_70 ( ! V_10 ) )
goto V_116;
switch ( V_54 ) {
case V_117 :
F_86 ( V_10 -> V_57 -> V_64 [ V_118 ] ) ;
break;
case V_119 :
F_86 ( V_10 -> V_57 -> V_64 [ V_120 ] ) ;
break;
default:
F_87 () ;
}
V_116:
F_11 () ;
}
struct V_72 * F_88 ( struct V_48 * V_48 ,
struct V_9 * V_10 )
{
struct V_18 * V_31 ;
if ( F_78 () )
return & V_48 -> V_72 ;
V_31 = F_19 ( V_10 , F_81 ( V_48 ) , F_82 ( V_48 ) ) ;
return & V_31 -> V_72 ;
}
struct V_72 * F_89 ( struct V_26 * V_26 , struct V_48 * V_48 )
{
struct V_18 * V_31 ;
struct V_9 * V_10 ;
struct V_121 * V_122 ;
if ( F_78 () )
return & V_48 -> V_72 ;
V_122 = F_90 ( V_26 ) ;
V_10 = V_122 -> V_9 ;
if ( ! F_91 ( V_26 ) && ! F_92 ( V_122 ) && V_10 != V_105 )
V_122 -> V_9 = V_10 = V_105 ;
V_31 = F_21 ( V_10 , V_26 ) ;
return & V_31 -> V_72 ;
}
void F_93 ( struct V_72 * V_72 , enum V_73 V_74 ,
int V_66 )
{
struct V_18 * V_31 ;
unsigned long * V_75 ;
if ( F_78 () )
return;
V_31 = F_59 ( V_72 , struct V_18 , V_72 ) ;
V_75 = V_31 -> V_75 + V_74 ;
* V_75 += V_66 ;
F_94 ( ( long ) ( * V_75 ) < 0 ) ;
}
bool F_95 ( const struct V_9 * V_123 ,
struct V_9 * V_10 )
{
if ( V_123 == V_10 )
return true ;
if ( ! V_123 -> V_106 || ! V_10 )
return false ;
return F_96 ( & V_10 -> V_25 , & V_123 -> V_25 ) ;
}
static bool F_97 ( const struct V_9 * V_123 ,
struct V_9 * V_10 )
{
bool V_77 ;
F_8 () ;
V_77 = F_95 ( V_123 , V_10 ) ;
F_11 () ;
return V_77 ;
}
int F_98 ( struct V_96 * V_124 , const struct V_9 * V_10 )
{
int V_77 ;
struct V_9 * V_125 = NULL ;
struct V_96 * V_35 ;
V_35 = F_99 ( V_124 ) ;
if ( V_35 ) {
V_125 = F_75 ( V_35 -> V_98 ) ;
F_100 ( V_35 ) ;
} else {
F_101 ( V_124 ) ;
V_125 = F_9 ( V_124 ) ;
if ( V_125 )
F_102 ( & V_125 -> V_25 ) ;
F_100 ( V_124 ) ;
}
if ( ! V_125 )
return 0 ;
V_77 = F_97 ( V_10 , V_125 ) ;
F_80 ( & V_125 -> V_25 ) ;
return V_77 ;
}
int F_103 ( struct V_72 * V_72 )
{
unsigned long V_126 ;
unsigned long V_127 ;
unsigned long V_128 ;
unsigned long V_129 ;
V_127 = F_58 ( V_72 , V_130 ) ;
V_128 = F_58 ( V_72 , V_131 ) ;
V_129 = ( V_127 + V_128 ) >> ( 30 - V_132 ) ;
if ( V_129 )
V_126 = F_104 ( 10 * V_129 ) ;
else
V_126 = 1 ;
return V_127 * V_126 < V_128 ;
}
int F_105 ( struct V_72 * V_72 )
{
unsigned long V_128 ;
unsigned long V_127 ;
V_127 = F_58 ( V_72 , V_133 ) ;
V_128 = F_58 ( V_72 , V_134 ) ;
return ( V_128 > V_127 ) ;
}
static unsigned long F_106 ( struct V_9 * V_10 )
{
unsigned long long V_135 ;
V_135 = F_107 ( & V_10 -> V_46 ) ;
if ( V_136 )
V_135 = F_108 ( V_135 , F_107 ( & V_10 -> V_137 ) ) ;
return V_135 >> V_132 ;
}
int F_109 ( struct V_9 * V_10 )
{
struct V_93 * V_138 = V_10 -> V_25 . V_93 ;
if ( V_138 -> V_37 == NULL )
return V_139 ;
return V_10 -> V_140 ;
}
static void F_110 ( struct V_9 * V_10 )
{
F_72 ( & V_141 ) ;
F_72 ( & V_10 -> V_142 ) ;
F_111 () ;
}
static void F_112 ( struct V_9 * V_10 )
{
if ( V_10 ) {
F_113 ( & V_141 ) ;
F_113 ( & V_10 -> V_142 ) ;
}
}
static bool F_114 ( struct V_9 * V_10 )
{
F_94 ( ! F_115 () ) ;
return F_116 ( & V_10 -> V_142 ) > 0 ;
}
static bool F_117 ( struct V_9 * V_10 )
{
struct V_9 * V_143 ;
struct V_9 * V_3 ;
bool V_77 = false ;
F_33 ( & V_2 . V_44 ) ;
V_143 = V_2 . V_143 ;
V_3 = V_2 . V_3 ;
if ( ! V_143 )
goto V_144;
V_77 = F_97 ( V_10 , V_143 )
|| F_97 ( V_10 , V_3 ) ;
V_144:
F_34 ( & V_2 . V_44 ) ;
return V_77 ;
}
static bool F_118 ( struct V_9 * V_10 )
{
if ( V_2 . V_145 && V_15 != V_2 . V_145 ) {
if ( F_117 ( V_10 ) ) {
F_119 ( V_146 ) ;
F_120 ( & V_2 . V_147 , & V_146 , V_148 ) ;
if ( V_2 . V_145 )
F_121 () ;
F_122 ( & V_2 . V_147 , & V_146 ) ;
return true ;
}
}
return false ;
}
static void F_123 ( struct V_9 * V_10 ,
unsigned long * V_149 )
{
F_124 ( & V_10 -> V_150 , * V_149 ) ;
}
static void F_125 ( struct V_9 * V_10 ,
unsigned long * V_149 )
{
F_126 ( & V_10 -> V_150 , * V_149 ) ;
}
void F_127 ( struct V_9 * V_10 , struct V_96 * V_35 )
{
struct V_93 * V_151 ;
struct V_93 * V_152 ;
static char V_153 [ V_154 ] ;
int V_77 ;
if ( ! V_10 || ! V_35 )
return;
F_8 () ;
V_152 = V_10 -> V_25 . V_93 ;
V_151 = F_128 ( V_35 , V_95 ) ;
V_77 = F_129 ( V_151 , V_153 , V_154 ) ;
if ( V_77 < 0 ) {
F_11 () ;
goto V_52;
}
F_11 () ;
F_130 ( V_155 L_1 , V_153 ) ;
F_8 () ;
V_77 = F_129 ( V_152 , V_153 , V_154 ) ;
if ( V_77 < 0 ) {
F_11 () ;
goto V_52;
}
F_11 () ;
F_130 ( V_156 L_2 , V_153 ) ;
V_52:
F_130 ( V_155 L_3 ,
F_131 ( & V_10 -> V_46 , V_157 ) >> 10 ,
F_131 ( & V_10 -> V_46 , V_158 ) >> 10 ,
F_131 ( & V_10 -> V_46 , V_159 ) ) ;
F_130 ( V_155 L_4
L_5 ,
F_131 ( & V_10 -> V_137 , V_157 ) >> 10 ,
F_131 ( & V_10 -> V_137 , V_158 ) >> 10 ,
F_131 ( & V_10 -> V_137 , V_159 ) ) ;
}
static int F_132 ( struct V_9 * V_10 )
{
int V_160 = 0 ;
struct V_9 * V_109 ;
F_133 (iter, memcg)
V_160 ++ ;
return V_160 ;
}
T_1 F_134 ( struct V_9 * V_10 )
{
T_1 V_161 ;
T_1 V_137 ;
V_161 = F_131 ( & V_10 -> V_46 , V_158 ) ;
V_161 += V_162 << V_132 ;
V_137 = F_131 ( & V_10 -> V_137 , V_158 ) ;
return F_108 ( V_161 , V_137 ) ;
}
static unsigned long F_135 ( struct V_9 * V_10 ,
T_3 V_163 ,
unsigned long V_149 )
{
unsigned long V_78 = 0 ;
bool V_164 = false ;
int V_165 ;
if ( V_149 & V_166 )
V_164 = true ;
if ( ! ( V_149 & V_167 ) && V_10 -> V_168 )
V_164 = true ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
if ( V_165 )
F_136 ( V_10 ) ;
V_78 += F_137 ( V_10 , V_163 , V_164 ) ;
if ( V_78 && ( V_149 & V_167 ) )
break;
if ( F_106 ( V_10 ) )
break;
if ( V_165 && ! V_78 )
break;
}
return V_78 ;
}
static bool F_138 ( struct V_9 * V_10 ,
int V_19 , bool V_164 )
{
if ( F_63 ( V_10 , V_19 , V_170 ) )
return true ;
if ( V_164 || ! V_162 )
return false ;
if ( F_63 ( V_10 , V_19 , V_171 ) )
return true ;
return false ;
}
static void F_139 ( struct V_9 * V_10 )
{
int V_19 ;
if ( ! F_116 ( & V_10 -> V_92 ) )
return;
if ( F_140 ( & V_10 -> V_172 ) > 1 )
return;
V_10 -> V_173 = V_174 [ V_175 ] ;
F_141 (nid, node_states[N_HIGH_MEMORY]) {
if ( ! F_138 ( V_10 , V_19 , false ) )
F_142 ( V_19 , V_10 -> V_173 ) ;
}
F_143 ( & V_10 -> V_92 , 0 ) ;
F_143 ( & V_10 -> V_172 , 0 ) ;
}
int F_144 ( struct V_9 * V_10 )
{
int V_47 ;
F_139 ( V_10 ) ;
V_47 = V_10 -> V_176 ;
V_47 = F_145 ( V_47 , V_10 -> V_173 ) ;
if ( V_47 == V_91 )
V_47 = F_146 ( V_10 -> V_173 ) ;
if ( F_70 ( V_47 == V_91 ) )
V_47 = F_147 () ;
V_10 -> V_176 = V_47 ;
return V_47 ;
}
static bool F_148 ( struct V_9 * V_10 , bool V_164 )
{
int V_19 ;
if ( ! F_149 ( V_10 -> V_173 ) ) {
for ( V_19 = F_146 ( V_10 -> V_173 ) ;
V_19 < V_91 ;
V_19 = F_145 ( V_19 , V_10 -> V_173 ) ) {
if ( F_138 ( V_10 , V_19 , V_164 ) )
return true ;
}
}
F_65 (nid, N_HIGH_MEMORY) {
if ( F_150 ( V_19 , V_10 -> V_173 ) )
continue;
if ( F_138 ( V_10 , V_19 , V_164 ) )
return true ;
}
return false ;
}
int F_144 ( struct V_9 * V_10 )
{
return 0 ;
}
static bool F_148 ( struct V_9 * V_10 , bool V_164 )
{
return F_138 ( V_10 , 0 , V_164 ) ;
}
static int F_151 ( struct V_9 * V_123 ,
struct V_48 * V_48 ,
T_3 V_163 ,
unsigned long * V_177 )
{
struct V_9 * V_178 = NULL ;
int V_78 = 0 ;
int V_165 = 0 ;
unsigned long V_45 ;
unsigned long V_179 ;
struct V_102 V_103 = {
. V_48 = V_48 ,
. V_111 = 0 ,
} ;
V_45 = F_37 ( & V_123 -> V_46 ) >> V_132 ;
while ( 1 ) {
V_178 = F_77 ( V_123 , V_178 , & V_103 ) ;
if ( ! V_178 ) {
V_165 ++ ;
if ( V_165 >= 2 ) {
if ( ! V_78 )
break;
if ( V_78 >= ( V_45 >> 2 ) ||
( V_165 > V_169 ) )
break;
}
continue;
}
if ( ! F_148 ( V_178 , false ) )
continue;
V_78 += F_152 ( V_178 , V_163 , false ,
V_48 , & V_179 ) ;
* V_177 += V_179 ;
if ( ! F_37 ( & V_123 -> V_46 ) )
break;
}
F_84 ( V_123 , V_178 ) ;
return V_78 ;
}
static bool F_153 ( struct V_9 * V_10 )
{
struct V_9 * V_109 , * V_180 = NULL ;
F_133 (iter, memcg) {
if ( V_109 -> V_181 ) {
V_180 = V_109 ;
F_84 ( V_10 , V_109 ) ;
break;
} else
V_109 -> V_181 = true ;
}
if ( ! V_180 )
return true ;
F_133 (iter, memcg) {
if ( V_109 == V_180 ) {
F_84 ( V_10 , V_109 ) ;
break;
}
V_109 -> V_181 = false ;
}
return false ;
}
static int F_154 ( struct V_9 * V_10 )
{
struct V_9 * V_109 ;
F_133 (iter, memcg)
V_109 -> V_181 = false ;
return 0 ;
}
static void F_155 ( struct V_9 * V_10 )
{
struct V_9 * V_109 ;
F_133 (iter, memcg)
F_72 ( & V_109 -> V_182 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
struct V_9 * V_109 ;
F_133 (iter, memcg)
F_157 ( & V_109 -> V_182 , - 1 , 0 ) ;
}
static int F_158 ( T_4 * V_146 ,
unsigned V_183 , int V_184 , void * V_185 )
{
struct V_9 * V_186 = (struct V_9 * ) V_185 ;
struct V_9 * V_187 ;
struct V_188 * V_188 ;
V_188 = F_59 ( V_146 , struct V_188 , V_146 ) ;
V_187 = V_188 -> V_10 ;
if ( ! F_97 ( V_187 , V_186 )
&& ! F_97 ( V_186 , V_187 ) )
return 0 ;
return F_159 ( V_146 , V_183 , V_184 , V_185 ) ;
}
static void F_160 ( struct V_9 * V_10 )
{
F_161 ( & V_189 , V_190 , 0 , V_10 ) ;
}
static void F_162 ( struct V_9 * V_10 )
{
if ( V_10 && F_116 ( & V_10 -> V_182 ) )
F_160 ( V_10 ) ;
}
static bool F_163 ( struct V_9 * V_10 , T_3 V_191 ,
int V_192 )
{
struct V_188 V_193 ;
bool V_194 , V_195 ;
V_193 . V_10 = V_10 ;
V_193 . V_146 . V_149 = 0 ;
V_193 . V_146 . V_196 = F_158 ;
V_193 . V_146 . V_197 = V_15 ;
F_164 ( & V_193 . V_146 . V_198 ) ;
V_195 = true ;
F_155 ( V_10 ) ;
F_33 ( & V_199 ) ;
V_194 = F_153 ( V_10 ) ;
F_120 ( & V_189 , & V_193 . V_146 , V_200 ) ;
if ( ! V_194 || V_10 -> V_201 )
V_195 = false ;
if ( V_194 )
F_165 ( V_10 ) ;
F_34 ( & V_199 ) ;
if ( V_195 ) {
F_122 ( & V_189 , & V_193 . V_146 ) ;
F_166 ( V_10 , V_191 , V_192 ) ;
} else {
F_121 () ;
F_122 ( & V_189 , & V_193 . V_146 ) ;
}
F_33 ( & V_199 ) ;
if ( V_194 )
F_154 ( V_10 ) ;
F_160 ( V_10 ) ;
F_34 ( & V_199 ) ;
F_156 ( V_10 ) ;
if ( F_167 ( V_202 ) || F_168 ( V_15 ) )
return false ;
F_169 ( 1 ) ;
return true ;
}
void F_170 ( struct V_26 * V_26 ,
bool * V_194 , unsigned long * V_149 )
{
struct V_9 * V_10 ;
struct V_121 * V_122 ;
V_122 = F_90 ( V_26 ) ;
V_203:
V_10 = V_122 -> V_9 ;
if ( F_70 ( ! V_10 || ! F_92 ( V_122 ) ) )
return;
if ( ! F_114 ( V_10 ) )
return;
F_123 ( V_10 , V_149 ) ;
if ( V_10 != V_122 -> V_9 || ! F_92 ( V_122 ) ) {
F_125 ( V_10 , V_149 ) ;
goto V_203;
}
* V_194 = true ;
}
void F_171 ( struct V_26 * V_26 , unsigned long * V_149 )
{
struct V_121 * V_122 = F_90 ( V_26 ) ;
F_125 ( V_122 -> V_9 , V_149 ) ;
}
void F_172 ( struct V_26 * V_26 ,
enum V_204 V_54 , int V_55 )
{
struct V_9 * V_10 ;
struct V_121 * V_122 = F_90 ( V_26 ) ;
unsigned long V_108 ( V_149 ) ;
if ( F_78 () )
return;
V_10 = V_122 -> V_9 ;
if ( F_70 ( ! V_10 || ! F_92 ( V_122 ) ) )
return;
switch ( V_54 ) {
case V_205 :
V_54 = V_206 ;
break;
default:
F_87 () ;
}
F_51 ( V_10 -> V_57 -> V_58 [ V_54 ] , V_55 ) ;
}
static bool F_173 ( struct V_9 * V_10 )
{
struct V_207 * V_208 ;
bool V_77 = true ;
V_208 = & F_174 ( V_209 ) ;
if ( V_10 == V_208 -> V_210 && V_208 -> V_66 )
V_208 -> V_66 -- ;
else
V_77 = false ;
F_175 ( V_209 ) ;
return V_77 ;
}
static void F_176 ( struct V_207 * V_208 )
{
struct V_9 * V_211 = V_208 -> V_210 ;
if ( V_208 -> V_66 ) {
unsigned long V_212 = V_208 -> V_66 * V_213 ;
F_177 ( & V_211 -> V_46 , V_212 ) ;
if ( V_136 )
F_177 ( & V_211 -> V_137 , V_212 ) ;
V_208 -> V_66 = 0 ;
}
V_208 -> V_210 = NULL ;
}
static void F_178 ( struct V_214 * V_215 )
{
struct V_207 * V_208 = & F_179 ( V_209 ) ;
F_176 ( V_208 ) ;
F_180 ( V_216 , & V_208 -> V_149 ) ;
}
static void F_181 ( struct V_9 * V_10 , unsigned int V_66 )
{
struct V_207 * V_208 = & F_174 ( V_209 ) ;
if ( V_208 -> V_210 != V_10 ) {
F_176 ( V_208 ) ;
V_208 -> V_210 = V_10 ;
}
V_208 -> V_66 += V_66 ;
F_175 ( V_209 ) ;
}
static void F_182 ( struct V_9 * V_123 , bool V_184 )
{
int V_56 , V_217 ;
F_45 () ;
V_217 = F_183 () ;
F_46 (cpu) {
struct V_207 * V_208 = & F_47 ( V_209 , V_56 ) ;
struct V_9 * V_10 ;
V_10 = V_208 -> V_210 ;
if ( ! V_10 || ! V_208 -> V_66 )
continue;
if ( ! F_97 ( V_123 , V_10 ) )
continue;
if ( ! F_184 ( V_216 , & V_208 -> V_149 ) ) {
if ( V_56 == V_217 )
F_178 ( & V_208 -> V_218 ) ;
else
F_185 ( V_56 , & V_208 -> V_218 ) ;
}
}
F_186 () ;
if ( ! V_184 )
goto V_116;
F_46 (cpu) {
struct V_207 * V_208 = & F_47 ( V_209 , V_56 ) ;
if ( F_2 ( V_216 , & V_208 -> V_149 ) )
F_187 ( & V_208 -> V_218 ) ;
}
V_116:
F_49 () ;
}
static void F_136 ( struct V_9 * V_123 )
{
if ( ! F_188 ( & V_219 ) )
return;
F_182 ( V_123 , false ) ;
F_189 ( & V_219 ) ;
}
static void F_190 ( struct V_9 * V_123 )
{
F_191 ( & V_219 ) ;
F_182 ( V_123 , true ) ;
F_189 ( & V_219 ) ;
}
static void F_192 ( struct V_9 * V_10 , int V_56 )
{
int V_220 ;
F_33 ( & V_10 -> V_59 ) ;
for ( V_220 = 0 ; V_220 < V_221 ; V_220 ++ ) {
long V_222 = F_47 ( V_10 -> V_57 -> V_58 [ V_220 ] , V_56 ) ;
F_47 ( V_10 -> V_57 -> V_58 [ V_220 ] , V_56 ) = 0 ;
V_10 -> V_60 . V_58 [ V_220 ] += V_222 ;
}
for ( V_220 = 0 ; V_220 < V_223 ; V_220 ++ ) {
unsigned long V_222 = F_47 ( V_10 -> V_57 -> V_64 [ V_220 ] , V_56 ) ;
F_47 ( V_10 -> V_57 -> V_64 [ V_220 ] , V_56 ) = 0 ;
V_10 -> V_60 . V_64 [ V_220 ] += V_222 ;
}
F_34 ( & V_10 -> V_59 ) ;
}
static int T_5 F_193 ( struct V_224 * V_225 ,
unsigned long V_226 ,
void * V_227 )
{
int V_56 = ( unsigned long ) V_227 ;
struct V_207 * V_208 ;
struct V_9 * V_109 ;
if ( V_226 == V_228 )
return V_229 ;
if ( V_226 != V_230 && V_226 != V_231 )
return V_229 ;
F_194 (iter)
F_192 ( V_109 , V_56 ) ;
V_208 = & F_47 ( V_209 , V_56 ) ;
F_176 ( V_208 ) ;
return V_229 ;
}
static int F_195 ( struct V_9 * V_10 , T_3 V_163 ,
unsigned int V_66 , bool V_232 )
{
unsigned long V_233 = V_66 * V_213 ;
struct V_9 * V_234 ;
struct V_235 * V_236 ;
unsigned long V_149 = 0 ;
int V_77 ;
V_77 = F_196 ( & V_10 -> V_46 , V_233 , & V_236 ) ;
if ( F_197 ( ! V_77 ) ) {
if ( ! V_136 )
return V_237 ;
V_77 = F_196 ( & V_10 -> V_137 , V_233 , & V_236 ) ;
if ( F_197 ( ! V_77 ) )
return V_237 ;
F_177 ( & V_10 -> V_46 , V_233 ) ;
V_234 = F_198 ( V_236 , V_137 ) ;
V_149 |= V_166 ;
} else
V_234 = F_198 ( V_236 , V_46 ) ;
if ( V_66 == V_238 )
return V_239 ;
if ( ! ( V_163 & V_240 ) )
return V_241 ;
V_77 = F_135 ( V_234 , V_163 , V_149 ) ;
if ( F_106 ( V_234 ) >= V_66 )
return V_239 ;
if ( V_66 == 1 && V_77 )
return V_239 ;
if ( F_118 ( V_234 ) )
return V_239 ;
if ( ! V_232 )
return V_242 ;
if ( ! F_163 ( V_234 , V_163 , F_199 ( V_233 ) ) )
return V_243 ;
return V_239 ;
}
static int F_200 ( struct V_97 * V_98 ,
T_3 V_163 ,
unsigned int V_66 ,
struct V_9 * * V_244 ,
bool V_245 )
{
unsigned int V_246 = F_201 ( V_238 , V_66 ) ;
int V_247 = V_248 ;
struct V_9 * V_10 = NULL ;
int V_77 ;
if ( F_70 ( F_167 ( V_202 )
|| F_168 ( V_15 ) ) )
goto V_249;
if ( ! * V_244 && ! V_98 )
* V_244 = V_105 ;
V_203:
if ( * V_244 ) {
V_10 = * V_244 ;
F_94 ( F_202 ( & V_10 -> V_25 ) ) ;
if ( F_6 ( V_10 ) )
goto V_52;
if ( V_66 == 1 && F_173 ( V_10 ) )
goto V_52;
F_102 ( & V_10 -> V_25 ) ;
} else {
struct V_96 * V_35 ;
F_8 () ;
V_35 = F_76 ( V_98 -> V_99 ) ;
V_10 = F_9 ( V_35 ) ;
if ( ! V_10 )
V_10 = V_105 ;
if ( F_6 ( V_10 ) ) {
F_11 () ;
goto V_52;
}
if ( V_66 == 1 && F_173 ( V_10 ) ) {
F_11 () ;
goto V_52;
}
if ( ! F_42 ( & V_10 -> V_25 ) ) {
F_11 () ;
goto V_203;
}
F_11 () ;
}
do {
bool V_232 ;
if ( F_168 ( V_15 ) ) {
F_80 ( & V_10 -> V_25 ) ;
goto V_249;
}
V_232 = false ;
if ( V_245 && ! V_247 ) {
V_232 = true ;
V_247 = V_248 ;
}
V_77 = F_195 ( V_10 , V_163 , V_246 , V_232 ) ;
switch ( V_77 ) {
case V_237 :
break;
case V_239 :
V_246 = V_66 ;
F_80 ( & V_10 -> V_25 ) ;
V_10 = NULL ;
goto V_203;
case V_241 :
F_80 ( & V_10 -> V_25 ) ;
goto V_250;
case V_242 :
if ( ! V_245 ) {
F_80 ( & V_10 -> V_25 ) ;
goto V_250;
}
V_247 -- ;
break;
case V_243 :
F_80 ( & V_10 -> V_25 ) ;
goto V_249;
}
} while ( V_77 != V_237 );
if ( V_246 > V_66 )
F_181 ( V_10 , V_246 - V_66 ) ;
F_80 ( & V_10 -> V_25 ) ;
V_52:
* V_244 = V_10 ;
return 0 ;
V_250:
* V_244 = NULL ;
return - V_251 ;
V_249:
* V_244 = V_105 ;
return - V_252 ;
}
static void F_203 ( struct V_9 * V_10 ,
unsigned int V_66 )
{
if ( ! F_6 ( V_10 ) ) {
unsigned long V_212 = V_66 * V_213 ;
F_177 ( & V_10 -> V_46 , V_212 ) ;
if ( V_136 )
F_177 ( & V_10 -> V_137 , V_212 ) ;
}
}
static void F_204 ( struct V_9 * V_10 ,
unsigned int V_66 )
{
unsigned long V_212 = V_66 * V_213 ;
if ( F_6 ( V_10 ) )
return;
F_205 ( & V_10 -> V_46 , V_10 -> V_46 . V_37 , V_212 ) ;
if ( V_136 )
F_205 ( & V_10 -> V_137 ,
V_10 -> V_137 . V_37 , V_212 ) ;
}
static struct V_9 * F_206 ( unsigned short V_104 )
{
struct V_24 * V_25 ;
if ( ! V_104 )
return NULL ;
V_25 = F_207 ( & V_114 , V_104 ) ;
if ( ! V_25 )
return NULL ;
return F_59 ( V_25 , struct V_9 , V_25 ) ;
}
struct V_9 * F_208 ( struct V_26 * V_26 )
{
struct V_9 * V_10 = NULL ;
struct V_121 * V_122 ;
unsigned short V_104 ;
T_6 V_253 ;
F_94 ( ! F_209 ( V_26 ) ) ;
V_122 = F_90 ( V_26 ) ;
F_210 ( V_122 ) ;
if ( F_92 ( V_122 ) ) {
V_10 = V_122 -> V_9 ;
if ( V_10 && ! F_42 ( & V_10 -> V_25 ) )
V_10 = NULL ;
} else if ( F_211 ( V_26 ) ) {
V_253 . V_55 = F_212 ( V_26 ) ;
V_104 = F_213 ( V_253 ) ;
F_8 () ;
V_10 = F_206 ( V_104 ) ;
if ( V_10 && ! F_42 ( & V_10 -> V_25 ) )
V_10 = NULL ;
F_11 () ;
}
F_214 ( V_122 ) ;
return V_10 ;
}
static void F_215 ( struct V_9 * V_10 ,
struct V_26 * V_26 ,
unsigned int V_66 ,
enum V_254 V_255 ,
bool V_256 )
{
struct V_121 * V_122 = F_90 ( V_26 ) ;
struct V_48 * V_108 ( V_48 ) ;
struct V_72 * V_72 ;
bool V_257 = false ;
bool V_65 ;
F_210 ( V_122 ) ;
if ( F_70 ( F_92 ( V_122 ) ) ) {
F_214 ( V_122 ) ;
F_203 ( V_10 , V_66 ) ;
return;
}
if ( V_256 ) {
V_48 = F_216 ( V_26 ) ;
F_217 ( & V_48 -> V_258 ) ;
if ( F_91 ( V_26 ) ) {
V_72 = F_88 ( V_48 , V_122 -> V_9 ) ;
F_218 ( V_26 ) ;
F_219 ( V_26 , V_72 , F_220 ( V_26 ) ) ;
V_257 = true ;
}
}
V_122 -> V_9 = V_10 ;
F_221 () ;
F_222 ( V_122 ) ;
if ( V_256 ) {
if ( V_257 ) {
V_72 = F_88 ( V_48 , V_122 -> V_9 ) ;
F_94 ( F_91 ( V_26 ) ) ;
F_223 ( V_26 ) ;
F_224 ( V_26 , V_72 , F_220 ( V_26 ) ) ;
}
F_225 ( & V_48 -> V_258 ) ;
}
if ( V_255 == V_259 )
V_65 = true ;
else
V_65 = false ;
F_53 ( V_10 , V_65 , V_66 ) ;
F_214 ( V_122 ) ;
F_69 ( V_10 , V_26 ) ;
}
void F_226 ( struct V_26 * V_260 )
{
struct V_121 * V_261 = F_90 ( V_260 ) ;
struct V_121 * V_122 ;
int V_220 ;
if ( F_78 () )
return;
for ( V_220 = 1 ; V_220 < V_262 ; V_220 ++ ) {
V_122 = V_261 + V_220 ;
V_122 -> V_9 = V_261 -> V_9 ;
F_221 () ;
V_122 -> V_149 = V_261 -> V_149 & ~ V_263 ;
}
}
static int F_227 ( struct V_26 * V_26 ,
unsigned int V_66 ,
struct V_121 * V_122 ,
struct V_9 * V_143 ,
struct V_9 * V_3 )
{
unsigned long V_149 ;
int V_77 ;
bool V_65 = F_228 ( V_26 ) ;
F_94 ( V_143 == V_3 ) ;
F_94 ( F_91 ( V_26 ) ) ;
V_77 = - V_264 ;
if ( V_66 > 1 && ! F_229 ( V_26 ) )
goto V_116;
F_210 ( V_122 ) ;
V_77 = - V_265 ;
if ( ! F_92 ( V_122 ) || V_122 -> V_9 != V_143 )
goto V_144;
F_123 ( V_143 , & V_149 ) ;
if ( ! V_65 && F_230 ( V_26 ) ) {
F_54 () ;
F_231 ( V_143 -> V_57 -> V_58 [ V_206 ] ) ;
F_56 ( V_3 -> V_57 -> V_58 [ V_206 ] ) ;
F_57 () ;
}
F_53 ( V_143 , V_65 , - V_66 ) ;
V_122 -> V_9 = V_3 ;
F_53 ( V_3 , V_65 , V_66 ) ;
F_125 ( V_143 , & V_149 ) ;
V_77 = 0 ;
V_144:
F_214 ( V_122 ) ;
F_69 ( V_3 , V_26 ) ;
F_69 ( V_143 , V_26 ) ;
V_116:
return V_77 ;
}
static int F_232 ( struct V_26 * V_26 ,
struct V_121 * V_122 ,
struct V_9 * V_266 ,
T_3 V_163 )
{
struct V_9 * V_37 ;
unsigned int V_66 ;
unsigned long V_108 ( V_149 ) ;
int V_77 ;
if ( F_6 ( V_266 ) )
return - V_265 ;
V_77 = - V_264 ;
if ( ! F_233 ( V_26 ) )
goto V_116;
if ( F_234 ( V_26 ) )
goto V_267;
V_66 = F_235 ( V_26 ) ;
V_37 = F_36 ( V_266 ) ;
if ( ! V_37 )
V_37 = V_105 ;
if ( V_66 > 1 )
V_149 = F_236 ( V_26 ) ;
V_77 = F_227 ( V_26 , V_66 ,
V_122 , V_266 , V_37 ) ;
if ( ! V_77 )
F_204 ( V_266 , V_66 ) ;
if ( V_66 > 1 )
F_237 ( V_26 , V_149 ) ;
F_238 ( V_26 ) ;
V_267:
F_239 ( V_26 ) ;
V_116:
return V_77 ;
}
static int F_240 ( struct V_26 * V_26 , struct V_97 * V_98 ,
T_3 V_163 , enum V_254 V_255 )
{
struct V_9 * V_10 = NULL ;
unsigned int V_66 = 1 ;
bool V_245 = true ;
int V_77 ;
if ( F_229 ( V_26 ) ) {
V_66 <<= F_241 ( V_26 ) ;
F_94 ( ! F_229 ( V_26 ) ) ;
V_245 = false ;
}
V_77 = F_200 ( V_98 , V_163 , V_66 , & V_10 , V_245 ) ;
if ( V_77 == - V_251 )
return V_77 ;
F_215 ( V_10 , V_26 , V_66 , V_255 , false ) ;
return 0 ;
}
int F_242 ( struct V_26 * V_26 ,
struct V_97 * V_98 , T_3 V_163 )
{
if ( F_78 () )
return 0 ;
F_94 ( F_230 ( V_26 ) ) ;
F_94 ( V_26 -> V_268 && ! F_228 ( V_26 ) ) ;
F_94 ( ! V_98 ) ;
return F_240 ( V_26 , V_98 , V_163 ,
V_259 ) ;
}
int F_243 ( struct V_26 * V_26 , struct V_97 * V_98 ,
T_3 V_163 )
{
struct V_9 * V_10 = NULL ;
enum V_254 type = V_269 ;
int V_77 ;
if ( F_78 () )
return 0 ;
if ( F_244 ( V_26 ) )
return 0 ;
if ( F_70 ( ! V_98 ) )
V_98 = & V_270 ;
if ( ! F_245 ( V_26 ) )
type = V_271 ;
if ( ! F_211 ( V_26 ) )
V_77 = F_240 ( V_26 , V_98 , V_163 , type ) ;
else {
V_77 = F_246 ( V_98 , V_26 , V_163 , & V_10 ) ;
if ( ! V_77 )
F_247 ( V_26 , V_10 , type ) ;
}
return V_77 ;
}
int F_246 ( struct V_97 * V_98 ,
struct V_26 * V_26 ,
T_3 V_191 , struct V_9 * * V_272 )
{
struct V_9 * V_10 ;
int V_77 ;
* V_272 = NULL ;
if ( F_78 () )
return 0 ;
if ( ! V_136 )
goto V_273;
if ( ! F_211 ( V_26 ) )
goto V_273;
V_10 = F_208 ( V_26 ) ;
if ( ! V_10 )
goto V_273;
* V_272 = V_10 ;
V_77 = F_200 ( NULL , V_191 , 1 , V_272 , true ) ;
F_80 ( & V_10 -> V_25 ) ;
if ( V_77 == - V_252 )
V_77 = 0 ;
return V_77 ;
V_273:
if ( F_70 ( ! V_98 ) )
V_98 = & V_270 ;
V_77 = F_200 ( V_98 , V_191 , 1 , V_272 , true ) ;
if ( V_77 == - V_252 )
V_77 = 0 ;
return V_77 ;
}
static void
F_247 ( struct V_26 * V_26 , struct V_9 * V_10 ,
enum V_254 V_255 )
{
if ( F_78 () )
return;
if ( ! V_10 )
return;
F_248 ( & V_10 -> V_25 ) ;
F_215 ( V_10 , V_26 , 1 , V_255 , true ) ;
if ( V_136 && F_211 ( V_26 ) ) {
T_6 V_253 = { . V_55 = F_212 (page) } ;
F_249 ( V_253 ) ;
}
F_250 ( & V_10 -> V_25 ) ;
}
void F_251 ( struct V_26 * V_26 ,
struct V_9 * V_10 )
{
F_247 ( V_26 , V_10 ,
V_259 ) ;
}
void F_252 ( struct V_9 * V_10 )
{
if ( F_78 () )
return;
if ( ! V_10 )
return;
F_203 ( V_10 , 1 ) ;
}
static void F_253 ( struct V_9 * V_10 ,
unsigned int V_66 ,
const enum V_254 V_255 )
{
struct V_274 * V_246 = NULL ;
bool V_275 = true ;
if ( ! V_136 || V_255 == V_276 )
V_275 = false ;
V_246 = & V_15 -> V_277 ;
if ( ! V_246 -> V_10 )
V_246 -> V_10 = V_10 ;
if ( ! V_246 -> V_278 || F_167 ( V_202 ) )
goto V_279;
if ( V_66 > 1 )
goto V_279;
if ( V_246 -> V_10 != V_10 )
goto V_279;
V_246 -> V_66 ++ ;
if ( V_275 )
V_246 -> V_280 ++ ;
return;
V_279:
F_177 ( & V_10 -> V_46 , V_66 * V_213 ) ;
if ( V_275 )
F_177 ( & V_10 -> V_137 , V_66 * V_213 ) ;
if ( F_70 ( V_246 -> V_10 != V_10 ) )
F_162 ( V_10 ) ;
}
static struct V_9 *
F_254 ( struct V_26 * V_26 , enum V_254 V_255 )
{
struct V_9 * V_10 = NULL ;
unsigned int V_66 = 1 ;
struct V_121 * V_122 ;
bool V_65 ;
if ( F_78 () )
return NULL ;
if ( F_211 ( V_26 ) )
return NULL ;
if ( F_229 ( V_26 ) ) {
V_66 <<= F_241 ( V_26 ) ;
F_94 ( ! F_229 ( V_26 ) ) ;
}
V_122 = F_90 ( V_26 ) ;
if ( F_70 ( ! F_92 ( V_122 ) ) )
return NULL ;
F_210 ( V_122 ) ;
V_10 = V_122 -> V_9 ;
if ( ! F_92 ( V_122 ) )
goto V_281;
V_65 = F_228 ( V_26 ) ;
switch ( V_255 ) {
case V_259 :
V_65 = true ;
case V_282 :
if ( F_230 ( V_26 ) || F_255 ( V_122 ) )
goto V_281;
break;
case V_276 :
if ( ! F_228 ( V_26 ) ) {
if ( V_26 -> V_268 && ! F_245 ( V_26 ) )
goto V_281;
} else if ( F_230 ( V_26 ) )
goto V_281;
break;
default:
break;
}
F_53 ( V_10 , V_65 , - V_66 ) ;
F_256 ( V_122 ) ;
F_214 ( V_122 ) ;
F_69 ( V_10 , V_26 ) ;
if ( V_136 && V_255 == V_276 ) {
F_50 ( V_10 , true ) ;
F_7 ( V_10 ) ;
}
if ( ! F_6 ( V_10 ) )
F_253 ( V_10 , V_66 , V_255 ) ;
return V_10 ;
V_281:
F_214 ( V_122 ) ;
return NULL ;
}
void F_257 ( struct V_26 * V_26 )
{
if ( F_230 ( V_26 ) )
return;
F_94 ( V_26 -> V_268 && ! F_228 ( V_26 ) ) ;
F_254 ( V_26 , V_259 ) ;
}
void F_258 ( struct V_26 * V_26 )
{
F_94 ( F_230 ( V_26 ) ) ;
F_94 ( V_26 -> V_268 ) ;
F_254 ( V_26 , V_269 ) ;
}
void F_259 ( void )
{
V_15 -> V_277 . V_278 ++ ;
if ( V_15 -> V_277 . V_278 == 1 ) {
V_15 -> V_277 . V_10 = NULL ;
V_15 -> V_277 . V_66 = 0 ;
V_15 -> V_277 . V_280 = 0 ;
}
}
void F_260 ( void )
{
struct V_274 * V_246 = & V_15 -> V_277 ;
if ( ! V_246 -> V_278 )
return;
V_246 -> V_278 -- ;
if ( V_246 -> V_278 )
return;
if ( ! V_246 -> V_10 )
return;
if ( V_246 -> V_66 )
F_177 ( & V_246 -> V_10 -> V_46 ,
V_246 -> V_66 * V_213 ) ;
if ( V_246 -> V_280 )
F_177 ( & V_246 -> V_10 -> V_137 ,
V_246 -> V_280 * V_213 ) ;
F_162 ( V_246 -> V_10 ) ;
V_246 -> V_10 = NULL ;
}
void
F_261 ( struct V_26 * V_26 , T_6 V_253 , bool V_283 )
{
struct V_9 * V_10 ;
int V_255 = V_276 ;
if ( ! V_283 )
V_255 = V_282 ;
V_10 = F_254 ( V_26 , V_255 ) ;
if ( V_136 && V_283 && V_10 )
F_262 ( V_253 , F_79 ( & V_10 -> V_25 ) ) ;
}
void F_249 ( T_6 V_253 )
{
struct V_9 * V_10 ;
unsigned short V_104 ;
if ( ! V_136 )
return;
V_104 = F_262 ( V_253 , 0 ) ;
F_8 () ;
V_10 = F_206 ( V_104 ) ;
if ( V_10 ) {
if ( ! F_6 ( V_10 ) )
F_177 ( & V_10 -> V_137 , V_213 ) ;
F_50 ( V_10 , false ) ;
F_14 ( V_10 ) ;
}
F_11 () ;
}
static int F_263 ( T_6 V_284 ,
struct V_9 * V_143 , struct V_9 * V_3 )
{
unsigned short V_285 , V_286 ;
V_285 = F_79 ( & V_143 -> V_25 ) ;
V_286 = F_79 ( & V_3 -> V_25 ) ;
if ( F_264 ( V_284 , V_285 , V_286 ) == V_285 ) {
F_50 ( V_143 , false ) ;
F_50 ( V_3 , true ) ;
F_7 ( V_3 ) ;
return 0 ;
}
return - V_265 ;
}
static inline int F_263 ( T_6 V_284 ,
struct V_9 * V_143 , struct V_9 * V_3 )
{
return - V_265 ;
}
int F_265 ( struct V_26 * V_26 ,
struct V_26 * V_287 , struct V_9 * * V_272 , T_3 V_163 )
{
struct V_9 * V_10 = NULL ;
struct V_121 * V_122 ;
enum V_254 V_255 ;
int V_77 = 0 ;
* V_272 = NULL ;
F_94 ( F_229 ( V_26 ) ) ;
if ( F_78 () )
return 0 ;
V_122 = F_90 ( V_26 ) ;
F_210 ( V_122 ) ;
if ( F_92 ( V_122 ) ) {
V_10 = V_122 -> V_9 ;
F_102 ( & V_10 -> V_25 ) ;
if ( F_228 ( V_26 ) )
F_266 ( V_122 ) ;
}
F_214 ( V_122 ) ;
if ( ! V_10 )
return 0 ;
* V_272 = V_10 ;
V_77 = F_200 ( NULL , V_163 , 1 , V_272 , false ) ;
F_80 ( & V_10 -> V_25 ) ;
if ( V_77 ) {
if ( F_228 ( V_26 ) ) {
F_210 ( V_122 ) ;
F_267 ( V_122 ) ;
F_214 ( V_122 ) ;
F_257 ( V_26 ) ;
}
return - V_251 ;
}
if ( F_228 ( V_26 ) )
V_255 = V_259 ;
else if ( F_245 ( V_26 ) )
V_255 = V_269 ;
else
V_255 = V_271 ;
F_215 ( V_10 , V_287 , 1 , V_255 , false ) ;
return V_77 ;
}
void F_268 ( struct V_9 * V_10 ,
struct V_26 * V_288 , struct V_26 * V_287 , bool V_289 )
{
struct V_26 * V_290 , * V_291 ;
struct V_121 * V_122 ;
bool V_65 ;
if ( ! V_10 )
return;
F_248 ( & V_10 -> V_25 ) ;
if ( ! V_289 ) {
V_290 = V_288 ;
V_291 = V_287 ;
} else {
V_290 = V_287 ;
V_291 = V_288 ;
}
V_122 = F_90 ( V_288 ) ;
F_210 ( V_122 ) ;
F_267 ( V_122 ) ;
F_214 ( V_122 ) ;
V_65 = F_228 ( V_290 ) ;
F_254 ( V_291 ,
V_65 ? V_259
: V_269 ) ;
if ( V_65 )
F_257 ( V_290 ) ;
F_250 ( & V_10 -> V_25 ) ;
}
void F_269 ( struct V_26 * V_288 ,
struct V_26 * V_287 )
{
struct V_9 * V_10 = NULL ;
struct V_121 * V_122 ;
enum V_254 type = V_269 ;
if ( F_78 () )
return;
V_122 = F_90 ( V_288 ) ;
F_210 ( V_122 ) ;
if ( F_92 ( V_122 ) ) {
V_10 = V_122 -> V_9 ;
F_53 ( V_10 , false , - 1 ) ;
F_256 ( V_122 ) ;
}
F_214 ( V_122 ) ;
if ( ! V_10 )
return;
if ( F_270 ( V_288 ) )
type = V_271 ;
F_215 ( V_10 , V_287 , 1 , type , true ) ;
}
static struct V_121 * F_271 ( struct V_26 * V_26 )
{
struct V_121 * V_122 ;
V_122 = F_90 ( V_26 ) ;
if ( F_197 ( V_122 ) && F_92 ( V_122 ) )
return V_122 ;
return NULL ;
}
bool F_272 ( struct V_26 * V_26 )
{
if ( F_78 () )
return false ;
return F_271 ( V_26 ) != NULL ;
}
void F_273 ( struct V_26 * V_26 )
{
struct V_121 * V_122 ;
V_122 = F_271 ( V_26 ) ;
if ( V_122 ) {
F_130 ( V_292 L_6 ,
V_122 , V_122 -> V_149 , V_122 -> V_9 ) ;
}
}
static int F_274 ( struct V_9 * V_10 ,
unsigned long long V_55 )
{
int V_293 ;
T_1 V_294 , V_295 ;
int V_77 = 0 ;
int V_296 = F_132 ( V_10 ) ;
T_1 V_297 , V_298 ;
int V_299 ;
V_293 = V_248 * V_296 ;
V_298 = F_131 ( & V_10 -> V_46 , V_157 ) ;
V_299 = 0 ;
while ( V_293 ) {
if ( F_275 ( V_15 ) ) {
V_77 = - V_252 ;
break;
}
F_191 ( & V_300 ) ;
V_294 = F_131 ( & V_10 -> V_137 , V_158 ) ;
if ( V_294 < V_55 ) {
V_77 = - V_265 ;
F_189 ( & V_300 ) ;
break;
}
V_295 = F_131 ( & V_10 -> V_46 , V_158 ) ;
if ( V_295 < V_55 )
V_299 = 1 ;
V_77 = F_276 ( & V_10 -> V_46 , V_55 ) ;
if ( ! V_77 ) {
if ( V_294 == V_55 )
V_10 -> V_168 = true ;
else
V_10 -> V_168 = false ;
}
F_189 ( & V_300 ) ;
if ( ! V_77 )
break;
F_135 ( V_10 , V_301 ,
V_167 ) ;
V_297 = F_131 ( & V_10 -> V_46 , V_157 ) ;
if ( V_297 >= V_298 )
V_293 -- ;
else
V_298 = V_297 ;
}
if ( ! V_77 && V_299 )
F_162 ( V_10 ) ;
return V_77 ;
}
static int F_277 ( struct V_9 * V_10 ,
unsigned long long V_55 )
{
int V_293 ;
T_1 V_295 , V_294 , V_298 , V_297 ;
int V_296 = F_132 ( V_10 ) ;
int V_77 = - V_264 ;
int V_299 = 0 ;
V_293 = V_296 * V_248 ;
V_298 = F_131 ( & V_10 -> V_137 , V_157 ) ;
while ( V_293 ) {
if ( F_275 ( V_15 ) ) {
V_77 = - V_252 ;
break;
}
F_191 ( & V_300 ) ;
V_295 = F_131 ( & V_10 -> V_46 , V_158 ) ;
if ( V_295 > V_55 ) {
V_77 = - V_265 ;
F_189 ( & V_300 ) ;
break;
}
V_294 = F_131 ( & V_10 -> V_137 , V_158 ) ;
if ( V_294 < V_55 )
V_299 = 1 ;
V_77 = F_276 ( & V_10 -> V_137 , V_55 ) ;
if ( ! V_77 ) {
if ( V_295 == V_55 )
V_10 -> V_168 = true ;
else
V_10 -> V_168 = false ;
}
F_189 ( & V_300 ) ;
if ( ! V_77 )
break;
F_135 ( V_10 , V_301 ,
V_166 |
V_167 ) ;
V_297 = F_131 ( & V_10 -> V_137 , V_157 ) ;
if ( V_297 >= V_298 )
V_293 -- ;
else
V_298 = V_297 ;
}
if ( ! V_77 && V_299 )
F_162 ( V_10 ) ;
return V_77 ;
}
unsigned long F_278 ( struct V_48 * V_48 , int V_192 ,
T_3 V_163 ,
unsigned long * V_177 )
{
unsigned long V_302 = 0 ;
struct V_18 * V_31 , * V_303 = NULL ;
unsigned long V_304 ;
int V_165 = 0 ;
struct V_27 * V_32 ;
unsigned long long V_45 ;
unsigned long V_179 ;
if ( V_192 > 0 )
return 0 ;
V_32 = F_24 ( F_81 ( V_48 ) , F_82 ( V_48 ) ) ;
do {
if ( V_303 )
V_31 = V_303 ;
else
V_31 = F_43 ( V_32 ) ;
if ( ! V_31 )
break;
V_179 = 0 ;
V_304 = F_151 ( V_31 -> V_10 , V_48 ,
V_163 , & V_179 ) ;
V_302 += V_304 ;
* V_177 += V_179 ;
F_33 ( & V_32 -> V_44 ) ;
V_303 = NULL ;
if ( ! V_304 ) {
do {
V_303 =
F_40 ( V_32 ) ;
if ( V_303 == V_31 )
F_80 ( & V_303 -> V_10 -> V_25 ) ;
else
break;
} while ( 1 );
}
F_30 ( V_31 -> V_10 , V_31 , V_32 ) ;
V_45 = F_37 ( & V_31 -> V_10 -> V_46 ) ;
F_26 ( V_31 -> V_10 , V_31 , V_32 , V_45 ) ;
F_34 ( & V_32 -> V_44 ) ;
F_80 ( & V_31 -> V_10 -> V_25 ) ;
V_165 ++ ;
if ( ! V_302 &&
( V_303 == NULL ||
V_165 > V_305 ) )
break;
} while ( ! V_302 );
if ( V_303 )
F_80 ( & V_303 -> V_10 -> V_25 ) ;
return V_302 ;
}
static int F_279 ( struct V_9 * V_10 ,
int V_47 , int V_20 , enum V_73 V_74 )
{
struct V_18 * V_31 ;
unsigned long V_149 , V_165 ;
struct V_306 * V_307 ;
struct V_26 * V_308 ;
struct V_48 * V_48 ;
int V_77 = 0 ;
V_48 = & F_280 ( V_47 ) -> V_309 [ V_20 ] ;
V_31 = F_19 ( V_10 , V_47 , V_20 ) ;
V_307 = & V_31 -> V_72 . V_310 [ V_74 ] ;
V_165 = V_31 -> V_75 [ V_74 ] ;
V_165 += 256 ;
V_308 = NULL ;
while ( V_165 -- ) {
struct V_121 * V_122 ;
struct V_26 * V_26 ;
V_77 = 0 ;
F_124 ( & V_48 -> V_258 , V_149 ) ;
if ( F_281 ( V_307 ) ) {
F_126 ( & V_48 -> V_258 , V_149 ) ;
break;
}
V_26 = F_282 ( V_307 -> V_101 , struct V_26 , V_74 ) ;
if ( V_308 == V_26 ) {
F_283 ( & V_26 -> V_74 , V_307 ) ;
V_308 = NULL ;
F_126 ( & V_48 -> V_258 , V_149 ) ;
continue;
}
F_126 ( & V_48 -> V_258 , V_149 ) ;
V_122 = F_90 ( V_26 ) ;
V_77 = F_232 ( V_26 , V_122 , V_10 , V_301 ) ;
if ( V_77 == - V_251 || V_77 == - V_252 )
break;
if ( V_77 == - V_264 || V_77 == - V_265 ) {
V_308 = V_26 ;
F_284 () ;
} else
V_308 = NULL ;
}
if ( ! V_77 && ! F_281 ( V_307 ) )
return - V_264 ;
return V_77 ;
}
static int F_285 ( struct V_9 * V_10 , bool V_311 )
{
int V_77 ;
int V_47 , V_20 , V_312 ;
int V_313 = V_248 ;
struct V_93 * V_138 = V_10 -> V_25 . V_93 ;
F_102 ( & V_10 -> V_25 ) ;
V_312 = 0 ;
if ( V_311 )
goto V_314;
V_315:
do {
V_77 = - V_264 ;
if ( F_286 ( V_138 ) || ! F_281 ( & V_138 -> V_296 ) )
goto V_116;
V_77 = - V_252 ;
if ( F_275 ( V_15 ) )
goto V_116;
F_287 () ;
F_190 ( V_10 ) ;
V_77 = 0 ;
F_110 ( V_10 ) ;
F_65 (node, N_HIGH_MEMORY) {
for ( V_20 = 0 ; ! V_77 && V_20 < V_49 ; V_20 ++ ) {
enum V_73 V_74 ;
F_61 (lru) {
V_77 = F_279 ( V_10 ,
V_47 , V_20 , V_74 ) ;
if ( V_77 )
break;
}
}
if ( V_77 )
break;
}
F_112 ( V_10 ) ;
F_162 ( V_10 ) ;
if ( V_77 == - V_251 )
goto V_314;
F_284 () ;
} while ( F_131 ( & V_10 -> V_46 , V_157 ) > 0 || V_77 );
V_116:
F_80 ( & V_10 -> V_25 ) ;
return V_77 ;
V_314:
if ( F_286 ( V_138 ) || ! F_281 ( & V_138 -> V_296 ) || V_312 ) {
V_77 = - V_264 ;
goto V_116;
}
F_287 () ;
V_312 = 1 ;
while ( V_313 && F_131 ( & V_10 -> V_46 , V_157 ) > 0 ) {
int V_316 ;
if ( F_275 ( V_15 ) ) {
V_77 = - V_252 ;
goto V_116;
}
V_316 = F_137 ( V_10 , V_301 ,
false ) ;
if ( ! V_316 ) {
V_313 -- ;
F_288 ( V_317 , V_318 / 10 ) ;
}
}
F_289 () ;
goto V_315;
}
static int F_290 ( struct V_93 * V_94 , unsigned int V_319 )
{
return F_285 ( F_73 ( V_94 ) , true ) ;
}
static T_1 F_291 ( struct V_93 * V_94 , struct V_320 * V_321 )
{
return F_73 ( V_94 ) -> V_106 ;
}
static int F_292 ( struct V_93 * V_94 , struct V_320 * V_321 ,
T_1 V_55 )
{
int V_322 = 0 ;
struct V_9 * V_10 = F_73 ( V_94 ) ;
struct V_93 * V_37 = V_94 -> V_37 ;
struct V_9 * V_323 = NULL ;
if ( V_37 )
V_323 = F_73 ( V_37 ) ;
F_293 () ;
if ( ( ! V_323 || ! V_323 -> V_106 ) &&
( V_55 == 1 || V_55 == 0 ) ) {
if ( F_281 ( & V_94 -> V_296 ) )
V_10 -> V_106 = V_55 ;
else
V_322 = - V_264 ;
} else
V_322 = - V_265 ;
F_294 () ;
return V_322 ;
}
static unsigned long F_295 ( struct V_9 * V_10 ,
enum V_53 V_54 )
{
struct V_9 * V_109 ;
long V_55 = 0 ;
F_133 (iter, memcg)
V_55 += F_44 ( V_109 , V_54 ) ;
if ( V_55 < 0 )
V_55 = 0 ;
return V_55 ;
}
static inline T_1 F_296 ( struct V_9 * V_10 , bool V_324 )
{
T_1 V_55 ;
if ( ! F_6 ( V_10 ) ) {
if ( ! V_324 )
return F_131 ( & V_10 -> V_46 , V_157 ) ;
else
return F_131 ( & V_10 -> V_137 , V_157 ) ;
}
V_55 = F_295 ( V_10 , V_68 ) ;
V_55 += F_295 ( V_10 , V_67 ) ;
if ( V_324 )
V_55 += F_295 ( V_10 , V_62 ) ;
return V_55 << V_132 ;
}
static T_7 F_297 ( struct V_93 * V_94 , struct V_320 * V_321 ,
struct V_325 * V_325 , char T_8 * V_326 ,
T_9 V_327 , T_10 * V_328 )
{
struct V_9 * V_10 = F_73 ( V_94 ) ;
char V_329 [ 64 ] ;
T_1 V_55 ;
int type , V_330 , V_331 ;
type = F_298 ( V_321 -> V_197 ) ;
V_330 = F_299 ( V_321 -> V_197 ) ;
if ( ! V_136 && type == V_332 )
return - V_333 ;
switch ( type ) {
case V_334 :
if ( V_330 == V_157 )
V_55 = F_296 ( V_10 , false ) ;
else
V_55 = F_131 ( & V_10 -> V_46 , V_330 ) ;
break;
case V_332 :
if ( V_330 == V_157 )
V_55 = F_296 ( V_10 , true ) ;
else
V_55 = F_131 ( & V_10 -> V_137 , V_330 ) ;
break;
default:
F_87 () ;
}
V_331 = F_300 ( V_329 , sizeof( V_329 ) , L_7 , ( unsigned long long ) V_55 ) ;
return F_301 ( V_326 , V_327 , V_328 , V_329 , V_331 ) ;
}
static int F_302 ( struct V_93 * V_94 , struct V_320 * V_321 ,
const char * V_335 )
{
struct V_9 * V_10 = F_73 ( V_94 ) ;
int type , V_330 ;
unsigned long long V_55 ;
int V_77 ;
type = F_298 ( V_321 -> V_197 ) ;
V_330 = F_299 ( V_321 -> V_197 ) ;
if ( ! V_136 && type == V_332 )
return - V_333 ;
switch ( V_330 ) {
case V_158 :
if ( F_6 ( V_10 ) ) {
V_77 = - V_265 ;
break;
}
V_77 = F_303 ( V_335 , & V_55 ) ;
if ( V_77 )
break;
if ( type == V_334 )
V_77 = F_274 ( V_10 , V_55 ) ;
else
V_77 = F_277 ( V_10 , V_55 ) ;
break;
case V_336 :
V_77 = F_303 ( V_335 , & V_55 ) ;
if ( V_77 )
break;
if ( type == V_334 )
V_77 = F_304 ( & V_10 -> V_46 , V_55 ) ;
else
V_77 = - V_265 ;
break;
default:
V_77 = - V_265 ;
break;
}
return V_77 ;
}
static void F_305 ( struct V_9 * V_10 ,
unsigned long long * V_337 , unsigned long long * V_338 )
{
struct V_93 * V_93 ;
unsigned long long V_339 , V_340 , V_341 ;
V_339 = F_131 ( & V_10 -> V_46 , V_158 ) ;
V_340 = F_131 ( & V_10 -> V_137 , V_158 ) ;
V_93 = V_10 -> V_25 . V_93 ;
if ( ! V_10 -> V_106 )
goto V_116;
while ( V_93 -> V_37 ) {
V_93 = V_93 -> V_37 ;
V_10 = F_73 ( V_93 ) ;
if ( ! V_10 -> V_106 )
break;
V_341 = F_131 ( & V_10 -> V_46 , V_158 ) ;
V_339 = F_108 ( V_339 , V_341 ) ;
V_341 = F_131 ( & V_10 -> V_137 , V_158 ) ;
V_340 = F_108 ( V_340 , V_341 ) ;
}
V_116:
* V_337 = V_339 ;
* V_338 = V_340 ;
}
static int F_306 ( struct V_93 * V_94 , unsigned int V_319 )
{
struct V_9 * V_10 = F_73 ( V_94 ) ;
int type , V_330 ;
type = F_298 ( V_319 ) ;
V_330 = F_299 ( V_319 ) ;
if ( ! V_136 && type == V_332 )
return - V_333 ;
switch ( V_330 ) {
case V_342 :
if ( type == V_334 )
F_307 ( & V_10 -> V_46 ) ;
else
F_307 ( & V_10 -> V_137 ) ;
break;
case V_159 :
if ( type == V_334 )
F_308 ( & V_10 -> V_46 ) ;
else
F_308 ( & V_10 -> V_137 ) ;
break;
}
return 0 ;
}
static T_1 F_309 ( struct V_93 * V_138 ,
struct V_320 * V_321 )
{
return F_73 ( V_138 ) -> V_4 ;
}
static int F_310 ( struct V_93 * V_138 ,
struct V_320 * V_321 , T_1 V_55 )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
if ( V_55 >= ( 1 << V_343 ) )
return - V_265 ;
F_293 () ;
V_10 -> V_4 = V_55 ;
F_294 () ;
return 0 ;
}
static int F_310 ( struct V_93 * V_138 ,
struct V_320 * V_321 , T_1 V_55 )
{
return - V_344 ;
}
static int F_311 ( struct V_93 * V_94 , struct V_320 * V_321 ,
struct V_345 * V_346 )
{
int V_19 ;
unsigned long V_347 , V_348 , V_349 , V_350 ;
unsigned long V_351 ;
struct V_9 * V_10 = F_73 ( V_94 ) ;
V_347 = F_64 ( V_10 , V_352 ) ;
F_312 ( V_346 , L_8 , V_347 ) ;
F_65 (nid, N_HIGH_MEMORY) {
V_351 = F_63 ( V_10 , V_19 , V_352 ) ;
F_312 ( V_346 , L_9 , V_19 , V_351 ) ;
}
F_313 ( V_346 , '\n' ) ;
V_348 = F_64 ( V_10 , V_170 ) ;
F_312 ( V_346 , L_10 , V_348 ) ;
F_65 (nid, N_HIGH_MEMORY) {
V_351 = F_63 ( V_10 , V_19 ,
V_170 ) ;
F_312 ( V_346 , L_9 , V_19 , V_351 ) ;
}
F_313 ( V_346 , '\n' ) ;
V_349 = F_64 ( V_10 , V_171 ) ;
F_312 ( V_346 , L_11 , V_349 ) ;
F_65 (nid, N_HIGH_MEMORY) {
V_351 = F_63 ( V_10 , V_19 ,
V_171 ) ;
F_312 ( V_346 , L_9 , V_19 , V_351 ) ;
}
F_313 ( V_346 , '\n' ) ;
V_350 = F_64 ( V_10 , F_62 ( V_353 ) ) ;
F_312 ( V_346 , L_12 , V_350 ) ;
F_65 (nid, N_HIGH_MEMORY) {
V_351 = F_63 ( V_10 , V_19 ,
F_62 ( V_353 ) ) ;
F_312 ( V_346 , L_9 , V_19 , V_351 ) ;
}
F_313 ( V_346 , '\n' ) ;
return 0 ;
}
static inline void F_314 ( void )
{
F_315 ( F_316 ( V_354 ) != V_355 ) ;
}
static int F_317 ( struct V_93 * V_94 , struct V_320 * V_321 ,
struct V_345 * V_346 )
{
struct V_9 * V_10 = F_73 ( V_94 ) ;
struct V_9 * V_356 ;
unsigned int V_220 ;
for ( V_220 = 0 ; V_220 < V_221 ; V_220 ++ ) {
if ( V_220 == V_62 && ! V_136 )
continue;
F_312 ( V_346 , L_13 , V_357 [ V_220 ] ,
F_44 ( V_10 , V_220 ) * V_213 ) ;
}
for ( V_220 = 0 ; V_220 < V_223 ; V_220 ++ )
F_312 ( V_346 , L_14 , V_358 [ V_220 ] ,
F_52 ( V_10 , V_220 ) ) ;
for ( V_220 = 0 ; V_220 < V_355 ; V_220 ++ )
F_312 ( V_346 , L_14 , V_354 [ V_220 ] ,
F_64 ( V_10 , F_62 ( V_220 ) ) * V_213 ) ;
{
unsigned long long V_161 , V_338 ;
F_305 ( V_10 , & V_161 , & V_338 ) ;
F_312 ( V_346 , L_15 , V_161 ) ;
if ( V_136 )
F_312 ( V_346 , L_16 ,
V_338 ) ;
}
for ( V_220 = 0 ; V_220 < V_221 ; V_220 ++ ) {
long long V_55 = 0 ;
if ( V_220 == V_62 && ! V_136 )
continue;
F_133 (mi, memcg)
V_55 += F_44 ( V_356 , V_220 ) * V_213 ;
F_312 ( V_346 , L_17 , V_357 [ V_220 ] , V_55 ) ;
}
for ( V_220 = 0 ; V_220 < V_223 ; V_220 ++ ) {
unsigned long long V_55 = 0 ;
F_133 (mi, memcg)
V_55 += F_52 ( V_356 , V_220 ) ;
F_312 ( V_346 , L_18 ,
V_358 [ V_220 ] , V_55 ) ;
}
for ( V_220 = 0 ; V_220 < V_355 ; V_220 ++ ) {
unsigned long long V_55 = 0 ;
F_133 (mi, memcg)
V_55 += F_64 ( V_356 , F_62 ( V_220 ) ) * V_213 ;
F_312 ( V_346 , L_18 , V_354 [ V_220 ] , V_55 ) ;
}
#ifdef F_318
{
int V_19 , V_20 ;
struct V_18 * V_31 ;
struct V_359 * V_360 ;
unsigned long V_361 [ 2 ] = { 0 , 0 } ;
unsigned long V_362 [ 2 ] = { 0 , 0 } ;
F_319 (nid)
for ( V_20 = 0 ; V_20 < V_49 ; V_20 ++ ) {
V_31 = F_19 ( V_10 , V_19 , V_20 ) ;
V_360 = & V_31 -> V_72 . V_363 ;
V_361 [ 0 ] += V_360 -> V_361 [ 0 ] ;
V_361 [ 1 ] += V_360 -> V_361 [ 1 ] ;
V_362 [ 0 ] += V_360 -> V_362 [ 0 ] ;
V_362 [ 1 ] += V_360 -> V_362 [ 1 ] ;
}
F_312 ( V_346 , L_19 , V_361 [ 0 ] ) ;
F_312 ( V_346 , L_20 , V_361 [ 1 ] ) ;
F_312 ( V_346 , L_21 , V_362 [ 0 ] ) ;
F_312 ( V_346 , L_22 , V_362 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_320 ( struct V_93 * V_138 , struct V_320 * V_321 )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
return F_109 ( V_10 ) ;
}
static int F_321 ( struct V_93 * V_138 , struct V_320 * V_321 ,
T_1 V_55 )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
struct V_9 * V_37 ;
if ( V_55 > 100 )
return - V_265 ;
if ( V_138 -> V_37 == NULL )
return - V_265 ;
V_37 = F_73 ( V_138 -> V_37 ) ;
F_293 () ;
if ( ( V_37 -> V_106 ) ||
( V_10 -> V_106 && ! F_281 ( & V_138 -> V_296 ) ) ) {
F_294 () ;
return - V_265 ;
}
V_10 -> V_140 = V_55 ;
F_294 () ;
return 0 ;
}
static void F_322 ( struct V_9 * V_10 , bool V_324 )
{
struct V_364 * V_365 ;
T_1 V_366 ;
int V_220 ;
F_8 () ;
if ( ! V_324 )
V_365 = F_76 ( V_10 -> V_367 . V_368 ) ;
else
V_365 = F_76 ( V_10 -> V_369 . V_368 ) ;
if ( ! V_365 )
goto V_144;
V_366 = F_296 ( V_10 , V_324 ) ;
V_220 = V_365 -> V_370 ;
for (; V_220 >= 0 && F_70 ( V_365 -> V_371 [ V_220 ] . V_372 > V_366 ) ; V_220 -- )
F_323 ( V_365 -> V_371 [ V_220 ] . V_373 , 1 ) ;
V_220 ++ ;
for (; V_220 < V_365 -> V_374 && F_70 ( V_365 -> V_371 [ V_220 ] . V_372 <= V_366 ) ; V_220 ++ )
F_323 ( V_365 -> V_371 [ V_220 ] . V_373 , 1 ) ;
V_365 -> V_370 = V_220 - 1 ;
V_144:
F_11 () ;
}
static void F_71 ( struct V_9 * V_10 )
{
while ( V_10 ) {
F_322 ( V_10 , false ) ;
if ( V_136 )
F_322 ( V_10 , true ) ;
V_10 = F_36 ( V_10 ) ;
}
}
static int F_324 ( const void * V_375 , const void * V_376 )
{
const struct F_71 * V_377 = V_375 ;
const struct F_71 * V_378 = V_376 ;
return V_377 -> V_372 - V_378 -> V_372 ;
}
static int F_325 ( struct V_9 * V_10 )
{
struct V_379 * V_380 ;
F_326 (ev, &memcg->oom_notify, list)
F_323 ( V_380 -> V_373 , 1 ) ;
return 0 ;
}
static void F_165 ( struct V_9 * V_10 )
{
struct V_9 * V_109 ;
F_133 (iter, memcg)
F_325 ( V_109 ) ;
}
static int F_327 ( struct V_93 * V_138 ,
struct V_320 * V_321 , struct V_381 * V_373 , const char * args )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
struct V_382 * V_367 ;
struct V_364 * V_383 ;
int type = F_298 ( V_321 -> V_197 ) ;
T_1 V_372 , V_366 ;
int V_220 , V_374 , V_77 ;
V_77 = F_303 ( args , & V_372 ) ;
if ( V_77 )
return V_77 ;
F_191 ( & V_10 -> V_384 ) ;
if ( type == V_334 )
V_367 = & V_10 -> V_367 ;
else if ( type == V_332 )
V_367 = & V_10 -> V_369 ;
else
F_87 () ;
V_366 = F_296 ( V_10 , type == V_332 ) ;
if ( V_367 -> V_368 )
F_322 ( V_10 , type == V_332 ) ;
V_374 = V_367 -> V_368 ? V_367 -> V_368 -> V_374 + 1 : 1 ;
V_383 = F_328 ( sizeof( * V_383 ) + V_374 * sizeof( struct F_71 ) ,
V_301 ) ;
if ( ! V_383 ) {
V_77 = - V_251 ;
goto V_144;
}
V_383 -> V_374 = V_374 ;
if ( V_367 -> V_368 ) {
memcpy ( V_383 -> V_371 , V_367 -> V_368 -> V_371 , ( V_374 - 1 ) *
sizeof( struct F_71 ) ) ;
}
V_383 -> V_371 [ V_374 - 1 ] . V_373 = V_373 ;
V_383 -> V_371 [ V_374 - 1 ] . V_372 = V_372 ;
F_329 ( V_383 -> V_371 , V_374 , sizeof( struct F_71 ) ,
F_324 , NULL ) ;
V_383 -> V_370 = - 1 ;
for ( V_220 = 0 ; V_220 < V_374 ; V_220 ++ ) {
if ( V_383 -> V_371 [ V_220 ] . V_372 <= V_366 ) {
++ V_383 -> V_370 ;
} else
break;
}
F_330 ( V_367 -> V_385 ) ;
V_367 -> V_385 = V_367 -> V_368 ;
F_331 ( V_367 -> V_368 , V_383 ) ;
F_111 () ;
V_144:
F_189 ( & V_10 -> V_384 ) ;
return V_77 ;
}
static void F_332 ( struct V_93 * V_138 ,
struct V_320 * V_321 , struct V_381 * V_373 )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
struct V_382 * V_367 ;
struct V_364 * V_383 ;
int type = F_298 ( V_321 -> V_197 ) ;
T_1 V_366 ;
int V_220 , V_386 , V_374 ;
F_191 ( & V_10 -> V_384 ) ;
if ( type == V_334 )
V_367 = & V_10 -> V_367 ;
else if ( type == V_332 )
V_367 = & V_10 -> V_369 ;
else
F_87 () ;
if ( ! V_367 -> V_368 )
goto V_144;
V_366 = F_296 ( V_10 , type == V_332 ) ;
F_322 ( V_10 , type == V_332 ) ;
V_374 = 0 ;
for ( V_220 = 0 ; V_220 < V_367 -> V_368 -> V_374 ; V_220 ++ ) {
if ( V_367 -> V_368 -> V_371 [ V_220 ] . V_373 != V_373 )
V_374 ++ ;
}
V_383 = V_367 -> V_385 ;
if ( ! V_374 ) {
F_330 ( V_383 ) ;
V_383 = NULL ;
goto V_387;
}
V_383 -> V_374 = V_374 ;
V_383 -> V_370 = - 1 ;
for ( V_220 = 0 , V_386 = 0 ; V_220 < V_367 -> V_368 -> V_374 ; V_220 ++ ) {
if ( V_367 -> V_368 -> V_371 [ V_220 ] . V_373 == V_373 )
continue;
V_383 -> V_371 [ V_386 ] = V_367 -> V_368 -> V_371 [ V_220 ] ;
if ( V_383 -> V_371 [ V_386 ] . V_372 <= V_366 ) {
++ V_383 -> V_370 ;
}
V_386 ++ ;
}
V_387:
V_367 -> V_385 = V_367 -> V_368 ;
if ( ! V_383 ) {
F_330 ( V_367 -> V_385 ) ;
V_367 -> V_385 = NULL ;
}
F_331 ( V_367 -> V_368 , V_383 ) ;
F_111 () ;
V_144:
F_189 ( & V_10 -> V_384 ) ;
}
static int F_333 ( struct V_93 * V_138 ,
struct V_320 * V_321 , struct V_381 * V_373 , const char * args )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
struct V_379 * V_319 ;
int type = F_298 ( V_321 -> V_197 ) ;
F_5 ( type != V_388 ) ;
V_319 = F_328 ( sizeof( * V_319 ) , V_301 ) ;
if ( ! V_319 )
return - V_251 ;
F_33 ( & V_199 ) ;
V_319 -> V_373 = V_373 ;
F_334 ( & V_319 -> V_307 , & V_10 -> V_389 ) ;
if ( F_116 ( & V_10 -> V_182 ) )
F_323 ( V_373 , 1 ) ;
F_34 ( & V_199 ) ;
return 0 ;
}
static void F_335 ( struct V_93 * V_138 ,
struct V_320 * V_321 , struct V_381 * V_373 )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
struct V_379 * V_380 , * V_341 ;
int type = F_298 ( V_321 -> V_197 ) ;
F_5 ( type != V_388 ) ;
F_33 ( & V_199 ) ;
F_336 (ev, tmp, &memcg->oom_notify, list) {
if ( V_380 -> V_373 == V_373 ) {
F_337 ( & V_380 -> V_307 ) ;
F_330 ( V_380 ) ;
}
}
F_34 ( & V_199 ) ;
}
static int F_338 ( struct V_93 * V_138 ,
struct V_320 * V_321 , struct V_390 * V_391 )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
V_391 -> V_392 ( V_391 , L_23 , V_10 -> V_201 ) ;
if ( F_116 ( & V_10 -> V_182 ) )
V_391 -> V_392 ( V_391 , L_24 , 1 ) ;
else
V_391 -> V_392 ( V_391 , L_24 , 0 ) ;
return 0 ;
}
static int F_339 ( struct V_93 * V_138 ,
struct V_320 * V_321 , T_1 V_55 )
{
struct V_9 * V_10 = F_73 ( V_138 ) ;
struct V_9 * V_37 ;
if ( ! V_138 -> V_37 || ! ( ( V_55 == 0 ) || ( V_55 == 1 ) ) )
return - V_265 ;
V_37 = F_73 ( V_138 -> V_37 ) ;
F_293 () ;
if ( ( V_37 -> V_106 ) ||
( V_10 -> V_106 && ! F_281 ( & V_138 -> V_296 ) ) ) {
F_294 () ;
return - V_265 ;
}
V_10 -> V_201 = V_55 ;
if ( ! V_55 )
F_162 ( V_10 ) ;
F_294 () ;
return 0 ;
}
static int F_340 ( struct V_9 * V_10 , struct V_393 * V_394 )
{
return F_341 ( V_10 , V_394 ) ;
}
static void F_342 ( struct V_9 * V_10 )
{
F_343 ( V_10 ) ;
}
static int F_340 ( struct V_9 * V_10 , struct V_393 * V_394 )
{
return 0 ;
}
static void F_342 ( struct V_9 * V_10 )
{
}
static int F_344 ( struct V_9 * V_10 , int V_47 )
{
struct V_395 * V_396 ;
struct V_18 * V_31 ;
int V_48 , V_341 = V_47 ;
if ( ! F_345 ( V_47 , V_397 ) )
V_341 = - 1 ;
V_396 = F_346 ( sizeof( * V_396 ) , V_301 , V_341 ) ;
if ( ! V_396 )
return 1 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_31 = & V_396 -> V_23 [ V_48 ] ;
F_347 ( & V_31 -> V_72 , & F_280 ( V_47 ) -> V_309 [ V_48 ] ) ;
V_31 -> V_40 = 0 ;
V_31 -> V_39 = false ;
V_31 -> V_10 = V_10 ;
}
V_10 -> V_21 . V_22 [ V_47 ] = V_396 ;
return 0 ;
}
static void F_348 ( struct V_9 * V_10 , int V_47 )
{
F_330 ( V_10 -> V_21 . V_22 [ V_47 ] ) ;
}
static struct V_9 * F_349 ( void )
{
struct V_9 * V_10 ;
int V_374 = sizeof( struct V_9 ) ;
if ( V_374 < V_213 )
V_10 = F_350 ( V_374 , V_301 ) ;
else
V_10 = F_351 ( V_374 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_57 = F_352 ( struct V_398 ) ;
if ( ! V_10 -> V_57 )
goto V_399;
F_353 ( & V_10 -> V_59 ) ;
return V_10 ;
V_399:
if ( V_374 < V_213 )
F_330 ( V_10 ) ;
else
F_354 ( V_10 ) ;
return NULL ;
}
static void F_355 ( struct V_214 * V_218 )
{
struct V_9 * V_10 ;
int V_374 = sizeof( struct V_9 ) ;
V_10 = F_59 ( V_218 , struct V_9 , V_400 ) ;
F_16 ( V_10 ) ;
if ( V_374 < V_213 )
F_330 ( V_10 ) ;
else
F_354 ( V_10 ) ;
}
static void F_356 ( struct V_401 * V_401 )
{
struct V_9 * V_10 ;
V_10 = F_59 ( V_401 , struct V_9 , V_402 ) ;
F_357 ( & V_10 -> V_400 , F_355 ) ;
F_358 ( & V_10 -> V_400 ) ;
}
static void F_359 ( struct V_9 * V_10 )
{
int V_47 ;
F_38 ( V_10 ) ;
F_360 ( & V_114 , & V_10 -> V_25 ) ;
F_39 (node)
F_348 ( V_10 , V_47 ) ;
F_361 ( V_10 -> V_57 ) ;
F_362 ( & V_10 -> V_402 , F_356 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
F_72 ( & V_10 -> V_403 ) ;
}
static void F_363 ( struct V_9 * V_10 , int V_58 )
{
if ( F_364 ( V_58 , & V_10 -> V_403 ) ) {
struct V_9 * V_37 = F_36 ( V_10 ) ;
F_359 ( V_10 ) ;
if ( V_37 )
F_14 ( V_37 ) ;
}
}
static void F_14 ( struct V_9 * V_10 )
{
F_363 ( V_10 , 1 ) ;
}
struct V_9 * F_36 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_46 . V_37 )
return NULL ;
return F_198 ( V_10 -> V_46 . V_37 , V_46 ) ;
}
static void T_11 F_365 ( void )
{
if ( ! F_78 () && V_404 )
V_136 = 1 ;
}
static void T_11 F_365 ( void )
{
}
static int F_366 ( void )
{
struct V_405 * V_406 ;
struct V_27 * V_407 ;
int V_341 , V_47 , V_48 ;
F_39 (node) {
V_341 = V_47 ;
if ( ! F_345 ( V_47 , V_397 ) )
V_341 = - 1 ;
V_406 = F_346 ( sizeof( * V_406 ) , V_301 , V_341 ) ;
if ( ! V_406 )
goto V_408;
V_28 . V_29 [ V_47 ] = V_406 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_407 = & V_406 -> V_30 [ V_48 ] ;
V_407 -> V_36 = V_409 ;
F_353 ( & V_407 -> V_44 ) ;
}
}
return 0 ;
V_408:
F_39 (node) {
if ( ! V_28 . V_29 [ V_47 ] )
break;
F_330 ( V_28 . V_29 [ V_47 ] ) ;
V_28 . V_29 [ V_47 ] = NULL ;
}
return 1 ;
}
static struct V_24 * T_12
F_367 ( struct V_93 * V_94 )
{
struct V_9 * V_10 , * V_37 ;
long error = - V_251 ;
int V_47 ;
V_10 = F_349 () ;
if ( ! V_10 )
return F_368 ( error ) ;
F_39 (node)
if ( F_344 ( V_10 , V_47 ) )
goto V_410;
if ( V_94 -> V_37 == NULL ) {
int V_56 ;
F_365 () ;
V_37 = NULL ;
if ( F_366 () )
goto V_410;
V_105 = V_10 ;
F_369 (cpu) {
struct V_207 * V_208 =
& F_47 ( V_209 , V_56 ) ;
F_357 ( & V_208 -> V_218 , F_178 ) ;
}
F_370 ( F_193 , 0 ) ;
} else {
V_37 = F_73 ( V_94 -> V_37 ) ;
V_10 -> V_106 = V_37 -> V_106 ;
V_10 -> V_201 = V_37 -> V_201 ;
}
if ( V_37 && V_37 -> V_106 ) {
F_371 ( & V_10 -> V_46 , & V_37 -> V_46 ) ;
F_371 ( & V_10 -> V_137 , & V_37 -> V_137 ) ;
F_7 ( V_37 ) ;
} else {
F_371 ( & V_10 -> V_46 , NULL ) ;
F_371 ( & V_10 -> V_137 , NULL ) ;
}
V_10 -> V_176 = V_91 ;
F_164 ( & V_10 -> V_389 ) ;
if ( V_37 )
V_10 -> V_140 = F_109 ( V_37 ) ;
F_143 ( & V_10 -> V_403 , 1 ) ;
V_10 -> V_4 = 0 ;
F_372 ( & V_10 -> V_384 ) ;
F_353 ( & V_10 -> V_150 ) ;
error = F_340 ( V_10 , & V_114 ) ;
if ( error ) {
F_14 ( V_10 ) ;
return F_368 ( error ) ;
}
return & V_10 -> V_25 ;
V_410:
F_359 ( V_10 ) ;
return F_368 ( error ) ;
}
static int F_373 ( struct V_93 * V_94 )
{
struct V_9 * V_10 = F_73 ( V_94 ) ;
return F_285 ( V_10 , false ) ;
}
static void F_374 ( struct V_93 * V_94 )
{
struct V_9 * V_10 = F_73 ( V_94 ) ;
F_342 ( V_10 ) ;
F_14 ( V_10 ) ;
}
static int F_375 ( unsigned long V_58 )
{
int V_77 = 0 ;
int V_411 = V_412 ;
struct V_9 * V_10 = V_2 . V_3 ;
if ( F_6 ( V_10 ) ) {
V_2 . V_413 += V_58 ;
return V_77 ;
}
if ( V_58 > 1 ) {
struct V_235 * V_215 ;
if ( F_196 ( & V_10 -> V_46 , V_213 * V_58 , & V_215 ) )
goto V_414;
if ( V_136 && F_196 ( & V_10 -> V_137 ,
V_213 * V_58 , & V_215 ) ) {
F_177 ( & V_10 -> V_46 , V_213 * V_58 ) ;
goto V_414;
}
V_2 . V_413 += V_58 ;
return V_77 ;
}
V_414:
while ( V_58 -- ) {
if ( F_275 ( V_15 ) ) {
V_77 = - V_252 ;
break;
}
if ( ! V_411 -- ) {
V_411 = V_412 ;
F_284 () ;
}
V_77 = F_200 ( NULL ,
V_301 , 1 , & V_10 , false ) ;
if ( V_77 )
return V_77 ;
V_2 . V_413 ++ ;
}
return V_77 ;
}
static struct V_26 * F_376 ( struct V_415 * V_416 ,
unsigned long V_417 , T_13 V_418 )
{
struct V_26 * V_26 = F_377 ( V_416 , V_417 , V_418 ) ;
if ( ! V_26 || ! F_230 ( V_26 ) )
return NULL ;
if ( F_228 ( V_26 ) ) {
if ( ! F_1 () )
return NULL ;
} else if ( ! F_3 () )
return NULL ;
if ( ! F_233 ( V_26 ) )
return NULL ;
return V_26 ;
}
static struct V_26 * F_378 ( struct V_415 * V_416 ,
unsigned long V_417 , T_13 V_418 , T_6 * V_284 )
{
struct V_26 * V_26 = NULL ;
T_6 V_253 = F_379 ( V_418 ) ;
if ( ! F_1 () || F_380 ( V_253 ) )
return NULL ;
V_26 = F_381 ( & V_419 , V_253 . V_55 ) ;
if ( V_136 )
V_284 -> V_55 = V_253 . V_55 ;
return V_26 ;
}
static struct V_26 * F_378 ( struct V_415 * V_416 ,
unsigned long V_417 , T_13 V_418 , T_6 * V_284 )
{
return NULL ;
}
static struct V_26 * F_382 ( struct V_415 * V_416 ,
unsigned long V_417 , T_13 V_418 , T_6 * V_284 )
{
struct V_26 * V_26 = NULL ;
struct V_420 * V_268 ;
T_14 V_421 ;
if ( ! V_416 -> V_422 )
return NULL ;
if ( ! F_3 () )
return NULL ;
V_268 = V_416 -> V_422 -> V_423 ;
if ( F_383 ( V_418 ) )
V_421 = F_384 ( V_416 , V_417 ) ;
else
V_421 = F_385 ( V_418 ) ;
V_26 = F_381 ( V_268 , V_421 ) ;
#ifdef F_386
if ( F_387 ( V_26 ) ) {
T_6 V_324 = F_388 ( V_26 ) ;
if ( V_136 )
* V_284 = V_324 ;
V_26 = F_381 ( & V_419 , V_324 . V_55 ) ;
}
#endif
return V_26 ;
}
static enum V_424 F_389 ( struct V_415 * V_416 ,
unsigned long V_417 , T_13 V_418 , union V_425 * V_80 )
{
struct V_26 * V_26 = NULL ;
struct V_121 * V_122 ;
enum V_424 V_77 = V_426 ;
T_6 V_253 = { . V_55 = 0 } ;
if ( F_390 ( V_418 ) )
V_26 = F_376 ( V_416 , V_417 , V_418 ) ;
else if ( F_391 ( V_418 ) )
V_26 = F_378 ( V_416 , V_417 , V_418 , & V_253 ) ;
else if ( F_383 ( V_418 ) || F_392 ( V_418 ) )
V_26 = F_382 ( V_416 , V_417 , V_418 , & V_253 ) ;
if ( ! V_26 && ! V_253 . V_55 )
return V_77 ;
if ( V_26 ) {
V_122 = F_90 ( V_26 ) ;
if ( F_92 ( V_122 ) && V_122 -> V_9 == V_2 . V_143 ) {
V_77 = V_427 ;
if ( V_80 )
V_80 -> V_26 = V_26 ;
}
if ( ! V_77 || ! V_80 )
F_239 ( V_26 ) ;
}
if ( V_253 . V_55 && ! V_77 &&
F_79 ( & V_2 . V_143 -> V_25 ) == F_213 ( V_253 ) ) {
V_77 = V_428 ;
if ( V_80 )
V_80 -> V_253 = V_253 ;
}
return V_77 ;
}
static enum V_424 F_393 ( struct V_415 * V_416 ,
unsigned long V_417 , T_15 V_429 , union V_425 * V_80 )
{
struct V_26 * V_26 = NULL ;
struct V_121 * V_122 ;
enum V_424 V_77 = V_426 ;
V_26 = F_394 ( V_429 ) ;
F_94 ( ! V_26 || ! F_395 ( V_26 ) ) ;
if ( ! F_1 () )
return V_77 ;
V_122 = F_90 ( V_26 ) ;
if ( F_92 ( V_122 ) && V_122 -> V_9 == V_2 . V_143 ) {
V_77 = V_427 ;
if ( V_80 ) {
F_396 ( V_26 ) ;
V_80 -> V_26 = V_26 ;
}
}
return V_77 ;
}
static inline enum V_424 F_393 ( struct V_415 * V_416 ,
unsigned long V_417 , T_15 V_429 , union V_425 * V_80 )
{
return V_426 ;
}
static int F_397 ( T_15 * V_429 ,
unsigned long V_417 , unsigned long V_430 ,
struct V_431 * V_432 )
{
struct V_415 * V_416 = V_432 -> V_197 ;
T_13 * V_433 ;
T_16 * V_434 ;
if ( F_398 ( V_429 , V_416 ) == 1 ) {
if ( F_393 ( V_416 , V_417 , * V_429 , NULL ) == V_427 )
V_2 . V_413 += V_262 ;
F_34 ( & V_416 -> V_435 -> V_436 ) ;
return 0 ;
}
if ( F_399 ( V_429 ) )
return 0 ;
V_433 = F_400 ( V_416 -> V_435 , V_429 , V_417 , & V_434 ) ;
for (; V_417 != V_430 ; V_433 ++ , V_417 += V_213 )
if ( F_389 ( V_416 , V_417 , * V_433 , NULL ) )
V_2 . V_413 ++ ;
F_401 ( V_433 - 1 , V_434 ) ;
F_284 () ;
return 0 ;
}
static unsigned long F_402 ( struct V_97 * V_98 )
{
unsigned long V_413 ;
struct V_415 * V_416 ;
F_403 ( & V_98 -> V_437 ) ;
for ( V_416 = V_98 -> V_438 ; V_416 ; V_416 = V_416 -> V_439 ) {
struct V_431 V_440 = {
. V_441 = F_397 ,
. V_98 = V_98 ,
. V_197 = V_416 ,
} ;
if ( F_404 ( V_416 ) )
continue;
F_405 ( V_416 -> V_442 , V_416 -> V_443 ,
& V_440 ) ;
}
F_406 ( & V_98 -> V_437 ) ;
V_413 = V_2 . V_413 ;
V_2 . V_413 = 0 ;
return V_413 ;
}
static int F_407 ( struct V_97 * V_98 )
{
unsigned long V_413 = F_402 ( V_98 ) ;
F_94 ( V_2 . V_145 ) ;
V_2 . V_145 = V_15 ;
return F_375 ( V_413 ) ;
}
static void F_408 ( void )
{
struct V_9 * V_143 = V_2 . V_143 ;
struct V_9 * V_3 = V_2 . V_3 ;
if ( V_2 . V_413 ) {
F_203 ( V_2 . V_3 , V_2 . V_413 ) ;
V_2 . V_413 = 0 ;
}
if ( V_2 . V_444 ) {
F_203 ( V_2 . V_143 , V_2 . V_444 ) ;
V_2 . V_444 = 0 ;
}
if ( V_2 . V_445 ) {
if ( ! F_6 ( V_2 . V_143 ) )
F_177 ( & V_2 . V_143 -> V_137 ,
V_213 * V_2 . V_445 ) ;
F_363 ( V_2 . V_143 , V_2 . V_445 ) ;
if ( ! F_6 ( V_2 . V_3 ) ) {
F_177 ( & V_2 . V_3 -> V_46 ,
V_213 * V_2 . V_445 ) ;
}
V_2 . V_445 = 0 ;
}
F_162 ( V_143 ) ;
F_162 ( V_3 ) ;
F_409 ( & V_2 . V_147 ) ;
}
static void F_410 ( void )
{
struct V_9 * V_143 = V_2 . V_143 ;
V_2 . V_145 = NULL ;
F_408 () ;
F_33 ( & V_2 . V_44 ) ;
V_2 . V_143 = NULL ;
V_2 . V_3 = NULL ;
F_34 ( & V_2 . V_44 ) ;
F_112 ( V_143 ) ;
}
static int F_411 ( struct V_93 * V_93 ,
struct V_446 * V_447 )
{
struct V_96 * V_35 = F_412 ( V_447 ) ;
int V_77 = 0 ;
struct V_9 * V_10 = F_73 ( V_93 ) ;
if ( V_10 -> V_4 ) {
struct V_97 * V_98 ;
struct V_9 * V_143 = F_9 ( V_35 ) ;
F_94 ( V_143 == V_10 ) ;
V_98 = F_413 ( V_35 ) ;
if ( ! V_98 )
return 0 ;
if ( V_98 -> V_99 == V_35 ) {
F_94 ( V_2 . V_143 ) ;
F_94 ( V_2 . V_3 ) ;
F_94 ( V_2 . V_413 ) ;
F_94 ( V_2 . V_444 ) ;
F_94 ( V_2 . V_445 ) ;
F_110 ( V_143 ) ;
F_33 ( & V_2 . V_44 ) ;
V_2 . V_143 = V_143 ;
V_2 . V_3 = V_10 ;
F_34 ( & V_2 . V_44 ) ;
V_77 = F_407 ( V_98 ) ;
if ( V_77 )
F_410 () ;
}
F_414 ( V_98 ) ;
}
return V_77 ;
}
static void F_415 ( struct V_93 * V_93 ,
struct V_446 * V_447 )
{
F_410 () ;
}
static int F_416 ( T_15 * V_429 ,
unsigned long V_417 , unsigned long V_430 ,
struct V_431 * V_432 )
{
int V_77 = 0 ;
struct V_415 * V_416 = V_432 -> V_197 ;
T_13 * V_433 ;
T_16 * V_434 ;
enum V_424 V_448 ;
union V_425 V_80 ;
struct V_26 * V_26 ;
struct V_121 * V_122 ;
if ( F_398 ( V_429 , V_416 ) == 1 ) {
if ( V_2 . V_413 < V_262 ) {
F_34 ( & V_416 -> V_435 -> V_436 ) ;
return 0 ;
}
V_448 = F_393 ( V_416 , V_417 , * V_429 , & V_80 ) ;
if ( V_448 == V_427 ) {
V_26 = V_80 . V_26 ;
if ( ! F_234 ( V_26 ) ) {
V_122 = F_90 ( V_26 ) ;
if ( ! F_227 ( V_26 , V_262 ,
V_122 , V_2 . V_143 , V_2 . V_3 ) ) {
V_2 . V_413 -= V_262 ;
V_2 . V_444 += V_262 ;
}
F_238 ( V_26 ) ;
}
F_239 ( V_26 ) ;
}
F_34 ( & V_416 -> V_435 -> V_436 ) ;
return 0 ;
}
if ( F_399 ( V_429 ) )
return 0 ;
V_51:
V_433 = F_400 ( V_416 -> V_435 , V_429 , V_417 , & V_434 ) ;
for (; V_417 != V_430 ; V_417 += V_213 ) {
T_13 V_418 = * ( V_433 ++ ) ;
T_6 V_253 ;
if ( ! V_2 . V_413 )
break;
switch ( F_389 ( V_416 , V_417 , V_418 , & V_80 ) ) {
case V_427 :
V_26 = V_80 . V_26 ;
if ( F_234 ( V_26 ) )
goto V_267;
V_122 = F_90 ( V_26 ) ;
if ( ! F_227 ( V_26 , 1 , V_122 ,
V_2 . V_143 , V_2 . V_3 ) ) {
V_2 . V_413 -- ;
V_2 . V_444 ++ ;
}
F_238 ( V_26 ) ;
V_267:
F_239 ( V_26 ) ;
break;
case V_428 :
V_253 = V_80 . V_253 ;
if ( ! F_263 ( V_253 , V_2 . V_143 , V_2 . V_3 ) ) {
V_2 . V_413 -- ;
V_2 . V_445 ++ ;
}
break;
default:
break;
}
}
F_401 ( V_433 - 1 , V_434 ) ;
F_284 () ;
if ( V_417 != V_430 ) {
V_77 = F_375 ( 1 ) ;
if ( ! V_77 )
goto V_51;
}
return V_77 ;
}
static void F_417 ( struct V_97 * V_98 )
{
struct V_415 * V_416 ;
F_287 () ;
V_51:
if ( F_70 ( ! F_418 ( & V_98 -> V_437 ) ) ) {
F_408 () ;
F_284 () ;
goto V_51;
}
for ( V_416 = V_98 -> V_438 ; V_416 ; V_416 = V_416 -> V_439 ) {
int V_77 ;
struct V_431 V_449 = {
. V_441 = F_416 ,
. V_98 = V_98 ,
. V_197 = V_416 ,
} ;
if ( F_404 ( V_416 ) )
continue;
V_77 = F_405 ( V_416 -> V_442 , V_416 -> V_443 ,
& V_449 ) ;
if ( V_77 )
break;
}
F_406 ( & V_98 -> V_437 ) ;
}
static void F_419 ( struct V_93 * V_94 ,
struct V_446 * V_447 )
{
struct V_96 * V_35 = F_412 ( V_447 ) ;
struct V_97 * V_98 = F_413 ( V_35 ) ;
if ( V_98 ) {
if ( V_2 . V_3 )
F_417 ( V_98 ) ;
F_414 ( V_98 ) ;
}
if ( V_2 . V_3 )
F_410 () ;
}
static int F_411 ( struct V_93 * V_93 ,
struct V_446 * V_447 )
{
return 0 ;
}
static void F_415 ( struct V_93 * V_93 ,
struct V_446 * V_447 )
{
}
static void F_419 ( struct V_93 * V_94 ,
struct V_446 * V_447 )
{
}
static int T_11 F_420 ( char * V_450 )
{
if ( ! strcmp ( V_450 , L_25 ) )
V_404 = 1 ;
else if ( ! strcmp ( V_450 , L_26 ) )
V_404 = 0 ;
return 1 ;
}
