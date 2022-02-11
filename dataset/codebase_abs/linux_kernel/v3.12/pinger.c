int F_1 ( void )
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
V_5 = F_2 ( V_12 -> V_14 . V_15 . V_16 ) ;
if ( V_5 == NULL )
return - V_17 ;
V_5 -> V_18 = V_19 ;
V_13 = F_6 ( V_5 ) ;
F_7 ( V_5 ) ;
return V_13 ;
}
int F_8 ( struct V_3 * V_4 )
{
struct V_2 * V_5 ;
V_5 = F_2 ( V_4 ) ;
if ( V_5 == NULL ) {
F_9 ( L_1 ,
V_4 -> V_20 -> V_21 . V_22 ,
F_10 ( V_4 -> V_20 ) ) ;
return - V_17 ;
}
F_11 ( V_23 , V_5 , L_2 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ) ;
F_12 ( V_5 , V_24 , - 1 ) ;
return 0 ;
}
void F_13 ( struct V_3 * V_4 , int V_25 )
{
int time = V_25 ? V_26 : V_27 ;
if ( V_4 -> V_28 == V_29 ) {
int V_30 = F_14 ( int , V_31 ,
V_32 ? 0 :
F_15 ( & V_4 -> V_33 . V_34 ) ) ;
time = F_16 ( time , V_30 ) ;
}
V_4 -> V_35 = F_17 ( time ) ;
}
void F_18 ( struct V_3 * V_4 )
{
V_4 -> V_35 = F_19 () ;
}
static inline int F_20 ( struct V_3 * V_4 )
{
return ( V_4 -> V_36 ||
F_21 ( V_37 ) ) ;
}
static inline int F_22 ( struct V_3 * V_4 )
{
if ( V_4 -> V_38 )
return F_17 ( V_39 / 2 ) ;
else
return F_17 ( V_39 ) ;
}
T_1 F_23 ( T_2 time )
{
struct V_40 * V_41 ;
T_2 V_42 = V_27 ;
F_24 ( & V_43 ) ;
F_25 (item, &timeout_list, ti_chain) {
int V_44 = V_41 -> V_44 ;
if ( V_42 > V_44 )
V_42 = V_44 ;
break;
}
F_26 ( & V_43 ) ;
return F_27 ( F_28 ( time , F_29 ( V_42 ) ) ,
F_19 () ) ;
}
T_2 F_30 ( void )
{
return V_45 ;
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
if ( F_34 ( & V_46 ) )
return 1 ;
return 0 ;
}
int F_35 ( struct V_2 * V_5 )
{
struct V_47 V_48 ;
if ( F_34 ( & V_46 ) ) {
F_11 ( V_49 , V_5 , L_3 ,
F_34 ( & V_46 ) ) ;
V_48 = F_36 ( NULL , NULL ) ;
F_37 ( V_50 ,
F_34 ( & V_46 ) == 0 , & V_48 ) ;
F_11 ( V_49 , V_5 , L_4 ) ;
return 1 ;
}
return 0 ;
}
void F_38 ( void )
{
F_39 ( V_51 , L_5 ) ;
V_52 = true ;
}
void F_40 ( void )
{
F_39 ( V_51 , L_6 ) ;
V_52 = false ;
}
static void F_41 ( struct V_3 * V_4 ,
unsigned long V_53 )
{
int V_54 ;
int V_55 ;
int V_56 ;
int V_57 ;
F_42 ( & V_4 -> V_58 ) ;
V_54 = V_4 -> V_28 ;
V_55 = V_4 -> V_59 ;
V_56 = V_4 -> V_60 ;
V_57 = V_52 && F_43 ( & V_4 -> V_61 , V_62 ) ;
V_4 -> V_59 = 0 ;
if ( F_44 ( V_4 -> V_35 - 5 * V_63 , V_53 ) &&
! V_55 ) {
F_45 ( & V_4 -> V_58 ) ;
return;
}
V_4 -> V_60 = 0 ;
F_45 ( & V_4 -> V_58 ) ;
F_39 ( V_54 == V_19 ? V_23 : V_51 , L_7
L_8 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ,
F_46 ( V_54 ) , V_54 , V_55 , V_56 ,
V_4 -> V_36 , V_4 -> V_64 , V_57 ) ;
if ( V_54 == V_29 && ! F_20 ( V_4 ) ) {
V_4 -> V_35 = F_22 ( V_4 ) ;
if ( ! V_4 -> V_65 )
F_47 ( V_4 ) ;
} else if ( V_54 != V_19 ||
V_4 -> V_20 -> V_66 ||
F_20 ( V_4 ) ) {
F_39 ( V_51 , L_9
L_10 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ,
F_46 ( V_54 ) ) ;
} else if ( ( V_4 -> V_64 && ! V_57 ) || V_56 || V_55 ) {
F_8 ( V_4 ) ;
}
}
static int F_48 ( void * V_67 )
{
struct V_68 * V_69 = (struct V_68 * ) V_67 ;
F_49 ( V_69 , V_70 ) ;
F_50 ( & V_69 -> V_71 ) ;
while ( 1 ) {
T_2 V_53 = F_19 () ;
struct V_47 V_48 ;
T_1 V_72 ;
struct V_40 * V_41 ;
struct V_73 * V_74 ;
F_24 ( & V_43 ) ;
F_25 (item, &timeout_list, ti_chain) {
V_41 -> V_75 ( V_41 , V_41 -> V_76 ) ;
}
F_51 (iter, &pinger_imports) {
struct V_3 * V_4 =
F_52 ( V_74 , struct V_3 ,
V_77 ) ;
F_41 ( V_4 , V_53 ) ;
if ( V_4 -> V_64 && V_4 -> V_35 &&
F_53 ( V_4 -> V_35 ,
F_28 ( V_53 ,
F_29 ( V_27 ) ) ) )
F_13 ( V_4 , 0 ) ;
}
F_26 ( & V_43 ) ;
F_54 () ;
V_72 = F_23 ( V_53 ) ;
F_39 ( V_23 , L_11 V_78 L_12
V_79 L_13 , V_72 ,
F_28 ( V_53 , F_29 ( V_27 ) ) ) ;
if ( V_72 > 0 ) {
V_48 = F_55 ( F_14 ( T_1 ,
V_72 ,
F_29 ( 1 ) ) ,
NULL , NULL ) ;
F_37 ( V_69 -> V_71 ,
F_56 ( V_69 ) ||
F_57 ( V_69 ) ,
& V_48 ) ;
if ( F_58 ( V_69 , V_80 ) ) {
break;
} else {
F_58 ( V_69 , V_81 ) ;
}
}
}
F_49 ( V_69 , V_82 ) ;
F_50 ( & V_69 -> V_71 ) ;
F_39 ( V_49 , L_14 , F_59 () ) ;
return 0 ;
}
int F_60 ( void )
{
struct V_47 V_48 = { 0 } ;
int V_13 ;
if ( ! F_61 ( & V_83 ) &&
! F_62 ( & V_83 ) )
return - V_84 ;
F_63 ( & V_83 . V_71 ) ;
F_63 ( & V_50 ) ;
strcpy ( V_83 . V_85 , L_15 ) ;
V_13 = F_64 ( F_65 ( F_48 , & V_83 ,
L_16 , V_83 . V_85 ) ) ;
if ( F_66 ( V_13 ) ) {
F_9 ( L_17 , V_13 ) ;
return V_13 ;
}
F_37 ( V_83 . V_71 ,
F_67 ( & V_83 ) , & V_48 ) ;
if ( V_1 )
F_68 ( L_18
L_19
L_20
L_21
L_22 ) ;
return 0 ;
}
int F_69 ( void )
{
struct V_47 V_48 = { 0 } ;
int V_13 = 0 ;
if ( ! F_61 ( & V_83 ) &&
! F_62 ( & V_83 ) )
return - V_84 ;
F_70 () ;
F_49 ( & V_83 , V_80 ) ;
F_50 ( & V_83 . V_71 ) ;
F_37 ( V_83 . V_71 ,
F_62 ( & V_83 ) , & V_48 ) ;
return V_13 ;
}
void F_71 ( struct V_3 * V_4 )
{
F_13 ( V_4 , 0 ) ;
}
void F_72 ( struct V_3 * V_4 )
{
F_13 ( V_4 , 1 ) ;
F_73 ( F_74 ( & V_4 -> V_58 ) ) ;
if ( V_4 -> V_28 != V_19 ||
F_43 ( & V_4 -> V_61 , V_62 ) )
V_4 -> V_60 = 1 ;
}
int F_75 ( struct V_3 * V_4 )
{
if ( ! F_76 ( & V_4 -> V_77 ) )
return - V_84 ;
F_24 ( & V_43 ) ;
F_39 ( V_51 , L_23 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 -> V_66 = 0 ;
F_13 ( V_4 , 0 ) ;
F_77 ( & V_4 -> V_77 , & V_86 ) ;
F_78 ( V_4 ) ;
F_79 () ;
F_26 ( & V_43 ) ;
return 0 ;
}
int F_80 ( struct V_3 * V_4 )
{
if ( F_76 ( & V_4 -> V_77 ) )
return - V_87 ;
F_24 ( & V_43 ) ;
F_81 ( & V_4 -> V_77 ) ;
F_39 ( V_51 , L_24 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 -> V_66 = 1 ;
F_82 ( V_4 ) ;
F_26 ( & V_43 ) ;
return 0 ;
}
struct V_40 * F_83 ( int time , enum V_88 V_89 ,
T_3 V_90 , void * V_91 )
{
struct V_40 * V_92 ;
F_84 ( V_92 ) ;
if ( ! V_92 )
return ( NULL ) ;
F_85 ( & V_92 -> V_93 ) ;
F_85 ( & V_92 -> V_94 ) ;
V_92 -> V_44 = time ;
V_92 -> V_95 = V_89 ;
V_92 -> V_75 = V_90 ;
V_92 -> V_76 = V_91 ;
return V_92 ;
}
static struct V_40 *
F_86 ( int time , enum V_88 V_89 ,
T_3 V_90 , void * V_91 )
{
struct V_40 * V_41 , * V_96 ;
F_73 ( F_87 ( & V_43 ) ) ;
F_25 (item, &timeout_list, ti_chain)
if ( V_41 -> V_95 == V_89 )
goto V_97;
V_41 = F_83 ( time , V_89 , V_90 , V_91 ) ;
if ( V_41 ) {
F_88 (tmp, &timeout_list, ti_chain) {
if ( V_96 -> V_44 < time ) {
F_89 ( & V_41 -> V_94 , & V_96 -> V_94 ) ;
goto V_97;
}
}
F_89 ( & V_41 -> V_94 , & V_98 ) ;
}
V_97:
return V_41 ;
}
int F_90 ( int time , enum V_88 V_89 ,
T_3 V_90 , void * V_91 ,
struct V_73 * V_99 )
{
struct V_40 * V_92 ;
F_24 ( & V_43 ) ;
V_92 = F_86 ( time , V_89 , V_90 , V_91 ) ;
if ( ! V_92 ) {
F_26 ( & V_43 ) ;
return ( - V_100 ) ;
}
F_89 ( V_99 , & V_92 -> V_93 ) ;
F_26 ( & V_43 ) ;
return 0 ;
}
int F_91 ( struct V_73 * V_99 ,
enum V_88 V_89 )
{
struct V_40 * V_92 = NULL , * V_41 ;
if ( F_76 ( V_99 ) )
return 0 ;
F_24 ( & V_43 ) ;
F_81 ( V_99 ) ;
F_25 (item, &timeout_list, ti_chain) {
if ( V_41 -> V_95 == V_89 ) {
V_92 = V_41 ;
break;
}
}
F_92 ( V_92 != NULL , L_25 ) ;
if ( F_76 ( & V_92 -> V_93 ) ) {
F_93 ( & V_92 -> V_94 ) ;
F_94 ( V_92 ) ;
}
F_26 ( & V_43 ) ;
return 0 ;
}
int F_70 ( void )
{
struct V_40 * V_41 , * V_96 ;
F_24 ( & V_43 ) ;
F_95 (item, tmp, &timeout_list, ti_chain) {
F_73 ( F_76 ( & V_41 -> V_93 ) ) ;
F_93 ( & V_41 -> V_94 ) ;
F_94 ( V_41 ) ;
}
F_26 ( & V_43 ) ;
return 0 ;
}
void F_79 ( void )
{
F_96 ( & V_83 , V_81 ) ;
F_50 ( & V_83 . V_71 ) ;
}
int F_97 ( struct V_101 * exp )
{
struct V_11 * V_12 ;
F_42 ( & V_102 ) ;
if ( V_103 != V_104 ) {
F_45 ( & V_102 ) ;
return 1 ;
}
V_12 = F_98 ( exp ) ;
if ( F_76 ( & V_12 -> V_105 ) ) {
F_99 ( V_12 , L_26 , V_12 ) ;
F_89 ( & V_12 -> V_105 , & V_106 ) ;
}
F_45 ( & V_102 ) ;
F_50 ( & V_107 ) ;
return 0 ;
}
static int F_100 ( void * V_67 )
{
struct V_11 * V_12 ;
struct V_101 * exp ;
struct V_47 V_48 = { 0 } ;
T_4 V_108 ;
F_101 () ;
F_39 ( V_51 , L_27 ) ;
V_103 = V_104 ;
while ( 1 ) {
F_37 ( V_107 , ( ! F_76 ( & V_106 ) ) ||
( V_103 == V_109 ) , & V_48 ) ;
if ( ( V_103 == V_109 ) && F_76 ( & V_106 ) )
break;
F_42 ( & V_102 ) ;
V_12 = F_52 ( V_106 . V_110 , struct V_11 ,
V_105 ) ;
F_45 ( & V_102 ) ;
V_108 = F_102 () - V_111 ;
F_39 ( V_51 , L_28 ,
V_12 -> V_112 , V_108 ) ;
F_42 ( & V_12 -> V_113 ) ;
while ( ! F_76 ( & V_12 -> V_114 ) ) {
exp = F_52 ( V_12 -> V_114 . V_110 ,
struct V_101 ,
V_115 ) ;
if ( V_108 > exp -> V_116 ) {
F_103 ( exp ) ;
F_45 ( & V_12 -> V_113 ) ;
F_104 ( L_29
L_30
L_31
L_32
L_33 ,
V_12 -> V_112 ,
F_105 ( & exp -> V_117 ) ,
F_106 ( exp ) ,
( long ) ( F_102 () -
exp -> V_116 ) ,
exp , ( long ) F_102 () ,
( long ) V_108 ,
( long ) exp -> V_116 ) ;
F_39 ( V_51 , L_34 ,
exp -> V_116 ) ;
F_107 ( exp ) ;
F_108 ( exp ) ;
F_42 ( & V_12 -> V_113 ) ;
} else {
break;
}
}
F_45 ( & V_12 -> V_113 ) ;
F_42 ( & V_102 ) ;
F_81 ( & V_12 -> V_105 ) ;
F_45 ( & V_102 ) ;
F_109 ( V_12 , L_26 , V_12 ) ;
}
F_39 ( V_51 , L_35 ) ;
return 0 ;
}
void F_110 ( void )
{
struct V_118 * V_119 ;
if ( ++ V_120 > 1 )
return;
F_63 ( & V_107 ) ;
V_119 = F_65 ( F_100 , NULL , L_36 ) ;
if ( F_111 ( V_119 ) ) {
V_120 -- ;
F_9 ( L_37 ,
F_64 ( V_119 ) ) ;
}
}
void F_112 ( void )
{
if ( -- V_120 > 0 )
return;
V_103 = V_109 ;
F_50 ( & V_107 ) ;
}
