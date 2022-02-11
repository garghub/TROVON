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
bool V_14 = true ;
struct V_12 * V_15 ;
struct V_16 * V_17 ;
F_4 ( & V_3 -> V_18 ) ;
F_9 (lun, &tpg->tpg_lun_hlist, link) {
if ( V_13 && V_15 != V_13 )
continue;
V_17 = F_13 ( V_15 -> V_19 ,
F_14 ( & V_3 -> V_18 ) ) ;
if ( ! V_3 -> V_20 -> V_21 ( V_3 ) ) {
V_14 = false ;
} else {
if ( V_17 -> V_22 -> V_23 ( V_17 ) == V_24 )
V_14 = true ;
else
V_14 = false ;
}
F_15 ( L_1
L_2 ,
V_3 -> V_20 -> V_25 () ,
V_3 -> V_20 -> V_26 ( V_3 ) , V_15 -> V_27 ,
V_14 ? L_3 : L_4 ) ;
F_16 ( V_15 , NULL , V_15 -> V_27 ,
V_14 , V_5 , V_3 ) ;
F_17 ( V_17 , V_3 , V_15 , V_5 ,
V_15 -> V_27 ) ;
}
F_6 ( & V_3 -> V_18 ) ;
}
static void
F_18 ( struct V_2 * V_3 ,
struct V_1 * V_5 , T_1 V_28 )
{
V_5 -> V_28 = V_28 ;
if ( ! V_5 -> V_28 ) {
F_19 ( L_5
L_6 , V_3 -> V_20 -> V_25 () ,
V_5 -> V_4 ) ;
V_5 -> V_28 = 1 ;
}
}
static struct V_1 * F_20 ( struct V_2 * V_3 ,
const unsigned char * V_4 )
{
struct V_1 * V_5 ;
T_1 V_28 ;
V_5 = F_21 ( F_22 ( sizeof( * V_5 ) , V_3 -> V_20 -> V_29 ) ,
V_30 ) ;
if ( ! V_5 )
return NULL ;
F_23 ( & V_5 -> V_31 ) ;
F_23 ( & V_5 -> V_32 ) ;
F_24 ( & V_5 -> V_33 ) ;
F_25 ( & V_5 -> V_7 ) ;
F_26 ( & V_5 -> V_34 ) ;
F_27 ( & V_5 -> V_35 ) ;
F_28 ( & V_5 -> V_36 ) ;
F_29 ( & V_5 -> V_37 , 0 ) ;
if ( V_3 -> V_20 -> V_38 )
V_28 = V_3 -> V_20 -> V_38 ( V_3 ) ;
else
V_28 = 1 ;
F_18 ( V_3 , V_5 , V_28 ) ;
snprintf ( V_5 -> V_4 , V_39 , L_7 , V_4 ) ;
V_5 -> V_40 = V_3 ;
V_5 -> V_41 = F_30 ( V_42 ) ;
V_3 -> V_20 -> V_43 ( V_5 ) ;
return V_5 ;
}
static void F_31 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_40 ;
F_4 ( & V_3 -> V_6 ) ;
F_32 ( & V_5 -> V_31 , & V_3 -> V_44 ) ;
F_6 ( & V_3 -> V_6 ) ;
F_15 ( L_8
L_9 ,
V_3 -> V_20 -> V_25 () ,
V_3 -> V_20 -> V_26 ( V_3 ) ,
V_5 -> V_45 ? L_10 : L_11 ,
V_5 -> V_28 ,
V_3 -> V_20 -> V_25 () ,
V_5 -> V_4 ) ;
}
bool F_33 ( struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
bool V_46 = false ;
F_4 ( & V_3 -> V_6 ) ;
F_2 (acl, &tpg->acl_node_list, acl_list) {
if ( ! strcmp ( V_5 -> V_4 , V_4 ) ) {
V_46 = true ;
break;
}
}
F_6 ( & V_3 -> V_6 ) ;
return V_46 ;
}
struct V_1 * F_34 (
struct V_2 * V_3 ,
unsigned char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_3 -> V_20 -> V_47 ( V_3 ) )
return NULL ;
V_5 = F_20 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
F_35 ( & V_5 -> V_7 ) ;
V_5 -> V_45 = 1 ;
if ( ( V_3 -> V_20 -> V_48 == NULL ) ||
( V_3 -> V_20 -> V_48 ( V_3 ) != 1 ) )
F_12 ( V_5 , V_3 , NULL ) ;
F_31 ( V_5 ) ;
return V_5 ;
}
void F_36 ( struct V_1 * V_8 )
{
while ( F_37 ( & V_8 -> V_37 ) != 0 )
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
if ( V_5 -> V_45 ) {
V_5 -> V_45 = 0 ;
F_15 ( L_12
L_13 , V_3 -> V_20 -> V_25 () ,
V_3 -> V_20 -> V_26 ( V_3 ) , V_4 ) ;
F_6 ( & V_3 -> V_6 ) ;
return V_5 ;
}
F_40 ( L_14
L_15
L_16 , V_3 -> V_20 -> V_25 () ,
V_4 , V_3 -> V_20 -> V_26 ( V_3 ) ) ;
F_6 ( & V_3 -> V_6 ) ;
return F_41 ( - V_49 ) ;
}
F_6 ( & V_3 -> V_6 ) ;
V_5 = F_20 ( V_3 , V_4 ) ;
if ( ! V_5 )
return F_41 ( - V_50 ) ;
F_31 ( V_5 ) ;
return V_5 ;
}
void F_42 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_40 ;
F_43 ( V_51 ) ;
struct V_52 * V_53 , * V_54 ;
unsigned long V_55 ;
int V_56 ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_5 -> V_45 ) {
V_5 -> V_45 = 0 ;
}
F_44 ( & V_5 -> V_31 ) ;
F_6 ( & V_3 -> V_6 ) ;
F_45 ( & V_5 -> V_35 , V_55 ) ;
V_5 -> V_57 = 1 ;
F_46 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_53 -> V_58 != 0 )
continue;
if ( ! F_47 ( V_53 ) )
continue;
F_48 ( & V_53 -> V_59 , & V_51 ) ;
}
F_49 ( & V_5 -> V_35 , V_55 ) ;
F_46 (sess, sess_tmp, &sess_list, sess_acl_list) {
F_44 ( & V_53 -> V_59 ) ;
V_56 = V_3 -> V_20 -> V_60 ( V_53 ) ;
F_50 ( V_53 ) ;
if ( ! V_56 )
continue;
F_50 ( V_53 ) ;
}
F_51 ( V_5 ) ;
F_52 ( & V_5 -> V_34 ) ;
F_36 ( V_5 ) ;
F_53 ( V_5 , V_3 ) ;
F_15 ( L_17
L_9 , V_3 -> V_20 -> V_25 () ,
V_3 -> V_20 -> V_26 ( V_3 ) , V_5 -> V_28 ,
V_3 -> V_20 -> V_25 () , V_5 -> V_4 ) ;
F_54 ( V_5 ) ;
}
int F_55 (
struct V_1 * V_5 ,
T_1 V_28 )
{
F_43 ( V_51 ) ;
struct V_2 * V_3 = V_5 -> V_40 ;
struct V_52 * V_53 , * V_54 ;
unsigned long V_55 ;
int V_56 ;
F_18 ( V_3 , V_5 , V_28 ) ;
F_45 ( & V_5 -> V_35 , V_55 ) ;
F_46 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_53 -> V_58 != 0 )
continue;
if ( ! F_47 ( V_53 ) )
continue;
F_49 ( & V_5 -> V_35 , V_55 ) ;
V_56 = V_3 -> V_20 -> V_60 ( V_53 ) ;
F_50 ( V_53 ) ;
if ( ! V_56 ) {
F_45 ( & V_5 -> V_35 , V_55 ) ;
continue;
}
F_50 ( V_53 ) ;
F_45 ( & V_5 -> V_35 , V_55 ) ;
}
F_49 ( & V_5 -> V_35 , V_55 ) ;
F_15 ( L_18
L_19 , V_5 -> V_28 ,
V_5 -> V_4 , V_3 -> V_20 -> V_25 () ,
V_3 -> V_20 -> V_26 ( V_3 ) ) ;
return 0 ;
}
int F_56 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
const char * V_61 )
{
if ( strlen ( V_61 ) >= V_62 )
return - V_63 ;
if ( ! strncmp ( L_20 , V_61 , 4 ) ) {
V_5 -> V_64 [ 0 ] = '\0' ;
return 0 ;
}
return snprintf ( V_5 -> V_64 , V_62 , L_7 , V_61 ) ;
}
static void F_57 ( struct V_65 * V_66 )
{
struct V_12 * V_15 = F_58 ( V_66 , struct V_12 , V_67 ) ;
F_59 ( & V_15 -> V_68 ) ;
}
int F_60 (
struct V_69 * V_69 ,
struct V_2 * V_40 ,
int V_70 )
{
int V_71 ;
if ( ! V_40 )
return - V_63 ;
if ( V_69 )
V_40 -> V_20 = V_69 -> V_72 -> V_73 ;
if ( ! V_40 -> V_20 ) {
F_40 ( L_21 ) ;
return - V_63 ;
}
F_24 ( & V_40 -> V_74 ) ;
V_40 -> V_70 = V_70 ;
V_40 -> V_75 = V_69 ;
F_29 ( & V_40 -> V_76 , 0 ) ;
F_23 ( & V_40 -> V_44 ) ;
F_23 ( & V_40 -> V_77 ) ;
F_23 ( & V_40 -> V_78 ) ;
F_27 ( & V_40 -> V_79 ) ;
F_28 ( & V_40 -> V_18 ) ;
F_28 ( & V_40 -> V_6 ) ;
if ( V_40 -> V_70 >= 0 ) {
V_40 -> V_80 = F_61 ( V_40 , 0 ) ;
if ( F_62 ( V_40 -> V_80 ) )
return F_63 ( V_40 -> V_80 ) ;
V_71 = F_64 ( V_40 , V_40 -> V_80 ,
true , V_81 ) ;
if ( V_71 < 0 ) {
F_54 ( V_40 -> V_80 ) ;
return V_71 ;
}
}
F_65 ( & V_82 ) ;
F_32 ( & V_40 -> V_77 , & V_83 ) ;
F_66 ( & V_82 ) ;
F_15 ( L_22
L_23 , V_40 -> V_20 -> V_25 () ,
V_40 -> V_20 -> V_84 ( V_40 ) ?
V_40 -> V_20 -> V_84 ( V_40 ) : NULL ,
V_40 -> V_70 , V_40 -> V_20 -> V_26 ( V_40 ) ) ;
return 0 ;
}
int F_67 ( struct V_2 * V_40 )
{
const struct V_85 * V_86 = V_40 -> V_20 ;
struct V_1 * V_8 , * V_87 ;
F_43 ( V_88 ) ;
F_15 ( L_24
L_23 , V_86 -> V_25 () ,
V_86 -> V_84 ( V_40 ) ? V_86 -> V_84 ( V_40 ) : NULL ,
V_40 -> V_70 , V_86 -> V_26 ( V_40 ) ) ;
F_65 ( & V_82 ) ;
F_44 ( & V_40 -> V_77 ) ;
F_66 ( & V_82 ) ;
while ( F_37 ( & V_40 -> V_76 ) != 0 )
F_38 () ;
F_4 ( & V_40 -> V_6 ) ;
F_68 ( & V_40 -> V_44 , & V_88 ) ;
F_6 ( & V_40 -> V_6 ) ;
F_46 (nacl, nacl_tmp, &node_list, acl_list) {
F_44 ( & V_8 -> V_31 ) ;
F_36 ( V_8 ) ;
F_53 ( V_8 , V_40 ) ;
F_54 ( V_8 ) ;
}
if ( V_40 -> V_70 >= 0 ) {
F_69 ( V_40 , V_40 -> V_80 ) ;
F_70 ( V_40 -> V_80 , V_89 ) ;
}
return 0 ;
}
struct V_12 * F_61 (
struct V_2 * V_3 ,
T_2 V_27 )
{
struct V_12 * V_15 ;
V_15 = F_21 ( sizeof( * V_15 ) , V_30 ) ;
if ( ! V_15 ) {
F_40 ( L_25 ) ;
return F_41 ( - V_50 ) ;
}
V_15 -> V_27 = V_27 ;
V_15 -> V_90 = V_91 ;
F_29 ( & V_15 -> V_92 , 0 ) ;
F_26 ( & V_15 -> V_68 ) ;
F_23 ( & V_15 -> V_93 ) ;
F_23 ( & V_15 -> V_94 ) ;
F_29 ( & V_15 -> V_95 , 0 ) ;
F_27 ( & V_15 -> V_96 ) ;
F_28 ( & V_15 -> V_97 ) ;
F_23 ( & V_15 -> V_98 ) ;
F_27 ( & V_15 -> V_99 ) ;
V_15 -> V_100 = V_3 ;
return V_15 ;
}
int F_64 (
struct V_2 * V_3 ,
struct V_12 * V_15 ,
bool V_14 ,
struct V_16 * V_17 )
{
int V_71 ;
V_71 = F_71 ( & V_15 -> V_67 , F_57 , 0 ,
V_30 ) ;
if ( V_71 < 0 )
goto V_101;
V_71 = F_72 ( V_15 , V_17 ) ;
if ( V_71 )
goto V_102;
if ( ! ( V_17 -> V_22 -> V_103 & V_104 ) &&
! ( V_17 -> V_105 -> V_106 & V_107 ) )
F_73 ( V_15 , V_17 -> V_108 . V_109 ) ;
F_4 ( & V_3 -> V_18 ) ;
F_74 ( & V_17 -> V_110 ) ;
V_15 -> V_111 = V_17 -> V_112 ;
F_75 ( V_15 -> V_19 , V_17 ) ;
V_17 -> V_113 ++ ;
F_32 ( & V_15 -> V_94 , & V_17 -> V_114 ) ;
F_76 ( & V_17 -> V_110 ) ;
if ( V_17 -> V_115 & V_116 )
V_15 -> V_14 = true ;
else
V_15 -> V_14 = V_14 ;
if ( ! ( V_17 -> V_105 -> V_106 & V_107 ) )
F_77 ( & V_15 -> V_117 , & V_3 -> V_74 ) ;
F_6 ( & V_3 -> V_18 ) ;
return 0 ;
V_102:
F_78 ( & V_15 -> V_67 ) ;
V_101:
return V_71 ;
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
F_74 ( & V_17 -> V_110 ) ;
F_44 ( & V_15 -> V_94 ) ;
V_17 -> V_113 -- ;
F_75 ( V_15 -> V_19 , NULL ) ;
F_76 ( & V_17 -> V_110 ) ;
}
if ( ! ( V_17 -> V_105 -> V_106 & V_107 ) )
F_83 ( & V_15 -> V_117 ) ;
F_6 ( & V_3 -> V_18 ) ;
F_78 ( & V_15 -> V_67 ) ;
}
