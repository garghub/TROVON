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
F_13 ( V_11 -> V_13 -> V_14 , V_11 ) ;
}
static inline void
F_14 ( struct V_10 * V_15 )
{
struct V_16 * V_17 ;
V_17 = V_15 -> V_17 ;
if ( ! V_17 )
return;
F_15 ( & V_17 -> V_18 . V_19 ) ;
if ( V_15 -> V_17 ) {
F_16 ( & V_15 -> V_20 ) ;
V_15 -> V_17 = NULL ;
}
F_17 ( & V_17 -> V_18 . V_19 ) ;
}
static struct V_21 *
F_18 ( struct V_22 * V_13 )
{
return F_19 ( V_13 -> V_23 , V_24 ) ;
}
static void
F_20 ( struct V_22 * V_13 ,
struct V_21 * V_25 )
{
F_13 ( V_13 -> V_23 , V_25 ) ;
}
static void
F_21 ( struct V_26 * V_27 ,
struct V_26 * signal ,
struct V_21 * V_25 ,
unsigned long V_4 )
{
F_22 ( & V_25 -> V_28 ) ;
F_23 ( & V_25 -> V_29 , & signal -> V_30 ) ;
F_23 ( & V_25 -> V_31 , & V_27 -> V_32 ) ;
V_25 -> V_33 = signal ;
V_25 -> V_4 = V_4 ;
}
static int
F_24 ( struct V_22 * V_13 ,
struct V_26 * V_27 ,
struct V_26 * signal )
{
struct V_21 * V_25 ;
V_25 = F_18 ( V_13 ) ;
if ( ! V_25 )
return - V_34 ;
F_21 ( V_27 , signal , V_25 , V_35 ) ;
return 0 ;
}
static void
F_25 ( struct V_22 * V_13 , struct V_26 * V_27 )
{
struct V_21 * V_25 , * V_36 ;
F_26 ( ! F_27 ( & V_27 -> V_37 ) ) ;
F_28 (dep, next, &pt->signalers_list, signal_link) {
F_16 ( & V_25 -> V_29 ) ;
if ( V_25 -> V_4 & V_35 )
F_20 ( V_13 , V_25 ) ;
}
F_28 (dep, next, &pt->waiters_list, wait_link) {
F_16 ( & V_25 -> V_31 ) ;
if ( V_25 -> V_4 & V_35 )
F_20 ( V_13 , V_25 ) ;
}
}
static void
F_29 ( struct V_26 * V_27 )
{
F_22 ( & V_27 -> V_32 ) ;
F_22 ( & V_27 -> V_30 ) ;
F_30 ( & V_27 -> V_37 ) ;
V_27 -> V_38 = V_39 ;
}
static int F_31 ( struct V_22 * V_13 , T_1 V_40 )
{
struct V_41 * V_42 ;
enum V_43 V_44 ;
int V_45 ;
V_45 = F_32 ( V_13 ,
V_46 |
V_47 ) ;
if ( V_45 )
return V_45 ;
F_33 (engine, i915, id) {
struct V_48 * V_5 ;
struct V_49 * V_50 = V_42 -> V_5 ;
if ( ! F_34 ( V_40 , V_50 -> V_40 ) ) {
while ( F_35 ( V_42 ) )
F_36 () ;
}
V_50 -> V_40 = V_40 ;
F_37 ( V_42 , V_40 ) ;
F_38 (timeline, &i915->gt.timelines, link)
memset ( V_5 -> V_42 [ V_44 ] . V_51 , 0 ,
sizeof( V_5 -> V_42 [ V_44 ] . V_51 ) ) ;
}
return 0 ;
}
int F_39 ( struct V_52 * V_53 , T_1 V_40 )
{
struct V_22 * V_54 = F_40 ( V_53 ) ;
F_41 ( & V_54 -> V_55 . V_56 ) ;
if ( V_40 == 0 )
return - V_57 ;
return F_31 ( V_54 , V_40 - 1 ) ;
}
static int F_42 ( struct V_41 * V_42 )
{
T_1 V_58 = ++ V_42 -> V_5 -> V_59 ;
T_1 V_40 = V_42 -> V_5 -> V_40 ;
int V_45 ;
if ( F_43 ( ! F_44 ( V_40 , V_58 ) ) )
return 0 ;
V_45 = F_31 ( V_42 -> V_13 , 0 ) ;
if ( V_45 ) {
V_42 -> V_5 -> V_59 -- ;
return V_45 ;
}
return 0 ;
}
static void F_45 ( struct V_41 * V_42 )
{
F_26 ( ! V_42 -> V_5 -> V_59 ) ;
V_42 -> V_5 -> V_59 -- ;
}
void F_46 ( struct V_60 * V_58 ,
struct V_10 * V_15 )
{
}
static void F_47 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_60 * V_58 , * V_36 ;
F_41 ( & V_15 -> V_13 -> V_55 . V_56 ) ;
F_26 ( ! F_48 ( & V_15 -> V_12 ) ) ;
F_26 ( ! F_6 ( V_15 ) ) ;
F_26 ( ! V_15 -> V_13 -> V_61 . V_62 ) ;
F_49 ( V_15 ) ;
F_50 ( & V_42 -> V_5 -> V_19 ) ;
F_51 ( & V_15 -> V_63 ) ;
F_52 ( & V_42 -> V_5 -> V_19 ) ;
F_16 ( & V_15 -> V_64 ) ;
V_15 -> V_65 -> V_66 = V_15 -> V_67 ;
if ( ! -- V_15 -> V_13 -> V_61 . V_62 ) {
F_26 ( ! V_15 -> V_13 -> V_61 . V_68 ) ;
F_53 ( V_15 -> V_13 -> V_69 ,
& V_15 -> V_13 -> V_61 . V_70 ,
F_54 ( 100 ) ) ;
}
F_45 ( V_15 -> V_42 ) ;
F_28 (active, next, &request->active_list, link) {
F_55 ( V_36 ) ;
F_22 ( & V_58 -> V_63 ) ;
F_56 ( V_58 -> V_15 , NULL ) ;
V_58 -> V_71 ( V_58 , V_15 ) ;
}
F_14 ( V_15 ) ;
if ( V_15 -> V_72 -> V_73 > 0 )
V_15 -> V_72 -> V_73 -- ;
if ( V_42 -> V_74 )
V_42 -> V_75 ( V_42 , V_42 -> V_74 ) ;
V_42 -> V_74 = V_15 -> V_72 ;
F_57 ( & V_15 -> V_2 ) ;
F_25 ( V_15 -> V_13 , & V_15 -> V_76 ) ;
F_58 ( V_15 ) ;
}
void F_59 ( struct V_10 * V_11 )
{
struct V_41 * V_42 = V_11 -> V_42 ;
struct V_10 * V_77 ;
F_41 ( & V_11 -> V_13 -> V_55 . V_56 ) ;
F_26 ( ! F_6 ( V_11 ) ) ;
if ( F_60 ( & V_11 -> V_63 ) )
return;
do {
V_77 = F_61 ( & V_42 -> V_5 -> V_14 ,
F_62 ( * V_77 ) , V_63 ) ;
F_47 ( V_77 ) ;
} while ( V_77 != V_11 );
}
static T_1 F_63 ( struct V_49 * V_50 )
{
return ++ V_50 -> V_40 ;
}
void F_64 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_49 * V_5 ;
T_1 V_40 ;
F_26 ( ! F_65 () ) ;
F_41 ( & V_42 -> V_5 -> V_19 ) ;
F_66 ( V_15 ) ;
V_5 = V_42 -> V_5 ;
F_26 ( V_5 == V_15 -> V_5 ) ;
V_40 = F_63 ( V_5 ) ;
F_26 ( ! V_40 ) ;
F_26 ( F_34 ( F_67 ( V_42 ) , V_40 ) ) ;
F_68 ( & V_15 -> V_19 , V_78 ) ;
V_15 -> V_79 = V_40 ;
if ( F_3 ( V_80 , & V_15 -> V_2 . V_4 ) )
F_8 ( V_15 ) ;
F_17 ( & V_15 -> V_19 ) ;
V_42 -> V_81 ( V_15 ,
V_15 -> V_65 -> V_82 + V_15 -> V_67 ) ;
F_15 ( & V_15 -> V_5 -> V_19 ) ;
F_69 ( & V_15 -> V_63 , & V_5 -> V_14 ) ;
F_17 ( & V_15 -> V_5 -> V_19 ) ;
F_70 ( & V_15 -> V_83 ) ;
}
void F_71 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
unsigned long V_4 ;
F_72 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
F_64 ( V_15 ) ;
F_73 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
}
void F_74 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_49 * V_5 ;
F_26 ( ! F_65 () ) ;
F_41 ( & V_42 -> V_5 -> V_19 ) ;
F_26 ( V_15 -> V_79 != V_42 -> V_5 -> V_40 ) ;
V_42 -> V_5 -> V_40 -- ;
F_68 ( & V_15 -> V_19 , V_78 ) ;
V_15 -> V_79 = 0 ;
if ( F_3 ( V_80 , & V_15 -> V_2 . V_4 ) )
F_75 ( V_15 ) ;
F_17 ( & V_15 -> V_19 ) ;
V_5 = V_15 -> V_5 ;
F_26 ( V_5 == V_42 -> V_5 ) ;
F_15 ( & V_5 -> V_19 ) ;
F_76 ( & V_15 -> V_63 , & V_5 -> V_14 ) ;
F_17 ( & V_5 -> V_19 ) ;
}
void F_77 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
unsigned long V_4 ;
F_72 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
F_74 ( V_15 ) ;
F_73 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
}
static int T_2
F_78 ( struct V_84 * V_2 , enum V_85 V_86 )
{
struct V_10 * V_15 =
F_79 ( V_2 , F_62 ( * V_15 ) , V_12 ) ;
switch ( V_86 ) {
case V_87 :
F_80 ( V_15 ) ;
V_15 -> V_42 -> V_88 ( V_15 ) ;
break;
case V_89 :
F_58 ( V_15 ) ;
break;
}
return V_90 ;
}
struct V_10 *
F_81 ( struct V_41 * V_42 ,
struct V_91 * V_72 )
{
struct V_22 * V_54 = V_42 -> V_13 ;
struct V_10 * V_11 ;
int V_45 ;
F_41 ( & V_54 -> V_55 . V_56 ) ;
if ( F_82 ( & V_54 -> V_92 ) )
return F_83 ( - V_93 ) ;
V_45 = V_42 -> V_94 ( V_42 , V_72 ) ;
if ( V_45 )
return F_83 ( V_45 ) ;
V_45 = F_42 ( V_42 ) ;
if ( V_45 )
goto V_95;
V_11 = F_84 ( & V_42 -> V_5 -> V_14 ,
F_62 ( * V_11 ) , V_63 ) ;
if ( V_11 && F_6 ( V_11 ) )
F_47 ( V_11 ) ;
V_11 = F_19 ( V_54 -> V_14 , V_24 ) ;
if ( ! V_11 ) {
V_45 = - V_34 ;
goto V_96;
}
V_11 -> V_5 = F_85 ( V_72 , V_42 ) ;
F_26 ( V_11 -> V_5 == V_42 -> V_5 ) ;
F_86 ( & V_11 -> V_19 ) ;
F_87 ( & V_11 -> V_2 ,
& V_97 ,
& V_11 -> V_19 ,
V_11 -> V_5 -> V_98 ,
F_63 ( V_11 -> V_5 ) ) ;
F_88 ( & F_89 ( V_11 ) -> V_12 , F_78 ) ;
F_90 ( & V_11 -> V_83 ) ;
F_29 ( & V_11 -> V_76 ) ;
F_22 ( & V_11 -> V_99 ) ;
V_11 -> V_13 = V_54 ;
V_11 -> V_42 = V_42 ;
V_11 -> V_72 = V_72 ;
V_11 -> V_79 = 0 ;
V_11 -> V_17 = NULL ;
V_11 -> V_100 = NULL ;
V_11 -> V_101 = V_102 ;
F_26 ( V_11 -> V_101 < V_42 -> V_103 ) ;
V_45 = V_42 -> V_104 ( V_11 ) ;
if ( V_45 )
goto V_105;
V_11 -> V_66 = V_11 -> V_65 -> V_106 ;
F_26 ( V_11 -> V_5 -> V_40 != V_11 -> V_2 . V_40 ) ;
return V_11 ;
V_105:
F_26 ( ! F_60 ( & V_11 -> V_99 ) ) ;
F_26 ( ! F_60 ( & V_11 -> V_76 . V_32 ) ) ;
F_26 ( ! F_60 ( & V_11 -> V_76 . V_30 ) ) ;
F_13 ( V_54 -> V_14 , V_11 ) ;
V_96:
F_45 ( V_42 ) ;
V_95:
V_42 -> V_75 ( V_42 , V_72 ) ;
return F_83 ( V_45 ) ;
}
static int
F_91 ( struct V_10 * V_107 ,
struct V_10 * V_108 )
{
T_1 V_40 ;
int V_45 ;
F_26 ( V_107 == V_108 ) ;
if ( F_6 ( V_108 ) )
return 0 ;
if ( V_107 -> V_42 -> V_109 ) {
V_45 = F_24 ( V_107 -> V_13 ,
& V_107 -> V_76 ,
& V_108 -> V_76 ) ;
if ( V_45 < 0 )
return V_45 ;
}
if ( V_107 -> V_5 == V_108 -> V_5 )
return 0 ;
if ( V_107 -> V_42 == V_108 -> V_42 ) {
V_45 = F_92 ( & V_107 -> V_12 ,
& V_108 -> V_12 ,
V_24 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
V_40 = F_93 ( V_108 ) ;
if ( ! V_40 ) {
V_45 = F_94 ( & V_107 -> V_12 ,
& V_108 -> V_2 , 0 ,
V_24 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
if ( V_40 <= V_107 -> V_5 -> V_51 [ V_108 -> V_42 -> V_44 ] )
return 0 ;
F_95 ( V_107 , V_108 ) ;
if ( ! V_13 . V_110 ) {
if ( ! F_96 ( V_108 , V_111 , 2 ) ) {
V_45 = F_94 ( & V_107 -> V_12 ,
& V_108 -> V_2 , 0 ,
V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
}
} else {
V_45 = V_107 -> V_42 -> V_112 . V_113 ( V_107 , V_108 ) ;
if ( V_45 )
return V_45 ;
}
V_107 -> V_5 -> V_51 [ V_108 -> V_42 -> V_44 ] = V_40 ;
return 0 ;
}
int
F_97 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_114 * V_115 ;
int V_45 ;
int V_116 ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
return 0 ;
if ( F_98 ( V_2 ) )
return F_91 ( V_11 , F_4 ( V_2 ) ) ;
if ( ! F_99 ( V_2 ) ) {
V_45 = F_94 ( & V_11 -> V_12 ,
V_2 , V_117 ,
V_24 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
V_115 = F_100 ( V_2 ) ;
for ( V_116 = 0 ; V_116 < V_115 -> V_118 ; V_116 ++ ) {
struct V_1 * V_119 = V_115 -> V_120 [ V_116 ] ;
if ( F_98 ( V_119 ) )
V_45 = F_91 ( V_11 ,
F_4 ( V_119 ) ) ;
else
V_45 = F_94 ( & V_11 -> V_12 ,
V_119 , V_117 ,
V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
}
return 0 ;
}
int
F_101 ( struct V_10 * V_107 ,
struct V_121 * V_122 ,
bool V_123 )
{
struct V_1 * V_124 ;
int V_45 = 0 ;
if ( V_123 ) {
struct V_1 * * V_125 ;
unsigned int V_126 , V_116 ;
V_45 = F_102 ( V_122 -> V_127 ,
& V_124 , & V_126 , & V_125 ) ;
if ( V_45 )
return V_45 ;
for ( V_116 = 0 ; V_116 < V_126 ; V_116 ++ ) {
V_45 = F_97 ( V_107 , V_125 [ V_116 ] ) ;
if ( V_45 )
break;
F_103 ( V_125 [ V_116 ] ) ;
}
for (; V_116 < V_126 ; V_116 ++ )
F_103 ( V_125 [ V_116 ] ) ;
F_104 ( V_125 ) ;
} else {
V_124 = F_105 ( V_122 -> V_127 ) ;
}
if ( V_124 ) {
if ( V_45 == 0 )
V_45 = F_97 ( V_107 , V_124 ) ;
F_103 ( V_124 ) ;
}
return V_45 ;
}
static void F_106 ( const struct V_41 * V_42 )
{
struct V_22 * V_54 = V_42 -> V_13 ;
if ( V_54 -> V_61 . V_68 )
return;
F_26 ( ! V_54 -> V_61 . V_62 ) ;
F_107 ( V_54 ) ;
V_54 -> V_61 . V_68 = true ;
F_108 ( V_54 ) ;
F_109 ( V_54 ) ;
if ( F_110 ( V_54 ) >= 6 )
F_111 ( V_54 ) ;
F_112 ( V_54 -> V_69 ,
& V_54 -> V_61 . V_128 ,
F_113 ( V_129 ) ) ;
}
void F_114 ( struct V_10 * V_15 , bool V_130 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_131 * V_65 = V_15 -> V_65 ;
struct V_49 * V_5 = V_15 -> V_5 ;
struct V_10 * V_132 ;
T_1 * V_133 ;
int V_134 ;
F_41 ( & V_15 -> V_13 -> V_55 . V_56 ) ;
F_115 ( V_15 ) ;
F_26 ( V_5 -> V_40 != V_15 -> V_2 . V_40 ) ;
V_15 -> V_101 = 0 ;
if ( V_130 ) {
V_134 = V_42 -> V_135 ( V_15 , V_136 ) ;
F_116 ( V_134 , L_3 , V_134 ) ;
}
V_133 = F_117 ( V_15 , V_42 -> V_103 ) ;
F_26 ( F_118 ( V_133 ) ) ;
V_15 -> V_67 = F_119 ( V_15 , V_133 ) ;
V_132 = F_120 ( & V_5 -> V_137 ,
& V_15 -> V_13 -> V_55 . V_56 ) ;
if ( V_132 ) {
F_121 ( & V_15 -> V_12 , & V_132 -> V_12 ,
& V_15 -> V_138 ) ;
if ( V_42 -> V_109 )
F_21 ( & V_15 -> V_76 ,
& V_132 -> V_76 ,
& V_15 -> V_25 ,
0 ) ;
}
F_50 ( & V_5 -> V_19 ) ;
F_122 ( & V_15 -> V_63 , & V_5 -> V_14 ) ;
F_52 ( & V_5 -> V_19 ) ;
F_26 ( V_5 -> V_40 != V_15 -> V_2 . V_40 ) ;
F_123 ( & V_5 -> V_137 , V_15 ) ;
F_122 ( & V_15 -> V_64 , & V_65 -> V_139 ) ;
V_15 -> V_140 = V_141 ;
if ( ! V_15 -> V_13 -> V_61 . V_62 ++ )
F_106 ( V_42 ) ;
if ( V_42 -> V_109 )
V_42 -> V_109 ( V_15 , V_15 -> V_72 -> V_38 ) ;
F_124 () ;
F_125 ( & V_15 -> V_12 ) ;
F_126 () ;
}
static unsigned long F_127 ( unsigned int * V_142 )
{
unsigned long V_143 ;
* V_142 = F_128 () ;
V_143 = F_129 () >> 10 ;
F_130 () ;
return V_143 ;
}
static bool F_131 ( unsigned long V_9 , unsigned int V_142 )
{
unsigned int V_144 ;
if ( F_132 ( F_127 ( & V_144 ) , V_9 ) )
return true ;
return V_144 != V_142 ;
}
bool F_133 ( const struct V_10 * V_11 ,
T_1 V_40 , int V_86 , unsigned long V_145 )
{
struct V_41 * V_42 = V_11 -> V_42 ;
unsigned int V_146 , V_142 ;
V_146 = F_134 ( & V_42 -> V_147 ) ;
V_145 += F_127 ( & V_142 ) ;
do {
if ( V_40 != F_93 ( V_11 ) )
break;
if ( F_34 ( F_67 ( V_11 -> V_42 ) ,
V_40 ) )
return true ;
if ( F_134 ( & V_42 -> V_147 ) != V_146 )
break;
if ( F_135 ( V_86 , V_148 ) )
break;
if ( F_131 ( V_145 , V_142 ) )
break;
F_136 () ;
} while ( ! F_137 () );
return false ;
}
static bool F_138 ( struct V_10 * V_15 )
{
if ( F_43 ( ! F_139 ( & V_15 -> V_13 -> V_92 ) ) )
return false ;
F_140 ( V_149 ) ;
F_141 ( V_15 -> V_13 ) ;
return true ;
}
long F_10 ( struct V_10 * V_11 ,
unsigned int V_4 ,
long V_9 )
{
const int V_86 = V_4 & V_46 ?
V_111 : V_150 ;
T_3 * V_151 = & V_11 -> V_13 -> V_92 . V_152 ;
F_142 ( V_153 , V_154 ) ;
F_142 ( V_155 , V_154 ) ;
struct V_156 V_157 ;
F_143 () ;
#if F_144 ( V_158 )
F_26 ( V_159 &&
! ! F_145 ( & V_11 -> V_13 -> V_55 . V_56 ) !=
! ! ( V_4 & V_47 ) ) ;
#endif
F_26 ( V_9 < 0 ) ;
if ( F_6 ( V_11 ) )
return V_9 ;
if ( ! V_9 )
return - V_160 ;
F_146 ( V_11 , V_4 ) ;
F_147 ( & V_11 -> V_83 , & V_155 ) ;
if ( V_4 & V_47 )
F_147 ( V_151 , & V_153 ) ;
F_148 ( & V_157 , V_11 ) ;
V_161:
do {
F_149 ( V_86 ) ;
if ( F_150 ( & V_157 , V_11 ) )
break;
if ( V_4 & V_47 &&
F_138 ( V_11 ) )
continue;
if ( F_135 ( V_86 , V_148 ) ) {
V_9 = - V_162 ;
goto V_163;
}
if ( ! V_9 ) {
V_9 = - V_160 ;
goto V_163;
}
V_9 = F_151 ( V_9 ) ;
} while ( 1 );
F_26 ( ! F_152 ( & V_157 ) ) ;
F_26 ( ! F_48 ( & V_11 -> V_12 ) ) ;
if ( F_96 ( V_11 , V_86 , 5 ) )
goto V_163;
F_149 ( V_86 ) ;
if ( F_153 ( V_11 -> V_42 , & V_157 ) )
goto V_164;
if ( V_4 & V_47 )
F_138 ( V_11 ) ;
for (; ; ) {
if ( F_135 ( V_86 , V_148 ) ) {
V_9 = - V_162 ;
break;
}
if ( ! V_9 ) {
V_9 = - V_160 ;
break;
}
V_9 = F_151 ( V_9 ) ;
if ( F_154 ( & V_157 ) &&
F_155 ( & V_157 , V_11 ) )
break;
F_149 ( V_86 ) ;
V_164:
if ( F_156 ( V_11 ) )
break;
if ( V_4 & V_47 &&
F_138 ( V_11 ) )
continue;
if ( F_96 ( V_11 , V_86 , 2 ) )
break;
if ( ! F_155 ( & V_157 , V_11 ) ) {
F_157 ( V_11 -> V_42 , & V_157 ) ;
goto V_161;
}
}
F_157 ( V_11 -> V_42 , & V_157 ) ;
V_163:
F_140 ( V_149 ) ;
if ( V_4 & V_47 )
F_158 ( V_151 , & V_153 ) ;
F_158 ( & V_11 -> V_83 , & V_155 ) ;
F_159 ( V_11 ) ;
return V_9 ;
}
static void F_160 ( struct V_41 * V_42 )
{
struct V_10 * V_15 , * V_36 ;
T_1 V_40 = F_67 ( V_42 ) ;
F_161 ( V_71 ) ;
F_50 ( & V_42 -> V_5 -> V_19 ) ;
F_28 (request, next,
&engine->timeline->requests, link) {
if ( ! F_34 ( V_40 , V_15 -> V_79 ) )
break;
F_69 ( & V_15 -> V_63 , & V_71 ) ;
}
F_52 ( & V_42 -> V_5 -> V_19 ) ;
F_28 (request, next, &retire, link)
F_47 ( V_15 ) ;
}
void F_162 ( struct V_22 * V_54 )
{
struct V_41 * V_42 ;
enum V_43 V_44 ;
F_41 ( & V_54 -> V_55 . V_56 ) ;
if ( ! V_54 -> V_61 . V_62 )
return;
F_33 (engine, dev_priv, id)
F_160 ( V_42 ) ;
}
