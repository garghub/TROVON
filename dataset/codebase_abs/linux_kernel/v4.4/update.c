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
return V_4 || F_9 ( & V_5 ) ;
}
void F_10 ( void )
{
F_11 ( & V_5 ) ;
}
void F_12 ( void )
{
F_13 ( & V_5 ) ;
}
void F_14 ( void )
{
if ( F_15 ( V_6 ) )
F_12 () ;
}
void F_16 ( void )
{
V_7 -> V_8 ++ ;
F_17 () ;
}
void F_18 ( void )
{
struct V_9 * V_10 = V_7 ;
if ( V_10 -> V_8 != 1 ) {
-- V_10 -> V_8 ;
} else {
F_17 () ;
V_10 -> V_8 = V_11 ;
F_17 () ;
if ( F_19 ( F_20 ( V_10 -> V_12 . V_13 ) ) )
V_12 ( V_10 ) ;
F_17 () ;
V_10 -> V_8 = 0 ;
}
#ifdef F_21
{
int V_14 = F_20 ( V_10 -> V_8 ) ;
F_22 ( V_14 < 0 && V_14 > V_11 / 2 ) ;
}
#endif
}
int T_1 F_2 ( void )
{
return V_15 && V_2 &&
V_7 -> V_16 == 0 ;
}
int F_23 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_5 ( & V_17 ) ;
}
int F_24 ( void )
{
if ( ! F_2 () )
return 1 ;
if ( ! F_3 () )
return 0 ;
if ( ! F_4 () )
return 0 ;
return F_25 () || F_7 () ;
}
void F_26 ( struct V_18 * V_19 )
{
struct V_20 * V_21 ;
V_21 = F_27 ( V_19 , struct V_20 , V_19 ) ;
F_28 ( & V_21 -> V_22 ) ;
}
void F_29 ( bool V_23 , int V_24 , T_2 * V_25 ,
struct V_20 * V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ ) {
if ( V_23 &&
( V_25 [ V_27 ] == V_28 ||
V_25 [ V_27 ] == V_29 ) ) {
F_30 () ;
continue;
}
F_31 ( & V_26 [ V_27 ] . V_19 ) ;
F_32 ( & V_26 [ V_27 ] . V_22 ) ;
( V_25 [ V_27 ] ) ( & V_26 [ V_27 ] . V_19 , F_26 ) ;
}
for ( V_27 = 0 ; V_27 < V_24 ; V_27 ++ ) {
if ( V_23 &&
( V_25 [ V_27 ] == V_28 ||
V_25 [ V_27 ] == V_29 ) )
continue;
F_33 ( & V_26 [ V_27 ] . V_22 ) ;
F_34 ( & V_26 [ V_27 ] . V_19 ) ;
}
}
void F_35 ( struct V_18 * V_19 )
{
F_36 ( V_19 , & V_30 ) ;
}
void F_37 ( struct V_18 * V_19 )
{
F_38 ( V_19 , & V_30 ) ;
}
static int F_39 ( void * V_31 , enum V_32 V_33 )
{
struct V_18 * V_19 = V_31 ;
switch ( V_33 ) {
case V_34 :
F_36 ( V_19 , & V_30 ) ;
F_40 ( V_19 , & V_30 ) ;
return 0 ;
default:
return 1 ;
}
}
void F_31 ( struct V_18 * V_19 )
{
F_41 ( V_19 , & V_30 ) ;
}
void F_34 ( struct V_18 * V_19 )
{
F_38 ( V_19 , & V_30 ) ;
}
void F_42 ( const char * V_35 , struct V_18 * V_36 ,
unsigned long V_37 ,
unsigned long V_38 , unsigned long V_39 )
{
F_43 ( V_35 , V_36 , V_37 , V_38 , V_39 ) ;
}
int F_44 ( void )
{
int V_40 = F_20 ( V_41 ) ;
if ( V_40 < 3 ) {
F_45 ( V_41 , 3 ) ;
V_40 = 3 ;
} else if ( V_40 > 300 ) {
F_45 ( V_41 , 300 ) ;
V_40 = 300 ;
}
return V_40 * V_42 + V_43 ;
}
void F_46 ( void )
{
if ( ! V_44 )
V_44 = 2 ;
}
void F_47 ( void )
{
if ( V_44 == 2 )
V_44 = 0 ;
}
static int F_48 ( struct V_45 * V_46 , unsigned long V_47 , void * V_48 )
{
V_44 = 1 ;
return V_49 ;
}
static int T_3 F_49 ( void )
{
F_50 ( & V_50 , & V_51 ) ;
return 0 ;
}
void F_51 ( struct V_18 * V_36 , T_4 V_52 )
{
unsigned long V_53 ;
bool V_54 ;
V_36 -> V_55 = NULL ;
V_36 -> V_52 = V_52 ;
F_52 ( & V_56 , V_53 ) ;
V_54 = ! V_57 ;
* V_58 = V_36 ;
V_58 = & V_36 -> V_55 ;
F_53 ( & V_56 , V_53 ) ;
if ( V_54 ) {
F_54 () ;
F_55 ( & V_59 ) ;
}
}
void F_56 ( void )
{
F_57 ( ! V_15 ,
L_1 ) ;
F_58 ( F_51 ) ;
}
void F_59 ( void )
{
F_56 () ;
}
static void F_60 ( struct V_9 * V_10 ,
bool V_60 , bool * V_61 )
{
int V_62 ;
if ( ! F_20 ( V_10 -> V_63 ) ||
V_10 -> V_64 != F_20 ( V_10 -> V_65 ) ||
! F_20 ( V_10 -> V_66 ) ||
( F_15 ( V_67 ) &&
! F_61 ( V_10 ) && V_10 -> V_68 >= 0 ) ) {
F_45 ( V_10 -> V_63 , false ) ;
F_62 ( & V_10 -> V_69 ) ;
F_63 ( V_10 ) ;
return;
}
if ( ! V_60 )
return;
if ( * V_61 ) {
F_64 ( L_2 ) ;
* V_61 = false ;
}
V_62 = F_65 ( V_10 ) ;
F_66 ( L_3 ,
V_10 , L_4 [ F_61 ( V_10 ) ] ,
L_5 [ V_62 < 0 || ! F_67 ( V_62 ) ] ,
V_10 -> V_64 , V_10 -> V_65 , V_10 -> V_63 ,
V_10 -> V_68 , V_62 ) ;
F_68 ( V_10 ) ;
}
static int T_5 F_69 ( void * V_70 )
{
unsigned long V_53 ;
struct V_9 * V_71 , * V_10 ;
unsigned long V_72 ;
struct V_18 * V_73 ;
struct V_18 * V_55 ;
F_70 ( V_74 ) ;
F_71 ( V_7 ) ;
for (; ; ) {
F_52 ( & V_56 , V_53 ) ;
V_73 = V_57 ;
V_57 = NULL ;
V_58 = & V_57 ;
F_53 ( & V_56 , V_53 ) ;
if ( ! V_73 ) {
F_72 ( V_59 ,
V_57 ) ;
if ( ! V_57 ) {
F_73 ( F_74 ( V_7 ) ) ;
F_75 ( V_42 / 10 ) ;
}
continue;
}
F_76 () ;
F_77 () ;
F_78 (g, t) {
if ( V_10 != V_7 && F_20 ( V_10 -> V_66 ) &&
! F_61 ( V_10 ) ) {
F_79 ( V_10 ) ;
V_10 -> V_64 = F_20 ( V_10 -> V_65 ) ;
F_45 ( V_10 -> V_63 , true ) ;
F_80 ( & V_10 -> V_69 ,
& V_74 ) ;
}
}
F_81 () ;
F_82 ( & V_75 ) ;
V_72 = V_76 ;
while ( ! F_83 ( & V_74 ) ) {
bool V_61 ;
bool V_60 ;
int V_77 ;
struct V_9 * V_78 ;
F_75 ( V_42 ) ;
V_77 = F_20 ( V_79 ) ;
V_60 = V_77 > 0 &&
F_84 ( V_76 , V_72 + V_77 ) ;
if ( V_60 )
V_72 = V_76 ;
V_61 = true ;
F_73 ( F_74 ( V_7 ) ) ;
F_85 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_60 ( V_10 , V_60 , & V_61 ) ;
F_86 () ;
}
}
F_76 () ;
while ( V_73 ) {
V_55 = V_73 -> V_55 ;
F_87 () ;
V_73 -> V_52 ( V_73 ) ;
F_88 () ;
V_73 = V_55 ;
F_86 () ;
}
F_89 ( V_42 / 10 ) ;
}
}
static void F_54 ( void )
{
static F_90 ( V_80 ) ;
static struct V_9 * V_81 ;
struct V_9 * V_10 ;
if ( F_20 ( V_81 ) ) {
F_91 () ;
return;
}
F_92 ( & V_80 ) ;
if ( V_81 ) {
F_93 ( & V_80 ) ;
return;
}
V_10 = F_94 ( F_69 , NULL , L_6 ) ;
F_95 ( F_96 ( V_10 ) ) ;
F_91 () ;
F_45 ( V_81 , V_10 ) ;
F_93 ( & V_80 ) ;
}
static void F_97 ( struct V_18 * V_82 )
{
V_83 ++ ;
F_98 ( L_7 , V_83 ) ;
}
static void F_99 ( void )
{
static struct V_18 V_19 ;
V_28 ( & V_19 , F_97 ) ;
}
static void F_100 ( void )
{
static struct V_18 V_19 ;
V_29 ( & V_19 , F_97 ) ;
}
static void F_101 ( void )
{
static struct V_18 V_19 ;
F_102 ( & V_19 , F_97 ) ;
}
void F_103 ( void )
{
F_98 ( L_8 ) ;
if ( V_84 )
F_99 () ;
if ( V_85 )
F_100 () ;
if ( V_86 )
F_101 () ;
}
static int F_104 ( void )
{
int V_87 = 0 ;
int V_88 = 0 ;
if ( V_84 ) {
V_88 ++ ;
F_105 () ;
}
if ( V_85 ) {
V_88 ++ ;
F_106 () ;
}
if ( V_86 ) {
V_88 ++ ;
F_107 () ;
}
if ( V_83 != V_88 ) {
F_73 ( 1 ) ;
V_87 = - 1 ;
}
return V_87 ;
}
void F_103 ( void ) {}
