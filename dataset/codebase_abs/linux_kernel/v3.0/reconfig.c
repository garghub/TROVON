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
static int F_16 ( const char * V_13 , struct V_8 * V_22 )
{
struct V_1 * V_2 ;
int V_23 = - V_18 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_17 ) ;
if ( ! V_2 )
goto V_24;
V_2 -> V_5 = F_18 ( V_13 , V_17 ) ;
if ( ! V_2 -> V_5 )
goto V_24;
V_2 -> V_10 = V_22 ;
F_19 ( V_2 , V_25 ) ;
F_20 ( & V_2 -> V_26 ) ;
V_2 -> V_6 = F_6 ( V_13 ) ;
if ( F_21 ( V_2 -> V_6 ) ) {
V_23 = F_22 ( V_2 -> V_6 ) ;
goto V_24;
}
V_23 = F_23 ( & V_21 ,
V_27 , V_2 ) ;
if ( V_23 == V_28 ) {
F_24 ( V_29 L_2 , V_13 ) ;
V_23 = - V_18 ;
goto V_24;
}
F_25 ( V_2 ) ;
F_1 ( V_2 ) ;
F_26 ( V_2 -> V_6 ) ;
return 0 ;
V_24:
if ( V_2 ) {
F_26 ( V_2 -> V_6 ) ;
F_11 ( V_2 -> V_5 ) ;
F_11 ( V_2 ) ;
}
return V_23 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_1 * V_6 , * V_30 ;
V_6 = F_28 ( V_2 ) ;
if ( ! V_6 )
return - V_16 ;
if ( ( V_30 = F_29 ( V_2 , NULL ) ) ) {
F_26 ( V_30 ) ;
F_26 ( V_6 ) ;
return - V_31 ;
}
F_4 ( V_2 ) ;
F_23 ( & V_21 ,
V_32 , V_2 ) ;
F_30 ( V_2 ) ;
F_26 ( V_6 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static void F_31 ( const struct V_8 * V_33 )
{
struct V_8 * V_12 ;
for (; V_33 ; V_33 = V_12 ) {
V_12 = V_33 -> V_12 ;
F_11 ( V_33 -> V_11 ) ;
F_11 ( V_33 -> V_34 ) ;
F_11 ( V_33 ) ;
}
}
static char * F_32 ( char * V_35 , char * V_36 , char * * V_11 , int * V_37 ,
unsigned char * * V_34 )
{
char * V_38 ;
* V_11 = V_35 ;
V_38 = strchr ( V_35 , ' ' ) ;
if ( ! V_38 ) {
F_24 ( V_29 L_3 ,
V_39 , __LINE__ ) ;
return NULL ;
}
* V_38 = '\0' ;
if ( ++ V_38 >= V_36 ) {
F_24 ( V_29 L_3 ,
V_39 , __LINE__ ) ;
return NULL ;
}
* V_37 = - 1 ;
* V_37 = F_33 ( V_38 , & V_38 , 10 ) ;
if ( * V_37 == - 1 ) {
F_24 ( V_29 L_3 ,
V_39 , __LINE__ ) ;
return NULL ;
}
if ( * V_38 != ' ' || ++ V_38 >= V_36 ) {
F_24 ( V_29 L_3 ,
V_39 , __LINE__ ) ;
return NULL ;
}
* V_34 = V_38 ;
V_38 += * V_37 ;
if ( V_38 > V_36 ) {
F_24 ( V_29 L_3 ,
V_39 , __LINE__ ) ;
return NULL ;
}
else if ( V_38 < V_36 && * V_38 != ' ' && * V_38 != '\0' ) {
F_24 ( V_29 L_3 ,
V_39 , __LINE__ ) ;
return NULL ;
}
V_38 ++ ;
return V_38 ;
}
static struct V_8 * F_34 ( const char * V_11 , const int V_37 ,
const unsigned char * V_34 , struct V_8 * V_40 )
{
struct V_8 * V_41 = F_17 ( sizeof( * V_41 ) , V_17 ) ;
if ( ! V_41 )
return NULL ;
if ( ! ( V_41 -> V_11 = F_8 ( strlen ( V_11 ) + 1 , V_17 ) ) )
goto V_42;
if ( ! ( V_41 -> V_34 = F_8 ( V_37 + 1 , V_17 ) ) )
goto V_42;
strcpy ( V_41 -> V_11 , V_11 ) ;
memcpy ( V_41 -> V_34 , V_34 , V_37 ) ;
* ( ( ( char * ) V_41 -> V_34 ) + V_37 ) = 0 ;
V_41 -> V_37 = V_37 ;
V_41 -> V_12 = V_40 ;
return V_41 ;
V_42:
F_11 ( V_41 -> V_11 ) ;
F_11 ( V_41 -> V_34 ) ;
F_11 ( V_41 ) ;
return NULL ;
}
static int F_35 ( char * V_35 , T_1 V_43 )
{
char * V_13 , * V_36 , * V_11 ;
struct V_1 * V_2 ;
struct V_8 * V_33 = NULL ;
unsigned char * V_34 ;
int V_37 , V_44 = 0 ;
V_36 = V_35 + V_43 ;
V_13 = V_35 ;
V_35 = strchr ( V_35 , ' ' ) ;
if ( ! V_35 )
return - V_16 ;
* V_35 = '\0' ;
V_35 ++ ;
if ( ( V_2 = F_10 ( V_13 ) ) ) {
F_26 ( V_2 ) ;
return - V_16 ;
}
while ( V_35 < V_36 &&
( V_35 = F_32 ( V_35 , V_36 , & V_11 , & V_37 , & V_34 ) ) ) {
struct V_8 * V_40 = V_33 ;
V_33 = F_34 ( V_11 , V_37 , V_34 , V_40 ) ;
if ( ! V_33 ) {
V_44 = - V_18 ;
V_33 = V_40 ;
goto V_45;
}
}
if ( ! V_35 ) {
V_44 = - V_16 ;
goto V_45;
}
V_44 = F_16 ( V_13 , V_33 ) ;
V_45:
if ( V_44 )
F_31 ( V_33 ) ;
return V_44 ;
}
static int F_36 ( char * V_35 )
{
struct V_1 * V_46 ;
int V_44 = - V_47 ;
if ( ( V_46 = F_10 ( V_35 ) ) )
V_44 = F_27 ( V_46 ) ;
F_26 ( V_46 ) ;
return V_44 ;
}
static char * F_37 ( char * V_35 , T_1 V_43 , struct V_1 * * V_48 )
{
char * V_49 ;
T_2 V_50 ;
* V_48 = NULL ;
V_49 = V_35 ;
V_35 = strchr ( V_35 , ' ' ) ;
if ( ! V_35 )
return NULL ;
* V_35 = '\0' ;
V_35 ++ ;
V_50 = F_33 ( V_49 , NULL , 0 ) ;
* V_48 = F_38 ( V_50 ) ;
return V_35 ;
}
static int F_39 ( char * V_35 , T_1 V_43 )
{
struct V_8 * V_33 = NULL ;
struct V_1 * V_2 ;
unsigned char * V_34 ;
char * V_11 , * V_36 ;
int V_37 ;
V_36 = V_35 + V_43 ;
V_35 = F_37 ( V_35 , V_43 , & V_2 ) ;
if ( ! V_2 )
return - V_47 ;
if ( F_32 ( V_35 , V_36 , & V_11 , & V_37 , & V_34 ) == NULL )
return - V_16 ;
V_33 = F_34 ( V_11 , V_37 , V_34 , NULL ) ;
if ( ! V_33 )
return - V_18 ;
F_40 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_41 ( char * V_35 , T_1 V_43 )
{
struct V_1 * V_2 ;
char * V_38 ;
struct V_8 * V_33 ;
V_35 = F_37 ( V_35 , V_43 , & V_2 ) ;
if ( ! V_2 )
return - V_47 ;
V_38 = strchr ( V_35 , ' ' ) ;
if ( V_38 )
* V_38 = '\0' ;
if ( strlen ( V_35 ) == 0 )
return - V_16 ;
V_33 = F_42 ( V_2 , V_35 , NULL ) ;
return F_43 ( V_2 , V_33 ) ;
}
static int F_44 ( char * V_35 , T_1 V_43 )
{
struct V_1 * V_2 ;
unsigned char * V_34 ;
char * V_11 , * V_36 , * V_51 ;
int V_52 , V_37 ;
struct V_8 * V_53 , * V_54 ;
V_35 = F_37 ( V_35 , V_43 , & V_2 ) ;
V_36 = V_35 + V_43 ;
if ( ! V_2 )
return - V_47 ;
V_51 = F_32 ( V_35 , V_36 , & V_11 , & V_37 , & V_34 ) ;
if ( ! V_51 )
return - V_16 ;
V_53 = F_34 ( V_11 , V_37 , V_34 , NULL ) ;
if ( ! V_53 )
return - V_18 ;
if ( ! strcmp ( V_11 , L_4 ) || ! strcmp ( V_11 , L_5 ) )
F_45 ( * ( int * ) V_34 ) ;
V_54 = F_42 ( V_2 , V_11 , NULL ) ;
if ( ! V_54 ) {
if ( strlen ( V_11 ) )
return F_40 ( V_2 , V_53 ) ;
return - V_47 ;
}
V_52 = F_46 ( V_2 , V_53 , V_54 ) ;
if ( V_52 )
return V_52 ;
if ( ! strcmp ( V_11 , L_6 ) ) {
int V_55 ;
V_51 = F_32 ( V_51 , V_36 , & V_11 ,
& V_37 , & V_34 ) ;
if ( ! V_51 )
return - V_16 ;
if ( ! strcmp ( V_11 , L_7 ) )
V_55 = V_56 ;
else
V_55 = V_57 ;
V_52 = F_23 ( & V_21 ,
V_55 , V_34 ) ;
if ( V_52 == V_28 ) {
V_52 = F_46 ( V_2 , V_54 , V_53 ) ;
return - V_18 ;
}
}
return 0 ;
}
static T_3 F_47 ( struct V_58 * V_58 , const char T_4 * V_35 , T_1 V_59 ,
T_5 * V_60 )
{
int V_44 = 0 ;
char * V_61 ;
char * V_38 ;
if ( ! ( V_61 = F_8 ( V_59 + 1 , V_17 ) ) ) {
V_44 = - V_18 ;
goto V_45;
}
if ( F_48 ( V_61 , V_35 , V_59 ) ) {
V_44 = - V_62 ;
goto V_45;
}
V_61 [ V_59 ] = '\0' ;
V_38 = strchr ( V_61 , ' ' ) ;
if ( ! V_38 ) {
V_44 = - V_16 ;
goto V_45;
}
* V_38 = '\0' ;
V_38 ++ ;
if ( ! strcmp ( V_61 , L_8 ) )
V_44 = F_35 ( V_38 , V_59 - ( V_38 - V_61 ) ) ;
else if ( ! strcmp ( V_61 , L_9 ) )
V_44 = F_36 ( V_38 ) ;
else if ( ! strcmp ( V_61 , L_10 ) )
V_44 = F_39 ( V_38 , V_59 - ( V_38 - V_61 ) ) ;
else if ( ! strcmp ( V_61 , L_11 ) )
V_44 = F_41 ( V_38 , V_59 - ( V_38 - V_61 ) ) ;
else if ( ! strcmp ( V_61 , L_12 ) )
V_44 = F_44 ( V_38 , V_59 - ( V_38 - V_61 ) ) ;
else
V_44 = - V_16 ;
V_45:
F_11 ( V_61 ) ;
return V_44 ? V_44 : V_59 ;
}
static int F_49 ( void )
{
struct V_3 * V_4 ;
if ( ! F_50 ( V_63 ) )
return 0 ;
V_4 = F_51 ( L_13 , V_64 , NULL , & V_65 ) ;
if ( V_4 )
V_4 -> V_66 = 0 ;
return 0 ;
}
