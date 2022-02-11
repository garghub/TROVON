static void F_1 (
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
F_2 ( & V_2 -> V_10 ) ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_7 = V_2 -> V_12 [ V_5 ] ;
if ( ! ( V_7 -> V_13 & V_14 ) )
continue;
if ( ! V_7 -> V_8 ) {
F_3 ( L_1
L_2 ,
V_4 -> V_15 -> V_16 () ) ;
continue;
}
V_9 = V_7 -> V_8 ;
F_4 ( & V_2 -> V_10 ) ;
F_5 ( V_9 , NULL , V_7 -> V_17 ,
V_18 , V_2 , V_4 , 0 ) ;
F_2 ( & V_2 -> V_10 ) ;
}
F_4 ( & V_2 -> V_10 ) ;
}
struct V_1 * F_6 (
struct V_3 * V_4 ,
const char * V_19 )
{
struct V_1 * V_20 ;
F_7 (acl, &tpg->acl_node_list, acl_list) {
if ( ! strcmp ( V_20 -> V_19 , V_19 ) )
return V_20 ;
}
return NULL ;
}
struct V_1 * F_8 (
struct V_3 * V_4 ,
unsigned char * V_19 )
{
struct V_1 * V_20 ;
F_2 ( & V_4 -> V_21 ) ;
F_7 (acl, &tpg->acl_node_list, acl_list) {
if ( ! strcmp ( V_20 -> V_19 , V_19 ) &&
! V_20 -> V_22 ) {
F_4 ( & V_4 -> V_21 ) ;
return V_20 ;
}
}
F_4 ( & V_4 -> V_21 ) ;
return NULL ;
}
void F_9 (
struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
T_1 V_23 = 0 ;
struct V_8 * V_9 ;
struct V_24 * V_25 ;
F_10 ( & V_4 -> V_26 ) ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_9 = V_4 -> V_27 [ V_5 ] ;
if ( V_9 -> V_28 != V_29 )
continue;
F_11 ( & V_4 -> V_26 ) ;
V_25 = V_9 -> V_30 ;
if ( ! V_4 -> V_15 -> V_31 ( V_4 ) ) {
if ( V_25 -> V_32 & V_33 )
V_23 = V_34 ;
else
V_23 = V_35 ;
} else {
if ( V_25 -> V_36 -> V_37 ( V_25 ) == V_38 )
V_23 = V_34 ;
else
V_23 = V_35 ;
}
F_12 ( L_3
L_4 ,
V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_39 ( V_4 ) , V_9 -> V_40 ,
( V_23 == V_35 ) ?
L_5 : L_6 ) ;
F_5 ( V_9 , NULL , V_9 -> V_40 ,
V_23 , V_20 , V_4 , 1 ) ;
F_10 ( & V_4 -> V_26 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
}
static int F_13 (
struct V_3 * V_4 ,
struct V_1 * V_20 )
{
if ( ! V_20 -> V_41 ) {
F_3 ( L_7
L_8 , V_4 -> V_15 -> V_16 () ,
V_20 -> V_19 ) ;
V_20 -> V_41 = 1 ;
}
return 0 ;
}
void F_14 ( void * V_42 , int V_43 )
{
void * * V_44 = V_42 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_43 ; V_5 ++ )
F_15 ( V_44 [ V_5 ] ) ;
F_15 ( V_44 ) ;
}
static void * F_16 ( int V_43 , T_2 V_45 , T_3 V_46 )
{
void * * V_44 ;
int V_5 ;
V_44 = F_17 ( V_43 * sizeof( void * ) , V_46 ) ;
if ( ! V_44 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_43 ; V_5 ++ ) {
V_44 [ V_5 ] = F_17 ( V_45 , V_46 ) ;
if ( ! V_44 [ V_5 ] ) {
F_14 ( V_44 , V_43 ) ;
return NULL ;
}
}
return V_44 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_5 ;
V_2 -> V_12 = F_16 ( V_11 ,
sizeof( struct V_6 ) , V_47 ) ;
if ( ! V_2 -> V_12 ) {
F_3 ( L_9
L_10 ) ;
return - V_48 ;
}
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_7 = V_2 -> V_12 [ V_5 ] ;
F_19 ( & V_7 -> V_49 , 0 ) ;
F_19 ( & V_7 -> V_50 , 0 ) ;
F_20 ( & V_7 -> V_51 ) ;
F_21 ( & V_7 -> V_52 ) ;
F_21 ( & V_7 -> V_53 ) ;
}
return 0 ;
}
struct V_1 * F_22 (
struct V_3 * V_4 ,
unsigned char * V_19 )
{
struct V_1 * V_20 ;
V_20 = F_8 ( V_4 , V_19 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_4 -> V_15 -> V_54 ( V_4 ) )
return NULL ;
V_20 = V_4 -> V_15 -> V_55 ( V_4 ) ;
if ( ! V_20 )
return NULL ;
F_21 ( & V_20 -> V_56 ) ;
F_21 ( & V_20 -> V_57 ) ;
F_23 ( & V_20 -> V_58 ) ;
F_24 ( & V_20 -> V_59 ) ;
F_20 ( & V_20 -> V_10 ) ;
F_20 ( & V_20 -> V_60 ) ;
F_19 ( & V_20 -> V_61 , 0 ) ;
V_20 -> V_41 = V_4 -> V_15 -> V_62 ( V_4 ) ;
snprintf ( V_20 -> V_19 , V_63 , L_11 , V_19 ) ;
V_20 -> V_64 = V_4 ;
V_20 -> V_65 = F_25 ( V_66 ) ;
F_20 ( & V_20 -> V_67 ) ;
V_20 -> V_22 = 1 ;
V_4 -> V_15 -> V_68 ( V_20 ) ;
if ( F_18 ( V_20 ) < 0 ) {
V_4 -> V_15 -> V_69 ( V_4 , V_20 ) ;
return NULL ;
}
if ( F_13 ( V_4 , V_20 ) < 0 ) {
F_26 ( V_20 , V_4 ) ;
V_4 -> V_15 -> V_69 ( V_4 , V_20 ) ;
return NULL ;
}
if ( ( V_4 -> V_15 -> V_70 != NULL ) &&
( V_4 -> V_15 -> V_70 ( V_4 ) == 1 ) )
do { ; } while ( 0 );
else
F_9 ( V_20 , V_4 ) ;
F_2 ( & V_4 -> V_21 ) ;
F_27 ( & V_20 -> V_56 , & V_4 -> V_71 ) ;
V_4 -> V_72 ++ ;
F_4 ( & V_4 -> V_21 ) ;
F_12 ( L_12
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_39 ( V_4 ) , V_20 -> V_41 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
return V_20 ;
}
void F_28 ( struct V_1 * V_2 )
{
while ( F_29 ( & V_2 -> V_61 ) != 0 )
F_30 () ;
}
void F_31 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_8 * V_9 ;
F_10 ( & V_4 -> V_26 ) ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_9 = V_4 -> V_27 [ V_5 ] ;
if ( ( V_9 -> V_28 != V_29 ) ||
( V_9 -> V_30 == NULL ) )
continue;
F_11 ( & V_4 -> V_26 ) ;
F_32 ( V_4 , V_9 -> V_40 ) ;
F_10 ( & V_4 -> V_26 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
}
struct V_1 * F_33 (
struct V_3 * V_4 ,
struct V_1 * V_73 ,
const char * V_19 ,
T_1 V_41 )
{
struct V_1 * V_20 = NULL ;
F_2 ( & V_4 -> V_21 ) ;
V_20 = F_6 ( V_4 , V_19 ) ;
if ( V_20 ) {
if ( V_20 -> V_22 ) {
V_20 -> V_22 = 0 ;
F_12 ( L_14
L_15 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_39 ( V_4 ) , V_19 ) ;
F_4 ( & V_4 -> V_21 ) ;
if ( V_73 )
V_4 -> V_15 -> V_69 ( V_4 ,
V_73 ) ;
goto V_74;
}
F_3 ( L_16
L_17
L_18 , V_4 -> V_15 -> V_16 () ,
V_19 , V_4 -> V_15 -> V_39 ( V_4 ) ) ;
F_4 ( & V_4 -> V_21 ) ;
return F_34 ( - V_75 ) ;
}
F_4 ( & V_4 -> V_21 ) ;
if ( ! V_73 ) {
F_3 ( L_19 ) ;
return F_34 ( - V_76 ) ;
}
V_20 = V_73 ;
F_21 ( & V_20 -> V_56 ) ;
F_21 ( & V_20 -> V_57 ) ;
F_23 ( & V_20 -> V_58 ) ;
F_24 ( & V_20 -> V_59 ) ;
F_20 ( & V_20 -> V_10 ) ;
F_20 ( & V_20 -> V_60 ) ;
F_19 ( & V_20 -> V_61 , 0 ) ;
V_20 -> V_41 = V_41 ;
snprintf ( V_20 -> V_19 , V_63 , L_11 , V_19 ) ;
V_20 -> V_64 = V_4 ;
V_20 -> V_65 = F_25 ( V_66 ) ;
F_20 ( & V_20 -> V_67 ) ;
V_4 -> V_15 -> V_68 ( V_20 ) ;
if ( F_18 ( V_20 ) < 0 ) {
V_4 -> V_15 -> V_69 ( V_4 , V_20 ) ;
return F_34 ( - V_48 ) ;
}
if ( F_13 ( V_4 , V_20 ) < 0 ) {
F_26 ( V_20 , V_4 ) ;
V_4 -> V_15 -> V_69 ( V_4 , V_20 ) ;
return F_34 ( - V_76 ) ;
}
F_2 ( & V_4 -> V_21 ) ;
F_27 ( & V_20 -> V_56 , & V_4 -> V_71 ) ;
V_4 -> V_72 ++ ;
F_4 ( & V_4 -> V_21 ) ;
V_74:
F_12 ( L_20
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_39 ( V_4 ) , V_20 -> V_41 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
return V_20 ;
}
int F_35 (
struct V_3 * V_4 ,
struct V_1 * V_20 ,
int V_77 )
{
F_36 ( V_78 ) ;
struct V_79 * V_80 , * V_81 ;
unsigned long V_46 ;
int V_82 ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_20 -> V_22 ) {
V_20 -> V_22 = 0 ;
}
F_37 ( & V_20 -> V_56 ) ;
V_4 -> V_72 -- ;
F_4 ( & V_4 -> V_21 ) ;
F_38 ( & V_20 -> V_60 , V_46 ) ;
V_20 -> V_83 = 1 ;
F_39 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_80 -> V_84 != 0 )
continue;
F_40 ( V_80 ) ;
F_41 ( & V_80 -> V_85 , & V_78 ) ;
}
F_42 ( & V_20 -> V_60 , V_46 ) ;
F_39 (sess, sess_tmp, &sess_list, sess_acl_list) {
F_37 ( & V_80 -> V_85 ) ;
V_82 = V_4 -> V_15 -> V_86 ( V_80 ) ;
F_43 ( V_80 ) ;
if ( ! V_82 )
continue;
F_43 ( V_80 ) ;
}
F_44 ( V_20 ) ;
F_45 ( & V_20 -> V_59 ) ;
F_28 ( V_20 ) ;
F_1 ( V_20 , V_4 ) ;
F_26 ( V_20 , V_4 ) ;
F_12 ( L_21
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_39 ( V_4 ) , V_20 -> V_41 ,
V_4 -> V_15 -> V_16 () , V_20 -> V_19 ) ;
return 0 ;
}
int F_46 (
struct V_3 * V_4 ,
unsigned char * V_19 ,
T_1 V_41 ,
int V_77 )
{
struct V_79 * V_80 , * V_87 = NULL ;
struct V_1 * V_20 ;
unsigned long V_46 ;
int V_88 = 0 ;
F_2 ( & V_4 -> V_21 ) ;
V_20 = F_6 ( V_4 , V_19 ) ;
if ( ! V_20 ) {
F_3 ( L_22
L_23
L_18 , V_4 -> V_15 -> V_16 () ,
V_19 , V_4 -> V_15 -> V_39 ( V_4 ) ) ;
F_4 ( & V_4 -> V_21 ) ;
return - V_89 ;
}
if ( V_20 -> V_22 ) {
V_20 -> V_22 = 0 ;
V_88 = 1 ;
}
F_4 ( & V_4 -> V_21 ) ;
F_38 ( & V_4 -> V_90 , V_46 ) ;
F_7 (sess, &tpg->tpg_sess_list, sess_list) {
if ( V_80 -> V_1 != V_20 )
continue;
if ( ! V_77 ) {
F_3 ( L_24
L_25
L_26
L_27
L_28 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
F_42 ( & V_4 -> V_90 , V_46 ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_88 )
V_20 -> V_22 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return - V_75 ;
}
if ( ! V_4 -> V_15 -> V_86 ( V_80 ) )
continue;
V_87 = V_80 ;
break;
}
V_20 -> V_41 = V_41 ;
if ( F_13 ( V_4 , V_20 ) < 0 ) {
F_42 ( & V_4 -> V_90 , V_46 ) ;
if ( V_87 )
V_4 -> V_15 -> V_91 ( V_87 ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_88 )
V_20 -> V_22 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return - V_76 ;
}
F_42 ( & V_4 -> V_90 , V_46 ) ;
if ( V_87 )
V_4 -> V_15 -> V_91 ( V_87 ) ;
F_12 ( L_29
L_30 , V_41 ,
V_19 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_39 ( V_4 ) ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_88 )
V_20 -> V_22 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return 0 ;
}
static int F_47 ( struct V_3 * V_64 )
{
struct V_24 * V_25 = V_92 ;
struct V_8 * V_9 = & V_64 -> V_93 ;
T_1 V_23 = V_34 ;
int V_94 ;
V_9 -> V_40 = 0 ;
V_9 -> V_28 = V_95 ;
F_19 ( & V_9 -> V_96 , 0 ) ;
F_24 ( & V_9 -> V_97 ) ;
F_21 ( & V_9 -> V_98 ) ;
F_21 ( & V_9 -> V_99 ) ;
F_20 ( & V_9 -> V_100 ) ;
F_20 ( & V_9 -> V_101 ) ;
F_20 ( & V_9 -> V_102 ) ;
V_94 = F_48 ( V_64 , V_9 , V_23 , V_25 ) ;
if ( V_94 < 0 )
return V_94 ;
return 0 ;
}
static void F_49 ( struct V_3 * V_64 )
{
struct V_8 * V_9 = & V_64 -> V_93 ;
F_50 ( V_64 , V_9 ) ;
}
int F_51 (
struct V_103 * V_104 ,
struct V_105 * V_105 ,
struct V_3 * V_64 ,
void * V_106 ,
int V_107 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
V_64 -> V_27 = F_16 ( V_11 ,
sizeof( struct V_8 ) , V_47 ) ;
if ( ! V_64 -> V_27 ) {
F_3 ( L_31
L_32 ) ;
return - V_48 ;
}
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_9 = V_64 -> V_27 [ V_5 ] ;
V_9 -> V_40 = V_5 ;
V_9 -> V_28 = V_95 ;
F_19 ( & V_9 -> V_96 , 0 ) ;
F_24 ( & V_9 -> V_97 ) ;
F_21 ( & V_9 -> V_98 ) ;
F_21 ( & V_9 -> V_99 ) ;
F_20 ( & V_9 -> V_100 ) ;
F_20 ( & V_9 -> V_101 ) ;
F_20 ( & V_9 -> V_102 ) ;
}
V_64 -> V_107 = V_107 ;
V_64 -> V_108 = V_106 ;
V_64 -> V_15 = V_104 ;
V_64 -> V_109 = V_105 ;
F_19 ( & V_64 -> V_110 , 0 ) ;
F_21 ( & V_64 -> V_71 ) ;
F_21 ( & V_64 -> V_111 ) ;
F_21 ( & V_64 -> V_112 ) ;
F_20 ( & V_64 -> V_21 ) ;
F_20 ( & V_64 -> V_90 ) ;
F_20 ( & V_64 -> V_26 ) ;
if ( V_64 -> V_107 == V_113 ) {
if ( F_47 ( V_64 ) < 0 ) {
F_15 ( V_64 ) ;
return - V_48 ;
}
}
F_52 ( & V_114 ) ;
F_27 ( & V_64 -> V_111 , & V_115 ) ;
F_53 ( & V_114 ) ;
F_12 ( L_33
L_34 , V_104 -> V_16 () ,
( V_64 -> V_107 == V_113 ) ?
L_35 : L_36 , ( V_104 -> V_116 ( V_64 ) == NULL ) ?
L_37 : V_104 -> V_116 ( V_64 ) , V_104 -> V_39 ( V_64 ) ) ;
return 0 ;
}
int F_54 ( struct V_3 * V_64 )
{
struct V_1 * V_2 , * V_117 ;
F_12 ( L_38
L_39 ,
( V_64 -> V_107 == V_113 ) ?
L_35 : L_36 , V_64 -> V_15 -> V_16 () ,
V_64 -> V_15 -> V_116 ( V_64 ) ,
V_64 -> V_15 -> V_39 ( V_64 ) ) ;
F_52 ( & V_114 ) ;
F_37 ( & V_64 -> V_111 ) ;
F_53 ( & V_114 ) ;
while ( F_29 ( & V_64 -> V_110 ) != 0 )
F_30 () ;
F_2 ( & V_64 -> V_21 ) ;
F_39 (nacl, nacl_tmp, &se_tpg->acl_node_list,
acl_list) {
F_37 ( & V_2 -> V_56 ) ;
V_64 -> V_72 -- ;
F_4 ( & V_64 -> V_21 ) ;
F_28 ( V_2 ) ;
F_26 ( V_2 , V_64 ) ;
V_64 -> V_15 -> V_69 ( V_64 , V_2 ) ;
F_2 ( & V_64 -> V_21 ) ;
}
F_4 ( & V_64 -> V_21 ) ;
if ( V_64 -> V_107 == V_113 )
F_49 ( V_64 ) ;
V_64 -> V_108 = NULL ;
F_14 ( V_64 -> V_27 , V_11 ) ;
return 0 ;
}
struct V_8 * F_55 (
struct V_3 * V_4 ,
T_1 V_40 )
{
struct V_8 * V_9 ;
if ( V_40 > ( V_11 - 1 ) ) {
F_3 ( L_40
L_41 ,
V_4 -> V_15 -> V_16 () ,
V_40 , V_11 - 1 ,
V_4 -> V_15 -> V_39 ( V_4 ) ) ;
return F_34 ( - V_118 ) ;
}
F_10 ( & V_4 -> V_26 ) ;
V_9 = V_4 -> V_27 [ V_40 ] ;
if ( V_9 -> V_28 == V_29 ) {
F_3 ( L_42
L_43 ,
V_40 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_39 ( V_4 ) ) ;
F_11 ( & V_4 -> V_26 ) ;
return F_34 ( - V_76 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
return V_9 ;
}
int F_48 (
struct V_3 * V_4 ,
struct V_8 * V_9 ,
T_1 V_23 ,
void * V_119 )
{
int V_94 ;
V_94 = F_56 ( V_119 , V_4 , V_9 ) ;
if ( V_94 < 0 )
return V_94 ;
F_10 ( & V_4 -> V_26 ) ;
V_9 -> V_23 = V_23 ;
V_9 -> V_28 = V_29 ;
F_11 ( & V_4 -> V_26 ) ;
return 0 ;
}
static void F_57 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_58 ( V_9 , V_4 ) ;
F_59 ( V_9 ) ;
}
struct V_8 * F_60 (
struct V_3 * V_4 ,
T_1 V_40 )
{
struct V_8 * V_9 ;
if ( V_40 > ( V_11 - 1 ) ) {
F_3 ( L_40
L_41 ,
V_4 -> V_15 -> V_16 () , V_40 ,
V_11 - 1 ,
V_4 -> V_15 -> V_39 ( V_4 ) ) ;
return F_34 ( - V_118 ) ;
}
F_10 ( & V_4 -> V_26 ) ;
V_9 = V_4 -> V_27 [ V_40 ] ;
if ( V_9 -> V_28 != V_29 ) {
F_3 ( L_44
L_45 ,
V_4 -> V_15 -> V_16 () , V_40 ,
V_4 -> V_15 -> V_39 ( V_4 ) ) ;
F_11 ( & V_4 -> V_26 ) ;
return F_34 ( - V_89 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
return V_9 ;
}
int F_50 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_57 ( V_4 , V_9 ) ;
F_61 ( V_9 -> V_30 , V_4 , V_9 ) ;
F_10 ( & V_4 -> V_26 ) ;
V_9 -> V_28 = V_95 ;
F_11 ( & V_4 -> V_26 ) ;
return 0 ;
}
