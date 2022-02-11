static T_1 F_1 ( void )
{
return sizeof( struct V_1 ) +
V_2 * sizeof( struct V_3 ) ;
}
static inline void F_2 ( struct V_1 * V_4 )
{
F_3 ( V_5 , & V_4 -> V_6 ) ;
}
static bool F_4 ( struct V_1 * V_4 )
{
return F_5 ( V_5 , & V_4 -> V_6 ) ;
}
static void F_6 ( struct V_1 * V_4 )
{
F_3 ( V_7 , & V_4 -> V_6 ) ;
}
static void F_7 ( struct V_1 * V_4 )
{
F_8 ( V_7 , & V_4 -> V_6 ) ;
}
static void F_9 ( struct V_1 * V_4 )
{
if ( F_5 ( V_5 , & V_4 -> V_6 ) )
F_3 ( V_8 , & V_4 -> V_6 ) ;
}
static bool F_10 ( struct V_1 * V_4 )
{
return F_11 ( V_8 ,
& V_4 -> V_6 ) ;
}
static bool F_12 ( void )
{
return F_5 ( V_9 , & V_10 . V_11 ) ;
}
static bool F_13 ( void )
{
return F_5 ( V_12 , & V_10 . V_11 ) ;
}
static inline
struct V_1 * F_14 ( struct V_13 * V_14 )
{
return F_15 ( V_14 , struct V_1 , V_15 ) ;
}
static inline bool F_16 ( struct V_1 * V_4 )
{
return ( V_4 == V_16 ) ;
}
void F_17 ( struct V_17 * V_18 )
{
if ( V_19 ) {
struct V_1 * V_4 ;
struct V_20 * V_20 ;
F_18 ( ! V_18 -> V_21 -> V_22 ) ;
if ( V_18 -> V_23 ) {
F_18 ( F_16 ( V_18 -> V_23 -> V_4 ) ) ;
F_19 ( V_18 -> V_23 -> V_4 ) ;
return;
}
F_20 () ;
V_4 = F_21 ( V_24 ) ;
V_20 = V_18 -> V_21 -> V_22 ( V_4 ) ;
if ( ! F_16 ( V_4 ) && F_22 ( V_20 ) ) {
F_19 ( V_4 ) ;
V_18 -> V_23 = V_20 ;
}
F_23 () ;
}
}
void F_24 ( struct V_17 * V_18 )
{
if ( V_19 && V_18 -> V_23 ) {
struct V_1 * V_4 ;
F_25 ( ! V_18 -> V_23 -> V_4 ) ;
V_4 = V_18 -> V_23 -> V_4 ;
F_26 ( V_4 ) ;
}
}
struct V_20 * F_27 ( struct V_1 * V_4 )
{
if ( ! V_4 || F_16 ( V_4 ) )
return NULL ;
return & V_4 -> V_25 . V_20 ;
}
static void F_28 ( struct V_1 * V_4 )
{
if ( ! F_29 ( & V_4 -> V_25 . V_20 ) )
return;
F_30 ( & V_26 ) ;
}
static void F_28 ( struct V_1 * V_4 )
{
}
static void F_31 ( struct V_1 * V_4 )
{
if ( F_4 ( V_4 ) ) {
F_30 ( & V_27 ) ;
F_32 ( & V_28 , V_4 -> V_29 ) ;
}
F_25 ( F_33 ( & V_4 -> V_30 , V_31 ) != 0 ) ;
}
static void F_31 ( struct V_1 * V_4 )
{
}
static void F_34 ( struct V_1 * V_4 )
{
F_28 ( V_4 ) ;
F_31 ( V_4 ) ;
}
static struct V_32 *
F_35 ( struct V_1 * V_4 , int V_33 , int V_34 )
{
F_36 ( ( unsigned ) V_33 >= V_2 ) ;
return & V_4 -> V_35 . V_36 [ V_33 ] -> V_37 [ V_34 ] ;
}
struct V_13 * F_37 ( struct V_1 * V_4 )
{
return & V_4 -> V_15 ;
}
static struct V_32 *
F_38 ( struct V_1 * V_4 , struct V_38 * V_38 )
{
int V_33 = F_39 ( V_38 ) ;
int V_34 = F_40 ( V_38 ) ;
return F_35 ( V_4 , V_33 , V_34 ) ;
}
static struct V_39 *
F_41 ( int V_33 , int V_34 )
{
return & V_40 . V_41 [ V_33 ] -> V_42 [ V_34 ] ;
}
static struct V_39 *
F_42 ( struct V_38 * V_38 )
{
int V_33 = F_39 ( V_38 ) ;
int V_34 = F_40 ( V_38 ) ;
return & V_40 . V_41 [ V_33 ] -> V_42 [ V_34 ] ;
}
static void
F_43 ( struct V_1 * V_4 ,
struct V_32 * V_43 ,
struct V_39 * V_44 ,
unsigned long long V_45 )
{
struct V_46 * * V_47 = & V_44 -> V_48 . V_46 ;
struct V_46 * V_49 = NULL ;
struct V_32 * V_50 ;
if ( V_43 -> V_51 )
return;
V_43 -> V_52 = V_45 ;
if ( ! V_43 -> V_52 )
return;
while ( * V_47 ) {
V_49 = * V_47 ;
V_50 = F_44 ( V_49 , struct V_32 ,
V_53 ) ;
if ( V_43 -> V_52 < V_50 -> V_52 )
V_47 = & ( * V_47 ) -> V_54 ;
else if ( V_43 -> V_52 >= V_50 -> V_52 )
V_47 = & ( * V_47 ) -> V_55 ;
}
F_45 ( & V_43 -> V_53 , V_49 , V_47 ) ;
F_46 ( & V_43 -> V_53 , & V_44 -> V_48 ) ;
V_43 -> V_51 = true ;
}
static void
F_47 ( struct V_1 * V_4 ,
struct V_32 * V_43 ,
struct V_39 * V_44 )
{
if ( ! V_43 -> V_51 )
return;
F_48 ( & V_43 -> V_53 , & V_44 -> V_48 ) ;
V_43 -> V_51 = false ;
}
static void
F_49 ( struct V_1 * V_4 ,
struct V_32 * V_43 ,
struct V_39 * V_44 )
{
F_50 ( & V_44 -> V_56 ) ;
F_47 ( V_4 , V_43 , V_44 ) ;
F_51 ( & V_44 -> V_56 ) ;
}
static void F_52 ( struct V_1 * V_4 , struct V_38 * V_38 )
{
unsigned long long V_57 ;
struct V_32 * V_43 ;
struct V_39 * V_44 ;
int V_33 = F_39 ( V_38 ) ;
int V_34 = F_40 ( V_38 ) ;
V_44 = F_42 ( V_38 ) ;
for (; V_4 ; V_4 = F_53 ( V_4 ) ) {
V_43 = F_35 ( V_4 , V_33 , V_34 ) ;
V_57 = F_54 ( & V_4 -> V_58 ) ;
if ( V_57 || V_43 -> V_51 ) {
F_50 ( & V_44 -> V_56 ) ;
if ( V_43 -> V_51 )
F_47 ( V_4 , V_43 , V_44 ) ;
F_43 ( V_4 , V_43 , V_44 , V_57 ) ;
F_51 ( & V_44 -> V_56 ) ;
}
}
}
static void F_55 ( struct V_1 * V_4 )
{
int V_59 , V_60 ;
struct V_32 * V_43 ;
struct V_39 * V_44 ;
F_56 (node) {
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
V_43 = F_35 ( V_4 , V_59 , V_60 ) ;
V_44 = F_41 ( V_59 , V_60 ) ;
F_49 ( V_4 , V_43 , V_44 ) ;
}
}
}
static struct V_32 *
F_57 ( struct V_39 * V_44 )
{
struct V_46 * V_62 = NULL ;
struct V_32 * V_43 ;
V_63:
V_43 = NULL ;
V_62 = F_58 ( & V_44 -> V_48 ) ;
if ( ! V_62 )
goto V_64;
V_43 = F_44 ( V_62 , struct V_32 , V_53 ) ;
F_47 ( V_43 -> V_4 , V_43 , V_44 ) ;
if ( ! F_54 ( & V_43 -> V_4 -> V_58 ) ||
! F_59 ( & V_43 -> V_4 -> V_15 ) )
goto V_63;
V_64:
return V_43 ;
}
static struct V_32 *
F_60 ( struct V_39 * V_44 )
{
struct V_32 * V_43 ;
F_50 ( & V_44 -> V_56 ) ;
V_43 = F_57 ( V_44 ) ;
F_51 ( & V_44 -> V_56 ) ;
return V_43 ;
}
static long F_61 ( struct V_1 * V_4 ,
enum V_65 V_66 )
{
long V_67 = 0 ;
int V_68 ;
F_62 () ;
F_63 (cpu)
V_67 += F_64 ( V_4 -> V_69 -> V_70 [ V_66 ] , V_68 ) ;
#ifdef F_65
F_50 ( & V_4 -> V_71 ) ;
V_67 += V_4 -> V_72 . V_70 [ V_66 ] ;
F_51 ( & V_4 -> V_71 ) ;
#endif
F_66 () ;
return V_67 ;
}
static void F_67 ( struct V_1 * V_4 ,
bool V_73 )
{
int V_67 = ( V_73 ) ? 1 : - 1 ;
F_68 ( V_4 -> V_69 -> V_70 [ V_74 ] , V_67 ) ;
}
static unsigned long F_69 ( struct V_1 * V_4 ,
enum V_75 V_66 )
{
unsigned long V_67 = 0 ;
int V_68 ;
F_63 (cpu)
V_67 += F_64 ( V_4 -> V_69 -> V_76 [ V_66 ] , V_68 ) ;
#ifdef F_65
F_50 ( & V_4 -> V_71 ) ;
V_67 += V_4 -> V_72 . V_76 [ V_66 ] ;
F_51 ( & V_4 -> V_71 ) ;
#endif
return V_67 ;
}
static void F_70 ( struct V_1 * V_4 ,
bool V_77 , int V_78 )
{
F_71 () ;
if ( V_77 )
F_72 ( V_4 -> V_69 -> V_70 [ V_79 ] ,
V_78 ) ;
else
F_72 ( V_4 -> V_69 -> V_70 [ V_80 ] ,
V_78 ) ;
if ( V_78 > 0 )
F_73 ( V_4 -> V_69 -> V_76 [ V_81 ] ) ;
else {
F_73 ( V_4 -> V_69 -> V_76 [ V_82 ] ) ;
V_78 = - V_78 ;
}
F_72 ( V_4 -> V_69 -> V_83 , V_78 ) ;
F_74 () ;
}
unsigned long
F_75 ( struct V_84 * V_84 , enum V_85 V_86 )
{
struct V_32 * V_43 ;
V_43 = F_15 ( V_84 , struct V_32 , V_84 ) ;
return V_43 -> V_87 [ V_86 ] ;
}
static unsigned long
F_76 ( struct V_1 * V_4 , int V_33 , int V_34 ,
unsigned int V_88 )
{
struct V_32 * V_43 ;
enum V_85 V_86 ;
unsigned long V_89 = 0 ;
V_43 = F_35 ( V_4 , V_33 , V_34 ) ;
F_77 (lru) {
if ( F_78 ( V_86 ) & V_88 )
V_89 += V_43 -> V_87 [ V_86 ] ;
}
return V_89 ;
}
static unsigned long
F_79 ( struct V_1 * V_4 ,
int V_33 , unsigned int V_88 )
{
T_2 V_90 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < V_61 ; V_34 ++ )
V_90 += F_76 ( V_4 ,
V_33 , V_34 , V_88 ) ;
return V_90 ;
}
static unsigned long F_80 ( struct V_1 * V_4 ,
unsigned int V_88 )
{
int V_33 ;
T_2 V_90 = 0 ;
F_81 (nid, N_MEMORY)
V_90 += F_79 ( V_4 , V_33 , V_88 ) ;
return V_90 ;
}
static bool F_82 ( struct V_1 * V_4 ,
enum V_91 V_92 )
{
unsigned long V_67 , V_93 ;
V_67 = F_83 ( V_4 -> V_69 -> V_83 ) ;
V_93 = F_83 ( V_4 -> V_69 -> V_94 [ V_92 ] ) ;
if ( ( long ) V_93 - ( long ) V_67 < 0 ) {
switch ( V_92 ) {
case V_95 :
V_93 = V_67 + V_96 ;
break;
case V_97 :
V_93 = V_67 + V_98 ;
break;
case V_99 :
V_93 = V_67 + V_100 ;
break;
default:
break;
}
F_84 ( V_4 -> V_69 -> V_94 [ V_92 ] , V_93 ) ;
return true ;
}
return false ;
}
static void F_85 ( struct V_1 * V_4 , struct V_38 * V_38 )
{
F_71 () ;
if ( F_86 ( F_82 ( V_4 ,
V_95 ) ) ) {
bool V_101 ;
bool T_3 V_102 ;
V_101 = F_82 ( V_4 ,
V_97 ) ;
#if V_103 > 1
T_3 = F_82 ( V_4 ,
V_99 ) ;
#endif
F_74 () ;
F_87 ( V_4 ) ;
if ( F_86 ( V_101 ) )
F_52 ( V_4 , V_38 ) ;
#if V_103 > 1
if ( F_86 ( T_3 ) )
F_88 ( & V_4 -> V_104 ) ;
#endif
} else
F_74 () ;
}
struct V_1 * F_89 ( struct V_105 * V_106 )
{
return F_14 (
V_13 ( V_106 , V_107 ) ) ;
}
struct V_1 * F_21 ( struct V_108 * V_47 )
{
if ( F_86 ( ! V_47 ) )
return NULL ;
return F_14 ( F_90 ( V_47 , V_107 ) ) ;
}
struct V_1 * F_91 ( struct V_109 * V_110 )
{
struct V_1 * V_4 = NULL ;
if ( ! V_110 )
return NULL ;
F_20 () ;
do {
V_4 = F_21 ( F_92 ( V_110 -> V_111 ) ) ;
if ( F_86 ( ! V_4 ) )
break;
} while ( ! F_59 ( & V_4 -> V_15 ) );
F_23 () ;
return V_4 ;
}
struct V_1 * F_93 ( struct V_1 * V_112 ,
struct V_1 * V_113 ,
struct V_114 * V_115 )
{
struct V_1 * V_4 = NULL ;
int V_116 = 0 ;
if ( F_94 () )
return NULL ;
if ( ! V_112 )
V_112 = V_16 ;
if ( V_113 && ! V_115 )
V_116 = F_95 ( & V_113 -> V_15 ) ;
if ( V_113 && V_113 != V_112 )
F_96 ( & V_113 -> V_15 ) ;
if ( ! V_112 -> V_117 && V_112 != V_16 ) {
if ( V_113 )
return NULL ;
return V_112 ;
}
while ( ! V_4 ) {
struct V_118 * V_119 ( V_120 ) ;
struct V_13 * V_15 ;
if ( V_115 ) {
int V_33 = F_97 ( V_115 -> V_60 ) ;
int V_34 = F_98 ( V_115 -> V_60 ) ;
struct V_32 * V_43 ;
V_43 = F_35 ( V_112 , V_33 , V_34 ) ;
V_120 = & V_43 -> V_121 [ V_115 -> V_122 ] ;
if ( V_113 && V_115 -> V_123 != V_120 -> V_123 )
return NULL ;
V_116 = V_120 -> V_124 ;
}
F_20 () ;
V_15 = F_99 ( & V_125 , V_116 + 1 , & V_112 -> V_15 , & V_116 ) ;
if ( V_15 ) {
if ( V_15 == & V_112 -> V_15 || F_59 ( V_15 ) )
V_4 = F_14 ( V_15 ) ;
} else
V_116 = 0 ;
F_23 () ;
if ( V_115 ) {
V_120 -> V_124 = V_116 ;
if ( ! V_15 )
V_120 -> V_123 ++ ;
else if ( ! V_113 && V_4 )
V_115 -> V_123 = V_120 -> V_123 ;
}
if ( V_113 && ! V_15 )
return NULL ;
}
return V_4 ;
}
void F_100 ( struct V_1 * V_112 ,
struct V_1 * V_113 )
{
if ( ! V_112 )
V_112 = V_16 ;
if ( V_113 && V_113 != V_112 )
F_96 ( & V_113 -> V_15 ) ;
}
void F_101 ( struct V_109 * V_110 , enum V_126 V_66 )
{
struct V_1 * V_4 ;
F_20 () ;
V_4 = F_21 ( F_92 ( V_110 -> V_111 ) ) ;
if ( F_86 ( ! V_4 ) )
goto V_127;
switch ( V_66 ) {
case V_128 :
F_102 ( V_4 -> V_69 -> V_76 [ V_129 ] ) ;
break;
case V_130 :
F_102 ( V_4 -> V_69 -> V_76 [ V_131 ] ) ;
break;
default:
F_103 () ;
}
V_127:
F_23 () ;
}
struct V_84 * F_104 ( struct V_60 * V_60 ,
struct V_1 * V_4 )
{
struct V_32 * V_43 ;
struct V_84 * V_84 ;
if ( F_94 () ) {
V_84 = & V_60 -> V_84 ;
goto V_127;
}
V_43 = F_35 ( V_4 , F_97 ( V_60 ) , F_98 ( V_60 ) ) ;
V_84 = & V_43 -> V_84 ;
V_127:
if ( F_86 ( V_84 -> V_60 != V_60 ) )
V_84 -> V_60 = V_60 ;
return V_84 ;
}
struct V_84 * F_105 ( struct V_38 * V_38 , struct V_60 * V_60 )
{
struct V_32 * V_43 ;
struct V_1 * V_4 ;
struct V_132 * V_133 ;
struct V_84 * V_84 ;
if ( F_94 () ) {
V_84 = & V_60 -> V_84 ;
goto V_127;
}
V_133 = F_106 ( V_38 ) ;
V_4 = V_133 -> V_1 ;
if ( ! F_107 ( V_38 ) && ! F_108 ( V_133 ) && V_4 != V_16 )
V_133 -> V_1 = V_4 = V_16 ;
V_43 = F_38 ( V_4 , V_38 ) ;
V_84 = & V_43 -> V_84 ;
V_127:
if ( F_86 ( V_84 -> V_60 != V_60 ) )
V_84 -> V_60 = V_60 ;
return V_84 ;
}
void F_109 ( struct V_84 * V_84 , enum V_85 V_86 ,
int V_78 )
{
struct V_32 * V_43 ;
unsigned long * V_87 ;
if ( F_94 () )
return;
V_43 = F_15 ( V_84 , struct V_32 , V_84 ) ;
V_87 = V_43 -> V_87 + V_86 ;
* V_87 += V_78 ;
F_36 ( ( long ) ( * V_87 ) < 0 ) ;
}
bool F_110 ( const struct V_1 * V_134 ,
struct V_1 * V_4 )
{
if ( V_134 == V_4 )
return true ;
if ( ! V_134 -> V_117 || ! V_4 )
return false ;
return F_111 ( & V_4 -> V_15 , & V_134 -> V_15 ) ;
}
static bool F_112 ( const struct V_1 * V_134 ,
struct V_1 * V_4 )
{
bool V_89 ;
F_20 () ;
V_89 = F_110 ( V_134 , V_4 ) ;
F_23 () ;
return V_89 ;
}
int F_113 ( struct V_108 * V_135 , const struct V_1 * V_4 )
{
int V_89 ;
struct V_1 * V_136 = NULL ;
struct V_108 * V_47 ;
V_47 = F_114 ( V_135 ) ;
if ( V_47 ) {
V_136 = F_91 ( V_47 -> V_110 ) ;
F_115 ( V_47 ) ;
} else {
F_116 ( V_135 ) ;
V_136 = F_21 ( V_135 ) ;
if ( V_136 )
F_117 ( & V_136 -> V_15 ) ;
F_115 ( V_135 ) ;
}
if ( ! V_136 )
return 0 ;
V_89 = F_112 ( V_4 , V_136 ) ;
F_96 ( & V_136 -> V_15 ) ;
return V_89 ;
}
int F_118 ( struct V_84 * V_84 )
{
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 ;
unsigned long V_140 ;
V_138 = F_75 ( V_84 , V_141 ) ;
V_139 = F_75 ( V_84 , V_142 ) ;
V_140 = ( V_138 + V_139 ) >> ( 30 - V_143 ) ;
if ( V_140 )
V_137 = F_119 ( 10 * V_140 ) ;
else
V_137 = 1 ;
return V_138 * V_137 < V_139 ;
}
static unsigned long F_120 ( struct V_1 * V_4 )
{
unsigned long long V_144 ;
V_144 = F_121 ( & V_4 -> V_58 ) ;
if ( V_145 )
V_144 = F_122 ( V_144 , F_121 ( & V_4 -> V_146 ) ) ;
return V_144 >> V_143 ;
}
int F_123 ( struct V_1 * V_4 )
{
struct V_105 * V_147 = V_4 -> V_15 . V_105 ;
if ( V_147 -> V_49 == NULL )
return V_148 ;
return V_4 -> V_149 ;
}
static void F_124 ( struct V_1 * V_4 )
{
F_88 ( & V_150 ) ;
F_88 ( & V_4 -> V_151 ) ;
F_125 () ;
}
static void F_126 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_127 ( & V_150 ) ;
F_127 ( & V_4 -> V_151 ) ;
}
}
static bool F_128 ( struct V_1 * V_4 )
{
F_36 ( ! F_129 () ) ;
return F_130 ( & V_4 -> V_151 ) > 0 ;
}
static bool F_131 ( struct V_1 * V_4 )
{
struct V_1 * V_152 ;
struct V_1 * V_153 ;
bool V_89 = false ;
F_50 ( & V_10 . V_56 ) ;
V_152 = V_10 . V_152 ;
V_153 = V_10 . V_153 ;
if ( ! V_152 )
goto V_154;
V_89 = F_112 ( V_4 , V_152 )
|| F_112 ( V_4 , V_153 ) ;
V_154:
F_51 ( & V_10 . V_56 ) ;
return V_89 ;
}
static bool F_132 ( struct V_1 * V_4 )
{
if ( V_10 . V_155 && V_24 != V_10 . V_155 ) {
if ( F_131 ( V_4 ) ) {
F_133 ( V_156 ) ;
F_134 ( & V_10 . V_157 , & V_156 , V_158 ) ;
if ( V_10 . V_155 )
F_135 () ;
F_136 ( & V_10 . V_157 , & V_156 ) ;
return true ;
}
}
return false ;
}
static void F_137 ( struct V_1 * V_4 ,
unsigned long * V_159 )
{
F_138 ( & V_4 -> V_160 , * V_159 ) ;
}
static void F_139 ( struct V_1 * V_4 ,
unsigned long * V_159 )
{
F_140 ( & V_4 -> V_160 , * V_159 ) ;
}
void F_141 ( struct V_1 * V_4 , struct V_108 * V_47 )
{
struct V_105 * V_161 ;
struct V_105 * V_162 ;
static char V_163 [ V_164 ] ;
int V_89 ;
struct V_1 * V_120 ;
unsigned int V_165 ;
if ( ! V_47 )
return;
F_20 () ;
V_162 = V_4 -> V_15 . V_105 ;
V_161 = F_142 ( V_47 , V_107 ) ;
V_89 = F_143 ( V_161 , V_163 , V_164 ) ;
if ( V_89 < 0 ) {
F_23 () ;
goto V_64;
}
F_23 () ;
F_144 ( L_1 , V_163 ) ;
F_20 () ;
V_89 = F_143 ( V_162 , V_163 , V_164 ) ;
if ( V_89 < 0 ) {
F_23 () ;
goto V_64;
}
F_23 () ;
F_145 ( L_2 , V_163 ) ;
V_64:
F_144 ( L_3 ,
F_33 ( & V_4 -> V_58 , V_31 ) >> 10 ,
F_33 ( & V_4 -> V_58 , V_166 ) >> 10 ,
F_33 ( & V_4 -> V_58 , V_167 ) ) ;
F_144 ( L_4 ,
F_33 ( & V_4 -> V_146 , V_31 ) >> 10 ,
F_33 ( & V_4 -> V_146 , V_166 ) >> 10 ,
F_33 ( & V_4 -> V_146 , V_167 ) ) ;
F_144 ( L_5 ,
F_33 ( & V_4 -> V_30 , V_31 ) >> 10 ,
F_33 ( & V_4 -> V_30 , V_166 ) >> 10 ,
F_33 ( & V_4 -> V_30 , V_167 ) ) ;
F_146 (iter, memcg) {
F_144 ( L_6 ) ;
F_20 () ;
V_89 = F_143 ( V_120 -> V_15 . V_105 , V_163 , V_164 ) ;
if ( ! V_89 )
F_145 ( L_7 , V_163 ) ;
F_23 () ;
F_145 ( L_8 ) ;
for ( V_165 = 0 ; V_165 < V_168 ; V_165 ++ ) {
if ( V_165 == V_74 && ! V_145 )
continue;
F_145 ( L_9 , V_169 [ V_165 ] ,
F_147 ( F_61 ( V_120 , V_165 ) ) ) ;
}
for ( V_165 = 0 ; V_165 < V_170 ; V_165 ++ )
F_145 ( L_10 , V_171 [ V_165 ] ,
F_147 ( F_80 ( V_120 , F_78 ( V_165 ) ) ) ) ;
F_145 ( L_11 ) ;
}
}
static int F_148 ( struct V_1 * V_4 )
{
int V_172 = 0 ;
struct V_1 * V_120 ;
F_146 (iter, memcg)
V_172 ++ ;
return V_172 ;
}
static T_2 F_149 ( struct V_1 * V_4 )
{
T_2 V_173 ;
V_173 = F_33 ( & V_4 -> V_58 , V_166 ) ;
if ( F_123 ( V_4 ) ) {
T_2 V_146 ;
V_173 += V_174 << V_143 ;
V_146 = F_33 ( & V_4 -> V_146 , V_166 ) ;
V_173 = F_122 ( V_173 , V_146 ) ;
}
return V_173 ;
}
static void F_150 ( struct V_1 * V_4 , T_4 V_175 ,
int V_176 )
{
struct V_1 * V_120 ;
unsigned long V_177 = 0 ;
unsigned long V_178 ;
unsigned int V_179 = 0 ;
struct V_108 * V_180 = NULL ;
if ( F_151 ( V_24 ) ) {
F_152 ( V_181 ) ;
return;
}
F_153 ( V_182 , V_175 , V_176 , NULL ) ;
V_178 = F_149 ( V_4 ) >> V_143 ? : 1 ;
F_146 (iter, memcg) {
struct V_105 * V_105 = V_120 -> V_15 . V_105 ;
struct V_183 V_184 ;
struct V_108 * V_135 ;
F_154 ( V_105 , & V_184 ) ;
while ( ( V_135 = F_155 ( V_105 , & V_184 ) ) ) {
switch ( F_156 ( V_135 , V_178 , NULL ,
false ) ) {
case V_185 :
if ( V_180 )
F_157 ( V_180 ) ;
V_180 = V_135 ;
V_177 = V_186 ;
F_158 ( V_180 ) ;
case V_187 :
continue;
case V_188 :
F_159 ( V_105 , & V_184 ) ;
F_100 ( V_4 , V_120 ) ;
if ( V_180 )
F_157 ( V_180 ) ;
return;
case V_189 :
break;
} ;
V_179 = F_160 ( V_135 , V_4 , NULL , V_178 ) ;
if ( V_179 > V_177 ) {
if ( V_180 )
F_157 ( V_180 ) ;
V_180 = V_135 ;
V_177 = V_179 ;
F_158 ( V_180 ) ;
}
}
F_159 ( V_105 , & V_184 ) ;
}
if ( ! V_180 )
return;
V_179 = V_177 * 1000 / V_178 ;
F_161 ( V_180 , V_175 , V_176 , V_179 , V_178 , V_4 ,
NULL , L_12 ) ;
}
static unsigned long F_162 ( struct V_1 * V_4 ,
T_4 V_175 ,
unsigned long V_159 )
{
unsigned long V_90 = 0 ;
bool V_190 = false ;
int V_191 ;
if ( V_159 & V_192 )
V_190 = true ;
if ( ! ( V_159 & V_193 ) && V_4 -> V_194 )
V_190 = true ;
for ( V_191 = 0 ; V_191 < V_195 ; V_191 ++ ) {
if ( V_191 )
F_163 ( V_4 ) ;
V_90 += F_164 ( V_4 , V_175 , V_190 ) ;
if ( V_90 && ( V_159 & V_193 ) )
break;
if ( F_120 ( V_4 ) )
break;
if ( V_191 && ! V_90 )
break;
}
return V_90 ;
}
static bool F_165 ( struct V_1 * V_4 ,
int V_33 , bool V_190 )
{
if ( F_79 ( V_4 , V_33 , V_196 ) )
return true ;
if ( V_190 || ! V_174 )
return false ;
if ( F_79 ( V_4 , V_33 , V_197 ) )
return true ;
return false ;
}
static void F_166 ( struct V_1 * V_4 )
{
int V_33 ;
if ( ! F_130 ( & V_4 -> V_104 ) )
return;
if ( F_167 ( & V_4 -> V_198 ) > 1 )
return;
V_4 -> V_199 = V_200 [ V_201 ] ;
F_168 (nid, node_states[N_MEMORY]) {
if ( ! F_165 ( V_4 , V_33 , false ) )
F_169 ( V_33 , V_4 -> V_199 ) ;
}
F_170 ( & V_4 -> V_104 , 0 ) ;
F_170 ( & V_4 -> V_198 , 0 ) ;
}
int F_171 ( struct V_1 * V_4 )
{
int V_59 ;
F_166 ( V_4 ) ;
V_59 = V_4 -> V_202 ;
V_59 = F_172 ( V_59 , V_4 -> V_199 ) ;
if ( V_59 == V_103 )
V_59 = F_173 ( V_4 -> V_199 ) ;
if ( F_86 ( V_59 == V_103 ) )
V_59 = F_174 () ;
V_4 -> V_202 = V_59 ;
return V_59 ;
}
static bool F_175 ( struct V_1 * V_4 , bool V_190 )
{
int V_33 ;
if ( ! F_176 ( V_4 -> V_199 ) ) {
for ( V_33 = F_173 ( V_4 -> V_199 ) ;
V_33 < V_103 ;
V_33 = F_172 ( V_33 , V_4 -> V_199 ) ) {
if ( F_165 ( V_4 , V_33 , V_190 ) )
return true ;
}
}
F_81 (nid, N_MEMORY) {
if ( F_177 ( V_33 , V_4 -> V_199 ) )
continue;
if ( F_165 ( V_4 , V_33 , V_190 ) )
return true ;
}
return false ;
}
int F_171 ( struct V_1 * V_4 )
{
return 0 ;
}
static bool F_175 ( struct V_1 * V_4 , bool V_190 )
{
return F_165 ( V_4 , 0 , V_190 ) ;
}
static int F_178 ( struct V_1 * V_134 ,
struct V_60 * V_60 ,
T_4 V_175 ,
unsigned long * V_203 )
{
struct V_1 * V_204 = NULL ;
int V_90 = 0 ;
int V_191 = 0 ;
unsigned long V_57 ;
unsigned long V_205 ;
struct V_114 V_115 = {
. V_60 = V_60 ,
. V_122 = 0 ,
} ;
V_57 = F_54 ( & V_134 -> V_58 ) >> V_143 ;
while ( 1 ) {
V_204 = F_93 ( V_134 , V_204 , & V_115 ) ;
if ( ! V_204 ) {
V_191 ++ ;
if ( V_191 >= 2 ) {
if ( ! V_90 )
break;
if ( V_90 >= ( V_57 >> 2 ) ||
( V_191 > V_195 ) )
break;
}
continue;
}
if ( ! F_175 ( V_204 , false ) )
continue;
V_90 += F_179 ( V_204 , V_175 , false ,
V_60 , & V_205 ) ;
* V_203 += V_205 ;
if ( ! F_54 ( & V_134 -> V_58 ) )
break;
}
F_100 ( V_134 , V_204 ) ;
return V_90 ;
}
static bool F_180 ( struct V_1 * V_4 )
{
struct V_1 * V_120 , * V_206 = NULL ;
F_146 (iter, memcg) {
if ( V_120 -> V_207 ) {
V_206 = V_120 ;
F_100 ( V_4 , V_120 ) ;
break;
} else
V_120 -> V_207 = true ;
}
if ( ! V_206 )
return true ;
F_146 (iter, memcg) {
if ( V_120 == V_206 ) {
F_100 ( V_4 , V_120 ) ;
break;
}
V_120 -> V_207 = false ;
}
return false ;
}
static int F_181 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_146 (iter, memcg)
V_120 -> V_207 = false ;
return 0 ;
}
static void F_182 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_146 (iter, memcg)
F_88 ( & V_120 -> V_208 ) ;
}
static void F_183 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_146 (iter, memcg)
F_184 ( & V_120 -> V_208 , - 1 , 0 ) ;
}
static int F_185 ( T_5 * V_156 ,
unsigned V_209 , int V_210 , void * V_211 )
{
struct V_1 * V_212 = (struct V_1 * ) V_211 ;
struct V_1 * V_213 ;
struct V_214 * V_214 ;
V_214 = F_15 ( V_156 , struct V_214 , V_156 ) ;
V_213 = V_214 -> V_4 ;
if ( ! F_112 ( V_213 , V_212 )
&& ! F_112 ( V_212 , V_213 ) )
return 0 ;
return F_186 ( V_156 , V_209 , V_210 , V_211 ) ;
}
static void F_187 ( struct V_1 * V_4 )
{
F_188 ( & V_215 , V_216 , 0 , V_4 ) ;
}
static void F_189 ( struct V_1 * V_4 )
{
if ( V_4 && F_130 ( & V_4 -> V_208 ) )
F_187 ( V_4 ) ;
}
static bool F_190 ( struct V_1 * V_4 , T_4 V_217 ,
int V_176 )
{
struct V_214 V_218 ;
bool V_219 , V_220 ;
V_218 . V_4 = V_4 ;
V_218 . V_156 . V_159 = 0 ;
V_218 . V_156 . V_221 = F_185 ;
V_218 . V_156 . V_222 = V_24 ;
F_191 ( & V_218 . V_156 . V_223 ) ;
V_220 = true ;
F_182 ( V_4 ) ;
F_50 ( & V_224 ) ;
V_219 = F_180 ( V_4 ) ;
F_134 ( & V_215 , & V_218 . V_156 , V_225 ) ;
if ( ! V_219 || V_4 -> V_226 )
V_220 = false ;
if ( V_219 )
F_192 ( V_4 ) ;
F_51 ( & V_224 ) ;
if ( V_220 ) {
F_136 ( & V_215 , & V_218 . V_156 ) ;
F_150 ( V_4 , V_217 , V_176 ) ;
} else {
F_135 () ;
F_136 ( & V_215 , & V_218 . V_156 ) ;
}
F_50 ( & V_224 ) ;
if ( V_219 )
F_181 ( V_4 ) ;
F_187 ( V_4 ) ;
F_51 ( & V_224 ) ;
F_183 ( V_4 ) ;
if ( F_193 ( V_181 ) || F_151 ( V_24 ) )
return false ;
F_194 ( 1 ) ;
return true ;
}
void F_195 ( struct V_38 * V_38 ,
bool * V_219 , unsigned long * V_159 )
{
struct V_1 * V_4 ;
struct V_132 * V_133 ;
V_133 = F_106 ( V_38 ) ;
V_227:
V_4 = V_133 -> V_1 ;
if ( F_86 ( ! V_4 || ! F_108 ( V_133 ) ) )
return;
if ( ! F_128 ( V_4 ) )
return;
F_137 ( V_4 , V_159 ) ;
if ( V_4 != V_133 -> V_1 || ! F_108 ( V_133 ) ) {
F_139 ( V_4 , V_159 ) ;
goto V_227;
}
* V_219 = true ;
}
void F_196 ( struct V_38 * V_38 , unsigned long * V_159 )
{
struct V_132 * V_133 = F_106 ( V_38 ) ;
F_139 ( V_133 -> V_1 , V_159 ) ;
}
void F_197 ( struct V_38 * V_38 ,
enum V_228 V_66 , int V_67 )
{
struct V_1 * V_4 ;
struct V_132 * V_133 = F_106 ( V_38 ) ;
unsigned long V_119 ( V_159 ) ;
if ( F_94 () )
return;
V_4 = V_133 -> V_1 ;
if ( F_86 ( ! V_4 || ! F_108 ( V_133 ) ) )
return;
switch ( V_66 ) {
case V_229 :
V_66 = V_230 ;
break;
default:
F_103 () ;
}
F_68 ( V_4 -> V_69 -> V_70 [ V_66 ] , V_67 ) ;
}
static bool F_198 ( struct V_1 * V_4 , unsigned int V_78 )
{
struct V_231 * V_232 ;
bool V_89 = true ;
if ( V_78 > V_233 )
return false ;
V_232 = & F_199 ( V_234 ) ;
if ( V_4 == V_232 -> V_235 && V_232 -> V_78 >= V_78 )
V_232 -> V_78 -= V_78 ;
else
V_89 = false ;
F_200 ( V_234 ) ;
return V_89 ;
}
static void F_201 ( struct V_231 * V_232 )
{
struct V_1 * V_236 = V_232 -> V_235 ;
if ( V_232 -> V_78 ) {
unsigned long V_237 = V_232 -> V_78 * V_238 ;
F_202 ( & V_236 -> V_58 , V_237 ) ;
if ( V_145 )
F_202 ( & V_236 -> V_146 , V_237 ) ;
V_232 -> V_78 = 0 ;
}
V_232 -> V_235 = NULL ;
}
static void F_203 ( struct V_239 * V_240 )
{
struct V_231 * V_232 = & F_204 ( V_234 ) ;
F_201 ( V_232 ) ;
F_8 ( V_241 , & V_232 -> V_159 ) ;
}
static void T_6 F_205 ( void )
{
int V_68 ;
F_206 (cpu) {
struct V_231 * V_232 =
& F_64 ( V_234 , V_68 ) ;
F_207 ( & V_232 -> V_242 , F_203 ) ;
}
}
static void F_208 ( struct V_1 * V_4 , unsigned int V_78 )
{
struct V_231 * V_232 = & F_199 ( V_234 ) ;
if ( V_232 -> V_235 != V_4 ) {
F_201 ( V_232 ) ;
V_232 -> V_235 = V_4 ;
}
V_232 -> V_78 += V_78 ;
F_200 ( V_234 ) ;
}
static void F_209 ( struct V_1 * V_134 , bool V_210 )
{
int V_68 , V_243 ;
F_62 () ;
V_243 = F_210 () ;
F_63 (cpu) {
struct V_231 * V_232 = & F_64 ( V_234 , V_68 ) ;
struct V_1 * V_4 ;
V_4 = V_232 -> V_235 ;
if ( ! V_4 || ! V_232 -> V_78 )
continue;
if ( ! F_112 ( V_134 , V_4 ) )
continue;
if ( ! F_211 ( V_241 , & V_232 -> V_159 ) ) {
if ( V_68 == V_243 )
F_203 ( & V_232 -> V_242 ) ;
else
F_212 ( V_68 , & V_232 -> V_242 ) ;
}
}
F_213 () ;
if ( ! V_210 )
goto V_127;
F_63 (cpu) {
struct V_231 * V_232 = & F_64 ( V_234 , V_68 ) ;
if ( F_5 ( V_241 , & V_232 -> V_159 ) )
F_214 ( & V_232 -> V_242 ) ;
}
V_127:
F_66 () ;
}
static void F_163 ( struct V_1 * V_134 )
{
if ( ! F_215 ( & V_244 ) )
return;
F_209 ( V_134 , false ) ;
F_216 ( & V_244 ) ;
}
static void F_217 ( struct V_1 * V_134 )
{
F_218 ( & V_244 ) ;
F_209 ( V_134 , true ) ;
F_216 ( & V_244 ) ;
}
static void F_219 ( struct V_1 * V_4 , int V_68 )
{
int V_165 ;
F_50 ( & V_4 -> V_71 ) ;
for ( V_165 = 0 ; V_165 < V_168 ; V_165 ++ ) {
long V_245 = F_64 ( V_4 -> V_69 -> V_70 [ V_165 ] , V_68 ) ;
F_64 ( V_4 -> V_69 -> V_70 [ V_165 ] , V_68 ) = 0 ;
V_4 -> V_72 . V_70 [ V_165 ] += V_245 ;
}
for ( V_165 = 0 ; V_165 < V_246 ; V_165 ++ ) {
unsigned long V_245 = F_64 ( V_4 -> V_69 -> V_76 [ V_165 ] , V_68 ) ;
F_64 ( V_4 -> V_69 -> V_76 [ V_165 ] , V_68 ) = 0 ;
V_4 -> V_72 . V_76 [ V_165 ] += V_245 ;
}
F_51 ( & V_4 -> V_71 ) ;
}
static int T_7 F_220 ( struct V_247 * V_248 ,
unsigned long V_249 ,
void * V_250 )
{
int V_68 = ( unsigned long ) V_250 ;
struct V_231 * V_232 ;
struct V_1 * V_120 ;
if ( V_249 == V_251 )
return V_252 ;
if ( V_249 != V_253 && V_249 != V_254 )
return V_252 ;
F_221 (iter)
F_219 ( V_120 , V_68 ) ;
V_232 = & F_64 ( V_234 , V_68 ) ;
F_201 ( V_232 ) ;
return V_252 ;
}
static int F_222 ( struct V_1 * V_4 , T_4 V_175 ,
unsigned int V_78 , unsigned int V_255 ,
bool V_256 )
{
unsigned long V_257 = V_78 * V_238 ;
struct V_1 * V_258 ;
struct V_259 * V_260 ;
unsigned long V_159 = 0 ;
int V_89 ;
V_89 = F_223 ( & V_4 -> V_58 , V_257 , & V_260 ) ;
if ( F_224 ( ! V_89 ) ) {
if ( ! V_145 )
return V_261 ;
V_89 = F_223 ( & V_4 -> V_146 , V_257 , & V_260 ) ;
if ( F_224 ( ! V_89 ) )
return V_261 ;
F_202 ( & V_4 -> V_58 , V_257 ) ;
V_258 = F_225 ( V_260 , V_146 ) ;
V_159 |= V_192 ;
} else
V_258 = F_225 ( V_260 , V_58 ) ;
if ( V_78 > V_255 )
return V_262 ;
if ( ! ( V_175 & V_263 ) )
return V_264 ;
if ( V_175 & V_265 )
return V_266 ;
V_89 = F_162 ( V_258 , V_175 , V_159 ) ;
if ( F_120 ( V_258 ) >= V_78 )
return V_262 ;
if ( V_78 <= ( 1 << V_267 ) && V_89 )
return V_262 ;
if ( F_132 ( V_258 ) )
return V_262 ;
if ( ! V_256 )
return V_266 ;
if ( ! F_190 ( V_258 , V_175 , F_226 ( V_257 ) ) )
return V_268 ;
return V_262 ;
}
static int F_227 ( struct V_109 * V_110 ,
T_4 V_175 ,
unsigned int V_78 ,
struct V_1 * * V_269 ,
bool V_270 )
{
unsigned int V_271 = F_228 ( V_233 , V_78 ) ;
int V_272 = V_273 ;
struct V_1 * V_4 = NULL ;
int V_89 ;
if ( F_86 ( F_193 ( V_181 )
|| F_151 ( V_24 ) ) )
goto V_274;
if ( ! * V_269 && ! V_110 )
* V_269 = V_16 ;
V_227:
if ( * V_269 ) {
V_4 = * V_269 ;
if ( F_16 ( V_4 ) )
goto V_64;
if ( F_198 ( V_4 , V_78 ) )
goto V_64;
F_117 ( & V_4 -> V_15 ) ;
} else {
struct V_108 * V_47 ;
F_20 () ;
V_47 = F_92 ( V_110 -> V_111 ) ;
V_4 = F_21 ( V_47 ) ;
if ( ! V_4 )
V_4 = V_16 ;
if ( F_16 ( V_4 ) ) {
F_23 () ;
goto V_64;
}
if ( F_198 ( V_4 , V_78 ) ) {
F_23 () ;
goto V_64;
}
if ( ! F_59 ( & V_4 -> V_15 ) ) {
F_23 () ;
goto V_227;
}
F_23 () ;
}
do {
bool V_256 ;
if ( F_151 ( V_24 ) ) {
F_96 ( & V_4 -> V_15 ) ;
goto V_274;
}
V_256 = false ;
if ( V_270 && ! V_272 ) {
V_256 = true ;
V_272 = V_273 ;
}
V_89 = F_222 ( V_4 , V_175 , V_271 , V_78 ,
V_256 ) ;
switch ( V_89 ) {
case V_261 :
break;
case V_262 :
V_271 = V_78 ;
F_96 ( & V_4 -> V_15 ) ;
V_4 = NULL ;
goto V_227;
case V_264 :
F_96 ( & V_4 -> V_15 ) ;
goto V_275;
case V_266 :
if ( ! V_270 ) {
F_96 ( & V_4 -> V_15 ) ;
goto V_275;
}
V_272 -- ;
break;
case V_268 :
F_96 ( & V_4 -> V_15 ) ;
goto V_274;
}
} while ( V_89 != V_261 );
if ( V_271 > V_78 )
F_208 ( V_4 , V_271 - V_78 ) ;
F_96 ( & V_4 -> V_15 ) ;
V_64:
* V_269 = V_4 ;
return 0 ;
V_275:
* V_269 = NULL ;
return - V_276 ;
V_274:
* V_269 = V_16 ;
return - V_277 ;
}
static void F_229 ( struct V_1 * V_4 ,
unsigned int V_78 )
{
if ( ! F_16 ( V_4 ) ) {
unsigned long V_237 = V_78 * V_238 ;
F_202 ( & V_4 -> V_58 , V_237 ) ;
if ( V_145 )
F_202 ( & V_4 -> V_146 , V_237 ) ;
}
}
static void F_230 ( struct V_1 * V_4 ,
unsigned int V_78 )
{
unsigned long V_237 = V_78 * V_238 ;
if ( F_16 ( V_4 ) )
return;
F_231 ( & V_4 -> V_58 , V_4 -> V_58 . V_49 , V_237 ) ;
if ( V_145 )
F_231 ( & V_4 -> V_146 ,
V_4 -> V_146 . V_49 , V_237 ) ;
}
static struct V_1 * F_232 ( unsigned short V_116 )
{
struct V_13 * V_15 ;
if ( ! V_116 )
return NULL ;
V_15 = F_233 ( & V_125 , V_116 ) ;
if ( ! V_15 )
return NULL ;
return F_14 ( V_15 ) ;
}
struct V_1 * F_234 ( struct V_38 * V_38 )
{
struct V_1 * V_4 = NULL ;
struct V_132 * V_133 ;
unsigned short V_116 ;
T_8 V_278 ;
F_36 ( ! F_235 ( V_38 ) ) ;
V_133 = F_106 ( V_38 ) ;
F_236 ( V_133 ) ;
if ( F_108 ( V_133 ) ) {
V_4 = V_133 -> V_1 ;
if ( V_4 && ! F_59 ( & V_4 -> V_15 ) )
V_4 = NULL ;
} else if ( F_237 ( V_38 ) ) {
V_278 . V_67 = F_238 ( V_38 ) ;
V_116 = F_239 ( V_278 ) ;
F_20 () ;
V_4 = F_232 ( V_116 ) ;
if ( V_4 && ! F_59 ( & V_4 -> V_15 ) )
V_4 = NULL ;
F_23 () ;
}
F_240 ( V_133 ) ;
return V_4 ;
}
static void F_241 ( struct V_1 * V_4 ,
struct V_38 * V_38 ,
unsigned int V_78 ,
enum V_279 V_280 ,
bool V_281 )
{
struct V_132 * V_133 = F_106 ( V_38 ) ;
struct V_60 * V_119 ( V_60 ) ;
struct V_84 * V_84 ;
bool V_282 = false ;
bool V_77 ;
F_236 ( V_133 ) ;
F_36 ( F_108 ( V_133 ) ) ;
if ( V_281 ) {
V_60 = F_242 ( V_38 ) ;
F_243 ( & V_60 -> V_283 ) ;
if ( F_107 ( V_38 ) ) {
V_84 = F_104 ( V_60 , V_133 -> V_1 ) ;
F_244 ( V_38 ) ;
F_245 ( V_38 , V_84 , F_246 ( V_38 ) ) ;
V_282 = true ;
}
}
V_133 -> V_1 = V_4 ;
F_247 () ;
F_248 ( V_133 ) ;
if ( V_281 ) {
if ( V_282 ) {
V_84 = F_104 ( V_60 , V_133 -> V_1 ) ;
F_36 ( F_107 ( V_38 ) ) ;
F_249 ( V_38 ) ;
F_250 ( V_38 , V_84 , F_246 ( V_38 ) ) ;
}
F_251 ( & V_60 -> V_283 ) ;
}
if ( V_280 == V_284 )
V_77 = true ;
else
V_77 = false ;
F_70 ( V_4 , V_77 , V_78 ) ;
F_240 ( V_133 ) ;
F_85 ( V_4 , V_38 ) ;
}
static inline bool F_252 ( struct V_1 * V_4 )
{
return ! F_94 () && ! F_16 ( V_4 ) &&
( V_4 -> V_6 & V_285 ) ;
}
static struct V_286 * F_253 ( struct V_287 * V_47 )
{
struct V_286 * V_288 ;
F_36 ( V_47 -> V_289 ) ;
V_288 = V_47 -> V_290 ;
return V_288 -> V_291 -> V_292 [ F_254 ( V_47 -> V_4 ) ] ;
}
static int F_255 ( struct V_105 * V_106 , struct V_293 * V_294 ,
struct V_295 * V_296 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
struct V_287 * V_297 ;
if ( ! F_252 ( V_4 ) )
return - V_298 ;
F_256 ( V_296 ) ;
F_218 ( & V_4 -> V_299 ) ;
F_257 (params, &memcg->memcg_slab_caches, list)
F_258 ( F_253 ( V_297 ) , V_296 ) ;
F_216 ( & V_4 -> V_299 ) ;
return 0 ;
}
static int F_259 ( struct V_1 * V_4 , T_4 V_300 , T_2 V_301 )
{
struct V_259 * V_260 ;
struct V_1 * V_302 ;
int V_89 = 0 ;
bool V_303 ;
V_89 = F_223 ( & V_4 -> V_30 , V_301 , & V_260 ) ;
if ( V_89 )
return V_89 ;
V_303 = ( V_300 & V_304 ) && ! ( V_300 & V_265 ) ;
V_302 = V_4 ;
V_89 = F_227 ( NULL , V_300 , V_301 >> V_143 ,
& V_302 , V_303 ) ;
if ( V_89 == - V_277 ) {
F_260 ( & V_4 -> V_58 , V_301 , & V_260 ) ;
if ( V_145 )
F_260 ( & V_4 -> V_146 , V_301 ,
& V_260 ) ;
V_89 = 0 ;
} else if ( V_89 )
F_202 ( & V_4 -> V_30 , V_301 ) ;
return V_89 ;
}
static void F_261 ( struct V_1 * V_4 , T_2 V_301 )
{
F_202 ( & V_4 -> V_58 , V_301 ) ;
if ( V_145 )
F_202 ( & V_4 -> V_146 , V_301 ) ;
if ( F_202 ( & V_4 -> V_30 , V_301 ) )
return;
if ( F_10 ( V_4 ) )
F_26 ( V_4 ) ;
}
void F_262 ( struct V_1 * V_4 , struct V_286 * V_288 )
{
if ( ! V_4 )
return;
F_218 ( & V_4 -> V_299 ) ;
F_263 ( & V_288 -> V_291 -> V_305 , & V_4 -> V_306 ) ;
F_216 ( & V_4 -> V_299 ) ;
}
int F_254 ( struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_29 : - 1 ;
}
int F_264 ( struct V_1 * V_4 )
{
int V_172 , V_89 ;
V_172 = F_265 ( & V_28 ,
0 , V_307 , V_308 ) ;
if ( V_172 < 0 )
return V_172 ;
F_6 ( V_4 ) ;
V_89 = F_266 ( V_172 + 1 ) ;
if ( V_89 ) {
F_32 ( & V_28 , V_172 ) ;
F_7 ( V_4 ) ;
return V_89 ;
}
V_4 -> V_29 = V_172 ;
F_191 ( & V_4 -> V_306 ) ;
F_267 ( & V_4 -> V_299 ) ;
return 0 ;
}
static T_1 F_268 ( int V_309 )
{
T_9 V_301 ;
if ( V_309 <= 0 )
return 0 ;
V_301 = 2 * V_309 ;
if ( V_301 < V_310 )
V_301 = V_310 ;
else if ( V_301 > V_307 )
V_301 = V_307 ;
return V_301 ;
}
void F_269 ( int V_172 )
{
if ( V_172 > V_311 )
V_311 = F_268 ( V_172 ) ;
}
int F_270 ( struct V_286 * V_14 , int V_309 )
{
struct V_287 * V_312 = V_14 -> V_291 ;
F_36 ( V_14 -> V_291 && ! V_14 -> V_291 -> V_289 ) ;
if ( V_309 > V_311 ) {
int V_165 ;
T_9 V_301 = F_268 ( V_309 ) ;
V_301 *= sizeof( void * ) ;
V_301 += sizeof( struct V_287 ) ;
V_14 -> V_291 = F_271 ( V_301 , V_308 ) ;
if ( ! V_14 -> V_291 ) {
V_14 -> V_291 = V_312 ;
return - V_276 ;
}
F_207 ( & V_14 -> V_291 -> V_313 ,
V_314 ) ;
V_14 -> V_291 -> V_289 = true ;
for ( V_165 = 0 ; V_165 < V_311 ; V_165 ++ ) {
if ( ! V_312 -> V_292 [ V_165 ] )
continue;
V_14 -> V_291 -> V_292 [ V_165 ] =
V_312 -> V_292 [ V_165 ] ;
}
F_272 ( V_312 ) ;
}
return 0 ;
}
int F_273 ( struct V_1 * V_4 , struct V_286 * V_14 ,
struct V_286 * V_290 )
{
T_1 V_301 = sizeof( struct V_287 ) ;
if ( ! F_274 () )
return 0 ;
if ( ! V_4 )
V_301 += V_311 * sizeof( void * ) ;
V_14 -> V_291 = F_271 ( V_301 , V_308 ) ;
if ( ! V_14 -> V_291 )
return - V_276 ;
F_207 ( & V_14 -> V_291 -> V_313 ,
V_314 ) ;
if ( V_4 ) {
V_14 -> V_291 -> V_4 = V_4 ;
V_14 -> V_291 -> V_290 = V_290 ;
} else
V_14 -> V_291 -> V_289 = true ;
return 0 ;
}
void F_275 ( struct V_286 * V_14 )
{
struct V_286 * V_112 ;
struct V_1 * V_4 ;
int V_116 ;
if ( ! V_14 -> V_291 )
return;
if ( V_14 -> V_291 -> V_289 )
goto V_127;
V_4 = V_14 -> V_291 -> V_4 ;
V_116 = F_254 ( V_4 ) ;
V_112 = V_14 -> V_291 -> V_290 ;
V_112 -> V_291 -> V_292 [ V_116 ] = NULL ;
F_26 ( V_4 ) ;
F_218 ( & V_4 -> V_299 ) ;
F_276 ( & V_14 -> V_291 -> V_305 ) ;
F_216 ( & V_4 -> V_299 ) ;
V_127:
F_272 ( V_14 -> V_291 ) ;
}
static inline void F_277 ( void )
{
F_36 ( ! V_24 -> V_110 ) ;
V_24 -> V_315 ++ ;
}
static inline void F_278 ( void )
{
F_36 ( ! V_24 -> V_110 ) ;
V_24 -> V_315 -- ;
}
static void V_314 ( struct V_239 * V_316 )
{
struct V_286 * V_288 ;
struct V_287 * V_47 ;
V_47 = F_15 ( V_316 , struct V_287 , V_313 ) ;
V_288 = F_253 ( V_47 ) ;
if ( F_130 ( & V_288 -> V_291 -> V_78 ) != 0 ) {
F_279 ( V_288 ) ;
if ( F_130 ( & V_288 -> V_291 -> V_78 ) == 0 )
return;
} else
F_280 ( V_288 ) ;
}
void F_281 ( struct V_286 * V_288 )
{
if ( ! V_288 -> V_291 -> V_317 )
return;
if ( F_282 ( & V_288 -> V_291 -> V_313 ) )
return;
F_283 ( & V_288 -> V_291 -> V_313 ) ;
}
static char * F_284 ( struct V_1 * V_4 , struct V_286 * V_14 )
{
char * V_318 ;
struct V_319 * V_319 ;
F_20 () ;
V_319 = F_92 ( V_4 -> V_15 . V_105 -> V_319 ) ;
F_23 () ;
F_18 ( V_319 == NULL ) ;
V_318 = F_285 ( V_308 , L_13 , V_14 -> V_318 ,
F_254 ( V_4 ) , V_319 -> V_320 . V_318 ) ;
return V_318 ;
}
static struct V_286 * F_286 ( struct V_1 * V_4 ,
struct V_286 * V_14 )
{
char * V_318 ;
struct V_286 * V_321 ;
V_318 = F_284 ( V_4 , V_14 ) ;
if ( ! V_318 )
return NULL ;
V_321 = F_287 ( V_4 , V_318 , V_14 -> V_322 , V_14 -> V_323 ,
( V_14 -> V_159 & ~ V_324 ) , V_14 -> V_325 , V_14 ) ;
if ( V_321 )
V_321 -> V_326 |= V_327 ;
F_272 ( V_318 ) ;
return V_321 ;
}
static struct V_286 * F_288 ( struct V_1 * V_4 ,
struct V_286 * V_288 )
{
struct V_286 * V_328 ;
int V_66 ;
F_18 ( ! F_252 ( V_4 ) ) ;
V_66 = F_254 ( V_4 ) ;
F_218 ( & V_329 ) ;
V_328 = V_288 -> V_291 -> V_292 [ V_66 ] ;
if ( V_328 )
goto V_127;
V_328 = F_286 ( V_4 , V_288 ) ;
if ( V_328 == NULL ) {
V_328 = V_288 ;
goto V_127;
}
F_19 ( V_4 ) ;
F_170 ( & V_328 -> V_291 -> V_78 , 0 ) ;
V_288 -> V_291 -> V_292 [ V_66 ] = V_328 ;
F_289 () ;
V_127:
F_216 ( & V_329 ) ;
return V_328 ;
}
void F_290 ( struct V_286 * V_14 )
{
struct V_286 * V_330 ;
int V_165 ;
if ( ! V_14 -> V_291 )
return;
if ( ! V_14 -> V_291 -> V_289 )
return;
F_218 ( & V_331 ) ;
for ( V_165 = 0 ; V_165 < V_311 ; V_165 ++ ) {
V_330 = V_14 -> V_291 -> V_292 [ V_165 ] ;
if ( ! V_330 )
continue;
V_330 -> V_291 -> V_317 = false ;
F_291 ( & V_330 -> V_291 -> V_313 ) ;
F_280 ( V_330 ) ;
}
F_216 ( & V_331 ) ;
}
static void F_292 ( struct V_1 * V_4 )
{
struct V_286 * V_288 ;
struct V_287 * V_297 ;
if ( ! F_4 ( V_4 ) )
return;
F_218 ( & V_4 -> V_299 ) ;
F_257 (params, &memcg->memcg_slab_caches, list) {
V_288 = F_253 ( V_297 ) ;
V_288 -> V_291 -> V_317 = true ;
F_283 ( & V_288 -> V_291 -> V_313 ) ;
}
F_216 ( & V_4 -> V_299 ) ;
}
static void F_293 ( struct V_239 * V_316 )
{
struct V_332 * V_333 ;
V_333 = F_15 ( V_316 , struct V_332 , V_242 ) ;
F_288 ( V_333 -> V_4 , V_333 -> V_288 ) ;
F_96 ( & V_333 -> V_4 -> V_15 ) ;
F_272 ( V_333 ) ;
}
static void F_294 ( struct V_1 * V_4 ,
struct V_286 * V_288 )
{
struct V_332 * V_333 ;
V_333 = F_295 ( sizeof( struct V_332 ) , V_334 ) ;
if ( V_333 == NULL )
return;
if ( ! F_59 ( & V_4 -> V_15 ) ) {
F_272 ( V_333 ) ;
return;
}
V_333 -> V_4 = V_4 ;
V_333 -> V_288 = V_288 ;
F_207 ( & V_333 -> V_242 , F_293 ) ;
F_283 ( & V_333 -> V_242 ) ;
}
static void F_296 ( struct V_1 * V_4 ,
struct V_286 * V_288 )
{
F_277 () ;
F_294 ( V_4 , V_288 ) ;
F_278 () ;
}
struct V_286 * F_297 ( struct V_286 * V_288 ,
T_4 V_300 )
{
struct V_1 * V_4 ;
int V_66 ;
F_36 ( ! V_288 -> V_291 ) ;
F_36 ( ! V_288 -> V_291 -> V_289 ) ;
if ( ! V_24 -> V_110 || V_24 -> V_315 )
return V_288 ;
F_20 () ;
V_4 = F_21 ( F_92 ( V_24 -> V_110 -> V_111 ) ) ;
F_23 () ;
if ( ! F_252 ( V_4 ) )
return V_288 ;
V_66 = F_254 ( V_4 ) ;
F_298 () ;
if ( F_86 ( V_288 -> V_291 -> V_292 [ V_66 ] == NULL ) ) {
F_296 ( V_4 , V_288 ) ;
return V_288 ;
}
return V_288 -> V_291 -> V_292 [ V_66 ] ;
}
bool
F_299 ( T_4 V_300 , struct V_1 * * V_302 , int V_176 )
{
struct V_1 * V_4 ;
int V_89 ;
* V_302 = NULL ;
V_4 = F_91 ( V_24 -> V_110 ) ;
if ( F_86 ( ! V_4 ) )
return true ;
if ( ! F_252 ( V_4 ) ) {
F_96 ( & V_4 -> V_15 ) ;
return true ;
}
V_89 = F_259 ( V_4 , V_300 , V_238 << V_176 ) ;
if ( ! V_89 )
* V_302 = V_4 ;
F_96 ( & V_4 -> V_15 ) ;
return ( V_89 == 0 ) ;
}
void F_300 ( struct V_38 * V_38 , struct V_1 * V_4 ,
int V_176 )
{
struct V_132 * V_133 ;
F_36 ( F_16 ( V_4 ) ) ;
if ( ! V_38 ) {
F_261 ( V_4 , V_238 << V_176 ) ;
return;
}
V_133 = F_106 ( V_38 ) ;
F_236 ( V_133 ) ;
V_133 -> V_1 = V_4 ;
F_248 ( V_133 ) ;
F_240 ( V_133 ) ;
}
void F_301 ( struct V_38 * V_38 , int V_176 )
{
struct V_1 * V_4 = NULL ;
struct V_132 * V_133 ;
V_133 = F_106 ( V_38 ) ;
if ( ! F_108 ( V_133 ) )
return;
F_236 ( V_133 ) ;
if ( F_108 ( V_133 ) ) {
V_4 = V_133 -> V_1 ;
F_302 ( V_133 ) ;
}
F_240 ( V_133 ) ;
if ( ! V_4 )
return;
F_36 ( F_16 ( V_4 ) ) ;
F_261 ( V_4 , V_238 << V_176 ) ;
}
static inline void F_292 ( struct V_1 * V_4 )
{
}
void F_303 ( struct V_38 * V_335 )
{
struct V_132 * V_336 = F_106 ( V_335 ) ;
struct V_132 * V_133 ;
int V_165 ;
if ( F_94 () )
return;
for ( V_165 = 1 ; V_165 < V_337 ; V_165 ++ ) {
V_133 = V_336 + V_165 ;
V_133 -> V_1 = V_336 -> V_1 ;
F_247 () ;
V_133 -> V_159 = V_336 -> V_159 & ~ V_338 ;
}
}
static int F_304 ( struct V_38 * V_38 ,
unsigned int V_78 ,
struct V_132 * V_133 ,
struct V_1 * V_152 ,
struct V_1 * V_153 )
{
unsigned long V_159 ;
int V_89 ;
bool V_77 = F_305 ( V_38 ) ;
F_36 ( V_152 == V_153 ) ;
F_36 ( F_107 ( V_38 ) ) ;
V_89 = - V_339 ;
if ( V_78 > 1 && ! F_306 ( V_38 ) )
goto V_127;
F_236 ( V_133 ) ;
V_89 = - V_340 ;
if ( ! F_108 ( V_133 ) || V_133 -> V_1 != V_152 )
goto V_154;
F_137 ( V_152 , & V_159 ) ;
if ( ! V_77 && F_307 ( V_38 ) ) {
F_71 () ;
F_308 ( V_152 -> V_69 -> V_70 [ V_230 ] ) ;
F_73 ( V_153 -> V_69 -> V_70 [ V_230 ] ) ;
F_74 () ;
}
F_70 ( V_152 , V_77 , - V_78 ) ;
V_133 -> V_1 = V_153 ;
F_70 ( V_153 , V_77 , V_78 ) ;
F_139 ( V_152 , & V_159 ) ;
V_89 = 0 ;
V_154:
F_240 ( V_133 ) ;
F_85 ( V_153 , V_38 ) ;
F_85 ( V_152 , V_38 ) ;
V_127:
return V_89 ;
}
static int F_309 ( struct V_38 * V_38 ,
struct V_132 * V_133 ,
struct V_1 * V_341 )
{
struct V_1 * V_49 ;
unsigned int V_78 ;
unsigned long V_119 ( V_159 ) ;
int V_89 ;
F_36 ( F_16 ( V_341 ) ) ;
V_89 = - V_339 ;
if ( ! F_310 ( V_38 ) )
goto V_127;
if ( F_311 ( V_38 ) )
goto V_342;
V_78 = F_312 ( V_38 ) ;
V_49 = F_53 ( V_341 ) ;
if ( ! V_49 )
V_49 = V_16 ;
if ( V_78 > 1 ) {
F_36 ( ! F_306 ( V_38 ) ) ;
V_159 = F_313 ( V_38 ) ;
}
V_89 = F_304 ( V_38 , V_78 ,
V_133 , V_341 , V_49 ) ;
if ( ! V_89 )
F_230 ( V_341 , V_78 ) ;
if ( V_78 > 1 )
F_314 ( V_38 , V_159 ) ;
F_315 ( V_38 ) ;
V_342:
F_316 ( V_38 ) ;
V_127:
return V_89 ;
}
static int F_317 ( struct V_38 * V_38 , struct V_109 * V_110 ,
T_4 V_175 , enum V_279 V_280 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_78 = 1 ;
bool V_270 = true ;
int V_89 ;
if ( F_306 ( V_38 ) ) {
V_78 <<= F_318 ( V_38 ) ;
F_36 ( ! F_306 ( V_38 ) ) ;
V_270 = false ;
}
V_89 = F_227 ( V_110 , V_175 , V_78 , & V_4 , V_270 ) ;
if ( V_89 == - V_276 )
return V_89 ;
F_241 ( V_4 , V_38 , V_78 , V_280 , false ) ;
return 0 ;
}
int F_319 ( struct V_38 * V_38 ,
struct V_109 * V_110 , T_4 V_175 )
{
if ( F_94 () )
return 0 ;
F_36 ( F_307 ( V_38 ) ) ;
F_36 ( V_38 -> V_343 && ! F_305 ( V_38 ) ) ;
F_36 ( ! V_110 ) ;
return F_317 ( V_38 , V_110 , V_175 ,
V_284 ) ;
}
static int F_320 ( struct V_109 * V_110 ,
struct V_38 * V_38 ,
T_4 V_217 ,
struct V_1 * * V_344 )
{
struct V_1 * V_4 ;
struct V_132 * V_133 ;
int V_89 ;
V_133 = F_106 ( V_38 ) ;
if ( F_108 ( V_133 ) )
return 0 ;
if ( ! V_145 )
goto V_345;
V_4 = F_234 ( V_38 ) ;
if ( ! V_4 )
goto V_345;
* V_344 = V_4 ;
V_89 = F_227 ( NULL , V_217 , 1 , V_344 , true ) ;
F_96 ( & V_4 -> V_15 ) ;
if ( V_89 == - V_277 )
V_89 = 0 ;
return V_89 ;
V_345:
V_89 = F_227 ( V_110 , V_217 , 1 , V_344 , true ) ;
if ( V_89 == - V_277 )
V_89 = 0 ;
return V_89 ;
}
int F_321 ( struct V_109 * V_110 , struct V_38 * V_38 ,
T_4 V_175 , struct V_1 * * V_344 )
{
* V_344 = NULL ;
if ( F_94 () )
return 0 ;
if ( ! F_237 ( V_38 ) ) {
int V_89 ;
V_89 = F_227 ( V_110 , V_175 , 1 , V_344 , true ) ;
if ( V_89 == - V_277 )
V_89 = 0 ;
return V_89 ;
}
return F_320 ( V_110 , V_38 , V_175 , V_344 ) ;
}
void F_322 ( struct V_1 * V_4 )
{
if ( F_94 () )
return;
if ( ! V_4 )
return;
F_229 ( V_4 , 1 ) ;
}
static void
F_323 ( struct V_38 * V_38 , struct V_1 * V_4 ,
enum V_279 V_280 )
{
if ( F_94 () )
return;
if ( ! V_4 )
return;
F_241 ( V_4 , V_38 , 1 , V_280 , true ) ;
if ( V_145 && F_237 ( V_38 ) ) {
T_8 V_278 = { . V_67 = F_238 (page) } ;
F_324 ( V_278 ) ;
}
}
void F_325 ( struct V_38 * V_38 ,
struct V_1 * V_4 )
{
F_323 ( V_38 , V_4 ,
V_284 ) ;
}
int F_326 ( struct V_38 * V_38 , struct V_109 * V_110 ,
T_4 V_175 )
{
struct V_1 * V_4 = NULL ;
enum V_279 type = V_346 ;
int V_89 ;
if ( F_94 () )
return 0 ;
if ( F_327 ( V_38 ) )
return 0 ;
if ( ! F_237 ( V_38 ) )
V_89 = F_317 ( V_38 , V_110 , V_175 , type ) ;
else {
V_89 = F_320 ( V_110 , V_38 ,
V_175 , & V_4 ) ;
if ( ! V_89 )
F_323 ( V_38 , V_4 , type ) ;
}
return V_89 ;
}
static void F_328 ( struct V_1 * V_4 ,
unsigned int V_78 ,
const enum V_279 V_280 )
{
struct V_347 * V_271 = NULL ;
bool V_348 = true ;
if ( ! V_145 || V_280 == V_349 )
V_348 = false ;
V_271 = & V_24 -> V_350 ;
if ( ! V_271 -> V_4 )
V_271 -> V_4 = V_4 ;
if ( ! V_271 -> V_351 || F_193 ( V_181 ) )
goto V_352;
if ( V_78 > 1 )
goto V_352;
if ( V_271 -> V_4 != V_4 )
goto V_352;
V_271 -> V_78 ++ ;
if ( V_348 )
V_271 -> V_353 ++ ;
return;
V_352:
F_202 ( & V_4 -> V_58 , V_78 * V_238 ) ;
if ( V_348 )
F_202 ( & V_4 -> V_146 , V_78 * V_238 ) ;
if ( F_86 ( V_271 -> V_4 != V_4 ) )
F_189 ( V_4 ) ;
}
static struct V_1 *
F_329 ( struct V_38 * V_38 , enum V_279 V_280 ,
bool V_354 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_78 = 1 ;
struct V_132 * V_133 ;
bool V_77 ;
if ( F_94 () )
return NULL ;
F_36 ( F_237 ( V_38 ) ) ;
if ( F_306 ( V_38 ) ) {
V_78 <<= F_318 ( V_38 ) ;
F_36 ( ! F_306 ( V_38 ) ) ;
}
V_133 = F_106 ( V_38 ) ;
if ( F_86 ( ! F_108 ( V_133 ) ) )
return NULL ;
F_236 ( V_133 ) ;
V_4 = V_133 -> V_1 ;
if ( ! F_108 ( V_133 ) )
goto V_355;
V_77 = F_305 ( V_38 ) ;
switch ( V_280 ) {
case V_284 :
V_77 = true ;
case V_356 :
if ( F_307 ( V_38 ) )
goto V_355;
if ( ! V_354 && F_330 ( V_133 ) )
goto V_355;
break;
case V_349 :
if ( ! F_305 ( V_38 ) ) {
if ( V_38 -> V_343 && ! F_331 ( V_38 ) )
goto V_355;
} else if ( F_307 ( V_38 ) )
goto V_355;
break;
default:
break;
}
F_70 ( V_4 , V_77 , - V_78 ) ;
F_302 ( V_133 ) ;
F_240 ( V_133 ) ;
F_85 ( V_4 , V_38 ) ;
if ( V_145 && V_280 == V_349 ) {
F_67 ( V_4 , true ) ;
F_19 ( V_4 ) ;
}
if ( ! V_354 && ! F_16 ( V_4 ) )
F_328 ( V_4 , V_78 , V_280 ) ;
return V_4 ;
V_355:
F_240 ( V_133 ) ;
return NULL ;
}
void F_332 ( struct V_38 * V_38 )
{
if ( F_307 ( V_38 ) )
return;
F_36 ( V_38 -> V_343 && ! F_305 ( V_38 ) ) ;
if ( F_237 ( V_38 ) )
return;
F_329 ( V_38 , V_284 , false ) ;
}
void F_333 ( struct V_38 * V_38 )
{
F_36 ( F_307 ( V_38 ) ) ;
F_36 ( V_38 -> V_343 ) ;
F_329 ( V_38 , V_346 , false ) ;
}
void F_334 ( void )
{
V_24 -> V_350 . V_351 ++ ;
if ( V_24 -> V_350 . V_351 == 1 ) {
V_24 -> V_350 . V_4 = NULL ;
V_24 -> V_350 . V_78 = 0 ;
V_24 -> V_350 . V_353 = 0 ;
}
}
void F_335 ( void )
{
struct V_347 * V_271 = & V_24 -> V_350 ;
if ( ! V_271 -> V_351 )
return;
V_271 -> V_351 -- ;
if ( V_271 -> V_351 )
return;
if ( ! V_271 -> V_4 )
return;
if ( V_271 -> V_78 )
F_202 ( & V_271 -> V_4 -> V_58 ,
V_271 -> V_78 * V_238 ) ;
if ( V_271 -> V_353 )
F_202 ( & V_271 -> V_4 -> V_146 ,
V_271 -> V_353 * V_238 ) ;
F_189 ( V_271 -> V_4 ) ;
V_271 -> V_4 = NULL ;
}
void
F_336 ( struct V_38 * V_38 , T_8 V_278 , bool V_357 )
{
struct V_1 * V_4 ;
int V_280 = V_349 ;
if ( ! V_357 )
V_280 = V_356 ;
V_4 = F_329 ( V_38 , V_280 , false ) ;
if ( V_145 && V_357 && V_4 )
F_337 ( V_278 , F_95 ( & V_4 -> V_15 ) ) ;
}
void F_324 ( T_8 V_278 )
{
struct V_1 * V_4 ;
unsigned short V_116 ;
if ( ! V_145 )
return;
V_116 = F_337 ( V_278 , 0 ) ;
F_20 () ;
V_4 = F_232 ( V_116 ) ;
if ( V_4 ) {
if ( ! F_16 ( V_4 ) )
F_202 ( & V_4 -> V_146 , V_238 ) ;
F_67 ( V_4 , false ) ;
F_26 ( V_4 ) ;
}
F_23 () ;
}
static int F_338 ( T_8 V_358 ,
struct V_1 * V_152 , struct V_1 * V_153 )
{
unsigned short V_359 , V_360 ;
V_359 = F_95 ( & V_152 -> V_15 ) ;
V_360 = F_95 ( & V_153 -> V_15 ) ;
if ( F_339 ( V_358 , V_359 , V_360 ) == V_359 ) {
F_67 ( V_152 , false ) ;
F_67 ( V_153 , true ) ;
F_19 ( V_153 ) ;
return 0 ;
}
return - V_340 ;
}
static inline int F_338 ( T_8 V_358 ,
struct V_1 * V_152 , struct V_1 * V_153 )
{
return - V_340 ;
}
void F_340 ( struct V_38 * V_38 , struct V_38 * V_361 ,
struct V_1 * * V_344 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_78 = 1 ;
struct V_132 * V_133 ;
enum V_279 V_280 ;
* V_344 = NULL ;
if ( F_94 () )
return;
if ( F_306 ( V_38 ) )
V_78 <<= F_318 ( V_38 ) ;
V_133 = F_106 ( V_38 ) ;
F_236 ( V_133 ) ;
if ( F_108 ( V_133 ) ) {
V_4 = V_133 -> V_1 ;
F_117 ( & V_4 -> V_15 ) ;
if ( F_305 ( V_38 ) )
F_341 ( V_133 ) ;
}
F_240 ( V_133 ) ;
if ( ! V_4 )
return;
* V_344 = V_4 ;
if ( F_305 ( V_38 ) )
V_280 = V_284 ;
else
V_280 = V_346 ;
F_241 ( V_4 , V_361 , V_78 , V_280 , false ) ;
}
void F_342 ( struct V_1 * V_4 ,
struct V_38 * V_362 , struct V_38 * V_361 , bool V_363 )
{
struct V_38 * V_364 , * V_365 ;
struct V_132 * V_133 ;
bool V_77 ;
if ( ! V_4 )
return;
if ( ! V_363 ) {
V_364 = V_362 ;
V_365 = V_361 ;
} else {
V_364 = V_361 ;
V_365 = V_362 ;
}
V_77 = F_305 ( V_364 ) ;
F_329 ( V_365 ,
V_77 ? V_284
: V_346 ,
true ) ;
F_96 ( & V_4 -> V_15 ) ;
V_133 = F_106 ( V_362 ) ;
F_236 ( V_133 ) ;
F_343 ( V_133 ) ;
F_240 ( V_133 ) ;
if ( V_77 )
F_332 ( V_364 ) ;
}
void F_344 ( struct V_38 * V_362 ,
struct V_38 * V_361 )
{
struct V_1 * V_4 = NULL ;
struct V_132 * V_133 ;
enum V_279 type = V_346 ;
if ( F_94 () )
return;
V_133 = F_106 ( V_362 ) ;
F_236 ( V_133 ) ;
if ( F_108 ( V_133 ) ) {
V_4 = V_133 -> V_1 ;
F_70 ( V_4 , false , - 1 ) ;
F_302 ( V_133 ) ;
}
F_240 ( V_133 ) ;
if ( ! V_4 )
return;
F_241 ( V_4 , V_361 , 1 , type , true ) ;
}
static struct V_132 * F_345 ( struct V_38 * V_38 )
{
struct V_132 * V_133 ;
V_133 = F_106 ( V_38 ) ;
if ( F_224 ( V_133 ) && F_108 ( V_133 ) )
return V_133 ;
return NULL ;
}
bool F_346 ( struct V_38 * V_38 )
{
if ( F_94 () )
return false ;
return F_345 ( V_38 ) != NULL ;
}
void F_347 ( struct V_38 * V_38 )
{
struct V_132 * V_133 ;
V_133 = F_345 ( V_38 ) ;
if ( V_133 ) {
F_348 ( L_14 ,
V_133 , V_133 -> V_159 , V_133 -> V_1 ) ;
}
}
static int F_349 ( struct V_1 * V_4 ,
unsigned long long V_67 )
{
int V_366 ;
T_2 V_367 , V_368 ;
int V_89 = 0 ;
int V_369 = F_148 ( V_4 ) ;
T_2 V_370 , V_371 ;
int V_372 ;
V_366 = V_273 * V_369 ;
V_371 = F_33 ( & V_4 -> V_58 , V_31 ) ;
V_372 = 0 ;
while ( V_366 ) {
if ( F_350 ( V_24 ) ) {
V_89 = - V_277 ;
break;
}
F_218 ( & V_331 ) ;
V_367 = F_33 ( & V_4 -> V_146 , V_166 ) ;
if ( V_367 < V_67 ) {
V_89 = - V_340 ;
F_216 ( & V_331 ) ;
break;
}
V_368 = F_33 ( & V_4 -> V_58 , V_166 ) ;
if ( V_368 < V_67 )
V_372 = 1 ;
V_89 = F_351 ( & V_4 -> V_58 , V_67 ) ;
if ( ! V_89 ) {
if ( V_367 == V_67 )
V_4 -> V_194 = true ;
else
V_4 -> V_194 = false ;
}
F_216 ( & V_331 ) ;
if ( ! V_89 )
break;
F_162 ( V_4 , V_308 ,
V_193 ) ;
V_370 = F_33 ( & V_4 -> V_58 , V_31 ) ;
if ( V_370 >= V_371 )
V_366 -- ;
else
V_371 = V_370 ;
}
if ( ! V_89 && V_372 )
F_189 ( V_4 ) ;
return V_89 ;
}
static int F_352 ( struct V_1 * V_4 ,
unsigned long long V_67 )
{
int V_366 ;
T_2 V_368 , V_367 , V_371 , V_370 ;
int V_369 = F_148 ( V_4 ) ;
int V_89 = - V_339 ;
int V_372 = 0 ;
V_366 = V_369 * V_273 ;
V_371 = F_33 ( & V_4 -> V_146 , V_31 ) ;
while ( V_366 ) {
if ( F_350 ( V_24 ) ) {
V_89 = - V_277 ;
break;
}
F_218 ( & V_331 ) ;
V_368 = F_33 ( & V_4 -> V_58 , V_166 ) ;
if ( V_368 > V_67 ) {
V_89 = - V_340 ;
F_216 ( & V_331 ) ;
break;
}
V_367 = F_33 ( & V_4 -> V_146 , V_166 ) ;
if ( V_367 < V_67 )
V_372 = 1 ;
V_89 = F_351 ( & V_4 -> V_146 , V_67 ) ;
if ( ! V_89 ) {
if ( V_368 == V_67 )
V_4 -> V_194 = true ;
else
V_4 -> V_194 = false ;
}
F_216 ( & V_331 ) ;
if ( ! V_89 )
break;
F_162 ( V_4 , V_308 ,
V_192 |
V_193 ) ;
V_370 = F_33 ( & V_4 -> V_146 , V_31 ) ;
if ( V_370 >= V_371 )
V_366 -- ;
else
V_371 = V_370 ;
}
if ( ! V_89 && V_372 )
F_189 ( V_4 ) ;
return V_89 ;
}
unsigned long F_353 ( struct V_60 * V_60 , int V_176 ,
T_4 V_175 ,
unsigned long * V_203 )
{
unsigned long V_373 = 0 ;
struct V_32 * V_43 , * V_374 = NULL ;
unsigned long V_375 ;
int V_191 = 0 ;
struct V_39 * V_44 ;
unsigned long long V_57 ;
unsigned long V_205 ;
if ( V_176 > 0 )
return 0 ;
V_44 = F_41 ( F_97 ( V_60 ) , F_98 ( V_60 ) ) ;
do {
if ( V_374 )
V_43 = V_374 ;
else
V_43 = F_60 ( V_44 ) ;
if ( ! V_43 )
break;
V_205 = 0 ;
V_375 = F_178 ( V_43 -> V_4 , V_60 ,
V_175 , & V_205 ) ;
V_373 += V_375 ;
* V_203 += V_205 ;
F_50 ( & V_44 -> V_56 ) ;
V_374 = NULL ;
if ( ! V_375 ) {
do {
V_374 =
F_57 ( V_44 ) ;
if ( V_374 == V_43 )
F_96 ( & V_374 -> V_4 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_47 ( V_43 -> V_4 , V_43 , V_44 ) ;
V_57 = F_54 ( & V_43 -> V_4 -> V_58 ) ;
F_43 ( V_43 -> V_4 , V_43 , V_44 , V_57 ) ;
F_51 ( & V_44 -> V_56 ) ;
F_96 ( & V_43 -> V_4 -> V_15 ) ;
V_191 ++ ;
if ( ! V_373 &&
( V_374 == NULL ||
V_191 > V_376 ) )
break;
} while ( ! V_373 );
if ( V_374 )
F_96 ( & V_374 -> V_4 -> V_15 ) ;
return V_373 ;
}
static void F_354 ( struct V_1 * V_4 ,
int V_59 , int V_34 , enum V_85 V_86 )
{
struct V_84 * V_84 ;
unsigned long V_159 ;
struct V_377 * V_305 ;
struct V_38 * V_378 ;
struct V_60 * V_60 ;
V_60 = & F_355 ( V_59 ) -> V_379 [ V_34 ] ;
V_84 = F_104 ( V_60 , V_4 ) ;
V_305 = & V_84 -> V_380 [ V_86 ] ;
V_378 = NULL ;
do {
struct V_132 * V_133 ;
struct V_38 * V_38 ;
F_138 ( & V_60 -> V_283 , V_159 ) ;
if ( F_356 ( V_305 ) ) {
F_140 ( & V_60 -> V_283 , V_159 ) ;
break;
}
V_38 = F_357 ( V_305 -> V_113 , struct V_38 , V_86 ) ;
if ( V_378 == V_38 ) {
F_358 ( & V_38 -> V_86 , V_305 ) ;
V_378 = NULL ;
F_140 ( & V_60 -> V_283 , V_159 ) ;
continue;
}
F_140 ( & V_60 -> V_283 , V_159 ) ;
V_133 = F_106 ( V_38 ) ;
if ( F_309 ( V_38 , V_133 , V_4 ) ) {
V_378 = V_38 ;
F_359 () ;
} else
V_378 = NULL ;
} while ( ! F_356 ( V_305 ) );
}
static void F_360 ( struct V_1 * V_4 )
{
int V_59 , V_34 ;
T_2 V_381 ;
do {
F_361 () ;
F_217 ( V_4 ) ;
F_124 ( V_4 ) ;
F_81 (node, N_MEMORY) {
for ( V_34 = 0 ; V_34 < V_61 ; V_34 ++ ) {
enum V_85 V_86 ;
F_77 (lru) {
F_354 ( V_4 ,
V_59 , V_34 , V_86 ) ;
}
}
}
F_126 ( V_4 ) ;
F_189 ( V_4 ) ;
F_359 () ;
V_381 = F_33 ( & V_4 -> V_58 , V_31 ) -
F_33 ( & V_4 -> V_30 , V_31 ) ;
} while ( V_381 > 0 );
}
static inline bool F_362 ( struct V_1 * V_4 )
{
struct V_105 * V_382 ;
F_363 (pos, memcg->css.cgroup)
return true ;
return false ;
}
static inline bool F_364 ( struct V_1 * V_4 )
{
return V_4 -> V_117 && F_362 ( V_4 ) ;
}
static int F_365 ( struct V_1 * V_4 )
{
int V_383 = V_273 ;
struct V_105 * V_147 = V_4 -> V_15 . V_105 ;
if ( F_366 ( V_147 ) || ! F_356 ( & V_147 -> V_369 ) )
return - V_339 ;
F_361 () ;
while ( V_383 && F_33 ( & V_4 -> V_58 , V_31 ) > 0 ) {
int V_384 ;
if ( F_350 ( V_24 ) )
return - V_277 ;
V_384 = F_164 ( V_4 , V_308 ,
false ) ;
if ( ! V_384 ) {
V_383 -- ;
F_367 ( V_385 , V_386 / 10 ) ;
}
}
F_368 () ;
F_360 ( V_4 ) ;
return 0 ;
}
static int F_369 ( struct V_105 * V_106 , unsigned int V_387 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
int V_89 ;
if ( F_16 ( V_4 ) )
return - V_340 ;
F_117 ( & V_4 -> V_15 ) ;
V_89 = F_365 ( V_4 ) ;
F_96 ( & V_4 -> V_15 ) ;
return V_89 ;
}
static T_2 F_370 ( struct V_105 * V_106 , struct V_293 * V_294 )
{
return F_89 ( V_106 ) -> V_117 ;
}
static int F_371 ( struct V_105 * V_106 , struct V_293 * V_294 ,
T_2 V_67 )
{
int V_388 = 0 ;
struct V_1 * V_4 = F_89 ( V_106 ) ;
struct V_105 * V_49 = V_106 -> V_49 ;
struct V_1 * V_389 = NULL ;
if ( V_49 )
V_389 = F_89 ( V_49 ) ;
F_218 ( & V_390 ) ;
if ( V_4 -> V_117 == V_67 )
goto V_127;
if ( ( ! V_389 || ! V_389 -> V_117 ) &&
( V_67 == 1 || V_67 == 0 ) ) {
if ( ! F_362 ( V_4 ) )
V_4 -> V_117 = V_67 ;
else
V_388 = - V_339 ;
} else
V_388 = - V_340 ;
V_127:
F_216 ( & V_390 ) ;
return V_388 ;
}
static unsigned long F_372 ( struct V_1 * V_4 ,
enum V_65 V_66 )
{
struct V_1 * V_120 ;
long V_67 = 0 ;
F_146 (iter, memcg)
V_67 += F_61 ( V_120 , V_66 ) ;
if ( V_67 < 0 )
V_67 = 0 ;
return V_67 ;
}
static inline T_2 F_373 ( struct V_1 * V_4 , bool V_391 )
{
T_2 V_67 ;
if ( ! F_16 ( V_4 ) ) {
if ( ! V_391 )
return F_33 ( & V_4 -> V_58 , V_31 ) ;
else
return F_33 ( & V_4 -> V_146 , V_31 ) ;
}
V_67 = F_372 ( V_4 , V_80 ) ;
V_67 += F_372 ( V_4 , V_79 ) ;
if ( V_391 )
V_67 += F_372 ( V_4 , V_74 ) ;
return V_67 << V_143 ;
}
static T_9 F_374 ( struct V_105 * V_106 , struct V_293 * V_294 ,
struct V_392 * V_392 , char T_10 * V_393 ,
T_1 V_394 , T_11 * V_395 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
char V_396 [ 64 ] ;
T_2 V_67 ;
int V_318 , V_397 ;
enum V_398 type ;
type = F_375 ( V_294 -> V_222 ) ;
V_318 = F_376 ( V_294 -> V_222 ) ;
if ( ! V_145 && type == V_399 )
return - V_400 ;
switch ( type ) {
case V_401 :
if ( V_318 == V_31 )
V_67 = F_373 ( V_4 , false ) ;
else
V_67 = F_33 ( & V_4 -> V_58 , V_318 ) ;
break;
case V_399 :
if ( V_318 == V_31 )
V_67 = F_373 ( V_4 , true ) ;
else
V_67 = F_33 ( & V_4 -> V_146 , V_318 ) ;
break;
case V_402 :
V_67 = F_33 ( & V_4 -> V_30 , V_318 ) ;
break;
default:
F_103 () ;
}
V_397 = F_377 ( V_396 , sizeof( V_396 ) , L_15 , ( unsigned long long ) V_67 ) ;
return F_378 ( V_393 , V_394 , V_395 , V_396 , V_397 ) ;
}
static int F_379 ( struct V_105 * V_106 , T_2 V_67 )
{
int V_89 = - V_340 ;
#ifdef F_380
struct V_1 * V_4 = F_89 ( V_106 ) ;
F_218 ( & V_390 ) ;
F_218 ( & V_331 ) ;
if ( ! V_4 -> V_6 && V_67 != V_403 ) {
if ( F_366 ( V_106 ) || F_364 ( V_4 ) ) {
V_89 = - V_339 ;
goto V_127;
}
V_89 = F_351 ( & V_4 -> V_30 , V_67 ) ;
F_36 ( V_89 ) ;
V_89 = F_264 ( V_4 ) ;
if ( V_89 ) {
F_351 ( & V_4 -> V_30 , V_403 ) ;
goto V_127;
}
F_381 ( & V_27 ) ;
F_2 ( V_4 ) ;
F_19 ( V_4 ) ;
} else
V_89 = F_351 ( & V_4 -> V_30 , V_67 ) ;
V_127:
F_216 ( & V_331 ) ;
F_216 ( & V_390 ) ;
#endif
return V_89 ;
}
static int F_382 ( struct V_1 * V_4 )
{
int V_89 = 0 ;
struct V_1 * V_49 = F_53 ( V_4 ) ;
if ( ! V_49 )
goto V_127;
V_4 -> V_6 = V_49 -> V_6 ;
if ( ! F_4 ( V_4 ) )
goto V_127;
F_19 ( V_4 ) ;
F_381 ( & V_27 ) ;
F_218 ( & V_331 ) ;
V_89 = F_264 ( V_4 ) ;
F_216 ( & V_331 ) ;
V_127:
return V_89 ;
}
static int F_383 ( struct V_105 * V_106 , struct V_293 * V_294 ,
const char * V_404 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
enum V_398 type ;
int V_318 ;
unsigned long long V_67 ;
int V_89 ;
type = F_375 ( V_294 -> V_222 ) ;
V_318 = F_376 ( V_294 -> V_222 ) ;
if ( ! V_145 && type == V_399 )
return - V_400 ;
switch ( V_318 ) {
case V_166 :
if ( F_16 ( V_4 ) ) {
V_89 = - V_340 ;
break;
}
V_89 = F_384 ( V_404 , & V_67 ) ;
if ( V_89 )
break;
if ( type == V_401 )
V_89 = F_349 ( V_4 , V_67 ) ;
else if ( type == V_399 )
V_89 = F_352 ( V_4 , V_67 ) ;
else if ( type == V_402 )
V_89 = F_379 ( V_106 , V_67 ) ;
else
return - V_340 ;
break;
case V_405 :
V_89 = F_384 ( V_404 , & V_67 ) ;
if ( V_89 )
break;
if ( type == V_401 )
V_89 = F_385 ( & V_4 -> V_58 , V_67 ) ;
else
V_89 = - V_340 ;
break;
default:
V_89 = - V_340 ;
break;
}
return V_89 ;
}
static void F_386 ( struct V_1 * V_4 ,
unsigned long long * V_406 , unsigned long long * V_407 )
{
struct V_105 * V_105 ;
unsigned long long V_408 , V_409 , V_410 ;
V_408 = F_33 ( & V_4 -> V_58 , V_166 ) ;
V_409 = F_33 ( & V_4 -> V_146 , V_166 ) ;
V_105 = V_4 -> V_15 . V_105 ;
if ( ! V_4 -> V_117 )
goto V_127;
while ( V_105 -> V_49 ) {
V_105 = V_105 -> V_49 ;
V_4 = F_89 ( V_105 ) ;
if ( ! V_4 -> V_117 )
break;
V_410 = F_33 ( & V_4 -> V_58 , V_166 ) ;
V_408 = F_122 ( V_408 , V_410 ) ;
V_410 = F_33 ( & V_4 -> V_146 , V_166 ) ;
V_409 = F_122 ( V_409 , V_410 ) ;
}
V_127:
* V_406 = V_408 ;
* V_407 = V_409 ;
}
static int F_387 ( struct V_105 * V_106 , unsigned int V_387 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
int V_318 ;
enum V_398 type ;
type = F_375 ( V_387 ) ;
V_318 = F_376 ( V_387 ) ;
if ( ! V_145 && type == V_399 )
return - V_400 ;
switch ( V_318 ) {
case V_411 :
if ( type == V_401 )
F_388 ( & V_4 -> V_58 ) ;
else if ( type == V_399 )
F_388 ( & V_4 -> V_146 ) ;
else if ( type == V_402 )
F_388 ( & V_4 -> V_30 ) ;
else
return - V_340 ;
break;
case V_167 :
if ( type == V_401 )
F_389 ( & V_4 -> V_58 ) ;
else if ( type == V_399 )
F_389 ( & V_4 -> V_146 ) ;
else if ( type == V_402 )
F_389 ( & V_4 -> V_30 ) ;
else
return - V_340 ;
break;
}
return 0 ;
}
static T_2 F_390 ( struct V_105 * V_147 ,
struct V_293 * V_294 )
{
return F_89 ( V_147 ) -> V_412 ;
}
static int F_391 ( struct V_105 * V_147 ,
struct V_293 * V_294 , T_2 V_67 )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
if ( V_67 >= ( 1 << V_413 ) )
return - V_340 ;
V_4 -> V_412 = V_67 ;
return 0 ;
}
static int F_391 ( struct V_105 * V_147 ,
struct V_293 * V_294 , T_2 V_67 )
{
return - V_414 ;
}
static int F_392 ( struct V_105 * V_106 , struct V_293 * V_294 ,
struct V_295 * V_296 )
{
int V_33 ;
unsigned long V_415 , V_416 , V_417 , V_418 ;
unsigned long V_419 ;
struct V_1 * V_4 = F_89 ( V_106 ) ;
V_415 = F_80 ( V_4 , V_420 ) ;
F_393 ( V_296 , L_16 , V_415 ) ;
F_81 (nid, N_MEMORY) {
V_419 = F_79 ( V_4 , V_33 , V_420 ) ;
F_393 ( V_296 , L_17 , V_33 , V_419 ) ;
}
F_394 ( V_296 , '\n' ) ;
V_416 = F_80 ( V_4 , V_196 ) ;
F_393 ( V_296 , L_18 , V_416 ) ;
F_81 (nid, N_MEMORY) {
V_419 = F_79 ( V_4 , V_33 ,
V_196 ) ;
F_393 ( V_296 , L_17 , V_33 , V_419 ) ;
}
F_394 ( V_296 , '\n' ) ;
V_417 = F_80 ( V_4 , V_197 ) ;
F_393 ( V_296 , L_19 , V_417 ) ;
F_81 (nid, N_MEMORY) {
V_419 = F_79 ( V_4 , V_33 ,
V_197 ) ;
F_393 ( V_296 , L_17 , V_33 , V_419 ) ;
}
F_394 ( V_296 , '\n' ) ;
V_418 = F_80 ( V_4 , F_78 ( V_421 ) ) ;
F_393 ( V_296 , L_20 , V_418 ) ;
F_81 (nid, N_MEMORY) {
V_419 = F_79 ( V_4 , V_33 ,
F_78 ( V_421 ) ) ;
F_393 ( V_296 , L_17 , V_33 , V_419 ) ;
}
F_394 ( V_296 , '\n' ) ;
return 0 ;
}
static inline void F_395 ( void )
{
F_396 ( F_397 ( V_171 ) != V_170 ) ;
}
static int F_398 ( struct V_105 * V_106 , struct V_293 * V_294 ,
struct V_295 * V_296 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
struct V_1 * V_422 ;
unsigned int V_165 ;
for ( V_165 = 0 ; V_165 < V_168 ; V_165 ++ ) {
if ( V_165 == V_74 && ! V_145 )
continue;
F_393 ( V_296 , L_21 , V_169 [ V_165 ] ,
F_61 ( V_4 , V_165 ) * V_238 ) ;
}
for ( V_165 = 0 ; V_165 < V_246 ; V_165 ++ )
F_393 ( V_296 , L_22 , V_423 [ V_165 ] ,
F_69 ( V_4 , V_165 ) ) ;
for ( V_165 = 0 ; V_165 < V_170 ; V_165 ++ )
F_393 ( V_296 , L_22 , V_171 [ V_165 ] ,
F_80 ( V_4 , F_78 ( V_165 ) ) * V_238 ) ;
{
unsigned long long V_173 , V_407 ;
F_386 ( V_4 , & V_173 , & V_407 ) ;
F_393 ( V_296 , L_23 , V_173 ) ;
if ( V_145 )
F_393 ( V_296 , L_24 ,
V_407 ) ;
}
for ( V_165 = 0 ; V_165 < V_168 ; V_165 ++ ) {
long long V_67 = 0 ;
if ( V_165 == V_74 && ! V_145 )
continue;
F_146 (mi, memcg)
V_67 += F_61 ( V_422 , V_165 ) * V_238 ;
F_393 ( V_296 , L_25 , V_169 [ V_165 ] , V_67 ) ;
}
for ( V_165 = 0 ; V_165 < V_246 ; V_165 ++ ) {
unsigned long long V_67 = 0 ;
F_146 (mi, memcg)
V_67 += F_69 ( V_422 , V_165 ) ;
F_393 ( V_296 , L_26 ,
V_423 [ V_165 ] , V_67 ) ;
}
for ( V_165 = 0 ; V_165 < V_170 ; V_165 ++ ) {
unsigned long long V_67 = 0 ;
F_146 (mi, memcg)
V_67 += F_80 ( V_422 , F_78 ( V_165 ) ) * V_238 ;
F_393 ( V_296 , L_26 , V_171 [ V_165 ] , V_67 ) ;
}
#ifdef F_399
{
int V_33 , V_34 ;
struct V_32 * V_43 ;
struct V_424 * V_425 ;
unsigned long V_426 [ 2 ] = { 0 , 0 } ;
unsigned long V_427 [ 2 ] = { 0 , 0 } ;
F_400 (nid)
for ( V_34 = 0 ; V_34 < V_61 ; V_34 ++ ) {
V_43 = F_35 ( V_4 , V_33 , V_34 ) ;
V_425 = & V_43 -> V_84 . V_428 ;
V_426 [ 0 ] += V_425 -> V_426 [ 0 ] ;
V_426 [ 1 ] += V_425 -> V_426 [ 1 ] ;
V_427 [ 0 ] += V_425 -> V_427 [ 0 ] ;
V_427 [ 1 ] += V_425 -> V_427 [ 1 ] ;
}
F_393 ( V_296 , L_27 , V_426 [ 0 ] ) ;
F_393 ( V_296 , L_28 , V_426 [ 1 ] ) ;
F_393 ( V_296 , L_29 , V_427 [ 0 ] ) ;
F_393 ( V_296 , L_30 , V_427 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_401 ( struct V_105 * V_147 , struct V_293 * V_294 )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
return F_123 ( V_4 ) ;
}
static int F_402 ( struct V_105 * V_147 , struct V_293 * V_294 ,
T_2 V_67 )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
struct V_1 * V_49 ;
if ( V_67 > 100 )
return - V_340 ;
if ( V_147 -> V_49 == NULL )
return - V_340 ;
V_49 = F_89 ( V_147 -> V_49 ) ;
F_218 ( & V_390 ) ;
if ( ( V_49 -> V_117 ) || F_364 ( V_4 ) ) {
F_216 ( & V_390 ) ;
return - V_340 ;
}
V_4 -> V_149 = V_67 ;
F_216 ( & V_390 ) ;
return 0 ;
}
static void F_403 ( struct V_1 * V_4 , bool V_391 )
{
struct V_429 * V_430 ;
T_2 V_381 ;
int V_165 ;
F_20 () ;
if ( ! V_391 )
V_430 = F_92 ( V_4 -> V_431 . V_432 ) ;
else
V_430 = F_92 ( V_4 -> V_433 . V_432 ) ;
if ( ! V_430 )
goto V_154;
V_381 = F_373 ( V_4 , V_391 ) ;
V_165 = V_430 -> V_434 ;
for (; V_165 >= 0 && F_86 ( V_430 -> V_435 [ V_165 ] . V_436 > V_381 ) ; V_165 -- )
F_404 ( V_430 -> V_435 [ V_165 ] . V_437 , 1 ) ;
V_165 ++ ;
for (; V_165 < V_430 -> V_301 && F_86 ( V_430 -> V_435 [ V_165 ] . V_436 <= V_381 ) ; V_165 ++ )
F_404 ( V_430 -> V_435 [ V_165 ] . V_437 , 1 ) ;
V_430 -> V_434 = V_165 - 1 ;
V_154:
F_23 () ;
}
static void F_87 ( struct V_1 * V_4 )
{
while ( V_4 ) {
F_403 ( V_4 , false ) ;
if ( V_145 )
F_403 ( V_4 , true ) ;
V_4 = F_53 ( V_4 ) ;
}
}
static int F_405 ( const void * V_438 , const void * V_439 )
{
const struct F_87 * V_440 = V_438 ;
const struct F_87 * V_441 = V_439 ;
return V_440 -> V_436 - V_441 -> V_436 ;
}
static int F_406 ( struct V_1 * V_4 )
{
struct V_442 * V_443 ;
F_257 (ev, &memcg->oom_notify, list)
F_404 ( V_443 -> V_437 , 1 ) ;
return 0 ;
}
static void F_192 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_146 (iter, memcg)
F_406 ( V_120 ) ;
}
static int F_407 ( struct V_105 * V_147 ,
struct V_293 * V_294 , struct V_444 * V_437 , const char * args )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
struct V_445 * V_431 ;
struct V_429 * V_321 ;
enum V_398 type = F_375 ( V_294 -> V_222 ) ;
T_2 V_436 , V_381 ;
int V_165 , V_301 , V_89 ;
V_89 = F_384 ( args , & V_436 ) ;
if ( V_89 )
return V_89 ;
F_218 ( & V_4 -> V_446 ) ;
if ( type == V_401 )
V_431 = & V_4 -> V_431 ;
else if ( type == V_399 )
V_431 = & V_4 -> V_433 ;
else
F_103 () ;
V_381 = F_373 ( V_4 , type == V_399 ) ;
if ( V_431 -> V_432 )
F_403 ( V_4 , type == V_399 ) ;
V_301 = V_431 -> V_432 ? V_431 -> V_432 -> V_301 + 1 : 1 ;
V_321 = F_295 ( sizeof( * V_321 ) + V_301 * sizeof( struct F_87 ) ,
V_308 ) ;
if ( ! V_321 ) {
V_89 = - V_276 ;
goto V_154;
}
V_321 -> V_301 = V_301 ;
if ( V_431 -> V_432 ) {
memcpy ( V_321 -> V_435 , V_431 -> V_432 -> V_435 , ( V_301 - 1 ) *
sizeof( struct F_87 ) ) ;
}
V_321 -> V_435 [ V_301 - 1 ] . V_437 = V_437 ;
V_321 -> V_435 [ V_301 - 1 ] . V_436 = V_436 ;
F_408 ( V_321 -> V_435 , V_301 , sizeof( struct F_87 ) ,
F_405 , NULL ) ;
V_321 -> V_434 = - 1 ;
for ( V_165 = 0 ; V_165 < V_301 ; V_165 ++ ) {
if ( V_321 -> V_435 [ V_165 ] . V_436 <= V_381 ) {
++ V_321 -> V_434 ;
} else
break;
}
F_272 ( V_431 -> V_447 ) ;
V_431 -> V_447 = V_431 -> V_432 ;
F_409 ( V_431 -> V_432 , V_321 ) ;
F_125 () ;
V_154:
F_216 ( & V_4 -> V_446 ) ;
return V_89 ;
}
static void F_410 ( struct V_105 * V_147 ,
struct V_293 * V_294 , struct V_444 * V_437 )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
struct V_445 * V_431 ;
struct V_429 * V_321 ;
enum V_398 type = F_375 ( V_294 -> V_222 ) ;
T_2 V_381 ;
int V_165 , V_448 , V_301 ;
F_218 ( & V_4 -> V_446 ) ;
if ( type == V_401 )
V_431 = & V_4 -> V_431 ;
else if ( type == V_399 )
V_431 = & V_4 -> V_433 ;
else
F_103 () ;
if ( ! V_431 -> V_432 )
goto V_154;
V_381 = F_373 ( V_4 , type == V_399 ) ;
F_403 ( V_4 , type == V_399 ) ;
V_301 = 0 ;
for ( V_165 = 0 ; V_165 < V_431 -> V_432 -> V_301 ; V_165 ++ ) {
if ( V_431 -> V_432 -> V_435 [ V_165 ] . V_437 != V_437 )
V_301 ++ ;
}
V_321 = V_431 -> V_447 ;
if ( ! V_301 ) {
F_272 ( V_321 ) ;
V_321 = NULL ;
goto V_449;
}
V_321 -> V_301 = V_301 ;
V_321 -> V_434 = - 1 ;
for ( V_165 = 0 , V_448 = 0 ; V_165 < V_431 -> V_432 -> V_301 ; V_165 ++ ) {
if ( V_431 -> V_432 -> V_435 [ V_165 ] . V_437 == V_437 )
continue;
V_321 -> V_435 [ V_448 ] = V_431 -> V_432 -> V_435 [ V_165 ] ;
if ( V_321 -> V_435 [ V_448 ] . V_436 <= V_381 ) {
++ V_321 -> V_434 ;
}
V_448 ++ ;
}
V_449:
V_431 -> V_447 = V_431 -> V_432 ;
if ( ! V_321 ) {
F_272 ( V_431 -> V_447 ) ;
V_431 -> V_447 = NULL ;
}
F_409 ( V_431 -> V_432 , V_321 ) ;
F_125 () ;
V_154:
F_216 ( & V_4 -> V_446 ) ;
}
static int F_411 ( struct V_105 * V_147 ,
struct V_293 * V_294 , struct V_444 * V_437 , const char * args )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
struct V_442 * V_387 ;
enum V_398 type = F_375 ( V_294 -> V_222 ) ;
F_18 ( type != V_450 ) ;
V_387 = F_295 ( sizeof( * V_387 ) , V_308 ) ;
if ( ! V_387 )
return - V_276 ;
F_50 ( & V_224 ) ;
V_387 -> V_437 = V_437 ;
F_263 ( & V_387 -> V_305 , & V_4 -> V_451 ) ;
if ( F_130 ( & V_4 -> V_208 ) )
F_404 ( V_437 , 1 ) ;
F_51 ( & V_224 ) ;
return 0 ;
}
static void F_412 ( struct V_105 * V_147 ,
struct V_293 * V_294 , struct V_444 * V_437 )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
struct V_442 * V_443 , * V_410 ;
enum V_398 type = F_375 ( V_294 -> V_222 ) ;
F_18 ( type != V_450 ) ;
F_50 ( & V_224 ) ;
F_413 (ev, tmp, &memcg->oom_notify, list) {
if ( V_443 -> V_437 == V_437 ) {
F_276 ( & V_443 -> V_305 ) ;
F_272 ( V_443 ) ;
}
}
F_51 ( & V_224 ) ;
}
static int F_414 ( struct V_105 * V_147 ,
struct V_293 * V_294 , struct V_452 * V_453 )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
V_453 -> V_454 ( V_453 , L_31 , V_4 -> V_226 ) ;
if ( F_130 ( & V_4 -> V_208 ) )
V_453 -> V_454 ( V_453 , L_32 , 1 ) ;
else
V_453 -> V_454 ( V_453 , L_32 , 0 ) ;
return 0 ;
}
static int F_415 ( struct V_105 * V_147 ,
struct V_293 * V_294 , T_2 V_67 )
{
struct V_1 * V_4 = F_89 ( V_147 ) ;
struct V_1 * V_49 ;
if ( ! V_147 -> V_49 || ! ( ( V_67 == 0 ) || ( V_67 == 1 ) ) )
return - V_340 ;
V_49 = F_89 ( V_147 -> V_49 ) ;
F_218 ( & V_390 ) ;
if ( ( V_49 -> V_117 ) || F_364 ( V_4 ) ) {
F_216 ( & V_390 ) ;
return - V_340 ;
}
V_4 -> V_226 = V_67 ;
if ( ! V_67 )
F_189 ( V_4 ) ;
F_216 ( & V_390 ) ;
return 0 ;
}
static int F_416 ( struct V_1 * V_4 , struct V_455 * V_456 )
{
int V_89 ;
V_4 -> V_29 = - 1 ;
V_89 = F_382 ( V_4 ) ;
if ( V_89 )
return V_89 ;
return F_417 ( V_4 , V_456 ) ;
}
static void F_418 ( struct V_1 * V_4 )
{
F_419 ( V_4 ) ;
F_9 ( V_4 ) ;
if ( F_33 ( & V_4 -> V_30 , V_31 ) != 0 )
return;
if ( F_10 ( V_4 ) )
F_26 ( V_4 ) ;
}
static int F_416 ( struct V_1 * V_4 , struct V_455 * V_456 )
{
return 0 ;
}
static void F_418 ( struct V_1 * V_4 )
{
}
static int F_420 ( struct V_1 * V_4 , int V_59 )
{
struct V_3 * V_457 ;
struct V_32 * V_43 ;
int V_60 , V_410 = V_59 ;
if ( ! F_421 ( V_59 , V_458 ) )
V_410 = - 1 ;
V_457 = F_422 ( sizeof( * V_457 ) , V_308 , V_410 ) ;
if ( ! V_457 )
return 1 ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
V_43 = & V_457 -> V_37 [ V_60 ] ;
F_423 ( & V_43 -> V_84 ) ;
V_43 -> V_52 = 0 ;
V_43 -> V_51 = false ;
V_43 -> V_4 = V_4 ;
}
V_4 -> V_35 . V_36 [ V_59 ] = V_457 ;
return 0 ;
}
static void F_424 ( struct V_1 * V_4 , int V_59 )
{
F_272 ( V_4 -> V_35 . V_36 [ V_59 ] ) ;
}
static struct V_1 * F_425 ( void )
{
struct V_1 * V_4 ;
T_1 V_301 = F_1 () ;
if ( V_301 < V_238 )
V_4 = F_271 ( V_301 , V_308 ) ;
else
V_4 = F_426 ( V_301 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_69 = F_427 ( struct V_459 ) ;
if ( ! V_4 -> V_69 )
goto V_460;
F_428 ( & V_4 -> V_71 ) ;
return V_4 ;
V_460:
if ( V_301 < V_238 )
F_272 ( V_4 ) ;
else
F_429 ( V_4 ) ;
return NULL ;
}
static void F_430 ( struct V_1 * V_4 )
{
int V_59 ;
T_1 V_301 = F_1 () ;
F_55 ( V_4 ) ;
F_431 ( & V_125 , & V_4 -> V_15 ) ;
F_56 (node)
F_424 ( V_4 , V_59 ) ;
F_432 ( V_4 -> V_69 ) ;
F_34 ( V_4 ) ;
if ( V_301 < V_238 )
F_272 ( V_4 ) ;
else
F_429 ( V_4 ) ;
}
static void F_433 ( struct V_239 * V_242 )
{
struct V_1 * V_4 ;
V_4 = F_15 ( V_242 , struct V_1 , V_461 ) ;
F_430 ( V_4 ) ;
}
static void F_434 ( struct V_462 * V_462 )
{
struct V_1 * V_4 ;
V_4 = F_15 ( V_462 , struct V_1 , V_463 ) ;
F_207 ( & V_4 -> V_461 , F_433 ) ;
F_283 ( & V_4 -> V_461 ) ;
}
static void F_19 ( struct V_1 * V_4 )
{
F_88 ( & V_4 -> V_464 ) ;
}
static void F_435 ( struct V_1 * V_4 , int V_70 )
{
if ( F_436 ( V_70 , & V_4 -> V_464 ) ) {
struct V_1 * V_49 = F_53 ( V_4 ) ;
F_437 ( & V_4 -> V_463 , F_434 ) ;
if ( V_49 )
F_26 ( V_49 ) ;
}
}
static void F_26 ( struct V_1 * V_4 )
{
F_435 ( V_4 , 1 ) ;
}
struct V_1 * F_53 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_58 . V_49 )
return NULL ;
return F_225 ( V_4 -> V_58 . V_49 , V_58 ) ;
}
static void T_6 F_438 ( void )
{
struct V_465 * V_466 ;
struct V_39 * V_467 ;
int V_410 , V_59 , V_60 ;
F_56 (node) {
V_410 = V_59 ;
if ( ! F_421 ( V_59 , V_458 ) )
V_410 = - 1 ;
V_466 = F_422 ( sizeof( * V_466 ) , V_308 , V_410 ) ;
F_18 ( ! V_466 ) ;
V_40 . V_41 [ V_59 ] = V_466 ;
for ( V_60 = 0 ; V_60 < V_61 ; V_60 ++ ) {
V_467 = & V_466 -> V_42 [ V_60 ] ;
V_467 -> V_48 = V_468 ;
F_428 ( & V_467 -> V_56 ) ;
}
}
}
static struct V_13 * T_12
F_439 ( struct V_105 * V_106 )
{
struct V_1 * V_4 ;
long error = - V_276 ;
int V_59 ;
V_4 = F_425 () ;
if ( ! V_4 )
return F_440 ( error ) ;
F_56 (node)
if ( F_420 ( V_4 , V_59 ) )
goto V_469;
if ( V_106 -> V_49 == NULL ) {
V_16 = V_4 ;
F_441 ( & V_4 -> V_58 , NULL ) ;
F_441 ( & V_4 -> V_146 , NULL ) ;
F_441 ( & V_4 -> V_30 , NULL ) ;
}
V_4 -> V_202 = V_103 ;
F_191 ( & V_4 -> V_451 ) ;
F_170 ( & V_4 -> V_464 , 1 ) ;
V_4 -> V_412 = 0 ;
F_267 ( & V_4 -> V_446 ) ;
F_428 ( & V_4 -> V_160 ) ;
return & V_4 -> V_15 ;
V_469:
F_430 ( V_4 ) ;
return F_440 ( error ) ;
}
static int
F_442 ( struct V_105 * V_106 )
{
struct V_1 * V_4 , * V_49 ;
int error = 0 ;
if ( ! V_106 -> V_49 )
return 0 ;
F_218 ( & V_390 ) ;
V_4 = F_89 ( V_106 ) ;
V_49 = F_89 ( V_106 -> V_49 ) ;
V_4 -> V_117 = V_49 -> V_117 ;
V_4 -> V_226 = V_49 -> V_226 ;
V_4 -> V_149 = F_123 ( V_49 ) ;
if ( V_49 -> V_117 ) {
F_441 ( & V_4 -> V_58 , & V_49 -> V_58 ) ;
F_441 ( & V_4 -> V_146 , & V_49 -> V_146 ) ;
F_441 ( & V_4 -> V_30 , & V_49 -> V_30 ) ;
F_19 ( V_49 ) ;
} else {
F_441 ( & V_4 -> V_58 , NULL ) ;
F_441 ( & V_4 -> V_146 , NULL ) ;
F_441 ( & V_4 -> V_30 , NULL ) ;
if ( V_49 != V_16 )
V_125 . V_470 = true ;
}
error = F_416 ( V_4 , & V_125 ) ;
F_216 ( & V_390 ) ;
if ( error ) {
F_26 ( V_4 ) ;
if ( V_49 -> V_117 )
F_26 ( V_49 ) ;
}
return error ;
}
static void F_443 ( struct V_105 * V_106 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
F_360 ( V_4 ) ;
F_292 ( V_4 ) ;
}
static void F_444 ( struct V_105 * V_106 )
{
struct V_1 * V_4 = F_89 ( V_106 ) ;
F_418 ( V_4 ) ;
F_26 ( V_4 ) ;
}
static int F_445 ( unsigned long V_70 )
{
int V_89 = 0 ;
int V_471 = V_472 ;
struct V_1 * V_4 = V_10 . V_153 ;
if ( F_16 ( V_4 ) ) {
V_10 . V_473 += V_70 ;
return V_89 ;
}
if ( V_70 > 1 ) {
struct V_259 * V_240 ;
if ( F_223 ( & V_4 -> V_58 , V_238 * V_70 , & V_240 ) )
goto V_474;
if ( V_145 && F_223 ( & V_4 -> V_146 ,
V_238 * V_70 , & V_240 ) ) {
F_202 ( & V_4 -> V_58 , V_238 * V_70 ) ;
goto V_474;
}
V_10 . V_473 += V_70 ;
return V_89 ;
}
V_474:
while ( V_70 -- ) {
if ( F_350 ( V_24 ) ) {
V_89 = - V_277 ;
break;
}
if ( ! V_471 -- ) {
V_471 = V_472 ;
F_359 () ;
}
V_89 = F_227 ( NULL ,
V_308 , 1 , & V_4 , false ) ;
if ( V_89 )
return V_89 ;
V_10 . V_473 ++ ;
}
return V_89 ;
}
static struct V_38 * F_446 ( struct V_475 * V_476 ,
unsigned long V_477 , T_13 V_478 )
{
struct V_38 * V_38 = F_447 ( V_476 , V_477 , V_478 ) ;
if ( ! V_38 || ! F_307 ( V_38 ) )
return NULL ;
if ( F_305 ( V_38 ) ) {
if ( ! F_12 () )
return NULL ;
} else if ( ! F_13 () )
return NULL ;
if ( ! F_310 ( V_38 ) )
return NULL ;
return V_38 ;
}
static struct V_38 * F_448 ( struct V_475 * V_476 ,
unsigned long V_477 , T_13 V_478 , T_8 * V_358 )
{
struct V_38 * V_38 = NULL ;
T_8 V_278 = F_449 ( V_478 ) ;
if ( ! F_12 () || F_450 ( V_278 ) )
return NULL ;
V_38 = F_451 ( F_452 ( V_278 ) , V_278 . V_67 ) ;
if ( V_145 )
V_358 -> V_67 = V_278 . V_67 ;
return V_38 ;
}
static struct V_38 * F_448 ( struct V_475 * V_476 ,
unsigned long V_477 , T_13 V_478 , T_8 * V_358 )
{
return NULL ;
}
static struct V_38 * F_453 ( struct V_475 * V_476 ,
unsigned long V_477 , T_13 V_478 , T_8 * V_358 )
{
struct V_38 * V_38 = NULL ;
struct V_479 * V_343 ;
T_14 V_480 ;
if ( ! V_476 -> V_481 )
return NULL ;
if ( ! F_13 () )
return NULL ;
V_343 = V_476 -> V_481 -> V_482 ;
if ( F_454 ( V_478 ) )
V_480 = F_455 ( V_476 , V_477 ) ;
else
V_480 = F_456 ( V_478 ) ;
V_38 = F_451 ( V_343 , V_480 ) ;
#ifdef F_457
if ( F_458 ( V_38 ) ) {
T_8 V_391 = F_459 ( V_38 ) ;
if ( V_145 )
* V_358 = V_391 ;
V_38 = F_451 ( F_452 ( V_391 ) , V_391 . V_67 ) ;
}
#endif
return V_38 ;
}
static enum V_483 F_460 ( struct V_475 * V_476 ,
unsigned long V_477 , T_13 V_478 , union V_484 * V_92 )
{
struct V_38 * V_38 = NULL ;
struct V_132 * V_133 ;
enum V_483 V_89 = V_485 ;
T_8 V_278 = { . V_67 = 0 } ;
if ( F_461 ( V_478 ) )
V_38 = F_446 ( V_476 , V_477 , V_478 ) ;
else if ( F_462 ( V_478 ) )
V_38 = F_448 ( V_476 , V_477 , V_478 , & V_278 ) ;
else if ( F_454 ( V_478 ) || F_463 ( V_478 ) )
V_38 = F_453 ( V_476 , V_477 , V_478 , & V_278 ) ;
if ( ! V_38 && ! V_278 . V_67 )
return V_89 ;
if ( V_38 ) {
V_133 = F_106 ( V_38 ) ;
if ( F_108 ( V_133 ) && V_133 -> V_1 == V_10 . V_152 ) {
V_89 = V_486 ;
if ( V_92 )
V_92 -> V_38 = V_38 ;
}
if ( ! V_89 || ! V_92 )
F_316 ( V_38 ) ;
}
if ( V_278 . V_67 && ! V_89 &&
F_95 ( & V_10 . V_152 -> V_15 ) == F_239 ( V_278 ) ) {
V_89 = V_487 ;
if ( V_92 )
V_92 -> V_278 = V_278 ;
}
return V_89 ;
}
static enum V_483 F_464 ( struct V_475 * V_476 ,
unsigned long V_477 , T_15 V_488 , union V_484 * V_92 )
{
struct V_38 * V_38 = NULL ;
struct V_132 * V_133 ;
enum V_483 V_89 = V_485 ;
V_38 = F_465 ( V_488 ) ;
F_36 ( ! V_38 || ! F_466 ( V_38 ) ) ;
if ( ! F_12 () )
return V_89 ;
V_133 = F_106 ( V_38 ) ;
if ( F_108 ( V_133 ) && V_133 -> V_1 == V_10 . V_152 ) {
V_89 = V_486 ;
if ( V_92 ) {
F_467 ( V_38 ) ;
V_92 -> V_38 = V_38 ;
}
}
return V_89 ;
}
static inline enum V_483 F_464 ( struct V_475 * V_476 ,
unsigned long V_477 , T_15 V_488 , union V_484 * V_92 )
{
return V_485 ;
}
static int F_468 ( T_15 * V_488 ,
unsigned long V_477 , unsigned long V_489 ,
struct V_490 * V_491 )
{
struct V_475 * V_476 = V_491 -> V_222 ;
T_13 * V_492 ;
T_16 * V_493 ;
if ( F_469 ( V_488 , V_476 ) == 1 ) {
if ( F_464 ( V_476 , V_477 , * V_488 , NULL ) == V_486 )
V_10 . V_473 += V_337 ;
F_51 ( & V_476 -> V_494 -> V_495 ) ;
return 0 ;
}
if ( F_470 ( V_488 ) )
return 0 ;
V_492 = F_471 ( V_476 -> V_494 , V_488 , V_477 , & V_493 ) ;
for (; V_477 != V_489 ; V_492 ++ , V_477 += V_238 )
if ( F_460 ( V_476 , V_477 , * V_492 , NULL ) )
V_10 . V_473 ++ ;
F_472 ( V_492 - 1 , V_493 ) ;
F_359 () ;
return 0 ;
}
static unsigned long F_473 ( struct V_109 * V_110 )
{
unsigned long V_473 ;
struct V_475 * V_476 ;
F_474 ( & V_110 -> V_496 ) ;
for ( V_476 = V_110 -> V_497 ; V_476 ; V_476 = V_476 -> V_498 ) {
struct V_490 V_499 = {
. V_500 = F_468 ,
. V_110 = V_110 ,
. V_222 = V_476 ,
} ;
if ( F_475 ( V_476 ) )
continue;
F_476 ( V_476 -> V_501 , V_476 -> V_502 ,
& V_499 ) ;
}
F_477 ( & V_110 -> V_496 ) ;
V_473 = V_10 . V_473 ;
V_10 . V_473 = 0 ;
return V_473 ;
}
static int F_478 ( struct V_109 * V_110 )
{
unsigned long V_473 = F_473 ( V_110 ) ;
F_36 ( V_10 . V_155 ) ;
V_10 . V_155 = V_24 ;
return F_445 ( V_473 ) ;
}
static void F_479 ( void )
{
struct V_1 * V_152 = V_10 . V_152 ;
struct V_1 * V_153 = V_10 . V_153 ;
if ( V_10 . V_473 ) {
F_229 ( V_10 . V_153 , V_10 . V_473 ) ;
V_10 . V_473 = 0 ;
}
if ( V_10 . V_503 ) {
F_229 ( V_10 . V_152 , V_10 . V_503 ) ;
V_10 . V_503 = 0 ;
}
if ( V_10 . V_504 ) {
if ( ! F_16 ( V_10 . V_152 ) )
F_202 ( & V_10 . V_152 -> V_146 ,
V_238 * V_10 . V_504 ) ;
F_435 ( V_10 . V_152 , V_10 . V_504 ) ;
if ( ! F_16 ( V_10 . V_153 ) ) {
F_202 ( & V_10 . V_153 -> V_58 ,
V_238 * V_10 . V_504 ) ;
}
V_10 . V_504 = 0 ;
}
F_189 ( V_152 ) ;
F_189 ( V_153 ) ;
F_480 ( & V_10 . V_157 ) ;
}
static void F_481 ( void )
{
struct V_1 * V_152 = V_10 . V_152 ;
V_10 . V_155 = NULL ;
F_479 () ;
F_50 ( & V_10 . V_56 ) ;
V_10 . V_152 = NULL ;
V_10 . V_153 = NULL ;
F_51 ( & V_10 . V_56 ) ;
F_126 ( V_152 ) ;
}
static int F_482 ( struct V_105 * V_105 ,
struct V_505 * V_506 )
{
struct V_108 * V_47 = F_483 ( V_506 ) ;
int V_89 = 0 ;
struct V_1 * V_4 = F_89 ( V_105 ) ;
unsigned long V_412 ;
V_412 = V_4 -> V_412 ;
if ( V_412 ) {
struct V_109 * V_110 ;
struct V_1 * V_152 = F_21 ( V_47 ) ;
F_36 ( V_152 == V_4 ) ;
V_110 = F_484 ( V_47 ) ;
if ( ! V_110 )
return 0 ;
if ( V_110 -> V_111 == V_47 ) {
F_36 ( V_10 . V_152 ) ;
F_36 ( V_10 . V_153 ) ;
F_36 ( V_10 . V_473 ) ;
F_36 ( V_10 . V_503 ) ;
F_36 ( V_10 . V_504 ) ;
F_124 ( V_152 ) ;
F_50 ( & V_10 . V_56 ) ;
V_10 . V_152 = V_152 ;
V_10 . V_153 = V_4 ;
V_10 . V_11 = V_412 ;
F_51 ( & V_10 . V_56 ) ;
V_89 = F_478 ( V_110 ) ;
if ( V_89 )
F_481 () ;
}
F_485 ( V_110 ) ;
}
return V_89 ;
}
static void F_486 ( struct V_105 * V_105 ,
struct V_505 * V_506 )
{
F_481 () ;
}
static int F_487 ( T_15 * V_488 ,
unsigned long V_477 , unsigned long V_489 ,
struct V_490 * V_491 )
{
int V_89 = 0 ;
struct V_475 * V_476 = V_491 -> V_222 ;
T_13 * V_492 ;
T_16 * V_493 ;
enum V_483 V_507 ;
union V_484 V_92 ;
struct V_38 * V_38 ;
struct V_132 * V_133 ;
if ( F_469 ( V_488 , V_476 ) == 1 ) {
if ( V_10 . V_473 < V_337 ) {
F_51 ( & V_476 -> V_494 -> V_495 ) ;
return 0 ;
}
V_507 = F_464 ( V_476 , V_477 , * V_488 , & V_92 ) ;
if ( V_507 == V_486 ) {
V_38 = V_92 . V_38 ;
if ( ! F_311 ( V_38 ) ) {
V_133 = F_106 ( V_38 ) ;
if ( ! F_304 ( V_38 , V_337 ,
V_133 , V_10 . V_152 , V_10 . V_153 ) ) {
V_10 . V_473 -= V_337 ;
V_10 . V_503 += V_337 ;
}
F_315 ( V_38 ) ;
}
F_316 ( V_38 ) ;
}
F_51 ( & V_476 -> V_494 -> V_495 ) ;
return 0 ;
}
if ( F_470 ( V_488 ) )
return 0 ;
V_63:
V_492 = F_471 ( V_476 -> V_494 , V_488 , V_477 , & V_493 ) ;
for (; V_477 != V_489 ; V_477 += V_238 ) {
T_13 V_478 = * ( V_492 ++ ) ;
T_8 V_278 ;
if ( ! V_10 . V_473 )
break;
switch ( F_460 ( V_476 , V_477 , V_478 , & V_92 ) ) {
case V_486 :
V_38 = V_92 . V_38 ;
if ( F_311 ( V_38 ) )
goto V_342;
V_133 = F_106 ( V_38 ) ;
if ( ! F_304 ( V_38 , 1 , V_133 ,
V_10 . V_152 , V_10 . V_153 ) ) {
V_10 . V_473 -- ;
V_10 . V_503 ++ ;
}
F_315 ( V_38 ) ;
V_342:
F_316 ( V_38 ) ;
break;
case V_487 :
V_278 = V_92 . V_278 ;
if ( ! F_338 ( V_278 , V_10 . V_152 , V_10 . V_153 ) ) {
V_10 . V_473 -- ;
V_10 . V_504 ++ ;
}
break;
default:
break;
}
}
F_472 ( V_492 - 1 , V_493 ) ;
F_359 () ;
if ( V_477 != V_489 ) {
V_89 = F_445 ( 1 ) ;
if ( ! V_89 )
goto V_63;
}
return V_89 ;
}
static void F_488 ( struct V_109 * V_110 )
{
struct V_475 * V_476 ;
F_361 () ;
V_63:
if ( F_86 ( ! F_489 ( & V_110 -> V_496 ) ) ) {
F_479 () ;
F_359 () ;
goto V_63;
}
for ( V_476 = V_110 -> V_497 ; V_476 ; V_476 = V_476 -> V_498 ) {
int V_89 ;
struct V_490 V_508 = {
. V_500 = F_487 ,
. V_110 = V_110 ,
. V_222 = V_476 ,
} ;
if ( F_475 ( V_476 ) )
continue;
V_89 = F_476 ( V_476 -> V_501 , V_476 -> V_502 ,
& V_508 ) ;
if ( V_89 )
break;
}
F_477 ( & V_110 -> V_496 ) ;
}
static void F_490 ( struct V_105 * V_106 ,
struct V_505 * V_506 )
{
struct V_108 * V_47 = F_483 ( V_506 ) ;
struct V_109 * V_110 = F_484 ( V_47 ) ;
if ( V_110 ) {
if ( V_10 . V_153 )
F_488 ( V_110 ) ;
F_485 ( V_110 ) ;
}
if ( V_10 . V_153 )
F_481 () ;
}
static int F_482 ( struct V_105 * V_105 ,
struct V_505 * V_506 )
{
return 0 ;
}
static void F_486 ( struct V_105 * V_105 ,
struct V_505 * V_506 )
{
}
static void F_490 ( struct V_105 * V_106 ,
struct V_505 * V_506 )
{
}
static int T_6 F_491 ( char * V_14 )
{
if ( ! strcmp ( V_14 , L_33 ) )
V_509 = 1 ;
else if ( ! strcmp ( V_14 , L_34 ) )
V_509 = 0 ;
return 1 ;
}
static void T_6 F_492 ( void )
{
F_25 ( F_493 ( & V_125 , V_510 ) ) ;
}
static void T_6 F_494 ( void )
{
if ( ! F_94 () && V_509 ) {
V_145 = 1 ;
F_492 () ;
}
}
static void T_6 F_494 ( void )
{
}
static int T_6 F_495 ( void )
{
F_496 ( F_220 , 0 ) ;
F_494 () ;
F_438 () ;
F_205 () ;
return 0 ;
}
