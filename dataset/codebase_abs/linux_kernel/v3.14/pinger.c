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
void F_30 ( void )
{
F_31 ( V_45 , L_3 ) ;
V_46 = true ;
}
void F_32 ( void )
{
F_31 ( V_45 , L_4 ) ;
V_46 = false ;
}
static void F_33 ( struct V_3 * V_4 ,
unsigned long V_47 )
{
int V_48 ;
int V_49 ;
int V_50 ;
int V_51 ;
F_34 ( & V_4 -> V_52 ) ;
V_48 = V_4 -> V_28 ;
V_49 = V_4 -> V_53 ;
V_50 = V_4 -> V_54 ;
V_51 = V_46 && F_35 ( & V_4 -> V_55 , V_56 ) ;
V_4 -> V_53 = 0 ;
if ( F_36 ( V_4 -> V_35 - 5 * V_57 , V_47 ) &&
! V_49 ) {
F_37 ( & V_4 -> V_52 ) ;
return;
}
V_4 -> V_54 = 0 ;
F_37 ( & V_4 -> V_52 ) ;
F_31 ( V_48 == V_19 ? V_23 : V_45 , L_5
L_6 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ,
F_38 ( V_48 ) , V_48 , V_49 , V_50 ,
V_4 -> V_36 , V_4 -> V_58 , V_51 ) ;
if ( V_48 == V_29 && ! F_20 ( V_4 ) ) {
V_4 -> V_35 = F_22 ( V_4 ) ;
if ( ! V_4 -> V_59 )
F_39 ( V_4 ) ;
} else if ( V_48 != V_19 ||
V_4 -> V_20 -> V_60 ||
F_20 ( V_4 ) ) {
F_31 ( V_45 , L_7
L_8 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ,
F_38 ( V_48 ) ) ;
} else if ( ( V_4 -> V_58 && ! V_51 ) || V_50 || V_49 ) {
F_8 ( V_4 ) ;
}
}
static int F_40 ( void * V_61 )
{
struct V_62 * V_63 = (struct V_62 * ) V_61 ;
F_41 ( V_63 , V_64 ) ;
F_42 ( & V_63 -> V_65 ) ;
while ( 1 ) {
T_2 V_47 = F_19 () ;
struct V_66 V_67 ;
T_1 V_68 ;
struct V_40 * V_41 ;
struct V_69 * V_70 ;
F_24 ( & V_43 ) ;
F_25 (item, &timeout_list, ti_chain) {
V_41 -> V_71 ( V_41 , V_41 -> V_72 ) ;
}
F_43 (iter, &pinger_imports) {
struct V_3 * V_4 =
F_44 ( V_70 , struct V_3 ,
V_73 ) ;
F_33 ( V_4 , V_47 ) ;
if ( V_4 -> V_58 && V_4 -> V_35 &&
F_45 ( V_4 -> V_35 ,
F_28 ( V_47 ,
F_29 ( V_27 ) ) ) )
F_13 ( V_4 , 0 ) ;
}
F_26 ( & V_43 ) ;
F_46 () ;
V_68 = F_23 ( V_47 ) ;
F_31 ( V_23 , L_9 V_74 L_10
V_75 L_11 , V_68 ,
F_28 ( V_47 , F_29 ( V_27 ) ) ) ;
if ( V_68 > 0 ) {
V_67 = F_47 ( F_14 ( T_1 ,
V_68 ,
F_29 ( 1 ) ) ,
NULL , NULL ) ;
F_48 ( V_63 -> V_65 ,
F_49 ( V_63 ) ||
F_50 ( V_63 ) ,
& V_67 ) ;
if ( F_51 ( V_63 , V_76 ) ) {
break;
} else {
F_51 ( V_63 , V_77 ) ;
}
}
}
F_41 ( V_63 , V_78 ) ;
F_42 ( & V_63 -> V_65 ) ;
F_31 ( V_79 , L_12 , F_52 () ) ;
return 0 ;
}
int F_53 ( void )
{
struct V_66 V_67 = { 0 } ;
int V_13 ;
if ( ! F_54 ( & V_80 ) &&
! F_55 ( & V_80 ) )
return - V_81 ;
F_56 ( & V_80 . V_65 ) ;
strcpy ( V_80 . V_82 , L_13 ) ;
V_13 = F_57 ( F_58 ( F_40 , & V_80 ,
L_14 , V_80 . V_82 ) ) ;
if ( F_59 ( V_13 ) ) {
F_9 ( L_15 , V_13 ) ;
return V_13 ;
}
F_48 ( V_80 . V_65 ,
F_60 ( & V_80 ) , & V_67 ) ;
if ( V_1 )
F_61 ( L_16
L_17
L_18
L_19
L_20 ) ;
return 0 ;
}
int F_62 ( void )
{
struct V_66 V_67 = { 0 } ;
int V_13 = 0 ;
if ( F_54 ( & V_80 ) ||
F_55 ( & V_80 ) )
return - V_81 ;
F_63 () ;
F_41 ( & V_80 , V_76 ) ;
F_42 ( & V_80 . V_65 ) ;
F_48 ( V_80 . V_65 ,
F_55 ( & V_80 ) , & V_67 ) ;
return V_13 ;
}
void F_64 ( struct V_3 * V_4 )
{
F_13 ( V_4 , 0 ) ;
}
void F_65 ( struct V_3 * V_4 )
{
F_13 ( V_4 , 1 ) ;
F_66 ( F_67 ( & V_4 -> V_52 ) ) ;
if ( V_4 -> V_28 != V_19 ||
F_35 ( & V_4 -> V_55 , V_56 ) )
V_4 -> V_54 = 1 ;
}
int F_68 ( struct V_3 * V_4 )
{
if ( ! F_69 ( & V_4 -> V_73 ) )
return - V_81 ;
F_24 ( & V_43 ) ;
F_31 ( V_45 , L_21 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 -> V_60 = 0 ;
F_13 ( V_4 , 0 ) ;
F_70 ( & V_4 -> V_73 , & V_83 ) ;
F_71 ( V_4 ) ;
F_72 () ;
F_26 ( & V_43 ) ;
return 0 ;
}
int F_73 ( struct V_3 * V_4 )
{
if ( F_69 ( & V_4 -> V_73 ) )
return - V_84 ;
F_24 ( & V_43 ) ;
F_74 ( & V_4 -> V_73 ) ;
F_31 ( V_45 , L_22 ,
V_4 -> V_20 -> V_21 . V_22 , F_10 ( V_4 -> V_20 ) ) ;
V_4 -> V_20 -> V_60 = 1 ;
F_75 ( V_4 ) ;
F_26 ( & V_43 ) ;
return 0 ;
}
struct V_40 * F_76 ( int time , enum V_85 V_86 ,
T_3 V_87 , void * V_88 )
{
struct V_40 * V_89 ;
F_77 ( V_89 ) ;
if ( ! V_89 )
return ( NULL ) ;
F_78 ( & V_89 -> V_90 ) ;
F_78 ( & V_89 -> V_91 ) ;
V_89 -> V_44 = time ;
V_89 -> V_92 = V_86 ;
V_89 -> V_71 = V_87 ;
V_89 -> V_72 = V_88 ;
return V_89 ;
}
static struct V_40 *
F_79 ( int time , enum V_85 V_86 ,
T_3 V_87 , void * V_88 )
{
struct V_40 * V_41 , * V_93 ;
F_66 ( F_80 ( & V_43 ) ) ;
F_25 (item, &timeout_list, ti_chain)
if ( V_41 -> V_92 == V_86 )
goto V_94;
V_41 = F_76 ( time , V_86 , V_87 , V_88 ) ;
if ( V_41 ) {
F_81 (tmp, &timeout_list, ti_chain) {
if ( V_93 -> V_44 < time ) {
F_82 ( & V_41 -> V_91 , & V_93 -> V_91 ) ;
goto V_94;
}
}
F_82 ( & V_41 -> V_91 , & V_95 ) ;
}
V_94:
return V_41 ;
}
int F_83 ( int time , enum V_85 V_86 ,
T_3 V_87 , void * V_88 ,
struct V_69 * V_96 )
{
struct V_40 * V_89 ;
F_24 ( & V_43 ) ;
V_89 = F_79 ( time , V_86 , V_87 , V_88 ) ;
if ( ! V_89 ) {
F_26 ( & V_43 ) ;
return ( - V_97 ) ;
}
F_82 ( V_96 , & V_89 -> V_90 ) ;
F_26 ( & V_43 ) ;
return 0 ;
}
int F_84 ( struct V_69 * V_96 ,
enum V_85 V_86 )
{
struct V_40 * V_89 = NULL , * V_41 ;
if ( F_69 ( V_96 ) )
return 0 ;
F_24 ( & V_43 ) ;
F_74 ( V_96 ) ;
F_25 (item, &timeout_list, ti_chain) {
if ( V_41 -> V_92 == V_86 ) {
V_89 = V_41 ;
break;
}
}
F_85 ( V_89 != NULL , L_23 ) ;
if ( F_69 ( & V_89 -> V_90 ) ) {
F_86 ( & V_89 -> V_91 ) ;
F_87 ( V_89 ) ;
}
F_26 ( & V_43 ) ;
return 0 ;
}
int F_63 ( void )
{
struct V_40 * V_41 , * V_93 ;
F_24 ( & V_43 ) ;
F_88 (item, tmp, &timeout_list, ti_chain) {
F_66 ( F_69 ( & V_41 -> V_90 ) ) ;
F_86 ( & V_41 -> V_91 ) ;
F_87 ( V_41 ) ;
}
F_26 ( & V_43 ) ;
return 0 ;
}
void F_72 ( void )
{
F_89 ( & V_80 , V_77 ) ;
F_42 ( & V_80 . V_65 ) ;
}
int F_90 ( struct V_98 * exp )
{
struct V_11 * V_12 ;
F_34 ( & V_99 ) ;
if ( V_100 != V_101 ) {
F_37 ( & V_99 ) ;
return 1 ;
}
V_12 = F_91 ( exp ) ;
if ( F_69 ( & V_12 -> V_102 ) ) {
F_92 ( V_12 , L_24 , V_12 ) ;
F_82 ( & V_12 -> V_102 , & V_103 ) ;
}
F_37 ( & V_99 ) ;
F_42 ( & V_104 ) ;
return 0 ;
}
static int F_93 ( void * V_61 )
{
struct V_11 * V_12 ;
struct V_98 * exp ;
struct V_66 V_67 = { 0 } ;
T_4 V_105 ;
F_94 () ;
F_31 ( V_45 , L_25 ) ;
V_100 = V_101 ;
while ( 1 ) {
F_48 ( V_104 , ( ! F_69 ( & V_103 ) ) ||
( V_100 == V_106 ) , & V_67 ) ;
if ( ( V_100 == V_106 ) && F_69 ( & V_103 ) )
break;
F_34 ( & V_99 ) ;
V_12 = F_44 ( V_103 . V_107 , struct V_11 ,
V_102 ) ;
F_37 ( & V_99 ) ;
V_105 = F_95 () - V_108 ;
F_31 ( V_45 , L_26 ,
V_12 -> V_109 , V_105 ) ;
F_34 ( & V_12 -> V_110 ) ;
while ( ! F_69 ( & V_12 -> V_111 ) ) {
exp = F_44 ( V_12 -> V_111 . V_107 ,
struct V_98 ,
V_112 ) ;
if ( V_105 > exp -> V_113 ) {
F_96 ( exp ) ;
F_37 ( & V_12 -> V_110 ) ;
F_97 ( L_27
L_28
L_29
L_30
L_31 ,
V_12 -> V_109 ,
F_98 ( & exp -> V_114 ) ,
F_99 ( exp ) ,
( long ) ( F_95 () -
exp -> V_113 ) ,
exp , ( long ) F_95 () ,
( long ) V_105 ,
( long ) exp -> V_113 ) ;
F_31 ( V_45 , L_32 ,
exp -> V_113 ) ;
F_100 ( exp ) ;
F_101 ( exp ) ;
F_34 ( & V_12 -> V_110 ) ;
} else {
break;
}
}
F_37 ( & V_12 -> V_110 ) ;
F_34 ( & V_99 ) ;
F_74 ( & V_12 -> V_102 ) ;
F_37 ( & V_99 ) ;
F_102 ( V_12 , L_24 , V_12 ) ;
}
F_31 ( V_45 , L_33 ) ;
return 0 ;
}
void F_103 ( void )
{
struct V_115 * V_116 ;
if ( ++ V_117 > 1 )
return;
F_56 ( & V_104 ) ;
V_116 = F_58 ( F_93 , NULL , L_34 ) ;
if ( F_104 ( V_116 ) ) {
V_117 -- ;
F_9 ( L_35 ,
F_57 ( V_116 ) ) ;
}
}
void F_105 ( void )
{
if ( -- V_117 > 0 )
return;
V_100 = V_106 ;
F_42 ( & V_104 ) ;
}
