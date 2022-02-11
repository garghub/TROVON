static int F_1 ( T_1 * V_1 , const struct V_2 * V_3 )
{
int V_4 ;
T_2 V_5 , V_6 ;
V_4 = F_2 ( V_3 -> V_7 , V_8 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
( V_12 | V_13 ) + 3 * 4 ,
& V_5 , sizeof( V_5 ) ) ;
if ( V_4 != V_14 )
return V_4 ;
V_4 = F_2 ( V_3 -> V_7 , V_8 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
( V_12 | V_13 ) + 4 * 4 ,
& V_6 , sizeof( V_6 ) ) ;
if ( V_4 != V_14 )
return V_4 ;
* V_1 = ( T_1 ) F_3 ( V_5 ) << 32 | F_3 ( V_6 ) ;
return V_14 ;
}
static struct V_15 * F_4 (
struct V_16 * V_17 , T_1 V_1 )
{
struct V_18 * V_19 ;
struct V_15 * V_20 , * V_21 = NULL ;
F_5 ( & V_17 -> V_22 . V_23 ) ;
F_6 (se_sess, &tpg->se_tpg.tpg_sess_list, sess_list) {
V_20 = V_19 -> V_24 ;
if ( V_20 -> V_1 == V_1 )
V_21 = V_20 ;
}
F_7 ( & V_17 -> V_22 . V_23 ) ;
return V_21 ;
}
static struct V_25 * F_8 (
struct V_15 * V_26 , T_3 V_27 )
{
struct V_25 * V_28 , * V_21 = NULL ;
F_5 ( & V_26 -> V_29 ) ;
F_6 (login, &session->login_list, link) {
if ( V_28 -> V_30 == V_27 )
V_21 = V_28 ;
}
F_7 ( & V_26 -> V_29 ) ;
return V_21 ;
}
static int F_9 (
struct V_16 * V_17 ,
T_3 V_27 ,
int V_31 )
{
struct V_18 * V_19 ;
struct V_15 * V_20 ;
struct V_25 * V_28 ;
int V_32 = 0 ;
F_5 ( & V_17 -> V_22 . V_23 ) ;
F_6 (se_sess, &tpg->se_tpg.tpg_sess_list, sess_list) {
V_20 = V_19 -> V_24 ;
F_5 ( & V_20 -> V_29 ) ;
F_6 (login, &sess->login_list, link) {
if ( V_28 -> V_30 != V_27 )
continue;
if ( ! V_31 || V_28 -> V_31 )
V_32 ++ ;
}
F_7 ( & V_20 -> V_29 ) ;
}
F_7 ( & V_17 -> V_22 . V_23 ) ;
return V_32 ;
}
static struct V_25 * F_10 (
struct V_16 * V_17 , int V_33 )
{
struct V_18 * V_19 ;
struct V_15 * V_20 ;
struct V_25 * V_28 , * V_21 = NULL ;
F_5 ( & V_17 -> V_22 . V_23 ) ;
F_6 (se_sess, &tpg->se_tpg.tpg_sess_list, sess_list) {
V_20 = V_19 -> V_24 ;
F_5 ( & V_20 -> V_29 ) ;
F_6 (login, &sess->login_list, link) {
if ( V_28 -> V_33 == V_33 )
V_21 = V_28 ;
}
F_7 ( & V_20 -> V_29 ) ;
}
F_7 ( & V_17 -> V_22 . V_23 ) ;
return V_21 ;
}
static T_3 F_11 ( struct V_16 * V_17 , T_3 V_30 , int * V_34 )
{
struct V_35 * V_22 = & V_17 -> V_22 ;
struct V_36 * V_36 ;
F_12 () ;
F_13 (se_lun, &se_tpg->tpg_lun_hlist, link) {
if ( V_36 -> V_27 == V_30 ) {
F_14 () ;
* V_34 = 0 ;
return V_30 ;
}
}
F_14 () ;
* V_34 = - V_37 ;
return V_30 ;
}
static struct V_15 * F_15 (
struct V_16 * V_17 ,
T_1 V_1 )
{
struct V_15 * V_20 ;
int V_4 ;
char V_38 [ 17 ] ;
struct V_39 * V_40 ;
V_20 = F_16 ( sizeof( * V_20 ) , V_41 ) ;
if ( ! V_20 ) {
F_17 ( L_1 ) ;
return F_18 ( - V_42 ) ;
}
V_20 -> V_19 = F_19 ( V_43 ) ;
if ( F_20 ( V_20 -> V_19 ) ) {
F_17 ( L_2 ) ;
V_4 = F_21 ( V_20 -> V_19 ) ;
F_22 ( V_20 ) ;
return F_18 ( V_4 ) ;
}
snprintf ( V_38 , sizeof( V_38 ) , L_3 , V_1 ) ;
V_40 = F_23 ( & V_17 -> V_22 , V_38 ) ;
if ( ! V_40 ) {
F_24 ( L_4 , V_38 ) ;
F_25 ( V_20 -> V_19 ) ;
F_22 ( V_20 ) ;
return F_18 ( - V_44 ) ;
}
V_20 -> V_19 -> V_39 = V_40 ;
F_26 ( & V_20 -> V_29 ) ;
F_27 ( & V_20 -> V_45 ) ;
F_28 ( & V_20 -> V_46 , V_47 ) ;
V_20 -> V_1 = V_1 ;
F_29 ( & V_17 -> V_22 , V_40 , V_20 -> V_19 , V_20 ) ;
return V_20 ;
}
static void F_30 ( struct V_15 * V_20 , bool V_48 )
{
F_5 ( & V_20 -> V_29 ) ;
if ( ! F_31 ( & V_20 -> V_45 ) ) {
F_7 ( & V_20 -> V_29 ) ;
return;
}
F_7 ( & V_20 -> V_29 ) ;
if ( V_48 )
F_32 ( & V_20 -> V_46 ) ;
F_33 ( V_20 -> V_19 ) ;
F_34 ( V_20 -> V_19 ) ;
if ( V_20 -> V_7 )
F_35 ( V_20 -> V_7 ) ;
F_22 ( V_20 ) ;
}
static void F_36 ( struct V_25 * V_28 ,
bool V_48 )
{
struct V_15 * V_20 = V_28 -> V_20 ;
F_37 ( V_28 -> V_49 ) ;
if ( V_20 ) {
F_5 ( & V_20 -> V_29 ) ;
F_38 ( & V_28 -> V_50 ) ;
F_7 ( & V_20 -> V_29 ) ;
F_30 ( V_20 , V_48 ) ;
}
F_22 ( V_28 ) ;
}
static void F_39 (
struct V_51 * V_52 , struct V_2 * V_3 ,
int * V_53 )
{
struct V_54 * V_55 = V_52 -> V_55 ;
struct V_16 * V_17 = V_55 -> V_17 ;
struct V_15 * V_20 ;
struct V_25 * V_28 ;
struct V_56 * V_57 ;
T_1 V_1 ;
T_3 V_27 ;
int V_58 , V_4 ;
V_27 = F_11 ( V_17 ,
F_40 ( F_3 ( V_3 -> V_59 . V_60 ) ) , & V_4 ) ;
if ( V_4 ) {
F_41 ( L_5 ,
F_40 ( F_3 ( V_3 -> V_59 . V_60 ) ) ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_63 ) ) ;
return;
}
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_24 ( L_6 , V_4 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_64 ) |
F_44 ( V_65 ) ) ;
return;
}
F_41 ( L_7 ,
V_27 , V_1 ) ;
V_20 = F_4 ( V_17 , V_1 ) ;
if ( V_20 ) {
V_28 = F_8 ( V_20 , V_27 ) ;
if ( V_28 ) {
F_41 ( L_8 ) ;
goto V_66;
}
}
if ( F_45 ( F_3 ( V_3 -> V_59 . V_60 ) ) &&
F_9 ( V_17 , V_27 , 0 ) ) {
F_24 ( L_9 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_67 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 1 ) ) {
F_24 ( L_10 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_67 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 0 ) >=
V_55 -> V_68 ) {
F_24 ( L_11 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_69 ) ) ;
return;
}
if ( ! V_20 ) {
V_20 = F_15 ( V_17 , V_1 ) ;
if ( F_20 ( V_20 ) ) {
switch ( F_21 ( V_20 ) ) {
case - V_44 :
V_4 = V_67 ;
break;
default:
V_4 = V_69 ;
break;
}
V_3 -> V_61 . V_61 = F_42 (
F_43 (
V_62 ) |
F_44 ( V_4 ) ) ;
return;
}
V_20 -> V_70 = V_3 -> V_9 ;
V_20 -> V_7 = F_46 ( V_3 -> V_7 ) ;
V_20 -> V_10 = V_3 -> V_10 ;
V_20 -> V_11 = V_3 -> V_11 ;
F_47 ( & V_20 -> V_46 ,
V_71 ) ;
}
V_20 -> V_72 = F_48 (
1 << F_49 ( F_3 ( V_3 -> V_59 . V_60 ) ) ,
V_55 -> V_73 ) - 1 ;
V_28 = F_16 ( sizeof( * V_28 ) , V_41 ) ;
if ( ! V_28 ) {
F_17 ( L_12 ) ;
F_30 ( V_20 , true ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_69 ) ) ;
return;
}
V_28 -> V_20 = V_20 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_74 = F_50 ( & V_3 -> V_59 . V_75 ) ;
V_28 -> V_31 = F_45 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
V_28 -> V_33 = F_51 ( & V_33 ) ;
V_28 -> V_49 = F_52 ( V_28 ) ;
if ( F_20 ( V_28 -> V_49 ) ) {
V_4 = F_21 ( V_28 -> V_49 ) ;
F_17 ( L_13 , V_4 ) ;
F_30 ( V_20 , true ) ;
F_22 ( V_28 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_69 ) ) ;
return;
}
F_5 ( & V_20 -> V_29 ) ;
F_53 ( & V_28 -> V_50 , & V_20 -> V_45 ) ;
F_7 ( & V_20 -> V_29 ) ;
V_66:
V_57 = F_54 ( sizeof( * V_57 ) , V_41 ) ;
if ( ! V_57 ) {
F_17 ( L_14 ) ;
F_36 ( V_28 , true ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_69 ) ) ;
return;
}
V_58 = F_55 (
F_56 ( F_3 ( V_3 -> V_59 . V_76 ) ) ,
12 , sizeof( * V_57 ) ) ;
V_57 -> V_60 = F_42 (
( ( V_58 & 0xffff ) << 16 ) |
( V_28 -> V_33 & 0xffff ) ) ;
V_57 -> V_72 = F_42 ( V_20 -> V_72 & 0xffff ) ;
F_57 ( V_28 -> V_49 -> V_77 . V_78 ,
& V_57 -> V_79 ) ;
V_4 = F_2 ( V_20 -> V_7 , V_80 ,
V_20 -> V_70 , V_20 -> V_10 , V_20 -> V_11 ,
F_50 ( & V_3 -> V_59 . V_81 ) , V_57 ,
V_58 ) ;
if ( V_4 != V_14 ) {
F_58 ( L_15 , V_4 ) ;
F_22 ( V_57 ) ;
F_36 ( V_28 , true ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_64 ) |
F_44 ( V_65 ) ) ;
return;
}
F_22 ( V_57 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_82 ) ) ;
}
static void F_59 (
struct V_51 * V_52 , struct V_2 * V_3 ,
int * V_53 )
{
F_41 ( L_16 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_83 ) ) ;
}
static void F_60 (
struct V_51 * V_52 , struct V_2 * V_3 ,
int * V_53 )
{
struct V_54 * V_55 = V_52 -> V_55 ;
struct V_16 * V_17 = V_55 -> V_17 ;
int V_4 ;
T_1 V_1 ;
struct V_25 * V_28 ;
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_24 ( L_6 , V_4 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_64 ) |
F_44 ( V_65 ) ) ;
return;
}
F_41 ( L_17 , V_1 ) ;
V_28 = F_10 ( V_17 ,
F_61 ( F_3 ( V_3 -> V_59 . V_60 ) ) ) ;
if ( ! V_28 ) {
F_17 ( L_18 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_67 ) ) ;
return;
}
if ( V_28 -> V_20 -> V_1 != V_1 ) {
F_17 ( L_19 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_67 ) ) ;
return;
}
F_5 ( & V_28 -> V_20 -> V_29 ) ;
if ( V_28 -> V_20 -> V_7 )
F_35 ( V_28 -> V_20 -> V_7 ) ;
V_28 -> V_20 -> V_10 = V_3 -> V_10 ;
V_28 -> V_20 -> V_70 = V_3 -> V_9 ;
V_28 -> V_20 -> V_7 = F_46 ( V_3 -> V_7 ) ;
V_28 -> V_20 -> V_11 = V_3 -> V_11 ;
F_7 ( & V_28 -> V_20 -> V_29 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_82 ) ) ;
}
static void F_62 (
struct V_51 * V_52 , struct V_2 * V_3 ,
int * V_53 )
{
struct V_54 * V_55 = V_52 -> V_55 ;
struct V_16 * V_17 = V_55 -> V_17 ;
int V_84 ;
struct V_25 * V_28 ;
V_84 = F_63 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
V_28 = F_10 ( V_17 , V_84 ) ;
if ( ! V_28 ) {
F_24 ( L_20 , V_84 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_85 ) ) ;
return;
}
F_64 ( L_21 ,
V_28 -> V_30 , V_28 -> V_33 ) ;
if ( V_3 -> V_9 != V_28 -> V_20 -> V_70 ) {
F_24 ( L_22 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_67 ) ) ;
return;
}
F_36 ( V_28 , true ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_82 ) ) ;
}
static void F_65 ( struct V_15 * V_20 )
{
bool V_86 = false ;
F_5 ( & V_20 -> V_29 ) ;
if ( V_20 -> V_7 ) {
F_66 ( & V_20 -> V_7 -> V_29 ) ;
V_86 = ( V_20 -> V_7 -> V_87 != NULL ) ;
F_67 ( & V_20 -> V_7 -> V_29 ) ;
if ( ! V_86 ) {
F_35 ( V_20 -> V_7 ) ;
V_20 -> V_7 = NULL ;
}
}
if ( ! V_86 || ( V_20 -> V_10 != V_20 -> V_7 -> V_10 ) ) {
F_64 ( L_23 ,
V_20 -> V_1 ) ;
V_20 -> V_70 = - 1 ;
V_20 -> V_88 = F_68 () +
( ( V_20 -> V_72 + 1 ) * V_89 ) ;
}
F_7 ( & V_20 -> V_29 ) ;
}
static void F_69 ( struct V_15 * V_20 )
{
struct V_25 * V_28 , * V_90 ;
F_70 ( V_45 ) ;
F_64 ( L_24 , V_20 -> V_1 ) ;
F_5 ( & V_20 -> V_29 ) ;
F_71 (login, temp, &sess->login_list, link) {
V_28 -> V_20 = NULL ;
F_72 ( & V_28 -> V_50 , & V_45 ) ;
}
F_7 ( & V_20 -> V_29 ) ;
F_71 (login, temp, &login_list, link) {
F_38 ( & V_28 -> V_50 ) ;
F_36 ( V_28 , false ) ;
}
F_30 ( V_20 , false ) ;
}
static void V_47 ( struct V_91 * V_92 )
{
struct V_15 * V_20 = F_73 ( V_92 , struct V_15 ,
V_46 . V_92 ) ;
F_5 ( & V_20 -> V_29 ) ;
if ( F_31 ( & V_20 -> V_45 ) ) {
F_7 ( & V_20 -> V_29 ) ;
return;
}
F_7 ( & V_20 -> V_29 ) ;
if ( V_20 -> V_70 != - 1 ) {
F_65 ( V_20 ) ;
F_47 ( & V_20 -> V_46 ,
V_71 ) ;
} else if ( ! F_74 ( F_68 () , V_20 -> V_88 ) ) {
F_47 ( & V_20 -> V_46 ,
V_71 ) ;
} else {
F_69 ( V_20 ) ;
}
}
static int F_75 ( struct V_93 * V_7 , int V_94 , void * V_95 ,
struct V_96 * V_52 )
{
int V_97 ;
switch ( V_94 ) {
case V_8 :
F_58 ( L_25 ) ;
F_5 ( & V_52 -> V_29 ) ;
V_97 = V_52 -> V_97 ;
F_7 ( & V_52 -> V_29 ) ;
* ( T_2 * ) V_95 = F_42 ( V_97 ) ;
return V_14 ;
case V_98 :
return V_14 ;
default:
return V_99 ;
}
}
static int F_76 ( struct V_93 * V_7 , int V_94 , void * V_95 ,
struct V_96 * V_52 )
{
switch ( V_94 ) {
case V_98 :
F_58 ( L_26 ) ;
F_5 ( & V_52 -> V_29 ) ;
V_52 -> V_97 = V_100 ;
F_7 ( & V_52 -> V_29 ) ;
return V_14 ;
default:
return V_99 ;
}
}
static int F_77 ( struct V_93 * V_7 , int V_94 , void * V_95 ,
struct V_96 * V_52 )
{
struct V_101 * V_102 = V_95 ;
switch ( V_94 ) {
case V_80 :
F_5 ( & V_52 -> V_29 ) ;
if ( V_52 -> V_97 != V_103 &&
V_52 -> V_97 != V_100 ) {
F_7 ( & V_52 -> V_29 ) ;
F_41 ( L_27 ) ;
return V_104 ;
}
V_52 -> V_97 = V_105 ;
F_7 ( & V_52 -> V_29 ) ;
V_52 -> V_106 = F_50 ( V_102 ) ;
V_52 -> V_107 = false ;
F_58 ( L_28 ,
V_52 -> V_106 ) ;
F_78 ( V_108 , & V_52 -> V_92 ) ;
return V_14 ;
case V_109 :
F_58 ( L_29 ) ;
F_5 ( & V_52 -> V_29 ) ;
F_57 ( V_52 -> V_106 , V_102 ) ;
F_7 ( & V_52 -> V_29 ) ;
return V_14 ;
default:
return V_99 ;
}
}
static int F_79 ( struct V_93 * V_7 , int V_94 , void * V_95 ,
struct V_96 * V_52 )
{
switch ( V_94 ) {
case V_98 :
F_5 ( & V_52 -> V_29 ) ;
if ( V_52 -> V_97 != V_103 ) {
F_7 ( & V_52 -> V_29 ) ;
F_58 ( L_30 ) ;
return V_104 ;
}
V_52 -> V_97 = V_105 ;
F_7 ( & V_52 -> V_29 ) ;
V_52 -> V_107 = true ;
F_58 ( L_31 ) ;
F_78 ( V_108 , & V_52 -> V_92 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_99 ;
}
}
static int F_80 ( struct V_93 * V_7 ,
int V_94 , void * V_95 , struct V_96 * V_52 )
{
switch ( V_94 ) {
case V_98 :
F_58 ( L_32 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_99 ;
}
}
static void F_81 ( struct V_93 * V_7 , struct V_110 * V_111 ,
int V_94 , int V_112 , int V_113 , int V_10 ,
unsigned long long V_78 , void * V_95 , T_4 V_76 ,
void * V_114 )
{
struct V_96 * V_52 = V_114 ;
struct V_15 * V_20 = V_52 -> V_28 -> V_20 ;
int V_115 , V_116 , V_117 ;
F_5 ( & V_20 -> V_29 ) ;
V_115 = V_20 -> V_10 ;
V_116 = V_20 -> V_70 ;
F_7 ( & V_20 -> V_29 ) ;
if ( V_10 != V_115 ) {
F_41 ( L_33 ) ;
V_117 = V_99 ;
goto V_118;
}
if ( V_113 != V_116 ) {
F_41 ( L_34 ,
V_113 , V_116 ) ;
V_117 = V_99 ;
goto V_118;
}
V_78 -= V_52 -> V_77 . V_78 ;
if ( V_78 == 0x00 && V_76 == 4 ) {
V_117 = F_75 ( V_7 , V_94 , V_95 , V_52 ) ;
} else if ( V_78 == 0x04 && V_76 == 4 ) {
V_117 = F_76 ( V_7 , V_94 , V_95 , V_52 ) ;
} else if ( V_78 == 0x08 && V_76 == 8 ) {
V_117 = F_77 ( V_7 , V_94 , V_95 , V_52 ) ;
} else if ( V_78 == 0x10 && V_76 == 4 ) {
V_117 = F_79 ( V_7 , V_94 , V_95 , V_52 ) ;
} else if ( V_78 == 0x14 && V_76 == 4 ) {
V_117 = F_80 ( V_7 , V_94 ,
V_95 , V_52 ) ;
} else {
V_117 = V_119 ;
}
V_118:
F_82 ( V_7 , V_111 , V_117 ) ;
}
static void F_83 ( struct V_91 * V_92 )
{
struct V_120 * V_3 =
F_73 ( V_92 , struct V_120 , V_92 ) ;
F_58 ( L_35 ,
V_3 -> V_106 ,
F_50 ( & V_3 -> V_59 . V_121 ) ,
F_50 ( & V_3 -> V_59 . V_122 ) ,
F_3 ( V_3 -> V_59 . V_60 ) ) ;
if ( V_3 -> V_106 >> 32 )
F_58 ( L_36 ) ;
switch ( F_84 ( F_3 ( V_3 -> V_59 . V_60 ) ) ) {
case 0 :
F_85 ( V_3 ) ;
return;
case 1 :
case 2 :
V_3 -> V_61 . V_61 |= F_42 (
F_43 (
V_62 ) |
F_86 ( 0 ) |
F_87 ( 1 ) |
F_44 (
V_83 ) ) ;
F_88 ( V_3 ) ;
F_89 ( V_3 ) ;
return;
case 3 :
V_3 -> V_61 . V_61 |= F_42 (
F_43 (
V_62 ) |
F_86 ( 0 ) |
F_87 ( 1 ) |
F_44 (
V_123 ) ) ;
F_88 ( V_3 ) ;
F_89 ( V_3 ) ;
return;
default:
F_90 () ;
}
}
static inline bool F_91 ( struct V_96 * V_52 )
{
bool V_124 ;
F_5 ( & V_52 -> V_29 ) ;
V_124 = ( V_52 -> V_97 == V_105 ) ;
F_7 ( & V_52 -> V_29 ) ;
return V_124 ;
}
static void F_92 ( struct V_91 * V_92 )
{
struct V_96 * V_52 =
F_73 ( V_92 , struct V_96 , V_92 ) ;
struct V_15 * V_20 = V_52 -> V_28 -> V_20 ;
struct V_120 * V_3 ;
int V_4 ;
bool V_107 = V_52 -> V_107 ;
T_1 V_121 = V_52 -> V_106 ;
while ( V_121 && F_91 ( V_52 ) ) {
V_3 = F_54 ( sizeof( * V_3 ) , V_41 ) ;
if ( ! V_3 ) {
F_5 ( & V_52 -> V_29 ) ;
V_52 -> V_97 = V_125 ;
F_7 ( & V_52 -> V_29 ) ;
return;
}
V_3 -> V_28 = V_52 -> V_28 ;
V_3 -> V_106 = V_121 ;
V_3 -> V_61 . V_61 = F_42 ( F_93 (
V_3 -> V_106 >> 32 ) ) ;
V_3 -> V_61 . V_126 = F_42 (
V_3 -> V_106 & 0xfffffffc ) ;
V_4 = F_2 ( V_20 -> V_7 , V_109 ,
V_20 -> V_70 , V_20 -> V_10 , V_20 -> V_11 ,
V_3 -> V_106 , & V_3 -> V_59 , sizeof( V_3 -> V_59 ) ) ;
if ( V_4 != V_14 ) {
F_58 ( L_37 , V_4 ) ;
V_3 -> V_61 . V_61 |= F_42 (
F_94 (
V_127 ) |
F_43 (
V_64 ) |
F_86 ( 1 ) |
F_87 ( 1 ) |
F_44 (
V_65 ) ) ;
F_5 ( & V_52 -> V_29 ) ;
V_52 -> V_97 = V_125 ;
F_7 ( & V_52 -> V_29 ) ;
F_88 ( V_3 ) ;
F_89 ( V_3 ) ;
return;
}
if ( F_3 ( V_3 -> V_59 . V_121 . V_5 ) & 0x80000000 ) {
V_121 = 0 ;
V_3 -> V_61 . V_61 |= F_42 ( F_94 (
V_127 ) ) ;
} else {
V_121 = F_50 ( & V_3 -> V_59 . V_121 ) ;
V_3 -> V_61 . V_61 |= F_42 ( F_94 (
V_128 ) ) ;
}
if ( F_91 ( V_52 ) && ! V_107 ) {
F_95 ( & V_3 -> V_92 , F_83 ) ;
F_78 ( V_108 , & V_3 -> V_92 ) ;
} else {
F_89 ( V_3 ) ;
}
F_5 ( & V_52 -> V_29 ) ;
V_107 = V_52 -> V_107 = false ;
if ( V_121 )
V_52 -> V_106 = V_121 ;
else
V_52 -> V_97 = V_103 ;
F_7 ( & V_52 -> V_29 ) ;
} ;
}
static struct V_96 * F_52 (
struct V_25 * V_28 )
{
struct V_96 * V_52 ;
int V_4 ;
V_52 = F_16 ( sizeof( * V_52 ) , V_41 ) ;
if ( ! V_52 )
return F_18 ( - V_42 ) ;
F_26 ( & V_52 -> V_29 ) ;
V_52 -> V_77 . V_76 = 0x20 ;
V_52 -> V_77 . V_129 = F_81 ;
V_52 -> V_77 . V_114 = V_52 ;
V_52 -> V_28 = V_28 ;
V_52 -> V_97 = V_100 ;
F_95 ( & V_52 -> V_92 , F_92 ) ;
V_52 -> V_106 = 0 ;
V_52 -> V_107 = false ;
V_4 = F_96 ( & V_52 -> V_77 ,
& V_130 ) ;
if ( V_4 < 0 ) {
F_22 ( V_52 ) ;
return F_18 ( V_4 ) ;
}
return V_52 ;
}
static void F_37 ( struct V_96 * V_52 )
{
F_97 ( & V_52 -> V_77 ) ;
F_98 ( & V_52 -> V_92 ) ;
F_22 ( V_52 ) ;
}
static int F_2 ( struct V_93 * V_7 , int V_94 , int V_131 ,
int V_10 , int V_11 , unsigned long long V_78 ,
void * V_132 , T_4 V_76 )
{
int V_133 , V_4 , V_134 ;
for ( V_133 = 1 ; V_133 <= 5 ; V_133 ++ ) {
V_4 = F_99 ( V_7 , V_94 , V_131 ,
V_10 , V_11 , V_78 , V_132 , V_76 ) ;
switch ( V_4 ) {
case V_14 :
case V_99 :
case V_119 :
case V_135 :
return V_4 ;
default:
V_134 = 5 * V_133 * V_133 ;
F_100 ( V_134 , V_134 * 2 ) ;
}
}
return V_4 ;
}
static int F_101 ( struct V_120 * V_3 ,
int V_94 , unsigned long long V_78 , void * V_132 ,
T_4 V_76 )
{
struct V_25 * V_28 = V_3 -> V_28 ;
struct V_15 * V_20 = V_28 -> V_20 ;
struct V_93 * V_7 ;
int V_70 , V_10 , V_11 , V_4 ;
F_5 ( & V_20 -> V_29 ) ;
V_7 = F_46 ( V_20 -> V_7 ) ;
V_70 = V_20 -> V_70 ;
V_10 = V_20 -> V_10 ;
V_11 = V_20 -> V_11 ;
F_7 ( & V_20 -> V_29 ) ;
V_4 = F_2 ( V_7 , V_94 , V_70 , V_10 , V_11 ,
V_78 , V_132 , V_76 ) ;
F_35 ( V_7 ) ;
return V_4 ;
}
static int F_102 ( struct V_120 * V_3 )
{
int V_4 , V_136 , V_137 ;
V_136 = F_103 ( V_3 -> V_59 . V_138 ) ;
V_3 -> V_139 = F_16 ( V_136 , V_41 ) ;
if ( ! V_3 -> V_139 )
return - V_42 ;
memcpy ( V_3 -> V_139 , V_3 -> V_59 . V_138 ,
F_104 ( int , V_136 , sizeof( V_3 -> V_59 . V_138 ) ) ) ;
if ( V_136 > sizeof( V_3 -> V_59 . V_138 ) ) {
F_58 ( L_38 ) ;
V_137 = V_136 - sizeof( V_3 -> V_59 . V_138 ) ;
V_4 = F_101 ( V_3 ,
V_109 ,
V_3 -> V_106 + sizeof( V_3 -> V_59 ) ,
V_3 -> V_139 + sizeof( V_3 -> V_59 . V_138 ) ,
V_137 ) ;
if ( V_4 != V_14 )
return - V_140 ;
}
return 0 ;
}
static int F_105 ( struct V_120 * V_3 )
{
int V_141 , V_4 ;
struct V_142 * V_143 ;
if ( ! F_106 ( F_3 ( V_3 -> V_59 . V_60 ) ) )
return 0 ;
V_141 = F_107 ( F_3 ( V_3 -> V_59 . V_60 ) ) *
sizeof( struct V_142 ) ;
V_143 = F_16 ( V_141 , V_41 ) ;
if ( ! V_143 )
return - V_42 ;
V_4 = F_101 ( V_3 , V_109 ,
F_50 ( & V_3 -> V_59 . V_122 ) ,
V_143 , V_141 ) ;
if ( V_4 != V_14 ) {
F_22 ( V_143 ) ;
return - V_140 ;
}
V_3 -> V_143 = V_143 ;
return 0 ;
}
static void F_108 ( struct V_120 * V_3 ,
T_3 * V_144 , enum V_145 * V_146 )
{
int V_147 , V_148 , V_149 ;
V_147 = F_107 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
V_148 = F_109 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
if ( ! V_147 ) {
* V_144 = 0 ;
* V_146 = V_150 ;
return;
}
* V_146 = V_148 ? V_151 : V_152 ;
if ( V_3 -> V_143 ) {
* V_144 = 0 ;
for ( V_149 = 0 ; V_149 < V_147 ; V_149 ++ ) {
* V_144 += F_110 (
V_3 -> V_143 [ V_149 ] . V_153 ) ;
}
} else {
* V_144 = V_147 ;
}
}
static void F_85 ( struct V_120 * V_3 )
{
struct V_25 * V_28 = V_3 -> V_28 ;
struct V_15 * V_20 = V_28 -> V_20 ;
int V_4 , V_27 ;
T_3 V_154 ;
enum V_145 V_146 ;
V_4 = F_102 ( V_3 ) ;
if ( V_4 ) {
F_58 ( L_39 , V_4 ) ;
goto V_34;
}
V_4 = F_105 ( V_3 ) ;
if ( V_4 ) {
F_58 ( L_40 ,
V_4 ) ;
goto V_34;
}
V_27 = V_3 -> V_28 -> V_30 ;
F_108 ( V_3 , & V_154 , & V_146 ) ;
F_58 ( L_41 ,
V_3 -> V_106 , V_27 , V_154 , V_146 ) ;
V_3 -> V_155 . V_156 = V_3 -> V_106 ;
if ( F_111 ( & V_3 -> V_155 , V_20 -> V_19 , V_3 -> V_139 ,
V_3 -> V_157 , V_27 , V_154 ,
V_158 , V_146 , 0 ) )
goto V_34;
return;
V_34:
V_3 -> V_61 . V_61 |= F_42 (
F_43 ( V_64 ) |
F_86 ( 0 ) |
F_87 ( 1 ) |
F_44 ( V_65 ) ) ;
F_88 ( V_3 ) ;
F_89 ( V_3 ) ;
}
static int F_112 ( struct V_120 * V_3 )
{
struct V_15 * V_20 = V_3 -> V_28 -> V_20 ;
int V_94 , V_159 , V_160 , V_161 , V_11 , V_70 ,
V_10 , V_162 , V_76 , V_163 ,
V_117 = V_14 ;
struct V_142 * V_164 ;
unsigned long long V_78 ;
struct V_93 * V_7 ;
struct V_165 V_166 ;
if ( V_3 -> V_155 . V_167 == V_151 ) {
V_94 = V_80 ;
V_159 = V_168 ;
} else {
V_94 = V_109 ;
V_159 = V_169 ;
}
V_160 = 4 << F_113 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
V_11 = F_114 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
V_161 = F_115 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
if ( V_161 ) {
F_17 ( L_42 ) ;
V_161 = 0x100 << V_161 ;
}
F_5 ( & V_20 -> V_29 ) ;
V_7 = F_46 ( V_20 -> V_7 ) ;
V_70 = V_20 -> V_70 ;
V_10 = V_20 -> V_10 ;
F_7 ( & V_20 -> V_29 ) ;
if ( V_3 -> V_143 ) {
V_164 = V_3 -> V_143 ;
V_162 = F_107 ( F_3 ( V_3 -> V_59 . V_60 ) ) ;
V_78 = 0 ;
V_76 = 0 ;
} else {
V_164 = NULL ;
V_162 = 0 ;
V_78 = F_50 ( & V_3 -> V_59 . V_122 ) ;
V_76 = V_3 -> V_155 . V_154 ;
}
F_116 ( & V_166 , V_3 -> V_155 . V_170 , V_3 -> V_155 . V_171 ,
V_159 ) ;
while ( V_76 || V_162 ) {
if ( ! V_76 ) {
V_78 = ( T_1 ) F_110 ( V_164 -> V_172 ) << 32 |
F_3 ( V_164 -> V_173 ) ;
V_76 = F_110 ( V_164 -> V_153 ) ;
V_164 ++ ;
V_162 -- ;
}
F_117 ( & V_166 ) ;
V_163 = F_118 ( V_76 , V_160 , ( int ) V_166 . V_76 ) ;
V_117 = F_2 ( V_7 , V_94 , V_70 ,
V_10 , V_11 ,
V_78 , V_166 . V_174 , V_163 ) ;
if ( V_117 != V_14 )
break;
V_76 -= V_163 ;
V_78 += V_163 ;
V_166 . V_175 = V_163 ;
}
F_119 ( & V_166 ) ;
F_35 ( V_7 ) ;
if ( V_117 == V_14 ) {
F_120 ( V_76 != 0 ) ;
return 0 ;
} else {
return - V_140 ;
}
}
static int F_88 ( struct V_120 * V_3 )
{
int V_4 , V_76 ;
struct V_25 * V_28 = V_3 -> V_28 ;
V_76 = ( ( ( F_3 ( V_3 -> V_61 . V_61 ) >> 24 ) & 0x07 ) + 1 ) * 4 ;
V_4 = F_101 ( V_3 , V_80 ,
V_28 -> V_74 , & V_3 -> V_61 , V_76 ) ;
if ( V_4 != V_14 ) {
F_58 ( L_43 , V_4 ) ;
return - V_140 ;
}
F_58 ( L_44 ,
V_3 -> V_106 ) ;
return 0 ;
}
static void F_121 ( struct V_120 * V_3 )
{
struct V_155 * V_155 = & V_3 -> V_155 ;
T_5 * V_176 = V_3 -> V_157 ;
T_5 * V_61 = V_3 -> V_61 . V_95 ;
F_120 ( V_155 -> V_177 < 18 ) ;
switch ( V_176 [ 0 ] & 0x7f ) {
case 0x70 :
V_61 [ 0 ] = 0 << 6 ;
break;
case 0x71 :
V_61 [ 0 ] = 1 << 6 ;
break;
case 0x72 :
case 0x73 :
default:
F_17 ( L_45 ,
V_176 [ 0 ] ) ;
V_3 -> V_61 . V_61 |= F_42 (
F_43 ( V_62 ) |
F_86 ( 0 ) |
F_87 ( 1 ) |
F_44 ( V_178 ) ) ;
return;
}
V_61 [ 0 ] |= V_155 -> V_179 & 0x3f ;
V_61 [ 1 ] =
( V_176 [ 0 ] & 0x80 ) |
( ( V_176 [ 2 ] & 0xe0 ) >> 1 ) |
( V_176 [ 2 ] & 0x0f ) ;
V_61 [ 2 ] = V_155 -> V_180 ;
V_61 [ 3 ] = V_155 -> V_181 ;
V_61 [ 4 ] = V_176 [ 3 ] ;
V_61 [ 5 ] = V_176 [ 4 ] ;
V_61 [ 6 ] = V_176 [ 5 ] ;
V_61 [ 7 ] = V_176 [ 6 ] ;
V_61 [ 8 ] = V_176 [ 8 ] ;
V_61 [ 9 ] = V_176 [ 9 ] ;
V_61 [ 10 ] = V_176 [ 10 ] ;
V_61 [ 11 ] = V_176 [ 11 ] ;
V_61 [ 12 ] = V_176 [ 14 ] ;
V_61 [ 13 ] = V_176 [ 15 ] ;
V_61 [ 14 ] = V_176 [ 16 ] ;
V_61 [ 15 ] = V_176 [ 17 ] ;
V_3 -> V_61 . V_61 |= F_42 (
F_43 ( V_62 ) |
F_86 ( 0 ) |
F_87 ( 5 ) |
F_44 ( V_82 ) ) ;
}
static int F_122 ( struct V_120 * V_3 )
{
struct V_155 * V_155 = & V_3 -> V_155 ;
if ( V_155 -> V_177 ) {
F_121 ( V_3 ) ;
} else {
V_3 -> V_61 . V_61 |= F_42 (
F_43 ( V_62 ) |
F_86 ( 0 ) |
F_87 ( 1 ) |
F_44 ( V_82 ) ) ;
}
return F_88 ( V_3 ) ;
}
static void F_89 ( struct V_120 * V_3 )
{
F_22 ( V_3 -> V_143 ) ;
F_22 ( V_3 -> V_139 ) ;
F_22 ( V_3 ) ;
}
static void F_123 ( struct V_91 * V_92 )
{
struct V_51 * V_52 =
F_73 ( V_92 , struct V_51 , V_92 ) ;
struct V_2 * V_3 = V_52 -> V_111 ;
int V_4 ;
int V_182 = 0 ;
V_4 = F_2 ( V_3 -> V_7 , V_109 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
V_52 -> V_183 , & V_3 -> V_59 , sizeof( V_3 -> V_59 ) ) ;
if ( V_4 != V_14 ) {
F_58 ( L_46 , V_4 ) ;
goto V_118;
}
F_58 ( L_47 ,
F_50 ( & V_3 -> V_59 . V_184 ) ,
F_50 ( & V_3 -> V_59 . V_81 ) ,
F_3 ( V_3 -> V_59 . V_60 ) , F_3 ( V_3 -> V_59 . V_76 ) ,
F_50 ( & V_3 -> V_59 . V_75 ) ) ;
if ( ! F_124 ( F_3 ( V_3 -> V_59 . V_60 ) ) ||
F_84 ( F_3 ( V_3 -> V_59 . V_60 ) ) != 0 ) {
F_17 ( L_48 ) ;
goto V_118;
}
switch ( F_125 ( F_3 ( V_3 -> V_59 . V_60 ) ) ) {
case V_185 :
F_39 ( V_52 , V_3 , & V_182 ) ;
break;
case V_186 :
F_59 ( V_52 , V_3 ,
& V_182 ) ;
break;
case V_187 :
F_60 ( V_52 , V_3 , & V_182 ) ;
break;
case V_188 :
F_41 ( L_49 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_83 ) ) ;
break;
case V_189 :
F_62 ( V_52 , V_3 , & V_182 ) ;
break;
case V_190 :
F_41 ( L_50 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_83 ) ) ;
break;
case V_191 :
F_41 ( L_51 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_83 ) ) ;
break;
case V_192 :
F_41 ( L_52 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_83 ) ) ;
break;
case V_193 :
F_41 ( L_53 ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_83 ) ) ;
break;
default:
F_41 ( L_54 ,
F_125 ( F_3 ( V_3 -> V_59 . V_60 ) ) ) ;
V_3 -> V_61 . V_61 = F_42 (
F_43 ( V_62 ) |
F_44 ( V_83 ) ) ;
break;
}
V_3 -> V_61 . V_61 |= F_42 (
F_94 ( 1 ) |
F_87 ( F_126 ( V_182 , 4 ) + 1 ) |
F_93 ( V_52 -> V_183 >> 32 ) ) ;
V_3 -> V_61 . V_126 = F_42 ( V_52 -> V_183 ) ;
V_4 = F_2 ( V_3 -> V_7 , V_80 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
F_50 ( & V_3 -> V_59 . V_75 ) ,
& V_3 -> V_61 , 8 + V_182 ) ;
if ( V_4 != V_14 ) {
F_58 ( L_55 , V_4 ) ;
goto V_118;
}
V_118:
F_35 ( V_3 -> V_7 ) ;
F_22 ( V_3 ) ;
F_5 ( & V_52 -> V_29 ) ;
V_52 -> V_97 = V_194 ;
F_7 ( & V_52 -> V_29 ) ;
}
static void F_127 ( struct V_93 * V_7 ,
struct V_110 * V_111 , int V_94 , int V_112 , int V_113 ,
int V_10 , unsigned long long V_78 , void * V_95 , T_4 V_76 ,
void * V_114 )
{
struct V_51 * V_52 = V_114 ;
struct V_101 * V_102 = V_95 ;
int V_117 = V_119 ;
if ( ! V_52 -> V_55 -> V_195 )
goto V_118;
if ( ( V_78 != V_52 -> V_77 . V_78 ) || ( V_76 != 8 ) )
goto V_118;
if ( V_94 == V_80 ) {
struct V_2 * V_3 ;
int V_196 ;
F_5 ( & V_52 -> V_29 ) ;
V_196 = V_52 -> V_97 ;
V_52 -> V_97 = V_197 ;
F_7 ( & V_52 -> V_29 ) ;
if ( V_196 == V_197 ) {
F_41 ( L_56 ) ;
V_117 = V_104 ;
goto V_118;
}
V_3 = F_54 ( sizeof( * V_3 ) , V_198 ) ;
if ( ! V_3 ) {
V_117 = V_104 ;
goto V_118;
}
V_3 -> V_7 = F_46 ( V_7 ) ;
V_3 -> V_10 = V_10 ;
V_3 -> V_9 = V_113 ;
V_3 -> V_11 = F_128 ( V_111 ) ;
V_52 -> V_183 = F_50 ( V_102 ) ;
V_52 -> V_111 = V_3 ;
F_78 ( V_108 , & V_52 -> V_92 ) ;
V_117 = V_14 ;
} else if ( V_94 == V_109 ) {
F_57 ( V_52 -> V_183 , V_102 ) ;
V_117 = V_14 ;
} else {
V_117 = V_99 ;
}
V_118:
F_82 ( V_7 , V_111 , V_117 ) ;
}
static struct V_51 * F_129 (
struct V_54 * V_55 )
{
int V_4 ;
struct V_51 * V_52 ;
V_52 = F_16 ( sizeof( * V_52 ) , V_41 ) ;
if ( ! V_52 )
return F_18 ( - V_42 ) ;
F_26 ( & V_52 -> V_29 ) ;
V_52 -> V_55 = V_55 ;
V_52 -> V_77 . V_76 = 0x08 ;
V_52 -> V_77 . V_129 = F_127 ;
V_52 -> V_77 . V_114 = V_52 ;
V_52 -> V_97 = V_194 ;
F_95 ( & V_52 -> V_92 , F_123 ) ;
V_52 -> V_183 = 0 ;
V_52 -> V_111 = NULL ;
V_4 = F_96 ( & V_52 -> V_77 ,
& V_130 ) ;
if ( V_4 < 0 ) {
F_22 ( V_52 ) ;
return F_18 ( V_4 ) ;
}
return V_52 ;
}
static void F_130 ( struct V_51 * V_52 )
{
F_97 ( & V_52 -> V_77 ) ;
F_98 ( & V_52 -> V_92 ) ;
F_22 ( V_52 ) ;
}
static int F_131 ( struct V_35 * V_22 )
{
return 1 ;
}
static int F_132 ( struct V_35 * V_22 )
{
return 0 ;
}
static char * F_133 ( void )
{
return L_57 ;
}
static char * F_134 ( struct V_35 * V_22 )
{
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
return & V_55 -> V_199 [ 0 ] ;
}
static T_6 F_135 ( struct V_35 * V_22 )
{
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
return V_17 -> V_200 ;
}
static T_3 F_136 ( struct V_35 * V_22 )
{
return 1 ;
}
static void F_137 ( struct V_155 * V_155 )
{
struct V_120 * V_3 = F_73 ( V_155 ,
struct V_120 , V_155 ) ;
F_89 ( V_3 ) ;
}
static int F_138 ( struct V_18 * V_19 )
{
return 0 ;
}
static void F_139 ( struct V_18 * V_19 )
{
return;
}
static T_3 F_140 ( struct V_18 * V_19 )
{
return 0 ;
}
static int F_141 ( struct V_155 * V_155 )
{
struct V_120 * V_3 = F_73 ( V_155 ,
struct V_120 , V_155 ) ;
int V_4 ;
V_4 = F_112 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_61 . V_61 |= F_42 (
F_43 (
V_64 ) |
F_86 ( 0 ) |
F_87 ( 1 ) |
F_44 (
V_65 ) ) ;
F_88 ( V_3 ) ;
return V_4 ;
}
F_142 ( V_155 ) ;
return 0 ;
}
static int F_143 ( struct V_155 * V_155 )
{
return 0 ;
}
static void F_144 ( struct V_39 * V_201 )
{
return;
}
static int F_145 ( struct V_155 * V_155 )
{
return 0 ;
}
static int F_146 ( struct V_155 * V_155 )
{
struct V_120 * V_3 = F_73 ( V_155 ,
struct V_120 , V_155 ) ;
int V_4 ;
V_4 = F_112 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_61 . V_61 |= F_42 (
F_43 ( V_64 ) |
F_86 ( 0 ) |
F_87 ( 1 ) |
F_44 ( V_65 ) ) ;
F_88 ( V_3 ) ;
return V_4 ;
}
return F_122 ( V_3 ) ;
}
static int F_147 ( struct V_155 * V_155 )
{
struct V_120 * V_3 = F_73 ( V_155 ,
struct V_120 , V_155 ) ;
return F_122 ( V_3 ) ;
}
static void F_148 ( struct V_155 * V_155 )
{
}
static void F_149 ( struct V_155 * V_155 )
{
return;
}
static int F_150 ( struct V_155 * V_155 )
{
struct V_120 * V_3 = F_73 ( V_155 ,
struct V_120 , V_155 ) ;
F_151 ( & V_3 -> V_155 , 0 ) ;
return 1 ;
}
static int F_152 ( struct V_35 * V_17 )
{
struct V_36 * V_202 ;
int V_32 = 0 ;
F_12 () ;
F_13 (lun, &tpg->tpg_lun_hlist, link)
V_32 ++ ;
F_14 () ;
return V_32 ;
}
static int F_153 ( struct V_54 * V_55 )
{
struct V_36 * V_202 ;
int V_203 , V_204 , V_149 = 0 , V_205 , V_4 ;
T_3 * V_95 ;
if ( V_55 -> V_206 . V_95 ) {
F_154 ( & V_55 -> V_206 ) ;
F_22 ( V_55 -> V_206 . V_95 ) ;
V_55 -> V_206 . V_95 = NULL ;
}
if ( ! V_55 -> V_195 || ! V_55 -> V_17 )
return 0 ;
V_203 = F_152 ( & V_55 -> V_17 -> V_22 ) ;
V_204 = F_155 ( V_207 ) + 4 + V_203 ;
if ( V_55 -> V_208 != - 1 )
V_204 ++ ;
V_95 = F_156 ( ( V_204 + 4 ) , sizeof( T_3 ) , V_41 ) ;
if ( ! V_95 )
return - V_42 ;
V_95 [ V_149 ++ ] = V_204 << 16 ;
if ( V_55 -> V_208 != - 1 )
V_95 [ V_149 ++ ] = ( V_209 << 24 ) | V_55 -> V_208 ;
memcpy ( & V_95 [ V_149 ] , V_207 ,
sizeof( V_207 ) ) ;
V_149 += F_155 ( V_207 ) ;
V_205 = ( V_55 -> V_210 -> V_77 . V_78 - V_12 ) / 4 ;
V_95 [ V_149 ++ ] = 0x54000000 | ( V_205 & 0x00ffffff ) ;
V_95 [ V_149 ++ ] = 0x3a000000 |
( ( ( V_55 -> V_211 * 2 ) << 8 ) & 0xff00 ) |
V_212 ;
V_95 [ V_149 ++ ] = 0x3d000000 | ( V_55 -> V_73 & 0xffff ) ;
V_95 [ V_149 ++ ] = 0x8d000000 | ( V_203 + 1 ) ;
F_12 () ;
F_13 (lun, &tport->tpg->se_tpg.tpg_lun_hlist, link) {
struct V_213 * V_214 ;
int type ;
V_214 = F_157 ( V_202 -> V_215 ) ;
type = V_214 -> V_216 -> V_217 ( V_214 ) ;
V_95 [ V_149 ++ ] = 0x14000000 |
( ( type << 16 ) & 0x1f0000 ) |
( V_202 -> V_27 & 0xffff ) ;
}
F_14 () ;
V_95 [ V_149 ++ ] = 2 << 16 ;
V_95 [ V_149 ++ ] = V_55 -> V_1 >> 32 ;
V_95 [ V_149 ++ ] = V_55 -> V_1 ;
V_55 -> V_206 . V_76 = V_149 ;
V_55 -> V_206 . V_218 = ( V_219 | V_220 ) << 24 ;
V_55 -> V_206 . V_95 = V_95 ;
V_4 = F_158 ( & V_55 -> V_206 ) ;
if ( V_4 < 0 ) {
F_22 ( V_55 -> V_206 . V_95 ) ;
V_55 -> V_206 . V_95 = NULL ;
}
return V_4 ;
}
static T_7 F_159 ( const char * V_221 , T_1 * V_222 )
{
const char * V_223 ;
char V_224 , V_225 ;
int V_226 = 0 , V_34 ;
* V_222 = 0 ;
for ( V_223 = V_221 ; V_223 < & V_221 [ V_227 - 1 ] ; V_223 ++ ) {
V_224 = * V_223 ;
if ( V_224 == '\n' && V_223 [ 1 ] == '\0' )
continue;
if ( V_224 == '\0' ) {
V_34 = 2 ;
if ( V_226 != 16 )
goto V_228;
return V_223 - V_221 ;
}
V_34 = 3 ;
if ( isdigit ( V_224 ) )
V_225 = V_224 - '0' ;
else if ( isxdigit ( V_224 ) )
V_225 = tolower ( V_224 ) - 'a' + 10 ;
else
goto V_228;
* V_222 = ( * V_222 << 4 ) | V_225 ;
V_226 ++ ;
}
V_34 = 4 ;
V_228:
F_160 ( V_229 L_58 ,
V_34 , V_223 - V_221 , V_226 ) ;
return - 1 ;
}
static T_7 F_161 ( char * V_230 , T_4 V_231 , T_1 V_222 )
{
return snprintf ( V_230 , V_231 , L_3 , V_222 ) ;
}
static int F_162 ( struct V_39 * V_40 , const char * V_221 )
{
T_1 V_1 = 0 ;
if ( F_159 ( V_221 , & V_1 ) < 0 )
return - V_232 ;
return 0 ;
}
static int F_163 (
struct V_35 * V_22 ,
struct V_36 * V_36 )
{
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
return F_153 ( V_17 -> V_55 ) ;
}
static void F_164 (
struct V_35 * V_22 ,
struct V_36 * V_36 )
{
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
int V_4 ;
if ( F_152 ( & V_17 -> V_22 ) == 0 )
V_55 -> V_195 = 0 ;
V_4 = F_153 ( V_55 ) ;
if ( V_4 < 0 )
F_17 ( L_59 ) ;
}
static struct V_35 * F_165 (
struct V_233 * V_222 ,
struct V_234 * V_235 ,
const char * V_221 )
{
struct V_54 * V_55 =
F_73 ( V_222 , struct V_54 , V_236 ) ;
struct V_16 * V_17 ;
unsigned long V_237 ;
int V_4 ;
if ( strstr ( V_221 , L_60 ) != V_221 )
return F_18 ( - V_232 ) ;
if ( F_166 ( V_221 + 5 , 10 , & V_237 ) || V_237 > V_238 )
return F_18 ( - V_232 ) ;
if ( V_55 -> V_17 ) {
F_17 ( L_61 ) ;
return F_18 ( - V_239 ) ;
}
V_17 = F_54 ( sizeof( * V_17 ) , V_41 ) ;
if ( ! V_17 ) {
F_17 ( L_62 ) ;
return F_18 ( - V_42 ) ;
}
V_17 -> V_55 = V_55 ;
V_17 -> V_200 = V_237 ;
V_55 -> V_17 = V_17 ;
V_55 -> V_195 = 0 ;
V_55 -> V_208 = - 1 ;
V_55 -> V_211 = 15 ;
V_55 -> V_73 = 5 ;
V_55 -> V_68 = 1 ;
V_55 -> V_210 = F_129 ( V_55 ) ;
if ( F_20 ( V_55 -> V_210 ) ) {
V_4 = F_21 ( V_55 -> V_210 ) ;
goto V_240;
}
V_4 = F_167 ( V_222 , & V_17 -> V_22 , V_241 ) ;
if ( V_4 < 0 )
goto V_242;
return & V_17 -> V_22 ;
V_242:
F_130 ( V_55 -> V_210 ) ;
V_240:
V_55 -> V_17 = NULL ;
F_22 ( V_17 ) ;
return F_18 ( V_4 ) ;
}
static void F_168 ( struct V_35 * V_22 )
{
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
F_169 ( V_22 ) ;
F_130 ( V_55 -> V_210 ) ;
V_55 -> V_17 = NULL ;
F_22 ( V_17 ) ;
}
static struct V_233 * F_170 (
struct V_243 * V_244 ,
struct V_234 * V_235 ,
const char * V_221 )
{
struct V_54 * V_55 ;
T_1 V_1 = 0 ;
if ( F_159 ( V_221 , & V_1 ) < 0 )
return F_18 ( - V_232 ) ;
V_55 = F_54 ( sizeof( * V_55 ) , V_41 ) ;
if ( ! V_55 ) {
F_17 ( L_63 ) ;
return F_18 ( - V_42 ) ;
}
V_55 -> V_1 = V_1 ;
F_161 ( V_55 -> V_199 , V_227 , V_1 ) ;
return & V_55 -> V_236 ;
}
static void F_171 ( struct V_233 * V_222 )
{
struct V_54 * V_55 =
F_73 ( V_222 , struct V_54 , V_236 ) ;
F_22 ( V_55 ) ;
}
static T_7 F_172 ( struct V_245 * V_246 , char * V_247 )
{
return sprintf ( V_247 , L_64 , V_248 ) ;
}
static T_7 F_173 ( struct V_245 * V_246 , char * V_247 )
{
struct V_35 * V_22 = F_174 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
if ( V_55 -> V_208 == - 1 )
return sprintf ( V_247 , L_65 ) ;
else
return sprintf ( V_247 , L_66 , V_55 -> V_208 ) ;
}
static T_7 F_175 ( struct V_245 * V_246 ,
const char * V_247 , T_4 V_32 )
{
struct V_35 * V_22 = F_174 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
unsigned long V_249 ;
if ( V_55 -> V_195 ) {
F_17 ( L_67 ) ;
return - V_239 ;
}
if ( strstr ( V_247 , L_68 ) == V_247 ) {
V_55 -> V_208 = - 1 ;
} else {
if ( F_166 ( V_247 , 16 , & V_249 ) < 0 )
return - V_232 ;
if ( V_249 > 0xffffff )
return - V_232 ;
V_55 -> V_208 = V_249 ;
}
return V_32 ;
}
static T_7 F_176 ( struct V_245 * V_246 , char * V_247 )
{
struct V_35 * V_22 = F_174 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
return sprintf ( V_247 , L_69 , V_55 -> V_195 ) ;
}
static T_7 F_177 ( struct V_245 * V_246 ,
const char * V_247 , T_4 V_32 )
{
struct V_35 * V_22 = F_174 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
unsigned long V_249 ;
int V_4 ;
if ( F_166 ( V_247 , 0 , & V_249 ) < 0 )
return - V_232 ;
if ( ( V_249 != 0 ) && ( V_249 != 1 ) )
return - V_232 ;
if ( V_55 -> V_195 == V_249 )
return V_32 ;
if ( V_249 ) {
if ( F_152 ( & V_17 -> V_22 ) == 0 ) {
F_17 ( L_70 ) ;
return - V_232 ;
}
} else {
F_5 ( & V_22 -> V_23 ) ;
if ( ! F_31 ( & V_22 -> V_250 ) ) {
F_7 ( & V_22 -> V_23 ) ;
return - V_239 ;
}
F_7 ( & V_22 -> V_23 ) ;
}
V_55 -> V_195 = V_249 ;
V_4 = F_153 ( V_55 ) ;
if ( V_4 < 0 ) {
F_17 ( L_71 ) ;
return V_4 ;
}
return V_32 ;
}
static T_7 F_178 ( struct V_245 * V_246 ,
char * V_247 )
{
struct V_35 * V_22 = F_179 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
return sprintf ( V_247 , L_69 , V_55 -> V_211 ) ;
}
static T_7 F_180 ( struct V_245 * V_246 ,
const char * V_247 , T_4 V_32 )
{
struct V_35 * V_22 = F_179 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
unsigned long V_249 ;
int V_4 ;
if ( F_166 ( V_247 , 0 , & V_249 ) < 0 )
return - V_232 ;
if ( ( V_249 < 1 ) || ( V_249 > 127 ) )
return - V_232 ;
if ( V_55 -> V_211 == V_249 )
return V_32 ;
V_55 -> V_211 = V_249 ;
V_4 = F_153 ( V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_181 ( struct V_245 * V_246 ,
char * V_247 )
{
struct V_35 * V_22 = F_179 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
return sprintf ( V_247 , L_69 , V_55 -> V_73 ) ;
}
static T_7 F_182 ( struct V_245 * V_246 ,
const char * V_247 , T_4 V_32 )
{
struct V_35 * V_22 = F_179 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
unsigned long V_249 ;
int V_4 ;
if ( F_166 ( V_247 , 0 , & V_249 ) < 0 )
return - V_232 ;
if ( ( V_249 < 1 ) || ( V_249 > 32767 ) )
return - V_232 ;
if ( V_55 -> V_73 == V_249 )
return V_32 ;
V_55 -> V_73 = V_249 ;
V_4 = F_153 ( V_55 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_183 ( struct V_245 * V_246 ,
char * V_247 )
{
struct V_35 * V_22 = F_179 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
return sprintf ( V_247 , L_69 , V_55 -> V_68 ) ;
}
static T_7 F_184 ( struct V_245 * V_246 ,
const char * V_247 , T_4 V_32 )
{
struct V_35 * V_22 = F_179 ( V_246 ) ;
struct V_16 * V_17 = F_73 ( V_22 , struct V_16 , V_22 ) ;
struct V_54 * V_55 = V_17 -> V_55 ;
unsigned long V_249 ;
if ( F_166 ( V_247 , 0 , & V_249 ) < 0 )
return - V_232 ;
if ( ( V_249 < 1 ) || ( V_249 > 127 ) )
return - V_232 ;
V_55 -> V_68 = V_249 ;
return V_32 ;
}
static int T_8 F_185 ( void )
{
return F_186 ( & V_251 ) ;
}
static void T_9 F_187 ( void )
{
F_188 ( & V_251 ) ;
}
