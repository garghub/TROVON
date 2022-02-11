static T_1 F_1 ( void )
{
return sizeof( struct V_1 ) +
V_2 * sizeof( struct V_3 * ) ;
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
F_10 () ;
if ( F_5 ( V_5 , & V_4 -> V_6 ) )
F_3 ( V_8 , & V_4 -> V_6 ) ;
}
static bool F_11 ( struct V_1 * V_4 )
{
return F_12 ( V_8 ,
& V_4 -> V_6 ) ;
}
static bool F_13 ( void )
{
return F_5 ( V_9 , & V_10 . V_11 ) ;
}
static bool F_14 ( void )
{
return F_5 ( V_12 , & V_10 . V_11 ) ;
}
struct V_1 * F_15 ( struct V_13 * V_14 )
{
return V_14 ? F_16 ( V_14 , struct V_1 , V_15 ) : NULL ;
}
struct V_16 * F_17 ( struct V_1 * V_4 )
{
if ( ! V_4 )
V_4 = V_17 ;
return & V_4 -> V_16 ;
}
struct V_13 * F_18 ( struct V_16 * V_18 )
{
return & F_16 ( V_18 , struct V_1 , V_16 ) -> V_15 ;
}
struct V_16 * F_19 ( struct V_13 * V_15 )
{
return & F_15 ( V_15 ) -> V_16 ;
}
static inline bool F_20 ( struct V_1 * V_4 )
{
return ( V_4 == V_17 ) ;
}
static inline unsigned short F_21 ( struct V_1 * V_4 )
{
return V_4 -> V_15 . V_19 -> V_20 + 1 ;
}
static inline struct V_1 * F_22 ( unsigned short V_20 )
{
struct V_13 * V_15 ;
V_15 = F_23 ( V_20 - 1 , & V_21 ) ;
return F_15 ( V_15 ) ;
}
void F_24 ( struct V_22 * V_23 )
{
if ( V_24 ) {
struct V_1 * V_4 ;
struct V_25 * V_25 ;
F_25 ( ! V_23 -> V_26 -> V_27 ) ;
if ( V_23 -> V_28 ) {
F_25 ( F_20 ( V_23 -> V_28 -> V_4 ) ) ;
F_26 ( & V_23 -> V_28 -> V_4 -> V_15 ) ;
return;
}
F_27 () ;
V_4 = F_28 ( V_29 ) ;
V_25 = V_23 -> V_26 -> V_27 ( V_4 ) ;
if ( ! F_20 ( V_4 ) &&
F_29 ( V_25 ) && F_30 ( & V_4 -> V_15 ) ) {
V_23 -> V_28 = V_25 ;
}
F_31 () ;
}
}
void F_32 ( struct V_22 * V_23 )
{
if ( V_24 && V_23 -> V_28 ) {
struct V_1 * V_4 ;
F_33 ( ! V_23 -> V_28 -> V_4 ) ;
V_4 = V_23 -> V_28 -> V_4 ;
F_34 ( & V_23 -> V_28 -> V_4 -> V_15 ) ;
}
}
struct V_25 * F_35 ( struct V_1 * V_4 )
{
if ( ! V_4 || F_20 ( V_4 ) )
return NULL ;
return & V_4 -> V_30 ;
}
static void F_36 ( struct V_1 * V_4 )
{
if ( ! F_37 ( & V_4 -> V_30 ) )
return;
F_38 ( & V_31 ) ;
}
static void F_36 ( struct V_1 * V_4 )
{
}
static void F_39 ( struct V_1 * V_4 )
{
if ( F_4 ( V_4 ) ) {
F_38 ( & V_32 ) ;
F_40 ( & V_33 , V_4 -> V_34 ) ;
}
F_33 ( F_41 ( & V_4 -> V_35 , V_36 ) != 0 ) ;
}
static void F_39 ( struct V_1 * V_4 )
{
}
static void F_42 ( struct V_1 * V_4 )
{
F_36 ( V_4 ) ;
F_39 ( V_4 ) ;
}
static struct V_37 *
F_43 ( struct V_1 * V_4 , int V_38 , int V_39 )
{
F_44 ( ( unsigned ) V_38 >= V_2 ) ;
return & V_4 -> V_40 [ V_38 ] -> V_41 [ V_39 ] ;
}
struct V_13 * F_45 ( struct V_1 * V_4 )
{
return & V_4 -> V_15 ;
}
static struct V_37 *
F_46 ( struct V_1 * V_4 , struct V_42 * V_42 )
{
int V_38 = F_47 ( V_42 ) ;
int V_39 = F_48 ( V_42 ) ;
return F_43 ( V_4 , V_38 , V_39 ) ;
}
static struct V_43 *
F_49 ( int V_38 , int V_39 )
{
return & V_44 . V_45 [ V_38 ] -> V_46 [ V_39 ] ;
}
static struct V_43 *
F_50 ( struct V_42 * V_42 )
{
int V_38 = F_47 ( V_42 ) ;
int V_39 = F_48 ( V_42 ) ;
return & V_44 . V_45 [ V_38 ] -> V_46 [ V_39 ] ;
}
static void
F_51 ( struct V_1 * V_4 ,
struct V_37 * V_47 ,
struct V_43 * V_48 ,
unsigned long long V_49 )
{
struct V_50 * * V_51 = & V_48 -> V_52 . V_50 ;
struct V_50 * V_53 = NULL ;
struct V_37 * V_54 ;
if ( V_47 -> V_55 )
return;
V_47 -> V_56 = V_49 ;
if ( ! V_47 -> V_56 )
return;
while ( * V_51 ) {
V_53 = * V_51 ;
V_54 = F_52 ( V_53 , struct V_37 ,
V_57 ) ;
if ( V_47 -> V_56 < V_54 -> V_56 )
V_51 = & ( * V_51 ) -> V_58 ;
else if ( V_47 -> V_56 >= V_54 -> V_56 )
V_51 = & ( * V_51 ) -> V_59 ;
}
F_53 ( & V_47 -> V_57 , V_53 , V_51 ) ;
F_54 ( & V_47 -> V_57 , & V_48 -> V_52 ) ;
V_47 -> V_55 = true ;
}
static void
F_55 ( struct V_1 * V_4 ,
struct V_37 * V_47 ,
struct V_43 * V_48 )
{
if ( ! V_47 -> V_55 )
return;
F_56 ( & V_47 -> V_57 , & V_48 -> V_52 ) ;
V_47 -> V_55 = false ;
}
static void
F_57 ( struct V_1 * V_4 ,
struct V_37 * V_47 ,
struct V_43 * V_48 )
{
F_58 ( & V_48 -> V_60 ) ;
F_55 ( V_4 , V_47 , V_48 ) ;
F_59 ( & V_48 -> V_60 ) ;
}
static void F_60 ( struct V_1 * V_4 , struct V_42 * V_42 )
{
unsigned long long V_61 ;
struct V_37 * V_47 ;
struct V_43 * V_48 ;
int V_38 = F_47 ( V_42 ) ;
int V_39 = F_48 ( V_42 ) ;
V_48 = F_50 ( V_42 ) ;
for (; V_4 ; V_4 = F_61 ( V_4 ) ) {
V_47 = F_43 ( V_4 , V_38 , V_39 ) ;
V_61 = F_62 ( & V_4 -> V_62 ) ;
if ( V_61 || V_47 -> V_55 ) {
F_58 ( & V_48 -> V_60 ) ;
if ( V_47 -> V_55 )
F_55 ( V_4 , V_47 , V_48 ) ;
F_51 ( V_4 , V_47 , V_48 , V_61 ) ;
F_59 ( & V_48 -> V_60 ) ;
}
}
}
static void F_63 ( struct V_1 * V_4 )
{
int V_63 , V_64 ;
struct V_37 * V_47 ;
struct V_43 * V_48 ;
F_64 (node) {
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_47 = F_43 ( V_4 , V_63 , V_64 ) ;
V_48 = F_49 ( V_63 , V_64 ) ;
F_57 ( V_4 , V_47 , V_48 ) ;
}
}
}
static struct V_37 *
F_65 ( struct V_43 * V_48 )
{
struct V_50 * V_66 = NULL ;
struct V_37 * V_47 ;
V_67:
V_47 = NULL ;
V_66 = F_66 ( & V_48 -> V_52 ) ;
if ( ! V_66 )
goto V_68;
V_47 = F_52 ( V_66 , struct V_37 , V_57 ) ;
F_55 ( V_47 -> V_4 , V_47 , V_48 ) ;
if ( ! F_62 ( & V_47 -> V_4 -> V_62 ) ||
! F_30 ( & V_47 -> V_4 -> V_15 ) )
goto V_67;
V_68:
return V_47 ;
}
static struct V_37 *
F_67 ( struct V_43 * V_48 )
{
struct V_37 * V_47 ;
F_58 ( & V_48 -> V_60 ) ;
V_47 = F_65 ( V_48 ) ;
F_59 ( & V_48 -> V_60 ) ;
return V_47 ;
}
static long F_68 ( struct V_1 * V_4 ,
enum V_69 V_70 )
{
long V_71 = 0 ;
int V_72 ;
F_69 () ;
F_70 (cpu)
V_71 += F_71 ( V_4 -> V_73 -> V_74 [ V_70 ] , V_72 ) ;
#ifdef F_72
F_58 ( & V_4 -> V_75 ) ;
V_71 += V_4 -> V_76 . V_74 [ V_70 ] ;
F_59 ( & V_4 -> V_75 ) ;
#endif
F_73 () ;
return V_71 ;
}
static void F_74 ( struct V_1 * V_4 ,
bool V_77 )
{
int V_71 = ( V_77 ) ? 1 : - 1 ;
F_75 ( V_4 -> V_73 -> V_74 [ V_78 ] , V_71 ) ;
}
static unsigned long F_76 ( struct V_1 * V_4 ,
enum V_79 V_70 )
{
unsigned long V_71 = 0 ;
int V_72 ;
F_69 () ;
F_70 (cpu)
V_71 += F_71 ( V_4 -> V_73 -> V_80 [ V_70 ] , V_72 ) ;
#ifdef F_72
F_58 ( & V_4 -> V_75 ) ;
V_71 += V_4 -> V_76 . V_80 [ V_70 ] ;
F_59 ( & V_4 -> V_75 ) ;
#endif
F_73 () ;
return V_71 ;
}
static void F_77 ( struct V_1 * V_4 ,
struct V_42 * V_42 ,
bool V_81 , int V_82 )
{
F_78 () ;
if ( V_81 )
F_79 ( V_4 -> V_73 -> V_74 [ V_83 ] ,
V_82 ) ;
else
F_79 ( V_4 -> V_73 -> V_74 [ V_84 ] ,
V_82 ) ;
if ( F_80 ( V_42 ) )
F_79 ( V_4 -> V_73 -> V_74 [ V_85 ] ,
V_82 ) ;
if ( V_82 > 0 )
F_81 ( V_4 -> V_73 -> V_80 [ V_86 ] ) ;
else {
F_81 ( V_4 -> V_73 -> V_80 [ V_87 ] ) ;
V_82 = - V_82 ;
}
F_79 ( V_4 -> V_73 -> V_88 , V_82 ) ;
F_82 () ;
}
unsigned long
F_83 ( struct V_89 * V_89 , enum V_90 V_91 )
{
struct V_37 * V_47 ;
V_47 = F_16 ( V_89 , struct V_37 , V_89 ) ;
return V_47 -> V_92 [ V_91 ] ;
}
static unsigned long
F_84 ( struct V_1 * V_4 , int V_38 , int V_39 ,
unsigned int V_93 )
{
struct V_37 * V_47 ;
enum V_90 V_91 ;
unsigned long V_94 = 0 ;
V_47 = F_43 ( V_4 , V_38 , V_39 ) ;
F_85 (lru) {
if ( F_86 ( V_91 ) & V_93 )
V_94 += V_47 -> V_92 [ V_91 ] ;
}
return V_94 ;
}
static unsigned long
F_87 ( struct V_1 * V_4 ,
int V_38 , unsigned int V_93 )
{
T_2 V_95 = 0 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_65 ; V_39 ++ )
V_95 += F_84 ( V_4 ,
V_38 , V_39 , V_93 ) ;
return V_95 ;
}
static unsigned long F_88 ( struct V_1 * V_4 ,
unsigned int V_93 )
{
int V_38 ;
T_2 V_95 = 0 ;
F_89 (nid, N_MEMORY)
V_95 += F_87 ( V_4 , V_38 , V_93 ) ;
return V_95 ;
}
static bool F_90 ( struct V_1 * V_4 ,
enum V_96 V_97 )
{
unsigned long V_71 , V_98 ;
V_71 = F_91 ( V_4 -> V_73 -> V_88 ) ;
V_98 = F_91 ( V_4 -> V_73 -> V_99 [ V_97 ] ) ;
if ( ( long ) V_98 - ( long ) V_71 < 0 ) {
switch ( V_97 ) {
case V_100 :
V_98 = V_71 + V_101 ;
break;
case V_102 :
V_98 = V_71 + V_103 ;
break;
case V_104 :
V_98 = V_71 + V_105 ;
break;
default:
break;
}
F_92 ( V_4 -> V_73 -> V_99 [ V_97 ] , V_98 ) ;
return true ;
}
return false ;
}
static void F_93 ( struct V_1 * V_4 , struct V_42 * V_42 )
{
F_78 () ;
if ( F_94 ( F_90 ( V_4 ,
V_100 ) ) ) {
bool V_106 ;
bool T_3 V_107 ;
V_106 = F_90 ( V_4 ,
V_102 ) ;
#if V_108 > 1
T_3 = F_90 ( V_4 ,
V_104 ) ;
#endif
F_82 () ;
F_95 ( V_4 ) ;
if ( F_94 ( V_106 ) )
F_60 ( V_4 , V_42 ) ;
#if V_108 > 1
if ( F_94 ( T_3 ) )
F_96 ( & V_4 -> V_109 ) ;
#endif
} else
F_82 () ;
}
struct V_1 * F_28 ( struct V_110 * V_51 )
{
if ( F_94 ( ! V_51 ) )
return NULL ;
return F_15 ( F_97 ( V_51 , V_111 ) ) ;
}
struct V_1 * F_98 ( struct V_112 * V_113 )
{
struct V_1 * V_4 = NULL ;
if ( ! V_113 )
return NULL ;
F_27 () ;
do {
V_4 = F_28 ( F_99 ( V_113 -> V_114 ) ) ;
if ( F_94 ( ! V_4 ) )
break;
} while ( ! F_30 ( & V_4 -> V_15 ) );
F_31 () ;
return V_4 ;
}
static struct V_1 * F_100 ( struct V_1 * V_115 ,
struct V_1 * V_116 )
{
struct V_13 * V_117 , * V_118 ;
V_117 = V_116 ? & V_116 -> V_15 : NULL ;
V_119:
V_118 = F_101 ( V_117 , & V_115 -> V_15 ) ;
if ( V_118 ) {
struct V_1 * V_120 = F_15 ( V_118 ) ;
if ( F_30 ( & V_120 -> V_15 ) )
return V_120 ;
else {
V_117 = V_118 ;
goto V_119;
}
}
return NULL ;
}
static void F_102 ( struct V_1 * V_115 )
{
F_96 ( & V_115 -> V_121 ) ;
}
static struct V_1 *
F_103 ( struct V_122 * V_123 ,
struct V_1 * V_115 ,
int * V_124 )
{
struct V_1 * V_125 = NULL ;
* V_124 = F_104 ( & V_115 -> V_121 ) ;
if ( V_123 -> V_126 == * V_124 ) {
F_105 () ;
V_125 = V_123 -> V_116 ;
if ( V_125 && ! F_30 ( & V_125 -> V_15 ) )
V_125 = NULL ;
}
return V_125 ;
}
static void F_106 ( struct V_122 * V_123 ,
struct V_1 * V_116 ,
struct V_1 * V_127 ,
int V_124 )
{
if ( V_116 )
F_34 ( & V_116 -> V_15 ) ;
V_123 -> V_116 = V_127 ;
F_10 () ;
V_123 -> V_126 = V_124 ;
}
struct V_1 * F_107 ( struct V_1 * V_115 ,
struct V_1 * V_128 ,
struct V_129 * V_130 )
{
struct V_1 * V_4 = NULL ;
struct V_1 * V_116 = NULL ;
if ( F_108 () )
return NULL ;
if ( ! V_115 )
V_115 = V_17 ;
if ( V_128 && ! V_130 )
V_116 = V_128 ;
if ( ! V_115 -> V_131 && V_115 != V_17 ) {
if ( V_128 )
goto V_132;
return V_115 ;
}
F_27 () ;
while ( ! V_4 ) {
struct V_122 * V_133 ( V_123 ) ;
int V_133 ( V_134 ) ;
if ( V_130 ) {
int V_38 = F_109 ( V_130 -> V_64 ) ;
int V_39 = F_110 ( V_130 -> V_64 ) ;
struct V_37 * V_47 ;
V_47 = F_43 ( V_115 , V_38 , V_39 ) ;
V_123 = & V_47 -> V_135 [ V_130 -> V_136 ] ;
if ( V_128 && V_130 -> V_137 != V_123 -> V_137 ) {
V_123 -> V_116 = NULL ;
goto V_138;
}
V_116 = F_103 ( V_123 , V_115 , & V_134 ) ;
}
V_4 = F_100 ( V_115 , V_116 ) ;
if ( V_130 ) {
F_106 ( V_123 , V_116 , V_4 , V_134 ) ;
if ( ! V_4 )
V_123 -> V_137 ++ ;
else if ( ! V_128 && V_4 )
V_130 -> V_137 = V_123 -> V_137 ;
}
if ( V_128 && ! V_4 )
goto V_138;
}
V_138:
F_31 () ;
V_132:
if ( V_128 && V_128 != V_115 )
F_34 ( & V_128 -> V_15 ) ;
return V_4 ;
}
void F_111 ( struct V_1 * V_115 ,
struct V_1 * V_128 )
{
if ( ! V_115 )
V_115 = V_17 ;
if ( V_128 && V_128 != V_115 )
F_34 ( & V_128 -> V_15 ) ;
}
void F_112 ( struct V_112 * V_113 , enum V_139 V_70 )
{
struct V_1 * V_4 ;
F_27 () ;
V_4 = F_28 ( F_99 ( V_113 -> V_114 ) ) ;
if ( F_94 ( ! V_4 ) )
goto V_140;
switch ( V_70 ) {
case V_141 :
F_113 ( V_4 -> V_73 -> V_80 [ V_142 ] ) ;
break;
case V_143 :
F_113 ( V_4 -> V_73 -> V_80 [ V_144 ] ) ;
break;
default:
F_114 () ;
}
V_140:
F_31 () ;
}
struct V_89 * F_115 ( struct V_64 * V_64 ,
struct V_1 * V_4 )
{
struct V_37 * V_47 ;
struct V_89 * V_89 ;
if ( F_108 () ) {
V_89 = & V_64 -> V_89 ;
goto V_140;
}
V_47 = F_43 ( V_4 , F_109 ( V_64 ) , F_110 ( V_64 ) ) ;
V_89 = & V_47 -> V_89 ;
V_140:
if ( F_94 ( V_89 -> V_64 != V_64 ) )
V_89 -> V_64 = V_64 ;
return V_89 ;
}
struct V_89 * F_116 ( struct V_42 * V_42 , struct V_64 * V_64 )
{
struct V_37 * V_47 ;
struct V_1 * V_4 ;
struct V_145 * V_146 ;
struct V_89 * V_89 ;
if ( F_108 () ) {
V_89 = & V_64 -> V_89 ;
goto V_140;
}
V_146 = F_117 ( V_42 ) ;
V_4 = V_146 -> V_1 ;
if ( ! F_118 ( V_42 ) && ! F_119 ( V_146 ) && V_4 != V_17 )
V_146 -> V_1 = V_4 = V_17 ;
V_47 = F_46 ( V_4 , V_42 ) ;
V_89 = & V_47 -> V_89 ;
V_140:
if ( F_94 ( V_89 -> V_64 != V_64 ) )
V_89 -> V_64 = V_64 ;
return V_89 ;
}
void F_120 ( struct V_89 * V_89 , enum V_90 V_91 ,
int V_82 )
{
struct V_37 * V_47 ;
unsigned long * V_92 ;
if ( F_108 () )
return;
V_47 = F_16 ( V_89 , struct V_37 , V_89 ) ;
V_92 = V_47 -> V_92 + V_91 ;
* V_92 += V_82 ;
F_44 ( ( long ) ( * V_92 ) < 0 ) ;
}
bool F_121 ( const struct V_1 * V_147 ,
struct V_1 * V_4 )
{
if ( V_147 == V_4 )
return true ;
if ( ! V_147 -> V_131 || ! V_4 )
return false ;
return F_122 ( V_4 -> V_15 . V_19 , V_147 -> V_15 . V_19 ) ;
}
static bool F_123 ( const struct V_1 * V_147 ,
struct V_1 * V_4 )
{
bool V_94 ;
F_27 () ;
V_94 = F_121 ( V_147 , V_4 ) ;
F_31 () ;
return V_94 ;
}
bool F_124 ( struct V_110 * V_148 ,
const struct V_1 * V_4 )
{
struct V_1 * V_149 = NULL ;
struct V_110 * V_51 ;
bool V_94 ;
V_51 = F_125 ( V_148 ) ;
if ( V_51 ) {
V_149 = F_98 ( V_51 -> V_113 ) ;
F_126 ( V_51 ) ;
} else {
F_27 () ;
V_149 = F_28 ( V_148 ) ;
if ( V_149 )
F_26 ( & V_149 -> V_15 ) ;
F_31 () ;
}
if ( ! V_149 )
return false ;
V_94 = F_123 ( V_4 , V_149 ) ;
F_34 ( & V_149 -> V_15 ) ;
return V_94 ;
}
int F_127 ( struct V_89 * V_89 )
{
unsigned long V_150 ;
unsigned long V_151 ;
unsigned long V_152 ;
unsigned long V_153 ;
V_151 = F_83 ( V_89 , V_154 ) ;
V_152 = F_83 ( V_89 , V_155 ) ;
V_153 = ( V_151 + V_152 ) >> ( 30 - V_156 ) ;
if ( V_153 )
V_150 = F_128 ( 10 * V_153 ) ;
else
V_150 = 1 ;
return V_151 * V_150 < V_152 ;
}
static unsigned long F_129 ( struct V_1 * V_4 )
{
unsigned long long V_157 ;
V_157 = F_130 ( & V_4 -> V_62 ) ;
if ( V_158 )
V_157 = F_131 ( V_157 , F_130 ( & V_4 -> V_159 ) ) ;
return V_157 >> V_156 ;
}
int F_132 ( struct V_1 * V_4 )
{
if ( ! F_133 ( & V_4 -> V_15 ) )
return V_160 ;
return V_4 -> V_161 ;
}
static void F_134 ( struct V_1 * V_4 )
{
F_96 ( & V_162 ) ;
F_96 ( & V_4 -> V_163 ) ;
F_135 () ;
}
static void F_136 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_137 ( & V_162 ) ;
F_137 ( & V_4 -> V_163 ) ;
}
}
static bool F_138 ( struct V_1 * V_4 )
{
F_44 ( ! F_139 () ) ;
return F_104 ( & V_4 -> V_163 ) > 0 ;
}
static bool F_140 ( struct V_1 * V_4 )
{
struct V_1 * V_164 ;
struct V_1 * V_165 ;
bool V_94 = false ;
F_58 ( & V_10 . V_60 ) ;
V_164 = V_10 . V_164 ;
V_165 = V_10 . V_165 ;
if ( ! V_164 )
goto V_166;
V_94 = F_123 ( V_4 , V_164 )
|| F_123 ( V_4 , V_165 ) ;
V_166:
F_59 ( & V_10 . V_60 ) ;
return V_94 ;
}
static bool F_141 ( struct V_1 * V_4 )
{
if ( V_10 . V_167 && V_29 != V_10 . V_167 ) {
if ( F_140 ( V_4 ) ) {
F_142 ( V_168 ) ;
F_143 ( & V_10 . V_169 , & V_168 , V_170 ) ;
if ( V_10 . V_167 )
F_144 () ;
F_145 ( & V_10 . V_169 , & V_168 ) ;
return true ;
}
}
return false ;
}
static void F_146 ( struct V_1 * V_4 ,
unsigned long * V_171 )
{
F_147 ( & V_4 -> V_172 , * V_171 ) ;
}
static void F_148 ( struct V_1 * V_4 ,
unsigned long * V_171 )
{
F_149 ( & V_4 -> V_172 , * V_171 ) ;
}
void F_150 ( struct V_1 * V_4 , struct V_110 * V_51 )
{
struct V_19 * V_173 ;
struct V_19 * V_174 ;
static char V_175 [ V_176 ] ;
int V_94 ;
struct V_1 * V_123 ;
unsigned int V_177 ;
if ( ! V_51 )
return;
F_27 () ;
V_174 = V_4 -> V_15 . V_19 ;
V_173 = F_151 ( V_51 , V_111 ) ;
V_94 = F_152 ( V_173 , V_175 , V_176 ) ;
if ( V_94 < 0 ) {
F_31 () ;
goto V_68;
}
F_31 () ;
F_153 ( L_1 , V_175 ) ;
F_27 () ;
V_94 = F_152 ( V_174 , V_175 , V_176 ) ;
if ( V_94 < 0 ) {
F_31 () ;
goto V_68;
}
F_31 () ;
F_154 ( L_2 , V_175 ) ;
V_68:
F_153 ( L_3 ,
F_41 ( & V_4 -> V_62 , V_36 ) >> 10 ,
F_41 ( & V_4 -> V_62 , V_178 ) >> 10 ,
F_41 ( & V_4 -> V_62 , V_179 ) ) ;
F_153 ( L_4 ,
F_41 ( & V_4 -> V_159 , V_36 ) >> 10 ,
F_41 ( & V_4 -> V_159 , V_178 ) >> 10 ,
F_41 ( & V_4 -> V_159 , V_179 ) ) ;
F_153 ( L_5 ,
F_41 ( & V_4 -> V_35 , V_36 ) >> 10 ,
F_41 ( & V_4 -> V_35 , V_178 ) >> 10 ,
F_41 ( & V_4 -> V_35 , V_179 ) ) ;
F_155 (iter, memcg) {
F_153 ( L_6 ) ;
F_27 () ;
V_94 = F_152 ( V_123 -> V_15 . V_19 , V_175 , V_176 ) ;
if ( ! V_94 )
F_154 ( L_7 , V_175 ) ;
F_31 () ;
F_154 ( L_8 ) ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
if ( V_177 == V_78 && ! V_158 )
continue;
F_154 ( L_9 , V_181 [ V_177 ] ,
F_156 ( F_68 ( V_123 , V_177 ) ) ) ;
}
for ( V_177 = 0 ; V_177 < V_182 ; V_177 ++ )
F_154 ( L_10 , V_183 [ V_177 ] ,
F_156 ( F_88 ( V_123 , F_86 ( V_177 ) ) ) ) ;
F_154 ( L_11 ) ;
}
}
static int F_157 ( struct V_1 * V_4 )
{
int V_184 = 0 ;
struct V_1 * V_123 ;
F_155 (iter, memcg)
V_184 ++ ;
return V_184 ;
}
static T_2 F_158 ( struct V_1 * V_4 )
{
T_2 V_185 ;
V_185 = F_41 ( & V_4 -> V_62 , V_178 ) ;
if ( F_132 ( V_4 ) ) {
T_2 V_159 ;
V_185 += V_186 << V_156 ;
V_159 = F_41 ( & V_4 -> V_159 , V_178 ) ;
V_185 = F_131 ( V_185 , V_159 ) ;
}
return V_185 ;
}
static void F_159 ( struct V_1 * V_4 , T_4 V_187 ,
int V_188 )
{
struct V_1 * V_123 ;
unsigned long V_189 = 0 ;
unsigned long V_190 ;
unsigned int V_191 = 0 ;
struct V_110 * V_192 = NULL ;
if ( F_160 ( V_29 ) || V_29 -> V_171 & V_193 ) {
F_161 ( V_194 ) ;
return;
}
F_162 ( V_195 , V_187 , V_188 , NULL ) ;
V_190 = F_158 ( V_4 ) >> V_156 ? : 1 ;
F_155 (iter, memcg) {
struct V_196 V_197 ;
struct V_110 * V_148 ;
F_163 ( & V_123 -> V_15 , & V_197 ) ;
while ( ( V_148 = F_164 ( & V_197 ) ) ) {
switch ( F_165 ( V_148 , V_190 , NULL ,
false ) ) {
case V_198 :
if ( V_192 )
F_166 ( V_192 ) ;
V_192 = V_148 ;
V_189 = V_199 ;
F_167 ( V_192 ) ;
case V_200 :
continue;
case V_201 :
F_168 ( & V_197 ) ;
F_111 ( V_4 , V_123 ) ;
if ( V_192 )
F_166 ( V_192 ) ;
return;
case V_202 :
break;
} ;
V_191 = F_169 ( V_148 , V_4 , NULL , V_190 ) ;
if ( V_191 > V_189 ) {
if ( V_192 )
F_166 ( V_192 ) ;
V_192 = V_148 ;
V_189 = V_191 ;
F_167 ( V_192 ) ;
}
}
F_168 ( & V_197 ) ;
}
if ( ! V_192 )
return;
V_191 = V_189 * 1000 / V_190 ;
F_170 ( V_192 , V_187 , V_188 , V_191 , V_190 , V_4 ,
NULL , L_12 ) ;
}
static unsigned long F_171 ( struct V_1 * V_4 ,
T_4 V_187 ,
unsigned long V_171 )
{
unsigned long V_95 = 0 ;
bool V_203 = false ;
int V_204 ;
if ( V_171 & V_205 )
V_203 = true ;
if ( ! ( V_171 & V_206 ) && V_4 -> V_207 )
V_203 = true ;
for ( V_204 = 0 ; V_204 < V_208 ; V_204 ++ ) {
if ( V_204 )
F_172 ( V_4 ) ;
V_95 += F_173 ( V_4 , V_187 , V_203 ) ;
if ( V_95 && ( V_171 & V_206 ) )
break;
if ( F_129 ( V_4 ) )
break;
if ( V_204 && ! V_95 )
break;
}
return V_95 ;
}
static bool F_174 ( struct V_1 * V_4 ,
int V_38 , bool V_203 )
{
if ( F_87 ( V_4 , V_38 , V_209 ) )
return true ;
if ( V_203 || ! V_186 )
return false ;
if ( F_87 ( V_4 , V_38 , V_210 ) )
return true ;
return false ;
}
static void F_175 ( struct V_1 * V_4 )
{
int V_38 ;
if ( ! F_104 ( & V_4 -> V_109 ) )
return;
if ( F_176 ( & V_4 -> V_211 ) > 1 )
return;
V_4 -> V_212 = V_213 [ V_214 ] ;
F_177 (nid, node_states[N_MEMORY]) {
if ( ! F_174 ( V_4 , V_38 , false ) )
F_178 ( V_38 , V_4 -> V_212 ) ;
}
F_179 ( & V_4 -> V_109 , 0 ) ;
F_179 ( & V_4 -> V_211 , 0 ) ;
}
int F_180 ( struct V_1 * V_4 )
{
int V_63 ;
F_175 ( V_4 ) ;
V_63 = V_4 -> V_215 ;
V_63 = F_181 ( V_63 , V_4 -> V_212 ) ;
if ( V_63 == V_108 )
V_63 = F_182 ( V_4 -> V_212 ) ;
if ( F_94 ( V_63 == V_108 ) )
V_63 = F_183 () ;
V_4 -> V_215 = V_63 ;
return V_63 ;
}
static bool F_184 ( struct V_1 * V_4 , bool V_203 )
{
int V_38 ;
if ( ! F_185 ( V_4 -> V_212 ) ) {
for ( V_38 = F_182 ( V_4 -> V_212 ) ;
V_38 < V_108 ;
V_38 = F_181 ( V_38 , V_4 -> V_212 ) ) {
if ( F_174 ( V_4 , V_38 , V_203 ) )
return true ;
}
}
F_89 (nid, N_MEMORY) {
if ( F_186 ( V_38 , V_4 -> V_212 ) )
continue;
if ( F_174 ( V_4 , V_38 , V_203 ) )
return true ;
}
return false ;
}
int F_180 ( struct V_1 * V_4 )
{
return 0 ;
}
static bool F_184 ( struct V_1 * V_4 , bool V_203 )
{
return F_174 ( V_4 , 0 , V_203 ) ;
}
static int F_187 ( struct V_1 * V_147 ,
struct V_64 * V_64 ,
T_4 V_187 ,
unsigned long * V_216 )
{
struct V_1 * V_217 = NULL ;
int V_95 = 0 ;
int V_204 = 0 ;
unsigned long V_61 ;
unsigned long V_218 ;
struct V_129 V_130 = {
. V_64 = V_64 ,
. V_136 = 0 ,
} ;
V_61 = F_62 ( & V_147 -> V_62 ) >> V_156 ;
while ( 1 ) {
V_217 = F_107 ( V_147 , V_217 , & V_130 ) ;
if ( ! V_217 ) {
V_204 ++ ;
if ( V_204 >= 2 ) {
if ( ! V_95 )
break;
if ( V_95 >= ( V_61 >> 2 ) ||
( V_204 > V_208 ) )
break;
}
continue;
}
if ( ! F_184 ( V_217 , false ) )
continue;
V_95 += F_188 ( V_217 , V_187 , false ,
V_64 , & V_218 ) ;
* V_216 += V_218 ;
if ( ! F_62 ( & V_147 -> V_62 ) )
break;
}
F_111 ( V_147 , V_217 ) ;
return V_95 ;
}
static bool F_189 ( struct V_1 * V_4 )
{
struct V_1 * V_123 , * V_219 = NULL ;
F_58 ( & V_220 ) ;
F_155 (iter, memcg) {
if ( V_123 -> V_221 ) {
V_219 = V_123 ;
F_111 ( V_4 , V_123 ) ;
break;
} else
V_123 -> V_221 = true ;
}
if ( V_219 ) {
F_155 (iter, memcg) {
if ( V_123 == V_219 ) {
F_111 ( V_4 , V_123 ) ;
break;
}
V_123 -> V_221 = false ;
}
} else
F_190 ( & V_222 , 0 , 1 , V_223 ) ;
F_59 ( & V_220 ) ;
return ! V_219 ;
}
static void F_191 ( struct V_1 * V_4 )
{
struct V_1 * V_123 ;
F_58 ( & V_220 ) ;
F_192 ( & V_222 , 1 , V_223 ) ;
F_155 (iter, memcg)
V_123 -> V_221 = false ;
F_59 ( & V_220 ) ;
}
static void F_193 ( struct V_1 * V_4 )
{
struct V_1 * V_123 ;
F_155 (iter, memcg)
F_96 ( & V_123 -> V_224 ) ;
}
static void F_194 ( struct V_1 * V_4 )
{
struct V_1 * V_123 ;
F_155 (iter, memcg)
F_195 ( & V_123 -> V_224 , - 1 , 0 ) ;
}
static int F_196 ( T_5 * V_168 ,
unsigned V_225 , int V_226 , void * V_227 )
{
struct V_1 * V_228 = (struct V_1 * ) V_227 ;
struct V_1 * V_229 ;
struct V_230 * V_230 ;
V_230 = F_16 ( V_168 , struct V_230 , V_168 ) ;
V_229 = V_230 -> V_4 ;
if ( ! F_123 ( V_229 , V_228 )
&& ! F_123 ( V_228 , V_229 ) )
return 0 ;
return F_197 ( V_168 , V_225 , V_226 , V_227 ) ;
}
static void F_198 ( struct V_1 * V_4 )
{
F_96 ( & V_4 -> V_231 ) ;
F_199 ( & V_232 , V_233 , 0 , V_4 ) ;
}
static void F_200 ( struct V_1 * V_4 )
{
if ( V_4 && F_104 ( & V_4 -> V_224 ) )
F_198 ( V_4 ) ;
}
static void F_201 ( struct V_1 * V_4 , T_4 V_234 , int V_188 )
{
if ( ! V_29 -> V_235 . V_236 )
return;
F_26 ( & V_4 -> V_15 ) ;
V_29 -> V_235 . V_4 = V_4 ;
V_29 -> V_235 . V_187 = V_234 ;
V_29 -> V_235 . V_188 = V_188 ;
}
bool F_202 ( bool V_237 )
{
struct V_1 * V_4 = V_29 -> V_235 . V_4 ;
struct V_230 V_238 ;
bool V_239 ;
if ( ! V_4 )
return false ;
if ( ! V_237 )
goto V_240;
V_238 . V_4 = V_4 ;
V_238 . V_168 . V_171 = 0 ;
V_238 . V_168 . V_241 = F_196 ;
V_238 . V_168 . V_242 = V_29 ;
F_203 ( & V_238 . V_168 . V_243 ) ;
F_143 ( & V_232 , & V_238 . V_168 , V_244 ) ;
F_193 ( V_4 ) ;
V_239 = F_189 ( V_4 ) ;
if ( V_239 )
F_204 ( V_4 ) ;
if ( V_239 && ! V_4 -> V_245 ) {
F_194 ( V_4 ) ;
F_145 ( & V_232 , & V_238 . V_168 ) ;
F_159 ( V_4 , V_29 -> V_235 . V_187 ,
V_29 -> V_235 . V_188 ) ;
} else {
F_144 () ;
F_194 ( V_4 ) ;
F_145 ( & V_232 , & V_238 . V_168 ) ;
}
if ( V_239 ) {
F_191 ( V_4 ) ;
F_200 ( V_4 ) ;
}
V_240:
V_29 -> V_235 . V_4 = NULL ;
F_34 ( & V_4 -> V_15 ) ;
return true ;
}
void F_205 ( struct V_42 * V_42 ,
bool * V_239 , unsigned long * V_171 )
{
struct V_1 * V_4 ;
struct V_145 * V_146 ;
V_146 = F_117 ( V_42 ) ;
V_246:
V_4 = V_146 -> V_1 ;
if ( F_94 ( ! V_4 || ! F_119 ( V_146 ) ) )
return;
if ( ! F_138 ( V_4 ) )
return;
F_146 ( V_4 , V_171 ) ;
if ( V_4 != V_146 -> V_1 || ! F_119 ( V_146 ) ) {
F_148 ( V_4 , V_171 ) ;
goto V_246;
}
* V_239 = true ;
}
void F_206 ( struct V_42 * V_42 , unsigned long * V_171 )
{
struct V_145 * V_146 = F_117 ( V_42 ) ;
F_148 ( V_146 -> V_1 , V_171 ) ;
}
void F_207 ( struct V_42 * V_42 ,
enum V_69 V_70 , int V_71 )
{
struct V_1 * V_4 ;
struct V_145 * V_146 = F_117 ( V_42 ) ;
unsigned long V_133 ( V_171 ) ;
if ( F_108 () )
return;
F_44 ( ! F_139 () ) ;
V_4 = V_146 -> V_1 ;
if ( F_94 ( ! V_4 || ! F_119 ( V_146 ) ) )
return;
F_75 ( V_4 -> V_73 -> V_74 [ V_70 ] , V_71 ) ;
}
static bool F_208 ( struct V_1 * V_4 , unsigned int V_82 )
{
struct V_247 * V_248 ;
bool V_94 = true ;
if ( V_82 > V_249 )
return false ;
V_248 = & F_209 ( V_250 ) ;
if ( V_4 == V_248 -> V_251 && V_248 -> V_82 >= V_82 )
V_248 -> V_82 -= V_82 ;
else
V_94 = false ;
F_210 ( V_250 ) ;
return V_94 ;
}
static void F_211 ( struct V_247 * V_248 )
{
struct V_1 * V_252 = V_248 -> V_251 ;
if ( V_248 -> V_82 ) {
unsigned long V_253 = V_248 -> V_82 * V_254 ;
F_212 ( & V_252 -> V_62 , V_253 ) ;
if ( V_158 )
F_212 ( & V_252 -> V_159 , V_253 ) ;
V_248 -> V_82 = 0 ;
}
V_248 -> V_251 = NULL ;
}
static void F_213 ( struct V_255 * V_256 )
{
struct V_247 * V_248 = & F_214 ( V_250 ) ;
F_211 ( V_248 ) ;
F_8 ( V_257 , & V_248 -> V_171 ) ;
}
static void T_6 F_215 ( void )
{
int V_72 ;
F_216 (cpu) {
struct V_247 * V_248 =
& F_71 ( V_250 , V_72 ) ;
F_217 ( & V_248 -> V_258 , F_213 ) ;
}
}
static void F_218 ( struct V_1 * V_4 , unsigned int V_82 )
{
struct V_247 * V_248 = & F_209 ( V_250 ) ;
if ( V_248 -> V_251 != V_4 ) {
F_211 ( V_248 ) ;
V_248 -> V_251 = V_4 ;
}
V_248 -> V_82 += V_82 ;
F_210 ( V_250 ) ;
}
static void F_219 ( struct V_1 * V_147 , bool V_226 )
{
int V_72 , V_259 ;
F_69 () ;
V_259 = F_220 () ;
F_70 (cpu) {
struct V_247 * V_248 = & F_71 ( V_250 , V_72 ) ;
struct V_1 * V_4 ;
V_4 = V_248 -> V_251 ;
if ( ! V_4 || ! V_248 -> V_82 )
continue;
if ( ! F_123 ( V_147 , V_4 ) )
continue;
if ( ! F_221 ( V_257 , & V_248 -> V_171 ) ) {
if ( V_72 == V_259 )
F_213 ( & V_248 -> V_258 ) ;
else
F_222 ( V_72 , & V_248 -> V_258 ) ;
}
}
F_223 () ;
if ( ! V_226 )
goto V_140;
F_70 (cpu) {
struct V_247 * V_248 = & F_71 ( V_250 , V_72 ) ;
if ( F_5 ( V_257 , & V_248 -> V_171 ) )
F_224 ( & V_248 -> V_258 ) ;
}
V_140:
F_73 () ;
}
static void F_172 ( struct V_1 * V_147 )
{
if ( ! F_225 ( & V_260 ) )
return;
F_219 ( V_147 , false ) ;
F_226 ( & V_260 ) ;
}
static void F_227 ( struct V_1 * V_147 )
{
F_228 ( & V_260 ) ;
F_219 ( V_147 , true ) ;
F_226 ( & V_260 ) ;
}
static void F_229 ( struct V_1 * V_4 , int V_72 )
{
int V_177 ;
F_58 ( & V_4 -> V_75 ) ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
long V_261 = F_71 ( V_4 -> V_73 -> V_74 [ V_177 ] , V_72 ) ;
F_71 ( V_4 -> V_73 -> V_74 [ V_177 ] , V_72 ) = 0 ;
V_4 -> V_76 . V_74 [ V_177 ] += V_261 ;
}
for ( V_177 = 0 ; V_177 < V_262 ; V_177 ++ ) {
unsigned long V_261 = F_71 ( V_4 -> V_73 -> V_80 [ V_177 ] , V_72 ) ;
F_71 ( V_4 -> V_73 -> V_80 [ V_177 ] , V_72 ) = 0 ;
V_4 -> V_76 . V_80 [ V_177 ] += V_261 ;
}
F_59 ( & V_4 -> V_75 ) ;
}
static int F_230 ( struct V_263 * V_264 ,
unsigned long V_265 ,
void * V_266 )
{
int V_72 = ( unsigned long ) V_266 ;
struct V_247 * V_248 ;
struct V_1 * V_123 ;
if ( V_265 == V_267 )
return V_268 ;
if ( V_265 != V_269 && V_265 != V_270 )
return V_268 ;
F_231 (iter)
F_229 ( V_123 , V_72 ) ;
V_248 = & F_71 ( V_250 , V_72 ) ;
F_211 ( V_248 ) ;
return V_268 ;
}
static int F_232 ( struct V_1 * V_4 , T_4 V_187 ,
unsigned int V_82 , unsigned int V_271 ,
bool V_272 )
{
unsigned long V_273 = V_82 * V_254 ;
struct V_1 * V_274 ;
struct V_275 * V_276 ;
unsigned long V_171 = 0 ;
int V_94 ;
V_94 = F_233 ( & V_4 -> V_62 , V_273 , & V_276 ) ;
if ( F_234 ( ! V_94 ) ) {
if ( ! V_158 )
return V_277 ;
V_94 = F_233 ( & V_4 -> V_159 , V_273 , & V_276 ) ;
if ( F_234 ( ! V_94 ) )
return V_277 ;
F_212 ( & V_4 -> V_62 , V_273 ) ;
V_274 = F_235 ( V_276 , V_159 ) ;
V_171 |= V_205 ;
} else
V_274 = F_235 ( V_276 , V_62 ) ;
if ( V_82 > V_271 )
return V_278 ;
if ( ! ( V_187 & V_279 ) )
return V_280 ;
if ( V_187 & V_281 )
return V_282 ;
V_94 = F_171 ( V_274 , V_187 , V_171 ) ;
if ( F_129 ( V_274 ) >= V_82 )
return V_278 ;
if ( V_82 <= ( 1 << V_283 ) && V_94 )
return V_278 ;
if ( F_141 ( V_274 ) )
return V_278 ;
if ( V_272 )
F_201 ( V_274 , V_187 , F_236 ( V_273 ) ) ;
return V_282 ;
}
static int F_237 ( struct V_112 * V_113 ,
T_4 V_187 ,
unsigned int V_82 ,
struct V_1 * * V_284 ,
bool V_285 )
{
unsigned int V_286 = F_238 ( V_249 , V_82 ) ;
int V_287 = V_288 ;
struct V_1 * V_4 = NULL ;
int V_94 ;
if ( F_94 ( F_239 ( V_194 )
|| F_160 ( V_29 ) ) )
goto V_289;
if ( F_94 ( F_240 ( V_29 ) ) )
goto V_290;
if ( V_187 & V_291 )
V_285 = false ;
if ( ! * V_284 && ! V_113 )
* V_284 = V_17 ;
V_246:
if ( * V_284 ) {
V_4 = * V_284 ;
if ( F_20 ( V_4 ) )
goto V_68;
if ( F_208 ( V_4 , V_82 ) )
goto V_68;
F_26 ( & V_4 -> V_15 ) ;
} else {
struct V_110 * V_51 ;
F_27 () ;
V_51 = F_99 ( V_113 -> V_114 ) ;
V_4 = F_28 ( V_51 ) ;
if ( ! V_4 )
V_4 = V_17 ;
if ( F_20 ( V_4 ) ) {
F_31 () ;
goto V_68;
}
if ( F_208 ( V_4 , V_82 ) ) {
F_31 () ;
goto V_68;
}
if ( ! F_30 ( & V_4 -> V_15 ) ) {
F_31 () ;
goto V_246;
}
F_31 () ;
}
do {
bool V_272 = V_285 && ! V_287 ;
if ( F_160 ( V_29 ) ) {
F_34 ( & V_4 -> V_15 ) ;
goto V_289;
}
V_94 = F_232 ( V_4 , V_187 , V_286 ,
V_82 , V_272 ) ;
switch ( V_94 ) {
case V_277 :
break;
case V_278 :
V_286 = V_82 ;
F_34 ( & V_4 -> V_15 ) ;
V_4 = NULL ;
goto V_246;
case V_280 :
F_34 ( & V_4 -> V_15 ) ;
goto V_290;
case V_282 :
if ( ! V_285 || V_272 ) {
F_34 ( & V_4 -> V_15 ) ;
goto V_290;
}
V_287 -- ;
break;
}
} while ( V_94 != V_277 );
if ( V_286 > V_82 )
F_218 ( V_4 , V_286 - V_82 ) ;
F_34 ( & V_4 -> V_15 ) ;
V_68:
* V_284 = V_4 ;
return 0 ;
V_290:
if ( ! ( V_187 & V_291 ) ) {
* V_284 = NULL ;
return - V_292 ;
}
V_289:
* V_284 = V_17 ;
return - V_293 ;
}
static void F_241 ( struct V_1 * V_4 ,
unsigned int V_82 )
{
if ( ! F_20 ( V_4 ) ) {
unsigned long V_253 = V_82 * V_254 ;
F_212 ( & V_4 -> V_62 , V_253 ) ;
if ( V_158 )
F_212 ( & V_4 -> V_159 , V_253 ) ;
}
}
static void F_242 ( struct V_1 * V_4 ,
unsigned int V_82 )
{
unsigned long V_253 = V_82 * V_254 ;
if ( F_20 ( V_4 ) )
return;
F_243 ( & V_4 -> V_62 , V_4 -> V_62 . V_53 , V_253 ) ;
if ( V_158 )
F_243 ( & V_4 -> V_159 ,
V_4 -> V_159 . V_53 , V_253 ) ;
}
static struct V_1 * F_244 ( unsigned short V_20 )
{
if ( ! V_20 )
return NULL ;
return F_22 ( V_20 ) ;
}
struct V_1 * F_245 ( struct V_42 * V_42 )
{
struct V_1 * V_4 = NULL ;
struct V_145 * V_146 ;
unsigned short V_20 ;
T_7 V_294 ;
F_44 ( ! F_246 ( V_42 ) ) ;
V_146 = F_117 ( V_42 ) ;
F_247 ( V_146 ) ;
if ( F_119 ( V_146 ) ) {
V_4 = V_146 -> V_1 ;
if ( V_4 && ! F_30 ( & V_4 -> V_15 ) )
V_4 = NULL ;
} else if ( F_248 ( V_42 ) ) {
V_294 . V_71 = F_249 ( V_42 ) ;
V_20 = F_250 ( V_294 ) ;
F_27 () ;
V_4 = F_244 ( V_20 ) ;
if ( V_4 && ! F_30 ( & V_4 -> V_15 ) )
V_4 = NULL ;
F_31 () ;
}
F_251 ( V_146 ) ;
return V_4 ;
}
static void F_252 ( struct V_1 * V_4 ,
struct V_42 * V_42 ,
unsigned int V_82 ,
enum V_295 V_296 ,
bool V_297 )
{
struct V_145 * V_146 = F_117 ( V_42 ) ;
struct V_64 * V_133 ( V_64 ) ;
struct V_89 * V_89 ;
bool V_298 = false ;
bool V_81 ;
F_247 ( V_146 ) ;
F_44 ( F_119 ( V_146 ) ) ;
if ( V_297 ) {
V_64 = F_253 ( V_42 ) ;
F_254 ( & V_64 -> V_299 ) ;
if ( F_118 ( V_42 ) ) {
V_89 = F_115 ( V_64 , V_146 -> V_1 ) ;
F_255 ( V_42 ) ;
F_256 ( V_42 , V_89 , F_257 ( V_42 ) ) ;
V_298 = true ;
}
}
V_146 -> V_1 = V_4 ;
F_10 () ;
F_258 ( V_146 ) ;
if ( V_297 ) {
if ( V_298 ) {
V_89 = F_115 ( V_64 , V_146 -> V_1 ) ;
F_44 ( F_118 ( V_42 ) ) ;
F_259 ( V_42 ) ;
F_260 ( V_42 , V_89 , F_257 ( V_42 ) ) ;
}
F_261 ( & V_64 -> V_299 ) ;
}
if ( V_296 == V_300 )
V_81 = true ;
else
V_81 = false ;
F_77 ( V_4 , V_42 , V_81 , V_82 ) ;
F_251 ( V_146 ) ;
F_93 ( V_4 , V_42 ) ;
}
static inline bool F_262 ( struct V_1 * V_4 )
{
return ! F_108 () && ! F_20 ( V_4 ) &&
( V_4 -> V_6 & V_301 ) ;
}
static struct V_302 * F_263 ( struct V_303 * V_51 )
{
struct V_302 * V_304 ;
F_44 ( V_51 -> V_305 ) ;
V_304 = V_51 -> V_306 ;
return F_264 ( V_304 , F_265 ( V_51 -> V_4 ) ) ;
}
static int F_266 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_309 * V_310 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_303 * V_311 ;
if ( ! F_262 ( V_4 ) )
return - V_312 ;
F_267 ( V_310 ) ;
F_228 ( & V_4 -> V_313 ) ;
F_268 (params, &memcg->memcg_slab_caches, list)
F_269 ( F_263 ( V_311 ) , V_310 ) ;
F_226 ( & V_4 -> V_313 ) ;
return 0 ;
}
static int F_270 ( struct V_1 * V_4 , T_4 V_314 , T_2 V_315 )
{
struct V_275 * V_276 ;
struct V_1 * V_316 ;
int V_94 = 0 ;
V_94 = F_233 ( & V_4 -> V_35 , V_315 , & V_276 ) ;
if ( V_94 )
return V_94 ;
V_316 = V_4 ;
V_94 = F_237 ( NULL , V_314 , V_315 >> V_156 ,
& V_316 , F_271 ( V_314 ) ) ;
if ( V_94 == - V_293 ) {
F_272 ( & V_4 -> V_62 , V_315 , & V_276 ) ;
if ( V_158 )
F_272 ( & V_4 -> V_159 , V_315 ,
& V_276 ) ;
V_94 = 0 ;
} else if ( V_94 )
F_212 ( & V_4 -> V_35 , V_315 ) ;
return V_94 ;
}
static void F_273 ( struct V_1 * V_4 , T_2 V_315 )
{
F_212 ( & V_4 -> V_62 , V_315 ) ;
if ( V_158 )
F_212 ( & V_4 -> V_159 , V_315 ) ;
if ( F_212 ( & V_4 -> V_35 , V_315 ) )
return;
if ( F_11 ( V_4 ) )
F_34 ( & V_4 -> V_15 ) ;
}
void F_274 ( struct V_1 * V_4 , struct V_302 * V_304 )
{
if ( ! V_4 )
return;
F_228 ( & V_4 -> V_313 ) ;
F_275 ( & V_304 -> V_317 -> V_318 , & V_4 -> V_319 ) ;
F_226 ( & V_4 -> V_313 ) ;
}
int F_265 ( struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_34 : - 1 ;
}
int F_276 ( struct V_1 * V_4 )
{
int V_184 , V_94 ;
V_184 = F_277 ( & V_33 ,
0 , V_320 , V_321 ) ;
if ( V_184 < 0 )
return V_184 ;
F_6 ( V_4 ) ;
V_94 = F_278 ( V_184 + 1 ) ;
if ( V_94 ) {
F_40 ( & V_33 , V_184 ) ;
F_7 ( V_4 ) ;
return V_94 ;
}
V_4 -> V_34 = V_184 ;
F_203 ( & V_4 -> V_319 ) ;
F_279 ( & V_4 -> V_313 ) ;
return 0 ;
}
static T_1 F_280 ( int V_322 )
{
T_8 V_315 ;
if ( V_322 <= 0 )
return 0 ;
V_315 = 2 * V_322 ;
if ( V_315 < V_323 )
V_315 = V_323 ;
else if ( V_315 > V_320 )
V_315 = V_320 ;
return V_315 ;
}
void F_281 ( int V_184 )
{
if ( V_184 > V_324 )
V_324 = F_280 ( V_184 ) ;
}
int F_282 ( struct V_302 * V_14 , int V_322 )
{
struct V_303 * V_325 = V_14 -> V_317 ;
F_44 ( ! V_305 ( V_14 ) ) ;
if ( V_322 > V_324 ) {
int V_177 ;
T_8 V_315 = F_280 ( V_322 ) ;
V_315 *= sizeof( void * ) ;
V_315 += F_283 ( struct V_303 , V_326 ) ;
V_14 -> V_317 = F_284 ( V_315 , V_321 ) ;
if ( ! V_14 -> V_317 ) {
V_14 -> V_317 = V_325 ;
return - V_292 ;
}
V_14 -> V_317 -> V_305 = true ;
for ( V_177 = 0 ; V_177 < V_324 ; V_177 ++ ) {
if ( ! V_325 -> V_326 [ V_177 ] )
continue;
V_14 -> V_317 -> V_326 [ V_177 ] =
V_325 -> V_326 [ V_177 ] ;
}
F_285 ( V_325 ) ;
}
return 0 ;
}
int F_286 ( struct V_1 * V_4 , struct V_302 * V_14 ,
struct V_302 * V_306 )
{
T_1 V_315 ;
if ( ! F_287 () )
return 0 ;
if ( ! V_4 ) {
V_315 = F_283 ( struct V_303 , V_326 ) ;
V_315 += V_324 * sizeof( void * ) ;
} else
V_315 = sizeof( struct V_303 ) ;
V_14 -> V_317 = F_284 ( V_315 , V_321 ) ;
if ( ! V_14 -> V_317 )
return - V_292 ;
if ( V_4 ) {
V_14 -> V_317 -> V_4 = V_4 ;
V_14 -> V_317 -> V_306 = V_306 ;
F_217 ( & V_14 -> V_317 -> V_327 ,
V_328 ) ;
} else
V_14 -> V_317 -> V_305 = true ;
return 0 ;
}
void F_288 ( struct V_302 * V_14 )
{
struct V_302 * V_115 ;
struct V_1 * V_4 ;
int V_20 ;
if ( ! V_14 -> V_317 )
return;
if ( V_14 -> V_317 -> V_305 )
goto V_140;
V_4 = V_14 -> V_317 -> V_4 ;
V_20 = F_265 ( V_4 ) ;
V_115 = V_14 -> V_317 -> V_306 ;
V_115 -> V_317 -> V_326 [ V_20 ] = NULL ;
F_228 ( & V_4 -> V_313 ) ;
F_289 ( & V_14 -> V_317 -> V_318 ) ;
F_226 ( & V_4 -> V_313 ) ;
F_34 ( & V_4 -> V_15 ) ;
V_140:
F_285 ( V_14 -> V_317 ) ;
}
static inline void F_290 ( void )
{
F_44 ( ! V_29 -> V_113 ) ;
V_29 -> V_329 ++ ;
}
static inline void F_291 ( void )
{
F_44 ( ! V_29 -> V_113 ) ;
V_29 -> V_329 -- ;
}
static void V_328 ( struct V_255 * V_330 )
{
struct V_302 * V_304 ;
struct V_303 * V_51 ;
V_51 = F_16 ( V_330 , struct V_303 , V_327 ) ;
V_304 = F_263 ( V_51 ) ;
if ( F_104 ( & V_304 -> V_317 -> V_82 ) != 0 ) {
F_292 ( V_304 ) ;
if ( F_104 ( & V_304 -> V_317 -> V_82 ) == 0 )
return;
} else
F_293 ( V_304 ) ;
}
void F_294 ( struct V_302 * V_304 )
{
if ( ! V_304 -> V_317 -> V_331 )
return;
if ( F_295 ( & V_304 -> V_317 -> V_327 ) )
return;
F_296 ( & V_304 -> V_317 -> V_327 ) ;
}
static struct V_302 * F_297 ( struct V_1 * V_4 ,
struct V_302 * V_14 )
{
struct V_302 * V_332 ;
static char * V_333 = NULL ;
F_298 ( & V_334 ) ;
if ( ! V_333 ) {
V_333 = F_299 ( V_176 , V_321 ) ;
if ( ! V_333 )
return NULL ;
}
F_27 () ;
snprintf ( V_333 , V_176 , L_13 , V_14 -> V_335 ,
F_265 ( V_4 ) , F_300 ( V_4 -> V_15 . V_19 ) ) ;
F_31 () ;
V_332 = F_301 ( V_4 , V_333 , V_14 -> V_336 , V_14 -> V_337 ,
( V_14 -> V_171 & ~ V_338 ) , V_14 -> V_339 , V_14 ) ;
if ( V_332 )
V_332 -> V_340 |= V_341 ;
return V_332 ;
}
static struct V_302 * F_302 ( struct V_1 * V_4 ,
struct V_302 * V_304 )
{
struct V_302 * V_342 ;
int V_70 ;
F_25 ( ! F_262 ( V_4 ) ) ;
V_70 = F_265 ( V_4 ) ;
F_228 ( & V_334 ) ;
V_342 = F_264 ( V_304 , V_70 ) ;
if ( V_342 ) {
F_34 ( & V_4 -> V_15 ) ;
goto V_140;
}
V_342 = F_297 ( V_4 , V_304 ) ;
if ( V_342 == NULL ) {
V_342 = V_304 ;
F_34 ( & V_4 -> V_15 ) ;
goto V_140;
}
F_179 ( & V_342 -> V_317 -> V_82 , 0 ) ;
V_304 -> V_317 -> V_326 [ V_70 ] = V_342 ;
F_303 () ;
V_140:
F_226 ( & V_334 ) ;
return V_342 ;
}
void F_304 ( struct V_302 * V_14 )
{
struct V_302 * V_343 ;
int V_177 ;
if ( ! V_14 -> V_317 )
return;
if ( ! V_14 -> V_317 -> V_305 )
return;
F_228 ( & V_344 ) ;
F_305 (i) {
V_343 = F_264 ( V_14 , V_177 ) ;
if ( ! V_343 )
continue;
V_343 -> V_317 -> V_331 = false ;
F_306 ( & V_343 -> V_317 -> V_327 ) ;
F_293 ( V_343 ) ;
}
F_226 ( & V_344 ) ;
}
static void F_307 ( struct V_1 * V_4 )
{
struct V_302 * V_304 ;
struct V_303 * V_311 ;
if ( ! F_4 ( V_4 ) )
return;
F_228 ( & V_4 -> V_313 ) ;
F_268 (params, &memcg->memcg_slab_caches, list) {
V_304 = F_263 ( V_311 ) ;
V_304 -> V_317 -> V_331 = true ;
F_296 ( & V_304 -> V_317 -> V_327 ) ;
}
F_226 ( & V_4 -> V_313 ) ;
}
static void F_308 ( struct V_255 * V_330 )
{
struct V_345 * V_346 ;
V_346 = F_16 ( V_330 , struct V_345 , V_258 ) ;
F_302 ( V_346 -> V_4 , V_346 -> V_304 ) ;
F_285 ( V_346 ) ;
}
static void F_309 ( struct V_1 * V_4 ,
struct V_302 * V_304 )
{
struct V_345 * V_346 ;
V_346 = F_299 ( sizeof( struct V_345 ) , V_347 ) ;
if ( V_346 == NULL ) {
F_34 ( & V_4 -> V_15 ) ;
return;
}
V_346 -> V_4 = V_4 ;
V_346 -> V_304 = V_304 ;
F_217 ( & V_346 -> V_258 , F_308 ) ;
F_296 ( & V_346 -> V_258 ) ;
}
static void F_310 ( struct V_1 * V_4 ,
struct V_302 * V_304 )
{
F_290 () ;
F_309 ( V_4 , V_304 ) ;
F_291 () ;
}
struct V_302 * F_311 ( struct V_302 * V_304 ,
T_4 V_314 )
{
struct V_1 * V_4 ;
int V_70 ;
F_44 ( ! V_304 -> V_317 ) ;
F_44 ( ! V_304 -> V_317 -> V_305 ) ;
if ( ! V_29 -> V_113 || V_29 -> V_329 )
return V_304 ;
F_27 () ;
V_4 = F_28 ( F_99 ( V_29 -> V_113 -> V_114 ) ) ;
if ( ! F_262 ( V_4 ) )
goto V_140;
V_70 = F_265 ( V_4 ) ;
F_312 () ;
if ( F_234 ( F_264 ( V_304 , V_70 ) ) ) {
V_304 = F_264 ( V_304 , V_70 ) ;
goto V_140;
}
if ( ! F_30 ( & V_4 -> V_15 ) )
goto V_140;
F_31 () ;
F_310 ( V_4 , V_304 ) ;
return V_304 ;
V_140:
F_31 () ;
return V_304 ;
}
bool
F_313 ( T_4 V_314 , struct V_1 * * V_316 , int V_188 )
{
struct V_1 * V_4 ;
int V_94 ;
* V_316 = NULL ;
if ( ! V_29 -> V_113 || V_29 -> V_329 )
return true ;
V_4 = F_98 ( V_29 -> V_113 ) ;
if ( F_94 ( ! V_4 ) )
return true ;
if ( ! F_262 ( V_4 ) ) {
F_34 ( & V_4 -> V_15 ) ;
return true ;
}
V_94 = F_270 ( V_4 , V_314 , V_254 << V_188 ) ;
if ( ! V_94 )
* V_316 = V_4 ;
F_34 ( & V_4 -> V_15 ) ;
return ( V_94 == 0 ) ;
}
void F_314 ( struct V_42 * V_42 , struct V_1 * V_4 ,
int V_188 )
{
struct V_145 * V_146 ;
F_44 ( F_20 ( V_4 ) ) ;
if ( ! V_42 ) {
F_273 ( V_4 , V_254 << V_188 ) ;
return;
}
V_146 = F_117 ( V_42 ) ;
F_247 ( V_146 ) ;
V_146 -> V_1 = V_4 ;
F_258 ( V_146 ) ;
F_251 ( V_146 ) ;
}
void F_315 ( struct V_42 * V_42 , int V_188 )
{
struct V_1 * V_4 = NULL ;
struct V_145 * V_146 ;
V_146 = F_117 ( V_42 ) ;
if ( ! F_119 ( V_146 ) )
return;
F_247 ( V_146 ) ;
if ( F_119 ( V_146 ) ) {
V_4 = V_146 -> V_1 ;
F_316 ( V_146 ) ;
}
F_251 ( V_146 ) ;
if ( ! V_4 )
return;
F_44 ( F_20 ( V_4 ) ) ;
F_273 ( V_4 , V_254 << V_188 ) ;
}
static inline void F_307 ( struct V_1 * V_4 )
{
}
void F_317 ( struct V_42 * V_348 )
{
struct V_145 * V_349 = F_117 ( V_348 ) ;
struct V_145 * V_146 ;
struct V_1 * V_4 ;
int V_177 ;
if ( F_108 () )
return;
V_4 = V_349 -> V_1 ;
for ( V_177 = 1 ; V_177 < V_350 ; V_177 ++ ) {
V_146 = V_349 + V_177 ;
V_146 -> V_1 = V_4 ;
F_10 () ;
V_146 -> V_171 = V_349 -> V_171 & ~ V_351 ;
}
F_318 ( V_4 -> V_73 -> V_74 [ V_85 ] ,
V_350 ) ;
}
static inline
void F_319 ( struct V_1 * V_164 ,
struct V_1 * V_165 ,
unsigned int V_82 ,
enum V_69 V_70 )
{
F_78 () ;
F_318 ( V_164 -> V_73 -> V_74 [ V_70 ] , V_82 ) ;
F_79 ( V_165 -> V_73 -> V_74 [ V_70 ] , V_82 ) ;
F_82 () ;
}
static int F_320 ( struct V_42 * V_42 ,
unsigned int V_82 ,
struct V_145 * V_146 ,
struct V_1 * V_164 ,
struct V_1 * V_165 )
{
unsigned long V_171 ;
int V_94 ;
bool V_81 = F_321 ( V_42 ) ;
F_44 ( V_164 == V_165 ) ;
F_44 ( F_118 ( V_42 ) ) ;
V_94 = - V_352 ;
if ( V_82 > 1 && ! F_80 ( V_42 ) )
goto V_140;
F_247 ( V_146 ) ;
V_94 = - V_353 ;
if ( ! F_119 ( V_146 ) || V_146 -> V_1 != V_164 )
goto V_166;
F_146 ( V_164 , & V_171 ) ;
if ( ! V_81 && F_322 ( V_42 ) )
F_319 ( V_164 , V_165 , V_82 ,
V_354 ) ;
if ( F_323 ( V_42 ) )
F_319 ( V_164 , V_165 , V_82 ,
V_355 ) ;
F_77 ( V_164 , V_42 , V_81 , - V_82 ) ;
V_146 -> V_1 = V_165 ;
F_77 ( V_165 , V_42 , V_81 , V_82 ) ;
F_148 ( V_164 , & V_171 ) ;
V_94 = 0 ;
V_166:
F_251 ( V_146 ) ;
F_93 ( V_165 , V_42 ) ;
F_93 ( V_164 , V_42 ) ;
V_140:
return V_94 ;
}
static int F_324 ( struct V_42 * V_42 ,
struct V_145 * V_146 ,
struct V_1 * V_356 )
{
struct V_1 * V_53 ;
unsigned int V_82 ;
unsigned long V_133 ( V_171 ) ;
int V_94 ;
F_44 ( F_20 ( V_356 ) ) ;
V_94 = - V_352 ;
if ( ! F_325 ( V_42 ) )
goto V_140;
if ( F_326 ( V_42 ) )
goto V_357;
V_82 = F_327 ( V_42 ) ;
V_53 = F_61 ( V_356 ) ;
if ( ! V_53 )
V_53 = V_17 ;
if ( V_82 > 1 ) {
F_44 ( ! F_80 ( V_42 ) ) ;
V_171 = F_328 ( V_42 ) ;
}
V_94 = F_320 ( V_42 , V_82 ,
V_146 , V_356 , V_53 ) ;
if ( ! V_94 )
F_242 ( V_356 , V_82 ) ;
if ( V_82 > 1 )
F_329 ( V_42 , V_171 ) ;
F_330 ( V_42 ) ;
V_357:
F_331 ( V_42 ) ;
V_140:
return V_94 ;
}
static int F_332 ( struct V_42 * V_42 , struct V_112 * V_113 ,
T_4 V_187 , enum V_295 V_296 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_82 = 1 ;
bool V_285 = true ;
int V_94 ;
if ( F_80 ( V_42 ) ) {
V_82 <<= F_333 ( V_42 ) ;
F_44 ( ! F_80 ( V_42 ) ) ;
V_285 = false ;
}
V_94 = F_237 ( V_113 , V_187 , V_82 , & V_4 , V_285 ) ;
if ( V_94 == - V_292 )
return V_94 ;
F_252 ( V_4 , V_42 , V_82 , V_296 , false ) ;
return 0 ;
}
int F_334 ( struct V_42 * V_42 ,
struct V_112 * V_113 , T_4 V_187 )
{
if ( F_108 () )
return 0 ;
F_44 ( F_322 ( V_42 ) ) ;
F_44 ( V_42 -> V_358 && ! F_321 ( V_42 ) ) ;
F_44 ( ! V_113 ) ;
return F_332 ( V_42 , V_113 , V_187 ,
V_300 ) ;
}
static int F_335 ( struct V_112 * V_113 ,
struct V_42 * V_42 ,
T_4 V_234 ,
struct V_1 * * V_359 )
{
struct V_1 * V_4 ;
struct V_145 * V_146 ;
int V_94 ;
V_146 = F_117 ( V_42 ) ;
if ( F_119 ( V_146 ) )
return 0 ;
if ( ! V_158 )
goto V_360;
V_4 = F_245 ( V_42 ) ;
if ( ! V_4 )
goto V_360;
* V_359 = V_4 ;
V_94 = F_237 ( NULL , V_234 , 1 , V_359 , true ) ;
F_34 ( & V_4 -> V_15 ) ;
if ( V_94 == - V_293 )
V_94 = 0 ;
return V_94 ;
V_360:
V_94 = F_237 ( V_113 , V_234 , 1 , V_359 , true ) ;
if ( V_94 == - V_293 )
V_94 = 0 ;
return V_94 ;
}
int F_336 ( struct V_112 * V_113 , struct V_42 * V_42 ,
T_4 V_187 , struct V_1 * * V_359 )
{
* V_359 = NULL ;
if ( F_108 () )
return 0 ;
if ( ! F_248 ( V_42 ) ) {
int V_94 ;
V_94 = F_237 ( V_113 , V_187 , 1 , V_359 , true ) ;
if ( V_94 == - V_293 )
V_94 = 0 ;
return V_94 ;
}
return F_335 ( V_113 , V_42 , V_187 , V_359 ) ;
}
void F_337 ( struct V_1 * V_4 )
{
if ( F_108 () )
return;
if ( ! V_4 )
return;
F_241 ( V_4 , 1 ) ;
}
static void
F_338 ( struct V_42 * V_42 , struct V_1 * V_4 ,
enum V_295 V_296 )
{
if ( F_108 () )
return;
if ( ! V_4 )
return;
F_252 ( V_4 , V_42 , 1 , V_296 , true ) ;
if ( V_158 && F_248 ( V_42 ) ) {
T_7 V_294 = { . V_71 = F_249 (page) } ;
F_339 ( V_294 ) ;
}
}
void F_340 ( struct V_42 * V_42 ,
struct V_1 * V_4 )
{
F_338 ( V_42 , V_4 ,
V_300 ) ;
}
int F_341 ( struct V_42 * V_42 , struct V_112 * V_113 ,
T_4 V_187 )
{
struct V_1 * V_4 = NULL ;
enum V_295 type = V_361 ;
int V_94 ;
if ( F_108 () )
return 0 ;
if ( F_342 ( V_42 ) )
return 0 ;
if ( ! F_248 ( V_42 ) )
V_94 = F_332 ( V_42 , V_113 , V_187 , type ) ;
else {
V_94 = F_335 ( V_113 , V_42 ,
V_187 , & V_4 ) ;
if ( ! V_94 )
F_338 ( V_42 , V_4 , type ) ;
}
return V_94 ;
}
static void F_343 ( struct V_1 * V_4 ,
unsigned int V_82 ,
const enum V_295 V_296 )
{
struct V_362 * V_286 = NULL ;
bool V_363 = true ;
if ( ! V_158 || V_296 == V_364 )
V_363 = false ;
V_286 = & V_29 -> V_365 ;
if ( ! V_286 -> V_4 )
V_286 -> V_4 = V_4 ;
if ( ! V_286 -> V_366 || F_239 ( V_194 ) )
goto V_367;
if ( V_82 > 1 )
goto V_367;
if ( V_286 -> V_4 != V_4 )
goto V_367;
V_286 -> V_82 ++ ;
if ( V_363 )
V_286 -> V_368 ++ ;
return;
V_367:
F_212 ( & V_4 -> V_62 , V_82 * V_254 ) ;
if ( V_363 )
F_212 ( & V_4 -> V_159 , V_82 * V_254 ) ;
if ( F_94 ( V_286 -> V_4 != V_4 ) )
F_200 ( V_4 ) ;
}
static struct V_1 *
F_344 ( struct V_42 * V_42 , enum V_295 V_296 ,
bool V_369 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_82 = 1 ;
struct V_145 * V_146 ;
bool V_81 ;
if ( F_108 () )
return NULL ;
if ( F_80 ( V_42 ) ) {
V_82 <<= F_333 ( V_42 ) ;
F_44 ( ! F_80 ( V_42 ) ) ;
}
V_146 = F_117 ( V_42 ) ;
if ( F_94 ( ! F_119 ( V_146 ) ) )
return NULL ;
F_247 ( V_146 ) ;
V_4 = V_146 -> V_1 ;
if ( ! F_119 ( V_146 ) )
goto V_370;
V_81 = F_321 ( V_42 ) ;
switch ( V_296 ) {
case V_300 :
V_81 = true ;
case V_371 :
if ( F_322 ( V_42 ) )
goto V_370;
if ( ! V_369 && F_345 ( V_146 ) )
goto V_370;
break;
case V_364 :
if ( ! F_321 ( V_42 ) ) {
if ( V_42 -> V_358 && ! F_346 ( V_42 ) )
goto V_370;
} else if ( F_322 ( V_42 ) )
goto V_370;
break;
default:
break;
}
F_77 ( V_4 , V_42 , V_81 , - V_82 ) ;
F_316 ( V_146 ) ;
F_251 ( V_146 ) ;
F_93 ( V_4 , V_42 ) ;
if ( V_158 && V_296 == V_364 ) {
F_74 ( V_4 , true ) ;
F_26 ( & V_4 -> V_15 ) ;
}
if ( ! V_369 && ! F_20 ( V_4 ) )
F_343 ( V_4 , V_82 , V_296 ) ;
return V_4 ;
V_370:
F_251 ( V_146 ) ;
return NULL ;
}
void F_347 ( struct V_42 * V_42 )
{
if ( F_322 ( V_42 ) )
return;
F_44 ( V_42 -> V_358 && ! F_321 ( V_42 ) ) ;
if ( F_248 ( V_42 ) )
return;
F_344 ( V_42 , V_300 , false ) ;
}
void F_348 ( struct V_42 * V_42 )
{
F_44 ( F_322 ( V_42 ) ) ;
F_44 ( V_42 -> V_358 ) ;
F_344 ( V_42 , V_361 , false ) ;
}
void F_349 ( void )
{
V_29 -> V_365 . V_366 ++ ;
if ( V_29 -> V_365 . V_366 == 1 ) {
V_29 -> V_365 . V_4 = NULL ;
V_29 -> V_365 . V_82 = 0 ;
V_29 -> V_365 . V_368 = 0 ;
}
}
void F_350 ( void )
{
struct V_362 * V_286 = & V_29 -> V_365 ;
if ( ! V_286 -> V_366 )
return;
V_286 -> V_366 -- ;
if ( V_286 -> V_366 )
return;
if ( ! V_286 -> V_4 )
return;
if ( V_286 -> V_82 )
F_212 ( & V_286 -> V_4 -> V_62 ,
V_286 -> V_82 * V_254 ) ;
if ( V_286 -> V_368 )
F_212 ( & V_286 -> V_4 -> V_159 ,
V_286 -> V_368 * V_254 ) ;
F_200 ( V_286 -> V_4 ) ;
V_286 -> V_4 = NULL ;
}
void
F_351 ( struct V_42 * V_42 , T_7 V_294 , bool V_372 )
{
struct V_1 * V_4 ;
int V_296 = V_364 ;
if ( ! V_372 )
V_296 = V_371 ;
V_4 = F_344 ( V_42 , V_296 , false ) ;
if ( V_158 && V_372 && V_4 )
F_352 ( V_294 , F_21 ( V_4 ) ) ;
}
void F_339 ( T_7 V_294 )
{
struct V_1 * V_4 ;
unsigned short V_20 ;
if ( ! V_158 )
return;
V_20 = F_352 ( V_294 , 0 ) ;
F_27 () ;
V_4 = F_244 ( V_20 ) ;
if ( V_4 ) {
if ( ! F_20 ( V_4 ) )
F_212 ( & V_4 -> V_159 , V_254 ) ;
F_74 ( V_4 , false ) ;
F_34 ( & V_4 -> V_15 ) ;
}
F_31 () ;
}
static int F_353 ( T_7 V_373 ,
struct V_1 * V_164 , struct V_1 * V_165 )
{
unsigned short V_374 , V_375 ;
V_374 = F_21 ( V_164 ) ;
V_375 = F_21 ( V_165 ) ;
if ( F_354 ( V_373 , V_374 , V_375 ) == V_374 ) {
F_74 ( V_164 , false ) ;
F_74 ( V_165 , true ) ;
F_26 ( & V_165 -> V_15 ) ;
return 0 ;
}
return - V_353 ;
}
static inline int F_353 ( T_7 V_373 ,
struct V_1 * V_164 , struct V_1 * V_165 )
{
return - V_353 ;
}
void F_355 ( struct V_42 * V_42 , struct V_42 * V_376 ,
struct V_1 * * V_359 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_82 = 1 ;
struct V_145 * V_146 ;
enum V_295 V_296 ;
* V_359 = NULL ;
if ( F_108 () )
return;
if ( F_80 ( V_42 ) )
V_82 <<= F_333 ( V_42 ) ;
V_146 = F_117 ( V_42 ) ;
F_247 ( V_146 ) ;
if ( F_119 ( V_146 ) ) {
V_4 = V_146 -> V_1 ;
F_26 ( & V_4 -> V_15 ) ;
if ( F_321 ( V_42 ) )
F_356 ( V_146 ) ;
}
F_251 ( V_146 ) ;
if ( ! V_4 )
return;
* V_359 = V_4 ;
if ( F_321 ( V_42 ) )
V_296 = V_300 ;
else
V_296 = V_361 ;
F_252 ( V_4 , V_376 , V_82 , V_296 , false ) ;
}
void F_357 ( struct V_1 * V_4 ,
struct V_42 * V_377 , struct V_42 * V_376 , bool V_378 )
{
struct V_42 * V_379 , * V_380 ;
struct V_145 * V_146 ;
bool V_81 ;
if ( ! V_4 )
return;
if ( ! V_378 ) {
V_379 = V_377 ;
V_380 = V_376 ;
} else {
V_379 = V_376 ;
V_380 = V_377 ;
}
V_81 = F_321 ( V_379 ) ;
F_344 ( V_380 ,
V_81 ? V_300
: V_361 ,
true ) ;
F_34 ( & V_4 -> V_15 ) ;
V_146 = F_117 ( V_377 ) ;
F_247 ( V_146 ) ;
F_358 ( V_146 ) ;
F_251 ( V_146 ) ;
if ( V_81 )
F_347 ( V_379 ) ;
}
void F_359 ( struct V_42 * V_377 ,
struct V_42 * V_376 )
{
struct V_1 * V_4 = NULL ;
struct V_145 * V_146 ;
enum V_295 type = V_361 ;
if ( F_108 () )
return;
V_146 = F_117 ( V_377 ) ;
F_247 ( V_146 ) ;
if ( F_119 ( V_146 ) ) {
V_4 = V_146 -> V_1 ;
F_77 ( V_4 , V_377 , false , - 1 ) ;
F_316 ( V_146 ) ;
}
F_251 ( V_146 ) ;
if ( ! V_4 )
return;
F_252 ( V_4 , V_376 , 1 , type , true ) ;
}
static struct V_145 * F_360 ( struct V_42 * V_42 )
{
struct V_145 * V_146 ;
V_146 = F_117 ( V_42 ) ;
if ( F_234 ( V_146 ) && F_119 ( V_146 ) )
return V_146 ;
return NULL ;
}
bool F_361 ( struct V_42 * V_42 )
{
if ( F_108 () )
return false ;
return F_360 ( V_42 ) != NULL ;
}
void F_362 ( struct V_42 * V_42 )
{
struct V_145 * V_146 ;
V_146 = F_360 ( V_42 ) ;
if ( V_146 ) {
F_363 ( L_14 ,
V_146 , V_146 -> V_171 , V_146 -> V_1 ) ;
}
}
static int F_364 ( struct V_1 * V_4 ,
unsigned long long V_71 )
{
int V_381 ;
T_2 V_382 , V_383 ;
int V_94 = 0 ;
int V_384 = F_157 ( V_4 ) ;
T_2 V_385 , V_386 ;
int V_387 ;
V_381 = V_288 * V_384 ;
V_386 = F_41 ( & V_4 -> V_62 , V_36 ) ;
V_387 = 0 ;
while ( V_381 ) {
if ( F_365 ( V_29 ) ) {
V_94 = - V_293 ;
break;
}
F_228 ( & V_344 ) ;
V_382 = F_41 ( & V_4 -> V_159 , V_178 ) ;
if ( V_382 < V_71 ) {
V_94 = - V_353 ;
F_226 ( & V_344 ) ;
break;
}
V_383 = F_41 ( & V_4 -> V_62 , V_178 ) ;
if ( V_383 < V_71 )
V_387 = 1 ;
V_94 = F_366 ( & V_4 -> V_62 , V_71 ) ;
if ( ! V_94 ) {
if ( V_382 == V_71 )
V_4 -> V_207 = true ;
else
V_4 -> V_207 = false ;
}
F_226 ( & V_344 ) ;
if ( ! V_94 )
break;
F_171 ( V_4 , V_321 ,
V_206 ) ;
V_385 = F_41 ( & V_4 -> V_62 , V_36 ) ;
if ( V_385 >= V_386 )
V_381 -- ;
else
V_386 = V_385 ;
}
if ( ! V_94 && V_387 )
F_200 ( V_4 ) ;
return V_94 ;
}
static int F_367 ( struct V_1 * V_4 ,
unsigned long long V_71 )
{
int V_381 ;
T_2 V_383 , V_382 , V_386 , V_385 ;
int V_384 = F_157 ( V_4 ) ;
int V_94 = - V_352 ;
int V_387 = 0 ;
V_381 = V_384 * V_288 ;
V_386 = F_41 ( & V_4 -> V_159 , V_36 ) ;
while ( V_381 ) {
if ( F_365 ( V_29 ) ) {
V_94 = - V_293 ;
break;
}
F_228 ( & V_344 ) ;
V_383 = F_41 ( & V_4 -> V_62 , V_178 ) ;
if ( V_383 > V_71 ) {
V_94 = - V_353 ;
F_226 ( & V_344 ) ;
break;
}
V_382 = F_41 ( & V_4 -> V_159 , V_178 ) ;
if ( V_382 < V_71 )
V_387 = 1 ;
V_94 = F_366 ( & V_4 -> V_159 , V_71 ) ;
if ( ! V_94 ) {
if ( V_383 == V_71 )
V_4 -> V_207 = true ;
else
V_4 -> V_207 = false ;
}
F_226 ( & V_344 ) ;
if ( ! V_94 )
break;
F_171 ( V_4 , V_321 ,
V_205 |
V_206 ) ;
V_385 = F_41 ( & V_4 -> V_159 , V_36 ) ;
if ( V_385 >= V_386 )
V_381 -- ;
else
V_386 = V_385 ;
}
if ( ! V_94 && V_387 )
F_200 ( V_4 ) ;
return V_94 ;
}
unsigned long F_368 ( struct V_64 * V_64 , int V_188 ,
T_4 V_187 ,
unsigned long * V_216 )
{
unsigned long V_388 = 0 ;
struct V_37 * V_47 , * V_389 = NULL ;
unsigned long V_390 ;
int V_204 = 0 ;
struct V_43 * V_48 ;
unsigned long long V_61 ;
unsigned long V_218 ;
if ( V_188 > 0 )
return 0 ;
V_48 = F_49 ( F_109 ( V_64 ) , F_110 ( V_64 ) ) ;
do {
if ( V_389 )
V_47 = V_389 ;
else
V_47 = F_67 ( V_48 ) ;
if ( ! V_47 )
break;
V_218 = 0 ;
V_390 = F_187 ( V_47 -> V_4 , V_64 ,
V_187 , & V_218 ) ;
V_388 += V_390 ;
* V_216 += V_218 ;
F_58 ( & V_48 -> V_60 ) ;
V_389 = NULL ;
if ( ! V_390 ) {
do {
V_389 =
F_65 ( V_48 ) ;
if ( V_389 == V_47 )
F_34 ( & V_389 -> V_4 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_55 ( V_47 -> V_4 , V_47 , V_48 ) ;
V_61 = F_62 ( & V_47 -> V_4 -> V_62 ) ;
F_51 ( V_47 -> V_4 , V_47 , V_48 , V_61 ) ;
F_59 ( & V_48 -> V_60 ) ;
F_34 ( & V_47 -> V_4 -> V_15 ) ;
V_204 ++ ;
if ( ! V_388 &&
( V_389 == NULL ||
V_204 > V_391 ) )
break;
} while ( ! V_388 );
if ( V_389 )
F_34 ( & V_389 -> V_4 -> V_15 ) ;
return V_388 ;
}
static void F_369 ( struct V_1 * V_4 ,
int V_63 , int V_39 , enum V_90 V_91 )
{
struct V_89 * V_89 ;
unsigned long V_171 ;
struct V_392 * V_318 ;
struct V_42 * V_393 ;
struct V_64 * V_64 ;
V_64 = & F_370 ( V_63 ) -> V_394 [ V_39 ] ;
V_89 = F_115 ( V_64 , V_4 ) ;
V_318 = & V_89 -> V_395 [ V_91 ] ;
V_393 = NULL ;
do {
struct V_145 * V_146 ;
struct V_42 * V_42 ;
F_147 ( & V_64 -> V_299 , V_171 ) ;
if ( F_371 ( V_318 ) ) {
F_149 ( & V_64 -> V_299 , V_171 ) ;
break;
}
V_42 = F_372 ( V_318 -> V_128 , struct V_42 , V_91 ) ;
if ( V_393 == V_42 ) {
F_373 ( & V_42 -> V_91 , V_318 ) ;
V_393 = NULL ;
F_149 ( & V_64 -> V_299 , V_171 ) ;
continue;
}
F_149 ( & V_64 -> V_299 , V_171 ) ;
V_146 = F_117 ( V_42 ) ;
if ( F_324 ( V_42 , V_146 , V_4 ) ) {
V_393 = V_42 ;
F_374 () ;
} else
V_393 = NULL ;
} while ( ! F_371 ( V_318 ) );
}
static void F_375 ( struct V_1 * V_4 )
{
int V_63 , V_39 ;
T_2 V_396 ;
do {
F_376 () ;
F_227 ( V_4 ) ;
F_134 ( V_4 ) ;
F_89 (node, N_MEMORY) {
for ( V_39 = 0 ; V_39 < V_65 ; V_39 ++ ) {
enum V_90 V_91 ;
F_85 (lru) {
F_369 ( V_4 ,
V_63 , V_39 , V_91 ) ;
}
}
}
F_136 ( V_4 ) ;
F_200 ( V_4 ) ;
F_374 () ;
V_396 = F_41 ( & V_4 -> V_62 , V_36 ) -
F_41 ( & V_4 -> V_35 , V_36 ) ;
} while ( V_396 > 0 );
}
static inline bool F_377 ( struct V_1 * V_4 )
{
F_298 ( & V_397 ) ;
return V_4 -> V_131 &&
! F_371 ( & V_4 -> V_15 . V_19 -> V_384 ) ;
}
static int F_378 ( struct V_1 * V_4 )
{
int V_398 = V_288 ;
struct V_19 * V_399 = V_4 -> V_15 . V_19 ;
if ( F_379 ( V_399 ) || ! F_371 ( & V_399 -> V_384 ) )
return - V_352 ;
F_376 () ;
while ( V_398 && F_41 ( & V_4 -> V_62 , V_36 ) > 0 ) {
int V_400 ;
if ( F_365 ( V_29 ) )
return - V_293 ;
V_400 = F_173 ( V_4 , V_321 ,
false ) ;
if ( ! V_400 ) {
V_398 -- ;
F_380 ( V_401 , V_402 / 10 ) ;
}
}
F_381 () ;
F_375 ( V_4 ) ;
return 0 ;
}
static int F_382 ( struct V_13 * V_15 ,
unsigned int V_403 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
if ( F_20 ( V_4 ) )
return - V_353 ;
return F_378 ( V_4 ) ;
}
static T_2 F_383 ( struct V_13 * V_15 ,
struct V_307 * V_308 )
{
return F_15 ( V_15 ) -> V_131 ;
}
static int F_384 ( struct V_13 * V_15 ,
struct V_307 * V_308 , T_2 V_71 )
{
int V_404 = 0 ;
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_405 = F_15 ( F_133 ( & V_4 -> V_15 ) ) ;
F_228 ( & V_397 ) ;
if ( V_4 -> V_131 == V_71 )
goto V_140;
if ( ( ! V_405 || ! V_405 -> V_131 ) &&
( V_71 == 1 || V_71 == 0 ) ) {
if ( F_371 ( & V_4 -> V_15 . V_19 -> V_384 ) )
V_4 -> V_131 = V_71 ;
else
V_404 = - V_352 ;
} else
V_404 = - V_353 ;
V_140:
F_226 ( & V_397 ) ;
return V_404 ;
}
static unsigned long F_385 ( struct V_1 * V_4 ,
enum V_69 V_70 )
{
struct V_1 * V_123 ;
long V_71 = 0 ;
F_155 (iter, memcg)
V_71 += F_68 ( V_123 , V_70 ) ;
if ( V_71 < 0 )
V_71 = 0 ;
return V_71 ;
}
static inline T_2 F_386 ( struct V_1 * V_4 , bool V_406 )
{
T_2 V_71 ;
if ( ! F_20 ( V_4 ) ) {
if ( ! V_406 )
return F_41 ( & V_4 -> V_62 , V_36 ) ;
else
return F_41 ( & V_4 -> V_159 , V_36 ) ;
}
V_71 = F_385 ( V_4 , V_84 ) ;
V_71 += F_385 ( V_4 , V_83 ) ;
if ( V_406 )
V_71 += F_385 ( V_4 , V_78 ) ;
return V_71 << V_156 ;
}
static T_8 F_387 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_407 * V_407 ,
char T_9 * V_408 , T_1 V_409 , T_10 * V_410 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
char V_411 [ 64 ] ;
T_2 V_71 ;
int V_335 , V_412 ;
enum V_413 type ;
type = F_388 ( V_308 -> V_242 ) ;
V_335 = F_389 ( V_308 -> V_242 ) ;
switch ( type ) {
case V_414 :
if ( V_335 == V_36 )
V_71 = F_386 ( V_4 , false ) ;
else
V_71 = F_41 ( & V_4 -> V_62 , V_335 ) ;
break;
case V_415 :
if ( V_335 == V_36 )
V_71 = F_386 ( V_4 , true ) ;
else
V_71 = F_41 ( & V_4 -> V_159 , V_335 ) ;
break;
case V_416 :
V_71 = F_41 ( & V_4 -> V_35 , V_335 ) ;
break;
default:
F_114 () ;
}
V_412 = F_390 ( V_411 , sizeof( V_411 ) , L_15 , ( unsigned long long ) V_71 ) ;
return F_391 ( V_408 , V_409 , V_410 , V_411 , V_412 ) ;
}
static int F_392 ( struct V_13 * V_15 , T_2 V_71 )
{
int V_94 = - V_353 ;
#ifdef F_393
struct V_1 * V_4 = F_15 ( V_15 ) ;
F_228 ( & V_397 ) ;
F_228 ( & V_344 ) ;
if ( ! V_4 -> V_6 && V_71 != V_417 ) {
if ( F_379 ( V_15 -> V_19 ) || F_377 ( V_4 ) ) {
V_94 = - V_352 ;
goto V_140;
}
V_94 = F_366 ( & V_4 -> V_35 , V_71 ) ;
F_44 ( V_94 ) ;
V_94 = F_276 ( V_4 ) ;
if ( V_94 ) {
F_366 ( & V_4 -> V_35 , V_417 ) ;
goto V_140;
}
F_394 ( & V_32 ) ;
F_2 ( V_4 ) ;
} else
V_94 = F_366 ( & V_4 -> V_35 , V_71 ) ;
V_140:
F_226 ( & V_344 ) ;
F_226 ( & V_397 ) ;
#endif
return V_94 ;
}
static int F_395 ( struct V_1 * V_4 )
{
int V_94 = 0 ;
struct V_1 * V_53 = F_61 ( V_4 ) ;
if ( ! V_53 )
goto V_140;
V_4 -> V_6 = V_53 -> V_6 ;
if ( ! F_4 ( V_4 ) )
goto V_140;
F_394 ( & V_32 ) ;
F_228 ( & V_344 ) ;
F_290 () ;
V_94 = F_276 ( V_4 ) ;
F_291 () ;
F_226 ( & V_344 ) ;
V_140:
return V_94 ;
}
static int F_396 ( struct V_13 * V_15 , struct V_307 * V_308 ,
const char * V_418 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
enum V_413 type ;
int V_335 ;
unsigned long long V_71 ;
int V_94 ;
type = F_388 ( V_308 -> V_242 ) ;
V_335 = F_389 ( V_308 -> V_242 ) ;
switch ( V_335 ) {
case V_178 :
if ( F_20 ( V_4 ) ) {
V_94 = - V_353 ;
break;
}
V_94 = F_397 ( V_418 , & V_71 ) ;
if ( V_94 )
break;
if ( type == V_414 )
V_94 = F_364 ( V_4 , V_71 ) ;
else if ( type == V_415 )
V_94 = F_367 ( V_4 , V_71 ) ;
else if ( type == V_416 )
V_94 = F_392 ( V_15 , V_71 ) ;
else
return - V_353 ;
break;
case V_419 :
V_94 = F_397 ( V_418 , & V_71 ) ;
if ( V_94 )
break;
if ( type == V_414 )
V_94 = F_398 ( & V_4 -> V_62 , V_71 ) ;
else
V_94 = - V_353 ;
break;
default:
V_94 = - V_353 ;
break;
}
return V_94 ;
}
static void F_399 ( struct V_1 * V_4 ,
unsigned long long * V_420 , unsigned long long * V_421 )
{
unsigned long long V_422 , V_423 , V_424 ;
V_422 = F_41 ( & V_4 -> V_62 , V_178 ) ;
V_423 = F_41 ( & V_4 -> V_159 , V_178 ) ;
if ( ! V_4 -> V_131 )
goto V_140;
while ( F_133 ( & V_4 -> V_15 ) ) {
V_4 = F_15 ( F_133 ( & V_4 -> V_15 ) ) ;
if ( ! V_4 -> V_131 )
break;
V_424 = F_41 ( & V_4 -> V_62 , V_178 ) ;
V_422 = F_131 ( V_422 , V_424 ) ;
V_424 = F_41 ( & V_4 -> V_159 , V_178 ) ;
V_423 = F_131 ( V_423 , V_424 ) ;
}
V_140:
* V_420 = V_422 ;
* V_421 = V_423 ;
}
static int F_400 ( struct V_13 * V_15 , unsigned int V_403 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
int V_335 ;
enum V_413 type ;
type = F_388 ( V_403 ) ;
V_335 = F_389 ( V_403 ) ;
switch ( V_335 ) {
case V_425 :
if ( type == V_414 )
F_401 ( & V_4 -> V_62 ) ;
else if ( type == V_415 )
F_401 ( & V_4 -> V_159 ) ;
else if ( type == V_416 )
F_401 ( & V_4 -> V_35 ) ;
else
return - V_353 ;
break;
case V_179 :
if ( type == V_414 )
F_402 ( & V_4 -> V_62 ) ;
else if ( type == V_415 )
F_402 ( & V_4 -> V_159 ) ;
else if ( type == V_416 )
F_402 ( & V_4 -> V_35 ) ;
else
return - V_353 ;
break;
}
return 0 ;
}
static T_2 F_403 ( struct V_13 * V_15 ,
struct V_307 * V_308 )
{
return F_15 ( V_15 ) -> V_426 ;
}
static int F_404 ( struct V_13 * V_15 ,
struct V_307 * V_308 , T_2 V_71 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
if ( V_71 >= ( 1 << V_427 ) )
return - V_353 ;
V_4 -> V_426 = V_71 ;
return 0 ;
}
static int F_404 ( struct V_13 * V_15 ,
struct V_307 * V_308 , T_2 V_71 )
{
return - V_428 ;
}
static int F_405 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_309 * V_310 )
{
struct V_429 {
const char * V_335 ;
unsigned int V_93 ;
};
static const struct V_429 V_430 [] = {
{ L_16 , V_431 } ,
{ L_17 , V_209 } ,
{ L_18 , V_210 } ,
{ L_19 , F_86 (LRU_UNEVICTABLE) } ,
} ;
const struct V_429 * V_73 ;
int V_38 ;
unsigned long V_432 ;
struct V_1 * V_4 = F_15 ( V_15 ) ;
for ( V_73 = V_430 ; V_73 < V_430 + F_406 ( V_430 ) ; V_73 ++ ) {
V_432 = F_88 ( V_4 , V_73 -> V_93 ) ;
F_407 ( V_310 , L_20 , V_73 -> V_335 , V_432 ) ;
F_89 (nid, N_MEMORY) {
V_432 = F_87 ( V_4 , V_38 ,
V_73 -> V_93 ) ;
F_407 ( V_310 , L_21 , V_38 , V_432 ) ;
}
F_408 ( V_310 , '\n' ) ;
}
for ( V_73 = V_430 ; V_73 < V_430 + F_406 ( V_430 ) ; V_73 ++ ) {
struct V_1 * V_123 ;
V_432 = 0 ;
F_155 (iter, memcg)
V_432 += F_88 ( V_123 , V_73 -> V_93 ) ;
F_407 ( V_310 , L_22 , V_73 -> V_335 , V_432 ) ;
F_89 (nid, N_MEMORY) {
V_432 = 0 ;
F_155 (iter, memcg)
V_432 += F_87 (
V_123 , V_38 , V_73 -> V_93 ) ;
F_407 ( V_310 , L_21 , V_38 , V_432 ) ;
}
F_408 ( V_310 , '\n' ) ;
}
return 0 ;
}
static inline void F_409 ( void )
{
F_410 ( F_406 ( V_183 ) != V_182 ) ;
}
static int F_411 ( struct V_13 * V_15 , struct V_307 * V_308 ,
struct V_309 * V_310 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_433 ;
unsigned int V_177 ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
if ( V_177 == V_78 && ! V_158 )
continue;
F_407 ( V_310 , L_23 , V_181 [ V_177 ] ,
F_68 ( V_4 , V_177 ) * V_254 ) ;
}
for ( V_177 = 0 ; V_177 < V_262 ; V_177 ++ )
F_407 ( V_310 , L_24 , V_434 [ V_177 ] ,
F_76 ( V_4 , V_177 ) ) ;
for ( V_177 = 0 ; V_177 < V_182 ; V_177 ++ )
F_407 ( V_310 , L_24 , V_183 [ V_177 ] ,
F_88 ( V_4 , F_86 ( V_177 ) ) * V_254 ) ;
{
unsigned long long V_185 , V_421 ;
F_399 ( V_4 , & V_185 , & V_421 ) ;
F_407 ( V_310 , L_25 , V_185 ) ;
if ( V_158 )
F_407 ( V_310 , L_26 ,
V_421 ) ;
}
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
long long V_71 = 0 ;
if ( V_177 == V_78 && ! V_158 )
continue;
F_155 (mi, memcg)
V_71 += F_68 ( V_433 , V_177 ) * V_254 ;
F_407 ( V_310 , L_27 , V_181 [ V_177 ] , V_71 ) ;
}
for ( V_177 = 0 ; V_177 < V_262 ; V_177 ++ ) {
unsigned long long V_71 = 0 ;
F_155 (mi, memcg)
V_71 += F_76 ( V_433 , V_177 ) ;
F_407 ( V_310 , L_28 ,
V_434 [ V_177 ] , V_71 ) ;
}
for ( V_177 = 0 ; V_177 < V_182 ; V_177 ++ ) {
unsigned long long V_71 = 0 ;
F_155 (mi, memcg)
V_71 += F_88 ( V_433 , F_86 ( V_177 ) ) * V_254 ;
F_407 ( V_310 , L_28 , V_183 [ V_177 ] , V_71 ) ;
}
#ifdef F_412
{
int V_38 , V_39 ;
struct V_37 * V_47 ;
struct V_435 * V_436 ;
unsigned long V_437 [ 2 ] = { 0 , 0 } ;
unsigned long V_438 [ 2 ] = { 0 , 0 } ;
F_413 (nid)
for ( V_39 = 0 ; V_39 < V_65 ; V_39 ++ ) {
V_47 = F_43 ( V_4 , V_38 , V_39 ) ;
V_436 = & V_47 -> V_89 . V_439 ;
V_437 [ 0 ] += V_436 -> V_437 [ 0 ] ;
V_437 [ 1 ] += V_436 -> V_437 [ 1 ] ;
V_438 [ 0 ] += V_436 -> V_438 [ 0 ] ;
V_438 [ 1 ] += V_436 -> V_438 [ 1 ] ;
}
F_407 ( V_310 , L_29 , V_437 [ 0 ] ) ;
F_407 ( V_310 , L_30 , V_437 [ 1 ] ) ;
F_407 ( V_310 , L_31 , V_438 [ 0 ] ) ;
F_407 ( V_310 , L_32 , V_438 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_414 ( struct V_13 * V_15 ,
struct V_307 * V_308 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
return F_132 ( V_4 ) ;
}
static int F_415 ( struct V_13 * V_15 ,
struct V_307 * V_308 , T_2 V_71 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_53 = F_15 ( F_133 ( & V_4 -> V_15 ) ) ;
if ( V_71 > 100 || ! V_53 )
return - V_353 ;
F_228 ( & V_397 ) ;
if ( ( V_53 -> V_131 ) || F_377 ( V_4 ) ) {
F_226 ( & V_397 ) ;
return - V_353 ;
}
V_4 -> V_161 = V_71 ;
F_226 ( & V_397 ) ;
return 0 ;
}
static void F_416 ( struct V_1 * V_4 , bool V_406 )
{
struct V_440 * V_441 ;
T_2 V_396 ;
int V_177 ;
F_27 () ;
if ( ! V_406 )
V_441 = F_99 ( V_4 -> V_442 . V_443 ) ;
else
V_441 = F_99 ( V_4 -> V_444 . V_443 ) ;
if ( ! V_441 )
goto V_166;
V_396 = F_386 ( V_4 , V_406 ) ;
V_177 = V_441 -> V_445 ;
for (; V_177 >= 0 && F_94 ( V_441 -> V_446 [ V_177 ] . V_447 > V_396 ) ; V_177 -- )
F_417 ( V_441 -> V_446 [ V_177 ] . V_448 , 1 ) ;
V_177 ++ ;
for (; V_177 < V_441 -> V_315 && F_94 ( V_441 -> V_446 [ V_177 ] . V_447 <= V_396 ) ; V_177 ++ )
F_417 ( V_441 -> V_446 [ V_177 ] . V_448 , 1 ) ;
V_441 -> V_445 = V_177 - 1 ;
V_166:
F_31 () ;
}
static void F_95 ( struct V_1 * V_4 )
{
while ( V_4 ) {
F_416 ( V_4 , false ) ;
if ( V_158 )
F_416 ( V_4 , true ) ;
V_4 = F_61 ( V_4 ) ;
}
}
static int F_418 ( const void * V_449 , const void * V_450 )
{
const struct F_95 * V_451 = V_449 ;
const struct F_95 * V_452 = V_450 ;
if ( V_451 -> V_447 > V_452 -> V_447 )
return 1 ;
if ( V_451 -> V_447 < V_452 -> V_447 )
return - 1 ;
return 0 ;
}
static int F_419 ( struct V_1 * V_4 )
{
struct V_453 * V_454 ;
F_268 (ev, &memcg->oom_notify, list)
F_417 ( V_454 -> V_448 , 1 ) ;
return 0 ;
}
static void F_204 ( struct V_1 * V_4 )
{
struct V_1 * V_123 ;
F_155 (iter, memcg)
F_419 ( V_123 ) ;
}
static int F_420 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_455 * V_448 , const char * args )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_456 * V_442 ;
struct V_440 * V_332 ;
enum V_413 type = F_388 ( V_308 -> V_242 ) ;
T_2 V_447 , V_396 ;
int V_177 , V_315 , V_94 ;
V_94 = F_397 ( args , & V_447 ) ;
if ( V_94 )
return V_94 ;
F_228 ( & V_4 -> V_457 ) ;
if ( type == V_414 )
V_442 = & V_4 -> V_442 ;
else if ( type == V_415 )
V_442 = & V_4 -> V_444 ;
else
F_114 () ;
V_396 = F_386 ( V_4 , type == V_415 ) ;
if ( V_442 -> V_443 )
F_416 ( V_4 , type == V_415 ) ;
V_315 = V_442 -> V_443 ? V_442 -> V_443 -> V_315 + 1 : 1 ;
V_332 = F_299 ( sizeof( * V_332 ) + V_315 * sizeof( struct F_95 ) ,
V_321 ) ;
if ( ! V_332 ) {
V_94 = - V_292 ;
goto V_166;
}
V_332 -> V_315 = V_315 ;
if ( V_442 -> V_443 ) {
memcpy ( V_332 -> V_446 , V_442 -> V_443 -> V_446 , ( V_315 - 1 ) *
sizeof( struct F_95 ) ) ;
}
V_332 -> V_446 [ V_315 - 1 ] . V_448 = V_448 ;
V_332 -> V_446 [ V_315 - 1 ] . V_447 = V_447 ;
F_421 ( V_332 -> V_446 , V_315 , sizeof( struct F_95 ) ,
F_418 , NULL ) ;
V_332 -> V_445 = - 1 ;
for ( V_177 = 0 ; V_177 < V_315 ; V_177 ++ ) {
if ( V_332 -> V_446 [ V_177 ] . V_447 <= V_396 ) {
++ V_332 -> V_445 ;
} else
break;
}
F_285 ( V_442 -> V_458 ) ;
V_442 -> V_458 = V_442 -> V_443 ;
F_422 ( V_442 -> V_443 , V_332 ) ;
F_135 () ;
V_166:
F_226 ( & V_4 -> V_457 ) ;
return V_94 ;
}
static void F_423 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_455 * V_448 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_456 * V_442 ;
struct V_440 * V_332 ;
enum V_413 type = F_388 ( V_308 -> V_242 ) ;
T_2 V_396 ;
int V_177 , V_459 , V_315 ;
F_228 ( & V_4 -> V_457 ) ;
if ( type == V_414 )
V_442 = & V_4 -> V_442 ;
else if ( type == V_415 )
V_442 = & V_4 -> V_444 ;
else
F_114 () ;
if ( ! V_442 -> V_443 )
goto V_166;
V_396 = F_386 ( V_4 , type == V_415 ) ;
F_416 ( V_4 , type == V_415 ) ;
V_315 = 0 ;
for ( V_177 = 0 ; V_177 < V_442 -> V_443 -> V_315 ; V_177 ++ ) {
if ( V_442 -> V_443 -> V_446 [ V_177 ] . V_448 != V_448 )
V_315 ++ ;
}
V_332 = V_442 -> V_458 ;
if ( ! V_315 ) {
F_285 ( V_332 ) ;
V_332 = NULL ;
goto V_460;
}
V_332 -> V_315 = V_315 ;
V_332 -> V_445 = - 1 ;
for ( V_177 = 0 , V_459 = 0 ; V_177 < V_442 -> V_443 -> V_315 ; V_177 ++ ) {
if ( V_442 -> V_443 -> V_446 [ V_177 ] . V_448 == V_448 )
continue;
V_332 -> V_446 [ V_459 ] = V_442 -> V_443 -> V_446 [ V_177 ] ;
if ( V_332 -> V_446 [ V_459 ] . V_447 <= V_396 ) {
++ V_332 -> V_445 ;
}
V_459 ++ ;
}
V_460:
V_442 -> V_458 = V_442 -> V_443 ;
if ( ! V_332 ) {
F_285 ( V_442 -> V_458 ) ;
V_442 -> V_458 = NULL ;
}
F_422 ( V_442 -> V_443 , V_332 ) ;
F_135 () ;
V_166:
F_226 ( & V_4 -> V_457 ) ;
}
static int F_424 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_455 * V_448 , const char * args )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_453 * V_403 ;
enum V_413 type = F_388 ( V_308 -> V_242 ) ;
F_25 ( type != V_461 ) ;
V_403 = F_299 ( sizeof( * V_403 ) , V_321 ) ;
if ( ! V_403 )
return - V_292 ;
F_58 ( & V_220 ) ;
V_403 -> V_448 = V_448 ;
F_275 ( & V_403 -> V_318 , & V_4 -> V_462 ) ;
if ( F_104 ( & V_4 -> V_224 ) )
F_417 ( V_448 , 1 ) ;
F_59 ( & V_220 ) ;
return 0 ;
}
static void F_425 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_455 * V_448 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_453 * V_454 , * V_424 ;
enum V_413 type = F_388 ( V_308 -> V_242 ) ;
F_25 ( type != V_461 ) ;
F_58 ( & V_220 ) ;
F_426 (ev, tmp, &memcg->oom_notify, list) {
if ( V_454 -> V_448 == V_448 ) {
F_289 ( & V_454 -> V_318 ) ;
F_285 ( V_454 ) ;
}
}
F_59 ( & V_220 ) ;
}
static int F_427 ( struct V_13 * V_15 ,
struct V_307 * V_308 , struct V_463 * V_464 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
V_464 -> V_465 ( V_464 , L_33 , V_4 -> V_245 ) ;
if ( F_104 ( & V_4 -> V_224 ) )
V_464 -> V_465 ( V_464 , L_34 , 1 ) ;
else
V_464 -> V_465 ( V_464 , L_34 , 0 ) ;
return 0 ;
}
static int F_428 ( struct V_13 * V_15 ,
struct V_307 * V_308 , T_2 V_71 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_53 = F_15 ( F_133 ( & V_4 -> V_15 ) ) ;
if ( ! V_53 || ! ( ( V_71 == 0 ) || ( V_71 == 1 ) ) )
return - V_353 ;
F_228 ( & V_397 ) ;
if ( ( V_53 -> V_131 ) || F_377 ( V_4 ) ) {
F_226 ( & V_397 ) ;
return - V_353 ;
}
V_4 -> V_245 = V_71 ;
if ( ! V_71 )
F_200 ( V_4 ) ;
F_226 ( & V_397 ) ;
return 0 ;
}
static int F_429 ( struct V_1 * V_4 , struct V_466 * V_467 )
{
int V_94 ;
V_4 -> V_34 = - 1 ;
V_94 = F_395 ( V_4 ) ;
if ( V_94 )
return V_94 ;
return F_430 ( V_4 , V_467 ) ;
}
static void F_431 ( struct V_1 * V_4 )
{
F_432 ( V_4 ) ;
}
static void F_433 ( struct V_1 * V_4 )
{
if ( ! F_4 ( V_4 ) )
return;
F_26 ( & V_4 -> V_15 ) ;
F_9 ( V_4 ) ;
if ( F_41 ( & V_4 -> V_35 , V_36 ) != 0 )
return;
if ( F_11 ( V_4 ) )
F_34 ( & V_4 -> V_15 ) ;
}
static int F_429 ( struct V_1 * V_4 , struct V_466 * V_467 )
{
return 0 ;
}
static void F_431 ( struct V_1 * V_4 )
{
}
static void F_433 ( struct V_1 * V_4 )
{
}
static int F_434 ( struct V_1 * V_4 , int V_63 )
{
struct V_3 * V_468 ;
struct V_37 * V_47 ;
int V_64 , V_424 = V_63 ;
if ( ! F_435 ( V_63 , V_469 ) )
V_424 = - 1 ;
V_468 = F_436 ( sizeof( * V_468 ) , V_321 , V_424 ) ;
if ( ! V_468 )
return 1 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_47 = & V_468 -> V_41 [ V_64 ] ;
F_437 ( & V_47 -> V_89 ) ;
V_47 -> V_56 = 0 ;
V_47 -> V_55 = false ;
V_47 -> V_4 = V_4 ;
}
V_4 -> V_40 [ V_63 ] = V_468 ;
return 0 ;
}
static void F_438 ( struct V_1 * V_4 , int V_63 )
{
F_285 ( V_4 -> V_40 [ V_63 ] ) ;
}
static struct V_1 * F_439 ( void )
{
struct V_1 * V_4 ;
T_1 V_315 = F_1 () ;
if ( V_315 < V_254 )
V_4 = F_284 ( V_315 , V_321 ) ;
else
V_4 = F_440 ( V_315 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_73 = F_441 ( struct V_470 ) ;
if ( ! V_4 -> V_73 )
goto V_471;
F_442 ( & V_4 -> V_75 ) ;
return V_4 ;
V_471:
if ( V_315 < V_254 )
F_285 ( V_4 ) ;
else
F_443 ( V_4 ) ;
return NULL ;
}
static void F_444 ( struct V_1 * V_4 )
{
int V_63 ;
T_1 V_315 = F_1 () ;
F_63 ( V_4 ) ;
F_64 (node)
F_438 ( V_4 , V_63 ) ;
F_445 ( V_4 -> V_73 ) ;
F_42 ( V_4 ) ;
if ( V_315 < V_254 )
F_285 ( V_4 ) ;
else
F_443 ( V_4 ) ;
}
struct V_1 * F_61 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_62 . V_53 )
return NULL ;
return F_235 ( V_4 -> V_62 . V_53 , V_62 ) ;
}
static void T_6 F_446 ( void )
{
struct V_472 * V_473 ;
struct V_43 * V_474 ;
int V_424 , V_63 , V_64 ;
F_64 (node) {
V_424 = V_63 ;
if ( ! F_435 ( V_63 , V_469 ) )
V_424 = - 1 ;
V_473 = F_436 ( sizeof( * V_473 ) , V_321 , V_424 ) ;
F_25 ( ! V_473 ) ;
V_44 . V_45 [ V_63 ] = V_473 ;
for ( V_64 = 0 ; V_64 < V_65 ; V_64 ++ ) {
V_474 = & V_473 -> V_46 [ V_64 ] ;
V_474 -> V_52 = V_475 ;
F_442 ( & V_474 -> V_60 ) ;
}
}
}
static struct V_13 * T_11
F_447 ( struct V_13 * V_476 )
{
struct V_1 * V_4 ;
long error = - V_292 ;
int V_63 ;
V_4 = F_439 () ;
if ( ! V_4 )
return F_448 ( error ) ;
F_64 (node)
if ( F_434 ( V_4 , V_63 ) )
goto V_477;
if ( V_476 == NULL ) {
V_17 = V_4 ;
F_449 ( & V_4 -> V_62 , NULL ) ;
F_449 ( & V_4 -> V_159 , NULL ) ;
F_449 ( & V_4 -> V_35 , NULL ) ;
}
V_4 -> V_215 = V_108 ;
F_203 ( & V_4 -> V_462 ) ;
V_4 -> V_426 = 0 ;
F_279 ( & V_4 -> V_457 ) ;
F_442 ( & V_4 -> V_172 ) ;
F_450 ( & V_4 -> V_16 ) ;
return & V_4 -> V_15 ;
V_477:
F_444 ( V_4 ) ;
return F_448 ( error ) ;
}
static int
F_451 ( struct V_13 * V_15 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_53 = F_15 ( F_133 ( V_15 ) ) ;
int error = 0 ;
if ( V_15 -> V_19 -> V_20 > V_478 )
return - V_479 ;
if ( ! V_53 )
return 0 ;
F_228 ( & V_397 ) ;
V_4 -> V_131 = V_53 -> V_131 ;
V_4 -> V_245 = V_53 -> V_245 ;
V_4 -> V_161 = F_132 ( V_53 ) ;
if ( V_53 -> V_131 ) {
F_449 ( & V_4 -> V_62 , & V_53 -> V_62 ) ;
F_449 ( & V_4 -> V_159 , & V_53 -> V_159 ) ;
F_449 ( & V_4 -> V_35 , & V_53 -> V_35 ) ;
} else {
F_449 ( & V_4 -> V_62 , NULL ) ;
F_449 ( & V_4 -> V_159 , NULL ) ;
F_449 ( & V_4 -> V_35 , NULL ) ;
if ( V_53 != V_17 )
V_21 . V_480 = true ;
}
error = F_429 ( V_4 , & V_21 ) ;
F_226 ( & V_397 ) ;
return error ;
}
static void F_452 ( struct V_1 * V_4 )
{
struct V_1 * V_53 = V_4 ;
while ( ( V_53 = F_61 ( V_53 ) ) )
F_102 ( V_53 ) ;
if ( ! V_17 -> V_131 )
F_102 ( V_17 ) ;
}
static void F_453 ( struct V_13 * V_15 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
F_433 ( V_4 ) ;
F_452 ( V_4 ) ;
F_375 ( V_4 ) ;
F_307 ( V_4 ) ;
F_454 ( & V_4 -> V_16 ) ;
}
static void F_455 ( struct V_13 * V_15 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
F_375 ( V_4 ) ;
F_431 ( V_4 ) ;
F_444 ( V_4 ) ;
}
static int F_456 ( unsigned long V_74 )
{
int V_94 = 0 ;
int V_481 = V_482 ;
struct V_1 * V_4 = V_10 . V_165 ;
if ( F_20 ( V_4 ) ) {
V_10 . V_483 += V_74 ;
return V_94 ;
}
if ( V_74 > 1 ) {
struct V_275 * V_256 ;
if ( F_233 ( & V_4 -> V_62 , V_254 * V_74 , & V_256 ) )
goto V_484;
if ( V_158 && F_233 ( & V_4 -> V_159 ,
V_254 * V_74 , & V_256 ) ) {
F_212 ( & V_4 -> V_62 , V_254 * V_74 ) ;
goto V_484;
}
V_10 . V_483 += V_74 ;
return V_94 ;
}
V_484:
while ( V_74 -- ) {
if ( F_365 ( V_29 ) ) {
V_94 = - V_293 ;
break;
}
if ( ! V_481 -- ) {
V_481 = V_482 ;
F_374 () ;
}
V_94 = F_237 ( NULL ,
V_321 , 1 , & V_4 , false ) ;
if ( V_94 )
return V_94 ;
V_10 . V_483 ++ ;
}
return V_94 ;
}
static struct V_42 * F_457 ( struct V_485 * V_486 ,
unsigned long V_487 , T_12 V_488 )
{
struct V_42 * V_42 = F_458 ( V_486 , V_487 , V_488 ) ;
if ( ! V_42 || ! F_322 ( V_42 ) )
return NULL ;
if ( F_321 ( V_42 ) ) {
if ( ! F_13 () )
return NULL ;
} else if ( ! F_14 () )
return NULL ;
if ( ! F_325 ( V_42 ) )
return NULL ;
return V_42 ;
}
static struct V_42 * F_459 ( struct V_485 * V_486 ,
unsigned long V_487 , T_12 V_488 , T_7 * V_373 )
{
struct V_42 * V_42 = NULL ;
T_7 V_294 = F_460 ( V_488 ) ;
if ( ! F_13 () || F_461 ( V_294 ) )
return NULL ;
V_42 = F_462 ( F_463 ( V_294 ) , V_294 . V_71 ) ;
if ( V_158 )
V_373 -> V_71 = V_294 . V_71 ;
return V_42 ;
}
static struct V_42 * F_459 ( struct V_485 * V_486 ,
unsigned long V_487 , T_12 V_488 , T_7 * V_373 )
{
return NULL ;
}
static struct V_42 * F_464 ( struct V_485 * V_486 ,
unsigned long V_487 , T_12 V_488 , T_7 * V_373 )
{
struct V_42 * V_42 = NULL ;
struct V_489 * V_358 ;
T_13 V_490 ;
if ( ! V_486 -> V_491 )
return NULL ;
if ( ! F_14 () )
return NULL ;
V_358 = V_486 -> V_491 -> V_492 ;
if ( F_465 ( V_488 ) )
V_490 = F_466 ( V_486 , V_487 ) ;
else
V_490 = F_467 ( V_488 ) ;
V_42 = F_462 ( V_358 , V_490 ) ;
#ifdef F_468
if ( F_469 ( V_42 ) ) {
T_7 V_406 = F_470 ( V_42 ) ;
if ( V_158 )
* V_373 = V_406 ;
V_42 = F_462 ( F_463 ( V_406 ) , V_406 . V_71 ) ;
}
#endif
return V_42 ;
}
static enum V_493 F_471 ( struct V_485 * V_486 ,
unsigned long V_487 , T_12 V_488 , union V_494 * V_97 )
{
struct V_42 * V_42 = NULL ;
struct V_145 * V_146 ;
enum V_493 V_94 = V_495 ;
T_7 V_294 = { . V_71 = 0 } ;
if ( F_472 ( V_488 ) )
V_42 = F_457 ( V_486 , V_487 , V_488 ) ;
else if ( F_473 ( V_488 ) )
V_42 = F_459 ( V_486 , V_487 , V_488 , & V_294 ) ;
else if ( F_465 ( V_488 ) || F_474 ( V_488 ) )
V_42 = F_464 ( V_486 , V_487 , V_488 , & V_294 ) ;
if ( ! V_42 && ! V_294 . V_71 )
return V_94 ;
if ( V_42 ) {
V_146 = F_117 ( V_42 ) ;
if ( F_119 ( V_146 ) && V_146 -> V_1 == V_10 . V_164 ) {
V_94 = V_496 ;
if ( V_97 )
V_97 -> V_42 = V_42 ;
}
if ( ! V_94 || ! V_97 )
F_331 ( V_42 ) ;
}
if ( V_294 . V_71 && ! V_94 &&
F_21 ( V_10 . V_164 ) == F_250 ( V_294 ) ) {
V_94 = V_497 ;
if ( V_97 )
V_97 -> V_294 = V_294 ;
}
return V_94 ;
}
static enum V_493 F_475 ( struct V_485 * V_486 ,
unsigned long V_487 , T_14 V_498 , union V_494 * V_97 )
{
struct V_42 * V_42 = NULL ;
struct V_145 * V_146 ;
enum V_493 V_94 = V_495 ;
V_42 = F_476 ( V_498 ) ;
F_44 ( ! V_42 || ! F_477 ( V_42 ) ) ;
if ( ! F_13 () )
return V_94 ;
V_146 = F_117 ( V_42 ) ;
if ( F_119 ( V_146 ) && V_146 -> V_1 == V_10 . V_164 ) {
V_94 = V_496 ;
if ( V_97 ) {
F_478 ( V_42 ) ;
V_97 -> V_42 = V_42 ;
}
}
return V_94 ;
}
static inline enum V_493 F_475 ( struct V_485 * V_486 ,
unsigned long V_487 , T_14 V_498 , union V_494 * V_97 )
{
return V_495 ;
}
static int F_479 ( T_14 * V_498 ,
unsigned long V_487 , unsigned long V_499 ,
struct V_500 * V_501 )
{
struct V_485 * V_486 = V_501 -> V_242 ;
T_12 * V_502 ;
T_15 * V_503 ;
if ( F_480 ( V_498 , V_486 , & V_503 ) == 1 ) {
if ( F_475 ( V_486 , V_487 , * V_498 , NULL ) == V_496 )
V_10 . V_483 += V_350 ;
F_59 ( V_503 ) ;
return 0 ;
}
if ( F_481 ( V_498 ) )
return 0 ;
V_502 = F_482 ( V_486 -> V_504 , V_498 , V_487 , & V_503 ) ;
for (; V_487 != V_499 ; V_502 ++ , V_487 += V_254 )
if ( F_471 ( V_486 , V_487 , * V_502 , NULL ) )
V_10 . V_483 ++ ;
F_483 ( V_502 - 1 , V_503 ) ;
F_374 () ;
return 0 ;
}
static unsigned long F_484 ( struct V_112 * V_113 )
{
unsigned long V_483 ;
struct V_485 * V_486 ;
F_485 ( & V_113 -> V_505 ) ;
for ( V_486 = V_113 -> V_506 ; V_486 ; V_486 = V_486 -> V_507 ) {
struct V_500 V_508 = {
. V_509 = F_479 ,
. V_113 = V_113 ,
. V_242 = V_486 ,
} ;
if ( F_486 ( V_486 ) )
continue;
F_487 ( V_486 -> V_510 , V_486 -> V_511 ,
& V_508 ) ;
}
F_488 ( & V_113 -> V_505 ) ;
V_483 = V_10 . V_483 ;
V_10 . V_483 = 0 ;
return V_483 ;
}
static int F_489 ( struct V_112 * V_113 )
{
unsigned long V_483 = F_484 ( V_113 ) ;
F_44 ( V_10 . V_167 ) ;
V_10 . V_167 = V_29 ;
return F_456 ( V_483 ) ;
}
static void F_490 ( void )
{
struct V_1 * V_164 = V_10 . V_164 ;
struct V_1 * V_165 = V_10 . V_165 ;
int V_177 ;
if ( V_10 . V_483 ) {
F_241 ( V_10 . V_165 , V_10 . V_483 ) ;
V_10 . V_483 = 0 ;
}
if ( V_10 . V_512 ) {
F_241 ( V_10 . V_164 , V_10 . V_512 ) ;
V_10 . V_512 = 0 ;
}
if ( V_10 . V_513 ) {
if ( ! F_20 ( V_10 . V_164 ) )
F_212 ( & V_10 . V_164 -> V_159 ,
V_254 * V_10 . V_513 ) ;
for ( V_177 = 0 ; V_177 < V_10 . V_513 ; V_177 ++ )
F_34 ( & V_10 . V_164 -> V_15 ) ;
if ( ! F_20 ( V_10 . V_165 ) ) {
F_212 ( & V_10 . V_165 -> V_62 ,
V_254 * V_10 . V_513 ) ;
}
V_10 . V_513 = 0 ;
}
F_200 ( V_164 ) ;
F_200 ( V_165 ) ;
F_491 ( & V_10 . V_169 ) ;
}
static void F_492 ( void )
{
struct V_1 * V_164 = V_10 . V_164 ;
V_10 . V_167 = NULL ;
F_490 () ;
F_58 ( & V_10 . V_60 ) ;
V_10 . V_164 = NULL ;
V_10 . V_165 = NULL ;
F_59 ( & V_10 . V_60 ) ;
F_136 ( V_164 ) ;
}
static int F_493 ( struct V_13 * V_15 ,
struct V_514 * V_515 )
{
struct V_110 * V_51 = F_494 ( V_515 ) ;
int V_94 = 0 ;
struct V_1 * V_4 = F_15 ( V_15 ) ;
unsigned long V_426 ;
V_426 = V_4 -> V_426 ;
if ( V_426 ) {
struct V_112 * V_113 ;
struct V_1 * V_164 = F_28 ( V_51 ) ;
F_44 ( V_164 == V_4 ) ;
V_113 = F_495 ( V_51 ) ;
if ( ! V_113 )
return 0 ;
if ( V_113 -> V_114 == V_51 ) {
F_44 ( V_10 . V_164 ) ;
F_44 ( V_10 . V_165 ) ;
F_44 ( V_10 . V_483 ) ;
F_44 ( V_10 . V_512 ) ;
F_44 ( V_10 . V_513 ) ;
F_134 ( V_164 ) ;
F_58 ( & V_10 . V_60 ) ;
V_10 . V_164 = V_164 ;
V_10 . V_165 = V_4 ;
V_10 . V_11 = V_426 ;
F_59 ( & V_10 . V_60 ) ;
V_94 = F_489 ( V_113 ) ;
if ( V_94 )
F_492 () ;
}
F_496 ( V_113 ) ;
}
return V_94 ;
}
static void F_497 ( struct V_13 * V_15 ,
struct V_514 * V_515 )
{
F_492 () ;
}
static int F_498 ( T_14 * V_498 ,
unsigned long V_487 , unsigned long V_499 ,
struct V_500 * V_501 )
{
int V_94 = 0 ;
struct V_485 * V_486 = V_501 -> V_242 ;
T_12 * V_502 ;
T_15 * V_503 ;
enum V_493 V_516 ;
union V_494 V_97 ;
struct V_42 * V_42 ;
struct V_145 * V_146 ;
if ( F_480 ( V_498 , V_486 , & V_503 ) == 1 ) {
if ( V_10 . V_483 < V_350 ) {
F_59 ( V_503 ) ;
return 0 ;
}
V_516 = F_475 ( V_486 , V_487 , * V_498 , & V_97 ) ;
if ( V_516 == V_496 ) {
V_42 = V_97 . V_42 ;
if ( ! F_326 ( V_42 ) ) {
V_146 = F_117 ( V_42 ) ;
if ( ! F_320 ( V_42 , V_350 ,
V_146 , V_10 . V_164 , V_10 . V_165 ) ) {
V_10 . V_483 -= V_350 ;
V_10 . V_512 += V_350 ;
}
F_330 ( V_42 ) ;
}
F_331 ( V_42 ) ;
}
F_59 ( V_503 ) ;
return 0 ;
}
if ( F_481 ( V_498 ) )
return 0 ;
V_67:
V_502 = F_482 ( V_486 -> V_504 , V_498 , V_487 , & V_503 ) ;
for (; V_487 != V_499 ; V_487 += V_254 ) {
T_12 V_488 = * ( V_502 ++ ) ;
T_7 V_294 ;
if ( ! V_10 . V_483 )
break;
switch ( F_471 ( V_486 , V_487 , V_488 , & V_97 ) ) {
case V_496 :
V_42 = V_97 . V_42 ;
if ( F_326 ( V_42 ) )
goto V_357;
V_146 = F_117 ( V_42 ) ;
if ( ! F_320 ( V_42 , 1 , V_146 ,
V_10 . V_164 , V_10 . V_165 ) ) {
V_10 . V_483 -- ;
V_10 . V_512 ++ ;
}
F_330 ( V_42 ) ;
V_357:
F_331 ( V_42 ) ;
break;
case V_497 :
V_294 = V_97 . V_294 ;
if ( ! F_353 ( V_294 , V_10 . V_164 , V_10 . V_165 ) ) {
V_10 . V_483 -- ;
V_10 . V_513 ++ ;
}
break;
default:
break;
}
}
F_483 ( V_502 - 1 , V_503 ) ;
F_374 () ;
if ( V_487 != V_499 ) {
V_94 = F_456 ( 1 ) ;
if ( ! V_94 )
goto V_67;
}
return V_94 ;
}
static void F_499 ( struct V_112 * V_113 )
{
struct V_485 * V_486 ;
F_376 () ;
V_67:
if ( F_94 ( ! F_500 ( & V_113 -> V_505 ) ) ) {
F_490 () ;
F_374 () ;
goto V_67;
}
for ( V_486 = V_113 -> V_506 ; V_486 ; V_486 = V_486 -> V_507 ) {
int V_94 ;
struct V_500 V_517 = {
. V_509 = F_498 ,
. V_113 = V_113 ,
. V_242 = V_486 ,
} ;
if ( F_486 ( V_486 ) )
continue;
V_94 = F_487 ( V_486 -> V_510 , V_486 -> V_511 ,
& V_517 ) ;
if ( V_94 )
break;
}
F_488 ( & V_113 -> V_505 ) ;
}
static void F_501 ( struct V_13 * V_15 ,
struct V_514 * V_515 )
{
struct V_110 * V_51 = F_494 ( V_515 ) ;
struct V_112 * V_113 = F_495 ( V_51 ) ;
if ( V_113 ) {
if ( V_10 . V_165 )
F_499 ( V_113 ) ;
F_496 ( V_113 ) ;
}
if ( V_10 . V_165 )
F_492 () ;
}
static int F_493 ( struct V_13 * V_15 ,
struct V_514 * V_515 )
{
return 0 ;
}
static void F_497 ( struct V_13 * V_15 ,
struct V_514 * V_515 )
{
}
static void F_501 ( struct V_13 * V_15 ,
struct V_514 * V_515 )
{
}
static void F_502 ( struct V_13 * V_518 )
{
if ( F_503 ( V_518 -> V_19 ) )
F_15 ( V_518 ) -> V_131 = true ;
}
static int T_6 F_504 ( char * V_14 )
{
if ( ! strcmp ( V_14 , L_35 ) )
V_519 = 1 ;
else if ( ! strcmp ( V_14 , L_36 ) )
V_519 = 0 ;
return 1 ;
}
static void T_6 F_505 ( void )
{
F_33 ( F_506 ( & V_21 , V_520 ) ) ;
}
static void T_6 F_507 ( void )
{
if ( ! F_108 () && V_519 ) {
V_158 = 1 ;
F_505 () ;
}
}
static void T_6 F_507 ( void )
{
}
static int T_6 F_508 ( void )
{
F_509 ( F_230 , 0 ) ;
F_507 () ;
F_446 () ;
F_215 () ;
return 0 ;
}
