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
F_11 ( V_11 ) ;
V_11 -> V_3 = F_1 ( V_2 ) ;
if ( F_12 ( V_11 -> V_3 ) ) {
V_12 = F_13 ( V_11 -> V_3 ) ;
goto V_13;
}
V_12 = F_14 ( V_11 ) ;
if ( V_12 ) {
F_15 ( V_17 L_2 , V_2 ) ;
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
struct V_1 * V_3 , * V_18 ;
V_3 = F_18 ( V_11 ) ;
if ( ! V_3 )
return - V_6 ;
if ( ( V_18 = F_19 ( V_11 , NULL ) ) ) {
F_16 ( V_18 ) ;
F_16 ( V_3 ) ;
return - V_19 ;
}
F_20 ( V_11 ) ;
F_16 ( V_3 ) ;
F_16 ( V_11 ) ;
return 0 ;
}
static void F_21 ( const struct V_9 * V_20 )
{
struct V_9 * V_21 ;
for (; V_20 ; V_20 = V_21 ) {
V_21 = V_20 -> V_21 ;
F_6 ( V_20 -> V_22 ) ;
F_6 ( V_20 -> V_23 ) ;
F_6 ( V_20 ) ;
}
}
static char * F_22 ( char * V_24 , char * V_25 , char * * V_22 , int * V_26 ,
unsigned char * * V_23 )
{
char * V_27 ;
* V_22 = V_24 ;
V_27 = strchr ( V_24 , ' ' ) ;
if ( ! V_27 ) {
F_15 ( V_17 L_3 ,
V_28 , __LINE__ ) ;
return NULL ;
}
* V_27 = '\0' ;
if ( ++ V_27 >= V_25 ) {
F_15 ( V_17 L_3 ,
V_28 , __LINE__ ) ;
return NULL ;
}
* V_26 = - 1 ;
* V_26 = F_23 ( V_27 , & V_27 , 10 ) ;
if ( * V_26 == - 1 ) {
F_15 ( V_17 L_3 ,
V_28 , __LINE__ ) ;
return NULL ;
}
if ( * V_27 != ' ' || ++ V_27 >= V_25 ) {
F_15 ( V_17 L_3 ,
V_28 , __LINE__ ) ;
return NULL ;
}
* V_23 = V_27 ;
V_27 += * V_26 ;
if ( V_27 > V_25 ) {
F_15 ( V_17 L_3 ,
V_28 , __LINE__ ) ;
return NULL ;
}
else if ( V_27 < V_25 && * V_27 != ' ' && * V_27 != '\0' ) {
F_15 ( V_17 L_3 ,
V_28 , __LINE__ ) ;
return NULL ;
}
V_27 ++ ;
return V_27 ;
}
static struct V_9 * F_24 ( const char * V_22 , const int V_26 ,
const unsigned char * V_23 , struct V_9 * V_29 )
{
struct V_9 * V_30 = F_8 ( sizeof( * V_30 ) , V_7 ) ;
if ( ! V_30 )
return NULL ;
if ( ! ( V_30 -> V_22 = F_9 ( V_22 , V_7 ) ) )
goto V_31;
if ( ! ( V_30 -> V_23 = F_3 ( V_26 + 1 , V_7 ) ) )
goto V_31;
memcpy ( V_30 -> V_23 , V_23 , V_26 ) ;
* ( ( ( char * ) V_30 -> V_23 ) + V_26 ) = 0 ;
V_30 -> V_26 = V_26 ;
V_30 -> V_21 = V_29 ;
return V_30 ;
V_31:
F_6 ( V_30 -> V_22 ) ;
F_6 ( V_30 -> V_23 ) ;
F_6 ( V_30 ) ;
return NULL ;
}
static int F_25 ( char * V_24 , T_1 V_32 )
{
char * V_2 , * V_25 , * V_22 ;
struct V_1 * V_11 ;
struct V_9 * V_20 = NULL ;
unsigned char * V_23 ;
int V_26 , V_33 = 0 ;
V_25 = V_24 + V_32 ;
V_2 = V_24 ;
V_24 = strchr ( V_24 , ' ' ) ;
if ( ! V_24 )
return - V_6 ;
* V_24 = '\0' ;
V_24 ++ ;
if ( ( V_11 = F_5 ( V_2 ) ) ) {
F_16 ( V_11 ) ;
return - V_6 ;
}
while ( V_24 < V_25 &&
( V_24 = F_22 ( V_24 , V_25 , & V_22 , & V_26 , & V_23 ) ) ) {
struct V_9 * V_29 = V_20 ;
V_20 = F_24 ( V_22 , V_26 , V_23 , V_29 ) ;
if ( ! V_20 ) {
V_33 = - V_8 ;
V_20 = V_29 ;
goto V_34;
}
}
if ( ! V_24 ) {
V_33 = - V_6 ;
goto V_34;
}
V_33 = F_7 ( V_2 , V_20 ) ;
V_34:
if ( V_33 )
F_21 ( V_20 ) ;
return V_33 ;
}
static int F_26 ( char * V_24 )
{
struct V_1 * V_35 ;
int V_33 = - V_36 ;
if ( ( V_35 = F_5 ( V_24 ) ) )
V_33 = F_17 ( V_35 ) ;
F_16 ( V_35 ) ;
return V_33 ;
}
static char * F_27 ( char * V_24 , T_1 V_32 , struct V_1 * * V_37 )
{
char * V_38 ;
T_2 V_39 ;
* V_37 = NULL ;
V_38 = V_24 ;
V_24 = strchr ( V_24 , ' ' ) ;
if ( ! V_24 )
return NULL ;
* V_24 = '\0' ;
V_24 ++ ;
V_39 = F_23 ( V_38 , NULL , 0 ) ;
* V_37 = F_28 ( V_39 ) ;
return V_24 ;
}
static int F_29 ( char * V_24 , T_1 V_32 )
{
struct V_9 * V_20 = NULL ;
struct V_1 * V_11 ;
unsigned char * V_23 ;
char * V_22 , * V_25 ;
int V_26 ;
V_25 = V_24 + V_32 ;
V_24 = F_27 ( V_24 , V_32 , & V_11 ) ;
if ( ! V_11 )
return - V_36 ;
if ( F_22 ( V_24 , V_25 , & V_22 , & V_26 , & V_23 ) == NULL )
return - V_6 ;
V_20 = F_24 ( V_22 , V_26 , V_23 , NULL ) ;
if ( ! V_20 )
return - V_8 ;
F_30 ( V_11 , V_20 ) ;
return 0 ;
}
static int F_31 ( char * V_24 , T_1 V_32 )
{
struct V_1 * V_11 ;
char * V_27 ;
struct V_9 * V_20 ;
V_24 = F_27 ( V_24 , V_32 , & V_11 ) ;
if ( ! V_11 )
return - V_36 ;
V_27 = strchr ( V_24 , ' ' ) ;
if ( V_27 )
* V_27 = '\0' ;
if ( strlen ( V_24 ) == 0 )
return - V_6 ;
V_20 = F_32 ( V_11 , V_24 , NULL ) ;
return F_33 ( V_11 , V_20 ) ;
}
static int F_34 ( char * V_24 , T_1 V_32 )
{
struct V_1 * V_11 ;
unsigned char * V_23 ;
char * V_22 , * V_25 , * V_40 ;
int V_26 ;
struct V_9 * V_41 ;
V_24 = F_27 ( V_24 , V_32 , & V_11 ) ;
V_25 = V_24 + V_32 ;
if ( ! V_11 )
return - V_36 ;
V_40 = F_22 ( V_24 , V_25 , & V_22 , & V_26 , & V_23 ) ;
if ( ! V_40 )
return - V_6 ;
if ( ! strlen ( V_22 ) )
return - V_36 ;
V_41 = F_24 ( V_22 , V_26 , V_23 , NULL ) ;
if ( ! V_41 )
return - V_8 ;
if ( ! strcmp ( V_22 , L_4 ) || ! strcmp ( V_22 , L_5 ) )
F_35 ( * ( int * ) V_23 ) ;
return F_36 ( V_11 , V_41 ) ;
}
static T_3 F_37 ( struct V_42 * V_42 , const char T_4 * V_24 , T_1 V_43 ,
T_5 * V_44 )
{
int V_33 = 0 ;
char * V_45 ;
char * V_27 ;
if ( ! ( V_45 = F_3 ( V_43 + 1 , V_7 ) ) ) {
V_33 = - V_8 ;
goto V_34;
}
if ( F_38 ( V_45 , V_24 , V_43 ) ) {
V_33 = - V_46 ;
goto V_34;
}
V_45 [ V_43 ] = '\0' ;
V_27 = strchr ( V_45 , ' ' ) ;
if ( ! V_27 ) {
V_33 = - V_6 ;
goto V_34;
}
* V_27 = '\0' ;
V_27 ++ ;
if ( ! strcmp ( V_45 , L_6 ) )
V_33 = F_25 ( V_27 , V_43 - ( V_27 - V_45 ) ) ;
else if ( ! strcmp ( V_45 , L_7 ) )
V_33 = F_26 ( V_27 ) ;
else if ( ! strcmp ( V_45 , L_8 ) )
V_33 = F_29 ( V_27 , V_43 - ( V_27 - V_45 ) ) ;
else if ( ! strcmp ( V_45 , L_9 ) )
V_33 = F_31 ( V_27 , V_43 - ( V_27 - V_45 ) ) ;
else if ( ! strcmp ( V_45 , L_10 ) )
V_33 = F_34 ( V_27 , V_43 - ( V_27 - V_45 ) ) ;
else
V_33 = - V_6 ;
V_34:
F_6 ( V_45 ) ;
return V_33 ? V_33 : V_43 ;
}
static int F_39 ( void )
{
struct V_47 * V_48 ;
V_48 = F_40 ( L_11 , V_49 , NULL , & V_50 ) ;
if ( V_48 )
F_41 ( V_48 , 0 ) ;
return 0 ;
}
