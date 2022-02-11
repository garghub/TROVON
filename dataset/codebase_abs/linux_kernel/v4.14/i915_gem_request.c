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
F_8 ( F_4 ( V_2 ) , true ) ;
return ! F_5 ( V_2 ) ;
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
F_22 ( & V_27 -> V_37 ) ;
V_27 -> V_38 = V_39 ;
}
static int F_30 ( struct V_22 * V_13 , T_1 V_40 )
{
struct V_41 * V_42 ;
enum V_43 V_44 ;
int V_45 ;
V_45 = F_31 ( V_13 ,
V_46 |
V_47 ) ;
if ( V_45 )
return V_45 ;
F_32 (engine, i915, id) {
struct V_48 * V_5 ;
struct V_49 * V_50 = V_42 -> V_5 ;
if ( ! F_33 ( V_40 , V_50 -> V_40 ) ) {
while ( F_34 ( V_42 ) )
F_35 () ;
}
F_26 ( ! F_36 ( V_42 ) ) ;
F_26 ( F_37 ( & V_42 -> V_5 -> V_51 ) ) ;
F_38 ( V_42 , V_40 ) ;
V_50 -> V_40 = V_40 ;
F_39 (timeline, &i915->gt.timelines, link)
memset ( V_5 -> V_42 [ V_44 ] . V_52 , 0 ,
sizeof( V_5 -> V_42 [ V_44 ] . V_52 ) ) ;
}
return 0 ;
}
int F_40 ( struct V_53 * V_54 , T_1 V_40 )
{
struct V_22 * V_55 = F_41 ( V_54 ) ;
F_42 ( & V_55 -> V_56 . V_57 ) ;
if ( V_40 == 0 )
return - V_58 ;
return F_30 ( V_55 , V_40 - 1 ) ;
}
static void F_43 ( struct V_22 * V_13 )
{
if ( V_13 -> V_59 . V_60 )
return;
F_26 ( ! V_13 -> V_59 . V_61 ) ;
F_44 ( V_13 ) ;
V_13 -> V_59 . V_60 = true ;
F_45 ( V_13 ) ;
F_46 ( V_13 ) ;
if ( F_47 ( V_13 ) >= 6 )
F_48 ( V_13 ) ;
F_49 ( V_13 -> V_62 ,
& V_13 -> V_59 . V_63 ,
F_50 ( V_64 ) ) ;
}
static int F_51 ( struct V_41 * V_42 )
{
struct V_22 * V_13 = V_42 -> V_13 ;
T_1 V_65 = ++ V_42 -> V_5 -> V_66 ;
T_1 V_40 = V_42 -> V_5 -> V_40 ;
int V_45 ;
if ( F_52 ( F_53 ( V_40 , V_65 ) ) ) {
V_45 = F_30 ( V_13 , 0 ) ;
if ( V_45 ) {
V_42 -> V_5 -> V_66 -- ;
return V_45 ;
}
}
if ( ! V_13 -> V_59 . V_61 ++ )
F_43 ( V_13 ) ;
return 0 ;
}
static void F_54 ( struct V_41 * V_42 )
{
struct V_22 * V_13 = V_42 -> V_13 ;
if ( ! -- V_13 -> V_59 . V_61 ) {
F_26 ( ! V_13 -> V_59 . V_60 ) ;
F_55 ( V_13 -> V_62 ,
& V_13 -> V_59 . V_67 ,
F_56 ( 100 ) ) ;
}
F_26 ( ! V_42 -> V_5 -> V_66 ) ;
V_42 -> V_5 -> V_66 -- ;
}
void F_57 ( struct V_68 * V_65 ,
struct V_10 * V_15 )
{
}
static void F_58 ( struct V_10 * V_15 )
{
unsigned int V_69 ;
if ( F_59 ( & V_15 -> V_70 , & V_15 -> V_71 -> V_72 ) ) {
V_69 = F_60 ( V_15 -> V_71 -> V_69 ) ;
} else {
V_69 = V_15 -> V_73 ;
}
F_16 ( & V_15 -> V_70 ) ;
V_15 -> V_71 -> V_74 = V_69 ;
}
static void F_61 ( struct V_10 * V_15 )
{
struct V_75 * V_76 ;
V_76 = V_15 -> V_77 ;
while ( V_76 ) {
struct V_75 * V_36 = V_76 -> V_36 ;
F_62 ( V_76 ) ;
V_76 = V_36 ;
}
}
static void F_63 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_68 * V_65 , * V_36 ;
F_42 ( & V_15 -> V_13 -> V_56 . V_57 ) ;
F_26 ( ! F_64 ( & V_15 -> V_12 ) ) ;
F_26 ( ! F_6 ( V_15 ) ) ;
F_26 ( ! V_15 -> V_13 -> V_59 . V_61 ) ;
F_65 ( V_15 ) ;
F_66 ( & V_42 -> V_5 -> V_19 ) ;
F_67 ( & V_15 -> V_37 ) ;
F_68 ( & V_42 -> V_5 -> V_19 ) ;
F_54 ( V_15 -> V_42 ) ;
F_58 ( V_15 ) ;
F_61 ( V_15 ) ;
F_28 (active, next, &request->active_list, link) {
F_69 ( V_36 ) ;
F_22 ( & V_65 -> V_37 ) ;
F_70 ( V_65 -> V_15 , NULL ) ;
V_65 -> V_78 ( V_65 , V_15 ) ;
}
F_14 ( V_15 ) ;
F_71 ( & V_15 -> V_79 -> V_80 ) ;
if ( V_42 -> V_81 )
V_42 -> V_82 ( V_42 , V_42 -> V_81 ) ;
V_42 -> V_81 = V_15 -> V_79 ;
F_66 ( & V_15 -> V_19 ) ;
if ( V_15 -> V_83 )
F_72 ( & V_15 -> V_13 -> V_84 . V_85 ) ;
F_73 ( & V_15 -> V_2 ) ;
F_68 ( & V_15 -> V_19 ) ;
F_25 ( V_15 -> V_13 , & V_15 -> V_86 ) ;
F_74 ( V_15 ) ;
}
void F_75 ( struct V_10 * V_11 )
{
struct V_41 * V_42 = V_11 -> V_42 ;
struct V_10 * V_87 ;
F_42 ( & V_11 -> V_13 -> V_56 . V_57 ) ;
F_26 ( ! F_6 ( V_11 ) ) ;
if ( F_27 ( & V_11 -> V_37 ) )
return;
do {
V_87 = F_76 ( & V_42 -> V_5 -> V_14 ,
F_77 ( * V_87 ) , V_37 ) ;
F_63 ( V_87 ) ;
} while ( V_87 != V_11 );
}
static T_1 F_78 ( struct V_49 * V_50 )
{
return ++ V_50 -> V_40 ;
}
void F_79 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_49 * V_5 ;
T_1 V_40 ;
F_26 ( ! F_80 () ) ;
F_42 ( & V_42 -> V_5 -> V_19 ) ;
F_81 ( V_15 ) ;
V_5 = V_42 -> V_5 ;
F_26 ( V_5 == V_15 -> V_5 ) ;
V_40 = F_78 ( V_5 ) ;
F_26 ( ! V_40 ) ;
F_26 ( F_33 ( F_82 ( V_42 ) , V_40 ) ) ;
F_83 ( & V_15 -> V_19 , V_88 ) ;
V_15 -> V_89 = V_40 ;
if ( F_3 ( V_90 , & V_15 -> V_2 . V_4 ) )
F_8 ( V_15 , false ) ;
F_17 ( & V_15 -> V_19 ) ;
V_42 -> V_91 ( V_15 ,
V_15 -> V_71 -> V_92 + V_15 -> V_73 ) ;
F_15 ( & V_15 -> V_5 -> V_19 ) ;
F_84 ( & V_15 -> V_37 , & V_5 -> V_14 ) ;
F_17 ( & V_15 -> V_5 -> V_19 ) ;
F_85 ( & V_15 -> V_93 ) ;
}
void F_86 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
unsigned long V_4 ;
F_87 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
F_79 ( V_15 ) ;
F_88 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
}
void F_89 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_49 * V_5 ;
F_26 ( ! F_80 () ) ;
F_42 ( & V_42 -> V_5 -> V_19 ) ;
F_26 ( V_15 -> V_89 != V_42 -> V_5 -> V_40 ) ;
V_42 -> V_5 -> V_40 -- ;
F_83 ( & V_15 -> V_19 , V_88 ) ;
V_15 -> V_89 = 0 ;
if ( F_3 ( V_90 , & V_15 -> V_2 . V_4 ) )
F_90 ( V_15 ) ;
F_17 ( & V_15 -> V_19 ) ;
V_5 = V_15 -> V_5 ;
F_26 ( V_5 == V_42 -> V_5 ) ;
F_15 ( & V_5 -> V_19 ) ;
F_91 ( & V_15 -> V_37 , & V_5 -> V_14 ) ;
F_17 ( & V_5 -> V_19 ) ;
}
void F_92 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
unsigned long V_4 ;
F_87 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
F_89 ( V_15 ) ;
F_88 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
}
static int T_2
F_93 ( struct V_94 * V_2 , enum V_95 V_96 )
{
struct V_10 * V_15 =
F_94 ( V_2 , F_77 ( * V_15 ) , V_12 ) ;
switch ( V_96 ) {
case V_97 :
F_95 ( V_15 ) ;
V_15 -> V_42 -> V_98 ( V_15 ) ;
break;
case V_99 :
F_74 ( V_15 ) ;
break;
}
return V_100 ;
}
struct V_10 *
F_96 ( struct V_41 * V_42 ,
struct V_101 * V_79 )
{
struct V_22 * V_55 = V_42 -> V_13 ;
struct V_10 * V_11 ;
struct V_102 * V_71 ;
int V_45 ;
F_42 ( & V_55 -> V_56 . V_57 ) ;
if ( F_97 ( & V_55 -> V_103 ) )
return F_98 ( - V_104 ) ;
V_71 = V_42 -> V_105 ( V_42 , V_79 ) ;
if ( F_99 ( V_71 ) )
return F_100 ( V_71 ) ;
F_26 ( ! V_71 ) ;
V_45 = F_51 ( V_42 ) ;
if ( V_45 )
goto V_106;
V_11 = F_101 ( & V_42 -> V_5 -> V_14 ,
F_77 ( * V_11 ) , V_37 ) ;
if ( V_11 && F_6 ( V_11 ) )
F_63 ( V_11 ) ;
V_11 = F_19 ( V_55 -> V_14 , V_24 ) ;
if ( ! V_11 ) {
V_45 = - V_34 ;
goto V_107;
}
V_11 -> V_5 = F_102 ( V_79 , V_42 ) ;
F_26 ( V_11 -> V_5 == V_42 -> V_5 ) ;
F_103 ( & V_11 -> V_19 ) ;
F_104 ( & V_11 -> V_2 ,
& V_108 ,
& V_11 -> V_19 ,
V_11 -> V_5 -> V_109 ,
F_78 ( V_11 -> V_5 ) ) ;
F_105 ( & F_106 ( V_11 ) -> V_12 , F_93 ) ;
F_107 ( & V_11 -> V_93 ) ;
F_29 ( & V_11 -> V_86 ) ;
F_22 ( & V_11 -> V_110 ) ;
V_11 -> V_13 = V_55 ;
V_11 -> V_42 = V_42 ;
V_11 -> V_79 = V_79 ;
V_11 -> V_71 = V_71 ;
V_11 -> V_89 = 0 ;
V_11 -> V_17 = NULL ;
V_11 -> V_111 = NULL ;
V_11 -> V_77 = NULL ;
V_11 -> V_83 = false ;
V_11 -> V_112 = V_113 ;
F_26 ( V_11 -> V_112 < V_42 -> V_114 ) ;
V_45 = V_42 -> V_115 ( V_11 ) ;
if ( V_45 )
goto V_116;
V_11 -> V_74 = V_11 -> V_71 -> V_117 ;
F_26 ( V_11 -> V_5 -> V_40 != V_11 -> V_2 . V_40 ) ;
return V_11 ;
V_116:
F_26 ( ! F_27 ( & V_11 -> V_110 ) ) ;
F_26 ( ! F_27 ( & V_11 -> V_86 . V_32 ) ) ;
F_26 ( ! F_27 ( & V_11 -> V_86 . V_30 ) ) ;
F_13 ( V_55 -> V_14 , V_11 ) ;
V_107:
F_54 ( V_42 ) ;
V_106:
V_42 -> V_82 ( V_42 , V_79 ) ;
return F_98 ( V_45 ) ;
}
static int
F_108 ( struct V_10 * V_118 ,
struct V_10 * V_119 )
{
int V_45 ;
F_26 ( V_118 == V_119 ) ;
F_26 ( V_118 -> V_5 == V_119 -> V_5 ) ;
if ( F_6 ( V_119 ) )
return 0 ;
if ( V_118 -> V_42 -> V_120 ) {
V_45 = F_24 ( V_118 -> V_13 ,
& V_118 -> V_86 ,
& V_119 -> V_86 ) ;
if ( V_45 < 0 )
return V_45 ;
}
if ( V_118 -> V_42 == V_119 -> V_42 ) {
V_45 = F_109 ( & V_118 -> V_12 ,
& V_119 -> V_12 ,
V_24 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
if ( V_118 -> V_42 -> V_121 . V_122 ) {
T_1 V_40 ;
F_26 ( ! V_119 -> V_42 -> V_121 . signal ) ;
V_40 = F_110 ( V_119 ) ;
if ( ! V_40 )
goto V_123;
if ( V_40 <= V_118 -> V_5 -> V_52 [ V_119 -> V_42 -> V_44 ] )
return 0 ;
F_111 ( V_118 , V_119 ) ;
V_45 = V_118 -> V_42 -> V_121 . V_122 ( V_118 , V_119 ) ;
if ( V_45 )
return V_45 ;
V_118 -> V_5 -> V_52 [ V_119 -> V_42 -> V_44 ] = V_40 ;
return 0 ;
}
V_123:
V_45 = F_112 ( & V_118 -> V_12 ,
& V_119 -> V_2 , 0 ,
V_24 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
int
F_113 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_1 * * V_124 = & V_2 ;
unsigned int V_125 = 1 ;
int V_45 ;
if ( F_114 ( V_2 ) ) {
struct V_126 * V_127 = F_115 ( V_2 ) ;
V_124 = V_127 -> V_128 ;
V_125 = V_127 -> V_129 ;
F_26 ( ! V_125 ) ;
}
do {
V_2 = * V_124 ++ ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
continue;
if ( V_2 -> V_130 == V_11 -> V_2 . V_130 )
continue;
if ( V_2 -> V_130 != V_11 -> V_13 -> V_18 . V_131 &&
F_116 ( V_11 -> V_5 , V_2 ) )
continue;
if ( F_117 ( V_2 ) )
V_45 = F_108 ( V_11 ,
F_4 ( V_2 ) ) ;
else
V_45 = F_112 ( & V_11 -> V_12 , V_2 ,
V_132 ,
V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_2 -> V_130 != V_11 -> V_13 -> V_18 . V_131 )
F_118 ( V_11 -> V_5 , V_2 ) ;
} while ( -- V_125 );
return 0 ;
}
int
F_119 ( struct V_10 * V_118 ,
struct V_133 * V_134 ,
bool V_135 )
{
struct V_1 * V_136 ;
int V_45 = 0 ;
if ( V_135 ) {
struct V_1 * * V_137 ;
unsigned int V_138 , V_139 ;
V_45 = F_120 ( V_134 -> V_140 ,
& V_136 , & V_138 , & V_137 ) ;
if ( V_45 )
return V_45 ;
for ( V_139 = 0 ; V_139 < V_138 ; V_139 ++ ) {
V_45 = F_113 ( V_118 , V_137 [ V_139 ] ) ;
if ( V_45 )
break;
F_121 ( V_137 [ V_139 ] ) ;
}
for (; V_139 < V_138 ; V_139 ++ )
F_121 ( V_137 [ V_139 ] ) ;
F_62 ( V_137 ) ;
} else {
V_136 = F_122 ( V_134 -> V_140 ) ;
}
if ( V_136 ) {
if ( V_45 == 0 )
V_45 = F_113 ( V_118 , V_136 ) ;
F_121 ( V_136 ) ;
}
return V_45 ;
}
void F_123 ( struct V_10 * V_15 , bool V_141 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_102 * V_71 = V_15 -> V_71 ;
struct V_49 * V_5 = V_15 -> V_5 ;
struct V_10 * V_142 ;
T_1 * V_143 ;
int V_144 ;
F_42 ( & V_15 -> V_13 -> V_56 . V_57 ) ;
F_124 ( V_15 ) ;
F_26 ( V_5 -> V_40 != V_15 -> V_2 . V_40 ) ;
V_15 -> V_112 = 0 ;
if ( V_141 ) {
V_144 = V_42 -> V_145 ( V_15 , V_146 ) ;
F_125 ( V_144 , L_3 , V_144 ) ;
}
V_143 = F_126 ( V_15 , V_42 -> V_114 ) ;
F_26 ( F_99 ( V_143 ) ) ;
V_15 -> V_73 = F_127 ( V_15 , V_143 ) ;
V_142 = F_128 ( & V_5 -> V_51 ,
& V_15 -> V_13 -> V_56 . V_57 ) ;
if ( V_142 ) {
F_129 ( & V_15 -> V_12 , & V_142 -> V_12 ,
& V_15 -> V_147 ) ;
if ( V_42 -> V_120 )
F_21 ( & V_15 -> V_86 ,
& V_142 -> V_86 ,
& V_15 -> V_25 ,
0 ) ;
}
F_66 ( & V_5 -> V_19 ) ;
F_130 ( & V_15 -> V_37 , & V_5 -> V_14 ) ;
F_68 ( & V_5 -> V_19 ) ;
F_26 ( V_5 -> V_40 != V_15 -> V_2 . V_40 ) ;
F_131 ( & V_5 -> V_51 , V_15 ) ;
F_130 ( & V_15 -> V_70 , & V_71 -> V_72 ) ;
V_15 -> V_148 = V_149 ;
if ( V_42 -> V_120 )
V_42 -> V_120 ( V_15 , V_15 -> V_79 -> V_38 ) ;
F_132 () ;
F_133 ( & V_15 -> V_12 ) ;
F_134 () ;
}
static unsigned long F_135 ( unsigned int * V_150 )
{
unsigned long V_151 ;
* V_150 = F_136 () ;
V_151 = F_137 () >> 10 ;
F_138 () ;
return V_151 ;
}
static bool F_139 ( unsigned long V_9 , unsigned int V_150 )
{
unsigned int V_152 ;
if ( F_140 ( F_135 ( & V_152 ) , V_9 ) )
return true ;
return V_152 != V_150 ;
}
bool F_141 ( const struct V_10 * V_11 ,
T_1 V_40 , int V_96 , unsigned long V_153 )
{
struct V_41 * V_42 = V_11 -> V_42 ;
unsigned int V_154 , V_150 ;
V_154 = F_142 ( & V_42 -> V_155 ) ;
V_153 += F_135 ( & V_150 ) ;
do {
if ( V_40 != F_110 ( V_11 ) )
break;
if ( F_33 ( F_82 ( V_11 -> V_42 ) ,
V_40 ) )
return true ;
if ( F_142 ( & V_42 -> V_155 ) != V_154 )
break;
if ( F_143 ( V_96 , V_156 ) )
break;
if ( F_139 ( V_153 , V_150 ) )
break;
F_144 () ;
} while ( ! F_145 () );
return false ;
}
static bool F_146 ( struct V_10 * V_15 )
{
if ( F_147 ( ! F_148 ( & V_15 -> V_13 -> V_103 ) ) )
return false ;
F_149 ( V_157 ) ;
F_150 ( V_15 -> V_13 , 0 ) ;
return true ;
}
long F_10 ( struct V_10 * V_11 ,
unsigned int V_4 ,
long V_9 )
{
const int V_96 = V_4 & V_46 ?
V_158 : V_159 ;
T_3 * V_160 = & V_11 -> V_13 -> V_103 . V_161 ;
F_151 ( V_162 , V_163 ) ;
F_151 ( V_164 , V_163 ) ;
struct V_165 V_166 ;
F_152 () ;
#if F_153 ( V_167 )
F_26 ( V_168 &&
! ! F_154 ( & V_11 -> V_13 -> V_56 . V_57 ) !=
! ! ( V_4 & V_47 ) ) ;
#endif
F_26 ( V_9 < 0 ) ;
if ( F_6 ( V_11 ) )
return V_9 ;
if ( ! V_9 )
return - V_169 ;
F_155 ( V_11 , V_4 ) ;
F_156 ( & V_11 -> V_93 , & V_164 ) ;
if ( V_4 & V_47 )
F_156 ( V_160 , & V_162 ) ;
F_157 ( & V_166 , V_11 ) ;
V_170:
do {
F_158 ( V_96 ) ;
if ( F_159 ( & V_166 , V_11 ) )
break;
if ( V_4 & V_47 &&
F_146 ( V_11 ) )
continue;
if ( F_143 ( V_96 , V_156 ) ) {
V_9 = - V_171 ;
goto V_172;
}
if ( ! V_9 ) {
V_9 = - V_169 ;
goto V_172;
}
V_9 = F_160 ( V_9 ) ;
} while ( 1 );
F_26 ( ! F_161 ( & V_166 ) ) ;
F_26 ( ! F_64 ( & V_11 -> V_12 ) ) ;
if ( F_162 ( V_11 , V_96 , 5 ) )
goto V_172;
F_158 ( V_96 ) ;
if ( F_163 ( V_11 -> V_42 , & V_166 ) )
goto V_173;
if ( V_4 & V_47 )
F_146 ( V_11 ) ;
for (; ; ) {
if ( F_143 ( V_96 , V_156 ) ) {
V_9 = - V_171 ;
break;
}
if ( ! V_9 ) {
V_9 = - V_169 ;
break;
}
V_9 = F_160 ( V_9 ) ;
if ( F_164 ( & V_166 ) &&
F_165 ( & V_166 , V_11 ) )
break;
F_158 ( V_96 ) ;
V_173:
if ( F_166 ( V_11 ) )
break;
if ( V_4 & V_47 &&
F_146 ( V_11 ) )
continue;
if ( F_162 ( V_11 , V_96 , 2 ) )
break;
if ( ! F_165 ( & V_166 , V_11 ) ) {
F_167 ( V_11 -> V_42 , & V_166 ) ;
goto V_170;
}
}
F_167 ( V_11 -> V_42 , & V_166 ) ;
V_172:
F_149 ( V_157 ) ;
if ( V_4 & V_47 )
F_168 ( V_160 , & V_162 ) ;
F_168 ( & V_11 -> V_93 , & V_164 ) ;
F_169 ( V_11 ) ;
return V_9 ;
}
static void F_170 ( struct V_41 * V_42 )
{
struct V_10 * V_15 , * V_36 ;
T_1 V_40 = F_82 ( V_42 ) ;
F_171 ( V_78 ) ;
F_66 ( & V_42 -> V_5 -> V_19 ) ;
F_28 (request, next,
&engine->timeline->requests, link) {
if ( ! F_33 ( V_40 , V_15 -> V_89 ) )
break;
F_84 ( & V_15 -> V_37 , & V_78 ) ;
}
F_68 ( & V_42 -> V_5 -> V_19 ) ;
F_28 (request, next, &retire, link)
F_63 ( V_15 ) ;
}
void F_172 ( struct V_22 * V_55 )
{
struct V_41 * V_42 ;
enum V_43 V_44 ;
F_42 ( & V_55 -> V_56 . V_57 ) ;
if ( ! V_55 -> V_59 . V_61 )
return;
F_32 (engine, dev_priv, id)
F_170 ( V_42 ) ;
}
