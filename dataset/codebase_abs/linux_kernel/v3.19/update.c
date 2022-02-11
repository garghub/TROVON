void F_1 ( void )
{
V_1 -> V_2 ++ ;
F_2 () ;
}
void F_3 ( void )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_2 != 1 ) {
-- V_4 -> V_2 ;
} else {
F_2 () ;
V_4 -> V_2 = V_5 ;
F_2 () ;
if ( F_4 ( F_5 ( V_4 -> V_6 . V_7 ) ) )
V_6 ( V_4 ) ;
F_2 () ;
V_4 -> V_2 = 0 ;
}
#ifdef F_6
{
int V_8 = F_5 ( V_4 -> V_2 ) ;
F_7 ( V_8 < 0 && V_8 > V_5 / 2 ) ;
}
#endif
}
int T_1 F_8 ( void )
{
return V_9 && V_10 &&
V_1 -> V_11 == 0 ;
}
int F_9 ( void )
{
if ( ! F_8 () )
return 1 ;
if ( ! F_10 () )
return 0 ;
if ( ! F_11 () )
return 0 ;
return F_12 ( & V_12 ) ;
}
int F_13 ( void )
{
if ( ! F_8 () )
return 1 ;
if ( ! F_10 () )
return 0 ;
if ( ! F_11 () )
return 0 ;
return F_14 () || F_15 () ;
}
static void F_16 ( struct V_13 * V_14 )
{
struct V_15 * V_16 ;
V_16 = F_17 ( V_14 , struct V_15 , V_14 ) ;
F_18 ( & V_16 -> V_17 ) ;
}
void F_19 ( T_2 V_18 )
{
struct V_15 V_16 ;
F_20 ( & V_16 . V_14 ) ;
F_21 ( & V_16 . V_17 ) ;
V_18 ( & V_16 . V_14 , F_16 ) ;
F_22 ( & V_16 . V_17 ) ;
F_23 ( & V_16 . V_14 ) ;
}
void F_24 ( struct V_13 * V_14 )
{
F_25 ( V_14 , & V_19 ) ;
}
void F_26 ( struct V_13 * V_14 )
{
F_27 ( V_14 , & V_19 ) ;
}
static int F_28 ( void * V_20 , enum V_21 V_22 )
{
struct V_13 * V_14 = V_20 ;
switch ( V_22 ) {
case V_23 :
F_25 ( V_14 , & V_19 ) ;
F_29 ( V_14 , & V_19 ) ;
return 0 ;
default:
return 1 ;
}
}
void F_20 ( struct V_13 * V_14 )
{
F_30 ( V_14 , & V_19 ) ;
}
void F_23 ( struct V_13 * V_14 )
{
F_27 ( V_14 , & V_19 ) ;
}
void F_31 ( const char * V_24 , struct V_13 * V_25 ,
unsigned long V_26 ,
unsigned long V_27 , unsigned long V_28 )
{
F_32 ( V_24 , V_25 , V_26 , V_27 , V_28 ) ;
}
int F_33 ( void )
{
int V_29 = F_5 ( V_30 ) ;
if ( V_29 < 3 ) {
F_5 ( V_30 ) = 3 ;
V_29 = 3 ;
} else if ( V_29 > 300 ) {
F_5 ( V_30 ) = 300 ;
V_29 = 300 ;
}
return V_29 * V_31 + V_32 ;
}
void F_34 ( void )
{
if ( ! V_33 )
V_33 = 2 ;
}
void F_35 ( void )
{
if ( V_33 == 2 )
V_33 = 0 ;
}
static int F_36 ( struct V_34 * V_35 , unsigned long V_36 , void * V_37 )
{
V_33 = 1 ;
return V_38 ;
}
static int T_3 F_37 ( void )
{
F_38 ( & V_39 , & V_40 ) ;
return 0 ;
}
void F_39 ( struct V_13 * V_25 , void (* F_40)( struct V_13 * V_25 ) )
{
unsigned long V_41 ;
bool V_42 ;
V_25 -> V_43 = NULL ;
V_25 -> F_40 = F_40 ;
F_41 ( & V_44 , V_41 ) ;
V_42 = ! V_45 ;
* V_46 = V_25 ;
V_46 = & V_25 -> V_43 ;
F_42 ( & V_44 , V_41 ) ;
if ( V_42 ) {
F_43 () ;
F_44 ( & V_47 ) ;
}
}
void F_45 ( void )
{
F_46 ( ! V_9 ,
L_1 ) ;
F_19 ( F_39 ) ;
}
void F_47 ( void )
{
F_45 () ;
}
static void F_48 ( struct V_3 * V_4 ,
bool V_48 , bool * V_49 )
{
int V_50 ;
if ( ! F_5 ( V_4 -> V_51 ) ||
V_4 -> V_52 != F_5 ( V_4 -> V_53 ) ||
! F_5 ( V_4 -> V_54 ) ||
( F_49 ( V_55 ) &&
! F_50 ( V_4 ) && V_4 -> V_56 >= 0 ) ) {
F_5 ( V_4 -> V_51 ) = false ;
F_51 ( & V_4 -> V_57 ) ;
F_52 ( V_4 ) ;
return;
}
if ( ! V_48 )
return;
if ( * V_49 ) {
F_53 ( L_2 ) ;
* V_49 = false ;
}
V_50 = F_54 ( V_4 ) ;
F_55 ( L_3 ,
V_4 , L_4 [ F_50 ( V_4 ) ] ,
L_5 [ V_50 < 0 || ! F_56 ( V_50 ) ] ,
V_4 -> V_52 , V_4 -> V_53 , V_4 -> V_51 ,
V_4 -> V_56 , V_50 ) ;
F_57 ( V_4 ) ;
}
static int T_4 F_58 ( void * V_58 )
{
unsigned long V_41 ;
struct V_3 * V_59 , * V_4 ;
unsigned long V_60 ;
struct V_13 * V_61 ;
struct V_13 * V_43 ;
F_59 ( V_62 ) ;
F_60 ( V_1 ) ;
for (; ; ) {
F_41 ( & V_44 , V_41 ) ;
V_61 = V_45 ;
V_45 = NULL ;
V_46 = & V_45 ;
F_42 ( & V_44 , V_41 ) ;
if ( ! V_61 ) {
F_61 ( V_47 ,
V_45 ) ;
if ( ! V_45 ) {
F_62 ( F_63 ( V_1 ) ) ;
F_64 ( V_31 / 10 ) ;
}
continue;
}
F_65 () ;
F_66 () ;
F_67 (g, t) {
if ( V_4 != V_1 && F_5 ( V_4 -> V_54 ) &&
! F_50 ( V_4 ) ) {
F_68 ( V_4 ) ;
V_4 -> V_52 = F_5 ( V_4 -> V_53 ) ;
F_5 ( V_4 -> V_51 ) = true ;
F_69 ( & V_4 -> V_57 ,
& V_62 ) ;
}
}
F_70 () ;
F_71 ( & V_63 ) ;
V_60 = V_64 ;
while ( ! F_72 ( & V_62 ) ) {
bool V_49 ;
bool V_48 ;
int V_65 ;
struct V_3 * V_66 ;
F_64 ( V_31 ) ;
V_65 = F_5 ( V_67 ) ;
V_48 = V_65 > 0 &&
F_73 ( V_64 , V_60 + V_65 ) ;
if ( V_48 )
V_60 = V_64 ;
V_49 = true ;
F_62 ( F_63 ( V_1 ) ) ;
F_74 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_48 ( V_4 , V_48 , & V_49 ) ;
F_75 () ;
}
}
F_65 () ;
while ( V_61 ) {
V_43 = V_61 -> V_43 ;
F_76 () ;
V_61 -> F_40 ( V_61 ) ;
F_77 () ;
V_61 = V_43 ;
F_75 () ;
}
F_78 ( V_31 / 10 ) ;
}
}
static void F_43 ( void )
{
static F_79 ( V_68 ) ;
static struct V_3 * V_69 ;
struct V_3 * V_4 ;
if ( F_5 ( V_69 ) ) {
F_80 () ;
return;
}
F_81 ( & V_68 ) ;
if ( V_69 ) {
F_82 ( & V_68 ) ;
return;
}
V_4 = F_83 ( F_58 , NULL , L_6 ) ;
F_84 ( F_85 ( V_4 ) ) ;
F_80 () ;
F_5 ( V_69 ) = V_4 ;
F_82 ( & V_68 ) ;
}
static void F_86 ( struct V_13 * V_70 )
{
V_71 ++ ;
F_87 ( L_7 , V_71 ) ;
}
static void F_88 ( void )
{
static struct V_13 V_14 ;
F_89 ( & V_14 , F_86 ) ;
}
static void F_90 ( void )
{
static struct V_13 V_14 ;
F_91 ( & V_14 , F_86 ) ;
}
static void F_92 ( void )
{
static struct V_13 V_14 ;
F_93 ( & V_14 , F_86 ) ;
}
void F_94 ( void )
{
F_87 ( L_8 ) ;
if ( V_72 )
F_88 () ;
if ( V_73 )
F_90 () ;
if ( V_74 )
F_92 () ;
}
static int F_95 ( void )
{
int V_75 = 0 ;
int V_76 = 0 ;
if ( V_72 ) {
V_76 ++ ;
F_96 () ;
}
if ( V_73 ) {
V_76 ++ ;
F_97 () ;
}
if ( V_74 ) {
V_76 ++ ;
F_98 () ;
}
if ( V_71 != V_76 ) {
F_62 ( 1 ) ;
V_75 = - 1 ;
}
return V_75 ;
}
void F_94 ( void ) {}
