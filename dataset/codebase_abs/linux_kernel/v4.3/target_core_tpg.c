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
F_5 ( & V_3 -> V_6 ) ;
return V_5 ;
}
void F_6 (
struct V_1 * V_7 )
{
struct V_8 * V_9 ;
if ( ! V_7 )
return;
F_7 () ;
F_8 (deve, &nacl->lun_entry_hlist, link)
F_9 ( V_9 , 0x29 ,
V_10 ) ;
F_10 () ;
}
void F_11 (
struct V_1 * V_5 ,
struct V_2 * V_3 ,
struct V_11 * V_12 )
{
T_1 V_13 = 0 ;
struct V_11 * V_14 ;
struct V_15 * V_16 ;
F_4 ( & V_3 -> V_17 ) ;
F_8 (lun, &tpg->tpg_lun_hlist, link) {
if ( V_12 && V_14 != V_12 )
continue;
V_16 = F_12 ( V_14 -> V_18 ,
F_13 ( & V_3 -> V_17 ) ) ;
if ( ! V_3 -> V_19 -> V_20 ( V_3 ) ) {
V_13 = V_21 ;
} else {
if ( V_16 -> V_22 -> V_23 ( V_16 ) == V_24 )
V_13 = V_25 ;
else
V_13 = V_21 ;
}
F_14 ( L_1
L_2 ,
V_3 -> V_19 -> V_26 () ,
V_3 -> V_19 -> V_27 ( V_3 ) , V_14 -> V_28 ,
( V_13 == V_21 ) ?
L_3 : L_4 ) ;
F_15 ( V_14 , NULL , V_14 -> V_28 ,
V_13 , V_5 , V_3 ) ;
F_16 ( V_16 , V_3 , V_14 , V_5 ,
V_14 -> V_28 ) ;
}
F_5 ( & V_3 -> V_17 ) ;
}
static int F_17 (
struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_29 ) {
F_18 ( L_5
L_6 , V_3 -> V_19 -> V_26 () ,
V_5 -> V_4 ) ;
V_5 -> V_29 = 1 ;
}
return 0 ;
}
static struct V_1 * F_19 ( struct V_2 * V_3 ,
const unsigned char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_20 ( F_21 ( sizeof( * V_5 ) , V_3 -> V_19 -> V_30 ) ,
V_31 ) ;
if ( ! V_5 )
return NULL ;
F_22 ( & V_5 -> V_32 ) ;
F_22 ( & V_5 -> V_33 ) ;
F_23 ( & V_5 -> V_34 ) ;
F_24 ( & V_5 -> V_35 ) ;
F_25 ( & V_5 -> V_36 ) ;
F_26 ( & V_5 -> V_37 ) ;
F_27 ( & V_5 -> V_38 ) ;
F_28 ( & V_5 -> V_39 , 0 ) ;
if ( V_3 -> V_19 -> V_40 )
V_5 -> V_29 = V_3 -> V_19 -> V_40 ( V_3 ) ;
else
V_5 -> V_29 = 1 ;
snprintf ( V_5 -> V_4 , V_41 , L_7 , V_4 ) ;
V_5 -> V_42 = V_3 ;
V_5 -> V_43 = F_29 ( V_44 ) ;
V_3 -> V_19 -> V_45 ( V_5 ) ;
if ( F_17 ( V_3 , V_5 ) < 0 )
goto V_46;
return V_5 ;
V_46:
F_30 ( V_5 ) ;
return NULL ;
}
static void F_31 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_42 ;
F_4 ( & V_3 -> V_6 ) ;
F_32 ( & V_5 -> V_32 , & V_3 -> V_47 ) ;
V_3 -> V_48 ++ ;
F_5 ( & V_3 -> V_6 ) ;
F_14 ( L_8
L_9 ,
V_3 -> V_19 -> V_26 () ,
V_3 -> V_19 -> V_27 ( V_3 ) ,
V_5 -> V_49 ? L_10 : L_11 ,
V_5 -> V_29 ,
V_3 -> V_19 -> V_26 () ,
V_5 -> V_4 ) ;
}
struct V_1 * F_33 (
struct V_2 * V_3 ,
unsigned char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_3 -> V_19 -> V_50 ( V_3 ) )
return NULL ;
V_5 = F_19 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_49 = 1 ;
if ( ( V_3 -> V_19 -> V_51 == NULL ) ||
( V_3 -> V_19 -> V_51 ( V_3 ) != 1 ) )
F_11 ( V_5 , V_3 , NULL ) ;
F_31 ( V_5 ) ;
return V_5 ;
}
void F_34 ( struct V_1 * V_7 )
{
while ( F_35 ( & V_7 -> V_39 ) != 0 )
F_36 () ;
}
struct V_1 * F_37 (
struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
F_4 ( & V_3 -> V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
if ( V_5 -> V_49 ) {
V_5 -> V_49 = 0 ;
F_14 ( L_12
L_13 , V_3 -> V_19 -> V_26 () ,
V_3 -> V_19 -> V_27 ( V_3 ) , V_4 ) ;
F_5 ( & V_3 -> V_6 ) ;
return V_5 ;
}
F_18 ( L_14
L_15
L_16 , V_3 -> V_19 -> V_26 () ,
V_4 , V_3 -> V_19 -> V_27 ( V_3 ) ) ;
F_5 ( & V_3 -> V_6 ) ;
return F_38 ( - V_52 ) ;
}
F_5 ( & V_3 -> V_6 ) ;
V_5 = F_19 ( V_3 , V_4 ) ;
if ( ! V_5 )
return F_38 ( - V_53 ) ;
F_31 ( V_5 ) ;
return V_5 ;
}
void F_39 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_42 ;
F_40 ( V_54 ) ;
struct V_55 * V_56 , * V_57 ;
unsigned long V_58 ;
int V_59 ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_5 -> V_49 ) {
V_5 -> V_49 = 0 ;
}
F_41 ( & V_5 -> V_32 ) ;
V_3 -> V_48 -- ;
F_5 ( & V_3 -> V_6 ) ;
F_42 ( & V_5 -> V_37 , V_58 ) ;
V_5 -> V_60 = 1 ;
F_43 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_56 -> V_61 != 0 )
continue;
F_44 ( V_56 ) ;
F_45 ( & V_56 -> V_62 , & V_54 ) ;
}
F_46 ( & V_5 -> V_37 , V_58 ) ;
F_43 (sess, sess_tmp, &sess_list, sess_acl_list) {
F_41 ( & V_56 -> V_62 ) ;
V_59 = V_3 -> V_19 -> V_63 ( V_56 ) ;
F_47 ( V_56 ) ;
if ( ! V_59 )
continue;
F_47 ( V_56 ) ;
}
F_48 ( V_5 ) ;
F_49 ( & V_5 -> V_36 ) ;
F_34 ( V_5 ) ;
F_50 ( V_5 , V_3 ) ;
F_14 ( L_17
L_9 , V_3 -> V_19 -> V_26 () ,
V_3 -> V_19 -> V_27 ( V_3 ) , V_5 -> V_29 ,
V_3 -> V_19 -> V_26 () , V_5 -> V_4 ) ;
F_30 ( V_5 ) ;
}
int F_51 (
struct V_2 * V_3 ,
unsigned char * V_4 ,
T_1 V_29 ,
int V_64 )
{
struct V_55 * V_56 , * V_65 = NULL ;
struct V_1 * V_5 ;
unsigned long V_58 ;
int V_66 = 0 ;
F_4 ( & V_3 -> V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_18 ( L_18
L_19
L_16 , V_3 -> V_19 -> V_26 () ,
V_4 , V_3 -> V_19 -> V_27 ( V_3 ) ) ;
F_5 ( & V_3 -> V_6 ) ;
return - V_67 ;
}
if ( V_5 -> V_49 ) {
V_5 -> V_49 = 0 ;
V_66 = 1 ;
}
F_5 ( & V_3 -> V_6 ) ;
F_42 ( & V_3 -> V_68 , V_58 ) ;
F_2 (sess, &tpg->tpg_sess_list, sess_list) {
if ( V_56 -> V_1 != V_5 )
continue;
if ( ! V_64 ) {
F_18 ( L_20
L_21
L_22
L_23
L_24 ,
V_3 -> V_19 -> V_26 () , V_4 ) ;
F_46 ( & V_3 -> V_68 , V_58 ) ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_66 )
V_5 -> V_49 = 1 ;
F_5 ( & V_3 -> V_6 ) ;
return - V_52 ;
}
if ( ! V_3 -> V_19 -> V_63 ( V_56 ) )
continue;
V_65 = V_56 ;
break;
}
V_5 -> V_29 = V_29 ;
if ( F_17 ( V_3 , V_5 ) < 0 ) {
F_46 ( & V_3 -> V_68 , V_58 ) ;
if ( V_65 )
V_3 -> V_19 -> V_69 ( V_65 ) ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_66 )
V_5 -> V_49 = 1 ;
F_5 ( & V_3 -> V_6 ) ;
return - V_70 ;
}
F_46 ( & V_3 -> V_68 , V_58 ) ;
if ( V_65 )
V_3 -> V_19 -> V_69 ( V_65 ) ;
F_14 ( L_25
L_26 , V_29 ,
V_4 , V_3 -> V_19 -> V_26 () ,
V_3 -> V_19 -> V_27 ( V_3 ) ) ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_66 )
V_5 -> V_49 = 1 ;
F_5 ( & V_3 -> V_6 ) ;
return 0 ;
}
int F_52 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
const char * V_71 )
{
if ( strlen ( V_71 ) >= V_72 )
return - V_70 ;
if ( ! strncmp ( L_27 , V_71 , 4 ) ) {
V_5 -> V_73 [ 0 ] = '\0' ;
return 0 ;
}
return snprintf ( V_5 -> V_73 , V_72 , L_7 , V_71 ) ;
}
static void F_53 ( struct V_74 * V_75 )
{
struct V_11 * V_14 = F_54 ( V_75 , struct V_11 , V_76 ) ;
F_55 ( & V_14 -> V_77 ) ;
}
int F_56 (
struct V_78 * V_78 ,
struct V_2 * V_42 ,
int V_79 )
{
int V_80 ;
if ( ! V_42 )
return - V_70 ;
if ( V_78 )
V_42 -> V_19 = V_78 -> V_81 -> V_82 ;
if ( ! V_42 -> V_19 ) {
F_18 ( L_28 ) ;
return - V_70 ;
}
F_23 ( & V_42 -> V_83 ) ;
V_42 -> V_79 = V_79 ;
V_42 -> V_84 = V_78 ;
F_28 ( & V_42 -> V_85 , 0 ) ;
F_22 ( & V_42 -> V_47 ) ;
F_22 ( & V_42 -> V_86 ) ;
F_22 ( & V_42 -> V_87 ) ;
F_26 ( & V_42 -> V_68 ) ;
F_27 ( & V_42 -> V_17 ) ;
F_27 ( & V_42 -> V_6 ) ;
if ( V_42 -> V_79 >= 0 ) {
V_42 -> V_88 = F_57 ( V_42 , 0 ) ;
if ( F_58 ( V_42 -> V_88 ) )
return F_59 ( V_42 -> V_88 ) ;
V_80 = F_60 ( V_42 , V_42 -> V_88 ,
V_25 , V_89 ) ;
if ( V_80 < 0 ) {
F_30 ( V_42 -> V_88 ) ;
return V_80 ;
}
}
F_61 ( & V_90 ) ;
F_32 ( & V_42 -> V_86 , & V_91 ) ;
F_62 ( & V_90 ) ;
F_14 ( L_29
L_30 , V_42 -> V_19 -> V_26 () ,
V_42 -> V_19 -> V_92 ( V_42 ) ?
V_42 -> V_19 -> V_92 ( V_42 ) : NULL ,
V_42 -> V_79 , V_42 -> V_19 -> V_27 ( V_42 ) ) ;
return 0 ;
}
int F_63 ( struct V_2 * V_42 )
{
const struct V_93 * V_94 = V_42 -> V_19 ;
struct V_1 * V_7 , * V_95 ;
F_40 ( V_96 ) ;
F_14 ( L_31
L_30 , V_94 -> V_26 () ,
V_94 -> V_92 ( V_42 ) ? V_94 -> V_92 ( V_42 ) : NULL ,
V_42 -> V_79 , V_94 -> V_27 ( V_42 ) ) ;
F_61 ( & V_90 ) ;
F_41 ( & V_42 -> V_86 ) ;
F_62 ( & V_90 ) ;
while ( F_35 ( & V_42 -> V_85 ) != 0 )
F_36 () ;
F_4 ( & V_42 -> V_6 ) ;
F_64 ( & V_42 -> V_47 , & V_96 ) ;
F_5 ( & V_42 -> V_6 ) ;
F_43 (nacl, nacl_tmp, &node_list, acl_list) {
F_41 ( & V_7 -> V_32 ) ;
V_42 -> V_48 -- ;
F_34 ( V_7 ) ;
F_50 ( V_7 , V_42 ) ;
F_30 ( V_7 ) ;
}
if ( V_42 -> V_79 >= 0 ) {
F_65 ( V_42 , V_42 -> V_88 ) ;
F_66 ( V_42 -> V_88 , V_97 ) ;
}
return 0 ;
}
struct V_11 * F_57 (
struct V_2 * V_3 ,
T_2 V_28 )
{
struct V_11 * V_14 ;
V_14 = F_20 ( sizeof( * V_14 ) , V_31 ) ;
if ( ! V_14 ) {
F_18 ( L_32 ) ;
return F_38 ( - V_53 ) ;
}
V_14 -> V_28 = V_28 ;
V_14 -> V_98 = V_99 ;
F_28 ( & V_14 -> V_100 , 0 ) ;
F_25 ( & V_14 -> V_77 ) ;
F_22 ( & V_14 -> V_101 ) ;
F_22 ( & V_14 -> V_102 ) ;
F_28 ( & V_14 -> V_103 , 0 ) ;
F_26 ( & V_14 -> V_104 ) ;
F_27 ( & V_14 -> V_105 ) ;
F_22 ( & V_14 -> V_106 ) ;
F_26 ( & V_14 -> V_107 ) ;
V_14 -> V_108 = V_3 ;
return V_14 ;
}
int F_60 (
struct V_2 * V_3 ,
struct V_11 * V_14 ,
T_1 V_13 ,
struct V_15 * V_16 )
{
int V_80 ;
V_80 = F_67 ( & V_14 -> V_76 , F_53 , 0 ,
V_31 ) ;
if ( V_80 < 0 )
goto V_109;
V_80 = F_68 ( V_14 , V_16 ) ;
if ( V_80 )
goto V_110;
if ( ! ( V_16 -> V_22 -> V_111 & V_112 ) &&
! ( V_16 -> V_113 -> V_114 & V_115 ) )
F_69 ( V_14 , V_16 -> V_116 . V_117 ) ;
F_4 ( & V_3 -> V_17 ) ;
F_70 ( & V_16 -> V_118 ) ;
V_14 -> V_119 = V_16 -> V_120 ;
F_71 ( V_14 -> V_18 , V_16 ) ;
V_16 -> V_121 ++ ;
F_32 ( & V_14 -> V_102 , & V_16 -> V_122 ) ;
F_72 ( & V_16 -> V_118 ) ;
if ( V_16 -> V_123 & V_124 )
V_14 -> V_13 = V_25 ;
else
V_14 -> V_13 = V_13 ;
if ( ! ( V_16 -> V_113 -> V_114 & V_115 ) )
F_73 ( & V_14 -> V_125 , & V_3 -> V_83 ) ;
F_5 ( & V_3 -> V_17 ) ;
return 0 ;
V_110:
F_74 ( & V_14 -> V_76 ) ;
V_109:
return V_80 ;
}
void F_65 (
struct V_2 * V_3 ,
struct V_11 * V_14 )
{
struct V_15 * V_16 = F_75 ( V_14 -> V_18 ) ;
F_76 ( V_14 , V_3 ) ;
F_77 ( V_14 ) ;
F_4 ( & V_3 -> V_17 ) ;
if ( V_14 -> V_18 ) {
F_78 ( V_14 ) ;
F_70 ( & V_16 -> V_118 ) ;
F_41 ( & V_14 -> V_102 ) ;
V_16 -> V_121 -- ;
F_71 ( V_14 -> V_18 , NULL ) ;
F_72 ( & V_16 -> V_118 ) ;
}
if ( ! ( V_16 -> V_113 -> V_114 & V_115 ) )
F_79 ( & V_14 -> V_125 ) ;
F_5 ( & V_3 -> V_17 ) ;
F_74 ( & V_14 -> V_76 ) ;
}
