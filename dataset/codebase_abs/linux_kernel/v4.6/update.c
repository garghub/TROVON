int F_1 ( void )
{
int V_1 = 0 ;
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
if ( V_2 )
V_1 = F_5 ( & V_3 ) ;
return V_1 || F_6 () != 0 || F_7 () ;
}
bool F_8 ( void )
{
return F_9 ( V_4 ) ;
}
bool F_10 ( void )
{
return V_5 || F_11 ( & V_6 ) ;
}
void F_12 ( void )
{
F_13 ( & V_6 ) ;
}
void F_14 ( void )
{
F_15 ( & V_6 ) ;
}
void F_16 ( void )
{
if ( F_17 ( V_7 ) )
F_14 () ;
if ( V_8 )
F_18 ( V_4 , 1 ) ;
}
void F_19 ( void )
{
V_9 -> V_10 ++ ;
F_20 () ;
}
void F_21 ( void )
{
struct V_11 * V_12 = V_9 ;
if ( V_12 -> V_10 != 1 ) {
-- V_12 -> V_10 ;
} else {
F_20 () ;
V_12 -> V_10 = V_13 ;
F_20 () ;
if ( F_22 ( F_9 ( V_12 -> V_14 . V_15 ) ) )
V_14 ( V_12 ) ;
F_20 () ;
V_12 -> V_10 = 0 ;
}
#ifdef F_23
{
int V_16 = F_9 ( V_12 -> V_10 ) ;
F_24 ( V_16 < 0 && V_16 > V_13 / 2 ) ;
}
#endif
}
int T_1 F_2 ( void )
{
return V_17 && V_2 &&
V_9 -> V_18 == 0 ;
}
int F_25 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_5 ( & V_19 ) ;
}
int F_26 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_27 () || F_7 () ;
}
void F_28 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
V_23 = F_29 ( V_21 , struct V_22 , V_21 ) ;
F_30 ( & V_23 -> V_24 ) ;
}
void F_31 ( bool V_25 , int V_26 , T_2 * V_27 ,
struct V_22 * V_28 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
if ( V_25 &&
( V_27 [ V_29 ] == V_30 ||
V_27 [ V_29 ] == V_31 ) ) {
F_32 () ;
continue;
}
F_33 ( & V_28 [ V_29 ] . V_21 ) ;
F_34 ( & V_28 [ V_29 ] . V_24 ) ;
( V_27 [ V_29 ] ) ( & V_28 [ V_29 ] . V_21 , F_28 ) ;
}
for ( V_29 = 0 ; V_29 < V_26 ; V_29 ++ ) {
if ( V_25 &&
( V_27 [ V_29 ] == V_30 ||
V_27 [ V_29 ] == V_31 ) )
continue;
F_35 ( & V_28 [ V_29 ] . V_24 ) ;
F_36 ( & V_28 [ V_29 ] . V_21 ) ;
}
}
void F_37 ( struct V_20 * V_21 )
{
F_38 ( V_21 , & V_32 ) ;
}
void F_39 ( struct V_20 * V_21 )
{
F_40 ( V_21 , & V_32 ) ;
}
static int F_41 ( void * V_33 , enum V_34 V_35 )
{
struct V_20 * V_21 = V_33 ;
switch ( V_35 ) {
case V_36 :
F_38 ( V_21 , & V_32 ) ;
F_42 ( V_21 , & V_32 ) ;
return 0 ;
default:
return 1 ;
}
}
void F_33 ( struct V_20 * V_21 )
{
F_43 ( V_21 , & V_32 ) ;
}
void F_36 ( struct V_20 * V_21 )
{
F_40 ( V_21 , & V_32 ) ;
}
void F_44 ( const char * V_37 , struct V_20 * V_38 ,
unsigned long V_39 ,
unsigned long V_40 , unsigned long V_41 )
{
F_45 ( V_37 , V_38 , V_39 , V_40 , V_41 ) ;
}
int F_46 ( void )
{
int V_42 = F_9 ( V_43 ) ;
if ( V_42 < 3 ) {
F_18 ( V_43 , 3 ) ;
V_42 = 3 ;
} else if ( V_42 > 300 ) {
F_18 ( V_43 , 300 ) ;
V_42 = 300 ;
}
return V_42 * V_44 + V_45 ;
}
void F_47 ( void )
{
if ( ! V_46 )
V_46 = 2 ;
}
void F_48 ( void )
{
if ( V_46 == 2 )
V_46 = 0 ;
}
static int F_49 ( struct V_47 * V_48 , unsigned long V_49 , void * V_50 )
{
V_46 = 1 ;
return V_51 ;
}
static int T_3 F_50 ( void )
{
F_51 ( & V_52 , & V_53 ) ;
return 0 ;
}
void F_52 ( struct V_20 * V_38 , T_4 V_54 )
{
unsigned long V_55 ;
bool V_56 ;
V_38 -> V_57 = NULL ;
V_38 -> V_54 = V_54 ;
F_53 ( & V_58 , V_55 ) ;
V_56 = ! V_59 ;
* V_60 = V_38 ;
V_60 = & V_38 -> V_57 ;
F_54 ( & V_58 , V_55 ) ;
if ( V_56 ) {
F_55 () ;
F_56 ( & V_61 ) ;
}
}
void F_57 ( void )
{
F_58 ( ! V_17 ,
L_1 ) ;
F_59 ( F_52 ) ;
}
void F_60 ( void )
{
F_57 () ;
}
static void F_61 ( struct V_11 * V_12 ,
bool V_62 , bool * V_63 )
{
int V_64 ;
if ( ! F_9 ( V_12 -> V_65 ) ||
V_12 -> V_66 != F_9 ( V_12 -> V_67 ) ||
! F_9 ( V_12 -> V_68 ) ||
( F_17 ( V_69 ) &&
! F_62 ( V_12 ) && V_12 -> V_70 >= 0 ) ) {
F_18 ( V_12 -> V_65 , false ) ;
F_63 ( & V_12 -> V_71 ) ;
F_64 ( V_12 ) ;
return;
}
if ( ! V_62 )
return;
if ( * V_63 ) {
F_65 ( L_2 ) ;
* V_63 = false ;
}
V_64 = F_66 ( V_12 ) ;
F_67 ( L_3 ,
V_12 , L_4 [ F_62 ( V_12 ) ] ,
L_5 [ V_64 < 0 || ! F_68 ( V_64 ) ] ,
V_12 -> V_66 , V_12 -> V_67 , V_12 -> V_65 ,
V_12 -> V_70 , V_64 ) ;
F_69 ( V_12 ) ;
}
static int T_5 F_70 ( void * V_72 )
{
unsigned long V_55 ;
struct V_11 * V_73 , * V_12 ;
unsigned long V_74 ;
struct V_20 * V_75 ;
struct V_20 * V_57 ;
F_71 ( V_76 ) ;
F_72 ( V_9 ) ;
for (; ; ) {
F_53 ( & V_58 , V_55 ) ;
V_75 = V_59 ;
V_59 = NULL ;
V_60 = & V_59 ;
F_54 ( & V_58 , V_55 ) ;
if ( ! V_75 ) {
F_73 ( V_61 ,
V_59 ) ;
if ( ! V_59 ) {
F_74 ( F_75 ( V_9 ) ) ;
F_76 ( V_44 / 10 ) ;
}
continue;
}
F_77 () ;
F_78 () ;
F_79 (g, t) {
if ( V_12 != V_9 && F_9 ( V_12 -> V_68 ) &&
! F_62 ( V_12 ) ) {
F_80 ( V_12 ) ;
V_12 -> V_66 = F_9 ( V_12 -> V_67 ) ;
F_18 ( V_12 -> V_65 , true ) ;
F_81 ( & V_12 -> V_71 ,
& V_76 ) ;
}
}
F_82 () ;
F_83 ( & V_77 ) ;
V_74 = V_78 ;
while ( ! F_84 ( & V_76 ) ) {
bool V_63 ;
bool V_62 ;
int V_79 ;
struct V_11 * V_80 ;
F_76 ( V_44 ) ;
V_79 = F_9 ( V_81 ) ;
V_62 = V_79 > 0 &&
F_85 ( V_78 , V_74 + V_79 ) ;
if ( V_62 )
V_74 = V_78 ;
V_63 = true ;
F_74 ( F_75 ( V_9 ) ) ;
F_86 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_61 ( V_12 , V_62 , & V_63 ) ;
F_87 () ;
}
}
F_77 () ;
while ( V_75 ) {
V_57 = V_75 -> V_57 ;
F_88 () ;
V_75 -> V_54 ( V_75 ) ;
F_89 () ;
V_75 = V_57 ;
F_87 () ;
}
F_90 ( V_44 / 10 ) ;
}
}
static void F_55 ( void )
{
static F_91 ( V_82 ) ;
static struct V_11 * V_83 ;
struct V_11 * V_12 ;
if ( F_9 ( V_83 ) ) {
F_92 () ;
return;
}
F_93 ( & V_82 ) ;
if ( V_83 ) {
F_94 ( & V_82 ) ;
return;
}
V_12 = F_95 ( F_70 , NULL , L_6 ) ;
F_96 ( F_97 ( V_12 ) ) ;
F_92 () ;
F_18 ( V_83 , V_12 ) ;
F_94 ( & V_82 ) ;
}
static void F_98 ( struct V_20 * V_84 )
{
V_85 ++ ;
F_99 ( L_7 , V_85 ) ;
}
static void F_100 ( void )
{
static struct V_20 V_21 ;
V_30 ( & V_21 , F_98 ) ;
}
static void F_101 ( void )
{
static struct V_20 V_21 ;
V_31 ( & V_21 , F_98 ) ;
}
static void F_102 ( void )
{
static struct V_20 V_21 ;
F_103 ( & V_21 , F_98 ) ;
}
void F_104 ( void )
{
F_99 ( L_8 ) ;
if ( V_86 )
F_100 () ;
if ( V_87 )
F_101 () ;
if ( V_88 )
F_102 () ;
}
static int F_105 ( void )
{
int V_89 = 0 ;
int V_90 = 0 ;
if ( V_86 ) {
V_90 ++ ;
F_106 () ;
}
if ( V_87 ) {
V_90 ++ ;
F_107 () ;
}
if ( V_88 ) {
V_90 ++ ;
F_108 () ;
}
if ( V_85 != V_90 ) {
F_74 ( 1 ) ;
V_89 = - 1 ;
}
return V_89 ;
}
void F_104 ( void ) {}
