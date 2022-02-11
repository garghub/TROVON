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
static bool F_11 ( struct V_1 * V_7 ,
struct V_11 * V_12 , const T_1 * V_13 )
{
if ( F_12 ( V_7 ) )
return true ;
if ( V_7 -> V_14 & V_15 )
return true ;
if ( V_12 && ! F_13 ( V_7 , V_12 ) )
return true ;
if ( ! F_1 ( V_7 , V_13 ) )
return true ;
return false ;
}
unsigned long F_14 ( struct V_1 * V_7 , struct V_11 * V_12 ,
const T_1 * V_13 , unsigned long V_16 )
{
long V_17 ;
long V_18 ;
if ( F_11 ( V_7 , V_12 , V_13 ) )
return 0 ;
V_7 = F_7 ( V_7 ) ;
if ( ! V_7 )
return 0 ;
V_18 = ( long ) V_7 -> signal -> V_19 ;
if ( V_18 == V_20 ) {
F_10 ( V_7 ) ;
return 0 ;
}
V_17 = F_15 ( V_7 -> V_9 ) + F_16 ( V_7 -> V_9 , V_21 ) +
F_17 ( & V_7 -> V_9 -> V_22 ) + F_18 ( V_7 -> V_9 ) ;
F_10 ( V_7 ) ;
if ( F_19 ( V_7 , V_23 ) )
V_17 -= ( V_17 * 3 ) / 100 ;
V_18 *= V_16 / 1000 ;
V_17 += V_18 ;
return V_17 > 0 ? V_17 : 1 ;
}
static enum V_24 F_20 ( struct V_25 * V_26 ,
unsigned long * V_16 )
{
struct V_27 * V_27 ;
struct V_28 * V_29 ;
enum V_30 V_31 = F_21 ( V_26 -> V_32 ) ;
bool V_33 = false ;
int V_34 ;
* V_16 = V_35 + V_36 ;
if ( ! V_26 -> V_37 )
return V_38 ;
if ( V_26 -> V_32 & V_39 )
return V_38 ;
if ( V_26 -> V_13 &&
! F_22 ( V_40 [ V_41 ] , * V_26 -> V_13 ) ) {
* V_16 = V_36 ;
F_23 ( V_34 , * V_26 -> V_13 )
* V_16 += F_24 ( V_34 ) ;
return V_42 ;
}
F_25 (zone, z, oc->zonelist,
high_zoneidx, oc->nodemask)
if ( ! F_26 ( V_27 , V_26 -> V_32 ) )
V_33 = true ;
if ( V_33 ) {
* V_16 = V_36 ;
F_23 ( V_34 , V_43 )
* V_16 += F_24 ( V_34 ) ;
return V_44 ;
}
return V_38 ;
}
static enum V_24 F_20 ( struct V_25 * V_26 ,
unsigned long * V_16 )
{
* V_16 = V_35 + V_36 ;
return V_38 ;
}
enum V_45 F_27 ( struct V_25 * V_26 ,
struct V_1 * V_46 , unsigned long V_16 )
{
if ( F_11 ( V_46 , NULL , V_26 -> V_13 ) )
return V_47 ;
if ( F_28 ( V_46 , V_48 ) ) {
if ( V_26 -> V_49 != - 1 )
return V_50 ;
}
if ( ! V_46 -> V_9 )
return V_47 ;
if ( F_29 ( V_46 ) )
return V_51 ;
if ( F_30 ( V_46 ) && V_26 -> V_49 != - 1 )
return V_50 ;
return V_52 ;
}
static struct V_1 * F_31 ( struct V_25 * V_26 ,
unsigned int * V_53 , unsigned long V_16 )
{
struct V_1 * V_54 , * V_7 ;
struct V_1 * V_55 = NULL ;
unsigned long V_56 = 0 ;
F_2 () ;
F_32 (g, p) {
unsigned int V_17 ;
switch ( F_27 ( V_26 , V_7 , V_16 ) ) {
case V_51 :
V_55 = V_7 ;
V_56 = V_57 ;
case V_47 :
continue;
case V_50 :
F_6 () ;
return (struct V_1 * ) ( - 1UL ) ;
case V_52 :
break;
} ;
V_17 = F_14 ( V_7 , NULL , V_26 -> V_13 , V_16 ) ;
if ( ! V_17 || V_17 < V_56 )
continue;
if ( V_17 == V_56 && F_33 ( V_55 ) )
continue;
V_55 = V_7 ;
V_56 = V_17 ;
}
if ( V_55 )
F_34 ( V_55 ) ;
F_6 () ;
* V_53 = V_56 * 1000 / V_16 ;
return V_55 ;
}
static void F_35 ( struct V_11 * V_12 , const T_1 * V_13 )
{
struct V_1 * V_7 ;
struct V_1 * V_46 ;
F_36 ( L_1 ) ;
F_2 () ;
F_37 (p) {
if ( F_11 ( V_7 , V_12 , V_13 ) )
continue;
V_46 = F_7 ( V_7 ) ;
if ( ! V_46 ) {
continue;
}
F_36 ( L_2 ,
V_46 -> V_58 , F_38 ( & V_59 , F_39 ( V_46 ) ) ,
V_46 -> V_60 , V_46 -> V_9 -> V_61 , F_15 ( V_46 -> V_9 ) ,
F_17 ( & V_46 -> V_9 -> V_22 ) ,
F_18 ( V_46 -> V_9 ) ,
F_16 ( V_46 -> V_9 , V_21 ) ,
V_46 -> signal -> V_19 , V_46 -> V_62 ) ;
F_10 ( V_46 ) ;
}
F_6 () ;
}
static void F_40 ( struct V_25 * V_26 , struct V_1 * V_7 ,
struct V_11 * V_12 )
{
F_8 ( V_6 ) ;
F_41 ( L_3
L_4 ,
V_6 -> V_62 , V_26 -> V_32 , V_26 -> V_49 ,
V_6 -> signal -> V_19 ) ;
F_42 ( V_6 ) ;
F_10 ( V_6 ) ;
F_43 () ;
if ( V_12 )
F_44 ( V_12 , V_7 ) ;
else
F_45 ( V_63 ) ;
if ( V_64 )
F_35 ( V_12 , V_26 -> V_13 ) ;
}
void F_46 ( struct V_1 * V_4 )
{
F_47 ( V_65 ) ;
if ( F_48 ( V_4 , V_48 ) )
return;
F_49 ( V_4 ) ;
F_50 ( & V_66 ) ;
}
void F_51 ( void )
{
F_52 ( V_48 ) ;
if ( ! F_53 ( & V_66 ) )
F_54 ( & V_67 ) ;
}
bool F_55 ( void )
{
F_56 ( & V_68 ) ;
if ( F_57 ( V_48 ) ) {
F_58 ( & V_68 ) ;
return false ;
}
V_65 = true ;
F_58 ( & V_68 ) ;
F_59 ( V_67 , ! F_60 ( & V_66 ) ) ;
return true ;
}
void F_61 ( void )
{
V_65 = false ;
}
void F_62 ( struct V_25 * V_26 , struct V_1 * V_7 ,
unsigned int V_17 , unsigned long V_16 ,
struct V_11 * V_12 , const char * V_69 )
{
struct V_1 * V_70 = V_7 ;
struct V_1 * V_71 ;
struct V_1 * V_8 ;
struct V_72 * V_9 ;
unsigned int V_73 = 0 ;
static F_63 ( V_74 , V_75 ,
V_76 ) ;
F_8 ( V_7 ) ;
if ( V_7 -> V_9 && F_30 ( V_7 ) ) {
F_46 ( V_7 ) ;
F_10 ( V_7 ) ;
F_64 ( V_7 ) ;
return;
}
F_10 ( V_7 ) ;
if ( F_65 ( & V_74 ) )
F_40 ( V_26 , V_7 , V_12 ) ;
F_8 ( V_7 ) ;
F_66 ( L_5 ,
V_69 , F_67 ( V_7 ) , V_7 -> V_62 , V_17 ) ;
F_10 ( V_7 ) ;
F_68 ( & V_77 ) ;
F_3 (p, t) {
F_69 (child, &t->children, sibling) {
unsigned int V_78 ;
if ( V_71 -> V_9 == V_7 -> V_9 )
continue;
V_78 = F_14 ( V_71 , V_12 , V_26 -> V_13 ,
V_16 ) ;
if ( V_78 > V_73 ) {
F_64 ( V_70 ) ;
V_70 = V_71 ;
V_73 = V_78 ;
F_34 ( V_70 ) ;
}
}
}
F_70 ( & V_77 ) ;
V_7 = F_7 ( V_70 ) ;
if ( ! V_7 ) {
F_64 ( V_70 ) ;
return;
} else if ( V_70 != V_7 ) {
F_34 ( V_7 ) ;
F_64 ( V_70 ) ;
V_70 = V_7 ;
}
V_9 = V_70 -> V_9 ;
F_46 ( V_70 ) ;
F_66 ( L_6 ,
F_67 ( V_70 ) , V_70 -> V_62 , F_71 ( V_70 -> V_9 -> V_61 ) ,
F_71 ( F_16 ( V_70 -> V_9 , V_79 ) ) ,
F_71 ( F_16 ( V_70 -> V_9 , V_80 ) ) ) ;
F_10 ( V_70 ) ;
F_2 () ;
F_37 (p)
if ( V_7 -> V_9 == V_9 && ! F_72 ( V_7 , V_70 ) &&
! ( V_7 -> V_14 & V_15 ) ) {
if ( V_7 -> signal -> V_19 == V_20 )
continue;
F_8 ( V_7 ) ;
F_66 ( L_7 ,
F_67 ( V_7 ) , V_7 -> V_62 ) ;
F_10 ( V_7 ) ;
F_73 ( V_81 , V_82 , V_7 , true ) ;
}
F_6 () ;
F_73 ( V_81 , V_82 , V_70 , true ) ;
F_64 ( V_70 ) ;
}
void F_74 ( struct V_25 * V_26 , enum V_24 V_83 ,
struct V_11 * V_12 )
{
if ( F_9 ( ! V_84 ) )
return;
if ( V_84 != 2 ) {
if ( V_83 != V_38 )
return;
}
if ( V_26 -> V_49 == - 1 )
return;
F_40 ( V_26 , NULL , V_12 ) ;
F_75 ( L_8 ,
V_84 == 2 ? L_9 : L_10 ) ;
}
int F_76 ( struct V_85 * V_86 )
{
return F_77 ( & V_87 , V_86 ) ;
}
int F_78 ( struct V_85 * V_86 )
{
return F_79 ( & V_87 , V_86 ) ;
}
bool F_80 ( struct V_25 * V_26 )
{
struct V_1 * V_7 ;
unsigned long V_16 ;
unsigned long V_88 = 0 ;
unsigned int V_89 ( V_17 ) ;
enum V_24 V_83 = V_38 ;
if ( V_65 )
return false ;
F_81 ( & V_87 , 0 , & V_88 ) ;
if ( V_88 > 0 )
return true ;
if ( V_6 -> V_9 &&
( F_82 ( V_6 ) || F_30 ( V_6 ) ) ) {
F_46 ( V_6 ) ;
return true ;
}
V_83 = F_20 ( V_26 , & V_16 ) ;
if ( V_83 != V_42 )
V_26 -> V_13 = NULL ;
F_74 ( V_26 , V_83 , NULL ) ;
if ( V_90 && V_6 -> V_9 &&
! F_11 ( V_6 , NULL , V_26 -> V_13 ) &&
V_6 -> signal -> V_19 != V_20 ) {
F_34 ( V_6 ) ;
F_62 ( V_26 , V_6 , 0 , V_16 , NULL ,
L_11 ) ;
return true ;
}
V_7 = F_31 ( V_26 , & V_17 , V_16 ) ;
if ( ! V_7 && V_26 -> V_49 != - 1 ) {
F_40 ( V_26 , NULL , NULL ) ;
F_75 ( L_12 ) ;
}
if ( V_7 && V_7 != ( void * ) - 1UL ) {
F_62 ( V_26 , V_7 , V_17 , V_16 , NULL ,
L_13 ) ;
F_83 ( 1 ) ;
}
return true ;
}
void F_84 ( void )
{
struct V_25 V_26 = {
. V_37 = NULL ,
. V_13 = NULL ,
. V_32 = 0 ,
. V_49 = 0 ,
} ;
if ( F_85 ( true ) )
return;
if ( ! F_86 ( & V_68 ) )
return;
if ( ! F_80 ( & V_26 ) ) {
F_47 ( F_57 ( V_48 ) ) ;
}
F_58 ( & V_68 ) ;
}
