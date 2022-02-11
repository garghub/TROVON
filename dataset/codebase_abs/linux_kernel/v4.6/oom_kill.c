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
if ( V_21 == V_23 ) {
F_10 ( V_7 ) ;
return 0 ;
}
V_20 = F_16 ( V_7 -> V_9 ) + F_17 ( V_7 -> V_9 , V_24 ) +
F_18 ( & V_7 -> V_9 -> V_25 ) + F_19 ( V_7 -> V_9 ) ;
F_10 ( V_7 ) ;
if ( F_20 ( V_7 , V_26 ) )
V_20 -= ( V_20 * 3 ) / 100 ;
V_21 *= V_19 / 1000 ;
V_20 += V_21 ;
return V_20 > 0 ? V_20 : 1 ;
}
static enum V_27 F_21 ( struct V_11 * V_12 ,
unsigned long * V_19 )
{
struct V_28 * V_28 ;
struct V_29 * V_30 ;
enum V_31 V_32 = F_22 ( V_12 -> V_33 ) ;
bool V_34 = false ;
int V_35 ;
* V_19 = V_36 + V_37 ;
if ( ! V_12 -> V_38 )
return V_39 ;
if ( V_12 -> V_33 & V_40 )
return V_39 ;
if ( V_12 -> V_16 &&
! F_23 ( V_41 [ V_42 ] , * V_12 -> V_16 ) ) {
* V_19 = V_37 ;
F_24 ( V_35 , * V_12 -> V_16 )
* V_19 += F_25 ( V_35 ) ;
return V_43 ;
}
F_26 (zone, z, oc->zonelist,
high_zoneidx, oc->nodemask)
if ( ! F_27 ( V_28 , V_12 -> V_33 ) )
V_34 = true ;
if ( V_34 ) {
* V_19 = V_37 ;
F_24 ( V_35 , V_44 )
* V_19 += F_25 ( V_35 ) ;
return V_45 ;
}
return V_39 ;
}
static enum V_27 F_21 ( struct V_11 * V_12 ,
unsigned long * V_19 )
{
* V_19 = V_36 + V_37 ;
return V_39 ;
}
enum V_46 F_28 ( struct V_11 * V_12 ,
struct V_1 * V_47 , unsigned long V_19 )
{
if ( F_12 ( V_47 , NULL , V_12 -> V_16 ) )
return V_48 ;
if ( F_29 ( V_47 , V_49 ) ) {
if ( ! F_11 ( V_12 ) )
return V_50 ;
}
if ( ! V_47 -> V_9 )
return V_48 ;
if ( F_30 ( V_47 ) )
return V_51 ;
return V_52 ;
}
static struct V_1 * F_31 ( struct V_11 * V_12 ,
unsigned int * V_53 , unsigned long V_19 )
{
struct V_1 * V_54 , * V_7 ;
struct V_1 * V_55 = NULL ;
unsigned long V_56 = 0 ;
F_2 () ;
F_32 (g, p) {
unsigned int V_20 ;
switch ( F_28 ( V_12 , V_7 , V_19 ) ) {
case V_51 :
V_55 = V_7 ;
V_56 = V_57 ;
case V_48 :
continue;
case V_50 :
F_6 () ;
return (struct V_1 * ) ( - 1UL ) ;
case V_52 :
break;
} ;
V_20 = F_15 ( V_7 , NULL , V_12 -> V_16 , V_19 ) ;
if ( ! V_20 || V_20 < V_56 )
continue;
if ( V_20 == V_56 && F_33 ( V_55 ) )
continue;
V_55 = V_7 ;
V_56 = V_20 ;
}
if ( V_55 )
F_34 ( V_55 ) ;
F_6 () ;
* V_53 = V_56 * 1000 / V_19 ;
return V_55 ;
}
static void F_35 ( struct V_14 * V_15 , const T_1 * V_16 )
{
struct V_1 * V_7 ;
struct V_1 * V_47 ;
F_36 ( L_1 ) ;
F_2 () ;
F_37 (p) {
if ( F_12 ( V_7 , V_15 , V_16 ) )
continue;
V_47 = F_7 ( V_7 ) ;
if ( ! V_47 ) {
continue;
}
F_36 ( L_2 ,
V_47 -> V_58 , F_38 ( & V_59 , F_39 ( V_47 ) ) ,
V_47 -> V_60 , V_47 -> V_9 -> V_61 , F_16 ( V_47 -> V_9 ) ,
F_18 ( & V_47 -> V_9 -> V_25 ) ,
F_19 ( V_47 -> V_9 ) ,
F_17 ( V_47 -> V_9 , V_24 ) ,
V_47 -> signal -> V_22 , V_47 -> V_62 ) ;
F_10 ( V_47 ) ;
}
F_6 () ;
}
static void F_40 ( struct V_11 * V_12 , struct V_1 * V_7 ,
struct V_14 * V_15 )
{
F_41 ( L_3 ,
V_6 -> V_62 , V_12 -> V_33 , & V_12 -> V_33 , V_12 -> V_13 ,
V_6 -> signal -> V_22 ) ;
F_42 () ;
F_43 () ;
if ( V_15 )
F_44 ( V_15 , V_7 ) ;
else
F_45 ( V_63 ) ;
if ( V_64 )
F_35 ( V_15 , V_12 -> V_16 ) ;
}
static bool F_46 ( struct V_1 * V_4 )
{
struct V_65 V_66 ;
struct V_67 * V_68 ;
struct V_69 * V_9 ;
struct V_1 * V_7 ;
struct V_70 V_71 = { . V_72 = true ,
. V_73 = true } ;
bool V_5 = true ;
V_7 = F_7 ( V_4 ) ;
if ( ! V_7 )
return true ;
V_9 = V_7 -> V_9 ;
if ( ! F_47 ( & V_9 -> V_74 ) ) {
F_10 ( V_7 ) ;
return true ;
}
F_10 ( V_7 ) ;
if ( ! F_48 ( & V_9 -> V_75 ) ) {
V_5 = false ;
goto V_76;
}
F_49 ( & V_66 , V_9 , 0 , - 1 ) ;
for ( V_68 = V_9 -> V_77 ; V_68 ; V_68 = V_68 -> V_78 ) {
if ( F_50 ( V_68 ) )
continue;
if ( V_68 -> V_79 & V_80 )
continue;
if ( F_51 ( V_68 ) || ! ( V_68 -> V_79 & V_81 ) )
F_52 ( & V_66 , V_68 , V_68 -> V_82 , V_68 -> V_83 ,
& V_71 ) ;
}
F_53 ( & V_66 , 0 , - 1 ) ;
F_36 ( L_4 ,
F_54 ( V_4 ) , V_4 -> V_62 ,
F_55 ( F_17 ( V_9 , V_84 ) ) ,
F_55 ( F_17 ( V_9 , V_85 ) ) ,
F_55 ( F_17 ( V_9 , V_86 ) ) ) ;
F_56 ( & V_9 -> V_75 ) ;
V_4 -> signal -> V_22 = V_23 ;
F_57 ( V_4 ) ;
V_76:
F_58 ( V_9 ) ;
return V_5 ;
}
static void F_59 ( struct V_1 * V_4 )
{
int V_87 = 0 ;
while ( V_87 ++ < V_88 && ! F_46 ( V_4 ) )
F_60 ( V_89 / 10 ) ;
if ( V_87 > V_88 ) {
F_36 ( L_5 ,
F_54 ( V_4 ) , V_4 -> V_62 ) ;
F_61 () ;
}
F_62 ( V_4 ) ;
}
static int F_63 ( void * V_90 )
{
F_64 () ;
while ( true ) {
struct V_1 * V_4 = NULL ;
F_65 ( V_91 , V_92 != NULL ) ;
F_66 ( & V_93 ) ;
if ( V_92 != NULL ) {
V_4 = V_92 ;
V_92 = V_4 -> V_92 ;
}
F_67 ( & V_93 ) ;
if ( V_4 )
F_59 ( V_4 ) ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_4 )
{
if ( ! V_94 )
return;
if ( V_4 == V_92 || V_4 -> V_92 )
return;
F_34 ( V_4 ) ;
F_66 ( & V_93 ) ;
V_4 -> V_92 = V_92 ;
V_92 = V_4 ;
F_67 ( & V_93 ) ;
F_69 ( & V_91 ) ;
}
static int T_2 F_70 ( void )
{
V_94 = F_71 ( F_63 , NULL , L_6 ) ;
if ( F_72 ( V_94 ) ) {
F_73 ( L_7 ,
F_74 ( V_94 ) ) ;
V_94 = NULL ;
}
return 0 ;
}
static void F_68 ( struct V_1 * V_4 )
{
}
void F_75 ( struct V_1 * V_4 )
{
F_76 ( V_95 ) ;
if ( F_77 ( V_4 , V_49 ) )
return;
F_78 ( V_4 ) ;
F_79 ( & V_96 ) ;
}
void F_57 ( struct V_1 * V_4 )
{
if ( ! F_80 ( V_4 , V_49 ) )
return;
if ( ! F_81 ( & V_96 ) )
F_82 ( & V_97 ) ;
}
bool F_83 ( void )
{
if ( F_84 ( & V_98 ) )
return false ;
V_95 = true ;
F_85 ( & V_98 ) ;
F_86 ( V_97 , ! F_87 ( & V_96 ) ) ;
return true ;
}
void F_88 ( void )
{
V_95 = false ;
}
static bool F_89 ( struct V_1 * V_7 , struct V_69 * V_9 )
{
struct V_1 * V_8 ;
F_3 (p, t) {
struct V_69 * V_99 = F_90 ( V_8 -> V_9 ) ;
if ( V_99 )
return V_99 == V_9 ;
}
return false ;
}
void F_91 ( struct V_11 * V_12 , struct V_1 * V_7 ,
unsigned int V_20 , unsigned long V_19 ,
struct V_14 * V_15 , const char * V_100 )
{
struct V_1 * V_101 = V_7 ;
struct V_1 * V_102 ;
struct V_1 * V_8 ;
struct V_69 * V_9 ;
unsigned int V_103 = 0 ;
static F_92 ( V_104 , V_105 ,
V_106 ) ;
bool V_107 = true ;
F_8 ( V_7 ) ;
if ( V_7 -> V_9 && F_93 ( V_7 ) ) {
F_75 ( V_7 ) ;
F_10 ( V_7 ) ;
F_62 ( V_7 ) ;
return;
}
F_10 ( V_7 ) ;
if ( F_94 ( & V_104 ) )
F_40 ( V_12 , V_7 , V_15 ) ;
F_73 ( L_8 ,
V_100 , F_54 ( V_7 ) , V_7 -> V_62 , V_20 ) ;
F_95 ( & V_108 ) ;
F_3 (p, t) {
F_96 (child, &t->children, sibling) {
unsigned int V_109 ;
if ( F_89 ( V_102 , V_7 -> V_9 ) )
continue;
V_109 = F_15 ( V_102 , V_15 , V_12 -> V_16 ,
V_19 ) ;
if ( V_109 > V_103 ) {
F_62 ( V_101 ) ;
V_101 = V_102 ;
V_103 = V_109 ;
F_34 ( V_101 ) ;
}
}
}
F_97 ( & V_108 ) ;
V_7 = F_7 ( V_101 ) ;
if ( ! V_7 ) {
F_62 ( V_101 ) ;
return;
} else if ( V_101 != V_7 ) {
F_34 ( V_7 ) ;
F_62 ( V_101 ) ;
V_101 = V_7 ;
}
V_9 = V_101 -> V_9 ;
F_79 ( & V_9 -> V_110 ) ;
F_98 ( V_111 , V_112 , V_101 , true ) ;
F_75 ( V_101 ) ;
F_73 ( L_9 ,
F_54 ( V_101 ) , V_101 -> V_62 , F_55 ( V_101 -> V_9 -> V_61 ) ,
F_55 ( F_17 ( V_101 -> V_9 , V_84 ) ) ,
F_55 ( F_17 ( V_101 -> V_9 , V_85 ) ) ,
F_55 ( F_17 ( V_101 -> V_9 , V_86 ) ) ) ;
F_10 ( V_101 ) ;
F_2 () ;
F_37 (p) {
if ( ! F_89 ( V_7 , V_9 ) )
continue;
if ( F_99 ( V_7 , V_101 ) )
continue;
if ( F_100 ( V_7 -> V_17 & V_18 ) || F_13 ( V_7 ) ||
V_7 -> signal -> V_22 == V_23 ) {
V_107 = false ;
continue;
}
F_98 ( V_111 , V_112 , V_7 , true ) ;
}
F_6 () ;
if ( V_107 )
F_68 ( V_101 ) ;
F_101 ( V_9 ) ;
F_62 ( V_101 ) ;
}
void F_102 ( struct V_11 * V_12 , enum V_27 V_113 ,
struct V_14 * V_15 )
{
if ( F_9 ( ! V_114 ) )
return;
if ( V_114 != 2 ) {
if ( V_113 != V_39 )
return;
}
if ( F_11 ( V_12 ) )
return;
F_40 ( V_12 , NULL , V_15 ) ;
F_103 ( L_10 ,
V_114 == 2 ? L_11 : L_12 ) ;
}
int F_104 ( struct V_115 * V_116 )
{
return F_105 ( & V_117 , V_116 ) ;
}
int F_106 ( struct V_115 * V_116 )
{
return F_107 ( & V_117 , V_116 ) ;
}
bool F_108 ( struct V_11 * V_12 )
{
struct V_1 * V_7 ;
unsigned long V_19 ;
unsigned long V_118 = 0 ;
unsigned int V_119 ( V_20 ) ;
enum V_27 V_113 = V_39 ;
if ( V_95 )
return false ;
F_109 ( & V_117 , 0 , & V_118 ) ;
if ( V_118 > 0 )
return true ;
if ( V_6 -> V_9 &&
( F_110 ( V_6 ) || F_93 ( V_6 ) ) ) {
F_75 ( V_6 ) ;
return true ;
}
V_113 = F_21 ( V_12 , & V_19 ) ;
if ( V_113 != V_43 )
V_12 -> V_16 = NULL ;
F_102 ( V_12 , V_113 , NULL ) ;
if ( V_120 && V_6 -> V_9 &&
! F_12 ( V_6 , NULL , V_12 -> V_16 ) &&
V_6 -> signal -> V_22 != V_23 ) {
F_34 ( V_6 ) ;
F_91 ( V_12 , V_6 , 0 , V_19 , NULL ,
L_13 ) ;
return true ;
}
V_7 = F_31 ( V_12 , & V_20 , V_19 ) ;
if ( ! V_7 && ! F_11 ( V_12 ) ) {
F_40 ( V_12 , NULL , NULL ) ;
F_103 ( L_14 ) ;
}
if ( V_7 && V_7 != ( void * ) - 1UL ) {
F_91 ( V_12 , V_7 , V_20 , V_19 , NULL ,
L_15 ) ;
F_111 ( 1 ) ;
}
return true ;
}
void F_112 ( void )
{
struct V_11 V_12 = {
. V_38 = NULL ,
. V_16 = NULL ,
. V_33 = 0 ,
. V_13 = 0 ,
} ;
if ( F_113 ( true ) )
return;
if ( ! F_114 ( & V_98 ) )
return;
if ( ! F_108 ( & V_12 ) ) {
F_76 ( F_115 ( V_49 ) ) ;
}
F_85 ( & V_98 ) ;
}
