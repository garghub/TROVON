static T_1 F_1 ( const char * V_1 , T_2 * V_2 , int V_3 )
{
const char * V_4 ;
char V_5 ;
T_3 V_6 ;
T_3 V_7 = 0 ;
T_3 V_8 = 0 ;
T_3 V_9 ;
* V_2 = 0 ;
for ( V_4 = V_1 ; V_4 < & V_1 [ V_10 - 1 ] ; V_4 ++ ) {
V_5 = * V_4 ;
if ( V_5 == '\n' && V_4 [ 1 ] == '\0' )
continue;
if ( V_3 && V_8 ++ == 2 && V_7 ++ < 7 ) {
V_8 = 0 ;
if ( V_5 == ':' )
continue;
V_9 = 1 ;
goto V_11;
}
if ( V_5 == '\0' ) {
V_9 = 2 ;
if ( V_3 && V_7 != 8 )
goto V_11;
return V_4 - V_1 ;
}
V_9 = 3 ;
if ( isdigit ( V_5 ) )
V_6 = V_5 - '0' ;
else if ( isxdigit ( V_5 ) && ( islower ( V_5 ) || ! V_3 ) )
V_6 = tolower ( V_5 ) - 'a' + 10 ;
else
goto V_11;
* V_2 = ( * V_2 << 4 ) | V_6 ;
}
V_9 = 4 ;
V_11:
F_2 ( L_1 ,
V_9 , V_4 - V_1 , V_8 , V_7 ) ;
return - 1 ;
}
T_1 F_3 ( char * V_12 , T_4 V_13 , T_2 V_2 )
{
T_5 V_14 [ 8 ] ;
F_4 ( V_2 , V_14 ) ;
return snprintf ( V_12 , V_13 ,
L_2 ,
V_14 [ 0 ] , V_14 [ 1 ] , V_14 [ 2 ] , V_14 [ 3 ] , V_14 [ 4 ] , V_14 [ 5 ] , V_14 [ 6 ] , V_14 [ 7 ] ) ;
}
static T_1 F_5 ( void * V_15 , char * V_12 )
{
T_2 * V_2 = V_15 ;
T_1 V_13 ;
V_13 = F_3 ( V_12 , V_16 - 2 , * V_2 ) ;
V_12 [ V_13 ++ ] = '\n' ;
return V_13 ;
}
static T_1 F_6 ( void * V_15 , const char * V_12 , T_4 V_13 )
{
T_1 V_17 ;
T_2 V_2 ;
V_17 = F_1 ( V_12 , & V_2 , 0 ) ;
if ( V_17 > 0 )
* ( T_2 * ) V_15 = V_2 ;
return V_17 ;
}
static T_1 F_7 (
struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_8 ( V_19 ,
struct V_21 , V_18 ) ;
return F_5 ( & V_22 -> V_23 . V_24 , V_20 ) ;
}
static T_1 F_9 (
struct V_18 * V_19 ,
const char * V_20 ,
T_4 V_25 )
{
struct V_21 * V_22 = F_8 ( V_19 ,
struct V_21 , V_18 ) ;
return F_6 ( & V_22 -> V_23 . V_24 , V_20 , V_25 ) ;
}
static T_1 F_10 (
struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_8 ( V_19 ,
struct V_21 , V_18 ) ;
return F_5 ( & V_22 -> V_23 . V_26 , V_20 ) ;
}
static T_1 F_11 (
struct V_18 * V_19 ,
const char * V_20 ,
T_4 V_25 )
{
struct V_21 * V_22 = F_8 ( V_19 ,
struct V_21 , V_18 ) ;
return F_6 ( & V_22 -> V_23 . V_26 , V_20 , V_25 ) ;
}
static struct V_18 * F_12 (
struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_1 )
{
struct V_21 * V_22 ;
struct V_31 * V_32 ;
T_2 V_33 ;
T_3 V_34 ;
F_2 ( L_3 , V_1 ) ;
V_32 = F_8 ( V_28 , struct V_31 , V_28 ) ;
if ( F_1 ( V_1 , & V_33 , 1 ) < 0 )
return F_13 ( - V_35 ) ;
V_22 = F_14 ( sizeof( struct V_21 ) , V_36 ) ;
if ( ! ( V_22 ) )
return F_13 ( - V_37 ) ;
V_22 -> V_23 . V_24 = V_33 ;
V_34 = 32 ;
return F_15 ( & V_32 -> V_28 ,
& V_22 -> V_18 , V_1 , V_34 ) ;
}
static void F_16 ( struct V_18 * V_38 )
{
struct V_27 * V_28 = V_38 -> V_28 ;
struct V_31 * V_32 ;
struct V_21 * V_22 = F_8 ( V_38 ,
struct V_21 , V_18 ) ;
F_2 ( L_4 ,
F_17 ( & V_38 -> V_39 . V_40 ) ) ;
V_32 = F_8 ( V_28 , struct V_31 , V_28 ) ;
F_2 ( L_5 ,
V_22 , V_38 , V_32 , & V_32 -> V_28 ) ;
F_18 ( & V_32 -> V_28 , V_38 , 1 ) ;
F_19 ( V_22 ) ;
}
struct V_21 * F_20 ( struct V_31 * V_32 , struct V_41 * V_42 )
{
struct V_21 * V_43 = NULL ;
struct V_21 * V_22 ;
struct V_27 * V_28 = & V_32 -> V_28 ;
struct V_18 * V_38 ;
F_21 ( & V_28 -> V_44 ) ;
F_22 (se_acl, &se_tpg->acl_node_list, acl_list) {
V_22 = F_8 ( V_38 , struct V_21 , V_18 ) ;
F_2 ( L_6 ,
V_22 , ( unsigned long long ) V_22 -> V_23 . V_24 ) ;
if ( V_22 -> V_23 . V_24 == V_42 -> V_45 . V_24 ||
V_22 -> V_23 . V_26 == V_42 -> V_45 . V_26 ) {
F_2 ( L_7 , V_22 ,
( unsigned long long ) V_42 -> V_45 . V_24 ) ;
V_43 = V_22 ;
break;
}
}
F_23 ( & V_28 -> V_44 ) ;
return V_43 ;
}
struct V_18 * F_24 ( struct V_27 * V_28 )
{
struct V_21 * V_22 ;
V_22 = F_14 ( sizeof( * V_22 ) , V_36 ) ;
if ( ! ( V_22 ) ) {
F_25 ( V_46 L_8 ) ;
return NULL ;
}
F_2 ( L_9 , V_22 ) ;
return & V_22 -> V_18 ;
}
static void F_26 ( struct V_27 * V_28 ,
struct V_18 * V_38 )
{
struct V_21 * V_22 = F_8 ( V_38 ,
struct V_21 , V_18 ) ;
F_2 ( V_47 L_9 , V_22 ) ;
F_19 ( V_22 ) ;
}
static struct V_27 * F_27 (
struct V_48 * V_2 ,
struct V_29 * V_30 ,
const char * V_1 )
{
struct V_49 * V_50 ;
struct V_31 * V_32 ;
unsigned long V_51 ;
int V_17 ;
F_2 ( L_10 , V_1 ) ;
if ( strstr ( V_1 , L_11 ) != V_1 )
return NULL ;
if ( F_28 ( V_1 + 5 , 10 , & V_51 ) || V_51 > V_52 )
return NULL ;
V_50 = F_8 ( V_2 , struct V_49 , V_53 ) ;
V_32 = F_14 ( sizeof( * V_32 ) , V_36 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_51 = V_51 ;
V_32 -> V_54 = V_50 ;
F_29 ( & V_32 -> V_55 ) ;
F_30 ( & V_32 -> V_56 ) ;
V_17 = F_31 ( & V_57 -> V_58 , V_2 , & V_32 -> V_28 ,
( void * ) V_32 , V_59 ) ;
if ( V_17 < 0 ) {
F_19 ( V_32 ) ;
return NULL ;
}
V_32 -> V_60 = F_32 ( V_61 , V_32 , L_12 , V_51 ) ;
if ( F_33 ( V_32 -> V_60 ) ) {
F_19 ( V_32 ) ;
return NULL ;
}
F_34 ( & V_62 ) ;
F_35 ( & V_32 -> V_63 , & V_50 -> V_64 ) ;
F_36 ( & V_62 ) ;
return & V_32 -> V_28 ;
}
static void F_37 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = F_8 ( V_28 , struct V_31 , V_28 ) ;
F_2 ( L_13 ,
F_17 ( & V_32 -> V_28 . V_65 . V_40 ) ) ;
F_38 ( V_32 -> V_60 ) ;
F_39 () ;
F_34 ( & V_62 ) ;
F_40 ( & V_32 -> V_63 ) ;
if ( V_32 -> V_66 ) {
V_32 -> V_66 -> V_32 = NULL ;
V_32 -> V_66 = NULL ;
}
F_36 ( & V_62 ) ;
F_41 ( V_28 ) ;
F_19 ( V_32 ) ;
}
struct V_31 * F_42 ( struct V_67 * V_68 )
{
struct V_49 * V_50 ;
struct V_31 * V_32 ;
F_22 (lacl, &ft_lport_list, list) {
if ( V_50 -> V_33 == V_68 -> V_33 ) {
F_22 (tpg, &lacl->tpg_list, list)
return V_32 ;
return NULL ;
}
}
return NULL ;
}
static struct V_48 * F_43 (
struct V_69 * V_70 ,
struct V_29 * V_30 ,
const char * V_1 )
{
struct V_49 * V_50 ;
struct V_49 * V_71 ;
T_2 V_33 ;
F_2 ( L_14 , V_1 ) ;
if ( F_1 ( V_1 , & V_33 , 1 ) < 0 )
return NULL ;
V_50 = F_14 ( sizeof( * V_50 ) , V_36 ) ;
if ( ! V_50 )
return NULL ;
V_50 -> V_33 = V_33 ;
F_29 ( & V_50 -> V_64 ) ;
F_34 ( & V_62 ) ;
F_22 (old_lacl, &ft_lport_list, list) {
if ( V_71 -> V_33 == V_33 ) {
F_36 ( & V_62 ) ;
F_19 ( V_50 ) ;
return NULL ;
}
}
F_35 ( & V_50 -> V_63 , & V_72 ) ;
F_3 ( V_50 -> V_1 , sizeof( V_50 -> V_1 ) , V_33 ) ;
F_36 ( & V_62 ) ;
return & V_50 -> V_53 ;
}
static void F_44 ( struct V_48 * V_2 )
{
struct V_49 * V_50 = F_8 ( V_2 ,
struct V_49 , V_53 ) ;
F_2 ( L_15 ,
F_17 ( & V_2 -> V_73 . V_40 ) ) ;
F_34 ( & V_62 ) ;
F_40 ( & V_50 -> V_63 ) ;
F_36 ( & V_62 ) ;
F_19 ( V_50 ) ;
}
static T_1 F_45 (
struct V_69 * V_70 ,
char * V_20 )
{
return sprintf ( V_20 , L_16 V_74 L_17
L_18 V_75 L_19 , F_46 () -> V_76 , F_46 () -> V_77 ) ;
}
static char * F_47 ( void )
{
return L_20 ;
}
static char * F_48 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = V_28 -> V_78 ;
return V_32 -> V_54 -> V_1 ;
}
static T_6 F_49 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = V_28 -> V_78 ;
return V_32 -> V_51 ;
}
static T_3 F_50 ( struct V_27 * V_28 )
{
return 1 ;
}
static int F_51 ( struct V_27 * V_28 )
{
return 0 ;
}
static void F_52 ( struct V_18 * V_19 )
{
}
static T_6 F_53 ( void )
{
return 0 ;
}
static T_6 F_54 ( struct V_79 * V_79 , T_3 V_80 )
{
return 0 ;
}
static T_3 F_55 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = V_28 -> V_78 ;
return V_32 -> V_51 ;
}
int F_56 ( void )
{
struct V_69 * V_81 ;
int V_17 ;
V_81 = F_57 ( V_82 , L_20 ) ;
if ( ! V_81 ) {
F_25 ( V_47 L_21 ,
V_83 ) ;
return - 1 ;
}
V_81 -> V_58 = V_84 ;
V_81 -> V_58 . V_85 = 1 ;
F_58 ( V_81 ) -> V_86 . V_87 = V_88 ;
F_58 ( V_81 ) -> V_89 . V_87 = NULL ;
F_58 ( V_81 ) -> V_90 . V_87 = NULL ;
F_58 ( V_81 ) -> V_91 . V_87 = NULL ;
F_58 ( V_81 ) -> V_92 . V_87 = NULL ;
F_58 ( V_81 ) -> V_93 . V_87 =
V_94 ;
F_58 ( V_81 ) -> V_95 . V_87 = NULL ;
F_58 ( V_81 ) -> V_96 . V_87 = NULL ;
F_58 ( V_81 ) -> V_97 . V_87 = NULL ;
V_17 = F_59 ( V_81 ) ;
if ( V_17 < 0 ) {
F_2 ( L_22
L_23 ) ;
F_25 ( V_47
L_24 ,
V_83 ) ;
F_60 ( V_81 ) ;
return - 1 ;
}
V_57 = V_81 ;
return 0 ;
}
void F_61 ( void )
{
if ( ! V_57 )
return;
F_62 ( V_57 ) ;
V_57 = NULL ;
}
static int T_7 F_63 ( void )
{
if ( F_56 () )
return - 1 ;
if ( F_64 ( V_98 , & V_99 ) ) {
F_61 () ;
return - 1 ;
}
F_65 ( & V_100 , & V_101 ) ;
F_66 ( V_102 , NULL ) ;
return 0 ;
}
static void T_8 F_67 ( void )
{
F_68 ( & V_100 ,
& V_101 ) ;
F_69 ( V_98 , & V_99 ) ;
F_66 ( V_103 , NULL ) ;
F_61 () ;
F_39 () ;
}
