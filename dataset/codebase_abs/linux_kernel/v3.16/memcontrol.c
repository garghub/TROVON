static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_3 , & V_2 -> V_4 ) ;
}
static bool F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_3 , & V_2 -> V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 () ;
if ( F_4 ( V_3 , & V_2 -> V_4 ) )
F_2 ( V_5 , & V_2 -> V_4 ) ;
}
static bool F_7 ( struct V_1 * V_2 )
{
return F_8 ( V_5 ,
& V_2 -> V_4 ) ;
}
static bool F_9 ( void )
{
return F_4 ( V_6 , & V_7 . V_8 ) ;
}
static bool F_10 ( void )
{
return F_4 ( V_9 , & V_7 . V_8 ) ;
}
struct V_1 * F_11 ( struct V_10 * V_11 )
{
return V_11 ? F_12 ( V_11 , struct V_1 , V_12 ) : NULL ;
}
struct V_13 * F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 )
V_2 = V_14 ;
return & V_2 -> V_13 ;
}
struct V_10 * F_14 ( struct V_13 * V_15 )
{
return & F_12 ( V_15 , struct V_1 , V_13 ) -> V_12 ;
}
static inline bool F_15 ( struct V_1 * V_2 )
{
return ( V_2 == V_14 ) ;
}
static inline unsigned short F_16 ( struct V_1 * V_2 )
{
return V_2 -> V_12 . V_16 ;
}
static inline struct V_1 * F_17 ( unsigned short V_16 )
{
struct V_10 * V_12 ;
V_12 = F_18 ( V_16 , & V_17 ) ;
return F_11 ( V_12 ) ;
}
void F_19 ( struct V_18 * V_19 )
{
if ( V_20 ) {
struct V_1 * V_2 ;
struct V_21 * V_21 ;
F_20 ( ! V_19 -> V_22 -> V_23 ) ;
if ( V_19 -> V_24 ) {
F_20 ( F_15 ( V_19 -> V_24 -> V_2 ) ) ;
F_21 ( & V_19 -> V_24 -> V_2 -> V_12 ) ;
return;
}
F_22 () ;
V_2 = F_23 ( V_25 ) ;
V_21 = V_19 -> V_22 -> V_23 ( V_2 ) ;
if ( ! F_15 ( V_2 ) &&
F_24 ( V_21 ) &&
F_25 ( & V_2 -> V_12 ) ) {
V_19 -> V_24 = V_21 ;
}
F_26 () ;
}
}
void F_27 ( struct V_18 * V_19 )
{
if ( V_20 && V_19 -> V_24 ) {
struct V_1 * V_2 ;
F_28 ( ! V_19 -> V_24 -> V_2 ) ;
V_2 = V_19 -> V_24 -> V_2 ;
F_29 ( & V_19 -> V_24 -> V_2 -> V_12 ) ;
}
}
struct V_21 * F_30 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_15 ( V_2 ) )
return NULL ;
return & V_2 -> V_26 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( ! F_32 ( & V_2 -> V_26 ) )
return;
F_33 ( & V_27 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
}
static void F_34 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) ) {
F_33 ( & V_28 ) ;
F_35 ( & V_29 , V_2 -> V_30 ) ;
}
F_28 ( F_36 ( & V_2 -> V_31 , V_32 ) != 0 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static void F_37 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_34 ( V_2 ) ;
}
static struct V_33 *
F_38 ( struct V_1 * V_2 , struct V_34 * V_34 )
{
int V_35 = F_39 ( V_34 ) ;
int V_36 = F_40 ( V_34 ) ;
return & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
}
struct V_10 * F_41 ( struct V_1 * V_2 )
{
return & V_2 -> V_12 ;
}
static struct V_33 *
F_42 ( struct V_1 * V_2 , struct V_39 * V_39 )
{
int V_35 = F_43 ( V_39 ) ;
int V_36 = F_44 ( V_39 ) ;
return & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
}
static struct V_40 *
F_45 ( int V_35 , int V_36 )
{
return & V_41 . V_42 [ V_35 ] -> V_43 [ V_36 ] ;
}
static struct V_40 *
F_46 ( struct V_39 * V_39 )
{
int V_35 = F_43 ( V_39 ) ;
int V_36 = F_44 ( V_39 ) ;
return & V_41 . V_42 [ V_35 ] -> V_43 [ V_36 ] ;
}
static void F_47 ( struct V_33 * V_44 ,
struct V_40 * V_45 ,
unsigned long long V_46 )
{
struct V_47 * * V_48 = & V_45 -> V_49 . V_47 ;
struct V_47 * V_50 = NULL ;
struct V_33 * V_51 ;
if ( V_44 -> V_52 )
return;
V_44 -> V_53 = V_46 ;
if ( ! V_44 -> V_53 )
return;
while ( * V_48 ) {
V_50 = * V_48 ;
V_51 = F_48 ( V_50 , struct V_33 ,
V_54 ) ;
if ( V_44 -> V_53 < V_51 -> V_53 )
V_48 = & ( * V_48 ) -> V_55 ;
else if ( V_44 -> V_53 >= V_51 -> V_53 )
V_48 = & ( * V_48 ) -> V_56 ;
}
F_49 ( & V_44 -> V_54 , V_50 , V_48 ) ;
F_50 ( & V_44 -> V_54 , & V_45 -> V_49 ) ;
V_44 -> V_52 = true ;
}
static void F_51 ( struct V_33 * V_44 ,
struct V_40 * V_45 )
{
if ( ! V_44 -> V_52 )
return;
F_52 ( & V_44 -> V_54 , & V_45 -> V_49 ) ;
V_44 -> V_52 = false ;
}
static void F_53 ( struct V_33 * V_44 ,
struct V_40 * V_45 )
{
F_54 ( & V_45 -> V_57 ) ;
F_51 ( V_44 , V_45 ) ;
F_55 ( & V_45 -> V_57 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_39 * V_39 )
{
unsigned long long V_58 ;
struct V_33 * V_44 ;
struct V_40 * V_45 ;
V_45 = F_46 ( V_39 ) ;
for (; V_2 ; V_2 = F_57 ( V_2 ) ) {
V_44 = F_42 ( V_2 , V_39 ) ;
V_58 = F_58 ( & V_2 -> V_59 ) ;
if ( V_58 || V_44 -> V_52 ) {
F_54 ( & V_45 -> V_57 ) ;
if ( V_44 -> V_52 )
F_51 ( V_44 , V_45 ) ;
F_47 ( V_44 , V_45 , V_58 ) ;
F_55 ( & V_45 -> V_57 ) ;
}
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_40 * V_45 ;
struct V_33 * V_44 ;
int V_35 , V_36 ;
F_60 (nid) {
for ( V_36 = 0 ; V_36 < V_60 ; V_36 ++ ) {
V_44 = & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
V_45 = F_45 ( V_35 , V_36 ) ;
F_53 ( V_44 , V_45 ) ;
}
}
}
static struct V_33 *
F_61 ( struct V_40 * V_45 )
{
struct V_47 * V_61 = NULL ;
struct V_33 * V_44 ;
V_62:
V_44 = NULL ;
V_61 = F_62 ( & V_45 -> V_49 ) ;
if ( ! V_61 )
goto V_63;
V_44 = F_48 ( V_61 , struct V_33 , V_54 ) ;
F_51 ( V_44 , V_45 ) ;
if ( ! F_58 ( & V_44 -> V_2 -> V_59 ) ||
! F_25 ( & V_44 -> V_2 -> V_12 ) )
goto V_62;
V_63:
return V_44 ;
}
static struct V_33 *
F_63 ( struct V_40 * V_45 )
{
struct V_33 * V_44 ;
F_54 ( & V_45 -> V_57 ) ;
V_44 = F_61 ( V_45 ) ;
F_55 ( & V_45 -> V_57 ) ;
return V_44 ;
}
static long F_64 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
long V_66 = 0 ;
int V_67 ;
F_65 () ;
F_66 (cpu)
V_66 += F_67 ( V_2 -> V_68 -> V_69 [ V_65 ] , V_67 ) ;
#ifdef F_68
F_54 ( & V_2 -> V_70 ) ;
V_66 += V_2 -> V_71 . V_69 [ V_65 ] ;
F_55 ( & V_2 -> V_70 ) ;
#endif
F_69 () ;
return V_66 ;
}
static void F_70 ( struct V_1 * V_2 ,
bool V_72 )
{
int V_66 = ( V_72 ) ? 1 : - 1 ;
F_71 ( V_2 -> V_68 -> V_69 [ V_73 ] , V_66 ) ;
}
static unsigned long F_72 ( struct V_1 * V_2 ,
enum V_74 V_65 )
{
unsigned long V_66 = 0 ;
int V_67 ;
F_65 () ;
F_66 (cpu)
V_66 += F_67 ( V_2 -> V_68 -> V_75 [ V_65 ] , V_67 ) ;
#ifdef F_68
F_54 ( & V_2 -> V_70 ) ;
V_66 += V_2 -> V_71 . V_75 [ V_65 ] ;
F_55 ( & V_2 -> V_70 ) ;
#endif
F_69 () ;
return V_66 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_39 * V_39 ,
bool V_76 , int V_77 )
{
if ( V_76 )
F_74 ( V_2 -> V_68 -> V_69 [ V_78 ] ,
V_77 ) ;
else
F_74 ( V_2 -> V_68 -> V_69 [ V_79 ] ,
V_77 ) ;
if ( F_75 ( V_39 ) )
F_74 ( V_2 -> V_68 -> V_69 [ V_80 ] ,
V_77 ) ;
if ( V_77 > 0 )
F_76 ( V_2 -> V_68 -> V_75 [ V_81 ] ) ;
else {
F_76 ( V_2 -> V_68 -> V_75 [ V_82 ] ) ;
V_77 = - V_77 ;
}
F_74 ( V_2 -> V_68 -> V_83 , V_77 ) ;
}
unsigned long F_77 ( struct V_84 * V_84 , enum V_85 V_86 )
{
struct V_33 * V_44 ;
V_44 = F_12 ( V_84 , struct V_33 , V_84 ) ;
return V_44 -> V_87 [ V_86 ] ;
}
static unsigned long F_78 ( struct V_1 * V_2 ,
int V_35 ,
unsigned int V_88 )
{
unsigned long V_89 = 0 ;
int V_36 ;
F_79 ( ( unsigned ) V_35 >= V_90 ) ;
for ( V_36 = 0 ; V_36 < V_60 ; V_36 ++ ) {
struct V_33 * V_44 ;
enum V_85 V_86 ;
F_80 (lru) {
if ( ! ( F_81 ( V_86 ) & V_88 ) )
continue;
V_44 = & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
V_89 += V_44 -> V_87 [ V_86 ] ;
}
}
return V_89 ;
}
static unsigned long F_82 ( struct V_1 * V_2 ,
unsigned int V_88 )
{
unsigned long V_89 = 0 ;
int V_35 ;
F_83 (nid, N_MEMORY)
V_89 += F_78 ( V_2 , V_35 , V_88 ) ;
return V_89 ;
}
static bool F_84 ( struct V_1 * V_2 ,
enum V_91 V_92 )
{
unsigned long V_66 , V_93 ;
V_66 = F_85 ( V_2 -> V_68 -> V_83 ) ;
V_93 = F_85 ( V_2 -> V_68 -> V_94 [ V_92 ] ) ;
if ( ( long ) V_93 - ( long ) V_66 < 0 ) {
switch ( V_92 ) {
case V_95 :
V_93 = V_66 + V_96 ;
break;
case V_97 :
V_93 = V_66 + V_98 ;
break;
case V_99 :
V_93 = V_66 + V_100 ;
break;
default:
break;
}
F_86 ( V_2 -> V_68 -> V_94 [ V_92 ] , V_93 ) ;
return true ;
}
return false ;
}
static void F_87 ( struct V_1 * V_2 , struct V_39 * V_39 )
{
F_88 () ;
if ( F_89 ( F_84 ( V_2 ,
V_95 ) ) ) {
bool V_101 ;
bool T_1 V_102 ;
V_101 = F_84 ( V_2 ,
V_97 ) ;
#if V_103 > 1
T_1 = F_84 ( V_2 ,
V_99 ) ;
#endif
F_90 () ;
F_91 ( V_2 ) ;
if ( F_89 ( V_101 ) )
F_56 ( V_2 , V_39 ) ;
#if V_103 > 1
if ( F_89 ( T_1 ) )
F_92 ( & V_2 -> V_104 ) ;
#endif
} else
F_90 () ;
}
struct V_1 * F_23 ( struct V_105 * V_48 )
{
if ( F_89 ( ! V_48 ) )
return NULL ;
return F_11 ( F_93 ( V_48 , V_106 ) ) ;
}
static struct V_1 * F_94 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = NULL ;
F_22 () ;
do {
if ( F_89 ( ! V_108 ) )
V_2 = V_14 ;
else {
V_2 = F_23 ( F_95 ( V_108 -> V_109 ) ) ;
if ( F_89 ( ! V_2 ) )
V_2 = V_14 ;
}
} while ( ! F_25 ( & V_2 -> V_12 ) );
F_26 () ;
return V_2 ;
}
static struct V_1 * F_96 ( struct V_1 * V_110 ,
struct V_1 * V_111 )
{
struct V_10 * V_112 , * V_113 ;
V_112 = V_111 ? & V_111 -> V_12 : NULL ;
V_114:
V_113 = F_97 ( V_112 , & V_110 -> V_12 ) ;
if ( V_113 ) {
if ( ( V_113 == & V_110 -> V_12 ) ||
( ( V_113 -> V_115 & V_116 ) &&
F_25 ( V_113 ) ) )
return F_11 ( V_113 ) ;
V_112 = V_113 ;
goto V_114;
}
return NULL ;
}
static void F_98 ( struct V_1 * V_110 )
{
F_92 ( & V_110 -> V_117 ) ;
}
static struct V_1 *
F_99 ( struct V_118 * V_119 ,
struct V_1 * V_110 ,
int * V_120 )
{
struct V_1 * V_121 = NULL ;
* V_120 = F_100 ( & V_110 -> V_117 ) ;
if ( V_119 -> V_122 == * V_120 ) {
F_101 () ;
V_121 = V_119 -> V_111 ;
if ( V_121 && V_121 != V_110 &&
! F_25 ( & V_121 -> V_12 ) )
V_121 = NULL ;
}
return V_121 ;
}
static void F_102 ( struct V_118 * V_119 ,
struct V_1 * V_111 ,
struct V_1 * V_123 ,
struct V_1 * V_110 ,
int V_120 )
{
if ( V_111 && V_111 != V_110 )
F_29 ( & V_111 -> V_12 ) ;
V_119 -> V_111 = V_123 ;
F_6 () ;
V_119 -> V_122 = V_120 ;
}
struct V_1 * F_103 ( struct V_1 * V_110 ,
struct V_1 * V_124 ,
struct V_125 * V_126 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_111 = NULL ;
if ( F_104 () )
return NULL ;
if ( ! V_110 )
V_110 = V_14 ;
if ( V_124 && ! V_126 )
V_111 = V_124 ;
if ( ! V_110 -> V_127 && V_110 != V_14 ) {
if ( V_124 )
goto V_128;
return V_110 ;
}
F_22 () ;
while ( ! V_2 ) {
struct V_118 * V_129 ( V_119 ) ;
int V_129 ( V_130 ) ;
if ( V_126 ) {
struct V_33 * V_44 ;
V_44 = F_38 ( V_110 , V_126 -> V_34 ) ;
V_119 = & V_44 -> V_131 [ V_126 -> V_132 ] ;
if ( V_124 && V_126 -> V_133 != V_119 -> V_133 ) {
V_119 -> V_111 = NULL ;
goto V_134;
}
V_111 = F_99 ( V_119 , V_110 , & V_130 ) ;
}
V_2 = F_96 ( V_110 , V_111 ) ;
if ( V_126 ) {
F_102 ( V_119 , V_111 , V_2 , V_110 ,
V_130 ) ;
if ( ! V_2 )
V_119 -> V_133 ++ ;
else if ( ! V_124 && V_2 )
V_126 -> V_133 = V_119 -> V_133 ;
}
if ( V_124 && ! V_2 )
goto V_134;
}
V_134:
F_26 () ;
V_128:
if ( V_124 && V_124 != V_110 )
F_29 ( & V_124 -> V_12 ) ;
return V_2 ;
}
void F_105 ( struct V_1 * V_110 ,
struct V_1 * V_124 )
{
if ( ! V_110 )
V_110 = V_14 ;
if ( V_124 && V_124 != V_110 )
F_29 ( & V_124 -> V_12 ) ;
}
void F_106 ( struct V_107 * V_108 , enum V_135 V_65 )
{
struct V_1 * V_2 ;
F_22 () ;
V_2 = F_23 ( F_95 ( V_108 -> V_109 ) ) ;
if ( F_89 ( ! V_2 ) )
goto V_136;
switch ( V_65 ) {
case V_137 :
F_107 ( V_2 -> V_68 -> V_75 [ V_138 ] ) ;
break;
case V_139 :
F_107 ( V_2 -> V_68 -> V_75 [ V_140 ] ) ;
break;
default:
F_108 () ;
}
V_136:
F_26 () ;
}
struct V_84 * F_109 ( struct V_34 * V_34 ,
struct V_1 * V_2 )
{
struct V_33 * V_44 ;
struct V_84 * V_84 ;
if ( F_104 () ) {
V_84 = & V_34 -> V_84 ;
goto V_136;
}
V_44 = F_38 ( V_2 , V_34 ) ;
V_84 = & V_44 -> V_84 ;
V_136:
if ( F_89 ( V_84 -> V_34 != V_34 ) )
V_84 -> V_34 = V_34 ;
return V_84 ;
}
struct V_84 * F_110 ( struct V_39 * V_39 , struct V_34 * V_34 )
{
struct V_33 * V_44 ;
struct V_1 * V_2 ;
struct V_141 * V_142 ;
struct V_84 * V_84 ;
if ( F_104 () ) {
V_84 = & V_34 -> V_84 ;
goto V_136;
}
V_142 = F_111 ( V_39 ) ;
V_2 = V_142 -> V_1 ;
if ( ! F_112 ( V_39 ) && ! F_113 ( V_142 ) && V_2 != V_14 )
V_142 -> V_1 = V_2 = V_14 ;
V_44 = F_42 ( V_2 , V_39 ) ;
V_84 = & V_44 -> V_84 ;
V_136:
if ( F_89 ( V_84 -> V_34 != V_34 ) )
V_84 -> V_34 = V_34 ;
return V_84 ;
}
void F_114 ( struct V_84 * V_84 , enum V_85 V_86 ,
int V_77 )
{
struct V_33 * V_44 ;
unsigned long * V_87 ;
if ( F_104 () )
return;
V_44 = F_12 ( V_84 , struct V_33 , V_84 ) ;
V_87 = V_44 -> V_87 + V_86 ;
* V_87 += V_77 ;
F_79 ( ( long ) ( * V_87 ) < 0 ) ;
}
bool F_115 ( const struct V_1 * V_143 ,
struct V_1 * V_2 )
{
if ( V_143 == V_2 )
return true ;
if ( ! V_143 -> V_127 || ! V_2 )
return false ;
return F_116 ( V_2 -> V_12 . V_144 , V_143 -> V_12 . V_144 ) ;
}
static bool F_117 ( const struct V_1 * V_143 ,
struct V_1 * V_2 )
{
bool V_145 ;
F_22 () ;
V_145 = F_115 ( V_143 , V_2 ) ;
F_26 () ;
return V_145 ;
}
bool F_118 ( struct V_105 * V_146 ,
const struct V_1 * V_2 )
{
struct V_1 * V_147 = NULL ;
struct V_105 * V_48 ;
bool V_145 ;
V_48 = F_119 ( V_146 ) ;
if ( V_48 ) {
V_147 = F_94 ( V_48 -> V_108 ) ;
F_120 ( V_48 ) ;
} else {
F_22 () ;
V_147 = F_23 ( V_146 ) ;
if ( V_147 )
F_21 ( & V_147 -> V_12 ) ;
F_26 () ;
}
V_145 = F_117 ( V_2 , V_147 ) ;
F_29 ( & V_147 -> V_12 ) ;
return V_145 ;
}
int F_121 ( struct V_84 * V_84 )
{
unsigned long V_148 ;
unsigned long V_149 ;
unsigned long V_150 ;
unsigned long V_151 ;
V_149 = F_77 ( V_84 , V_152 ) ;
V_150 = F_77 ( V_84 , V_153 ) ;
V_151 = ( V_149 + V_150 ) >> ( 30 - V_154 ) ;
if ( V_151 )
V_148 = F_122 ( 10 * V_151 ) ;
else
V_148 = 1 ;
return V_149 * V_148 < V_150 ;
}
static unsigned long F_123 ( struct V_1 * V_2 )
{
unsigned long long V_155 ;
V_155 = F_124 ( & V_2 -> V_59 ) ;
if ( V_156 )
V_155 = F_125 ( V_155 , F_124 ( & V_2 -> V_157 ) ) ;
return V_155 >> V_154 ;
}
int F_126 ( struct V_1 * V_2 )
{
if ( F_104 () || ! V_2 -> V_12 . V_50 )
return V_158 ;
return V_2 -> V_159 ;
}
static void F_127 ( struct V_1 * V_2 )
{
F_92 ( & V_160 ) ;
F_92 ( & V_2 -> V_161 ) ;
F_128 () ;
}
static void F_129 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_130 ( & V_160 ) ;
F_130 ( & V_2 -> V_161 ) ;
}
}
static bool F_131 ( struct V_1 * V_2 )
{
struct V_1 * V_162 ;
struct V_1 * V_163 ;
bool V_145 = false ;
F_54 ( & V_7 . V_57 ) ;
V_162 = V_7 . V_162 ;
V_163 = V_7 . V_163 ;
if ( ! V_162 )
goto V_164;
V_145 = F_117 ( V_2 , V_162 )
|| F_117 ( V_2 , V_163 ) ;
V_164:
F_55 ( & V_7 . V_57 ) ;
return V_145 ;
}
static bool F_132 ( struct V_1 * V_2 )
{
if ( V_7 . V_165 && V_25 != V_7 . V_165 ) {
if ( F_131 ( V_2 ) ) {
F_133 ( V_166 ) ;
F_134 ( & V_7 . V_167 , & V_166 , V_168 ) ;
if ( V_7 . V_165 )
F_135 () ;
F_136 ( & V_7 . V_167 , & V_166 ) ;
return true ;
}
}
return false ;
}
static void F_137 ( struct V_1 * V_2 ,
unsigned long * V_115 )
{
F_138 ( & V_2 -> V_169 , * V_115 ) ;
}
static void F_139 ( struct V_1 * V_2 ,
unsigned long * V_115 )
{
F_140 ( & V_2 -> V_169 , * V_115 ) ;
}
void F_141 ( struct V_1 * V_2 , struct V_105 * V_48 )
{
static F_142 ( V_170 ) ;
struct V_1 * V_119 ;
unsigned int V_171 ;
if ( ! V_48 )
return;
F_143 ( & V_170 ) ;
F_22 () ;
F_144 ( L_1 ) ;
F_145 ( F_146 ( V_48 , V_106 ) ) ;
F_144 ( L_2 ) ;
F_145 ( V_2 -> V_12 . V_144 ) ;
F_144 ( L_3 ) ;
F_26 () ;
F_144 ( L_4 ,
F_36 ( & V_2 -> V_59 , V_32 ) >> 10 ,
F_36 ( & V_2 -> V_59 , V_172 ) >> 10 ,
F_36 ( & V_2 -> V_59 , V_173 ) ) ;
F_144 ( L_5 ,
F_36 ( & V_2 -> V_157 , V_32 ) >> 10 ,
F_36 ( & V_2 -> V_157 , V_172 ) >> 10 ,
F_36 ( & V_2 -> V_157 , V_173 ) ) ;
F_144 ( L_6 ,
F_36 ( & V_2 -> V_31 , V_32 ) >> 10 ,
F_36 ( & V_2 -> V_31 , V_172 ) >> 10 ,
F_36 ( & V_2 -> V_31 , V_173 ) ) ;
F_147 (iter, memcg) {
F_144 ( L_7 ) ;
F_145 ( V_119 -> V_12 . V_144 ) ;
F_148 ( L_8 ) ;
for ( V_171 = 0 ; V_171 < V_174 ; V_171 ++ ) {
if ( V_171 == V_73 && ! V_156 )
continue;
F_148 ( L_9 , V_175 [ V_171 ] ,
F_149 ( F_64 ( V_119 , V_171 ) ) ) ;
}
for ( V_171 = 0 ; V_171 < V_176 ; V_171 ++ )
F_148 ( L_10 , V_177 [ V_171 ] ,
F_149 ( F_82 ( V_119 , F_81 ( V_171 ) ) ) ) ;
F_148 ( L_3 ) ;
}
F_150 ( & V_170 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_178 = 0 ;
struct V_1 * V_119 ;
F_147 (iter, memcg)
V_178 ++ ;
return V_178 ;
}
static T_2 F_152 ( struct V_1 * V_2 )
{
T_2 V_179 ;
V_179 = F_36 ( & V_2 -> V_59 , V_172 ) ;
if ( F_126 ( V_2 ) ) {
T_2 V_157 ;
V_179 += V_180 << V_154 ;
V_157 = F_36 ( & V_2 -> V_157 , V_172 ) ;
V_179 = F_125 ( V_179 , V_157 ) ;
}
return V_179 ;
}
static void F_153 ( struct V_1 * V_2 , T_3 V_181 ,
int V_182 )
{
struct V_1 * V_119 ;
unsigned long V_183 = 0 ;
unsigned long V_184 ;
unsigned int V_185 = 0 ;
struct V_105 * V_186 = NULL ;
if ( F_154 ( V_25 ) || V_25 -> V_115 & V_187 ) {
F_155 ( V_188 ) ;
return;
}
F_156 ( V_189 , V_181 , V_182 , NULL ) ;
V_184 = F_152 ( V_2 ) >> V_154 ? : 1 ;
F_147 (iter, memcg) {
struct V_190 V_191 ;
struct V_105 * V_146 ;
F_157 ( & V_119 -> V_12 , & V_191 ) ;
while ( ( V_146 = F_158 ( & V_191 ) ) ) {
switch ( F_159 ( V_146 , V_184 , NULL ,
false ) ) {
case V_192 :
if ( V_186 )
F_160 ( V_186 ) ;
V_186 = V_146 ;
V_183 = V_193 ;
F_161 ( V_186 ) ;
case V_194 :
continue;
case V_195 :
F_162 ( & V_191 ) ;
F_105 ( V_2 , V_119 ) ;
if ( V_186 )
F_160 ( V_186 ) ;
return;
case V_196 :
break;
} ;
V_185 = F_163 ( V_146 , V_2 , NULL , V_184 ) ;
if ( ! V_185 || V_185 < V_183 )
continue;
if ( V_185 == V_183 &&
F_164 ( V_186 ) )
continue;
if ( V_186 )
F_160 ( V_186 ) ;
V_186 = V_146 ;
V_183 = V_185 ;
F_161 ( V_186 ) ;
}
F_162 ( & V_191 ) ;
}
if ( ! V_186 )
return;
V_185 = V_183 * 1000 / V_184 ;
F_165 ( V_186 , V_181 , V_182 , V_185 , V_184 , V_2 ,
NULL , L_11 ) ;
}
static unsigned long F_166 ( struct V_1 * V_2 ,
T_3 V_181 ,
unsigned long V_115 )
{
unsigned long V_197 = 0 ;
bool V_198 = false ;
int V_199 ;
if ( V_115 & V_200 )
V_198 = true ;
if ( ! ( V_115 & V_201 ) && V_2 -> V_202 )
V_198 = true ;
for ( V_199 = 0 ; V_199 < V_203 ; V_199 ++ ) {
if ( V_199 )
F_167 ( V_2 ) ;
V_197 += F_168 ( V_2 , V_181 , V_198 ) ;
if ( V_197 && ( V_115 & V_201 ) )
break;
if ( F_123 ( V_2 ) )
break;
if ( V_199 && ! V_197 )
break;
}
return V_197 ;
}
static bool F_169 ( struct V_1 * V_2 ,
int V_35 , bool V_198 )
{
if ( F_78 ( V_2 , V_35 , V_204 ) )
return true ;
if ( V_198 || ! V_180 )
return false ;
if ( F_78 ( V_2 , V_35 , V_205 ) )
return true ;
return false ;
}
static void F_170 ( struct V_1 * V_2 )
{
int V_35 ;
if ( ! F_100 ( & V_2 -> V_104 ) )
return;
if ( F_171 ( & V_2 -> V_206 ) > 1 )
return;
V_2 -> V_207 = V_208 [ V_209 ] ;
F_172 (nid, node_states[N_MEMORY]) {
if ( ! F_169 ( V_2 , V_35 , false ) )
F_173 ( V_35 , V_2 -> V_207 ) ;
}
F_174 ( & V_2 -> V_104 , 0 ) ;
F_174 ( & V_2 -> V_206 , 0 ) ;
}
int F_175 ( struct V_1 * V_2 )
{
int V_210 ;
F_170 ( V_2 ) ;
V_210 = V_2 -> V_211 ;
V_210 = F_176 ( V_210 , V_2 -> V_207 ) ;
if ( V_210 == V_103 )
V_210 = F_177 ( V_2 -> V_207 ) ;
if ( F_89 ( V_210 == V_103 ) )
V_210 = F_178 () ;
V_2 -> V_211 = V_210 ;
return V_210 ;
}
static bool F_179 ( struct V_1 * V_2 , bool V_198 )
{
int V_35 ;
if ( ! F_180 ( V_2 -> V_207 ) ) {
for ( V_35 = F_177 ( V_2 -> V_207 ) ;
V_35 < V_103 ;
V_35 = F_176 ( V_35 , V_2 -> V_207 ) ) {
if ( F_169 ( V_2 , V_35 , V_198 ) )
return true ;
}
}
F_83 (nid, N_MEMORY) {
if ( F_181 ( V_35 , V_2 -> V_207 ) )
continue;
if ( F_169 ( V_2 , V_35 , V_198 ) )
return true ;
}
return false ;
}
int F_175 ( struct V_1 * V_2 )
{
return 0 ;
}
static bool F_179 ( struct V_1 * V_2 , bool V_198 )
{
return F_169 ( V_2 , 0 , V_198 ) ;
}
static int F_182 ( struct V_1 * V_143 ,
struct V_34 * V_34 ,
T_3 V_181 ,
unsigned long * V_212 )
{
struct V_1 * V_213 = NULL ;
int V_197 = 0 ;
int V_199 = 0 ;
unsigned long V_58 ;
unsigned long V_214 ;
struct V_125 V_126 = {
. V_34 = V_34 ,
. V_132 = 0 ,
} ;
V_58 = F_58 ( & V_143 -> V_59 ) >> V_154 ;
while ( 1 ) {
V_213 = F_103 ( V_143 , V_213 , & V_126 ) ;
if ( ! V_213 ) {
V_199 ++ ;
if ( V_199 >= 2 ) {
if ( ! V_197 )
break;
if ( V_197 >= ( V_58 >> 2 ) ||
( V_199 > V_203 ) )
break;
}
continue;
}
if ( ! F_179 ( V_213 , false ) )
continue;
V_197 += F_183 ( V_213 , V_181 , false ,
V_34 , & V_214 ) ;
* V_212 += V_214 ;
if ( ! F_58 ( & V_143 -> V_59 ) )
break;
}
F_105 ( V_143 , V_213 ) ;
return V_197 ;
}
static bool F_184 ( struct V_1 * V_2 )
{
struct V_1 * V_119 , * V_215 = NULL ;
F_54 ( & V_216 ) ;
F_147 (iter, memcg) {
if ( V_119 -> V_217 ) {
V_215 = V_119 ;
F_105 ( V_2 , V_119 ) ;
break;
} else
V_119 -> V_217 = true ;
}
if ( V_215 ) {
F_147 (iter, memcg) {
if ( V_119 == V_215 ) {
F_105 ( V_2 , V_119 ) ;
break;
}
V_119 -> V_217 = false ;
}
} else
F_185 ( & V_218 , 0 , 1 , V_219 ) ;
F_55 ( & V_216 ) ;
return ! V_215 ;
}
static void F_186 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_54 ( & V_216 ) ;
F_187 ( & V_218 , 1 , V_219 ) ;
F_147 (iter, memcg)
V_119 -> V_217 = false ;
F_55 ( & V_216 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_147 (iter, memcg)
F_92 ( & V_119 -> V_220 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_147 (iter, memcg)
F_190 ( & V_119 -> V_220 , - 1 , 0 ) ;
}
static int F_191 ( T_4 * V_166 ,
unsigned V_221 , int V_222 , void * V_223 )
{
struct V_1 * V_224 = (struct V_1 * ) V_223 ;
struct V_1 * V_225 ;
struct V_226 * V_226 ;
V_226 = F_12 ( V_166 , struct V_226 , V_166 ) ;
V_225 = V_226 -> V_2 ;
if ( ! F_117 ( V_225 , V_224 )
&& ! F_117 ( V_224 , V_225 ) )
return 0 ;
return F_192 ( V_166 , V_221 , V_222 , V_223 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_92 ( & V_2 -> V_227 ) ;
F_194 ( & V_228 , V_229 , 0 , V_2 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
if ( V_2 && F_100 ( & V_2 -> V_220 ) )
F_193 ( V_2 ) ;
}
static void F_196 ( struct V_1 * V_2 , T_3 V_230 , int V_182 )
{
if ( ! V_25 -> V_231 . V_232 )
return;
F_21 ( & V_2 -> V_12 ) ;
V_25 -> V_231 . V_2 = V_2 ;
V_25 -> V_231 . V_181 = V_230 ;
V_25 -> V_231 . V_182 = V_182 ;
}
bool F_197 ( bool V_233 )
{
struct V_1 * V_2 = V_25 -> V_231 . V_2 ;
struct V_226 V_234 ;
bool V_235 ;
if ( ! V_2 )
return false ;
if ( ! V_233 )
goto V_236;
V_234 . V_2 = V_2 ;
V_234 . V_166 . V_115 = 0 ;
V_234 . V_166 . V_237 = F_191 ;
V_234 . V_166 . V_238 = V_25 ;
F_198 ( & V_234 . V_166 . V_239 ) ;
F_134 ( & V_228 , & V_234 . V_166 , V_240 ) ;
F_188 ( V_2 ) ;
V_235 = F_184 ( V_2 ) ;
if ( V_235 )
F_199 ( V_2 ) ;
if ( V_235 && ! V_2 -> V_241 ) {
F_189 ( V_2 ) ;
F_136 ( & V_228 , & V_234 . V_166 ) ;
F_153 ( V_2 , V_25 -> V_231 . V_181 ,
V_25 -> V_231 . V_182 ) ;
} else {
F_135 () ;
F_189 ( V_2 ) ;
F_136 ( & V_228 , & V_234 . V_166 ) ;
}
if ( V_235 ) {
F_186 ( V_2 ) ;
F_195 ( V_2 ) ;
}
V_236:
V_25 -> V_231 . V_2 = NULL ;
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
void F_200 ( struct V_39 * V_39 ,
bool * V_235 , unsigned long * V_115 )
{
struct V_1 * V_2 ;
struct V_141 * V_142 ;
V_142 = F_111 ( V_39 ) ;
V_242:
V_2 = V_142 -> V_1 ;
if ( F_89 ( ! V_2 || ! F_113 ( V_142 ) ) )
return;
F_79 ( ! F_201 () ) ;
if ( F_100 ( & V_2 -> V_161 ) <= 0 )
return;
F_137 ( V_2 , V_115 ) ;
if ( V_2 != V_142 -> V_1 || ! F_113 ( V_142 ) ) {
F_139 ( V_2 , V_115 ) ;
goto V_242;
}
* V_235 = true ;
}
void F_202 ( struct V_39 * V_39 , unsigned long * V_115 )
{
struct V_141 * V_142 = F_111 ( V_39 ) ;
F_139 ( V_142 -> V_1 , V_115 ) ;
}
void F_203 ( struct V_39 * V_39 ,
enum V_64 V_65 , int V_66 )
{
struct V_1 * V_2 ;
struct V_141 * V_142 = F_111 ( V_39 ) ;
unsigned long V_129 ( V_115 ) ;
if ( F_104 () )
return;
F_79 ( ! F_201 () ) ;
V_2 = V_142 -> V_1 ;
if ( F_89 ( ! V_2 || ! F_113 ( V_142 ) ) )
return;
F_71 ( V_2 -> V_68 -> V_69 [ V_65 ] , V_66 ) ;
}
static bool F_204 ( struct V_1 * V_2 , unsigned int V_77 )
{
struct V_243 * V_244 ;
bool V_145 = true ;
if ( V_77 > V_245 )
return false ;
V_244 = & F_205 ( V_246 ) ;
if ( V_2 == V_244 -> V_247 && V_244 -> V_77 >= V_77 )
V_244 -> V_77 -= V_77 ;
else
V_145 = false ;
F_206 ( V_246 ) ;
return V_145 ;
}
static void F_207 ( struct V_243 * V_244 )
{
struct V_1 * V_248 = V_244 -> V_247 ;
if ( V_244 -> V_77 ) {
unsigned long V_249 = V_244 -> V_77 * V_250 ;
F_208 ( & V_248 -> V_59 , V_249 ) ;
if ( V_156 )
F_208 ( & V_248 -> V_157 , V_249 ) ;
V_244 -> V_77 = 0 ;
}
V_244 -> V_247 = NULL ;
}
static void F_209 ( struct V_251 * V_252 )
{
struct V_243 * V_244 = F_210 ( & V_246 ) ;
F_207 ( V_244 ) ;
F_211 ( V_253 , & V_244 -> V_115 ) ;
}
static void T_5 F_212 ( void )
{
int V_67 ;
F_213 (cpu) {
struct V_243 * V_244 =
& F_67 ( V_246 , V_67 ) ;
F_214 ( & V_244 -> V_254 , F_209 ) ;
}
}
static void F_215 ( struct V_1 * V_2 , unsigned int V_77 )
{
struct V_243 * V_244 = & F_205 ( V_246 ) ;
if ( V_244 -> V_247 != V_2 ) {
F_207 ( V_244 ) ;
V_244 -> V_247 = V_2 ;
}
V_244 -> V_77 += V_77 ;
F_206 ( V_246 ) ;
}
static void F_216 ( struct V_1 * V_143 , bool V_222 )
{
int V_67 , V_255 ;
F_65 () ;
V_255 = F_217 () ;
F_66 (cpu) {
struct V_243 * V_244 = & F_67 ( V_246 , V_67 ) ;
struct V_1 * V_2 ;
V_2 = V_244 -> V_247 ;
if ( ! V_2 || ! V_244 -> V_77 )
continue;
if ( ! F_117 ( V_143 , V_2 ) )
continue;
if ( ! F_218 ( V_253 , & V_244 -> V_115 ) ) {
if ( V_67 == V_255 )
F_209 ( & V_244 -> V_254 ) ;
else
F_219 ( V_67 , & V_244 -> V_254 ) ;
}
}
F_220 () ;
if ( ! V_222 )
goto V_136;
F_66 (cpu) {
struct V_243 * V_244 = & F_67 ( V_246 , V_67 ) ;
if ( F_4 ( V_253 , & V_244 -> V_115 ) )
F_221 ( & V_244 -> V_254 ) ;
}
V_136:
F_69 () ;
}
static void F_167 ( struct V_1 * V_143 )
{
if ( ! F_222 ( & V_256 ) )
return;
F_216 ( V_143 , false ) ;
F_150 ( & V_256 ) ;
}
static void F_223 ( struct V_1 * V_143 )
{
F_143 ( & V_256 ) ;
F_216 ( V_143 , true ) ;
F_150 ( & V_256 ) ;
}
static void F_224 ( struct V_1 * V_2 , int V_67 )
{
int V_171 ;
F_54 ( & V_2 -> V_70 ) ;
for ( V_171 = 0 ; V_171 < V_174 ; V_171 ++ ) {
long V_257 = F_67 ( V_2 -> V_68 -> V_69 [ V_171 ] , V_67 ) ;
F_67 ( V_2 -> V_68 -> V_69 [ V_171 ] , V_67 ) = 0 ;
V_2 -> V_71 . V_69 [ V_171 ] += V_257 ;
}
for ( V_171 = 0 ; V_171 < V_258 ; V_171 ++ ) {
unsigned long V_257 = F_67 ( V_2 -> V_68 -> V_75 [ V_171 ] , V_67 ) ;
F_67 ( V_2 -> V_68 -> V_75 [ V_171 ] , V_67 ) = 0 ;
V_2 -> V_71 . V_75 [ V_171 ] += V_257 ;
}
F_55 ( & V_2 -> V_70 ) ;
}
static int F_225 ( struct V_259 * V_260 ,
unsigned long V_261 ,
void * V_262 )
{
int V_67 = ( unsigned long ) V_262 ;
struct V_243 * V_244 ;
struct V_1 * V_119 ;
if ( V_261 == V_263 )
return V_264 ;
if ( V_261 != V_265 && V_261 != V_266 )
return V_264 ;
F_226 (iter)
F_224 ( V_119 , V_67 ) ;
V_244 = & F_67 ( V_246 , V_67 ) ;
F_207 ( V_244 ) ;
return V_264 ;
}
static int F_227 ( struct V_1 * V_2 , T_3 V_181 ,
unsigned int V_77 , unsigned int V_267 ,
bool V_268 )
{
unsigned long V_269 = V_77 * V_250 ;
struct V_1 * V_270 ;
struct V_271 * V_272 ;
unsigned long V_115 = 0 ;
int V_145 ;
V_145 = F_228 ( & V_2 -> V_59 , V_269 , & V_272 ) ;
if ( F_229 ( ! V_145 ) ) {
if ( ! V_156 )
return V_273 ;
V_145 = F_228 ( & V_2 -> V_157 , V_269 , & V_272 ) ;
if ( F_229 ( ! V_145 ) )
return V_273 ;
F_208 ( & V_2 -> V_59 , V_269 ) ;
V_270 = F_230 ( V_272 , V_157 ) ;
V_115 |= V_200 ;
} else
V_270 = F_230 ( V_272 , V_59 ) ;
if ( V_77 > V_267 )
return V_274 ;
if ( ! ( V_181 & V_275 ) )
return V_276 ;
if ( V_181 & V_277 )
return V_278 ;
V_145 = F_166 ( V_270 , V_181 , V_115 ) ;
if ( F_123 ( V_270 ) >= V_77 )
return V_274 ;
if ( V_77 <= ( 1 << V_279 ) && V_145 )
return V_274 ;
if ( F_132 ( V_270 ) )
return V_274 ;
if ( V_268 )
F_196 ( V_270 , V_181 , F_231 ( V_269 ) ) ;
return V_278 ;
}
static int F_232 ( struct V_1 * V_2 ,
T_3 V_181 ,
unsigned int V_77 ,
bool V_280 )
{
unsigned int V_281 = F_233 ( V_245 , V_77 ) ;
int V_282 = V_283 ;
int V_145 ;
if ( F_15 ( V_2 ) )
goto V_63;
if ( F_89 ( F_234 ( V_188 ) ||
F_154 ( V_25 ) ||
V_25 -> V_115 & V_187 ) )
goto V_284;
if ( F_89 ( F_235 ( V_25 ) ) )
goto V_285;
if ( V_181 & V_286 )
V_280 = false ;
V_242:
if ( F_204 ( V_2 , V_77 ) )
goto V_63;
do {
bool V_268 = V_280 && ! V_282 ;
if ( F_154 ( V_25 ) )
goto V_284;
V_145 = F_227 ( V_2 , V_181 , V_281 ,
V_77 , V_268 ) ;
switch ( V_145 ) {
case V_273 :
break;
case V_274 :
V_281 = V_77 ;
goto V_242;
case V_276 :
goto V_285;
case V_278 :
if ( ! V_280 || V_268 )
goto V_285;
V_282 -- ;
break;
}
} while ( V_145 != V_273 );
if ( V_281 > V_77 )
F_215 ( V_2 , V_281 - V_77 ) ;
V_63:
return 0 ;
V_285:
if ( ! ( V_181 & V_286 ) )
return - V_287 ;
V_284:
return - V_288 ;
}
static struct V_1 * F_236 ( struct V_107 * V_108 ,
T_3 V_181 ,
unsigned int V_77 ,
bool V_280 )
{
struct V_1 * V_2 ;
int V_145 ;
V_2 = F_94 ( V_108 ) ;
V_145 = F_232 ( V_2 , V_181 , V_77 , V_280 ) ;
F_29 ( & V_2 -> V_12 ) ;
if ( V_145 == - V_288 )
V_2 = V_14 ;
else if ( V_145 )
V_2 = NULL ;
return V_2 ;
}
static void F_237 ( struct V_1 * V_2 ,
unsigned int V_77 )
{
if ( ! F_15 ( V_2 ) ) {
unsigned long V_249 = V_77 * V_250 ;
F_208 ( & V_2 -> V_59 , V_249 ) ;
if ( V_156 )
F_208 ( & V_2 -> V_157 , V_249 ) ;
}
}
static void F_238 ( struct V_1 * V_2 ,
unsigned int V_77 )
{
unsigned long V_249 = V_77 * V_250 ;
if ( F_15 ( V_2 ) )
return;
F_239 ( & V_2 -> V_59 , V_2 -> V_59 . V_50 , V_249 ) ;
if ( V_156 )
F_239 ( & V_2 -> V_157 ,
V_2 -> V_157 . V_50 , V_249 ) ;
}
static struct V_1 * F_240 ( unsigned short V_16 )
{
if ( ! V_16 )
return NULL ;
return F_17 ( V_16 ) ;
}
struct V_1 * F_241 ( struct V_39 * V_39 )
{
struct V_1 * V_2 = NULL ;
struct V_141 * V_142 ;
unsigned short V_16 ;
T_6 V_289 ;
F_242 ( ! F_243 ( V_39 ) , V_39 ) ;
V_142 = F_111 ( V_39 ) ;
F_244 ( V_142 ) ;
if ( F_113 ( V_142 ) ) {
V_2 = V_142 -> V_1 ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
} else if ( F_245 ( V_39 ) ) {
V_289 . V_66 = F_246 ( V_39 ) ;
V_16 = F_247 ( V_289 ) ;
F_22 () ;
V_2 = F_240 ( V_16 ) ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
F_26 () ;
}
F_248 ( V_142 ) ;
return V_2 ;
}
static void F_249 ( struct V_1 * V_2 ,
struct V_39 * V_39 ,
unsigned int V_77 ,
enum V_290 V_291 ,
bool V_292 )
{
struct V_141 * V_142 = F_111 ( V_39 ) ;
struct V_34 * V_129 ( V_34 ) ;
struct V_84 * V_84 ;
bool V_293 = false ;
bool V_76 ;
F_244 ( V_142 ) ;
F_242 ( F_113 ( V_142 ) , V_39 ) ;
if ( V_292 ) {
V_34 = F_250 ( V_39 ) ;
F_251 ( & V_34 -> V_294 ) ;
if ( F_112 ( V_39 ) ) {
V_84 = F_109 ( V_34 , V_142 -> V_1 ) ;
F_252 ( V_39 ) ;
F_253 ( V_39 , V_84 , F_254 ( V_39 ) ) ;
V_293 = true ;
}
}
V_142 -> V_1 = V_2 ;
F_6 () ;
F_255 ( V_142 ) ;
if ( V_292 ) {
if ( V_293 ) {
V_84 = F_109 ( V_34 , V_142 -> V_1 ) ;
F_242 ( F_112 ( V_39 ) , V_39 ) ;
F_256 ( V_39 ) ;
F_257 ( V_39 , V_84 , F_254 ( V_39 ) ) ;
}
F_258 ( & V_34 -> V_294 ) ;
}
if ( V_291 == V_295 )
V_76 = true ;
else
V_76 = false ;
F_73 ( V_2 , V_39 , V_76 , V_77 ) ;
F_248 ( V_142 ) ;
F_87 ( V_2 , V_39 ) ;
}
static inline bool F_259 ( struct V_1 * V_2 )
{
return ! F_104 () && ! F_15 ( V_2 ) &&
F_3 ( V_2 ) ;
}
static struct V_296 * F_260 ( struct V_297 * V_48 )
{
struct V_296 * V_298 ;
F_79 ( V_48 -> V_299 ) ;
V_298 = V_48 -> V_300 ;
return F_261 ( V_298 , F_262 ( V_48 -> V_2 ) ) ;
}
static int F_263 ( struct V_301 * V_302 , void * V_303 )
{
struct V_1 * V_2 = F_11 ( F_264 ( V_302 ) ) ;
struct V_297 * V_304 ;
if ( ! F_259 ( V_2 ) )
return - V_305 ;
F_265 ( V_302 ) ;
F_143 ( & V_306 ) ;
F_266 (params, &memcg->memcg_slab_caches, list)
F_267 ( F_260 ( V_304 ) , V_302 ) ;
F_150 ( & V_306 ) ;
return 0 ;
}
static int F_268 ( struct V_1 * V_2 , T_3 V_307 , T_2 V_308 )
{
struct V_271 * V_272 ;
int V_145 = 0 ;
V_145 = F_228 ( & V_2 -> V_31 , V_308 , & V_272 ) ;
if ( V_145 )
return V_145 ;
V_145 = F_232 ( V_2 , V_307 , V_308 >> V_154 ,
F_269 ( V_307 ) ) ;
if ( V_145 == - V_288 ) {
F_270 ( & V_2 -> V_59 , V_308 , & V_272 ) ;
if ( V_156 )
F_270 ( & V_2 -> V_157 , V_308 ,
& V_272 ) ;
V_145 = 0 ;
} else if ( V_145 )
F_208 ( & V_2 -> V_31 , V_308 ) ;
return V_145 ;
}
static void F_271 ( struct V_1 * V_2 , T_2 V_308 )
{
F_208 ( & V_2 -> V_59 , V_308 ) ;
if ( V_156 )
F_208 ( & V_2 -> V_157 , V_308 ) ;
if ( F_208 ( & V_2 -> V_31 , V_308 ) )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
int F_262 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_30 : - 1 ;
}
static T_7 F_272 ( int V_309 )
{
T_8 V_308 ;
if ( V_309 <= 0 )
return 0 ;
V_308 = 2 * V_309 ;
if ( V_308 < V_310 )
V_308 = V_310 ;
else if ( V_308 > V_311 )
V_308 = V_311 ;
return V_308 ;
}
void F_273 ( int V_178 )
{
if ( V_178 > V_312 )
V_312 = F_272 ( V_178 ) ;
}
int F_274 ( struct V_296 * V_11 , int V_309 )
{
struct V_297 * V_313 = V_11 -> V_314 ;
F_79 ( ! V_299 ( V_11 ) ) ;
if ( V_309 > V_312 ) {
int V_171 ;
struct V_297 * V_315 ;
T_8 V_308 = F_272 ( V_309 ) ;
V_308 *= sizeof( void * ) ;
V_308 += F_275 ( struct V_297 , V_316 ) ;
V_315 = F_276 ( V_308 , V_317 ) ;
if ( ! V_315 )
return - V_287 ;
V_315 -> V_299 = true ;
for ( V_171 = 0 ; V_171 < V_312 ; V_171 ++ ) {
if ( ! V_313 -> V_316 [ V_171 ] )
continue;
V_315 -> V_316 [ V_171 ] =
V_313 -> V_316 [ V_171 ] ;
}
F_277 ( V_11 -> V_314 , V_315 ) ;
if ( V_313 )
F_278 ( V_313 , V_318 ) ;
}
return 0 ;
}
int F_279 ( struct V_1 * V_2 , struct V_296 * V_11 ,
struct V_296 * V_300 )
{
T_7 V_308 ;
if ( ! F_280 () )
return 0 ;
if ( ! V_2 ) {
V_308 = F_275 ( struct V_297 , V_316 ) ;
V_308 += V_312 * sizeof( void * ) ;
} else
V_308 = sizeof( struct V_297 ) ;
V_11 -> V_314 = F_276 ( V_308 , V_317 ) ;
if ( ! V_11 -> V_314 )
return - V_287 ;
if ( V_2 ) {
V_11 -> V_314 -> V_2 = V_2 ;
V_11 -> V_314 -> V_300 = V_300 ;
F_21 ( & V_2 -> V_12 ) ;
} else
V_11 -> V_314 -> V_299 = true ;
return 0 ;
}
void F_281 ( struct V_296 * V_11 )
{
if ( ! V_11 -> V_314 )
return;
if ( ! V_11 -> V_314 -> V_299 )
F_29 ( & V_11 -> V_314 -> V_2 -> V_12 ) ;
F_282 ( V_11 -> V_314 ) ;
}
static void F_283 ( struct V_1 * V_2 ,
struct V_296 * V_300 )
{
static char V_319 [ V_320 + 1 ] ;
struct V_296 * V_298 ;
int V_16 ;
F_284 ( & V_306 ) ;
V_16 = F_262 ( V_2 ) ;
if ( F_261 ( V_300 , V_16 ) )
return;
F_285 ( V_2 -> V_12 . V_144 , V_319 , V_320 + 1 ) ;
V_298 = F_286 ( V_2 , V_300 , V_319 ) ;
if ( ! V_298 )
return;
F_287 ( & V_298 -> V_314 -> V_321 , & V_2 -> V_322 ) ;
F_6 () ;
F_20 ( V_300 -> V_314 -> V_316 [ V_16 ] ) ;
V_300 -> V_314 -> V_316 [ V_16 ] = V_298 ;
}
static void F_288 ( struct V_296 * V_298 )
{
struct V_296 * V_300 ;
struct V_1 * V_2 ;
int V_16 ;
F_284 ( & V_306 ) ;
F_20 ( V_299 ( V_298 ) ) ;
V_300 = V_298 -> V_314 -> V_300 ;
V_2 = V_298 -> V_314 -> V_2 ;
V_16 = F_262 ( V_2 ) ;
F_20 ( V_300 -> V_314 -> V_316 [ V_16 ] != V_298 ) ;
V_300 -> V_314 -> V_316 [ V_16 ] = NULL ;
F_289 ( & V_298 -> V_314 -> V_321 ) ;
F_290 ( V_298 ) ;
}
static inline void F_291 ( void )
{
F_79 ( ! V_25 -> V_108 ) ;
V_25 -> V_323 ++ ;
}
static inline void F_292 ( void )
{
F_79 ( ! V_25 -> V_108 ) ;
V_25 -> V_323 -- ;
}
int F_293 ( struct V_296 * V_11 )
{
struct V_296 * V_324 ;
int V_171 , V_215 = 0 ;
F_143 ( & V_306 ) ;
F_294 (i) {
V_324 = F_261 ( V_11 , V_171 ) ;
if ( ! V_324 )
continue;
F_288 ( V_324 ) ;
if ( F_261 ( V_11 , V_171 ) )
V_215 ++ ;
}
F_150 ( & V_306 ) ;
return V_215 ;
}
static void F_295 ( struct V_1 * V_2 )
{
struct V_296 * V_298 ;
struct V_297 * V_304 , * V_325 ;
if ( ! F_3 ( V_2 ) )
return;
F_143 ( & V_306 ) ;
F_296 (params, tmp, &memcg->memcg_slab_caches, list) {
V_298 = F_260 ( V_304 ) ;
F_297 ( V_298 ) ;
if ( F_100 ( & V_298 -> V_314 -> V_77 ) == 0 )
F_288 ( V_298 ) ;
}
F_150 ( & V_306 ) ;
}
static void F_298 ( struct V_251 * V_326 )
{
struct V_327 * V_328 =
F_12 ( V_326 , struct V_327 , V_254 ) ;
struct V_1 * V_2 = V_328 -> V_2 ;
struct V_296 * V_298 = V_328 -> V_298 ;
F_143 ( & V_306 ) ;
F_283 ( V_2 , V_298 ) ;
F_150 ( & V_306 ) ;
F_29 ( & V_2 -> V_12 ) ;
F_282 ( V_328 ) ;
}
static void F_299 ( struct V_1 * V_2 ,
struct V_296 * V_298 )
{
struct V_327 * V_328 ;
V_328 = F_300 ( sizeof( * V_328 ) , V_329 ) ;
if ( V_328 == NULL ) {
F_29 ( & V_2 -> V_12 ) ;
return;
}
V_328 -> V_2 = V_2 ;
V_328 -> V_298 = V_298 ;
F_214 ( & V_328 -> V_254 , F_298 ) ;
F_301 ( & V_328 -> V_254 ) ;
}
static void F_302 ( struct V_1 * V_2 ,
struct V_296 * V_298 )
{
F_291 () ;
F_299 ( V_2 , V_298 ) ;
F_292 () ;
}
int F_303 ( struct V_296 * V_298 , T_3 V_307 , int V_182 )
{
int V_59 ;
V_59 = F_268 ( V_298 -> V_314 -> V_2 , V_307 ,
V_250 << V_182 ) ;
if ( ! V_59 )
F_304 ( 1 << V_182 , & V_298 -> V_314 -> V_77 ) ;
return V_59 ;
}
void F_305 ( struct V_296 * V_298 , int V_182 )
{
F_271 ( V_298 -> V_314 -> V_2 , V_250 << V_182 ) ;
F_306 ( 1 << V_182 , & V_298 -> V_314 -> V_77 ) ;
}
struct V_296 * F_307 ( struct V_296 * V_298 ,
T_3 V_307 )
{
struct V_1 * V_2 ;
struct V_296 * V_330 ;
F_79 ( ! V_298 -> V_314 ) ;
F_79 ( ! V_298 -> V_314 -> V_299 ) ;
if ( ! V_25 -> V_108 || V_25 -> V_323 )
return V_298 ;
F_22 () ;
V_2 = F_23 ( F_95 ( V_25 -> V_108 -> V_109 ) ) ;
if ( ! F_259 ( V_2 ) )
goto V_136;
V_330 = F_261 ( V_298 , F_262 ( V_2 ) ) ;
if ( F_229 ( V_330 ) ) {
V_298 = V_330 ;
goto V_136;
}
if ( ! F_25 ( & V_2 -> V_12 ) )
goto V_136;
F_26 () ;
F_302 ( V_2 , V_298 ) ;
return V_298 ;
V_136:
F_26 () ;
return V_298 ;
}
bool
F_308 ( T_3 V_307 , struct V_1 * * V_331 , int V_182 )
{
struct V_1 * V_2 ;
int V_145 ;
* V_331 = NULL ;
if ( ! V_25 -> V_108 || V_25 -> V_323 )
return true ;
V_2 = F_94 ( V_25 -> V_108 ) ;
if ( ! F_259 ( V_2 ) ) {
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
V_145 = F_268 ( V_2 , V_307 , V_250 << V_182 ) ;
if ( ! V_145 )
* V_331 = V_2 ;
F_29 ( & V_2 -> V_12 ) ;
return ( V_145 == 0 ) ;
}
void F_309 ( struct V_39 * V_39 , struct V_1 * V_2 ,
int V_182 )
{
struct V_141 * V_142 ;
F_79 ( F_15 ( V_2 ) ) ;
if ( ! V_39 ) {
F_271 ( V_2 , V_250 << V_182 ) ;
return;
}
V_142 = F_111 ( V_39 ) ;
F_244 ( V_142 ) ;
V_142 -> V_1 = V_2 ;
F_255 ( V_142 ) ;
F_248 ( V_142 ) ;
}
void F_310 ( struct V_39 * V_39 , int V_182 )
{
struct V_1 * V_2 = NULL ;
struct V_141 * V_142 ;
V_142 = F_111 ( V_39 ) ;
if ( ! F_113 ( V_142 ) )
return;
F_244 ( V_142 ) ;
if ( F_113 ( V_142 ) ) {
V_2 = V_142 -> V_1 ;
F_311 ( V_142 ) ;
}
F_248 ( V_142 ) ;
if ( ! V_2 )
return;
F_242 ( F_15 ( V_2 ) , V_39 ) ;
F_271 ( V_2 , V_250 << V_182 ) ;
}
static inline void F_295 ( struct V_1 * V_2 )
{
}
void F_312 ( struct V_39 * V_332 )
{
struct V_141 * V_333 = F_111 ( V_332 ) ;
struct V_141 * V_142 ;
struct V_1 * V_2 ;
int V_171 ;
if ( F_104 () )
return;
V_2 = V_333 -> V_1 ;
for ( V_171 = 1 ; V_171 < V_334 ; V_171 ++ ) {
V_142 = V_333 + V_171 ;
V_142 -> V_1 = V_2 ;
F_6 () ;
V_142 -> V_115 = V_333 -> V_115 & ~ V_335 ;
}
F_313 ( V_2 -> V_68 -> V_69 [ V_80 ] ,
V_334 ) ;
}
static int F_314 ( struct V_39 * V_39 ,
unsigned int V_77 ,
struct V_141 * V_142 ,
struct V_1 * V_162 ,
struct V_1 * V_163 )
{
unsigned long V_115 ;
int V_145 ;
bool V_76 = F_315 ( V_39 ) ;
F_79 ( V_162 == V_163 ) ;
F_242 ( F_112 ( V_39 ) , V_39 ) ;
V_145 = - V_336 ;
if ( V_77 > 1 && ! F_75 ( V_39 ) )
goto V_136;
F_244 ( V_142 ) ;
V_145 = - V_337 ;
if ( ! F_113 ( V_142 ) || V_142 -> V_1 != V_162 )
goto V_164;
F_137 ( V_162 , & V_115 ) ;
if ( ! V_76 && F_316 ( V_39 ) ) {
F_313 ( V_162 -> V_68 -> V_69 [ V_338 ] ,
V_77 ) ;
F_74 ( V_163 -> V_68 -> V_69 [ V_338 ] ,
V_77 ) ;
}
if ( F_317 ( V_39 ) ) {
F_313 ( V_162 -> V_68 -> V_69 [ V_339 ] ,
V_77 ) ;
F_74 ( V_163 -> V_68 -> V_69 [ V_339 ] ,
V_77 ) ;
}
F_73 ( V_162 , V_39 , V_76 , - V_77 ) ;
V_142 -> V_1 = V_163 ;
F_73 ( V_163 , V_39 , V_76 , V_77 ) ;
F_139 ( V_162 , & V_115 ) ;
V_145 = 0 ;
V_164:
F_248 ( V_142 ) ;
F_87 ( V_163 , V_39 ) ;
F_87 ( V_162 , V_39 ) ;
V_136:
return V_145 ;
}
static int F_318 ( struct V_39 * V_39 ,
struct V_141 * V_142 ,
struct V_1 * V_340 )
{
struct V_1 * V_50 ;
unsigned int V_77 ;
unsigned long V_129 ( V_115 ) ;
int V_145 ;
F_79 ( F_15 ( V_340 ) ) ;
V_145 = - V_336 ;
if ( ! F_319 ( V_39 ) )
goto V_136;
if ( F_320 ( V_39 ) )
goto V_341;
V_77 = F_321 ( V_39 ) ;
V_50 = F_57 ( V_340 ) ;
if ( ! V_50 )
V_50 = V_14 ;
if ( V_77 > 1 ) {
F_242 ( ! F_75 ( V_39 ) , V_39 ) ;
V_115 = F_322 ( V_39 ) ;
}
V_145 = F_314 ( V_39 , V_77 ,
V_142 , V_340 , V_50 ) ;
if ( ! V_145 )
F_238 ( V_340 , V_77 ) ;
if ( V_77 > 1 )
F_323 ( V_39 , V_115 ) ;
F_324 ( V_39 ) ;
V_341:
F_325 ( V_39 ) ;
V_136:
return V_145 ;
}
int F_326 ( struct V_39 * V_39 ,
struct V_107 * V_108 , T_3 V_181 )
{
unsigned int V_77 = 1 ;
struct V_1 * V_2 ;
bool V_280 = true ;
if ( F_104 () )
return 0 ;
F_242 ( F_316 ( V_39 ) , V_39 ) ;
F_242 ( V_39 -> V_342 && ! F_315 ( V_39 ) , V_39 ) ;
F_79 ( ! V_108 ) ;
if ( F_75 ( V_39 ) ) {
V_77 <<= F_327 ( V_39 ) ;
F_242 ( ! F_75 ( V_39 ) , V_39 ) ;
V_280 = false ;
}
V_2 = F_236 ( V_108 , V_181 , V_77 , V_280 ) ;
if ( ! V_2 )
return - V_287 ;
F_249 ( V_2 , V_39 , V_77 ,
V_295 , false ) ;
return 0 ;
}
static int F_328 ( struct V_107 * V_108 ,
struct V_39 * V_39 ,
T_3 V_230 ,
struct V_1 * * V_343 )
{
struct V_1 * V_2 = NULL ;
struct V_141 * V_142 ;
int V_145 ;
V_142 = F_111 ( V_39 ) ;
if ( F_113 ( V_142 ) )
goto V_136;
if ( V_156 )
V_2 = F_241 ( V_39 ) ;
if ( ! V_2 )
V_2 = F_94 ( V_108 ) ;
V_145 = F_232 ( V_2 , V_230 , 1 , true ) ;
F_29 ( & V_2 -> V_12 ) ;
if ( V_145 == - V_288 )
V_2 = V_14 ;
else if ( V_145 )
return V_145 ;
V_136:
* V_343 = V_2 ;
return 0 ;
}
int F_329 ( struct V_107 * V_108 , struct V_39 * V_39 ,
T_3 V_181 , struct V_1 * * V_343 )
{
if ( F_104 () ) {
* V_343 = NULL ;
return 0 ;
}
if ( ! F_245 ( V_39 ) ) {
struct V_1 * V_2 ;
V_2 = F_236 ( V_108 , V_181 , 1 , true ) ;
if ( ! V_2 )
return - V_287 ;
* V_343 = V_2 ;
return 0 ;
}
return F_328 ( V_108 , V_39 , V_181 , V_343 ) ;
}
void F_330 ( struct V_1 * V_2 )
{
if ( F_104 () )
return;
if ( ! V_2 )
return;
F_237 ( V_2 , 1 ) ;
}
static void
F_331 ( struct V_39 * V_39 , struct V_1 * V_2 ,
enum V_290 V_291 )
{
if ( F_104 () )
return;
if ( ! V_2 )
return;
F_249 ( V_2 , V_39 , 1 , V_291 , true ) ;
if ( V_156 && F_245 ( V_39 ) ) {
T_6 V_289 = { . V_66 = F_246 (page) } ;
F_332 ( V_289 ) ;
}
}
void F_333 ( struct V_39 * V_39 ,
struct V_1 * V_2 )
{
F_331 ( V_39 , V_2 ,
V_295 ) ;
}
int F_334 ( struct V_39 * V_39 , struct V_107 * V_108 ,
T_3 V_181 )
{
enum V_290 type = V_344 ;
struct V_1 * V_2 ;
int V_145 ;
if ( F_104 () )
return 0 ;
if ( F_335 ( V_39 ) )
return 0 ;
if ( F_245 ( V_39 ) ) {
V_145 = F_328 ( V_108 , V_39 ,
V_181 , & V_2 ) ;
if ( V_145 )
return V_145 ;
F_331 ( V_39 , V_2 , type ) ;
return 0 ;
}
V_2 = F_236 ( V_108 , V_181 , 1 , true ) ;
if ( ! V_2 )
return - V_287 ;
F_249 ( V_2 , V_39 , 1 , type , false ) ;
return 0 ;
}
static void F_336 ( struct V_1 * V_2 ,
unsigned int V_77 ,
const enum V_290 V_291 )
{
struct V_345 * V_281 = NULL ;
bool V_346 = true ;
if ( ! V_156 || V_291 == V_347 )
V_346 = false ;
V_281 = & V_25 -> V_348 ;
if ( ! V_281 -> V_2 )
V_281 -> V_2 = V_2 ;
if ( ! V_281 -> V_349 || F_234 ( V_188 ) )
goto V_350;
if ( V_77 > 1 )
goto V_350;
if ( V_281 -> V_2 != V_2 )
goto V_350;
V_281 -> V_77 ++ ;
if ( V_346 )
V_281 -> V_351 ++ ;
return;
V_350:
F_208 ( & V_2 -> V_59 , V_77 * V_250 ) ;
if ( V_346 )
F_208 ( & V_2 -> V_157 , V_77 * V_250 ) ;
if ( F_89 ( V_281 -> V_2 != V_2 ) )
F_195 ( V_2 ) ;
}
static struct V_1 *
F_337 ( struct V_39 * V_39 , enum V_290 V_291 ,
bool V_352 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_77 = 1 ;
struct V_141 * V_142 ;
bool V_76 ;
if ( F_104 () )
return NULL ;
if ( F_75 ( V_39 ) ) {
V_77 <<= F_327 ( V_39 ) ;
F_242 ( ! F_75 ( V_39 ) , V_39 ) ;
}
V_142 = F_111 ( V_39 ) ;
if ( F_89 ( ! F_113 ( V_142 ) ) )
return NULL ;
F_244 ( V_142 ) ;
V_2 = V_142 -> V_1 ;
if ( ! F_113 ( V_142 ) )
goto V_353;
V_76 = F_315 ( V_39 ) ;
switch ( V_291 ) {
case V_295 :
V_76 = true ;
case V_354 :
if ( F_316 ( V_39 ) )
goto V_353;
if ( ! V_352 && F_338 ( V_142 ) )
goto V_353;
break;
case V_347 :
if ( ! F_315 ( V_39 ) ) {
if ( V_39 -> V_342 && ! F_339 ( V_39 ) )
goto V_353;
} else if ( F_316 ( V_39 ) )
goto V_353;
break;
default:
break;
}
F_73 ( V_2 , V_39 , V_76 , - V_77 ) ;
F_311 ( V_142 ) ;
F_248 ( V_142 ) ;
F_87 ( V_2 , V_39 ) ;
if ( V_156 && V_291 == V_347 ) {
F_70 ( V_2 , true ) ;
F_21 ( & V_2 -> V_12 ) ;
}
if ( ! V_352 && ! F_15 ( V_2 ) )
F_336 ( V_2 , V_77 , V_291 ) ;
return V_2 ;
V_353:
F_248 ( V_142 ) ;
return NULL ;
}
void F_340 ( struct V_39 * V_39 )
{
if ( F_316 ( V_39 ) )
return;
F_242 ( V_39 -> V_342 && ! F_315 ( V_39 ) , V_39 ) ;
if ( F_245 ( V_39 ) )
return;
F_337 ( V_39 , V_295 , false ) ;
}
void F_341 ( struct V_39 * V_39 )
{
F_242 ( F_316 ( V_39 ) , V_39 ) ;
F_242 ( V_39 -> V_342 , V_39 ) ;
F_337 ( V_39 , V_344 , false ) ;
}
void F_342 ( void )
{
V_25 -> V_348 . V_349 ++ ;
if ( V_25 -> V_348 . V_349 == 1 ) {
V_25 -> V_348 . V_2 = NULL ;
V_25 -> V_348 . V_77 = 0 ;
V_25 -> V_348 . V_351 = 0 ;
}
}
void F_343 ( void )
{
struct V_345 * V_281 = & V_25 -> V_348 ;
if ( ! V_281 -> V_349 )
return;
V_281 -> V_349 -- ;
if ( V_281 -> V_349 )
return;
if ( ! V_281 -> V_2 )
return;
if ( V_281 -> V_77 )
F_208 ( & V_281 -> V_2 -> V_59 ,
V_281 -> V_77 * V_250 ) ;
if ( V_281 -> V_351 )
F_208 ( & V_281 -> V_2 -> V_157 ,
V_281 -> V_351 * V_250 ) ;
F_195 ( V_281 -> V_2 ) ;
V_281 -> V_2 = NULL ;
}
void
F_344 ( struct V_39 * V_39 , T_6 V_289 , bool V_355 )
{
struct V_1 * V_2 ;
int V_291 = V_347 ;
if ( ! V_355 )
V_291 = V_354 ;
V_2 = F_337 ( V_39 , V_291 , false ) ;
if ( V_156 && V_355 && V_2 )
F_345 ( V_289 , F_16 ( V_2 ) ) ;
}
void F_332 ( T_6 V_289 )
{
struct V_1 * V_2 ;
unsigned short V_16 ;
if ( ! V_156 )
return;
V_16 = F_345 ( V_289 , 0 ) ;
F_22 () ;
V_2 = F_240 ( V_16 ) ;
if ( V_2 ) {
if ( ! F_15 ( V_2 ) )
F_208 ( & V_2 -> V_157 , V_250 ) ;
F_70 ( V_2 , false ) ;
F_29 ( & V_2 -> V_12 ) ;
}
F_26 () ;
}
static int F_346 ( T_6 V_356 ,
struct V_1 * V_162 , struct V_1 * V_163 )
{
unsigned short V_357 , V_358 ;
V_357 = F_16 ( V_162 ) ;
V_358 = F_16 ( V_163 ) ;
if ( F_347 ( V_356 , V_357 , V_358 ) == V_357 ) {
F_70 ( V_162 , false ) ;
F_70 ( V_163 , true ) ;
F_21 ( & V_163 -> V_12 ) ;
return 0 ;
}
return - V_337 ;
}
static inline int F_346 ( T_6 V_356 ,
struct V_1 * V_162 , struct V_1 * V_163 )
{
return - V_337 ;
}
void F_348 ( struct V_39 * V_39 , struct V_39 * V_359 ,
struct V_1 * * V_343 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_77 = 1 ;
struct V_141 * V_142 ;
enum V_290 V_291 ;
* V_343 = NULL ;
if ( F_104 () )
return;
if ( F_75 ( V_39 ) )
V_77 <<= F_327 ( V_39 ) ;
V_142 = F_111 ( V_39 ) ;
F_244 ( V_142 ) ;
if ( F_113 ( V_142 ) ) {
V_2 = V_142 -> V_1 ;
F_21 ( & V_2 -> V_12 ) ;
if ( F_315 ( V_39 ) )
F_349 ( V_142 ) ;
}
F_248 ( V_142 ) ;
if ( ! V_2 )
return;
* V_343 = V_2 ;
if ( F_315 ( V_39 ) )
V_291 = V_295 ;
else
V_291 = V_344 ;
F_249 ( V_2 , V_359 , V_77 , V_291 , false ) ;
}
void F_350 ( struct V_1 * V_2 ,
struct V_39 * V_360 , struct V_39 * V_359 , bool V_361 )
{
struct V_39 * V_362 , * V_363 ;
struct V_141 * V_142 ;
bool V_76 ;
if ( ! V_2 )
return;
if ( ! V_361 ) {
V_362 = V_360 ;
V_363 = V_359 ;
} else {
V_362 = V_359 ;
V_363 = V_360 ;
}
V_76 = F_315 ( V_362 ) ;
F_337 ( V_363 ,
V_76 ? V_295
: V_344 ,
true ) ;
F_29 ( & V_2 -> V_12 ) ;
V_142 = F_111 ( V_360 ) ;
F_244 ( V_142 ) ;
F_351 ( V_142 ) ;
F_248 ( V_142 ) ;
if ( V_76 )
F_340 ( V_362 ) ;
}
void F_352 ( struct V_39 * V_360 ,
struct V_39 * V_359 )
{
struct V_1 * V_2 = NULL ;
struct V_141 * V_142 ;
enum V_290 type = V_344 ;
if ( F_104 () )
return;
V_142 = F_111 ( V_360 ) ;
F_244 ( V_142 ) ;
if ( F_113 ( V_142 ) ) {
V_2 = V_142 -> V_1 ;
F_73 ( V_2 , V_360 , false , - 1 ) ;
F_311 ( V_142 ) ;
}
F_248 ( V_142 ) ;
if ( ! V_2 )
return;
F_249 ( V_2 , V_359 , 1 , type , true ) ;
}
static struct V_141 * F_353 ( struct V_39 * V_39 )
{
struct V_141 * V_142 ;
V_142 = F_111 ( V_39 ) ;
if ( F_229 ( V_142 ) && F_113 ( V_142 ) )
return V_142 ;
return NULL ;
}
bool F_354 ( struct V_39 * V_39 )
{
if ( F_104 () )
return false ;
return F_353 ( V_39 ) != NULL ;
}
void F_355 ( struct V_39 * V_39 )
{
struct V_141 * V_142 ;
V_142 = F_353 ( V_39 ) ;
if ( V_142 ) {
F_356 ( L_12 ,
V_142 , V_142 -> V_115 , V_142 -> V_1 ) ;
}
}
static int F_357 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_364 ;
T_2 V_365 , V_366 ;
int V_145 = 0 ;
int V_367 = F_151 ( V_2 ) ;
T_2 V_368 , V_369 ;
int V_370 ;
V_364 = V_283 * V_367 ;
V_369 = F_36 ( & V_2 -> V_59 , V_32 ) ;
V_370 = 0 ;
while ( V_364 ) {
if ( F_358 ( V_25 ) ) {
V_145 = - V_288 ;
break;
}
F_143 ( & V_371 ) ;
V_365 = F_36 ( & V_2 -> V_157 , V_172 ) ;
if ( V_365 < V_66 ) {
V_145 = - V_337 ;
F_150 ( & V_371 ) ;
break;
}
V_366 = F_36 ( & V_2 -> V_59 , V_172 ) ;
if ( V_366 < V_66 )
V_370 = 1 ;
V_145 = F_359 ( & V_2 -> V_59 , V_66 ) ;
if ( ! V_145 ) {
if ( V_365 == V_66 )
V_2 -> V_202 = true ;
else
V_2 -> V_202 = false ;
}
F_150 ( & V_371 ) ;
if ( ! V_145 )
break;
F_166 ( V_2 , V_317 ,
V_201 ) ;
V_368 = F_36 ( & V_2 -> V_59 , V_32 ) ;
if ( V_368 >= V_369 )
V_364 -- ;
else
V_369 = V_368 ;
}
if ( ! V_145 && V_370 )
F_195 ( V_2 ) ;
return V_145 ;
}
static int F_360 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_364 ;
T_2 V_366 , V_365 , V_369 , V_368 ;
int V_367 = F_151 ( V_2 ) ;
int V_145 = - V_336 ;
int V_370 = 0 ;
V_364 = V_367 * V_283 ;
V_369 = F_36 ( & V_2 -> V_157 , V_32 ) ;
while ( V_364 ) {
if ( F_358 ( V_25 ) ) {
V_145 = - V_288 ;
break;
}
F_143 ( & V_371 ) ;
V_366 = F_36 ( & V_2 -> V_59 , V_172 ) ;
if ( V_366 > V_66 ) {
V_145 = - V_337 ;
F_150 ( & V_371 ) ;
break;
}
V_365 = F_36 ( & V_2 -> V_157 , V_172 ) ;
if ( V_365 < V_66 )
V_370 = 1 ;
V_145 = F_359 ( & V_2 -> V_157 , V_66 ) ;
if ( ! V_145 ) {
if ( V_366 == V_66 )
V_2 -> V_202 = true ;
else
V_2 -> V_202 = false ;
}
F_150 ( & V_371 ) ;
if ( ! V_145 )
break;
F_166 ( V_2 , V_317 ,
V_200 |
V_201 ) ;
V_368 = F_36 ( & V_2 -> V_157 , V_32 ) ;
if ( V_368 >= V_369 )
V_364 -- ;
else
V_369 = V_368 ;
}
if ( ! V_145 && V_370 )
F_195 ( V_2 ) ;
return V_145 ;
}
unsigned long F_361 ( struct V_34 * V_34 , int V_182 ,
T_3 V_181 ,
unsigned long * V_212 )
{
unsigned long V_372 = 0 ;
struct V_33 * V_44 , * V_373 = NULL ;
unsigned long V_374 ;
int V_199 = 0 ;
struct V_40 * V_45 ;
unsigned long long V_58 ;
unsigned long V_214 ;
if ( V_182 > 0 )
return 0 ;
V_45 = F_45 ( F_39 ( V_34 ) , F_40 ( V_34 ) ) ;
do {
if ( V_373 )
V_44 = V_373 ;
else
V_44 = F_63 ( V_45 ) ;
if ( ! V_44 )
break;
V_214 = 0 ;
V_374 = F_182 ( V_44 -> V_2 , V_34 ,
V_181 , & V_214 ) ;
V_372 += V_374 ;
* V_212 += V_214 ;
F_54 ( & V_45 -> V_57 ) ;
V_373 = NULL ;
if ( ! V_374 ) {
do {
V_373 =
F_61 ( V_45 ) ;
if ( V_373 == V_44 )
F_29 ( & V_373 -> V_2 -> V_12 ) ;
else
break;
} while ( 1 );
}
F_51 ( V_44 , V_45 ) ;
V_58 = F_58 ( & V_44 -> V_2 -> V_59 ) ;
F_47 ( V_44 , V_45 , V_58 ) ;
F_55 ( & V_45 -> V_57 ) ;
F_29 ( & V_44 -> V_2 -> V_12 ) ;
V_199 ++ ;
if ( ! V_372 &&
( V_373 == NULL ||
V_199 > V_375 ) )
break;
} while ( ! V_372 );
if ( V_373 )
F_29 ( & V_373 -> V_2 -> V_12 ) ;
return V_372 ;
}
static void F_362 ( struct V_1 * V_2 ,
int V_210 , int V_36 , enum V_85 V_86 )
{
struct V_84 * V_84 ;
unsigned long V_115 ;
struct V_376 * V_321 ;
struct V_39 * V_377 ;
struct V_34 * V_34 ;
V_34 = & F_363 ( V_210 ) -> V_378 [ V_36 ] ;
V_84 = F_109 ( V_34 , V_2 ) ;
V_321 = & V_84 -> V_379 [ V_86 ] ;
V_377 = NULL ;
do {
struct V_141 * V_142 ;
struct V_39 * V_39 ;
F_138 ( & V_34 -> V_294 , V_115 ) ;
if ( F_364 ( V_321 ) ) {
F_140 ( & V_34 -> V_294 , V_115 ) ;
break;
}
V_39 = F_365 ( V_321 -> V_124 , struct V_39 , V_86 ) ;
if ( V_377 == V_39 ) {
F_366 ( & V_39 -> V_86 , V_321 ) ;
V_377 = NULL ;
F_140 ( & V_34 -> V_294 , V_115 ) ;
continue;
}
F_140 ( & V_34 -> V_294 , V_115 ) ;
V_142 = F_111 ( V_39 ) ;
if ( F_318 ( V_39 , V_142 , V_2 ) ) {
V_377 = V_39 ;
} else
V_377 = NULL ;
F_367 () ;
} while ( ! F_364 ( V_321 ) );
}
static void F_368 ( struct V_1 * V_2 )
{
int V_210 , V_36 ;
T_2 V_380 ;
do {
F_369 () ;
F_223 ( V_2 ) ;
F_127 ( V_2 ) ;
F_83 (node, N_MEMORY) {
for ( V_36 = 0 ; V_36 < V_60 ; V_36 ++ ) {
enum V_85 V_86 ;
F_80 (lru) {
F_362 ( V_2 ,
V_210 , V_36 , V_86 ) ;
}
}
}
F_129 ( V_2 ) ;
F_195 ( V_2 ) ;
F_367 () ;
V_380 = F_36 ( & V_2 -> V_59 , V_32 ) -
F_36 ( & V_2 -> V_31 , V_32 ) ;
} while ( V_380 > 0 );
}
static inline bool F_370 ( struct V_1 * V_2 )
{
bool V_145 ;
F_284 ( & V_381 ) ;
F_22 () ;
V_145 = F_371 ( NULL , & V_2 -> V_12 ) ;
F_26 () ;
return V_145 ;
}
static int F_372 ( struct V_1 * V_2 )
{
int V_382 = V_283 ;
F_369 () ;
while ( V_382 && F_36 ( & V_2 -> V_59 , V_32 ) > 0 ) {
int V_383 ;
if ( F_358 ( V_25 ) )
return - V_288 ;
V_383 = F_168 ( V_2 , V_317 ,
false ) ;
if ( ! V_383 ) {
V_382 -- ;
F_373 ( V_384 , V_385 / 10 ) ;
}
}
return 0 ;
}
static T_8 F_374 ( struct V_386 * V_387 ,
char * V_388 , T_7 V_389 ,
T_9 V_390 )
{
struct V_1 * V_2 = F_11 ( F_375 ( V_387 ) ) ;
if ( F_15 ( V_2 ) )
return - V_337 ;
return F_372 ( V_2 ) ? : V_389 ;
}
static T_2 F_376 ( struct V_10 * V_12 ,
struct V_391 * V_392 )
{
return F_11 ( V_12 ) -> V_127 ;
}
static int F_377 ( struct V_10 * V_12 ,
struct V_391 * V_392 , T_2 V_66 )
{
int V_393 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_394 = F_11 ( V_2 -> V_12 . V_50 ) ;
F_143 ( & V_381 ) ;
if ( V_2 -> V_127 == V_66 )
goto V_136;
if ( ( ! V_394 || ! V_394 -> V_127 ) &&
( V_66 == 1 || V_66 == 0 ) ) {
if ( ! F_370 ( V_2 ) )
V_2 -> V_127 = V_66 ;
else
V_393 = - V_336 ;
} else
V_393 = - V_337 ;
V_136:
F_150 ( & V_381 ) ;
return V_393 ;
}
static unsigned long F_378 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
struct V_1 * V_119 ;
long V_66 = 0 ;
F_147 (iter, memcg)
V_66 += F_64 ( V_119 , V_65 ) ;
if ( V_66 < 0 )
V_66 = 0 ;
return V_66 ;
}
static inline T_2 F_379 ( struct V_1 * V_2 , bool V_395 )
{
T_2 V_66 ;
if ( ! F_15 ( V_2 ) ) {
if ( ! V_395 )
return F_36 ( & V_2 -> V_59 , V_32 ) ;
else
return F_36 ( & V_2 -> V_157 , V_32 ) ;
}
V_66 = F_378 ( V_2 , V_79 ) ;
V_66 += F_378 ( V_2 , V_78 ) ;
if ( V_395 )
V_66 += F_378 ( V_2 , V_73 ) ;
return V_66 << V_154 ;
}
static T_2 F_380 ( struct V_10 * V_12 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_2 V_66 ;
int V_396 ;
enum V_397 type ;
type = F_381 ( V_392 -> V_238 ) ;
V_396 = F_382 ( V_392 -> V_238 ) ;
switch ( type ) {
case V_398 :
if ( V_396 == V_32 )
V_66 = F_379 ( V_2 , false ) ;
else
V_66 = F_36 ( & V_2 -> V_59 , V_396 ) ;
break;
case V_399 :
if ( V_396 == V_32 )
V_66 = F_379 ( V_2 , true ) ;
else
V_66 = F_36 ( & V_2 -> V_157 , V_396 ) ;
break;
case V_400 :
V_66 = F_36 ( & V_2 -> V_31 , V_396 ) ;
break;
default:
F_108 () ;
}
return V_66 ;
}
static int F_383 ( struct V_1 * V_2 ,
unsigned long long V_179 )
{
int V_401 = 0 ;
int V_402 ;
if ( F_3 ( V_2 ) )
return 0 ;
F_291 () ;
F_143 ( & V_381 ) ;
if ( F_384 ( V_2 -> V_12 . V_144 ) ||
( V_2 -> V_127 && F_370 ( V_2 ) ) )
V_401 = - V_336 ;
F_150 ( & V_381 ) ;
if ( V_401 )
goto V_136;
V_402 = F_385 ( & V_29 ,
0 , V_311 , V_317 ) ;
if ( V_402 < 0 ) {
V_401 = V_402 ;
goto V_136;
}
F_143 ( & V_306 ) ;
V_401 = F_386 ( V_402 + 1 ) ;
F_150 ( & V_306 ) ;
if ( V_401 )
goto V_403;
V_2 -> V_30 = V_402 ;
F_198 ( & V_2 -> V_322 ) ;
V_401 = F_359 ( & V_2 -> V_31 , V_179 ) ;
F_79 ( V_401 ) ;
F_387 ( & V_28 ) ;
F_1 ( V_2 ) ;
V_136:
F_292 () ;
return V_401 ;
V_403:
F_35 ( & V_29 , V_402 ) ;
goto V_136;
}
static int F_388 ( struct V_1 * V_2 ,
unsigned long long V_179 )
{
int V_145 ;
F_143 ( & V_404 ) ;
V_145 = F_383 ( V_2 , V_179 ) ;
F_150 ( & V_404 ) ;
return V_145 ;
}
static int F_389 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_145 ;
if ( ! F_3 ( V_2 ) )
V_145 = F_388 ( V_2 , V_66 ) ;
else
V_145 = F_359 ( & V_2 -> V_31 , V_66 ) ;
return V_145 ;
}
static int F_390 ( struct V_1 * V_2 )
{
int V_145 = 0 ;
struct V_1 * V_50 = F_57 ( V_2 ) ;
if ( ! V_50 )
return 0 ;
F_143 ( & V_404 ) ;
if ( F_3 ( V_50 ) )
V_145 = F_383 ( V_2 , V_405 ) ;
F_150 ( & V_404 ) ;
return V_145 ;
}
static int F_389 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
return - V_337 ;
}
static T_8 F_391 ( struct V_386 * V_387 ,
char * V_388 , T_7 V_389 , T_9 V_390 )
{
struct V_1 * V_2 = F_11 ( F_375 ( V_387 ) ) ;
enum V_397 type ;
int V_396 ;
unsigned long long V_66 ;
int V_145 ;
V_388 = F_392 ( V_388 ) ;
type = F_381 ( F_393 ( V_387 ) -> V_238 ) ;
V_396 = F_382 ( F_393 ( V_387 ) -> V_238 ) ;
switch ( V_396 ) {
case V_172 :
if ( F_15 ( V_2 ) ) {
V_145 = - V_337 ;
break;
}
V_145 = F_394 ( V_388 , & V_66 ) ;
if ( V_145 )
break;
if ( type == V_398 )
V_145 = F_357 ( V_2 , V_66 ) ;
else if ( type == V_399 )
V_145 = F_360 ( V_2 , V_66 ) ;
else if ( type == V_400 )
V_145 = F_389 ( V_2 , V_66 ) ;
else
return - V_337 ;
break;
case V_406 :
V_145 = F_394 ( V_388 , & V_66 ) ;
if ( V_145 )
break;
if ( type == V_398 )
V_145 = F_395 ( & V_2 -> V_59 , V_66 ) ;
else
V_145 = - V_337 ;
break;
default:
V_145 = - V_337 ;
break;
}
return V_145 ? : V_389 ;
}
static void F_396 ( struct V_1 * V_2 ,
unsigned long long * V_407 , unsigned long long * V_408 )
{
unsigned long long V_409 , V_410 , V_325 ;
V_409 = F_36 ( & V_2 -> V_59 , V_172 ) ;
V_410 = F_36 ( & V_2 -> V_157 , V_172 ) ;
if ( ! V_2 -> V_127 )
goto V_136;
while ( V_2 -> V_12 . V_50 ) {
V_2 = F_11 ( V_2 -> V_12 . V_50 ) ;
if ( ! V_2 -> V_127 )
break;
V_325 = F_36 ( & V_2 -> V_59 , V_172 ) ;
V_409 = F_125 ( V_409 , V_325 ) ;
V_325 = F_36 ( & V_2 -> V_157 , V_172 ) ;
V_410 = F_125 ( V_410 , V_325 ) ;
}
V_136:
* V_407 = V_409 ;
* V_408 = V_410 ;
}
static T_8 F_397 ( struct V_386 * V_387 , char * V_388 ,
T_7 V_389 , T_9 V_390 )
{
struct V_1 * V_2 = F_11 ( F_375 ( V_387 ) ) ;
int V_396 ;
enum V_397 type ;
type = F_381 ( F_393 ( V_387 ) -> V_238 ) ;
V_396 = F_382 ( F_393 ( V_387 ) -> V_238 ) ;
switch ( V_396 ) {
case V_411 :
if ( type == V_398 )
F_398 ( & V_2 -> V_59 ) ;
else if ( type == V_399 )
F_398 ( & V_2 -> V_157 ) ;
else if ( type == V_400 )
F_398 ( & V_2 -> V_31 ) ;
else
return - V_337 ;
break;
case V_173 :
if ( type == V_398 )
F_399 ( & V_2 -> V_59 ) ;
else if ( type == V_399 )
F_399 ( & V_2 -> V_157 ) ;
else if ( type == V_400 )
F_399 ( & V_2 -> V_31 ) ;
else
return - V_337 ;
break;
}
return V_389 ;
}
static T_2 F_400 ( struct V_10 * V_12 ,
struct V_391 * V_392 )
{
return F_11 ( V_12 ) -> V_412 ;
}
static int F_401 ( struct V_10 * V_12 ,
struct V_391 * V_392 , T_2 V_66 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_66 >= ( 1 << V_413 ) )
return - V_337 ;
V_2 -> V_412 = V_66 ;
return 0 ;
}
static int F_401 ( struct V_10 * V_12 ,
struct V_391 * V_392 , T_2 V_66 )
{
return - V_414 ;
}
static int F_402 ( struct V_301 * V_302 , void * V_303 )
{
struct V_415 {
const char * V_396 ;
unsigned int V_88 ;
};
static const struct V_415 V_416 [] = {
{ L_13 , V_417 } ,
{ L_14 , V_204 } ,
{ L_15 , V_205 } ,
{ L_16 , F_81 (LRU_UNEVICTABLE) } ,
} ;
const struct V_415 * V_68 ;
int V_35 ;
unsigned long V_89 ;
struct V_1 * V_2 = F_11 ( F_264 ( V_302 ) ) ;
for ( V_68 = V_416 ; V_68 < V_416 + F_403 ( V_416 ) ; V_68 ++ ) {
V_89 = F_82 ( V_2 , V_68 -> V_88 ) ;
F_404 ( V_302 , L_17 , V_68 -> V_396 , V_89 ) ;
F_83 (nid, N_MEMORY) {
V_89 = F_78 ( V_2 , V_35 ,
V_68 -> V_88 ) ;
F_404 ( V_302 , L_18 , V_35 , V_89 ) ;
}
F_405 ( V_302 , '\n' ) ;
}
for ( V_68 = V_416 ; V_68 < V_416 + F_403 ( V_416 ) ; V_68 ++ ) {
struct V_1 * V_119 ;
V_89 = 0 ;
F_147 (iter, memcg)
V_89 += F_82 ( V_119 , V_68 -> V_88 ) ;
F_404 ( V_302 , L_19 , V_68 -> V_396 , V_89 ) ;
F_83 (nid, N_MEMORY) {
V_89 = 0 ;
F_147 (iter, memcg)
V_89 += F_78 (
V_119 , V_35 , V_68 -> V_88 ) ;
F_404 ( V_302 , L_18 , V_35 , V_89 ) ;
}
F_405 ( V_302 , '\n' ) ;
}
return 0 ;
}
static inline void F_406 ( void )
{
F_407 ( F_403 ( V_177 ) != V_176 ) ;
}
static int F_408 ( struct V_301 * V_302 , void * V_303 )
{
struct V_1 * V_2 = F_11 ( F_264 ( V_302 ) ) ;
struct V_1 * V_418 ;
unsigned int V_171 ;
for ( V_171 = 0 ; V_171 < V_174 ; V_171 ++ ) {
if ( V_171 == V_73 && ! V_156 )
continue;
F_404 ( V_302 , L_20 , V_175 [ V_171 ] ,
F_64 ( V_2 , V_171 ) * V_250 ) ;
}
for ( V_171 = 0 ; V_171 < V_258 ; V_171 ++ )
F_404 ( V_302 , L_21 , V_419 [ V_171 ] ,
F_72 ( V_2 , V_171 ) ) ;
for ( V_171 = 0 ; V_171 < V_176 ; V_171 ++ )
F_404 ( V_302 , L_21 , V_177 [ V_171 ] ,
F_82 ( V_2 , F_81 ( V_171 ) ) * V_250 ) ;
{
unsigned long long V_179 , V_408 ;
F_396 ( V_2 , & V_179 , & V_408 ) ;
F_404 ( V_302 , L_22 , V_179 ) ;
if ( V_156 )
F_404 ( V_302 , L_23 ,
V_408 ) ;
}
for ( V_171 = 0 ; V_171 < V_174 ; V_171 ++ ) {
long long V_66 = 0 ;
if ( V_171 == V_73 && ! V_156 )
continue;
F_147 (mi, memcg)
V_66 += F_64 ( V_418 , V_171 ) * V_250 ;
F_404 ( V_302 , L_24 , V_175 [ V_171 ] , V_66 ) ;
}
for ( V_171 = 0 ; V_171 < V_258 ; V_171 ++ ) {
unsigned long long V_66 = 0 ;
F_147 (mi, memcg)
V_66 += F_72 ( V_418 , V_171 ) ;
F_404 ( V_302 , L_25 ,
V_419 [ V_171 ] , V_66 ) ;
}
for ( V_171 = 0 ; V_171 < V_176 ; V_171 ++ ) {
unsigned long long V_66 = 0 ;
F_147 (mi, memcg)
V_66 += F_82 ( V_418 , F_81 ( V_171 ) ) * V_250 ;
F_404 ( V_302 , L_25 , V_177 [ V_171 ] , V_66 ) ;
}
#ifdef F_409
{
int V_35 , V_36 ;
struct V_33 * V_44 ;
struct V_420 * V_421 ;
unsigned long V_422 [ 2 ] = { 0 , 0 } ;
unsigned long V_423 [ 2 ] = { 0 , 0 } ;
F_410 (nid)
for ( V_36 = 0 ; V_36 < V_60 ; V_36 ++ ) {
V_44 = & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
V_421 = & V_44 -> V_84 . V_424 ;
V_422 [ 0 ] += V_421 -> V_422 [ 0 ] ;
V_422 [ 1 ] += V_421 -> V_422 [ 1 ] ;
V_423 [ 0 ] += V_421 -> V_423 [ 0 ] ;
V_423 [ 1 ] += V_421 -> V_423 [ 1 ] ;
}
F_404 ( V_302 , L_26 , V_422 [ 0 ] ) ;
F_404 ( V_302 , L_27 , V_422 [ 1 ] ) ;
F_404 ( V_302 , L_28 , V_423 [ 0 ] ) ;
F_404 ( V_302 , L_29 , V_423 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_411 ( struct V_10 * V_12 ,
struct V_391 * V_392 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
return F_126 ( V_2 ) ;
}
static int F_412 ( struct V_10 * V_12 ,
struct V_391 * V_392 , T_2 V_66 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_66 > 100 )
return - V_337 ;
if ( V_12 -> V_50 )
V_2 -> V_159 = V_66 ;
else
V_158 = V_66 ;
return 0 ;
}
static void F_413 ( struct V_1 * V_2 , bool V_395 )
{
struct V_425 * V_426 ;
T_2 V_380 ;
int V_171 ;
F_22 () ;
if ( ! V_395 )
V_426 = F_95 ( V_2 -> V_427 . V_428 ) ;
else
V_426 = F_95 ( V_2 -> V_429 . V_428 ) ;
if ( ! V_426 )
goto V_164;
V_380 = F_379 ( V_2 , V_395 ) ;
V_171 = V_426 -> V_430 ;
for (; V_171 >= 0 && F_89 ( V_426 -> V_431 [ V_171 ] . V_432 > V_380 ) ; V_171 -- )
F_414 ( V_426 -> V_431 [ V_171 ] . V_433 , 1 ) ;
V_171 ++ ;
for (; V_171 < V_426 -> V_308 && F_89 ( V_426 -> V_431 [ V_171 ] . V_432 <= V_380 ) ; V_171 ++ )
F_414 ( V_426 -> V_431 [ V_171 ] . V_433 , 1 ) ;
V_426 -> V_430 = V_171 - 1 ;
V_164:
F_26 () ;
}
static void F_91 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_413 ( V_2 , false ) ;
if ( V_156 )
F_413 ( V_2 , true ) ;
V_2 = F_57 ( V_2 ) ;
}
}
static int F_415 ( const void * V_434 , const void * V_435 )
{
const struct F_91 * V_436 = V_434 ;
const struct F_91 * V_437 = V_435 ;
if ( V_436 -> V_432 > V_437 -> V_432 )
return 1 ;
if ( V_436 -> V_432 < V_437 -> V_432 )
return - 1 ;
return 0 ;
}
static int F_416 ( struct V_1 * V_2 )
{
struct V_438 * V_439 ;
F_54 ( & V_216 ) ;
F_266 (ev, &memcg->oom_notify, list)
F_414 ( V_439 -> V_433 , 1 ) ;
F_55 ( & V_216 ) ;
return 0 ;
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_147 (iter, memcg)
F_416 ( V_119 ) ;
}
static int F_417 ( struct V_1 * V_2 ,
struct V_440 * V_433 , const char * args , enum V_397 type )
{
struct V_441 * V_427 ;
struct V_425 * V_442 ;
T_2 V_432 , V_380 ;
int V_171 , V_308 , V_145 ;
V_145 = F_394 ( args , & V_432 ) ;
if ( V_145 )
return V_145 ;
F_143 ( & V_2 -> V_443 ) ;
if ( type == V_398 )
V_427 = & V_2 -> V_427 ;
else if ( type == V_399 )
V_427 = & V_2 -> V_429 ;
else
F_108 () ;
V_380 = F_379 ( V_2 , type == V_399 ) ;
if ( V_427 -> V_428 )
F_413 ( V_2 , type == V_399 ) ;
V_308 = V_427 -> V_428 ? V_427 -> V_428 -> V_308 + 1 : 1 ;
V_442 = F_300 ( sizeof( * V_442 ) + V_308 * sizeof( struct F_91 ) ,
V_317 ) ;
if ( ! V_442 ) {
V_145 = - V_287 ;
goto V_164;
}
V_442 -> V_308 = V_308 ;
if ( V_427 -> V_428 ) {
memcpy ( V_442 -> V_431 , V_427 -> V_428 -> V_431 , ( V_308 - 1 ) *
sizeof( struct F_91 ) ) ;
}
V_442 -> V_431 [ V_308 - 1 ] . V_433 = V_433 ;
V_442 -> V_431 [ V_308 - 1 ] . V_432 = V_432 ;
F_418 ( V_442 -> V_431 , V_308 , sizeof( struct F_91 ) ,
F_415 , NULL ) ;
V_442 -> V_430 = - 1 ;
for ( V_171 = 0 ; V_171 < V_308 ; V_171 ++ ) {
if ( V_442 -> V_431 [ V_171 ] . V_432 <= V_380 ) {
++ V_442 -> V_430 ;
} else
break;
}
F_282 ( V_427 -> V_444 ) ;
V_427 -> V_444 = V_427 -> V_428 ;
F_277 ( V_427 -> V_428 , V_442 ) ;
F_128 () ;
V_164:
F_150 ( & V_2 -> V_443 ) ;
return V_145 ;
}
static int F_419 ( struct V_1 * V_2 ,
struct V_440 * V_433 , const char * args )
{
return F_417 ( V_2 , V_433 , args , V_398 ) ;
}
static int F_420 ( struct V_1 * V_2 ,
struct V_440 * V_433 , const char * args )
{
return F_417 ( V_2 , V_433 , args , V_399 ) ;
}
static void F_421 ( struct V_1 * V_2 ,
struct V_440 * V_433 , enum V_397 type )
{
struct V_441 * V_427 ;
struct V_425 * V_442 ;
T_2 V_380 ;
int V_171 , V_445 , V_308 ;
F_143 ( & V_2 -> V_443 ) ;
if ( type == V_398 )
V_427 = & V_2 -> V_427 ;
else if ( type == V_399 )
V_427 = & V_2 -> V_429 ;
else
F_108 () ;
if ( ! V_427 -> V_428 )
goto V_164;
V_380 = F_379 ( V_2 , type == V_399 ) ;
F_413 ( V_2 , type == V_399 ) ;
V_308 = 0 ;
for ( V_171 = 0 ; V_171 < V_427 -> V_428 -> V_308 ; V_171 ++ ) {
if ( V_427 -> V_428 -> V_431 [ V_171 ] . V_433 != V_433 )
V_308 ++ ;
}
V_442 = V_427 -> V_444 ;
if ( ! V_308 ) {
F_282 ( V_442 ) ;
V_442 = NULL ;
goto V_446;
}
V_442 -> V_308 = V_308 ;
V_442 -> V_430 = - 1 ;
for ( V_171 = 0 , V_445 = 0 ; V_171 < V_427 -> V_428 -> V_308 ; V_171 ++ ) {
if ( V_427 -> V_428 -> V_431 [ V_171 ] . V_433 == V_433 )
continue;
V_442 -> V_431 [ V_445 ] = V_427 -> V_428 -> V_431 [ V_171 ] ;
if ( V_442 -> V_431 [ V_445 ] . V_432 <= V_380 ) {
++ V_442 -> V_430 ;
}
V_445 ++ ;
}
V_446:
V_427 -> V_444 = V_427 -> V_428 ;
if ( ! V_442 ) {
F_282 ( V_427 -> V_444 ) ;
V_427 -> V_444 = NULL ;
}
F_277 ( V_427 -> V_428 , V_442 ) ;
F_128 () ;
V_164:
F_150 ( & V_2 -> V_443 ) ;
}
static void F_422 ( struct V_1 * V_2 ,
struct V_440 * V_433 )
{
return F_421 ( V_2 , V_433 , V_398 ) ;
}
static void F_423 ( struct V_1 * V_2 ,
struct V_440 * V_433 )
{
return F_421 ( V_2 , V_433 , V_399 ) ;
}
static int F_424 ( struct V_1 * V_2 ,
struct V_440 * V_433 , const char * args )
{
struct V_438 * V_447 ;
V_447 = F_300 ( sizeof( * V_447 ) , V_317 ) ;
if ( ! V_447 )
return - V_287 ;
F_54 ( & V_216 ) ;
V_447 -> V_433 = V_433 ;
F_287 ( & V_447 -> V_321 , & V_2 -> V_448 ) ;
if ( F_100 ( & V_2 -> V_220 ) )
F_414 ( V_433 , 1 ) ;
F_55 ( & V_216 ) ;
return 0 ;
}
static void F_425 ( struct V_1 * V_2 ,
struct V_440 * V_433 )
{
struct V_438 * V_439 , * V_325 ;
F_54 ( & V_216 ) ;
F_296 (ev, tmp, &memcg->oom_notify, list) {
if ( V_439 -> V_433 == V_433 ) {
F_289 ( & V_439 -> V_321 ) ;
F_282 ( V_439 ) ;
}
}
F_55 ( & V_216 ) ;
}
static int F_426 ( struct V_301 * V_449 , void * V_303 )
{
struct V_1 * V_2 = F_11 ( F_264 ( V_449 ) ) ;
F_404 ( V_449 , L_30 , V_2 -> V_241 ) ;
F_404 ( V_449 , L_31 , ( bool ) F_100 ( & V_2 -> V_220 ) ) ;
return 0 ;
}
static int F_427 ( struct V_10 * V_12 ,
struct V_391 * V_392 , T_2 V_66 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( ! V_12 -> V_50 || ! ( ( V_66 == 0 ) || ( V_66 == 1 ) ) )
return - V_337 ;
V_2 -> V_241 = V_66 ;
if ( ! V_66 )
F_195 ( V_2 ) ;
return 0 ;
}
static int F_428 ( struct V_1 * V_2 , struct V_450 * V_451 )
{
int V_145 ;
V_2 -> V_30 = - 1 ;
V_145 = F_390 ( V_2 ) ;
if ( V_145 )
return V_145 ;
return F_429 ( V_2 , V_451 ) ;
}
static void F_430 ( struct V_1 * V_2 )
{
F_431 ( V_2 ) ;
}
static void F_432 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_2 ) )
return;
F_21 ( & V_2 -> V_12 ) ;
F_5 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_31 , V_32 ) != 0 )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
static int F_428 ( struct V_1 * V_2 , struct V_450 * V_451 )
{
return 0 ;
}
static void F_430 ( struct V_1 * V_2 )
{
}
static void F_432 ( struct V_1 * V_2 )
{
}
static void F_433 ( struct V_251 * V_254 )
{
struct V_452 * V_447 =
F_12 ( V_254 , struct V_452 , remove ) ;
struct V_1 * V_2 = V_447 -> V_2 ;
F_434 ( V_447 -> V_453 , & V_447 -> V_166 ) ;
V_447 -> V_454 ( V_2 , V_447 -> V_433 ) ;
F_414 ( V_447 -> V_433 , 1 ) ;
F_435 ( V_447 -> V_433 ) ;
F_282 ( V_447 ) ;
F_29 ( & V_2 -> V_12 ) ;
}
static int F_436 ( T_4 * V_166 , unsigned V_221 ,
int V_222 , void * V_455 )
{
struct V_452 * V_447 =
F_12 ( V_166 , struct V_452 , V_166 ) ;
struct V_1 * V_2 = V_447 -> V_2 ;
unsigned long V_115 = ( unsigned long ) V_455 ;
if ( V_115 & V_456 ) {
F_54 ( & V_2 -> V_457 ) ;
if ( ! F_364 ( & V_447 -> V_321 ) ) {
F_437 ( & V_447 -> V_321 ) ;
F_301 ( & V_447 -> remove ) ;
}
F_55 ( & V_2 -> V_457 ) ;
}
return 0 ;
}
static void F_438 ( struct V_458 * V_458 ,
T_10 * V_453 , T_11 * V_459 )
{
struct V_452 * V_447 =
F_12 ( V_459 , struct V_452 , V_459 ) ;
V_447 -> V_453 = V_453 ;
F_439 ( V_453 , & V_447 -> V_166 ) ;
}
static T_8 F_440 ( struct V_386 * V_387 ,
char * V_388 , T_7 V_389 , T_9 V_390 )
{
struct V_10 * V_12 = F_375 ( V_387 ) ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_452 * V_447 ;
struct V_10 * V_460 ;
unsigned int V_461 , V_462 ;
struct V_463 V_464 ;
struct V_463 V_465 ;
const char * V_396 ;
char * V_466 ;
int V_145 ;
V_388 = F_392 ( V_388 ) ;
V_461 = F_441 ( V_388 , & V_466 , 10 ) ;
if ( * V_466 != ' ' )
return - V_337 ;
V_388 = V_466 + 1 ;
V_462 = F_441 ( V_388 , & V_466 , 10 ) ;
if ( ( * V_466 != ' ' ) && ( * V_466 != '\0' ) )
return - V_337 ;
V_388 = V_466 + 1 ;
V_447 = F_276 ( sizeof( * V_447 ) , V_317 ) ;
if ( ! V_447 )
return - V_287 ;
V_447 -> V_2 = V_2 ;
F_198 ( & V_447 -> V_321 ) ;
F_442 ( & V_447 -> V_459 , F_438 ) ;
F_443 ( & V_447 -> V_166 , F_436 ) ;
F_214 ( & V_447 -> remove , F_433 ) ;
V_464 = F_444 ( V_461 ) ;
if ( ! V_464 . V_458 ) {
V_145 = - V_467 ;
goto V_468;
}
V_447 -> V_433 = F_445 ( V_464 . V_458 ) ;
if ( F_446 ( V_447 -> V_433 ) ) {
V_145 = F_447 ( V_447 -> V_433 ) ;
goto V_469;
}
V_465 = F_444 ( V_462 ) ;
if ( ! V_465 . V_458 ) {
V_145 = - V_467 ;
goto V_470;
}
V_145 = F_448 ( F_449 ( V_465 . V_458 ) , V_471 ) ;
if ( V_145 < 0 )
goto V_472;
V_396 = V_465 . V_458 -> V_473 -> V_474 . V_396 ;
if ( ! strcmp ( V_396 , L_32 ) ) {
V_447 -> V_475 = F_419 ;
V_447 -> V_454 = F_422 ;
} else if ( ! strcmp ( V_396 , L_33 ) ) {
V_447 -> V_475 = F_424 ;
V_447 -> V_454 = F_425 ;
} else if ( ! strcmp ( V_396 , L_34 ) ) {
V_447 -> V_475 = V_476 ;
V_447 -> V_454 = V_477 ;
} else if ( ! strcmp ( V_396 , L_35 ) ) {
V_447 -> V_475 = F_420 ;
V_447 -> V_454 = F_423 ;
} else {
V_145 = - V_337 ;
goto V_472;
}
V_460 = F_450 ( V_465 . V_458 -> V_473 -> V_478 ,
& V_17 ) ;
V_145 = - V_337 ;
if ( F_446 ( V_460 ) )
goto V_472;
if ( V_460 != V_12 ) {
F_29 ( V_460 ) ;
goto V_472;
}
V_145 = V_447 -> V_475 ( V_2 , V_447 -> V_433 , V_388 ) ;
if ( V_145 )
goto V_479;
V_464 . V_458 -> V_480 -> V_481 ( V_464 . V_458 , & V_447 -> V_459 ) ;
F_54 ( & V_2 -> V_457 ) ;
F_287 ( & V_447 -> V_321 , & V_2 -> V_482 ) ;
F_55 ( & V_2 -> V_457 ) ;
F_451 ( V_465 ) ;
F_451 ( V_464 ) ;
return V_389 ;
V_479:
F_29 ( V_12 ) ;
V_472:
F_451 ( V_465 ) ;
V_470:
F_435 ( V_447 -> V_433 ) ;
V_469:
F_451 ( V_464 ) ;
V_468:
F_282 ( V_447 ) ;
return V_145 ;
}
static int F_452 ( struct V_1 * V_2 , int V_210 )
{
struct V_483 * V_484 ;
struct V_33 * V_44 ;
int V_34 , V_325 = V_210 ;
if ( ! F_453 ( V_210 , V_485 ) )
V_325 = - 1 ;
V_484 = F_454 ( sizeof( * V_484 ) , V_317 , V_325 ) ;
if ( ! V_484 )
return 1 ;
for ( V_34 = 0 ; V_34 < V_60 ; V_34 ++ ) {
V_44 = & V_484 -> V_38 [ V_34 ] ;
F_455 ( & V_44 -> V_84 ) ;
V_44 -> V_53 = 0 ;
V_44 -> V_52 = false ;
V_44 -> V_2 = V_2 ;
}
V_2 -> V_37 [ V_210 ] = V_484 ;
return 0 ;
}
static void F_456 ( struct V_1 * V_2 , int V_210 )
{
F_282 ( V_2 -> V_37 [ V_210 ] ) ;
}
static struct V_1 * F_457 ( void )
{
struct V_1 * V_2 ;
T_7 V_308 ;
V_308 = sizeof( struct V_1 ) ;
V_308 += V_90 * sizeof( struct V_483 * ) ;
V_2 = F_276 ( V_308 , V_317 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_68 = F_458 ( struct V_486 ) ;
if ( ! V_2 -> V_68 )
goto V_487;
F_459 ( & V_2 -> V_70 ) ;
return V_2 ;
V_487:
F_282 ( V_2 ) ;
return NULL ;
}
static void F_460 ( struct V_1 * V_2 )
{
int V_210 ;
F_59 ( V_2 ) ;
F_60 (node)
F_456 ( V_2 , V_210 ) ;
F_461 ( V_2 -> V_68 ) ;
F_37 ( V_2 ) ;
F_282 ( V_2 ) ;
}
struct V_1 * F_57 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 . V_50 )
return NULL ;
return F_230 ( V_2 -> V_59 . V_50 , V_59 ) ;
}
static void T_5 F_462 ( void )
{
struct V_488 * V_489 ;
struct V_40 * V_490 ;
int V_325 , V_210 , V_34 ;
F_60 (node) {
V_325 = V_210 ;
if ( ! F_453 ( V_210 , V_485 ) )
V_325 = - 1 ;
V_489 = F_454 ( sizeof( * V_489 ) , V_317 , V_325 ) ;
F_20 ( ! V_489 ) ;
V_41 . V_42 [ V_210 ] = V_489 ;
for ( V_34 = 0 ; V_34 < V_60 ; V_34 ++ ) {
V_490 = & V_489 -> V_43 [ V_34 ] ;
V_490 -> V_49 = V_491 ;
F_459 ( & V_490 -> V_57 ) ;
}
}
}
static struct V_10 * T_12
F_463 ( struct V_10 * V_492 )
{
struct V_1 * V_2 ;
long error = - V_287 ;
int V_210 ;
V_2 = F_457 () ;
if ( ! V_2 )
return F_464 ( error ) ;
F_60 (node)
if ( F_452 ( V_2 , V_210 ) )
goto V_493;
if ( V_492 == NULL ) {
V_14 = V_2 ;
F_465 ( & V_2 -> V_59 , NULL ) ;
F_465 ( & V_2 -> V_157 , NULL ) ;
F_465 ( & V_2 -> V_31 , NULL ) ;
}
V_2 -> V_211 = V_103 ;
F_198 ( & V_2 -> V_448 ) ;
V_2 -> V_412 = 0 ;
F_466 ( & V_2 -> V_443 ) ;
F_459 ( & V_2 -> V_169 ) ;
F_467 ( & V_2 -> V_13 ) ;
F_198 ( & V_2 -> V_482 ) ;
F_459 ( & V_2 -> V_457 ) ;
return & V_2 -> V_12 ;
V_493:
F_460 ( V_2 ) ;
return F_464 ( error ) ;
}
static int
F_468 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_50 = F_11 ( V_12 -> V_50 ) ;
if ( V_12 -> V_16 > V_494 )
return - V_495 ;
if ( ! V_50 )
return 0 ;
F_143 ( & V_381 ) ;
V_2 -> V_127 = V_50 -> V_127 ;
V_2 -> V_241 = V_50 -> V_241 ;
V_2 -> V_159 = F_126 ( V_50 ) ;
if ( V_50 -> V_127 ) {
F_465 ( & V_2 -> V_59 , & V_50 -> V_59 ) ;
F_465 ( & V_2 -> V_157 , & V_50 -> V_157 ) ;
F_465 ( & V_2 -> V_31 , & V_50 -> V_31 ) ;
} else {
F_465 ( & V_2 -> V_59 , NULL ) ;
F_465 ( & V_2 -> V_157 , NULL ) ;
F_465 ( & V_2 -> V_31 , NULL ) ;
if ( V_50 != V_14 )
V_17 . V_496 = true ;
}
F_150 ( & V_381 ) ;
return F_428 ( V_2 , & V_17 ) ;
}
static void F_469 ( struct V_1 * V_2 )
{
struct V_1 * V_50 = V_2 ;
while ( ( V_50 = F_57 ( V_50 ) ) )
F_98 ( V_50 ) ;
if ( ! V_14 -> V_127 )
F_98 ( V_14 ) ;
}
static void F_470 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_452 * V_447 , * V_325 ;
struct V_10 * V_119 ;
F_54 ( & V_2 -> V_457 ) ;
F_296 (event, tmp, &memcg->event_list, list) {
F_437 ( & V_447 -> V_321 ) ;
F_301 ( & V_447 -> remove ) ;
}
F_55 ( & V_2 -> V_457 ) ;
F_432 ( V_2 ) ;
F_469 ( V_2 ) ;
F_471 (iter, css)
F_368 ( F_11 ( V_119 ) ) ;
F_295 ( V_2 ) ;
F_472 ( & V_2 -> V_13 ) ;
}
static void F_473 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_368 ( V_2 ) ;
F_430 ( V_2 ) ;
F_460 ( V_2 ) ;
}
static int F_474 ( unsigned long V_69 )
{
int V_145 = 0 ;
int V_497 = V_498 ;
struct V_1 * V_2 = V_7 . V_163 ;
if ( F_15 ( V_2 ) ) {
V_7 . V_499 += V_69 ;
return V_145 ;
}
if ( V_69 > 1 ) {
struct V_271 * V_252 ;
if ( F_228 ( & V_2 -> V_59 , V_250 * V_69 , & V_252 ) )
goto V_500;
if ( V_156 && F_228 ( & V_2 -> V_157 ,
V_250 * V_69 , & V_252 ) ) {
F_208 ( & V_2 -> V_59 , V_250 * V_69 ) ;
goto V_500;
}
V_7 . V_499 += V_69 ;
return V_145 ;
}
V_500:
while ( V_69 -- ) {
if ( F_358 ( V_25 ) ) {
V_145 = - V_288 ;
break;
}
if ( ! V_497 -- ) {
V_497 = V_498 ;
F_367 () ;
}
V_145 = F_232 ( V_2 , V_317 , 1 , false ) ;
if ( V_145 )
return V_145 ;
V_7 . V_499 ++ ;
}
return V_145 ;
}
static struct V_39 * F_475 ( struct V_501 * V_502 ,
unsigned long V_503 , T_13 V_504 )
{
struct V_39 * V_39 = F_476 ( V_502 , V_503 , V_504 ) ;
if ( ! V_39 || ! F_316 ( V_39 ) )
return NULL ;
if ( F_315 ( V_39 ) ) {
if ( ! F_9 () )
return NULL ;
} else if ( ! F_10 () )
return NULL ;
if ( ! F_319 ( V_39 ) )
return NULL ;
return V_39 ;
}
static struct V_39 * F_477 ( struct V_501 * V_502 ,
unsigned long V_503 , T_13 V_504 , T_6 * V_356 )
{
struct V_39 * V_39 = NULL ;
T_6 V_289 = F_478 ( V_504 ) ;
if ( ! F_9 () || F_479 ( V_289 ) )
return NULL ;
V_39 = F_480 ( F_481 ( V_289 ) , V_289 . V_66 ) ;
if ( V_156 )
V_356 -> V_66 = V_289 . V_66 ;
return V_39 ;
}
static struct V_39 * F_477 ( struct V_501 * V_502 ,
unsigned long V_503 , T_13 V_504 , T_6 * V_356 )
{
return NULL ;
}
static struct V_39 * F_482 ( struct V_501 * V_502 ,
unsigned long V_503 , T_13 V_504 , T_6 * V_356 )
{
struct V_39 * V_39 = NULL ;
struct V_505 * V_342 ;
T_14 V_506 ;
if ( ! V_502 -> V_507 )
return NULL ;
if ( ! F_10 () )
return NULL ;
V_342 = V_502 -> V_507 -> V_508 ;
if ( F_483 ( V_504 ) )
V_506 = F_484 ( V_502 , V_503 ) ;
else
V_506 = F_485 ( V_504 ) ;
#ifdef F_486
if ( F_487 ( V_342 ) ) {
V_39 = F_488 ( V_342 , V_506 ) ;
if ( F_489 ( V_39 ) ) {
T_6 V_509 = F_490 ( V_39 ) ;
if ( V_156 )
* V_356 = V_509 ;
V_39 = F_480 ( F_481 ( V_509 ) , V_509 . V_66 ) ;
}
} else
V_39 = F_480 ( V_342 , V_506 ) ;
#else
V_39 = F_480 ( V_342 , V_506 ) ;
#endif
return V_39 ;
}
static enum V_510 F_491 ( struct V_501 * V_502 ,
unsigned long V_503 , T_13 V_504 , union V_511 * V_92 )
{
struct V_39 * V_39 = NULL ;
struct V_141 * V_142 ;
enum V_510 V_145 = V_512 ;
T_6 V_289 = { . V_66 = 0 } ;
if ( F_492 ( V_504 ) )
V_39 = F_475 ( V_502 , V_503 , V_504 ) ;
else if ( F_493 ( V_504 ) )
V_39 = F_477 ( V_502 , V_503 , V_504 , & V_289 ) ;
else if ( F_483 ( V_504 ) || F_494 ( V_504 ) )
V_39 = F_482 ( V_502 , V_503 , V_504 , & V_289 ) ;
if ( ! V_39 && ! V_289 . V_66 )
return V_145 ;
if ( V_39 ) {
V_142 = F_111 ( V_39 ) ;
if ( F_113 ( V_142 ) && V_142 -> V_1 == V_7 . V_162 ) {
V_145 = V_513 ;
if ( V_92 )
V_92 -> V_39 = V_39 ;
}
if ( ! V_145 || ! V_92 )
F_325 ( V_39 ) ;
}
if ( V_289 . V_66 && ! V_145 &&
F_16 ( V_7 . V_162 ) == F_247 ( V_289 ) ) {
V_145 = V_514 ;
if ( V_92 )
V_92 -> V_289 = V_289 ;
}
return V_145 ;
}
static enum V_510 F_495 ( struct V_501 * V_502 ,
unsigned long V_503 , T_15 V_515 , union V_511 * V_92 )
{
struct V_39 * V_39 = NULL ;
struct V_141 * V_142 ;
enum V_510 V_145 = V_512 ;
V_39 = F_496 ( V_515 ) ;
F_242 ( ! V_39 || ! F_497 ( V_39 ) , V_39 ) ;
if ( ! F_9 () )
return V_145 ;
V_142 = F_111 ( V_39 ) ;
if ( F_113 ( V_142 ) && V_142 -> V_1 == V_7 . V_162 ) {
V_145 = V_513 ;
if ( V_92 ) {
F_498 ( V_39 ) ;
V_92 -> V_39 = V_39 ;
}
}
return V_145 ;
}
static inline enum V_510 F_495 ( struct V_501 * V_502 ,
unsigned long V_503 , T_15 V_515 , union V_511 * V_92 )
{
return V_512 ;
}
static int F_499 ( T_15 * V_515 ,
unsigned long V_503 , unsigned long V_516 ,
struct V_517 * V_518 )
{
struct V_501 * V_502 = V_518 -> V_238 ;
T_13 * V_519 ;
T_16 * V_520 ;
if ( F_500 ( V_515 , V_502 , & V_520 ) == 1 ) {
if ( F_495 ( V_502 , V_503 , * V_515 , NULL ) == V_513 )
V_7 . V_499 += V_334 ;
F_55 ( V_520 ) ;
return 0 ;
}
if ( F_501 ( V_515 ) )
return 0 ;
V_519 = F_502 ( V_502 -> V_521 , V_515 , V_503 , & V_520 ) ;
for (; V_503 != V_516 ; V_519 ++ , V_503 += V_250 )
if ( F_491 ( V_502 , V_503 , * V_519 , NULL ) )
V_7 . V_499 ++ ;
F_503 ( V_519 - 1 , V_520 ) ;
F_367 () ;
return 0 ;
}
static unsigned long F_504 ( struct V_107 * V_108 )
{
unsigned long V_499 ;
struct V_501 * V_502 ;
F_505 ( & V_108 -> V_522 ) ;
for ( V_502 = V_108 -> V_523 ; V_502 ; V_502 = V_502 -> V_524 ) {
struct V_517 V_525 = {
. V_526 = F_499 ,
. V_108 = V_108 ,
. V_238 = V_502 ,
} ;
if ( F_506 ( V_502 ) )
continue;
F_507 ( V_502 -> V_527 , V_502 -> V_528 ,
& V_525 ) ;
}
F_508 ( & V_108 -> V_522 ) ;
V_499 = V_7 . V_499 ;
V_7 . V_499 = 0 ;
return V_499 ;
}
static int F_509 ( struct V_107 * V_108 )
{
unsigned long V_499 = F_504 ( V_108 ) ;
F_79 ( V_7 . V_165 ) ;
V_7 . V_165 = V_25 ;
return F_474 ( V_499 ) ;
}
static void F_510 ( void )
{
struct V_1 * V_162 = V_7 . V_162 ;
struct V_1 * V_163 = V_7 . V_163 ;
int V_171 ;
if ( V_7 . V_499 ) {
F_237 ( V_7 . V_163 , V_7 . V_499 ) ;
V_7 . V_499 = 0 ;
}
if ( V_7 . V_529 ) {
F_237 ( V_7 . V_162 , V_7 . V_529 ) ;
V_7 . V_529 = 0 ;
}
if ( V_7 . V_530 ) {
if ( ! F_15 ( V_7 . V_162 ) )
F_208 ( & V_7 . V_162 -> V_157 ,
V_250 * V_7 . V_530 ) ;
for ( V_171 = 0 ; V_171 < V_7 . V_530 ; V_171 ++ )
F_29 ( & V_7 . V_162 -> V_12 ) ;
if ( ! F_15 ( V_7 . V_163 ) ) {
F_208 ( & V_7 . V_163 -> V_59 ,
V_250 * V_7 . V_530 ) ;
}
V_7 . V_530 = 0 ;
}
F_195 ( V_162 ) ;
F_195 ( V_163 ) ;
F_511 ( & V_7 . V_167 ) ;
}
static void F_512 ( void )
{
struct V_1 * V_162 = V_7 . V_162 ;
V_7 . V_165 = NULL ;
F_510 () ;
F_54 ( & V_7 . V_57 ) ;
V_7 . V_162 = NULL ;
V_7 . V_163 = NULL ;
F_55 ( & V_7 . V_57 ) ;
F_129 ( V_162 ) ;
}
static int F_513 ( struct V_10 * V_12 ,
struct V_531 * V_532 )
{
struct V_105 * V_48 = F_514 ( V_532 ) ;
int V_145 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned long V_412 ;
V_412 = V_2 -> V_412 ;
if ( V_412 ) {
struct V_107 * V_108 ;
struct V_1 * V_162 = F_23 ( V_48 ) ;
F_79 ( V_162 == V_2 ) ;
V_108 = F_515 ( V_48 ) ;
if ( ! V_108 )
return 0 ;
if ( V_108 -> V_109 == V_48 ) {
F_79 ( V_7 . V_162 ) ;
F_79 ( V_7 . V_163 ) ;
F_79 ( V_7 . V_499 ) ;
F_79 ( V_7 . V_529 ) ;
F_79 ( V_7 . V_530 ) ;
F_127 ( V_162 ) ;
F_54 ( & V_7 . V_57 ) ;
V_7 . V_162 = V_162 ;
V_7 . V_163 = V_2 ;
V_7 . V_8 = V_412 ;
F_55 ( & V_7 . V_57 ) ;
V_145 = F_509 ( V_108 ) ;
if ( V_145 )
F_512 () ;
}
F_516 ( V_108 ) ;
}
return V_145 ;
}
static void F_517 ( struct V_10 * V_12 ,
struct V_531 * V_532 )
{
F_512 () ;
}
static int F_518 ( T_15 * V_515 ,
unsigned long V_503 , unsigned long V_516 ,
struct V_517 * V_518 )
{
int V_145 = 0 ;
struct V_501 * V_502 = V_518 -> V_238 ;
T_13 * V_519 ;
T_16 * V_520 ;
enum V_510 V_533 ;
union V_511 V_92 ;
struct V_39 * V_39 ;
struct V_141 * V_142 ;
if ( F_500 ( V_515 , V_502 , & V_520 ) == 1 ) {
if ( V_7 . V_499 < V_334 ) {
F_55 ( V_520 ) ;
return 0 ;
}
V_533 = F_495 ( V_502 , V_503 , * V_515 , & V_92 ) ;
if ( V_533 == V_513 ) {
V_39 = V_92 . V_39 ;
if ( ! F_320 ( V_39 ) ) {
V_142 = F_111 ( V_39 ) ;
if ( ! F_314 ( V_39 , V_334 ,
V_142 , V_7 . V_162 , V_7 . V_163 ) ) {
V_7 . V_499 -= V_334 ;
V_7 . V_529 += V_334 ;
}
F_324 ( V_39 ) ;
}
F_325 ( V_39 ) ;
}
F_55 ( V_520 ) ;
return 0 ;
}
if ( F_501 ( V_515 ) )
return 0 ;
V_62:
V_519 = F_502 ( V_502 -> V_521 , V_515 , V_503 , & V_520 ) ;
for (; V_503 != V_516 ; V_503 += V_250 ) {
T_13 V_504 = * ( V_519 ++ ) ;
T_6 V_289 ;
if ( ! V_7 . V_499 )
break;
switch ( F_491 ( V_502 , V_503 , V_504 , & V_92 ) ) {
case V_513 :
V_39 = V_92 . V_39 ;
if ( F_320 ( V_39 ) )
goto V_341;
V_142 = F_111 ( V_39 ) ;
if ( ! F_314 ( V_39 , 1 , V_142 ,
V_7 . V_162 , V_7 . V_163 ) ) {
V_7 . V_499 -- ;
V_7 . V_529 ++ ;
}
F_324 ( V_39 ) ;
V_341:
F_325 ( V_39 ) ;
break;
case V_514 :
V_289 = V_92 . V_289 ;
if ( ! F_346 ( V_289 , V_7 . V_162 , V_7 . V_163 ) ) {
V_7 . V_499 -- ;
V_7 . V_530 ++ ;
}
break;
default:
break;
}
}
F_503 ( V_519 - 1 , V_520 ) ;
F_367 () ;
if ( V_503 != V_516 ) {
V_145 = F_474 ( 1 ) ;
if ( ! V_145 )
goto V_62;
}
return V_145 ;
}
static void F_519 ( struct V_107 * V_108 )
{
struct V_501 * V_502 ;
F_369 () ;
V_62:
if ( F_89 ( ! F_520 ( & V_108 -> V_522 ) ) ) {
F_510 () ;
F_367 () ;
goto V_62;
}
for ( V_502 = V_108 -> V_523 ; V_502 ; V_502 = V_502 -> V_524 ) {
int V_145 ;
struct V_517 V_534 = {
. V_526 = F_518 ,
. V_108 = V_108 ,
. V_238 = V_502 ,
} ;
if ( F_506 ( V_502 ) )
continue;
V_145 = F_507 ( V_502 -> V_527 , V_502 -> V_528 ,
& V_534 ) ;
if ( V_145 )
break;
}
F_508 ( & V_108 -> V_522 ) ;
}
static void F_521 ( struct V_10 * V_12 ,
struct V_531 * V_532 )
{
struct V_105 * V_48 = F_514 ( V_532 ) ;
struct V_107 * V_108 = F_515 ( V_48 ) ;
if ( V_108 ) {
if ( V_7 . V_163 )
F_519 ( V_108 ) ;
F_516 ( V_108 ) ;
}
if ( V_7 . V_163 )
F_512 () ;
}
static int F_513 ( struct V_10 * V_12 ,
struct V_531 * V_532 )
{
return 0 ;
}
static void F_517 ( struct V_10 * V_12 ,
struct V_531 * V_532 )
{
}
static void F_521 ( struct V_10 * V_12 ,
struct V_531 * V_532 )
{
}
static void F_522 ( struct V_10 * V_535 )
{
if ( F_523 ( V_535 -> V_144 ) )
F_11 ( V_535 ) -> V_127 = true ;
}
static int T_5 F_524 ( char * V_11 )
{
if ( ! strcmp ( V_11 , L_36 ) )
V_536 = 1 ;
else if ( ! strcmp ( V_11 , L_37 ) )
V_536 = 0 ;
return 1 ;
}
static void T_5 F_525 ( void )
{
F_28 ( F_526 ( & V_17 , V_537 ) ) ;
}
static void T_5 F_527 ( void )
{
if ( ! F_104 () && V_536 ) {
V_156 = 1 ;
F_525 () ;
}
}
static void T_5 F_527 ( void )
{
}
static int T_5 F_528 ( void )
{
F_529 ( F_225 , 0 ) ;
F_527 () ;
F_462 () ;
F_212 () ;
return 0 ;
}
