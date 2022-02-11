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
V_18 , V_2 , V_4 ) ;
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
V_23 = V_32 ;
} else {
if ( V_25 -> V_33 -> V_34 ( V_25 ) == V_35 )
V_23 = V_36 ;
else
V_23 = V_32 ;
}
F_12 ( L_3
L_4 ,
V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_37 ( V_4 ) , V_9 -> V_38 ,
( V_23 == V_32 ) ?
L_5 : L_6 ) ;
F_13 ( V_9 , NULL , V_9 -> V_38 ,
V_23 , V_20 , V_4 ) ;
F_10 ( & V_4 -> V_26 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
}
static int F_14 (
struct V_3 * V_4 ,
struct V_1 * V_20 )
{
if ( ! V_20 -> V_39 ) {
F_3 ( L_7
L_8 , V_4 -> V_15 -> V_16 () ,
V_20 -> V_19 ) ;
V_20 -> V_39 = 1 ;
}
return 0 ;
}
void F_15 ( void * V_40 , int V_41 )
{
void * * V_42 = V_40 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_41 ; V_5 ++ )
F_16 ( V_42 [ V_5 ] ) ;
F_16 ( V_42 ) ;
}
static void * F_17 ( int V_41 , T_2 V_43 , T_3 V_44 )
{
void * * V_42 ;
int V_5 ;
V_42 = F_18 ( V_41 * sizeof( void * ) , V_44 ) ;
if ( ! V_42 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_41 ; V_5 ++ ) {
V_42 [ V_5 ] = F_18 ( V_43 , V_44 ) ;
if ( ! V_42 [ V_5 ] ) {
F_15 ( V_42 , V_41 ) ;
return NULL ;
}
}
return V_42 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_5 ;
V_2 -> V_12 = F_17 ( V_11 ,
sizeof( struct V_6 ) , V_45 ) ;
if ( ! V_2 -> V_12 ) {
F_3 ( L_9
L_10 ) ;
return - V_46 ;
}
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_7 = V_2 -> V_12 [ V_5 ] ;
F_20 ( & V_7 -> V_47 , 0 ) ;
F_20 ( & V_7 -> V_48 , 0 ) ;
F_21 ( & V_7 -> V_49 ) ;
F_22 ( & V_7 -> V_50 ) ;
F_22 ( & V_7 -> V_51 ) ;
}
return 0 ;
}
struct V_1 * F_23 (
struct V_3 * V_4 ,
unsigned char * V_19 )
{
struct V_1 * V_20 ;
V_20 = F_8 ( V_4 , V_19 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_4 -> V_15 -> V_52 ( V_4 ) )
return NULL ;
V_20 = V_4 -> V_15 -> V_53 ( V_4 ) ;
if ( ! V_20 )
return NULL ;
F_22 ( & V_20 -> V_54 ) ;
F_22 ( & V_20 -> V_55 ) ;
F_24 ( & V_20 -> V_56 ) ;
F_25 ( & V_20 -> V_57 ) ;
F_21 ( & V_20 -> V_10 ) ;
F_21 ( & V_20 -> V_58 ) ;
F_20 ( & V_20 -> V_59 , 0 ) ;
V_20 -> V_39 = V_4 -> V_15 -> V_60 ( V_4 ) ;
snprintf ( V_20 -> V_19 , V_61 , L_11 , V_19 ) ;
V_20 -> V_62 = V_4 ;
V_20 -> V_63 = F_26 ( V_64 ) ;
F_21 ( & V_20 -> V_65 ) ;
V_20 -> V_22 = 1 ;
V_4 -> V_15 -> V_66 ( V_20 ) ;
if ( F_19 ( V_20 ) < 0 ) {
V_4 -> V_15 -> V_67 ( V_4 , V_20 ) ;
return NULL ;
}
if ( F_14 ( V_4 , V_20 ) < 0 ) {
F_27 ( V_20 , V_4 ) ;
V_4 -> V_15 -> V_67 ( V_4 , V_20 ) ;
return NULL ;
}
if ( ( V_4 -> V_15 -> V_68 == NULL ) ||
( V_4 -> V_15 -> V_68 ( V_4 ) != 1 ) )
F_9 ( V_20 , V_4 ) ;
F_2 ( & V_4 -> V_21 ) ;
F_28 ( & V_20 -> V_54 , & V_4 -> V_69 ) ;
V_4 -> V_70 ++ ;
F_4 ( & V_4 -> V_21 ) ;
F_12 ( L_12
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_37 ( V_4 ) , V_20 -> V_39 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
return V_20 ;
}
void F_29 ( struct V_1 * V_2 )
{
while ( F_30 ( & V_2 -> V_59 ) != 0 )
F_31 () ;
}
void F_32 ( struct V_3 * V_4 )
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
F_33 ( V_4 , V_9 -> V_38 ) ;
F_10 ( & V_4 -> V_26 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
}
struct V_1 * F_34 (
struct V_3 * V_4 ,
struct V_1 * V_71 ,
const char * V_19 ,
T_1 V_39 )
{
struct V_1 * V_20 = NULL ;
F_2 ( & V_4 -> V_21 ) ;
V_20 = F_6 ( V_4 , V_19 ) ;
if ( V_20 ) {
if ( V_20 -> V_22 ) {
V_20 -> V_22 = 0 ;
F_12 ( L_14
L_15 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_37 ( V_4 ) , V_19 ) ;
F_4 ( & V_4 -> V_21 ) ;
if ( V_71 )
V_4 -> V_15 -> V_67 ( V_4 ,
V_71 ) ;
goto V_72;
}
F_3 ( L_16
L_17
L_18 , V_4 -> V_15 -> V_16 () ,
V_19 , V_4 -> V_15 -> V_37 ( V_4 ) ) ;
F_4 ( & V_4 -> V_21 ) ;
return F_35 ( - V_73 ) ;
}
F_4 ( & V_4 -> V_21 ) ;
if ( ! V_71 ) {
F_3 ( L_19 ) ;
return F_35 ( - V_74 ) ;
}
V_20 = V_71 ;
F_22 ( & V_20 -> V_54 ) ;
F_22 ( & V_20 -> V_55 ) ;
F_24 ( & V_20 -> V_56 ) ;
F_25 ( & V_20 -> V_57 ) ;
F_21 ( & V_20 -> V_10 ) ;
F_21 ( & V_20 -> V_58 ) ;
F_20 ( & V_20 -> V_59 , 0 ) ;
V_20 -> V_39 = V_39 ;
snprintf ( V_20 -> V_19 , V_61 , L_11 , V_19 ) ;
V_20 -> V_62 = V_4 ;
V_20 -> V_63 = F_26 ( V_64 ) ;
F_21 ( & V_20 -> V_65 ) ;
V_4 -> V_15 -> V_66 ( V_20 ) ;
if ( F_19 ( V_20 ) < 0 ) {
V_4 -> V_15 -> V_67 ( V_4 , V_20 ) ;
return F_35 ( - V_46 ) ;
}
if ( F_14 ( V_4 , V_20 ) < 0 ) {
F_27 ( V_20 , V_4 ) ;
V_4 -> V_15 -> V_67 ( V_4 , V_20 ) ;
return F_35 ( - V_74 ) ;
}
F_2 ( & V_4 -> V_21 ) ;
F_28 ( & V_20 -> V_54 , & V_4 -> V_69 ) ;
V_4 -> V_70 ++ ;
F_4 ( & V_4 -> V_21 ) ;
V_72:
F_12 ( L_20
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_37 ( V_4 ) , V_20 -> V_39 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
return V_20 ;
}
int F_36 (
struct V_3 * V_4 ,
struct V_1 * V_20 ,
int V_75 )
{
F_37 ( V_76 ) ;
struct V_77 * V_78 , * V_79 ;
unsigned long V_44 ;
int V_80 ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_20 -> V_22 ) {
V_20 -> V_22 = 0 ;
}
F_38 ( & V_20 -> V_54 ) ;
V_4 -> V_70 -- ;
F_4 ( & V_4 -> V_21 ) ;
F_39 ( & V_20 -> V_58 , V_44 ) ;
V_20 -> V_81 = 1 ;
F_40 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_78 -> V_82 != 0 )
continue;
F_41 ( V_78 ) ;
F_42 ( & V_78 -> V_83 , & V_76 ) ;
}
F_43 ( & V_20 -> V_58 , V_44 ) ;
F_40 (sess, sess_tmp, &sess_list, sess_acl_list) {
F_38 ( & V_78 -> V_83 ) ;
V_80 = V_4 -> V_15 -> V_84 ( V_78 ) ;
F_44 ( V_78 ) ;
if ( ! V_80 )
continue;
F_44 ( V_78 ) ;
}
F_45 ( V_20 ) ;
F_46 ( & V_20 -> V_57 ) ;
F_29 ( V_20 ) ;
F_1 ( V_20 , V_4 ) ;
F_27 ( V_20 , V_4 ) ;
F_12 ( L_21
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_37 ( V_4 ) , V_20 -> V_39 ,
V_4 -> V_15 -> V_16 () , V_20 -> V_19 ) ;
return 0 ;
}
int F_47 (
struct V_3 * V_4 ,
unsigned char * V_19 ,
T_1 V_39 ,
int V_75 )
{
struct V_77 * V_78 , * V_85 = NULL ;
struct V_1 * V_20 ;
unsigned long V_44 ;
int V_86 = 0 ;
F_2 ( & V_4 -> V_21 ) ;
V_20 = F_6 ( V_4 , V_19 ) ;
if ( ! V_20 ) {
F_3 ( L_22
L_23
L_18 , V_4 -> V_15 -> V_16 () ,
V_19 , V_4 -> V_15 -> V_37 ( V_4 ) ) ;
F_4 ( & V_4 -> V_21 ) ;
return - V_87 ;
}
if ( V_20 -> V_22 ) {
V_20 -> V_22 = 0 ;
V_86 = 1 ;
}
F_4 ( & V_4 -> V_21 ) ;
F_39 ( & V_4 -> V_88 , V_44 ) ;
F_7 (sess, &tpg->tpg_sess_list, sess_list) {
if ( V_78 -> V_1 != V_20 )
continue;
if ( ! V_75 ) {
F_3 ( L_24
L_25
L_26
L_27
L_28 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
F_43 ( & V_4 -> V_88 , V_44 ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_86 )
V_20 -> V_22 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return - V_73 ;
}
if ( ! V_4 -> V_15 -> V_84 ( V_78 ) )
continue;
V_85 = V_78 ;
break;
}
V_20 -> V_39 = V_39 ;
if ( F_14 ( V_4 , V_20 ) < 0 ) {
F_43 ( & V_4 -> V_88 , V_44 ) ;
if ( V_85 )
V_4 -> V_15 -> V_89 ( V_85 ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_86 )
V_20 -> V_22 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return - V_74 ;
}
F_43 ( & V_4 -> V_88 , V_44 ) ;
if ( V_85 )
V_4 -> V_15 -> V_89 ( V_85 ) ;
F_12 ( L_29
L_30 , V_39 ,
V_19 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_37 ( V_4 ) ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_86 )
V_20 -> V_22 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return 0 ;
}
int F_48 (
struct V_3 * V_4 ,
struct V_1 * V_20 ,
const char * V_90 )
{
if ( strlen ( V_90 ) >= V_91 )
return - V_74 ;
if ( ! strncmp ( L_31 , V_90 , 4 ) ) {
V_20 -> V_92 [ 0 ] = '\0' ;
return 0 ;
}
return snprintf ( V_20 -> V_92 , V_91 , L_11 , V_90 ) ;
}
static int F_49 ( struct V_3 * V_62 )
{
struct V_24 * V_25 = V_93 ;
struct V_8 * V_9 = & V_62 -> V_94 ;
T_1 V_23 = V_36 ;
int V_95 ;
V_9 -> V_38 = 0 ;
V_9 -> V_28 = V_96 ;
F_20 ( & V_9 -> V_97 , 0 ) ;
F_25 ( & V_9 -> V_98 ) ;
F_22 ( & V_9 -> V_99 ) ;
F_22 ( & V_9 -> V_100 ) ;
F_21 ( & V_9 -> V_101 ) ;
F_21 ( & V_9 -> V_102 ) ;
F_21 ( & V_9 -> V_103 ) ;
V_95 = F_50 ( V_62 , V_9 , V_23 , V_25 ) ;
if ( V_95 < 0 )
return V_95 ;
return 0 ;
}
static void F_51 ( struct V_3 * V_62 )
{
struct V_8 * V_9 = & V_62 -> V_94 ;
F_52 ( V_62 , V_9 ) ;
}
int F_53 (
struct V_104 * V_105 ,
struct V_106 * V_106 ,
struct V_3 * V_62 ,
void * V_107 ,
int V_108 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
V_62 -> V_27 = F_17 ( V_11 ,
sizeof( struct V_8 ) , V_45 ) ;
if ( ! V_62 -> V_27 ) {
F_3 ( L_32
L_33 ) ;
return - V_46 ;
}
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_9 = V_62 -> V_27 [ V_5 ] ;
V_9 -> V_38 = V_5 ;
V_9 -> V_109 = V_110 ;
V_9 -> V_28 = V_96 ;
F_20 ( & V_9 -> V_97 , 0 ) ;
F_25 ( & V_9 -> V_98 ) ;
F_22 ( & V_9 -> V_99 ) ;
F_22 ( & V_9 -> V_100 ) ;
F_21 ( & V_9 -> V_101 ) ;
F_21 ( & V_9 -> V_102 ) ;
F_21 ( & V_9 -> V_103 ) ;
}
V_62 -> V_108 = V_108 ;
V_62 -> V_111 = V_107 ;
V_62 -> V_15 = V_105 ;
V_62 -> V_112 = V_106 ;
F_20 ( & V_62 -> V_113 , 0 ) ;
F_22 ( & V_62 -> V_69 ) ;
F_22 ( & V_62 -> V_114 ) ;
F_22 ( & V_62 -> V_115 ) ;
F_21 ( & V_62 -> V_21 ) ;
F_21 ( & V_62 -> V_88 ) ;
F_21 ( & V_62 -> V_26 ) ;
if ( V_62 -> V_108 == V_116 ) {
if ( F_49 ( V_62 ) < 0 ) {
F_16 ( V_62 ) ;
return - V_46 ;
}
}
F_54 ( & V_117 ) ;
F_28 ( & V_62 -> V_114 , & V_118 ) ;
F_55 ( & V_117 ) ;
F_12 ( L_34
L_35 , V_105 -> V_16 () ,
( V_62 -> V_108 == V_116 ) ?
L_36 : L_37 , ( V_105 -> V_119 ( V_62 ) == NULL ) ?
L_38 : V_105 -> V_119 ( V_62 ) , V_105 -> V_37 ( V_62 ) ) ;
return 0 ;
}
int F_56 ( struct V_3 * V_62 )
{
struct V_1 * V_2 , * V_120 ;
F_12 ( L_39
L_40 ,
( V_62 -> V_108 == V_116 ) ?
L_36 : L_37 , V_62 -> V_15 -> V_16 () ,
V_62 -> V_15 -> V_119 ( V_62 ) ,
V_62 -> V_15 -> V_37 ( V_62 ) ) ;
F_54 ( & V_117 ) ;
F_38 ( & V_62 -> V_114 ) ;
F_55 ( & V_117 ) ;
while ( F_30 ( & V_62 -> V_113 ) != 0 )
F_31 () ;
F_2 ( & V_62 -> V_21 ) ;
F_40 (nacl, nacl_tmp, &se_tpg->acl_node_list,
acl_list) {
F_38 ( & V_2 -> V_54 ) ;
V_62 -> V_70 -- ;
F_4 ( & V_62 -> V_21 ) ;
F_29 ( V_2 ) ;
F_27 ( V_2 , V_62 ) ;
V_62 -> V_15 -> V_67 ( V_62 , V_2 ) ;
F_2 ( & V_62 -> V_21 ) ;
}
F_4 ( & V_62 -> V_21 ) ;
if ( V_62 -> V_108 == V_116 )
F_51 ( V_62 ) ;
V_62 -> V_111 = NULL ;
F_15 ( V_62 -> V_27 , V_11 ) ;
return 0 ;
}
struct V_8 * F_57 (
struct V_3 * V_4 ,
T_1 V_38 )
{
struct V_8 * V_9 ;
if ( V_38 > ( V_11 - 1 ) ) {
F_3 ( L_41
L_42 ,
V_4 -> V_15 -> V_16 () ,
V_38 , V_11 - 1 ,
V_4 -> V_15 -> V_37 ( V_4 ) ) ;
return F_35 ( - V_121 ) ;
}
F_10 ( & V_4 -> V_26 ) ;
V_9 = V_4 -> V_27 [ V_38 ] ;
if ( V_9 -> V_28 == V_29 ) {
F_3 ( L_43
L_44 ,
V_38 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_37 ( V_4 ) ) ;
F_11 ( & V_4 -> V_26 ) ;
return F_35 ( - V_74 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
return V_9 ;
}
int F_50 (
struct V_3 * V_4 ,
struct V_8 * V_9 ,
T_1 V_23 ,
void * V_122 )
{
int V_95 ;
V_95 = F_58 ( V_122 , V_4 , V_9 ) ;
if ( V_95 < 0 )
return V_95 ;
F_10 ( & V_4 -> V_26 ) ;
V_9 -> V_23 = V_23 ;
V_9 -> V_28 = V_29 ;
F_11 ( & V_4 -> V_26 ) ;
return 0 ;
}
static void F_59 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_60 ( V_9 , V_4 ) ;
F_61 ( V_9 ) ;
}
struct V_8 * F_62 (
struct V_3 * V_4 ,
T_1 V_38 )
{
struct V_8 * V_9 ;
if ( V_38 > ( V_11 - 1 ) ) {
F_3 ( L_41
L_42 ,
V_4 -> V_15 -> V_16 () , V_38 ,
V_11 - 1 ,
V_4 -> V_15 -> V_37 ( V_4 ) ) ;
return F_35 ( - V_121 ) ;
}
F_10 ( & V_4 -> V_26 ) ;
V_9 = V_4 -> V_27 [ V_38 ] ;
if ( V_9 -> V_28 != V_29 ) {
F_3 ( L_45
L_46 ,
V_4 -> V_15 -> V_16 () , V_38 ,
V_4 -> V_15 -> V_37 ( V_4 ) ) ;
F_11 ( & V_4 -> V_26 ) ;
return F_35 ( - V_87 ) ;
}
F_11 ( & V_4 -> V_26 ) ;
return V_9 ;
}
int F_52 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_59 ( V_4 , V_9 ) ;
F_63 ( V_9 -> V_30 , V_4 , V_9 ) ;
F_10 ( & V_4 -> V_26 ) ;
V_9 -> V_28 = V_96 ;
F_11 ( & V_4 -> V_26 ) ;
return 0 ;
}
