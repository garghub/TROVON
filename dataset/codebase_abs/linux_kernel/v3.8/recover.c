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
int V_3 , V_54 ;
V_3 = F_37 ( & V_2 -> V_55 , V_56 ) ;
if ( ! V_3 )
return - V_57 ;
F_7 ( & V_2 -> V_53 ) ;
if ( V_47 -> V_58 ) {
F_8 ( & V_2 -> V_53 ) ;
return - 1 ;
}
V_3 = F_38 ( & V_2 -> V_55 , V_47 , 1 , & V_54 ) ;
if ( V_3 ) {
F_8 ( & V_2 -> V_53 ) ;
return V_3 ;
}
V_47 -> V_58 = V_54 ;
V_2 -> V_50 ++ ;
F_28 ( V_47 ) ;
F_8 ( & V_2 -> V_53 ) ;
return 0 ;
}
static void F_39 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
F_7 ( & V_2 -> V_53 ) ;
F_40 ( & V_2 -> V_55 , V_47 -> V_58 ) ;
V_47 -> V_58 = 0 ;
V_2 -> V_50 -- ;
F_8 ( & V_2 -> V_53 ) ;
F_31 ( V_47 ) ;
}
static struct V_46 * F_41 ( struct V_1 * V_2 , T_2 V_54 )
{
struct V_46 * V_47 ;
F_7 ( & V_2 -> V_53 ) ;
V_47 = F_42 ( & V_2 -> V_55 , ( int ) V_54 ) ;
F_8 ( & V_2 -> V_53 ) ;
return V_47 ;
}
static int F_43 ( int V_54 , void * V_59 , void * V_60 )
{
struct V_1 * V_2 = V_60 ;
struct V_46 * V_47 = V_59 ;
V_47 -> V_58 = 0 ;
V_47 -> V_52 = 0 ;
V_2 -> V_50 -- ;
F_31 ( V_47 ) ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 )
{
F_7 ( & V_2 -> V_53 ) ;
F_45 ( & V_2 -> V_55 , F_43 , V_2 ) ;
F_46 ( & V_2 -> V_55 ) ;
if ( V_2 -> V_50 != 0 ) {
F_34 ( V_2 , L_2 ,
V_2 -> V_50 ) ;
V_2 -> V_50 = 0 ;
}
F_8 ( & V_2 -> V_53 ) ;
}
static void F_47 ( struct V_61 * V_62 , int V_21 )
{
struct V_63 * V_64 ;
F_12 (lkb, queue, lkb_statequeue) {
if ( ! ( V_64 -> V_65 & V_66 ) ) {
V_64 -> V_67 = V_21 ;
V_64 -> V_68 = 0 ;
}
}
}
static void F_48 ( struct V_46 * V_47 )
{
F_47 ( & V_47 -> V_69 , V_47 -> V_70 ) ;
F_47 ( & V_47 -> V_71 , V_47 -> V_70 ) ;
F_47 ( & V_47 -> V_72 , V_47 -> V_70 ) ;
}
static void F_49 ( struct V_46 * V_47 )
{
F_48 ( V_47 ) ;
F_50 ( V_47 , V_73 ) ;
F_50 ( V_47 , V_74 ) ;
}
static int F_51 ( struct V_46 * V_47 , unsigned int * V_75 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
int V_76 , V_77 ;
int V_78 = 0 ;
int error ;
if ( F_52 ( V_47 ) )
return 0 ;
V_78 = F_53 ( V_2 , V_47 -> V_70 ) ;
if ( ! V_78 && ! F_54 ( V_47 , V_73 ) )
return 0 ;
V_76 = F_17 () ;
V_77 = F_55 ( V_47 ) ;
if ( V_77 == V_76 ) {
if ( V_78 ) {
V_47 -> V_79 = V_76 ;
V_47 -> V_70 = 0 ;
}
F_49 ( V_47 ) ;
error = 0 ;
} else {
F_36 ( V_47 ) ;
error = F_56 ( V_47 , V_77 ) ;
}
( * V_75 ) ++ ;
return error ;
}
static int F_57 ( struct V_46 * V_47 , unsigned int * V_75 )
{
int V_77 = F_55 ( V_47 ) ;
int V_80 = V_77 ;
if ( V_77 == F_17 () )
V_80 = 0 ;
F_58 ( V_47 ) ;
V_47 -> V_79 = V_77 ;
V_47 -> V_70 = V_80 ;
F_49 ( V_47 ) ;
( * V_75 ) ++ ;
return 0 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
unsigned int V_81 = 0 ;
unsigned int V_75 = 0 ;
int V_82 = F_60 ( V_2 ) ;
int error ;
F_5 ( V_2 , L_3 ) ;
F_61 ( & V_2 -> V_83 ) ;
F_12 (r, &ls->ls_root_list, res_root_list) {
if ( F_4 ( V_2 ) ) {
F_62 ( & V_2 -> V_83 ) ;
error = - V_8 ;
goto V_20;
}
F_63 ( V_47 ) ;
if ( V_82 )
error = F_57 ( V_47 , & V_75 ) ;
else
error = F_51 ( V_47 , & V_75 ) ;
F_64 ( V_47 ) ;
F_65 () ;
V_81 ++ ;
if ( error ) {
F_62 ( & V_2 -> V_83 ) ;
goto V_20;
}
}
F_62 ( & V_2 -> V_83 ) ;
F_5 ( V_2 , L_4 , V_75 , V_81 ) ;
error = F_1 ( V_2 , & F_35 ) ;
V_20:
if ( error )
F_44 ( V_2 ) ;
return error ;
}
int F_66 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_46 * V_47 ;
int V_84 , V_80 ;
V_47 = F_41 ( V_2 , V_15 -> V_85 ) ;
if ( ! V_47 ) {
F_34 ( V_2 , L_5 ,
( unsigned long long ) V_15 -> V_85 ) ;
goto V_20;
}
V_84 = V_15 -> V_22 ;
if ( V_84 == F_17 () )
V_80 = 0 ;
else
V_80 = V_84 ;
F_63 ( V_47 ) ;
V_47 -> V_79 = V_84 ;
V_47 -> V_70 = V_80 ;
F_49 ( V_47 ) ;
F_64 ( V_47 ) ;
F_39 ( V_47 ) ;
if ( F_35 ( V_2 ) )
F_67 ( & V_2 -> V_4 ) ;
V_20:
return 0 ;
}
static int F_68 ( struct V_46 * V_47 , struct V_61 * V_86 )
{
struct V_63 * V_64 ;
int error = 0 ;
F_12 (lkb, head, lkb_statequeue) {
error = F_69 ( V_47 , V_64 ) ;
if ( error )
break;
V_47 -> V_52 ++ ;
}
return error ;
}
static int F_70 ( struct V_46 * V_47 )
{
int error = 0 ;
F_63 ( V_47 ) ;
F_71 (!r->res_recover_locks_count, dlm_dump_rsb(r);) ;
error = F_68 ( V_47 , & V_47 -> V_69 ) ;
if ( error )
goto V_20;
error = F_68 ( V_47 , & V_47 -> V_71 ) ;
if ( error )
goto V_20;
error = F_68 ( V_47 , & V_47 -> V_72 ) ;
if ( error )
goto V_20;
if ( V_47 -> V_52 )
F_26 ( V_47 ) ;
else
F_72 ( V_47 , V_73 ) ;
V_20:
F_64 ( V_47 ) ;
return error ;
}
int F_73 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
int error , V_75 = 0 ;
F_61 ( & V_2 -> V_83 ) ;
F_12 (r, &ls->ls_root_list, res_root_list) {
if ( F_52 ( V_47 ) ) {
F_72 ( V_47 , V_73 ) ;
continue;
}
if ( ! F_54 ( V_47 , V_73 ) )
continue;
if ( F_4 ( V_2 ) ) {
error = - V_8 ;
F_62 ( & V_2 -> V_83 ) ;
goto V_20;
}
error = F_70 ( V_47 ) ;
if ( error ) {
F_62 ( & V_2 -> V_83 ) ;
goto V_20;
}
V_75 += V_47 -> V_52 ;
}
F_62 ( & V_2 -> V_83 ) ;
F_5 ( V_2 , L_6 , V_75 ) ;
error = F_1 ( V_2 , & F_24 ) ;
V_20:
if ( error )
F_32 ( V_2 ) ;
return error ;
}
void F_74 ( struct V_46 * V_47 )
{
F_71 (rsb_flag(r, RSB_NEW_MASTER), dlm_dump_rsb(r);) ;
V_47 -> V_52 -- ;
if ( ! V_47 -> V_52 ) {
F_72 ( V_47 , V_73 ) ;
F_29 ( V_47 ) ;
}
if ( F_24 ( V_47 -> V_48 ) )
F_67 ( & V_47 -> V_48 -> V_4 ) ;
}
static void F_75 ( struct V_46 * V_47 )
{
struct V_63 * V_64 , * V_87 = NULL ;
T_1 V_88 = 0 ;
int V_89 = 0 ;
int V_90 = 0 ;
int V_91 = V_47 -> V_48 -> V_92 ;
if ( ! F_54 ( V_47 , V_74 ) &&
F_54 ( V_47 , V_93 ) ) {
F_50 ( V_47 , V_94 ) ;
return;
}
if ( ! F_54 ( V_47 , V_74 ) )
return;
F_12 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( ! ( V_64 -> V_95 & V_96 ) )
continue;
V_89 = 1 ;
if ( V_64 -> V_97 > V_98 ) {
V_90 = 1 ;
goto V_99;
}
if ( ( ( int ) V_64 -> V_100 - ( int ) V_88 ) >= 0 ) {
V_87 = V_64 ;
V_88 = V_64 -> V_100 ;
}
}
F_12 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( ! ( V_64 -> V_95 & V_96 ) )
continue;
V_89 = 1 ;
if ( V_64 -> V_97 > V_98 ) {
V_90 = 1 ;
goto V_99;
}
if ( ( ( int ) V_64 -> V_100 - ( int ) V_88 ) >= 0 ) {
V_87 = V_64 ;
V_88 = V_64 -> V_100 ;
}
}
V_99:
if ( ! V_89 )
goto V_20;
if ( ! V_90 )
F_50 ( V_47 , V_94 ) ;
if ( ! V_47 -> V_101 ) {
V_47 -> V_101 = F_76 ( V_47 -> V_48 ) ;
if ( ! V_47 -> V_101 )
goto V_20;
}
if ( V_90 ) {
V_47 -> V_102 = V_64 -> V_100 ;
memcpy ( V_47 -> V_101 , V_64 -> V_103 , V_91 ) ;
} else if ( V_87 ) {
V_47 -> V_102 = V_87 -> V_100 ;
memcpy ( V_47 -> V_101 , V_87 -> V_103 , V_91 ) ;
} else {
V_47 -> V_102 = 0 ;
memset ( V_47 -> V_101 , 0 , V_91 ) ;
}
V_20:
return;
}
static void F_77 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = V_47 -> V_48 ;
struct V_63 * V_64 ;
int V_104 = - 1 ;
F_12 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( V_64 -> V_97 == V_105 ||
V_64 -> V_97 == V_106 ) {
V_104 = V_64 -> V_97 ;
break;
}
}
F_12 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( V_64 -> V_97 != V_107 )
continue;
if ( V_104 == - 1 ) {
F_5 ( V_2 , L_7 ,
V_64 -> V_108 , V_64 -> V_109 ) ;
V_64 -> V_97 = V_64 -> V_109 ;
} else {
F_5 ( V_2 , L_8 ,
V_64 -> V_108 , V_104 ) ;
V_64 -> V_97 = V_104 ;
}
}
}
static void F_78 ( struct V_46 * V_47 )
{
if ( ! F_25 ( & V_47 -> V_72 ) || ! F_25 ( & V_47 -> V_71 ) )
F_50 ( V_47 , V_110 ) ;
}
void F_79 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
unsigned int V_75 = 0 ;
F_61 ( & V_2 -> V_83 ) ;
F_12 (r, &ls->ls_root_list, res_root_list) {
F_63 ( V_47 ) ;
if ( F_52 ( V_47 ) ) {
if ( F_54 ( V_47 , V_111 ) )
F_77 ( V_47 ) ;
F_75 ( V_47 ) ;
if ( F_54 ( V_47 , V_74 ) )
F_78 ( V_47 ) ;
V_75 ++ ;
} else {
F_72 ( V_47 , V_94 ) ;
}
F_72 ( V_47 , V_111 ) ;
F_72 ( V_47 , V_93 ) ;
F_72 ( V_47 , V_74 ) ;
F_64 ( V_47 ) ;
}
F_62 ( & V_2 -> V_83 ) ;
if ( V_75 )
F_5 ( V_2 , L_9 , V_75 ) ;
}
int F_80 ( struct V_1 * V_2 )
{
struct V_112 * V_113 ;
struct V_46 * V_47 ;
int V_114 , error = 0 ;
F_81 ( & V_2 -> V_83 ) ;
if ( ! F_25 ( & V_2 -> V_115 ) ) {
F_34 ( V_2 , L_10 ) ;
error = - V_116 ;
goto V_20;
}
for ( V_114 = 0 ; V_114 < V_2 -> V_117 ; V_114 ++ ) {
F_7 ( & V_2 -> V_118 [ V_114 ] . V_119 ) ;
for ( V_113 = F_82 ( & V_2 -> V_118 [ V_114 ] . V_120 ) ; V_113 ; V_113 = F_83 ( V_113 ) ) {
V_47 = F_84 ( V_113 , struct V_46 , V_121 ) ;
F_85 ( & V_47 -> V_122 , & V_2 -> V_115 ) ;
F_28 ( V_47 ) ;
}
if ( ! F_86 ( & V_2 -> V_118 [ V_114 ] . V_123 ) )
F_34 ( V_2 , L_11 ) ;
F_8 ( & V_2 -> V_118 [ V_114 ] . V_119 ) ;
}
V_20:
F_87 ( & V_2 -> V_83 ) ;
return error ;
}
void F_88 ( struct V_1 * V_2 )
{
struct V_46 * V_47 , * V_124 ;
F_81 ( & V_2 -> V_83 ) ;
F_33 (r, safe, &ls->ls_root_list, res_root_list) {
F_30 ( & V_47 -> V_122 ) ;
F_31 ( V_47 ) ;
}
F_87 ( & V_2 -> V_83 ) ;
}
void F_89 ( struct V_1 * V_2 )
{
struct V_112 * V_113 , * V_125 ;
struct V_46 * V_47 ;
unsigned int V_75 = 0 ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_2 -> V_117 ; V_114 ++ ) {
F_7 ( & V_2 -> V_118 [ V_114 ] . V_119 ) ;
for ( V_113 = F_82 ( & V_2 -> V_118 [ V_114 ] . V_123 ) ; V_113 ; V_113 = V_125 ) {
V_125 = F_83 ( V_113 ) ;
V_47 = F_84 ( V_113 , struct V_46 , V_121 ) ;
F_90 ( V_113 , & V_2 -> V_118 [ V_114 ] . V_123 ) ;
F_91 ( V_47 ) ;
V_75 ++ ;
}
F_8 ( & V_2 -> V_118 [ V_114 ] . V_119 ) ;
}
if ( V_75 )
F_5 ( V_2 , L_12 , V_75 ) ;
}
