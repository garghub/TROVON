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
F_2 ( V_5 , & V_2 -> V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_5 , & V_2 -> V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( F_4 ( V_3 , & V_2 -> V_4 ) )
F_2 ( V_6 , & V_2 -> V_4 ) ;
}
static bool F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_6 ,
& V_2 -> V_4 ) ;
}
static bool F_11 ( void )
{
return F_4 ( V_7 ,
& V_8 . V_9 -> V_10 ) ;
}
static bool F_12 ( void )
{
return F_4 ( V_11 ,
& V_8 . V_9 -> V_10 ) ;
}
static inline
struct V_1 * F_13 ( struct V_12 * V_13 )
{
return F_14 ( V_13 , struct V_1 , V_14 ) ;
}
static inline bool F_15 ( struct V_1 * V_2 )
{
return ( V_2 == V_15 ) ;
}
void F_16 ( struct V_16 * V_17 )
{
if ( V_18 ) {
struct V_1 * V_2 ;
struct V_19 * V_19 ;
F_17 ( ! V_17 -> V_20 -> V_21 ) ;
if ( V_17 -> V_22 ) {
F_17 ( F_15 ( V_17 -> V_22 -> V_2 ) ) ;
F_18 ( V_17 -> V_22 -> V_2 ) ;
return;
}
F_19 () ;
V_2 = F_20 ( V_23 ) ;
V_19 = V_17 -> V_20 -> V_21 ( V_2 ) ;
if ( ! F_15 ( V_2 ) && F_21 ( V_19 ) ) {
F_18 ( V_2 ) ;
V_17 -> V_22 = V_19 ;
}
F_22 () ;
}
}
void F_23 ( struct V_16 * V_17 )
{
if ( V_18 && V_17 -> V_22 ) {
struct V_1 * V_2 ;
F_24 ( ! V_17 -> V_22 -> V_2 ) ;
V_2 = V_17 -> V_22 -> V_2 ;
F_25 ( V_2 ) ;
}
}
struct V_19 * F_26 ( struct V_1 * V_2 )
{
if ( ! V_2 || F_15 ( V_2 ) )
return NULL ;
return & V_2 -> V_24 . V_19 ;
}
static void F_27 ( struct V_1 * V_2 )
{
if ( ! F_28 ( & V_2 -> V_24 . V_19 ) )
return;
F_29 ( & V_25 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
}
static void F_30 ( struct V_1 * V_2 )
{
if ( F_3 ( V_2 ) ) {
F_29 ( & V_26 ) ;
F_31 ( & V_27 , V_2 -> V_28 ) ;
}
F_24 ( F_32 ( & V_2 -> V_29 , V_30 ) != 0 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
}
static void F_33 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static struct V_31 *
F_34 ( struct V_1 * V_2 , int V_32 , int V_33 )
{
return & V_2 -> V_34 . V_35 [ V_32 ] -> V_36 [ V_33 ] ;
}
struct V_12 * F_35 ( struct V_1 * V_2 )
{
return & V_2 -> V_14 ;
}
static struct V_31 *
F_36 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
int V_32 = F_37 ( V_37 ) ;
int V_33 = F_38 ( V_37 ) ;
return F_34 ( V_2 , V_32 , V_33 ) ;
}
static struct V_38 *
F_39 ( int V_32 , int V_33 )
{
return & V_39 . V_40 [ V_32 ] -> V_41 [ V_33 ] ;
}
static struct V_38 *
F_40 ( struct V_37 * V_37 )
{
int V_32 = F_37 ( V_37 ) ;
int V_33 = F_38 ( V_37 ) ;
return & V_39 . V_40 [ V_32 ] -> V_41 [ V_33 ] ;
}
static void
F_41 ( struct V_1 * V_2 ,
struct V_31 * V_42 ,
struct V_38 * V_43 ,
unsigned long long V_44 )
{
struct V_45 * * V_46 = & V_43 -> V_47 . V_45 ;
struct V_45 * V_48 = NULL ;
struct V_31 * V_49 ;
if ( V_42 -> V_50 )
return;
V_42 -> V_51 = V_44 ;
if ( ! V_42 -> V_51 )
return;
while ( * V_46 ) {
V_48 = * V_46 ;
V_49 = F_42 ( V_48 , struct V_31 ,
V_52 ) ;
if ( V_42 -> V_51 < V_49 -> V_51 )
V_46 = & ( * V_46 ) -> V_53 ;
else if ( V_42 -> V_51 >= V_49 -> V_51 )
V_46 = & ( * V_46 ) -> V_54 ;
}
F_43 ( & V_42 -> V_52 , V_48 , V_46 ) ;
F_44 ( & V_42 -> V_52 , & V_43 -> V_47 ) ;
V_42 -> V_50 = true ;
}
static void
F_45 ( struct V_1 * V_2 ,
struct V_31 * V_42 ,
struct V_38 * V_43 )
{
if ( ! V_42 -> V_50 )
return;
F_46 ( & V_42 -> V_52 , & V_43 -> V_47 ) ;
V_42 -> V_50 = false ;
}
static void
F_47 ( struct V_1 * V_2 ,
struct V_31 * V_42 ,
struct V_38 * V_43 )
{
F_48 ( & V_43 -> V_55 ) ;
F_45 ( V_2 , V_42 , V_43 ) ;
F_49 ( & V_43 -> V_55 ) ;
}
static void F_50 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
unsigned long long V_56 ;
struct V_31 * V_42 ;
struct V_38 * V_43 ;
int V_32 = F_37 ( V_37 ) ;
int V_33 = F_38 ( V_37 ) ;
V_43 = F_40 ( V_37 ) ;
for (; V_2 ; V_2 = F_51 ( V_2 ) ) {
V_42 = F_34 ( V_2 , V_32 , V_33 ) ;
V_56 = F_52 ( & V_2 -> V_57 ) ;
if ( V_56 || V_42 -> V_50 ) {
F_48 ( & V_43 -> V_55 ) ;
if ( V_42 -> V_50 )
F_45 ( V_2 , V_42 , V_43 ) ;
F_41 ( V_2 , V_42 , V_43 , V_56 ) ;
F_49 ( & V_43 -> V_55 ) ;
}
}
}
static void F_53 ( struct V_1 * V_2 )
{
int V_58 , V_59 ;
struct V_31 * V_42 ;
struct V_38 * V_43 ;
F_54 (node) {
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_42 = F_34 ( V_2 , V_58 , V_59 ) ;
V_43 = F_39 ( V_58 , V_59 ) ;
F_47 ( V_2 , V_42 , V_43 ) ;
}
}
}
static struct V_31 *
F_55 ( struct V_38 * V_43 )
{
struct V_45 * V_61 = NULL ;
struct V_31 * V_42 ;
V_62:
V_42 = NULL ;
V_61 = F_56 ( & V_43 -> V_47 ) ;
if ( ! V_61 )
goto V_63;
V_42 = F_42 ( V_61 , struct V_31 , V_52 ) ;
F_45 ( V_42 -> V_2 , V_42 , V_43 ) ;
if ( ! F_52 ( & V_42 -> V_2 -> V_57 ) ||
! F_57 ( & V_42 -> V_2 -> V_14 ) )
goto V_62;
V_63:
return V_42 ;
}
static struct V_31 *
F_58 ( struct V_38 * V_43 )
{
struct V_31 * V_42 ;
F_48 ( & V_43 -> V_55 ) ;
V_42 = F_55 ( V_43 ) ;
F_49 ( & V_43 -> V_55 ) ;
return V_42 ;
}
static long F_59 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
long V_66 = 0 ;
int V_67 ;
F_60 () ;
F_61 (cpu)
V_66 += F_62 ( V_2 -> V_68 -> V_69 [ V_65 ] , V_67 ) ;
#ifdef F_63
F_48 ( & V_2 -> V_70 ) ;
V_66 += V_2 -> V_71 . V_69 [ V_65 ] ;
F_49 ( & V_2 -> V_70 ) ;
#endif
F_64 () ;
return V_66 ;
}
static void F_65 ( struct V_1 * V_2 ,
bool V_72 )
{
int V_66 = ( V_72 ) ? 1 : - 1 ;
F_66 ( V_2 -> V_68 -> V_69 [ V_73 ] , V_66 ) ;
}
static unsigned long F_67 ( struct V_1 * V_2 ,
enum V_74 V_65 )
{
unsigned long V_66 = 0 ;
int V_67 ;
F_61 (cpu)
V_66 += F_62 ( V_2 -> V_68 -> V_75 [ V_65 ] , V_67 ) ;
#ifdef F_63
F_48 ( & V_2 -> V_70 ) ;
V_66 += V_2 -> V_71 . V_75 [ V_65 ] ;
F_49 ( & V_2 -> V_70 ) ;
#endif
return V_66 ;
}
static void F_68 ( struct V_1 * V_2 ,
bool V_76 , int V_77 )
{
F_69 () ;
if ( V_76 )
F_70 ( V_2 -> V_68 -> V_69 [ V_78 ] ,
V_77 ) ;
else
F_70 ( V_2 -> V_68 -> V_69 [ V_79 ] ,
V_77 ) ;
if ( V_77 > 0 )
F_71 ( V_2 -> V_68 -> V_75 [ V_80 ] ) ;
else {
F_71 ( V_2 -> V_68 -> V_75 [ V_81 ] ) ;
V_77 = - V_77 ;
}
F_70 ( V_2 -> V_68 -> V_82 , V_77 ) ;
F_72 () ;
}
unsigned long
F_73 ( struct V_83 * V_83 , enum V_84 V_85 )
{
struct V_31 * V_42 ;
V_42 = F_14 ( V_83 , struct V_31 , V_83 ) ;
return V_42 -> V_86 [ V_85 ] ;
}
static unsigned long
F_74 ( struct V_1 * V_2 , int V_32 , int V_33 ,
unsigned int V_87 )
{
struct V_31 * V_42 ;
enum V_84 V_85 ;
unsigned long V_88 = 0 ;
V_42 = F_34 ( V_2 , V_32 , V_33 ) ;
F_75 (lru) {
if ( F_76 ( V_85 ) & V_87 )
V_88 += V_42 -> V_86 [ V_85 ] ;
}
return V_88 ;
}
static unsigned long
F_77 ( struct V_1 * V_2 ,
int V_32 , unsigned int V_87 )
{
T_1 V_89 = 0 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ )
V_89 += F_74 ( V_2 ,
V_32 , V_33 , V_87 ) ;
return V_89 ;
}
static unsigned long F_78 ( struct V_1 * V_2 ,
unsigned int V_87 )
{
int V_32 ;
T_1 V_89 = 0 ;
F_79 (nid, N_MEMORY)
V_89 += F_77 ( V_2 , V_32 , V_87 ) ;
return V_89 ;
}
static bool F_80 ( struct V_1 * V_2 ,
enum V_90 V_91 )
{
unsigned long V_66 , V_92 ;
V_66 = F_81 ( V_2 -> V_68 -> V_82 ) ;
V_92 = F_81 ( V_2 -> V_68 -> V_93 [ V_91 ] ) ;
if ( ( long ) V_92 - ( long ) V_66 < 0 ) {
switch ( V_91 ) {
case V_94 :
V_92 = V_66 + V_95 ;
break;
case V_96 :
V_92 = V_66 + V_97 ;
break;
case V_98 :
V_92 = V_66 + V_99 ;
break;
default:
break;
}
F_82 ( V_2 -> V_68 -> V_93 [ V_91 ] , V_92 ) ;
return true ;
}
return false ;
}
static void F_83 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
F_69 () ;
if ( F_84 ( F_80 ( V_2 ,
V_94 ) ) ) {
bool V_100 ;
bool T_2 V_101 ;
V_100 = F_80 ( V_2 ,
V_96 ) ;
#if V_102 > 1
T_2 = F_80 ( V_2 ,
V_98 ) ;
#endif
F_72 () ;
F_85 ( V_2 ) ;
if ( F_84 ( V_100 ) )
F_50 ( V_2 , V_37 ) ;
#if V_102 > 1
if ( F_84 ( T_2 ) )
F_86 ( & V_2 -> V_103 ) ;
#endif
} else
F_72 () ;
}
struct V_1 * F_87 ( struct V_104 * V_105 )
{
return F_13 (
V_12 ( V_105 , V_106 ) ) ;
}
struct V_1 * F_20 ( struct V_107 * V_46 )
{
if ( F_84 ( ! V_46 ) )
return NULL ;
return F_13 ( F_88 ( V_46 , V_106 ) ) ;
}
struct V_1 * F_89 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = NULL ;
if ( ! V_109 )
return NULL ;
F_19 () ;
do {
V_2 = F_20 ( F_90 ( V_109 -> V_110 ) ) ;
if ( F_84 ( ! V_2 ) )
break;
} while ( ! F_57 ( & V_2 -> V_14 ) );
F_22 () ;
return V_2 ;
}
struct V_1 * F_91 ( struct V_1 * V_111 ,
struct V_1 * V_112 ,
struct V_113 * V_114 )
{
struct V_1 * V_2 = NULL ;
int V_115 = 0 ;
if ( F_92 () )
return NULL ;
if ( ! V_111 )
V_111 = V_15 ;
if ( V_112 && ! V_114 )
V_115 = F_93 ( & V_112 -> V_14 ) ;
if ( V_112 && V_112 != V_111 )
F_94 ( & V_112 -> V_14 ) ;
if ( ! V_111 -> V_116 && V_111 != V_15 ) {
if ( V_112 )
return NULL ;
return V_111 ;
}
while ( ! V_2 ) {
struct V_117 * V_118 ( V_119 ) ;
struct V_12 * V_14 ;
if ( V_114 ) {
int V_32 = F_95 ( V_114 -> V_59 ) ;
int V_33 = F_96 ( V_114 -> V_59 ) ;
struct V_31 * V_42 ;
V_42 = F_34 ( V_111 , V_32 , V_33 ) ;
V_119 = & V_42 -> V_120 [ V_114 -> V_121 ] ;
if ( V_112 && V_114 -> V_122 != V_119 -> V_122 )
return NULL ;
V_115 = V_119 -> V_123 ;
}
F_19 () ;
V_14 = F_97 ( & V_124 , V_115 + 1 , & V_111 -> V_14 , & V_115 ) ;
if ( V_14 ) {
if ( V_14 == & V_111 -> V_14 || F_57 ( V_14 ) )
V_2 = F_13 ( V_14 ) ;
} else
V_115 = 0 ;
F_22 () ;
if ( V_114 ) {
V_119 -> V_123 = V_115 ;
if ( ! V_14 )
V_119 -> V_122 ++ ;
else if ( ! V_112 && V_2 )
V_114 -> V_122 = V_119 -> V_122 ;
}
if ( V_112 && ! V_14 )
return NULL ;
}
return V_2 ;
}
void F_98 ( struct V_1 * V_111 ,
struct V_1 * V_112 )
{
if ( ! V_111 )
V_111 = V_15 ;
if ( V_112 && V_112 != V_111 )
F_94 ( & V_112 -> V_14 ) ;
}
void F_99 ( struct V_108 * V_109 , enum V_125 V_65 )
{
struct V_1 * V_2 ;
F_19 () ;
V_2 = F_20 ( F_90 ( V_109 -> V_110 ) ) ;
if ( F_84 ( ! V_2 ) )
goto V_126;
switch ( V_65 ) {
case V_127 :
F_100 ( V_2 -> V_68 -> V_75 [ V_128 ] ) ;
break;
case V_129 :
F_100 ( V_2 -> V_68 -> V_75 [ V_130 ] ) ;
break;
default:
F_101 () ;
}
V_126:
F_22 () ;
}
struct V_83 * F_102 ( struct V_59 * V_59 ,
struct V_1 * V_2 )
{
struct V_31 * V_42 ;
struct V_83 * V_83 ;
if ( F_92 () ) {
V_83 = & V_59 -> V_83 ;
goto V_126;
}
V_42 = F_34 ( V_2 , F_95 ( V_59 ) , F_96 ( V_59 ) ) ;
V_83 = & V_42 -> V_83 ;
V_126:
if ( F_84 ( V_83 -> V_59 != V_59 ) )
V_83 -> V_59 = V_59 ;
return V_83 ;
}
struct V_83 * F_103 ( struct V_37 * V_37 , struct V_59 * V_59 )
{
struct V_31 * V_42 ;
struct V_1 * V_2 ;
struct V_131 * V_132 ;
struct V_83 * V_83 ;
if ( F_92 () ) {
V_83 = & V_59 -> V_83 ;
goto V_126;
}
V_132 = F_104 ( V_37 ) ;
V_2 = V_132 -> V_1 ;
if ( ! F_105 ( V_37 ) && ! F_106 ( V_132 ) && V_2 != V_15 )
V_132 -> V_1 = V_2 = V_15 ;
V_42 = F_36 ( V_2 , V_37 ) ;
V_83 = & V_42 -> V_83 ;
V_126:
if ( F_84 ( V_83 -> V_59 != V_59 ) )
V_83 -> V_59 = V_59 ;
return V_83 ;
}
void F_107 ( struct V_83 * V_83 , enum V_84 V_85 ,
int V_77 )
{
struct V_31 * V_42 ;
unsigned long * V_86 ;
if ( F_92 () )
return;
V_42 = F_14 ( V_83 , struct V_31 , V_83 ) ;
V_86 = V_42 -> V_86 + V_85 ;
* V_86 += V_77 ;
F_108 ( ( long ) ( * V_86 ) < 0 ) ;
}
bool F_109 ( const struct V_1 * V_133 ,
struct V_1 * V_2 )
{
if ( V_133 == V_2 )
return true ;
if ( ! V_133 -> V_116 || ! V_2 )
return false ;
return F_110 ( & V_2 -> V_14 , & V_133 -> V_14 ) ;
}
static bool F_111 ( const struct V_1 * V_133 ,
struct V_1 * V_2 )
{
bool V_88 ;
F_19 () ;
V_88 = F_109 ( V_133 , V_2 ) ;
F_22 () ;
return V_88 ;
}
int F_112 ( struct V_107 * V_134 , const struct V_1 * V_2 )
{
int V_88 ;
struct V_1 * V_135 = NULL ;
struct V_107 * V_46 ;
V_46 = F_113 ( V_134 ) ;
if ( V_46 ) {
V_135 = F_89 ( V_46 -> V_109 ) ;
F_114 ( V_46 ) ;
} else {
F_115 ( V_134 ) ;
V_135 = F_20 ( V_134 ) ;
if ( V_135 )
F_116 ( & V_135 -> V_14 ) ;
F_114 ( V_134 ) ;
}
if ( ! V_135 )
return 0 ;
V_88 = F_111 ( V_2 , V_135 ) ;
F_94 ( & V_135 -> V_14 ) ;
return V_88 ;
}
int F_117 ( struct V_83 * V_83 )
{
unsigned long V_136 ;
unsigned long V_137 ;
unsigned long V_138 ;
unsigned long V_139 ;
V_137 = F_73 ( V_83 , V_140 ) ;
V_138 = F_73 ( V_83 , V_141 ) ;
V_139 = ( V_137 + V_138 ) >> ( 30 - V_142 ) ;
if ( V_139 )
V_136 = F_118 ( 10 * V_139 ) ;
else
V_136 = 1 ;
return V_137 * V_136 < V_138 ;
}
int F_119 ( struct V_83 * V_83 )
{
unsigned long V_138 ;
unsigned long V_137 ;
V_137 = F_73 ( V_83 , V_143 ) ;
V_138 = F_73 ( V_83 , V_144 ) ;
return ( V_138 > V_137 ) ;
}
static unsigned long F_120 ( struct V_1 * V_2 )
{
unsigned long long V_145 ;
V_145 = F_121 ( & V_2 -> V_57 ) ;
if ( V_146 )
V_145 = F_122 ( V_145 , F_121 ( & V_2 -> V_147 ) ) ;
return V_145 >> V_142 ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_104 * V_148 = V_2 -> V_14 . V_104 ;
if ( V_148 -> V_48 == NULL )
return V_149 ;
return V_2 -> V_150 ;
}
static void F_124 ( struct V_1 * V_2 )
{
F_86 ( & V_151 ) ;
F_86 ( & V_2 -> V_152 ) ;
F_125 () ;
}
static void F_126 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_127 ( & V_151 ) ;
F_127 ( & V_2 -> V_152 ) ;
}
}
static bool F_128 ( struct V_1 * V_2 )
{
F_108 ( ! F_129 () ) ;
return F_130 ( & V_2 -> V_152 ) > 0 ;
}
static bool F_131 ( struct V_1 * V_2 )
{
struct V_1 * V_153 ;
struct V_1 * V_9 ;
bool V_88 = false ;
F_48 ( & V_8 . V_55 ) ;
V_153 = V_8 . V_153 ;
V_9 = V_8 . V_9 ;
if ( ! V_153 )
goto V_154;
V_88 = F_111 ( V_2 , V_153 )
|| F_111 ( V_2 , V_9 ) ;
V_154:
F_49 ( & V_8 . V_55 ) ;
return V_88 ;
}
static bool F_132 ( struct V_1 * V_2 )
{
if ( V_8 . V_155 && V_23 != V_8 . V_155 ) {
if ( F_131 ( V_2 ) ) {
F_133 ( V_156 ) ;
F_134 ( & V_8 . V_157 , & V_156 , V_158 ) ;
if ( V_8 . V_155 )
F_135 () ;
F_136 ( & V_8 . V_157 , & V_156 ) ;
return true ;
}
}
return false ;
}
static void F_137 ( struct V_1 * V_2 ,
unsigned long * V_159 )
{
F_138 ( & V_2 -> V_160 , * V_159 ) ;
}
static void F_139 ( struct V_1 * V_2 ,
unsigned long * V_159 )
{
F_140 ( & V_2 -> V_160 , * V_159 ) ;
}
void F_141 ( struct V_1 * V_2 , struct V_107 * V_46 )
{
struct V_104 * V_161 ;
struct V_104 * V_162 ;
static char V_163 [ V_164 ] ;
int V_88 ;
if ( ! V_2 || ! V_46 )
return;
F_19 () ;
V_162 = V_2 -> V_14 . V_104 ;
V_161 = F_142 ( V_46 , V_106 ) ;
V_88 = F_143 ( V_161 , V_163 , V_164 ) ;
if ( V_88 < 0 ) {
F_22 () ;
goto V_63;
}
F_22 () ;
F_144 ( V_165 L_1 , V_163 ) ;
F_19 () ;
V_88 = F_143 ( V_162 , V_163 , V_164 ) ;
if ( V_88 < 0 ) {
F_22 () ;
goto V_63;
}
F_22 () ;
F_144 ( V_166 L_2 , V_163 ) ;
V_63:
F_144 ( V_165 L_3 ,
F_32 ( & V_2 -> V_57 , V_30 ) >> 10 ,
F_32 ( & V_2 -> V_57 , V_167 ) >> 10 ,
F_32 ( & V_2 -> V_57 , V_168 ) ) ;
F_144 ( V_165 L_4
L_5 ,
F_32 ( & V_2 -> V_147 , V_30 ) >> 10 ,
F_32 ( & V_2 -> V_147 , V_167 ) >> 10 ,
F_32 ( & V_2 -> V_147 , V_168 ) ) ;
F_144 ( V_165 L_6 ,
F_32 ( & V_2 -> V_29 , V_30 ) >> 10 ,
F_32 ( & V_2 -> V_29 , V_167 ) >> 10 ,
F_32 ( & V_2 -> V_29 , V_168 ) ) ;
}
static int F_145 ( struct V_1 * V_2 )
{
int V_169 = 0 ;
struct V_1 * V_119 ;
F_146 (iter, memcg)
V_169 ++ ;
return V_169 ;
}
static T_1 F_147 ( struct V_1 * V_2 )
{
T_1 V_170 ;
V_170 = F_32 ( & V_2 -> V_57 , V_167 ) ;
if ( F_123 ( V_2 ) ) {
T_1 V_147 ;
V_170 += V_171 << V_142 ;
V_147 = F_32 ( & V_2 -> V_147 , V_167 ) ;
V_170 = F_122 ( V_170 , V_147 ) ;
}
return V_170 ;
}
static void F_148 ( struct V_1 * V_2 , T_3 V_172 ,
int V_173 )
{
struct V_1 * V_119 ;
unsigned long V_174 = 0 ;
unsigned long V_175 ;
unsigned int V_176 = 0 ;
struct V_107 * V_177 = NULL ;
if ( F_149 ( V_23 ) ) {
F_150 ( V_178 ) ;
return;
}
F_151 ( V_179 , V_172 , V_173 , NULL ) ;
V_175 = F_147 ( V_2 ) >> V_142 ? : 1 ;
F_146 (iter, memcg) {
struct V_104 * V_104 = V_119 -> V_14 . V_104 ;
struct V_180 V_181 ;
struct V_107 * V_134 ;
F_152 ( V_104 , & V_181 ) ;
while ( ( V_134 = F_153 ( V_104 , & V_181 ) ) ) {
switch ( F_154 ( V_134 , V_175 , NULL ,
false ) ) {
case V_182 :
if ( V_177 )
F_155 ( V_177 ) ;
V_177 = V_134 ;
V_174 = V_183 ;
F_156 ( V_177 ) ;
case V_184 :
continue;
case V_185 :
F_157 ( V_104 , & V_181 ) ;
F_98 ( V_2 , V_119 ) ;
if ( V_177 )
F_155 ( V_177 ) ;
return;
case V_186 :
break;
} ;
V_176 = F_158 ( V_134 , V_2 , NULL , V_175 ) ;
if ( V_176 > V_174 ) {
if ( V_177 )
F_155 ( V_177 ) ;
V_177 = V_134 ;
V_174 = V_176 ;
F_156 ( V_177 ) ;
}
}
F_157 ( V_104 , & V_181 ) ;
}
if ( ! V_177 )
return;
V_176 = V_174 * 1000 / V_175 ;
F_159 ( V_177 , V_172 , V_173 , V_176 , V_175 , V_2 ,
NULL , L_7 ) ;
}
static unsigned long F_160 ( struct V_1 * V_2 ,
T_3 V_172 ,
unsigned long V_159 )
{
unsigned long V_89 = 0 ;
bool V_187 = false ;
int V_188 ;
if ( V_159 & V_189 )
V_187 = true ;
if ( ! ( V_159 & V_190 ) && V_2 -> V_191 )
V_187 = true ;
for ( V_188 = 0 ; V_188 < V_192 ; V_188 ++ ) {
if ( V_188 )
F_161 ( V_2 ) ;
V_89 += F_162 ( V_2 , V_172 , V_187 ) ;
if ( V_89 && ( V_159 & V_190 ) )
break;
if ( F_120 ( V_2 ) )
break;
if ( V_188 && ! V_89 )
break;
}
return V_89 ;
}
static bool F_163 ( struct V_1 * V_2 ,
int V_32 , bool V_187 )
{
if ( F_77 ( V_2 , V_32 , V_193 ) )
return true ;
if ( V_187 || ! V_171 )
return false ;
if ( F_77 ( V_2 , V_32 , V_194 ) )
return true ;
return false ;
}
static void F_164 ( struct V_1 * V_2 )
{
int V_32 ;
if ( ! F_130 ( & V_2 -> V_103 ) )
return;
if ( F_165 ( & V_2 -> V_195 ) > 1 )
return;
V_2 -> V_196 = V_197 [ V_198 ] ;
F_166 (nid, node_states[N_MEMORY]) {
if ( ! F_163 ( V_2 , V_32 , false ) )
F_167 ( V_32 , V_2 -> V_196 ) ;
}
F_168 ( & V_2 -> V_103 , 0 ) ;
F_168 ( & V_2 -> V_195 , 0 ) ;
}
int F_169 ( struct V_1 * V_2 )
{
int V_58 ;
F_164 ( V_2 ) ;
V_58 = V_2 -> V_199 ;
V_58 = F_170 ( V_58 , V_2 -> V_196 ) ;
if ( V_58 == V_102 )
V_58 = F_171 ( V_2 -> V_196 ) ;
if ( F_84 ( V_58 == V_102 ) )
V_58 = F_172 () ;
V_2 -> V_199 = V_58 ;
return V_58 ;
}
static bool F_173 ( struct V_1 * V_2 , bool V_187 )
{
int V_32 ;
if ( ! F_174 ( V_2 -> V_196 ) ) {
for ( V_32 = F_171 ( V_2 -> V_196 ) ;
V_32 < V_102 ;
V_32 = F_170 ( V_32 , V_2 -> V_196 ) ) {
if ( F_163 ( V_2 , V_32 , V_187 ) )
return true ;
}
}
F_79 (nid, N_MEMORY) {
if ( F_175 ( V_32 , V_2 -> V_196 ) )
continue;
if ( F_163 ( V_2 , V_32 , V_187 ) )
return true ;
}
return false ;
}
int F_169 ( struct V_1 * V_2 )
{
return 0 ;
}
static bool F_173 ( struct V_1 * V_2 , bool V_187 )
{
return F_163 ( V_2 , 0 , V_187 ) ;
}
static int F_176 ( struct V_1 * V_133 ,
struct V_59 * V_59 ,
T_3 V_172 ,
unsigned long * V_200 )
{
struct V_1 * V_201 = NULL ;
int V_89 = 0 ;
int V_188 = 0 ;
unsigned long V_56 ;
unsigned long V_202 ;
struct V_113 V_114 = {
. V_59 = V_59 ,
. V_121 = 0 ,
} ;
V_56 = F_52 ( & V_133 -> V_57 ) >> V_142 ;
while ( 1 ) {
V_201 = F_91 ( V_133 , V_201 , & V_114 ) ;
if ( ! V_201 ) {
V_188 ++ ;
if ( V_188 >= 2 ) {
if ( ! V_89 )
break;
if ( V_89 >= ( V_56 >> 2 ) ||
( V_188 > V_192 ) )
break;
}
continue;
}
if ( ! F_173 ( V_201 , false ) )
continue;
V_89 += F_177 ( V_201 , V_172 , false ,
V_59 , & V_202 ) ;
* V_200 += V_202 ;
if ( ! F_52 ( & V_133 -> V_57 ) )
break;
}
F_98 ( V_133 , V_201 ) ;
return V_89 ;
}
static bool F_178 ( struct V_1 * V_2 )
{
struct V_1 * V_119 , * V_203 = NULL ;
F_146 (iter, memcg) {
if ( V_119 -> V_204 ) {
V_203 = V_119 ;
F_98 ( V_2 , V_119 ) ;
break;
} else
V_119 -> V_204 = true ;
}
if ( ! V_203 )
return true ;
F_146 (iter, memcg) {
if ( V_119 == V_203 ) {
F_98 ( V_2 , V_119 ) ;
break;
}
V_119 -> V_204 = false ;
}
return false ;
}
static int F_179 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_146 (iter, memcg)
V_119 -> V_204 = false ;
return 0 ;
}
static void F_180 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_146 (iter, memcg)
F_86 ( & V_119 -> V_205 ) ;
}
static void F_181 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_146 (iter, memcg)
F_182 ( & V_119 -> V_205 , - 1 , 0 ) ;
}
static int F_183 ( T_4 * V_156 ,
unsigned V_206 , int V_207 , void * V_208 )
{
struct V_1 * V_209 = (struct V_1 * ) V_208 ;
struct V_1 * V_210 ;
struct V_211 * V_211 ;
V_211 = F_14 ( V_156 , struct V_211 , V_156 ) ;
V_210 = V_211 -> V_2 ;
if ( ! F_111 ( V_210 , V_209 )
&& ! F_111 ( V_209 , V_210 ) )
return 0 ;
return F_184 ( V_156 , V_206 , V_207 , V_208 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
F_186 ( & V_212 , V_213 , 0 , V_2 ) ;
}
static void F_187 ( struct V_1 * V_2 )
{
if ( V_2 && F_130 ( & V_2 -> V_205 ) )
F_185 ( V_2 ) ;
}
static bool F_188 ( struct V_1 * V_2 , T_3 V_214 ,
int V_173 )
{
struct V_211 V_215 ;
bool V_216 , V_217 ;
V_215 . V_2 = V_2 ;
V_215 . V_156 . V_159 = 0 ;
V_215 . V_156 . V_218 = F_183 ;
V_215 . V_156 . V_219 = V_23 ;
F_189 ( & V_215 . V_156 . V_220 ) ;
V_217 = true ;
F_180 ( V_2 ) ;
F_48 ( & V_221 ) ;
V_216 = F_178 ( V_2 ) ;
F_134 ( & V_212 , & V_215 . V_156 , V_222 ) ;
if ( ! V_216 || V_2 -> V_223 )
V_217 = false ;
if ( V_216 )
F_190 ( V_2 ) ;
F_49 ( & V_221 ) ;
if ( V_217 ) {
F_136 ( & V_212 , & V_215 . V_156 ) ;
F_148 ( V_2 , V_214 , V_173 ) ;
} else {
F_135 () ;
F_136 ( & V_212 , & V_215 . V_156 ) ;
}
F_48 ( & V_221 ) ;
if ( V_216 )
F_179 ( V_2 ) ;
F_185 ( V_2 ) ;
F_49 ( & V_221 ) ;
F_181 ( V_2 ) ;
if ( F_191 ( V_178 ) || F_149 ( V_23 ) )
return false ;
F_192 ( 1 ) ;
return true ;
}
void F_193 ( struct V_37 * V_37 ,
bool * V_216 , unsigned long * V_159 )
{
struct V_1 * V_2 ;
struct V_131 * V_132 ;
V_132 = F_104 ( V_37 ) ;
V_224:
V_2 = V_132 -> V_1 ;
if ( F_84 ( ! V_2 || ! F_106 ( V_132 ) ) )
return;
if ( ! F_128 ( V_2 ) )
return;
F_137 ( V_2 , V_159 ) ;
if ( V_2 != V_132 -> V_1 || ! F_106 ( V_132 ) ) {
F_139 ( V_2 , V_159 ) ;
goto V_224;
}
* V_216 = true ;
}
void F_194 ( struct V_37 * V_37 , unsigned long * V_159 )
{
struct V_131 * V_132 = F_104 ( V_37 ) ;
F_139 ( V_132 -> V_1 , V_159 ) ;
}
void F_195 ( struct V_37 * V_37 ,
enum V_225 V_65 , int V_66 )
{
struct V_1 * V_2 ;
struct V_131 * V_132 = F_104 ( V_37 ) ;
unsigned long V_118 ( V_159 ) ;
if ( F_92 () )
return;
V_2 = V_132 -> V_1 ;
if ( F_84 ( ! V_2 || ! F_106 ( V_132 ) ) )
return;
switch ( V_65 ) {
case V_226 :
V_65 = V_227 ;
break;
default:
F_101 () ;
}
F_66 ( V_2 -> V_68 -> V_69 [ V_65 ] , V_66 ) ;
}
static bool F_196 ( struct V_1 * V_2 , unsigned int V_77 )
{
struct V_228 * V_229 ;
bool V_88 = true ;
if ( V_77 > V_230 )
return false ;
V_229 = & F_197 ( V_231 ) ;
if ( V_2 == V_229 -> V_232 && V_229 -> V_77 >= V_77 )
V_229 -> V_77 -= V_77 ;
else
V_88 = false ;
F_198 ( V_231 ) ;
return V_88 ;
}
static void F_199 ( struct V_228 * V_229 )
{
struct V_1 * V_233 = V_229 -> V_232 ;
if ( V_229 -> V_77 ) {
unsigned long V_234 = V_229 -> V_77 * V_235 ;
F_200 ( & V_233 -> V_57 , V_234 ) ;
if ( V_146 )
F_200 ( & V_233 -> V_147 , V_234 ) ;
V_229 -> V_77 = 0 ;
}
V_229 -> V_232 = NULL ;
}
static void F_201 ( struct V_236 * V_237 )
{
struct V_228 * V_229 = & F_202 ( V_231 ) ;
F_199 ( V_229 ) ;
F_7 ( V_238 , & V_229 -> V_159 ) ;
}
static void F_203 ( struct V_1 * V_2 , unsigned int V_77 )
{
struct V_228 * V_229 = & F_197 ( V_231 ) ;
if ( V_229 -> V_232 != V_2 ) {
F_199 ( V_229 ) ;
V_229 -> V_232 = V_2 ;
}
V_229 -> V_77 += V_77 ;
F_198 ( V_231 ) ;
}
static void F_204 ( struct V_1 * V_133 , bool V_207 )
{
int V_67 , V_239 ;
F_60 () ;
V_239 = F_205 () ;
F_61 (cpu) {
struct V_228 * V_229 = & F_62 ( V_231 , V_67 ) ;
struct V_1 * V_2 ;
V_2 = V_229 -> V_232 ;
if ( ! V_2 || ! V_229 -> V_77 )
continue;
if ( ! F_111 ( V_133 , V_2 ) )
continue;
if ( ! F_206 ( V_238 , & V_229 -> V_159 ) ) {
if ( V_67 == V_239 )
F_201 ( & V_229 -> V_240 ) ;
else
F_207 ( V_67 , & V_229 -> V_240 ) ;
}
}
F_208 () ;
if ( ! V_207 )
goto V_126;
F_61 (cpu) {
struct V_228 * V_229 = & F_62 ( V_231 , V_67 ) ;
if ( F_4 ( V_238 , & V_229 -> V_159 ) )
F_209 ( & V_229 -> V_240 ) ;
}
V_126:
F_64 () ;
}
static void F_161 ( struct V_1 * V_133 )
{
if ( ! F_210 ( & V_241 ) )
return;
F_204 ( V_133 , false ) ;
F_211 ( & V_241 ) ;
}
static void F_212 ( struct V_1 * V_133 )
{
F_213 ( & V_241 ) ;
F_204 ( V_133 , true ) ;
F_211 ( & V_241 ) ;
}
static void F_214 ( struct V_1 * V_2 , int V_67 )
{
int V_242 ;
F_48 ( & V_2 -> V_70 ) ;
for ( V_242 = 0 ; V_242 < V_243 ; V_242 ++ ) {
long V_244 = F_62 ( V_2 -> V_68 -> V_69 [ V_242 ] , V_67 ) ;
F_62 ( V_2 -> V_68 -> V_69 [ V_242 ] , V_67 ) = 0 ;
V_2 -> V_71 . V_69 [ V_242 ] += V_244 ;
}
for ( V_242 = 0 ; V_242 < V_245 ; V_242 ++ ) {
unsigned long V_244 = F_62 ( V_2 -> V_68 -> V_75 [ V_242 ] , V_67 ) ;
F_62 ( V_2 -> V_68 -> V_75 [ V_242 ] , V_67 ) = 0 ;
V_2 -> V_71 . V_75 [ V_242 ] += V_244 ;
}
F_49 ( & V_2 -> V_70 ) ;
}
static int T_5 F_215 ( struct V_246 * V_247 ,
unsigned long V_248 ,
void * V_249 )
{
int V_67 = ( unsigned long ) V_249 ;
struct V_228 * V_229 ;
struct V_1 * V_119 ;
if ( V_248 == V_250 )
return V_251 ;
if ( V_248 != V_252 && V_248 != V_253 )
return V_251 ;
F_216 (iter)
F_214 ( V_119 , V_67 ) ;
V_229 = & F_62 ( V_231 , V_67 ) ;
F_199 ( V_229 ) ;
return V_251 ;
}
static int F_217 ( struct V_1 * V_2 , T_3 V_172 ,
unsigned int V_77 , unsigned int V_254 ,
bool V_255 )
{
unsigned long V_256 = V_77 * V_235 ;
struct V_1 * V_257 ;
struct V_258 * V_259 ;
unsigned long V_159 = 0 ;
int V_88 ;
V_88 = F_218 ( & V_2 -> V_57 , V_256 , & V_259 ) ;
if ( F_219 ( ! V_88 ) ) {
if ( ! V_146 )
return V_260 ;
V_88 = F_218 ( & V_2 -> V_147 , V_256 , & V_259 ) ;
if ( F_219 ( ! V_88 ) )
return V_260 ;
F_200 ( & V_2 -> V_57 , V_256 ) ;
V_257 = F_220 ( V_259 , V_147 ) ;
V_159 |= V_189 ;
} else
V_257 = F_220 ( V_259 , V_57 ) ;
if ( V_77 > V_254 )
return V_261 ;
if ( ! ( V_172 & V_262 ) )
return V_263 ;
if ( V_172 & V_264 )
return V_265 ;
V_88 = F_160 ( V_257 , V_172 , V_159 ) ;
if ( F_120 ( V_257 ) >= V_77 )
return V_261 ;
if ( V_77 <= ( 1 << V_266 ) && V_88 )
return V_261 ;
if ( F_132 ( V_257 ) )
return V_261 ;
if ( ! V_255 )
return V_265 ;
if ( ! F_188 ( V_257 , V_172 , F_221 ( V_256 ) ) )
return V_267 ;
return V_261 ;
}
static int F_222 ( struct V_108 * V_109 ,
T_3 V_172 ,
unsigned int V_77 ,
struct V_1 * * V_268 ,
bool V_269 )
{
unsigned int V_270 = F_223 ( V_230 , V_77 ) ;
int V_271 = V_272 ;
struct V_1 * V_2 = NULL ;
int V_88 ;
if ( F_84 ( F_191 ( V_178 )
|| F_149 ( V_23 ) ) )
goto V_273;
if ( ! * V_268 && ! V_109 )
* V_268 = V_15 ;
V_224:
if ( * V_268 ) {
V_2 = * V_268 ;
if ( F_15 ( V_2 ) )
goto V_63;
if ( F_196 ( V_2 , V_77 ) )
goto V_63;
F_116 ( & V_2 -> V_14 ) ;
} else {
struct V_107 * V_46 ;
F_19 () ;
V_46 = F_90 ( V_109 -> V_110 ) ;
V_2 = F_20 ( V_46 ) ;
if ( ! V_2 )
V_2 = V_15 ;
if ( F_15 ( V_2 ) ) {
F_22 () ;
goto V_63;
}
if ( F_196 ( V_2 , V_77 ) ) {
F_22 () ;
goto V_63;
}
if ( ! F_57 ( & V_2 -> V_14 ) ) {
F_22 () ;
goto V_224;
}
F_22 () ;
}
do {
bool V_255 ;
if ( F_149 ( V_23 ) ) {
F_94 ( & V_2 -> V_14 ) ;
goto V_273;
}
V_255 = false ;
if ( V_269 && ! V_271 ) {
V_255 = true ;
V_271 = V_272 ;
}
V_88 = F_217 ( V_2 , V_172 , V_270 , V_77 ,
V_255 ) ;
switch ( V_88 ) {
case V_260 :
break;
case V_261 :
V_270 = V_77 ;
F_94 ( & V_2 -> V_14 ) ;
V_2 = NULL ;
goto V_224;
case V_263 :
F_94 ( & V_2 -> V_14 ) ;
goto V_274;
case V_265 :
if ( ! V_269 ) {
F_94 ( & V_2 -> V_14 ) ;
goto V_274;
}
V_271 -- ;
break;
case V_267 :
F_94 ( & V_2 -> V_14 ) ;
goto V_273;
}
} while ( V_88 != V_260 );
if ( V_270 > V_77 )
F_203 ( V_2 , V_270 - V_77 ) ;
F_94 ( & V_2 -> V_14 ) ;
V_63:
* V_268 = V_2 ;
return 0 ;
V_274:
* V_268 = NULL ;
return - V_275 ;
V_273:
* V_268 = V_15 ;
return - V_276 ;
}
static void F_224 ( struct V_1 * V_2 ,
unsigned int V_77 )
{
if ( ! F_15 ( V_2 ) ) {
unsigned long V_234 = V_77 * V_235 ;
F_200 ( & V_2 -> V_57 , V_234 ) ;
if ( V_146 )
F_200 ( & V_2 -> V_147 , V_234 ) ;
}
}
static void F_225 ( struct V_1 * V_2 ,
unsigned int V_77 )
{
unsigned long V_234 = V_77 * V_235 ;
if ( F_15 ( V_2 ) )
return;
F_226 ( & V_2 -> V_57 , V_2 -> V_57 . V_48 , V_234 ) ;
if ( V_146 )
F_226 ( & V_2 -> V_147 ,
V_2 -> V_147 . V_48 , V_234 ) ;
}
static struct V_1 * F_227 ( unsigned short V_115 )
{
struct V_12 * V_14 ;
if ( ! V_115 )
return NULL ;
V_14 = F_228 ( & V_124 , V_115 ) ;
if ( ! V_14 )
return NULL ;
return F_13 ( V_14 ) ;
}
struct V_1 * F_229 ( struct V_37 * V_37 )
{
struct V_1 * V_2 = NULL ;
struct V_131 * V_132 ;
unsigned short V_115 ;
T_6 V_277 ;
F_108 ( ! F_230 ( V_37 ) ) ;
V_132 = F_104 ( V_37 ) ;
F_231 ( V_132 ) ;
if ( F_106 ( V_132 ) ) {
V_2 = V_132 -> V_1 ;
if ( V_2 && ! F_57 ( & V_2 -> V_14 ) )
V_2 = NULL ;
} else if ( F_232 ( V_37 ) ) {
V_277 . V_66 = F_233 ( V_37 ) ;
V_115 = F_234 ( V_277 ) ;
F_19 () ;
V_2 = F_227 ( V_115 ) ;
if ( V_2 && ! F_57 ( & V_2 -> V_14 ) )
V_2 = NULL ;
F_22 () ;
}
F_235 ( V_132 ) ;
return V_2 ;
}
static void F_236 ( struct V_1 * V_2 ,
struct V_37 * V_37 ,
unsigned int V_77 ,
enum V_278 V_279 ,
bool V_280 )
{
struct V_131 * V_132 = F_104 ( V_37 ) ;
struct V_59 * V_118 ( V_59 ) ;
struct V_83 * V_83 ;
bool V_281 = false ;
bool V_76 ;
F_231 ( V_132 ) ;
F_108 ( F_106 ( V_132 ) ) ;
if ( V_280 ) {
V_59 = F_237 ( V_37 ) ;
F_238 ( & V_59 -> V_282 ) ;
if ( F_105 ( V_37 ) ) {
V_83 = F_102 ( V_59 , V_132 -> V_1 ) ;
F_239 ( V_37 ) ;
F_240 ( V_37 , V_83 , F_241 ( V_37 ) ) ;
V_281 = true ;
}
}
V_132 -> V_1 = V_2 ;
F_242 () ;
F_243 ( V_132 ) ;
if ( V_280 ) {
if ( V_281 ) {
V_83 = F_102 ( V_59 , V_132 -> V_1 ) ;
F_108 ( F_105 ( V_37 ) ) ;
F_244 ( V_37 ) ;
F_245 ( V_37 , V_83 , F_241 ( V_37 ) ) ;
}
F_246 ( & V_59 -> V_282 ) ;
}
if ( V_279 == V_283 )
V_76 = true ;
else
V_76 = false ;
F_68 ( V_2 , V_76 , V_77 ) ;
F_235 ( V_132 ) ;
F_83 ( V_2 , V_37 ) ;
}
static inline bool F_247 ( struct V_1 * V_2 )
{
return ! F_92 () && ! F_15 ( V_2 ) &&
( V_2 -> V_4 & V_284 ) ;
}
static struct V_285 * F_248 ( struct V_286 * V_46 )
{
struct V_285 * V_287 ;
F_108 ( V_46 -> V_288 ) ;
V_287 = V_46 -> V_289 ;
return V_287 -> V_290 -> V_291 [ F_249 ( V_46 -> V_2 ) ] ;
}
static int F_250 ( struct V_104 * V_105 , struct V_292 * V_293 ,
struct V_294 * V_295 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
struct V_286 * V_296 ;
if ( ! F_247 ( V_2 ) )
return - V_297 ;
F_251 ( V_295 ) ;
F_213 ( & V_2 -> V_298 ) ;
F_252 (params, &memcg->memcg_slab_caches, list)
F_253 ( F_248 ( V_296 ) , V_295 ) ;
F_211 ( & V_2 -> V_298 ) ;
return 0 ;
}
static int F_254 ( struct V_1 * V_2 , T_3 V_299 , T_1 V_300 )
{
struct V_258 * V_259 ;
struct V_1 * V_301 ;
int V_88 = 0 ;
bool V_302 ;
V_88 = F_218 ( & V_2 -> V_29 , V_300 , & V_259 ) ;
if ( V_88 )
return V_88 ;
V_302 = ( V_299 & V_303 ) && ! ( V_299 & V_264 ) ;
V_301 = V_2 ;
V_88 = F_222 ( NULL , V_299 , V_300 >> V_142 ,
& V_301 , V_302 ) ;
if ( V_88 == - V_276 ) {
F_255 ( & V_2 -> V_57 , V_300 , & V_259 ) ;
if ( V_146 )
F_255 ( & V_2 -> V_147 , V_300 ,
& V_259 ) ;
V_88 = 0 ;
} else if ( V_88 )
F_200 ( & V_2 -> V_29 , V_300 ) ;
return V_88 ;
}
static void F_256 ( struct V_1 * V_2 , T_1 V_300 )
{
F_200 ( & V_2 -> V_57 , V_300 ) ;
if ( V_146 )
F_200 ( & V_2 -> V_147 , V_300 ) ;
if ( F_200 ( & V_2 -> V_29 , V_300 ) )
return;
if ( F_9 ( V_2 ) )
F_25 ( V_2 ) ;
}
void F_257 ( struct V_1 * V_2 , struct V_285 * V_287 )
{
if ( ! V_2 )
return;
F_213 ( & V_2 -> V_298 ) ;
F_258 ( & V_287 -> V_290 -> V_304 , & V_2 -> V_305 ) ;
F_211 ( & V_2 -> V_298 ) ;
}
int F_249 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_28 : - 1 ;
}
int F_259 ( struct V_1 * V_2 )
{
int V_169 , V_88 ;
V_169 = F_260 ( & V_27 ,
0 , V_306 , V_307 ) ;
if ( V_169 < 0 )
return V_169 ;
F_5 ( V_2 ) ;
V_88 = F_261 ( V_169 + 1 ) ;
if ( V_88 ) {
F_31 ( & V_27 , V_169 ) ;
F_6 ( V_2 ) ;
return V_88 ;
}
V_2 -> V_28 = V_169 ;
F_189 ( & V_2 -> V_305 ) ;
F_262 ( & V_2 -> V_298 ) ;
return 0 ;
}
static T_7 F_263 ( int V_308 )
{
T_8 V_300 ;
if ( V_308 <= 0 )
return 0 ;
V_300 = 2 * V_308 ;
if ( V_300 < V_309 )
V_300 = V_309 ;
else if ( V_300 > V_306 )
V_300 = V_306 ;
return V_300 ;
}
void F_264 ( int V_169 )
{
if ( V_169 > V_310 )
V_310 = F_263 ( V_169 ) ;
}
int F_265 ( struct V_285 * V_13 , int V_308 )
{
struct V_286 * V_311 = V_13 -> V_290 ;
F_108 ( V_13 -> V_290 && ! V_13 -> V_290 -> V_288 ) ;
if ( V_308 > V_310 ) {
int V_242 ;
T_8 V_300 = F_263 ( V_308 ) ;
V_300 *= sizeof( void * ) ;
V_300 += sizeof( struct V_286 ) ;
V_13 -> V_290 = F_266 ( V_300 , V_307 ) ;
if ( ! V_13 -> V_290 ) {
V_13 -> V_290 = V_311 ;
return - V_275 ;
}
V_13 -> V_290 -> V_288 = true ;
for ( V_242 = 0 ; V_242 < V_310 ; V_242 ++ ) {
if ( ! V_311 -> V_291 [ V_242 ] )
continue;
V_13 -> V_290 -> V_291 [ V_242 ] =
V_311 -> V_291 [ V_242 ] ;
}
F_267 ( V_311 ) ;
}
return 0 ;
}
int F_268 ( struct V_1 * V_2 , struct V_285 * V_13 ,
struct V_285 * V_289 )
{
T_7 V_300 = sizeof( struct V_286 ) ;
if ( ! F_269 () )
return 0 ;
if ( ! V_2 )
V_300 += V_310 * sizeof( void * ) ;
V_13 -> V_290 = F_266 ( V_300 , V_307 ) ;
if ( ! V_13 -> V_290 )
return - V_275 ;
if ( V_2 ) {
V_13 -> V_290 -> V_2 = V_2 ;
V_13 -> V_290 -> V_289 = V_289 ;
} else
V_13 -> V_290 -> V_288 = true ;
return 0 ;
}
void F_270 ( struct V_285 * V_13 )
{
struct V_285 * V_111 ;
struct V_1 * V_2 ;
int V_115 ;
if ( ! V_13 -> V_290 )
return;
if ( V_13 -> V_290 -> V_288 )
goto V_126;
V_2 = V_13 -> V_290 -> V_2 ;
V_115 = F_249 ( V_2 ) ;
V_111 = V_13 -> V_290 -> V_289 ;
V_111 -> V_290 -> V_291 [ V_115 ] = NULL ;
F_25 ( V_2 ) ;
F_213 ( & V_2 -> V_298 ) ;
F_271 ( & V_13 -> V_290 -> V_304 ) ;
F_211 ( & V_2 -> V_298 ) ;
V_126:
F_267 ( V_13 -> V_290 ) ;
}
static inline void F_272 ( void )
{
F_108 ( ! V_23 -> V_109 ) ;
V_23 -> V_312 ++ ;
}
static inline void F_273 ( void )
{
F_108 ( ! V_23 -> V_109 ) ;
V_23 -> V_312 -- ;
}
static void F_274 ( struct V_236 * V_313 )
{
struct V_285 * V_287 ;
struct V_286 * V_46 ;
V_46 = F_14 ( V_313 , struct V_286 , V_314 ) ;
V_287 = F_248 ( V_46 ) ;
if ( F_130 ( & V_287 -> V_290 -> V_77 ) != 0 ) {
F_275 ( V_287 ) ;
if ( F_130 ( & V_287 -> V_290 -> V_77 ) == 0 )
return;
} else
F_276 ( V_287 ) ;
}
void F_277 ( struct V_285 * V_287 )
{
if ( ! V_287 -> V_290 -> V_315 )
return;
if ( F_278 ( & V_287 -> V_290 -> V_314 ) )
return;
F_279 ( & V_287 -> V_290 -> V_314 ) ;
}
static char * F_280 ( struct V_1 * V_2 , struct V_285 * V_13 )
{
char * V_316 ;
struct V_317 * V_317 ;
F_19 () ;
V_317 = F_90 ( V_2 -> V_14 . V_104 -> V_317 ) ;
F_22 () ;
F_17 ( V_317 == NULL ) ;
V_316 = F_281 ( V_307 , L_8 , V_13 -> V_316 ,
F_249 ( V_2 ) , V_317 -> V_318 . V_316 ) ;
return V_316 ;
}
static struct V_285 * F_282 ( struct V_1 * V_2 ,
struct V_285 * V_13 )
{
char * V_316 ;
struct V_285 * V_319 ;
V_316 = F_280 ( V_2 , V_13 ) ;
if ( ! V_316 )
return NULL ;
V_319 = F_283 ( V_2 , V_316 , V_13 -> V_320 , V_13 -> V_321 ,
( V_13 -> V_159 & ~ V_322 ) , V_13 -> V_323 , V_13 ) ;
if ( V_319 )
V_319 -> V_324 |= V_325 ;
F_267 ( V_316 ) ;
return V_319 ;
}
static struct V_285 * F_284 ( struct V_1 * V_2 ,
struct V_285 * V_287 )
{
struct V_285 * V_326 ;
int V_65 ;
F_17 ( ! F_247 ( V_2 ) ) ;
V_65 = F_249 ( V_2 ) ;
F_213 ( & V_327 ) ;
V_326 = V_287 -> V_290 -> V_291 [ V_65 ] ;
if ( V_326 )
goto V_126;
V_326 = F_282 ( V_2 , V_287 ) ;
if ( V_326 == NULL ) {
V_326 = V_287 ;
goto V_126;
}
F_18 ( V_2 ) ;
F_168 ( & V_326 -> V_290 -> V_77 , 0 ) ;
V_287 -> V_290 -> V_291 [ V_65 ] = V_326 ;
F_285 () ;
V_126:
F_211 ( & V_327 ) ;
return V_326 ;
}
void F_286 ( struct V_285 * V_13 )
{
struct V_285 * V_328 ;
int V_242 ;
if ( ! V_13 -> V_290 )
return;
if ( ! V_13 -> V_290 -> V_288 )
return;
F_213 ( & V_329 ) ;
for ( V_242 = 0 ; V_242 < V_310 ; V_242 ++ ) {
V_328 = V_13 -> V_290 -> V_291 [ V_242 ] ;
if ( ! V_328 )
continue;
V_328 -> V_290 -> V_315 = false ;
F_287 ( & V_328 -> V_290 -> V_314 ) ;
F_276 ( V_328 ) ;
}
F_211 ( & V_329 ) ;
}
static void F_288 ( struct V_1 * V_2 )
{
struct V_285 * V_287 ;
struct V_286 * V_296 ;
if ( ! F_3 ( V_2 ) )
return;
F_213 ( & V_2 -> V_298 ) ;
F_252 (params, &memcg->memcg_slab_caches, list) {
V_287 = F_248 ( V_296 ) ;
V_287 -> V_290 -> V_315 = true ;
F_289 ( & V_287 -> V_290 -> V_314 ,
F_274 ) ;
F_279 ( & V_287 -> V_290 -> V_314 ) ;
}
F_211 ( & V_2 -> V_298 ) ;
}
static void F_290 ( struct V_236 * V_313 )
{
struct V_330 * V_331 ;
V_331 = F_14 ( V_313 , struct V_330 , V_240 ) ;
F_284 ( V_331 -> V_2 , V_331 -> V_287 ) ;
F_94 ( & V_331 -> V_2 -> V_14 ) ;
F_267 ( V_331 ) ;
}
static void F_291 ( struct V_1 * V_2 ,
struct V_285 * V_287 )
{
struct V_330 * V_331 ;
V_331 = F_292 ( sizeof( struct V_330 ) , V_332 ) ;
if ( V_331 == NULL )
return;
if ( ! F_57 ( & V_2 -> V_14 ) ) {
F_267 ( V_331 ) ;
return;
}
V_331 -> V_2 = V_2 ;
V_331 -> V_287 = V_287 ;
F_289 ( & V_331 -> V_240 , F_290 ) ;
F_279 ( & V_331 -> V_240 ) ;
}
static void F_293 ( struct V_1 * V_2 ,
struct V_285 * V_287 )
{
F_272 () ;
F_291 ( V_2 , V_287 ) ;
F_273 () ;
}
struct V_285 * F_294 ( struct V_285 * V_287 ,
T_3 V_299 )
{
struct V_1 * V_2 ;
int V_65 ;
F_108 ( ! V_287 -> V_290 ) ;
F_108 ( ! V_287 -> V_290 -> V_288 ) ;
if ( ! V_23 -> V_109 || V_23 -> V_312 )
return V_287 ;
F_19 () ;
V_2 = F_20 ( F_90 ( V_23 -> V_109 -> V_110 ) ) ;
F_22 () ;
if ( ! F_247 ( V_2 ) )
return V_287 ;
V_65 = F_249 ( V_2 ) ;
F_295 () ;
if ( F_84 ( V_287 -> V_290 -> V_291 [ V_65 ] == NULL ) ) {
F_293 ( V_2 , V_287 ) ;
return V_287 ;
}
return V_287 -> V_290 -> V_291 [ V_65 ] ;
}
bool
F_296 ( T_3 V_299 , struct V_1 * * V_301 , int V_173 )
{
struct V_1 * V_2 ;
int V_88 ;
* V_301 = NULL ;
V_2 = F_89 ( V_23 -> V_109 ) ;
if ( F_84 ( ! V_2 ) )
return true ;
if ( ! F_247 ( V_2 ) ) {
F_94 ( & V_2 -> V_14 ) ;
return true ;
}
V_88 = F_254 ( V_2 , V_299 , V_235 << V_173 ) ;
if ( ! V_88 )
* V_301 = V_2 ;
F_94 ( & V_2 -> V_14 ) ;
return ( V_88 == 0 ) ;
}
void F_297 ( struct V_37 * V_37 , struct V_1 * V_2 ,
int V_173 )
{
struct V_131 * V_132 ;
F_108 ( F_15 ( V_2 ) ) ;
if ( ! V_37 ) {
F_256 ( V_2 , V_235 << V_173 ) ;
return;
}
V_132 = F_104 ( V_37 ) ;
F_231 ( V_132 ) ;
V_132 -> V_1 = V_2 ;
F_243 ( V_132 ) ;
F_235 ( V_132 ) ;
}
void F_298 ( struct V_37 * V_37 , int V_173 )
{
struct V_1 * V_2 = NULL ;
struct V_131 * V_132 ;
V_132 = F_104 ( V_37 ) ;
if ( ! F_106 ( V_132 ) )
return;
F_231 ( V_132 ) ;
if ( F_106 ( V_132 ) ) {
V_2 = V_132 -> V_1 ;
F_299 ( V_132 ) ;
}
F_235 ( V_132 ) ;
if ( ! V_2 )
return;
F_108 ( F_15 ( V_2 ) ) ;
F_256 ( V_2 , V_235 << V_173 ) ;
}
static inline void F_288 ( struct V_1 * V_2 )
{
}
void F_300 ( struct V_37 * V_333 )
{
struct V_131 * V_334 = F_104 ( V_333 ) ;
struct V_131 * V_132 ;
int V_242 ;
if ( F_92 () )
return;
for ( V_242 = 1 ; V_242 < V_335 ; V_242 ++ ) {
V_132 = V_334 + V_242 ;
V_132 -> V_1 = V_334 -> V_1 ;
F_242 () ;
V_132 -> V_159 = V_334 -> V_159 & ~ V_336 ;
}
}
static int F_301 ( struct V_37 * V_37 ,
unsigned int V_77 ,
struct V_131 * V_132 ,
struct V_1 * V_153 ,
struct V_1 * V_9 )
{
unsigned long V_159 ;
int V_88 ;
bool V_76 = F_302 ( V_37 ) ;
F_108 ( V_153 == V_9 ) ;
F_108 ( F_105 ( V_37 ) ) ;
V_88 = - V_337 ;
if ( V_77 > 1 && ! F_303 ( V_37 ) )
goto V_126;
F_231 ( V_132 ) ;
V_88 = - V_338 ;
if ( ! F_106 ( V_132 ) || V_132 -> V_1 != V_153 )
goto V_154;
F_137 ( V_153 , & V_159 ) ;
if ( ! V_76 && F_304 ( V_37 ) ) {
F_69 () ;
F_305 ( V_153 -> V_68 -> V_69 [ V_227 ] ) ;
F_71 ( V_9 -> V_68 -> V_69 [ V_227 ] ) ;
F_72 () ;
}
F_68 ( V_153 , V_76 , - V_77 ) ;
V_132 -> V_1 = V_9 ;
F_68 ( V_9 , V_76 , V_77 ) ;
F_139 ( V_153 , & V_159 ) ;
V_88 = 0 ;
V_154:
F_235 ( V_132 ) ;
F_83 ( V_9 , V_37 ) ;
F_83 ( V_153 , V_37 ) ;
V_126:
return V_88 ;
}
static int F_306 ( struct V_37 * V_37 ,
struct V_131 * V_132 ,
struct V_1 * V_339 )
{
struct V_1 * V_48 ;
unsigned int V_77 ;
unsigned long V_118 ( V_159 ) ;
int V_88 ;
F_108 ( F_15 ( V_339 ) ) ;
V_88 = - V_337 ;
if ( ! F_307 ( V_37 ) )
goto V_126;
if ( F_308 ( V_37 ) )
goto V_340;
V_77 = F_309 ( V_37 ) ;
V_48 = F_51 ( V_339 ) ;
if ( ! V_48 )
V_48 = V_15 ;
if ( V_77 > 1 ) {
F_108 ( ! F_303 ( V_37 ) ) ;
V_159 = F_310 ( V_37 ) ;
}
V_88 = F_301 ( V_37 , V_77 ,
V_132 , V_339 , V_48 ) ;
if ( ! V_88 )
F_225 ( V_339 , V_77 ) ;
if ( V_77 > 1 )
F_311 ( V_37 , V_159 ) ;
F_312 ( V_37 ) ;
V_340:
F_313 ( V_37 ) ;
V_126:
return V_88 ;
}
static int F_314 ( struct V_37 * V_37 , struct V_108 * V_109 ,
T_3 V_172 , enum V_278 V_279 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_77 = 1 ;
bool V_269 = true ;
int V_88 ;
if ( F_303 ( V_37 ) ) {
V_77 <<= F_315 ( V_37 ) ;
F_108 ( ! F_303 ( V_37 ) ) ;
V_269 = false ;
}
V_88 = F_222 ( V_109 , V_172 , V_77 , & V_2 , V_269 ) ;
if ( V_88 == - V_275 )
return V_88 ;
F_236 ( V_2 , V_37 , V_77 , V_279 , false ) ;
return 0 ;
}
int F_316 ( struct V_37 * V_37 ,
struct V_108 * V_109 , T_3 V_172 )
{
if ( F_92 () )
return 0 ;
F_108 ( F_304 ( V_37 ) ) ;
F_108 ( V_37 -> V_341 && ! F_302 ( V_37 ) ) ;
F_108 ( ! V_109 ) ;
return F_314 ( V_37 , V_109 , V_172 ,
V_283 ) ;
}
static int F_317 ( struct V_108 * V_109 ,
struct V_37 * V_37 ,
T_3 V_214 ,
struct V_1 * * V_342 )
{
struct V_1 * V_2 ;
struct V_131 * V_132 ;
int V_88 ;
V_132 = F_104 ( V_37 ) ;
if ( F_106 ( V_132 ) )
return 0 ;
if ( ! V_146 )
goto V_343;
V_2 = F_229 ( V_37 ) ;
if ( ! V_2 )
goto V_343;
* V_342 = V_2 ;
V_88 = F_222 ( NULL , V_214 , 1 , V_342 , true ) ;
F_94 ( & V_2 -> V_14 ) ;
if ( V_88 == - V_276 )
V_88 = 0 ;
return V_88 ;
V_343:
V_88 = F_222 ( V_109 , V_214 , 1 , V_342 , true ) ;
if ( V_88 == - V_276 )
V_88 = 0 ;
return V_88 ;
}
int F_318 ( struct V_108 * V_109 , struct V_37 * V_37 ,
T_3 V_172 , struct V_1 * * V_342 )
{
* V_342 = NULL ;
if ( F_92 () )
return 0 ;
if ( ! F_232 ( V_37 ) ) {
int V_88 ;
V_88 = F_222 ( V_109 , V_172 , 1 , V_342 , true ) ;
if ( V_88 == - V_276 )
V_88 = 0 ;
return V_88 ;
}
return F_317 ( V_109 , V_37 , V_172 , V_342 ) ;
}
void F_319 ( struct V_1 * V_2 )
{
if ( F_92 () )
return;
if ( ! V_2 )
return;
F_224 ( V_2 , 1 ) ;
}
static void
F_320 ( struct V_37 * V_37 , struct V_1 * V_2 ,
enum V_278 V_279 )
{
if ( F_92 () )
return;
if ( ! V_2 )
return;
F_236 ( V_2 , V_37 , 1 , V_279 , true ) ;
if ( V_146 && F_232 ( V_37 ) ) {
T_6 V_277 = { . V_66 = F_233 (page) } ;
F_321 ( V_277 ) ;
}
}
void F_322 ( struct V_37 * V_37 ,
struct V_1 * V_2 )
{
F_320 ( V_37 , V_2 ,
V_283 ) ;
}
int F_323 ( struct V_37 * V_37 , struct V_108 * V_109 ,
T_3 V_172 )
{
struct V_1 * V_2 = NULL ;
enum V_278 type = V_344 ;
int V_88 ;
if ( F_92 () )
return 0 ;
if ( F_324 ( V_37 ) )
return 0 ;
if ( ! F_232 ( V_37 ) )
V_88 = F_314 ( V_37 , V_109 , V_172 , type ) ;
else {
V_88 = F_317 ( V_109 , V_37 ,
V_172 , & V_2 ) ;
if ( ! V_88 )
F_320 ( V_37 , V_2 , type ) ;
}
return V_88 ;
}
static void F_325 ( struct V_1 * V_2 ,
unsigned int V_77 ,
const enum V_278 V_279 )
{
struct V_345 * V_270 = NULL ;
bool V_346 = true ;
if ( ! V_146 || V_279 == V_347 )
V_346 = false ;
V_270 = & V_23 -> V_348 ;
if ( ! V_270 -> V_2 )
V_270 -> V_2 = V_2 ;
if ( ! V_270 -> V_349 || F_191 ( V_178 ) )
goto V_350;
if ( V_77 > 1 )
goto V_350;
if ( V_270 -> V_2 != V_2 )
goto V_350;
V_270 -> V_77 ++ ;
if ( V_346 )
V_270 -> V_351 ++ ;
return;
V_350:
F_200 ( & V_2 -> V_57 , V_77 * V_235 ) ;
if ( V_346 )
F_200 ( & V_2 -> V_147 , V_77 * V_235 ) ;
if ( F_84 ( V_270 -> V_2 != V_2 ) )
F_187 ( V_2 ) ;
}
static struct V_1 *
F_326 ( struct V_37 * V_37 , enum V_278 V_279 ,
bool V_352 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_77 = 1 ;
struct V_131 * V_132 ;
bool V_76 ;
if ( F_92 () )
return NULL ;
F_108 ( F_232 ( V_37 ) ) ;
if ( F_303 ( V_37 ) ) {
V_77 <<= F_315 ( V_37 ) ;
F_108 ( ! F_303 ( V_37 ) ) ;
}
V_132 = F_104 ( V_37 ) ;
if ( F_84 ( ! F_106 ( V_132 ) ) )
return NULL ;
F_231 ( V_132 ) ;
V_2 = V_132 -> V_1 ;
if ( ! F_106 ( V_132 ) )
goto V_353;
V_76 = F_302 ( V_37 ) ;
switch ( V_279 ) {
case V_283 :
V_76 = true ;
case V_354 :
if ( F_304 ( V_37 ) )
goto V_353;
if ( ! V_352 && F_327 ( V_132 ) )
goto V_353;
break;
case V_347 :
if ( ! F_302 ( V_37 ) ) {
if ( V_37 -> V_341 && ! F_328 ( V_37 ) )
goto V_353;
} else if ( F_304 ( V_37 ) )
goto V_353;
break;
default:
break;
}
F_68 ( V_2 , V_76 , - V_77 ) ;
F_299 ( V_132 ) ;
F_235 ( V_132 ) ;
F_83 ( V_2 , V_37 ) ;
if ( V_146 && V_279 == V_347 ) {
F_65 ( V_2 , true ) ;
F_18 ( V_2 ) ;
}
if ( ! V_352 && ! F_15 ( V_2 ) )
F_325 ( V_2 , V_77 , V_279 ) ;
return V_2 ;
V_353:
F_235 ( V_132 ) ;
return NULL ;
}
void F_329 ( struct V_37 * V_37 )
{
if ( F_304 ( V_37 ) )
return;
F_108 ( V_37 -> V_341 && ! F_302 ( V_37 ) ) ;
if ( F_232 ( V_37 ) )
return;
F_326 ( V_37 , V_283 , false ) ;
}
void F_330 ( struct V_37 * V_37 )
{
F_108 ( F_304 ( V_37 ) ) ;
F_108 ( V_37 -> V_341 ) ;
F_326 ( V_37 , V_344 , false ) ;
}
void F_331 ( void )
{
V_23 -> V_348 . V_349 ++ ;
if ( V_23 -> V_348 . V_349 == 1 ) {
V_23 -> V_348 . V_2 = NULL ;
V_23 -> V_348 . V_77 = 0 ;
V_23 -> V_348 . V_351 = 0 ;
}
}
void F_332 ( void )
{
struct V_345 * V_270 = & V_23 -> V_348 ;
if ( ! V_270 -> V_349 )
return;
V_270 -> V_349 -- ;
if ( V_270 -> V_349 )
return;
if ( ! V_270 -> V_2 )
return;
if ( V_270 -> V_77 )
F_200 ( & V_270 -> V_2 -> V_57 ,
V_270 -> V_77 * V_235 ) ;
if ( V_270 -> V_351 )
F_200 ( & V_270 -> V_2 -> V_147 ,
V_270 -> V_351 * V_235 ) ;
F_187 ( V_270 -> V_2 ) ;
V_270 -> V_2 = NULL ;
}
void
F_333 ( struct V_37 * V_37 , T_6 V_277 , bool V_355 )
{
struct V_1 * V_2 ;
int V_279 = V_347 ;
if ( ! V_355 )
V_279 = V_354 ;
V_2 = F_326 ( V_37 , V_279 , false ) ;
if ( V_146 && V_355 && V_2 )
F_334 ( V_277 , F_93 ( & V_2 -> V_14 ) ) ;
}
void F_321 ( T_6 V_277 )
{
struct V_1 * V_2 ;
unsigned short V_115 ;
if ( ! V_146 )
return;
V_115 = F_334 ( V_277 , 0 ) ;
F_19 () ;
V_2 = F_227 ( V_115 ) ;
if ( V_2 ) {
if ( ! F_15 ( V_2 ) )
F_200 ( & V_2 -> V_147 , V_235 ) ;
F_65 ( V_2 , false ) ;
F_25 ( V_2 ) ;
}
F_22 () ;
}
static int F_335 ( T_6 V_356 ,
struct V_1 * V_153 , struct V_1 * V_9 )
{
unsigned short V_357 , V_358 ;
V_357 = F_93 ( & V_153 -> V_14 ) ;
V_358 = F_93 ( & V_9 -> V_14 ) ;
if ( F_336 ( V_356 , V_357 , V_358 ) == V_357 ) {
F_65 ( V_153 , false ) ;
F_65 ( V_9 , true ) ;
F_18 ( V_9 ) ;
return 0 ;
}
return - V_338 ;
}
static inline int F_335 ( T_6 V_356 ,
struct V_1 * V_153 , struct V_1 * V_9 )
{
return - V_338 ;
}
void F_337 ( struct V_37 * V_37 , struct V_37 * V_359 ,
struct V_1 * * V_342 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_77 = 1 ;
struct V_131 * V_132 ;
enum V_278 V_279 ;
* V_342 = NULL ;
if ( F_92 () )
return;
if ( F_303 ( V_37 ) )
V_77 <<= F_315 ( V_37 ) ;
V_132 = F_104 ( V_37 ) ;
F_231 ( V_132 ) ;
if ( F_106 ( V_132 ) ) {
V_2 = V_132 -> V_1 ;
F_116 ( & V_2 -> V_14 ) ;
if ( F_302 ( V_37 ) )
F_338 ( V_132 ) ;
}
F_235 ( V_132 ) ;
if ( ! V_2 )
return;
* V_342 = V_2 ;
if ( F_302 ( V_37 ) )
V_279 = V_283 ;
else
V_279 = V_344 ;
F_236 ( V_2 , V_359 , V_77 , V_279 , false ) ;
}
void F_339 ( struct V_1 * V_2 ,
struct V_37 * V_360 , struct V_37 * V_359 , bool V_361 )
{
struct V_37 * V_362 , * V_363 ;
struct V_131 * V_132 ;
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
V_76 = F_302 ( V_362 ) ;
F_326 ( V_363 ,
V_76 ? V_283
: V_344 ,
true ) ;
F_94 ( & V_2 -> V_14 ) ;
V_132 = F_104 ( V_360 ) ;
F_231 ( V_132 ) ;
F_340 ( V_132 ) ;
F_235 ( V_132 ) ;
if ( V_76 )
F_329 ( V_362 ) ;
}
void F_341 ( struct V_37 * V_360 ,
struct V_37 * V_359 )
{
struct V_1 * V_2 = NULL ;
struct V_131 * V_132 ;
enum V_278 type = V_344 ;
if ( F_92 () )
return;
V_132 = F_104 ( V_360 ) ;
F_231 ( V_132 ) ;
if ( F_106 ( V_132 ) ) {
V_2 = V_132 -> V_1 ;
F_68 ( V_2 , false , - 1 ) ;
F_299 ( V_132 ) ;
}
F_235 ( V_132 ) ;
if ( ! V_2 )
return;
F_236 ( V_2 , V_359 , 1 , type , true ) ;
}
static struct V_131 * F_342 ( struct V_37 * V_37 )
{
struct V_131 * V_132 ;
V_132 = F_104 ( V_37 ) ;
if ( F_219 ( V_132 ) && F_106 ( V_132 ) )
return V_132 ;
return NULL ;
}
bool F_343 ( struct V_37 * V_37 )
{
if ( F_92 () )
return false ;
return F_342 ( V_37 ) != NULL ;
}
void F_344 ( struct V_37 * V_37 )
{
struct V_131 * V_132 ;
V_132 = F_342 ( V_37 ) ;
if ( V_132 ) {
F_144 ( V_364 L_9 ,
V_132 , V_132 -> V_159 , V_132 -> V_1 ) ;
}
}
static int F_345 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_365 ;
T_1 V_366 , V_367 ;
int V_88 = 0 ;
int V_368 = F_145 ( V_2 ) ;
T_1 V_369 , V_370 ;
int V_371 ;
V_365 = V_272 * V_368 ;
V_370 = F_32 ( & V_2 -> V_57 , V_30 ) ;
V_371 = 0 ;
while ( V_365 ) {
if ( F_346 ( V_23 ) ) {
V_88 = - V_276 ;
break;
}
F_213 ( & V_329 ) ;
V_366 = F_32 ( & V_2 -> V_147 , V_167 ) ;
if ( V_366 < V_66 ) {
V_88 = - V_338 ;
F_211 ( & V_329 ) ;
break;
}
V_367 = F_32 ( & V_2 -> V_57 , V_167 ) ;
if ( V_367 < V_66 )
V_371 = 1 ;
V_88 = F_347 ( & V_2 -> V_57 , V_66 ) ;
if ( ! V_88 ) {
if ( V_366 == V_66 )
V_2 -> V_191 = true ;
else
V_2 -> V_191 = false ;
}
F_211 ( & V_329 ) ;
if ( ! V_88 )
break;
F_160 ( V_2 , V_307 ,
V_190 ) ;
V_369 = F_32 ( & V_2 -> V_57 , V_30 ) ;
if ( V_369 >= V_370 )
V_365 -- ;
else
V_370 = V_369 ;
}
if ( ! V_88 && V_371 )
F_187 ( V_2 ) ;
return V_88 ;
}
static int F_348 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_365 ;
T_1 V_367 , V_366 , V_370 , V_369 ;
int V_368 = F_145 ( V_2 ) ;
int V_88 = - V_337 ;
int V_371 = 0 ;
V_365 = V_368 * V_272 ;
V_370 = F_32 ( & V_2 -> V_147 , V_30 ) ;
while ( V_365 ) {
if ( F_346 ( V_23 ) ) {
V_88 = - V_276 ;
break;
}
F_213 ( & V_329 ) ;
V_367 = F_32 ( & V_2 -> V_57 , V_167 ) ;
if ( V_367 > V_66 ) {
V_88 = - V_338 ;
F_211 ( & V_329 ) ;
break;
}
V_366 = F_32 ( & V_2 -> V_147 , V_167 ) ;
if ( V_366 < V_66 )
V_371 = 1 ;
V_88 = F_347 ( & V_2 -> V_147 , V_66 ) ;
if ( ! V_88 ) {
if ( V_367 == V_66 )
V_2 -> V_191 = true ;
else
V_2 -> V_191 = false ;
}
F_211 ( & V_329 ) ;
if ( ! V_88 )
break;
F_160 ( V_2 , V_307 ,
V_189 |
V_190 ) ;
V_369 = F_32 ( & V_2 -> V_147 , V_30 ) ;
if ( V_369 >= V_370 )
V_365 -- ;
else
V_370 = V_369 ;
}
if ( ! V_88 && V_371 )
F_187 ( V_2 ) ;
return V_88 ;
}
unsigned long F_349 ( struct V_59 * V_59 , int V_173 ,
T_3 V_172 ,
unsigned long * V_200 )
{
unsigned long V_372 = 0 ;
struct V_31 * V_42 , * V_373 = NULL ;
unsigned long V_374 ;
int V_188 = 0 ;
struct V_38 * V_43 ;
unsigned long long V_56 ;
unsigned long V_202 ;
if ( V_173 > 0 )
return 0 ;
V_43 = F_39 ( F_95 ( V_59 ) , F_96 ( V_59 ) ) ;
do {
if ( V_373 )
V_42 = V_373 ;
else
V_42 = F_58 ( V_43 ) ;
if ( ! V_42 )
break;
V_202 = 0 ;
V_374 = F_176 ( V_42 -> V_2 , V_59 ,
V_172 , & V_202 ) ;
V_372 += V_374 ;
* V_200 += V_202 ;
F_48 ( & V_43 -> V_55 ) ;
V_373 = NULL ;
if ( ! V_374 ) {
do {
V_373 =
F_55 ( V_43 ) ;
if ( V_373 == V_42 )
F_94 ( & V_373 -> V_2 -> V_14 ) ;
else
break;
} while ( 1 );
}
F_45 ( V_42 -> V_2 , V_42 , V_43 ) ;
V_56 = F_52 ( & V_42 -> V_2 -> V_57 ) ;
F_41 ( V_42 -> V_2 , V_42 , V_43 , V_56 ) ;
F_49 ( & V_43 -> V_55 ) ;
F_94 ( & V_42 -> V_2 -> V_14 ) ;
V_188 ++ ;
if ( ! V_372 &&
( V_373 == NULL ||
V_188 > V_375 ) )
break;
} while ( ! V_372 );
if ( V_373 )
F_94 ( & V_373 -> V_2 -> V_14 ) ;
return V_372 ;
}
static void F_350 ( struct V_1 * V_2 ,
int V_58 , int V_33 , enum V_84 V_85 )
{
struct V_83 * V_83 ;
unsigned long V_159 ;
struct V_376 * V_304 ;
struct V_37 * V_377 ;
struct V_59 * V_59 ;
V_59 = & F_351 ( V_58 ) -> V_378 [ V_33 ] ;
V_83 = F_102 ( V_59 , V_2 ) ;
V_304 = & V_83 -> V_379 [ V_85 ] ;
V_377 = NULL ;
do {
struct V_131 * V_132 ;
struct V_37 * V_37 ;
F_138 ( & V_59 -> V_282 , V_159 ) ;
if ( F_352 ( V_304 ) ) {
F_140 ( & V_59 -> V_282 , V_159 ) ;
break;
}
V_37 = F_353 ( V_304 -> V_112 , struct V_37 , V_85 ) ;
if ( V_377 == V_37 ) {
F_354 ( & V_37 -> V_85 , V_304 ) ;
V_377 = NULL ;
F_140 ( & V_59 -> V_282 , V_159 ) ;
continue;
}
F_140 ( & V_59 -> V_282 , V_159 ) ;
V_132 = F_104 ( V_37 ) ;
if ( F_306 ( V_37 , V_132 , V_2 ) ) {
V_377 = V_37 ;
F_355 () ;
} else
V_377 = NULL ;
} while ( ! F_352 ( V_304 ) );
}
static void F_356 ( struct V_1 * V_2 )
{
int V_58 , V_33 ;
T_1 V_380 ;
do {
F_357 () ;
F_212 ( V_2 ) ;
F_124 ( V_2 ) ;
F_79 (node, N_MEMORY) {
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
enum V_84 V_85 ;
F_75 (lru) {
F_350 ( V_2 ,
V_58 , V_33 , V_85 ) ;
}
}
}
F_126 ( V_2 ) ;
F_187 ( V_2 ) ;
F_355 () ;
V_380 = F_32 ( & V_2 -> V_57 , V_30 ) -
F_32 ( & V_2 -> V_29 , V_30 ) ;
} while ( V_380 > 0 );
}
static int F_358 ( struct V_1 * V_2 )
{
int V_381 = V_272 ;
struct V_104 * V_148 = V_2 -> V_14 . V_104 ;
if ( F_359 ( V_148 ) || ! F_352 ( & V_148 -> V_368 ) )
return - V_337 ;
F_357 () ;
while ( V_381 && F_32 ( & V_2 -> V_57 , V_30 ) > 0 ) {
int V_382 ;
if ( F_346 ( V_23 ) )
return - V_276 ;
V_382 = F_162 ( V_2 , V_307 ,
false ) ;
if ( ! V_382 ) {
V_381 -- ;
F_360 ( V_383 , V_384 / 10 ) ;
}
}
F_361 () ;
F_356 ( V_2 ) ;
return 0 ;
}
static int F_362 ( struct V_104 * V_105 , unsigned int V_385 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
int V_88 ;
if ( F_15 ( V_2 ) )
return - V_338 ;
F_116 ( & V_2 -> V_14 ) ;
V_88 = F_358 ( V_2 ) ;
F_94 ( & V_2 -> V_14 ) ;
return V_88 ;
}
static T_1 F_363 ( struct V_104 * V_105 , struct V_292 * V_293 )
{
return F_87 ( V_105 ) -> V_116 ;
}
static int F_364 ( struct V_104 * V_105 , struct V_292 * V_293 ,
T_1 V_66 )
{
int V_386 = 0 ;
struct V_1 * V_2 = F_87 ( V_105 ) ;
struct V_104 * V_48 = V_105 -> V_48 ;
struct V_1 * V_387 = NULL ;
if ( V_48 )
V_387 = F_87 ( V_48 ) ;
F_365 () ;
if ( V_2 -> V_116 == V_66 )
goto V_126;
if ( ( ! V_387 || ! V_387 -> V_116 ) &&
( V_66 == 1 || V_66 == 0 ) ) {
if ( F_352 ( & V_105 -> V_368 ) )
V_2 -> V_116 = V_66 ;
else
V_386 = - V_337 ;
} else
V_386 = - V_338 ;
V_126:
F_366 () ;
return V_386 ;
}
static unsigned long F_367 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
struct V_1 * V_119 ;
long V_66 = 0 ;
F_146 (iter, memcg)
V_66 += F_59 ( V_119 , V_65 ) ;
if ( V_66 < 0 )
V_66 = 0 ;
return V_66 ;
}
static inline T_1 F_368 ( struct V_1 * V_2 , bool V_388 )
{
T_1 V_66 ;
if ( ! F_15 ( V_2 ) ) {
if ( ! V_388 )
return F_32 ( & V_2 -> V_57 , V_30 ) ;
else
return F_32 ( & V_2 -> V_147 , V_30 ) ;
}
V_66 = F_367 ( V_2 , V_79 ) ;
V_66 += F_367 ( V_2 , V_78 ) ;
if ( V_388 )
V_66 += F_367 ( V_2 , V_73 ) ;
return V_66 << V_142 ;
}
static T_8 F_369 ( struct V_104 * V_105 , struct V_292 * V_293 ,
struct V_389 * V_389 , char T_9 * V_390 ,
T_7 V_391 , T_10 * V_392 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
char V_393 [ 64 ] ;
T_1 V_66 ;
int V_316 , V_394 ;
enum V_395 type ;
type = F_370 ( V_293 -> V_219 ) ;
V_316 = F_371 ( V_293 -> V_219 ) ;
if ( ! V_146 && type == V_396 )
return - V_397 ;
switch ( type ) {
case V_398 :
if ( V_316 == V_30 )
V_66 = F_368 ( V_2 , false ) ;
else
V_66 = F_32 ( & V_2 -> V_57 , V_316 ) ;
break;
case V_396 :
if ( V_316 == V_30 )
V_66 = F_368 ( V_2 , true ) ;
else
V_66 = F_32 ( & V_2 -> V_147 , V_316 ) ;
break;
case V_399 :
V_66 = F_32 ( & V_2 -> V_29 , V_316 ) ;
break;
default:
F_101 () ;
}
V_394 = F_372 ( V_393 , sizeof( V_393 ) , L_10 , ( unsigned long long ) V_66 ) ;
return F_373 ( V_390 , V_391 , V_392 , V_393 , V_394 ) ;
}
static int F_374 ( struct V_104 * V_105 , T_1 V_66 )
{
int V_88 = - V_338 ;
#ifdef F_375
bool V_400 = false ;
struct V_1 * V_2 = F_87 ( V_105 ) ;
F_365 () ;
F_213 ( & V_329 ) ;
if ( ! V_2 -> V_4 && V_66 != V_401 ) {
if ( F_359 ( V_105 ) || ( V_2 -> V_116 &&
! F_352 ( & V_105 -> V_368 ) ) ) {
V_88 = - V_337 ;
goto V_126;
}
V_88 = F_347 ( & V_2 -> V_29 , V_66 ) ;
F_108 ( V_88 ) ;
V_88 = F_259 ( V_2 ) ;
if ( V_88 ) {
F_347 ( & V_2 -> V_29 , V_401 ) ;
goto V_126;
}
V_400 = true ;
F_18 ( V_2 ) ;
} else
V_88 = F_347 ( & V_2 -> V_29 , V_66 ) ;
V_126:
F_211 ( & V_329 ) ;
F_366 () ;
if ( V_400 ) {
F_376 ( & V_26 ) ;
F_1 ( V_2 ) ;
}
#endif
return V_88 ;
}
static int F_377 ( struct V_1 * V_2 )
{
int V_88 = 0 ;
struct V_1 * V_48 = F_51 ( V_2 ) ;
if ( ! V_48 )
goto V_126;
V_2 -> V_4 = V_48 -> V_4 ;
#ifdef F_375
if ( ! F_3 ( V_2 ) )
goto V_126;
F_18 ( V_2 ) ;
F_376 ( & V_26 ) ;
F_213 ( & V_329 ) ;
V_88 = F_259 ( V_2 ) ;
F_211 ( & V_329 ) ;
#endif
V_126:
return V_88 ;
}
static int F_378 ( struct V_104 * V_105 , struct V_292 * V_293 ,
const char * V_402 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
enum V_395 type ;
int V_316 ;
unsigned long long V_66 ;
int V_88 ;
type = F_370 ( V_293 -> V_219 ) ;
V_316 = F_371 ( V_293 -> V_219 ) ;
if ( ! V_146 && type == V_396 )
return - V_397 ;
switch ( V_316 ) {
case V_167 :
if ( F_15 ( V_2 ) ) {
V_88 = - V_338 ;
break;
}
V_88 = F_379 ( V_402 , & V_66 ) ;
if ( V_88 )
break;
if ( type == V_398 )
V_88 = F_345 ( V_2 , V_66 ) ;
else if ( type == V_396 )
V_88 = F_348 ( V_2 , V_66 ) ;
else if ( type == V_399 )
V_88 = F_374 ( V_105 , V_66 ) ;
else
return - V_338 ;
break;
case V_403 :
V_88 = F_379 ( V_402 , & V_66 ) ;
if ( V_88 )
break;
if ( type == V_398 )
V_88 = F_380 ( & V_2 -> V_57 , V_66 ) ;
else
V_88 = - V_338 ;
break;
default:
V_88 = - V_338 ;
break;
}
return V_88 ;
}
static void F_381 ( struct V_1 * V_2 ,
unsigned long long * V_404 , unsigned long long * V_405 )
{
struct V_104 * V_104 ;
unsigned long long V_406 , V_407 , V_408 ;
V_406 = F_32 ( & V_2 -> V_57 , V_167 ) ;
V_407 = F_32 ( & V_2 -> V_147 , V_167 ) ;
V_104 = V_2 -> V_14 . V_104 ;
if ( ! V_2 -> V_116 )
goto V_126;
while ( V_104 -> V_48 ) {
V_104 = V_104 -> V_48 ;
V_2 = F_87 ( V_104 ) ;
if ( ! V_2 -> V_116 )
break;
V_408 = F_32 ( & V_2 -> V_57 , V_167 ) ;
V_406 = F_122 ( V_406 , V_408 ) ;
V_408 = F_32 ( & V_2 -> V_147 , V_167 ) ;
V_407 = F_122 ( V_407 , V_408 ) ;
}
V_126:
* V_404 = V_406 ;
* V_405 = V_407 ;
}
static int F_382 ( struct V_104 * V_105 , unsigned int V_385 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
int V_316 ;
enum V_395 type ;
type = F_370 ( V_385 ) ;
V_316 = F_371 ( V_385 ) ;
if ( ! V_146 && type == V_396 )
return - V_397 ;
switch ( V_316 ) {
case V_409 :
if ( type == V_398 )
F_383 ( & V_2 -> V_57 ) ;
else if ( type == V_396 )
F_383 ( & V_2 -> V_147 ) ;
else if ( type == V_399 )
F_383 ( & V_2 -> V_29 ) ;
else
return - V_338 ;
break;
case V_168 :
if ( type == V_398 )
F_384 ( & V_2 -> V_57 ) ;
else if ( type == V_396 )
F_384 ( & V_2 -> V_147 ) ;
else if ( type == V_399 )
F_384 ( & V_2 -> V_29 ) ;
else
return - V_338 ;
break;
}
return 0 ;
}
static T_1 F_385 ( struct V_104 * V_148 ,
struct V_292 * V_293 )
{
return F_87 ( V_148 ) -> V_10 ;
}
static int F_386 ( struct V_104 * V_148 ,
struct V_292 * V_293 , T_1 V_66 )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
if ( V_66 >= ( 1 << V_410 ) )
return - V_338 ;
F_365 () ;
V_2 -> V_10 = V_66 ;
F_366 () ;
return 0 ;
}
static int F_386 ( struct V_104 * V_148 ,
struct V_292 * V_293 , T_1 V_66 )
{
return - V_411 ;
}
static int F_387 ( struct V_104 * V_105 , struct V_292 * V_293 ,
struct V_294 * V_295 )
{
int V_32 ;
unsigned long V_412 , V_413 , V_414 , V_415 ;
unsigned long V_416 ;
struct V_1 * V_2 = F_87 ( V_105 ) ;
V_412 = F_78 ( V_2 , V_417 ) ;
F_388 ( V_295 , L_11 , V_412 ) ;
F_79 (nid, N_MEMORY) {
V_416 = F_77 ( V_2 , V_32 , V_417 ) ;
F_388 ( V_295 , L_12 , V_32 , V_416 ) ;
}
F_389 ( V_295 , '\n' ) ;
V_413 = F_78 ( V_2 , V_193 ) ;
F_388 ( V_295 , L_13 , V_413 ) ;
F_79 (nid, N_MEMORY) {
V_416 = F_77 ( V_2 , V_32 ,
V_193 ) ;
F_388 ( V_295 , L_12 , V_32 , V_416 ) ;
}
F_389 ( V_295 , '\n' ) ;
V_414 = F_78 ( V_2 , V_194 ) ;
F_388 ( V_295 , L_14 , V_414 ) ;
F_79 (nid, N_MEMORY) {
V_416 = F_77 ( V_2 , V_32 ,
V_194 ) ;
F_388 ( V_295 , L_12 , V_32 , V_416 ) ;
}
F_389 ( V_295 , '\n' ) ;
V_415 = F_78 ( V_2 , F_76 ( V_418 ) ) ;
F_388 ( V_295 , L_15 , V_415 ) ;
F_79 (nid, N_MEMORY) {
V_416 = F_77 ( V_2 , V_32 ,
F_76 ( V_418 ) ) ;
F_388 ( V_295 , L_12 , V_32 , V_416 ) ;
}
F_389 ( V_295 , '\n' ) ;
return 0 ;
}
static inline void F_390 ( void )
{
F_391 ( F_392 ( V_419 ) != V_420 ) ;
}
static int F_393 ( struct V_104 * V_105 , struct V_292 * V_293 ,
struct V_294 * V_295 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
struct V_1 * V_421 ;
unsigned int V_242 ;
for ( V_242 = 0 ; V_242 < V_243 ; V_242 ++ ) {
if ( V_242 == V_73 && ! V_146 )
continue;
F_388 ( V_295 , L_16 , V_422 [ V_242 ] ,
F_59 ( V_2 , V_242 ) * V_235 ) ;
}
for ( V_242 = 0 ; V_242 < V_245 ; V_242 ++ )
F_388 ( V_295 , L_17 , V_423 [ V_242 ] ,
F_67 ( V_2 , V_242 ) ) ;
for ( V_242 = 0 ; V_242 < V_420 ; V_242 ++ )
F_388 ( V_295 , L_17 , V_419 [ V_242 ] ,
F_78 ( V_2 , F_76 ( V_242 ) ) * V_235 ) ;
{
unsigned long long V_170 , V_405 ;
F_381 ( V_2 , & V_170 , & V_405 ) ;
F_388 ( V_295 , L_18 , V_170 ) ;
if ( V_146 )
F_388 ( V_295 , L_19 ,
V_405 ) ;
}
for ( V_242 = 0 ; V_242 < V_243 ; V_242 ++ ) {
long long V_66 = 0 ;
if ( V_242 == V_73 && ! V_146 )
continue;
F_146 (mi, memcg)
V_66 += F_59 ( V_421 , V_242 ) * V_235 ;
F_388 ( V_295 , L_20 , V_422 [ V_242 ] , V_66 ) ;
}
for ( V_242 = 0 ; V_242 < V_245 ; V_242 ++ ) {
unsigned long long V_66 = 0 ;
F_146 (mi, memcg)
V_66 += F_67 ( V_421 , V_242 ) ;
F_388 ( V_295 , L_21 ,
V_423 [ V_242 ] , V_66 ) ;
}
for ( V_242 = 0 ; V_242 < V_420 ; V_242 ++ ) {
unsigned long long V_66 = 0 ;
F_146 (mi, memcg)
V_66 += F_78 ( V_421 , F_76 ( V_242 ) ) * V_235 ;
F_388 ( V_295 , L_21 , V_419 [ V_242 ] , V_66 ) ;
}
#ifdef F_394
{
int V_32 , V_33 ;
struct V_31 * V_42 ;
struct V_424 * V_425 ;
unsigned long V_426 [ 2 ] = { 0 , 0 } ;
unsigned long V_427 [ 2 ] = { 0 , 0 } ;
F_395 (nid)
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
V_42 = F_34 ( V_2 , V_32 , V_33 ) ;
V_425 = & V_42 -> V_83 . V_428 ;
V_426 [ 0 ] += V_425 -> V_426 [ 0 ] ;
V_426 [ 1 ] += V_425 -> V_426 [ 1 ] ;
V_427 [ 0 ] += V_425 -> V_427 [ 0 ] ;
V_427 [ 1 ] += V_425 -> V_427 [ 1 ] ;
}
F_388 ( V_295 , L_22 , V_426 [ 0 ] ) ;
F_388 ( V_295 , L_23 , V_426 [ 1 ] ) ;
F_388 ( V_295 , L_24 , V_427 [ 0 ] ) ;
F_388 ( V_295 , L_25 , V_427 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_396 ( struct V_104 * V_148 , struct V_292 * V_293 )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
return F_123 ( V_2 ) ;
}
static int F_397 ( struct V_104 * V_148 , struct V_292 * V_293 ,
T_1 V_66 )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
struct V_1 * V_48 ;
if ( V_66 > 100 )
return - V_338 ;
if ( V_148 -> V_48 == NULL )
return - V_338 ;
V_48 = F_87 ( V_148 -> V_48 ) ;
F_365 () ;
if ( ( V_48 -> V_116 ) ||
( V_2 -> V_116 && ! F_352 ( & V_148 -> V_368 ) ) ) {
F_366 () ;
return - V_338 ;
}
V_2 -> V_150 = V_66 ;
F_366 () ;
return 0 ;
}
static void F_398 ( struct V_1 * V_2 , bool V_388 )
{
struct V_429 * V_430 ;
T_1 V_380 ;
int V_242 ;
F_19 () ;
if ( ! V_388 )
V_430 = F_90 ( V_2 -> V_431 . V_432 ) ;
else
V_430 = F_90 ( V_2 -> V_433 . V_432 ) ;
if ( ! V_430 )
goto V_154;
V_380 = F_368 ( V_2 , V_388 ) ;
V_242 = V_430 -> V_434 ;
for (; V_242 >= 0 && F_84 ( V_430 -> V_435 [ V_242 ] . V_436 > V_380 ) ; V_242 -- )
F_399 ( V_430 -> V_435 [ V_242 ] . V_437 , 1 ) ;
V_242 ++ ;
for (; V_242 < V_430 -> V_300 && F_84 ( V_430 -> V_435 [ V_242 ] . V_436 <= V_380 ) ; V_242 ++ )
F_399 ( V_430 -> V_435 [ V_242 ] . V_437 , 1 ) ;
V_430 -> V_434 = V_242 - 1 ;
V_154:
F_22 () ;
}
static void F_85 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_398 ( V_2 , false ) ;
if ( V_146 )
F_398 ( V_2 , true ) ;
V_2 = F_51 ( V_2 ) ;
}
}
static int F_400 ( const void * V_438 , const void * V_439 )
{
const struct F_85 * V_440 = V_438 ;
const struct F_85 * V_441 = V_439 ;
return V_440 -> V_436 - V_441 -> V_436 ;
}
static int F_401 ( struct V_1 * V_2 )
{
struct V_442 * V_443 ;
F_252 (ev, &memcg->oom_notify, list)
F_399 ( V_443 -> V_437 , 1 ) ;
return 0 ;
}
static void F_190 ( struct V_1 * V_2 )
{
struct V_1 * V_119 ;
F_146 (iter, memcg)
F_401 ( V_119 ) ;
}
static int F_402 ( struct V_104 * V_148 ,
struct V_292 * V_293 , struct V_444 * V_437 , const char * args )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
struct V_445 * V_431 ;
struct V_429 * V_319 ;
enum V_395 type = F_370 ( V_293 -> V_219 ) ;
T_1 V_436 , V_380 ;
int V_242 , V_300 , V_88 ;
V_88 = F_379 ( args , & V_436 ) ;
if ( V_88 )
return V_88 ;
F_213 ( & V_2 -> V_446 ) ;
if ( type == V_398 )
V_431 = & V_2 -> V_431 ;
else if ( type == V_396 )
V_431 = & V_2 -> V_433 ;
else
F_101 () ;
V_380 = F_368 ( V_2 , type == V_396 ) ;
if ( V_431 -> V_432 )
F_398 ( V_2 , type == V_396 ) ;
V_300 = V_431 -> V_432 ? V_431 -> V_432 -> V_300 + 1 : 1 ;
V_319 = F_292 ( sizeof( * V_319 ) + V_300 * sizeof( struct F_85 ) ,
V_307 ) ;
if ( ! V_319 ) {
V_88 = - V_275 ;
goto V_154;
}
V_319 -> V_300 = V_300 ;
if ( V_431 -> V_432 ) {
memcpy ( V_319 -> V_435 , V_431 -> V_432 -> V_435 , ( V_300 - 1 ) *
sizeof( struct F_85 ) ) ;
}
V_319 -> V_435 [ V_300 - 1 ] . V_437 = V_437 ;
V_319 -> V_435 [ V_300 - 1 ] . V_436 = V_436 ;
F_403 ( V_319 -> V_435 , V_300 , sizeof( struct F_85 ) ,
F_400 , NULL ) ;
V_319 -> V_434 = - 1 ;
for ( V_242 = 0 ; V_242 < V_300 ; V_242 ++ ) {
if ( V_319 -> V_435 [ V_242 ] . V_436 <= V_380 ) {
++ V_319 -> V_434 ;
} else
break;
}
F_267 ( V_431 -> V_447 ) ;
V_431 -> V_447 = V_431 -> V_432 ;
F_404 ( V_431 -> V_432 , V_319 ) ;
F_125 () ;
V_154:
F_211 ( & V_2 -> V_446 ) ;
return V_88 ;
}
static void F_405 ( struct V_104 * V_148 ,
struct V_292 * V_293 , struct V_444 * V_437 )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
struct V_445 * V_431 ;
struct V_429 * V_319 ;
enum V_395 type = F_370 ( V_293 -> V_219 ) ;
T_1 V_380 ;
int V_242 , V_448 , V_300 ;
F_213 ( & V_2 -> V_446 ) ;
if ( type == V_398 )
V_431 = & V_2 -> V_431 ;
else if ( type == V_396 )
V_431 = & V_2 -> V_433 ;
else
F_101 () ;
if ( ! V_431 -> V_432 )
goto V_154;
V_380 = F_368 ( V_2 , type == V_396 ) ;
F_398 ( V_2 , type == V_396 ) ;
V_300 = 0 ;
for ( V_242 = 0 ; V_242 < V_431 -> V_432 -> V_300 ; V_242 ++ ) {
if ( V_431 -> V_432 -> V_435 [ V_242 ] . V_437 != V_437 )
V_300 ++ ;
}
V_319 = V_431 -> V_447 ;
if ( ! V_300 ) {
F_267 ( V_319 ) ;
V_319 = NULL ;
goto V_449;
}
V_319 -> V_300 = V_300 ;
V_319 -> V_434 = - 1 ;
for ( V_242 = 0 , V_448 = 0 ; V_242 < V_431 -> V_432 -> V_300 ; V_242 ++ ) {
if ( V_431 -> V_432 -> V_435 [ V_242 ] . V_437 == V_437 )
continue;
V_319 -> V_435 [ V_448 ] = V_431 -> V_432 -> V_435 [ V_242 ] ;
if ( V_319 -> V_435 [ V_448 ] . V_436 <= V_380 ) {
++ V_319 -> V_434 ;
}
V_448 ++ ;
}
V_449:
V_431 -> V_447 = V_431 -> V_432 ;
if ( ! V_319 ) {
F_267 ( V_431 -> V_447 ) ;
V_431 -> V_447 = NULL ;
}
F_404 ( V_431 -> V_432 , V_319 ) ;
F_125 () ;
V_154:
F_211 ( & V_2 -> V_446 ) ;
}
static int F_406 ( struct V_104 * V_148 ,
struct V_292 * V_293 , struct V_444 * V_437 , const char * args )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
struct V_442 * V_385 ;
enum V_395 type = F_370 ( V_293 -> V_219 ) ;
F_17 ( type != V_450 ) ;
V_385 = F_292 ( sizeof( * V_385 ) , V_307 ) ;
if ( ! V_385 )
return - V_275 ;
F_48 ( & V_221 ) ;
V_385 -> V_437 = V_437 ;
F_258 ( & V_385 -> V_304 , & V_2 -> V_451 ) ;
if ( F_130 ( & V_2 -> V_205 ) )
F_399 ( V_437 , 1 ) ;
F_49 ( & V_221 ) ;
return 0 ;
}
static void F_407 ( struct V_104 * V_148 ,
struct V_292 * V_293 , struct V_444 * V_437 )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
struct V_442 * V_443 , * V_408 ;
enum V_395 type = F_370 ( V_293 -> V_219 ) ;
F_17 ( type != V_450 ) ;
F_48 ( & V_221 ) ;
F_408 (ev, tmp, &memcg->oom_notify, list) {
if ( V_443 -> V_437 == V_437 ) {
F_271 ( & V_443 -> V_304 ) ;
F_267 ( V_443 ) ;
}
}
F_49 ( & V_221 ) ;
}
static int F_409 ( struct V_104 * V_148 ,
struct V_292 * V_293 , struct V_452 * V_453 )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
V_453 -> V_454 ( V_453 , L_26 , V_2 -> V_223 ) ;
if ( F_130 ( & V_2 -> V_205 ) )
V_453 -> V_454 ( V_453 , L_27 , 1 ) ;
else
V_453 -> V_454 ( V_453 , L_27 , 0 ) ;
return 0 ;
}
static int F_410 ( struct V_104 * V_148 ,
struct V_292 * V_293 , T_1 V_66 )
{
struct V_1 * V_2 = F_87 ( V_148 ) ;
struct V_1 * V_48 ;
if ( ! V_148 -> V_48 || ! ( ( V_66 == 0 ) || ( V_66 == 1 ) ) )
return - V_338 ;
V_48 = F_87 ( V_148 -> V_48 ) ;
F_365 () ;
if ( ( V_48 -> V_116 ) ||
( V_2 -> V_116 && ! F_352 ( & V_148 -> V_368 ) ) ) {
F_366 () ;
return - V_338 ;
}
V_2 -> V_223 = V_66 ;
if ( ! V_66 )
F_187 ( V_2 ) ;
F_366 () ;
return 0 ;
}
static int F_411 ( struct V_1 * V_2 , struct V_455 * V_456 )
{
int V_88 ;
V_2 -> V_28 = - 1 ;
V_88 = F_377 ( V_2 ) ;
if ( V_88 )
return V_88 ;
return F_412 ( V_2 , V_456 ) ;
}
static void F_413 ( struct V_1 * V_2 )
{
F_414 ( V_2 ) ;
F_8 ( V_2 ) ;
if ( F_32 ( & V_2 -> V_29 , V_30 ) != 0 )
return;
if ( F_9 ( V_2 ) )
F_25 ( V_2 ) ;
}
static int F_411 ( struct V_1 * V_2 , struct V_455 * V_456 )
{
return 0 ;
}
static void F_413 ( struct V_1 * V_2 )
{
}
static int F_415 ( struct V_1 * V_2 , int V_58 )
{
struct V_457 * V_458 ;
struct V_31 * V_42 ;
int V_59 , V_408 = V_58 ;
if ( ! F_416 ( V_58 , V_459 ) )
V_408 = - 1 ;
V_458 = F_417 ( sizeof( * V_458 ) , V_307 , V_408 ) ;
if ( ! V_458 )
return 1 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_42 = & V_458 -> V_36 [ V_59 ] ;
F_418 ( & V_42 -> V_83 ) ;
V_42 -> V_51 = 0 ;
V_42 -> V_50 = false ;
V_42 -> V_2 = V_2 ;
}
V_2 -> V_34 . V_35 [ V_58 ] = V_458 ;
return 0 ;
}
static void F_419 ( struct V_1 * V_2 , int V_58 )
{
F_267 ( V_2 -> V_34 . V_35 [ V_58 ] ) ;
}
static struct V_1 * F_420 ( void )
{
struct V_1 * V_2 ;
int V_300 = sizeof( struct V_1 ) ;
if ( V_300 < V_235 )
V_2 = F_266 ( V_300 , V_307 ) ;
else
V_2 = F_421 ( V_300 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_68 = F_422 ( struct V_460 ) ;
if ( ! V_2 -> V_68 )
goto V_461;
F_423 ( & V_2 -> V_70 ) ;
return V_2 ;
V_461:
if ( V_300 < V_235 )
F_267 ( V_2 ) ;
else
F_424 ( V_2 ) ;
return NULL ;
}
static void F_425 ( struct V_1 * V_2 )
{
int V_58 ;
int V_300 = sizeof( struct V_1 ) ;
F_53 ( V_2 ) ;
F_426 ( & V_124 , & V_2 -> V_14 ) ;
F_54 (node)
F_419 ( V_2 , V_58 ) ;
F_427 ( V_2 -> V_68 ) ;
F_33 ( V_2 ) ;
if ( V_300 < V_235 )
F_267 ( V_2 ) ;
else
F_424 ( V_2 ) ;
}
static void F_428 ( struct V_236 * V_240 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_240 , struct V_1 , V_462 ) ;
F_425 ( V_2 ) ;
}
static void F_429 ( struct V_463 * V_463 )
{
struct V_1 * V_2 ;
V_2 = F_14 ( V_463 , struct V_1 , V_464 ) ;
F_289 ( & V_2 -> V_462 , F_428 ) ;
F_279 ( & V_2 -> V_462 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_86 ( & V_2 -> V_465 ) ;
}
static void F_430 ( struct V_1 * V_2 , int V_69 )
{
if ( F_431 ( V_69 , & V_2 -> V_465 ) ) {
struct V_1 * V_48 = F_51 ( V_2 ) ;
F_432 ( & V_2 -> V_464 , F_429 ) ;
if ( V_48 )
F_25 ( V_48 ) ;
}
}
static void F_25 ( struct V_1 * V_2 )
{
F_430 ( V_2 , 1 ) ;
}
struct V_1 * F_51 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_57 . V_48 )
return NULL ;
return F_220 ( V_2 -> V_57 . V_48 , V_57 ) ;
}
static void T_11 F_433 ( void )
{
if ( ! F_92 () && V_466 )
V_146 = 1 ;
}
static void T_11 F_433 ( void )
{
}
static int F_434 ( void )
{
struct V_467 * V_468 ;
struct V_38 * V_469 ;
int V_408 , V_58 , V_59 ;
F_54 (node) {
V_408 = V_58 ;
if ( ! F_416 ( V_58 , V_459 ) )
V_408 = - 1 ;
V_468 = F_417 ( sizeof( * V_468 ) , V_307 , V_408 ) ;
if ( ! V_468 )
goto V_470;
V_39 . V_40 [ V_58 ] = V_468 ;
for ( V_59 = 0 ; V_59 < V_60 ; V_59 ++ ) {
V_469 = & V_468 -> V_41 [ V_59 ] ;
V_469 -> V_47 = V_471 ;
F_423 ( & V_469 -> V_55 ) ;
}
}
return 0 ;
V_470:
F_54 (node) {
if ( ! V_39 . V_40 [ V_58 ] )
break;
F_267 ( V_39 . V_40 [ V_58 ] ) ;
V_39 . V_40 [ V_58 ] = NULL ;
}
return 1 ;
}
static struct V_12 * T_12
F_435 ( struct V_104 * V_105 )
{
struct V_1 * V_2 , * V_48 ;
long error = - V_275 ;
int V_58 ;
V_2 = F_420 () ;
if ( ! V_2 )
return F_436 ( error ) ;
F_54 (node)
if ( F_415 ( V_2 , V_58 ) )
goto V_472;
if ( V_105 -> V_48 == NULL ) {
int V_67 ;
F_433 () ;
V_48 = NULL ;
if ( F_434 () )
goto V_472;
V_15 = V_2 ;
F_437 (cpu) {
struct V_228 * V_229 =
& F_62 ( V_231 , V_67 ) ;
F_289 ( & V_229 -> V_240 , F_201 ) ;
}
} else {
V_48 = F_87 ( V_105 -> V_48 ) ;
V_2 -> V_116 = V_48 -> V_116 ;
V_2 -> V_223 = V_48 -> V_223 ;
}
if ( V_48 && V_48 -> V_116 ) {
F_438 ( & V_2 -> V_57 , & V_48 -> V_57 ) ;
F_438 ( & V_2 -> V_147 , & V_48 -> V_147 ) ;
F_438 ( & V_2 -> V_29 , & V_48 -> V_29 ) ;
F_18 ( V_48 ) ;
} else {
F_438 ( & V_2 -> V_57 , NULL ) ;
F_438 ( & V_2 -> V_147 , NULL ) ;
F_438 ( & V_2 -> V_29 , NULL ) ;
if ( V_48 && V_48 != V_15 )
V_124 . V_473 = true ;
}
V_2 -> V_199 = V_102 ;
F_189 ( & V_2 -> V_451 ) ;
if ( V_48 )
V_2 -> V_150 = F_123 ( V_48 ) ;
F_168 ( & V_2 -> V_465 , 1 ) ;
V_2 -> V_10 = 0 ;
F_262 ( & V_2 -> V_446 ) ;
F_423 ( & V_2 -> V_160 ) ;
error = F_411 ( V_2 , & V_124 ) ;
if ( error ) {
F_25 ( V_2 ) ;
return F_436 ( error ) ;
}
return & V_2 -> V_14 ;
V_472:
F_425 ( V_2 ) ;
return F_436 ( error ) ;
}
static void F_439 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
F_356 ( V_2 ) ;
F_288 ( V_2 ) ;
}
static void F_440 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = F_87 ( V_105 ) ;
F_413 ( V_2 ) ;
F_25 ( V_2 ) ;
}
static int F_441 ( unsigned long V_69 )
{
int V_88 = 0 ;
int V_474 = V_475 ;
struct V_1 * V_2 = V_8 . V_9 ;
if ( F_15 ( V_2 ) ) {
V_8 . V_476 += V_69 ;
return V_88 ;
}
if ( V_69 > 1 ) {
struct V_258 * V_237 ;
if ( F_218 ( & V_2 -> V_57 , V_235 * V_69 , & V_237 ) )
goto V_477;
if ( V_146 && F_218 ( & V_2 -> V_147 ,
V_235 * V_69 , & V_237 ) ) {
F_200 ( & V_2 -> V_57 , V_235 * V_69 ) ;
goto V_477;
}
V_8 . V_476 += V_69 ;
return V_88 ;
}
V_477:
while ( V_69 -- ) {
if ( F_346 ( V_23 ) ) {
V_88 = - V_276 ;
break;
}
if ( ! V_474 -- ) {
V_474 = V_475 ;
F_355 () ;
}
V_88 = F_222 ( NULL ,
V_307 , 1 , & V_2 , false ) ;
if ( V_88 )
return V_88 ;
V_8 . V_476 ++ ;
}
return V_88 ;
}
static struct V_37 * F_442 ( struct V_478 * V_479 ,
unsigned long V_480 , T_13 V_481 )
{
struct V_37 * V_37 = F_443 ( V_479 , V_480 , V_481 ) ;
if ( ! V_37 || ! F_304 ( V_37 ) )
return NULL ;
if ( F_302 ( V_37 ) ) {
if ( ! F_11 () )
return NULL ;
} else if ( ! F_12 () )
return NULL ;
if ( ! F_307 ( V_37 ) )
return NULL ;
return V_37 ;
}
static struct V_37 * F_444 ( struct V_478 * V_479 ,
unsigned long V_480 , T_13 V_481 , T_6 * V_356 )
{
struct V_37 * V_37 = NULL ;
T_6 V_277 = F_445 ( V_481 ) ;
if ( ! F_11 () || F_446 ( V_277 ) )
return NULL ;
V_37 = F_447 ( & V_482 , V_277 . V_66 ) ;
if ( V_146 )
V_356 -> V_66 = V_277 . V_66 ;
return V_37 ;
}
static struct V_37 * F_444 ( struct V_478 * V_479 ,
unsigned long V_480 , T_13 V_481 , T_6 * V_356 )
{
return NULL ;
}
static struct V_37 * F_448 ( struct V_478 * V_479 ,
unsigned long V_480 , T_13 V_481 , T_6 * V_356 )
{
struct V_37 * V_37 = NULL ;
struct V_483 * V_341 ;
T_14 V_484 ;
if ( ! V_479 -> V_485 )
return NULL ;
if ( ! F_12 () )
return NULL ;
V_341 = V_479 -> V_485 -> V_486 ;
if ( F_449 ( V_481 ) )
V_484 = F_450 ( V_479 , V_480 ) ;
else
V_484 = F_451 ( V_481 ) ;
V_37 = F_447 ( V_341 , V_484 ) ;
#ifdef F_452
if ( F_453 ( V_37 ) ) {
T_6 V_388 = F_454 ( V_37 ) ;
if ( V_146 )
* V_356 = V_388 ;
V_37 = F_447 ( & V_482 , V_388 . V_66 ) ;
}
#endif
return V_37 ;
}
static enum V_487 F_455 ( struct V_478 * V_479 ,
unsigned long V_480 , T_13 V_481 , union V_488 * V_91 )
{
struct V_37 * V_37 = NULL ;
struct V_131 * V_132 ;
enum V_487 V_88 = V_489 ;
T_6 V_277 = { . V_66 = 0 } ;
if ( F_456 ( V_481 ) )
V_37 = F_442 ( V_479 , V_480 , V_481 ) ;
else if ( F_457 ( V_481 ) )
V_37 = F_444 ( V_479 , V_480 , V_481 , & V_277 ) ;
else if ( F_449 ( V_481 ) || F_458 ( V_481 ) )
V_37 = F_448 ( V_479 , V_480 , V_481 , & V_277 ) ;
if ( ! V_37 && ! V_277 . V_66 )
return V_88 ;
if ( V_37 ) {
V_132 = F_104 ( V_37 ) ;
if ( F_106 ( V_132 ) && V_132 -> V_1 == V_8 . V_153 ) {
V_88 = V_490 ;
if ( V_91 )
V_91 -> V_37 = V_37 ;
}
if ( ! V_88 || ! V_91 )
F_313 ( V_37 ) ;
}
if ( V_277 . V_66 && ! V_88 &&
F_93 ( & V_8 . V_153 -> V_14 ) == F_234 ( V_277 ) ) {
V_88 = V_491 ;
if ( V_91 )
V_91 -> V_277 = V_277 ;
}
return V_88 ;
}
static enum V_487 F_459 ( struct V_478 * V_479 ,
unsigned long V_480 , T_15 V_492 , union V_488 * V_91 )
{
struct V_37 * V_37 = NULL ;
struct V_131 * V_132 ;
enum V_487 V_88 = V_489 ;
V_37 = F_460 ( V_492 ) ;
F_108 ( ! V_37 || ! F_461 ( V_37 ) ) ;
if ( ! F_11 () )
return V_88 ;
V_132 = F_104 ( V_37 ) ;
if ( F_106 ( V_132 ) && V_132 -> V_1 == V_8 . V_153 ) {
V_88 = V_490 ;
if ( V_91 ) {
F_462 ( V_37 ) ;
V_91 -> V_37 = V_37 ;
}
}
return V_88 ;
}
static inline enum V_487 F_459 ( struct V_478 * V_479 ,
unsigned long V_480 , T_15 V_492 , union V_488 * V_91 )
{
return V_489 ;
}
static int F_463 ( T_15 * V_492 ,
unsigned long V_480 , unsigned long V_493 ,
struct V_494 * V_495 )
{
struct V_478 * V_479 = V_495 -> V_219 ;
T_13 * V_496 ;
T_16 * V_497 ;
if ( F_464 ( V_492 , V_479 ) == 1 ) {
if ( F_459 ( V_479 , V_480 , * V_492 , NULL ) == V_490 )
V_8 . V_476 += V_335 ;
F_49 ( & V_479 -> V_498 -> V_499 ) ;
return 0 ;
}
if ( F_465 ( V_492 ) )
return 0 ;
V_496 = F_466 ( V_479 -> V_498 , V_492 , V_480 , & V_497 ) ;
for (; V_480 != V_493 ; V_496 ++ , V_480 += V_235 )
if ( F_455 ( V_479 , V_480 , * V_496 , NULL ) )
V_8 . V_476 ++ ;
F_467 ( V_496 - 1 , V_497 ) ;
F_355 () ;
return 0 ;
}
static unsigned long F_468 ( struct V_108 * V_109 )
{
unsigned long V_476 ;
struct V_478 * V_479 ;
F_469 ( & V_109 -> V_500 ) ;
for ( V_479 = V_109 -> V_501 ; V_479 ; V_479 = V_479 -> V_502 ) {
struct V_494 V_503 = {
. V_504 = F_463 ,
. V_109 = V_109 ,
. V_219 = V_479 ,
} ;
if ( F_470 ( V_479 ) )
continue;
F_471 ( V_479 -> V_505 , V_479 -> V_506 ,
& V_503 ) ;
}
F_472 ( & V_109 -> V_500 ) ;
V_476 = V_8 . V_476 ;
V_8 . V_476 = 0 ;
return V_476 ;
}
static int F_473 ( struct V_108 * V_109 )
{
unsigned long V_476 = F_468 ( V_109 ) ;
F_108 ( V_8 . V_155 ) ;
V_8 . V_155 = V_23 ;
return F_441 ( V_476 ) ;
}
static void F_474 ( void )
{
struct V_1 * V_153 = V_8 . V_153 ;
struct V_1 * V_9 = V_8 . V_9 ;
if ( V_8 . V_476 ) {
F_224 ( V_8 . V_9 , V_8 . V_476 ) ;
V_8 . V_476 = 0 ;
}
if ( V_8 . V_507 ) {
F_224 ( V_8 . V_153 , V_8 . V_507 ) ;
V_8 . V_507 = 0 ;
}
if ( V_8 . V_508 ) {
if ( ! F_15 ( V_8 . V_153 ) )
F_200 ( & V_8 . V_153 -> V_147 ,
V_235 * V_8 . V_508 ) ;
F_430 ( V_8 . V_153 , V_8 . V_508 ) ;
if ( ! F_15 ( V_8 . V_9 ) ) {
F_200 ( & V_8 . V_9 -> V_57 ,
V_235 * V_8 . V_508 ) ;
}
V_8 . V_508 = 0 ;
}
F_187 ( V_153 ) ;
F_187 ( V_9 ) ;
F_475 ( & V_8 . V_157 ) ;
}
static void F_476 ( void )
{
struct V_1 * V_153 = V_8 . V_153 ;
V_8 . V_155 = NULL ;
F_474 () ;
F_48 ( & V_8 . V_55 ) ;
V_8 . V_153 = NULL ;
V_8 . V_9 = NULL ;
F_49 ( & V_8 . V_55 ) ;
F_126 ( V_153 ) ;
}
static int F_477 ( struct V_104 * V_104 ,
struct V_509 * V_510 )
{
struct V_107 * V_46 = F_478 ( V_510 ) ;
int V_88 = 0 ;
struct V_1 * V_2 = F_87 ( V_104 ) ;
if ( V_2 -> V_10 ) {
struct V_108 * V_109 ;
struct V_1 * V_153 = F_20 ( V_46 ) ;
F_108 ( V_153 == V_2 ) ;
V_109 = F_479 ( V_46 ) ;
if ( ! V_109 )
return 0 ;
if ( V_109 -> V_110 == V_46 ) {
F_108 ( V_8 . V_153 ) ;
F_108 ( V_8 . V_9 ) ;
F_108 ( V_8 . V_476 ) ;
F_108 ( V_8 . V_507 ) ;
F_108 ( V_8 . V_508 ) ;
F_124 ( V_153 ) ;
F_48 ( & V_8 . V_55 ) ;
V_8 . V_153 = V_153 ;
V_8 . V_9 = V_2 ;
F_49 ( & V_8 . V_55 ) ;
V_88 = F_473 ( V_109 ) ;
if ( V_88 )
F_476 () ;
}
F_480 ( V_109 ) ;
}
return V_88 ;
}
static void F_481 ( struct V_104 * V_104 ,
struct V_509 * V_510 )
{
F_476 () ;
}
static int F_482 ( T_15 * V_492 ,
unsigned long V_480 , unsigned long V_493 ,
struct V_494 * V_495 )
{
int V_88 = 0 ;
struct V_478 * V_479 = V_495 -> V_219 ;
T_13 * V_496 ;
T_16 * V_497 ;
enum V_487 V_511 ;
union V_488 V_91 ;
struct V_37 * V_37 ;
struct V_131 * V_132 ;
if ( F_464 ( V_492 , V_479 ) == 1 ) {
if ( V_8 . V_476 < V_335 ) {
F_49 ( & V_479 -> V_498 -> V_499 ) ;
return 0 ;
}
V_511 = F_459 ( V_479 , V_480 , * V_492 , & V_91 ) ;
if ( V_511 == V_490 ) {
V_37 = V_91 . V_37 ;
if ( ! F_308 ( V_37 ) ) {
V_132 = F_104 ( V_37 ) ;
if ( ! F_301 ( V_37 , V_335 ,
V_132 , V_8 . V_153 , V_8 . V_9 ) ) {
V_8 . V_476 -= V_335 ;
V_8 . V_507 += V_335 ;
}
F_312 ( V_37 ) ;
}
F_313 ( V_37 ) ;
}
F_49 ( & V_479 -> V_498 -> V_499 ) ;
return 0 ;
}
if ( F_465 ( V_492 ) )
return 0 ;
V_62:
V_496 = F_466 ( V_479 -> V_498 , V_492 , V_480 , & V_497 ) ;
for (; V_480 != V_493 ; V_480 += V_235 ) {
T_13 V_481 = * ( V_496 ++ ) ;
T_6 V_277 ;
if ( ! V_8 . V_476 )
break;
switch ( F_455 ( V_479 , V_480 , V_481 , & V_91 ) ) {
case V_490 :
V_37 = V_91 . V_37 ;
if ( F_308 ( V_37 ) )
goto V_340;
V_132 = F_104 ( V_37 ) ;
if ( ! F_301 ( V_37 , 1 , V_132 ,
V_8 . V_153 , V_8 . V_9 ) ) {
V_8 . V_476 -- ;
V_8 . V_507 ++ ;
}
F_312 ( V_37 ) ;
V_340:
F_313 ( V_37 ) ;
break;
case V_491 :
V_277 = V_91 . V_277 ;
if ( ! F_335 ( V_277 , V_8 . V_153 , V_8 . V_9 ) ) {
V_8 . V_476 -- ;
V_8 . V_508 ++ ;
}
break;
default:
break;
}
}
F_467 ( V_496 - 1 , V_497 ) ;
F_355 () ;
if ( V_480 != V_493 ) {
V_88 = F_441 ( 1 ) ;
if ( ! V_88 )
goto V_62;
}
return V_88 ;
}
static void F_483 ( struct V_108 * V_109 )
{
struct V_478 * V_479 ;
F_357 () ;
V_62:
if ( F_84 ( ! F_484 ( & V_109 -> V_500 ) ) ) {
F_474 () ;
F_355 () ;
goto V_62;
}
for ( V_479 = V_109 -> V_501 ; V_479 ; V_479 = V_479 -> V_502 ) {
int V_88 ;
struct V_494 V_512 = {
. V_504 = F_482 ,
. V_109 = V_109 ,
. V_219 = V_479 ,
} ;
if ( F_470 ( V_479 ) )
continue;
V_88 = F_471 ( V_479 -> V_505 , V_479 -> V_506 ,
& V_512 ) ;
if ( V_88 )
break;
}
F_472 ( & V_109 -> V_500 ) ;
}
static void F_485 ( struct V_104 * V_105 ,
struct V_509 * V_510 )
{
struct V_107 * V_46 = F_478 ( V_510 ) ;
struct V_108 * V_109 = F_479 ( V_46 ) ;
if ( V_109 ) {
if ( V_8 . V_9 )
F_483 ( V_109 ) ;
F_480 ( V_109 ) ;
}
if ( V_8 . V_9 )
F_476 () ;
}
static int F_477 ( struct V_104 * V_104 ,
struct V_509 * V_510 )
{
return 0 ;
}
static void F_481 ( struct V_104 * V_104 ,
struct V_509 * V_510 )
{
}
static void F_485 ( struct V_104 * V_105 ,
struct V_509 * V_510 )
{
}
static int T_11 F_486 ( void )
{
F_487 ( F_215 , 0 ) ;
return 0 ;
}
static int T_11 F_488 ( char * V_13 )
{
if ( ! strcmp ( V_13 , L_28 ) )
V_466 = 1 ;
else if ( ! strcmp ( V_13 , L_29 ) )
V_466 = 0 ;
return 1 ;
}
