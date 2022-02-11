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
F_35 ( V_2 -> V_29 ) ;
}
F_28 ( F_36 ( & V_2 -> V_30 , V_31 ) != 0 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
}
static void F_37 ( struct V_1 * V_2 )
{
F_31 ( V_2 ) ;
F_34 ( V_2 ) ;
}
static struct V_32 *
F_38 ( struct V_1 * V_2 , struct V_33 * V_33 )
{
int V_34 = F_39 ( V_33 ) ;
int V_35 = F_40 ( V_33 ) ;
return & V_2 -> V_36 [ V_34 ] -> V_37 [ V_35 ] ;
}
struct V_10 * F_41 ( struct V_1 * V_2 )
{
return & V_2 -> V_12 ;
}
static struct V_32 *
F_42 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
int V_34 = F_43 ( V_38 ) ;
int V_35 = F_44 ( V_38 ) ;
return & V_2 -> V_36 [ V_34 ] -> V_37 [ V_35 ] ;
}
static struct V_39 *
F_45 ( int V_34 , int V_35 )
{
return & V_40 . V_41 [ V_34 ] -> V_42 [ V_35 ] ;
}
static struct V_39 *
F_46 ( struct V_38 * V_38 )
{
int V_34 = F_43 ( V_38 ) ;
int V_35 = F_44 ( V_38 ) ;
return & V_40 . V_41 [ V_34 ] -> V_42 [ V_35 ] ;
}
static void F_47 ( struct V_32 * V_43 ,
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
V_50 = F_48 ( V_49 , struct V_32 ,
V_53 ) ;
if ( V_43 -> V_52 < V_50 -> V_52 )
V_47 = & ( * V_47 ) -> V_54 ;
else if ( V_43 -> V_52 >= V_50 -> V_52 )
V_47 = & ( * V_47 ) -> V_55 ;
}
F_49 ( & V_43 -> V_53 , V_49 , V_47 ) ;
F_50 ( & V_43 -> V_53 , & V_44 -> V_48 ) ;
V_43 -> V_51 = true ;
}
static void F_51 ( struct V_32 * V_43 ,
struct V_39 * V_44 )
{
if ( ! V_43 -> V_51 )
return;
F_52 ( & V_43 -> V_53 , & V_44 -> V_48 ) ;
V_43 -> V_51 = false ;
}
static void F_53 ( struct V_32 * V_43 ,
struct V_39 * V_44 )
{
unsigned long V_56 ;
F_54 ( & V_44 -> V_57 , V_56 ) ;
F_51 ( V_43 , V_44 ) ;
F_55 ( & V_44 -> V_57 , V_56 ) ;
}
static void F_56 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
unsigned long long V_58 ;
struct V_32 * V_43 ;
struct V_39 * V_44 ;
V_44 = F_46 ( V_38 ) ;
for (; V_2 ; V_2 = F_57 ( V_2 ) ) {
V_43 = F_42 ( V_2 , V_38 ) ;
V_58 = F_58 ( & V_2 -> V_59 ) ;
if ( V_58 || V_43 -> V_51 ) {
unsigned long V_56 ;
F_54 ( & V_44 -> V_57 , V_56 ) ;
if ( V_43 -> V_51 )
F_51 ( V_43 , V_44 ) ;
F_47 ( V_43 , V_44 , V_58 ) ;
F_55 ( & V_44 -> V_57 , V_56 ) ;
}
}
}
static void F_59 ( struct V_1 * V_2 )
{
struct V_39 * V_44 ;
struct V_32 * V_43 ;
int V_34 , V_35 ;
F_60 (nid) {
for ( V_35 = 0 ; V_35 < V_60 ; V_35 ++ ) {
V_43 = & V_2 -> V_36 [ V_34 ] -> V_37 [ V_35 ] ;
V_44 = F_45 ( V_34 , V_35 ) ;
F_53 ( V_43 , V_44 ) ;
}
}
}
static struct V_32 *
F_61 ( struct V_39 * V_44 )
{
struct V_46 * V_61 = NULL ;
struct V_32 * V_43 ;
V_62:
V_43 = NULL ;
V_61 = F_62 ( & V_44 -> V_48 ) ;
if ( ! V_61 )
goto V_63;
V_43 = F_48 ( V_61 , struct V_32 , V_53 ) ;
F_51 ( V_43 , V_44 ) ;
if ( ! F_58 ( & V_43 -> V_2 -> V_59 ) ||
! F_25 ( & V_43 -> V_2 -> V_12 ) )
goto V_62;
V_63:
return V_43 ;
}
static struct V_32 *
F_63 ( struct V_39 * V_44 )
{
struct V_32 * V_43 ;
F_64 ( & V_44 -> V_57 ) ;
V_43 = F_61 ( V_44 ) ;
F_65 ( & V_44 -> V_57 ) ;
return V_43 ;
}
static long F_66 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
long V_66 = 0 ;
int V_67 ;
F_67 () ;
F_68 (cpu)
V_66 += F_69 ( V_2 -> V_68 -> V_69 [ V_65 ] , V_67 ) ;
#ifdef F_70
F_71 ( & V_2 -> V_70 ) ;
V_66 += V_2 -> V_71 . V_69 [ V_65 ] ;
F_72 ( & V_2 -> V_70 ) ;
#endif
F_73 () ;
return V_66 ;
}
static unsigned long F_74 ( struct V_1 * V_2 ,
enum V_72 V_65 )
{
unsigned long V_66 = 0 ;
int V_67 ;
F_67 () ;
F_68 (cpu)
V_66 += F_69 ( V_2 -> V_68 -> V_73 [ V_65 ] , V_67 ) ;
#ifdef F_70
F_71 ( & V_2 -> V_70 ) ;
V_66 += V_2 -> V_71 . V_73 [ V_65 ] ;
F_72 ( & V_2 -> V_70 ) ;
#endif
F_73 () ;
return V_66 ;
}
static void F_75 ( struct V_1 * V_2 ,
struct V_38 * V_38 ,
int V_74 )
{
if ( F_76 ( V_38 ) )
F_77 ( V_2 -> V_68 -> V_69 [ V_75 ] ,
V_74 ) ;
else
F_77 ( V_2 -> V_68 -> V_69 [ V_76 ] ,
V_74 ) ;
if ( F_78 ( V_38 ) )
F_77 ( V_2 -> V_68 -> V_69 [ V_77 ] ,
V_74 ) ;
if ( V_74 > 0 )
F_79 ( V_2 -> V_68 -> V_73 [ V_78 ] ) ;
else {
F_79 ( V_2 -> V_68 -> V_73 [ V_79 ] ) ;
V_74 = - V_74 ;
}
F_77 ( V_2 -> V_68 -> V_80 , V_74 ) ;
}
unsigned long F_80 ( struct V_81 * V_81 , enum V_82 V_83 )
{
struct V_32 * V_43 ;
V_43 = F_12 ( V_81 , struct V_32 , V_81 ) ;
return V_43 -> V_84 [ V_83 ] ;
}
static unsigned long F_81 ( struct V_1 * V_2 ,
int V_34 ,
unsigned int V_85 )
{
unsigned long V_86 = 0 ;
int V_35 ;
F_82 ( ( unsigned ) V_34 >= V_87 ) ;
for ( V_35 = 0 ; V_35 < V_60 ; V_35 ++ ) {
struct V_32 * V_43 ;
enum V_82 V_83 ;
F_83 (lru) {
if ( ! ( F_84 ( V_83 ) & V_85 ) )
continue;
V_43 = & V_2 -> V_36 [ V_34 ] -> V_37 [ V_35 ] ;
V_86 += V_43 -> V_84 [ V_83 ] ;
}
}
return V_86 ;
}
static unsigned long F_85 ( struct V_1 * V_2 ,
unsigned int V_85 )
{
unsigned long V_86 = 0 ;
int V_34 ;
F_86 (nid, N_MEMORY)
V_86 += F_81 ( V_2 , V_34 , V_85 ) ;
return V_86 ;
}
static bool F_87 ( struct V_1 * V_2 ,
enum V_88 V_89 )
{
unsigned long V_66 , V_90 ;
V_66 = F_88 ( V_2 -> V_68 -> V_80 ) ;
V_90 = F_88 ( V_2 -> V_68 -> V_91 [ V_89 ] ) ;
if ( ( long ) V_90 - ( long ) V_66 < 0 ) {
switch ( V_89 ) {
case V_92 :
V_90 = V_66 + V_93 ;
break;
case V_94 :
V_90 = V_66 + V_95 ;
break;
case V_96 :
V_90 = V_66 + V_97 ;
break;
default:
break;
}
F_89 ( V_2 -> V_68 -> V_91 [ V_89 ] , V_90 ) ;
return true ;
}
return false ;
}
static void F_90 ( struct V_1 * V_2 , struct V_38 * V_38 )
{
if ( F_91 ( F_87 ( V_2 ,
V_92 ) ) ) {
bool V_98 ;
bool T_1 V_99 ;
V_98 = F_87 ( V_2 ,
V_94 ) ;
#if V_100 > 1
T_1 = F_87 ( V_2 ,
V_96 ) ;
#endif
F_92 ( V_2 ) ;
if ( F_91 ( V_98 ) )
F_56 ( V_2 , V_38 ) ;
#if V_100 > 1
if ( F_91 ( T_1 ) )
F_93 ( & V_2 -> V_101 ) ;
#endif
}
}
struct V_1 * F_23 ( struct V_102 * V_47 )
{
if ( F_91 ( ! V_47 ) )
return NULL ;
return F_11 ( F_94 ( V_47 , V_103 ) ) ;
}
static struct V_1 * F_95 ( struct V_104 * V_105 )
{
struct V_1 * V_2 = NULL ;
F_22 () ;
do {
if ( F_91 ( ! V_105 ) )
V_2 = V_14 ;
else {
V_2 = F_23 ( F_96 ( V_105 -> V_106 ) ) ;
if ( F_91 ( ! V_2 ) )
V_2 = V_14 ;
}
} while ( ! F_25 ( & V_2 -> V_12 ) );
F_26 () ;
return V_2 ;
}
static struct V_1 * F_97 ( struct V_1 * V_107 ,
struct V_1 * V_108 )
{
struct V_10 * V_109 , * V_110 ;
V_109 = V_108 ? & V_108 -> V_12 : NULL ;
V_111:
V_110 = F_98 ( V_109 , & V_107 -> V_12 ) ;
if ( V_110 ) {
struct V_1 * V_2 = F_11 ( V_110 ) ;
if ( V_110 == & V_107 -> V_12 )
return V_2 ;
if ( F_25 ( V_110 ) ) {
if ( F_99 ( & V_2 -> V_112 ) )
return V_2 ;
F_29 ( V_110 ) ;
}
V_109 = V_110 ;
goto V_111;
}
return NULL ;
}
static void F_100 ( struct V_1 * V_107 )
{
F_93 ( & V_107 -> V_113 ) ;
}
static struct V_1 *
F_101 ( struct V_114 * V_115 ,
struct V_1 * V_107 ,
int * V_116 )
{
struct V_1 * V_117 = NULL ;
* V_116 = F_102 ( & V_107 -> V_113 ) ;
if ( V_115 -> V_118 == * V_116 ) {
F_103 () ;
V_117 = V_115 -> V_108 ;
if ( V_117 && V_117 != V_107 &&
! F_25 ( & V_117 -> V_12 ) )
V_117 = NULL ;
}
return V_117 ;
}
static void F_104 ( struct V_114 * V_115 ,
struct V_1 * V_108 ,
struct V_1 * V_119 ,
struct V_1 * V_107 ,
int V_116 )
{
if ( V_108 && V_108 != V_107 )
F_29 ( & V_108 -> V_12 ) ;
V_115 -> V_108 = V_119 ;
F_6 () ;
V_115 -> V_118 = V_116 ;
}
struct V_1 * F_105 ( struct V_1 * V_107 ,
struct V_1 * V_120 ,
struct V_121 * V_122 )
{
struct V_1 * V_2 = NULL ;
struct V_1 * V_108 = NULL ;
if ( F_106 () )
return NULL ;
if ( ! V_107 )
V_107 = V_14 ;
if ( V_120 && ! V_122 )
V_108 = V_120 ;
if ( ! V_107 -> V_123 && V_107 != V_14 ) {
if ( V_120 )
goto V_124;
return V_107 ;
}
F_22 () ;
while ( ! V_2 ) {
struct V_114 * V_125 ( V_115 ) ;
int V_125 ( V_126 ) ;
if ( V_122 ) {
struct V_32 * V_43 ;
V_43 = F_38 ( V_107 , V_122 -> V_33 ) ;
V_115 = & V_43 -> V_127 [ V_122 -> V_128 ] ;
if ( V_120 && V_122 -> V_129 != V_115 -> V_129 ) {
V_115 -> V_108 = NULL ;
goto V_130;
}
V_108 = F_101 ( V_115 , V_107 , & V_126 ) ;
}
V_2 = F_97 ( V_107 , V_108 ) ;
if ( V_122 ) {
F_104 ( V_115 , V_108 , V_2 , V_107 ,
V_126 ) ;
if ( ! V_2 )
V_115 -> V_129 ++ ;
else if ( ! V_120 && V_2 )
V_122 -> V_129 = V_115 -> V_129 ;
}
if ( V_120 && ! V_2 )
goto V_130;
}
V_130:
F_26 () ;
V_124:
if ( V_120 && V_120 != V_107 )
F_29 ( & V_120 -> V_12 ) ;
return V_2 ;
}
void F_107 ( struct V_1 * V_107 ,
struct V_1 * V_120 )
{
if ( ! V_107 )
V_107 = V_14 ;
if ( V_120 && V_120 != V_107 )
F_29 ( & V_120 -> V_12 ) ;
}
void F_108 ( struct V_104 * V_105 , enum V_131 V_65 )
{
struct V_1 * V_2 ;
F_22 () ;
V_2 = F_23 ( F_96 ( V_105 -> V_106 ) ) ;
if ( F_91 ( ! V_2 ) )
goto V_132;
switch ( V_65 ) {
case V_133 :
F_109 ( V_2 -> V_68 -> V_73 [ V_134 ] ) ;
break;
case V_135 :
F_109 ( V_2 -> V_68 -> V_73 [ V_136 ] ) ;
break;
default:
F_110 () ;
}
V_132:
F_26 () ;
}
struct V_81 * F_111 ( struct V_33 * V_33 ,
struct V_1 * V_2 )
{
struct V_32 * V_43 ;
struct V_81 * V_81 ;
if ( F_106 () ) {
V_81 = & V_33 -> V_81 ;
goto V_132;
}
V_43 = F_38 ( V_2 , V_33 ) ;
V_81 = & V_43 -> V_81 ;
V_132:
if ( F_91 ( V_81 -> V_33 != V_33 ) )
V_81 -> V_33 = V_33 ;
return V_81 ;
}
struct V_81 * F_112 ( struct V_38 * V_38 , struct V_33 * V_33 )
{
struct V_32 * V_43 ;
struct V_1 * V_2 ;
struct V_137 * V_138 ;
struct V_81 * V_81 ;
if ( F_106 () ) {
V_81 = & V_33 -> V_81 ;
goto V_132;
}
V_138 = F_113 ( V_38 ) ;
V_2 = V_138 -> V_1 ;
if ( ! F_114 ( V_38 ) && ! F_115 ( V_138 ) && V_2 != V_14 )
V_138 -> V_1 = V_2 = V_14 ;
V_43 = F_42 ( V_2 , V_38 ) ;
V_81 = & V_43 -> V_81 ;
V_132:
if ( F_91 ( V_81 -> V_33 != V_33 ) )
V_81 -> V_33 = V_33 ;
return V_81 ;
}
void F_116 ( struct V_81 * V_81 , enum V_82 V_83 ,
int V_74 )
{
struct V_32 * V_43 ;
unsigned long * V_84 ;
if ( F_106 () )
return;
V_43 = F_12 ( V_81 , struct V_32 , V_81 ) ;
V_84 = V_43 -> V_84 + V_83 ;
* V_84 += V_74 ;
F_82 ( ( long ) ( * V_84 ) < 0 ) ;
}
bool F_117 ( const struct V_1 * V_139 ,
struct V_1 * V_2 )
{
if ( V_139 == V_2 )
return true ;
if ( ! V_139 -> V_123 || ! V_2 )
return false ;
return F_118 ( V_2 -> V_12 . V_140 , V_139 -> V_12 . V_140 ) ;
}
static bool F_119 ( const struct V_1 * V_139 ,
struct V_1 * V_2 )
{
bool V_141 ;
F_22 () ;
V_141 = F_117 ( V_139 , V_2 ) ;
F_26 () ;
return V_141 ;
}
bool F_120 ( struct V_102 * V_142 ,
const struct V_1 * V_2 )
{
struct V_1 * V_143 = NULL ;
struct V_102 * V_47 ;
bool V_141 ;
V_47 = F_121 ( V_142 ) ;
if ( V_47 ) {
V_143 = F_95 ( V_47 -> V_105 ) ;
F_122 ( V_47 ) ;
} else {
F_22 () ;
V_143 = F_23 ( V_142 ) ;
if ( V_143 )
F_21 ( & V_143 -> V_12 ) ;
F_26 () ;
}
V_141 = F_119 ( V_2 , V_143 ) ;
F_29 ( & V_143 -> V_12 ) ;
return V_141 ;
}
int F_123 ( struct V_81 * V_81 )
{
unsigned long V_144 ;
unsigned long V_145 ;
unsigned long V_146 ;
unsigned long V_147 ;
V_145 = F_80 ( V_81 , V_148 ) ;
V_146 = F_80 ( V_81 , V_149 ) ;
V_147 = ( V_145 + V_146 ) >> ( 30 - V_150 ) ;
if ( V_147 )
V_144 = F_124 ( 10 * V_147 ) ;
else
V_144 = 1 ;
return V_145 * V_144 < V_146 ;
}
static unsigned long F_125 ( struct V_1 * V_2 )
{
unsigned long long V_151 ;
V_151 = F_126 ( & V_2 -> V_59 ) ;
if ( V_152 )
V_151 = F_127 ( V_151 , F_126 ( & V_2 -> V_153 ) ) ;
return V_151 >> V_150 ;
}
int F_128 ( struct V_1 * V_2 )
{
if ( F_106 () || ! V_2 -> V_12 . V_49 )
return V_154 ;
return V_2 -> V_155 ;
}
static void F_129 ( struct V_1 * V_2 )
{
F_93 ( & V_2 -> V_156 ) ;
F_130 () ;
}
static void F_131 ( struct V_1 * V_2 )
{
if ( V_2 )
F_132 ( & V_2 -> V_156 ) ;
}
static bool F_133 ( struct V_1 * V_2 )
{
struct V_1 * V_157 ;
struct V_1 * V_158 ;
bool V_141 = false ;
F_71 ( & V_7 . V_57 ) ;
V_157 = V_7 . V_157 ;
V_158 = V_7 . V_158 ;
if ( ! V_157 )
goto V_159;
V_141 = F_119 ( V_2 , V_157 )
|| F_119 ( V_2 , V_158 ) ;
V_159:
F_72 ( & V_7 . V_57 ) ;
return V_141 ;
}
static bool F_134 ( struct V_1 * V_2 )
{
if ( V_7 . V_160 && V_25 != V_7 . V_160 ) {
if ( F_133 ( V_2 ) ) {
F_135 ( V_161 ) ;
F_136 ( & V_7 . V_162 , & V_161 , V_163 ) ;
if ( V_7 . V_160 )
F_137 () ;
F_138 ( & V_7 . V_162 , & V_161 ) ;
return true ;
}
}
return false ;
}
static void F_139 ( struct V_1 * V_2 ,
unsigned long * V_56 )
{
F_54 ( & V_2 -> V_164 , * V_56 ) ;
}
static void F_140 ( struct V_1 * V_2 ,
unsigned long * V_56 )
{
F_55 ( & V_2 -> V_164 , * V_56 ) ;
}
void F_141 ( struct V_1 * V_2 , struct V_102 * V_47 )
{
static F_142 ( V_165 ) ;
struct V_1 * V_115 ;
unsigned int V_166 ;
if ( ! V_47 )
return;
F_143 ( & V_165 ) ;
F_22 () ;
F_144 ( L_1 ) ;
F_145 ( F_146 ( V_47 , V_103 ) ) ;
F_144 ( L_2 ) ;
F_145 ( V_2 -> V_12 . V_140 ) ;
F_144 ( L_3 ) ;
F_26 () ;
F_144 ( L_4 ,
F_36 ( & V_2 -> V_59 , V_31 ) >> 10 ,
F_36 ( & V_2 -> V_59 , V_167 ) >> 10 ,
F_36 ( & V_2 -> V_59 , V_168 ) ) ;
F_144 ( L_5 ,
F_36 ( & V_2 -> V_153 , V_31 ) >> 10 ,
F_36 ( & V_2 -> V_153 , V_167 ) >> 10 ,
F_36 ( & V_2 -> V_153 , V_168 ) ) ;
F_144 ( L_6 ,
F_36 ( & V_2 -> V_30 , V_31 ) >> 10 ,
F_36 ( & V_2 -> V_30 , V_167 ) >> 10 ,
F_36 ( & V_2 -> V_30 , V_168 ) ) ;
F_147 (iter, memcg) {
F_144 ( L_7 ) ;
F_145 ( V_115 -> V_12 . V_140 ) ;
F_148 ( L_8 ) ;
for ( V_166 = 0 ; V_166 < V_169 ; V_166 ++ ) {
if ( V_166 == V_170 && ! V_152 )
continue;
F_148 ( L_9 , V_171 [ V_166 ] ,
F_149 ( F_66 ( V_115 , V_166 ) ) ) ;
}
for ( V_166 = 0 ; V_166 < V_172 ; V_166 ++ )
F_148 ( L_10 , V_173 [ V_166 ] ,
F_149 ( F_85 ( V_115 , F_84 ( V_166 ) ) ) ) ;
F_148 ( L_3 ) ;
}
F_150 ( & V_165 ) ;
}
static int F_151 ( struct V_1 * V_2 )
{
int V_174 = 0 ;
struct V_1 * V_115 ;
F_147 (iter, memcg)
V_174 ++ ;
return V_174 ;
}
static T_2 F_152 ( struct V_1 * V_2 )
{
T_2 V_175 ;
V_175 = F_36 ( & V_2 -> V_59 , V_167 ) ;
if ( F_128 ( V_2 ) ) {
T_2 V_153 ;
V_175 += V_176 << V_150 ;
V_153 = F_36 ( & V_2 -> V_153 , V_167 ) ;
V_175 = F_127 ( V_175 , V_153 ) ;
}
return V_175 ;
}
static void F_153 ( struct V_1 * V_2 , T_3 V_177 ,
int V_178 )
{
struct V_1 * V_115 ;
unsigned long V_179 = 0 ;
unsigned long V_180 ;
unsigned int V_181 = 0 ;
struct V_102 * V_182 = NULL ;
if ( F_154 ( V_25 ) || V_25 -> V_56 & V_183 ) {
F_155 ( V_184 ) ;
return;
}
F_156 ( V_185 , V_177 , V_178 , NULL ) ;
V_180 = F_152 ( V_2 ) >> V_150 ? : 1 ;
F_147 (iter, memcg) {
struct V_186 V_187 ;
struct V_102 * V_142 ;
F_157 ( & V_115 -> V_12 , & V_187 ) ;
while ( ( V_142 = F_158 ( & V_187 ) ) ) {
switch ( F_159 ( V_142 , V_180 , NULL ,
false ) ) {
case V_188 :
if ( V_182 )
F_160 ( V_182 ) ;
V_182 = V_142 ;
V_179 = V_189 ;
F_161 ( V_182 ) ;
case V_190 :
continue;
case V_191 :
F_162 ( & V_187 ) ;
F_107 ( V_2 , V_115 ) ;
if ( V_182 )
F_160 ( V_182 ) ;
return;
case V_192 :
break;
} ;
V_181 = F_163 ( V_142 , V_2 , NULL , V_180 ) ;
if ( ! V_181 || V_181 < V_179 )
continue;
if ( V_181 == V_179 &&
F_164 ( V_182 ) )
continue;
if ( V_182 )
F_160 ( V_182 ) ;
V_182 = V_142 ;
V_179 = V_181 ;
F_161 ( V_182 ) ;
}
F_162 ( & V_187 ) ;
}
if ( ! V_182 )
return;
V_181 = V_179 * 1000 / V_180 ;
F_165 ( V_182 , V_177 , V_178 , V_181 , V_180 , V_2 ,
NULL , L_11 ) ;
}
static bool F_166 ( struct V_1 * V_2 ,
int V_34 , bool V_193 )
{
if ( F_81 ( V_2 , V_34 , V_194 ) )
return true ;
if ( V_193 || ! V_176 )
return false ;
if ( F_81 ( V_2 , V_34 , V_195 ) )
return true ;
return false ;
}
static void F_167 ( struct V_1 * V_2 )
{
int V_34 ;
if ( ! F_102 ( & V_2 -> V_101 ) )
return;
if ( F_168 ( & V_2 -> V_196 ) > 1 )
return;
V_2 -> V_197 = V_198 [ V_199 ] ;
F_169 (nid, node_states[N_MEMORY]) {
if ( ! F_166 ( V_2 , V_34 , false ) )
F_170 ( V_34 , V_2 -> V_197 ) ;
}
F_171 ( & V_2 -> V_101 , 0 ) ;
F_171 ( & V_2 -> V_196 , 0 ) ;
}
int F_172 ( struct V_1 * V_2 )
{
int V_200 ;
F_167 ( V_2 ) ;
V_200 = V_2 -> V_201 ;
V_200 = F_173 ( V_200 , V_2 -> V_197 ) ;
if ( V_200 == V_100 )
V_200 = F_174 ( V_2 -> V_197 ) ;
if ( F_91 ( V_200 == V_100 ) )
V_200 = F_175 () ;
V_2 -> V_201 = V_200 ;
return V_200 ;
}
static bool F_176 ( struct V_1 * V_2 , bool V_193 )
{
int V_34 ;
if ( ! F_177 ( V_2 -> V_197 ) ) {
for ( V_34 = F_174 ( V_2 -> V_197 ) ;
V_34 < V_100 ;
V_34 = F_173 ( V_34 , V_2 -> V_197 ) ) {
if ( F_166 ( V_2 , V_34 , V_193 ) )
return true ;
}
}
F_86 (nid, N_MEMORY) {
if ( F_178 ( V_34 , V_2 -> V_197 ) )
continue;
if ( F_166 ( V_2 , V_34 , V_193 ) )
return true ;
}
return false ;
}
int F_172 ( struct V_1 * V_2 )
{
return 0 ;
}
static bool F_176 ( struct V_1 * V_2 , bool V_193 )
{
return F_166 ( V_2 , 0 , V_193 ) ;
}
static int F_179 ( struct V_1 * V_139 ,
struct V_33 * V_33 ,
T_3 V_177 ,
unsigned long * V_202 )
{
struct V_1 * V_203 = NULL ;
int V_204 = 0 ;
int V_205 = 0 ;
unsigned long V_58 ;
unsigned long V_206 ;
struct V_121 V_122 = {
. V_33 = V_33 ,
. V_128 = 0 ,
} ;
V_58 = F_58 ( & V_139 -> V_59 ) >> V_150 ;
while ( 1 ) {
V_203 = F_105 ( V_139 , V_203 , & V_122 ) ;
if ( ! V_203 ) {
V_205 ++ ;
if ( V_205 >= 2 ) {
if ( ! V_204 )
break;
if ( V_204 >= ( V_58 >> 2 ) ||
( V_205 > V_207 ) )
break;
}
continue;
}
if ( ! F_176 ( V_203 , false ) )
continue;
V_204 += F_180 ( V_203 , V_177 , false ,
V_33 , & V_206 ) ;
* V_202 += V_206 ;
if ( ! F_58 ( & V_139 -> V_59 ) )
break;
}
F_107 ( V_139 , V_203 ) ;
return V_204 ;
}
static bool F_181 ( struct V_1 * V_2 )
{
struct V_1 * V_115 , * V_208 = NULL ;
F_71 ( & V_209 ) ;
F_147 (iter, memcg) {
if ( V_115 -> V_210 ) {
V_208 = V_115 ;
F_107 ( V_2 , V_115 ) ;
break;
} else
V_115 -> V_210 = true ;
}
if ( V_208 ) {
F_147 (iter, memcg) {
if ( V_115 == V_208 ) {
F_107 ( V_2 , V_115 ) ;
break;
}
V_115 -> V_210 = false ;
}
} else
F_182 ( & V_211 , 0 , 1 , V_212 ) ;
F_72 ( & V_209 ) ;
return ! V_208 ;
}
static void F_183 ( struct V_1 * V_2 )
{
struct V_1 * V_115 ;
F_71 ( & V_209 ) ;
F_184 ( & V_211 , 1 , V_212 ) ;
F_147 (iter, memcg)
V_115 -> V_210 = false ;
F_72 ( & V_209 ) ;
}
static void F_185 ( struct V_1 * V_2 )
{
struct V_1 * V_115 ;
F_147 (iter, memcg)
F_93 ( & V_115 -> V_213 ) ;
}
static void F_186 ( struct V_1 * V_2 )
{
struct V_1 * V_115 ;
F_147 (iter, memcg)
F_187 ( & V_115 -> V_213 , - 1 , 0 ) ;
}
static int F_188 ( T_4 * V_161 ,
unsigned V_214 , int V_215 , void * V_216 )
{
struct V_1 * V_217 = (struct V_1 * ) V_216 ;
struct V_1 * V_218 ;
struct V_219 * V_219 ;
V_219 = F_12 ( V_161 , struct V_219 , V_161 ) ;
V_218 = V_219 -> V_2 ;
if ( ! F_119 ( V_218 , V_217 )
&& ! F_119 ( V_217 , V_218 ) )
return 0 ;
return F_189 ( V_161 , V_214 , V_215 , V_216 ) ;
}
static void F_190 ( struct V_1 * V_2 )
{
F_93 ( & V_2 -> V_220 ) ;
F_191 ( & V_221 , V_222 , 0 , V_2 ) ;
}
static void F_192 ( struct V_1 * V_2 )
{
if ( V_2 && F_102 ( & V_2 -> V_213 ) )
F_190 ( V_2 ) ;
}
static void F_193 ( struct V_1 * V_2 , T_3 V_223 , int V_178 )
{
if ( ! V_25 -> V_224 . V_225 )
return;
F_21 ( & V_2 -> V_12 ) ;
V_25 -> V_224 . V_2 = V_2 ;
V_25 -> V_224 . V_177 = V_223 ;
V_25 -> V_224 . V_178 = V_178 ;
}
bool F_194 ( bool V_226 )
{
struct V_1 * V_2 = V_25 -> V_224 . V_2 ;
struct V_219 V_227 ;
bool V_228 ;
if ( ! V_2 )
return false ;
if ( ! V_226 )
goto V_229;
V_227 . V_2 = V_2 ;
V_227 . V_161 . V_56 = 0 ;
V_227 . V_161 . V_230 = F_188 ;
V_227 . V_161 . V_231 = V_25 ;
F_195 ( & V_227 . V_161 . V_232 ) ;
F_136 ( & V_221 , & V_227 . V_161 , V_233 ) ;
F_185 ( V_2 ) ;
V_228 = F_181 ( V_2 ) ;
if ( V_228 )
F_196 ( V_2 ) ;
if ( V_228 && ! V_2 -> V_234 ) {
F_186 ( V_2 ) ;
F_138 ( & V_221 , & V_227 . V_161 ) ;
F_153 ( V_2 , V_25 -> V_224 . V_177 ,
V_25 -> V_224 . V_178 ) ;
} else {
F_137 () ;
F_186 ( V_2 ) ;
F_138 ( & V_221 , & V_227 . V_161 ) ;
}
if ( V_228 ) {
F_183 ( V_2 ) ;
F_192 ( V_2 ) ;
}
V_229:
V_25 -> V_224 . V_2 = NULL ;
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
struct V_1 * F_197 ( struct V_38 * V_38 ,
bool * V_228 ,
unsigned long * V_56 )
{
struct V_1 * V_2 ;
struct V_137 * V_138 ;
F_22 () ;
if ( F_106 () )
return NULL ;
V_138 = F_113 ( V_38 ) ;
V_235:
V_2 = V_138 -> V_1 ;
if ( F_91 ( ! V_2 || ! F_115 ( V_138 ) ) )
return NULL ;
* V_228 = false ;
if ( F_102 ( & V_2 -> V_156 ) <= 0 )
return V_2 ;
F_139 ( V_2 , V_56 ) ;
if ( V_2 != V_138 -> V_1 || ! F_115 ( V_138 ) ) {
F_140 ( V_2 , V_56 ) ;
goto V_235;
}
* V_228 = true ;
return V_2 ;
}
void F_198 ( struct V_1 * V_2 , bool V_228 ,
unsigned long V_56 )
{
if ( V_2 && V_228 )
F_140 ( V_2 , & V_56 ) ;
F_26 () ;
}
void F_199 ( struct V_1 * V_2 ,
enum V_64 V_65 , int V_66 )
{
F_82 ( ! F_200 () ) ;
if ( V_2 )
F_201 ( V_2 -> V_68 -> V_69 [ V_65 ] , V_66 ) ;
}
static bool F_202 ( struct V_1 * V_2 , unsigned int V_74 )
{
struct V_236 * V_237 ;
bool V_141 = true ;
if ( V_74 > V_238 )
return false ;
V_237 = & F_203 ( V_239 ) ;
if ( V_2 == V_237 -> V_240 && V_237 -> V_74 >= V_74 )
V_237 -> V_74 -= V_74 ;
else
V_141 = false ;
F_204 ( V_239 ) ;
return V_141 ;
}
static void F_205 ( struct V_236 * V_237 )
{
struct V_1 * V_241 = V_237 -> V_240 ;
if ( V_237 -> V_74 ) {
unsigned long V_242 = V_237 -> V_74 * V_243 ;
F_206 ( & V_241 -> V_59 , V_242 ) ;
if ( V_152 )
F_206 ( & V_241 -> V_153 , V_242 ) ;
V_237 -> V_74 = 0 ;
}
V_237 -> V_240 = NULL ;
}
static void F_207 ( struct V_244 * V_245 )
{
struct V_236 * V_237 = F_208 ( & V_239 ) ;
F_205 ( V_237 ) ;
F_209 ( V_246 , & V_237 -> V_56 ) ;
}
static void T_5 F_210 ( void )
{
int V_67 ;
F_211 (cpu) {
struct V_236 * V_237 =
& F_69 ( V_239 , V_67 ) ;
F_212 ( & V_237 -> V_247 , F_207 ) ;
}
}
static void F_213 ( struct V_1 * V_2 , unsigned int V_74 )
{
struct V_236 * V_237 = & F_203 ( V_239 ) ;
if ( V_237 -> V_240 != V_2 ) {
F_205 ( V_237 ) ;
V_237 -> V_240 = V_2 ;
}
V_237 -> V_74 += V_74 ;
F_204 ( V_239 ) ;
}
static void F_214 ( struct V_1 * V_139 , bool V_215 )
{
int V_67 , V_248 ;
F_67 () ;
V_248 = F_215 () ;
F_68 (cpu) {
struct V_236 * V_237 = & F_69 ( V_239 , V_67 ) ;
struct V_1 * V_2 ;
V_2 = V_237 -> V_240 ;
if ( ! V_2 || ! V_237 -> V_74 )
continue;
if ( ! F_119 ( V_139 , V_2 ) )
continue;
if ( ! F_216 ( V_246 , & V_237 -> V_56 ) ) {
if ( V_67 == V_248 )
F_207 ( & V_237 -> V_247 ) ;
else
F_217 ( V_67 , & V_237 -> V_247 ) ;
}
}
F_218 () ;
if ( ! V_215 )
goto V_132;
F_68 (cpu) {
struct V_236 * V_237 = & F_69 ( V_239 , V_67 ) ;
if ( F_4 ( V_246 , & V_237 -> V_56 ) )
F_219 ( & V_237 -> V_247 ) ;
}
V_132:
F_73 () ;
}
static void F_220 ( struct V_1 * V_139 )
{
if ( ! F_221 ( & V_249 ) )
return;
F_214 ( V_139 , false ) ;
F_150 ( & V_249 ) ;
}
static void F_222 ( struct V_1 * V_139 )
{
F_143 ( & V_249 ) ;
F_214 ( V_139 , true ) ;
F_150 ( & V_249 ) ;
}
static void F_223 ( struct V_1 * V_2 , int V_67 )
{
int V_166 ;
F_71 ( & V_2 -> V_70 ) ;
for ( V_166 = 0 ; V_166 < V_169 ; V_166 ++ ) {
long V_250 = F_69 ( V_2 -> V_68 -> V_69 [ V_166 ] , V_67 ) ;
F_69 ( V_2 -> V_68 -> V_69 [ V_166 ] , V_67 ) = 0 ;
V_2 -> V_71 . V_69 [ V_166 ] += V_250 ;
}
for ( V_166 = 0 ; V_166 < V_251 ; V_166 ++ ) {
unsigned long V_250 = F_69 ( V_2 -> V_68 -> V_73 [ V_166 ] , V_67 ) ;
F_69 ( V_2 -> V_68 -> V_73 [ V_166 ] , V_67 ) = 0 ;
V_2 -> V_71 . V_73 [ V_166 ] += V_250 ;
}
F_72 ( & V_2 -> V_70 ) ;
}
static int F_224 ( struct V_252 * V_253 ,
unsigned long V_254 ,
void * V_255 )
{
int V_67 = ( unsigned long ) V_255 ;
struct V_236 * V_237 ;
struct V_1 * V_115 ;
if ( V_254 == V_256 )
return V_257 ;
if ( V_254 != V_258 && V_254 != V_259 )
return V_257 ;
F_225 (iter)
F_223 ( V_115 , V_67 ) ;
V_237 = & F_69 ( V_239 , V_67 ) ;
F_205 ( V_237 ) ;
return V_257 ;
}
static int F_226 ( struct V_1 * V_2 , T_3 V_177 ,
unsigned int V_74 )
{
unsigned int V_260 = F_227 ( V_238 , V_74 ) ;
int V_261 = V_262 ;
struct V_1 * V_263 ;
struct V_264 * V_265 ;
unsigned long V_266 ;
unsigned long long V_267 ;
bool V_268 = true ;
bool V_269 = false ;
int V_141 = 0 ;
if ( F_15 ( V_2 ) )
goto V_63;
V_62:
if ( F_202 ( V_2 , V_74 ) )
goto V_63;
V_267 = V_260 * V_243 ;
if ( ! V_152 ||
! F_228 ( & V_2 -> V_153 , V_267 , & V_265 ) ) {
if ( ! F_228 ( & V_2 -> V_59 , V_267 , & V_265 ) )
goto V_270;
if ( V_152 )
F_206 ( & V_2 -> V_153 , V_267 ) ;
V_263 = F_229 ( V_265 , V_59 ) ;
} else {
V_263 = F_229 ( V_265 , V_153 ) ;
V_268 = false ;
}
if ( V_260 > V_74 ) {
V_260 = V_74 ;
goto V_62;
}
if ( F_91 ( F_230 ( V_184 ) ||
F_154 ( V_25 ) ||
V_25 -> V_56 & V_183 ) )
goto V_271;
if ( F_91 ( F_231 ( V_25 ) ) )
goto V_272;
if ( ! ( V_177 & V_273 ) )
goto V_272;
V_266 = F_232 ( V_263 , V_74 ,
V_177 , V_268 ) ;
if ( F_125 ( V_263 ) >= V_74 )
goto V_62;
if ( ! V_269 ) {
F_220 ( V_263 ) ;
V_269 = true ;
goto V_62;
}
if ( V_177 & V_274 )
goto V_272;
if ( V_266 && V_74 <= ( 1 << V_275 ) )
goto V_62;
if ( F_134 ( V_263 ) )
goto V_62;
if ( V_261 -- )
goto V_62;
if ( V_177 & V_276 )
goto V_271;
if ( F_154 ( V_25 ) )
goto V_271;
F_193 ( V_263 , V_177 , F_233 ( V_74 ) ) ;
V_272:
if ( ! ( V_177 & V_276 ) )
return - V_277 ;
V_271:
return - V_278 ;
V_270:
if ( V_260 > V_74 )
F_213 ( V_2 , V_260 - V_74 ) ;
V_63:
return V_141 ;
}
static void F_234 ( struct V_1 * V_2 , unsigned int V_74 )
{
unsigned long V_242 = V_74 * V_243 ;
if ( F_15 ( V_2 ) )
return;
F_206 ( & V_2 -> V_59 , V_242 ) ;
if ( V_152 )
F_206 ( & V_2 -> V_153 , V_242 ) ;
}
static void F_235 ( struct V_1 * V_2 ,
unsigned int V_74 )
{
unsigned long V_242 = V_74 * V_243 ;
if ( F_15 ( V_2 ) )
return;
F_236 ( & V_2 -> V_59 , V_2 -> V_59 . V_49 , V_242 ) ;
if ( V_152 )
F_236 ( & V_2 -> V_153 ,
V_2 -> V_153 . V_49 , V_242 ) ;
}
static struct V_1 * F_237 ( unsigned short V_16 )
{
if ( ! V_16 )
return NULL ;
return F_17 ( V_16 ) ;
}
struct V_1 * F_238 ( struct V_38 * V_38 )
{
struct V_1 * V_2 = NULL ;
struct V_137 * V_138 ;
unsigned short V_16 ;
T_6 V_279 ;
F_239 ( ! F_240 ( V_38 ) , V_38 ) ;
V_138 = F_113 ( V_38 ) ;
if ( F_115 ( V_138 ) ) {
V_2 = V_138 -> V_1 ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
} else if ( F_241 ( V_38 ) ) {
V_279 . V_66 = F_242 ( V_38 ) ;
V_16 = F_243 ( V_279 ) ;
F_22 () ;
V_2 = F_237 ( V_16 ) ;
if ( V_2 && ! F_25 ( & V_2 -> V_12 ) )
V_2 = NULL ;
F_26 () ;
}
return V_2 ;
}
static void F_244 ( struct V_38 * V_38 , int * V_280 )
{
struct V_33 * V_33 = F_245 ( V_38 ) ;
F_64 ( & V_33 -> V_281 ) ;
if ( F_114 ( V_38 ) ) {
struct V_81 * V_81 ;
V_81 = F_112 ( V_38 , V_33 ) ;
F_246 ( V_38 ) ;
F_247 ( V_38 , V_81 , F_248 ( V_38 ) ) ;
* V_280 = 1 ;
} else
* V_280 = 0 ;
}
static void F_249 ( struct V_38 * V_38 , int V_280 )
{
struct V_33 * V_33 = F_245 ( V_38 ) ;
if ( V_280 ) {
struct V_81 * V_81 ;
V_81 = F_112 ( V_38 , V_33 ) ;
F_239 ( F_114 ( V_38 ) , V_38 ) ;
F_250 ( V_38 ) ;
F_251 ( V_38 , V_81 , F_248 ( V_38 ) ) ;
}
F_65 ( & V_33 -> V_281 ) ;
}
static void F_252 ( struct V_38 * V_38 , struct V_1 * V_2 ,
bool V_282 )
{
struct V_137 * V_138 = F_113 ( V_38 ) ;
int V_280 ;
F_239 ( F_115 ( V_138 ) , V_38 ) ;
if ( V_282 )
F_244 ( V_38 , & V_280 ) ;
V_138 -> V_1 = V_2 ;
V_138 -> V_56 = V_283 | V_284 | ( V_152 ? V_285 : 0 ) ;
if ( V_282 )
F_249 ( V_38 , V_280 ) ;
}
static struct V_286 * F_253 ( struct V_287 * V_47 )
{
struct V_286 * V_288 ;
F_82 ( V_47 -> V_289 ) ;
V_288 = V_47 -> V_290 ;
return F_254 ( V_288 , F_255 ( V_47 -> V_2 ) ) ;
}
static int F_256 ( struct V_291 * V_292 , void * V_293 )
{
struct V_1 * V_2 = F_11 ( F_257 ( V_292 ) ) ;
struct V_287 * V_294 ;
if ( ! F_3 ( V_2 ) )
return - V_295 ;
F_258 ( V_292 ) ;
F_143 ( & V_296 ) ;
F_259 (params, &memcg->memcg_slab_caches, list)
F_260 ( F_253 ( V_294 ) , V_292 ) ;
F_150 ( & V_296 ) ;
return 0 ;
}
static int F_261 ( struct V_1 * V_2 , T_3 V_297 , T_2 V_267 )
{
struct V_264 * V_265 ;
int V_141 = 0 ;
V_141 = F_228 ( & V_2 -> V_30 , V_267 , & V_265 ) ;
if ( V_141 )
return V_141 ;
V_141 = F_226 ( V_2 , V_297 , V_267 >> V_150 ) ;
if ( V_141 == - V_278 ) {
F_262 ( & V_2 -> V_59 , V_267 , & V_265 ) ;
if ( V_152 )
F_262 ( & V_2 -> V_153 , V_267 ,
& V_265 ) ;
V_141 = 0 ;
} else if ( V_141 )
F_206 ( & V_2 -> V_30 , V_267 ) ;
return V_141 ;
}
static void F_263 ( struct V_1 * V_2 , T_2 V_267 )
{
F_206 ( & V_2 -> V_59 , V_267 ) ;
if ( V_152 )
F_206 ( & V_2 -> V_153 , V_267 ) ;
if ( F_206 ( & V_2 -> V_30 , V_267 ) )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
int F_255 ( struct V_1 * V_2 )
{
return V_2 ? V_2 -> V_29 : - 1 ;
}
static int F_264 ( void )
{
int V_16 , V_267 ;
int V_298 ;
V_16 = F_265 ( & V_299 ,
0 , V_300 , V_301 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_16 < V_302 )
return V_16 ;
V_267 = 2 * ( V_16 + 1 ) ;
if ( V_267 < V_303 )
V_267 = V_303 ;
else if ( V_267 > V_300 )
V_267 = V_300 ;
F_143 ( & V_296 ) ;
V_298 = F_266 ( V_267 ) ;
F_150 ( & V_296 ) ;
if ( V_298 ) {
F_267 ( & V_299 , V_16 ) ;
return V_298 ;
}
return V_16 ;
}
static void F_35 ( int V_16 )
{
F_267 ( & V_299 , V_16 ) ;
}
void F_268 ( int V_174 )
{
V_302 = V_174 ;
}
static void F_269 ( struct V_1 * V_2 ,
struct V_286 * V_290 )
{
static char V_304 [ V_305 + 1 ] ;
struct V_286 * V_288 ;
int V_16 ;
F_270 ( & V_296 ) ;
V_16 = F_255 ( V_2 ) ;
if ( F_254 ( V_290 , V_16 ) )
return;
F_271 ( V_2 -> V_12 . V_140 , V_304 , V_305 + 1 ) ;
V_288 = F_272 ( V_2 , V_290 , V_304 ) ;
if ( ! V_288 )
return;
F_21 ( & V_2 -> V_12 ) ;
F_273 ( & V_288 -> V_306 -> V_307 , & V_2 -> V_308 ) ;
F_6 () ;
F_20 ( V_290 -> V_306 -> V_309 [ V_16 ] ) ;
V_290 -> V_306 -> V_309 [ V_16 ] = V_288 ;
}
static void F_274 ( struct V_286 * V_288 )
{
struct V_286 * V_290 ;
struct V_1 * V_2 ;
int V_16 ;
F_270 ( & V_296 ) ;
F_20 ( V_289 ( V_288 ) ) ;
V_290 = V_288 -> V_306 -> V_290 ;
V_2 = V_288 -> V_306 -> V_2 ;
V_16 = F_255 ( V_2 ) ;
F_20 ( V_290 -> V_306 -> V_309 [ V_16 ] != V_288 ) ;
V_290 -> V_306 -> V_309 [ V_16 ] = NULL ;
F_275 ( & V_288 -> V_306 -> V_307 ) ;
F_276 ( V_288 ) ;
F_29 ( & V_2 -> V_12 ) ;
}
static inline void F_277 ( void )
{
F_82 ( ! V_25 -> V_105 ) ;
V_25 -> V_310 ++ ;
}
static inline void F_278 ( void )
{
F_82 ( ! V_25 -> V_105 ) ;
V_25 -> V_310 -- ;
}
int F_279 ( struct V_286 * V_11 )
{
struct V_286 * V_311 ;
int V_166 , V_208 = 0 ;
F_143 ( & V_296 ) ;
F_280 (i) {
V_311 = F_254 ( V_11 , V_166 ) ;
if ( ! V_311 )
continue;
F_274 ( V_311 ) ;
if ( F_254 ( V_11 , V_166 ) )
V_208 ++ ;
}
F_150 ( & V_296 ) ;
return V_208 ;
}
static void F_281 ( struct V_1 * V_2 )
{
struct V_286 * V_288 ;
struct V_287 * V_294 , * V_312 ;
if ( ! F_3 ( V_2 ) )
return;
F_143 ( & V_296 ) ;
F_282 (params, tmp, &memcg->memcg_slab_caches, list) {
V_288 = F_253 ( V_294 ) ;
F_283 ( V_288 ) ;
if ( F_102 ( & V_288 -> V_306 -> V_74 ) == 0 )
F_274 ( V_288 ) ;
}
F_150 ( & V_296 ) ;
}
static void F_284 ( struct V_244 * V_313 )
{
struct V_314 * V_315 =
F_12 ( V_313 , struct V_314 , V_247 ) ;
struct V_1 * V_2 = V_315 -> V_2 ;
struct V_286 * V_288 = V_315 -> V_288 ;
F_143 ( & V_296 ) ;
F_269 ( V_2 , V_288 ) ;
F_150 ( & V_296 ) ;
F_29 ( & V_2 -> V_12 ) ;
F_285 ( V_315 ) ;
}
static void F_286 ( struct V_1 * V_2 ,
struct V_286 * V_288 )
{
struct V_314 * V_315 ;
V_315 = F_287 ( sizeof( * V_315 ) , V_316 ) ;
if ( V_315 == NULL ) {
F_29 ( & V_2 -> V_12 ) ;
return;
}
V_315 -> V_2 = V_2 ;
V_315 -> V_288 = V_288 ;
F_212 ( & V_315 -> V_247 , F_284 ) ;
F_288 ( & V_315 -> V_247 ) ;
}
static void F_289 ( struct V_1 * V_2 ,
struct V_286 * V_288 )
{
F_277 () ;
F_286 ( V_2 , V_288 ) ;
F_278 () ;
}
int F_290 ( struct V_286 * V_288 , T_3 V_297 , int V_178 )
{
int V_59 ;
V_59 = F_261 ( V_288 -> V_306 -> V_2 , V_297 ,
V_243 << V_178 ) ;
if ( ! V_59 )
F_291 ( 1 << V_178 , & V_288 -> V_306 -> V_74 ) ;
return V_59 ;
}
void F_292 ( struct V_286 * V_288 , int V_178 )
{
F_263 ( V_288 -> V_306 -> V_2 , V_243 << V_178 ) ;
F_293 ( 1 << V_178 , & V_288 -> V_306 -> V_74 ) ;
}
struct V_286 * F_294 ( struct V_286 * V_288 ,
T_3 V_297 )
{
struct V_1 * V_2 ;
struct V_286 * V_317 ;
F_82 ( ! V_288 -> V_306 ) ;
F_82 ( ! V_288 -> V_306 -> V_289 ) ;
if ( ! V_25 -> V_105 || V_25 -> V_310 )
return V_288 ;
F_22 () ;
V_2 = F_23 ( F_96 ( V_25 -> V_105 -> V_106 ) ) ;
if ( ! F_3 ( V_2 ) )
goto V_132;
V_317 = F_254 ( V_288 , F_255 ( V_2 ) ) ;
if ( F_295 ( V_317 ) ) {
V_288 = V_317 ;
goto V_132;
}
if ( ! F_25 ( & V_2 -> V_12 ) )
goto V_132;
F_26 () ;
F_289 ( V_2 , V_288 ) ;
return V_288 ;
V_132:
F_26 () ;
return V_288 ;
}
bool
F_296 ( T_3 V_297 , struct V_1 * * V_318 , int V_178 )
{
struct V_1 * V_2 ;
int V_141 ;
* V_318 = NULL ;
if ( ! V_25 -> V_105 || V_25 -> V_310 )
return true ;
V_2 = F_95 ( V_25 -> V_105 ) ;
if ( ! F_3 ( V_2 ) ) {
F_29 ( & V_2 -> V_12 ) ;
return true ;
}
V_141 = F_261 ( V_2 , V_297 , V_243 << V_178 ) ;
if ( ! V_141 )
* V_318 = V_2 ;
F_29 ( & V_2 -> V_12 ) ;
return ( V_141 == 0 ) ;
}
void F_297 ( struct V_38 * V_38 , struct V_1 * V_2 ,
int V_178 )
{
struct V_137 * V_138 ;
F_82 ( F_15 ( V_2 ) ) ;
if ( ! V_38 ) {
F_263 ( V_2 , V_243 << V_178 ) ;
return;
}
V_138 = F_113 ( V_38 ) ;
V_138 -> V_1 = V_2 ;
V_138 -> V_56 = V_283 ;
}
void F_298 ( struct V_38 * V_38 , int V_178 )
{
struct V_1 * V_2 = NULL ;
struct V_137 * V_138 ;
V_138 = F_113 ( V_38 ) ;
if ( ! F_115 ( V_138 ) )
return;
V_2 = V_138 -> V_1 ;
V_138 -> V_56 = 0 ;
if ( ! V_2 )
return;
F_239 ( F_15 ( V_2 ) , V_38 ) ;
F_263 ( V_2 , V_243 << V_178 ) ;
}
static inline void F_281 ( struct V_1 * V_2 )
{
}
void F_299 ( struct V_38 * V_319 )
{
struct V_137 * V_320 = F_113 ( V_319 ) ;
struct V_137 * V_138 ;
struct V_1 * V_2 ;
int V_166 ;
if ( F_106 () )
return;
V_2 = V_320 -> V_1 ;
for ( V_166 = 1 ; V_166 < V_321 ; V_166 ++ ) {
V_138 = V_320 + V_166 ;
V_138 -> V_1 = V_2 ;
V_138 -> V_56 = V_320 -> V_56 ;
}
F_300 ( V_2 -> V_68 -> V_69 [ V_77 ] ,
V_321 ) ;
}
static int F_301 ( struct V_38 * V_38 ,
unsigned int V_74 ,
struct V_137 * V_138 ,
struct V_1 * V_157 ,
struct V_1 * V_158 )
{
unsigned long V_56 ;
int V_141 ;
F_82 ( V_157 == V_158 ) ;
F_239 ( F_114 ( V_38 ) , V_38 ) ;
V_141 = - V_322 ;
if ( V_74 > 1 && ! F_78 ( V_38 ) )
goto V_132;
if ( ! F_302 ( V_38 ) )
goto V_132;
V_141 = - V_323 ;
if ( ! F_115 ( V_138 ) || V_138 -> V_1 != V_157 )
goto V_130;
F_139 ( V_157 , & V_56 ) ;
if ( ! F_76 ( V_38 ) && F_303 ( V_38 ) ) {
F_300 ( V_157 -> V_68 -> V_69 [ V_324 ] ,
V_74 ) ;
F_77 ( V_158 -> V_68 -> V_69 [ V_324 ] ,
V_74 ) ;
}
if ( F_304 ( V_38 ) ) {
F_300 ( V_157 -> V_68 -> V_69 [ V_325 ] ,
V_74 ) ;
F_77 ( V_158 -> V_68 -> V_69 [ V_325 ] ,
V_74 ) ;
}
V_138 -> V_1 = V_158 ;
F_140 ( V_157 , & V_56 ) ;
V_141 = 0 ;
F_305 () ;
F_75 ( V_158 , V_38 , V_74 ) ;
F_90 ( V_158 , V_38 ) ;
F_75 ( V_157 , V_38 , - V_74 ) ;
F_90 ( V_157 , V_38 ) ;
F_306 () ;
V_130:
F_307 ( V_38 ) ;
V_132:
return V_141 ;
}
static int F_308 ( struct V_38 * V_38 ,
struct V_137 * V_138 ,
struct V_1 * V_326 )
{
struct V_1 * V_49 ;
unsigned int V_74 ;
unsigned long V_125 ( V_56 ) ;
int V_141 ;
F_82 ( F_15 ( V_326 ) ) ;
V_141 = - V_322 ;
if ( ! F_309 ( V_38 ) )
goto V_132;
if ( F_310 ( V_38 ) )
goto V_327;
V_74 = F_311 ( V_38 ) ;
V_49 = F_57 ( V_326 ) ;
if ( ! V_49 )
V_49 = V_14 ;
if ( V_74 > 1 ) {
F_239 ( ! F_78 ( V_38 ) , V_38 ) ;
V_56 = F_312 ( V_38 ) ;
}
V_141 = F_301 ( V_38 , V_74 ,
V_138 , V_326 , V_49 ) ;
if ( ! V_141 )
F_235 ( V_326 , V_74 ) ;
if ( V_74 > 1 )
F_313 ( V_38 , V_56 ) ;
F_314 ( V_38 ) ;
V_327:
F_315 ( V_38 ) ;
V_132:
return V_141 ;
}
static void F_316 ( struct V_1 * V_2 ,
bool V_328 )
{
int V_66 = ( V_328 ) ? 1 : - 1 ;
F_201 ( V_2 -> V_68 -> V_69 [ V_170 ] , V_66 ) ;
}
static int F_317 ( T_6 V_329 ,
struct V_1 * V_157 , struct V_1 * V_158 )
{
unsigned short V_330 , V_331 ;
V_330 = F_16 ( V_157 ) ;
V_331 = F_16 ( V_158 ) ;
if ( F_318 ( V_329 , V_330 , V_331 ) == V_330 ) {
F_316 ( V_157 , false ) ;
F_316 ( V_158 , true ) ;
F_21 ( & V_158 -> V_12 ) ;
return 0 ;
}
return - V_323 ;
}
static inline int F_317 ( T_6 V_329 ,
struct V_1 * V_157 , struct V_1 * V_158 )
{
return - V_323 ;
}
static struct V_137 * F_319 ( struct V_38 * V_38 )
{
struct V_137 * V_138 ;
V_138 = F_113 ( V_38 ) ;
if ( F_295 ( V_138 ) && F_115 ( V_138 ) )
return V_138 ;
return NULL ;
}
bool F_320 ( struct V_38 * V_38 )
{
if ( F_106 () )
return false ;
return F_319 ( V_38 ) != NULL ;
}
void F_321 ( struct V_38 * V_38 )
{
struct V_137 * V_138 ;
V_138 = F_319 ( V_38 ) ;
if ( V_138 ) {
F_322 ( L_12 ,
V_138 , V_138 -> V_56 , V_138 -> V_1 ) ;
}
}
static int F_323 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_332 ;
int V_141 = 0 ;
int V_333 = F_151 ( V_2 ) ;
T_2 V_334 , V_335 ;
int V_336 ;
V_332 = V_262 * V_333 ;
V_335 = F_36 ( & V_2 -> V_59 , V_31 ) ;
V_336 = 0 ;
while ( V_332 ) {
if ( F_324 ( V_25 ) ) {
V_141 = - V_278 ;
break;
}
F_143 ( & V_337 ) ;
if ( F_36 ( & V_2 -> V_153 , V_167 ) < V_66 ) {
V_141 = - V_323 ;
F_150 ( & V_337 ) ;
break;
}
if ( F_36 ( & V_2 -> V_59 , V_167 ) < V_66 )
V_336 = 1 ;
V_141 = F_325 ( & V_2 -> V_59 , V_66 ) ;
F_150 ( & V_337 ) ;
if ( ! V_141 )
break;
F_232 ( V_2 , 1 , V_301 , true ) ;
V_334 = F_36 ( & V_2 -> V_59 , V_31 ) ;
if ( V_334 >= V_335 )
V_332 -- ;
else
V_335 = V_334 ;
}
if ( ! V_141 && V_336 )
F_192 ( V_2 ) ;
return V_141 ;
}
static int F_326 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_332 ;
T_2 V_335 , V_334 ;
int V_333 = F_151 ( V_2 ) ;
int V_141 = - V_322 ;
int V_336 = 0 ;
V_332 = V_333 * V_262 ;
V_335 = F_36 ( & V_2 -> V_153 , V_31 ) ;
while ( V_332 ) {
if ( F_324 ( V_25 ) ) {
V_141 = - V_278 ;
break;
}
F_143 ( & V_337 ) ;
if ( F_36 ( & V_2 -> V_59 , V_167 ) > V_66 ) {
V_141 = - V_323 ;
F_150 ( & V_337 ) ;
break;
}
if ( F_36 ( & V_2 -> V_153 , V_167 ) < V_66 )
V_336 = 1 ;
V_141 = F_325 ( & V_2 -> V_153 , V_66 ) ;
F_150 ( & V_337 ) ;
if ( ! V_141 )
break;
F_232 ( V_2 , 1 , V_301 , false ) ;
V_334 = F_36 ( & V_2 -> V_153 , V_31 ) ;
if ( V_334 >= V_335 )
V_332 -- ;
else
V_335 = V_334 ;
}
if ( ! V_141 && V_336 )
F_192 ( V_2 ) ;
return V_141 ;
}
unsigned long F_327 ( struct V_33 * V_33 , int V_178 ,
T_3 V_177 ,
unsigned long * V_202 )
{
unsigned long V_266 = 0 ;
struct V_32 * V_43 , * V_338 = NULL ;
unsigned long V_339 ;
int V_205 = 0 ;
struct V_39 * V_44 ;
unsigned long long V_58 ;
unsigned long V_206 ;
if ( V_178 > 0 )
return 0 ;
V_44 = F_45 ( F_39 ( V_33 ) , F_40 ( V_33 ) ) ;
do {
if ( V_338 )
V_43 = V_338 ;
else
V_43 = F_63 ( V_44 ) ;
if ( ! V_43 )
break;
V_206 = 0 ;
V_339 = F_179 ( V_43 -> V_2 , V_33 ,
V_177 , & V_206 ) ;
V_266 += V_339 ;
* V_202 += V_206 ;
F_64 ( & V_44 -> V_57 ) ;
V_338 = NULL ;
if ( ! V_339 ) {
do {
V_338 =
F_61 ( V_44 ) ;
if ( V_338 == V_43 )
F_29 ( & V_338 -> V_2 -> V_12 ) ;
else
break;
} while ( 1 );
}
F_51 ( V_43 , V_44 ) ;
V_58 = F_58 ( & V_43 -> V_2 -> V_59 ) ;
F_47 ( V_43 , V_44 , V_58 ) ;
F_65 ( & V_44 -> V_57 ) ;
F_29 ( & V_43 -> V_2 -> V_12 ) ;
V_205 ++ ;
if ( ! V_266 &&
( V_338 == NULL ||
V_205 > V_340 ) )
break;
} while ( ! V_266 );
if ( V_338 )
F_29 ( & V_338 -> V_2 -> V_12 ) ;
return V_266 ;
}
static void F_328 ( struct V_1 * V_2 ,
int V_200 , int V_35 , enum V_82 V_83 )
{
struct V_81 * V_81 ;
unsigned long V_56 ;
struct V_341 * V_307 ;
struct V_38 * V_342 ;
struct V_33 * V_33 ;
V_33 = & F_329 ( V_200 ) -> V_343 [ V_35 ] ;
V_81 = F_111 ( V_33 , V_2 ) ;
V_307 = & V_81 -> V_344 [ V_83 ] ;
V_342 = NULL ;
do {
struct V_137 * V_138 ;
struct V_38 * V_38 ;
F_54 ( & V_33 -> V_281 , V_56 ) ;
if ( F_330 ( V_307 ) ) {
F_55 ( & V_33 -> V_281 , V_56 ) ;
break;
}
V_38 = F_331 ( V_307 -> V_120 , struct V_38 , V_83 ) ;
if ( V_342 == V_38 ) {
F_332 ( & V_38 -> V_83 , V_307 ) ;
V_342 = NULL ;
F_55 ( & V_33 -> V_281 , V_56 ) ;
continue;
}
F_55 ( & V_33 -> V_281 , V_56 ) ;
V_138 = F_113 ( V_38 ) ;
if ( F_308 ( V_38 , V_138 , V_2 ) ) {
V_342 = V_38 ;
} else
V_342 = NULL ;
F_333 () ;
} while ( ! F_330 ( V_307 ) );
}
static void F_334 ( struct V_1 * V_2 )
{
int V_200 , V_35 ;
T_2 V_345 ;
do {
F_335 () ;
F_222 ( V_2 ) ;
F_129 ( V_2 ) ;
F_86 (node, N_MEMORY) {
for ( V_35 = 0 ; V_35 < V_60 ; V_35 ++ ) {
enum V_82 V_83 ;
F_83 (lru) {
F_328 ( V_2 ,
V_200 , V_35 , V_83 ) ;
}
}
}
F_131 ( V_2 ) ;
F_192 ( V_2 ) ;
F_333 () ;
V_345 = F_36 ( & V_2 -> V_59 , V_31 ) -
F_36 ( & V_2 -> V_30 , V_31 ) ;
} while ( V_345 > 0 );
}
static inline bool F_336 ( struct V_1 * V_2 )
{
bool V_141 ;
F_270 ( & V_346 ) ;
F_22 () ;
V_141 = F_337 ( NULL , & V_2 -> V_12 ) ;
F_26 () ;
return V_141 ;
}
static int F_338 ( struct V_1 * V_2 )
{
int V_261 = V_262 ;
F_335 () ;
while ( V_261 && F_36 ( & V_2 -> V_59 , V_31 ) > 0 ) {
int V_347 ;
if ( F_324 ( V_25 ) )
return - V_278 ;
V_347 = F_232 ( V_2 , 1 ,
V_301 , true ) ;
if ( ! V_347 ) {
V_261 -- ;
F_339 ( V_348 , V_349 / 10 ) ;
}
}
return 0 ;
}
static T_7 F_340 ( struct V_350 * V_351 ,
char * V_352 , T_8 V_353 ,
T_9 V_354 )
{
struct V_1 * V_2 = F_11 ( F_341 ( V_351 ) ) ;
if ( F_15 ( V_2 ) )
return - V_323 ;
return F_338 ( V_2 ) ? : V_353 ;
}
static T_2 F_342 ( struct V_10 * V_12 ,
struct V_355 * V_356 )
{
return F_11 ( V_12 ) -> V_123 ;
}
static int F_343 ( struct V_10 * V_12 ,
struct V_355 * V_356 , T_2 V_66 )
{
int V_357 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_358 = F_11 ( V_2 -> V_12 . V_49 ) ;
F_143 ( & V_346 ) ;
if ( V_2 -> V_123 == V_66 )
goto V_132;
if ( ( ! V_358 || ! V_358 -> V_123 ) &&
( V_66 == 1 || V_66 == 0 ) ) {
if ( ! F_336 ( V_2 ) )
V_2 -> V_123 = V_66 ;
else
V_357 = - V_322 ;
} else
V_357 = - V_323 ;
V_132:
F_150 ( & V_346 ) ;
return V_357 ;
}
static unsigned long F_344 ( struct V_1 * V_2 ,
enum V_64 V_65 )
{
struct V_1 * V_115 ;
long V_66 = 0 ;
F_147 (iter, memcg)
V_66 += F_66 ( V_115 , V_65 ) ;
if ( V_66 < 0 )
V_66 = 0 ;
return V_66 ;
}
static inline T_2 F_345 ( struct V_1 * V_2 , bool V_359 )
{
T_2 V_66 ;
if ( ! F_15 ( V_2 ) ) {
if ( ! V_359 )
return F_36 ( & V_2 -> V_59 , V_31 ) ;
else
return F_36 ( & V_2 -> V_153 , V_31 ) ;
}
V_66 = F_344 ( V_2 , V_76 ) ;
V_66 += F_344 ( V_2 , V_75 ) ;
if ( V_359 )
V_66 += F_344 ( V_2 , V_170 ) ;
return V_66 << V_150 ;
}
static T_2 F_346 ( struct V_10 * V_12 ,
struct V_355 * V_356 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
enum V_360 type = F_347 ( V_356 -> V_231 ) ;
int V_361 = F_348 ( V_356 -> V_231 ) ;
switch ( type ) {
case V_362 :
if ( V_361 == V_31 )
return F_345 ( V_2 , false ) ;
return F_36 ( & V_2 -> V_59 , V_361 ) ;
case V_363 :
if ( V_361 == V_31 )
return F_345 ( V_2 , true ) ;
return F_36 ( & V_2 -> V_153 , V_361 ) ;
case V_364 :
return F_36 ( & V_2 -> V_30 , V_361 ) ;
break;
default:
F_110 () ;
}
}
static int F_349 ( struct V_1 * V_2 ,
unsigned long long V_175 )
{
int V_298 = 0 ;
int V_365 ;
if ( F_3 ( V_2 ) )
return 0 ;
F_277 () ;
F_143 ( & V_346 ) ;
if ( F_350 ( V_2 -> V_12 . V_140 ) ||
( V_2 -> V_123 && F_336 ( V_2 ) ) )
V_298 = - V_322 ;
F_150 ( & V_346 ) ;
if ( V_298 )
goto V_132;
V_365 = F_264 () ;
if ( V_365 < 0 ) {
V_298 = V_365 ;
goto V_132;
}
V_2 -> V_29 = V_365 ;
F_195 ( & V_2 -> V_308 ) ;
V_298 = F_325 ( & V_2 -> V_30 , V_175 ) ;
F_82 ( V_298 ) ;
F_351 ( & V_28 ) ;
F_1 ( V_2 ) ;
V_132:
F_278 () ;
return V_298 ;
}
static int F_352 ( struct V_1 * V_2 ,
unsigned long long V_175 )
{
int V_141 ;
F_143 ( & V_366 ) ;
V_141 = F_349 ( V_2 , V_175 ) ;
F_150 ( & V_366 ) ;
return V_141 ;
}
static int F_353 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
int V_141 ;
if ( ! F_3 ( V_2 ) )
V_141 = F_352 ( V_2 , V_66 ) ;
else
V_141 = F_325 ( & V_2 -> V_30 , V_66 ) ;
return V_141 ;
}
static int F_354 ( struct V_1 * V_2 )
{
int V_141 = 0 ;
struct V_1 * V_49 = F_57 ( V_2 ) ;
if ( ! V_49 )
return 0 ;
F_143 ( & V_366 ) ;
if ( F_3 ( V_49 ) )
V_141 = F_349 ( V_2 , V_367 ) ;
F_150 ( & V_366 ) ;
return V_141 ;
}
static int F_353 ( struct V_1 * V_2 ,
unsigned long long V_66 )
{
return - V_323 ;
}
static T_7 F_355 ( struct V_350 * V_351 ,
char * V_352 , T_8 V_353 , T_9 V_354 )
{
struct V_1 * V_2 = F_11 ( F_341 ( V_351 ) ) ;
enum V_360 type ;
int V_361 ;
unsigned long long V_66 ;
int V_141 ;
V_352 = F_356 ( V_352 ) ;
type = F_347 ( F_357 ( V_351 ) -> V_231 ) ;
V_361 = F_348 ( F_357 ( V_351 ) -> V_231 ) ;
switch ( V_361 ) {
case V_167 :
if ( F_15 ( V_2 ) ) {
V_141 = - V_323 ;
break;
}
V_141 = F_358 ( V_352 , & V_66 ) ;
if ( V_141 )
break;
if ( type == V_362 )
V_141 = F_323 ( V_2 , V_66 ) ;
else if ( type == V_363 )
V_141 = F_326 ( V_2 , V_66 ) ;
else if ( type == V_364 )
V_141 = F_353 ( V_2 , V_66 ) ;
else
return - V_323 ;
break;
case V_368 :
V_141 = F_358 ( V_352 , & V_66 ) ;
if ( V_141 )
break;
if ( type == V_362 )
V_141 = F_359 ( & V_2 -> V_59 , V_66 ) ;
else
V_141 = - V_323 ;
break;
default:
V_141 = - V_323 ;
break;
}
return V_141 ? : V_353 ;
}
static void F_360 ( struct V_1 * V_2 ,
unsigned long long * V_369 , unsigned long long * V_370 )
{
unsigned long long V_371 , V_372 , V_312 ;
V_371 = F_36 ( & V_2 -> V_59 , V_167 ) ;
V_372 = F_36 ( & V_2 -> V_153 , V_167 ) ;
if ( ! V_2 -> V_123 )
goto V_132;
while ( V_2 -> V_12 . V_49 ) {
V_2 = F_11 ( V_2 -> V_12 . V_49 ) ;
if ( ! V_2 -> V_123 )
break;
V_312 = F_36 ( & V_2 -> V_59 , V_167 ) ;
V_371 = F_127 ( V_371 , V_312 ) ;
V_312 = F_36 ( & V_2 -> V_153 , V_167 ) ;
V_372 = F_127 ( V_372 , V_312 ) ;
}
V_132:
* V_369 = V_371 ;
* V_370 = V_372 ;
}
static T_7 F_361 ( struct V_350 * V_351 , char * V_352 ,
T_8 V_353 , T_9 V_354 )
{
struct V_1 * V_2 = F_11 ( F_341 ( V_351 ) ) ;
int V_361 ;
enum V_360 type ;
type = F_347 ( F_357 ( V_351 ) -> V_231 ) ;
V_361 = F_348 ( F_357 ( V_351 ) -> V_231 ) ;
switch ( V_361 ) {
case V_373 :
if ( type == V_362 )
F_362 ( & V_2 -> V_59 ) ;
else if ( type == V_363 )
F_362 ( & V_2 -> V_153 ) ;
else if ( type == V_364 )
F_362 ( & V_2 -> V_30 ) ;
else
return - V_323 ;
break;
case V_168 :
if ( type == V_362 )
F_363 ( & V_2 -> V_59 ) ;
else if ( type == V_363 )
F_363 ( & V_2 -> V_153 ) ;
else if ( type == V_364 )
F_363 ( & V_2 -> V_30 ) ;
else
return - V_323 ;
break;
}
return V_353 ;
}
static T_2 F_364 ( struct V_10 * V_12 ,
struct V_355 * V_356 )
{
return F_11 ( V_12 ) -> V_374 ;
}
static int F_365 ( struct V_10 * V_12 ,
struct V_355 * V_356 , T_2 V_66 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_66 >= ( 1 << V_375 ) )
return - V_323 ;
V_2 -> V_374 = V_66 ;
return 0 ;
}
static int F_365 ( struct V_10 * V_12 ,
struct V_355 * V_356 , T_2 V_66 )
{
return - V_376 ;
}
static int F_366 ( struct V_291 * V_292 , void * V_293 )
{
struct V_377 {
const char * V_361 ;
unsigned int V_85 ;
};
static const struct V_377 V_378 [] = {
{ L_13 , V_379 } ,
{ L_14 , V_194 } ,
{ L_15 , V_195 } ,
{ L_16 , F_84 (LRU_UNEVICTABLE) } ,
} ;
const struct V_377 * V_68 ;
int V_34 ;
unsigned long V_86 ;
struct V_1 * V_2 = F_11 ( F_257 ( V_292 ) ) ;
for ( V_68 = V_378 ; V_68 < V_378 + F_367 ( V_378 ) ; V_68 ++ ) {
V_86 = F_85 ( V_2 , V_68 -> V_85 ) ;
F_368 ( V_292 , L_17 , V_68 -> V_361 , V_86 ) ;
F_86 (nid, N_MEMORY) {
V_86 = F_81 ( V_2 , V_34 ,
V_68 -> V_85 ) ;
F_368 ( V_292 , L_18 , V_34 , V_86 ) ;
}
F_369 ( V_292 , '\n' ) ;
}
for ( V_68 = V_378 ; V_68 < V_378 + F_367 ( V_378 ) ; V_68 ++ ) {
struct V_1 * V_115 ;
V_86 = 0 ;
F_147 (iter, memcg)
V_86 += F_85 ( V_115 , V_68 -> V_85 ) ;
F_368 ( V_292 , L_19 , V_68 -> V_361 , V_86 ) ;
F_86 (nid, N_MEMORY) {
V_86 = 0 ;
F_147 (iter, memcg)
V_86 += F_81 (
V_115 , V_34 , V_68 -> V_85 ) ;
F_368 ( V_292 , L_18 , V_34 , V_86 ) ;
}
F_369 ( V_292 , '\n' ) ;
}
return 0 ;
}
static inline void F_370 ( void )
{
F_371 ( F_367 ( V_173 ) != V_172 ) ;
}
static int F_372 ( struct V_291 * V_292 , void * V_293 )
{
struct V_1 * V_2 = F_11 ( F_257 ( V_292 ) ) ;
struct V_1 * V_380 ;
unsigned int V_166 ;
for ( V_166 = 0 ; V_166 < V_169 ; V_166 ++ ) {
if ( V_166 == V_170 && ! V_152 )
continue;
F_368 ( V_292 , L_20 , V_171 [ V_166 ] ,
F_66 ( V_2 , V_166 ) * V_243 ) ;
}
for ( V_166 = 0 ; V_166 < V_251 ; V_166 ++ )
F_368 ( V_292 , L_21 , V_381 [ V_166 ] ,
F_74 ( V_2 , V_166 ) ) ;
for ( V_166 = 0 ; V_166 < V_172 ; V_166 ++ )
F_368 ( V_292 , L_21 , V_173 [ V_166 ] ,
F_85 ( V_2 , F_84 ( V_166 ) ) * V_243 ) ;
{
unsigned long long V_175 , V_370 ;
F_360 ( V_2 , & V_175 , & V_370 ) ;
F_368 ( V_292 , L_22 , V_175 ) ;
if ( V_152 )
F_368 ( V_292 , L_23 ,
V_370 ) ;
}
for ( V_166 = 0 ; V_166 < V_169 ; V_166 ++ ) {
long long V_66 = 0 ;
if ( V_166 == V_170 && ! V_152 )
continue;
F_147 (mi, memcg)
V_66 += F_66 ( V_380 , V_166 ) * V_243 ;
F_368 ( V_292 , L_24 , V_171 [ V_166 ] , V_66 ) ;
}
for ( V_166 = 0 ; V_166 < V_251 ; V_166 ++ ) {
unsigned long long V_66 = 0 ;
F_147 (mi, memcg)
V_66 += F_74 ( V_380 , V_166 ) ;
F_368 ( V_292 , L_25 ,
V_381 [ V_166 ] , V_66 ) ;
}
for ( V_166 = 0 ; V_166 < V_172 ; V_166 ++ ) {
unsigned long long V_66 = 0 ;
F_147 (mi, memcg)
V_66 += F_85 ( V_380 , F_84 ( V_166 ) ) * V_243 ;
F_368 ( V_292 , L_25 , V_173 [ V_166 ] , V_66 ) ;
}
#ifdef F_373
{
int V_34 , V_35 ;
struct V_32 * V_43 ;
struct V_382 * V_383 ;
unsigned long V_384 [ 2 ] = { 0 , 0 } ;
unsigned long V_385 [ 2 ] = { 0 , 0 } ;
F_374 (nid)
for ( V_35 = 0 ; V_35 < V_60 ; V_35 ++ ) {
V_43 = & V_2 -> V_36 [ V_34 ] -> V_37 [ V_35 ] ;
V_383 = & V_43 -> V_81 . V_386 ;
V_384 [ 0 ] += V_383 -> V_384 [ 0 ] ;
V_384 [ 1 ] += V_383 -> V_384 [ 1 ] ;
V_385 [ 0 ] += V_383 -> V_385 [ 0 ] ;
V_385 [ 1 ] += V_383 -> V_385 [ 1 ] ;
}
F_368 ( V_292 , L_26 , V_384 [ 0 ] ) ;
F_368 ( V_292 , L_27 , V_384 [ 1 ] ) ;
F_368 ( V_292 , L_28 , V_385 [ 0 ] ) ;
F_368 ( V_292 , L_29 , V_385 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_375 ( struct V_10 * V_12 ,
struct V_355 * V_356 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
return F_128 ( V_2 ) ;
}
static int F_376 ( struct V_10 * V_12 ,
struct V_355 * V_356 , T_2 V_66 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( V_66 > 100 )
return - V_323 ;
if ( V_12 -> V_49 )
V_2 -> V_155 = V_66 ;
else
V_154 = V_66 ;
return 0 ;
}
static void F_377 ( struct V_1 * V_2 , bool V_359 )
{
struct V_387 * V_388 ;
T_2 V_345 ;
int V_166 ;
F_22 () ;
if ( ! V_359 )
V_388 = F_96 ( V_2 -> V_389 . V_390 ) ;
else
V_388 = F_96 ( V_2 -> V_391 . V_390 ) ;
if ( ! V_388 )
goto V_159;
V_345 = F_345 ( V_2 , V_359 ) ;
V_166 = V_388 -> V_392 ;
for (; V_166 >= 0 && F_91 ( V_388 -> V_393 [ V_166 ] . V_394 > V_345 ) ; V_166 -- )
F_378 ( V_388 -> V_393 [ V_166 ] . V_395 , 1 ) ;
V_166 ++ ;
for (; V_166 < V_388 -> V_267 && F_91 ( V_388 -> V_393 [ V_166 ] . V_394 <= V_345 ) ; V_166 ++ )
F_378 ( V_388 -> V_393 [ V_166 ] . V_395 , 1 ) ;
V_388 -> V_392 = V_166 - 1 ;
V_159:
F_26 () ;
}
static void F_92 ( struct V_1 * V_2 )
{
while ( V_2 ) {
F_377 ( V_2 , false ) ;
if ( V_152 )
F_377 ( V_2 , true ) ;
V_2 = F_57 ( V_2 ) ;
}
}
static int F_379 ( const void * V_396 , const void * V_397 )
{
const struct F_92 * V_398 = V_396 ;
const struct F_92 * V_399 = V_397 ;
if ( V_398 -> V_394 > V_399 -> V_394 )
return 1 ;
if ( V_398 -> V_394 < V_399 -> V_394 )
return - 1 ;
return 0 ;
}
static int F_380 ( struct V_1 * V_2 )
{
struct V_400 * V_401 ;
F_71 ( & V_209 ) ;
F_259 (ev, &memcg->oom_notify, list)
F_378 ( V_401 -> V_395 , 1 ) ;
F_72 ( & V_209 ) ;
return 0 ;
}
static void F_196 ( struct V_1 * V_2 )
{
struct V_1 * V_115 ;
F_147 (iter, memcg)
F_380 ( V_115 ) ;
}
static int F_381 ( struct V_1 * V_2 ,
struct V_402 * V_395 , const char * args , enum V_360 type )
{
struct V_403 * V_389 ;
struct V_387 * V_404 ;
T_2 V_394 , V_345 ;
int V_166 , V_267 , V_141 ;
V_141 = F_358 ( args , & V_394 ) ;
if ( V_141 )
return V_141 ;
F_143 ( & V_2 -> V_405 ) ;
if ( type == V_362 ) {
V_389 = & V_2 -> V_389 ;
V_345 = F_345 ( V_2 , false ) ;
} else if ( type == V_363 ) {
V_389 = & V_2 -> V_391 ;
V_345 = F_345 ( V_2 , true ) ;
} else
F_110 () ;
if ( V_389 -> V_390 )
F_377 ( V_2 , type == V_363 ) ;
V_267 = V_389 -> V_390 ? V_389 -> V_390 -> V_267 + 1 : 1 ;
V_404 = F_287 ( sizeof( * V_404 ) + V_267 * sizeof( struct F_92 ) ,
V_301 ) ;
if ( ! V_404 ) {
V_141 = - V_277 ;
goto V_159;
}
V_404 -> V_267 = V_267 ;
if ( V_389 -> V_390 ) {
memcpy ( V_404 -> V_393 , V_389 -> V_390 -> V_393 , ( V_267 - 1 ) *
sizeof( struct F_92 ) ) ;
}
V_404 -> V_393 [ V_267 - 1 ] . V_395 = V_395 ;
V_404 -> V_393 [ V_267 - 1 ] . V_394 = V_394 ;
F_382 ( V_404 -> V_393 , V_267 , sizeof( struct F_92 ) ,
F_379 , NULL ) ;
V_404 -> V_392 = - 1 ;
for ( V_166 = 0 ; V_166 < V_267 ; V_166 ++ ) {
if ( V_404 -> V_393 [ V_166 ] . V_394 <= V_345 ) {
++ V_404 -> V_392 ;
} else
break;
}
F_285 ( V_389 -> V_406 ) ;
V_389 -> V_406 = V_389 -> V_390 ;
F_383 ( V_389 -> V_390 , V_404 ) ;
F_130 () ;
V_159:
F_150 ( & V_2 -> V_405 ) ;
return V_141 ;
}
static int F_384 ( struct V_1 * V_2 ,
struct V_402 * V_395 , const char * args )
{
return F_381 ( V_2 , V_395 , args , V_362 ) ;
}
static int F_385 ( struct V_1 * V_2 ,
struct V_402 * V_395 , const char * args )
{
return F_381 ( V_2 , V_395 , args , V_363 ) ;
}
static void F_386 ( struct V_1 * V_2 ,
struct V_402 * V_395 , enum V_360 type )
{
struct V_403 * V_389 ;
struct V_387 * V_404 ;
T_2 V_345 ;
int V_166 , V_407 , V_267 ;
F_143 ( & V_2 -> V_405 ) ;
if ( type == V_362 ) {
V_389 = & V_2 -> V_389 ;
V_345 = F_345 ( V_2 , false ) ;
} else if ( type == V_363 ) {
V_389 = & V_2 -> V_391 ;
V_345 = F_345 ( V_2 , true ) ;
} else
F_110 () ;
if ( ! V_389 -> V_390 )
goto V_159;
F_377 ( V_2 , type == V_363 ) ;
V_267 = 0 ;
for ( V_166 = 0 ; V_166 < V_389 -> V_390 -> V_267 ; V_166 ++ ) {
if ( V_389 -> V_390 -> V_393 [ V_166 ] . V_395 != V_395 )
V_267 ++ ;
}
V_404 = V_389 -> V_406 ;
if ( ! V_267 ) {
F_285 ( V_404 ) ;
V_404 = NULL ;
goto V_408;
}
V_404 -> V_267 = V_267 ;
V_404 -> V_392 = - 1 ;
for ( V_166 = 0 , V_407 = 0 ; V_166 < V_389 -> V_390 -> V_267 ; V_166 ++ ) {
if ( V_389 -> V_390 -> V_393 [ V_166 ] . V_395 == V_395 )
continue;
V_404 -> V_393 [ V_407 ] = V_389 -> V_390 -> V_393 [ V_166 ] ;
if ( V_404 -> V_393 [ V_407 ] . V_394 <= V_345 ) {
++ V_404 -> V_392 ;
}
V_407 ++ ;
}
V_408:
V_389 -> V_406 = V_389 -> V_390 ;
if ( ! V_404 ) {
F_285 ( V_389 -> V_406 ) ;
V_389 -> V_406 = NULL ;
}
F_383 ( V_389 -> V_390 , V_404 ) ;
F_130 () ;
V_159:
F_150 ( & V_2 -> V_405 ) ;
}
static void F_387 ( struct V_1 * V_2 ,
struct V_402 * V_395 )
{
return F_386 ( V_2 , V_395 , V_362 ) ;
}
static void F_388 ( struct V_1 * V_2 ,
struct V_402 * V_395 )
{
return F_386 ( V_2 , V_395 , V_363 ) ;
}
static int F_389 ( struct V_1 * V_2 ,
struct V_402 * V_395 , const char * args )
{
struct V_400 * V_409 ;
V_409 = F_287 ( sizeof( * V_409 ) , V_301 ) ;
if ( ! V_409 )
return - V_277 ;
F_71 ( & V_209 ) ;
V_409 -> V_395 = V_395 ;
F_273 ( & V_409 -> V_307 , & V_2 -> V_410 ) ;
if ( F_102 ( & V_2 -> V_213 ) )
F_378 ( V_395 , 1 ) ;
F_72 ( & V_209 ) ;
return 0 ;
}
static void F_390 ( struct V_1 * V_2 ,
struct V_402 * V_395 )
{
struct V_400 * V_401 , * V_312 ;
F_71 ( & V_209 ) ;
F_282 (ev, tmp, &memcg->oom_notify, list) {
if ( V_401 -> V_395 == V_395 ) {
F_275 ( & V_401 -> V_307 ) ;
F_285 ( V_401 ) ;
}
}
F_72 ( & V_209 ) ;
}
static int F_391 ( struct V_291 * V_411 , void * V_293 )
{
struct V_1 * V_2 = F_11 ( F_257 ( V_411 ) ) ;
F_368 ( V_411 , L_30 , V_2 -> V_234 ) ;
F_368 ( V_411 , L_31 , ( bool ) F_102 ( & V_2 -> V_213 ) ) ;
return 0 ;
}
static int F_392 ( struct V_10 * V_12 ,
struct V_355 * V_356 , T_2 V_66 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
if ( ! V_12 -> V_49 || ! ( ( V_66 == 0 ) || ( V_66 == 1 ) ) )
return - V_323 ;
V_2 -> V_234 = V_66 ;
if ( ! V_66 )
F_192 ( V_2 ) ;
return 0 ;
}
static int F_393 ( struct V_1 * V_2 , struct V_412 * V_413 )
{
int V_141 ;
V_2 -> V_29 = - 1 ;
V_141 = F_354 ( V_2 ) ;
if ( V_141 )
return V_141 ;
return F_394 ( V_2 , V_413 ) ;
}
static void F_395 ( struct V_1 * V_2 )
{
F_396 ( V_2 ) ;
}
static void F_397 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_2 ) )
return;
F_21 ( & V_2 -> V_12 ) ;
F_5 ( V_2 ) ;
if ( F_36 ( & V_2 -> V_30 , V_31 ) != 0 )
return;
if ( F_7 ( V_2 ) )
F_29 ( & V_2 -> V_12 ) ;
}
static int F_393 ( struct V_1 * V_2 , struct V_412 * V_413 )
{
return 0 ;
}
static void F_395 ( struct V_1 * V_2 )
{
}
static void F_397 ( struct V_1 * V_2 )
{
}
static void F_398 ( struct V_244 * V_247 )
{
struct V_414 * V_409 =
F_12 ( V_247 , struct V_414 , remove ) ;
struct V_1 * V_2 = V_409 -> V_2 ;
F_399 ( V_409 -> V_415 , & V_409 -> V_161 ) ;
V_409 -> V_416 ( V_2 , V_409 -> V_395 ) ;
F_378 ( V_409 -> V_395 , 1 ) ;
F_400 ( V_409 -> V_395 ) ;
F_285 ( V_409 ) ;
F_29 ( & V_2 -> V_12 ) ;
}
static int F_401 ( T_4 * V_161 , unsigned V_214 ,
int V_215 , void * V_417 )
{
struct V_414 * V_409 =
F_12 ( V_161 , struct V_414 , V_161 ) ;
struct V_1 * V_2 = V_409 -> V_2 ;
unsigned long V_56 = ( unsigned long ) V_417 ;
if ( V_56 & V_418 ) {
F_71 ( & V_2 -> V_419 ) ;
if ( ! F_330 ( & V_409 -> V_307 ) ) {
F_402 ( & V_409 -> V_307 ) ;
F_288 ( & V_409 -> remove ) ;
}
F_72 ( & V_2 -> V_419 ) ;
}
return 0 ;
}
static void F_403 ( struct V_420 * V_420 ,
T_10 * V_415 , T_11 * V_421 )
{
struct V_414 * V_409 =
F_12 ( V_421 , struct V_414 , V_421 ) ;
V_409 -> V_415 = V_415 ;
F_404 ( V_415 , & V_409 -> V_161 ) ;
}
static T_7 F_405 ( struct V_350 * V_351 ,
char * V_352 , T_8 V_353 , T_9 V_354 )
{
struct V_10 * V_12 = F_341 ( V_351 ) ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_414 * V_409 ;
struct V_10 * V_422 ;
unsigned int V_423 , V_424 ;
struct V_425 V_426 ;
struct V_425 V_427 ;
const char * V_361 ;
char * V_428 ;
int V_141 ;
V_352 = F_356 ( V_352 ) ;
V_423 = F_406 ( V_352 , & V_428 , 10 ) ;
if ( * V_428 != ' ' )
return - V_323 ;
V_352 = V_428 + 1 ;
V_424 = F_406 ( V_352 , & V_428 , 10 ) ;
if ( ( * V_428 != ' ' ) && ( * V_428 != '\0' ) )
return - V_323 ;
V_352 = V_428 + 1 ;
V_409 = F_407 ( sizeof( * V_409 ) , V_301 ) ;
if ( ! V_409 )
return - V_277 ;
V_409 -> V_2 = V_2 ;
F_195 ( & V_409 -> V_307 ) ;
F_408 ( & V_409 -> V_421 , F_403 ) ;
F_409 ( & V_409 -> V_161 , F_401 ) ;
F_212 ( & V_409 -> remove , F_398 ) ;
V_426 = F_410 ( V_423 ) ;
if ( ! V_426 . V_420 ) {
V_141 = - V_429 ;
goto V_430;
}
V_409 -> V_395 = F_411 ( V_426 . V_420 ) ;
if ( F_412 ( V_409 -> V_395 ) ) {
V_141 = F_413 ( V_409 -> V_395 ) ;
goto V_431;
}
V_427 = F_410 ( V_424 ) ;
if ( ! V_427 . V_420 ) {
V_141 = - V_429 ;
goto V_432;
}
V_141 = F_414 ( F_415 ( V_427 . V_420 ) , V_433 ) ;
if ( V_141 < 0 )
goto V_434;
V_361 = V_427 . V_420 -> V_435 -> V_436 . V_361 ;
if ( ! strcmp ( V_361 , L_32 ) ) {
V_409 -> V_437 = F_384 ;
V_409 -> V_416 = F_387 ;
} else if ( ! strcmp ( V_361 , L_33 ) ) {
V_409 -> V_437 = F_389 ;
V_409 -> V_416 = F_390 ;
} else if ( ! strcmp ( V_361 , L_34 ) ) {
V_409 -> V_437 = V_438 ;
V_409 -> V_416 = V_439 ;
} else if ( ! strcmp ( V_361 , L_35 ) ) {
V_409 -> V_437 = F_385 ;
V_409 -> V_416 = F_388 ;
} else {
V_141 = - V_323 ;
goto V_434;
}
V_422 = F_416 ( V_427 . V_420 -> V_435 -> V_440 ,
& V_17 ) ;
V_141 = - V_323 ;
if ( F_412 ( V_422 ) )
goto V_434;
if ( V_422 != V_12 ) {
F_29 ( V_422 ) ;
goto V_434;
}
V_141 = V_409 -> V_437 ( V_2 , V_409 -> V_395 , V_352 ) ;
if ( V_141 )
goto V_441;
V_426 . V_420 -> V_442 -> V_443 ( V_426 . V_420 , & V_409 -> V_421 ) ;
F_71 ( & V_2 -> V_419 ) ;
F_273 ( & V_409 -> V_307 , & V_2 -> V_444 ) ;
F_72 ( & V_2 -> V_419 ) ;
F_417 ( V_427 ) ;
F_417 ( V_426 ) ;
return V_353 ;
V_441:
F_29 ( V_12 ) ;
V_434:
F_417 ( V_427 ) ;
V_432:
F_400 ( V_409 -> V_395 ) ;
V_431:
F_417 ( V_426 ) ;
V_430:
F_285 ( V_409 ) ;
return V_141 ;
}
static int F_418 ( struct V_1 * V_2 , int V_200 )
{
struct V_445 * V_446 ;
struct V_32 * V_43 ;
int V_33 , V_312 = V_200 ;
if ( ! F_419 ( V_200 , V_447 ) )
V_312 = - 1 ;
V_446 = F_420 ( sizeof( * V_446 ) , V_301 , V_312 ) ;
if ( ! V_446 )
return 1 ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
V_43 = & V_446 -> V_37 [ V_33 ] ;
F_421 ( & V_43 -> V_81 ) ;
V_43 -> V_52 = 0 ;
V_43 -> V_51 = false ;
V_43 -> V_2 = V_2 ;
}
V_2 -> V_36 [ V_200 ] = V_446 ;
return 0 ;
}
static void F_422 ( struct V_1 * V_2 , int V_200 )
{
F_285 ( V_2 -> V_36 [ V_200 ] ) ;
}
static struct V_1 * F_423 ( void )
{
struct V_1 * V_2 ;
T_8 V_267 ;
V_267 = sizeof( struct V_1 ) ;
V_267 += V_87 * sizeof( struct V_445 * ) ;
V_2 = F_407 ( V_267 , V_301 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_68 = F_424 ( struct V_448 ) ;
if ( ! V_2 -> V_68 )
goto V_449;
F_425 ( & V_2 -> V_70 ) ;
return V_2 ;
V_449:
F_285 ( V_2 ) ;
return NULL ;
}
static void F_426 ( struct V_1 * V_2 )
{
int V_200 ;
F_59 ( V_2 ) ;
F_60 (node)
F_422 ( V_2 , V_200 ) ;
F_427 ( V_2 -> V_68 ) ;
F_37 ( V_2 ) ;
F_285 ( V_2 ) ;
}
struct V_1 * F_57 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 . V_49 )
return NULL ;
return F_229 ( V_2 -> V_59 . V_49 , V_59 ) ;
}
static void T_5 F_428 ( void )
{
struct V_450 * V_451 ;
struct V_39 * V_452 ;
int V_312 , V_200 , V_33 ;
F_60 (node) {
V_312 = V_200 ;
if ( ! F_419 ( V_200 , V_447 ) )
V_312 = - 1 ;
V_451 = F_420 ( sizeof( * V_451 ) , V_301 , V_312 ) ;
F_20 ( ! V_451 ) ;
V_40 . V_41 [ V_200 ] = V_451 ;
for ( V_33 = 0 ; V_33 < V_60 ; V_33 ++ ) {
V_452 = & V_451 -> V_42 [ V_33 ] ;
V_452 -> V_48 = V_453 ;
F_425 ( & V_452 -> V_57 ) ;
}
}
}
static struct V_10 * T_12
F_429 ( struct V_10 * V_454 )
{
struct V_1 * V_2 ;
long error = - V_277 ;
int V_200 ;
V_2 = F_423 () ;
if ( ! V_2 )
return F_430 ( error ) ;
F_60 (node)
if ( F_418 ( V_2 , V_200 ) )
goto V_455;
if ( V_454 == NULL ) {
V_14 = V_2 ;
F_431 ( & V_2 -> V_59 , NULL ) ;
F_431 ( & V_2 -> V_153 , NULL ) ;
F_431 ( & V_2 -> V_30 , NULL ) ;
}
V_2 -> V_201 = V_100 ;
F_195 ( & V_2 -> V_410 ) ;
V_2 -> V_374 = 0 ;
F_432 ( & V_2 -> V_405 ) ;
F_425 ( & V_2 -> V_164 ) ;
F_433 ( & V_2 -> V_13 ) ;
F_195 ( & V_2 -> V_444 ) ;
F_425 ( & V_2 -> V_419 ) ;
return & V_2 -> V_12 ;
V_455:
F_426 ( V_2 ) ;
return F_430 ( error ) ;
}
static int
F_434 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_1 * V_49 = F_11 ( V_12 -> V_49 ) ;
int V_141 ;
if ( V_12 -> V_16 > V_456 )
return - V_457 ;
if ( ! V_49 )
return 0 ;
F_143 ( & V_346 ) ;
V_2 -> V_123 = V_49 -> V_123 ;
V_2 -> V_234 = V_49 -> V_234 ;
V_2 -> V_155 = F_128 ( V_49 ) ;
if ( V_49 -> V_123 ) {
F_431 ( & V_2 -> V_59 , & V_49 -> V_59 ) ;
F_431 ( & V_2 -> V_153 , & V_49 -> V_153 ) ;
F_431 ( & V_2 -> V_30 , & V_49 -> V_30 ) ;
} else {
F_431 ( & V_2 -> V_59 , NULL ) ;
F_431 ( & V_2 -> V_153 , NULL ) ;
F_431 ( & V_2 -> V_30 , NULL ) ;
if ( V_49 != V_14 )
V_17 . V_458 = true ;
}
F_150 ( & V_346 ) ;
V_141 = F_393 ( V_2 , & V_17 ) ;
if ( V_141 )
return V_141 ;
F_435 ( & V_2 -> V_112 , 1 ) ;
return 0 ;
}
static void F_436 ( struct V_1 * V_2 )
{
struct V_1 * V_49 = V_2 ;
while ( ( V_49 = F_57 ( V_49 ) ) )
F_100 ( V_49 ) ;
if ( ! V_14 -> V_123 )
F_100 ( V_14 ) ;
}
static void F_437 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
struct V_414 * V_409 , * V_312 ;
struct V_10 * V_115 ;
F_71 ( & V_2 -> V_419 ) ;
F_282 (event, tmp, &memcg->event_list, list) {
F_402 ( & V_409 -> V_307 ) ;
F_288 ( & V_409 -> remove ) ;
}
F_72 ( & V_2 -> V_419 ) ;
F_397 ( V_2 ) ;
F_436 ( V_2 ) ;
F_438 (iter, css)
F_334 ( F_11 ( V_115 ) ) ;
F_281 ( V_2 ) ;
F_439 ( & V_2 -> V_13 ) ;
}
static void F_440 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_334 ( V_2 ) ;
F_395 ( V_2 ) ;
F_426 ( V_2 ) ;
}
static void F_441 ( struct V_10 * V_12 )
{
struct V_1 * V_2 = F_11 ( V_12 ) ;
F_323 ( V_2 , V_459 ) ;
F_326 ( V_2 , V_459 ) ;
F_353 ( V_2 , V_459 ) ;
F_359 ( & V_2 -> V_59 , V_459 ) ;
}
static int F_442 ( unsigned long V_69 )
{
int V_141 ;
V_141 = F_226 ( V_7 . V_158 , V_301 & ~ V_273 , V_69 ) ;
if ( ! V_141 ) {
V_7 . V_460 += V_69 ;
return V_141 ;
}
if ( V_141 == - V_278 ) {
F_234 ( V_14 , V_69 ) ;
return V_141 ;
}
while ( V_69 -- ) {
V_141 = F_226 ( V_7 . V_158 , V_301 & ~ V_274 , 1 ) ;
if ( V_141 == - V_278 )
F_234 ( V_14 , 1 ) ;
if ( V_141 )
return V_141 ;
V_7 . V_460 ++ ;
F_333 () ;
}
return 0 ;
}
static struct V_38 * F_443 ( struct V_461 * V_462 ,
unsigned long V_463 , T_13 V_464 )
{
struct V_38 * V_38 = F_444 ( V_462 , V_463 , V_464 ) ;
if ( ! V_38 || ! F_303 ( V_38 ) )
return NULL ;
if ( F_76 ( V_38 ) ) {
if ( ! F_9 () )
return NULL ;
} else if ( ! F_10 () )
return NULL ;
if ( ! F_309 ( V_38 ) )
return NULL ;
return V_38 ;
}
static struct V_38 * F_445 ( struct V_461 * V_462 ,
unsigned long V_463 , T_13 V_464 , T_6 * V_329 )
{
struct V_38 * V_38 = NULL ;
T_6 V_279 = F_446 ( V_464 ) ;
if ( ! F_9 () || F_447 ( V_279 ) )
return NULL ;
V_38 = F_448 ( F_449 ( V_279 ) , V_279 . V_66 ) ;
if ( V_152 )
V_329 -> V_66 = V_279 . V_66 ;
return V_38 ;
}
static struct V_38 * F_445 ( struct V_461 * V_462 ,
unsigned long V_463 , T_13 V_464 , T_6 * V_329 )
{
return NULL ;
}
static struct V_38 * F_450 ( struct V_461 * V_462 ,
unsigned long V_463 , T_13 V_464 , T_6 * V_329 )
{
struct V_38 * V_38 = NULL ;
struct V_465 * V_466 ;
T_14 V_467 ;
if ( ! V_462 -> V_468 )
return NULL ;
if ( ! F_10 () )
return NULL ;
V_466 = V_462 -> V_468 -> V_469 ;
if ( F_451 ( V_464 ) )
V_467 = F_452 ( V_462 , V_463 ) ;
else
V_467 = F_453 ( V_464 ) ;
#ifdef F_454
if ( F_455 ( V_466 ) ) {
V_38 = F_456 ( V_466 , V_467 ) ;
if ( F_457 ( V_38 ) ) {
T_6 V_470 = F_458 ( V_38 ) ;
if ( V_152 )
* V_329 = V_470 ;
V_38 = F_448 ( F_449 ( V_470 ) , V_470 . V_66 ) ;
}
} else
V_38 = F_448 ( V_466 , V_467 ) ;
#else
V_38 = F_448 ( V_466 , V_467 ) ;
#endif
return V_38 ;
}
static enum V_471 F_459 ( struct V_461 * V_462 ,
unsigned long V_463 , T_13 V_464 , union V_472 * V_89 )
{
struct V_38 * V_38 = NULL ;
struct V_137 * V_138 ;
enum V_471 V_141 = V_473 ;
T_6 V_279 = { . V_66 = 0 } ;
if ( F_460 ( V_464 ) )
V_38 = F_443 ( V_462 , V_463 , V_464 ) ;
else if ( F_461 ( V_464 ) )
V_38 = F_445 ( V_462 , V_463 , V_464 , & V_279 ) ;
else if ( F_451 ( V_464 ) || F_462 ( V_464 ) )
V_38 = F_450 ( V_462 , V_463 , V_464 , & V_279 ) ;
if ( ! V_38 && ! V_279 . V_66 )
return V_141 ;
if ( V_38 ) {
V_138 = F_113 ( V_38 ) ;
if ( F_115 ( V_138 ) && V_138 -> V_1 == V_7 . V_157 ) {
V_141 = V_474 ;
if ( V_89 )
V_89 -> V_38 = V_38 ;
}
if ( ! V_141 || ! V_89 )
F_315 ( V_38 ) ;
}
if ( V_279 . V_66 && ! V_141 &&
F_16 ( V_7 . V_157 ) == F_243 ( V_279 ) ) {
V_141 = V_475 ;
if ( V_89 )
V_89 -> V_279 = V_279 ;
}
return V_141 ;
}
static enum V_471 F_463 ( struct V_461 * V_462 ,
unsigned long V_463 , T_15 V_476 , union V_472 * V_89 )
{
struct V_38 * V_38 = NULL ;
struct V_137 * V_138 ;
enum V_471 V_141 = V_473 ;
V_38 = F_464 ( V_476 ) ;
F_239 ( ! V_38 || ! F_465 ( V_38 ) , V_38 ) ;
if ( ! F_9 () )
return V_141 ;
V_138 = F_113 ( V_38 ) ;
if ( F_115 ( V_138 ) && V_138 -> V_1 == V_7 . V_157 ) {
V_141 = V_474 ;
if ( V_89 ) {
F_466 ( V_38 ) ;
V_89 -> V_38 = V_38 ;
}
}
return V_141 ;
}
static inline enum V_471 F_463 ( struct V_461 * V_462 ,
unsigned long V_463 , T_15 V_476 , union V_472 * V_89 )
{
return V_473 ;
}
static int F_467 ( T_15 * V_476 ,
unsigned long V_463 , unsigned long V_477 ,
struct V_478 * V_479 )
{
struct V_461 * V_462 = V_479 -> V_231 ;
T_13 * V_480 ;
T_16 * V_481 ;
if ( F_468 ( V_476 , V_462 , & V_481 ) == 1 ) {
if ( F_463 ( V_462 , V_463 , * V_476 , NULL ) == V_474 )
V_7 . V_460 += V_321 ;
F_72 ( V_481 ) ;
return 0 ;
}
if ( F_469 ( V_476 ) )
return 0 ;
V_480 = F_470 ( V_462 -> V_482 , V_476 , V_463 , & V_481 ) ;
for (; V_463 != V_477 ; V_480 ++ , V_463 += V_243 )
if ( F_459 ( V_462 , V_463 , * V_480 , NULL ) )
V_7 . V_460 ++ ;
F_471 ( V_480 - 1 , V_481 ) ;
F_333 () ;
return 0 ;
}
static unsigned long F_472 ( struct V_104 * V_105 )
{
unsigned long V_460 ;
struct V_461 * V_462 ;
F_473 ( & V_105 -> V_483 ) ;
for ( V_462 = V_105 -> V_484 ; V_462 ; V_462 = V_462 -> V_485 ) {
struct V_478 V_486 = {
. V_487 = F_467 ,
. V_105 = V_105 ,
. V_231 = V_462 ,
} ;
if ( F_474 ( V_462 ) )
continue;
F_475 ( V_462 -> V_488 , V_462 -> V_489 ,
& V_486 ) ;
}
F_476 ( & V_105 -> V_483 ) ;
V_460 = V_7 . V_460 ;
V_7 . V_460 = 0 ;
return V_460 ;
}
static int F_477 ( struct V_104 * V_105 )
{
unsigned long V_460 = F_472 ( V_105 ) ;
F_82 ( V_7 . V_160 ) ;
V_7 . V_160 = V_25 ;
return F_442 ( V_460 ) ;
}
static void F_478 ( void )
{
struct V_1 * V_157 = V_7 . V_157 ;
struct V_1 * V_158 = V_7 . V_158 ;
int V_166 ;
if ( V_7 . V_460 ) {
F_234 ( V_7 . V_158 , V_7 . V_460 ) ;
V_7 . V_460 = 0 ;
}
if ( V_7 . V_490 ) {
F_234 ( V_7 . V_157 , V_7 . V_490 ) ;
V_7 . V_490 = 0 ;
}
if ( V_7 . V_491 ) {
if ( ! F_15 ( V_7 . V_157 ) )
F_206 ( & V_7 . V_157 -> V_153 ,
V_243 * V_7 . V_491 ) ;
for ( V_166 = 0 ; V_166 < V_7 . V_491 ; V_166 ++ )
F_29 ( & V_7 . V_157 -> V_12 ) ;
if ( ! F_15 ( V_7 . V_158 ) )
F_206 ( & V_7 . V_158 -> V_59 ,
V_243 * V_7 . V_491 ) ;
V_7 . V_491 = 0 ;
}
F_192 ( V_157 ) ;
F_192 ( V_158 ) ;
F_479 ( & V_7 . V_162 ) ;
}
static void F_480 ( void )
{
struct V_1 * V_157 = V_7 . V_157 ;
V_7 . V_160 = NULL ;
F_478 () ;
F_71 ( & V_7 . V_57 ) ;
V_7 . V_157 = NULL ;
V_7 . V_158 = NULL ;
F_72 ( & V_7 . V_57 ) ;
F_131 ( V_157 ) ;
}
static int F_481 ( struct V_10 * V_12 ,
struct V_492 * V_493 )
{
struct V_102 * V_47 = F_482 ( V_493 ) ;
int V_141 = 0 ;
struct V_1 * V_2 = F_11 ( V_12 ) ;
unsigned long V_374 ;
V_374 = V_2 -> V_374 ;
if ( V_374 ) {
struct V_104 * V_105 ;
struct V_1 * V_157 = F_23 ( V_47 ) ;
F_82 ( V_157 == V_2 ) ;
V_105 = F_483 ( V_47 ) ;
if ( ! V_105 )
return 0 ;
if ( V_105 -> V_106 == V_47 ) {
F_82 ( V_7 . V_157 ) ;
F_82 ( V_7 . V_158 ) ;
F_82 ( V_7 . V_460 ) ;
F_82 ( V_7 . V_490 ) ;
F_82 ( V_7 . V_491 ) ;
F_129 ( V_157 ) ;
F_71 ( & V_7 . V_57 ) ;
V_7 . V_157 = V_157 ;
V_7 . V_158 = V_2 ;
V_7 . V_8 = V_374 ;
F_72 ( & V_7 . V_57 ) ;
V_141 = F_477 ( V_105 ) ;
if ( V_141 )
F_480 () ;
}
F_484 ( V_105 ) ;
}
return V_141 ;
}
static void F_485 ( struct V_10 * V_12 ,
struct V_492 * V_493 )
{
F_480 () ;
}
static int F_486 ( T_15 * V_476 ,
unsigned long V_463 , unsigned long V_477 ,
struct V_478 * V_479 )
{
int V_141 = 0 ;
struct V_461 * V_462 = V_479 -> V_231 ;
T_13 * V_480 ;
T_16 * V_481 ;
enum V_471 V_494 ;
union V_472 V_89 ;
struct V_38 * V_38 ;
struct V_137 * V_138 ;
if ( F_468 ( V_476 , V_462 , & V_481 ) == 1 ) {
if ( V_7 . V_460 < V_321 ) {
F_72 ( V_481 ) ;
return 0 ;
}
V_494 = F_463 ( V_462 , V_463 , * V_476 , & V_89 ) ;
if ( V_494 == V_474 ) {
V_38 = V_89 . V_38 ;
if ( ! F_310 ( V_38 ) ) {
V_138 = F_113 ( V_38 ) ;
if ( ! F_301 ( V_38 , V_321 ,
V_138 , V_7 . V_157 , V_7 . V_158 ) ) {
V_7 . V_460 -= V_321 ;
V_7 . V_490 += V_321 ;
}
F_314 ( V_38 ) ;
}
F_315 ( V_38 ) ;
}
F_72 ( V_481 ) ;
return 0 ;
}
if ( F_469 ( V_476 ) )
return 0 ;
V_62:
V_480 = F_470 ( V_462 -> V_482 , V_476 , V_463 , & V_481 ) ;
for (; V_463 != V_477 ; V_463 += V_243 ) {
T_13 V_464 = * ( V_480 ++ ) ;
T_6 V_279 ;
if ( ! V_7 . V_460 )
break;
switch ( F_459 ( V_462 , V_463 , V_464 , & V_89 ) ) {
case V_474 :
V_38 = V_89 . V_38 ;
if ( F_310 ( V_38 ) )
goto V_327;
V_138 = F_113 ( V_38 ) ;
if ( ! F_301 ( V_38 , 1 , V_138 ,
V_7 . V_157 , V_7 . V_158 ) ) {
V_7 . V_460 -- ;
V_7 . V_490 ++ ;
}
F_314 ( V_38 ) ;
V_327:
F_315 ( V_38 ) ;
break;
case V_475 :
V_279 = V_89 . V_279 ;
if ( ! F_317 ( V_279 , V_7 . V_157 , V_7 . V_158 ) ) {
V_7 . V_460 -- ;
V_7 . V_491 ++ ;
}
break;
default:
break;
}
}
F_471 ( V_480 - 1 , V_481 ) ;
F_333 () ;
if ( V_463 != V_477 ) {
V_141 = F_442 ( 1 ) ;
if ( ! V_141 )
goto V_62;
}
return V_141 ;
}
static void F_487 ( struct V_104 * V_105 )
{
struct V_461 * V_462 ;
F_335 () ;
V_62:
if ( F_91 ( ! F_488 ( & V_105 -> V_483 ) ) ) {
F_478 () ;
F_333 () ;
goto V_62;
}
for ( V_462 = V_105 -> V_484 ; V_462 ; V_462 = V_462 -> V_485 ) {
int V_141 ;
struct V_478 V_495 = {
. V_487 = F_486 ,
. V_105 = V_105 ,
. V_231 = V_462 ,
} ;
if ( F_474 ( V_462 ) )
continue;
V_141 = F_475 ( V_462 -> V_488 , V_462 -> V_489 ,
& V_495 ) ;
if ( V_141 )
break;
}
F_476 ( & V_105 -> V_483 ) ;
}
static void F_489 ( struct V_10 * V_12 ,
struct V_492 * V_493 )
{
struct V_102 * V_47 = F_482 ( V_493 ) ;
struct V_104 * V_105 = F_483 ( V_47 ) ;
if ( V_105 ) {
if ( V_7 . V_158 )
F_487 ( V_105 ) ;
F_484 ( V_105 ) ;
}
if ( V_7 . V_158 )
F_480 () ;
}
static int F_481 ( struct V_10 * V_12 ,
struct V_492 * V_493 )
{
return 0 ;
}
static void F_485 ( struct V_10 * V_12 ,
struct V_492 * V_493 )
{
}
static void F_489 ( struct V_10 * V_12 ,
struct V_492 * V_493 )
{
}
static void F_490 ( struct V_10 * V_496 )
{
if ( F_491 ( V_496 -> V_140 ) )
F_11 ( V_496 ) -> V_123 = true ;
}
static int T_5 F_492 ( char * V_11 )
{
if ( ! strcmp ( V_11 , L_36 ) )
V_497 = 1 ;
else if ( ! strcmp ( V_11 , L_37 ) )
V_497 = 0 ;
return 1 ;
}
static void T_5 F_493 ( void )
{
F_28 ( F_494 ( & V_17 ,
V_498 ) ) ;
}
static void T_5 F_495 ( void )
{
if ( ! F_106 () && V_497 ) {
V_152 = 1 ;
F_493 () ;
}
}
static void T_5 F_495 ( void )
{
}
void F_496 ( struct V_38 * V_38 , T_6 V_329 )
{
struct V_137 * V_138 ;
unsigned short V_499 ;
F_239 ( F_114 ( V_38 ) , V_38 ) ;
F_239 ( F_497 ( V_38 ) , V_38 ) ;
if ( ! V_152 )
return;
V_138 = F_113 ( V_38 ) ;
if ( ! F_115 ( V_138 ) )
return;
F_239 ( ! ( V_138 -> V_56 & V_285 ) , V_38 ) ;
V_499 = F_498 ( V_329 , F_16 ( V_138 -> V_1 ) ) ;
F_239 ( V_499 , V_38 ) ;
V_138 -> V_56 &= ~ V_285 ;
F_21 ( & V_138 -> V_1 -> V_12 ) ;
F_316 ( V_138 -> V_1 , true ) ;
}
void F_499 ( T_6 V_329 )
{
struct V_1 * V_2 ;
unsigned short V_16 ;
if ( ! V_152 )
return;
V_16 = F_498 ( V_329 , 0 ) ;
F_22 () ;
V_2 = F_237 ( V_16 ) ;
if ( V_2 ) {
if ( ! F_15 ( V_2 ) )
F_206 ( & V_2 -> V_153 , V_243 ) ;
F_316 ( V_2 , false ) ;
F_29 ( & V_2 -> V_12 ) ;
}
F_26 () ;
}
int F_500 ( struct V_38 * V_38 , struct V_104 * V_105 ,
T_3 V_177 , struct V_1 * * V_500 )
{
struct V_1 * V_2 = NULL ;
unsigned int V_74 = 1 ;
int V_141 = 0 ;
if ( F_106 () )
goto V_132;
if ( F_241 ( V_38 ) ) {
struct V_137 * V_138 = F_113 ( V_38 ) ;
if ( F_115 ( V_138 ) )
goto V_132;
}
if ( F_78 ( V_38 ) ) {
V_74 <<= F_501 ( V_38 ) ;
F_239 ( ! F_78 ( V_38 ) , V_38 ) ;
}
if ( V_152 && F_241 ( V_38 ) )
V_2 = F_238 ( V_38 ) ;
if ( ! V_2 )
V_2 = F_95 ( V_105 ) ;
V_141 = F_226 ( V_2 , V_177 , V_74 ) ;
F_29 ( & V_2 -> V_12 ) ;
if ( V_141 == - V_278 ) {
V_2 = V_14 ;
V_141 = 0 ;
}
V_132:
* V_500 = V_2 ;
return V_141 ;
}
void F_502 ( struct V_38 * V_38 , struct V_1 * V_2 ,
bool V_282 )
{
unsigned int V_74 = 1 ;
F_239 ( ! V_38 -> V_466 , V_38 ) ;
F_239 ( F_114 ( V_38 ) && ! V_282 , V_38 ) ;
if ( F_106 () )
return;
if ( ! V_2 )
return;
F_252 ( V_38 , V_2 , V_282 ) ;
if ( F_78 ( V_38 ) ) {
V_74 <<= F_501 ( V_38 ) ;
F_239 ( ! F_78 ( V_38 ) , V_38 ) ;
}
F_305 () ;
F_75 ( V_2 , V_38 , V_74 ) ;
F_90 ( V_2 , V_38 ) ;
F_306 () ;
if ( V_152 && F_241 ( V_38 ) ) {
T_6 V_329 = { . V_66 = F_242 (page) } ;
F_499 ( V_329 ) ;
}
}
void F_503 ( struct V_38 * V_38 , struct V_1 * V_2 )
{
unsigned int V_74 = 1 ;
if ( F_106 () )
return;
if ( ! V_2 )
return;
if ( F_78 ( V_38 ) ) {
V_74 <<= F_501 ( V_38 ) ;
F_239 ( ! F_78 ( V_38 ) , V_38 ) ;
}
F_234 ( V_2 , V_74 ) ;
}
static void F_504 ( struct V_1 * V_2 , unsigned long V_501 ,
unsigned long V_502 , unsigned long V_503 ,
unsigned long V_504 , unsigned long V_505 ,
unsigned long V_506 , struct V_38 * V_507 )
{
unsigned long V_56 ;
if ( ! F_15 ( V_2 ) ) {
if ( V_502 )
F_206 ( & V_2 -> V_59 ,
V_502 * V_243 ) ;
if ( V_503 )
F_206 ( & V_2 -> V_153 ,
V_503 * V_243 ) ;
F_192 ( V_2 ) ;
}
F_505 ( V_56 ) ;
F_300 ( V_2 -> V_68 -> V_69 [ V_75 ] , V_504 ) ;
F_300 ( V_2 -> V_68 -> V_69 [ V_76 ] , V_505 ) ;
F_300 ( V_2 -> V_68 -> V_69 [ V_77 ] , V_506 ) ;
F_77 ( V_2 -> V_68 -> V_73 [ V_79 ] , V_501 ) ;
F_77 ( V_2 -> V_68 -> V_80 , V_504 + V_505 ) ;
F_90 ( V_2 , V_507 ) ;
F_506 ( V_56 ) ;
}
static void F_507 ( struct V_341 * V_508 )
{
struct V_1 * V_2 = NULL ;
unsigned long V_503 = 0 ;
unsigned long V_504 = 0 ;
unsigned long V_505 = 0 ;
unsigned long V_506 = 0 ;
unsigned long V_501 = 0 ;
unsigned long V_502 = 0 ;
struct V_341 * V_90 ;
struct V_38 * V_38 ;
V_90 = V_508 -> V_90 ;
do {
unsigned int V_74 = 1 ;
struct V_137 * V_138 ;
V_38 = F_331 ( V_90 , struct V_38 , V_83 ) ;
V_90 = V_38 -> V_83 . V_90 ;
F_239 ( F_114 ( V_38 ) , V_38 ) ;
F_239 ( F_497 ( V_38 ) , V_38 ) ;
V_138 = F_113 ( V_38 ) ;
if ( ! F_115 ( V_138 ) )
continue;
if ( V_2 != V_138 -> V_1 ) {
if ( V_2 ) {
F_504 ( V_2 , V_501 , V_502 , V_503 ,
V_504 , V_505 , V_506 , V_38 ) ;
V_501 = V_502 = V_503 = 0 ;
V_504 = V_505 = V_506 = 0 ;
}
V_2 = V_138 -> V_1 ;
}
if ( F_78 ( V_38 ) ) {
V_74 <<= F_501 ( V_38 ) ;
F_239 ( ! F_78 ( V_38 ) , V_38 ) ;
V_506 += V_74 ;
}
if ( F_76 ( V_38 ) )
V_504 += V_74 ;
else
V_505 += V_74 ;
if ( V_138 -> V_56 & V_284 )
V_502 += V_74 ;
if ( V_138 -> V_56 & V_285 )
V_503 += V_74 ;
V_138 -> V_56 = 0 ;
V_501 ++ ;
} while ( V_90 != V_508 );
if ( V_2 )
F_504 ( V_2 , V_501 , V_502 , V_503 ,
V_504 , V_505 , V_506 , V_38 ) ;
}
void F_508 ( struct V_38 * V_38 )
{
struct V_137 * V_138 ;
if ( F_106 () )
return;
V_138 = F_113 ( V_38 ) ;
if ( ! F_115 ( V_138 ) )
return;
F_195 ( & V_38 -> V_83 ) ;
F_507 ( & V_38 -> V_83 ) ;
}
void F_509 ( struct V_341 * V_508 )
{
if ( F_106 () )
return;
if ( ! F_330 ( V_508 ) )
F_507 ( V_508 ) ;
}
void F_510 ( struct V_38 * V_509 , struct V_38 * V_510 ,
bool V_282 )
{
struct V_137 * V_138 ;
int V_280 ;
F_239 ( ! F_240 ( V_509 ) , V_509 ) ;
F_239 ( ! F_240 ( V_510 ) , V_510 ) ;
F_239 ( ! V_282 && F_114 ( V_509 ) , V_509 ) ;
F_239 ( ! V_282 && F_114 ( V_510 ) , V_510 ) ;
F_239 ( F_76 ( V_509 ) != F_76 ( V_510 ) , V_510 ) ;
F_239 ( F_78 ( V_509 ) != F_78 ( V_510 ) ,
V_510 ) ;
if ( F_106 () )
return;
V_138 = F_113 ( V_510 ) ;
if ( F_115 ( V_138 ) )
return;
V_138 = F_113 ( V_509 ) ;
if ( ! F_115 ( V_138 ) )
return;
F_239 ( ! ( V_138 -> V_56 & V_284 ) , V_509 ) ;
F_239 ( V_152 && ! ( V_138 -> V_56 & V_285 ) , V_509 ) ;
if ( V_282 )
F_244 ( V_509 , & V_280 ) ;
V_138 -> V_56 = 0 ;
if ( V_282 )
F_249 ( V_509 , V_280 ) ;
F_252 ( V_510 , V_138 -> V_1 , V_282 ) ;
}
static int T_5 F_511 ( void )
{
F_512 ( F_224 , 0 ) ;
F_495 () ;
F_428 () ;
F_210 () ;
return 0 ;
}
