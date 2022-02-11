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
V_20 = F_6 ( V_4 , V_19 ) ;
F_4 ( & V_4 -> V_21 ) ;
return V_20 ;
}
void F_9 (
struct V_1 * V_20 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
T_1 V_22 = 0 ;
struct V_8 * V_9 ;
struct V_23 * V_24 ;
F_10 ( & V_4 -> V_25 ) ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_9 = V_4 -> V_26 [ V_5 ] ;
if ( V_9 -> V_27 != V_28 )
continue;
F_11 ( & V_4 -> V_25 ) ;
V_24 = V_9 -> V_29 ;
if ( ! V_4 -> V_15 -> V_30 ( V_4 ) ) {
V_22 = V_31 ;
} else {
if ( V_24 -> V_32 -> V_33 ( V_24 ) == V_34 )
V_22 = V_35 ;
else
V_22 = V_31 ;
}
F_12 ( L_3
L_4 ,
V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_36 ( V_4 ) , V_9 -> V_37 ,
( V_22 == V_31 ) ?
L_5 : L_6 ) ;
F_13 ( V_9 , NULL , V_9 -> V_37 ,
V_22 , V_20 , V_4 ) ;
F_10 ( & V_4 -> V_25 ) ;
}
F_11 ( & V_4 -> V_25 ) ;
}
static int F_14 (
struct V_3 * V_4 ,
struct V_1 * V_20 )
{
if ( ! V_20 -> V_38 ) {
F_3 ( L_7
L_8 , V_4 -> V_15 -> V_16 () ,
V_20 -> V_19 ) ;
V_20 -> V_38 = 1 ;
}
return 0 ;
}
void F_15 ( void * V_39 , int V_40 )
{
void * * V_41 = V_39 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ )
F_16 ( V_41 [ V_5 ] ) ;
F_16 ( V_41 ) ;
}
static void * F_17 ( int V_40 , T_2 V_42 , T_3 V_43 )
{
void * * V_41 ;
int V_5 ;
V_41 = F_18 ( V_40 * sizeof( void * ) , V_43 ) ;
if ( ! V_41 )
return NULL ;
for ( V_5 = 0 ; V_5 < V_40 ; V_5 ++ ) {
V_41 [ V_5 ] = F_18 ( V_42 , V_43 ) ;
if ( ! V_41 [ V_5 ] ) {
F_15 ( V_41 , V_40 ) ;
return NULL ;
}
}
return V_41 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
int V_5 ;
V_2 -> V_12 = F_17 ( V_11 ,
sizeof( struct V_6 ) , V_44 ) ;
if ( ! V_2 -> V_12 ) {
F_3 ( L_9
L_10 ) ;
return - V_45 ;
}
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_7 = V_2 -> V_12 [ V_5 ] ;
F_20 ( & V_7 -> V_46 , 0 ) ;
F_20 ( & V_7 -> V_47 , 0 ) ;
F_21 ( & V_7 -> V_48 ) ;
F_22 ( & V_7 -> V_49 ) ;
F_22 ( & V_7 -> V_50 ) ;
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
if ( ! V_4 -> V_15 -> V_51 ( V_4 ) )
return NULL ;
V_20 = V_4 -> V_15 -> V_52 ( V_4 ) ;
if ( ! V_20 )
return NULL ;
F_22 ( & V_20 -> V_53 ) ;
F_22 ( & V_20 -> V_54 ) ;
F_24 ( & V_20 -> V_55 ) ;
F_25 ( & V_20 -> V_56 ) ;
F_21 ( & V_20 -> V_10 ) ;
F_21 ( & V_20 -> V_57 ) ;
F_20 ( & V_20 -> V_58 , 0 ) ;
V_20 -> V_38 = V_4 -> V_15 -> V_59 ( V_4 ) ;
snprintf ( V_20 -> V_19 , V_60 , L_11 , V_19 ) ;
V_20 -> V_61 = V_4 ;
V_20 -> V_62 = F_26 ( V_63 ) ;
V_20 -> V_64 = 1 ;
V_4 -> V_15 -> V_65 ( V_20 ) ;
if ( F_19 ( V_20 ) < 0 ) {
V_4 -> V_15 -> V_66 ( V_4 , V_20 ) ;
return NULL ;
}
if ( F_14 ( V_4 , V_20 ) < 0 ) {
F_27 ( V_20 , V_4 ) ;
V_4 -> V_15 -> V_66 ( V_4 , V_20 ) ;
return NULL ;
}
if ( ( V_4 -> V_15 -> V_67 == NULL ) ||
( V_4 -> V_15 -> V_67 ( V_4 ) != 1 ) )
F_9 ( V_20 , V_4 ) ;
F_2 ( & V_4 -> V_21 ) ;
F_28 ( & V_20 -> V_53 , & V_4 -> V_68 ) ;
V_4 -> V_69 ++ ;
F_4 ( & V_4 -> V_21 ) ;
F_12 ( L_12
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_36 ( V_4 ) , V_20 -> V_38 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
return V_20 ;
}
void F_29 ( struct V_1 * V_2 )
{
while ( F_30 ( & V_2 -> V_58 ) != 0 )
F_31 () ;
}
void F_32 ( struct V_3 * V_4 )
{
int V_5 ;
struct V_8 * V_9 ;
F_10 ( & V_4 -> V_25 ) ;
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_9 = V_4 -> V_26 [ V_5 ] ;
if ( ( V_9 -> V_27 != V_28 ) ||
( V_9 -> V_29 == NULL ) )
continue;
F_11 ( & V_4 -> V_25 ) ;
F_33 ( V_4 , V_9 -> V_37 ) ;
F_10 ( & V_4 -> V_25 ) ;
}
F_11 ( & V_4 -> V_25 ) ;
}
struct V_1 * F_34 (
struct V_3 * V_4 ,
struct V_1 * V_70 ,
const char * V_19 ,
T_1 V_38 )
{
struct V_1 * V_20 = NULL ;
F_2 ( & V_4 -> V_21 ) ;
V_20 = F_6 ( V_4 , V_19 ) ;
if ( V_20 ) {
if ( V_20 -> V_64 ) {
V_20 -> V_64 = 0 ;
F_12 ( L_14
L_15 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_36 ( V_4 ) , V_19 ) ;
F_4 ( & V_4 -> V_21 ) ;
if ( V_70 )
V_4 -> V_15 -> V_66 ( V_4 ,
V_70 ) ;
goto V_71;
}
F_3 ( L_16
L_17
L_18 , V_4 -> V_15 -> V_16 () ,
V_19 , V_4 -> V_15 -> V_36 ( V_4 ) ) ;
F_4 ( & V_4 -> V_21 ) ;
return F_35 ( - V_72 ) ;
}
F_4 ( & V_4 -> V_21 ) ;
if ( ! V_70 ) {
F_3 ( L_19 ) ;
return F_35 ( - V_73 ) ;
}
V_20 = V_70 ;
F_22 ( & V_20 -> V_53 ) ;
F_22 ( & V_20 -> V_54 ) ;
F_24 ( & V_20 -> V_55 ) ;
F_25 ( & V_20 -> V_56 ) ;
F_21 ( & V_20 -> V_10 ) ;
F_21 ( & V_20 -> V_57 ) ;
F_20 ( & V_20 -> V_58 , 0 ) ;
V_20 -> V_38 = V_38 ;
snprintf ( V_20 -> V_19 , V_60 , L_11 , V_19 ) ;
V_20 -> V_61 = V_4 ;
V_20 -> V_62 = F_26 ( V_63 ) ;
V_4 -> V_15 -> V_65 ( V_20 ) ;
if ( F_19 ( V_20 ) < 0 ) {
V_4 -> V_15 -> V_66 ( V_4 , V_20 ) ;
return F_35 ( - V_45 ) ;
}
if ( F_14 ( V_4 , V_20 ) < 0 ) {
F_27 ( V_20 , V_4 ) ;
V_4 -> V_15 -> V_66 ( V_4 , V_20 ) ;
return F_35 ( - V_73 ) ;
}
F_2 ( & V_4 -> V_21 ) ;
F_28 ( & V_20 -> V_53 , & V_4 -> V_68 ) ;
V_4 -> V_69 ++ ;
F_4 ( & V_4 -> V_21 ) ;
V_71:
F_12 ( L_20
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_36 ( V_4 ) , V_20 -> V_38 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
return V_20 ;
}
int F_36 (
struct V_3 * V_4 ,
struct V_1 * V_20 ,
int V_74 )
{
F_37 ( V_75 ) ;
struct V_76 * V_77 , * V_78 ;
unsigned long V_43 ;
int V_79 ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_20 -> V_64 ) {
V_20 -> V_64 = 0 ;
}
F_38 ( & V_20 -> V_53 ) ;
V_4 -> V_69 -- ;
F_4 ( & V_4 -> V_21 ) ;
F_39 ( & V_20 -> V_57 , V_43 ) ;
V_20 -> V_80 = 1 ;
F_40 (sess, sess_tmp, &acl->acl_sess_list,
sess_acl_list) {
if ( V_77 -> V_81 != 0 )
continue;
F_41 ( V_77 ) ;
F_42 ( & V_77 -> V_82 , & V_75 ) ;
}
F_43 ( & V_20 -> V_57 , V_43 ) ;
F_40 (sess, sess_tmp, &sess_list, sess_acl_list) {
F_38 ( & V_77 -> V_82 ) ;
V_79 = V_4 -> V_15 -> V_83 ( V_77 ) ;
F_44 ( V_77 ) ;
if ( ! V_79 )
continue;
F_44 ( V_77 ) ;
}
F_45 ( V_20 ) ;
F_46 ( & V_20 -> V_56 ) ;
F_29 ( V_20 ) ;
F_1 ( V_20 , V_4 ) ;
F_27 ( V_20 , V_4 ) ;
F_12 ( L_21
L_13 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_36 ( V_4 ) , V_20 -> V_38 ,
V_4 -> V_15 -> V_16 () , V_20 -> V_19 ) ;
return 0 ;
}
int F_47 (
struct V_3 * V_4 ,
unsigned char * V_19 ,
T_1 V_38 ,
int V_74 )
{
struct V_76 * V_77 , * V_84 = NULL ;
struct V_1 * V_20 ;
unsigned long V_43 ;
int V_85 = 0 ;
F_2 ( & V_4 -> V_21 ) ;
V_20 = F_6 ( V_4 , V_19 ) ;
if ( ! V_20 ) {
F_3 ( L_22
L_23
L_18 , V_4 -> V_15 -> V_16 () ,
V_19 , V_4 -> V_15 -> V_36 ( V_4 ) ) ;
F_4 ( & V_4 -> V_21 ) ;
return - V_86 ;
}
if ( V_20 -> V_64 ) {
V_20 -> V_64 = 0 ;
V_85 = 1 ;
}
F_4 ( & V_4 -> V_21 ) ;
F_39 ( & V_4 -> V_87 , V_43 ) ;
F_7 (sess, &tpg->tpg_sess_list, sess_list) {
if ( V_77 -> V_1 != V_20 )
continue;
if ( ! V_74 ) {
F_3 ( L_24
L_25
L_26
L_27
L_28 ,
V_4 -> V_15 -> V_16 () , V_19 ) ;
F_43 ( & V_4 -> V_87 , V_43 ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_85 )
V_20 -> V_64 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return - V_72 ;
}
if ( ! V_4 -> V_15 -> V_83 ( V_77 ) )
continue;
V_84 = V_77 ;
break;
}
V_20 -> V_38 = V_38 ;
if ( F_14 ( V_4 , V_20 ) < 0 ) {
F_43 ( & V_4 -> V_87 , V_43 ) ;
if ( V_84 )
V_4 -> V_15 -> V_88 ( V_84 ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_85 )
V_20 -> V_64 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return - V_73 ;
}
F_43 ( & V_4 -> V_87 , V_43 ) ;
if ( V_84 )
V_4 -> V_15 -> V_88 ( V_84 ) ;
F_12 ( L_29
L_30 , V_38 ,
V_19 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_36 ( V_4 ) ) ;
F_2 ( & V_4 -> V_21 ) ;
if ( V_85 )
V_20 -> V_64 = 1 ;
F_4 ( & V_4 -> V_21 ) ;
return 0 ;
}
int F_48 (
struct V_3 * V_4 ,
struct V_1 * V_20 ,
const char * V_89 )
{
if ( strlen ( V_89 ) >= V_90 )
return - V_73 ;
if ( ! strncmp ( L_31 , V_89 , 4 ) ) {
V_20 -> V_91 [ 0 ] = '\0' ;
return 0 ;
}
return snprintf ( V_20 -> V_91 , V_90 , L_11 , V_89 ) ;
}
static void F_49 ( struct V_92 * V_93 )
{
struct V_8 * V_9 = F_50 ( V_93 , struct V_8 , V_94 ) ;
F_51 ( & V_9 -> V_95 ) ;
}
static int F_52 ( struct V_3 * V_61 )
{
struct V_23 * V_24 = V_96 ;
struct V_8 * V_9 = & V_61 -> V_97 ;
T_1 V_22 = V_35 ;
int V_98 ;
V_9 -> V_37 = 0 ;
V_9 -> V_27 = V_99 ;
F_20 ( & V_9 -> V_100 , 0 ) ;
F_25 ( & V_9 -> V_101 ) ;
F_22 ( & V_9 -> V_102 ) ;
F_21 ( & V_9 -> V_103 ) ;
F_21 ( & V_9 -> V_104 ) ;
F_25 ( & V_9 -> V_95 ) ;
V_98 = F_53 ( V_61 , V_9 , V_22 , V_24 ) ;
if ( V_98 < 0 )
return V_98 ;
return 0 ;
}
static void F_54 ( struct V_3 * V_61 )
{
struct V_8 * V_9 = & V_61 -> V_97 ;
F_55 ( V_61 , V_9 ) ;
}
int F_56 (
struct V_105 * V_106 ,
struct V_107 * V_107 ,
struct V_3 * V_61 ,
void * V_108 ,
int V_109 )
{
struct V_8 * V_9 ;
T_1 V_5 ;
V_61 -> V_26 = F_17 ( V_11 ,
sizeof( struct V_8 ) , V_44 ) ;
if ( ! V_61 -> V_26 ) {
F_3 ( L_32
L_33 ) ;
return - V_45 ;
}
for ( V_5 = 0 ; V_5 < V_11 ; V_5 ++ ) {
V_9 = V_61 -> V_26 [ V_5 ] ;
V_9 -> V_37 = V_5 ;
V_9 -> V_110 = V_111 ;
V_9 -> V_27 = V_99 ;
F_20 ( & V_9 -> V_100 , 0 ) ;
F_25 ( & V_9 -> V_101 ) ;
F_22 ( & V_9 -> V_102 ) ;
F_21 ( & V_9 -> V_103 ) ;
F_21 ( & V_9 -> V_104 ) ;
F_25 ( & V_9 -> V_95 ) ;
}
V_61 -> V_109 = V_109 ;
V_61 -> V_112 = V_108 ;
V_61 -> V_15 = V_106 ;
V_61 -> V_113 = V_107 ;
F_20 ( & V_61 -> V_114 , 0 ) ;
F_22 ( & V_61 -> V_68 ) ;
F_22 ( & V_61 -> V_115 ) ;
F_22 ( & V_61 -> V_116 ) ;
F_21 ( & V_61 -> V_21 ) ;
F_21 ( & V_61 -> V_87 ) ;
F_21 ( & V_61 -> V_25 ) ;
if ( V_61 -> V_109 == V_117 ) {
if ( F_52 ( V_61 ) < 0 ) {
F_15 ( V_61 -> V_26 ,
V_11 ) ;
return - V_45 ;
}
}
F_57 ( & V_118 ) ;
F_28 ( & V_61 -> V_115 , & V_119 ) ;
F_58 ( & V_118 ) ;
F_12 ( L_34
L_35 , V_106 -> V_16 () ,
( V_61 -> V_109 == V_117 ) ?
L_36 : L_37 , ( V_106 -> V_120 ( V_61 ) == NULL ) ?
L_38 : V_106 -> V_120 ( V_61 ) , V_106 -> V_36 ( V_61 ) ) ;
return 0 ;
}
int F_59 ( struct V_3 * V_61 )
{
struct V_1 * V_2 , * V_121 ;
F_12 ( L_39
L_40 ,
( V_61 -> V_109 == V_117 ) ?
L_36 : L_37 , V_61 -> V_15 -> V_16 () ,
V_61 -> V_15 -> V_120 ( V_61 ) ,
V_61 -> V_15 -> V_36 ( V_61 ) ) ;
F_57 ( & V_118 ) ;
F_38 ( & V_61 -> V_115 ) ;
F_58 ( & V_118 ) ;
while ( F_30 ( & V_61 -> V_114 ) != 0 )
F_31 () ;
F_2 ( & V_61 -> V_21 ) ;
F_40 (nacl, nacl_tmp, &se_tpg->acl_node_list,
acl_list) {
F_38 ( & V_2 -> V_53 ) ;
V_61 -> V_69 -- ;
F_4 ( & V_61 -> V_21 ) ;
F_29 ( V_2 ) ;
F_27 ( V_2 , V_61 ) ;
V_61 -> V_15 -> V_66 ( V_61 , V_2 ) ;
F_2 ( & V_61 -> V_21 ) ;
}
F_4 ( & V_61 -> V_21 ) ;
if ( V_61 -> V_109 == V_117 )
F_54 ( V_61 ) ;
V_61 -> V_112 = NULL ;
F_15 ( V_61 -> V_26 , V_11 ) ;
return 0 ;
}
struct V_8 * F_60 (
struct V_3 * V_4 ,
T_1 V_37 )
{
struct V_8 * V_9 ;
if ( V_37 > ( V_11 - 1 ) ) {
F_3 ( L_41
L_42 ,
V_4 -> V_15 -> V_16 () ,
V_37 , V_11 - 1 ,
V_4 -> V_15 -> V_36 ( V_4 ) ) ;
return F_35 ( - V_122 ) ;
}
F_10 ( & V_4 -> V_25 ) ;
V_9 = V_4 -> V_26 [ V_37 ] ;
if ( V_9 -> V_27 == V_28 ) {
F_3 ( L_43
L_44 ,
V_37 , V_4 -> V_15 -> V_16 () ,
V_4 -> V_15 -> V_36 ( V_4 ) ) ;
F_11 ( & V_4 -> V_25 ) ;
return F_35 ( - V_73 ) ;
}
F_11 ( & V_4 -> V_25 ) ;
return V_9 ;
}
int F_53 (
struct V_3 * V_4 ,
struct V_8 * V_9 ,
T_1 V_22 ,
void * V_123 )
{
int V_98 ;
V_98 = F_61 ( & V_9 -> V_94 , F_49 ) ;
if ( V_98 < 0 )
return V_98 ;
V_98 = F_62 ( V_123 , V_4 , V_9 ) ;
if ( V_98 < 0 ) {
F_63 ( & V_9 -> V_94 ) ;
return V_98 ;
}
F_10 ( & V_4 -> V_25 ) ;
V_9 -> V_22 = V_22 ;
V_9 -> V_27 = V_28 ;
F_11 ( & V_4 -> V_25 ) ;
return 0 ;
}
struct V_8 * F_64 (
struct V_3 * V_4 ,
T_1 V_37 )
{
struct V_8 * V_9 ;
if ( V_37 > ( V_11 - 1 ) ) {
F_3 ( L_41
L_42 ,
V_4 -> V_15 -> V_16 () , V_37 ,
V_11 - 1 ,
V_4 -> V_15 -> V_36 ( V_4 ) ) ;
return F_35 ( - V_122 ) ;
}
F_10 ( & V_4 -> V_25 ) ;
V_9 = V_4 -> V_26 [ V_37 ] ;
if ( V_9 -> V_27 != V_28 ) {
F_3 ( L_45
L_46 ,
V_4 -> V_15 -> V_16 () , V_37 ,
V_4 -> V_15 -> V_36 ( V_4 ) ) ;
F_11 ( & V_4 -> V_25 ) ;
return F_35 ( - V_86 ) ;
}
F_11 ( & V_4 -> V_25 ) ;
return V_9 ;
}
int F_55 (
struct V_3 * V_4 ,
struct V_8 * V_9 )
{
F_65 ( V_9 , V_4 ) ;
F_66 ( V_9 ) ;
F_67 ( V_9 -> V_29 , V_4 , V_9 ) ;
F_10 ( & V_4 -> V_25 ) ;
V_9 -> V_27 = V_99 ;
F_11 ( & V_4 -> V_25 ) ;
return 0 ;
}
