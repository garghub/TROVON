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
static bool F_12 ( struct V_1 * V_7 ,
struct V_14 * V_15 , const T_1 * V_16 )
{
if ( F_13 ( V_7 ) )
return true ;
if ( V_7 -> V_17 & V_18 )
return true ;
if ( V_15 && ! F_14 ( V_7 , V_15 ) )
return true ;
if ( ! F_1 ( V_7 , V_16 ) )
return true ;
return false ;
}
unsigned long F_15 ( struct V_1 * V_7 , struct V_14 * V_15 ,
const T_1 * V_16 , unsigned long V_19 )
{
long V_20 ;
long V_21 ;
if ( F_12 ( V_7 , V_15 , V_16 ) )
return 0 ;
V_7 = F_7 ( V_7 ) ;
if ( ! V_7 )
return 0 ;
V_21 = ( long ) V_7 -> signal -> V_22 ;
if ( V_21 == V_23 ||
F_16 ( V_24 , & V_7 -> V_9 -> V_17 ) ||
F_17 ( V_7 ) ) {
F_10 ( V_7 ) ;
return 0 ;
}
V_20 = F_18 ( V_7 -> V_9 ) + F_19 ( V_7 -> V_9 , V_25 ) +
F_20 ( & V_7 -> V_9 -> V_26 ) + F_21 ( V_7 -> V_9 ) ;
F_10 ( V_7 ) ;
if ( F_22 ( V_7 , V_27 ) )
V_20 -= ( V_20 * 3 ) / 100 ;
V_21 *= V_19 / 1000 ;
V_20 += V_21 ;
return V_20 > 0 ? V_20 : 1 ;
}
static enum V_28 F_23 ( struct V_11 * V_12 ,
unsigned long * V_19 )
{
struct V_29 * V_29 ;
struct V_30 * V_31 ;
enum V_32 V_33 = F_24 ( V_12 -> V_34 ) ;
bool V_35 = false ;
int V_36 ;
* V_19 = V_37 + V_38 ;
if ( ! V_12 -> V_39 )
return V_40 ;
if ( V_12 -> V_34 & V_41 )
return V_40 ;
if ( V_12 -> V_16 &&
! F_25 ( V_42 [ V_43 ] , * V_12 -> V_16 ) ) {
* V_19 = V_38 ;
F_26 ( V_36 , * V_12 -> V_16 )
* V_19 += F_27 ( V_36 ) ;
return V_44 ;
}
F_28 (zone, z, oc->zonelist,
high_zoneidx, oc->nodemask)
if ( ! F_29 ( V_29 , V_12 -> V_34 ) )
V_35 = true ;
if ( V_35 ) {
* V_19 = V_38 ;
F_26 ( V_36 , V_45 )
* V_19 += F_27 ( V_36 ) ;
return V_46 ;
}
return V_40 ;
}
static enum V_28 F_23 ( struct V_11 * V_12 ,
unsigned long * V_19 )
{
* V_19 = V_37 + V_38 ;
return V_40 ;
}
enum V_47 F_30 ( struct V_11 * V_12 ,
struct V_1 * V_48 )
{
if ( F_12 ( V_48 , NULL , V_12 -> V_16 ) )
return V_49 ;
if ( ! F_11 ( V_12 ) && F_31 ( & V_48 -> signal -> V_50 ) ) {
struct V_1 * V_7 = F_7 ( V_48 ) ;
enum V_47 V_5 = V_51 ;
if ( V_7 ) {
if ( F_16 ( V_24 , & V_7 -> V_9 -> V_17 ) )
V_5 = V_49 ;
F_10 ( V_7 ) ;
}
return V_5 ;
}
if ( F_32 ( V_48 ) )
return V_52 ;
return V_53 ;
}
static struct V_1 * F_33 ( struct V_11 * V_12 ,
unsigned int * V_54 , unsigned long V_19 )
{
struct V_1 * V_7 ;
struct V_1 * V_55 = NULL ;
unsigned long V_56 = 0 ;
F_2 () ;
F_34 (p) {
unsigned int V_20 ;
switch ( F_30 ( V_12 , V_7 ) ) {
case V_52 :
V_55 = V_7 ;
V_56 = V_57 ;
case V_49 :
continue;
case V_51 :
F_6 () ;
return (struct V_1 * ) ( - 1UL ) ;
case V_53 :
break;
} ;
V_20 = F_15 ( V_7 , NULL , V_12 -> V_16 , V_19 ) ;
if ( ! V_20 || V_20 < V_56 )
continue;
V_55 = V_7 ;
V_56 = V_20 ;
}
if ( V_55 )
F_35 ( V_55 ) ;
F_6 () ;
* V_54 = V_56 * 1000 / V_19 ;
return V_55 ;
}
static void F_36 ( struct V_14 * V_15 , const T_1 * V_16 )
{
struct V_1 * V_7 ;
struct V_1 * V_48 ;
F_37 ( L_1 ) ;
F_2 () ;
F_34 (p) {
if ( F_12 ( V_7 , V_15 , V_16 ) )
continue;
V_48 = F_7 ( V_7 ) ;
if ( ! V_48 ) {
continue;
}
F_37 ( L_2 ,
V_48 -> V_58 , F_38 ( & V_59 , F_39 ( V_48 ) ) ,
V_48 -> V_60 , V_48 -> V_9 -> V_61 , F_18 ( V_48 -> V_9 ) ,
F_20 ( & V_48 -> V_9 -> V_26 ) ,
F_21 ( V_48 -> V_9 ) ,
F_19 ( V_48 -> V_9 , V_25 ) ,
V_48 -> signal -> V_22 , V_48 -> V_62 ) ;
F_10 ( V_48 ) ;
}
F_6 () ;
}
static void F_40 ( struct V_11 * V_12 , struct V_1 * V_7 )
{
F_41 ( L_3 ,
V_6 -> V_62 , V_12 -> V_34 , & V_12 -> V_34 , V_12 -> V_13 ,
V_6 -> signal -> V_22 ) ;
F_42 () ;
F_43 () ;
if ( V_12 -> V_15 )
F_44 ( V_12 -> V_15 , V_7 ) ;
else
F_45 ( V_63 ) ;
if ( V_64 )
F_36 ( V_12 -> V_15 , V_12 -> V_16 ) ;
}
bool F_46 ( struct V_1 * V_7 , struct V_65 * V_9 )
{
struct V_1 * V_8 ;
F_3 (p, t) {
struct V_65 * V_66 = F_47 ( V_8 -> V_9 ) ;
if ( V_66 )
return V_66 == V_9 ;
}
return false ;
}
static bool F_48 ( struct V_1 * V_4 )
{
struct V_67 V_68 ;
struct V_69 * V_70 ;
struct V_65 * V_9 = NULL ;
struct V_1 * V_7 ;
struct V_71 V_72 = { . V_73 = true ,
. V_74 = true } ;
bool V_5 = true ;
F_49 ( & V_75 ) ;
V_7 = F_7 ( V_4 ) ;
if ( ! V_7 )
goto V_76;
V_9 = V_7 -> V_9 ;
F_50 ( & V_9 -> V_77 ) ;
F_10 ( V_7 ) ;
if ( ! F_51 ( & V_9 -> V_78 ) ) {
V_5 = false ;
goto V_79;
}
if ( ! F_52 ( V_9 ) ) {
F_53 ( & V_9 -> V_78 ) ;
goto V_79;
}
F_54 ( & V_68 , V_9 , 0 , - 1 ) ;
for ( V_70 = V_9 -> V_80 ; V_70 ; V_70 = V_70 -> V_81 ) {
if ( F_55 ( V_70 ) )
continue;
if ( V_70 -> V_82 & V_83 )
continue;
if ( F_56 ( V_70 ) || ! ( V_70 -> V_82 & V_84 ) )
F_57 ( & V_68 , V_70 , V_70 -> V_85 , V_70 -> V_86 ,
& V_72 ) ;
}
F_58 ( & V_68 , 0 , - 1 ) ;
F_37 ( L_4 ,
F_59 ( V_4 ) , V_4 -> V_62 ,
F_60 ( F_19 ( V_9 , V_87 ) ) ,
F_60 ( F_19 ( V_9 , V_88 ) ) ,
F_60 ( F_19 ( V_9 , V_89 ) ) ) ;
F_53 ( & V_9 -> V_78 ) ;
F_61 ( V_24 , & V_9 -> V_17 ) ;
F_62 ( V_9 ) ;
V_79:
F_63 ( V_9 ) ;
V_76:
F_64 ( & V_75 ) ;
return V_5 ;
}
static void F_65 ( struct V_1 * V_4 )
{
int V_90 = 0 ;
while ( V_90 ++ < V_91 && ! F_48 ( V_4 ) )
F_66 ( V_92 / 10 ) ;
if ( V_90 > V_91 ) {
struct V_1 * V_7 ;
F_37 ( L_5 ,
F_59 ( V_4 ) , V_4 -> V_62 ) ;
V_7 = F_7 ( V_4 ) ;
if ( V_7 ) {
if ( F_67 ( V_93 , & V_7 -> V_9 -> V_17 ) ) {
F_37 ( L_6 ,
F_59 ( V_4 ) , V_4 -> V_62 ) ;
F_61 ( V_24 , & V_7 -> V_9 -> V_17 ) ;
}
F_10 ( V_7 ) ;
}
F_68 () ;
}
V_4 -> V_94 = NULL ;
F_69 ( V_4 ) ;
F_70 ( V_4 ) ;
}
static int F_71 ( void * V_95 )
{
F_72 () ;
while ( true ) {
struct V_1 * V_4 = NULL ;
F_73 ( V_96 , V_94 != NULL ) ;
F_74 ( & V_97 ) ;
if ( V_94 != NULL ) {
V_4 = V_94 ;
V_94 = V_4 -> V_94 ;
}
F_75 ( & V_97 ) ;
if ( V_4 )
F_65 ( V_4 ) ;
}
return 0 ;
}
void F_76 ( struct V_1 * V_4 )
{
if ( ! V_98 )
return;
if ( V_4 == V_94 || V_4 -> V_94 )
return;
F_35 ( V_4 ) ;
F_74 ( & V_97 ) ;
V_4 -> V_94 = V_94 ;
V_94 = V_4 ;
F_75 ( & V_97 ) ;
F_77 ( & V_96 ) ;
}
static int T_2 F_78 ( void )
{
V_98 = F_79 ( F_71 , NULL , L_7 ) ;
if ( F_80 ( V_98 ) ) {
F_81 ( L_8 ,
F_82 ( V_98 ) ) ;
V_98 = NULL ;
}
return 0 ;
}
void F_83 ( struct V_1 * V_4 )
{
F_84 ( V_99 ) ;
if ( F_85 ( V_4 , V_100 ) )
return;
F_50 ( & V_4 -> signal -> V_50 ) ;
F_86 ( V_4 ) ;
F_50 ( & V_50 ) ;
}
void F_69 ( struct V_1 * V_4 )
{
if ( ! F_87 ( V_4 , V_100 ) )
return;
F_88 ( & V_4 -> signal -> V_50 ) ;
if ( ! F_89 ( & V_50 ) )
F_90 ( & V_101 ) ;
}
bool F_91 ( void )
{
if ( F_92 ( & V_75 ) )
return false ;
V_99 = true ;
F_64 ( & V_75 ) ;
F_93 ( V_101 , ! F_31 ( & V_50 ) ) ;
return true ;
}
void F_94 ( void )
{
V_99 = false ;
}
static inline bool F_95 ( struct V_1 * V_48 )
{
struct V_102 * V_103 = V_48 -> signal ;
if ( V_103 -> V_17 & V_104 )
return false ;
if ( V_103 -> V_17 & V_105 )
return true ;
if ( F_96 ( V_48 ) && ( V_48 -> V_17 & V_106 ) )
return true ;
return false ;
}
bool F_97 ( struct V_1 * V_48 )
{
struct V_65 * V_9 = V_48 -> V_9 ;
struct V_1 * V_7 ;
bool V_5 = true ;
if ( ! V_9 )
return false ;
if ( ! F_95 ( V_48 ) )
return false ;
if ( F_16 ( V_24 , & V_9 -> V_17 ) )
return false ;
if ( F_31 ( & V_9 -> V_107 ) <= 1 )
return true ;
F_2 () ;
F_34 (p) {
if ( ! F_46 ( V_7 , V_9 ) )
continue;
if ( F_98 ( V_48 , V_7 ) )
continue;
V_5 = F_95 ( V_7 ) ;
if ( ! V_5 )
break;
}
F_6 () ;
return V_5 ;
}
void F_99 ( struct V_11 * V_12 , struct V_1 * V_7 ,
unsigned int V_20 , unsigned long V_19 ,
const char * V_108 )
{
struct V_1 * V_109 = V_7 ;
struct V_1 * V_110 ;
struct V_1 * V_8 ;
struct V_65 * V_9 ;
unsigned int V_111 = 0 ;
static F_100 ( V_112 , V_113 ,
V_114 ) ;
bool V_115 = true ;
F_8 ( V_7 ) ;
if ( F_97 ( V_7 ) ) {
F_83 ( V_7 ) ;
F_76 ( V_7 ) ;
F_10 ( V_7 ) ;
F_70 ( V_7 ) ;
return;
}
F_10 ( V_7 ) ;
if ( F_101 ( & V_112 ) )
F_40 ( V_12 , V_7 ) ;
F_81 ( L_9 ,
V_108 , F_59 ( V_7 ) , V_7 -> V_62 , V_20 ) ;
F_102 ( & V_116 ) ;
F_3 (p, t) {
F_103 (child, &t->children, sibling) {
unsigned int V_117 ;
if ( F_46 ( V_110 , V_7 -> V_9 ) )
continue;
V_117 = F_15 ( V_110 ,
V_12 -> V_15 , V_12 -> V_16 , V_19 ) ;
if ( V_117 > V_111 ) {
F_70 ( V_109 ) ;
V_109 = V_110 ;
V_111 = V_117 ;
F_35 ( V_109 ) ;
}
}
}
F_104 ( & V_116 ) ;
V_7 = F_7 ( V_109 ) ;
if ( ! V_7 ) {
F_70 ( V_109 ) ;
return;
} else if ( V_109 != V_7 ) {
F_35 ( V_7 ) ;
F_70 ( V_109 ) ;
V_109 = V_7 ;
}
V_9 = V_109 -> V_9 ;
F_50 ( & V_9 -> V_77 ) ;
F_105 ( V_118 , V_119 , V_109 , true ) ;
F_83 ( V_109 ) ;
F_81 ( L_10 ,
F_59 ( V_109 ) , V_109 -> V_62 , F_60 ( V_109 -> V_9 -> V_61 ) ,
F_60 ( F_19 ( V_109 -> V_9 , V_87 ) ) ,
F_60 ( F_19 ( V_109 -> V_9 , V_88 ) ) ,
F_60 ( F_19 ( V_109 -> V_9 , V_89 ) ) ) ;
F_10 ( V_109 ) ;
F_2 () ;
F_34 (p) {
if ( ! F_46 ( V_7 , V_9 ) )
continue;
if ( F_98 ( V_7 , V_109 ) )
continue;
if ( F_106 ( V_7 -> V_17 & V_18 ) || F_13 ( V_7 ) ) {
V_115 = false ;
F_61 ( V_24 , & V_9 -> V_17 ) ;
F_37 ( L_11 ,
F_59 ( V_109 ) , V_109 -> V_62 ,
F_59 ( V_7 ) , V_7 -> V_62 ) ;
continue;
}
F_105 ( V_118 , V_119 , V_7 , true ) ;
}
F_6 () ;
if ( V_115 )
F_76 ( V_109 ) ;
F_63 ( V_9 ) ;
F_70 ( V_109 ) ;
}
void F_107 ( struct V_11 * V_12 , enum V_28 V_120 )
{
if ( F_9 ( ! V_121 ) )
return;
if ( V_121 != 2 ) {
if ( V_120 != V_40 )
return;
}
if ( F_11 ( V_12 ) )
return;
F_40 ( V_12 , NULL ) ;
F_108 ( L_12 ,
V_121 == 2 ? L_13 : L_14 ) ;
}
int F_109 ( struct V_122 * V_123 )
{
return F_110 ( & V_124 , V_123 ) ;
}
int F_111 ( struct V_122 * V_123 )
{
return F_112 ( & V_124 , V_123 ) ;
}
bool F_113 ( struct V_11 * V_12 )
{
struct V_1 * V_7 ;
unsigned long V_19 ;
unsigned long V_125 = 0 ;
unsigned int V_126 ( V_20 ) ;
enum V_28 V_120 = V_40 ;
if ( V_99 )
return false ;
F_114 ( & V_124 , 0 , & V_125 ) ;
if ( V_125 > 0 )
return true ;
if ( F_97 ( V_6 ) ) {
F_83 ( V_6 ) ;
F_76 ( V_6 ) ;
return true ;
}
if ( V_12 -> V_34 && ! ( V_12 -> V_34 & ( V_127 | V_128 ) ) )
return true ;
V_120 = F_23 ( V_12 , & V_19 ) ;
if ( V_120 != V_44 )
V_12 -> V_16 = NULL ;
F_107 ( V_12 , V_120 ) ;
if ( V_129 && V_6 -> V_9 &&
! F_12 ( V_6 , NULL , V_12 -> V_16 ) &&
V_6 -> signal -> V_22 != V_23 ) {
F_35 ( V_6 ) ;
F_99 ( V_12 , V_6 , 0 , V_19 ,
L_15 ) ;
return true ;
}
V_7 = F_33 ( V_12 , & V_20 , V_19 ) ;
if ( ! V_7 && ! F_11 ( V_12 ) ) {
F_40 ( V_12 , NULL ) ;
F_108 ( L_16 ) ;
}
if ( V_7 && V_7 != ( void * ) - 1UL ) {
F_99 ( V_12 , V_7 , V_20 , V_19 , L_17 ) ;
F_115 ( 1 ) ;
}
return true ;
}
void F_116 ( void )
{
struct V_11 V_12 = {
. V_39 = NULL ,
. V_16 = NULL ,
. V_15 = NULL ,
. V_34 = 0 ,
. V_13 = 0 ,
} ;
if ( F_117 ( true ) )
return;
if ( ! F_118 ( & V_75 ) )
return;
if ( ! F_113 ( & V_12 ) ) {
F_84 ( F_119 ( V_100 ) ) ;
}
F_64 ( & V_75 ) ;
}
