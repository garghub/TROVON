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
F_36 ( V_42 , V_40 ) ;
V_50 -> V_40 = V_40 ;
F_37 (timeline, &i915->gt.timelines, link)
memset ( V_5 -> V_42 [ V_44 ] . V_51 , 0 ,
sizeof( V_5 -> V_42 [ V_44 ] . V_51 ) ) ;
}
return 0 ;
}
int F_38 ( struct V_52 * V_53 , T_1 V_40 )
{
struct V_22 * V_54 = F_39 ( V_53 ) ;
F_40 ( & V_54 -> V_55 . V_56 ) ;
if ( V_40 == 0 )
return - V_57 ;
return F_30 ( V_54 , V_40 - 1 ) ;
}
static int F_41 ( struct V_41 * V_42 )
{
T_1 V_58 = ++ V_42 -> V_5 -> V_59 ;
T_1 V_40 = V_42 -> V_5 -> V_40 ;
int V_45 ;
if ( F_42 ( ! F_43 ( V_40 , V_58 ) ) )
return 0 ;
V_45 = F_30 ( V_42 -> V_13 , 0 ) ;
if ( V_45 ) {
V_42 -> V_5 -> V_59 -- ;
return V_45 ;
}
return 0 ;
}
static void F_44 ( struct V_41 * V_42 )
{
F_26 ( ! V_42 -> V_5 -> V_59 ) ;
V_42 -> V_5 -> V_59 -- ;
}
void F_45 ( struct V_60 * V_58 ,
struct V_10 * V_15 )
{
}
static void F_46 ( struct V_10 * V_15 )
{
unsigned int V_61 ;
if ( F_47 ( & V_15 -> V_62 , & V_15 -> V_63 -> V_64 ) ) {
V_61 = F_48 ( V_15 -> V_63 -> V_61 ) ;
} else {
V_61 = V_15 -> V_65 ;
}
F_16 ( & V_15 -> V_62 ) ;
V_15 -> V_63 -> V_66 = V_61 ;
}
static void F_49 ( struct V_10 * V_15 )
{
struct V_67 * V_68 ;
V_68 = V_15 -> V_69 ;
while ( V_68 ) {
struct V_67 * V_36 = V_68 -> V_36 ;
F_50 ( V_68 ) ;
V_68 = V_36 ;
}
}
static void F_51 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_60 * V_58 , * V_36 ;
F_40 ( & V_15 -> V_13 -> V_55 . V_56 ) ;
F_26 ( ! F_52 ( & V_15 -> V_12 ) ) ;
F_26 ( ! F_6 ( V_15 ) ) ;
F_26 ( ! V_15 -> V_13 -> V_70 . V_71 ) ;
F_53 ( V_15 ) ;
F_54 ( & V_42 -> V_5 -> V_19 ) ;
F_55 ( & V_15 -> V_37 ) ;
F_56 ( & V_42 -> V_5 -> V_19 ) ;
if ( ! -- V_15 -> V_13 -> V_70 . V_71 ) {
F_26 ( ! V_15 -> V_13 -> V_70 . V_72 ) ;
F_57 ( V_15 -> V_13 -> V_73 ,
& V_15 -> V_13 -> V_70 . V_74 ,
F_58 ( 100 ) ) ;
}
F_44 ( V_15 -> V_42 ) ;
F_46 ( V_15 ) ;
F_49 ( V_15 ) ;
F_28 (active, next, &request->active_list, link) {
F_59 ( V_36 ) ;
F_22 ( & V_58 -> V_37 ) ;
F_60 ( V_58 -> V_15 , NULL ) ;
V_58 -> V_75 ( V_58 , V_15 ) ;
}
F_14 ( V_15 ) ;
if ( V_15 -> V_76 -> V_77 > 0 )
V_15 -> V_76 -> V_77 -- ;
if ( V_42 -> V_78 )
V_42 -> V_79 ( V_42 , V_42 -> V_78 ) ;
V_42 -> V_78 = V_15 -> V_76 ;
F_61 ( & V_15 -> V_2 ) ;
F_25 ( V_15 -> V_13 , & V_15 -> V_80 ) ;
F_62 ( V_15 ) ;
}
void F_63 ( struct V_10 * V_11 )
{
struct V_41 * V_42 = V_11 -> V_42 ;
struct V_10 * V_81 ;
F_40 ( & V_11 -> V_13 -> V_55 . V_56 ) ;
F_26 ( ! F_6 ( V_11 ) ) ;
if ( F_27 ( & V_11 -> V_37 ) )
return;
do {
V_81 = F_64 ( & V_42 -> V_5 -> V_14 ,
F_65 ( * V_81 ) , V_37 ) ;
F_51 ( V_81 ) ;
} while ( V_81 != V_11 );
}
static T_1 F_66 ( struct V_49 * V_50 )
{
return ++ V_50 -> V_40 ;
}
void F_67 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_49 * V_5 ;
T_1 V_40 ;
F_26 ( ! F_68 () ) ;
F_40 ( & V_42 -> V_5 -> V_19 ) ;
F_69 ( V_15 ) ;
V_5 = V_42 -> V_5 ;
F_26 ( V_5 == V_15 -> V_5 ) ;
V_40 = F_66 ( V_5 ) ;
F_26 ( ! V_40 ) ;
F_26 ( F_33 ( F_70 ( V_42 ) , V_40 ) ) ;
F_71 ( & V_15 -> V_19 , V_82 ) ;
V_15 -> V_83 = V_40 ;
if ( F_3 ( V_84 , & V_15 -> V_2 . V_4 ) )
F_8 ( V_15 , false ) ;
F_17 ( & V_15 -> V_19 ) ;
V_42 -> V_85 ( V_15 ,
V_15 -> V_63 -> V_86 + V_15 -> V_65 ) ;
F_15 ( & V_15 -> V_5 -> V_19 ) ;
F_72 ( & V_15 -> V_37 , & V_5 -> V_14 ) ;
F_17 ( & V_15 -> V_5 -> V_19 ) ;
F_73 ( & V_15 -> V_87 ) ;
}
void F_74 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
unsigned long V_4 ;
F_75 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
F_67 ( V_15 ) ;
F_76 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
}
void F_77 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_49 * V_5 ;
F_26 ( ! F_68 () ) ;
F_40 ( & V_42 -> V_5 -> V_19 ) ;
F_26 ( V_15 -> V_83 != V_42 -> V_5 -> V_40 ) ;
V_42 -> V_5 -> V_40 -- ;
F_71 ( & V_15 -> V_19 , V_82 ) ;
V_15 -> V_83 = 0 ;
if ( F_3 ( V_84 , & V_15 -> V_2 . V_4 ) )
F_78 ( V_15 ) ;
F_17 ( & V_15 -> V_19 ) ;
V_5 = V_15 -> V_5 ;
F_26 ( V_5 == V_42 -> V_5 ) ;
F_15 ( & V_5 -> V_19 ) ;
F_79 ( & V_15 -> V_37 , & V_5 -> V_14 ) ;
F_17 ( & V_5 -> V_19 ) ;
}
void F_80 ( struct V_10 * V_15 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
unsigned long V_4 ;
F_75 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
F_77 ( V_15 ) ;
F_76 ( & V_42 -> V_5 -> V_19 , V_4 ) ;
}
static int T_2
F_81 ( struct V_88 * V_2 , enum V_89 V_90 )
{
struct V_10 * V_15 =
F_82 ( V_2 , F_65 ( * V_15 ) , V_12 ) ;
switch ( V_90 ) {
case V_91 :
F_83 ( V_15 ) ;
V_15 -> V_42 -> V_92 ( V_15 ) ;
break;
case V_93 :
F_62 ( V_15 ) ;
break;
}
return V_94 ;
}
struct V_10 *
F_84 ( struct V_41 * V_42 ,
struct V_95 * V_76 )
{
struct V_22 * V_54 = V_42 -> V_13 ;
struct V_10 * V_11 ;
struct V_96 * V_63 ;
int V_45 ;
F_40 ( & V_54 -> V_55 . V_56 ) ;
if ( F_85 ( & V_54 -> V_97 ) )
return F_86 ( - V_98 ) ;
V_63 = V_42 -> V_99 ( V_42 , V_76 ) ;
if ( F_87 ( V_63 ) )
return F_88 ( V_63 ) ;
F_26 ( ! V_63 ) ;
V_45 = F_41 ( V_42 ) ;
if ( V_45 )
goto V_100;
V_11 = F_89 ( & V_42 -> V_5 -> V_14 ,
F_65 ( * V_11 ) , V_37 ) ;
if ( V_11 && F_6 ( V_11 ) )
F_51 ( V_11 ) ;
V_11 = F_19 ( V_54 -> V_14 , V_24 ) ;
if ( ! V_11 ) {
V_45 = - V_34 ;
goto V_101;
}
V_11 -> V_5 = F_90 ( V_76 , V_42 ) ;
F_26 ( V_11 -> V_5 == V_42 -> V_5 ) ;
F_91 ( & V_11 -> V_19 ) ;
F_92 ( & V_11 -> V_2 ,
& V_102 ,
& V_11 -> V_19 ,
V_11 -> V_5 -> V_103 ,
F_66 ( V_11 -> V_5 ) ) ;
F_93 ( & F_94 ( V_11 ) -> V_12 , F_81 ) ;
F_95 ( & V_11 -> V_87 ) ;
F_29 ( & V_11 -> V_80 ) ;
F_22 ( & V_11 -> V_104 ) ;
V_11 -> V_13 = V_54 ;
V_11 -> V_42 = V_42 ;
V_11 -> V_76 = V_76 ;
V_11 -> V_63 = V_63 ;
V_11 -> V_83 = 0 ;
V_11 -> V_17 = NULL ;
V_11 -> V_105 = NULL ;
V_11 -> V_69 = NULL ;
V_11 -> V_106 = V_107 ;
F_26 ( V_11 -> V_106 < V_42 -> V_108 ) ;
V_45 = V_42 -> V_109 ( V_11 ) ;
if ( V_45 )
goto V_110;
V_11 -> V_66 = V_11 -> V_63 -> V_111 ;
F_26 ( V_11 -> V_5 -> V_40 != V_11 -> V_2 . V_40 ) ;
return V_11 ;
V_110:
F_26 ( ! F_27 ( & V_11 -> V_104 ) ) ;
F_26 ( ! F_27 ( & V_11 -> V_80 . V_32 ) ) ;
F_26 ( ! F_27 ( & V_11 -> V_80 . V_30 ) ) ;
F_13 ( V_54 -> V_14 , V_11 ) ;
V_101:
F_44 ( V_42 ) ;
V_100:
V_42 -> V_79 ( V_42 , V_76 ) ;
return F_86 ( V_45 ) ;
}
static int
F_96 ( struct V_10 * V_112 ,
struct V_10 * V_113 )
{
int V_45 ;
F_26 ( V_112 == V_113 ) ;
F_26 ( V_112 -> V_5 == V_113 -> V_5 ) ;
if ( F_6 ( V_113 ) )
return 0 ;
if ( V_112 -> V_42 -> V_114 ) {
V_45 = F_24 ( V_112 -> V_13 ,
& V_112 -> V_80 ,
& V_113 -> V_80 ) ;
if ( V_45 < 0 )
return V_45 ;
}
if ( V_112 -> V_42 == V_113 -> V_42 ) {
V_45 = F_97 ( & V_112 -> V_12 ,
& V_113 -> V_12 ,
V_24 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
if ( V_112 -> V_42 -> V_115 . V_116 ) {
T_1 V_40 ;
F_26 ( ! V_113 -> V_42 -> V_115 . signal ) ;
V_40 = F_98 ( V_113 ) ;
if ( ! V_40 )
goto V_117;
if ( V_40 <= V_112 -> V_5 -> V_51 [ V_113 -> V_42 -> V_44 ] )
return 0 ;
F_99 ( V_112 , V_113 ) ;
V_45 = V_112 -> V_42 -> V_115 . V_116 ( V_112 , V_113 ) ;
if ( V_45 )
return V_45 ;
V_112 -> V_5 -> V_51 [ V_113 -> V_42 -> V_44 ] = V_40 ;
return 0 ;
}
V_117:
V_45 = F_100 ( & V_112 -> V_12 ,
& V_113 -> V_2 , 0 ,
V_24 ) ;
return V_45 < 0 ? V_45 : 0 ;
}
int
F_101 ( struct V_10 * V_11 ,
struct V_1 * V_2 )
{
struct V_1 * * V_118 = & V_2 ;
unsigned int V_119 = 1 ;
int V_45 ;
if ( F_102 ( V_2 ) ) {
struct V_120 * V_121 = F_103 ( V_2 ) ;
V_118 = V_121 -> V_122 ;
V_119 = V_121 -> V_123 ;
F_26 ( ! V_119 ) ;
}
do {
V_2 = * V_118 ++ ;
if ( F_3 ( V_3 , & V_2 -> V_4 ) )
continue;
if ( V_2 -> V_124 == V_11 -> V_2 . V_124 )
continue;
if ( V_2 -> V_124 != V_11 -> V_13 -> V_18 . V_125 &&
F_104 ( V_11 -> V_5 , V_2 ) )
continue;
if ( F_105 ( V_2 ) )
V_45 = F_96 ( V_11 ,
F_4 ( V_2 ) ) ;
else
V_45 = F_100 ( & V_11 -> V_12 , V_2 ,
V_126 ,
V_24 ) ;
if ( V_45 < 0 )
return V_45 ;
if ( V_2 -> V_124 != V_11 -> V_13 -> V_18 . V_125 )
F_106 ( V_11 -> V_5 , V_2 ) ;
} while ( -- V_119 );
return 0 ;
}
int
F_107 ( struct V_10 * V_112 ,
struct V_127 * V_128 ,
bool V_129 )
{
struct V_1 * V_130 ;
int V_45 = 0 ;
if ( V_129 ) {
struct V_1 * * V_131 ;
unsigned int V_132 , V_133 ;
V_45 = F_108 ( V_128 -> V_134 ,
& V_130 , & V_132 , & V_131 ) ;
if ( V_45 )
return V_45 ;
for ( V_133 = 0 ; V_133 < V_132 ; V_133 ++ ) {
V_45 = F_101 ( V_112 , V_131 [ V_133 ] ) ;
if ( V_45 )
break;
F_109 ( V_131 [ V_133 ] ) ;
}
for (; V_133 < V_132 ; V_133 ++ )
F_109 ( V_131 [ V_133 ] ) ;
F_50 ( V_131 ) ;
} else {
V_130 = F_110 ( V_128 -> V_134 ) ;
}
if ( V_130 ) {
if ( V_45 == 0 )
V_45 = F_101 ( V_112 , V_130 ) ;
F_109 ( V_130 ) ;
}
return V_45 ;
}
static void F_111 ( const struct V_41 * V_42 )
{
struct V_22 * V_54 = V_42 -> V_13 ;
if ( V_54 -> V_70 . V_72 )
return;
F_26 ( ! V_54 -> V_70 . V_71 ) ;
F_112 ( V_54 ) ;
V_54 -> V_70 . V_72 = true ;
F_113 ( V_54 ) ;
F_114 ( V_54 ) ;
if ( F_115 ( V_54 ) >= 6 )
F_116 ( V_54 ) ;
F_117 ( V_54 -> V_73 ,
& V_54 -> V_70 . V_135 ,
F_118 ( V_136 ) ) ;
}
void F_119 ( struct V_10 * V_15 , bool V_137 )
{
struct V_41 * V_42 = V_15 -> V_42 ;
struct V_96 * V_63 = V_15 -> V_63 ;
struct V_49 * V_5 = V_15 -> V_5 ;
struct V_10 * V_138 ;
T_1 * V_139 ;
int V_140 ;
F_40 ( & V_15 -> V_13 -> V_55 . V_56 ) ;
F_120 ( V_15 ) ;
F_26 ( V_5 -> V_40 != V_15 -> V_2 . V_40 ) ;
V_15 -> V_106 = 0 ;
if ( V_137 ) {
V_140 = V_42 -> V_141 ( V_15 , V_142 ) ;
F_121 ( V_140 , L_3 , V_140 ) ;
}
V_139 = F_122 ( V_15 , V_42 -> V_108 ) ;
F_26 ( F_87 ( V_139 ) ) ;
V_15 -> V_65 = F_123 ( V_15 , V_139 ) ;
V_138 = F_124 ( & V_5 -> V_143 ,
& V_15 -> V_13 -> V_55 . V_56 ) ;
if ( V_138 ) {
F_125 ( & V_15 -> V_12 , & V_138 -> V_12 ,
& V_15 -> V_144 ) ;
if ( V_42 -> V_114 )
F_21 ( & V_15 -> V_80 ,
& V_138 -> V_80 ,
& V_15 -> V_25 ,
0 ) ;
}
F_54 ( & V_5 -> V_19 ) ;
F_126 ( & V_15 -> V_37 , & V_5 -> V_14 ) ;
F_56 ( & V_5 -> V_19 ) ;
F_26 ( V_5 -> V_40 != V_15 -> V_2 . V_40 ) ;
F_127 ( & V_5 -> V_143 , V_15 ) ;
F_126 ( & V_15 -> V_62 , & V_63 -> V_64 ) ;
V_15 -> V_145 = V_146 ;
if ( ! V_15 -> V_13 -> V_70 . V_71 ++ )
F_111 ( V_42 ) ;
if ( V_42 -> V_114 )
V_42 -> V_114 ( V_15 , V_15 -> V_76 -> V_38 ) ;
F_128 () ;
F_129 ( & V_15 -> V_12 ) ;
F_130 () ;
}
static unsigned long F_131 ( unsigned int * V_147 )
{
unsigned long V_148 ;
* V_147 = F_132 () ;
V_148 = F_133 () >> 10 ;
F_134 () ;
return V_148 ;
}
static bool F_135 ( unsigned long V_9 , unsigned int V_147 )
{
unsigned int V_149 ;
if ( F_136 ( F_131 ( & V_149 ) , V_9 ) )
return true ;
return V_149 != V_147 ;
}
bool F_137 ( const struct V_10 * V_11 ,
T_1 V_40 , int V_90 , unsigned long V_150 )
{
struct V_41 * V_42 = V_11 -> V_42 ;
unsigned int V_151 , V_147 ;
V_151 = F_138 ( & V_42 -> V_152 ) ;
V_150 += F_131 ( & V_147 ) ;
do {
if ( V_40 != F_98 ( V_11 ) )
break;
if ( F_33 ( F_70 ( V_11 -> V_42 ) ,
V_40 ) )
return true ;
if ( F_138 ( & V_42 -> V_152 ) != V_151 )
break;
if ( F_139 ( V_90 , V_153 ) )
break;
if ( F_135 ( V_150 , V_147 ) )
break;
F_140 () ;
} while ( ! F_141 () );
return false ;
}
static bool F_142 ( struct V_10 * V_15 )
{
if ( F_42 ( ! F_143 ( & V_15 -> V_13 -> V_97 ) ) )
return false ;
F_144 ( V_154 ) ;
F_145 ( V_15 -> V_13 ) ;
return true ;
}
long F_10 ( struct V_10 * V_11 ,
unsigned int V_4 ,
long V_9 )
{
const int V_90 = V_4 & V_46 ?
V_155 : V_156 ;
T_3 * V_157 = & V_11 -> V_13 -> V_97 . V_158 ;
F_146 ( V_159 , V_160 ) ;
F_146 ( V_161 , V_160 ) ;
struct V_162 V_163 ;
F_147 () ;
#if F_148 ( V_164 )
F_26 ( V_165 &&
! ! F_149 ( & V_11 -> V_13 -> V_55 . V_56 ) !=
! ! ( V_4 & V_47 ) ) ;
#endif
F_26 ( V_9 < 0 ) ;
if ( F_6 ( V_11 ) )
return V_9 ;
if ( ! V_9 )
return - V_166 ;
F_150 ( V_11 , V_4 ) ;
F_151 ( & V_11 -> V_87 , & V_161 ) ;
if ( V_4 & V_47 )
F_151 ( V_157 , & V_159 ) ;
F_152 ( & V_163 , V_11 ) ;
V_167:
do {
F_153 ( V_90 ) ;
if ( F_154 ( & V_163 , V_11 ) )
break;
if ( V_4 & V_47 &&
F_142 ( V_11 ) )
continue;
if ( F_139 ( V_90 , V_153 ) ) {
V_9 = - V_168 ;
goto V_169;
}
if ( ! V_9 ) {
V_9 = - V_166 ;
goto V_169;
}
V_9 = F_155 ( V_9 ) ;
} while ( 1 );
F_26 ( ! F_156 ( & V_163 ) ) ;
F_26 ( ! F_52 ( & V_11 -> V_12 ) ) ;
if ( F_157 ( V_11 , V_90 , 5 ) )
goto V_169;
F_153 ( V_90 ) ;
if ( F_158 ( V_11 -> V_42 , & V_163 ) )
goto V_170;
if ( V_4 & V_47 )
F_142 ( V_11 ) ;
for (; ; ) {
if ( F_139 ( V_90 , V_153 ) ) {
V_9 = - V_168 ;
break;
}
if ( ! V_9 ) {
V_9 = - V_166 ;
break;
}
V_9 = F_155 ( V_9 ) ;
if ( F_159 ( & V_163 ) &&
F_160 ( & V_163 , V_11 ) )
break;
F_153 ( V_90 ) ;
V_170:
if ( F_161 ( V_11 ) )
break;
if ( V_4 & V_47 &&
F_142 ( V_11 ) )
continue;
if ( F_157 ( V_11 , V_90 , 2 ) )
break;
if ( ! F_160 ( & V_163 , V_11 ) ) {
F_162 ( V_11 -> V_42 , & V_163 ) ;
goto V_167;
}
}
F_162 ( V_11 -> V_42 , & V_163 ) ;
V_169:
F_144 ( V_154 ) ;
if ( V_4 & V_47 )
F_163 ( V_157 , & V_159 ) ;
F_163 ( & V_11 -> V_87 , & V_161 ) ;
F_164 ( V_11 ) ;
return V_9 ;
}
static void F_165 ( struct V_41 * V_42 )
{
struct V_10 * V_15 , * V_36 ;
T_1 V_40 = F_70 ( V_42 ) ;
F_166 ( V_75 ) ;
F_54 ( & V_42 -> V_5 -> V_19 ) ;
F_28 (request, next,
&engine->timeline->requests, link) {
if ( ! F_33 ( V_40 , V_15 -> V_83 ) )
break;
F_72 ( & V_15 -> V_37 , & V_75 ) ;
}
F_56 ( & V_42 -> V_5 -> V_19 ) ;
F_28 (request, next, &retire, link)
F_51 ( V_15 ) ;
}
void F_167 ( struct V_22 * V_54 )
{
struct V_41 * V_42 ;
enum V_43 V_44 ;
F_40 ( & V_54 -> V_55 . V_56 ) ;
if ( ! V_54 -> V_70 . V_71 )
return;
F_32 (engine, dev_priv, id)
F_165 ( V_42 ) ;
}
