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
int V_33 ;
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ ) {
if ( V_28 &&
( V_30 [ V_32 ] == V_34 ||
V_30 [ V_32 ] == V_35 ) ) {
F_40 () ;
continue;
}
F_41 ( & V_31 [ V_32 ] . V_24 ) ;
F_42 ( & V_31 [ V_32 ] . V_27 ) ;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
if ( V_30 [ V_33 ] == V_30 [ V_32 ] )
break;
if ( V_33 == V_32 )
( V_30 [ V_32 ] ) ( & V_31 [ V_32 ] . V_24 , F_36 ) ;
}
for ( V_32 = 0 ; V_32 < V_29 ; V_32 ++ ) {
if ( V_28 &&
( V_30 [ V_32 ] == V_34 ||
V_30 [ V_32 ] == V_35 ) )
continue;
for ( V_33 = 0 ; V_33 < V_32 ; V_33 ++ )
if ( V_30 [ V_33 ] == V_30 [ V_32 ] )
break;
if ( V_33 == V_32 )
F_43 ( & V_31 [ V_32 ] . V_27 ) ;
F_44 ( & V_31 [ V_32 ] . V_24 ) ;
}
}
void F_45 ( struct V_23 * V_24 )
{
F_46 ( V_24 , & V_36 ) ;
}
void F_47 ( struct V_23 * V_24 )
{
F_48 ( V_24 , & V_36 ) ;
}
static bool F_49 ( void * V_37 )
{
return true ;
}
void F_41 ( struct V_23 * V_24 )
{
F_50 ( V_24 , & V_36 ) ;
}
void F_44 ( struct V_23 * V_24 )
{
F_48 ( V_24 , & V_36 ) ;
}
void F_51 ( const char * V_38 , struct V_23 * V_39 ,
unsigned long V_40 ,
unsigned long V_41 , unsigned long V_42 )
{
F_52 ( V_38 , V_39 , V_40 , V_41 , V_42 ) ;
}
int F_53 ( void )
{
int V_43 = F_8 ( V_44 ) ;
if ( V_43 < 3 ) {
F_16 ( V_44 , 3 ) ;
V_43 = 3 ;
} else if ( V_43 > 300 ) {
F_16 ( V_44 , 300 ) ;
V_43 = 300 ;
}
return V_43 * V_45 + V_46 ;
}
void F_54 ( void )
{
if ( ! V_47 )
V_47 = 2 ;
}
void F_55 ( void )
{
if ( V_47 == 2 )
V_47 = 0 ;
}
static int F_56 ( struct V_48 * V_49 , unsigned long V_50 , void * V_51 )
{
V_47 = 1 ;
return V_52 ;
}
static int T_1 F_57 ( void )
{
F_58 ( & V_53 , & V_54 ) ;
return 0 ;
}
void F_59 ( struct V_23 * V_39 , T_4 V_55 )
{
unsigned long V_56 ;
bool V_57 ;
bool V_58 = F_8 ( V_59 ) ;
V_39 -> V_60 = NULL ;
V_39 -> V_55 = V_55 ;
F_60 ( & V_61 , V_56 ) ;
V_57 = ! V_62 ;
* V_63 = V_39 ;
V_63 = & V_39 -> V_60 ;
F_61 ( & V_61 , V_56 ) ;
if ( ( V_57 && V_58 ) ||
( ! V_58 && ! F_62 ( V_56 ) ) ) {
F_63 () ;
F_64 ( & V_64 ) ;
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
bool V_65 , bool * V_66 )
{
int V_67 ;
if ( ! F_8 ( V_15 -> V_68 ) ||
V_15 -> V_69 != F_8 ( V_15 -> V_70 ) ||
! F_8 ( V_15 -> V_71 ) ||
( F_18 ( V_72 ) &&
! F_70 ( V_15 ) && V_15 -> V_73 >= 0 ) ) {
F_16 ( V_15 -> V_68 , false ) ;
F_71 ( & V_15 -> V_74 ) ;
F_72 ( V_15 ) ;
return;
}
F_73 ( V_15 ) ;
if ( ! V_65 )
return;
if ( * V_66 ) {
F_74 ( L_2 ) ;
* V_66 = false ;
}
V_67 = F_75 ( V_15 ) ;
F_76 ( L_3 ,
V_15 , L_4 [ F_70 ( V_15 ) ] ,
L_5 [ V_67 < 0 || ! F_77 ( V_67 ) ] ,
V_15 -> V_69 , V_15 -> V_70 , V_15 -> V_68 ,
V_15 -> V_73 , V_67 ) ;
F_78 ( V_15 ) ;
}
static int T_5 F_79 ( void * V_75 )
{
unsigned long V_56 ;
struct V_14 * V_76 , * V_15 ;
unsigned long V_77 ;
struct V_23 * V_78 ;
struct V_23 * V_60 ;
F_80 ( V_79 ) ;
F_81 ( V_12 ) ;
for (; ; ) {
F_60 ( & V_61 , V_56 ) ;
V_78 = V_62 ;
V_62 = NULL ;
V_63 = & V_62 ;
F_61 ( & V_61 , V_56 ) ;
if ( ! V_78 ) {
F_82 ( V_64 ,
V_62 ) ;
if ( ! V_62 ) {
F_83 ( F_84 ( V_12 ) ) ;
F_85 ( V_45 / 10 ) ;
}
continue;
}
F_21 () ;
F_86 () ;
F_87 (g, t) {
if ( V_15 != V_12 && F_8 ( V_15 -> V_71 ) &&
! F_70 ( V_15 ) ) {
F_88 ( V_15 ) ;
V_15 -> V_69 = F_8 ( V_15 -> V_70 ) ;
F_16 ( V_15 -> V_68 , true ) ;
F_89 ( & V_15 -> V_74 ,
& V_79 ) ;
}
}
F_90 () ;
F_91 ( & V_80 ) ;
V_77 = V_81 ;
while ( ! F_92 ( & V_79 ) ) {
bool V_66 ;
bool V_65 ;
int V_82 ;
struct V_14 * V_83 ;
F_85 ( V_45 ) ;
V_82 = F_8 ( V_84 ) ;
V_65 = V_82 > 0 &&
F_93 ( V_81 , V_77 + V_82 ) ;
if ( V_65 )
V_77 = V_81 ;
V_66 = true ;
F_83 ( F_84 ( V_12 ) ) ;
F_94 (t, t1, &rcu_tasks_holdouts,
rcu_tasks_holdout_list) {
F_69 ( V_15 , V_65 , & V_66 ) ;
F_95 () ;
}
}
F_21 () ;
while ( V_78 ) {
V_60 = V_78 -> V_60 ;
F_96 () ;
V_78 -> V_55 ( V_78 ) ;
F_97 () ;
V_78 = V_60 ;
F_95 () ;
}
F_98 ( V_45 / 10 ) ;
}
}
static void F_63 ( void )
{
static F_99 ( V_85 ) ;
struct V_14 * V_15 ;
if ( F_8 ( V_59 ) ) {
F_100 () ;
return;
}
F_101 ( & V_85 ) ;
if ( V_59 ) {
F_102 ( & V_85 ) ;
return;
}
V_15 = F_103 ( F_79 , NULL , L_6 ) ;
F_104 ( F_105 ( V_15 ) ) ;
F_100 () ;
F_16 ( V_59 , V_15 ) ;
F_102 ( & V_85 ) ;
}
static void T_1 F_106 ( void )
{
#ifdef F_107
if ( V_84 != V_86 )
F_108 ( L_7 , V_84 ) ;
else
F_108 ( L_8 ) ;
#endif
}
static void F_109 ( struct V_23 * V_87 )
{
V_88 ++ ;
F_108 ( L_9 , V_88 ) ;
}
static void F_110 ( void )
{
static struct V_23 V_24 ;
V_34 ( & V_24 , F_109 ) ;
}
static void F_111 ( void )
{
static struct V_23 V_24 ;
V_35 ( & V_24 , F_109 ) ;
}
static void F_112 ( void )
{
static struct V_23 V_24 ;
F_113 ( & V_24 , F_109 ) ;
}
void F_114 ( void )
{
F_108 ( L_10 ) ;
if ( V_89 )
F_110 () ;
if ( V_90 )
F_111 () ;
if ( V_91 )
F_112 () ;
F_17 () ;
}
static int F_115 ( void )
{
int V_92 = 0 ;
int V_93 = 0 ;
if ( V_89 ) {
V_93 ++ ;
F_116 () ;
}
if ( V_90 ) {
V_93 ++ ;
F_117 () ;
}
if ( V_91 ) {
V_93 ++ ;
F_118 () ;
}
if ( V_88 != V_93 ) {
F_83 ( 1 ) ;
V_92 = - 1 ;
}
return V_92 ;
}
void F_114 ( void ) {}
void T_1 F_119 ( void )
{
if ( V_4 )
F_108 ( L_11 ) ;
else if ( V_9 )
F_108 ( L_12 ) ;
else if ( V_7 )
F_108 ( L_13 ) ;
if ( V_47 )
F_108 ( L_14 ) ;
if ( V_44 != V_94 )
F_108 ( L_15 , V_44 ) ;
F_106 () ;
}
