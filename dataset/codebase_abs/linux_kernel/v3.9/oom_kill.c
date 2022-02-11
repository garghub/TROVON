static bool F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
struct V_1 * V_4 = V_2 ;
do {
if ( V_3 ) {
if ( F_2 ( V_2 , V_3 ) )
return true ;
} else {
if ( F_3 ( V_5 , V_2 ) )
return true ;
}
} while_each_thread(start, tsk) ;
bool F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 )
{
return true ;
}
struct V_1 * F_4 ( struct V_1 * V_6 )
{
struct V_1 * V_7 = V_6 ;
do {
F_5 ( V_7 ) ;
if ( F_6 ( V_7 -> V_8 ) )
return V_7 ;
F_7 ( V_7 ) ;
} while_each_thread(p, t) ;
bool F_8 ( struct V_1 * V_6 ,
const struct V_9 * V_10 , const T_1 * V_11 )
{
if ( F_9 ( V_6 ) )
return true ;
if ( V_6 -> V_12 & V_13 )
return true ;
if ( V_10 && ! F_10 ( V_6 , V_10 ) )
return true ;
if ( ! F_1 ( V_6 , V_11 ) )
return true ;
return false ;
}
unsigned long F_11 ( struct V_1 * V_6 , struct V_9 * V_10 ,
const T_1 * V_11 , unsigned long V_14 )
{
long V_15 ;
long V_16 ;
if ( F_8 ( V_6 , V_10 , V_11 ) )
return 0 ;
V_6 = F_4 ( V_6 ) ;
if ( ! V_6 )
return 0 ;
V_16 = ( long ) V_6 -> signal -> V_17 ;
if ( V_16 == V_18 ) {
F_7 ( V_6 ) ;
return 0 ;
}
V_15 = F_12 ( V_6 -> V_8 ) + V_6 -> V_8 -> V_19 +
F_13 ( V_6 -> V_8 , V_20 ) ;
F_7 ( V_6 ) ;
if ( F_14 ( V_6 , V_21 ) )
V_16 -= 30 ;
V_16 *= V_14 / 1000 ;
V_15 += V_16 ;
return V_15 > 0 ? V_15 : 1 ;
}
static enum V_22 F_15 ( struct V_23 * V_23 ,
T_2 V_24 , T_1 * V_11 ,
unsigned long * V_14 )
{
struct V_25 * V_25 ;
struct V_26 * V_27 ;
enum V_28 V_29 = F_16 ( V_24 ) ;
bool V_30 = false ;
int V_31 ;
* V_14 = V_32 + V_33 ;
if ( ! V_23 )
return V_34 ;
if ( V_24 & V_35 )
return V_34 ;
if ( V_11 && ! F_17 ( V_36 [ V_37 ] , * V_11 ) ) {
* V_14 = V_33 ;
F_18 ( V_31 , * V_11 )
* V_14 += F_19 ( V_31 ) ;
return V_38 ;
}
F_20 (zone, z, zonelist,
high_zoneidx, nodemask)
if ( ! F_21 ( V_25 , V_24 ) )
V_30 = true ;
if ( V_30 ) {
* V_14 = V_33 ;
F_18 ( V_31 , V_39 )
* V_14 += F_19 ( V_31 ) ;
return V_40 ;
}
return V_34 ;
}
static enum V_22 F_15 ( struct V_23 * V_23 ,
T_2 V_24 , T_1 * V_11 ,
unsigned long * V_14 )
{
* V_14 = V_32 + V_33 ;
return V_34 ;
}
enum V_41 F_22 ( struct V_1 * V_42 ,
unsigned long V_14 , const T_1 * V_11 ,
bool V_43 )
{
if ( V_42 -> V_44 )
return V_45 ;
if ( F_8 ( V_42 , NULL , V_11 ) )
return V_45 ;
if ( F_23 ( V_42 , V_46 ) ) {
if ( F_24 ( F_25 ( V_42 ) ) )
F_26 ( V_42 ) ;
if ( ! V_43 )
return V_47 ;
}
if ( ! V_42 -> V_8 )
return V_45 ;
if ( F_27 ( V_42 ) )
return V_48 ;
if ( V_42 -> V_12 & V_49 && ! V_43 ) {
if ( ! ( V_42 -> V_50 -> V_51 & V_52 ) )
return V_47 ;
}
return V_53 ;
}
static struct V_1 * F_28 ( unsigned int * V_54 ,
unsigned long V_14 , const T_1 * V_11 ,
bool V_43 )
{
struct V_1 * V_55 , * V_6 ;
struct V_1 * V_56 = NULL ;
unsigned long V_57 = 0 ;
F_29 () ;
F_30 (g, p) {
unsigned int V_15 ;
switch ( F_22 ( V_6 , V_14 , V_11 ,
V_43 ) ) {
case V_48 :
V_56 = V_6 ;
V_57 = V_58 ;
case V_45 :
continue;
case V_47 :
F_31 () ;
return F_32 ( - 1UL ) ;
case V_53 :
break;
} ;
V_15 = F_11 ( V_6 , NULL , V_11 , V_14 ) ;
if ( V_15 > V_57 ) {
V_56 = V_6 ;
V_57 = V_15 ;
}
} F_33 ( V_55 , V_6 ) ;
if ( V_56 )
F_34 ( V_56 ) ;
F_31 () ;
* V_54 = V_57 * 1000 / V_14 ;
return V_56 ;
}
static void F_35 ( const struct V_9 * V_10 , const T_1 * V_11 )
{
struct V_1 * V_6 ;
struct V_1 * V_42 ;
F_36 ( L_1 ) ;
F_29 () ;
F_37 (p) {
if ( F_8 ( V_6 , V_10 , V_11 ) )
continue;
V_42 = F_4 ( V_6 ) ;
if ( ! V_42 ) {
continue;
}
F_36 ( L_2 ,
V_42 -> V_59 , F_38 ( & V_60 , F_39 ( V_42 ) ) ,
V_42 -> V_61 , V_42 -> V_8 -> V_62 , F_12 ( V_42 -> V_8 ) ,
V_42 -> V_8 -> V_19 ,
F_13 ( V_42 -> V_8 , V_20 ) ,
V_42 -> signal -> V_17 , V_42 -> V_63 ) ;
F_7 ( V_42 ) ;
}
F_31 () ;
}
static void F_40 ( struct V_1 * V_6 , T_2 V_24 , int V_64 ,
struct V_9 * V_10 , const T_1 * V_11 )
{
F_5 ( V_5 ) ;
F_41 ( L_3
L_4 ,
V_5 -> V_63 , V_24 , V_64 ,
V_5 -> signal -> V_17 ) ;
F_42 ( V_5 ) ;
F_7 ( V_5 ) ;
F_43 () ;
if ( V_10 )
F_44 ( V_10 , V_6 ) ;
else
F_45 ( V_65 ) ;
if ( V_66 )
F_35 ( V_10 , V_11 ) ;
}
void F_46 ( struct V_1 * V_6 , T_2 V_24 , int V_64 ,
unsigned int V_15 , unsigned long V_14 ,
struct V_9 * V_10 , T_1 * V_11 ,
const char * V_67 )
{
struct V_1 * V_68 = V_6 ;
struct V_1 * V_69 ;
struct V_1 * V_7 = V_6 ;
struct V_70 * V_8 ;
unsigned int V_71 = 0 ;
static F_47 ( V_72 , V_73 ,
V_74 ) ;
if ( V_6 -> V_12 & V_49 ) {
F_48 ( V_6 , V_46 ) ;
F_49 ( V_6 ) ;
return;
}
if ( F_50 ( & V_72 ) )
F_40 ( V_6 , V_24 , V_64 , V_10 , V_11 ) ;
F_5 ( V_6 ) ;
F_51 ( L_5 ,
V_67 , F_52 ( V_6 ) , V_6 -> V_63 , V_15 ) ;
F_7 ( V_6 ) ;
F_53 ( & V_75 ) ;
do {
F_54 (child, &t->children, sibling) {
unsigned int V_76 ;
if ( V_69 -> V_8 == V_6 -> V_8 )
continue;
V_76 = F_11 ( V_69 , V_10 , V_11 ,
V_14 ) ;
if ( V_76 > V_71 ) {
F_49 ( V_68 ) ;
V_68 = V_69 ;
V_71 = V_76 ;
F_34 ( V_68 ) ;
}
}
} while_each_thread(p, t) ;
int F_55 ( struct V_77 * V_78 )
{
return F_56 ( & V_79 , V_78 ) ;
}
int F_57 ( struct V_77 * V_78 )
{
return F_58 ( & V_79 , V_78 ) ;
}
int F_59 ( struct V_23 * V_23 , T_2 V_24 )
{
struct V_26 * V_27 ;
struct V_25 * V_25 ;
int V_80 = 1 ;
F_60 ( & V_81 ) ;
F_61 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_62 ( V_25 ) ) {
V_80 = 0 ;
goto V_82;
}
}
F_61 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_63 ( V_25 , V_83 ) ;
}
V_82:
F_64 ( & V_81 ) ;
return V_80 ;
}
void F_65 ( struct V_23 * V_23 , T_2 V_24 )
{
struct V_26 * V_27 ;
struct V_25 * V_25 ;
F_60 ( & V_81 ) ;
F_61 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_66 ( V_25 , V_83 ) ;
}
F_64 ( & V_81 ) ;
}
void F_67 ( struct V_23 * V_23 , T_2 V_24 ,
int V_64 , T_1 * V_11 , bool V_43 )
{
const T_1 * V_84 ;
struct V_1 * V_6 ;
unsigned long V_14 ;
unsigned long V_85 = 0 ;
unsigned int V_86 ( V_15 ) ;
enum V_22 V_87 = V_34 ;
int V_88 = 0 ;
F_68 ( & V_79 , 0 , & V_85 ) ;
if ( V_85 > 0 )
return;
if ( F_69 ( V_5 ) || V_5 -> V_12 & V_49 ) {
F_70 ( V_46 ) ;
return;
}
V_87 = F_15 ( V_23 , V_24 , V_11 ,
& V_14 ) ;
V_84 = ( V_87 == V_38 ) ? V_11 : NULL ;
F_71 ( V_87 , V_24 , V_64 , V_84 ) ;
if ( V_89 && V_5 -> V_8 &&
! F_8 ( V_5 , NULL , V_11 ) &&
V_5 -> signal -> V_17 != V_18 ) {
F_34 ( V_5 ) ;
F_46 ( V_5 , V_24 , V_64 , 0 , V_14 , NULL ,
V_11 ,
L_6 ) ;
goto V_82;
}
V_6 = F_28 ( & V_15 , V_14 , V_84 , V_43 ) ;
if ( ! V_6 ) {
F_40 ( NULL , V_24 , V_64 , NULL , V_84 ) ;
F_72 ( L_7 ) ;
}
if ( F_73 ( V_6 ) != - 1UL ) {
F_46 ( V_6 , V_24 , V_64 , V_15 , V_14 , NULL ,
V_11 , L_8 ) ;
V_88 = 1 ;
}
V_82:
if ( V_88 )
F_74 ( 1 ) ;
}
void F_75 ( void )
{
struct V_23 * V_23 = F_76 ( V_90 ,
V_91 ) ;
if ( F_59 ( V_23 , V_91 ) ) {
F_67 ( NULL , 0 , 0 , NULL , false ) ;
F_65 ( V_23 , V_91 ) ;
}
}
