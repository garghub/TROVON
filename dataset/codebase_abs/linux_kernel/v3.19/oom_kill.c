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
if ( F_11 ( V_44 , NULL , V_13 ) )
return V_46 ;
if ( F_27 ( V_44 , V_47 ) ) {
if ( F_28 ( F_29 ( V_44 ) ) )
F_30 ( V_44 ) ;
if ( ! V_45 )
return V_48 ;
}
if ( ! V_44 -> V_9 )
return V_46 ;
if ( F_31 ( V_44 ) )
return V_49 ;
if ( F_32 ( V_44 ) && ! V_45 )
return V_48 ;
return V_50 ;
}
static struct V_1 * F_33 ( unsigned int * V_51 ,
unsigned long V_16 , const T_1 * V_13 ,
bool V_45 )
{
struct V_1 * V_52 , * V_7 ;
struct V_1 * V_53 = NULL ;
unsigned long V_54 = 0 ;
F_2 () ;
F_34 (g, p) {
unsigned int V_17 ;
switch ( F_26 ( V_7 , V_16 , V_13 ,
V_45 ) ) {
case V_49 :
V_53 = V_7 ;
V_54 = V_55 ;
case V_46 :
continue;
case V_48 :
F_6 () ;
return (struct V_1 * ) ( - 1UL ) ;
case V_50 :
break;
} ;
V_17 = F_14 ( V_7 , NULL , V_13 , V_16 ) ;
if ( ! V_17 || V_17 < V_54 )
continue;
if ( V_17 == V_54 && F_35 ( V_53 ) )
continue;
V_53 = V_7 ;
V_54 = V_17 ;
}
if ( V_53 )
F_36 ( V_53 ) ;
F_6 () ;
* V_51 = V_54 * 1000 / V_16 ;
return V_53 ;
}
static void F_37 ( struct V_11 * V_12 , const T_1 * V_13 )
{
struct V_1 * V_7 ;
struct V_1 * V_44 ;
F_38 ( L_1 ) ;
F_2 () ;
F_39 (p) {
if ( F_11 ( V_7 , V_12 , V_13 ) )
continue;
V_44 = F_7 ( V_7 ) ;
if ( ! V_44 ) {
continue;
}
F_38 ( L_2 ,
V_44 -> V_56 , F_40 ( & V_57 , F_41 ( V_44 ) ) ,
V_44 -> V_58 , V_44 -> V_9 -> V_59 , F_15 ( V_44 -> V_9 ) ,
F_16 ( & V_44 -> V_9 -> V_21 ) ,
F_17 ( V_44 -> V_9 , V_22 ) ,
V_44 -> signal -> V_19 , V_44 -> V_60 ) ;
F_10 ( V_44 ) ;
}
F_6 () ;
}
static void F_42 ( struct V_1 * V_7 , T_2 V_26 , int V_61 ,
struct V_11 * V_12 , const T_1 * V_13 )
{
F_8 ( V_6 ) ;
F_43 ( L_3
L_4 ,
V_6 -> V_60 , V_26 , V_61 ,
V_6 -> signal -> V_19 ) ;
F_44 ( V_6 ) ;
F_10 ( V_6 ) ;
F_45 () ;
if ( V_12 )
F_46 ( V_12 , V_7 ) ;
else
F_47 ( V_62 ) ;
if ( V_63 )
F_37 ( V_12 , V_13 ) ;
}
int F_48 ( void )
{
return F_49 ( & V_64 ) ;
}
void F_50 ( void )
{
F_51 ( & V_64 ) ;
}
void F_52 ( struct V_1 * V_7 , T_2 V_26 , int V_61 ,
unsigned int V_17 , unsigned long V_16 ,
struct V_11 * V_12 , T_1 * V_13 ,
const char * V_65 )
{
struct V_1 * V_66 = V_7 ;
struct V_1 * V_67 ;
struct V_1 * V_8 ;
struct V_68 * V_9 ;
unsigned int V_69 = 0 ;
static F_53 ( V_70 , V_71 ,
V_72 ) ;
if ( F_32 ( V_7 ) ) {
F_54 ( V_7 , V_47 ) ;
F_55 ( V_7 ) ;
return;
}
if ( F_56 ( & V_70 ) )
F_42 ( V_7 , V_26 , V_61 , V_12 , V_13 ) ;
F_8 ( V_7 ) ;
F_57 ( L_5 ,
V_65 , F_58 ( V_7 ) , V_7 -> V_60 , V_17 ) ;
F_10 ( V_7 ) ;
F_59 ( & V_73 ) ;
F_3 (p, t) {
F_60 (child, &t->children, sibling) {
unsigned int V_74 ;
if ( V_67 -> V_9 == V_7 -> V_9 )
continue;
V_74 = F_14 ( V_67 , V_12 , V_13 ,
V_16 ) ;
if ( V_74 > V_69 ) {
F_55 ( V_66 ) ;
V_66 = V_67 ;
V_69 = V_74 ;
F_36 ( V_66 ) ;
}
}
}
F_61 ( & V_73 ) ;
V_7 = F_7 ( V_66 ) ;
if ( ! V_7 ) {
F_55 ( V_66 ) ;
return;
} else if ( V_66 != V_7 ) {
F_36 ( V_7 ) ;
F_55 ( V_66 ) ;
V_66 = V_7 ;
}
V_9 = V_66 -> V_9 ;
F_57 ( L_6 ,
F_58 ( V_66 ) , V_66 -> V_60 , F_62 ( V_66 -> V_9 -> V_59 ) ,
F_62 ( F_17 ( V_66 -> V_9 , V_75 ) ) ,
F_62 ( F_17 ( V_66 -> V_9 , V_76 ) ) ) ;
F_10 ( V_66 ) ;
F_2 () ;
F_39 (p)
if ( V_7 -> V_9 == V_9 && ! F_63 ( V_7 , V_66 ) &&
! ( V_7 -> V_14 & V_15 ) ) {
if ( V_7 -> signal -> V_19 == V_20 )
continue;
F_8 ( V_7 ) ;
F_57 ( L_7 ,
F_58 ( V_7 ) , V_7 -> V_60 ) ;
F_10 ( V_7 ) ;
F_64 ( V_77 , V_78 , V_7 , true ) ;
}
F_6 () ;
F_54 ( V_66 , V_47 ) ;
F_64 ( V_77 , V_78 , V_66 , true ) ;
F_55 ( V_66 ) ;
}
void F_65 ( enum V_24 V_79 , T_2 V_26 ,
int V_61 , const T_1 * V_13 )
{
if ( F_9 ( ! V_80 ) )
return;
if ( V_80 != 2 ) {
if ( V_79 != V_36 )
return;
}
F_42 ( NULL , V_26 , V_61 , NULL , V_13 ) ;
F_66 ( L_8 ,
V_80 == 2 ? L_9 : L_10 ) ;
}
int F_67 ( struct V_81 * V_82 )
{
return F_68 ( & V_83 , V_82 ) ;
}
int F_69 ( struct V_81 * V_82 )
{
return F_70 ( & V_83 , V_82 ) ;
}
bool F_71 ( struct V_25 * V_25 , T_2 V_26 )
{
struct V_28 * V_29 ;
struct V_27 * V_27 ;
bool V_5 = true ;
F_72 ( & V_84 ) ;
F_73 (zone, z, zonelist, gfp_zone(gfp_mask))
if ( F_74 ( V_85 , & V_27 -> V_14 ) ) {
V_5 = false ;
goto V_86;
}
F_73 (zone, z, zonelist, gfp_zone(gfp_mask))
F_75 ( V_85 , & V_27 -> V_14 ) ;
V_86:
F_76 ( & V_84 ) ;
return V_5 ;
}
void F_77 ( struct V_25 * V_25 , T_2 V_26 )
{
struct V_28 * V_29 ;
struct V_27 * V_27 ;
F_72 ( & V_84 ) ;
F_73 (zone, z, zonelist, gfp_zone(gfp_mask))
F_78 ( V_85 , & V_27 -> V_14 ) ;
F_76 ( & V_84 ) ;
}
void F_79 ( struct V_25 * V_25 , T_2 V_26 ,
int V_61 , T_1 * V_13 , bool V_45 )
{
const T_1 * V_87 ;
struct V_1 * V_7 ;
unsigned long V_16 ;
unsigned long V_88 = 0 ;
unsigned int V_89 ( V_17 ) ;
enum V_24 V_79 = V_36 ;
int V_90 = 0 ;
F_80 ( & V_83 , 0 , & V_88 ) ;
if ( V_88 > 0 )
return;
if ( F_81 ( V_6 ) || F_32 ( V_6 ) ) {
F_82 ( V_47 ) ;
return;
}
V_79 = F_19 ( V_25 , V_26 , V_13 ,
& V_16 ) ;
V_87 = ( V_79 == V_40 ) ? V_13 : NULL ;
F_65 ( V_79 , V_26 , V_61 , V_87 ) ;
if ( V_91 && V_6 -> V_9 &&
! F_11 ( V_6 , NULL , V_13 ) &&
V_6 -> signal -> V_19 != V_20 ) {
F_36 ( V_6 ) ;
F_52 ( V_6 , V_26 , V_61 , 0 , V_16 , NULL ,
V_13 ,
L_11 ) ;
goto V_86;
}
V_7 = F_33 ( & V_17 , V_16 , V_87 , V_45 ) ;
if ( ! V_7 ) {
F_42 ( NULL , V_26 , V_61 , NULL , V_87 ) ;
F_66 ( L_12 ) ;
}
if ( V_7 != ( void * ) - 1UL ) {
F_52 ( V_7 , V_26 , V_61 , V_17 , V_16 , NULL ,
V_13 , L_13 ) ;
V_90 = 1 ;
}
V_86:
if ( V_90 )
F_83 ( 1 ) ;
}
void F_84 ( void )
{
struct V_25 * V_25 ;
if ( F_85 ( true ) )
return;
V_25 = F_86 ( V_92 , V_93 ) ;
if ( F_71 ( V_25 , V_93 ) ) {
F_79 ( NULL , 0 , 0 , NULL , false ) ;
F_77 ( V_25 , V_93 ) ;
}
}
