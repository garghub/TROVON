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
return V_2 -> V_12 . V_16 -> V_17 + 1 ;
}
static inline struct V_1 * F_17 ( unsigned short V_17 )
{
struct V_10 * V_12 ;
V_12 = F_18 ( V_17 - 1 , & V_18 ) ;
return F_11 ( V_12 ) ;
}
void F_19 ( struct V_19 * V_20 )
{
if ( V_21 ) {
struct V_1 * V_2 ;
struct V_22 * V_22 ;
F_20 ( ! V_20 -> V_23 -> V_24 ) ;
if ( V_20 -> V_25 ) {
F_20 ( F_15 ( V_20 -> V_25 -> V_2 ) ) ;
F_21 ( & V_20 -> V_25 -> V_2 -> V_12 ) ;
return;
}
F_22 () ;
V_2 = F_23 ( V_26 ) ;
V_22 = V_20 -> V_23 -> V_24 ( V_2 ) ;
if ( ! F_15 ( V_2 ) &&
F_24 ( V_22 ) && F_25 ( & V_2 -> V_12 ) ) {
V_20 -> V_25 = V_22 ;
}
F_26 () ;
}
}
void F_27 ( struct V_19 * V_20 )
{
if ( V_21 && V_20 -> V_25 ) {
struct V_1 * V_2 ;
F_28 ( ! V_20 -> V_25 -> V_2 ) ;
V_2 = V_20 -> V_25 -> V_2 ;
F_29 ( & V_20 -> V_25 -> V_2 -> V_12 ) ;
}
}
struct V_22 * F_30 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_15 ( V_2 ) )
return NULL ;
return & V_2 -> V_27 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( ! F_32 ( & V_2 -> V_27 ) )
return;
F_33 ( & V_28 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
}
static void F_34 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) ) {
F_33 ( & V_29 ) ;
F_35 ( & V_30 , V_2 -> V_31 ) ;
}
F_28 ( F_36 ( & V_2 -> V_32 , V_33 ) != 0 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static void F_37 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_34 ( V_2 ) ;
}
static struct V_34 *
F_38 ( struct V_1 * V_2 , int V_35 , int V_36 )
{
F_39 ( ( unsigned ) V_35 >= V_37 ) ;
return & V_2 -> V_38 [ V_35 ] -> V_39 [ V_36 ] ;
}
struct V_10 * F_40 ( struct V_1 * V_2 )
{
return & V_2 -> V_12 ;
}
static struct V_34 *
F_41 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
int V_35 = F_42 ( V_40 ) ;
int V_36 = F_43 ( V_40 ) ;
return F_38 ( V_2 , V_35 , V_36 ) ;
}
static struct V_41 *
F_44 ( int V_35 , int V_36 )
{
return & V_42 . V_43 [ V_35 ] -> V_44 [ V_36 ] ;
}
static struct V_41 *
F_45 ( struct V_40 * V_40 )
{
int V_35 = F_42 ( V_40 ) ;
int V_36 = F_43 ( V_40 ) ;
return & V_42 . V_43 [ V_35 ] -> V_44 [ V_36 ] ;
}
static void
F_46 ( struct V_1 * V_2 ,
struct V_34 * V_45 ,
struct V_41 * V_46 ,
unsigned long long V_47 )
{
struct V_48 * * V_49 = & V_46 -> V_50 . V_48 ;
struct V_48 * V_51 = NULL ;
struct V_34 * V_52 ;
if ( V_45 -> V_53 )
return;
V_45 -> V_54 = V_47 ;
if ( ! V_45 -> V_54 )
return;
while ( * V_49 ) {
V_51 = * V_49 ;
V_52 = F_47 ( V_51 , struct V_34 ,
V_55 ) ;
if ( V_45 -> V_54 < V_52 -> V_54 )
V_49 = & ( * V_49 ) -> V_56 ;
else if ( V_45 -> V_54 >= V_52 -> V_54 )
V_49 = & ( * V_49 ) -> V_57 ;
}
F_48 ( & V_45 -> V_55 , V_51 , V_49 ) ;
F_49 ( & V_45 -> V_55 , & V_46 -> V_50 ) ;
V_45 -> V_53 = true ;
}
static void
F_50 ( struct V_1 * V_2 ,
struct V_34 * V_45 ,
struct V_41 * V_46 )
{
if ( ! V_45 -> V_53 )
return;
F_51 ( & V_45 -> V_55 , & V_46 -> V_50 ) ;
V_45 -> V_53 = false ;
}
static void
F_52 ( struct V_1 * V_2 ,
struct V_34 * V_45 ,
struct V_41 * V_46 )
{
F_53 ( & V_46 -> V_58 ) ;
F_50 ( V_2 , V_45 , V_46 ) ;
F_54 ( & V_46 -> V_58 ) ;
}
static void F_55 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
unsigned long long V_59 ;
struct V_34 * V_45 ;
struct V_41 * V_46 ;
int V_35 = F_42 ( V_40 ) ;
int V_36 = F_43 ( V_40 ) ;
V_46 = F_45 ( V_40 ) ;
for (; V_2 ; V_2 = F_56 ( V_2 ) ) {
V_45 = F_38 ( V_2 , V_35 , V_36 ) ;
V_59 = F_57 ( & V_2 -> V_60 ) ;
if ( V_59 || V_45 -> V_53 ) {
F_53 ( & V_46 -> V_58 ) ;
if ( V_45 -> V_53 )
F_50 ( V_2 , V_45 , V_46 ) ;
F_46 ( V_2 , V_45 , V_46 , V_59 ) ;
F_54 ( & V_46 -> V_58 ) ;
}
}
}
static void F_58 ( struct V_1 * V_2 )
{
int V_61 , V_62 ;
struct V_34 * V_45 ;
struct V_41 * V_46 ;
F_59 (node) {
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_45 = F_38 ( V_2 , V_61 , V_62 ) ;
V_46 = F_44 ( V_61 , V_62 ) ;
F_52 ( V_2 , V_45 , V_46 ) ;
}
}
}
static struct V_34 *
F_60 ( struct V_41 * V_46 )
{
struct V_48 * V_64 = NULL ;
struct V_34 * V_45 ;
V_65:
V_45 = NULL ;
V_64 = F_61 ( & V_46 -> V_50 ) ;
if ( ! V_64 )
goto V_66;
V_45 = F_47 ( V_64 , struct V_34 , V_55 ) ;
F_50 ( V_45 -> V_2 , V_45 , V_46 ) ;
if ( ! F_57 ( & V_45 -> V_2 -> V_60 ) ||
! F_25 ( & V_45 -> V_2 -> V_12 ) )
goto V_65;
V_66:
return V_45 ;
}
static struct V_34 *
F_62 ( struct V_41 * V_46 )
{
struct V_34 * V_45 ;
F_53 ( & V_46 -> V_58 ) ;
V_45 = F_60 ( V_46 ) ;
F_54 ( & V_46 -> V_58 ) ;
return V_45 ;
}
static long F_63 ( struct V_1 * V_2 ,
enum V_67 V_68 )
{
long V_69 = 0 ;
int V_70 ;
F_64 () ;
F_65 (cpu)
V_69 += F_66 ( V_2 -> V_71 -> V_72 [ V_68 ] , V_70 ) ;
#ifdef F_67
F_53 ( & V_2 -> V_73 ) ;
V_69 += V_2 -> V_74 . V_72 [ V_68 ] ;
F_54 ( & V_2 -> V_73 ) ;
#endif
F_68 () ;
return V_69 ;
}
static void F_69 ( struct V_1 * V_2 ,
bool V_75 )
{
int V_69 = ( V_75 ) ? 1 : - 1 ;
F_70 ( V_2 -> V_71 -> V_72 [ V_76 ] , V_69 ) ;
}
static unsigned long F_71 ( struct V_1 * V_2 ,
enum V_77 V_68 )
{
unsigned long V_69 = 0 ;
int V_70 ;
F_64 () ;
F_65 (cpu)
V_69 += F_66 ( V_2 -> V_71 -> V_78 [ V_68 ] , V_70 ) ;
#ifdef F_67
F_53 ( & V_2 -> V_73 ) ;
V_69 += V_2 -> V_74 . V_78 [ V_68 ] ;
F_54 ( & V_2 -> V_73 ) ;
#endif
F_68 () ;
return V_69 ;
}
static void F_72 ( struct V_1 * V_2 ,
struct V_40 * V_40 ,
bool V_79 , int V_80 )
{
F_73 () ;
if ( V_79 )
F_74 ( V_2 -> V_71 -> V_72 [ V_81 ] ,
V_80 ) ;
else
F_74 ( V_2 -> V_71 -> V_72 [ V_82 ] ,
V_80 ) ;
if ( F_75 ( V_40 ) )
F_74 ( V_2 -> V_71 -> V_72 [ V_83 ] ,
V_80 ) ;
if ( V_80 > 0 )
F_76 ( V_2 -> V_71 -> V_78 [ V_84 ] ) ;
else {
F_76 ( V_2 -> V_71 -> V_78 [ V_85 ] ) ;
V_80 = - V_80 ;
}
F_74 ( V_2 -> V_71 -> V_86 , V_80 ) ;
F_77 () ;
}
unsigned long
F_78 ( struct V_87 * V_87 , enum V_88 V_89 )
{
struct V_34 * V_45 ;
V_45 = F_12 ( V_87 , struct V_34 , V_87 ) ;
return V_45 -> V_90 [ V_89 ] ;
}
static unsigned long
F_79 ( struct V_1 * V_2 , int V_35 , int V_36 ,
unsigned int V_91 )
{
struct V_34 * V_45 ;
enum V_88 V_89 ;
unsigned long V_92 = 0 ;
V_45 = F_38 ( V_2 , V_35 , V_36 ) ;
F_80 (lru) {
if ( F_81 ( V_89 ) & V_91 )
V_92 += V_45 -> V_90 [ V_89 ] ;
}
return V_92 ;
}
static unsigned long
F_82 ( struct V_1 * V_2 ,
int V_35 , unsigned int V_91 )
{
T_1 V_93 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ )
V_93 += F_79 ( V_2 ,
V_35 , V_36 , V_91 ) ;
return V_93 ;
}
static unsigned long F_83 ( struct V_1 * V_2 ,
unsigned int V_91 )
{
int V_35 ;
T_1 V_93 = 0 ;
F_84 (nid, N_MEMORY)
V_93 += F_82 ( V_2 , V_35 , V_91 ) ;
return V_93 ;
}
static bool F_85 ( struct V_1 * V_2 ,
enum V_94 V_95 )
{
unsigned long V_69 , V_96 ;
V_69 = F_86 ( V_2 -> V_71 -> V_86 ) ;
V_96 = F_86 ( V_2 -> V_71 -> V_97 [ V_95 ] ) ;
if ( ( long ) V_96 - ( long ) V_69 < 0 ) {
switch ( V_95 ) {
case V_98 :
V_96 = V_69 + V_99 ;
break;
case V_100 :
V_96 = V_69 + V_101 ;
break;
case V_102 :
V_96 = V_69 + V_103 ;
break;
default:
break;
}
F_87 ( V_2 -> V_71 -> V_97 [ V_95 ] , V_96 ) ;
return true ;
}
return false ;
}
static void F_88 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
F_73 () ;
if ( F_89 ( F_85 ( V_2 ,
V_98 ) ) ) {
bool V_104 ;
bool T_2 V_105 ;
V_104 = F_85 ( V_2 ,
V_100 ) ;
#if V_106 > 1
T_2 = F_85 ( V_2 ,
V_102 ) ;
#endif
F_77 () ;
F_90 ( V_2 ) ;
if ( F_89 ( V_104 ) )
F_55 ( V_2 , V_40 ) ;
#if V_106 > 1
if ( F_89 ( T_2 ) )
F_91 ( & V_2 -> V_107 ) ;
#endif
} else
F_77 () ;
}
struct V_1 * F_23 ( struct V_108 * V_49 )
{
if ( F_89 ( ! V_49 ) )
return NULL ;
return F_11 ( F_92 ( V_49 , V_109 ) ) ;
}
struct V_1 * F_93 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_111 )
return NULL ;
F_22 () ;
do {
V_2 = F_23 ( F_94 ( V_111 -> V_112 ) ) ;
if ( F_89 ( ! V_2 ) )
break;
} while ( ! F_25 ( & V_2 -> V_12 ) );
F_26 () ;
return V_2 ;
}
static struct V_1 * F_95 ( struct V_1 * V_113 ,
struct V_1 * V_114 )
{
struct V_10 * V_115 , * V_116 ;
V_115 = V_114 ? & V_114 -> V_12 : NULL ;
V_117:
V_116 = F_96 ( V_115 , & V_113 -> V_12 ) ;
if ( V_116 ) {
if ( ( V_116 == & V_113 -> V_12 ) ||
( ( V_116 -> V_118 & V_119 ) && F_25 ( V_116 ) ) )
return F_11 ( V_116 ) ;
V_115 = V_116 ;
goto V_117;
}
return NULL ;
}
static void F_97 ( struct V_1 * V_113 )
{
F_91 ( & V_113 -> V_120 ) ;
}
static struct V_1 *
F_98 ( struct V_121 * V_122 ,
struct V_1 * V_113 ,
int * V_123 )
{
struct V_1 * V_124 = NULL ;
* V_123 = F_99 ( & V_113 -> V_120 ) ;
if ( V_122 -> V_125 == * V_123 ) {
F_100 () ;
V_124 = V_122 -> V_114 ;
if ( V_124 && V_124 != V_113 &&
! F_25 ( & V_124 -> V_12 ) )
V_124 = NULL ;
}
return V_124 ;
}
static void F_101 ( struct V_121 * V_122 ,
struct V_1 * V_114 ,
struct V_1 * V_126 ,
struct V_1 * V_113 ,
int V_123 )
{
if ( V_114 && V_114 != V_113 )
F_29 ( & V_114 -> V_12 ) ;
V_122 -> V_114 = V_126 ;
F_6 () ;
V_122 -> V_125 = V_123 ;
}
struct V_1 * F_102 ( struct V_1 * V_113 ,
struct V_1 * V_127 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_114 = NULL ;
if ( F_103 () )
return NULL ;
if ( ! V_113 )
V_113 = V_14 ;
if ( V_127 && ! V_129 )
V_114 = V_127 ;
if ( ! V_113 -> V_130 && V_113 != V_14 ) {
if ( V_127 )
goto V_131;
return V_113 ;
}
F_22 () ;
while ( ! V_2 ) {
struct V_121 * V_132 ( V_122 ) ;
int V_132 ( V_133 ) ;
if ( V_129 ) {
int V_35 = F_104 ( V_129 -> V_62 ) ;
int V_36 = F_105 ( V_129 -> V_62 ) ;
struct V_34 * V_45 ;
V_45 = F_38 ( V_113 , V_35 , V_36 ) ;
V_122 = & V_45 -> V_134 [ V_129 -> V_135 ] ;
if ( V_127 && V_129 -> V_136 != V_122 -> V_136 ) {
V_122 -> V_114 = NULL ;
goto V_137;
}
V_114 = F_98 ( V_122 , V_113 , & V_133 ) ;
}
V_2 = F_95 ( V_113 , V_114 ) ;
if ( V_129 ) {
F_101 ( V_122 , V_114 , V_2 , V_113 ,
V_133 ) ;
if ( ! V_2 )
V_122 -> V_136 ++ ;
else if ( ! V_127 && V_2 )
V_129 -> V_136 = V_122 -> V_136 ;
}
if ( V_127 && ! V_2 )
goto V_137;
}
V_137:
F_26 () ;
V_131:
if ( V_127 && V_127 != V_113 )
F_29 ( & V_127 -> V_12 ) ;
return V_2 ;
}
void F_106 ( struct V_1 * V_113 ,
struct V_1 * V_127 )
{
if ( ! V_113 )
V_113 = V_14 ;
if ( V_127 && V_127 != V_113 )
F_29 ( & V_127 -> V_12 ) ;
}
void F_107 ( struct V_110 * V_111 , enum V_138 V_68 )
{
struct V_1 * V_2 ;
F_22 () ;
V_2 = F_23 ( F_94 ( V_111 -> V_112 ) ) ;
if ( F_89 ( ! V_2 ) )
goto V_139;
switch ( V_68 ) {
case V_140 :
F_108 ( V_2 -> V_71 -> V_78 [ V_141 ] ) ;
break;
case V_142 :
F_108 ( V_2 -> V_71 -> V_78 [ V_143 ] ) ;
break;
default:
F_109 () ;
}
V_139:
F_26 () ;
}
struct V_87 * F_110 ( struct V_62 * V_62 ,
struct V_1 * V_2 )
{
struct V_34 * V_45 ;
struct V_87 * V_87 ;
if ( F_103 () ) {
V_87 = & V_62 -> V_87 ;
goto V_139;
}
V_45 = F_38 ( V_2 , F_104 ( V_62 ) , F_105 ( V_62 ) ) ;
V_87 = & V_45 -> V_87 ;
V_139:
if ( F_89 ( V_87 -> V_62 != V_62 ) )
V_87 -> V_62 = V_62 ;
return V_87 ;
}
struct V_87 * F_111 ( struct V_40 * V_40 , struct V_62 * V_62 )
{
struct V_34 * V_45 ;
struct V_1 * V_2 ;
struct V_144 * V_145 ;
struct V_87 * V_87 ;
if ( F_103 () ) {
V_87 = & V_62 -> V_87 ;
goto V_139;
}
V_145 = F_112 ( V_40 ) ;
V_2 = V_145 -> V_1 ;
if ( ! F_113 ( V_40 ) && ! F_114 ( V_145 ) && V_2 != V_14 )
V_145 -> V_1 = V_2 = V_14 ;
V_45 = F_41 ( V_2 , V_40 ) ;
V_87 = & V_45 -> V_87 ;
V_139:
if ( F_89 ( V_87 -> V_62 != V_62 ) )
V_87 -> V_62 = V_62 ;
return V_87 ;
}
void F_115 ( struct V_87 * V_87 , enum V_88 V_89 ,
int V_80 )
{
struct V_34 * V_45 ;
unsigned long * V_90 ;
if ( F_103 () )
return;
V_45 = F_12 ( V_87 , struct V_34 , V_87 ) ;
V_90 = V_45 -> V_90 + V_89 ;
* V_90 += V_80 ;
F_39 ( ( long ) ( * V_90 ) < 0 ) ;
}
bool F_116 ( const struct V_1 * V_146 ,
struct V_1 * V_2 )
{
if ( V_146 == V_2 )
return true ;
if ( ! V_146 -> V_130 || ! V_2 )
return false ;
return F_117 ( V_2 -> V_12 . V_16 , V_146 -> V_12 . V_16 ) ;
}
static bool F_118 ( const struct V_1 * V_146 ,
struct V_1 * V_2 )
{
bool V_92 ;
F_22 () ;
V_92 = F_116 ( V_146 , V_2 ) ;
F_26 () ;
return V_92 ;
}
bool F_119 ( struct V_108 * V_147 ,
const struct V_1 * V_2 )
{
struct V_1 * V_148 = NULL ;
struct V_108 * V_49 ;
bool V_92 ;
V_49 = F_120 ( V_147 ) ;
if ( V_49 ) {
V_148 = F_93 ( V_49 -> V_111 ) ;
F_121 ( V_49 ) ;
} else {
F_22 () ;
V_148 = F_23 ( V_147 ) ;
if ( V_148 )
F_21 ( & V_148 -> V_12 ) ;
F_26 () ;
}
if ( ! V_148 )
return false ;
V_92 = F_118 ( V_2 , V_148 ) ;
F_29 ( & V_148 -> V_12 ) ;
return V_92 ;
}
int F_122 ( struct V_87 * V_87 )
{
unsigned long V_149 ;
unsigned long V_150 ;
unsigned long V_151 ;
unsigned long V_152 ;
V_150 = F_78 ( V_87 , V_153 ) ;
V_151 = F_78 ( V_87 , V_154 ) ;
V_152 = ( V_150 + V_151 ) >> ( 30 - V_155 ) ;
if ( V_152 )
V_149 = F_123 ( 10 * V_152 ) ;
else
V_149 = 1 ;
return V_150 * V_149 < V_151 ;
}
static unsigned long F_124 ( struct V_1 * V_2 )
{
unsigned long long V_156 ;
V_156 = F_125 ( & V_2 -> V_60 ) ;
if ( V_157 )
V_156 = F_126 ( V_156 , F_125 ( & V_2 -> V_158 ) ) ;
return V_156 >> V_155 ;
}
int F_127 ( struct V_1 * V_2 )
{
if ( ! F_128 ( & V_2 -> V_12 ) )
return V_159 ;
return V_2 -> V_160 ;
}
static void F_129 ( struct V_1 * V_2 )
{
F_91 ( & V_161 ) ;
F_91 ( & V_2 -> V_162 ) ;
F_130 () ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_132 ( & V_161 ) ;
F_132 ( & V_2 -> V_162 ) ;
}
}
static bool F_133 ( struct V_1 * V_2 )
{
F_39 ( ! F_134 () ) ;
return F_99 ( & V_2 -> V_162 ) > 0 ;
}
static bool F_135 ( struct V_1 * V_2 )
{
struct V_1 * V_163 ;
struct V_1 * V_164 ;
bool V_92 = false ;
F_53 ( & V_7 . V_58 ) ;
V_163 = V_7 . V_163 ;
V_164 = V_7 . V_164 ;
if ( ! V_163 )
goto V_165;
V_92 = F_118 ( V_2 , V_163 )
|| F_118 ( V_2 , V_164 ) ;
V_165:
F_54 ( & V_7 . V_58 ) ;
return V_92 ;
}
static bool F_136 ( struct V_1 * V_2 )
{
if ( V_7 . V_166 && V_26 != V_7 . V_166 ) {
if ( F_135 ( V_2 ) ) {
F_137 ( V_167 ) ;
F_138 ( & V_7 . V_168 , & V_167 , V_169 ) ;
if ( V_7 . V_166 )
F_139 () ;
F_140 ( & V_7 . V_168 , & V_167 ) ;
return true ;
}
}
return false ;
}
static void F_141 ( struct V_1 * V_2 ,
unsigned long * V_118 )
{
F_142 ( & V_2 -> V_170 , * V_118 ) ;
}
static void F_143 ( struct V_1 * V_2 ,
unsigned long * V_118 )
{
F_144 ( & V_2 -> V_170 , * V_118 ) ;
}
void F_145 ( struct V_1 * V_2 , struct V_108 * V_49 )
{
static F_146 ( V_171 ) ;
struct V_16 * V_172 ;
struct V_16 * V_173 ;
static char V_174 [ V_175 ] ;
int V_92 ;
struct V_1 * V_122 ;
unsigned int V_176 ;
if ( ! V_49 )
return;
F_147 ( & V_171 ) ;
F_22 () ;
V_173 = V_2 -> V_12 . V_16 ;
V_172 = F_148 ( V_49 , V_109 ) ;
V_92 = F_149 ( V_172 , V_174 , V_175 ) ;
if ( V_92 < 0 ) {
F_26 () ;
goto V_66;
}
F_26 () ;
F_150 ( L_1 , V_174 ) ;
F_22 () ;
V_92 = F_149 ( V_173 , V_174 , V_175 ) ;
if ( V_92 < 0 ) {
F_26 () ;
goto V_66;
}
F_26 () ;
F_151 ( L_2 , V_174 ) ;
V_66:
F_150 ( L_3 ,
F_36 ( & V_2 -> V_60 , V_33 ) >> 10 ,
F_36 ( & V_2 -> V_60 , V_177 ) >> 10 ,
F_36 ( & V_2 -> V_60 , V_178 ) ) ;
F_150 ( L_4 ,
F_36 ( & V_2 -> V_158 , V_33 ) >> 10 ,
F_36 ( & V_2 -> V_158 , V_177 ) >> 10 ,
F_36 ( & V_2 -> V_158 , V_178 ) ) ;
F_150 ( L_5 ,
F_36 ( & V_2 -> V_32 , V_33 ) >> 10 ,
F_36 ( & V_2 -> V_32 , V_177 ) >> 10 ,
F_36 ( & V_2 -> V_32 , V_178 ) ) ;
F_152 (iter, memcg) {
F_150 ( L_6 ) ;
F_22 () ;
V_92 = F_149 ( V_122 -> V_12 . V_16 , V_174 , V_175 ) ;
if ( ! V_92 )
F_151 ( L_7 , V_174 ) ;
F_26 () ;
F_151 ( L_8 ) ;
for ( V_176 = 0 ; V_176 < V_179 ; V_176 ++ ) {
if ( V_176 == V_76 && ! V_157 )
continue;
F_151 ( L_9 , V_180 [ V_176 ] ,
F_153 ( F_63 ( V_122 , V_176 ) ) ) ;
}
for ( V_176 = 0 ; V_176 < V_181 ; V_176 ++ )
F_151 ( L_10 , V_182 [ V_176 ] ,
F_153 ( F_83 ( V_122 , F_81 ( V_176 ) ) ) ) ;
F_151 ( L_11 ) ;
}
F_154 ( & V_171 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_183 = 0 ;
struct V_1 * V_122 ;
F_152 (iter, memcg)
V_183 ++ ;
return V_183 ;
}
static T_1 F_156 ( struct V_1 * V_2 )
{
T_1 V_184 ;
V_184 = F_36 ( & V_2 -> V_60 , V_177 ) ;
if ( F_127 ( V_2 ) ) {
T_1 V_158 ;
V_184 += V_185 << V_155 ;
V_158 = F_36 ( & V_2 -> V_158 , V_177 ) ;
V_184 = F_126 ( V_184 , V_158 ) ;
}
return V_184 ;
}
static void F_157 ( struct V_1 * V_2 , T_3 V_186 ,
int V_187 )
{
struct V_1 * V_122 ;
unsigned long V_188 = 0 ;
unsigned long V_189 ;
unsigned int V_190 = 0 ;
struct V_108 * V_191 = NULL ;
if ( F_158 ( V_26 ) || V_26 -> V_118 & V_192 ) {
F_159 ( V_193 ) ;
return;
}
F_160 ( V_194 , V_186 , V_187 , NULL ) ;
V_189 = F_156 ( V_2 ) >> V_155 ? : 1 ;
F_152 (iter, memcg) {
struct V_195 V_196 ;
struct V_108 * V_147 ;
F_161 ( & V_122 -> V_12 , & V_196 ) ;
while ( ( V_147 = F_162 ( & V_196 ) ) ) {
switch ( F_163 ( V_147 , V_189 , NULL ,
false ) ) {
case V_197 :
if ( V_191 )
F_164 ( V_191 ) ;
V_191 = V_147 ;
V_188 = V_198 ;
F_165 ( V_191 ) ;
case V_199 :
continue;
case V_200 :
F_166 ( & V_196 ) ;
F_106 ( V_2 , V_122 ) ;
if ( V_191 )
F_164 ( V_191 ) ;
return;
case V_201 :
break;
} ;
V_190 = F_167 ( V_147 , V_2 , NULL , V_189 ) ;
if ( ! V_190 || V_190 < V_188 )
continue;
if ( V_190 == V_188 &&
F_168 ( V_191 ) )
continue;
if ( V_191 )
F_164 ( V_191 ) ;
V_191 = V_147 ;
V_188 = V_190 ;
F_165 ( V_191 ) ;
}
F_166 ( & V_196 ) ;
}
if ( ! V_191 )
return;
V_190 = V_188 * 1000 / V_189 ;
F_169 ( V_191 , V_186 , V_187 , V_190 , V_189 , V_2 ,
NULL , L_12 ) ;
}
static unsigned long F_170 ( struct V_1 * V_2 ,
T_3 V_186 ,
unsigned long V_118 )
{
unsigned long V_93 = 0 ;
bool V_202 = false ;
int V_203 ;
if ( V_118 & V_204 )
V_202 = true ;
if ( ! ( V_118 & V_205 ) && V_2 -> V_206 )
V_202 = true ;
for ( V_203 = 0 ; V_203 < V_207 ; V_203 ++ ) {
if ( V_203 )
F_171 ( V_2 ) ;
V_93 += F_172 ( V_2 , V_186 , V_202 ) ;
if ( V_93 && ( V_118 & V_205 ) )
break;
if ( F_124 ( V_2 ) )
break;
if ( V_203 && ! V_93 )
break;
}
return V_93 ;
}
static bool F_173 ( struct V_1 * V_2 ,
int V_35 , bool V_202 )
{
if ( F_82 ( V_2 , V_35 , V_208 ) )
return true ;
if ( V_202 || ! V_185 )
return false ;
if ( F_82 ( V_2 , V_35 , V_209 ) )
return true ;
return false ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_35 ;
if ( ! F_99 ( & V_2 -> V_107 ) )
return;
if ( F_175 ( & V_2 -> V_210 ) > 1 )
return;
V_2 -> V_211 = V_212 [ V_213 ] ;
F_176 (nid, node_states[N_MEMORY]) {
if ( ! F_173 ( V_2 , V_35 , false ) )
F_177 ( V_35 , V_2 -> V_211 ) ;
}
F_178 ( & V_2 -> V_107 , 0 ) ;
F_178 ( & V_2 -> V_210 , 0 ) ;
}
int F_179 ( struct V_1 * V_2 )
{
int V_61 ;
F_174 ( V_2 ) ;
V_61 = V_2 -> V_214 ;
V_61 = F_180 ( V_61 , V_2 -> V_211 ) ;
if ( V_61 == V_106 )
V_61 = F_181 ( V_2 -> V_211 ) ;
if ( F_89 ( V_61 == V_106 ) )
V_61 = F_182 () ;
V_2 -> V_214 = V_61 ;
return V_61 ;
}
static bool F_183 ( struct V_1 * V_2 , bool V_202 )
{
int V_35 ;
if ( ! F_184 ( V_2 -> V_211 ) ) {
for ( V_35 = F_181 ( V_2 -> V_211 ) ;
V_35 < V_106 ;
V_35 = F_180 ( V_35 , V_2 -> V_211 ) ) {
if ( F_173 ( V_2 , V_35 , V_202 ) )
return true ;
}
}
F_84 (nid, N_MEMORY) {
if ( F_185 ( V_35 , V_2 -> V_211 ) )
continue;
if ( F_173 ( V_2 , V_35 , V_202 ) )
return true ;
}
return false ;
}
int F_179 ( struct V_1 * V_2 )
{
return 0 ;
}
static bool F_183 ( struct V_1 * V_2 , bool V_202 )
{
return F_173 ( V_2 , 0 , V_202 ) ;
}
static int F_186 ( struct V_1 * V_146 ,
struct V_62 * V_62 ,
T_3 V_186 ,
unsigned long * V_215 )
{
struct V_1 * V_216 = NULL ;
int V_93 = 0 ;
int V_203 = 0 ;
unsigned long V_59 ;
unsigned long V_217 ;
struct V_128 V_129 = {
. V_62 = V_62 ,
. V_135 = 0 ,
} ;
V_59 = F_57 ( & V_146 -> V_60 ) >> V_155 ;
while ( 1 ) {
V_216 = F_102 ( V_146 , V_216 , & V_129 ) ;
if ( ! V_216 ) {
V_203 ++ ;
if ( V_203 >= 2 ) {
if ( ! V_93 )
break;
if ( V_93 >= ( V_59 >> 2 ) ||
( V_203 > V_207 ) )
break;
}
continue;
}
if ( ! F_183 ( V_216 , false ) )
continue;
V_93 += F_187 ( V_216 , V_186 , false ,
V_62 , & V_217 ) ;
* V_215 += V_217 ;
if ( ! F_57 ( & V_146 -> V_60 ) )
break;
}
F_106 ( V_146 , V_216 ) ;
return V_93 ;
}
static bool F_188 ( struct V_1 * V_2 )
{
struct V_1 * V_122 , * V_218 = NULL ;
F_53 ( & V_219 ) ;
F_152 (iter, memcg) {
if ( V_122 -> V_220 ) {
V_218 = V_122 ;
F_106 ( V_2 , V_122 ) ;
break;
} else
V_122 -> V_220 = true ;
}
if ( V_218 ) {
F_152 (iter, memcg) {
if ( V_122 == V_218 ) {
F_106 ( V_2 , V_122 ) ;
break;
}
V_122 -> V_220 = false ;
}
} else
F_189 ( & V_221 , 0 , 1 , V_222 ) ;
F_54 ( & V_219 ) ;
return ! V_218 ;
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_53 ( & V_219 ) ;
F_191 ( & V_221 , 1 , V_222 ) ;
F_152 (iter, memcg)
V_122 -> V_220 = false ;
F_54 ( & V_219 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_152 (iter, memcg)
F_91 ( & V_122 -> V_223 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_152 (iter, memcg)
F_194 ( & V_122 -> V_223 , - 1 , 0 ) ;
}
static int F_195 ( T_4 * V_167 ,
unsigned V_224 , int V_225 , void * V_226 )
{
struct V_1 * V_227 = (struct V_1 * ) V_226 ;
struct V_1 * V_228 ;
struct V_229 * V_229 ;
V_229 = F_12 ( V_167 , struct V_229 , V_167 ) ;
V_228 = V_229 -> V_2 ;
if ( ! F_118 ( V_228 , V_227 )
&& ! F_118 ( V_227 , V_228 ) )
return 0 ;
return F_196 ( V_167 , V_224 , V_225 , V_226 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
F_91 ( & V_2 -> V_230 ) ;
F_198 ( & V_231 , V_232 , 0 , V_2 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
if ( V_2 && F_99 ( & V_2 -> V_223 ) )
F_197 ( V_2 ) ;
}
static void F_200 ( struct V_1 * V_2 , T_3 V_233 , int V_187 )
{
if ( ! V_26 -> V_234 . V_235 )
return;
F_21 ( & V_2 -> V_12 ) ;
V_26 -> V_234 . V_2 = V_2 ;
V_26 -> V_234 . V_186 = V_233 ;
V_26 -> V_234 . V_187 = V_187 ;
}
bool F_201 ( bool V_236 )
{
struct V_1 * V_2 = V_26 -> V_234 . V_2 ;
struct V_229 V_237 ;
bool V_238 ;
if ( ! V_2 )
return false ;
if ( ! V_236 )
goto V_239;
V_237 . V_2 = V_2 ;
V_237 . V_167 . V_118 = 0 ;
V_237 . V_167 . V_240 = F_195 ;
V_237 . V_167 . V_241 = V_26 ;
F_202 ( & V_237 . V_167 . V_242 ) ;
F_138 ( & V_231 , & V_237 . V_167 , V_243 ) ;
F_192 ( V_2 ) ;
V_238 = F_188 ( V_2 ) ;
if ( V_238 )
F_203 ( V_2 ) ;
if ( V_238 && ! V_2 -> V_244 ) {
F_193 ( V_2 ) ;
F_140 ( & V_231 , & V_237 . V_167 ) ;
F_157 ( V_2 , V_26 -> V_234 . V_186 ,
V_26 -> V_234 . V_187 ) ;
} else {
F_139 () ;
F_193 ( V_2 ) ;
F_140 ( & V_231 , & V_237 . V_167 ) ;
}
if ( V_238 ) {
F_190 ( V_2 ) ;
F_199 ( V_2 ) ;
}
V_239:
V_26 -> V_234 . V_2 = NULL ;
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
void F_204 ( struct V_40 * V_40 ,
bool * V_238 , unsigned long * V_118 )
{
struct V_1 * V_2 ;
struct V_144 * V_145 ;
V_145 = F_112 ( V_40 ) ;
V_245:
V_2 = V_145 -> V_1 ;
if ( F_89 ( ! V_2 || ! F_114 ( V_145 ) ) )
return;
if ( ! F_133 ( V_2 ) )
return;
F_141 ( V_2 , V_118 ) ;
if ( V_2 != V_145 -> V_1 || ! F_114 ( V_145 ) ) {
F_143 ( V_2 , V_118 ) ;
goto V_245;
}
* V_238 = true ;
}
void F_205 ( struct V_40 * V_40 , unsigned long * V_118 )
{
struct V_144 * V_145 = F_112 ( V_40 ) ;
F_143 ( V_145 -> V_1 , V_118 ) ;
}
void F_206 ( struct V_40 * V_40 ,
enum V_67 V_68 , int V_69 )
{
struct V_1 * V_2 ;
struct V_144 * V_145 = F_112 ( V_40 ) ;
unsigned long V_132 ( V_118 ) ;
if ( F_103 () )
return;
F_39 ( ! F_134 () ) ;
V_2 = V_145 -> V_1 ;
if ( F_89 ( ! V_2 || ! F_114 ( V_145 ) ) )
return;
F_70 ( V_2 -> V_71 -> V_72 [ V_68 ] , V_69 ) ;
}
static bool F_207 ( struct V_1 * V_2 , unsigned int V_80 )
{
struct V_246 * V_247 ;
bool V_92 = true ;
if ( V_80 > V_248 )
return false ;
V_247 = & F_208 ( V_249 ) ;
if ( V_2 == V_247 -> V_250 && V_247 -> V_80 >= V_80 )
V_247 -> V_80 -= V_80 ;
else
V_92 = false ;
F_209 ( V_249 ) ;
return V_92 ;
}
static void F_210 ( struct V_246 * V_247 )
{
struct V_1 * V_251 = V_247 -> V_250 ;
if ( V_247 -> V_80 ) {
unsigned long V_252 = V_247 -> V_80 * V_253 ;
F_211 ( & V_251 -> V_60 , V_252 ) ;
if ( V_157 )
F_211 ( & V_251 -> V_158 , V_252 ) ;
V_247 -> V_80 = 0 ;
}
V_247 -> V_250 = NULL ;
}
static void F_212 ( struct V_254 * V_255 )
{
struct V_246 * V_247 = & F_213 ( V_249 ) ;
F_210 ( V_247 ) ;
F_214 ( V_256 , & V_247 -> V_118 ) ;
}
static void T_5 F_215 ( void )
{
int V_70 ;
F_216 (cpu) {
struct V_246 * V_247 =
& F_66 ( V_249 , V_70 ) ;
F_217 ( & V_247 -> V_257 , F_212 ) ;
}
}
static void F_218 ( struct V_1 * V_2 , unsigned int V_80 )
{
struct V_246 * V_247 = & F_208 ( V_249 ) ;
if ( V_247 -> V_250 != V_2 ) {
F_210 ( V_247 ) ;
V_247 -> V_250 = V_2 ;
}
V_247 -> V_80 += V_80 ;
F_209 ( V_249 ) ;
}
static void F_219 ( struct V_1 * V_146 , bool V_225 )
{
int V_70 , V_258 ;
F_64 () ;
V_258 = F_220 () ;
F_65 (cpu) {
struct V_246 * V_247 = & F_66 ( V_249 , V_70 ) ;
struct V_1 * V_2 ;
V_2 = V_247 -> V_250 ;
if ( ! V_2 || ! V_247 -> V_80 )
continue;
if ( ! F_118 ( V_146 , V_2 ) )
continue;
if ( ! F_221 ( V_256 , & V_247 -> V_118 ) ) {
if ( V_70 == V_258 )
F_212 ( & V_247 -> V_257 ) ;
else
F_222 ( V_70 , & V_247 -> V_257 ) ;
}
}
F_223 () ;
if ( ! V_225 )
goto V_139;
F_65 (cpu) {
struct V_246 * V_247 = & F_66 ( V_249 , V_70 ) ;
if ( F_4 ( V_256 , & V_247 -> V_118 ) )
F_224 ( & V_247 -> V_257 ) ;
}
V_139:
F_68 () ;
}
static void F_171 ( struct V_1 * V_146 )
{
if ( ! F_225 ( & V_259 ) )
return;
F_219 ( V_146 , false ) ;
F_154 ( & V_259 ) ;
}
static void F_226 ( struct V_1 * V_146 )
{
F_147 ( & V_259 ) ;
F_219 ( V_146 , true ) ;
F_154 ( & V_259 ) ;
}
static void F_227 ( struct V_1 * V_2 , int V_70 )
{
int V_176 ;
F_53 ( & V_2 -> V_73 ) ;
for ( V_176 = 0 ; V_176 < V_179 ; V_176 ++ ) {
long V_260 = F_66 ( V_2 -> V_71 -> V_72 [ V_176 ] , V_70 ) ;
F_66 ( V_2 -> V_71 -> V_72 [ V_176 ] , V_70 ) = 0 ;
V_2 -> V_74 . V_72 [ V_176 ] += V_260 ;
}
for ( V_176 = 0 ; V_176 < V_261 ; V_176 ++ ) {
unsigned long V_260 = F_66 ( V_2 -> V_71 -> V_78 [ V_176 ] , V_70 ) ;
F_66 ( V_2 -> V_71 -> V_78 [ V_176 ] , V_70 ) = 0 ;
V_2 -> V_74 . V_78 [ V_176 ] += V_260 ;
}
F_54 ( & V_2 -> V_73 ) ;
}
static int F_228 ( struct V_262 * V_263 ,
unsigned long V_264 ,
void * V_265 )
{
int V_70 = ( unsigned long ) V_265 ;
struct V_246 * V_247 ;
struct V_1 * V_122 ;
if ( V_264 == V_266 )
return V_267 ;
if ( V_264 != V_268 && V_264 != V_269 )
return V_267 ;
F_229 (iter)
F_227 ( V_122 , V_70 ) ;
V_247 = & F_66 ( V_249 , V_70 ) ;
F_210 ( V_247 ) ;
return V_267 ;
}
static int F_230 ( struct V_1 * V_2 , T_3 V_186 ,
unsigned int V_80 , unsigned int V_270 ,
bool V_271 )
{
unsigned long V_272 = V_80 * V_253 ;
struct V_1 * V_273 ;
struct V_274 * V_275 ;
unsigned long V_118 = 0 ;
int V_92 ;
V_92 = F_231 ( & V_2 -> V_60 , V_272 , & V_275 ) ;
if ( F_232 ( ! V_92 ) ) {
if ( ! V_157 )
return V_276 ;
V_92 = F_231 ( & V_2 -> V_158 , V_272 , & V_275 ) ;
if ( F_232 ( ! V_92 ) )
return V_276 ;
F_211 ( & V_2 -> V_60 , V_272 ) ;
V_273 = F_233 ( V_275 , V_158 ) ;
V_118 |= V_204 ;
} else
V_273 = F_233 ( V_275 , V_60 ) ;
if ( V_80 > V_270 )
return V_277 ;
if ( ! ( V_186 & V_278 ) )
return V_279 ;
if ( V_186 & V_280 )
return V_281 ;
V_92 = F_170 ( V_273 , V_186 , V_118 ) ;
if ( F_124 ( V_273 ) >= V_80 )
return V_277 ;
if ( V_80 <= ( 1 << V_282 ) && V_92 )
return V_277 ;
if ( F_136 ( V_273 ) )
return V_277 ;
if ( V_271 )
F_200 ( V_273 , V_186 , F_234 ( V_272 ) ) ;
return V_281 ;
}
static int F_235 ( struct V_110 * V_111 ,
T_3 V_186 ,
unsigned int V_80 ,
struct V_1 * * V_283 ,
bool V_284 )
{
unsigned int V_285 = F_236 ( V_248 , V_80 ) ;
int V_286 = V_287 ;
struct V_1 * V_2 = NULL ;
int V_92 ;
if ( F_89 ( F_237 ( V_193 )
|| F_158 ( V_26 ) ) )
goto V_288;
if ( F_89 ( F_238 ( V_26 ) ) )
goto V_289;
if ( V_186 & V_290 )
V_284 = false ;
if ( ! * V_283 && ! V_111 )
* V_283 = V_14 ;
V_245:
if ( * V_283 ) {
V_2 = * V_283 ;
if ( F_15 ( V_2 ) )
goto V_66;
if ( F_207 ( V_2 , V_80 ) )
goto V_66;
F_21 ( & V_2 -> V_12 ) ;
} else {
struct V_108 * V_49 ;
F_22 () ;
V_49 = F_94 ( V_111 -> V_112 ) ;
V_2 = F_23 ( V_49 ) ;
if ( ! V_2 )
V_2 = V_14 ;
if ( F_15 ( V_2 ) ) {
F_26 () ;
goto V_66;
}
if ( F_207 ( V_2 , V_80 ) ) {
F_26 () ;
goto V_66;
}
if ( ! F_25 ( & V_2 -> V_12 ) ) {
F_26 () ;
goto V_245;
}
F_26 () ;
}
do {
bool V_271 = V_284 && ! V_286 ;
if ( F_158 ( V_26 ) ) {
F_29 ( & V_2 -> V_12 ) ;
goto V_288;
}
V_92 = F_230 ( V_2 , V_186 , V_285 ,
V_80 , V_271 ) ;
switch ( V_92 ) {
case V_276 :
break;
case V_277 :
V_285 = V_80 ;
F_29 ( & V_2 -> V_12 ) ;
V_2 = NULL ;
goto V_245;
case V_279 :
F_29 ( & V_2 -> V_12 ) ;
goto V_289;
case V_281 :
if ( ! V_284 || V_271 ) {
F_29 ( & V_2 -> V_12 ) ;
goto V_289;
}
V_286 -- ;
break;
}
} while ( V_92 != V_276 );
if ( V_285 > V_80 )
F_218 ( V_2 , V_285 - V_80 ) ;
F_29 ( & V_2 -> V_12 ) ;
V_66:
* V_283 = V_2 ;
return 0 ;
V_289:
if ( ! ( V_186 & V_290 ) ) {
* V_283 = NULL ;
return - V_291 ;
}
V_288:
* V_283 = V_14 ;
return - V_292 ;
}
static void F_239 ( struct V_1 * V_2 ,
unsigned int V_80 )
{
if ( ! F_15 ( V_2 ) ) {
unsigned long V_252 = V_80 * V_253 ;
F_211 ( & V_2 -> V_60 , V_252 ) ;
if ( V_157 )
F_211 ( & V_2 -> V_158 , V_252 ) ;
}
}
static void F_240 ( struct V_1 * V_2 ,
unsigned int V_80 )
{
unsigned long V_252 = V_80 * V_253 ;
if ( F_15 ( V_2 ) )
return;
F_241 ( & V_2 -> V_60 , V_2 -> V_60 . V_51 , V_252 ) ;
if ( V_157 )
F_241 ( & V_2 -> V_158 ,
V_2 -> V_158 . V_51 , V_252 ) ;
}
static struct V_1 * F_242 ( unsigned short V_17 )
{
if ( ! V_17 )
return NULL ;
return F_17 ( V_17 ) ;
}
struct V_1 * F_243 ( struct V_40 * V_40 )
{
struct V_1 * V_2 = NULL ;
struct V_144 * V_145 ;
unsigned short V_17 ;
T_6 V_293 ;
F_244 ( ! F_245 ( V_40 ) , V_40 ) ;
V_145 = F_112 ( V_40 ) ;
F_246 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
} else if ( F_247 ( V_40 ) ) {
V_293 . V_69 = F_248 ( V_40 ) ;
V_17 = F_249 ( V_293 ) ;
F_22 () ;
V_2 = F_242 ( V_17 ) ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
F_26 () ;
}
F_250 ( V_145 ) ;
return V_2 ;
}
static void F_251 ( struct V_1 * V_2 ,
struct V_40 * V_40 ,
unsigned int V_80 ,
enum V_294 V_295 ,
bool V_296 )
{
struct V_144 * V_145 = F_112 ( V_40 ) ;
struct V_62 * V_132 ( V_62 ) ;
struct V_87 * V_87 ;
bool V_297 = false ;
bool V_79 ;
F_246 ( V_145 ) ;
F_244 ( F_114 ( V_145 ) , V_40 ) ;
if ( V_296 ) {
V_62 = F_252 ( V_40 ) ;
F_253 ( & V_62 -> V_298 ) ;
if ( F_113 ( V_40 ) ) {
V_87 = F_110 ( V_62 , V_145 -> V_1 ) ;
F_254 ( V_40 ) ;
F_255 ( V_40 , V_87 , F_256 ( V_40 ) ) ;
V_297 = true ;
}
}
V_145 -> V_1 = V_2 ;
F_6 () ;
F_257 ( V_145 ) ;
if ( V_296 ) {
if ( V_297 ) {
V_87 = F_110 ( V_62 , V_145 -> V_1 ) ;
F_244 ( F_113 ( V_40 ) , V_40 ) ;
F_258 ( V_40 ) ;
F_259 ( V_40 , V_87 , F_256 ( V_40 ) ) ;
}
F_260 ( & V_62 -> V_298 ) ;
}
if ( V_295 == V_299 )
V_79 = true ;
else
V_79 = false ;
F_72 ( V_2 , V_40 , V_79 , V_80 ) ;
F_250 ( V_145 ) ;
F_88 ( V_2 , V_40 ) ;
}
static inline bool F_261 ( struct V_1 * V_2 )
{
return ! F_103 () && ! F_15 ( V_2 ) &&
F_3 ( V_2 ) ;
}
static struct V_300 * F_262 ( struct V_301 * V_49 )
{
struct V_300 * V_302 ;
F_39 ( V_49 -> V_303 ) ;
V_302 = V_49 -> V_304 ;
return F_263 ( V_302 , F_264 ( V_49 -> V_2 ) ) ;
}
static int F_265 ( struct V_305 * V_306 , void * V_307 )
{
struct V_1 * V_2 = F_11 ( F_266 ( V_306 ) ) ;
struct V_301 * V_308 ;
if ( ! F_261 ( V_2 ) )
return - V_309 ;
F_267 ( V_306 ) ;
F_147 ( & V_2 -> V_310 ) ;
F_268 (params, &memcg->memcg_slab_caches, list)
F_269 ( F_262 ( V_308 ) , V_306 ) ;
F_154 ( & V_2 -> V_310 ) ;
return 0 ;
}
static int F_270 ( struct V_1 * V_2 , T_3 V_311 , T_1 V_312 )
{
struct V_274 * V_275 ;
struct V_1 * V_313 ;
int V_92 = 0 ;
V_92 = F_231 ( & V_2 -> V_32 , V_312 , & V_275 ) ;
if ( V_92 )
return V_92 ;
V_313 = V_2 ;
V_92 = F_235 ( NULL , V_311 , V_312 >> V_155 ,
& V_313 , F_271 ( V_311 ) ) ;
if ( V_92 == - V_292 ) {
F_272 ( & V_2 -> V_60 , V_312 , & V_275 ) ;
if ( V_157 )
F_272 ( & V_2 -> V_158 , V_312 ,
& V_275 ) ;
V_92 = 0 ;
} else if ( V_92 )
F_211 ( & V_2 -> V_32 , V_312 ) ;
return V_92 ;
}
static void F_273 ( struct V_1 * V_2 , T_1 V_312 )
{
F_211 ( & V_2 -> V_60 , V_312 ) ;
if ( V_157 )
F_211 ( & V_2 -> V_158 , V_312 ) ;
if ( F_211 ( & V_2 -> V_32 , V_312 ) )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
int F_264 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_31 : - 1 ;
}
static T_7 F_274 ( int V_314 )
{
T_8 V_312 ;
if ( V_314 <= 0 )
return 0 ;
V_312 = 2 * V_314 ;
if ( V_312 < V_315 )
V_312 = V_315 ;
else if ( V_312 > V_316 )
V_312 = V_316 ;
return V_312 ;
}
void F_275 ( int V_183 )
{
if ( V_183 > V_317 )
V_317 = F_274 ( V_183 ) ;
}
int F_276 ( struct V_300 * V_11 , int V_314 )
{
struct V_301 * V_318 = V_11 -> V_319 ;
F_39 ( ! V_303 ( V_11 ) ) ;
if ( V_314 > V_317 ) {
int V_176 ;
struct V_301 * V_320 ;
T_8 V_312 = F_274 ( V_314 ) ;
V_312 *= sizeof( void * ) ;
V_312 += F_277 ( struct V_301 , V_321 ) ;
V_320 = F_278 ( V_312 , V_322 ) ;
if ( ! V_320 )
return - V_291 ;
V_320 -> V_303 = true ;
for ( V_176 = 0 ; V_176 < V_317 ; V_176 ++ ) {
if ( ! V_318 -> V_321 [ V_176 ] )
continue;
V_320 -> V_321 [ V_176 ] =
V_318 -> V_321 [ V_176 ] ;
}
F_279 ( V_11 -> V_319 , V_320 ) ;
if ( V_318 )
F_280 ( V_318 , V_323 ) ;
}
return 0 ;
}
int F_281 ( struct V_1 * V_2 , struct V_300 * V_11 ,
struct V_300 * V_304 )
{
T_7 V_312 ;
if ( ! F_282 () )
return 0 ;
if ( ! V_2 ) {
V_312 = F_277 ( struct V_301 , V_321 ) ;
V_312 += V_317 * sizeof( void * ) ;
} else
V_312 = sizeof( struct V_301 ) ;
V_11 -> V_319 = F_278 ( V_312 , V_322 ) ;
if ( ! V_11 -> V_319 )
return - V_291 ;
if ( V_2 ) {
V_11 -> V_319 -> V_2 = V_2 ;
V_11 -> V_319 -> V_304 = V_304 ;
F_217 ( & V_11 -> V_319 -> V_324 ,
V_325 ) ;
} else
V_11 -> V_319 -> V_303 = true ;
return 0 ;
}
void F_283 ( struct V_300 * V_11 )
{
F_284 ( V_11 -> V_319 ) ;
}
void F_285 ( struct V_300 * V_11 )
{
struct V_300 * V_113 ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_303 ( V_11 ) )
return;
F_286 ( & V_326 ) ;
V_113 = V_11 -> V_319 -> V_304 ;
V_2 = V_11 -> V_319 -> V_2 ;
V_17 = F_264 ( V_2 ) ;
F_21 ( & V_2 -> V_12 ) ;
F_6 () ;
F_39 ( V_113 -> V_319 -> V_321 [ V_17 ] ) ;
V_113 -> V_319 -> V_321 [ V_17 ] = V_11 ;
F_147 ( & V_2 -> V_310 ) ;
F_287 ( & V_11 -> V_319 -> V_327 , & V_2 -> V_328 ) ;
F_154 ( & V_2 -> V_310 ) ;
}
void F_288 ( struct V_300 * V_11 )
{
struct V_300 * V_113 ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_303 ( V_11 ) )
return;
F_286 ( & V_326 ) ;
V_113 = V_11 -> V_319 -> V_304 ;
V_2 = V_11 -> V_319 -> V_2 ;
V_17 = F_264 ( V_2 ) ;
F_147 ( & V_2 -> V_310 ) ;
F_289 ( & V_11 -> V_319 -> V_327 ) ;
F_154 ( & V_2 -> V_310 ) ;
F_39 ( ! V_113 -> V_319 -> V_321 [ V_17 ] ) ;
V_113 -> V_319 -> V_321 [ V_17 ] = NULL ;
F_29 ( & V_2 -> V_12 ) ;
}
static inline void F_290 ( void )
{
F_39 ( ! V_26 -> V_111 ) ;
V_26 -> V_329 ++ ;
}
static inline void F_291 ( void )
{
F_39 ( ! V_26 -> V_111 ) ;
V_26 -> V_329 -- ;
}
static void V_325 ( struct V_254 * V_330 )
{
struct V_300 * V_302 ;
struct V_301 * V_49 ;
V_49 = F_12 ( V_330 , struct V_301 , V_324 ) ;
V_302 = F_262 ( V_49 ) ;
if ( F_99 ( & V_302 -> V_319 -> V_80 ) != 0 )
F_292 ( V_302 ) ;
else
F_293 ( V_302 ) ;
}
void F_294 ( struct V_300 * V_302 )
{
if ( ! V_302 -> V_319 -> V_331 )
return;
if ( F_295 ( & V_302 -> V_319 -> V_324 ) )
return;
F_296 ( & V_302 -> V_319 -> V_324 ) ;
}
static struct V_300 * F_297 ( struct V_1 * V_2 ,
struct V_300 * V_11 )
{
struct V_300 * V_332 = NULL ;
static char * V_333 = NULL ;
static F_146 ( V_334 ) ;
F_20 ( ! F_261 ( V_2 ) ) ;
F_147 ( & V_334 ) ;
if ( ! V_333 ) {
V_333 = F_298 ( V_175 , V_322 ) ;
if ( ! V_333 )
goto V_139;
}
F_22 () ;
snprintf ( V_333 , V_175 , L_13 , V_11 -> V_335 ,
F_264 ( V_2 ) , F_299 ( V_2 -> V_12 . V_16 ) ) ;
F_26 () ;
V_332 = F_300 ( V_2 , V_333 , V_11 -> V_336 , V_11 -> V_337 ,
( V_11 -> V_118 & ~ V_338 ) , V_11 -> V_339 , V_11 ) ;
if ( V_332 )
V_332 -> V_340 |= V_341 ;
else
V_332 = V_11 ;
V_139:
F_154 ( & V_334 ) ;
return V_332 ;
}
void F_301 ( struct V_300 * V_11 )
{
struct V_300 * V_342 ;
int V_176 ;
if ( ! V_11 -> V_319 )
return;
if ( ! V_11 -> V_319 -> V_303 )
return;
F_147 ( & V_343 ) ;
F_302 (i) {
V_342 = F_263 ( V_11 , V_176 ) ;
if ( ! V_342 )
continue;
V_342 -> V_319 -> V_331 = false ;
F_303 ( & V_342 -> V_319 -> V_324 ) ;
F_293 ( V_342 ) ;
}
F_154 ( & V_343 ) ;
}
static void F_304 ( struct V_1 * V_2 )
{
struct V_300 * V_302 ;
struct V_301 * V_308 ;
if ( ! F_3 ( V_2 ) )
return;
F_147 ( & V_2 -> V_310 ) ;
F_268 (params, &memcg->memcg_slab_caches, list) {
V_302 = F_262 ( V_308 ) ;
V_302 -> V_319 -> V_331 = true ;
F_296 ( & V_302 -> V_319 -> V_324 ) ;
}
F_154 ( & V_2 -> V_310 ) ;
}
static void F_305 ( struct V_254 * V_330 )
{
struct V_344 * V_345 ;
V_345 = F_12 ( V_330 , struct V_344 , V_257 ) ;
F_297 ( V_345 -> V_2 , V_345 -> V_302 ) ;
F_29 ( & V_345 -> V_2 -> V_12 ) ;
F_284 ( V_345 ) ;
}
static void F_306 ( struct V_1 * V_2 ,
struct V_300 * V_302 )
{
struct V_344 * V_345 ;
V_345 = F_298 ( sizeof( struct V_344 ) , V_346 ) ;
if ( V_345 == NULL ) {
F_29 ( & V_2 -> V_12 ) ;
return;
}
V_345 -> V_2 = V_2 ;
V_345 -> V_302 = V_302 ;
F_217 ( & V_345 -> V_257 , F_305 ) ;
F_296 ( & V_345 -> V_257 ) ;
}
static void F_307 ( struct V_1 * V_2 ,
struct V_300 * V_302 )
{
F_290 () ;
F_306 ( V_2 , V_302 ) ;
F_291 () ;
}
struct V_300 * F_308 ( struct V_300 * V_302 ,
T_3 V_311 )
{
struct V_1 * V_2 ;
struct V_300 * V_347 ;
F_39 ( ! V_302 -> V_319 ) ;
F_39 ( ! V_302 -> V_319 -> V_303 ) ;
if ( ! V_26 -> V_111 || V_26 -> V_329 )
return V_302 ;
F_22 () ;
V_2 = F_23 ( F_94 ( V_26 -> V_111 -> V_112 ) ) ;
if ( ! F_261 ( V_2 ) )
goto V_139;
V_347 = F_263 ( V_302 , F_264 ( V_2 ) ) ;
if ( F_232 ( V_347 ) ) {
V_302 = V_347 ;
goto V_139;
}
if ( ! F_25 ( & V_2 -> V_12 ) )
goto V_139;
F_26 () ;
F_307 ( V_2 , V_302 ) ;
return V_302 ;
V_139:
F_26 () ;
return V_302 ;
}
bool
F_309 ( T_3 V_311 , struct V_1 * * V_313 , int V_187 )
{
struct V_1 * V_2 ;
int V_92 ;
* V_313 = NULL ;
if ( ! V_26 -> V_111 || V_26 -> V_329 )
return true ;
V_2 = F_93 ( V_26 -> V_111 ) ;
if ( F_89 ( ! V_2 ) )
return true ;
if ( ! F_261 ( V_2 ) ) {
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
V_92 = F_270 ( V_2 , V_311 , V_253 << V_187 ) ;
if ( ! V_92 )
* V_313 = V_2 ;
F_29 ( & V_2 -> V_12 ) ;
return ( V_92 == 0 ) ;
}
void F_310 ( struct V_40 * V_40 , struct V_1 * V_2 ,
int V_187 )
{
struct V_144 * V_145 ;
F_39 ( F_15 ( V_2 ) ) ;
if ( ! V_40 ) {
F_273 ( V_2 , V_253 << V_187 ) ;
return;
}
V_145 = F_112 ( V_40 ) ;
F_246 ( V_145 ) ;
V_145 -> V_1 = V_2 ;
F_257 ( V_145 ) ;
F_250 ( V_145 ) ;
}
void F_311 ( struct V_40 * V_40 , int V_187 )
{
struct V_1 * V_2 = NULL ;
struct V_144 * V_145 ;
V_145 = F_112 ( V_40 ) ;
if ( ! F_114 ( V_145 ) )
return;
F_246 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
F_312 ( V_145 ) ;
}
F_250 ( V_145 ) ;
if ( ! V_2 )
return;
F_244 ( F_15 ( V_2 ) , V_40 ) ;
F_273 ( V_2 , V_253 << V_187 ) ;
}
static inline void F_304 ( struct V_1 * V_2 )
{
}
void F_313 ( struct V_40 * V_348 )
{
struct V_144 * V_349 = F_112 ( V_348 ) ;
struct V_144 * V_145 ;
struct V_1 * V_2 ;
int V_176 ;
if ( F_103 () )
return;
V_2 = V_349 -> V_1 ;
for ( V_176 = 1 ; V_176 < V_350 ; V_176 ++ ) {
V_145 = V_349 + V_176 ;
V_145 -> V_1 = V_2 ;
F_6 () ;
V_145 -> V_118 = V_349 -> V_118 & ~ V_351 ;
}
F_314 ( V_2 -> V_71 -> V_72 [ V_83 ] ,
V_350 ) ;
}
static inline
void F_315 ( struct V_1 * V_163 ,
struct V_1 * V_164 ,
unsigned int V_80 ,
enum V_67 V_68 )
{
F_73 () ;
F_314 ( V_163 -> V_71 -> V_72 [ V_68 ] , V_80 ) ;
F_74 ( V_164 -> V_71 -> V_72 [ V_68 ] , V_80 ) ;
F_77 () ;
}
static int F_316 ( struct V_40 * V_40 ,
unsigned int V_80 ,
struct V_144 * V_145 ,
struct V_1 * V_163 ,
struct V_1 * V_164 )
{
unsigned long V_118 ;
int V_92 ;
bool V_79 = F_317 ( V_40 ) ;
F_39 ( V_163 == V_164 ) ;
F_244 ( F_113 ( V_40 ) , V_40 ) ;
V_92 = - V_352 ;
if ( V_80 > 1 && ! F_75 ( V_40 ) )
goto V_139;
F_246 ( V_145 ) ;
V_92 = - V_353 ;
if ( ! F_114 ( V_145 ) || V_145 -> V_1 != V_163 )
goto V_165;
F_141 ( V_163 , & V_118 ) ;
if ( ! V_79 && F_318 ( V_40 ) )
F_315 ( V_163 , V_164 , V_80 ,
V_354 ) ;
if ( F_319 ( V_40 ) )
F_315 ( V_163 , V_164 , V_80 ,
V_355 ) ;
F_72 ( V_163 , V_40 , V_79 , - V_80 ) ;
V_145 -> V_1 = V_164 ;
F_72 ( V_164 , V_40 , V_79 , V_80 ) ;
F_143 ( V_163 , & V_118 ) ;
V_92 = 0 ;
V_165:
F_250 ( V_145 ) ;
F_88 ( V_164 , V_40 ) ;
F_88 ( V_163 , V_40 ) ;
V_139:
return V_92 ;
}
static int F_320 ( struct V_40 * V_40 ,
struct V_144 * V_145 ,
struct V_1 * V_356 )
{
struct V_1 * V_51 ;
unsigned int V_80 ;
unsigned long V_132 ( V_118 ) ;
int V_92 ;
F_39 ( F_15 ( V_356 ) ) ;
V_92 = - V_352 ;
if ( ! F_321 ( V_40 ) )
goto V_139;
if ( F_322 ( V_40 ) )
goto V_357;
V_80 = F_323 ( V_40 ) ;
V_51 = F_56 ( V_356 ) ;
if ( ! V_51 )
V_51 = V_14 ;
if ( V_80 > 1 ) {
F_244 ( ! F_75 ( V_40 ) , V_40 ) ;
V_118 = F_324 ( V_40 ) ;
}
V_92 = F_316 ( V_40 , V_80 ,
V_145 , V_356 , V_51 ) ;
if ( ! V_92 )
F_240 ( V_356 , V_80 ) ;
if ( V_80 > 1 )
F_325 ( V_40 , V_118 ) ;
F_326 ( V_40 ) ;
V_357:
F_327 ( V_40 ) ;
V_139:
return V_92 ;
}
static int F_328 ( struct V_40 * V_40 , struct V_110 * V_111 ,
T_3 V_186 , enum V_294 V_295 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_80 = 1 ;
bool V_284 = true ;
int V_92 ;
if ( F_75 ( V_40 ) ) {
V_80 <<= F_329 ( V_40 ) ;
F_244 ( ! F_75 ( V_40 ) , V_40 ) ;
V_284 = false ;
}
V_92 = F_235 ( V_111 , V_186 , V_80 , & V_2 , V_284 ) ;
if ( V_92 == - V_291 )
return V_92 ;
F_251 ( V_2 , V_40 , V_80 , V_295 , false ) ;
return 0 ;
}
int F_330 ( struct V_40 * V_40 ,
struct V_110 * V_111 , T_3 V_186 )
{
if ( F_103 () )
return 0 ;
F_244 ( F_318 ( V_40 ) , V_40 ) ;
F_244 ( V_40 -> V_358 && ! F_317 ( V_40 ) , V_40 ) ;
F_39 ( ! V_111 ) ;
return F_328 ( V_40 , V_111 , V_186 ,
V_299 ) ;
}
static int F_331 ( struct V_110 * V_111 ,
struct V_40 * V_40 ,
T_3 V_233 ,
struct V_1 * * V_359 )
{
struct V_1 * V_2 ;
struct V_144 * V_145 ;
int V_92 ;
V_145 = F_112 ( V_40 ) ;
if ( F_114 ( V_145 ) )
return 0 ;
if ( ! V_157 )
goto V_360;
V_2 = F_243 ( V_40 ) ;
if ( ! V_2 )
goto V_360;
* V_359 = V_2 ;
V_92 = F_235 ( NULL , V_233 , 1 , V_359 , true ) ;
F_29 ( & V_2 -> V_12 ) ;
if ( V_92 == - V_292 )
V_92 = 0 ;
return V_92 ;
V_360:
V_92 = F_235 ( V_111 , V_233 , 1 , V_359 , true ) ;
if ( V_92 == - V_292 )
V_92 = 0 ;
return V_92 ;
}
int F_332 ( struct V_110 * V_111 , struct V_40 * V_40 ,
T_3 V_186 , struct V_1 * * V_359 )
{
* V_359 = NULL ;
if ( F_103 () )
return 0 ;
if ( ! F_247 ( V_40 ) ) {
int V_92 ;
V_92 = F_235 ( V_111 , V_186 , 1 , V_359 , true ) ;
if ( V_92 == - V_292 )
V_92 = 0 ;
return V_92 ;
}
return F_331 ( V_111 , V_40 , V_186 , V_359 ) ;
}
void F_333 ( struct V_1 * V_2 )
{
if ( F_103 () )
return;
if ( ! V_2 )
return;
F_239 ( V_2 , 1 ) ;
}
static void
F_334 ( struct V_40 * V_40 , struct V_1 * V_2 ,
enum V_294 V_295 )
{
if ( F_103 () )
return;
if ( ! V_2 )
return;
F_251 ( V_2 , V_40 , 1 , V_295 , true ) ;
if ( V_157 && F_247 ( V_40 ) ) {
T_6 V_293 = { . V_69 = F_248 (page) } ;
F_335 ( V_293 ) ;
}
}
void F_336 ( struct V_40 * V_40 ,
struct V_1 * V_2 )
{
F_334 ( V_40 , V_2 ,
V_299 ) ;
}
int F_337 ( struct V_40 * V_40 , struct V_110 * V_111 ,
T_3 V_186 )
{
struct V_1 * V_2 = NULL ;
enum V_294 type = V_361 ;
int V_92 ;
if ( F_103 () )
return 0 ;
if ( F_338 ( V_40 ) )
return 0 ;
if ( ! F_247 ( V_40 ) )
V_92 = F_328 ( V_40 , V_111 , V_186 , type ) ;
else {
V_92 = F_331 ( V_111 , V_40 ,
V_186 , & V_2 ) ;
if ( ! V_92 )
F_334 ( V_40 , V_2 , type ) ;
}
return V_92 ;
}
static void F_339 ( struct V_1 * V_2 ,
unsigned int V_80 ,
const enum V_294 V_295 )
{
struct V_362 * V_285 = NULL ;
bool V_363 = true ;
if ( ! V_157 || V_295 == V_364 )
V_363 = false ;
V_285 = & V_26 -> V_365 ;
if ( ! V_285 -> V_2 )
V_285 -> V_2 = V_2 ;
if ( ! V_285 -> V_366 || F_237 ( V_193 ) )
goto V_367;
if ( V_80 > 1 )
goto V_367;
if ( V_285 -> V_2 != V_2 )
goto V_367;
V_285 -> V_80 ++ ;
if ( V_363 )
V_285 -> V_368 ++ ;
return;
V_367:
F_211 ( & V_2 -> V_60 , V_80 * V_253 ) ;
if ( V_363 )
F_211 ( & V_2 -> V_158 , V_80 * V_253 ) ;
if ( F_89 ( V_285 -> V_2 != V_2 ) )
F_199 ( V_2 ) ;
}
static struct V_1 *
F_340 ( struct V_40 * V_40 , enum V_294 V_295 ,
bool V_369 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_80 = 1 ;
struct V_144 * V_145 ;
bool V_79 ;
if ( F_103 () )
return NULL ;
if ( F_75 ( V_40 ) ) {
V_80 <<= F_329 ( V_40 ) ;
F_244 ( ! F_75 ( V_40 ) , V_40 ) ;
}
V_145 = F_112 ( V_40 ) ;
if ( F_89 ( ! F_114 ( V_145 ) ) )
return NULL ;
F_246 ( V_145 ) ;
V_2 = V_145 -> V_1 ;
if ( ! F_114 ( V_145 ) )
goto V_370;
V_79 = F_317 ( V_40 ) ;
switch ( V_295 ) {
case V_299 :
V_79 = true ;
case V_371 :
if ( F_318 ( V_40 ) )
goto V_370;
if ( ! V_369 && F_341 ( V_145 ) )
goto V_370;
break;
case V_364 :
if ( ! F_317 ( V_40 ) ) {
if ( V_40 -> V_358 && ! F_342 ( V_40 ) )
goto V_370;
} else if ( F_318 ( V_40 ) )
goto V_370;
break;
default:
break;
}
F_72 ( V_2 , V_40 , V_79 , - V_80 ) ;
F_312 ( V_145 ) ;
F_250 ( V_145 ) ;
F_88 ( V_2 , V_40 ) ;
if ( V_157 && V_295 == V_364 ) {
F_69 ( V_2 , true ) ;
F_21 ( & V_2 -> V_12 ) ;
}
if ( ! V_369 && ! F_15 ( V_2 ) )
F_339 ( V_2 , V_80 , V_295 ) ;
return V_2 ;
V_370:
F_250 ( V_145 ) ;
return NULL ;
}
void F_343 ( struct V_40 * V_40 )
{
if ( F_318 ( V_40 ) )
return;
F_244 ( V_40 -> V_358 && ! F_317 ( V_40 ) , V_40 ) ;
if ( F_247 ( V_40 ) )
return;
F_340 ( V_40 , V_299 , false ) ;
}
void F_344 ( struct V_40 * V_40 )
{
F_244 ( F_318 ( V_40 ) , V_40 ) ;
F_244 ( V_40 -> V_358 , V_40 ) ;
F_340 ( V_40 , V_361 , false ) ;
}
void F_345 ( void )
{
V_26 -> V_365 . V_366 ++ ;
if ( V_26 -> V_365 . V_366 == 1 ) {
V_26 -> V_365 . V_2 = NULL ;
V_26 -> V_365 . V_80 = 0 ;
V_26 -> V_365 . V_368 = 0 ;
}
}
void F_346 ( void )
{
struct V_362 * V_285 = & V_26 -> V_365 ;
if ( ! V_285 -> V_366 )
return;
V_285 -> V_366 -- ;
if ( V_285 -> V_366 )
return;
if ( ! V_285 -> V_2 )
return;
if ( V_285 -> V_80 )
F_211 ( & V_285 -> V_2 -> V_60 ,
V_285 -> V_80 * V_253 ) ;
if ( V_285 -> V_368 )
F_211 ( & V_285 -> V_2 -> V_158 ,
V_285 -> V_368 * V_253 ) ;
F_199 ( V_285 -> V_2 ) ;
V_285 -> V_2 = NULL ;
}
void
F_347 ( struct V_40 * V_40 , T_6 V_293 , bool V_372 )
{
struct V_1 * V_2 ;
int V_295 = V_364 ;
if ( ! V_372 )
V_295 = V_371 ;
V_2 = F_340 ( V_40 , V_295 , false ) ;
if ( V_157 && V_372 && V_2 )
F_348 ( V_293 , F_16 ( V_2 ) ) ;
}
void F_335 ( T_6 V_293 )
{
struct V_1 * V_2 ;
unsigned short V_17 ;
if ( ! V_157 )
return;
V_17 = F_348 ( V_293 , 0 ) ;
F_22 () ;
V_2 = F_242 ( V_17 ) ;
if ( V_2 ) {
if ( ! F_15 ( V_2 ) )
F_211 ( & V_2 -> V_158 , V_253 ) ;
F_69 ( V_2 , false ) ;
F_29 ( & V_2 -> V_12 ) ;
}
F_26 () ;
}
static int F_349 ( T_6 V_373 ,
struct V_1 * V_163 , struct V_1 * V_164 )
{
unsigned short V_374 , V_375 ;
V_374 = F_16 ( V_163 ) ;
V_375 = F_16 ( V_164 ) ;
if ( F_350 ( V_373 , V_374 , V_375 ) == V_374 ) {
F_69 ( V_163 , false ) ;
F_69 ( V_164 , true ) ;
F_21 ( & V_164 -> V_12 ) ;
return 0 ;
}
return - V_353 ;
}
static inline int F_349 ( T_6 V_373 ,
struct V_1 * V_163 , struct V_1 * V_164 )
{
return - V_353 ;
}
void F_351 ( struct V_40 * V_40 , struct V_40 * V_376 ,
struct V_1 * * V_359 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_80 = 1 ;
struct V_144 * V_145 ;
enum V_294 V_295 ;
* V_359 = NULL ;
if ( F_103 () )
return;
if ( F_75 ( V_40 ) )
V_80 <<= F_329 ( V_40 ) ;
V_145 = F_112 ( V_40 ) ;
F_246 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
F_21 ( & V_2 -> V_12 ) ;
if ( F_317 ( V_40 ) )
F_352 ( V_145 ) ;
}
F_250 ( V_145 ) ;
if ( ! V_2 )
return;
* V_359 = V_2 ;
if ( F_317 ( V_40 ) )
V_295 = V_299 ;
else
V_295 = V_361 ;
F_251 ( V_2 , V_376 , V_80 , V_295 , false ) ;
}
void F_353 ( struct V_1 * V_2 ,
struct V_40 * V_377 , struct V_40 * V_376 , bool V_378 )
{
struct V_40 * V_379 , * V_380 ;
struct V_144 * V_145 ;
bool V_79 ;
if ( ! V_2 )
return;
if ( ! V_378 ) {
V_379 = V_377 ;
V_380 = V_376 ;
} else {
V_379 = V_376 ;
V_380 = V_377 ;
}
V_79 = F_317 ( V_379 ) ;
F_340 ( V_380 ,
V_79 ? V_299
: V_361 ,
true ) ;
F_29 ( & V_2 -> V_12 ) ;
V_145 = F_112 ( V_377 ) ;
F_246 ( V_145 ) ;
F_354 ( V_145 ) ;
F_250 ( V_145 ) ;
if ( V_79 )
F_343 ( V_379 ) ;
}
void F_355 ( struct V_40 * V_377 ,
struct V_40 * V_376 )
{
struct V_1 * V_2 = NULL ;
struct V_144 * V_145 ;
enum V_294 type = V_361 ;
if ( F_103 () )
return;
V_145 = F_112 ( V_377 ) ;
F_246 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
F_72 ( V_2 , V_377 , false , - 1 ) ;
F_312 ( V_145 ) ;
}
F_250 ( V_145 ) ;
if ( ! V_2 )
return;
F_251 ( V_2 , V_376 , 1 , type , true ) ;
}
static struct V_144 * F_356 ( struct V_40 * V_40 )
{
struct V_144 * V_145 ;
V_145 = F_112 ( V_40 ) ;
if ( F_232 ( V_145 ) && F_114 ( V_145 ) )
return V_145 ;
return NULL ;
}
bool F_357 ( struct V_40 * V_40 )
{
if ( F_103 () )
return false ;
return F_356 ( V_40 ) != NULL ;
}
void F_358 ( struct V_40 * V_40 )
{
struct V_144 * V_145 ;
V_145 = F_356 ( V_40 ) ;
if ( V_145 ) {
F_359 ( L_14 ,
V_145 , V_145 -> V_118 , V_145 -> V_1 ) ;
}
}
static int F_360 ( struct V_1 * V_2 ,
unsigned long long V_69 )
{
int V_381 ;
T_1 V_382 , V_383 ;
int V_92 = 0 ;
int V_384 = F_155 ( V_2 ) ;
T_1 V_385 , V_386 ;
int V_387 ;
V_381 = V_287 * V_384 ;
V_386 = F_36 ( & V_2 -> V_60 , V_33 ) ;
V_387 = 0 ;
while ( V_381 ) {
if ( F_361 ( V_26 ) ) {
V_92 = - V_292 ;
break;
}
F_147 ( & V_388 ) ;
V_382 = F_36 ( & V_2 -> V_158 , V_177 ) ;
if ( V_382 < V_69 ) {
V_92 = - V_353 ;
F_154 ( & V_388 ) ;
break;
}
V_383 = F_36 ( & V_2 -> V_60 , V_177 ) ;
if ( V_383 < V_69 )
V_387 = 1 ;
V_92 = F_362 ( & V_2 -> V_60 , V_69 ) ;
if ( ! V_92 ) {
if ( V_382 == V_69 )
V_2 -> V_206 = true ;
else
V_2 -> V_206 = false ;
}
F_154 ( & V_388 ) ;
if ( ! V_92 )
break;
F_170 ( V_2 , V_322 ,
V_205 ) ;
V_385 = F_36 ( & V_2 -> V_60 , V_33 ) ;
if ( V_385 >= V_386 )
V_381 -- ;
else
V_386 = V_385 ;
}
if ( ! V_92 && V_387 )
F_199 ( V_2 ) ;
return V_92 ;
}
static int F_363 ( struct V_1 * V_2 ,
unsigned long long V_69 )
{
int V_381 ;
T_1 V_383 , V_382 , V_386 , V_385 ;
int V_384 = F_155 ( V_2 ) ;
int V_92 = - V_352 ;
int V_387 = 0 ;
V_381 = V_384 * V_287 ;
V_386 = F_36 ( & V_2 -> V_158 , V_33 ) ;
while ( V_381 ) {
if ( F_361 ( V_26 ) ) {
V_92 = - V_292 ;
break;
}
F_147 ( & V_388 ) ;
V_383 = F_36 ( & V_2 -> V_60 , V_177 ) ;
if ( V_383 > V_69 ) {
V_92 = - V_353 ;
F_154 ( & V_388 ) ;
break;
}
V_382 = F_36 ( & V_2 -> V_158 , V_177 ) ;
if ( V_382 < V_69 )
V_387 = 1 ;
V_92 = F_362 ( & V_2 -> V_158 , V_69 ) ;
if ( ! V_92 ) {
if ( V_383 == V_69 )
V_2 -> V_206 = true ;
else
V_2 -> V_206 = false ;
}
F_154 ( & V_388 ) ;
if ( ! V_92 )
break;
F_170 ( V_2 , V_322 ,
V_204 |
V_205 ) ;
V_385 = F_36 ( & V_2 -> V_158 , V_33 ) ;
if ( V_385 >= V_386 )
V_381 -- ;
else
V_386 = V_385 ;
}
if ( ! V_92 && V_387 )
F_199 ( V_2 ) ;
return V_92 ;
}
unsigned long F_364 ( struct V_62 * V_62 , int V_187 ,
T_3 V_186 ,
unsigned long * V_215 )
{
unsigned long V_389 = 0 ;
struct V_34 * V_45 , * V_390 = NULL ;
unsigned long V_391 ;
int V_203 = 0 ;
struct V_41 * V_46 ;
unsigned long long V_59 ;
unsigned long V_217 ;
if ( V_187 > 0 )
return 0 ;
V_46 = F_44 ( F_104 ( V_62 ) , F_105 ( V_62 ) ) ;
do {
if ( V_390 )
V_45 = V_390 ;
else
V_45 = F_62 ( V_46 ) ;
if ( ! V_45 )
break;
V_217 = 0 ;
V_391 = F_186 ( V_45 -> V_2 , V_62 ,
V_186 , & V_217 ) ;
V_389 += V_391 ;
* V_215 += V_217 ;
F_53 ( & V_46 -> V_58 ) ;
V_390 = NULL ;
if ( ! V_391 ) {
do {
V_390 =
F_60 ( V_46 ) ;
if ( V_390 == V_45 )
F_29 ( & V_390 -> V_2 -> V_12 ) ;
else
break;
} while ( 1 );
}
F_50 ( V_45 -> V_2 , V_45 , V_46 ) ;
V_59 = F_57 ( & V_45 -> V_2 -> V_60 ) ;
F_46 ( V_45 -> V_2 , V_45 , V_46 , V_59 ) ;
F_54 ( & V_46 -> V_58 ) ;
F_29 ( & V_45 -> V_2 -> V_12 ) ;
V_203 ++ ;
if ( ! V_389 &&
( V_390 == NULL ||
V_203 > V_392 ) )
break;
} while ( ! V_389 );
if ( V_390 )
F_29 ( & V_390 -> V_2 -> V_12 ) ;
return V_389 ;
}
static void F_365 ( struct V_1 * V_2 ,
int V_61 , int V_36 , enum V_88 V_89 )
{
struct V_87 * V_87 ;
unsigned long V_118 ;
struct V_393 * V_327 ;
struct V_40 * V_394 ;
struct V_62 * V_62 ;
V_62 = & F_366 ( V_61 ) -> V_395 [ V_36 ] ;
V_87 = F_110 ( V_62 , V_2 ) ;
V_327 = & V_87 -> V_396 [ V_89 ] ;
V_394 = NULL ;
do {
struct V_144 * V_145 ;
struct V_40 * V_40 ;
F_142 ( & V_62 -> V_298 , V_118 ) ;
if ( F_367 ( V_327 ) ) {
F_144 ( & V_62 -> V_298 , V_118 ) ;
break;
}
V_40 = F_368 ( V_327 -> V_127 , struct V_40 , V_89 ) ;
if ( V_394 == V_40 ) {
F_369 ( & V_40 -> V_89 , V_327 ) ;
V_394 = NULL ;
F_144 ( & V_62 -> V_298 , V_118 ) ;
continue;
}
F_144 ( & V_62 -> V_298 , V_118 ) ;
V_145 = F_112 ( V_40 ) ;
if ( F_320 ( V_40 , V_145 , V_2 ) ) {
V_394 = V_40 ;
F_370 () ;
} else
V_394 = NULL ;
} while ( ! F_367 ( V_327 ) );
}
static void F_371 ( struct V_1 * V_2 )
{
int V_61 , V_36 ;
T_1 V_397 ;
do {
F_372 () ;
F_226 ( V_2 ) ;
F_129 ( V_2 ) ;
F_84 (node, N_MEMORY) {
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ ) {
enum V_88 V_89 ;
F_80 (lru) {
F_365 ( V_2 ,
V_61 , V_36 , V_89 ) ;
}
}
}
F_131 ( V_2 ) ;
F_199 ( V_2 ) ;
F_370 () ;
V_397 = F_36 ( & V_2 -> V_60 , V_33 ) -
F_36 ( & V_2 -> V_32 , V_33 ) ;
} while ( V_397 > 0 );
}
static inline bool F_373 ( struct V_1 * V_2 )
{
F_286 ( & V_398 ) ;
return V_2 -> V_130 &&
! F_367 ( & V_2 -> V_12 . V_16 -> V_384 ) ;
}
static int F_374 ( struct V_1 * V_2 )
{
int V_399 = V_287 ;
struct V_16 * V_400 = V_2 -> V_12 . V_16 ;
if ( F_375 ( V_400 ) || ! F_367 ( & V_400 -> V_384 ) )
return - V_352 ;
F_372 () ;
while ( V_399 && F_36 ( & V_2 -> V_60 , V_33 ) > 0 ) {
int V_401 ;
if ( F_361 ( V_26 ) )
return - V_292 ;
V_401 = F_172 ( V_2 , V_322 ,
false ) ;
if ( ! V_401 ) {
V_399 -- ;
F_376 ( V_402 , V_403 / 10 ) ;
}
}
F_377 () ;
F_371 ( V_2 ) ;
return 0 ;
}
static int F_378 ( struct V_10 * V_12 ,
unsigned int V_404 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( F_15 ( V_2 ) )
return - V_353 ;
return F_374 ( V_2 ) ;
}
static T_1 F_379 ( struct V_10 * V_12 ,
struct V_405 * V_406 )
{
return F_11 ( V_12 ) -> V_130 ;
}
static int F_380 ( struct V_10 * V_12 ,
struct V_405 * V_406 , T_1 V_69 )
{
int V_407 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_408 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
F_147 ( & V_398 ) ;
if ( V_2 -> V_130 == V_69 )
goto V_139;
if ( ( ! V_408 || ! V_408 -> V_130 ) &&
( V_69 == 1 || V_69 == 0 ) ) {
if ( F_367 ( & V_2 -> V_12 . V_16 -> V_384 ) )
V_2 -> V_130 = V_69 ;
else
V_407 = - V_352 ;
} else
V_407 = - V_353 ;
V_139:
F_154 ( & V_398 ) ;
return V_407 ;
}
static unsigned long F_381 ( struct V_1 * V_2 ,
enum V_67 V_68 )
{
struct V_1 * V_122 ;
long V_69 = 0 ;
F_152 (iter, memcg)
V_69 += F_63 ( V_122 , V_68 ) ;
if ( V_69 < 0 )
V_69 = 0 ;
return V_69 ;
}
static inline T_1 F_382 ( struct V_1 * V_2 , bool V_409 )
{
T_1 V_69 ;
if ( ! F_15 ( V_2 ) ) {
if ( ! V_409 )
return F_36 ( & V_2 -> V_60 , V_33 ) ;
else
return F_36 ( & V_2 -> V_158 , V_33 ) ;
}
V_69 = F_381 ( V_2 , V_82 ) ;
V_69 += F_381 ( V_2 , V_81 ) ;
if ( V_409 )
V_69 += F_381 ( V_2 , V_76 ) ;
return V_69 << V_155 ;
}
static T_1 F_383 ( struct V_10 * V_12 ,
struct V_405 * V_406 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_1 V_69 ;
int V_335 ;
enum V_410 type ;
type = F_384 ( V_406 -> V_241 ) ;
V_335 = F_385 ( V_406 -> V_241 ) ;
switch ( type ) {
case V_411 :
if ( V_335 == V_33 )
V_69 = F_382 ( V_2 , false ) ;
else
V_69 = F_36 ( & V_2 -> V_60 , V_335 ) ;
break;
case V_412 :
if ( V_335 == V_33 )
V_69 = F_382 ( V_2 , true ) ;
else
V_69 = F_36 ( & V_2 -> V_158 , V_335 ) ;
break;
case V_413 :
V_69 = F_36 ( & V_2 -> V_32 , V_335 ) ;
break;
default:
F_109 () ;
}
return V_69 ;
}
static int F_386 ( struct V_1 * V_2 ,
unsigned long long V_184 )
{
int V_414 = 0 ;
int V_415 ;
if ( F_3 ( V_2 ) )
return 0 ;
F_290 () ;
F_147 ( & V_398 ) ;
if ( F_375 ( V_2 -> V_12 . V_16 ) || F_373 ( V_2 ) )
V_414 = - V_352 ;
F_154 ( & V_398 ) ;
if ( V_414 )
goto V_139;
V_415 = F_387 ( & V_30 ,
0 , V_316 , V_322 ) ;
if ( V_415 < 0 ) {
V_414 = V_415 ;
goto V_139;
}
V_414 = F_388 ( V_415 + 1 ) ;
if ( V_414 )
goto V_416;
V_2 -> V_31 = V_415 ;
F_202 ( & V_2 -> V_328 ) ;
F_389 ( & V_2 -> V_310 ) ;
V_414 = F_362 ( & V_2 -> V_32 , V_184 ) ;
F_39 ( V_414 ) ;
F_390 ( & V_29 ) ;
F_1 ( V_2 ) ;
V_139:
F_291 () ;
return V_414 ;
V_416:
F_35 ( & V_30 , V_415 ) ;
goto V_139;
}
static int F_391 ( struct V_1 * V_2 ,
unsigned long long V_184 )
{
int V_92 ;
F_147 ( & V_343 ) ;
V_92 = F_386 ( V_2 , V_184 ) ;
F_154 ( & V_343 ) ;
return V_92 ;
}
static int F_392 ( struct V_1 * V_2 ,
unsigned long long V_69 )
{
int V_92 ;
if ( ! F_3 ( V_2 ) )
V_92 = F_391 ( V_2 , V_69 ) ;
else
V_92 = F_362 ( & V_2 -> V_32 , V_69 ) ;
return V_92 ;
}
static int F_393 ( struct V_1 * V_2 )
{
int V_92 = 0 ;
struct V_1 * V_51 = F_56 ( V_2 ) ;
if ( ! V_51 )
return 0 ;
F_147 ( & V_343 ) ;
if ( F_3 ( V_51 ) )
V_92 = F_386 ( V_2 , V_417 ) ;
F_154 ( & V_343 ) ;
return V_92 ;
}
static int F_392 ( struct V_1 * V_2 ,
unsigned long long V_69 )
{
return - V_353 ;
}
static int F_394 ( struct V_10 * V_12 , struct V_405 * V_406 ,
const char * V_418 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
enum V_410 type ;
int V_335 ;
unsigned long long V_69 ;
int V_92 ;
type = F_384 ( V_406 -> V_241 ) ;
V_335 = F_385 ( V_406 -> V_241 ) ;
switch ( V_335 ) {
case V_177 :
if ( F_15 ( V_2 ) ) {
V_92 = - V_353 ;
break;
}
V_92 = F_395 ( V_418 , & V_69 ) ;
if ( V_92 )
break;
if ( type == V_411 )
V_92 = F_360 ( V_2 , V_69 ) ;
else if ( type == V_412 )
V_92 = F_363 ( V_2 , V_69 ) ;
else if ( type == V_413 )
V_92 = F_392 ( V_2 , V_69 ) ;
else
return - V_353 ;
break;
case V_419 :
V_92 = F_395 ( V_418 , & V_69 ) ;
if ( V_92 )
break;
if ( type == V_411 )
V_92 = F_396 ( & V_2 -> V_60 , V_69 ) ;
else
V_92 = - V_353 ;
break;
default:
V_92 = - V_353 ;
break;
}
return V_92 ;
}
static void F_397 ( struct V_1 * V_2 ,
unsigned long long * V_420 , unsigned long long * V_421 )
{
unsigned long long V_422 , V_423 , V_424 ;
V_422 = F_36 ( & V_2 -> V_60 , V_177 ) ;
V_423 = F_36 ( & V_2 -> V_158 , V_177 ) ;
if ( ! V_2 -> V_130 )
goto V_139;
while ( F_128 ( & V_2 -> V_12 ) ) {
V_2 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
if ( ! V_2 -> V_130 )
break;
V_424 = F_36 ( & V_2 -> V_60 , V_177 ) ;
V_422 = F_126 ( V_422 , V_424 ) ;
V_424 = F_36 ( & V_2 -> V_158 , V_177 ) ;
V_423 = F_126 ( V_423 , V_424 ) ;
}
V_139:
* V_420 = V_422 ;
* V_421 = V_423 ;
}
static int F_398 ( struct V_10 * V_12 , unsigned int V_404 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_335 ;
enum V_410 type ;
type = F_384 ( V_404 ) ;
V_335 = F_385 ( V_404 ) ;
switch ( V_335 ) {
case V_425 :
if ( type == V_411 )
F_399 ( & V_2 -> V_60 ) ;
else if ( type == V_412 )
F_399 ( & V_2 -> V_158 ) ;
else if ( type == V_413 )
F_399 ( & V_2 -> V_32 ) ;
else
return - V_353 ;
break;
case V_178 :
if ( type == V_411 )
F_400 ( & V_2 -> V_60 ) ;
else if ( type == V_412 )
F_400 ( & V_2 -> V_158 ) ;
else if ( type == V_413 )
F_400 ( & V_2 -> V_32 ) ;
else
return - V_353 ;
break;
}
return 0 ;
}
static T_1 F_401 ( struct V_10 * V_12 ,
struct V_405 * V_406 )
{
return F_11 ( V_12 ) -> V_426 ;
}
static int F_402 ( struct V_10 * V_12 ,
struct V_405 * V_406 , T_1 V_69 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_69 >= ( 1 << V_427 ) )
return - V_353 ;
V_2 -> V_426 = V_69 ;
return 0 ;
}
static int F_402 ( struct V_10 * V_12 ,
struct V_405 * V_406 , T_1 V_69 )
{
return - V_428 ;
}
static int F_403 ( struct V_305 * V_306 , void * V_307 )
{
struct V_429 {
const char * V_335 ;
unsigned int V_91 ;
};
static const struct V_429 V_430 [] = {
{ L_15 , V_431 } ,
{ L_16 , V_208 } ,
{ L_17 , V_209 } ,
{ L_18 , F_81 (LRU_UNEVICTABLE) } ,
} ;
const struct V_429 * V_71 ;
int V_35 ;
unsigned long V_432 ;
struct V_1 * V_2 = F_11 ( F_266 ( V_306 ) ) ;
for ( V_71 = V_430 ; V_71 < V_430 + F_404 ( V_430 ) ; V_71 ++ ) {
V_432 = F_83 ( V_2 , V_71 -> V_91 ) ;
F_405 ( V_306 , L_19 , V_71 -> V_335 , V_432 ) ;
F_84 (nid, N_MEMORY) {
V_432 = F_82 ( V_2 , V_35 ,
V_71 -> V_91 ) ;
F_405 ( V_306 , L_20 , V_35 , V_432 ) ;
}
F_406 ( V_306 , '\n' ) ;
}
for ( V_71 = V_430 ; V_71 < V_430 + F_404 ( V_430 ) ; V_71 ++ ) {
struct V_1 * V_122 ;
V_432 = 0 ;
F_152 (iter, memcg)
V_432 += F_83 ( V_122 , V_71 -> V_91 ) ;
F_405 ( V_306 , L_21 , V_71 -> V_335 , V_432 ) ;
F_84 (nid, N_MEMORY) {
V_432 = 0 ;
F_152 (iter, memcg)
V_432 += F_82 (
V_122 , V_35 , V_71 -> V_91 ) ;
F_405 ( V_306 , L_20 , V_35 , V_432 ) ;
}
F_406 ( V_306 , '\n' ) ;
}
return 0 ;
}
static inline void F_407 ( void )
{
F_408 ( F_404 ( V_182 ) != V_181 ) ;
}
static int F_409 ( struct V_305 * V_306 , void * V_307 )
{
struct V_1 * V_2 = F_11 ( F_266 ( V_306 ) ) ;
struct V_1 * V_433 ;
unsigned int V_176 ;
for ( V_176 = 0 ; V_176 < V_179 ; V_176 ++ ) {
if ( V_176 == V_76 && ! V_157 )
continue;
F_405 ( V_306 , L_22 , V_180 [ V_176 ] ,
F_63 ( V_2 , V_176 ) * V_253 ) ;
}
for ( V_176 = 0 ; V_176 < V_261 ; V_176 ++ )
F_405 ( V_306 , L_23 , V_434 [ V_176 ] ,
F_71 ( V_2 , V_176 ) ) ;
for ( V_176 = 0 ; V_176 < V_181 ; V_176 ++ )
F_405 ( V_306 , L_23 , V_182 [ V_176 ] ,
F_83 ( V_2 , F_81 ( V_176 ) ) * V_253 ) ;
{
unsigned long long V_184 , V_421 ;
F_397 ( V_2 , & V_184 , & V_421 ) ;
F_405 ( V_306 , L_24 , V_184 ) ;
if ( V_157 )
F_405 ( V_306 , L_25 ,
V_421 ) ;
}
for ( V_176 = 0 ; V_176 < V_179 ; V_176 ++ ) {
long long V_69 = 0 ;
if ( V_176 == V_76 && ! V_157 )
continue;
F_152 (mi, memcg)
V_69 += F_63 ( V_433 , V_176 ) * V_253 ;
F_405 ( V_306 , L_26 , V_180 [ V_176 ] , V_69 ) ;
}
for ( V_176 = 0 ; V_176 < V_261 ; V_176 ++ ) {
unsigned long long V_69 = 0 ;
F_152 (mi, memcg)
V_69 += F_71 ( V_433 , V_176 ) ;
F_405 ( V_306 , L_27 ,
V_434 [ V_176 ] , V_69 ) ;
}
for ( V_176 = 0 ; V_176 < V_181 ; V_176 ++ ) {
unsigned long long V_69 = 0 ;
F_152 (mi, memcg)
V_69 += F_83 ( V_433 , F_81 ( V_176 ) ) * V_253 ;
F_405 ( V_306 , L_27 , V_182 [ V_176 ] , V_69 ) ;
}
#ifdef F_410
{
int V_35 , V_36 ;
struct V_34 * V_45 ;
struct V_435 * V_436 ;
unsigned long V_437 [ 2 ] = { 0 , 0 } ;
unsigned long V_438 [ 2 ] = { 0 , 0 } ;
F_411 (nid)
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ ) {
V_45 = F_38 ( V_2 , V_35 , V_36 ) ;
V_436 = & V_45 -> V_87 . V_439 ;
V_437 [ 0 ] += V_436 -> V_437 [ 0 ] ;
V_437 [ 1 ] += V_436 -> V_437 [ 1 ] ;
V_438 [ 0 ] += V_436 -> V_438 [ 0 ] ;
V_438 [ 1 ] += V_436 -> V_438 [ 1 ] ;
}
F_405 ( V_306 , L_28 , V_437 [ 0 ] ) ;
F_405 ( V_306 , L_29 , V_437 [ 1 ] ) ;
F_405 ( V_306 , L_30 , V_438 [ 0 ] ) ;
F_405 ( V_306 , L_31 , V_438 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_412 ( struct V_10 * V_12 ,
struct V_405 * V_406 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
return F_127 ( V_2 ) ;
}
static int F_413 ( struct V_10 * V_12 ,
struct V_405 * V_406 , T_1 V_69 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_51 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
if ( V_69 > 100 || ! V_51 )
return - V_353 ;
F_147 ( & V_398 ) ;
if ( ( V_51 -> V_130 ) || F_373 ( V_2 ) ) {
F_154 ( & V_398 ) ;
return - V_353 ;
}
V_2 -> V_160 = V_69 ;
F_154 ( & V_398 ) ;
return 0 ;
}
static void F_414 ( struct V_1 * V_2 , bool V_409 )
{
struct V_440 * V_441 ;
T_1 V_397 ;
int V_176 ;
F_22 () ;
if ( ! V_409 )
V_441 = F_94 ( V_2 -> V_442 . V_443 ) ;
else
V_441 = F_94 ( V_2 -> V_444 . V_443 ) ;
if ( ! V_441 )
goto V_165;
V_397 = F_382 ( V_2 , V_409 ) ;
V_176 = V_441 -> V_445 ;
for (; V_176 >= 0 && F_89 ( V_441 -> V_446 [ V_176 ] . V_447 > V_397 ) ; V_176 -- )
F_415 ( V_441 -> V_446 [ V_176 ] . V_448 , 1 ) ;
V_176 ++ ;
for (; V_176 < V_441 -> V_312 && F_89 ( V_441 -> V_446 [ V_176 ] . V_447 <= V_397 ) ; V_176 ++ )
F_415 ( V_441 -> V_446 [ V_176 ] . V_448 , 1 ) ;
V_441 -> V_445 = V_176 - 1 ;
V_165:
F_26 () ;
}
static void F_90 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_414 ( V_2 , false ) ;
if ( V_157 )
F_414 ( V_2 , true ) ;
V_2 = F_56 ( V_2 ) ;
}
}
static int F_416 ( const void * V_449 , const void * V_450 )
{
const struct F_90 * V_451 = V_449 ;
const struct F_90 * V_452 = V_450 ;
if ( V_451 -> V_447 > V_452 -> V_447 )
return 1 ;
if ( V_451 -> V_447 < V_452 -> V_447 )
return - 1 ;
return 0 ;
}
static int F_417 ( struct V_1 * V_2 )
{
struct V_453 * V_454 ;
F_268 (ev, &memcg->oom_notify, list)
F_415 ( V_454 -> V_448 , 1 ) ;
return 0 ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_152 (iter, memcg)
F_417 ( V_122 ) ;
}
static int F_418 ( struct V_1 * V_2 ,
struct V_455 * V_448 , const char * args , enum V_410 type )
{
struct V_456 * V_442 ;
struct V_440 * V_332 ;
T_1 V_447 , V_397 ;
int V_176 , V_312 , V_92 ;
V_92 = F_395 ( args , & V_447 ) ;
if ( V_92 )
return V_92 ;
F_147 ( & V_2 -> V_457 ) ;
if ( type == V_411 )
V_442 = & V_2 -> V_442 ;
else if ( type == V_412 )
V_442 = & V_2 -> V_444 ;
else
F_109 () ;
V_397 = F_382 ( V_2 , type == V_412 ) ;
if ( V_442 -> V_443 )
F_414 ( V_2 , type == V_412 ) ;
V_312 = V_442 -> V_443 ? V_442 -> V_443 -> V_312 + 1 : 1 ;
V_332 = F_298 ( sizeof( * V_332 ) + V_312 * sizeof( struct F_90 ) ,
V_322 ) ;
if ( ! V_332 ) {
V_92 = - V_291 ;
goto V_165;
}
V_332 -> V_312 = V_312 ;
if ( V_442 -> V_443 ) {
memcpy ( V_332 -> V_446 , V_442 -> V_443 -> V_446 , ( V_312 - 1 ) *
sizeof( struct F_90 ) ) ;
}
V_332 -> V_446 [ V_312 - 1 ] . V_448 = V_448 ;
V_332 -> V_446 [ V_312 - 1 ] . V_447 = V_447 ;
F_419 ( V_332 -> V_446 , V_312 , sizeof( struct F_90 ) ,
F_416 , NULL ) ;
V_332 -> V_445 = - 1 ;
for ( V_176 = 0 ; V_176 < V_312 ; V_176 ++ ) {
if ( V_332 -> V_446 [ V_176 ] . V_447 <= V_397 ) {
++ V_332 -> V_445 ;
} else
break;
}
F_284 ( V_442 -> V_458 ) ;
V_442 -> V_458 = V_442 -> V_443 ;
F_279 ( V_442 -> V_443 , V_332 ) ;
F_130 () ;
V_165:
F_154 ( & V_2 -> V_457 ) ;
return V_92 ;
}
static int F_420 ( struct V_1 * V_2 ,
struct V_455 * V_448 , const char * args )
{
return F_418 ( V_2 , V_448 , args , V_411 ) ;
}
static int F_421 ( struct V_1 * V_2 ,
struct V_455 * V_448 , const char * args )
{
return F_418 ( V_2 , V_448 , args , V_412 ) ;
}
static void F_422 ( struct V_1 * V_2 ,
struct V_455 * V_448 , enum V_410 type )
{
struct V_456 * V_442 ;
struct V_440 * V_332 ;
T_1 V_397 ;
int V_176 , V_459 , V_312 ;
F_147 ( & V_2 -> V_457 ) ;
if ( type == V_411 )
V_442 = & V_2 -> V_442 ;
else if ( type == V_412 )
V_442 = & V_2 -> V_444 ;
else
F_109 () ;
if ( ! V_442 -> V_443 )
goto V_165;
V_397 = F_382 ( V_2 , type == V_412 ) ;
F_414 ( V_2 , type == V_412 ) ;
V_312 = 0 ;
for ( V_176 = 0 ; V_176 < V_442 -> V_443 -> V_312 ; V_176 ++ ) {
if ( V_442 -> V_443 -> V_446 [ V_176 ] . V_448 != V_448 )
V_312 ++ ;
}
V_332 = V_442 -> V_458 ;
if ( ! V_312 ) {
F_284 ( V_332 ) ;
V_332 = NULL ;
goto V_460;
}
V_332 -> V_312 = V_312 ;
V_332 -> V_445 = - 1 ;
for ( V_176 = 0 , V_459 = 0 ; V_176 < V_442 -> V_443 -> V_312 ; V_176 ++ ) {
if ( V_442 -> V_443 -> V_446 [ V_176 ] . V_448 == V_448 )
continue;
V_332 -> V_446 [ V_459 ] = V_442 -> V_443 -> V_446 [ V_176 ] ;
if ( V_332 -> V_446 [ V_459 ] . V_447 <= V_397 ) {
++ V_332 -> V_445 ;
}
V_459 ++ ;
}
V_460:
V_442 -> V_458 = V_442 -> V_443 ;
if ( ! V_332 ) {
F_284 ( V_442 -> V_458 ) ;
V_442 -> V_458 = NULL ;
}
F_279 ( V_442 -> V_443 , V_332 ) ;
F_130 () ;
V_165:
F_154 ( & V_2 -> V_457 ) ;
}
static void F_423 ( struct V_1 * V_2 ,
struct V_455 * V_448 )
{
return F_422 ( V_2 , V_448 , V_411 ) ;
}
static void F_424 ( struct V_1 * V_2 ,
struct V_455 * V_448 )
{
return F_422 ( V_2 , V_448 , V_412 ) ;
}
static int F_425 ( struct V_1 * V_2 ,
struct V_455 * V_448 , const char * args )
{
struct V_453 * V_404 ;
V_404 = F_298 ( sizeof( * V_404 ) , V_322 ) ;
if ( ! V_404 )
return - V_291 ;
F_53 ( & V_219 ) ;
V_404 -> V_448 = V_448 ;
F_287 ( & V_404 -> V_327 , & V_2 -> V_461 ) ;
if ( F_99 ( & V_2 -> V_223 ) )
F_415 ( V_448 , 1 ) ;
F_54 ( & V_219 ) ;
return 0 ;
}
static void F_426 ( struct V_1 * V_2 ,
struct V_455 * V_448 )
{
struct V_453 * V_454 , * V_424 ;
F_53 ( & V_219 ) ;
F_427 (ev, tmp, &memcg->oom_notify, list) {
if ( V_454 -> V_448 == V_448 ) {
F_289 ( & V_454 -> V_327 ) ;
F_284 ( V_454 ) ;
}
}
F_54 ( & V_219 ) ;
}
static int F_428 ( struct V_305 * V_462 , void * V_307 )
{
struct V_1 * V_2 = F_11 ( F_266 ( V_462 ) ) ;
F_405 ( V_462 , L_32 , V_2 -> V_244 ) ;
F_405 ( V_462 , L_33 , ( bool ) F_99 ( & V_2 -> V_223 ) ) ;
return 0 ;
}
static int F_429 ( struct V_10 * V_12 ,
struct V_405 * V_406 , T_1 V_69 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_51 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
if ( ! V_51 || ! ( ( V_69 == 0 ) || ( V_69 == 1 ) ) )
return - V_353 ;
F_147 ( & V_398 ) ;
if ( ( V_51 -> V_130 ) || F_373 ( V_2 ) ) {
F_154 ( & V_398 ) ;
return - V_353 ;
}
V_2 -> V_244 = V_69 ;
if ( ! V_69 )
F_199 ( V_2 ) ;
F_154 ( & V_398 ) ;
return 0 ;
}
static int F_430 ( struct V_1 * V_2 , struct V_463 * V_464 )
{
int V_92 ;
V_2 -> V_31 = - 1 ;
V_92 = F_393 ( V_2 ) ;
if ( V_92 )
return V_92 ;
return F_431 ( V_2 , V_464 ) ;
}
static void F_432 ( struct V_1 * V_2 )
{
F_433 ( V_2 ) ;
}
static void F_434 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_2 ) )
return;
F_21 ( & V_2 -> V_12 ) ;
F_5 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_32 , V_33 ) != 0 )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
static int F_430 ( struct V_1 * V_2 , struct V_463 * V_464 )
{
return 0 ;
}
static void F_432 ( struct V_1 * V_2 )
{
}
static void F_434 ( struct V_1 * V_2 )
{
}
static void F_435 ( struct V_254 * V_257 )
{
struct V_465 * V_404 =
F_12 ( V_257 , struct V_465 , remove ) ;
struct V_1 * V_2 = V_404 -> V_2 ;
F_436 ( V_404 -> V_466 , & V_404 -> V_167 ) ;
V_404 -> V_467 ( V_2 , V_404 -> V_448 ) ;
F_415 ( V_404 -> V_448 , 1 ) ;
F_437 ( V_404 -> V_448 ) ;
F_284 ( V_404 ) ;
F_29 ( & V_2 -> V_12 ) ;
}
static int F_438 ( T_4 * V_167 , unsigned V_224 ,
int V_225 , void * V_468 )
{
struct V_465 * V_404 =
F_12 ( V_167 , struct V_465 , V_167 ) ;
struct V_1 * V_2 = V_404 -> V_2 ;
unsigned long V_118 = ( unsigned long ) V_468 ;
if ( V_118 & V_469 ) {
F_53 ( & V_2 -> V_470 ) ;
if ( ! F_367 ( & V_404 -> V_327 ) ) {
F_439 ( & V_404 -> V_327 ) ;
F_296 ( & V_404 -> remove ) ;
}
F_54 ( & V_2 -> V_470 ) ;
}
return 0 ;
}
static void F_440 ( struct V_471 * V_471 ,
T_9 * V_466 , T_10 * V_472 )
{
struct V_465 * V_404 =
F_12 ( V_472 , struct V_465 , V_472 ) ;
V_404 -> V_466 = V_466 ;
F_441 ( V_466 , & V_404 -> V_167 ) ;
}
static int F_442 ( struct V_10 * V_12 ,
struct V_405 * V_406 , const char * V_418 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_465 * V_404 ;
struct V_10 * V_473 ;
unsigned int V_474 , V_475 ;
struct V_476 V_477 ;
struct V_476 V_478 ;
const char * V_335 ;
char * V_479 ;
int V_92 ;
V_474 = F_443 ( V_418 , & V_479 , 10 ) ;
if ( * V_479 != ' ' )
return - V_353 ;
V_418 = V_479 + 1 ;
V_475 = F_443 ( V_418 , & V_479 , 10 ) ;
if ( ( * V_479 != ' ' ) && ( * V_479 != '\0' ) )
return - V_353 ;
V_418 = V_479 + 1 ;
V_404 = F_278 ( sizeof( * V_404 ) , V_322 ) ;
if ( ! V_404 )
return - V_291 ;
V_404 -> V_2 = V_2 ;
F_202 ( & V_404 -> V_327 ) ;
F_444 ( & V_404 -> V_472 , F_440 ) ;
F_445 ( & V_404 -> V_167 , F_438 ) ;
F_217 ( & V_404 -> remove , F_435 ) ;
V_477 = F_446 ( V_474 ) ;
if ( ! V_477 . V_471 ) {
V_92 = - V_480 ;
goto V_481;
}
V_404 -> V_448 = F_447 ( V_477 . V_471 ) ;
if ( F_448 ( V_404 -> V_448 ) ) {
V_92 = F_449 ( V_404 -> V_448 ) ;
goto V_482;
}
V_478 = F_446 ( V_475 ) ;
if ( ! V_478 . V_471 ) {
V_92 = - V_480 ;
goto V_483;
}
V_92 = F_450 ( F_451 ( V_478 . V_471 ) , V_484 ) ;
if ( V_92 < 0 )
goto V_485;
V_335 = V_478 . V_471 -> V_486 -> V_487 . V_335 ;
if ( ! strcmp ( V_335 , L_34 ) ) {
V_404 -> V_488 = F_420 ;
V_404 -> V_467 = F_423 ;
} else if ( ! strcmp ( V_335 , L_35 ) ) {
V_404 -> V_488 = F_425 ;
V_404 -> V_467 = F_426 ;
} else if ( ! strcmp ( V_335 , L_36 ) ) {
V_404 -> V_488 = V_489 ;
V_404 -> V_467 = V_490 ;
} else if ( ! strcmp ( V_335 , L_37 ) ) {
V_404 -> V_488 = F_421 ;
V_404 -> V_467 = F_424 ;
} else {
V_92 = - V_353 ;
goto V_485;
}
F_22 () ;
V_92 = - V_353 ;
V_473 = F_452 ( V_478 . V_471 -> V_486 -> V_491 ,
& V_18 ) ;
if ( V_473 == V_12 && F_25 ( V_12 ) )
V_92 = 0 ;
F_26 () ;
if ( V_92 )
goto V_485;
V_92 = V_404 -> V_488 ( V_2 , V_404 -> V_448 , V_418 ) ;
if ( V_92 )
goto V_492;
V_477 . V_471 -> V_493 -> V_494 ( V_477 . V_471 , & V_404 -> V_472 ) ;
F_53 ( & V_2 -> V_470 ) ;
F_287 ( & V_404 -> V_327 , & V_2 -> V_495 ) ;
F_54 ( & V_2 -> V_470 ) ;
F_453 ( V_478 ) ;
F_453 ( V_477 ) ;
return 0 ;
V_492:
F_29 ( V_12 ) ;
V_485:
F_453 ( V_478 ) ;
V_483:
F_437 ( V_404 -> V_448 ) ;
V_482:
F_453 ( V_477 ) ;
V_481:
F_284 ( V_404 ) ;
return V_92 ;
}
static int F_454 ( struct V_1 * V_2 , int V_61 )
{
struct V_496 * V_497 ;
struct V_34 * V_45 ;
int V_62 , V_424 = V_61 ;
if ( ! F_455 ( V_61 , V_498 ) )
V_424 = - 1 ;
V_497 = F_456 ( sizeof( * V_497 ) , V_322 , V_424 ) ;
if ( ! V_497 )
return 1 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_45 = & V_497 -> V_39 [ V_62 ] ;
F_457 ( & V_45 -> V_87 ) ;
V_45 -> V_54 = 0 ;
V_45 -> V_53 = false ;
V_45 -> V_2 = V_2 ;
}
V_2 -> V_38 [ V_61 ] = V_497 ;
return 0 ;
}
static void F_458 ( struct V_1 * V_2 , int V_61 )
{
F_284 ( V_2 -> V_38 [ V_61 ] ) ;
}
static struct V_1 * F_459 ( void )
{
struct V_1 * V_2 ;
T_7 V_312 ;
V_312 = sizeof( struct V_1 ) ;
V_312 += V_37 * sizeof( struct V_496 * ) ;
V_2 = F_278 ( V_312 , V_322 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_71 = F_460 ( struct V_499 ) ;
if ( ! V_2 -> V_71 )
goto V_500;
F_461 ( & V_2 -> V_73 ) ;
return V_2 ;
V_500:
F_284 ( V_2 ) ;
return NULL ;
}
static void F_462 ( struct V_1 * V_2 )
{
int V_61 ;
F_58 ( V_2 ) ;
F_59 (node)
F_458 ( V_2 , V_61 ) ;
F_463 ( V_2 -> V_71 ) ;
F_37 ( V_2 ) ;
F_284 ( V_2 ) ;
}
struct V_1 * F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_60 . V_51 )
return NULL ;
return F_233 ( V_2 -> V_60 . V_51 , V_60 ) ;
}
static void T_5 F_464 ( void )
{
struct V_501 * V_502 ;
struct V_41 * V_503 ;
int V_424 , V_61 , V_62 ;
F_59 (node) {
V_424 = V_61 ;
if ( ! F_455 ( V_61 , V_498 ) )
V_424 = - 1 ;
V_502 = F_456 ( sizeof( * V_502 ) , V_322 , V_424 ) ;
F_20 ( ! V_502 ) ;
V_42 . V_43 [ V_61 ] = V_502 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_503 = & V_502 -> V_44 [ V_62 ] ;
V_503 -> V_50 = V_504 ;
F_461 ( & V_503 -> V_58 ) ;
}
}
}
static struct V_10 * T_11
F_465 ( struct V_10 * V_505 )
{
struct V_1 * V_2 ;
long error = - V_291 ;
int V_61 ;
V_2 = F_459 () ;
if ( ! V_2 )
return F_466 ( error ) ;
F_59 (node)
if ( F_454 ( V_2 , V_61 ) )
goto V_506;
if ( V_505 == NULL ) {
V_14 = V_2 ;
F_467 ( & V_2 -> V_60 , NULL ) ;
F_467 ( & V_2 -> V_158 , NULL ) ;
F_467 ( & V_2 -> V_32 , NULL ) ;
}
V_2 -> V_214 = V_106 ;
F_202 ( & V_2 -> V_461 ) ;
V_2 -> V_426 = 0 ;
F_389 ( & V_2 -> V_457 ) ;
F_461 ( & V_2 -> V_170 ) ;
F_468 ( & V_2 -> V_13 ) ;
F_202 ( & V_2 -> V_495 ) ;
F_461 ( & V_2 -> V_470 ) ;
return & V_2 -> V_12 ;
V_506:
F_462 ( V_2 ) ;
return F_466 ( error ) ;
}
static int
F_469 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_51 = F_11 ( F_128 ( V_12 ) ) ;
if ( V_12 -> V_16 -> V_17 > V_507 )
return - V_508 ;
if ( ! V_51 )
return 0 ;
F_147 ( & V_398 ) ;
V_2 -> V_130 = V_51 -> V_130 ;
V_2 -> V_244 = V_51 -> V_244 ;
V_2 -> V_160 = F_127 ( V_51 ) ;
if ( V_51 -> V_130 ) {
F_467 ( & V_2 -> V_60 , & V_51 -> V_60 ) ;
F_467 ( & V_2 -> V_158 , & V_51 -> V_158 ) ;
F_467 ( & V_2 -> V_32 , & V_51 -> V_32 ) ;
} else {
F_467 ( & V_2 -> V_60 , NULL ) ;
F_467 ( & V_2 -> V_158 , NULL ) ;
F_467 ( & V_2 -> V_32 , NULL ) ;
if ( V_51 != V_14 )
V_18 . V_509 = true ;
}
F_154 ( & V_398 ) ;
return F_430 ( V_2 , & V_18 ) ;
}
static void F_470 ( struct V_1 * V_2 )
{
struct V_1 * V_51 = V_2 ;
while ( ( V_51 = F_56 ( V_51 ) ) )
F_97 ( V_51 ) ;
if ( ! V_14 -> V_130 )
F_97 ( V_14 ) ;
}
static void F_471 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_465 * V_404 , * V_424 ;
struct V_10 * V_122 ;
F_53 ( & V_2 -> V_470 ) ;
F_427 (event, tmp, &memcg->event_list, list) {
F_439 ( & V_404 -> V_327 ) ;
F_296 ( & V_404 -> remove ) ;
}
F_54 ( & V_2 -> V_470 ) ;
F_434 ( V_2 ) ;
F_470 ( V_2 ) ;
F_472 (iter, css)
F_371 ( F_11 ( V_122 ) ) ;
F_304 ( V_2 ) ;
F_473 ( & V_2 -> V_13 ) ;
}
static void F_474 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_371 ( V_2 ) ;
F_432 ( V_2 ) ;
F_462 ( V_2 ) ;
}
static int F_475 ( unsigned long V_72 )
{
int V_92 = 0 ;
int V_510 = V_511 ;
struct V_1 * V_2 = V_7 . V_164 ;
if ( F_15 ( V_2 ) ) {
V_7 . V_512 += V_72 ;
return V_92 ;
}
if ( V_72 > 1 ) {
struct V_274 * V_255 ;
if ( F_231 ( & V_2 -> V_60 , V_253 * V_72 , & V_255 ) )
goto V_513;
if ( V_157 && F_231 ( & V_2 -> V_158 ,
V_253 * V_72 , & V_255 ) ) {
F_211 ( & V_2 -> V_60 , V_253 * V_72 ) ;
goto V_513;
}
V_7 . V_512 += V_72 ;
return V_92 ;
}
V_513:
while ( V_72 -- ) {
if ( F_361 ( V_26 ) ) {
V_92 = - V_292 ;
break;
}
if ( ! V_510 -- ) {
V_510 = V_511 ;
F_370 () ;
}
V_92 = F_235 ( NULL ,
V_322 , 1 , & V_2 , false ) ;
if ( V_92 )
return V_92 ;
V_7 . V_512 ++ ;
}
return V_92 ;
}
static struct V_40 * F_476 ( struct V_514 * V_515 ,
unsigned long V_516 , T_12 V_517 )
{
struct V_40 * V_40 = F_477 ( V_515 , V_516 , V_517 ) ;
if ( ! V_40 || ! F_318 ( V_40 ) )
return NULL ;
if ( F_317 ( V_40 ) ) {
if ( ! F_9 () )
return NULL ;
} else if ( ! F_10 () )
return NULL ;
if ( ! F_321 ( V_40 ) )
return NULL ;
return V_40 ;
}
static struct V_40 * F_478 ( struct V_514 * V_515 ,
unsigned long V_516 , T_12 V_517 , T_6 * V_373 )
{
struct V_40 * V_40 = NULL ;
T_6 V_293 = F_479 ( V_517 ) ;
if ( ! F_9 () || F_480 ( V_293 ) )
return NULL ;
V_40 = F_481 ( F_482 ( V_293 ) , V_293 . V_69 ) ;
if ( V_157 )
V_373 -> V_69 = V_293 . V_69 ;
return V_40 ;
}
static struct V_40 * F_478 ( struct V_514 * V_515 ,
unsigned long V_516 , T_12 V_517 , T_6 * V_373 )
{
return NULL ;
}
static struct V_40 * F_483 ( struct V_514 * V_515 ,
unsigned long V_516 , T_12 V_517 , T_6 * V_373 )
{
struct V_40 * V_40 = NULL ;
struct V_518 * V_358 ;
T_13 V_519 ;
if ( ! V_515 -> V_520 )
return NULL ;
if ( ! F_10 () )
return NULL ;
V_358 = V_515 -> V_520 -> V_521 ;
if ( F_484 ( V_517 ) )
V_519 = F_485 ( V_515 , V_516 ) ;
else
V_519 = F_486 ( V_517 ) ;
V_40 = F_481 ( V_358 , V_519 ) ;
#ifdef F_487
if ( F_488 ( V_40 ) ) {
T_6 V_409 = F_489 ( V_40 ) ;
if ( V_157 )
* V_373 = V_409 ;
V_40 = F_481 ( F_482 ( V_409 ) , V_409 . V_69 ) ;
}
#endif
return V_40 ;
}
static enum V_522 F_490 ( struct V_514 * V_515 ,
unsigned long V_516 , T_12 V_517 , union V_523 * V_95 )
{
struct V_40 * V_40 = NULL ;
struct V_144 * V_145 ;
enum V_522 V_92 = V_524 ;
T_6 V_293 = { . V_69 = 0 } ;
if ( F_491 ( V_517 ) )
V_40 = F_476 ( V_515 , V_516 , V_517 ) ;
else if ( F_492 ( V_517 ) )
V_40 = F_478 ( V_515 , V_516 , V_517 , & V_293 ) ;
else if ( F_484 ( V_517 ) || F_493 ( V_517 ) )
V_40 = F_483 ( V_515 , V_516 , V_517 , & V_293 ) ;
if ( ! V_40 && ! V_293 . V_69 )
return V_92 ;
if ( V_40 ) {
V_145 = F_112 ( V_40 ) ;
if ( F_114 ( V_145 ) && V_145 -> V_1 == V_7 . V_163 ) {
V_92 = V_525 ;
if ( V_95 )
V_95 -> V_40 = V_40 ;
}
if ( ! V_92 || ! V_95 )
F_327 ( V_40 ) ;
}
if ( V_293 . V_69 && ! V_92 &&
F_16 ( V_7 . V_163 ) == F_249 ( V_293 ) ) {
V_92 = V_526 ;
if ( V_95 )
V_95 -> V_293 = V_293 ;
}
return V_92 ;
}
static enum V_522 F_494 ( struct V_514 * V_515 ,
unsigned long V_516 , T_14 V_527 , union V_523 * V_95 )
{
struct V_40 * V_40 = NULL ;
struct V_144 * V_145 ;
enum V_522 V_92 = V_524 ;
V_40 = F_495 ( V_527 ) ;
F_244 ( ! V_40 || ! F_496 ( V_40 ) , V_40 ) ;
if ( ! F_9 () )
return V_92 ;
V_145 = F_112 ( V_40 ) ;
if ( F_114 ( V_145 ) && V_145 -> V_1 == V_7 . V_163 ) {
V_92 = V_525 ;
if ( V_95 ) {
F_497 ( V_40 ) ;
V_95 -> V_40 = V_40 ;
}
}
return V_92 ;
}
static inline enum V_522 F_494 ( struct V_514 * V_515 ,
unsigned long V_516 , T_14 V_527 , union V_523 * V_95 )
{
return V_524 ;
}
static int F_498 ( T_14 * V_527 ,
unsigned long V_516 , unsigned long V_528 ,
struct V_529 * V_530 )
{
struct V_514 * V_515 = V_530 -> V_241 ;
T_12 * V_531 ;
T_15 * V_532 ;
if ( F_499 ( V_527 , V_515 , & V_532 ) == 1 ) {
if ( F_494 ( V_515 , V_516 , * V_527 , NULL ) == V_525 )
V_7 . V_512 += V_350 ;
F_54 ( V_532 ) ;
return 0 ;
}
if ( F_500 ( V_527 ) )
return 0 ;
V_531 = F_501 ( V_515 -> V_533 , V_527 , V_516 , & V_532 ) ;
for (; V_516 != V_528 ; V_531 ++ , V_516 += V_253 )
if ( F_490 ( V_515 , V_516 , * V_531 , NULL ) )
V_7 . V_512 ++ ;
F_502 ( V_531 - 1 , V_532 ) ;
F_370 () ;
return 0 ;
}
static unsigned long F_503 ( struct V_110 * V_111 )
{
unsigned long V_512 ;
struct V_514 * V_515 ;
F_504 ( & V_111 -> V_534 ) ;
for ( V_515 = V_111 -> V_535 ; V_515 ; V_515 = V_515 -> V_536 ) {
struct V_529 V_537 = {
. V_538 = F_498 ,
. V_111 = V_111 ,
. V_241 = V_515 ,
} ;
if ( F_505 ( V_515 ) )
continue;
F_506 ( V_515 -> V_539 , V_515 -> V_540 ,
& V_537 ) ;
}
F_507 ( & V_111 -> V_534 ) ;
V_512 = V_7 . V_512 ;
V_7 . V_512 = 0 ;
return V_512 ;
}
static int F_508 ( struct V_110 * V_111 )
{
unsigned long V_512 = F_503 ( V_111 ) ;
F_39 ( V_7 . V_166 ) ;
V_7 . V_166 = V_26 ;
return F_475 ( V_512 ) ;
}
static void F_509 ( void )
{
struct V_1 * V_163 = V_7 . V_163 ;
struct V_1 * V_164 = V_7 . V_164 ;
int V_176 ;
if ( V_7 . V_512 ) {
F_239 ( V_7 . V_164 , V_7 . V_512 ) ;
V_7 . V_512 = 0 ;
}
if ( V_7 . V_541 ) {
F_239 ( V_7 . V_163 , V_7 . V_541 ) ;
V_7 . V_541 = 0 ;
}
if ( V_7 . V_542 ) {
if ( ! F_15 ( V_7 . V_163 ) )
F_211 ( & V_7 . V_163 -> V_158 ,
V_253 * V_7 . V_542 ) ;
for ( V_176 = 0 ; V_176 < V_7 . V_542 ; V_176 ++ )
F_29 ( & V_7 . V_163 -> V_12 ) ;
if ( ! F_15 ( V_7 . V_164 ) ) {
F_211 ( & V_7 . V_164 -> V_60 ,
V_253 * V_7 . V_542 ) ;
}
V_7 . V_542 = 0 ;
}
F_199 ( V_163 ) ;
F_199 ( V_164 ) ;
F_510 ( & V_7 . V_168 ) ;
}
static void F_511 ( void )
{
struct V_1 * V_163 = V_7 . V_163 ;
V_7 . V_166 = NULL ;
F_509 () ;
F_53 ( & V_7 . V_58 ) ;
V_7 . V_163 = NULL ;
V_7 . V_164 = NULL ;
F_54 ( & V_7 . V_58 ) ;
F_131 ( V_163 ) ;
}
static int F_512 ( struct V_10 * V_12 ,
struct V_543 * V_544 )
{
struct V_108 * V_49 = F_513 ( V_544 ) ;
int V_92 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned long V_426 ;
V_426 = V_2 -> V_426 ;
if ( V_426 ) {
struct V_110 * V_111 ;
struct V_1 * V_163 = F_23 ( V_49 ) ;
F_39 ( V_163 == V_2 ) ;
V_111 = F_514 ( V_49 ) ;
if ( ! V_111 )
return 0 ;
if ( V_111 -> V_112 == V_49 ) {
F_39 ( V_7 . V_163 ) ;
F_39 ( V_7 . V_164 ) ;
F_39 ( V_7 . V_512 ) ;
F_39 ( V_7 . V_541 ) ;
F_39 ( V_7 . V_542 ) ;
F_129 ( V_163 ) ;
F_53 ( & V_7 . V_58 ) ;
V_7 . V_163 = V_163 ;
V_7 . V_164 = V_2 ;
V_7 . V_8 = V_426 ;
F_54 ( & V_7 . V_58 ) ;
V_92 = F_508 ( V_111 ) ;
if ( V_92 )
F_511 () ;
}
F_515 ( V_111 ) ;
}
return V_92 ;
}
static void F_516 ( struct V_10 * V_12 ,
struct V_543 * V_544 )
{
F_511 () ;
}
static int F_517 ( T_14 * V_527 ,
unsigned long V_516 , unsigned long V_528 ,
struct V_529 * V_530 )
{
int V_92 = 0 ;
struct V_514 * V_515 = V_530 -> V_241 ;
T_12 * V_531 ;
T_15 * V_532 ;
enum V_522 V_545 ;
union V_523 V_95 ;
struct V_40 * V_40 ;
struct V_144 * V_145 ;
if ( F_499 ( V_527 , V_515 , & V_532 ) == 1 ) {
if ( V_7 . V_512 < V_350 ) {
F_54 ( V_532 ) ;
return 0 ;
}
V_545 = F_494 ( V_515 , V_516 , * V_527 , & V_95 ) ;
if ( V_545 == V_525 ) {
V_40 = V_95 . V_40 ;
if ( ! F_322 ( V_40 ) ) {
V_145 = F_112 ( V_40 ) ;
if ( ! F_316 ( V_40 , V_350 ,
V_145 , V_7 . V_163 , V_7 . V_164 ) ) {
V_7 . V_512 -= V_350 ;
V_7 . V_541 += V_350 ;
}
F_326 ( V_40 ) ;
}
F_327 ( V_40 ) ;
}
F_54 ( V_532 ) ;
return 0 ;
}
if ( F_500 ( V_527 ) )
return 0 ;
V_65:
V_531 = F_501 ( V_515 -> V_533 , V_527 , V_516 , & V_532 ) ;
for (; V_516 != V_528 ; V_516 += V_253 ) {
T_12 V_517 = * ( V_531 ++ ) ;
T_6 V_293 ;
if ( ! V_7 . V_512 )
break;
switch ( F_490 ( V_515 , V_516 , V_517 , & V_95 ) ) {
case V_525 :
V_40 = V_95 . V_40 ;
if ( F_322 ( V_40 ) )
goto V_357;
V_145 = F_112 ( V_40 ) ;
if ( ! F_316 ( V_40 , 1 , V_145 ,
V_7 . V_163 , V_7 . V_164 ) ) {
V_7 . V_512 -- ;
V_7 . V_541 ++ ;
}
F_326 ( V_40 ) ;
V_357:
F_327 ( V_40 ) ;
break;
case V_526 :
V_293 = V_95 . V_293 ;
if ( ! F_349 ( V_293 , V_7 . V_163 , V_7 . V_164 ) ) {
V_7 . V_512 -- ;
V_7 . V_542 ++ ;
}
break;
default:
break;
}
}
F_502 ( V_531 - 1 , V_532 ) ;
F_370 () ;
if ( V_516 != V_528 ) {
V_92 = F_475 ( 1 ) ;
if ( ! V_92 )
goto V_65;
}
return V_92 ;
}
static void F_518 ( struct V_110 * V_111 )
{
struct V_514 * V_515 ;
F_372 () ;
V_65:
if ( F_89 ( ! F_519 ( & V_111 -> V_534 ) ) ) {
F_509 () ;
F_370 () ;
goto V_65;
}
for ( V_515 = V_111 -> V_535 ; V_515 ; V_515 = V_515 -> V_536 ) {
int V_92 ;
struct V_529 V_546 = {
. V_538 = F_517 ,
. V_111 = V_111 ,
. V_241 = V_515 ,
} ;
if ( F_505 ( V_515 ) )
continue;
V_92 = F_506 ( V_515 -> V_539 , V_515 -> V_540 ,
& V_546 ) ;
if ( V_92 )
break;
}
F_507 ( & V_111 -> V_534 ) ;
}
static void F_520 ( struct V_10 * V_12 ,
struct V_543 * V_544 )
{
struct V_108 * V_49 = F_513 ( V_544 ) ;
struct V_110 * V_111 = F_514 ( V_49 ) ;
if ( V_111 ) {
if ( V_7 . V_164 )
F_518 ( V_111 ) ;
F_515 ( V_111 ) ;
}
if ( V_7 . V_164 )
F_511 () ;
}
static int F_512 ( struct V_10 * V_12 ,
struct V_543 * V_544 )
{
return 0 ;
}
static void F_516 ( struct V_10 * V_12 ,
struct V_543 * V_544 )
{
}
static void F_520 ( struct V_10 * V_12 ,
struct V_543 * V_544 )
{
}
static void F_521 ( struct V_10 * V_547 )
{
if ( F_522 ( V_547 -> V_16 ) )
F_11 ( V_547 ) -> V_130 = true ;
}
static int T_5 F_523 ( char * V_11 )
{
if ( ! strcmp ( V_11 , L_38 ) )
V_548 = 1 ;
else if ( ! strcmp ( V_11 , L_39 ) )
V_548 = 0 ;
return 1 ;
}
static void T_5 F_524 ( void )
{
F_28 ( F_525 ( & V_18 , V_549 ) ) ;
}
static void T_5 F_526 ( void )
{
if ( ! F_103 () && V_548 ) {
V_157 = 1 ;
F_524 () ;
}
}
static void T_5 F_526 ( void )
{
}
static int T_5 F_527 ( void )
{
F_528 ( F_228 , 0 ) ;
F_526 () ;
F_464 () ;
F_215 () ;
return 0 ;
}
