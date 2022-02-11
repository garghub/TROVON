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
int error ;
error = F_7 ( V_2 , F_1 ( V_2 ) ) ;
if ( ! error ) {
error = F_3 ( V_2 ) ;
if ( error )
F_8 ( V_2 ) ;
}
F_9 ( V_2 -> V_14 ) ;
return error ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_15 = 1 ;
struct V_1 * V_16 = V_2 ;
do {
if ( F_11 ( V_16 ) == NULL )
return 0 ;
V_15 += strlen ( F_11 ( V_16 ) ) + 1 ;
V_16 = V_16 -> V_16 ;
} while ( V_16 );
return V_15 ;
}
static void F_12 ( struct V_1 * V_2 , char * V_17 , int V_15 )
{
struct V_1 * V_16 ;
-- V_15 ;
for ( V_16 = V_2 ; V_16 ; V_16 = V_16 -> V_16 ) {
int V_18 = strlen ( F_11 ( V_16 ) ) ;
V_15 -= V_18 ;
strncpy ( V_17 + V_15 , F_11 ( V_16 ) , V_18 ) ;
* ( V_17 + -- V_15 ) = '/' ;
}
F_13 ( L_1 , F_11 ( V_2 ) ,
V_2 , V_19 , V_17 ) ;
}
char * F_14 ( struct V_1 * V_2 , T_1 V_20 )
{
char * V_17 ;
int V_21 ;
V_21 = F_10 ( V_2 ) ;
if ( V_21 == 0 )
return NULL ;
V_17 = F_15 ( V_21 , V_20 ) ;
if ( ! V_17 )
return NULL ;
F_12 ( V_2 , V_17 , V_21 ) ;
return V_17 ;
}
static void F_16 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 )
return;
F_17 ( V_2 -> V_22 ) ;
F_18 ( & V_2 -> V_22 -> V_23 ) ;
F_19 ( & V_2 -> V_24 , & V_2 -> V_22 -> V_25 ) ;
F_20 ( & V_2 -> V_22 -> V_23 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_22 )
return;
F_18 ( & V_2 -> V_22 -> V_23 ) ;
F_22 ( & V_2 -> V_24 ) ;
F_20 ( & V_2 -> V_22 -> V_23 ) ;
F_23 ( V_2 -> V_22 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
F_25 ( & V_2 -> V_26 ) ;
F_26 ( & V_2 -> V_24 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_28 = 0 ;
V_2 -> V_29 = 0 ;
V_2 -> V_30 = 1 ;
}
static int F_27 ( struct V_1 * V_2 )
{
int error = 0 ;
struct V_1 * V_16 ;
if ( ! V_2 )
return - V_31 ;
if ( ! V_2 -> V_32 || ! V_2 -> V_32 [ 0 ] ) {
F_28 ( 1 , L_2
L_3 , V_2 ) ;
return - V_33 ;
}
V_16 = F_29 ( V_2 -> V_16 ) ;
if ( V_2 -> V_22 ) {
if ( ! V_16 )
V_16 = F_29 ( & V_2 -> V_22 -> V_2 ) ;
F_16 ( V_2 ) ;
V_2 -> V_16 = V_16 ;
}
F_13 ( L_4 ,
F_11 ( V_2 ) , V_2 , V_19 ,
V_16 ? F_11 ( V_16 ) : L_5 ,
V_2 -> V_22 ? F_11 ( & V_2 -> V_22 -> V_2 ) : L_5 ) ;
error = F_6 ( V_2 ) ;
if ( error ) {
F_21 ( V_2 ) ;
F_30 ( V_16 ) ;
V_2 -> V_16 = NULL ;
if ( error == - V_34 )
F_28 ( 1 , L_6
L_7
L_8 ,
V_19 , F_11 ( V_2 ) ) ;
else
F_28 ( 1 , L_9 ,
V_19 , F_11 ( V_2 ) , error ,
V_16 ? F_11 ( V_16 ) : L_10 ) ;
} else
V_2 -> V_27 = 1 ;
return error ;
}
int F_31 ( struct V_1 * V_2 , const char * V_35 ,
T_2 V_36 )
{
const char * V_37 = V_2 -> V_32 ;
char * V_38 ;
if ( V_2 -> V_32 && ! V_35 )
return 0 ;
V_2 -> V_32 = F_32 ( V_39 , V_35 , V_36 ) ;
if ( ! V_2 -> V_32 )
return - V_40 ;
while ( ( V_38 = strchr ( V_2 -> V_32 , '/' ) ) )
V_38 [ 0 ] = '!' ;
F_33 ( V_37 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , const char * V_35 , ... )
{
T_2 V_36 ;
int V_41 ;
va_start ( V_36 , V_35 ) ;
V_41 = F_31 ( V_2 , V_35 , V_36 ) ;
va_end ( V_36 ) ;
return V_41 ;
}
void F_35 ( struct V_1 * V_2 , struct V_8 * V_6 )
{
char * V_42 ;
if ( ! V_2 ) {
V_42 = L_11 ;
goto error;
}
if ( ! V_6 ) {
V_42 = L_12 ;
goto error;
}
if ( V_2 -> V_30 ) {
F_36 ( V_43 L_13
L_14 , V_2 ) ;
F_37 () ;
}
F_24 ( V_2 ) ;
V_2 -> V_6 = V_6 ;
return;
error:
F_36 ( V_43 L_15 , V_2 , V_42 ) ;
F_37 () ;
}
static int F_38 ( struct V_1 * V_2 , struct V_1 * V_16 ,
const char * V_35 , T_2 V_36 )
{
int V_41 ;
V_41 = F_31 ( V_2 , V_35 , V_36 ) ;
if ( V_41 ) {
F_36 ( V_43 L_16 ) ;
return V_41 ;
}
V_2 -> V_16 = V_16 ;
return F_27 ( V_2 ) ;
}
int F_39 ( struct V_1 * V_2 , struct V_1 * V_16 ,
const char * V_35 , ... )
{
T_2 args ;
int V_41 ;
if ( ! V_2 )
return - V_33 ;
if ( ! V_2 -> V_30 ) {
F_36 ( V_43 L_17
L_18 ,
F_11 ( V_2 ) , V_2 ) ;
F_37 () ;
return - V_33 ;
}
va_start ( args , V_35 ) ;
V_41 = F_38 ( V_2 , V_16 , V_35 , args ) ;
va_end ( args ) ;
return V_41 ;
}
int F_40 ( struct V_1 * V_2 , struct V_8 * V_6 ,
struct V_1 * V_16 , const char * V_35 , ... )
{
T_2 args ;
int V_41 ;
F_35 ( V_2 , V_6 ) ;
va_start ( args , V_35 ) ;
V_41 = F_38 ( V_2 , V_16 , V_35 , args ) ;
va_end ( args ) ;
return V_41 ;
}
int F_41 ( struct V_1 * V_2 , const char * V_44 )
{
int error = 0 ;
const char * V_45 = NULL ;
const char * V_46 = NULL , * V_32 ;
char * V_47 = NULL ;
char * V_48 [ 2 ] ;
V_2 = F_29 ( V_2 ) ;
if ( ! V_2 )
return - V_33 ;
if ( ! V_2 -> V_16 )
return - V_33 ;
V_45 = F_14 ( V_2 , V_39 ) ;
if ( ! V_45 ) {
error = - V_40 ;
goto V_49;
}
V_47 = F_42 ( strlen ( V_45 ) + 15 , V_39 ) ;
if ( ! V_47 ) {
error = - V_40 ;
goto V_49;
}
sprintf ( V_47 , L_19 , V_45 ) ;
V_48 [ 0 ] = V_47 ;
V_48 [ 1 ] = NULL ;
V_32 = V_46 = F_43 ( V_44 , V_39 ) ;
if ( ! V_32 ) {
error = - V_40 ;
goto V_49;
}
error = F_44 ( V_2 , V_44 , F_1 ( V_2 ) ) ;
if ( error )
goto V_49;
V_46 = V_2 -> V_32 ;
V_2 -> V_32 = V_32 ;
F_45 ( V_2 , V_50 , V_48 ) ;
V_49:
F_33 ( V_46 ) ;
F_33 ( V_47 ) ;
F_33 ( V_45 ) ;
F_30 ( V_2 ) ;
return error ;
}
int F_46 ( struct V_1 * V_2 , struct V_1 * V_51 )
{
int error ;
struct V_1 * V_52 ;
const char * V_45 = NULL ;
char * V_47 = NULL ;
char * V_48 [ 2 ] ;
V_2 = F_29 ( V_2 ) ;
if ( ! V_2 )
return - V_33 ;
V_51 = F_29 ( V_51 ) ;
if ( ! V_51 ) {
if ( V_2 -> V_22 )
V_51 = F_29 ( & V_2 -> V_22 -> V_2 ) ;
}
V_45 = F_14 ( V_2 , V_39 ) ;
if ( ! V_45 ) {
error = - V_40 ;
goto V_49;
}
V_47 = F_42 ( strlen ( V_45 ) + 15 , V_39 ) ;
if ( ! V_47 ) {
error = - V_40 ;
goto V_49;
}
sprintf ( V_47 , L_19 , V_45 ) ;
V_48 [ 0 ] = V_47 ;
V_48 [ 1 ] = NULL ;
error = F_47 ( V_2 , V_51 , F_1 ( V_2 ) ) ;
if ( error )
goto V_49;
V_52 = V_2 -> V_16 ;
V_2 -> V_16 = V_51 ;
V_51 = NULL ;
F_30 ( V_52 ) ;
F_45 ( V_2 , V_50 , V_48 ) ;
V_49:
F_30 ( V_51 ) ;
F_30 ( V_2 ) ;
F_33 ( V_47 ) ;
F_33 ( V_45 ) ;
return error ;
}
void F_48 ( struct V_1 * V_2 )
{
struct V_53 * V_14 ;
if ( ! V_2 )
return;
V_14 = V_2 -> V_14 ;
F_8 ( V_2 ) ;
F_49 ( V_14 ) ;
V_2 -> V_27 = 0 ;
F_21 ( V_2 ) ;
F_30 ( V_2 -> V_16 ) ;
V_2 -> V_16 = NULL ;
}
struct V_1 * F_29 ( struct V_1 * V_2 )
{
if ( V_2 )
F_50 ( & V_2 -> V_26 ) ;
return V_2 ;
}
static struct V_1 * T_3 F_51 ( struct V_1 * V_2 )
{
if ( ! F_52 ( & V_2 -> V_26 ) )
V_2 = NULL ;
return V_2 ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_4 ( V_2 ) ;
const char * V_32 = V_2 -> V_32 ;
F_13 ( L_20 ,
F_11 ( V_2 ) , V_2 , V_19 , V_2 -> V_16 ) ;
if ( V_9 && ! V_9 -> V_54 )
F_13 ( L_21
L_22 ,
F_11 ( V_2 ) , V_2 ) ;
if ( V_2 -> V_28 && ! V_2 -> V_29 ) {
F_13 ( L_23 ,
F_11 ( V_2 ) , V_2 ) ;
F_54 ( V_2 , V_55 ) ;
}
if ( V_2 -> V_27 ) {
F_13 ( L_24 ,
F_11 ( V_2 ) , V_2 ) ;
F_48 ( V_2 ) ;
}
if ( V_9 && V_9 -> V_54 ) {
F_13 ( L_25 ,
F_11 ( V_2 ) , V_2 ) ;
V_9 -> V_54 ( V_2 ) ;
}
if ( V_32 ) {
F_13 ( L_26 , V_32 ) ;
F_33 ( V_32 ) ;
}
}
static void F_55 ( struct V_56 * V_57 )
{
F_53 ( F_56 ( F_57 ( V_57 ) ,
struct V_1 , V_54 ) ) ;
}
static void F_58 ( struct V_26 * V_26 )
{
struct V_1 * V_2 = F_56 ( V_26 , struct V_1 , V_26 ) ;
#ifdef F_59
F_60 ( L_27 ,
F_11 ( V_2 ) , V_2 , V_19 , V_2 -> V_16 ) ;
F_61 ( & V_2 -> V_54 , F_55 ) ;
F_62 ( & V_2 -> V_54 , V_58 ) ;
#else
F_53 ( V_2 ) ;
#endif
}
void F_30 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! V_2 -> V_30 )
F_28 ( 1 , V_59 L_28
L_29
L_30 , F_11 ( V_2 ) , V_2 ) ;
F_63 ( & V_2 -> V_26 , F_58 ) ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
F_13 ( L_31 , V_2 , V_19 ) ;
F_33 ( V_2 ) ;
}
struct V_1 * F_65 ( void )
{
struct V_1 * V_2 ;
V_2 = F_15 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 )
return NULL ;
F_35 ( V_2 , & V_60 ) ;
return V_2 ;
}
struct V_1 * F_66 ( const char * V_32 , struct V_1 * V_16 )
{
struct V_1 * V_2 ;
int V_41 ;
V_2 = F_65 () ;
if ( ! V_2 )
return NULL ;
V_41 = F_39 ( V_2 , V_16 , L_32 , V_32 ) ;
if ( V_41 ) {
F_36 ( V_59 L_33 ,
V_19 , V_41 ) ;
F_30 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_67 ( struct V_22 * V_61 )
{
F_24 ( & V_61 -> V_2 ) ;
F_26 ( & V_61 -> V_25 ) ;
F_68 ( & V_61 -> V_23 ) ;
}
static T_4 F_69 ( struct V_1 * V_2 , struct V_10 * V_11 ,
char * V_62 )
{
struct V_63 * V_64 ;
T_4 V_65 = - V_66 ;
V_64 = F_56 ( V_11 , struct V_63 , V_11 ) ;
if ( V_64 -> V_67 )
V_65 = V_64 -> V_67 ( V_2 , V_64 , V_62 ) ;
return V_65 ;
}
static T_4 F_70 ( struct V_1 * V_2 , struct V_10 * V_11 ,
const char * V_62 , T_5 V_68 )
{
struct V_63 * V_64 ;
T_4 V_65 = - V_66 ;
V_64 = F_56 ( V_11 , struct V_63 , V_11 ) ;
if ( V_64 -> V_69 )
V_65 = V_64 -> V_69 ( V_2 , V_64 , V_62 , V_68 ) ;
return V_65 ;
}
void F_71 ( struct V_70 * V_71 , struct V_8 * V_6 )
{
F_72 ( & V_71 -> V_72 ) ;
F_35 ( & V_71 -> V_73 , V_6 ) ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_70 * V_71 = F_74 ( V_2 ) ;
F_75 ( & V_71 -> V_72 ) ;
}
void F_76 ( struct V_70 * V_71 )
{
F_48 ( & V_71 -> V_73 ) ;
F_30 ( & V_71 -> V_73 ) ;
F_77 ( & V_71 -> V_72 ) ;
}
int F_78 ( struct V_22 * V_61 )
{
int V_74 ;
if ( ! V_61 )
return - V_33 ;
F_67 ( V_61 ) ;
V_74 = F_27 ( & V_61 -> V_2 ) ;
if ( V_74 )
return V_74 ;
F_54 ( & V_61 -> V_2 , V_75 ) ;
return 0 ;
}
void F_79 ( struct V_22 * V_61 )
{
if ( ! V_61 )
return;
F_30 ( & V_61 -> V_2 ) ;
}
struct V_1 * F_80 ( struct V_22 * V_22 , const char * V_32 )
{
struct V_1 * V_61 ;
struct V_1 * V_65 = NULL ;
F_18 ( & V_22 -> V_23 ) ;
F_81 (k, &kset->list, entry) {
if ( F_11 ( V_61 ) && ! strcmp ( F_11 ( V_61 ) , V_32 ) ) {
V_65 = F_51 ( V_61 ) ;
break;
}
}
F_20 ( & V_22 -> V_23 ) ;
return V_65 ;
}
static void F_82 ( struct V_1 * V_2 )
{
struct V_22 * V_22 = F_56 ( V_2 , struct V_22 , V_2 ) ;
F_13 ( L_34 ,
F_11 ( V_2 ) , V_2 , V_19 ) ;
F_33 ( V_22 ) ;
}
static struct V_22 * F_83 ( const char * V_32 ,
const struct V_76 * V_77 ,
struct V_1 * V_78 )
{
struct V_22 * V_22 ;
int V_41 ;
V_22 = F_15 ( sizeof( * V_22 ) , V_39 ) ;
if ( ! V_22 )
return NULL ;
V_41 = F_34 ( & V_22 -> V_2 , L_32 , V_32 ) ;
if ( V_41 ) {
F_33 ( V_22 ) ;
return NULL ;
}
V_22 -> V_77 = V_77 ;
V_22 -> V_2 . V_16 = V_78 ;
V_22 -> V_2 . V_6 = & V_79 ;
V_22 -> V_2 . V_22 = NULL ;
return V_22 ;
}
struct V_22 * F_84 ( const char * V_32 ,
const struct V_76 * V_77 ,
struct V_1 * V_78 )
{
struct V_22 * V_22 ;
int error ;
V_22 = F_83 ( V_32 , V_77 , V_78 ) ;
if ( ! V_22 )
return NULL ;
error = F_78 ( V_22 ) ;
if ( error ) {
F_33 ( V_22 ) ;
return NULL ;
}
return V_22 ;
}
int F_85 ( const struct V_3 * V_80 )
{
enum V_81 type = V_80 -> type ;
int error ;
F_18 ( & V_82 ) ;
error = - V_33 ;
if ( type >= V_83 )
goto V_49;
error = - V_33 ;
if ( type <= V_5 )
goto V_49;
error = - V_84 ;
if ( V_85 [ type ] )
goto V_49;
error = 0 ;
V_85 [ type ] = V_80 ;
V_49:
F_20 ( & V_82 ) ;
return error ;
}
int F_86 ( enum V_81 type )
{
int V_86 = 0 ;
F_18 ( & V_82 ) ;
if ( ( type > V_5 ) && ( type < V_83 ) )
V_86 = V_85 [ type ] != NULL ;
F_20 ( & V_82 ) ;
return V_86 ;
}
const struct V_3 * F_87 ( struct V_1 * V_16 )
{
const struct V_3 * V_80 = NULL ;
if ( V_16 && V_16 -> V_6 -> V_87 )
V_80 = V_16 -> V_6 -> V_87 ( V_16 ) ;
return V_80 ;
}
const struct V_3 * F_2 ( struct V_1 * V_2 )
{
return F_87 ( V_2 -> V_16 ) ;
}
bool F_88 ( enum V_81 type )
{
bool V_88 = true ;
F_18 ( & V_82 ) ;
if ( ( type > V_5 ) && ( type < V_83 ) &&
V_85 [ type ] )
V_88 = V_85 [ type ] -> F_89 () ;
F_20 ( & V_82 ) ;
return V_88 ;
}
void * F_90 ( enum V_81 type )
{
void * V_89 = NULL ;
F_18 ( & V_82 ) ;
if ( ( type > V_5 ) && ( type < V_83 ) &&
V_85 [ type ] )
V_89 = V_85 [ type ] -> F_91 () ;
F_20 ( & V_82 ) ;
return V_89 ;
}
const void * F_92 ( enum V_81 type , struct V_90 * V_91 )
{
const void * V_89 = NULL ;
F_18 ( & V_82 ) ;
if ( ( type > V_5 ) && ( type < V_83 ) &&
V_85 [ type ] )
V_89 = V_85 [ type ] -> F_93 ( V_91 ) ;
F_20 ( & V_82 ) ;
return V_89 ;
}
const void * F_94 ( enum V_81 type )
{
const void * V_89 = NULL ;
F_18 ( & V_82 ) ;
if ( ( type > V_5 ) && ( type < V_83 ) &&
V_85 [ type ] )
V_89 = V_85 [ type ] -> F_95 () ;
F_20 ( & V_82 ) ;
return V_89 ;
}
void F_96 ( enum V_81 type , void * V_89 )
{
F_18 ( & V_82 ) ;
if ( ( type > V_5 ) && ( type < V_83 ) &&
V_85 [ type ] && V_85 [ type ] -> V_92 )
V_85 [ type ] -> V_92 ( V_89 ) ;
F_20 ( & V_82 ) ;
}
