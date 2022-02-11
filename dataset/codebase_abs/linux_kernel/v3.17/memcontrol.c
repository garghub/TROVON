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
unsigned long V_57 ;
F_54 ( & V_45 -> V_58 , V_57 ) ;
F_51 ( V_44 , V_45 ) ;
F_55 ( & V_45 -> V_58 , V_57 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_39 * V_39 )
{
unsigned long long V_59 ;
struct V_33 * V_44 ;
struct V_40 * V_45 ;
V_45 = F_46 ( V_39 ) ;
for (; V_2 ; V_2 = F_57 ( V_2 ) ) {
V_44 = F_42 ( V_2 , V_39 ) ;
V_59 = F_58 ( & V_2 -> V_60 ) ;
if ( V_59 || V_44 -> V_52 ) {
unsigned long V_57 ;
F_54 ( & V_45 -> V_58 , V_57 ) ;
if ( V_44 -> V_52 )
F_51 ( V_44 , V_45 ) ;
F_47 ( V_44 , V_45 , V_59 ) ;
F_55 ( & V_45 -> V_58 , V_57 ) ;
}
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_40 * V_45 ;
struct V_33 * V_44 ;
int V_35 , V_36 ;
F_60 (nid) {
for ( V_36 = 0 ; V_36 < V_61 ; V_36 ++ ) {
V_44 = & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
V_45 = F_45 ( V_35 , V_36 ) ;
F_53 ( V_44 , V_45 ) ;
}
}
}
static struct V_33 *
F_61 ( struct V_40 * V_45 )
{
struct V_47 * V_62 = NULL ;
struct V_33 * V_44 ;
V_63:
V_44 = NULL ;
V_62 = F_62 ( & V_45 -> V_49 ) ;
if ( ! V_62 )
goto V_64;
V_44 = F_48 ( V_62 , struct V_33 , V_54 ) ;
F_51 ( V_44 , V_45 ) ;
if ( ! F_58 ( & V_44 -> V_2 -> V_60 ) ||
! F_25 ( & V_44 -> V_2 -> V_12 ) )
goto V_63;
V_64:
return V_44 ;
}
static struct V_33 *
F_63 ( struct V_40 * V_45 )
{
struct V_33 * V_44 ;
F_64 ( & V_45 -> V_58 ) ;
V_44 = F_61 ( V_45 ) ;
F_65 ( & V_45 -> V_58 ) ;
return V_44 ;
}
static long F_66 ( struct V_1 * V_2 ,
enum V_65 V_66 )
{
long V_67 = 0 ;
int V_68 ;
F_67 () ;
F_68 (cpu)
V_67 += F_69 ( V_2 -> V_69 -> V_70 [ V_66 ] , V_68 ) ;
#ifdef F_70
F_71 ( & V_2 -> V_71 ) ;
V_67 += V_2 -> V_72 . V_70 [ V_66 ] ;
F_72 ( & V_2 -> V_71 ) ;
#endif
F_73 () ;
return V_67 ;
}
static unsigned long F_74 ( struct V_1 * V_2 ,
enum V_73 V_66 )
{
unsigned long V_67 = 0 ;
int V_68 ;
F_67 () ;
F_68 (cpu)
V_67 += F_69 ( V_2 -> V_69 -> V_74 [ V_66 ] , V_68 ) ;
#ifdef F_70
F_71 ( & V_2 -> V_71 ) ;
V_67 += V_2 -> V_72 . V_74 [ V_66 ] ;
F_72 ( & V_2 -> V_71 ) ;
#endif
F_73 () ;
return V_67 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_39 * V_39 ,
int V_75 )
{
if ( F_76 ( V_39 ) )
F_77 ( V_2 -> V_69 -> V_70 [ V_76 ] ,
V_75 ) ;
else
F_77 ( V_2 -> V_69 -> V_70 [ V_77 ] ,
V_75 ) ;
if ( F_78 ( V_39 ) )
F_77 ( V_2 -> V_69 -> V_70 [ V_78 ] ,
V_75 ) ;
if ( V_75 > 0 )
F_79 ( V_2 -> V_69 -> V_74 [ V_79 ] ) ;
else {
F_79 ( V_2 -> V_69 -> V_74 [ V_80 ] ) ;
V_75 = - V_75 ;
}
F_77 ( V_2 -> V_69 -> V_81 , V_75 ) ;
}
unsigned long F_80 ( struct V_82 * V_82 , enum V_83 V_84 )
{
struct V_33 * V_44 ;
V_44 = F_12 ( V_82 , struct V_33 , V_82 ) ;
return V_44 -> V_85 [ V_84 ] ;
}
static unsigned long F_81 ( struct V_1 * V_2 ,
int V_35 ,
unsigned int V_86 )
{
unsigned long V_87 = 0 ;
int V_36 ;
F_82 ( ( unsigned ) V_35 >= V_88 ) ;
for ( V_36 = 0 ; V_36 < V_61 ; V_36 ++ ) {
struct V_33 * V_44 ;
enum V_83 V_84 ;
F_83 (lru) {
if ( ! ( F_84 ( V_84 ) & V_86 ) )
continue;
V_44 = & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
V_87 += V_44 -> V_85 [ V_84 ] ;
}
}
return V_87 ;
}
static unsigned long F_85 ( struct V_1 * V_2 ,
unsigned int V_86 )
{
unsigned long V_87 = 0 ;
int V_35 ;
F_86 (nid, N_MEMORY)
V_87 += F_81 ( V_2 , V_35 , V_86 ) ;
return V_87 ;
}
static bool F_87 ( struct V_1 * V_2 ,
enum V_89 V_90 )
{
unsigned long V_67 , V_91 ;
V_67 = F_88 ( V_2 -> V_69 -> V_81 ) ;
V_91 = F_88 ( V_2 -> V_69 -> V_92 [ V_90 ] ) ;
if ( ( long ) V_91 - ( long ) V_67 < 0 ) {
switch ( V_90 ) {
case V_93 :
V_91 = V_67 + V_94 ;
break;
case V_95 :
V_91 = V_67 + V_96 ;
break;
case V_97 :
V_91 = V_67 + V_98 ;
break;
default:
break;
}
F_89 ( V_2 -> V_69 -> V_92 [ V_90 ] , V_91 ) ;
return true ;
}
return false ;
}
static void F_90 ( struct V_1 * V_2 , struct V_39 * V_39 )
{
if ( F_91 ( F_87 ( V_2 ,
V_93 ) ) ) {
bool V_99 ;
bool T_1 V_100 ;
V_99 = F_87 ( V_2 ,
V_95 ) ;
#if V_101 > 1
T_1 = F_87 ( V_2 ,
V_97 ) ;
#endif
F_92 ( V_2 ) ;
if ( F_91 ( V_99 ) )
F_56 ( V_2 , V_39 ) ;
#if V_101 > 1
if ( F_91 ( T_1 ) )
F_93 ( & V_2 -> V_102 ) ;
#endif
}
}
struct V_1 * F_23 ( struct V_103 * V_48 )
{
if ( F_91 ( ! V_48 ) )
return NULL ;
return F_11 ( F_94 ( V_48 , V_104 ) ) ;
}
static struct V_1 * F_95 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = NULL ;
F_22 () ;
do {
if ( F_91 ( ! V_106 ) )
V_2 = V_14 ;
else {
V_2 = F_23 ( F_96 ( V_106 -> V_107 ) ) ;
if ( F_91 ( ! V_2 ) )
V_2 = V_14 ;
}
} while ( ! F_25 ( & V_2 -> V_12 ) );
F_26 () ;
return V_2 ;
}
static struct V_1 * F_97 ( struct V_1 * V_108 ,
struct V_1 * V_109 )
{
struct V_10 * V_110 , * V_111 ;
V_110 = V_109 ? & V_109 -> V_12 : NULL ;
V_112:
V_111 = F_98 ( V_110 , & V_108 -> V_12 ) ;
if ( V_111 ) {
struct V_1 * V_2 = F_11 ( V_111 ) ;
if ( V_111 == & V_108 -> V_12 )
return V_2 ;
if ( F_25 ( V_111 ) ) {
if ( F_99 ( & V_2 -> V_113 ) )
return V_2 ;
F_29 ( V_111 ) ;
}
V_110 = V_111 ;
goto V_112;
}
return NULL ;
}
static void F_100 ( struct V_1 * V_108 )
{
F_93 ( & V_108 -> V_114 ) ;
}
static struct V_1 *
F_101 ( struct V_115 * V_116 ,
struct V_1 * V_108 ,
int * V_117 )
{
struct V_1 * V_118 = NULL ;
* V_117 = F_102 ( & V_108 -> V_114 ) ;
if ( V_116 -> V_119 == * V_117 ) {
F_103 () ;
V_118 = V_116 -> V_109 ;
if ( V_118 && V_118 != V_108 &&
! F_25 ( & V_118 -> V_12 ) )
V_118 = NULL ;
}
return V_118 ;
}
static void F_104 ( struct V_115 * V_116 ,
struct V_1 * V_109 ,
struct V_1 * V_120 ,
struct V_1 * V_108 ,
int V_117 )
{
if ( V_109 && V_109 != V_108 )
F_29 ( & V_109 -> V_12 ) ;
V_116 -> V_109 = V_120 ;
F_6 () ;
V_116 -> V_119 = V_117 ;
}
struct V_1 * F_105 ( struct V_1 * V_108 ,
struct V_1 * V_121 ,
struct V_122 * V_123 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_109 = NULL ;
if ( F_106 () )
return NULL ;
if ( ! V_108 )
V_108 = V_14 ;
if ( V_121 && ! V_123 )
V_109 = V_121 ;
if ( ! V_108 -> V_124 && V_108 != V_14 ) {
if ( V_121 )
goto V_125;
return V_108 ;
}
F_22 () ;
while ( ! V_2 ) {
struct V_115 * V_126 ( V_116 ) ;
int V_126 ( V_127 ) ;
if ( V_123 ) {
struct V_33 * V_44 ;
V_44 = F_38 ( V_108 , V_123 -> V_34 ) ;
V_116 = & V_44 -> V_128 [ V_123 -> V_129 ] ;
if ( V_121 && V_123 -> V_130 != V_116 -> V_130 ) {
V_116 -> V_109 = NULL ;
goto V_131;
}
V_109 = F_101 ( V_116 , V_108 , & V_127 ) ;
}
V_2 = F_97 ( V_108 , V_109 ) ;
if ( V_123 ) {
F_104 ( V_116 , V_109 , V_2 , V_108 ,
V_127 ) ;
if ( ! V_2 )
V_116 -> V_130 ++ ;
else if ( ! V_121 && V_2 )
V_123 -> V_130 = V_116 -> V_130 ;
}
if ( V_121 && ! V_2 )
goto V_131;
}
V_131:
F_26 () ;
V_125:
if ( V_121 && V_121 != V_108 )
F_29 ( & V_121 -> V_12 ) ;
return V_2 ;
}
void F_107 ( struct V_1 * V_108 ,
struct V_1 * V_121 )
{
if ( ! V_108 )
V_108 = V_14 ;
if ( V_121 && V_121 != V_108 )
F_29 ( & V_121 -> V_12 ) ;
}
void F_108 ( struct V_105 * V_106 , enum V_132 V_66 )
{
struct V_1 * V_2 ;
F_22 () ;
V_2 = F_23 ( F_96 ( V_106 -> V_107 ) ) ;
if ( F_91 ( ! V_2 ) )
goto V_133;
switch ( V_66 ) {
case V_134 :
F_109 ( V_2 -> V_69 -> V_74 [ V_135 ] ) ;
break;
case V_136 :
F_109 ( V_2 -> V_69 -> V_74 [ V_137 ] ) ;
break;
default:
F_110 () ;
}
V_133:
F_26 () ;
}
struct V_82 * F_111 ( struct V_34 * V_34 ,
struct V_1 * V_2 )
{
struct V_33 * V_44 ;
struct V_82 * V_82 ;
if ( F_106 () ) {
V_82 = & V_34 -> V_82 ;
goto V_133;
}
V_44 = F_38 ( V_2 , V_34 ) ;
V_82 = & V_44 -> V_82 ;
V_133:
if ( F_91 ( V_82 -> V_34 != V_34 ) )
V_82 -> V_34 = V_34 ;
return V_82 ;
}
struct V_82 * F_112 ( struct V_39 * V_39 , struct V_34 * V_34 )
{
struct V_33 * V_44 ;
struct V_1 * V_2 ;
struct V_138 * V_139 ;
struct V_82 * V_82 ;
if ( F_106 () ) {
V_82 = & V_34 -> V_82 ;
goto V_133;
}
V_139 = F_113 ( V_39 ) ;
V_2 = V_139 -> V_1 ;
if ( ! F_114 ( V_39 ) && ! F_115 ( V_139 ) && V_2 != V_14 )
V_139 -> V_1 = V_2 = V_14 ;
V_44 = F_42 ( V_2 , V_39 ) ;
V_82 = & V_44 -> V_82 ;
V_133:
if ( F_91 ( V_82 -> V_34 != V_34 ) )
V_82 -> V_34 = V_34 ;
return V_82 ;
}
void F_116 ( struct V_82 * V_82 , enum V_83 V_84 ,
int V_75 )
{
struct V_33 * V_44 ;
unsigned long * V_85 ;
if ( F_106 () )
return;
V_44 = F_12 ( V_82 , struct V_33 , V_82 ) ;
V_85 = V_44 -> V_85 + V_84 ;
* V_85 += V_75 ;
F_82 ( ( long ) ( * V_85 ) < 0 ) ;
}
bool F_117 ( const struct V_1 * V_140 ,
struct V_1 * V_2 )
{
if ( V_140 == V_2 )
return true ;
if ( ! V_140 -> V_124 || ! V_2 )
return false ;
return F_118 ( V_2 -> V_12 . V_141 , V_140 -> V_12 . V_141 ) ;
}
static bool F_119 ( const struct V_1 * V_140 ,
struct V_1 * V_2 )
{
bool V_142 ;
F_22 () ;
V_142 = F_117 ( V_140 , V_2 ) ;
F_26 () ;
return V_142 ;
}
bool F_120 ( struct V_103 * V_143 ,
const struct V_1 * V_2 )
{
struct V_1 * V_144 = NULL ;
struct V_103 * V_48 ;
bool V_142 ;
V_48 = F_121 ( V_143 ) ;
if ( V_48 ) {
V_144 = F_95 ( V_48 -> V_106 ) ;
F_122 ( V_48 ) ;
} else {
F_22 () ;
V_144 = F_23 ( V_143 ) ;
if ( V_144 )
F_21 ( & V_144 -> V_12 ) ;
F_26 () ;
}
V_142 = F_119 ( V_2 , V_144 ) ;
F_29 ( & V_144 -> V_12 ) ;
return V_142 ;
}
int F_123 ( struct V_82 * V_82 )
{
unsigned long V_145 ;
unsigned long V_146 ;
unsigned long V_147 ;
unsigned long V_148 ;
V_146 = F_80 ( V_82 , V_149 ) ;
V_147 = F_80 ( V_82 , V_150 ) ;
V_148 = ( V_146 + V_147 ) >> ( 30 - V_151 ) ;
if ( V_148 )
V_145 = F_124 ( 10 * V_148 ) ;
else
V_145 = 1 ;
return V_146 * V_145 < V_147 ;
}
static unsigned long F_125 ( struct V_1 * V_2 )
{
unsigned long long V_152 ;
V_152 = F_126 ( & V_2 -> V_60 ) ;
if ( V_153 )
V_152 = F_127 ( V_152 , F_126 ( & V_2 -> V_154 ) ) ;
return V_152 >> V_151 ;
}
int F_128 ( struct V_1 * V_2 )
{
if ( F_106 () || ! V_2 -> V_12 . V_50 )
return V_155 ;
return V_2 -> V_156 ;
}
static void F_129 ( struct V_1 * V_2 )
{
F_93 ( & V_157 ) ;
F_93 ( & V_2 -> V_158 ) ;
F_130 () ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( V_2 ) {
F_132 ( & V_157 ) ;
F_132 ( & V_2 -> V_158 ) ;
}
}
static bool F_133 ( struct V_1 * V_2 )
{
struct V_1 * V_159 ;
struct V_1 * V_160 ;
bool V_142 = false ;
F_71 ( & V_7 . V_58 ) ;
V_159 = V_7 . V_159 ;
V_160 = V_7 . V_160 ;
if ( ! V_159 )
goto V_161;
V_142 = F_119 ( V_2 , V_159 )
|| F_119 ( V_2 , V_160 ) ;
V_161:
F_72 ( & V_7 . V_58 ) ;
return V_142 ;
}
static bool F_134 ( struct V_1 * V_2 )
{
if ( V_7 . V_162 && V_25 != V_7 . V_162 ) {
if ( F_133 ( V_2 ) ) {
F_135 ( V_163 ) ;
F_136 ( & V_7 . V_164 , & V_163 , V_165 ) ;
if ( V_7 . V_162 )
F_137 () ;
F_138 ( & V_7 . V_164 , & V_163 ) ;
return true ;
}
}
return false ;
}
static void F_139 ( struct V_1 * V_2 ,
unsigned long * V_57 )
{
F_54 ( & V_2 -> V_166 , * V_57 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
unsigned long * V_57 )
{
F_55 ( & V_2 -> V_166 , * V_57 ) ;
}
void F_141 ( struct V_1 * V_2 , struct V_103 * V_48 )
{
static F_142 ( V_167 ) ;
struct V_1 * V_116 ;
unsigned int V_168 ;
if ( ! V_48 )
return;
F_143 ( & V_167 ) ;
F_22 () ;
F_144 ( L_1 ) ;
F_145 ( F_146 ( V_48 , V_104 ) ) ;
F_144 ( L_2 ) ;
F_145 ( V_2 -> V_12 . V_141 ) ;
F_144 ( L_3 ) ;
F_26 () ;
F_144 ( L_4 ,
F_36 ( & V_2 -> V_60 , V_32 ) >> 10 ,
F_36 ( & V_2 -> V_60 , V_169 ) >> 10 ,
F_36 ( & V_2 -> V_60 , V_170 ) ) ;
F_144 ( L_5 ,
F_36 ( & V_2 -> V_154 , V_32 ) >> 10 ,
F_36 ( & V_2 -> V_154 , V_169 ) >> 10 ,
F_36 ( & V_2 -> V_154 , V_170 ) ) ;
F_144 ( L_6 ,
F_36 ( & V_2 -> V_31 , V_32 ) >> 10 ,
F_36 ( & V_2 -> V_31 , V_169 ) >> 10 ,
F_36 ( & V_2 -> V_31 , V_170 ) ) ;
F_147 (iter, memcg) {
F_144 ( L_7 ) ;
F_145 ( V_116 -> V_12 . V_141 ) ;
F_148 ( L_8 ) ;
for ( V_168 = 0 ; V_168 < V_171 ; V_168 ++ ) {
if ( V_168 == V_172 && ! V_153 )
continue;
F_148 ( L_9 , V_173 [ V_168 ] ,
F_149 ( F_66 ( V_116 , V_168 ) ) ) ;
}
for ( V_168 = 0 ; V_168 < V_174 ; V_168 ++ )
F_148 ( L_10 , V_175 [ V_168 ] ,
F_149 ( F_85 ( V_116 , F_84 ( V_168 ) ) ) ) ;
F_148 ( L_3 ) ;
}
F_150 ( & V_167 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_176 = 0 ;
struct V_1 * V_116 ;
F_147 (iter, memcg)
V_176 ++ ;
return V_176 ;
}
static T_2 F_152 ( struct V_1 * V_2 )
{
T_2 V_177 ;
V_177 = F_36 ( & V_2 -> V_60 , V_169 ) ;
if ( F_128 ( V_2 ) ) {
T_2 V_154 ;
V_177 += V_178 << V_151 ;
V_154 = F_36 ( & V_2 -> V_154 , V_169 ) ;
V_177 = F_127 ( V_177 , V_154 ) ;
}
return V_177 ;
}
static void F_153 ( struct V_1 * V_2 , T_3 V_179 ,
int V_180 )
{
struct V_1 * V_116 ;
unsigned long V_181 = 0 ;
unsigned long V_182 ;
unsigned int V_183 = 0 ;
struct V_103 * V_184 = NULL ;
if ( F_154 ( V_25 ) || V_25 -> V_57 & V_185 ) {
F_155 ( V_186 ) ;
return;
}
F_156 ( V_187 , V_179 , V_180 , NULL ) ;
V_182 = F_152 ( V_2 ) >> V_151 ? : 1 ;
F_147 (iter, memcg) {
struct V_188 V_189 ;
struct V_103 * V_143 ;
F_157 ( & V_116 -> V_12 , & V_189 ) ;
while ( ( V_143 = F_158 ( & V_189 ) ) ) {
switch ( F_159 ( V_143 , V_182 , NULL ,
false ) ) {
case V_190 :
if ( V_184 )
F_160 ( V_184 ) ;
V_184 = V_143 ;
V_181 = V_191 ;
F_161 ( V_184 ) ;
case V_192 :
continue;
case V_193 :
F_162 ( & V_189 ) ;
F_107 ( V_2 , V_116 ) ;
if ( V_184 )
F_160 ( V_184 ) ;
return;
case V_194 :
break;
} ;
V_183 = F_163 ( V_143 , V_2 , NULL , V_182 ) ;
if ( ! V_183 || V_183 < V_181 )
continue;
if ( V_183 == V_181 &&
F_164 ( V_184 ) )
continue;
if ( V_184 )
F_160 ( V_184 ) ;
V_184 = V_143 ;
V_181 = V_183 ;
F_161 ( V_184 ) ;
}
F_162 ( & V_189 ) ;
}
if ( ! V_184 )
return;
V_183 = V_181 * 1000 / V_182 ;
F_165 ( V_184 , V_179 , V_180 , V_183 , V_182 , V_2 ,
NULL , L_11 ) ;
}
static unsigned long F_166 ( struct V_1 * V_2 ,
T_3 V_179 ,
unsigned long V_57 )
{
unsigned long V_195 = 0 ;
bool V_196 = false ;
int V_197 ;
if ( V_57 & V_198 )
V_196 = true ;
if ( ! ( V_57 & V_199 ) && V_2 -> V_200 )
V_196 = true ;
for ( V_197 = 0 ; V_197 < V_201 ; V_197 ++ ) {
if ( V_197 )
F_167 ( V_2 ) ;
V_195 += F_168 ( V_2 , V_179 , V_196 ) ;
if ( V_195 && ( V_57 & V_199 ) )
break;
if ( F_125 ( V_2 ) )
break;
if ( V_197 && ! V_195 )
break;
}
return V_195 ;
}
static bool F_169 ( struct V_1 * V_2 ,
int V_35 , bool V_196 )
{
if ( F_81 ( V_2 , V_35 , V_202 ) )
return true ;
if ( V_196 || ! V_178 )
return false ;
if ( F_81 ( V_2 , V_35 , V_203 ) )
return true ;
return false ;
}
static void F_170 ( struct V_1 * V_2 )
{
int V_35 ;
if ( ! F_102 ( & V_2 -> V_102 ) )
return;
if ( F_171 ( & V_2 -> V_204 ) > 1 )
return;
V_2 -> V_205 = V_206 [ V_207 ] ;
F_172 (nid, node_states[N_MEMORY]) {
if ( ! F_169 ( V_2 , V_35 , false ) )
F_173 ( V_35 , V_2 -> V_205 ) ;
}
F_174 ( & V_2 -> V_102 , 0 ) ;
F_174 ( & V_2 -> V_204 , 0 ) ;
}
int F_175 ( struct V_1 * V_2 )
{
int V_208 ;
F_170 ( V_2 ) ;
V_208 = V_2 -> V_209 ;
V_208 = F_176 ( V_208 , V_2 -> V_205 ) ;
if ( V_208 == V_101 )
V_208 = F_177 ( V_2 -> V_205 ) ;
if ( F_91 ( V_208 == V_101 ) )
V_208 = F_178 () ;
V_2 -> V_209 = V_208 ;
return V_208 ;
}
static bool F_179 ( struct V_1 * V_2 , bool V_196 )
{
int V_35 ;
if ( ! F_180 ( V_2 -> V_205 ) ) {
for ( V_35 = F_177 ( V_2 -> V_205 ) ;
V_35 < V_101 ;
V_35 = F_176 ( V_35 , V_2 -> V_205 ) ) {
if ( F_169 ( V_2 , V_35 , V_196 ) )
return true ;
}
}
F_86 (nid, N_MEMORY) {
if ( F_181 ( V_35 , V_2 -> V_205 ) )
continue;
if ( F_169 ( V_2 , V_35 , V_196 ) )
return true ;
}
return false ;
}
int F_175 ( struct V_1 * V_2 )
{
return 0 ;
}
static bool F_179 ( struct V_1 * V_2 , bool V_196 )
{
return F_169 ( V_2 , 0 , V_196 ) ;
}
static int F_182 ( struct V_1 * V_140 ,
struct V_34 * V_34 ,
T_3 V_179 ,
unsigned long * V_210 )
{
struct V_1 * V_211 = NULL ;
int V_195 = 0 ;
int V_197 = 0 ;
unsigned long V_59 ;
unsigned long V_212 ;
struct V_122 V_123 = {
. V_34 = V_34 ,
. V_129 = 0 ,
} ;
V_59 = F_58 ( & V_140 -> V_60 ) >> V_151 ;
while ( 1 ) {
V_211 = F_105 ( V_140 , V_211 , & V_123 ) ;
if ( ! V_211 ) {
V_197 ++ ;
if ( V_197 >= 2 ) {
if ( ! V_195 )
break;
if ( V_195 >= ( V_59 >> 2 ) ||
( V_197 > V_201 ) )
break;
}
continue;
}
if ( ! F_179 ( V_211 , false ) )
continue;
V_195 += F_183 ( V_211 , V_179 , false ,
V_34 , & V_212 ) ;
* V_210 += V_212 ;
if ( ! F_58 ( & V_140 -> V_60 ) )
break;
}
F_107 ( V_140 , V_211 ) ;
return V_195 ;
}
static bool F_184 ( struct V_1 * V_2 )
{
struct V_1 * V_116 , * V_213 = NULL ;
F_71 ( & V_214 ) ;
F_147 (iter, memcg) {
if ( V_116 -> V_215 ) {
V_213 = V_116 ;
F_107 ( V_2 , V_116 ) ;
break;
} else
V_116 -> V_215 = true ;
}
if ( V_213 ) {
F_147 (iter, memcg) {
if ( V_116 == V_213 ) {
F_107 ( V_2 , V_116 ) ;
break;
}
V_116 -> V_215 = false ;
}
} else
F_185 ( & V_216 , 0 , 1 , V_217 ) ;
F_72 ( & V_214 ) ;
return ! V_213 ;
}
static void F_186 ( struct V_1 * V_2 )
{
struct V_1 * V_116 ;
F_71 ( & V_214 ) ;
F_187 ( & V_216 , 1 , V_217 ) ;
F_147 (iter, memcg)
V_116 -> V_215 = false ;
F_72 ( & V_214 ) ;
}
static void F_188 ( struct V_1 * V_2 )
{
struct V_1 * V_116 ;
F_147 (iter, memcg)
F_93 ( & V_116 -> V_218 ) ;
}
static void F_189 ( struct V_1 * V_2 )
{
struct V_1 * V_116 ;
F_147 (iter, memcg)
F_190 ( & V_116 -> V_218 , - 1 , 0 ) ;
}
static int F_191 ( T_4 * V_163 ,
unsigned V_219 , int V_220 , void * V_221 )
{
struct V_1 * V_222 = (struct V_1 * ) V_221 ;
struct V_1 * V_223 ;
struct V_224 * V_224 ;
V_224 = F_12 ( V_163 , struct V_224 , V_163 ) ;
V_223 = V_224 -> V_2 ;
if ( ! F_119 ( V_223 , V_222 )
&& ! F_119 ( V_222 , V_223 ) )
return 0 ;
return F_192 ( V_163 , V_219 , V_220 , V_221 ) ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_93 ( & V_2 -> V_225 ) ;
F_194 ( & V_226 , V_227 , 0 , V_2 ) ;
}
static void F_195 ( struct V_1 * V_2 )
{
if ( V_2 && F_102 ( & V_2 -> V_218 ) )
F_193 ( V_2 ) ;
}
static void F_196 ( struct V_1 * V_2 , T_3 V_228 , int V_180 )
{
if ( ! V_25 -> V_229 . V_230 )
return;
F_21 ( & V_2 -> V_12 ) ;
V_25 -> V_229 . V_2 = V_2 ;
V_25 -> V_229 . V_179 = V_228 ;
V_25 -> V_229 . V_180 = V_180 ;
}
bool F_197 ( bool V_231 )
{
struct V_1 * V_2 = V_25 -> V_229 . V_2 ;
struct V_224 V_232 ;
bool V_233 ;
if ( ! V_2 )
return false ;
if ( ! V_231 )
goto V_234;
V_232 . V_2 = V_2 ;
V_232 . V_163 . V_57 = 0 ;
V_232 . V_163 . V_235 = F_191 ;
V_232 . V_163 . V_236 = V_25 ;
F_198 ( & V_232 . V_163 . V_237 ) ;
F_136 ( & V_226 , & V_232 . V_163 , V_238 ) ;
F_188 ( V_2 ) ;
V_233 = F_184 ( V_2 ) ;
if ( V_233 )
F_199 ( V_2 ) ;
if ( V_233 && ! V_2 -> V_239 ) {
F_189 ( V_2 ) ;
F_138 ( & V_226 , & V_232 . V_163 ) ;
F_153 ( V_2 , V_25 -> V_229 . V_179 ,
V_25 -> V_229 . V_180 ) ;
} else {
F_137 () ;
F_189 ( V_2 ) ;
F_138 ( & V_226 , & V_232 . V_163 ) ;
}
if ( V_233 ) {
F_186 ( V_2 ) ;
F_195 ( V_2 ) ;
}
V_234:
V_25 -> V_229 . V_2 = NULL ;
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
void F_200 ( struct V_39 * V_39 ,
bool * V_233 , unsigned long * V_57 )
{
struct V_1 * V_2 ;
struct V_138 * V_139 ;
V_139 = F_113 ( V_39 ) ;
V_240:
V_2 = V_139 -> V_1 ;
if ( F_91 ( ! V_2 || ! F_115 ( V_139 ) ) )
return;
F_82 ( ! F_201 () ) ;
if ( F_102 ( & V_2 -> V_158 ) <= 0 )
return;
F_139 ( V_2 , V_57 ) ;
if ( V_2 != V_139 -> V_1 || ! F_115 ( V_139 ) ) {
F_140 ( V_2 , V_57 ) ;
goto V_240;
}
* V_233 = true ;
}
void F_202 ( struct V_39 * V_39 , unsigned long * V_57 )
{
struct V_138 * V_139 = F_113 ( V_39 ) ;
F_140 ( V_139 -> V_1 , V_57 ) ;
}
void F_203 ( struct V_39 * V_39 ,
enum V_65 V_66 , int V_67 )
{
struct V_1 * V_2 ;
struct V_138 * V_139 = F_113 ( V_39 ) ;
unsigned long V_126 ( V_57 ) ;
if ( F_106 () )
return;
F_82 ( ! F_201 () ) ;
V_2 = V_139 -> V_1 ;
if ( F_91 ( ! V_2 || ! F_115 ( V_139 ) ) )
return;
F_204 ( V_2 -> V_69 -> V_70 [ V_66 ] , V_67 ) ;
}
static bool F_205 ( struct V_1 * V_2 , unsigned int V_75 )
{
struct V_241 * V_242 ;
bool V_142 = true ;
if ( V_75 > V_243 )
return false ;
V_242 = & F_206 ( V_244 ) ;
if ( V_2 == V_242 -> V_245 && V_242 -> V_75 >= V_75 )
V_242 -> V_75 -= V_75 ;
else
V_142 = false ;
F_207 ( V_244 ) ;
return V_142 ;
}
static void F_208 ( struct V_241 * V_242 )
{
struct V_1 * V_246 = V_242 -> V_245 ;
if ( V_242 -> V_75 ) {
unsigned long V_247 = V_242 -> V_75 * V_248 ;
F_209 ( & V_246 -> V_60 , V_247 ) ;
if ( V_153 )
F_209 ( & V_246 -> V_154 , V_247 ) ;
V_242 -> V_75 = 0 ;
}
V_242 -> V_245 = NULL ;
}
static void F_210 ( struct V_249 * V_250 )
{
struct V_241 * V_242 = F_211 ( & V_244 ) ;
F_208 ( V_242 ) ;
F_212 ( V_251 , & V_242 -> V_57 ) ;
}
static void T_5 F_213 ( void )
{
int V_68 ;
F_214 (cpu) {
struct V_241 * V_242 =
& F_69 ( V_244 , V_68 ) ;
F_215 ( & V_242 -> V_252 , F_210 ) ;
}
}
static void F_216 ( struct V_1 * V_2 , unsigned int V_75 )
{
struct V_241 * V_242 = & F_206 ( V_244 ) ;
if ( V_242 -> V_245 != V_2 ) {
F_208 ( V_242 ) ;
V_242 -> V_245 = V_2 ;
}
V_242 -> V_75 += V_75 ;
F_207 ( V_244 ) ;
}
static void F_217 ( struct V_1 * V_140 , bool V_220 )
{
int V_68 , V_253 ;
F_67 () ;
V_253 = F_218 () ;
F_68 (cpu) {
struct V_241 * V_242 = & F_69 ( V_244 , V_68 ) ;
struct V_1 * V_2 ;
V_2 = V_242 -> V_245 ;
if ( ! V_2 || ! V_242 -> V_75 )
continue;
if ( ! F_119 ( V_140 , V_2 ) )
continue;
if ( ! F_219 ( V_251 , & V_242 -> V_57 ) ) {
if ( V_68 == V_253 )
F_210 ( & V_242 -> V_252 ) ;
else
F_220 ( V_68 , & V_242 -> V_252 ) ;
}
}
F_221 () ;
if ( ! V_220 )
goto V_133;
F_68 (cpu) {
struct V_241 * V_242 = & F_69 ( V_244 , V_68 ) ;
if ( F_4 ( V_251 , & V_242 -> V_57 ) )
F_222 ( & V_242 -> V_252 ) ;
}
V_133:
F_73 () ;
}
static void F_167 ( struct V_1 * V_140 )
{
if ( ! F_223 ( & V_254 ) )
return;
F_217 ( V_140 , false ) ;
F_150 ( & V_254 ) ;
}
static void F_224 ( struct V_1 * V_140 )
{
F_143 ( & V_254 ) ;
F_217 ( V_140 , true ) ;
F_150 ( & V_254 ) ;
}
static void F_225 ( struct V_1 * V_2 , int V_68 )
{
int V_168 ;
F_71 ( & V_2 -> V_71 ) ;
for ( V_168 = 0 ; V_168 < V_171 ; V_168 ++ ) {
long V_255 = F_69 ( V_2 -> V_69 -> V_70 [ V_168 ] , V_68 ) ;
F_69 ( V_2 -> V_69 -> V_70 [ V_168 ] , V_68 ) = 0 ;
V_2 -> V_72 . V_70 [ V_168 ] += V_255 ;
}
for ( V_168 = 0 ; V_168 < V_256 ; V_168 ++ ) {
unsigned long V_255 = F_69 ( V_2 -> V_69 -> V_74 [ V_168 ] , V_68 ) ;
F_69 ( V_2 -> V_69 -> V_74 [ V_168 ] , V_68 ) = 0 ;
V_2 -> V_72 . V_74 [ V_168 ] += V_255 ;
}
F_72 ( & V_2 -> V_71 ) ;
}
static int F_226 ( struct V_257 * V_258 ,
unsigned long V_259 ,
void * V_260 )
{
int V_68 = ( unsigned long ) V_260 ;
struct V_241 * V_242 ;
struct V_1 * V_116 ;
if ( V_259 == V_261 )
return V_262 ;
if ( V_259 != V_263 && V_259 != V_264 )
return V_262 ;
F_227 (iter)
F_225 ( V_116 , V_68 ) ;
V_242 = & F_69 ( V_244 , V_68 ) ;
F_208 ( V_242 ) ;
return V_262 ;
}
static int F_228 ( struct V_1 * V_2 , T_3 V_179 ,
unsigned int V_75 )
{
unsigned int V_265 = F_229 ( V_243 , V_75 ) ;
int V_266 = V_267 ;
struct V_1 * V_268 ;
struct V_269 * V_270 ;
unsigned long V_271 ;
unsigned long V_57 = 0 ;
unsigned long long V_272 ;
int V_142 = 0 ;
if ( F_15 ( V_2 ) )
goto V_64;
V_63:
if ( F_205 ( V_2 , V_75 ) )
goto V_64;
V_272 = V_265 * V_248 ;
if ( ! F_230 ( & V_2 -> V_60 , V_272 , & V_270 ) ) {
if ( ! V_153 )
goto V_273;
if ( ! F_230 ( & V_2 -> V_154 , V_272 , & V_270 ) )
goto V_273;
F_209 ( & V_2 -> V_60 , V_272 ) ;
V_268 = F_231 ( V_270 , V_154 ) ;
V_57 |= V_198 ;
} else
V_268 = F_231 ( V_270 , V_60 ) ;
if ( V_265 > V_75 ) {
V_265 = V_75 ;
goto V_63;
}
if ( F_91 ( F_232 ( V_186 ) ||
F_154 ( V_25 ) ||
V_25 -> V_57 & V_185 ) )
goto V_274;
if ( F_91 ( F_233 ( V_25 ) ) )
goto V_275;
if ( ! ( V_179 & V_276 ) )
goto V_275;
V_271 = F_166 ( V_268 , V_179 , V_57 ) ;
if ( F_125 ( V_268 ) >= V_75 )
goto V_63;
if ( V_179 & V_277 )
goto V_275;
if ( V_271 && V_75 <= ( 1 << V_278 ) )
goto V_63;
if ( F_134 ( V_268 ) )
goto V_63;
if ( V_266 -- )
goto V_63;
if ( V_179 & V_279 )
goto V_274;
if ( F_154 ( V_25 ) )
goto V_274;
F_196 ( V_268 , V_179 , F_234 ( V_75 ) ) ;
V_275:
if ( ! ( V_179 & V_279 ) )
return - V_280 ;
V_274:
return - V_281 ;
V_273:
if ( V_265 > V_75 )
F_216 ( V_2 , V_265 - V_75 ) ;
V_64:
return V_142 ;
}
static void F_235 ( struct V_1 * V_2 , unsigned int V_75 )
{
unsigned long V_247 = V_75 * V_248 ;
if ( F_15 ( V_2 ) )
return;
F_209 ( & V_2 -> V_60 , V_247 ) ;
if ( V_153 )
F_209 ( & V_2 -> V_154 , V_247 ) ;
}
static void F_236 ( struct V_1 * V_2 ,
unsigned int V_75 )
{
unsigned long V_247 = V_75 * V_248 ;
if ( F_15 ( V_2 ) )
return;
F_237 ( & V_2 -> V_60 , V_2 -> V_60 . V_50 , V_247 ) ;
if ( V_153 )
F_237 ( & V_2 -> V_154 ,
V_2 -> V_154 . V_50 , V_247 ) ;
}
static struct V_1 * F_238 ( unsigned short V_16 )
{
if ( ! V_16 )
return NULL ;
return F_17 ( V_16 ) ;
}
struct V_1 * F_239 ( struct V_39 * V_39 )
{
struct V_1 * V_2 = NULL ;
struct V_138 * V_139 ;
unsigned short V_16 ;
T_6 V_282 ;
F_240 ( ! F_241 ( V_39 ) , V_39 ) ;
V_139 = F_113 ( V_39 ) ;
if ( F_115 ( V_139 ) ) {
V_2 = V_139 -> V_1 ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
} else if ( F_242 ( V_39 ) ) {
V_282 . V_67 = F_243 ( V_39 ) ;
V_16 = F_244 ( V_282 ) ;
F_22 () ;
V_2 = F_238 ( V_16 ) ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
F_26 () ;
}
return V_2 ;
}
static void F_245 ( struct V_39 * V_39 , int * V_283 )
{
struct V_34 * V_34 = F_246 ( V_39 ) ;
F_64 ( & V_34 -> V_284 ) ;
if ( F_114 ( V_39 ) ) {
struct V_82 * V_82 ;
V_82 = F_112 ( V_39 , V_34 ) ;
F_247 ( V_39 ) ;
F_248 ( V_39 , V_82 , F_249 ( V_39 ) ) ;
* V_283 = 1 ;
} else
* V_283 = 0 ;
}
static void F_250 ( struct V_39 * V_39 , int V_283 )
{
struct V_34 * V_34 = F_246 ( V_39 ) ;
if ( V_283 ) {
struct V_82 * V_82 ;
V_82 = F_112 ( V_39 , V_34 ) ;
F_240 ( F_114 ( V_39 ) , V_39 ) ;
F_251 ( V_39 ) ;
F_252 ( V_39 , V_82 , F_249 ( V_39 ) ) ;
}
F_65 ( & V_34 -> V_284 ) ;
}
static void F_253 ( struct V_39 * V_39 , struct V_1 * V_2 ,
bool V_285 )
{
struct V_138 * V_139 = F_113 ( V_39 ) ;
int V_283 ;
F_240 ( F_115 ( V_139 ) , V_39 ) ;
if ( V_285 )
F_245 ( V_39 , & V_283 ) ;
V_139 -> V_1 = V_2 ;
V_139 -> V_57 = V_286 | V_287 | ( V_153 ? V_288 : 0 ) ;
if ( V_285 )
F_250 ( V_39 , V_283 ) ;
}
static inline bool F_254 ( struct V_1 * V_2 )
{
return ! F_106 () && ! F_15 ( V_2 ) &&
F_3 ( V_2 ) ;
}
static struct V_289 * F_255 ( struct V_290 * V_48 )
{
struct V_289 * V_291 ;
F_82 ( V_48 -> V_292 ) ;
V_291 = V_48 -> V_293 ;
return F_256 ( V_291 , F_257 ( V_48 -> V_2 ) ) ;
}
static int F_258 ( struct V_294 * V_295 , void * V_296 )
{
struct V_1 * V_2 = F_11 ( F_259 ( V_295 ) ) ;
struct V_290 * V_297 ;
if ( ! F_254 ( V_2 ) )
return - V_298 ;
F_260 ( V_295 ) ;
F_143 ( & V_299 ) ;
F_261 (params, &memcg->memcg_slab_caches, list)
F_262 ( F_255 ( V_297 ) , V_295 ) ;
F_150 ( & V_299 ) ;
return 0 ;
}
static int F_263 ( struct V_1 * V_2 , T_3 V_300 , T_2 V_272 )
{
struct V_269 * V_270 ;
int V_142 = 0 ;
V_142 = F_230 ( & V_2 -> V_31 , V_272 , & V_270 ) ;
if ( V_142 )
return V_142 ;
V_142 = F_228 ( V_2 , V_300 , V_272 >> V_151 ) ;
if ( V_142 == - V_281 ) {
F_264 ( & V_2 -> V_60 , V_272 , & V_270 ) ;
if ( V_153 )
F_264 ( & V_2 -> V_154 , V_272 ,
& V_270 ) ;
V_142 = 0 ;
} else if ( V_142 )
F_209 ( & V_2 -> V_31 , V_272 ) ;
return V_142 ;
}
static void F_265 ( struct V_1 * V_2 , T_2 V_272 )
{
F_209 ( & V_2 -> V_60 , V_272 ) ;
if ( V_153 )
F_209 ( & V_2 -> V_154 , V_272 ) ;
if ( F_209 ( & V_2 -> V_31 , V_272 ) )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
int F_257 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_30 : - 1 ;
}
static T_7 F_266 ( int V_301 )
{
T_8 V_272 ;
if ( V_301 <= 0 )
return 0 ;
V_272 = 2 * V_301 ;
if ( V_272 < V_302 )
V_272 = V_302 ;
else if ( V_272 > V_303 )
V_272 = V_303 ;
return V_272 ;
}
void F_267 ( int V_176 )
{
if ( V_176 > V_304 )
V_304 = F_266 ( V_176 ) ;
}
int F_268 ( struct V_289 * V_11 , int V_301 )
{
struct V_290 * V_305 = V_11 -> V_306 ;
F_82 ( ! V_292 ( V_11 ) ) ;
if ( V_301 > V_304 ) {
int V_168 ;
struct V_290 * V_307 ;
T_8 V_272 = F_266 ( V_301 ) ;
V_272 *= sizeof( void * ) ;
V_272 += F_269 ( struct V_290 , V_308 ) ;
V_307 = F_270 ( V_272 , V_309 ) ;
if ( ! V_307 )
return - V_280 ;
V_307 -> V_292 = true ;
for ( V_168 = 0 ; V_168 < V_304 ; V_168 ++ ) {
if ( ! V_305 -> V_308 [ V_168 ] )
continue;
V_307 -> V_308 [ V_168 ] =
V_305 -> V_308 [ V_168 ] ;
}
F_271 ( V_11 -> V_306 , V_307 ) ;
if ( V_305 )
F_272 ( V_305 , V_310 ) ;
}
return 0 ;
}
int F_273 ( struct V_1 * V_2 , struct V_289 * V_11 ,
struct V_289 * V_293 )
{
T_7 V_272 ;
if ( ! F_274 () )
return 0 ;
if ( ! V_2 ) {
V_272 = F_269 ( struct V_290 , V_308 ) ;
V_272 += V_304 * sizeof( void * ) ;
} else
V_272 = sizeof( struct V_290 ) ;
V_11 -> V_306 = F_270 ( V_272 , V_309 ) ;
if ( ! V_11 -> V_306 )
return - V_280 ;
if ( V_2 ) {
V_11 -> V_306 -> V_2 = V_2 ;
V_11 -> V_306 -> V_293 = V_293 ;
F_21 ( & V_2 -> V_12 ) ;
} else
V_11 -> V_306 -> V_292 = true ;
return 0 ;
}
void F_275 ( struct V_289 * V_11 )
{
if ( ! V_11 -> V_306 )
return;
if ( ! V_11 -> V_306 -> V_292 )
F_29 ( & V_11 -> V_306 -> V_2 -> V_12 ) ;
F_276 ( V_11 -> V_306 ) ;
}
static void F_277 ( struct V_1 * V_2 ,
struct V_289 * V_293 )
{
static char V_311 [ V_312 + 1 ] ;
struct V_289 * V_291 ;
int V_16 ;
F_278 ( & V_299 ) ;
V_16 = F_257 ( V_2 ) ;
if ( F_256 ( V_293 , V_16 ) )
return;
F_279 ( V_2 -> V_12 . V_141 , V_311 , V_312 + 1 ) ;
V_291 = F_280 ( V_2 , V_293 , V_311 ) ;
if ( ! V_291 )
return;
F_281 ( & V_291 -> V_306 -> V_313 , & V_2 -> V_314 ) ;
F_6 () ;
F_20 ( V_293 -> V_306 -> V_308 [ V_16 ] ) ;
V_293 -> V_306 -> V_308 [ V_16 ] = V_291 ;
}
static void F_282 ( struct V_289 * V_291 )
{
struct V_289 * V_293 ;
struct V_1 * V_2 ;
int V_16 ;
F_278 ( & V_299 ) ;
F_20 ( V_292 ( V_291 ) ) ;
V_293 = V_291 -> V_306 -> V_293 ;
V_2 = V_291 -> V_306 -> V_2 ;
V_16 = F_257 ( V_2 ) ;
F_20 ( V_293 -> V_306 -> V_308 [ V_16 ] != V_291 ) ;
V_293 -> V_306 -> V_308 [ V_16 ] = NULL ;
F_283 ( & V_291 -> V_306 -> V_313 ) ;
F_284 ( V_291 ) ;
}
static inline void F_285 ( void )
{
F_82 ( ! V_25 -> V_106 ) ;
V_25 -> V_315 ++ ;
}
static inline void F_286 ( void )
{
F_82 ( ! V_25 -> V_106 ) ;
V_25 -> V_315 -- ;
}
int F_287 ( struct V_289 * V_11 )
{
struct V_289 * V_316 ;
int V_168 , V_213 = 0 ;
F_143 ( & V_299 ) ;
F_288 (i) {
V_316 = F_256 ( V_11 , V_168 ) ;
if ( ! V_316 )
continue;
F_282 ( V_316 ) ;
if ( F_256 ( V_11 , V_168 ) )
V_213 ++ ;
}
F_150 ( & V_299 ) ;
return V_213 ;
}
static void F_289 ( struct V_1 * V_2 )
{
struct V_289 * V_291 ;
struct V_290 * V_297 , * V_317 ;
if ( ! F_3 ( V_2 ) )
return;
F_143 ( & V_299 ) ;
F_290 (params, tmp, &memcg->memcg_slab_caches, list) {
V_291 = F_255 ( V_297 ) ;
F_291 ( V_291 ) ;
if ( F_102 ( & V_291 -> V_306 -> V_75 ) == 0 )
F_282 ( V_291 ) ;
}
F_150 ( & V_299 ) ;
}
static void F_292 ( struct V_249 * V_318 )
{
struct V_319 * V_320 =
F_12 ( V_318 , struct V_319 , V_252 ) ;
struct V_1 * V_2 = V_320 -> V_2 ;
struct V_289 * V_291 = V_320 -> V_291 ;
F_143 ( & V_299 ) ;
F_277 ( V_2 , V_291 ) ;
F_150 ( & V_299 ) ;
F_29 ( & V_2 -> V_12 ) ;
F_276 ( V_320 ) ;
}
static void F_293 ( struct V_1 * V_2 ,
struct V_289 * V_291 )
{
struct V_319 * V_320 ;
V_320 = F_294 ( sizeof( * V_320 ) , V_321 ) ;
if ( V_320 == NULL ) {
F_29 ( & V_2 -> V_12 ) ;
return;
}
V_320 -> V_2 = V_2 ;
V_320 -> V_291 = V_291 ;
F_215 ( & V_320 -> V_252 , F_292 ) ;
F_295 ( & V_320 -> V_252 ) ;
}
static void F_296 ( struct V_1 * V_2 ,
struct V_289 * V_291 )
{
F_285 () ;
F_293 ( V_2 , V_291 ) ;
F_286 () ;
}
int F_297 ( struct V_289 * V_291 , T_3 V_300 , int V_180 )
{
int V_60 ;
V_60 = F_263 ( V_291 -> V_306 -> V_2 , V_300 ,
V_248 << V_180 ) ;
if ( ! V_60 )
F_298 ( 1 << V_180 , & V_291 -> V_306 -> V_75 ) ;
return V_60 ;
}
void F_299 ( struct V_289 * V_291 , int V_180 )
{
F_265 ( V_291 -> V_306 -> V_2 , V_248 << V_180 ) ;
F_300 ( 1 << V_180 , & V_291 -> V_306 -> V_75 ) ;
}
struct V_289 * F_301 ( struct V_289 * V_291 ,
T_3 V_300 )
{
struct V_1 * V_2 ;
struct V_289 * V_322 ;
F_82 ( ! V_291 -> V_306 ) ;
F_82 ( ! V_291 -> V_306 -> V_292 ) ;
if ( ! V_25 -> V_106 || V_25 -> V_315 )
return V_291 ;
F_22 () ;
V_2 = F_23 ( F_96 ( V_25 -> V_106 -> V_107 ) ) ;
if ( ! F_254 ( V_2 ) )
goto V_133;
V_322 = F_256 ( V_291 , F_257 ( V_2 ) ) ;
if ( F_302 ( V_322 ) ) {
V_291 = V_322 ;
goto V_133;
}
if ( ! F_25 ( & V_2 -> V_12 ) )
goto V_133;
F_26 () ;
F_296 ( V_2 , V_291 ) ;
return V_291 ;
V_133:
F_26 () ;
return V_291 ;
}
bool
F_303 ( T_3 V_300 , struct V_1 * * V_323 , int V_180 )
{
struct V_1 * V_2 ;
int V_142 ;
* V_323 = NULL ;
if ( ! V_25 -> V_106 || V_25 -> V_315 )
return true ;
V_2 = F_95 ( V_25 -> V_106 ) ;
if ( ! F_254 ( V_2 ) ) {
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
V_142 = F_263 ( V_2 , V_300 , V_248 << V_180 ) ;
if ( ! V_142 )
* V_323 = V_2 ;
F_29 ( & V_2 -> V_12 ) ;
return ( V_142 == 0 ) ;
}
void F_304 ( struct V_39 * V_39 , struct V_1 * V_2 ,
int V_180 )
{
struct V_138 * V_139 ;
F_82 ( F_15 ( V_2 ) ) ;
if ( ! V_39 ) {
F_265 ( V_2 , V_248 << V_180 ) ;
return;
}
V_139 = F_113 ( V_39 ) ;
V_139 -> V_1 = V_2 ;
V_139 -> V_57 = V_286 ;
}
void F_305 ( struct V_39 * V_39 , int V_180 )
{
struct V_1 * V_2 = NULL ;
struct V_138 * V_139 ;
V_139 = F_113 ( V_39 ) ;
if ( ! F_115 ( V_139 ) )
return;
V_2 = V_139 -> V_1 ;
V_139 -> V_57 = 0 ;
if ( ! V_2 )
return;
F_240 ( F_15 ( V_2 ) , V_39 ) ;
F_265 ( V_2 , V_248 << V_180 ) ;
}
static inline void F_289 ( struct V_1 * V_2 )
{
}
void F_306 ( struct V_39 * V_324 )
{
struct V_138 * V_325 = F_113 ( V_324 ) ;
struct V_138 * V_139 ;
struct V_1 * V_2 ;
int V_168 ;
if ( F_106 () )
return;
V_2 = V_325 -> V_1 ;
for ( V_168 = 1 ; V_168 < V_326 ; V_168 ++ ) {
V_139 = V_325 + V_168 ;
V_139 -> V_1 = V_2 ;
V_139 -> V_57 = V_325 -> V_57 ;
}
F_307 ( V_2 -> V_69 -> V_70 [ V_78 ] ,
V_326 ) ;
}
static int F_308 ( struct V_39 * V_39 ,
unsigned int V_75 ,
struct V_138 * V_139 ,
struct V_1 * V_159 ,
struct V_1 * V_160 )
{
unsigned long V_57 ;
int V_142 ;
F_82 ( V_159 == V_160 ) ;
F_240 ( F_114 ( V_39 ) , V_39 ) ;
V_142 = - V_327 ;
if ( V_75 > 1 && ! F_78 ( V_39 ) )
goto V_133;
if ( ! F_309 ( V_39 ) )
goto V_133;
V_142 = - V_328 ;
if ( ! F_115 ( V_139 ) || V_139 -> V_1 != V_159 )
goto V_131;
F_139 ( V_159 , & V_57 ) ;
if ( ! F_76 ( V_39 ) && F_310 ( V_39 ) ) {
F_307 ( V_159 -> V_69 -> V_70 [ V_329 ] ,
V_75 ) ;
F_77 ( V_160 -> V_69 -> V_70 [ V_329 ] ,
V_75 ) ;
}
if ( F_311 ( V_39 ) ) {
F_307 ( V_159 -> V_69 -> V_70 [ V_330 ] ,
V_75 ) ;
F_77 ( V_160 -> V_69 -> V_70 [ V_330 ] ,
V_75 ) ;
}
V_139 -> V_1 = V_160 ;
F_140 ( V_159 , & V_57 ) ;
V_142 = 0 ;
F_312 () ;
F_75 ( V_160 , V_39 , V_75 ) ;
F_90 ( V_160 , V_39 ) ;
F_75 ( V_159 , V_39 , - V_75 ) ;
F_90 ( V_159 , V_39 ) ;
F_313 () ;
V_131:
F_314 ( V_39 ) ;
V_133:
return V_142 ;
}
static int F_315 ( struct V_39 * V_39 ,
struct V_138 * V_139 ,
struct V_1 * V_331 )
{
struct V_1 * V_50 ;
unsigned int V_75 ;
unsigned long V_126 ( V_57 ) ;
int V_142 ;
F_82 ( F_15 ( V_331 ) ) ;
V_142 = - V_327 ;
if ( ! F_316 ( V_39 ) )
goto V_133;
if ( F_317 ( V_39 ) )
goto V_332;
V_75 = F_318 ( V_39 ) ;
V_50 = F_57 ( V_331 ) ;
if ( ! V_50 )
V_50 = V_14 ;
if ( V_75 > 1 ) {
F_240 ( ! F_78 ( V_39 ) , V_39 ) ;
V_57 = F_319 ( V_39 ) ;
}
V_142 = F_308 ( V_39 , V_75 ,
V_139 , V_331 , V_50 ) ;
if ( ! V_142 )
F_236 ( V_331 , V_75 ) ;
if ( V_75 > 1 )
F_320 ( V_39 , V_57 ) ;
F_321 ( V_39 ) ;
V_332:
F_322 ( V_39 ) ;
V_133:
return V_142 ;
}
static void F_323 ( struct V_1 * V_2 ,
bool V_333 )
{
int V_67 = ( V_333 ) ? 1 : - 1 ;
F_204 ( V_2 -> V_69 -> V_70 [ V_172 ] , V_67 ) ;
}
static int F_324 ( T_6 V_334 ,
struct V_1 * V_159 , struct V_1 * V_160 )
{
unsigned short V_335 , V_336 ;
V_335 = F_16 ( V_159 ) ;
V_336 = F_16 ( V_160 ) ;
if ( F_325 ( V_334 , V_335 , V_336 ) == V_335 ) {
F_323 ( V_159 , false ) ;
F_323 ( V_160 , true ) ;
F_21 ( & V_160 -> V_12 ) ;
return 0 ;
}
return - V_328 ;
}
static inline int F_324 ( T_6 V_334 ,
struct V_1 * V_159 , struct V_1 * V_160 )
{
return - V_328 ;
}
static struct V_138 * F_326 ( struct V_39 * V_39 )
{
struct V_138 * V_139 ;
V_139 = F_113 ( V_39 ) ;
if ( F_302 ( V_139 ) && F_115 ( V_139 ) )
return V_139 ;
return NULL ;
}
bool F_327 ( struct V_39 * V_39 )
{
if ( F_106 () )
return false ;
return F_326 ( V_39 ) != NULL ;
}
void F_328 ( struct V_39 * V_39 )
{
struct V_138 * V_139 ;
V_139 = F_326 ( V_39 ) ;
if ( V_139 ) {
F_329 ( L_12 ,
V_139 , V_139 -> V_57 , V_139 -> V_1 ) ;
}
}
static int F_330 ( struct V_1 * V_2 ,
unsigned long long V_67 )
{
int V_337 ;
T_2 V_338 , V_339 ;
int V_142 = 0 ;
int V_340 = F_151 ( V_2 ) ;
T_2 V_341 , V_342 ;
int V_343 ;
V_337 = V_267 * V_340 ;
V_342 = F_36 ( & V_2 -> V_60 , V_32 ) ;
V_343 = 0 ;
while ( V_337 ) {
if ( F_331 ( V_25 ) ) {
V_142 = - V_281 ;
break;
}
F_143 ( & V_344 ) ;
V_338 = F_36 ( & V_2 -> V_154 , V_169 ) ;
if ( V_338 < V_67 ) {
V_142 = - V_328 ;
F_150 ( & V_344 ) ;
break;
}
V_339 = F_36 ( & V_2 -> V_60 , V_169 ) ;
if ( V_339 < V_67 )
V_343 = 1 ;
V_142 = F_332 ( & V_2 -> V_60 , V_67 ) ;
if ( ! V_142 ) {
if ( V_338 == V_67 )
V_2 -> V_200 = true ;
else
V_2 -> V_200 = false ;
}
F_150 ( & V_344 ) ;
if ( ! V_142 )
break;
F_166 ( V_2 , V_309 ,
V_199 ) ;
V_341 = F_36 ( & V_2 -> V_60 , V_32 ) ;
if ( V_341 >= V_342 )
V_337 -- ;
else
V_342 = V_341 ;
}
if ( ! V_142 && V_343 )
F_195 ( V_2 ) ;
return V_142 ;
}
static int F_333 ( struct V_1 * V_2 ,
unsigned long long V_67 )
{
int V_337 ;
T_2 V_339 , V_338 , V_342 , V_341 ;
int V_340 = F_151 ( V_2 ) ;
int V_142 = - V_327 ;
int V_343 = 0 ;
V_337 = V_340 * V_267 ;
V_342 = F_36 ( & V_2 -> V_154 , V_32 ) ;
while ( V_337 ) {
if ( F_331 ( V_25 ) ) {
V_142 = - V_281 ;
break;
}
F_143 ( & V_344 ) ;
V_339 = F_36 ( & V_2 -> V_60 , V_169 ) ;
if ( V_339 > V_67 ) {
V_142 = - V_328 ;
F_150 ( & V_344 ) ;
break;
}
V_338 = F_36 ( & V_2 -> V_154 , V_169 ) ;
if ( V_338 < V_67 )
V_343 = 1 ;
V_142 = F_332 ( & V_2 -> V_154 , V_67 ) ;
if ( ! V_142 ) {
if ( V_339 == V_67 )
V_2 -> V_200 = true ;
else
V_2 -> V_200 = false ;
}
F_150 ( & V_344 ) ;
if ( ! V_142 )
break;
F_166 ( V_2 , V_309 ,
V_198 |
V_199 ) ;
V_341 = F_36 ( & V_2 -> V_154 , V_32 ) ;
if ( V_341 >= V_342 )
V_337 -- ;
else
V_342 = V_341 ;
}
if ( ! V_142 && V_343 )
F_195 ( V_2 ) ;
return V_142 ;
}
unsigned long F_334 ( struct V_34 * V_34 , int V_180 ,
T_3 V_179 ,
unsigned long * V_210 )
{
unsigned long V_271 = 0 ;
struct V_33 * V_44 , * V_345 = NULL ;
unsigned long V_346 ;
int V_197 = 0 ;
struct V_40 * V_45 ;
unsigned long long V_59 ;
unsigned long V_212 ;
if ( V_180 > 0 )
return 0 ;
V_45 = F_45 ( F_39 ( V_34 ) , F_40 ( V_34 ) ) ;
do {
if ( V_345 )
V_44 = V_345 ;
else
V_44 = F_63 ( V_45 ) ;
if ( ! V_44 )
break;
V_212 = 0 ;
V_346 = F_182 ( V_44 -> V_2 , V_34 ,
V_179 , & V_212 ) ;
V_271 += V_346 ;
* V_210 += V_212 ;
F_64 ( & V_45 -> V_58 ) ;
V_345 = NULL ;
if ( ! V_346 ) {
do {
V_345 =
F_61 ( V_45 ) ;
if ( V_345 == V_44 )
F_29 ( & V_345 -> V_2 -> V_12 ) ;
else
break;
} while ( 1 );
}
F_51 ( V_44 , V_45 ) ;
V_59 = F_58 ( & V_44 -> V_2 -> V_60 ) ;
F_47 ( V_44 , V_45 , V_59 ) ;
F_65 ( & V_45 -> V_58 ) ;
F_29 ( & V_44 -> V_2 -> V_12 ) ;
V_197 ++ ;
if ( ! V_271 &&
( V_345 == NULL ||
V_197 > V_347 ) )
break;
} while ( ! V_271 );
if ( V_345 )
F_29 ( & V_345 -> V_2 -> V_12 ) ;
return V_271 ;
}
static void F_335 ( struct V_1 * V_2 ,
int V_208 , int V_36 , enum V_83 V_84 )
{
struct V_82 * V_82 ;
unsigned long V_57 ;
struct V_348 * V_313 ;
struct V_39 * V_349 ;
struct V_34 * V_34 ;
V_34 = & F_336 ( V_208 ) -> V_350 [ V_36 ] ;
V_82 = F_111 ( V_34 , V_2 ) ;
V_313 = & V_82 -> V_351 [ V_84 ] ;
V_349 = NULL ;
do {
struct V_138 * V_139 ;
struct V_39 * V_39 ;
F_54 ( & V_34 -> V_284 , V_57 ) ;
if ( F_337 ( V_313 ) ) {
F_55 ( & V_34 -> V_284 , V_57 ) ;
break;
}
V_39 = F_338 ( V_313 -> V_121 , struct V_39 , V_84 ) ;
if ( V_349 == V_39 ) {
F_339 ( & V_39 -> V_84 , V_313 ) ;
V_349 = NULL ;
F_55 ( & V_34 -> V_284 , V_57 ) ;
continue;
}
F_55 ( & V_34 -> V_284 , V_57 ) ;
V_139 = F_113 ( V_39 ) ;
if ( F_315 ( V_39 , V_139 , V_2 ) ) {
V_349 = V_39 ;
} else
V_349 = NULL ;
F_340 () ;
} while ( ! F_337 ( V_313 ) );
}
static void F_341 ( struct V_1 * V_2 )
{
int V_208 , V_36 ;
T_2 V_352 ;
do {
F_342 () ;
F_224 ( V_2 ) ;
F_129 ( V_2 ) ;
F_86 (node, N_MEMORY) {
for ( V_36 = 0 ; V_36 < V_61 ; V_36 ++ ) {
enum V_83 V_84 ;
F_83 (lru) {
F_335 ( V_2 ,
V_208 , V_36 , V_84 ) ;
}
}
}
F_131 ( V_2 ) ;
F_195 ( V_2 ) ;
F_340 () ;
V_352 = F_36 ( & V_2 -> V_60 , V_32 ) -
F_36 ( & V_2 -> V_31 , V_32 ) ;
} while ( V_352 > 0 );
}
static inline bool F_343 ( struct V_1 * V_2 )
{
bool V_142 ;
F_278 ( & V_353 ) ;
F_22 () ;
V_142 = F_344 ( NULL , & V_2 -> V_12 ) ;
F_26 () ;
return V_142 ;
}
static int F_345 ( struct V_1 * V_2 )
{
int V_266 = V_267 ;
F_342 () ;
while ( V_266 && F_36 ( & V_2 -> V_60 , V_32 ) > 0 ) {
int V_354 ;
if ( F_331 ( V_25 ) )
return - V_281 ;
V_354 = F_168 ( V_2 , V_309 ,
false ) ;
if ( ! V_354 ) {
V_266 -- ;
F_346 ( V_355 , V_356 / 10 ) ;
}
}
return 0 ;
}
static T_8 F_347 ( struct V_357 * V_358 ,
char * V_359 , T_7 V_360 ,
T_9 V_361 )
{
struct V_1 * V_2 = F_11 ( F_348 ( V_358 ) ) ;
if ( F_15 ( V_2 ) )
return - V_328 ;
return F_345 ( V_2 ) ? : V_360 ;
}
static T_2 F_349 ( struct V_10 * V_12 ,
struct V_362 * V_363 )
{
return F_11 ( V_12 ) -> V_124 ;
}
static int F_350 ( struct V_10 * V_12 ,
struct V_362 * V_363 , T_2 V_67 )
{
int V_364 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_365 = F_11 ( V_2 -> V_12 . V_50 ) ;
F_143 ( & V_353 ) ;
if ( V_2 -> V_124 == V_67 )
goto V_133;
if ( ( ! V_365 || ! V_365 -> V_124 ) &&
( V_67 == 1 || V_67 == 0 ) ) {
if ( ! F_343 ( V_2 ) )
V_2 -> V_124 = V_67 ;
else
V_364 = - V_327 ;
} else
V_364 = - V_328 ;
V_133:
F_150 ( & V_353 ) ;
return V_364 ;
}
static unsigned long F_351 ( struct V_1 * V_2 ,
enum V_65 V_66 )
{
struct V_1 * V_116 ;
long V_67 = 0 ;
F_147 (iter, memcg)
V_67 += F_66 ( V_116 , V_66 ) ;
if ( V_67 < 0 )
V_67 = 0 ;
return V_67 ;
}
static inline T_2 F_352 ( struct V_1 * V_2 , bool V_366 )
{
T_2 V_67 ;
if ( ! F_15 ( V_2 ) ) {
if ( ! V_366 )
return F_36 ( & V_2 -> V_60 , V_32 ) ;
else
return F_36 ( & V_2 -> V_154 , V_32 ) ;
}
V_67 = F_351 ( V_2 , V_77 ) ;
V_67 += F_351 ( V_2 , V_76 ) ;
if ( V_366 )
V_67 += F_351 ( V_2 , V_172 ) ;
return V_67 << V_151 ;
}
static T_2 F_353 ( struct V_10 * V_12 ,
struct V_362 * V_363 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
enum V_367 type = F_354 ( V_363 -> V_236 ) ;
int V_368 = F_355 ( V_363 -> V_236 ) ;
switch ( type ) {
case V_369 :
if ( V_368 == V_32 )
return F_352 ( V_2 , false ) ;
return F_36 ( & V_2 -> V_60 , V_368 ) ;
case V_370 :
if ( V_368 == V_32 )
return F_352 ( V_2 , true ) ;
return F_36 ( & V_2 -> V_154 , V_368 ) ;
case V_371 :
return F_36 ( & V_2 -> V_31 , V_368 ) ;
break;
default:
F_110 () ;
}
}
static int F_356 ( struct V_1 * V_2 ,
unsigned long long V_177 )
{
int V_372 = 0 ;
int V_373 ;
if ( F_3 ( V_2 ) )
return 0 ;
F_285 () ;
F_143 ( & V_353 ) ;
if ( F_357 ( V_2 -> V_12 . V_141 ) ||
( V_2 -> V_124 && F_343 ( V_2 ) ) )
V_372 = - V_327 ;
F_150 ( & V_353 ) ;
if ( V_372 )
goto V_133;
V_373 = F_358 ( & V_29 ,
0 , V_303 , V_309 ) ;
if ( V_373 < 0 ) {
V_372 = V_373 ;
goto V_133;
}
F_143 ( & V_299 ) ;
V_372 = F_359 ( V_373 + 1 ) ;
F_150 ( & V_299 ) ;
if ( V_372 )
goto V_374;
V_2 -> V_30 = V_373 ;
F_198 ( & V_2 -> V_314 ) ;
V_372 = F_332 ( & V_2 -> V_31 , V_177 ) ;
F_82 ( V_372 ) ;
F_360 ( & V_28 ) ;
F_1 ( V_2 ) ;
V_133:
F_286 () ;
return V_372 ;
V_374:
F_35 ( & V_29 , V_373 ) ;
goto V_133;
}
static int F_361 ( struct V_1 * V_2 ,
unsigned long long V_177 )
{
int V_142 ;
F_143 ( & V_375 ) ;
V_142 = F_356 ( V_2 , V_177 ) ;
F_150 ( & V_375 ) ;
return V_142 ;
}
static int F_362 ( struct V_1 * V_2 ,
unsigned long long V_67 )
{
int V_142 ;
if ( ! F_3 ( V_2 ) )
V_142 = F_361 ( V_2 , V_67 ) ;
else
V_142 = F_332 ( & V_2 -> V_31 , V_67 ) ;
return V_142 ;
}
static int F_363 ( struct V_1 * V_2 )
{
int V_142 = 0 ;
struct V_1 * V_50 = F_57 ( V_2 ) ;
if ( ! V_50 )
return 0 ;
F_143 ( & V_375 ) ;
if ( F_3 ( V_50 ) )
V_142 = F_356 ( V_2 , V_376 ) ;
F_150 ( & V_375 ) ;
return V_142 ;
}
static int F_362 ( struct V_1 * V_2 ,
unsigned long long V_67 )
{
return - V_328 ;
}
static T_8 F_364 ( struct V_357 * V_358 ,
char * V_359 , T_7 V_360 , T_9 V_361 )
{
struct V_1 * V_2 = F_11 ( F_348 ( V_358 ) ) ;
enum V_367 type ;
int V_368 ;
unsigned long long V_67 ;
int V_142 ;
V_359 = F_365 ( V_359 ) ;
type = F_354 ( F_366 ( V_358 ) -> V_236 ) ;
V_368 = F_355 ( F_366 ( V_358 ) -> V_236 ) ;
switch ( V_368 ) {
case V_169 :
if ( F_15 ( V_2 ) ) {
V_142 = - V_328 ;
break;
}
V_142 = F_367 ( V_359 , & V_67 ) ;
if ( V_142 )
break;
if ( type == V_369 )
V_142 = F_330 ( V_2 , V_67 ) ;
else if ( type == V_370 )
V_142 = F_333 ( V_2 , V_67 ) ;
else if ( type == V_371 )
V_142 = F_362 ( V_2 , V_67 ) ;
else
return - V_328 ;
break;
case V_377 :
V_142 = F_367 ( V_359 , & V_67 ) ;
if ( V_142 )
break;
if ( type == V_369 )
V_142 = F_368 ( & V_2 -> V_60 , V_67 ) ;
else
V_142 = - V_328 ;
break;
default:
V_142 = - V_328 ;
break;
}
return V_142 ? : V_360 ;
}
static void F_369 ( struct V_1 * V_2 ,
unsigned long long * V_378 , unsigned long long * V_379 )
{
unsigned long long V_380 , V_381 , V_317 ;
V_380 = F_36 ( & V_2 -> V_60 , V_169 ) ;
V_381 = F_36 ( & V_2 -> V_154 , V_169 ) ;
if ( ! V_2 -> V_124 )
goto V_133;
while ( V_2 -> V_12 . V_50 ) {
V_2 = F_11 ( V_2 -> V_12 . V_50 ) ;
if ( ! V_2 -> V_124 )
break;
V_317 = F_36 ( & V_2 -> V_60 , V_169 ) ;
V_380 = F_127 ( V_380 , V_317 ) ;
V_317 = F_36 ( & V_2 -> V_154 , V_169 ) ;
V_381 = F_127 ( V_381 , V_317 ) ;
}
V_133:
* V_378 = V_380 ;
* V_379 = V_381 ;
}
static T_8 F_370 ( struct V_357 * V_358 , char * V_359 ,
T_7 V_360 , T_9 V_361 )
{
struct V_1 * V_2 = F_11 ( F_348 ( V_358 ) ) ;
int V_368 ;
enum V_367 type ;
type = F_354 ( F_366 ( V_358 ) -> V_236 ) ;
V_368 = F_355 ( F_366 ( V_358 ) -> V_236 ) ;
switch ( V_368 ) {
case V_382 :
if ( type == V_369 )
F_371 ( & V_2 -> V_60 ) ;
else if ( type == V_370 )
F_371 ( & V_2 -> V_154 ) ;
else if ( type == V_371 )
F_371 ( & V_2 -> V_31 ) ;
else
return - V_328 ;
break;
case V_170 :
if ( type == V_369 )
F_372 ( & V_2 -> V_60 ) ;
else if ( type == V_370 )
F_372 ( & V_2 -> V_154 ) ;
else if ( type == V_371 )
F_372 ( & V_2 -> V_31 ) ;
else
return - V_328 ;
break;
}
return V_360 ;
}
static T_2 F_373 ( struct V_10 * V_12 ,
struct V_362 * V_363 )
{
return F_11 ( V_12 ) -> V_383 ;
}
static int F_374 ( struct V_10 * V_12 ,
struct V_362 * V_363 , T_2 V_67 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_67 >= ( 1 << V_384 ) )
return - V_328 ;
V_2 -> V_383 = V_67 ;
return 0 ;
}
static int F_374 ( struct V_10 * V_12 ,
struct V_362 * V_363 , T_2 V_67 )
{
return - V_385 ;
}
static int F_375 ( struct V_294 * V_295 , void * V_296 )
{
struct V_386 {
const char * V_368 ;
unsigned int V_86 ;
};
static const struct V_386 V_387 [] = {
{ L_13 , V_388 } ,
{ L_14 , V_202 } ,
{ L_15 , V_203 } ,
{ L_16 , F_84 (LRU_UNEVICTABLE) } ,
} ;
const struct V_386 * V_69 ;
int V_35 ;
unsigned long V_87 ;
struct V_1 * V_2 = F_11 ( F_259 ( V_295 ) ) ;
for ( V_69 = V_387 ; V_69 < V_387 + F_376 ( V_387 ) ; V_69 ++ ) {
V_87 = F_85 ( V_2 , V_69 -> V_86 ) ;
F_377 ( V_295 , L_17 , V_69 -> V_368 , V_87 ) ;
F_86 (nid, N_MEMORY) {
V_87 = F_81 ( V_2 , V_35 ,
V_69 -> V_86 ) ;
F_377 ( V_295 , L_18 , V_35 , V_87 ) ;
}
F_378 ( V_295 , '\n' ) ;
}
for ( V_69 = V_387 ; V_69 < V_387 + F_376 ( V_387 ) ; V_69 ++ ) {
struct V_1 * V_116 ;
V_87 = 0 ;
F_147 (iter, memcg)
V_87 += F_85 ( V_116 , V_69 -> V_86 ) ;
F_377 ( V_295 , L_19 , V_69 -> V_368 , V_87 ) ;
F_86 (nid, N_MEMORY) {
V_87 = 0 ;
F_147 (iter, memcg)
V_87 += F_81 (
V_116 , V_35 , V_69 -> V_86 ) ;
F_377 ( V_295 , L_18 , V_35 , V_87 ) ;
}
F_378 ( V_295 , '\n' ) ;
}
return 0 ;
}
static inline void F_379 ( void )
{
F_380 ( F_376 ( V_175 ) != V_174 ) ;
}
static int F_381 ( struct V_294 * V_295 , void * V_296 )
{
struct V_1 * V_2 = F_11 ( F_259 ( V_295 ) ) ;
struct V_1 * V_389 ;
unsigned int V_168 ;
for ( V_168 = 0 ; V_168 < V_171 ; V_168 ++ ) {
if ( V_168 == V_172 && ! V_153 )
continue;
F_377 ( V_295 , L_20 , V_173 [ V_168 ] ,
F_66 ( V_2 , V_168 ) * V_248 ) ;
}
for ( V_168 = 0 ; V_168 < V_256 ; V_168 ++ )
F_377 ( V_295 , L_21 , V_390 [ V_168 ] ,
F_74 ( V_2 , V_168 ) ) ;
for ( V_168 = 0 ; V_168 < V_174 ; V_168 ++ )
F_377 ( V_295 , L_21 , V_175 [ V_168 ] ,
F_85 ( V_2 , F_84 ( V_168 ) ) * V_248 ) ;
{
unsigned long long V_177 , V_379 ;
F_369 ( V_2 , & V_177 , & V_379 ) ;
F_377 ( V_295 , L_22 , V_177 ) ;
if ( V_153 )
F_377 ( V_295 , L_23 ,
V_379 ) ;
}
for ( V_168 = 0 ; V_168 < V_171 ; V_168 ++ ) {
long long V_67 = 0 ;
if ( V_168 == V_172 && ! V_153 )
continue;
F_147 (mi, memcg)
V_67 += F_66 ( V_389 , V_168 ) * V_248 ;
F_377 ( V_295 , L_24 , V_173 [ V_168 ] , V_67 ) ;
}
for ( V_168 = 0 ; V_168 < V_256 ; V_168 ++ ) {
unsigned long long V_67 = 0 ;
F_147 (mi, memcg)
V_67 += F_74 ( V_389 , V_168 ) ;
F_377 ( V_295 , L_25 ,
V_390 [ V_168 ] , V_67 ) ;
}
for ( V_168 = 0 ; V_168 < V_174 ; V_168 ++ ) {
unsigned long long V_67 = 0 ;
F_147 (mi, memcg)
V_67 += F_85 ( V_389 , F_84 ( V_168 ) ) * V_248 ;
F_377 ( V_295 , L_25 , V_175 [ V_168 ] , V_67 ) ;
}
#ifdef F_382
{
int V_35 , V_36 ;
struct V_33 * V_44 ;
struct V_391 * V_392 ;
unsigned long V_393 [ 2 ] = { 0 , 0 } ;
unsigned long V_394 [ 2 ] = { 0 , 0 } ;
F_383 (nid)
for ( V_36 = 0 ; V_36 < V_61 ; V_36 ++ ) {
V_44 = & V_2 -> V_37 [ V_35 ] -> V_38 [ V_36 ] ;
V_392 = & V_44 -> V_82 . V_395 ;
V_393 [ 0 ] += V_392 -> V_393 [ 0 ] ;
V_393 [ 1 ] += V_392 -> V_393 [ 1 ] ;
V_394 [ 0 ] += V_392 -> V_394 [ 0 ] ;
V_394 [ 1 ] += V_392 -> V_394 [ 1 ] ;
}
F_377 ( V_295 , L_26 , V_393 [ 0 ] ) ;
F_377 ( V_295 , L_27 , V_393 [ 1 ] ) ;
F_377 ( V_295 , L_28 , V_394 [ 0 ] ) ;
F_377 ( V_295 , L_29 , V_394 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_384 ( struct V_10 * V_12 ,
struct V_362 * V_363 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
return F_128 ( V_2 ) ;
}
static int F_385 ( struct V_10 * V_12 ,
struct V_362 * V_363 , T_2 V_67 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_67 > 100 )
return - V_328 ;
if ( V_12 -> V_50 )
V_2 -> V_156 = V_67 ;
else
V_155 = V_67 ;
return 0 ;
}
static void F_386 ( struct V_1 * V_2 , bool V_366 )
{
struct V_396 * V_397 ;
T_2 V_352 ;
int V_168 ;
F_22 () ;
if ( ! V_366 )
V_397 = F_96 ( V_2 -> V_398 . V_399 ) ;
else
V_397 = F_96 ( V_2 -> V_400 . V_399 ) ;
if ( ! V_397 )
goto V_161;
V_352 = F_352 ( V_2 , V_366 ) ;
V_168 = V_397 -> V_401 ;
for (; V_168 >= 0 && F_91 ( V_397 -> V_402 [ V_168 ] . V_403 > V_352 ) ; V_168 -- )
F_387 ( V_397 -> V_402 [ V_168 ] . V_404 , 1 ) ;
V_168 ++ ;
for (; V_168 < V_397 -> V_272 && F_91 ( V_397 -> V_402 [ V_168 ] . V_403 <= V_352 ) ; V_168 ++ )
F_387 ( V_397 -> V_402 [ V_168 ] . V_404 , 1 ) ;
V_397 -> V_401 = V_168 - 1 ;
V_161:
F_26 () ;
}
static void F_92 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_386 ( V_2 , false ) ;
if ( V_153 )
F_386 ( V_2 , true ) ;
V_2 = F_57 ( V_2 ) ;
}
}
static int F_388 ( const void * V_405 , const void * V_406 )
{
const struct F_92 * V_407 = V_405 ;
const struct F_92 * V_408 = V_406 ;
if ( V_407 -> V_403 > V_408 -> V_403 )
return 1 ;
if ( V_407 -> V_403 < V_408 -> V_403 )
return - 1 ;
return 0 ;
}
static int F_389 ( struct V_1 * V_2 )
{
struct V_409 * V_410 ;
F_71 ( & V_214 ) ;
F_261 (ev, &memcg->oom_notify, list)
F_387 ( V_410 -> V_404 , 1 ) ;
F_72 ( & V_214 ) ;
return 0 ;
}
static void F_199 ( struct V_1 * V_2 )
{
struct V_1 * V_116 ;
F_147 (iter, memcg)
F_389 ( V_116 ) ;
}
static int F_390 ( struct V_1 * V_2 ,
struct V_411 * V_404 , const char * args , enum V_367 type )
{
struct V_412 * V_398 ;
struct V_396 * V_413 ;
T_2 V_403 , V_352 ;
int V_168 , V_272 , V_142 ;
V_142 = F_367 ( args , & V_403 ) ;
if ( V_142 )
return V_142 ;
F_143 ( & V_2 -> V_414 ) ;
if ( type == V_369 ) {
V_398 = & V_2 -> V_398 ;
V_352 = F_352 ( V_2 , false ) ;
} else if ( type == V_370 ) {
V_398 = & V_2 -> V_400 ;
V_352 = F_352 ( V_2 , true ) ;
} else
F_110 () ;
if ( V_398 -> V_399 )
F_386 ( V_2 , type == V_370 ) ;
V_272 = V_398 -> V_399 ? V_398 -> V_399 -> V_272 + 1 : 1 ;
V_413 = F_294 ( sizeof( * V_413 ) + V_272 * sizeof( struct F_92 ) ,
V_309 ) ;
if ( ! V_413 ) {
V_142 = - V_280 ;
goto V_161;
}
V_413 -> V_272 = V_272 ;
if ( V_398 -> V_399 ) {
memcpy ( V_413 -> V_402 , V_398 -> V_399 -> V_402 , ( V_272 - 1 ) *
sizeof( struct F_92 ) ) ;
}
V_413 -> V_402 [ V_272 - 1 ] . V_404 = V_404 ;
V_413 -> V_402 [ V_272 - 1 ] . V_403 = V_403 ;
F_391 ( V_413 -> V_402 , V_272 , sizeof( struct F_92 ) ,
F_388 , NULL ) ;
V_413 -> V_401 = - 1 ;
for ( V_168 = 0 ; V_168 < V_272 ; V_168 ++ ) {
if ( V_413 -> V_402 [ V_168 ] . V_403 <= V_352 ) {
++ V_413 -> V_401 ;
} else
break;
}
F_276 ( V_398 -> V_415 ) ;
V_398 -> V_415 = V_398 -> V_399 ;
F_271 ( V_398 -> V_399 , V_413 ) ;
F_130 () ;
V_161:
F_150 ( & V_2 -> V_414 ) ;
return V_142 ;
}
static int F_392 ( struct V_1 * V_2 ,
struct V_411 * V_404 , const char * args )
{
return F_390 ( V_2 , V_404 , args , V_369 ) ;
}
static int F_393 ( struct V_1 * V_2 ,
struct V_411 * V_404 , const char * args )
{
return F_390 ( V_2 , V_404 , args , V_370 ) ;
}
static void F_394 ( struct V_1 * V_2 ,
struct V_411 * V_404 , enum V_367 type )
{
struct V_412 * V_398 ;
struct V_396 * V_413 ;
T_2 V_352 ;
int V_168 , V_416 , V_272 ;
F_143 ( & V_2 -> V_414 ) ;
if ( type == V_369 ) {
V_398 = & V_2 -> V_398 ;
V_352 = F_352 ( V_2 , false ) ;
} else if ( type == V_370 ) {
V_398 = & V_2 -> V_400 ;
V_352 = F_352 ( V_2 , true ) ;
} else
F_110 () ;
if ( ! V_398 -> V_399 )
goto V_161;
F_386 ( V_2 , type == V_370 ) ;
V_272 = 0 ;
for ( V_168 = 0 ; V_168 < V_398 -> V_399 -> V_272 ; V_168 ++ ) {
if ( V_398 -> V_399 -> V_402 [ V_168 ] . V_404 != V_404 )
V_272 ++ ;
}
V_413 = V_398 -> V_415 ;
if ( ! V_272 ) {
F_276 ( V_413 ) ;
V_413 = NULL ;
goto V_417;
}
V_413 -> V_272 = V_272 ;
V_413 -> V_401 = - 1 ;
for ( V_168 = 0 , V_416 = 0 ; V_168 < V_398 -> V_399 -> V_272 ; V_168 ++ ) {
if ( V_398 -> V_399 -> V_402 [ V_168 ] . V_404 == V_404 )
continue;
V_413 -> V_402 [ V_416 ] = V_398 -> V_399 -> V_402 [ V_168 ] ;
if ( V_413 -> V_402 [ V_416 ] . V_403 <= V_352 ) {
++ V_413 -> V_401 ;
}
V_416 ++ ;
}
V_417:
V_398 -> V_415 = V_398 -> V_399 ;
if ( ! V_413 ) {
F_276 ( V_398 -> V_415 ) ;
V_398 -> V_415 = NULL ;
}
F_271 ( V_398 -> V_399 , V_413 ) ;
F_130 () ;
V_161:
F_150 ( & V_2 -> V_414 ) ;
}
static void F_395 ( struct V_1 * V_2 ,
struct V_411 * V_404 )
{
return F_394 ( V_2 , V_404 , V_369 ) ;
}
static void F_396 ( struct V_1 * V_2 ,
struct V_411 * V_404 )
{
return F_394 ( V_2 , V_404 , V_370 ) ;
}
static int F_397 ( struct V_1 * V_2 ,
struct V_411 * V_404 , const char * args )
{
struct V_409 * V_418 ;
V_418 = F_294 ( sizeof( * V_418 ) , V_309 ) ;
if ( ! V_418 )
return - V_280 ;
F_71 ( & V_214 ) ;
V_418 -> V_404 = V_404 ;
F_281 ( & V_418 -> V_313 , & V_2 -> V_419 ) ;
if ( F_102 ( & V_2 -> V_218 ) )
F_387 ( V_404 , 1 ) ;
F_72 ( & V_214 ) ;
return 0 ;
}
static void F_398 ( struct V_1 * V_2 ,
struct V_411 * V_404 )
{
struct V_409 * V_410 , * V_317 ;
F_71 ( & V_214 ) ;
F_290 (ev, tmp, &memcg->oom_notify, list) {
if ( V_410 -> V_404 == V_404 ) {
F_283 ( & V_410 -> V_313 ) ;
F_276 ( V_410 ) ;
}
}
F_72 ( & V_214 ) ;
}
static int F_399 ( struct V_294 * V_420 , void * V_296 )
{
struct V_1 * V_2 = F_11 ( F_259 ( V_420 ) ) ;
F_377 ( V_420 , L_30 , V_2 -> V_239 ) ;
F_377 ( V_420 , L_31 , ( bool ) F_102 ( & V_2 -> V_218 ) ) ;
return 0 ;
}
static int F_400 ( struct V_10 * V_12 ,
struct V_362 * V_363 , T_2 V_67 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( ! V_12 -> V_50 || ! ( ( V_67 == 0 ) || ( V_67 == 1 ) ) )
return - V_328 ;
V_2 -> V_239 = V_67 ;
if ( ! V_67 )
F_195 ( V_2 ) ;
return 0 ;
}
static int F_401 ( struct V_1 * V_2 , struct V_421 * V_422 )
{
int V_142 ;
V_2 -> V_30 = - 1 ;
V_142 = F_363 ( V_2 ) ;
if ( V_142 )
return V_142 ;
return F_402 ( V_2 , V_422 ) ;
}
static void F_403 ( struct V_1 * V_2 )
{
F_404 ( V_2 ) ;
}
static void F_405 ( struct V_1 * V_2 )
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
static int F_401 ( struct V_1 * V_2 , struct V_421 * V_422 )
{
return 0 ;
}
static void F_403 ( struct V_1 * V_2 )
{
}
static void F_405 ( struct V_1 * V_2 )
{
}
static void F_406 ( struct V_249 * V_252 )
{
struct V_423 * V_418 =
F_12 ( V_252 , struct V_423 , remove ) ;
struct V_1 * V_2 = V_418 -> V_2 ;
F_407 ( V_418 -> V_424 , & V_418 -> V_163 ) ;
V_418 -> V_425 ( V_2 , V_418 -> V_404 ) ;
F_387 ( V_418 -> V_404 , 1 ) ;
F_408 ( V_418 -> V_404 ) ;
F_276 ( V_418 ) ;
F_29 ( & V_2 -> V_12 ) ;
}
static int F_409 ( T_4 * V_163 , unsigned V_219 ,
int V_220 , void * V_426 )
{
struct V_423 * V_418 =
F_12 ( V_163 , struct V_423 , V_163 ) ;
struct V_1 * V_2 = V_418 -> V_2 ;
unsigned long V_57 = ( unsigned long ) V_426 ;
if ( V_57 & V_427 ) {
F_71 ( & V_2 -> V_428 ) ;
if ( ! F_337 ( & V_418 -> V_313 ) ) {
F_410 ( & V_418 -> V_313 ) ;
F_295 ( & V_418 -> remove ) ;
}
F_72 ( & V_2 -> V_428 ) ;
}
return 0 ;
}
static void F_411 ( struct V_429 * V_429 ,
T_10 * V_424 , T_11 * V_430 )
{
struct V_423 * V_418 =
F_12 ( V_430 , struct V_423 , V_430 ) ;
V_418 -> V_424 = V_424 ;
F_412 ( V_424 , & V_418 -> V_163 ) ;
}
static T_8 F_413 ( struct V_357 * V_358 ,
char * V_359 , T_7 V_360 , T_9 V_361 )
{
struct V_10 * V_12 = F_348 ( V_358 ) ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_423 * V_418 ;
struct V_10 * V_431 ;
unsigned int V_432 , V_433 ;
struct V_434 V_435 ;
struct V_434 V_436 ;
const char * V_368 ;
char * V_437 ;
int V_142 ;
V_359 = F_365 ( V_359 ) ;
V_432 = F_414 ( V_359 , & V_437 , 10 ) ;
if ( * V_437 != ' ' )
return - V_328 ;
V_359 = V_437 + 1 ;
V_433 = F_414 ( V_359 , & V_437 , 10 ) ;
if ( ( * V_437 != ' ' ) && ( * V_437 != '\0' ) )
return - V_328 ;
V_359 = V_437 + 1 ;
V_418 = F_270 ( sizeof( * V_418 ) , V_309 ) ;
if ( ! V_418 )
return - V_280 ;
V_418 -> V_2 = V_2 ;
F_198 ( & V_418 -> V_313 ) ;
F_415 ( & V_418 -> V_430 , F_411 ) ;
F_416 ( & V_418 -> V_163 , F_409 ) ;
F_215 ( & V_418 -> remove , F_406 ) ;
V_435 = F_417 ( V_432 ) ;
if ( ! V_435 . V_429 ) {
V_142 = - V_438 ;
goto V_439;
}
V_418 -> V_404 = F_418 ( V_435 . V_429 ) ;
if ( F_419 ( V_418 -> V_404 ) ) {
V_142 = F_420 ( V_418 -> V_404 ) ;
goto V_440;
}
V_436 = F_417 ( V_433 ) ;
if ( ! V_436 . V_429 ) {
V_142 = - V_438 ;
goto V_441;
}
V_142 = F_421 ( F_422 ( V_436 . V_429 ) , V_442 ) ;
if ( V_142 < 0 )
goto V_443;
V_368 = V_436 . V_429 -> V_444 -> V_445 . V_368 ;
if ( ! strcmp ( V_368 , L_32 ) ) {
V_418 -> V_446 = F_392 ;
V_418 -> V_425 = F_395 ;
} else if ( ! strcmp ( V_368 , L_33 ) ) {
V_418 -> V_446 = F_397 ;
V_418 -> V_425 = F_398 ;
} else if ( ! strcmp ( V_368 , L_34 ) ) {
V_418 -> V_446 = V_447 ;
V_418 -> V_425 = V_448 ;
} else if ( ! strcmp ( V_368 , L_35 ) ) {
V_418 -> V_446 = F_393 ;
V_418 -> V_425 = F_396 ;
} else {
V_142 = - V_328 ;
goto V_443;
}
V_431 = F_423 ( V_436 . V_429 -> V_444 -> V_449 ,
& V_17 ) ;
V_142 = - V_328 ;
if ( F_419 ( V_431 ) )
goto V_443;
if ( V_431 != V_12 ) {
F_29 ( V_431 ) ;
goto V_443;
}
V_142 = V_418 -> V_446 ( V_2 , V_418 -> V_404 , V_359 ) ;
if ( V_142 )
goto V_450;
V_435 . V_429 -> V_451 -> V_452 ( V_435 . V_429 , & V_418 -> V_430 ) ;
F_71 ( & V_2 -> V_428 ) ;
F_281 ( & V_418 -> V_313 , & V_2 -> V_453 ) ;
F_72 ( & V_2 -> V_428 ) ;
F_424 ( V_436 ) ;
F_424 ( V_435 ) ;
return V_360 ;
V_450:
F_29 ( V_12 ) ;
V_443:
F_424 ( V_436 ) ;
V_441:
F_408 ( V_418 -> V_404 ) ;
V_440:
F_424 ( V_435 ) ;
V_439:
F_276 ( V_418 ) ;
return V_142 ;
}
static int F_425 ( struct V_1 * V_2 , int V_208 )
{
struct V_454 * V_455 ;
struct V_33 * V_44 ;
int V_34 , V_317 = V_208 ;
if ( ! F_426 ( V_208 , V_456 ) )
V_317 = - 1 ;
V_455 = F_427 ( sizeof( * V_455 ) , V_309 , V_317 ) ;
if ( ! V_455 )
return 1 ;
for ( V_34 = 0 ; V_34 < V_61 ; V_34 ++ ) {
V_44 = & V_455 -> V_38 [ V_34 ] ;
F_428 ( & V_44 -> V_82 ) ;
V_44 -> V_53 = 0 ;
V_44 -> V_52 = false ;
V_44 -> V_2 = V_2 ;
}
V_2 -> V_37 [ V_208 ] = V_455 ;
return 0 ;
}
static void F_429 ( struct V_1 * V_2 , int V_208 )
{
F_276 ( V_2 -> V_37 [ V_208 ] ) ;
}
static struct V_1 * F_430 ( void )
{
struct V_1 * V_2 ;
T_7 V_272 ;
V_272 = sizeof( struct V_1 ) ;
V_272 += V_88 * sizeof( struct V_454 * ) ;
V_2 = F_270 ( V_272 , V_309 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_69 = F_431 ( struct V_457 ) ;
if ( ! V_2 -> V_69 )
goto V_458;
F_432 ( & V_2 -> V_71 ) ;
return V_2 ;
V_458:
F_276 ( V_2 ) ;
return NULL ;
}
static void F_433 ( struct V_1 * V_2 )
{
int V_208 ;
F_59 ( V_2 ) ;
F_60 (node)
F_429 ( V_2 , V_208 ) ;
F_434 ( V_2 -> V_69 ) ;
F_37 ( V_2 ) ;
F_276 ( V_2 ) ;
}
struct V_1 * F_57 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_60 . V_50 )
return NULL ;
return F_231 ( V_2 -> V_60 . V_50 , V_60 ) ;
}
static void T_5 F_435 ( void )
{
struct V_459 * V_460 ;
struct V_40 * V_461 ;
int V_317 , V_208 , V_34 ;
F_60 (node) {
V_317 = V_208 ;
if ( ! F_426 ( V_208 , V_456 ) )
V_317 = - 1 ;
V_460 = F_427 ( sizeof( * V_460 ) , V_309 , V_317 ) ;
F_20 ( ! V_460 ) ;
V_41 . V_42 [ V_208 ] = V_460 ;
for ( V_34 = 0 ; V_34 < V_61 ; V_34 ++ ) {
V_461 = & V_460 -> V_43 [ V_34 ] ;
V_461 -> V_49 = V_462 ;
F_432 ( & V_461 -> V_58 ) ;
}
}
}
static struct V_10 * T_12
F_436 ( struct V_10 * V_463 )
{
struct V_1 * V_2 ;
long error = - V_280 ;
int V_208 ;
V_2 = F_430 () ;
if ( ! V_2 )
return F_437 ( error ) ;
F_60 (node)
if ( F_425 ( V_2 , V_208 ) )
goto V_464;
if ( V_463 == NULL ) {
V_14 = V_2 ;
F_438 ( & V_2 -> V_60 , NULL ) ;
F_438 ( & V_2 -> V_154 , NULL ) ;
F_438 ( & V_2 -> V_31 , NULL ) ;
}
V_2 -> V_209 = V_101 ;
F_198 ( & V_2 -> V_419 ) ;
V_2 -> V_383 = 0 ;
F_439 ( & V_2 -> V_414 ) ;
F_432 ( & V_2 -> V_166 ) ;
F_440 ( & V_2 -> V_13 ) ;
F_198 ( & V_2 -> V_453 ) ;
F_432 ( & V_2 -> V_428 ) ;
return & V_2 -> V_12 ;
V_464:
F_433 ( V_2 ) ;
return F_437 ( error ) ;
}
static int
F_441 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_50 = F_11 ( V_12 -> V_50 ) ;
int V_142 ;
if ( V_12 -> V_16 > V_465 )
return - V_466 ;
if ( ! V_50 )
return 0 ;
F_143 ( & V_353 ) ;
V_2 -> V_124 = V_50 -> V_124 ;
V_2 -> V_239 = V_50 -> V_239 ;
V_2 -> V_156 = F_128 ( V_50 ) ;
if ( V_50 -> V_124 ) {
F_438 ( & V_2 -> V_60 , & V_50 -> V_60 ) ;
F_438 ( & V_2 -> V_154 , & V_50 -> V_154 ) ;
F_438 ( & V_2 -> V_31 , & V_50 -> V_31 ) ;
} else {
F_438 ( & V_2 -> V_60 , NULL ) ;
F_438 ( & V_2 -> V_154 , NULL ) ;
F_438 ( & V_2 -> V_31 , NULL ) ;
if ( V_50 != V_14 )
V_17 . V_467 = true ;
}
F_150 ( & V_353 ) ;
V_142 = F_401 ( V_2 , & V_17 ) ;
if ( V_142 )
return V_142 ;
F_442 ( & V_2 -> V_113 , 1 ) ;
return 0 ;
}
static void F_443 ( struct V_1 * V_2 )
{
struct V_1 * V_50 = V_2 ;
while ( ( V_50 = F_57 ( V_50 ) ) )
F_100 ( V_50 ) ;
if ( ! V_14 -> V_124 )
F_100 ( V_14 ) ;
}
static void F_444 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_423 * V_418 , * V_317 ;
struct V_10 * V_116 ;
F_71 ( & V_2 -> V_428 ) ;
F_290 (event, tmp, &memcg->event_list, list) {
F_410 ( & V_418 -> V_313 ) ;
F_295 ( & V_418 -> remove ) ;
}
F_72 ( & V_2 -> V_428 ) ;
F_405 ( V_2 ) ;
F_443 ( V_2 ) ;
F_445 (iter, css)
F_341 ( F_11 ( V_116 ) ) ;
F_289 ( V_2 ) ;
F_446 ( & V_2 -> V_13 ) ;
}
static void F_447 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_341 ( V_2 ) ;
F_403 ( V_2 ) ;
F_433 ( V_2 ) ;
}
static void F_448 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_330 ( V_2 , V_468 ) ;
F_333 ( V_2 , V_468 ) ;
F_362 ( V_2 , V_468 ) ;
F_368 ( & V_2 -> V_60 , V_468 ) ;
}
static int F_449 ( unsigned long V_70 )
{
int V_142 ;
V_142 = F_228 ( V_7 . V_160 , V_309 & ~ V_276 , V_70 ) ;
if ( ! V_142 ) {
V_7 . V_469 += V_70 ;
return V_142 ;
}
if ( V_142 == - V_281 ) {
F_235 ( V_14 , V_70 ) ;
return V_142 ;
}
while ( V_70 -- ) {
V_142 = F_228 ( V_7 . V_160 , V_309 & ~ V_277 , 1 ) ;
if ( V_142 == - V_281 )
F_235 ( V_14 , 1 ) ;
if ( V_142 )
return V_142 ;
V_7 . V_469 ++ ;
F_340 () ;
}
return 0 ;
}
static struct V_39 * F_450 ( struct V_470 * V_471 ,
unsigned long V_472 , T_13 V_473 )
{
struct V_39 * V_39 = F_451 ( V_471 , V_472 , V_473 ) ;
if ( ! V_39 || ! F_310 ( V_39 ) )
return NULL ;
if ( F_76 ( V_39 ) ) {
if ( ! F_9 () )
return NULL ;
} else if ( ! F_10 () )
return NULL ;
if ( ! F_316 ( V_39 ) )
return NULL ;
return V_39 ;
}
static struct V_39 * F_452 ( struct V_470 * V_471 ,
unsigned long V_472 , T_13 V_473 , T_6 * V_334 )
{
struct V_39 * V_39 = NULL ;
T_6 V_282 = F_453 ( V_473 ) ;
if ( ! F_9 () || F_454 ( V_282 ) )
return NULL ;
V_39 = F_455 ( F_456 ( V_282 ) , V_282 . V_67 ) ;
if ( V_153 )
V_334 -> V_67 = V_282 . V_67 ;
return V_39 ;
}
static struct V_39 * F_452 ( struct V_470 * V_471 ,
unsigned long V_472 , T_13 V_473 , T_6 * V_334 )
{
return NULL ;
}
static struct V_39 * F_457 ( struct V_470 * V_471 ,
unsigned long V_472 , T_13 V_473 , T_6 * V_334 )
{
struct V_39 * V_39 = NULL ;
struct V_474 * V_475 ;
T_14 V_476 ;
if ( ! V_471 -> V_477 )
return NULL ;
if ( ! F_10 () )
return NULL ;
V_475 = V_471 -> V_477 -> V_478 ;
if ( F_458 ( V_473 ) )
V_476 = F_459 ( V_471 , V_472 ) ;
else
V_476 = F_460 ( V_473 ) ;
#ifdef F_461
if ( F_462 ( V_475 ) ) {
V_39 = F_463 ( V_475 , V_476 ) ;
if ( F_464 ( V_39 ) ) {
T_6 V_479 = F_465 ( V_39 ) ;
if ( V_153 )
* V_334 = V_479 ;
V_39 = F_455 ( F_456 ( V_479 ) , V_479 . V_67 ) ;
}
} else
V_39 = F_455 ( V_475 , V_476 ) ;
#else
V_39 = F_455 ( V_475 , V_476 ) ;
#endif
return V_39 ;
}
static enum V_480 F_466 ( struct V_470 * V_471 ,
unsigned long V_472 , T_13 V_473 , union V_481 * V_90 )
{
struct V_39 * V_39 = NULL ;
struct V_138 * V_139 ;
enum V_480 V_142 = V_482 ;
T_6 V_282 = { . V_67 = 0 } ;
if ( F_467 ( V_473 ) )
V_39 = F_450 ( V_471 , V_472 , V_473 ) ;
else if ( F_468 ( V_473 ) )
V_39 = F_452 ( V_471 , V_472 , V_473 , & V_282 ) ;
else if ( F_458 ( V_473 ) || F_469 ( V_473 ) )
V_39 = F_457 ( V_471 , V_472 , V_473 , & V_282 ) ;
if ( ! V_39 && ! V_282 . V_67 )
return V_142 ;
if ( V_39 ) {
V_139 = F_113 ( V_39 ) ;
if ( F_115 ( V_139 ) && V_139 -> V_1 == V_7 . V_159 ) {
V_142 = V_483 ;
if ( V_90 )
V_90 -> V_39 = V_39 ;
}
if ( ! V_142 || ! V_90 )
F_322 ( V_39 ) ;
}
if ( V_282 . V_67 && ! V_142 &&
F_16 ( V_7 . V_159 ) == F_244 ( V_282 ) ) {
V_142 = V_484 ;
if ( V_90 )
V_90 -> V_282 = V_282 ;
}
return V_142 ;
}
static enum V_480 F_470 ( struct V_470 * V_471 ,
unsigned long V_472 , T_15 V_485 , union V_481 * V_90 )
{
struct V_39 * V_39 = NULL ;
struct V_138 * V_139 ;
enum V_480 V_142 = V_482 ;
V_39 = F_471 ( V_485 ) ;
F_240 ( ! V_39 || ! F_472 ( V_39 ) , V_39 ) ;
if ( ! F_9 () )
return V_142 ;
V_139 = F_113 ( V_39 ) ;
if ( F_115 ( V_139 ) && V_139 -> V_1 == V_7 . V_159 ) {
V_142 = V_483 ;
if ( V_90 ) {
F_473 ( V_39 ) ;
V_90 -> V_39 = V_39 ;
}
}
return V_142 ;
}
static inline enum V_480 F_470 ( struct V_470 * V_471 ,
unsigned long V_472 , T_15 V_485 , union V_481 * V_90 )
{
return V_482 ;
}
static int F_474 ( T_15 * V_485 ,
unsigned long V_472 , unsigned long V_486 ,
struct V_487 * V_488 )
{
struct V_470 * V_471 = V_488 -> V_236 ;
T_13 * V_489 ;
T_16 * V_490 ;
if ( F_475 ( V_485 , V_471 , & V_490 ) == 1 ) {
if ( F_470 ( V_471 , V_472 , * V_485 , NULL ) == V_483 )
V_7 . V_469 += V_326 ;
F_72 ( V_490 ) ;
return 0 ;
}
if ( F_476 ( V_485 ) )
return 0 ;
V_489 = F_477 ( V_471 -> V_491 , V_485 , V_472 , & V_490 ) ;
for (; V_472 != V_486 ; V_489 ++ , V_472 += V_248 )
if ( F_466 ( V_471 , V_472 , * V_489 , NULL ) )
V_7 . V_469 ++ ;
F_478 ( V_489 - 1 , V_490 ) ;
F_340 () ;
return 0 ;
}
static unsigned long F_479 ( struct V_105 * V_106 )
{
unsigned long V_469 ;
struct V_470 * V_471 ;
F_480 ( & V_106 -> V_492 ) ;
for ( V_471 = V_106 -> V_493 ; V_471 ; V_471 = V_471 -> V_494 ) {
struct V_487 V_495 = {
. V_496 = F_474 ,
. V_106 = V_106 ,
. V_236 = V_471 ,
} ;
if ( F_481 ( V_471 ) )
continue;
F_482 ( V_471 -> V_497 , V_471 -> V_498 ,
& V_495 ) ;
}
F_483 ( & V_106 -> V_492 ) ;
V_469 = V_7 . V_469 ;
V_7 . V_469 = 0 ;
return V_469 ;
}
static int F_484 ( struct V_105 * V_106 )
{
unsigned long V_469 = F_479 ( V_106 ) ;
F_82 ( V_7 . V_162 ) ;
V_7 . V_162 = V_25 ;
return F_449 ( V_469 ) ;
}
static void F_485 ( void )
{
struct V_1 * V_159 = V_7 . V_159 ;
struct V_1 * V_160 = V_7 . V_160 ;
int V_168 ;
if ( V_7 . V_469 ) {
F_235 ( V_7 . V_160 , V_7 . V_469 ) ;
V_7 . V_469 = 0 ;
}
if ( V_7 . V_499 ) {
F_235 ( V_7 . V_159 , V_7 . V_499 ) ;
V_7 . V_499 = 0 ;
}
if ( V_7 . V_500 ) {
if ( ! F_15 ( V_7 . V_159 ) )
F_209 ( & V_7 . V_159 -> V_154 ,
V_248 * V_7 . V_500 ) ;
for ( V_168 = 0 ; V_168 < V_7 . V_500 ; V_168 ++ )
F_29 ( & V_7 . V_159 -> V_12 ) ;
if ( ! F_15 ( V_7 . V_160 ) )
F_209 ( & V_7 . V_160 -> V_60 ,
V_248 * V_7 . V_500 ) ;
V_7 . V_500 = 0 ;
}
F_195 ( V_159 ) ;
F_195 ( V_160 ) ;
F_486 ( & V_7 . V_164 ) ;
}
static void F_487 ( void )
{
struct V_1 * V_159 = V_7 . V_159 ;
V_7 . V_162 = NULL ;
F_485 () ;
F_71 ( & V_7 . V_58 ) ;
V_7 . V_159 = NULL ;
V_7 . V_160 = NULL ;
F_72 ( & V_7 . V_58 ) ;
F_131 ( V_159 ) ;
}
static int F_488 ( struct V_10 * V_12 ,
struct V_501 * V_502 )
{
struct V_103 * V_48 = F_489 ( V_502 ) ;
int V_142 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned long V_383 ;
V_383 = V_2 -> V_383 ;
if ( V_383 ) {
struct V_105 * V_106 ;
struct V_1 * V_159 = F_23 ( V_48 ) ;
F_82 ( V_159 == V_2 ) ;
V_106 = F_490 ( V_48 ) ;
if ( ! V_106 )
return 0 ;
if ( V_106 -> V_107 == V_48 ) {
F_82 ( V_7 . V_159 ) ;
F_82 ( V_7 . V_160 ) ;
F_82 ( V_7 . V_469 ) ;
F_82 ( V_7 . V_499 ) ;
F_82 ( V_7 . V_500 ) ;
F_129 ( V_159 ) ;
F_71 ( & V_7 . V_58 ) ;
V_7 . V_159 = V_159 ;
V_7 . V_160 = V_2 ;
V_7 . V_8 = V_383 ;
F_72 ( & V_7 . V_58 ) ;
V_142 = F_484 ( V_106 ) ;
if ( V_142 )
F_487 () ;
}
F_491 ( V_106 ) ;
}
return V_142 ;
}
static void F_492 ( struct V_10 * V_12 ,
struct V_501 * V_502 )
{
F_487 () ;
}
static int F_493 ( T_15 * V_485 ,
unsigned long V_472 , unsigned long V_486 ,
struct V_487 * V_488 )
{
int V_142 = 0 ;
struct V_470 * V_471 = V_488 -> V_236 ;
T_13 * V_489 ;
T_16 * V_490 ;
enum V_480 V_503 ;
union V_481 V_90 ;
struct V_39 * V_39 ;
struct V_138 * V_139 ;
if ( F_475 ( V_485 , V_471 , & V_490 ) == 1 ) {
if ( V_7 . V_469 < V_326 ) {
F_72 ( V_490 ) ;
return 0 ;
}
V_503 = F_470 ( V_471 , V_472 , * V_485 , & V_90 ) ;
if ( V_503 == V_483 ) {
V_39 = V_90 . V_39 ;
if ( ! F_317 ( V_39 ) ) {
V_139 = F_113 ( V_39 ) ;
if ( ! F_308 ( V_39 , V_326 ,
V_139 , V_7 . V_159 , V_7 . V_160 ) ) {
V_7 . V_469 -= V_326 ;
V_7 . V_499 += V_326 ;
}
F_321 ( V_39 ) ;
}
F_322 ( V_39 ) ;
}
F_72 ( V_490 ) ;
return 0 ;
}
if ( F_476 ( V_485 ) )
return 0 ;
V_63:
V_489 = F_477 ( V_471 -> V_491 , V_485 , V_472 , & V_490 ) ;
for (; V_472 != V_486 ; V_472 += V_248 ) {
T_13 V_473 = * ( V_489 ++ ) ;
T_6 V_282 ;
if ( ! V_7 . V_469 )
break;
switch ( F_466 ( V_471 , V_472 , V_473 , & V_90 ) ) {
case V_483 :
V_39 = V_90 . V_39 ;
if ( F_317 ( V_39 ) )
goto V_332;
V_139 = F_113 ( V_39 ) ;
if ( ! F_308 ( V_39 , 1 , V_139 ,
V_7 . V_159 , V_7 . V_160 ) ) {
V_7 . V_469 -- ;
V_7 . V_499 ++ ;
}
F_321 ( V_39 ) ;
V_332:
F_322 ( V_39 ) ;
break;
case V_484 :
V_282 = V_90 . V_282 ;
if ( ! F_324 ( V_282 , V_7 . V_159 , V_7 . V_160 ) ) {
V_7 . V_469 -- ;
V_7 . V_500 ++ ;
}
break;
default:
break;
}
}
F_478 ( V_489 - 1 , V_490 ) ;
F_340 () ;
if ( V_472 != V_486 ) {
V_142 = F_449 ( 1 ) ;
if ( ! V_142 )
goto V_63;
}
return V_142 ;
}
static void F_494 ( struct V_105 * V_106 )
{
struct V_470 * V_471 ;
F_342 () ;
V_63:
if ( F_91 ( ! F_495 ( & V_106 -> V_492 ) ) ) {
F_485 () ;
F_340 () ;
goto V_63;
}
for ( V_471 = V_106 -> V_493 ; V_471 ; V_471 = V_471 -> V_494 ) {
int V_142 ;
struct V_487 V_504 = {
. V_496 = F_493 ,
. V_106 = V_106 ,
. V_236 = V_471 ,
} ;
if ( F_481 ( V_471 ) )
continue;
V_142 = F_482 ( V_471 -> V_497 , V_471 -> V_498 ,
& V_504 ) ;
if ( V_142 )
break;
}
F_483 ( & V_106 -> V_492 ) ;
}
static void F_496 ( struct V_10 * V_12 ,
struct V_501 * V_502 )
{
struct V_103 * V_48 = F_489 ( V_502 ) ;
struct V_105 * V_106 = F_490 ( V_48 ) ;
if ( V_106 ) {
if ( V_7 . V_160 )
F_494 ( V_106 ) ;
F_491 ( V_106 ) ;
}
if ( V_7 . V_160 )
F_487 () ;
}
static int F_488 ( struct V_10 * V_12 ,
struct V_501 * V_502 )
{
return 0 ;
}
static void F_492 ( struct V_10 * V_12 ,
struct V_501 * V_502 )
{
}
static void F_496 ( struct V_10 * V_12 ,
struct V_501 * V_502 )
{
}
static void F_497 ( struct V_10 * V_505 )
{
if ( F_498 ( V_505 -> V_141 ) )
F_11 ( V_505 ) -> V_124 = true ;
}
static int T_5 F_499 ( char * V_11 )
{
if ( ! strcmp ( V_11 , L_36 ) )
V_506 = 1 ;
else if ( ! strcmp ( V_11 , L_37 ) )
V_506 = 0 ;
return 1 ;
}
static void T_5 F_500 ( void )
{
F_28 ( F_501 ( & V_17 ,
V_507 ) ) ;
}
static void T_5 F_502 ( void )
{
if ( ! F_106 () && V_506 ) {
V_153 = 1 ;
F_500 () ;
}
}
static void T_5 F_502 ( void )
{
}
void F_503 ( struct V_39 * V_39 , T_6 V_334 )
{
struct V_138 * V_139 ;
unsigned short V_508 ;
F_240 ( F_114 ( V_39 ) , V_39 ) ;
F_240 ( F_504 ( V_39 ) , V_39 ) ;
if ( ! V_153 )
return;
V_139 = F_113 ( V_39 ) ;
if ( ! F_115 ( V_139 ) )
return;
F_240 ( ! ( V_139 -> V_57 & V_288 ) , V_39 ) ;
V_508 = F_505 ( V_334 , F_16 ( V_139 -> V_1 ) ) ;
F_240 ( V_508 , V_39 ) ;
V_139 -> V_57 &= ~ V_288 ;
F_21 ( & V_139 -> V_1 -> V_12 ) ;
F_323 ( V_139 -> V_1 , true ) ;
}
void F_506 ( T_6 V_334 )
{
struct V_1 * V_2 ;
unsigned short V_16 ;
if ( ! V_153 )
return;
V_16 = F_505 ( V_334 , 0 ) ;
F_22 () ;
V_2 = F_238 ( V_16 ) ;
if ( V_2 ) {
if ( ! F_15 ( V_2 ) )
F_209 ( & V_2 -> V_154 , V_248 ) ;
F_323 ( V_2 , false ) ;
F_29 ( & V_2 -> V_12 ) ;
}
F_26 () ;
}
int F_507 ( struct V_39 * V_39 , struct V_105 * V_106 ,
T_3 V_179 , struct V_1 * * V_509 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_75 = 1 ;
int V_142 = 0 ;
if ( F_106 () )
goto V_133;
if ( F_242 ( V_39 ) ) {
struct V_138 * V_139 = F_113 ( V_39 ) ;
if ( F_115 ( V_139 ) )
goto V_133;
}
if ( F_78 ( V_39 ) ) {
V_75 <<= F_508 ( V_39 ) ;
F_240 ( ! F_78 ( V_39 ) , V_39 ) ;
}
if ( V_153 && F_242 ( V_39 ) )
V_2 = F_239 ( V_39 ) ;
if ( ! V_2 )
V_2 = F_95 ( V_106 ) ;
V_142 = F_228 ( V_2 , V_179 , V_75 ) ;
F_29 ( & V_2 -> V_12 ) ;
if ( V_142 == - V_281 ) {
V_2 = V_14 ;
V_142 = 0 ;
}
V_133:
* V_509 = V_2 ;
return V_142 ;
}
void F_509 ( struct V_39 * V_39 , struct V_1 * V_2 ,
bool V_285 )
{
unsigned int V_75 = 1 ;
F_240 ( ! V_39 -> V_475 , V_39 ) ;
F_240 ( F_114 ( V_39 ) && ! V_285 , V_39 ) ;
if ( F_106 () )
return;
if ( ! V_2 )
return;
F_253 ( V_39 , V_2 , V_285 ) ;
if ( F_78 ( V_39 ) ) {
V_75 <<= F_508 ( V_39 ) ;
F_240 ( ! F_78 ( V_39 ) , V_39 ) ;
}
F_312 () ;
F_75 ( V_2 , V_39 , V_75 ) ;
F_90 ( V_2 , V_39 ) ;
F_313 () ;
if ( V_153 && F_242 ( V_39 ) ) {
T_6 V_334 = { . V_67 = F_243 (page) } ;
F_506 ( V_334 ) ;
}
}
void F_510 ( struct V_39 * V_39 , struct V_1 * V_2 )
{
unsigned int V_75 = 1 ;
if ( F_106 () )
return;
if ( ! V_2 )
return;
if ( F_78 ( V_39 ) ) {
V_75 <<= F_508 ( V_39 ) ;
F_240 ( ! F_78 ( V_39 ) , V_39 ) ;
}
F_235 ( V_2 , V_75 ) ;
}
static void F_511 ( struct V_1 * V_2 , unsigned long V_510 ,
unsigned long V_511 , unsigned long V_512 ,
unsigned long V_513 , unsigned long V_514 ,
unsigned long V_515 , struct V_39 * V_516 )
{
unsigned long V_57 ;
if ( ! F_15 ( V_2 ) ) {
if ( V_511 )
F_209 ( & V_2 -> V_60 ,
V_511 * V_248 ) ;
if ( V_512 )
F_209 ( & V_2 -> V_154 ,
V_512 * V_248 ) ;
F_195 ( V_2 ) ;
}
F_512 ( V_57 ) ;
F_307 ( V_2 -> V_69 -> V_70 [ V_76 ] , V_513 ) ;
F_307 ( V_2 -> V_69 -> V_70 [ V_77 ] , V_514 ) ;
F_307 ( V_2 -> V_69 -> V_70 [ V_78 ] , V_515 ) ;
F_77 ( V_2 -> V_69 -> V_74 [ V_80 ] , V_510 ) ;
F_77 ( V_2 -> V_69 -> V_81 , V_513 + V_514 ) ;
F_90 ( V_2 , V_516 ) ;
F_513 ( V_57 ) ;
}
static void F_514 ( struct V_348 * V_517 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_512 = 0 ;
unsigned long V_513 = 0 ;
unsigned long V_514 = 0 ;
unsigned long V_515 = 0 ;
unsigned long V_510 = 0 ;
unsigned long V_511 = 0 ;
struct V_348 * V_91 ;
struct V_39 * V_39 ;
V_91 = V_517 -> V_91 ;
do {
unsigned int V_75 = 1 ;
struct V_138 * V_139 ;
V_39 = F_338 ( V_91 , struct V_39 , V_84 ) ;
V_91 = V_39 -> V_84 . V_91 ;
F_240 ( F_114 ( V_39 ) , V_39 ) ;
F_240 ( F_504 ( V_39 ) , V_39 ) ;
V_139 = F_113 ( V_39 ) ;
if ( ! F_115 ( V_139 ) )
continue;
if ( V_2 != V_139 -> V_1 ) {
if ( V_2 ) {
F_511 ( V_2 , V_510 , V_511 , V_512 ,
V_513 , V_514 , V_515 , V_39 ) ;
V_510 = V_511 = V_512 = 0 ;
V_513 = V_514 = V_515 = 0 ;
}
V_2 = V_139 -> V_1 ;
}
if ( F_78 ( V_39 ) ) {
V_75 <<= F_508 ( V_39 ) ;
F_240 ( ! F_78 ( V_39 ) , V_39 ) ;
V_515 += V_75 ;
}
if ( F_76 ( V_39 ) )
V_513 += V_75 ;
else
V_514 += V_75 ;
if ( V_139 -> V_57 & V_287 )
V_511 += V_75 ;
if ( V_139 -> V_57 & V_288 )
V_512 += V_75 ;
V_139 -> V_57 = 0 ;
V_510 ++ ;
} while ( V_91 != V_517 );
if ( V_2 )
F_511 ( V_2 , V_510 , V_511 , V_512 ,
V_513 , V_514 , V_515 , V_39 ) ;
}
void F_515 ( struct V_39 * V_39 )
{
struct V_138 * V_139 ;
if ( F_106 () )
return;
V_139 = F_113 ( V_39 ) ;
if ( ! F_115 ( V_139 ) )
return;
F_198 ( & V_39 -> V_84 ) ;
F_514 ( & V_39 -> V_84 ) ;
}
void F_516 ( struct V_348 * V_517 )
{
if ( F_106 () )
return;
if ( ! F_337 ( V_517 ) )
F_514 ( V_517 ) ;
}
void F_517 ( struct V_39 * V_518 , struct V_39 * V_519 ,
bool V_285 )
{
struct V_138 * V_139 ;
int V_283 ;
F_240 ( ! F_241 ( V_518 ) , V_518 ) ;
F_240 ( ! F_241 ( V_519 ) , V_519 ) ;
F_240 ( ! V_285 && F_114 ( V_518 ) , V_518 ) ;
F_240 ( ! V_285 && F_114 ( V_519 ) , V_519 ) ;
F_240 ( F_76 ( V_518 ) != F_76 ( V_519 ) , V_519 ) ;
F_240 ( F_78 ( V_518 ) != F_78 ( V_519 ) ,
V_519 ) ;
if ( F_106 () )
return;
V_139 = F_113 ( V_519 ) ;
if ( F_115 ( V_139 ) )
return;
V_139 = F_113 ( V_518 ) ;
if ( ! F_115 ( V_139 ) )
return;
F_240 ( ! ( V_139 -> V_57 & V_287 ) , V_518 ) ;
F_240 ( V_153 && ! ( V_139 -> V_57 & V_288 ) , V_518 ) ;
if ( V_285 )
F_245 ( V_518 , & V_283 ) ;
V_139 -> V_57 = 0 ;
if ( V_285 )
F_250 ( V_518 , V_283 ) ;
F_253 ( V_519 , V_139 -> V_1 , V_285 ) ;
}
static int T_5 F_518 ( void )
{
F_519 ( F_226 , 0 ) ;
F_502 () ;
F_435 () ;
F_213 () ;
return 0 ;
}
