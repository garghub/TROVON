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
struct V_16 * F_16 ( struct V_1 * V_4 )
{
if ( ! V_4 )
V_4 = V_17 ;
return & V_4 -> V_16 ;
}
struct V_13 * F_17 ( struct V_16 * V_18 )
{
return & F_15 ( V_18 , struct V_1 , V_16 ) -> V_15 ;
}
struct V_16 * F_18 ( struct V_13 * V_15 )
{
return & F_14 ( V_15 ) -> V_16 ;
}
static inline bool F_19 ( struct V_1 * V_4 )
{
return ( V_4 == V_17 ) ;
}
void F_20 ( struct V_19 * V_20 )
{
if ( V_21 ) {
struct V_1 * V_4 ;
struct V_22 * V_22 ;
F_21 ( ! V_20 -> V_23 -> V_24 ) ;
if ( V_20 -> V_25 ) {
F_21 ( F_19 ( V_20 -> V_25 -> V_4 ) ) ;
F_22 ( V_20 -> V_25 -> V_4 ) ;
return;
}
F_23 () ;
V_4 = F_24 ( V_26 ) ;
V_22 = V_20 -> V_23 -> V_24 ( V_4 ) ;
if ( ! F_19 ( V_4 ) && F_25 ( V_22 ) ) {
F_22 ( V_4 ) ;
V_20 -> V_25 = V_22 ;
}
F_26 () ;
}
}
void F_27 ( struct V_19 * V_20 )
{
if ( V_21 && V_20 -> V_25 ) {
struct V_1 * V_4 ;
F_28 ( ! V_20 -> V_25 -> V_4 ) ;
V_4 = V_20 -> V_25 -> V_4 ;
F_29 ( V_4 ) ;
}
}
struct V_22 * F_30 ( struct V_1 * V_4 )
{
if ( ! V_4 || F_19 ( V_4 ) )
return NULL ;
return & V_4 -> V_27 . V_22 ;
}
static void F_31 ( struct V_1 * V_4 )
{
if ( ! F_32 ( & V_4 -> V_27 . V_22 ) )
return;
F_33 ( & V_28 ) ;
}
static void F_31 ( struct V_1 * V_4 )
{
}
static void F_34 ( struct V_1 * V_4 )
{
if ( F_4 ( V_4 ) ) {
F_33 ( & V_29 ) ;
F_35 ( & V_30 , V_4 -> V_31 ) ;
}
F_28 ( F_36 ( & V_4 -> V_32 , V_33 ) != 0 ) ;
}
static void F_34 ( struct V_1 * V_4 )
{
}
static void F_37 ( struct V_1 * V_4 )
{
F_31 ( V_4 ) ;
F_34 ( V_4 ) ;
}
static struct V_34 *
F_38 ( struct V_1 * V_4 , int V_35 , int V_36 )
{
F_39 ( ( unsigned ) V_35 >= V_2 ) ;
return & V_4 -> V_37 . V_38 [ V_35 ] -> V_39 [ V_36 ] ;
}
struct V_13 * F_40 ( struct V_1 * V_4 )
{
return & V_4 -> V_15 ;
}
static struct V_34 *
F_41 ( struct V_1 * V_4 , struct V_40 * V_40 )
{
int V_35 = F_42 ( V_40 ) ;
int V_36 = F_43 ( V_40 ) ;
return F_38 ( V_4 , V_35 , V_36 ) ;
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
F_46 ( struct V_1 * V_4 ,
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
F_50 ( struct V_1 * V_4 ,
struct V_34 * V_45 ,
struct V_41 * V_46 )
{
if ( ! V_45 -> V_53 )
return;
F_51 ( & V_45 -> V_55 , & V_46 -> V_50 ) ;
V_45 -> V_53 = false ;
}
static void
F_52 ( struct V_1 * V_4 ,
struct V_34 * V_45 ,
struct V_41 * V_46 )
{
F_53 ( & V_46 -> V_58 ) ;
F_50 ( V_4 , V_45 , V_46 ) ;
F_54 ( & V_46 -> V_58 ) ;
}
static void F_55 ( struct V_1 * V_4 , struct V_40 * V_40 )
{
unsigned long long V_59 ;
struct V_34 * V_45 ;
struct V_41 * V_46 ;
int V_35 = F_42 ( V_40 ) ;
int V_36 = F_43 ( V_40 ) ;
V_46 = F_45 ( V_40 ) ;
for (; V_4 ; V_4 = F_56 ( V_4 ) ) {
V_45 = F_38 ( V_4 , V_35 , V_36 ) ;
V_59 = F_57 ( & V_4 -> V_60 ) ;
if ( V_59 || V_45 -> V_53 ) {
F_53 ( & V_46 -> V_58 ) ;
if ( V_45 -> V_53 )
F_50 ( V_4 , V_45 , V_46 ) ;
F_46 ( V_4 , V_45 , V_46 , V_59 ) ;
F_54 ( & V_46 -> V_58 ) ;
}
}
}
static void F_58 ( struct V_1 * V_4 )
{
int V_61 , V_62 ;
struct V_34 * V_45 ;
struct V_41 * V_46 ;
F_59 (node) {
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_45 = F_38 ( V_4 , V_61 , V_62 ) ;
V_46 = F_44 ( V_61 , V_62 ) ;
F_52 ( V_4 , V_45 , V_46 ) ;
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
F_50 ( V_45 -> V_4 , V_45 , V_46 ) ;
if ( ! F_57 ( & V_45 -> V_4 -> V_60 ) ||
! F_62 ( & V_45 -> V_4 -> V_15 ) )
goto V_65;
V_66:
return V_45 ;
}
static struct V_34 *
F_63 ( struct V_41 * V_46 )
{
struct V_34 * V_45 ;
F_53 ( & V_46 -> V_58 ) ;
V_45 = F_60 ( V_46 ) ;
F_54 ( & V_46 -> V_58 ) ;
return V_45 ;
}
static long F_64 ( struct V_1 * V_4 ,
enum V_67 V_68 )
{
long V_69 = 0 ;
int V_70 ;
F_65 () ;
F_66 (cpu)
V_69 += F_67 ( V_4 -> V_71 -> V_72 [ V_68 ] , V_70 ) ;
#ifdef F_68
F_53 ( & V_4 -> V_73 ) ;
V_69 += V_4 -> V_74 . V_72 [ V_68 ] ;
F_54 ( & V_4 -> V_73 ) ;
#endif
F_69 () ;
return V_69 ;
}
static void F_70 ( struct V_1 * V_4 ,
bool V_75 )
{
int V_69 = ( V_75 ) ? 1 : - 1 ;
F_71 ( V_4 -> V_71 -> V_72 [ V_76 ] , V_69 ) ;
}
static unsigned long F_72 ( struct V_1 * V_4 ,
enum V_77 V_68 )
{
unsigned long V_69 = 0 ;
int V_70 ;
F_66 (cpu)
V_69 += F_67 ( V_4 -> V_71 -> V_78 [ V_68 ] , V_70 ) ;
#ifdef F_68
F_53 ( & V_4 -> V_73 ) ;
V_69 += V_4 -> V_74 . V_78 [ V_68 ] ;
F_54 ( & V_4 -> V_73 ) ;
#endif
return V_69 ;
}
static void F_73 ( struct V_1 * V_4 ,
struct V_40 * V_40 ,
bool V_79 , int V_80 )
{
F_74 () ;
if ( V_79 )
F_75 ( V_4 -> V_71 -> V_72 [ V_81 ] ,
V_80 ) ;
else
F_75 ( V_4 -> V_71 -> V_72 [ V_82 ] ,
V_80 ) ;
if ( F_76 ( V_40 ) )
F_75 ( V_4 -> V_71 -> V_72 [ V_83 ] ,
V_80 ) ;
if ( V_80 > 0 )
F_77 ( V_4 -> V_71 -> V_78 [ V_84 ] ) ;
else {
F_77 ( V_4 -> V_71 -> V_78 [ V_85 ] ) ;
V_80 = - V_80 ;
}
F_75 ( V_4 -> V_71 -> V_86 , V_80 ) ;
F_78 () ;
}
unsigned long
F_79 ( struct V_87 * V_87 , enum V_88 V_89 )
{
struct V_34 * V_45 ;
V_45 = F_15 ( V_87 , struct V_34 , V_87 ) ;
return V_45 -> V_90 [ V_89 ] ;
}
static unsigned long
F_80 ( struct V_1 * V_4 , int V_35 , int V_36 ,
unsigned int V_91 )
{
struct V_34 * V_45 ;
enum V_88 V_89 ;
unsigned long V_92 = 0 ;
V_45 = F_38 ( V_4 , V_35 , V_36 ) ;
F_81 (lru) {
if ( F_82 ( V_89 ) & V_91 )
V_92 += V_45 -> V_90 [ V_89 ] ;
}
return V_92 ;
}
static unsigned long
F_83 ( struct V_1 * V_4 ,
int V_35 , unsigned int V_91 )
{
T_2 V_93 = 0 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ )
V_93 += F_80 ( V_4 ,
V_35 , V_36 , V_91 ) ;
return V_93 ;
}
static unsigned long F_84 ( struct V_1 * V_4 ,
unsigned int V_91 )
{
int V_35 ;
T_2 V_93 = 0 ;
F_85 (nid, N_MEMORY)
V_93 += F_83 ( V_4 , V_35 , V_91 ) ;
return V_93 ;
}
static bool F_86 ( struct V_1 * V_4 ,
enum V_94 V_95 )
{
unsigned long V_69 , V_96 ;
V_69 = F_87 ( V_4 -> V_71 -> V_86 ) ;
V_96 = F_87 ( V_4 -> V_71 -> V_97 [ V_95 ] ) ;
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
F_88 ( V_4 -> V_71 -> V_97 [ V_95 ] , V_96 ) ;
return true ;
}
return false ;
}
static void F_89 ( struct V_1 * V_4 , struct V_40 * V_40 )
{
F_74 () ;
if ( F_90 ( F_86 ( V_4 ,
V_98 ) ) ) {
bool V_104 ;
bool T_3 V_105 ;
V_104 = F_86 ( V_4 ,
V_100 ) ;
#if V_106 > 1
T_3 = F_86 ( V_4 ,
V_102 ) ;
#endif
F_78 () ;
F_91 ( V_4 ) ;
if ( F_90 ( V_104 ) )
F_55 ( V_4 , V_40 ) ;
#if V_106 > 1
if ( F_90 ( T_3 ) )
F_92 ( & V_4 -> V_107 ) ;
#endif
} else
F_78 () ;
}
struct V_1 * F_93 ( struct V_108 * V_109 )
{
return F_14 (
V_13 ( V_109 , V_110 ) ) ;
}
struct V_1 * F_24 ( struct V_111 * V_49 )
{
if ( F_90 ( ! V_49 ) )
return NULL ;
return F_14 ( F_94 ( V_49 , V_110 ) ) ;
}
struct V_1 * F_95 ( struct V_112 * V_113 )
{
struct V_1 * V_4 = NULL ;
if ( ! V_113 )
return NULL ;
F_23 () ;
do {
V_4 = F_24 ( F_96 ( V_113 -> V_114 ) ) ;
if ( F_90 ( ! V_4 ) )
break;
} while ( ! F_62 ( & V_4 -> V_15 ) );
F_26 () ;
return V_4 ;
}
static struct V_1 * F_97 ( struct V_1 * V_115 ,
struct V_1 * V_116 )
{
struct V_108 * V_117 , * V_118 ;
if ( ! V_116 )
return V_115 ;
V_117 = ( V_116 == V_115 ) ? NULL
: V_116 -> V_15 . V_108 ;
V_119:
V_118 = F_98 (
V_117 , V_115 -> V_15 . V_108 ) ;
if ( V_118 ) {
struct V_1 * V_120 = F_93 (
V_118 ) ;
if ( F_62 ( & V_120 -> V_15 ) )
return V_120 ;
else {
V_117 = V_118 ;
goto V_119;
}
}
return NULL ;
}
struct V_1 * F_99 ( struct V_1 * V_115 ,
struct V_1 * V_121 ,
struct V_122 * V_123 )
{
struct V_1 * V_4 = NULL ;
struct V_1 * V_116 = NULL ;
unsigned long V_124 ( V_125 ) ;
if ( F_100 () )
return NULL ;
if ( ! V_115 )
V_115 = V_17 ;
if ( V_121 && ! V_123 )
V_116 = V_121 ;
if ( ! V_115 -> V_126 && V_115 != V_17 ) {
if ( V_121 )
goto V_127;
return V_115 ;
}
F_23 () ;
while ( ! V_4 ) {
struct V_128 * V_124 ( V_129 ) ;
if ( V_123 ) {
int V_35 = F_101 ( V_123 -> V_62 ) ;
int V_36 = F_102 ( V_123 -> V_62 ) ;
struct V_34 * V_45 ;
V_45 = F_38 ( V_115 , V_35 , V_36 ) ;
V_129 = & V_45 -> V_130 [ V_123 -> V_131 ] ;
if ( V_121 && V_123 -> V_132 != V_129 -> V_132 ) {
V_129 -> V_116 = NULL ;
goto V_133;
}
V_125 = F_103 ( & V_115 -> V_125 ) ;
if ( V_125 == V_129 -> V_134 ) {
F_104 () ;
V_116 = V_129 -> V_116 ;
if ( V_116 &&
! F_62 ( & V_116 -> V_15 ) )
V_116 = NULL ;
}
}
V_4 = F_97 ( V_115 , V_116 ) ;
if ( V_123 ) {
if ( V_116 )
F_105 ( & V_116 -> V_15 ) ;
V_129 -> V_116 = V_4 ;
F_106 () ;
V_129 -> V_134 = V_125 ;
if ( ! V_4 )
V_129 -> V_132 ++ ;
else if ( ! V_121 && V_4 )
V_123 -> V_132 = V_129 -> V_132 ;
}
if ( V_121 && ! V_4 )
goto V_133;
}
V_133:
F_26 () ;
V_127:
if ( V_121 && V_121 != V_115 )
F_105 ( & V_121 -> V_15 ) ;
return V_4 ;
}
void F_107 ( struct V_1 * V_115 ,
struct V_1 * V_121 )
{
if ( ! V_115 )
V_115 = V_17 ;
if ( V_121 && V_121 != V_115 )
F_105 ( & V_121 -> V_15 ) ;
}
void F_108 ( struct V_112 * V_113 , enum V_135 V_68 )
{
struct V_1 * V_4 ;
F_23 () ;
V_4 = F_24 ( F_96 ( V_113 -> V_114 ) ) ;
if ( F_90 ( ! V_4 ) )
goto V_136;
switch ( V_68 ) {
case V_137 :
F_109 ( V_4 -> V_71 -> V_78 [ V_138 ] ) ;
break;
case V_139 :
F_109 ( V_4 -> V_71 -> V_78 [ V_140 ] ) ;
break;
default:
F_110 () ;
}
V_136:
F_26 () ;
}
struct V_87 * F_111 ( struct V_62 * V_62 ,
struct V_1 * V_4 )
{
struct V_34 * V_45 ;
struct V_87 * V_87 ;
if ( F_100 () ) {
V_87 = & V_62 -> V_87 ;
goto V_136;
}
V_45 = F_38 ( V_4 , F_101 ( V_62 ) , F_102 ( V_62 ) ) ;
V_87 = & V_45 -> V_87 ;
V_136:
if ( F_90 ( V_87 -> V_62 != V_62 ) )
V_87 -> V_62 = V_62 ;
return V_87 ;
}
struct V_87 * F_112 ( struct V_40 * V_40 , struct V_62 * V_62 )
{
struct V_34 * V_45 ;
struct V_1 * V_4 ;
struct V_141 * V_142 ;
struct V_87 * V_87 ;
if ( F_100 () ) {
V_87 = & V_62 -> V_87 ;
goto V_136;
}
V_142 = F_113 ( V_40 ) ;
V_4 = V_142 -> V_1 ;
if ( ! F_114 ( V_40 ) && ! F_115 ( V_142 ) && V_4 != V_17 )
V_142 -> V_1 = V_4 = V_17 ;
V_45 = F_41 ( V_4 , V_40 ) ;
V_87 = & V_45 -> V_87 ;
V_136:
if ( F_90 ( V_87 -> V_62 != V_62 ) )
V_87 -> V_62 = V_62 ;
return V_87 ;
}
void F_116 ( struct V_87 * V_87 , enum V_88 V_89 ,
int V_80 )
{
struct V_34 * V_45 ;
unsigned long * V_90 ;
if ( F_100 () )
return;
V_45 = F_15 ( V_87 , struct V_34 , V_87 ) ;
V_90 = V_45 -> V_90 + V_89 ;
* V_90 += V_80 ;
F_39 ( ( long ) ( * V_90 ) < 0 ) ;
}
bool F_117 ( const struct V_1 * V_143 ,
struct V_1 * V_4 )
{
if ( V_143 == V_4 )
return true ;
if ( ! V_143 -> V_126 || ! V_4 )
return false ;
return F_118 ( & V_4 -> V_15 , & V_143 -> V_15 ) ;
}
static bool F_119 ( const struct V_1 * V_143 ,
struct V_1 * V_4 )
{
bool V_92 ;
F_23 () ;
V_92 = F_117 ( V_143 , V_4 ) ;
F_26 () ;
return V_92 ;
}
int F_120 ( struct V_111 * V_144 , const struct V_1 * V_4 )
{
int V_92 ;
struct V_1 * V_145 = NULL ;
struct V_111 * V_49 ;
V_49 = F_121 ( V_144 ) ;
if ( V_49 ) {
V_145 = F_95 ( V_49 -> V_113 ) ;
F_122 ( V_49 ) ;
} else {
F_123 ( V_144 ) ;
V_145 = F_24 ( V_144 ) ;
if ( V_145 )
F_124 ( & V_145 -> V_15 ) ;
F_122 ( V_144 ) ;
}
if ( ! V_145 )
return 0 ;
V_92 = F_119 ( V_4 , V_145 ) ;
F_105 ( & V_145 -> V_15 ) ;
return V_92 ;
}
int F_125 ( struct V_87 * V_87 )
{
unsigned long V_146 ;
unsigned long V_147 ;
unsigned long V_148 ;
unsigned long V_149 ;
V_147 = F_79 ( V_87 , V_150 ) ;
V_148 = F_79 ( V_87 , V_151 ) ;
V_149 = ( V_147 + V_148 ) >> ( 30 - V_152 ) ;
if ( V_149 )
V_146 = F_126 ( 10 * V_149 ) ;
else
V_146 = 1 ;
return V_147 * V_146 < V_148 ;
}
static unsigned long F_127 ( struct V_1 * V_4 )
{
unsigned long long V_153 ;
V_153 = F_128 ( & V_4 -> V_60 ) ;
if ( V_154 )
V_153 = F_129 ( V_153 , F_128 ( & V_4 -> V_155 ) ) ;
return V_153 >> V_152 ;
}
int F_130 ( struct V_1 * V_4 )
{
struct V_108 * V_156 = V_4 -> V_15 . V_108 ;
if ( V_156 -> V_51 == NULL )
return V_157 ;
return V_4 -> V_158 ;
}
static void F_131 ( struct V_1 * V_4 )
{
F_92 ( & V_159 ) ;
F_92 ( & V_4 -> V_160 ) ;
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
F_39 ( ! F_136 () ) ;
return F_103 ( & V_4 -> V_160 ) > 0 ;
}
static bool F_137 ( struct V_1 * V_4 )
{
struct V_1 * V_161 ;
struct V_1 * V_162 ;
bool V_92 = false ;
F_53 ( & V_10 . V_58 ) ;
V_161 = V_10 . V_161 ;
V_162 = V_10 . V_162 ;
if ( ! V_161 )
goto V_163;
V_92 = F_119 ( V_4 , V_161 )
|| F_119 ( V_4 , V_162 ) ;
V_163:
F_54 ( & V_10 . V_58 ) ;
return V_92 ;
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
void F_147 ( struct V_1 * V_4 , struct V_111 * V_49 )
{
struct V_108 * V_170 ;
struct V_108 * V_171 ;
static char V_172 [ V_173 ] ;
int V_92 ;
struct V_1 * V_129 ;
unsigned int V_174 ;
if ( ! V_49 )
return;
F_23 () ;
V_171 = V_4 -> V_15 . V_108 ;
V_170 = F_148 ( V_49 , V_110 ) ;
V_92 = F_149 ( V_170 , V_172 , V_173 ) ;
if ( V_92 < 0 ) {
F_26 () ;
goto V_66;
}
F_26 () ;
F_150 ( L_1 , V_172 ) ;
F_23 () ;
V_92 = F_149 ( V_171 , V_172 , V_173 ) ;
if ( V_92 < 0 ) {
F_26 () ;
goto V_66;
}
F_26 () ;
F_151 ( L_2 , V_172 ) ;
V_66:
F_150 ( L_3 ,
F_36 ( & V_4 -> V_60 , V_33 ) >> 10 ,
F_36 ( & V_4 -> V_60 , V_175 ) >> 10 ,
F_36 ( & V_4 -> V_60 , V_176 ) ) ;
F_150 ( L_4 ,
F_36 ( & V_4 -> V_155 , V_33 ) >> 10 ,
F_36 ( & V_4 -> V_155 , V_175 ) >> 10 ,
F_36 ( & V_4 -> V_155 , V_176 ) ) ;
F_150 ( L_5 ,
F_36 ( & V_4 -> V_32 , V_33 ) >> 10 ,
F_36 ( & V_4 -> V_32 , V_175 ) >> 10 ,
F_36 ( & V_4 -> V_32 , V_176 ) ) ;
F_152 (iter, memcg) {
F_150 ( L_6 ) ;
F_23 () ;
V_92 = F_149 ( V_129 -> V_15 . V_108 , V_172 , V_173 ) ;
if ( ! V_92 )
F_151 ( L_7 , V_172 ) ;
F_26 () ;
F_151 ( L_8 ) ;
for ( V_174 = 0 ; V_174 < V_177 ; V_174 ++ ) {
if ( V_174 == V_76 && ! V_154 )
continue;
F_151 ( L_9 , V_178 [ V_174 ] ,
F_153 ( F_64 ( V_129 , V_174 ) ) ) ;
}
for ( V_174 = 0 ; V_174 < V_179 ; V_174 ++ )
F_151 ( L_10 , V_180 [ V_174 ] ,
F_153 ( F_84 ( V_129 , F_82 ( V_174 ) ) ) ) ;
F_151 ( L_11 ) ;
}
}
static int F_154 ( struct V_1 * V_4 )
{
int V_181 = 0 ;
struct V_1 * V_129 ;
F_152 (iter, memcg)
V_181 ++ ;
return V_181 ;
}
static T_2 F_155 ( struct V_1 * V_4 )
{
T_2 V_182 ;
V_182 = F_36 ( & V_4 -> V_60 , V_175 ) ;
if ( F_130 ( V_4 ) ) {
T_2 V_155 ;
V_182 += V_183 << V_152 ;
V_155 = F_36 ( & V_4 -> V_155 , V_175 ) ;
V_182 = F_129 ( V_182 , V_155 ) ;
}
return V_182 ;
}
static void F_156 ( struct V_1 * V_4 , T_4 V_184 ,
int V_185 )
{
struct V_1 * V_129 ;
unsigned long V_186 = 0 ;
unsigned long V_187 ;
unsigned int V_188 = 0 ;
struct V_111 * V_189 = NULL ;
if ( F_157 ( V_26 ) || V_26 -> V_168 & V_190 ) {
F_158 ( V_191 ) ;
return;
}
F_159 ( V_192 , V_184 , V_185 , NULL ) ;
V_187 = F_155 ( V_4 ) >> V_152 ? : 1 ;
F_152 (iter, memcg) {
struct V_108 * V_108 = V_129 -> V_15 . V_108 ;
struct V_193 V_194 ;
struct V_111 * V_144 ;
F_160 ( V_108 , & V_194 ) ;
while ( ( V_144 = F_161 ( V_108 , & V_194 ) ) ) {
switch ( F_162 ( V_144 , V_187 , NULL ,
false ) ) {
case V_195 :
if ( V_189 )
F_163 ( V_189 ) ;
V_189 = V_144 ;
V_186 = V_196 ;
F_164 ( V_189 ) ;
case V_197 :
continue;
case V_198 :
F_165 ( V_108 , & V_194 ) ;
F_107 ( V_4 , V_129 ) ;
if ( V_189 )
F_163 ( V_189 ) ;
return;
case V_199 :
break;
} ;
V_188 = F_166 ( V_144 , V_4 , NULL , V_187 ) ;
if ( V_188 > V_186 ) {
if ( V_189 )
F_163 ( V_189 ) ;
V_189 = V_144 ;
V_186 = V_188 ;
F_164 ( V_189 ) ;
}
}
F_165 ( V_108 , & V_194 ) ;
}
if ( ! V_189 )
return;
V_188 = V_186 * 1000 / V_187 ;
F_167 ( V_189 , V_184 , V_185 , V_188 , V_187 , V_4 ,
NULL , L_12 ) ;
}
static unsigned long F_168 ( struct V_1 * V_4 ,
T_4 V_184 ,
unsigned long V_168 )
{
unsigned long V_93 = 0 ;
bool V_200 = false ;
int V_201 ;
if ( V_168 & V_202 )
V_200 = true ;
if ( ! ( V_168 & V_203 ) && V_4 -> V_204 )
V_200 = true ;
for ( V_201 = 0 ; V_201 < V_205 ; V_201 ++ ) {
if ( V_201 )
F_169 ( V_4 ) ;
V_93 += F_170 ( V_4 , V_184 , V_200 ) ;
if ( V_93 && ( V_168 & V_203 ) )
break;
if ( F_127 ( V_4 ) )
break;
if ( V_201 && ! V_93 )
break;
}
return V_93 ;
}
static bool F_171 ( struct V_1 * V_4 ,
int V_35 , bool V_200 )
{
if ( F_83 ( V_4 , V_35 , V_206 ) )
return true ;
if ( V_200 || ! V_183 )
return false ;
if ( F_83 ( V_4 , V_35 , V_207 ) )
return true ;
return false ;
}
static void F_172 ( struct V_1 * V_4 )
{
int V_35 ;
if ( ! F_103 ( & V_4 -> V_107 ) )
return;
if ( F_173 ( & V_4 -> V_208 ) > 1 )
return;
V_4 -> V_209 = V_210 [ V_211 ] ;
F_174 (nid, node_states[N_MEMORY]) {
if ( ! F_171 ( V_4 , V_35 , false ) )
F_175 ( V_35 , V_4 -> V_209 ) ;
}
F_176 ( & V_4 -> V_107 , 0 ) ;
F_176 ( & V_4 -> V_208 , 0 ) ;
}
int F_177 ( struct V_1 * V_4 )
{
int V_61 ;
F_172 ( V_4 ) ;
V_61 = V_4 -> V_212 ;
V_61 = F_178 ( V_61 , V_4 -> V_209 ) ;
if ( V_61 == V_106 )
V_61 = F_179 ( V_4 -> V_209 ) ;
if ( F_90 ( V_61 == V_106 ) )
V_61 = F_180 () ;
V_4 -> V_212 = V_61 ;
return V_61 ;
}
static bool F_181 ( struct V_1 * V_4 , bool V_200 )
{
int V_35 ;
if ( ! F_182 ( V_4 -> V_209 ) ) {
for ( V_35 = F_179 ( V_4 -> V_209 ) ;
V_35 < V_106 ;
V_35 = F_178 ( V_35 , V_4 -> V_209 ) ) {
if ( F_171 ( V_4 , V_35 , V_200 ) )
return true ;
}
}
F_85 (nid, N_MEMORY) {
if ( F_183 ( V_35 , V_4 -> V_209 ) )
continue;
if ( F_171 ( V_4 , V_35 , V_200 ) )
return true ;
}
return false ;
}
int F_177 ( struct V_1 * V_4 )
{
return 0 ;
}
static bool F_181 ( struct V_1 * V_4 , bool V_200 )
{
return F_171 ( V_4 , 0 , V_200 ) ;
}
static int F_184 ( struct V_1 * V_143 ,
struct V_62 * V_62 ,
T_4 V_184 ,
unsigned long * V_213 )
{
struct V_1 * V_214 = NULL ;
int V_93 = 0 ;
int V_201 = 0 ;
unsigned long V_59 ;
unsigned long V_215 ;
struct V_122 V_123 = {
. V_62 = V_62 ,
. V_131 = 0 ,
} ;
V_59 = F_57 ( & V_143 -> V_60 ) >> V_152 ;
while ( 1 ) {
V_214 = F_99 ( V_143 , V_214 , & V_123 ) ;
if ( ! V_214 ) {
V_201 ++ ;
if ( V_201 >= 2 ) {
if ( ! V_93 )
break;
if ( V_93 >= ( V_59 >> 2 ) ||
( V_201 > V_205 ) )
break;
}
continue;
}
if ( ! F_181 ( V_214 , false ) )
continue;
V_93 += F_185 ( V_214 , V_184 , false ,
V_62 , & V_215 ) ;
* V_213 += V_215 ;
if ( ! F_57 ( & V_143 -> V_60 ) )
break;
}
F_107 ( V_143 , V_214 ) ;
return V_93 ;
}
static bool F_186 ( struct V_1 * V_4 )
{
struct V_1 * V_129 , * V_216 = NULL ;
F_152 (iter, memcg) {
if ( V_129 -> V_217 ) {
V_216 = V_129 ;
F_107 ( V_4 , V_129 ) ;
break;
} else
V_129 -> V_217 = true ;
}
if ( ! V_216 )
return true ;
F_152 (iter, memcg) {
if ( V_129 == V_216 ) {
F_107 ( V_4 , V_129 ) ;
break;
}
V_129 -> V_217 = false ;
}
return false ;
}
static int F_187 ( struct V_1 * V_4 )
{
struct V_1 * V_129 ;
F_152 (iter, memcg)
V_129 -> V_217 = false ;
return 0 ;
}
static void F_188 ( struct V_1 * V_4 )
{
struct V_1 * V_129 ;
F_152 (iter, memcg)
F_92 ( & V_129 -> V_218 ) ;
}
static void F_189 ( struct V_1 * V_4 )
{
struct V_1 * V_129 ;
F_152 (iter, memcg)
F_190 ( & V_129 -> V_218 , - 1 , 0 ) ;
}
static int F_191 ( T_5 * V_165 ,
unsigned V_219 , int V_220 , void * V_221 )
{
struct V_1 * V_222 = (struct V_1 * ) V_221 ;
struct V_1 * V_223 ;
struct V_224 * V_224 ;
V_224 = F_15 ( V_165 , struct V_224 , V_165 ) ;
V_223 = V_224 -> V_4 ;
if ( ! F_119 ( V_223 , V_222 )
&& ! F_119 ( V_222 , V_223 ) )
return 0 ;
return F_192 ( V_165 , V_219 , V_220 , V_221 ) ;
}
static void F_193 ( struct V_1 * V_4 )
{
F_194 ( & V_225 , V_226 , 0 , V_4 ) ;
}
static void F_195 ( struct V_1 * V_4 )
{
if ( V_4 && F_103 ( & V_4 -> V_218 ) )
F_193 ( V_4 ) ;
}
static bool F_196 ( struct V_1 * V_4 , T_4 V_227 ,
int V_185 )
{
struct V_224 V_228 ;
bool V_229 , V_230 ;
V_228 . V_4 = V_4 ;
V_228 . V_165 . V_168 = 0 ;
V_228 . V_165 . V_231 = F_191 ;
V_228 . V_165 . V_232 = V_26 ;
F_197 ( & V_228 . V_165 . V_233 ) ;
V_230 = true ;
F_188 ( V_4 ) ;
F_53 ( & V_234 ) ;
V_229 = F_186 ( V_4 ) ;
F_140 ( & V_225 , & V_228 . V_165 , V_235 ) ;
if ( ! V_229 || V_4 -> V_236 )
V_230 = false ;
if ( V_229 )
F_198 ( V_4 ) ;
F_54 ( & V_234 ) ;
if ( V_230 ) {
F_142 ( & V_225 , & V_228 . V_165 ) ;
F_156 ( V_4 , V_227 , V_185 ) ;
} else {
F_141 () ;
F_142 ( & V_225 , & V_228 . V_165 ) ;
}
F_53 ( & V_234 ) ;
if ( V_229 )
F_187 ( V_4 ) ;
F_193 ( V_4 ) ;
F_54 ( & V_234 ) ;
F_189 ( V_4 ) ;
if ( F_199 ( V_191 ) || F_157 ( V_26 ) )
return false ;
F_200 ( 1 ) ;
return true ;
}
void F_201 ( struct V_40 * V_40 ,
bool * V_229 , unsigned long * V_168 )
{
struct V_1 * V_4 ;
struct V_141 * V_142 ;
V_142 = F_113 ( V_40 ) ;
V_237:
V_4 = V_142 -> V_1 ;
if ( F_90 ( ! V_4 || ! F_115 ( V_142 ) ) )
return;
if ( ! F_135 ( V_4 ) )
return;
F_143 ( V_4 , V_168 ) ;
if ( V_4 != V_142 -> V_1 || ! F_115 ( V_142 ) ) {
F_145 ( V_4 , V_168 ) ;
goto V_237;
}
* V_229 = true ;
}
void F_202 ( struct V_40 * V_40 , unsigned long * V_168 )
{
struct V_141 * V_142 = F_113 ( V_40 ) ;
F_145 ( V_142 -> V_1 , V_168 ) ;
}
void F_203 ( struct V_40 * V_40 ,
enum V_238 V_68 , int V_69 )
{
struct V_1 * V_4 ;
struct V_141 * V_142 = F_113 ( V_40 ) ;
unsigned long V_124 ( V_168 ) ;
if ( F_100 () )
return;
V_4 = V_142 -> V_1 ;
if ( F_90 ( ! V_4 || ! F_115 ( V_142 ) ) )
return;
switch ( V_68 ) {
case V_239 :
V_68 = V_240 ;
break;
default:
F_110 () ;
}
F_71 ( V_4 -> V_71 -> V_72 [ V_68 ] , V_69 ) ;
}
static bool F_204 ( struct V_1 * V_4 , unsigned int V_80 )
{
struct V_241 * V_242 ;
bool V_92 = true ;
if ( V_80 > V_243 )
return false ;
V_242 = & F_205 ( V_244 ) ;
if ( V_4 == V_242 -> V_245 && V_242 -> V_80 >= V_80 )
V_242 -> V_80 -= V_80 ;
else
V_92 = false ;
F_206 ( V_244 ) ;
return V_92 ;
}
static void F_207 ( struct V_241 * V_242 )
{
struct V_1 * V_246 = V_242 -> V_245 ;
if ( V_242 -> V_80 ) {
unsigned long V_247 = V_242 -> V_80 * V_248 ;
F_208 ( & V_246 -> V_60 , V_247 ) ;
if ( V_154 )
F_208 ( & V_246 -> V_155 , V_247 ) ;
V_242 -> V_80 = 0 ;
}
V_242 -> V_245 = NULL ;
}
static void F_209 ( struct V_249 * V_250 )
{
struct V_241 * V_242 = & F_210 ( V_244 ) ;
F_207 ( V_242 ) ;
F_8 ( V_251 , & V_242 -> V_168 ) ;
}
static void T_6 F_211 ( void )
{
int V_70 ;
F_212 (cpu) {
struct V_241 * V_242 =
& F_67 ( V_244 , V_70 ) ;
F_213 ( & V_242 -> V_252 , F_209 ) ;
}
}
static void F_214 ( struct V_1 * V_4 , unsigned int V_80 )
{
struct V_241 * V_242 = & F_205 ( V_244 ) ;
if ( V_242 -> V_245 != V_4 ) {
F_207 ( V_242 ) ;
V_242 -> V_245 = V_4 ;
}
V_242 -> V_80 += V_80 ;
F_206 ( V_244 ) ;
}
static void F_215 ( struct V_1 * V_143 , bool V_220 )
{
int V_70 , V_253 ;
F_65 () ;
V_253 = F_216 () ;
F_66 (cpu) {
struct V_241 * V_242 = & F_67 ( V_244 , V_70 ) ;
struct V_1 * V_4 ;
V_4 = V_242 -> V_245 ;
if ( ! V_4 || ! V_242 -> V_80 )
continue;
if ( ! F_119 ( V_143 , V_4 ) )
continue;
if ( ! F_217 ( V_251 , & V_242 -> V_168 ) ) {
if ( V_70 == V_253 )
F_209 ( & V_242 -> V_252 ) ;
else
F_218 ( V_70 , & V_242 -> V_252 ) ;
}
}
F_219 () ;
if ( ! V_220 )
goto V_136;
F_66 (cpu) {
struct V_241 * V_242 = & F_67 ( V_244 , V_70 ) ;
if ( F_5 ( V_251 , & V_242 -> V_168 ) )
F_220 ( & V_242 -> V_252 ) ;
}
V_136:
F_69 () ;
}
static void F_169 ( struct V_1 * V_143 )
{
if ( ! F_221 ( & V_254 ) )
return;
F_215 ( V_143 , false ) ;
F_222 ( & V_254 ) ;
}
static void F_223 ( struct V_1 * V_143 )
{
F_224 ( & V_254 ) ;
F_215 ( V_143 , true ) ;
F_222 ( & V_254 ) ;
}
static void F_225 ( struct V_1 * V_4 , int V_70 )
{
int V_174 ;
F_53 ( & V_4 -> V_73 ) ;
for ( V_174 = 0 ; V_174 < V_177 ; V_174 ++ ) {
long V_255 = F_67 ( V_4 -> V_71 -> V_72 [ V_174 ] , V_70 ) ;
F_67 ( V_4 -> V_71 -> V_72 [ V_174 ] , V_70 ) = 0 ;
V_4 -> V_74 . V_72 [ V_174 ] += V_255 ;
}
for ( V_174 = 0 ; V_174 < V_256 ; V_174 ++ ) {
unsigned long V_255 = F_67 ( V_4 -> V_71 -> V_78 [ V_174 ] , V_70 ) ;
F_67 ( V_4 -> V_71 -> V_78 [ V_174 ] , V_70 ) = 0 ;
V_4 -> V_74 . V_78 [ V_174 ] += V_255 ;
}
F_54 ( & V_4 -> V_73 ) ;
}
static int T_7 F_226 ( struct V_257 * V_258 ,
unsigned long V_259 ,
void * V_260 )
{
int V_70 = ( unsigned long ) V_260 ;
struct V_241 * V_242 ;
struct V_1 * V_129 ;
if ( V_259 == V_261 )
return V_262 ;
if ( V_259 != V_263 && V_259 != V_264 )
return V_262 ;
F_227 (iter)
F_225 ( V_129 , V_70 ) ;
V_242 = & F_67 ( V_244 , V_70 ) ;
F_207 ( V_242 ) ;
return V_262 ;
}
static int F_228 ( struct V_1 * V_4 , T_4 V_184 ,
unsigned int V_80 , unsigned int V_265 ,
bool V_266 )
{
unsigned long V_267 = V_80 * V_248 ;
struct V_1 * V_268 ;
struct V_269 * V_270 ;
unsigned long V_168 = 0 ;
int V_92 ;
V_92 = F_229 ( & V_4 -> V_60 , V_267 , & V_270 ) ;
if ( F_230 ( ! V_92 ) ) {
if ( ! V_154 )
return V_271 ;
V_92 = F_229 ( & V_4 -> V_155 , V_267 , & V_270 ) ;
if ( F_230 ( ! V_92 ) )
return V_271 ;
F_208 ( & V_4 -> V_60 , V_267 ) ;
V_268 = F_231 ( V_270 , V_155 ) ;
V_168 |= V_202 ;
} else
V_268 = F_231 ( V_270 , V_60 ) ;
if ( V_80 > V_265 )
return V_272 ;
if ( ! ( V_184 & V_273 ) )
return V_274 ;
if ( V_184 & V_275 )
return V_276 ;
V_92 = F_168 ( V_268 , V_184 , V_168 ) ;
if ( F_127 ( V_268 ) >= V_80 )
return V_272 ;
if ( V_80 <= ( 1 << V_277 ) && V_92 )
return V_272 ;
if ( F_138 ( V_268 ) )
return V_272 ;
if ( ! V_266 )
return V_276 ;
if ( ! F_196 ( V_268 , V_184 , F_232 ( V_267 ) ) )
return V_278 ;
return V_272 ;
}
static int F_233 ( struct V_112 * V_113 ,
T_4 V_184 ,
unsigned int V_80 ,
struct V_1 * * V_279 ,
bool V_280 )
{
unsigned int V_281 = F_234 ( V_243 , V_80 ) ;
int V_282 = V_283 ;
struct V_1 * V_4 = NULL ;
int V_92 ;
if ( F_90 ( F_199 ( V_191 )
|| F_157 ( V_26 ) ) )
goto V_284;
if ( ! * V_279 && ! V_113 )
* V_279 = V_17 ;
V_237:
if ( * V_279 ) {
V_4 = * V_279 ;
if ( F_19 ( V_4 ) )
goto V_66;
if ( F_204 ( V_4 , V_80 ) )
goto V_66;
F_124 ( & V_4 -> V_15 ) ;
} else {
struct V_111 * V_49 ;
F_23 () ;
V_49 = F_96 ( V_113 -> V_114 ) ;
V_4 = F_24 ( V_49 ) ;
if ( ! V_4 )
V_4 = V_17 ;
if ( F_19 ( V_4 ) ) {
F_26 () ;
goto V_66;
}
if ( F_204 ( V_4 , V_80 ) ) {
F_26 () ;
goto V_66;
}
if ( ! F_62 ( & V_4 -> V_15 ) ) {
F_26 () ;
goto V_237;
}
F_26 () ;
}
do {
bool V_266 ;
if ( F_157 ( V_26 ) ) {
F_105 ( & V_4 -> V_15 ) ;
goto V_284;
}
V_266 = false ;
if ( V_280 && ! V_282 ) {
V_266 = true ;
V_282 = V_283 ;
}
V_92 = F_228 ( V_4 , V_184 , V_281 , V_80 ,
V_266 ) ;
switch ( V_92 ) {
case V_271 :
break;
case V_272 :
V_281 = V_80 ;
F_105 ( & V_4 -> V_15 ) ;
V_4 = NULL ;
goto V_237;
case V_274 :
F_105 ( & V_4 -> V_15 ) ;
goto V_285;
case V_276 :
if ( ! V_280 ) {
F_105 ( & V_4 -> V_15 ) ;
goto V_285;
}
V_282 -- ;
break;
case V_278 :
F_105 ( & V_4 -> V_15 ) ;
goto V_284;
}
} while ( V_92 != V_271 );
if ( V_281 > V_80 )
F_214 ( V_4 , V_281 - V_80 ) ;
F_105 ( & V_4 -> V_15 ) ;
V_66:
* V_279 = V_4 ;
return 0 ;
V_285:
* V_279 = NULL ;
return - V_286 ;
V_284:
* V_279 = V_17 ;
return - V_287 ;
}
static void F_235 ( struct V_1 * V_4 ,
unsigned int V_80 )
{
if ( ! F_19 ( V_4 ) ) {
unsigned long V_247 = V_80 * V_248 ;
F_208 ( & V_4 -> V_60 , V_247 ) ;
if ( V_154 )
F_208 ( & V_4 -> V_155 , V_247 ) ;
}
}
static void F_236 ( struct V_1 * V_4 ,
unsigned int V_80 )
{
unsigned long V_247 = V_80 * V_248 ;
if ( F_19 ( V_4 ) )
return;
F_237 ( & V_4 -> V_60 , V_4 -> V_60 . V_51 , V_247 ) ;
if ( V_154 )
F_237 ( & V_4 -> V_155 ,
V_4 -> V_155 . V_51 , V_247 ) ;
}
static struct V_1 * F_238 ( unsigned short V_288 )
{
struct V_13 * V_15 ;
if ( ! V_288 )
return NULL ;
V_15 = F_239 ( & V_289 , V_288 ) ;
if ( ! V_15 )
return NULL ;
return F_14 ( V_15 ) ;
}
struct V_1 * F_240 ( struct V_40 * V_40 )
{
struct V_1 * V_4 = NULL ;
struct V_141 * V_142 ;
unsigned short V_288 ;
T_8 V_290 ;
F_39 ( ! F_241 ( V_40 ) ) ;
V_142 = F_113 ( V_40 ) ;
F_242 ( V_142 ) ;
if ( F_115 ( V_142 ) ) {
V_4 = V_142 -> V_1 ;
if ( V_4 && ! F_62 ( & V_4 -> V_15 ) )
V_4 = NULL ;
} else if ( F_243 ( V_40 ) ) {
V_290 . V_69 = F_244 ( V_40 ) ;
V_288 = F_245 ( V_290 ) ;
F_23 () ;
V_4 = F_238 ( V_288 ) ;
if ( V_4 && ! F_62 ( & V_4 -> V_15 ) )
V_4 = NULL ;
F_26 () ;
}
F_246 ( V_142 ) ;
return V_4 ;
}
static void F_247 ( struct V_1 * V_4 ,
struct V_40 * V_40 ,
unsigned int V_80 ,
enum V_291 V_292 ,
bool V_293 )
{
struct V_141 * V_142 = F_113 ( V_40 ) ;
struct V_62 * V_124 ( V_62 ) ;
struct V_87 * V_87 ;
bool V_294 = false ;
bool V_79 ;
F_242 ( V_142 ) ;
F_39 ( F_115 ( V_142 ) ) ;
if ( V_293 ) {
V_62 = F_248 ( V_40 ) ;
F_249 ( & V_62 -> V_295 ) ;
if ( F_114 ( V_40 ) ) {
V_87 = F_111 ( V_62 , V_142 -> V_1 ) ;
F_250 ( V_40 ) ;
F_251 ( V_40 , V_87 , F_252 ( V_40 ) ) ;
V_294 = true ;
}
}
V_142 -> V_1 = V_4 ;
F_106 () ;
F_253 ( V_142 ) ;
if ( V_293 ) {
if ( V_294 ) {
V_87 = F_111 ( V_62 , V_142 -> V_1 ) ;
F_39 ( F_114 ( V_40 ) ) ;
F_254 ( V_40 ) ;
F_255 ( V_40 , V_87 , F_252 ( V_40 ) ) ;
}
F_256 ( & V_62 -> V_295 ) ;
}
if ( V_292 == V_296 )
V_79 = true ;
else
V_79 = false ;
F_73 ( V_4 , V_40 , V_79 , V_80 ) ;
F_246 ( V_142 ) ;
F_89 ( V_4 , V_40 ) ;
}
static inline bool F_257 ( struct V_1 * V_4 )
{
return ! F_100 () && ! F_19 ( V_4 ) &&
( V_4 -> V_6 & V_297 ) ;
}
static struct V_298 * F_258 ( struct V_299 * V_49 )
{
struct V_298 * V_300 ;
F_39 ( V_49 -> V_301 ) ;
V_300 = V_49 -> V_302 ;
return V_300 -> V_303 -> V_304 [ F_259 ( V_49 -> V_4 ) ] ;
}
static int F_260 ( struct V_108 * V_109 , struct V_305 * V_306 ,
struct V_307 * V_308 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
struct V_299 * V_309 ;
if ( ! F_257 ( V_4 ) )
return - V_310 ;
F_261 ( V_308 ) ;
F_224 ( & V_4 -> V_311 ) ;
F_262 (params, &memcg->memcg_slab_caches, list)
F_263 ( F_258 ( V_309 ) , V_308 ) ;
F_222 ( & V_4 -> V_311 ) ;
return 0 ;
}
static int F_264 ( struct V_1 * V_4 , T_4 V_312 , T_2 V_313 )
{
struct V_269 * V_270 ;
struct V_1 * V_314 ;
int V_92 = 0 ;
bool V_315 ;
V_92 = F_229 ( & V_4 -> V_32 , V_313 , & V_270 ) ;
if ( V_92 )
return V_92 ;
V_315 = ( V_312 & V_316 ) && ! ( V_312 & V_275 ) ;
V_314 = V_4 ;
V_92 = F_233 ( NULL , V_312 , V_313 >> V_152 ,
& V_314 , V_315 ) ;
if ( V_92 == - V_287 ) {
F_265 ( & V_4 -> V_60 , V_313 , & V_270 ) ;
if ( V_154 )
F_265 ( & V_4 -> V_155 , V_313 ,
& V_270 ) ;
V_92 = 0 ;
} else if ( V_92 )
F_208 ( & V_4 -> V_32 , V_313 ) ;
return V_92 ;
}
static void F_266 ( struct V_1 * V_4 , T_2 V_313 )
{
F_208 ( & V_4 -> V_60 , V_313 ) ;
if ( V_154 )
F_208 ( & V_4 -> V_155 , V_313 ) ;
if ( F_208 ( & V_4 -> V_32 , V_313 ) )
return;
if ( F_10 ( V_4 ) )
F_29 ( V_4 ) ;
}
void F_267 ( struct V_1 * V_4 , struct V_298 * V_300 )
{
if ( ! V_4 )
return;
F_224 ( & V_4 -> V_311 ) ;
F_268 ( & V_300 -> V_303 -> V_317 , & V_4 -> V_318 ) ;
F_222 ( & V_4 -> V_311 ) ;
}
int F_259 ( struct V_1 * V_4 )
{
return V_4 ? V_4 -> V_31 : - 1 ;
}
int F_269 ( struct V_1 * V_4 )
{
int V_181 , V_92 ;
V_181 = F_270 ( & V_30 ,
0 , V_319 , V_320 ) ;
if ( V_181 < 0 )
return V_181 ;
F_6 ( V_4 ) ;
V_92 = F_271 ( V_181 + 1 ) ;
if ( V_92 ) {
F_35 ( & V_30 , V_181 ) ;
F_7 ( V_4 ) ;
return V_92 ;
}
V_4 -> V_31 = V_181 ;
F_197 ( & V_4 -> V_318 ) ;
F_272 ( & V_4 -> V_311 ) ;
return 0 ;
}
static T_1 F_273 ( int V_321 )
{
T_9 V_313 ;
if ( V_321 <= 0 )
return 0 ;
V_313 = 2 * V_321 ;
if ( V_313 < V_322 )
V_313 = V_322 ;
else if ( V_313 > V_319 )
V_313 = V_319 ;
return V_313 ;
}
void F_274 ( int V_181 )
{
if ( V_181 > V_323 )
V_323 = F_273 ( V_181 ) ;
}
int F_275 ( struct V_298 * V_14 , int V_321 )
{
struct V_299 * V_324 = V_14 -> V_303 ;
F_39 ( V_14 -> V_303 && ! V_14 -> V_303 -> V_301 ) ;
if ( V_321 > V_323 ) {
int V_174 ;
T_9 V_313 = F_273 ( V_321 ) ;
V_313 *= sizeof( void * ) ;
V_313 += sizeof( struct V_299 ) ;
V_14 -> V_303 = F_276 ( V_313 , V_320 ) ;
if ( ! V_14 -> V_303 ) {
V_14 -> V_303 = V_324 ;
return - V_286 ;
}
V_14 -> V_303 -> V_301 = true ;
for ( V_174 = 0 ; V_174 < V_323 ; V_174 ++ ) {
if ( ! V_324 -> V_304 [ V_174 ] )
continue;
V_14 -> V_303 -> V_304 [ V_174 ] =
V_324 -> V_304 [ V_174 ] ;
}
F_277 ( V_324 ) ;
}
return 0 ;
}
int F_278 ( struct V_1 * V_4 , struct V_298 * V_14 ,
struct V_298 * V_302 )
{
T_1 V_313 = sizeof( struct V_299 ) ;
if ( ! F_279 () )
return 0 ;
if ( ! V_4 )
V_313 += V_323 * sizeof( void * ) ;
V_14 -> V_303 = F_276 ( V_313 , V_320 ) ;
if ( ! V_14 -> V_303 )
return - V_286 ;
F_213 ( & V_14 -> V_303 -> V_325 ,
V_326 ) ;
if ( V_4 ) {
V_14 -> V_303 -> V_4 = V_4 ;
V_14 -> V_303 -> V_302 = V_302 ;
} else
V_14 -> V_303 -> V_301 = true ;
return 0 ;
}
void F_280 ( struct V_298 * V_14 )
{
struct V_298 * V_115 ;
struct V_1 * V_4 ;
int V_288 ;
if ( ! V_14 -> V_303 )
return;
if ( V_14 -> V_303 -> V_301 )
goto V_136;
V_4 = V_14 -> V_303 -> V_4 ;
V_288 = F_259 ( V_4 ) ;
V_115 = V_14 -> V_303 -> V_302 ;
V_115 -> V_303 -> V_304 [ V_288 ] = NULL ;
F_224 ( & V_4 -> V_311 ) ;
F_281 ( & V_14 -> V_303 -> V_317 ) ;
F_222 ( & V_4 -> V_311 ) ;
F_29 ( V_4 ) ;
V_136:
F_277 ( V_14 -> V_303 ) ;
}
static inline void F_282 ( void )
{
F_39 ( ! V_26 -> V_113 ) ;
V_26 -> V_327 ++ ;
}
static inline void F_283 ( void )
{
F_39 ( ! V_26 -> V_113 ) ;
V_26 -> V_327 -- ;
}
static void V_326 ( struct V_249 * V_328 )
{
struct V_298 * V_300 ;
struct V_299 * V_49 ;
V_49 = F_15 ( V_328 , struct V_299 , V_325 ) ;
V_300 = F_258 ( V_49 ) ;
if ( F_103 ( & V_300 -> V_303 -> V_80 ) != 0 ) {
F_284 ( V_300 ) ;
if ( F_103 ( & V_300 -> V_303 -> V_80 ) == 0 )
return;
} else
F_285 ( V_300 ) ;
}
void F_286 ( struct V_298 * V_300 )
{
if ( ! V_300 -> V_303 -> V_329 )
return;
if ( F_287 ( & V_300 -> V_303 -> V_325 ) )
return;
F_288 ( & V_300 -> V_303 -> V_325 ) ;
}
static struct V_298 * F_289 ( struct V_1 * V_4 ,
struct V_298 * V_14 )
{
struct V_298 * V_330 ;
static char * V_331 = NULL ;
F_290 ( & V_332 ) ;
if ( ! V_331 ) {
V_331 = F_291 ( V_173 , V_320 ) ;
if ( ! V_331 )
return NULL ;
}
F_23 () ;
snprintf ( V_331 , V_173 , L_13 , V_14 -> V_333 ,
F_259 ( V_4 ) , F_292 ( V_4 -> V_15 . V_108 ) ) ;
F_26 () ;
V_330 = F_293 ( V_4 , V_331 , V_14 -> V_334 , V_14 -> V_335 ,
( V_14 -> V_168 & ~ V_336 ) , V_14 -> V_337 , V_14 ) ;
if ( V_330 )
V_330 -> V_338 |= V_339 ;
return V_330 ;
}
static struct V_298 * F_294 ( struct V_1 * V_4 ,
struct V_298 * V_300 )
{
struct V_298 * V_340 ;
int V_68 ;
F_21 ( ! F_257 ( V_4 ) ) ;
V_68 = F_259 ( V_4 ) ;
F_224 ( & V_332 ) ;
V_340 = V_300 -> V_303 -> V_304 [ V_68 ] ;
if ( V_340 )
goto V_136;
V_340 = F_289 ( V_4 , V_300 ) ;
if ( V_340 == NULL ) {
V_340 = V_300 ;
goto V_136;
}
F_22 ( V_4 ) ;
F_176 ( & V_340 -> V_303 -> V_80 , 0 ) ;
V_300 -> V_303 -> V_304 [ V_68 ] = V_340 ;
F_295 () ;
V_136:
F_222 ( & V_332 ) ;
return V_340 ;
}
void F_296 ( struct V_298 * V_14 )
{
struct V_298 * V_341 ;
int V_174 ;
if ( ! V_14 -> V_303 )
return;
if ( ! V_14 -> V_303 -> V_301 )
return;
F_224 ( & V_342 ) ;
for ( V_174 = 0 ; V_174 < V_323 ; V_174 ++ ) {
V_341 = V_14 -> V_303 -> V_304 [ V_174 ] ;
if ( ! V_341 )
continue;
V_341 -> V_303 -> V_329 = false ;
F_297 ( & V_341 -> V_303 -> V_325 ) ;
F_285 ( V_341 ) ;
}
F_222 ( & V_342 ) ;
}
static void F_298 ( struct V_1 * V_4 )
{
struct V_298 * V_300 ;
struct V_299 * V_309 ;
if ( ! F_4 ( V_4 ) )
return;
F_224 ( & V_4 -> V_311 ) ;
F_262 (params, &memcg->memcg_slab_caches, list) {
V_300 = F_258 ( V_309 ) ;
V_300 -> V_303 -> V_329 = true ;
F_288 ( & V_300 -> V_303 -> V_325 ) ;
}
F_222 ( & V_4 -> V_311 ) ;
}
static void F_299 ( struct V_249 * V_328 )
{
struct V_343 * V_344 ;
V_344 = F_15 ( V_328 , struct V_343 , V_252 ) ;
F_294 ( V_344 -> V_4 , V_344 -> V_300 ) ;
F_105 ( & V_344 -> V_4 -> V_15 ) ;
F_277 ( V_344 ) ;
}
static void F_300 ( struct V_1 * V_4 ,
struct V_298 * V_300 )
{
struct V_343 * V_344 ;
V_344 = F_291 ( sizeof( struct V_343 ) , V_345 ) ;
if ( V_344 == NULL ) {
F_105 ( & V_4 -> V_15 ) ;
return;
}
V_344 -> V_4 = V_4 ;
V_344 -> V_300 = V_300 ;
F_213 ( & V_344 -> V_252 , F_299 ) ;
F_288 ( & V_344 -> V_252 ) ;
}
static void F_301 ( struct V_1 * V_4 ,
struct V_298 * V_300 )
{
F_282 () ;
F_300 ( V_4 , V_300 ) ;
F_283 () ;
}
struct V_298 * F_302 ( struct V_298 * V_300 ,
T_4 V_312 )
{
struct V_1 * V_4 ;
int V_68 ;
F_39 ( ! V_300 -> V_303 ) ;
F_39 ( ! V_300 -> V_303 -> V_301 ) ;
if ( ! V_26 -> V_113 || V_26 -> V_327 )
return V_300 ;
F_23 () ;
V_4 = F_24 ( F_96 ( V_26 -> V_113 -> V_114 ) ) ;
if ( ! F_257 ( V_4 ) )
goto V_136;
V_68 = F_259 ( V_4 ) ;
F_303 () ;
if ( F_230 ( V_300 -> V_303 -> V_304 [ V_68 ] ) ) {
V_300 = V_300 -> V_303 -> V_304 [ V_68 ] ;
goto V_136;
}
if ( ! F_62 ( & V_4 -> V_15 ) )
goto V_136;
F_26 () ;
F_301 ( V_4 , V_300 ) ;
return V_300 ;
V_136:
F_26 () ;
return V_300 ;
}
bool
F_304 ( T_4 V_312 , struct V_1 * * V_314 , int V_185 )
{
struct V_1 * V_4 ;
int V_92 ;
* V_314 = NULL ;
V_4 = F_95 ( V_26 -> V_113 ) ;
if ( F_90 ( ! V_4 ) )
return true ;
if ( ! F_257 ( V_4 ) ) {
F_105 ( & V_4 -> V_15 ) ;
return true ;
}
V_92 = F_264 ( V_4 , V_312 , V_248 << V_185 ) ;
if ( ! V_92 )
* V_314 = V_4 ;
F_105 ( & V_4 -> V_15 ) ;
return ( V_92 == 0 ) ;
}
void F_305 ( struct V_40 * V_40 , struct V_1 * V_4 ,
int V_185 )
{
struct V_141 * V_142 ;
F_39 ( F_19 ( V_4 ) ) ;
if ( ! V_40 ) {
F_266 ( V_4 , V_248 << V_185 ) ;
return;
}
V_142 = F_113 ( V_40 ) ;
F_242 ( V_142 ) ;
V_142 -> V_1 = V_4 ;
F_253 ( V_142 ) ;
F_246 ( V_142 ) ;
}
void F_306 ( struct V_40 * V_40 , int V_185 )
{
struct V_1 * V_4 = NULL ;
struct V_141 * V_142 ;
V_142 = F_113 ( V_40 ) ;
if ( ! F_115 ( V_142 ) )
return;
F_242 ( V_142 ) ;
if ( F_115 ( V_142 ) ) {
V_4 = V_142 -> V_1 ;
F_307 ( V_142 ) ;
}
F_246 ( V_142 ) ;
if ( ! V_4 )
return;
F_39 ( F_19 ( V_4 ) ) ;
F_266 ( V_4 , V_248 << V_185 ) ;
}
static inline void F_298 ( struct V_1 * V_4 )
{
}
void F_308 ( struct V_40 * V_346 )
{
struct V_141 * V_347 = F_113 ( V_346 ) ;
struct V_141 * V_142 ;
struct V_1 * V_4 ;
int V_174 ;
if ( F_100 () )
return;
V_4 = V_347 -> V_1 ;
for ( V_174 = 1 ; V_174 < V_348 ; V_174 ++ ) {
V_142 = V_347 + V_174 ;
V_142 -> V_1 = V_4 ;
F_106 () ;
V_142 -> V_168 = V_347 -> V_168 & ~ V_349 ;
}
F_309 ( V_4 -> V_71 -> V_72 [ V_83 ] ,
V_348 ) ;
}
static int F_310 ( struct V_40 * V_40 ,
unsigned int V_80 ,
struct V_141 * V_142 ,
struct V_1 * V_161 ,
struct V_1 * V_162 )
{
unsigned long V_168 ;
int V_92 ;
bool V_79 = F_311 ( V_40 ) ;
F_39 ( V_161 == V_162 ) ;
F_39 ( F_114 ( V_40 ) ) ;
V_92 = - V_350 ;
if ( V_80 > 1 && ! F_76 ( V_40 ) )
goto V_136;
F_242 ( V_142 ) ;
V_92 = - V_351 ;
if ( ! F_115 ( V_142 ) || V_142 -> V_1 != V_161 )
goto V_163;
F_143 ( V_161 , & V_168 ) ;
if ( ! V_79 && F_312 ( V_40 ) ) {
F_74 () ;
F_313 ( V_161 -> V_71 -> V_72 [ V_240 ] ) ;
F_77 ( V_162 -> V_71 -> V_72 [ V_240 ] ) ;
F_78 () ;
}
F_73 ( V_161 , V_40 , V_79 , - V_80 ) ;
V_142 -> V_1 = V_162 ;
F_73 ( V_162 , V_40 , V_79 , V_80 ) ;
F_145 ( V_161 , & V_168 ) ;
V_92 = 0 ;
V_163:
F_246 ( V_142 ) ;
F_89 ( V_162 , V_40 ) ;
F_89 ( V_161 , V_40 ) ;
V_136:
return V_92 ;
}
static int F_314 ( struct V_40 * V_40 ,
struct V_141 * V_142 ,
struct V_1 * V_352 )
{
struct V_1 * V_51 ;
unsigned int V_80 ;
unsigned long V_124 ( V_168 ) ;
int V_92 ;
F_39 ( F_19 ( V_352 ) ) ;
V_92 = - V_350 ;
if ( ! F_315 ( V_40 ) )
goto V_136;
if ( F_316 ( V_40 ) )
goto V_353;
V_80 = F_317 ( V_40 ) ;
V_51 = F_56 ( V_352 ) ;
if ( ! V_51 )
V_51 = V_17 ;
if ( V_80 > 1 ) {
F_39 ( ! F_76 ( V_40 ) ) ;
V_168 = F_318 ( V_40 ) ;
}
V_92 = F_310 ( V_40 , V_80 ,
V_142 , V_352 , V_51 ) ;
if ( ! V_92 )
F_236 ( V_352 , V_80 ) ;
if ( V_80 > 1 )
F_319 ( V_40 , V_168 ) ;
F_320 ( V_40 ) ;
V_353:
F_321 ( V_40 ) ;
V_136:
return V_92 ;
}
static int F_322 ( struct V_40 * V_40 , struct V_112 * V_113 ,
T_4 V_184 , enum V_291 V_292 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_80 = 1 ;
bool V_280 = true ;
int V_92 ;
if ( F_76 ( V_40 ) ) {
V_80 <<= F_323 ( V_40 ) ;
F_39 ( ! F_76 ( V_40 ) ) ;
V_280 = false ;
}
V_92 = F_233 ( V_113 , V_184 , V_80 , & V_4 , V_280 ) ;
if ( V_92 == - V_286 )
return V_92 ;
F_247 ( V_4 , V_40 , V_80 , V_292 , false ) ;
return 0 ;
}
int F_324 ( struct V_40 * V_40 ,
struct V_112 * V_113 , T_4 V_184 )
{
if ( F_100 () )
return 0 ;
F_39 ( F_312 ( V_40 ) ) ;
F_39 ( V_40 -> V_354 && ! F_311 ( V_40 ) ) ;
F_39 ( ! V_113 ) ;
return F_322 ( V_40 , V_113 , V_184 ,
V_296 ) ;
}
static int F_325 ( struct V_112 * V_113 ,
struct V_40 * V_40 ,
T_4 V_227 ,
struct V_1 * * V_355 )
{
struct V_1 * V_4 ;
struct V_141 * V_142 ;
int V_92 ;
V_142 = F_113 ( V_40 ) ;
if ( F_115 ( V_142 ) )
return 0 ;
if ( ! V_154 )
goto V_356;
V_4 = F_240 ( V_40 ) ;
if ( ! V_4 )
goto V_356;
* V_355 = V_4 ;
V_92 = F_233 ( NULL , V_227 , 1 , V_355 , true ) ;
F_105 ( & V_4 -> V_15 ) ;
if ( V_92 == - V_287 )
V_92 = 0 ;
return V_92 ;
V_356:
V_92 = F_233 ( V_113 , V_227 , 1 , V_355 , true ) ;
if ( V_92 == - V_287 )
V_92 = 0 ;
return V_92 ;
}
int F_326 ( struct V_112 * V_113 , struct V_40 * V_40 ,
T_4 V_184 , struct V_1 * * V_355 )
{
* V_355 = NULL ;
if ( F_100 () )
return 0 ;
if ( ! F_243 ( V_40 ) ) {
int V_92 ;
V_92 = F_233 ( V_113 , V_184 , 1 , V_355 , true ) ;
if ( V_92 == - V_287 )
V_92 = 0 ;
return V_92 ;
}
return F_325 ( V_113 , V_40 , V_184 , V_355 ) ;
}
void F_327 ( struct V_1 * V_4 )
{
if ( F_100 () )
return;
if ( ! V_4 )
return;
F_235 ( V_4 , 1 ) ;
}
static void
F_328 ( struct V_40 * V_40 , struct V_1 * V_4 ,
enum V_291 V_292 )
{
if ( F_100 () )
return;
if ( ! V_4 )
return;
F_247 ( V_4 , V_40 , 1 , V_292 , true ) ;
if ( V_154 && F_243 ( V_40 ) ) {
T_8 V_290 = { . V_69 = F_244 (page) } ;
F_329 ( V_290 ) ;
}
}
void F_330 ( struct V_40 * V_40 ,
struct V_1 * V_4 )
{
F_328 ( V_40 , V_4 ,
V_296 ) ;
}
int F_331 ( struct V_40 * V_40 , struct V_112 * V_113 ,
T_4 V_184 )
{
struct V_1 * V_4 = NULL ;
enum V_291 type = V_357 ;
int V_92 ;
if ( F_100 () )
return 0 ;
if ( F_332 ( V_40 ) )
return 0 ;
if ( ! F_243 ( V_40 ) )
V_92 = F_322 ( V_40 , V_113 , V_184 , type ) ;
else {
V_92 = F_325 ( V_113 , V_40 ,
V_184 , & V_4 ) ;
if ( ! V_92 )
F_328 ( V_40 , V_4 , type ) ;
}
return V_92 ;
}
static void F_333 ( struct V_1 * V_4 ,
unsigned int V_80 ,
const enum V_291 V_292 )
{
struct V_358 * V_281 = NULL ;
bool V_359 = true ;
if ( ! V_154 || V_292 == V_360 )
V_359 = false ;
V_281 = & V_26 -> V_361 ;
if ( ! V_281 -> V_4 )
V_281 -> V_4 = V_4 ;
if ( ! V_281 -> V_362 || F_199 ( V_191 ) )
goto V_363;
if ( V_80 > 1 )
goto V_363;
if ( V_281 -> V_4 != V_4 )
goto V_363;
V_281 -> V_80 ++ ;
if ( V_359 )
V_281 -> V_364 ++ ;
return;
V_363:
F_208 ( & V_4 -> V_60 , V_80 * V_248 ) ;
if ( V_359 )
F_208 ( & V_4 -> V_155 , V_80 * V_248 ) ;
if ( F_90 ( V_281 -> V_4 != V_4 ) )
F_195 ( V_4 ) ;
}
static struct V_1 *
F_334 ( struct V_40 * V_40 , enum V_291 V_292 ,
bool V_365 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_80 = 1 ;
struct V_141 * V_142 ;
bool V_79 ;
if ( F_100 () )
return NULL ;
if ( F_76 ( V_40 ) ) {
V_80 <<= F_323 ( V_40 ) ;
F_39 ( ! F_76 ( V_40 ) ) ;
}
V_142 = F_113 ( V_40 ) ;
if ( F_90 ( ! F_115 ( V_142 ) ) )
return NULL ;
F_242 ( V_142 ) ;
V_4 = V_142 -> V_1 ;
if ( ! F_115 ( V_142 ) )
goto V_366;
V_79 = F_311 ( V_40 ) ;
switch ( V_292 ) {
case V_296 :
V_79 = true ;
case V_367 :
if ( F_312 ( V_40 ) )
goto V_366;
if ( ! V_365 && F_335 ( V_142 ) )
goto V_366;
break;
case V_360 :
if ( ! F_311 ( V_40 ) ) {
if ( V_40 -> V_354 && ! F_336 ( V_40 ) )
goto V_366;
} else if ( F_312 ( V_40 ) )
goto V_366;
break;
default:
break;
}
F_73 ( V_4 , V_40 , V_79 , - V_80 ) ;
F_307 ( V_142 ) ;
F_246 ( V_142 ) ;
F_89 ( V_4 , V_40 ) ;
if ( V_154 && V_292 == V_360 ) {
F_70 ( V_4 , true ) ;
F_22 ( V_4 ) ;
}
if ( ! V_365 && ! F_19 ( V_4 ) )
F_333 ( V_4 , V_80 , V_292 ) ;
return V_4 ;
V_366:
F_246 ( V_142 ) ;
return NULL ;
}
void F_337 ( struct V_40 * V_40 )
{
if ( F_312 ( V_40 ) )
return;
F_39 ( V_40 -> V_354 && ! F_311 ( V_40 ) ) ;
if ( F_243 ( V_40 ) )
return;
F_334 ( V_40 , V_296 , false ) ;
}
void F_338 ( struct V_40 * V_40 )
{
F_39 ( F_312 ( V_40 ) ) ;
F_39 ( V_40 -> V_354 ) ;
F_334 ( V_40 , V_357 , false ) ;
}
void F_339 ( void )
{
V_26 -> V_361 . V_362 ++ ;
if ( V_26 -> V_361 . V_362 == 1 ) {
V_26 -> V_361 . V_4 = NULL ;
V_26 -> V_361 . V_80 = 0 ;
V_26 -> V_361 . V_364 = 0 ;
}
}
void F_340 ( void )
{
struct V_358 * V_281 = & V_26 -> V_361 ;
if ( ! V_281 -> V_362 )
return;
V_281 -> V_362 -- ;
if ( V_281 -> V_362 )
return;
if ( ! V_281 -> V_4 )
return;
if ( V_281 -> V_80 )
F_208 ( & V_281 -> V_4 -> V_60 ,
V_281 -> V_80 * V_248 ) ;
if ( V_281 -> V_364 )
F_208 ( & V_281 -> V_4 -> V_155 ,
V_281 -> V_364 * V_248 ) ;
F_195 ( V_281 -> V_4 ) ;
V_281 -> V_4 = NULL ;
}
void
F_341 ( struct V_40 * V_40 , T_8 V_290 , bool V_368 )
{
struct V_1 * V_4 ;
int V_292 = V_360 ;
if ( ! V_368 )
V_292 = V_367 ;
V_4 = F_334 ( V_40 , V_292 , false ) ;
if ( V_154 && V_368 && V_4 )
F_342 ( V_290 , F_343 ( & V_4 -> V_15 ) ) ;
}
void F_329 ( T_8 V_290 )
{
struct V_1 * V_4 ;
unsigned short V_288 ;
if ( ! V_154 )
return;
V_288 = F_342 ( V_290 , 0 ) ;
F_23 () ;
V_4 = F_238 ( V_288 ) ;
if ( V_4 ) {
if ( ! F_19 ( V_4 ) )
F_208 ( & V_4 -> V_155 , V_248 ) ;
F_70 ( V_4 , false ) ;
F_29 ( V_4 ) ;
}
F_26 () ;
}
static int F_344 ( T_8 V_369 ,
struct V_1 * V_161 , struct V_1 * V_162 )
{
unsigned short V_370 , V_371 ;
V_370 = F_343 ( & V_161 -> V_15 ) ;
V_371 = F_343 ( & V_162 -> V_15 ) ;
if ( F_345 ( V_369 , V_370 , V_371 ) == V_370 ) {
F_70 ( V_161 , false ) ;
F_70 ( V_162 , true ) ;
F_22 ( V_162 ) ;
return 0 ;
}
return - V_351 ;
}
static inline int F_344 ( T_8 V_369 ,
struct V_1 * V_161 , struct V_1 * V_162 )
{
return - V_351 ;
}
void F_346 ( struct V_40 * V_40 , struct V_40 * V_372 ,
struct V_1 * * V_355 )
{
struct V_1 * V_4 = NULL ;
unsigned int V_80 = 1 ;
struct V_141 * V_142 ;
enum V_291 V_292 ;
* V_355 = NULL ;
if ( F_100 () )
return;
if ( F_76 ( V_40 ) )
V_80 <<= F_323 ( V_40 ) ;
V_142 = F_113 ( V_40 ) ;
F_242 ( V_142 ) ;
if ( F_115 ( V_142 ) ) {
V_4 = V_142 -> V_1 ;
F_124 ( & V_4 -> V_15 ) ;
if ( F_311 ( V_40 ) )
F_347 ( V_142 ) ;
}
F_246 ( V_142 ) ;
if ( ! V_4 )
return;
* V_355 = V_4 ;
if ( F_311 ( V_40 ) )
V_292 = V_296 ;
else
V_292 = V_357 ;
F_247 ( V_4 , V_372 , V_80 , V_292 , false ) ;
}
void F_348 ( struct V_1 * V_4 ,
struct V_40 * V_373 , struct V_40 * V_372 , bool V_374 )
{
struct V_40 * V_375 , * V_376 ;
struct V_141 * V_142 ;
bool V_79 ;
if ( ! V_4 )
return;
if ( ! V_374 ) {
V_375 = V_373 ;
V_376 = V_372 ;
} else {
V_375 = V_372 ;
V_376 = V_373 ;
}
V_79 = F_311 ( V_375 ) ;
F_334 ( V_376 ,
V_79 ? V_296
: V_357 ,
true ) ;
F_105 ( & V_4 -> V_15 ) ;
V_142 = F_113 ( V_373 ) ;
F_242 ( V_142 ) ;
F_349 ( V_142 ) ;
F_246 ( V_142 ) ;
if ( V_79 )
F_337 ( V_375 ) ;
}
void F_350 ( struct V_40 * V_373 ,
struct V_40 * V_372 )
{
struct V_1 * V_4 = NULL ;
struct V_141 * V_142 ;
enum V_291 type = V_357 ;
if ( F_100 () )
return;
V_142 = F_113 ( V_373 ) ;
F_242 ( V_142 ) ;
if ( F_115 ( V_142 ) ) {
V_4 = V_142 -> V_1 ;
F_73 ( V_4 , V_373 , false , - 1 ) ;
F_307 ( V_142 ) ;
}
F_246 ( V_142 ) ;
if ( ! V_4 )
return;
F_247 ( V_4 , V_372 , 1 , type , true ) ;
}
static struct V_141 * F_351 ( struct V_40 * V_40 )
{
struct V_141 * V_142 ;
V_142 = F_113 ( V_40 ) ;
if ( F_230 ( V_142 ) && F_115 ( V_142 ) )
return V_142 ;
return NULL ;
}
bool F_352 ( struct V_40 * V_40 )
{
if ( F_100 () )
return false ;
return F_351 ( V_40 ) != NULL ;
}
void F_353 ( struct V_40 * V_40 )
{
struct V_141 * V_142 ;
V_142 = F_351 ( V_40 ) ;
if ( V_142 ) {
F_354 ( L_14 ,
V_142 , V_142 -> V_168 , V_142 -> V_1 ) ;
}
}
static int F_355 ( struct V_1 * V_4 ,
unsigned long long V_69 )
{
int V_377 ;
T_2 V_378 , V_379 ;
int V_92 = 0 ;
int V_380 = F_154 ( V_4 ) ;
T_2 V_381 , V_382 ;
int V_383 ;
V_377 = V_283 * V_380 ;
V_382 = F_36 ( & V_4 -> V_60 , V_33 ) ;
V_383 = 0 ;
while ( V_377 ) {
if ( F_356 ( V_26 ) ) {
V_92 = - V_287 ;
break;
}
F_224 ( & V_342 ) ;
V_378 = F_36 ( & V_4 -> V_155 , V_175 ) ;
if ( V_378 < V_69 ) {
V_92 = - V_351 ;
F_222 ( & V_342 ) ;
break;
}
V_379 = F_36 ( & V_4 -> V_60 , V_175 ) ;
if ( V_379 < V_69 )
V_383 = 1 ;
V_92 = F_357 ( & V_4 -> V_60 , V_69 ) ;
if ( ! V_92 ) {
if ( V_378 == V_69 )
V_4 -> V_204 = true ;
else
V_4 -> V_204 = false ;
}
F_222 ( & V_342 ) ;
if ( ! V_92 )
break;
F_168 ( V_4 , V_320 ,
V_203 ) ;
V_381 = F_36 ( & V_4 -> V_60 , V_33 ) ;
if ( V_381 >= V_382 )
V_377 -- ;
else
V_382 = V_381 ;
}
if ( ! V_92 && V_383 )
F_195 ( V_4 ) ;
return V_92 ;
}
static int F_358 ( struct V_1 * V_4 ,
unsigned long long V_69 )
{
int V_377 ;
T_2 V_379 , V_378 , V_382 , V_381 ;
int V_380 = F_154 ( V_4 ) ;
int V_92 = - V_350 ;
int V_383 = 0 ;
V_377 = V_380 * V_283 ;
V_382 = F_36 ( & V_4 -> V_155 , V_33 ) ;
while ( V_377 ) {
if ( F_356 ( V_26 ) ) {
V_92 = - V_287 ;
break;
}
F_224 ( & V_342 ) ;
V_379 = F_36 ( & V_4 -> V_60 , V_175 ) ;
if ( V_379 > V_69 ) {
V_92 = - V_351 ;
F_222 ( & V_342 ) ;
break;
}
V_378 = F_36 ( & V_4 -> V_155 , V_175 ) ;
if ( V_378 < V_69 )
V_383 = 1 ;
V_92 = F_357 ( & V_4 -> V_155 , V_69 ) ;
if ( ! V_92 ) {
if ( V_379 == V_69 )
V_4 -> V_204 = true ;
else
V_4 -> V_204 = false ;
}
F_222 ( & V_342 ) ;
if ( ! V_92 )
break;
F_168 ( V_4 , V_320 ,
V_202 |
V_203 ) ;
V_381 = F_36 ( & V_4 -> V_155 , V_33 ) ;
if ( V_381 >= V_382 )
V_377 -- ;
else
V_382 = V_381 ;
}
if ( ! V_92 && V_383 )
F_195 ( V_4 ) ;
return V_92 ;
}
unsigned long F_359 ( struct V_62 * V_62 , int V_185 ,
T_4 V_184 ,
unsigned long * V_213 )
{
unsigned long V_384 = 0 ;
struct V_34 * V_45 , * V_385 = NULL ;
unsigned long V_386 ;
int V_201 = 0 ;
struct V_41 * V_46 ;
unsigned long long V_59 ;
unsigned long V_215 ;
if ( V_185 > 0 )
return 0 ;
V_46 = F_44 ( F_101 ( V_62 ) , F_102 ( V_62 ) ) ;
do {
if ( V_385 )
V_45 = V_385 ;
else
V_45 = F_63 ( V_46 ) ;
if ( ! V_45 )
break;
V_215 = 0 ;
V_386 = F_184 ( V_45 -> V_4 , V_62 ,
V_184 , & V_215 ) ;
V_384 += V_386 ;
* V_213 += V_215 ;
F_53 ( & V_46 -> V_58 ) ;
V_385 = NULL ;
if ( ! V_386 ) {
do {
V_385 =
F_60 ( V_46 ) ;
if ( V_385 == V_45 )
F_105 ( & V_385 -> V_4 -> V_15 ) ;
else
break;
} while ( 1 );
}
F_50 ( V_45 -> V_4 , V_45 , V_46 ) ;
V_59 = F_57 ( & V_45 -> V_4 -> V_60 ) ;
F_46 ( V_45 -> V_4 , V_45 , V_46 , V_59 ) ;
F_54 ( & V_46 -> V_58 ) ;
F_105 ( & V_45 -> V_4 -> V_15 ) ;
V_201 ++ ;
if ( ! V_384 &&
( V_385 == NULL ||
V_201 > V_387 ) )
break;
} while ( ! V_384 );
if ( V_385 )
F_105 ( & V_385 -> V_4 -> V_15 ) ;
return V_384 ;
}
static void F_360 ( struct V_1 * V_4 ,
int V_61 , int V_36 , enum V_88 V_89 )
{
struct V_87 * V_87 ;
unsigned long V_168 ;
struct V_388 * V_317 ;
struct V_40 * V_389 ;
struct V_62 * V_62 ;
V_62 = & F_361 ( V_61 ) -> V_390 [ V_36 ] ;
V_87 = F_111 ( V_62 , V_4 ) ;
V_317 = & V_87 -> V_391 [ V_89 ] ;
V_389 = NULL ;
do {
struct V_141 * V_142 ;
struct V_40 * V_40 ;
F_144 ( & V_62 -> V_295 , V_168 ) ;
if ( F_362 ( V_317 ) ) {
F_146 ( & V_62 -> V_295 , V_168 ) ;
break;
}
V_40 = F_363 ( V_317 -> V_121 , struct V_40 , V_89 ) ;
if ( V_389 == V_40 ) {
F_364 ( & V_40 -> V_89 , V_317 ) ;
V_389 = NULL ;
F_146 ( & V_62 -> V_295 , V_168 ) ;
continue;
}
F_146 ( & V_62 -> V_295 , V_168 ) ;
V_142 = F_113 ( V_40 ) ;
if ( F_314 ( V_40 , V_142 , V_4 ) ) {
V_389 = V_40 ;
F_365 () ;
} else
V_389 = NULL ;
} while ( ! F_362 ( V_317 ) );
}
static void F_366 ( struct V_1 * V_4 )
{
int V_61 , V_36 ;
T_2 V_392 ;
do {
F_367 () ;
F_223 ( V_4 ) ;
F_131 ( V_4 ) ;
F_85 (node, N_MEMORY) {
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ ) {
enum V_88 V_89 ;
F_81 (lru) {
F_360 ( V_4 ,
V_61 , V_36 , V_89 ) ;
}
}
}
F_133 ( V_4 ) ;
F_195 ( V_4 ) ;
F_365 () ;
V_392 = F_36 ( & V_4 -> V_60 , V_33 ) -
F_36 ( & V_4 -> V_32 , V_33 ) ;
} while ( V_392 > 0 );
}
static inline bool F_368 ( struct V_1 * V_4 )
{
struct V_108 * V_393 ;
F_369 (pos, memcg->css.cgroup)
return true ;
return false ;
}
static inline bool F_370 ( struct V_1 * V_4 )
{
return V_4 -> V_126 && F_368 ( V_4 ) ;
}
static int F_371 ( struct V_1 * V_4 )
{
int V_394 = V_283 ;
struct V_108 * V_156 = V_4 -> V_15 . V_108 ;
if ( F_372 ( V_156 ) || ! F_362 ( & V_156 -> V_380 ) )
return - V_350 ;
F_367 () ;
while ( V_394 && F_36 ( & V_4 -> V_60 , V_33 ) > 0 ) {
int V_395 ;
if ( F_356 ( V_26 ) )
return - V_287 ;
V_395 = F_170 ( V_4 , V_320 ,
false ) ;
if ( ! V_395 ) {
V_394 -- ;
F_373 ( V_396 , V_397 / 10 ) ;
}
}
F_374 () ;
F_366 ( V_4 ) ;
return 0 ;
}
static int F_375 ( struct V_108 * V_109 , unsigned int V_398 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
int V_92 ;
if ( F_19 ( V_4 ) )
return - V_351 ;
F_124 ( & V_4 -> V_15 ) ;
V_92 = F_371 ( V_4 ) ;
F_105 ( & V_4 -> V_15 ) ;
return V_92 ;
}
static T_2 F_376 ( struct V_108 * V_109 , struct V_305 * V_306 )
{
return F_93 ( V_109 ) -> V_126 ;
}
static int F_377 ( struct V_108 * V_109 , struct V_305 * V_306 ,
T_2 V_69 )
{
int V_399 = 0 ;
struct V_1 * V_4 = F_93 ( V_109 ) ;
struct V_108 * V_51 = V_109 -> V_51 ;
struct V_1 * V_400 = NULL ;
if ( V_51 )
V_400 = F_93 ( V_51 ) ;
F_224 ( & V_401 ) ;
if ( V_4 -> V_126 == V_69 )
goto V_136;
if ( ( ! V_400 || ! V_400 -> V_126 ) &&
( V_69 == 1 || V_69 == 0 ) ) {
if ( ! F_368 ( V_4 ) )
V_4 -> V_126 = V_69 ;
else
V_399 = - V_350 ;
} else
V_399 = - V_351 ;
V_136:
F_222 ( & V_401 ) ;
return V_399 ;
}
static unsigned long F_378 ( struct V_1 * V_4 ,
enum V_67 V_68 )
{
struct V_1 * V_129 ;
long V_69 = 0 ;
F_152 (iter, memcg)
V_69 += F_64 ( V_129 , V_68 ) ;
if ( V_69 < 0 )
V_69 = 0 ;
return V_69 ;
}
static inline T_2 F_379 ( struct V_1 * V_4 , bool V_402 )
{
T_2 V_69 ;
if ( ! F_19 ( V_4 ) ) {
if ( ! V_402 )
return F_36 ( & V_4 -> V_60 , V_33 ) ;
else
return F_36 ( & V_4 -> V_155 , V_33 ) ;
}
V_69 = F_378 ( V_4 , V_82 ) ;
V_69 += F_378 ( V_4 , V_81 ) ;
if ( V_402 )
V_69 += F_378 ( V_4 , V_76 ) ;
return V_69 << V_152 ;
}
static T_9 F_380 ( struct V_108 * V_109 , struct V_305 * V_306 ,
struct V_403 * V_403 , char T_10 * V_404 ,
T_1 V_405 , T_11 * V_406 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
char V_407 [ 64 ] ;
T_2 V_69 ;
int V_333 , V_408 ;
enum V_409 type ;
type = F_381 ( V_306 -> V_232 ) ;
V_333 = F_382 ( V_306 -> V_232 ) ;
switch ( type ) {
case V_410 :
if ( V_333 == V_33 )
V_69 = F_379 ( V_4 , false ) ;
else
V_69 = F_36 ( & V_4 -> V_60 , V_333 ) ;
break;
case V_411 :
if ( V_333 == V_33 )
V_69 = F_379 ( V_4 , true ) ;
else
V_69 = F_36 ( & V_4 -> V_155 , V_333 ) ;
break;
case V_412 :
V_69 = F_36 ( & V_4 -> V_32 , V_333 ) ;
break;
default:
F_110 () ;
}
V_408 = F_383 ( V_407 , sizeof( V_407 ) , L_15 , ( unsigned long long ) V_69 ) ;
return F_384 ( V_404 , V_405 , V_406 , V_407 , V_408 ) ;
}
static int F_385 ( struct V_108 * V_109 , T_2 V_69 )
{
int V_92 = - V_351 ;
#ifdef F_386
struct V_1 * V_4 = F_93 ( V_109 ) ;
F_224 ( & V_401 ) ;
F_224 ( & V_342 ) ;
if ( ! V_4 -> V_6 && V_69 != V_413 ) {
if ( F_372 ( V_109 ) || F_370 ( V_4 ) ) {
V_92 = - V_350 ;
goto V_136;
}
V_92 = F_357 ( & V_4 -> V_32 , V_69 ) ;
F_39 ( V_92 ) ;
V_92 = F_269 ( V_4 ) ;
if ( V_92 ) {
F_357 ( & V_4 -> V_32 , V_413 ) ;
goto V_136;
}
F_387 ( & V_29 ) ;
F_2 ( V_4 ) ;
F_22 ( V_4 ) ;
} else
V_92 = F_357 ( & V_4 -> V_32 , V_69 ) ;
V_136:
F_222 ( & V_342 ) ;
F_222 ( & V_401 ) ;
#endif
return V_92 ;
}
static int F_388 ( struct V_1 * V_4 )
{
int V_92 = 0 ;
struct V_1 * V_51 = F_56 ( V_4 ) ;
if ( ! V_51 )
goto V_136;
V_4 -> V_6 = V_51 -> V_6 ;
if ( ! F_4 ( V_4 ) )
goto V_136;
F_22 ( V_4 ) ;
F_387 ( & V_29 ) ;
F_224 ( & V_342 ) ;
V_92 = F_269 ( V_4 ) ;
F_222 ( & V_342 ) ;
V_136:
return V_92 ;
}
static int F_389 ( struct V_108 * V_109 , struct V_305 * V_306 ,
const char * V_414 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
enum V_409 type ;
int V_333 ;
unsigned long long V_69 ;
int V_92 ;
type = F_381 ( V_306 -> V_232 ) ;
V_333 = F_382 ( V_306 -> V_232 ) ;
switch ( V_333 ) {
case V_175 :
if ( F_19 ( V_4 ) ) {
V_92 = - V_351 ;
break;
}
V_92 = F_390 ( V_414 , & V_69 ) ;
if ( V_92 )
break;
if ( type == V_410 )
V_92 = F_355 ( V_4 , V_69 ) ;
else if ( type == V_411 )
V_92 = F_358 ( V_4 , V_69 ) ;
else if ( type == V_412 )
V_92 = F_385 ( V_109 , V_69 ) ;
else
return - V_351 ;
break;
case V_415 :
V_92 = F_390 ( V_414 , & V_69 ) ;
if ( V_92 )
break;
if ( type == V_410 )
V_92 = F_391 ( & V_4 -> V_60 , V_69 ) ;
else
V_92 = - V_351 ;
break;
default:
V_92 = - V_351 ;
break;
}
return V_92 ;
}
static void F_392 ( struct V_1 * V_4 ,
unsigned long long * V_416 , unsigned long long * V_417 )
{
struct V_108 * V_108 ;
unsigned long long V_418 , V_419 , V_420 ;
V_418 = F_36 ( & V_4 -> V_60 , V_175 ) ;
V_419 = F_36 ( & V_4 -> V_155 , V_175 ) ;
V_108 = V_4 -> V_15 . V_108 ;
if ( ! V_4 -> V_126 )
goto V_136;
while ( V_108 -> V_51 ) {
V_108 = V_108 -> V_51 ;
V_4 = F_93 ( V_108 ) ;
if ( ! V_4 -> V_126 )
break;
V_420 = F_36 ( & V_4 -> V_60 , V_175 ) ;
V_418 = F_129 ( V_418 , V_420 ) ;
V_420 = F_36 ( & V_4 -> V_155 , V_175 ) ;
V_419 = F_129 ( V_419 , V_420 ) ;
}
V_136:
* V_416 = V_418 ;
* V_417 = V_419 ;
}
static int F_393 ( struct V_108 * V_109 , unsigned int V_398 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
int V_333 ;
enum V_409 type ;
type = F_381 ( V_398 ) ;
V_333 = F_382 ( V_398 ) ;
switch ( V_333 ) {
case V_421 :
if ( type == V_410 )
F_394 ( & V_4 -> V_60 ) ;
else if ( type == V_411 )
F_394 ( & V_4 -> V_155 ) ;
else if ( type == V_412 )
F_394 ( & V_4 -> V_32 ) ;
else
return - V_351 ;
break;
case V_176 :
if ( type == V_410 )
F_395 ( & V_4 -> V_60 ) ;
else if ( type == V_411 )
F_395 ( & V_4 -> V_155 ) ;
else if ( type == V_412 )
F_395 ( & V_4 -> V_32 ) ;
else
return - V_351 ;
break;
}
return 0 ;
}
static T_2 F_396 ( struct V_108 * V_156 ,
struct V_305 * V_306 )
{
return F_93 ( V_156 ) -> V_422 ;
}
static int F_397 ( struct V_108 * V_156 ,
struct V_305 * V_306 , T_2 V_69 )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
if ( V_69 >= ( 1 << V_423 ) )
return - V_351 ;
V_4 -> V_422 = V_69 ;
return 0 ;
}
static int F_397 ( struct V_108 * V_156 ,
struct V_305 * V_306 , T_2 V_69 )
{
return - V_424 ;
}
static int F_398 ( struct V_108 * V_109 , struct V_305 * V_306 ,
struct V_307 * V_308 )
{
int V_35 ;
unsigned long V_425 , V_426 , V_427 , V_428 ;
unsigned long V_429 ;
struct V_1 * V_4 = F_93 ( V_109 ) ;
V_425 = F_84 ( V_4 , V_430 ) ;
F_399 ( V_308 , L_16 , V_425 ) ;
F_85 (nid, N_MEMORY) {
V_429 = F_83 ( V_4 , V_35 , V_430 ) ;
F_399 ( V_308 , L_17 , V_35 , V_429 ) ;
}
F_400 ( V_308 , '\n' ) ;
V_426 = F_84 ( V_4 , V_206 ) ;
F_399 ( V_308 , L_18 , V_426 ) ;
F_85 (nid, N_MEMORY) {
V_429 = F_83 ( V_4 , V_35 ,
V_206 ) ;
F_399 ( V_308 , L_17 , V_35 , V_429 ) ;
}
F_400 ( V_308 , '\n' ) ;
V_427 = F_84 ( V_4 , V_207 ) ;
F_399 ( V_308 , L_19 , V_427 ) ;
F_85 (nid, N_MEMORY) {
V_429 = F_83 ( V_4 , V_35 ,
V_207 ) ;
F_399 ( V_308 , L_17 , V_35 , V_429 ) ;
}
F_400 ( V_308 , '\n' ) ;
V_428 = F_84 ( V_4 , F_82 ( V_431 ) ) ;
F_399 ( V_308 , L_20 , V_428 ) ;
F_85 (nid, N_MEMORY) {
V_429 = F_83 ( V_4 , V_35 ,
F_82 ( V_431 ) ) ;
F_399 ( V_308 , L_17 , V_35 , V_429 ) ;
}
F_400 ( V_308 , '\n' ) ;
return 0 ;
}
static inline void F_401 ( void )
{
F_402 ( F_403 ( V_180 ) != V_179 ) ;
}
static int F_404 ( struct V_108 * V_109 , struct V_305 * V_306 ,
struct V_307 * V_308 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
struct V_1 * V_432 ;
unsigned int V_174 ;
for ( V_174 = 0 ; V_174 < V_177 ; V_174 ++ ) {
if ( V_174 == V_76 && ! V_154 )
continue;
F_399 ( V_308 , L_21 , V_178 [ V_174 ] ,
F_64 ( V_4 , V_174 ) * V_248 ) ;
}
for ( V_174 = 0 ; V_174 < V_256 ; V_174 ++ )
F_399 ( V_308 , L_22 , V_433 [ V_174 ] ,
F_72 ( V_4 , V_174 ) ) ;
for ( V_174 = 0 ; V_174 < V_179 ; V_174 ++ )
F_399 ( V_308 , L_22 , V_180 [ V_174 ] ,
F_84 ( V_4 , F_82 ( V_174 ) ) * V_248 ) ;
{
unsigned long long V_182 , V_417 ;
F_392 ( V_4 , & V_182 , & V_417 ) ;
F_399 ( V_308 , L_23 , V_182 ) ;
if ( V_154 )
F_399 ( V_308 , L_24 ,
V_417 ) ;
}
for ( V_174 = 0 ; V_174 < V_177 ; V_174 ++ ) {
long long V_69 = 0 ;
if ( V_174 == V_76 && ! V_154 )
continue;
F_152 (mi, memcg)
V_69 += F_64 ( V_432 , V_174 ) * V_248 ;
F_399 ( V_308 , L_25 , V_178 [ V_174 ] , V_69 ) ;
}
for ( V_174 = 0 ; V_174 < V_256 ; V_174 ++ ) {
unsigned long long V_69 = 0 ;
F_152 (mi, memcg)
V_69 += F_72 ( V_432 , V_174 ) ;
F_399 ( V_308 , L_26 ,
V_433 [ V_174 ] , V_69 ) ;
}
for ( V_174 = 0 ; V_174 < V_179 ; V_174 ++ ) {
unsigned long long V_69 = 0 ;
F_152 (mi, memcg)
V_69 += F_84 ( V_432 , F_82 ( V_174 ) ) * V_248 ;
F_399 ( V_308 , L_26 , V_180 [ V_174 ] , V_69 ) ;
}
#ifdef F_405
{
int V_35 , V_36 ;
struct V_34 * V_45 ;
struct V_434 * V_435 ;
unsigned long V_436 [ 2 ] = { 0 , 0 } ;
unsigned long V_437 [ 2 ] = { 0 , 0 } ;
F_406 (nid)
for ( V_36 = 0 ; V_36 < V_63 ; V_36 ++ ) {
V_45 = F_38 ( V_4 , V_35 , V_36 ) ;
V_435 = & V_45 -> V_87 . V_438 ;
V_436 [ 0 ] += V_435 -> V_436 [ 0 ] ;
V_436 [ 1 ] += V_435 -> V_436 [ 1 ] ;
V_437 [ 0 ] += V_435 -> V_437 [ 0 ] ;
V_437 [ 1 ] += V_435 -> V_437 [ 1 ] ;
}
F_399 ( V_308 , L_27 , V_436 [ 0 ] ) ;
F_399 ( V_308 , L_28 , V_436 [ 1 ] ) ;
F_399 ( V_308 , L_29 , V_437 [ 0 ] ) ;
F_399 ( V_308 , L_30 , V_437 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_2 F_407 ( struct V_108 * V_156 , struct V_305 * V_306 )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
return F_130 ( V_4 ) ;
}
static int F_408 ( struct V_108 * V_156 , struct V_305 * V_306 ,
T_2 V_69 )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
struct V_1 * V_51 ;
if ( V_69 > 100 )
return - V_351 ;
if ( V_156 -> V_51 == NULL )
return - V_351 ;
V_51 = F_93 ( V_156 -> V_51 ) ;
F_224 ( & V_401 ) ;
if ( ( V_51 -> V_126 ) || F_370 ( V_4 ) ) {
F_222 ( & V_401 ) ;
return - V_351 ;
}
V_4 -> V_158 = V_69 ;
F_222 ( & V_401 ) ;
return 0 ;
}
static void F_409 ( struct V_1 * V_4 , bool V_402 )
{
struct V_439 * V_440 ;
T_2 V_392 ;
int V_174 ;
F_23 () ;
if ( ! V_402 )
V_440 = F_96 ( V_4 -> V_441 . V_442 ) ;
else
V_440 = F_96 ( V_4 -> V_443 . V_442 ) ;
if ( ! V_440 )
goto V_163;
V_392 = F_379 ( V_4 , V_402 ) ;
V_174 = V_440 -> V_444 ;
for (; V_174 >= 0 && F_90 ( V_440 -> V_445 [ V_174 ] . V_446 > V_392 ) ; V_174 -- )
F_410 ( V_440 -> V_445 [ V_174 ] . V_447 , 1 ) ;
V_174 ++ ;
for (; V_174 < V_440 -> V_313 && F_90 ( V_440 -> V_445 [ V_174 ] . V_446 <= V_392 ) ; V_174 ++ )
F_410 ( V_440 -> V_445 [ V_174 ] . V_447 , 1 ) ;
V_440 -> V_444 = V_174 - 1 ;
V_163:
F_26 () ;
}
static void F_91 ( struct V_1 * V_4 )
{
while ( V_4 ) {
F_409 ( V_4 , false ) ;
if ( V_154 )
F_409 ( V_4 , true ) ;
V_4 = F_56 ( V_4 ) ;
}
}
static int F_411 ( const void * V_448 , const void * V_449 )
{
const struct F_91 * V_450 = V_448 ;
const struct F_91 * V_451 = V_449 ;
return V_450 -> V_446 - V_451 -> V_446 ;
}
static int F_412 ( struct V_1 * V_4 )
{
struct V_452 * V_453 ;
F_262 (ev, &memcg->oom_notify, list)
F_410 ( V_453 -> V_447 , 1 ) ;
return 0 ;
}
static void F_198 ( struct V_1 * V_4 )
{
struct V_1 * V_129 ;
F_152 (iter, memcg)
F_412 ( V_129 ) ;
}
static int F_413 ( struct V_108 * V_156 ,
struct V_305 * V_306 , struct V_454 * V_447 , const char * args )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
struct V_455 * V_441 ;
struct V_439 * V_330 ;
enum V_409 type = F_381 ( V_306 -> V_232 ) ;
T_2 V_446 , V_392 ;
int V_174 , V_313 , V_92 ;
V_92 = F_390 ( args , & V_446 ) ;
if ( V_92 )
return V_92 ;
F_224 ( & V_4 -> V_456 ) ;
if ( type == V_410 )
V_441 = & V_4 -> V_441 ;
else if ( type == V_411 )
V_441 = & V_4 -> V_443 ;
else
F_110 () ;
V_392 = F_379 ( V_4 , type == V_411 ) ;
if ( V_441 -> V_442 )
F_409 ( V_4 , type == V_411 ) ;
V_313 = V_441 -> V_442 ? V_441 -> V_442 -> V_313 + 1 : 1 ;
V_330 = F_291 ( sizeof( * V_330 ) + V_313 * sizeof( struct F_91 ) ,
V_320 ) ;
if ( ! V_330 ) {
V_92 = - V_286 ;
goto V_163;
}
V_330 -> V_313 = V_313 ;
if ( V_441 -> V_442 ) {
memcpy ( V_330 -> V_445 , V_441 -> V_442 -> V_445 , ( V_313 - 1 ) *
sizeof( struct F_91 ) ) ;
}
V_330 -> V_445 [ V_313 - 1 ] . V_447 = V_447 ;
V_330 -> V_445 [ V_313 - 1 ] . V_446 = V_446 ;
F_414 ( V_330 -> V_445 , V_313 , sizeof( struct F_91 ) ,
F_411 , NULL ) ;
V_330 -> V_444 = - 1 ;
for ( V_174 = 0 ; V_174 < V_313 ; V_174 ++ ) {
if ( V_330 -> V_445 [ V_174 ] . V_446 <= V_392 ) {
++ V_330 -> V_444 ;
} else
break;
}
F_277 ( V_441 -> V_457 ) ;
V_441 -> V_457 = V_441 -> V_442 ;
F_415 ( V_441 -> V_442 , V_330 ) ;
F_132 () ;
V_163:
F_222 ( & V_4 -> V_456 ) ;
return V_92 ;
}
static void F_416 ( struct V_108 * V_156 ,
struct V_305 * V_306 , struct V_454 * V_447 )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
struct V_455 * V_441 ;
struct V_439 * V_330 ;
enum V_409 type = F_381 ( V_306 -> V_232 ) ;
T_2 V_392 ;
int V_174 , V_458 , V_313 ;
F_224 ( & V_4 -> V_456 ) ;
if ( type == V_410 )
V_441 = & V_4 -> V_441 ;
else if ( type == V_411 )
V_441 = & V_4 -> V_443 ;
else
F_110 () ;
if ( ! V_441 -> V_442 )
goto V_163;
V_392 = F_379 ( V_4 , type == V_411 ) ;
F_409 ( V_4 , type == V_411 ) ;
V_313 = 0 ;
for ( V_174 = 0 ; V_174 < V_441 -> V_442 -> V_313 ; V_174 ++ ) {
if ( V_441 -> V_442 -> V_445 [ V_174 ] . V_447 != V_447 )
V_313 ++ ;
}
V_330 = V_441 -> V_457 ;
if ( ! V_313 ) {
F_277 ( V_330 ) ;
V_330 = NULL ;
goto V_459;
}
V_330 -> V_313 = V_313 ;
V_330 -> V_444 = - 1 ;
for ( V_174 = 0 , V_458 = 0 ; V_174 < V_441 -> V_442 -> V_313 ; V_174 ++ ) {
if ( V_441 -> V_442 -> V_445 [ V_174 ] . V_447 == V_447 )
continue;
V_330 -> V_445 [ V_458 ] = V_441 -> V_442 -> V_445 [ V_174 ] ;
if ( V_330 -> V_445 [ V_458 ] . V_446 <= V_392 ) {
++ V_330 -> V_444 ;
}
V_458 ++ ;
}
V_459:
V_441 -> V_457 = V_441 -> V_442 ;
if ( ! V_330 ) {
F_277 ( V_441 -> V_457 ) ;
V_441 -> V_457 = NULL ;
}
F_415 ( V_441 -> V_442 , V_330 ) ;
F_132 () ;
V_163:
F_222 ( & V_4 -> V_456 ) ;
}
static int F_417 ( struct V_108 * V_156 ,
struct V_305 * V_306 , struct V_454 * V_447 , const char * args )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
struct V_452 * V_398 ;
enum V_409 type = F_381 ( V_306 -> V_232 ) ;
F_21 ( type != V_460 ) ;
V_398 = F_291 ( sizeof( * V_398 ) , V_320 ) ;
if ( ! V_398 )
return - V_286 ;
F_53 ( & V_234 ) ;
V_398 -> V_447 = V_447 ;
F_268 ( & V_398 -> V_317 , & V_4 -> V_461 ) ;
if ( F_103 ( & V_4 -> V_218 ) )
F_410 ( V_447 , 1 ) ;
F_54 ( & V_234 ) ;
return 0 ;
}
static void F_418 ( struct V_108 * V_156 ,
struct V_305 * V_306 , struct V_454 * V_447 )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
struct V_452 * V_453 , * V_420 ;
enum V_409 type = F_381 ( V_306 -> V_232 ) ;
F_21 ( type != V_460 ) ;
F_53 ( & V_234 ) ;
F_419 (ev, tmp, &memcg->oom_notify, list) {
if ( V_453 -> V_447 == V_447 ) {
F_281 ( & V_453 -> V_317 ) ;
F_277 ( V_453 ) ;
}
}
F_54 ( & V_234 ) ;
}
static int F_420 ( struct V_108 * V_156 ,
struct V_305 * V_306 , struct V_462 * V_463 )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
V_463 -> V_464 ( V_463 , L_31 , V_4 -> V_236 ) ;
if ( F_103 ( & V_4 -> V_218 ) )
V_463 -> V_464 ( V_463 , L_32 , 1 ) ;
else
V_463 -> V_464 ( V_463 , L_32 , 0 ) ;
return 0 ;
}
static int F_421 ( struct V_108 * V_156 ,
struct V_305 * V_306 , T_2 V_69 )
{
struct V_1 * V_4 = F_93 ( V_156 ) ;
struct V_1 * V_51 ;
if ( ! V_156 -> V_51 || ! ( ( V_69 == 0 ) || ( V_69 == 1 ) ) )
return - V_351 ;
V_51 = F_93 ( V_156 -> V_51 ) ;
F_224 ( & V_401 ) ;
if ( ( V_51 -> V_126 ) || F_370 ( V_4 ) ) {
F_222 ( & V_401 ) ;
return - V_351 ;
}
V_4 -> V_236 = V_69 ;
if ( ! V_69 )
F_195 ( V_4 ) ;
F_222 ( & V_401 ) ;
return 0 ;
}
static int F_422 ( struct V_1 * V_4 , struct V_465 * V_466 )
{
int V_92 ;
V_4 -> V_31 = - 1 ;
V_92 = F_388 ( V_4 ) ;
if ( V_92 )
return V_92 ;
return F_423 ( V_4 , V_466 ) ;
}
static void F_424 ( struct V_1 * V_4 )
{
F_425 ( V_4 ) ;
F_9 ( V_4 ) ;
if ( F_36 ( & V_4 -> V_32 , V_33 ) != 0 )
return;
if ( F_10 ( V_4 ) )
F_29 ( V_4 ) ;
}
static int F_422 ( struct V_1 * V_4 , struct V_465 * V_466 )
{
return 0 ;
}
static void F_424 ( struct V_1 * V_4 )
{
}
static int F_426 ( struct V_1 * V_4 , int V_61 )
{
struct V_3 * V_467 ;
struct V_34 * V_45 ;
int V_62 , V_420 = V_61 ;
if ( ! F_427 ( V_61 , V_468 ) )
V_420 = - 1 ;
V_467 = F_428 ( sizeof( * V_467 ) , V_320 , V_420 ) ;
if ( ! V_467 )
return 1 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_45 = & V_467 -> V_39 [ V_62 ] ;
F_429 ( & V_45 -> V_87 ) ;
V_45 -> V_54 = 0 ;
V_45 -> V_53 = false ;
V_45 -> V_4 = V_4 ;
}
V_4 -> V_37 . V_38 [ V_61 ] = V_467 ;
return 0 ;
}
static void F_430 ( struct V_1 * V_4 , int V_61 )
{
F_277 ( V_4 -> V_37 . V_38 [ V_61 ] ) ;
}
static struct V_1 * F_431 ( void )
{
struct V_1 * V_4 ;
T_1 V_313 = F_1 () ;
if ( V_313 < V_248 )
V_4 = F_276 ( V_313 , V_320 ) ;
else
V_4 = F_432 ( V_313 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_71 = F_433 ( struct V_469 ) ;
if ( ! V_4 -> V_71 )
goto V_470;
F_434 ( & V_4 -> V_73 ) ;
return V_4 ;
V_470:
if ( V_313 < V_248 )
F_277 ( V_4 ) ;
else
F_435 ( V_4 ) ;
return NULL ;
}
static void F_436 ( struct V_1 * V_4 )
{
int V_61 ;
T_1 V_313 = F_1 () ;
F_58 ( V_4 ) ;
F_437 ( & V_289 , & V_4 -> V_15 ) ;
F_59 (node)
F_430 ( V_4 , V_61 ) ;
F_438 ( V_4 -> V_71 ) ;
F_37 ( V_4 ) ;
if ( V_313 < V_248 )
F_277 ( V_4 ) ;
else
F_435 ( V_4 ) ;
}
static void F_439 ( struct V_249 * V_252 )
{
struct V_1 * V_4 ;
V_4 = F_15 ( V_252 , struct V_1 , V_471 ) ;
F_436 ( V_4 ) ;
}
static void F_440 ( struct V_472 * V_472 )
{
struct V_1 * V_4 ;
V_4 = F_15 ( V_472 , struct V_1 , V_473 ) ;
F_213 ( & V_4 -> V_471 , F_439 ) ;
F_288 ( & V_4 -> V_471 ) ;
}
static void F_22 ( struct V_1 * V_4 )
{
F_92 ( & V_4 -> V_474 ) ;
}
static void F_441 ( struct V_1 * V_4 , int V_72 )
{
if ( F_442 ( V_72 , & V_4 -> V_474 ) ) {
struct V_1 * V_51 = F_56 ( V_4 ) ;
F_443 ( & V_4 -> V_473 , F_440 ) ;
if ( V_51 )
F_29 ( V_51 ) ;
}
}
static void F_29 ( struct V_1 * V_4 )
{
F_441 ( V_4 , 1 ) ;
}
struct V_1 * F_56 ( struct V_1 * V_4 )
{
if ( ! V_4 -> V_60 . V_51 )
return NULL ;
return F_231 ( V_4 -> V_60 . V_51 , V_60 ) ;
}
static void T_6 F_444 ( void )
{
struct V_475 * V_476 ;
struct V_41 * V_477 ;
int V_420 , V_61 , V_62 ;
F_59 (node) {
V_420 = V_61 ;
if ( ! F_427 ( V_61 , V_468 ) )
V_420 = - 1 ;
V_476 = F_428 ( sizeof( * V_476 ) , V_320 , V_420 ) ;
F_21 ( ! V_476 ) ;
V_42 . V_43 [ V_61 ] = V_476 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
V_477 = & V_476 -> V_44 [ V_62 ] ;
V_477 -> V_50 = V_478 ;
F_434 ( & V_477 -> V_58 ) ;
}
}
}
static struct V_13 * T_12
F_445 ( struct V_108 * V_109 )
{
struct V_1 * V_4 ;
long error = - V_286 ;
int V_61 ;
V_4 = F_431 () ;
if ( ! V_4 )
return F_446 ( error ) ;
F_59 (node)
if ( F_426 ( V_4 , V_61 ) )
goto V_479;
if ( V_109 -> V_51 == NULL ) {
V_17 = V_4 ;
F_447 ( & V_4 -> V_60 , NULL ) ;
F_447 ( & V_4 -> V_155 , NULL ) ;
F_447 ( & V_4 -> V_32 , NULL ) ;
}
V_4 -> V_212 = V_106 ;
F_197 ( & V_4 -> V_461 ) ;
F_176 ( & V_4 -> V_474 , 1 ) ;
V_4 -> V_422 = 0 ;
F_272 ( & V_4 -> V_456 ) ;
F_434 ( & V_4 -> V_169 ) ;
F_448 ( & V_4 -> V_16 ) ;
return & V_4 -> V_15 ;
V_479:
F_436 ( V_4 ) ;
return F_446 ( error ) ;
}
static int
F_449 ( struct V_108 * V_109 )
{
struct V_1 * V_4 , * V_51 ;
int error = 0 ;
if ( ! V_109 -> V_51 )
return 0 ;
F_224 ( & V_401 ) ;
V_4 = F_93 ( V_109 ) ;
V_51 = F_93 ( V_109 -> V_51 ) ;
V_4 -> V_126 = V_51 -> V_126 ;
V_4 -> V_236 = V_51 -> V_236 ;
V_4 -> V_158 = F_130 ( V_51 ) ;
if ( V_51 -> V_126 ) {
F_447 ( & V_4 -> V_60 , & V_51 -> V_60 ) ;
F_447 ( & V_4 -> V_155 , & V_51 -> V_155 ) ;
F_447 ( & V_4 -> V_32 , & V_51 -> V_32 ) ;
F_22 ( V_51 ) ;
} else {
F_447 ( & V_4 -> V_60 , NULL ) ;
F_447 ( & V_4 -> V_155 , NULL ) ;
F_447 ( & V_4 -> V_32 , NULL ) ;
if ( V_51 != V_17 )
V_289 . V_480 = true ;
}
error = F_422 ( V_4 , & V_289 ) ;
F_222 ( & V_401 ) ;
if ( error ) {
F_29 ( V_4 ) ;
if ( V_51 -> V_126 )
F_29 ( V_51 ) ;
}
return error ;
}
static void F_450 ( struct V_1 * V_4 )
{
struct V_1 * V_51 = V_4 ;
while ( ( V_51 = F_56 ( V_51 ) ) )
F_92 ( & V_51 -> V_125 ) ;
if ( ! V_17 -> V_126 )
F_92 ( & V_17 -> V_125 ) ;
}
static void F_451 ( struct V_108 * V_109 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
F_450 ( V_4 ) ;
F_366 ( V_4 ) ;
F_298 ( V_4 ) ;
}
static void F_452 ( struct V_108 * V_109 )
{
struct V_1 * V_4 = F_93 ( V_109 ) ;
F_424 ( V_4 ) ;
F_29 ( V_4 ) ;
}
static int F_453 ( unsigned long V_72 )
{
int V_92 = 0 ;
int V_481 = V_482 ;
struct V_1 * V_4 = V_10 . V_162 ;
if ( F_19 ( V_4 ) ) {
V_10 . V_483 += V_72 ;
return V_92 ;
}
if ( V_72 > 1 ) {
struct V_269 * V_250 ;
if ( F_229 ( & V_4 -> V_60 , V_248 * V_72 , & V_250 ) )
goto V_484;
if ( V_154 && F_229 ( & V_4 -> V_155 ,
V_248 * V_72 , & V_250 ) ) {
F_208 ( & V_4 -> V_60 , V_248 * V_72 ) ;
goto V_484;
}
V_10 . V_483 += V_72 ;
return V_92 ;
}
V_484:
while ( V_72 -- ) {
if ( F_356 ( V_26 ) ) {
V_92 = - V_287 ;
break;
}
if ( ! V_481 -- ) {
V_481 = V_482 ;
F_365 () ;
}
V_92 = F_233 ( NULL ,
V_320 , 1 , & V_4 , false ) ;
if ( V_92 )
return V_92 ;
V_10 . V_483 ++ ;
}
return V_92 ;
}
static struct V_40 * F_454 ( struct V_485 * V_486 ,
unsigned long V_487 , T_13 V_488 )
{
struct V_40 * V_40 = F_455 ( V_486 , V_487 , V_488 ) ;
if ( ! V_40 || ! F_312 ( V_40 ) )
return NULL ;
if ( F_311 ( V_40 ) ) {
if ( ! F_12 () )
return NULL ;
} else if ( ! F_13 () )
return NULL ;
if ( ! F_315 ( V_40 ) )
return NULL ;
return V_40 ;
}
static struct V_40 * F_456 ( struct V_485 * V_486 ,
unsigned long V_487 , T_13 V_488 , T_8 * V_369 )
{
struct V_40 * V_40 = NULL ;
T_8 V_290 = F_457 ( V_488 ) ;
if ( ! F_12 () || F_458 ( V_290 ) )
return NULL ;
V_40 = F_459 ( F_460 ( V_290 ) , V_290 . V_69 ) ;
if ( V_154 )
V_369 -> V_69 = V_290 . V_69 ;
return V_40 ;
}
static struct V_40 * F_456 ( struct V_485 * V_486 ,
unsigned long V_487 , T_13 V_488 , T_8 * V_369 )
{
return NULL ;
}
static struct V_40 * F_461 ( struct V_485 * V_486 ,
unsigned long V_487 , T_13 V_488 , T_8 * V_369 )
{
struct V_40 * V_40 = NULL ;
struct V_489 * V_354 ;
T_14 V_490 ;
if ( ! V_486 -> V_491 )
return NULL ;
if ( ! F_13 () )
return NULL ;
V_354 = V_486 -> V_491 -> V_492 ;
if ( F_462 ( V_488 ) )
V_490 = F_463 ( V_486 , V_487 ) ;
else
V_490 = F_464 ( V_488 ) ;
V_40 = F_459 ( V_354 , V_490 ) ;
#ifdef F_465
if ( F_466 ( V_40 ) ) {
T_8 V_402 = F_467 ( V_40 ) ;
if ( V_154 )
* V_369 = V_402 ;
V_40 = F_459 ( F_460 ( V_402 ) , V_402 . V_69 ) ;
}
#endif
return V_40 ;
}
static enum V_493 F_468 ( struct V_485 * V_486 ,
unsigned long V_487 , T_13 V_488 , union V_494 * V_95 )
{
struct V_40 * V_40 = NULL ;
struct V_141 * V_142 ;
enum V_493 V_92 = V_495 ;
T_8 V_290 = { . V_69 = 0 } ;
if ( F_469 ( V_488 ) )
V_40 = F_454 ( V_486 , V_487 , V_488 ) ;
else if ( F_470 ( V_488 ) )
V_40 = F_456 ( V_486 , V_487 , V_488 , & V_290 ) ;
else if ( F_462 ( V_488 ) || F_471 ( V_488 ) )
V_40 = F_461 ( V_486 , V_487 , V_488 , & V_290 ) ;
if ( ! V_40 && ! V_290 . V_69 )
return V_92 ;
if ( V_40 ) {
V_142 = F_113 ( V_40 ) ;
if ( F_115 ( V_142 ) && V_142 -> V_1 == V_10 . V_161 ) {
V_92 = V_496 ;
if ( V_95 )
V_95 -> V_40 = V_40 ;
}
if ( ! V_92 || ! V_95 )
F_321 ( V_40 ) ;
}
if ( V_290 . V_69 && ! V_92 &&
F_343 ( & V_10 . V_161 -> V_15 ) == F_245 ( V_290 ) ) {
V_92 = V_497 ;
if ( V_95 )
V_95 -> V_290 = V_290 ;
}
return V_92 ;
}
static enum V_493 F_472 ( struct V_485 * V_486 ,
unsigned long V_487 , T_15 V_498 , union V_494 * V_95 )
{
struct V_40 * V_40 = NULL ;
struct V_141 * V_142 ;
enum V_493 V_92 = V_495 ;
V_40 = F_473 ( V_498 ) ;
F_39 ( ! V_40 || ! F_474 ( V_40 ) ) ;
if ( ! F_12 () )
return V_92 ;
V_142 = F_113 ( V_40 ) ;
if ( F_115 ( V_142 ) && V_142 -> V_1 == V_10 . V_161 ) {
V_92 = V_496 ;
if ( V_95 ) {
F_475 ( V_40 ) ;
V_95 -> V_40 = V_40 ;
}
}
return V_92 ;
}
static inline enum V_493 F_472 ( struct V_485 * V_486 ,
unsigned long V_487 , T_15 V_498 , union V_494 * V_95 )
{
return V_495 ;
}
static int F_476 ( T_15 * V_498 ,
unsigned long V_487 , unsigned long V_499 ,
struct V_500 * V_501 )
{
struct V_485 * V_486 = V_501 -> V_232 ;
T_13 * V_502 ;
T_16 * V_503 ;
if ( F_477 ( V_498 , V_486 ) == 1 ) {
if ( F_472 ( V_486 , V_487 , * V_498 , NULL ) == V_496 )
V_10 . V_483 += V_348 ;
F_54 ( & V_486 -> V_504 -> V_505 ) ;
return 0 ;
}
if ( F_478 ( V_498 ) )
return 0 ;
V_502 = F_479 ( V_486 -> V_504 , V_498 , V_487 , & V_503 ) ;
for (; V_487 != V_499 ; V_502 ++ , V_487 += V_248 )
if ( F_468 ( V_486 , V_487 , * V_502 , NULL ) )
V_10 . V_483 ++ ;
F_480 ( V_502 - 1 , V_503 ) ;
F_365 () ;
return 0 ;
}
static unsigned long F_481 ( struct V_112 * V_113 )
{
unsigned long V_483 ;
struct V_485 * V_486 ;
F_482 ( & V_113 -> V_506 ) ;
for ( V_486 = V_113 -> V_507 ; V_486 ; V_486 = V_486 -> V_508 ) {
struct V_500 V_509 = {
. V_510 = F_476 ,
. V_113 = V_113 ,
. V_232 = V_486 ,
} ;
if ( F_483 ( V_486 ) )
continue;
F_484 ( V_486 -> V_511 , V_486 -> V_512 ,
& V_509 ) ;
}
F_485 ( & V_113 -> V_506 ) ;
V_483 = V_10 . V_483 ;
V_10 . V_483 = 0 ;
return V_483 ;
}
static int F_486 ( struct V_112 * V_113 )
{
unsigned long V_483 = F_481 ( V_113 ) ;
F_39 ( V_10 . V_164 ) ;
V_10 . V_164 = V_26 ;
return F_453 ( V_483 ) ;
}
static void F_487 ( void )
{
struct V_1 * V_161 = V_10 . V_161 ;
struct V_1 * V_162 = V_10 . V_162 ;
if ( V_10 . V_483 ) {
F_235 ( V_10 . V_162 , V_10 . V_483 ) ;
V_10 . V_483 = 0 ;
}
if ( V_10 . V_513 ) {
F_235 ( V_10 . V_161 , V_10 . V_513 ) ;
V_10 . V_513 = 0 ;
}
if ( V_10 . V_514 ) {
if ( ! F_19 ( V_10 . V_161 ) )
F_208 ( & V_10 . V_161 -> V_155 ,
V_248 * V_10 . V_514 ) ;
F_441 ( V_10 . V_161 , V_10 . V_514 ) ;
if ( ! F_19 ( V_10 . V_162 ) ) {
F_208 ( & V_10 . V_162 -> V_60 ,
V_248 * V_10 . V_514 ) ;
}
V_10 . V_514 = 0 ;
}
F_195 ( V_161 ) ;
F_195 ( V_162 ) ;
F_488 ( & V_10 . V_166 ) ;
}
static void F_489 ( void )
{
struct V_1 * V_161 = V_10 . V_161 ;
V_10 . V_164 = NULL ;
F_487 () ;
F_53 ( & V_10 . V_58 ) ;
V_10 . V_161 = NULL ;
V_10 . V_162 = NULL ;
F_54 ( & V_10 . V_58 ) ;
F_133 ( V_161 ) ;
}
static int F_490 ( struct V_108 * V_108 ,
struct V_515 * V_516 )
{
struct V_111 * V_49 = F_491 ( V_516 ) ;
int V_92 = 0 ;
struct V_1 * V_4 = F_93 ( V_108 ) ;
unsigned long V_422 ;
V_422 = V_4 -> V_422 ;
if ( V_422 ) {
struct V_112 * V_113 ;
struct V_1 * V_161 = F_24 ( V_49 ) ;
F_39 ( V_161 == V_4 ) ;
V_113 = F_492 ( V_49 ) ;
if ( ! V_113 )
return 0 ;
if ( V_113 -> V_114 == V_49 ) {
F_39 ( V_10 . V_161 ) ;
F_39 ( V_10 . V_162 ) ;
F_39 ( V_10 . V_483 ) ;
F_39 ( V_10 . V_513 ) ;
F_39 ( V_10 . V_514 ) ;
F_131 ( V_161 ) ;
F_53 ( & V_10 . V_58 ) ;
V_10 . V_161 = V_161 ;
V_10 . V_162 = V_4 ;
V_10 . V_11 = V_422 ;
F_54 ( & V_10 . V_58 ) ;
V_92 = F_486 ( V_113 ) ;
if ( V_92 )
F_489 () ;
}
F_493 ( V_113 ) ;
}
return V_92 ;
}
static void F_494 ( struct V_108 * V_108 ,
struct V_515 * V_516 )
{
F_489 () ;
}
static int F_495 ( T_15 * V_498 ,
unsigned long V_487 , unsigned long V_499 ,
struct V_500 * V_501 )
{
int V_92 = 0 ;
struct V_485 * V_486 = V_501 -> V_232 ;
T_13 * V_502 ;
T_16 * V_503 ;
enum V_493 V_517 ;
union V_494 V_95 ;
struct V_40 * V_40 ;
struct V_141 * V_142 ;
if ( F_477 ( V_498 , V_486 ) == 1 ) {
if ( V_10 . V_483 < V_348 ) {
F_54 ( & V_486 -> V_504 -> V_505 ) ;
return 0 ;
}
V_517 = F_472 ( V_486 , V_487 , * V_498 , & V_95 ) ;
if ( V_517 == V_496 ) {
V_40 = V_95 . V_40 ;
if ( ! F_316 ( V_40 ) ) {
V_142 = F_113 ( V_40 ) ;
if ( ! F_310 ( V_40 , V_348 ,
V_142 , V_10 . V_161 , V_10 . V_162 ) ) {
V_10 . V_483 -= V_348 ;
V_10 . V_513 += V_348 ;
}
F_320 ( V_40 ) ;
}
F_321 ( V_40 ) ;
}
F_54 ( & V_486 -> V_504 -> V_505 ) ;
return 0 ;
}
if ( F_478 ( V_498 ) )
return 0 ;
V_65:
V_502 = F_479 ( V_486 -> V_504 , V_498 , V_487 , & V_503 ) ;
for (; V_487 != V_499 ; V_487 += V_248 ) {
T_13 V_488 = * ( V_502 ++ ) ;
T_8 V_290 ;
if ( ! V_10 . V_483 )
break;
switch ( F_468 ( V_486 , V_487 , V_488 , & V_95 ) ) {
case V_496 :
V_40 = V_95 . V_40 ;
if ( F_316 ( V_40 ) )
goto V_353;
V_142 = F_113 ( V_40 ) ;
if ( ! F_310 ( V_40 , 1 , V_142 ,
V_10 . V_161 , V_10 . V_162 ) ) {
V_10 . V_483 -- ;
V_10 . V_513 ++ ;
}
F_320 ( V_40 ) ;
V_353:
F_321 ( V_40 ) ;
break;
case V_497 :
V_290 = V_95 . V_290 ;
if ( ! F_344 ( V_290 , V_10 . V_161 , V_10 . V_162 ) ) {
V_10 . V_483 -- ;
V_10 . V_514 ++ ;
}
break;
default:
break;
}
}
F_480 ( V_502 - 1 , V_503 ) ;
F_365 () ;
if ( V_487 != V_499 ) {
V_92 = F_453 ( 1 ) ;
if ( ! V_92 )
goto V_65;
}
return V_92 ;
}
static void F_496 ( struct V_112 * V_113 )
{
struct V_485 * V_486 ;
F_367 () ;
V_65:
if ( F_90 ( ! F_497 ( & V_113 -> V_506 ) ) ) {
F_487 () ;
F_365 () ;
goto V_65;
}
for ( V_486 = V_113 -> V_507 ; V_486 ; V_486 = V_486 -> V_508 ) {
int V_92 ;
struct V_500 V_518 = {
. V_510 = F_495 ,
. V_113 = V_113 ,
. V_232 = V_486 ,
} ;
if ( F_483 ( V_486 ) )
continue;
V_92 = F_484 ( V_486 -> V_511 , V_486 -> V_512 ,
& V_518 ) ;
if ( V_92 )
break;
}
F_485 ( & V_113 -> V_506 ) ;
}
static void F_498 ( struct V_108 * V_109 ,
struct V_515 * V_516 )
{
struct V_111 * V_49 = F_491 ( V_516 ) ;
struct V_112 * V_113 = F_492 ( V_49 ) ;
if ( V_113 ) {
if ( V_10 . V_162 )
F_496 ( V_113 ) ;
F_493 ( V_113 ) ;
}
if ( V_10 . V_162 )
F_489 () ;
}
static int F_490 ( struct V_108 * V_108 ,
struct V_515 * V_516 )
{
return 0 ;
}
static void F_494 ( struct V_108 * V_108 ,
struct V_515 * V_516 )
{
}
static void F_498 ( struct V_108 * V_109 ,
struct V_515 * V_516 )
{
}
static void F_499 ( struct V_108 * V_115 )
{
if ( F_500 ( V_115 ) )
F_93 ( V_115 ) -> V_126 = true ;
}
static int T_6 F_501 ( char * V_14 )
{
if ( ! strcmp ( V_14 , L_33 ) )
V_519 = 1 ;
else if ( ! strcmp ( V_14 , L_34 ) )
V_519 = 0 ;
return 1 ;
}
static void T_6 F_502 ( void )
{
F_28 ( F_503 ( & V_289 , V_520 ) ) ;
}
static void T_6 F_504 ( void )
{
if ( ! F_100 () && V_519 ) {
V_154 = 1 ;
F_502 () ;
}
}
static void T_6 F_504 ( void )
{
}
static int T_6 F_505 ( void )
{
F_506 ( F_226 , 0 ) ;
F_504 () ;
F_444 () ;
F_211 () ;
return 0 ;
}
