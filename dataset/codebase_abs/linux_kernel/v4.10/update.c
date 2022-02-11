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
if ( F_16 ( V_9 ) )
F_13 () ;
if ( V_10 )
F_17 ( V_4 , 1 ) ;
}
void F_18 ( void )
{
V_11 -> V_12 ++ ;
F_19 () ;
}
void F_20 ( void )
{
struct V_13 * V_14 = V_11 ;
if ( V_14 -> V_12 != 1 ) {
-- V_14 -> V_12 ;
} else {
F_19 () ;
V_14 -> V_12 = V_15 ;
F_19 () ;
if ( F_21 ( F_8 ( V_14 -> V_16 . V_17 ) ) )
V_16 ( V_14 ) ;
F_19 () ;
V_14 -> V_12 = 0 ;
}
#ifdef F_22
{
int V_18 = F_8 ( V_14 -> V_12 ) ;
F_23 ( V_18 < 0 && V_18 > V_15 / 2 ) ;
}
#endif
}
int T_1 F_2 ( void )
{
return V_5 != V_19 && V_2 &&
V_11 -> V_20 == 0 ;
}
int F_24 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_5 ( & V_21 ) ;
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
void F_28 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
V_25 = F_29 ( V_23 , struct V_24 , V_23 ) ;
F_30 ( & V_25 -> V_26 ) ;
}
void F_31 ( bool V_27 , int V_28 , T_2 * V_29 ,
struct V_24 * V_30 )
{
int V_31 ;
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
if ( V_27 &&
( V_29 [ V_31 ] == V_32 ||
V_29 [ V_31 ] == V_33 ) ) {
F_32 () ;
continue;
}
F_33 ( & V_30 [ V_31 ] . V_23 ) ;
F_34 ( & V_30 [ V_31 ] . V_26 ) ;
( V_29 [ V_31 ] ) ( & V_30 [ V_31 ] . V_23 , F_28 ) ;
}
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
if ( V_27 &&
( V_29 [ V_31 ] == V_32 ||
V_29 [ V_31 ] == V_33 ) )
continue;
F_35 ( & V_30 [ V_31 ] . V_26 ) ;
F_36 ( & V_30 [ V_31 ] . V_23 ) ;
}
}
void F_37 ( struct V_22 * V_23 )
{
F_38 ( V_23 , & V_34 ) ;
}
void F_39 ( struct V_22 * V_23 )
{
F_40 ( V_23 , & V_34 ) ;
}
static bool F_41 ( void * V_35 )
{
return true ;
}
void F_33 ( struct V_22 * V_23 )
{
F_42 ( V_23 , & V_34 ) ;
}
void F_36 ( struct V_22 * V_23 )
{
F_40 ( V_23 , & V_34 ) ;
}
void F_43 ( const char * V_36 , struct V_22 * V_37 ,
unsigned long V_38 ,
unsigned long V_39 , unsigned long V_40 )
{
F_44 ( V_36 , V_37 , V_38 , V_39 , V_40 ) ;
}
int F_45 ( void )
{
int V_41 = F_8 ( V_42 ) ;
if ( V_41 < 3 ) {
F_17 ( V_42 , 3 ) ;
V_41 = 3 ;
} else if ( V_41 > 300 ) {
F_17 ( V_42 , 300 ) ;
V_41 = 300 ;
}
return V_41 * V_43 + V_44 ;
}
void F_46 ( void )
{
if ( ! V_45 )
V_45 = 2 ;
}
void F_47 ( void )
{
if ( V_45 == 2 )
V_45 = 0 ;
}
static int F_48 ( struct V_46 * V_47 , unsigned long V_48 , void * V_49 )
{
V_45 = 1 ;
return V_50 ;
}
static int T_3 F_49 ( void )
{
F_50 ( & V_51 , & V_52 ) ;
return 0 ;
}
void F_51 ( struct V_22 * V_37 , T_4 V_53 )
{
unsigned long V_54 ;
bool V_55 ;
bool V_56 = F_8 ( V_57 ) ;
V_37 -> V_58 = NULL ;
V_37 -> V_53 = V_53 ;
F_52 ( & V_59 , V_54 ) ;
V_55 = ! V_60 ;
* V_61 = V_37 ;
V_61 = & V_37 -> V_58 ;
F_53 ( & V_59 , V_54 ) ;
if ( ( V_55 && V_56 ) ||
( ! V_56 && ! F_54 ( V_54 ) ) ) {
F_55 () ;
F_56 ( & V_62 ) ;
}
}
void F_57 ( void )
{
F_58 ( V_5 == V_19 ,
L_1 ) ;
F_59 ( F_51 ) ;
}
void F_60 ( void )
{
F_57 () ;
}
static void F_61 ( struct V_13 * V_14 ,
bool V_63 , bool * V_64 )
{
int V_65 ;
if ( ! F_8 ( V_14 -> V_66 ) ||
V_14 -> V_67 != F_8 ( V_14 -> V_68 ) ||
! F_8 ( V_14 -> V_69 ) ||
( F_16 ( V_70 ) &&
! F_62 ( V_14 ) && V_14 -> V_71 >= 0 ) ) {
F_17 ( V_14 -> V_66 , false ) ;
F_63 ( & V_14 -> V_72 ) ;
F_64 ( V_14 ) ;
return;
}
if ( ! V_63 )
return;
if ( * V_64 ) {
F_65 ( L_2 ) ;
* V_64 = false ;
}
V_65 = F_66 ( V_14 ) ;
F_67 ( L_3 ,
V_14 , L_4 [ F_62 ( V_14 ) ] ,
L_5 [ V_65 < 0 || ! F_68 ( V_65 ) ] ,
V_14 -> V_67 , V_14 -> V_68 , V_14 -> V_66 ,
V_14 -> V_71 , V_65 ) ;
F_69 ( V_14 ) ;
}
static int T_5 F_70 ( void * V_73 )
{
unsigned long V_54 ;
struct V_13 * V_74 , * V_14 ;
unsigned long V_75 ;
struct V_22 * V_76 ;
struct V_22 * V_58 ;
F_71 ( V_77 ) ;
F_72 ( V_11 ) ;
for (; ; ) {
F_52 ( & V_59 , V_54 ) ;
V_76 = V_60 ;
V_60 = NULL ;
V_61 = & V_60 ;
F_53 ( & V_59 , V_54 ) ;
if ( ! V_76 ) {
F_73 ( V_62 ,
V_60 ) ;
if ( ! V_60 ) {
F_74 ( F_75 ( V_11 ) ) ;
F_76 ( V_43 / 10 ) ;
}
continue;
}
F_77 () ;
F_78 () ;
F_79 (g, t) {
if ( V_14 != V_11 && F_8 ( V_14 -> V_69 ) &&
! F_62 ( V_14 ) ) {
F_80 ( V_14 ) ;
V_14 -> V_67 = F_8 ( V_14 -> V_68 ) ;
F_17 ( V_14 -> V_66 , true ) ;
F_81 ( & V_14 -> V_72 ,
& V_77 ) ;
}
}
F_82 () ;
F_83 ( & V_78 ) ;
V_75 = V_79 ;
while ( ! F_84 ( & V_77 ) ) {
bool V_64 ;
bool V_63 ;
int V_80 ;
struct V_13 * V_81 ;
F_76 ( V_43 ) ;
V_80 = F_8 ( V_82 ) ;
V_63 = V_80 > 0 &&
F_85 ( V_79 , V_75 + V_80 ) ;
if ( V_63 )
V_75 = V_79 ;
V_64 = true ;
F_74 ( F_75 ( V_11 ) ) ;
F_86 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_61 ( V_14 , V_63 , & V_64 ) ;
F_87 () ;
}
}
F_77 () ;
while ( V_76 ) {
V_58 = V_76 -> V_58 ;
F_88 () ;
V_76 -> V_53 ( V_76 ) ;
F_89 () ;
V_76 = V_58 ;
F_87 () ;
}
F_90 ( V_43 / 10 ) ;
}
}
static void F_55 ( void )
{
static F_91 ( V_83 ) ;
struct V_13 * V_14 ;
if ( F_8 ( V_57 ) ) {
F_92 () ;
return;
}
F_93 ( & V_83 ) ;
if ( V_57 ) {
F_94 ( & V_83 ) ;
return;
}
V_14 = F_95 ( F_70 , NULL , L_6 ) ;
F_96 ( F_97 ( V_14 ) ) ;
F_92 () ;
F_17 ( V_57 , V_14 ) ;
F_94 ( & V_83 ) ;
}
void F_98 ( void )
{
if ( ! F_16 ( V_84 ) )
return;
F_99 () ;
F_100 () ;
F_77 () ;
F_101 () ;
F_102 () ;
F_103 () ;
}
static void F_104 ( struct V_22 * V_85 )
{
V_86 ++ ;
F_105 ( L_7 , V_86 ) ;
}
static void F_106 ( void )
{
static struct V_22 V_23 ;
V_32 ( & V_23 , F_104 ) ;
}
static void F_107 ( void )
{
static struct V_22 V_23 ;
V_33 ( & V_23 , F_104 ) ;
}
static void F_108 ( void )
{
static struct V_22 V_23 ;
F_109 ( & V_23 , F_104 ) ;
}
void F_110 ( void )
{
F_105 ( L_8 ) ;
if ( V_87 )
F_106 () ;
if ( V_88 )
F_107 () ;
if ( V_89 )
F_108 () ;
F_98 () ;
}
static int F_111 ( void )
{
int V_90 = 0 ;
int V_91 = 0 ;
if ( V_87 ) {
V_91 ++ ;
F_112 () ;
}
if ( V_88 ) {
V_91 ++ ;
F_113 () ;
}
if ( V_89 ) {
V_91 ++ ;
F_114 () ;
}
if ( V_86 != V_91 ) {
F_74 ( 1 ) ;
V_90 = - 1 ;
}
return V_90 ;
}
void F_110 ( void ) {}
