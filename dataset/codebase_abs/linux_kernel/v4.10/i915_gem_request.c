static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_2 )
{
return F_3 ( V_2 ) -> V_3 -> V_4 -> V_5 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
return F_5 ( F_3 ( V_2 ) ) ;
}
static bool F_6 ( struct V_1 * V_2 )
{
if ( F_4 ( V_2 ) )
return false ;
F_7 ( F_3 ( V_2 ) ) ;
return true ;
}
static signed long F_8 ( struct V_1 * V_2 ,
bool V_6 ,
signed long V_7 )
{
return F_9 ( F_3 ( V_2 ) , V_6 , V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_3 ( V_2 ) ;
F_11 ( V_9 -> V_10 -> V_11 , V_9 ) ;
}
int F_12 ( struct V_8 * V_9 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
F_13 ( ! V_9 || ! V_13 || V_9 -> V_17 ) ;
if ( ! V_9 || ! V_13 )
return - V_18 ;
if ( V_9 -> V_17 )
return - V_18 ;
V_15 = V_9 -> V_10 ;
V_17 = V_13 -> V_19 ;
F_14 ( & V_17 -> V_20 . V_21 ) ;
V_9 -> V_17 = V_17 ;
F_15 ( & V_9 -> V_22 , & V_17 -> V_20 . V_23 ) ;
F_16 ( & V_17 -> V_20 . V_21 ) ;
return 0 ;
}
static inline void
F_17 ( struct V_8 * V_24 )
{
struct V_16 * V_17 = V_24 -> V_17 ;
if ( ! V_17 )
return;
F_14 ( & V_17 -> V_20 . V_21 ) ;
F_18 ( & V_24 -> V_22 ) ;
V_24 -> V_17 = NULL ;
F_16 ( & V_17 -> V_20 . V_21 ) ;
}
static struct V_25 *
F_19 ( struct V_14 * V_10 )
{
return F_20 ( V_10 -> V_26 , V_27 ) ;
}
static void
F_21 ( struct V_14 * V_10 ,
struct V_25 * V_28 )
{
F_11 ( V_10 -> V_26 , V_28 ) ;
}
static void
F_22 ( struct V_29 * V_30 ,
struct V_29 * signal ,
struct V_25 * V_28 ,
unsigned long V_31 )
{
F_23 ( & V_28 -> V_32 ) ;
F_24 ( & V_28 -> V_33 , & signal -> V_34 ) ;
F_24 ( & V_28 -> V_35 , & V_30 -> V_36 ) ;
V_28 -> V_37 = signal ;
V_28 -> V_31 = V_31 ;
}
static int
F_25 ( struct V_14 * V_10 ,
struct V_29 * V_30 ,
struct V_29 * signal )
{
struct V_25 * V_28 ;
V_28 = F_19 ( V_10 ) ;
if ( ! V_28 )
return - V_38 ;
F_22 ( V_30 , signal , V_28 , V_39 ) ;
return 0 ;
}
static void
F_26 ( struct V_14 * V_10 , struct V_29 * V_30 )
{
struct V_25 * V_28 , * V_40 ;
F_27 ( ! F_28 ( & V_30 -> V_41 ) ) ;
F_29 (dep, next, &pt->signalers_list, signal_link) {
F_18 ( & V_28 -> V_33 ) ;
if ( V_28 -> V_31 & V_39 )
F_21 ( V_10 , V_28 ) ;
}
F_29 (dep, next, &pt->waiters_list, wait_link) {
F_18 ( & V_28 -> V_35 ) ;
if ( V_28 -> V_31 & V_39 )
F_21 ( V_10 , V_28 ) ;
}
}
static void
F_30 ( struct V_29 * V_30 )
{
F_23 ( & V_30 -> V_36 ) ;
F_23 ( & V_30 -> V_34 ) ;
F_31 ( & V_30 -> V_41 ) ;
V_30 -> V_42 = V_43 ;
}
void F_32 ( struct V_44 * V_45 ,
struct V_8 * V_24 )
{
}
static void F_33 ( struct V_8 * V_24 )
{
struct V_44 * V_45 , * V_40 ;
F_34 ( & V_24 -> V_10 -> V_46 . V_47 ) ;
F_27 ( ! F_35 ( & V_24 -> V_48 ) ) ;
F_27 ( ! F_35 ( & V_24 -> V_49 ) ) ;
F_27 ( ! F_5 ( V_24 ) ) ;
F_27 ( ! V_24 -> V_10 -> V_50 . V_51 ) ;
F_36 ( V_24 ) ;
F_37 ( & V_24 -> V_52 -> V_3 -> V_21 ) ;
F_38 ( & V_24 -> V_53 ) ;
F_39 ( & V_24 -> V_52 -> V_3 -> V_21 ) ;
F_18 ( & V_24 -> V_54 ) ;
V_24 -> V_55 -> V_56 = V_24 -> V_57 ;
if ( ! -- V_24 -> V_10 -> V_50 . V_51 ) {
F_27 ( ! V_24 -> V_10 -> V_50 . V_58 ) ;
F_40 ( V_24 -> V_10 -> V_59 ,
& V_24 -> V_10 -> V_50 . V_60 ,
F_41 ( 100 ) ) ;
}
F_29 (active, next, &request->active_list, link) {
F_42 ( V_40 ) ;
F_23 ( & V_45 -> V_53 ) ;
F_43 ( V_45 -> V_24 , NULL ) ;
V_45 -> V_61 ( V_45 , V_24 ) ;
}
F_17 ( V_24 ) ;
if ( V_24 -> V_62 ) {
if ( V_10 . V_63 )
F_44 ( V_24 -> V_62 ,
V_24 -> V_52 ) ;
}
F_45 ( V_24 -> V_64 ) ;
F_46 ( & V_24 -> V_2 ) ;
F_26 ( V_24 -> V_10 , & V_24 -> V_65 ) ;
F_47 ( V_24 ) ;
}
void F_48 ( struct V_8 * V_9 )
{
struct V_66 * V_52 = V_9 -> V_52 ;
struct V_8 * V_67 ;
F_34 ( & V_9 -> V_10 -> V_46 . V_47 ) ;
if ( F_49 ( & V_9 -> V_53 ) )
return;
do {
V_67 = F_50 ( & V_52 -> V_3 -> V_11 ,
F_51 ( * V_67 ) , V_53 ) ;
F_33 ( V_67 ) ;
} while ( V_67 != V_9 );
}
static int F_52 ( struct V_14 * V_68 )
{
struct V_69 * error = & V_68 -> V_70 ;
if ( F_53 ( error ) )
return - V_71 ;
if ( F_54 ( error ) ) {
if ( ! V_68 -> V_20 . V_6 )
return - V_71 ;
return - V_72 ;
}
return 0 ;
}
static int F_55 ( struct V_14 * V_10 , T_1 V_73 )
{
struct V_74 * V_3 = & V_10 -> V_50 . V_75 ;
struct V_66 * V_52 ;
enum V_76 V_77 ;
int V_78 ;
V_78 = F_56 ( V_10 ,
V_79 |
V_80 ) ;
if ( V_78 )
return V_78 ;
F_57 ( V_10 ) ;
F_27 ( V_10 -> V_50 . V_51 > 1 ) ;
if ( ! F_58 ( V_73 , F_59 ( & V_3 -> V_81 ) ) ) {
while ( F_60 ( V_10 ) )
F_61 () ;
}
F_62 ( & V_3 -> V_81 , V_73 ) ;
F_63 (engine, i915, id)
F_64 ( V_52 , V_73 ) ;
F_65 (timeline, &i915->gt.timelines, link) {
F_63 (engine, i915, id) {
struct V_82 * V_83 = & V_3 -> V_52 [ V_77 ] ;
memset ( V_83 -> V_84 , 0 , sizeof( V_83 -> V_84 ) ) ;
}
}
return 0 ;
}
int F_66 ( struct V_85 * V_86 , T_1 V_73 )
{
struct V_14 * V_68 = F_67 ( V_86 ) ;
F_34 ( & V_68 -> V_46 . V_47 ) ;
if ( V_73 == 0 )
return - V_18 ;
return F_55 ( V_68 , V_73 - 1 ) ;
}
static int F_68 ( struct V_14 * V_10 )
{
T_1 V_51 = ++ V_10 -> V_50 . V_51 ;
T_1 V_81 = F_59 ( & V_10 -> V_50 . V_75 . V_81 ) ;
int V_78 ;
if ( F_69 ( V_81 + V_51 > V_81 ) )
return 0 ;
V_78 = F_55 ( V_10 , 0 ) ;
if ( V_78 ) {
V_10 -> V_50 . V_51 -- ;
return V_78 ;
}
return 0 ;
}
static T_1 F_70 ( struct V_74 * V_83 )
{
return ++ V_83 -> V_81 . V_87 ;
}
static T_1 F_71 ( struct V_74 * V_83 )
{
return F_72 ( & V_83 -> V_81 ) ;
}
void F_73 ( struct V_8 * V_24 )
{
struct V_66 * V_52 = V_24 -> V_52 ;
struct V_82 * V_3 ;
T_1 V_73 ;
V_3 = V_52 -> V_3 ;
F_27 ( V_3 == V_24 -> V_3 ) ;
F_74 ( & V_3 -> V_21 ) ;
V_73 = F_71 ( V_3 -> V_4 ) ;
F_27 ( ! V_73 ) ;
F_27 ( F_58 ( F_75 ( V_52 ) , V_73 ) ) ;
F_27 ( F_58 ( V_3 -> V_88 , V_73 ) ) ;
V_24 -> V_89 = V_3 -> V_88 ;
V_3 -> V_88 = V_73 ;
F_76 ( & V_24 -> V_21 , V_90 ) ;
V_24 -> V_91 = V_73 ;
if ( F_77 ( V_92 , & V_24 -> V_2 . V_31 ) )
F_7 ( V_24 ) ;
F_16 ( & V_24 -> V_21 ) ;
F_27 ( ! V_24 -> V_91 ) ;
V_52 -> V_93 ( V_24 ,
V_24 -> V_55 -> V_94 + V_24 -> V_57 ) ;
F_14 ( & V_24 -> V_3 -> V_21 ) ;
F_78 ( & V_24 -> V_53 , & V_3 -> V_11 ) ;
F_16 ( & V_24 -> V_3 -> V_21 ) ;
F_79 ( & V_24 -> V_49 ) ;
}
void F_80 ( struct V_8 * V_24 )
{
struct V_66 * V_52 = V_24 -> V_52 ;
unsigned long V_31 ;
F_81 ( & V_52 -> V_3 -> V_21 , V_31 ) ;
F_73 ( V_24 ) ;
F_82 ( & V_52 -> V_3 -> V_21 , V_31 ) ;
}
static int T_2
F_83 ( struct V_95 * V_2 , enum V_96 V_97 )
{
struct V_8 * V_24 =
F_84 ( V_2 , F_51 ( * V_24 ) , V_48 ) ;
switch ( V_97 ) {
case V_98 :
V_24 -> V_52 -> V_99 ( V_24 ) ;
break;
case V_100 :
F_47 ( V_24 ) ;
break;
}
return V_101 ;
}
static int T_2
F_85 ( struct V_95 * V_2 , enum V_96 V_97 )
{
struct V_8 * V_24 =
F_84 ( V_2 , F_51 ( * V_24 ) , V_49 ) ;
switch ( V_97 ) {
case V_98 :
break;
case V_100 :
F_47 ( V_24 ) ;
break;
}
return V_101 ;
}
struct V_8 *
F_86 ( struct V_66 * V_52 ,
struct V_102 * V_64 )
{
struct V_14 * V_68 = V_52 -> V_10 ;
struct V_8 * V_9 ;
int V_78 ;
F_34 ( & V_68 -> V_46 . V_47 ) ;
V_78 = F_52 ( V_68 ) ;
if ( V_78 )
return F_87 ( V_78 ) ;
V_78 = F_68 ( V_68 ) ;
if ( V_78 )
return F_87 ( V_78 ) ;
V_9 = F_88 ( & V_52 -> V_3 -> V_11 ,
F_51 ( * V_9 ) , V_53 ) ;
if ( V_9 && F_89 ( V_9 ) )
F_33 ( V_9 ) ;
V_9 = F_20 ( V_68 -> V_11 , V_27 ) ;
if ( ! V_9 ) {
V_78 = - V_38 ;
goto V_103;
}
V_9 -> V_3 = F_90 ( V_64 , V_52 ) ;
F_27 ( V_9 -> V_3 == V_52 -> V_3 ) ;
F_91 ( & V_9 -> V_21 ) ;
F_92 ( & V_9 -> V_2 ,
& V_104 ,
& V_9 -> V_21 ,
V_9 -> V_3 -> V_105 ,
F_70 ( V_9 -> V_3 -> V_4 ) ) ;
F_93 ( & F_94 ( V_9 ) -> V_48 , F_83 ) ;
F_93 ( & F_94 ( V_9 ) -> V_49 , F_85 ) ;
F_95 ( & V_9 -> V_49 , & V_9 -> V_48 , & V_9 -> V_106 ) ;
F_30 ( & V_9 -> V_65 ) ;
F_23 ( & V_9 -> V_107 ) ;
V_9 -> V_10 = V_68 ;
V_9 -> V_52 = V_52 ;
V_9 -> V_64 = F_96 ( V_64 ) ;
V_9 -> V_91 = 0 ;
V_9 -> V_62 = NULL ;
V_9 -> V_17 = NULL ;
V_9 -> V_108 = NULL ;
V_9 -> V_109 = V_110 ;
F_27 ( V_9 -> V_109 < V_52 -> V_111 ) ;
if ( V_10 . V_63 )
V_78 = F_97 ( V_9 ) ;
else
V_78 = F_98 ( V_9 ) ;
if ( V_78 )
goto V_112;
V_9 -> V_113 = V_9 -> V_55 -> V_114 ;
return V_9 ;
V_112:
F_45 ( V_64 ) ;
F_11 ( V_68 -> V_11 , V_9 ) ;
V_103:
V_68 -> V_50 . V_51 -- ;
return F_87 ( V_78 ) ;
}
static int
F_99 ( struct V_8 * V_115 ,
struct V_8 * V_116 )
{
int V_78 ;
F_27 ( V_115 == V_116 ) ;
if ( V_115 -> V_52 -> V_117 ) {
V_78 = F_25 ( V_115 -> V_10 ,
& V_115 -> V_65 ,
& V_116 -> V_65 ) ;
if ( V_78 < 0 )
return V_78 ;
}
if ( V_115 -> V_3 == V_116 -> V_3 )
return 0 ;
if ( V_115 -> V_52 == V_116 -> V_52 ) {
V_78 = F_100 ( & V_115 -> V_48 ,
& V_116 -> V_48 ,
V_27 ) ;
return V_78 < 0 ? V_78 : 0 ;
}
if ( ! V_116 -> V_91 ) {
V_78 = F_101 ( & V_115 -> V_48 ,
& V_116 -> V_2 , 0 ,
V_27 ) ;
return V_78 < 0 ? V_78 : 0 ;
}
if ( V_116 -> V_91 <= V_115 -> V_3 -> V_84 [ V_116 -> V_52 -> V_77 ] )
return 0 ;
F_102 ( V_115 , V_116 ) ;
if ( ! V_10 . V_118 ) {
if ( ! F_103 ( V_116 , V_119 , 2 ) ) {
V_78 = F_101 ( & V_115 -> V_48 ,
& V_116 -> V_2 , 0 ,
V_27 ) ;
if ( V_78 < 0 )
return V_78 ;
}
} else {
V_78 = V_115 -> V_52 -> V_120 . V_121 ( V_115 , V_116 ) ;
if ( V_78 )
return V_78 ;
}
V_115 -> V_3 -> V_84 [ V_116 -> V_52 -> V_77 ] = V_116 -> V_91 ;
return 0 ;
}
int
F_104 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_122 * V_123 ;
int V_78 ;
int V_124 ;
if ( F_77 ( V_125 , & V_2 -> V_31 ) )
return 0 ;
if ( F_105 ( V_2 ) )
return F_99 ( V_9 , F_3 ( V_2 ) ) ;
if ( ! F_106 ( V_2 ) ) {
V_78 = F_101 ( & V_9 -> V_48 ,
V_2 , V_126 ,
V_27 ) ;
return V_78 < 0 ? V_78 : 0 ;
}
V_123 = F_107 ( V_2 ) ;
for ( V_124 = 0 ; V_124 < V_123 -> V_127 ; V_124 ++ ) {
struct V_1 * V_128 = V_123 -> V_129 [ V_124 ] ;
if ( F_105 ( V_128 ) )
V_78 = F_99 ( V_9 ,
F_3 ( V_128 ) ) ;
else
V_78 = F_101 ( & V_9 -> V_48 ,
V_128 , V_126 ,
V_27 ) ;
if ( V_78 < 0 )
return V_78 ;
}
return 0 ;
}
int
F_108 ( struct V_8 * V_115 ,
struct V_130 * V_131 ,
bool V_132 )
{
struct V_1 * V_133 ;
int V_78 = 0 ;
if ( V_132 ) {
struct V_1 * * V_134 ;
unsigned int V_135 , V_124 ;
V_78 = F_109 ( V_131 -> V_136 ,
& V_133 , & V_135 , & V_134 ) ;
if ( V_78 )
return V_78 ;
for ( V_124 = 0 ; V_124 < V_135 ; V_124 ++ ) {
V_78 = F_104 ( V_115 , V_134 [ V_124 ] ) ;
if ( V_78 )
break;
F_110 ( V_134 [ V_124 ] ) ;
}
for (; V_124 < V_135 ; V_124 ++ )
F_110 ( V_134 [ V_124 ] ) ;
F_111 ( V_134 ) ;
} else {
V_133 = F_112 ( V_131 -> V_136 ) ;
}
if ( V_133 ) {
if ( V_78 == 0 )
V_78 = F_104 ( V_115 , V_133 ) ;
F_110 ( V_133 ) ;
}
return V_78 ;
}
static void F_113 ( const struct V_66 * V_52 )
{
struct V_14 * V_68 = V_52 -> V_10 ;
if ( V_68 -> V_50 . V_58 )
return;
F_27 ( ! V_68 -> V_50 . V_51 ) ;
F_114 ( V_68 ) ;
V_68 -> V_50 . V_58 = true ;
F_115 ( V_68 ) ;
F_116 ( V_68 ) ;
if ( F_117 ( V_68 ) >= 6 )
F_118 ( V_68 ) ;
F_119 ( V_68 -> V_59 ,
& V_68 -> V_50 . V_137 ,
F_120 ( V_138 ) ) ;
}
void F_121 ( struct V_8 * V_24 , bool V_139 )
{
struct V_66 * V_52 = V_24 -> V_52 ;
struct V_140 * V_55 = V_24 -> V_55 ;
struct V_82 * V_3 = V_24 -> V_3 ;
struct V_8 * V_141 ;
int V_142 ;
F_34 ( & V_24 -> V_10 -> V_46 . V_47 ) ;
F_122 ( V_24 ) ;
V_24 -> V_109 = 0 ;
if ( V_139 ) {
V_142 = V_52 -> V_143 ( V_24 , V_144 ) ;
F_123 ( V_142 , L_2 , V_142 ) ;
}
V_142 = F_124 ( V_24 , V_52 -> V_111 ) ;
F_27 ( V_142 ) ;
V_24 -> V_57 = V_55 -> V_114 ;
V_55 -> V_114 += V_52 -> V_111 * sizeof( T_1 ) ;
V_141 = F_125 ( & V_3 -> V_145 ,
& V_24 -> V_10 -> V_46 . V_47 ) ;
if ( V_141 ) {
F_95 ( & V_24 -> V_48 , & V_141 -> V_48 ,
& V_24 -> V_146 ) ;
if ( V_52 -> V_117 )
F_22 ( & V_24 -> V_65 ,
& V_141 -> V_65 ,
& V_24 -> V_28 ,
0 ) ;
}
F_37 ( & V_3 -> V_21 ) ;
F_15 ( & V_24 -> V_53 , & V_3 -> V_11 ) ;
F_39 ( & V_3 -> V_21 ) ;
F_27 ( F_58 ( V_3 -> V_88 ,
V_24 -> V_2 . V_73 ) ) ;
V_3 -> V_88 = V_24 -> V_2 . V_73 ;
F_126 ( & V_3 -> V_145 , V_24 ) ;
F_15 ( & V_24 -> V_54 , & V_55 -> V_23 ) ;
V_24 -> V_147 = V_148 ;
F_113 ( V_52 ) ;
if ( V_52 -> V_117 )
V_52 -> V_117 ( V_24 , V_24 -> V_64 -> V_42 ) ;
F_127 () ;
F_79 ( & V_24 -> V_48 ) ;
F_128 () ;
}
static void F_129 ( T_3 * V_149 , T_4 * V_150 )
{
unsigned long V_31 ;
F_81 ( & V_149 -> V_21 , V_31 ) ;
if ( F_49 ( & V_150 -> V_151 ) )
F_130 ( V_149 , V_150 ) ;
F_82 ( & V_149 -> V_21 , V_31 ) ;
}
static unsigned long F_131 ( unsigned int * V_152 )
{
unsigned long V_153 ;
* V_152 = F_132 () ;
V_153 = F_133 () >> 10 ;
F_134 () ;
return V_153 ;
}
static bool F_135 ( unsigned long V_7 , unsigned int V_152 )
{
unsigned int V_154 ;
if ( F_136 ( F_131 ( & V_154 ) , V_7 ) )
return true ;
return V_154 != V_152 ;
}
bool F_137 ( const struct V_8 * V_9 ,
int V_97 , unsigned long V_155 )
{
unsigned int V_152 ;
V_155 += F_131 ( & V_152 ) ;
do {
if ( F_89 ( V_9 ) )
return true ;
if ( F_138 ( V_97 , V_156 ) )
break;
if ( F_135 ( V_155 , V_152 ) )
break;
F_139 () ;
} while ( ! F_140 () );
return false ;
}
static long
F_141 ( struct V_8 * V_24 ,
unsigned int V_31 ,
long V_7 )
{
const int V_97 = V_31 & V_79 ?
V_119 : V_157 ;
T_3 * V_149 = & V_24 -> V_10 -> V_70 . V_158 ;
F_142 ( V_159 ) ;
F_142 ( V_150 ) ;
if ( V_31 & V_80 )
F_143 ( V_149 , & V_159 ) ;
do {
F_144 ( & V_24 -> V_49 . V_150 , & V_150 , V_97 ) ;
if ( F_145 ( & V_24 -> V_49 ) )
break;
if ( V_31 & V_80 &&
F_54 ( & V_24 -> V_10 -> V_70 ) ) {
F_146 ( V_160 ) ;
F_147 ( V_24 -> V_10 ) ;
F_129 ( V_149 , & V_159 ) ;
continue;
}
if ( F_138 ( V_97 , V_156 ) ) {
V_7 = - V_161 ;
break;
}
V_7 = F_148 ( V_7 ) ;
} while ( V_7 );
F_149 ( & V_24 -> V_49 . V_150 , & V_150 ) ;
if ( V_31 & V_80 )
F_150 ( V_149 , & V_159 ) ;
return V_7 ;
}
long F_9 ( struct V_8 * V_9 ,
unsigned int V_31 ,
long V_7 )
{
const int V_97 = V_31 & V_79 ?
V_119 : V_157 ;
F_142 ( V_159 ) ;
struct V_162 V_150 ;
F_151 () ;
#if F_152 ( V_163 )
F_27 ( V_164 &&
! ! F_153 ( & V_9 -> V_10 -> V_46 . V_47 ) !=
! ! ( V_31 & V_80 ) ) ;
#endif
F_27 ( V_7 < 0 ) ;
if ( F_5 ( V_9 ) )
return V_7 ;
if ( ! V_7 )
return - V_165 ;
F_154 ( V_9 ) ;
if ( ! F_145 ( & V_9 -> V_49 ) ) {
V_7 = F_141 ( V_9 , V_31 , V_7 ) ;
if ( V_7 < 0 )
goto V_166;
F_27 ( ! F_145 ( & V_9 -> V_49 ) ) ;
}
F_27 ( ! F_145 ( & V_9 -> V_48 ) ) ;
F_27 ( ! V_9 -> V_91 ) ;
if ( F_103 ( V_9 , V_97 , 5 ) )
goto V_166;
F_155 ( V_97 ) ;
if ( V_31 & V_80 )
F_143 ( & V_9 -> V_10 -> V_70 . V_158 , & V_159 ) ;
F_156 ( & V_150 , V_9 -> V_91 ) ;
if ( F_157 ( V_9 -> V_52 , & V_150 ) )
goto V_167;
for (; ; ) {
if ( F_138 ( V_97 , V_156 ) ) {
V_7 = - V_161 ;
break;
}
if ( ! V_7 ) {
V_7 = - V_165 ;
break;
}
V_7 = F_148 ( V_7 ) ;
if ( F_158 ( & V_150 ) )
break;
F_155 ( V_97 ) ;
V_167:
if ( F_159 ( V_9 ) )
break;
if ( V_31 & V_80 &&
F_54 ( & V_9 -> V_10 -> V_70 ) ) {
F_146 ( V_160 ) ;
F_147 ( V_9 -> V_10 ) ;
F_129 ( & V_9 -> V_10 -> V_70 . V_158 ,
& V_159 ) ;
continue;
}
if ( F_103 ( V_9 , V_97 , 2 ) )
break;
}
F_160 ( V_9 -> V_52 , & V_150 ) ;
if ( V_31 & V_80 )
F_150 ( & V_9 -> V_10 -> V_70 . V_158 , & V_159 ) ;
F_146 ( V_160 ) ;
V_166:
F_161 ( V_9 ) ;
return V_7 ;
}
static void F_162 ( struct V_66 * V_52 )
{
struct V_8 * V_24 , * V_40 ;
F_29 (request, next,
&engine->timeline->requests, link) {
if ( ! F_89 ( V_24 ) )
return;
F_33 ( V_24 ) ;
}
}
void F_57 ( struct V_14 * V_68 )
{
struct V_66 * V_52 ;
enum V_76 V_77 ;
F_34 ( & V_68 -> V_46 . V_47 ) ;
if ( ! V_68 -> V_50 . V_51 )
return;
F_63 (engine, dev_priv, id)
F_162 ( V_52 ) ;
}
