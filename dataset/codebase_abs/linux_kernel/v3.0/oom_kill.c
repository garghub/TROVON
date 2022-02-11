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
if ( ! V_15 -> V_9 )
continue;
if ( F_13 ( V_15 , V_18 , V_19 ) )
continue;
if ( F_30 ( V_15 , V_49 ) )
return F_31 ( - 1UL ) ;
if ( V_15 -> V_20 & V_50 ) {
if ( V_15 == V_4 ) {
V_48 = V_15 ;
* V_46 = 1000 ;
} else {
if ( ! ( F_32 ( V_15 -> V_51 ) &
V_52 ) )
return F_31 ( - 1UL ) ;
}
}
V_23 = F_16 ( V_15 , V_18 , V_19 , V_22 ) ;
if ( V_23 > * V_46 ) {
V_48 = V_15 ;
* V_46 = V_23 ;
}
} F_33 ( V_47 , V_15 ) ;
return V_48 ;
}
static void F_34 ( const struct V_17 * V_18 , const T_1 * V_19 )
{
struct V_11 * V_15 ;
struct V_11 * V_53 ;
F_35 ( L_1 ) ;
F_36 (p) {
if ( F_13 ( V_15 , V_18 , V_19 ) )
continue;
V_53 = F_9 ( V_15 ) ;
if ( ! V_53 ) {
continue;
}
F_35 ( L_2 ,
V_53 -> V_54 , F_37 ( V_53 ) , V_53 -> V_55 ,
V_53 -> V_9 -> V_56 , F_18 ( V_53 -> V_9 ) ,
F_38 ( V_53 ) , V_53 -> signal -> V_57 ,
V_53 -> signal -> V_7 , V_53 -> V_58 ) ;
F_12 ( V_53 ) ;
}
}
static void F_39 ( struct V_11 * V_15 , T_2 V_29 , int V_59 ,
struct V_17 * V_18 , const T_1 * V_19 )
{
F_10 ( V_4 ) ;
F_40 ( L_3
L_4 ,
V_4 -> V_58 , V_29 , V_59 , V_4 -> signal -> V_57 ,
V_4 -> signal -> V_7 ) ;
F_41 ( V_4 ) ;
F_12 ( V_4 ) ;
F_42 () ;
F_43 ( V_18 , V_15 ) ;
F_44 ( V_60 ) ;
if ( V_61 )
F_34 ( V_18 , V_19 ) ;
}
static int F_45 ( struct V_11 * V_15 , struct V_17 * V_18 )
{
struct V_11 * V_62 ;
struct V_63 * V_9 ;
V_15 = F_9 ( V_15 ) ;
if ( ! V_15 )
return 1 ;
V_9 = V_15 -> V_9 ;
F_46 ( L_5 ,
F_47 ( V_15 ) , V_15 -> V_58 , F_48 ( V_15 -> V_9 -> V_56 ) ,
F_48 ( F_19 ( V_15 -> V_9 , V_64 ) ) ,
F_48 ( F_19 ( V_15 -> V_9 , V_65 ) ) ) ;
F_12 ( V_15 ) ;
F_36 (q)
if ( V_62 -> V_9 == V_9 && ! F_49 ( V_62 , V_15 ) ) {
F_10 ( V_62 ) ;
F_46 ( L_6 ,
F_47 ( V_62 ) , V_62 -> V_58 ) ;
F_12 ( V_62 ) ;
F_50 ( V_66 , V_62 ) ;
}
F_51 ( V_15 , V_49 ) ;
F_50 ( V_66 , V_15 ) ;
return 0 ;
}
static int F_52 ( struct V_11 * V_15 , T_2 V_29 , int V_59 ,
unsigned int V_23 , unsigned long V_22 ,
struct V_17 * V_18 , T_1 * V_19 ,
const char * V_67 )
{
struct V_11 * V_68 = V_15 ;
struct V_11 * V_69 ;
struct V_11 * V_16 = V_15 ;
unsigned int V_70 = 0 ;
if ( F_53 () )
F_39 ( V_15 , V_29 , V_59 , V_18 , V_19 ) ;
if ( V_15 -> V_20 & V_50 ) {
F_51 ( V_15 , V_49 ) ;
return 0 ;
}
F_10 ( V_15 ) ;
F_46 ( L_7 ,
V_67 , F_47 ( V_15 ) , V_15 -> V_58 , V_23 ) ;
F_12 ( V_15 ) ;
do {
F_54 (child, &t->children, sibling) {
unsigned int V_71 ;
if ( V_69 -> V_9 == V_15 -> V_9 )
continue;
V_71 = F_16 ( V_69 , V_18 , V_19 ,
V_22 ) ;
if ( V_71 > V_70 ) {
V_68 = V_69 ;
V_70 = V_71 ;
}
}
} while_each_thread(p, t) ;
void F_55 ( enum V_27 V_72 , T_2 V_29 ,
int V_59 , const T_1 * V_19 )
{
if ( F_11 ( ! V_73 ) )
return;
if ( V_73 != 2 ) {
if ( V_72 != V_39 )
return;
}
F_56 ( & V_74 ) ;
F_39 ( NULL , V_29 , V_59 , NULL , V_19 ) ;
F_57 ( & V_74 ) ;
F_58 ( L_8 ,
V_73 == 2 ? L_9 : L_10 ) ;
}
void F_59 ( struct V_17 * V_18 , T_2 V_29 )
{
unsigned long V_75 ;
unsigned int V_23 = 0 ;
struct V_11 * V_15 ;
if ( F_60 ( V_4 ) ) {
F_61 ( V_49 ) ;
return;
}
F_55 ( V_76 , V_29 , 0 , NULL ) ;
V_75 = F_62 ( V_18 ) >> V_77 ;
F_56 ( & V_74 ) ;
V_78:
V_15 = F_28 ( & V_23 , V_75 , V_18 , NULL ) ;
if ( ! V_15 || F_63 ( V_15 ) == - 1UL )
goto V_79;
if ( F_52 ( V_15 , V_29 , 0 , V_23 , V_75 , V_18 , NULL ,
L_11 ) )
goto V_78;
V_79:
F_57 ( & V_74 ) ;
}
int F_64 ( struct V_80 * V_81 )
{
return F_65 ( & V_82 , V_81 ) ;
}
int F_66 ( struct V_80 * V_81 )
{
return F_67 ( & V_82 , V_81 ) ;
}
int F_68 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
int V_83 = 1 ;
F_69 ( & V_84 ) ;
F_70 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_71 ( V_30 ) ) {
V_83 = 0 ;
goto V_79;
}
}
F_70 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_72 ( V_30 , V_85 ) ;
}
V_79:
F_73 ( & V_84 ) ;
return V_83 ;
}
void F_74 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
F_69 ( & V_84 ) ;
F_70 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_75 ( V_30 , V_85 ) ;
}
F_73 ( & V_84 ) ;
}
static int F_76 ( void )
{
struct V_30 * V_30 ;
int V_83 = 1 ;
F_69 ( & V_84 ) ;
F_77 (zone)
if ( F_71 ( V_30 ) ) {
V_83 = 0 ;
goto V_79;
}
F_77 (zone)
F_72 ( V_30 , V_85 ) ;
V_79:
F_73 ( & V_84 ) ;
return V_83 ;
}
static void F_78 ( void )
{
struct V_30 * V_30 ;
F_69 ( & V_84 ) ;
F_77 (zone)
F_75 ( V_30 , V_85 ) ;
F_73 ( & V_84 ) ;
}
void F_79 ( struct V_28 * V_28 , T_2 V_29 ,
int V_59 , T_1 * V_19 )
{
const T_1 * V_86 ;
struct V_11 * V_15 ;
unsigned long V_22 ;
unsigned long V_87 = 0 ;
unsigned int V_23 ;
enum V_27 V_72 = V_39 ;
int V_88 = 0 ;
F_80 ( & V_82 , 0 , & V_87 ) ;
if ( V_87 > 0 )
return;
if ( F_60 ( V_4 ) ) {
F_61 ( V_49 ) ;
return;
}
V_72 = F_21 ( V_28 , V_29 , V_19 ,
& V_22 ) ;
V_86 = ( V_72 == V_43 ) ? V_19 : NULL ;
F_55 ( V_72 , V_29 , V_59 , V_86 ) ;
F_56 ( & V_74 ) ;
if ( V_89 &&
! F_13 ( V_4 , NULL , V_19 ) &&
V_4 -> V_9 && ! F_17 ( & V_4 -> V_9 -> V_10 ) ) {
if ( ! F_52 ( V_4 , V_29 , V_59 , 0 , V_22 ,
NULL , V_19 ,
L_12 ) )
goto V_79;
}
V_78:
V_15 = F_28 ( & V_23 , V_22 , NULL , V_86 ) ;
if ( F_63 ( V_15 ) == - 1UL )
goto V_79;
if ( ! V_15 ) {
F_39 ( NULL , V_29 , V_59 , NULL , V_86 ) ;
F_57 ( & V_74 ) ;
F_58 ( L_13 ) ;
}
if ( F_52 ( V_15 , V_29 , V_59 , V_23 , V_22 , NULL ,
V_19 , L_14 ) )
goto V_78;
V_88 = 1 ;
V_79:
F_57 ( & V_74 ) ;
if ( V_88 && ! F_81 ( V_49 ) )
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
