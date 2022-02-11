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
F_5 ( ! V_7 -> V_11 -> V_12 ) ;
if ( V_7 -> V_13 ) {
F_5 ( F_6 ( V_7 -> V_13 -> V_10 ) ) ;
F_7 ( V_7 -> V_13 -> V_10 ) ;
return;
}
F_8 () ;
V_10 = F_9 ( V_14 ) ;
if ( ! F_6 ( V_10 ) ) {
F_7 ( V_10 ) ;
V_7 -> V_13 = V_7 -> V_11 -> V_12 ( V_10 ) ;
}
F_10 () ;
}
}
void F_11 ( struct V_6 * V_7 )
{
if ( V_8 && V_7 -> V_13 ) {
struct V_9 * V_10 ;
F_12 ( ! V_7 -> V_13 -> V_10 ) ;
V_10 = V_7 -> V_13 -> V_10 ;
F_13 ( V_10 ) ;
}
}
struct V_15 * F_14 ( struct V_9 * V_10 )
{
if ( ! V_10 || F_6 ( V_10 ) )
return NULL ;
return & V_10 -> V_16 . V_15 ;
}
static struct V_17 *
F_15 ( struct V_9 * V_10 , int V_18 , int V_19 )
{
return & V_10 -> V_20 . V_21 [ V_18 ] -> V_22 [ V_19 ] ;
}
struct V_23 * F_16 ( struct V_9 * V_10 )
{
return & V_10 -> V_24 ;
}
static struct V_17 *
F_17 ( struct V_9 * V_10 , struct V_25 * V_25 )
{
int V_18 = F_18 ( V_25 ) ;
int V_19 = F_19 ( V_25 ) ;
return F_15 ( V_10 , V_18 , V_19 ) ;
}
static struct V_26 *
F_20 ( int V_18 , int V_19 )
{
return & V_27 . V_28 [ V_18 ] -> V_29 [ V_19 ] ;
}
static struct V_26 *
F_21 ( struct V_25 * V_25 )
{
int V_18 = F_18 ( V_25 ) ;
int V_19 = F_19 ( V_25 ) ;
return & V_27 . V_28 [ V_18 ] -> V_29 [ V_19 ] ;
}
static void
F_22 ( struct V_9 * V_10 ,
struct V_17 * V_30 ,
struct V_26 * V_31 ,
unsigned long long V_32 )
{
struct V_33 * * V_34 = & V_31 -> V_35 . V_33 ;
struct V_33 * V_36 = NULL ;
struct V_17 * V_37 ;
if ( V_30 -> V_38 )
return;
V_30 -> V_39 = V_32 ;
if ( ! V_30 -> V_39 )
return;
while ( * V_34 ) {
V_36 = * V_34 ;
V_37 = F_23 ( V_36 , struct V_17 ,
V_40 ) ;
if ( V_30 -> V_39 < V_37 -> V_39 )
V_34 = & ( * V_34 ) -> V_41 ;
else if ( V_30 -> V_39 >= V_37 -> V_39 )
V_34 = & ( * V_34 ) -> V_42 ;
}
F_24 ( & V_30 -> V_40 , V_36 , V_34 ) ;
F_25 ( & V_30 -> V_40 , & V_31 -> V_35 ) ;
V_30 -> V_38 = true ;
}
static void
F_26 ( struct V_9 * V_10 ,
struct V_17 * V_30 ,
struct V_26 * V_31 )
{
if ( ! V_30 -> V_38 )
return;
F_27 ( & V_30 -> V_40 , & V_31 -> V_35 ) ;
V_30 -> V_38 = false ;
}
static void
F_28 ( struct V_9 * V_10 ,
struct V_17 * V_30 ,
struct V_26 * V_31 )
{
F_29 ( & V_31 -> V_43 ) ;
F_26 ( V_10 , V_30 , V_31 ) ;
F_30 ( & V_31 -> V_43 ) ;
}
static void F_31 ( struct V_9 * V_10 , struct V_25 * V_25 )
{
unsigned long long V_44 ;
struct V_17 * V_30 ;
struct V_26 * V_31 ;
int V_18 = F_18 ( V_25 ) ;
int V_19 = F_19 ( V_25 ) ;
V_31 = F_21 ( V_25 ) ;
for (; V_10 ; V_10 = F_32 ( V_10 ) ) {
V_30 = F_15 ( V_10 , V_18 , V_19 ) ;
V_44 = F_33 ( & V_10 -> V_45 ) ;
if ( V_44 || V_30 -> V_38 ) {
F_29 ( & V_31 -> V_43 ) ;
if ( V_30 -> V_38 )
F_26 ( V_10 , V_30 , V_31 ) ;
F_22 ( V_10 , V_30 , V_31 , V_44 ) ;
F_30 ( & V_31 -> V_43 ) ;
}
}
}
static void F_34 ( struct V_9 * V_10 )
{
int V_46 , V_47 ;
struct V_17 * V_30 ;
struct V_26 * V_31 ;
F_35 (node) {
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_30 = F_15 ( V_10 , V_46 , V_47 ) ;
V_31 = F_20 ( V_46 , V_47 ) ;
F_28 ( V_10 , V_30 , V_31 ) ;
}
}
}
static struct V_17 *
F_36 ( struct V_26 * V_31 )
{
struct V_33 * V_49 = NULL ;
struct V_17 * V_30 ;
V_50:
V_30 = NULL ;
V_49 = F_37 ( & V_31 -> V_35 ) ;
if ( ! V_49 )
goto V_51;
V_30 = F_23 ( V_49 , struct V_17 , V_40 ) ;
F_26 ( V_30 -> V_10 , V_30 , V_31 ) ;
if ( ! F_33 ( & V_30 -> V_10 -> V_45 ) ||
! F_38 ( & V_30 -> V_10 -> V_24 ) )
goto V_50;
V_51:
return V_30 ;
}
static struct V_17 *
F_39 ( struct V_26 * V_31 )
{
struct V_17 * V_30 ;
F_29 ( & V_31 -> V_43 ) ;
V_30 = F_36 ( V_31 ) ;
F_30 ( & V_31 -> V_43 ) ;
return V_30 ;
}
static long F_40 ( struct V_9 * V_10 ,
enum V_52 V_53 )
{
long V_54 = 0 ;
int V_55 ;
F_41 () ;
F_42 (cpu)
V_54 += F_43 ( V_10 -> V_56 -> V_57 [ V_53 ] , V_55 ) ;
#ifdef F_44
F_29 ( & V_10 -> V_58 ) ;
V_54 += V_10 -> V_59 . V_57 [ V_53 ] ;
F_30 ( & V_10 -> V_58 ) ;
#endif
F_45 () ;
return V_54 ;
}
static void F_46 ( struct V_9 * V_10 ,
bool V_60 )
{
int V_54 = ( V_60 ) ? 1 : - 1 ;
F_47 ( V_10 -> V_56 -> V_57 [ V_61 ] , V_54 ) ;
}
static unsigned long F_48 ( struct V_9 * V_10 ,
enum V_62 V_53 )
{
unsigned long V_54 = 0 ;
int V_55 ;
F_42 (cpu)
V_54 += F_43 ( V_10 -> V_56 -> V_63 [ V_53 ] , V_55 ) ;
#ifdef F_44
F_29 ( & V_10 -> V_58 ) ;
V_54 += V_10 -> V_59 . V_63 [ V_53 ] ;
F_30 ( & V_10 -> V_58 ) ;
#endif
return V_54 ;
}
static void F_49 ( struct V_9 * V_10 ,
bool V_64 , int V_65 )
{
F_50 () ;
if ( V_64 )
F_51 ( V_10 -> V_56 -> V_57 [ V_66 ] ,
V_65 ) ;
else
F_51 ( V_10 -> V_56 -> V_57 [ V_67 ] ,
V_65 ) ;
if ( V_65 > 0 )
F_52 ( V_10 -> V_56 -> V_63 [ V_68 ] ) ;
else {
F_52 ( V_10 -> V_56 -> V_63 [ V_69 ] ) ;
V_65 = - V_65 ;
}
F_51 ( V_10 -> V_56 -> V_63 [ V_70 ] , V_65 ) ;
F_53 () ;
}
unsigned long
F_54 ( struct V_9 * V_10 , int V_18 , int V_19 ,
unsigned int V_71 )
{
struct V_17 * V_30 ;
enum V_72 V_73 ;
unsigned long V_74 = 0 ;
V_30 = F_15 ( V_10 , V_18 , V_19 ) ;
F_55 (lru) {
if ( F_56 ( V_73 ) & V_71 )
V_74 += V_30 -> V_75 [ V_73 ] ;
}
return V_74 ;
}
static unsigned long
F_57 ( struct V_9 * V_10 ,
int V_18 , unsigned int V_71 )
{
T_1 V_76 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_48 ; V_19 ++ )
V_76 += F_54 ( V_10 ,
V_18 , V_19 , V_71 ) ;
return V_76 ;
}
static unsigned long F_58 ( struct V_9 * V_10 ,
unsigned int V_71 )
{
int V_18 ;
T_1 V_76 = 0 ;
F_59 (nid, N_HIGH_MEMORY)
V_76 += F_57 ( V_10 , V_18 , V_71 ) ;
return V_76 ;
}
static bool F_60 ( struct V_9 * V_10 ,
enum V_77 V_78 )
{
unsigned long V_54 , V_79 ;
V_54 = F_61 ( V_10 -> V_56 -> V_63 [ V_70 ] ) ;
V_79 = F_61 ( V_10 -> V_56 -> V_80 [ V_78 ] ) ;
if ( ( long ) V_79 - ( long ) V_54 < 0 ) {
switch ( V_78 ) {
case V_81 :
V_79 = V_54 + V_82 ;
break;
case V_83 :
V_79 = V_54 + V_84 ;
break;
case V_85 :
V_79 = V_54 + V_86 ;
break;
default:
break;
}
F_62 ( V_10 -> V_56 -> V_80 [ V_78 ] , V_79 ) ;
return true ;
}
return false ;
}
static void F_63 ( struct V_9 * V_10 , struct V_25 * V_25 )
{
F_50 () ;
if ( F_64 ( F_60 ( V_10 ,
V_81 ) ) ) {
bool V_87 ;
bool T_2 V_88 ;
V_87 = F_60 ( V_10 ,
V_83 ) ;
#if V_89 > 1
T_2 = F_60 ( V_10 ,
V_85 ) ;
#endif
F_53 () ;
F_65 ( V_10 ) ;
if ( F_64 ( V_87 ) )
F_31 ( V_10 , V_25 ) ;
#if V_89 > 1
if ( F_64 ( T_2 ) )
F_66 ( & V_10 -> V_90 ) ;
#endif
} else
F_53 () ;
}
struct V_9 * F_67 ( struct V_91 * V_92 )
{
return F_68 ( V_23 ( V_92 ,
V_93 ) , struct V_9 ,
V_24 ) ;
}
struct V_9 * F_9 ( struct V_94 * V_34 )
{
if ( F_64 ( ! V_34 ) )
return NULL ;
return F_68 ( F_69 ( V_34 , V_93 ) ,
struct V_9 , V_24 ) ;
}
struct V_9 * F_70 ( struct V_95 * V_96 )
{
struct V_9 * V_10 = NULL ;
if ( ! V_96 )
return NULL ;
F_8 () ;
do {
V_10 = F_9 ( F_71 ( V_96 -> V_97 ) ) ;
if ( F_64 ( ! V_10 ) )
break;
} while ( ! F_38 ( & V_10 -> V_24 ) );
F_10 () ;
return V_10 ;
}
struct V_9 * F_72 ( struct V_9 * V_98 ,
struct V_9 * V_99 ,
struct V_100 * V_101 )
{
struct V_9 * V_10 = NULL ;
int V_102 = 0 ;
if ( F_73 () )
return NULL ;
if ( ! V_98 )
V_98 = V_103 ;
if ( V_99 && ! V_101 )
V_102 = F_74 ( & V_99 -> V_24 ) ;
if ( V_99 && V_99 != V_98 )
F_75 ( & V_99 -> V_24 ) ;
if ( ! V_98 -> V_104 && V_98 != V_103 ) {
if ( V_99 )
return NULL ;
return V_98 ;
}
while ( ! V_10 ) {
struct V_105 * V_106 ( V_107 ) ;
struct V_23 * V_24 ;
if ( V_101 ) {
int V_18 = F_76 ( V_101 -> V_47 ) ;
int V_19 = F_77 ( V_101 -> V_47 ) ;
struct V_17 * V_30 ;
V_30 = F_15 ( V_98 , V_18 , V_19 ) ;
V_107 = & V_30 -> V_108 [ V_101 -> V_109 ] ;
if ( V_99 && V_101 -> V_110 != V_107 -> V_110 )
return NULL ;
V_102 = V_107 -> V_111 ;
}
F_8 () ;
V_24 = F_78 ( & V_112 , V_102 + 1 , & V_98 -> V_24 , & V_102 ) ;
if ( V_24 ) {
if ( V_24 == & V_98 -> V_24 || F_38 ( V_24 ) )
V_10 = F_68 ( V_24 ,
struct V_9 , V_24 ) ;
} else
V_102 = 0 ;
F_10 () ;
if ( V_101 ) {
V_107 -> V_111 = V_102 ;
if ( ! V_24 )
V_107 -> V_110 ++ ;
else if ( ! V_99 && V_10 )
V_101 -> V_110 = V_107 -> V_110 ;
}
if ( V_99 && ! V_24 )
return NULL ;
}
return V_10 ;
}
void F_79 ( struct V_9 * V_98 ,
struct V_9 * V_99 )
{
if ( ! V_98 )
V_98 = V_103 ;
if ( V_99 && V_99 != V_98 )
F_75 ( & V_99 -> V_24 ) ;
}
static inline bool F_6 ( struct V_9 * V_10 )
{
return ( V_10 == V_103 ) ;
}
void F_80 ( struct V_95 * V_96 , enum V_113 V_53 )
{
struct V_9 * V_10 ;
if ( ! V_96 )
return;
F_8 () ;
V_10 = F_9 ( F_71 ( V_96 -> V_97 ) ) ;
if ( F_64 ( ! V_10 ) )
goto V_114;
switch ( V_53 ) {
case V_115 :
F_81 ( V_10 -> V_56 -> V_63 [ V_116 ] ) ;
break;
case V_117 :
F_81 ( V_10 -> V_56 -> V_63 [ V_118 ] ) ;
break;
default:
F_82 () ;
}
V_114:
F_10 () ;
}
struct V_119 * F_83 ( struct V_47 * V_47 ,
struct V_9 * V_10 )
{
struct V_17 * V_30 ;
if ( F_73 () )
return & V_47 -> V_119 ;
V_30 = F_15 ( V_10 , F_76 ( V_47 ) , F_77 ( V_47 ) ) ;
return & V_30 -> V_119 ;
}
struct V_119 * F_84 ( struct V_47 * V_47 , struct V_25 * V_25 ,
enum V_72 V_73 )
{
struct V_17 * V_30 ;
struct V_9 * V_10 ;
struct V_120 * V_121 ;
if ( F_73 () )
return & V_47 -> V_119 ;
V_121 = F_85 ( V_25 ) ;
V_10 = V_121 -> V_9 ;
if ( ! F_86 ( V_121 ) && V_10 != V_103 )
V_121 -> V_9 = V_10 = V_103 ;
V_30 = F_17 ( V_10 , V_25 ) ;
V_30 -> V_75 [ V_73 ] += 1 << F_87 ( V_25 ) ;
return & V_30 -> V_119 ;
}
void F_88 ( struct V_25 * V_25 , enum V_72 V_73 )
{
struct V_17 * V_30 ;
struct V_9 * V_10 ;
struct V_120 * V_121 ;
if ( F_73 () )
return;
V_121 = F_85 ( V_25 ) ;
V_10 = V_121 -> V_9 ;
F_89 ( ! V_10 ) ;
V_30 = F_17 ( V_10 , V_25 ) ;
F_89 ( V_30 -> V_75 [ V_73 ] < ( 1 << F_87 ( V_25 ) ) ) ;
V_30 -> V_75 [ V_73 ] -= 1 << F_87 ( V_25 ) ;
}
void F_90 ( struct V_25 * V_25 )
{
F_88 ( V_25 , F_91 ( V_25 ) ) ;
}
struct V_119 * F_92 ( struct V_47 * V_47 ,
struct V_25 * V_25 ,
enum V_72 V_122 ,
enum V_72 V_3 )
{
F_88 ( V_25 , V_122 ) ;
return F_84 ( V_47 , V_25 , V_3 ) ;
}
static bool F_93 ( const struct V_9 * V_123 ,
struct V_9 * V_10 )
{
if ( V_123 != V_10 ) {
return ( V_123 -> V_104 &&
F_94 ( & V_10 -> V_24 , & V_123 -> V_24 ) ) ;
}
return true ;
}
int F_95 ( struct V_94 * V_124 , const struct V_9 * V_10 )
{
int V_74 ;
struct V_9 * V_125 = NULL ;
struct V_94 * V_34 ;
V_34 = F_96 ( V_124 ) ;
if ( V_34 ) {
V_125 = F_70 ( V_34 -> V_96 ) ;
F_97 ( V_34 ) ;
} else {
F_98 ( V_124 ) ;
V_125 = F_9 ( V_124 ) ;
if ( V_125 )
F_99 ( & V_125 -> V_24 ) ;
F_97 ( V_124 ) ;
}
if ( ! V_125 )
return 0 ;
V_74 = F_93 ( V_10 , V_125 ) ;
F_75 ( & V_125 -> V_24 ) ;
return V_74 ;
}
int F_100 ( struct V_9 * V_10 , struct V_47 * V_47 )
{
unsigned long V_126 ;
int V_18 = F_76 ( V_47 ) ;
int V_19 = F_77 ( V_47 ) ;
unsigned long V_127 ;
unsigned long V_128 ;
unsigned long V_129 ;
V_127 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_130 ) ) ;
V_128 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_131 ) ) ;
V_129 = ( V_127 + V_128 ) >> ( 30 - V_132 ) ;
if ( V_129 )
V_126 = F_101 ( 10 * V_129 ) ;
else
V_126 = 1 ;
return V_127 * V_126 < V_128 ;
}
int F_102 ( struct V_9 * V_10 , struct V_47 * V_47 )
{
unsigned long V_128 ;
unsigned long V_127 ;
int V_19 = F_77 ( V_47 ) ;
int V_18 = F_76 ( V_47 ) ;
V_127 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_133 ) ) ;
V_128 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_134 ) ) ;
return ( V_128 > V_127 ) ;
}
struct V_135 * F_103 ( struct V_9 * V_10 ,
struct V_47 * V_47 )
{
int V_18 = F_76 ( V_47 ) ;
int V_19 = F_77 ( V_47 ) ;
struct V_17 * V_30 = F_15 ( V_10 , V_18 , V_19 ) ;
return & V_30 -> V_136 ;
}
struct V_135 *
F_104 ( struct V_25 * V_25 )
{
struct V_120 * V_121 ;
struct V_17 * V_30 ;
if ( F_73 () )
return NULL ;
V_121 = F_85 ( V_25 ) ;
if ( ! F_86 ( V_121 ) )
return NULL ;
F_105 () ;
V_30 = F_17 ( V_121 -> V_9 , V_25 ) ;
return & V_30 -> V_136 ;
}
static unsigned long F_106 ( struct V_9 * V_10 )
{
unsigned long long V_137 ;
V_137 = F_107 ( & V_10 -> V_45 ) ;
if ( V_138 )
V_137 = F_108 ( V_137 , F_107 ( & V_10 -> V_139 ) ) ;
return V_137 >> V_132 ;
}
int F_109 ( struct V_9 * V_10 )
{
struct V_91 * V_140 = V_10 -> V_24 . V_91 ;
if ( V_140 -> V_36 == NULL )
return V_141 ;
return V_10 -> V_142 ;
}
static void F_110 ( struct V_9 * V_10 )
{
F_66 ( & V_143 ) ;
F_66 ( & V_10 -> V_144 ) ;
F_111 () ;
}
static void F_112 ( struct V_9 * V_10 )
{
if ( V_10 ) {
F_113 ( & V_143 ) ;
F_113 ( & V_10 -> V_144 ) ;
}
}
static bool F_114 ( struct V_9 * V_10 )
{
F_89 ( ! F_115 () ) ;
return F_116 ( & V_10 -> V_144 ) > 0 ;
}
static bool F_117 ( struct V_9 * V_10 )
{
struct V_9 * V_122 ;
struct V_9 * V_3 ;
bool V_74 = false ;
F_29 ( & V_2 . V_43 ) ;
V_122 = V_2 . V_122 ;
V_3 = V_2 . V_3 ;
if ( ! V_122 )
goto V_145;
V_74 = F_93 ( V_10 , V_122 )
|| F_93 ( V_10 , V_3 ) ;
V_145:
F_30 ( & V_2 . V_43 ) ;
return V_74 ;
}
static bool F_118 ( struct V_9 * V_10 )
{
if ( V_2 . V_146 && V_14 != V_2 . V_146 ) {
if ( F_117 ( V_10 ) ) {
F_119 ( V_147 ) ;
F_120 ( & V_2 . V_148 , & V_147 , V_149 ) ;
if ( V_2 . V_146 )
F_121 () ;
F_122 ( & V_2 . V_148 , & V_147 ) ;
return true ;
}
}
return false ;
}
static void F_123 ( struct V_9 * V_10 ,
unsigned long * V_150 )
{
F_124 ( & V_10 -> V_151 , * V_150 ) ;
}
static void F_125 ( struct V_9 * V_10 ,
unsigned long * V_150 )
{
F_126 ( & V_10 -> V_151 , * V_150 ) ;
}
void F_127 ( struct V_9 * V_10 , struct V_94 * V_34 )
{
struct V_91 * V_152 ;
struct V_91 * V_153 ;
static char V_154 [ V_155 ] ;
int V_74 ;
if ( ! V_10 || ! V_34 )
return;
F_8 () ;
V_153 = V_10 -> V_24 . V_91 ;
V_152 = F_128 ( V_34 , V_93 ) ;
V_74 = F_129 ( V_152 , V_154 , V_155 ) ;
if ( V_74 < 0 ) {
F_10 () ;
goto V_51;
}
F_10 () ;
F_130 ( V_156 L_1 , V_154 ) ;
F_8 () ;
V_74 = F_129 ( V_153 , V_154 , V_155 ) ;
if ( V_74 < 0 ) {
F_10 () ;
goto V_51;
}
F_10 () ;
F_130 ( V_157 L_2 , V_154 ) ;
V_51:
F_130 ( V_156 L_3 ,
F_131 ( & V_10 -> V_45 , V_158 ) >> 10 ,
F_131 ( & V_10 -> V_45 , V_159 ) >> 10 ,
F_131 ( & V_10 -> V_45 , V_160 ) ) ;
F_130 ( V_156 L_4
L_5 ,
F_131 ( & V_10 -> V_139 , V_158 ) >> 10 ,
F_131 ( & V_10 -> V_139 , V_159 ) >> 10 ,
F_131 ( & V_10 -> V_139 , V_160 ) ) ;
}
static int F_132 ( struct V_9 * V_10 )
{
int V_161 = 0 ;
struct V_9 * V_107 ;
F_133 (iter, memcg)
V_161 ++ ;
return V_161 ;
}
T_1 F_134 ( struct V_9 * V_10 )
{
T_1 V_162 ;
T_1 V_139 ;
V_162 = F_131 ( & V_10 -> V_45 , V_159 ) ;
V_162 += V_163 << V_132 ;
V_139 = F_131 ( & V_10 -> V_139 , V_159 ) ;
return F_108 ( V_162 , V_139 ) ;
}
static unsigned long F_135 ( struct V_9 * V_10 ,
T_3 V_164 ,
unsigned long V_150 )
{
unsigned long V_76 = 0 ;
bool V_165 = false ;
int V_166 ;
if ( V_150 & V_167 )
V_165 = true ;
if ( ! ( V_150 & V_168 ) && V_10 -> V_169 )
V_165 = true ;
for ( V_166 = 0 ; V_166 < V_170 ; V_166 ++ ) {
if ( V_166 )
F_136 ( V_10 ) ;
V_76 += F_137 ( V_10 , V_164 , V_165 ) ;
if ( V_76 && ( V_150 & V_168 ) )
break;
if ( F_106 ( V_10 ) )
break;
if ( V_166 && ! V_76 )
break;
}
return V_76 ;
}
static bool F_138 ( struct V_9 * V_10 ,
int V_18 , bool V_165 )
{
if ( F_57 ( V_10 , V_18 , V_171 ) )
return true ;
if ( V_165 || ! V_163 )
return false ;
if ( F_57 ( V_10 , V_18 , V_172 ) )
return true ;
return false ;
}
static void F_139 ( struct V_9 * V_10 )
{
int V_18 ;
if ( ! F_116 ( & V_10 -> V_90 ) )
return;
if ( F_140 ( & V_10 -> V_173 ) > 1 )
return;
V_10 -> V_174 = V_175 [ V_176 ] ;
F_141 (nid, node_states[N_HIGH_MEMORY]) {
if ( ! F_138 ( V_10 , V_18 , false ) )
F_142 ( V_18 , V_10 -> V_174 ) ;
}
F_143 ( & V_10 -> V_90 , 0 ) ;
F_143 ( & V_10 -> V_173 , 0 ) ;
}
int F_144 ( struct V_9 * V_10 )
{
int V_46 ;
F_139 ( V_10 ) ;
V_46 = V_10 -> V_177 ;
V_46 = F_145 ( V_46 , V_10 -> V_174 ) ;
if ( V_46 == V_89 )
V_46 = F_146 ( V_10 -> V_174 ) ;
if ( F_64 ( V_46 == V_89 ) )
V_46 = F_147 () ;
V_10 -> V_177 = V_46 ;
return V_46 ;
}
bool F_148 ( struct V_9 * V_10 , bool V_165 )
{
int V_18 ;
if ( ! F_149 ( V_10 -> V_174 ) ) {
for ( V_18 = F_146 ( V_10 -> V_174 ) ;
V_18 < V_89 ;
V_18 = F_145 ( V_18 , V_10 -> V_174 ) ) {
if ( F_138 ( V_10 , V_18 , V_165 ) )
return true ;
}
}
F_59 (nid, N_HIGH_MEMORY) {
if ( F_150 ( V_18 , V_10 -> V_174 ) )
continue;
if ( F_138 ( V_10 , V_18 , V_165 ) )
return true ;
}
return false ;
}
int F_144 ( struct V_9 * V_10 )
{
return 0 ;
}
bool F_148 ( struct V_9 * V_10 , bool V_165 )
{
return F_138 ( V_10 , 0 , V_165 ) ;
}
static int F_151 ( struct V_9 * V_123 ,
struct V_47 * V_47 ,
T_3 V_164 ,
unsigned long * V_178 )
{
struct V_9 * V_179 = NULL ;
int V_76 = 0 ;
int V_166 = 0 ;
unsigned long V_44 ;
unsigned long V_180 ;
struct V_100 V_101 = {
. V_47 = V_47 ,
. V_109 = 0 ,
} ;
V_44 = F_33 ( & V_123 -> V_45 ) >> V_132 ;
while ( 1 ) {
V_179 = F_72 ( V_123 , V_179 , & V_101 ) ;
if ( ! V_179 ) {
V_166 ++ ;
if ( V_166 >= 2 ) {
if ( ! V_76 )
break;
if ( V_76 >= ( V_44 >> 2 ) ||
( V_166 > V_170 ) )
break;
}
continue;
}
if ( ! F_148 ( V_179 , false ) )
continue;
V_76 += F_152 ( V_179 , V_164 , false ,
V_47 , & V_180 ) ;
* V_178 += V_180 ;
if ( ! F_33 ( & V_123 -> V_45 ) )
break;
}
F_79 ( V_123 , V_179 ) ;
return V_76 ;
}
static bool F_153 ( struct V_9 * V_10 )
{
struct V_9 * V_107 , * V_181 = NULL ;
F_133 (iter, memcg) {
if ( V_107 -> V_182 ) {
V_181 = V_107 ;
F_79 ( V_10 , V_107 ) ;
break;
} else
V_107 -> V_182 = true ;
}
if ( ! V_181 )
return true ;
F_133 (iter, memcg) {
if ( V_107 == V_181 ) {
F_79 ( V_10 , V_107 ) ;
break;
}
V_107 -> V_182 = false ;
}
return false ;
}
static int F_154 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_133 (iter, memcg)
V_107 -> V_182 = false ;
return 0 ;
}
static void F_155 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_133 (iter, memcg)
F_66 ( & V_107 -> V_183 ) ;
}
static void F_156 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_133 (iter, memcg)
F_157 ( & V_107 -> V_183 , - 1 , 0 ) ;
}
static int F_158 ( T_4 * V_147 ,
unsigned V_184 , int V_185 , void * V_186 )
{
struct V_9 * V_187 = (struct V_9 * ) V_186 ;
struct V_9 * V_188 ;
struct V_189 * V_189 ;
V_189 = F_68 ( V_147 , struct V_189 , V_147 ) ;
V_188 = V_189 -> V_10 ;
if ( ! F_93 ( V_188 , V_187 )
&& ! F_93 ( V_187 , V_188 ) )
return 0 ;
return F_159 ( V_147 , V_184 , V_185 , V_186 ) ;
}
static void F_160 ( struct V_9 * V_10 )
{
F_161 ( & V_190 , V_191 , 0 , V_10 ) ;
}
static void F_162 ( struct V_9 * V_10 )
{
if ( V_10 && F_116 ( & V_10 -> V_183 ) )
F_160 ( V_10 ) ;
}
bool F_163 ( struct V_9 * V_10 , T_3 V_192 , int V_193 )
{
struct V_189 V_194 ;
bool V_195 , V_196 ;
V_194 . V_10 = V_10 ;
V_194 . V_147 . V_150 = 0 ;
V_194 . V_147 . V_197 = F_158 ;
V_194 . V_147 . V_198 = V_14 ;
F_164 ( & V_194 . V_147 . V_199 ) ;
V_196 = true ;
F_155 ( V_10 ) ;
F_29 ( & V_200 ) ;
V_195 = F_153 ( V_10 ) ;
F_120 ( & V_190 , & V_194 . V_147 , V_201 ) ;
if ( ! V_195 || V_10 -> V_202 )
V_196 = false ;
if ( V_195 )
F_165 ( V_10 ) ;
F_30 ( & V_200 ) ;
if ( V_196 ) {
F_122 ( & V_190 , & V_194 . V_147 ) ;
F_166 ( V_10 , V_192 , V_193 ) ;
} else {
F_121 () ;
F_122 ( & V_190 , & V_194 . V_147 ) ;
}
F_29 ( & V_200 ) ;
if ( V_195 )
F_154 ( V_10 ) ;
F_160 ( V_10 ) ;
F_30 ( & V_200 ) ;
F_156 ( V_10 ) ;
if ( F_167 ( V_203 ) || F_168 ( V_14 ) )
return false ;
F_169 ( 1 ) ;
return true ;
}
void F_170 ( struct V_25 * V_25 ,
bool * V_195 , unsigned long * V_150 )
{
struct V_9 * V_10 ;
struct V_120 * V_121 ;
V_121 = F_85 ( V_25 ) ;
V_204:
V_10 = V_121 -> V_9 ;
if ( F_64 ( ! V_10 || ! F_86 ( V_121 ) ) )
return;
if ( ! F_114 ( V_10 ) )
return;
F_123 ( V_10 , V_150 ) ;
if ( V_10 != V_121 -> V_9 || ! F_86 ( V_121 ) ) {
F_125 ( V_10 , V_150 ) ;
goto V_204;
}
* V_195 = true ;
}
void F_171 ( struct V_25 * V_25 , unsigned long * V_150 )
{
struct V_120 * V_121 = F_85 ( V_25 ) ;
F_125 ( V_121 -> V_9 , V_150 ) ;
}
void F_172 ( struct V_25 * V_25 ,
enum V_205 V_53 , int V_54 )
{
struct V_9 * V_10 ;
struct V_120 * V_121 = F_85 ( V_25 ) ;
unsigned long V_106 ( V_150 ) ;
if ( F_73 () )
return;
V_10 = V_121 -> V_9 ;
if ( F_64 ( ! V_10 || ! F_86 ( V_121 ) ) )
return;
switch ( V_53 ) {
case V_206 :
V_53 = V_207 ;
break;
default:
F_82 () ;
}
F_47 ( V_10 -> V_56 -> V_57 [ V_53 ] , V_54 ) ;
}
static bool F_173 ( struct V_9 * V_10 )
{
struct V_208 * V_209 ;
bool V_74 = true ;
V_209 = & F_174 ( V_210 ) ;
if ( V_10 == V_209 -> V_211 && V_209 -> V_65 )
V_209 -> V_65 -- ;
else
V_74 = false ;
F_175 ( V_210 ) ;
return V_74 ;
}
static void F_176 ( struct V_208 * V_209 )
{
struct V_9 * V_212 = V_209 -> V_211 ;
if ( V_209 -> V_65 ) {
unsigned long V_213 = V_209 -> V_65 * V_214 ;
F_177 ( & V_212 -> V_45 , V_213 ) ;
if ( V_138 )
F_177 ( & V_212 -> V_139 , V_213 ) ;
V_209 -> V_65 = 0 ;
}
V_209 -> V_211 = NULL ;
}
static void F_178 ( struct V_215 * V_216 )
{
struct V_208 * V_209 = & F_179 ( V_210 ) ;
F_176 ( V_209 ) ;
F_180 ( V_217 , & V_209 -> V_150 ) ;
}
static void F_181 ( struct V_9 * V_10 , unsigned int V_65 )
{
struct V_208 * V_209 = & F_174 ( V_210 ) ;
if ( V_209 -> V_211 != V_10 ) {
F_176 ( V_209 ) ;
V_209 -> V_211 = V_10 ;
}
V_209 -> V_65 += V_65 ;
F_175 ( V_210 ) ;
}
static void F_182 ( struct V_9 * V_123 , bool V_185 )
{
int V_55 , V_218 ;
F_41 () ;
V_218 = F_183 () ;
F_42 (cpu) {
struct V_208 * V_209 = & F_43 ( V_210 , V_55 ) ;
struct V_9 * V_10 ;
V_10 = V_209 -> V_211 ;
if ( ! V_10 || ! V_209 -> V_65 )
continue;
if ( ! F_93 ( V_123 , V_10 ) )
continue;
if ( ! F_184 ( V_217 , & V_209 -> V_150 ) ) {
if ( V_55 == V_218 )
F_178 ( & V_209 -> V_219 ) ;
else
F_185 ( V_55 , & V_209 -> V_219 ) ;
}
}
F_186 () ;
if ( ! V_185 )
goto V_114;
F_42 (cpu) {
struct V_208 * V_209 = & F_43 ( V_210 , V_55 ) ;
if ( F_2 ( V_217 , & V_209 -> V_150 ) )
F_187 ( & V_209 -> V_219 ) ;
}
V_114:
F_45 () ;
}
static void F_136 ( struct V_9 * V_123 )
{
if ( ! F_188 ( & V_220 ) )
return;
F_182 ( V_123 , false ) ;
F_189 ( & V_220 ) ;
}
static void F_190 ( struct V_9 * V_123 )
{
F_191 ( & V_220 ) ;
F_182 ( V_123 , true ) ;
F_189 ( & V_220 ) ;
}
static void F_192 ( struct V_9 * V_10 , int V_55 )
{
int V_221 ;
F_29 ( & V_10 -> V_58 ) ;
for ( V_221 = 0 ; V_221 < V_222 ; V_221 ++ ) {
long V_223 = F_43 ( V_10 -> V_56 -> V_57 [ V_221 ] , V_55 ) ;
F_43 ( V_10 -> V_56 -> V_57 [ V_221 ] , V_55 ) = 0 ;
V_10 -> V_59 . V_57 [ V_221 ] += V_223 ;
}
for ( V_221 = 0 ; V_221 < V_224 ; V_221 ++ ) {
unsigned long V_223 = F_43 ( V_10 -> V_56 -> V_63 [ V_221 ] , V_55 ) ;
F_43 ( V_10 -> V_56 -> V_63 [ V_221 ] , V_55 ) = 0 ;
V_10 -> V_59 . V_63 [ V_221 ] += V_223 ;
}
F_30 ( & V_10 -> V_58 ) ;
}
static int T_5 F_193 ( struct V_225 * V_226 ,
unsigned long V_227 ,
void * V_228 )
{
int V_55 = ( unsigned long ) V_228 ;
struct V_208 * V_209 ;
struct V_9 * V_107 ;
if ( V_227 == V_229 )
return V_230 ;
if ( V_227 != V_231 && V_227 != V_232 )
return V_230 ;
F_194 (iter)
F_192 ( V_107 , V_55 ) ;
V_209 = & F_43 ( V_210 , V_55 ) ;
F_176 ( V_209 ) ;
return V_230 ;
}
static int F_195 ( struct V_9 * V_10 , T_3 V_164 ,
unsigned int V_65 , bool V_233 )
{
unsigned long V_234 = V_65 * V_214 ;
struct V_9 * V_235 ;
struct V_236 * V_237 ;
unsigned long V_150 = 0 ;
int V_74 ;
V_74 = F_196 ( & V_10 -> V_45 , V_234 , & V_237 ) ;
if ( F_197 ( ! V_74 ) ) {
if ( ! V_138 )
return V_238 ;
V_74 = F_196 ( & V_10 -> V_139 , V_234 , & V_237 ) ;
if ( F_197 ( ! V_74 ) )
return V_238 ;
F_177 ( & V_10 -> V_45 , V_234 ) ;
V_235 = F_198 ( V_237 , V_139 ) ;
V_150 |= V_167 ;
} else
V_235 = F_198 ( V_237 , V_45 ) ;
if ( V_65 == V_239 )
return V_240 ;
if ( ! ( V_164 & V_241 ) )
return V_242 ;
V_74 = F_135 ( V_235 , V_164 , V_150 ) ;
if ( F_106 ( V_235 ) >= V_65 )
return V_240 ;
if ( V_65 == 1 && V_74 )
return V_240 ;
if ( F_118 ( V_235 ) )
return V_240 ;
if ( ! V_233 )
return V_243 ;
if ( ! F_163 ( V_235 , V_164 , F_199 ( V_234 ) ) )
return V_244 ;
return V_240 ;
}
static int F_200 ( struct V_95 * V_96 ,
T_3 V_164 ,
unsigned int V_65 ,
struct V_9 * * V_245 ,
bool V_246 )
{
unsigned int V_247 = F_201 ( V_239 , V_65 ) ;
int V_248 = V_249 ;
struct V_9 * V_10 = NULL ;
int V_74 ;
if ( F_64 ( F_167 ( V_203 )
|| F_168 ( V_14 ) ) )
goto V_250;
if ( ! * V_245 && ! V_96 )
* V_245 = V_103 ;
V_204:
if ( * V_245 ) {
V_10 = * V_245 ;
F_89 ( F_202 ( & V_10 -> V_24 ) ) ;
if ( F_6 ( V_10 ) )
goto V_51;
if ( V_65 == 1 && F_173 ( V_10 ) )
goto V_51;
F_99 ( & V_10 -> V_24 ) ;
} else {
struct V_94 * V_34 ;
F_8 () ;
V_34 = F_71 ( V_96 -> V_97 ) ;
V_10 = F_9 ( V_34 ) ;
if ( ! V_10 )
V_10 = V_103 ;
if ( F_6 ( V_10 ) ) {
F_10 () ;
goto V_51;
}
if ( V_65 == 1 && F_173 ( V_10 ) ) {
F_10 () ;
goto V_51;
}
if ( ! F_38 ( & V_10 -> V_24 ) ) {
F_10 () ;
goto V_204;
}
F_10 () ;
}
do {
bool V_233 ;
if ( F_168 ( V_14 ) ) {
F_75 ( & V_10 -> V_24 ) ;
goto V_250;
}
V_233 = false ;
if ( V_246 && ! V_248 ) {
V_233 = true ;
V_248 = V_249 ;
}
V_74 = F_195 ( V_10 , V_164 , V_247 , V_233 ) ;
switch ( V_74 ) {
case V_238 :
break;
case V_240 :
V_247 = V_65 ;
F_75 ( & V_10 -> V_24 ) ;
V_10 = NULL ;
goto V_204;
case V_242 :
F_75 ( & V_10 -> V_24 ) ;
goto V_251;
case V_243 :
if ( ! V_246 ) {
F_75 ( & V_10 -> V_24 ) ;
goto V_251;
}
V_248 -- ;
break;
case V_244 :
F_75 ( & V_10 -> V_24 ) ;
goto V_250;
}
} while ( V_74 != V_238 );
if ( V_247 > V_65 )
F_181 ( V_10 , V_247 - V_65 ) ;
F_75 ( & V_10 -> V_24 ) ;
V_51:
* V_245 = V_10 ;
return 0 ;
V_251:
* V_245 = NULL ;
return - V_252 ;
V_250:
* V_245 = V_103 ;
return - V_253 ;
}
static void F_203 ( struct V_9 * V_10 ,
unsigned int V_65 )
{
if ( ! F_6 ( V_10 ) ) {
unsigned long V_213 = V_65 * V_214 ;
F_177 ( & V_10 -> V_45 , V_213 ) ;
if ( V_138 )
F_177 ( & V_10 -> V_139 , V_213 ) ;
}
}
static struct V_9 * F_204 ( unsigned short V_102 )
{
struct V_23 * V_24 ;
if ( ! V_102 )
return NULL ;
V_24 = F_205 ( & V_112 , V_102 ) ;
if ( ! V_24 )
return NULL ;
return F_68 ( V_24 , struct V_9 , V_24 ) ;
}
struct V_9 * F_206 ( struct V_25 * V_25 )
{
struct V_9 * V_10 = NULL ;
struct V_120 * V_121 ;
unsigned short V_102 ;
T_6 V_254 ;
F_89 ( ! F_207 ( V_25 ) ) ;
V_121 = F_85 ( V_25 ) ;
F_208 ( V_121 ) ;
if ( F_86 ( V_121 ) ) {
V_10 = V_121 -> V_9 ;
if ( V_10 && ! F_38 ( & V_10 -> V_24 ) )
V_10 = NULL ;
} else if ( F_209 ( V_25 ) ) {
V_254 . V_54 = F_210 ( V_25 ) ;
V_102 = F_211 ( V_254 ) ;
F_8 () ;
V_10 = F_204 ( V_102 ) ;
if ( V_10 && ! F_38 ( & V_10 -> V_24 ) )
V_10 = NULL ;
F_10 () ;
}
F_212 ( V_121 ) ;
return V_10 ;
}
static void F_213 ( struct V_9 * V_10 ,
struct V_25 * V_25 ,
unsigned int V_65 ,
enum V_255 V_256 ,
bool V_257 )
{
struct V_120 * V_121 = F_85 ( V_25 ) ;
struct V_47 * V_106 ( V_47 ) ;
bool V_258 = false ;
bool V_64 ;
F_208 ( V_121 ) ;
if ( F_64 ( F_86 ( V_121 ) ) ) {
F_212 ( V_121 ) ;
F_203 ( V_10 , V_65 ) ;
return;
}
if ( V_257 ) {
V_47 = F_214 ( V_25 ) ;
F_215 ( & V_47 -> V_259 ) ;
if ( F_216 ( V_25 ) ) {
F_217 ( V_25 ) ;
F_218 ( V_47 , V_25 , F_91 ( V_25 ) ) ;
V_258 = true ;
}
}
V_121 -> V_9 = V_10 ;
F_219 () ;
F_220 ( V_121 ) ;
if ( V_257 ) {
if ( V_258 ) {
F_89 ( F_216 ( V_25 ) ) ;
F_221 ( V_25 ) ;
F_222 ( V_47 , V_25 , F_91 ( V_25 ) ) ;
}
F_223 ( & V_47 -> V_259 ) ;
}
if ( V_256 == V_260 )
V_64 = true ;
else
V_64 = false ;
F_49 ( V_10 , V_64 , V_65 ) ;
F_212 ( V_121 ) ;
F_63 ( V_10 , V_25 ) ;
}
void F_224 ( struct V_25 * V_261 )
{
struct V_120 * V_262 = F_85 ( V_261 ) ;
struct V_120 * V_121 ;
int V_221 ;
if ( F_73 () )
return;
for ( V_221 = 1 ; V_221 < V_263 ; V_221 ++ ) {
V_121 = V_262 + V_221 ;
V_121 -> V_9 = V_262 -> V_9 ;
F_219 () ;
V_121 -> V_150 = V_262 -> V_150 & ~ V_264 ;
}
}
static int F_225 ( struct V_25 * V_25 ,
unsigned int V_65 ,
struct V_120 * V_121 ,
struct V_9 * V_122 ,
struct V_9 * V_3 ,
bool V_265 )
{
unsigned long V_150 ;
int V_74 ;
bool V_64 = F_226 ( V_25 ) ;
F_89 ( V_122 == V_3 ) ;
F_89 ( F_216 ( V_25 ) ) ;
V_74 = - V_266 ;
if ( V_65 > 1 && ! F_227 ( V_25 ) )
goto V_114;
F_208 ( V_121 ) ;
V_74 = - V_267 ;
if ( ! F_86 ( V_121 ) || V_121 -> V_9 != V_122 )
goto V_145;
F_123 ( V_122 , & V_150 ) ;
if ( ! V_64 && F_228 ( V_25 ) ) {
F_50 () ;
F_229 ( V_122 -> V_56 -> V_57 [ V_207 ] ) ;
F_52 ( V_3 -> V_56 -> V_57 [ V_207 ] ) ;
F_53 () ;
}
F_49 ( V_122 , V_64 , - V_65 ) ;
if ( V_265 )
F_203 ( V_122 , V_65 ) ;
V_121 -> V_9 = V_3 ;
F_49 ( V_3 , V_64 , V_65 ) ;
F_125 ( V_122 , & V_150 ) ;
V_74 = 0 ;
V_145:
F_212 ( V_121 ) ;
F_63 ( V_3 , V_25 ) ;
F_63 ( V_122 , V_25 ) ;
V_114:
return V_74 ;
}
static int F_230 ( struct V_25 * V_25 ,
struct V_120 * V_121 ,
struct V_9 * V_268 ,
T_3 V_164 )
{
struct V_91 * V_269 = V_268 -> V_24 . V_91 ;
struct V_91 * V_270 = V_269 -> V_36 ;
struct V_9 * V_36 ;
unsigned int V_65 ;
unsigned long V_106 ( V_150 ) ;
int V_74 ;
if ( ! V_270 )
return - V_267 ;
V_74 = - V_266 ;
if ( ! F_231 ( V_25 ) )
goto V_114;
if ( F_232 ( V_25 ) )
goto V_271;
V_65 = F_233 ( V_25 ) ;
V_36 = F_67 ( V_270 ) ;
V_74 = F_200 ( NULL , V_164 , V_65 , & V_36 , false ) ;
if ( V_74 )
goto V_272;
if ( V_65 > 1 )
V_150 = F_234 ( V_25 ) ;
V_74 = F_225 ( V_25 , V_65 , V_121 , V_268 , V_36 , true ) ;
if ( V_74 )
F_203 ( V_36 , V_65 ) ;
if ( V_65 > 1 )
F_235 ( V_25 , V_150 ) ;
V_272:
F_236 ( V_25 ) ;
V_271:
F_237 ( V_25 ) ;
V_114:
return V_74 ;
}
static int F_238 ( struct V_25 * V_25 , struct V_95 * V_96 ,
T_3 V_164 , enum V_255 V_256 )
{
struct V_9 * V_10 = NULL ;
unsigned int V_65 = 1 ;
bool V_246 = true ;
int V_74 ;
if ( F_227 ( V_25 ) ) {
V_65 <<= F_87 ( V_25 ) ;
F_89 ( ! F_227 ( V_25 ) ) ;
V_246 = false ;
}
V_74 = F_200 ( V_96 , V_164 , V_65 , & V_10 , V_246 ) ;
if ( V_74 == - V_252 )
return V_74 ;
F_213 ( V_10 , V_25 , V_65 , V_256 , false ) ;
return 0 ;
}
int F_239 ( struct V_25 * V_25 ,
struct V_95 * V_96 , T_3 V_164 )
{
if ( F_73 () )
return 0 ;
F_89 ( F_228 ( V_25 ) ) ;
F_89 ( V_25 -> V_273 && ! F_226 ( V_25 ) ) ;
F_89 ( ! V_96 ) ;
return F_238 ( V_25 , V_96 , V_164 ,
V_260 ) ;
}
int F_240 ( struct V_25 * V_25 , struct V_95 * V_96 ,
T_3 V_164 )
{
struct V_9 * V_10 = NULL ;
enum V_255 type = V_274 ;
int V_74 ;
if ( F_73 () )
return 0 ;
if ( F_241 ( V_25 ) )
return 0 ;
if ( F_64 ( ! V_96 ) )
V_96 = & V_275 ;
if ( ! F_242 ( V_25 ) )
type = V_276 ;
if ( ! F_209 ( V_25 ) )
V_74 = F_238 ( V_25 , V_96 , V_164 , type ) ;
else {
V_74 = F_243 ( V_96 , V_25 , V_164 , & V_10 ) ;
if ( ! V_74 )
F_244 ( V_25 , V_10 , type ) ;
}
return V_74 ;
}
int F_243 ( struct V_95 * V_96 ,
struct V_25 * V_25 ,
T_3 V_192 , struct V_9 * * V_277 )
{
struct V_9 * V_10 ;
int V_74 ;
* V_277 = NULL ;
if ( F_73 () )
return 0 ;
if ( ! V_138 )
goto V_278;
if ( ! F_209 ( V_25 ) )
goto V_278;
V_10 = F_206 ( V_25 ) ;
if ( ! V_10 )
goto V_278;
* V_277 = V_10 ;
V_74 = F_200 ( NULL , V_192 , 1 , V_277 , true ) ;
F_75 ( & V_10 -> V_24 ) ;
if ( V_74 == - V_253 )
V_74 = 0 ;
return V_74 ;
V_278:
if ( F_64 ( ! V_96 ) )
V_96 = & V_275 ;
V_74 = F_200 ( V_96 , V_192 , 1 , V_277 , true ) ;
if ( V_74 == - V_253 )
V_74 = 0 ;
return V_74 ;
}
static void
F_244 ( struct V_25 * V_25 , struct V_9 * V_10 ,
enum V_255 V_256 )
{
if ( F_73 () )
return;
if ( ! V_10 )
return;
F_245 ( & V_10 -> V_24 ) ;
F_213 ( V_10 , V_25 , 1 , V_256 , true ) ;
if ( V_138 && F_209 ( V_25 ) ) {
T_6 V_254 = { . V_54 = F_210 (page) } ;
struct V_9 * V_279 ;
unsigned short V_102 ;
V_102 = F_246 ( V_254 , 0 ) ;
F_8 () ;
V_279 = F_204 ( V_102 ) ;
if ( V_279 ) {
if ( ! F_6 ( V_279 ) )
F_177 ( & V_279 -> V_139 ,
V_214 ) ;
F_46 ( V_279 , false ) ;
F_13 ( V_279 ) ;
}
F_10 () ;
}
F_247 ( & V_10 -> V_24 ) ;
}
void F_248 ( struct V_25 * V_25 ,
struct V_9 * V_10 )
{
F_244 ( V_25 , V_10 ,
V_260 ) ;
}
void F_249 ( struct V_9 * V_10 )
{
if ( F_73 () )
return;
if ( ! V_10 )
return;
F_203 ( V_10 , 1 ) ;
}
static void F_250 ( struct V_9 * V_10 ,
unsigned int V_65 ,
const enum V_255 V_256 )
{
struct V_280 * V_247 = NULL ;
bool V_281 = true ;
if ( ! V_138 || V_256 == V_282 )
V_281 = false ;
V_247 = & V_14 -> V_283 ;
if ( ! V_247 -> V_10 )
V_247 -> V_10 = V_10 ;
if ( ! V_247 -> V_284 || F_167 ( V_203 ) )
goto V_285;
if ( V_65 > 1 )
goto V_285;
if ( V_247 -> V_10 != V_10 )
goto V_285;
V_247 -> V_65 ++ ;
if ( V_281 )
V_247 -> V_286 ++ ;
return;
V_285:
F_177 ( & V_10 -> V_45 , V_65 * V_214 ) ;
if ( V_281 )
F_177 ( & V_10 -> V_139 , V_65 * V_214 ) ;
if ( F_64 ( V_247 -> V_10 != V_10 ) )
F_162 ( V_10 ) ;
}
static struct V_9 *
F_251 ( struct V_25 * V_25 , enum V_255 V_256 )
{
struct V_9 * V_10 = NULL ;
unsigned int V_65 = 1 ;
struct V_120 * V_121 ;
bool V_64 ;
if ( F_73 () )
return NULL ;
if ( F_209 ( V_25 ) )
return NULL ;
if ( F_227 ( V_25 ) ) {
V_65 <<= F_87 ( V_25 ) ;
F_89 ( ! F_227 ( V_25 ) ) ;
}
V_121 = F_85 ( V_25 ) ;
if ( F_64 ( ! F_86 ( V_121 ) ) )
return NULL ;
F_208 ( V_121 ) ;
V_10 = V_121 -> V_9 ;
if ( ! F_86 ( V_121 ) )
goto V_287;
V_64 = F_226 ( V_25 ) ;
switch ( V_256 ) {
case V_260 :
V_64 = true ;
case V_288 :
if ( F_228 ( V_25 ) || F_252 ( V_121 ) )
goto V_287;
break;
case V_282 :
if ( ! F_226 ( V_25 ) ) {
if ( V_25 -> V_273 && ! F_242 ( V_25 ) )
goto V_287;
} else if ( F_228 ( V_25 ) )
goto V_287;
break;
default:
break;
}
F_49 ( V_10 , V_64 , - V_65 ) ;
F_253 ( V_121 ) ;
F_212 ( V_121 ) ;
F_63 ( V_10 , V_25 ) ;
if ( V_138 && V_256 == V_282 ) {
F_46 ( V_10 , true ) ;
F_7 ( V_10 ) ;
}
if ( ! F_6 ( V_10 ) )
F_250 ( V_10 , V_65 , V_256 ) ;
return V_10 ;
V_287:
F_212 ( V_121 ) ;
return NULL ;
}
void F_254 ( struct V_25 * V_25 )
{
if ( F_228 ( V_25 ) )
return;
F_89 ( V_25 -> V_273 && ! F_226 ( V_25 ) ) ;
F_251 ( V_25 , V_260 ) ;
}
void F_255 ( struct V_25 * V_25 )
{
F_89 ( F_228 ( V_25 ) ) ;
F_89 ( V_25 -> V_273 ) ;
F_251 ( V_25 , V_274 ) ;
}
void F_256 ( void )
{
V_14 -> V_283 . V_284 ++ ;
if ( V_14 -> V_283 . V_284 == 1 ) {
V_14 -> V_283 . V_10 = NULL ;
V_14 -> V_283 . V_65 = 0 ;
V_14 -> V_283 . V_286 = 0 ;
}
}
void F_257 ( void )
{
struct V_280 * V_247 = & V_14 -> V_283 ;
if ( ! V_247 -> V_284 )
return;
V_247 -> V_284 -- ;
if ( V_247 -> V_284 )
return;
if ( ! V_247 -> V_10 )
return;
if ( V_247 -> V_65 )
F_177 ( & V_247 -> V_10 -> V_45 ,
V_247 -> V_65 * V_214 ) ;
if ( V_247 -> V_286 )
F_177 ( & V_247 -> V_10 -> V_139 ,
V_247 -> V_286 * V_214 ) ;
F_162 ( V_247 -> V_10 ) ;
V_247 -> V_10 = NULL ;
}
void
F_258 ( struct V_25 * V_25 , T_6 V_254 , bool V_289 )
{
struct V_9 * V_10 ;
int V_256 = V_282 ;
if ( ! V_289 )
V_256 = V_288 ;
V_10 = F_251 ( V_25 , V_256 ) ;
if ( V_138 && V_289 && V_10 )
F_246 ( V_254 , F_74 ( & V_10 -> V_24 ) ) ;
}
void F_259 ( T_6 V_254 )
{
struct V_9 * V_10 ;
unsigned short V_102 ;
if ( ! V_138 )
return;
V_102 = F_246 ( V_254 , 0 ) ;
F_8 () ;
V_10 = F_204 ( V_102 ) ;
if ( V_10 ) {
if ( ! F_6 ( V_10 ) )
F_177 ( & V_10 -> V_139 , V_214 ) ;
F_46 ( V_10 , false ) ;
F_13 ( V_10 ) ;
}
F_10 () ;
}
static int F_260 ( T_6 V_290 ,
struct V_9 * V_122 , struct V_9 * V_3 , bool V_291 )
{
unsigned short V_292 , V_293 ;
V_292 = F_74 ( & V_122 -> V_24 ) ;
V_293 = F_74 ( & V_3 -> V_24 ) ;
if ( F_261 ( V_290 , V_292 , V_293 ) == V_292 ) {
F_46 ( V_122 , false ) ;
F_46 ( V_3 , true ) ;
F_7 ( V_3 ) ;
if ( V_291 ) {
if ( ! F_6 ( V_122 ) )
F_177 ( & V_122 -> V_139 , V_214 ) ;
F_13 ( V_122 ) ;
if ( ! F_6 ( V_3 ) )
F_177 ( & V_3 -> V_45 , V_214 ) ;
}
return 0 ;
}
return - V_267 ;
}
static inline int F_260 ( T_6 V_290 ,
struct V_9 * V_122 , struct V_9 * V_3 , bool V_291 )
{
return - V_267 ;
}
int F_262 ( struct V_25 * V_25 ,
struct V_25 * V_294 , struct V_9 * * V_277 , T_3 V_164 )
{
struct V_9 * V_10 = NULL ;
struct V_120 * V_121 ;
enum V_255 V_256 ;
int V_74 = 0 ;
* V_277 = NULL ;
F_89 ( F_227 ( V_25 ) ) ;
if ( F_73 () )
return 0 ;
V_121 = F_85 ( V_25 ) ;
F_208 ( V_121 ) ;
if ( F_86 ( V_121 ) ) {
V_10 = V_121 -> V_9 ;
F_99 ( & V_10 -> V_24 ) ;
if ( F_226 ( V_25 ) )
F_263 ( V_121 ) ;
}
F_212 ( V_121 ) ;
if ( ! V_10 )
return 0 ;
* V_277 = V_10 ;
V_74 = F_200 ( NULL , V_164 , 1 , V_277 , false ) ;
F_75 ( & V_10 -> V_24 ) ;
if ( V_74 ) {
if ( F_226 ( V_25 ) ) {
F_208 ( V_121 ) ;
F_264 ( V_121 ) ;
F_212 ( V_121 ) ;
F_254 ( V_25 ) ;
}
return - V_252 ;
}
if ( F_226 ( V_25 ) )
V_256 = V_260 ;
else if ( F_242 ( V_25 ) )
V_256 = V_274 ;
else
V_256 = V_276 ;
F_213 ( V_10 , V_294 , 1 , V_256 , false ) ;
return V_74 ;
}
void F_265 ( struct V_9 * V_10 ,
struct V_25 * V_295 , struct V_25 * V_294 , bool V_296 )
{
struct V_25 * V_297 , * V_298 ;
struct V_120 * V_121 ;
bool V_64 ;
if ( ! V_10 )
return;
F_245 ( & V_10 -> V_24 ) ;
if ( ! V_296 ) {
V_297 = V_295 ;
V_298 = V_294 ;
} else {
V_297 = V_294 ;
V_298 = V_295 ;
}
V_121 = F_85 ( V_295 ) ;
F_208 ( V_121 ) ;
F_264 ( V_121 ) ;
F_212 ( V_121 ) ;
V_64 = F_226 ( V_297 ) ;
F_251 ( V_298 ,
V_64 ? V_260
: V_274 ) ;
if ( V_64 )
F_254 ( V_297 ) ;
F_247 ( & V_10 -> V_24 ) ;
}
void F_266 ( struct V_25 * V_295 ,
struct V_25 * V_294 )
{
struct V_9 * V_10 ;
struct V_120 * V_121 ;
enum V_255 type = V_274 ;
if ( F_73 () )
return;
V_121 = F_85 ( V_295 ) ;
F_208 ( V_121 ) ;
V_10 = V_121 -> V_9 ;
F_49 ( V_10 , false , - 1 ) ;
F_253 ( V_121 ) ;
F_212 ( V_121 ) ;
if ( F_267 ( V_295 ) )
type = V_276 ;
F_213 ( V_10 , V_294 , 1 , type , true ) ;
}
static struct V_120 * F_268 ( struct V_25 * V_25 )
{
struct V_120 * V_121 ;
V_121 = F_85 ( V_25 ) ;
if ( F_197 ( V_121 ) && F_86 ( V_121 ) )
return V_121 ;
return NULL ;
}
bool F_269 ( struct V_25 * V_25 )
{
if ( F_73 () )
return false ;
return F_268 ( V_25 ) != NULL ;
}
void F_270 ( struct V_25 * V_25 )
{
struct V_120 * V_121 ;
V_121 = F_268 ( V_25 ) ;
if ( V_121 ) {
F_130 ( V_299 L_6 ,
V_121 , V_121 -> V_150 , V_121 -> V_9 ) ;
}
}
static int F_271 ( struct V_9 * V_10 ,
unsigned long long V_54 )
{
int V_300 ;
T_1 V_301 , V_302 ;
int V_74 = 0 ;
int V_303 = F_132 ( V_10 ) ;
T_1 V_304 , V_305 ;
int V_306 ;
V_300 = V_249 * V_303 ;
V_305 = F_131 ( & V_10 -> V_45 , V_158 ) ;
V_306 = 0 ;
while ( V_300 ) {
if ( F_272 ( V_14 ) ) {
V_74 = - V_253 ;
break;
}
F_191 ( & V_307 ) ;
V_301 = F_131 ( & V_10 -> V_139 , V_159 ) ;
if ( V_301 < V_54 ) {
V_74 = - V_267 ;
F_189 ( & V_307 ) ;
break;
}
V_302 = F_131 ( & V_10 -> V_45 , V_159 ) ;
if ( V_302 < V_54 )
V_306 = 1 ;
V_74 = F_273 ( & V_10 -> V_45 , V_54 ) ;
if ( ! V_74 ) {
if ( V_301 == V_54 )
V_10 -> V_169 = true ;
else
V_10 -> V_169 = false ;
}
F_189 ( & V_307 ) ;
if ( ! V_74 )
break;
F_135 ( V_10 , V_308 ,
V_168 ) ;
V_304 = F_131 ( & V_10 -> V_45 , V_158 ) ;
if ( V_304 >= V_305 )
V_300 -- ;
else
V_305 = V_304 ;
}
if ( ! V_74 && V_306 )
F_162 ( V_10 ) ;
return V_74 ;
}
static int F_274 ( struct V_9 * V_10 ,
unsigned long long V_54 )
{
int V_300 ;
T_1 V_302 , V_301 , V_305 , V_304 ;
int V_303 = F_132 ( V_10 ) ;
int V_74 = - V_266 ;
int V_306 = 0 ;
V_300 = V_303 * V_249 ;
V_305 = F_131 ( & V_10 -> V_139 , V_158 ) ;
while ( V_300 ) {
if ( F_272 ( V_14 ) ) {
V_74 = - V_253 ;
break;
}
F_191 ( & V_307 ) ;
V_302 = F_131 ( & V_10 -> V_45 , V_159 ) ;
if ( V_302 > V_54 ) {
V_74 = - V_267 ;
F_189 ( & V_307 ) ;
break;
}
V_301 = F_131 ( & V_10 -> V_139 , V_159 ) ;
if ( V_301 < V_54 )
V_306 = 1 ;
V_74 = F_273 ( & V_10 -> V_139 , V_54 ) ;
if ( ! V_74 ) {
if ( V_302 == V_54 )
V_10 -> V_169 = true ;
else
V_10 -> V_169 = false ;
}
F_189 ( & V_307 ) ;
if ( ! V_74 )
break;
F_135 ( V_10 , V_308 ,
V_167 |
V_168 ) ;
V_304 = F_131 ( & V_10 -> V_139 , V_158 ) ;
if ( V_304 >= V_305 )
V_300 -- ;
else
V_305 = V_304 ;
}
if ( ! V_74 && V_306 )
F_162 ( V_10 ) ;
return V_74 ;
}
unsigned long F_275 ( struct V_47 * V_47 , int V_193 ,
T_3 V_164 ,
unsigned long * V_178 )
{
unsigned long V_309 = 0 ;
struct V_17 * V_30 , * V_310 = NULL ;
unsigned long V_311 ;
int V_166 = 0 ;
struct V_26 * V_31 ;
unsigned long long V_44 ;
unsigned long V_180 ;
if ( V_193 > 0 )
return 0 ;
V_31 = F_20 ( F_76 ( V_47 ) , F_77 ( V_47 ) ) ;
do {
if ( V_310 )
V_30 = V_310 ;
else
V_30 = F_39 ( V_31 ) ;
if ( ! V_30 )
break;
V_180 = 0 ;
V_311 = F_151 ( V_30 -> V_10 , V_47 ,
V_164 , & V_180 ) ;
V_309 += V_311 ;
* V_178 += V_180 ;
F_29 ( & V_31 -> V_43 ) ;
V_310 = NULL ;
if ( ! V_311 ) {
do {
V_310 =
F_36 ( V_31 ) ;
if ( V_310 == V_30 )
F_75 ( & V_310 -> V_10 -> V_24 ) ;
else
break;
} while ( 1 );
}
F_26 ( V_30 -> V_10 , V_30 , V_31 ) ;
V_44 = F_33 ( & V_30 -> V_10 -> V_45 ) ;
F_22 ( V_30 -> V_10 , V_30 , V_31 , V_44 ) ;
F_30 ( & V_31 -> V_43 ) ;
F_75 ( & V_30 -> V_10 -> V_24 ) ;
V_166 ++ ;
if ( ! V_309 &&
( V_310 == NULL ||
V_166 > V_312 ) )
break;
} while ( ! V_309 );
if ( V_310 )
F_75 ( & V_310 -> V_10 -> V_24 ) ;
return V_309 ;
}
static int F_276 ( struct V_9 * V_10 ,
int V_46 , int V_19 , enum V_72 V_73 )
{
struct V_17 * V_30 ;
unsigned long V_150 , V_166 ;
struct V_313 * V_314 ;
struct V_25 * V_315 ;
struct V_47 * V_47 ;
int V_74 = 0 ;
V_47 = & F_277 ( V_46 ) -> V_316 [ V_19 ] ;
V_30 = F_15 ( V_10 , V_46 , V_19 ) ;
V_314 = & V_30 -> V_119 . V_317 [ V_73 ] ;
V_166 = V_30 -> V_75 [ V_73 ] ;
V_166 += 256 ;
V_315 = NULL ;
while ( V_166 -- ) {
struct V_120 * V_121 ;
struct V_25 * V_25 ;
V_74 = 0 ;
F_124 ( & V_47 -> V_259 , V_150 ) ;
if ( F_278 ( V_314 ) ) {
F_126 ( & V_47 -> V_259 , V_150 ) ;
break;
}
V_25 = F_279 ( V_314 -> V_99 , struct V_25 , V_73 ) ;
if ( V_315 == V_25 ) {
F_280 ( & V_25 -> V_73 , V_314 ) ;
V_315 = NULL ;
F_126 ( & V_47 -> V_259 , V_150 ) ;
continue;
}
F_126 ( & V_47 -> V_259 , V_150 ) ;
V_121 = F_85 ( V_25 ) ;
V_74 = F_230 ( V_25 , V_121 , V_10 , V_308 ) ;
if ( V_74 == - V_252 || V_74 == - V_253 )
break;
if ( V_74 == - V_266 || V_74 == - V_267 ) {
V_315 = V_25 ;
F_281 () ;
} else
V_315 = NULL ;
}
if ( ! V_74 && ! F_278 ( V_314 ) )
return - V_266 ;
return V_74 ;
}
static int F_282 ( struct V_9 * V_10 , bool V_318 )
{
int V_74 ;
int V_46 , V_19 , V_319 ;
int V_320 = V_249 ;
struct V_91 * V_140 = V_10 -> V_24 . V_91 ;
F_99 ( & V_10 -> V_24 ) ;
V_319 = 0 ;
if ( V_318 )
goto V_321;
V_322:
do {
V_74 = - V_266 ;
if ( F_283 ( V_140 ) || ! F_278 ( & V_140 -> V_303 ) )
goto V_114;
V_74 = - V_253 ;
if ( F_272 ( V_14 ) )
goto V_114;
F_284 () ;
F_190 ( V_10 ) ;
V_74 = 0 ;
F_110 ( V_10 ) ;
F_59 (node, N_HIGH_MEMORY) {
for ( V_19 = 0 ; ! V_74 && V_19 < V_48 ; V_19 ++ ) {
enum V_72 V_73 ;
F_55 (lru) {
V_74 = F_276 ( V_10 ,
V_46 , V_19 , V_73 ) ;
if ( V_74 )
break;
}
}
if ( V_74 )
break;
}
F_112 ( V_10 ) ;
F_162 ( V_10 ) ;
if ( V_74 == - V_252 )
goto V_321;
F_281 () ;
} while ( F_131 ( & V_10 -> V_45 , V_158 ) > 0 || V_74 );
V_114:
F_75 ( & V_10 -> V_24 ) ;
return V_74 ;
V_321:
if ( F_283 ( V_140 ) || ! F_278 ( & V_140 -> V_303 ) || V_319 ) {
V_74 = - V_266 ;
goto V_114;
}
F_284 () ;
V_319 = 1 ;
while ( V_320 && F_131 ( & V_10 -> V_45 , V_158 ) > 0 ) {
int V_323 ;
if ( F_272 ( V_14 ) ) {
V_74 = - V_253 ;
goto V_114;
}
V_323 = F_137 ( V_10 , V_308 ,
false ) ;
if ( ! V_323 ) {
V_320 -- ;
F_285 ( V_324 , V_325 / 10 ) ;
}
}
F_286 () ;
goto V_322;
}
int F_287 ( struct V_91 * V_92 , unsigned int V_326 )
{
return F_282 ( F_67 ( V_92 ) , true ) ;
}
static T_1 F_288 ( struct V_91 * V_92 , struct V_327 * V_328 )
{
return F_67 ( V_92 ) -> V_104 ;
}
static int F_289 ( struct V_91 * V_92 , struct V_327 * V_328 ,
T_1 V_54 )
{
int V_329 = 0 ;
struct V_9 * V_10 = F_67 ( V_92 ) ;
struct V_91 * V_36 = V_92 -> V_36 ;
struct V_9 * V_330 = NULL ;
if ( V_36 )
V_330 = F_67 ( V_36 ) ;
F_290 () ;
if ( ( ! V_330 || ! V_330 -> V_104 ) &&
( V_54 == 1 || V_54 == 0 ) ) {
if ( F_278 ( & V_92 -> V_303 ) )
V_10 -> V_104 = V_54 ;
else
V_329 = - V_266 ;
} else
V_329 = - V_267 ;
F_291 () ;
return V_329 ;
}
static unsigned long F_292 ( struct V_9 * V_10 ,
enum V_52 V_53 )
{
struct V_9 * V_107 ;
long V_54 = 0 ;
F_133 (iter, memcg)
V_54 += F_40 ( V_107 , V_53 ) ;
if ( V_54 < 0 )
V_54 = 0 ;
return V_54 ;
}
static inline T_1 F_293 ( struct V_9 * V_10 , bool V_331 )
{
T_1 V_54 ;
if ( ! F_6 ( V_10 ) ) {
if ( ! V_331 )
return F_131 ( & V_10 -> V_45 , V_158 ) ;
else
return F_131 ( & V_10 -> V_139 , V_158 ) ;
}
V_54 = F_292 ( V_10 , V_67 ) ;
V_54 += F_292 ( V_10 , V_66 ) ;
if ( V_331 )
V_54 += F_292 ( V_10 , V_61 ) ;
return V_54 << V_132 ;
}
static T_1 F_294 ( struct V_91 * V_92 , struct V_327 * V_328 )
{
struct V_9 * V_10 = F_67 ( V_92 ) ;
T_1 V_54 ;
int type , V_332 ;
type = F_295 ( V_328 -> V_198 ) ;
V_332 = F_296 ( V_328 -> V_198 ) ;
switch ( type ) {
case V_333 :
if ( V_332 == V_158 )
V_54 = F_293 ( V_10 , false ) ;
else
V_54 = F_131 ( & V_10 -> V_45 , V_332 ) ;
break;
case V_334 :
if ( V_332 == V_158 )
V_54 = F_293 ( V_10 , true ) ;
else
V_54 = F_131 ( & V_10 -> V_139 , V_332 ) ;
break;
default:
F_82 () ;
}
return V_54 ;
}
static int F_297 ( struct V_91 * V_92 , struct V_327 * V_328 ,
const char * V_335 )
{
struct V_9 * V_10 = F_67 ( V_92 ) ;
int type , V_332 ;
unsigned long long V_54 ;
int V_74 ;
type = F_295 ( V_328 -> V_198 ) ;
V_332 = F_296 ( V_328 -> V_198 ) ;
switch ( V_332 ) {
case V_159 :
if ( F_6 ( V_10 ) ) {
V_74 = - V_267 ;
break;
}
V_74 = F_298 ( V_335 , & V_54 ) ;
if ( V_74 )
break;
if ( type == V_333 )
V_74 = F_271 ( V_10 , V_54 ) ;
else
V_74 = F_274 ( V_10 , V_54 ) ;
break;
case V_336 :
V_74 = F_298 ( V_335 , & V_54 ) ;
if ( V_74 )
break;
if ( type == V_333 )
V_74 = F_299 ( & V_10 -> V_45 , V_54 ) ;
else
V_74 = - V_267 ;
break;
default:
V_74 = - V_267 ;
break;
}
return V_74 ;
}
static void F_300 ( struct V_9 * V_10 ,
unsigned long long * V_337 , unsigned long long * V_338 )
{
struct V_91 * V_91 ;
unsigned long long V_339 , V_340 , V_341 ;
V_339 = F_131 ( & V_10 -> V_45 , V_159 ) ;
V_340 = F_131 ( & V_10 -> V_139 , V_159 ) ;
V_91 = V_10 -> V_24 . V_91 ;
if ( ! V_10 -> V_104 )
goto V_114;
while ( V_91 -> V_36 ) {
V_91 = V_91 -> V_36 ;
V_10 = F_67 ( V_91 ) ;
if ( ! V_10 -> V_104 )
break;
V_341 = F_131 ( & V_10 -> V_45 , V_159 ) ;
V_339 = F_108 ( V_339 , V_341 ) ;
V_341 = F_131 ( & V_10 -> V_139 , V_159 ) ;
V_340 = F_108 ( V_340 , V_341 ) ;
}
V_114:
* V_337 = V_339 ;
* V_338 = V_340 ;
}
static int F_301 ( struct V_91 * V_92 , unsigned int V_326 )
{
struct V_9 * V_10 ;
int type , V_332 ;
V_10 = F_67 ( V_92 ) ;
type = F_295 ( V_326 ) ;
V_332 = F_296 ( V_326 ) ;
switch ( V_332 ) {
case V_342 :
if ( type == V_333 )
F_302 ( & V_10 -> V_45 ) ;
else
F_302 ( & V_10 -> V_139 ) ;
break;
case V_160 :
if ( type == V_333 )
F_303 ( & V_10 -> V_45 ) ;
else
F_303 ( & V_10 -> V_139 ) ;
break;
}
return 0 ;
}
static T_1 F_304 ( struct V_91 * V_140 ,
struct V_327 * V_328 )
{
return F_67 ( V_140 ) -> V_4 ;
}
static int F_305 ( struct V_91 * V_140 ,
struct V_327 * V_328 , T_1 V_54 )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
if ( V_54 >= ( 1 << V_343 ) )
return - V_267 ;
F_290 () ;
V_10 -> V_4 = V_54 ;
F_291 () ;
return 0 ;
}
static int F_305 ( struct V_91 * V_140 ,
struct V_327 * V_328 , T_1 V_54 )
{
return - V_344 ;
}
static void
F_306 ( struct V_9 * V_10 , struct V_345 * V_346 )
{
T_7 V_54 ;
V_54 = F_40 ( V_10 , V_67 ) ;
V_346 -> V_56 [ V_347 ] += V_54 * V_214 ;
V_54 = F_40 ( V_10 , V_66 ) ;
V_346 -> V_56 [ V_348 ] += V_54 * V_214 ;
V_54 = F_40 ( V_10 , V_207 ) ;
V_346 -> V_56 [ V_349 ] += V_54 * V_214 ;
V_54 = F_48 ( V_10 , V_68 ) ;
V_346 -> V_56 [ V_350 ] += V_54 ;
V_54 = F_48 ( V_10 , V_69 ) ;
V_346 -> V_56 [ V_351 ] += V_54 ;
if ( V_138 ) {
V_54 = F_40 ( V_10 , V_61 ) ;
V_346 -> V_56 [ V_352 ] += V_54 * V_214 ;
}
V_54 = F_48 ( V_10 , V_116 ) ;
V_346 -> V_56 [ V_353 ] += V_54 ;
V_54 = F_48 ( V_10 , V_118 ) ;
V_346 -> V_56 [ V_354 ] += V_54 ;
V_54 = F_58 ( V_10 , F_56 ( V_130 ) ) ;
V_346 -> V_56 [ V_355 ] += V_54 * V_214 ;
V_54 = F_58 ( V_10 , F_56 ( V_131 ) ) ;
V_346 -> V_56 [ V_356 ] += V_54 * V_214 ;
V_54 = F_58 ( V_10 , F_56 ( V_133 ) ) ;
V_346 -> V_56 [ V_357 ] += V_54 * V_214 ;
V_54 = F_58 ( V_10 , F_56 ( V_134 ) ) ;
V_346 -> V_56 [ V_358 ] += V_54 * V_214 ;
V_54 = F_58 ( V_10 , F_56 ( V_359 ) ) ;
V_346 -> V_56 [ V_360 ] += V_54 * V_214 ;
}
static void
F_307 ( struct V_9 * V_10 , struct V_345 * V_346 )
{
struct V_9 * V_107 ;
F_133 (iter, memcg)
F_306 ( V_107 , V_346 ) ;
}
static int F_308 ( struct V_361 * V_362 , void * V_186 )
{
int V_18 ;
unsigned long V_363 , V_364 , V_365 , V_366 ;
unsigned long V_367 ;
struct V_91 * V_92 = V_362 -> V_198 ;
struct V_9 * V_10 = F_67 ( V_92 ) ;
V_363 = F_58 ( V_10 , V_368 ) ;
F_309 ( V_362 , L_7 , V_363 ) ;
F_59 (nid, N_HIGH_MEMORY) {
V_367 = F_57 ( V_10 , V_18 , V_368 ) ;
F_309 ( V_362 , L_8 , V_18 , V_367 ) ;
}
F_310 ( V_362 , '\n' ) ;
V_364 = F_58 ( V_10 , V_171 ) ;
F_309 ( V_362 , L_9 , V_364 ) ;
F_59 (nid, N_HIGH_MEMORY) {
V_367 = F_57 ( V_10 , V_18 ,
V_171 ) ;
F_309 ( V_362 , L_8 , V_18 , V_367 ) ;
}
F_310 ( V_362 , '\n' ) ;
V_365 = F_58 ( V_10 , V_172 ) ;
F_309 ( V_362 , L_10 , V_365 ) ;
F_59 (nid, N_HIGH_MEMORY) {
V_367 = F_57 ( V_10 , V_18 ,
V_172 ) ;
F_309 ( V_362 , L_8 , V_18 , V_367 ) ;
}
F_310 ( V_362 , '\n' ) ;
V_366 = F_58 ( V_10 , F_56 ( V_359 ) ) ;
F_309 ( V_362 , L_11 , V_366 ) ;
F_59 (nid, N_HIGH_MEMORY) {
V_367 = F_57 ( V_10 , V_18 ,
F_56 ( V_359 ) ) ;
F_309 ( V_362 , L_8 , V_18 , V_367 ) ;
}
F_310 ( V_362 , '\n' ) ;
return 0 ;
}
static int F_311 ( struct V_91 * V_92 , struct V_327 * V_328 ,
struct V_369 * V_370 )
{
struct V_9 * V_10 = F_67 ( V_92 ) ;
struct V_345 V_371 ;
int V_221 ;
memset ( & V_371 , 0 , sizeof( V_371 ) ) ;
F_306 ( V_10 , & V_371 ) ;
for ( V_221 = 0 ; V_221 < V_372 ; V_221 ++ ) {
if ( V_221 == V_352 && ! V_138 )
continue;
V_370 -> V_373 ( V_370 , V_374 [ V_221 ] . V_375 , V_371 . V_56 [ V_221 ] ) ;
}
{
unsigned long long V_162 , V_338 ;
F_300 ( V_10 , & V_162 , & V_338 ) ;
V_370 -> V_373 ( V_370 , L_12 , V_162 ) ;
if ( V_138 )
V_370 -> V_373 ( V_370 , L_13 , V_338 ) ;
}
memset ( & V_371 , 0 , sizeof( V_371 ) ) ;
F_307 ( V_10 , & V_371 ) ;
for ( V_221 = 0 ; V_221 < V_372 ; V_221 ++ ) {
if ( V_221 == V_352 && ! V_138 )
continue;
V_370 -> V_373 ( V_370 , V_374 [ V_221 ] . V_376 , V_371 . V_56 [ V_221 ] ) ;
}
#ifdef F_312
{
int V_18 , V_19 ;
struct V_17 * V_30 ;
unsigned long V_377 [ 2 ] = { 0 , 0 } ;
unsigned long V_378 [ 2 ] = { 0 , 0 } ;
F_313 (nid)
for ( V_19 = 0 ; V_19 < V_48 ; V_19 ++ ) {
V_30 = F_15 ( V_10 , V_18 , V_19 ) ;
V_377 [ 0 ] +=
V_30 -> V_136 . V_377 [ 0 ] ;
V_377 [ 1 ] +=
V_30 -> V_136 . V_377 [ 1 ] ;
V_378 [ 0 ] +=
V_30 -> V_136 . V_378 [ 0 ] ;
V_378 [ 1 ] +=
V_30 -> V_136 . V_378 [ 1 ] ;
}
V_370 -> V_373 ( V_370 , L_14 , V_377 [ 0 ] ) ;
V_370 -> V_373 ( V_370 , L_15 , V_377 [ 1 ] ) ;
V_370 -> V_373 ( V_370 , L_16 , V_378 [ 0 ] ) ;
V_370 -> V_373 ( V_370 , L_17 , V_378 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_314 ( struct V_91 * V_140 , struct V_327 * V_328 )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
return F_109 ( V_10 ) ;
}
static int F_315 ( struct V_91 * V_140 , struct V_327 * V_328 ,
T_1 V_54 )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
struct V_9 * V_36 ;
if ( V_54 > 100 )
return - V_267 ;
if ( V_140 -> V_36 == NULL )
return - V_267 ;
V_36 = F_67 ( V_140 -> V_36 ) ;
F_290 () ;
if ( ( V_36 -> V_104 ) ||
( V_10 -> V_104 && ! F_278 ( & V_140 -> V_303 ) ) ) {
F_291 () ;
return - V_267 ;
}
V_10 -> V_142 = V_54 ;
F_291 () ;
return 0 ;
}
static void F_316 ( struct V_9 * V_10 , bool V_331 )
{
struct V_379 * V_380 ;
T_1 V_381 ;
int V_221 ;
F_8 () ;
if ( ! V_331 )
V_380 = F_71 ( V_10 -> V_382 . V_383 ) ;
else
V_380 = F_71 ( V_10 -> V_384 . V_383 ) ;
if ( ! V_380 )
goto V_145;
V_381 = F_293 ( V_10 , V_331 ) ;
V_221 = V_380 -> V_385 ;
for (; V_221 >= 0 && F_64 ( V_380 -> V_386 [ V_221 ] . V_387 > V_381 ) ; V_221 -- )
F_317 ( V_380 -> V_386 [ V_221 ] . V_388 , 1 ) ;
V_221 ++ ;
for (; V_221 < V_380 -> V_389 && F_64 ( V_380 -> V_386 [ V_221 ] . V_387 <= V_381 ) ; V_221 ++ )
F_317 ( V_380 -> V_386 [ V_221 ] . V_388 , 1 ) ;
V_380 -> V_385 = V_221 - 1 ;
V_145:
F_10 () ;
}
static void F_65 ( struct V_9 * V_10 )
{
while ( V_10 ) {
F_316 ( V_10 , false ) ;
if ( V_138 )
F_316 ( V_10 , true ) ;
V_10 = F_32 ( V_10 ) ;
}
}
static int F_318 ( const void * V_390 , const void * V_391 )
{
const struct F_65 * V_392 = V_390 ;
const struct F_65 * V_393 = V_391 ;
return V_392 -> V_387 - V_393 -> V_387 ;
}
static int F_319 ( struct V_9 * V_10 )
{
struct V_394 * V_395 ;
F_320 (ev, &memcg->oom_notify, list)
F_317 ( V_395 -> V_388 , 1 ) ;
return 0 ;
}
static void F_165 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_133 (iter, memcg)
F_319 ( V_107 ) ;
}
static int F_321 ( struct V_91 * V_140 ,
struct V_327 * V_328 , struct V_396 * V_388 , const char * args )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
struct V_397 * V_382 ;
struct V_379 * V_398 ;
int type = F_295 ( V_328 -> V_198 ) ;
T_1 V_387 , V_381 ;
int V_221 , V_389 , V_74 ;
V_74 = F_298 ( args , & V_387 ) ;
if ( V_74 )
return V_74 ;
F_191 ( & V_10 -> V_399 ) ;
if ( type == V_333 )
V_382 = & V_10 -> V_382 ;
else if ( type == V_334 )
V_382 = & V_10 -> V_384 ;
else
F_82 () ;
V_381 = F_293 ( V_10 , type == V_334 ) ;
if ( V_382 -> V_383 )
F_316 ( V_10 , type == V_334 ) ;
V_389 = V_382 -> V_383 ? V_382 -> V_383 -> V_389 + 1 : 1 ;
V_398 = F_322 ( sizeof( * V_398 ) + V_389 * sizeof( struct F_65 ) ,
V_308 ) ;
if ( ! V_398 ) {
V_74 = - V_252 ;
goto V_145;
}
V_398 -> V_389 = V_389 ;
if ( V_382 -> V_383 ) {
memcpy ( V_398 -> V_386 , V_382 -> V_383 -> V_386 , ( V_389 - 1 ) *
sizeof( struct F_65 ) ) ;
}
V_398 -> V_386 [ V_389 - 1 ] . V_388 = V_388 ;
V_398 -> V_386 [ V_389 - 1 ] . V_387 = V_387 ;
F_323 ( V_398 -> V_386 , V_389 , sizeof( struct F_65 ) ,
F_318 , NULL ) ;
V_398 -> V_385 = - 1 ;
for ( V_221 = 0 ; V_221 < V_389 ; V_221 ++ ) {
if ( V_398 -> V_386 [ V_221 ] . V_387 < V_381 ) {
++ V_398 -> V_385 ;
}
}
F_324 ( V_382 -> V_400 ) ;
V_382 -> V_400 = V_382 -> V_383 ;
F_325 ( V_382 -> V_383 , V_398 ) ;
F_111 () ;
V_145:
F_189 ( & V_10 -> V_399 ) ;
return V_74 ;
}
static void F_326 ( struct V_91 * V_140 ,
struct V_327 * V_328 , struct V_396 * V_388 )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
struct V_397 * V_382 ;
struct V_379 * V_398 ;
int type = F_295 ( V_328 -> V_198 ) ;
T_1 V_381 ;
int V_221 , V_401 , V_389 ;
F_191 ( & V_10 -> V_399 ) ;
if ( type == V_333 )
V_382 = & V_10 -> V_382 ;
else if ( type == V_334 )
V_382 = & V_10 -> V_384 ;
else
F_82 () ;
if ( ! V_382 -> V_383 )
goto V_145;
V_381 = F_293 ( V_10 , type == V_334 ) ;
F_316 ( V_10 , type == V_334 ) ;
V_389 = 0 ;
for ( V_221 = 0 ; V_221 < V_382 -> V_383 -> V_389 ; V_221 ++ ) {
if ( V_382 -> V_383 -> V_386 [ V_221 ] . V_388 != V_388 )
V_389 ++ ;
}
V_398 = V_382 -> V_400 ;
if ( ! V_389 ) {
F_324 ( V_398 ) ;
V_398 = NULL ;
goto V_402;
}
V_398 -> V_389 = V_389 ;
V_398 -> V_385 = - 1 ;
for ( V_221 = 0 , V_401 = 0 ; V_221 < V_382 -> V_383 -> V_389 ; V_221 ++ ) {
if ( V_382 -> V_383 -> V_386 [ V_221 ] . V_388 == V_388 )
continue;
V_398 -> V_386 [ V_401 ] = V_382 -> V_383 -> V_386 [ V_221 ] ;
if ( V_398 -> V_386 [ V_401 ] . V_387 < V_381 ) {
++ V_398 -> V_385 ;
}
V_401 ++ ;
}
V_402:
V_382 -> V_400 = V_382 -> V_383 ;
if ( ! V_398 ) {
F_324 ( V_382 -> V_400 ) ;
V_382 -> V_400 = NULL ;
}
F_325 ( V_382 -> V_383 , V_398 ) ;
F_111 () ;
V_145:
F_189 ( & V_10 -> V_399 ) ;
}
static int F_327 ( struct V_91 * V_140 ,
struct V_327 * V_328 , struct V_396 * V_388 , const char * args )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
struct V_394 * V_326 ;
int type = F_295 ( V_328 -> V_198 ) ;
F_5 ( type != V_403 ) ;
V_326 = F_322 ( sizeof( * V_326 ) , V_308 ) ;
if ( ! V_326 )
return - V_252 ;
F_29 ( & V_200 ) ;
V_326 -> V_388 = V_388 ;
F_328 ( & V_326 -> V_314 , & V_10 -> V_404 ) ;
if ( F_116 ( & V_10 -> V_183 ) )
F_317 ( V_388 , 1 ) ;
F_30 ( & V_200 ) ;
return 0 ;
}
static void F_329 ( struct V_91 * V_140 ,
struct V_327 * V_328 , struct V_396 * V_388 )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
struct V_394 * V_395 , * V_341 ;
int type = F_295 ( V_328 -> V_198 ) ;
F_5 ( type != V_403 ) ;
F_29 ( & V_200 ) ;
F_330 (ev, tmp, &memcg->oom_notify, list) {
if ( V_395 -> V_388 == V_388 ) {
F_331 ( & V_395 -> V_314 ) ;
F_324 ( V_395 ) ;
}
}
F_30 ( & V_200 ) ;
}
static int F_332 ( struct V_91 * V_140 ,
struct V_327 * V_328 , struct V_369 * V_370 )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
V_370 -> V_373 ( V_370 , L_18 , V_10 -> V_202 ) ;
if ( F_116 ( & V_10 -> V_183 ) )
V_370 -> V_373 ( V_370 , L_19 , 1 ) ;
else
V_370 -> V_373 ( V_370 , L_19 , 0 ) ;
return 0 ;
}
static int F_333 ( struct V_91 * V_140 ,
struct V_327 * V_328 , T_1 V_54 )
{
struct V_9 * V_10 = F_67 ( V_140 ) ;
struct V_9 * V_36 ;
if ( ! V_140 -> V_36 || ! ( ( V_54 == 0 ) || ( V_54 == 1 ) ) )
return - V_267 ;
V_36 = F_67 ( V_140 -> V_36 ) ;
F_290 () ;
if ( ( V_36 -> V_104 ) ||
( V_10 -> V_104 && ! F_278 ( & V_140 -> V_303 ) ) ) {
F_291 () ;
return - V_267 ;
}
V_10 -> V_202 = V_54 ;
if ( ! V_54 )
F_162 ( V_10 ) ;
F_291 () ;
return 0 ;
}
static int F_334 ( struct V_405 * V_298 , struct V_406 * V_406 )
{
struct V_91 * V_92 = V_406 -> V_407 -> V_408 -> V_409 ;
V_406 -> V_410 = & V_411 ;
return F_335 ( V_406 , F_308 , V_92 ) ;
}
static int F_336 ( struct V_91 * V_92 , struct V_412 * V_413 )
{
return F_337 ( V_92 , V_413 ) ;
}
static void F_338 ( struct V_91 * V_92 )
{
F_339 ( V_92 ) ;
}
static int F_336 ( struct V_91 * V_92 , struct V_412 * V_413 )
{
return 0 ;
}
static void F_338 ( struct V_91 * V_92 )
{
}
static int F_340 ( struct V_91 * V_92 , struct V_412 * V_413 )
{
if ( ! V_138 )
return 0 ;
return F_341 ( V_92 , V_413 , V_414 ,
F_342 ( V_414 ) ) ;
}
static int F_340 ( struct V_91 * V_92 , struct V_412 * V_413 )
{
return 0 ;
}
static int F_343 ( struct V_9 * V_10 , int V_46 )
{
struct V_415 * V_416 ;
struct V_17 * V_30 ;
enum V_72 V_73 ;
int V_47 , V_341 = V_46 ;
if ( ! F_344 ( V_46 , V_417 ) )
V_341 = - 1 ;
V_416 = F_345 ( sizeof( * V_416 ) , V_308 , V_341 ) ;
if ( ! V_416 )
return 1 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_30 = & V_416 -> V_22 [ V_47 ] ;
F_55 (lru)
F_164 ( & V_30 -> V_119 . V_317 [ V_73 ] ) ;
V_30 -> V_39 = 0 ;
V_30 -> V_38 = false ;
V_30 -> V_10 = V_10 ;
}
V_10 -> V_20 . V_21 [ V_46 ] = V_416 ;
return 0 ;
}
static void F_346 ( struct V_9 * V_10 , int V_46 )
{
F_324 ( V_10 -> V_20 . V_21 [ V_46 ] ) ;
}
static struct V_9 * F_347 ( void )
{
struct V_9 * V_10 ;
int V_389 = sizeof( struct V_9 ) ;
if ( V_389 < V_214 )
V_10 = F_348 ( V_389 , V_308 ) ;
else
V_10 = F_349 ( V_389 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_56 = F_350 ( struct V_418 ) ;
if ( ! V_10 -> V_56 )
goto V_419;
F_351 ( & V_10 -> V_58 ) ;
return V_10 ;
V_419:
if ( V_389 < V_214 )
F_324 ( V_10 ) ;
else
F_352 ( V_10 ) ;
return NULL ;
}
static void F_353 ( struct V_215 * V_219 )
{
struct V_9 * V_10 ;
V_10 = F_68 ( V_219 , struct V_9 , V_420 ) ;
F_352 ( V_10 ) ;
}
static void F_354 ( struct V_421 * V_421 )
{
struct V_9 * V_10 ;
V_10 = F_68 ( V_421 , struct V_9 , V_422 ) ;
F_355 ( & V_10 -> V_420 , F_353 ) ;
F_356 ( & V_10 -> V_420 ) ;
}
static void F_357 ( struct V_9 * V_10 )
{
int V_46 ;
F_34 ( V_10 ) ;
F_358 ( & V_112 , & V_10 -> V_24 ) ;
F_35 (node)
F_346 ( V_10 , V_46 ) ;
F_359 ( V_10 -> V_56 ) ;
if ( sizeof( struct V_9 ) < V_214 )
F_360 ( V_10 , V_422 ) ;
else
F_361 ( & V_10 -> V_422 , F_354 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
F_66 ( & V_10 -> V_423 ) ;
}
static void F_362 ( struct V_9 * V_10 , int V_57 )
{
if ( F_363 ( V_57 , & V_10 -> V_423 ) ) {
struct V_9 * V_36 = F_32 ( V_10 ) ;
F_357 ( V_10 ) ;
if ( V_36 )
F_13 ( V_36 ) ;
}
}
static void F_13 ( struct V_9 * V_10 )
{
F_362 ( V_10 , 1 ) ;
}
struct V_9 * F_32 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_45 . V_36 )
return NULL ;
return F_198 ( V_10 -> V_45 . V_36 , V_45 ) ;
}
static void T_8 F_364 ( void )
{
if ( ! F_73 () && V_424 )
V_138 = 1 ;
}
static void T_8 F_364 ( void )
{
}
static int F_365 ( void )
{
struct V_425 * V_426 ;
struct V_26 * V_427 ;
int V_341 , V_46 , V_47 ;
F_35 (node) {
V_341 = V_46 ;
if ( ! F_344 ( V_46 , V_417 ) )
V_341 = - 1 ;
V_426 = F_345 ( sizeof( * V_426 ) , V_308 , V_341 ) ;
if ( ! V_426 )
goto V_428;
V_27 . V_28 [ V_46 ] = V_426 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_427 = & V_426 -> V_29 [ V_47 ] ;
V_427 -> V_35 = V_429 ;
F_351 ( & V_427 -> V_43 ) ;
}
}
return 0 ;
V_428:
F_35 (node) {
if ( ! V_27 . V_28 [ V_46 ] )
break;
F_324 ( V_27 . V_28 [ V_46 ] ) ;
V_27 . V_28 [ V_46 ] = NULL ;
}
return 1 ;
}
static struct V_23 * T_9
F_366 ( struct V_91 * V_92 )
{
struct V_9 * V_10 , * V_36 ;
long error = - V_252 ;
int V_46 ;
V_10 = F_347 () ;
if ( ! V_10 )
return F_367 ( error ) ;
F_35 (node)
if ( F_343 ( V_10 , V_46 ) )
goto V_430;
if ( V_92 -> V_36 == NULL ) {
int V_55 ;
F_364 () ;
V_36 = NULL ;
if ( F_365 () )
goto V_430;
V_103 = V_10 ;
F_368 (cpu) {
struct V_208 * V_209 =
& F_43 ( V_210 , V_55 ) ;
F_355 ( & V_209 -> V_219 , F_178 ) ;
}
F_369 ( F_193 , 0 ) ;
} else {
V_36 = F_67 ( V_92 -> V_36 ) ;
V_10 -> V_104 = V_36 -> V_104 ;
V_10 -> V_202 = V_36 -> V_202 ;
}
if ( V_36 && V_36 -> V_104 ) {
F_370 ( & V_10 -> V_45 , & V_36 -> V_45 ) ;
F_370 ( & V_10 -> V_139 , & V_36 -> V_139 ) ;
F_7 ( V_36 ) ;
} else {
F_370 ( & V_10 -> V_45 , NULL ) ;
F_370 ( & V_10 -> V_139 , NULL ) ;
}
V_10 -> V_177 = V_89 ;
F_164 ( & V_10 -> V_404 ) ;
if ( V_36 )
V_10 -> V_142 = F_109 ( V_36 ) ;
F_143 ( & V_10 -> V_423 , 1 ) ;
V_10 -> V_4 = 0 ;
F_371 ( & V_10 -> V_399 ) ;
F_351 ( & V_10 -> V_151 ) ;
return & V_10 -> V_24 ;
V_430:
F_357 ( V_10 ) ;
return F_367 ( error ) ;
}
static int F_372 ( struct V_91 * V_92 )
{
struct V_9 * V_10 = F_67 ( V_92 ) ;
return F_282 ( V_10 , false ) ;
}
static void F_373 ( struct V_91 * V_92 )
{
struct V_9 * V_10 = F_67 ( V_92 ) ;
F_338 ( V_92 ) ;
F_13 ( V_10 ) ;
}
static int F_374 ( struct V_412 * V_413 ,
struct V_91 * V_92 )
{
int V_74 ;
V_74 = F_341 ( V_92 , V_413 , V_431 ,
F_342 ( V_431 ) ) ;
if ( ! V_74 )
V_74 = F_340 ( V_92 , V_413 ) ;
if ( ! V_74 )
V_74 = F_336 ( V_92 , V_413 ) ;
return V_74 ;
}
static int F_375 ( unsigned long V_57 )
{
int V_74 = 0 ;
int V_432 = V_433 ;
struct V_9 * V_10 = V_2 . V_3 ;
if ( F_6 ( V_10 ) ) {
V_2 . V_434 += V_57 ;
return V_74 ;
}
if ( V_57 > 1 ) {
struct V_236 * V_216 ;
if ( F_196 ( & V_10 -> V_45 , V_214 * V_57 , & V_216 ) )
goto V_435;
if ( V_138 && F_196 ( & V_10 -> V_139 ,
V_214 * V_57 , & V_216 ) ) {
F_177 ( & V_10 -> V_45 , V_214 * V_57 ) ;
goto V_435;
}
V_2 . V_434 += V_57 ;
return V_74 ;
}
V_435:
while ( V_57 -- ) {
if ( F_272 ( V_14 ) ) {
V_74 = - V_253 ;
break;
}
if ( ! V_432 -- ) {
V_432 = V_433 ;
F_281 () ;
}
V_74 = F_200 ( NULL ,
V_308 , 1 , & V_10 , false ) ;
if ( V_74 )
return V_74 ;
V_2 . V_434 ++ ;
}
return V_74 ;
}
static struct V_25 * F_376 ( struct V_436 * V_437 ,
unsigned long V_438 , T_10 V_439 )
{
struct V_25 * V_25 = F_377 ( V_437 , V_438 , V_439 ) ;
if ( ! V_25 || ! F_228 ( V_25 ) )
return NULL ;
if ( F_226 ( V_25 ) ) {
if ( ! F_1 () || F_378 ( V_25 ) > 2 )
return NULL ;
} else if ( ! F_3 () )
return NULL ;
if ( ! F_231 ( V_25 ) )
return NULL ;
return V_25 ;
}
static struct V_25 * F_379 ( struct V_436 * V_437 ,
unsigned long V_438 , T_10 V_439 , T_6 * V_290 )
{
int V_440 ;
struct V_25 * V_25 = NULL ;
T_6 V_254 = F_380 ( V_439 ) ;
if ( ! F_1 () || F_381 ( V_254 ) )
return NULL ;
V_440 = F_382 ( V_254 , & V_25 ) ;
if ( V_440 > 1 ) {
if ( V_25 )
F_237 ( V_25 ) ;
return NULL ;
}
if ( V_138 )
V_290 -> V_54 = V_254 . V_54 ;
return V_25 ;
}
static struct V_25 * F_383 ( struct V_436 * V_437 ,
unsigned long V_438 , T_10 V_439 , T_6 * V_290 )
{
struct V_25 * V_25 = NULL ;
struct V_405 * V_405 ;
struct V_441 * V_273 ;
T_11 V_442 ;
if ( ! V_437 -> V_443 )
return NULL ;
if ( ! F_3 () )
return NULL ;
V_405 = V_437 -> V_443 -> V_444 . V_445 -> V_446 ;
V_273 = V_437 -> V_443 -> V_447 ;
if ( F_384 ( V_439 ) )
V_442 = F_385 ( V_437 , V_438 ) ;
else
V_442 = F_386 ( V_439 ) ;
V_25 = F_387 ( V_273 , V_442 ) ;
#ifdef F_388
if ( F_389 ( V_25 ) ) {
T_6 V_331 = F_390 ( V_25 ) ;
if ( V_138 )
* V_290 = V_331 ;
V_25 = F_387 ( & V_448 , V_331 . V_54 ) ;
}
#endif
return V_25 ;
}
static enum V_449 F_391 ( struct V_436 * V_437 ,
unsigned long V_438 , T_10 V_439 , union V_450 * V_78 )
{
struct V_25 * V_25 = NULL ;
struct V_120 * V_121 ;
enum V_449 V_74 = V_451 ;
T_6 V_254 = { . V_54 = 0 } ;
if ( F_392 ( V_439 ) )
V_25 = F_376 ( V_437 , V_438 , V_439 ) ;
else if ( F_393 ( V_439 ) )
V_25 = F_379 ( V_437 , V_438 , V_439 , & V_254 ) ;
else if ( F_384 ( V_439 ) || F_394 ( V_439 ) )
V_25 = F_383 ( V_437 , V_438 , V_439 , & V_254 ) ;
if ( ! V_25 && ! V_254 . V_54 )
return V_74 ;
if ( V_25 ) {
V_121 = F_85 ( V_25 ) ;
if ( F_86 ( V_121 ) && V_121 -> V_9 == V_2 . V_122 ) {
V_74 = V_452 ;
if ( V_78 )
V_78 -> V_25 = V_25 ;
}
if ( ! V_74 || ! V_78 )
F_237 ( V_25 ) ;
}
if ( V_254 . V_54 && ! V_74 &&
F_74 ( & V_2 . V_122 -> V_24 ) == F_211 ( V_254 ) ) {
V_74 = V_453 ;
if ( V_78 )
V_78 -> V_254 = V_254 ;
}
return V_74 ;
}
static enum V_449 F_395 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_454 , union V_450 * V_78 )
{
struct V_25 * V_25 = NULL ;
struct V_120 * V_121 ;
enum V_449 V_74 = V_451 ;
V_25 = F_396 ( V_454 ) ;
F_89 ( ! V_25 || ! F_397 ( V_25 ) ) ;
if ( ! F_1 () )
return V_74 ;
V_121 = F_85 ( V_25 ) ;
if ( F_86 ( V_121 ) && V_121 -> V_9 == V_2 . V_122 ) {
V_74 = V_452 ;
if ( V_78 ) {
F_398 ( V_25 ) ;
V_78 -> V_25 = V_25 ;
}
}
return V_74 ;
}
static inline enum V_449 F_395 ( struct V_436 * V_437 ,
unsigned long V_438 , T_12 V_454 , union V_450 * V_78 )
{
return V_451 ;
}
static int F_399 ( T_12 * V_454 ,
unsigned long V_438 , unsigned long V_455 ,
struct V_456 * V_457 )
{
struct V_436 * V_437 = V_457 -> V_198 ;
T_10 * V_458 ;
T_13 * V_459 ;
if ( F_400 ( V_454 , V_437 ) == 1 ) {
if ( F_395 ( V_437 , V_438 , * V_454 , NULL ) == V_452 )
V_2 . V_434 += V_263 ;
F_30 ( & V_437 -> V_460 -> V_461 ) ;
return 0 ;
}
if ( F_401 ( V_454 ) )
return 0 ;
V_458 = F_402 ( V_437 -> V_460 , V_454 , V_438 , & V_459 ) ;
for (; V_438 != V_455 ; V_458 ++ , V_438 += V_214 )
if ( F_391 ( V_437 , V_438 , * V_458 , NULL ) )
V_2 . V_434 ++ ;
F_403 ( V_458 - 1 , V_459 ) ;
F_281 () ;
return 0 ;
}
static unsigned long F_404 ( struct V_95 * V_96 )
{
unsigned long V_434 ;
struct V_436 * V_437 ;
F_405 ( & V_96 -> V_462 ) ;
for ( V_437 = V_96 -> V_463 ; V_437 ; V_437 = V_437 -> V_464 ) {
struct V_456 V_465 = {
. V_466 = F_399 ,
. V_96 = V_96 ,
. V_198 = V_437 ,
} ;
if ( F_406 ( V_437 ) )
continue;
F_407 ( V_437 -> V_467 , V_437 -> V_468 ,
& V_465 ) ;
}
F_408 ( & V_96 -> V_462 ) ;
V_434 = V_2 . V_434 ;
V_2 . V_434 = 0 ;
return V_434 ;
}
static int F_409 ( struct V_95 * V_96 )
{
unsigned long V_434 = F_404 ( V_96 ) ;
F_89 ( V_2 . V_146 ) ;
V_2 . V_146 = V_14 ;
return F_375 ( V_434 ) ;
}
static void F_410 ( void )
{
struct V_9 * V_122 = V_2 . V_122 ;
struct V_9 * V_3 = V_2 . V_3 ;
if ( V_2 . V_434 ) {
F_203 ( V_2 . V_3 , V_2 . V_434 ) ;
V_2 . V_434 = 0 ;
}
if ( V_2 . V_469 ) {
F_203 ( V_2 . V_122 , V_2 . V_469 ) ;
V_2 . V_469 = 0 ;
}
if ( V_2 . V_470 ) {
if ( ! F_6 ( V_2 . V_122 ) )
F_177 ( & V_2 . V_122 -> V_139 ,
V_214 * V_2 . V_470 ) ;
F_362 ( V_2 . V_122 , V_2 . V_470 ) ;
if ( ! F_6 ( V_2 . V_3 ) ) {
F_177 ( & V_2 . V_3 -> V_45 ,
V_214 * V_2 . V_470 ) ;
}
V_2 . V_470 = 0 ;
}
F_162 ( V_122 ) ;
F_162 ( V_3 ) ;
F_411 ( & V_2 . V_148 ) ;
}
static void F_412 ( void )
{
struct V_9 * V_122 = V_2 . V_122 ;
V_2 . V_146 = NULL ;
F_410 () ;
F_29 ( & V_2 . V_43 ) ;
V_2 . V_122 = NULL ;
V_2 . V_3 = NULL ;
F_30 ( & V_2 . V_43 ) ;
F_112 ( V_122 ) ;
}
static int F_413 ( struct V_91 * V_91 ,
struct V_471 * V_472 )
{
struct V_94 * V_34 = F_414 ( V_472 ) ;
int V_74 = 0 ;
struct V_9 * V_10 = F_67 ( V_91 ) ;
if ( V_10 -> V_4 ) {
struct V_95 * V_96 ;
struct V_9 * V_122 = F_9 ( V_34 ) ;
F_89 ( V_122 == V_10 ) ;
V_96 = F_415 ( V_34 ) ;
if ( ! V_96 )
return 0 ;
if ( V_96 -> V_97 == V_34 ) {
F_89 ( V_2 . V_122 ) ;
F_89 ( V_2 . V_3 ) ;
F_89 ( V_2 . V_434 ) ;
F_89 ( V_2 . V_469 ) ;
F_89 ( V_2 . V_470 ) ;
F_110 ( V_122 ) ;
F_29 ( & V_2 . V_43 ) ;
V_2 . V_122 = V_122 ;
V_2 . V_3 = V_10 ;
F_30 ( & V_2 . V_43 ) ;
V_74 = F_409 ( V_96 ) ;
if ( V_74 )
F_412 () ;
}
F_416 ( V_96 ) ;
}
return V_74 ;
}
static void F_417 ( struct V_91 * V_91 ,
struct V_471 * V_472 )
{
F_412 () ;
}
static int F_418 ( T_12 * V_454 ,
unsigned long V_438 , unsigned long V_455 ,
struct V_456 * V_457 )
{
int V_74 = 0 ;
struct V_436 * V_437 = V_457 -> V_198 ;
T_10 * V_458 ;
T_13 * V_459 ;
enum V_449 V_473 ;
union V_450 V_78 ;
struct V_25 * V_25 ;
struct V_120 * V_121 ;
if ( F_400 ( V_454 , V_437 ) == 1 ) {
if ( V_2 . V_434 < V_263 ) {
F_30 ( & V_437 -> V_460 -> V_461 ) ;
return 0 ;
}
V_473 = F_395 ( V_437 , V_438 , * V_454 , & V_78 ) ;
if ( V_473 == V_452 ) {
V_25 = V_78 . V_25 ;
if ( ! F_232 ( V_25 ) ) {
V_121 = F_85 ( V_25 ) ;
if ( ! F_225 ( V_25 , V_263 ,
V_121 , V_2 . V_122 , V_2 . V_3 ,
false ) ) {
V_2 . V_434 -= V_263 ;
V_2 . V_469 += V_263 ;
}
F_236 ( V_25 ) ;
}
F_237 ( V_25 ) ;
}
F_30 ( & V_437 -> V_460 -> V_461 ) ;
return 0 ;
}
if ( F_401 ( V_454 ) )
return 0 ;
V_50:
V_458 = F_402 ( V_437 -> V_460 , V_454 , V_438 , & V_459 ) ;
for (; V_438 != V_455 ; V_438 += V_214 ) {
T_10 V_439 = * ( V_458 ++ ) ;
T_6 V_254 ;
if ( ! V_2 . V_434 )
break;
switch ( F_391 ( V_437 , V_438 , V_439 , & V_78 ) ) {
case V_452 :
V_25 = V_78 . V_25 ;
if ( F_232 ( V_25 ) )
goto V_271;
V_121 = F_85 ( V_25 ) ;
if ( ! F_225 ( V_25 , 1 , V_121 ,
V_2 . V_122 , V_2 . V_3 , false ) ) {
V_2 . V_434 -- ;
V_2 . V_469 ++ ;
}
F_236 ( V_25 ) ;
V_271:
F_237 ( V_25 ) ;
break;
case V_453 :
V_254 = V_78 . V_254 ;
if ( ! F_260 ( V_254 ,
V_2 . V_122 , V_2 . V_3 , false ) ) {
V_2 . V_434 -- ;
V_2 . V_470 ++ ;
}
break;
default:
break;
}
}
F_403 ( V_458 - 1 , V_459 ) ;
F_281 () ;
if ( V_438 != V_455 ) {
V_74 = F_375 ( 1 ) ;
if ( ! V_74 )
goto V_50;
}
return V_74 ;
}
static void F_419 ( struct V_95 * V_96 )
{
struct V_436 * V_437 ;
F_284 () ;
V_50:
if ( F_64 ( ! F_420 ( & V_96 -> V_462 ) ) ) {
F_410 () ;
F_281 () ;
goto V_50;
}
for ( V_437 = V_96 -> V_463 ; V_437 ; V_437 = V_437 -> V_464 ) {
int V_74 ;
struct V_456 V_474 = {
. V_466 = F_418 ,
. V_96 = V_96 ,
. V_198 = V_437 ,
} ;
if ( F_406 ( V_437 ) )
continue;
V_74 = F_407 ( V_437 -> V_467 , V_437 -> V_468 ,
& V_474 ) ;
if ( V_74 )
break;
}
F_408 ( & V_96 -> V_462 ) ;
}
static void F_421 ( struct V_91 * V_92 ,
struct V_471 * V_472 )
{
struct V_94 * V_34 = F_414 ( V_472 ) ;
struct V_95 * V_96 = F_415 ( V_34 ) ;
if ( V_96 ) {
if ( V_2 . V_3 )
F_419 ( V_96 ) ;
F_422 ( V_96 ) ;
F_416 ( V_96 ) ;
}
if ( V_2 . V_3 )
F_412 () ;
}
static int F_413 ( struct V_91 * V_91 ,
struct V_471 * V_472 )
{
return 0 ;
}
static void F_417 ( struct V_91 * V_91 ,
struct V_471 * V_472 )
{
}
static void F_421 ( struct V_91 * V_92 ,
struct V_471 * V_472 )
{
}
static int T_8 F_423 ( char * V_346 )
{
if ( ! strcmp ( V_346 , L_20 ) )
V_424 = 1 ;
else if ( ! strcmp ( V_346 , L_21 ) )
V_424 = 0 ;
return 1 ;
}
