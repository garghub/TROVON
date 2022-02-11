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
struct V_15 * V_26 , struct V_27 * V_28 )
{
struct V_25 * V_29 , * V_21 = NULL ;
F_5 ( & V_26 -> V_30 ) ;
F_6 (login, &session->login_list, link) {
if ( V_29 -> V_28 == V_28 )
V_21 = V_29 ;
}
F_7 ( & V_26 -> V_30 ) ;
return V_21 ;
}
static int F_9 (
struct V_16 * V_17 ,
struct V_27 * V_28 ,
int V_31 )
{
struct V_18 * V_19 ;
struct V_15 * V_20 ;
struct V_25 * V_29 ;
int V_32 = 0 ;
F_5 ( & V_17 -> V_22 . V_23 ) ;
F_6 (se_sess, &tpg->se_tpg.tpg_sess_list, sess_list) {
V_20 = V_19 -> V_24 ;
F_5 ( & V_20 -> V_30 ) ;
F_6 (login, &sess->login_list, link) {
if ( V_29 -> V_28 != V_28 )
continue;
if ( ! V_31 || V_29 -> V_31 )
V_32 ++ ;
}
F_7 ( & V_20 -> V_30 ) ;
}
F_7 ( & V_17 -> V_22 . V_23 ) ;
return V_32 ;
}
static struct V_25 * F_10 (
struct V_16 * V_17 , int V_33 )
{
struct V_18 * V_19 ;
struct V_15 * V_20 ;
struct V_25 * V_29 , * V_21 = NULL ;
F_5 ( & V_17 -> V_22 . V_23 ) ;
F_6 (se_sess, &tpg->se_tpg.tpg_sess_list, sess_list) {
V_20 = V_19 -> V_24 ;
F_5 ( & V_20 -> V_30 ) ;
F_6 (login, &sess->login_list, link) {
if ( V_29 -> V_33 == V_33 )
V_21 = V_29 ;
}
F_7 ( & V_20 -> V_30 ) ;
}
F_7 ( & V_17 -> V_22 . V_23 ) ;
return V_21 ;
}
static struct V_27 * F_11 ( struct V_16 * V_17 , int V_28 )
{
struct V_34 * V_22 = & V_17 -> V_22 ;
struct V_27 * V_27 ;
if ( V_28 >= V_35 )
return F_12 ( - V_36 ) ;
F_13 ( & V_22 -> V_37 ) ;
V_27 = V_22 -> V_38 [ V_28 ] ;
if ( V_27 -> V_39 != V_40 )
V_27 = F_12 ( - V_41 ) ;
F_14 ( & V_22 -> V_37 ) ;
return V_27 ;
}
static struct V_15 * F_15 (
struct V_16 * V_17 ,
T_1 V_1 )
{
struct V_15 * V_20 ;
int V_4 ;
char V_42 [ 17 ] ;
struct V_43 * V_44 ;
V_20 = F_16 ( sizeof( * V_20 ) , V_45 ) ;
if ( ! V_20 ) {
F_17 ( L_1 ) ;
return F_12 ( - V_46 ) ;
}
V_20 -> V_19 = F_18 ( V_47 ) ;
if ( F_19 ( V_20 -> V_19 ) ) {
F_17 ( L_2 ) ;
V_4 = F_20 ( V_20 -> V_19 ) ;
F_21 ( V_20 ) ;
return F_12 ( V_4 ) ;
}
snprintf ( V_42 , sizeof( V_42 ) , L_3 , V_1 ) ;
V_44 = F_22 ( & V_17 -> V_22 , V_42 ) ;
if ( ! V_44 ) {
F_23 ( L_4 , V_42 ) ;
F_24 ( V_20 -> V_19 ) ;
F_21 ( V_20 ) ;
return F_12 ( - V_48 ) ;
}
V_20 -> V_19 -> V_43 = V_44 ;
F_25 ( & V_20 -> V_30 ) ;
F_26 ( & V_20 -> V_49 ) ;
F_27 ( & V_20 -> V_50 , V_51 ) ;
V_20 -> V_1 = V_1 ;
F_28 ( & V_17 -> V_22 , V_44 , V_20 -> V_19 , V_20 ) ;
return V_20 ;
}
static void F_29 ( struct V_15 * V_20 , bool V_52 )
{
F_5 ( & V_20 -> V_30 ) ;
if ( ! F_30 ( & V_20 -> V_49 ) ) {
F_7 ( & V_20 -> V_30 ) ;
return;
}
F_7 ( & V_20 -> V_30 ) ;
if ( V_52 )
F_31 ( & V_20 -> V_50 ) ;
F_32 ( V_20 -> V_19 ) ;
F_33 ( V_20 -> V_19 ) ;
if ( V_20 -> V_7 )
F_34 ( V_20 -> V_7 ) ;
F_21 ( V_20 ) ;
}
static void F_35 ( struct V_25 * V_29 ,
bool V_52 )
{
struct V_15 * V_20 = V_29 -> V_20 ;
F_36 ( V_29 -> V_53 ) ;
if ( V_20 ) {
F_5 ( & V_20 -> V_30 ) ;
F_37 ( & V_29 -> V_54 ) ;
F_7 ( & V_20 -> V_30 ) ;
F_29 ( V_20 , V_52 ) ;
}
F_21 ( V_29 ) ;
}
static void F_38 (
struct V_55 * V_56 , struct V_2 * V_3 ,
int * V_57 )
{
struct V_58 * V_59 = V_56 -> V_59 ;
struct V_16 * V_17 = V_59 -> V_17 ;
struct V_27 * V_27 ;
int V_4 ;
T_1 V_1 ;
struct V_15 * V_20 ;
struct V_25 * V_29 ;
struct V_60 * V_61 ;
int V_62 ;
V_27 = F_11 ( V_17 ,
F_39 ( F_3 ( V_3 -> V_63 . V_64 ) ) ) ;
if ( F_19 ( V_27 ) ) {
F_40 ( L_5 ,
F_39 ( F_3 ( V_3 -> V_63 . V_64 ) ) ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_67 ) ) ;
return;
}
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_23 ( L_6 , V_4 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_68 ) |
F_43 ( V_69 ) ) ;
return;
}
F_40 ( L_7 ,
V_27 -> V_70 , V_1 ) ;
V_20 = F_4 ( V_17 , V_1 ) ;
if ( V_20 ) {
V_29 = F_8 ( V_20 , V_27 ) ;
if ( V_29 ) {
F_40 ( L_8 ) ;
goto V_71;
}
}
if ( F_44 ( F_3 ( V_3 -> V_63 . V_64 ) ) &&
F_9 ( V_17 , V_27 , 0 ) ) {
F_23 ( L_9 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_72 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 1 ) ) {
F_23 ( L_10 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_72 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 0 ) >=
V_59 -> V_73 ) {
F_23 ( L_11 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_74 ) ) ;
return;
}
if ( ! V_20 ) {
V_20 = F_15 ( V_17 , V_1 ) ;
if ( F_19 ( V_20 ) ) {
switch ( F_20 ( V_20 ) ) {
case - V_48 :
V_4 = V_72 ;
break;
default:
V_4 = V_74 ;
break;
}
V_3 -> V_65 . V_65 = F_41 (
F_42 (
V_66 ) |
F_43 ( V_4 ) ) ;
return;
}
V_20 -> V_75 = V_3 -> V_9 ;
V_20 -> V_7 = F_45 ( V_3 -> V_7 ) ;
V_20 -> V_10 = V_3 -> V_10 ;
V_20 -> V_11 = V_3 -> V_11 ;
F_46 ( & V_20 -> V_50 ,
V_76 ) ;
}
V_20 -> V_77 = F_47 (
1 << F_48 ( F_3 ( V_3 -> V_63 . V_64 ) ) ,
V_59 -> V_78 ) - 1 ;
V_29 = F_16 ( sizeof( * V_29 ) , V_45 ) ;
if ( ! V_29 ) {
F_17 ( L_12 ) ;
F_29 ( V_20 , true ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_74 ) ) ;
return;
}
V_29 -> V_20 = V_20 ;
V_29 -> V_28 = V_27 ;
V_29 -> V_79 = F_49 ( & V_3 -> V_63 . V_80 ) ;
V_29 -> V_31 = F_44 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
V_29 -> V_33 = F_50 ( & V_33 ) ;
V_29 -> V_53 = F_51 ( V_29 ) ;
if ( F_19 ( V_29 -> V_53 ) ) {
V_4 = F_20 ( V_29 -> V_53 ) ;
F_17 ( L_13 , V_4 ) ;
F_29 ( V_20 , true ) ;
F_21 ( V_29 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_74 ) ) ;
return;
}
F_5 ( & V_20 -> V_30 ) ;
F_52 ( & V_29 -> V_54 , & V_20 -> V_49 ) ;
F_7 ( & V_20 -> V_30 ) ;
V_71:
V_61 = F_53 ( sizeof( * V_61 ) , V_45 ) ;
if ( ! V_61 ) {
F_17 ( L_14 ) ;
F_35 ( V_29 , true ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_74 ) ) ;
return;
}
V_62 = F_54 (
F_55 ( F_3 ( V_3 -> V_63 . V_81 ) ) ,
12 , sizeof( * V_61 ) ) ;
V_61 -> V_64 = F_41 (
( ( V_62 & 0xffff ) << 16 ) |
( V_29 -> V_33 & 0xffff ) ) ;
V_61 -> V_77 = F_41 ( V_20 -> V_77 & 0xffff ) ;
F_56 ( V_29 -> V_53 -> V_82 . V_83 ,
& V_61 -> V_84 ) ;
V_4 = F_2 ( V_20 -> V_7 , V_85 ,
V_20 -> V_75 , V_20 -> V_10 , V_20 -> V_11 ,
F_49 ( & V_3 -> V_63 . V_86 ) , V_61 ,
V_62 ) ;
if ( V_4 != V_14 ) {
F_57 ( L_15 , V_4 ) ;
F_21 ( V_61 ) ;
F_35 ( V_29 , true ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_68 ) |
F_43 ( V_69 ) ) ;
return;
}
F_21 ( V_61 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_87 ) ) ;
}
static void F_58 (
struct V_55 * V_56 , struct V_2 * V_3 ,
int * V_57 )
{
F_40 ( L_16 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_88 ) ) ;
}
static void F_59 (
struct V_55 * V_56 , struct V_2 * V_3 ,
int * V_57 )
{
struct V_58 * V_59 = V_56 -> V_59 ;
struct V_16 * V_17 = V_59 -> V_17 ;
int V_4 ;
T_1 V_1 ;
struct V_25 * V_29 ;
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_23 ( L_6 , V_4 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_68 ) |
F_43 ( V_69 ) ) ;
return;
}
F_40 ( L_17 , V_1 ) ;
V_29 = F_10 ( V_17 ,
F_60 ( F_3 ( V_3 -> V_63 . V_64 ) ) ) ;
if ( ! V_29 ) {
F_17 ( L_18 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_72 ) ) ;
return;
}
if ( V_29 -> V_20 -> V_1 != V_1 ) {
F_17 ( L_19 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_72 ) ) ;
return;
}
F_5 ( & V_29 -> V_20 -> V_30 ) ;
if ( V_29 -> V_20 -> V_7 )
F_34 ( V_29 -> V_20 -> V_7 ) ;
V_29 -> V_20 -> V_10 = V_3 -> V_10 ;
V_29 -> V_20 -> V_75 = V_3 -> V_9 ;
V_29 -> V_20 -> V_7 = F_45 ( V_3 -> V_7 ) ;
V_29 -> V_20 -> V_11 = V_3 -> V_11 ;
F_7 ( & V_29 -> V_20 -> V_30 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_87 ) ) ;
}
static void F_61 (
struct V_55 * V_56 , struct V_2 * V_3 ,
int * V_57 )
{
struct V_58 * V_59 = V_56 -> V_59 ;
struct V_16 * V_17 = V_59 -> V_17 ;
int V_89 ;
struct V_25 * V_29 ;
V_89 = F_62 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
V_29 = F_10 ( V_17 , V_89 ) ;
if ( ! V_29 ) {
F_23 ( L_20 , V_89 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_90 ) ) ;
return;
}
F_63 ( L_21 ,
V_29 -> V_28 -> V_70 , V_29 -> V_33 ) ;
if ( V_3 -> V_9 != V_29 -> V_20 -> V_75 ) {
F_23 ( L_22 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_72 ) ) ;
return;
}
F_35 ( V_29 , true ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_87 ) ) ;
}
static void F_64 ( struct V_15 * V_20 )
{
bool V_91 = false ;
F_5 ( & V_20 -> V_30 ) ;
if ( V_20 -> V_7 ) {
F_65 ( & V_20 -> V_7 -> V_30 ) ;
V_91 = ( V_20 -> V_7 -> V_92 != NULL ) ;
F_66 ( & V_20 -> V_7 -> V_30 ) ;
if ( ! V_91 ) {
F_34 ( V_20 -> V_7 ) ;
V_20 -> V_7 = NULL ;
}
}
if ( ! V_91 || ( V_20 -> V_10 != V_20 -> V_7 -> V_10 ) ) {
F_63 ( L_23 ,
V_20 -> V_1 ) ;
V_20 -> V_75 = - 1 ;
V_20 -> V_93 = F_67 () +
( ( V_20 -> V_77 + 1 ) * V_94 ) ;
}
F_7 ( & V_20 -> V_30 ) ;
}
static void F_68 ( struct V_15 * V_20 )
{
struct V_25 * V_29 , * V_95 ;
F_69 ( V_49 ) ;
F_63 ( L_24 , V_20 -> V_1 ) ;
F_5 ( & V_20 -> V_30 ) ;
F_70 (login, temp, &sess->login_list, link) {
V_29 -> V_20 = NULL ;
F_71 ( & V_29 -> V_54 , & V_49 ) ;
}
F_7 ( & V_20 -> V_30 ) ;
F_70 (login, temp, &login_list, link) {
F_37 ( & V_29 -> V_54 ) ;
F_35 ( V_29 , false ) ;
}
F_29 ( V_20 , false ) ;
}
static void V_51 ( struct V_96 * V_97 )
{
struct V_15 * V_20 = F_72 ( V_97 , struct V_15 ,
V_50 . V_97 ) ;
F_5 ( & V_20 -> V_30 ) ;
if ( F_30 ( & V_20 -> V_49 ) ) {
F_7 ( & V_20 -> V_30 ) ;
return;
}
F_7 ( & V_20 -> V_30 ) ;
if ( V_20 -> V_75 != - 1 ) {
F_64 ( V_20 ) ;
F_46 ( & V_20 -> V_50 ,
V_76 ) ;
} else if ( ! F_73 ( F_67 () , V_20 -> V_93 ) ) {
F_46 ( & V_20 -> V_50 ,
V_76 ) ;
} else {
F_68 ( V_20 ) ;
}
}
static int F_74 ( struct V_98 * V_7 , int V_99 , void * V_100 ,
struct V_101 * V_56 )
{
int V_102 ;
switch ( V_99 ) {
case V_8 :
F_57 ( L_25 ) ;
F_5 ( & V_56 -> V_30 ) ;
V_102 = V_56 -> V_102 ;
F_7 ( & V_56 -> V_30 ) ;
* ( T_2 * ) V_100 = F_41 ( V_102 ) ;
return V_14 ;
case V_103 :
return V_14 ;
default:
return V_104 ;
}
}
static int F_75 ( struct V_98 * V_7 , int V_99 , void * V_100 ,
struct V_101 * V_56 )
{
switch ( V_99 ) {
case V_103 :
F_57 ( L_26 ) ;
F_5 ( & V_56 -> V_30 ) ;
V_56 -> V_102 = V_105 ;
F_7 ( & V_56 -> V_30 ) ;
return V_14 ;
default:
return V_104 ;
}
}
static int F_76 ( struct V_98 * V_7 , int V_99 , void * V_100 ,
struct V_101 * V_56 )
{
struct V_106 * V_107 = V_100 ;
switch ( V_99 ) {
case V_85 :
F_5 ( & V_56 -> V_30 ) ;
if ( V_56 -> V_102 != V_108 &&
V_56 -> V_102 != V_105 ) {
F_7 ( & V_56 -> V_30 ) ;
F_40 ( L_27 ) ;
return V_109 ;
}
V_56 -> V_102 = V_110 ;
F_7 ( & V_56 -> V_30 ) ;
V_56 -> V_111 = F_49 ( V_107 ) ;
V_56 -> V_112 = false ;
F_57 ( L_28 ,
V_56 -> V_111 ) ;
F_77 ( V_113 , & V_56 -> V_97 ) ;
return V_14 ;
case V_114 :
F_57 ( L_29 ) ;
F_5 ( & V_56 -> V_30 ) ;
F_56 ( V_56 -> V_111 , V_107 ) ;
F_7 ( & V_56 -> V_30 ) ;
return V_14 ;
default:
return V_104 ;
}
}
static int F_78 ( struct V_98 * V_7 , int V_99 , void * V_100 ,
struct V_101 * V_56 )
{
switch ( V_99 ) {
case V_103 :
F_5 ( & V_56 -> V_30 ) ;
if ( V_56 -> V_102 != V_108 ) {
F_7 ( & V_56 -> V_30 ) ;
F_57 ( L_30 ) ;
return V_109 ;
}
V_56 -> V_102 = V_110 ;
F_7 ( & V_56 -> V_30 ) ;
V_56 -> V_112 = true ;
F_57 ( L_31 ) ;
F_77 ( V_113 , & V_56 -> V_97 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_104 ;
}
}
static int F_79 ( struct V_98 * V_7 ,
int V_99 , void * V_100 , struct V_101 * V_56 )
{
switch ( V_99 ) {
case V_103 :
F_57 ( L_32 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_104 ;
}
}
static void F_80 ( struct V_98 * V_7 , struct V_115 * V_116 ,
int V_99 , int V_117 , int V_118 , int V_10 ,
unsigned long long V_83 , void * V_100 , T_3 V_81 ,
void * V_119 )
{
struct V_101 * V_56 = V_119 ;
struct V_15 * V_20 = V_56 -> V_29 -> V_20 ;
int V_120 , V_121 , V_122 ;
F_5 ( & V_20 -> V_30 ) ;
V_120 = V_20 -> V_10 ;
V_121 = V_20 -> V_75 ;
F_7 ( & V_20 -> V_30 ) ;
if ( V_10 != V_120 ) {
F_40 ( L_33 ) ;
V_122 = V_104 ;
goto V_123;
}
if ( V_118 != V_121 ) {
F_40 ( L_34 ,
V_118 , V_121 ) ;
V_122 = V_104 ;
goto V_123;
}
V_83 -= V_56 -> V_82 . V_83 ;
if ( V_83 == 0x00 && V_81 == 4 ) {
V_122 = F_74 ( V_7 , V_99 , V_100 , V_56 ) ;
} else if ( V_83 == 0x04 && V_81 == 4 ) {
V_122 = F_75 ( V_7 , V_99 , V_100 , V_56 ) ;
} else if ( V_83 == 0x08 && V_81 == 8 ) {
V_122 = F_76 ( V_7 , V_99 , V_100 , V_56 ) ;
} else if ( V_83 == 0x10 && V_81 == 4 ) {
V_122 = F_78 ( V_7 , V_99 , V_100 , V_56 ) ;
} else if ( V_83 == 0x14 && V_81 == 4 ) {
V_122 = F_79 ( V_7 , V_99 ,
V_100 , V_56 ) ;
} else {
V_122 = V_124 ;
}
V_123:
F_81 ( V_7 , V_116 , V_122 ) ;
}
static void F_82 ( struct V_96 * V_97 )
{
struct V_125 * V_3 =
F_72 ( V_97 , struct V_125 , V_97 ) ;
F_57 ( L_35 ,
V_3 -> V_111 ,
F_49 ( & V_3 -> V_63 . V_126 ) ,
F_49 ( & V_3 -> V_63 . V_127 ) ,
F_3 ( V_3 -> V_63 . V_64 ) ) ;
if ( V_3 -> V_111 >> 32 )
F_57 ( L_36 ) ;
switch ( F_83 ( F_3 ( V_3 -> V_63 . V_64 ) ) ) {
case 0 :
F_84 ( V_3 ) ;
return;
case 1 :
case 2 :
V_3 -> V_65 . V_65 |= F_41 (
F_42 (
V_66 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 (
V_88 ) ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
return;
case 3 :
V_3 -> V_65 . V_65 |= F_41 (
F_42 (
V_66 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 (
V_128 ) ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
return;
default:
F_89 () ;
}
}
static inline bool F_90 ( struct V_101 * V_56 )
{
bool V_129 ;
F_5 ( & V_56 -> V_30 ) ;
V_129 = ( V_56 -> V_102 == V_110 ) ;
F_7 ( & V_56 -> V_30 ) ;
return V_129 ;
}
static void F_91 ( struct V_96 * V_97 )
{
struct V_101 * V_56 =
F_72 ( V_97 , struct V_101 , V_97 ) ;
struct V_15 * V_20 = V_56 -> V_29 -> V_20 ;
struct V_125 * V_3 ;
int V_4 ;
bool V_112 = V_56 -> V_112 ;
T_1 V_126 = V_56 -> V_111 ;
while ( V_126 && F_90 ( V_56 ) ) {
V_3 = F_53 ( sizeof( * V_3 ) , V_45 ) ;
if ( ! V_3 ) {
F_5 ( & V_56 -> V_30 ) ;
V_56 -> V_102 = V_130 ;
F_7 ( & V_56 -> V_30 ) ;
return;
}
V_3 -> V_29 = V_56 -> V_29 ;
V_3 -> V_111 = V_126 ;
V_3 -> V_65 . V_65 = F_41 ( F_92 (
V_3 -> V_111 >> 32 ) ) ;
V_3 -> V_65 . V_131 = F_41 (
V_3 -> V_111 & 0xfffffffc ) ;
V_4 = F_2 ( V_20 -> V_7 , V_114 ,
V_20 -> V_75 , V_20 -> V_10 , V_20 -> V_11 ,
V_3 -> V_111 , & V_3 -> V_63 , sizeof( V_3 -> V_63 ) ) ;
if ( V_4 != V_14 ) {
F_57 ( L_37 , V_4 ) ;
V_3 -> V_65 . V_65 |= F_41 (
F_93 (
V_132 ) |
F_42 (
V_68 ) |
F_85 ( 1 ) |
F_86 ( 1 ) |
F_43 (
V_69 ) ) ;
F_5 ( & V_56 -> V_30 ) ;
V_56 -> V_102 = V_130 ;
F_7 ( & V_56 -> V_30 ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
return;
}
if ( F_3 ( V_3 -> V_63 . V_126 . V_5 ) & 0x80000000 ) {
V_126 = 0 ;
V_3 -> V_65 . V_65 |= F_41 ( F_93 (
V_132 ) ) ;
} else {
V_126 = F_49 ( & V_3 -> V_63 . V_126 ) ;
V_3 -> V_65 . V_65 |= F_41 ( F_93 (
V_133 ) ) ;
}
if ( F_90 ( V_56 ) && ! V_112 ) {
F_94 ( & V_3 -> V_97 , F_82 ) ;
F_77 ( V_113 , & V_3 -> V_97 ) ;
} else {
F_88 ( V_3 ) ;
}
F_5 ( & V_56 -> V_30 ) ;
V_112 = V_56 -> V_112 = false ;
if ( V_126 )
V_56 -> V_111 = V_126 ;
else
V_56 -> V_102 = V_108 ;
F_7 ( & V_56 -> V_30 ) ;
} ;
}
static struct V_101 * F_51 (
struct V_25 * V_29 )
{
struct V_101 * V_56 ;
int V_4 ;
V_56 = F_16 ( sizeof( * V_56 ) , V_45 ) ;
if ( ! V_56 )
return F_12 ( - V_46 ) ;
F_25 ( & V_56 -> V_30 ) ;
V_56 -> V_82 . V_81 = 0x20 ;
V_56 -> V_82 . V_134 = F_80 ;
V_56 -> V_82 . V_119 = V_56 ;
V_56 -> V_29 = V_29 ;
V_56 -> V_102 = V_105 ;
F_94 ( & V_56 -> V_97 , F_91 ) ;
V_56 -> V_111 = 0 ;
V_56 -> V_112 = false ;
V_4 = F_95 ( & V_56 -> V_82 ,
& V_135 ) ;
if ( V_4 < 0 ) {
F_21 ( V_56 ) ;
return F_12 ( V_4 ) ;
}
return V_56 ;
}
static void F_36 ( struct V_101 * V_56 )
{
F_96 ( & V_56 -> V_82 ) ;
F_97 ( & V_56 -> V_97 ) ;
F_21 ( V_56 ) ;
}
static int F_2 ( struct V_98 * V_7 , int V_99 , int V_136 ,
int V_10 , int V_11 , unsigned long long V_83 ,
void * V_137 , T_3 V_81 )
{
int V_138 , V_4 , V_139 ;
for ( V_138 = 1 ; V_138 <= 5 ; V_138 ++ ) {
V_4 = F_98 ( V_7 , V_99 , V_136 ,
V_10 , V_11 , V_83 , V_137 , V_81 ) ;
switch ( V_4 ) {
case V_14 :
case V_104 :
case V_124 :
case V_140 :
return V_4 ;
default:
V_139 = 5 * V_138 * V_138 ;
F_99 ( V_139 , V_139 * 2 ) ;
}
}
return V_4 ;
}
static int F_100 ( struct V_125 * V_3 ,
int V_99 , unsigned long long V_83 , void * V_137 ,
T_3 V_81 )
{
struct V_25 * V_29 = V_3 -> V_29 ;
struct V_15 * V_20 = V_29 -> V_20 ;
struct V_98 * V_7 ;
int V_75 , V_10 , V_11 , V_4 ;
F_5 ( & V_20 -> V_30 ) ;
V_7 = F_45 ( V_20 -> V_7 ) ;
V_75 = V_20 -> V_75 ;
V_10 = V_20 -> V_10 ;
V_11 = V_20 -> V_11 ;
F_7 ( & V_20 -> V_30 ) ;
V_4 = F_2 ( V_7 , V_99 , V_75 , V_10 , V_11 ,
V_83 , V_137 , V_81 ) ;
F_34 ( V_7 ) ;
return V_4 ;
}
static int F_101 ( struct V_125 * V_3 )
{
int V_4 , V_141 , V_142 ;
V_141 = F_102 ( V_3 -> V_63 . V_143 ) ;
V_3 -> V_144 = F_16 ( V_141 , V_45 ) ;
if ( ! V_3 -> V_144 )
return - V_46 ;
memcpy ( V_3 -> V_144 , V_3 -> V_63 . V_143 ,
F_103 ( int , V_141 , sizeof( V_3 -> V_63 . V_143 ) ) ) ;
if ( V_141 > sizeof( V_3 -> V_63 . V_143 ) ) {
F_57 ( L_38 ) ;
V_142 = V_141 - sizeof( V_3 -> V_63 . V_143 ) ;
V_4 = F_100 ( V_3 ,
V_114 ,
V_3 -> V_111 + sizeof( V_3 -> V_63 ) ,
V_3 -> V_144 + sizeof( V_3 -> V_63 . V_143 ) ,
V_142 ) ;
if ( V_4 != V_14 )
return - V_145 ;
}
return 0 ;
}
static int F_104 ( struct V_125 * V_3 )
{
int V_146 , V_4 ;
struct V_147 * V_148 ;
if ( ! F_105 ( F_3 ( V_3 -> V_63 . V_64 ) ) )
return 0 ;
V_146 = F_106 ( F_3 ( V_3 -> V_63 . V_64 ) ) *
sizeof( struct V_147 ) ;
V_148 = F_16 ( V_146 , V_45 ) ;
if ( ! V_148 )
return - V_46 ;
V_4 = F_100 ( V_3 , V_114 ,
F_49 ( & V_3 -> V_63 . V_127 ) ,
V_148 , V_146 ) ;
if ( V_4 != V_14 ) {
F_21 ( V_148 ) ;
return - V_145 ;
}
V_3 -> V_148 = V_148 ;
return 0 ;
}
static void F_107 ( struct V_125 * V_3 ,
T_4 * V_149 , enum V_150 * V_151 )
{
int V_152 , V_153 , V_154 ;
V_152 = F_106 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
V_153 = F_108 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
if ( ! V_152 ) {
* V_149 = 0 ;
* V_151 = V_155 ;
return;
}
* V_151 = V_153 ? V_156 : V_157 ;
if ( V_3 -> V_148 ) {
* V_149 = 0 ;
for ( V_154 = 0 ; V_154 < V_152 ; V_154 ++ ) {
* V_149 += F_109 (
V_3 -> V_148 [ V_154 ] . V_158 ) ;
}
} else {
* V_149 = V_152 ;
}
}
static void F_84 ( struct V_125 * V_3 )
{
struct V_25 * V_29 = V_3 -> V_29 ;
struct V_15 * V_20 = V_29 -> V_20 ;
int V_4 , V_70 ;
T_4 V_159 ;
enum V_150 V_151 ;
V_4 = F_101 ( V_3 ) ;
if ( V_4 ) {
F_57 ( L_39 , V_4 ) ;
goto V_160;
}
V_4 = F_104 ( V_3 ) ;
if ( V_4 ) {
F_57 ( L_40 ,
V_4 ) ;
goto V_160;
}
V_70 = V_3 -> V_29 -> V_28 -> V_70 ;
F_107 ( V_3 , & V_159 , & V_151 ) ;
F_57 ( L_41 ,
V_3 -> V_111 , V_70 , V_159 , V_151 ) ;
if ( F_110 ( & V_3 -> V_161 , V_20 -> V_19 , V_3 -> V_144 ,
V_3 -> V_162 , V_70 , V_159 ,
V_163 , V_151 , 0 ) )
goto V_160;
return;
V_160:
V_3 -> V_65 . V_65 |= F_41 (
F_42 ( V_68 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_69 ) ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
}
static int F_111 ( struct V_125 * V_3 )
{
struct V_15 * V_20 = V_3 -> V_29 -> V_20 ;
int V_99 , V_164 , V_165 , V_166 , V_11 , V_75 ,
V_10 , V_167 , V_81 , V_168 ,
V_122 = V_14 ;
struct V_147 * V_169 ;
unsigned long long V_83 ;
struct V_98 * V_7 ;
struct V_170 V_171 ;
if ( V_3 -> V_161 . V_172 == V_156 ) {
V_99 = V_85 ;
V_164 = V_173 ;
} else {
V_99 = V_114 ;
V_164 = V_174 ;
}
V_165 = 4 << F_112 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
V_11 = F_113 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
V_166 = F_114 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
if ( V_166 ) {
F_17 ( L_42 ) ;
V_166 = 0x100 << V_166 ;
}
F_5 ( & V_20 -> V_30 ) ;
V_7 = F_45 ( V_20 -> V_7 ) ;
V_75 = V_20 -> V_75 ;
V_10 = V_20 -> V_10 ;
F_7 ( & V_20 -> V_30 ) ;
if ( V_3 -> V_148 ) {
V_169 = V_3 -> V_148 ;
V_167 = F_106 ( F_3 ( V_3 -> V_63 . V_64 ) ) ;
V_83 = 0 ;
V_81 = 0 ;
} else {
V_169 = NULL ;
V_167 = 0 ;
V_83 = F_49 ( & V_3 -> V_63 . V_127 ) ;
V_81 = V_3 -> V_161 . V_159 ;
}
F_115 ( & V_171 , V_3 -> V_161 . V_175 , V_3 -> V_161 . V_176 ,
V_164 ) ;
while ( V_81 || V_167 ) {
if ( ! V_81 ) {
V_83 = ( T_1 ) F_109 ( V_169 -> V_177 ) << 32 |
F_3 ( V_169 -> V_178 ) ;
V_81 = F_109 ( V_169 -> V_158 ) ;
V_169 ++ ;
V_167 -- ;
}
F_116 ( & V_171 ) ;
V_168 = F_117 ( V_81 , V_165 , ( int ) V_171 . V_81 ) ;
V_122 = F_2 ( V_7 , V_99 , V_75 ,
V_10 , V_11 ,
V_83 , V_171 . V_179 , V_168 ) ;
if ( V_122 != V_14 )
break;
V_81 -= V_168 ;
V_83 += V_168 ;
V_171 . V_180 = V_168 ;
}
F_118 ( & V_171 ) ;
F_34 ( V_7 ) ;
if ( V_122 == V_14 ) {
F_119 ( V_81 != 0 ) ;
return 0 ;
} else {
return - V_145 ;
}
}
static int F_87 ( struct V_125 * V_3 )
{
int V_4 , V_81 ;
struct V_25 * V_29 = V_3 -> V_29 ;
V_81 = ( ( ( F_3 ( V_3 -> V_65 . V_65 ) >> 24 ) & 0x07 ) + 1 ) * 4 ;
V_4 = F_100 ( V_3 , V_85 ,
V_29 -> V_79 , & V_3 -> V_65 , V_81 ) ;
if ( V_4 != V_14 ) {
F_57 ( L_43 , V_4 ) ;
return - V_145 ;
}
F_57 ( L_44 ,
V_3 -> V_111 ) ;
return 0 ;
}
static void F_120 ( struct V_125 * V_3 )
{
struct V_161 * V_161 = & V_3 -> V_161 ;
T_5 * V_181 = V_3 -> V_162 ;
T_5 * V_65 = V_3 -> V_65 . V_100 ;
F_119 ( V_161 -> V_182 < 18 ) ;
switch ( V_181 [ 0 ] & 0x7f ) {
case 0x70 :
V_65 [ 0 ] = 0 << 6 ;
break;
case 0x71 :
V_65 [ 0 ] = 1 << 6 ;
break;
case 0x72 :
case 0x73 :
default:
F_17 ( L_45 ,
V_181 [ 0 ] ) ;
V_3 -> V_65 . V_65 |= F_41 (
F_42 ( V_66 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_183 ) ) ;
return;
}
V_65 [ 0 ] |= V_161 -> V_184 & 0x3f ;
V_65 [ 1 ] =
( V_181 [ 0 ] & 0x80 ) |
( ( V_181 [ 2 ] & 0xe0 ) >> 1 ) |
( V_181 [ 2 ] & 0x0f ) ;
V_65 [ 2 ] = V_161 -> V_185 ;
V_65 [ 3 ] = V_161 -> V_186 ;
V_65 [ 4 ] = V_181 [ 3 ] ;
V_65 [ 5 ] = V_181 [ 4 ] ;
V_65 [ 6 ] = V_181 [ 5 ] ;
V_65 [ 7 ] = V_181 [ 6 ] ;
V_65 [ 8 ] = V_181 [ 8 ] ;
V_65 [ 9 ] = V_181 [ 9 ] ;
V_65 [ 10 ] = V_181 [ 10 ] ;
V_65 [ 11 ] = V_181 [ 11 ] ;
V_65 [ 12 ] = V_181 [ 14 ] ;
V_65 [ 13 ] = V_181 [ 15 ] ;
V_65 [ 14 ] = V_181 [ 16 ] ;
V_65 [ 15 ] = V_181 [ 17 ] ;
V_3 -> V_65 . V_65 |= F_41 (
F_42 ( V_66 ) |
F_85 ( 0 ) |
F_86 ( 5 ) |
F_43 ( V_87 ) ) ;
}
static int F_121 ( struct V_125 * V_3 )
{
struct V_161 * V_161 = & V_3 -> V_161 ;
if ( V_161 -> V_182 ) {
F_120 ( V_3 ) ;
} else {
V_3 -> V_65 . V_65 |= F_41 (
F_42 ( V_66 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_87 ) ) ;
}
return F_87 ( V_3 ) ;
}
static void F_88 ( struct V_125 * V_3 )
{
F_21 ( V_3 -> V_148 ) ;
F_21 ( V_3 -> V_144 ) ;
F_21 ( V_3 ) ;
}
static void F_122 ( struct V_96 * V_97 )
{
struct V_55 * V_56 =
F_72 ( V_97 , struct V_55 , V_97 ) ;
struct V_2 * V_3 = V_56 -> V_116 ;
int V_4 ;
int V_187 = 0 ;
V_4 = F_2 ( V_3 -> V_7 , V_114 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
V_56 -> V_188 , & V_3 -> V_63 , sizeof( V_3 -> V_63 ) ) ;
if ( V_4 != V_14 ) {
F_57 ( L_46 , V_4 ) ;
goto V_123;
}
F_57 ( L_47 ,
F_49 ( & V_3 -> V_63 . V_189 ) ,
F_49 ( & V_3 -> V_63 . V_86 ) ,
F_3 ( V_3 -> V_63 . V_64 ) , F_3 ( V_3 -> V_63 . V_81 ) ,
F_49 ( & V_3 -> V_63 . V_80 ) ) ;
if ( ! F_123 ( F_3 ( V_3 -> V_63 . V_64 ) ) ||
F_83 ( F_3 ( V_3 -> V_63 . V_64 ) ) != 0 ) {
F_17 ( L_48 ) ;
goto V_123;
}
switch ( F_124 ( F_3 ( V_3 -> V_63 . V_64 ) ) ) {
case V_190 :
F_38 ( V_56 , V_3 , & V_187 ) ;
break;
case V_191 :
F_58 ( V_56 , V_3 ,
& V_187 ) ;
break;
case V_192 :
F_59 ( V_56 , V_3 , & V_187 ) ;
break;
case V_193 :
F_40 ( L_49 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_88 ) ) ;
break;
case V_194 :
F_61 ( V_56 , V_3 , & V_187 ) ;
break;
case V_195 :
F_40 ( L_50 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_88 ) ) ;
break;
case V_196 :
F_40 ( L_51 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_88 ) ) ;
break;
case V_197 :
F_40 ( L_52 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_88 ) ) ;
break;
case V_198 :
F_40 ( L_53 ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_88 ) ) ;
break;
default:
F_40 ( L_54 ,
F_124 ( F_3 ( V_3 -> V_63 . V_64 ) ) ) ;
V_3 -> V_65 . V_65 = F_41 (
F_42 ( V_66 ) |
F_43 ( V_88 ) ) ;
break;
}
V_3 -> V_65 . V_65 |= F_41 (
F_93 ( 1 ) |
F_86 ( F_125 ( V_187 , 4 ) + 1 ) |
F_92 ( V_56 -> V_188 >> 32 ) ) ;
V_3 -> V_65 . V_131 = F_41 ( V_56 -> V_188 ) ;
V_4 = F_2 ( V_3 -> V_7 , V_85 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
F_49 ( & V_3 -> V_63 . V_80 ) ,
& V_3 -> V_65 , 8 + V_187 ) ;
if ( V_4 != V_14 ) {
F_57 ( L_55 , V_4 ) ;
goto V_123;
}
V_123:
F_34 ( V_3 -> V_7 ) ;
F_21 ( V_3 ) ;
F_5 ( & V_56 -> V_30 ) ;
V_56 -> V_102 = V_199 ;
F_7 ( & V_56 -> V_30 ) ;
}
static void F_126 ( struct V_98 * V_7 ,
struct V_115 * V_116 , int V_99 , int V_117 , int V_118 ,
int V_10 , unsigned long long V_83 , void * V_100 , T_3 V_81 ,
void * V_119 )
{
struct V_55 * V_56 = V_119 ;
struct V_106 * V_107 = V_100 ;
int V_122 = V_124 ;
if ( ! V_56 -> V_59 -> V_200 )
goto V_123;
if ( ( V_83 != V_56 -> V_82 . V_83 ) || ( V_81 != 8 ) )
goto V_123;
if ( V_99 == V_85 ) {
struct V_2 * V_3 ;
int V_201 ;
F_5 ( & V_56 -> V_30 ) ;
V_201 = V_56 -> V_102 ;
V_56 -> V_102 = V_202 ;
F_7 ( & V_56 -> V_30 ) ;
if ( V_201 == V_202 ) {
F_40 ( L_56 ) ;
V_122 = V_109 ;
goto V_123;
}
V_3 = F_53 ( sizeof( * V_3 ) , V_203 ) ;
if ( ! V_3 ) {
V_122 = V_109 ;
goto V_123;
}
V_3 -> V_7 = F_45 ( V_7 ) ;
V_3 -> V_10 = V_10 ;
V_3 -> V_9 = V_118 ;
V_3 -> V_11 = F_127 ( V_116 ) ;
V_56 -> V_188 = F_49 ( V_107 ) ;
V_56 -> V_116 = V_3 ;
F_77 ( V_113 , & V_56 -> V_97 ) ;
V_122 = V_14 ;
} else if ( V_99 == V_114 ) {
F_56 ( V_56 -> V_188 , V_107 ) ;
V_122 = V_14 ;
} else {
V_122 = V_104 ;
}
V_123:
F_81 ( V_7 , V_116 , V_122 ) ;
}
static struct V_55 * F_128 (
struct V_58 * V_59 )
{
int V_4 ;
struct V_55 * V_56 ;
V_56 = F_16 ( sizeof( * V_56 ) , V_45 ) ;
if ( ! V_56 )
return F_12 ( - V_46 ) ;
F_25 ( & V_56 -> V_30 ) ;
V_56 -> V_59 = V_59 ;
V_56 -> V_82 . V_81 = 0x08 ;
V_56 -> V_82 . V_134 = F_126 ;
V_56 -> V_82 . V_119 = V_56 ;
V_56 -> V_102 = V_199 ;
F_94 ( & V_56 -> V_97 , F_122 ) ;
V_56 -> V_188 = 0 ;
V_56 -> V_116 = NULL ;
V_4 = F_95 ( & V_56 -> V_82 ,
& V_135 ) ;
if ( V_4 < 0 ) {
F_21 ( V_56 ) ;
return F_12 ( V_4 ) ;
}
return V_56 ;
}
static void F_129 ( struct V_55 * V_56 )
{
F_96 ( & V_56 -> V_82 ) ;
F_97 ( & V_56 -> V_97 ) ;
F_21 ( V_56 ) ;
}
static int F_130 ( struct V_34 * V_22 )
{
return 1 ;
}
static int F_131 ( struct V_34 * V_22 )
{
return 0 ;
}
static char * F_132 ( void )
{
return L_57 ;
}
static char * F_133 ( struct V_34 * V_22 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
return & V_59 -> V_204 [ 0 ] ;
}
static T_6 F_134 ( struct V_34 * V_22 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
return V_17 -> V_205 ;
}
static T_4 F_135 ( struct V_34 * V_22 )
{
return 1 ;
}
static struct V_43 * F_136 ( struct V_34 * V_22 )
{
struct V_206 * V_207 ;
V_207 = F_53 ( sizeof( struct V_206 ) , V_45 ) ;
if ( ! V_207 ) {
F_17 ( L_58 ) ;
return NULL ;
}
return & V_207 -> V_43 ;
}
static void F_137 (
struct V_34 * V_22 ,
struct V_43 * V_44 )
{
struct V_206 * V_207 =
F_72 ( V_44 , struct V_206 , V_43 ) ;
F_21 ( V_207 ) ;
}
static T_4 F_138 ( struct V_34 * V_22 )
{
return 1 ;
}
static void F_139 ( struct V_161 * V_161 )
{
struct V_125 * V_3 = F_72 ( V_161 ,
struct V_125 , V_161 ) ;
F_88 ( V_3 ) ;
}
static int F_140 ( struct V_18 * V_19 )
{
return 0 ;
}
static void F_141 ( struct V_18 * V_19 )
{
return;
}
static T_4 F_142 ( struct V_18 * V_19 )
{
return 0 ;
}
static int F_143 ( struct V_161 * V_161 )
{
struct V_125 * V_3 = F_72 ( V_161 ,
struct V_125 , V_161 ) ;
int V_4 ;
V_4 = F_111 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_65 . V_65 |= F_41 (
F_42 (
V_68 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 (
V_69 ) ) ;
F_87 ( V_3 ) ;
return V_4 ;
}
F_144 ( V_161 ) ;
return 0 ;
}
static int F_145 ( struct V_161 * V_161 )
{
return 0 ;
}
static void F_146 ( struct V_43 * V_207 )
{
return;
}
static T_4 F_147 ( struct V_161 * V_161 )
{
struct V_125 * V_3 = F_72 ( V_161 ,
struct V_125 , V_161 ) ;
return ( T_4 ) V_3 -> V_111 ;
}
static int F_148 ( struct V_161 * V_161 )
{
return 0 ;
}
static int F_149 ( struct V_161 * V_161 )
{
struct V_125 * V_3 = F_72 ( V_161 ,
struct V_125 , V_161 ) ;
int V_4 ;
V_4 = F_111 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_65 . V_65 |= F_41 (
F_42 ( V_68 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_69 ) ) ;
F_87 ( V_3 ) ;
return V_4 ;
}
return F_121 ( V_3 ) ;
}
static int F_150 ( struct V_161 * V_161 )
{
struct V_125 * V_3 = F_72 ( V_161 ,
struct V_125 , V_161 ) ;
return F_121 ( V_3 ) ;
}
static void F_151 ( struct V_161 * V_161 )
{
}
static void F_152 ( struct V_161 * V_161 )
{
return;
}
static int F_153 ( struct V_161 * V_161 )
{
struct V_125 * V_3 = F_72 ( V_161 ,
struct V_125 , V_161 ) ;
F_154 ( & V_3 -> V_161 , 0 ) ;
return 1 ;
}
static T_5 F_155 ( struct V_34 * V_22 )
{
return V_208 ;
}
static T_4 F_156 (
struct V_34 * V_22 ,
struct V_43 * V_44 ,
struct V_209 * V_210 ,
int * V_211 ,
unsigned char * V_212 )
{
int V_4 ;
V_212 [ 0 ] = V_208 ;
V_4 = F_157 ( & V_212 [ 8 ] , V_44 -> V_213 , 8 ) ;
if ( V_4 < 0 )
F_57 ( L_59 ) ;
return 24 ;
}
static T_4 F_158 (
struct V_34 * V_22 ,
struct V_43 * V_44 ,
struct V_209 * V_210 ,
int * V_211 )
{
* V_211 = 0 ;
return 24 ;
}
static char * F_159 (
struct V_34 * V_22 ,
const char * V_212 ,
T_4 * V_214 ,
char * * V_215 )
{
* V_215 = NULL ;
* V_214 = 24 ;
return ( char * ) & V_212 [ 8 ] ;
}
static int F_160 ( struct V_34 * V_17 )
{
int V_216 , V_32 = 0 ;
F_13 ( & V_17 -> V_37 ) ;
for ( V_216 = 0 ; V_216 < V_35 ; V_216 ++ ) {
struct V_27 * V_27 = V_17 -> V_38 [ V_216 ] ;
if ( V_27 -> V_39 == V_217 )
continue;
V_32 ++ ;
}
F_14 ( & V_17 -> V_37 ) ;
return V_32 ;
}
static int F_161 ( struct V_58 * V_59 )
{
int V_218 , V_219 , V_154 = 0 , V_220 , V_4 , V_216 ;
T_4 * V_100 ;
if ( V_59 -> V_221 . V_100 ) {
F_162 ( & V_59 -> V_221 ) ;
F_21 ( V_59 -> V_221 . V_100 ) ;
V_59 -> V_221 . V_100 = NULL ;
}
if ( ! V_59 -> V_200 || ! V_59 -> V_17 )
return 0 ;
V_218 = F_160 ( & V_59 -> V_17 -> V_22 ) ;
V_219 = F_163 ( V_222 ) + 4 + V_218 ;
if ( V_59 -> V_223 != - 1 )
V_219 ++ ;
V_100 = F_164 ( ( V_219 + 4 ) , sizeof( T_4 ) , V_45 ) ;
if ( ! V_100 )
return - V_46 ;
V_100 [ V_154 ++ ] = V_219 << 16 ;
if ( V_59 -> V_223 != - 1 )
V_100 [ V_154 ++ ] = ( V_224 << 24 ) | V_59 -> V_223 ;
memcpy ( & V_100 [ V_154 ] , V_222 ,
sizeof( V_222 ) ) ;
V_154 += F_163 ( V_222 ) ;
V_220 = ( V_59 -> V_225 -> V_82 . V_83 - V_12 ) / 4 ;
V_100 [ V_154 ++ ] = 0x54000000 | ( V_220 & 0x00ffffff ) ;
V_100 [ V_154 ++ ] = 0x3a000000 |
( ( ( V_59 -> V_226 * 2 ) << 8 ) & 0xff00 ) |
V_227 ;
V_100 [ V_154 ++ ] = 0x3d000000 | ( V_59 -> V_78 & 0xffff ) ;
V_100 [ V_154 ++ ] = 0x8d000000 | ( V_218 + 1 ) ;
F_13 ( & V_59 -> V_17 -> V_22 . V_37 ) ;
for ( V_216 = 0 ; V_216 < V_35 ; V_216 ++ ) {
struct V_27 * V_27 = V_59 -> V_17 -> V_22 . V_38 [ V_216 ] ;
struct V_228 * V_229 ;
int type ;
if ( V_27 -> V_39 == V_217 )
continue;
F_14 ( & V_59 -> V_17 -> V_22 . V_37 ) ;
V_229 = V_27 -> V_230 ;
type = V_229 -> V_231 -> V_232 ( V_229 ) ;
V_100 [ V_154 ++ ] = 0x14000000 |
( ( type << 16 ) & 0x1f0000 ) |
( V_27 -> V_70 & 0xffff ) ;
F_13 ( & V_59 -> V_17 -> V_22 . V_37 ) ;
}
F_14 ( & V_59 -> V_17 -> V_22 . V_37 ) ;
V_100 [ V_154 ++ ] = 2 << 16 ;
V_100 [ V_154 ++ ] = V_59 -> V_1 >> 32 ;
V_100 [ V_154 ++ ] = V_59 -> V_1 ;
V_59 -> V_221 . V_81 = V_154 ;
V_59 -> V_221 . V_233 = ( V_234 | V_235 ) << 24 ;
V_59 -> V_221 . V_100 = V_100 ;
V_4 = F_165 ( & V_59 -> V_221 ) ;
if ( V_4 < 0 ) {
F_21 ( V_59 -> V_221 . V_100 ) ;
V_59 -> V_221 . V_100 = NULL ;
}
return V_4 ;
}
static T_7 F_166 ( const char * V_236 , T_1 * V_237 )
{
const char * V_238 ;
char V_239 , V_240 ;
int V_241 = 0 , V_160 ;
* V_237 = 0 ;
for ( V_238 = V_236 ; V_238 < & V_236 [ V_242 - 1 ] ; V_238 ++ ) {
V_239 = * V_238 ;
if ( V_239 == '\n' && V_238 [ 1 ] == '\0' )
continue;
if ( V_239 == '\0' ) {
V_160 = 2 ;
if ( V_241 != 16 )
goto V_243;
return V_238 - V_236 ;
}
V_160 = 3 ;
if ( isdigit ( V_239 ) )
V_240 = V_239 - '0' ;
else if ( isxdigit ( V_239 ) )
V_240 = tolower ( V_239 ) - 'a' + 10 ;
else
goto V_243;
* V_237 = ( * V_237 << 4 ) | V_240 ;
V_241 ++ ;
}
V_160 = 4 ;
V_243:
F_167 ( V_244 L_60 ,
V_160 , V_238 - V_236 , V_241 ) ;
return - 1 ;
}
static T_7 F_168 ( char * V_212 , T_3 V_245 , T_1 V_237 )
{
return snprintf ( V_212 , V_245 , L_3 , V_237 ) ;
}
static struct V_43 * F_169 (
struct V_34 * V_22 ,
struct V_246 * V_247 ,
const char * V_236 )
{
struct V_43 * V_44 , * V_248 ;
struct V_206 * V_207 ;
T_1 V_1 = 0 ;
T_4 V_249 = 1 ;
if ( F_166 ( V_236 , & V_1 ) < 0 )
return F_12 ( - V_36 ) ;
V_248 = F_136 ( V_22 ) ;
if ( ! V_248 )
return F_12 ( - V_46 ) ;
V_44 = F_170 ( V_22 , V_248 ,
V_236 , V_249 ) ;
if ( F_19 ( V_44 ) ) {
F_137 ( V_22 , V_248 ) ;
return V_44 ;
}
V_207 = F_72 ( V_44 , struct V_206 , V_43 ) ;
V_207 -> V_1 = V_1 ;
F_168 ( V_207 -> V_250 , V_242 , V_1 ) ;
return V_44 ;
}
static void F_171 ( struct V_43 * V_251 )
{
struct V_206 * V_207 =
F_72 ( V_251 , struct V_206 , V_43 ) ;
F_172 ( V_251 -> V_22 , V_251 , 1 ) ;
F_21 ( V_207 ) ;
}
static int F_173 (
struct V_34 * V_22 ,
struct V_27 * V_27 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
return F_161 ( V_17 -> V_59 ) ;
}
static void F_174 (
struct V_34 * V_22 ,
struct V_27 * V_27 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
int V_4 ;
if ( F_160 ( & V_17 -> V_22 ) == 0 )
V_59 -> V_200 = 0 ;
V_4 = F_161 ( V_59 ) ;
if ( V_4 < 0 )
F_17 ( L_61 ) ;
}
static struct V_34 * F_175 (
struct V_252 * V_237 ,
struct V_246 * V_247 ,
const char * V_236 )
{
struct V_58 * V_59 =
F_72 ( V_237 , struct V_58 , V_253 ) ;
struct V_16 * V_17 ;
unsigned long V_254 ;
int V_4 ;
if ( strstr ( V_236 , L_62 ) != V_236 )
return F_12 ( - V_36 ) ;
if ( F_176 ( V_236 + 5 , 10 , & V_254 ) || V_254 > V_255 )
return F_12 ( - V_36 ) ;
if ( V_59 -> V_17 ) {
F_17 ( L_63 ) ;
return F_12 ( - V_256 ) ;
}
V_17 = F_53 ( sizeof( * V_17 ) , V_45 ) ;
if ( ! V_17 ) {
F_17 ( L_64 ) ;
return F_12 ( - V_46 ) ;
}
V_17 -> V_59 = V_59 ;
V_17 -> V_205 = V_254 ;
V_59 -> V_17 = V_17 ;
V_59 -> V_200 = 0 ;
V_59 -> V_223 = - 1 ;
V_59 -> V_226 = 15 ;
V_59 -> V_78 = 5 ;
V_59 -> V_73 = 1 ;
V_59 -> V_225 = F_128 ( V_59 ) ;
if ( F_19 ( V_59 -> V_225 ) ) {
V_4 = F_20 ( V_59 -> V_225 ) ;
goto V_257;
}
V_4 = F_177 ( & V_258 , V_237 , & V_17 -> V_22 , V_17 ,
V_259 ) ;
if ( V_4 < 0 )
goto V_260;
return & V_17 -> V_22 ;
V_260:
F_129 ( V_59 -> V_225 ) ;
V_257:
V_59 -> V_17 = NULL ;
F_21 ( V_17 ) ;
return F_12 ( V_4 ) ;
}
static void F_178 ( struct V_34 * V_22 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
F_179 ( V_22 ) ;
F_129 ( V_59 -> V_225 ) ;
V_59 -> V_17 = NULL ;
F_21 ( V_17 ) ;
}
static struct V_252 * F_180 (
struct V_261 * V_262 ,
struct V_246 * V_247 ,
const char * V_236 )
{
struct V_58 * V_59 ;
T_1 V_1 = 0 ;
if ( F_166 ( V_236 , & V_1 ) < 0 )
return F_12 ( - V_36 ) ;
V_59 = F_53 ( sizeof( * V_59 ) , V_45 ) ;
if ( ! V_59 ) {
F_17 ( L_65 ) ;
return F_12 ( - V_46 ) ;
}
V_59 -> V_1 = V_1 ;
F_168 ( V_59 -> V_204 , V_242 , V_1 ) ;
return & V_59 -> V_253 ;
}
static void F_181 ( struct V_252 * V_237 )
{
struct V_58 * V_59 =
F_72 ( V_237 , struct V_58 , V_253 ) ;
F_21 ( V_59 ) ;
}
static T_7 F_182 (
struct V_261 * V_262 ,
char * V_263 )
{
return sprintf ( V_263 , L_66 , V_264 ) ;
}
static T_7 F_183 (
struct V_34 * V_22 ,
char * V_263 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
if ( V_59 -> V_223 == - 1 )
return sprintf ( V_263 , L_67 ) ;
else
return sprintf ( V_263 , L_68 , V_59 -> V_223 ) ;
}
static T_7 F_184 (
struct V_34 * V_22 ,
const char * V_263 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
unsigned long V_265 ;
if ( V_59 -> V_200 ) {
F_17 ( L_69 ) ;
return - V_256 ;
}
if ( strstr ( V_263 , L_70 ) == V_263 ) {
V_59 -> V_223 = - 1 ;
} else {
if ( F_176 ( V_263 , 16 , & V_265 ) < 0 )
return - V_36 ;
if ( V_265 > 0xffffff )
return - V_36 ;
V_59 -> V_223 = V_265 ;
}
return V_32 ;
}
static T_7 F_185 (
struct V_34 * V_22 ,
char * V_263 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
return sprintf ( V_263 , L_71 , V_59 -> V_200 ) ;
}
static T_7 F_186 (
struct V_34 * V_22 ,
const char * V_263 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
unsigned long V_265 ;
int V_4 ;
if ( F_176 ( V_263 , 0 , & V_265 ) < 0 )
return - V_36 ;
if ( ( V_265 != 0 ) && ( V_265 != 1 ) )
return - V_36 ;
if ( V_59 -> V_200 == V_265 )
return V_32 ;
if ( V_265 ) {
if ( F_160 ( & V_17 -> V_22 ) == 0 ) {
F_17 ( L_72 ) ;
return - V_36 ;
}
} else {
F_5 ( & V_22 -> V_23 ) ;
if ( ! F_30 ( & V_22 -> V_266 ) ) {
F_7 ( & V_22 -> V_23 ) ;
return - V_256 ;
}
F_7 ( & V_22 -> V_23 ) ;
}
V_59 -> V_200 = V_265 ;
V_4 = F_161 ( V_59 ) ;
if ( V_4 < 0 ) {
F_17 ( L_73 ) ;
return V_4 ;
}
return V_32 ;
}
static T_7 F_187 (
struct V_34 * V_22 ,
char * V_263 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
return sprintf ( V_263 , L_71 , V_59 -> V_226 ) ;
}
static T_7 F_188 (
struct V_34 * V_22 ,
const char * V_263 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
unsigned long V_265 ;
int V_4 ;
if ( F_176 ( V_263 , 0 , & V_265 ) < 0 )
return - V_36 ;
if ( ( V_265 < 1 ) || ( V_265 > 127 ) )
return - V_36 ;
if ( V_59 -> V_226 == V_265 )
return V_32 ;
V_59 -> V_226 = V_265 ;
V_4 = F_161 ( V_59 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_189 (
struct V_34 * V_22 ,
char * V_263 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
return sprintf ( V_263 , L_71 , V_59 -> V_78 ) ;
}
static T_7 F_190 (
struct V_34 * V_22 ,
const char * V_263 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
unsigned long V_265 ;
int V_4 ;
if ( F_176 ( V_263 , 0 , & V_265 ) < 0 )
return - V_36 ;
if ( ( V_265 < 1 ) || ( V_265 > 32767 ) )
return - V_36 ;
if ( V_59 -> V_78 == V_265 )
return V_32 ;
V_59 -> V_78 = V_265 ;
V_4 = F_161 ( V_59 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_191 (
struct V_34 * V_22 ,
char * V_263 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
return sprintf ( V_263 , L_71 , V_59 -> V_73 ) ;
}
static T_7 F_192 (
struct V_34 * V_22 ,
const char * V_263 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_58 * V_59 = V_17 -> V_59 ;
unsigned long V_265 ;
if ( F_176 ( V_263 , 0 , & V_265 ) < 0 )
return - V_36 ;
if ( ( V_265 < 1 ) || ( V_265 > 127 ) )
return - V_36 ;
V_59 -> V_73 = V_265 ;
return V_32 ;
}
static int T_8 F_193 ( void )
{
return F_194 ( & V_258 ) ;
}
static void T_9 F_195 ( void )
{
F_196 ( & V_258 ) ;
}
