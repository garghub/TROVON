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
const struct V_11 * V_12 , const T_1 * V_13 )
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
V_17 = F_15 ( V_7 -> V_9 ) + F_16 ( & V_7 -> V_9 -> V_21 ) +
F_17 ( V_7 -> V_9 , V_22 ) ;
F_10 ( V_7 ) ;
if ( F_18 ( V_7 , V_23 ) )
V_17 -= ( V_17 * 3 ) / 100 ;
V_18 *= V_16 / 1000 ;
V_17 += V_18 ;
return V_17 > 0 ? V_17 : 1 ;
}
static enum V_24 F_19 ( struct V_25 * V_25 ,
T_2 V_26 , T_1 * V_13 ,
unsigned long * V_16 )
{
struct V_27 * V_27 ;
struct V_28 * V_29 ;
enum V_30 V_31 = F_20 ( V_26 ) ;
bool V_32 = false ;
int V_33 ;
* V_16 = V_34 + V_35 ;
if ( ! V_25 )
return V_36 ;
if ( V_26 & V_37 )
return V_36 ;
if ( V_13 && ! F_21 ( V_38 [ V_39 ] , * V_13 ) ) {
* V_16 = V_35 ;
F_22 ( V_33 , * V_13 )
* V_16 += F_23 ( V_33 ) ;
return V_40 ;
}
F_24 (zone, z, zonelist,
high_zoneidx, nodemask)
if ( ! F_25 ( V_27 , V_26 ) )
V_32 = true ;
if ( V_32 ) {
* V_16 = V_35 ;
F_22 ( V_33 , V_41 )
* V_16 += F_23 ( V_33 ) ;
return V_42 ;
}
return V_36 ;
}
static enum V_24 F_19 ( struct V_25 * V_25 ,
T_2 V_26 , T_1 * V_13 ,
unsigned long * V_16 )
{
* V_16 = V_34 + V_35 ;
return V_36 ;
}
enum V_43 F_26 ( struct V_1 * V_44 ,
unsigned long V_16 , const T_1 * V_13 ,
bool V_45 )
{
if ( V_44 -> V_46 )
return V_47 ;
if ( F_11 ( V_44 , NULL , V_13 ) )
return V_47 ;
if ( F_27 ( V_44 , V_48 ) ) {
if ( F_28 ( F_29 ( V_44 ) ) )
F_30 ( V_44 ) ;
if ( ! V_45 )
return V_49 ;
}
if ( ! V_44 -> V_9 )
return V_47 ;
if ( F_31 ( V_44 ) )
return V_50 ;
if ( V_44 -> V_14 & V_51 && ! V_45 ) {
if ( ! ( V_44 -> V_52 -> V_53 & V_54 ) )
return V_49 ;
}
return V_55 ;
}
static struct V_1 * F_32 ( unsigned int * V_56 ,
unsigned long V_16 , const T_1 * V_13 ,
bool V_45 )
{
struct V_1 * V_57 , * V_7 ;
struct V_1 * V_58 = NULL ;
unsigned long V_59 = 0 ;
F_2 () ;
F_33 (g, p) {
unsigned int V_17 ;
switch ( F_26 ( V_7 , V_16 , V_13 ,
V_45 ) ) {
case V_50 :
V_58 = V_7 ;
V_59 = V_60 ;
case V_47 :
continue;
case V_49 :
F_6 () ;
return (struct V_1 * ) ( - 1UL ) ;
case V_55 :
break;
} ;
V_17 = F_14 ( V_7 , NULL , V_13 , V_16 ) ;
if ( ! V_17 || V_17 < V_59 )
continue;
if ( V_17 == V_59 && F_34 ( V_58 ) )
continue;
V_58 = V_7 ;
V_59 = V_17 ;
}
if ( V_58 )
F_35 ( V_58 ) ;
F_6 () ;
* V_56 = V_59 * 1000 / V_16 ;
return V_58 ;
}
static void F_36 ( const struct V_11 * V_12 , const T_1 * V_13 )
{
struct V_1 * V_7 ;
struct V_1 * V_44 ;
F_37 ( L_1 ) ;
F_2 () ;
F_38 (p) {
if ( F_11 ( V_7 , V_12 , V_13 ) )
continue;
V_44 = F_7 ( V_7 ) ;
if ( ! V_44 ) {
continue;
}
F_37 ( L_2 ,
V_44 -> V_61 , F_39 ( & V_62 , F_40 ( V_44 ) ) ,
V_44 -> V_63 , V_44 -> V_9 -> V_64 , F_15 ( V_44 -> V_9 ) ,
F_16 ( & V_44 -> V_9 -> V_21 ) ,
F_17 ( V_44 -> V_9 , V_22 ) ,
V_44 -> signal -> V_19 , V_44 -> V_65 ) ;
F_10 ( V_44 ) ;
}
F_6 () ;
}
static void F_41 ( struct V_1 * V_7 , T_2 V_26 , int V_66 ,
struct V_11 * V_12 , const T_1 * V_13 )
{
F_8 ( V_6 ) ;
F_42 ( L_3
L_4 ,
V_6 -> V_65 , V_26 , V_66 ,
V_6 -> signal -> V_19 ) ;
F_43 ( V_6 ) ;
F_10 ( V_6 ) ;
F_44 () ;
if ( V_12 )
F_45 ( V_12 , V_7 ) ;
else
F_46 ( V_67 ) ;
if ( V_68 )
F_36 ( V_12 , V_13 ) ;
}
void F_47 ( struct V_1 * V_7 , T_2 V_26 , int V_66 ,
unsigned int V_17 , unsigned long V_16 ,
struct V_11 * V_12 , T_1 * V_13 ,
const char * V_69 )
{
struct V_1 * V_70 = V_7 ;
struct V_1 * V_71 ;
struct V_1 * V_8 ;
struct V_72 * V_9 ;
unsigned int V_73 = 0 ;
static F_48 ( V_74 , V_75 ,
V_76 ) ;
if ( V_7 -> V_14 & V_51 ) {
F_49 ( V_7 , V_48 ) ;
F_50 ( V_7 ) ;
return;
}
if ( F_51 ( & V_74 ) )
F_41 ( V_7 , V_26 , V_66 , V_12 , V_13 ) ;
F_8 ( V_7 ) ;
F_52 ( L_5 ,
V_69 , F_53 ( V_7 ) , V_7 -> V_65 , V_17 ) ;
F_10 ( V_7 ) ;
F_54 ( & V_77 ) ;
F_3 (p, t) {
F_55 (child, &t->children, sibling) {
unsigned int V_78 ;
if ( V_71 -> V_9 == V_7 -> V_9 )
continue;
V_78 = F_14 ( V_71 , V_12 , V_13 ,
V_16 ) ;
if ( V_78 > V_73 ) {
F_50 ( V_70 ) ;
V_70 = V_71 ;
V_73 = V_78 ;
F_35 ( V_70 ) ;
}
}
}
F_56 ( & V_77 ) ;
V_7 = F_7 ( V_70 ) ;
if ( ! V_7 ) {
F_50 ( V_70 ) ;
return;
} else if ( V_70 != V_7 ) {
F_35 ( V_7 ) ;
F_50 ( V_70 ) ;
V_70 = V_7 ;
}
V_9 = V_70 -> V_9 ;
F_52 ( L_6 ,
F_53 ( V_70 ) , V_70 -> V_65 , F_57 ( V_70 -> V_9 -> V_64 ) ,
F_57 ( F_17 ( V_70 -> V_9 , V_79 ) ) ,
F_57 ( F_17 ( V_70 -> V_9 , V_80 ) ) ) ;
F_10 ( V_70 ) ;
F_2 () ;
F_38 (p)
if ( V_7 -> V_9 == V_9 && ! F_58 ( V_7 , V_70 ) &&
! ( V_7 -> V_14 & V_15 ) ) {
if ( V_7 -> signal -> V_19 == V_20 )
continue;
F_8 ( V_7 ) ;
F_52 ( L_7 ,
F_53 ( V_7 ) , V_7 -> V_65 ) ;
F_10 ( V_7 ) ;
F_59 ( V_81 , V_82 , V_7 , true ) ;
}
F_6 () ;
F_49 ( V_70 , V_48 ) ;
F_59 ( V_81 , V_82 , V_70 , true ) ;
F_50 ( V_70 ) ;
}
void F_60 ( enum V_24 V_83 , T_2 V_26 ,
int V_66 , const T_1 * V_13 )
{
if ( F_9 ( ! V_84 ) )
return;
if ( V_84 != 2 ) {
if ( V_83 != V_36 )
return;
}
F_41 ( NULL , V_26 , V_66 , NULL , V_13 ) ;
F_61 ( L_8 ,
V_84 == 2 ? L_9 : L_10 ) ;
}
int F_62 ( struct V_85 * V_86 )
{
return F_63 ( & V_87 , V_86 ) ;
}
int F_64 ( struct V_85 * V_86 )
{
return F_65 ( & V_87 , V_86 ) ;
}
int F_66 ( struct V_25 * V_25 , T_2 V_26 )
{
struct V_28 * V_29 ;
struct V_27 * V_27 ;
int V_5 = 1 ;
F_67 ( & V_88 ) ;
F_68 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_69 ( V_27 ) ) {
V_5 = 0 ;
goto V_89;
}
}
F_68 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_70 ( V_27 , V_90 ) ;
}
V_89:
F_71 ( & V_88 ) ;
return V_5 ;
}
void F_72 ( struct V_25 * V_25 , T_2 V_26 )
{
struct V_28 * V_29 ;
struct V_27 * V_27 ;
F_67 ( & V_88 ) ;
F_68 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_73 ( V_27 , V_90 ) ;
}
F_71 ( & V_88 ) ;
}
void F_74 ( struct V_25 * V_25 , T_2 V_26 ,
int V_66 , T_1 * V_13 , bool V_45 )
{
const T_1 * V_91 ;
struct V_1 * V_7 ;
unsigned long V_16 ;
unsigned long V_92 = 0 ;
unsigned int V_93 ( V_17 ) ;
enum V_24 V_83 = V_36 ;
int V_94 = 0 ;
F_75 ( & V_87 , 0 , & V_92 ) ;
if ( V_92 > 0 )
return;
if ( F_76 ( V_6 ) || V_6 -> V_14 & V_51 ) {
F_77 ( V_48 ) ;
return;
}
V_83 = F_19 ( V_25 , V_26 , V_13 ,
& V_16 ) ;
V_91 = ( V_83 == V_40 ) ? V_13 : NULL ;
F_60 ( V_83 , V_26 , V_66 , V_91 ) ;
if ( V_95 && V_6 -> V_9 &&
! F_11 ( V_6 , NULL , V_13 ) &&
V_6 -> signal -> V_19 != V_20 ) {
F_35 ( V_6 ) ;
F_47 ( V_6 , V_26 , V_66 , 0 , V_16 , NULL ,
V_13 ,
L_11 ) ;
goto V_89;
}
V_7 = F_32 ( & V_17 , V_16 , V_91 , V_45 ) ;
if ( ! V_7 ) {
F_41 ( NULL , V_26 , V_66 , NULL , V_91 ) ;
F_61 ( L_12 ) ;
}
if ( V_7 != ( void * ) - 1UL ) {
F_47 ( V_7 , V_26 , V_66 , V_17 , V_16 , NULL ,
V_13 , L_13 ) ;
V_94 = 1 ;
}
V_89:
if ( V_94 )
F_78 ( 1 ) ;
}
void F_79 ( void )
{
struct V_25 * V_25 ;
if ( F_80 ( true ) )
return;
V_25 = F_81 ( V_96 , V_97 ) ;
if ( F_66 ( V_25 , V_97 ) ) {
F_74 ( NULL , 0 , 0 , NULL , false ) ;
F_72 ( V_25 , V_97 ) ;
}
}
