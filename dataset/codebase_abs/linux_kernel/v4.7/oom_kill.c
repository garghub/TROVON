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
F_16 ( V_24 , & V_7 -> V_9 -> V_17 ) ) {
F_10 ( V_7 ) ;
return 0 ;
}
V_20 = F_17 ( V_7 -> V_9 ) + F_18 ( V_7 -> V_9 , V_25 ) +
F_19 ( & V_7 -> V_9 -> V_26 ) + F_20 ( V_7 -> V_9 ) ;
F_10 ( V_7 ) ;
if ( F_21 ( V_7 , V_27 ) )
V_20 -= ( V_20 * 3 ) / 100 ;
V_21 *= V_19 / 1000 ;
V_20 += V_21 ;
return V_20 > 0 ? V_20 : 1 ;
}
static enum V_28 F_22 ( struct V_11 * V_12 ,
unsigned long * V_19 )
{
struct V_29 * V_29 ;
struct V_30 * V_31 ;
enum V_32 V_33 = F_23 ( V_12 -> V_34 ) ;
bool V_35 = false ;
int V_36 ;
* V_19 = V_37 + V_38 ;
if ( ! V_12 -> V_39 )
return V_40 ;
if ( V_12 -> V_34 & V_41 )
return V_40 ;
if ( V_12 -> V_16 &&
! F_24 ( V_42 [ V_43 ] , * V_12 -> V_16 ) ) {
* V_19 = V_38 ;
F_25 ( V_36 , * V_12 -> V_16 )
* V_19 += F_26 ( V_36 ) ;
return V_44 ;
}
F_27 (zone, z, oc->zonelist,
high_zoneidx, oc->nodemask)
if ( ! F_28 ( V_29 , V_12 -> V_34 ) )
V_35 = true ;
if ( V_35 ) {
* V_19 = V_38 ;
F_25 ( V_36 , V_45 )
* V_19 += F_26 ( V_36 ) ;
return V_46 ;
}
return V_40 ;
}
static enum V_28 F_22 ( struct V_11 * V_12 ,
unsigned long * V_19 )
{
* V_19 = V_37 + V_38 ;
return V_40 ;
}
enum V_47 F_29 ( struct V_11 * V_12 ,
struct V_1 * V_48 , unsigned long V_19 )
{
if ( F_12 ( V_48 , NULL , V_12 -> V_16 ) )
return V_49 ;
if ( ! F_11 ( V_12 ) && F_30 ( & V_48 -> signal -> V_50 ) )
return V_51 ;
if ( F_31 ( V_48 ) )
return V_52 ;
return V_53 ;
}
static struct V_1 * F_32 ( struct V_11 * V_12 ,
unsigned int * V_54 , unsigned long V_19 )
{
struct V_1 * V_7 ;
struct V_1 * V_55 = NULL ;
unsigned long V_56 = 0 ;
F_2 () ;
F_33 (p) {
unsigned int V_20 ;
switch ( F_29 ( V_12 , V_7 , V_19 ) ) {
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
F_34 ( V_55 ) ;
F_6 () ;
* V_54 = V_56 * 1000 / V_19 ;
return V_55 ;
}
static void F_35 ( struct V_14 * V_15 , const T_1 * V_16 )
{
struct V_1 * V_7 ;
struct V_1 * V_48 ;
F_36 ( L_1 ) ;
F_2 () ;
F_33 (p) {
if ( F_12 ( V_7 , V_15 , V_16 ) )
continue;
V_48 = F_7 ( V_7 ) ;
if ( ! V_48 ) {
continue;
}
F_36 ( L_2 ,
V_48 -> V_58 , F_37 ( & V_59 , F_38 ( V_48 ) ) ,
V_48 -> V_60 , V_48 -> V_9 -> V_61 , F_17 ( V_48 -> V_9 ) ,
F_19 ( & V_48 -> V_9 -> V_26 ) ,
F_20 ( V_48 -> V_9 ) ,
F_18 ( V_48 -> V_9 , V_25 ) ,
V_48 -> signal -> V_22 , V_48 -> V_62 ) ;
F_10 ( V_48 ) ;
}
F_6 () ;
}
static void F_39 ( struct V_11 * V_12 , struct V_1 * V_7 ,
struct V_14 * V_15 )
{
F_40 ( L_3 ,
V_6 -> V_62 , V_12 -> V_34 , & V_12 -> V_34 , V_12 -> V_13 ,
V_6 -> signal -> V_22 ) ;
F_41 () ;
F_42 () ;
if ( V_15 )
F_43 ( V_15 , V_7 ) ;
else
F_44 ( V_63 ) ;
if ( V_64 )
F_35 ( V_15 , V_12 -> V_16 ) ;
}
static bool F_45 ( struct V_1 * V_7 , struct V_65 * V_9 )
{
struct V_1 * V_8 ;
F_3 (p, t) {
struct V_65 * V_66 = F_46 ( V_8 -> V_9 ) ;
if ( V_66 )
return V_66 == V_9 ;
}
return false ;
}
static bool F_47 ( struct V_1 * V_4 )
{
struct V_67 V_68 ;
struct V_69 * V_70 ;
struct V_65 * V_9 = NULL ;
struct V_1 * V_7 ;
struct V_71 V_72 = { . V_73 = true ,
. V_74 = true } ;
bool V_5 = true ;
F_48 ( & V_75 ) ;
V_7 = F_7 ( V_4 ) ;
if ( ! V_7 )
goto V_76;
V_9 = V_7 -> V_9 ;
F_49 ( & V_9 -> V_77 ) ;
F_10 ( V_7 ) ;
if ( ! F_50 ( & V_9 -> V_78 ) ) {
V_5 = false ;
goto V_76;
}
F_51 ( & V_68 , V_9 , 0 , - 1 ) ;
for ( V_70 = V_9 -> V_79 ; V_70 ; V_70 = V_70 -> V_80 ) {
if ( F_52 ( V_70 ) )
continue;
if ( V_70 -> V_81 & V_82 )
continue;
if ( F_53 ( V_70 ) || ! ( V_70 -> V_81 & V_83 ) )
F_54 ( & V_68 , V_70 , V_70 -> V_84 , V_70 -> V_85 ,
& V_72 ) ;
}
F_55 ( & V_68 , 0 , - 1 ) ;
F_36 ( L_4 ,
F_56 ( V_4 ) , V_4 -> V_62 ,
F_57 ( F_18 ( V_9 , V_86 ) ) ,
F_57 ( F_18 ( V_9 , V_87 ) ) ,
F_57 ( F_18 ( V_9 , V_88 ) ) ) ;
F_58 ( & V_9 -> V_78 ) ;
F_59 ( V_24 , & V_9 -> V_17 ) ;
V_76:
F_60 ( & V_75 ) ;
if ( V_9 )
F_61 ( V_9 ) ;
return V_5 ;
}
static void F_62 ( struct V_1 * V_4 )
{
int V_89 = 0 ;
while ( V_89 ++ < V_90 && ! F_47 ( V_4 ) )
F_63 ( V_91 / 10 ) ;
if ( V_89 > V_90 ) {
F_36 ( L_5 ,
F_56 ( V_4 ) , V_4 -> V_62 ) ;
F_64 () ;
}
V_4 -> V_92 = NULL ;
F_65 ( V_4 ) ;
F_66 ( V_4 ) ;
}
static int F_67 ( void * V_93 )
{
F_68 () ;
while ( true ) {
struct V_1 * V_4 = NULL ;
F_69 ( V_94 , V_92 != NULL ) ;
F_70 ( & V_95 ) ;
if ( V_92 != NULL ) {
V_4 = V_92 ;
V_92 = V_4 -> V_92 ;
}
F_71 ( & V_95 ) ;
if ( V_4 )
F_62 ( V_4 ) ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_4 )
{
if ( ! V_96 )
return;
if ( V_4 == V_92 || V_4 -> V_92 )
return;
F_34 ( V_4 ) ;
F_70 ( & V_95 ) ;
V_4 -> V_92 = V_92 ;
V_92 = V_4 ;
F_71 ( & V_95 ) ;
F_73 ( & V_94 ) ;
}
void F_74 ( struct V_1 * V_4 )
{
struct V_65 * V_9 = V_4 -> V_9 ;
struct V_1 * V_7 ;
if ( ! V_9 )
return;
if ( F_30 ( & V_9 -> V_77 ) > 1 ) {
F_2 () ;
F_33 (p) {
if ( ! F_45 ( V_7 , V_9 ) )
continue;
if ( F_75 ( V_7 ) )
continue;
if ( F_76 ( V_7 -> signal ) )
continue;
F_6 () ;
return;
}
F_6 () ;
}
F_72 ( V_4 ) ;
}
static int T_2 F_77 ( void )
{
V_96 = F_78 ( F_67 , NULL , L_6 ) ;
if ( F_79 ( V_96 ) ) {
F_80 ( L_7 ,
F_81 ( V_96 ) ) ;
V_96 = NULL ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_4 )
{
}
void F_82 ( struct V_1 * V_4 )
{
F_83 ( V_97 ) ;
if ( F_84 ( V_4 , V_98 ) )
return;
F_49 ( & V_4 -> signal -> V_50 ) ;
F_85 ( V_4 ) ;
F_49 ( & V_50 ) ;
}
void F_65 ( struct V_1 * V_4 )
{
if ( ! F_86 ( V_4 , V_98 ) )
return;
F_87 ( & V_4 -> signal -> V_50 ) ;
if ( ! F_88 ( & V_50 ) )
F_89 ( & V_99 ) ;
}
bool F_90 ( void )
{
if ( F_91 ( & V_75 ) )
return false ;
V_97 = true ;
F_60 ( & V_75 ) ;
F_92 ( V_99 , ! F_30 ( & V_50 ) ) ;
return true ;
}
void F_93 ( void )
{
V_97 = false ;
}
void F_94 ( struct V_11 * V_12 , struct V_1 * V_7 ,
unsigned int V_20 , unsigned long V_19 ,
struct V_14 * V_15 , const char * V_100 )
{
struct V_1 * V_101 = V_7 ;
struct V_1 * V_102 ;
struct V_1 * V_8 ;
struct V_65 * V_9 ;
unsigned int V_103 = 0 ;
static F_95 ( V_104 , V_105 ,
V_106 ) ;
bool V_107 = true ;
F_8 ( V_7 ) ;
if ( V_7 -> V_9 && F_96 ( V_7 ) ) {
F_82 ( V_7 ) ;
F_74 ( V_7 ) ;
F_10 ( V_7 ) ;
F_66 ( V_7 ) ;
return;
}
F_10 ( V_7 ) ;
if ( F_97 ( & V_104 ) )
F_39 ( V_12 , V_7 , V_15 ) ;
F_80 ( L_8 ,
V_100 , F_56 ( V_7 ) , V_7 -> V_62 , V_20 ) ;
F_98 ( & V_108 ) ;
F_3 (p, t) {
F_99 (child, &t->children, sibling) {
unsigned int V_109 ;
if ( F_45 ( V_102 , V_7 -> V_9 ) )
continue;
V_109 = F_15 ( V_102 , V_15 , V_12 -> V_16 ,
V_19 ) ;
if ( V_109 > V_103 ) {
F_66 ( V_101 ) ;
V_101 = V_102 ;
V_103 = V_109 ;
F_34 ( V_101 ) ;
}
}
}
F_100 ( & V_108 ) ;
V_7 = F_7 ( V_101 ) ;
if ( ! V_7 ) {
F_66 ( V_101 ) ;
return;
} else if ( V_101 != V_7 ) {
F_34 ( V_7 ) ;
F_66 ( V_101 ) ;
V_101 = V_7 ;
}
V_9 = V_101 -> V_9 ;
F_49 ( & V_9 -> V_110 ) ;
F_101 ( V_111 , V_112 , V_101 , true ) ;
F_82 ( V_101 ) ;
F_80 ( L_9 ,
F_56 ( V_101 ) , V_101 -> V_62 , F_57 ( V_101 -> V_9 -> V_61 ) ,
F_57 ( F_18 ( V_101 -> V_9 , V_86 ) ) ,
F_57 ( F_18 ( V_101 -> V_9 , V_87 ) ) ,
F_57 ( F_18 ( V_101 -> V_9 , V_88 ) ) ) ;
F_10 ( V_101 ) ;
F_2 () ;
F_33 (p) {
if ( ! F_45 ( V_7 , V_9 ) )
continue;
if ( F_102 ( V_7 , V_101 ) )
continue;
if ( F_103 ( V_7 -> V_17 & V_18 ) || F_13 ( V_7 ) ||
V_7 -> signal -> V_22 == V_23 ) {
V_107 = false ;
continue;
}
F_101 ( V_111 , V_112 , V_7 , true ) ;
}
F_6 () ;
if ( V_107 )
F_72 ( V_101 ) ;
F_104 ( V_9 ) ;
F_66 ( V_101 ) ;
}
void F_105 ( struct V_11 * V_12 , enum V_28 V_113 ,
struct V_14 * V_15 )
{
if ( F_9 ( ! V_114 ) )
return;
if ( V_114 != 2 ) {
if ( V_113 != V_40 )
return;
}
if ( F_11 ( V_12 ) )
return;
F_39 ( V_12 , NULL , V_15 ) ;
F_106 ( L_10 ,
V_114 == 2 ? L_11 : L_12 ) ;
}
int F_107 ( struct V_115 * V_116 )
{
return F_108 ( & V_117 , V_116 ) ;
}
int F_109 ( struct V_115 * V_116 )
{
return F_110 ( & V_117 , V_116 ) ;
}
bool F_111 ( struct V_11 * V_12 )
{
struct V_1 * V_7 ;
unsigned long V_19 ;
unsigned long V_118 = 0 ;
unsigned int V_119 ( V_20 ) ;
enum V_28 V_113 = V_40 ;
if ( V_97 )
return false ;
F_112 ( & V_117 , 0 , & V_118 ) ;
if ( V_118 > 0 )
return true ;
if ( V_6 -> V_9 &&
( F_75 ( V_6 ) || F_96 ( V_6 ) ) ) {
F_82 ( V_6 ) ;
F_74 ( V_6 ) ;
return true ;
}
if ( V_12 -> V_34 && ! ( V_12 -> V_34 & ( V_120 | V_121 ) ) )
return true ;
V_113 = F_22 ( V_12 , & V_19 ) ;
if ( V_113 != V_44 )
V_12 -> V_16 = NULL ;
F_105 ( V_12 , V_113 , NULL ) ;
if ( V_122 && V_6 -> V_9 &&
! F_12 ( V_6 , NULL , V_12 -> V_16 ) &&
V_6 -> signal -> V_22 != V_23 ) {
F_34 ( V_6 ) ;
F_94 ( V_12 , V_6 , 0 , V_19 , NULL ,
L_13 ) ;
return true ;
}
V_7 = F_32 ( V_12 , & V_20 , V_19 ) ;
if ( ! V_7 && ! F_11 ( V_12 ) ) {
F_39 ( V_12 , NULL , NULL ) ;
F_106 ( L_14 ) ;
}
if ( V_7 && V_7 != ( void * ) - 1UL ) {
F_94 ( V_12 , V_7 , V_20 , V_19 , NULL ,
L_15 ) ;
F_113 ( 1 ) ;
}
return true ;
}
void F_114 ( void )
{
struct V_11 V_12 = {
. V_39 = NULL ,
. V_16 = NULL ,
. V_34 = 0 ,
. V_13 = 0 ,
} ;
if ( F_115 ( true ) )
return;
if ( ! F_116 ( & V_75 ) )
return;
if ( ! F_111 ( & V_12 ) ) {
F_83 ( F_117 ( V_98 ) ) ;
}
F_60 ( & V_75 ) ;
}
