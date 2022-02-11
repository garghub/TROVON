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
void F_15 ( struct V_2 * V_3 , T_1 V_13 )
{
F_13 ( & V_3 -> V_14 ) ;
V_3 -> V_15 |= V_13 ;
F_14 ( & V_3 -> V_14 ) ;
}
static int F_16 ( struct V_2 * V_3 , T_1 V_16 )
{
struct V_17 * V_18 = V_3 -> V_19 ;
struct V_20 * V_21 ;
int error = 0 , V_22 ;
F_17 (memb, &ls->ls_nodes, list) {
V_22 = 0 ;
for (; ; ) {
if ( F_9 ( V_3 ) ) {
error = - V_12 ;
goto V_23;
}
error = F_18 ( V_3 , V_21 -> V_24 ) ;
if ( error )
goto V_23;
if ( V_18 -> V_25 & V_16 )
break;
if ( V_22 < 1000 )
V_22 += 20 ;
F_19 ( V_22 ) ;
}
}
V_23:
return error ;
}
static int F_20 ( struct V_2 * V_3 , T_1 V_16 )
{
struct V_17 * V_18 = V_3 -> V_19 ;
int error = 0 , V_22 = 0 , V_24 = V_3 -> V_26 ;
for (; ; ) {
if ( F_9 ( V_3 ) ) {
error = - V_12 ;
goto V_23;
}
error = F_18 ( V_3 , V_24 ) ;
if ( error )
break;
if ( V_18 -> V_25 & V_16 )
break;
if ( V_22 < 1000 )
V_22 += 20 ;
F_19 ( V_22 ) ;
}
V_23:
return error ;
}
static int V_16 ( struct V_2 * V_3 , T_1 V_13 )
{
T_1 V_27 = V_13 << 1 ;
int error ;
if ( V_3 -> V_26 == F_21 () ) {
error = F_16 ( V_3 , V_13 ) ;
if ( ! error )
F_15 ( V_3 , V_27 ) ;
} else
error = F_20 ( V_3 , V_27 ) ;
return error ;
}
int F_22 ( struct V_2 * V_3 )
{
return V_16 ( V_3 , V_28 ) ;
}
int F_23 ( struct V_2 * V_3 )
{
return V_16 ( V_3 , V_29 ) ;
}
int F_24 ( struct V_2 * V_3 )
{
return V_16 ( V_3 , V_30 ) ;
}
int F_25 ( struct V_2 * V_3 )
{
return V_16 ( V_3 , V_31 ) ;
}
static int F_26 ( struct V_2 * V_3 )
{
int V_32 ;
F_13 ( & V_3 -> V_33 ) ;
V_32 = F_27 ( & V_3 -> V_34 ) ;
F_14 ( & V_3 -> V_33 ) ;
return V_32 ;
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_37 ;
F_13 ( & V_3 -> V_33 ) ;
if ( F_27 ( & V_36 -> V_38 ) ) {
F_29 ( & V_36 -> V_38 , & V_3 -> V_34 ) ;
V_3 -> V_39 ++ ;
F_30 ( V_36 ) ;
}
F_14 ( & V_3 -> V_33 ) ;
}
static void F_31 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_37 ;
F_13 ( & V_3 -> V_33 ) ;
F_32 ( & V_36 -> V_38 ) ;
V_3 -> V_39 -- ;
F_14 ( & V_3 -> V_33 ) ;
F_33 ( V_36 ) ;
}
static struct V_35 * F_34 ( struct V_2 * V_3 , T_2 V_40 )
{
struct V_35 * V_36 = NULL ;
F_13 ( & V_3 -> V_33 ) ;
F_17 (r, &ls->ls_recover_list, res_recover_list) {
if ( V_40 == ( unsigned long ) V_36 )
goto V_23;
}
V_36 = NULL ;
V_23:
F_14 ( & V_3 -> V_33 ) ;
return V_36 ;
}
static void F_35 ( struct V_2 * V_3 )
{
struct V_35 * V_36 , * V_41 ;
F_13 ( & V_3 -> V_33 ) ;
F_36 (r, s, &ls->ls_recover_list, res_recover_list) {
F_32 ( & V_36 -> V_38 ) ;
V_36 -> V_42 = 0 ;
F_33 ( V_36 ) ;
V_3 -> V_39 -- ;
}
if ( V_3 -> V_39 != 0 ) {
F_37 ( V_3 , L_2 ,
V_3 -> V_39 ) ;
V_3 -> V_39 = 0 ;
}
F_14 ( & V_3 -> V_33 ) ;
}
static void F_38 ( struct V_43 * V_44 , int V_24 )
{
struct V_45 * V_46 ;
F_17 (lkb, queue, lkb_statequeue)
if ( ! ( V_46 -> V_47 & V_48 ) )
V_46 -> V_49 = V_24 ;
}
static void F_39 ( struct V_35 * V_36 )
{
F_38 ( & V_36 -> V_50 , V_36 -> V_51 ) ;
F_38 ( & V_36 -> V_52 , V_36 -> V_51 ) ;
F_38 ( & V_36 -> V_53 , V_36 -> V_51 ) ;
}
static void F_40 ( struct V_35 * V_36 , int V_24 )
{
F_41 ( V_36 ) ;
V_36 -> V_51 = V_24 ;
F_39 ( V_36 ) ;
F_42 ( V_36 , V_54 ) ;
F_42 ( V_36 , V_55 ) ;
F_43 ( V_36 ) ;
}
static int F_44 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = V_36 -> V_37 ;
int error , V_56 , V_57 , V_58 = F_21 () ;
V_56 = F_45 ( V_36 ) ;
if ( V_56 == V_58 ) {
error = F_46 ( V_3 , V_58 , V_36 -> V_59 ,
V_36 -> V_60 , & V_57 ) ;
if ( error )
F_37 ( V_3 , L_3 , error ) ;
if ( V_57 == V_58 )
V_57 = 0 ;
F_40 ( V_36 , V_57 ) ;
} else {
F_28 ( V_36 ) ;
error = F_47 ( V_36 , V_56 ) ;
}
return error ;
}
static int F_48 ( struct V_35 * V_36 )
{
int V_61 = F_45 ( V_36 ) ;
if ( V_61 == F_21 () )
V_61 = 0 ;
if ( V_36 -> V_51 != V_61 ) {
if ( F_49 ( V_36 ) )
F_50 ( V_36 ) ;
F_40 ( V_36 , V_61 ) ;
return 1 ;
}
return 0 ;
}
int F_51 ( struct V_2 * V_3 )
{
struct V_35 * V_36 ;
int error = 0 , V_62 = 0 ;
F_11 ( V_3 , L_4 ) ;
F_52 ( & V_3 -> V_63 ) ;
F_17 (r, &ls->ls_root_list, res_root_list) {
if ( F_9 ( V_3 ) ) {
F_53 ( & V_3 -> V_63 ) ;
error = - V_12 ;
goto V_23;
}
if ( F_54 ( V_3 ) )
V_62 += F_48 ( V_36 ) ;
else if ( ! F_49 ( V_36 ) &&
( F_55 ( V_3 , V_36 -> V_51 ) ||
F_56 ( V_36 , V_54 ) ) ) {
F_44 ( V_36 ) ;
V_62 ++ ;
}
F_57 () ;
}
F_53 ( & V_3 -> V_63 ) ;
F_11 ( V_3 , L_5 , V_62 ) ;
error = F_4 ( V_3 , & F_26 ) ;
V_23:
if ( error )
F_35 ( V_3 ) ;
return error ;
}
int F_58 ( struct V_2 * V_3 , struct V_17 * V_18 )
{
struct V_35 * V_36 ;
int V_24 ;
V_36 = F_34 ( V_3 , V_18 -> V_64 ) ;
if ( ! V_36 ) {
F_37 ( V_3 , L_6 ,
( unsigned long long ) V_18 -> V_64 ) ;
goto V_23;
}
V_24 = V_18 -> V_25 ;
if ( V_24 == F_21 () )
V_24 = 0 ;
F_40 ( V_36 , V_24 ) ;
F_31 ( V_36 ) ;
if ( F_26 ( V_3 ) )
F_3 ( & V_3 -> V_9 ) ;
V_23:
return 0 ;
}
static int F_59 ( struct V_35 * V_36 , struct V_43 * V_65 )
{
struct V_45 * V_46 ;
int error = 0 ;
F_17 (lkb, head, lkb_statequeue) {
error = F_60 ( V_36 , V_46 ) ;
if ( error )
break;
V_36 -> V_42 ++ ;
}
return error ;
}
static int F_61 ( struct V_35 * V_36 )
{
int error = 0 ;
F_41 ( V_36 ) ;
F_62 (!r->res_recover_locks_count, dlm_dump_rsb(r);) ;
error = F_59 ( V_36 , & V_36 -> V_50 ) ;
if ( error )
goto V_23;
error = F_59 ( V_36 , & V_36 -> V_52 ) ;
if ( error )
goto V_23;
error = F_59 ( V_36 , & V_36 -> V_53 ) ;
if ( error )
goto V_23;
if ( V_36 -> V_42 )
F_28 ( V_36 ) ;
else
F_63 ( V_36 , V_54 ) ;
V_23:
F_43 ( V_36 ) ;
return error ;
}
int F_64 ( struct V_2 * V_3 )
{
struct V_35 * V_36 ;
int error , V_62 = 0 ;
F_11 ( V_3 , L_7 ) ;
F_52 ( & V_3 -> V_63 ) ;
F_17 (r, &ls->ls_root_list, res_root_list) {
if ( F_49 ( V_36 ) ) {
F_63 ( V_36 , V_54 ) ;
continue;
}
if ( ! F_56 ( V_36 , V_54 ) )
continue;
if ( F_9 ( V_3 ) ) {
error = - V_12 ;
F_53 ( & V_3 -> V_63 ) ;
goto V_23;
}
error = F_61 ( V_36 ) ;
if ( error ) {
F_53 ( & V_3 -> V_63 ) ;
goto V_23;
}
V_62 += V_36 -> V_42 ;
}
F_53 ( & V_3 -> V_63 ) ;
F_11 ( V_3 , L_8 , V_62 ) ;
error = F_4 ( V_3 , & F_26 ) ;
V_23:
if ( error )
F_35 ( V_3 ) ;
else
F_15 ( V_3 , V_30 ) ;
return error ;
}
void F_65 ( struct V_35 * V_36 )
{
F_62 (rsb_flag(r, RSB_NEW_MASTER), dlm_dump_rsb(r);) ;
V_36 -> V_42 -- ;
if ( ! V_36 -> V_42 ) {
F_63 ( V_36 , V_54 ) ;
F_31 ( V_36 ) ;
}
if ( F_26 ( V_36 -> V_37 ) )
F_3 ( & V_36 -> V_37 -> V_9 ) ;
}
static void F_66 ( struct V_35 * V_36 )
{
struct V_45 * V_46 , * V_66 = NULL ;
T_1 V_67 = 0 ;
int V_68 = 0 ;
int V_69 = 0 ;
int V_70 = V_36 -> V_37 -> V_71 ;
F_17 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( ! ( V_46 -> V_72 & V_73 ) )
continue;
V_68 = 1 ;
if ( V_46 -> V_74 > V_75 ) {
V_69 = 1 ;
goto V_76;
}
if ( ( ( int ) V_46 -> V_77 - ( int ) V_67 ) >= 0 ) {
V_66 = V_46 ;
V_67 = V_46 -> V_77 ;
}
}
F_17 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( ! ( V_46 -> V_72 & V_73 ) )
continue;
V_68 = 1 ;
if ( V_46 -> V_74 > V_75 ) {
V_69 = 1 ;
goto V_76;
}
if ( ( ( int ) V_46 -> V_77 - ( int ) V_67 ) >= 0 ) {
V_66 = V_46 ;
V_67 = V_46 -> V_77 ;
}
}
V_76:
if ( ! V_68 )
goto V_23;
if ( ! V_69 )
F_42 ( V_36 , V_78 ) ;
if ( ! F_56 ( V_36 , V_55 ) )
goto V_23;
if ( ! V_36 -> V_79 ) {
V_36 -> V_79 = F_67 ( V_36 -> V_37 ) ;
if ( ! V_36 -> V_79 )
goto V_23;
}
if ( V_69 ) {
V_36 -> V_80 = V_46 -> V_77 ;
memcpy ( V_36 -> V_79 , V_46 -> V_81 , V_70 ) ;
} else if ( V_66 ) {
V_36 -> V_80 = V_66 -> V_77 ;
memcpy ( V_36 -> V_79 , V_66 -> V_81 , V_70 ) ;
} else {
V_36 -> V_80 = 0 ;
memset ( V_36 -> V_79 , 0 , V_70 ) ;
}
V_23:
return;
}
static void F_68 ( struct V_35 * V_36 )
{
struct V_45 * V_46 ;
int V_82 = - 1 ;
F_17 (lkb, &r->res_grantqueue, lkb_statequeue) {
if ( V_46 -> V_74 == V_83 ||
V_46 -> V_74 == V_84 ) {
V_82 = V_46 -> V_74 ;
break;
}
}
F_17 (lkb, &r->res_convertqueue, lkb_statequeue) {
if ( V_46 -> V_74 != V_85 )
continue;
if ( V_82 == - 1 )
V_46 -> V_74 = V_46 -> V_86 ;
else
V_46 -> V_74 = V_82 ;
}
}
static void F_69 ( struct V_35 * V_36 )
{
if ( ! F_27 ( & V_36 -> V_53 ) || ! F_27 ( & V_36 -> V_52 ) )
F_42 ( V_36 , V_87 ) ;
}
void F_70 ( struct V_2 * V_3 )
{
struct V_35 * V_36 ;
int V_62 = 0 ;
F_11 ( V_3 , L_9 ) ;
F_52 ( & V_3 -> V_63 ) ;
F_17 (r, &ls->ls_root_list, res_root_list) {
F_41 ( V_36 ) ;
if ( F_49 ( V_36 ) ) {
if ( F_56 ( V_36 , V_88 ) )
F_68 ( V_36 ) ;
if ( F_56 ( V_36 , V_55 ) )
F_69 ( V_36 ) ;
F_66 ( V_36 ) ;
V_62 ++ ;
}
F_63 ( V_36 , V_88 ) ;
F_63 ( V_36 , V_55 ) ;
F_43 ( V_36 ) ;
}
F_53 ( & V_3 -> V_63 ) ;
F_11 ( V_3 , L_10 , V_62 ) ;
}
int F_71 ( struct V_2 * V_3 )
{
struct V_35 * V_36 ;
int V_89 , error = 0 ;
F_72 ( & V_3 -> V_63 ) ;
if ( ! F_27 ( & V_3 -> V_90 ) ) {
F_37 ( V_3 , L_11 ) ;
error = - V_91 ;
goto V_23;
}
for ( V_89 = 0 ; V_89 < V_3 -> V_92 ; V_89 ++ ) {
F_13 ( & V_3 -> V_93 [ V_89 ] . V_94 ) ;
F_17 (r, &ls->ls_rsbtbl[i].list, res_hashchain) {
F_73 ( & V_36 -> V_95 , & V_3 -> V_90 ) ;
F_30 ( V_36 ) ;
}
if ( F_54 ( V_3 ) ) {
F_14 ( & V_3 -> V_93 [ V_89 ] . V_94 ) ;
continue;
}
F_17 (r, &ls->ls_rsbtbl[i].toss, res_hashchain) {
F_73 ( & V_36 -> V_95 , & V_3 -> V_90 ) ;
F_30 ( V_36 ) ;
}
F_14 ( & V_3 -> V_93 [ V_89 ] . V_94 ) ;
}
V_23:
F_74 ( & V_3 -> V_63 ) ;
return error ;
}
void F_75 ( struct V_2 * V_3 )
{
struct V_35 * V_36 , * V_96 ;
F_72 ( & V_3 -> V_63 ) ;
F_36 (r, safe, &ls->ls_root_list, res_root_list) {
F_32 ( & V_36 -> V_95 ) ;
F_33 ( V_36 ) ;
}
F_74 ( & V_3 -> V_63 ) ;
}
void F_76 ( struct V_2 * V_3 )
{
struct V_35 * V_36 , * V_96 ;
int V_89 ;
for ( V_89 = 0 ; V_89 < V_3 -> V_92 ; V_89 ++ ) {
F_13 ( & V_3 -> V_93 [ V_89 ] . V_94 ) ;
F_36 (r, safe, &ls->ls_rsbtbl[i].toss,
res_hashchain) {
if ( F_54 ( V_3 ) || ! F_49 ( V_36 ) ) {
F_77 ( & V_36 -> V_97 ) ;
F_78 ( V_36 ) ;
}
}
F_14 ( & V_3 -> V_93 [ V_89 ] . V_94 ) ;
}
}
