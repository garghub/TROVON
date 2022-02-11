static void F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 , * V_12 ;
F_2 ( & V_2 -> V_13 ) ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_7 = & V_2 -> V_15 [ V_5 ] ;
if ( ! ( V_7 -> V_16 & V_17 ) )
continue;
if ( ! V_7 -> V_8 ) {
F_3 ( L_1
L_2 ,
V_4 -> V_18 -> V_19 () ) ;
continue;
}
V_9 = V_7 -> V_8 ;
F_4 ( & V_2 -> V_13 ) ;
F_5 ( V_9 , NULL , V_7 -> V_20 ,
V_21 , V_2 , V_4 , 0 ) ;
F_6 ( & V_9 -> V_22 ) ;
F_7 (acl, acl_tmp,
&lun->lun_acl_list, lacl_list) {
if ( ! strcmp ( V_11 -> V_23 , V_2 -> V_23 ) &&
( V_11 -> V_20 == V_7 -> V_20 ) )
break;
}
if ( ! V_11 ) {
F_3 ( L_3
L_4 , V_2 -> V_23 ,
V_7 -> V_20 ) ;
F_8 ( & V_9 -> V_22 ) ;
F_2 ( & V_2 -> V_13 ) ;
continue;
}
F_9 ( & V_11 -> V_24 ) ;
F_8 ( & V_9 -> V_22 ) ;
F_2 ( & V_2 -> V_13 ) ;
F_10 ( V_11 ) ;
}
F_4 ( & V_2 -> V_13 ) ;
}
struct V_1 * F_11 (
struct V_3 * V_4 ,
const char * V_23 )
{
struct V_1 * V_11 ;
F_12 (acl, &tpg->acl_node_list, acl_list) {
if ( ! strcmp ( V_11 -> V_23 , V_23 ) )
return V_11 ;
}
return NULL ;
}
struct V_1 * F_13 (
struct V_3 * V_4 ,
unsigned char * V_23 )
{
struct V_1 * V_11 ;
F_2 ( & V_4 -> V_25 ) ;
F_12 (acl, &tpg->acl_node_list, acl_list) {
if ( ! strcmp ( V_11 -> V_23 , V_23 ) &&
! V_11 -> V_26 ) {
F_4 ( & V_4 -> V_25 ) ;
return V_11 ;
}
}
F_4 ( & V_4 -> V_25 ) ;
return NULL ;
}
void F_14 (
struct V_1 * V_11 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
T_1 V_27 = 0 ;
struct V_8 * V_9 ;
struct V_28 * V_29 ;
F_6 ( & V_4 -> V_30 ) ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_9 = & V_4 -> V_31 [ V_5 ] ;
if ( V_9 -> V_32 != V_33 )
continue;
F_8 ( & V_4 -> V_30 ) ;
V_29 = V_9 -> V_34 ;
if ( ! V_4 -> V_18 -> V_35 ( V_4 ) ) {
if ( V_29 -> V_36 & V_37 )
V_27 = V_38 ;
else
V_27 = V_39 ;
} else {
if ( V_29 -> V_40 -> V_41 ( V_29 ) == V_42 )
V_27 = V_38 ;
else
V_27 = V_39 ;
}
F_15 ( L_5
L_6 ,
V_4 -> V_18 -> V_19 () ,
V_4 -> V_18 -> V_43 ( V_4 ) , V_9 -> V_44 ,
( V_27 == V_39 ) ?
L_7 : L_8 ) ;
F_5 ( V_9 , NULL , V_9 -> V_44 ,
V_27 , V_11 , V_4 , 1 ) ;
F_6 ( & V_4 -> V_30 ) ;
}
F_8 ( & V_4 -> V_30 ) ;
}
static int F_16 (
struct V_3 * V_4 ,
struct V_1 * V_11 )
{
if ( ! V_11 -> V_45 ) {
F_3 ( L_9
L_10 , V_4 -> V_18 -> V_19 () ,
V_11 -> V_23 ) ;
V_11 -> V_45 = 1 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_5 ;
V_2 -> V_15 = F_18 ( sizeof( struct V_6 ) *
V_14 , V_46 ) ;
if ( ! V_2 -> V_15 ) {
F_3 ( L_11
L_12 ) ;
return - V_47 ;
}
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_7 = & V_2 -> V_15 [ V_5 ] ;
F_19 ( & V_7 -> V_48 , 0 ) ;
F_19 ( & V_7 -> V_49 , 0 ) ;
F_20 ( & V_7 -> V_50 ) ;
F_21 ( & V_7 -> V_51 ) ;
F_21 ( & V_7 -> V_52 ) ;
}
return 0 ;
}
struct V_1 * F_22 (
struct V_3 * V_4 ,
unsigned char * V_23 )
{
struct V_1 * V_11 ;
V_11 = F_13 ( V_4 , V_23 ) ;
if ( V_11 )
return V_11 ;
if ( ! V_4 -> V_18 -> V_53 ( V_4 ) )
return NULL ;
V_11 = V_4 -> V_18 -> V_54 ( V_4 ) ;
if ( ! V_11 )
return NULL ;
F_21 ( & V_11 -> V_55 ) ;
F_21 ( & V_11 -> V_56 ) ;
F_20 ( & V_11 -> V_13 ) ;
F_20 ( & V_11 -> V_57 ) ;
F_19 ( & V_11 -> V_58 , 0 ) ;
V_11 -> V_45 = V_4 -> V_18 -> V_59 ( V_4 ) ;
snprintf ( V_11 -> V_23 , V_60 , L_13 , V_23 ) ;
V_11 -> V_61 = V_4 ;
V_11 -> V_62 = F_23 ( V_63 ) ;
F_20 ( & V_11 -> V_64 ) ;
V_11 -> V_26 = 1 ;
V_4 -> V_18 -> V_65 ( V_11 ) ;
if ( F_17 ( V_11 ) < 0 ) {
V_4 -> V_18 -> V_66 ( V_4 , V_11 ) ;
return NULL ;
}
if ( F_16 ( V_4 , V_11 ) < 0 ) {
F_24 ( V_11 , V_4 ) ;
V_4 -> V_18 -> V_66 ( V_4 , V_11 ) ;
return NULL ;
}
if ( ( V_4 -> V_18 -> V_67 != NULL ) &&
( V_4 -> V_18 -> V_67 ( V_4 ) == 1 ) )
do { ; } while ( 0 );
else
F_14 ( V_11 , V_4 ) ;
F_2 ( & V_4 -> V_25 ) ;
F_25 ( & V_11 -> V_55 , & V_4 -> V_68 ) ;
V_4 -> V_69 ++ ;
F_4 ( & V_4 -> V_25 ) ;
F_15 ( L_14
L_15 , V_4 -> V_18 -> V_19 () ,
V_4 -> V_18 -> V_43 ( V_4 ) , V_11 -> V_45 ,
V_4 -> V_18 -> V_19 () , V_23 ) ;
return V_11 ;
}
void F_26 ( struct V_1 * V_2 )
{
while ( F_27 ( & V_2 -> V_58 ) != 0 )
F_28 () ;
}
void F_29 ( struct V_3 * V_4 )
{
int V_5 , V_70 ;
struct V_8 * V_9 ;
F_6 ( & V_4 -> V_30 ) ;
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_9 = & V_4 -> V_31 [ V_5 ] ;
if ( ( V_9 -> V_32 != V_33 ) ||
( V_9 -> V_34 == NULL ) )
continue;
F_8 ( & V_4 -> V_30 ) ;
V_70 = F_30 ( V_4 , V_9 -> V_44 ) ;
F_6 ( & V_4 -> V_30 ) ;
}
F_8 ( & V_4 -> V_30 ) ;
}
struct V_1 * F_31 (
struct V_3 * V_4 ,
struct V_1 * V_71 ,
const char * V_23 ,
T_1 V_45 )
{
struct V_1 * V_11 = NULL ;
F_2 ( & V_4 -> V_25 ) ;
V_11 = F_11 ( V_4 , V_23 ) ;
if ( V_11 ) {
if ( V_11 -> V_26 ) {
V_11 -> V_26 = 0 ;
F_15 ( L_16
L_17 , V_4 -> V_18 -> V_19 () ,
V_4 -> V_18 -> V_43 ( V_4 ) , V_23 ) ;
F_4 ( & V_4 -> V_25 ) ;
if ( V_71 )
V_4 -> V_18 -> V_66 ( V_4 ,
V_71 ) ;
goto V_72;
}
F_3 ( L_18
L_19
L_20 , V_4 -> V_18 -> V_19 () ,
V_23 , V_4 -> V_18 -> V_43 ( V_4 ) ) ;
F_4 ( & V_4 -> V_25 ) ;
return F_32 ( - V_73 ) ;
}
F_4 ( & V_4 -> V_25 ) ;
if ( ! V_71 ) {
F_3 ( L_21 ) ;
return F_32 ( - V_74 ) ;
}
V_11 = V_71 ;
F_21 ( & V_11 -> V_55 ) ;
F_21 ( & V_11 -> V_56 ) ;
F_20 ( & V_11 -> V_13 ) ;
F_20 ( & V_11 -> V_57 ) ;
F_19 ( & V_11 -> V_58 , 0 ) ;
V_11 -> V_45 = V_45 ;
snprintf ( V_11 -> V_23 , V_60 , L_13 , V_23 ) ;
V_11 -> V_61 = V_4 ;
V_11 -> V_62 = F_23 ( V_63 ) ;
F_20 ( & V_11 -> V_64 ) ;
V_4 -> V_18 -> V_65 ( V_11 ) ;
if ( F_17 ( V_11 ) < 0 ) {
V_4 -> V_18 -> V_66 ( V_4 , V_11 ) ;
return F_32 ( - V_47 ) ;
}
if ( F_16 ( V_4 , V_11 ) < 0 ) {
F_24 ( V_11 , V_4 ) ;
V_4 -> V_18 -> V_66 ( V_4 , V_11 ) ;
return F_32 ( - V_74 ) ;
}
F_2 ( & V_4 -> V_25 ) ;
F_25 ( & V_11 -> V_55 , & V_4 -> V_68 ) ;
V_4 -> V_69 ++ ;
F_4 ( & V_4 -> V_25 ) ;
V_72:
F_15 ( L_22
L_15 , V_4 -> V_18 -> V_19 () ,
V_4 -> V_18 -> V_43 ( V_4 ) , V_11 -> V_45 ,
V_4 -> V_18 -> V_19 () , V_23 ) ;
return V_11 ;
}
int F_33 (
struct V_3 * V_4 ,
struct V_1 * V_11 ,
int V_75 )
{
struct V_76 * V_77 , * V_78 ;
int V_79 = 0 ;
F_2 ( & V_4 -> V_25 ) ;
if ( V_11 -> V_26 ) {
V_11 -> V_26 = 0 ;
V_79 = 1 ;
}
F_9 ( & V_11 -> V_55 ) ;
V_4 -> V_69 -- ;
F_4 ( & V_4 -> V_25 ) ;
F_34 ( & V_4 -> V_80 ) ;
F_7 (sess, sess_tmp,
&tpg->tpg_sess_list, sess_list) {
if ( V_77 -> V_1 != V_11 )
continue;
if ( ! V_4 -> V_18 -> V_81 ( V_77 ) )
continue;
F_35 ( & V_4 -> V_80 ) ;
V_4 -> V_18 -> V_82 ( V_77 ) ;
F_34 ( & V_4 -> V_80 ) ;
}
F_35 ( & V_4 -> V_80 ) ;
F_26 ( V_11 ) ;
F_1 ( V_11 , V_4 ) ;
F_24 ( V_11 , V_4 ) ;
F_15 ( L_23
L_15 , V_4 -> V_18 -> V_19 () ,
V_4 -> V_18 -> V_43 ( V_4 ) , V_11 -> V_45 ,
V_4 -> V_18 -> V_19 () , V_11 -> V_23 ) ;
return 0 ;
}
int F_36 (
struct V_3 * V_4 ,
unsigned char * V_23 ,
T_1 V_45 ,
int V_75 )
{
struct V_76 * V_77 , * V_83 = NULL ;
struct V_1 * V_11 ;
int V_79 = 0 ;
F_2 ( & V_4 -> V_25 ) ;
V_11 = F_11 ( V_4 , V_23 ) ;
if ( ! V_11 ) {
F_3 ( L_24
L_25
L_20 , V_4 -> V_18 -> V_19 () ,
V_23 , V_4 -> V_18 -> V_43 ( V_4 ) ) ;
F_4 ( & V_4 -> V_25 ) ;
return - V_84 ;
}
if ( V_11 -> V_26 ) {
V_11 -> V_26 = 0 ;
V_79 = 1 ;
}
F_4 ( & V_4 -> V_25 ) ;
F_34 ( & V_4 -> V_80 ) ;
F_12 (sess, &tpg->tpg_sess_list, sess_list) {
if ( V_77 -> V_1 != V_11 )
continue;
if ( ! V_75 ) {
F_3 ( L_26
L_27
L_28
L_29
L_30 ,
V_4 -> V_18 -> V_19 () , V_23 ) ;
F_35 ( & V_4 -> V_80 ) ;
F_2 ( & V_4 -> V_25 ) ;
if ( V_79 )
V_11 -> V_26 = 1 ;
F_4 ( & V_4 -> V_25 ) ;
return - V_73 ;
}
if ( ! V_4 -> V_18 -> V_81 ( V_77 ) )
continue;
V_83 = V_77 ;
break;
}
V_11 -> V_45 = V_45 ;
if ( F_16 ( V_4 , V_11 ) < 0 ) {
F_35 ( & V_4 -> V_80 ) ;
if ( V_83 )
V_4 -> V_18 -> V_82 ( V_83 ) ;
F_2 ( & V_4 -> V_25 ) ;
if ( V_79 )
V_11 -> V_26 = 1 ;
F_4 ( & V_4 -> V_25 ) ;
return - V_74 ;
}
F_35 ( & V_4 -> V_80 ) ;
if ( V_83 )
V_4 -> V_18 -> V_82 ( V_83 ) ;
F_15 ( L_31
L_32 , V_45 ,
V_23 , V_4 -> V_18 -> V_19 () ,
V_4 -> V_18 -> V_43 ( V_4 ) ) ;
F_2 ( & V_4 -> V_25 ) ;
if ( V_79 )
V_11 -> V_26 = 1 ;
F_4 ( & V_4 -> V_25 ) ;
return 0 ;
}
static int F_37 ( struct V_3 * V_61 )
{
struct V_28 * V_29 = V_85 ;
struct V_8 * V_9 = & V_61 -> V_86 ;
T_1 V_27 = V_38 ;
int V_70 ;
V_9 -> V_44 = 0 ;
V_9 -> V_32 = V_87 ;
F_19 ( & V_9 -> V_88 , 0 ) ;
F_38 ( & V_9 -> V_89 ) ;
F_21 ( & V_9 -> V_90 ) ;
F_21 ( & V_9 -> V_91 ) ;
F_20 ( & V_9 -> V_22 ) ;
F_20 ( & V_9 -> V_92 ) ;
F_20 ( & V_9 -> V_93 ) ;
V_70 = F_39 ( V_61 , V_9 , V_27 , V_29 ) ;
if ( V_70 < 0 )
return V_70 ;
return 0 ;
}
static void F_40 ( struct V_3 * V_61 )
{
struct V_8 * V_9 = & V_61 -> V_86 ;
F_41 ( V_61 , V_9 ) ;
}
int F_42 (
struct V_94 * V_95 ,
struct V_96 * V_96 ,
struct V_3 * V_61 ,
void * V_97 ,
int V_98 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
V_61 -> V_31 = F_18 ( ( sizeof( struct V_8 ) *
V_14 ) , V_46 ) ;
if ( ! V_61 -> V_31 ) {
F_3 ( L_33
L_34 ) ;
return - V_47 ;
}
for ( V_5 = 0 ; V_5 < V_14 ; V_5 ++ ) {
V_9 = & V_61 -> V_31 [ V_5 ] ;
V_9 -> V_44 = V_5 ;
V_9 -> V_32 = V_87 ;
F_19 ( & V_9 -> V_88 , 0 ) ;
F_38 ( & V_9 -> V_89 ) ;
F_21 ( & V_9 -> V_90 ) ;
F_21 ( & V_9 -> V_91 ) ;
F_20 ( & V_9 -> V_22 ) ;
F_20 ( & V_9 -> V_92 ) ;
F_20 ( & V_9 -> V_93 ) ;
}
V_61 -> V_98 = V_98 ;
V_61 -> V_99 = V_97 ;
V_61 -> V_18 = V_95 ;
V_61 -> V_100 = V_96 ;
F_19 ( & V_61 -> V_101 , 0 ) ;
F_21 ( & V_61 -> V_68 ) ;
F_21 ( & V_61 -> V_102 ) ;
F_21 ( & V_61 -> V_103 ) ;
F_20 ( & V_61 -> V_25 ) ;
F_20 ( & V_61 -> V_80 ) ;
F_20 ( & V_61 -> V_30 ) ;
if ( V_61 -> V_98 == V_104 ) {
if ( F_37 ( V_61 ) < 0 ) {
F_10 ( V_61 ) ;
return - V_47 ;
}
}
F_34 ( & V_105 ) ;
F_25 ( & V_61 -> V_102 , & V_106 ) ;
F_35 ( & V_105 ) ;
F_15 ( L_35
L_36 , V_95 -> V_19 () ,
( V_61 -> V_98 == V_104 ) ?
L_37 : L_38 , ( V_95 -> V_107 ( V_61 ) == NULL ) ?
L_39 : V_95 -> V_107 ( V_61 ) , V_95 -> V_43 ( V_61 ) ) ;
return 0 ;
}
int F_43 ( struct V_3 * V_61 )
{
struct V_1 * V_2 , * V_108 ;
F_15 ( L_40
L_41 ,
( V_61 -> V_98 == V_104 ) ?
L_37 : L_38 , V_61 -> V_18 -> V_19 () ,
V_61 -> V_18 -> V_107 ( V_61 ) ,
V_61 -> V_18 -> V_43 ( V_61 ) ) ;
F_34 ( & V_105 ) ;
F_9 ( & V_61 -> V_102 ) ;
F_35 ( & V_105 ) ;
while ( F_27 ( & V_61 -> V_101 ) != 0 )
F_28 () ;
F_2 ( & V_61 -> V_25 ) ;
F_7 (nacl, nacl_tmp, &se_tpg->acl_node_list,
acl_list) {
F_9 ( & V_2 -> V_55 ) ;
V_61 -> V_69 -- ;
F_4 ( & V_61 -> V_25 ) ;
F_26 ( V_2 ) ;
F_24 ( V_2 , V_61 ) ;
V_61 -> V_18 -> V_66 ( V_61 , V_2 ) ;
F_2 ( & V_61 -> V_25 ) ;
}
F_4 ( & V_61 -> V_25 ) ;
if ( V_61 -> V_98 == V_104 )
F_40 ( V_61 ) ;
V_61 -> V_99 = NULL ;
F_10 ( V_61 -> V_31 ) ;
return 0 ;
}
struct V_8 * F_44 (
struct V_3 * V_4 ,
T_1 V_44 )
{
struct V_8 * V_9 ;
if ( V_44 > ( V_14 - 1 ) ) {
F_3 ( L_42
L_43 ,
V_4 -> V_18 -> V_19 () ,
V_44 , V_14 - 1 ,
V_4 -> V_18 -> V_43 ( V_4 ) ) ;
return F_32 ( - V_109 ) ;
}
F_6 ( & V_4 -> V_30 ) ;
V_9 = & V_4 -> V_31 [ V_44 ] ;
if ( V_9 -> V_32 == V_33 ) {
F_3 ( L_44
L_45 ,
V_44 , V_4 -> V_18 -> V_19 () ,
V_4 -> V_18 -> V_43 ( V_4 ) ) ;
F_8 ( & V_4 -> V_30 ) ;
return F_32 ( - V_74 ) ;
}
F_8 ( & V_4 -> V_30 ) ;
return V_9 ;
}
int F_39 (
struct V_3 * V_4 ,
struct V_8 * V_9 ,
T_1 V_27 ,
void * V_110 )
{
int V_70 ;
V_70 = F_45 ( V_110 , V_4 , V_9 ) ;
if ( V_70 < 0 )
return V_70 ;
F_6 ( & V_4 -> V_30 ) ;
V_9 -> V_27 = V_27 ;
V_9 -> V_32 = V_33 ;
F_8 ( & V_4 -> V_30 ) ;
return 0 ;
}
static void F_46 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_47 ( V_9 , V_4 ) ;
F_48 ( V_9 ) ;
}
struct V_8 * F_49 (
struct V_3 * V_4 ,
T_1 V_44 ,
int * V_70 )
{
struct V_8 * V_9 ;
if ( V_44 > ( V_14 - 1 ) ) {
F_3 ( L_42
L_43 ,
V_4 -> V_18 -> V_19 () , V_44 ,
V_14 - 1 ,
V_4 -> V_18 -> V_43 ( V_4 ) ) ;
return F_32 ( - V_109 ) ;
}
F_6 ( & V_4 -> V_30 ) ;
V_9 = & V_4 -> V_31 [ V_44 ] ;
if ( V_9 -> V_32 != V_33 ) {
F_3 ( L_46
L_47 ,
V_4 -> V_18 -> V_19 () , V_44 ,
V_4 -> V_18 -> V_43 ( V_4 ) ) ;
F_8 ( & V_4 -> V_30 ) ;
return F_32 ( - V_84 ) ;
}
F_8 ( & V_4 -> V_30 ) ;
return V_9 ;
}
int F_41 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_46 ( V_4 , V_9 ) ;
F_50 ( V_9 -> V_34 , V_4 , V_9 ) ;
F_6 ( & V_4 -> V_30 ) ;
V_9 -> V_32 = V_87 ;
F_8 ( & V_4 -> V_30 ) ;
return 0 ;
}
