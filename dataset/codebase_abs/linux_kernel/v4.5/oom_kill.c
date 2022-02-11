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
if ( F_31 ( V_47 ) && ! F_11 ( V_12 ) )
return V_50 ;
return V_52 ;
}
static struct V_1 * F_32 ( struct V_11 * V_12 ,
unsigned int * V_53 , unsigned long V_19 )
{
struct V_1 * V_54 , * V_7 ;
struct V_1 * V_55 = NULL ;
unsigned long V_56 = 0 ;
F_2 () ;
F_33 (g, p) {
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
if ( V_20 == V_56 && F_34 ( V_55 ) )
continue;
V_55 = V_7 ;
V_56 = V_20 ;
}
if ( V_55 )
F_35 ( V_55 ) ;
F_6 () ;
* V_53 = V_56 * 1000 / V_19 ;
return V_55 ;
}
static void F_36 ( struct V_14 * V_15 , const T_1 * V_16 )
{
struct V_1 * V_7 ;
struct V_1 * V_47 ;
F_37 ( L_1 ) ;
F_2 () ;
F_38 (p) {
if ( F_12 ( V_7 , V_15 , V_16 ) )
continue;
V_47 = F_7 ( V_7 ) ;
if ( ! V_47 ) {
continue;
}
F_37 ( L_2 ,
V_47 -> V_58 , F_39 ( & V_59 , F_40 ( V_47 ) ) ,
V_47 -> V_60 , V_47 -> V_9 -> V_61 , F_16 ( V_47 -> V_9 ) ,
F_18 ( & V_47 -> V_9 -> V_25 ) ,
F_19 ( V_47 -> V_9 ) ,
F_17 ( V_47 -> V_9 , V_24 ) ,
V_47 -> signal -> V_22 , V_47 -> V_62 ) ;
F_10 ( V_47 ) ;
}
F_6 () ;
}
static void F_41 ( struct V_11 * V_12 , struct V_1 * V_7 ,
struct V_14 * V_15 )
{
F_42 ( L_3
L_4 ,
V_6 -> V_62 , V_12 -> V_33 , V_12 -> V_13 ,
V_6 -> signal -> V_22 ) ;
F_43 () ;
F_44 () ;
if ( V_15 )
F_45 ( V_15 , V_7 ) ;
else
F_46 ( V_63 ) ;
if ( V_64 )
F_36 ( V_15 , V_12 -> V_16 ) ;
}
void F_47 ( struct V_1 * V_4 )
{
F_48 ( V_65 ) ;
if ( F_49 ( V_4 , V_49 ) )
return;
F_50 ( V_4 ) ;
F_51 ( & V_66 ) ;
}
void F_52 ( void )
{
F_53 ( V_49 ) ;
if ( ! F_54 ( & V_66 ) )
F_55 ( & V_67 ) ;
}
bool F_56 ( void )
{
F_57 ( & V_68 ) ;
if ( F_58 ( V_49 ) ) {
F_59 ( & V_68 ) ;
return false ;
}
V_65 = true ;
F_59 ( & V_68 ) ;
F_60 ( V_67 , ! F_61 ( & V_66 ) ) ;
return true ;
}
void F_62 ( void )
{
V_65 = false ;
}
static bool F_63 ( struct V_1 * V_7 , struct V_69 * V_9 )
{
struct V_1 * V_8 ;
F_3 (p, t) {
struct V_69 * V_70 = F_64 ( V_8 -> V_9 ) ;
if ( V_70 )
return V_70 == V_9 ;
}
return false ;
}
void F_65 ( struct V_11 * V_12 , struct V_1 * V_7 ,
unsigned int V_20 , unsigned long V_19 ,
struct V_14 * V_15 , const char * V_71 )
{
struct V_1 * V_72 = V_7 ;
struct V_1 * V_73 ;
struct V_1 * V_8 ;
struct V_69 * V_9 ;
unsigned int V_74 = 0 ;
static F_66 ( V_75 , V_76 ,
V_77 ) ;
F_8 ( V_7 ) ;
if ( V_7 -> V_9 && F_31 ( V_7 ) ) {
F_47 ( V_7 ) ;
F_10 ( V_7 ) ;
F_67 ( V_7 ) ;
return;
}
F_10 ( V_7 ) ;
if ( F_68 ( & V_75 ) )
F_41 ( V_12 , V_7 , V_15 ) ;
F_69 ( L_5 ,
V_71 , F_70 ( V_7 ) , V_7 -> V_62 , V_20 ) ;
F_71 ( & V_78 ) ;
F_3 (p, t) {
F_72 (child, &t->children, sibling) {
unsigned int V_79 ;
if ( F_63 ( V_73 , V_7 -> V_9 ) )
continue;
V_79 = F_15 ( V_73 , V_15 , V_12 -> V_16 ,
V_19 ) ;
if ( V_79 > V_74 ) {
F_67 ( V_72 ) ;
V_72 = V_73 ;
V_74 = V_79 ;
F_35 ( V_72 ) ;
}
}
}
F_73 ( & V_78 ) ;
V_7 = F_7 ( V_72 ) ;
if ( ! V_7 ) {
F_67 ( V_72 ) ;
return;
} else if ( V_72 != V_7 ) {
F_35 ( V_7 ) ;
F_67 ( V_72 ) ;
V_72 = V_7 ;
}
V_9 = V_72 -> V_9 ;
F_51 ( & V_9 -> V_80 ) ;
F_74 ( V_81 , V_82 , V_72 , true ) ;
F_47 ( V_72 ) ;
F_69 ( L_6 ,
F_70 ( V_72 ) , V_72 -> V_62 , F_75 ( V_72 -> V_9 -> V_61 ) ,
F_75 ( F_17 ( V_72 -> V_9 , V_83 ) ) ,
F_75 ( F_17 ( V_72 -> V_9 , V_84 ) ) ,
F_75 ( F_17 ( V_72 -> V_9 , V_85 ) ) ) ;
F_10 ( V_72 ) ;
F_2 () ;
F_38 (p) {
if ( ! F_63 ( V_7 , V_9 ) )
continue;
if ( F_76 ( V_7 , V_72 ) )
continue;
if ( F_77 ( V_7 -> V_17 & V_18 ) )
continue;
if ( F_13 ( V_7 ) )
continue;
if ( V_7 -> signal -> V_22 == V_23 )
continue;
F_74 ( V_81 , V_82 , V_7 , true ) ;
}
F_6 () ;
F_78 ( V_9 ) ;
F_67 ( V_72 ) ;
}
void F_79 ( struct V_11 * V_12 , enum V_27 V_86 ,
struct V_14 * V_15 )
{
if ( F_9 ( ! V_87 ) )
return;
if ( V_87 != 2 ) {
if ( V_86 != V_39 )
return;
}
if ( F_11 ( V_12 ) )
return;
F_41 ( V_12 , NULL , V_15 ) ;
F_80 ( L_7 ,
V_87 == 2 ? L_8 : L_9 ) ;
}
int F_81 ( struct V_88 * V_89 )
{
return F_82 ( & V_90 , V_89 ) ;
}
int F_83 ( struct V_88 * V_89 )
{
return F_84 ( & V_90 , V_89 ) ;
}
bool F_85 ( struct V_11 * V_12 )
{
struct V_1 * V_7 ;
unsigned long V_19 ;
unsigned long V_91 = 0 ;
unsigned int V_92 ( V_20 ) ;
enum V_27 V_86 = V_39 ;
if ( V_65 )
return false ;
F_86 ( & V_90 , 0 , & V_91 ) ;
if ( V_91 > 0 )
return true ;
if ( V_6 -> V_9 &&
( F_87 ( V_6 ) || F_31 ( V_6 ) ) ) {
F_47 ( V_6 ) ;
return true ;
}
V_86 = F_21 ( V_12 , & V_19 ) ;
if ( V_86 != V_43 )
V_12 -> V_16 = NULL ;
F_79 ( V_12 , V_86 , NULL ) ;
if ( V_93 && V_6 -> V_9 &&
! F_12 ( V_6 , NULL , V_12 -> V_16 ) &&
V_6 -> signal -> V_22 != V_23 ) {
F_35 ( V_6 ) ;
F_65 ( V_12 , V_6 , 0 , V_19 , NULL ,
L_10 ) ;
return true ;
}
V_7 = F_32 ( V_12 , & V_20 , V_19 ) ;
if ( ! V_7 && ! F_11 ( V_12 ) ) {
F_41 ( V_12 , NULL , NULL ) ;
F_80 ( L_11 ) ;
}
if ( V_7 && V_7 != ( void * ) - 1UL ) {
F_65 ( V_12 , V_7 , V_20 , V_19 , NULL ,
L_12 ) ;
F_88 ( 1 ) ;
}
return true ;
}
void F_89 ( void )
{
struct V_11 V_12 = {
. V_38 = NULL ,
. V_16 = NULL ,
. V_33 = 0 ,
. V_13 = 0 ,
} ;
if ( F_90 ( true ) )
return;
if ( ! F_91 ( & V_68 ) )
return;
if ( ! F_85 ( & V_12 ) ) {
F_48 ( F_58 ( V_49 ) ) ;
}
F_59 ( & V_68 ) ;
}
