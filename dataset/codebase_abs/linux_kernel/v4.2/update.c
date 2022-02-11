bool F_1 ( void )
{
return V_1 || F_2 ( & V_2 ) ;
}
void F_3 ( void )
{
F_4 ( & V_2 ) ;
}
void F_5 ( void )
{
F_6 ( & V_2 ) ;
}
void F_7 ( void )
{
if ( F_8 ( V_3 ) )
F_5 () ;
}
void F_9 ( void )
{
V_4 -> V_5 ++ ;
F_10 () ;
}
void F_11 ( void )
{
struct V_6 * V_7 = V_4 ;
if ( V_7 -> V_5 != 1 ) {
-- V_7 -> V_5 ;
} else {
F_10 () ;
V_7 -> V_5 = V_8 ;
F_10 () ;
if ( F_12 ( F_13 ( V_7 -> V_9 . V_10 ) ) )
V_9 ( V_7 ) ;
F_10 () ;
V_7 -> V_5 = 0 ;
}
#ifdef F_14
{
int V_11 = F_13 ( V_7 -> V_5 ) ;
F_15 ( V_11 < 0 && V_11 > V_8 / 2 ) ;
}
#endif
}
int T_1 F_16 ( void )
{
return V_12 && V_13 &&
V_4 -> V_14 == 0 ;
}
int F_17 ( void )
{
if ( ! F_16 () )
return 1 ;
if ( ! F_18 () )
return 0 ;
if ( ! F_19 () )
return 0 ;
return F_20 ( & V_15 ) ;
}
int F_21 ( void )
{
if ( ! F_16 () )
return 1 ;
if ( ! F_18 () )
return 0 ;
if ( ! F_19 () )
return 0 ;
return F_22 () || F_23 () ;
}
void F_24 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
V_19 = F_25 ( V_17 , struct V_18 , V_17 ) ;
F_26 ( & V_19 -> V_20 ) ;
}
void F_27 ( T_2 V_21 )
{
struct V_18 V_19 ;
F_28 ( & V_19 . V_17 ) ;
F_29 ( & V_19 . V_20 ) ;
V_21 ( & V_19 . V_17 , F_24 ) ;
F_30 ( & V_19 . V_20 ) ;
F_31 ( & V_19 . V_17 ) ;
}
void F_32 ( struct V_16 * V_17 )
{
F_33 ( V_17 , & V_22 ) ;
}
void F_34 ( struct V_16 * V_17 )
{
F_35 ( V_17 , & V_22 ) ;
}
static int F_36 ( void * V_23 , enum V_24 V_25 )
{
struct V_16 * V_17 = V_23 ;
switch ( V_25 ) {
case V_26 :
F_33 ( V_17 , & V_22 ) ;
F_37 ( V_17 , & V_22 ) ;
return 0 ;
default:
return 1 ;
}
}
void F_28 ( struct V_16 * V_17 )
{
F_38 ( V_17 , & V_22 ) ;
}
void F_31 ( struct V_16 * V_17 )
{
F_35 ( V_17 , & V_22 ) ;
}
void F_39 ( const char * V_27 , struct V_16 * V_28 ,
unsigned long V_29 ,
unsigned long V_30 , unsigned long V_31 )
{
F_40 ( V_27 , V_28 , V_29 , V_30 , V_31 ) ;
}
int F_41 ( void )
{
int V_32 = F_13 ( V_33 ) ;
if ( V_32 < 3 ) {
F_42 ( V_33 , 3 ) ;
V_32 = 3 ;
} else if ( V_32 > 300 ) {
F_42 ( V_33 , 300 ) ;
V_32 = 300 ;
}
return V_32 * V_34 + V_35 ;
}
void F_43 ( void )
{
if ( ! V_36 )
V_36 = 2 ;
}
void F_44 ( void )
{
if ( V_36 == 2 )
V_36 = 0 ;
}
static int F_45 ( struct V_37 * V_38 , unsigned long V_39 , void * V_40 )
{
V_36 = 1 ;
return V_41 ;
}
static int T_3 F_46 ( void )
{
F_47 ( & V_42 , & V_43 ) ;
return 0 ;
}
void F_48 ( struct V_16 * V_28 , void (* F_49)( struct V_16 * V_28 ) )
{
unsigned long V_44 ;
bool V_45 ;
V_28 -> V_46 = NULL ;
V_28 -> F_49 = F_49 ;
F_50 ( & V_47 , V_44 ) ;
V_45 = ! V_48 ;
* V_49 = V_28 ;
V_49 = & V_28 -> V_46 ;
F_51 ( & V_47 , V_44 ) ;
if ( V_45 ) {
F_52 () ;
F_53 ( & V_50 ) ;
}
}
void F_54 ( void )
{
F_55 ( ! V_12 ,
L_1 ) ;
F_27 ( F_48 ) ;
}
void F_56 ( void )
{
F_54 () ;
}
static void F_57 ( struct V_6 * V_7 ,
bool V_51 , bool * V_52 )
{
int V_53 ;
if ( ! F_13 ( V_7 -> V_54 ) ||
V_7 -> V_55 != F_13 ( V_7 -> V_56 ) ||
! F_13 ( V_7 -> V_57 ) ||
( F_8 ( V_58 ) &&
! F_58 ( V_7 ) && V_7 -> V_59 >= 0 ) ) {
F_42 ( V_7 -> V_54 , false ) ;
F_59 ( & V_7 -> V_60 ) ;
F_60 ( V_7 ) ;
return;
}
if ( ! V_51 )
return;
if ( * V_52 ) {
F_61 ( L_2 ) ;
* V_52 = false ;
}
V_53 = F_62 ( V_7 ) ;
F_63 ( L_3 ,
V_7 , L_4 [ F_58 ( V_7 ) ] ,
L_5 [ V_53 < 0 || ! F_64 ( V_53 ) ] ,
V_7 -> V_55 , V_7 -> V_56 , V_7 -> V_54 ,
V_7 -> V_59 , V_53 ) ;
F_65 ( V_7 ) ;
}
static int T_4 F_66 ( void * V_61 )
{
unsigned long V_44 ;
struct V_6 * V_62 , * V_7 ;
unsigned long V_63 ;
struct V_16 * V_64 ;
struct V_16 * V_46 ;
F_67 ( V_65 ) ;
F_68 ( V_4 ) ;
for (; ; ) {
F_50 ( & V_47 , V_44 ) ;
V_64 = V_48 ;
V_48 = NULL ;
V_49 = & V_48 ;
F_51 ( & V_47 , V_44 ) ;
if ( ! V_64 ) {
F_69 ( V_50 ,
V_48 ) ;
if ( ! V_48 ) {
F_70 ( F_71 ( V_4 ) ) ;
F_72 ( V_34 / 10 ) ;
}
continue;
}
F_73 () ;
F_74 () ;
F_75 (g, t) {
if ( V_7 != V_4 && F_13 ( V_7 -> V_57 ) &&
! F_58 ( V_7 ) ) {
F_76 ( V_7 ) ;
V_7 -> V_55 = F_13 ( V_7 -> V_56 ) ;
F_42 ( V_7 -> V_54 , true ) ;
F_77 ( & V_7 -> V_60 ,
& V_65 ) ;
}
}
F_78 () ;
F_79 ( & V_66 ) ;
V_63 = V_67 ;
while ( ! F_80 ( & V_65 ) ) {
bool V_52 ;
bool V_51 ;
int V_68 ;
struct V_6 * V_69 ;
F_72 ( V_34 ) ;
V_68 = F_13 ( V_70 ) ;
V_51 = V_68 > 0 &&
F_81 ( V_67 , V_63 + V_68 ) ;
if ( V_51 )
V_63 = V_67 ;
V_52 = true ;
F_70 ( F_71 ( V_4 ) ) ;
F_82 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_57 ( V_7 , V_51 , & V_52 ) ;
F_83 () ;
}
}
F_73 () ;
while ( V_64 ) {
V_46 = V_64 -> V_46 ;
F_84 () ;
V_64 -> F_49 ( V_64 ) ;
F_85 () ;
V_64 = V_46 ;
F_83 () ;
}
F_86 ( V_34 / 10 ) ;
}
}
static void F_52 ( void )
{
static F_87 ( V_71 ) ;
static struct V_6 * V_72 ;
struct V_6 * V_7 ;
if ( F_13 ( V_72 ) ) {
F_88 () ;
return;
}
F_89 ( & V_71 ) ;
if ( V_72 ) {
F_90 ( & V_71 ) ;
return;
}
V_7 = F_91 ( F_66 , NULL , L_6 ) ;
F_92 ( F_93 ( V_7 ) ) ;
F_88 () ;
F_42 ( V_72 , V_7 ) ;
F_90 ( & V_71 ) ;
}
static void F_94 ( struct V_16 * V_73 )
{
V_74 ++ ;
F_95 ( L_7 , V_74 ) ;
}
static void F_96 ( void )
{
static struct V_16 V_17 ;
F_97 ( & V_17 , F_94 ) ;
}
static void F_98 ( void )
{
static struct V_16 V_17 ;
F_99 ( & V_17 , F_94 ) ;
}
static void F_100 ( void )
{
static struct V_16 V_17 ;
F_101 ( & V_17 , F_94 ) ;
}
void F_102 ( void )
{
F_95 ( L_8 ) ;
if ( V_75 )
F_96 () ;
if ( V_76 )
F_98 () ;
if ( V_77 )
F_100 () ;
}
static int F_103 ( void )
{
int V_78 = 0 ;
int V_79 = 0 ;
if ( V_75 ) {
V_79 ++ ;
F_104 () ;
}
if ( V_76 ) {
V_79 ++ ;
F_105 () ;
}
if ( V_77 ) {
V_79 ++ ;
F_106 () ;
}
if ( V_74 != V_79 ) {
F_70 ( 1 ) ;
V_78 = - 1 ;
}
return V_78 ;
}
void F_102 ( void ) {}
