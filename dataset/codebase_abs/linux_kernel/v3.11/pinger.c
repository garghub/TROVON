int F_1 ()
{
return V_1 ;
}
struct V_2 *
F_2 ( struct V_3 * V_4 )
{
struct V_2 * V_5 ;
V_5 = F_3 ( V_4 , & V_6 ,
V_7 , V_8 ) ;
if ( V_5 ) {
F_4 ( V_5 ) ;
V_5 -> V_9 = V_5 -> V_10 = 1 ;
}
return V_5 ;
}
int F_5 ( struct V_11 * V_12 )
{
int V_13 ;
struct V_2 * V_5 ;
V_14 ;
V_5 = F_2 ( V_12 -> V_15 . V_16 . V_17 ) ;
if ( V_5 == NULL )
RETURN ( - V_18 ) ;
V_5 -> V_19 = V_20 ;
V_13 = F_6 ( V_5 ) ;
F_7 ( V_5 ) ;
RETURN ( V_13 ) ;
}
int F_8 ( struct V_3 * V_4 )
{
struct V_2 * V_5 ;
V_14 ;
V_5 = F_2 ( V_4 ) ;
if ( V_5 == NULL ) {
F_9 ( L_1 ,
V_4 -> V_21 -> V_22 . V_23 ,
F_10 ( V_4 -> V_21 ) ) ;
RETURN ( - V_18 ) ;
}
F_11 ( V_24 , V_5 , L_2 ,
V_4 -> V_21 -> V_22 . V_23 , F_10 ( V_4 -> V_21 ) ) ;
F_12 ( V_5 , V_25 , - 1 ) ;
RETURN ( 0 ) ;
}
void F_13 ( struct V_3 * V_4 , int V_26 )
{
int time = V_26 ? V_27 : V_28 ;
if ( V_4 -> V_29 == V_30 ) {
int V_31 = F_14 ( int , V_32 ,
V_33 ? 0 :
F_15 ( & V_4 -> V_34 . V_35 ) ) ;
time = F_16 ( time , V_31 ) ;
}
V_4 -> V_36 = F_17 ( time ) ;
}
void F_18 ( struct V_3 * V_4 )
{
V_4 -> V_36 = F_19 () ;
}
static inline int F_20 ( struct V_3 * V_4 )
{
return ( V_4 -> V_37 ||
F_21 ( V_38 ) ) ;
}
static inline int F_22 ( struct V_3 * V_4 )
{
if ( V_4 -> V_39 )
return F_17 ( V_40 / 2 ) ;
else
return F_17 ( V_40 ) ;
}
T_1 F_23 ( T_2 time )
{
struct V_41 * V_42 ;
T_2 V_43 = V_28 ;
F_24 ( & V_44 ) ;
F_25 (item, &timeout_list, ti_chain) {
int V_45 = V_42 -> V_45 ;
if ( V_43 > V_45 )
V_43 = V_45 ;
break;
}
F_26 ( & V_44 ) ;
return F_27 ( F_28 ( time , F_29 ( V_43 ) ) ,
F_19 () ) ;
}
T_2 F_30 ( void )
{
return V_46 ;
}
void F_31 ( struct V_3 * V_4 )
{
#if 0
if (imp->imp_no_timeout)
return;
imp->imp_no_timeout = 1;
atomic_inc(&suspend_timeouts);
CDEBUG(D_HA|D_WARNING, "deactivate timeouts %u\n",
atomic_read(&suspend_timeouts));
#endif
}
void F_32 ( struct V_3 * V_4 )
{
#if 0
if (!imp->imp_no_timeout)
return;
imp->imp_no_timeout = 0;
LASSERT(atomic_read(&suspend_timeouts) > 0);
if (atomic_dec_and_test(&suspend_timeouts)) {
suspend_wakeup_time = cfs_time_current();
wake_up(&suspend_timeouts_waitq);
}
CDEBUG(D_HA|D_WARNING, "activate timeouts %u\n",
atomic_read(&suspend_timeouts));
#endif
}
int F_33 ( void )
{
if ( F_34 ( & V_47 ) )
return 1 ;
return 0 ;
}
int F_35 ( struct V_2 * V_5 )
{
struct V_48 V_49 ;
if ( F_34 ( & V_47 ) ) {
F_11 ( V_50 , V_5 , L_3 ,
F_34 ( & V_47 ) ) ;
V_49 = F_36 ( NULL , NULL ) ;
F_37 ( V_51 ,
F_34 ( & V_47 ) == 0 , & V_49 ) ;
F_11 ( V_50 , V_5 , L_4 ) ;
return 1 ;
}
return 0 ;
}
void F_38 ( void )
{
F_39 ( V_52 , L_5 ) ;
V_53 = true ;
}
void F_40 ( void )
{
F_39 ( V_52 , L_6 ) ;
V_53 = false ;
}
static void F_41 ( struct V_3 * V_4 ,
unsigned long V_54 )
{
int V_55 ;
int V_56 ;
int V_57 ;
int V_58 ;
F_42 ( & V_4 -> V_59 ) ;
V_55 = V_4 -> V_29 ;
V_56 = V_4 -> V_60 ;
V_57 = V_4 -> V_61 ;
V_58 = V_53 && F_43 ( & V_4 -> V_62 , V_63 ) ;
V_4 -> V_60 = 0 ;
if ( F_44 ( V_4 -> V_36 - 5 * V_64 , V_54 ) &&
! V_56 ) {
F_45 ( & V_4 -> V_59 ) ;
return;
}
V_4 -> V_61 = 0 ;
F_45 ( & V_4 -> V_59 ) ;
F_39 ( V_55 == V_20 ? V_24 : V_52 , L_7
L_8 ,
V_4 -> V_21 -> V_22 . V_23 , F_10 ( V_4 -> V_21 ) ,
F_46 ( V_55 ) , V_55 , V_56 , V_57 ,
V_4 -> V_37 , V_4 -> V_65 , V_58 ) ;
if ( V_55 == V_30 && ! F_20 ( V_4 ) ) {
V_4 -> V_36 = F_22 ( V_4 ) ;
if ( ! V_4 -> V_66 )
F_47 ( V_4 ) ;
} else if ( V_55 != V_20 ||
V_4 -> V_21 -> V_67 ||
F_20 ( V_4 ) ) {
F_39 ( V_52 , L_9
L_10 ,
V_4 -> V_21 -> V_22 . V_23 , F_10 ( V_4 -> V_21 ) ,
F_46 ( V_55 ) ) ;
} else if ( ( V_4 -> V_65 && ! V_58 ) || V_57 || V_56 ) {
F_8 ( V_4 ) ;
}
}
static int F_48 ( void * V_68 )
{
struct V_69 * V_70 = (struct V_69 * ) V_68 ;
V_14 ;
F_49 ( V_70 , V_71 ) ;
F_50 ( & V_70 -> V_72 ) ;
while ( 1 ) {
T_2 V_54 = F_19 () ;
struct V_48 V_49 ;
T_1 V_73 ;
struct V_41 * V_42 ;
struct V_74 * V_75 ;
F_24 ( & V_44 ) ;
F_25 (item, &timeout_list, ti_chain) {
V_42 -> V_76 ( V_42 , V_42 -> V_77 ) ;
}
F_51 (iter, &pinger_imports) {
struct V_3 * V_4 =
F_52 ( V_75 , struct V_3 ,
V_78 ) ;
F_41 ( V_4 , V_54 ) ;
if ( V_4 -> V_65 && V_4 -> V_36 &&
F_53 ( V_4 -> V_36 ,
F_28 ( V_54 ,
F_29 ( V_28 ) ) ) )
F_13 ( V_4 , 0 ) ;
}
F_26 ( & V_44 ) ;
F_54 () ;
V_73 = F_23 ( V_54 ) ;
F_39 ( V_24 , L_11 V_79 L_12
V_80 L_13 , V_73 ,
F_28 ( V_54 , F_29 ( V_28 ) ) ) ;
if ( V_73 > 0 ) {
V_49 = F_55 ( F_14 ( T_1 ,
V_73 ,
F_29 ( 1 ) ) ,
NULL , NULL ) ;
F_37 ( V_70 -> V_72 ,
F_56 ( V_70 ) ||
F_57 ( V_70 ) ,
& V_49 ) ;
if ( F_58 ( V_70 , V_81 ) ) {
EXIT ;
break;
} else {
F_58 ( V_70 , V_82 ) ;
}
}
}
F_49 ( V_70 , V_83 ) ;
F_50 ( & V_70 -> V_72 ) ;
F_39 ( V_50 , L_14 , F_59 () ) ;
return 0 ;
}
int F_60 ( void )
{
struct V_48 V_49 = { 0 } ;
int V_13 ;
V_14 ;
if ( V_84 != NULL )
RETURN ( - V_85 ) ;
F_61 ( V_84 ) ;
if ( V_84 == NULL )
RETURN ( - V_18 ) ;
F_62 ( & V_84 -> V_72 ) ;
F_62 ( & V_51 ) ;
strcpy ( V_84 -> V_86 , L_15 ) ;
V_13 = F_63 ( F_64 ( F_48 ,
V_84 , V_84 -> V_86 ) ) ;
if ( F_65 ( V_13 ) ) {
F_9 ( L_16 , V_13 ) ;
F_66 ( V_84 , sizeof( * V_84 ) ) ;
V_84 = NULL ;
RETURN ( V_13 ) ;
}
F_37 ( V_84 -> V_72 ,
F_67 ( V_84 ) , & V_49 ) ;
if ( V_1 )
F_68 ( L_17
L_18
L_19
L_20
L_21 ) ;
RETURN ( 0 ) ;
}
int F_69 ( void )
{
struct V_48 V_49 = { 0 } ;
int V_13 = 0 ;
V_14 ;
if ( V_84 == NULL )
RETURN ( - V_85 ) ;
F_70 () ;
F_24 ( & V_44 ) ;
F_49 ( V_84 , V_81 ) ;
F_50 ( & V_84 -> V_72 ) ;
F_26 ( & V_44 ) ;
F_37 ( V_84 -> V_72 ,
F_71 ( V_84 ) , & V_49 ) ;
F_72 ( V_84 ) ;
V_84 = NULL ;
RETURN ( V_13 ) ;
}
void F_73 ( struct V_3 * V_4 )
{
F_13 ( V_4 , 0 ) ;
}
void F_74 ( struct V_3 * V_4 )
{
F_13 ( V_4 , 1 ) ;
F_75 ( F_76 ( & V_4 -> V_59 ) ) ;
if ( V_4 -> V_29 != V_20 ||
F_43 ( & V_4 -> V_62 , V_63 ) )
V_4 -> V_61 = 1 ;
}
int F_77 ( struct V_3 * V_4 )
{
V_14 ;
if ( ! F_78 ( & V_4 -> V_78 ) )
RETURN ( - V_85 ) ;
F_24 ( & V_44 ) ;
F_39 ( V_52 , L_22 ,
V_4 -> V_21 -> V_22 . V_23 , F_10 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 -> V_67 = 0 ;
F_13 ( V_4 , 0 ) ;
F_79 ( & V_4 -> V_78 , & V_87 ) ;
F_80 ( V_4 ) ;
F_81 () ;
F_26 ( & V_44 ) ;
RETURN ( 0 ) ;
}
int F_82 ( struct V_3 * V_4 )
{
V_14 ;
if ( F_78 ( & V_4 -> V_78 ) )
RETURN ( - V_88 ) ;
F_24 ( & V_44 ) ;
F_83 ( & V_4 -> V_78 ) ;
F_39 ( V_52 , L_23 ,
V_4 -> V_21 -> V_22 . V_23 , F_10 ( V_4 -> V_21 ) ) ;
V_4 -> V_21 -> V_67 = 1 ;
F_84 ( V_4 ) ;
F_26 ( & V_44 ) ;
RETURN ( 0 ) ;
}
struct V_41 * F_85 ( int time , enum V_89 V_90 ,
T_3 V_91 , void * V_92 )
{
struct V_41 * V_93 ;
F_61 ( V_93 ) ;
if ( ! V_93 )
return ( NULL ) ;
F_86 ( & V_93 -> V_94 ) ;
F_86 ( & V_93 -> V_95 ) ;
V_93 -> V_45 = time ;
V_93 -> V_96 = V_90 ;
V_93 -> V_76 = V_91 ;
V_93 -> V_77 = V_92 ;
return V_93 ;
}
static struct V_41 *
F_87 ( int time , enum V_89 V_90 ,
T_3 V_91 , void * V_92 )
{
struct V_41 * V_42 , * V_97 ;
F_75 ( F_88 ( & V_44 ) ) ;
F_25 (item, &timeout_list, ti_chain)
if ( V_42 -> V_96 == V_90 )
goto V_98;
V_42 = F_85 ( time , V_90 , V_91 , V_92 ) ;
if ( V_42 ) {
F_89 (tmp, &timeout_list, ti_chain) {
if ( V_97 -> V_45 < time ) {
F_90 ( & V_42 -> V_95 , & V_97 -> V_95 ) ;
goto V_98;
}
}
F_90 ( & V_42 -> V_95 , & V_99 ) ;
}
V_98:
return V_42 ;
}
int F_91 ( int time , enum V_89 V_90 ,
T_3 V_91 , void * V_92 ,
struct V_74 * V_100 )
{
struct V_41 * V_93 ;
F_24 ( & V_44 ) ;
V_93 = F_87 ( time , V_90 , V_91 , V_92 ) ;
if ( ! V_93 ) {
F_26 ( & V_44 ) ;
return ( - V_101 ) ;
}
F_90 ( V_100 , & V_93 -> V_94 ) ;
F_26 ( & V_44 ) ;
return 0 ;
}
int F_92 ( struct V_74 * V_100 ,
enum V_89 V_90 )
{
struct V_41 * V_93 = NULL , * V_42 ;
if ( F_78 ( V_100 ) )
return 0 ;
F_24 ( & V_44 ) ;
F_83 ( V_100 ) ;
F_25 (item, &timeout_list, ti_chain) {
if ( V_42 -> V_96 == V_90 ) {
V_93 = V_42 ;
break;
}
}
F_93 ( V_93 != NULL , L_24 ) ;
if ( F_78 ( & V_93 -> V_94 ) ) {
F_94 ( & V_93 -> V_95 ) ;
F_72 ( V_93 ) ;
}
F_26 ( & V_44 ) ;
return 0 ;
}
int F_70 ( void )
{
struct V_41 * V_42 , * V_97 ;
F_24 ( & V_44 ) ;
F_95 (item, tmp, &timeout_list, ti_chain) {
F_75 ( F_78 ( & V_42 -> V_94 ) ) ;
F_94 ( & V_42 -> V_95 ) ;
F_72 ( V_42 ) ;
}
F_26 ( & V_44 ) ;
return 0 ;
}
void F_81 ()
{
F_96 ( V_84 , V_82 ) ;
F_50 ( & V_84 -> V_72 ) ;
}
int F_97 ( struct V_102 * exp )
{
struct V_11 * V_12 ;
F_42 ( & V_103 ) ;
if ( V_104 != V_105 ) {
F_45 ( & V_103 ) ;
return 1 ;
}
V_12 = F_98 ( exp ) ;
if ( F_78 ( & V_12 -> V_106 ) ) {
F_99 ( V_12 , L_25 , V_12 ) ;
F_90 ( & V_12 -> V_106 , & V_107 ) ;
}
F_45 ( & V_103 ) ;
F_50 ( & V_108 ) ;
return 0 ;
}
static int F_100 ( void * V_68 )
{
struct V_11 * V_12 ;
struct V_102 * exp ;
struct V_48 V_49 = { 0 } ;
T_4 V_109 ;
V_14 ;
F_101 () ;
F_39 ( V_52 , L_26 ) ;
V_104 = V_105 ;
while ( 1 ) {
F_37 ( V_108 , ( ! F_78 ( & V_107 ) ) ||
( V_104 == V_110 ) , & V_49 ) ;
if ( ( V_104 == V_110 ) && F_78 ( & V_107 ) )
break;
F_42 ( & V_103 ) ;
V_12 = F_52 ( V_107 . V_111 , struct V_11 ,
V_106 ) ;
F_45 ( & V_103 ) ;
V_109 = F_102 () - V_112 ;
F_39 ( V_52 , L_27 ,
V_12 -> V_113 , V_109 ) ;
F_42 ( & V_12 -> V_114 ) ;
while ( ! F_78 ( & V_12 -> V_115 ) ) {
exp = F_52 ( V_12 -> V_115 . V_111 ,
struct V_102 ,
V_116 ) ;
if ( V_109 > exp -> V_117 ) {
F_103 ( exp ) ;
F_45 ( & V_12 -> V_114 ) ;
F_104 ( L_28
L_29
L_30
L_31
L_32 ,
V_12 -> V_113 ,
F_105 ( & exp -> V_118 ) ,
F_106 ( exp ) ,
( long ) ( F_102 () -
exp -> V_117 ) ,
exp , ( long ) F_102 () ,
( long ) V_109 ,
( long ) exp -> V_117 ) ;
F_39 ( V_52 , L_33 ,
exp -> V_117 ) ;
F_107 ( exp ) ;
F_108 ( exp ) ;
F_42 ( & V_12 -> V_114 ) ;
} else {
break;
}
}
F_45 ( & V_12 -> V_114 ) ;
F_42 ( & V_103 ) ;
F_83 ( & V_12 -> V_106 ) ;
F_45 ( & V_103 ) ;
F_109 ( V_12 , L_25 , V_12 ) ;
}
F_39 ( V_52 , L_34 ) ;
RETURN ( 0 ) ;
}
void F_110 ( void )
{
T_5 * V_119 ;
if ( ++ V_120 > 1 )
return;
F_62 ( & V_108 ) ;
V_119 = F_64 ( F_100 , NULL , L_35 ) ;
if ( F_111 ( V_119 ) ) {
V_120 -- ;
F_9 ( L_36 ,
F_63 ( V_119 ) ) ;
}
}
void F_112 ( void )
{
if ( -- V_120 > 0 )
return;
V_104 = V_110 ;
F_50 ( & V_108 ) ;
}
