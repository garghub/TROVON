int F_1 ( struct V_1 * V_2 , int (* F_2) ( struct V_1 * V_2 ) )
{
int error = 0 ;
int V_3 ;
while ( 1 ) {
V_3 = F_3 ( V_2 -> V_4 ,
F_2 ( V_2 ) || F_4 ( V_2 ) ,
V_5 . V_6 * V_7 ) ;
if ( V_3 )
break;
}
if ( F_4 ( V_2 ) ) {
F_5 ( V_2 , L_1 ) ;
error = - V_8 ;
}
return error ;
}
T_1 F_6 ( struct V_1 * V_2 )
{
T_1 V_9 ;
F_7 ( & V_2 -> V_10 ) ;
V_9 = V_2 -> V_11 ;
F_8 ( & V_2 -> V_10 ) ;
return V_9 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_9 )
{
V_2 -> V_11 |= V_9 ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_9 )
{
F_7 ( & V_2 -> V_10 ) ;
F_9 ( V_2 , V_9 ) ;
F_8 ( & V_2 -> V_10 ) ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_12 ,
int V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_17 * V_18 ;
int error = 0 , V_19 ;
F_12 (memb, &ls->ls_nodes, list) {
V_19 = 0 ;
for (; ; ) {
if ( F_4 ( V_2 ) ) {
error = - V_8 ;
goto V_20;
}
error = F_13 ( V_2 , V_18 -> V_21 , 0 ) ;
if ( error )
goto V_20;
if ( V_13 )
F_14 ( V_2 , V_15 , V_18 ) ;
if ( V_15 -> V_22 & V_12 )
break;
if ( V_19 < 1000 )
V_19 += 20 ;
F_15 ( V_19 ) ;
}
}
V_20:
return error ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_23 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int error = 0 , V_19 = 0 , V_21 = V_2 -> V_24 ;
for (; ; ) {
if ( F_4 ( V_2 ) ) {
error = - V_8 ;
goto V_20;
}
error = F_13 ( V_2 , V_21 , V_23 ) ;
if ( error )
break;
if ( V_15 -> V_22 & V_12 )
break;
if ( V_19 < 1000 )
V_19 += 20 ;
F_15 ( V_19 ) ;
}
V_20:
return error ;
}
static int V_12 ( struct V_1 * V_2 , T_1 V_9 )
{
T_1 V_25 = V_9 << 1 ;
int error ;
if ( V_2 -> V_24 == F_17 () ) {
error = F_11 ( V_2 , V_9 , 0 ) ;
if ( ! error )
F_10 ( V_2 , V_25 ) ;
} else
error = F_16 ( V_2 , V_25 , 0 ) ;
return error ;
}
int F_18 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_26 * V_27 ;
int V_28 , V_29 ;
int error , V_3 ;
T_1 V_30 ;
F_12 (memb, &ls->ls_nodes, list) {
V_18 -> V_31 = - 1 ;
V_18 -> V_32 = 0 ;
}
if ( V_2 -> V_24 == F_17 () ) {
error = F_11 ( V_2 , V_33 , 1 ) ;
if ( error )
goto V_20;
V_3 = F_19 ( V_2 , & V_28 , & V_29 , & V_27 , & V_30 ) ;
if ( ! V_3 ) {
F_7 ( & V_2 -> V_10 ) ;
F_9 ( V_2 , V_34 ) ;
V_2 -> V_35 = V_28 ;
V_2 -> V_36 = V_29 ;
V_2 -> V_37 = V_27 ;
V_2 -> V_38 = V_30 ;
F_8 ( & V_2 -> V_10 ) ;
} else {
F_10 ( V_2 , V_34 ) ;
}
} else {
error = F_16 ( V_2 , V_34 , V_39 ) ;
if ( error )
goto V_20;
F_20 ( V_2 ) ;
}
V_20:
return error ;
}
int F_21 ( struct V_1 * V_2 )
{
return V_12 ( V_2 , V_40 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
return V_12 ( V_2 , V_41 ) ;
}
int F_23 ( struct V_1 * V_2 )
{
return V_12 ( V_2 , V_42 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
int V_43 ;
F_7 ( & V_2 -> V_44 ) ;
V_43 = F_25 ( & V_2 -> V_45 ) ;
F_8 ( & V_2 -> V_44 ) ;
return V_43 ;
}
static void F_26 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_7 ( & V_2 -> V_44 ) ;
if ( F_25 ( & V_47 -> V_49 ) ) {
F_27 ( & V_47 -> V_49 , & V_2 -> V_45 ) ;
V_2 -> V_50 ++ ;
F_28 ( V_47 ) ;
}
F_8 ( & V_2 -> V_44 ) ;
}
static void F_29 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_7 ( & V_2 -> V_44 ) ;
F_30 ( & V_47 -> V_49 ) ;
V_2 -> V_50 -- ;
F_8 ( & V_2 -> V_44 ) ;
F_31 ( V_47 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_46 * V_47 , * V_51 ;
F_7 ( & V_2 -> V_44 ) ;
F_33 (r, s, &ls->ls_recover_list, res_recover_list) {
F_30 ( & V_47 -> V_49 ) ;
V_47 -> V_52 = 0 ;
F_31 ( V_47 ) ;
V_2 -> V_50 -- ;
}
if ( V_2 -> V_50 != 0 ) {
F_34 ( V_2 , L_2 ,
V_2 -> V_50 ) ;
V_2 -> V_50 = 0 ;
}
F_8 ( & V_2 -> V_44 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_43 = 1 ;
F_7 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_50 )
V_43 = 0 ;
F_8 ( & V_2 -> V_53 ) ;
return V_43 ;
}
static int F_36 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
int V_3 ;
F_37 ( V_54 ) ;
F_7 ( & V_2 -> V_53 ) ;
if ( V_47 -> V_55 ) {
V_3 = - 1 ;
goto V_56;
}
V_3 = F_38 ( & V_2 -> V_57 , V_47 , 1 , 0 , V_58 ) ;
if ( V_3 < 0 )
goto V_56;
V_47 -> V_55 = V_3 ;
V_2 -> V_50 ++ ;
F_28 ( V_47 ) ;
V_3 = 0 ;
V_56:
F_8 ( & V_2 -> V_53 ) ;
F_39 () ;
return V_3 ;
}
static void F_40 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_7 ( & V_2 -> V_53 ) ;
F_41 ( & V_2 -> V_57 , V_47 -> V_55 ) ;
V_47 -> V_55 = 0 ;
V_2 -> V_50 -- ;
F_8 ( & V_2 -> V_53 ) ;
F_31 ( V_47 ) ;
}
static struct V_46 * F_42 ( struct V_1 * V_2 , T_2 V_59 )
{
struct V_46 * V_47 ;
F_7 ( & V_2 -> V_53 ) ;
V_47 = F_43 ( & V_2 -> V_57 , ( int ) V_59 ) ;
F_8 ( & V_2 -> V_53 ) ;
return V_47 ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
int V_59 ;
F_7 ( & V_2 -> V_53 ) ;
F_45 (&ls->ls_recover_idr, r, id) {
F_41 ( & V_2 -> V_57 , V_59 ) ;
V_47 -> V_55 = 0 ;
V_47 -> V_52 = 0 ;
V_2 -> V_50 -- ;
F_31 ( V_47 ) ;
}
if ( V_2 -> V_50 != 0 ) {
F_34 ( V_2 , L_2 ,
V_2 -> V_50 ) ;
V_2 -> V_50 = 0 ;
}
F_8 ( & V_2 -> V_53 ) ;
}
static void F_46 ( struct V_60 * V_61 , int V_21 )
{
struct V_62 * V_63 ;
F_12 (lkb, queue, lkb_statequeue) {
if ( ! ( V_63 -> V_64 & V_65 ) ) {
V_63 -> V_66 = V_21 ;
V_63 -> V_67 = 0 ;
}
}
}
static void F_47 ( struct V_46 * V_47 )
{
F_46 ( & V_47 -> V_68 , V_47 -> V_69 ) ;
F_46 ( & V_47 -> V_70 , V_47 -> V_69 ) ;
F_46 ( & V_47 -> V_71 , V_47 -> V_69 ) ;
}
static void F_48 ( struct V_46 * V_47 )
{
F_47 ( V_47 ) ;
F_49 ( V_47 , V_72 ) ;
F_49 ( V_47 , V_73 ) ;
}
static int F_50 ( struct V_46 * V_47 , unsigned int * V_74 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
int V_75 , V_76 ;
int V_77 = 0 ;
int error ;
if ( F_51 ( V_47 ) )
return 0 ;
V_77 = F_52 ( V_2 , V_47 -> V_69 ) ;
if ( ! V_77 && ! F_53 ( V_47 , V_72 ) )
return 0 ;
V_75 = F_17 () ;
V_76 = F_54 ( V_47 ) ;
if ( V_76 == V_75 ) {
if ( V_77 ) {
V_47 -> V_78 = V_75 ;
V_47 -> V_69 = 0 ;
}
F_48 ( V_47 ) ;
error = 0 ;
} else {
F_36 ( V_47 ) ;
error = F_55 ( V_47 , V_76 ) ;
}
( * V_74 ) ++ ;
return error ;
}
static int F_56 ( struct V_46 * V_47 , unsigned int * V_74 )
{
int V_76 = F_54 ( V_47 ) ;
int V_79 = V_76 ;
if ( V_76 == F_17 () )
V_79 = 0 ;
F_57 ( V_47 ) ;
V_47 -> V_78 = V_76 ;
V_47 -> V_69 = V_79 ;
F_48 ( V_47 ) ;
( * V_74 ) ++ ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
unsigned int V_80 = 0 ;
unsigned int V_74 = 0 ;
int V_81 = F_59 ( V_2 ) ;
int error ;
F_5 ( V_2 , L_3 ) ;
F_60 ( & V_2 -> V_82 ) ;
F_12 (r, &ls->ls_root_list, res_root_list) {
if ( F_4 ( V_2 ) ) {
F_61 ( & V_2 -> V_82 ) ;
error = - V_8 ;
goto V_20;
}
F_62 ( V_47 ) ;
if ( V_81 )
error = F_56 ( V_47 , & V_74 ) ;
else
error = F_50 ( V_47 , & V_74 ) ;
F_63 ( V_47 ) ;
F_64 () ;
V_80 ++ ;
if ( error ) {
F_61 ( & V_2 -> V_82 ) ;
goto V_20;
}
}
F_61 ( & V_2 -> V_82 ) ;
F_5 ( V_2 , L_4 , V_74 , V_80 ) ;
error = F_1 ( V_2 , & F_35 ) ;
V_20:
if ( error )
F_44 ( V_2 ) ;
return error ;
}
int F_65 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_46 * V_47 ;
int V_83 , V_79 ;
V_47 = F_42 ( V_2 , V_15 -> V_84 ) ;
if ( ! V_47 ) {
F_34 ( V_2 , L_5 ,
( unsigned long long ) V_15 -> V_84 ) ;
goto V_20;
}
V_83 = V_15 -> V_22 ;
if ( V_83 == F_17 () )
V_79 = 0 ;
else
V_79 = V_83 ;
F_62 ( V_47 ) ;
V_47 -> V_78 = V_83 ;
V_47 -> V_69 = V_79 ;
F_48 ( V_47 ) ;
F_63 ( V_47 ) ;
F_40 ( V_47 ) ;
if ( F_35 ( V_2 ) )
F_66 ( & V_2 -> V_4 ) ;
V_20:
return 0 ;
}
static int F_67 ( struct V_46 * V_47 , struct V_60 * V_85 )
{
struct V_62 * V_63 ;
int error = 0 ;
F_12 (lkb, head, lkb_statequeue) {
error = F_68 ( V_47 , V_63 ) ;
if ( error )
break;
V_47 -> V_52 ++ ;
}
return error ;
}
static int F_69 ( struct V_46 * V_47 )
{
int error = 0 ;
F_62 ( V_47 ) ;
F_70 (!r->res_recover_locks_count, dlm_dump_rsb(r);) ;
error = F_67 ( V_47 , & V_47 -> V_68 ) ;
if ( error )
goto V_20;
error = F_67 ( V_47 , & V_47 -> V_70 ) ;
if ( error )
goto V_20;
error = F_67 ( V_47 , & V_47 -> V_71 ) ;
if ( error )
goto V_20;
if ( V_47 -> V_52 )
F_26 ( V_47 ) ;
else
F_71 ( V_47 , V_72 ) ;
V_20:
F_63 ( V_47 ) ;
return error ;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
int error , V_74 = 0 ;
F_60 ( & V_2 -> V_82 ) ;
F_12 (r, &ls->ls_root_list, res_root_list) {
if ( F_51 ( V_47 ) ) {
F_71 ( V_47 , V_72 ) ;
continue;
}
if ( ! F_53 ( V_47 , V_72 ) )
continue;
if ( F_4 ( V_2 ) ) {
error = - V_8 ;
F_61 ( & V_2 -> V_82 ) ;
goto V_20;
}
error = F_69 ( V_47 ) ;
if ( error ) {
F_61 ( & V_2 -> V_82 ) ;
goto V_20;
}
V_74 += V_47 -> V_52 ;
}
F_61 ( & V_2 -> V_82 ) ;
F_5 ( V_2 , L_6 , V_74 ) ;
error = F_1 ( V_2 , & F_24 ) ;
V_20:
if ( error )
F_32 ( V_2 ) ;
return error ;
}
void F_73 ( struct V_46 * V_47 )
{
F_70 (rsb_flag(r, RSB_NEW_MASTER), dlm_dump_rsb(r);) ;
V_47 -> V_52 -- ;
if ( ! V_47 -> V_52 ) {
F_71 ( V_47 , V_72 ) ;
F_29 ( V_47 ) ;
}
if ( F_24 ( V_47 -> V_48 ) )
F_66 ( & V_47 -> V_48 -> V_4 ) ;
}
static void F_74 ( struct V_46 * V_47 )
{
struct V_62 * V_63 , * V_86 = NULL ;
T_1 V_87 = 0 ;
int V_88 = 0 ;
int V_89 = 0 ;
int V_90 = V_47 -> V_48 -> V_91 ;
if ( ! F_53 ( V_47 , V_73 ) &&
F_53 ( V_47 , V_92 ) ) {
F_49 ( V_47 , V_93 ) ;
return;
}
if ( ! F_53 ( V_47 , V_73 ) )
return;
F_12 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( ! ( V_63 -> V_94 & V_95 ) )
continue;
V_88 = 1 ;
if ( V_63 -> V_96 > V_97 ) {
V_89 = 1 ;
goto V_98;
}
if ( ( ( int ) V_63 -> V_99 - ( int ) V_87 ) >= 0 ) {
V_86 = V_63 ;
V_87 = V_63 -> V_99 ;
}
}
F_12 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( ! ( V_63 -> V_94 & V_95 ) )
continue;
V_88 = 1 ;
if ( V_63 -> V_96 > V_97 ) {
V_89 = 1 ;
goto V_98;
}
if ( ( ( int ) V_63 -> V_99 - ( int ) V_87 ) >= 0 ) {
V_86 = V_63 ;
V_87 = V_63 -> V_99 ;
}
}
V_98:
if ( ! V_88 )
goto V_20;
if ( ! V_89 )
F_49 ( V_47 , V_93 ) ;
if ( ! V_47 -> V_100 ) {
V_47 -> V_100 = F_75 ( V_47 -> V_48 ) ;
if ( ! V_47 -> V_100 )
goto V_20;
}
if ( V_89 ) {
V_47 -> V_101 = V_63 -> V_99 ;
memcpy ( V_47 -> V_100 , V_63 -> V_102 , V_90 ) ;
} else if ( V_86 ) {
V_47 -> V_101 = V_86 -> V_99 ;
memcpy ( V_47 -> V_100 , V_86 -> V_102 , V_90 ) ;
} else {
V_47 -> V_101 = 0 ;
memset ( V_47 -> V_100 , 0 , V_90 ) ;
}
V_20:
return;
}
static void F_76 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
struct V_62 * V_63 ;
int V_103 = - 1 ;
F_12 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( V_63 -> V_96 == V_104 ||
V_63 -> V_96 == V_105 ) {
V_103 = V_63 -> V_96 ;
break;
}
}
F_12 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( V_63 -> V_96 != V_106 )
continue;
if ( V_103 == - 1 ) {
F_5 ( V_2 , L_7 ,
V_63 -> V_107 , V_63 -> V_108 ) ;
V_63 -> V_96 = V_63 -> V_108 ;
} else {
F_5 ( V_2 , L_8 ,
V_63 -> V_107 , V_103 ) ;
V_63 -> V_96 = V_103 ;
}
}
}
static void F_77 ( struct V_46 * V_47 )
{
if ( ! F_25 ( & V_47 -> V_71 ) || ! F_25 ( & V_47 -> V_70 ) )
F_49 ( V_47 , V_109 ) ;
}
void F_78 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
unsigned int V_74 = 0 ;
F_60 ( & V_2 -> V_82 ) ;
F_12 (r, &ls->ls_root_list, res_root_list) {
F_62 ( V_47 ) ;
if ( F_51 ( V_47 ) ) {
if ( F_53 ( V_47 , V_110 ) )
F_76 ( V_47 ) ;
F_74 ( V_47 ) ;
if ( F_53 ( V_47 , V_73 ) )
F_77 ( V_47 ) ;
V_74 ++ ;
} else {
F_71 ( V_47 , V_93 ) ;
}
F_71 ( V_47 , V_110 ) ;
F_71 ( V_47 , V_92 ) ;
F_71 ( V_47 , V_73 ) ;
F_63 ( V_47 ) ;
}
F_61 ( & V_2 -> V_82 ) ;
if ( V_74 )
F_5 ( V_2 , L_9 , V_74 ) ;
}
int F_79 ( struct V_1 * V_2 )
{
struct V_111 * V_112 ;
struct V_46 * V_47 ;
int V_113 , error = 0 ;
F_80 ( & V_2 -> V_82 ) ;
if ( ! F_25 ( & V_2 -> V_114 ) ) {
F_34 ( V_2 , L_10 ) ;
error = - V_115 ;
goto V_20;
}
for ( V_113 = 0 ; V_113 < V_2 -> V_116 ; V_113 ++ ) {
F_7 ( & V_2 -> V_117 [ V_113 ] . V_118 ) ;
for ( V_112 = F_81 ( & V_2 -> V_117 [ V_113 ] . V_119 ) ; V_112 ; V_112 = F_82 ( V_112 ) ) {
V_47 = F_83 ( V_112 , struct V_46 , V_120 ) ;
F_84 ( & V_47 -> V_121 , & V_2 -> V_114 ) ;
F_28 ( V_47 ) ;
}
if ( ! F_85 ( & V_2 -> V_117 [ V_113 ] . V_122 ) )
F_34 ( V_2 , L_11 ) ;
F_8 ( & V_2 -> V_117 [ V_113 ] . V_118 ) ;
}
V_20:
F_86 ( & V_2 -> V_82 ) ;
return error ;
}
void F_87 ( struct V_1 * V_2 )
{
struct V_46 * V_47 , * V_123 ;
F_80 ( & V_2 -> V_82 ) ;
F_33 (r, safe, &ls->ls_root_list, res_root_list) {
F_30 ( & V_47 -> V_121 ) ;
F_31 ( V_47 ) ;
}
F_86 ( & V_2 -> V_82 ) ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_111 * V_112 , * V_124 ;
struct V_46 * V_47 ;
unsigned int V_74 = 0 ;
int V_113 ;
for ( V_113 = 0 ; V_113 < V_2 -> V_116 ; V_113 ++ ) {
F_7 ( & V_2 -> V_117 [ V_113 ] . V_118 ) ;
for ( V_112 = F_81 ( & V_2 -> V_117 [ V_113 ] . V_122 ) ; V_112 ; V_112 = V_124 ) {
V_124 = F_82 ( V_112 ) ;
V_47 = F_83 ( V_112 , struct V_46 , V_120 ) ;
F_89 ( V_112 , & V_2 -> V_117 [ V_113 ] . V_122 ) ;
F_90 ( V_47 ) ;
V_74 ++ ;
}
F_8 ( & V_2 -> V_117 [ V_113 ] . V_118 ) ;
}
if ( V_74 )
F_5 ( V_2 , L_12 , V_74 ) ;
}
