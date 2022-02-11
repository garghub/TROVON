int F_1 ( int V_1 )
{
struct V_2 * V_3 = V_4 -> V_3 ;
int V_5 ;
F_2 ( & V_3 -> V_6 ) ;
V_5 = V_4 -> signal -> V_7 ;
if ( V_1 != V_5 ) {
if ( V_1 == V_8 )
F_3 ( & V_4 -> V_9 -> V_10 ) ;
else if ( V_5 == V_8 )
F_4 ( & V_4 -> V_9 -> V_10 ) ;
V_4 -> signal -> V_7 = V_1 ;
}
F_5 ( & V_3 -> V_6 ) ;
return V_5 ;
}
static bool F_6 ( struct V_11 * V_12 ,
const T_1 * V_13 )
{
struct V_11 * V_14 = V_12 ;
do {
if ( V_13 ) {
if ( F_7 ( V_12 , V_13 ) )
return true ;
} else {
if ( F_8 ( V_4 , V_12 ) )
return true ;
}
} while_each_thread(start, tsk) ;
bool F_6 ( struct V_11 * V_12 ,
const T_1 * V_13 )
{
return true ;
}
struct V_11 * F_9 ( struct V_11 * V_15 )
{
struct V_11 * V_16 = V_15 ;
do {
F_10 ( V_16 ) ;
if ( F_11 ( V_16 -> V_9 ) )
return V_16 ;
F_12 ( V_16 ) ;
} while_each_thread(p, t) ;
bool F_13 ( struct V_11 * V_15 ,
const struct V_17 * V_18 , const T_1 * V_19 )
{
if ( F_14 ( V_15 ) )
return true ;
if ( V_15 -> V_20 & V_21 )
return true ;
if ( V_18 && ! F_15 ( V_15 , V_18 ) )
return true ;
if ( ! F_6 ( V_15 , V_19 ) )
return true ;
return false ;
}
unsigned int F_16 ( struct V_11 * V_15 , struct V_17 * V_18 ,
const T_1 * V_19 , unsigned long V_22 )
{
int V_23 ;
if ( F_13 ( V_15 , V_18 , V_19 ) )
return 0 ;
V_15 = F_9 ( V_15 ) ;
if ( ! V_15 )
return 0 ;
if ( F_17 ( & V_15 -> V_9 -> V_10 ) ) {
F_12 ( V_15 ) ;
return 0 ;
}
if ( ! V_22 )
V_22 = 1 ;
V_23 = F_18 ( V_15 -> V_9 ) + V_15 -> V_9 -> V_24 ;
V_23 += F_19 ( V_15 -> V_9 , V_25 ) ;
V_23 *= 1000 ;
V_23 /= V_22 ;
F_12 ( V_15 ) ;
if ( F_20 ( V_15 , V_26 ) )
V_23 -= 30 ;
V_23 += V_15 -> signal -> V_7 ;
if ( V_23 <= 0 )
return 1 ;
return ( V_23 < 1000 ) ? V_23 : 1000 ;
}
static enum V_27 F_21 ( struct V_28 * V_28 ,
T_2 V_29 , T_1 * V_19 ,
unsigned long * V_22 )
{
struct V_30 * V_30 ;
struct V_31 * V_32 ;
enum V_33 V_34 = F_22 ( V_29 ) ;
bool V_35 = false ;
int V_36 ;
* V_22 = V_37 + V_38 ;
if ( ! V_28 )
return V_39 ;
if ( V_29 & V_40 )
return V_39 ;
if ( V_19 && ! F_23 ( V_41 [ V_42 ] , * V_19 ) ) {
* V_22 = V_38 ;
F_24 ( V_36 , * V_19 )
* V_22 += F_25 ( V_36 ) ;
return V_43 ;
}
F_26 (zone, z, zonelist,
high_zoneidx, nodemask)
if ( ! F_27 ( V_30 , V_29 ) )
V_35 = true ;
if ( V_35 ) {
* V_22 = V_38 ;
F_24 ( V_36 , V_44 )
* V_22 += F_25 ( V_36 ) ;
return V_45 ;
}
return V_39 ;
}
static enum V_27 F_21 ( struct V_28 * V_28 ,
T_2 V_29 , T_1 * V_19 ,
unsigned long * V_22 )
{
* V_22 = V_37 + V_38 ;
return V_39 ;
}
static struct V_11 * F_28 ( unsigned int * V_46 ,
unsigned long V_22 , struct V_17 * V_18 ,
const T_1 * V_19 )
{
struct V_11 * V_47 , * V_15 ;
struct V_11 * V_48 = NULL ;
* V_46 = 0 ;
F_29 (g, p) {
unsigned int V_23 ;
if ( V_15 -> V_49 )
continue;
if ( F_13 ( V_15 , V_18 , V_19 ) )
continue;
if ( F_30 ( V_15 , V_50 ) )
return F_31 ( - 1UL ) ;
if ( ! V_15 -> V_9 )
continue;
if ( V_15 -> V_20 & V_51 ) {
if ( V_15 == V_4 ) {
V_48 = V_15 ;
* V_46 = 1000 ;
} else {
if ( ! ( V_15 -> V_52 -> V_53 & V_54 ) )
return F_31 ( - 1UL ) ;
}
}
V_23 = F_16 ( V_15 , V_18 , V_19 , V_22 ) ;
if ( V_23 > * V_46 ) {
V_48 = V_15 ;
* V_46 = V_23 ;
}
} F_32 ( V_47 , V_15 ) ;
return V_48 ;
}
static void F_33 ( const struct V_17 * V_18 , const T_1 * V_19 )
{
struct V_11 * V_15 ;
struct V_11 * V_55 ;
F_34 ( L_1 ) ;
F_35 (p) {
if ( F_13 ( V_15 , V_18 , V_19 ) )
continue;
V_55 = F_9 ( V_15 ) ;
if ( ! V_55 ) {
continue;
}
F_34 ( L_2 ,
V_55 -> V_56 , F_36 ( V_55 ) , V_55 -> V_57 ,
V_55 -> V_9 -> V_58 , F_18 ( V_55 -> V_9 ) ,
F_37 ( V_55 ) , V_55 -> signal -> V_59 ,
V_55 -> signal -> V_7 , V_55 -> V_60 ) ;
F_12 ( V_55 ) ;
}
}
static void F_38 ( struct V_11 * V_15 , T_2 V_29 , int V_61 ,
struct V_17 * V_18 , const T_1 * V_19 )
{
F_10 ( V_4 ) ;
F_39 ( L_3
L_4 ,
V_4 -> V_60 , V_29 , V_61 , V_4 -> signal -> V_59 ,
V_4 -> signal -> V_7 ) ;
F_40 ( V_4 ) ;
F_12 ( V_4 ) ;
F_41 () ;
F_42 ( V_18 , V_15 ) ;
F_43 ( V_62 ) ;
if ( V_63 )
F_33 ( V_18 , V_19 ) ;
}
static int F_44 ( struct V_11 * V_15 , struct V_17 * V_18 )
{
struct V_11 * V_64 ;
struct V_65 * V_9 ;
V_15 = F_9 ( V_15 ) ;
if ( ! V_15 )
return 1 ;
V_9 = V_15 -> V_9 ;
F_45 ( L_5 ,
F_46 ( V_15 ) , V_15 -> V_60 , F_47 ( V_15 -> V_9 -> V_58 ) ,
F_47 ( F_19 ( V_15 -> V_9 , V_66 ) ) ,
F_47 ( F_19 ( V_15 -> V_9 , V_67 ) ) ) ;
F_12 ( V_15 ) ;
F_35 (q)
if ( V_64 -> V_9 == V_9 && ! F_48 ( V_64 , V_15 ) ) {
F_10 ( V_64 ) ;
F_45 ( L_6 ,
F_46 ( V_64 ) , V_64 -> V_60 ) ;
F_12 ( V_64 ) ;
F_49 ( V_68 , V_64 ) ;
}
F_50 ( V_15 , V_50 ) ;
F_49 ( V_68 , V_15 ) ;
return 0 ;
}
static int F_51 ( struct V_11 * V_15 , T_2 V_29 , int V_61 ,
unsigned int V_23 , unsigned long V_22 ,
struct V_17 * V_18 , T_1 * V_19 ,
const char * V_69 )
{
struct V_11 * V_70 = V_15 ;
struct V_11 * V_71 ;
struct V_11 * V_16 = V_15 ;
unsigned int V_72 = 0 ;
if ( F_52 () )
F_38 ( V_15 , V_29 , V_61 , V_18 , V_19 ) ;
if ( V_15 -> V_20 & V_51 ) {
F_50 ( V_15 , V_50 ) ;
return 0 ;
}
F_10 ( V_15 ) ;
F_45 ( L_7 ,
V_69 , F_46 ( V_15 ) , V_15 -> V_60 , V_23 ) ;
F_12 ( V_15 ) ;
do {
F_53 (child, &t->children, sibling) {
unsigned int V_73 ;
if ( V_71 -> V_9 == V_15 -> V_9 )
continue;
V_73 = F_16 ( V_71 , V_18 , V_19 ,
V_22 ) ;
if ( V_73 > V_72 ) {
V_70 = V_71 ;
V_72 = V_73 ;
}
}
} while_each_thread(p, t) ;
void F_54 ( enum V_27 V_74 , T_2 V_29 ,
int V_61 , const T_1 * V_19 )
{
if ( F_11 ( ! V_75 ) )
return;
if ( V_75 != 2 ) {
if ( V_74 != V_39 )
return;
}
F_55 ( & V_76 ) ;
F_38 ( NULL , V_29 , V_61 , NULL , V_19 ) ;
F_56 ( & V_76 ) ;
F_57 ( L_8 ,
V_75 == 2 ? L_9 : L_10 ) ;
}
void F_58 ( struct V_17 * V_18 , T_2 V_29 )
{
unsigned long V_77 ;
unsigned int V_23 = 0 ;
struct V_11 * V_15 ;
if ( F_59 ( V_4 ) ) {
F_60 ( V_50 ) ;
return;
}
F_54 ( V_78 , V_29 , 0 , NULL ) ;
V_77 = F_61 ( V_18 ) >> V_79 ;
F_55 ( & V_76 ) ;
V_80:
V_15 = F_28 ( & V_23 , V_77 , V_18 , NULL ) ;
if ( ! V_15 || F_62 ( V_15 ) == - 1UL )
goto V_81;
if ( F_51 ( V_15 , V_29 , 0 , V_23 , V_77 , V_18 , NULL ,
L_11 ) )
goto V_80;
V_81:
F_56 ( & V_76 ) ;
}
int F_63 ( struct V_82 * V_83 )
{
return F_64 ( & V_84 , V_83 ) ;
}
int F_65 ( struct V_82 * V_83 )
{
return F_66 ( & V_84 , V_83 ) ;
}
int F_67 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
int V_85 = 1 ;
F_68 ( & V_86 ) ;
F_69 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_70 ( V_30 ) ) {
V_85 = 0 ;
goto V_81;
}
}
F_69 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_71 ( V_30 , V_87 ) ;
}
V_81:
F_72 ( & V_86 ) ;
return V_85 ;
}
void F_73 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
F_68 ( & V_86 ) ;
F_69 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_74 ( V_30 , V_87 ) ;
}
F_72 ( & V_86 ) ;
}
static int F_75 ( void )
{
struct V_30 * V_30 ;
int V_85 = 1 ;
F_68 ( & V_86 ) ;
F_76 (zone)
if ( F_70 ( V_30 ) ) {
V_85 = 0 ;
goto V_81;
}
F_76 (zone)
F_71 ( V_30 , V_87 ) ;
V_81:
F_72 ( & V_86 ) ;
return V_85 ;
}
static void F_77 ( void )
{
struct V_30 * V_30 ;
F_68 ( & V_86 ) ;
F_76 (zone)
F_74 ( V_30 , V_87 ) ;
F_72 ( & V_86 ) ;
}
void F_78 ( struct V_28 * V_28 , T_2 V_29 ,
int V_61 , T_1 * V_19 )
{
const T_1 * V_88 ;
struct V_11 * V_15 ;
unsigned long V_22 ;
unsigned long V_89 = 0 ;
unsigned int V_23 ;
enum V_27 V_74 = V_39 ;
int V_90 = 0 ;
F_79 ( & V_84 , 0 , & V_89 ) ;
if ( V_89 > 0 )
return;
if ( F_59 ( V_4 ) ) {
F_60 ( V_50 ) ;
return;
}
V_74 = F_21 ( V_28 , V_29 , V_19 ,
& V_22 ) ;
V_88 = ( V_74 == V_43 ) ? V_19 : NULL ;
F_54 ( V_74 , V_29 , V_61 , V_88 ) ;
F_55 ( & V_76 ) ;
if ( V_91 &&
! F_13 ( V_4 , NULL , V_19 ) &&
V_4 -> V_9 && ! F_17 ( & V_4 -> V_9 -> V_10 ) ) {
if ( ! F_51 ( V_4 , V_29 , V_61 , 0 , V_22 ,
NULL , V_19 ,
L_12 ) )
goto V_81;
}
V_80:
V_15 = F_28 ( & V_23 , V_22 , NULL , V_88 ) ;
if ( F_62 ( V_15 ) == - 1UL )
goto V_81;
if ( ! V_15 ) {
F_38 ( NULL , V_29 , V_61 , NULL , V_88 ) ;
F_56 ( & V_76 ) ;
F_57 ( L_13 ) ;
}
if ( F_51 ( V_15 , V_29 , V_61 , V_23 , V_22 , NULL ,
V_19 , L_14 ) )
goto V_80;
V_90 = 1 ;
V_81:
F_56 ( & V_76 ) ;
if ( V_90 && ! F_80 ( V_50 ) )
F_81 ( 1 ) ;
}
void F_82 ( void )
{
if ( F_75 () ) {
F_78 ( NULL , 0 , 0 , NULL ) ;
F_77 () ;
}
if ( ! F_80 ( V_50 ) )
F_81 ( 1 ) ;
}
