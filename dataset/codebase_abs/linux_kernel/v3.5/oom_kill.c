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
unsigned long F_16 ( struct V_8 * V_12 , struct V_15 * V_16 ,
const T_1 * V_17 , unsigned long V_20 )
{
long V_21 ;
long V_22 ;
if ( F_13 ( V_12 , V_16 , V_17 ) )
return 0 ;
V_12 = F_9 ( V_12 ) ;
if ( ! V_12 )
return 0 ;
V_22 = V_12 -> signal -> V_7 ;
if ( V_22 == V_23 ) {
F_12 ( V_12 ) ;
return 0 ;
}
V_21 = F_17 ( V_12 -> V_14 ) + V_12 -> V_14 -> V_24 +
F_18 ( V_12 -> V_14 , V_25 ) ;
F_12 ( V_12 ) ;
if ( F_19 ( V_12 , V_26 ) )
V_22 -= 30 ;
V_22 *= V_20 / 1000 ;
V_21 += V_22 ;
return V_21 > 0 ? V_21 : 1 ;
}
static enum V_27 F_20 ( struct V_28 * V_28 ,
T_2 V_29 , T_1 * V_17 ,
unsigned long * V_20 )
{
struct V_30 * V_30 ;
struct V_31 * V_32 ;
enum V_33 V_34 = F_21 ( V_29 ) ;
bool V_35 = false ;
int V_36 ;
* V_20 = V_37 + V_38 ;
if ( ! V_28 )
return V_39 ;
if ( V_29 & V_40 )
return V_39 ;
if ( V_17 && ! F_22 ( V_41 [ V_42 ] , * V_17 ) ) {
* V_20 = V_38 ;
F_23 ( V_36 , * V_17 )
* V_20 += F_24 ( V_36 ) ;
return V_43 ;
}
F_25 (zone, z, zonelist,
high_zoneidx, nodemask)
if ( ! F_26 ( V_30 , V_29 ) )
V_35 = true ;
if ( V_35 ) {
* V_20 = V_38 ;
F_23 ( V_36 , V_44 )
* V_20 += F_24 ( V_36 ) ;
return V_45 ;
}
return V_39 ;
}
static enum V_27 F_20 ( struct V_28 * V_28 ,
T_2 V_29 , T_1 * V_17 ,
unsigned long * V_20 )
{
* V_20 = V_37 + V_38 ;
return V_39 ;
}
static struct V_8 * F_27 ( unsigned int * V_46 ,
unsigned long V_20 , struct V_15 * V_16 ,
const T_1 * V_17 , bool V_47 )
{
struct V_8 * V_48 , * V_12 ;
struct V_8 * V_49 = NULL ;
unsigned long V_50 = 0 ;
F_28 (g, p) {
unsigned int V_21 ;
if ( V_12 -> V_51 )
continue;
if ( F_13 ( V_12 , V_16 , V_17 ) )
continue;
if ( F_29 ( V_12 , V_52 ) ) {
if ( F_30 ( F_31 ( V_12 ) ) )
F_32 ( V_12 ) ;
if ( ! V_47 )
return F_33 ( - 1UL ) ;
}
if ( ! V_12 -> V_14 )
continue;
if ( V_12 -> V_18 & V_53 ) {
if ( V_12 == V_5 ) {
V_49 = V_12 ;
V_50 = V_54 ;
} else if ( ! V_47 ) {
if ( ! ( V_12 -> V_55 -> V_56 & V_57 ) )
return F_33 ( - 1UL ) ;
}
}
V_21 = F_16 ( V_12 , V_16 , V_17 , V_20 ) ;
if ( V_21 > V_50 ) {
V_49 = V_12 ;
V_50 = V_21 ;
}
} F_34 ( V_48 , V_12 ) ;
* V_46 = V_50 * 1000 / V_20 ;
return V_49 ;
}
static void F_35 ( const struct V_15 * V_16 , const T_1 * V_17 )
{
struct V_8 * V_12 ;
struct V_8 * V_58 ;
F_36 ( L_1 ) ;
F_37 (p) {
if ( F_13 ( V_12 , V_16 , V_17 ) )
continue;
V_58 = F_9 ( V_12 ) ;
if ( ! V_58 ) {
continue;
}
F_36 ( L_2 ,
V_58 -> V_59 , F_38 ( & V_60 , F_39 ( V_58 ) ) ,
V_58 -> V_61 , V_58 -> V_14 -> V_62 , F_17 ( V_58 -> V_14 ) ,
F_40 ( V_58 ) , V_58 -> signal -> V_63 ,
V_58 -> signal -> V_7 , V_58 -> V_64 ) ;
F_12 ( V_58 ) ;
}
}
static void F_41 ( struct V_8 * V_12 , T_2 V_29 , int V_65 ,
struct V_15 * V_16 , const T_1 * V_17 )
{
F_10 ( V_5 ) ;
F_42 ( L_3
L_4 ,
V_5 -> V_64 , V_29 , V_65 , V_5 -> signal -> V_63 ,
V_5 -> signal -> V_7 ) ;
F_43 ( V_5 ) ;
F_12 ( V_5 ) ;
F_44 () ;
F_45 ( V_16 , V_12 ) ;
F_46 ( V_66 ) ;
if ( V_67 )
F_35 ( V_16 , V_17 ) ;
}
static void F_47 ( struct V_8 * V_12 , T_2 V_29 , int V_65 ,
unsigned int V_21 , unsigned long V_20 ,
struct V_15 * V_16 , T_1 * V_17 ,
const char * V_68 )
{
struct V_8 * V_69 = V_12 ;
struct V_8 * V_70 ;
struct V_8 * V_13 = V_12 ;
struct V_71 * V_14 ;
unsigned int V_72 = 0 ;
static F_48 ( V_73 , V_74 ,
V_75 ) ;
if ( V_12 -> V_18 & V_53 ) {
F_49 ( V_12 , V_52 ) ;
return;
}
if ( F_50 ( & V_73 ) )
F_41 ( V_12 , V_29 , V_65 , V_16 , V_17 ) ;
F_10 ( V_12 ) ;
F_51 ( L_5 ,
V_68 , F_52 ( V_12 ) , V_12 -> V_64 , V_21 ) ;
F_12 ( V_12 ) ;
do {
F_53 (child, &t->children, sibling) {
unsigned int V_76 ;
if ( V_70 -> V_14 == V_12 -> V_14 )
continue;
V_76 = F_16 ( V_70 , V_16 , V_17 ,
V_20 ) ;
if ( V_76 > V_72 ) {
V_69 = V_70 ;
V_72 = V_76 ;
}
}
} while_each_thread(p, t) ;
void F_54 ( enum V_27 V_77 , T_2 V_29 ,
int V_65 , const T_1 * V_17 )
{
if ( F_11 ( ! V_78 ) )
return;
if ( V_78 != 2 ) {
if ( V_77 != V_39 )
return;
}
F_55 ( & V_79 ) ;
F_41 ( NULL , V_29 , V_65 , NULL , V_17 ) ;
F_56 ( & V_79 ) ;
F_57 ( L_6 ,
V_78 == 2 ? L_7 : L_8 ) ;
}
void F_58 ( struct V_15 * V_16 , T_2 V_29 ,
int V_65 )
{
unsigned long V_80 ;
unsigned int V_21 = 0 ;
struct V_8 * V_12 ;
if ( F_59 ( V_5 ) ) {
F_60 ( V_52 ) ;
return;
}
F_54 ( V_81 , V_29 , V_65 , NULL ) ;
V_80 = F_61 ( V_16 ) >> V_82 ? : 1 ;
F_55 ( & V_79 ) ;
V_12 = F_27 ( & V_21 , V_80 , V_16 , NULL , false ) ;
if ( V_12 && F_62 ( V_12 ) != - 1UL )
F_47 ( V_12 , V_29 , V_65 , V_21 , V_80 , V_16 , NULL ,
L_9 ) ;
F_56 ( & V_79 ) ;
}
int F_63 ( struct V_83 * V_84 )
{
return F_64 ( & V_85 , V_84 ) ;
}
int F_65 ( struct V_83 * V_84 )
{
return F_66 ( & V_85 , V_84 ) ;
}
int F_67 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
int V_86 = 1 ;
F_68 ( & V_87 ) ;
F_69 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_70 ( V_30 ) ) {
V_86 = 0 ;
goto V_88;
}
}
F_69 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_71 ( V_30 , V_89 ) ;
}
V_88:
F_72 ( & V_87 ) ;
return V_86 ;
}
void F_73 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
F_68 ( & V_87 ) ;
F_69 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_74 ( V_30 , V_89 ) ;
}
F_72 ( & V_87 ) ;
}
static int F_75 ( void )
{
struct V_30 * V_30 ;
int V_86 = 1 ;
F_68 ( & V_87 ) ;
F_76 (zone)
if ( F_70 ( V_30 ) ) {
V_86 = 0 ;
goto V_88;
}
F_76 (zone)
F_71 ( V_30 , V_89 ) ;
V_88:
F_72 ( & V_87 ) ;
return V_86 ;
}
static void F_77 ( void )
{
struct V_30 * V_30 ;
F_68 ( & V_87 ) ;
F_76 (zone)
F_74 ( V_30 , V_89 ) ;
F_72 ( & V_87 ) ;
}
void F_78 ( struct V_28 * V_28 , T_2 V_29 ,
int V_65 , T_1 * V_17 , bool V_47 )
{
const T_1 * V_90 ;
struct V_8 * V_12 ;
unsigned long V_20 ;
unsigned long V_91 = 0 ;
unsigned int V_21 ;
enum V_27 V_77 = V_39 ;
int V_92 = 0 ;
F_79 ( & V_85 , 0 , & V_91 ) ;
if ( V_91 > 0 )
return;
if ( F_59 ( V_5 ) ) {
F_60 ( V_52 ) ;
return;
}
V_77 = F_20 ( V_28 , V_29 , V_17 ,
& V_20 ) ;
V_90 = ( V_77 == V_43 ) ? V_17 : NULL ;
F_54 ( V_77 , V_29 , V_65 , V_90 ) ;
F_55 ( & V_79 ) ;
if ( V_93 &&
! F_13 ( V_5 , NULL , V_17 ) &&
V_5 -> V_14 ) {
F_47 ( V_5 , V_29 , V_65 , 0 , V_20 , NULL ,
V_17 ,
L_10 ) ;
goto V_88;
}
V_12 = F_27 ( & V_21 , V_20 , NULL , V_90 ,
V_47 ) ;
if ( ! V_12 ) {
F_41 ( NULL , V_29 , V_65 , NULL , V_90 ) ;
F_56 ( & V_79 ) ;
F_57 ( L_11 ) ;
}
if ( F_62 ( V_12 ) != - 1UL ) {
F_47 ( V_12 , V_29 , V_65 , V_21 , V_20 , NULL ,
V_17 , L_12 ) ;
V_92 = 1 ;
}
V_88:
F_56 ( & V_79 ) ;
if ( V_92 && ! F_80 ( V_52 ) )
F_81 ( 1 ) ;
}
void F_82 ( void )
{
if ( F_75 () ) {
F_78 ( NULL , 0 , 0 , NULL , false ) ;
F_77 () ;
}
if ( ! F_80 ( V_52 ) )
F_81 ( 1 ) ;
}
