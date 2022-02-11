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
if ( ! F_18 ( V_10 ) )
return;
F_19 () ;
F_20 () ;
F_21 () ;
F_22 () ;
F_23 () ;
F_24 () ;
}
static int T_1 F_25 ( void )
{
F_17 () ;
V_5 = V_11 ;
F_17 () ;
return 0 ;
}
void F_26 ( void )
{
V_12 -> V_13 ++ ;
F_27 () ;
}
void F_28 ( void )
{
struct V_14 * V_15 = V_12 ;
if ( V_15 -> V_13 != 1 ) {
-- V_15 -> V_13 ;
} else {
F_27 () ;
V_15 -> V_13 = V_16 ;
F_27 () ;
if ( F_29 ( F_8 ( V_15 -> V_17 . V_18 ) ) )
V_17 ( V_15 ) ;
F_27 () ;
V_15 -> V_13 = 0 ;
}
#ifdef F_30
{
int V_19 = F_8 ( V_15 -> V_13 ) ;
F_31 ( V_19 < 0 && V_19 > V_16 / 2 ) ;
}
#endif
}
int T_2 F_2 ( void )
{
return V_5 != V_20 && V_2 &&
V_12 -> V_21 == 0 ;
}
int F_32 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_5 ( & V_22 ) ;
}
int F_33 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_34 () || F_35 () ;
}
void F_36 ( struct V_23 * V_24 )
{
struct V_25 * V_26 ;
V_26 = F_37 ( V_24 , struct V_25 , V_24 ) ;
F_38 ( & V_26 -> V_27 ) ;
}
void F_39 ( bool V_28 , int V_29 , T_3 * V_30 ,
struct V_25 * V_31 )
{
int V_32 ;
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ ) {
if ( V_28 &&
( V_30 [ V_32 ] == V_33 ||
V_30 [ V_32 ] == V_34 ) ) {
F_40 () ;
continue;
}
F_41 ( & V_31 [ V_32 ] . V_24 ) ;
F_42 ( & V_31 [ V_32 ] . V_27 ) ;
( V_30 [ V_32 ] ) ( & V_31 [ V_32 ] . V_24 , F_36 ) ;
}
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ ) {
if ( V_28 &&
( V_30 [ V_32 ] == V_33 ||
V_30 [ V_32 ] == V_34 ) )
continue;
F_43 ( & V_31 [ V_32 ] . V_27 ) ;
F_44 ( & V_31 [ V_32 ] . V_24 ) ;
}
}
void F_45 ( struct V_23 * V_24 )
{
F_46 ( V_24 , & V_35 ) ;
}
void F_47 ( struct V_23 * V_24 )
{
F_48 ( V_24 , & V_35 ) ;
}
static bool F_49 ( void * V_36 )
{
return true ;
}
void F_41 ( struct V_23 * V_24 )
{
F_50 ( V_24 , & V_35 ) ;
}
void F_44 ( struct V_23 * V_24 )
{
F_48 ( V_24 , & V_35 ) ;
}
void F_51 ( const char * V_37 , struct V_23 * V_38 ,
unsigned long V_39 ,
unsigned long V_40 , unsigned long V_41 )
{
F_52 ( V_37 , V_38 , V_39 , V_40 , V_41 ) ;
}
int F_53 ( void )
{
int V_42 = F_8 ( V_43 ) ;
if ( V_42 < 3 ) {
F_16 ( V_43 , 3 ) ;
V_42 = 3 ;
} else if ( V_42 > 300 ) {
F_16 ( V_43 , 300 ) ;
V_42 = 300 ;
}
return V_42 * V_44 + V_45 ;
}
void F_54 ( void )
{
if ( ! V_46 )
V_46 = 2 ;
}
void F_55 ( void )
{
if ( V_46 == 2 )
V_46 = 0 ;
}
static int F_56 ( struct V_47 * V_48 , unsigned long V_49 , void * V_50 )
{
V_46 = 1 ;
return V_51 ;
}
static int T_1 F_57 ( void )
{
F_58 ( & V_52 , & V_53 ) ;
return 0 ;
}
void F_59 ( struct V_23 * V_38 , T_4 V_54 )
{
unsigned long V_55 ;
bool V_56 ;
bool V_57 = F_8 ( V_58 ) ;
V_38 -> V_59 = NULL ;
V_38 -> V_54 = V_54 ;
F_60 ( & V_60 , V_55 ) ;
V_56 = ! V_61 ;
* V_62 = V_38 ;
V_62 = & V_38 -> V_59 ;
F_61 ( & V_60 , V_55 ) ;
if ( ( V_56 && V_57 ) ||
( ! V_57 && ! F_62 ( V_55 ) ) ) {
F_63 () ;
F_64 ( & V_63 ) ;
}
}
void F_65 ( void )
{
F_66 ( V_5 == V_20 ,
L_1 ) ;
F_67 ( F_59 ) ;
}
void F_68 ( void )
{
F_65 () ;
}
static void F_69 ( struct V_14 * V_15 ,
bool V_64 , bool * V_65 )
{
int V_66 ;
if ( ! F_8 ( V_15 -> V_67 ) ||
V_15 -> V_68 != F_8 ( V_15 -> V_69 ) ||
! F_8 ( V_15 -> V_70 ) ||
( F_18 ( V_71 ) &&
! F_70 ( V_15 ) && V_15 -> V_72 >= 0 ) ) {
F_16 ( V_15 -> V_67 , false ) ;
F_71 ( & V_15 -> V_73 ) ;
F_72 ( V_15 ) ;
return;
}
F_73 ( V_15 ) ;
if ( ! V_64 )
return;
if ( * V_65 ) {
F_74 ( L_2 ) ;
* V_65 = false ;
}
V_66 = F_75 ( V_15 ) ;
F_76 ( L_3 ,
V_15 , L_4 [ F_70 ( V_15 ) ] ,
L_5 [ V_66 < 0 || ! F_77 ( V_66 ) ] ,
V_15 -> V_68 , V_15 -> V_69 , V_15 -> V_67 ,
V_15 -> V_72 , V_66 ) ;
F_78 ( V_15 ) ;
}
static int T_5 F_79 ( void * V_74 )
{
unsigned long V_55 ;
struct V_14 * V_75 , * V_15 ;
unsigned long V_76 ;
struct V_23 * V_77 ;
struct V_23 * V_59 ;
F_80 ( V_78 ) ;
F_81 ( V_12 ) ;
for (; ; ) {
F_60 ( & V_60 , V_55 ) ;
V_77 = V_61 ;
V_61 = NULL ;
V_62 = & V_61 ;
F_61 ( & V_60 , V_55 ) ;
if ( ! V_77 ) {
F_82 ( V_63 ,
V_61 ) ;
if ( ! V_61 ) {
F_83 ( F_84 ( V_12 ) ) ;
F_85 ( V_44 / 10 ) ;
}
continue;
}
F_21 () ;
F_86 () ;
F_87 (g, t) {
if ( V_15 != V_12 && F_8 ( V_15 -> V_70 ) &&
! F_70 ( V_15 ) ) {
F_88 ( V_15 ) ;
V_15 -> V_68 = F_8 ( V_15 -> V_69 ) ;
F_16 ( V_15 -> V_67 , true ) ;
F_89 ( & V_15 -> V_73 ,
& V_78 ) ;
}
}
F_90 () ;
F_91 ( & V_79 ) ;
V_76 = V_80 ;
while ( ! F_92 ( & V_78 ) ) {
bool V_65 ;
bool V_64 ;
int V_81 ;
struct V_14 * V_82 ;
F_85 ( V_44 ) ;
V_81 = F_8 ( V_83 ) ;
V_64 = V_81 > 0 &&
F_93 ( V_80 , V_76 + V_81 ) ;
if ( V_64 )
V_76 = V_80 ;
V_65 = true ;
F_83 ( F_84 ( V_12 ) ) ;
F_94 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_69 ( V_15 , V_64 , & V_65 ) ;
F_95 () ;
}
}
F_21 () ;
while ( V_77 ) {
V_59 = V_77 -> V_59 ;
F_96 () ;
V_77 -> V_54 ( V_77 ) ;
F_97 () ;
V_77 = V_59 ;
F_95 () ;
}
F_98 ( V_44 / 10 ) ;
}
}
static void F_63 ( void )
{
static F_99 ( V_84 ) ;
struct V_14 * V_15 ;
if ( F_8 ( V_58 ) ) {
F_100 () ;
return;
}
F_101 ( & V_84 ) ;
if ( V_58 ) {
F_102 ( & V_84 ) ;
return;
}
V_15 = F_103 ( F_79 , NULL , L_6 ) ;
F_104 ( F_105 ( V_15 ) ) ;
F_100 () ;
F_16 ( V_58 , V_15 ) ;
F_102 ( & V_84 ) ;
}
static void F_106 ( struct V_23 * V_85 )
{
V_86 ++ ;
F_107 ( L_7 , V_86 ) ;
}
static void F_108 ( void )
{
static struct V_23 V_24 ;
V_33 ( & V_24 , F_106 ) ;
}
static void F_109 ( void )
{
static struct V_23 V_24 ;
V_34 ( & V_24 , F_106 ) ;
}
static void F_110 ( void )
{
static struct V_23 V_24 ;
F_111 ( & V_24 , F_106 ) ;
}
void F_112 ( void )
{
F_107 ( L_8 ) ;
if ( V_87 )
F_108 () ;
if ( V_88 )
F_109 () ;
if ( V_89 )
F_110 () ;
F_17 () ;
}
static int F_113 ( void )
{
int V_90 = 0 ;
int V_91 = 0 ;
if ( V_87 ) {
V_91 ++ ;
F_114 () ;
}
if ( V_88 ) {
V_91 ++ ;
F_115 () ;
}
if ( V_89 ) {
V_91 ++ ;
F_116 () ;
}
if ( V_86 != V_91 ) {
F_83 ( 1 ) ;
V_90 = - 1 ;
}
return V_90 ;
}
void F_112 ( void ) {}
