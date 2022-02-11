static const char * F_1 ( struct V_1 * V_2 )
{
return L_1 ;
}
static const char * F_2 ( struct V_1 * V_2 )
{
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return L_2 ;
return F_4 ( V_2 ) -> V_5 -> V_6 -> V_7 ;
}
static bool F_5 ( struct V_1 * V_2 )
{
return F_6 ( F_4 ( V_2 ) ) ;
}
static bool F_7 ( struct V_1 * V_2 )
{
if ( F_5 ( V_2 ) )
return false ;
F_8 ( F_4 ( V_2 ) ) ;
return true ;
}
static signed long F_9 ( struct V_1 * V_2 ,
bool V_8 ,
signed long V_9 )
{
return F_10 ( F_4 ( V_2 ) , V_8 , V_9 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_4 ( V_2 ) ;
F_12 ( & V_11 -> V_12 ) ;
F_12 ( & V_11 -> V_13 ) ;
F_13 ( V_11 -> V_14 -> V_15 , V_11 ) ;
}
int F_14 ( struct V_10 * V_11 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
F_15 ( ! V_11 || ! V_17 || V_11 -> V_21 ) ;
if ( ! V_11 || ! V_17 )
return - V_22 ;
if ( V_11 -> V_21 )
return - V_22 ;
V_19 = V_11 -> V_14 ;
V_21 = V_17 -> V_23 ;
F_16 ( & V_21 -> V_24 . V_25 ) ;
V_11 -> V_21 = V_21 ;
F_17 ( & V_11 -> V_26 , & V_21 -> V_24 . V_27 ) ;
F_18 ( & V_21 -> V_24 . V_25 ) ;
return 0 ;
}
static inline void
F_19 ( struct V_10 * V_28 )
{
struct V_20 * V_21 = V_28 -> V_21 ;
if ( ! V_21 )
return;
F_16 ( & V_21 -> V_24 . V_25 ) ;
F_20 ( & V_28 -> V_26 ) ;
V_28 -> V_21 = NULL ;
F_18 ( & V_21 -> V_24 . V_25 ) ;
}
static struct V_29 *
F_21 ( struct V_18 * V_14 )
{
return F_22 ( V_14 -> V_30 , V_31 ) ;
}
static void
F_23 ( struct V_18 * V_14 ,
struct V_29 * V_32 )
{
F_13 ( V_14 -> V_30 , V_32 ) ;
}
static void
F_24 ( struct V_33 * V_34 ,
struct V_33 * signal ,
struct V_29 * V_32 ,
unsigned long V_4 )
{
F_25 ( & V_32 -> V_35 ) ;
F_26 ( & V_32 -> V_36 , & signal -> V_37 ) ;
F_26 ( & V_32 -> V_38 , & V_34 -> V_39 ) ;
V_32 -> V_40 = signal ;
V_32 -> V_4 = V_4 ;
}
static int
F_27 ( struct V_18 * V_14 ,
struct V_33 * V_34 ,
struct V_33 * signal )
{
struct V_29 * V_32 ;
V_32 = F_21 ( V_14 ) ;
if ( ! V_32 )
return - V_41 ;
F_24 ( V_34 , signal , V_32 , V_42 ) ;
return 0 ;
}
static void
F_28 ( struct V_18 * V_14 , struct V_33 * V_34 )
{
struct V_29 * V_32 , * V_43 ;
F_29 ( ! F_30 ( & V_34 -> V_44 ) ) ;
F_31 (dep, next, &pt->signalers_list, signal_link) {
F_20 ( & V_32 -> V_36 ) ;
if ( V_32 -> V_4 & V_42 )
F_23 ( V_14 , V_32 ) ;
}
F_31 (dep, next, &pt->waiters_list, wait_link) {
F_20 ( & V_32 -> V_38 ) ;
if ( V_32 -> V_4 & V_42 )
F_23 ( V_14 , V_32 ) ;
}
}
static void
F_32 ( struct V_33 * V_34 )
{
F_25 ( & V_34 -> V_39 ) ;
F_25 ( & V_34 -> V_37 ) ;
F_33 ( & V_34 -> V_44 ) ;
V_34 -> V_45 = V_46 ;
}
void F_34 ( struct V_47 * V_48 ,
struct V_10 * V_28 )
{
}
static void F_35 ( struct V_10 * V_28 )
{
struct V_49 * V_50 = V_28 -> V_50 ;
struct V_47 * V_48 , * V_43 ;
F_36 ( & V_28 -> V_14 -> V_51 . V_52 ) ;
F_29 ( ! F_37 ( & V_28 -> V_12 ) ) ;
F_29 ( ! F_37 ( & V_28 -> V_13 ) ) ;
F_29 ( ! F_6 ( V_28 ) ) ;
F_29 ( ! V_28 -> V_14 -> V_53 . V_54 ) ;
F_38 ( V_28 ) ;
F_39 ( & V_50 -> V_5 -> V_25 ) ;
F_40 ( & V_28 -> V_55 ) ;
F_41 ( & V_50 -> V_5 -> V_25 ) ;
F_20 ( & V_28 -> V_56 ) ;
V_28 -> V_57 -> V_58 = V_28 -> V_59 ;
if ( ! -- V_28 -> V_14 -> V_53 . V_54 ) {
F_29 ( ! V_28 -> V_14 -> V_53 . V_60 ) ;
F_42 ( V_28 -> V_14 -> V_61 ,
& V_28 -> V_14 -> V_53 . V_62 ,
F_43 ( 100 ) ) ;
}
F_31 (active, next, &request->active_list, link) {
F_44 ( V_43 ) ;
F_25 ( & V_48 -> V_55 ) ;
F_45 ( V_48 -> V_28 , NULL ) ;
V_48 -> V_63 ( V_48 , V_28 ) ;
}
F_19 ( V_28 ) ;
if ( V_28 -> V_64 -> V_65 > 0 )
V_28 -> V_64 -> V_65 -- ;
if ( V_50 -> V_66 )
V_50 -> V_67 ( V_50 , V_50 -> V_66 ) ;
V_50 -> V_66 = V_28 -> V_64 ;
F_46 ( & V_28 -> V_2 ) ;
F_28 ( V_28 -> V_14 , & V_28 -> V_68 ) ;
F_47 ( V_28 ) ;
}
void F_48 ( struct V_10 * V_11 )
{
struct V_49 * V_50 = V_11 -> V_50 ;
struct V_10 * V_69 ;
F_36 ( & V_11 -> V_14 -> V_51 . V_52 ) ;
F_29 ( ! F_6 ( V_11 ) ) ;
if ( F_49 ( & V_11 -> V_55 ) )
return;
do {
V_69 = F_50 ( & V_50 -> V_5 -> V_15 ,
F_51 ( * V_69 ) , V_55 ) ;
F_35 ( V_69 ) ;
} while ( V_69 != V_11 );
}
static int F_52 ( struct V_18 * V_14 , T_1 V_70 )
{
struct V_71 * V_5 = & V_14 -> V_53 . V_72 ;
struct V_49 * V_50 ;
enum V_73 V_74 ;
int V_75 ;
V_75 = F_53 ( V_14 ,
V_76 |
V_77 ) ;
if ( V_75 )
return V_75 ;
F_54 ( V_14 ) ;
F_29 ( V_14 -> V_53 . V_54 > 1 ) ;
if ( ! F_55 ( V_70 , F_56 ( & V_5 -> V_70 ) ) ) {
while ( F_57 ( V_14 ) )
F_58 () ;
}
F_59 ( & V_5 -> V_70 , V_70 ) ;
F_60 (engine, i915, id)
F_61 ( V_50 , V_70 ) ;
F_62 (timeline, &i915->gt.timelines, link) {
F_60 (engine, i915, id) {
struct V_78 * V_79 = & V_5 -> V_50 [ V_74 ] ;
memset ( V_79 -> V_80 , 0 , sizeof( V_79 -> V_80 ) ) ;
}
}
return 0 ;
}
int F_63 ( struct V_81 * V_82 , T_1 V_70 )
{
struct V_18 * V_83 = F_64 ( V_82 ) ;
F_36 ( & V_83 -> V_51 . V_52 ) ;
if ( V_70 == 0 )
return - V_22 ;
return F_52 ( V_83 , V_70 - 1 ) ;
}
static int F_65 ( struct V_18 * V_14 )
{
T_1 V_54 = ++ V_14 -> V_53 . V_54 ;
T_1 V_70 = F_56 ( & V_14 -> V_53 . V_72 . V_70 ) ;
int V_75 ;
if ( F_66 ( V_70 + V_54 > V_70 ) )
return 0 ;
V_75 = F_52 ( V_14 , 0 ) ;
if ( V_75 ) {
V_14 -> V_53 . V_54 -- ;
return V_75 ;
}
return 0 ;
}
static T_1 F_67 ( struct V_71 * V_79 )
{
return ++ V_79 -> V_70 . V_84 ;
}
static T_1 F_68 ( struct V_71 * V_79 )
{
return F_69 ( & V_79 -> V_70 ) ;
}
void F_70 ( struct V_10 * V_28 )
{
struct V_49 * V_50 = V_28 -> V_50 ;
struct V_78 * V_5 ;
T_1 V_70 ;
V_5 = V_50 -> V_5 ;
F_29 ( V_5 == V_28 -> V_5 ) ;
F_71 ( & V_5 -> V_25 ) ;
V_70 = F_68 ( V_5 -> V_6 ) ;
F_29 ( ! V_70 ) ;
F_29 ( F_55 ( F_72 ( V_50 ) , V_70 ) ) ;
F_29 ( F_55 ( V_5 -> V_85 , V_70 ) ) ;
V_28 -> V_86 = V_5 -> V_85 ;
V_5 -> V_85 = V_70 ;
F_73 ( & V_28 -> V_25 , V_87 ) ;
V_28 -> V_88 = V_70 ;
if ( F_3 ( V_89 , & V_28 -> V_2 . V_4 ) )
F_8 ( V_28 ) ;
F_18 ( & V_28 -> V_25 ) ;
F_29 ( ! V_28 -> V_88 ) ;
V_50 -> V_90 ( V_28 ,
V_28 -> V_57 -> V_91 + V_28 -> V_59 ) ;
F_16 ( & V_28 -> V_5 -> V_25 ) ;
F_74 ( & V_28 -> V_55 , & V_5 -> V_15 ) ;
F_18 ( & V_28 -> V_5 -> V_25 ) ;
F_75 ( & V_28 -> V_13 ) ;
}
void F_76 ( struct V_10 * V_28 )
{
struct V_49 * V_50 = V_28 -> V_50 ;
unsigned long V_4 ;
F_77 ( & V_50 -> V_5 -> V_25 , V_4 ) ;
F_70 ( V_28 ) ;
F_78 ( & V_50 -> V_5 -> V_25 , V_4 ) ;
}
static int T_2
F_79 ( struct V_92 * V_2 , enum V_93 V_94 )
{
struct V_10 * V_28 =
F_80 ( V_2 , F_51 ( * V_28 ) , V_12 ) ;
switch ( V_94 ) {
case V_95 :
V_28 -> V_50 -> V_96 ( V_28 ) ;
break;
case V_97 :
F_47 ( V_28 ) ;
break;
}
return V_98 ;
}
static int T_2
F_81 ( struct V_92 * V_2 , enum V_93 V_94 )
{
struct V_10 * V_28 =
F_80 ( V_2 , F_51 ( * V_28 ) , V_13 ) ;
switch ( V_94 ) {
case V_95 :
break;
case V_97 :
F_47 ( V_28 ) ;
break;
}
return V_98 ;
}
struct V_10 *
F_82 ( struct V_49 * V_50 ,
struct V_99 * V_64 )
{
struct V_18 * V_83 = V_50 -> V_14 ;
struct V_10 * V_11 ;
int V_75 ;
F_36 ( & V_83 -> V_51 . V_52 ) ;
if ( F_83 ( & V_83 -> V_100 ) )
return F_84 ( - V_101 ) ;
V_75 = V_50 -> V_102 ( V_50 , V_64 ) ;
if ( V_75 )
return F_84 ( V_75 ) ;
V_75 = F_65 ( V_83 ) ;
if ( V_75 )
goto V_103;
V_11 = F_85 ( & V_50 -> V_5 -> V_15 ,
F_51 ( * V_11 ) , V_55 ) ;
if ( V_11 && F_86 ( V_11 ) )
F_35 ( V_11 ) ;
V_11 = F_22 ( V_83 -> V_15 , V_31 ) ;
if ( ! V_11 ) {
V_75 = - V_41 ;
goto V_104;
}
V_11 -> V_5 = F_87 ( V_64 , V_50 ) ;
F_29 ( V_11 -> V_5 == V_50 -> V_5 ) ;
F_88 ( & V_11 -> V_25 ) ;
F_89 ( & V_11 -> V_2 ,
& V_105 ,
& V_11 -> V_25 ,
V_11 -> V_5 -> V_106 ,
F_67 ( V_11 -> V_5 -> V_6 ) ) ;
F_90 ( & F_91 ( V_11 ) -> V_12 , F_79 ) ;
F_90 ( & F_91 ( V_11 ) -> V_13 , F_81 ) ;
F_92 ( & V_11 -> V_13 , & V_11 -> V_12 , & V_11 -> V_107 ) ;
F_32 ( & V_11 -> V_68 ) ;
F_25 ( & V_11 -> V_108 ) ;
V_11 -> V_14 = V_83 ;
V_11 -> V_50 = V_50 ;
V_11 -> V_64 = V_64 ;
V_11 -> V_88 = 0 ;
V_11 -> V_21 = NULL ;
V_11 -> V_109 = NULL ;
V_11 -> V_110 = V_111 ;
F_29 ( V_11 -> V_110 < V_50 -> V_112 ) ;
V_75 = V_50 -> V_113 ( V_11 ) ;
if ( V_75 )
goto V_114;
V_11 -> V_115 = V_11 -> V_57 -> V_116 ;
return V_11 ;
V_114:
F_29 ( ! F_49 ( & V_11 -> V_108 ) ) ;
F_29 ( ! F_49 ( & V_11 -> V_68 . V_39 ) ) ;
F_29 ( ! F_49 ( & V_11 -> V_68 . V_37 ) ) ;
F_13 ( V_83 -> V_15 , V_11 ) ;
V_104:
V_83 -> V_53 . V_54 -- ;
V_103:
V_50 -> V_67 ( V_50 , V_64 ) ;
return F_84 ( V_75 ) ;
}
static int
F_93 ( struct V_10 * V_117 ,
struct V_10 * V_118 )
{
int V_75 ;
F_29 ( V_117 == V_118 ) ;
if ( V_117 -> V_50 -> V_119 ) {
V_75 = F_27 ( V_117 -> V_14 ,
& V_117 -> V_68 ,
& V_118 -> V_68 ) ;
if ( V_75 < 0 )
return V_75 ;
}
if ( V_117 -> V_5 == V_118 -> V_5 )
return 0 ;
if ( V_117 -> V_50 == V_118 -> V_50 ) {
V_75 = F_94 ( & V_117 -> V_12 ,
& V_118 -> V_12 ,
V_31 ) ;
return V_75 < 0 ? V_75 : 0 ;
}
if ( ! V_118 -> V_88 ) {
V_75 = F_95 ( & V_117 -> V_12 ,
& V_118 -> V_2 , 0 ,
V_31 ) ;
return V_75 < 0 ? V_75 : 0 ;
}
if ( V_118 -> V_88 <= V_117 -> V_5 -> V_80 [ V_118 -> V_50 -> V_74 ] )
return 0 ;
F_96 ( V_117 , V_118 ) ;
if ( ! V_14 . V_120 ) {
if ( ! F_97 ( V_118 , V_121 , 2 ) ) {
V_75 = F_95 ( & V_117 -> V_12 ,
& V_118 -> V_2 , 0 ,
V_31 ) ;
if ( V_75 < 0 )
return V_75 ;
}
} else {
V_75 = V_117 -> V_50 -> V_122 . V_123 ( V_117 , V_118 ) ;
if ( V_75 )
return V_75 ;
}
V_117 -> V_5 -> V_80 [ V_118 -> V_50 -> V_74 ] = V_118 -> V_88 ;
return 0 ;
}
int
F_98 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_124 * V_125 ;
int V_75 ;
int V_126 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return 0 ;
if ( F_99 ( V_2 ) )
return F_93 ( V_11 , F_4 ( V_2 ) ) ;
if ( ! F_100 ( V_2 ) ) {
V_75 = F_95 ( & V_11 -> V_12 ,
V_2 , V_127 ,
V_31 ) ;
return V_75 < 0 ? V_75 : 0 ;
}
V_125 = F_101 ( V_2 ) ;
for ( V_126 = 0 ; V_126 < V_125 -> V_128 ; V_126 ++ ) {
struct V_1 * V_129 = V_125 -> V_130 [ V_126 ] ;
if ( F_99 ( V_129 ) )
V_75 = F_93 ( V_11 ,
F_4 ( V_129 ) ) ;
else
V_75 = F_95 ( & V_11 -> V_12 ,
V_129 , V_127 ,
V_31 ) ;
if ( V_75 < 0 )
return V_75 ;
}
return 0 ;
}
int
F_102 ( struct V_10 * V_117 ,
struct V_131 * V_132 ,
bool V_133 )
{
struct V_1 * V_134 ;
int V_75 = 0 ;
if ( V_133 ) {
struct V_1 * * V_135 ;
unsigned int V_136 , V_126 ;
V_75 = F_103 ( V_132 -> V_137 ,
& V_134 , & V_136 , & V_135 ) ;
if ( V_75 )
return V_75 ;
for ( V_126 = 0 ; V_126 < V_136 ; V_126 ++ ) {
V_75 = F_98 ( V_117 , V_135 [ V_126 ] ) ;
if ( V_75 )
break;
F_104 ( V_135 [ V_126 ] ) ;
}
for (; V_126 < V_136 ; V_126 ++ )
F_104 ( V_135 [ V_126 ] ) ;
F_105 ( V_135 ) ;
} else {
V_134 = F_106 ( V_132 -> V_137 ) ;
}
if ( V_134 ) {
if ( V_75 == 0 )
V_75 = F_98 ( V_117 , V_134 ) ;
F_104 ( V_134 ) ;
}
return V_75 ;
}
static void F_107 ( const struct V_49 * V_50 )
{
struct V_18 * V_83 = V_50 -> V_14 ;
if ( V_83 -> V_53 . V_60 )
return;
F_29 ( ! V_83 -> V_53 . V_54 ) ;
F_108 ( V_83 ) ;
V_83 -> V_53 . V_60 = true ;
F_109 ( V_83 ) ;
F_110 ( V_83 ) ;
if ( F_111 ( V_83 ) >= 6 )
F_112 ( V_83 ) ;
F_113 ( V_83 -> V_61 ,
& V_83 -> V_53 . V_138 ,
F_114 ( V_139 ) ) ;
}
void F_115 ( struct V_10 * V_28 , bool V_140 )
{
struct V_49 * V_50 = V_28 -> V_50 ;
struct V_141 * V_57 = V_28 -> V_57 ;
struct V_78 * V_5 = V_28 -> V_5 ;
struct V_10 * V_142 ;
int V_143 ;
F_36 ( & V_28 -> V_14 -> V_51 . V_52 ) ;
F_116 ( V_28 ) ;
F_29 ( F_55 ( V_5 -> V_85 ,
V_28 -> V_2 . V_70 ) ) ;
V_28 -> V_110 = 0 ;
if ( V_140 ) {
V_143 = V_50 -> V_144 ( V_28 , V_145 ) ;
F_117 ( V_143 , L_3 , V_143 ) ;
}
V_143 = F_118 ( V_28 , V_50 -> V_112 ) ;
F_29 ( V_143 ) ;
V_28 -> V_59 = V_57 -> V_116 ;
V_57 -> V_116 += V_50 -> V_112 * sizeof( T_1 ) ;
V_142 = F_119 ( & V_5 -> V_146 ,
& V_28 -> V_14 -> V_51 . V_52 ) ;
if ( V_142 ) {
F_92 ( & V_28 -> V_12 , & V_142 -> V_12 ,
& V_28 -> V_147 ) ;
if ( V_50 -> V_119 )
F_24 ( & V_28 -> V_68 ,
& V_142 -> V_68 ,
& V_28 -> V_32 ,
0 ) ;
}
F_39 ( & V_5 -> V_25 ) ;
F_17 ( & V_28 -> V_55 , & V_5 -> V_15 ) ;
F_41 ( & V_5 -> V_25 ) ;
F_29 ( F_55 ( V_5 -> V_85 ,
V_28 -> V_2 . V_70 ) ) ;
V_5 -> V_85 = V_28 -> V_2 . V_70 ;
F_120 ( & V_5 -> V_146 , V_28 ) ;
F_17 ( & V_28 -> V_56 , & V_57 -> V_27 ) ;
V_28 -> V_148 = V_149 ;
F_107 ( V_50 ) ;
if ( V_50 -> V_119 )
V_50 -> V_119 ( V_28 , V_28 -> V_64 -> V_45 ) ;
F_121 () ;
F_75 ( & V_28 -> V_12 ) ;
F_122 () ;
}
static void F_123 ( T_3 * V_150 , T_4 * V_151 )
{
unsigned long V_4 ;
F_77 ( & V_150 -> V_25 , V_4 ) ;
if ( F_49 ( & V_151 -> V_152 ) )
F_124 ( V_150 , V_151 ) ;
F_78 ( & V_150 -> V_25 , V_4 ) ;
}
static unsigned long F_125 ( unsigned int * V_153 )
{
unsigned long V_154 ;
* V_153 = F_126 () ;
V_154 = F_127 () >> 10 ;
F_128 () ;
return V_154 ;
}
static bool F_129 ( unsigned long V_9 , unsigned int V_153 )
{
unsigned int V_155 ;
if ( F_130 ( F_125 ( & V_155 ) , V_9 ) )
return true ;
return V_155 != V_153 ;
}
bool F_131 ( const struct V_10 * V_11 ,
int V_94 , unsigned long V_156 )
{
unsigned int V_153 ;
V_156 += F_125 ( & V_153 ) ;
do {
if ( F_86 ( V_11 ) )
return true ;
if ( F_132 ( V_94 , V_157 ) )
break;
if ( F_129 ( V_156 , V_153 ) )
break;
F_133 () ;
} while ( ! F_134 () );
return false ;
}
static long
F_135 ( struct V_10 * V_28 ,
unsigned int V_4 ,
long V_9 )
{
const int V_94 = V_4 & V_76 ?
V_121 : V_158 ;
T_3 * V_150 = & V_28 -> V_14 -> V_100 . V_159 ;
F_136 ( V_160 ) ;
F_136 ( V_151 ) ;
if ( V_4 & V_77 )
F_137 ( V_150 , & V_160 ) ;
do {
F_138 ( & V_28 -> V_13 . V_151 , & V_151 , V_94 ) ;
if ( F_139 ( & V_28 -> V_13 ) )
break;
if ( V_4 & V_77 &&
F_140 ( & V_28 -> V_14 -> V_100 ) ) {
F_141 ( V_161 ) ;
F_142 ( V_28 -> V_14 ) ;
F_123 ( V_150 , & V_160 ) ;
continue;
}
if ( F_132 ( V_94 , V_157 ) ) {
V_9 = - V_162 ;
break;
}
if ( ! V_9 ) {
V_9 = - V_163 ;
break;
}
V_9 = F_143 ( V_9 ) ;
} while ( 1 );
F_144 ( & V_28 -> V_13 . V_151 , & V_151 ) ;
if ( V_4 & V_77 )
F_145 ( V_150 , & V_160 ) ;
return V_9 ;
}
long F_10 ( struct V_10 * V_11 ,
unsigned int V_4 ,
long V_9 )
{
const int V_94 = V_4 & V_76 ?
V_121 : V_158 ;
F_136 ( V_160 ) ;
struct V_164 V_151 ;
F_146 () ;
#if F_147 ( V_165 )
F_29 ( V_166 &&
! ! F_148 ( & V_11 -> V_14 -> V_51 . V_52 ) !=
! ! ( V_4 & V_77 ) ) ;
#endif
F_29 ( V_9 < 0 ) ;
if ( F_6 ( V_11 ) )
return V_9 ;
if ( ! V_9 )
return - V_163 ;
F_149 ( V_11 ) ;
if ( ! F_139 ( & V_11 -> V_13 ) ) {
V_9 = F_135 ( V_11 , V_4 , V_9 ) ;
if ( V_9 < 0 )
goto V_167;
F_29 ( ! F_139 ( & V_11 -> V_13 ) ) ;
}
F_29 ( ! F_139 ( & V_11 -> V_12 ) ) ;
F_29 ( ! V_11 -> V_88 ) ;
if ( F_97 ( V_11 , V_94 , 5 ) )
goto V_167;
F_150 ( V_94 ) ;
if ( V_4 & V_77 )
F_137 ( & V_11 -> V_14 -> V_100 . V_159 , & V_160 ) ;
F_151 ( & V_151 , V_11 -> V_88 ) ;
if ( F_152 ( V_11 -> V_50 , & V_151 ) )
goto V_168;
for (; ; ) {
if ( F_132 ( V_94 , V_157 ) ) {
V_9 = - V_162 ;
break;
}
if ( ! V_9 ) {
V_9 = - V_163 ;
break;
}
V_9 = F_143 ( V_9 ) ;
if ( F_153 ( & V_151 ) )
break;
F_150 ( V_94 ) ;
V_168:
if ( F_154 ( V_11 ) )
break;
if ( V_4 & V_77 &&
F_140 ( & V_11 -> V_14 -> V_100 ) ) {
F_141 ( V_161 ) ;
F_142 ( V_11 -> V_14 ) ;
F_123 ( & V_11 -> V_14 -> V_100 . V_159 ,
& V_160 ) ;
continue;
}
if ( F_97 ( V_11 , V_94 , 2 ) )
break;
}
F_155 ( V_11 -> V_50 , & V_151 ) ;
if ( V_4 & V_77 )
F_145 ( & V_11 -> V_14 -> V_100 . V_159 , & V_160 ) ;
F_141 ( V_161 ) ;
V_167:
F_156 ( V_11 ) ;
return V_9 ;
}
static void F_157 ( struct V_49 * V_50 )
{
struct V_10 * V_28 , * V_43 ;
F_31 (request, next,
&engine->timeline->requests, link) {
if ( ! F_86 ( V_28 ) )
return;
F_35 ( V_28 ) ;
}
}
void F_54 ( struct V_18 * V_83 )
{
struct V_49 * V_50 ;
enum V_73 V_74 ;
F_36 ( & V_83 -> V_51 . V_52 ) ;
if ( ! V_83 -> V_53 . V_54 )
return;
F_60 (engine, dev_priv, id)
F_157 ( V_50 ) ;
}
