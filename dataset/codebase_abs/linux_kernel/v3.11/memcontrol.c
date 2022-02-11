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
static inline
struct V_1 * F_15 ( struct V_13 * V_14 )
{
return F_16 ( V_14 , struct V_1 , V_15 ) ;
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
F_67 (cpu)
V_68 += F_68 ( V_4 -> V_70 -> V_77 [ V_67 ] , V_69 ) ;
#ifdef F_69
F_55 ( & V_4 -> V_72 ) ;
V_68 += V_4 -> V_73 . V_77 [ V_67 ] ;
F_56 ( & V_4 -> V_72 ) ;
#endif
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
struct V_1 * F_94 ( struct V_107 * V_108 )
{
return F_15 (
V_13 ( V_108 , V_109 ) ) ;
}
struct V_1 * F_25 ( struct V_110 * V_48 )
{
if ( F_91 ( ! V_48 ) )
return NULL ;
return F_15 ( F_95 ( V_48 , V_109 ) ) ;
}
struct V_1 * F_96 ( struct V_111 * V_112 )
{
struct V_1 * V_4 = NULL ;
if ( ! V_112 )
return NULL ;
F_24 () ;
do {
V_4 = F_25 ( F_97 ( V_112 -> V_113 ) ) ;
if ( F_91 ( ! V_4 ) )
break;
} while ( ! F_27 ( & V_4 -> V_15 ) );
F_28 () ;
return V_4 ;
}
static struct V_1 * F_98 ( struct V_1 * V_114 ,
struct V_1 * V_115 )
{
struct V_107 * V_116 , * V_117 ;
if ( ! V_115 )
return V_114 ;
V_116 = ( V_115 == V_114 ) ? NULL
: V_115 -> V_15 . V_107 ;
V_118:
V_117 = F_99 (
V_116 , V_114 -> V_15 . V_107 ) ;
if ( V_117 ) {
struct V_1 * V_119 = F_94 (
V_117 ) ;
if ( F_27 ( & V_119 -> V_15 ) )
return V_119 ;
else {
V_116 = V_117 ;
goto V_118;
}
}
return NULL ;
}
static void F_100 ( struct V_1 * V_114 )
{
F_93 ( & V_114 -> V_120 ) ;
}
static struct V_1 *
F_101 ( struct V_121 * V_122 ,
struct V_1 * V_114 ,
int * V_123 )
{
struct V_1 * V_124 = NULL ;
* V_123 = F_102 ( & V_114 -> V_120 ) ;
if ( V_122 -> V_125 == * V_123 ) {
F_103 () ;
V_124 = V_122 -> V_115 ;
if ( V_124 && ! F_27 ( & V_124 -> V_15 ) )
V_124 = NULL ;
}
return V_124 ;
}
static void F_104 ( struct V_121 * V_122 ,
struct V_1 * V_115 ,
struct V_1 * V_126 ,
int V_123 )
{
if ( V_115 )
F_31 ( & V_115 -> V_15 ) ;
V_122 -> V_115 = V_126 ;
F_10 () ;
V_122 -> V_125 = V_123 ;
}
struct V_1 * F_105 ( struct V_1 * V_114 ,
struct V_1 * V_127 ,
struct V_128 * V_129 )
{
struct V_1 * V_4 = NULL ;
struct V_1 * V_115 = NULL ;
if ( F_106 () )
return NULL ;
if ( ! V_114 )
V_114 = V_17 ;
if ( V_127 && ! V_129 )
V_115 = V_127 ;
if ( ! V_114 -> V_130 && V_114 != V_17 ) {
if ( V_127 )
goto V_131;
return V_114 ;
}
F_24 () ;
while ( ! V_4 ) {
struct V_121 * V_132 ( V_122 ) ;
int V_132 ( V_133 ) ;
if ( V_129 ) {
int V_35 = F_107 ( V_129 -> V_61 ) ;
int V_36 = F_108 ( V_129 -> V_61 ) ;
struct V_34 * V_44 ;
V_44 = F_40 ( V_114 , V_35 , V_36 ) ;
V_122 = & V_44 -> V_134 [ V_129 -> V_135 ] ;
if ( V_127 && V_129 -> V_136 != V_122 -> V_136 ) {
V_122 -> V_115 = NULL ;
goto V_137;
}
V_115 = F_101 ( V_122 , V_114 , & V_133 ) ;
}
V_4 = F_98 ( V_114 , V_115 ) ;
if ( V_129 ) {
F_104 ( V_122 , V_115 , V_4 , V_133 ) ;
if ( ! V_4 )
V_122 -> V_136 ++ ;
else if ( ! V_127 && V_4 )
V_129 -> V_136 = V_122 -> V_136 ;
}
if ( V_127 && ! V_4 )
goto V_137;
}
V_137:
F_28 () ;
V_131:
if ( V_127 && V_127 != V_114 )
F_31 ( & V_127 -> V_15 ) ;
return V_4 ;
}
void F_109 ( struct V_1 * V_114 ,
struct V_1 * V_127 )
{
if ( ! V_114 )
V_114 = V_17 ;
if ( V_127 && V_127 != V_114 )
F_31 ( & V_127 -> V_15 ) ;
}
void F_110 ( struct V_111 * V_112 , enum V_138 V_67 )
{
struct V_1 * V_4 ;
F_24 () ;
V_4 = F_25 ( F_97 ( V_112 -> V_113 ) ) ;
if ( F_91 ( ! V_4 ) )
goto V_139;
switch ( V_67 ) {
case V_140 :
F_111 ( V_4 -> V_70 -> V_77 [ V_141 ] ) ;
break;
case V_142 :
F_111 ( V_4 -> V_70 -> V_77 [ V_143 ] ) ;
break;
default:
F_112 () ;
}
V_139:
F_28 () ;
}
struct V_86 * F_113 ( struct V_61 * V_61 ,
struct V_1 * V_4 )
{
struct V_34 * V_44 ;
struct V_86 * V_86 ;
if ( F_106 () ) {
V_86 = & V_61 -> V_86 ;
goto V_139;
}
V_44 = F_40 ( V_4 , F_107 ( V_61 ) , F_108 ( V_61 ) ) ;
V_86 = & V_44 -> V_86 ;
V_139:
if ( F_91 ( V_86 -> V_61 != V_61 ) )
V_86 -> V_61 = V_61 ;
return V_86 ;
}
struct V_86 * F_114 ( struct V_39 * V_39 , struct V_61 * V_61 )
{
struct V_34 * V_44 ;
struct V_1 * V_4 ;
struct V_144 * V_145 ;
struct V_86 * V_86 ;
if ( F_106 () ) {
V_86 = & V_61 -> V_86 ;
goto V_139;
}
V_145 = F_115 ( V_39 ) ;
V_4 = V_145 -> V_1 ;
if ( ! F_116 ( V_39 ) && ! F_117 ( V_145 ) && V_4 != V_17 )
V_145 -> V_1 = V_4 = V_17 ;
V_44 = F_43 ( V_4 , V_39 ) ;
V_86 = & V_44 -> V_86 ;
V_139:
if ( F_91 ( V_86 -> V_61 != V_61 ) )
V_86 -> V_61 = V_61 ;
return V_86 ;
}
void F_118 ( struct V_86 * V_86 , enum V_87 V_88 ,
int V_79 )
{
struct V_34 * V_44 ;
unsigned long * V_89 ;
if ( F_106 () )
return;
V_44 = F_16 ( V_86 , struct V_34 , V_86 ) ;
V_89 = V_44 -> V_89 + V_88 ;
* V_89 += V_79 ;
F_41 ( ( long ) ( * V_89 ) < 0 ) ;
}
bool F_119 ( const struct V_1 * V_146 ,
struct V_1 * V_4 )
{
if ( V_146 == V_4 )
return true ;
if ( ! V_146 -> V_130 || ! V_4 )
return false ;
return F_120 ( & V_4 -> V_15 , & V_146 -> V_15 ) ;
}
static bool F_121 ( const struct V_1 * V_146 ,
struct V_1 * V_4 )
{
bool V_91 ;
F_24 () ;
V_91 = F_119 ( V_146 , V_4 ) ;
F_28 () ;
return V_91 ;
}
bool F_122 ( struct V_110 * V_147 ,
const struct V_1 * V_4 )
{
struct V_1 * V_148 = NULL ;
struct V_110 * V_48 ;
bool V_91 ;
V_48 = F_123 ( V_147 ) ;
if ( V_48 ) {
V_148 = F_96 ( V_48 -> V_112 ) ;
F_124 ( V_48 ) ;
} else {
F_24 () ;
V_148 = F_25 ( V_147 ) ;
if ( V_148 )
F_23 ( & V_148 -> V_15 ) ;
F_28 () ;
}
if ( ! V_148 )
return false ;
V_91 = F_121 ( V_4 , V_148 ) ;
F_31 ( & V_148 -> V_15 ) ;
return V_91 ;
}
int F_125 ( struct V_86 * V_86 )
{
unsigned long V_149 ;
unsigned long V_150 ;
unsigned long V_151 ;
unsigned long V_152 ;
V_150 = F_80 ( V_86 , V_153 ) ;
V_151 = F_80 ( V_86 , V_154 ) ;
V_152 = ( V_150 + V_151 ) >> ( 30 - V_155 ) ;
if ( V_152 )
V_149 = F_126 ( 10 * V_152 ) ;
else
V_149 = 1 ;
return V_150 * V_149 < V_151 ;
}
static unsigned long F_127 ( struct V_1 * V_4 )
{
unsigned long long V_156 ;
V_156 = F_128 ( & V_4 -> V_59 ) ;
if ( V_157 )
V_156 = F_129 ( V_156 , F_128 ( & V_4 -> V_158 ) ) ;
return V_156 >> V_155 ;
}
int F_130 ( struct V_1 * V_4 )
{
struct V_107 * V_159 = V_4 -> V_15 . V_107 ;
if ( V_159 -> V_50 == NULL )
return V_160 ;
return V_4 -> V_161 ;
}
static void F_131 ( struct V_1 * V_4 )
{
F_93 ( & V_162 ) ;
F_93 ( & V_4 -> V_163 ) ;
F_132 () ;
}
static void F_133 ( struct V_1 * V_4 )
{
if ( V_4 ) {
F_134 ( & V_162 ) ;
F_134 ( & V_4 -> V_163 ) ;
}
}
static bool F_135 ( struct V_1 * V_4 )
{
F_41 ( ! F_136 () ) ;
return F_102 ( & V_4 -> V_163 ) > 0 ;
}
static bool F_137 ( struct V_1 * V_4 )
{
struct V_1 * V_164 ;
struct V_1 * V_165 ;
bool V_91 = false ;
F_55 ( & V_10 . V_57 ) ;
V_164 = V_10 . V_164 ;
V_165 = V_10 . V_165 ;
if ( ! V_164 )
goto V_166;
V_91 = F_121 ( V_4 , V_164 )
|| F_121 ( V_4 , V_165 ) ;
V_166:
F_56 ( & V_10 . V_57 ) ;
return V_91 ;
}
static bool F_138 ( struct V_1 * V_4 )
{
if ( V_10 . V_167 && V_26 != V_10 . V_167 ) {
if ( F_137 ( V_4 ) ) {
F_139 ( V_168 ) ;
F_140 ( & V_10 . V_169 , & V_168 , V_170 ) ;
if ( V_10 . V_167 )
F_141 () ;
F_142 ( & V_10 . V_169 , & V_168 ) ;
return true ;
}
}
return false ;
}
static void F_143 ( struct V_1 * V_4 ,
unsigned long * V_171 )
{
F_144 ( & V_4 -> V_172 , * V_171 ) ;
}
static void F_145 ( struct V_1 * V_4 ,
unsigned long * V_171 )
{
F_146 ( & V_4 -> V_172 , * V_171 ) ;
}
void F_147 ( struct V_1 * V_4 , struct V_110 * V_48 )
{
struct V_107 * V_173 ;
struct V_107 * V_174 ;
static char V_175 [ V_176 ] ;
int V_91 ;
struct V_1 * V_122 ;
unsigned int V_177 ;
if ( ! V_48 )
return;
F_24 () ;
V_174 = V_4 -> V_15 . V_107 ;
V_173 = F_148 ( V_48 , V_109 ) ;
V_91 = F_149 ( V_173 , V_175 , V_176 ) ;
if ( V_91 < 0 ) {
F_28 () ;
goto V_65;
}
F_28 () ;
F_150 ( L_1 , V_175 ) ;
F_24 () ;
V_91 = F_149 ( V_174 , V_175 , V_176 ) ;
if ( V_91 < 0 ) {
F_28 () ;
goto V_65;
}
F_28 () ;
F_151 ( L_2 , V_175 ) ;
V_65:
F_150 ( L_3 ,
F_38 ( & V_4 -> V_59 , V_33 ) >> 10 ,
F_38 ( & V_4 -> V_59 , V_178 ) >> 10 ,
F_38 ( & V_4 -> V_59 , V_179 ) ) ;
F_150 ( L_4 ,
F_38 ( & V_4 -> V_158 , V_33 ) >> 10 ,
F_38 ( & V_4 -> V_158 , V_178 ) >> 10 ,
F_38 ( & V_4 -> V_158 , V_179 ) ) ;
F_150 ( L_5 ,
F_38 ( & V_4 -> V_32 , V_33 ) >> 10 ,
F_38 ( & V_4 -> V_32 , V_178 ) >> 10 ,
F_38 ( & V_4 -> V_32 , V_179 ) ) ;
F_152 (iter, memcg) {
F_150 ( L_6 ) ;
F_24 () ;
V_91 = F_149 ( V_122 -> V_15 . V_107 , V_175 , V_176 ) ;
if ( ! V_91 )
F_151 ( L_7 , V_175 ) ;
F_28 () ;
F_151 ( L_8 ) ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
if ( V_177 == V_75 && ! V_157 )
continue;
F_151 ( L_9 , V_181 [ V_177 ] ,
F_153 ( F_65 ( V_122 , V_177 ) ) ) ;
}
for ( V_177 = 0 ; V_177 < V_182 ; V_177 ++ )
F_151 ( L_10 , V_183 [ V_177 ] ,
F_153 ( F_85 ( V_122 , F_83 ( V_177 ) ) ) ) ;
F_151 ( L_11 ) ;
}
}
static int F_154 ( struct V_1 * V_4 )
{
int V_184 = 0 ;
struct V_1 * V_122 ;
F_152 (iter, memcg)
V_184 ++ ;
return V_184 ;
}
static T_2 F_155 ( struct V_1 * V_4 )
{
T_2 V_185 ;
V_185 = F_38 ( & V_4 -> V_59 , V_178 ) ;
if ( F_130 ( V_4 ) ) {
T_2 V_158 ;
V_185 += V_186 << V_155 ;
V_158 = F_38 ( & V_4 -> V_158 , V_178 ) ;
V_185 = F_129 ( V_185 , V_158 ) ;
}
return V_185 ;
}
static void F_156 ( struct V_1 * V_4 , T_4 V_187 ,
int V_188 )
{
struct V_1 * V_122 ;
unsigned long V_189 = 0 ;
unsigned long V_190 ;
unsigned int V_191 = 0 ;
struct V_110 * V_192 = NULL ;
if ( F_157 ( V_26 ) || V_26 -> V_171 & V_193 ) {
F_158 ( V_194 ) ;
return;
}
F_159 ( V_195 , V_187 , V_188 , NULL ) ;
V_190 = F_155 ( V_4 ) >> V_155 ? : 1 ;
F_152 (iter, memcg) {
struct V_107 * V_107 = V_122 -> V_15 . V_107 ;
struct V_196 V_197 ;
struct V_110 * V_147 ;
F_160 ( V_107 , & V_197 ) ;
while ( ( V_147 = F_161 ( V_107 , & V_197 ) ) ) {
switch ( F_162 ( V_147 , V_190 , NULL ,
false ) ) {
case V_198 :
if ( V_192 )
F_163 ( V_192 ) ;
V_192 = V_147 ;
V_189 = V_199 ;
F_164 ( V_192 ) ;
case V_200 :
continue;
case V_201 :
F_165 ( V_107 , & V_197 ) ;
F_109 ( V_4 , V_122 ) ;
if ( V_192 )
F_163 ( V_192 ) ;
return;
case V_202 :
break;
} ;
V_191 = F_166 ( V_147 , V_4 , NULL , V_190 ) ;
if ( V_191 > V_189 ) {
if ( V_192 )
F_163 ( V_192 ) ;
V_192 = V_147 ;
V_189 = V_191 ;
F_164 ( V_192 ) ;
}
}
F_165 ( V_107 , & V_197 ) ;
}
if ( ! V_192 )
return;
V_191 = V_189 * 1000 / V_190 ;
F_167 ( V_192 , V_187 , V_188 , V_191 , V_190 , V_4 ,
NULL , L_12 ) ;
}
static unsigned long F_168 ( struct V_1 * V_4 ,
T_4 V_187 ,
unsigned long V_171 )
{
unsigned long V_92 = 0 ;
bool V_203 = false ;
int V_204 ;
if ( V_171 & V_205 )
V_203 = true ;
if ( ! ( V_171 & V_206 ) && V_4 -> V_207 )
V_203 = true ;
for ( V_204 = 0 ; V_204 < V_208 ; V_204 ++ ) {
if ( V_204 )
F_169 ( V_4 ) ;
V_92 += F_170 ( V_4 , V_187 , V_203 ) ;
if ( V_92 && ( V_171 & V_206 ) )
break;
if ( F_127 ( V_4 ) )
break;
if ( V_204 && ! V_92 )
break;
}
return V_92 ;
}
static bool F_171 ( struct V_1 * V_4 ,
int V_35 , bool V_203 )
{
if ( F_84 ( V_4 , V_35 , V_209 ) )
return true ;
if ( V_203 || ! V_186 )
return false ;
if ( F_84 ( V_4 , V_35 , V_210 ) )
return true ;
return false ;
}
static void F_172 ( struct V_1 * V_4 )
{
int V_35 ;
if ( ! F_102 ( & V_4 -> V_106 ) )
return;
if ( F_173 ( & V_4 -> V_211 ) > 1 )
return;
V_4 -> V_212 = V_213 [ V_214 ] ;
F_174 (nid, node_states[N_MEMORY]) {
if ( ! F_171 ( V_4 , V_35 , false ) )
F_175 ( V_35 , V_4 -> V_212 ) ;
}
F_176 ( & V_4 -> V_106 , 0 ) ;
F_176 ( & V_4 -> V_211 , 0 ) ;
}
int F_177 ( struct V_1 * V_4 )
{
int V_60 ;
F_172 ( V_4 ) ;
V_60 = V_4 -> V_215 ;
V_60 = F_178 ( V_60 , V_4 -> V_212 ) ;
if ( V_60 == V_105 )
V_60 = F_179 ( V_4 -> V_212 ) ;
if ( F_91 ( V_60 == V_105 ) )
V_60 = F_180 () ;
V_4 -> V_215 = V_60 ;
return V_60 ;
}
static bool F_181 ( struct V_1 * V_4 , bool V_203 )
{
int V_35 ;
if ( ! F_182 ( V_4 -> V_212 ) ) {
for ( V_35 = F_179 ( V_4 -> V_212 ) ;
V_35 < V_105 ;
V_35 = F_178 ( V_35 , V_4 -> V_212 ) ) {
if ( F_171 ( V_4 , V_35 , V_203 ) )
return true ;
}
}
F_86 (nid, N_MEMORY) {
if ( F_183 ( V_35 , V_4 -> V_212 ) )
continue;
if ( F_171 ( V_4 , V_35 , V_203 ) )
return true ;
}
return false ;
}
int F_177 ( struct V_1 * V_4 )
{
return 0 ;
}
static bool F_181 ( struct V_1 * V_4 , bool V_203 )
{
return F_171 ( V_4 , 0 , V_203 ) ;
}
static int F_184 ( struct V_1 * V_146 ,
struct V_61 * V_61 ,
T_4 V_187 ,
unsigned long * V_216 )
{
struct V_1 * V_217 = NULL ;
int V_92 = 0 ;
int V_204 = 0 ;
unsigned long V_58 ;
unsigned long V_218 ;
struct V_128 V_129 = {
. V_61 = V_61 ,
. V_135 = 0 ,
} ;
V_58 = F_59 ( & V_146 -> V_59 ) >> V_155 ;
while ( 1 ) {
V_217 = F_105 ( V_146 , V_217 , & V_129 ) ;
if ( ! V_217 ) {
V_204 ++ ;
if ( V_204 >= 2 ) {
if ( ! V_92 )
break;
if ( V_92 >= ( V_58 >> 2 ) ||
( V_204 > V_208 ) )
break;
}
continue;
}
if ( ! F_181 ( V_217 , false ) )
continue;
V_92 += F_185 ( V_217 , V_187 , false ,
V_61 , & V_218 ) ;
* V_216 += V_218 ;
if ( ! F_59 ( & V_146 -> V_59 ) )
break;
}
F_109 ( V_146 , V_217 ) ;
return V_92 ;
}
static bool F_186 ( struct V_1 * V_4 )
{
struct V_1 * V_122 , * V_219 = NULL ;
F_152 (iter, memcg) {
if ( V_122 -> V_220 ) {
V_219 = V_122 ;
F_109 ( V_4 , V_122 ) ;
break;
} else
V_122 -> V_220 = true ;
}
if ( ! V_219 )
return true ;
F_152 (iter, memcg) {
if ( V_122 == V_219 ) {
F_109 ( V_4 , V_122 ) ;
break;
}
V_122 -> V_220 = false ;
}
return false ;
}
static int F_187 ( struct V_1 * V_4 )
{
struct V_1 * V_122 ;
F_152 (iter, memcg)
V_122 -> V_220 = false ;
return 0 ;
}
static void F_188 ( struct V_1 * V_4 )
{
struct V_1 * V_122 ;
F_152 (iter, memcg)
F_93 ( & V_122 -> V_221 ) ;
}
static void F_189 ( struct V_1 * V_4 )
{
struct V_1 * V_122 ;
F_152 (iter, memcg)
F_190 ( & V_122 -> V_221 , - 1 , 0 ) ;
}
static int F_191 ( T_5 * V_168 ,
unsigned V_222 , int V_223 , void * V_224 )
{
struct V_1 * V_225 = (struct V_1 * ) V_224 ;
struct V_1 * V_226 ;
struct V_227 * V_227 ;
V_227 = F_16 ( V_168 , struct V_227 , V_168 ) ;
V_226 = V_227 -> V_4 ;
if ( ! F_121 ( V_226 , V_225 )
&& ! F_121 ( V_225 , V_226 ) )
return 0 ;
return F_192 ( V_168 , V_222 , V_223 , V_224 ) ;
}
static void F_193 ( struct V_1 * V_4 )
{
F_194 ( & V_228 , V_229 , 0 , V_4 ) ;
}
static void F_195 ( struct V_1 * V_4 )
{
if ( V_4 && F_102 ( & V_4 -> V_221 ) )
F_193 ( V_4 ) ;
}
static bool F_196 ( struct V_1 * V_4 , T_4 V_230 ,
int V_188 )
{
struct V_227 V_231 ;
bool V_232 , V_233 ;
V_231 . V_4 = V_4 ;
V_231 . V_168 . V_171 = 0 ;
V_231 . V_168 . V_234 = F_191 ;
V_231 . V_168 . V_235 = V_26 ;
F_197 ( & V_231 . V_168 . V_236 ) ;
V_233 = true ;
F_188 ( V_4 ) ;
F_55 ( & V_237 ) ;
V_232 = F_186 ( V_4 ) ;
F_140 ( & V_228 , & V_231 . V_168 , V_238 ) ;
if ( ! V_232 || V_4 -> V_239 )
V_233 = false ;
if ( V_232 )
F_198 ( V_4 ) ;
F_56 ( & V_237 ) ;
if ( V_233 ) {
F_142 ( & V_228 , & V_231 . V_168 ) ;
F_156 ( V_4 , V_230 , V_188 ) ;
} else {
F_141 () ;
F_142 ( & V_228 , & V_231 . V_168 ) ;
}
F_55 ( & V_237 ) ;
if ( V_232 )
F_187 ( V_4 ) ;
F_193 ( V_4 ) ;
F_56 ( & V_237 ) ;
F_189 ( V_4 ) ;
if ( F_199 ( V_194 ) || F_157 ( V_26 ) )
return false ;
F_200 ( 1 ) ;
return true ;
}
void F_201 ( struct V_39 * V_39 ,
bool * V_232 , unsigned long * V_171 )
{
struct V_1 * V_4 ;
struct V_144 * V_145 ;
V_145 = F_115 ( V_39 ) ;
V_240:
V_4 = V_145 -> V_1 ;
if ( F_91 ( ! V_4 || ! F_117 ( V_145 ) ) )
return;
if ( ! F_135 ( V_4 ) )
return;
F_143 ( V_4 , V_171 ) ;
if ( V_4 != V_145 -> V_1 || ! F_117 ( V_145 ) ) {
F_145 ( V_4 , V_171 ) ;
goto V_240;
}
* V_232 = true ;
}
void F_202 ( struct V_39 * V_39 , unsigned long * V_171 )
{
struct V_144 * V_145 = F_115 ( V_39 ) ;
F_145 ( V_145 -> V_1 , V_171 ) ;
}
void F_203 ( struct V_39 * V_39 ,
enum V_241 V_67 , int V_68 )
{
struct V_1 * V_4 ;
struct V_144 * V_145 = F_115 ( V_39 ) ;
unsigned long V_132 ( V_171 ) ;
if ( F_106 () )
return;
V_4 = V_145 -> V_1 ;
if ( F_91 ( ! V_4 || ! F_117 ( V_145 ) ) )
return;
switch ( V_67 ) {
case V_242 :
V_67 = V_243 ;
break;
default:
F_112 () ;
}
F_72 ( V_4 -> V_70 -> V_71 [ V_67 ] , V_68 ) ;
}
static bool F_204 ( struct V_1 * V_4 , unsigned int V_79 )
{
struct V_244 * V_245 ;
bool V_91 = true ;
if ( V_79 > V_246 )
return false ;
V_245 = & F_205 ( V_247 ) ;
if ( V_4 == V_245 -> V_248 && V_245 -> V_79 >= V_79 )
V_245 -> V_79 -= V_79 ;
else
V_91 = false ;
F_206 ( V_247 ) ;
return V_91 ;
}
static void F_207 ( struct V_244 * V_245 )
{
struct V_1 * V_249 = V_245 -> V_248 ;
if ( V_245 -> V_79 ) {
unsigned long V_250 = V_245 -> V_79 * V_251 ;
F_208 ( & V_249 -> V_59 , V_250 ) ;
if ( V_157 )
F_208 ( & V_249 -> V_158 , V_250 ) ;
V_245 -> V_79 = 0 ;
}
V_245 -> V_248 = NULL ;
}
static void F_209 ( struct V_252 * V_253 )
{
struct V_244 * V_245 = & F_210 ( V_247 ) ;
F_207 ( V_245 ) ;
F_8 ( V_254 , & V_245 -> V_171 ) ;
}
static void T_6 F_211 ( void )
{
int V_69 ;
F_212 (cpu) {
struct V_244 * V_245 =
& F_68 ( V_247 , V_69 ) ;
F_213 ( & V_245 -> V_255 , F_209 ) ;
}
}
static void F_214 ( struct V_1 * V_4 , unsigned int V_79 )
{
struct V_244 * V_245 = & F_205 ( V_247 ) ;
if ( V_245 -> V_248 != V_4 ) {
F_207 ( V_245 ) ;
V_245 -> V_248 = V_4 ;
}
V_245 -> V_79 += V_79 ;
F_206 ( V_247 ) ;
}
static void F_215 ( struct V_1 * V_146 , bool V_223 )
{
int V_69 , V_256 ;
F_66 () ;
V_256 = F_216 () ;
F_67 (cpu) {
struct V_244 * V_245 = & F_68 ( V_247 , V_69 ) ;
struct V_1 * V_4 ;
V_4 = V_245 -> V_248 ;
if ( ! V_4 || ! V_245 -> V_79 )
continue;
if ( ! F_121 ( V_146 , V_4 ) )
continue;
if ( ! F_217 ( V_254 , & V_245 -> V_171 ) ) {
if ( V_69 == V_256 )
F_209 ( & V_245 -> V_255 ) ;
else
F_218 ( V_69 , & V_245 -> V_255 ) ;
}
}
F_219 () ;
if ( ! V_223 )
goto V_139;
F_67 (cpu) {
struct V_244 * V_245 = & F_68 ( V_247 , V_69 ) ;
if ( F_5 ( V_254 , & V_245 -> V_171 ) )
F_220 ( & V_245 -> V_255 ) ;
}
V_139:
F_70 () ;
}
static void F_169 ( struct V_1 * V_146 )
{
if ( ! F_221 ( & V_257 ) )
return;
F_215 ( V_146 , false ) ;
F_222 ( & V_257 ) ;
}
static void F_223 ( struct V_1 * V_146 )
{
F_224 ( & V_257 ) ;
F_215 ( V_146 , true ) ;
F_222 ( & V_257 ) ;
}
static void F_225 ( struct V_1 * V_4 , int V_69 )
{
int V_177 ;
F_55 ( & V_4 -> V_72 ) ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
long V_258 = F_68 ( V_4 -> V_70 -> V_71 [ V_177 ] , V_69 ) ;
F_68 ( V_4 -> V_70 -> V_71 [ V_177 ] , V_69 ) = 0 ;
V_4 -> V_73 . V_71 [ V_177 ] += V_258 ;
}
for ( V_177 = 0 ; V_177 < V_259 ; V_177 ++ ) {
unsigned long V_258 = F_68 ( V_4 -> V_70 -> V_77 [ V_177 ] , V_69 ) ;
F_68 ( V_4 -> V_70 -> V_77 [ V_177 ] , V_69 ) = 0 ;
V_4 -> V_73 . V_77 [ V_177 ] += V_258 ;
}
F_56 ( & V_4 -> V_72 ) ;
}
static int F_226 ( struct V_260 * V_261 ,
unsigned long V_262 ,
void * V_263 )
{
int V_69 = ( unsigned long ) V_263 ;
struct V_244 * V_245 ;
struct V_1 * V_122 ;
if ( V_262 == V_264 )
return V_265 ;
if ( V_262 != V_266 && V_262 != V_267 )
return V_265 ;
F_227 (iter)
F_225 ( V_122 , V_69 ) ;
V_245 = & F_68 ( V_247 , V_69 ) ;
F_207 ( V_245 ) ;
return V_265 ;
}
static int F_228 ( struct V_1 * V_4 , T_4 V_187 ,
unsigned int V_79 , unsigned int V_268 ,
bool V_269 )
{
unsigned long V_270 = V_79 * V_251 ;
struct V_1 * V_271 ;
struct V_272 * V_273 ;
unsigned long V_171 = 0 ;
int V_91 ;
V_91 = F_229 ( & V_4 -> V_59 , V_270 , & V_273 ) ;
if ( F_230 ( ! V_91 ) ) {
if ( ! V_157 )
return V_274 ;
V_91 = F_229 ( & V_4 -> V_158 , V_270 , & V_273 ) ;
if ( F_230 ( ! V_91 ) )
return V_274 ;
F_208 ( & V_4 -> V_59 , V_270 ) ;
V_271 = F_231 ( V_273 , V_158 ) ;
V_171 |= V_205 ;
} else
V_271 = F_231 ( V_273 , V_59 ) ;
if ( V_79 > V_268 )
return V_275 ;
if ( ! ( V_187 & V_276 ) )
return V_277 ;
if ( V_187 & V_278 )
return V_279 ;
V_91 = F_168 ( V_271 , V_187 , V_171 ) ;
if ( F_127 ( V_271 ) >= V_79 )
return V_275 ;
if ( V_79 <= ( 1 << V_280 ) && V_91 )
return V_275 ;
if ( F_138 ( V_271 ) )
return V_275 ;
if ( ! V_269 )
return V_279 ;
if ( ! F_196 ( V_271 , V_187 , F_232 ( V_270 ) ) )
return V_281 ;
return V_275 ;
}
static int F_233 ( struct V_111 * V_112 ,
T_4 V_187 ,
unsigned int V_79 ,
struct V_1 * * V_282 ,
bool V_283 )
{
unsigned int V_284 = F_234 ( V_246 , V_79 ) ;
int V_285 = V_286 ;
struct V_1 * V_4 = NULL ;
int V_91 ;
if ( F_91 ( F_199 ( V_194 )
|| F_157 ( V_26 ) ) )
goto V_287;
if ( ! * V_282 && ! V_112 )
* V_282 = V_17 ;
V_240:
if ( * V_282 ) {
V_4 = * V_282 ;
if ( F_20 ( V_4 ) )
goto V_65;
if ( F_204 ( V_4 , V_79 ) )
goto V_65;
F_23 ( & V_4 -> V_15 ) ;
} else {
struct V_110 * V_48 ;
F_24 () ;
V_48 = F_97 ( V_112 -> V_113 ) ;
V_4 = F_25 ( V_48 ) ;
if ( ! V_4 )
V_4 = V_17 ;
if ( F_20 ( V_4 ) ) {
F_28 () ;
goto V_65;
}
if ( F_204 ( V_4 , V_79 ) ) {
F_28 () ;
goto V_65;
}
if ( ! F_27 ( & V_4 -> V_15 ) ) {
F_28 () ;
goto V_240;
}
F_28 () ;
}
do {
bool V_269 ;
if ( F_157 ( V_26 ) ) {
F_31 ( & V_4 -> V_15 ) ;
goto V_287;
}
V_269 = false ;
if ( V_283 && ! V_285 ) {
V_269 = true ;
V_285 = V_286 ;
}
V_91 = F_228 ( V_4 , V_187 , V_284 , V_79 ,
V_269 ) ;
switch ( V_91 ) {
case V_274 :
break;
case V_275 :
V_284 = V_79 ;
F_31 ( & V_4 -> V_15 ) ;
V_4 = NULL ;
goto V_240;
case V_277 :
F_31 ( & V_4 -> V_15 ) ;
goto V_288;
case V_279 :
if ( ! V_283 ) {
F_31 ( & V_4 -> V_15 ) ;
goto V_288;
}
V_285 -- ;
break;
case V_281 :
F_31 ( & V_4 -> V_15 ) ;
goto V_287;
}
} while ( V_91 != V_274 );
if ( V_284 > V_79 )
F_214 ( V_4 , V_284 - V_79 ) ;
F_31 ( & V_4 -> V_15 ) ;
V_65:
* V_282 = V_4 ;
return 0 ;
V_288:
* V_282 = NULL ;
return - V_289 ;
V_287:
* V_282 = V_17 ;
return - V_290 ;
}
static void F_235 ( struct V_1 * V_4 ,
unsigned int V_79 )
{
if ( ! F_20 ( V_4 ) ) {
unsigned long V_250 = V_79 * V_251 ;
F_208 ( & V_4 -> V_59 , V_250 ) ;
if ( V_157 )
F_208 ( & V_4 -> V_158 , V_250 ) ;
}
}
static void F_236 ( struct V_1 * V_4 ,
unsigned int V_79 )
{
unsigned long V_250 = V_79 * V_251 ;
if ( F_20 ( V_4 ) )
return;
F_237 ( & V_4 -> V_59 , V_4 -> V_59 . V_50 , V_250 ) ;
if ( V_157 )
F_237 ( & V_4 -> V_158 ,
V_4 -> V_158 . V_50 , V_250 ) ;
}
static struct V_1 * F_238 ( unsigned short V_291 )
{
struct V_13 * V_15 ;
if ( ! V_291 )
return NULL ;
V_15 = F_239 ( & V_292 , V_291 ) ;
if ( ! V_15 )
return NULL ;
return F_15 ( V_15 ) ;
}
struct V_1 * F_240 ( struct V_39 * V_39 )
{
struct V_1 * V_4 = NULL ;
struct V_144 * V_145 ;
unsigned short V_291 ;
T_7 V_293 ;
F_41 ( ! F_241 ( V_39 ) ) ;
V_145 = F_115 ( V_39 ) ;
F_242 ( V_145 ) ;
if ( F_117 ( V_145 ) ) {
V_4 = V_145 -> V_1 ;
if ( V_4 && ! F_27 ( & V_4 -> V_15 ) )
V_4 = NULL ;
} else if ( F_243 ( V_39 ) ) {
V_293 . V_68 = F_244 ( V_39 ) ;
V_291 = F_245 ( V_293 ) ;
F_24 () ;
V_4 = F_238 ( V_291 ) ;
if ( V_4 && ! F_27 ( & V_4 -> V_15 ) )
V_4 = NULL ;
F_28 () ;
}
F_246 ( V_145 ) ;
return V_4 ;
}
static void F_247 ( struct V_1 * V_4 ,
struct V_39 * V_39 ,
unsigned int V_79 ,
enum V_294 V_295 ,
bool V_296 )
{
struct V_144 * V_145 = F_115 ( V_39 ) ;
struct V_61 * V_132 ( V_61 ) ;
struct V_86 * V_86 ;
bool V_297 = false ;
bool V_78 ;
F_242 ( V_145 ) ;
F_41 ( F_117 ( V_145 ) ) ;
if ( V_296 ) {
V_61 = F_248 ( V_39 ) ;
F_249 ( & V_61 -> V_298 ) ;
if ( F_116 ( V_39 ) ) {
V_86 = F_113 ( V_61 , V_145 -> V_1 ) ;
F_250 ( V_39 ) ;
F_251 ( V_39 , V_86 , F_252 ( V_39 ) ) ;
V_297 = true ;
}
}
V_145 -> V_1 = V_4 ;
F_10 () ;
F_253 ( V_145 ) ;
if ( V_296 ) {
if ( V_297 ) {
V_86 = F_113 ( V_61 , V_145 -> V_1 ) ;
F_41 ( F_116 ( V_39 ) ) ;
F_254 ( V_39 ) ;
F_255 ( V_39 , V_86 , F_252 ( V_39 ) ) ;
}
F_256 ( & V_61 -> V_298 ) ;
}
if ( V_295 == V_299 )
V_78 = true ;
else
V_78 = false ;
F_74 ( V_4 , V_39 , V_78 , V_79 ) ;
F_246 ( V_145 ) ;
F_90 ( V_4 , V_39 ) ;
}
static inline bool F_257 ( struct V_1 * V_4 )
{
return ! F_106 () && ! F_20 ( V_4 ) &&
( V_4 -> V_6 & V_300 ) ;
}
static struct V_301 * F_258 ( struct V_302 * V_48 )
{
struct V_301 * V_303 ;
F_41 ( V_48 -> V_304 ) ;
V_303 = V_48 -> V_305 ;
return V_303 -> V_306 -> V_307 [ F_259 ( V_48 -> V_4 ) ] ;
}
static int F_260 ( struct V_107 * V_108 , struct V_308 * V_309 ,
struct V_310 * V_311 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
struct V_302 * V_312 ;
if ( ! F_257 ( V_4 ) )
return - V_313 ;
F_261 ( V_311 ) ;
F_224 ( & V_4 -> V_314 ) ;
F_262 (params, &memcg->memcg_slab_caches, list)
F_263 ( F_258 ( V_312 ) , V_311 ) ;
F_222 ( & V_4 -> V_314 ) ;
return 0 ;
}
static int F_264 ( struct V_1 * V_4 , T_4 V_315 , T_2 V_316 )
{
struct V_272 * V_273 ;
struct V_1 * V_317 ;
int V_91 = 0 ;
bool V_318 ;
V_91 = F_229 ( & V_4 -> V_32 , V_316 , & V_273 ) ;
if ( V_91 )
return V_91 ;
V_318 = ( V_315 & V_319 ) && ! ( V_315 & V_278 ) ;
V_317 = V_4 ;
V_91 = F_233 ( NULL , V_315 , V_316 >> V_155 ,
& V_317 , V_318 ) ;
if ( V_91 == - V_290 ) {
F_265 ( & V_4 -> V_59 , V_316 , & V_273 ) ;
if ( V_157 )
F_265 ( & V_4 -> V_158 , V_316 ,
& V_273 ) ;
V_91 = 0 ;
} else if ( V_91 )
F_208 ( & V_4 -> V_32 , V_316 ) ;
return V_91 ;
}
static void F_266 ( struct V_1 * V_4 , T_2 V_316 )
{
F_208 ( & V_4 -> V_59 , V_316 ) ;
if ( V_157 )
F_208 ( & V_4 -> V_158 , V_316 ) ;
if ( F_208 ( & V_4 -> V_32 , V_316 ) )
return;
if ( F_11 ( V_4 ) )
F_31 ( & V_4 -> V_15 ) ;
}
void F_267 ( struct V_1 * V_4 , struct V_301 * V_303 )
{
if ( ! V_4 )
return;
F_224 ( & V_4 -> V_314 ) ;
F_268 ( & V_303 -> V_306 -> V_320 , & V_4 -> V_321 ) ;
F_222 ( & V_4 -> V_314 ) ;
}
int F_259 ( struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_31 : - 1 ;
}
int F_269 ( struct V_1 * V_4 )
{
int V_184 , V_91 ;
V_184 = F_270 ( & V_30 ,
0 , V_322 , V_323 ) ;
if ( V_184 < 0 )
return V_184 ;
F_6 ( V_4 ) ;
V_91 = F_271 ( V_184 + 1 ) ;
if ( V_91 ) {
F_37 ( & V_30 , V_184 ) ;
F_7 ( V_4 ) ;
return V_91 ;
}
V_4 -> V_31 = V_184 ;
F_197 ( & V_4 -> V_321 ) ;
F_272 ( & V_4 -> V_314 ) ;
return 0 ;
}
static T_1 F_273 ( int V_324 )
{
T_8 V_316 ;
if ( V_324 <= 0 )
return 0 ;
V_316 = 2 * V_324 ;
if ( V_316 < V_325 )
V_316 = V_325 ;
else if ( V_316 > V_322 )
V_316 = V_322 ;
return V_316 ;
}
void F_274 ( int V_184 )
{
if ( V_184 > V_326 )
V_326 = F_273 ( V_184 ) ;
}
int F_275 ( struct V_301 * V_14 , int V_324 )
{
struct V_302 * V_327 = V_14 -> V_306 ;
F_41 ( V_14 -> V_306 && ! V_14 -> V_306 -> V_304 ) ;
if ( V_324 > V_326 ) {
int V_177 ;
T_8 V_316 = F_273 ( V_324 ) ;
V_316 *= sizeof( void * ) ;
V_316 += sizeof( struct V_302 ) ;
V_14 -> V_306 = F_276 ( V_316 , V_323 ) ;
if ( ! V_14 -> V_306 ) {
V_14 -> V_306 = V_327 ;
return - V_289 ;
}
V_14 -> V_306 -> V_304 = true ;
for ( V_177 = 0 ; V_177 < V_326 ; V_177 ++ ) {
if ( ! V_327 -> V_307 [ V_177 ] )
continue;
V_14 -> V_306 -> V_307 [ V_177 ] =
V_327 -> V_307 [ V_177 ] ;
}
F_277 ( V_327 ) ;
}
return 0 ;
}
int F_278 ( struct V_1 * V_4 , struct V_301 * V_14 ,
struct V_301 * V_305 )
{
T_1 V_316 = sizeof( struct V_302 ) ;
if ( ! F_279 () )
return 0 ;
if ( ! V_4 )
V_316 += V_326 * sizeof( void * ) ;
V_14 -> V_306 = F_276 ( V_316 , V_323 ) ;
if ( ! V_14 -> V_306 )
return - V_289 ;
if ( V_4 ) {
V_14 -> V_306 -> V_4 = V_4 ;
V_14 -> V_306 -> V_305 = V_305 ;
F_213 ( & V_14 -> V_306 -> V_328 ,
V_329 ) ;
} else
V_14 -> V_306 -> V_304 = true ;
return 0 ;
}
void F_280 ( struct V_301 * V_14 )
{
struct V_301 * V_114 ;
struct V_1 * V_4 ;
int V_291 ;
if ( ! V_14 -> V_306 )
return;
if ( V_14 -> V_306 -> V_304 )
goto V_139;
V_4 = V_14 -> V_306 -> V_4 ;
V_291 = F_259 ( V_4 ) ;
V_114 = V_14 -> V_306 -> V_305 ;
V_114 -> V_306 -> V_307 [ V_291 ] = NULL ;
F_224 ( & V_4 -> V_314 ) ;
F_281 ( & V_14 -> V_306 -> V_320 ) ;
F_222 ( & V_4 -> V_314 ) ;
F_31 ( & V_4 -> V_15 ) ;
V_139:
F_277 ( V_14 -> V_306 ) ;
}
static inline void F_282 ( void )
{
F_41 ( ! V_26 -> V_112 ) ;
V_26 -> V_330 ++ ;
}
static inline void F_283 ( void )
{
F_41 ( ! V_26 -> V_112 ) ;
V_26 -> V_330 -- ;
}
static void V_329 ( struct V_252 * V_331 )
{
struct V_301 * V_303 ;
struct V_302 * V_48 ;
V_48 = F_16 ( V_331 , struct V_302 , V_328 ) ;
V_303 = F_258 ( V_48 ) ;
if ( F_102 ( & V_303 -> V_306 -> V_79 ) != 0 ) {
F_284 ( V_303 ) ;
if ( F_102 ( & V_303 -> V_306 -> V_79 ) == 0 )
return;
} else
F_285 ( V_303 ) ;
}
void F_286 ( struct V_301 * V_303 )
{
if ( ! V_303 -> V_306 -> V_332 )
return;
if ( F_287 ( & V_303 -> V_306 -> V_328 ) )
return;
F_288 ( & V_303 -> V_306 -> V_328 ) ;
}
static struct V_301 * F_289 ( struct V_1 * V_4 ,
struct V_301 * V_14 )
{
struct V_301 * V_333 ;
static char * V_334 = NULL ;
F_290 ( & V_335 ) ;
if ( ! V_334 ) {
V_334 = F_291 ( V_176 , V_323 ) ;
if ( ! V_334 )
return NULL ;
}
F_24 () ;
snprintf ( V_334 , V_176 , L_13 , V_14 -> V_336 ,
F_259 ( V_4 ) , F_292 ( V_4 -> V_15 . V_107 ) ) ;
F_28 () ;
V_333 = F_293 ( V_4 , V_334 , V_14 -> V_337 , V_14 -> V_338 ,
( V_14 -> V_171 & ~ V_339 ) , V_14 -> V_340 , V_14 ) ;
if ( V_333 )
V_333 -> V_341 |= V_342 ;
return V_333 ;
}
static struct V_301 * F_294 ( struct V_1 * V_4 ,
struct V_301 * V_303 )
{
struct V_301 * V_343 ;
int V_67 ;
F_22 ( ! F_257 ( V_4 ) ) ;
V_67 = F_259 ( V_4 ) ;
F_224 ( & V_335 ) ;
V_343 = V_303 -> V_306 -> V_307 [ V_67 ] ;
if ( V_343 ) {
F_31 ( & V_4 -> V_15 ) ;
goto V_139;
}
V_343 = F_289 ( V_4 , V_303 ) ;
if ( V_343 == NULL ) {
V_343 = V_303 ;
F_31 ( & V_4 -> V_15 ) ;
goto V_139;
}
F_176 ( & V_343 -> V_306 -> V_79 , 0 ) ;
V_303 -> V_306 -> V_307 [ V_67 ] = V_343 ;
F_295 () ;
V_139:
F_222 ( & V_335 ) ;
return V_343 ;
}
void F_296 ( struct V_301 * V_14 )
{
struct V_301 * V_344 ;
int V_177 ;
if ( ! V_14 -> V_306 )
return;
if ( ! V_14 -> V_306 -> V_304 )
return;
F_224 ( & V_345 ) ;
for ( V_177 = 0 ; V_177 < V_326 ; V_177 ++ ) {
V_344 = V_14 -> V_306 -> V_307 [ V_177 ] ;
if ( ! V_344 )
continue;
V_344 -> V_306 -> V_332 = false ;
F_297 ( & V_344 -> V_306 -> V_328 ) ;
F_285 ( V_344 ) ;
}
F_222 ( & V_345 ) ;
}
static void F_298 ( struct V_1 * V_4 )
{
struct V_301 * V_303 ;
struct V_302 * V_312 ;
if ( ! F_4 ( V_4 ) )
return;
F_224 ( & V_4 -> V_314 ) ;
F_262 (params, &memcg->memcg_slab_caches, list) {
V_303 = F_258 ( V_312 ) ;
V_303 -> V_306 -> V_332 = true ;
F_288 ( & V_303 -> V_306 -> V_328 ) ;
}
F_222 ( & V_4 -> V_314 ) ;
}
static void F_299 ( struct V_252 * V_331 )
{
struct V_346 * V_347 ;
V_347 = F_16 ( V_331 , struct V_346 , V_255 ) ;
F_294 ( V_347 -> V_4 , V_347 -> V_303 ) ;
F_277 ( V_347 ) ;
}
static void F_300 ( struct V_1 * V_4 ,
struct V_301 * V_303 )
{
struct V_346 * V_347 ;
V_347 = F_291 ( sizeof( struct V_346 ) , V_348 ) ;
if ( V_347 == NULL ) {
F_31 ( & V_4 -> V_15 ) ;
return;
}
V_347 -> V_4 = V_4 ;
V_347 -> V_303 = V_303 ;
F_213 ( & V_347 -> V_255 , F_299 ) ;
F_288 ( & V_347 -> V_255 ) ;
}
static void F_301 ( struct V_1 * V_4 ,
struct V_301 * V_303 )
{
F_282 () ;
F_300 ( V_4 , V_303 ) ;
F_283 () ;
}
struct V_301 * F_302 ( struct V_301 * V_303 ,
T_4 V_315 )
{
struct V_1 * V_4 ;
int V_67 ;
F_41 ( ! V_303 -> V_306 ) ;
F_41 ( ! V_303 -> V_306 -> V_304 ) ;
if ( ! V_26 -> V_112 || V_26 -> V_330 )
return V_303 ;
F_24 () ;
V_4 = F_25 ( F_97 ( V_26 -> V_112 -> V_113 ) ) ;
if ( ! F_257 ( V_4 ) )
goto V_139;
V_67 = F_259 ( V_4 ) ;
F_303 () ;
if ( F_230 ( V_303 -> V_306 -> V_307 [ V_67 ] ) ) {
V_303 = V_303 -> V_306 -> V_307 [ V_67 ] ;
goto V_139;
}
if ( ! F_27 ( & V_4 -> V_15 ) )
goto V_139;
F_28 () ;
F_301 ( V_4 , V_303 ) ;
return V_303 ;
V_139:
F_28 () ;
return V_303 ;
}
bool
F_304 ( T_4 V_315 , struct V_1 * * V_317 , int V_188 )
{
struct V_1 * V_4 ;
int V_91 ;
* V_317 = NULL ;
if ( ! V_26 -> V_112 || V_26 -> V_330 )
return true ;
V_4 = F_96 ( V_26 -> V_112 ) ;
if ( F_91 ( ! V_4 ) )
return true ;
if ( ! F_257 ( V_4 ) ) {
F_31 ( & V_4 -> V_15 ) ;
return true ;
}
V_91 = F_264 ( V_4 , V_315 , V_251 << V_188 ) ;
if ( ! V_91 )
* V_317 = V_4 ;
F_31 ( & V_4 -> V_15 ) ;
return ( V_91 == 0 ) ;
}
void F_305 ( struct V_39 * V_39 , struct V_1 * V_4 ,
int V_188 )
{
struct V_144 * V_145 ;
F_41 ( F_20 ( V_4 ) ) ;
if ( ! V_39 ) {
F_266 ( V_4 , V_251 << V_188 ) ;
return;
}
V_145 = F_115 ( V_39 ) ;
F_242 ( V_145 ) ;
V_145 -> V_1 = V_4 ;
F_253 ( V_145 ) ;
F_246 ( V_145 ) ;
}
void F_306 ( struct V_39 * V_39 , int V_188 )
{
struct V_1 * V_4 = NULL ;
struct V_144 * V_145 ;
V_145 = F_115 ( V_39 ) ;
if ( ! F_117 ( V_145 ) )
return;
F_242 ( V_145 ) ;
if ( F_117 ( V_145 ) ) {
V_4 = V_145 -> V_1 ;
F_307 ( V_145 ) ;
}
F_246 ( V_145 ) ;
if ( ! V_4 )
return;
F_41 ( F_20 ( V_4 ) ) ;
F_266 ( V_4 , V_251 << V_188 ) ;
}
static inline void F_298 ( struct V_1 * V_4 )
{
}
void F_308 ( struct V_39 * V_349 )
{
struct V_144 * V_350 = F_115 ( V_349 ) ;
struct V_144 * V_145 ;
struct V_1 * V_4 ;
int V_177 ;
if ( F_106 () )
return;
V_4 = V_350 -> V_1 ;
for ( V_177 = 1 ; V_177 < V_351 ; V_177 ++ ) {
V_145 = V_350 + V_177 ;
V_145 -> V_1 = V_4 ;
F_10 () ;
V_145 -> V_171 = V_350 -> V_171 & ~ V_352 ;
}
F_309 ( V_4 -> V_70 -> V_71 [ V_82 ] ,
V_351 ) ;
}
static int F_310 ( struct V_39 * V_39 ,
unsigned int V_79 ,
struct V_144 * V_145 ,
struct V_1 * V_164 ,
struct V_1 * V_165 )
{
unsigned long V_171 ;
int V_91 ;
bool V_78 = F_311 ( V_39 ) ;
F_41 ( V_164 == V_165 ) ;
F_41 ( F_116 ( V_39 ) ) ;
V_91 = - V_353 ;
if ( V_79 > 1 && ! F_77 ( V_39 ) )
goto V_139;
F_242 ( V_145 ) ;
V_91 = - V_354 ;
if ( ! F_117 ( V_145 ) || V_145 -> V_1 != V_164 )
goto V_166;
F_143 ( V_164 , & V_171 ) ;
if ( ! V_78 && F_312 ( V_39 ) ) {
F_75 () ;
F_313 ( V_164 -> V_70 -> V_71 [ V_243 ] ) ;
F_78 ( V_165 -> V_70 -> V_71 [ V_243 ] ) ;
F_79 () ;
}
F_74 ( V_164 , V_39 , V_78 , - V_79 ) ;
V_145 -> V_1 = V_165 ;
F_74 ( V_165 , V_39 , V_78 , V_79 ) ;
F_145 ( V_164 , & V_171 ) ;
V_91 = 0 ;
V_166:
F_246 ( V_145 ) ;
F_90 ( V_165 , V_39 ) ;
F_90 ( V_164 , V_39 ) ;
V_139:
return V_91 ;
}
static int F_314 ( struct V_39 * V_39 ,
struct V_144 * V_145 ,
struct V_1 * V_355 )
{
struct V_1 * V_50 ;
unsigned int V_79 ;
unsigned long V_132 ( V_171 ) ;
int V_91 ;
F_41 ( F_20 ( V_355 ) ) ;
V_91 = - V_353 ;
if ( ! F_315 ( V_39 ) )
goto V_139;
if ( F_316 ( V_39 ) )
goto V_356;
V_79 = F_317 ( V_39 ) ;
V_50 = F_58 ( V_355 ) ;
if ( ! V_50 )
V_50 = V_17 ;
if ( V_79 > 1 ) {
F_41 ( ! F_77 ( V_39 ) ) ;
V_171 = F_318 ( V_39 ) ;
}
V_91 = F_310 ( V_39 , V_79 ,
V_145 , V_355 , V_50 ) ;
if ( ! V_91 )
F_236 ( V_355 , V_79 ) ;
if ( V_79 > 1 )
F_319 ( V_39 , V_171 ) ;
F_320 ( V_39 ) ;
V_356:
F_321 ( V_39 ) ;
V_139:
return V_91 ;
}
static int F_322 ( struct V_39 * V_39 , struct V_111 * V_112 ,
T_4 V_187 , enum V_294 V_295 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_79 = 1 ;
bool V_283 = true ;
int V_91 ;
if ( F_77 ( V_39 ) ) {
V_79 <<= F_323 ( V_39 ) ;
F_41 ( ! F_77 ( V_39 ) ) ;
V_283 = false ;
}
V_91 = F_233 ( V_112 , V_187 , V_79 , & V_4 , V_283 ) ;
if ( V_91 == - V_289 )
return V_91 ;
F_247 ( V_4 , V_39 , V_79 , V_295 , false ) ;
return 0 ;
}
int F_324 ( struct V_39 * V_39 ,
struct V_111 * V_112 , T_4 V_187 )
{
if ( F_106 () )
return 0 ;
F_41 ( F_312 ( V_39 ) ) ;
F_41 ( V_39 -> V_357 && ! F_311 ( V_39 ) ) ;
F_41 ( ! V_112 ) ;
return F_322 ( V_39 , V_112 , V_187 ,
V_299 ) ;
}
static int F_325 ( struct V_111 * V_112 ,
struct V_39 * V_39 ,
T_4 V_230 ,
struct V_1 * * V_358 )
{
struct V_1 * V_4 ;
struct V_144 * V_145 ;
int V_91 ;
V_145 = F_115 ( V_39 ) ;
if ( F_117 ( V_145 ) )
return 0 ;
if ( ! V_157 )
goto V_359;
V_4 = F_240 ( V_39 ) ;
if ( ! V_4 )
goto V_359;
* V_358 = V_4 ;
V_91 = F_233 ( NULL , V_230 , 1 , V_358 , true ) ;
F_31 ( & V_4 -> V_15 ) ;
if ( V_91 == - V_290 )
V_91 = 0 ;
return V_91 ;
V_359:
V_91 = F_233 ( V_112 , V_230 , 1 , V_358 , true ) ;
if ( V_91 == - V_290 )
V_91 = 0 ;
return V_91 ;
}
int F_326 ( struct V_111 * V_112 , struct V_39 * V_39 ,
T_4 V_187 , struct V_1 * * V_358 )
{
* V_358 = NULL ;
if ( F_106 () )
return 0 ;
if ( ! F_243 ( V_39 ) ) {
int V_91 ;
V_91 = F_233 ( V_112 , V_187 , 1 , V_358 , true ) ;
if ( V_91 == - V_290 )
V_91 = 0 ;
return V_91 ;
}
return F_325 ( V_112 , V_39 , V_187 , V_358 ) ;
}
void F_327 ( struct V_1 * V_4 )
{
if ( F_106 () )
return;
if ( ! V_4 )
return;
F_235 ( V_4 , 1 ) ;
}
static void
F_328 ( struct V_39 * V_39 , struct V_1 * V_4 ,
enum V_294 V_295 )
{
if ( F_106 () )
return;
if ( ! V_4 )
return;
F_247 ( V_4 , V_39 , 1 , V_295 , true ) ;
if ( V_157 && F_243 ( V_39 ) ) {
T_7 V_293 = { . V_68 = F_244 (page) } ;
F_329 ( V_293 ) ;
}
}
void F_330 ( struct V_39 * V_39 ,
struct V_1 * V_4 )
{
F_328 ( V_39 , V_4 ,
V_299 ) ;
}
int F_331 ( struct V_39 * V_39 , struct V_111 * V_112 ,
T_4 V_187 )
{
struct V_1 * V_4 = NULL ;
enum V_294 type = V_360 ;
int V_91 ;
if ( F_106 () )
return 0 ;
if ( F_332 ( V_39 ) )
return 0 ;
if ( ! F_243 ( V_39 ) )
V_91 = F_322 ( V_39 , V_112 , V_187 , type ) ;
else {
V_91 = F_325 ( V_112 , V_39 ,
V_187 , & V_4 ) ;
if ( ! V_91 )
F_328 ( V_39 , V_4 , type ) ;
}
return V_91 ;
}
static void F_333 ( struct V_1 * V_4 ,
unsigned int V_79 ,
const enum V_294 V_295 )
{
struct V_361 * V_284 = NULL ;
bool V_362 = true ;
if ( ! V_157 || V_295 == V_363 )
V_362 = false ;
V_284 = & V_26 -> V_364 ;
if ( ! V_284 -> V_4 )
V_284 -> V_4 = V_4 ;
if ( ! V_284 -> V_365 || F_199 ( V_194 ) )
goto V_366;
if ( V_79 > 1 )
goto V_366;
if ( V_284 -> V_4 != V_4 )
goto V_366;
V_284 -> V_79 ++ ;
if ( V_362 )
V_284 -> V_367 ++ ;
return;
V_366:
F_208 ( & V_4 -> V_59 , V_79 * V_251 ) ;
if ( V_362 )
F_208 ( & V_4 -> V_158 , V_79 * V_251 ) ;
if ( F_91 ( V_284 -> V_4 != V_4 ) )
F_195 ( V_4 ) ;
}
static struct V_1 *
F_334 ( struct V_39 * V_39 , enum V_294 V_295 ,
bool V_368 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_79 = 1 ;
struct V_144 * V_145 ;
bool V_78 ;
if ( F_106 () )
return NULL ;
if ( F_77 ( V_39 ) ) {
V_79 <<= F_323 ( V_39 ) ;
F_41 ( ! F_77 ( V_39 ) ) ;
}
V_145 = F_115 ( V_39 ) ;
if ( F_91 ( ! F_117 ( V_145 ) ) )
return NULL ;
F_242 ( V_145 ) ;
V_4 = V_145 -> V_1 ;
if ( ! F_117 ( V_145 ) )
goto V_369;
V_78 = F_311 ( V_39 ) ;
switch ( V_295 ) {
case V_299 :
V_78 = true ;
case V_370 :
if ( F_312 ( V_39 ) )
goto V_369;
if ( ! V_368 && F_335 ( V_145 ) )
goto V_369;
break;
case V_363 :
if ( ! F_311 ( V_39 ) ) {
if ( V_39 -> V_357 && ! F_336 ( V_39 ) )
goto V_369;
} else if ( F_312 ( V_39 ) )
goto V_369;
break;
default:
break;
}
F_74 ( V_4 , V_39 , V_78 , - V_79 ) ;
F_307 ( V_145 ) ;
F_246 ( V_145 ) ;
F_90 ( V_4 , V_39 ) ;
if ( V_157 && V_295 == V_363 ) {
F_71 ( V_4 , true ) ;
F_23 ( & V_4 -> V_15 ) ;
}
if ( ! V_368 && ! F_20 ( V_4 ) )
F_333 ( V_4 , V_79 , V_295 ) ;
return V_4 ;
V_369:
F_246 ( V_145 ) ;
return NULL ;
}
void F_337 ( struct V_39 * V_39 )
{
if ( F_312 ( V_39 ) )
return;
F_41 ( V_39 -> V_357 && ! F_311 ( V_39 ) ) ;
if ( F_243 ( V_39 ) )
return;
F_334 ( V_39 , V_299 , false ) ;
}
void F_338 ( struct V_39 * V_39 )
{
F_41 ( F_312 ( V_39 ) ) ;
F_41 ( V_39 -> V_357 ) ;
F_334 ( V_39 , V_360 , false ) ;
}
void F_339 ( void )
{
V_26 -> V_364 . V_365 ++ ;
if ( V_26 -> V_364 . V_365 == 1 ) {
V_26 -> V_364 . V_4 = NULL ;
V_26 -> V_364 . V_79 = 0 ;
V_26 -> V_364 . V_367 = 0 ;
}
}
void F_340 ( void )
{
struct V_361 * V_284 = & V_26 -> V_364 ;
if ( ! V_284 -> V_365 )
return;
V_284 -> V_365 -- ;
if ( V_284 -> V_365 )
return;
if ( ! V_284 -> V_4 )
return;
if ( V_284 -> V_79 )
F_208 ( & V_284 -> V_4 -> V_59 ,
V_284 -> V_79 * V_251 ) ;
if ( V_284 -> V_367 )
F_208 ( & V_284 -> V_4 -> V_158 ,
V_284 -> V_367 * V_251 ) ;
F_195 ( V_284 -> V_4 ) ;
V_284 -> V_4 = NULL ;
}
void
F_341 ( struct V_39 * V_39 , T_7 V_293 , bool V_371 )
{
struct V_1 * V_4 ;
int V_295 = V_363 ;
if ( ! V_371 )
V_295 = V_370 ;
V_4 = F_334 ( V_39 , V_295 , false ) ;
if ( V_157 && V_371 && V_4 )
F_342 ( V_293 , F_343 ( & V_4 -> V_15 ) ) ;
}
void F_329 ( T_7 V_293 )
{
struct V_1 * V_4 ;
unsigned short V_291 ;
if ( ! V_157 )
return;
V_291 = F_342 ( V_293 , 0 ) ;
F_24 () ;
V_4 = F_238 ( V_291 ) ;
if ( V_4 ) {
if ( ! F_20 ( V_4 ) )
F_208 ( & V_4 -> V_158 , V_251 ) ;
F_71 ( V_4 , false ) ;
F_31 ( & V_4 -> V_15 ) ;
}
F_28 () ;
}
static int F_344 ( T_7 V_372 ,
struct V_1 * V_164 , struct V_1 * V_165 )
{
unsigned short V_373 , V_374 ;
V_373 = F_343 ( & V_164 -> V_15 ) ;
V_374 = F_343 ( & V_165 -> V_15 ) ;
if ( F_345 ( V_372 , V_373 , V_374 ) == V_373 ) {
F_71 ( V_164 , false ) ;
F_71 ( V_165 , true ) ;
F_23 ( & V_165 -> V_15 ) ;
return 0 ;
}
return - V_354 ;
}
static inline int F_344 ( T_7 V_372 ,
struct V_1 * V_164 , struct V_1 * V_165 )
{
return - V_354 ;
}
void F_346 ( struct V_39 * V_39 , struct V_39 * V_375 ,
struct V_1 * * V_358 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_79 = 1 ;
struct V_144 * V_145 ;
enum V_294 V_295 ;
* V_358 = NULL ;
if ( F_106 () )
return;
if ( F_77 ( V_39 ) )
V_79 <<= F_323 ( V_39 ) ;
V_145 = F_115 ( V_39 ) ;
F_242 ( V_145 ) ;
if ( F_117 ( V_145 ) ) {
V_4 = V_145 -> V_1 ;
F_23 ( & V_4 -> V_15 ) ;
if ( F_311 ( V_39 ) )
F_347 ( V_145 ) ;
}
F_246 ( V_145 ) ;
if ( ! V_4 )
return;
* V_358 = V_4 ;
if ( F_311 ( V_39 ) )
V_295 = V_299 ;
else
V_295 = V_360 ;
F_247 ( V_4 , V_375 , V_79 , V_295 , false ) ;
}
void F_348 ( struct V_1 * V_4 ,
struct V_39 * V_376 , struct V_39 * V_375 , bool V_377 )
{
struct V_39 * V_378 , * V_379 ;
struct V_144 * V_145 ;
bool V_78 ;
if ( ! V_4 )
return;
if ( ! V_377 ) {
V_378 = V_376 ;
V_379 = V_375 ;
} else {
V_378 = V_375 ;
V_379 = V_376 ;
}
V_78 = F_311 ( V_378 ) ;
F_334 ( V_379 ,
V_78 ? V_299
: V_360 ,
true ) ;
F_31 ( & V_4 -> V_15 ) ;
V_145 = F_115 ( V_376 ) ;
F_242 ( V_145 ) ;
F_349 ( V_145 ) ;
F_246 ( V_145 ) ;
if ( V_78 )
F_337 ( V_378 ) ;
}
void F_350 ( struct V_39 * V_376 ,
struct V_39 * V_375 )
{
struct V_1 * V_4 = NULL ;
struct V_144 * V_145 ;
enum V_294 type = V_360 ;
if ( F_106 () )
return;
V_145 = F_115 ( V_376 ) ;
F_242 ( V_145 ) ;
if ( F_117 ( V_145 ) ) {
V_4 = V_145 -> V_1 ;
F_74 ( V_4 , V_376 , false , - 1 ) ;
F_307 ( V_145 ) ;
}
F_246 ( V_145 ) ;
if ( ! V_4 )
return;
F_247 ( V_4 , V_375 , 1 , type , true ) ;
}
static struct V_144 * F_351 ( struct V_39 * V_39 )
{
struct V_144 * V_145 ;
V_145 = F_115 ( V_39 ) ;
if ( F_230 ( V_145 ) && F_117 ( V_145 ) )
return V_145 ;
return NULL ;
}
bool F_352 ( struct V_39 * V_39 )
{
if ( F_106 () )
return false ;
return F_351 ( V_39 ) != NULL ;
}
void F_353 ( struct V_39 * V_39 )
{
struct V_144 * V_145 ;
V_145 = F_351 ( V_39 ) ;
if ( V_145 ) {
F_354 ( L_14 ,
V_145 , V_145 -> V_171 , V_145 -> V_1 ) ;
}
}
static int F_355 ( struct V_1 * V_4 ,
unsigned long long V_68 )
{
int V_380 ;
T_2 V_381 , V_382 ;
int V_91 = 0 ;
int V_383 = F_154 ( V_4 ) ;
T_2 V_384 , V_385 ;
int V_386 ;
V_380 = V_286 * V_383 ;
V_385 = F_38 ( & V_4 -> V_59 , V_33 ) ;
V_386 = 0 ;
while ( V_380 ) {
if ( F_356 ( V_26 ) ) {
V_91 = - V_290 ;
break;
}
F_224 ( & V_345 ) ;
V_381 = F_38 ( & V_4 -> V_158 , V_178 ) ;
if ( V_381 < V_68 ) {
V_91 = - V_354 ;
F_222 ( & V_345 ) ;
break;
}
V_382 = F_38 ( & V_4 -> V_59 , V_178 ) ;
if ( V_382 < V_68 )
V_386 = 1 ;
V_91 = F_357 ( & V_4 -> V_59 , V_68 ) ;
if ( ! V_91 ) {
if ( V_381 == V_68 )
V_4 -> V_207 = true ;
else
V_4 -> V_207 = false ;
}
F_222 ( & V_345 ) ;
if ( ! V_91 )
break;
F_168 ( V_4 , V_323 ,
V_206 ) ;
V_384 = F_38 ( & V_4 -> V_59 , V_33 ) ;
if ( V_384 >= V_385 )
V_380 -- ;
else
V_385 = V_384 ;
}
if ( ! V_91 && V_386 )
F_195 ( V_4 ) ;
return V_91 ;
}
static int F_358 ( struct V_1 * V_4 ,
unsigned long long V_68 )
{
int V_380 ;
T_2 V_382 , V_381 , V_385 , V_384 ;
int V_383 = F_154 ( V_4 ) ;
int V_91 = - V_353 ;
int V_386 = 0 ;
V_380 = V_383 * V_286 ;
V_385 = F_38 ( & V_4 -> V_158 , V_33 ) ;
while ( V_380 ) {
if ( F_356 ( V_26 ) ) {
V_91 = - V_290 ;
break;
}
F_224 ( & V_345 ) ;
V_382 = F_38 ( & V_4 -> V_59 , V_178 ) ;
if ( V_382 > V_68 ) {
V_91 = - V_354 ;
F_222 ( & V_345 ) ;
break;
}
V_381 = F_38 ( & V_4 -> V_158 , V_178 ) ;
if ( V_381 < V_68 )
V_386 = 1 ;
V_91 = F_357 ( & V_4 -> V_158 , V_68 ) ;
if ( ! V_91 ) {
if ( V_382 == V_68 )
V_4 -> V_207 = true ;
else
V_4 -> V_207 = false ;
}
F_222 ( & V_345 ) ;
if ( ! V_91 )
break;
F_168 ( V_4 , V_323 ,
V_205 |
V_206 ) ;
V_384 = F_38 ( & V_4 -> V_158 , V_33 ) ;
if ( V_384 >= V_385 )
V_380 -- ;
else
V_385 = V_384 ;
}
if ( ! V_91 && V_386 )
F_195 ( V_4 ) ;
return V_91 ;
}
unsigned long F_359 ( struct V_61 * V_61 , int V_188 ,
T_4 V_187 ,
unsigned long * V_216 )
{
unsigned long V_387 = 0 ;
struct V_34 * V_44 , * V_388 = NULL ;
unsigned long V_389 ;
int V_204 = 0 ;
struct V_40 * V_45 ;
unsigned long long V_58 ;
unsigned long V_218 ;
if ( V_188 > 0 )
return 0 ;
V_45 = F_46 ( F_107 ( V_61 ) , F_108 ( V_61 ) ) ;
do {
if ( V_388 )
V_44 = V_388 ;
else
V_44 = F_64 ( V_45 ) ;
if ( ! V_44 )
break;
V_218 = 0 ;
V_389 = F_184 ( V_44 -> V_4 , V_61 ,
V_187 , & V_218 ) ;
V_387 += V_389 ;
* V_216 += V_218 ;
F_55 ( & V_45 -> V_57 ) ;
V_388 = NULL ;
if ( ! V_389 ) {
do {
V_388 =
F_62 ( V_45 ) ;
if ( V_388 == V_44 )
F_31 ( & V_388 -> V_4 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_52 ( V_44 -> V_4 , V_44 , V_45 ) ;
V_58 = F_59 ( & V_44 -> V_4 -> V_59 ) ;
F_48 ( V_44 -> V_4 , V_44 , V_45 , V_58 ) ;
F_56 ( & V_45 -> V_57 ) ;
F_31 ( & V_44 -> V_4 -> V_15 ) ;
V_204 ++ ;
if ( ! V_387 &&
( V_388 == NULL ||
V_204 > V_390 ) )
break;
} while ( ! V_387 );
if ( V_388 )
F_31 ( & V_388 -> V_4 -> V_15 ) ;
return V_387 ;
}
static void F_360 ( struct V_1 * V_4 ,
int V_60 , int V_36 , enum V_87 V_88 )
{
struct V_86 * V_86 ;
unsigned long V_171 ;
struct V_391 * V_320 ;
struct V_39 * V_392 ;
struct V_61 * V_61 ;
V_61 = & F_361 ( V_60 ) -> V_393 [ V_36 ] ;
V_86 = F_113 ( V_61 , V_4 ) ;
V_320 = & V_86 -> V_394 [ V_88 ] ;
V_392 = NULL ;
do {
struct V_144 * V_145 ;
struct V_39 * V_39 ;
F_144 ( & V_61 -> V_298 , V_171 ) ;
if ( F_362 ( V_320 ) ) {
F_146 ( & V_61 -> V_298 , V_171 ) ;
break;
}
V_39 = F_363 ( V_320 -> V_127 , struct V_39 , V_88 ) ;
if ( V_392 == V_39 ) {
F_364 ( & V_39 -> V_88 , V_320 ) ;
V_392 = NULL ;
F_146 ( & V_61 -> V_298 , V_171 ) ;
continue;
}
F_146 ( & V_61 -> V_298 , V_171 ) ;
V_145 = F_115 ( V_39 ) ;
if ( F_314 ( V_39 , V_145 , V_4 ) ) {
V_392 = V_39 ;
F_365 () ;
} else
V_392 = NULL ;
} while ( ! F_362 ( V_320 ) );
}
static void F_366 ( struct V_1 * V_4 )
{
int V_60 , V_36 ;
T_2 V_395 ;
do {
F_367 () ;
F_223 ( V_4 ) ;
F_131 ( V_4 ) ;
F_86 (node, N_MEMORY) {
for ( V_36 = 0 ; V_36 < V_62 ; V_36 ++ ) {
enum V_87 V_88 ;
F_82 (lru) {
F_360 ( V_4 ,
V_60 , V_36 , V_88 ) ;
}
}
}
F_133 ( V_4 ) ;
F_195 ( V_4 ) ;
F_365 () ;
V_395 = F_38 ( & V_4 -> V_59 , V_33 ) -
F_38 ( & V_4 -> V_32 , V_33 ) ;
} while ( V_395 > 0 );
}
static inline bool F_368 ( struct V_1 * V_4 )
{
struct V_107 * V_396 ;
F_369 (pos, memcg->css.cgroup)
return true ;
return false ;
}
static inline bool F_370 ( struct V_1 * V_4 )
{
return V_4 -> V_130 && F_368 ( V_4 ) ;
}
static int F_371 ( struct V_1 * V_4 )
{
int V_397 = V_286 ;
struct V_107 * V_159 = V_4 -> V_15 . V_107 ;
if ( F_372 ( V_159 ) || ! F_362 ( & V_159 -> V_383 ) )
return - V_353 ;
F_367 () ;
while ( V_397 && F_38 ( & V_4 -> V_59 , V_33 ) > 0 ) {
int V_398 ;
if ( F_356 ( V_26 ) )
return - V_290 ;
V_398 = F_170 ( V_4 , V_323 ,
false ) ;
if ( ! V_398 ) {
V_397 -- ;
F_373 ( V_399 , V_400 / 10 ) ;
}
}
F_374 () ;
F_366 ( V_4 ) ;
return 0 ;
}
static int F_375 ( struct V_107 * V_108 , unsigned int V_401 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
int V_91 ;
if ( F_20 ( V_4 ) )
return - V_354 ;
F_23 ( & V_4 -> V_15 ) ;
V_91 = F_371 ( V_4 ) ;
F_31 ( & V_4 -> V_15 ) ;
return V_91 ;
}
static T_2 F_376 ( struct V_107 * V_108 , struct V_308 * V_309 )
{
return F_94 ( V_108 ) -> V_130 ;
}
static int F_377 ( struct V_107 * V_108 , struct V_308 * V_309 ,
T_2 V_68 )
{
int V_402 = 0 ;
struct V_1 * V_4 = F_94 ( V_108 ) ;
struct V_107 * V_50 = V_108 -> V_50 ;
struct V_1 * V_403 = NULL ;
if ( V_50 )
V_403 = F_94 ( V_50 ) ;
F_224 ( & V_404 ) ;
if ( V_4 -> V_130 == V_68 )
goto V_139;
if ( ( ! V_403 || ! V_403 -> V_130 ) &&
( V_68 == 1 || V_68 == 0 ) ) {
if ( ! F_368 ( V_4 ) )
V_4 -> V_130 = V_68 ;
else
V_402 = - V_353 ;
} else
V_402 = - V_354 ;
V_139:
F_222 ( & V_404 ) ;
return V_402 ;
}
static unsigned long F_378 ( struct V_1 * V_4 ,
enum V_66 V_67 )
{
struct V_1 * V_122 ;
long V_68 = 0 ;
F_152 (iter, memcg)
V_68 += F_65 ( V_122 , V_67 ) ;
if ( V_68 < 0 )
V_68 = 0 ;
return V_68 ;
}
static inline T_2 F_379 ( struct V_1 * V_4 , bool V_405 )
{
T_2 V_68 ;
if ( ! F_20 ( V_4 ) ) {
if ( ! V_405 )
return F_38 ( & V_4 -> V_59 , V_33 ) ;
else
return F_38 ( & V_4 -> V_158 , V_33 ) ;
}
V_68 = F_378 ( V_4 , V_81 ) ;
V_68 += F_378 ( V_4 , V_80 ) ;
if ( V_405 )
V_68 += F_378 ( V_4 , V_75 ) ;
return V_68 << V_155 ;
}
static T_8 F_380 ( struct V_107 * V_108 , struct V_308 * V_309 ,
struct V_406 * V_406 , char T_9 * V_407 ,
T_1 V_408 , T_10 * V_409 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
char V_410 [ 64 ] ;
T_2 V_68 ;
int V_336 , V_411 ;
enum V_412 type ;
type = F_381 ( V_309 -> V_235 ) ;
V_336 = F_382 ( V_309 -> V_235 ) ;
switch ( type ) {
case V_413 :
if ( V_336 == V_33 )
V_68 = F_379 ( V_4 , false ) ;
else
V_68 = F_38 ( & V_4 -> V_59 , V_336 ) ;
break;
case V_414 :
if ( V_336 == V_33 )
V_68 = F_379 ( V_4 , true ) ;
else
V_68 = F_38 ( & V_4 -> V_158 , V_336 ) ;
break;
case V_415 :
V_68 = F_38 ( & V_4 -> V_32 , V_336 ) ;
break;
default:
F_112 () ;
}
V_411 = F_383 ( V_410 , sizeof( V_410 ) , L_15 , ( unsigned long long ) V_68 ) ;
return F_384 ( V_407 , V_408 , V_409 , V_410 , V_411 ) ;
}
static int F_385 ( struct V_107 * V_108 , T_2 V_68 )
{
int V_91 = - V_354 ;
#ifdef F_386
struct V_1 * V_4 = F_94 ( V_108 ) ;
F_224 ( & V_404 ) ;
F_224 ( & V_345 ) ;
if ( ! V_4 -> V_6 && V_68 != V_416 ) {
if ( F_372 ( V_108 ) || F_370 ( V_4 ) ) {
V_91 = - V_353 ;
goto V_139;
}
V_91 = F_357 ( & V_4 -> V_32 , V_68 ) ;
F_41 ( V_91 ) ;
V_91 = F_269 ( V_4 ) ;
if ( V_91 ) {
F_357 ( & V_4 -> V_32 , V_416 ) ;
goto V_139;
}
F_387 ( & V_29 ) ;
F_2 ( V_4 ) ;
} else
V_91 = F_357 ( & V_4 -> V_32 , V_68 ) ;
V_139:
F_222 ( & V_345 ) ;
F_222 ( & V_404 ) ;
#endif
return V_91 ;
}
static int F_388 ( struct V_1 * V_4 )
{
int V_91 = 0 ;
struct V_1 * V_50 = F_58 ( V_4 ) ;
if ( ! V_50 )
goto V_139;
V_4 -> V_6 = V_50 -> V_6 ;
if ( ! F_4 ( V_4 ) )
goto V_139;
F_387 ( & V_29 ) ;
F_224 ( & V_345 ) ;
F_282 () ;
V_91 = F_269 ( V_4 ) ;
F_283 () ;
F_222 ( & V_345 ) ;
V_139:
return V_91 ;
}
static int F_389 ( struct V_107 * V_108 , struct V_308 * V_309 ,
const char * V_417 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
enum V_412 type ;
int V_336 ;
unsigned long long V_68 ;
int V_91 ;
type = F_381 ( V_309 -> V_235 ) ;
V_336 = F_382 ( V_309 -> V_235 ) ;
switch ( V_336 ) {
case V_178 :
if ( F_20 ( V_4 ) ) {
V_91 = - V_354 ;
break;
}
V_91 = F_390 ( V_417 , & V_68 ) ;
if ( V_91 )
break;
if ( type == V_413 )
V_91 = F_355 ( V_4 , V_68 ) ;
else if ( type == V_414 )
V_91 = F_358 ( V_4 , V_68 ) ;
else if ( type == V_415 )
V_91 = F_385 ( V_108 , V_68 ) ;
else
return - V_354 ;
break;
case V_418 :
V_91 = F_390 ( V_417 , & V_68 ) ;
if ( V_91 )
break;
if ( type == V_413 )
V_91 = F_391 ( & V_4 -> V_59 , V_68 ) ;
else
V_91 = - V_354 ;
break;
default:
V_91 = - V_354 ;
break;
}
return V_91 ;
}
static void F_392 ( struct V_1 * V_4 ,
unsigned long long * V_419 , unsigned long long * V_420 )
{
struct V_107 * V_107 ;
unsigned long long V_421 , V_422 , V_423 ;
V_421 = F_38 ( & V_4 -> V_59 , V_178 ) ;
V_422 = F_38 ( & V_4 -> V_158 , V_178 ) ;
V_107 = V_4 -> V_15 . V_107 ;
if ( ! V_4 -> V_130 )
goto V_139;
while ( V_107 -> V_50 ) {
V_107 = V_107 -> V_50 ;
V_4 = F_94 ( V_107 ) ;
if ( ! V_4 -> V_130 )
break;
V_423 = F_38 ( & V_4 -> V_59 , V_178 ) ;
V_421 = F_129 ( V_421 , V_423 ) ;
V_423 = F_38 ( & V_4 -> V_158 , V_178 ) ;
V_422 = F_129 ( V_422 , V_423 ) ;
}
V_139:
* V_419 = V_421 ;
* V_420 = V_422 ;
}
static int F_393 ( struct V_107 * V_108 , unsigned int V_401 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
int V_336 ;
enum V_412 type ;
type = F_381 ( V_401 ) ;
V_336 = F_382 ( V_401 ) ;
switch ( V_336 ) {
case V_424 :
if ( type == V_413 )
F_394 ( & V_4 -> V_59 ) ;
else if ( type == V_414 )
F_394 ( & V_4 -> V_158 ) ;
else if ( type == V_415 )
F_394 ( & V_4 -> V_32 ) ;
else
return - V_354 ;
break;
case V_179 :
if ( type == V_413 )
F_395 ( & V_4 -> V_59 ) ;
else if ( type == V_414 )
F_395 ( & V_4 -> V_158 ) ;
else if ( type == V_415 )
F_395 ( & V_4 -> V_32 ) ;
else
return - V_354 ;
break;
}
return 0 ;
}
static T_2 F_396 ( struct V_107 * V_159 ,
struct V_308 * V_309 )
{
return F_94 ( V_159 ) -> V_425 ;
}
static int F_397 ( struct V_107 * V_159 ,
struct V_308 * V_309 , T_2 V_68 )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
if ( V_68 >= ( 1 << V_426 ) )
return - V_354 ;
V_4 -> V_425 = V_68 ;
return 0 ;
}
static int F_397 ( struct V_107 * V_159 ,
struct V_308 * V_309 , T_2 V_68 )
{
return - V_427 ;
}
static int F_398 ( struct V_107 * V_108 , struct V_308 * V_309 ,
struct V_310 * V_311 )
{
int V_35 ;
unsigned long V_428 , V_429 , V_430 , V_431 ;
unsigned long V_432 ;
struct V_1 * V_4 = F_94 ( V_108 ) ;
V_428 = F_85 ( V_4 , V_433 ) ;
F_399 ( V_311 , L_16 , V_428 ) ;
F_86 (nid, N_MEMORY) {
V_432 = F_84 ( V_4 , V_35 , V_433 ) ;
F_399 ( V_311 , L_17 , V_35 , V_432 ) ;
}
F_400 ( V_311 , '\n' ) ;
V_429 = F_85 ( V_4 , V_209 ) ;
F_399 ( V_311 , L_18 , V_429 ) ;
F_86 (nid, N_MEMORY) {
V_432 = F_84 ( V_4 , V_35 ,
V_209 ) ;
F_399 ( V_311 , L_17 , V_35 , V_432 ) ;
}
F_400 ( V_311 , '\n' ) ;
V_430 = F_85 ( V_4 , V_210 ) ;
F_399 ( V_311 , L_19 , V_430 ) ;
F_86 (nid, N_MEMORY) {
V_432 = F_84 ( V_4 , V_35 ,
V_210 ) ;
F_399 ( V_311 , L_17 , V_35 , V_432 ) ;
}
F_400 ( V_311 , '\n' ) ;
V_431 = F_85 ( V_4 , F_83 ( V_434 ) ) ;
F_399 ( V_311 , L_20 , V_431 ) ;
F_86 (nid, N_MEMORY) {
V_432 = F_84 ( V_4 , V_35 ,
F_83 ( V_434 ) ) ;
F_399 ( V_311 , L_17 , V_35 , V_432 ) ;
}
F_400 ( V_311 , '\n' ) ;
return 0 ;
}
static inline void F_401 ( void )
{
F_402 ( F_403 ( V_183 ) != V_182 ) ;
}
static int F_404 ( struct V_107 * V_108 , struct V_308 * V_309 ,
struct V_310 * V_311 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
struct V_1 * V_435 ;
unsigned int V_177 ;
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
if ( V_177 == V_75 && ! V_157 )
continue;
F_399 ( V_311 , L_21 , V_181 [ V_177 ] ,
F_65 ( V_4 , V_177 ) * V_251 ) ;
}
for ( V_177 = 0 ; V_177 < V_259 ; V_177 ++ )
F_399 ( V_311 , L_22 , V_436 [ V_177 ] ,
F_73 ( V_4 , V_177 ) ) ;
for ( V_177 = 0 ; V_177 < V_182 ; V_177 ++ )
F_399 ( V_311 , L_22 , V_183 [ V_177 ] ,
F_85 ( V_4 , F_83 ( V_177 ) ) * V_251 ) ;
{
unsigned long long V_185 , V_420 ;
F_392 ( V_4 , & V_185 , & V_420 ) ;
F_399 ( V_311 , L_23 , V_185 ) ;
if ( V_157 )
F_399 ( V_311 , L_24 ,
V_420 ) ;
}
for ( V_177 = 0 ; V_177 < V_180 ; V_177 ++ ) {
long long V_68 = 0 ;
if ( V_177 == V_75 && ! V_157 )
continue;
F_152 (mi, memcg)
V_68 += F_65 ( V_435 , V_177 ) * V_251 ;
F_399 ( V_311 , L_25 , V_181 [ V_177 ] , V_68 ) ;
}
for ( V_177 = 0 ; V_177 < V_259 ; V_177 ++ ) {
unsigned long long V_68 = 0 ;
F_152 (mi, memcg)
V_68 += F_73 ( V_435 , V_177 ) ;
F_399 ( V_311 , L_26 ,
V_436 [ V_177 ] , V_68 ) ;
}
for ( V_177 = 0 ; V_177 < V_182 ; V_177 ++ ) {
unsigned long long V_68 = 0 ;
F_152 (mi, memcg)
V_68 += F_85 ( V_435 , F_83 ( V_177 ) ) * V_251 ;
F_399 ( V_311 , L_26 , V_183 [ V_177 ] , V_68 ) ;
}
#ifdef F_405
{
int V_35 , V_36 ;
struct V_34 * V_44 ;
struct V_437 * V_438 ;
unsigned long V_439 [ 2 ] = { 0 , 0 } ;
unsigned long V_440 [ 2 ] = { 0 , 0 } ;
F_406 (nid)
for ( V_36 = 0 ; V_36 < V_62 ; V_36 ++ ) {
V_44 = F_40 ( V_4 , V_35 , V_36 ) ;
V_438 = & V_44 -> V_86 . V_441 ;
V_439 [ 0 ] += V_438 -> V_439 [ 0 ] ;
V_439 [ 1 ] += V_438 -> V_439 [ 1 ] ;
V_440 [ 0 ] += V_438 -> V_440 [ 0 ] ;
V_440 [ 1 ] += V_438 -> V_440 [ 1 ] ;
}
F_399 ( V_311 , L_27 , V_439 [ 0 ] ) ;
F_399 ( V_311 , L_28 , V_439 [ 1 ] ) ;
F_399 ( V_311 , L_29 , V_440 [ 0 ] ) ;
F_399 ( V_311 , L_30 , V_440 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_407 ( struct V_107 * V_159 , struct V_308 * V_309 )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
return F_130 ( V_4 ) ;
}
static int F_408 ( struct V_107 * V_159 , struct V_308 * V_309 ,
T_2 V_68 )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
struct V_1 * V_50 ;
if ( V_68 > 100 )
return - V_354 ;
if ( V_159 -> V_50 == NULL )
return - V_354 ;
V_50 = F_94 ( V_159 -> V_50 ) ;
F_224 ( & V_404 ) ;
if ( ( V_50 -> V_130 ) || F_370 ( V_4 ) ) {
F_222 ( & V_404 ) ;
return - V_354 ;
}
V_4 -> V_161 = V_68 ;
F_222 ( & V_404 ) ;
return 0 ;
}
static void F_409 ( struct V_1 * V_4 , bool V_405 )
{
struct V_442 * V_443 ;
T_2 V_395 ;
int V_177 ;
F_24 () ;
if ( ! V_405 )
V_443 = F_97 ( V_4 -> V_444 . V_445 ) ;
else
V_443 = F_97 ( V_4 -> V_446 . V_445 ) ;
if ( ! V_443 )
goto V_166;
V_395 = F_379 ( V_4 , V_405 ) ;
V_177 = V_443 -> V_447 ;
for (; V_177 >= 0 && F_91 ( V_443 -> V_448 [ V_177 ] . V_449 > V_395 ) ; V_177 -- )
F_410 ( V_443 -> V_448 [ V_177 ] . V_450 , 1 ) ;
V_177 ++ ;
for (; V_177 < V_443 -> V_316 && F_91 ( V_443 -> V_448 [ V_177 ] . V_449 <= V_395 ) ; V_177 ++ )
F_410 ( V_443 -> V_448 [ V_177 ] . V_450 , 1 ) ;
V_443 -> V_447 = V_177 - 1 ;
V_166:
F_28 () ;
}
static void F_92 ( struct V_1 * V_4 )
{
while ( V_4 ) {
F_409 ( V_4 , false ) ;
if ( V_157 )
F_409 ( V_4 , true ) ;
V_4 = F_58 ( V_4 ) ;
}
}
static int F_411 ( const void * V_451 , const void * V_452 )
{
const struct F_92 * V_453 = V_451 ;
const struct F_92 * V_454 = V_452 ;
return V_453 -> V_449 - V_454 -> V_449 ;
}
static int F_412 ( struct V_1 * V_4 )
{
struct V_455 * V_456 ;
F_262 (ev, &memcg->oom_notify, list)
F_410 ( V_456 -> V_450 , 1 ) ;
return 0 ;
}
static void F_198 ( struct V_1 * V_4 )
{
struct V_1 * V_122 ;
F_152 (iter, memcg)
F_412 ( V_122 ) ;
}
static int F_413 ( struct V_107 * V_159 ,
struct V_308 * V_309 , struct V_457 * V_450 , const char * args )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
struct V_458 * V_444 ;
struct V_442 * V_333 ;
enum V_412 type = F_381 ( V_309 -> V_235 ) ;
T_2 V_449 , V_395 ;
int V_177 , V_316 , V_91 ;
V_91 = F_390 ( args , & V_449 ) ;
if ( V_91 )
return V_91 ;
F_224 ( & V_4 -> V_459 ) ;
if ( type == V_413 )
V_444 = & V_4 -> V_444 ;
else if ( type == V_414 )
V_444 = & V_4 -> V_446 ;
else
F_112 () ;
V_395 = F_379 ( V_4 , type == V_414 ) ;
if ( V_444 -> V_445 )
F_409 ( V_4 , type == V_414 ) ;
V_316 = V_444 -> V_445 ? V_444 -> V_445 -> V_316 + 1 : 1 ;
V_333 = F_291 ( sizeof( * V_333 ) + V_316 * sizeof( struct F_92 ) ,
V_323 ) ;
if ( ! V_333 ) {
V_91 = - V_289 ;
goto V_166;
}
V_333 -> V_316 = V_316 ;
if ( V_444 -> V_445 ) {
memcpy ( V_333 -> V_448 , V_444 -> V_445 -> V_448 , ( V_316 - 1 ) *
sizeof( struct F_92 ) ) ;
}
V_333 -> V_448 [ V_316 - 1 ] . V_450 = V_450 ;
V_333 -> V_448 [ V_316 - 1 ] . V_449 = V_449 ;
F_414 ( V_333 -> V_448 , V_316 , sizeof( struct F_92 ) ,
F_411 , NULL ) ;
V_333 -> V_447 = - 1 ;
for ( V_177 = 0 ; V_177 < V_316 ; V_177 ++ ) {
if ( V_333 -> V_448 [ V_177 ] . V_449 <= V_395 ) {
++ V_333 -> V_447 ;
} else
break;
}
F_277 ( V_444 -> V_460 ) ;
V_444 -> V_460 = V_444 -> V_445 ;
F_415 ( V_444 -> V_445 , V_333 ) ;
F_132 () ;
V_166:
F_222 ( & V_4 -> V_459 ) ;
return V_91 ;
}
static void F_416 ( struct V_107 * V_159 ,
struct V_308 * V_309 , struct V_457 * V_450 )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
struct V_458 * V_444 ;
struct V_442 * V_333 ;
enum V_412 type = F_381 ( V_309 -> V_235 ) ;
T_2 V_395 ;
int V_177 , V_461 , V_316 ;
F_224 ( & V_4 -> V_459 ) ;
if ( type == V_413 )
V_444 = & V_4 -> V_444 ;
else if ( type == V_414 )
V_444 = & V_4 -> V_446 ;
else
F_112 () ;
if ( ! V_444 -> V_445 )
goto V_166;
V_395 = F_379 ( V_4 , type == V_414 ) ;
F_409 ( V_4 , type == V_414 ) ;
V_316 = 0 ;
for ( V_177 = 0 ; V_177 < V_444 -> V_445 -> V_316 ; V_177 ++ ) {
if ( V_444 -> V_445 -> V_448 [ V_177 ] . V_450 != V_450 )
V_316 ++ ;
}
V_333 = V_444 -> V_460 ;
if ( ! V_316 ) {
F_277 ( V_333 ) ;
V_333 = NULL ;
goto V_462;
}
V_333 -> V_316 = V_316 ;
V_333 -> V_447 = - 1 ;
for ( V_177 = 0 , V_461 = 0 ; V_177 < V_444 -> V_445 -> V_316 ; V_177 ++ ) {
if ( V_444 -> V_445 -> V_448 [ V_177 ] . V_450 == V_450 )
continue;
V_333 -> V_448 [ V_461 ] = V_444 -> V_445 -> V_448 [ V_177 ] ;
if ( V_333 -> V_448 [ V_461 ] . V_449 <= V_395 ) {
++ V_333 -> V_447 ;
}
V_461 ++ ;
}
V_462:
V_444 -> V_460 = V_444 -> V_445 ;
if ( ! V_333 ) {
F_277 ( V_444 -> V_460 ) ;
V_444 -> V_460 = NULL ;
}
F_415 ( V_444 -> V_445 , V_333 ) ;
F_132 () ;
V_166:
F_222 ( & V_4 -> V_459 ) ;
}
static int F_417 ( struct V_107 * V_159 ,
struct V_308 * V_309 , struct V_457 * V_450 , const char * args )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
struct V_455 * V_401 ;
enum V_412 type = F_381 ( V_309 -> V_235 ) ;
F_22 ( type != V_463 ) ;
V_401 = F_291 ( sizeof( * V_401 ) , V_323 ) ;
if ( ! V_401 )
return - V_289 ;
F_55 ( & V_237 ) ;
V_401 -> V_450 = V_450 ;
F_268 ( & V_401 -> V_320 , & V_4 -> V_464 ) ;
if ( F_102 ( & V_4 -> V_221 ) )
F_410 ( V_450 , 1 ) ;
F_56 ( & V_237 ) ;
return 0 ;
}
static void F_418 ( struct V_107 * V_159 ,
struct V_308 * V_309 , struct V_457 * V_450 )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
struct V_455 * V_456 , * V_423 ;
enum V_412 type = F_381 ( V_309 -> V_235 ) ;
F_22 ( type != V_463 ) ;
F_55 ( & V_237 ) ;
F_419 (ev, tmp, &memcg->oom_notify, list) {
if ( V_456 -> V_450 == V_450 ) {
F_281 ( & V_456 -> V_320 ) ;
F_277 ( V_456 ) ;
}
}
F_56 ( & V_237 ) ;
}
static int F_420 ( struct V_107 * V_159 ,
struct V_308 * V_309 , struct V_465 * V_466 )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
V_466 -> V_467 ( V_466 , L_31 , V_4 -> V_239 ) ;
if ( F_102 ( & V_4 -> V_221 ) )
V_466 -> V_467 ( V_466 , L_32 , 1 ) ;
else
V_466 -> V_467 ( V_466 , L_32 , 0 ) ;
return 0 ;
}
static int F_421 ( struct V_107 * V_159 ,
struct V_308 * V_309 , T_2 V_68 )
{
struct V_1 * V_4 = F_94 ( V_159 ) ;
struct V_1 * V_50 ;
if ( ! V_159 -> V_50 || ! ( ( V_68 == 0 ) || ( V_68 == 1 ) ) )
return - V_354 ;
V_50 = F_94 ( V_159 -> V_50 ) ;
F_224 ( & V_404 ) ;
if ( ( V_50 -> V_130 ) || F_370 ( V_4 ) ) {
F_222 ( & V_404 ) ;
return - V_354 ;
}
V_4 -> V_239 = V_68 ;
if ( ! V_68 )
F_195 ( V_4 ) ;
F_222 ( & V_404 ) ;
return 0 ;
}
static int F_422 ( struct V_1 * V_4 , struct V_468 * V_469 )
{
int V_91 ;
V_4 -> V_31 = - 1 ;
V_91 = F_388 ( V_4 ) ;
if ( V_91 )
return V_91 ;
return F_423 ( V_4 , V_469 ) ;
}
static void F_424 ( struct V_1 * V_4 )
{
F_425 ( V_4 ) ;
}
static void F_426 ( struct V_1 * V_4 )
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
static int F_422 ( struct V_1 * V_4 , struct V_468 * V_469 )
{
return 0 ;
}
static void F_424 ( struct V_1 * V_4 )
{
}
static void F_426 ( struct V_1 * V_4 )
{
}
static int F_427 ( struct V_1 * V_4 , int V_60 )
{
struct V_3 * V_470 ;
struct V_34 * V_44 ;
int V_61 , V_423 = V_60 ;
if ( ! F_428 ( V_60 , V_471 ) )
V_423 = - 1 ;
V_470 = F_429 ( sizeof( * V_470 ) , V_323 , V_423 ) ;
if ( ! V_470 )
return 1 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_44 = & V_470 -> V_38 [ V_61 ] ;
F_430 ( & V_44 -> V_86 ) ;
V_44 -> V_53 = 0 ;
V_44 -> V_52 = false ;
V_44 -> V_4 = V_4 ;
}
V_4 -> V_37 [ V_60 ] = V_470 ;
return 0 ;
}
static void F_431 ( struct V_1 * V_4 , int V_60 )
{
F_277 ( V_4 -> V_37 [ V_60 ] ) ;
}
static struct V_1 * F_432 ( void )
{
struct V_1 * V_4 ;
T_1 V_316 = F_1 () ;
if ( V_316 < V_251 )
V_4 = F_276 ( V_316 , V_323 ) ;
else
V_4 = F_433 ( V_316 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_70 = F_434 ( struct V_472 ) ;
if ( ! V_4 -> V_70 )
goto V_473;
F_435 ( & V_4 -> V_72 ) ;
return V_4 ;
V_473:
if ( V_316 < V_251 )
F_277 ( V_4 ) ;
else
F_436 ( V_4 ) ;
return NULL ;
}
static void F_437 ( struct V_1 * V_4 )
{
int V_60 ;
T_1 V_316 = F_1 () ;
F_60 ( V_4 ) ;
F_438 ( & V_292 , & V_4 -> V_15 ) ;
F_61 (node)
F_431 ( V_4 , V_60 ) ;
F_439 ( V_4 -> V_70 ) ;
F_39 ( V_4 ) ;
if ( V_316 < V_251 )
F_277 ( V_4 ) ;
else
F_436 ( V_4 ) ;
}
struct V_1 * F_58 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_59 . V_50 )
return NULL ;
return F_231 ( V_4 -> V_59 . V_50 , V_59 ) ;
}
static void T_6 F_440 ( void )
{
struct V_474 * V_475 ;
struct V_40 * V_476 ;
int V_423 , V_60 , V_61 ;
F_61 (node) {
V_423 = V_60 ;
if ( ! F_428 ( V_60 , V_471 ) )
V_423 = - 1 ;
V_475 = F_429 ( sizeof( * V_475 ) , V_323 , V_423 ) ;
F_22 ( ! V_475 ) ;
V_41 . V_42 [ V_60 ] = V_475 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
V_476 = & V_475 -> V_43 [ V_61 ] ;
V_476 -> V_49 = V_477 ;
F_435 ( & V_476 -> V_57 ) ;
}
}
}
static struct V_13 * T_11
F_441 ( struct V_107 * V_108 )
{
struct V_1 * V_4 ;
long error = - V_289 ;
int V_60 ;
V_4 = F_432 () ;
if ( ! V_4 )
return F_442 ( error ) ;
F_61 (node)
if ( F_427 ( V_4 , V_60 ) )
goto V_478;
if ( V_108 -> V_50 == NULL ) {
V_17 = V_4 ;
F_443 ( & V_4 -> V_59 , NULL ) ;
F_443 ( & V_4 -> V_158 , NULL ) ;
F_443 ( & V_4 -> V_32 , NULL ) ;
}
V_4 -> V_215 = V_105 ;
F_197 ( & V_4 -> V_464 ) ;
V_4 -> V_425 = 0 ;
F_272 ( & V_4 -> V_459 ) ;
F_435 ( & V_4 -> V_172 ) ;
F_444 ( & V_4 -> V_16 ) ;
return & V_4 -> V_15 ;
V_478:
F_437 ( V_4 ) ;
return F_442 ( error ) ;
}
static int
F_445 ( struct V_107 * V_108 )
{
struct V_1 * V_4 , * V_50 ;
int error = 0 ;
if ( ! V_108 -> V_50 )
return 0 ;
F_224 ( & V_404 ) ;
V_4 = F_94 ( V_108 ) ;
V_50 = F_94 ( V_108 -> V_50 ) ;
V_4 -> V_130 = V_50 -> V_130 ;
V_4 -> V_239 = V_50 -> V_239 ;
V_4 -> V_161 = F_130 ( V_50 ) ;
if ( V_50 -> V_130 ) {
F_443 ( & V_4 -> V_59 , & V_50 -> V_59 ) ;
F_443 ( & V_4 -> V_158 , & V_50 -> V_158 ) ;
F_443 ( & V_4 -> V_32 , & V_50 -> V_32 ) ;
} else {
F_443 ( & V_4 -> V_59 , NULL ) ;
F_443 ( & V_4 -> V_158 , NULL ) ;
F_443 ( & V_4 -> V_32 , NULL ) ;
if ( V_50 != V_17 )
V_292 . V_479 = true ;
}
error = F_422 ( V_4 , & V_292 ) ;
F_222 ( & V_404 ) ;
return error ;
}
static void F_446 ( struct V_1 * V_4 )
{
struct V_1 * V_50 = V_4 ;
while ( ( V_50 = F_58 ( V_50 ) ) )
F_100 ( V_50 ) ;
if ( ! V_17 -> V_130 )
F_100 ( V_17 ) ;
}
static void F_447 ( struct V_107 * V_108 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
F_426 ( V_4 ) ;
F_446 ( V_4 ) ;
F_366 ( V_4 ) ;
F_298 ( V_4 ) ;
F_448 ( & V_4 -> V_16 ) ;
}
static void F_449 ( struct V_107 * V_108 )
{
struct V_1 * V_4 = F_94 ( V_108 ) ;
F_424 ( V_4 ) ;
F_437 ( V_4 ) ;
}
static int F_450 ( unsigned long V_71 )
{
int V_91 = 0 ;
int V_480 = V_481 ;
struct V_1 * V_4 = V_10 . V_165 ;
if ( F_20 ( V_4 ) ) {
V_10 . V_482 += V_71 ;
return V_91 ;
}
if ( V_71 > 1 ) {
struct V_272 * V_253 ;
if ( F_229 ( & V_4 -> V_59 , V_251 * V_71 , & V_253 ) )
goto V_483;
if ( V_157 && F_229 ( & V_4 -> V_158 ,
V_251 * V_71 , & V_253 ) ) {
F_208 ( & V_4 -> V_59 , V_251 * V_71 ) ;
goto V_483;
}
V_10 . V_482 += V_71 ;
return V_91 ;
}
V_483:
while ( V_71 -- ) {
if ( F_356 ( V_26 ) ) {
V_91 = - V_290 ;
break;
}
if ( ! V_480 -- ) {
V_480 = V_481 ;
F_365 () ;
}
V_91 = F_233 ( NULL ,
V_323 , 1 , & V_4 , false ) ;
if ( V_91 )
return V_91 ;
V_10 . V_482 ++ ;
}
return V_91 ;
}
static struct V_39 * F_451 ( struct V_484 * V_485 ,
unsigned long V_486 , T_12 V_487 )
{
struct V_39 * V_39 = F_452 ( V_485 , V_486 , V_487 ) ;
if ( ! V_39 || ! F_312 ( V_39 ) )
return NULL ;
if ( F_311 ( V_39 ) ) {
if ( ! F_13 () )
return NULL ;
} else if ( ! F_14 () )
return NULL ;
if ( ! F_315 ( V_39 ) )
return NULL ;
return V_39 ;
}
static struct V_39 * F_453 ( struct V_484 * V_485 ,
unsigned long V_486 , T_12 V_487 , T_7 * V_372 )
{
struct V_39 * V_39 = NULL ;
T_7 V_293 = F_454 ( V_487 ) ;
if ( ! F_13 () || F_455 ( V_293 ) )
return NULL ;
V_39 = F_456 ( F_457 ( V_293 ) , V_293 . V_68 ) ;
if ( V_157 )
V_372 -> V_68 = V_293 . V_68 ;
return V_39 ;
}
static struct V_39 * F_453 ( struct V_484 * V_485 ,
unsigned long V_486 , T_12 V_487 , T_7 * V_372 )
{
return NULL ;
}
static struct V_39 * F_458 ( struct V_484 * V_485 ,
unsigned long V_486 , T_12 V_487 , T_7 * V_372 )
{
struct V_39 * V_39 = NULL ;
struct V_488 * V_357 ;
T_13 V_489 ;
if ( ! V_485 -> V_490 )
return NULL ;
if ( ! F_14 () )
return NULL ;
V_357 = V_485 -> V_490 -> V_491 ;
if ( F_459 ( V_487 ) )
V_489 = F_460 ( V_485 , V_486 ) ;
else
V_489 = F_461 ( V_487 ) ;
V_39 = F_456 ( V_357 , V_489 ) ;
#ifdef F_462
if ( F_463 ( V_39 ) ) {
T_7 V_405 = F_464 ( V_39 ) ;
if ( V_157 )
* V_372 = V_405 ;
V_39 = F_456 ( F_457 ( V_405 ) , V_405 . V_68 ) ;
}
#endif
return V_39 ;
}
static enum V_492 F_465 ( struct V_484 * V_485 ,
unsigned long V_486 , T_12 V_487 , union V_493 * V_94 )
{
struct V_39 * V_39 = NULL ;
struct V_144 * V_145 ;
enum V_492 V_91 = V_494 ;
T_7 V_293 = { . V_68 = 0 } ;
if ( F_466 ( V_487 ) )
V_39 = F_451 ( V_485 , V_486 , V_487 ) ;
else if ( F_467 ( V_487 ) )
V_39 = F_453 ( V_485 , V_486 , V_487 , & V_293 ) ;
else if ( F_459 ( V_487 ) || F_468 ( V_487 ) )
V_39 = F_458 ( V_485 , V_486 , V_487 , & V_293 ) ;
if ( ! V_39 && ! V_293 . V_68 )
return V_91 ;
if ( V_39 ) {
V_145 = F_115 ( V_39 ) ;
if ( F_117 ( V_145 ) && V_145 -> V_1 == V_10 . V_164 ) {
V_91 = V_495 ;
if ( V_94 )
V_94 -> V_39 = V_39 ;
}
if ( ! V_91 || ! V_94 )
F_321 ( V_39 ) ;
}
if ( V_293 . V_68 && ! V_91 &&
F_343 ( & V_10 . V_164 -> V_15 ) == F_245 ( V_293 ) ) {
V_91 = V_496 ;
if ( V_94 )
V_94 -> V_293 = V_293 ;
}
return V_91 ;
}
static enum V_492 F_469 ( struct V_484 * V_485 ,
unsigned long V_486 , T_14 V_497 , union V_493 * V_94 )
{
struct V_39 * V_39 = NULL ;
struct V_144 * V_145 ;
enum V_492 V_91 = V_494 ;
V_39 = F_470 ( V_497 ) ;
F_41 ( ! V_39 || ! F_471 ( V_39 ) ) ;
if ( ! F_13 () )
return V_91 ;
V_145 = F_115 ( V_39 ) ;
if ( F_117 ( V_145 ) && V_145 -> V_1 == V_10 . V_164 ) {
V_91 = V_495 ;
if ( V_94 ) {
F_472 ( V_39 ) ;
V_94 -> V_39 = V_39 ;
}
}
return V_91 ;
}
static inline enum V_492 F_469 ( struct V_484 * V_485 ,
unsigned long V_486 , T_14 V_497 , union V_493 * V_94 )
{
return V_494 ;
}
static int F_473 ( T_14 * V_497 ,
unsigned long V_486 , unsigned long V_498 ,
struct V_499 * V_500 )
{
struct V_484 * V_485 = V_500 -> V_235 ;
T_12 * V_501 ;
T_15 * V_502 ;
if ( F_474 ( V_497 , V_485 ) == 1 ) {
if ( F_469 ( V_485 , V_486 , * V_497 , NULL ) == V_495 )
V_10 . V_482 += V_351 ;
F_56 ( & V_485 -> V_503 -> V_504 ) ;
return 0 ;
}
if ( F_475 ( V_497 ) )
return 0 ;
V_501 = F_476 ( V_485 -> V_503 , V_497 , V_486 , & V_502 ) ;
for (; V_486 != V_498 ; V_501 ++ , V_486 += V_251 )
if ( F_465 ( V_485 , V_486 , * V_501 , NULL ) )
V_10 . V_482 ++ ;
F_477 ( V_501 - 1 , V_502 ) ;
F_365 () ;
return 0 ;
}
static unsigned long F_478 ( struct V_111 * V_112 )
{
unsigned long V_482 ;
struct V_484 * V_485 ;
F_479 ( & V_112 -> V_505 ) ;
for ( V_485 = V_112 -> V_506 ; V_485 ; V_485 = V_485 -> V_507 ) {
struct V_499 V_508 = {
. V_509 = F_473 ,
. V_112 = V_112 ,
. V_235 = V_485 ,
} ;
if ( F_480 ( V_485 ) )
continue;
F_481 ( V_485 -> V_510 , V_485 -> V_511 ,
& V_508 ) ;
}
F_482 ( & V_112 -> V_505 ) ;
V_482 = V_10 . V_482 ;
V_10 . V_482 = 0 ;
return V_482 ;
}
static int F_483 ( struct V_111 * V_112 )
{
unsigned long V_482 = F_478 ( V_112 ) ;
F_41 ( V_10 . V_167 ) ;
V_10 . V_167 = V_26 ;
return F_450 ( V_482 ) ;
}
static void F_484 ( void )
{
struct V_1 * V_164 = V_10 . V_164 ;
struct V_1 * V_165 = V_10 . V_165 ;
int V_177 ;
if ( V_10 . V_482 ) {
F_235 ( V_10 . V_165 , V_10 . V_482 ) ;
V_10 . V_482 = 0 ;
}
if ( V_10 . V_512 ) {
F_235 ( V_10 . V_164 , V_10 . V_512 ) ;
V_10 . V_512 = 0 ;
}
if ( V_10 . V_513 ) {
if ( ! F_20 ( V_10 . V_164 ) )
F_208 ( & V_10 . V_164 -> V_158 ,
V_251 * V_10 . V_513 ) ;
for ( V_177 = 0 ; V_177 < V_10 . V_513 ; V_177 ++ )
F_31 ( & V_10 . V_164 -> V_15 ) ;
if ( ! F_20 ( V_10 . V_165 ) ) {
F_208 ( & V_10 . V_165 -> V_59 ,
V_251 * V_10 . V_513 ) ;
}
V_10 . V_513 = 0 ;
}
F_195 ( V_164 ) ;
F_195 ( V_165 ) ;
F_485 ( & V_10 . V_169 ) ;
}
static void F_486 ( void )
{
struct V_1 * V_164 = V_10 . V_164 ;
V_10 . V_167 = NULL ;
F_484 () ;
F_55 ( & V_10 . V_57 ) ;
V_10 . V_164 = NULL ;
V_10 . V_165 = NULL ;
F_56 ( & V_10 . V_57 ) ;
F_133 ( V_164 ) ;
}
static int F_487 ( struct V_107 * V_107 ,
struct V_514 * V_515 )
{
struct V_110 * V_48 = F_488 ( V_515 ) ;
int V_91 = 0 ;
struct V_1 * V_4 = F_94 ( V_107 ) ;
unsigned long V_425 ;
V_425 = V_4 -> V_425 ;
if ( V_425 ) {
struct V_111 * V_112 ;
struct V_1 * V_164 = F_25 ( V_48 ) ;
F_41 ( V_164 == V_4 ) ;
V_112 = F_489 ( V_48 ) ;
if ( ! V_112 )
return 0 ;
if ( V_112 -> V_113 == V_48 ) {
F_41 ( V_10 . V_164 ) ;
F_41 ( V_10 . V_165 ) ;
F_41 ( V_10 . V_482 ) ;
F_41 ( V_10 . V_512 ) ;
F_41 ( V_10 . V_513 ) ;
F_131 ( V_164 ) ;
F_55 ( & V_10 . V_57 ) ;
V_10 . V_164 = V_164 ;
V_10 . V_165 = V_4 ;
V_10 . V_11 = V_425 ;
F_56 ( & V_10 . V_57 ) ;
V_91 = F_483 ( V_112 ) ;
if ( V_91 )
F_486 () ;
}
F_490 ( V_112 ) ;
}
return V_91 ;
}
static void F_491 ( struct V_107 * V_107 ,
struct V_514 * V_515 )
{
F_486 () ;
}
static int F_492 ( T_14 * V_497 ,
unsigned long V_486 , unsigned long V_498 ,
struct V_499 * V_500 )
{
int V_91 = 0 ;
struct V_484 * V_485 = V_500 -> V_235 ;
T_12 * V_501 ;
T_15 * V_502 ;
enum V_492 V_516 ;
union V_493 V_94 ;
struct V_39 * V_39 ;
struct V_144 * V_145 ;
if ( F_474 ( V_497 , V_485 ) == 1 ) {
if ( V_10 . V_482 < V_351 ) {
F_56 ( & V_485 -> V_503 -> V_504 ) ;
return 0 ;
}
V_516 = F_469 ( V_485 , V_486 , * V_497 , & V_94 ) ;
if ( V_516 == V_495 ) {
V_39 = V_94 . V_39 ;
if ( ! F_316 ( V_39 ) ) {
V_145 = F_115 ( V_39 ) ;
if ( ! F_310 ( V_39 , V_351 ,
V_145 , V_10 . V_164 , V_10 . V_165 ) ) {
V_10 . V_482 -= V_351 ;
V_10 . V_512 += V_351 ;
}
F_320 ( V_39 ) ;
}
F_321 ( V_39 ) ;
}
F_56 ( & V_485 -> V_503 -> V_504 ) ;
return 0 ;
}
if ( F_475 ( V_497 ) )
return 0 ;
V_64:
V_501 = F_476 ( V_485 -> V_503 , V_497 , V_486 , & V_502 ) ;
for (; V_486 != V_498 ; V_486 += V_251 ) {
T_12 V_487 = * ( V_501 ++ ) ;
T_7 V_293 ;
if ( ! V_10 . V_482 )
break;
switch ( F_465 ( V_485 , V_486 , V_487 , & V_94 ) ) {
case V_495 :
V_39 = V_94 . V_39 ;
if ( F_316 ( V_39 ) )
goto V_356;
V_145 = F_115 ( V_39 ) ;
if ( ! F_310 ( V_39 , 1 , V_145 ,
V_10 . V_164 , V_10 . V_165 ) ) {
V_10 . V_482 -- ;
V_10 . V_512 ++ ;
}
F_320 ( V_39 ) ;
V_356:
F_321 ( V_39 ) ;
break;
case V_496 :
V_293 = V_94 . V_293 ;
if ( ! F_344 ( V_293 , V_10 . V_164 , V_10 . V_165 ) ) {
V_10 . V_482 -- ;
V_10 . V_513 ++ ;
}
break;
default:
break;
}
}
F_477 ( V_501 - 1 , V_502 ) ;
F_365 () ;
if ( V_486 != V_498 ) {
V_91 = F_450 ( 1 ) ;
if ( ! V_91 )
goto V_64;
}
return V_91 ;
}
static void F_493 ( struct V_111 * V_112 )
{
struct V_484 * V_485 ;
F_367 () ;
V_64:
if ( F_91 ( ! F_494 ( & V_112 -> V_505 ) ) ) {
F_484 () ;
F_365 () ;
goto V_64;
}
for ( V_485 = V_112 -> V_506 ; V_485 ; V_485 = V_485 -> V_507 ) {
int V_91 ;
struct V_499 V_517 = {
. V_509 = F_492 ,
. V_112 = V_112 ,
. V_235 = V_485 ,
} ;
if ( F_480 ( V_485 ) )
continue;
V_91 = F_481 ( V_485 -> V_510 , V_485 -> V_511 ,
& V_517 ) ;
if ( V_91 )
break;
}
F_482 ( & V_112 -> V_505 ) ;
}
static void F_495 ( struct V_107 * V_108 ,
struct V_514 * V_515 )
{
struct V_110 * V_48 = F_488 ( V_515 ) ;
struct V_111 * V_112 = F_489 ( V_48 ) ;
if ( V_112 ) {
if ( V_10 . V_165 )
F_493 ( V_112 ) ;
F_490 ( V_112 ) ;
}
if ( V_10 . V_165 )
F_486 () ;
}
static int F_487 ( struct V_107 * V_107 ,
struct V_514 * V_515 )
{
return 0 ;
}
static void F_491 ( struct V_107 * V_107 ,
struct V_514 * V_515 )
{
}
static void F_495 ( struct V_107 * V_108 ,
struct V_514 * V_515 )
{
}
static void F_496 ( struct V_107 * V_114 )
{
if ( F_497 ( V_114 ) )
F_94 ( V_114 ) -> V_130 = true ;
}
static int T_6 F_498 ( char * V_14 )
{
if ( ! strcmp ( V_14 , L_33 ) )
V_518 = 1 ;
else if ( ! strcmp ( V_14 , L_34 ) )
V_518 = 0 ;
return 1 ;
}
static void T_6 F_499 ( void )
{
F_30 ( F_500 ( & V_292 , V_519 ) ) ;
}
static void T_6 F_501 ( void )
{
if ( ! F_106 () && V_518 ) {
V_157 = 1 ;
F_499 () ;
}
}
static void T_6 F_501 ( void )
{
}
static int T_6 F_502 ( void )
{
F_503 ( F_226 , 0 ) ;
F_501 () ;
F_440 () ;
F_211 () ;
return 0 ;
}
