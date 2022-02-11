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
enum V_46 F_27 ( struct V_8 * V_47 ,
unsigned long V_20 , const T_1 * V_17 ,
bool V_48 )
{
if ( V_47 -> V_49 )
return V_50 ;
if ( F_13 ( V_47 , NULL , V_17 ) )
return V_50 ;
if ( F_28 ( V_47 , V_51 ) ) {
if ( F_29 ( F_30 ( V_47 ) ) )
F_31 ( V_47 ) ;
if ( ! V_48 )
return V_52 ;
}
if ( ! V_47 -> V_14 )
return V_50 ;
if ( V_47 -> V_18 & V_53 ) {
if ( V_47 == V_5 )
return V_54 ;
else if ( ! V_48 ) {
if ( ! ( V_47 -> V_55 -> V_56 & V_57 ) )
return V_52 ;
}
}
return V_58 ;
}
static struct V_8 * F_32 ( unsigned int * V_59 ,
unsigned long V_20 , const T_1 * V_17 ,
bool V_48 )
{
struct V_8 * V_60 , * V_12 ;
struct V_8 * V_61 = NULL ;
unsigned long V_62 = 0 ;
F_33 () ;
F_34 (g, p) {
unsigned int V_21 ;
switch ( F_27 ( V_12 , V_20 , V_17 ,
V_48 ) ) {
case V_54 :
V_61 = V_12 ;
V_62 = V_63 ;
case V_50 :
continue;
case V_52 :
F_35 () ;
return F_36 ( - 1UL ) ;
case V_58 :
break;
} ;
V_21 = F_16 ( V_12 , NULL , V_17 , V_20 ) ;
if ( V_21 > V_62 ) {
V_61 = V_12 ;
V_62 = V_21 ;
}
} F_37 ( V_60 , V_12 ) ;
if ( V_61 )
F_38 ( V_61 ) ;
F_35 () ;
* V_59 = V_62 * 1000 / V_20 ;
return V_61 ;
}
static void F_39 ( const struct V_15 * V_16 , const T_1 * V_17 )
{
struct V_8 * V_12 ;
struct V_8 * V_47 ;
F_40 ( L_1 ) ;
F_33 () ;
F_41 (p) {
if ( F_13 ( V_12 , V_16 , V_17 ) )
continue;
V_47 = F_9 ( V_12 ) ;
if ( ! V_47 ) {
continue;
}
F_40 ( L_2 ,
V_47 -> V_64 , F_42 ( & V_65 , F_43 ( V_47 ) ) ,
V_47 -> V_66 , V_47 -> V_14 -> V_67 , F_17 ( V_47 -> V_14 ) ,
V_47 -> V_14 -> V_24 ,
F_18 ( V_47 -> V_14 , V_25 ) ,
V_47 -> signal -> V_7 , V_47 -> V_68 ) ;
F_12 ( V_47 ) ;
}
F_35 () ;
}
static void F_44 ( struct V_8 * V_12 , T_2 V_29 , int V_69 ,
struct V_15 * V_16 , const T_1 * V_17 )
{
F_10 ( V_5 ) ;
F_45 ( L_3
L_4 ,
V_5 -> V_68 , V_29 , V_69 ,
V_5 -> signal -> V_7 ) ;
F_46 ( V_5 ) ;
F_12 ( V_5 ) ;
F_47 () ;
F_48 ( V_16 , V_12 ) ;
F_49 ( V_70 ) ;
if ( V_71 )
F_39 ( V_16 , V_17 ) ;
}
void F_50 ( struct V_8 * V_12 , T_2 V_29 , int V_69 ,
unsigned int V_21 , unsigned long V_20 ,
struct V_15 * V_16 , T_1 * V_17 ,
const char * V_72 )
{
struct V_8 * V_73 = V_12 ;
struct V_8 * V_74 ;
struct V_8 * V_13 = V_12 ;
struct V_75 * V_14 ;
unsigned int V_76 = 0 ;
static F_51 ( V_77 , V_78 ,
V_79 ) ;
if ( V_12 -> V_18 & V_53 ) {
F_52 ( V_12 , V_51 ) ;
F_53 ( V_12 ) ;
return;
}
if ( F_54 ( & V_77 ) )
F_44 ( V_12 , V_29 , V_69 , V_16 , V_17 ) ;
F_10 ( V_12 ) ;
F_55 ( L_5 ,
V_72 , F_56 ( V_12 ) , V_12 -> V_68 , V_21 ) ;
F_12 ( V_12 ) ;
F_57 ( & V_80 ) ;
do {
F_58 (child, &t->children, sibling) {
unsigned int V_81 ;
if ( V_74 -> V_14 == V_12 -> V_14 )
continue;
V_81 = F_16 ( V_74 , V_16 , V_17 ,
V_20 ) ;
if ( V_81 > V_76 ) {
F_53 ( V_73 ) ;
V_73 = V_74 ;
V_76 = V_81 ;
F_38 ( V_73 ) ;
}
}
} while_each_thread(p, t) ;
int F_59 ( struct V_82 * V_83 )
{
return F_60 ( & V_84 , V_83 ) ;
}
int F_61 ( struct V_82 * V_83 )
{
return F_62 ( & V_84 , V_83 ) ;
}
int F_63 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
int V_85 = 1 ;
F_64 ( & V_86 ) ;
F_65 (zone, z, zonelist, gfp_zone(gfp_mask)) {
if ( F_66 ( V_30 ) ) {
V_85 = 0 ;
goto V_87;
}
}
F_65 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_67 ( V_30 , V_88 ) ;
}
V_87:
F_68 ( & V_86 ) ;
return V_85 ;
}
void F_69 ( struct V_28 * V_28 , T_2 V_29 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 ;
F_64 ( & V_86 ) ;
F_65 (zone, z, zonelist, gfp_zone(gfp_mask)) {
F_70 ( V_30 , V_88 ) ;
}
F_68 ( & V_86 ) ;
}
static int F_71 ( void )
{
struct V_30 * V_30 ;
int V_85 = 1 ;
F_64 ( & V_86 ) ;
F_72 (zone)
if ( F_66 ( V_30 ) ) {
V_85 = 0 ;
goto V_87;
}
F_72 (zone)
F_67 ( V_30 , V_88 ) ;
V_87:
F_68 ( & V_86 ) ;
return V_85 ;
}
static void F_73 ( void )
{
struct V_30 * V_30 ;
F_64 ( & V_86 ) ;
F_72 (zone)
F_70 ( V_30 , V_88 ) ;
F_68 ( & V_86 ) ;
}
void F_74 ( struct V_28 * V_28 , T_2 V_29 ,
int V_69 , T_1 * V_17 , bool V_48 )
{
const T_1 * V_89 ;
struct V_8 * V_12 ;
unsigned long V_20 ;
unsigned long V_90 = 0 ;
unsigned int V_91 ( V_21 ) ;
enum V_27 V_92 = V_39 ;
int V_93 = 0 ;
F_75 ( & V_84 , 0 , & V_90 ) ;
if ( V_90 > 0 )
return;
if ( F_76 ( V_5 ) ) {
F_77 ( V_51 ) ;
return;
}
V_92 = F_20 ( V_28 , V_29 , V_17 ,
& V_20 ) ;
V_89 = ( V_92 == V_43 ) ? V_17 : NULL ;
F_78 ( V_92 , V_29 , V_69 , V_89 ) ;
if ( V_94 && V_5 -> V_14 &&
! F_13 ( V_5 , NULL , V_17 ) &&
V_5 -> signal -> V_7 != V_23 ) {
F_38 ( V_5 ) ;
F_50 ( V_5 , V_29 , V_69 , 0 , V_20 , NULL ,
V_17 ,
L_6 ) ;
goto V_87;
}
V_12 = F_32 ( & V_21 , V_20 , V_89 , V_48 ) ;
if ( ! V_12 ) {
F_44 ( NULL , V_29 , V_69 , NULL , V_89 ) ;
F_79 ( L_7 ) ;
}
if ( F_80 ( V_12 ) != - 1UL ) {
F_50 ( V_12 , V_29 , V_69 , V_21 , V_20 , NULL ,
V_17 , L_8 ) ;
V_93 = 1 ;
}
V_87:
if ( V_93 )
F_81 ( 1 ) ;
}
void F_82 ( void )
{
if ( F_71 () ) {
F_74 ( NULL , 0 , 0 , NULL , false ) ;
F_73 () ;
}
F_81 ( 1 ) ;
}
