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
static T_1 F_14 ( struct V_18 * V_19 ,
char * V_20 )
{
return snprintf ( V_20 , V_16 , L_3 , F_9 ( V_19 ) -> V_29 ) ;
}
static T_1 F_15 ( struct V_18 * V_19 ,
const char * V_20 , T_4 V_27 )
{
struct V_21 * V_22 = F_9 ( V_19 ) ;
int V_17 ;
V_17 = F_16 ( V_22 -> V_30 , V_22 , V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
return V_27 ;
}
static int F_17 ( struct V_21 * V_31 , const char * V_1 )
{
struct V_23 * V_24 =
F_10 ( V_31 , struct V_23 , V_21 ) ;
T_2 V_32 ;
if ( F_1 ( V_1 , & V_32 , 1 ) < 0 )
return - V_33 ;
V_24 -> V_25 . V_26 = V_32 ;
return 0 ;
}
static struct V_34 * F_18 (
struct V_35 * V_2 ,
struct V_36 * V_37 ,
const char * V_1 )
{
struct V_38 * V_39 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
unsigned long V_44 ;
int V_17 ;
F_3 ( L_4 , V_1 ) ;
if ( strstr ( V_1 , L_5 ) != V_1 )
return NULL ;
V_17 = F_19 ( V_1 + 5 , 10 , & V_44 ) ;
if ( V_17 )
return NULL ;
if ( V_44 > V_45 )
return NULL ;
if ( ( V_44 != 1 ) ) {
F_20 ( L_6 ) ;
return F_21 ( - V_46 ) ;
}
V_39 = F_10 ( V_2 , struct V_38 , V_35 ) ;
V_41 = F_22 ( sizeof( * V_41 ) , V_47 ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_44 = V_44 ;
V_41 -> V_48 = V_39 ;
F_23 ( & V_41 -> V_49 ) ;
V_43 = F_24 ( L_7 , 0 , 1 ) ;
if ( ! V_43 ) {
F_25 ( V_41 ) ;
return NULL ;
}
V_17 = F_26 ( V_2 , & V_41 -> V_30 , V_50 ) ;
if ( V_17 < 0 ) {
F_27 ( V_43 ) ;
F_25 ( V_41 ) ;
return NULL ;
}
V_41 -> V_51 = V_43 ;
F_28 ( & V_52 ) ;
V_39 -> V_41 = V_41 ;
F_29 ( & V_52 ) ;
return & V_41 -> V_30 ;
}
static void F_30 ( struct V_34 * V_30 )
{
struct V_40 * V_41 = F_10 ( V_30 , struct V_40 , V_30 ) ;
struct V_38 * V_39 = V_41 -> V_48 ;
F_3 ( L_8 ,
F_31 ( & V_41 -> V_30 . V_53 . V_54 ) ) ;
F_27 ( V_41 -> V_51 ) ;
F_32 () ;
F_28 ( & V_52 ) ;
V_39 -> V_41 = NULL ;
if ( V_41 -> V_55 ) {
V_41 -> V_55 -> V_41 = NULL ;
V_41 -> V_55 = NULL ;
}
F_29 ( & V_52 ) ;
F_33 ( V_30 ) ;
F_25 ( V_41 ) ;
}
struct V_40 * F_34 ( struct V_56 * V_57 )
{
struct V_38 * V_39 ;
F_35 (ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_39 -> V_32 == V_57 -> V_32 )
return V_39 -> V_41 ;
}
return NULL ;
}
static struct V_35 * F_36 (
struct V_58 * V_59 ,
struct V_36 * V_37 ,
const char * V_1 )
{
struct V_38 * V_39 ;
struct V_38 * V_60 ;
T_2 V_32 ;
F_3 ( L_9 , V_1 ) ;
if ( F_1 ( V_1 , & V_32 , 1 ) < 0 )
return NULL ;
V_39 = F_22 ( sizeof( * V_39 ) , V_47 ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_32 = V_32 ;
F_28 ( & V_52 ) ;
F_35 (old_ft_wwn, &ft_wwn_list, ft_wwn_node) {
if ( V_60 -> V_32 == V_32 ) {
F_29 ( & V_52 ) ;
F_25 ( V_39 ) ;
return NULL ;
}
}
F_37 ( & V_39 -> V_61 , & V_62 ) ;
F_4 ( V_39 -> V_1 , sizeof( V_39 -> V_1 ) , V_32 ) ;
F_29 ( & V_52 ) ;
return & V_39 -> V_35 ;
}
static void F_38 ( struct V_35 * V_2 )
{
struct V_38 * V_39 = F_10 ( V_2 ,
struct V_38 , V_35 ) ;
F_3 ( L_10 , V_39 -> V_1 ) ;
F_28 ( & V_52 ) ;
F_39 ( & V_39 -> V_61 ) ;
F_29 ( & V_52 ) ;
F_25 ( V_39 ) ;
}
static T_1 F_40 ( struct V_18 * V_19 , char * V_20 )
{
return sprintf ( V_20 , L_11 V_63 L_12
L_13 V_64 L_14 , F_41 () -> V_65 , F_41 () -> V_66 ) ;
}
static inline struct V_40 * V_40 ( struct V_34 * V_30 )
{
return F_10 ( V_30 , struct V_40 , V_30 ) ;
}
static char * F_42 ( void )
{
return L_15 ;
}
static char * F_43 ( struct V_34 * V_30 )
{
return V_40 ( V_30 ) -> V_48 -> V_1 ;
}
static T_6 F_44 ( struct V_34 * V_30 )
{
return V_40 ( V_30 ) -> V_44 ;
}
static int F_45 ( struct V_34 * V_30 )
{
return 0 ;
}
static void F_46 ( struct V_21 * V_22 )
{
}
static T_3 F_47 ( struct V_34 * V_30 )
{
return V_40 ( V_30 ) -> V_44 ;
}
static int T_7 F_48 ( void )
{
int V_17 ;
V_17 = F_49 ( & V_67 ) ;
if ( V_17 )
goto V_68;
V_17 = F_50 ( V_69 , & V_70 ) ;
if ( V_17 )
goto V_71;
F_51 ( & V_72 , & V_73 ) ;
F_52 ( V_74 , NULL ) ;
return 0 ;
V_71:
F_53 ( & V_67 ) ;
V_68:
return V_17 ;
}
static void T_8 F_54 ( void )
{
F_55 ( & V_72 ,
& V_73 ) ;
F_56 ( V_69 , & V_70 ) ;
F_52 ( V_75 , NULL ) ;
F_53 ( & V_67 ) ;
F_32 () ;
}
