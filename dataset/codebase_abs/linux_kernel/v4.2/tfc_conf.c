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
static int F_13 ( struct V_18 * V_27 , const char * V_1 )
{
struct V_21 * V_22 =
F_9 ( V_27 , struct V_21 , V_18 ) ;
T_2 V_28 ;
if ( F_1 ( V_1 , & V_28 , 1 ) < 0 )
return - V_29 ;
V_22 -> V_23 . V_24 = V_28 ;
return 0 ;
}
struct V_21 * F_14 ( struct V_30 * V_31 , struct V_32 * V_33 )
{
struct V_21 * V_34 = NULL ;
struct V_21 * V_22 ;
struct V_35 * V_36 = & V_31 -> V_36 ;
struct V_18 * V_37 ;
F_15 ( & V_36 -> V_38 ) ;
F_16 (se_acl, &se_tpg->acl_node_list, acl_list) {
V_22 = F_9 ( V_37 , struct V_21 , V_18 ) ;
F_3 ( L_3 ,
V_22 , ( unsigned long long ) V_22 -> V_23 . V_24 ) ;
if ( V_22 -> V_23 . V_24 == V_33 -> V_39 . V_24 ||
V_22 -> V_23 . V_26 == V_33 -> V_39 . V_26 ) {
F_3 ( L_4 , V_22 ,
( unsigned long long ) V_33 -> V_39 . V_24 ) ;
V_34 = V_22 ;
break;
}
}
F_17 ( & V_36 -> V_38 ) ;
return V_34 ;
}
static struct V_35 * F_18 (
struct V_40 * V_2 ,
struct V_41 * V_42 ,
const char * V_1 )
{
struct V_43 * V_44 ;
struct V_30 * V_31 ;
struct V_45 * V_46 ;
unsigned long V_47 ;
int V_17 ;
F_3 ( L_5 , V_1 ) ;
if ( strstr ( V_1 , L_6 ) != V_1 )
return NULL ;
V_17 = F_19 ( V_1 + 5 , 10 , & V_47 ) ;
if ( V_17 )
return NULL ;
if ( V_47 > V_48 )
return NULL ;
if ( ( V_47 != 1 ) ) {
F_20 ( L_7 ) ;
return F_21 ( - V_49 ) ;
}
V_44 = F_9 ( V_2 , struct V_43 , V_40 ) ;
V_31 = F_22 ( sizeof( * V_31 ) , V_50 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_47 = V_47 ;
V_31 -> V_51 = V_44 ;
F_23 ( & V_31 -> V_52 ) ;
V_46 = F_24 ( L_8 , 0 , 1 ) ;
if ( ! V_46 ) {
F_25 ( V_31 ) ;
return NULL ;
}
V_17 = F_26 ( V_2 , & V_31 -> V_36 , V_53 ) ;
if ( V_17 < 0 ) {
F_27 ( V_46 ) ;
F_25 ( V_31 ) ;
return NULL ;
}
V_31 -> V_54 = V_46 ;
F_15 ( & V_55 ) ;
V_44 -> V_31 = V_31 ;
F_17 ( & V_55 ) ;
return & V_31 -> V_36 ;
}
static void F_28 ( struct V_35 * V_36 )
{
struct V_30 * V_31 = F_9 ( V_36 , struct V_30 , V_36 ) ;
struct V_43 * V_44 = V_31 -> V_51 ;
F_3 ( L_9 ,
F_29 ( & V_31 -> V_36 . V_56 . V_57 ) ) ;
F_27 ( V_31 -> V_54 ) ;
F_30 () ;
F_15 ( & V_55 ) ;
V_44 -> V_31 = NULL ;
if ( V_31 -> V_58 ) {
V_31 -> V_58 -> V_31 = NULL ;
V_31 -> V_58 = NULL ;
}
F_17 ( & V_55 ) ;
F_31 ( V_36 ) ;
F_25 ( V_31 ) ;
}
struct V_30 * F_32 ( struct V_59 * V_60 )
{
struct V_43 * V_44 ;
F_16 (ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_44 -> V_28 == V_60 -> V_28 )
return V_44 -> V_31 ;
}
return NULL ;
}
static struct V_40 * F_33 (
struct V_61 * V_62 ,
struct V_41 * V_42 ,
const char * V_1 )
{
struct V_43 * V_44 ;
struct V_43 * V_63 ;
T_2 V_28 ;
F_3 ( L_10 , V_1 ) ;
if ( F_1 ( V_1 , & V_28 , 1 ) < 0 )
return NULL ;
V_44 = F_22 ( sizeof( * V_44 ) , V_50 ) ;
if ( ! V_44 )
return NULL ;
V_44 -> V_28 = V_28 ;
F_15 ( & V_55 ) ;
F_16 (old_ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_63 -> V_28 == V_28 ) {
F_17 ( & V_55 ) ;
F_25 ( V_44 ) ;
return NULL ;
}
}
F_34 ( & V_44 -> V_64 , & V_65 ) ;
F_4 ( V_44 -> V_1 , sizeof( V_44 -> V_1 ) , V_28 ) ;
F_17 ( & V_55 ) ;
return & V_44 -> V_40 ;
}
static void F_35 ( struct V_40 * V_2 )
{
struct V_43 * V_44 = F_9 ( V_2 ,
struct V_43 , V_40 ) ;
F_3 ( L_11 , V_44 -> V_1 ) ;
F_15 ( & V_55 ) ;
F_36 ( & V_44 -> V_64 ) ;
F_17 ( & V_55 ) ;
F_25 ( V_44 ) ;
}
static T_1 F_37 (
struct V_61 * V_62 ,
char * V_20 )
{
return sprintf ( V_20 , L_12 V_66 L_13
L_14 V_67 L_15 , F_38 () -> V_68 , F_38 () -> V_69 ) ;
}
static inline struct V_30 * V_30 ( struct V_35 * V_36 )
{
return F_9 ( V_36 , struct V_30 , V_36 ) ;
}
static char * F_39 ( void )
{
return L_16 ;
}
static char * F_40 ( struct V_35 * V_36 )
{
return V_30 ( V_36 ) -> V_51 -> V_1 ;
}
static T_6 F_41 ( struct V_35 * V_36 )
{
return V_30 ( V_36 ) -> V_47 ;
}
static int F_42 ( struct V_35 * V_36 )
{
return 0 ;
}
static void F_43 ( struct V_18 * V_19 )
{
}
static T_3 F_44 ( struct V_35 * V_36 )
{
return V_30 ( V_36 ) -> V_47 ;
}
static int T_7 F_45 ( void )
{
int V_17 ;
V_17 = F_46 ( & V_70 ) ;
if ( V_17 )
goto V_71;
V_17 = F_47 ( V_72 , & V_73 ) ;
if ( V_17 )
goto V_74;
F_48 ( & V_75 , & V_76 ) ;
F_49 ( V_77 , NULL ) ;
return 0 ;
V_74:
F_50 ( & V_70 ) ;
V_71:
return V_17 ;
}
static void T_8 F_51 ( void )
{
F_52 ( & V_75 ,
& V_76 ) ;
F_53 ( V_72 , & V_73 ) ;
F_49 ( V_78 , NULL ) ;
F_50 ( & V_70 ) ;
F_30 () ;
}
