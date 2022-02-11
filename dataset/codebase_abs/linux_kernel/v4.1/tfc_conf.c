static T_1 F_1 ( const char * V_1 , T_2 * V_2 , int V_3 )
{
const char * V_4 ;
char V_5 ;
T_3 V_6 = 0 ;
T_3 V_7 = 0 ;
T_3 V_8 ;
int V_9 ;
* V_2 = 0 ;
for ( V_4 = V_1 ; V_4 < & V_1 [ V_10 - 1 ] ; V_4 ++ ) {
V_5 = * V_4 ;
if ( V_5 == '\n' && V_4 [ 1 ] == '\0' )
continue;
if ( V_3 && V_7 ++ == 2 && V_6 ++ < 7 ) {
V_7 = 0 ;
if ( V_5 == ':' )
continue;
V_8 = 1 ;
goto V_11;
}
if ( V_5 == '\0' ) {
V_8 = 2 ;
if ( V_3 && V_6 != 8 )
goto V_11;
return V_4 - V_1 ;
}
V_8 = 3 ;
V_9 = F_2 ( V_5 ) ;
if ( V_9 < 0 || ( V_3 && isupper ( V_5 ) ) )
goto V_11;
* V_2 = ( * V_2 << 4 ) | V_9 ;
}
V_8 = 4 ;
V_11:
F_3 ( L_1 ,
V_8 , V_4 - V_1 , V_7 , V_6 ) ;
return - 1 ;
}
T_1 F_4 ( char * V_12 , T_4 V_13 , T_2 V_2 )
{
T_5 V_14 [ 8 ] ;
F_5 ( V_2 , V_14 ) ;
return snprintf ( V_12 , V_13 ,
L_2 ,
V_14 [ 0 ] , V_14 [ 1 ] , V_14 [ 2 ] , V_14 [ 3 ] , V_14 [ 4 ] , V_14 [ 5 ] , V_14 [ 6 ] , V_14 [ 7 ] ) ;
}
static T_1 F_6 ( void * V_15 , char * V_12 )
{
T_2 * V_2 = V_15 ;
T_1 V_13 ;
V_13 = F_4 ( V_12 , V_16 - 2 , * V_2 ) ;
V_12 [ V_13 ++ ] = '\n' ;
return V_13 ;
}
static T_1 F_7 ( void * V_15 , const char * V_12 , T_4 V_13 )
{
T_1 V_17 ;
T_2 V_2 ;
V_17 = F_1 ( V_12 , & V_2 , 0 ) ;
if ( V_17 > 0 )
* ( T_2 * ) V_15 = V_2 ;
return V_17 ;
}
static T_1 F_8 (
struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ,
struct V_21 , V_18 ) ;
return F_6 ( & V_22 -> V_23 . V_24 , V_20 ) ;
}
static T_1 F_10 (
struct V_18 * V_19 ,
const char * V_20 ,
T_4 V_25 )
{
struct V_21 * V_22 = F_9 ( V_19 ,
struct V_21 , V_18 ) ;
return F_7 ( & V_22 -> V_23 . V_24 , V_20 , V_25 ) ;
}
static T_1 F_11 (
struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ,
struct V_21 , V_18 ) ;
return F_6 ( & V_22 -> V_23 . V_26 , V_20 ) ;
}
static T_1 F_12 (
struct V_18 * V_19 ,
const char * V_20 ,
T_4 V_25 )
{
struct V_21 * V_22 = F_9 ( V_19 ,
struct V_21 , V_18 ) ;
return F_7 ( & V_22 -> V_23 . V_26 , V_20 , V_25 ) ;
}
static struct V_18 * F_13 (
struct V_27 * V_28 ,
struct V_29 * V_30 ,
const char * V_1 )
{
struct V_21 * V_22 ;
struct V_31 * V_32 ;
T_2 V_33 ;
T_3 V_34 ;
F_3 ( L_3 , V_1 ) ;
V_32 = F_9 ( V_28 , struct V_31 , V_28 ) ;
if ( F_1 ( V_1 , & V_33 , 1 ) < 0 )
return F_14 ( - V_35 ) ;
V_22 = F_15 ( sizeof( struct V_21 ) , V_36 ) ;
if ( ! V_22 )
return F_14 ( - V_37 ) ;
V_22 -> V_23 . V_24 = V_33 ;
V_34 = 32 ;
return F_16 ( & V_32 -> V_28 ,
& V_22 -> V_18 , V_1 , V_34 ) ;
}
static void F_17 ( struct V_18 * V_38 )
{
struct V_27 * V_28 = V_38 -> V_28 ;
struct V_31 * V_32 ;
struct V_21 * V_22 = F_9 ( V_38 ,
struct V_21 , V_18 ) ;
F_3 ( L_4 ,
F_18 ( & V_38 -> V_39 . V_40 ) ) ;
V_32 = F_9 ( V_28 , struct V_31 , V_28 ) ;
F_3 ( L_5 ,
V_22 , V_38 , V_32 , & V_32 -> V_28 ) ;
F_19 ( & V_32 -> V_28 , V_38 , 1 ) ;
F_20 ( V_22 ) ;
}
struct V_21 * F_21 ( struct V_31 * V_32 , struct V_41 * V_42 )
{
struct V_21 * V_43 = NULL ;
struct V_21 * V_22 ;
struct V_27 * V_28 = & V_32 -> V_28 ;
struct V_18 * V_38 ;
F_22 ( & V_28 -> V_44 ) ;
F_23 (se_acl, &se_tpg->acl_node_list, acl_list) {
V_22 = F_9 ( V_38 , struct V_21 , V_18 ) ;
F_3 ( L_6 ,
V_22 , ( unsigned long long ) V_22 -> V_23 . V_24 ) ;
if ( V_22 -> V_23 . V_24 == V_42 -> V_45 . V_24 ||
V_22 -> V_23 . V_26 == V_42 -> V_45 . V_26 ) {
F_3 ( L_7 , V_22 ,
( unsigned long long ) V_42 -> V_45 . V_24 ) ;
V_43 = V_22 ;
break;
}
}
F_24 ( & V_28 -> V_44 ) ;
return V_43 ;
}
static struct V_18 * F_25 ( struct V_27 * V_28 )
{
struct V_21 * V_22 ;
V_22 = F_15 ( sizeof( * V_22 ) , V_36 ) ;
if ( ! V_22 ) {
F_26 ( L_8 ) ;
return NULL ;
}
F_3 ( L_9 , V_22 ) ;
return & V_22 -> V_18 ;
}
static void F_27 ( struct V_27 * V_28 ,
struct V_18 * V_38 )
{
struct V_21 * V_22 = F_9 ( V_38 ,
struct V_21 , V_18 ) ;
F_3 ( L_9 , V_22 ) ;
F_20 ( V_22 ) ;
}
static struct V_27 * F_28 (
struct V_46 * V_2 ,
struct V_29 * V_30 ,
const char * V_1 )
{
struct V_47 * V_48 ;
struct V_31 * V_32 ;
struct V_49 * V_50 ;
unsigned long V_51 ;
int V_17 ;
F_3 ( L_10 , V_1 ) ;
if ( strstr ( V_1 , L_11 ) != V_1 )
return NULL ;
V_17 = F_29 ( V_1 + 5 , 10 , & V_51 ) ;
if ( V_17 )
return NULL ;
if ( V_51 > V_52 )
return NULL ;
if ( ( V_51 != 1 ) ) {
F_26 ( L_12 ) ;
return F_14 ( - V_53 ) ;
}
V_48 = F_9 ( V_2 , struct V_47 , V_46 ) ;
V_32 = F_15 ( sizeof( * V_32 ) , V_36 ) ;
if ( ! V_32 )
return NULL ;
V_32 -> V_51 = V_51 ;
V_32 -> V_54 = V_48 ;
F_30 ( & V_32 -> V_55 ) ;
V_50 = F_31 ( L_13 , 0 , 1 ) ;
if ( ! V_50 ) {
F_20 ( V_32 ) ;
return NULL ;
}
V_17 = F_32 ( & V_56 , V_2 , & V_32 -> V_28 ,
V_32 , V_57 ) ;
if ( V_17 < 0 ) {
F_33 ( V_50 ) ;
F_20 ( V_32 ) ;
return NULL ;
}
V_32 -> V_58 = V_50 ;
F_34 ( & V_59 ) ;
V_48 -> V_32 = V_32 ;
F_35 ( & V_59 ) ;
return & V_32 -> V_28 ;
}
static void F_36 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = F_9 ( V_28 , struct V_31 , V_28 ) ;
struct V_47 * V_48 = V_32 -> V_54 ;
F_3 ( L_14 ,
F_18 ( & V_32 -> V_28 . V_60 . V_40 ) ) ;
F_33 ( V_32 -> V_58 ) ;
F_37 () ;
F_34 ( & V_59 ) ;
V_48 -> V_32 = NULL ;
if ( V_32 -> V_61 ) {
V_32 -> V_61 -> V_32 = NULL ;
V_32 -> V_61 = NULL ;
}
F_35 ( & V_59 ) ;
F_38 ( V_28 ) ;
F_20 ( V_32 ) ;
}
struct V_31 * F_39 ( struct V_62 * V_63 )
{
struct V_47 * V_48 ;
F_23 (ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_48 -> V_33 == V_63 -> V_33 )
return V_48 -> V_32 ;
}
return NULL ;
}
static struct V_46 * F_40 (
struct V_64 * V_65 ,
struct V_29 * V_30 ,
const char * V_1 )
{
struct V_47 * V_48 ;
struct V_47 * V_66 ;
T_2 V_33 ;
F_3 ( L_15 , V_1 ) ;
if ( F_1 ( V_1 , & V_33 , 1 ) < 0 )
return NULL ;
V_48 = F_15 ( sizeof( * V_48 ) , V_36 ) ;
if ( ! V_48 )
return NULL ;
V_48 -> V_33 = V_33 ;
F_34 ( & V_59 ) ;
F_23 (old_ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_66 -> V_33 == V_33 ) {
F_35 ( & V_59 ) ;
F_20 ( V_48 ) ;
return NULL ;
}
}
F_41 ( & V_48 -> V_67 , & V_68 ) ;
F_4 ( V_48 -> V_1 , sizeof( V_48 -> V_1 ) , V_33 ) ;
F_35 ( & V_59 ) ;
return & V_48 -> V_46 ;
}
static void F_42 ( struct V_46 * V_2 )
{
struct V_47 * V_48 = F_9 ( V_2 ,
struct V_47 , V_46 ) ;
F_3 ( L_16 , V_48 -> V_1 ) ;
F_34 ( & V_59 ) ;
F_43 ( & V_48 -> V_67 ) ;
F_35 ( & V_59 ) ;
F_20 ( V_48 ) ;
}
static T_1 F_44 (
struct V_64 * V_65 ,
char * V_20 )
{
return sprintf ( V_20 , L_17 V_69 L_18
L_19 V_70 L_20 , F_45 () -> V_71 , F_45 () -> V_72 ) ;
}
static char * F_46 ( void )
{
return L_21 ;
}
static char * F_47 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = V_28 -> V_73 ;
return V_32 -> V_54 -> V_1 ;
}
static T_6 F_48 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = V_28 -> V_73 ;
return V_32 -> V_51 ;
}
static T_3 F_49 ( struct V_27 * V_28 )
{
return 1 ;
}
static int F_50 ( struct V_27 * V_28 )
{
return 0 ;
}
static void F_51 ( struct V_18 * V_19 )
{
}
static T_3 F_52 ( struct V_27 * V_28 )
{
struct V_31 * V_32 = V_28 -> V_73 ;
return V_32 -> V_51 ;
}
static int T_7 F_53 ( void )
{
int V_17 ;
V_17 = F_54 ( & V_56 ) ;
if ( V_17 )
goto V_74;
V_17 = F_55 ( V_75 , & V_76 ) ;
if ( V_17 )
goto V_77;
F_56 ( & V_78 , & V_79 ) ;
F_57 ( V_80 , NULL ) ;
return 0 ;
V_77:
F_58 ( & V_56 ) ;
V_74:
return V_17 ;
}
static void T_8 F_59 ( void )
{
F_60 ( & V_78 ,
& V_79 ) ;
F_61 ( V_75 , & V_76 ) ;
F_57 ( V_81 , NULL ) ;
F_58 ( & V_56 ) ;
F_37 () ;
}
