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
void F_21 ( struct V_19 * V_20 )
{
if ( V_21 ) {
struct V_1 * V_4 ;
struct V_22 * V_22 ;
F_22 ( ! V_20 -> V_23 -> V_24 ) ;
if ( V_20 -> V_25 ) {
F_22 ( F_20 ( V_20 -> V_25 -> V_4 ) ) ;
F_23 ( & V_20 -> V_25 -> V_4 -> V_15 ) ;
return;
}
F_24 () ;
V_4 = F_25 ( V_26 ) ;
V_22 = V_20 -> V_23 -> V_24 ( V_4 ) ;
if ( ! F_20 ( V_4 ) &&
F_26 ( V_22 ) && F_27 ( & V_4 -> V_15 ) ) {
V_20 -> V_25 = V_22 ;
}
F_28 () ;
}
}
void F_29 ( struct V_19 * V_20 )
{
if ( V_21 && V_20 -> V_25 ) {
struct V_1 * V_4 ;
F_30 ( ! V_20 -> V_25 -> V_4 ) ;
V_4 = V_20 -> V_25 -> V_4 ;
F_31 ( & V_20 -> V_25 -> V_4 -> V_15 ) ;
}
}
struct V_22 * F_32 ( struct V_1 * V_4 )
{
if ( ! V_4 || F_20 ( V_4 ) )
return NULL ;
return & V_4 -> V_27 . V_22 ;
}
static void F_33 ( struct V_1 * V_4 )
{
if ( ! F_34 ( & V_4 -> V_27 . V_22 ) )
return;
F_35 ( & V_28 ) ;
}
static void F_33 ( struct V_1 * V_4 )
{
}
static void F_36 ( struct V_1 * V_4 )
{
if ( F_4 ( V_4 ) ) {
F_35 ( & V_29 ) ;
F_37 ( & V_30 , V_4 -> V_31 ) ;
}
F_30 ( F_38 ( & V_4 -> V_32 , V_33 ) != 0 ) ;
}
static void F_36 ( struct V_1 * V_4 )
{
}
static void F_39 ( struct V_1 * V_4 )
{
F_33 ( V_4 ) ;
F_36 ( V_4 ) ;
}
static struct V_34 *
F_40 ( struct V_1 * V_4 , int V_35 , int V_36 )
{
F_41 ( ( unsigned ) V_35 >= V_2 ) ;
return & V_4 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
}
struct V_13 * F_42 ( struct V_1 * V_4 )
{
return & V_4 -> V_15 ;
}
static struct V_34 *
F_43 ( struct V_1 * V_4 , struct V_39 * V_39 )
{
int V_35 = F_44 ( V_39 ) ;
int V_36 = F_45 ( V_39 ) ;
return F_40 ( V_4 , V_35 , V_36 ) ;
}
static struct V_40 *
F_46 ( int V_35 , int V_36 )
{
return & V_41 . V_42 [ V_35 ] -> V_43 [ V_36 ] ;
}
static struct V_40 *
F_47 ( struct V_39 * V_39 )
{
int V_35 = F_44 ( V_39 ) ;
int V_36 = F_45 ( V_39 ) ;
return & V_41 . V_42 [ V_35 ] -> V_43 [ V_36 ] ;
}
static void
F_48 ( struct V_1 * V_4 ,
struct V_34 * V_44 ,
struct V_40 * V_45 ,
unsigned long long V_46 )
{
struct V_47 * * V_48 = & V_45 -> V_49 . V_47 ;
struct V_47 * V_50 = NULL ;
struct V_34 * V_51 ;
if ( V_44 -> V_52 )
return;
V_44 -> V_53 = V_46 ;
if ( ! V_44 -> V_53 )
return;
while ( * V_48 ) {
V_50 = * V_48 ;
V_51 = F_49 ( V_50 , struct V_34 ,
V_54 ) ;
if ( V_44 -> V_53 < V_51 -> V_53 )
V_48 = & ( * V_48 ) -> V_55 ;
else if ( V_44 -> V_53 >= V_51 -> V_53 )
V_48 = & ( * V_48 ) -> V_56 ;
}
F_50 ( & V_44 -> V_54 , V_50 , V_48 ) ;
F_51 ( & V_44 -> V_54 , & V_45 -> V_49 ) ;
V_44 -> V_52 = true ;
}
static void
F_52 ( struct V_1 * V_4 ,
struct V_34 * V_44 ,
struct V_40 * V_45 )
{
if ( ! V_44 -> V_52 )
return;
F_53 ( & V_44 -> V_54 , & V_45 -> V_49 ) ;
V_44 -> V_52 = false ;
}
static void
F_54 ( struct V_1 * V_4 ,
struct V_34 * V_44 ,
struct V_40 * V_45 )
{
F_55 ( & V_45 -> V_57 ) ;
F_52 ( V_4 , V_44 , V_45 ) ;
F_56 ( & V_45 -> V_57 ) ;
}
static void F_57 ( struct V_1 * V_4 , struct V_39 * V_39 )
{
unsigned long long V_58 ;
struct V_34 * V_44 ;
struct V_40 * V_45 ;
int V_35 = F_44 ( V_39 ) ;
int V_36 = F_45 ( V_39 ) ;
V_45 = F_47 ( V_39 ) ;
for (; V_4 ; V_4 = F_58 ( V_4 ) ) {
V_44 = F_40 ( V_4 , V_35 , V_36 ) ;
V_58 = F_59 ( & V_4 -> V_59 ) ;
if ( V_58 || V_44 -> V_52 ) {
F_55 ( & V_45 -> V_57 ) ;
if ( V_44 -> V_52 )
F_52 ( V_4 , V_44 , V_45 ) ;
F_48 ( V_4 , V_44 , V_45 , V_58 ) ;
F_56 ( & V_45 -> V_57 ) ;
}
}
}
static void F_60 ( struct V_1 * V_4 )
{
int V_60 , V_61 ;
struct V_34 * V_44 ;
struct V_40 * V_45 ;
F_61 (node) {
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_44 = F_40 ( V_4 , V_60 , V_61 ) ;
V_45 = F_46 ( V_60 , V_61 ) ;
F_54 ( V_4 , V_44 , V_45 ) ;
}
}
}
static struct V_34 *
F_62 ( struct V_40 * V_45 )
{
struct V_47 * V_63 = NULL ;
struct V_34 * V_44 ;
V_64:
V_44 = NULL ;
V_63 = F_63 ( & V_45 -> V_49 ) ;
if ( ! V_63 )
goto V_65;
V_44 = F_49 ( V_63 , struct V_34 , V_54 ) ;
F_52 ( V_44 -> V_4 , V_44 , V_45 ) ;
if ( ! F_59 ( & V_44 -> V_4 -> V_59 ) ||
! F_27 ( & V_44 -> V_4 -> V_15 ) )
goto V_64;
V_65:
return V_44 ;
}
static struct V_34 *
F_64 ( struct V_40 * V_45 )
{
struct V_34 * V_44 ;
F_55 ( & V_45 -> V_57 ) ;
V_44 = F_62 ( V_45 ) ;
F_56 ( & V_45 -> V_57 ) ;
return V_44 ;
}
static long F_65 ( struct V_1 * V_4 ,
enum V_66 V_67 )
{
long V_68 = 0 ;
int V_69 ;
F_66 () ;
F_67 (cpu)
V_68 += F_68 ( V_4 -> V_70 -> V_71 [ V_67 ] , V_69 ) ;
#ifdef F_69
F_55 ( & V_4 -> V_72 ) ;
V_68 += V_4 -> V_73 . V_71 [ V_67 ] ;
F_56 ( & V_4 -> V_72 ) ;
#endif
F_70 () ;
return V_68 ;
}
static void F_71 ( struct V_1 * V_4 ,
bool V_74 )
{
int V_68 = ( V_74 ) ? 1 : - 1 ;
F_72 ( V_4 -> V_70 -> V_71 [ V_75 ] , V_68 ) ;
}
static unsigned long F_73 ( struct V_1 * V_4 ,
enum V_76 V_67 )
{
unsigned long V_68 = 0 ;
int V_69 ;
F_66 () ;
F_67 (cpu)
V_68 += F_68 ( V_4 -> V_70 -> V_77 [ V_67 ] , V_69 ) ;
#ifdef F_69
F_55 ( & V_4 -> V_72 ) ;
V_68 += V_4 -> V_73 . V_77 [ V_67 ] ;
F_56 ( & V_4 -> V_72 ) ;
#endif
F_70 () ;
return V_68 ;
}
static void F_74 ( struct V_1 * V_4 ,
struct V_39 * V_39 ,
bool V_78 , int V_79 )
{
F_75 () ;
if ( V_78 )
F_76 ( V_4 -> V_70 -> V_71 [ V_80 ] ,
V_79 ) ;
else
F_76 ( V_4 -> V_70 -> V_71 [ V_81 ] ,
V_79 ) ;
if ( F_77 ( V_39 ) )
F_76 ( V_4 -> V_70 -> V_71 [ V_82 ] ,
V_79 ) ;
if ( V_79 > 0 )
F_78 ( V_4 -> V_70 -> V_77 [ V_83 ] ) ;
else {
F_78 ( V_4 -> V_70 -> V_77 [ V_84 ] ) ;
V_79 = - V_79 ;
}
F_76 ( V_4 -> V_70 -> V_85 , V_79 ) ;
F_79 () ;
}
unsigned long
F_80 ( struct V_86 * V_86 , enum V_87 V_88 )
{
struct V_34 * V_44 ;
V_44 = F_16 ( V_86 , struct V_34 , V_86 ) ;
return V_44 -> V_89 [ V_88 ] ;
}
static unsigned long
F_81 ( struct V_1 * V_4 , int V_35 , int V_36 ,
unsigned int V_90 )
{
struct V_34 * V_44 ;
enum V_87 V_88 ;
unsigned long V_91 = 0 ;
V_44 = F_40 ( V_4 , V_35 , V_36 ) ;
F_82 (lru) {
if ( F_83 ( V_88 ) & V_90 )
V_91 += V_44 -> V_89 [ V_88 ] ;
}
return V_91 ;
}
static unsigned long
F_84 ( struct V_1 * V_4 ,
int V_35 , unsigned int V_90 )
{
T_2 V_92 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_62 ; V_36 ++ )
V_92 += F_81 ( V_4 ,
V_35 , V_36 , V_90 ) ;
return V_92 ;
}
static unsigned long F_85 ( struct V_1 * V_4 ,
unsigned int V_90 )
{
int V_35 ;
T_2 V_92 = 0 ;
F_86 (nid, N_MEMORY)
V_92 += F_84 ( V_4 , V_35 , V_90 ) ;
return V_92 ;
}
static bool F_87 ( struct V_1 * V_4 ,
enum V_93 V_94 )
{
unsigned long V_68 , V_95 ;
V_68 = F_88 ( V_4 -> V_70 -> V_85 ) ;
V_95 = F_88 ( V_4 -> V_70 -> V_96 [ V_94 ] ) ;
if ( ( long ) V_95 - ( long ) V_68 < 0 ) {
switch ( V_94 ) {
case V_97 :
V_95 = V_68 + V_98 ;
break;
case V_99 :
V_95 = V_68 + V_100 ;
break;
case V_101 :
V_95 = V_68 + V_102 ;
break;
default:
break;
}
F_89 ( V_4 -> V_70 -> V_96 [ V_94 ] , V_95 ) ;
return true ;
}
return false ;
}
static void F_90 ( struct V_1 * V_4 , struct V_39 * V_39 )
{
F_75 () ;
if ( F_91 ( F_87 ( V_4 ,
V_97 ) ) ) {
bool V_103 ;
bool T_3 V_104 ;
V_103 = F_87 ( V_4 ,
V_99 ) ;
#if V_105 > 1
T_3 = F_87 ( V_4 ,
V_101 ) ;
#endif
F_79 () ;
F_92 ( V_4 ) ;
if ( F_91 ( V_103 ) )
F_57 ( V_4 , V_39 ) ;
#if V_105 > 1
if ( F_91 ( T_3 ) )
F_93 ( & V_4 -> V_106 ) ;
#endif
} else
F_79 () ;
}
struct V_1 * F_25 ( struct V_107 * V_48 )
{
if ( F_91 ( ! V_48 ) )
return NULL ;
return F_15 ( F_94 ( V_48 , V_108 ) ) ;
}
struct V_1 * F_95 ( struct V_109 * V_110 )
{
struct V_1 * V_4 = NULL ;
if ( ! V_110 )
return NULL ;
F_24 () ;
do {
V_4 = F_25 ( F_96 ( V_110 -> V_111 ) ) ;
if ( F_91 ( ! V_4 ) )
break;
} while ( ! F_27 ( & V_4 -> V_15 ) );
F_28 () ;
return V_4 ;
}
static struct V_1 * F_97 ( struct V_1 * V_112 ,
struct V_1 * V_113 )
{
struct V_13 * V_114 , * V_115 ;
V_114 = V_113 ? & V_113 -> V_15 : NULL ;
V_116:
V_115 = F_98 ( V_114 , & V_112 -> V_15 ) ;
if ( V_115 ) {
struct V_1 * V_117 = F_15 ( V_115 ) ;
if ( F_27 ( & V_117 -> V_15 ) )
return V_117 ;
else {
V_114 = V_115 ;
goto V_116;
}
}
return NULL ;
}
static void F_99 ( struct V_1 * V_112 )
{
F_93 ( & V_112 -> V_118 ) ;
}
static struct V_1 *
F_100 ( struct V_119 * V_120 ,
struct V_1 * V_112 ,
int * V_121 )
{
struct V_1 * V_122 = NULL ;
* V_121 = F_101 ( & V_112 -> V_118 ) ;
if ( V_120 -> V_123 == * V_121 ) {
F_102 () ;
V_122 = V_120 -> V_113 ;
if ( V_122 && ! F_27 ( & V_122 -> V_15 ) )
V_122 = NULL ;
}
return V_122 ;
}
static void F_103 ( struct V_119 * V_120 ,
struct V_1 * V_113 ,
struct V_1 * V_124 ,
int V_121 )
{
if ( V_113 )
F_31 ( & V_113 -> V_15 ) ;
V_120 -> V_113 = V_124 ;
F_10 () ;
V_120 -> V_123 = V_121 ;
}
struct V_1 * F_104 ( struct V_1 * V_112 ,
struct V_1 * V_125 ,
struct V_126 * V_127 )
{
struct V_1 * V_4 = NULL ;
struct V_1 * V_113 = NULL ;
if ( F_105 () )
return NULL ;
if ( ! V_112 )
V_112 = V_17 ;
if ( V_125 && ! V_127 )
V_113 = V_125 ;
if ( ! V_112 -> V_128 && V_112 != V_17 ) {
if ( V_125 )
goto V_129;
return V_112 ;
}
F_24 () ;
while ( ! V_4 ) {
struct V_119 * V_130 ( V_120 ) ;
int V_130 ( V_131 ) ;
if ( V_127 ) {
int V_35 = F_106 ( V_127 -> V_61 ) ;
int V_36 = F_107 ( V_127 -> V_61 ) ;
struct V_34 * V_44 ;
V_44 = F_40 ( V_112 , V_35 , V_36 ) ;
V_120 = & V_44 -> V_132 [ V_127 -> V_133 ] ;
if ( V_125 && V_127 -> V_134 != V_120 -> V_134 ) {
V_120 -> V_113 = NULL ;
goto V_135;
}
V_113 = F_100 ( V_120 , V_112 , & V_131 ) ;
}
V_4 = F_97 ( V_112 , V_113 ) ;
if ( V_127 ) {
F_103 ( V_120 , V_113 , V_4 , V_131 ) ;
if ( ! V_4 )
V_120 -> V_134 ++ ;
else if ( ! V_125 && V_4 )
V_127 -> V_134 = V_120 -> V_134 ;
}
if ( V_125 && ! V_4 )
goto V_135;
}
V_135:
F_28 () ;
V_129:
if ( V_125 && V_125 != V_112 )
F_31 ( & V_125 -> V_15 ) ;
return V_4 ;
}
void F_108 ( struct V_1 * V_112 ,
struct V_1 * V_125 )
{
if ( ! V_112 )
V_112 = V_17 ;
if ( V_125 && V_125 != V_112 )
F_31 ( & V_125 -> V_15 ) ;
}
void F_109 ( struct V_109 * V_110 , enum V_136 V_67 )
{
struct V_1 * V_4 ;
F_24 () ;
V_4 = F_25 ( F_96 ( V_110 -> V_111 ) ) ;
if ( F_91 ( ! V_4 ) )
goto V_137;
switch ( V_67 ) {
case V_138 :
F_110 ( V_4 -> V_70 -> V_77 [ V_139 ] ) ;
break;
case V_140 :
F_110 ( V_4 -> V_70 -> V_77 [ V_141 ] ) ;
break;
default:
F_111 () ;
}
V_137:
F_28 () ;
}
struct V_86 * F_112 ( struct V_61 * V_61 ,
struct V_1 * V_4 )
{
struct V_34 * V_44 ;
struct V_86 * V_86 ;
if ( F_105 () ) {
V_86 = & V_61 -> V_86 ;
goto V_137;
}
V_44 = F_40 ( V_4 , F_106 ( V_61 ) , F_107 ( V_61 ) ) ;
V_86 = & V_44 -> V_86 ;
V_137:
if ( F_91 ( V_86 -> V_61 != V_61 ) )
V_86 -> V_61 = V_61 ;
return V_86 ;
}
struct V_86 * F_113 ( struct V_39 * V_39 , struct V_61 * V_61 )
{
struct V_34 * V_44 ;
struct V_1 * V_4 ;
struct V_142 * V_143 ;
struct V_86 * V_86 ;
if ( F_105 () ) {
V_86 = & V_61 -> V_86 ;
goto V_137;
}
V_143 = F_114 ( V_39 ) ;
V_4 = V_143 -> V_1 ;
if ( ! F_115 ( V_39 ) && ! F_116 ( V_143 ) && V_4 != V_17 )
V_143 -> V_1 = V_4 = V_17 ;
V_44 = F_43 ( V_4 , V_39 ) ;
V_86 = & V_44 -> V_86 ;
V_137:
if ( F_91 ( V_86 -> V_61 != V_61 ) )
V_86 -> V_61 = V_61 ;
return V_86 ;
}
void F_117 ( struct V_86 * V_86 , enum V_87 V_88 ,
int V_79 )
{
struct V_34 * V_44 ;
unsigned long * V_89 ;
if ( F_105 () )
return;
V_44 = F_16 ( V_86 , struct V_34 , V_86 ) ;
V_89 = V_44 -> V_89 + V_88 ;
* V_89 += V_79 ;
F_41 ( ( long ) ( * V_89 ) < 0 ) ;
}
bool F_118 ( const struct V_1 * V_144 ,
struct V_1 * V_4 )
{
if ( V_144 == V_4 )
return true ;
if ( ! V_144 -> V_128 || ! V_4 )
return false ;
return F_119 ( & V_4 -> V_15 , & V_144 -> V_15 ) ;
}
static bool F_120 ( const struct V_1 * V_144 ,
struct V_1 * V_4 )
{
bool V_91 ;
F_24 () ;
V_91 = F_118 ( V_144 , V_4 ) ;
F_28 () ;
return V_91 ;
}
bool F_121 ( struct V_107 * V_145 ,
const struct V_1 * V_4 )
{
struct V_1 * V_146 = NULL ;
struct V_107 * V_48 ;
bool V_91 ;
V_48 = F_122 ( V_145 ) ;
if ( V_48 ) {
V_146 = F_95 ( V_48 -> V_110 ) ;
F_123 ( V_48 ) ;
} else {
F_24 () ;
V_146 = F_25 ( V_145 ) ;
if ( V_146 )
F_23 ( & V_146 -> V_15 ) ;
F_28 () ;
}
if ( ! V_146 )
return false ;
V_91 = F_120 ( V_4 , V_146 ) ;
F_31 ( & V_146 -> V_15 ) ;
return V_91 ;
}
int F_124 ( struct V_86 * V_86 )
{
unsigned long V_147 ;
unsigned long V_148 ;
unsigned long V_149 ;
unsigned long V_150 ;
V_148 = F_80 ( V_86 , V_151 ) ;
V_149 = F_80 ( V_86 , V_152 ) ;
V_150 = ( V_148 + V_149 ) >> ( 30 - V_153 ) ;
if ( V_150 )
V_147 = F_125 ( 10 * V_150 ) ;
else
V_147 = 1 ;
return V_148 * V_147 < V_149 ;
}
static unsigned long F_126 ( struct V_1 * V_4 )
{
unsigned long long V_154 ;
V_154 = F_127 ( & V_4 -> V_59 ) ;
if ( V_155 )
V_154 = F_128 ( V_154 , F_127 ( & V_4 -> V_156 ) ) ;
return V_154 >> V_153 ;
}
int F_129 ( struct V_1 * V_4 )
{
if ( ! F_130 ( & V_4 -> V_15 ) )
return V_157 ;
return V_4 -> V_158 ;
}
static void F_131 ( struct V_1 * V_4 )
{
F_93 ( & V_159 ) ;
F_93 ( & V_4 -> V_160 ) ;
F_132 () ;
}
static void F_133 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_134 ( & V_159 ) ;
F_134 ( & V_4 -> V_160 ) ;
}
}
static bool F_135 ( struct V_1 * V_4 )
{
F_41 ( ! F_136 () ) ;
return F_101 ( & V_4 -> V_160 ) > 0 ;
}
static bool F_137 ( struct V_1 * V_4 )
{
struct V_1 * V_161 ;
struct V_1 * V_162 ;
bool V_91 = false ;
F_55 ( & V_10 . V_57 ) ;
V_161 = V_10 . V_161 ;
V_162 = V_10 . V_162 ;
if ( ! V_161 )
goto V_163;
V_91 = F_120 ( V_4 , V_161 )
|| F_120 ( V_4 , V_162 ) ;
V_163:
F_56 ( & V_10 . V_57 ) ;
return V_91 ;
}
static bool F_138 ( struct V_1 * V_4 )
{
if ( V_10 . V_164 && V_26 != V_10 . V_164 ) {
if ( F_137 ( V_4 ) ) {
F_139 ( V_165 ) ;
F_140 ( & V_10 . V_166 , & V_165 , V_167 ) ;
if ( V_10 . V_164 )
F_141 () ;
F_142 ( & V_10 . V_166 , & V_165 ) ;
return true ;
}
}
return false ;
}
static void F_143 ( struct V_1 * V_4 ,
unsigned long * V_168 )
{
F_144 ( & V_4 -> V_169 , * V_168 ) ;
}
static void F_145 ( struct V_1 * V_4 ,
unsigned long * V_168 )
{
F_146 ( & V_4 -> V_169 , * V_168 ) ;
}
void F_147 ( struct V_1 * V_4 , struct V_107 * V_48 )
{
struct V_170 * V_171 ;
struct V_170 * V_172 ;
static char V_173 [ V_174 ] ;
int V_91 ;
struct V_1 * V_120 ;
unsigned int V_175 ;
if ( ! V_48 )
return;
F_24 () ;
V_172 = V_4 -> V_15 . V_170 ;
V_171 = F_148 ( V_48 , V_108 ) ;
V_91 = F_149 ( V_171 , V_173 , V_174 ) ;
if ( V_91 < 0 ) {
F_28 () ;
goto V_65;
}
F_28 () ;
F_150 ( L_1 , V_173 ) ;
F_24 () ;
V_91 = F_149 ( V_172 , V_173 , V_174 ) ;
if ( V_91 < 0 ) {
F_28 () ;
goto V_65;
}
F_28 () ;
F_151 ( L_2 , V_173 ) ;
V_65:
F_150 ( L_3 ,
F_38 ( & V_4 -> V_59 , V_33 ) >> 10 ,
F_38 ( & V_4 -> V_59 , V_176 ) >> 10 ,
F_38 ( & V_4 -> V_59 , V_177 ) ) ;
F_150 ( L_4 ,
F_38 ( & V_4 -> V_156 , V_33 ) >> 10 ,
F_38 ( & V_4 -> V_156 , V_176 ) >> 10 ,
F_38 ( & V_4 -> V_156 , V_177 ) ) ;
F_150 ( L_5 ,
F_38 ( & V_4 -> V_32 , V_33 ) >> 10 ,
F_38 ( & V_4 -> V_32 , V_176 ) >> 10 ,
F_38 ( & V_4 -> V_32 , V_177 ) ) ;
F_152 (iter, memcg) {
F_150 ( L_6 ) ;
F_24 () ;
V_91 = F_149 ( V_120 -> V_15 . V_170 , V_173 , V_174 ) ;
if ( ! V_91 )
F_151 ( L_7 , V_173 ) ;
F_28 () ;
F_151 ( L_8 ) ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
if ( V_175 == V_75 && ! V_155 )
continue;
F_151 ( L_9 , V_179 [ V_175 ] ,
F_153 ( F_65 ( V_120 , V_175 ) ) ) ;
}
for ( V_175 = 0 ; V_175 < V_180 ; V_175 ++ )
F_151 ( L_10 , V_181 [ V_175 ] ,
F_153 ( F_85 ( V_120 , F_83 ( V_175 ) ) ) ) ;
F_151 ( L_11 ) ;
}
}
static int F_154 ( struct V_1 * V_4 )
{
int V_182 = 0 ;
struct V_1 * V_120 ;
F_152 (iter, memcg)
V_182 ++ ;
return V_182 ;
}
static T_2 F_155 ( struct V_1 * V_4 )
{
T_2 V_183 ;
V_183 = F_38 ( & V_4 -> V_59 , V_176 ) ;
if ( F_129 ( V_4 ) ) {
T_2 V_156 ;
V_183 += V_184 << V_153 ;
V_156 = F_38 ( & V_4 -> V_156 , V_176 ) ;
V_183 = F_128 ( V_183 , V_156 ) ;
}
return V_183 ;
}
static void F_156 ( struct V_1 * V_4 , T_4 V_185 ,
int V_186 )
{
struct V_1 * V_120 ;
unsigned long V_187 = 0 ;
unsigned long V_188 ;
unsigned int V_189 = 0 ;
struct V_107 * V_190 = NULL ;
if ( F_157 ( V_26 ) || V_26 -> V_168 & V_191 ) {
F_158 ( V_192 ) ;
return;
}
F_159 ( V_193 , V_185 , V_186 , NULL ) ;
V_188 = F_155 ( V_4 ) >> V_153 ? : 1 ;
F_152 (iter, memcg) {
struct V_194 V_195 ;
struct V_107 * V_145 ;
F_160 ( & V_120 -> V_15 , & V_195 ) ;
while ( ( V_145 = F_161 ( & V_195 ) ) ) {
switch ( F_162 ( V_145 , V_188 , NULL ,
false ) ) {
case V_196 :
if ( V_190 )
F_163 ( V_190 ) ;
V_190 = V_145 ;
V_187 = V_197 ;
F_164 ( V_190 ) ;
case V_198 :
continue;
case V_199 :
F_165 ( & V_195 ) ;
F_108 ( V_4 , V_120 ) ;
if ( V_190 )
F_163 ( V_190 ) ;
return;
case V_200 :
break;
} ;
V_189 = F_166 ( V_145 , V_4 , NULL , V_188 ) ;
if ( V_189 > V_187 ) {
if ( V_190 )
F_163 ( V_190 ) ;
V_190 = V_145 ;
V_187 = V_189 ;
F_164 ( V_190 ) ;
}
}
F_165 ( & V_195 ) ;
}
if ( ! V_190 )
return;
V_189 = V_187 * 1000 / V_188 ;
F_167 ( V_190 , V_185 , V_186 , V_189 , V_188 , V_4 ,
NULL , L_12 ) ;
}
static unsigned long F_168 ( struct V_1 * V_4 ,
T_4 V_185 ,
unsigned long V_168 )
{
unsigned long V_92 = 0 ;
bool V_201 = false ;
int V_202 ;
if ( V_168 & V_203 )
V_201 = true ;
if ( ! ( V_168 & V_204 ) && V_4 -> V_205 )
V_201 = true ;
for ( V_202 = 0 ; V_202 < V_206 ; V_202 ++ ) {
if ( V_202 )
F_169 ( V_4 ) ;
V_92 += F_170 ( V_4 , V_185 , V_201 ) ;
if ( V_92 && ( V_168 & V_204 ) )
break;
if ( F_126 ( V_4 ) )
break;
if ( V_202 && ! V_92 )
break;
}
return V_92 ;
}
static bool F_171 ( struct V_1 * V_4 ,
int V_35 , bool V_201 )
{
if ( F_84 ( V_4 , V_35 , V_207 ) )
return true ;
if ( V_201 || ! V_184 )
return false ;
if ( F_84 ( V_4 , V_35 , V_208 ) )
return true ;
return false ;
}
static void F_172 ( struct V_1 * V_4 )
{
int V_35 ;
if ( ! F_101 ( & V_4 -> V_106 ) )
return;
if ( F_173 ( & V_4 -> V_209 ) > 1 )
return;
V_4 -> V_210 = V_211 [ V_212 ] ;
F_174 (nid, node_states[N_MEMORY]) {
if ( ! F_171 ( V_4 , V_35 , false ) )
F_175 ( V_35 , V_4 -> V_210 ) ;
}
F_176 ( & V_4 -> V_106 , 0 ) ;
F_176 ( & V_4 -> V_209 , 0 ) ;
}
int F_177 ( struct V_1 * V_4 )
{
int V_60 ;
F_172 ( V_4 ) ;
V_60 = V_4 -> V_213 ;
V_60 = F_178 ( V_60 , V_4 -> V_210 ) ;
if ( V_60 == V_105 )
V_60 = F_179 ( V_4 -> V_210 ) ;
if ( F_91 ( V_60 == V_105 ) )
V_60 = F_180 () ;
V_4 -> V_213 = V_60 ;
return V_60 ;
}
static bool F_181 ( struct V_1 * V_4 , bool V_201 )
{
int V_35 ;
if ( ! F_182 ( V_4 -> V_210 ) ) {
for ( V_35 = F_179 ( V_4 -> V_210 ) ;
V_35 < V_105 ;
V_35 = F_178 ( V_35 , V_4 -> V_210 ) ) {
if ( F_171 ( V_4 , V_35 , V_201 ) )
return true ;
}
}
F_86 (nid, N_MEMORY) {
if ( F_183 ( V_35 , V_4 -> V_210 ) )
continue;
if ( F_171 ( V_4 , V_35 , V_201 ) )
return true ;
}
return false ;
}
int F_177 ( struct V_1 * V_4 )
{
return 0 ;
}
static bool F_181 ( struct V_1 * V_4 , bool V_201 )
{
return F_171 ( V_4 , 0 , V_201 ) ;
}
static int F_184 ( struct V_1 * V_144 ,
struct V_61 * V_61 ,
T_4 V_185 ,
unsigned long * V_214 )
{
struct V_1 * V_215 = NULL ;
int V_92 = 0 ;
int V_202 = 0 ;
unsigned long V_58 ;
unsigned long V_216 ;
struct V_126 V_127 = {
. V_61 = V_61 ,
. V_133 = 0 ,
} ;
V_58 = F_59 ( & V_144 -> V_59 ) >> V_153 ;
while ( 1 ) {
V_215 = F_104 ( V_144 , V_215 , & V_127 ) ;
if ( ! V_215 ) {
V_202 ++ ;
if ( V_202 >= 2 ) {
if ( ! V_92 )
break;
if ( V_92 >= ( V_58 >> 2 ) ||
( V_202 > V_206 ) )
break;
}
continue;
}
if ( ! F_181 ( V_215 , false ) )
continue;
V_92 += F_185 ( V_215 , V_185 , false ,
V_61 , & V_216 ) ;
* V_214 += V_216 ;
if ( ! F_59 ( & V_144 -> V_59 ) )
break;
}
F_108 ( V_144 , V_215 ) ;
return V_92 ;
}
static bool F_186 ( struct V_1 * V_4 )
{
struct V_1 * V_120 , * V_217 = NULL ;
F_55 ( & V_218 ) ;
F_152 (iter, memcg) {
if ( V_120 -> V_219 ) {
V_217 = V_120 ;
F_108 ( V_4 , V_120 ) ;
break;
} else
V_120 -> V_219 = true ;
}
if ( V_217 ) {
F_152 (iter, memcg) {
if ( V_120 == V_217 ) {
F_108 ( V_4 , V_120 ) ;
break;
}
V_120 -> V_219 = false ;
}
} else
F_187 ( & V_220 , 0 , 1 , V_221 ) ;
F_56 ( & V_218 ) ;
return ! V_217 ;
}
static void F_188 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_55 ( & V_218 ) ;
F_189 ( & V_220 , 1 , V_221 ) ;
F_152 (iter, memcg)
V_120 -> V_219 = false ;
F_56 ( & V_218 ) ;
}
static void F_190 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_152 (iter, memcg)
F_93 ( & V_120 -> V_222 ) ;
}
static void F_191 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_152 (iter, memcg)
F_192 ( & V_120 -> V_222 , - 1 , 0 ) ;
}
static int F_193 ( T_5 * V_165 ,
unsigned V_223 , int V_224 , void * V_225 )
{
struct V_1 * V_226 = (struct V_1 * ) V_225 ;
struct V_1 * V_227 ;
struct V_228 * V_228 ;
V_228 = F_16 ( V_165 , struct V_228 , V_165 ) ;
V_227 = V_228 -> V_4 ;
if ( ! F_120 ( V_227 , V_226 )
&& ! F_120 ( V_226 , V_227 ) )
return 0 ;
return F_194 ( V_165 , V_223 , V_224 , V_225 ) ;
}
static void F_195 ( struct V_1 * V_4 )
{
F_93 ( & V_4 -> V_229 ) ;
F_196 ( & V_230 , V_231 , 0 , V_4 ) ;
}
static void F_197 ( struct V_1 * V_4 )
{
if ( V_4 && F_101 ( & V_4 -> V_222 ) )
F_195 ( V_4 ) ;
}
static void F_198 ( struct V_1 * V_4 , T_4 V_232 , int V_186 )
{
if ( ! V_26 -> V_233 . V_234 )
return;
F_23 ( & V_4 -> V_15 ) ;
V_26 -> V_233 . V_4 = V_4 ;
V_26 -> V_233 . V_185 = V_232 ;
V_26 -> V_233 . V_186 = V_186 ;
}
bool F_199 ( bool V_235 )
{
struct V_1 * V_4 = V_26 -> V_233 . V_4 ;
struct V_228 V_236 ;
bool V_237 ;
if ( ! V_4 )
return false ;
if ( ! V_235 )
goto V_238;
V_236 . V_4 = V_4 ;
V_236 . V_165 . V_168 = 0 ;
V_236 . V_165 . V_239 = F_193 ;
V_236 . V_165 . V_240 = V_26 ;
F_200 ( & V_236 . V_165 . V_241 ) ;
F_140 ( & V_230 , & V_236 . V_165 , V_242 ) ;
F_190 ( V_4 ) ;
V_237 = F_186 ( V_4 ) ;
if ( V_237 )
F_201 ( V_4 ) ;
if ( V_237 && ! V_4 -> V_243 ) {
F_191 ( V_4 ) ;
F_142 ( & V_230 , & V_236 . V_165 ) ;
F_156 ( V_4 , V_26 -> V_233 . V_185 ,
V_26 -> V_233 . V_186 ) ;
} else {
F_141 () ;
F_191 ( V_4 ) ;
F_142 ( & V_230 , & V_236 . V_165 ) ;
}
if ( V_237 ) {
F_188 ( V_4 ) ;
F_197 ( V_4 ) ;
}
V_238:
V_26 -> V_233 . V_4 = NULL ;
F_31 ( & V_4 -> V_15 ) ;
return true ;
}
void F_202 ( struct V_39 * V_39 ,
bool * V_237 , unsigned long * V_168 )
{
struct V_1 * V_4 ;
struct V_142 * V_143 ;
V_143 = F_114 ( V_39 ) ;
V_244:
V_4 = V_143 -> V_1 ;
if ( F_91 ( ! V_4 || ! F_116 ( V_143 ) ) )
return;
if ( ! F_135 ( V_4 ) )
return;
F_143 ( V_4 , V_168 ) ;
if ( V_4 != V_143 -> V_1 || ! F_116 ( V_143 ) ) {
F_145 ( V_4 , V_168 ) ;
goto V_244;
}
* V_237 = true ;
}
void F_203 ( struct V_39 * V_39 , unsigned long * V_168 )
{
struct V_142 * V_143 = F_114 ( V_39 ) ;
F_145 ( V_143 -> V_1 , V_168 ) ;
}
void F_204 ( struct V_39 * V_39 ,
enum V_66 V_67 , int V_68 )
{
struct V_1 * V_4 ;
struct V_142 * V_143 = F_114 ( V_39 ) ;
unsigned long V_130 ( V_168 ) ;
if ( F_105 () )
return;
F_41 ( ! F_136 () ) ;
V_4 = V_143 -> V_1 ;
if ( F_91 ( ! V_4 || ! F_116 ( V_143 ) ) )
return;
F_72 ( V_4 -> V_70 -> V_71 [ V_67 ] , V_68 ) ;
}
static bool F_205 ( struct V_1 * V_4 , unsigned int V_79 )
{
struct V_245 * V_246 ;
bool V_91 = true ;
if ( V_79 > V_247 )
return false ;
V_246 = & F_206 ( V_248 ) ;
if ( V_4 == V_246 -> V_249 && V_246 -> V_79 >= V_79 )
V_246 -> V_79 -= V_79 ;
else
V_91 = false ;
F_207 ( V_248 ) ;
return V_91 ;
}
static void F_208 ( struct V_245 * V_246 )
{
struct V_1 * V_250 = V_246 -> V_249 ;
if ( V_246 -> V_79 ) {
unsigned long V_251 = V_246 -> V_79 * V_252 ;
F_209 ( & V_250 -> V_59 , V_251 ) ;
if ( V_155 )
F_209 ( & V_250 -> V_156 , V_251 ) ;
V_246 -> V_79 = 0 ;
}
V_246 -> V_249 = NULL ;
}
static void F_210 ( struct V_253 * V_254 )
{
struct V_245 * V_246 = & F_211 ( V_248 ) ;
F_208 ( V_246 ) ;
F_8 ( V_255 , & V_246 -> V_168 ) ;
}
static void T_6 F_212 ( void )
{
int V_69 ;
F_213 (cpu) {
struct V_245 * V_246 =
& F_68 ( V_248 , V_69 ) ;
F_214 ( & V_246 -> V_256 , F_210 ) ;
}
}
static void F_215 ( struct V_1 * V_4 , unsigned int V_79 )
{
struct V_245 * V_246 = & F_206 ( V_248 ) ;
if ( V_246 -> V_249 != V_4 ) {
F_208 ( V_246 ) ;
V_246 -> V_249 = V_4 ;
}
V_246 -> V_79 += V_79 ;
F_207 ( V_248 ) ;
}
static void F_216 ( struct V_1 * V_144 , bool V_224 )
{
int V_69 , V_257 ;
F_66 () ;
V_257 = F_217 () ;
F_67 (cpu) {
struct V_245 * V_246 = & F_68 ( V_248 , V_69 ) ;
struct V_1 * V_4 ;
V_4 = V_246 -> V_249 ;
if ( ! V_4 || ! V_246 -> V_79 )
continue;
if ( ! F_120 ( V_144 , V_4 ) )
continue;
if ( ! F_218 ( V_255 , & V_246 -> V_168 ) ) {
if ( V_69 == V_257 )
F_210 ( & V_246 -> V_256 ) ;
else
F_219 ( V_69 , & V_246 -> V_256 ) ;
}
}
F_220 () ;
if ( ! V_224 )
goto V_137;
F_67 (cpu) {
struct V_245 * V_246 = & F_68 ( V_248 , V_69 ) ;
if ( F_5 ( V_255 , & V_246 -> V_168 ) )
F_221 ( & V_246 -> V_256 ) ;
}
V_137:
F_70 () ;
}
static void F_169 ( struct V_1 * V_144 )
{
if ( ! F_222 ( & V_258 ) )
return;
F_216 ( V_144 , false ) ;
F_223 ( & V_258 ) ;
}
static void F_224 ( struct V_1 * V_144 )
{
F_225 ( & V_258 ) ;
F_216 ( V_144 , true ) ;
F_223 ( & V_258 ) ;
}
static void F_226 ( struct V_1 * V_4 , int V_69 )
{
int V_175 ;
F_55 ( & V_4 -> V_72 ) ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
long V_259 = F_68 ( V_4 -> V_70 -> V_71 [ V_175 ] , V_69 ) ;
F_68 ( V_4 -> V_70 -> V_71 [ V_175 ] , V_69 ) = 0 ;
V_4 -> V_73 . V_71 [ V_175 ] += V_259 ;
}
for ( V_175 = 0 ; V_175 < V_260 ; V_175 ++ ) {
unsigned long V_259 = F_68 ( V_4 -> V_70 -> V_77 [ V_175 ] , V_69 ) ;
F_68 ( V_4 -> V_70 -> V_77 [ V_175 ] , V_69 ) = 0 ;
V_4 -> V_73 . V_77 [ V_175 ] += V_259 ;
}
F_56 ( & V_4 -> V_72 ) ;
}
static int F_227 ( struct V_261 * V_262 ,
unsigned long V_263 ,
void * V_264 )
{
int V_69 = ( unsigned long ) V_264 ;
struct V_245 * V_246 ;
struct V_1 * V_120 ;
if ( V_263 == V_265 )
return V_266 ;
if ( V_263 != V_267 && V_263 != V_268 )
return V_266 ;
F_228 (iter)
F_226 ( V_120 , V_69 ) ;
V_246 = & F_68 ( V_248 , V_69 ) ;
F_208 ( V_246 ) ;
return V_266 ;
}
static int F_229 ( struct V_1 * V_4 , T_4 V_185 ,
unsigned int V_79 , unsigned int V_269 ,
bool V_270 )
{
unsigned long V_271 = V_79 * V_252 ;
struct V_1 * V_272 ;
struct V_273 * V_274 ;
unsigned long V_168 = 0 ;
int V_91 ;
V_91 = F_230 ( & V_4 -> V_59 , V_271 , & V_274 ) ;
if ( F_231 ( ! V_91 ) ) {
if ( ! V_155 )
return V_275 ;
V_91 = F_230 ( & V_4 -> V_156 , V_271 , & V_274 ) ;
if ( F_231 ( ! V_91 ) )
return V_275 ;
F_209 ( & V_4 -> V_59 , V_271 ) ;
V_272 = F_232 ( V_274 , V_156 ) ;
V_168 |= V_203 ;
} else
V_272 = F_232 ( V_274 , V_59 ) ;
if ( V_79 > V_269 )
return V_276 ;
if ( ! ( V_185 & V_277 ) )
return V_278 ;
if ( V_185 & V_279 )
return V_280 ;
V_91 = F_168 ( V_272 , V_185 , V_168 ) ;
if ( F_126 ( V_272 ) >= V_79 )
return V_276 ;
if ( V_79 <= ( 1 << V_281 ) && V_91 )
return V_276 ;
if ( F_138 ( V_272 ) )
return V_276 ;
if ( V_270 )
F_198 ( V_272 , V_185 , F_233 ( V_271 ) ) ;
return V_280 ;
}
static int F_234 ( struct V_109 * V_110 ,
T_4 V_185 ,
unsigned int V_79 ,
struct V_1 * * V_282 ,
bool V_283 )
{
unsigned int V_284 = F_235 ( V_247 , V_79 ) ;
int V_285 = V_286 ;
struct V_1 * V_4 = NULL ;
int V_91 ;
if ( F_91 ( F_236 ( V_192 )
|| F_157 ( V_26 ) ) )
goto V_287;
if ( F_91 ( F_237 ( V_26 ) ) )
goto V_287;
if ( ! * V_282 && ! V_110 )
* V_282 = V_17 ;
V_244:
if ( * V_282 ) {
V_4 = * V_282 ;
if ( F_20 ( V_4 ) )
goto V_65;
if ( F_205 ( V_4 , V_79 ) )
goto V_65;
F_23 ( & V_4 -> V_15 ) ;
} else {
struct V_107 * V_48 ;
F_24 () ;
V_48 = F_96 ( V_110 -> V_111 ) ;
V_4 = F_25 ( V_48 ) ;
if ( ! V_4 )
V_4 = V_17 ;
if ( F_20 ( V_4 ) ) {
F_28 () ;
goto V_65;
}
if ( F_205 ( V_4 , V_79 ) ) {
F_28 () ;
goto V_65;
}
if ( ! F_27 ( & V_4 -> V_15 ) ) {
F_28 () ;
goto V_244;
}
F_28 () ;
}
do {
bool V_270 = V_283 && ! V_285 ;
if ( F_157 ( V_26 ) ) {
F_31 ( & V_4 -> V_15 ) ;
goto V_287;
}
V_91 = F_229 ( V_4 , V_185 , V_284 ,
V_79 , V_270 ) ;
switch ( V_91 ) {
case V_275 :
break;
case V_276 :
V_284 = V_79 ;
F_31 ( & V_4 -> V_15 ) ;
V_4 = NULL ;
goto V_244;
case V_278 :
F_31 ( & V_4 -> V_15 ) ;
goto V_288;
case V_280 :
if ( ! V_283 || V_270 ) {
F_31 ( & V_4 -> V_15 ) ;
goto V_288;
}
V_285 -- ;
break;
}
} while ( V_91 != V_275 );
if ( V_284 > V_79 )
F_215 ( V_4 , V_284 - V_79 ) ;
F_31 ( & V_4 -> V_15 ) ;
V_65:
* V_282 = V_4 ;
return 0 ;
V_288:
if ( ! ( V_185 & V_289 ) ) {
* V_282 = NULL ;
return - V_290 ;
}
V_287:
* V_282 = V_17 ;
return - V_291 ;
}
static void F_238 ( struct V_1 * V_4 ,
unsigned int V_79 )
{
if ( ! F_20 ( V_4 ) ) {
unsigned long V_251 = V_79 * V_252 ;
F_209 ( & V_4 -> V_59 , V_251 ) ;
if ( V_155 )
F_209 ( & V_4 -> V_156 , V_251 ) ;
}
}
static void F_239 ( struct V_1 * V_4 ,
unsigned int V_79 )
{
unsigned long V_251 = V_79 * V_252 ;
if ( F_20 ( V_4 ) )
return;
F_240 ( & V_4 -> V_59 , V_4 -> V_59 . V_50 , V_251 ) ;
if ( V_155 )
F_240 ( & V_4 -> V_156 ,
V_4 -> V_156 . V_50 , V_251 ) ;
}
static struct V_1 * F_241 ( unsigned short V_292 )
{
struct V_13 * V_15 ;
if ( ! V_292 )
return NULL ;
V_15 = F_242 ( & V_293 , V_292 ) ;
if ( ! V_15 )
return NULL ;
return F_15 ( V_15 ) ;
}
struct V_1 * F_243 ( struct V_39 * V_39 )
{
struct V_1 * V_4 = NULL ;
struct V_142 * V_143 ;
unsigned short V_292 ;
T_7 V_294 ;
F_41 ( ! F_244 ( V_39 ) ) ;
V_143 = F_114 ( V_39 ) ;
F_245 ( V_143 ) ;
if ( F_116 ( V_143 ) ) {
V_4 = V_143 -> V_1 ;
if ( V_4 && ! F_27 ( & V_4 -> V_15 ) )
V_4 = NULL ;
} else if ( F_246 ( V_39 ) ) {
V_294 . V_68 = F_247 ( V_39 ) ;
V_292 = F_248 ( V_294 ) ;
F_24 () ;
V_4 = F_241 ( V_292 ) ;
if ( V_4 && ! F_27 ( & V_4 -> V_15 ) )
V_4 = NULL ;
F_28 () ;
}
F_249 ( V_143 ) ;
return V_4 ;
}
static void F_250 ( struct V_1 * V_4 ,
struct V_39 * V_39 ,
unsigned int V_79 ,
enum V_295 V_296 ,
bool V_297 )
{
struct V_142 * V_143 = F_114 ( V_39 ) ;
struct V_61 * V_130 ( V_61 ) ;
struct V_86 * V_86 ;
bool V_298 = false ;
bool V_78 ;
F_245 ( V_143 ) ;
F_41 ( F_116 ( V_143 ) ) ;
if ( V_297 ) {
V_61 = F_251 ( V_39 ) ;
F_252 ( & V_61 -> V_299 ) ;
if ( F_115 ( V_39 ) ) {
V_86 = F_112 ( V_61 , V_143 -> V_1 ) ;
F_253 ( V_39 ) ;
F_254 ( V_39 , V_86 , F_255 ( V_39 ) ) ;
V_298 = true ;
}
}
V_143 -> V_1 = V_4 ;
F_10 () ;
F_256 ( V_143 ) ;
if ( V_297 ) {
if ( V_298 ) {
V_86 = F_112 ( V_61 , V_143 -> V_1 ) ;
F_41 ( F_115 ( V_39 ) ) ;
F_257 ( V_39 ) ;
F_258 ( V_39 , V_86 , F_255 ( V_39 ) ) ;
}
F_259 ( & V_61 -> V_299 ) ;
}
if ( V_296 == V_300 )
V_78 = true ;
else
V_78 = false ;
F_74 ( V_4 , V_39 , V_78 , V_79 ) ;
F_249 ( V_143 ) ;
F_90 ( V_4 , V_39 ) ;
}
static inline bool F_260 ( struct V_1 * V_4 )
{
return ! F_105 () && ! F_20 ( V_4 ) &&
( V_4 -> V_6 & V_301 ) ;
}
static struct V_302 * F_261 ( struct V_303 * V_48 )
{
struct V_302 * V_304 ;
F_41 ( V_48 -> V_305 ) ;
V_304 = V_48 -> V_306 ;
return V_304 -> V_307 -> V_308 [ F_262 ( V_48 -> V_4 ) ] ;
}
static int F_263 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_311 * V_312 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_303 * V_313 ;
if ( ! F_260 ( V_4 ) )
return - V_314 ;
F_264 ( V_312 ) ;
F_225 ( & V_4 -> V_315 ) ;
F_265 (params, &memcg->memcg_slab_caches, list)
F_266 ( F_261 ( V_313 ) , V_312 ) ;
F_223 ( & V_4 -> V_315 ) ;
return 0 ;
}
static int F_267 ( struct V_1 * V_4 , T_4 V_316 , T_2 V_317 )
{
struct V_273 * V_274 ;
struct V_1 * V_318 ;
int V_91 = 0 ;
bool V_234 ;
V_91 = F_230 ( & V_4 -> V_32 , V_317 , & V_274 ) ;
if ( V_91 )
return V_91 ;
V_234 = ( V_316 & V_319 ) && ! ( V_316 & V_279 ) ;
V_318 = V_4 ;
V_91 = F_234 ( NULL , V_316 , V_317 >> V_153 ,
& V_318 , V_234 ) ;
if ( V_91 == - V_291 ) {
F_268 ( & V_4 -> V_59 , V_317 , & V_274 ) ;
if ( V_155 )
F_268 ( & V_4 -> V_156 , V_317 ,
& V_274 ) ;
V_91 = 0 ;
} else if ( V_91 )
F_209 ( & V_4 -> V_32 , V_317 ) ;
return V_91 ;
}
static void F_269 ( struct V_1 * V_4 , T_2 V_317 )
{
F_209 ( & V_4 -> V_59 , V_317 ) ;
if ( V_155 )
F_209 ( & V_4 -> V_156 , V_317 ) ;
if ( F_209 ( & V_4 -> V_32 , V_317 ) )
return;
if ( F_11 ( V_4 ) )
F_31 ( & V_4 -> V_15 ) ;
}
void F_270 ( struct V_1 * V_4 , struct V_302 * V_304 )
{
if ( ! V_4 )
return;
F_225 ( & V_4 -> V_315 ) ;
F_271 ( & V_304 -> V_307 -> V_320 , & V_4 -> V_321 ) ;
F_223 ( & V_4 -> V_315 ) ;
}
int F_262 ( struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_31 : - 1 ;
}
int F_272 ( struct V_1 * V_4 )
{
int V_182 , V_91 ;
V_182 = F_273 ( & V_30 ,
0 , V_322 , V_323 ) ;
if ( V_182 < 0 )
return V_182 ;
F_6 ( V_4 ) ;
V_91 = F_274 ( V_182 + 1 ) ;
if ( V_91 ) {
F_37 ( & V_30 , V_182 ) ;
F_7 ( V_4 ) ;
return V_91 ;
}
V_4 -> V_31 = V_182 ;
F_200 ( & V_4 -> V_321 ) ;
F_275 ( & V_4 -> V_315 ) ;
return 0 ;
}
static T_1 F_276 ( int V_324 )
{
T_8 V_317 ;
if ( V_324 <= 0 )
return 0 ;
V_317 = 2 * V_324 ;
if ( V_317 < V_325 )
V_317 = V_325 ;
else if ( V_317 > V_322 )
V_317 = V_322 ;
return V_317 ;
}
void F_277 ( int V_182 )
{
if ( V_182 > V_326 )
V_326 = F_276 ( V_182 ) ;
}
int F_278 ( struct V_302 * V_14 , int V_324 )
{
struct V_303 * V_327 = V_14 -> V_307 ;
F_41 ( V_14 -> V_307 && ! V_14 -> V_307 -> V_305 ) ;
if ( V_324 > V_326 ) {
int V_175 ;
T_8 V_317 = F_276 ( V_324 ) ;
V_317 *= sizeof( void * ) ;
V_317 += F_279 ( struct V_303 , V_308 ) ;
V_14 -> V_307 = F_280 ( V_317 , V_323 ) ;
if ( ! V_14 -> V_307 ) {
V_14 -> V_307 = V_327 ;
return - V_290 ;
}
V_14 -> V_307 -> V_305 = true ;
for ( V_175 = 0 ; V_175 < V_326 ; V_175 ++ ) {
if ( ! V_327 -> V_308 [ V_175 ] )
continue;
V_14 -> V_307 -> V_308 [ V_175 ] =
V_327 -> V_308 [ V_175 ] ;
}
F_281 ( V_327 ) ;
}
return 0 ;
}
int F_282 ( struct V_1 * V_4 , struct V_302 * V_14 ,
struct V_302 * V_306 )
{
T_1 V_317 ;
if ( ! F_283 () )
return 0 ;
if ( ! V_4 ) {
V_317 = F_279 ( struct V_303 , V_308 ) ;
V_317 += V_326 * sizeof( void * ) ;
} else
V_317 = sizeof( struct V_303 ) ;
V_14 -> V_307 = F_280 ( V_317 , V_323 ) ;
if ( ! V_14 -> V_307 )
return - V_290 ;
if ( V_4 ) {
V_14 -> V_307 -> V_4 = V_4 ;
V_14 -> V_307 -> V_306 = V_306 ;
F_214 ( & V_14 -> V_307 -> V_328 ,
V_329 ) ;
} else
V_14 -> V_307 -> V_305 = true ;
return 0 ;
}
void F_284 ( struct V_302 * V_14 )
{
struct V_302 * V_112 ;
struct V_1 * V_4 ;
int V_292 ;
if ( ! V_14 -> V_307 )
return;
if ( V_14 -> V_307 -> V_305 )
goto V_137;
V_4 = V_14 -> V_307 -> V_4 ;
V_292 = F_262 ( V_4 ) ;
V_112 = V_14 -> V_307 -> V_306 ;
V_112 -> V_307 -> V_308 [ V_292 ] = NULL ;
F_225 ( & V_4 -> V_315 ) ;
F_285 ( & V_14 -> V_307 -> V_320 ) ;
F_223 ( & V_4 -> V_315 ) ;
F_31 ( & V_4 -> V_15 ) ;
V_137:
F_281 ( V_14 -> V_307 ) ;
}
static inline void F_286 ( void )
{
F_41 ( ! V_26 -> V_110 ) ;
V_26 -> V_330 ++ ;
}
static inline void F_287 ( void )
{
F_41 ( ! V_26 -> V_110 ) ;
V_26 -> V_330 -- ;
}
static void V_329 ( struct V_253 * V_331 )
{
struct V_302 * V_304 ;
struct V_303 * V_48 ;
V_48 = F_16 ( V_331 , struct V_303 , V_328 ) ;
V_304 = F_261 ( V_48 ) ;
if ( F_101 ( & V_304 -> V_307 -> V_79 ) != 0 ) {
F_288 ( V_304 ) ;
if ( F_101 ( & V_304 -> V_307 -> V_79 ) == 0 )
return;
} else
F_289 ( V_304 ) ;
}
void F_290 ( struct V_302 * V_304 )
{
if ( ! V_304 -> V_307 -> V_332 )
return;
if ( F_291 ( & V_304 -> V_307 -> V_328 ) )
return;
F_292 ( & V_304 -> V_307 -> V_328 ) ;
}
static struct V_302 * F_293 ( struct V_1 * V_4 ,
struct V_302 * V_14 )
{
struct V_302 * V_333 ;
static char * V_334 = NULL ;
F_294 ( & V_335 ) ;
if ( ! V_334 ) {
V_334 = F_295 ( V_174 , V_323 ) ;
if ( ! V_334 )
return NULL ;
}
F_24 () ;
snprintf ( V_334 , V_174 , L_13 , V_14 -> V_336 ,
F_262 ( V_4 ) , F_296 ( V_4 -> V_15 . V_170 ) ) ;
F_28 () ;
V_333 = F_297 ( V_4 , V_334 , V_14 -> V_337 , V_14 -> V_338 ,
( V_14 -> V_168 & ~ V_339 ) , V_14 -> V_340 , V_14 ) ;
if ( V_333 )
V_333 -> V_341 |= V_342 ;
return V_333 ;
}
static struct V_302 * F_298 ( struct V_1 * V_4 ,
struct V_302 * V_304 )
{
struct V_302 * V_343 ;
int V_67 ;
F_22 ( ! F_260 ( V_4 ) ) ;
V_67 = F_262 ( V_4 ) ;
F_225 ( & V_335 ) ;
V_343 = V_304 -> V_307 -> V_308 [ V_67 ] ;
if ( V_343 ) {
F_31 ( & V_4 -> V_15 ) ;
goto V_137;
}
V_343 = F_293 ( V_4 , V_304 ) ;
if ( V_343 == NULL ) {
V_343 = V_304 ;
F_31 ( & V_4 -> V_15 ) ;
goto V_137;
}
F_176 ( & V_343 -> V_307 -> V_79 , 0 ) ;
V_304 -> V_307 -> V_308 [ V_67 ] = V_343 ;
F_299 () ;
V_137:
F_223 ( & V_335 ) ;
return V_343 ;
}
void F_300 ( struct V_302 * V_14 )
{
struct V_302 * V_344 ;
int V_175 ;
if ( ! V_14 -> V_307 )
return;
if ( ! V_14 -> V_307 -> V_305 )
return;
F_225 ( & V_345 ) ;
for ( V_175 = 0 ; V_175 < V_326 ; V_175 ++ ) {
V_344 = V_14 -> V_307 -> V_308 [ V_175 ] ;
if ( ! V_344 )
continue;
V_344 -> V_307 -> V_332 = false ;
F_301 ( & V_344 -> V_307 -> V_328 ) ;
F_289 ( V_344 ) ;
}
F_223 ( & V_345 ) ;
}
static void F_302 ( struct V_1 * V_4 )
{
struct V_302 * V_304 ;
struct V_303 * V_313 ;
if ( ! F_4 ( V_4 ) )
return;
F_225 ( & V_4 -> V_315 ) ;
F_265 (params, &memcg->memcg_slab_caches, list) {
V_304 = F_261 ( V_313 ) ;
V_304 -> V_307 -> V_332 = true ;
F_292 ( & V_304 -> V_307 -> V_328 ) ;
}
F_223 ( & V_4 -> V_315 ) ;
}
static void F_303 ( struct V_253 * V_331 )
{
struct V_346 * V_347 ;
V_347 = F_16 ( V_331 , struct V_346 , V_256 ) ;
F_298 ( V_347 -> V_4 , V_347 -> V_304 ) ;
F_281 ( V_347 ) ;
}
static void F_304 ( struct V_1 * V_4 ,
struct V_302 * V_304 )
{
struct V_346 * V_347 ;
V_347 = F_295 ( sizeof( struct V_346 ) , V_348 ) ;
if ( V_347 == NULL ) {
F_31 ( & V_4 -> V_15 ) ;
return;
}
V_347 -> V_4 = V_4 ;
V_347 -> V_304 = V_304 ;
F_214 ( & V_347 -> V_256 , F_303 ) ;
F_292 ( & V_347 -> V_256 ) ;
}
static void F_305 ( struct V_1 * V_4 ,
struct V_302 * V_304 )
{
F_286 () ;
F_304 ( V_4 , V_304 ) ;
F_287 () ;
}
struct V_302 * F_306 ( struct V_302 * V_304 ,
T_4 V_316 )
{
struct V_1 * V_4 ;
int V_67 ;
F_41 ( ! V_304 -> V_307 ) ;
F_41 ( ! V_304 -> V_307 -> V_305 ) ;
if ( ! V_26 -> V_110 || V_26 -> V_330 )
return V_304 ;
F_24 () ;
V_4 = F_25 ( F_96 ( V_26 -> V_110 -> V_111 ) ) ;
if ( ! F_260 ( V_4 ) )
goto V_137;
V_67 = F_262 ( V_4 ) ;
F_307 () ;
if ( F_231 ( V_304 -> V_307 -> V_308 [ V_67 ] ) ) {
V_304 = V_304 -> V_307 -> V_308 [ V_67 ] ;
goto V_137;
}
if ( ! F_27 ( & V_4 -> V_15 ) )
goto V_137;
F_28 () ;
F_305 ( V_4 , V_304 ) ;
return V_304 ;
V_137:
F_28 () ;
return V_304 ;
}
bool
F_308 ( T_4 V_316 , struct V_1 * * V_318 , int V_186 )
{
struct V_1 * V_4 ;
int V_91 ;
* V_318 = NULL ;
if ( ! V_26 -> V_110 || V_26 -> V_330 )
return true ;
V_4 = F_95 ( V_26 -> V_110 ) ;
if ( F_91 ( ! V_4 ) )
return true ;
if ( ! F_260 ( V_4 ) ) {
F_31 ( & V_4 -> V_15 ) ;
return true ;
}
V_91 = F_267 ( V_4 , V_316 , V_252 << V_186 ) ;
if ( ! V_91 )
* V_318 = V_4 ;
F_31 ( & V_4 -> V_15 ) ;
return ( V_91 == 0 ) ;
}
void F_309 ( struct V_39 * V_39 , struct V_1 * V_4 ,
int V_186 )
{
struct V_142 * V_143 ;
F_41 ( F_20 ( V_4 ) ) ;
if ( ! V_39 ) {
F_269 ( V_4 , V_252 << V_186 ) ;
return;
}
V_143 = F_114 ( V_39 ) ;
F_245 ( V_143 ) ;
V_143 -> V_1 = V_4 ;
F_256 ( V_143 ) ;
F_249 ( V_143 ) ;
}
void F_310 ( struct V_39 * V_39 , int V_186 )
{
struct V_1 * V_4 = NULL ;
struct V_142 * V_143 ;
V_143 = F_114 ( V_39 ) ;
if ( ! F_116 ( V_143 ) )
return;
F_245 ( V_143 ) ;
if ( F_116 ( V_143 ) ) {
V_4 = V_143 -> V_1 ;
F_311 ( V_143 ) ;
}
F_249 ( V_143 ) ;
if ( ! V_4 )
return;
F_41 ( F_20 ( V_4 ) ) ;
F_269 ( V_4 , V_252 << V_186 ) ;
}
static inline void F_302 ( struct V_1 * V_4 )
{
}
void F_312 ( struct V_39 * V_349 )
{
struct V_142 * V_350 = F_114 ( V_349 ) ;
struct V_142 * V_143 ;
struct V_1 * V_4 ;
int V_175 ;
if ( F_105 () )
return;
V_4 = V_350 -> V_1 ;
for ( V_175 = 1 ; V_175 < V_351 ; V_175 ++ ) {
V_143 = V_350 + V_175 ;
V_143 -> V_1 = V_4 ;
F_10 () ;
V_143 -> V_168 = V_350 -> V_168 & ~ V_352 ;
}
F_313 ( V_4 -> V_70 -> V_71 [ V_82 ] ,
V_351 ) ;
}
static inline
void F_314 ( struct V_1 * V_161 ,
struct V_1 * V_162 ,
unsigned int V_79 ,
enum V_66 V_67 )
{
F_75 () ;
F_313 ( V_161 -> V_70 -> V_71 [ V_67 ] , V_79 ) ;
F_76 ( V_162 -> V_70 -> V_71 [ V_67 ] , V_79 ) ;
F_79 () ;
}
static int F_315 ( struct V_39 * V_39 ,
unsigned int V_79 ,
struct V_142 * V_143 ,
struct V_1 * V_161 ,
struct V_1 * V_162 )
{
unsigned long V_168 ;
int V_91 ;
bool V_78 = F_316 ( V_39 ) ;
F_41 ( V_161 == V_162 ) ;
F_41 ( F_115 ( V_39 ) ) ;
V_91 = - V_353 ;
if ( V_79 > 1 && ! F_77 ( V_39 ) )
goto V_137;
F_245 ( V_143 ) ;
V_91 = - V_354 ;
if ( ! F_116 ( V_143 ) || V_143 -> V_1 != V_161 )
goto V_163;
F_143 ( V_161 , & V_168 ) ;
if ( ! V_78 && F_317 ( V_39 ) )
F_314 ( V_161 , V_162 , V_79 ,
V_355 ) ;
if ( F_318 ( V_39 ) )
F_314 ( V_161 , V_162 , V_79 ,
V_356 ) ;
F_74 ( V_161 , V_39 , V_78 , - V_79 ) ;
V_143 -> V_1 = V_162 ;
F_74 ( V_162 , V_39 , V_78 , V_79 ) ;
F_145 ( V_161 , & V_168 ) ;
V_91 = 0 ;
V_163:
F_249 ( V_143 ) ;
F_90 ( V_162 , V_39 ) ;
F_90 ( V_161 , V_39 ) ;
V_137:
return V_91 ;
}
static int F_319 ( struct V_39 * V_39 ,
struct V_142 * V_143 ,
struct V_1 * V_357 )
{
struct V_1 * V_50 ;
unsigned int V_79 ;
unsigned long V_130 ( V_168 ) ;
int V_91 ;
F_41 ( F_20 ( V_357 ) ) ;
V_91 = - V_353 ;
if ( ! F_320 ( V_39 ) )
goto V_137;
if ( F_321 ( V_39 ) )
goto V_358;
V_79 = F_322 ( V_39 ) ;
V_50 = F_58 ( V_357 ) ;
if ( ! V_50 )
V_50 = V_17 ;
if ( V_79 > 1 ) {
F_41 ( ! F_77 ( V_39 ) ) ;
V_168 = F_323 ( V_39 ) ;
}
V_91 = F_315 ( V_39 , V_79 ,
V_143 , V_357 , V_50 ) ;
if ( ! V_91 )
F_239 ( V_357 , V_79 ) ;
if ( V_79 > 1 )
F_324 ( V_39 , V_168 ) ;
F_325 ( V_39 ) ;
V_358:
F_326 ( V_39 ) ;
V_137:
return V_91 ;
}
static int F_327 ( struct V_39 * V_39 , struct V_109 * V_110 ,
T_4 V_185 , enum V_295 V_296 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_79 = 1 ;
bool V_283 = true ;
int V_91 ;
if ( F_77 ( V_39 ) ) {
V_79 <<= F_328 ( V_39 ) ;
F_41 ( ! F_77 ( V_39 ) ) ;
V_283 = false ;
}
V_91 = F_234 ( V_110 , V_185 , V_79 , & V_4 , V_283 ) ;
if ( V_91 == - V_290 )
return V_91 ;
F_250 ( V_4 , V_39 , V_79 , V_296 , false ) ;
return 0 ;
}
int F_329 ( struct V_39 * V_39 ,
struct V_109 * V_110 , T_4 V_185 )
{
if ( F_105 () )
return 0 ;
F_41 ( F_317 ( V_39 ) ) ;
F_41 ( V_39 -> V_359 && ! F_316 ( V_39 ) ) ;
F_41 ( ! V_110 ) ;
return F_327 ( V_39 , V_110 , V_185 ,
V_300 ) ;
}
static int F_330 ( struct V_109 * V_110 ,
struct V_39 * V_39 ,
T_4 V_232 ,
struct V_1 * * V_360 )
{
struct V_1 * V_4 ;
struct V_142 * V_143 ;
int V_91 ;
V_143 = F_114 ( V_39 ) ;
if ( F_116 ( V_143 ) )
return 0 ;
if ( ! V_155 )
goto V_361;
V_4 = F_243 ( V_39 ) ;
if ( ! V_4 )
goto V_361;
* V_360 = V_4 ;
V_91 = F_234 ( NULL , V_232 , 1 , V_360 , true ) ;
F_31 ( & V_4 -> V_15 ) ;
if ( V_91 == - V_291 )
V_91 = 0 ;
return V_91 ;
V_361:
V_91 = F_234 ( V_110 , V_232 , 1 , V_360 , true ) ;
if ( V_91 == - V_291 )
V_91 = 0 ;
return V_91 ;
}
int F_331 ( struct V_109 * V_110 , struct V_39 * V_39 ,
T_4 V_185 , struct V_1 * * V_360 )
{
* V_360 = NULL ;
if ( F_105 () )
return 0 ;
if ( ! F_246 ( V_39 ) ) {
int V_91 ;
V_91 = F_234 ( V_110 , V_185 , 1 , V_360 , true ) ;
if ( V_91 == - V_291 )
V_91 = 0 ;
return V_91 ;
}
return F_330 ( V_110 , V_39 , V_185 , V_360 ) ;
}
void F_332 ( struct V_1 * V_4 )
{
if ( F_105 () )
return;
if ( ! V_4 )
return;
F_238 ( V_4 , 1 ) ;
}
static void
F_333 ( struct V_39 * V_39 , struct V_1 * V_4 ,
enum V_295 V_296 )
{
if ( F_105 () )
return;
if ( ! V_4 )
return;
F_250 ( V_4 , V_39 , 1 , V_296 , true ) ;
if ( V_155 && F_246 ( V_39 ) ) {
T_7 V_294 = { . V_68 = F_247 (page) } ;
F_334 ( V_294 ) ;
}
}
void F_335 ( struct V_39 * V_39 ,
struct V_1 * V_4 )
{
F_333 ( V_39 , V_4 ,
V_300 ) ;
}
int F_336 ( struct V_39 * V_39 , struct V_109 * V_110 ,
T_4 V_185 )
{
struct V_1 * V_4 = NULL ;
enum V_295 type = V_362 ;
int V_91 ;
if ( F_105 () )
return 0 ;
if ( F_337 ( V_39 ) )
return 0 ;
if ( ! F_246 ( V_39 ) )
V_91 = F_327 ( V_39 , V_110 , V_185 , type ) ;
else {
V_91 = F_330 ( V_110 , V_39 ,
V_185 , & V_4 ) ;
if ( ! V_91 )
F_333 ( V_39 , V_4 , type ) ;
}
return V_91 ;
}
static void F_338 ( struct V_1 * V_4 ,
unsigned int V_79 ,
const enum V_295 V_296 )
{
struct V_363 * V_284 = NULL ;
bool V_364 = true ;
if ( ! V_155 || V_296 == V_365 )
V_364 = false ;
V_284 = & V_26 -> V_366 ;
if ( ! V_284 -> V_4 )
V_284 -> V_4 = V_4 ;
if ( ! V_284 -> V_367 || F_236 ( V_192 ) )
goto V_368;
if ( V_79 > 1 )
goto V_368;
if ( V_284 -> V_4 != V_4 )
goto V_368;
V_284 -> V_79 ++ ;
if ( V_364 )
V_284 -> V_369 ++ ;
return;
V_368:
F_209 ( & V_4 -> V_59 , V_79 * V_252 ) ;
if ( V_364 )
F_209 ( & V_4 -> V_156 , V_79 * V_252 ) ;
if ( F_91 ( V_284 -> V_4 != V_4 ) )
F_197 ( V_4 ) ;
}
static struct V_1 *
F_339 ( struct V_39 * V_39 , enum V_295 V_296 ,
bool V_370 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_79 = 1 ;
struct V_142 * V_143 ;
bool V_78 ;
if ( F_105 () )
return NULL ;
if ( F_77 ( V_39 ) ) {
V_79 <<= F_328 ( V_39 ) ;
F_41 ( ! F_77 ( V_39 ) ) ;
}
V_143 = F_114 ( V_39 ) ;
if ( F_91 ( ! F_116 ( V_143 ) ) )
return NULL ;
F_245 ( V_143 ) ;
V_4 = V_143 -> V_1 ;
if ( ! F_116 ( V_143 ) )
goto V_371;
V_78 = F_316 ( V_39 ) ;
switch ( V_296 ) {
case V_300 :
V_78 = true ;
case V_372 :
if ( F_317 ( V_39 ) )
goto V_371;
if ( ! V_370 && F_340 ( V_143 ) )
goto V_371;
break;
case V_365 :
if ( ! F_316 ( V_39 ) ) {
if ( V_39 -> V_359 && ! F_341 ( V_39 ) )
goto V_371;
} else if ( F_317 ( V_39 ) )
goto V_371;
break;
default:
break;
}
F_74 ( V_4 , V_39 , V_78 , - V_79 ) ;
F_311 ( V_143 ) ;
F_249 ( V_143 ) ;
F_90 ( V_4 , V_39 ) ;
if ( V_155 && V_296 == V_365 ) {
F_71 ( V_4 , true ) ;
F_23 ( & V_4 -> V_15 ) ;
}
if ( ! V_370 && ! F_20 ( V_4 ) )
F_338 ( V_4 , V_79 , V_296 ) ;
return V_4 ;
V_371:
F_249 ( V_143 ) ;
return NULL ;
}
void F_342 ( struct V_39 * V_39 )
{
if ( F_317 ( V_39 ) )
return;
F_41 ( V_39 -> V_359 && ! F_316 ( V_39 ) ) ;
if ( F_246 ( V_39 ) )
return;
F_339 ( V_39 , V_300 , false ) ;
}
void F_343 ( struct V_39 * V_39 )
{
F_41 ( F_317 ( V_39 ) ) ;
F_41 ( V_39 -> V_359 ) ;
F_339 ( V_39 , V_362 , false ) ;
}
void F_344 ( void )
{
V_26 -> V_366 . V_367 ++ ;
if ( V_26 -> V_366 . V_367 == 1 ) {
V_26 -> V_366 . V_4 = NULL ;
V_26 -> V_366 . V_79 = 0 ;
V_26 -> V_366 . V_369 = 0 ;
}
}
void F_345 ( void )
{
struct V_363 * V_284 = & V_26 -> V_366 ;
if ( ! V_284 -> V_367 )
return;
V_284 -> V_367 -- ;
if ( V_284 -> V_367 )
return;
if ( ! V_284 -> V_4 )
return;
if ( V_284 -> V_79 )
F_209 ( & V_284 -> V_4 -> V_59 ,
V_284 -> V_79 * V_252 ) ;
if ( V_284 -> V_369 )
F_209 ( & V_284 -> V_4 -> V_156 ,
V_284 -> V_369 * V_252 ) ;
F_197 ( V_284 -> V_4 ) ;
V_284 -> V_4 = NULL ;
}
void
F_346 ( struct V_39 * V_39 , T_7 V_294 , bool V_373 )
{
struct V_1 * V_4 ;
int V_296 = V_365 ;
if ( ! V_373 )
V_296 = V_372 ;
V_4 = F_339 ( V_39 , V_296 , false ) ;
if ( V_155 && V_373 && V_4 )
F_347 ( V_294 , F_348 ( & V_4 -> V_15 ) ) ;
}
void F_334 ( T_7 V_294 )
{
struct V_1 * V_4 ;
unsigned short V_292 ;
if ( ! V_155 )
return;
V_292 = F_347 ( V_294 , 0 ) ;
F_24 () ;
V_4 = F_241 ( V_292 ) ;
if ( V_4 ) {
if ( ! F_20 ( V_4 ) )
F_209 ( & V_4 -> V_156 , V_252 ) ;
F_71 ( V_4 , false ) ;
F_31 ( & V_4 -> V_15 ) ;
}
F_28 () ;
}
static int F_349 ( T_7 V_374 ,
struct V_1 * V_161 , struct V_1 * V_162 )
{
unsigned short V_375 , V_376 ;
V_375 = F_348 ( & V_161 -> V_15 ) ;
V_376 = F_348 ( & V_162 -> V_15 ) ;
if ( F_350 ( V_374 , V_375 , V_376 ) == V_375 ) {
F_71 ( V_161 , false ) ;
F_71 ( V_162 , true ) ;
F_23 ( & V_162 -> V_15 ) ;
return 0 ;
}
return - V_354 ;
}
static inline int F_349 ( T_7 V_374 ,
struct V_1 * V_161 , struct V_1 * V_162 )
{
return - V_354 ;
}
void F_351 ( struct V_39 * V_39 , struct V_39 * V_377 ,
struct V_1 * * V_360 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_79 = 1 ;
struct V_142 * V_143 ;
enum V_295 V_296 ;
* V_360 = NULL ;
if ( F_105 () )
return;
if ( F_77 ( V_39 ) )
V_79 <<= F_328 ( V_39 ) ;
V_143 = F_114 ( V_39 ) ;
F_245 ( V_143 ) ;
if ( F_116 ( V_143 ) ) {
V_4 = V_143 -> V_1 ;
F_23 ( & V_4 -> V_15 ) ;
if ( F_316 ( V_39 ) )
F_352 ( V_143 ) ;
}
F_249 ( V_143 ) ;
if ( ! V_4 )
return;
* V_360 = V_4 ;
if ( F_316 ( V_39 ) )
V_296 = V_300 ;
else
V_296 = V_362 ;
F_250 ( V_4 , V_377 , V_79 , V_296 , false ) ;
}
void F_353 ( struct V_1 * V_4 ,
struct V_39 * V_378 , struct V_39 * V_377 , bool V_379 )
{
struct V_39 * V_380 , * V_381 ;
struct V_142 * V_143 ;
bool V_78 ;
if ( ! V_4 )
return;
if ( ! V_379 ) {
V_380 = V_378 ;
V_381 = V_377 ;
} else {
V_380 = V_377 ;
V_381 = V_378 ;
}
V_78 = F_316 ( V_380 ) ;
F_339 ( V_381 ,
V_78 ? V_300
: V_362 ,
true ) ;
F_31 ( & V_4 -> V_15 ) ;
V_143 = F_114 ( V_378 ) ;
F_245 ( V_143 ) ;
F_354 ( V_143 ) ;
F_249 ( V_143 ) ;
if ( V_78 )
F_342 ( V_380 ) ;
}
void F_355 ( struct V_39 * V_378 ,
struct V_39 * V_377 )
{
struct V_1 * V_4 = NULL ;
struct V_142 * V_143 ;
enum V_295 type = V_362 ;
if ( F_105 () )
return;
V_143 = F_114 ( V_378 ) ;
F_245 ( V_143 ) ;
if ( F_116 ( V_143 ) ) {
V_4 = V_143 -> V_1 ;
F_74 ( V_4 , V_378 , false , - 1 ) ;
F_311 ( V_143 ) ;
}
F_249 ( V_143 ) ;
if ( ! V_4 )
return;
F_250 ( V_4 , V_377 , 1 , type , true ) ;
}
static struct V_142 * F_356 ( struct V_39 * V_39 )
{
struct V_142 * V_143 ;
V_143 = F_114 ( V_39 ) ;
if ( F_231 ( V_143 ) && F_116 ( V_143 ) )
return V_143 ;
return NULL ;
}
bool F_357 ( struct V_39 * V_39 )
{
if ( F_105 () )
return false ;
return F_356 ( V_39 ) != NULL ;
}
void F_358 ( struct V_39 * V_39 )
{
struct V_142 * V_143 ;
V_143 = F_356 ( V_39 ) ;
if ( V_143 ) {
F_359 ( L_14 ,
V_143 , V_143 -> V_168 , V_143 -> V_1 ) ;
}
}
static int F_360 ( struct V_1 * V_4 ,
unsigned long long V_68 )
{
int V_382 ;
T_2 V_383 , V_384 ;
int V_91 = 0 ;
int V_385 = F_154 ( V_4 ) ;
T_2 V_386 , V_387 ;
int V_388 ;
V_382 = V_286 * V_385 ;
V_387 = F_38 ( & V_4 -> V_59 , V_33 ) ;
V_388 = 0 ;
while ( V_382 ) {
if ( F_361 ( V_26 ) ) {
V_91 = - V_291 ;
break;
}
F_225 ( & V_345 ) ;
V_383 = F_38 ( & V_4 -> V_156 , V_176 ) ;
if ( V_383 < V_68 ) {
V_91 = - V_354 ;
F_223 ( & V_345 ) ;
break;
}
V_384 = F_38 ( & V_4 -> V_59 , V_176 ) ;
if ( V_384 < V_68 )
V_388 = 1 ;
V_91 = F_362 ( & V_4 -> V_59 , V_68 ) ;
if ( ! V_91 ) {
if ( V_383 == V_68 )
V_4 -> V_205 = true ;
else
V_4 -> V_205 = false ;
}
F_223 ( & V_345 ) ;
if ( ! V_91 )
break;
F_168 ( V_4 , V_323 ,
V_204 ) ;
V_386 = F_38 ( & V_4 -> V_59 , V_33 ) ;
if ( V_386 >= V_387 )
V_382 -- ;
else
V_387 = V_386 ;
}
if ( ! V_91 && V_388 )
F_197 ( V_4 ) ;
return V_91 ;
}
static int F_363 ( struct V_1 * V_4 ,
unsigned long long V_68 )
{
int V_382 ;
T_2 V_384 , V_383 , V_387 , V_386 ;
int V_385 = F_154 ( V_4 ) ;
int V_91 = - V_353 ;
int V_388 = 0 ;
V_382 = V_385 * V_286 ;
V_387 = F_38 ( & V_4 -> V_156 , V_33 ) ;
while ( V_382 ) {
if ( F_361 ( V_26 ) ) {
V_91 = - V_291 ;
break;
}
F_225 ( & V_345 ) ;
V_384 = F_38 ( & V_4 -> V_59 , V_176 ) ;
if ( V_384 > V_68 ) {
V_91 = - V_354 ;
F_223 ( & V_345 ) ;
break;
}
V_383 = F_38 ( & V_4 -> V_156 , V_176 ) ;
if ( V_383 < V_68 )
V_388 = 1 ;
V_91 = F_362 ( & V_4 -> V_156 , V_68 ) ;
if ( ! V_91 ) {
if ( V_384 == V_68 )
V_4 -> V_205 = true ;
else
V_4 -> V_205 = false ;
}
F_223 ( & V_345 ) ;
if ( ! V_91 )
break;
F_168 ( V_4 , V_323 ,
V_203 |
V_204 ) ;
V_386 = F_38 ( & V_4 -> V_156 , V_33 ) ;
if ( V_386 >= V_387 )
V_382 -- ;
else
V_387 = V_386 ;
}
if ( ! V_91 && V_388 )
F_197 ( V_4 ) ;
return V_91 ;
}
unsigned long F_364 ( struct V_61 * V_61 , int V_186 ,
T_4 V_185 ,
unsigned long * V_214 )
{
unsigned long V_389 = 0 ;
struct V_34 * V_44 , * V_390 = NULL ;
unsigned long V_391 ;
int V_202 = 0 ;
struct V_40 * V_45 ;
unsigned long long V_58 ;
unsigned long V_216 ;
if ( V_186 > 0 )
return 0 ;
V_45 = F_46 ( F_106 ( V_61 ) , F_107 ( V_61 ) ) ;
do {
if ( V_390 )
V_44 = V_390 ;
else
V_44 = F_64 ( V_45 ) ;
if ( ! V_44 )
break;
V_216 = 0 ;
V_391 = F_184 ( V_44 -> V_4 , V_61 ,
V_185 , & V_216 ) ;
V_389 += V_391 ;
* V_214 += V_216 ;
F_55 ( & V_45 -> V_57 ) ;
V_390 = NULL ;
if ( ! V_391 ) {
do {
V_390 =
F_62 ( V_45 ) ;
if ( V_390 == V_44 )
F_31 ( & V_390 -> V_4 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_52 ( V_44 -> V_4 , V_44 , V_45 ) ;
V_58 = F_59 ( & V_44 -> V_4 -> V_59 ) ;
F_48 ( V_44 -> V_4 , V_44 , V_45 , V_58 ) ;
F_56 ( & V_45 -> V_57 ) ;
F_31 ( & V_44 -> V_4 -> V_15 ) ;
V_202 ++ ;
if ( ! V_389 &&
( V_390 == NULL ||
V_202 > V_392 ) )
break;
} while ( ! V_389 );
if ( V_390 )
F_31 ( & V_390 -> V_4 -> V_15 ) ;
return V_389 ;
}
static void F_365 ( struct V_1 * V_4 ,
int V_60 , int V_36 , enum V_87 V_88 )
{
struct V_86 * V_86 ;
unsigned long V_168 ;
struct V_393 * V_320 ;
struct V_39 * V_394 ;
struct V_61 * V_61 ;
V_61 = & F_366 ( V_60 ) -> V_395 [ V_36 ] ;
V_86 = F_112 ( V_61 , V_4 ) ;
V_320 = & V_86 -> V_396 [ V_88 ] ;
V_394 = NULL ;
do {
struct V_142 * V_143 ;
struct V_39 * V_39 ;
F_144 ( & V_61 -> V_299 , V_168 ) ;
if ( F_367 ( V_320 ) ) {
F_146 ( & V_61 -> V_299 , V_168 ) ;
break;
}
V_39 = F_368 ( V_320 -> V_125 , struct V_39 , V_88 ) ;
if ( V_394 == V_39 ) {
F_369 ( & V_39 -> V_88 , V_320 ) ;
V_394 = NULL ;
F_146 ( & V_61 -> V_299 , V_168 ) ;
continue;
}
F_146 ( & V_61 -> V_299 , V_168 ) ;
V_143 = F_114 ( V_39 ) ;
if ( F_319 ( V_39 , V_143 , V_4 ) ) {
V_394 = V_39 ;
F_370 () ;
} else
V_394 = NULL ;
} while ( ! F_367 ( V_320 ) );
}
static void F_371 ( struct V_1 * V_4 )
{
int V_60 , V_36 ;
T_2 V_397 ;
do {
F_372 () ;
F_224 ( V_4 ) ;
F_131 ( V_4 ) ;
F_86 (node, N_MEMORY) {
for ( V_36 = 0 ; V_36 < V_62 ; V_36 ++ ) {
enum V_87 V_88 ;
F_82 (lru) {
F_365 ( V_4 ,
V_60 , V_36 , V_88 ) ;
}
}
}
F_133 ( V_4 ) ;
F_197 ( V_4 ) ;
F_370 () ;
V_397 = F_38 ( & V_4 -> V_59 , V_33 ) -
F_38 ( & V_4 -> V_32 , V_33 ) ;
} while ( V_397 > 0 );
}
static inline bool F_373 ( struct V_1 * V_4 )
{
F_294 ( & V_398 ) ;
return V_4 -> V_128 &&
! F_367 ( & V_4 -> V_15 . V_170 -> V_385 ) ;
}
static int F_374 ( struct V_1 * V_4 )
{
int V_399 = V_286 ;
struct V_170 * V_400 = V_4 -> V_15 . V_170 ;
if ( F_375 ( V_400 ) || ! F_367 ( & V_400 -> V_385 ) )
return - V_353 ;
F_372 () ;
while ( V_399 && F_38 ( & V_4 -> V_59 , V_33 ) > 0 ) {
int V_401 ;
if ( F_361 ( V_26 ) )
return - V_291 ;
V_401 = F_170 ( V_4 , V_323 ,
false ) ;
if ( ! V_401 ) {
V_399 -- ;
F_376 ( V_402 , V_403 / 10 ) ;
}
}
F_377 () ;
F_371 ( V_4 ) ;
return 0 ;
}
static int F_378 ( struct V_13 * V_15 ,
unsigned int V_404 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
if ( F_20 ( V_4 ) )
return - V_354 ;
return F_374 ( V_4 ) ;
}
static T_2 F_379 ( struct V_13 * V_15 ,
struct V_309 * V_310 )
{
return F_15 ( V_15 ) -> V_128 ;
}
static int F_380 ( struct V_13 * V_15 ,
struct V_309 * V_310 , T_2 V_68 )
{
int V_405 = 0 ;
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_406 = F_15 ( F_130 ( & V_4 -> V_15 ) ) ;
F_225 ( & V_398 ) ;
if ( V_4 -> V_128 == V_68 )
goto V_137;
if ( ( ! V_406 || ! V_406 -> V_128 ) &&
( V_68 == 1 || V_68 == 0 ) ) {
if ( F_367 ( & V_4 -> V_15 . V_170 -> V_385 ) )
V_4 -> V_128 = V_68 ;
else
V_405 = - V_353 ;
} else
V_405 = - V_354 ;
V_137:
F_223 ( & V_398 ) ;
return V_405 ;
}
static unsigned long F_381 ( struct V_1 * V_4 ,
enum V_66 V_67 )
{
struct V_1 * V_120 ;
long V_68 = 0 ;
F_152 (iter, memcg)
V_68 += F_65 ( V_120 , V_67 ) ;
if ( V_68 < 0 )
V_68 = 0 ;
return V_68 ;
}
static inline T_2 F_382 ( struct V_1 * V_4 , bool V_407 )
{
T_2 V_68 ;
if ( ! F_20 ( V_4 ) ) {
if ( ! V_407 )
return F_38 ( & V_4 -> V_59 , V_33 ) ;
else
return F_38 ( & V_4 -> V_156 , V_33 ) ;
}
V_68 = F_381 ( V_4 , V_81 ) ;
V_68 += F_381 ( V_4 , V_80 ) ;
if ( V_407 )
V_68 += F_381 ( V_4 , V_75 ) ;
return V_68 << V_153 ;
}
static T_8 F_383 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_408 * V_408 ,
char T_9 * V_409 , T_1 V_410 , T_10 * V_411 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
char V_412 [ 64 ] ;
T_2 V_68 ;
int V_336 , V_413 ;
enum V_414 type ;
type = F_384 ( V_310 -> V_240 ) ;
V_336 = F_385 ( V_310 -> V_240 ) ;
switch ( type ) {
case V_415 :
if ( V_336 == V_33 )
V_68 = F_382 ( V_4 , false ) ;
else
V_68 = F_38 ( & V_4 -> V_59 , V_336 ) ;
break;
case V_416 :
if ( V_336 == V_33 )
V_68 = F_382 ( V_4 , true ) ;
else
V_68 = F_38 ( & V_4 -> V_156 , V_336 ) ;
break;
case V_417 :
V_68 = F_38 ( & V_4 -> V_32 , V_336 ) ;
break;
default:
F_111 () ;
}
V_413 = F_386 ( V_412 , sizeof( V_412 ) , L_15 , ( unsigned long long ) V_68 ) ;
return F_387 ( V_409 , V_410 , V_411 , V_412 , V_413 ) ;
}
static int F_388 ( struct V_13 * V_15 , T_2 V_68 )
{
int V_91 = - V_354 ;
#ifdef F_389
struct V_1 * V_4 = F_15 ( V_15 ) ;
F_225 ( & V_398 ) ;
F_225 ( & V_345 ) ;
if ( ! V_4 -> V_6 && V_68 != V_418 ) {
if ( F_375 ( V_15 -> V_170 ) || F_373 ( V_4 ) ) {
V_91 = - V_353 ;
goto V_137;
}
V_91 = F_362 ( & V_4 -> V_32 , V_68 ) ;
F_41 ( V_91 ) ;
V_91 = F_272 ( V_4 ) ;
if ( V_91 ) {
F_362 ( & V_4 -> V_32 , V_418 ) ;
goto V_137;
}
F_390 ( & V_29 ) ;
F_2 ( V_4 ) ;
} else
V_91 = F_362 ( & V_4 -> V_32 , V_68 ) ;
V_137:
F_223 ( & V_345 ) ;
F_223 ( & V_398 ) ;
#endif
return V_91 ;
}
static int F_391 ( struct V_1 * V_4 )
{
int V_91 = 0 ;
struct V_1 * V_50 = F_58 ( V_4 ) ;
if ( ! V_50 )
goto V_137;
V_4 -> V_6 = V_50 -> V_6 ;
if ( ! F_4 ( V_4 ) )
goto V_137;
F_390 ( & V_29 ) ;
F_225 ( & V_345 ) ;
F_286 () ;
V_91 = F_272 ( V_4 ) ;
F_287 () ;
F_223 ( & V_345 ) ;
V_137:
return V_91 ;
}
static int F_392 ( struct V_13 * V_15 , struct V_309 * V_310 ,
const char * V_419 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
enum V_414 type ;
int V_336 ;
unsigned long long V_68 ;
int V_91 ;
type = F_384 ( V_310 -> V_240 ) ;
V_336 = F_385 ( V_310 -> V_240 ) ;
switch ( V_336 ) {
case V_176 :
if ( F_20 ( V_4 ) ) {
V_91 = - V_354 ;
break;
}
V_91 = F_393 ( V_419 , & V_68 ) ;
if ( V_91 )
break;
if ( type == V_415 )
V_91 = F_360 ( V_4 , V_68 ) ;
else if ( type == V_416 )
V_91 = F_363 ( V_4 , V_68 ) ;
else if ( type == V_417 )
V_91 = F_388 ( V_15 , V_68 ) ;
else
return - V_354 ;
break;
case V_420 :
V_91 = F_393 ( V_419 , & V_68 ) ;
if ( V_91 )
break;
if ( type == V_415 )
V_91 = F_394 ( & V_4 -> V_59 , V_68 ) ;
else
V_91 = - V_354 ;
break;
default:
V_91 = - V_354 ;
break;
}
return V_91 ;
}
static void F_395 ( struct V_1 * V_4 ,
unsigned long long * V_421 , unsigned long long * V_422 )
{
unsigned long long V_423 , V_424 , V_425 ;
V_423 = F_38 ( & V_4 -> V_59 , V_176 ) ;
V_424 = F_38 ( & V_4 -> V_156 , V_176 ) ;
if ( ! V_4 -> V_128 )
goto V_137;
while ( F_130 ( & V_4 -> V_15 ) ) {
V_4 = F_15 ( F_130 ( & V_4 -> V_15 ) ) ;
if ( ! V_4 -> V_128 )
break;
V_425 = F_38 ( & V_4 -> V_59 , V_176 ) ;
V_423 = F_128 ( V_423 , V_425 ) ;
V_425 = F_38 ( & V_4 -> V_156 , V_176 ) ;
V_424 = F_128 ( V_424 , V_425 ) ;
}
V_137:
* V_421 = V_423 ;
* V_422 = V_424 ;
}
static int F_396 ( struct V_13 * V_15 , unsigned int V_404 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
int V_336 ;
enum V_414 type ;
type = F_384 ( V_404 ) ;
V_336 = F_385 ( V_404 ) ;
switch ( V_336 ) {
case V_426 :
if ( type == V_415 )
F_397 ( & V_4 -> V_59 ) ;
else if ( type == V_416 )
F_397 ( & V_4 -> V_156 ) ;
else if ( type == V_417 )
F_397 ( & V_4 -> V_32 ) ;
else
return - V_354 ;
break;
case V_177 :
if ( type == V_415 )
F_398 ( & V_4 -> V_59 ) ;
else if ( type == V_416 )
F_398 ( & V_4 -> V_156 ) ;
else if ( type == V_417 )
F_398 ( & V_4 -> V_32 ) ;
else
return - V_354 ;
break;
}
return 0 ;
}
static T_2 F_399 ( struct V_13 * V_15 ,
struct V_309 * V_310 )
{
return F_15 ( V_15 ) -> V_427 ;
}
static int F_400 ( struct V_13 * V_15 ,
struct V_309 * V_310 , T_2 V_68 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
if ( V_68 >= ( 1 << V_428 ) )
return - V_354 ;
V_4 -> V_427 = V_68 ;
return 0 ;
}
static int F_400 ( struct V_13 * V_15 ,
struct V_309 * V_310 , T_2 V_68 )
{
return - V_429 ;
}
static int F_401 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_311 * V_312 )
{
int V_35 ;
unsigned long V_430 , V_431 , V_432 , V_433 ;
unsigned long V_434 ;
struct V_1 * V_4 = F_15 ( V_15 ) ;
V_430 = F_85 ( V_4 , V_435 ) ;
F_402 ( V_312 , L_16 , V_430 ) ;
F_86 (nid, N_MEMORY) {
V_434 = F_84 ( V_4 , V_35 , V_435 ) ;
F_402 ( V_312 , L_17 , V_35 , V_434 ) ;
}
F_403 ( V_312 , '\n' ) ;
V_431 = F_85 ( V_4 , V_207 ) ;
F_402 ( V_312 , L_18 , V_431 ) ;
F_86 (nid, N_MEMORY) {
V_434 = F_84 ( V_4 , V_35 ,
V_207 ) ;
F_402 ( V_312 , L_17 , V_35 , V_434 ) ;
}
F_403 ( V_312 , '\n' ) ;
V_432 = F_85 ( V_4 , V_208 ) ;
F_402 ( V_312 , L_19 , V_432 ) ;
F_86 (nid, N_MEMORY) {
V_434 = F_84 ( V_4 , V_35 ,
V_208 ) ;
F_402 ( V_312 , L_17 , V_35 , V_434 ) ;
}
F_403 ( V_312 , '\n' ) ;
V_433 = F_85 ( V_4 , F_83 ( V_436 ) ) ;
F_402 ( V_312 , L_20 , V_433 ) ;
F_86 (nid, N_MEMORY) {
V_434 = F_84 ( V_4 , V_35 ,
F_83 ( V_436 ) ) ;
F_402 ( V_312 , L_17 , V_35 , V_434 ) ;
}
F_403 ( V_312 , '\n' ) ;
return 0 ;
}
static inline void F_404 ( void )
{
F_405 ( F_406 ( V_181 ) != V_180 ) ;
}
static int F_407 ( struct V_13 * V_15 , struct V_309 * V_310 ,
struct V_311 * V_312 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_437 ;
unsigned int V_175 ;
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
if ( V_175 == V_75 && ! V_155 )
continue;
F_402 ( V_312 , L_21 , V_179 [ V_175 ] ,
F_65 ( V_4 , V_175 ) * V_252 ) ;
}
for ( V_175 = 0 ; V_175 < V_260 ; V_175 ++ )
F_402 ( V_312 , L_22 , V_438 [ V_175 ] ,
F_73 ( V_4 , V_175 ) ) ;
for ( V_175 = 0 ; V_175 < V_180 ; V_175 ++ )
F_402 ( V_312 , L_22 , V_181 [ V_175 ] ,
F_85 ( V_4 , F_83 ( V_175 ) ) * V_252 ) ;
{
unsigned long long V_183 , V_422 ;
F_395 ( V_4 , & V_183 , & V_422 ) ;
F_402 ( V_312 , L_23 , V_183 ) ;
if ( V_155 )
F_402 ( V_312 , L_24 ,
V_422 ) ;
}
for ( V_175 = 0 ; V_175 < V_178 ; V_175 ++ ) {
long long V_68 = 0 ;
if ( V_175 == V_75 && ! V_155 )
continue;
F_152 (mi, memcg)
V_68 += F_65 ( V_437 , V_175 ) * V_252 ;
F_402 ( V_312 , L_25 , V_179 [ V_175 ] , V_68 ) ;
}
for ( V_175 = 0 ; V_175 < V_260 ; V_175 ++ ) {
unsigned long long V_68 = 0 ;
F_152 (mi, memcg)
V_68 += F_73 ( V_437 , V_175 ) ;
F_402 ( V_312 , L_26 ,
V_438 [ V_175 ] , V_68 ) ;
}
for ( V_175 = 0 ; V_175 < V_180 ; V_175 ++ ) {
unsigned long long V_68 = 0 ;
F_152 (mi, memcg)
V_68 += F_85 ( V_437 , F_83 ( V_175 ) ) * V_252 ;
F_402 ( V_312 , L_26 , V_181 [ V_175 ] , V_68 ) ;
}
#ifdef F_408
{
int V_35 , V_36 ;
struct V_34 * V_44 ;
struct V_439 * V_440 ;
unsigned long V_441 [ 2 ] = { 0 , 0 } ;
unsigned long V_442 [ 2 ] = { 0 , 0 } ;
F_409 (nid)
for ( V_36 = 0 ; V_36 < V_62 ; V_36 ++ ) {
V_44 = F_40 ( V_4 , V_35 , V_36 ) ;
V_440 = & V_44 -> V_86 . V_443 ;
V_441 [ 0 ] += V_440 -> V_441 [ 0 ] ;
V_441 [ 1 ] += V_440 -> V_441 [ 1 ] ;
V_442 [ 0 ] += V_440 -> V_442 [ 0 ] ;
V_442 [ 1 ] += V_440 -> V_442 [ 1 ] ;
}
F_402 ( V_312 , L_27 , V_441 [ 0 ] ) ;
F_402 ( V_312 , L_28 , V_441 [ 1 ] ) ;
F_402 ( V_312 , L_29 , V_442 [ 0 ] ) ;
F_402 ( V_312 , L_30 , V_442 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_410 ( struct V_13 * V_15 ,
struct V_309 * V_310 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
return F_129 ( V_4 ) ;
}
static int F_411 ( struct V_13 * V_15 ,
struct V_309 * V_310 , T_2 V_68 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_50 = F_15 ( F_130 ( & V_4 -> V_15 ) ) ;
if ( V_68 > 100 || ! V_50 )
return - V_354 ;
F_225 ( & V_398 ) ;
if ( ( V_50 -> V_128 ) || F_373 ( V_4 ) ) {
F_223 ( & V_398 ) ;
return - V_354 ;
}
V_4 -> V_158 = V_68 ;
F_223 ( & V_398 ) ;
return 0 ;
}
static void F_412 ( struct V_1 * V_4 , bool V_407 )
{
struct V_444 * V_445 ;
T_2 V_397 ;
int V_175 ;
F_24 () ;
if ( ! V_407 )
V_445 = F_96 ( V_4 -> V_446 . V_447 ) ;
else
V_445 = F_96 ( V_4 -> V_448 . V_447 ) ;
if ( ! V_445 )
goto V_163;
V_397 = F_382 ( V_4 , V_407 ) ;
V_175 = V_445 -> V_449 ;
for (; V_175 >= 0 && F_91 ( V_445 -> V_450 [ V_175 ] . V_451 > V_397 ) ; V_175 -- )
F_413 ( V_445 -> V_450 [ V_175 ] . V_452 , 1 ) ;
V_175 ++ ;
for (; V_175 < V_445 -> V_317 && F_91 ( V_445 -> V_450 [ V_175 ] . V_451 <= V_397 ) ; V_175 ++ )
F_413 ( V_445 -> V_450 [ V_175 ] . V_452 , 1 ) ;
V_445 -> V_449 = V_175 - 1 ;
V_163:
F_28 () ;
}
static void F_92 ( struct V_1 * V_4 )
{
while ( V_4 ) {
F_412 ( V_4 , false ) ;
if ( V_155 )
F_412 ( V_4 , true ) ;
V_4 = F_58 ( V_4 ) ;
}
}
static int F_414 ( const void * V_453 , const void * V_454 )
{
const struct F_92 * V_455 = V_453 ;
const struct F_92 * V_456 = V_454 ;
if ( V_455 -> V_451 > V_456 -> V_451 )
return 1 ;
if ( V_455 -> V_451 < V_456 -> V_451 )
return - 1 ;
return 0 ;
}
static int F_415 ( struct V_1 * V_4 )
{
struct V_457 * V_458 ;
F_265 (ev, &memcg->oom_notify, list)
F_413 ( V_458 -> V_452 , 1 ) ;
return 0 ;
}
static void F_201 ( struct V_1 * V_4 )
{
struct V_1 * V_120 ;
F_152 (iter, memcg)
F_415 ( V_120 ) ;
}
static int F_416 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_459 * V_452 , const char * args )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_460 * V_446 ;
struct V_444 * V_333 ;
enum V_414 type = F_384 ( V_310 -> V_240 ) ;
T_2 V_451 , V_397 ;
int V_175 , V_317 , V_91 ;
V_91 = F_393 ( args , & V_451 ) ;
if ( V_91 )
return V_91 ;
F_225 ( & V_4 -> V_461 ) ;
if ( type == V_415 )
V_446 = & V_4 -> V_446 ;
else if ( type == V_416 )
V_446 = & V_4 -> V_448 ;
else
F_111 () ;
V_397 = F_382 ( V_4 , type == V_416 ) ;
if ( V_446 -> V_447 )
F_412 ( V_4 , type == V_416 ) ;
V_317 = V_446 -> V_447 ? V_446 -> V_447 -> V_317 + 1 : 1 ;
V_333 = F_295 ( sizeof( * V_333 ) + V_317 * sizeof( struct F_92 ) ,
V_323 ) ;
if ( ! V_333 ) {
V_91 = - V_290 ;
goto V_163;
}
V_333 -> V_317 = V_317 ;
if ( V_446 -> V_447 ) {
memcpy ( V_333 -> V_450 , V_446 -> V_447 -> V_450 , ( V_317 - 1 ) *
sizeof( struct F_92 ) ) ;
}
V_333 -> V_450 [ V_317 - 1 ] . V_452 = V_452 ;
V_333 -> V_450 [ V_317 - 1 ] . V_451 = V_451 ;
F_417 ( V_333 -> V_450 , V_317 , sizeof( struct F_92 ) ,
F_414 , NULL ) ;
V_333 -> V_449 = - 1 ;
for ( V_175 = 0 ; V_175 < V_317 ; V_175 ++ ) {
if ( V_333 -> V_450 [ V_175 ] . V_451 <= V_397 ) {
++ V_333 -> V_449 ;
} else
break;
}
F_281 ( V_446 -> V_462 ) ;
V_446 -> V_462 = V_446 -> V_447 ;
F_418 ( V_446 -> V_447 , V_333 ) ;
F_132 () ;
V_163:
F_223 ( & V_4 -> V_461 ) ;
return V_91 ;
}
static void F_419 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_459 * V_452 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_460 * V_446 ;
struct V_444 * V_333 ;
enum V_414 type = F_384 ( V_310 -> V_240 ) ;
T_2 V_397 ;
int V_175 , V_463 , V_317 ;
F_225 ( & V_4 -> V_461 ) ;
if ( type == V_415 )
V_446 = & V_4 -> V_446 ;
else if ( type == V_416 )
V_446 = & V_4 -> V_448 ;
else
F_111 () ;
if ( ! V_446 -> V_447 )
goto V_163;
V_397 = F_382 ( V_4 , type == V_416 ) ;
F_412 ( V_4 , type == V_416 ) ;
V_317 = 0 ;
for ( V_175 = 0 ; V_175 < V_446 -> V_447 -> V_317 ; V_175 ++ ) {
if ( V_446 -> V_447 -> V_450 [ V_175 ] . V_452 != V_452 )
V_317 ++ ;
}
V_333 = V_446 -> V_462 ;
if ( ! V_317 ) {
F_281 ( V_333 ) ;
V_333 = NULL ;
goto V_464;
}
V_333 -> V_317 = V_317 ;
V_333 -> V_449 = - 1 ;
for ( V_175 = 0 , V_463 = 0 ; V_175 < V_446 -> V_447 -> V_317 ; V_175 ++ ) {
if ( V_446 -> V_447 -> V_450 [ V_175 ] . V_452 == V_452 )
continue;
V_333 -> V_450 [ V_463 ] = V_446 -> V_447 -> V_450 [ V_175 ] ;
if ( V_333 -> V_450 [ V_463 ] . V_451 <= V_397 ) {
++ V_333 -> V_449 ;
}
V_463 ++ ;
}
V_464:
V_446 -> V_462 = V_446 -> V_447 ;
if ( ! V_333 ) {
F_281 ( V_446 -> V_462 ) ;
V_446 -> V_462 = NULL ;
}
F_418 ( V_446 -> V_447 , V_333 ) ;
F_132 () ;
V_163:
F_223 ( & V_4 -> V_461 ) ;
}
static int F_420 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_459 * V_452 , const char * args )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_457 * V_404 ;
enum V_414 type = F_384 ( V_310 -> V_240 ) ;
F_22 ( type != V_465 ) ;
V_404 = F_295 ( sizeof( * V_404 ) , V_323 ) ;
if ( ! V_404 )
return - V_290 ;
F_55 ( & V_218 ) ;
V_404 -> V_452 = V_452 ;
F_271 ( & V_404 -> V_320 , & V_4 -> V_466 ) ;
if ( F_101 ( & V_4 -> V_222 ) )
F_413 ( V_452 , 1 ) ;
F_56 ( & V_218 ) ;
return 0 ;
}
static void F_421 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_459 * V_452 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_457 * V_458 , * V_425 ;
enum V_414 type = F_384 ( V_310 -> V_240 ) ;
F_22 ( type != V_465 ) ;
F_55 ( & V_218 ) ;
F_422 (ev, tmp, &memcg->oom_notify, list) {
if ( V_458 -> V_452 == V_452 ) {
F_285 ( & V_458 -> V_320 ) ;
F_281 ( V_458 ) ;
}
}
F_56 ( & V_218 ) ;
}
static int F_423 ( struct V_13 * V_15 ,
struct V_309 * V_310 , struct V_467 * V_468 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
V_468 -> V_469 ( V_468 , L_31 , V_4 -> V_243 ) ;
if ( F_101 ( & V_4 -> V_222 ) )
V_468 -> V_469 ( V_468 , L_32 , 1 ) ;
else
V_468 -> V_469 ( V_468 , L_32 , 0 ) ;
return 0 ;
}
static int F_424 ( struct V_13 * V_15 ,
struct V_309 * V_310 , T_2 V_68 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_50 = F_15 ( F_130 ( & V_4 -> V_15 ) ) ;
if ( ! V_50 || ! ( ( V_68 == 0 ) || ( V_68 == 1 ) ) )
return - V_354 ;
F_225 ( & V_398 ) ;
if ( ( V_50 -> V_128 ) || F_373 ( V_4 ) ) {
F_223 ( & V_398 ) ;
return - V_354 ;
}
V_4 -> V_243 = V_68 ;
if ( ! V_68 )
F_197 ( V_4 ) ;
F_223 ( & V_398 ) ;
return 0 ;
}
static int F_425 ( struct V_1 * V_4 , struct V_470 * V_471 )
{
int V_91 ;
V_4 -> V_31 = - 1 ;
V_91 = F_391 ( V_4 ) ;
if ( V_91 )
return V_91 ;
return F_426 ( V_4 , V_471 ) ;
}
static void F_427 ( struct V_1 * V_4 )
{
F_428 ( V_4 ) ;
}
static void F_429 ( struct V_1 * V_4 )
{
if ( ! F_4 ( V_4 ) )
return;
F_23 ( & V_4 -> V_15 ) ;
F_9 ( V_4 ) ;
if ( F_38 ( & V_4 -> V_32 , V_33 ) != 0 )
return;
if ( F_11 ( V_4 ) )
F_31 ( & V_4 -> V_15 ) ;
}
static int F_425 ( struct V_1 * V_4 , struct V_470 * V_471 )
{
return 0 ;
}
static void F_427 ( struct V_1 * V_4 )
{
}
static void F_429 ( struct V_1 * V_4 )
{
}
static int F_430 ( struct V_1 * V_4 , int V_60 )
{
struct V_3 * V_472 ;
struct V_34 * V_44 ;
int V_61 , V_425 = V_60 ;
if ( ! F_431 ( V_60 , V_473 ) )
V_425 = - 1 ;
V_472 = F_432 ( sizeof( * V_472 ) , V_323 , V_425 ) ;
if ( ! V_472 )
return 1 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_44 = & V_472 -> V_38 [ V_61 ] ;
F_433 ( & V_44 -> V_86 ) ;
V_44 -> V_53 = 0 ;
V_44 -> V_52 = false ;
V_44 -> V_4 = V_4 ;
}
V_4 -> V_37 [ V_60 ] = V_472 ;
return 0 ;
}
static void F_434 ( struct V_1 * V_4 , int V_60 )
{
F_281 ( V_4 -> V_37 [ V_60 ] ) ;
}
static struct V_1 * F_435 ( void )
{
struct V_1 * V_4 ;
T_1 V_317 = F_1 () ;
if ( V_317 < V_252 )
V_4 = F_280 ( V_317 , V_323 ) ;
else
V_4 = F_436 ( V_317 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_70 = F_437 ( struct V_474 ) ;
if ( ! V_4 -> V_70 )
goto V_475;
F_438 ( & V_4 -> V_72 ) ;
return V_4 ;
V_475:
if ( V_317 < V_252 )
F_281 ( V_4 ) ;
else
F_439 ( V_4 ) ;
return NULL ;
}
static void F_440 ( struct V_1 * V_4 )
{
int V_60 ;
T_1 V_317 = F_1 () ;
F_60 ( V_4 ) ;
F_441 ( & V_293 , & V_4 -> V_15 ) ;
F_61 (node)
F_434 ( V_4 , V_60 ) ;
F_442 ( V_4 -> V_70 ) ;
F_39 ( V_4 ) ;
if ( V_317 < V_252 )
F_281 ( V_4 ) ;
else
F_439 ( V_4 ) ;
}
struct V_1 * F_58 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_59 . V_50 )
return NULL ;
return F_232 ( V_4 -> V_59 . V_50 , V_59 ) ;
}
static void T_6 F_443 ( void )
{
struct V_476 * V_477 ;
struct V_40 * V_478 ;
int V_425 , V_60 , V_61 ;
F_61 (node) {
V_425 = V_60 ;
if ( ! F_431 ( V_60 , V_473 ) )
V_425 = - 1 ;
V_477 = F_432 ( sizeof( * V_477 ) , V_323 , V_425 ) ;
F_22 ( ! V_477 ) ;
V_41 . V_42 [ V_60 ] = V_477 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_478 = & V_477 -> V_43 [ V_61 ] ;
V_478 -> V_49 = V_479 ;
F_438 ( & V_478 -> V_57 ) ;
}
}
}
static struct V_13 * T_11
F_444 ( struct V_13 * V_480 )
{
struct V_1 * V_4 ;
long error = - V_290 ;
int V_60 ;
V_4 = F_435 () ;
if ( ! V_4 )
return F_445 ( error ) ;
F_61 (node)
if ( F_430 ( V_4 , V_60 ) )
goto V_481;
if ( V_480 == NULL ) {
V_17 = V_4 ;
F_446 ( & V_4 -> V_59 , NULL ) ;
F_446 ( & V_4 -> V_156 , NULL ) ;
F_446 ( & V_4 -> V_32 , NULL ) ;
}
V_4 -> V_213 = V_105 ;
F_200 ( & V_4 -> V_466 ) ;
V_4 -> V_427 = 0 ;
F_275 ( & V_4 -> V_461 ) ;
F_438 ( & V_4 -> V_169 ) ;
F_447 ( & V_4 -> V_16 ) ;
return & V_4 -> V_15 ;
V_481:
F_440 ( V_4 ) ;
return F_445 ( error ) ;
}
static int
F_448 ( struct V_13 * V_15 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
struct V_1 * V_50 = F_15 ( F_130 ( V_15 ) ) ;
int error = 0 ;
if ( ! V_50 )
return 0 ;
F_225 ( & V_398 ) ;
V_4 -> V_128 = V_50 -> V_128 ;
V_4 -> V_243 = V_50 -> V_243 ;
V_4 -> V_158 = F_129 ( V_50 ) ;
if ( V_50 -> V_128 ) {
F_446 ( & V_4 -> V_59 , & V_50 -> V_59 ) ;
F_446 ( & V_4 -> V_156 , & V_50 -> V_156 ) ;
F_446 ( & V_4 -> V_32 , & V_50 -> V_32 ) ;
} else {
F_446 ( & V_4 -> V_59 , NULL ) ;
F_446 ( & V_4 -> V_156 , NULL ) ;
F_446 ( & V_4 -> V_32 , NULL ) ;
if ( V_50 != V_17 )
V_293 . V_482 = true ;
}
error = F_425 ( V_4 , & V_293 ) ;
F_223 ( & V_398 ) ;
return error ;
}
static void F_449 ( struct V_1 * V_4 )
{
struct V_1 * V_50 = V_4 ;
while ( ( V_50 = F_58 ( V_50 ) ) )
F_99 ( V_50 ) ;
if ( ! V_17 -> V_128 )
F_99 ( V_17 ) ;
}
static void F_450 ( struct V_13 * V_15 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
F_429 ( V_4 ) ;
F_449 ( V_4 ) ;
F_371 ( V_4 ) ;
F_302 ( V_4 ) ;
F_451 ( & V_4 -> V_16 ) ;
}
static void F_452 ( struct V_13 * V_15 )
{
struct V_1 * V_4 = F_15 ( V_15 ) ;
F_427 ( V_4 ) ;
F_440 ( V_4 ) ;
}
static int F_453 ( unsigned long V_71 )
{
int V_91 = 0 ;
int V_483 = V_484 ;
struct V_1 * V_4 = V_10 . V_162 ;
if ( F_20 ( V_4 ) ) {
V_10 . V_485 += V_71 ;
return V_91 ;
}
if ( V_71 > 1 ) {
struct V_273 * V_254 ;
if ( F_230 ( & V_4 -> V_59 , V_252 * V_71 , & V_254 ) )
goto V_486;
if ( V_155 && F_230 ( & V_4 -> V_156 ,
V_252 * V_71 , & V_254 ) ) {
F_209 ( & V_4 -> V_59 , V_252 * V_71 ) ;
goto V_486;
}
V_10 . V_485 += V_71 ;
return V_91 ;
}
V_486:
while ( V_71 -- ) {
if ( F_361 ( V_26 ) ) {
V_91 = - V_291 ;
break;
}
if ( ! V_483 -- ) {
V_483 = V_484 ;
F_370 () ;
}
V_91 = F_234 ( NULL ,
V_323 , 1 , & V_4 , false ) ;
if ( V_91 )
return V_91 ;
V_10 . V_485 ++ ;
}
return V_91 ;
}
static struct V_39 * F_454 ( struct V_487 * V_488 ,
unsigned long V_489 , T_12 V_490 )
{
struct V_39 * V_39 = F_455 ( V_488 , V_489 , V_490 ) ;
if ( ! V_39 || ! F_317 ( V_39 ) )
return NULL ;
if ( F_316 ( V_39 ) ) {
if ( ! F_13 () )
return NULL ;
} else if ( ! F_14 () )
return NULL ;
if ( ! F_320 ( V_39 ) )
return NULL ;
return V_39 ;
}
static struct V_39 * F_456 ( struct V_487 * V_488 ,
unsigned long V_489 , T_12 V_490 , T_7 * V_374 )
{
struct V_39 * V_39 = NULL ;
T_7 V_294 = F_457 ( V_490 ) ;
if ( ! F_13 () || F_458 ( V_294 ) )
return NULL ;
V_39 = F_459 ( F_460 ( V_294 ) , V_294 . V_68 ) ;
if ( V_155 )
V_374 -> V_68 = V_294 . V_68 ;
return V_39 ;
}
static struct V_39 * F_456 ( struct V_487 * V_488 ,
unsigned long V_489 , T_12 V_490 , T_7 * V_374 )
{
return NULL ;
}
static struct V_39 * F_461 ( struct V_487 * V_488 ,
unsigned long V_489 , T_12 V_490 , T_7 * V_374 )
{
struct V_39 * V_39 = NULL ;
struct V_491 * V_359 ;
T_13 V_492 ;
if ( ! V_488 -> V_493 )
return NULL ;
if ( ! F_14 () )
return NULL ;
V_359 = V_488 -> V_493 -> V_494 ;
if ( F_462 ( V_490 ) )
V_492 = F_463 ( V_488 , V_489 ) ;
else
V_492 = F_464 ( V_490 ) ;
V_39 = F_459 ( V_359 , V_492 ) ;
#ifdef F_465
if ( F_466 ( V_39 ) ) {
T_7 V_407 = F_467 ( V_39 ) ;
if ( V_155 )
* V_374 = V_407 ;
V_39 = F_459 ( F_460 ( V_407 ) , V_407 . V_68 ) ;
}
#endif
return V_39 ;
}
static enum V_495 F_468 ( struct V_487 * V_488 ,
unsigned long V_489 , T_12 V_490 , union V_496 * V_94 )
{
struct V_39 * V_39 = NULL ;
struct V_142 * V_143 ;
enum V_495 V_91 = V_497 ;
T_7 V_294 = { . V_68 = 0 } ;
if ( F_469 ( V_490 ) )
V_39 = F_454 ( V_488 , V_489 , V_490 ) ;
else if ( F_470 ( V_490 ) )
V_39 = F_456 ( V_488 , V_489 , V_490 , & V_294 ) ;
else if ( F_462 ( V_490 ) || F_471 ( V_490 ) )
V_39 = F_461 ( V_488 , V_489 , V_490 , & V_294 ) ;
if ( ! V_39 && ! V_294 . V_68 )
return V_91 ;
if ( V_39 ) {
V_143 = F_114 ( V_39 ) ;
if ( F_116 ( V_143 ) && V_143 -> V_1 == V_10 . V_161 ) {
V_91 = V_498 ;
if ( V_94 )
V_94 -> V_39 = V_39 ;
}
if ( ! V_91 || ! V_94 )
F_326 ( V_39 ) ;
}
if ( V_294 . V_68 && ! V_91 &&
F_348 ( & V_10 . V_161 -> V_15 ) == F_248 ( V_294 ) ) {
V_91 = V_499 ;
if ( V_94 )
V_94 -> V_294 = V_294 ;
}
return V_91 ;
}
static enum V_495 F_472 ( struct V_487 * V_488 ,
unsigned long V_489 , T_14 V_500 , union V_496 * V_94 )
{
struct V_39 * V_39 = NULL ;
struct V_142 * V_143 ;
enum V_495 V_91 = V_497 ;
V_39 = F_473 ( V_500 ) ;
F_41 ( ! V_39 || ! F_474 ( V_39 ) ) ;
if ( ! F_13 () )
return V_91 ;
V_143 = F_114 ( V_39 ) ;
if ( F_116 ( V_143 ) && V_143 -> V_1 == V_10 . V_161 ) {
V_91 = V_498 ;
if ( V_94 ) {
F_475 ( V_39 ) ;
V_94 -> V_39 = V_39 ;
}
}
return V_91 ;
}
static inline enum V_495 F_472 ( struct V_487 * V_488 ,
unsigned long V_489 , T_14 V_500 , union V_496 * V_94 )
{
return V_497 ;
}
static int F_476 ( T_14 * V_500 ,
unsigned long V_489 , unsigned long V_501 ,
struct V_502 * V_503 )
{
struct V_487 * V_488 = V_503 -> V_240 ;
T_12 * V_504 ;
T_15 * V_505 ;
if ( F_477 ( V_500 , V_488 ) == 1 ) {
if ( F_472 ( V_488 , V_489 , * V_500 , NULL ) == V_498 )
V_10 . V_485 += V_351 ;
F_56 ( & V_488 -> V_506 -> V_507 ) ;
return 0 ;
}
if ( F_478 ( V_500 ) )
return 0 ;
V_504 = F_479 ( V_488 -> V_506 , V_500 , V_489 , & V_505 ) ;
for (; V_489 != V_501 ; V_504 ++ , V_489 += V_252 )
if ( F_468 ( V_488 , V_489 , * V_504 , NULL ) )
V_10 . V_485 ++ ;
F_480 ( V_504 - 1 , V_505 ) ;
F_370 () ;
return 0 ;
}
static unsigned long F_481 ( struct V_109 * V_110 )
{
unsigned long V_485 ;
struct V_487 * V_488 ;
F_482 ( & V_110 -> V_508 ) ;
for ( V_488 = V_110 -> V_509 ; V_488 ; V_488 = V_488 -> V_510 ) {
struct V_502 V_511 = {
. V_512 = F_476 ,
. V_110 = V_110 ,
. V_240 = V_488 ,
} ;
if ( F_483 ( V_488 ) )
continue;
F_484 ( V_488 -> V_513 , V_488 -> V_514 ,
& V_511 ) ;
}
F_485 ( & V_110 -> V_508 ) ;
V_485 = V_10 . V_485 ;
V_10 . V_485 = 0 ;
return V_485 ;
}
static int F_486 ( struct V_109 * V_110 )
{
unsigned long V_485 = F_481 ( V_110 ) ;
F_41 ( V_10 . V_164 ) ;
V_10 . V_164 = V_26 ;
return F_453 ( V_485 ) ;
}
static void F_487 ( void )
{
struct V_1 * V_161 = V_10 . V_161 ;
struct V_1 * V_162 = V_10 . V_162 ;
int V_175 ;
if ( V_10 . V_485 ) {
F_238 ( V_10 . V_162 , V_10 . V_485 ) ;
V_10 . V_485 = 0 ;
}
if ( V_10 . V_515 ) {
F_238 ( V_10 . V_161 , V_10 . V_515 ) ;
V_10 . V_515 = 0 ;
}
if ( V_10 . V_516 ) {
if ( ! F_20 ( V_10 . V_161 ) )
F_209 ( & V_10 . V_161 -> V_156 ,
V_252 * V_10 . V_516 ) ;
for ( V_175 = 0 ; V_175 < V_10 . V_516 ; V_175 ++ )
F_31 ( & V_10 . V_161 -> V_15 ) ;
if ( ! F_20 ( V_10 . V_162 ) ) {
F_209 ( & V_10 . V_162 -> V_59 ,
V_252 * V_10 . V_516 ) ;
}
V_10 . V_516 = 0 ;
}
F_197 ( V_161 ) ;
F_197 ( V_162 ) ;
F_488 ( & V_10 . V_166 ) ;
}
static void F_489 ( void )
{
struct V_1 * V_161 = V_10 . V_161 ;
V_10 . V_164 = NULL ;
F_487 () ;
F_55 ( & V_10 . V_57 ) ;
V_10 . V_161 = NULL ;
V_10 . V_162 = NULL ;
F_56 ( & V_10 . V_57 ) ;
F_133 ( V_161 ) ;
}
static int F_490 ( struct V_13 * V_15 ,
struct V_517 * V_518 )
{
struct V_107 * V_48 = F_491 ( V_518 ) ;
int V_91 = 0 ;
struct V_1 * V_4 = F_15 ( V_15 ) ;
unsigned long V_427 ;
V_427 = V_4 -> V_427 ;
if ( V_427 ) {
struct V_109 * V_110 ;
struct V_1 * V_161 = F_25 ( V_48 ) ;
F_41 ( V_161 == V_4 ) ;
V_110 = F_492 ( V_48 ) ;
if ( ! V_110 )
return 0 ;
if ( V_110 -> V_111 == V_48 ) {
F_41 ( V_10 . V_161 ) ;
F_41 ( V_10 . V_162 ) ;
F_41 ( V_10 . V_485 ) ;
F_41 ( V_10 . V_515 ) ;
F_41 ( V_10 . V_516 ) ;
F_131 ( V_161 ) ;
F_55 ( & V_10 . V_57 ) ;
V_10 . V_161 = V_161 ;
V_10 . V_162 = V_4 ;
V_10 . V_11 = V_427 ;
F_56 ( & V_10 . V_57 ) ;
V_91 = F_486 ( V_110 ) ;
if ( V_91 )
F_489 () ;
}
F_493 ( V_110 ) ;
}
return V_91 ;
}
static void F_494 ( struct V_13 * V_15 ,
struct V_517 * V_518 )
{
F_489 () ;
}
static int F_495 ( T_14 * V_500 ,
unsigned long V_489 , unsigned long V_501 ,
struct V_502 * V_503 )
{
int V_91 = 0 ;
struct V_487 * V_488 = V_503 -> V_240 ;
T_12 * V_504 ;
T_15 * V_505 ;
enum V_495 V_519 ;
union V_496 V_94 ;
struct V_39 * V_39 ;
struct V_142 * V_143 ;
if ( F_477 ( V_500 , V_488 ) == 1 ) {
if ( V_10 . V_485 < V_351 ) {
F_56 ( & V_488 -> V_506 -> V_507 ) ;
return 0 ;
}
V_519 = F_472 ( V_488 , V_489 , * V_500 , & V_94 ) ;
if ( V_519 == V_498 ) {
V_39 = V_94 . V_39 ;
if ( ! F_321 ( V_39 ) ) {
V_143 = F_114 ( V_39 ) ;
if ( ! F_315 ( V_39 , V_351 ,
V_143 , V_10 . V_161 , V_10 . V_162 ) ) {
V_10 . V_485 -= V_351 ;
V_10 . V_515 += V_351 ;
}
F_325 ( V_39 ) ;
}
F_326 ( V_39 ) ;
}
F_56 ( & V_488 -> V_506 -> V_507 ) ;
return 0 ;
}
if ( F_478 ( V_500 ) )
return 0 ;
V_64:
V_504 = F_479 ( V_488 -> V_506 , V_500 , V_489 , & V_505 ) ;
for (; V_489 != V_501 ; V_489 += V_252 ) {
T_12 V_490 = * ( V_504 ++ ) ;
T_7 V_294 ;
if ( ! V_10 . V_485 )
break;
switch ( F_468 ( V_488 , V_489 , V_490 , & V_94 ) ) {
case V_498 :
V_39 = V_94 . V_39 ;
if ( F_321 ( V_39 ) )
goto V_358;
V_143 = F_114 ( V_39 ) ;
if ( ! F_315 ( V_39 , 1 , V_143 ,
V_10 . V_161 , V_10 . V_162 ) ) {
V_10 . V_485 -- ;
V_10 . V_515 ++ ;
}
F_325 ( V_39 ) ;
V_358:
F_326 ( V_39 ) ;
break;
case V_499 :
V_294 = V_94 . V_294 ;
if ( ! F_349 ( V_294 , V_10 . V_161 , V_10 . V_162 ) ) {
V_10 . V_485 -- ;
V_10 . V_516 ++ ;
}
break;
default:
break;
}
}
F_480 ( V_504 - 1 , V_505 ) ;
F_370 () ;
if ( V_489 != V_501 ) {
V_91 = F_453 ( 1 ) ;
if ( ! V_91 )
goto V_64;
}
return V_91 ;
}
static void F_496 ( struct V_109 * V_110 )
{
struct V_487 * V_488 ;
F_372 () ;
V_64:
if ( F_91 ( ! F_497 ( & V_110 -> V_508 ) ) ) {
F_487 () ;
F_370 () ;
goto V_64;
}
for ( V_488 = V_110 -> V_509 ; V_488 ; V_488 = V_488 -> V_510 ) {
int V_91 ;
struct V_502 V_520 = {
. V_512 = F_495 ,
. V_110 = V_110 ,
. V_240 = V_488 ,
} ;
if ( F_483 ( V_488 ) )
continue;
V_91 = F_484 ( V_488 -> V_513 , V_488 -> V_514 ,
& V_520 ) ;
if ( V_91 )
break;
}
F_485 ( & V_110 -> V_508 ) ;
}
static void F_498 ( struct V_13 * V_15 ,
struct V_517 * V_518 )
{
struct V_107 * V_48 = F_491 ( V_518 ) ;
struct V_109 * V_110 = F_492 ( V_48 ) ;
if ( V_110 ) {
if ( V_10 . V_162 )
F_496 ( V_110 ) ;
F_493 ( V_110 ) ;
}
if ( V_10 . V_162 )
F_489 () ;
}
static int F_490 ( struct V_13 * V_15 ,
struct V_517 * V_518 )
{
return 0 ;
}
static void F_494 ( struct V_13 * V_15 ,
struct V_517 * V_518 )
{
}
static void F_498 ( struct V_13 * V_15 ,
struct V_517 * V_518 )
{
}
static void F_499 ( struct V_13 * V_521 )
{
if ( F_500 ( V_521 -> V_170 ) )
F_15 ( V_521 ) -> V_128 = true ;
}
static int T_6 F_501 ( char * V_14 )
{
if ( ! strcmp ( V_14 , L_33 ) )
V_522 = 1 ;
else if ( ! strcmp ( V_14 , L_34 ) )
V_522 = 0 ;
return 1 ;
}
static void T_6 F_502 ( void )
{
F_30 ( F_503 ( & V_293 , V_523 ) ) ;
}
static void T_6 F_504 ( void )
{
if ( ! F_105 () && V_522 ) {
V_155 = 1 ;
F_502 () ;
}
}
static void T_6 F_504 ( void )
{
}
static int T_6 F_505 ( void )
{
F_506 ( F_227 , 0 ) ;
F_504 () ;
F_443 () ;
F_212 () ;
return 0 ;
}
