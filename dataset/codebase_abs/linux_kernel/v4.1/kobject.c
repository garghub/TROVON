const void * F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_4 || V_4 -> type == V_5 )
return NULL ;
return V_2 -> V_6 -> V_7 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
struct V_10 * V_11 ;
int error = 0 ;
int V_12 ;
if ( V_9 && V_9 -> V_13 ) {
for ( V_12 = 0 ; ( V_11 = V_9 -> V_13 [ V_12 ] ) != NULL ; V_12 ++ ) {
error = F_5 ( V_2 , V_11 ) ;
if ( error )
break;
}
}
return error ;
}
static int F_6 ( struct V_1 * V_2 )
{
const struct V_3 * V_14 ;
int error ;
error = F_7 ( V_2 , F_1 ( V_2 ) ) ;
if ( error )
return error ;
error = F_3 ( V_2 ) ;
if ( error ) {
F_8 ( V_2 ) ;
return error ;
}
F_9 ( V_2 -> V_15 ) ;
V_14 = F_10 ( V_2 ) ;
if ( V_14 ) {
F_11 ( V_14 -> type <= V_5 ) ;
F_11 ( V_14 -> type >= V_16 ) ;
F_11 ( ! F_12 ( V_14 -> type ) ) ;
F_13 ( V_2 -> V_15 ) ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_17 = 1 ;
struct V_1 * V_18 = V_2 ;
do {
if ( F_15 ( V_18 ) == NULL )
return 0 ;
V_17 += strlen ( F_15 ( V_18 ) ) + 1 ;
V_18 = V_18 -> V_18 ;
} while ( V_18 );
return V_17 ;
}
static void F_16 ( struct V_1 * V_2 , char * V_19 , int V_17 )
{
struct V_1 * V_18 ;
-- V_17 ;
for ( V_18 = V_2 ; V_18 ; V_18 = V_18 -> V_18 ) {
int V_20 = strlen ( F_15 ( V_18 ) ) ;
V_17 -= V_20 ;
strncpy ( V_19 + V_17 , F_15 ( V_18 ) , V_20 ) ;
* ( V_19 + -- V_17 ) = '/' ;
}
F_17 ( L_1 , F_15 ( V_2 ) ,
V_2 , V_21 , V_19 ) ;
}
char * F_18 ( struct V_1 * V_2 , T_1 V_22 )
{
char * V_19 ;
int V_23 ;
V_23 = F_14 ( V_2 ) ;
if ( V_23 == 0 )
return NULL ;
V_19 = F_19 ( V_23 , V_22 ) ;
if ( ! V_19 )
return NULL ;
F_16 ( V_2 , V_19 , V_23 ) ;
return V_19 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 )
return;
F_21 ( V_2 -> V_24 ) ;
F_22 ( & V_2 -> V_24 -> V_25 ) ;
F_23 ( & V_2 -> V_26 , & V_2 -> V_24 -> V_27 ) ;
F_24 ( & V_2 -> V_24 -> V_25 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_24 )
return;
F_22 ( & V_2 -> V_24 -> V_25 ) ;
F_26 ( & V_2 -> V_26 ) ;
F_24 ( & V_2 -> V_24 -> V_25 ) ;
F_27 ( V_2 -> V_24 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_29 ( & V_2 -> V_28 ) ;
F_30 ( & V_2 -> V_26 ) ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 0 ;
V_2 -> V_31 = 0 ;
V_2 -> V_32 = 1 ;
}
static int F_31 ( struct V_1 * V_2 )
{
int error = 0 ;
struct V_1 * V_18 ;
if ( ! V_2 )
return - V_33 ;
if ( ! V_2 -> V_34 || ! V_2 -> V_34 [ 0 ] ) {
F_32 ( 1 , L_2
L_3 , V_2 ) ;
return - V_35 ;
}
V_18 = F_33 ( V_2 -> V_18 ) ;
if ( V_2 -> V_24 ) {
if ( ! V_18 )
V_18 = F_33 ( & V_2 -> V_24 -> V_2 ) ;
F_20 ( V_2 ) ;
V_2 -> V_18 = V_18 ;
}
F_17 ( L_4 ,
F_15 ( V_2 ) , V_2 , V_21 ,
V_18 ? F_15 ( V_18 ) : L_5 ,
V_2 -> V_24 ? F_15 ( & V_2 -> V_24 -> V_2 ) : L_5 ) ;
error = F_6 ( V_2 ) ;
if ( error ) {
F_25 ( V_2 ) ;
F_34 ( V_18 ) ;
V_2 -> V_18 = NULL ;
if ( error == - V_36 )
F_32 ( 1 , L_6
L_7
L_8 ,
V_21 , F_15 ( V_2 ) ) ;
else
F_32 ( 1 , L_9 ,
V_21 , F_15 ( V_2 ) , error ,
V_18 ? F_15 ( V_18 ) : L_10 ) ;
} else
V_2 -> V_29 = 1 ;
return error ;
}
int F_35 ( struct V_1 * V_2 , const char * V_37 ,
T_2 V_38 )
{
const char * V_39 = V_2 -> V_34 ;
char * V_40 ;
if ( V_2 -> V_34 && ! V_37 )
return 0 ;
V_2 -> V_34 = F_36 ( V_41 , V_37 , V_38 ) ;
if ( ! V_2 -> V_34 ) {
V_2 -> V_34 = V_39 ;
return - V_42 ;
}
while ( ( V_40 = strchr ( V_2 -> V_34 , '/' ) ) )
V_40 [ 0 ] = '!' ;
F_37 ( V_39 ) ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 , const char * V_37 , ... )
{
T_2 V_38 ;
int V_43 ;
va_start ( V_38 , V_37 ) ;
V_43 = F_35 ( V_2 , V_37 , V_38 ) ;
va_end ( V_38 ) ;
return V_43 ;
}
void F_39 ( struct V_1 * V_2 , struct V_8 * V_6 )
{
char * V_44 ;
if ( ! V_2 ) {
V_44 = L_11 ;
goto error;
}
if ( ! V_6 ) {
V_44 = L_12 ;
goto error;
}
if ( V_2 -> V_32 ) {
F_40 ( V_45 L_13
L_14 , V_2 ) ;
F_41 () ;
}
F_28 ( V_2 ) ;
V_2 -> V_6 = V_6 ;
return;
error:
F_40 ( V_45 L_15 , V_2 , V_44 ) ;
F_41 () ;
}
static int F_42 ( struct V_1 * V_2 , struct V_1 * V_18 ,
const char * V_37 , T_2 V_38 )
{
int V_43 ;
V_43 = F_35 ( V_2 , V_37 , V_38 ) ;
if ( V_43 ) {
F_40 ( V_45 L_16 ) ;
return V_43 ;
}
V_2 -> V_18 = V_18 ;
return F_31 ( V_2 ) ;
}
int F_43 ( struct V_1 * V_2 , struct V_1 * V_18 ,
const char * V_37 , ... )
{
T_2 args ;
int V_43 ;
if ( ! V_2 )
return - V_35 ;
if ( ! V_2 -> V_32 ) {
F_40 ( V_45 L_17
L_18 ,
F_15 ( V_2 ) , V_2 ) ;
F_41 () ;
return - V_35 ;
}
va_start ( args , V_37 ) ;
V_43 = F_42 ( V_2 , V_18 , V_37 , args ) ;
va_end ( args ) ;
return V_43 ;
}
int F_44 ( struct V_1 * V_2 , struct V_8 * V_6 ,
struct V_1 * V_18 , const char * V_37 , ... )
{
T_2 args ;
int V_43 ;
F_39 ( V_2 , V_6 ) ;
va_start ( args , V_37 ) ;
V_43 = F_42 ( V_2 , V_18 , V_37 , args ) ;
va_end ( args ) ;
return V_43 ;
}
int F_45 ( struct V_1 * V_2 , const char * V_46 )
{
int error = 0 ;
const char * V_47 = NULL ;
const char * V_48 = NULL , * V_34 ;
char * V_49 = NULL ;
char * V_50 [ 2 ] ;
V_2 = F_33 ( V_2 ) ;
if ( ! V_2 )
return - V_35 ;
if ( ! V_2 -> V_18 )
return - V_35 ;
V_47 = F_18 ( V_2 , V_41 ) ;
if ( ! V_47 ) {
error = - V_42 ;
goto V_51;
}
V_49 = F_46 ( strlen ( V_47 ) + 15 , V_41 ) ;
if ( ! V_49 ) {
error = - V_42 ;
goto V_51;
}
sprintf ( V_49 , L_19 , V_47 ) ;
V_50 [ 0 ] = V_49 ;
V_50 [ 1 ] = NULL ;
V_34 = V_48 = F_47 ( V_46 , V_41 ) ;
if ( ! V_34 ) {
error = - V_42 ;
goto V_51;
}
error = F_48 ( V_2 , V_46 , F_1 ( V_2 ) ) ;
if ( error )
goto V_51;
V_48 = V_2 -> V_34 ;
V_2 -> V_34 = V_34 ;
F_49 ( V_2 , V_52 , V_50 ) ;
V_51:
F_37 ( V_48 ) ;
F_37 ( V_49 ) ;
F_37 ( V_47 ) ;
F_34 ( V_2 ) ;
return error ;
}
int F_50 ( struct V_1 * V_2 , struct V_1 * V_53 )
{
int error ;
struct V_1 * V_54 ;
const char * V_47 = NULL ;
char * V_49 = NULL ;
char * V_50 [ 2 ] ;
V_2 = F_33 ( V_2 ) ;
if ( ! V_2 )
return - V_35 ;
V_53 = F_33 ( V_53 ) ;
if ( ! V_53 ) {
if ( V_2 -> V_24 )
V_53 = F_33 ( & V_2 -> V_24 -> V_2 ) ;
}
V_47 = F_18 ( V_2 , V_41 ) ;
if ( ! V_47 ) {
error = - V_42 ;
goto V_51;
}
V_49 = F_46 ( strlen ( V_47 ) + 15 , V_41 ) ;
if ( ! V_49 ) {
error = - V_42 ;
goto V_51;
}
sprintf ( V_49 , L_19 , V_47 ) ;
V_50 [ 0 ] = V_49 ;
V_50 [ 1 ] = NULL ;
error = F_51 ( V_2 , V_53 , F_1 ( V_2 ) ) ;
if ( error )
goto V_51;
V_54 = V_2 -> V_18 ;
V_2 -> V_18 = V_53 ;
V_53 = NULL ;
F_34 ( V_54 ) ;
F_49 ( V_2 , V_52 , V_50 ) ;
V_51:
F_34 ( V_53 ) ;
F_34 ( V_2 ) ;
F_37 ( V_49 ) ;
F_37 ( V_47 ) ;
return error ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_55 * V_15 ;
if ( ! V_2 )
return;
V_15 = V_2 -> V_15 ;
F_8 ( V_2 ) ;
F_53 ( V_15 ) ;
V_2 -> V_29 = 0 ;
F_25 ( V_2 ) ;
F_34 ( V_2 -> V_18 ) ;
V_2 -> V_18 = NULL ;
}
struct V_1 * F_33 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! V_2 -> V_32 )
F_32 ( 1 , V_56 L_20
L_21
L_22 , F_15 ( V_2 ) , V_2 ) ;
F_54 ( & V_2 -> V_28 ) ;
}
return V_2 ;
}
static struct V_1 * T_3 F_55 ( struct V_1 * V_2 )
{
if ( ! F_56 ( & V_2 -> V_28 ) )
V_2 = NULL ;
return V_2 ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
const char * V_34 = V_2 -> V_34 ;
F_17 ( L_23 ,
F_15 ( V_2 ) , V_2 , V_21 , V_2 -> V_18 ) ;
if ( V_9 && ! V_9 -> V_57 )
F_17 ( L_24
L_25 ,
F_15 ( V_2 ) , V_2 ) ;
if ( V_2 -> V_30 && ! V_2 -> V_31 ) {
F_17 ( L_26 ,
F_15 ( V_2 ) , V_2 ) ;
F_58 ( V_2 , V_58 ) ;
}
if ( V_2 -> V_29 ) {
F_17 ( L_27 ,
F_15 ( V_2 ) , V_2 ) ;
F_52 ( V_2 ) ;
}
if ( V_9 && V_9 -> V_57 ) {
F_17 ( L_28 ,
F_15 ( V_2 ) , V_2 ) ;
V_9 -> V_57 ( V_2 ) ;
}
if ( V_34 ) {
F_17 ( L_29 , V_34 ) ;
F_37 ( V_34 ) ;
}
}
static void F_59 ( struct V_59 * V_60 )
{
F_57 ( F_60 ( F_61 ( V_60 ) ,
struct V_1 , V_57 ) ) ;
}
static void F_62 ( struct V_28 * V_28 )
{
struct V_1 * V_2 = F_60 ( V_28 , struct V_1 , V_28 ) ;
#ifdef F_63
unsigned long V_61 = V_62 + V_62 * ( F_64 () & 0x3 ) ;
F_65 ( L_30 ,
F_15 ( V_2 ) , V_2 , V_21 , V_2 -> V_18 , V_61 ) ;
F_66 ( & V_2 -> V_57 , F_59 ) ;
F_67 ( & V_2 -> V_57 , V_61 ) ;
#else
F_57 ( V_2 ) ;
#endif
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! V_2 -> V_32 )
F_32 ( 1 , V_56 L_20
L_31
L_22 , F_15 ( V_2 ) , V_2 ) ;
F_68 ( & V_2 -> V_28 , F_62 ) ;
}
}
static void F_69 ( struct V_1 * V_2 )
{
F_17 ( L_32 , V_2 , V_21 ) ;
F_37 ( V_2 ) ;
}
struct V_1 * F_70 ( void )
{
struct V_1 * V_2 ;
V_2 = F_19 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return NULL ;
F_39 ( V_2 , & V_63 ) ;
return V_2 ;
}
struct V_1 * F_71 ( const char * V_34 , struct V_1 * V_18 )
{
struct V_1 * V_2 ;
int V_43 ;
V_2 = F_70 () ;
if ( ! V_2 )
return NULL ;
V_43 = F_43 ( V_2 , V_18 , L_33 , V_34 ) ;
if ( V_43 ) {
F_40 ( V_56 L_34 ,
V_21 , V_43 ) ;
F_34 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_72 ( struct V_24 * V_64 )
{
F_28 ( & V_64 -> V_2 ) ;
F_30 ( & V_64 -> V_27 ) ;
F_73 ( & V_64 -> V_25 ) ;
}
static T_4 F_74 ( struct V_1 * V_2 , struct V_10 * V_11 ,
char * V_65 )
{
struct V_66 * V_67 ;
T_4 V_68 = - V_69 ;
V_67 = F_60 ( V_11 , struct V_66 , V_11 ) ;
if ( V_67 -> V_70 )
V_68 = V_67 -> V_70 ( V_2 , V_67 , V_65 ) ;
return V_68 ;
}
static T_4 F_75 ( struct V_1 * V_2 , struct V_10 * V_11 ,
const char * V_65 , T_5 V_71 )
{
struct V_66 * V_67 ;
T_4 V_68 = - V_69 ;
V_67 = F_60 ( V_11 , struct V_66 , V_11 ) ;
if ( V_67 -> V_72 )
V_68 = V_67 -> V_72 ( V_2 , V_67 , V_65 , V_71 ) ;
return V_68 ;
}
int F_76 ( struct V_24 * V_64 )
{
int V_73 ;
if ( ! V_64 )
return - V_35 ;
F_72 ( V_64 ) ;
V_73 = F_31 ( & V_64 -> V_2 ) ;
if ( V_73 )
return V_73 ;
F_58 ( & V_64 -> V_2 , V_74 ) ;
return 0 ;
}
void F_77 ( struct V_24 * V_64 )
{
if ( ! V_64 )
return;
F_52 ( & V_64 -> V_2 ) ;
F_34 ( & V_64 -> V_2 ) ;
}
struct V_1 * F_78 ( struct V_24 * V_24 , const char * V_34 )
{
struct V_1 * V_64 ;
struct V_1 * V_68 = NULL ;
F_22 ( & V_24 -> V_25 ) ;
F_79 (k, &kset->list, entry) {
if ( F_15 ( V_64 ) && ! strcmp ( F_15 ( V_64 ) , V_34 ) ) {
V_68 = F_55 ( V_64 ) ;
break;
}
}
F_24 ( & V_24 -> V_25 ) ;
return V_68 ;
}
static void F_80 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = F_60 ( V_2 , struct V_24 , V_2 ) ;
F_17 ( L_35 ,
F_15 ( V_2 ) , V_2 , V_21 ) ;
F_37 ( V_24 ) ;
}
static struct V_24 * F_81 ( const char * V_34 ,
const struct V_75 * V_76 ,
struct V_1 * V_77 )
{
struct V_24 * V_24 ;
int V_43 ;
V_24 = F_19 ( sizeof( * V_24 ) , V_41 ) ;
if ( ! V_24 )
return NULL ;
V_43 = F_38 ( & V_24 -> V_2 , L_33 , V_34 ) ;
if ( V_43 ) {
F_37 ( V_24 ) ;
return NULL ;
}
V_24 -> V_76 = V_76 ;
V_24 -> V_2 . V_18 = V_77 ;
V_24 -> V_2 . V_6 = & V_78 ;
V_24 -> V_2 . V_24 = NULL ;
return V_24 ;
}
struct V_24 * F_82 ( const char * V_34 ,
const struct V_75 * V_76 ,
struct V_1 * V_77 )
{
struct V_24 * V_24 ;
int error ;
V_24 = F_81 ( V_34 , V_76 , V_77 ) ;
if ( ! V_24 )
return NULL ;
error = F_76 ( V_24 ) ;
if ( error ) {
F_37 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
int F_83 ( const struct V_3 * V_14 )
{
enum V_79 type = V_14 -> type ;
int error ;
F_22 ( & V_80 ) ;
error = - V_35 ;
if ( type >= V_16 )
goto V_51;
error = - V_35 ;
if ( type <= V_5 )
goto V_51;
error = - V_81 ;
if ( V_82 [ type ] )
goto V_51;
error = 0 ;
V_82 [ type ] = V_14 ;
V_51:
F_24 ( & V_80 ) ;
return error ;
}
int F_12 ( enum V_79 type )
{
int V_83 = 0 ;
F_22 ( & V_80 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) )
V_83 = V_82 [ type ] != NULL ;
F_24 ( & V_80 ) ;
return V_83 ;
}
const struct V_3 * F_10 ( struct V_1 * V_18 )
{
const struct V_3 * V_14 = NULL ;
if ( V_18 && V_18 -> V_6 && V_18 -> V_6 -> V_84 )
V_14 = V_18 -> V_6 -> V_84 ( V_18 ) ;
return V_14 ;
}
const struct V_3 * F_2 ( struct V_1 * V_2 )
{
return F_10 ( V_2 -> V_18 ) ;
}
bool F_84 ( enum V_79 type )
{
bool V_85 = true ;
F_22 ( & V_80 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_82 [ type ] )
V_85 = V_82 [ type ] -> F_85 () ;
F_24 ( & V_80 ) ;
return V_85 ;
}
void * F_86 ( enum V_79 type )
{
void * V_86 = NULL ;
F_22 ( & V_80 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_82 [ type ] )
V_86 = V_82 [ type ] -> F_87 () ;
F_24 ( & V_80 ) ;
return V_86 ;
}
const void * F_88 ( enum V_79 type , struct V_87 * V_88 )
{
const void * V_86 = NULL ;
F_22 ( & V_80 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_82 [ type ] )
V_86 = V_82 [ type ] -> F_89 ( V_88 ) ;
F_24 ( & V_80 ) ;
return V_86 ;
}
const void * F_90 ( enum V_79 type )
{
const void * V_86 = NULL ;
F_22 ( & V_80 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_82 [ type ] )
V_86 = V_82 [ type ] -> F_91 () ;
F_24 ( & V_80 ) ;
return V_86 ;
}
void F_92 ( enum V_79 type , void * V_86 )
{
F_22 ( & V_80 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_82 [ type ] && V_82 [ type ] -> V_89 )
V_82 [ type ] -> V_89 ( V_86 ) ;
F_24 ( & V_80 ) ;
}
