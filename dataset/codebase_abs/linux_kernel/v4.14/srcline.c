static const char * F_1 ( struct V_1 * V_1 )
{
const char * V_2 ;
if ( V_1 -> V_3 )
V_2 = V_1 -> V_3 ;
else
V_2 = V_1 -> V_4 ;
if ( V_2 [ 0 ] == '[' )
return NULL ;
if ( ! strncmp ( V_2 , L_1 , 10 ) )
return NULL ;
return V_2 ;
}
static int F_2 ( char * V_5 , char * V_6 , int V_7 ,
struct V_8 * V_9 , struct V_1 * V_1 )
{
struct V_10 * V_11 ;
char * V_12 ;
V_11 = F_3 ( sizeof( * V_11 ) ) ;
if ( V_11 == NULL )
return - 1 ;
V_11 -> V_5 = V_5 ;
V_11 -> V_7 = V_7 ;
if ( V_1 != NULL ) {
V_12 = F_4 ( V_1 , 0 , V_6 ) ;
if ( V_12 == NULL ) {
V_11 -> V_6 = V_6 ;
} else {
V_11 -> V_6 = V_12 ;
free ( V_6 ) ;
}
}
if ( V_13 . V_14 == V_15 )
F_5 ( & V_11 -> V_16 , & V_9 -> V_17 ) ;
else
F_6 ( & V_11 -> V_16 , & V_9 -> V_17 ) ;
return 0 ;
}
static int F_7 ( const char * string )
{
const char * V_18 ;
V_18 = F_8 ( F_9 () ) ;
fflush ( stdout ) ;
if ( string )
F_10 ( L_2 , string , V_18 ) ;
else
F_10 ( L_3 , V_18 ) ;
return - 1 ;
}
static int F_11 ( T_1 * V_19 , struct V_20 * V_21 )
{
long V_22 ;
long V_23 ;
T_2 * * V_24 ;
T_3 V_25 = FALSE ;
if ( ( F_12 ( V_19 ) & V_26 ) == 0 )
return F_7 ( F_13 ( V_19 ) ) ;
V_22 = F_14 ( V_19 ) ;
if ( V_22 == 0L ) {
V_22 = F_15 ( V_19 ) ;
V_25 = TRUE ;
}
if ( V_22 < 0L )
return F_7 ( F_13 ( V_19 ) ) ;
V_24 = malloc ( V_22 ) ;
if ( V_25 )
V_23 = F_16 ( V_19 , V_24 ) ;
else
V_23 = F_17 ( V_19 , V_24 ) ;
if ( V_23 < 0 ) {
free ( V_24 ) ;
return F_7 ( F_13 ( V_19 ) ) ;
}
V_21 -> V_24 = V_24 ;
return 0 ;
}
static void F_18 ( T_1 * V_19 , T_4 * V_27 , void * V_28 )
{
T_5 V_29 , V_30 ;
T_6 V_31 ;
struct V_20 * V_21 = V_28 ;
if ( V_21 -> V_32 )
return;
if ( ( F_19 ( V_19 , V_27 ) & V_33 ) == 0 )
return;
V_29 = V_21 -> V_34 ;
V_30 = F_20 ( V_19 , V_27 ) ;
V_31 = F_21 ( V_27 ) ;
if ( V_29 < V_30 || V_29 >= V_30 + V_31 )
return;
V_21 -> V_32 = F_22 ( V_19 , V_27 , V_21 -> V_24 , V_29 - V_30 ,
& V_21 -> V_5 , & V_21 -> V_6 ,
& V_21 -> line ) ;
if ( V_21 -> V_5 && ! strlen ( V_21 -> V_5 ) )
V_21 -> V_5 = NULL ;
}
static struct V_20 * F_23 ( const char * V_35 )
{
T_1 * V_19 ;
struct V_20 * V_21 = NULL ;
V_19 = F_24 ( V_35 , NULL ) ;
if ( V_19 == NULL )
return NULL ;
if ( ! F_25 ( V_19 , V_36 ) )
goto V_37;
V_21 = F_3 ( sizeof( * V_21 ) ) ;
if ( V_21 == NULL )
goto V_37;
V_21 -> V_19 = V_19 ;
V_21 -> V_38 = F_26 ( V_35 ) ;
if ( V_21 -> V_38 == NULL )
goto V_37;
if ( F_11 ( V_19 , V_21 ) )
goto V_37;
return V_21 ;
V_37:
if ( V_21 ) {
F_27 ( ( char * * ) & V_21 -> V_38 ) ;
free ( V_21 ) ;
}
F_28 ( V_19 ) ;
return NULL ;
}
static void F_29 ( struct V_20 * V_21 )
{
if ( V_21 -> V_19 )
F_28 ( V_21 -> V_19 ) ;
F_27 ( ( char * * ) & V_21 -> V_38 ) ;
F_27 ( & V_21 -> V_24 ) ;
free ( V_21 ) ;
}
static int F_30 ( struct V_1 * V_1 ,
struct V_8 * V_9 )
{
struct V_20 * V_21 = V_1 -> V_21 ;
char * V_6 = V_21 -> V_6 ? F_26 ( V_21 -> V_6 ) : NULL ;
char * V_5 = V_21 -> V_5 ? F_26 ( V_21 -> V_5 ) : NULL ;
return F_2 ( V_5 , V_6 , V_21 -> line , V_9 , V_1 ) ;
}
static int F_31 ( const char * V_2 , T_7 V_34 ,
char * * V_39 , unsigned int * line , struct V_1 * V_1 ,
bool V_40 , struct V_8 * V_9 )
{
int V_41 = 0 ;
struct V_20 * V_21 = V_1 -> V_21 ;
if ( ! V_21 ) {
V_1 -> V_21 = F_23 ( V_2 ) ;
V_21 = V_1 -> V_21 ;
}
if ( V_21 == NULL ) {
F_32 ( L_4 , V_2 ) ;
return 0 ;
}
V_21 -> V_34 = V_34 ;
V_21 -> V_32 = false ;
F_33 ( V_21 -> V_19 , F_18 , V_21 ) ;
if ( ! V_21 -> V_32 )
return 0 ;
if ( V_40 ) {
int V_42 = 0 ;
if ( V_9 && F_30 ( V_1 , V_9 ) )
return 0 ;
while ( F_34 ( V_21 -> V_19 , & V_21 -> V_5 ,
& V_21 -> V_6 , & V_21 -> line ) &&
V_42 ++ < V_43 ) {
if ( V_21 -> V_5 && ! strlen ( V_21 -> V_5 ) )
V_21 -> V_5 = NULL ;
if ( V_9 != NULL ) {
if ( F_30 ( V_1 , V_9 ) )
return 0 ;
V_41 = 1 ;
}
}
}
if ( V_39 ) {
* V_39 = V_21 -> V_5 ? F_26 ( V_21 -> V_5 ) : NULL ;
V_41 = * V_39 ? 1 : 0 ;
}
if ( line )
* line = V_21 -> line ;
return V_41 ;
}
void F_35 ( struct V_1 * V_1 )
{
struct V_20 * V_21 = V_1 -> V_21 ;
if ( ! V_21 )
return;
F_29 ( V_21 ) ;
V_1 -> V_21 = NULL ;
}
static struct V_8 * F_36 ( const char * V_2 , T_7 V_34 ,
struct V_1 * V_1 )
{
struct V_8 * V_9 ;
V_9 = F_3 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
perror ( L_5 ) ;
return NULL ;
}
F_37 ( & V_9 -> V_17 ) ;
V_9 -> V_34 = V_34 ;
if ( ! F_31 ( V_2 , V_34 , NULL , NULL , V_1 , TRUE , V_9 ) )
goto V_44;
if ( F_38 ( & V_9 -> V_17 ) )
goto V_44;
return V_9 ;
V_44:
F_39 ( V_9 ) ;
return NULL ;
}
static int F_40 ( char * V_5 , unsigned int * V_7 )
{
char * V_45 ;
V_45 = strchr ( V_5 , '\n' ) ;
if ( V_45 )
* V_45 = '\0' ;
if ( ! strcmp ( V_5 , L_6 ) )
return 0 ;
V_45 = strchr ( V_5 , ':' ) ;
if ( V_45 ) {
* V_45 ++ = '\0' ;
* V_7 = strtoul ( V_45 , NULL , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_31 ( const char * V_2 , T_7 V_34 ,
char * * V_39 , unsigned int * V_7 ,
struct V_1 * V_1 V_46 ,
bool V_40 V_46 ,
struct V_8 * V_9 V_46 )
{
T_8 * V_47 ;
char V_48 [ V_49 ] ;
char * V_5 = NULL ;
T_9 V_50 ;
int V_41 = 0 ;
F_41 ( V_48 , sizeof( V_48 ) , L_7 V_51 ,
V_2 , V_34 ) ;
V_47 = F_42 ( V_48 , L_8 ) ;
if ( V_47 == NULL ) {
F_32 ( L_9 , V_2 ) ;
return 0 ;
}
if ( F_43 ( & V_5 , & V_50 , V_47 ) < 0 || ! V_50 ) {
F_32 ( L_10 , V_2 ) ;
goto V_37;
}
V_41 = F_40 ( V_5 , V_7 ) ;
if ( V_41 != 1 ) {
free ( V_5 ) ;
goto V_37;
}
* V_39 = V_5 ;
V_37:
F_44 ( V_47 ) ;
return V_41 ;
}
void F_35 ( struct V_1 * V_1 V_46 )
{
}
static struct V_8 * F_36 ( const char * V_2 , T_7 V_34 ,
struct V_1 * V_1 V_46 )
{
T_8 * V_47 ;
char V_48 [ V_49 ] ;
struct V_8 * V_9 ;
char * V_5 = NULL ;
T_9 V_50 ;
unsigned int V_7 = 0 ;
F_41 ( V_48 , sizeof( V_48 ) , L_11 V_51 ,
V_2 , V_34 ) ;
V_47 = F_42 ( V_48 , L_8 ) ;
if ( V_47 == NULL ) {
F_45 ( L_9 , V_2 ) ;
return NULL ;
}
V_9 = F_3 ( sizeof( * V_9 ) ) ;
if ( V_9 == NULL ) {
perror ( L_5 ) ;
goto V_37;
}
F_37 ( & V_9 -> V_17 ) ;
V_9 -> V_34 = V_34 ;
while ( F_43 ( & V_5 , & V_50 , V_47 ) != - 1 ) {
if ( F_40 ( V_5 , & V_7 ) != 1 ) {
free ( V_5 ) ;
goto V_37;
}
if ( F_2 ( V_5 , NULL , V_7 , V_9 ,
NULL ) != 0 )
goto V_37;
V_5 = NULL ;
}
V_37:
F_44 ( V_47 ) ;
if ( F_38 ( & V_9 -> V_17 ) ) {
F_39 ( V_9 ) ;
return NULL ;
}
return V_9 ;
}
char * F_46 ( struct V_1 * V_1 , T_7 V_34 , struct V_52 * V_53 ,
bool V_54 , bool V_55 , bool V_40 )
{
char * V_39 = NULL ;
unsigned line = 0 ;
char * V_56 ;
const char * V_2 ;
if ( ! V_1 -> V_57 )
goto V_37;
V_2 = F_1 ( V_1 ) ;
if ( V_2 == NULL )
goto V_37;
if ( ! F_31 ( V_2 , V_34 , & V_39 , & line , V_1 , V_40 , NULL ) )
goto V_37;
if ( F_47 ( & V_56 , L_12 ,
V_58 ? V_39 : F_48 ( V_39 ) ,
line ) < 0 ) {
free ( V_39 ) ;
goto V_37;
}
V_1 -> V_59 = 0 ;
free ( V_39 ) ;
return V_56 ;
V_37:
if ( V_1 -> V_59 && ++ V_1 -> V_59 > V_60 ) {
V_1 -> V_57 = 0 ;
F_35 ( V_1 ) ;
}
if ( ! V_55 )
return ( V_54 && V_53 ) ?
F_49 ( V_53 -> V_61 , V_53 -> V_62 ) : NULL ;
if ( V_53 ) {
if ( F_47 ( & V_56 , L_13 V_63 , V_54 ? V_53 -> V_61 : L_14 ,
V_34 - V_53 -> V_64 ) < 0 )
return V_65 ;
} else if ( F_47 ( & V_56 , L_15 V_51 L_16 , V_1 -> V_66 , V_34 ) < 0 )
return V_65 ;
return V_56 ;
}
void F_50 ( char * V_56 )
{
if ( V_56 && strcmp ( V_56 , V_65 ) != 0 )
free ( V_56 ) ;
}
char * F_51 ( struct V_1 * V_1 , T_7 V_34 , struct V_52 * V_53 ,
bool V_54 , bool V_55 )
{
return F_46 ( V_1 , V_34 , V_53 , V_54 , V_55 , false ) ;
}
struct V_8 * F_52 ( struct V_1 * V_1 , T_7 V_34 )
{
const char * V_2 ;
V_2 = F_1 ( V_1 ) ;
if ( V_2 == NULL )
return NULL ;
return F_36 ( V_2 , V_34 , V_1 ) ;
}
void F_39 ( struct V_8 * V_9 )
{
struct V_10 * V_11 , * V_67 ;
F_53 (ilist, tmp, &node->val, list) {
F_54 ( & V_11 -> V_16 ) ;
F_27 ( & V_11 -> V_5 ) ;
F_27 ( & V_11 -> V_6 ) ;
free ( V_11 ) ;
}
free ( V_9 ) ;
}
