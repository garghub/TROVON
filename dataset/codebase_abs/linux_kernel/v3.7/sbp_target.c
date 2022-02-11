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
V_20 -> V_19 = F_18 () ;
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
return F_12 ( - V_47 ) ;
}
V_20 -> V_19 -> V_43 = V_44 ;
F_25 ( & V_20 -> V_30 ) ;
F_26 ( & V_20 -> V_48 ) ;
F_27 ( & V_20 -> V_49 , V_50 ) ;
V_20 -> V_1 = V_1 ;
F_28 ( & V_17 -> V_22 , V_44 , V_20 -> V_19 , V_20 ) ;
return V_20 ;
}
static void F_29 ( struct V_15 * V_20 , bool V_51 )
{
F_5 ( & V_20 -> V_30 ) ;
if ( ! F_30 ( & V_20 -> V_48 ) ) {
F_7 ( & V_20 -> V_30 ) ;
return;
}
F_7 ( & V_20 -> V_30 ) ;
if ( V_51 )
F_31 ( & V_20 -> V_49 ) ;
F_32 ( V_20 -> V_19 ) ;
F_33 ( V_20 -> V_19 ) ;
if ( V_20 -> V_7 )
F_34 ( V_20 -> V_7 ) ;
F_21 ( V_20 ) ;
}
static void F_35 ( struct V_25 * V_29 ,
bool V_51 )
{
struct V_15 * V_20 = V_29 -> V_20 ;
F_36 ( V_29 -> V_52 ) ;
if ( V_20 ) {
F_5 ( & V_20 -> V_30 ) ;
F_37 ( & V_29 -> V_53 ) ;
F_7 ( & V_20 -> V_30 ) ;
F_29 ( V_20 , V_51 ) ;
}
F_21 ( V_29 ) ;
}
static void F_38 (
struct V_54 * V_55 , struct V_2 * V_3 ,
int * V_56 )
{
struct V_57 * V_58 = V_55 -> V_58 ;
struct V_16 * V_17 = V_58 -> V_17 ;
struct V_27 * V_27 ;
int V_4 ;
T_1 V_1 ;
struct V_15 * V_20 ;
struct V_25 * V_29 ;
struct V_59 * V_60 ;
int V_61 ;
V_27 = F_11 ( V_17 ,
F_39 ( F_3 ( V_3 -> V_62 . V_63 ) ) ) ;
if ( F_19 ( V_27 ) ) {
F_40 ( L_5 ,
F_39 ( F_3 ( V_3 -> V_62 . V_63 ) ) ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_66 ) ) ;
return;
}
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_23 ( L_6 , V_4 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_67 ) |
F_43 ( V_68 ) ) ;
return;
}
F_40 ( L_7 ,
V_27 -> V_69 , V_1 ) ;
V_20 = F_4 ( V_17 , V_1 ) ;
if ( V_20 ) {
V_29 = F_8 ( V_20 , V_27 ) ;
if ( V_29 ) {
F_40 ( L_8 ) ;
goto V_70;
}
}
if ( F_44 ( F_3 ( V_3 -> V_62 . V_63 ) ) &&
F_9 ( V_17 , V_27 , 0 ) ) {
F_23 ( L_9 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_71 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 1 ) ) {
F_23 ( L_10 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_71 ) ) ;
return;
}
if ( F_9 ( V_17 , V_27 , 0 ) >=
V_58 -> V_72 ) {
F_23 ( L_11 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_73 ) ) ;
return;
}
if ( ! V_20 ) {
V_20 = F_15 ( V_17 , V_1 ) ;
if ( F_19 ( V_20 ) ) {
switch ( F_20 ( V_20 ) ) {
case - V_47 :
V_4 = V_71 ;
break;
default:
V_4 = V_73 ;
break;
}
V_3 -> V_64 . V_64 = F_41 (
F_42 (
V_65 ) |
F_43 ( V_4 ) ) ;
return;
}
V_20 -> V_74 = V_3 -> V_9 ;
V_20 -> V_7 = F_45 ( V_3 -> V_7 ) ;
V_20 -> V_10 = V_3 -> V_10 ;
V_20 -> V_11 = V_3 -> V_11 ;
F_46 ( & V_20 -> V_49 ,
V_75 ) ;
}
V_20 -> V_76 = F_47 (
1 << F_48 ( F_3 ( V_3 -> V_62 . V_63 ) ) ,
V_58 -> V_77 ) - 1 ;
V_29 = F_16 ( sizeof( * V_29 ) , V_45 ) ;
if ( ! V_29 ) {
F_17 ( L_12 ) ;
F_29 ( V_20 , true ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_73 ) ) ;
return;
}
V_29 -> V_20 = V_20 ;
V_29 -> V_28 = V_27 ;
V_29 -> V_78 = F_49 ( & V_3 -> V_62 . V_79 ) ;
V_29 -> V_31 = F_44 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
V_29 -> V_33 = F_50 ( & V_33 ) ;
V_29 -> V_52 = F_51 ( V_29 ) ;
if ( F_19 ( V_29 -> V_52 ) ) {
V_4 = F_20 ( V_29 -> V_52 ) ;
F_17 ( L_13 , V_4 ) ;
F_29 ( V_20 , true ) ;
F_21 ( V_29 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_73 ) ) ;
return;
}
F_5 ( & V_20 -> V_30 ) ;
F_52 ( & V_29 -> V_53 , & V_20 -> V_48 ) ;
F_7 ( & V_20 -> V_30 ) ;
V_70:
V_60 = F_53 ( sizeof( * V_60 ) , V_45 ) ;
if ( ! V_60 ) {
F_17 ( L_14 ) ;
F_35 ( V_29 , true ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_73 ) ) ;
return;
}
V_61 = F_54 (
F_55 ( F_3 ( V_3 -> V_62 . V_80 ) ) ,
12 , sizeof( * V_60 ) ) ;
V_60 -> V_63 = F_41 (
( ( V_61 & 0xffff ) << 16 ) |
( V_29 -> V_33 & 0xffff ) ) ;
V_60 -> V_76 = F_41 ( V_20 -> V_76 & 0xffff ) ;
F_56 ( V_29 -> V_52 -> V_81 . V_82 ,
& V_60 -> V_83 ) ;
V_4 = F_2 ( V_20 -> V_7 , V_84 ,
V_20 -> V_74 , V_20 -> V_10 , V_20 -> V_11 ,
F_49 ( & V_3 -> V_62 . V_85 ) , V_60 ,
V_61 ) ;
if ( V_4 != V_14 ) {
F_57 ( L_15 , V_4 ) ;
F_21 ( V_60 ) ;
F_35 ( V_29 , true ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_67 ) |
F_43 ( V_68 ) ) ;
return;
}
F_21 ( V_60 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_86 ) ) ;
}
static void F_58 (
struct V_54 * V_55 , struct V_2 * V_3 ,
int * V_56 )
{
F_40 ( L_16 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_87 ) ) ;
}
static void F_59 (
struct V_54 * V_55 , struct V_2 * V_3 ,
int * V_56 )
{
struct V_57 * V_58 = V_55 -> V_58 ;
struct V_16 * V_17 = V_58 -> V_17 ;
int V_4 ;
T_1 V_1 ;
struct V_25 * V_29 ;
V_4 = F_1 ( & V_1 , V_3 ) ;
if ( V_4 != V_14 ) {
F_23 ( L_6 , V_4 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_67 ) |
F_43 ( V_68 ) ) ;
return;
}
F_40 ( L_17 , V_1 ) ;
V_29 = F_10 ( V_17 ,
F_60 ( F_3 ( V_3 -> V_62 . V_63 ) ) ) ;
if ( ! V_29 ) {
F_17 ( L_18 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_71 ) ) ;
return;
}
if ( V_29 -> V_20 -> V_1 != V_1 ) {
F_17 ( L_19 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_71 ) ) ;
return;
}
F_5 ( & V_29 -> V_20 -> V_30 ) ;
if ( V_29 -> V_20 -> V_7 )
F_34 ( V_29 -> V_20 -> V_7 ) ;
V_29 -> V_20 -> V_10 = V_3 -> V_10 ;
V_29 -> V_20 -> V_74 = V_3 -> V_9 ;
V_29 -> V_20 -> V_7 = F_45 ( V_3 -> V_7 ) ;
V_29 -> V_20 -> V_11 = V_3 -> V_11 ;
F_7 ( & V_29 -> V_20 -> V_30 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_86 ) ) ;
}
static void F_61 (
struct V_54 * V_55 , struct V_2 * V_3 ,
int * V_56 )
{
struct V_57 * V_58 = V_55 -> V_58 ;
struct V_16 * V_17 = V_58 -> V_17 ;
int V_88 ;
struct V_25 * V_29 ;
V_88 = F_62 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
V_29 = F_10 ( V_17 , V_88 ) ;
if ( ! V_29 ) {
F_23 ( L_20 , V_88 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_89 ) ) ;
return;
}
F_63 ( L_21 ,
V_29 -> V_28 -> V_69 , V_29 -> V_33 ) ;
if ( V_3 -> V_9 != V_29 -> V_20 -> V_74 ) {
F_23 ( L_22 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_71 ) ) ;
return;
}
F_35 ( V_29 , true ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_86 ) ) ;
}
static void F_64 ( struct V_15 * V_20 )
{
bool V_90 = false ;
F_5 ( & V_20 -> V_30 ) ;
if ( V_20 -> V_7 ) {
F_65 ( & V_20 -> V_7 -> V_30 ) ;
V_90 = ( V_20 -> V_7 -> V_91 != NULL ) ;
F_66 ( & V_20 -> V_7 -> V_30 ) ;
if ( ! V_90 ) {
F_34 ( V_20 -> V_7 ) ;
V_20 -> V_7 = NULL ;
}
}
if ( ! V_90 || ( V_20 -> V_10 != V_20 -> V_7 -> V_10 ) ) {
F_63 ( L_23 ,
V_20 -> V_1 ) ;
V_20 -> V_74 = - 1 ;
V_20 -> V_92 = F_67 () +
( ( V_20 -> V_76 + 1 ) * V_93 ) ;
}
F_7 ( & V_20 -> V_30 ) ;
}
static void F_68 ( struct V_15 * V_20 )
{
struct V_25 * V_29 , * V_94 ;
F_69 ( V_48 ) ;
F_63 ( L_24 , V_20 -> V_1 ) ;
F_5 ( & V_20 -> V_30 ) ;
F_70 (login, temp, &sess->login_list, link) {
V_29 -> V_20 = NULL ;
F_71 ( & V_29 -> V_53 , & V_48 ) ;
}
F_7 ( & V_20 -> V_30 ) ;
F_70 (login, temp, &login_list, link) {
F_37 ( & V_29 -> V_53 ) ;
F_35 ( V_29 , false ) ;
}
F_29 ( V_20 , false ) ;
}
static void V_50 ( struct V_95 * V_96 )
{
struct V_15 * V_20 = F_72 ( V_96 , struct V_15 ,
V_49 . V_96 ) ;
F_5 ( & V_20 -> V_30 ) ;
if ( F_30 ( & V_20 -> V_48 ) ) {
F_7 ( & V_20 -> V_30 ) ;
return;
}
F_7 ( & V_20 -> V_30 ) ;
if ( V_20 -> V_74 != - 1 ) {
F_64 ( V_20 ) ;
F_46 ( & V_20 -> V_49 ,
V_75 ) ;
} else if ( ! F_73 ( F_67 () , V_20 -> V_92 ) ) {
F_46 ( & V_20 -> V_49 ,
V_75 ) ;
} else {
F_68 ( V_20 ) ;
}
}
static int F_74 ( struct V_97 * V_7 , int V_98 , void * V_99 ,
struct V_100 * V_55 )
{
T_2 V_101 ;
switch ( V_98 ) {
case V_8 :
F_57 ( L_25 ) ;
F_5 ( & V_55 -> V_30 ) ;
V_101 = F_41 ( V_55 -> V_101 ) ;
F_7 ( & V_55 -> V_30 ) ;
memcpy ( V_99 , & V_101 , sizeof( V_101 ) ) ;
return V_14 ;
case V_102 :
return V_14 ;
default:
return V_103 ;
}
}
static int F_75 ( struct V_97 * V_7 , int V_98 , void * V_99 ,
struct V_100 * V_55 )
{
switch ( V_98 ) {
case V_102 :
F_57 ( L_26 ) ;
F_5 ( & V_55 -> V_30 ) ;
V_55 -> V_101 = V_104 ;
F_7 ( & V_55 -> V_30 ) ;
return V_14 ;
default:
return V_103 ;
}
}
static int F_76 ( struct V_97 * V_7 , int V_98 , void * V_99 ,
struct V_100 * V_55 )
{
struct V_105 * V_106 = V_99 ;
switch ( V_98 ) {
case V_84 :
F_5 ( & V_55 -> V_30 ) ;
if ( V_55 -> V_101 != V_107 &&
V_55 -> V_101 != V_104 ) {
F_7 ( & V_55 -> V_30 ) ;
F_40 ( L_27 ) ;
return V_108 ;
}
V_55 -> V_101 = V_109 ;
F_7 ( & V_55 -> V_30 ) ;
V_55 -> V_110 = F_49 ( V_106 ) ;
V_55 -> V_111 = false ;
F_57 ( L_28 ,
V_55 -> V_110 ) ;
F_77 ( V_112 , & V_55 -> V_96 ) ;
return V_14 ;
case V_113 :
F_57 ( L_29 ) ;
F_5 ( & V_55 -> V_30 ) ;
F_56 ( V_55 -> V_110 , V_106 ) ;
F_7 ( & V_55 -> V_30 ) ;
return V_14 ;
default:
return V_103 ;
}
}
static int F_78 ( struct V_97 * V_7 , int V_98 , void * V_99 ,
struct V_100 * V_55 )
{
switch ( V_98 ) {
case V_102 :
F_5 ( & V_55 -> V_30 ) ;
if ( V_55 -> V_101 != V_107 ) {
F_7 ( & V_55 -> V_30 ) ;
F_57 ( L_30 ) ;
return V_108 ;
}
V_55 -> V_101 = V_109 ;
F_7 ( & V_55 -> V_30 ) ;
V_55 -> V_111 = true ;
F_57 ( L_31 ) ;
F_77 ( V_112 , & V_55 -> V_96 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_103 ;
}
}
static int F_79 ( struct V_97 * V_7 ,
int V_98 , void * V_99 , struct V_100 * V_55 )
{
switch ( V_98 ) {
case V_102 :
F_57 ( L_32 ) ;
return V_14 ;
case V_8 :
return V_14 ;
default:
return V_103 ;
}
}
static void F_80 ( struct V_97 * V_7 , struct V_114 * V_115 ,
int V_98 , int V_116 , int V_117 , int V_10 ,
unsigned long long V_82 , void * V_99 , T_3 V_80 ,
void * V_118 )
{
struct V_100 * V_55 = V_118 ;
struct V_15 * V_20 = V_55 -> V_29 -> V_20 ;
int V_119 , V_120 , V_121 ;
F_5 ( & V_20 -> V_30 ) ;
V_119 = V_20 -> V_10 ;
V_120 = V_20 -> V_74 ;
F_7 ( & V_20 -> V_30 ) ;
if ( V_10 != V_119 ) {
F_40 ( L_33 ) ;
V_121 = V_103 ;
goto V_122;
}
if ( V_117 != V_120 ) {
F_40 ( L_34 ,
V_117 , V_120 ) ;
V_121 = V_103 ;
goto V_122;
}
V_82 -= V_55 -> V_81 . V_82 ;
if ( V_82 == 0x00 && V_80 == 4 ) {
V_121 = F_74 ( V_7 , V_98 , V_99 , V_55 ) ;
} else if ( V_82 == 0x04 && V_80 == 4 ) {
V_121 = F_75 ( V_7 , V_98 , V_99 , V_55 ) ;
} else if ( V_82 == 0x08 && V_80 == 8 ) {
V_121 = F_76 ( V_7 , V_98 , V_99 , V_55 ) ;
} else if ( V_82 == 0x10 && V_80 == 4 ) {
V_121 = F_78 ( V_7 , V_98 , V_99 , V_55 ) ;
} else if ( V_82 == 0x14 && V_80 == 4 ) {
V_121 = F_79 ( V_7 , V_98 ,
V_99 , V_55 ) ;
} else {
V_121 = V_123 ;
}
V_122:
F_81 ( V_7 , V_115 , V_121 ) ;
}
static void F_82 ( struct V_95 * V_96 )
{
struct V_124 * V_3 =
F_72 ( V_96 , struct V_124 , V_96 ) ;
F_57 ( L_35 ,
V_3 -> V_110 ,
F_49 ( & V_3 -> V_62 . V_125 ) ,
F_49 ( & V_3 -> V_62 . V_126 ) ,
F_3 ( V_3 -> V_62 . V_63 ) ) ;
if ( V_3 -> V_110 >> 32 )
F_57 ( L_36 ) ;
switch ( F_83 ( F_3 ( V_3 -> V_62 . V_63 ) ) ) {
case 0 :
F_84 ( V_3 ) ;
return;
case 1 :
case 2 :
V_3 -> V_64 . V_64 |= F_41 (
F_42 (
V_65 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 (
V_87 ) ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
return;
case 3 :
V_3 -> V_64 . V_64 |= F_41 (
F_42 (
V_65 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 (
V_127 ) ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
return;
default:
F_89 () ;
}
}
static inline bool F_90 ( struct V_100 * V_55 )
{
bool V_128 ;
F_5 ( & V_55 -> V_30 ) ;
V_128 = ( V_55 -> V_101 == V_109 ) ;
F_7 ( & V_55 -> V_30 ) ;
return V_128 ;
}
static void F_91 ( struct V_95 * V_96 )
{
struct V_100 * V_55 =
F_72 ( V_96 , struct V_100 , V_96 ) ;
struct V_15 * V_20 = V_55 -> V_29 -> V_20 ;
struct V_124 * V_3 ;
int V_4 ;
bool V_111 = V_55 -> V_111 ;
T_1 V_125 = V_55 -> V_110 ;
while ( V_125 && F_90 ( V_55 ) ) {
V_3 = F_53 ( sizeof( * V_3 ) , V_45 ) ;
if ( ! V_3 ) {
F_5 ( & V_55 -> V_30 ) ;
V_55 -> V_101 = V_129 ;
F_7 ( & V_55 -> V_30 ) ;
return;
}
V_3 -> V_29 = V_55 -> V_29 ;
V_3 -> V_110 = V_125 ;
V_3 -> V_64 . V_64 = F_41 ( F_92 (
V_3 -> V_110 >> 32 ) ) ;
V_3 -> V_64 . V_130 = F_41 (
V_3 -> V_110 & 0xfffffffc ) ;
V_4 = F_2 ( V_20 -> V_7 , V_113 ,
V_20 -> V_74 , V_20 -> V_10 , V_20 -> V_11 ,
V_3 -> V_110 , & V_3 -> V_62 , sizeof( V_3 -> V_62 ) ) ;
if ( V_4 != V_14 ) {
F_57 ( L_37 , V_4 ) ;
V_3 -> V_64 . V_64 |= F_41 (
F_93 (
V_131 ) |
F_42 (
V_67 ) |
F_85 ( 1 ) |
F_86 ( 1 ) |
F_43 (
V_68 ) ) ;
F_5 ( & V_55 -> V_30 ) ;
V_55 -> V_101 = V_129 ;
F_7 ( & V_55 -> V_30 ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
return;
}
if ( F_3 ( V_3 -> V_62 . V_125 . V_5 ) & 0x80000000 ) {
V_125 = 0 ;
V_3 -> V_64 . V_64 |= F_41 ( F_93 (
V_131 ) ) ;
} else {
V_125 = F_49 ( & V_3 -> V_62 . V_125 ) ;
V_3 -> V_64 . V_64 |= F_41 ( F_93 (
V_132 ) ) ;
}
if ( F_90 ( V_55 ) && ! V_111 ) {
F_94 ( & V_3 -> V_96 , F_82 ) ;
F_77 ( V_112 , & V_3 -> V_96 ) ;
} else {
F_88 ( V_3 ) ;
}
F_5 ( & V_55 -> V_30 ) ;
V_111 = V_55 -> V_111 = false ;
if ( V_125 )
V_55 -> V_110 = V_125 ;
else
V_55 -> V_101 = V_107 ;
F_7 ( & V_55 -> V_30 ) ;
} ;
}
static struct V_100 * F_51 (
struct V_25 * V_29 )
{
struct V_100 * V_55 ;
int V_4 ;
V_55 = F_16 ( sizeof( * V_55 ) , V_45 ) ;
if ( ! V_55 )
return F_12 ( - V_46 ) ;
F_25 ( & V_55 -> V_30 ) ;
V_55 -> V_81 . V_80 = 0x20 ;
V_55 -> V_81 . V_133 = F_80 ;
V_55 -> V_81 . V_118 = V_55 ;
V_55 -> V_29 = V_29 ;
V_55 -> V_101 = V_104 ;
F_94 ( & V_55 -> V_96 , F_91 ) ;
V_55 -> V_110 = 0 ;
V_55 -> V_111 = false ;
V_4 = F_95 ( & V_55 -> V_81 ,
& V_134 ) ;
if ( V_4 < 0 ) {
F_21 ( V_55 ) ;
return F_12 ( V_4 ) ;
}
return V_55 ;
}
static void F_36 ( struct V_100 * V_55 )
{
F_96 ( & V_55 -> V_81 ) ;
F_97 ( & V_55 -> V_96 ) ;
F_21 ( V_55 ) ;
}
static int F_2 ( struct V_97 * V_7 , int V_98 , int V_135 ,
int V_10 , int V_11 , unsigned long long V_82 ,
void * V_136 , T_3 V_80 )
{
int V_137 , V_4 , V_138 ;
for ( V_137 = 1 ; V_137 <= 5 ; V_137 ++ ) {
V_4 = F_98 ( V_7 , V_98 , V_135 ,
V_10 , V_11 , V_82 , V_136 , V_80 ) ;
switch ( V_4 ) {
case V_14 :
case V_103 :
case V_123 :
case V_139 :
return V_4 ;
default:
V_138 = 5 * V_137 * V_137 ;
F_99 ( V_138 , V_138 * 2 ) ;
}
}
return V_4 ;
}
static int F_100 ( struct V_124 * V_3 ,
int V_98 , unsigned long long V_82 , void * V_136 ,
T_3 V_80 )
{
struct V_25 * V_29 = V_3 -> V_29 ;
struct V_15 * V_20 = V_29 -> V_20 ;
struct V_97 * V_7 ;
int V_74 , V_10 , V_11 , V_4 ;
F_5 ( & V_20 -> V_30 ) ;
V_7 = F_45 ( V_20 -> V_7 ) ;
V_74 = V_20 -> V_74 ;
V_10 = V_20 -> V_10 ;
V_11 = V_20 -> V_11 ;
F_7 ( & V_20 -> V_30 ) ;
V_4 = F_2 ( V_7 , V_98 , V_74 , V_10 , V_11 ,
V_82 , V_136 , V_80 ) ;
F_34 ( V_7 ) ;
return V_4 ;
}
static int F_101 ( struct V_124 * V_3 )
{
int V_4 , V_140 , V_141 ;
V_140 = F_102 ( V_3 -> V_62 . V_142 ) ;
V_3 -> V_143 = F_16 ( V_140 , V_45 ) ;
if ( ! V_3 -> V_143 )
return - V_46 ;
memcpy ( V_3 -> V_143 , V_3 -> V_62 . V_142 ,
F_103 ( int , V_140 , sizeof( V_3 -> V_62 . V_142 ) ) ) ;
if ( V_140 > sizeof( V_3 -> V_62 . V_142 ) ) {
F_57 ( L_38 ) ;
V_141 = V_140 - sizeof( V_3 -> V_62 . V_142 ) ;
V_4 = F_100 ( V_3 ,
V_113 ,
V_3 -> V_110 + sizeof( V_3 -> V_62 ) ,
V_3 -> V_143 + sizeof( V_3 -> V_62 . V_142 ) ,
V_141 ) ;
if ( V_4 != V_14 )
return - V_144 ;
}
return 0 ;
}
static int F_104 ( struct V_124 * V_3 )
{
int V_145 , V_4 ;
struct V_146 * V_147 ;
if ( ! F_105 ( F_3 ( V_3 -> V_62 . V_63 ) ) )
return 0 ;
V_145 = F_106 ( F_3 ( V_3 -> V_62 . V_63 ) ) *
sizeof( struct V_146 ) ;
V_147 = F_16 ( V_145 , V_45 ) ;
if ( ! V_147 )
return - V_46 ;
V_4 = F_100 ( V_3 , V_113 ,
F_49 ( & V_3 -> V_62 . V_126 ) ,
V_147 , V_145 ) ;
if ( V_4 != V_14 ) {
F_21 ( V_147 ) ;
return - V_144 ;
}
V_3 -> V_147 = V_147 ;
return 0 ;
}
static void F_107 ( struct V_124 * V_3 ,
T_4 * V_148 , enum V_149 * V_150 )
{
int V_151 , V_152 , V_153 ;
V_151 = F_106 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
V_152 = F_108 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
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
static void F_84 ( struct V_124 * V_3 )
{
struct V_25 * V_29 = V_3 -> V_29 ;
struct V_15 * V_20 = V_29 -> V_20 ;
int V_4 , V_69 ;
T_4 V_158 ;
enum V_149 V_150 ;
V_4 = F_101 ( V_3 ) ;
if ( V_4 ) {
F_57 ( L_39 , V_4 ) ;
goto V_159;
}
V_4 = F_104 ( V_3 ) ;
if ( V_4 ) {
F_57 ( L_40 ,
V_4 ) ;
goto V_159;
}
V_69 = V_3 -> V_29 -> V_28 -> V_69 ;
F_107 ( V_3 , & V_158 , & V_150 ) ;
F_57 ( L_41 ,
V_3 -> V_110 , V_69 , V_158 , V_150 ) ;
if ( F_110 ( & V_3 -> V_160 , V_20 -> V_19 , V_3 -> V_143 ,
V_3 -> V_161 , V_69 , V_158 ,
V_162 , V_150 , 0 ) )
goto V_159;
return;
V_159:
V_3 -> V_64 . V_64 |= F_41 (
F_42 ( V_67 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_68 ) ) ;
F_87 ( V_3 ) ;
F_88 ( V_3 ) ;
}
static int F_111 ( struct V_124 * V_3 )
{
struct V_15 * V_20 = V_3 -> V_29 -> V_20 ;
int V_98 , V_163 , V_164 , V_165 , V_11 , V_74 ,
V_10 , V_166 , V_80 , V_167 ,
V_121 = V_14 ;
struct V_146 * V_168 ;
unsigned long long V_82 ;
struct V_97 * V_7 ;
struct V_169 V_170 ;
if ( V_3 -> V_160 . V_171 == V_155 ) {
V_98 = V_84 ;
V_163 = V_172 ;
} else {
V_98 = V_113 ;
V_163 = V_173 ;
}
V_164 = 4 << F_112 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
V_11 = F_113 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
V_165 = F_114 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
if ( V_165 ) {
F_17 ( L_42 ) ;
V_165 = 0x100 << V_165 ;
}
F_5 ( & V_20 -> V_30 ) ;
V_7 = F_45 ( V_20 -> V_7 ) ;
V_74 = V_20 -> V_74 ;
V_10 = V_20 -> V_10 ;
F_7 ( & V_20 -> V_30 ) ;
if ( V_3 -> V_147 ) {
V_168 = V_3 -> V_147 ;
V_166 = F_106 ( F_3 ( V_3 -> V_62 . V_63 ) ) ;
V_82 = 0 ;
V_80 = 0 ;
} else {
V_168 = NULL ;
V_166 = 0 ;
V_82 = F_49 ( & V_3 -> V_62 . V_126 ) ;
V_80 = V_3 -> V_160 . V_158 ;
}
F_115 ( & V_170 , V_3 -> V_160 . V_174 , V_3 -> V_160 . V_175 ,
V_163 ) ;
while ( V_80 || V_166 ) {
if ( ! V_80 ) {
V_82 = ( T_1 ) F_109 ( V_168 -> V_176 ) << 32 |
F_3 ( V_168 -> V_177 ) ;
V_80 = F_109 ( V_168 -> V_157 ) ;
V_168 ++ ;
V_166 -- ;
}
F_116 ( & V_170 ) ;
V_167 = F_117 ( V_80 , V_164 , ( int ) V_170 . V_80 ) ;
V_121 = F_2 ( V_7 , V_98 , V_74 ,
V_10 , V_11 ,
V_82 , V_170 . V_178 , V_167 ) ;
if ( V_121 != V_14 )
break;
V_80 -= V_167 ;
V_82 += V_167 ;
V_170 . V_179 = V_167 ;
}
F_118 ( & V_170 ) ;
F_34 ( V_7 ) ;
if ( V_121 == V_14 ) {
F_119 ( V_80 != 0 ) ;
return 0 ;
} else {
return - V_144 ;
}
}
static int F_87 ( struct V_124 * V_3 )
{
int V_4 , V_80 ;
struct V_25 * V_29 = V_3 -> V_29 ;
V_80 = ( ( ( F_3 ( V_3 -> V_64 . V_64 ) >> 24 ) & 0x07 ) + 1 ) * 4 ;
V_4 = F_100 ( V_3 , V_84 ,
V_29 -> V_78 , & V_3 -> V_64 , V_80 ) ;
if ( V_4 != V_14 ) {
F_57 ( L_43 , V_4 ) ;
return - V_144 ;
}
F_57 ( L_44 ,
V_3 -> V_110 ) ;
return 0 ;
}
static void F_120 ( struct V_124 * V_3 )
{
struct V_160 * V_160 = & V_3 -> V_160 ;
T_5 * V_180 = V_3 -> V_161 ;
T_5 * V_64 = V_3 -> V_64 . V_99 ;
F_119 ( V_160 -> V_181 < 18 ) ;
switch ( V_180 [ 0 ] & 0x7f ) {
case 0x70 :
V_64 [ 0 ] = 0 << 6 ;
break;
case 0x71 :
V_64 [ 0 ] = 1 << 6 ;
break;
case 0x72 :
case 0x73 :
default:
F_17 ( L_45 ,
V_180 [ 0 ] ) ;
V_3 -> V_64 . V_64 |= F_41 (
F_42 ( V_65 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_182 ) ) ;
return;
}
V_64 [ 0 ] |= V_160 -> V_183 & 0x3f ;
V_64 [ 1 ] =
( V_180 [ 0 ] & 0x80 ) |
( ( V_180 [ 2 ] & 0xe0 ) >> 1 ) |
( V_180 [ 2 ] & 0x0f ) ;
V_64 [ 2 ] = V_160 -> V_184 ;
V_64 [ 3 ] = V_160 -> V_185 ;
V_64 [ 4 ] = V_180 [ 3 ] ;
V_64 [ 5 ] = V_180 [ 4 ] ;
V_64 [ 6 ] = V_180 [ 5 ] ;
V_64 [ 7 ] = V_180 [ 6 ] ;
V_64 [ 8 ] = V_180 [ 8 ] ;
V_64 [ 9 ] = V_180 [ 9 ] ;
V_64 [ 10 ] = V_180 [ 10 ] ;
V_64 [ 11 ] = V_180 [ 11 ] ;
V_64 [ 12 ] = V_180 [ 14 ] ;
V_64 [ 13 ] = V_180 [ 15 ] ;
V_64 [ 14 ] = V_180 [ 16 ] ;
V_64 [ 15 ] = V_180 [ 17 ] ;
V_3 -> V_64 . V_64 |= F_41 (
F_42 ( V_65 ) |
F_85 ( 0 ) |
F_86 ( 5 ) |
F_43 ( V_86 ) ) ;
}
static int F_121 ( struct V_124 * V_3 )
{
struct V_160 * V_160 = & V_3 -> V_160 ;
if ( V_160 -> V_181 ) {
F_120 ( V_3 ) ;
} else {
V_3 -> V_64 . V_64 |= F_41 (
F_42 ( V_65 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_86 ) ) ;
}
return F_87 ( V_3 ) ;
}
static void F_88 ( struct V_124 * V_3 )
{
F_21 ( V_3 -> V_147 ) ;
F_21 ( V_3 -> V_143 ) ;
F_21 ( V_3 ) ;
}
static void F_122 ( struct V_95 * V_96 )
{
struct V_54 * V_55 =
F_72 ( V_96 , struct V_54 , V_96 ) ;
struct V_2 * V_3 = V_55 -> V_115 ;
int V_4 ;
int V_186 = 0 ;
V_4 = F_2 ( V_3 -> V_7 , V_113 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
V_55 -> V_187 , & V_3 -> V_62 , sizeof( V_3 -> V_62 ) ) ;
if ( V_4 != V_14 ) {
F_57 ( L_46 , V_4 ) ;
goto V_122;
}
F_57 ( L_47 ,
F_49 ( & V_3 -> V_62 . V_188 ) ,
F_49 ( & V_3 -> V_62 . V_85 ) ,
F_3 ( V_3 -> V_62 . V_63 ) , F_3 ( V_3 -> V_62 . V_80 ) ,
F_49 ( & V_3 -> V_62 . V_79 ) ) ;
if ( ! F_123 ( F_3 ( V_3 -> V_62 . V_63 ) ) ||
F_83 ( F_3 ( V_3 -> V_62 . V_63 ) ) != 0 ) {
F_17 ( L_48 ) ;
goto V_122;
}
switch ( F_124 ( F_3 ( V_3 -> V_62 . V_63 ) ) ) {
case V_189 :
F_38 ( V_55 , V_3 , & V_186 ) ;
break;
case V_190 :
F_58 ( V_55 , V_3 ,
& V_186 ) ;
break;
case V_191 :
F_59 ( V_55 , V_3 , & V_186 ) ;
break;
case V_192 :
F_40 ( L_49 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_87 ) ) ;
break;
case V_193 :
F_61 ( V_55 , V_3 , & V_186 ) ;
break;
case V_194 :
F_40 ( L_50 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_87 ) ) ;
break;
case V_195 :
F_40 ( L_51 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_87 ) ) ;
break;
case V_196 :
F_40 ( L_52 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_87 ) ) ;
break;
case V_197 :
F_40 ( L_53 ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_87 ) ) ;
break;
default:
F_40 ( L_54 ,
F_124 ( F_3 ( V_3 -> V_62 . V_63 ) ) ) ;
V_3 -> V_64 . V_64 = F_41 (
F_42 ( V_65 ) |
F_43 ( V_87 ) ) ;
break;
}
V_3 -> V_64 . V_64 |= F_41 (
F_93 ( 1 ) |
F_86 ( F_125 ( V_186 , 4 ) + 1 ) |
F_92 ( V_55 -> V_187 >> 32 ) ) ;
V_3 -> V_64 . V_130 = F_41 ( V_55 -> V_187 ) ;
V_4 = F_2 ( V_3 -> V_7 , V_84 ,
V_3 -> V_9 , V_3 -> V_10 , V_3 -> V_11 ,
F_49 ( & V_3 -> V_62 . V_79 ) ,
& V_3 -> V_64 , 8 + V_186 ) ;
if ( V_4 != V_14 ) {
F_57 ( L_55 , V_4 ) ;
goto V_122;
}
V_122:
F_34 ( V_3 -> V_7 ) ;
F_21 ( V_3 ) ;
F_5 ( & V_55 -> V_30 ) ;
V_55 -> V_101 = V_198 ;
F_7 ( & V_55 -> V_30 ) ;
}
static void F_126 ( struct V_97 * V_7 ,
struct V_114 * V_115 , int V_98 , int V_116 , int V_117 ,
int V_10 , unsigned long long V_82 , void * V_99 , T_3 V_80 ,
void * V_118 )
{
struct V_54 * V_55 = V_118 ;
struct V_105 * V_106 = V_99 ;
int V_121 = V_123 ;
if ( ! V_55 -> V_58 -> V_199 )
goto V_122;
if ( ( V_82 != V_55 -> V_81 . V_82 ) || ( V_80 != 8 ) )
goto V_122;
if ( V_98 == V_84 ) {
struct V_2 * V_3 ;
int V_200 ;
F_5 ( & V_55 -> V_30 ) ;
V_200 = V_55 -> V_101 ;
V_55 -> V_101 = V_201 ;
F_7 ( & V_55 -> V_30 ) ;
if ( V_200 == V_201 ) {
F_40 ( L_56 ) ;
V_121 = V_108 ;
goto V_122;
}
V_3 = F_53 ( sizeof( * V_3 ) , V_202 ) ;
if ( ! V_3 ) {
V_121 = V_108 ;
goto V_122;
}
V_3 -> V_7 = F_45 ( V_7 ) ;
V_3 -> V_10 = V_10 ;
V_3 -> V_9 = V_117 ;
V_3 -> V_11 = F_127 ( V_115 ) ;
V_55 -> V_187 = F_49 ( V_106 ) ;
V_55 -> V_115 = V_3 ;
F_77 ( V_112 , & V_55 -> V_96 ) ;
V_121 = V_14 ;
} else if ( V_98 == V_113 ) {
F_56 ( V_55 -> V_187 , V_106 ) ;
V_121 = V_14 ;
} else {
V_121 = V_103 ;
}
V_122:
F_81 ( V_7 , V_115 , V_121 ) ;
}
static struct V_54 * F_128 (
struct V_57 * V_58 )
{
int V_4 ;
struct V_54 * V_55 ;
V_55 = F_16 ( sizeof( * V_55 ) , V_45 ) ;
if ( ! V_55 )
return F_12 ( - V_46 ) ;
F_25 ( & V_55 -> V_30 ) ;
V_55 -> V_58 = V_58 ;
V_55 -> V_81 . V_80 = 0x08 ;
V_55 -> V_81 . V_133 = F_126 ;
V_55 -> V_81 . V_118 = V_55 ;
V_55 -> V_101 = V_198 ;
F_94 ( & V_55 -> V_96 , F_122 ) ;
V_55 -> V_187 = 0 ;
V_55 -> V_115 = NULL ;
V_4 = F_95 ( & V_55 -> V_81 ,
& V_134 ) ;
if ( V_4 < 0 ) {
F_21 ( V_55 ) ;
return F_12 ( V_4 ) ;
}
return V_55 ;
}
static void F_129 ( struct V_54 * V_55 )
{
F_96 ( & V_55 -> V_81 ) ;
F_97 ( & V_55 -> V_96 ) ;
F_21 ( V_55 ) ;
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
struct V_57 * V_58 = V_17 -> V_58 ;
return & V_58 -> V_203 [ 0 ] ;
}
static T_6 F_134 ( struct V_34 * V_22 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
return V_17 -> V_204 ;
}
static T_4 F_135 ( struct V_34 * V_22 )
{
return 1 ;
}
static struct V_43 * F_136 ( struct V_34 * V_22 )
{
struct V_205 * V_206 ;
V_206 = F_53 ( sizeof( struct V_205 ) , V_45 ) ;
if ( ! V_206 ) {
F_17 ( L_58 ) ;
return NULL ;
}
return & V_206 -> V_43 ;
}
static void F_137 (
struct V_34 * V_22 ,
struct V_43 * V_44 )
{
struct V_205 * V_206 =
F_72 ( V_44 , struct V_205 , V_43 ) ;
F_21 ( V_206 ) ;
}
static T_4 F_138 ( struct V_34 * V_22 )
{
return 1 ;
}
static void F_139 ( struct V_160 * V_160 )
{
struct V_124 * V_3 = F_72 ( V_160 ,
struct V_124 , V_160 ) ;
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
static int F_143 ( struct V_160 * V_160 )
{
struct V_124 * V_3 = F_72 ( V_160 ,
struct V_124 , V_160 ) ;
int V_4 ;
V_4 = F_111 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_64 . V_64 |= F_41 (
F_42 (
V_67 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 (
V_68 ) ) ;
F_87 ( V_3 ) ;
return V_4 ;
}
F_144 ( V_160 ) ;
return 0 ;
}
static int F_145 ( struct V_160 * V_160 )
{
return 0 ;
}
static void F_146 ( struct V_43 * V_206 )
{
return;
}
static T_4 F_147 ( struct V_160 * V_160 )
{
struct V_124 * V_3 = F_72 ( V_160 ,
struct V_124 , V_160 ) ;
return ( T_4 ) V_3 -> V_110 ;
}
static int F_148 ( struct V_160 * V_160 )
{
return 0 ;
}
static int F_149 ( struct V_160 * V_160 )
{
struct V_124 * V_3 = F_72 ( V_160 ,
struct V_124 , V_160 ) ;
int V_4 ;
V_4 = F_111 ( V_3 ) ;
if ( V_4 ) {
V_3 -> V_64 . V_64 |= F_41 (
F_42 ( V_67 ) |
F_85 ( 0 ) |
F_86 ( 1 ) |
F_43 ( V_68 ) ) ;
F_87 ( V_3 ) ;
return V_4 ;
}
return F_121 ( V_3 ) ;
}
static int F_150 ( struct V_160 * V_160 )
{
struct V_124 * V_3 = F_72 ( V_160 ,
struct V_124 , V_160 ) ;
return F_121 ( V_3 ) ;
}
static int F_151 ( struct V_160 * V_160 )
{
return 0 ;
}
static int F_152 ( struct V_160 * V_160 )
{
struct V_124 * V_3 = F_72 ( V_160 ,
struct V_124 , V_160 ) ;
F_153 ( & V_3 -> V_160 , 0 ) ;
return 1 ;
}
static T_5 F_154 ( struct V_34 * V_22 )
{
return V_207 ;
}
static T_4 F_155 (
struct V_34 * V_22 ,
struct V_43 * V_44 ,
struct V_208 * V_209 ,
int * V_210 ,
unsigned char * V_211 )
{
int V_4 ;
V_211 [ 0 ] = V_207 ;
V_4 = F_156 ( & V_211 [ 8 ] , V_44 -> V_212 , 8 ) ;
if ( V_4 < 0 )
F_57 ( L_59 ) ;
return 24 ;
}
static T_4 F_157 (
struct V_34 * V_22 ,
struct V_43 * V_44 ,
struct V_208 * V_209 ,
int * V_210 )
{
* V_210 = 0 ;
return 24 ;
}
static char * F_158 (
struct V_34 * V_22 ,
const char * V_211 ,
T_4 * V_213 ,
char * * V_214 )
{
* V_214 = NULL ;
* V_213 = 24 ;
return ( char * ) & V_211 [ 8 ] ;
}
static int F_159 ( struct V_34 * V_17 )
{
int V_215 , V_32 = 0 ;
F_13 ( & V_17 -> V_37 ) ;
for ( V_215 = 0 ; V_215 < V_35 ; V_215 ++ ) {
struct V_27 * V_27 = V_17 -> V_38 [ V_215 ] ;
if ( V_27 -> V_39 == V_216 )
continue;
V_32 ++ ;
}
F_14 ( & V_17 -> V_37 ) ;
return V_32 ;
}
static int F_160 ( struct V_57 * V_58 )
{
int V_217 , V_218 , V_153 = 0 , V_219 , V_4 , V_215 ;
T_4 * V_99 ;
if ( V_58 -> V_220 . V_99 ) {
F_161 ( & V_58 -> V_220 ) ;
F_21 ( V_58 -> V_220 . V_99 ) ;
V_58 -> V_220 . V_99 = NULL ;
}
if ( ! V_58 -> V_199 || ! V_58 -> V_17 )
return 0 ;
V_217 = F_159 ( & V_58 -> V_17 -> V_22 ) ;
V_218 = F_162 ( V_221 ) + 4 + V_217 ;
if ( V_58 -> V_222 != - 1 )
V_218 ++ ;
V_99 = F_163 ( ( V_218 + 4 ) , sizeof( T_4 ) , V_45 ) ;
if ( ! V_99 )
return - V_46 ;
V_99 [ V_153 ++ ] = V_218 << 16 ;
if ( V_58 -> V_222 != - 1 )
V_99 [ V_153 ++ ] = ( V_223 << 24 ) | V_58 -> V_222 ;
memcpy ( & V_99 [ V_153 ] , V_221 ,
sizeof( V_221 ) ) ;
V_153 += F_162 ( V_221 ) ;
V_219 = ( V_58 -> V_224 -> V_81 . V_82 - V_12 ) / 4 ;
V_99 [ V_153 ++ ] = 0x54000000 | ( V_219 & 0x00ffffff ) ;
V_99 [ V_153 ++ ] = 0x3a000000 |
( ( ( V_58 -> V_225 * 2 ) << 8 ) & 0xff00 ) |
V_226 ;
V_99 [ V_153 ++ ] = 0x3d000000 | ( V_58 -> V_77 & 0xffff ) ;
V_99 [ V_153 ++ ] = 0x8d000000 | ( V_217 + 1 ) ;
F_13 ( & V_58 -> V_17 -> V_22 . V_37 ) ;
for ( V_215 = 0 ; V_215 < V_35 ; V_215 ++ ) {
struct V_27 * V_27 = V_58 -> V_17 -> V_22 . V_38 [ V_215 ] ;
struct V_227 * V_228 ;
int type ;
if ( V_27 -> V_39 == V_216 )
continue;
F_14 ( & V_58 -> V_17 -> V_22 . V_37 ) ;
V_228 = V_27 -> V_229 ;
type = V_228 -> V_230 -> V_231 ( V_228 ) ;
V_99 [ V_153 ++ ] = 0x14000000 |
( ( type << 16 ) & 0x1f0000 ) |
( V_27 -> V_69 & 0xffff ) ;
F_13 ( & V_58 -> V_17 -> V_22 . V_37 ) ;
}
F_14 ( & V_58 -> V_17 -> V_22 . V_37 ) ;
V_99 [ V_153 ++ ] = 2 << 16 ;
V_99 [ V_153 ++ ] = V_58 -> V_1 >> 32 ;
V_99 [ V_153 ++ ] = V_58 -> V_1 ;
V_58 -> V_220 . V_80 = V_153 ;
V_58 -> V_220 . V_232 = ( V_233 | V_234 ) << 24 ;
V_58 -> V_220 . V_99 = V_99 ;
V_4 = F_164 ( & V_58 -> V_220 ) ;
if ( V_4 < 0 ) {
F_21 ( V_58 -> V_220 . V_99 ) ;
V_58 -> V_220 . V_99 = NULL ;
}
return V_4 ;
}
static T_7 F_165 ( const char * V_235 , T_1 * V_236 )
{
const char * V_237 ;
char V_238 , V_239 ;
int V_240 = 0 , V_159 ;
* V_236 = 0 ;
for ( V_237 = V_235 ; V_237 < & V_235 [ V_241 - 1 ] ; V_237 ++ ) {
V_238 = * V_237 ;
if ( V_238 == '\n' && V_237 [ 1 ] == '\0' )
continue;
if ( V_238 == '\0' ) {
V_159 = 2 ;
if ( V_240 != 16 )
goto V_242;
return V_237 - V_235 ;
}
V_159 = 3 ;
if ( isdigit ( V_238 ) )
V_239 = V_238 - '0' ;
else if ( isxdigit ( V_238 ) )
V_239 = tolower ( V_238 ) - 'a' + 10 ;
else
goto V_242;
* V_236 = ( * V_236 << 4 ) | V_239 ;
V_240 ++ ;
}
V_159 = 4 ;
V_242:
F_166 ( V_243 L_60 ,
V_159 , V_237 - V_235 , V_240 ) ;
return - 1 ;
}
static T_7 F_167 ( char * V_211 , T_3 V_244 , T_1 V_236 )
{
return snprintf ( V_211 , V_244 , L_3 , V_236 ) ;
}
static struct V_43 * F_168 (
struct V_34 * V_22 ,
struct V_245 * V_246 ,
const char * V_235 )
{
struct V_43 * V_44 , * V_247 ;
struct V_205 * V_206 ;
T_1 V_1 = 0 ;
T_4 V_248 = 1 ;
if ( F_165 ( V_235 , & V_1 ) < 0 )
return F_12 ( - V_36 ) ;
V_247 = F_136 ( V_22 ) ;
if ( ! V_247 )
return F_12 ( - V_46 ) ;
V_44 = F_169 ( V_22 , V_247 ,
V_235 , V_248 ) ;
if ( F_19 ( V_44 ) ) {
F_137 ( V_22 , V_247 ) ;
return V_44 ;
}
V_206 = F_72 ( V_44 , struct V_205 , V_43 ) ;
V_206 -> V_1 = V_1 ;
F_167 ( V_206 -> V_249 , V_241 , V_1 ) ;
return V_44 ;
}
static void F_170 ( struct V_43 * V_250 )
{
struct V_205 * V_206 =
F_72 ( V_250 , struct V_205 , V_43 ) ;
F_171 ( V_250 -> V_22 , V_250 , 1 ) ;
F_21 ( V_206 ) ;
}
static int F_172 (
struct V_34 * V_22 ,
struct V_27 * V_27 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
return F_160 ( V_17 -> V_58 ) ;
}
static void F_173 (
struct V_34 * V_22 ,
struct V_27 * V_27 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
int V_4 ;
if ( F_159 ( & V_17 -> V_22 ) == 0 )
V_58 -> V_199 = 0 ;
V_4 = F_160 ( V_58 ) ;
if ( V_4 < 0 )
F_17 ( L_61 ) ;
}
static struct V_34 * F_174 (
struct V_251 * V_236 ,
struct V_245 * V_246 ,
const char * V_235 )
{
struct V_57 * V_58 =
F_72 ( V_236 , struct V_57 , V_252 ) ;
struct V_16 * V_17 ;
unsigned long V_253 ;
int V_4 ;
if ( strstr ( V_235 , L_62 ) != V_235 )
return F_12 ( - V_36 ) ;
if ( F_175 ( V_235 + 5 , 10 , & V_253 ) || V_253 > V_254 )
return F_12 ( - V_36 ) ;
if ( V_58 -> V_17 ) {
F_17 ( L_63 ) ;
return F_12 ( - V_255 ) ;
}
V_17 = F_53 ( sizeof( * V_17 ) , V_45 ) ;
if ( ! V_17 ) {
F_17 ( L_64 ) ;
return F_12 ( - V_46 ) ;
}
V_17 -> V_58 = V_58 ;
V_17 -> V_204 = V_253 ;
V_58 -> V_17 = V_17 ;
V_58 -> V_199 = 0 ;
V_58 -> V_222 = - 1 ;
V_58 -> V_225 = 15 ;
V_58 -> V_77 = 5 ;
V_58 -> V_72 = 1 ;
V_58 -> V_224 = F_128 ( V_58 ) ;
if ( F_19 ( V_58 -> V_224 ) ) {
V_4 = F_20 ( V_58 -> V_224 ) ;
F_21 ( V_17 ) ;
return F_12 ( V_4 ) ;
}
V_4 = F_176 ( & V_256 -> V_257 , V_236 ,
& V_17 -> V_22 , ( void * ) V_17 ,
V_258 ) ;
if ( V_4 < 0 ) {
F_129 ( V_58 -> V_224 ) ;
F_21 ( V_17 ) ;
return F_12 ( V_4 ) ;
}
return & V_17 -> V_22 ;
}
static void F_177 ( struct V_34 * V_22 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
F_178 ( V_22 ) ;
F_129 ( V_58 -> V_224 ) ;
V_58 -> V_17 = NULL ;
F_21 ( V_17 ) ;
}
static struct V_251 * F_179 (
struct V_259 * V_260 ,
struct V_245 * V_246 ,
const char * V_235 )
{
struct V_57 * V_58 ;
T_1 V_1 = 0 ;
if ( F_165 ( V_235 , & V_1 ) < 0 )
return F_12 ( - V_36 ) ;
V_58 = F_53 ( sizeof( * V_58 ) , V_45 ) ;
if ( ! V_58 ) {
F_17 ( L_65 ) ;
return F_12 ( - V_46 ) ;
}
V_58 -> V_1 = V_1 ;
F_167 ( V_58 -> V_203 , V_241 , V_1 ) ;
return & V_58 -> V_252 ;
}
static void F_180 ( struct V_251 * V_236 )
{
struct V_57 * V_58 =
F_72 ( V_236 , struct V_57 , V_252 ) ;
F_21 ( V_58 ) ;
}
static T_7 F_181 (
struct V_259 * V_260 ,
char * V_261 )
{
return sprintf ( V_261 , L_66 , V_262 ) ;
}
static T_7 F_182 (
struct V_34 * V_22 ,
char * V_261 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
if ( V_58 -> V_222 == - 1 )
return sprintf ( V_261 , L_67 ) ;
else
return sprintf ( V_261 , L_68 , V_58 -> V_222 ) ;
}
static T_7 F_183 (
struct V_34 * V_22 ,
const char * V_261 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
unsigned long V_263 ;
if ( V_58 -> V_199 ) {
F_17 ( L_69 ) ;
return - V_255 ;
}
if ( strstr ( V_261 , L_70 ) == V_261 ) {
V_58 -> V_222 = - 1 ;
} else {
if ( F_175 ( V_261 , 16 , & V_263 ) < 0 )
return - V_36 ;
if ( V_263 > 0xffffff )
return - V_36 ;
V_58 -> V_222 = V_263 ;
}
return V_32 ;
}
static T_7 F_184 (
struct V_34 * V_22 ,
char * V_261 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
return sprintf ( V_261 , L_71 , V_58 -> V_199 ) ;
}
static T_7 F_185 (
struct V_34 * V_22 ,
const char * V_261 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
unsigned long V_263 ;
int V_4 ;
if ( F_175 ( V_261 , 0 , & V_263 ) < 0 )
return - V_36 ;
if ( ( V_263 != 0 ) && ( V_263 != 1 ) )
return - V_36 ;
if ( V_58 -> V_199 == V_263 )
return V_32 ;
if ( V_263 ) {
if ( F_159 ( & V_17 -> V_22 ) == 0 ) {
F_17 ( L_72 ) ;
return - V_36 ;
}
} else {
F_5 ( & V_22 -> V_23 ) ;
if ( ! F_30 ( & V_22 -> V_264 ) ) {
F_7 ( & V_22 -> V_23 ) ;
return - V_255 ;
}
F_7 ( & V_22 -> V_23 ) ;
}
V_58 -> V_199 = V_263 ;
V_4 = F_160 ( V_58 ) ;
if ( V_4 < 0 ) {
F_17 ( L_73 ) ;
return V_4 ;
}
return V_32 ;
}
static T_7 F_186 (
struct V_34 * V_22 ,
char * V_261 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
return sprintf ( V_261 , L_71 , V_58 -> V_225 ) ;
}
static T_7 F_187 (
struct V_34 * V_22 ,
const char * V_261 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
unsigned long V_263 ;
int V_4 ;
if ( F_175 ( V_261 , 0 , & V_263 ) < 0 )
return - V_36 ;
if ( ( V_263 < 1 ) || ( V_263 > 127 ) )
return - V_36 ;
if ( V_58 -> V_225 == V_263 )
return V_32 ;
V_58 -> V_225 = V_263 ;
V_4 = F_160 ( V_58 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_188 (
struct V_34 * V_22 ,
char * V_261 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
return sprintf ( V_261 , L_71 , V_58 -> V_77 ) ;
}
static T_7 F_189 (
struct V_34 * V_22 ,
const char * V_261 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
unsigned long V_263 ;
int V_4 ;
if ( F_175 ( V_261 , 0 , & V_263 ) < 0 )
return - V_36 ;
if ( ( V_263 < 1 ) || ( V_263 > 32767 ) )
return - V_36 ;
if ( V_58 -> V_77 == V_263 )
return V_32 ;
V_58 -> V_77 = V_263 ;
V_4 = F_160 ( V_58 ) ;
if ( V_4 < 0 )
return V_4 ;
return V_32 ;
}
static T_7 F_190 (
struct V_34 * V_22 ,
char * V_261 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
return sprintf ( V_261 , L_71 , V_58 -> V_72 ) ;
}
static T_7 F_191 (
struct V_34 * V_22 ,
const char * V_261 ,
T_3 V_32 )
{
struct V_16 * V_17 = F_72 ( V_22 , struct V_16 , V_22 ) ;
struct V_57 * V_58 = V_17 -> V_58 ;
unsigned long V_263 ;
if ( F_175 ( V_261 , 0 , & V_263 ) < 0 )
return - V_36 ;
if ( ( V_263 < 1 ) || ( V_263 > 127 ) )
return - V_36 ;
V_58 -> V_72 = V_263 ;
return V_32 ;
}
static int F_192 ( void )
{
struct V_259 * V_265 ;
int V_4 ;
V_265 = F_193 ( V_266 , L_57 ) ;
if ( F_19 ( V_265 ) ) {
F_17 ( L_74 ) ;
return F_20 ( V_265 ) ;
}
V_265 -> V_257 = V_267 ;
F_194 ( V_265 ) -> V_268 . V_269 = V_270 ;
F_194 ( V_265 ) -> V_271 . V_269 = V_272 ;
F_194 ( V_265 ) -> V_273 . V_269 = V_274 ;
F_194 ( V_265 ) -> V_275 . V_269 = NULL ;
F_194 ( V_265 ) -> V_276 . V_269 = NULL ;
F_194 ( V_265 ) -> V_277 . V_269 = NULL ;
F_194 ( V_265 ) -> V_278 . V_269 = NULL ;
F_194 ( V_265 ) -> V_279 . V_269 = NULL ;
F_194 ( V_265 ) -> V_280 . V_269 = NULL ;
V_4 = F_195 ( V_265 ) ;
if ( V_4 < 0 ) {
F_17 ( L_75 ) ;
return V_4 ;
}
V_256 = V_265 ;
return 0 ;
}
static void F_196 ( void )
{
if ( ! V_256 )
return;
F_197 ( V_256 ) ;
V_256 = NULL ;
}
static int T_8 F_198 ( void )
{
int V_4 ;
V_4 = F_192 () ;
if ( V_4 < 0 )
return V_4 ;
return 0 ;
}
static void F_199 ( void )
{
F_196 () ;
}
