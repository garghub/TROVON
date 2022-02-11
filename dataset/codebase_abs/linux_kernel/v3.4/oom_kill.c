void F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_5 -> signal -> V_7 == V_1 )
V_5 -> signal -> V_7 = V_2 ;
F_3 ( V_5 ) ;
F_4 ( & V_4 -> V_6 ) ;
}
int F_5 ( int V_2 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
int V_1 ;
F_2 ( & V_4 -> V_6 ) ;
V_1 = V_5 -> signal -> V_7 ;
V_5 -> signal -> V_7 = V_2 ;
F_3 ( V_5 ) ;
F_4 ( & V_4 -> V_6 ) ;
return V_1 ;
}
static bool F_6 ( struct V_8 * V_9 ,
const T_1 * V_10 )
{
struct V_8 * V_11 = V_9 ;
do {
if ( V_10 ) {
if ( F_7 ( V_9 , V_10 ) )
return true ;
} else {
if ( F_8 ( V_5 , V_9 ) )
return true ;
}
} while_each_thread(start, tsk) ;
bool F_6 ( struct V_8 * V_9 ,
const T_1 * V_10 )
{
return true ;
}
struct V_8 * F_9 ( struct V_8 * V_12 )
{
struct V_8 * V_13 = V_12 ;
do {
F_10 ( V_13 ) ;
if ( F_11 ( V_13 -> V_14 ) )
return V_13 ;
F_12 ( V_13 ) ;
} while_each_thread(p, t) ;
bool F_13 ( struct V_8 * V_12 ,
const struct V_15 * V_16 , const T_1 * V_17 )
{
if ( F_14 ( V_12 ) )
return true ;
if ( V_12 -> V_18 & V_19 )
return true ;
if ( V_16 && ! F_15 ( V_12 , V_16 ) )
return true ;
if ( ! F_6 ( V_12 , V_17 ) )
return true ;
return false ;
}
unsigned int F_16 ( struct V_8 * V_12 , struct V_15 * V_16 ,
const T_1 * V_17 , unsigned long V_20 )
{
long V_21 ;
if ( F_13 ( V_12 , V_16 , V_17 ) )
return 0 ;
V_12 = F_9 ( V_12 ) ;
if ( ! V_12 )
return 0 ;
if ( V_12 -> signal -> V_7 == V_22 ) {
F_12 ( V_12 ) ;
return 0 ;
}
if ( ! V_20 )
V_20 = 1 ;
V_21 = F_17 ( V_12 -> V_14 ) + V_12 -> V_14 -> V_23 ;
V_21 += F_18 ( V_12 -> V_14 , V_24 ) ;
V_21 *= 1000 ;
V_21 /= V_20 ;
F_12 ( V_12 ) ;
if ( F_19 ( V_12 , V_25 ) )
V_21 -= 30 ;
V_21 += V_12 -> signal -> V_7 ;
if ( V_21 <= 0 )
return 1 ;
return ( V_21 < 1000 ) ? V_21 : 1000 ;
}
static enum V_26 F_20 ( struct V_27 * V_27 ,
T_2 V_28 , T_1 * V_17 ,
unsigned long * V_20 )
{
struct V_29 * V_29 ;
struct V_30 * V_31 ;
enum V_32 V_33 = F_21 ( V_28 ) ;
bool V_34 = false ;
int V_35 ;
* V_20 = V_36 + V_37 ;
if ( ! V_27 )
return V_38 ;
if ( V_28 & V_39 )
return V_38 ;
if ( V_17 && ! F_22 ( V_40 [ V_41 ] , * V_17 ) ) {
* V_20 = V_37 ;
F_23 ( V_35 , * V_17 )
* V_20 += F_24 ( V_35 ) ;
return V_42 ;
}
F_25 (zone, z, zonelist,
high_zoneidx, nodemask)
if ( ! F_26 ( V_29 , V_28 ) )
V_34 = true ;
if ( V_34 ) {
* V_20 = V_37 ;
F_23 ( V_35 , V_43 )
* V_20 += F_24 ( V_35 ) ;
return V_44 ;
}
return V_38 ;
}
static enum V_26 F_20 ( struct V_27 * V_27 ,
T_2 V_28 , T_1 * V_17 ,
unsigned long * V_20 )
{
* V_20 = V_36 + V_37 ;
return V_38 ;
}
static struct V_8 * F_27 ( unsigned int * V_45 ,
unsigned long V_20 , struct V_15 * V_16 ,
const T_1 * V_17 , bool V_46 )
{
struct V_8 * V_47 , * V_12 ;
struct V_8 * V_48 = NULL ;
* V_45 = 0 ;
F_28 (g, p) {
unsigned int V_21 ;
if ( V_12 -> V_49 )
continue;
if ( F_13 ( V_12 , V_16 , V_17 ) )
continue;
if ( F_29 ( V_12 , V_50 ) ) {
if ( F_30 ( F_31 ( V_12 ) ) )
F_32 ( V_12 ) ;
if ( ! V_46 )
return F_33 ( - 1UL ) ;
}
if ( ! V_12 -> V_14 )
continue;
if ( V_12 -> V_18 & V_51 ) {
if ( V_12 == V_5 ) {
V_48 = V_12 ;
* V_45 = 1000 ;
} else if ( ! V_46 ) {
if ( ! ( V_12 -> V_52 -> V_53 & V_54 ) )
return F_33 ( - 1UL ) ;
}
}
V_21 = F_16 ( V_12 , V_16 , V_17 , V_20 ) ;
if ( V_21 > * V_45 ) {
V_48 = V_12 ;
* V_45 = V_21 ;
}
} F_34 ( V_47 , V_12 ) ;
return V_48 ;
}
static void F_35 ( const struct V_15 * V_16 , const T_1 * V_17 )
{
struct V_8 * V_12 ;
struct V_8 * V_55 ;
F_36 ( L_1 ) ;
F_37 (p) {
if ( F_13 ( V_12 , V_16 , V_17 ) )
continue;
V_55 = F_9 ( V_12 ) ;
if ( ! V_55 ) {
continue;
}
F_36 ( L_2 ,
V_55 -> V_56 , F_38 ( V_55 ) , V_55 -> V_57 ,
V_55 -> V_14 -> V_58 , F_17 ( V_55 -> V_14 ) ,
F_39 ( V_55 ) , V_55 -> signal -> V_59 ,
V_55 -> signal -> V_7 , V_55 -> V_60 ) ;
F_12 ( V_55 ) ;
}
}
static void F_40 ( struct V_8 * V_12 , T_2 V_28 , int V_61 ,
struct V_15 * V_16 , const T_1 * V_17 )
{
F_10 ( V_5 ) ;
F_41 ( L_3
L_4 ,
V_5 -> V_60 , V_28 , V_61 , V_5 -> signal -> V_59 ,
V_5 -> signal -> V_7 ) ;
F_42 ( V_5 ) ;
F_12 ( V_5 ) ;
F_43 () ;
F_44 ( V_16 , V_12 ) ;
F_45 ( V_62 ) ;
if ( V_63 )
F_35 ( V_16 , V_17 ) ;
}
static void F_46 ( struct V_8 * V_12 , T_2 V_28 , int V_61 ,
unsigned int V_21 , unsigned long V_20 ,
struct V_15 * V_16 , T_1 * V_17 ,
const char * V_64 )
{
struct V_8 * V_65 = V_12 ;
struct V_8 * V_66 ;
struct V_8 * V_13 = V_12 ;
struct V_67 * V_14 ;
unsigned int V_68 = 0 ;
static F_47 ( V_69 , V_70 ,
V_71 ) ;
if ( V_12 -> V_18 & V_51 ) {
F_48 ( V_12 , V_50 ) ;
return;
}
if ( F_49 ( & V_69 ) )
F_40 ( V_12 , V_28 , V_61 , V_16 , V_17 ) ;
F_10 ( V_12 ) ;
F_50 ( L_5 ,
V_64 , F_51 ( V_12 ) , V_12 -> V_60 , V_21 ) ;
F_12 ( V_12 ) ;
do {
F_52 (child, &t->children, sibling) {
unsigned int V_72 ;
if ( V_66 -> V_14 == V_12 -> V_14 )
continue;
V_72 = F_16 ( V_66 , V_16 , V_17 ,
V_20 ) ;
if ( V_72 > V_68 ) {
V_65 = V_66 ;
V_68 = V_72 ;
}
}
} while_each_thread(p, t) ;
void F_53 ( enum V_26 V_73 , T_2 V_28 ,
int V_61 , const T_1 * V_17 )
{
if ( F_11 ( ! V_74 ) )
return;
if ( V_74 != 2 ) {
if ( V_73 != V_38 )
return;
}
F_54 ( & V_75 ) ;
F_40 ( NULL , V_28 , V_61 , NULL , V_17 ) ;
F_55 ( & V_75 ) ;
F_56 ( L_6 ,
V_74 == 2 ? L_7 : L_8 ) ;
}
void F_57 ( struct V_15 * V_16 , T_2 V_28 ,
int V_61 )
{
unsigned long V_76 ;
unsigned int V_21 = 0 ;
struct V_8 * V_12 ;
if ( F_58 ( V_5 ) ) {
F_59 ( V_50 ) ;
return;
}
F_53 ( V_77 , V_28 , V_61 , NULL ) ;
V_76 = F_60 ( V_16 ) >> V_78 ;
F_54 ( & V_75 ) ;
V_12 = F_27 ( & V_21 , V_76 , V_16 , NULL , false ) ;
if ( V_12 && F_61 ( V_12 ) != - 1UL )
F_46 ( V_12 , V_28 , V_61 , V_21 , V_76 , V_16 , NULL ,
L_9 ) ;
F_55 ( & V_75 ) ;
}
int F_62 ( struct V_79 * V_80 )
{
return F_63 ( & V_81 , V_80 ) ;
}
int F_64 ( struct V_79 * V_80 )
{
return F_65 ( & V_81 , V_80 ) ;
}
int F_66 ( struct V_27 * V_27 , T_2 V_28 )
{
struct V_30 * V_31 ;
struct V_29 * V_29 ;
int V_82 = 1 ;
F_67 ( & V_83 ) ;
F_68 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_69 ( V_29 ) ) {
V_82 = 0 ;
goto V_84;
}
}
F_68 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_70 ( V_29 , V_85 ) ;
}
V_84:
F_71 ( & V_83 ) ;
return V_82 ;
}
void F_72 ( struct V_27 * V_27 , T_2 V_28 )
{
struct V_30 * V_31 ;
struct V_29 * V_29 ;
F_67 ( & V_83 ) ;
F_68 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_73 ( V_29 , V_85 ) ;
}
F_71 ( & V_83 ) ;
}
static int F_74 ( void )
{
struct V_29 * V_29 ;
int V_82 = 1 ;
F_67 ( & V_83 ) ;
F_75 (zone)
if ( F_69 ( V_29 ) ) {
V_82 = 0 ;
goto V_84;
}
F_75 (zone)
F_70 ( V_29 , V_85 ) ;
V_84:
F_71 ( & V_83 ) ;
return V_82 ;
}
static void F_76 ( void )
{
struct V_29 * V_29 ;
F_67 ( & V_83 ) ;
F_75 (zone)
F_73 ( V_29 , V_85 ) ;
F_71 ( & V_83 ) ;
}
void F_77 ( struct V_27 * V_27 , T_2 V_28 ,
int V_61 , T_1 * V_17 , bool V_46 )
{
const T_1 * V_86 ;
struct V_8 * V_12 ;
unsigned long V_20 ;
unsigned long V_87 = 0 ;
unsigned int V_21 ;
enum V_26 V_73 = V_38 ;
int V_88 = 0 ;
F_78 ( & V_81 , 0 , & V_87 ) ;
if ( V_87 > 0 )
return;
if ( F_58 ( V_5 ) ) {
F_59 ( V_50 ) ;
return;
}
V_73 = F_20 ( V_27 , V_28 , V_17 ,
& V_20 ) ;
V_86 = ( V_73 == V_42 ) ? V_17 : NULL ;
F_53 ( V_73 , V_28 , V_61 , V_86 ) ;
F_54 ( & V_75 ) ;
if ( V_89 &&
! F_13 ( V_5 , NULL , V_17 ) &&
V_5 -> V_14 ) {
F_46 ( V_5 , V_28 , V_61 , 0 , V_20 , NULL ,
V_17 ,
L_10 ) ;
goto V_84;
}
V_12 = F_27 ( & V_21 , V_20 , NULL , V_86 ,
V_46 ) ;
if ( ! V_12 ) {
F_40 ( NULL , V_28 , V_61 , NULL , V_86 ) ;
F_55 ( & V_75 ) ;
F_56 ( L_11 ) ;
}
if ( F_61 ( V_12 ) != - 1UL ) {
F_46 ( V_12 , V_28 , V_61 , V_21 , V_20 , NULL ,
V_17 , L_12 ) ;
V_88 = 1 ;
}
V_84:
F_55 ( & V_75 ) ;
if ( V_88 && ! F_79 ( V_50 ) )
F_80 ( 1 ) ;
}
void F_81 ( void )
{
if ( F_74 () ) {
F_77 ( NULL , 0 , 0 , NULL , false ) ;
F_76 () ;
}
if ( ! F_79 ( V_50 ) )
F_80 ( 1 ) ;
}
