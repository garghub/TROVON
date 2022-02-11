static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( strrchr ( V_2 -> V_5 , '/' ) + 1 , V_2 -> V_6 -> V_7 ) ;
if ( V_4 )
F_3 ( V_2 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_1 * V_6 = V_2 -> V_6 ;
while ( V_9 ) {
F_5 ( V_9 -> V_11 , V_2 -> V_7 ) ;
V_9 = V_9 -> V_12 ;
}
if ( V_2 -> V_7 )
F_5 ( V_2 -> V_7 -> V_11 , V_6 -> V_7 ) ;
}
static void F_1 ( struct V_1 * V_2 )
{
return;
}
static void F_4 ( struct V_1 * V_2 )
{
return;
}
static struct V_1 * F_6 ( const char * V_13 )
{
struct V_1 * V_6 = NULL ;
char * V_14 = L_1 ;
T_1 V_15 = strrchr ( V_13 , '/' ) - V_13 + 1 ;
if ( ! strcmp ( V_13 , L_1 ) )
return F_7 ( - V_16 ) ;
if ( strrchr ( V_13 , '/' ) != V_13 ) {
V_14 = F_8 ( V_15 , V_17 ) ;
if ( ! V_14 )
return F_7 ( - V_18 ) ;
F_9 ( V_14 , V_13 , V_15 ) ;
}
V_6 = F_10 ( V_14 ) ;
if ( ! V_6 )
return F_7 ( - V_16 ) ;
if ( strcmp ( V_14 , L_1 ) )
F_11 ( V_14 ) ;
return V_6 ;
}
int F_12 ( struct V_19 * V_20 )
{
return F_13 ( & V_21 , V_20 ) ;
}
void F_14 ( struct V_19 * V_20 )
{
F_15 ( & V_21 , V_20 ) ;
}
int F_16 ( unsigned long V_22 , void * V_23 )
{
int V_24 = F_17 ( & V_21 ,
V_22 , V_23 ) ;
return F_18 ( V_24 ) ;
}
static int F_19 ( const char * V_13 , struct V_8 * V_25 )
{
struct V_1 * V_2 ;
int V_24 = - V_18 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
goto V_26;
V_2 -> V_5 = F_21 ( V_13 , V_17 ) ;
if ( ! V_2 -> V_5 )
goto V_26;
V_2 -> V_10 = V_25 ;
F_22 ( V_2 , V_27 ) ;
F_23 ( & V_2 -> V_28 ) ;
V_2 -> V_6 = F_6 ( V_13 ) ;
if ( F_24 ( V_2 -> V_6 ) ) {
V_24 = F_25 ( V_2 -> V_6 ) ;
goto V_26;
}
V_24 = F_16 ( V_29 , V_2 ) ;
if ( V_24 ) {
F_26 ( V_30 L_2 , V_13 ) ;
goto V_26;
}
F_27 ( V_2 ) ;
F_1 ( V_2 ) ;
F_28 ( V_2 -> V_6 ) ;
return 0 ;
V_26:
if ( V_2 ) {
F_28 ( V_2 -> V_6 ) ;
F_11 ( V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
}
return V_24 ;
}
static int F_29 ( struct V_1 * V_2 )
{
struct V_1 * V_6 , * V_31 ;
V_6 = F_30 ( V_2 ) ;
if ( ! V_6 )
return - V_16 ;
if ( ( V_31 = F_31 ( V_2 , NULL ) ) ) {
F_28 ( V_31 ) ;
F_28 ( V_6 ) ;
return - V_32 ;
}
F_4 ( V_2 ) ;
F_16 ( V_33 , V_2 ) ;
F_32 ( V_2 ) ;
F_28 ( V_6 ) ;
F_28 ( V_2 ) ;
return 0 ;
}
static void F_33 ( const struct V_8 * V_34 )
{
struct V_8 * V_12 ;
for (; V_34 ; V_34 = V_12 ) {
V_12 = V_34 -> V_12 ;
F_11 ( V_34 -> V_11 ) ;
F_11 ( V_34 -> V_35 ) ;
F_11 ( V_34 ) ;
}
}
static char * F_34 ( char * V_36 , char * V_37 , char * * V_11 , int * V_38 ,
unsigned char * * V_35 )
{
char * V_39 ;
* V_11 = V_36 ;
V_39 = strchr ( V_36 , ' ' ) ;
if ( ! V_39 ) {
F_26 ( V_30 L_3 ,
V_40 , __LINE__ ) ;
return NULL ;
}
* V_39 = '\0' ;
if ( ++ V_39 >= V_37 ) {
F_26 ( V_30 L_3 ,
V_40 , __LINE__ ) ;
return NULL ;
}
* V_38 = - 1 ;
* V_38 = F_35 ( V_39 , & V_39 , 10 ) ;
if ( * V_38 == - 1 ) {
F_26 ( V_30 L_3 ,
V_40 , __LINE__ ) ;
return NULL ;
}
if ( * V_39 != ' ' || ++ V_39 >= V_37 ) {
F_26 ( V_30 L_3 ,
V_40 , __LINE__ ) ;
return NULL ;
}
* V_35 = V_39 ;
V_39 += * V_38 ;
if ( V_39 > V_37 ) {
F_26 ( V_30 L_3 ,
V_40 , __LINE__ ) ;
return NULL ;
}
else if ( V_39 < V_37 && * V_39 != ' ' && * V_39 != '\0' ) {
F_26 ( V_30 L_3 ,
V_40 , __LINE__ ) ;
return NULL ;
}
V_39 ++ ;
return V_39 ;
}
static struct V_8 * F_36 ( const char * V_11 , const int V_38 ,
const unsigned char * V_35 , struct V_8 * V_41 )
{
struct V_8 * V_42 = F_20 ( sizeof( * V_42 ) , V_17 ) ;
if ( ! V_42 )
return NULL ;
if ( ! ( V_42 -> V_11 = F_8 ( strlen ( V_11 ) + 1 , V_17 ) ) )
goto V_43;
if ( ! ( V_42 -> V_35 = F_8 ( V_38 + 1 , V_17 ) ) )
goto V_43;
strcpy ( V_42 -> V_11 , V_11 ) ;
memcpy ( V_42 -> V_35 , V_35 , V_38 ) ;
* ( ( ( char * ) V_42 -> V_35 ) + V_38 ) = 0 ;
V_42 -> V_38 = V_38 ;
V_42 -> V_12 = V_41 ;
return V_42 ;
V_43:
F_11 ( V_42 -> V_11 ) ;
F_11 ( V_42 -> V_35 ) ;
F_11 ( V_42 ) ;
return NULL ;
}
static int F_37 ( char * V_36 , T_1 V_44 )
{
char * V_13 , * V_37 , * V_11 ;
struct V_1 * V_2 ;
struct V_8 * V_34 = NULL ;
unsigned char * V_35 ;
int V_38 , V_45 = 0 ;
V_37 = V_36 + V_44 ;
V_13 = V_36 ;
V_36 = strchr ( V_36 , ' ' ) ;
if ( ! V_36 )
return - V_16 ;
* V_36 = '\0' ;
V_36 ++ ;
if ( ( V_2 = F_10 ( V_13 ) ) ) {
F_28 ( V_2 ) ;
return - V_16 ;
}
while ( V_36 < V_37 &&
( V_36 = F_34 ( V_36 , V_37 , & V_11 , & V_38 , & V_35 ) ) ) {
struct V_8 * V_41 = V_34 ;
V_34 = F_36 ( V_11 , V_38 , V_35 , V_41 ) ;
if ( ! V_34 ) {
V_45 = - V_18 ;
V_34 = V_41 ;
goto V_46;
}
}
if ( ! V_36 ) {
V_45 = - V_16 ;
goto V_46;
}
V_45 = F_19 ( V_13 , V_34 ) ;
V_46:
if ( V_45 )
F_33 ( V_34 ) ;
return V_45 ;
}
static int F_38 ( char * V_36 )
{
struct V_1 * V_47 ;
int V_45 = - V_48 ;
if ( ( V_47 = F_10 ( V_36 ) ) )
V_45 = F_29 ( V_47 ) ;
F_28 ( V_47 ) ;
return V_45 ;
}
static char * F_39 ( char * V_36 , T_1 V_44 , struct V_1 * * V_49 )
{
char * V_50 ;
T_2 V_51 ;
* V_49 = NULL ;
V_50 = V_36 ;
V_36 = strchr ( V_36 , ' ' ) ;
if ( ! V_36 )
return NULL ;
* V_36 = '\0' ;
V_36 ++ ;
V_51 = F_35 ( V_50 , NULL , 0 ) ;
* V_49 = F_40 ( V_51 ) ;
return V_36 ;
}
static int F_41 ( char * V_36 , T_1 V_44 )
{
struct V_8 * V_34 = NULL ;
struct V_1 * V_2 ;
unsigned char * V_35 ;
char * V_11 , * V_37 ;
int V_38 ;
V_37 = V_36 + V_44 ;
V_36 = F_39 ( V_36 , V_44 , & V_2 ) ;
if ( ! V_2 )
return - V_48 ;
if ( F_34 ( V_36 , V_37 , & V_11 , & V_38 , & V_35 ) == NULL )
return - V_16 ;
V_34 = F_36 ( V_11 , V_38 , V_35 , NULL ) ;
if ( ! V_34 )
return - V_18 ;
F_42 ( V_2 , V_34 ) ;
return 0 ;
}
static int F_43 ( char * V_36 , T_1 V_44 )
{
struct V_1 * V_2 ;
char * V_39 ;
struct V_8 * V_34 ;
V_36 = F_39 ( V_36 , V_44 , & V_2 ) ;
if ( ! V_2 )
return - V_48 ;
V_39 = strchr ( V_36 , ' ' ) ;
if ( V_39 )
* V_39 = '\0' ;
if ( strlen ( V_36 ) == 0 )
return - V_16 ;
V_34 = F_44 ( V_2 , V_36 , NULL ) ;
return F_45 ( V_2 , V_34 ) ;
}
static int F_46 ( char * V_36 , T_1 V_44 )
{
struct V_1 * V_2 ;
struct V_52 V_53 ;
unsigned char * V_35 ;
char * V_11 , * V_37 , * V_54 ;
int V_55 , V_38 ;
struct V_8 * V_56 , * V_57 ;
V_36 = F_39 ( V_36 , V_44 , & V_2 ) ;
V_37 = V_36 + V_44 ;
if ( ! V_2 )
return - V_48 ;
V_54 = F_34 ( V_36 , V_37 , & V_11 , & V_38 , & V_35 ) ;
if ( ! V_54 )
return - V_16 ;
V_56 = F_36 ( V_11 , V_38 , V_35 , NULL ) ;
if ( ! V_56 )
return - V_18 ;
if ( ! strcmp ( V_11 , L_4 ) || ! strcmp ( V_11 , L_5 ) )
F_47 ( * ( int * ) V_35 ) ;
V_57 = F_44 ( V_2 , V_11 , NULL ) ;
if ( ! V_57 ) {
if ( strlen ( V_11 ) )
return F_42 ( V_2 , V_56 ) ;
return - V_48 ;
}
V_53 . V_47 = V_2 ;
V_53 . V_8 = V_56 ;
F_16 ( V_58 , & V_53 ) ;
V_55 = F_48 ( V_2 , V_56 , V_57 ) ;
if ( V_55 )
return V_55 ;
if ( ! strcmp ( V_11 , L_6 ) ) {
int V_22 ;
V_54 = F_34 ( V_54 , V_37 , & V_11 ,
& V_38 , & V_35 ) ;
if ( ! V_54 )
return - V_16 ;
if ( ! strcmp ( V_11 , L_7 ) )
V_22 = V_59 ;
else
V_22 = V_60 ;
V_55 = F_16 ( V_22 , V_35 ) ;
if ( V_55 ) {
F_48 ( V_2 , V_57 , V_56 ) ;
return V_55 ;
}
}
return 0 ;
}
static T_3 F_49 ( struct V_61 * V_61 , const char T_4 * V_36 , T_1 V_62 ,
T_5 * V_63 )
{
int V_45 = 0 ;
char * V_64 ;
char * V_39 ;
if ( ! ( V_64 = F_8 ( V_62 + 1 , V_17 ) ) ) {
V_45 = - V_18 ;
goto V_46;
}
if ( F_50 ( V_64 , V_36 , V_62 ) ) {
V_45 = - V_65 ;
goto V_46;
}
V_64 [ V_62 ] = '\0' ;
V_39 = strchr ( V_64 , ' ' ) ;
if ( ! V_39 ) {
V_45 = - V_16 ;
goto V_46;
}
* V_39 = '\0' ;
V_39 ++ ;
if ( ! strcmp ( V_64 , L_8 ) )
V_45 = F_37 ( V_39 , V_62 - ( V_39 - V_64 ) ) ;
else if ( ! strcmp ( V_64 , L_9 ) )
V_45 = F_38 ( V_39 ) ;
else if ( ! strcmp ( V_64 , L_10 ) )
V_45 = F_41 ( V_39 , V_62 - ( V_39 - V_64 ) ) ;
else if ( ! strcmp ( V_64 , L_11 ) )
V_45 = F_43 ( V_39 , V_62 - ( V_39 - V_64 ) ) ;
else if ( ! strcmp ( V_64 , L_12 ) )
V_45 = F_46 ( V_39 , V_62 - ( V_39 - V_64 ) ) ;
else
V_45 = - V_16 ;
V_46:
F_11 ( V_64 ) ;
return V_45 ? V_45 : V_62 ;
}
static int F_51 ( void )
{
struct V_3 * V_4 ;
if ( ! F_52 ( V_66 ) )
return 0 ;
V_4 = F_53 ( L_13 , V_67 , NULL , & V_68 ) ;
if ( V_4 )
V_4 -> V_69 = 0 ;
return 0 ;
}
