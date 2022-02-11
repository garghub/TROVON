static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 = NULL ;
char * V_4 = L_1 ;
T_1 V_5 = strrchr ( V_2 , '/' ) - V_2 + 1 ;
if ( ! strcmp ( V_2 , L_1 ) )
return F_2 ( - V_6 ) ;
if ( strrchr ( V_2 , '/' ) != V_2 ) {
V_4 = F_3 ( V_5 , V_7 ) ;
if ( ! V_4 )
return F_2 ( - V_8 ) ;
F_4 ( V_4 , V_2 , V_5 ) ;
}
V_3 = F_5 ( V_4 ) ;
if ( ! V_3 )
return F_2 ( - V_6 ) ;
if ( strcmp ( V_4 , L_1 ) )
F_6 ( V_4 ) ;
return V_3 ;
}
static int F_7 ( const char * V_2 , struct V_9 * V_10 )
{
struct V_1 * V_11 ;
int V_12 = - V_8 ;
V_11 = F_8 ( sizeof( * V_11 ) , V_7 ) ;
if ( ! V_11 )
goto V_13;
V_11 -> V_14 = F_9 ( V_2 , V_7 ) ;
if ( ! V_11 -> V_14 )
goto V_13;
V_11 -> V_15 = V_10 ;
F_10 ( V_11 , V_16 ) ;
F_11 ( & V_11 -> V_17 ) ;
V_11 -> V_3 = F_1 ( V_2 ) ;
if ( F_12 ( V_11 -> V_3 ) ) {
V_12 = F_13 ( V_11 -> V_3 ) ;
goto V_13;
}
V_12 = F_14 ( V_11 ) ;
if ( V_12 ) {
F_15 ( V_18 L_2 , V_2 ) ;
goto V_13;
}
F_16 ( V_11 -> V_3 ) ;
return 0 ;
V_13:
if ( V_11 ) {
F_16 ( V_11 -> V_3 ) ;
F_6 ( V_11 -> V_14 ) ;
F_6 ( V_11 ) ;
}
return V_12 ;
}
static int F_17 ( struct V_1 * V_11 )
{
struct V_1 * V_3 , * V_19 ;
V_3 = F_18 ( V_11 ) ;
if ( ! V_3 )
return - V_6 ;
if ( ( V_19 = F_19 ( V_11 , NULL ) ) ) {
F_16 ( V_19 ) ;
F_16 ( V_3 ) ;
return - V_20 ;
}
F_20 ( V_11 ) ;
F_16 ( V_3 ) ;
F_16 ( V_11 ) ;
return 0 ;
}
static void F_21 ( const struct V_9 * V_21 )
{
struct V_9 * V_22 ;
for (; V_21 ; V_21 = V_22 ) {
V_22 = V_21 -> V_22 ;
F_6 ( V_21 -> V_23 ) ;
F_6 ( V_21 -> V_24 ) ;
F_6 ( V_21 ) ;
}
}
static char * F_22 ( char * V_25 , char * V_26 , char * * V_23 , int * V_27 ,
unsigned char * * V_24 )
{
char * V_28 ;
* V_23 = V_25 ;
V_28 = strchr ( V_25 , ' ' ) ;
if ( ! V_28 ) {
F_15 ( V_18 L_3 ,
V_29 , __LINE__ ) ;
return NULL ;
}
* V_28 = '\0' ;
if ( ++ V_28 >= V_26 ) {
F_15 ( V_18 L_3 ,
V_29 , __LINE__ ) ;
return NULL ;
}
* V_27 = - 1 ;
* V_27 = F_23 ( V_28 , & V_28 , 10 ) ;
if ( * V_27 == - 1 ) {
F_15 ( V_18 L_3 ,
V_29 , __LINE__ ) ;
return NULL ;
}
if ( * V_28 != ' ' || ++ V_28 >= V_26 ) {
F_15 ( V_18 L_3 ,
V_29 , __LINE__ ) ;
return NULL ;
}
* V_24 = V_28 ;
V_28 += * V_27 ;
if ( V_28 > V_26 ) {
F_15 ( V_18 L_3 ,
V_29 , __LINE__ ) ;
return NULL ;
}
else if ( V_28 < V_26 && * V_28 != ' ' && * V_28 != '\0' ) {
F_15 ( V_18 L_3 ,
V_29 , __LINE__ ) ;
return NULL ;
}
V_28 ++ ;
return V_28 ;
}
static struct V_9 * F_24 ( const char * V_23 , const int V_27 ,
const unsigned char * V_24 , struct V_9 * V_30 )
{
struct V_9 * V_31 = F_8 ( sizeof( * V_31 ) , V_7 ) ;
if ( ! V_31 )
return NULL ;
if ( ! ( V_31 -> V_23 = F_9 ( V_23 , V_7 ) ) )
goto V_32;
if ( ! ( V_31 -> V_24 = F_3 ( V_27 + 1 , V_7 ) ) )
goto V_32;
memcpy ( V_31 -> V_24 , V_24 , V_27 ) ;
* ( ( ( char * ) V_31 -> V_24 ) + V_27 ) = 0 ;
V_31 -> V_27 = V_27 ;
V_31 -> V_22 = V_30 ;
return V_31 ;
V_32:
F_6 ( V_31 -> V_23 ) ;
F_6 ( V_31 -> V_24 ) ;
F_6 ( V_31 ) ;
return NULL ;
}
static int F_25 ( char * V_25 , T_1 V_33 )
{
char * V_2 , * V_26 , * V_23 ;
struct V_1 * V_11 ;
struct V_9 * V_21 = NULL ;
unsigned char * V_24 ;
int V_27 , V_34 = 0 ;
V_26 = V_25 + V_33 ;
V_2 = V_25 ;
V_25 = strchr ( V_25 , ' ' ) ;
if ( ! V_25 )
return - V_6 ;
* V_25 = '\0' ;
V_25 ++ ;
if ( ( V_11 = F_5 ( V_2 ) ) ) {
F_16 ( V_11 ) ;
return - V_6 ;
}
while ( V_25 < V_26 &&
( V_25 = F_22 ( V_25 , V_26 , & V_23 , & V_27 , & V_24 ) ) ) {
struct V_9 * V_30 = V_21 ;
V_21 = F_24 ( V_23 , V_27 , V_24 , V_30 ) ;
if ( ! V_21 ) {
V_34 = - V_8 ;
V_21 = V_30 ;
goto V_35;
}
}
if ( ! V_25 ) {
V_34 = - V_6 ;
goto V_35;
}
V_34 = F_7 ( V_2 , V_21 ) ;
V_35:
if ( V_34 )
F_21 ( V_21 ) ;
return V_34 ;
}
static int F_26 ( char * V_25 )
{
struct V_1 * V_36 ;
int V_34 = - V_37 ;
if ( ( V_36 = F_5 ( V_25 ) ) )
V_34 = F_17 ( V_36 ) ;
F_16 ( V_36 ) ;
return V_34 ;
}
static char * F_27 ( char * V_25 , T_1 V_33 , struct V_1 * * V_38 )
{
char * V_39 ;
T_2 V_40 ;
* V_38 = NULL ;
V_39 = V_25 ;
V_25 = strchr ( V_25 , ' ' ) ;
if ( ! V_25 )
return NULL ;
* V_25 = '\0' ;
V_25 ++ ;
V_40 = F_23 ( V_39 , NULL , 0 ) ;
* V_38 = F_28 ( V_40 ) ;
return V_25 ;
}
static int F_29 ( char * V_25 , T_1 V_33 )
{
struct V_9 * V_21 = NULL ;
struct V_1 * V_11 ;
unsigned char * V_24 ;
char * V_23 , * V_26 ;
int V_27 ;
V_26 = V_25 + V_33 ;
V_25 = F_27 ( V_25 , V_33 , & V_11 ) ;
if ( ! V_11 )
return - V_37 ;
if ( F_22 ( V_25 , V_26 , & V_23 , & V_27 , & V_24 ) == NULL )
return - V_6 ;
V_21 = F_24 ( V_23 , V_27 , V_24 , NULL ) ;
if ( ! V_21 )
return - V_8 ;
F_30 ( V_11 , V_21 ) ;
return 0 ;
}
static int F_31 ( char * V_25 , T_1 V_33 )
{
struct V_1 * V_11 ;
char * V_28 ;
struct V_9 * V_21 ;
V_25 = F_27 ( V_25 , V_33 , & V_11 ) ;
if ( ! V_11 )
return - V_37 ;
V_28 = strchr ( V_25 , ' ' ) ;
if ( V_28 )
* V_28 = '\0' ;
if ( strlen ( V_25 ) == 0 )
return - V_6 ;
V_21 = F_32 ( V_11 , V_25 , NULL ) ;
return F_33 ( V_11 , V_21 ) ;
}
static int F_34 ( char * V_25 , T_1 V_33 )
{
struct V_1 * V_11 ;
unsigned char * V_24 ;
char * V_23 , * V_26 , * V_41 ;
int V_27 ;
struct V_9 * V_42 ;
V_25 = F_27 ( V_25 , V_33 , & V_11 ) ;
V_26 = V_25 + V_33 ;
if ( ! V_11 )
return - V_37 ;
V_41 = F_22 ( V_25 , V_26 , & V_23 , & V_27 , & V_24 ) ;
if ( ! V_41 )
return - V_6 ;
if ( ! strlen ( V_23 ) )
return - V_37 ;
V_42 = F_24 ( V_23 , V_27 , V_24 , NULL ) ;
if ( ! V_42 )
return - V_8 ;
if ( ! strcmp ( V_23 , L_4 ) || ! strcmp ( V_23 , L_5 ) )
F_35 ( * ( int * ) V_24 ) ;
return F_36 ( V_11 , V_42 ) ;
}
static T_3 F_37 ( struct V_43 * V_43 , const char T_4 * V_25 , T_1 V_44 ,
T_5 * V_45 )
{
int V_34 = 0 ;
char * V_46 ;
char * V_28 ;
if ( ! ( V_46 = F_3 ( V_44 + 1 , V_7 ) ) ) {
V_34 = - V_8 ;
goto V_35;
}
if ( F_38 ( V_46 , V_25 , V_44 ) ) {
V_34 = - V_47 ;
goto V_35;
}
V_46 [ V_44 ] = '\0' ;
V_28 = strchr ( V_46 , ' ' ) ;
if ( ! V_28 ) {
V_34 = - V_6 ;
goto V_35;
}
* V_28 = '\0' ;
V_28 ++ ;
if ( ! strcmp ( V_46 , L_6 ) )
V_34 = F_25 ( V_28 , V_44 - ( V_28 - V_46 ) ) ;
else if ( ! strcmp ( V_46 , L_7 ) )
V_34 = F_26 ( V_28 ) ;
else if ( ! strcmp ( V_46 , L_8 ) )
V_34 = F_29 ( V_28 , V_44 - ( V_28 - V_46 ) ) ;
else if ( ! strcmp ( V_46 , L_9 ) )
V_34 = F_31 ( V_28 , V_44 - ( V_28 - V_46 ) ) ;
else if ( ! strcmp ( V_46 , L_10 ) )
V_34 = F_34 ( V_28 , V_44 - ( V_28 - V_46 ) ) ;
else
V_34 = - V_6 ;
V_35:
F_6 ( V_46 ) ;
return V_34 ? V_34 : V_44 ;
}
static int F_39 ( void )
{
struct V_48 * V_49 ;
if ( ! F_40 ( V_50 ) )
return 0 ;
V_49 = F_41 ( L_11 , V_51 , NULL , & V_52 ) ;
if ( V_49 )
F_42 ( V_49 , 0 ) ;
return 0 ;
}
