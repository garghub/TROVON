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
static void F_42 ( struct V_1 * V_5 )
{
struct V_51 * V_52 ;
unsigned long V_53 ;
V_54:
F_43 ( & V_5 -> V_35 , V_53 ) ;
F_2 (sess, &acl->acl_sess_list, sess_acl_list) {
if ( V_52 -> V_55 )
continue;
F_44 ( & V_52 -> V_56 ) ;
F_45 ( & V_5 -> V_35 , V_53 ) ;
if ( V_5 -> V_40 -> V_20 -> V_57 )
V_5 -> V_40 -> V_20 -> V_57 ( V_52 ) ;
goto V_54;
}
F_45 ( & V_5 -> V_35 , V_53 ) ;
}
void F_46 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_40 ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_5 -> V_45 )
V_5 -> V_45 = 0 ;
F_47 ( & V_5 -> V_31 ) ;
F_6 ( & V_3 -> V_6 ) ;
F_42 ( V_5 ) ;
F_48 ( V_5 ) ;
F_49 ( & V_5 -> V_34 ) ;
F_36 ( V_5 ) ;
F_50 ( V_5 , V_3 ) ;
F_15 ( L_17
L_9 , V_3 -> V_20 -> V_25 () ,
V_3 -> V_20 -> V_26 ( V_3 ) , V_5 -> V_28 ,
V_3 -> V_20 -> V_25 () , V_5 -> V_4 ) ;
F_51 ( V_5 ) ;
}
int F_52 (
struct V_1 * V_5 ,
T_1 V_28 )
{
struct V_2 * V_3 = V_5 -> V_40 ;
F_18 ( V_3 , V_5 , V_28 ) ;
F_42 ( V_5 ) ;
F_15 ( L_18
L_19 , V_5 -> V_28 ,
V_5 -> V_4 , V_3 -> V_20 -> V_25 () ,
V_3 -> V_20 -> V_26 ( V_3 ) ) ;
return 0 ;
}
int F_53 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
const char * V_58 )
{
if ( strlen ( V_58 ) >= V_59 )
return - V_60 ;
if ( ! strncmp ( L_20 , V_58 , 4 ) ) {
V_5 -> V_61 [ 0 ] = '\0' ;
return 0 ;
}
return snprintf ( V_5 -> V_61 , V_59 , L_7 , V_58 ) ;
}
static void F_54 ( struct V_62 * V_63 )
{
struct V_12 * V_15 = F_55 ( V_63 , struct V_12 , V_64 ) ;
F_56 ( & V_15 -> V_65 ) ;
}
int F_57 (
struct V_66 * V_66 ,
struct V_2 * V_40 ,
int V_67 )
{
int V_68 ;
if ( ! V_40 )
return - V_60 ;
if ( V_66 )
V_40 -> V_20 = V_66 -> V_69 -> V_70 ;
if ( ! V_40 -> V_20 ) {
F_40 ( L_21 ) ;
return - V_60 ;
}
F_24 ( & V_40 -> V_71 ) ;
V_40 -> V_67 = V_67 ;
V_40 -> V_72 = V_66 ;
F_29 ( & V_40 -> V_73 , 0 ) ;
F_23 ( & V_40 -> V_44 ) ;
F_23 ( & V_40 -> V_74 ) ;
F_23 ( & V_40 -> V_75 ) ;
F_27 ( & V_40 -> V_76 ) ;
F_28 ( & V_40 -> V_18 ) ;
F_28 ( & V_40 -> V_6 ) ;
if ( V_40 -> V_67 >= 0 ) {
V_40 -> V_77 = F_58 ( V_40 , 0 ) ;
if ( F_59 ( V_40 -> V_77 ) )
return F_60 ( V_40 -> V_77 ) ;
V_68 = F_61 ( V_40 , V_40 -> V_77 ,
true , V_78 ) ;
if ( V_68 < 0 ) {
F_51 ( V_40 -> V_77 ) ;
return V_68 ;
}
}
F_62 ( & V_79 ) ;
F_32 ( & V_40 -> V_74 , & V_80 ) ;
F_63 ( & V_79 ) ;
F_15 ( L_22
L_23 , V_40 -> V_20 -> V_25 () ,
V_40 -> V_20 -> V_81 ( V_40 ) ?
V_40 -> V_20 -> V_81 ( V_40 ) : NULL ,
V_40 -> V_67 , V_40 -> V_20 -> V_26 ( V_40 ) ) ;
return 0 ;
}
int F_64 ( struct V_2 * V_40 )
{
const struct V_82 * V_83 = V_40 -> V_20 ;
struct V_1 * V_8 , * V_84 ;
F_65 ( V_85 ) ;
F_15 ( L_24
L_23 , V_83 -> V_25 () ,
V_83 -> V_81 ( V_40 ) ? V_83 -> V_81 ( V_40 ) : NULL ,
V_40 -> V_67 , V_83 -> V_26 ( V_40 ) ) ;
F_62 ( & V_79 ) ;
F_47 ( & V_40 -> V_74 ) ;
F_63 ( & V_79 ) ;
while ( F_37 ( & V_40 -> V_73 ) != 0 )
F_38 () ;
F_4 ( & V_40 -> V_6 ) ;
F_66 ( & V_40 -> V_44 , & V_85 ) ;
F_6 ( & V_40 -> V_6 ) ;
F_67 (nacl, nacl_tmp, &node_list, acl_list) {
F_47 ( & V_8 -> V_31 ) ;
F_36 ( V_8 ) ;
F_50 ( V_8 , V_40 ) ;
F_51 ( V_8 ) ;
}
if ( V_40 -> V_67 >= 0 ) {
F_68 ( V_40 , V_40 -> V_77 ) ;
F_69 ( V_40 -> V_77 , V_86 ) ;
}
return 0 ;
}
struct V_12 * F_58 (
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
V_15 -> V_87 = V_88 ;
F_29 ( & V_15 -> V_89 , 0 ) ;
F_26 ( & V_15 -> V_65 ) ;
F_23 ( & V_15 -> V_90 ) ;
F_23 ( & V_15 -> V_91 ) ;
F_29 ( & V_15 -> V_92 , 0 ) ;
F_27 ( & V_15 -> V_93 ) ;
F_28 ( & V_15 -> V_94 ) ;
F_23 ( & V_15 -> V_95 ) ;
F_27 ( & V_15 -> V_96 ) ;
V_15 -> V_97 = V_3 ;
return V_15 ;
}
int F_61 (
struct V_2 * V_3 ,
struct V_12 * V_15 ,
bool V_14 ,
struct V_16 * V_17 )
{
int V_68 ;
V_68 = F_70 ( & V_15 -> V_64 , F_54 , 0 ,
V_30 ) ;
if ( V_68 < 0 )
goto V_98;
V_68 = F_71 ( V_15 , V_17 ) ;
if ( V_68 )
goto V_99;
if ( ! ( V_17 -> V_22 -> V_100 & V_101 ) &&
! ( V_17 -> V_102 -> V_103 & V_104 ) )
F_72 ( V_15 , V_17 -> V_105 . V_106 ) ;
F_4 ( & V_3 -> V_18 ) ;
F_73 ( & V_17 -> V_107 ) ;
V_15 -> V_108 = V_17 -> V_109 ;
F_74 ( V_15 -> V_19 , V_17 ) ;
V_17 -> V_110 ++ ;
F_32 ( & V_15 -> V_91 , & V_17 -> V_111 ) ;
F_75 ( & V_17 -> V_107 ) ;
if ( V_17 -> V_112 & V_113 )
V_15 -> V_14 = true ;
else
V_15 -> V_14 = V_14 ;
if ( ! ( V_17 -> V_102 -> V_103 & V_104 ) )
F_76 ( & V_15 -> V_114 , & V_3 -> V_71 ) ;
F_6 ( & V_3 -> V_18 ) ;
return 0 ;
V_99:
F_77 ( & V_15 -> V_64 ) ;
V_98:
return V_68 ;
}
void F_68 (
struct V_2 * V_3 ,
struct V_12 * V_15 )
{
struct V_16 * V_17 = F_78 ( V_15 -> V_19 ) ;
F_79 ( V_15 , V_3 ) ;
F_80 ( V_15 ) ;
F_4 ( & V_3 -> V_18 ) ;
if ( V_15 -> V_19 ) {
F_81 ( V_15 ) ;
F_73 ( & V_17 -> V_107 ) ;
F_47 ( & V_15 -> V_91 ) ;
V_17 -> V_110 -- ;
F_74 ( V_15 -> V_19 , NULL ) ;
F_75 ( & V_17 -> V_107 ) ;
}
if ( ! ( V_17 -> V_102 -> V_103 & V_104 ) )
F_82 ( & V_15 -> V_114 ) ;
F_6 ( & V_3 -> V_18 ) ;
F_77 ( & V_15 -> V_64 ) ;
}
