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
snprintf ( V_38 , sizeof( V_38 ) , L_1 , V_1 ) ;
V_20 = F_16 ( sizeof( * V_20 ) , V_39 ) ;
if ( ! V_20 ) {
F_17 ( L_2 ) ;
return F_18 ( - V_40 ) ;
}
F_19 ( & V_20 -> V_29 ) ;
F_20 ( & V_20 -> V_41 ) ;
F_21 ( & V_20 -> V_42 , V_43 ) ;
V_20 -> V_1 = V_1 ;
V_20 -> V_19 = F_22 ( & V_17 -> V_22 , 128 ,
sizeof( struct V_44 ) ,
V_45 , V_38 ,
V_20 , NULL ) ;
if ( F_23 ( V_20 -> V_19 ) ) {
F_17 ( L_3 ) ;
V_4 = F_24 ( V_20 -> V_19 ) ;
F_25 ( V_20 ) ;
return F_18 ( V_4 ) ;
}
return V_20 ;
}
static void F_26 ( struct V_15 * V_20 , bool V_46 )
{
F_5 ( & V_20 -> V_29 ) ;
if ( ! F_27 ( & V_20 -> V_41 ) ) {
F_7 ( & V_20 -> V_29 ) ;
return;
}
F_7 ( & V_20 -> V_29 ) ;
if ( V_46 )
F_28 ( & V_20 -> V_42 ) ;
F_29 ( V_20 -> V_19 ) ;
F_30 ( V_20 -> V_19 ) ;
if ( V_20 -> V_7 )
F_31 ( V_20 -> V_7 ) ;
F_25 ( V_20 ) ;
}
static void F_32 ( struct V_25 * V_28 ,
bool V_46 )
{
struct V_15 * V_20 = V_28 -> V_20 ;
F_33 ( V_28 -> V_47 ) ;
if ( V_20 ) {
F_5 ( & V_20 -> V_29 ) ;
F_34 ( & V_28 -> V_48 ) ;
F_7 ( & V_20 -> V_29 ) ;
F_26 ( V_20 , V_46 ) ;
}
F_25 ( V_28 ) ;
}
static void F_35 (
struct V_49 * V_50 , struct V_2 * V_3 ,
int * V_51 )
{
struct V_52 * V_53 = V_50 -> V_53 ;
struct V_16 * V_17 = V_53 -> V_17 ;
struct V_15 * V_20 ;
struct V_25 * V_28 ;
struct V_54 * V_55 ;
T_1 V_1 ;
T_3 V_27 ;
int V_56 , V_4 ;
V_27 = F_11 ( V_17 ,
F_36 ( F_3 ( V_3 -> V_57 . V_58 ) ) , & V_4 ) ;
if ( V_4 ) {
F_37 ( L_4 ,
F_36 ( F_3 ( V_3 -> V_57 . V_58 ) ) ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_61 ) ) ;
return;
}
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_41 ( L_5 , V_4 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_62 ) |
F_40 ( V_63 ) ) ;
return;
}
F_37 ( L_6 ,
V_27 , V_1 ) ;
V_20 = F_4 ( V_17 , V_1 ) ;
if ( V_20 ) {
V_28 = F_8 ( V_20 , V_27 ) ;
if ( V_28 ) {
F_37 ( L_7 ) ;
goto V_64;
}
}
if ( F_42 ( F_3 ( V_3 -> V_57 . V_58 ) ) &&
F_9 ( V_17 , V_27 , 0 ) ) {
F_41 ( L_8 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_65 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 1 ) ) {
F_41 ( L_9 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_65 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 0 ) >=
V_53 -> V_66 ) {
F_41 ( L_10 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_67 ) ) ;
return;
}
if ( ! V_20 ) {
V_20 = F_15 ( V_17 , V_1 ) ;
if ( F_23 ( V_20 ) ) {
switch ( F_24 ( V_20 ) ) {
case - V_68 :
V_4 = V_65 ;
break;
default:
V_4 = V_67 ;
break;
}
V_3 -> V_59 . V_59 = F_38 (
F_39 (
V_60 ) |
F_40 ( V_4 ) ) ;
return;
}
V_20 -> V_69 = V_3 -> V_9 ;
V_20 -> V_7 = F_43 ( V_3 -> V_7 ) ;
V_20 -> V_10 = V_3 -> V_10 ;
V_20 -> V_11 = V_3 -> V_11 ;
F_44 ( & V_20 -> V_42 ,
V_70 ) ;
}
V_20 -> V_71 = F_45 (
1 << F_46 ( F_3 ( V_3 -> V_57 . V_58 ) ) ,
V_53 -> V_72 ) - 1 ;
V_28 = F_16 ( sizeof( * V_28 ) , V_39 ) ;
if ( ! V_28 ) {
F_17 ( L_11 ) ;
F_26 ( V_20 , true ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_67 ) ) ;
return;
}
V_28 -> V_20 = V_20 ;
V_28 -> V_30 = V_27 ;
V_28 -> V_73 = F_47 ( & V_3 -> V_57 . V_74 ) ;
V_28 -> V_31 = F_42 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
V_28 -> V_33 = F_48 ( & V_33 ) ;
V_28 -> V_47 = F_49 ( V_28 ) ;
if ( F_23 ( V_28 -> V_47 ) ) {
V_4 = F_24 ( V_28 -> V_47 ) ;
F_17 ( L_12 , V_4 ) ;
F_26 ( V_20 , true ) ;
F_25 ( V_28 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_67 ) ) ;
return;
}
F_5 ( & V_20 -> V_29 ) ;
F_50 ( & V_28 -> V_48 , & V_20 -> V_41 ) ;
F_7 ( & V_20 -> V_29 ) ;
V_64:
V_55 = F_51 ( sizeof( * V_55 ) , V_39 ) ;
if ( ! V_55 ) {
F_17 ( L_13 ) ;
F_32 ( V_28 , true ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_67 ) ) ;
return;
}
V_56 = F_52 (
F_53 ( F_3 ( V_3 -> V_57 . V_75 ) ) ,
12 , sizeof( * V_55 ) ) ;
V_55 -> V_58 = F_38 (
( ( V_56 & 0xffff ) << 16 ) |
( V_28 -> V_33 & 0xffff ) ) ;
V_55 -> V_71 = F_38 ( V_20 -> V_71 & 0xffff ) ;
F_54 ( V_28 -> V_47 -> V_76 . V_77 ,
& V_55 -> V_78 ) ;
V_4 = F_2 ( V_20 -> V_7 , V_79 ,
V_20 -> V_69 , V_20 -> V_10 , V_20 -> V_11 ,
F_47 ( & V_3 -> V_57 . V_80 ) , V_55 ,
V_56 ) ;
if ( V_4 != V_14 ) {
F_55 ( L_14 , V_4 ) ;
F_25 ( V_55 ) ;
F_32 ( V_28 , true ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_62 ) |
F_40 ( V_63 ) ) ;
return;
}
F_25 ( V_55 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_81 ) ) ;
}
static void F_56 (
struct V_49 * V_50 , struct V_2 * V_3 ,
int * V_51 )
{
F_37 ( L_15 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_82 ) ) ;
}
static void F_57 (
struct V_49 * V_50 , struct V_2 * V_3 ,
int * V_51 )
{
struct V_52 * V_53 = V_50 -> V_53 ;
struct V_16 * V_17 = V_53 -> V_17 ;
int V_4 ;
T_1 V_1 ;
struct V_25 * V_28 ;
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_41 ( L_5 , V_4 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_62 ) |
F_40 ( V_63 ) ) ;
return;
}
F_37 ( L_16 , V_1 ) ;
V_28 = F_10 ( V_17 ,
F_58 ( F_3 ( V_3 -> V_57 . V_58 ) ) ) ;
if ( ! V_28 ) {
F_17 ( L_17 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_65 ) ) ;
return;
}
if ( V_28 -> V_20 -> V_1 != V_1 ) {
F_17 ( L_18 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_65 ) ) ;
return;
}
F_5 ( & V_28 -> V_20 -> V_29 ) ;
if ( V_28 -> V_20 -> V_7 )
F_31 ( V_28 -> V_20 -> V_7 ) ;
V_28 -> V_20 -> V_10 = V_3 -> V_10 ;
V_28 -> V_20 -> V_69 = V_3 -> V_9 ;
V_28 -> V_20 -> V_7 = F_43 ( V_3 -> V_7 ) ;
V_28 -> V_20 -> V_11 = V_3 -> V_11 ;
F_7 ( & V_28 -> V_20 -> V_29 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_81 ) ) ;
}
static void F_59 (
struct V_49 * V_50 , struct V_2 * V_3 ,
int * V_51 )
{
struct V_52 * V_53 = V_50 -> V_53 ;
struct V_16 * V_17 = V_53 -> V_17 ;
int V_83 ;
struct V_25 * V_28 ;
V_83 = F_60 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
V_28 = F_10 ( V_17 , V_83 ) ;
if ( ! V_28 ) {
F_41 ( L_19 , V_83 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_84 ) ) ;
return;
}
F_61 ( L_20 ,
V_28 -> V_30 , V_28 -> V_33 ) ;
if ( V_3 -> V_9 != V_28 -> V_20 -> V_69 ) {
F_41 ( L_21 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_65 ) ) ;
return;
}
F_32 ( V_28 , true ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_81 ) ) ;
}
static void F_62 ( struct V_15 * V_20 )
{
bool V_85 = false ;
F_5 ( & V_20 -> V_29 ) ;
if ( V_20 -> V_7 ) {
F_63 ( & V_20 -> V_7 -> V_29 ) ;
V_85 = ( V_20 -> V_7 -> V_86 != NULL ) ;
F_64 ( & V_20 -> V_7 -> V_29 ) ;
if ( ! V_85 ) {
F_31 ( V_20 -> V_7 ) ;
V_20 -> V_7 = NULL ;
}
}
if ( ! V_85 || ( V_20 -> V_10 != V_20 -> V_7 -> V_10 ) ) {
F_61 ( L_22 ,
V_20 -> V_1 ) ;
V_20 -> V_69 = - 1 ;
V_20 -> V_87 = F_65 () +
( ( V_20 -> V_71 + 1 ) * V_88 ) ;
}
F_7 ( & V_20 -> V_29 ) ;
}
static void F_66 ( struct V_15 * V_20 )
{
struct V_25 * V_28 , * V_89 ;
F_67 ( V_41 ) ;
F_61 ( L_23 , V_20 -> V_1 ) ;
F_5 ( & V_20 -> V_29 ) ;
F_68 (login, temp, &sess->login_list, link) {
V_28 -> V_20 = NULL ;
F_69 ( & V_28 -> V_48 , & V_41 ) ;
}
F_7 ( & V_20 -> V_29 ) ;
F_68 (login, temp, &login_list, link) {
F_34 ( & V_28 -> V_48 ) ;
F_32 ( V_28 , false ) ;
}
F_26 ( V_20 , false ) ;
}
static void V_43 ( struct V_90 * V_91 )
{
struct V_15 * V_20 = F_70 ( V_91 , struct V_15 ,
V_42 . V_91 ) ;
F_5 ( & V_20 -> V_29 ) ;
if ( F_27 ( & V_20 -> V_41 ) ) {
F_7 ( & V_20 -> V_29 ) ;
return;
}
F_7 ( & V_20 -> V_29 ) ;
if ( V_20 -> V_69 != - 1 ) {
F_62 ( V_20 ) ;
F_44 ( & V_20 -> V_42 ,
V_70 ) ;
} else if ( ! F_71 ( F_65 () , V_20 -> V_87 ) ) {
F_44 ( & V_20 -> V_42 ,
V_70 ) ;
} else {
F_66 ( V_20 ) ;
}
}
static int F_72 ( struct V_92 * V_7 , int V_93 , void * V_94 ,
struct V_95 * V_50 )
{
int V_96 ;
switch ( V_93 ) {
case V_8 :
F_55 ( L_24 ) ;
F_5 ( & V_50 -> V_29 ) ;
V_96 = V_50 -> V_96 ;
F_7 ( & V_50 -> V_29 ) ;
* ( T_2 * ) V_94 = F_38 ( V_96 ) ;
return V_14 ;
case V_97 :
return V_14 ;
default:
return V_98 ;
}
}
static int F_73 ( struct V_92 * V_7 , int V_93 , void * V_94 ,
struct V_95 * V_50 )
{
switch ( V_93 ) {
case V_97 :
F_55 ( L_25 ) ;
F_5 ( & V_50 -> V_29 ) ;
V_50 -> V_96 = V_99 ;
F_7 ( & V_50 -> V_29 ) ;
return V_14 ;
default:
return V_98 ;
}
}
static int F_74 ( struct V_92 * V_7 , int V_93 , void * V_94 ,
struct V_95 * V_50 )
{
struct V_100 * V_101 = V_94 ;
switch ( V_93 ) {
case V_79 :
F_5 ( & V_50 -> V_29 ) ;
if ( V_50 -> V_96 != V_102 &&
V_50 -> V_96 != V_99 ) {
F_7 ( & V_50 -> V_29 ) ;
F_37 ( L_26 ) ;
return V_103 ;
}
V_50 -> V_96 = V_104 ;
F_7 ( & V_50 -> V_29 ) ;
V_50 -> V_105 = F_47 ( V_101 ) ;
V_50 -> V_106 = false ;
F_55 ( L_27 ,
V_50 -> V_105 ) ;
F_75 ( V_107 , & V_50 -> V_91 ) ;
return V_14 ;
case V_108 :
F_55 ( L_28 ) ;
F_5 ( & V_50 -> V_29 ) ;
F_54 ( V_50 -> V_105 , V_101 ) ;
F_7 ( & V_50 -> V_29 ) ;
return V_14 ;
default:
return V_98 ;
}
}
static int F_76 ( struct V_92 * V_7 , int V_93 , void * V_94 ,
struct V_95 * V_50 )
{
switch ( V_93 ) {
case V_97 :
F_5 ( & V_50 -> V_29 ) ;
if ( V_50 -> V_96 != V_102 ) {
F_7 ( & V_50 -> V_29 ) ;
F_55 ( L_29 ) ;
return V_103 ;
}
V_50 -> V_96 = V_104 ;
F_7 ( & V_50 -> V_29 ) ;
V_50 -> V_106 = true ;
F_55 ( L_30 ) ;
F_75 ( V_107 , & V_50 -> V_91 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_98 ;
}
}
static int F_77 ( struct V_92 * V_7 ,
int V_93 , void * V_94 , struct V_95 * V_50 )
{
switch ( V_93 ) {
case V_97 :
F_55 ( L_31 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_98 ;
}
}
static void F_78 ( struct V_92 * V_7 , struct V_109 * V_110 ,
int V_93 , int V_111 , int V_112 , int V_10 ,
unsigned long long V_77 , void * V_94 , T_4 V_75 ,
void * V_113 )
{
struct V_95 * V_50 = V_113 ;
struct V_15 * V_20 = V_50 -> V_28 -> V_20 ;
int V_114 , V_115 , V_116 ;
F_5 ( & V_20 -> V_29 ) ;
V_114 = V_20 -> V_10 ;
V_115 = V_20 -> V_69 ;
F_7 ( & V_20 -> V_29 ) ;
if ( V_10 != V_114 ) {
F_37 ( L_32 ) ;
V_116 = V_98 ;
goto V_117;
}
if ( V_112 != V_115 ) {
F_37 ( L_33 ,
V_112 , V_115 ) ;
V_116 = V_98 ;
goto V_117;
}
V_77 -= V_50 -> V_76 . V_77 ;
if ( V_77 == 0x00 && V_75 == 4 ) {
V_116 = F_72 ( V_7 , V_93 , V_94 , V_50 ) ;
} else if ( V_77 == 0x04 && V_75 == 4 ) {
V_116 = F_73 ( V_7 , V_93 , V_94 , V_50 ) ;
} else if ( V_77 == 0x08 && V_75 == 8 ) {
V_116 = F_74 ( V_7 , V_93 , V_94 , V_50 ) ;
} else if ( V_77 == 0x10 && V_75 == 4 ) {
V_116 = F_76 ( V_7 , V_93 , V_94 , V_50 ) ;
} else if ( V_77 == 0x14 && V_75 == 4 ) {
V_116 = F_77 ( V_7 , V_93 ,
V_94 , V_50 ) ;
} else {
V_116 = V_118 ;
}
V_117:
F_79 ( V_7 , V_110 , V_116 ) ;
}
static void F_80 ( struct V_90 * V_91 )
{
struct V_44 * V_3 =
F_70 ( V_91 , struct V_44 , V_91 ) ;
F_55 ( L_34 ,
V_3 -> V_105 ,
F_47 ( & V_3 -> V_57 . V_119 ) ,
F_47 ( & V_3 -> V_57 . V_120 ) ,
F_3 ( V_3 -> V_57 . V_58 ) ) ;
if ( V_3 -> V_105 >> 32 )
F_55 ( L_35 ) ;
switch ( F_81 ( F_3 ( V_3 -> V_57 . V_58 ) ) ) {
case 0 :
F_82 ( V_3 ) ;
return;
case 1 :
case 2 :
V_3 -> V_59 . V_59 |= F_38 (
F_39 (
V_60 ) |
F_83 ( 0 ) |
F_84 ( 1 ) |
F_40 (
V_82 ) ) ;
F_85 ( V_3 ) ;
return;
case 3 :
V_3 -> V_59 . V_59 |= F_38 (
F_39 (
V_60 ) |
F_83 ( 0 ) |
F_84 ( 1 ) |
F_40 (
V_121 ) ) ;
F_85 ( V_3 ) ;
return;
default:
F_86 () ;
}
}
static inline bool F_87 ( struct V_95 * V_50 )
{
bool V_122 ;
F_5 ( & V_50 -> V_29 ) ;
V_122 = ( V_50 -> V_96 == V_104 ) ;
F_7 ( & V_50 -> V_29 ) ;
return V_122 ;
}
static struct V_44 * F_88 ( struct V_15 * V_20 ,
struct V_92 * V_7 , T_1 V_119 )
{
struct V_18 * V_19 = V_20 -> V_19 ;
struct V_44 * V_3 ;
int V_123 ;
V_123 = F_89 ( & V_19 -> V_124 , V_125 ) ;
if ( V_123 < 0 )
return F_18 ( - V_40 ) ;
V_3 = & ( (struct V_44 * ) V_19 -> V_126 ) [ V_123 ] ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_127 . V_128 = V_123 ;
V_3 -> V_127 . V_123 = V_119 ;
return V_3 ;
}
static void F_90 ( struct V_90 * V_91 )
{
struct V_95 * V_50 =
F_70 ( V_91 , struct V_95 , V_91 ) ;
struct V_15 * V_20 = V_50 -> V_28 -> V_20 ;
struct V_44 * V_3 ;
int V_4 ;
bool V_106 = V_50 -> V_106 ;
T_1 V_119 = V_50 -> V_105 ;
while ( V_119 && F_87 ( V_50 ) ) {
V_3 = F_88 ( V_20 , V_20 -> V_7 , V_119 ) ;
if ( F_23 ( V_3 ) ) {
F_5 ( & V_50 -> V_29 ) ;
V_50 -> V_96 = V_129 ;
F_7 ( & V_50 -> V_29 ) ;
return;
}
V_3 -> V_28 = V_50 -> V_28 ;
V_3 -> V_105 = V_119 ;
V_3 -> V_59 . V_59 = F_38 ( F_91 (
V_3 -> V_105 >> 32 ) ) ;
V_3 -> V_59 . V_130 = F_38 (
V_3 -> V_105 & 0xfffffffc ) ;
V_4 = F_2 ( V_20 -> V_7 , V_108 ,
V_20 -> V_69 , V_20 -> V_10 , V_20 -> V_11 ,
V_3 -> V_105 , & V_3 -> V_57 , sizeof( V_3 -> V_57 ) ) ;
if ( V_4 != V_14 ) {
F_55 ( L_36 , V_4 ) ;
V_3 -> V_59 . V_59 |= F_38 (
F_92 (
V_131 ) |
F_39 (
V_62 ) |
F_83 ( 1 ) |
F_84 ( 1 ) |
F_40 (
V_63 ) ) ;
F_5 ( & V_50 -> V_29 ) ;
V_50 -> V_96 = V_129 ;
F_7 ( & V_50 -> V_29 ) ;
F_85 ( V_3 ) ;
return;
}
if ( F_3 ( V_3 -> V_57 . V_119 . V_5 ) & 0x80000000 ) {
V_119 = 0 ;
V_3 -> V_59 . V_59 |= F_38 ( F_92 (
V_131 ) ) ;
} else {
V_119 = F_47 ( & V_3 -> V_57 . V_119 ) ;
V_3 -> V_59 . V_59 |= F_38 ( F_92 (
V_132 ) ) ;
}
if ( F_87 ( V_50 ) && ! V_106 ) {
F_93 ( & V_3 -> V_91 , F_80 ) ;
F_75 ( V_107 , & V_3 -> V_91 ) ;
} else {
F_94 ( V_3 ) ;
}
F_5 ( & V_50 -> V_29 ) ;
V_106 = V_50 -> V_106 = false ;
if ( V_119 )
V_50 -> V_105 = V_119 ;
else
V_50 -> V_96 = V_102 ;
F_7 ( & V_50 -> V_29 ) ;
} ;
}
static struct V_95 * F_49 (
struct V_25 * V_28 )
{
struct V_95 * V_50 ;
int V_4 ;
V_50 = F_16 ( sizeof( * V_50 ) , V_39 ) ;
if ( ! V_50 )
return F_18 ( - V_40 ) ;
F_19 ( & V_50 -> V_29 ) ;
V_50 -> V_76 . V_75 = 0x20 ;
V_50 -> V_76 . V_133 = F_78 ;
V_50 -> V_76 . V_113 = V_50 ;
V_50 -> V_28 = V_28 ;
V_50 -> V_96 = V_99 ;
F_93 ( & V_50 -> V_91 , F_90 ) ;
V_50 -> V_105 = 0 ;
V_50 -> V_106 = false ;
V_4 = F_95 ( & V_50 -> V_76 ,
& V_134 ) ;
if ( V_4 < 0 ) {
F_25 ( V_50 ) ;
return F_18 ( V_4 ) ;
}
return V_50 ;
}
static void F_33 ( struct V_95 * V_50 )
{
F_96 ( & V_50 -> V_76 ) ;
F_97 ( & V_50 -> V_91 ) ;
F_25 ( V_50 ) ;
}
static int F_2 ( struct V_92 * V_7 , int V_93 , int V_135 ,
int V_10 , int V_11 , unsigned long long V_77 ,
void * V_136 , T_4 V_75 )
{
int V_137 , V_4 , V_138 ;
for ( V_137 = 1 ; V_137 <= 5 ; V_137 ++ ) {
V_4 = F_98 ( V_7 , V_93 , V_135 ,
V_10 , V_11 , V_77 , V_136 , V_75 ) ;
switch ( V_4 ) {
case V_14 :
case V_98 :
case V_118 :
case V_139 :
return V_4 ;
default:
V_138 = 5 * V_137 * V_137 ;
F_99 ( V_138 , V_138 * 2 ) ;
}
}
return V_4 ;
}
static int F_100 ( struct V_44 * V_3 ,
int V_93 , unsigned long long V_77 , void * V_136 ,
T_4 V_75 )
{
struct V_25 * V_28 = V_3 -> V_28 ;
struct V_15 * V_20 = V_28 -> V_20 ;
struct V_92 * V_7 ;
int V_69 , V_10 , V_11 , V_4 ;
F_5 ( & V_20 -> V_29 ) ;
V_7 = F_43 ( V_20 -> V_7 ) ;
V_69 = V_20 -> V_69 ;
V_10 = V_20 -> V_10 ;
V_11 = V_20 -> V_11 ;
F_7 ( & V_20 -> V_29 ) ;
V_4 = F_2 ( V_7 , V_93 , V_69 , V_10 , V_11 ,
V_77 , V_136 , V_75 ) ;
F_31 ( V_7 ) ;
return V_4 ;
}
static int F_101 ( struct V_44 * V_3 )
{
int V_4 , V_140 , V_141 ;
V_140 = F_102 ( V_3 -> V_57 . V_142 ) ;
V_3 -> V_143 = F_16 ( V_140 , V_39 ) ;
if ( ! V_3 -> V_143 )
return - V_40 ;
memcpy ( V_3 -> V_143 , V_3 -> V_57 . V_142 ,
F_103 ( int , V_140 , sizeof( V_3 -> V_57 . V_142 ) ) ) ;
if ( V_140 > sizeof( V_3 -> V_57 . V_142 ) ) {
F_55 ( L_37 ) ;
V_141 = V_140 - sizeof( V_3 -> V_57 . V_142 ) ;
V_4 = F_100 ( V_3 ,
V_108 ,
V_3 -> V_105 + sizeof( V_3 -> V_57 ) ,
V_3 -> V_143 + sizeof( V_3 -> V_57 . V_142 ) ,
V_141 ) ;
if ( V_4 != V_14 )
return - V_144 ;
}
return 0 ;
}
static int F_104 ( struct V_44 * V_3 )
{
int V_145 , V_4 ;
struct V_146 * V_147 ;
if ( ! F_105 ( F_3 ( V_3 -> V_57 . V_58 ) ) )
return 0 ;
V_145 = F_106 ( F_3 ( V_3 -> V_57 . V_58 ) ) *
sizeof( struct V_146 ) ;
V_147 = F_16 ( V_145 , V_39 ) ;
if ( ! V_147 )
return - V_40 ;
V_4 = F_100 ( V_3 , V_108 ,
F_47 ( & V_3 -> V_57 . V_120 ) ,
V_147 , V_145 ) ;
if ( V_4 != V_14 ) {
F_25 ( V_147 ) ;
return - V_144 ;
}
V_3 -> V_147 = V_147 ;
return 0 ;
}
static void F_107 ( struct V_44 * V_3 ,
T_3 * V_148 , enum V_149 * V_150 )
{
int V_151 , V_152 , V_153 ;
V_151 = F_106 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
V_152 = F_108 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
if ( ! V_151 ) {
* V_148 = 0 ;
* V_150 = V_154 ;
return;
}
* V_150 = V_152 ? V_155 : V_156 ;
if ( V_3 -> V_147 ) {
* V_148 = 0 ;
for ( V_153 = 0 ; V_153 < V_151 ; V_153 ++ ) {
* V_148 += F_109 (
V_3 -> V_147 [ V_153 ] . V_157 ) ;
}
} else {
* V_148 = V_151 ;
}
}
static void F_82 ( struct V_44 * V_3 )
{
struct V_25 * V_28 = V_3 -> V_28 ;
struct V_15 * V_20 = V_28 -> V_20 ;
int V_4 , V_27 ;
T_3 V_158 ;
enum V_149 V_150 ;
V_4 = F_101 ( V_3 ) ;
if ( V_4 ) {
F_55 ( L_38 , V_4 ) ;
goto V_34;
}
V_4 = F_104 ( V_3 ) ;
if ( V_4 ) {
F_55 ( L_39 ,
V_4 ) ;
goto V_34;
}
V_27 = V_3 -> V_28 -> V_30 ;
F_107 ( V_3 , & V_158 , & V_150 ) ;
F_55 ( L_40 ,
V_3 -> V_105 , V_27 , V_158 , V_150 ) ;
V_3 -> V_127 . V_123 = V_3 -> V_105 ;
if ( F_110 ( & V_3 -> V_127 , V_20 -> V_19 , V_3 -> V_143 ,
V_3 -> V_159 , V_27 , V_158 ,
V_160 , V_150 , V_161 ) )
goto V_34;
return;
V_34:
V_3 -> V_59 . V_59 |= F_38 (
F_39 ( V_62 ) |
F_83 ( 0 ) |
F_84 ( 1 ) |
F_40 ( V_63 ) ) ;
F_85 ( V_3 ) ;
}
static int F_111 ( struct V_44 * V_3 )
{
struct V_15 * V_20 = V_3 -> V_28 -> V_20 ;
int V_93 , V_162 , V_163 , V_164 , V_11 , V_69 ,
V_10 , V_165 , V_75 , V_166 ,
V_116 = V_14 ;
struct V_146 * V_167 ;
unsigned long long V_77 ;
struct V_92 * V_7 ;
struct V_168 V_169 ;
if ( V_3 -> V_127 . V_170 == V_155 ) {
V_93 = V_79 ;
V_162 = V_171 ;
} else {
V_93 = V_108 ;
V_162 = V_172 ;
}
V_163 = 4 << F_112 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
V_11 = F_113 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
V_164 = F_114 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
if ( V_164 ) {
F_17 ( L_41 ) ;
V_164 = 0x100 << V_164 ;
}
F_5 ( & V_20 -> V_29 ) ;
V_7 = F_43 ( V_20 -> V_7 ) ;
V_69 = V_20 -> V_69 ;
V_10 = V_20 -> V_10 ;
F_7 ( & V_20 -> V_29 ) ;
if ( V_3 -> V_147 ) {
V_167 = V_3 -> V_147 ;
V_165 = F_106 ( F_3 ( V_3 -> V_57 . V_58 ) ) ;
V_77 = 0 ;
V_75 = 0 ;
} else {
V_167 = NULL ;
V_165 = 0 ;
V_77 = F_47 ( & V_3 -> V_57 . V_120 ) ;
V_75 = V_3 -> V_127 . V_158 ;
}
F_115 ( & V_169 , V_3 -> V_127 . V_173 , V_3 -> V_127 . V_174 ,
V_162 ) ;
while ( V_75 || V_165 ) {
if ( ! V_75 ) {
V_77 = ( T_1 ) F_109 ( V_167 -> V_175 ) << 32 |
F_3 ( V_167 -> V_176 ) ;
V_75 = F_109 ( V_167 -> V_157 ) ;
V_167 ++ ;
V_165 -- ;
}
F_116 ( & V_169 ) ;
V_166 = F_117 ( V_75 , V_163 , ( int ) V_169 . V_75 ) ;
V_116 = F_2 ( V_7 , V_93 , V_69 ,
V_10 , V_11 ,
V_77 , V_169 . V_177 , V_166 ) ;
if ( V_116 != V_14 )
break;
V_75 -= V_166 ;
V_77 += V_166 ;
V_169 . V_178 = V_166 ;
}
F_118 ( & V_169 ) ;
F_31 ( V_7 ) ;
if ( V_116 == V_14 ) {
F_119 ( V_75 != 0 ) ;
return 0 ;
} else {
return - V_144 ;
}
}
static int F_85 ( struct V_44 * V_3 )
{
int V_179 , V_4 = 0 , V_75 ;
struct V_25 * V_28 = V_3 -> V_28 ;
V_75 = ( ( ( F_3 ( V_3 -> V_59 . V_59 ) >> 24 ) & 0x07 ) + 1 ) * 4 ;
V_179 = F_100 ( V_3 , V_79 ,
V_28 -> V_73 , & V_3 -> V_59 , V_75 ) ;
if ( V_179 != V_14 ) {
F_55 ( L_42 , V_179 ) ;
V_4 = - V_144 ;
goto V_180;
}
F_55 ( L_43 ,
V_3 -> V_105 ) ;
V_180:
F_120 ( & V_3 -> V_127 ) ;
return V_4 ;
}
static void F_121 ( struct V_44 * V_3 )
{
struct V_127 * V_127 = & V_3 -> V_127 ;
T_5 * V_181 = V_3 -> V_159 ;
T_5 * V_59 = V_3 -> V_59 . V_94 ;
F_119 ( V_127 -> V_182 < 18 ) ;
switch ( V_181 [ 0 ] & 0x7f ) {
case 0x70 :
V_59 [ 0 ] = 0 << 6 ;
break;
case 0x71 :
V_59 [ 0 ] = 1 << 6 ;
break;
case 0x72 :
case 0x73 :
default:
F_17 ( L_44 ,
V_181 [ 0 ] ) ;
V_3 -> V_59 . V_59 |= F_38 (
F_39 ( V_60 ) |
F_83 ( 0 ) |
F_84 ( 1 ) |
F_40 ( V_183 ) ) ;
return;
}
V_59 [ 0 ] |= V_127 -> V_184 & 0x3f ;
V_59 [ 1 ] =
( V_181 [ 0 ] & 0x80 ) |
( ( V_181 [ 2 ] & 0xe0 ) >> 1 ) |
( V_181 [ 2 ] & 0x0f ) ;
V_59 [ 2 ] = V_127 -> V_185 ;
V_59 [ 3 ] = V_127 -> V_186 ;
V_59 [ 4 ] = V_181 [ 3 ] ;
V_59 [ 5 ] = V_181 [ 4 ] ;
V_59 [ 6 ] = V_181 [ 5 ] ;
V_59 [ 7 ] = V_181 [ 6 ] ;
V_59 [ 8 ] = V_181 [ 8 ] ;
V_59 [ 9 ] = V_181 [ 9 ] ;
V_59 [ 10 ] = V_181 [ 10 ] ;
V_59 [ 11 ] = V_181 [ 11 ] ;
V_59 [ 12 ] = V_181 [ 14 ] ;
V_59 [ 13 ] = V_181 [ 15 ] ;
V_59 [ 14 ] = V_181 [ 16 ] ;
V_59 [ 15 ] = V_181 [ 17 ] ;
V_3 -> V_59 . V_59 |= F_38 (
F_39 ( V_60 ) |
F_83 ( 0 ) |
F_84 ( 5 ) |
F_40 ( V_81 ) ) ;
}
static int F_122 ( struct V_44 * V_3 )
{
struct V_127 * V_127 = & V_3 -> V_127 ;
if ( V_127 -> V_182 ) {
F_121 ( V_3 ) ;
} else {
V_3 -> V_59 . V_59 |= F_38 (
F_39 ( V_60 ) |
F_83 ( 0 ) |
F_84 ( 1 ) |
F_40 ( V_81 ) ) ;
}
return F_85 ( V_3 ) ;
}
static void F_94 ( struct V_44 * V_3 )
{
struct V_127 * V_127 = & V_3 -> V_127 ;
struct V_18 * V_19 = V_127 -> V_19 ;
F_25 ( V_3 -> V_147 ) ;
F_25 ( V_3 -> V_143 ) ;
F_123 ( & V_19 -> V_124 , V_127 -> V_128 ) ;
}
static void F_124 ( struct V_90 * V_91 )
{
struct V_49 * V_50 =
F_70 ( V_91 , struct V_49 , V_91 ) ;
struct V_2 * V_3 = V_50 -> V_110 ;
int V_4 ;
int V_187 = 0 ;
V_4 = F_2 ( V_3 -> V_7 , V_108 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
V_50 -> V_188 , & V_3 -> V_57 , sizeof( V_3 -> V_57 ) ) ;
if ( V_4 != V_14 ) {
F_55 ( L_45 , V_4 ) ;
goto V_117;
}
F_55 ( L_46 ,
F_47 ( & V_3 -> V_57 . V_189 ) ,
F_47 ( & V_3 -> V_57 . V_80 ) ,
F_3 ( V_3 -> V_57 . V_58 ) , F_3 ( V_3 -> V_57 . V_75 ) ,
F_47 ( & V_3 -> V_57 . V_74 ) ) ;
if ( ! F_125 ( F_3 ( V_3 -> V_57 . V_58 ) ) ||
F_81 ( F_3 ( V_3 -> V_57 . V_58 ) ) != 0 ) {
F_17 ( L_47 ) ;
goto V_117;
}
switch ( F_126 ( F_3 ( V_3 -> V_57 . V_58 ) ) ) {
case V_190 :
F_35 ( V_50 , V_3 , & V_187 ) ;
break;
case V_191 :
F_56 ( V_50 , V_3 ,
& V_187 ) ;
break;
case V_192 :
F_57 ( V_50 , V_3 , & V_187 ) ;
break;
case V_193 :
F_37 ( L_48 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_82 ) ) ;
break;
case V_194 :
F_59 ( V_50 , V_3 , & V_187 ) ;
break;
case V_195 :
F_37 ( L_49 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_82 ) ) ;
break;
case V_196 :
F_37 ( L_50 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_82 ) ) ;
break;
case V_197 :
F_37 ( L_51 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_82 ) ) ;
break;
case V_198 :
F_37 ( L_52 ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_82 ) ) ;
break;
default:
F_37 ( L_53 ,
F_126 ( F_3 ( V_3 -> V_57 . V_58 ) ) ) ;
V_3 -> V_59 . V_59 = F_38 (
F_39 ( V_60 ) |
F_40 ( V_82 ) ) ;
break;
}
V_3 -> V_59 . V_59 |= F_38 (
F_92 ( 1 ) |
F_84 ( F_127 ( V_187 , 4 ) + 1 ) |
F_91 ( V_50 -> V_188 >> 32 ) ) ;
V_3 -> V_59 . V_130 = F_38 ( V_50 -> V_188 ) ;
V_4 = F_2 ( V_3 -> V_7 , V_79 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
F_47 ( & V_3 -> V_57 . V_74 ) ,
& V_3 -> V_59 , 8 + V_187 ) ;
if ( V_4 != V_14 ) {
F_55 ( L_54 , V_4 ) ;
goto V_117;
}
V_117:
F_31 ( V_3 -> V_7 ) ;
F_25 ( V_3 ) ;
F_5 ( & V_50 -> V_29 ) ;
V_50 -> V_96 = V_199 ;
F_7 ( & V_50 -> V_29 ) ;
}
static void F_128 ( struct V_92 * V_7 ,
struct V_109 * V_110 , int V_93 , int V_111 , int V_112 ,
int V_10 , unsigned long long V_77 , void * V_94 , T_4 V_75 ,
void * V_113 )
{
struct V_49 * V_50 = V_113 ;
struct V_100 * V_101 = V_94 ;
int V_116 = V_118 ;
if ( ! V_50 -> V_53 -> V_200 )
goto V_117;
if ( ( V_77 != V_50 -> V_76 . V_77 ) || ( V_75 != 8 ) )
goto V_117;
if ( V_93 == V_79 ) {
struct V_2 * V_3 ;
int V_201 ;
F_5 ( & V_50 -> V_29 ) ;
V_201 = V_50 -> V_96 ;
V_50 -> V_96 = V_202 ;
F_7 ( & V_50 -> V_29 ) ;
if ( V_201 == V_202 ) {
F_37 ( L_55 ) ;
V_116 = V_103 ;
goto V_117;
}
V_3 = F_51 ( sizeof( * V_3 ) , V_203 ) ;
if ( ! V_3 ) {
V_116 = V_103 ;
goto V_117;
}
V_3 -> V_7 = F_43 ( V_7 ) ;
V_3 -> V_10 = V_10 ;
V_3 -> V_9 = V_112 ;
V_3 -> V_11 = F_129 ( V_110 ) ;
V_50 -> V_188 = F_47 ( V_101 ) ;
V_50 -> V_110 = V_3 ;
F_75 ( V_107 , & V_50 -> V_91 ) ;
V_116 = V_14 ;
} else if ( V_93 == V_108 ) {
F_54 ( V_50 -> V_188 , V_101 ) ;
V_116 = V_14 ;
} else {
V_116 = V_98 ;
}
V_117:
F_79 ( V_7 , V_110 , V_116 ) ;
}
static struct V_49 * F_130 (
struct V_52 * V_53 )
{
int V_4 ;
struct V_49 * V_50 ;
V_50 = F_16 ( sizeof( * V_50 ) , V_39 ) ;
if ( ! V_50 )
return F_18 ( - V_40 ) ;
F_19 ( & V_50 -> V_29 ) ;
V_50 -> V_53 = V_53 ;
V_50 -> V_76 . V_75 = 0x08 ;
V_50 -> V_76 . V_133 = F_128 ;
V_50 -> V_76 . V_113 = V_50 ;
V_50 -> V_96 = V_199 ;
F_93 ( & V_50 -> V_91 , F_124 ) ;
V_50 -> V_188 = 0 ;
V_50 -> V_110 = NULL ;
V_4 = F_95 ( & V_50 -> V_76 ,
& V_134 ) ;
if ( V_4 < 0 ) {
F_25 ( V_50 ) ;
return F_18 ( V_4 ) ;
}
return V_50 ;
}
static void F_131 ( struct V_49 * V_50 )
{
F_96 ( & V_50 -> V_76 ) ;
F_97 ( & V_50 -> V_91 ) ;
F_25 ( V_50 ) ;
}
static int F_132 ( struct V_35 * V_22 )
{
return 1 ;
}
static int F_133 ( struct V_35 * V_22 )
{
return 0 ;
}
static char * F_134 ( void )
{
return L_56 ;
}
static char * F_135 ( struct V_35 * V_22 )
{
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
return & V_53 -> V_204 [ 0 ] ;
}
static T_6 F_136 ( struct V_35 * V_22 )
{
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
return V_17 -> V_205 ;
}
static T_3 F_137 ( struct V_35 * V_22 )
{
return 1 ;
}
static void F_138 ( struct V_127 * V_127 )
{
struct V_44 * V_3 = F_70 ( V_127 ,
struct V_44 , V_127 ) ;
F_94 ( V_3 ) ;
}
static T_3 F_139 ( struct V_18 * V_19 )
{
return 0 ;
}
static int F_140 ( struct V_127 * V_127 )
{
struct V_44 * V_3 = F_70 ( V_127 ,
struct V_44 , V_127 ) ;
int V_4 ;
V_4 = F_111 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_59 . V_59 |= F_38 (
F_39 (
V_62 ) |
F_83 ( 0 ) |
F_84 ( 1 ) |
F_40 (
V_63 ) ) ;
F_85 ( V_3 ) ;
return V_4 ;
}
F_141 ( V_127 ) ;
return 0 ;
}
static int F_142 ( struct V_127 * V_127 )
{
return 0 ;
}
static void F_143 ( struct V_206 * V_207 )
{
return;
}
static int F_144 ( struct V_127 * V_127 )
{
return 0 ;
}
static int F_145 ( struct V_127 * V_127 )
{
struct V_44 * V_3 = F_70 ( V_127 ,
struct V_44 , V_127 ) ;
int V_4 ;
V_4 = F_111 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_59 . V_59 |= F_38 (
F_39 ( V_62 ) |
F_83 ( 0 ) |
F_84 ( 1 ) |
F_40 ( V_63 ) ) ;
F_85 ( V_3 ) ;
return V_4 ;
}
return F_122 ( V_3 ) ;
}
static int F_146 ( struct V_127 * V_127 )
{
struct V_44 * V_3 = F_70 ( V_127 ,
struct V_44 , V_127 ) ;
return F_122 ( V_3 ) ;
}
static void F_147 ( struct V_127 * V_127 )
{
}
static void F_148 ( struct V_127 * V_127 )
{
return;
}
static int F_149 ( struct V_127 * V_127 )
{
struct V_44 * V_3 = F_70 ( V_127 ,
struct V_44 , V_127 ) ;
return F_150 ( & V_3 -> V_127 , 0 ) ;
}
static int F_151 ( struct V_35 * V_17 )
{
struct V_36 * V_208 ;
int V_32 = 0 ;
F_12 () ;
F_13 (lun, &tpg->tpg_lun_hlist, link)
V_32 ++ ;
F_14 () ;
return V_32 ;
}
static int F_152 ( struct V_52 * V_53 )
{
struct V_36 * V_208 ;
int V_209 , V_210 , V_153 = 0 , V_211 , V_4 ;
T_3 * V_94 ;
if ( V_53 -> V_212 . V_94 ) {
F_153 ( & V_53 -> V_212 ) ;
F_25 ( V_53 -> V_212 . V_94 ) ;
V_53 -> V_212 . V_94 = NULL ;
}
if ( ! V_53 -> V_200 || ! V_53 -> V_17 )
return 0 ;
V_209 = F_151 ( & V_53 -> V_17 -> V_22 ) ;
V_210 = F_154 ( V_213 ) + 4 + V_209 ;
if ( V_53 -> V_214 != - 1 )
V_210 ++ ;
V_94 = F_155 ( ( V_210 + 4 ) , sizeof( T_3 ) , V_39 ) ;
if ( ! V_94 )
return - V_40 ;
V_94 [ V_153 ++ ] = V_210 << 16 ;
if ( V_53 -> V_214 != - 1 )
V_94 [ V_153 ++ ] = ( V_215 << 24 ) | V_53 -> V_214 ;
memcpy ( & V_94 [ V_153 ] , V_213 ,
sizeof( V_213 ) ) ;
V_153 += F_154 ( V_213 ) ;
V_211 = ( V_53 -> V_216 -> V_76 . V_77 - V_12 ) / 4 ;
V_94 [ V_153 ++ ] = 0x54000000 | ( V_211 & 0x00ffffff ) ;
V_94 [ V_153 ++ ] = 0x3a000000 |
( ( ( V_53 -> V_217 * 2 ) << 8 ) & 0xff00 ) |
V_218 ;
V_94 [ V_153 ++ ] = 0x3d000000 | ( V_53 -> V_72 & 0xffff ) ;
V_94 [ V_153 ++ ] = 0x8d000000 | ( V_209 + 1 ) ;
F_12 () ;
F_13 (lun, &tport->tpg->se_tpg.tpg_lun_hlist, link) {
struct V_219 * V_220 ;
int type ;
V_220 = F_156 ( V_208 -> V_221 ) ;
type = V_220 -> V_222 -> V_223 ( V_220 ) ;
V_94 [ V_153 ++ ] = 0x14000000 |
( ( type << 16 ) & 0x1f0000 ) |
( V_208 -> V_27 & 0xffff ) ;
}
F_14 () ;
V_94 [ V_153 ++ ] = 2 << 16 ;
V_94 [ V_153 ++ ] = V_53 -> V_1 >> 32 ;
V_94 [ V_153 ++ ] = V_53 -> V_1 ;
V_53 -> V_212 . V_75 = V_153 ;
V_53 -> V_212 . V_224 = ( V_225 | V_226 ) << 24 ;
V_53 -> V_212 . V_94 = V_94 ;
V_4 = F_157 ( & V_53 -> V_212 ) ;
if ( V_4 < 0 ) {
F_25 ( V_53 -> V_212 . V_94 ) ;
V_53 -> V_212 . V_94 = NULL ;
}
return V_4 ;
}
static T_7 F_158 ( const char * V_227 , T_1 * V_228 )
{
const char * V_229 ;
char V_230 , V_231 ;
int V_232 = 0 , V_34 ;
* V_228 = 0 ;
for ( V_229 = V_227 ; V_229 < & V_227 [ V_233 - 1 ] ; V_229 ++ ) {
V_230 = * V_229 ;
if ( V_230 == '\n' && V_229 [ 1 ] == '\0' )
continue;
if ( V_230 == '\0' ) {
V_34 = 2 ;
if ( V_232 != 16 )
goto V_234;
return V_229 - V_227 ;
}
V_34 = 3 ;
if ( isdigit ( V_230 ) )
V_231 = V_230 - '0' ;
else if ( isxdigit ( V_230 ) )
V_231 = tolower ( V_230 ) - 'a' + 10 ;
else
goto V_234;
* V_228 = ( * V_228 << 4 ) | V_231 ;
V_232 ++ ;
}
V_34 = 4 ;
V_234:
F_159 ( V_235 L_57 ,
V_34 , V_229 - V_227 , V_232 ) ;
return - 1 ;
}
static T_7 F_160 ( char * V_236 , T_4 V_237 , T_1 V_228 )
{
return snprintf ( V_236 , V_237 , L_1 , V_228 ) ;
}
static int F_161 ( struct V_206 * V_238 , const char * V_227 )
{
T_1 V_1 = 0 ;
if ( F_158 ( V_227 , & V_1 ) < 0 )
return - V_239 ;
return 0 ;
}
static int F_162 (
struct V_35 * V_22 ,
struct V_36 * V_36 )
{
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
return F_152 ( V_17 -> V_53 ) ;
}
static void F_163 (
struct V_35 * V_22 ,
struct V_36 * V_36 )
{
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
int V_4 ;
if ( F_151 ( & V_17 -> V_22 ) == 0 )
V_53 -> V_200 = 0 ;
V_4 = F_152 ( V_53 ) ;
if ( V_4 < 0 )
F_17 ( L_58 ) ;
}
static struct V_35 * F_164 (
struct V_240 * V_228 ,
struct V_241 * V_242 ,
const char * V_227 )
{
struct V_52 * V_53 =
F_70 ( V_228 , struct V_52 , V_243 ) ;
struct V_16 * V_17 ;
unsigned long V_244 ;
int V_4 ;
if ( strstr ( V_227 , L_59 ) != V_227 )
return F_18 ( - V_239 ) ;
if ( F_165 ( V_227 + 5 , 10 , & V_244 ) || V_244 > V_245 )
return F_18 ( - V_239 ) ;
if ( V_53 -> V_17 ) {
F_17 ( L_60 ) ;
return F_18 ( - V_246 ) ;
}
V_17 = F_51 ( sizeof( * V_17 ) , V_39 ) ;
if ( ! V_17 ) {
F_17 ( L_61 ) ;
return F_18 ( - V_40 ) ;
}
V_17 -> V_53 = V_53 ;
V_17 -> V_205 = V_244 ;
V_53 -> V_17 = V_17 ;
V_53 -> V_200 = 0 ;
V_53 -> V_214 = - 1 ;
V_53 -> V_217 = 15 ;
V_53 -> V_72 = 5 ;
V_53 -> V_66 = 1 ;
V_53 -> V_216 = F_130 ( V_53 ) ;
if ( F_23 ( V_53 -> V_216 ) ) {
V_4 = F_24 ( V_53 -> V_216 ) ;
goto V_247;
}
V_4 = F_166 ( V_228 , & V_17 -> V_22 , V_248 ) ;
if ( V_4 < 0 )
goto V_249;
return & V_17 -> V_22 ;
V_249:
F_131 ( V_53 -> V_216 ) ;
V_247:
V_53 -> V_17 = NULL ;
F_25 ( V_17 ) ;
return F_18 ( V_4 ) ;
}
static void F_167 ( struct V_35 * V_22 )
{
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
F_168 ( V_22 ) ;
F_131 ( V_53 -> V_216 ) ;
V_53 -> V_17 = NULL ;
F_25 ( V_17 ) ;
}
static struct V_240 * F_169 (
struct V_250 * V_251 ,
struct V_241 * V_242 ,
const char * V_227 )
{
struct V_52 * V_53 ;
T_1 V_1 = 0 ;
if ( F_158 ( V_227 , & V_1 ) < 0 )
return F_18 ( - V_239 ) ;
V_53 = F_51 ( sizeof( * V_53 ) , V_39 ) ;
if ( ! V_53 ) {
F_17 ( L_62 ) ;
return F_18 ( - V_40 ) ;
}
V_53 -> V_1 = V_1 ;
F_160 ( V_53 -> V_204 , V_233 , V_1 ) ;
return & V_53 -> V_243 ;
}
static void F_170 ( struct V_240 * V_228 )
{
struct V_52 * V_53 =
F_70 ( V_228 , struct V_52 , V_243 ) ;
F_25 ( V_53 ) ;
}
static T_7 F_171 ( struct V_252 * V_253 , char * V_254 )
{
return sprintf ( V_254 , L_63 , V_255 ) ;
}
static T_7 F_172 ( struct V_252 * V_253 , char * V_254 )
{
struct V_35 * V_22 = F_173 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
if ( V_53 -> V_214 == - 1 )
return sprintf ( V_254 , L_64 ) ;
else
return sprintf ( V_254 , L_65 , V_53 -> V_214 ) ;
}
static T_7 F_174 ( struct V_252 * V_253 ,
const char * V_254 , T_4 V_32 )
{
struct V_35 * V_22 = F_173 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
unsigned long V_256 ;
if ( V_53 -> V_200 ) {
F_17 ( L_66 ) ;
return - V_246 ;
}
if ( strstr ( V_254 , L_67 ) == V_254 ) {
V_53 -> V_214 = - 1 ;
} else {
if ( F_165 ( V_254 , 16 , & V_256 ) < 0 )
return - V_239 ;
if ( V_256 > 0xffffff )
return - V_239 ;
V_53 -> V_214 = V_256 ;
}
return V_32 ;
}
static T_7 F_175 ( struct V_252 * V_253 , char * V_254 )
{
struct V_35 * V_22 = F_173 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
return sprintf ( V_254 , L_68 , V_53 -> V_200 ) ;
}
static T_7 F_176 ( struct V_252 * V_253 ,
const char * V_254 , T_4 V_32 )
{
struct V_35 * V_22 = F_173 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
unsigned long V_256 ;
int V_4 ;
if ( F_165 ( V_254 , 0 , & V_256 ) < 0 )
return - V_239 ;
if ( ( V_256 != 0 ) && ( V_256 != 1 ) )
return - V_239 ;
if ( V_53 -> V_200 == V_256 )
return V_32 ;
if ( V_256 ) {
if ( F_151 ( & V_17 -> V_22 ) == 0 ) {
F_17 ( L_69 ) ;
return - V_239 ;
}
} else {
F_5 ( & V_22 -> V_23 ) ;
if ( ! F_27 ( & V_22 -> V_257 ) ) {
F_7 ( & V_22 -> V_23 ) ;
return - V_246 ;
}
F_7 ( & V_22 -> V_23 ) ;
}
V_53 -> V_200 = V_256 ;
V_4 = F_152 ( V_53 ) ;
if ( V_4 < 0 ) {
F_17 ( L_70 ) ;
return V_4 ;
}
return V_32 ;
}
static T_7 F_177 ( struct V_252 * V_253 ,
char * V_254 )
{
struct V_35 * V_22 = F_178 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
return sprintf ( V_254 , L_68 , V_53 -> V_217 ) ;
}
static T_7 F_179 ( struct V_252 * V_253 ,
const char * V_254 , T_4 V_32 )
{
struct V_35 * V_22 = F_178 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
unsigned long V_256 ;
int V_4 ;
if ( F_165 ( V_254 , 0 , & V_256 ) < 0 )
return - V_239 ;
if ( ( V_256 < 1 ) || ( V_256 > 127 ) )
return - V_239 ;
if ( V_53 -> V_217 == V_256 )
return V_32 ;
V_53 -> V_217 = V_256 ;
V_4 = F_152 ( V_53 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_180 ( struct V_252 * V_253 ,
char * V_254 )
{
struct V_35 * V_22 = F_178 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
return sprintf ( V_254 , L_68 , V_53 -> V_72 ) ;
}
static T_7 F_181 ( struct V_252 * V_253 ,
const char * V_254 , T_4 V_32 )
{
struct V_35 * V_22 = F_178 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
unsigned long V_256 ;
int V_4 ;
if ( F_165 ( V_254 , 0 , & V_256 ) < 0 )
return - V_239 ;
if ( ( V_256 < 1 ) || ( V_256 > 32767 ) )
return - V_239 ;
if ( V_53 -> V_72 == V_256 )
return V_32 ;
V_53 -> V_72 = V_256 ;
V_4 = F_152 ( V_53 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_182 ( struct V_252 * V_253 ,
char * V_254 )
{
struct V_35 * V_22 = F_178 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
return sprintf ( V_254 , L_68 , V_53 -> V_66 ) ;
}
static T_7 F_183 ( struct V_252 * V_253 ,
const char * V_254 , T_4 V_32 )
{
struct V_35 * V_22 = F_178 ( V_253 ) ;
struct V_16 * V_17 = F_70 ( V_22 , struct V_16 , V_22 ) ;
struct V_52 * V_53 = V_17 -> V_53 ;
unsigned long V_256 ;
if ( F_165 ( V_254 , 0 , & V_256 ) < 0 )
return - V_239 ;
if ( ( V_256 < 1 ) || ( V_256 > 127 ) )
return - V_239 ;
V_53 -> V_66 = V_256 ;
return V_32 ;
}
static int T_8 F_184 ( void )
{
return F_185 ( & V_258 ) ;
}
static void T_9 F_186 ( void )
{
F_187 ( & V_258 ) ;
}
