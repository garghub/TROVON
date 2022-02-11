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
return F_8 ( V_4 ) &&
V_5 != V_6 ;
}
bool F_9 ( void )
{
return V_7 || F_10 ( & V_8 ) ||
V_5 == V_6 ;
}
void F_11 ( void )
{
F_12 ( & V_8 ) ;
}
void F_13 ( void )
{
F_14 ( & V_8 ) ;
}
void F_15 ( void )
{
F_13 () ;
if ( V_9 )
F_16 ( V_4 , 1 ) ;
}
void F_17 ( void )
{
V_10 -> V_11 ++ ;
F_18 () ;
}
void F_19 ( void )
{
struct V_12 * V_13 = V_10 ;
if ( V_13 -> V_11 != 1 ) {
-- V_13 -> V_11 ;
} else {
F_18 () ;
V_13 -> V_11 = V_14 ;
F_18 () ;
if ( F_20 ( F_8 ( V_13 -> V_15 . V_16 ) ) )
V_15 ( V_13 ) ;
F_18 () ;
V_13 -> V_11 = 0 ;
}
#ifdef F_21
{
int V_17 = F_8 ( V_13 -> V_11 ) ;
F_22 ( V_17 < 0 && V_17 > V_14 / 2 ) ;
}
#endif
}
int T_1 F_2 ( void )
{
return V_5 != V_18 && V_2 &&
V_10 -> V_19 == 0 ;
}
int F_23 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_5 ( & V_20 ) ;
}
int F_24 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_25 () || F_26 () ;
}
void F_27 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
V_24 = F_28 ( V_22 , struct V_23 , V_22 ) ;
F_29 ( & V_24 -> V_25 ) ;
}
void F_30 ( bool V_26 , int V_27 , T_2 * V_28 ,
struct V_23 * V_29 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ ) {
if ( V_26 &&
( V_28 [ V_30 ] == V_31 ||
V_28 [ V_30 ] == V_32 ) ) {
F_31 () ;
continue;
}
F_32 ( & V_29 [ V_30 ] . V_22 ) ;
F_33 ( & V_29 [ V_30 ] . V_25 ) ;
( V_28 [ V_30 ] ) ( & V_29 [ V_30 ] . V_22 , F_27 ) ;
}
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ ) {
if ( V_26 &&
( V_28 [ V_30 ] == V_31 ||
V_28 [ V_30 ] == V_32 ) )
continue;
F_34 ( & V_29 [ V_30 ] . V_25 ) ;
F_35 ( & V_29 [ V_30 ] . V_22 ) ;
}
}
void F_36 ( struct V_21 * V_22 )
{
F_37 ( V_22 , & V_33 ) ;
}
void F_38 ( struct V_21 * V_22 )
{
F_39 ( V_22 , & V_33 ) ;
}
static bool F_40 ( void * V_34 )
{
return true ;
}
void F_32 ( struct V_21 * V_22 )
{
F_41 ( V_22 , & V_33 ) ;
}
void F_35 ( struct V_21 * V_22 )
{
F_39 ( V_22 , & V_33 ) ;
}
void F_42 ( const char * V_35 , struct V_21 * V_36 ,
unsigned long V_37 ,
unsigned long V_38 , unsigned long V_39 )
{
F_43 ( V_35 , V_36 , V_37 , V_38 , V_39 ) ;
}
int F_44 ( void )
{
int V_40 = F_8 ( V_41 ) ;
if ( V_40 < 3 ) {
F_16 ( V_41 , 3 ) ;
V_40 = 3 ;
} else if ( V_40 > 300 ) {
F_16 ( V_41 , 300 ) ;
V_40 = 300 ;
}
return V_40 * V_42 + V_43 ;
}
void F_45 ( void )
{
if ( ! V_44 )
V_44 = 2 ;
}
void F_46 ( void )
{
if ( V_44 == 2 )
V_44 = 0 ;
}
static int F_47 ( struct V_45 * V_46 , unsigned long V_47 , void * V_48 )
{
V_44 = 1 ;
return V_49 ;
}
static int T_3 F_48 ( void )
{
F_49 ( & V_50 , & V_51 ) ;
return 0 ;
}
void F_50 ( struct V_21 * V_36 , T_4 V_52 )
{
unsigned long V_53 ;
bool V_54 ;
bool V_55 = F_8 ( V_56 ) ;
V_36 -> V_57 = NULL ;
V_36 -> V_52 = V_52 ;
F_51 ( & V_58 , V_53 ) ;
V_54 = ! V_59 ;
* V_60 = V_36 ;
V_60 = & V_36 -> V_57 ;
F_52 ( & V_58 , V_53 ) ;
if ( ( V_54 && V_55 ) ||
( ! V_55 && ! F_53 ( V_53 ) ) ) {
F_54 () ;
F_55 ( & V_61 ) ;
}
}
void F_56 ( void )
{
F_57 ( V_5 == V_18 ,
L_1 ) ;
F_58 ( F_50 ) ;
}
void F_59 ( void )
{
F_56 () ;
}
static void F_60 ( struct V_12 * V_13 ,
bool V_62 , bool * V_63 )
{
int V_64 ;
if ( ! F_8 ( V_13 -> V_65 ) ||
V_13 -> V_66 != F_8 ( V_13 -> V_67 ) ||
! F_8 ( V_13 -> V_68 ) ||
( F_61 ( V_69 ) &&
! F_62 ( V_13 ) && V_13 -> V_70 >= 0 ) ) {
F_16 ( V_13 -> V_65 , false ) ;
F_63 ( & V_13 -> V_71 ) ;
F_64 ( V_13 ) ;
return;
}
if ( ! V_62 )
return;
if ( * V_63 ) {
F_65 ( L_2 ) ;
* V_63 = false ;
}
V_64 = F_66 ( V_13 ) ;
F_67 ( L_3 ,
V_13 , L_4 [ F_62 ( V_13 ) ] ,
L_5 [ V_64 < 0 || ! F_68 ( V_64 ) ] ,
V_13 -> V_66 , V_13 -> V_67 , V_13 -> V_65 ,
V_13 -> V_70 , V_64 ) ;
F_69 ( V_13 ) ;
}
static int T_5 F_70 ( void * V_72 )
{
unsigned long V_53 ;
struct V_12 * V_73 , * V_13 ;
unsigned long V_74 ;
struct V_21 * V_75 ;
struct V_21 * V_57 ;
F_71 ( V_76 ) ;
F_72 ( V_10 ) ;
for (; ; ) {
F_51 ( & V_58 , V_53 ) ;
V_75 = V_59 ;
V_59 = NULL ;
V_60 = & V_59 ;
F_52 ( & V_58 , V_53 ) ;
if ( ! V_75 ) {
F_73 ( V_61 ,
V_59 ) ;
if ( ! V_59 ) {
F_74 ( F_75 ( V_10 ) ) ;
F_76 ( V_42 / 10 ) ;
}
continue;
}
F_77 () ;
F_78 () ;
F_79 (g, t) {
if ( V_13 != V_10 && F_8 ( V_13 -> V_68 ) &&
! F_62 ( V_13 ) ) {
F_80 ( V_13 ) ;
V_13 -> V_66 = F_8 ( V_13 -> V_67 ) ;
F_16 ( V_13 -> V_65 , true ) ;
F_81 ( & V_13 -> V_71 ,
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
struct V_12 * V_80 ;
F_76 ( V_42 ) ;
V_79 = F_8 ( V_81 ) ;
V_62 = V_79 > 0 &&
F_85 ( V_78 , V_74 + V_79 ) ;
if ( V_62 )
V_74 = V_78 ;
V_63 = true ;
F_74 ( F_75 ( V_10 ) ) ;
F_86 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_60 ( V_13 , V_62 , & V_63 ) ;
F_87 () ;
}
}
F_77 () ;
while ( V_75 ) {
V_57 = V_75 -> V_57 ;
F_88 () ;
V_75 -> V_52 ( V_75 ) ;
F_89 () ;
V_75 = V_57 ;
F_87 () ;
}
F_90 ( V_42 / 10 ) ;
}
}
static void F_54 ( void )
{
static F_91 ( V_82 ) ;
struct V_12 * V_13 ;
if ( F_8 ( V_56 ) ) {
F_92 () ;
return;
}
F_93 ( & V_82 ) ;
if ( V_56 ) {
F_94 ( & V_82 ) ;
return;
}
V_13 = F_95 ( F_70 , NULL , L_6 ) ;
F_96 ( F_97 ( V_13 ) ) ;
F_92 () ;
F_16 ( V_56 , V_13 ) ;
F_94 ( & V_82 ) ;
}
void F_98 ( void )
{
if ( ! F_61 ( V_83 ) )
return;
F_99 () ;
F_100 () ;
F_77 () ;
F_101 () ;
F_102 () ;
F_103 () ;
}
static void F_104 ( struct V_21 * V_84 )
{
V_85 ++ ;
F_105 ( L_7 , V_85 ) ;
}
static void F_106 ( void )
{
static struct V_21 V_22 ;
V_31 ( & V_22 , F_104 ) ;
}
static void F_107 ( void )
{
static struct V_21 V_22 ;
V_32 ( & V_22 , F_104 ) ;
}
static void F_108 ( void )
{
static struct V_21 V_22 ;
F_109 ( & V_22 , F_104 ) ;
}
void F_110 ( void )
{
F_105 ( L_8 ) ;
if ( V_86 )
F_106 () ;
if ( V_87 )
F_107 () ;
if ( V_88 )
F_108 () ;
F_98 () ;
}
static int F_111 ( void )
{
int V_89 = 0 ;
int V_90 = 0 ;
if ( V_86 ) {
V_90 ++ ;
F_112 () ;
}
if ( V_87 ) {
V_90 ++ ;
F_113 () ;
}
if ( V_88 ) {
V_90 ++ ;
F_114 () ;
}
if ( V_85 != V_90 ) {
F_74 ( 1 ) ;
V_89 = - 1 ;
}
return V_89 ;
}
void F_110 ( void ) {}
