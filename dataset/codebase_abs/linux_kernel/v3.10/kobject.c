static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 ;
int error = 0 ;
int V_7 ;
if ( V_4 && V_4 -> V_8 ) {
for ( V_7 = 0 ; ( V_6 = V_4 -> V_8 [ V_7 ] ) != NULL ; V_7 ++ ) {
error = F_3 ( V_2 , V_6 ) ;
if ( error )
break;
}
}
return error ;
}
static int F_4 ( struct V_1 * V_2 )
{
int error = 0 ;
error = F_5 ( V_2 ) ;
if ( ! error ) {
error = F_1 ( V_2 ) ;
if ( error )
F_6 ( V_2 ) ;
}
return error ;
}
static int F_7 ( struct V_1 * V_2 )
{
int V_9 = 1 ;
struct V_1 * V_10 = V_2 ;
do {
if ( F_8 ( V_10 ) == NULL )
return 0 ;
V_9 += strlen ( F_8 ( V_10 ) ) + 1 ;
V_10 = V_10 -> V_10 ;
} while ( V_10 );
return V_9 ;
}
static void F_9 ( struct V_1 * V_2 , char * V_11 , int V_9 )
{
struct V_1 * V_10 ;
-- V_9 ;
for ( V_10 = V_2 ; V_10 ; V_10 = V_10 -> V_10 ) {
int V_12 = strlen ( F_8 ( V_10 ) ) ;
V_9 -= V_12 ;
strncpy ( V_11 + V_9 , F_8 ( V_10 ) , V_12 ) ;
* ( V_11 + -- V_9 ) = '/' ;
}
F_10 ( L_1 , F_8 ( V_2 ) ,
V_2 , V_13 , V_11 ) ;
}
char * F_11 ( struct V_1 * V_2 , T_1 V_14 )
{
char * V_11 ;
int V_15 ;
V_15 = F_7 ( V_2 ) ;
if ( V_15 == 0 )
return NULL ;
V_11 = F_12 ( V_15 , V_14 ) ;
if ( ! V_11 )
return NULL ;
F_9 ( V_2 , V_11 , V_15 ) ;
return V_11 ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_16 )
return;
F_14 ( V_2 -> V_16 ) ;
F_15 ( & V_2 -> V_16 -> V_17 ) ;
F_16 ( & V_2 -> V_18 , & V_2 -> V_16 -> V_19 ) ;
F_17 ( & V_2 -> V_16 -> V_17 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_16 )
return;
F_15 ( & V_2 -> V_16 -> V_17 ) ;
F_19 ( & V_2 -> V_18 ) ;
F_17 ( & V_2 -> V_16 -> V_17 ) ;
F_20 ( V_2 -> V_16 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_22 ( & V_2 -> V_20 ) ;
F_23 ( & V_2 -> V_18 ) ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 1 ;
}
static int F_24 ( struct V_1 * V_2 )
{
int error = 0 ;
struct V_1 * V_10 ;
if ( ! V_2 )
return - V_25 ;
if ( ! V_2 -> V_26 || ! V_2 -> V_26 [ 0 ] ) {
F_25 ( 1 , L_2
L_3 , V_2 ) ;
return - V_27 ;
}
V_10 = F_26 ( V_2 -> V_10 ) ;
if ( V_2 -> V_16 ) {
if ( ! V_10 )
V_10 = F_26 ( & V_2 -> V_16 -> V_2 ) ;
F_13 ( V_2 ) ;
V_2 -> V_10 = V_10 ;
}
F_10 ( L_4 ,
F_8 ( V_2 ) , V_2 , V_13 ,
V_10 ? F_8 ( V_10 ) : L_5 ,
V_2 -> V_16 ? F_8 ( & V_2 -> V_16 -> V_2 ) : L_5 ) ;
error = F_4 ( V_2 ) ;
if ( error ) {
F_18 ( V_2 ) ;
F_27 ( V_10 ) ;
V_2 -> V_10 = NULL ;
if ( error == - V_28 )
F_25 ( 1 , L_6
L_7
L_8 ,
V_13 , F_8 ( V_2 ) ) ;
else
F_25 ( 1 , L_9 ,
V_13 , F_8 ( V_2 ) , error ,
V_10 ? F_8 ( V_10 ) : L_10 ) ;
} else
V_2 -> V_21 = 1 ;
return error ;
}
int F_28 ( struct V_1 * V_2 , const char * V_29 ,
T_2 V_30 )
{
const char * V_31 = V_2 -> V_26 ;
char * V_32 ;
if ( V_2 -> V_26 && ! V_29 )
return 0 ;
V_2 -> V_26 = F_29 ( V_33 , V_29 , V_30 ) ;
if ( ! V_2 -> V_26 )
return - V_34 ;
while ( ( V_32 = strchr ( V_2 -> V_26 , '/' ) ) )
V_32 [ 0 ] = '!' ;
F_30 ( V_31 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , const char * V_29 , ... )
{
T_2 V_30 ;
int V_35 ;
va_start ( V_30 , V_29 ) ;
V_35 = F_28 ( V_2 , V_29 , V_30 ) ;
va_end ( V_30 ) ;
return V_35 ;
}
void F_32 ( struct V_1 * V_2 , struct V_3 * V_36 )
{
char * V_37 ;
if ( ! V_2 ) {
V_37 = L_11 ;
goto error;
}
if ( ! V_36 ) {
V_37 = L_12 ;
goto error;
}
if ( V_2 -> V_24 ) {
F_33 ( V_38 L_13
L_14 , V_2 ) ;
F_34 () ;
}
F_21 ( V_2 ) ;
V_2 -> V_36 = V_36 ;
return;
error:
F_33 ( V_38 L_15 , V_2 , V_37 ) ;
F_34 () ;
}
static int F_35 ( struct V_1 * V_2 , struct V_1 * V_10 ,
const char * V_29 , T_2 V_30 )
{
int V_35 ;
V_35 = F_28 ( V_2 , V_29 , V_30 ) ;
if ( V_35 ) {
F_33 ( V_38 L_16 ) ;
return V_35 ;
}
V_2 -> V_10 = V_10 ;
return F_24 ( V_2 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_1 * V_10 ,
const char * V_29 , ... )
{
T_2 args ;
int V_35 ;
if ( ! V_2 )
return - V_27 ;
if ( ! V_2 -> V_24 ) {
F_33 ( V_38 L_17
L_18 ,
F_8 ( V_2 ) , V_2 ) ;
F_34 () ;
return - V_27 ;
}
va_start ( args , V_29 ) ;
V_35 = F_35 ( V_2 , V_10 , V_29 , args ) ;
va_end ( args ) ;
return V_35 ;
}
int F_37 ( struct V_1 * V_2 , struct V_3 * V_36 ,
struct V_1 * V_10 , const char * V_29 , ... )
{
T_2 args ;
int V_35 ;
F_32 ( V_2 , V_36 ) ;
va_start ( args , V_29 ) ;
V_35 = F_35 ( V_2 , V_10 , V_29 , args ) ;
va_end ( args ) ;
return V_35 ;
}
int F_38 ( struct V_1 * V_2 , const char * V_39 )
{
int error = 0 ;
const char * V_40 = NULL ;
const char * V_41 = NULL , * V_26 ;
char * V_42 = NULL ;
char * V_43 [ 2 ] ;
V_2 = F_26 ( V_2 ) ;
if ( ! V_2 )
return - V_27 ;
if ( ! V_2 -> V_10 )
return - V_27 ;
V_40 = F_11 ( V_2 , V_33 ) ;
if ( ! V_40 ) {
error = - V_34 ;
goto V_44;
}
V_42 = F_39 ( strlen ( V_40 ) + 15 , V_33 ) ;
if ( ! V_42 ) {
error = - V_34 ;
goto V_44;
}
sprintf ( V_42 , L_19 , V_40 ) ;
V_43 [ 0 ] = V_42 ;
V_43 [ 1 ] = NULL ;
V_26 = V_41 = F_40 ( V_39 , V_33 ) ;
if ( ! V_26 ) {
error = - V_34 ;
goto V_44;
}
error = F_41 ( V_2 , V_39 ) ;
if ( error )
goto V_44;
V_41 = V_2 -> V_26 ;
V_2 -> V_26 = V_26 ;
F_42 ( V_2 , V_45 , V_43 ) ;
V_44:
F_30 ( V_41 ) ;
F_30 ( V_42 ) ;
F_30 ( V_40 ) ;
F_27 ( V_2 ) ;
return error ;
}
int F_43 ( struct V_1 * V_2 , struct V_1 * V_46 )
{
int error ;
struct V_1 * V_47 ;
const char * V_40 = NULL ;
char * V_42 = NULL ;
char * V_43 [ 2 ] ;
V_2 = F_26 ( V_2 ) ;
if ( ! V_2 )
return - V_27 ;
V_46 = F_26 ( V_46 ) ;
if ( ! V_46 ) {
if ( V_2 -> V_16 )
V_46 = F_26 ( & V_2 -> V_16 -> V_2 ) ;
}
V_40 = F_11 ( V_2 , V_33 ) ;
if ( ! V_40 ) {
error = - V_34 ;
goto V_44;
}
V_42 = F_39 ( strlen ( V_40 ) + 15 , V_33 ) ;
if ( ! V_42 ) {
error = - V_34 ;
goto V_44;
}
sprintf ( V_42 , L_19 , V_40 ) ;
V_43 [ 0 ] = V_42 ;
V_43 [ 1 ] = NULL ;
error = F_44 ( V_2 , V_46 ) ;
if ( error )
goto V_44;
V_47 = V_2 -> V_10 ;
V_2 -> V_10 = V_46 ;
V_46 = NULL ;
F_27 ( V_47 ) ;
F_42 ( V_2 , V_45 , V_43 ) ;
V_44:
F_27 ( V_46 ) ;
F_27 ( V_2 ) ;
F_30 ( V_42 ) ;
F_30 ( V_40 ) ;
return error ;
}
void F_45 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_6 ( V_2 ) ;
V_2 -> V_21 = 0 ;
F_18 ( V_2 ) ;
F_27 ( V_2 -> V_10 ) ;
V_2 -> V_10 = NULL ;
}
struct V_1 * F_26 ( struct V_1 * V_2 )
{
if ( V_2 )
F_46 ( & V_2 -> V_20 ) ;
return V_2 ;
}
static struct V_1 * T_3 F_47 ( struct V_1 * V_2 )
{
if ( ! F_48 ( & V_2 -> V_20 ) )
V_2 = NULL ;
return V_2 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const char * V_26 = V_2 -> V_26 ;
F_10 ( L_20 ,
F_8 ( V_2 ) , V_2 , V_13 ) ;
if ( V_4 && ! V_4 -> V_48 )
F_10 ( L_21
L_22 ,
F_8 ( V_2 ) , V_2 ) ;
if ( V_2 -> V_22 && ! V_2 -> V_23 ) {
F_10 ( L_23 ,
F_8 ( V_2 ) , V_2 ) ;
F_50 ( V_2 , V_49 ) ;
}
if ( V_2 -> V_21 ) {
F_10 ( L_24 ,
F_8 ( V_2 ) , V_2 ) ;
F_45 ( V_2 ) ;
}
if ( V_4 && V_4 -> V_48 ) {
F_10 ( L_25 ,
F_8 ( V_2 ) , V_2 ) ;
V_4 -> V_48 ( V_2 ) ;
}
if ( V_26 ) {
F_10 ( L_26 , V_26 ) ;
F_30 ( V_26 ) ;
}
}
static void F_51 ( struct V_20 * V_20 )
{
F_49 ( F_52 ( V_20 , struct V_1 , V_20 ) ) ;
}
void F_27 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! V_2 -> V_24 )
F_25 ( 1 , V_50 L_27
L_28
L_29 , F_8 ( V_2 ) , V_2 ) ;
F_53 ( & V_2 -> V_20 , F_51 ) ;
}
}
static void F_54 ( struct V_1 * V_2 )
{
F_10 ( L_30 , V_2 , V_13 ) ;
F_30 ( V_2 ) ;
}
struct V_1 * F_55 ( void )
{
struct V_1 * V_2 ;
V_2 = F_12 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return NULL ;
F_32 ( V_2 , & V_51 ) ;
return V_2 ;
}
struct V_1 * F_56 ( const char * V_26 , struct V_1 * V_10 )
{
struct V_1 * V_2 ;
int V_35 ;
V_2 = F_55 () ;
if ( ! V_2 )
return NULL ;
V_35 = F_36 ( V_2 , V_10 , L_31 , V_26 ) ;
if ( V_35 ) {
F_33 ( V_50 L_32 ,
V_13 , V_35 ) ;
F_27 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_57 ( struct V_16 * V_52 )
{
F_21 ( & V_52 -> V_2 ) ;
F_23 ( & V_52 -> V_19 ) ;
F_58 ( & V_52 -> V_17 ) ;
}
static T_4 F_59 ( struct V_1 * V_2 , struct V_5 * V_6 ,
char * V_53 )
{
struct V_54 * V_55 ;
T_4 V_56 = - V_57 ;
V_55 = F_52 ( V_6 , struct V_54 , V_6 ) ;
if ( V_55 -> V_58 )
V_56 = V_55 -> V_58 ( V_2 , V_55 , V_53 ) ;
return V_56 ;
}
static T_4 F_60 ( struct V_1 * V_2 , struct V_5 * V_6 ,
const char * V_53 , T_5 V_59 )
{
struct V_54 * V_55 ;
T_4 V_56 = - V_57 ;
V_55 = F_52 ( V_6 , struct V_54 , V_6 ) ;
if ( V_55 -> V_60 )
V_56 = V_55 -> V_60 ( V_2 , V_55 , V_53 , V_59 ) ;
return V_56 ;
}
int F_61 ( struct V_16 * V_52 )
{
int V_61 ;
if ( ! V_52 )
return - V_27 ;
F_57 ( V_52 ) ;
V_61 = F_24 ( & V_52 -> V_2 ) ;
if ( V_61 )
return V_61 ;
F_50 ( & V_52 -> V_2 , V_62 ) ;
return 0 ;
}
void F_62 ( struct V_16 * V_52 )
{
if ( ! V_52 )
return;
F_27 ( & V_52 -> V_2 ) ;
}
struct V_1 * F_63 ( struct V_16 * V_16 , const char * V_26 )
{
struct V_1 * V_52 ;
struct V_1 * V_56 = NULL ;
F_15 ( & V_16 -> V_17 ) ;
F_64 (k, &kset->list, entry) {
if ( F_8 ( V_52 ) && ! strcmp ( F_8 ( V_52 ) , V_26 ) ) {
V_56 = F_47 ( V_52 ) ;
break;
}
}
F_17 ( & V_16 -> V_17 ) ;
return V_56 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_16 * V_16 = F_52 ( V_2 , struct V_16 , V_2 ) ;
F_10 ( L_20 ,
F_8 ( V_2 ) , V_2 , V_13 ) ;
F_30 ( V_16 ) ;
}
static struct V_16 * F_66 ( const char * V_26 ,
const struct V_63 * V_64 ,
struct V_1 * V_65 )
{
struct V_16 * V_16 ;
int V_35 ;
V_16 = F_12 ( sizeof( * V_16 ) , V_33 ) ;
if ( ! V_16 )
return NULL ;
V_35 = F_31 ( & V_16 -> V_2 , V_26 ) ;
if ( V_35 ) {
F_30 ( V_16 ) ;
return NULL ;
}
V_16 -> V_64 = V_64 ;
V_16 -> V_2 . V_10 = V_65 ;
V_16 -> V_2 . V_36 = & V_66 ;
V_16 -> V_2 . V_16 = NULL ;
return V_16 ;
}
struct V_16 * F_67 ( const char * V_26 ,
const struct V_63 * V_64 ,
struct V_1 * V_65 )
{
struct V_16 * V_16 ;
int error ;
V_16 = F_66 ( V_26 , V_64 , V_65 ) ;
if ( ! V_16 )
return NULL ;
error = F_61 ( V_16 ) ;
if ( error ) {
F_30 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
int F_68 ( const struct V_67 * V_68 )
{
enum V_69 type = V_68 -> type ;
int error ;
F_15 ( & V_70 ) ;
error = - V_27 ;
if ( type >= V_71 )
goto V_44;
error = - V_27 ;
if ( type <= V_72 )
goto V_44;
error = - V_73 ;
if ( V_74 [ type ] )
goto V_44;
error = 0 ;
V_74 [ type ] = V_68 ;
V_44:
F_17 ( & V_70 ) ;
return error ;
}
int F_69 ( enum V_69 type )
{
int V_75 = 0 ;
F_15 ( & V_70 ) ;
if ( ( type > V_72 ) && ( type < V_71 ) )
V_75 = V_74 [ type ] != NULL ;
F_17 ( & V_70 ) ;
return V_75 ;
}
const struct V_67 * F_70 ( struct V_1 * V_10 )
{
const struct V_67 * V_68 = NULL ;
if ( V_10 && V_10 -> V_36 -> V_76 )
V_68 = V_10 -> V_36 -> V_76 ( V_10 ) ;
return V_68 ;
}
const struct V_67 * F_71 ( struct V_1 * V_2 )
{
return F_70 ( V_2 -> V_10 ) ;
}
void * F_72 ( enum V_69 type )
{
void * V_77 = NULL ;
F_15 ( & V_70 ) ;
if ( ( type > V_72 ) && ( type < V_71 ) &&
V_74 [ type ] )
V_77 = V_74 [ type ] -> F_73 () ;
F_17 ( & V_70 ) ;
return V_77 ;
}
const void * F_74 ( enum V_69 type , struct V_78 * V_79 )
{
const void * V_77 = NULL ;
F_15 ( & V_70 ) ;
if ( ( type > V_72 ) && ( type < V_71 ) &&
V_74 [ type ] )
V_77 = V_74 [ type ] -> F_75 ( V_79 ) ;
F_17 ( & V_70 ) ;
return V_77 ;
}
const void * F_76 ( enum V_69 type )
{
const void * V_77 = NULL ;
F_15 ( & V_70 ) ;
if ( ( type > V_72 ) && ( type < V_71 ) &&
V_74 [ type ] )
V_77 = V_74 [ type ] -> F_77 () ;
F_17 ( & V_70 ) ;
return V_77 ;
}
void F_78 ( enum V_69 type , void * V_77 )
{
F_15 ( & V_70 ) ;
if ( ( type > V_72 ) && ( type < V_71 ) &&
V_74 [ type ] && V_74 [ type ] -> V_80 )
V_74 [ type ] -> V_80 ( V_77 ) ;
F_17 ( & V_70 ) ;
}
