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
static T_1 F_8 ( struct V_18 * V_19 , char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_23 * V_24 = F_10 ( V_22 ,
struct V_23 , V_21 ) ;
return F_6 ( & V_24 -> V_25 . V_26 , V_20 ) ;
}
static T_1 F_11 ( struct V_18 * V_19 ,
const char * V_20 , T_4 V_27 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_23 * V_24 = F_10 ( V_22 ,
struct V_23 , V_21 ) ;
return F_7 ( & V_24 -> V_25 . V_26 , V_20 , V_27 ) ;
}
static T_1 F_12 ( struct V_18 * V_19 ,
char * V_20 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_23 * V_24 = F_10 ( V_22 ,
struct V_23 , V_21 ) ;
return F_6 ( & V_24 -> V_25 . V_28 , V_20 ) ;
}
static T_1 F_13 ( struct V_18 * V_19 ,
const char * V_20 , T_4 V_27 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
struct V_23 * V_24 = F_10 ( V_22 ,
struct V_23 , V_21 ) ;
return F_7 ( & V_24 -> V_25 . V_28 , V_20 , V_27 ) ;
}
static int F_14 ( struct V_21 * V_29 , const char * V_1 )
{
struct V_23 * V_24 =
F_10 ( V_29 , struct V_23 , V_21 ) ;
T_2 V_30 ;
if ( F_1 ( V_1 , & V_30 , 1 ) < 0 )
return - V_31 ;
V_24 -> V_25 . V_26 = V_30 ;
return 0 ;
}
struct V_23 * F_15 ( struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_23 * V_36 = NULL ;
struct V_23 * V_24 ;
struct V_37 * V_38 = & V_33 -> V_38 ;
struct V_21 * V_39 ;
F_16 ( & V_38 -> V_40 ) ;
F_17 (se_acl, &se_tpg->acl_node_list, acl_list) {
V_24 = F_10 ( V_39 , struct V_23 , V_21 ) ;
F_3 ( L_3 ,
V_24 , ( unsigned long long ) V_24 -> V_25 . V_26 ) ;
if ( V_24 -> V_25 . V_26 == V_35 -> V_41 . V_26 ||
V_24 -> V_25 . V_28 == V_35 -> V_41 . V_28 ) {
F_3 ( L_4 , V_24 ,
( unsigned long long ) V_35 -> V_41 . V_26 ) ;
V_36 = V_24 ;
break;
}
}
F_18 ( & V_38 -> V_40 ) ;
return V_36 ;
}
static struct V_37 * F_19 (
struct V_42 * V_2 ,
struct V_43 * V_44 ,
const char * V_1 )
{
struct V_45 * V_46 ;
struct V_32 * V_33 ;
struct V_47 * V_48 ;
unsigned long V_49 ;
int V_17 ;
F_3 ( L_5 , V_1 ) ;
if ( strstr ( V_1 , L_6 ) != V_1 )
return NULL ;
V_17 = F_20 ( V_1 + 5 , 10 , & V_49 ) ;
if ( V_17 )
return NULL ;
if ( V_49 > V_50 )
return NULL ;
if ( ( V_49 != 1 ) ) {
F_21 ( L_7 ) ;
return F_22 ( - V_51 ) ;
}
V_46 = F_10 ( V_2 , struct V_45 , V_42 ) ;
V_33 = F_23 ( sizeof( * V_33 ) , V_52 ) ;
if ( ! V_33 )
return NULL ;
V_33 -> V_49 = V_49 ;
V_33 -> V_53 = V_46 ;
F_24 ( & V_33 -> V_54 ) ;
V_48 = F_25 ( L_8 , 0 , 1 ) ;
if ( ! V_48 ) {
F_26 ( V_33 ) ;
return NULL ;
}
V_17 = F_27 ( V_2 , & V_33 -> V_38 , V_55 ) ;
if ( V_17 < 0 ) {
F_28 ( V_48 ) ;
F_26 ( V_33 ) ;
return NULL ;
}
V_33 -> V_56 = V_48 ;
F_16 ( & V_57 ) ;
V_46 -> V_33 = V_33 ;
F_18 ( & V_57 ) ;
return & V_33 -> V_38 ;
}
static void F_29 ( struct V_37 * V_38 )
{
struct V_32 * V_33 = F_10 ( V_38 , struct V_32 , V_38 ) ;
struct V_45 * V_46 = V_33 -> V_53 ;
F_3 ( L_9 ,
F_30 ( & V_33 -> V_38 . V_58 . V_59 ) ) ;
F_28 ( V_33 -> V_56 ) ;
F_31 () ;
F_16 ( & V_57 ) ;
V_46 -> V_33 = NULL ;
if ( V_33 -> V_60 ) {
V_33 -> V_60 -> V_33 = NULL ;
V_33 -> V_60 = NULL ;
}
F_18 ( & V_57 ) ;
F_32 ( V_38 ) ;
F_26 ( V_33 ) ;
}
struct V_32 * F_33 ( struct V_61 * V_62 )
{
struct V_45 * V_46 ;
F_17 (ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_46 -> V_30 == V_62 -> V_30 )
return V_46 -> V_33 ;
}
return NULL ;
}
static struct V_42 * F_34 (
struct V_63 * V_64 ,
struct V_43 * V_44 ,
const char * V_1 )
{
struct V_45 * V_46 ;
struct V_45 * V_65 ;
T_2 V_30 ;
F_3 ( L_10 , V_1 ) ;
if ( F_1 ( V_1 , & V_30 , 1 ) < 0 )
return NULL ;
V_46 = F_23 ( sizeof( * V_46 ) , V_52 ) ;
if ( ! V_46 )
return NULL ;
V_46 -> V_30 = V_30 ;
F_16 ( & V_57 ) ;
F_17 (old_ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_65 -> V_30 == V_30 ) {
F_18 ( & V_57 ) ;
F_26 ( V_46 ) ;
return NULL ;
}
}
F_35 ( & V_46 -> V_66 , & V_67 ) ;
F_4 ( V_46 -> V_1 , sizeof( V_46 -> V_1 ) , V_30 ) ;
F_18 ( & V_57 ) ;
return & V_46 -> V_42 ;
}
static void F_36 ( struct V_42 * V_2 )
{
struct V_45 * V_46 = F_10 ( V_2 ,
struct V_45 , V_42 ) ;
F_3 ( L_11 , V_46 -> V_1 ) ;
F_16 ( & V_57 ) ;
F_37 ( & V_46 -> V_66 ) ;
F_18 ( & V_57 ) ;
F_26 ( V_46 ) ;
}
static T_1 F_38 ( struct V_18 * V_19 , char * V_20 )
{
return sprintf ( V_20 , L_12 V_68 L_13
L_14 V_69 L_15 , F_39 () -> V_70 , F_39 () -> V_71 ) ;
}
static inline struct V_32 * V_32 ( struct V_37 * V_38 )
{
return F_10 ( V_38 , struct V_32 , V_38 ) ;
}
static char * F_40 ( void )
{
return L_16 ;
}
static char * F_41 ( struct V_37 * V_38 )
{
return V_32 ( V_38 ) -> V_53 -> V_1 ;
}
static T_6 F_42 ( struct V_37 * V_38 )
{
return V_32 ( V_38 ) -> V_49 ;
}
static int F_43 ( struct V_37 * V_38 )
{
return 0 ;
}
static void F_44 ( struct V_21 * V_22 )
{
}
static T_3 F_45 ( struct V_37 * V_38 )
{
return V_32 ( V_38 ) -> V_49 ;
}
static int T_7 F_46 ( void )
{
int V_17 ;
V_17 = F_47 ( & V_72 ) ;
if ( V_17 )
goto V_73;
V_17 = F_48 ( V_74 , & V_75 ) ;
if ( V_17 )
goto V_76;
F_49 ( & V_77 , & V_78 ) ;
F_50 ( V_79 , NULL ) ;
return 0 ;
V_76:
F_51 ( & V_72 ) ;
V_73:
return V_17 ;
}
static void T_8 F_52 ( void )
{
F_53 ( & V_77 ,
& V_78 ) ;
F_54 ( V_74 , & V_75 ) ;
F_50 ( V_80 , NULL ) ;
F_51 ( & V_72 ) ;
F_31 () ;
}
