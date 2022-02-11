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
if ( V_79 )
F_73 ( V_2 -> V_71 -> V_72 [ V_81 ] ,
V_80 ) ;
else
F_73 ( V_2 -> V_71 -> V_72 [ V_82 ] ,
V_80 ) ;
if ( F_74 ( V_40 ) )
F_73 ( V_2 -> V_71 -> V_72 [ V_83 ] ,
V_80 ) ;
if ( V_80 > 0 )
F_75 ( V_2 -> V_71 -> V_78 [ V_84 ] ) ;
else {
F_75 ( V_2 -> V_71 -> V_78 [ V_85 ] ) ;
V_80 = - V_80 ;
}
F_73 ( V_2 -> V_71 -> V_86 , V_80 ) ;
}
unsigned long
F_76 ( struct V_87 * V_87 , enum V_88 V_89 )
{
struct V_34 * V_45 ;
V_45 = F_12 ( V_87 , struct V_34 , V_87 ) ;
return V_45 -> V_90 [ V_89 ] ;
}
static unsigned long
F_77 ( struct V_1 * V_2 , int V_35 , int V_36 ,
unsigned int V_91 )
{
struct V_34 * V_45 ;
enum V_88 V_89 ;
unsigned long V_92 = 0 ;
V_45 = F_38 ( V_2 , V_35 , V_36 ) ;
F_78 (lru) {
if ( F_79 ( V_89 ) & V_91 )
V_92 += V_45 -> V_90 [ V_89 ] ;
}
return V_92 ;
}
static unsigned long
F_80 ( struct V_1 * V_2 ,
int V_35 , unsigned int V_91 )
{
T_1 V_93 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ )
V_93 += F_77 ( V_2 ,
V_35 , V_36 , V_91 ) ;
return V_93 ;
}
static unsigned long F_81 ( struct V_1 * V_2 ,
unsigned int V_91 )
{
int V_35 ;
T_1 V_93 = 0 ;
F_82 (nid, N_MEMORY)
V_93 += F_80 ( V_2 , V_35 , V_91 ) ;
return V_93 ;
}
static bool F_83 ( struct V_1 * V_2 ,
enum V_94 V_95 )
{
unsigned long V_69 , V_96 ;
V_69 = F_84 ( V_2 -> V_71 -> V_86 ) ;
V_96 = F_84 ( V_2 -> V_71 -> V_97 [ V_95 ] ) ;
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
F_85 ( V_2 -> V_71 -> V_97 [ V_95 ] , V_96 ) ;
return true ;
}
return false ;
}
static void F_86 ( struct V_1 * V_2 , struct V_40 * V_40 )
{
F_87 () ;
if ( F_88 ( F_83 ( V_2 ,
V_98 ) ) ) {
bool V_104 ;
bool T_2 V_105 ;
V_104 = F_83 ( V_2 ,
V_100 ) ;
#if V_106 > 1
T_2 = F_83 ( V_2 ,
V_102 ) ;
#endif
F_89 () ;
F_90 ( V_2 ) ;
if ( F_88 ( V_104 ) )
F_55 ( V_2 , V_40 ) ;
#if V_106 > 1
if ( F_88 ( T_2 ) )
F_91 ( & V_2 -> V_107 ) ;
#endif
} else
F_89 () ;
}
struct V_1 * F_23 ( struct V_108 * V_49 )
{
if ( F_88 ( ! V_49 ) )
return NULL ;
return F_11 ( F_92 ( V_49 , V_109 ) ) ;
}
static struct V_1 * F_93 ( struct V_110 * V_111 )
{
struct V_1 * V_2 = NULL ;
F_22 () ;
do {
if ( F_88 ( ! V_111 ) )
V_2 = V_14 ;
else {
V_2 = F_23 ( F_94 ( V_111 -> V_112 ) ) ;
if ( F_88 ( ! V_2 ) )
V_2 = V_14 ;
}
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
if ( F_88 ( ! V_2 ) )
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
if ( F_88 ( V_87 -> V_62 != V_62 ) )
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
if ( F_88 ( V_87 -> V_62 != V_62 ) )
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
V_150 = F_76 ( V_87 , V_153 ) ;
V_151 = F_76 ( V_87 , V_154 ) ;
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
struct V_1 * V_122 ;
unsigned int V_172 ;
if ( ! V_49 )
return;
F_147 ( & V_171 ) ;
F_22 () ;
F_148 ( L_1 ) ;
F_149 ( F_150 ( V_49 , V_109 ) ) ;
F_148 ( L_2 ) ;
F_149 ( V_2 -> V_12 . V_16 ) ;
F_148 ( L_3 ) ;
F_26 () ;
F_148 ( L_4 ,
F_36 ( & V_2 -> V_60 , V_33 ) >> 10 ,
F_36 ( & V_2 -> V_60 , V_173 ) >> 10 ,
F_36 ( & V_2 -> V_60 , V_174 ) ) ;
F_148 ( L_5 ,
F_36 ( & V_2 -> V_158 , V_33 ) >> 10 ,
F_36 ( & V_2 -> V_158 , V_173 ) >> 10 ,
F_36 ( & V_2 -> V_158 , V_174 ) ) ;
F_148 ( L_6 ,
F_36 ( & V_2 -> V_32 , V_33 ) >> 10 ,
F_36 ( & V_2 -> V_32 , V_173 ) >> 10 ,
F_36 ( & V_2 -> V_32 , V_174 ) ) ;
F_151 (iter, memcg) {
F_148 ( L_7 ) ;
F_149 ( V_122 -> V_12 . V_16 ) ;
F_152 ( L_8 ) ;
for ( V_172 = 0 ; V_172 < V_175 ; V_172 ++ ) {
if ( V_172 == V_76 && ! V_157 )
continue;
F_152 ( L_9 , V_176 [ V_172 ] ,
F_153 ( F_63 ( V_122 , V_172 ) ) ) ;
}
for ( V_172 = 0 ; V_172 < V_177 ; V_172 ++ )
F_152 ( L_10 , V_178 [ V_172 ] ,
F_153 ( F_81 ( V_122 , F_79 ( V_172 ) ) ) ) ;
F_152 ( L_3 ) ;
}
F_154 ( & V_171 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
int V_179 = 0 ;
struct V_1 * V_122 ;
F_151 (iter, memcg)
V_179 ++ ;
return V_179 ;
}
static T_1 F_156 ( struct V_1 * V_2 )
{
T_1 V_180 ;
V_180 = F_36 ( & V_2 -> V_60 , V_173 ) ;
if ( F_127 ( V_2 ) ) {
T_1 V_158 ;
V_180 += V_181 << V_155 ;
V_158 = F_36 ( & V_2 -> V_158 , V_173 ) ;
V_180 = F_126 ( V_180 , V_158 ) ;
}
return V_180 ;
}
static void F_157 ( struct V_1 * V_2 , T_3 V_182 ,
int V_183 )
{
struct V_1 * V_122 ;
unsigned long V_184 = 0 ;
unsigned long V_185 ;
unsigned int V_186 = 0 ;
struct V_108 * V_187 = NULL ;
if ( F_158 ( V_26 ) || V_26 -> V_118 & V_188 ) {
F_159 ( V_189 ) ;
return;
}
F_160 ( V_190 , V_182 , V_183 , NULL ) ;
V_185 = F_156 ( V_2 ) >> V_155 ? : 1 ;
F_151 (iter, memcg) {
struct V_191 V_192 ;
struct V_108 * V_147 ;
F_161 ( & V_122 -> V_12 , & V_192 ) ;
while ( ( V_147 = F_162 ( & V_192 ) ) ) {
switch ( F_163 ( V_147 , V_185 , NULL ,
false ) ) {
case V_193 :
if ( V_187 )
F_164 ( V_187 ) ;
V_187 = V_147 ;
V_184 = V_194 ;
F_165 ( V_187 ) ;
case V_195 :
continue;
case V_196 :
F_166 ( & V_192 ) ;
F_106 ( V_2 , V_122 ) ;
if ( V_187 )
F_164 ( V_187 ) ;
return;
case V_197 :
break;
} ;
V_186 = F_167 ( V_147 , V_2 , NULL , V_185 ) ;
if ( ! V_186 || V_186 < V_184 )
continue;
if ( V_186 == V_184 &&
F_168 ( V_187 ) )
continue;
if ( V_187 )
F_164 ( V_187 ) ;
V_187 = V_147 ;
V_184 = V_186 ;
F_165 ( V_187 ) ;
}
F_166 ( & V_192 ) ;
}
if ( ! V_187 )
return;
V_186 = V_184 * 1000 / V_185 ;
F_169 ( V_187 , V_182 , V_183 , V_186 , V_185 , V_2 ,
NULL , L_11 ) ;
}
static unsigned long F_170 ( struct V_1 * V_2 ,
T_3 V_182 ,
unsigned long V_118 )
{
unsigned long V_93 = 0 ;
bool V_198 = false ;
int V_199 ;
if ( V_118 & V_200 )
V_198 = true ;
if ( ! ( V_118 & V_201 ) && V_2 -> V_202 )
V_198 = true ;
for ( V_199 = 0 ; V_199 < V_203 ; V_199 ++ ) {
if ( V_199 )
F_171 ( V_2 ) ;
V_93 += F_172 ( V_2 , V_182 , V_198 ) ;
if ( V_93 && ( V_118 & V_201 ) )
break;
if ( F_124 ( V_2 ) )
break;
if ( V_199 && ! V_93 )
break;
}
return V_93 ;
}
static bool F_173 ( struct V_1 * V_2 ,
int V_35 , bool V_198 )
{
if ( F_80 ( V_2 , V_35 , V_204 ) )
return true ;
if ( V_198 || ! V_181 )
return false ;
if ( F_80 ( V_2 , V_35 , V_205 ) )
return true ;
return false ;
}
static void F_174 ( struct V_1 * V_2 )
{
int V_35 ;
if ( ! F_99 ( & V_2 -> V_107 ) )
return;
if ( F_175 ( & V_2 -> V_206 ) > 1 )
return;
V_2 -> V_207 = V_208 [ V_209 ] ;
F_176 (nid, node_states[N_MEMORY]) {
if ( ! F_173 ( V_2 , V_35 , false ) )
F_177 ( V_35 , V_2 -> V_207 ) ;
}
F_178 ( & V_2 -> V_107 , 0 ) ;
F_178 ( & V_2 -> V_206 , 0 ) ;
}
int F_179 ( struct V_1 * V_2 )
{
int V_61 ;
F_174 ( V_2 ) ;
V_61 = V_2 -> V_210 ;
V_61 = F_180 ( V_61 , V_2 -> V_207 ) ;
if ( V_61 == V_106 )
V_61 = F_181 ( V_2 -> V_207 ) ;
if ( F_88 ( V_61 == V_106 ) )
V_61 = F_182 () ;
V_2 -> V_210 = V_61 ;
return V_61 ;
}
static bool F_183 ( struct V_1 * V_2 , bool V_198 )
{
int V_35 ;
if ( ! F_184 ( V_2 -> V_207 ) ) {
for ( V_35 = F_181 ( V_2 -> V_207 ) ;
V_35 < V_106 ;
V_35 = F_180 ( V_35 , V_2 -> V_207 ) ) {
if ( F_173 ( V_2 , V_35 , V_198 ) )
return true ;
}
}
F_82 (nid, N_MEMORY) {
if ( F_185 ( V_35 , V_2 -> V_207 ) )
continue;
if ( F_173 ( V_2 , V_35 , V_198 ) )
return true ;
}
return false ;
}
int F_179 ( struct V_1 * V_2 )
{
return 0 ;
}
static bool F_183 ( struct V_1 * V_2 , bool V_198 )
{
return F_173 ( V_2 , 0 , V_198 ) ;
}
static int F_186 ( struct V_1 * V_146 ,
struct V_62 * V_62 ,
T_3 V_182 ,
unsigned long * V_211 )
{
struct V_1 * V_212 = NULL ;
int V_93 = 0 ;
int V_199 = 0 ;
unsigned long V_59 ;
unsigned long V_213 ;
struct V_128 V_129 = {
. V_62 = V_62 ,
. V_135 = 0 ,
} ;
V_59 = F_57 ( & V_146 -> V_60 ) >> V_155 ;
while ( 1 ) {
V_212 = F_102 ( V_146 , V_212 , & V_129 ) ;
if ( ! V_212 ) {
V_199 ++ ;
if ( V_199 >= 2 ) {
if ( ! V_93 )
break;
if ( V_93 >= ( V_59 >> 2 ) ||
( V_199 > V_203 ) )
break;
}
continue;
}
if ( ! F_183 ( V_212 , false ) )
continue;
V_93 += F_187 ( V_212 , V_182 , false ,
V_62 , & V_213 ) ;
* V_211 += V_213 ;
if ( ! F_57 ( & V_146 -> V_60 ) )
break;
}
F_106 ( V_146 , V_212 ) ;
return V_93 ;
}
static bool F_188 ( struct V_1 * V_2 )
{
struct V_1 * V_122 , * V_214 = NULL ;
F_53 ( & V_215 ) ;
F_151 (iter, memcg) {
if ( V_122 -> V_216 ) {
V_214 = V_122 ;
F_106 ( V_2 , V_122 ) ;
break;
} else
V_122 -> V_216 = true ;
}
if ( V_214 ) {
F_151 (iter, memcg) {
if ( V_122 == V_214 ) {
F_106 ( V_2 , V_122 ) ;
break;
}
V_122 -> V_216 = false ;
}
} else
F_189 ( & V_217 , 0 , 1 , V_218 ) ;
F_54 ( & V_215 ) ;
return ! V_214 ;
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_53 ( & V_215 ) ;
F_191 ( & V_217 , 1 , V_218 ) ;
F_151 (iter, memcg)
V_122 -> V_216 = false ;
F_54 ( & V_215 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_151 (iter, memcg)
F_91 ( & V_122 -> V_219 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_151 (iter, memcg)
F_194 ( & V_122 -> V_219 , - 1 , 0 ) ;
}
static int F_195 ( T_4 * V_167 ,
unsigned V_220 , int V_221 , void * V_222 )
{
struct V_1 * V_223 = (struct V_1 * ) V_222 ;
struct V_1 * V_224 ;
struct V_225 * V_225 ;
V_225 = F_12 ( V_167 , struct V_225 , V_167 ) ;
V_224 = V_225 -> V_2 ;
if ( ! F_118 ( V_224 , V_223 )
&& ! F_118 ( V_223 , V_224 ) )
return 0 ;
return F_196 ( V_167 , V_220 , V_221 , V_222 ) ;
}
static void F_197 ( struct V_1 * V_2 )
{
F_91 ( & V_2 -> V_226 ) ;
F_198 ( & V_227 , V_228 , 0 , V_2 ) ;
}
static void F_199 ( struct V_1 * V_2 )
{
if ( V_2 && F_99 ( & V_2 -> V_219 ) )
F_197 ( V_2 ) ;
}
static void F_200 ( struct V_1 * V_2 , T_3 V_229 , int V_183 )
{
if ( ! V_26 -> V_230 . V_231 )
return;
F_21 ( & V_2 -> V_12 ) ;
V_26 -> V_230 . V_2 = V_2 ;
V_26 -> V_230 . V_182 = V_229 ;
V_26 -> V_230 . V_183 = V_183 ;
}
bool F_201 ( bool V_232 )
{
struct V_1 * V_2 = V_26 -> V_230 . V_2 ;
struct V_225 V_233 ;
bool V_234 ;
if ( ! V_2 )
return false ;
if ( ! V_232 )
goto V_235;
V_233 . V_2 = V_2 ;
V_233 . V_167 . V_118 = 0 ;
V_233 . V_167 . V_236 = F_195 ;
V_233 . V_167 . V_237 = V_26 ;
F_202 ( & V_233 . V_167 . V_238 ) ;
F_138 ( & V_227 , & V_233 . V_167 , V_239 ) ;
F_192 ( V_2 ) ;
V_234 = F_188 ( V_2 ) ;
if ( V_234 )
F_203 ( V_2 ) ;
if ( V_234 && ! V_2 -> V_240 ) {
F_193 ( V_2 ) ;
F_140 ( & V_227 , & V_233 . V_167 ) ;
F_157 ( V_2 , V_26 -> V_230 . V_182 ,
V_26 -> V_230 . V_183 ) ;
} else {
F_139 () ;
F_193 ( V_2 ) ;
F_140 ( & V_227 , & V_233 . V_167 ) ;
}
if ( V_234 ) {
F_190 ( V_2 ) ;
F_199 ( V_2 ) ;
}
V_235:
V_26 -> V_230 . V_2 = NULL ;
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
void F_204 ( struct V_40 * V_40 ,
bool * V_234 , unsigned long * V_118 )
{
struct V_1 * V_2 ;
struct V_144 * V_145 ;
V_145 = F_112 ( V_40 ) ;
V_241:
V_2 = V_145 -> V_1 ;
if ( F_88 ( ! V_2 || ! F_114 ( V_145 ) ) )
return;
if ( ! F_133 ( V_2 ) )
return;
F_141 ( V_2 , V_118 ) ;
if ( V_2 != V_145 -> V_1 || ! F_114 ( V_145 ) ) {
F_143 ( V_2 , V_118 ) ;
goto V_241;
}
* V_234 = true ;
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
if ( F_88 ( ! V_2 || ! F_114 ( V_145 ) ) )
return;
F_70 ( V_2 -> V_71 -> V_72 [ V_68 ] , V_69 ) ;
}
static bool F_207 ( struct V_1 * V_2 , unsigned int V_80 )
{
struct V_242 * V_243 ;
bool V_92 = true ;
if ( V_80 > V_244 )
return false ;
V_243 = & F_208 ( V_245 ) ;
if ( V_2 == V_243 -> V_246 && V_243 -> V_80 >= V_80 )
V_243 -> V_80 -= V_80 ;
else
V_92 = false ;
F_209 ( V_245 ) ;
return V_92 ;
}
static void F_210 ( struct V_242 * V_243 )
{
struct V_1 * V_247 = V_243 -> V_246 ;
if ( V_243 -> V_80 ) {
unsigned long V_248 = V_243 -> V_80 * V_249 ;
F_211 ( & V_247 -> V_60 , V_248 ) ;
if ( V_157 )
F_211 ( & V_247 -> V_158 , V_248 ) ;
V_243 -> V_80 = 0 ;
}
V_243 -> V_246 = NULL ;
}
static void F_212 ( struct V_250 * V_251 )
{
struct V_242 * V_243 = & F_213 ( V_245 ) ;
F_210 ( V_243 ) ;
F_214 ( V_252 , & V_243 -> V_118 ) ;
}
static void T_5 F_215 ( void )
{
int V_70 ;
F_216 (cpu) {
struct V_242 * V_243 =
& F_66 ( V_245 , V_70 ) ;
F_217 ( & V_243 -> V_253 , F_212 ) ;
}
}
static void F_218 ( struct V_1 * V_2 , unsigned int V_80 )
{
struct V_242 * V_243 = & F_208 ( V_245 ) ;
if ( V_243 -> V_246 != V_2 ) {
F_210 ( V_243 ) ;
V_243 -> V_246 = V_2 ;
}
V_243 -> V_80 += V_80 ;
F_209 ( V_245 ) ;
}
static void F_219 ( struct V_1 * V_146 , bool V_221 )
{
int V_70 , V_254 ;
F_64 () ;
V_254 = F_220 () ;
F_65 (cpu) {
struct V_242 * V_243 = & F_66 ( V_245 , V_70 ) ;
struct V_1 * V_2 ;
V_2 = V_243 -> V_246 ;
if ( ! V_2 || ! V_243 -> V_80 )
continue;
if ( ! F_118 ( V_146 , V_2 ) )
continue;
if ( ! F_221 ( V_252 , & V_243 -> V_118 ) ) {
if ( V_70 == V_254 )
F_212 ( & V_243 -> V_253 ) ;
else
F_222 ( V_70 , & V_243 -> V_253 ) ;
}
}
F_223 () ;
if ( ! V_221 )
goto V_139;
F_65 (cpu) {
struct V_242 * V_243 = & F_66 ( V_245 , V_70 ) ;
if ( F_4 ( V_252 , & V_243 -> V_118 ) )
F_224 ( & V_243 -> V_253 ) ;
}
V_139:
F_68 () ;
}
static void F_171 ( struct V_1 * V_146 )
{
if ( ! F_225 ( & V_255 ) )
return;
F_219 ( V_146 , false ) ;
F_154 ( & V_255 ) ;
}
static void F_226 ( struct V_1 * V_146 )
{
F_147 ( & V_255 ) ;
F_219 ( V_146 , true ) ;
F_154 ( & V_255 ) ;
}
static void F_227 ( struct V_1 * V_2 , int V_70 )
{
int V_172 ;
F_53 ( & V_2 -> V_73 ) ;
for ( V_172 = 0 ; V_172 < V_175 ; V_172 ++ ) {
long V_256 = F_66 ( V_2 -> V_71 -> V_72 [ V_172 ] , V_70 ) ;
F_66 ( V_2 -> V_71 -> V_72 [ V_172 ] , V_70 ) = 0 ;
V_2 -> V_74 . V_72 [ V_172 ] += V_256 ;
}
for ( V_172 = 0 ; V_172 < V_257 ; V_172 ++ ) {
unsigned long V_256 = F_66 ( V_2 -> V_71 -> V_78 [ V_172 ] , V_70 ) ;
F_66 ( V_2 -> V_71 -> V_78 [ V_172 ] , V_70 ) = 0 ;
V_2 -> V_74 . V_78 [ V_172 ] += V_256 ;
}
F_54 ( & V_2 -> V_73 ) ;
}
static int F_228 ( struct V_258 * V_259 ,
unsigned long V_260 ,
void * V_261 )
{
int V_70 = ( unsigned long ) V_261 ;
struct V_242 * V_243 ;
struct V_1 * V_122 ;
if ( V_260 == V_262 )
return V_263 ;
if ( V_260 != V_264 && V_260 != V_265 )
return V_263 ;
F_229 (iter)
F_227 ( V_122 , V_70 ) ;
V_243 = & F_66 ( V_245 , V_70 ) ;
F_210 ( V_243 ) ;
return V_263 ;
}
static int F_230 ( struct V_1 * V_2 , T_3 V_182 ,
unsigned int V_80 , unsigned int V_266 ,
bool V_267 )
{
unsigned long V_268 = V_80 * V_249 ;
struct V_1 * V_269 ;
struct V_270 * V_271 ;
unsigned long V_118 = 0 ;
int V_92 ;
V_92 = F_231 ( & V_2 -> V_60 , V_268 , & V_271 ) ;
if ( F_232 ( ! V_92 ) ) {
if ( ! V_157 )
return V_272 ;
V_92 = F_231 ( & V_2 -> V_158 , V_268 , & V_271 ) ;
if ( F_232 ( ! V_92 ) )
return V_272 ;
F_211 ( & V_2 -> V_60 , V_268 ) ;
V_269 = F_233 ( V_271 , V_158 ) ;
V_118 |= V_200 ;
} else
V_269 = F_233 ( V_271 , V_60 ) ;
if ( V_80 > V_266 )
return V_273 ;
if ( ! ( V_182 & V_274 ) )
return V_275 ;
if ( V_182 & V_276 )
return V_277 ;
V_92 = F_170 ( V_269 , V_182 , V_118 ) ;
if ( F_124 ( V_269 ) >= V_80 )
return V_273 ;
if ( V_80 <= ( 1 << V_278 ) && V_92 )
return V_273 ;
if ( F_136 ( V_269 ) )
return V_273 ;
if ( V_267 )
F_200 ( V_269 , V_182 , F_234 ( V_268 ) ) ;
return V_277 ;
}
static int F_235 ( struct V_1 * V_2 ,
T_3 V_182 ,
unsigned int V_80 ,
bool V_279 )
{
unsigned int V_280 = F_236 ( V_244 , V_80 ) ;
int V_281 = V_282 ;
int V_92 ;
if ( F_15 ( V_2 ) )
goto V_66;
if ( F_88 ( F_237 ( V_189 ) ||
F_158 ( V_26 ) ) )
goto V_283;
if ( F_88 ( F_238 ( V_26 ) ) )
goto V_284;
if ( V_182 & V_285 )
V_279 = false ;
V_241:
if ( F_207 ( V_2 , V_80 ) )
goto V_66;
do {
bool V_267 = V_279 && ! V_281 ;
if ( F_158 ( V_26 ) )
goto V_283;
V_92 = F_230 ( V_2 , V_182 , V_280 ,
V_80 , V_267 ) ;
switch ( V_92 ) {
case V_272 :
break;
case V_273 :
V_280 = V_80 ;
goto V_241;
case V_275 :
goto V_284;
case V_277 :
if ( ! V_279 || V_267 )
goto V_284;
V_281 -- ;
break;
}
} while ( V_92 != V_272 );
if ( V_280 > V_80 )
F_218 ( V_2 , V_280 - V_80 ) ;
V_66:
return 0 ;
V_284:
if ( ! ( V_182 & V_285 ) )
return - V_286 ;
V_283:
return - V_287 ;
}
static struct V_1 * F_239 ( struct V_110 * V_111 ,
T_3 V_182 ,
unsigned int V_80 ,
bool V_279 )
{
struct V_1 * V_2 ;
int V_92 ;
V_2 = F_93 ( V_111 ) ;
V_92 = F_235 ( V_2 , V_182 , V_80 , V_279 ) ;
F_29 ( & V_2 -> V_12 ) ;
if ( V_92 == - V_287 )
V_2 = V_14 ;
else if ( V_92 )
V_2 = NULL ;
return V_2 ;
}
static void F_240 ( struct V_1 * V_2 ,
unsigned int V_80 )
{
if ( ! F_15 ( V_2 ) ) {
unsigned long V_248 = V_80 * V_249 ;
F_211 ( & V_2 -> V_60 , V_248 ) ;
if ( V_157 )
F_211 ( & V_2 -> V_158 , V_248 ) ;
}
}
static void F_241 ( struct V_1 * V_2 ,
unsigned int V_80 )
{
unsigned long V_248 = V_80 * V_249 ;
if ( F_15 ( V_2 ) )
return;
F_242 ( & V_2 -> V_60 , V_2 -> V_60 . V_51 , V_248 ) ;
if ( V_157 )
F_242 ( & V_2 -> V_158 ,
V_2 -> V_158 . V_51 , V_248 ) ;
}
static struct V_1 * F_243 ( unsigned short V_17 )
{
if ( ! V_17 )
return NULL ;
return F_17 ( V_17 ) ;
}
struct V_1 * F_244 ( struct V_40 * V_40 )
{
struct V_1 * V_2 = NULL ;
struct V_144 * V_145 ;
unsigned short V_17 ;
T_6 V_288 ;
F_245 ( ! F_246 ( V_40 ) , V_40 ) ;
V_145 = F_112 ( V_40 ) ;
F_247 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
} else if ( F_248 ( V_40 ) ) {
V_288 . V_69 = F_249 ( V_40 ) ;
V_17 = F_250 ( V_288 ) ;
F_22 () ;
V_2 = F_243 ( V_17 ) ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
F_26 () ;
}
F_251 ( V_145 ) ;
return V_2 ;
}
static void F_252 ( struct V_1 * V_2 ,
struct V_40 * V_40 ,
unsigned int V_80 ,
enum V_289 V_290 ,
bool V_291 )
{
struct V_144 * V_145 = F_112 ( V_40 ) ;
struct V_62 * V_132 ( V_62 ) ;
struct V_87 * V_87 ;
bool V_292 = false ;
bool V_79 ;
F_247 ( V_145 ) ;
F_245 ( F_114 ( V_145 ) , V_40 ) ;
if ( V_291 ) {
V_62 = F_253 ( V_40 ) ;
F_254 ( & V_62 -> V_293 ) ;
if ( F_113 ( V_40 ) ) {
V_87 = F_110 ( V_62 , V_145 -> V_1 ) ;
F_255 ( V_40 ) ;
F_256 ( V_40 , V_87 , F_257 ( V_40 ) ) ;
V_292 = true ;
}
}
V_145 -> V_1 = V_2 ;
F_6 () ;
F_258 ( V_145 ) ;
if ( V_291 ) {
if ( V_292 ) {
V_87 = F_110 ( V_62 , V_145 -> V_1 ) ;
F_245 ( F_113 ( V_40 ) , V_40 ) ;
F_259 ( V_40 ) ;
F_260 ( V_40 , V_87 , F_257 ( V_40 ) ) ;
}
F_261 ( & V_62 -> V_293 ) ;
}
if ( V_290 == V_294 )
V_79 = true ;
else
V_79 = false ;
F_72 ( V_2 , V_40 , V_79 , V_80 ) ;
F_251 ( V_145 ) ;
F_86 ( V_2 , V_40 ) ;
}
static inline bool F_262 ( struct V_1 * V_2 )
{
return ! F_103 () && ! F_15 ( V_2 ) &&
F_3 ( V_2 ) ;
}
static struct V_295 * F_263 ( struct V_296 * V_49 )
{
struct V_295 * V_297 ;
F_39 ( V_49 -> V_298 ) ;
V_297 = V_49 -> V_299 ;
return F_264 ( V_297 , F_265 ( V_49 -> V_2 ) ) ;
}
static int F_266 ( struct V_300 * V_301 , void * V_302 )
{
struct V_1 * V_2 = F_11 ( F_267 ( V_301 ) ) ;
struct V_296 * V_303 ;
if ( ! F_262 ( V_2 ) )
return - V_304 ;
F_268 ( V_301 ) ;
F_147 ( & V_2 -> V_305 ) ;
F_269 (params, &memcg->memcg_slab_caches, list)
F_270 ( F_263 ( V_303 ) , V_301 ) ;
F_154 ( & V_2 -> V_305 ) ;
return 0 ;
}
static int F_271 ( struct V_1 * V_2 , T_3 V_306 , T_1 V_307 )
{
struct V_270 * V_271 ;
int V_92 = 0 ;
V_92 = F_231 ( & V_2 -> V_32 , V_307 , & V_271 ) ;
if ( V_92 )
return V_92 ;
V_92 = F_235 ( V_2 , V_306 , V_307 >> V_155 ,
F_272 ( V_306 ) ) ;
if ( V_92 == - V_287 ) {
F_273 ( & V_2 -> V_60 , V_307 , & V_271 ) ;
if ( V_157 )
F_273 ( & V_2 -> V_158 , V_307 ,
& V_271 ) ;
V_92 = 0 ;
} else if ( V_92 )
F_211 ( & V_2 -> V_32 , V_307 ) ;
return V_92 ;
}
static void F_274 ( struct V_1 * V_2 , T_1 V_307 )
{
F_211 ( & V_2 -> V_60 , V_307 ) ;
if ( V_157 )
F_211 ( & V_2 -> V_158 , V_307 ) ;
if ( F_211 ( & V_2 -> V_32 , V_307 ) )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
int F_265 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_31 : - 1 ;
}
static T_7 F_275 ( int V_308 )
{
T_8 V_307 ;
if ( V_308 <= 0 )
return 0 ;
V_307 = 2 * V_308 ;
if ( V_307 < V_309 )
V_307 = V_309 ;
else if ( V_307 > V_310 )
V_307 = V_310 ;
return V_307 ;
}
void F_276 ( int V_179 )
{
if ( V_179 > V_311 )
V_311 = F_275 ( V_179 ) ;
}
int F_277 ( struct V_295 * V_11 , int V_308 )
{
struct V_296 * V_312 = V_11 -> V_313 ;
F_39 ( ! V_298 ( V_11 ) ) ;
if ( V_308 > V_311 ) {
int V_172 ;
struct V_296 * V_314 ;
T_8 V_307 = F_275 ( V_308 ) ;
V_307 *= sizeof( void * ) ;
V_307 += F_278 ( struct V_296 , V_315 ) ;
V_314 = F_279 ( V_307 , V_316 ) ;
if ( ! V_314 )
return - V_286 ;
V_314 -> V_298 = true ;
for ( V_172 = 0 ; V_172 < V_311 ; V_172 ++ ) {
if ( ! V_312 -> V_315 [ V_172 ] )
continue;
V_314 -> V_315 [ V_172 ] =
V_312 -> V_315 [ V_172 ] ;
}
F_280 ( V_11 -> V_313 , V_314 ) ;
if ( V_312 )
F_281 ( V_312 , V_317 ) ;
}
return 0 ;
}
char * F_282 ( struct V_1 * V_2 ,
struct V_295 * V_299 )
{
static char * V_318 = NULL ;
F_283 ( & V_319 ) ;
if ( ! V_318 ) {
V_318 = F_284 ( V_320 + 1 , V_316 ) ;
if ( ! V_318 )
return NULL ;
}
F_285 ( V_2 -> V_12 . V_16 , V_318 , V_320 + 1 ) ;
return F_286 ( V_316 , L_12 , V_299 -> V_321 ,
F_265 ( V_2 ) , V_318 ) ;
}
int F_287 ( struct V_1 * V_2 , struct V_295 * V_11 ,
struct V_295 * V_299 )
{
T_7 V_307 ;
if ( ! F_288 () )
return 0 ;
if ( ! V_2 ) {
V_307 = F_278 ( struct V_296 , V_315 ) ;
V_307 += V_311 * sizeof( void * ) ;
} else
V_307 = sizeof( struct V_296 ) ;
V_11 -> V_313 = F_279 ( V_307 , V_316 ) ;
if ( ! V_11 -> V_313 )
return - V_286 ;
if ( V_2 ) {
V_11 -> V_313 -> V_2 = V_2 ;
V_11 -> V_313 -> V_299 = V_299 ;
F_217 ( & V_11 -> V_313 -> V_322 ,
V_323 ) ;
F_21 ( & V_2 -> V_12 ) ;
} else
V_11 -> V_313 -> V_298 = true ;
return 0 ;
}
void F_289 ( struct V_295 * V_11 )
{
if ( ! V_11 -> V_313 )
return;
if ( ! V_11 -> V_313 -> V_298 )
F_29 ( & V_11 -> V_313 -> V_2 -> V_12 ) ;
F_290 ( V_11 -> V_313 ) ;
}
void F_291 ( struct V_295 * V_11 )
{
struct V_295 * V_113 ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_298 ( V_11 ) )
return;
F_283 ( & V_319 ) ;
V_113 = V_11 -> V_313 -> V_299 ;
V_2 = V_11 -> V_313 -> V_2 ;
V_17 = F_265 ( V_2 ) ;
F_6 () ;
F_39 ( V_113 -> V_313 -> V_315 [ V_17 ] ) ;
V_113 -> V_313 -> V_315 [ V_17 ] = V_11 ;
F_147 ( & V_2 -> V_305 ) ;
F_292 ( & V_11 -> V_313 -> V_324 , & V_2 -> V_325 ) ;
F_154 ( & V_2 -> V_305 ) ;
}
void F_293 ( struct V_295 * V_11 )
{
struct V_295 * V_113 ;
struct V_1 * V_2 ;
int V_17 ;
if ( V_298 ( V_11 ) )
return;
F_283 ( & V_319 ) ;
V_113 = V_11 -> V_313 -> V_299 ;
V_2 = V_11 -> V_313 -> V_2 ;
V_17 = F_265 ( V_2 ) ;
F_147 ( & V_2 -> V_305 ) ;
F_294 ( & V_11 -> V_313 -> V_324 ) ;
F_154 ( & V_2 -> V_305 ) ;
F_39 ( V_113 -> V_313 -> V_315 [ V_17 ] != V_11 ) ;
V_113 -> V_313 -> V_315 [ V_17 ] = NULL ;
}
static inline void F_295 ( void )
{
F_39 ( ! V_26 -> V_111 ) ;
V_26 -> V_326 ++ ;
}
static inline void F_296 ( void )
{
F_39 ( ! V_26 -> V_111 ) ;
V_26 -> V_326 -- ;
}
static void V_323 ( struct V_250 * V_327 )
{
struct V_295 * V_297 ;
struct V_296 * V_49 ;
V_49 = F_12 ( V_327 , struct V_296 , V_322 ) ;
V_297 = F_263 ( V_49 ) ;
if ( F_99 ( & V_297 -> V_313 -> V_80 ) != 0 )
F_297 ( V_297 ) ;
else
F_298 ( V_297 ) ;
}
void F_299 ( struct V_295 * V_297 )
{
if ( ! V_297 -> V_313 -> V_328 )
return;
if ( F_300 ( & V_297 -> V_313 -> V_322 ) )
return;
F_301 ( & V_297 -> V_313 -> V_322 ) ;
}
int F_302 ( struct V_295 * V_11 )
{
struct V_295 * V_329 ;
int V_172 , V_214 = 0 ;
F_147 ( & V_330 ) ;
F_303 (i) {
V_329 = F_264 ( V_11 , V_172 ) ;
if ( ! V_329 )
continue;
V_329 -> V_313 -> V_328 = false ;
F_304 ( & V_329 -> V_313 -> V_322 ) ;
F_298 ( V_329 ) ;
if ( F_264 ( V_11 , V_172 ) )
V_214 ++ ;
}
F_154 ( & V_330 ) ;
return V_214 ;
}
static void F_305 ( struct V_1 * V_2 )
{
struct V_295 * V_297 ;
struct V_296 * V_303 ;
if ( ! F_3 ( V_2 ) )
return;
F_147 ( & V_2 -> V_305 ) ;
F_269 (params, &memcg->memcg_slab_caches, list) {
V_297 = F_263 ( V_303 ) ;
V_297 -> V_313 -> V_328 = true ;
F_301 ( & V_297 -> V_313 -> V_322 ) ;
}
F_154 ( & V_2 -> V_305 ) ;
}
static void F_306 ( struct V_250 * V_327 )
{
struct V_331 * V_332 = F_12 ( V_327 , struct V_331 , V_253 ) ;
struct V_1 * V_2 = V_332 -> V_2 ;
struct V_295 * V_297 = V_332 -> V_297 ;
F_307 ( V_2 , V_297 ) ;
F_29 ( & V_2 -> V_12 ) ;
F_290 ( V_332 ) ;
}
static void F_308 ( struct V_1 * V_2 ,
struct V_295 * V_297 )
{
struct V_331 * V_332 ;
V_332 = F_284 ( sizeof( struct V_331 ) , V_333 ) ;
if ( V_332 == NULL ) {
F_29 ( & V_2 -> V_12 ) ;
return;
}
V_332 -> V_2 = V_2 ;
V_332 -> V_297 = V_297 ;
F_217 ( & V_332 -> V_253 , F_306 ) ;
F_301 ( & V_332 -> V_253 ) ;
}
static void F_309 ( struct V_1 * V_2 ,
struct V_295 * V_297 )
{
F_295 () ;
F_308 ( V_2 , V_297 ) ;
F_296 () ;
}
struct V_295 * F_310 ( struct V_295 * V_297 ,
T_3 V_306 )
{
struct V_1 * V_2 ;
struct V_295 * V_334 ;
F_39 ( ! V_297 -> V_313 ) ;
F_39 ( ! V_297 -> V_313 -> V_298 ) ;
if ( ! V_26 -> V_111 || V_26 -> V_326 )
return V_297 ;
F_22 () ;
V_2 = F_23 ( F_94 ( V_26 -> V_111 -> V_112 ) ) ;
if ( ! F_262 ( V_2 ) )
goto V_139;
V_334 = F_264 ( V_297 , F_265 ( V_2 ) ) ;
if ( F_232 ( V_334 ) ) {
V_297 = V_334 ;
goto V_139;
}
if ( ! F_25 ( & V_2 -> V_12 ) )
goto V_139;
F_26 () ;
F_309 ( V_2 , V_297 ) ;
return V_297 ;
V_139:
F_26 () ;
return V_297 ;
}
bool
F_311 ( T_3 V_306 , struct V_1 * * V_335 , int V_183 )
{
struct V_1 * V_2 ;
int V_92 ;
* V_335 = NULL ;
if ( ! V_26 -> V_111 || V_26 -> V_326 )
return true ;
V_2 = F_93 ( V_26 -> V_111 ) ;
if ( ! F_262 ( V_2 ) ) {
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
V_92 = F_271 ( V_2 , V_306 , V_249 << V_183 ) ;
if ( ! V_92 )
* V_335 = V_2 ;
F_29 ( & V_2 -> V_12 ) ;
return ( V_92 == 0 ) ;
}
void F_312 ( struct V_40 * V_40 , struct V_1 * V_2 ,
int V_183 )
{
struct V_144 * V_145 ;
F_39 ( F_15 ( V_2 ) ) ;
if ( ! V_40 ) {
F_274 ( V_2 , V_249 << V_183 ) ;
return;
}
V_145 = F_112 ( V_40 ) ;
F_247 ( V_145 ) ;
V_145 -> V_1 = V_2 ;
F_258 ( V_145 ) ;
F_251 ( V_145 ) ;
}
void F_313 ( struct V_40 * V_40 , int V_183 )
{
struct V_1 * V_2 = NULL ;
struct V_144 * V_145 ;
V_145 = F_112 ( V_40 ) ;
if ( ! F_114 ( V_145 ) )
return;
F_247 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
F_314 ( V_145 ) ;
}
F_251 ( V_145 ) ;
if ( ! V_2 )
return;
F_245 ( F_15 ( V_2 ) , V_40 ) ;
F_274 ( V_2 , V_249 << V_183 ) ;
}
static inline void F_305 ( struct V_1 * V_2 )
{
}
void F_315 ( struct V_40 * V_336 )
{
struct V_144 * V_337 = F_112 ( V_336 ) ;
struct V_144 * V_145 ;
struct V_1 * V_2 ;
int V_172 ;
if ( F_103 () )
return;
V_2 = V_337 -> V_1 ;
for ( V_172 = 1 ; V_172 < V_338 ; V_172 ++ ) {
V_145 = V_337 + V_172 ;
V_145 -> V_1 = V_2 ;
F_6 () ;
V_145 -> V_118 = V_337 -> V_118 & ~ V_339 ;
}
F_316 ( V_2 -> V_71 -> V_72 [ V_83 ] ,
V_338 ) ;
}
static int F_317 ( struct V_40 * V_40 ,
unsigned int V_80 ,
struct V_144 * V_145 ,
struct V_1 * V_163 ,
struct V_1 * V_164 )
{
unsigned long V_118 ;
int V_92 ;
bool V_79 = F_318 ( V_40 ) ;
F_39 ( V_163 == V_164 ) ;
F_245 ( F_113 ( V_40 ) , V_40 ) ;
V_92 = - V_340 ;
if ( V_80 > 1 && ! F_74 ( V_40 ) )
goto V_139;
F_247 ( V_145 ) ;
V_92 = - V_341 ;
if ( ! F_114 ( V_145 ) || V_145 -> V_1 != V_163 )
goto V_165;
F_141 ( V_163 , & V_118 ) ;
if ( ! V_79 && F_319 ( V_40 ) ) {
F_316 ( V_163 -> V_71 -> V_72 [ V_342 ] ,
V_80 ) ;
F_73 ( V_164 -> V_71 -> V_72 [ V_342 ] ,
V_80 ) ;
}
if ( F_320 ( V_40 ) ) {
F_316 ( V_163 -> V_71 -> V_72 [ V_343 ] ,
V_80 ) ;
F_73 ( V_164 -> V_71 -> V_72 [ V_343 ] ,
V_80 ) ;
}
F_72 ( V_163 , V_40 , V_79 , - V_80 ) ;
V_145 -> V_1 = V_164 ;
F_72 ( V_164 , V_40 , V_79 , V_80 ) ;
F_143 ( V_163 , & V_118 ) ;
V_92 = 0 ;
V_165:
F_251 ( V_145 ) ;
F_86 ( V_164 , V_40 ) ;
F_86 ( V_163 , V_40 ) ;
V_139:
return V_92 ;
}
static int F_321 ( struct V_40 * V_40 ,
struct V_144 * V_145 ,
struct V_1 * V_344 )
{
struct V_1 * V_51 ;
unsigned int V_80 ;
unsigned long V_132 ( V_118 ) ;
int V_92 ;
F_39 ( F_15 ( V_344 ) ) ;
V_92 = - V_340 ;
if ( ! F_322 ( V_40 ) )
goto V_139;
if ( F_323 ( V_40 ) )
goto V_345;
V_80 = F_324 ( V_40 ) ;
V_51 = F_56 ( V_344 ) ;
if ( ! V_51 )
V_51 = V_14 ;
if ( V_80 > 1 ) {
F_245 ( ! F_74 ( V_40 ) , V_40 ) ;
V_118 = F_325 ( V_40 ) ;
}
V_92 = F_317 ( V_40 , V_80 ,
V_145 , V_344 , V_51 ) ;
if ( ! V_92 )
F_241 ( V_344 , V_80 ) ;
if ( V_80 > 1 )
F_326 ( V_40 , V_118 ) ;
F_327 ( V_40 ) ;
V_345:
F_328 ( V_40 ) ;
V_139:
return V_92 ;
}
int F_329 ( struct V_40 * V_40 ,
struct V_110 * V_111 , T_3 V_182 )
{
unsigned int V_80 = 1 ;
struct V_1 * V_2 ;
bool V_279 = true ;
if ( F_103 () )
return 0 ;
F_245 ( F_319 ( V_40 ) , V_40 ) ;
F_245 ( V_40 -> V_346 && ! F_318 ( V_40 ) , V_40 ) ;
F_39 ( ! V_111 ) ;
if ( F_74 ( V_40 ) ) {
V_80 <<= F_330 ( V_40 ) ;
F_245 ( ! F_74 ( V_40 ) , V_40 ) ;
V_279 = false ;
}
V_2 = F_239 ( V_111 , V_182 , V_80 , V_279 ) ;
if ( ! V_2 )
return - V_286 ;
F_252 ( V_2 , V_40 , V_80 ,
V_294 , false ) ;
return 0 ;
}
static int F_331 ( struct V_110 * V_111 ,
struct V_40 * V_40 ,
T_3 V_229 ,
struct V_1 * * V_347 )
{
struct V_1 * V_2 = NULL ;
struct V_144 * V_145 ;
int V_92 ;
V_145 = F_112 ( V_40 ) ;
if ( F_114 ( V_145 ) )
goto V_139;
if ( V_157 )
V_2 = F_244 ( V_40 ) ;
if ( ! V_2 )
V_2 = F_93 ( V_111 ) ;
V_92 = F_235 ( V_2 , V_229 , 1 , true ) ;
F_29 ( & V_2 -> V_12 ) ;
if ( V_92 == - V_287 )
V_2 = V_14 ;
else if ( V_92 )
return V_92 ;
V_139:
* V_347 = V_2 ;
return 0 ;
}
int F_332 ( struct V_110 * V_111 , struct V_40 * V_40 ,
T_3 V_182 , struct V_1 * * V_347 )
{
if ( F_103 () ) {
* V_347 = NULL ;
return 0 ;
}
if ( ! F_248 ( V_40 ) ) {
struct V_1 * V_2 ;
V_2 = F_239 ( V_111 , V_182 , 1 , true ) ;
if ( ! V_2 )
return - V_286 ;
* V_347 = V_2 ;
return 0 ;
}
return F_331 ( V_111 , V_40 , V_182 , V_347 ) ;
}
void F_333 ( struct V_1 * V_2 )
{
if ( F_103 () )
return;
if ( ! V_2 )
return;
F_240 ( V_2 , 1 ) ;
}
static void
F_334 ( struct V_40 * V_40 , struct V_1 * V_2 ,
enum V_289 V_290 )
{
if ( F_103 () )
return;
if ( ! V_2 )
return;
F_252 ( V_2 , V_40 , 1 , V_290 , true ) ;
if ( V_157 && F_248 ( V_40 ) ) {
T_6 V_288 = { . V_69 = F_249 (page) } ;
F_335 ( V_288 ) ;
}
}
void F_336 ( struct V_40 * V_40 ,
struct V_1 * V_2 )
{
F_334 ( V_40 , V_2 ,
V_294 ) ;
}
int F_337 ( struct V_40 * V_40 , struct V_110 * V_111 ,
T_3 V_182 )
{
enum V_289 type = V_348 ;
struct V_1 * V_2 ;
int V_92 ;
if ( F_103 () )
return 0 ;
if ( F_338 ( V_40 ) )
return 0 ;
if ( F_248 ( V_40 ) ) {
V_92 = F_331 ( V_111 , V_40 ,
V_182 , & V_2 ) ;
if ( V_92 )
return V_92 ;
F_334 ( V_40 , V_2 , type ) ;
return 0 ;
}
V_2 = F_239 ( V_111 , V_182 , 1 , true ) ;
if ( ! V_2 )
return - V_286 ;
F_252 ( V_2 , V_40 , 1 , type , false ) ;
return 0 ;
}
static void F_339 ( struct V_1 * V_2 ,
unsigned int V_80 ,
const enum V_289 V_290 )
{
struct V_349 * V_280 = NULL ;
bool V_350 = true ;
if ( ! V_157 || V_290 == V_351 )
V_350 = false ;
V_280 = & V_26 -> V_352 ;
if ( ! V_280 -> V_2 )
V_280 -> V_2 = V_2 ;
if ( ! V_280 -> V_353 || F_237 ( V_189 ) )
goto V_354;
if ( V_80 > 1 )
goto V_354;
if ( V_280 -> V_2 != V_2 )
goto V_354;
V_280 -> V_80 ++ ;
if ( V_350 )
V_280 -> V_355 ++ ;
return;
V_354:
F_211 ( & V_2 -> V_60 , V_80 * V_249 ) ;
if ( V_350 )
F_211 ( & V_2 -> V_158 , V_80 * V_249 ) ;
if ( F_88 ( V_280 -> V_2 != V_2 ) )
F_199 ( V_2 ) ;
}
static struct V_1 *
F_340 ( struct V_40 * V_40 , enum V_289 V_290 ,
bool V_356 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_80 = 1 ;
struct V_144 * V_145 ;
bool V_79 ;
if ( F_103 () )
return NULL ;
if ( F_74 ( V_40 ) ) {
V_80 <<= F_330 ( V_40 ) ;
F_245 ( ! F_74 ( V_40 ) , V_40 ) ;
}
V_145 = F_112 ( V_40 ) ;
if ( F_88 ( ! F_114 ( V_145 ) ) )
return NULL ;
F_247 ( V_145 ) ;
V_2 = V_145 -> V_1 ;
if ( ! F_114 ( V_145 ) )
goto V_357;
V_79 = F_318 ( V_40 ) ;
switch ( V_290 ) {
case V_294 :
V_79 = true ;
case V_358 :
if ( F_319 ( V_40 ) )
goto V_357;
if ( ! V_356 && F_341 ( V_145 ) )
goto V_357;
break;
case V_351 :
if ( ! F_318 ( V_40 ) ) {
if ( V_40 -> V_346 && ! F_342 ( V_40 ) )
goto V_357;
} else if ( F_319 ( V_40 ) )
goto V_357;
break;
default:
break;
}
F_72 ( V_2 , V_40 , V_79 , - V_80 ) ;
F_314 ( V_145 ) ;
F_251 ( V_145 ) ;
F_86 ( V_2 , V_40 ) ;
if ( V_157 && V_290 == V_351 ) {
F_69 ( V_2 , true ) ;
F_21 ( & V_2 -> V_12 ) ;
}
if ( ! V_356 && ! F_15 ( V_2 ) )
F_339 ( V_2 , V_80 , V_290 ) ;
return V_2 ;
V_357:
F_251 ( V_145 ) ;
return NULL ;
}
void F_343 ( struct V_40 * V_40 )
{
if ( F_319 ( V_40 ) )
return;
F_245 ( V_40 -> V_346 && ! F_318 ( V_40 ) , V_40 ) ;
if ( F_248 ( V_40 ) )
return;
F_340 ( V_40 , V_294 , false ) ;
}
void F_344 ( struct V_40 * V_40 )
{
F_245 ( F_319 ( V_40 ) , V_40 ) ;
F_245 ( V_40 -> V_346 , V_40 ) ;
F_340 ( V_40 , V_348 , false ) ;
}
void F_345 ( void )
{
V_26 -> V_352 . V_353 ++ ;
if ( V_26 -> V_352 . V_353 == 1 ) {
V_26 -> V_352 . V_2 = NULL ;
V_26 -> V_352 . V_80 = 0 ;
V_26 -> V_352 . V_355 = 0 ;
}
}
void F_346 ( void )
{
struct V_349 * V_280 = & V_26 -> V_352 ;
if ( ! V_280 -> V_353 )
return;
V_280 -> V_353 -- ;
if ( V_280 -> V_353 )
return;
if ( ! V_280 -> V_2 )
return;
if ( V_280 -> V_80 )
F_211 ( & V_280 -> V_2 -> V_60 ,
V_280 -> V_80 * V_249 ) ;
if ( V_280 -> V_355 )
F_211 ( & V_280 -> V_2 -> V_158 ,
V_280 -> V_355 * V_249 ) ;
F_199 ( V_280 -> V_2 ) ;
V_280 -> V_2 = NULL ;
}
void
F_347 ( struct V_40 * V_40 , T_6 V_288 , bool V_359 )
{
struct V_1 * V_2 ;
int V_290 = V_351 ;
if ( ! V_359 )
V_290 = V_358 ;
V_2 = F_340 ( V_40 , V_290 , false ) ;
if ( V_157 && V_359 && V_2 )
F_348 ( V_288 , F_16 ( V_2 ) ) ;
}
void F_335 ( T_6 V_288 )
{
struct V_1 * V_2 ;
unsigned short V_17 ;
if ( ! V_157 )
return;
V_17 = F_348 ( V_288 , 0 ) ;
F_22 () ;
V_2 = F_243 ( V_17 ) ;
if ( V_2 ) {
if ( ! F_15 ( V_2 ) )
F_211 ( & V_2 -> V_158 , V_249 ) ;
F_69 ( V_2 , false ) ;
F_29 ( & V_2 -> V_12 ) ;
}
F_26 () ;
}
static int F_349 ( T_6 V_360 ,
struct V_1 * V_163 , struct V_1 * V_164 )
{
unsigned short V_361 , V_362 ;
V_361 = F_16 ( V_163 ) ;
V_362 = F_16 ( V_164 ) ;
if ( F_350 ( V_360 , V_361 , V_362 ) == V_361 ) {
F_69 ( V_163 , false ) ;
F_69 ( V_164 , true ) ;
F_21 ( & V_164 -> V_12 ) ;
return 0 ;
}
return - V_341 ;
}
static inline int F_349 ( T_6 V_360 ,
struct V_1 * V_163 , struct V_1 * V_164 )
{
return - V_341 ;
}
void F_351 ( struct V_40 * V_40 , struct V_40 * V_363 ,
struct V_1 * * V_347 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_80 = 1 ;
struct V_144 * V_145 ;
enum V_289 V_290 ;
* V_347 = NULL ;
if ( F_103 () )
return;
if ( F_74 ( V_40 ) )
V_80 <<= F_330 ( V_40 ) ;
V_145 = F_112 ( V_40 ) ;
F_247 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
F_21 ( & V_2 -> V_12 ) ;
if ( F_318 ( V_40 ) )
F_352 ( V_145 ) ;
}
F_251 ( V_145 ) ;
if ( ! V_2 )
return;
* V_347 = V_2 ;
if ( F_318 ( V_40 ) )
V_290 = V_294 ;
else
V_290 = V_348 ;
F_252 ( V_2 , V_363 , V_80 , V_290 , false ) ;
}
void F_353 ( struct V_1 * V_2 ,
struct V_40 * V_364 , struct V_40 * V_363 , bool V_365 )
{
struct V_40 * V_366 , * V_367 ;
struct V_144 * V_145 ;
bool V_79 ;
if ( ! V_2 )
return;
if ( ! V_365 ) {
V_366 = V_364 ;
V_367 = V_363 ;
} else {
V_366 = V_363 ;
V_367 = V_364 ;
}
V_79 = F_318 ( V_366 ) ;
F_340 ( V_367 ,
V_79 ? V_294
: V_348 ,
true ) ;
F_29 ( & V_2 -> V_12 ) ;
V_145 = F_112 ( V_364 ) ;
F_247 ( V_145 ) ;
F_354 ( V_145 ) ;
F_251 ( V_145 ) ;
if ( V_79 )
F_343 ( V_366 ) ;
}
void F_355 ( struct V_40 * V_364 ,
struct V_40 * V_363 )
{
struct V_1 * V_2 = NULL ;
struct V_144 * V_145 ;
enum V_289 type = V_348 ;
if ( F_103 () )
return;
V_145 = F_112 ( V_364 ) ;
F_247 ( V_145 ) ;
if ( F_114 ( V_145 ) ) {
V_2 = V_145 -> V_1 ;
F_72 ( V_2 , V_364 , false , - 1 ) ;
F_314 ( V_145 ) ;
}
F_251 ( V_145 ) ;
if ( ! V_2 )
return;
F_252 ( V_2 , V_363 , 1 , type , true ) ;
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
F_359 ( L_13 ,
V_145 , V_145 -> V_118 , V_145 -> V_1 ) ;
}
}
static int F_360 ( struct V_1 * V_2 ,
unsigned long long V_69 )
{
int V_368 ;
T_1 V_369 , V_370 ;
int V_92 = 0 ;
int V_371 = F_155 ( V_2 ) ;
T_1 V_372 , V_373 ;
int V_374 ;
V_368 = V_282 * V_371 ;
V_373 = F_36 ( & V_2 -> V_60 , V_33 ) ;
V_374 = 0 ;
while ( V_368 ) {
if ( F_361 ( V_26 ) ) {
V_92 = - V_287 ;
break;
}
F_147 ( & V_375 ) ;
V_369 = F_36 ( & V_2 -> V_158 , V_173 ) ;
if ( V_369 < V_69 ) {
V_92 = - V_341 ;
F_154 ( & V_375 ) ;
break;
}
V_370 = F_36 ( & V_2 -> V_60 , V_173 ) ;
if ( V_370 < V_69 )
V_374 = 1 ;
V_92 = F_362 ( & V_2 -> V_60 , V_69 ) ;
if ( ! V_92 ) {
if ( V_369 == V_69 )
V_2 -> V_202 = true ;
else
V_2 -> V_202 = false ;
}
F_154 ( & V_375 ) ;
if ( ! V_92 )
break;
F_170 ( V_2 , V_316 ,
V_201 ) ;
V_372 = F_36 ( & V_2 -> V_60 , V_33 ) ;
if ( V_372 >= V_373 )
V_368 -- ;
else
V_373 = V_372 ;
}
if ( ! V_92 && V_374 )
F_199 ( V_2 ) ;
return V_92 ;
}
static int F_363 ( struct V_1 * V_2 ,
unsigned long long V_69 )
{
int V_368 ;
T_1 V_370 , V_369 , V_373 , V_372 ;
int V_371 = F_155 ( V_2 ) ;
int V_92 = - V_340 ;
int V_374 = 0 ;
V_368 = V_371 * V_282 ;
V_373 = F_36 ( & V_2 -> V_158 , V_33 ) ;
while ( V_368 ) {
if ( F_361 ( V_26 ) ) {
V_92 = - V_287 ;
break;
}
F_147 ( & V_375 ) ;
V_370 = F_36 ( & V_2 -> V_60 , V_173 ) ;
if ( V_370 > V_69 ) {
V_92 = - V_341 ;
F_154 ( & V_375 ) ;
break;
}
V_369 = F_36 ( & V_2 -> V_158 , V_173 ) ;
if ( V_369 < V_69 )
V_374 = 1 ;
V_92 = F_362 ( & V_2 -> V_158 , V_69 ) ;
if ( ! V_92 ) {
if ( V_370 == V_69 )
V_2 -> V_202 = true ;
else
V_2 -> V_202 = false ;
}
F_154 ( & V_375 ) ;
if ( ! V_92 )
break;
F_170 ( V_2 , V_316 ,
V_200 |
V_201 ) ;
V_372 = F_36 ( & V_2 -> V_158 , V_33 ) ;
if ( V_372 >= V_373 )
V_368 -- ;
else
V_373 = V_372 ;
}
if ( ! V_92 && V_374 )
F_199 ( V_2 ) ;
return V_92 ;
}
unsigned long F_364 ( struct V_62 * V_62 , int V_183 ,
T_3 V_182 ,
unsigned long * V_211 )
{
unsigned long V_376 = 0 ;
struct V_34 * V_45 , * V_377 = NULL ;
unsigned long V_378 ;
int V_199 = 0 ;
struct V_41 * V_46 ;
unsigned long long V_59 ;
unsigned long V_213 ;
if ( V_183 > 0 )
return 0 ;
V_46 = F_44 ( F_104 ( V_62 ) , F_105 ( V_62 ) ) ;
do {
if ( V_377 )
V_45 = V_377 ;
else
V_45 = F_62 ( V_46 ) ;
if ( ! V_45 )
break;
V_213 = 0 ;
V_378 = F_186 ( V_45 -> V_2 , V_62 ,
V_182 , & V_213 ) ;
V_376 += V_378 ;
* V_211 += V_213 ;
F_53 ( & V_46 -> V_58 ) ;
V_377 = NULL ;
if ( ! V_378 ) {
do {
V_377 =
F_60 ( V_46 ) ;
if ( V_377 == V_45 )
F_29 ( & V_377 -> V_2 -> V_12 ) ;
else
break;
} while ( 1 );
}
F_50 ( V_45 -> V_2 , V_45 , V_46 ) ;
V_59 = F_57 ( & V_45 -> V_2 -> V_60 ) ;
F_46 ( V_45 -> V_2 , V_45 , V_46 , V_59 ) ;
F_54 ( & V_46 -> V_58 ) ;
F_29 ( & V_45 -> V_2 -> V_12 ) ;
V_199 ++ ;
if ( ! V_376 &&
( V_377 == NULL ||
V_199 > V_379 ) )
break;
} while ( ! V_376 );
if ( V_377 )
F_29 ( & V_377 -> V_2 -> V_12 ) ;
return V_376 ;
}
static void F_365 ( struct V_1 * V_2 ,
int V_61 , int V_36 , enum V_88 V_89 )
{
struct V_87 * V_87 ;
unsigned long V_118 ;
struct V_380 * V_324 ;
struct V_40 * V_381 ;
struct V_62 * V_62 ;
V_62 = & F_366 ( V_61 ) -> V_382 [ V_36 ] ;
V_87 = F_110 ( V_62 , V_2 ) ;
V_324 = & V_87 -> V_383 [ V_89 ] ;
V_381 = NULL ;
do {
struct V_144 * V_145 ;
struct V_40 * V_40 ;
F_142 ( & V_62 -> V_293 , V_118 ) ;
if ( F_367 ( V_324 ) ) {
F_144 ( & V_62 -> V_293 , V_118 ) ;
break;
}
V_40 = F_368 ( V_324 -> V_127 , struct V_40 , V_89 ) ;
if ( V_381 == V_40 ) {
F_369 ( & V_40 -> V_89 , V_324 ) ;
V_381 = NULL ;
F_144 ( & V_62 -> V_293 , V_118 ) ;
continue;
}
F_144 ( & V_62 -> V_293 , V_118 ) ;
V_145 = F_112 ( V_40 ) ;
if ( F_321 ( V_40 , V_145 , V_2 ) ) {
V_381 = V_40 ;
F_370 () ;
} else
V_381 = NULL ;
} while ( ! F_367 ( V_324 ) );
}
static void F_371 ( struct V_1 * V_2 )
{
int V_61 , V_36 ;
T_1 V_384 ;
do {
F_372 () ;
F_226 ( V_2 ) ;
F_129 ( V_2 ) ;
F_82 (node, N_MEMORY) {
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ ) {
enum V_88 V_89 ;
F_78 (lru) {
F_365 ( V_2 ,
V_61 , V_36 , V_89 ) ;
}
}
}
F_131 ( V_2 ) ;
F_199 ( V_2 ) ;
F_370 () ;
V_384 = F_36 ( & V_2 -> V_60 , V_33 ) -
F_36 ( & V_2 -> V_32 , V_33 ) ;
} while ( V_384 > 0 );
}
static inline bool F_373 ( struct V_1 * V_2 )
{
F_283 ( & V_385 ) ;
return V_2 -> V_130 &&
! F_367 ( & V_2 -> V_12 . V_16 -> V_371 ) ;
}
static int F_374 ( struct V_1 * V_2 )
{
int V_386 = V_282 ;
struct V_16 * V_387 = V_2 -> V_12 . V_16 ;
if ( F_375 ( V_387 ) || ! F_367 ( & V_387 -> V_371 ) )
return - V_340 ;
F_372 () ;
while ( V_386 && F_36 ( & V_2 -> V_60 , V_33 ) > 0 ) {
int V_388 ;
if ( F_361 ( V_26 ) )
return - V_287 ;
V_388 = F_172 ( V_2 , V_316 ,
false ) ;
if ( ! V_388 ) {
V_386 -- ;
F_376 ( V_389 , V_390 / 10 ) ;
}
}
F_377 () ;
F_371 ( V_2 ) ;
return 0 ;
}
static int F_378 ( struct V_10 * V_12 ,
unsigned int V_391 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( F_15 ( V_2 ) )
return - V_341 ;
return F_374 ( V_2 ) ;
}
static T_1 F_379 ( struct V_10 * V_12 ,
struct V_392 * V_393 )
{
return F_11 ( V_12 ) -> V_130 ;
}
static int F_380 ( struct V_10 * V_12 ,
struct V_392 * V_393 , T_1 V_69 )
{
int V_394 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_395 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
F_147 ( & V_385 ) ;
if ( V_2 -> V_130 == V_69 )
goto V_139;
if ( ( ! V_395 || ! V_395 -> V_130 ) &&
( V_69 == 1 || V_69 == 0 ) ) {
if ( F_367 ( & V_2 -> V_12 . V_16 -> V_371 ) )
V_2 -> V_130 = V_69 ;
else
V_394 = - V_340 ;
} else
V_394 = - V_341 ;
V_139:
F_154 ( & V_385 ) ;
return V_394 ;
}
static unsigned long F_381 ( struct V_1 * V_2 ,
enum V_67 V_68 )
{
struct V_1 * V_122 ;
long V_69 = 0 ;
F_151 (iter, memcg)
V_69 += F_63 ( V_122 , V_68 ) ;
if ( V_69 < 0 )
V_69 = 0 ;
return V_69 ;
}
static inline T_1 F_382 ( struct V_1 * V_2 , bool V_396 )
{
T_1 V_69 ;
if ( ! F_15 ( V_2 ) ) {
if ( ! V_396 )
return F_36 ( & V_2 -> V_60 , V_33 ) ;
else
return F_36 ( & V_2 -> V_158 , V_33 ) ;
}
V_69 = F_381 ( V_2 , V_82 ) ;
V_69 += F_381 ( V_2 , V_81 ) ;
if ( V_396 )
V_69 += F_381 ( V_2 , V_76 ) ;
return V_69 << V_155 ;
}
static T_1 F_383 ( struct V_10 * V_12 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
T_1 V_69 ;
int V_321 ;
enum V_397 type ;
type = F_384 ( V_393 -> V_237 ) ;
V_321 = F_385 ( V_393 -> V_237 ) ;
switch ( type ) {
case V_398 :
if ( V_321 == V_33 )
V_69 = F_382 ( V_2 , false ) ;
else
V_69 = F_36 ( & V_2 -> V_60 , V_321 ) ;
break;
case V_399 :
if ( V_321 == V_33 )
V_69 = F_382 ( V_2 , true ) ;
else
V_69 = F_36 ( & V_2 -> V_158 , V_321 ) ;
break;
case V_400 :
V_69 = F_36 ( & V_2 -> V_32 , V_321 ) ;
break;
default:
F_109 () ;
}
return V_69 ;
}
static int F_386 ( struct V_1 * V_2 ,
unsigned long long V_180 )
{
int V_401 = 0 ;
int V_402 ;
if ( F_3 ( V_2 ) )
return 0 ;
F_295 () ;
F_147 ( & V_385 ) ;
if ( F_375 ( V_2 -> V_12 . V_16 ) || F_373 ( V_2 ) )
V_401 = - V_340 ;
F_154 ( & V_385 ) ;
if ( V_401 )
goto V_139;
V_402 = F_387 ( & V_30 ,
0 , V_310 , V_316 ) ;
if ( V_402 < 0 ) {
V_401 = V_402 ;
goto V_139;
}
V_401 = F_388 ( V_402 + 1 ) ;
if ( V_401 )
goto V_403;
V_2 -> V_31 = V_402 ;
F_202 ( & V_2 -> V_325 ) ;
F_389 ( & V_2 -> V_305 ) ;
V_401 = F_362 ( & V_2 -> V_32 , V_180 ) ;
F_39 ( V_401 ) ;
F_390 ( & V_29 ) ;
F_1 ( V_2 ) ;
V_139:
F_296 () ;
return V_401 ;
V_403:
F_35 ( & V_30 , V_402 ) ;
goto V_139;
}
static int F_391 ( struct V_1 * V_2 ,
unsigned long long V_180 )
{
int V_92 ;
F_147 ( & V_330 ) ;
V_92 = F_386 ( V_2 , V_180 ) ;
F_154 ( & V_330 ) ;
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
F_147 ( & V_330 ) ;
if ( F_3 ( V_51 ) )
V_92 = F_386 ( V_2 , V_404 ) ;
F_154 ( & V_330 ) ;
return V_92 ;
}
static int F_392 ( struct V_1 * V_2 ,
unsigned long long V_69 )
{
return - V_341 ;
}
static int F_394 ( struct V_10 * V_12 , struct V_392 * V_393 ,
char * V_405 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
enum V_397 type ;
int V_321 ;
unsigned long long V_69 ;
int V_92 ;
type = F_384 ( V_393 -> V_237 ) ;
V_321 = F_385 ( V_393 -> V_237 ) ;
switch ( V_321 ) {
case V_173 :
if ( F_15 ( V_2 ) ) {
V_92 = - V_341 ;
break;
}
V_92 = F_395 ( V_405 , & V_69 ) ;
if ( V_92 )
break;
if ( type == V_398 )
V_92 = F_360 ( V_2 , V_69 ) ;
else if ( type == V_399 )
V_92 = F_363 ( V_2 , V_69 ) ;
else if ( type == V_400 )
V_92 = F_392 ( V_2 , V_69 ) ;
else
return - V_341 ;
break;
case V_406 :
V_92 = F_395 ( V_405 , & V_69 ) ;
if ( V_92 )
break;
if ( type == V_398 )
V_92 = F_396 ( & V_2 -> V_60 , V_69 ) ;
else
V_92 = - V_341 ;
break;
default:
V_92 = - V_341 ;
break;
}
return V_92 ;
}
static void F_397 ( struct V_1 * V_2 ,
unsigned long long * V_407 , unsigned long long * V_408 )
{
unsigned long long V_409 , V_410 , V_411 ;
V_409 = F_36 ( & V_2 -> V_60 , V_173 ) ;
V_410 = F_36 ( & V_2 -> V_158 , V_173 ) ;
if ( ! V_2 -> V_130 )
goto V_139;
while ( F_128 ( & V_2 -> V_12 ) ) {
V_2 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
if ( ! V_2 -> V_130 )
break;
V_411 = F_36 ( & V_2 -> V_60 , V_173 ) ;
V_409 = F_126 ( V_409 , V_411 ) ;
V_411 = F_36 ( & V_2 -> V_158 , V_173 ) ;
V_410 = F_126 ( V_410 , V_411 ) ;
}
V_139:
* V_407 = V_409 ;
* V_408 = V_410 ;
}
static int F_398 ( struct V_10 * V_12 , unsigned int V_391 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
int V_321 ;
enum V_397 type ;
type = F_384 ( V_391 ) ;
V_321 = F_385 ( V_391 ) ;
switch ( V_321 ) {
case V_412 :
if ( type == V_398 )
F_399 ( & V_2 -> V_60 ) ;
else if ( type == V_399 )
F_399 ( & V_2 -> V_158 ) ;
else if ( type == V_400 )
F_399 ( & V_2 -> V_32 ) ;
else
return - V_341 ;
break;
case V_174 :
if ( type == V_398 )
F_400 ( & V_2 -> V_60 ) ;
else if ( type == V_399 )
F_400 ( & V_2 -> V_158 ) ;
else if ( type == V_400 )
F_400 ( & V_2 -> V_32 ) ;
else
return - V_341 ;
break;
}
return 0 ;
}
static T_1 F_401 ( struct V_10 * V_12 ,
struct V_392 * V_393 )
{
return F_11 ( V_12 ) -> V_413 ;
}
static int F_402 ( struct V_10 * V_12 ,
struct V_392 * V_393 , T_1 V_69 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_69 >= ( 1 << V_414 ) )
return - V_341 ;
V_2 -> V_413 = V_69 ;
return 0 ;
}
static int F_402 ( struct V_10 * V_12 ,
struct V_392 * V_393 , T_1 V_69 )
{
return - V_415 ;
}
static int F_403 ( struct V_300 * V_301 , void * V_302 )
{
struct V_416 {
const char * V_321 ;
unsigned int V_91 ;
};
static const struct V_416 V_417 [] = {
{ L_14 , V_418 } ,
{ L_15 , V_204 } ,
{ L_16 , V_205 } ,
{ L_17 , F_79 (LRU_UNEVICTABLE) } ,
} ;
const struct V_416 * V_71 ;
int V_35 ;
unsigned long V_419 ;
struct V_1 * V_2 = F_11 ( F_267 ( V_301 ) ) ;
for ( V_71 = V_417 ; V_71 < V_417 + F_404 ( V_417 ) ; V_71 ++ ) {
V_419 = F_81 ( V_2 , V_71 -> V_91 ) ;
F_405 ( V_301 , L_18 , V_71 -> V_321 , V_419 ) ;
F_82 (nid, N_MEMORY) {
V_419 = F_80 ( V_2 , V_35 ,
V_71 -> V_91 ) ;
F_405 ( V_301 , L_19 , V_35 , V_419 ) ;
}
F_406 ( V_301 , '\n' ) ;
}
for ( V_71 = V_417 ; V_71 < V_417 + F_404 ( V_417 ) ; V_71 ++ ) {
struct V_1 * V_122 ;
V_419 = 0 ;
F_151 (iter, memcg)
V_419 += F_81 ( V_122 , V_71 -> V_91 ) ;
F_405 ( V_301 , L_20 , V_71 -> V_321 , V_419 ) ;
F_82 (nid, N_MEMORY) {
V_419 = 0 ;
F_151 (iter, memcg)
V_419 += F_80 (
V_122 , V_35 , V_71 -> V_91 ) ;
F_405 ( V_301 , L_19 , V_35 , V_419 ) ;
}
F_406 ( V_301 , '\n' ) ;
}
return 0 ;
}
static inline void F_407 ( void )
{
F_408 ( F_404 ( V_178 ) != V_177 ) ;
}
static int F_409 ( struct V_300 * V_301 , void * V_302 )
{
struct V_1 * V_2 = F_11 ( F_267 ( V_301 ) ) ;
struct V_1 * V_420 ;
unsigned int V_172 ;
for ( V_172 = 0 ; V_172 < V_175 ; V_172 ++ ) {
if ( V_172 == V_76 && ! V_157 )
continue;
F_405 ( V_301 , L_21 , V_176 [ V_172 ] ,
F_63 ( V_2 , V_172 ) * V_249 ) ;
}
for ( V_172 = 0 ; V_172 < V_257 ; V_172 ++ )
F_405 ( V_301 , L_22 , V_421 [ V_172 ] ,
F_71 ( V_2 , V_172 ) ) ;
for ( V_172 = 0 ; V_172 < V_177 ; V_172 ++ )
F_405 ( V_301 , L_22 , V_178 [ V_172 ] ,
F_81 ( V_2 , F_79 ( V_172 ) ) * V_249 ) ;
{
unsigned long long V_180 , V_408 ;
F_397 ( V_2 , & V_180 , & V_408 ) ;
F_405 ( V_301 , L_23 , V_180 ) ;
if ( V_157 )
F_405 ( V_301 , L_24 ,
V_408 ) ;
}
for ( V_172 = 0 ; V_172 < V_175 ; V_172 ++ ) {
long long V_69 = 0 ;
if ( V_172 == V_76 && ! V_157 )
continue;
F_151 (mi, memcg)
V_69 += F_63 ( V_420 , V_172 ) * V_249 ;
F_405 ( V_301 , L_25 , V_176 [ V_172 ] , V_69 ) ;
}
for ( V_172 = 0 ; V_172 < V_257 ; V_172 ++ ) {
unsigned long long V_69 = 0 ;
F_151 (mi, memcg)
V_69 += F_71 ( V_420 , V_172 ) ;
F_405 ( V_301 , L_26 ,
V_421 [ V_172 ] , V_69 ) ;
}
for ( V_172 = 0 ; V_172 < V_177 ; V_172 ++ ) {
unsigned long long V_69 = 0 ;
F_151 (mi, memcg)
V_69 += F_81 ( V_420 , F_79 ( V_172 ) ) * V_249 ;
F_405 ( V_301 , L_26 , V_178 [ V_172 ] , V_69 ) ;
}
#ifdef F_410
{
int V_35 , V_36 ;
struct V_34 * V_45 ;
struct V_422 * V_423 ;
unsigned long V_424 [ 2 ] = { 0 , 0 } ;
unsigned long V_425 [ 2 ] = { 0 , 0 } ;
F_411 (nid)
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ ) {
V_45 = F_38 ( V_2 , V_35 , V_36 ) ;
V_423 = & V_45 -> V_87 . V_426 ;
V_424 [ 0 ] += V_423 -> V_424 [ 0 ] ;
V_424 [ 1 ] += V_423 -> V_424 [ 1 ] ;
V_425 [ 0 ] += V_423 -> V_425 [ 0 ] ;
V_425 [ 1 ] += V_423 -> V_425 [ 1 ] ;
}
F_405 ( V_301 , L_27 , V_424 [ 0 ] ) ;
F_405 ( V_301 , L_28 , V_424 [ 1 ] ) ;
F_405 ( V_301 , L_29 , V_425 [ 0 ] ) ;
F_405 ( V_301 , L_30 , V_425 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_412 ( struct V_10 * V_12 ,
struct V_392 * V_393 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
return F_127 ( V_2 ) ;
}
static int F_413 ( struct V_10 * V_12 ,
struct V_392 * V_393 , T_1 V_69 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_51 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
if ( V_69 > 100 || ! V_51 )
return - V_341 ;
F_147 ( & V_385 ) ;
if ( ( V_51 -> V_130 ) || F_373 ( V_2 ) ) {
F_154 ( & V_385 ) ;
return - V_341 ;
}
V_2 -> V_160 = V_69 ;
F_154 ( & V_385 ) ;
return 0 ;
}
static void F_414 ( struct V_1 * V_2 , bool V_396 )
{
struct V_427 * V_428 ;
T_1 V_384 ;
int V_172 ;
F_22 () ;
if ( ! V_396 )
V_428 = F_94 ( V_2 -> V_429 . V_430 ) ;
else
V_428 = F_94 ( V_2 -> V_431 . V_430 ) ;
if ( ! V_428 )
goto V_165;
V_384 = F_382 ( V_2 , V_396 ) ;
V_172 = V_428 -> V_432 ;
for (; V_172 >= 0 && F_88 ( V_428 -> V_433 [ V_172 ] . V_434 > V_384 ) ; V_172 -- )
F_415 ( V_428 -> V_433 [ V_172 ] . V_435 , 1 ) ;
V_172 ++ ;
for (; V_172 < V_428 -> V_307 && F_88 ( V_428 -> V_433 [ V_172 ] . V_434 <= V_384 ) ; V_172 ++ )
F_415 ( V_428 -> V_433 [ V_172 ] . V_435 , 1 ) ;
V_428 -> V_432 = V_172 - 1 ;
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
static int F_416 ( const void * V_436 , const void * V_437 )
{
const struct F_90 * V_438 = V_436 ;
const struct F_90 * V_439 = V_437 ;
if ( V_438 -> V_434 > V_439 -> V_434 )
return 1 ;
if ( V_438 -> V_434 < V_439 -> V_434 )
return - 1 ;
return 0 ;
}
static int F_417 ( struct V_1 * V_2 )
{
struct V_440 * V_441 ;
F_269 (ev, &memcg->oom_notify, list)
F_415 ( V_441 -> V_435 , 1 ) ;
return 0 ;
}
static void F_203 ( struct V_1 * V_2 )
{
struct V_1 * V_122 ;
F_151 (iter, memcg)
F_417 ( V_122 ) ;
}
static int F_418 ( struct V_1 * V_2 ,
struct V_442 * V_435 , const char * args , enum V_397 type )
{
struct V_443 * V_429 ;
struct V_427 * V_444 ;
T_1 V_434 , V_384 ;
int V_172 , V_307 , V_92 ;
V_92 = F_395 ( args , & V_434 ) ;
if ( V_92 )
return V_92 ;
F_147 ( & V_2 -> V_445 ) ;
if ( type == V_398 )
V_429 = & V_2 -> V_429 ;
else if ( type == V_399 )
V_429 = & V_2 -> V_431 ;
else
F_109 () ;
V_384 = F_382 ( V_2 , type == V_399 ) ;
if ( V_429 -> V_430 )
F_414 ( V_2 , type == V_399 ) ;
V_307 = V_429 -> V_430 ? V_429 -> V_430 -> V_307 + 1 : 1 ;
V_444 = F_284 ( sizeof( * V_444 ) + V_307 * sizeof( struct F_90 ) ,
V_316 ) ;
if ( ! V_444 ) {
V_92 = - V_286 ;
goto V_165;
}
V_444 -> V_307 = V_307 ;
if ( V_429 -> V_430 ) {
memcpy ( V_444 -> V_433 , V_429 -> V_430 -> V_433 , ( V_307 - 1 ) *
sizeof( struct F_90 ) ) ;
}
V_444 -> V_433 [ V_307 - 1 ] . V_435 = V_435 ;
V_444 -> V_433 [ V_307 - 1 ] . V_434 = V_434 ;
F_419 ( V_444 -> V_433 , V_307 , sizeof( struct F_90 ) ,
F_416 , NULL ) ;
V_444 -> V_432 = - 1 ;
for ( V_172 = 0 ; V_172 < V_307 ; V_172 ++ ) {
if ( V_444 -> V_433 [ V_172 ] . V_434 <= V_384 ) {
++ V_444 -> V_432 ;
} else
break;
}
F_290 ( V_429 -> V_446 ) ;
V_429 -> V_446 = V_429 -> V_430 ;
F_280 ( V_429 -> V_430 , V_444 ) ;
F_130 () ;
V_165:
F_154 ( & V_2 -> V_445 ) ;
return V_92 ;
}
static int F_420 ( struct V_1 * V_2 ,
struct V_442 * V_435 , const char * args )
{
return F_418 ( V_2 , V_435 , args , V_398 ) ;
}
static int F_421 ( struct V_1 * V_2 ,
struct V_442 * V_435 , const char * args )
{
return F_418 ( V_2 , V_435 , args , V_399 ) ;
}
static void F_422 ( struct V_1 * V_2 ,
struct V_442 * V_435 , enum V_397 type )
{
struct V_443 * V_429 ;
struct V_427 * V_444 ;
T_1 V_384 ;
int V_172 , V_447 , V_307 ;
F_147 ( & V_2 -> V_445 ) ;
if ( type == V_398 )
V_429 = & V_2 -> V_429 ;
else if ( type == V_399 )
V_429 = & V_2 -> V_431 ;
else
F_109 () ;
if ( ! V_429 -> V_430 )
goto V_165;
V_384 = F_382 ( V_2 , type == V_399 ) ;
F_414 ( V_2 , type == V_399 ) ;
V_307 = 0 ;
for ( V_172 = 0 ; V_172 < V_429 -> V_430 -> V_307 ; V_172 ++ ) {
if ( V_429 -> V_430 -> V_433 [ V_172 ] . V_435 != V_435 )
V_307 ++ ;
}
V_444 = V_429 -> V_446 ;
if ( ! V_307 ) {
F_290 ( V_444 ) ;
V_444 = NULL ;
goto V_448;
}
V_444 -> V_307 = V_307 ;
V_444 -> V_432 = - 1 ;
for ( V_172 = 0 , V_447 = 0 ; V_172 < V_429 -> V_430 -> V_307 ; V_172 ++ ) {
if ( V_429 -> V_430 -> V_433 [ V_172 ] . V_435 == V_435 )
continue;
V_444 -> V_433 [ V_447 ] = V_429 -> V_430 -> V_433 [ V_172 ] ;
if ( V_444 -> V_433 [ V_447 ] . V_434 <= V_384 ) {
++ V_444 -> V_432 ;
}
V_447 ++ ;
}
V_448:
V_429 -> V_446 = V_429 -> V_430 ;
if ( ! V_444 ) {
F_290 ( V_429 -> V_446 ) ;
V_429 -> V_446 = NULL ;
}
F_280 ( V_429 -> V_430 , V_444 ) ;
F_130 () ;
V_165:
F_154 ( & V_2 -> V_445 ) ;
}
static void F_423 ( struct V_1 * V_2 ,
struct V_442 * V_435 )
{
return F_422 ( V_2 , V_435 , V_398 ) ;
}
static void F_424 ( struct V_1 * V_2 ,
struct V_442 * V_435 )
{
return F_422 ( V_2 , V_435 , V_399 ) ;
}
static int F_425 ( struct V_1 * V_2 ,
struct V_442 * V_435 , const char * args )
{
struct V_440 * V_391 ;
V_391 = F_284 ( sizeof( * V_391 ) , V_316 ) ;
if ( ! V_391 )
return - V_286 ;
F_53 ( & V_215 ) ;
V_391 -> V_435 = V_435 ;
F_292 ( & V_391 -> V_324 , & V_2 -> V_449 ) ;
if ( F_99 ( & V_2 -> V_219 ) )
F_415 ( V_435 , 1 ) ;
F_54 ( & V_215 ) ;
return 0 ;
}
static void F_426 ( struct V_1 * V_2 ,
struct V_442 * V_435 )
{
struct V_440 * V_441 , * V_411 ;
F_53 ( & V_215 ) ;
F_427 (ev, tmp, &memcg->oom_notify, list) {
if ( V_441 -> V_435 == V_435 ) {
F_294 ( & V_441 -> V_324 ) ;
F_290 ( V_441 ) ;
}
}
F_54 ( & V_215 ) ;
}
static int F_428 ( struct V_300 * V_450 , void * V_302 )
{
struct V_1 * V_2 = F_11 ( F_267 ( V_450 ) ) ;
F_405 ( V_450 , L_31 , V_2 -> V_240 ) ;
F_405 ( V_450 , L_32 , ( bool ) F_99 ( & V_2 -> V_219 ) ) ;
return 0 ;
}
static int F_429 ( struct V_10 * V_12 ,
struct V_392 * V_393 , T_1 V_69 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_51 = F_11 ( F_128 ( & V_2 -> V_12 ) ) ;
if ( ! V_51 || ! ( ( V_69 == 0 ) || ( V_69 == 1 ) ) )
return - V_341 ;
F_147 ( & V_385 ) ;
if ( ( V_51 -> V_130 ) || F_373 ( V_2 ) ) {
F_154 ( & V_385 ) ;
return - V_341 ;
}
V_2 -> V_240 = V_69 ;
if ( ! V_69 )
F_199 ( V_2 ) ;
F_154 ( & V_385 ) ;
return 0 ;
}
static int F_430 ( struct V_1 * V_2 , struct V_451 * V_452 )
{
int V_92 ;
V_2 -> V_31 = - 1 ;
V_92 = F_393 ( V_2 ) ;
if ( V_92 )
return V_92 ;
return F_431 ( V_2 , V_452 ) ;
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
static int F_430 ( struct V_1 * V_2 , struct V_451 * V_452 )
{
return 0 ;
}
static void F_432 ( struct V_1 * V_2 )
{
}
static void F_434 ( struct V_1 * V_2 )
{
}
static void F_435 ( struct V_250 * V_253 )
{
struct V_453 * V_391 =
F_12 ( V_253 , struct V_453 , remove ) ;
struct V_1 * V_2 = V_391 -> V_2 ;
F_436 ( V_391 -> V_454 , & V_391 -> V_167 ) ;
V_391 -> V_455 ( V_2 , V_391 -> V_435 ) ;
F_415 ( V_391 -> V_435 , 1 ) ;
F_437 ( V_391 -> V_435 ) ;
F_290 ( V_391 ) ;
F_29 ( & V_2 -> V_12 ) ;
}
static int F_438 ( T_4 * V_167 , unsigned V_220 ,
int V_221 , void * V_456 )
{
struct V_453 * V_391 =
F_12 ( V_167 , struct V_453 , V_167 ) ;
struct V_1 * V_2 = V_391 -> V_2 ;
unsigned long V_118 = ( unsigned long ) V_456 ;
if ( V_118 & V_457 ) {
F_53 ( & V_2 -> V_458 ) ;
if ( ! F_367 ( & V_391 -> V_324 ) ) {
F_439 ( & V_391 -> V_324 ) ;
F_301 ( & V_391 -> remove ) ;
}
F_54 ( & V_2 -> V_458 ) ;
}
return 0 ;
}
static void F_440 ( struct V_459 * V_459 ,
T_9 * V_454 , T_10 * V_460 )
{
struct V_453 * V_391 =
F_12 ( V_460 , struct V_453 , V_460 ) ;
V_391 -> V_454 = V_454 ;
F_441 ( V_454 , & V_391 -> V_167 ) ;
}
static int F_442 ( struct V_10 * V_12 ,
struct V_392 * V_393 , char * V_405 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_453 * V_391 ;
struct V_10 * V_461 ;
unsigned int V_462 , V_463 ;
struct V_464 V_465 ;
struct V_464 V_466 ;
const char * V_321 ;
char * V_467 ;
int V_92 ;
V_462 = F_443 ( V_405 , & V_467 , 10 ) ;
if ( * V_467 != ' ' )
return - V_341 ;
V_405 = V_467 + 1 ;
V_463 = F_443 ( V_405 , & V_467 , 10 ) ;
if ( ( * V_467 != ' ' ) && ( * V_467 != '\0' ) )
return - V_341 ;
V_405 = V_467 + 1 ;
V_391 = F_279 ( sizeof( * V_391 ) , V_316 ) ;
if ( ! V_391 )
return - V_286 ;
V_391 -> V_2 = V_2 ;
F_202 ( & V_391 -> V_324 ) ;
F_444 ( & V_391 -> V_460 , F_440 ) ;
F_445 ( & V_391 -> V_167 , F_438 ) ;
F_217 ( & V_391 -> remove , F_435 ) ;
V_465 = F_446 ( V_462 ) ;
if ( ! V_465 . V_459 ) {
V_92 = - V_468 ;
goto V_469;
}
V_391 -> V_435 = F_447 ( V_465 . V_459 ) ;
if ( F_448 ( V_391 -> V_435 ) ) {
V_92 = F_449 ( V_391 -> V_435 ) ;
goto V_470;
}
V_466 = F_446 ( V_463 ) ;
if ( ! V_466 . V_459 ) {
V_92 = - V_468 ;
goto V_471;
}
V_92 = F_450 ( F_451 ( V_466 . V_459 ) , V_472 ) ;
if ( V_92 < 0 )
goto V_473;
V_321 = V_466 . V_459 -> V_474 -> V_475 . V_321 ;
if ( ! strcmp ( V_321 , L_33 ) ) {
V_391 -> V_476 = F_420 ;
V_391 -> V_455 = F_423 ;
} else if ( ! strcmp ( V_321 , L_34 ) ) {
V_391 -> V_476 = F_425 ;
V_391 -> V_455 = F_426 ;
} else if ( ! strcmp ( V_321 , L_35 ) ) {
V_391 -> V_476 = V_477 ;
V_391 -> V_455 = V_478 ;
} else if ( ! strcmp ( V_321 , L_36 ) ) {
V_391 -> V_476 = F_421 ;
V_391 -> V_455 = F_424 ;
} else {
V_92 = - V_341 ;
goto V_473;
}
V_461 = F_452 ( V_466 . V_459 -> V_474 -> V_479 ,
& V_18 ) ;
V_92 = - V_341 ;
if ( F_448 ( V_461 ) )
goto V_473;
if ( V_461 != V_12 ) {
F_29 ( V_461 ) ;
goto V_473;
}
V_92 = V_391 -> V_476 ( V_2 , V_391 -> V_435 , V_405 ) ;
if ( V_92 )
goto V_480;
V_465 . V_459 -> V_481 -> V_482 ( V_465 . V_459 , & V_391 -> V_460 ) ;
F_53 ( & V_2 -> V_458 ) ;
F_292 ( & V_391 -> V_324 , & V_2 -> V_483 ) ;
F_54 ( & V_2 -> V_458 ) ;
F_453 ( V_466 ) ;
F_453 ( V_465 ) ;
return 0 ;
V_480:
F_29 ( V_12 ) ;
V_473:
F_453 ( V_466 ) ;
V_471:
F_437 ( V_391 -> V_435 ) ;
V_470:
F_453 ( V_465 ) ;
V_469:
F_290 ( V_391 ) ;
return V_92 ;
}
static int F_454 ( struct V_1 * V_2 , int V_61 )
{
struct V_484 * V_485 ;
struct V_34 * V_45 ;
int V_62 , V_411 = V_61 ;
if ( ! F_455 ( V_61 , V_486 ) )
V_411 = - 1 ;
V_485 = F_456 ( sizeof( * V_485 ) , V_316 , V_411 ) ;
if ( ! V_485 )
return 1 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_45 = & V_485 -> V_39 [ V_62 ] ;
F_457 ( & V_45 -> V_87 ) ;
V_45 -> V_54 = 0 ;
V_45 -> V_53 = false ;
V_45 -> V_2 = V_2 ;
}
V_2 -> V_38 [ V_61 ] = V_485 ;
return 0 ;
}
static void F_458 ( struct V_1 * V_2 , int V_61 )
{
F_290 ( V_2 -> V_38 [ V_61 ] ) ;
}
static struct V_1 * F_459 ( void )
{
struct V_1 * V_2 ;
T_7 V_307 ;
V_307 = sizeof( struct V_1 ) ;
V_307 += V_37 * sizeof( struct V_484 * ) ;
V_2 = F_279 ( V_307 , V_316 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_71 = F_460 ( struct V_487 ) ;
if ( ! V_2 -> V_71 )
goto V_488;
F_461 ( & V_2 -> V_73 ) ;
return V_2 ;
V_488:
F_290 ( V_2 ) ;
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
F_290 ( V_2 ) ;
}
struct V_1 * F_56 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_60 . V_51 )
return NULL ;
return F_233 ( V_2 -> V_60 . V_51 , V_60 ) ;
}
static void T_5 F_464 ( void )
{
struct V_489 * V_490 ;
struct V_41 * V_491 ;
int V_411 , V_61 , V_62 ;
F_59 (node) {
V_411 = V_61 ;
if ( ! F_455 ( V_61 , V_486 ) )
V_411 = - 1 ;
V_490 = F_456 ( sizeof( * V_490 ) , V_316 , V_411 ) ;
F_20 ( ! V_490 ) ;
V_42 . V_43 [ V_61 ] = V_490 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_491 = & V_490 -> V_44 [ V_62 ] ;
V_491 -> V_50 = V_492 ;
F_461 ( & V_491 -> V_58 ) ;
}
}
}
static struct V_10 * T_11
F_465 ( struct V_10 * V_493 )
{
struct V_1 * V_2 ;
long error = - V_286 ;
int V_61 ;
V_2 = F_459 () ;
if ( ! V_2 )
return F_466 ( error ) ;
F_59 (node)
if ( F_454 ( V_2 , V_61 ) )
goto V_494;
if ( V_493 == NULL ) {
V_14 = V_2 ;
F_467 ( & V_2 -> V_60 , NULL ) ;
F_467 ( & V_2 -> V_158 , NULL ) ;
F_467 ( & V_2 -> V_32 , NULL ) ;
}
V_2 -> V_210 = V_106 ;
F_202 ( & V_2 -> V_449 ) ;
V_2 -> V_413 = 0 ;
F_389 ( & V_2 -> V_445 ) ;
F_461 ( & V_2 -> V_170 ) ;
F_468 ( & V_2 -> V_13 ) ;
F_202 ( & V_2 -> V_483 ) ;
F_461 ( & V_2 -> V_458 ) ;
return & V_2 -> V_12 ;
V_494:
F_462 ( V_2 ) ;
return F_466 ( error ) ;
}
static int
F_469 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_51 = F_11 ( F_128 ( V_12 ) ) ;
if ( V_12 -> V_16 -> V_17 > V_495 )
return - V_496 ;
if ( ! V_51 )
return 0 ;
F_147 ( & V_385 ) ;
V_2 -> V_130 = V_51 -> V_130 ;
V_2 -> V_240 = V_51 -> V_240 ;
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
V_18 . V_497 = true ;
}
F_154 ( & V_385 ) ;
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
struct V_453 * V_391 , * V_411 ;
struct V_10 * V_122 ;
F_53 ( & V_2 -> V_458 ) ;
F_427 (event, tmp, &memcg->event_list, list) {
F_439 ( & V_391 -> V_324 ) ;
F_301 ( & V_391 -> remove ) ;
}
F_54 ( & V_2 -> V_458 ) ;
F_434 ( V_2 ) ;
F_470 ( V_2 ) ;
F_472 (iter, css)
F_371 ( F_11 ( V_122 ) ) ;
F_305 ( V_2 ) ;
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
int V_498 = V_499 ;
struct V_1 * V_2 = V_7 . V_164 ;
if ( F_15 ( V_2 ) ) {
V_7 . V_500 += V_72 ;
return V_92 ;
}
if ( V_72 > 1 ) {
struct V_270 * V_251 ;
if ( F_231 ( & V_2 -> V_60 , V_249 * V_72 , & V_251 ) )
goto V_501;
if ( V_157 && F_231 ( & V_2 -> V_158 ,
V_249 * V_72 , & V_251 ) ) {
F_211 ( & V_2 -> V_60 , V_249 * V_72 ) ;
goto V_501;
}
V_7 . V_500 += V_72 ;
return V_92 ;
}
V_501:
while ( V_72 -- ) {
if ( F_361 ( V_26 ) ) {
V_92 = - V_287 ;
break;
}
if ( ! V_498 -- ) {
V_498 = V_499 ;
F_370 () ;
}
V_92 = F_235 ( V_2 , V_316 , 1 , false ) ;
if ( V_92 )
return V_92 ;
V_7 . V_500 ++ ;
}
return V_92 ;
}
static struct V_40 * F_476 ( struct V_502 * V_503 ,
unsigned long V_504 , T_12 V_505 )
{
struct V_40 * V_40 = F_477 ( V_503 , V_504 , V_505 ) ;
if ( ! V_40 || ! F_319 ( V_40 ) )
return NULL ;
if ( F_318 ( V_40 ) ) {
if ( ! F_9 () )
return NULL ;
} else if ( ! F_10 () )
return NULL ;
if ( ! F_322 ( V_40 ) )
return NULL ;
return V_40 ;
}
static struct V_40 * F_478 ( struct V_502 * V_503 ,
unsigned long V_504 , T_12 V_505 , T_6 * V_360 )
{
struct V_40 * V_40 = NULL ;
T_6 V_288 = F_479 ( V_505 ) ;
if ( ! F_9 () || F_480 ( V_288 ) )
return NULL ;
V_40 = F_481 ( F_482 ( V_288 ) , V_288 . V_69 ) ;
if ( V_157 )
V_360 -> V_69 = V_288 . V_69 ;
return V_40 ;
}
static struct V_40 * F_478 ( struct V_502 * V_503 ,
unsigned long V_504 , T_12 V_505 , T_6 * V_360 )
{
return NULL ;
}
static struct V_40 * F_483 ( struct V_502 * V_503 ,
unsigned long V_504 , T_12 V_505 , T_6 * V_360 )
{
struct V_40 * V_40 = NULL ;
struct V_506 * V_346 ;
T_13 V_507 ;
if ( ! V_503 -> V_508 )
return NULL ;
if ( ! F_10 () )
return NULL ;
V_346 = V_503 -> V_508 -> V_509 ;
if ( F_484 ( V_505 ) )
V_507 = F_485 ( V_503 , V_504 ) ;
else
V_507 = F_486 ( V_505 ) ;
#ifdef F_487
if ( F_488 ( V_346 ) ) {
V_40 = F_489 ( V_346 , V_507 ) ;
if ( F_490 ( V_40 ) ) {
T_6 V_510 = F_491 ( V_40 ) ;
if ( V_157 )
* V_360 = V_510 ;
V_40 = F_481 ( F_482 ( V_510 ) , V_510 . V_69 ) ;
}
} else
V_40 = F_481 ( V_346 , V_507 ) ;
#else
V_40 = F_481 ( V_346 , V_507 ) ;
#endif
return V_40 ;
}
static enum V_511 F_492 ( struct V_502 * V_503 ,
unsigned long V_504 , T_12 V_505 , union V_512 * V_95 )
{
struct V_40 * V_40 = NULL ;
struct V_144 * V_145 ;
enum V_511 V_92 = V_513 ;
T_6 V_288 = { . V_69 = 0 } ;
if ( F_493 ( V_505 ) )
V_40 = F_476 ( V_503 , V_504 , V_505 ) ;
else if ( F_494 ( V_505 ) )
V_40 = F_478 ( V_503 , V_504 , V_505 , & V_288 ) ;
else if ( F_484 ( V_505 ) || F_495 ( V_505 ) )
V_40 = F_483 ( V_503 , V_504 , V_505 , & V_288 ) ;
if ( ! V_40 && ! V_288 . V_69 )
return V_92 ;
if ( V_40 ) {
V_145 = F_112 ( V_40 ) ;
if ( F_114 ( V_145 ) && V_145 -> V_1 == V_7 . V_163 ) {
V_92 = V_514 ;
if ( V_95 )
V_95 -> V_40 = V_40 ;
}
if ( ! V_92 || ! V_95 )
F_328 ( V_40 ) ;
}
if ( V_288 . V_69 && ! V_92 &&
F_16 ( V_7 . V_163 ) == F_250 ( V_288 ) ) {
V_92 = V_515 ;
if ( V_95 )
V_95 -> V_288 = V_288 ;
}
return V_92 ;
}
static enum V_511 F_496 ( struct V_502 * V_503 ,
unsigned long V_504 , T_14 V_516 , union V_512 * V_95 )
{
struct V_40 * V_40 = NULL ;
struct V_144 * V_145 ;
enum V_511 V_92 = V_513 ;
V_40 = F_497 ( V_516 ) ;
F_245 ( ! V_40 || ! F_498 ( V_40 ) , V_40 ) ;
if ( ! F_9 () )
return V_92 ;
V_145 = F_112 ( V_40 ) ;
if ( F_114 ( V_145 ) && V_145 -> V_1 == V_7 . V_163 ) {
V_92 = V_514 ;
if ( V_95 ) {
F_499 ( V_40 ) ;
V_95 -> V_40 = V_40 ;
}
}
return V_92 ;
}
static inline enum V_511 F_496 ( struct V_502 * V_503 ,
unsigned long V_504 , T_14 V_516 , union V_512 * V_95 )
{
return V_513 ;
}
static int F_500 ( T_14 * V_516 ,
unsigned long V_504 , unsigned long V_517 ,
struct V_518 * V_519 )
{
struct V_502 * V_503 = V_519 -> V_237 ;
T_12 * V_520 ;
T_15 * V_521 ;
if ( F_501 ( V_516 , V_503 , & V_521 ) == 1 ) {
if ( F_496 ( V_503 , V_504 , * V_516 , NULL ) == V_514 )
V_7 . V_500 += V_338 ;
F_54 ( V_521 ) ;
return 0 ;
}
if ( F_502 ( V_516 ) )
return 0 ;
V_520 = F_503 ( V_503 -> V_522 , V_516 , V_504 , & V_521 ) ;
for (; V_504 != V_517 ; V_520 ++ , V_504 += V_249 )
if ( F_492 ( V_503 , V_504 , * V_520 , NULL ) )
V_7 . V_500 ++ ;
F_504 ( V_520 - 1 , V_521 ) ;
F_370 () ;
return 0 ;
}
static unsigned long F_505 ( struct V_110 * V_111 )
{
unsigned long V_500 ;
struct V_502 * V_503 ;
F_506 ( & V_111 -> V_523 ) ;
for ( V_503 = V_111 -> V_524 ; V_503 ; V_503 = V_503 -> V_525 ) {
struct V_518 V_526 = {
. V_527 = F_500 ,
. V_111 = V_111 ,
. V_237 = V_503 ,
} ;
if ( F_507 ( V_503 ) )
continue;
F_508 ( V_503 -> V_528 , V_503 -> V_529 ,
& V_526 ) ;
}
F_509 ( & V_111 -> V_523 ) ;
V_500 = V_7 . V_500 ;
V_7 . V_500 = 0 ;
return V_500 ;
}
static int F_510 ( struct V_110 * V_111 )
{
unsigned long V_500 = F_505 ( V_111 ) ;
F_39 ( V_7 . V_166 ) ;
V_7 . V_166 = V_26 ;
return F_475 ( V_500 ) ;
}
static void F_511 ( void )
{
struct V_1 * V_163 = V_7 . V_163 ;
struct V_1 * V_164 = V_7 . V_164 ;
int V_172 ;
if ( V_7 . V_500 ) {
F_240 ( V_7 . V_164 , V_7 . V_500 ) ;
V_7 . V_500 = 0 ;
}
if ( V_7 . V_530 ) {
F_240 ( V_7 . V_163 , V_7 . V_530 ) ;
V_7 . V_530 = 0 ;
}
if ( V_7 . V_531 ) {
if ( ! F_15 ( V_7 . V_163 ) )
F_211 ( & V_7 . V_163 -> V_158 ,
V_249 * V_7 . V_531 ) ;
for ( V_172 = 0 ; V_172 < V_7 . V_531 ; V_172 ++ )
F_29 ( & V_7 . V_163 -> V_12 ) ;
if ( ! F_15 ( V_7 . V_164 ) ) {
F_211 ( & V_7 . V_164 -> V_60 ,
V_249 * V_7 . V_531 ) ;
}
V_7 . V_531 = 0 ;
}
F_199 ( V_163 ) ;
F_199 ( V_164 ) ;
F_512 ( & V_7 . V_168 ) ;
}
static void F_513 ( void )
{
struct V_1 * V_163 = V_7 . V_163 ;
V_7 . V_166 = NULL ;
F_511 () ;
F_53 ( & V_7 . V_58 ) ;
V_7 . V_163 = NULL ;
V_7 . V_164 = NULL ;
F_54 ( & V_7 . V_58 ) ;
F_131 ( V_163 ) ;
}
static int F_514 ( struct V_10 * V_12 ,
struct V_532 * V_533 )
{
struct V_108 * V_49 = F_515 ( V_533 ) ;
int V_92 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned long V_413 ;
V_413 = V_2 -> V_413 ;
if ( V_413 ) {
struct V_110 * V_111 ;
struct V_1 * V_163 = F_23 ( V_49 ) ;
F_39 ( V_163 == V_2 ) ;
V_111 = F_516 ( V_49 ) ;
if ( ! V_111 )
return 0 ;
if ( V_111 -> V_112 == V_49 ) {
F_39 ( V_7 . V_163 ) ;
F_39 ( V_7 . V_164 ) ;
F_39 ( V_7 . V_500 ) ;
F_39 ( V_7 . V_530 ) ;
F_39 ( V_7 . V_531 ) ;
F_129 ( V_163 ) ;
F_53 ( & V_7 . V_58 ) ;
V_7 . V_163 = V_163 ;
V_7 . V_164 = V_2 ;
V_7 . V_8 = V_413 ;
F_54 ( & V_7 . V_58 ) ;
V_92 = F_510 ( V_111 ) ;
if ( V_92 )
F_513 () ;
}
F_517 ( V_111 ) ;
}
return V_92 ;
}
static void F_518 ( struct V_10 * V_12 ,
struct V_532 * V_533 )
{
F_513 () ;
}
static int F_519 ( T_14 * V_516 ,
unsigned long V_504 , unsigned long V_517 ,
struct V_518 * V_519 )
{
int V_92 = 0 ;
struct V_502 * V_503 = V_519 -> V_237 ;
T_12 * V_520 ;
T_15 * V_521 ;
enum V_511 V_534 ;
union V_512 V_95 ;
struct V_40 * V_40 ;
struct V_144 * V_145 ;
if ( F_501 ( V_516 , V_503 , & V_521 ) == 1 ) {
if ( V_7 . V_500 < V_338 ) {
F_54 ( V_521 ) ;
return 0 ;
}
V_534 = F_496 ( V_503 , V_504 , * V_516 , & V_95 ) ;
if ( V_534 == V_514 ) {
V_40 = V_95 . V_40 ;
if ( ! F_323 ( V_40 ) ) {
V_145 = F_112 ( V_40 ) ;
if ( ! F_317 ( V_40 , V_338 ,
V_145 , V_7 . V_163 , V_7 . V_164 ) ) {
V_7 . V_500 -= V_338 ;
V_7 . V_530 += V_338 ;
}
F_327 ( V_40 ) ;
}
F_328 ( V_40 ) ;
}
F_54 ( V_521 ) ;
return 0 ;
}
if ( F_502 ( V_516 ) )
return 0 ;
V_65:
V_520 = F_503 ( V_503 -> V_522 , V_516 , V_504 , & V_521 ) ;
for (; V_504 != V_517 ; V_504 += V_249 ) {
T_12 V_505 = * ( V_520 ++ ) ;
T_6 V_288 ;
if ( ! V_7 . V_500 )
break;
switch ( F_492 ( V_503 , V_504 , V_505 , & V_95 ) ) {
case V_514 :
V_40 = V_95 . V_40 ;
if ( F_323 ( V_40 ) )
goto V_345;
V_145 = F_112 ( V_40 ) ;
if ( ! F_317 ( V_40 , 1 , V_145 ,
V_7 . V_163 , V_7 . V_164 ) ) {
V_7 . V_500 -- ;
V_7 . V_530 ++ ;
}
F_327 ( V_40 ) ;
V_345:
F_328 ( V_40 ) ;
break;
case V_515 :
V_288 = V_95 . V_288 ;
if ( ! F_349 ( V_288 , V_7 . V_163 , V_7 . V_164 ) ) {
V_7 . V_500 -- ;
V_7 . V_531 ++ ;
}
break;
default:
break;
}
}
F_504 ( V_520 - 1 , V_521 ) ;
F_370 () ;
if ( V_504 != V_517 ) {
V_92 = F_475 ( 1 ) ;
if ( ! V_92 )
goto V_65;
}
return V_92 ;
}
static void F_520 ( struct V_110 * V_111 )
{
struct V_502 * V_503 ;
F_372 () ;
V_65:
if ( F_88 ( ! F_521 ( & V_111 -> V_523 ) ) ) {
F_511 () ;
F_370 () ;
goto V_65;
}
for ( V_503 = V_111 -> V_524 ; V_503 ; V_503 = V_503 -> V_525 ) {
int V_92 ;
struct V_518 V_535 = {
. V_527 = F_519 ,
. V_111 = V_111 ,
. V_237 = V_503 ,
} ;
if ( F_507 ( V_503 ) )
continue;
V_92 = F_508 ( V_503 -> V_528 , V_503 -> V_529 ,
& V_535 ) ;
if ( V_92 )
break;
}
F_509 ( & V_111 -> V_523 ) ;
}
static void F_522 ( struct V_10 * V_12 ,
struct V_532 * V_533 )
{
struct V_108 * V_49 = F_515 ( V_533 ) ;
struct V_110 * V_111 = F_516 ( V_49 ) ;
if ( V_111 ) {
if ( V_7 . V_164 )
F_520 ( V_111 ) ;
F_517 ( V_111 ) ;
}
if ( V_7 . V_164 )
F_513 () ;
}
static int F_514 ( struct V_10 * V_12 ,
struct V_532 * V_533 )
{
return 0 ;
}
static void F_518 ( struct V_10 * V_12 ,
struct V_532 * V_533 )
{
}
static void F_522 ( struct V_10 * V_12 ,
struct V_532 * V_533 )
{
}
static void F_523 ( struct V_10 * V_536 )
{
if ( F_524 ( V_536 -> V_16 ) )
F_11 ( V_536 ) -> V_130 = true ;
}
static int T_5 F_525 ( char * V_11 )
{
if ( ! strcmp ( V_11 , L_37 ) )
V_537 = 1 ;
else if ( ! strcmp ( V_11 , L_38 ) )
V_537 = 0 ;
return 1 ;
}
static void T_5 F_526 ( void )
{
F_28 ( F_527 ( & V_18 , V_538 ) ) ;
}
static void T_5 F_528 ( void )
{
if ( ! F_103 () && V_537 ) {
V_157 = 1 ;
F_526 () ;
}
}
static void T_5 F_528 ( void )
{
}
static int T_5 F_529 ( void )
{
F_530 ( F_228 , 0 ) ;
F_528 () ;
F_464 () ;
F_215 () ;
return 0 ;
}
