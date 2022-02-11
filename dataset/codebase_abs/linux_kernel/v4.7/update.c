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
return V_1 || ! F_6 () ;
}
bool F_7 ( void )
{
return F_8 ( V_4 ) ;
}
bool F_9 ( void )
{
return V_5 || F_10 ( & V_6 ) ;
}
void F_11 ( void )
{
F_12 ( & V_6 ) ;
}
void F_13 ( void )
{
F_14 ( & V_6 ) ;
}
void F_15 ( void )
{
if ( F_16 ( V_7 ) )
F_13 () ;
if ( V_8 )
F_17 ( V_4 , 1 ) ;
}
void F_18 ( void )
{
V_9 -> V_10 ++ ;
F_19 () ;
}
void F_20 ( void )
{
struct V_11 * V_12 = V_9 ;
if ( V_12 -> V_10 != 1 ) {
-- V_12 -> V_10 ;
} else {
F_19 () ;
V_12 -> V_10 = V_13 ;
F_19 () ;
if ( F_21 ( F_8 ( V_12 -> V_14 . V_15 ) ) )
V_14 ( V_12 ) ;
F_19 () ;
V_12 -> V_10 = 0 ;
}
#ifdef F_22
{
int V_16 = F_8 ( V_12 -> V_10 ) ;
F_23 ( V_16 < 0 && V_16 > V_13 / 2 ) ;
}
#endif
}
int T_1 F_2 ( void )
{
return V_17 && V_2 &&
V_9 -> V_18 == 0 ;
}
int F_24 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_5 ( & V_19 ) ;
}
int F_25 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_26 () || F_27 () ;
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
static bool F_41 ( void * V_33 )
{
return true ;
}
void F_33 ( struct V_20 * V_21 )
{
F_42 ( V_21 , & V_32 ) ;
}
void F_36 ( struct V_20 * V_21 )
{
F_40 ( V_21 , & V_32 ) ;
}
void F_43 ( const char * V_34 , struct V_20 * V_35 ,
unsigned long V_36 ,
unsigned long V_37 , unsigned long V_38 )
{
F_44 ( V_34 , V_35 , V_36 , V_37 , V_38 ) ;
}
int F_45 ( void )
{
int V_39 = F_8 ( V_40 ) ;
if ( V_39 < 3 ) {
F_17 ( V_40 , 3 ) ;
V_39 = 3 ;
} else if ( V_39 > 300 ) {
F_17 ( V_40 , 300 ) ;
V_39 = 300 ;
}
return V_39 * V_41 + V_42 ;
}
void F_46 ( void )
{
if ( ! V_43 )
V_43 = 2 ;
}
void F_47 ( void )
{
if ( V_43 == 2 )
V_43 = 0 ;
}
static int F_48 ( struct V_44 * V_45 , unsigned long V_46 , void * V_47 )
{
V_43 = 1 ;
return V_48 ;
}
static int T_3 F_49 ( void )
{
F_50 ( & V_49 , & V_50 ) ;
return 0 ;
}
void F_51 ( struct V_20 * V_35 , T_4 V_51 )
{
unsigned long V_52 ;
bool V_53 ;
V_35 -> V_54 = NULL ;
V_35 -> V_51 = V_51 ;
F_52 ( & V_55 , V_52 ) ;
V_53 = ! V_56 ;
* V_57 = V_35 ;
V_57 = & V_35 -> V_54 ;
F_53 ( & V_55 , V_52 ) ;
if ( V_53 ) {
F_54 () ;
F_55 ( & V_58 ) ;
}
}
void F_56 ( void )
{
F_57 ( ! V_17 ,
L_1 ) ;
F_58 ( F_51 ) ;
}
void F_59 ( void )
{
F_56 () ;
}
static void F_60 ( struct V_11 * V_12 ,
bool V_59 , bool * V_60 )
{
int V_61 ;
if ( ! F_8 ( V_12 -> V_62 ) ||
V_12 -> V_63 != F_8 ( V_12 -> V_64 ) ||
! F_8 ( V_12 -> V_65 ) ||
( F_16 ( V_66 ) &&
! F_61 ( V_12 ) && V_12 -> V_67 >= 0 ) ) {
F_17 ( V_12 -> V_62 , false ) ;
F_62 ( & V_12 -> V_68 ) ;
F_63 ( V_12 ) ;
return;
}
if ( ! V_59 )
return;
if ( * V_60 ) {
F_64 ( L_2 ) ;
* V_60 = false ;
}
V_61 = F_65 ( V_12 ) ;
F_66 ( L_3 ,
V_12 , L_4 [ F_61 ( V_12 ) ] ,
L_5 [ V_61 < 0 || ! F_67 ( V_61 ) ] ,
V_12 -> V_63 , V_12 -> V_64 , V_12 -> V_62 ,
V_12 -> V_67 , V_61 ) ;
F_68 ( V_12 ) ;
}
static int T_5 F_69 ( void * V_69 )
{
unsigned long V_52 ;
struct V_11 * V_70 , * V_12 ;
unsigned long V_71 ;
struct V_20 * V_72 ;
struct V_20 * V_54 ;
F_70 ( V_73 ) ;
F_71 ( V_9 ) ;
for (; ; ) {
F_52 ( & V_55 , V_52 ) ;
V_72 = V_56 ;
V_56 = NULL ;
V_57 = & V_56 ;
F_53 ( & V_55 , V_52 ) ;
if ( ! V_72 ) {
F_72 ( V_58 ,
V_56 ) ;
if ( ! V_56 ) {
F_73 ( F_74 ( V_9 ) ) ;
F_75 ( V_41 / 10 ) ;
}
continue;
}
F_76 () ;
F_77 () ;
F_78 (g, t) {
if ( V_12 != V_9 && F_8 ( V_12 -> V_65 ) &&
! F_61 ( V_12 ) ) {
F_79 ( V_12 ) ;
V_12 -> V_63 = F_8 ( V_12 -> V_64 ) ;
F_17 ( V_12 -> V_62 , true ) ;
F_80 ( & V_12 -> V_68 ,
& V_73 ) ;
}
}
F_81 () ;
F_82 ( & V_74 ) ;
V_71 = V_75 ;
while ( ! F_83 ( & V_73 ) ) {
bool V_60 ;
bool V_59 ;
int V_76 ;
struct V_11 * V_77 ;
F_75 ( V_41 ) ;
V_76 = F_8 ( V_78 ) ;
V_59 = V_76 > 0 &&
F_84 ( V_75 , V_71 + V_76 ) ;
if ( V_59 )
V_71 = V_75 ;
V_60 = true ;
F_73 ( F_74 ( V_9 ) ) ;
F_85 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_60 ( V_12 , V_59 , & V_60 ) ;
F_86 () ;
}
}
F_76 () ;
while ( V_72 ) {
V_54 = V_72 -> V_54 ;
F_87 () ;
V_72 -> V_51 ( V_72 ) ;
F_88 () ;
V_72 = V_54 ;
F_86 () ;
}
F_89 ( V_41 / 10 ) ;
}
}
static void F_54 ( void )
{
static F_90 ( V_79 ) ;
static struct V_11 * V_80 ;
struct V_11 * V_12 ;
if ( F_8 ( V_80 ) ) {
F_91 () ;
return;
}
F_92 ( & V_79 ) ;
if ( V_80 ) {
F_93 ( & V_79 ) ;
return;
}
V_12 = F_94 ( F_69 , NULL , L_6 ) ;
F_95 ( F_96 ( V_12 ) ) ;
F_91 () ;
F_17 ( V_80 , V_12 ) ;
F_93 ( & V_79 ) ;
}
static void F_97 ( struct V_20 * V_81 )
{
V_82 ++ ;
F_98 ( L_7 , V_82 ) ;
}
static void F_99 ( void )
{
static struct V_20 V_21 ;
V_30 ( & V_21 , F_97 ) ;
}
static void F_100 ( void )
{
static struct V_20 V_21 ;
V_31 ( & V_21 , F_97 ) ;
}
static void F_101 ( void )
{
static struct V_20 V_21 ;
F_102 ( & V_21 , F_97 ) ;
}
void F_103 ( void )
{
F_98 ( L_8 ) ;
if ( V_83 )
F_99 () ;
if ( V_84 )
F_100 () ;
if ( V_85 )
F_101 () ;
}
static int F_104 ( void )
{
int V_86 = 0 ;
int V_87 = 0 ;
if ( V_83 ) {
V_87 ++ ;
F_105 () ;
}
if ( V_84 ) {
V_87 ++ ;
F_106 () ;
}
if ( V_85 ) {
V_87 ++ ;
F_107 () ;
}
if ( V_82 != V_87 ) {
F_73 ( 1 ) ;
V_86 = - 1 ;
}
return V_86 ;
}
void F_103 ( void ) {}
