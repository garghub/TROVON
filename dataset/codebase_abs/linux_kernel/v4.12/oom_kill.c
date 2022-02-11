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
F_47 ( L_3 ,
V_6 -> V_60 , V_12 -> V_34 , & V_12 -> V_34 ) ;
if ( V_12 -> V_16 )
F_48 ( L_4 , F_49 ( V_12 -> V_16 ) ) ;
else
F_48 ( L_5 ) ;
F_48 ( L_6 ,
V_12 -> V_13 , V_6 -> signal -> V_22 ) ;
if ( ! F_27 ( V_61 ) && V_12 -> V_13 )
F_47 ( L_7 ) ;
F_50 () ;
F_51 () ;
if ( V_12 -> V_14 )
F_52 ( V_12 -> V_14 , V_7 ) ;
else
F_53 ( V_62 , V_12 -> V_16 ) ;
if ( V_63 )
F_42 ( V_12 -> V_14 , V_12 -> V_16 ) ;
}
bool F_54 ( struct V_1 * V_7 , struct V_64 * V_9 )
{
struct V_1 * V_8 ;
F_3 (p, t) {
struct V_64 * V_65 = F_55 ( V_8 -> V_9 ) ;
if ( V_65 )
return V_65 == V_9 ;
}
return false ;
}
static bool F_56 ( struct V_1 * V_4 , struct V_64 * V_9 )
{
struct V_66 V_67 ;
struct V_68 * V_69 ;
bool V_5 = true ;
F_57 ( & V_70 ) ;
if ( ! F_58 ( & V_9 -> V_71 ) ) {
V_5 = false ;
goto V_72;
}
if ( ! F_59 ( V_9 ) ) {
F_60 ( & V_9 -> V_71 ) ;
goto V_72;
}
F_61 ( V_73 , & V_9 -> V_17 ) ;
F_62 ( & V_67 , V_9 , 0 , - 1 ) ;
for ( V_69 = V_9 -> V_74 ; V_69 ; V_69 = V_69 -> V_75 ) {
if ( ! F_63 ( V_69 ) )
continue;
if ( F_64 ( V_69 ) || ! ( V_69 -> V_76 & V_77 ) )
F_65 ( & V_67 , V_69 , V_69 -> V_78 , V_69 -> V_79 ,
NULL ) ;
}
F_66 ( & V_67 , 0 , - 1 ) ;
F_43 ( L_8 ,
F_67 ( V_4 ) , V_4 -> V_60 ,
F_68 ( F_20 ( V_9 , V_80 ) ) ,
F_68 ( F_20 ( V_9 , V_81 ) ) ,
F_68 ( F_20 ( V_9 , V_82 ) ) ) ;
F_60 ( & V_9 -> V_71 ) ;
F_69 ( V_9 ) ;
V_72:
F_70 ( & V_70 ) ;
return V_5 ;
}
static void F_71 ( struct V_1 * V_4 )
{
int V_83 = 0 ;
struct V_64 * V_9 = V_4 -> signal -> V_51 ;
while ( V_83 ++ < V_84 && ! F_56 ( V_4 , V_9 ) )
F_72 ( V_85 / 10 ) ;
if ( V_83 <= V_84 )
goto V_86;
F_43 ( L_9 ,
F_67 ( V_4 ) , V_4 -> V_60 ) ;
F_73 () ;
V_86:
V_4 -> V_87 = NULL ;
F_61 ( V_24 , & V_9 -> V_17 ) ;
F_37 ( V_4 ) ;
}
static int F_74 ( void * V_88 )
{
while ( true ) {
struct V_1 * V_4 = NULL ;
F_75 ( V_89 , V_87 != NULL ) ;
F_76 ( & V_90 ) ;
if ( V_87 != NULL ) {
V_4 = V_87 ;
V_87 = V_4 -> V_87 ;
}
F_77 ( & V_90 ) ;
if ( V_4 )
F_71 ( V_4 ) ;
}
return 0 ;
}
static void F_78 ( struct V_1 * V_4 )
{
if ( ! V_91 )
return;
if ( V_4 == V_87 || V_4 -> V_87 )
return;
F_38 ( V_4 ) ;
F_76 ( & V_90 ) ;
V_4 -> V_87 = V_87 ;
V_87 = V_4 ;
F_77 ( & V_90 ) ;
F_79 ( & V_89 ) ;
}
static int T_2 F_80 ( void )
{
V_91 = F_81 ( F_74 , NULL , L_10 ) ;
if ( F_82 ( V_91 ) ) {
F_83 ( L_11 ,
F_84 ( V_91 ) ) ;
V_91 = NULL ;
}
return 0 ;
}
static inline void F_78 ( struct V_1 * V_4 )
{
}
static void F_85 ( struct V_1 * V_4 )
{
struct V_64 * V_9 = V_4 -> V_9 ;
F_86 ( V_92 ) ;
if ( F_87 ( V_4 , V_93 ) )
return;
if ( ! F_88 ( & V_4 -> signal -> V_51 , NULL , V_9 ) )
F_89 ( V_4 -> signal -> V_51 ) ;
F_90 ( V_4 ) ;
F_91 ( & V_94 ) ;
}
void F_92 ( void )
{
F_93 ( V_93 ) ;
if ( ! F_94 ( & V_94 ) )
F_95 ( & V_95 ) ;
}
void F_96 ( void )
{
V_92 = false ;
F_43 ( L_12 ) ;
}
bool F_97 ( signed long V_96 )
{
signed long V_5 ;
if ( F_98 ( & V_70 ) )
return false ;
V_92 = true ;
F_70 ( & V_70 ) ;
V_5 = F_99 ( V_95 ,
! F_100 ( & V_94 ) , V_96 ) ;
if ( V_5 <= 0 ) {
F_96 () ;
return false ;
}
F_43 ( L_13 ) ;
return true ;
}
static inline bool F_101 ( struct V_1 * V_48 )
{
struct V_97 * V_98 = V_48 -> signal ;
if ( V_98 -> V_17 & V_99 )
return false ;
if ( V_98 -> V_17 & V_100 )
return true ;
if ( F_102 ( V_48 ) && ( V_48 -> V_17 & V_101 ) )
return true ;
return false ;
}
static bool F_103 ( struct V_1 * V_48 )
{
struct V_64 * V_9 = V_48 -> V_9 ;
struct V_1 * V_7 ;
bool V_5 = true ;
if ( ! V_9 )
return false ;
if ( ! F_101 ( V_48 ) )
return false ;
if ( F_17 ( V_24 , & V_9 -> V_17 ) )
return false ;
if ( F_100 ( & V_9 -> V_102 ) <= 1 )
return true ;
F_2 () ;
F_41 (p) {
if ( ! F_54 ( V_7 , V_9 ) )
continue;
if ( F_104 ( V_48 , V_7 ) )
continue;
V_5 = F_101 ( V_7 ) ;
if ( ! V_5 )
break;
}
F_6 () ;
return V_5 ;
}
static void F_105 ( struct V_11 * V_12 , const char * V_103 )
{
struct V_1 * V_7 = V_12 -> V_55 ;
unsigned int V_20 = V_12 -> V_54 ;
struct V_1 * V_104 = V_7 ;
struct V_1 * V_105 ;
struct V_1 * V_8 ;
struct V_64 * V_9 ;
unsigned int V_106 = 0 ;
static F_106 ( V_107 , V_108 ,
V_109 ) ;
bool V_110 = true ;
F_8 ( V_7 ) ;
if ( F_103 ( V_7 ) ) {
F_85 ( V_7 ) ;
F_78 ( V_7 ) ;
F_10 ( V_7 ) ;
F_37 ( V_7 ) ;
return;
}
F_10 ( V_7 ) ;
if ( F_107 ( & V_107 ) )
F_46 ( V_12 , V_7 ) ;
F_83 ( L_14 ,
V_103 , F_67 ( V_7 ) , V_7 -> V_60 , V_20 ) ;
F_108 ( & V_111 ) ;
F_3 (p, t) {
F_109 (child, &t->children, sibling) {
unsigned int V_112 ;
if ( F_54 ( V_105 , V_7 -> V_9 ) )
continue;
V_112 = F_16 ( V_105 ,
V_12 -> V_14 , V_12 -> V_16 , V_12 -> V_19 ) ;
if ( V_112 > V_106 ) {
F_37 ( V_104 ) ;
V_104 = V_105 ;
V_106 = V_112 ;
F_38 ( V_104 ) ;
}
}
}
F_110 ( & V_111 ) ;
V_7 = F_7 ( V_104 ) ;
if ( ! V_7 ) {
F_37 ( V_104 ) ;
return;
} else if ( V_104 != V_7 ) {
F_38 ( V_7 ) ;
F_37 ( V_104 ) ;
V_104 = V_7 ;
}
V_9 = V_104 -> V_9 ;
F_89 ( V_9 ) ;
F_111 ( V_113 , V_114 , V_104 , true ) ;
F_85 ( V_104 ) ;
F_83 ( L_15 ,
F_67 ( V_104 ) , V_104 -> V_60 , F_68 ( V_104 -> V_9 -> V_59 ) ,
F_68 ( F_20 ( V_104 -> V_9 , V_80 ) ) ,
F_68 ( F_20 ( V_104 -> V_9 , V_81 ) ) ,
F_68 ( F_20 ( V_104 -> V_9 , V_82 ) ) ) ;
F_10 ( V_104 ) ;
F_2 () ;
F_41 (p) {
if ( ! F_54 ( V_7 , V_9 ) )
continue;
if ( F_104 ( V_7 , V_104 ) )
continue;
if ( F_14 ( V_7 ) ) {
V_110 = false ;
F_61 ( V_24 , & V_9 -> V_17 ) ;
F_43 ( L_16 ,
F_67 ( V_104 ) , V_104 -> V_60 ,
F_67 ( V_7 ) , V_7 -> V_60 ) ;
continue;
}
if ( F_112 ( V_7 -> V_17 & V_18 ) )
continue;
F_111 ( V_113 , V_114 , V_7 , true ) ;
}
F_6 () ;
if ( V_110 )
F_78 ( V_104 ) ;
F_113 ( V_9 ) ;
F_37 ( V_104 ) ;
}
static void F_114 ( struct V_11 * V_12 ,
enum V_28 V_115 )
{
if ( F_9 ( ! V_116 ) )
return;
if ( V_116 != 2 ) {
if ( V_115 != V_41 )
return;
}
if ( F_11 ( V_12 ) )
return;
F_46 ( V_12 , NULL ) ;
F_115 ( L_17 ,
V_116 == 2 ? L_18 : L_19 ) ;
}
int F_116 ( struct V_117 * V_118 )
{
return F_117 ( & V_119 , V_118 ) ;
}
int F_118 ( struct V_117 * V_118 )
{
return F_119 ( & V_119 , V_118 ) ;
}
bool F_120 ( struct V_11 * V_12 )
{
unsigned long V_120 = 0 ;
enum V_28 V_115 = V_41 ;
if ( V_92 )
return false ;
if ( ! F_12 ( V_12 ) ) {
F_121 ( & V_119 , 0 , & V_120 ) ;
if ( V_120 > 0 )
return true ;
}
if ( F_103 ( V_6 ) ) {
F_85 ( V_6 ) ;
F_78 ( V_6 ) ;
return true ;
}
if ( V_12 -> V_34 && ! ( V_12 -> V_34 & V_121 ) )
return true ;
V_115 = F_24 ( V_12 ) ;
if ( V_115 != V_46 )
V_12 -> V_16 = NULL ;
F_114 ( V_12 , V_115 ) ;
if ( ! F_12 ( V_12 ) && V_122 &&
V_6 -> V_9 && ! F_13 ( V_6 , NULL , V_12 -> V_16 ) &&
V_6 -> signal -> V_22 != V_23 ) {
F_38 ( V_6 ) ;
V_12 -> V_55 = V_6 ;
F_105 ( V_12 , L_20 ) ;
return true ;
}
F_39 ( V_12 ) ;
if ( ! V_12 -> V_55 && ! F_11 ( V_12 ) && ! F_12 ( V_12 ) ) {
F_46 ( V_12 , NULL ) ;
F_115 ( L_21 ) ;
}
if ( V_12 -> V_55 && V_12 -> V_55 != ( void * ) - 1UL ) {
F_105 ( V_12 , ! F_12 ( V_12 ) ? L_22 :
L_23 ) ;
F_122 ( 1 ) ;
}
return ! ! V_12 -> V_55 ;
}
void F_123 ( void )
{
struct V_11 V_12 = {
. V_42 = NULL ,
. V_16 = NULL ,
. V_14 = NULL ,
. V_34 = 0 ,
. V_13 = 0 ,
} ;
if ( F_124 ( true ) )
return;
if ( ! F_125 ( & V_70 ) )
return;
F_120 ( & V_12 ) ;
F_70 ( & V_70 ) ;
}
