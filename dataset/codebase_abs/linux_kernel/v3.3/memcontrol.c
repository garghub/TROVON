static bool F_1 ( void )
{
return F_2 ( V_1 ,
& V_2 . V_3 -> V_4 ) ;
}
static bool F_3 ( void )
{
return F_2 ( V_5 ,
& V_2 . V_3 -> V_4 ) ;
}
void F_4 ( struct V_6 * V_7 )
{
if ( V_8 ) {
struct V_9 * V_10 ;
F_5 ( ! V_7 -> V_11 -> V_12 ) ;
if ( V_7 -> V_13 ) {
F_5 ( F_6 ( V_7 -> V_13 -> V_10 ) ) ;
F_7 ( V_7 -> V_13 -> V_10 ) ;
return;
}
F_8 () ;
V_10 = F_9 ( V_14 ) ;
if ( ! F_6 ( V_10 ) ) {
F_7 ( V_10 ) ;
V_7 -> V_13 = V_7 -> V_11 -> V_12 ( V_10 ) ;
}
F_10 () ;
}
}
void F_11 ( struct V_6 * V_7 )
{
if ( V_8 && V_7 -> V_13 ) {
struct V_9 * V_10 ;
F_12 ( ! V_7 -> V_13 -> V_10 ) ;
V_10 = V_7 -> V_13 -> V_10 ;
F_13 ( V_10 ) ;
}
}
struct V_15 * F_14 ( struct V_9 * V_10 )
{
if ( ! V_10 || F_6 ( V_10 ) )
return NULL ;
return & V_10 -> V_16 . V_15 ;
}
static struct V_17 *
F_15 ( struct V_9 * V_10 , int V_18 , int V_19 )
{
return & V_10 -> V_20 . V_21 [ V_18 ] -> V_22 [ V_19 ] ;
}
struct V_23 * F_16 ( struct V_9 * V_10 )
{
return & V_10 -> V_24 ;
}
static struct V_17 *
F_17 ( struct V_9 * V_10 , struct V_25 * V_25 )
{
int V_18 = F_18 ( V_25 ) ;
int V_19 = F_19 ( V_25 ) ;
return F_15 ( V_10 , V_18 , V_19 ) ;
}
static struct V_26 *
F_20 ( int V_18 , int V_19 )
{
return & V_27 . V_28 [ V_18 ] -> V_29 [ V_19 ] ;
}
static struct V_26 *
F_21 ( struct V_25 * V_25 )
{
int V_18 = F_18 ( V_25 ) ;
int V_19 = F_19 ( V_25 ) ;
return & V_27 . V_28 [ V_18 ] -> V_29 [ V_19 ] ;
}
static void
F_22 ( struct V_9 * V_10 ,
struct V_17 * V_30 ,
struct V_26 * V_31 ,
unsigned long long V_32 )
{
struct V_33 * * V_34 = & V_31 -> V_35 . V_33 ;
struct V_33 * V_36 = NULL ;
struct V_17 * V_37 ;
if ( V_30 -> V_38 )
return;
V_30 -> V_39 = V_32 ;
if ( ! V_30 -> V_39 )
return;
while ( * V_34 ) {
V_36 = * V_34 ;
V_37 = F_23 ( V_36 , struct V_17 ,
V_40 ) ;
if ( V_30 -> V_39 < V_37 -> V_39 )
V_34 = & ( * V_34 ) -> V_41 ;
else if ( V_30 -> V_39 >= V_37 -> V_39 )
V_34 = & ( * V_34 ) -> V_42 ;
}
F_24 ( & V_30 -> V_40 , V_36 , V_34 ) ;
F_25 ( & V_30 -> V_40 , & V_31 -> V_35 ) ;
V_30 -> V_38 = true ;
}
static void
F_26 ( struct V_9 * V_10 ,
struct V_17 * V_30 ,
struct V_26 * V_31 )
{
if ( ! V_30 -> V_38 )
return;
F_27 ( & V_30 -> V_40 , & V_31 -> V_35 ) ;
V_30 -> V_38 = false ;
}
static void
F_28 ( struct V_9 * V_10 ,
struct V_17 * V_30 ,
struct V_26 * V_31 )
{
F_29 ( & V_31 -> V_43 ) ;
F_26 ( V_10 , V_30 , V_31 ) ;
F_30 ( & V_31 -> V_43 ) ;
}
static void F_31 ( struct V_9 * V_10 , struct V_25 * V_25 )
{
unsigned long long V_44 ;
struct V_17 * V_30 ;
struct V_26 * V_31 ;
int V_18 = F_18 ( V_25 ) ;
int V_19 = F_19 ( V_25 ) ;
V_31 = F_21 ( V_25 ) ;
for (; V_10 ; V_10 = F_32 ( V_10 ) ) {
V_30 = F_15 ( V_10 , V_18 , V_19 ) ;
V_44 = F_33 ( & V_10 -> V_45 ) ;
if ( V_44 || V_30 -> V_38 ) {
F_29 ( & V_31 -> V_43 ) ;
if ( V_30 -> V_38 )
F_26 ( V_10 , V_30 , V_31 ) ;
F_22 ( V_10 , V_30 , V_31 , V_44 ) ;
F_30 ( & V_31 -> V_43 ) ;
}
}
}
static void F_34 ( struct V_9 * V_10 )
{
int V_46 , V_47 ;
struct V_17 * V_30 ;
struct V_26 * V_31 ;
F_35 (node) {
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_30 = F_15 ( V_10 , V_46 , V_47 ) ;
V_31 = F_20 ( V_46 , V_47 ) ;
F_28 ( V_10 , V_30 , V_31 ) ;
}
}
}
static struct V_17 *
F_36 ( struct V_26 * V_31 )
{
struct V_33 * V_49 = NULL ;
struct V_17 * V_30 ;
V_50:
V_30 = NULL ;
V_49 = F_37 ( & V_31 -> V_35 ) ;
if ( ! V_49 )
goto V_51;
V_30 = F_23 ( V_49 , struct V_17 , V_40 ) ;
F_26 ( V_30 -> V_52 , V_30 , V_31 ) ;
if ( ! F_33 ( & V_30 -> V_52 -> V_45 ) ||
! F_38 ( & V_30 -> V_52 -> V_24 ) )
goto V_50;
V_51:
return V_30 ;
}
static struct V_17 *
F_39 ( struct V_26 * V_31 )
{
struct V_17 * V_30 ;
F_29 ( & V_31 -> V_43 ) ;
V_30 = F_36 ( V_31 ) ;
F_30 ( & V_31 -> V_43 ) ;
return V_30 ;
}
static long F_40 ( struct V_9 * V_10 ,
enum V_53 V_54 )
{
long V_55 = 0 ;
int V_56 ;
F_41 () ;
F_42 (cpu)
V_55 += F_43 ( V_10 -> V_57 -> V_58 [ V_54 ] , V_56 ) ;
#ifdef F_44
F_29 ( & V_10 -> V_59 ) ;
V_55 += V_10 -> V_60 . V_58 [ V_54 ] ;
F_30 ( & V_10 -> V_59 ) ;
#endif
F_45 () ;
return V_55 ;
}
static void F_46 ( struct V_9 * V_10 ,
bool V_61 )
{
int V_55 = ( V_61 ) ? 1 : - 1 ;
F_47 ( V_10 -> V_57 -> V_58 [ V_62 ] , V_55 ) ;
}
static unsigned long F_48 ( struct V_9 * V_10 ,
enum V_63 V_54 )
{
unsigned long V_55 = 0 ;
int V_56 ;
F_42 (cpu)
V_55 += F_43 ( V_10 -> V_57 -> V_64 [ V_54 ] , V_56 ) ;
#ifdef F_44
F_29 ( & V_10 -> V_59 ) ;
V_55 += V_10 -> V_60 . V_64 [ V_54 ] ;
F_30 ( & V_10 -> V_59 ) ;
#endif
return V_55 ;
}
static void F_49 ( struct V_9 * V_10 ,
bool V_65 , int V_66 )
{
F_50 () ;
if ( V_65 )
F_51 ( V_10 -> V_57 -> V_58 [ V_67 ] ,
V_66 ) ;
else
F_51 ( V_10 -> V_57 -> V_58 [ V_68 ] ,
V_66 ) ;
if ( V_66 > 0 )
F_52 ( V_10 -> V_57 -> V_64 [ V_69 ] ) ;
else {
F_52 ( V_10 -> V_57 -> V_64 [ V_70 ] ) ;
V_66 = - V_66 ;
}
F_51 ( V_10 -> V_57 -> V_64 [ V_71 ] , V_66 ) ;
F_53 () ;
}
unsigned long
F_54 ( struct V_9 * V_10 , int V_18 , int V_19 ,
unsigned int V_72 )
{
struct V_17 * V_30 ;
enum V_73 V_74 ;
unsigned long V_75 = 0 ;
V_30 = F_15 ( V_10 , V_18 , V_19 ) ;
F_55 (l) {
if ( F_56 ( V_74 ) & V_72 )
V_75 += F_57 ( V_30 , V_74 ) ;
}
return V_75 ;
}
static unsigned long
F_58 ( struct V_9 * V_10 ,
int V_18 , unsigned int V_72 )
{
T_1 V_76 = 0 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < V_48 ; V_19 ++ )
V_76 += F_54 ( V_10 ,
V_18 , V_19 , V_72 ) ;
return V_76 ;
}
static unsigned long F_59 ( struct V_9 * V_10 ,
unsigned int V_72 )
{
int V_18 ;
T_1 V_76 = 0 ;
F_60 (nid, N_HIGH_MEMORY)
V_76 += F_58 ( V_10 , V_18 , V_72 ) ;
return V_76 ;
}
static bool F_61 ( struct V_9 * V_10 ,
enum V_77 V_78 )
{
unsigned long V_55 , V_79 ;
V_55 = F_62 ( V_10 -> V_57 -> V_64 [ V_71 ] ) ;
V_79 = F_62 ( V_10 -> V_57 -> V_80 [ V_78 ] ) ;
if ( ( long ) V_79 - ( long ) V_55 < 0 ) {
switch ( V_78 ) {
case V_81 :
V_79 = V_55 + V_82 ;
break;
case V_83 :
V_79 = V_55 + V_84 ;
break;
case V_85 :
V_79 = V_55 + V_86 ;
break;
default:
break;
}
F_63 ( V_10 -> V_57 -> V_80 [ V_78 ] , V_79 ) ;
return true ;
}
return false ;
}
static void F_64 ( struct V_9 * V_10 , struct V_25 * V_25 )
{
F_50 () ;
if ( F_65 ( F_61 ( V_10 ,
V_81 ) ) ) {
bool V_87 ;
bool T_2 V_88 ;
V_87 = F_61 ( V_10 ,
V_83 ) ;
#if V_89 > 1
T_2 = F_61 ( V_10 ,
V_85 ) ;
#endif
F_53 () ;
F_66 ( V_10 ) ;
if ( F_65 ( V_87 ) )
F_31 ( V_10 , V_25 ) ;
#if V_89 > 1
if ( F_65 ( T_2 ) )
F_67 ( & V_10 -> V_90 ) ;
#endif
} else
F_53 () ;
}
struct V_9 * F_68 ( struct V_91 * V_92 )
{
return F_69 ( V_23 ( V_92 ,
V_93 ) , struct V_9 ,
V_24 ) ;
}
struct V_9 * F_9 ( struct V_94 * V_34 )
{
if ( F_65 ( ! V_34 ) )
return NULL ;
return F_69 ( F_70 ( V_34 , V_93 ) ,
struct V_9 , V_24 ) ;
}
struct V_9 * F_71 ( struct V_95 * V_96 )
{
struct V_9 * V_10 = NULL ;
if ( ! V_96 )
return NULL ;
F_8 () ;
do {
V_10 = F_9 ( F_72 ( V_96 -> V_97 ) ) ;
if ( F_65 ( ! V_10 ) )
break;
} while ( ! F_38 ( & V_10 -> V_24 ) );
F_10 () ;
return V_10 ;
}
struct V_9 * F_73 ( struct V_9 * V_98 ,
struct V_9 * V_99 ,
struct V_100 * V_101 )
{
struct V_9 * V_10 = NULL ;
int V_102 = 0 ;
if ( F_74 () )
return NULL ;
if ( ! V_98 )
V_98 = V_103 ;
if ( V_99 && ! V_101 )
V_102 = F_75 ( & V_99 -> V_24 ) ;
if ( V_99 && V_99 != V_98 )
F_76 ( & V_99 -> V_24 ) ;
if ( ! V_98 -> V_104 && V_98 != V_103 ) {
if ( V_99 )
return NULL ;
return V_98 ;
}
while ( ! V_10 ) {
struct V_105 * V_106 ( V_107 ) ;
struct V_23 * V_24 ;
if ( V_101 ) {
int V_18 = F_77 ( V_101 -> V_47 ) ;
int V_19 = F_78 ( V_101 -> V_47 ) ;
struct V_17 * V_30 ;
V_30 = F_15 ( V_98 , V_18 , V_19 ) ;
V_107 = & V_30 -> V_108 [ V_101 -> V_109 ] ;
if ( V_99 && V_101 -> V_110 != V_107 -> V_110 )
return NULL ;
V_102 = V_107 -> V_111 ;
}
F_8 () ;
V_24 = F_79 ( & V_112 , V_102 + 1 , & V_98 -> V_24 , & V_102 ) ;
if ( V_24 ) {
if ( V_24 == & V_98 -> V_24 || F_38 ( V_24 ) )
V_10 = F_69 ( V_24 ,
struct V_9 , V_24 ) ;
} else
V_102 = 0 ;
F_10 () ;
if ( V_101 ) {
V_107 -> V_111 = V_102 ;
if ( ! V_24 )
V_107 -> V_110 ++ ;
else if ( ! V_99 && V_10 )
V_101 -> V_110 = V_107 -> V_110 ;
}
if ( V_99 && ! V_24 )
return NULL ;
}
return V_10 ;
}
void F_80 ( struct V_9 * V_98 ,
struct V_9 * V_99 )
{
if ( ! V_98 )
V_98 = V_103 ;
if ( V_99 && V_99 != V_98 )
F_76 ( & V_99 -> V_24 ) ;
}
static inline bool F_6 ( struct V_9 * V_10 )
{
return ( V_10 == V_103 ) ;
}
void F_81 ( struct V_95 * V_96 , enum V_113 V_54 )
{
struct V_9 * V_10 ;
if ( ! V_96 )
return;
F_8 () ;
V_10 = F_9 ( F_72 ( V_96 -> V_97 ) ) ;
if ( F_65 ( ! V_10 ) )
goto V_114;
switch ( V_54 ) {
case V_115 :
F_82 ( V_10 -> V_57 -> V_64 [ V_116 ] ) ;
break;
case V_117 :
F_82 ( V_10 -> V_57 -> V_64 [ V_118 ] ) ;
break;
default:
F_83 () ;
}
V_114:
F_10 () ;
}
struct V_119 * F_84 ( struct V_47 * V_47 ,
struct V_9 * V_10 )
{
struct V_17 * V_30 ;
if ( F_74 () )
return & V_47 -> V_119 ;
V_30 = F_15 ( V_10 , F_77 ( V_47 ) , F_78 ( V_47 ) ) ;
return & V_30 -> V_119 ;
}
struct V_119 * F_85 ( struct V_47 * V_47 , struct V_25 * V_25 ,
enum V_73 V_120 )
{
struct V_17 * V_30 ;
struct V_9 * V_10 ;
struct V_121 * V_122 ;
if ( F_74 () )
return & V_47 -> V_119 ;
V_122 = F_86 ( V_25 ) ;
V_10 = V_122 -> V_9 ;
if ( ! F_87 ( V_122 ) && V_10 != V_103 )
V_122 -> V_9 = V_10 = V_103 ;
V_30 = F_17 ( V_10 , V_25 ) ;
F_57 ( V_30 , V_120 ) += 1 << F_88 ( V_25 ) ;
return & V_30 -> V_119 ;
}
void F_89 ( struct V_25 * V_25 , enum V_73 V_120 )
{
struct V_17 * V_30 ;
struct V_9 * V_10 ;
struct V_121 * V_122 ;
if ( F_74 () )
return;
V_122 = F_86 ( V_25 ) ;
V_10 = V_122 -> V_9 ;
F_90 ( ! V_10 ) ;
V_30 = F_17 ( V_10 , V_25 ) ;
F_90 ( F_57 ( V_30 , V_120 ) < ( 1 << F_88 ( V_25 ) ) ) ;
F_57 ( V_30 , V_120 ) -= 1 << F_88 ( V_25 ) ;
}
void F_91 ( struct V_25 * V_25 )
{
F_89 ( V_25 , F_92 ( V_25 ) ) ;
}
struct V_119 * F_93 ( struct V_47 * V_47 ,
struct V_25 * V_25 ,
enum V_73 V_123 ,
enum V_73 V_3 )
{
F_89 ( V_25 , V_123 ) ;
return F_85 ( V_47 , V_25 , V_3 ) ;
}
static bool F_94 ( const struct V_9 * V_124 ,
struct V_9 * V_10 )
{
if ( V_124 != V_10 ) {
return ( V_124 -> V_104 &&
F_95 ( & V_10 -> V_24 , & V_124 -> V_24 ) ) ;
}
return true ;
}
int F_96 ( struct V_94 * V_125 , const struct V_9 * V_10 )
{
int V_75 ;
struct V_9 * V_126 = NULL ;
struct V_94 * V_34 ;
V_34 = F_97 ( V_125 ) ;
if ( V_34 ) {
V_126 = F_71 ( V_34 -> V_96 ) ;
F_98 ( V_34 ) ;
} else {
F_99 ( V_125 ) ;
V_126 = F_9 ( V_125 ) ;
if ( V_126 )
F_100 ( & V_126 -> V_24 ) ;
F_98 ( V_125 ) ;
}
if ( ! V_126 )
return 0 ;
V_75 = F_94 ( V_10 , V_126 ) ;
F_76 ( & V_126 -> V_24 ) ;
return V_75 ;
}
int F_101 ( struct V_9 * V_10 , struct V_47 * V_47 )
{
unsigned long V_127 ;
int V_18 = F_77 ( V_47 ) ;
int V_19 = F_78 ( V_47 ) ;
unsigned long V_128 ;
unsigned long V_129 ;
unsigned long V_130 ;
V_128 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_131 ) ) ;
V_129 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_132 ) ) ;
V_130 = ( V_128 + V_129 ) >> ( 30 - V_133 ) ;
if ( V_130 )
V_127 = F_102 ( 10 * V_130 ) ;
else
V_127 = 1 ;
return V_128 * V_127 < V_129 ;
}
int F_103 ( struct V_9 * V_10 , struct V_47 * V_47 )
{
unsigned long V_129 ;
unsigned long V_128 ;
int V_19 = F_78 ( V_47 ) ;
int V_18 = F_77 ( V_47 ) ;
V_128 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_134 ) ) ;
V_129 = F_54 ( V_10 , V_18 , V_19 ,
F_56 ( V_135 ) ) ;
return ( V_129 > V_128 ) ;
}
struct V_136 * F_104 ( struct V_9 * V_10 ,
struct V_47 * V_47 )
{
int V_18 = F_77 ( V_47 ) ;
int V_19 = F_78 ( V_47 ) ;
struct V_17 * V_30 = F_15 ( V_10 , V_18 , V_19 ) ;
return & V_30 -> V_137 ;
}
struct V_136 *
F_105 ( struct V_25 * V_25 )
{
struct V_121 * V_122 ;
struct V_17 * V_30 ;
if ( F_74 () )
return NULL ;
V_122 = F_86 ( V_25 ) ;
if ( ! F_87 ( V_122 ) )
return NULL ;
F_106 () ;
V_30 = F_17 ( V_122 -> V_9 , V_25 ) ;
return & V_30 -> V_137 ;
}
static unsigned long F_107 ( struct V_9 * V_10 )
{
unsigned long long V_138 ;
V_138 = F_108 ( & V_10 -> V_45 ) ;
if ( V_139 )
V_138 = F_109 ( V_138 , F_108 ( & V_10 -> V_140 ) ) ;
return V_138 >> V_133 ;
}
int F_110 ( struct V_9 * V_10 )
{
struct V_91 * V_141 = V_10 -> V_24 . V_91 ;
if ( V_141 -> V_36 == NULL )
return V_142 ;
return V_10 -> V_143 ;
}
static void F_111 ( struct V_9 * V_10 )
{
int V_56 ;
F_41 () ;
F_29 ( & V_10 -> V_59 ) ;
F_42 (cpu)
F_43 ( V_10 -> V_57 -> V_58 [ V_144 ] , V_56 ) += 1 ;
V_10 -> V_60 . V_58 [ V_144 ] += 1 ;
F_30 ( & V_10 -> V_59 ) ;
F_45 () ;
F_112 () ;
}
static void F_113 ( struct V_9 * V_10 )
{
int V_56 ;
if ( ! V_10 )
return;
F_41 () ;
F_29 ( & V_10 -> V_59 ) ;
F_42 (cpu)
F_43 ( V_10 -> V_57 -> V_58 [ V_144 ] , V_56 ) -= 1 ;
V_10 -> V_60 . V_58 [ V_144 ] -= 1 ;
F_30 ( & V_10 -> V_59 ) ;
F_45 () ;
}
static bool F_114 ( struct V_9 * V_10 )
{
F_90 ( ! F_115 () ) ;
return F_116 ( V_10 -> V_57 -> V_58 [ V_144 ] ) > 0 ;
}
static bool F_117 ( struct V_9 * V_10 )
{
struct V_9 * V_123 ;
struct V_9 * V_3 ;
bool V_75 = false ;
F_29 ( & V_2 . V_43 ) ;
V_123 = V_2 . V_123 ;
V_3 = V_2 . V_3 ;
if ( ! V_123 )
goto V_145;
V_75 = F_94 ( V_10 , V_123 )
|| F_94 ( V_10 , V_3 ) ;
V_145:
F_30 ( & V_2 . V_43 ) ;
return V_75 ;
}
static bool F_118 ( struct V_9 * V_10 )
{
if ( V_2 . V_146 && V_14 != V_2 . V_146 ) {
if ( F_117 ( V_10 ) ) {
F_119 ( V_147 ) ;
F_120 ( & V_2 . V_148 , & V_147 , V_149 ) ;
if ( V_2 . V_146 )
F_121 () ;
F_122 ( & V_2 . V_148 , & V_147 ) ;
return true ;
}
}
return false ;
}
void F_123 ( struct V_9 * V_10 , struct V_94 * V_34 )
{
struct V_91 * V_150 ;
struct V_91 * V_151 ;
static char V_152 [ V_153 ] ;
int V_75 ;
if ( ! V_10 || ! V_34 )
return;
F_8 () ;
V_151 = V_10 -> V_24 . V_91 ;
V_150 = F_124 ( V_34 , V_93 ) ;
V_75 = F_125 ( V_150 , V_152 , V_153 ) ;
if ( V_75 < 0 ) {
F_10 () ;
goto V_51;
}
F_10 () ;
F_126 ( V_154 L_1 , V_152 ) ;
F_8 () ;
V_75 = F_125 ( V_151 , V_152 , V_153 ) ;
if ( V_75 < 0 ) {
F_10 () ;
goto V_51;
}
F_10 () ;
F_126 ( V_155 L_2 , V_152 ) ;
V_51:
F_126 ( V_154 L_3 ,
F_127 ( & V_10 -> V_45 , V_156 ) >> 10 ,
F_127 ( & V_10 -> V_45 , V_157 ) >> 10 ,
F_127 ( & V_10 -> V_45 , V_158 ) ) ;
F_126 ( V_154 L_4
L_5 ,
F_127 ( & V_10 -> V_140 , V_156 ) >> 10 ,
F_127 ( & V_10 -> V_140 , V_157 ) >> 10 ,
F_127 ( & V_10 -> V_140 , V_158 ) ) ;
}
static int F_128 ( struct V_9 * V_10 )
{
int V_159 = 0 ;
struct V_9 * V_107 ;
F_129 (iter, memcg)
V_159 ++ ;
return V_159 ;
}
T_1 F_130 ( struct V_9 * V_10 )
{
T_1 V_160 ;
T_1 V_140 ;
V_160 = F_127 ( & V_10 -> V_45 , V_157 ) ;
V_160 += V_161 << V_133 ;
V_140 = F_127 ( & V_10 -> V_140 , V_157 ) ;
return F_109 ( V_160 , V_140 ) ;
}
static unsigned long F_131 ( struct V_9 * V_10 ,
T_3 V_162 ,
unsigned long V_163 )
{
unsigned long V_76 = 0 ;
bool V_164 = false ;
int V_165 ;
if ( V_163 & V_166 )
V_164 = true ;
if ( ! ( V_163 & V_167 ) && V_10 -> V_168 )
V_164 = true ;
for ( V_165 = 0 ; V_165 < V_169 ; V_165 ++ ) {
if ( V_165 )
F_132 ( V_10 ) ;
V_76 += F_133 ( V_10 , V_162 , V_164 ) ;
if ( V_76 && ( V_163 & V_167 ) )
break;
if ( F_107 ( V_10 ) )
break;
if ( V_165 && ! V_76 )
break;
}
return V_76 ;
}
static bool F_134 ( struct V_9 * V_10 ,
int V_18 , bool V_164 )
{
if ( F_58 ( V_10 , V_18 , V_170 ) )
return true ;
if ( V_164 || ! V_161 )
return false ;
if ( F_58 ( V_10 , V_18 , V_171 ) )
return true ;
return false ;
}
static void F_135 ( struct V_9 * V_10 )
{
int V_18 ;
if ( ! F_136 ( & V_10 -> V_90 ) )
return;
if ( F_137 ( & V_10 -> V_172 ) > 1 )
return;
V_10 -> V_173 = V_174 [ V_175 ] ;
F_138 (nid, node_states[N_HIGH_MEMORY]) {
if ( ! F_134 ( V_10 , V_18 , false ) )
F_139 ( V_18 , V_10 -> V_173 ) ;
}
F_140 ( & V_10 -> V_90 , 0 ) ;
F_140 ( & V_10 -> V_172 , 0 ) ;
}
int F_141 ( struct V_9 * V_10 )
{
int V_46 ;
F_135 ( V_10 ) ;
V_46 = V_10 -> V_176 ;
V_46 = F_142 ( V_46 , V_10 -> V_173 ) ;
if ( V_46 == V_89 )
V_46 = F_143 ( V_10 -> V_173 ) ;
if ( F_65 ( V_46 == V_89 ) )
V_46 = F_144 () ;
V_10 -> V_176 = V_46 ;
return V_46 ;
}
bool F_145 ( struct V_9 * V_10 , bool V_164 )
{
int V_18 ;
if ( ! F_146 ( V_10 -> V_173 ) ) {
for ( V_18 = F_143 ( V_10 -> V_173 ) ;
V_18 < V_89 ;
V_18 = F_142 ( V_18 , V_10 -> V_173 ) ) {
if ( F_134 ( V_10 , V_18 , V_164 ) )
return true ;
}
}
F_60 (nid, N_HIGH_MEMORY) {
if ( F_147 ( V_18 , V_10 -> V_173 ) )
continue;
if ( F_134 ( V_10 , V_18 , V_164 ) )
return true ;
}
return false ;
}
int F_141 ( struct V_9 * V_10 )
{
return 0 ;
}
bool F_145 ( struct V_9 * V_10 , bool V_164 )
{
return F_134 ( V_10 , 0 , V_164 ) ;
}
static int F_148 ( struct V_9 * V_124 ,
struct V_47 * V_47 ,
T_3 V_162 ,
unsigned long * V_177 )
{
struct V_9 * V_178 = NULL ;
int V_76 = 0 ;
int V_165 = 0 ;
unsigned long V_44 ;
unsigned long V_179 ;
struct V_100 V_101 = {
. V_47 = V_47 ,
. V_109 = 0 ,
} ;
V_44 = F_33 ( & V_124 -> V_45 ) >> V_133 ;
while ( 1 ) {
V_178 = F_73 ( V_124 , V_178 , & V_101 ) ;
if ( ! V_178 ) {
V_165 ++ ;
if ( V_165 >= 2 ) {
if ( ! V_76 )
break;
if ( V_76 >= ( V_44 >> 2 ) ||
( V_165 > V_169 ) )
break;
}
continue;
}
if ( ! F_145 ( V_178 , false ) )
continue;
V_76 += F_149 ( V_178 , V_162 , false ,
V_47 , & V_179 ) ;
* V_177 += V_179 ;
if ( ! F_33 ( & V_124 -> V_45 ) )
break;
}
F_80 ( V_124 , V_178 ) ;
return V_76 ;
}
static bool F_150 ( struct V_9 * V_10 )
{
struct V_9 * V_107 , * V_180 = NULL ;
F_129 (iter, memcg) {
if ( V_107 -> V_181 ) {
V_180 = V_107 ;
F_80 ( V_10 , V_107 ) ;
break;
} else
V_107 -> V_181 = true ;
}
if ( ! V_180 )
return true ;
F_129 (iter, memcg) {
if ( V_107 == V_180 ) {
F_80 ( V_10 , V_107 ) ;
break;
}
V_107 -> V_181 = false ;
}
return false ;
}
static int F_151 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_129 (iter, memcg)
V_107 -> V_181 = false ;
return 0 ;
}
static void F_152 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_129 (iter, memcg)
F_67 ( & V_107 -> V_182 ) ;
}
static void F_153 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_129 (iter, memcg)
F_154 ( & V_107 -> V_182 , - 1 , 0 ) ;
}
static int F_155 ( T_4 * V_147 ,
unsigned V_183 , int V_184 , void * V_185 )
{
struct V_9 * V_186 = (struct V_9 * ) V_185 ,
* V_187 ;
struct V_188 * V_188 ;
V_188 = F_69 ( V_147 , struct V_188 , V_147 ) ;
V_187 = V_188 -> V_52 ;
if ( ! F_94 ( V_187 , V_186 )
&& ! F_94 ( V_186 , V_187 ) )
return 0 ;
return F_156 ( V_147 , V_183 , V_184 , V_185 ) ;
}
static void F_157 ( struct V_9 * V_10 )
{
F_158 ( & V_189 , V_190 , 0 , V_10 ) ;
}
static void F_159 ( struct V_9 * V_10 )
{
if ( V_10 && F_136 ( & V_10 -> V_182 ) )
F_157 ( V_10 ) ;
}
bool F_160 ( struct V_9 * V_10 , T_3 V_191 )
{
struct V_188 V_192 ;
bool V_193 , V_194 ;
V_192 . V_52 = V_10 ;
V_192 . V_147 . V_163 = 0 ;
V_192 . V_147 . V_195 = F_155 ;
V_192 . V_147 . V_196 = V_14 ;
F_161 ( & V_192 . V_147 . V_197 ) ;
V_194 = true ;
F_152 ( V_10 ) ;
F_29 ( & V_198 ) ;
V_193 = F_150 ( V_10 ) ;
F_120 ( & V_189 , & V_192 . V_147 , V_199 ) ;
if ( ! V_193 || V_10 -> V_200 )
V_194 = false ;
if ( V_193 )
F_162 ( V_10 ) ;
F_30 ( & V_198 ) ;
if ( V_194 ) {
F_122 ( & V_189 , & V_192 . V_147 ) ;
F_163 ( V_10 , V_191 ) ;
} else {
F_121 () ;
F_122 ( & V_189 , & V_192 . V_147 ) ;
}
F_29 ( & V_198 ) ;
if ( V_193 )
F_151 ( V_10 ) ;
F_157 ( V_10 ) ;
F_30 ( & V_198 ) ;
F_153 ( V_10 ) ;
if ( F_164 ( V_201 ) || F_165 ( V_14 ) )
return false ;
F_166 ( 1 ) ;
return true ;
}
void F_167 ( struct V_25 * V_25 ,
enum V_202 V_54 , int V_55 )
{
struct V_9 * V_10 ;
struct V_121 * V_122 = F_86 ( V_25 ) ;
bool V_203 = false ;
unsigned long V_106 ( V_163 ) ;
if ( F_74 () )
return;
F_8 () ;
V_10 = V_122 -> V_9 ;
if ( F_65 ( ! V_10 || ! F_87 ( V_122 ) ) )
goto V_114;
if ( F_65 ( F_114 ( V_10 ) ) || F_168 ( V_25 ) ) {
F_169 ( V_122 , & V_163 ) ;
V_203 = true ;
V_10 = V_122 -> V_9 ;
if ( ! V_10 || ! F_87 ( V_122 ) )
goto V_114;
}
switch ( V_54 ) {
case V_204 :
if ( V_55 > 0 )
F_170 ( V_122 ) ;
else if ( ! F_171 ( V_25 ) )
F_172 ( V_122 ) ;
V_54 = V_205 ;
break;
default:
F_83 () ;
}
F_47 ( V_10 -> V_57 -> V_58 [ V_54 ] , V_55 ) ;
V_114:
if ( F_65 ( V_203 ) )
F_173 ( V_122 , & V_163 ) ;
F_10 () ;
return;
}
static bool F_174 ( struct V_9 * V_10 )
{
struct V_206 * V_207 ;
bool V_75 = true ;
V_207 = & F_175 ( V_208 ) ;
if ( V_10 == V_207 -> V_209 && V_207 -> V_66 )
V_207 -> V_66 -- ;
else
V_75 = false ;
F_176 ( V_208 ) ;
return V_75 ;
}
static void F_177 ( struct V_206 * V_207 )
{
struct V_9 * V_210 = V_207 -> V_209 ;
if ( V_207 -> V_66 ) {
unsigned long V_211 = V_207 -> V_66 * V_212 ;
F_178 ( & V_210 -> V_45 , V_211 ) ;
if ( V_139 )
F_178 ( & V_210 -> V_140 , V_211 ) ;
V_207 -> V_66 = 0 ;
}
V_207 -> V_209 = NULL ;
}
static void F_179 ( struct V_213 * V_214 )
{
struct V_206 * V_207 = & F_180 ( V_208 ) ;
F_177 ( V_207 ) ;
F_181 ( V_215 , & V_207 -> V_163 ) ;
}
static void F_182 ( struct V_9 * V_10 , unsigned int V_66 )
{
struct V_206 * V_207 = & F_175 ( V_208 ) ;
if ( V_207 -> V_209 != V_10 ) {
F_177 ( V_207 ) ;
V_207 -> V_209 = V_10 ;
}
V_207 -> V_66 += V_66 ;
F_176 ( V_208 ) ;
}
static void F_183 ( struct V_9 * V_124 , bool V_184 )
{
int V_56 , V_216 ;
F_41 () ;
V_216 = F_184 () ;
F_42 (cpu) {
struct V_206 * V_207 = & F_43 ( V_208 , V_56 ) ;
struct V_9 * V_10 ;
V_10 = V_207 -> V_209 ;
if ( ! V_10 || ! V_207 -> V_66 )
continue;
if ( ! F_94 ( V_124 , V_10 ) )
continue;
if ( ! F_185 ( V_215 , & V_207 -> V_163 ) ) {
if ( V_56 == V_216 )
F_179 ( & V_207 -> V_217 ) ;
else
F_186 ( V_56 , & V_207 -> V_217 ) ;
}
}
F_187 () ;
if ( ! V_184 )
goto V_114;
F_42 (cpu) {
struct V_206 * V_207 = & F_43 ( V_208 , V_56 ) ;
if ( F_2 ( V_215 , & V_207 -> V_163 ) )
F_188 ( & V_207 -> V_217 ) ;
}
V_114:
F_45 () ;
}
static void F_132 ( struct V_9 * V_124 )
{
if ( ! F_189 ( & V_218 ) )
return;
F_183 ( V_124 , false ) ;
F_190 ( & V_218 ) ;
}
static void F_191 ( struct V_9 * V_124 )
{
F_192 ( & V_218 ) ;
F_183 ( V_124 , true ) ;
F_190 ( & V_218 ) ;
}
static void F_193 ( struct V_9 * V_10 , int V_56 )
{
int V_219 ;
F_29 ( & V_10 -> V_59 ) ;
for ( V_219 = 0 ; V_219 < V_220 ; V_219 ++ ) {
long V_221 = F_43 ( V_10 -> V_57 -> V_58 [ V_219 ] , V_56 ) ;
F_43 ( V_10 -> V_57 -> V_58 [ V_219 ] , V_56 ) = 0 ;
V_10 -> V_60 . V_58 [ V_219 ] += V_221 ;
}
for ( V_219 = 0 ; V_219 < V_222 ; V_219 ++ ) {
unsigned long V_221 = F_43 ( V_10 -> V_57 -> V_64 [ V_219 ] , V_56 ) ;
F_43 ( V_10 -> V_57 -> V_64 [ V_219 ] , V_56 ) = 0 ;
V_10 -> V_60 . V_64 [ V_219 ] += V_221 ;
}
F_43 ( V_10 -> V_57 -> V_58 [ V_144 ] , V_56 ) = 0 ;
F_30 ( & V_10 -> V_59 ) ;
}
static void F_194 ( struct V_9 * V_10 , int V_56 )
{
int V_54 = V_144 ;
F_29 ( & V_10 -> V_59 ) ;
F_43 ( V_10 -> V_57 -> V_58 [ V_54 ] , V_56 ) = V_10 -> V_60 . V_58 [ V_54 ] ;
F_30 ( & V_10 -> V_59 ) ;
}
static int T_5 F_195 ( struct V_223 * V_224 ,
unsigned long V_225 ,
void * V_226 )
{
int V_56 = ( unsigned long ) V_226 ;
struct V_206 * V_207 ;
struct V_9 * V_107 ;
if ( ( V_225 == V_227 ) ) {
F_196 (iter)
F_194 ( V_107 , V_56 ) ;
return V_228 ;
}
if ( ( V_225 != V_229 ) || V_225 != V_230 )
return V_228 ;
F_196 (iter)
F_193 ( V_107 , V_56 ) ;
V_207 = & F_43 ( V_208 , V_56 ) ;
F_177 ( V_207 ) ;
return V_228 ;
}
static int F_197 ( struct V_9 * V_10 , T_3 V_162 ,
unsigned int V_66 , bool V_231 )
{
unsigned long V_232 = V_66 * V_212 ;
struct V_9 * V_233 ;
struct V_234 * V_235 ;
unsigned long V_163 = 0 ;
int V_75 ;
V_75 = F_198 ( & V_10 -> V_45 , V_232 , & V_235 ) ;
if ( F_199 ( ! V_75 ) ) {
if ( ! V_139 )
return V_236 ;
V_75 = F_198 ( & V_10 -> V_140 , V_232 , & V_235 ) ;
if ( F_199 ( ! V_75 ) )
return V_236 ;
F_178 ( & V_10 -> V_45 , V_232 ) ;
V_233 = F_200 ( V_235 , V_140 ) ;
V_163 |= V_166 ;
} else
V_233 = F_200 ( V_235 , V_45 ) ;
if ( V_66 == V_237 )
return V_238 ;
if ( ! ( V_162 & V_239 ) )
return V_240 ;
V_75 = F_131 ( V_233 , V_162 , V_163 ) ;
if ( F_107 ( V_233 ) >= V_66 )
return V_238 ;
if ( V_66 == 1 && V_75 )
return V_238 ;
if ( F_118 ( V_233 ) )
return V_238 ;
if ( ! V_231 )
return V_241 ;
if ( ! F_160 ( V_233 , V_162 ) )
return V_242 ;
return V_238 ;
}
static int F_201 ( struct V_95 * V_96 ,
T_3 V_162 ,
unsigned int V_66 ,
struct V_9 * * V_243 ,
bool V_244 )
{
unsigned int V_245 = F_202 ( V_237 , V_66 ) ;
int V_246 = V_247 ;
struct V_9 * V_10 = NULL ;
int V_75 ;
if ( F_65 ( F_164 ( V_201 )
|| F_165 ( V_14 ) ) )
goto V_248;
if ( ! * V_243 && ! V_96 )
* V_243 = V_103 ;
V_249:
if ( * V_243 ) {
V_10 = * V_243 ;
F_90 ( F_203 ( & V_10 -> V_24 ) ) ;
if ( F_6 ( V_10 ) )
goto V_51;
if ( V_66 == 1 && F_174 ( V_10 ) )
goto V_51;
F_100 ( & V_10 -> V_24 ) ;
} else {
struct V_94 * V_34 ;
F_8 () ;
V_34 = F_72 ( V_96 -> V_97 ) ;
V_10 = F_9 ( V_34 ) ;
if ( ! V_10 )
V_10 = V_103 ;
if ( F_6 ( V_10 ) ) {
F_10 () ;
goto V_51;
}
if ( V_66 == 1 && F_174 ( V_10 ) ) {
F_10 () ;
goto V_51;
}
if ( ! F_38 ( & V_10 -> V_24 ) ) {
F_10 () ;
goto V_249;
}
F_10 () ;
}
do {
bool V_231 ;
if ( F_165 ( V_14 ) ) {
F_76 ( & V_10 -> V_24 ) ;
goto V_248;
}
V_231 = false ;
if ( V_244 && ! V_246 ) {
V_231 = true ;
V_246 = V_247 ;
}
V_75 = F_197 ( V_10 , V_162 , V_245 , V_231 ) ;
switch ( V_75 ) {
case V_236 :
break;
case V_238 :
V_245 = V_66 ;
F_76 ( & V_10 -> V_24 ) ;
V_10 = NULL ;
goto V_249;
case V_240 :
F_76 ( & V_10 -> V_24 ) ;
goto V_250;
case V_241 :
if ( ! V_244 ) {
F_76 ( & V_10 -> V_24 ) ;
goto V_250;
}
V_246 -- ;
break;
case V_242 :
F_76 ( & V_10 -> V_24 ) ;
goto V_248;
}
} while ( V_75 != V_236 );
if ( V_245 > V_66 )
F_182 ( V_10 , V_245 - V_66 ) ;
F_76 ( & V_10 -> V_24 ) ;
V_51:
* V_243 = V_10 ;
return 0 ;
V_250:
* V_243 = NULL ;
return - V_251 ;
V_248:
* V_243 = V_103 ;
return - V_252 ;
}
static void F_204 ( struct V_9 * V_10 ,
unsigned int V_66 )
{
if ( ! F_6 ( V_10 ) ) {
unsigned long V_211 = V_66 * V_212 ;
F_178 ( & V_10 -> V_45 , V_211 ) ;
if ( V_139 )
F_178 ( & V_10 -> V_140 , V_211 ) ;
}
}
static struct V_9 * F_205 ( unsigned short V_102 )
{
struct V_23 * V_24 ;
if ( ! V_102 )
return NULL ;
V_24 = F_206 ( & V_112 , V_102 ) ;
if ( ! V_24 )
return NULL ;
return F_69 ( V_24 , struct V_9 , V_24 ) ;
}
struct V_9 * F_207 ( struct V_25 * V_25 )
{
struct V_9 * V_10 = NULL ;
struct V_121 * V_122 ;
unsigned short V_102 ;
T_6 V_253 ;
F_90 ( ! F_208 ( V_25 ) ) ;
V_122 = F_86 ( V_25 ) ;
F_209 ( V_122 ) ;
if ( F_87 ( V_122 ) ) {
V_10 = V_122 -> V_9 ;
if ( V_10 && ! F_38 ( & V_10 -> V_24 ) )
V_10 = NULL ;
} else if ( F_210 ( V_25 ) ) {
V_253 . V_55 = F_211 ( V_25 ) ;
V_102 = F_212 ( V_253 ) ;
F_8 () ;
V_10 = F_205 ( V_102 ) ;
if ( V_10 && ! F_38 ( & V_10 -> V_24 ) )
V_10 = NULL ;
F_10 () ;
}
F_213 ( V_122 ) ;
return V_10 ;
}
static void F_214 ( struct V_9 * V_10 ,
struct V_25 * V_25 ,
unsigned int V_66 ,
struct V_121 * V_122 ,
enum V_254 V_255 ,
bool V_256 )
{
struct V_47 * V_106 ( V_47 ) ;
bool V_257 = false ;
F_209 ( V_122 ) ;
if ( F_65 ( F_87 ( V_122 ) ) ) {
F_213 ( V_122 ) ;
F_204 ( V_10 , V_66 ) ;
return;
}
if ( V_256 ) {
V_47 = F_215 ( V_25 ) ;
F_216 ( & V_47 -> V_258 ) ;
if ( F_217 ( V_25 ) ) {
F_218 ( V_25 ) ;
F_219 ( V_47 , V_25 , F_92 ( V_25 ) ) ;
V_257 = true ;
}
}
V_122 -> V_9 = V_10 ;
F_220 () ;
switch ( V_255 ) {
case V_259 :
case V_260 :
F_221 ( V_122 ) ;
F_222 ( V_122 ) ;
break;
case V_261 :
F_223 ( V_122 ) ;
F_222 ( V_122 ) ;
break;
default:
break;
}
if ( V_256 ) {
if ( V_257 ) {
F_90 ( F_217 ( V_25 ) ) ;
F_224 ( V_25 ) ;
F_225 ( V_47 , V_25 , F_92 ( V_25 ) ) ;
}
F_226 ( & V_47 -> V_258 ) ;
}
F_49 ( V_10 , F_227 ( V_122 ) , V_66 ) ;
F_213 ( V_122 ) ;
F_64 ( V_10 , V_25 ) ;
}
void F_228 ( struct V_25 * V_262 )
{
struct V_121 * V_263 = F_86 ( V_262 ) ;
struct V_121 * V_122 ;
int V_219 ;
if ( F_74 () )
return;
for ( V_219 = 1 ; V_219 < V_264 ; V_219 ++ ) {
V_122 = V_263 + V_219 ;
V_122 -> V_9 = V_263 -> V_9 ;
F_220 () ;
V_122 -> V_163 = V_263 -> V_163 & ~ V_265 ;
}
}
static int F_229 ( struct V_25 * V_25 ,
unsigned int V_66 ,
struct V_121 * V_122 ,
struct V_9 * V_123 ,
struct V_9 * V_3 ,
bool V_266 )
{
unsigned long V_163 ;
int V_75 ;
F_90 ( V_123 == V_3 ) ;
F_90 ( F_217 ( V_25 ) ) ;
V_75 = - V_267 ;
if ( V_66 > 1 && ! F_168 ( V_25 ) )
goto V_114;
F_209 ( V_122 ) ;
V_75 = - V_268 ;
if ( ! F_87 ( V_122 ) || V_122 -> V_9 != V_123 )
goto V_145;
F_169 ( V_122 , & V_163 ) ;
if ( F_230 ( V_122 ) ) {
F_50 () ;
F_231 ( V_123 -> V_57 -> V_58 [ V_205 ] ) ;
F_52 ( V_3 -> V_57 -> V_58 [ V_205 ] ) ;
F_53 () ;
}
F_49 ( V_123 , F_227 ( V_122 ) , - V_66 ) ;
if ( V_266 )
F_204 ( V_123 , V_66 ) ;
V_122 -> V_9 = V_3 ;
F_49 ( V_3 , F_227 ( V_122 ) , V_66 ) ;
F_173 ( V_122 , & V_163 ) ;
V_75 = 0 ;
V_145:
F_213 ( V_122 ) ;
F_64 ( V_3 , V_25 ) ;
F_64 ( V_123 , V_25 ) ;
V_114:
return V_75 ;
}
static int F_232 ( struct V_25 * V_25 ,
struct V_121 * V_122 ,
struct V_9 * V_269 ,
T_3 V_162 )
{
struct V_91 * V_270 = V_269 -> V_24 . V_91 ;
struct V_91 * V_271 = V_270 -> V_36 ;
struct V_9 * V_36 ;
unsigned int V_66 ;
unsigned long V_106 ( V_163 ) ;
int V_75 ;
if ( ! V_271 )
return - V_268 ;
V_75 = - V_267 ;
if ( ! F_233 ( V_25 ) )
goto V_114;
if ( F_234 ( V_25 ) )
goto V_272;
V_66 = F_235 ( V_25 ) ;
V_36 = F_68 ( V_271 ) ;
V_75 = F_201 ( NULL , V_162 , V_66 , & V_36 , false ) ;
if ( V_75 )
goto V_273;
if ( V_66 > 1 )
V_163 = F_236 ( V_25 ) ;
V_75 = F_229 ( V_25 , V_66 , V_122 , V_269 , V_36 , true ) ;
if ( V_75 )
F_204 ( V_36 , V_66 ) ;
if ( V_66 > 1 )
F_237 ( V_25 , V_163 ) ;
V_273:
F_238 ( V_25 ) ;
V_272:
F_239 ( V_25 ) ;
V_114:
return V_75 ;
}
static int F_240 ( struct V_25 * V_25 , struct V_95 * V_96 ,
T_3 V_162 , enum V_254 V_255 )
{
struct V_9 * V_10 = NULL ;
unsigned int V_66 = 1 ;
struct V_121 * V_122 ;
bool V_244 = true ;
int V_75 ;
if ( F_168 ( V_25 ) ) {
V_66 <<= F_88 ( V_25 ) ;
F_90 ( ! F_168 ( V_25 ) ) ;
V_244 = false ;
}
V_122 = F_86 ( V_25 ) ;
V_75 = F_201 ( V_96 , V_162 , V_66 , & V_10 , V_244 ) ;
if ( V_75 == - V_251 )
return V_75 ;
F_214 ( V_10 , V_25 , V_66 , V_122 , V_255 , false ) ;
return 0 ;
}
int F_241 ( struct V_25 * V_25 ,
struct V_95 * V_96 , T_3 V_162 )
{
if ( F_74 () )
return 0 ;
F_90 ( F_171 ( V_25 ) ) ;
F_90 ( V_25 -> V_274 && ! F_242 ( V_25 ) ) ;
F_90 ( ! V_96 ) ;
return F_240 ( V_25 , V_96 , V_162 ,
V_261 ) ;
}
int F_243 ( struct V_25 * V_25 , struct V_95 * V_96 ,
T_3 V_162 )
{
struct V_9 * V_10 = NULL ;
enum V_254 type = V_259 ;
int V_75 ;
if ( F_74 () )
return 0 ;
if ( F_244 ( V_25 ) )
return 0 ;
if ( F_65 ( ! V_96 ) )
V_96 = & V_275 ;
if ( ! F_245 ( V_25 ) )
type = V_260 ;
if ( ! F_210 ( V_25 ) )
V_75 = F_240 ( V_25 , V_96 , V_162 , type ) ;
else {
V_75 = F_246 ( V_96 , V_25 , V_162 , & V_10 ) ;
if ( ! V_75 )
F_247 ( V_25 , V_10 , type ) ;
}
return V_75 ;
}
int F_246 ( struct V_95 * V_96 ,
struct V_25 * V_25 ,
T_3 V_191 , struct V_9 * * V_276 )
{
struct V_9 * V_10 ;
int V_75 ;
* V_276 = NULL ;
if ( F_74 () )
return 0 ;
if ( ! V_139 )
goto V_277;
if ( ! F_210 ( V_25 ) )
goto V_277;
V_10 = F_207 ( V_25 ) ;
if ( ! V_10 )
goto V_277;
* V_276 = V_10 ;
V_75 = F_201 ( NULL , V_191 , 1 , V_276 , true ) ;
F_76 ( & V_10 -> V_24 ) ;
if ( V_75 == - V_252 )
V_75 = 0 ;
return V_75 ;
V_277:
if ( F_65 ( ! V_96 ) )
V_96 = & V_275 ;
V_75 = F_201 ( V_96 , V_191 , 1 , V_276 , true ) ;
if ( V_75 == - V_252 )
V_75 = 0 ;
return V_75 ;
}
static void
F_247 ( struct V_25 * V_25 , struct V_9 * V_10 ,
enum V_254 V_255 )
{
struct V_121 * V_122 ;
if ( F_74 () )
return;
if ( ! V_10 )
return;
F_248 ( & V_10 -> V_24 ) ;
V_122 = F_86 ( V_25 ) ;
F_214 ( V_10 , V_25 , 1 , V_122 , V_255 , true ) ;
if ( V_139 && F_210 ( V_25 ) ) {
T_6 V_253 = { . V_55 = F_211 (page) } ;
struct V_9 * V_278 ;
unsigned short V_102 ;
V_102 = F_249 ( V_253 , 0 ) ;
F_8 () ;
V_278 = F_205 ( V_102 ) ;
if ( V_278 ) {
if ( ! F_6 ( V_278 ) )
F_178 ( & V_278 -> V_140 ,
V_212 ) ;
F_46 ( V_278 , false ) ;
F_13 ( V_278 ) ;
}
F_10 () ;
}
F_250 ( & V_10 -> V_24 ) ;
}
void F_251 ( struct V_25 * V_25 ,
struct V_9 * V_10 )
{
F_247 ( V_25 , V_10 ,
V_261 ) ;
}
void F_252 ( struct V_9 * V_10 )
{
if ( F_74 () )
return;
if ( ! V_10 )
return;
F_204 ( V_10 , 1 ) ;
}
static void F_253 ( struct V_9 * V_10 ,
unsigned int V_66 ,
const enum V_254 V_255 )
{
struct V_279 * V_245 = NULL ;
bool V_280 = true ;
if ( ! V_139 || V_255 == V_281 )
V_280 = false ;
V_245 = & V_14 -> V_282 ;
if ( ! V_245 -> V_10 )
V_245 -> V_10 = V_10 ;
if ( ! V_245 -> V_283 || F_164 ( V_201 ) )
goto V_284;
if ( V_66 > 1 )
goto V_284;
if ( V_245 -> V_10 != V_10 )
goto V_284;
V_245 -> V_66 ++ ;
if ( V_280 )
V_245 -> V_285 ++ ;
return;
V_284:
F_178 ( & V_10 -> V_45 , V_66 * V_212 ) ;
if ( V_280 )
F_178 ( & V_10 -> V_140 , V_66 * V_212 ) ;
if ( F_65 ( V_245 -> V_10 != V_10 ) )
F_159 ( V_10 ) ;
return;
}
static struct V_9 *
F_254 ( struct V_25 * V_25 , enum V_254 V_255 )
{
struct V_9 * V_10 = NULL ;
unsigned int V_66 = 1 ;
struct V_121 * V_122 ;
if ( F_74 () )
return NULL ;
if ( F_210 ( V_25 ) )
return NULL ;
if ( F_168 ( V_25 ) ) {
V_66 <<= F_88 ( V_25 ) ;
F_90 ( ! F_168 ( V_25 ) ) ;
}
V_122 = F_86 ( V_25 ) ;
if ( F_65 ( ! F_87 ( V_122 ) ) )
return NULL ;
F_209 ( V_122 ) ;
V_10 = V_122 -> V_9 ;
if ( ! F_87 ( V_122 ) )
goto V_286;
switch ( V_255 ) {
case V_261 :
case V_287 :
if ( F_171 ( V_25 ) || F_255 ( V_122 ) )
goto V_286;
break;
case V_281 :
if ( ! F_242 ( V_25 ) ) {
if ( V_25 -> V_274 && ! F_245 ( V_25 ) )
goto V_286;
} else if ( F_171 ( V_25 ) )
goto V_286;
break;
default:
break;
}
F_49 ( V_10 , F_227 ( V_122 ) , - V_66 ) ;
F_256 ( V_122 ) ;
F_213 ( V_122 ) ;
F_64 ( V_10 , V_25 ) ;
if ( V_139 && V_255 == V_281 ) {
F_46 ( V_10 , true ) ;
F_7 ( V_10 ) ;
}
if ( ! F_6 ( V_10 ) )
F_253 ( V_10 , V_66 , V_255 ) ;
return V_10 ;
V_286:
F_213 ( V_122 ) ;
return NULL ;
}
void F_257 ( struct V_25 * V_25 )
{
if ( F_171 ( V_25 ) )
return;
F_90 ( V_25 -> V_274 && ! F_242 ( V_25 ) ) ;
F_254 ( V_25 , V_261 ) ;
}
void F_258 ( struct V_25 * V_25 )
{
F_90 ( F_171 ( V_25 ) ) ;
F_90 ( V_25 -> V_274 ) ;
F_254 ( V_25 , V_259 ) ;
}
void F_259 ( void )
{
V_14 -> V_282 . V_283 ++ ;
if ( V_14 -> V_282 . V_283 == 1 ) {
V_14 -> V_282 . V_10 = NULL ;
V_14 -> V_282 . V_66 = 0 ;
V_14 -> V_282 . V_285 = 0 ;
}
}
void F_260 ( void )
{
struct V_279 * V_245 = & V_14 -> V_282 ;
if ( ! V_245 -> V_283 )
return;
V_245 -> V_283 -- ;
if ( V_245 -> V_283 )
return;
if ( ! V_245 -> V_10 )
return;
if ( V_245 -> V_66 )
F_178 ( & V_245 -> V_10 -> V_45 ,
V_245 -> V_66 * V_212 ) ;
if ( V_245 -> V_285 )
F_178 ( & V_245 -> V_10 -> V_140 ,
V_245 -> V_285 * V_212 ) ;
F_159 ( V_245 -> V_10 ) ;
V_245 -> V_10 = NULL ;
}
void
F_261 ( struct V_25 * V_25 , T_6 V_253 , bool V_288 )
{
struct V_9 * V_10 ;
int V_255 = V_281 ;
if ( ! V_288 )
V_255 = V_287 ;
V_10 = F_254 ( V_25 , V_255 ) ;
if ( V_139 && V_288 && V_10 )
F_249 ( V_253 , F_75 ( & V_10 -> V_24 ) ) ;
}
void F_262 ( T_6 V_253 )
{
struct V_9 * V_10 ;
unsigned short V_102 ;
if ( ! V_139 )
return;
V_102 = F_249 ( V_253 , 0 ) ;
F_8 () ;
V_10 = F_205 ( V_102 ) ;
if ( V_10 ) {
if ( ! F_6 ( V_10 ) )
F_178 ( & V_10 -> V_140 , V_212 ) ;
F_46 ( V_10 , false ) ;
F_13 ( V_10 ) ;
}
F_10 () ;
}
static int F_263 ( T_6 V_289 ,
struct V_9 * V_123 , struct V_9 * V_3 , bool V_290 )
{
unsigned short V_291 , V_292 ;
V_291 = F_75 ( & V_123 -> V_24 ) ;
V_292 = F_75 ( & V_3 -> V_24 ) ;
if ( F_264 ( V_289 , V_291 , V_292 ) == V_291 ) {
F_46 ( V_123 , false ) ;
F_46 ( V_3 , true ) ;
F_7 ( V_3 ) ;
if ( V_290 ) {
if ( ! F_6 ( V_123 ) )
F_178 ( & V_123 -> V_140 , V_212 ) ;
F_13 ( V_123 ) ;
if ( ! F_6 ( V_3 ) )
F_178 ( & V_3 -> V_45 , V_212 ) ;
}
return 0 ;
}
return - V_268 ;
}
static inline int F_263 ( T_6 V_289 ,
struct V_9 * V_123 , struct V_9 * V_3 , bool V_290 )
{
return - V_268 ;
}
int F_265 ( struct V_25 * V_25 ,
struct V_25 * V_293 , struct V_9 * * V_276 , T_3 V_162 )
{
struct V_9 * V_10 = NULL ;
struct V_121 * V_122 ;
enum V_254 V_255 ;
int V_75 = 0 ;
* V_276 = NULL ;
F_90 ( F_168 ( V_25 ) ) ;
if ( F_74 () )
return 0 ;
V_122 = F_86 ( V_25 ) ;
F_209 ( V_122 ) ;
if ( F_87 ( V_122 ) ) {
V_10 = V_122 -> V_9 ;
F_100 ( & V_10 -> V_24 ) ;
if ( F_242 ( V_25 ) )
F_266 ( V_122 ) ;
}
F_213 ( V_122 ) ;
if ( ! V_10 )
return 0 ;
* V_276 = V_10 ;
V_75 = F_201 ( NULL , V_162 , 1 , V_276 , false ) ;
F_76 ( & V_10 -> V_24 ) ;
if ( V_75 ) {
if ( F_242 ( V_25 ) ) {
F_209 ( V_122 ) ;
F_267 ( V_122 ) ;
F_213 ( V_122 ) ;
F_257 ( V_25 ) ;
}
return - V_251 ;
}
V_122 = F_86 ( V_293 ) ;
if ( F_242 ( V_25 ) )
V_255 = V_261 ;
else if ( F_245 ( V_25 ) )
V_255 = V_259 ;
else
V_255 = V_260 ;
F_214 ( V_10 , V_293 , 1 , V_122 , V_255 , false ) ;
return V_75 ;
}
void F_268 ( struct V_9 * V_10 ,
struct V_25 * V_294 , struct V_25 * V_293 , bool V_295 )
{
struct V_25 * V_296 , * V_297 ;
struct V_121 * V_122 ;
if ( ! V_10 )
return;
F_248 ( & V_10 -> V_24 ) ;
if ( ! V_295 ) {
V_296 = V_294 ;
V_297 = V_293 ;
} else {
V_296 = V_293 ;
V_297 = V_294 ;
}
V_122 = F_86 ( V_294 ) ;
F_209 ( V_122 ) ;
F_267 ( V_122 ) ;
F_213 ( V_122 ) ;
F_254 ( V_297 , V_298 ) ;
if ( F_242 ( V_296 ) )
F_257 ( V_296 ) ;
F_250 ( & V_10 -> V_24 ) ;
}
void F_269 ( struct V_25 * V_294 ,
struct V_25 * V_293 )
{
struct V_9 * V_10 ;
struct V_121 * V_122 ;
enum V_254 type = V_259 ;
if ( F_74 () )
return;
V_122 = F_86 ( V_294 ) ;
F_209 ( V_122 ) ;
V_10 = V_122 -> V_9 ;
F_49 ( V_10 , F_227 ( V_122 ) , - 1 ) ;
F_256 ( V_122 ) ;
F_213 ( V_122 ) ;
if ( F_270 ( V_294 ) )
type = V_260 ;
F_214 ( V_10 , V_293 , 1 , V_122 , type , true ) ;
}
static struct V_121 * F_271 ( struct V_25 * V_25 )
{
struct V_121 * V_122 ;
V_122 = F_86 ( V_25 ) ;
if ( F_199 ( V_122 ) && F_87 ( V_122 ) )
return V_122 ;
return NULL ;
}
bool F_272 ( struct V_25 * V_25 )
{
if ( F_74 () )
return false ;
return F_271 ( V_25 ) != NULL ;
}
void F_273 ( struct V_25 * V_25 )
{
struct V_121 * V_122 ;
V_122 = F_271 ( V_25 ) ;
if ( V_122 ) {
F_126 ( V_299 L_6 ,
V_122 , V_122 -> V_163 , V_122 -> V_9 ) ;
}
}
static int F_274 ( struct V_9 * V_10 ,
unsigned long long V_55 )
{
int V_300 ;
T_1 V_301 , V_302 ;
int V_75 = 0 ;
int V_303 = F_128 ( V_10 ) ;
T_1 V_304 , V_305 ;
int V_306 ;
V_300 = V_247 * V_303 ;
V_305 = F_127 ( & V_10 -> V_45 , V_156 ) ;
V_306 = 0 ;
while ( V_300 ) {
if ( F_275 ( V_14 ) ) {
V_75 = - V_252 ;
break;
}
F_192 ( & V_307 ) ;
V_301 = F_127 ( & V_10 -> V_140 , V_157 ) ;
if ( V_301 < V_55 ) {
V_75 = - V_268 ;
F_190 ( & V_307 ) ;
break;
}
V_302 = F_127 ( & V_10 -> V_45 , V_157 ) ;
if ( V_302 < V_55 )
V_306 = 1 ;
V_75 = F_276 ( & V_10 -> V_45 , V_55 ) ;
if ( ! V_75 ) {
if ( V_301 == V_55 )
V_10 -> V_168 = true ;
else
V_10 -> V_168 = false ;
}
F_190 ( & V_307 ) ;
if ( ! V_75 )
break;
F_131 ( V_10 , V_308 ,
V_167 ) ;
V_304 = F_127 ( & V_10 -> V_45 , V_156 ) ;
if ( V_304 >= V_305 )
V_300 -- ;
else
V_305 = V_304 ;
}
if ( ! V_75 && V_306 )
F_159 ( V_10 ) ;
return V_75 ;
}
static int F_277 ( struct V_9 * V_10 ,
unsigned long long V_55 )
{
int V_300 ;
T_1 V_302 , V_301 , V_305 , V_304 ;
int V_303 = F_128 ( V_10 ) ;
int V_75 = - V_267 ;
int V_306 = 0 ;
V_300 = V_303 * V_247 ;
V_305 = F_127 ( & V_10 -> V_140 , V_156 ) ;
while ( V_300 ) {
if ( F_275 ( V_14 ) ) {
V_75 = - V_252 ;
break;
}
F_192 ( & V_307 ) ;
V_302 = F_127 ( & V_10 -> V_45 , V_157 ) ;
if ( V_302 > V_55 ) {
V_75 = - V_268 ;
F_190 ( & V_307 ) ;
break;
}
V_301 = F_127 ( & V_10 -> V_140 , V_157 ) ;
if ( V_301 < V_55 )
V_306 = 1 ;
V_75 = F_276 ( & V_10 -> V_140 , V_55 ) ;
if ( ! V_75 ) {
if ( V_302 == V_55 )
V_10 -> V_168 = true ;
else
V_10 -> V_168 = false ;
}
F_190 ( & V_307 ) ;
if ( ! V_75 )
break;
F_131 ( V_10 , V_308 ,
V_166 |
V_167 ) ;
V_304 = F_127 ( & V_10 -> V_140 , V_156 ) ;
if ( V_304 >= V_305 )
V_300 -- ;
else
V_305 = V_304 ;
}
if ( ! V_75 && V_306 )
F_159 ( V_10 ) ;
return V_75 ;
}
unsigned long F_278 ( struct V_47 * V_47 , int V_309 ,
T_3 V_162 ,
unsigned long * V_177 )
{
unsigned long V_310 = 0 ;
struct V_17 * V_30 , * V_311 = NULL ;
unsigned long V_312 ;
int V_165 = 0 ;
struct V_26 * V_31 ;
unsigned long long V_44 ;
unsigned long V_179 ;
if ( V_309 > 0 )
return 0 ;
V_31 = F_20 ( F_77 ( V_47 ) , F_78 ( V_47 ) ) ;
do {
if ( V_311 )
V_30 = V_311 ;
else
V_30 = F_39 ( V_31 ) ;
if ( ! V_30 )
break;
V_179 = 0 ;
V_312 = F_148 ( V_30 -> V_52 , V_47 ,
V_162 , & V_179 ) ;
V_310 += V_312 ;
* V_177 += V_179 ;
F_29 ( & V_31 -> V_43 ) ;
V_311 = NULL ;
if ( ! V_312 ) {
do {
V_311 =
F_36 ( V_31 ) ;
if ( V_311 == V_30 )
F_76 ( & V_311 -> V_52 -> V_24 ) ;
else
break;
} while ( 1 );
}
F_26 ( V_30 -> V_52 , V_30 , V_31 ) ;
V_44 = F_33 ( & V_30 -> V_52 -> V_45 ) ;
F_22 ( V_30 -> V_52 , V_30 , V_31 , V_44 ) ;
F_30 ( & V_31 -> V_43 ) ;
F_76 ( & V_30 -> V_52 -> V_24 ) ;
V_165 ++ ;
if ( ! V_310 &&
( V_311 == NULL ||
V_165 > V_313 ) )
break;
} while ( ! V_310 );
if ( V_311 )
F_76 ( & V_311 -> V_52 -> V_24 ) ;
return V_310 ;
}
static int F_279 ( struct V_9 * V_10 ,
int V_46 , int V_19 , enum V_73 V_120 )
{
struct V_17 * V_30 ;
unsigned long V_163 , V_165 ;
struct V_314 * V_315 ;
struct V_25 * V_316 ;
struct V_47 * V_47 ;
int V_75 = 0 ;
V_47 = & F_280 ( V_46 ) -> V_317 [ V_19 ] ;
V_30 = F_15 ( V_10 , V_46 , V_19 ) ;
V_315 = & V_30 -> V_119 . V_318 [ V_120 ] ;
V_165 = F_57 ( V_30 , V_120 ) ;
V_165 += 256 ;
V_316 = NULL ;
while ( V_165 -- ) {
struct V_121 * V_122 ;
struct V_25 * V_25 ;
V_75 = 0 ;
F_281 ( & V_47 -> V_258 , V_163 ) ;
if ( F_282 ( V_315 ) ) {
F_283 ( & V_47 -> V_258 , V_163 ) ;
break;
}
V_25 = F_284 ( V_315 -> V_99 , struct V_25 , V_120 ) ;
if ( V_316 == V_25 ) {
F_285 ( & V_25 -> V_120 , V_315 ) ;
V_316 = NULL ;
F_283 ( & V_47 -> V_258 , V_163 ) ;
continue;
}
F_283 ( & V_47 -> V_258 , V_163 ) ;
V_122 = F_86 ( V_25 ) ;
V_75 = F_232 ( V_25 , V_122 , V_10 , V_308 ) ;
if ( V_75 == - V_251 || V_75 == - V_252 )
break;
if ( V_75 == - V_267 || V_75 == - V_268 ) {
V_316 = V_25 ;
F_286 () ;
} else
V_316 = NULL ;
}
if ( ! V_75 && ! F_282 ( V_315 ) )
return - V_267 ;
return V_75 ;
}
static int F_287 ( struct V_9 * V_10 , bool V_319 )
{
int V_75 ;
int V_46 , V_19 , V_320 ;
int V_321 = V_247 ;
struct V_91 * V_141 = V_10 -> V_24 . V_91 ;
F_100 ( & V_10 -> V_24 ) ;
V_320 = 0 ;
if ( V_319 )
goto V_322;
V_323:
do {
V_75 = - V_267 ;
if ( F_288 ( V_141 ) || ! F_282 ( & V_141 -> V_303 ) )
goto V_114;
V_75 = - V_252 ;
if ( F_275 ( V_14 ) )
goto V_114;
F_289 () ;
F_191 ( V_10 ) ;
V_75 = 0 ;
F_111 ( V_10 ) ;
F_60 (node, N_HIGH_MEMORY) {
for ( V_19 = 0 ; ! V_75 && V_19 < V_48 ; V_19 ++ ) {
enum V_73 V_74 ;
F_55 (l) {
V_75 = F_279 ( V_10 ,
V_46 , V_19 , V_74 ) ;
if ( V_75 )
break;
}
}
if ( V_75 )
break;
}
F_113 ( V_10 ) ;
F_159 ( V_10 ) ;
if ( V_75 == - V_251 )
goto V_322;
F_286 () ;
} while ( V_10 -> V_45 . V_324 > 0 || V_75 );
V_114:
F_76 ( & V_10 -> V_24 ) ;
return V_75 ;
V_322:
if ( F_288 ( V_141 ) || ! F_282 ( & V_141 -> V_303 ) || V_320 ) {
V_75 = - V_267 ;
goto V_114;
}
F_289 () ;
V_320 = 1 ;
while ( V_321 && V_10 -> V_45 . V_324 > 0 ) {
int V_325 ;
if ( F_275 ( V_14 ) ) {
V_75 = - V_252 ;
goto V_114;
}
V_325 = F_133 ( V_10 , V_308 ,
false ) ;
if ( ! V_325 ) {
V_321 -- ;
F_290 ( V_326 , V_327 / 10 ) ;
}
}
F_291 () ;
goto V_323;
}
int F_292 ( struct V_91 * V_92 , unsigned int V_328 )
{
return F_287 ( F_68 ( V_92 ) , true ) ;
}
static T_1 F_293 ( struct V_91 * V_92 , struct V_329 * V_330 )
{
return F_68 ( V_92 ) -> V_104 ;
}
static int F_294 ( struct V_91 * V_92 , struct V_329 * V_330 ,
T_1 V_55 )
{
int V_331 = 0 ;
struct V_9 * V_10 = F_68 ( V_92 ) ;
struct V_91 * V_36 = V_92 -> V_36 ;
struct V_9 * V_332 = NULL ;
if ( V_36 )
V_332 = F_68 ( V_36 ) ;
F_295 () ;
if ( ( ! V_332 || ! V_332 -> V_104 ) &&
( V_55 == 1 || V_55 == 0 ) ) {
if ( F_282 ( & V_92 -> V_303 ) )
V_10 -> V_104 = V_55 ;
else
V_331 = - V_267 ;
} else
V_331 = - V_268 ;
F_296 () ;
return V_331 ;
}
static unsigned long F_297 ( struct V_9 * V_10 ,
enum V_53 V_54 )
{
struct V_9 * V_107 ;
long V_55 = 0 ;
F_129 (iter, memcg)
V_55 += F_40 ( V_107 , V_54 ) ;
if ( V_55 < 0 )
V_55 = 0 ;
return V_55 ;
}
static inline T_1 F_298 ( struct V_9 * V_10 , bool V_333 )
{
T_1 V_55 ;
if ( ! F_6 ( V_10 ) ) {
if ( ! V_333 )
return F_127 ( & V_10 -> V_45 , V_156 ) ;
else
return F_127 ( & V_10 -> V_140 , V_156 ) ;
}
V_55 = F_297 ( V_10 , V_67 ) ;
V_55 += F_297 ( V_10 , V_68 ) ;
if ( V_333 )
V_55 += F_297 ( V_10 , V_62 ) ;
return V_55 << V_133 ;
}
static T_1 F_299 ( struct V_91 * V_92 , struct V_329 * V_330 )
{
struct V_9 * V_10 = F_68 ( V_92 ) ;
T_1 V_55 ;
int type , V_334 ;
type = F_300 ( V_330 -> V_196 ) ;
V_334 = F_301 ( V_330 -> V_196 ) ;
switch ( type ) {
case V_335 :
if ( V_334 == V_156 )
V_55 = F_298 ( V_10 , false ) ;
else
V_55 = F_127 ( & V_10 -> V_45 , V_334 ) ;
break;
case V_336 :
if ( V_334 == V_156 )
V_55 = F_298 ( V_10 , true ) ;
else
V_55 = F_127 ( & V_10 -> V_140 , V_334 ) ;
break;
default:
F_83 () ;
break;
}
return V_55 ;
}
static int F_302 ( struct V_91 * V_92 , struct V_329 * V_330 ,
const char * V_337 )
{
struct V_9 * V_10 = F_68 ( V_92 ) ;
int type , V_334 ;
unsigned long long V_55 ;
int V_75 ;
type = F_300 ( V_330 -> V_196 ) ;
V_334 = F_301 ( V_330 -> V_196 ) ;
switch ( V_334 ) {
case V_157 :
if ( F_6 ( V_10 ) ) {
V_75 = - V_268 ;
break;
}
V_75 = F_303 ( V_337 , & V_55 ) ;
if ( V_75 )
break;
if ( type == V_335 )
V_75 = F_274 ( V_10 , V_55 ) ;
else
V_75 = F_277 ( V_10 , V_55 ) ;
break;
case V_338 :
V_75 = F_303 ( V_337 , & V_55 ) ;
if ( V_75 )
break;
if ( type == V_335 )
V_75 = F_304 ( & V_10 -> V_45 , V_55 ) ;
else
V_75 = - V_268 ;
break;
default:
V_75 = - V_268 ;
break;
}
return V_75 ;
}
static void F_305 ( struct V_9 * V_10 ,
unsigned long long * V_339 , unsigned long long * V_340 )
{
struct V_91 * V_91 ;
unsigned long long V_341 , V_342 , V_343 ;
V_341 = F_127 ( & V_10 -> V_45 , V_157 ) ;
V_342 = F_127 ( & V_10 -> V_140 , V_157 ) ;
V_91 = V_10 -> V_24 . V_91 ;
if ( ! V_10 -> V_104 )
goto V_114;
while ( V_91 -> V_36 ) {
V_91 = V_91 -> V_36 ;
V_10 = F_68 ( V_91 ) ;
if ( ! V_10 -> V_104 )
break;
V_343 = F_127 ( & V_10 -> V_45 , V_157 ) ;
V_341 = F_109 ( V_341 , V_343 ) ;
V_343 = F_127 ( & V_10 -> V_140 , V_157 ) ;
V_342 = F_109 ( V_342 , V_343 ) ;
}
V_114:
* V_339 = V_341 ;
* V_340 = V_342 ;
return;
}
static int F_306 ( struct V_91 * V_92 , unsigned int V_328 )
{
struct V_9 * V_10 ;
int type , V_334 ;
V_10 = F_68 ( V_92 ) ;
type = F_300 ( V_328 ) ;
V_334 = F_301 ( V_328 ) ;
switch ( V_334 ) {
case V_344 :
if ( type == V_335 )
F_307 ( & V_10 -> V_45 ) ;
else
F_307 ( & V_10 -> V_140 ) ;
break;
case V_158 :
if ( type == V_335 )
F_308 ( & V_10 -> V_45 ) ;
else
F_308 ( & V_10 -> V_140 ) ;
break;
}
return 0 ;
}
static T_1 F_309 ( struct V_91 * V_141 ,
struct V_329 * V_330 )
{
return F_68 ( V_141 ) -> V_4 ;
}
static int F_310 ( struct V_91 * V_141 ,
struct V_329 * V_330 , T_1 V_55 )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
if ( V_55 >= ( 1 << V_345 ) )
return - V_268 ;
F_295 () ;
V_10 -> V_4 = V_55 ;
F_296 () ;
return 0 ;
}
static int F_310 ( struct V_91 * V_141 ,
struct V_329 * V_330 , T_1 V_55 )
{
return - V_346 ;
}
static void
F_311 ( struct V_9 * V_10 , struct V_347 * V_348 )
{
T_7 V_55 ;
V_55 = F_40 ( V_10 , V_67 ) ;
V_348 -> V_57 [ V_349 ] += V_55 * V_212 ;
V_55 = F_40 ( V_10 , V_68 ) ;
V_348 -> V_57 [ V_350 ] += V_55 * V_212 ;
V_55 = F_40 ( V_10 , V_205 ) ;
V_348 -> V_57 [ V_351 ] += V_55 * V_212 ;
V_55 = F_48 ( V_10 , V_69 ) ;
V_348 -> V_57 [ V_352 ] += V_55 ;
V_55 = F_48 ( V_10 , V_70 ) ;
V_348 -> V_57 [ V_353 ] += V_55 ;
if ( V_139 ) {
V_55 = F_40 ( V_10 , V_62 ) ;
V_348 -> V_57 [ V_354 ] += V_55 * V_212 ;
}
V_55 = F_48 ( V_10 , V_116 ) ;
V_348 -> V_57 [ V_355 ] += V_55 ;
V_55 = F_48 ( V_10 , V_118 ) ;
V_348 -> V_57 [ V_356 ] += V_55 ;
V_55 = F_59 ( V_10 , F_56 ( V_131 ) ) ;
V_348 -> V_57 [ V_357 ] += V_55 * V_212 ;
V_55 = F_59 ( V_10 , F_56 ( V_132 ) ) ;
V_348 -> V_57 [ V_358 ] += V_55 * V_212 ;
V_55 = F_59 ( V_10 , F_56 ( V_134 ) ) ;
V_348 -> V_57 [ V_359 ] += V_55 * V_212 ;
V_55 = F_59 ( V_10 , F_56 ( V_135 ) ) ;
V_348 -> V_57 [ V_360 ] += V_55 * V_212 ;
V_55 = F_59 ( V_10 , F_56 ( V_361 ) ) ;
V_348 -> V_57 [ V_362 ] += V_55 * V_212 ;
}
static void
F_312 ( struct V_9 * V_10 , struct V_347 * V_348 )
{
struct V_9 * V_107 ;
F_129 (iter, memcg)
F_311 ( V_107 , V_348 ) ;
}
static int F_313 ( struct V_363 * V_364 , void * V_185 )
{
int V_18 ;
unsigned long V_365 , V_366 , V_367 , V_368 ;
unsigned long V_369 ;
struct V_91 * V_92 = V_364 -> V_196 ;
struct V_9 * V_370 = F_68 ( V_92 ) ;
V_365 = F_59 ( V_370 , V_371 ) ;
F_314 ( V_364 , L_7 , V_365 ) ;
F_60 (nid, N_HIGH_MEMORY) {
V_369 = F_58 ( V_370 , V_18 , V_371 ) ;
F_314 ( V_364 , L_8 , V_18 , V_369 ) ;
}
F_315 ( V_364 , '\n' ) ;
V_366 = F_59 ( V_370 , V_170 ) ;
F_314 ( V_364 , L_9 , V_366 ) ;
F_60 (nid, N_HIGH_MEMORY) {
V_369 = F_58 ( V_370 , V_18 ,
V_170 ) ;
F_314 ( V_364 , L_8 , V_18 , V_369 ) ;
}
F_315 ( V_364 , '\n' ) ;
V_367 = F_59 ( V_370 , V_171 ) ;
F_314 ( V_364 , L_10 , V_367 ) ;
F_60 (nid, N_HIGH_MEMORY) {
V_369 = F_58 ( V_370 , V_18 ,
V_171 ) ;
F_314 ( V_364 , L_8 , V_18 , V_369 ) ;
}
F_315 ( V_364 , '\n' ) ;
V_368 = F_59 ( V_370 , F_56 ( V_361 ) ) ;
F_314 ( V_364 , L_11 , V_368 ) ;
F_60 (nid, N_HIGH_MEMORY) {
V_369 = F_58 ( V_370 , V_18 ,
F_56 ( V_361 ) ) ;
F_314 ( V_364 , L_8 , V_18 , V_369 ) ;
}
F_315 ( V_364 , '\n' ) ;
return 0 ;
}
static int F_316 ( struct V_91 * V_92 , struct V_329 * V_330 ,
struct V_372 * V_373 )
{
struct V_9 * V_370 = F_68 ( V_92 ) ;
struct V_347 V_374 ;
int V_219 ;
memset ( & V_374 , 0 , sizeof( V_374 ) ) ;
F_311 ( V_370 , & V_374 ) ;
for ( V_219 = 0 ; V_219 < V_375 ; V_219 ++ ) {
if ( V_219 == V_354 && ! V_139 )
continue;
V_373 -> V_376 ( V_373 , V_377 [ V_219 ] . V_378 , V_374 . V_57 [ V_219 ] ) ;
}
{
unsigned long long V_160 , V_340 ;
F_305 ( V_370 , & V_160 , & V_340 ) ;
V_373 -> V_376 ( V_373 , L_12 , V_160 ) ;
if ( V_139 )
V_373 -> V_376 ( V_373 , L_13 , V_340 ) ;
}
memset ( & V_374 , 0 , sizeof( V_374 ) ) ;
F_312 ( V_370 , & V_374 ) ;
for ( V_219 = 0 ; V_219 < V_375 ; V_219 ++ ) {
if ( V_219 == V_354 && ! V_139 )
continue;
V_373 -> V_376 ( V_373 , V_377 [ V_219 ] . V_379 , V_374 . V_57 [ V_219 ] ) ;
}
#ifdef F_317
{
int V_18 , V_19 ;
struct V_17 * V_30 ;
unsigned long V_380 [ 2 ] = { 0 , 0 } ;
unsigned long V_381 [ 2 ] = { 0 , 0 } ;
F_318 (nid)
for ( V_19 = 0 ; V_19 < V_48 ; V_19 ++ ) {
V_30 = F_15 ( V_370 , V_18 , V_19 ) ;
V_380 [ 0 ] +=
V_30 -> V_137 . V_380 [ 0 ] ;
V_380 [ 1 ] +=
V_30 -> V_137 . V_380 [ 1 ] ;
V_381 [ 0 ] +=
V_30 -> V_137 . V_381 [ 0 ] ;
V_381 [ 1 ] +=
V_30 -> V_137 . V_381 [ 1 ] ;
}
V_373 -> V_376 ( V_373 , L_14 , V_380 [ 0 ] ) ;
V_373 -> V_376 ( V_373 , L_15 , V_380 [ 1 ] ) ;
V_373 -> V_376 ( V_373 , L_16 , V_381 [ 0 ] ) ;
V_373 -> V_376 ( V_373 , L_17 , V_381 [ 1 ] ) ;
}
#endif
return 0 ;
}
static T_1 F_319 ( struct V_91 * V_141 , struct V_329 * V_330 )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
return F_110 ( V_10 ) ;
}
static int F_320 ( struct V_91 * V_141 , struct V_329 * V_330 ,
T_1 V_55 )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
struct V_9 * V_36 ;
if ( V_55 > 100 )
return - V_268 ;
if ( V_141 -> V_36 == NULL )
return - V_268 ;
V_36 = F_68 ( V_141 -> V_36 ) ;
F_295 () ;
if ( ( V_36 -> V_104 ) ||
( V_10 -> V_104 && ! F_282 ( & V_141 -> V_303 ) ) ) {
F_296 () ;
return - V_268 ;
}
V_10 -> V_143 = V_55 ;
F_296 () ;
return 0 ;
}
static void F_321 ( struct V_9 * V_10 , bool V_333 )
{
struct V_382 * V_383 ;
T_1 V_324 ;
int V_219 ;
F_8 () ;
if ( ! V_333 )
V_383 = F_72 ( V_10 -> V_384 . V_385 ) ;
else
V_383 = F_72 ( V_10 -> V_386 . V_385 ) ;
if ( ! V_383 )
goto V_145;
V_324 = F_298 ( V_10 , V_333 ) ;
V_219 = V_383 -> V_387 ;
for (; V_219 >= 0 && F_65 ( V_383 -> V_388 [ V_219 ] . V_389 > V_324 ) ; V_219 -- )
F_322 ( V_383 -> V_388 [ V_219 ] . V_390 , 1 ) ;
V_219 ++ ;
for (; V_219 < V_383 -> V_391 && F_65 ( V_383 -> V_388 [ V_219 ] . V_389 <= V_324 ) ; V_219 ++ )
F_322 ( V_383 -> V_388 [ V_219 ] . V_390 , 1 ) ;
V_383 -> V_387 = V_219 - 1 ;
V_145:
F_10 () ;
}
static void F_66 ( struct V_9 * V_10 )
{
while ( V_10 ) {
F_321 ( V_10 , false ) ;
if ( V_139 )
F_321 ( V_10 , true ) ;
V_10 = F_32 ( V_10 ) ;
}
}
static int F_323 ( const void * V_392 , const void * V_393 )
{
const struct F_66 * V_394 = V_392 ;
const struct F_66 * V_395 = V_393 ;
return V_394 -> V_389 - V_395 -> V_389 ;
}
static int F_324 ( struct V_9 * V_10 )
{
struct V_396 * V_397 ;
F_325 (ev, &memcg->oom_notify, list)
F_322 ( V_397 -> V_390 , 1 ) ;
return 0 ;
}
static void F_162 ( struct V_9 * V_10 )
{
struct V_9 * V_107 ;
F_129 (iter, memcg)
F_324 ( V_107 ) ;
}
static int F_326 ( struct V_91 * V_141 ,
struct V_329 * V_330 , struct V_398 * V_390 , const char * args )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
struct V_399 * V_384 ;
struct V_382 * V_400 ;
int type = F_300 ( V_330 -> V_196 ) ;
T_1 V_389 , V_324 ;
int V_219 , V_391 , V_75 ;
V_75 = F_303 ( args , & V_389 ) ;
if ( V_75 )
return V_75 ;
F_192 ( & V_10 -> V_401 ) ;
if ( type == V_335 )
V_384 = & V_10 -> V_384 ;
else if ( type == V_336 )
V_384 = & V_10 -> V_386 ;
else
F_83 () ;
V_324 = F_298 ( V_10 , type == V_336 ) ;
if ( V_384 -> V_385 )
F_321 ( V_10 , type == V_336 ) ;
V_391 = V_384 -> V_385 ? V_384 -> V_385 -> V_391 + 1 : 1 ;
V_400 = F_327 ( sizeof( * V_400 ) + V_391 * sizeof( struct F_66 ) ,
V_308 ) ;
if ( ! V_400 ) {
V_75 = - V_251 ;
goto V_145;
}
V_400 -> V_391 = V_391 ;
if ( V_384 -> V_385 ) {
memcpy ( V_400 -> V_388 , V_384 -> V_385 -> V_388 , ( V_391 - 1 ) *
sizeof( struct F_66 ) ) ;
}
V_400 -> V_388 [ V_391 - 1 ] . V_390 = V_390 ;
V_400 -> V_388 [ V_391 - 1 ] . V_389 = V_389 ;
F_328 ( V_400 -> V_388 , V_391 , sizeof( struct F_66 ) ,
F_323 , NULL ) ;
V_400 -> V_387 = - 1 ;
for ( V_219 = 0 ; V_219 < V_391 ; V_219 ++ ) {
if ( V_400 -> V_388 [ V_219 ] . V_389 < V_324 ) {
++ V_400 -> V_387 ;
}
}
F_329 ( V_384 -> V_402 ) ;
V_384 -> V_402 = V_384 -> V_385 ;
F_330 ( V_384 -> V_385 , V_400 ) ;
F_112 () ;
V_145:
F_190 ( & V_10 -> V_401 ) ;
return V_75 ;
}
static void F_331 ( struct V_91 * V_141 ,
struct V_329 * V_330 , struct V_398 * V_390 )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
struct V_399 * V_384 ;
struct V_382 * V_400 ;
int type = F_300 ( V_330 -> V_196 ) ;
T_1 V_324 ;
int V_219 , V_403 , V_391 ;
F_192 ( & V_10 -> V_401 ) ;
if ( type == V_335 )
V_384 = & V_10 -> V_384 ;
else if ( type == V_336 )
V_384 = & V_10 -> V_386 ;
else
F_83 () ;
F_5 ( ! V_384 ) ;
if ( ! V_384 -> V_385 )
goto V_145;
V_324 = F_298 ( V_10 , type == V_336 ) ;
F_321 ( V_10 , type == V_336 ) ;
V_391 = 0 ;
for ( V_219 = 0 ; V_219 < V_384 -> V_385 -> V_391 ; V_219 ++ ) {
if ( V_384 -> V_385 -> V_388 [ V_219 ] . V_390 != V_390 )
V_391 ++ ;
}
V_400 = V_384 -> V_402 ;
if ( ! V_391 ) {
F_329 ( V_400 ) ;
V_400 = NULL ;
goto V_404;
}
V_400 -> V_391 = V_391 ;
V_400 -> V_387 = - 1 ;
for ( V_219 = 0 , V_403 = 0 ; V_219 < V_384 -> V_385 -> V_391 ; V_219 ++ ) {
if ( V_384 -> V_385 -> V_388 [ V_219 ] . V_390 == V_390 )
continue;
V_400 -> V_388 [ V_403 ] = V_384 -> V_385 -> V_388 [ V_219 ] ;
if ( V_400 -> V_388 [ V_403 ] . V_389 < V_324 ) {
++ V_400 -> V_387 ;
}
V_403 ++ ;
}
V_404:
V_384 -> V_402 = V_384 -> V_385 ;
F_330 ( V_384 -> V_385 , V_400 ) ;
F_112 () ;
V_145:
F_190 ( & V_10 -> V_401 ) ;
}
static int F_332 ( struct V_91 * V_141 ,
struct V_329 * V_330 , struct V_398 * V_390 , const char * args )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
struct V_396 * V_328 ;
int type = F_300 ( V_330 -> V_196 ) ;
F_5 ( type != V_405 ) ;
V_328 = F_327 ( sizeof( * V_328 ) , V_308 ) ;
if ( ! V_328 )
return - V_251 ;
F_29 ( & V_198 ) ;
V_328 -> V_390 = V_390 ;
F_333 ( & V_328 -> V_315 , & V_10 -> V_406 ) ;
if ( F_136 ( & V_10 -> V_182 ) )
F_322 ( V_390 , 1 ) ;
F_30 ( & V_198 ) ;
return 0 ;
}
static void F_334 ( struct V_91 * V_141 ,
struct V_329 * V_330 , struct V_398 * V_390 )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
struct V_396 * V_397 , * V_343 ;
int type = F_300 ( V_330 -> V_196 ) ;
F_5 ( type != V_405 ) ;
F_29 ( & V_198 ) ;
F_335 (ev, tmp, &memcg->oom_notify, list) {
if ( V_397 -> V_390 == V_390 ) {
F_336 ( & V_397 -> V_315 ) ;
F_329 ( V_397 ) ;
}
}
F_30 ( & V_198 ) ;
}
static int F_337 ( struct V_91 * V_141 ,
struct V_329 * V_330 , struct V_372 * V_373 )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
V_373 -> V_376 ( V_373 , L_18 , V_10 -> V_200 ) ;
if ( F_136 ( & V_10 -> V_182 ) )
V_373 -> V_376 ( V_373 , L_19 , 1 ) ;
else
V_373 -> V_376 ( V_373 , L_19 , 0 ) ;
return 0 ;
}
static int F_338 ( struct V_91 * V_141 ,
struct V_329 * V_330 , T_1 V_55 )
{
struct V_9 * V_10 = F_68 ( V_141 ) ;
struct V_9 * V_36 ;
if ( ! V_141 -> V_36 || ! ( ( V_55 == 0 ) || ( V_55 == 1 ) ) )
return - V_268 ;
V_36 = F_68 ( V_141 -> V_36 ) ;
F_295 () ;
if ( ( V_36 -> V_104 ) ||
( V_10 -> V_104 && ! F_282 ( & V_141 -> V_303 ) ) ) {
F_296 () ;
return - V_268 ;
}
V_10 -> V_200 = V_55 ;
if ( ! V_55 )
F_159 ( V_10 ) ;
F_296 () ;
return 0 ;
}
static int F_339 ( struct V_407 * V_297 , struct V_65 * V_65 )
{
struct V_91 * V_92 = V_65 -> V_408 -> V_409 -> V_410 ;
V_65 -> V_411 = & V_412 ;
return F_340 ( V_65 , F_313 , V_92 ) ;
}
static int F_341 ( struct V_91 * V_92 , struct V_413 * V_414 )
{
return F_342 ( V_92 , V_414 ) ;
}
static void F_343 ( struct V_413 * V_414 ,
struct V_91 * V_92 )
{
F_344 ( V_92 , V_414 ) ;
}
static int F_341 ( struct V_91 * V_92 , struct V_413 * V_414 )
{
return 0 ;
}
static void F_343 ( struct V_413 * V_414 ,
struct V_91 * V_92 )
{
}
static int F_345 ( struct V_91 * V_92 , struct V_413 * V_414 )
{
if ( ! V_139 )
return 0 ;
return F_346 ( V_92 , V_414 , V_415 ,
F_347 ( V_415 ) ) ;
}
static int F_345 ( struct V_91 * V_92 , struct V_413 * V_414 )
{
return 0 ;
}
static int F_348 ( struct V_9 * V_10 , int V_46 )
{
struct V_416 * V_417 ;
struct V_17 * V_30 ;
enum V_73 V_74 ;
int V_47 , V_343 = V_46 ;
if ( ! F_349 ( V_46 , V_418 ) )
V_343 = - 1 ;
V_417 = F_350 ( sizeof( * V_417 ) , V_308 , V_343 ) ;
if ( ! V_417 )
return 1 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_30 = & V_417 -> V_22 [ V_47 ] ;
F_55 (l)
F_161 ( & V_30 -> V_119 . V_318 [ V_74 ] ) ;
V_30 -> V_39 = 0 ;
V_30 -> V_38 = false ;
V_30 -> V_52 = V_10 ;
}
V_10 -> V_20 . V_21 [ V_46 ] = V_417 ;
return 0 ;
}
static void F_351 ( struct V_9 * V_10 , int V_46 )
{
F_329 ( V_10 -> V_20 . V_21 [ V_46 ] ) ;
}
static struct V_9 * F_352 ( void )
{
struct V_9 * V_52 ;
int V_391 = sizeof( struct V_9 ) ;
if ( V_391 < V_212 )
V_52 = F_353 ( V_391 , V_308 ) ;
else
V_52 = F_354 ( V_391 ) ;
if ( ! V_52 )
return NULL ;
V_52 -> V_57 = F_355 ( struct V_419 ) ;
if ( ! V_52 -> V_57 )
goto V_420;
F_356 ( & V_52 -> V_59 ) ;
return V_52 ;
V_420:
if ( V_391 < V_212 )
F_329 ( V_52 ) ;
else
F_357 ( V_52 ) ;
return NULL ;
}
static void F_358 ( struct V_213 * V_217 )
{
struct V_9 * V_10 ;
V_10 = F_69 ( V_217 , struct V_9 , V_421 ) ;
F_357 ( V_10 ) ;
}
static void F_359 ( struct V_422 * V_422 )
{
struct V_9 * V_10 ;
V_10 = F_69 ( V_422 , struct V_9 , V_423 ) ;
F_360 ( & V_10 -> V_421 , F_358 ) ;
F_361 ( & V_10 -> V_421 ) ;
}
static void F_362 ( struct V_9 * V_10 )
{
int V_46 ;
F_34 ( V_10 ) ;
F_363 ( & V_112 , & V_10 -> V_24 ) ;
F_35 (node)
F_351 ( V_10 , V_46 ) ;
F_364 ( V_10 -> V_57 ) ;
if ( sizeof( struct V_9 ) < V_212 )
F_365 ( V_10 , V_423 ) ;
else
F_366 ( & V_10 -> V_423 , F_359 ) ;
}
static void F_7 ( struct V_9 * V_10 )
{
F_67 ( & V_10 -> V_424 ) ;
}
static void F_367 ( struct V_9 * V_10 , int V_58 )
{
if ( F_368 ( V_58 , & V_10 -> V_424 ) ) {
struct V_9 * V_36 = F_32 ( V_10 ) ;
F_362 ( V_10 ) ;
if ( V_36 )
F_13 ( V_36 ) ;
}
}
static void F_13 ( struct V_9 * V_10 )
{
F_367 ( V_10 , 1 ) ;
}
struct V_9 * F_32 ( struct V_9 * V_10 )
{
if ( ! V_10 -> V_45 . V_36 )
return NULL ;
return F_200 ( V_10 -> V_45 . V_36 , V_45 ) ;
}
static void T_8 F_369 ( void )
{
if ( ! F_74 () && V_425 )
V_139 = 1 ;
}
static void T_8 F_369 ( void )
{
}
static int F_370 ( void )
{
struct V_426 * V_427 ;
struct V_26 * V_428 ;
int V_343 , V_46 , V_47 ;
F_35 (node) {
V_343 = V_46 ;
if ( ! F_349 ( V_46 , V_418 ) )
V_343 = - 1 ;
V_427 = F_350 ( sizeof( * V_427 ) , V_308 , V_343 ) ;
if ( ! V_427 )
goto V_429;
V_27 . V_28 [ V_46 ] = V_427 ;
for ( V_47 = 0 ; V_47 < V_48 ; V_47 ++ ) {
V_428 = & V_427 -> V_29 [ V_47 ] ;
V_428 -> V_35 = V_430 ;
F_356 ( & V_428 -> V_43 ) ;
}
}
return 0 ;
V_429:
F_35 (node) {
if ( ! V_27 . V_28 [ V_46 ] )
break;
F_329 ( V_27 . V_28 [ V_46 ] ) ;
V_27 . V_28 [ V_46 ] = NULL ;
}
return 1 ;
}
static struct V_23 * T_9
F_371 ( struct V_413 * V_414 , struct V_91 * V_92 )
{
struct V_9 * V_10 , * V_36 ;
long error = - V_251 ;
int V_46 ;
V_10 = F_352 () ;
if ( ! V_10 )
return F_372 ( error ) ;
F_35 (node)
if ( F_348 ( V_10 , V_46 ) )
goto V_431;
if ( V_92 -> V_36 == NULL ) {
int V_56 ;
F_369 () ;
V_36 = NULL ;
if ( F_370 () )
goto V_431;
V_103 = V_10 ;
F_373 (cpu) {
struct V_206 * V_207 =
& F_43 ( V_208 , V_56 ) ;
F_360 ( & V_207 -> V_217 , F_179 ) ;
}
F_374 ( F_195 , 0 ) ;
} else {
V_36 = F_68 ( V_92 -> V_36 ) ;
V_10 -> V_104 = V_36 -> V_104 ;
V_10 -> V_200 = V_36 -> V_200 ;
}
if ( V_36 && V_36 -> V_104 ) {
F_375 ( & V_10 -> V_45 , & V_36 -> V_45 ) ;
F_375 ( & V_10 -> V_140 , & V_36 -> V_140 ) ;
F_7 ( V_36 ) ;
} else {
F_375 ( & V_10 -> V_45 , NULL ) ;
F_375 ( & V_10 -> V_140 , NULL ) ;
}
V_10 -> V_176 = V_89 ;
F_161 ( & V_10 -> V_406 ) ;
if ( V_36 )
V_10 -> V_143 = F_110 ( V_36 ) ;
F_140 ( & V_10 -> V_424 , 1 ) ;
V_10 -> V_4 = 0 ;
F_376 ( & V_10 -> V_401 ) ;
return & V_10 -> V_24 ;
V_431:
F_362 ( V_10 ) ;
return F_372 ( error ) ;
}
static int F_377 ( struct V_413 * V_414 ,
struct V_91 * V_92 )
{
struct V_9 * V_10 = F_68 ( V_92 ) ;
return F_287 ( V_10 , false ) ;
}
static void F_378 ( struct V_413 * V_414 ,
struct V_91 * V_92 )
{
struct V_9 * V_10 = F_68 ( V_92 ) ;
F_343 ( V_414 , V_92 ) ;
F_13 ( V_10 ) ;
}
static int F_379 ( struct V_413 * V_414 ,
struct V_91 * V_92 )
{
int V_75 ;
V_75 = F_346 ( V_92 , V_414 , V_432 ,
F_347 ( V_432 ) ) ;
if ( ! V_75 )
V_75 = F_345 ( V_92 , V_414 ) ;
if ( ! V_75 )
V_75 = F_341 ( V_92 , V_414 ) ;
return V_75 ;
}
static int F_380 ( unsigned long V_58 )
{
int V_75 = 0 ;
int V_433 = V_434 ;
struct V_9 * V_10 = V_2 . V_3 ;
if ( F_6 ( V_10 ) ) {
V_2 . V_435 += V_58 ;
return V_75 ;
}
if ( V_58 > 1 ) {
struct V_234 * V_214 ;
if ( F_198 ( & V_10 -> V_45 , V_212 * V_58 , & V_214 ) )
goto V_436;
if ( V_139 && F_198 ( & V_10 -> V_140 ,
V_212 * V_58 , & V_214 ) ) {
F_178 ( & V_10 -> V_45 , V_212 * V_58 ) ;
goto V_436;
}
V_2 . V_435 += V_58 ;
return V_75 ;
}
V_436:
while ( V_58 -- ) {
if ( F_275 ( V_14 ) ) {
V_75 = - V_252 ;
break;
}
if ( ! V_433 -- ) {
V_433 = V_434 ;
F_286 () ;
}
V_75 = F_201 ( NULL ,
V_308 , 1 , & V_10 , false ) ;
if ( V_75 )
return V_75 ;
V_2 . V_435 ++ ;
}
return V_75 ;
}
static struct V_25 * F_381 ( struct V_437 * V_438 ,
unsigned long V_439 , T_10 V_440 )
{
struct V_25 * V_25 = F_382 ( V_438 , V_439 , V_440 ) ;
if ( ! V_25 || ! F_171 ( V_25 ) )
return NULL ;
if ( F_242 ( V_25 ) ) {
if ( ! F_1 () || F_383 ( V_25 ) > 2 )
return NULL ;
} else if ( ! F_3 () )
return NULL ;
if ( ! F_233 ( V_25 ) )
return NULL ;
return V_25 ;
}
static struct V_25 * F_384 ( struct V_437 * V_438 ,
unsigned long V_439 , T_10 V_440 , T_6 * V_289 )
{
int V_441 ;
struct V_25 * V_25 = NULL ;
T_6 V_253 = F_385 ( V_440 ) ;
if ( ! F_1 () || F_386 ( V_253 ) )
return NULL ;
V_441 = F_387 ( V_253 , & V_25 ) ;
if ( V_441 > 1 ) {
if ( V_25 )
F_239 ( V_25 ) ;
return NULL ;
}
if ( V_139 )
V_289 -> V_55 = V_253 . V_55 ;
return V_25 ;
}
static struct V_25 * F_388 ( struct V_437 * V_438 ,
unsigned long V_439 , T_10 V_440 , T_6 * V_289 )
{
struct V_25 * V_25 = NULL ;
struct V_407 * V_407 ;
struct V_442 * V_274 ;
T_11 V_443 ;
if ( ! V_438 -> V_444 )
return NULL ;
if ( ! F_3 () )
return NULL ;
V_407 = V_438 -> V_444 -> V_445 . V_446 -> V_447 ;
V_274 = V_438 -> V_444 -> V_448 ;
if ( F_389 ( V_440 ) )
V_443 = F_390 ( V_438 , V_439 ) ;
else
V_443 = F_391 ( V_440 ) ;
V_25 = F_392 ( V_274 , V_443 ) ;
#ifdef F_393
if ( F_394 ( V_25 ) ) {
T_6 V_333 = F_395 ( V_25 ) ;
if ( V_139 )
* V_289 = V_333 ;
V_25 = F_392 ( & V_449 , V_333 . V_55 ) ;
}
#endif
return V_25 ;
}
static int F_396 ( struct V_437 * V_438 ,
unsigned long V_439 , T_10 V_440 , union V_450 * V_78 )
{
struct V_25 * V_25 = NULL ;
struct V_121 * V_122 ;
int V_75 = 0 ;
T_6 V_253 = { . V_55 = 0 } ;
if ( F_397 ( V_440 ) )
V_25 = F_381 ( V_438 , V_439 , V_440 ) ;
else if ( F_398 ( V_440 ) )
V_25 = F_384 ( V_438 , V_439 , V_440 , & V_253 ) ;
else if ( F_389 ( V_440 ) || F_399 ( V_440 ) )
V_25 = F_388 ( V_438 , V_439 , V_440 , & V_253 ) ;
if ( ! V_25 && ! V_253 . V_55 )
return 0 ;
if ( V_25 ) {
V_122 = F_86 ( V_25 ) ;
if ( F_87 ( V_122 ) && V_122 -> V_9 == V_2 . V_123 ) {
V_75 = V_451 ;
if ( V_78 )
V_78 -> V_25 = V_25 ;
}
if ( ! V_75 || ! V_78 )
F_239 ( V_25 ) ;
}
if ( V_253 . V_55 && ! V_75 &&
F_75 ( & V_2 . V_123 -> V_24 ) == F_212 ( V_253 ) ) {
V_75 = V_452 ;
if ( V_78 )
V_78 -> V_253 = V_253 ;
}
return V_75 ;
}
static int F_400 ( T_12 * V_453 ,
unsigned long V_439 , unsigned long V_454 ,
struct V_455 * V_456 )
{
struct V_437 * V_438 = V_456 -> V_196 ;
T_10 * V_457 ;
T_13 * V_458 ;
F_401 ( V_456 -> V_96 , V_453 ) ;
V_457 = F_402 ( V_438 -> V_459 , V_453 , V_439 , & V_458 ) ;
for (; V_439 != V_454 ; V_457 ++ , V_439 += V_212 )
if ( F_396 ( V_438 , V_439 , * V_457 , NULL ) )
V_2 . V_435 ++ ;
F_403 ( V_457 - 1 , V_458 ) ;
F_286 () ;
return 0 ;
}
static unsigned long F_404 ( struct V_95 * V_96 )
{
unsigned long V_435 ;
struct V_437 * V_438 ;
F_405 ( & V_96 -> V_460 ) ;
for ( V_438 = V_96 -> V_461 ; V_438 ; V_438 = V_438 -> V_462 ) {
struct V_455 V_463 = {
. V_464 = F_400 ,
. V_96 = V_96 ,
. V_196 = V_438 ,
} ;
if ( F_406 ( V_438 ) )
continue;
F_407 ( V_438 -> V_465 , V_438 -> V_466 ,
& V_463 ) ;
}
F_408 ( & V_96 -> V_460 ) ;
V_435 = V_2 . V_435 ;
V_2 . V_435 = 0 ;
return V_435 ;
}
static int F_409 ( struct V_95 * V_96 )
{
unsigned long V_435 = F_404 ( V_96 ) ;
F_90 ( V_2 . V_146 ) ;
V_2 . V_146 = V_14 ;
return F_380 ( V_435 ) ;
}
static void F_410 ( void )
{
struct V_9 * V_123 = V_2 . V_123 ;
struct V_9 * V_3 = V_2 . V_3 ;
if ( V_2 . V_435 ) {
F_204 ( V_2 . V_3 , V_2 . V_435 ) ;
V_2 . V_435 = 0 ;
}
if ( V_2 . V_467 ) {
F_204 ( V_2 . V_123 , V_2 . V_467 ) ;
V_2 . V_467 = 0 ;
}
if ( V_2 . V_468 ) {
if ( ! F_6 ( V_2 . V_123 ) )
F_178 ( & V_2 . V_123 -> V_140 ,
V_212 * V_2 . V_468 ) ;
F_367 ( V_2 . V_123 , V_2 . V_468 ) ;
if ( ! F_6 ( V_2 . V_3 ) ) {
F_178 ( & V_2 . V_3 -> V_45 ,
V_212 * V_2 . V_468 ) ;
}
V_2 . V_468 = 0 ;
}
F_159 ( V_123 ) ;
F_159 ( V_3 ) ;
F_411 ( & V_2 . V_148 ) ;
}
static void F_412 ( void )
{
struct V_9 * V_123 = V_2 . V_123 ;
V_2 . V_146 = NULL ;
F_410 () ;
F_29 ( & V_2 . V_43 ) ;
V_2 . V_123 = NULL ;
V_2 . V_3 = NULL ;
F_30 ( & V_2 . V_43 ) ;
F_113 ( V_123 ) ;
}
static int F_413 ( struct V_413 * V_414 ,
struct V_91 * V_91 ,
struct V_469 * V_470 )
{
struct V_94 * V_34 = F_414 ( V_470 ) ;
int V_75 = 0 ;
struct V_9 * V_10 = F_68 ( V_91 ) ;
if ( V_10 -> V_4 ) {
struct V_95 * V_96 ;
struct V_9 * V_123 = F_9 ( V_34 ) ;
F_90 ( V_123 == V_10 ) ;
V_96 = F_415 ( V_34 ) ;
if ( ! V_96 )
return 0 ;
if ( V_96 -> V_97 == V_34 ) {
F_90 ( V_2 . V_123 ) ;
F_90 ( V_2 . V_3 ) ;
F_90 ( V_2 . V_435 ) ;
F_90 ( V_2 . V_467 ) ;
F_90 ( V_2 . V_468 ) ;
F_111 ( V_123 ) ;
F_29 ( & V_2 . V_43 ) ;
V_2 . V_123 = V_123 ;
V_2 . V_3 = V_10 ;
F_30 ( & V_2 . V_43 ) ;
V_75 = F_409 ( V_96 ) ;
if ( V_75 )
F_412 () ;
}
F_416 ( V_96 ) ;
}
return V_75 ;
}
static void F_417 ( struct V_413 * V_414 ,
struct V_91 * V_91 ,
struct V_469 * V_470 )
{
F_412 () ;
}
static int F_418 ( T_12 * V_453 ,
unsigned long V_439 , unsigned long V_454 ,
struct V_455 * V_456 )
{
int V_75 = 0 ;
struct V_437 * V_438 = V_456 -> V_196 ;
T_10 * V_457 ;
T_13 * V_458 ;
F_401 ( V_456 -> V_96 , V_453 ) ;
V_50:
V_457 = F_402 ( V_438 -> V_459 , V_453 , V_439 , & V_458 ) ;
for (; V_439 != V_454 ; V_439 += V_212 ) {
T_10 V_440 = * ( V_457 ++ ) ;
union V_450 V_78 ;
int type ;
struct V_25 * V_25 ;
struct V_121 * V_122 ;
T_6 V_253 ;
if ( ! V_2 . V_435 )
break;
type = F_396 ( V_438 , V_439 , V_440 , & V_78 ) ;
switch ( type ) {
case V_451 :
V_25 = V_78 . V_25 ;
if ( F_234 ( V_25 ) )
goto V_272;
V_122 = F_86 ( V_25 ) ;
if ( ! F_229 ( V_25 , 1 , V_122 ,
V_2 . V_123 , V_2 . V_3 , false ) ) {
V_2 . V_435 -- ;
V_2 . V_467 ++ ;
}
F_238 ( V_25 ) ;
V_272:
F_239 ( V_25 ) ;
break;
case V_452 :
V_253 = V_78 . V_253 ;
if ( ! F_263 ( V_253 ,
V_2 . V_123 , V_2 . V_3 , false ) ) {
V_2 . V_435 -- ;
V_2 . V_468 ++ ;
}
break;
default:
break;
}
}
F_403 ( V_457 - 1 , V_458 ) ;
F_286 () ;
if ( V_439 != V_454 ) {
V_75 = F_380 ( 1 ) ;
if ( ! V_75 )
goto V_50;
}
return V_75 ;
}
static void F_419 ( struct V_95 * V_96 )
{
struct V_437 * V_438 ;
F_289 () ;
V_50:
if ( F_65 ( ! F_420 ( & V_96 -> V_460 ) ) ) {
F_410 () ;
F_286 () ;
goto V_50;
}
for ( V_438 = V_96 -> V_461 ; V_438 ; V_438 = V_438 -> V_462 ) {
int V_75 ;
struct V_455 V_471 = {
. V_464 = F_418 ,
. V_96 = V_96 ,
. V_196 = V_438 ,
} ;
if ( F_406 ( V_438 ) )
continue;
V_75 = F_407 ( V_438 -> V_465 , V_438 -> V_466 ,
& V_471 ) ;
if ( V_75 )
break;
}
F_408 ( & V_96 -> V_460 ) ;
}
static void F_421 ( struct V_413 * V_414 ,
struct V_91 * V_92 ,
struct V_469 * V_470 )
{
struct V_94 * V_34 = F_414 ( V_470 ) ;
struct V_95 * V_96 = F_415 ( V_34 ) ;
if ( V_96 ) {
if ( V_2 . V_3 )
F_419 ( V_96 ) ;
F_422 ( V_96 ) ;
F_416 ( V_96 ) ;
}
if ( V_2 . V_3 )
F_412 () ;
}
static int F_413 ( struct V_413 * V_414 ,
struct V_91 * V_91 ,
struct V_469 * V_470 )
{
return 0 ;
}
static void F_417 ( struct V_413 * V_414 ,
struct V_91 * V_91 ,
struct V_469 * V_470 )
{
}
static void F_421 ( struct V_413 * V_414 ,
struct V_91 * V_92 ,
struct V_469 * V_470 )
{
}
static int T_8 F_423 ( char * V_348 )
{
if ( ! strcmp ( V_348 , L_20 ) )
V_425 = 1 ;
else if ( ! strcmp ( V_348 , L_21 ) )
V_425 = 0 ;
return 1 ;
}
