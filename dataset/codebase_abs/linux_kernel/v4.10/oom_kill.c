static bool F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
struct V_1 * V_4 ;
bool V_5 = false ;
F_2 () ;
F_3 (start, tsk) {
if ( V_3 ) {
V_5 = F_4 ( V_4 , V_3 ) ;
} else {
V_5 = F_5 ( V_6 , V_4 ) ;
}
if ( V_5 )
break;
}
F_6 () ;
return V_5 ;
}
static bool F_1 ( struct V_1 * V_4 ,
const T_1 * V_3 )
{
return true ;
}
struct V_1 * F_7 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
F_2 () ;
F_3 (p, t) {
F_8 ( V_8 ) ;
if ( F_9 ( V_8 -> V_9 ) )
goto V_10;
F_10 ( V_8 ) ;
}
V_8 = NULL ;
V_10:
F_6 () ;
return V_8 ;
}
static inline bool F_11 ( struct V_11 * V_12 )
{
return V_12 -> V_13 == - 1 ;
}
static inline bool F_12 ( struct V_11 * V_12 )
{
return V_12 -> V_14 != NULL ;
}
static bool F_13 ( struct V_1 * V_7 ,
struct V_15 * V_14 , const T_1 * V_16 )
{
if ( F_14 ( V_7 ) )
return true ;
if ( V_7 -> V_17 & V_18 )
return true ;
if ( V_14 && ! F_15 ( V_7 , V_14 ) )
return true ;
if ( ! F_1 ( V_7 , V_16 ) )
return true ;
return false ;
}
unsigned long F_16 ( struct V_1 * V_7 , struct V_15 * V_14 ,
const T_1 * V_16 , unsigned long V_19 )
{
long V_20 ;
long V_21 ;
if ( F_13 ( V_7 , V_14 , V_16 ) )
return 0 ;
V_7 = F_7 ( V_7 ) ;
if ( ! V_7 )
return 0 ;
V_21 = ( long ) V_7 -> signal -> V_22 ;
if ( V_21 == V_23 ||
F_17 ( V_24 , & V_7 -> V_9 -> V_17 ) ||
F_18 ( V_7 ) ) {
F_10 ( V_7 ) ;
return 0 ;
}
V_20 = F_19 ( V_7 -> V_9 ) + F_20 ( V_7 -> V_9 , V_25 ) +
F_21 ( & V_7 -> V_9 -> V_26 ) + F_22 ( V_7 -> V_9 ) ;
F_10 ( V_7 ) ;
if ( F_23 ( V_7 , V_27 ) )
V_20 -= ( V_20 * 3 ) / 100 ;
V_21 *= V_19 / 1000 ;
V_20 += V_21 ;
return V_20 > 0 ? V_20 : 1 ;
}
static enum V_28 F_24 ( struct V_11 * V_12 )
{
struct V_29 * V_29 ;
struct V_30 * V_31 ;
enum V_32 V_33 = F_25 ( V_12 -> V_34 ) ;
bool V_35 = false ;
int V_36 ;
if ( F_12 ( V_12 ) ) {
V_12 -> V_19 = F_26 ( V_12 -> V_14 ) ? : 1 ;
return V_37 ;
}
V_12 -> V_19 = V_38 + V_39 ;
if ( ! F_27 ( V_40 ) )
return V_41 ;
if ( ! V_12 -> V_42 )
return V_41 ;
if ( V_12 -> V_34 & V_43 )
return V_41 ;
if ( V_12 -> V_16 &&
! F_28 ( V_44 [ V_45 ] , * V_12 -> V_16 ) ) {
V_12 -> V_19 = V_39 ;
F_29 (nid, *oc->nodemask)
V_12 -> V_19 += F_30 ( V_36 ) ;
return V_46 ;
}
F_31 (zone, z, oc->zonelist,
high_zoneidx, oc->nodemask)
if ( ! F_32 ( V_29 , V_12 -> V_34 ) )
V_35 = true ;
if ( V_35 ) {
V_12 -> V_19 = V_39 ;
F_29 (nid, cpuset_current_mems_allowed)
V_12 -> V_19 += F_30 ( V_36 ) ;
return V_47 ;
}
return V_41 ;
}
static int F_33 ( struct V_1 * V_48 , void * V_49 )
{
struct V_11 * V_12 = V_49 ;
unsigned long V_20 ;
if ( F_13 ( V_48 , NULL , V_12 -> V_16 ) )
goto V_50;
if ( ! F_11 ( V_12 ) && F_34 ( V_48 ) ) {
if ( F_17 ( V_24 , & V_48 -> signal -> V_51 -> V_17 ) )
goto V_50;
goto abort;
}
if ( F_35 ( V_48 ) ) {
V_20 = V_52 ;
goto V_53;
}
V_20 = F_16 ( V_48 , NULL , V_12 -> V_16 , V_12 -> V_19 ) ;
if ( ! V_20 || V_20 < V_12 -> V_54 )
goto V_50;
if ( V_20 == V_12 -> V_54 && F_36 ( V_12 -> V_55 ) )
goto V_50;
V_53:
if ( V_12 -> V_55 )
F_37 ( V_12 -> V_55 ) ;
F_38 ( V_48 ) ;
V_12 -> V_55 = V_48 ;
V_12 -> V_54 = V_20 ;
V_50:
return 0 ;
abort:
if ( V_12 -> V_55 )
F_37 ( V_12 -> V_55 ) ;
V_12 -> V_55 = ( void * ) - 1UL ;
return 1 ;
}
static void F_39 ( struct V_11 * V_12 )
{
if ( F_12 ( V_12 ) )
F_40 ( V_12 -> V_14 , F_33 , V_12 ) ;
else {
struct V_1 * V_7 ;
F_2 () ;
F_41 (p)
if ( F_33 ( V_7 , V_12 ) )
break;
F_6 () ;
}
V_12 -> V_54 = V_12 -> V_54 * 1000 / V_12 -> V_19 ;
}
static void F_42 ( struct V_15 * V_14 , const T_1 * V_16 )
{
struct V_1 * V_7 ;
struct V_1 * V_48 ;
F_43 ( L_1 ) ;
F_2 () ;
F_41 (p) {
if ( F_13 ( V_7 , V_14 , V_16 ) )
continue;
V_48 = F_7 ( V_7 ) ;
if ( ! V_48 ) {
continue;
}
F_43 ( L_2 ,
V_48 -> V_56 , F_44 ( & V_57 , F_45 ( V_48 ) ) ,
V_48 -> V_58 , V_48 -> V_9 -> V_59 , F_19 ( V_48 -> V_9 ) ,
F_21 ( & V_48 -> V_9 -> V_26 ) ,
F_22 ( V_48 -> V_9 ) ,
F_20 ( V_48 -> V_9 , V_25 ) ,
V_48 -> signal -> V_22 , V_48 -> V_60 ) ;
F_10 ( V_48 ) ;
}
F_6 () ;
}
static void F_46 ( struct V_11 * V_12 , struct V_1 * V_7 )
{
T_1 * V_61 = ( V_12 -> V_16 ) ? V_12 -> V_16 : & V_62 ;
F_47 ( L_3 ,
V_6 -> V_60 , V_12 -> V_34 , & V_12 -> V_34 ,
F_48 ( V_61 ) , V_12 -> V_13 ,
V_6 -> signal -> V_22 ) ;
if ( ! F_27 ( V_63 ) && V_12 -> V_13 )
F_47 ( L_4 ) ;
F_49 () ;
F_50 () ;
if ( V_12 -> V_14 )
F_51 ( V_12 -> V_14 , V_7 ) ;
else
F_52 ( V_64 ) ;
if ( V_65 )
F_42 ( V_12 -> V_14 , V_12 -> V_16 ) ;
}
bool F_53 ( struct V_1 * V_7 , struct V_66 * V_9 )
{
struct V_1 * V_8 ;
F_3 (p, t) {
struct V_66 * V_67 = F_54 ( V_8 -> V_9 ) ;
if ( V_67 )
return V_67 == V_9 ;
}
return false ;
}
static bool F_55 ( struct V_1 * V_4 , struct V_66 * V_9 )
{
struct V_68 V_69 ;
struct V_70 * V_71 ;
struct V_72 V_73 = { . V_74 = true ,
. V_75 = true } ;
bool V_5 = true ;
F_56 ( & V_76 ) ;
if ( ! F_57 ( & V_9 -> V_77 ) ) {
V_5 = false ;
goto V_78;
}
if ( ! F_58 ( V_9 ) ) {
F_59 ( & V_9 -> V_77 ) ;
goto V_78;
}
F_60 ( V_79 , & V_9 -> V_17 ) ;
F_61 ( & V_69 , V_9 , 0 , - 1 ) ;
for ( V_71 = V_9 -> V_80 ; V_71 ; V_71 = V_71 -> V_81 ) {
if ( F_62 ( V_71 ) )
continue;
if ( V_71 -> V_82 & V_83 )
continue;
if ( F_63 ( V_71 ) || ! ( V_71 -> V_82 & V_84 ) )
F_64 ( & V_69 , V_71 , V_71 -> V_85 , V_71 -> V_86 ,
& V_73 ) ;
}
F_65 ( & V_69 , 0 , - 1 ) ;
F_43 ( L_5 ,
F_66 ( V_4 ) , V_4 -> V_60 ,
F_67 ( F_20 ( V_9 , V_87 ) ) ,
F_67 ( F_20 ( V_9 , V_88 ) ) ,
F_67 ( F_20 ( V_9 , V_89 ) ) ) ;
F_59 ( & V_9 -> V_77 ) ;
F_68 ( V_9 ) ;
V_78:
F_69 ( & V_76 ) ;
return V_5 ;
}
static void F_70 ( struct V_1 * V_4 )
{
int V_90 = 0 ;
struct V_66 * V_9 = V_4 -> signal -> V_51 ;
while ( V_90 ++ < V_91 && ! F_55 ( V_4 , V_9 ) )
F_71 ( V_92 / 10 ) ;
if ( V_90 <= V_91 )
goto V_93;
F_43 ( L_6 ,
F_66 ( V_4 ) , V_4 -> V_60 ) ;
F_72 () ;
V_93:
V_4 -> V_94 = NULL ;
F_60 ( V_24 , & V_9 -> V_17 ) ;
F_37 ( V_4 ) ;
}
static int F_73 ( void * V_95 )
{
while ( true ) {
struct V_1 * V_4 = NULL ;
F_74 ( V_96 , V_94 != NULL ) ;
F_75 ( & V_97 ) ;
if ( V_94 != NULL ) {
V_4 = V_94 ;
V_94 = V_4 -> V_94 ;
}
F_76 ( & V_97 ) ;
if ( V_4 )
F_70 ( V_4 ) ;
}
return 0 ;
}
static void F_77 ( struct V_1 * V_4 )
{
if ( ! V_98 )
return;
if ( V_4 == V_94 || V_4 -> V_94 )
return;
F_38 ( V_4 ) ;
F_75 ( & V_97 ) ;
V_4 -> V_94 = V_94 ;
V_94 = V_4 ;
F_76 ( & V_97 ) ;
F_78 ( & V_96 ) ;
}
static int T_2 F_79 ( void )
{
V_98 = F_80 ( F_73 , NULL , L_7 ) ;
if ( F_81 ( V_98 ) ) {
F_82 ( L_8 ,
F_83 ( V_98 ) ) ;
V_98 = NULL ;
}
return 0 ;
}
static inline void F_77 ( struct V_1 * V_4 )
{
}
static void F_84 ( struct V_1 * V_4 )
{
struct V_66 * V_9 = V_4 -> V_9 ;
F_85 ( V_99 ) ;
if ( F_86 ( V_4 , V_100 ) )
return;
if ( ! F_87 ( & V_4 -> signal -> V_51 , NULL , V_9 ) )
F_88 ( & V_4 -> signal -> V_51 -> V_101 ) ;
F_89 ( V_4 ) ;
F_88 ( & V_102 ) ;
}
void F_90 ( void )
{
F_91 ( V_100 ) ;
if ( ! F_92 ( & V_102 ) )
F_93 ( & V_103 ) ;
}
void F_94 ( void )
{
V_99 = false ;
}
bool F_95 ( signed long V_104 )
{
signed long V_5 ;
if ( F_96 ( & V_76 ) )
return false ;
V_99 = true ;
F_69 ( & V_76 ) ;
V_5 = F_97 ( V_103 ,
! F_98 ( & V_102 ) , V_104 ) ;
if ( V_5 <= 0 ) {
F_94 () ;
return false ;
}
return true ;
}
static inline bool F_99 ( struct V_1 * V_48 )
{
struct V_105 * V_106 = V_48 -> signal ;
if ( V_106 -> V_17 & V_107 )
return false ;
if ( V_106 -> V_17 & V_108 )
return true ;
if ( F_100 ( V_48 ) && ( V_48 -> V_17 & V_109 ) )
return true ;
return false ;
}
static bool F_101 ( struct V_1 * V_48 )
{
struct V_66 * V_9 = V_48 -> V_9 ;
struct V_1 * V_7 ;
bool V_5 = true ;
if ( ! V_9 )
return false ;
if ( ! F_99 ( V_48 ) )
return false ;
if ( F_17 ( V_24 , & V_9 -> V_17 ) )
return false ;
if ( F_98 ( & V_9 -> V_110 ) <= 1 )
return true ;
F_2 () ;
F_41 (p) {
if ( ! F_53 ( V_7 , V_9 ) )
continue;
if ( F_102 ( V_48 , V_7 ) )
continue;
V_5 = F_99 ( V_7 ) ;
if ( ! V_5 )
break;
}
F_6 () ;
return V_5 ;
}
static void F_103 ( struct V_11 * V_12 , const char * V_111 )
{
struct V_1 * V_7 = V_12 -> V_55 ;
unsigned int V_20 = V_12 -> V_54 ;
struct V_1 * V_112 = V_7 ;
struct V_1 * V_113 ;
struct V_1 * V_8 ;
struct V_66 * V_9 ;
unsigned int V_114 = 0 ;
static F_104 ( V_115 , V_116 ,
V_117 ) ;
bool V_118 = true ;
F_8 ( V_7 ) ;
if ( F_101 ( V_7 ) ) {
F_84 ( V_7 ) ;
F_77 ( V_7 ) ;
F_10 ( V_7 ) ;
F_37 ( V_7 ) ;
return;
}
F_10 ( V_7 ) ;
if ( F_105 ( & V_115 ) )
F_46 ( V_12 , V_7 ) ;
F_82 ( L_9 ,
V_111 , F_66 ( V_7 ) , V_7 -> V_60 , V_20 ) ;
F_106 ( & V_119 ) ;
F_3 (p, t) {
F_107 (child, &t->children, sibling) {
unsigned int V_120 ;
if ( F_53 ( V_113 , V_7 -> V_9 ) )
continue;
V_120 = F_16 ( V_113 ,
V_12 -> V_14 , V_12 -> V_16 , V_12 -> V_19 ) ;
if ( V_120 > V_114 ) {
F_37 ( V_112 ) ;
V_112 = V_113 ;
V_114 = V_120 ;
F_38 ( V_112 ) ;
}
}
}
F_108 ( & V_119 ) ;
V_7 = F_7 ( V_112 ) ;
if ( ! V_7 ) {
F_37 ( V_112 ) ;
return;
} else if ( V_112 != V_7 ) {
F_38 ( V_7 ) ;
F_37 ( V_112 ) ;
V_112 = V_7 ;
}
V_9 = V_112 -> V_9 ;
F_88 ( & V_9 -> V_101 ) ;
F_109 ( V_121 , V_122 , V_112 , true ) ;
F_84 ( V_112 ) ;
F_82 ( L_10 ,
F_66 ( V_112 ) , V_112 -> V_60 , F_67 ( V_112 -> V_9 -> V_59 ) ,
F_67 ( F_20 ( V_112 -> V_9 , V_87 ) ) ,
F_67 ( F_20 ( V_112 -> V_9 , V_88 ) ) ,
F_67 ( F_20 ( V_112 -> V_9 , V_89 ) ) ) ;
F_10 ( V_112 ) ;
F_2 () ;
F_41 (p) {
if ( ! F_53 ( V_7 , V_9 ) )
continue;
if ( F_102 ( V_7 , V_112 ) )
continue;
if ( F_14 ( V_7 ) ) {
V_118 = false ;
F_60 ( V_24 , & V_9 -> V_17 ) ;
F_43 ( L_11 ,
F_66 ( V_112 ) , V_112 -> V_60 ,
F_66 ( V_7 ) , V_7 -> V_60 ) ;
continue;
}
if ( F_110 ( V_7 -> V_17 & V_18 ) )
continue;
F_109 ( V_121 , V_122 , V_7 , true ) ;
}
F_6 () ;
if ( V_118 )
F_77 ( V_112 ) ;
F_111 ( V_9 ) ;
F_37 ( V_112 ) ;
}
static void F_112 ( struct V_11 * V_12 ,
enum V_28 V_123 )
{
if ( F_9 ( ! V_124 ) )
return;
if ( V_124 != 2 ) {
if ( V_123 != V_41 )
return;
}
if ( F_11 ( V_12 ) )
return;
F_46 ( V_12 , NULL ) ;
F_113 ( L_12 ,
V_124 == 2 ? L_13 : L_14 ) ;
}
int F_114 ( struct V_125 * V_126 )
{
return F_115 ( & V_127 , V_126 ) ;
}
int F_116 ( struct V_125 * V_126 )
{
return F_117 ( & V_127 , V_126 ) ;
}
bool F_118 ( struct V_11 * V_12 )
{
unsigned long V_128 = 0 ;
enum V_28 V_123 = V_41 ;
if ( V_99 )
return false ;
if ( ! F_12 ( V_12 ) ) {
F_119 ( & V_127 , 0 , & V_128 ) ;
if ( V_128 > 0 )
return true ;
}
if ( F_101 ( V_6 ) ) {
F_84 ( V_6 ) ;
F_77 ( V_6 ) ;
return true ;
}
if ( V_12 -> V_34 && ! ( V_12 -> V_34 & ( V_129 | V_130 ) ) )
return true ;
V_123 = F_24 ( V_12 ) ;
if ( V_123 != V_46 )
V_12 -> V_16 = NULL ;
F_112 ( V_12 , V_123 ) ;
if ( ! F_12 ( V_12 ) && V_131 &&
V_6 -> V_9 && ! F_13 ( V_6 , NULL , V_12 -> V_16 ) &&
V_6 -> signal -> V_22 != V_23 ) {
F_38 ( V_6 ) ;
V_12 -> V_55 = V_6 ;
F_103 ( V_12 , L_15 ) ;
return true ;
}
F_39 ( V_12 ) ;
if ( ! V_12 -> V_55 && ! F_11 ( V_12 ) && ! F_12 ( V_12 ) ) {
F_46 ( V_12 , NULL ) ;
F_113 ( L_16 ) ;
}
if ( V_12 -> V_55 && V_12 -> V_55 != ( void * ) - 1UL ) {
F_103 ( V_12 , ! F_12 ( V_12 ) ? L_17 :
L_18 ) ;
F_120 ( 1 ) ;
}
return ! ! V_12 -> V_55 ;
}
void F_121 ( void )
{
struct V_11 V_12 = {
. V_42 = NULL ,
. V_16 = NULL ,
. V_14 = NULL ,
. V_34 = 0 ,
. V_13 = 0 ,
} ;
if ( F_122 ( true ) )
return;
if ( ! F_123 ( & V_76 ) )
return;
F_118 ( & V_12 ) ;
F_69 ( & V_76 ) ;
}
