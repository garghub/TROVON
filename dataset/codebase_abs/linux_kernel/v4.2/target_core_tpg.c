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
struct V_1 * V_5 ,
struct V_2 * V_3 ,
struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
struct V_7 * V_10 ;
struct V_11 * V_12 ;
F_4 ( & V_3 -> V_13 ) ;
F_7 (lun, &tpg->tpg_lun_hlist, link) {
if ( V_8 && V_10 != V_8 )
continue;
V_12 = F_8 ( V_10 -> V_14 ,
F_9 ( & V_3 -> V_13 ) ) ;
if ( ! V_3 -> V_15 -> V_16 ( V_3 ) ) {
V_9 = V_17 ;
} else {
if ( V_12 -> V_18 -> V_19 ( V_12 ) == V_20 )
V_9 = V_21 ;
else
V_9 = V_17 ;
}
F_10 ( L_1
L_2 ,
V_3 -> V_15 -> V_22 () ,
V_3 -> V_15 -> V_23 ( V_3 ) , V_10 -> V_24 ,
( V_9 == V_17 ) ?
L_3 : L_4 ) ;
F_11 ( V_10 , NULL , V_10 -> V_24 ,
V_9 , V_5 , V_3 ) ;
F_12 ( V_12 , V_3 , V_10 , V_5 ,
V_10 -> V_24 ) ;
}
F_5 ( & V_3 -> V_13 ) ;
}
static int F_13 (
struct V_2 * V_3 ,
struct V_1 * V_5 )
{
if ( ! V_5 -> V_25 ) {
F_14 ( L_5
L_6 , V_3 -> V_15 -> V_22 () ,
V_5 -> V_4 ) ;
V_5 -> V_25 = 1 ;
}
return 0 ;
}
static struct V_1 * F_15 ( struct V_2 * V_3 ,
const unsigned char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_16 ( F_17 ( sizeof( * V_5 ) , V_3 -> V_15 -> V_26 ) ,
V_27 ) ;
if ( ! V_5 )
return NULL ;
F_18 ( & V_5 -> V_28 ) ;
F_18 ( & V_5 -> V_29 ) ;
F_19 ( & V_5 -> V_30 ) ;
F_20 ( & V_5 -> V_31 ) ;
F_21 ( & V_5 -> V_32 ) ;
F_22 ( & V_5 -> V_33 ) ;
F_23 ( & V_5 -> V_34 ) ;
F_24 ( & V_5 -> V_35 , 0 ) ;
if ( V_3 -> V_15 -> V_36 )
V_5 -> V_25 = V_3 -> V_15 -> V_36 ( V_3 ) ;
else
V_5 -> V_25 = 1 ;
snprintf ( V_5 -> V_4 , V_37 , L_7 , V_4 ) ;
V_5 -> V_38 = V_3 ;
V_5 -> V_39 = F_25 ( V_40 ) ;
V_3 -> V_15 -> V_41 ( V_5 ) ;
if ( F_13 ( V_3 , V_5 ) < 0 )
goto V_42;
return V_5 ;
V_42:
F_26 ( V_5 ) ;
return NULL ;
}
static void F_27 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_38 ;
F_4 ( & V_3 -> V_6 ) ;
F_28 ( & V_5 -> V_28 , & V_3 -> V_43 ) ;
V_3 -> V_44 ++ ;
F_5 ( & V_3 -> V_6 ) ;
F_10 ( L_8
L_9 ,
V_3 -> V_15 -> V_22 () ,
V_3 -> V_15 -> V_23 ( V_3 ) ,
V_5 -> V_45 ? L_10 : L_11 ,
V_5 -> V_25 ,
V_3 -> V_15 -> V_22 () ,
V_5 -> V_4 ) ;
}
struct V_1 * F_29 (
struct V_2 * V_3 ,
unsigned char * V_4 )
{
struct V_1 * V_5 ;
V_5 = F_3 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_3 -> V_15 -> V_46 ( V_3 ) )
return NULL ;
V_5 = F_15 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_45 = 1 ;
if ( ( V_3 -> V_15 -> V_47 == NULL ) ||
( V_3 -> V_15 -> V_47 ( V_3 ) != 1 ) )
F_6 ( V_5 , V_3 , NULL ) ;
F_27 ( V_5 ) ;
return V_5 ;
}
void F_30 ( struct V_1 * V_48 )
{
while ( F_31 ( & V_48 -> V_35 ) != 0 )
F_32 () ;
}
struct V_1 * F_33 (
struct V_2 * V_3 ,
const char * V_4 )
{
struct V_1 * V_5 ;
F_4 ( & V_3 -> V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 ) {
if ( V_5 -> V_45 ) {
V_5 -> V_45 = 0 ;
F_10 ( L_12
L_13 , V_3 -> V_15 -> V_22 () ,
V_3 -> V_15 -> V_23 ( V_3 ) , V_4 ) ;
F_5 ( & V_3 -> V_6 ) ;
return V_5 ;
}
F_14 ( L_14
L_15
L_16 , V_3 -> V_15 -> V_22 () ,
V_4 , V_3 -> V_15 -> V_23 ( V_3 ) ) ;
F_5 ( & V_3 -> V_6 ) ;
return F_34 ( - V_49 ) ;
}
F_5 ( & V_3 -> V_6 ) ;
V_5 = F_15 ( V_3 , V_4 ) ;
if ( ! V_5 )
return F_34 ( - V_50 ) ;
F_27 ( V_5 ) ;
return V_5 ;
}
void F_35 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_38 ;
F_36 ( V_51 ) ;
struct V_52 * V_53 , * V_54 ;
unsigned long V_55 ;
int V_56 ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_5 -> V_45 ) {
V_5 -> V_45 = 0 ;
}
F_37 ( & V_5 -> V_28 ) ;
V_3 -> V_44 -- ;
F_5 ( & V_3 -> V_6 ) ;
F_38 ( & V_5 -> V_33 , V_55 ) ;
V_5 -> V_57 = 1 ;
F_39 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_53 -> V_58 != 0 )
continue;
F_40 ( V_53 ) ;
F_41 ( & V_53 -> V_59 , & V_51 ) ;
}
F_42 ( & V_5 -> V_33 , V_55 ) ;
F_39 (sess, sess_tmp, &sess_list, sess_acl_list) {
F_37 ( & V_53 -> V_59 ) ;
V_56 = V_3 -> V_15 -> V_60 ( V_53 ) ;
F_43 ( V_53 ) ;
if ( ! V_56 )
continue;
F_43 ( V_53 ) ;
}
F_44 ( V_5 ) ;
F_45 ( & V_5 -> V_32 ) ;
F_30 ( V_5 ) ;
F_46 ( V_5 , V_3 ) ;
F_10 ( L_17
L_9 , V_3 -> V_15 -> V_22 () ,
V_3 -> V_15 -> V_23 ( V_3 ) , V_5 -> V_25 ,
V_3 -> V_15 -> V_22 () , V_5 -> V_4 ) ;
F_26 ( V_5 ) ;
}
int F_47 (
struct V_2 * V_3 ,
unsigned char * V_4 ,
T_1 V_25 ,
int V_61 )
{
struct V_52 * V_53 , * V_62 = NULL ;
struct V_1 * V_5 ;
unsigned long V_55 ;
int V_63 = 0 ;
F_4 ( & V_3 -> V_6 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 ) {
F_14 ( L_18
L_19
L_16 , V_3 -> V_15 -> V_22 () ,
V_4 , V_3 -> V_15 -> V_23 ( V_3 ) ) ;
F_5 ( & V_3 -> V_6 ) ;
return - V_64 ;
}
if ( V_5 -> V_45 ) {
V_5 -> V_45 = 0 ;
V_63 = 1 ;
}
F_5 ( & V_3 -> V_6 ) ;
F_38 ( & V_3 -> V_65 , V_55 ) ;
F_2 (sess, &tpg->tpg_sess_list, sess_list) {
if ( V_53 -> V_1 != V_5 )
continue;
if ( ! V_61 ) {
F_14 ( L_20
L_21
L_22
L_23
L_24 ,
V_3 -> V_15 -> V_22 () , V_4 ) ;
F_42 ( & V_3 -> V_65 , V_55 ) ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_63 )
V_5 -> V_45 = 1 ;
F_5 ( & V_3 -> V_6 ) ;
return - V_49 ;
}
if ( ! V_3 -> V_15 -> V_60 ( V_53 ) )
continue;
V_62 = V_53 ;
break;
}
V_5 -> V_25 = V_25 ;
if ( F_13 ( V_3 , V_5 ) < 0 ) {
F_42 ( & V_3 -> V_65 , V_55 ) ;
if ( V_62 )
V_3 -> V_15 -> V_66 ( V_62 ) ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_63 )
V_5 -> V_45 = 1 ;
F_5 ( & V_3 -> V_6 ) ;
return - V_67 ;
}
F_42 ( & V_3 -> V_65 , V_55 ) ;
if ( V_62 )
V_3 -> V_15 -> V_66 ( V_62 ) ;
F_10 ( L_25
L_26 , V_25 ,
V_4 , V_3 -> V_15 -> V_22 () ,
V_3 -> V_15 -> V_23 ( V_3 ) ) ;
F_4 ( & V_3 -> V_6 ) ;
if ( V_63 )
V_5 -> V_45 = 1 ;
F_5 ( & V_3 -> V_6 ) ;
return 0 ;
}
int F_48 (
struct V_2 * V_3 ,
struct V_1 * V_5 ,
const char * V_68 )
{
if ( strlen ( V_68 ) >= V_69 )
return - V_67 ;
if ( ! strncmp ( L_27 , V_68 , 4 ) ) {
V_5 -> V_70 [ 0 ] = '\0' ;
return 0 ;
}
return snprintf ( V_5 -> V_70 , V_69 , L_7 , V_68 ) ;
}
static void F_49 ( struct V_71 * V_72 )
{
struct V_7 * V_10 = F_50 ( V_72 , struct V_7 , V_73 ) ;
F_51 ( & V_10 -> V_74 ) ;
}
int F_52 (
struct V_75 * V_75 ,
struct V_2 * V_38 ,
int V_76 )
{
int V_77 ;
if ( ! V_38 )
return - V_67 ;
if ( V_75 )
V_38 -> V_15 = V_75 -> V_78 -> V_79 ;
if ( ! V_38 -> V_15 ) {
F_14 ( L_28 ) ;
return - V_67 ;
}
F_19 ( & V_38 -> V_80 ) ;
V_38 -> V_76 = V_76 ;
V_38 -> V_81 = V_75 ;
F_24 ( & V_38 -> V_82 , 0 ) ;
F_18 ( & V_38 -> V_43 ) ;
F_18 ( & V_38 -> V_83 ) ;
F_18 ( & V_38 -> V_84 ) ;
F_22 ( & V_38 -> V_65 ) ;
F_23 ( & V_38 -> V_13 ) ;
F_23 ( & V_38 -> V_6 ) ;
if ( V_38 -> V_76 >= 0 ) {
V_38 -> V_85 = F_53 ( V_38 , 0 ) ;
if ( F_54 ( V_38 -> V_85 ) )
return F_55 ( V_38 -> V_85 ) ;
V_77 = F_56 ( V_38 , V_38 -> V_85 ,
V_21 , V_86 ) ;
if ( V_77 < 0 ) {
F_26 ( V_38 -> V_85 ) ;
return V_77 ;
}
}
F_57 ( & V_87 ) ;
F_28 ( & V_38 -> V_83 , & V_88 ) ;
F_58 ( & V_87 ) ;
F_10 ( L_29
L_30 , V_38 -> V_15 -> V_22 () ,
V_38 -> V_15 -> V_89 ( V_38 ) ?
V_38 -> V_15 -> V_89 ( V_38 ) : NULL ,
V_38 -> V_76 , V_38 -> V_15 -> V_23 ( V_38 ) ) ;
return 0 ;
}
int F_59 ( struct V_2 * V_38 )
{
const struct V_90 * V_91 = V_38 -> V_15 ;
struct V_1 * V_48 , * V_92 ;
F_36 ( V_93 ) ;
F_10 ( L_31
L_30 , V_91 -> V_22 () ,
V_91 -> V_89 ( V_38 ) ? V_91 -> V_89 ( V_38 ) : NULL ,
V_38 -> V_76 , V_91 -> V_23 ( V_38 ) ) ;
F_57 ( & V_87 ) ;
F_37 ( & V_38 -> V_83 ) ;
F_58 ( & V_87 ) ;
while ( F_31 ( & V_38 -> V_82 ) != 0 )
F_32 () ;
F_4 ( & V_38 -> V_6 ) ;
F_60 ( & V_38 -> V_43 , & V_93 ) ;
F_5 ( & V_38 -> V_6 ) ;
F_39 (nacl, nacl_tmp, &node_list, acl_list) {
F_37 ( & V_48 -> V_28 ) ;
V_38 -> V_44 -- ;
F_30 ( V_48 ) ;
F_46 ( V_48 , V_38 ) ;
F_26 ( V_48 ) ;
}
if ( V_38 -> V_76 >= 0 ) {
F_61 ( V_38 , V_38 -> V_85 ) ;
F_62 ( V_38 -> V_85 , V_94 ) ;
}
return 0 ;
}
struct V_7 * F_53 (
struct V_2 * V_3 ,
T_2 V_24 )
{
struct V_7 * V_10 ;
V_10 = F_16 ( sizeof( * V_10 ) , V_27 ) ;
if ( ! V_10 ) {
F_14 ( L_32 ) ;
return F_34 ( - V_50 ) ;
}
V_10 -> V_24 = V_24 ;
V_10 -> V_95 = V_96 ;
F_24 ( & V_10 -> V_97 , 0 ) ;
F_21 ( & V_10 -> V_74 ) ;
F_18 ( & V_10 -> V_98 ) ;
F_18 ( & V_10 -> V_99 ) ;
F_24 ( & V_10 -> V_100 , 0 ) ;
F_22 ( & V_10 -> V_101 ) ;
F_23 ( & V_10 -> V_102 ) ;
F_18 ( & V_10 -> V_103 ) ;
F_22 ( & V_10 -> V_104 ) ;
V_10 -> V_105 = V_3 ;
return V_10 ;
}
int F_56 (
struct V_2 * V_3 ,
struct V_7 * V_10 ,
T_1 V_9 ,
struct V_11 * V_12 )
{
int V_77 ;
V_77 = F_63 ( & V_10 -> V_73 , F_49 , 0 ,
V_27 ) ;
if ( V_77 < 0 )
goto V_106;
V_77 = F_64 ( V_10 , V_12 ) ;
if ( V_77 )
goto V_107;
if ( ! ( V_12 -> V_18 -> V_108 & V_109 ) &&
! ( V_12 -> V_110 -> V_111 & V_112 ) )
F_65 ( V_10 , V_12 -> V_113 . V_114 ) ;
F_4 ( & V_3 -> V_13 ) ;
F_66 ( & V_12 -> V_115 ) ;
V_10 -> V_116 = V_12 -> V_117 ;
F_67 ( V_10 -> V_14 , V_12 ) ;
V_12 -> V_118 ++ ;
F_28 ( & V_10 -> V_99 , & V_12 -> V_119 ) ;
F_68 ( & V_12 -> V_115 ) ;
V_10 -> V_9 = V_9 ;
if ( ! ( V_12 -> V_110 -> V_111 & V_112 ) )
F_69 ( & V_10 -> V_120 , & V_3 -> V_80 ) ;
F_5 ( & V_3 -> V_13 ) ;
return 0 ;
V_107:
F_70 ( & V_10 -> V_73 ) ;
V_106:
return V_77 ;
}
void F_61 (
struct V_2 * V_3 ,
struct V_7 * V_10 )
{
struct V_11 * V_12 = F_71 ( V_10 -> V_14 ) ;
F_72 ( V_10 , V_3 ) ;
F_73 ( V_10 ) ;
F_4 ( & V_3 -> V_13 ) ;
if ( V_10 -> V_14 ) {
F_74 ( V_10 ) ;
F_66 ( & V_12 -> V_115 ) ;
F_37 ( & V_10 -> V_99 ) ;
V_12 -> V_118 -- ;
F_67 ( V_10 -> V_14 , NULL ) ;
F_68 ( & V_12 -> V_115 ) ;
}
if ( ! ( V_12 -> V_110 -> V_111 & V_112 ) )
F_75 ( & V_10 -> V_120 ) ;
F_5 ( & V_3 -> V_13 ) ;
F_70 ( & V_10 -> V_73 ) ;
}
