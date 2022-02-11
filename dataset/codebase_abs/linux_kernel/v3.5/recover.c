static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 ( & V_3 -> V_4 , V_5 + ( V_6 . V_7 * V_8 ) ) ;
F_3 ( & V_3 -> V_9 ) ;
}
int F_4 ( struct V_2 * V_3 , int (* F_5) ( struct V_2 * V_3 ) )
{
int error = 0 ;
F_6 ( & V_3 -> V_4 ) ;
V_3 -> V_4 . V_10 = F_1 ;
V_3 -> V_4 . V_1 = ( long ) V_3 ;
V_3 -> V_4 . V_11 = V_5 + ( V_6 . V_7 * V_8 ) ;
F_7 ( & V_3 -> V_4 ) ;
F_8 ( V_3 -> V_9 , F_5 ( V_3 ) || F_9 ( V_3 ) ) ;
F_10 ( & V_3 -> V_4 ) ;
if ( F_9 ( V_3 ) ) {
F_11 ( V_3 , L_1 ) ;
error = - V_12 ;
}
return error ;
}
T_1 F_12 ( struct V_2 * V_3 )
{
T_1 V_13 ;
F_13 ( & V_3 -> V_14 ) ;
V_13 = V_3 -> V_15 ;
F_14 ( & V_3 -> V_14 ) ;
return V_13 ;
}
static void F_15 ( struct V_2 * V_3 , T_1 V_13 )
{
V_3 -> V_15 |= V_13 ;
}
void F_16 ( struct V_2 * V_3 , T_1 V_13 )
{
F_13 ( & V_3 -> V_14 ) ;
F_15 ( V_3 , V_13 ) ;
F_14 ( & V_3 -> V_14 ) ;
}
static int F_17 ( struct V_2 * V_3 , T_1 V_16 ,
int V_17 )
{
struct V_18 * V_19 = V_3 -> V_20 ;
struct V_21 * V_22 ;
int error = 0 , V_23 ;
F_18 (memb, &ls->ls_nodes, list) {
V_23 = 0 ;
for (; ; ) {
if ( F_9 ( V_3 ) ) {
error = - V_12 ;
goto V_24;
}
error = F_19 ( V_3 , V_22 -> V_25 , 0 ) ;
if ( error )
goto V_24;
if ( V_17 )
F_20 ( V_3 , V_19 , V_22 ) ;
if ( V_19 -> V_26 & V_16 )
break;
if ( V_23 < 1000 )
V_23 += 20 ;
F_21 ( V_23 ) ;
}
}
V_24:
return error ;
}
static int F_22 ( struct V_2 * V_3 , T_1 V_16 ,
T_1 V_27 )
{
struct V_18 * V_19 = V_3 -> V_20 ;
int error = 0 , V_23 = 0 , V_25 = V_3 -> V_28 ;
for (; ; ) {
if ( F_9 ( V_3 ) ) {
error = - V_12 ;
goto V_24;
}
error = F_19 ( V_3 , V_25 , V_27 ) ;
if ( error )
break;
if ( V_19 -> V_26 & V_16 )
break;
if ( V_23 < 1000 )
V_23 += 20 ;
F_21 ( V_23 ) ;
}
V_24:
return error ;
}
static int V_16 ( struct V_2 * V_3 , T_1 V_13 )
{
T_1 V_29 = V_13 << 1 ;
int error ;
if ( V_3 -> V_28 == F_23 () ) {
error = F_17 ( V_3 , V_13 , 0 ) ;
if ( ! error )
F_16 ( V_3 , V_29 ) ;
} else
error = F_22 ( V_3 , V_29 , 0 ) ;
return error ;
}
int F_24 ( struct V_2 * V_3 )
{
struct V_21 * V_22 ;
struct V_30 * V_31 ;
int V_32 , V_33 ;
int error , V_34 ;
T_1 V_35 ;
F_18 (memb, &ls->ls_nodes, list) {
V_22 -> V_36 = - 1 ;
V_22 -> V_37 = 0 ;
}
if ( V_3 -> V_28 == F_23 () ) {
error = F_17 ( V_3 , V_38 , 1 ) ;
if ( error )
goto V_24;
V_34 = F_25 ( V_3 , & V_32 , & V_33 , & V_31 , & V_35 ) ;
if ( ! V_34 ) {
F_13 ( & V_3 -> V_14 ) ;
F_15 ( V_3 , V_39 ) ;
V_3 -> V_40 = V_32 ;
V_3 -> V_41 = V_33 ;
V_3 -> V_42 = V_31 ;
V_3 -> V_43 = V_35 ;
F_14 ( & V_3 -> V_14 ) ;
} else {
F_16 ( V_3 , V_39 ) ;
}
} else {
error = F_22 ( V_3 , V_39 , V_44 ) ;
if ( error )
goto V_24;
F_26 ( V_3 ) ;
}
V_24:
return error ;
}
int F_27 ( struct V_2 * V_3 )
{
return V_16 ( V_3 , V_45 ) ;
}
int F_28 ( struct V_2 * V_3 )
{
return V_16 ( V_3 , V_46 ) ;
}
int F_29 ( struct V_2 * V_3 )
{
return V_16 ( V_3 , V_47 ) ;
}
static int F_30 ( struct V_2 * V_3 )
{
int V_48 ;
F_13 ( & V_3 -> V_49 ) ;
V_48 = F_31 ( & V_3 -> V_50 ) ;
F_14 ( & V_3 -> V_49 ) ;
return V_48 ;
}
static void F_32 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_53 ;
F_13 ( & V_3 -> V_49 ) ;
if ( F_31 ( & V_52 -> V_54 ) ) {
F_33 ( & V_52 -> V_54 , & V_3 -> V_50 ) ;
V_3 -> V_55 ++ ;
F_34 ( V_52 ) ;
}
F_14 ( & V_3 -> V_49 ) ;
}
static void F_35 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_53 ;
F_13 ( & V_3 -> V_49 ) ;
F_36 ( & V_52 -> V_54 ) ;
V_3 -> V_55 -- ;
F_14 ( & V_3 -> V_49 ) ;
F_37 ( V_52 ) ;
}
static struct V_51 * F_38 ( struct V_2 * V_3 , T_2 V_56 )
{
struct V_51 * V_52 = NULL ;
F_13 ( & V_3 -> V_49 ) ;
F_18 (r, &ls->ls_recover_list, res_recover_list) {
if ( V_56 == ( unsigned long ) V_52 )
goto V_24;
}
V_52 = NULL ;
V_24:
F_14 ( & V_3 -> V_49 ) ;
return V_52 ;
}
static void F_39 ( struct V_2 * V_3 )
{
struct V_51 * V_52 , * V_57 ;
F_13 ( & V_3 -> V_49 ) ;
F_40 (r, s, &ls->ls_recover_list, res_recover_list) {
F_36 ( & V_52 -> V_54 ) ;
V_52 -> V_58 = 0 ;
F_37 ( V_52 ) ;
V_3 -> V_55 -- ;
}
if ( V_3 -> V_55 != 0 ) {
F_41 ( V_3 , L_2 ,
V_3 -> V_55 ) ;
V_3 -> V_55 = 0 ;
}
F_14 ( & V_3 -> V_49 ) ;
}
static void F_42 ( struct V_59 * V_60 , int V_25 )
{
struct V_61 * V_62 ;
F_18 (lkb, queue, lkb_statequeue) {
if ( ! ( V_62 -> V_63 & V_64 ) ) {
V_62 -> V_65 = V_25 ;
V_62 -> V_66 = 0 ;
}
}
}
static void F_43 ( struct V_51 * V_52 )
{
F_42 ( & V_52 -> V_67 , V_52 -> V_68 ) ;
F_42 ( & V_52 -> V_69 , V_52 -> V_68 ) ;
F_42 ( & V_52 -> V_70 , V_52 -> V_68 ) ;
}
static void F_44 ( struct V_51 * V_52 , int V_25 )
{
V_52 -> V_68 = V_25 ;
F_43 ( V_52 ) ;
F_45 ( V_52 , V_71 ) ;
F_45 ( V_52 , V_72 ) ;
}
static int F_46 ( struct V_51 * V_52 )
{
struct V_2 * V_3 = V_52 -> V_53 ;
int error , V_73 ;
int V_74 = F_23 () ;
int V_75 = F_47 ( V_52 ) ;
if ( V_75 == V_74 ) {
error = F_48 ( V_3 , V_74 , V_52 -> V_76 ,
V_52 -> V_77 , & V_73 ) ;
if ( error )
F_41 ( V_3 , L_3 , error ) ;
if ( V_73 == V_74 )
V_73 = 0 ;
F_49 ( V_52 ) ;
F_44 ( V_52 , V_73 ) ;
F_50 ( V_52 ) ;
} else {
F_32 ( V_52 ) ;
error = F_51 ( V_52 , V_75 ) ;
}
return error ;
}
static int F_52 ( struct V_51 * V_52 )
{
int V_75 = F_47 ( V_52 ) ;
int V_78 = V_75 ;
if ( V_75 == F_23 () )
V_78 = 0 ;
F_49 ( V_52 ) ;
F_53 ( V_52 ) ;
F_44 ( V_52 , V_78 ) ;
F_50 ( V_52 ) ;
return 1 ;
}
int F_54 ( struct V_2 * V_3 )
{
struct V_51 * V_52 ;
int error = 0 , V_79 = 0 ;
F_11 ( V_3 , L_4 ) ;
F_55 ( & V_3 -> V_80 ) ;
F_18 (r, &ls->ls_root_list, res_root_list) {
if ( F_9 ( V_3 ) ) {
F_56 ( & V_3 -> V_80 ) ;
error = - V_12 ;
goto V_24;
}
if ( F_57 ( V_3 ) )
V_79 += F_52 ( V_52 ) ;
else if ( ! F_58 ( V_52 ) &&
( F_59 ( V_3 , V_52 -> V_68 ) ||
F_60 ( V_52 , V_71 ) ) ) {
F_46 ( V_52 ) ;
V_79 ++ ;
}
F_61 () ;
}
F_56 ( & V_3 -> V_80 ) ;
F_11 ( V_3 , L_5 , V_79 ) ;
error = F_4 ( V_3 , & F_30 ) ;
V_24:
if ( error )
F_39 ( V_3 ) ;
return error ;
}
int F_62 ( struct V_2 * V_3 , struct V_18 * V_19 )
{
struct V_51 * V_52 ;
int V_25 ;
V_52 = F_38 ( V_3 , V_19 -> V_81 ) ;
if ( ! V_52 ) {
F_41 ( V_3 , L_6 ,
( unsigned long long ) V_19 -> V_81 ) ;
goto V_24;
}
V_25 = V_19 -> V_26 ;
if ( V_25 == F_23 () )
V_25 = 0 ;
F_49 ( V_52 ) ;
F_44 ( V_52 , V_25 ) ;
F_50 ( V_52 ) ;
F_35 ( V_52 ) ;
if ( F_30 ( V_3 ) )
F_3 ( & V_3 -> V_9 ) ;
V_24:
return 0 ;
}
static int F_63 ( struct V_51 * V_52 , struct V_59 * V_82 )
{
struct V_61 * V_62 ;
int error = 0 ;
F_18 (lkb, head, lkb_statequeue) {
error = F_64 ( V_52 , V_62 ) ;
if ( error )
break;
V_52 -> V_58 ++ ;
}
return error ;
}
static int F_65 ( struct V_51 * V_52 )
{
int error = 0 ;
F_49 ( V_52 ) ;
F_66 (!r->res_recover_locks_count, dlm_dump_rsb(r);) ;
error = F_63 ( V_52 , & V_52 -> V_67 ) ;
if ( error )
goto V_24;
error = F_63 ( V_52 , & V_52 -> V_69 ) ;
if ( error )
goto V_24;
error = F_63 ( V_52 , & V_52 -> V_70 ) ;
if ( error )
goto V_24;
if ( V_52 -> V_58 )
F_32 ( V_52 ) ;
else
F_67 ( V_52 , V_71 ) ;
V_24:
F_50 ( V_52 ) ;
return error ;
}
int F_68 ( struct V_2 * V_3 )
{
struct V_51 * V_52 ;
int error , V_79 = 0 ;
F_55 ( & V_3 -> V_80 ) ;
F_18 (r, &ls->ls_root_list, res_root_list) {
if ( F_58 ( V_52 ) ) {
F_67 ( V_52 , V_71 ) ;
continue;
}
if ( ! F_60 ( V_52 , V_71 ) )
continue;
if ( F_9 ( V_3 ) ) {
error = - V_12 ;
F_56 ( & V_3 -> V_80 ) ;
goto V_24;
}
error = F_65 ( V_52 ) ;
if ( error ) {
F_56 ( & V_3 -> V_80 ) ;
goto V_24;
}
V_79 += V_52 -> V_58 ;
}
F_56 ( & V_3 -> V_80 ) ;
F_11 ( V_3 , L_7 , V_79 ) ;
error = F_4 ( V_3 , & F_30 ) ;
V_24:
if ( error )
F_39 ( V_3 ) ;
return error ;
}
void F_69 ( struct V_51 * V_52 )
{
F_66 (rsb_flag(r, RSB_NEW_MASTER), dlm_dump_rsb(r);) ;
V_52 -> V_58 -- ;
if ( ! V_52 -> V_58 ) {
F_67 ( V_52 , V_71 ) ;
F_35 ( V_52 ) ;
}
if ( F_30 ( V_52 -> V_53 ) )
F_3 ( & V_52 -> V_53 -> V_9 ) ;
}
static void F_70 ( struct V_51 * V_52 )
{
struct V_61 * V_62 , * V_83 = NULL ;
T_1 V_84 = 0 ;
int V_85 = 0 ;
int V_86 = 0 ;
int V_87 = V_52 -> V_53 -> V_88 ;
F_18 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( ! ( V_62 -> V_89 & V_90 ) )
continue;
V_85 = 1 ;
if ( V_62 -> V_91 > V_92 ) {
V_86 = 1 ;
goto V_93;
}
if ( ( ( int ) V_62 -> V_94 - ( int ) V_84 ) >= 0 ) {
V_83 = V_62 ;
V_84 = V_62 -> V_94 ;
}
}
F_18 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( ! ( V_62 -> V_89 & V_90 ) )
continue;
V_85 = 1 ;
if ( V_62 -> V_91 > V_92 ) {
V_86 = 1 ;
goto V_93;
}
if ( ( ( int ) V_62 -> V_94 - ( int ) V_84 ) >= 0 ) {
V_83 = V_62 ;
V_84 = V_62 -> V_94 ;
}
}
V_93:
if ( ! V_85 )
goto V_24;
if ( ! V_86 )
F_45 ( V_52 , V_95 ) ;
if ( ! F_60 ( V_52 , V_72 ) )
goto V_24;
if ( ! V_52 -> V_96 ) {
V_52 -> V_96 = F_71 ( V_52 -> V_53 ) ;
if ( ! V_52 -> V_96 )
goto V_24;
}
if ( V_86 ) {
V_52 -> V_97 = V_62 -> V_94 ;
memcpy ( V_52 -> V_96 , V_62 -> V_98 , V_87 ) ;
} else if ( V_83 ) {
V_52 -> V_97 = V_83 -> V_94 ;
memcpy ( V_52 -> V_96 , V_83 -> V_98 , V_87 ) ;
} else {
V_52 -> V_97 = 0 ;
memset ( V_52 -> V_96 , 0 , V_87 ) ;
}
V_24:
return;
}
static void F_72 ( struct V_51 * V_52 )
{
struct V_61 * V_62 ;
int V_99 = - 1 ;
F_18 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( V_62 -> V_91 == V_100 ||
V_62 -> V_91 == V_101 ) {
V_99 = V_62 -> V_91 ;
break;
}
}
F_18 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( V_62 -> V_91 != V_102 )
continue;
if ( V_99 == - 1 )
V_62 -> V_91 = V_62 -> V_103 ;
else
V_62 -> V_91 = V_99 ;
}
}
static void F_73 ( struct V_51 * V_52 )
{
if ( ! F_31 ( & V_52 -> V_70 ) || ! F_31 ( & V_52 -> V_69 ) )
F_45 ( V_52 , V_104 ) ;
}
void F_74 ( struct V_2 * V_3 )
{
struct V_51 * V_52 ;
unsigned int V_79 = 0 ;
F_55 ( & V_3 -> V_80 ) ;
F_18 (r, &ls->ls_root_list, res_root_list) {
F_49 ( V_52 ) ;
if ( F_58 ( V_52 ) ) {
if ( F_60 ( V_52 , V_105 ) )
F_72 ( V_52 ) ;
if ( F_60 ( V_52 , V_72 ) )
F_73 ( V_52 ) ;
F_70 ( V_52 ) ;
V_79 ++ ;
}
F_67 ( V_52 , V_105 ) ;
F_67 ( V_52 , V_72 ) ;
F_50 ( V_52 ) ;
}
F_56 ( & V_3 -> V_80 ) ;
if ( V_79 )
F_11 ( V_3 , L_8 , V_79 ) ;
}
int F_75 ( struct V_2 * V_3 )
{
struct V_106 * V_107 ;
struct V_51 * V_52 ;
int V_108 , error = 0 ;
F_76 ( & V_3 -> V_80 ) ;
if ( ! F_31 ( & V_3 -> V_109 ) ) {
F_41 ( V_3 , L_9 ) ;
error = - V_110 ;
goto V_24;
}
for ( V_108 = 0 ; V_108 < V_3 -> V_111 ; V_108 ++ ) {
F_13 ( & V_3 -> V_112 [ V_108 ] . V_113 ) ;
for ( V_107 = F_77 ( & V_3 -> V_112 [ V_108 ] . V_114 ) ; V_107 ; V_107 = F_78 ( V_107 ) ) {
V_52 = F_79 ( V_107 , struct V_51 , V_115 ) ;
F_80 ( & V_52 -> V_116 , & V_3 -> V_109 ) ;
F_34 ( V_52 ) ;
}
if ( F_57 ( V_3 ) ) {
F_14 ( & V_3 -> V_112 [ V_108 ] . V_113 ) ;
continue;
}
for ( V_107 = F_77 ( & V_3 -> V_112 [ V_108 ] . V_117 ) ; V_107 ; V_107 = F_78 ( V_107 ) ) {
V_52 = F_79 ( V_107 , struct V_51 , V_115 ) ;
F_80 ( & V_52 -> V_116 , & V_3 -> V_109 ) ;
F_34 ( V_52 ) ;
}
F_14 ( & V_3 -> V_112 [ V_108 ] . V_113 ) ;
}
V_24:
F_81 ( & V_3 -> V_80 ) ;
return error ;
}
void F_82 ( struct V_2 * V_3 )
{
struct V_51 * V_52 , * V_118 ;
F_76 ( & V_3 -> V_80 ) ;
F_40 (r, safe, &ls->ls_root_list, res_root_list) {
F_36 ( & V_52 -> V_116 ) ;
F_37 ( V_52 ) ;
}
F_81 ( & V_3 -> V_80 ) ;
}
void F_83 ( struct V_2 * V_3 )
{
struct V_106 * V_107 , * V_119 ;
struct V_51 * V_120 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_3 -> V_111 ; V_108 ++ ) {
F_13 ( & V_3 -> V_112 [ V_108 ] . V_113 ) ;
for ( V_107 = F_77 ( & V_3 -> V_112 [ V_108 ] . V_117 ) ; V_107 ; V_107 = V_119 ) {
V_119 = F_78 ( V_107 ) ; ;
V_120 = F_79 ( V_107 , struct V_51 , V_115 ) ;
if ( F_57 ( V_3 ) || ! F_58 ( V_120 ) ) {
F_84 ( V_107 , & V_3 -> V_112 [ V_108 ] . V_117 ) ;
F_85 ( V_120 ) ;
}
}
F_14 ( & V_3 -> V_112 [ V_108 ] . V_113 ) ;
}
}
