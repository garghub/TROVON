static void
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_6 ) ;
struct V_4 * V_7 = F_2 ( V_3 , struct V_4 , V_6 ) ;
V_5 -> V_8 = V_7 -> V_8 ;
V_5 -> type = V_7 -> type ;
F_3 ( V_5 -> V_9 , V_7 -> V_9 , sizeof( V_5 -> V_9 ) ) ;
F_3 ( V_5 -> V_10 , V_7 -> V_10 , sizeof( V_5 -> V_9 ) ) ;
}
static void
F_4 ( struct V_11 * V_12 )
{
struct V_4 * V_13 = F_2 ( V_12 , struct V_4 , V_6 . V_12 ) ;
F_5 ( V_13 ) ;
}
static struct V_1 *
F_6 ( void )
{
struct V_4 * V_14 = F_7 ( sizeof( * V_14 ) , V_15 ) ;
if ( V_14 )
return & V_14 -> V_6 ;
else
return NULL ;
}
static T_1
F_8 ( struct V_4 * V_4 )
{
T_1 V_16 ;
V_16 = F_9 ( V_4 -> V_10 , V_17 ) ;
V_16 = F_10 ( V_16 ^ V_4 -> V_8 , V_17 ) ;
if ( V_4 -> type == V_18 )
V_16 ^= 1 ;
return V_16 ;
}
static void
F_11 ( struct V_19 * V_20 , struct V_1 * V_21 , char * * V_22 ,
int * V_23 )
{
struct V_4 * V_4 = F_2 ( V_21 , struct V_4 , V_6 ) ;
char V_24 [ 11 ] ;
F_12 ( V_22 , V_23 , V_4 -> V_10 ) ;
snprintf ( V_24 , sizeof( V_24 ) , L_1 , V_4 -> V_8 ) ;
F_12 ( V_22 , V_23 , V_4 -> type == V_18 ? L_2 : L_3 ) ;
F_12 ( V_22 , V_23 , V_24 ) ;
( * V_22 ) [ - 1 ] = '\n' ;
}
static int
F_13 ( struct V_19 * V_20 , struct V_1 * V_21 )
{
return F_14 ( V_20 , V_21 , F_11 ) ;
}
static int
F_15 ( struct V_1 * V_25 , struct V_1 * V_26 )
{
struct V_4 * V_27 = F_2 ( V_25 , struct V_4 , V_6 ) ;
struct V_4 * V_28 = F_2 ( V_26 , struct V_4 , V_6 ) ;
return ( V_27 -> V_8 == V_28 -> V_8 && V_27 -> type == V_28 -> type &&
strcmp ( V_27 -> V_10 , V_28 -> V_10 ) == 0 ) ;
}
static int
F_16 ( struct V_29 * V_30 , struct V_19 * V_20 , struct V_1 * V_6 )
{
struct V_4 * V_4 ;
if ( V_6 == NULL ) {
F_17 ( V_30 , L_4 ) ;
return 0 ;
}
V_4 = F_2 ( V_6 , struct V_4 , V_6 ) ;
F_18 ( V_30 , L_5 , V_4 -> V_10 ,
V_4 -> type == V_18 ? L_2 : L_3 ,
V_4 -> V_8 ) ;
if ( F_19 ( V_31 , & V_6 -> V_32 ) )
F_18 ( V_30 , L_6 , V_4 -> V_9 ) ;
F_18 ( V_30 , L_7 ) ;
return 0 ;
}
static void
F_20 ( struct V_19 * V_33 , int V_34 )
{
F_21 ( L_8 ,
V_34 ? L_9 : L_10 ) ;
}
static int
F_22 ( struct V_19 * V_20 , char * V_35 , int V_36 )
{
struct V_4 V_4 , * V_37 ;
char * V_38 , * V_39 ;
int V_40 ;
int error = - V_41 ;
if ( V_35 [ V_36 - 1 ] != '\n' )
return ( - V_41 ) ;
V_35 [ V_36 - 1 ] = '\0' ;
V_38 = F_7 ( V_42 , V_15 ) ;
if ( V_38 == NULL )
return ( - V_43 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( F_23 ( & V_35 , V_38 , V_42 ) <= 0 )
goto V_44;
memcpy ( V_4 . V_10 , V_38 , sizeof( V_4 . V_10 ) ) ;
if ( F_23 ( & V_35 , V_38 , V_42 ) <= 0 )
goto V_44;
V_4 . type = strcmp ( V_38 , L_3 ) == 0 ?
V_45 : V_18 ;
if ( F_23 ( & V_35 , V_38 , V_42 ) <= 0 )
goto V_44;
V_4 . V_8 = F_24 ( V_38 , & V_39 , 10 ) ;
if ( V_39 == V_38 )
goto V_44;
V_4 . V_6 . V_46 = F_25 ( & V_35 ) ;
if ( V_4 . V_6 . V_46 == 0 )
goto V_44;
error = - V_43 ;
V_37 = F_26 ( V_20 , & V_4 ) ;
if ( ! V_37 )
goto V_44;
error = - V_41 ;
V_40 = F_23 ( & V_35 , V_38 , V_42 ) ;
if ( V_40 < 0 )
goto V_44;
if ( V_40 == 0 )
F_27 ( V_47 , & V_4 . V_6 . V_32 ) ;
else if ( V_40 >= V_48 )
goto V_44;
else
memcpy ( V_4 . V_9 , V_38 , sizeof( V_4 . V_9 ) ) ;
error = - V_43 ;
V_37 = F_28 ( V_20 , & V_4 , V_37 ) ;
if ( V_37 == NULL )
goto V_44;
F_29 ( & V_37 -> V_6 , V_20 ) ;
error = 0 ;
V_44:
F_5 ( V_38 ) ;
return error ;
}
static struct V_4 *
F_26 ( struct V_19 * V_20 , struct V_4 * V_49 )
{
struct V_1 * V_21 = F_30 ( V_20 , & V_49 -> V_6 ,
F_8 ( V_49 ) ) ;
if ( V_21 )
return F_2 ( V_21 , struct V_4 , V_6 ) ;
else
return NULL ;
}
static struct V_4 *
F_28 ( struct V_19 * V_20 , struct V_4 * V_5 , struct V_4 * V_50 )
{
struct V_1 * V_21 = F_31 ( V_20 , & V_5 -> V_6 , & V_50 -> V_6 ,
F_8 ( V_5 ) ) ;
if ( V_21 )
return F_2 ( V_21 , struct V_4 , V_6 ) ;
else
return NULL ;
}
static inline int
F_32 ( struct V_4 * V_4 )
{
return F_9 ( V_4 -> V_9 , V_17 ) ;
}
static void
F_33 ( struct V_19 * V_20 , struct V_1 * V_21 , char * * V_22 ,
int * V_23 )
{
struct V_4 * V_4 = F_2 ( V_21 , struct V_4 , V_6 ) ;
F_12 ( V_22 , V_23 , V_4 -> V_10 ) ;
F_12 ( V_22 , V_23 , V_4 -> type == V_18 ? L_2 : L_3 ) ;
F_12 ( V_22 , V_23 , V_4 -> V_9 ) ;
( * V_22 ) [ - 1 ] = '\n' ;
}
static int
F_34 ( struct V_19 * V_20 , struct V_1 * V_21 )
{
return F_14 ( V_20 , V_21 , F_33 ) ;
}
static int
F_35 ( struct V_1 * V_25 , struct V_1 * V_26 )
{
struct V_4 * V_27 = F_2 ( V_25 , struct V_4 , V_6 ) ;
struct V_4 * V_28 = F_2 ( V_26 , struct V_4 , V_6 ) ;
return ( V_27 -> type == V_28 -> type && strcmp ( V_27 -> V_9 , V_28 -> V_9 ) == 0 &&
strcmp ( V_27 -> V_10 , V_28 -> V_10 ) == 0 ) ;
}
static int
F_36 ( struct V_29 * V_30 , struct V_19 * V_20 , struct V_1 * V_6 )
{
struct V_4 * V_4 ;
if ( V_6 == NULL ) {
F_17 ( V_30 , L_11 ) ;
return 0 ;
}
V_4 = F_2 ( V_6 , struct V_4 , V_6 ) ;
F_18 ( V_30 , L_12 , V_4 -> V_10 ,
V_4 -> type == V_18 ? L_2 : L_3 ,
V_4 -> V_9 ) ;
if ( F_19 ( V_31 , & V_6 -> V_32 ) )
F_18 ( V_30 , L_13 , V_4 -> V_8 ) ;
F_18 ( V_30 , L_7 ) ;
return 0 ;
}
static int
F_37 ( struct V_19 * V_20 , char * V_35 , int V_36 )
{
struct V_4 V_4 , * V_37 ;
char * V_38 ;
int error = - V_41 ;
if ( V_35 [ V_36 - 1 ] != '\n' )
return ( - V_41 ) ;
V_35 [ V_36 - 1 ] = '\0' ;
V_38 = F_7 ( V_42 , V_15 ) ;
if ( V_38 == NULL )
return ( - V_43 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
if ( F_23 ( & V_35 , V_38 , V_42 ) <= 0 )
goto V_44;
memcpy ( V_4 . V_10 , V_38 , sizeof( V_4 . V_10 ) ) ;
if ( F_23 ( & V_35 , V_38 , V_42 ) <= 0 )
goto V_44;
V_4 . type = strcmp ( V_38 , L_3 ) == 0 ?
V_45 : V_18 ;
error = F_23 ( & V_35 , V_38 , V_42 ) ;
if ( error <= 0 || error >= V_48 )
goto V_44;
memcpy ( V_4 . V_9 , V_38 , sizeof( V_4 . V_9 ) ) ;
V_4 . V_6 . V_46 = F_25 ( & V_35 ) ;
if ( V_4 . V_6 . V_46 == 0 )
goto V_44;
error = F_38 ( & V_35 , & V_4 . V_8 ) ;
if ( error == - V_41 )
goto V_44;
if ( error == - V_51 )
F_27 ( V_47 , & V_4 . V_6 . V_32 ) ;
error = - V_43 ;
V_37 = F_39 ( V_20 , & V_4 ) ;
if ( V_37 == NULL )
goto V_44;
V_37 = F_40 ( V_20 , & V_4 , V_37 ) ;
if ( V_37 == NULL )
goto V_44;
F_29 ( & V_37 -> V_6 , V_20 ) ;
error = 0 ;
V_44:
F_5 ( V_38 ) ;
return ( error ) ;
}
static struct V_4 *
F_39 ( struct V_19 * V_20 , struct V_4 * V_49 )
{
struct V_1 * V_21 = F_30 ( V_20 , & V_49 -> V_6 ,
F_32 ( V_49 ) ) ;
if ( V_21 )
return F_2 ( V_21 , struct V_4 , V_6 ) ;
else
return NULL ;
}
static struct V_4 *
F_40 ( struct V_19 * V_20 , struct V_4 * V_5 , struct V_4 * V_50 )
{
struct V_1 * V_21 = F_31 ( V_20 , & V_5 -> V_6 , & V_50 -> V_6 ,
F_32 ( V_5 ) ) ;
if ( V_21 )
return F_2 ( V_21 , struct V_4 , V_6 ) ;
else
return NULL ;
}
int
F_41 ( struct V_52 * V_52 )
{
int V_53 ;
struct V_54 * V_55 = F_42 ( V_52 , V_56 ) ;
V_55 -> V_57 = F_43 ( & V_58 , V_52 ) ;
if ( F_44 ( V_55 -> V_57 ) )
return F_45 ( V_55 -> V_57 ) ;
V_53 = F_46 ( V_55 -> V_57 , V_52 ) ;
if ( V_53 )
goto V_59;
V_55 -> V_60 = F_43 ( & V_61 , V_52 ) ;
if ( F_44 ( V_55 -> V_60 ) ) {
V_53 = F_45 ( V_55 -> V_60 ) ;
goto V_62;
}
V_53 = F_46 ( V_55 -> V_60 , V_52 ) ;
if ( V_53 )
goto V_63;
return 0 ;
V_63:
F_47 ( V_55 -> V_60 , V_52 ) ;
V_62:
F_48 ( V_55 -> V_57 , V_52 ) ;
V_59:
F_47 ( V_55 -> V_57 , V_52 ) ;
return V_53 ;
}
void
F_49 ( struct V_52 * V_52 )
{
struct V_54 * V_55 = F_42 ( V_52 , V_56 ) ;
F_48 ( V_55 -> V_57 , V_52 ) ;
F_48 ( V_55 -> V_60 , V_52 ) ;
F_47 ( V_55 -> V_57 , V_52 ) ;
F_47 ( V_55 -> V_60 , V_52 ) ;
}
static char *
F_50 ( struct V_64 * V_65 )
{
struct V_66 * V_67 ;
V_67 = V_65 -> V_68 ? V_65 -> V_68 : V_65 -> V_69 ;
return V_67 -> V_9 ;
}
static T_2
F_51 ( struct V_64 * V_65 , int type , const char * V_9 , T_3 V_70 ,
T_4 * V_8 )
{
struct V_4 * V_49 , V_71 = {
. type = type ,
} ;
int V_72 ;
struct V_54 * V_55 = F_42 ( F_52 ( V_65 ) , V_56 ) ;
if ( V_70 + 1 > sizeof( V_71 . V_9 ) )
return V_73 ;
memcpy ( V_71 . V_9 , V_9 , V_70 ) ;
V_71 . V_9 [ V_70 ] = '\0' ;
F_3 ( V_71 . V_10 , F_50 ( V_65 ) , sizeof( V_71 . V_10 ) ) ;
V_72 = F_53 ( V_65 , F_39 , & V_71 , V_55 -> V_60 , & V_49 ) ;
if ( V_72 == - V_51 )
return V_73 ;
if ( V_72 )
return F_54 ( V_72 ) ;
* V_8 = V_49 -> V_8 ;
F_29 ( & V_49 -> V_6 , V_55 -> V_60 ) ;
return 0 ;
}
static int
F_55 ( struct V_64 * V_65 , int type , T_4 V_8 , char * V_9 )
{
struct V_4 * V_49 , V_71 = {
. V_8 = V_8 ,
. type = type ,
} ;
int V_72 ;
struct V_54 * V_55 = F_42 ( F_52 ( V_65 ) , V_56 ) ;
F_3 ( V_71 . V_10 , F_50 ( V_65 ) , sizeof( V_71 . V_10 ) ) ;
V_72 = F_53 ( V_65 , F_26 , & V_71 , V_55 -> V_57 , & V_49 ) ;
if ( V_72 == - V_51 )
return sprintf ( V_9 , L_1 , V_8 ) ;
if ( V_72 )
return V_72 ;
V_72 = strlen ( V_49 -> V_9 ) ;
F_56 ( V_72 > V_48 ) ;
memcpy ( V_9 , V_49 -> V_9 , V_72 ) ;
F_29 ( & V_49 -> V_6 , V_55 -> V_57 ) ;
return V_72 ;
}
static bool
F_57 ( struct V_64 * V_65 , int type , const char * V_9 , T_3 V_70 , T_4 * V_8 )
{
int V_72 ;
char V_35 [ 11 ] ;
if ( V_70 + 1 > sizeof( V_35 ) )
return false ;
memcpy ( V_35 , V_9 , V_70 ) ;
V_35 [ V_70 ] = '\0' ;
V_72 = F_58 ( V_35 , 10 , V_8 ) ;
return V_72 == 0 ;
}
static T_2
F_59 ( struct V_64 * V_65 , int type , const char * V_9 , T_3 V_70 , T_4 * V_8 )
{
if ( V_74 && V_65 -> V_75 . V_76 < V_77 )
if ( F_57 ( V_65 , type , V_9 , V_70 , V_8 ) )
return 0 ;
return F_51 ( V_65 , type , V_9 , V_70 , V_8 ) ;
}
static int
F_60 ( struct V_64 * V_65 , int type , T_4 V_8 , char * V_9 )
{
if ( V_74 && V_65 -> V_75 . V_76 < V_77 )
return sprintf ( V_9 , L_1 , V_8 ) ;
return F_55 ( V_65 , type , V_8 , V_9 ) ;
}
T_2
F_61 ( struct V_64 * V_65 , const char * V_9 , T_5 V_70 ,
T_6 * V_8 )
{
return F_59 ( V_65 , V_45 , V_9 , V_70 , V_8 ) ;
}
T_2
F_62 ( struct V_64 * V_65 , const char * V_9 , T_5 V_70 ,
T_6 * V_8 )
{
return F_59 ( V_65 , V_18 , V_9 , V_70 , V_8 ) ;
}
int
F_63 ( struct V_64 * V_65 , T_6 V_8 , char * V_9 )
{
return F_60 ( V_65 , V_45 , V_8 , V_9 ) ;
}
int
F_64 ( struct V_64 * V_65 , T_6 V_8 , char * V_9 )
{
return F_60 ( V_65 , V_18 , V_8 , V_9 ) ;
}
