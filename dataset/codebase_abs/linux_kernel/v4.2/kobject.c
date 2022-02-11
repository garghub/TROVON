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
char * V_39 ;
if ( V_2 -> V_34 && ! V_37 )
return 0 ;
V_39 = F_36 ( V_40 , V_37 , V_38 ) ;
if ( ! V_39 )
return - V_41 ;
F_37 ( V_39 , '/' , '!' ) ;
F_38 ( V_2 -> V_34 ) ;
V_2 -> V_34 = V_39 ;
return 0 ;
}
int F_39 ( struct V_1 * V_2 , const char * V_37 , ... )
{
T_2 V_38 ;
int V_42 ;
va_start ( V_38 , V_37 ) ;
V_42 = F_35 ( V_2 , V_37 , V_38 ) ;
va_end ( V_38 ) ;
return V_42 ;
}
void F_40 ( struct V_1 * V_2 , struct V_8 * V_6 )
{
char * V_43 ;
if ( ! V_2 ) {
V_43 = L_11 ;
goto error;
}
if ( ! V_6 ) {
V_43 = L_12 ;
goto error;
}
if ( V_2 -> V_32 ) {
F_41 ( V_44 L_13
L_14 , V_2 ) ;
F_42 () ;
}
F_28 ( V_2 ) ;
V_2 -> V_6 = V_6 ;
return;
error:
F_41 ( V_44 L_15 , V_2 , V_43 ) ;
F_42 () ;
}
int F_43 ( struct V_1 * V_2 , struct V_8 * V_6 ,
struct V_1 * V_18 , const char * V_37 , ... )
{
T_2 args ;
int V_42 ;
F_40 ( V_2 , V_6 ) ;
va_start ( args , V_37 ) ;
V_42 = F_44 ( V_2 , V_18 , V_37 , args ) ;
va_end ( args ) ;
return V_42 ;
}
int F_45 ( struct V_1 * V_2 , const char * V_45 )
{
int error = 0 ;
const char * V_46 = NULL ;
const char * V_47 = NULL , * V_34 ;
char * V_48 = NULL ;
char * V_49 [ 2 ] ;
V_2 = F_33 ( V_2 ) ;
if ( ! V_2 )
return - V_35 ;
if ( ! V_2 -> V_18 )
return - V_35 ;
V_46 = F_18 ( V_2 , V_40 ) ;
if ( ! V_46 ) {
error = - V_41 ;
goto V_50;
}
V_48 = F_46 ( strlen ( V_46 ) + 15 , V_40 ) ;
if ( ! V_48 ) {
error = - V_41 ;
goto V_50;
}
sprintf ( V_48 , L_16 , V_46 ) ;
V_49 [ 0 ] = V_48 ;
V_49 [ 1 ] = NULL ;
V_34 = V_47 = F_47 ( V_45 , V_40 ) ;
if ( ! V_34 ) {
error = - V_41 ;
goto V_50;
}
error = F_48 ( V_2 , V_45 , F_1 ( V_2 ) ) ;
if ( error )
goto V_50;
V_47 = V_2 -> V_34 ;
V_2 -> V_34 = V_34 ;
F_49 ( V_2 , V_51 , V_49 ) ;
V_50:
F_38 ( V_47 ) ;
F_38 ( V_48 ) ;
F_38 ( V_46 ) ;
F_34 ( V_2 ) ;
return error ;
}
int F_50 ( struct V_1 * V_2 , struct V_1 * V_52 )
{
int error ;
struct V_1 * V_53 ;
const char * V_46 = NULL ;
char * V_48 = NULL ;
char * V_49 [ 2 ] ;
V_2 = F_33 ( V_2 ) ;
if ( ! V_2 )
return - V_35 ;
V_52 = F_33 ( V_52 ) ;
if ( ! V_52 ) {
if ( V_2 -> V_24 )
V_52 = F_33 ( & V_2 -> V_24 -> V_2 ) ;
}
V_46 = F_18 ( V_2 , V_40 ) ;
if ( ! V_46 ) {
error = - V_41 ;
goto V_50;
}
V_48 = F_46 ( strlen ( V_46 ) + 15 , V_40 ) ;
if ( ! V_48 ) {
error = - V_41 ;
goto V_50;
}
sprintf ( V_48 , L_16 , V_46 ) ;
V_49 [ 0 ] = V_48 ;
V_49 [ 1 ] = NULL ;
error = F_51 ( V_2 , V_52 , F_1 ( V_2 ) ) ;
if ( error )
goto V_50;
V_53 = V_2 -> V_18 ;
V_2 -> V_18 = V_52 ;
V_52 = NULL ;
F_34 ( V_53 ) ;
F_49 ( V_2 , V_51 , V_49 ) ;
V_50:
F_34 ( V_52 ) ;
F_34 ( V_2 ) ;
F_38 ( V_48 ) ;
F_38 ( V_46 ) ;
return error ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_54 * V_15 ;
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
F_32 ( 1 , V_55 L_17
L_18
L_19 , F_15 ( V_2 ) , V_2 ) ;
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
F_17 ( L_20 ,
F_15 ( V_2 ) , V_2 , V_21 , V_2 -> V_18 ) ;
if ( V_9 && ! V_9 -> V_56 )
F_17 ( L_21
L_22 ,
F_15 ( V_2 ) , V_2 ) ;
if ( V_2 -> V_30 && ! V_2 -> V_31 ) {
F_17 ( L_23 ,
F_15 ( V_2 ) , V_2 ) ;
F_58 ( V_2 , V_57 ) ;
}
if ( V_2 -> V_29 ) {
F_17 ( L_24 ,
F_15 ( V_2 ) , V_2 ) ;
F_52 ( V_2 ) ;
}
if ( V_9 && V_9 -> V_56 ) {
F_17 ( L_25 ,
F_15 ( V_2 ) , V_2 ) ;
V_9 -> V_56 ( V_2 ) ;
}
if ( V_34 ) {
F_17 ( L_26 , V_34 ) ;
F_38 ( V_34 ) ;
}
}
static void F_59 ( struct V_58 * V_59 )
{
F_57 ( F_60 ( F_61 ( V_59 ) ,
struct V_1 , V_56 ) ) ;
}
static void F_62 ( struct V_28 * V_28 )
{
struct V_1 * V_2 = F_60 ( V_28 , struct V_1 , V_28 ) ;
#ifdef F_63
unsigned long V_60 = V_61 + V_61 * ( F_64 () & 0x3 ) ;
F_65 ( L_27 ,
F_15 ( V_2 ) , V_2 , V_21 , V_2 -> V_18 , V_60 ) ;
F_66 ( & V_2 -> V_56 , F_59 ) ;
F_67 ( & V_2 -> V_56 , V_60 ) ;
#else
F_57 ( V_2 ) ;
#endif
}
void F_34 ( struct V_1 * V_2 )
{
if ( V_2 ) {
if ( ! V_2 -> V_32 )
F_32 ( 1 , V_55 L_17
L_28
L_19 , F_15 ( V_2 ) , V_2 ) ;
F_68 ( & V_2 -> V_28 , F_62 ) ;
}
}
static void F_69 ( struct V_1 * V_2 )
{
F_17 ( L_29 , V_2 , V_21 ) ;
F_38 ( V_2 ) ;
}
struct V_1 * F_70 ( void )
{
struct V_1 * V_2 ;
V_2 = F_19 ( sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return NULL ;
F_40 ( V_2 , & V_62 ) ;
return V_2 ;
}
struct V_1 * F_71 ( const char * V_34 , struct V_1 * V_18 )
{
struct V_1 * V_2 ;
int V_42 ;
V_2 = F_70 () ;
if ( ! V_2 )
return NULL ;
V_42 = F_72 ( V_2 , V_18 , L_30 , V_34 ) ;
if ( V_42 ) {
F_41 ( V_55 L_31 ,
V_21 , V_42 ) ;
F_34 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_73 ( struct V_24 * V_63 )
{
F_28 ( & V_63 -> V_2 ) ;
F_30 ( & V_63 -> V_27 ) ;
F_74 ( & V_63 -> V_25 ) ;
}
static T_4 F_75 ( struct V_1 * V_2 , struct V_10 * V_11 ,
char * V_64 )
{
struct V_65 * V_66 ;
T_4 V_67 = - V_68 ;
V_66 = F_60 ( V_11 , struct V_65 , V_11 ) ;
if ( V_66 -> V_69 )
V_67 = V_66 -> V_69 ( V_2 , V_66 , V_64 ) ;
return V_67 ;
}
static T_4 F_76 ( struct V_1 * V_2 , struct V_10 * V_11 ,
const char * V_64 , T_5 V_70 )
{
struct V_65 * V_66 ;
T_4 V_67 = - V_68 ;
V_66 = F_60 ( V_11 , struct V_65 , V_11 ) ;
if ( V_66 -> V_71 )
V_67 = V_66 -> V_71 ( V_2 , V_66 , V_64 , V_70 ) ;
return V_67 ;
}
int F_77 ( struct V_24 * V_63 )
{
int V_72 ;
if ( ! V_63 )
return - V_35 ;
F_73 ( V_63 ) ;
V_72 = F_31 ( & V_63 -> V_2 ) ;
if ( V_72 )
return V_72 ;
F_58 ( & V_63 -> V_2 , V_73 ) ;
return 0 ;
}
void F_78 ( struct V_24 * V_63 )
{
if ( ! V_63 )
return;
F_52 ( & V_63 -> V_2 ) ;
F_34 ( & V_63 -> V_2 ) ;
}
struct V_1 * F_79 ( struct V_24 * V_24 , const char * V_34 )
{
struct V_1 * V_63 ;
struct V_1 * V_67 = NULL ;
F_22 ( & V_24 -> V_25 ) ;
F_80 (k, &kset->list, entry) {
if ( F_15 ( V_63 ) && ! strcmp ( F_15 ( V_63 ) , V_34 ) ) {
V_67 = F_55 ( V_63 ) ;
break;
}
}
F_24 ( & V_24 -> V_25 ) ;
return V_67 ;
}
static void F_81 ( struct V_1 * V_2 )
{
struct V_24 * V_24 = F_60 ( V_2 , struct V_24 , V_2 ) ;
F_17 ( L_32 ,
F_15 ( V_2 ) , V_2 , V_21 ) ;
F_38 ( V_24 ) ;
}
static struct V_24 * F_82 ( const char * V_34 ,
const struct V_74 * V_75 ,
struct V_1 * V_76 )
{
struct V_24 * V_24 ;
int V_42 ;
V_24 = F_19 ( sizeof( * V_24 ) , V_40 ) ;
if ( ! V_24 )
return NULL ;
V_42 = F_39 ( & V_24 -> V_2 , L_30 , V_34 ) ;
if ( V_42 ) {
F_38 ( V_24 ) ;
return NULL ;
}
V_24 -> V_75 = V_75 ;
V_24 -> V_2 . V_18 = V_76 ;
V_24 -> V_2 . V_6 = & V_77 ;
V_24 -> V_2 . V_24 = NULL ;
return V_24 ;
}
struct V_24 * F_83 ( const char * V_34 ,
const struct V_74 * V_75 ,
struct V_1 * V_76 )
{
struct V_24 * V_24 ;
int error ;
V_24 = F_82 ( V_34 , V_75 , V_76 ) ;
if ( ! V_24 )
return NULL ;
error = F_77 ( V_24 ) ;
if ( error ) {
F_38 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
int F_84 ( const struct V_3 * V_14 )
{
enum V_78 type = V_14 -> type ;
int error ;
F_22 ( & V_79 ) ;
error = - V_35 ;
if ( type >= V_16 )
goto V_50;
error = - V_35 ;
if ( type <= V_5 )
goto V_50;
error = - V_80 ;
if ( V_81 [ type ] )
goto V_50;
error = 0 ;
V_81 [ type ] = V_14 ;
V_50:
F_24 ( & V_79 ) ;
return error ;
}
int F_12 ( enum V_78 type )
{
int V_82 = 0 ;
F_22 ( & V_79 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) )
V_82 = V_81 [ type ] != NULL ;
F_24 ( & V_79 ) ;
return V_82 ;
}
const struct V_3 * F_10 ( struct V_1 * V_18 )
{
const struct V_3 * V_14 = NULL ;
if ( V_18 && V_18 -> V_6 && V_18 -> V_6 -> V_83 )
V_14 = V_18 -> V_6 -> V_83 ( V_18 ) ;
return V_14 ;
}
const struct V_3 * F_2 ( struct V_1 * V_2 )
{
return F_10 ( V_2 -> V_18 ) ;
}
bool F_85 ( enum V_78 type )
{
bool V_84 = true ;
F_22 ( & V_79 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_81 [ type ] )
V_84 = V_81 [ type ] -> F_86 () ;
F_24 ( & V_79 ) ;
return V_84 ;
}
void * F_87 ( enum V_78 type )
{
void * V_85 = NULL ;
F_22 ( & V_79 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_81 [ type ] )
V_85 = V_81 [ type ] -> F_88 () ;
F_24 ( & V_79 ) ;
return V_85 ;
}
const void * F_89 ( enum V_78 type , struct V_86 * V_87 )
{
const void * V_85 = NULL ;
F_22 ( & V_79 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_81 [ type ] )
V_85 = V_81 [ type ] -> F_90 ( V_87 ) ;
F_24 ( & V_79 ) ;
return V_85 ;
}
const void * F_91 ( enum V_78 type )
{
const void * V_85 = NULL ;
F_22 ( & V_79 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_81 [ type ] )
V_85 = V_81 [ type ] -> F_92 () ;
F_24 ( & V_79 ) ;
return V_85 ;
}
void F_93 ( enum V_78 type , void * V_85 )
{
F_22 ( & V_79 ) ;
if ( ( type > V_5 ) && ( type < V_16 ) &&
V_81 [ type ] && V_81 [ type ] -> V_88 )
V_81 [ type ] -> V_88 ( V_85 ) ;
F_24 ( & V_79 ) ;
}
