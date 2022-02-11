void F_1 ( int V_1 , int V_2 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_5 -> signal -> V_7 == V_1 )
V_5 -> signal -> V_7 = V_2 ;
F_3 ( & V_4 -> V_6 ) ;
}
int F_4 ( int V_2 )
{
struct V_3 * V_4 = V_5 -> V_4 ;
int V_1 ;
F_2 ( & V_4 -> V_6 ) ;
V_1 = V_5 -> signal -> V_7 ;
V_5 -> signal -> V_7 = V_2 ;
F_3 ( & V_4 -> V_6 ) ;
return V_1 ;
}
static bool F_5 ( struct V_8 * V_9 ,
const T_1 * V_10 )
{
struct V_8 * V_11 = V_9 ;
do {
if ( V_10 ) {
if ( F_6 ( V_9 , V_10 ) )
return true ;
} else {
if ( F_7 ( V_5 , V_9 ) )
return true ;
}
} while_each_thread(start, tsk) ;
bool F_5 ( struct V_8 * V_9 ,
const T_1 * V_10 )
{
return true ;
}
struct V_8 * F_8 ( struct V_8 * V_12 )
{
struct V_8 * V_13 = V_12 ;
do {
F_9 ( V_13 ) ;
if ( F_10 ( V_13 -> V_14 ) )
return V_13 ;
F_11 ( V_13 ) ;
} while_each_thread(p, t) ;
bool F_12 ( struct V_8 * V_12 ,
const struct V_15 * V_16 , const T_1 * V_17 )
{
if ( F_13 ( V_12 ) )
return true ;
if ( V_12 -> V_18 & V_19 )
return true ;
if ( V_16 && ! F_14 ( V_12 , V_16 ) )
return true ;
if ( ! F_5 ( V_12 , V_17 ) )
return true ;
return false ;
}
unsigned int F_15 ( struct V_8 * V_12 , struct V_15 * V_16 ,
const T_1 * V_17 , unsigned long V_20 )
{
long V_21 ;
if ( F_12 ( V_12 , V_16 , V_17 ) )
return 0 ;
V_12 = F_8 ( V_12 ) ;
if ( ! V_12 )
return 0 ;
if ( V_12 -> signal -> V_7 == V_22 ) {
F_11 ( V_12 ) ;
return 0 ;
}
if ( ! V_20 )
V_20 = 1 ;
V_21 = F_16 ( V_12 -> V_14 ) + V_12 -> V_14 -> V_23 ;
V_21 += F_17 ( V_12 -> V_14 , V_24 ) ;
V_21 *= 1000 ;
V_21 /= V_20 ;
F_11 ( V_12 ) ;
if ( F_18 ( V_12 , V_25 ) )
V_21 -= 30 ;
V_21 += V_12 -> signal -> V_7 ;
if ( V_21 <= 0 )
return 1 ;
return ( V_21 < 1000 ) ? V_21 : 1000 ;
}
static enum V_26 F_19 ( struct V_27 * V_27 ,
T_2 V_28 , T_1 * V_17 ,
unsigned long * V_20 )
{
struct V_29 * V_29 ;
struct V_30 * V_31 ;
enum V_32 V_33 = F_20 ( V_28 ) ;
bool V_34 = false ;
int V_35 ;
* V_20 = V_36 + V_37 ;
if ( ! V_27 )
return V_38 ;
if ( V_28 & V_39 )
return V_38 ;
if ( V_17 && ! F_21 ( V_40 [ V_41 ] , * V_17 ) ) {
* V_20 = V_37 ;
F_22 ( V_35 , * V_17 )
* V_20 += F_23 ( V_35 ) ;
return V_42 ;
}
F_24 (zone, z, zonelist,
high_zoneidx, nodemask)
if ( ! F_25 ( V_29 , V_28 ) )
V_34 = true ;
if ( V_34 ) {
* V_20 = V_37 ;
F_22 ( V_35 , V_43 )
* V_20 += F_23 ( V_35 ) ;
return V_44 ;
}
return V_38 ;
}
static enum V_26 F_19 ( struct V_27 * V_27 ,
T_2 V_28 , T_1 * V_17 ,
unsigned long * V_20 )
{
* V_20 = V_36 + V_37 ;
return V_38 ;
}
static struct V_8 * F_26 ( unsigned int * V_45 ,
unsigned long V_20 , struct V_15 * V_16 ,
const T_1 * V_17 )
{
struct V_8 * V_46 , * V_12 ;
struct V_8 * V_47 = NULL ;
* V_45 = 0 ;
F_27 (g, p) {
unsigned int V_21 ;
if ( V_12 -> V_48 )
continue;
if ( F_12 ( V_12 , V_16 , V_17 ) )
continue;
if ( F_28 ( V_12 , V_49 ) ) {
if ( F_29 ( F_30 ( V_12 ) ) )
F_31 ( V_12 ) ;
return F_32 ( - 1UL ) ;
}
if ( ! V_12 -> V_14 )
continue;
if ( V_12 -> V_18 & V_50 ) {
if ( V_12 == V_5 ) {
V_47 = V_12 ;
* V_45 = 1000 ;
} else {
if ( ! ( V_12 -> V_51 -> V_52 & V_53 ) )
return F_32 ( - 1UL ) ;
}
}
V_21 = F_15 ( V_12 , V_16 , V_17 , V_20 ) ;
if ( V_21 > * V_45 ) {
V_47 = V_12 ;
* V_45 = V_21 ;
}
} F_33 ( V_46 , V_12 ) ;
return V_47 ;
}
static void F_34 ( const struct V_15 * V_16 , const T_1 * V_17 )
{
struct V_8 * V_12 ;
struct V_8 * V_54 ;
F_35 ( L_1 ) ;
F_36 (p) {
if ( F_12 ( V_12 , V_16 , V_17 ) )
continue;
V_54 = F_8 ( V_12 ) ;
if ( ! V_54 ) {
continue;
}
F_35 ( L_2 ,
V_54 -> V_55 , F_37 ( V_54 ) , V_54 -> V_56 ,
V_54 -> V_14 -> V_57 , F_16 ( V_54 -> V_14 ) ,
F_38 ( V_54 ) , V_54 -> signal -> V_58 ,
V_54 -> signal -> V_7 , V_54 -> V_59 ) ;
F_11 ( V_54 ) ;
}
}
static void F_39 ( struct V_8 * V_12 , T_2 V_28 , int V_60 ,
struct V_15 * V_16 , const T_1 * V_17 )
{
F_9 ( V_5 ) ;
F_40 ( L_3
L_4 ,
V_5 -> V_59 , V_28 , V_60 , V_5 -> signal -> V_58 ,
V_5 -> signal -> V_7 ) ;
F_41 ( V_5 ) ;
F_11 ( V_5 ) ;
F_42 () ;
F_43 ( V_16 , V_12 ) ;
F_44 ( V_61 ) ;
if ( V_62 )
F_34 ( V_16 , V_17 ) ;
}
static int F_45 ( struct V_8 * V_12 , struct V_15 * V_16 )
{
struct V_8 * V_63 ;
struct V_64 * V_14 ;
V_12 = F_8 ( V_12 ) ;
if ( ! V_12 )
return 1 ;
V_14 = V_12 -> V_14 ;
F_46 ( L_5 ,
F_47 ( V_12 ) , V_12 -> V_59 , F_48 ( V_12 -> V_14 -> V_57 ) ,
F_48 ( F_17 ( V_12 -> V_14 , V_65 ) ) ,
F_48 ( F_17 ( V_12 -> V_14 , V_66 ) ) ) ;
F_11 ( V_12 ) ;
F_36 (q)
if ( V_63 -> V_14 == V_14 && ! F_49 ( V_63 , V_12 ) &&
! ( V_63 -> V_18 & V_19 ) ) {
if ( V_63 -> signal -> V_7 == V_22 )
continue;
F_9 ( V_63 ) ;
F_46 ( L_6 ,
F_47 ( V_63 ) , V_63 -> V_59 ) ;
F_11 ( V_63 ) ;
F_50 ( V_67 , V_63 ) ;
}
F_51 ( V_12 , V_49 ) ;
F_50 ( V_67 , V_12 ) ;
return 0 ;
}
static int F_52 ( struct V_8 * V_12 , T_2 V_28 , int V_60 ,
unsigned int V_21 , unsigned long V_20 ,
struct V_15 * V_16 , T_1 * V_17 ,
const char * V_68 )
{
struct V_8 * V_69 = V_12 ;
struct V_8 * V_70 ;
struct V_8 * V_13 = V_12 ;
unsigned int V_71 = 0 ;
if ( F_53 () )
F_39 ( V_12 , V_28 , V_60 , V_16 , V_17 ) ;
if ( V_12 -> V_18 & V_50 ) {
F_51 ( V_12 , V_49 ) ;
return 0 ;
}
F_9 ( V_12 ) ;
F_46 ( L_7 ,
V_68 , F_47 ( V_12 ) , V_12 -> V_59 , V_21 ) ;
F_11 ( V_12 ) ;
do {
F_54 (child, &t->children, sibling) {
unsigned int V_72 ;
if ( V_70 -> V_14 == V_12 -> V_14 )
continue;
V_72 = F_15 ( V_70 , V_16 , V_17 ,
V_20 ) ;
if ( V_72 > V_71 ) {
V_69 = V_70 ;
V_71 = V_72 ;
}
}
} while_each_thread(p, t) ;
void F_55 ( enum V_26 V_73 , T_2 V_28 ,
int V_60 , const T_1 * V_17 )
{
if ( F_10 ( ! V_74 ) )
return;
if ( V_74 != 2 ) {
if ( V_73 != V_38 )
return;
}
F_56 ( & V_75 ) ;
F_39 ( NULL , V_28 , V_60 , NULL , V_17 ) ;
F_57 ( & V_75 ) ;
F_58 ( L_8 ,
V_74 == 2 ? L_9 : L_10 ) ;
}
void F_59 ( struct V_15 * V_16 , T_2 V_28 )
{
unsigned long V_76 ;
unsigned int V_21 = 0 ;
struct V_8 * V_12 ;
if ( F_60 ( V_5 ) ) {
F_61 ( V_49 ) ;
return;
}
F_55 ( V_77 , V_28 , 0 , NULL ) ;
V_76 = F_62 ( V_16 ) >> V_78 ;
F_56 ( & V_75 ) ;
V_79:
V_12 = F_26 ( & V_21 , V_76 , V_16 , NULL ) ;
if ( ! V_12 || F_63 ( V_12 ) == - 1UL )
goto V_80;
if ( F_52 ( V_12 , V_28 , 0 , V_21 , V_76 , V_16 , NULL ,
L_11 ) )
goto V_79;
V_80:
F_57 ( & V_75 ) ;
}
int F_64 ( struct V_81 * V_82 )
{
return F_65 ( & V_83 , V_82 ) ;
}
int F_66 ( struct V_81 * V_82 )
{
return F_67 ( & V_83 , V_82 ) ;
}
int F_68 ( struct V_27 * V_27 , T_2 V_28 )
{
struct V_30 * V_31 ;
struct V_29 * V_29 ;
int V_84 = 1 ;
F_69 ( & V_85 ) ;
F_70 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_71 ( V_29 ) ) {
V_84 = 0 ;
goto V_80;
}
}
F_70 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_72 ( V_29 , V_86 ) ;
}
V_80:
F_73 ( & V_85 ) ;
return V_84 ;
}
void F_74 ( struct V_27 * V_27 , T_2 V_28 )
{
struct V_30 * V_31 ;
struct V_29 * V_29 ;
F_69 ( & V_85 ) ;
F_70 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_75 ( V_29 , V_86 ) ;
}
F_73 ( & V_85 ) ;
}
static int F_76 ( void )
{
struct V_29 * V_29 ;
int V_84 = 1 ;
F_69 ( & V_85 ) ;
F_77 (zone)
if ( F_71 ( V_29 ) ) {
V_84 = 0 ;
goto V_80;
}
F_77 (zone)
F_72 ( V_29 , V_86 ) ;
V_80:
F_73 ( & V_85 ) ;
return V_84 ;
}
static void F_78 ( void )
{
struct V_29 * V_29 ;
F_69 ( & V_85 ) ;
F_77 (zone)
F_75 ( V_29 , V_86 ) ;
F_73 ( & V_85 ) ;
}
void F_79 ( struct V_27 * V_27 , T_2 V_28 ,
int V_60 , T_1 * V_17 )
{
const T_1 * V_87 ;
struct V_8 * V_12 ;
unsigned long V_20 ;
unsigned long V_88 = 0 ;
unsigned int V_21 ;
enum V_26 V_73 = V_38 ;
int V_89 = 0 ;
F_80 ( & V_83 , 0 , & V_88 ) ;
if ( V_88 > 0 )
return;
if ( F_60 ( V_5 ) ) {
F_61 ( V_49 ) ;
return;
}
V_73 = F_19 ( V_27 , V_28 , V_17 ,
& V_20 ) ;
V_87 = ( V_73 == V_42 ) ? V_17 : NULL ;
F_55 ( V_73 , V_28 , V_60 , V_87 ) ;
F_56 ( & V_75 ) ;
if ( V_90 &&
! F_12 ( V_5 , NULL , V_17 ) &&
V_5 -> V_14 ) {
if ( ! F_52 ( V_5 , V_28 , V_60 , 0 , V_20 ,
NULL , V_17 ,
L_12 ) )
goto V_80;
}
V_79:
V_12 = F_26 ( & V_21 , V_20 , NULL , V_87 ) ;
if ( F_63 ( V_12 ) == - 1UL )
goto V_80;
if ( ! V_12 ) {
F_39 ( NULL , V_28 , V_60 , NULL , V_87 ) ;
F_57 ( & V_75 ) ;
F_58 ( L_13 ) ;
}
if ( F_52 ( V_12 , V_28 , V_60 , V_21 , V_20 , NULL ,
V_17 , L_14 ) )
goto V_79;
V_89 = 1 ;
V_80:
F_57 ( & V_75 ) ;
if ( V_89 && ! F_81 ( V_49 ) )
F_82 ( 1 ) ;
}
void F_83 ( void )
{
if ( F_76 () ) {
F_79 ( NULL , 0 , 0 , NULL ) ;
F_78 () ;
}
if ( ! F_81 ( V_49 ) )
F_82 ( 1 ) ;
}
