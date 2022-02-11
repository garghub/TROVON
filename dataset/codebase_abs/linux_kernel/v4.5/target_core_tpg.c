struct V_1 * F_1 (
struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
F_2 (acl, &tpg->acl_node_list, acl_list) {
if ( ! strcmp ( V_5 -> V_4 , V_4 ) )
return V_5 ;
}
return NULL ;
}
struct V_1 * F_3 (
struct V_2 * V_3 ,
unsigned char * V_4 )
{
struct V_1 * V_5 ;
F_4 ( & V_3 -> V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
if ( ! F_5 ( & V_5 -> V_7 ) )
V_5 = NULL ;
}
F_6 ( & V_3 -> V_6 ) ;
return V_5 ;
}
void F_7 (
struct V_1 * V_8 )
{
struct V_9 * V_10 ;
if ( ! V_8 )
return;
F_8 () ;
F_9 (deve, &nacl->lun_entry_hlist, link)
F_10 ( V_10 , 0x29 ,
V_11 ) ;
F_11 () ;
}
void F_12 (
struct V_1 * V_5 ,
struct V_2 * V_3 ,
struct V_12 * V_13 )
{
T_1 V_14 = 0 ;
struct V_12 * V_15 ;
struct V_16 * V_17 ;
F_4 ( & V_3 -> V_18 ) ;
F_9 (lun, &tpg->tpg_lun_hlist, link) {
if ( V_13 && V_15 != V_13 )
continue;
V_17 = F_13 ( V_15 -> V_19 ,
F_14 ( & V_3 -> V_18 ) ) ;
if ( ! V_3 -> V_20 -> V_21 ( V_3 ) ) {
V_14 = V_22 ;
} else {
if ( V_17 -> V_23 -> V_24 ( V_17 ) == V_25 )
V_14 = V_26 ;
else
V_14 = V_22 ;
}
F_15 ( L_1
L_2 ,
V_3 -> V_20 -> V_27 () ,
V_3 -> V_20 -> V_28 ( V_3 ) , V_15 -> V_29 ,
( V_14 == V_22 ) ?
L_3 : L_4 ) ;
F_16 ( V_15 , NULL , V_15 -> V_29 ,
V_14 , V_5 , V_3 ) ;
F_17 ( V_17 , V_3 , V_15 , V_5 ,
V_15 -> V_29 ) ;
}
F_6 ( & V_3 -> V_18 ) ;
}
static void
F_18 ( struct V_2 * V_3 ,
struct V_1 * V_5 , T_1 V_30 )
{
V_5 -> V_30 = V_30 ;
if ( ! V_5 -> V_30 ) {
F_19 ( L_5
L_6 , V_3 -> V_20 -> V_27 () ,
V_5 -> V_4 ) ;
V_5 -> V_30 = 1 ;
}
}
static struct V_1 * F_20 ( struct V_2 * V_3 ,
const unsigned char * V_4 )
{
struct V_1 * V_5 ;
T_1 V_30 ;
V_5 = F_21 ( F_22 ( sizeof( * V_5 ) , V_3 -> V_20 -> V_31 ) ,
V_32 ) ;
if ( ! V_5 )
return NULL ;
F_23 ( & V_5 -> V_33 ) ;
F_23 ( & V_5 -> V_34 ) ;
F_24 ( & V_5 -> V_35 ) ;
F_25 ( & V_5 -> V_7 ) ;
F_26 ( & V_5 -> V_36 ) ;
F_27 ( & V_5 -> V_37 ) ;
F_28 ( & V_5 -> V_38 ) ;
F_29 ( & V_5 -> V_39 , 0 ) ;
if ( V_3 -> V_20 -> V_40 )
V_30 = V_3 -> V_20 -> V_40 ( V_3 ) ;
else
V_30 = 1 ;
F_18 ( V_3 , V_5 , V_30 ) ;
snprintf ( V_5 -> V_4 , V_41 , L_7 , V_4 ) ;
V_5 -> V_42 = V_3 ;
V_5 -> V_43 = F_30 ( V_44 ) ;
V_3 -> V_20 -> V_45 ( V_5 ) ;
return V_5 ;
}
static void F_31 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_42 ;
F_4 ( & V_3 -> V_6 ) ;
F_32 ( & V_5 -> V_33 , & V_3 -> V_46 ) ;
F_6 ( & V_3 -> V_6 ) ;
F_15 ( L_8
L_9 ,
V_3 -> V_20 -> V_27 () ,
V_3 -> V_20 -> V_28 ( V_3 ) ,
V_5 -> V_47 ? L_10 : L_11 ,
V_5 -> V_30 ,
V_3 -> V_20 -> V_27 () ,
V_5 -> V_4 ) ;
}
bool F_33 ( struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
bool V_48 = false ;
F_4 ( & V_3 -> V_6 ) ;
F_2 (acl, &tpg->acl_node_list, acl_list) {
if ( ! strcmp ( V_5 -> V_4 , V_4 ) ) {
V_48 = true ;
break;
}
}
F_6 ( & V_3 -> V_6 ) ;
return V_48 ;
}
struct V_1 * F_34 (
struct V_2 * V_3 ,
unsigned char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_3 -> V_20 -> V_49 ( V_3 ) )
return NULL ;
V_5 = F_20 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
F_35 ( & V_5 -> V_7 ) ;
V_5 -> V_47 = 1 ;
if ( ( V_3 -> V_20 -> V_50 == NULL ) ||
( V_3 -> V_20 -> V_50 ( V_3 ) != 1 ) )
F_12 ( V_5 , V_3 , NULL ) ;
F_31 ( V_5 ) ;
return V_5 ;
}
void F_36 ( struct V_1 * V_8 )
{
while ( F_37 ( & V_8 -> V_39 ) != 0 )
F_38 () ;
}
struct V_1 * F_39 (
struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
F_4 ( & V_3 -> V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
if ( V_5 -> V_47 ) {
V_5 -> V_47 = 0 ;
F_15 ( L_12
L_13 , V_3 -> V_20 -> V_27 () ,
V_3 -> V_20 -> V_28 ( V_3 ) , V_4 ) ;
F_6 ( & V_3 -> V_6 ) ;
return V_5 ;
}
F_40 ( L_14
L_15
L_16 , V_3 -> V_20 -> V_27 () ,
V_4 , V_3 -> V_20 -> V_28 ( V_3 ) ) ;
F_6 ( & V_3 -> V_6 ) ;
return F_41 ( - V_51 ) ;
}
F_6 ( & V_3 -> V_6 ) ;
V_5 = F_20 ( V_3 , V_4 ) ;
if ( ! V_5 )
return F_41 ( - V_52 ) ;
F_31 ( V_5 ) ;
return V_5 ;
}
void F_42 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_42 ;
F_43 ( V_53 ) ;
struct V_54 * V_55 , * V_56 ;
unsigned long V_57 ;
int V_58 ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_5 -> V_47 ) {
V_5 -> V_47 = 0 ;
}
F_44 ( & V_5 -> V_33 ) ;
F_6 ( & V_3 -> V_6 ) ;
F_45 ( & V_5 -> V_37 , V_57 ) ;
V_5 -> V_59 = 1 ;
F_46 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_55 -> V_60 != 0 )
continue;
if ( ! F_47 ( V_55 ) )
continue;
F_48 ( & V_55 -> V_61 , & V_53 ) ;
}
F_49 ( & V_5 -> V_37 , V_57 ) ;
F_46 (sess, sess_tmp, &sess_list, sess_acl_list) {
F_44 ( & V_55 -> V_61 ) ;
V_58 = V_3 -> V_20 -> V_62 ( V_55 ) ;
F_50 ( V_55 ) ;
if ( ! V_58 )
continue;
F_50 ( V_55 ) ;
}
F_51 ( V_5 ) ;
F_52 ( & V_5 -> V_36 ) ;
F_36 ( V_5 ) ;
F_53 ( V_5 , V_3 ) ;
F_15 ( L_17
L_9 , V_3 -> V_20 -> V_27 () ,
V_3 -> V_20 -> V_28 ( V_3 ) , V_5 -> V_30 ,
V_3 -> V_20 -> V_27 () , V_5 -> V_4 ) ;
F_54 ( V_5 ) ;
}
int F_55 (
struct V_1 * V_5 ,
T_1 V_30 )
{
F_43 ( V_53 ) ;
struct V_2 * V_3 = V_5 -> V_42 ;
struct V_54 * V_55 , * V_56 ;
unsigned long V_57 ;
int V_58 ;
F_18 ( V_3 , V_5 , V_30 ) ;
F_45 ( & V_5 -> V_37 , V_57 ) ;
F_46 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_55 -> V_60 != 0 )
continue;
if ( ! F_47 ( V_55 ) )
continue;
F_49 ( & V_5 -> V_37 , V_57 ) ;
V_58 = V_3 -> V_20 -> V_62 ( V_55 ) ;
F_50 ( V_55 ) ;
if ( ! V_58 ) {
F_45 ( & V_5 -> V_37 , V_57 ) ;
continue;
}
F_50 ( V_55 ) ;
F_45 ( & V_5 -> V_37 , V_57 ) ;
}
F_49 ( & V_5 -> V_37 , V_57 ) ;
F_15 ( L_18
L_19 , V_5 -> V_30 ,
V_5 -> V_4 , V_3 -> V_20 -> V_27 () ,
V_3 -> V_20 -> V_28 ( V_3 ) ) ;
return 0 ;
}
int F_56 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
const char * V_63 )
{
if ( strlen ( V_63 ) >= V_64 )
return - V_65 ;
if ( ! strncmp ( L_20 , V_63 , 4 ) ) {
V_5 -> V_66 [ 0 ] = '\0' ;
return 0 ;
}
return snprintf ( V_5 -> V_66 , V_64 , L_7 , V_63 ) ;
}
static void F_57 ( struct V_67 * V_68 )
{
struct V_12 * V_15 = F_58 ( V_68 , struct V_12 , V_69 ) ;
F_59 ( & V_15 -> V_70 ) ;
}
int F_60 (
struct V_71 * V_71 ,
struct V_2 * V_42 ,
int V_72 )
{
int V_73 ;
if ( ! V_42 )
return - V_65 ;
if ( V_71 )
V_42 -> V_20 = V_71 -> V_74 -> V_75 ;
if ( ! V_42 -> V_20 ) {
F_40 ( L_21 ) ;
return - V_65 ;
}
F_24 ( & V_42 -> V_76 ) ;
V_42 -> V_72 = V_72 ;
V_42 -> V_77 = V_71 ;
F_29 ( & V_42 -> V_78 , 0 ) ;
F_23 ( & V_42 -> V_46 ) ;
F_23 ( & V_42 -> V_79 ) ;
F_23 ( & V_42 -> V_80 ) ;
F_27 ( & V_42 -> V_81 ) ;
F_28 ( & V_42 -> V_18 ) ;
F_28 ( & V_42 -> V_6 ) ;
if ( V_42 -> V_72 >= 0 ) {
V_42 -> V_82 = F_61 ( V_42 , 0 ) ;
if ( F_62 ( V_42 -> V_82 ) )
return F_63 ( V_42 -> V_82 ) ;
V_73 = F_64 ( V_42 , V_42 -> V_82 ,
V_26 , V_83 ) ;
if ( V_73 < 0 ) {
F_54 ( V_42 -> V_82 ) ;
return V_73 ;
}
}
F_65 ( & V_84 ) ;
F_32 ( & V_42 -> V_79 , & V_85 ) ;
F_66 ( & V_84 ) ;
F_15 ( L_22
L_23 , V_42 -> V_20 -> V_27 () ,
V_42 -> V_20 -> V_86 ( V_42 ) ?
V_42 -> V_20 -> V_86 ( V_42 ) : NULL ,
V_42 -> V_72 , V_42 -> V_20 -> V_28 ( V_42 ) ) ;
return 0 ;
}
int F_67 ( struct V_2 * V_42 )
{
const struct V_87 * V_88 = V_42 -> V_20 ;
struct V_1 * V_8 , * V_89 ;
F_43 ( V_90 ) ;
F_15 ( L_24
L_23 , V_88 -> V_27 () ,
V_88 -> V_86 ( V_42 ) ? V_88 -> V_86 ( V_42 ) : NULL ,
V_42 -> V_72 , V_88 -> V_28 ( V_42 ) ) ;
F_65 ( & V_84 ) ;
F_44 ( & V_42 -> V_79 ) ;
F_66 ( & V_84 ) ;
while ( F_37 ( & V_42 -> V_78 ) != 0 )
F_38 () ;
F_4 ( & V_42 -> V_6 ) ;
F_68 ( & V_42 -> V_46 , & V_90 ) ;
F_6 ( & V_42 -> V_6 ) ;
F_46 (nacl, nacl_tmp, &node_list, acl_list) {
F_44 ( & V_8 -> V_33 ) ;
F_36 ( V_8 ) ;
F_53 ( V_8 , V_42 ) ;
F_54 ( V_8 ) ;
}
if ( V_42 -> V_72 >= 0 ) {
F_69 ( V_42 , V_42 -> V_82 ) ;
F_70 ( V_42 -> V_82 , V_91 ) ;
}
return 0 ;
}
struct V_12 * F_61 (
struct V_2 * V_3 ,
T_2 V_29 )
{
struct V_12 * V_15 ;
V_15 = F_21 ( sizeof( * V_15 ) , V_32 ) ;
if ( ! V_15 ) {
F_40 ( L_25 ) ;
return F_41 ( - V_52 ) ;
}
V_15 -> V_29 = V_29 ;
V_15 -> V_92 = V_93 ;
F_29 ( & V_15 -> V_94 , 0 ) ;
F_26 ( & V_15 -> V_70 ) ;
F_23 ( & V_15 -> V_95 ) ;
F_23 ( & V_15 -> V_96 ) ;
F_29 ( & V_15 -> V_97 , 0 ) ;
F_27 ( & V_15 -> V_98 ) ;
F_28 ( & V_15 -> V_99 ) ;
F_23 ( & V_15 -> V_100 ) ;
F_27 ( & V_15 -> V_101 ) ;
V_15 -> V_102 = V_3 ;
return V_15 ;
}
int F_64 (
struct V_2 * V_3 ,
struct V_12 * V_15 ,
T_1 V_14 ,
struct V_16 * V_17 )
{
int V_73 ;
V_73 = F_71 ( & V_15 -> V_69 , F_57 , 0 ,
V_32 ) ;
if ( V_73 < 0 )
goto V_103;
V_73 = F_72 ( V_15 , V_17 ) ;
if ( V_73 )
goto V_104;
if ( ! ( V_17 -> V_23 -> V_105 & V_106 ) &&
! ( V_17 -> V_107 -> V_108 & V_109 ) )
F_73 ( V_15 , V_17 -> V_110 . V_111 ) ;
F_4 ( & V_3 -> V_18 ) ;
F_74 ( & V_17 -> V_112 ) ;
V_15 -> V_113 = V_17 -> V_114 ;
F_75 ( V_15 -> V_19 , V_17 ) ;
V_17 -> V_115 ++ ;
F_32 ( & V_15 -> V_96 , & V_17 -> V_116 ) ;
F_76 ( & V_17 -> V_112 ) ;
if ( V_17 -> V_117 & V_118 )
V_15 -> V_14 = V_26 ;
else
V_15 -> V_14 = V_14 ;
if ( ! ( V_17 -> V_107 -> V_108 & V_109 ) )
F_77 ( & V_15 -> V_119 , & V_3 -> V_76 ) ;
F_6 ( & V_3 -> V_18 ) ;
return 0 ;
V_104:
F_78 ( & V_15 -> V_69 ) ;
V_103:
return V_73 ;
}
void F_69 (
struct V_2 * V_3 ,
struct V_12 * V_15 )
{
struct V_16 * V_17 = F_79 ( V_15 -> V_19 ) ;
F_80 ( V_15 , V_3 ) ;
F_81 ( V_15 ) ;
F_4 ( & V_3 -> V_18 ) ;
if ( V_15 -> V_19 ) {
F_82 ( V_15 ) ;
F_74 ( & V_17 -> V_112 ) ;
F_44 ( & V_15 -> V_96 ) ;
V_17 -> V_115 -- ;
F_75 ( V_15 -> V_19 , NULL ) ;
F_76 ( & V_17 -> V_112 ) ;
}
if ( ! ( V_17 -> V_107 -> V_108 & V_109 ) )
F_83 ( & V_15 -> V_119 ) ;
F_6 ( & V_3 -> V_18 ) ;
F_78 ( & V_15 -> V_69 ) ;
}
