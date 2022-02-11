static int F_1 ( const char * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int V_6 = - V_7 ;
V_5 = F_2 ( sizeof( * V_5 ) , V_8 ) ;
if ( ! V_5 )
goto V_9;
V_5 -> V_10 = F_3 ( V_1 , V_8 ) ;
if ( ! V_5 -> V_10 )
goto V_9;
V_5 -> V_11 = V_3 ;
F_4 ( V_5 , V_12 ) ;
F_5 ( V_5 ) ;
V_5 -> V_13 = F_6 ( V_1 ) ;
if ( F_7 ( V_5 -> V_13 ) ) {
V_6 = F_8 ( V_5 -> V_13 ) ;
goto V_9;
}
V_6 = F_9 ( V_5 ) ;
if ( V_6 ) {
F_10 ( V_14 L_1 , V_1 ) ;
goto V_9;
}
F_11 ( V_5 -> V_13 ) ;
return 0 ;
V_9:
if ( V_5 ) {
F_11 ( V_5 -> V_13 ) ;
F_12 ( V_5 -> V_10 ) ;
F_12 ( V_5 ) ;
}
return V_6 ;
}
static int F_13 ( struct V_4 * V_5 )
{
struct V_4 * V_13 , * V_15 ;
V_13 = F_14 ( V_5 ) ;
if ( ! V_13 )
return - V_16 ;
if ( ( V_15 = F_15 ( V_5 , NULL ) ) ) {
F_11 ( V_15 ) ;
F_11 ( V_13 ) ;
return - V_17 ;
}
F_16 ( V_5 ) ;
F_11 ( V_13 ) ;
F_11 ( V_5 ) ;
return 0 ;
}
static void F_17 ( const struct V_2 * V_18 )
{
struct V_2 * V_19 ;
for (; V_18 ; V_18 = V_19 ) {
V_19 = V_18 -> V_19 ;
F_12 ( V_18 -> V_20 ) ;
F_12 ( V_18 -> V_21 ) ;
F_12 ( V_18 ) ;
}
}
static char * F_18 ( char * V_22 , char * V_23 , char * * V_20 , int * V_24 ,
unsigned char * * V_21 )
{
char * V_25 ;
* V_20 = V_22 ;
V_25 = strchr ( V_22 , ' ' ) ;
if ( ! V_25 ) {
F_10 ( V_14 L_2 ,
V_26 , __LINE__ ) ;
return NULL ;
}
* V_25 = '\0' ;
if ( ++ V_25 >= V_23 ) {
F_10 ( V_14 L_2 ,
V_26 , __LINE__ ) ;
return NULL ;
}
* V_24 = - 1 ;
* V_24 = F_19 ( V_25 , & V_25 , 10 ) ;
if ( * V_24 == - 1 ) {
F_10 ( V_14 L_2 ,
V_26 , __LINE__ ) ;
return NULL ;
}
if ( * V_25 != ' ' || ++ V_25 >= V_23 ) {
F_10 ( V_14 L_2 ,
V_26 , __LINE__ ) ;
return NULL ;
}
* V_21 = V_25 ;
V_25 += * V_24 ;
if ( V_25 > V_23 ) {
F_10 ( V_14 L_2 ,
V_26 , __LINE__ ) ;
return NULL ;
}
else if ( V_25 < V_23 && * V_25 != ' ' && * V_25 != '\0' ) {
F_10 ( V_14 L_2 ,
V_26 , __LINE__ ) ;
return NULL ;
}
V_25 ++ ;
return V_25 ;
}
static struct V_2 * F_20 ( const char * V_20 , const int V_24 ,
const unsigned char * V_21 , struct V_2 * V_27 )
{
struct V_2 * V_28 = F_2 ( sizeof( * V_28 ) , V_8 ) ;
if ( ! V_28 )
return NULL ;
if ( ! ( V_28 -> V_20 = F_3 ( V_20 , V_8 ) ) )
goto V_29;
if ( ! ( V_28 -> V_21 = F_21 ( V_24 + 1 , V_8 ) ) )
goto V_29;
memcpy ( V_28 -> V_21 , V_21 , V_24 ) ;
* ( ( ( char * ) V_28 -> V_21 ) + V_24 ) = 0 ;
V_28 -> V_24 = V_24 ;
V_28 -> V_19 = V_27 ;
return V_28 ;
V_29:
F_12 ( V_28 -> V_20 ) ;
F_12 ( V_28 -> V_21 ) ;
F_12 ( V_28 ) ;
return NULL ;
}
static int F_22 ( char * V_22 , T_1 V_30 )
{
char * V_1 , * V_23 , * V_20 ;
struct V_4 * V_5 ;
struct V_2 * V_18 = NULL ;
unsigned char * V_21 ;
int V_24 , V_31 = 0 ;
V_23 = V_22 + V_30 ;
V_1 = V_22 ;
V_22 = strchr ( V_22 , ' ' ) ;
if ( ! V_22 )
return - V_16 ;
* V_22 = '\0' ;
V_22 ++ ;
if ( ( V_5 = F_23 ( V_1 ) ) ) {
F_11 ( V_5 ) ;
return - V_16 ;
}
while ( V_22 < V_23 &&
( V_22 = F_18 ( V_22 , V_23 , & V_20 , & V_24 , & V_21 ) ) ) {
struct V_2 * V_27 = V_18 ;
V_18 = F_20 ( V_20 , V_24 , V_21 , V_27 ) ;
if ( ! V_18 ) {
V_31 = - V_7 ;
V_18 = V_27 ;
goto V_32;
}
}
if ( ! V_22 ) {
V_31 = - V_16 ;
goto V_32;
}
V_31 = F_1 ( V_1 , V_18 ) ;
V_32:
if ( V_31 )
F_17 ( V_18 ) ;
return V_31 ;
}
static int F_24 ( char * V_22 )
{
struct V_4 * V_33 ;
int V_31 = - V_34 ;
if ( ( V_33 = F_23 ( V_22 ) ) )
V_31 = F_13 ( V_33 ) ;
F_11 ( V_33 ) ;
return V_31 ;
}
static char * F_25 ( char * V_22 , T_1 V_30 , struct V_4 * * V_35 )
{
char * V_36 ;
T_2 V_37 ;
* V_35 = NULL ;
V_36 = V_22 ;
V_22 = strchr ( V_22 , ' ' ) ;
if ( ! V_22 )
return NULL ;
* V_22 = '\0' ;
V_22 ++ ;
V_37 = F_19 ( V_36 , NULL , 0 ) ;
* V_35 = F_26 ( V_37 ) ;
return V_22 ;
}
static int F_27 ( char * V_22 , T_1 V_30 )
{
struct V_2 * V_18 = NULL ;
struct V_4 * V_5 ;
unsigned char * V_21 ;
char * V_20 , * V_23 ;
int V_24 ;
V_23 = V_22 + V_30 ;
V_22 = F_25 ( V_22 , V_30 , & V_5 ) ;
if ( ! V_5 )
return - V_34 ;
if ( F_18 ( V_22 , V_23 , & V_20 , & V_24 , & V_21 ) == NULL )
return - V_16 ;
V_18 = F_20 ( V_20 , V_24 , V_21 , NULL ) ;
if ( ! V_18 )
return - V_7 ;
F_28 ( V_5 , V_18 ) ;
return 0 ;
}
static int F_29 ( char * V_22 , T_1 V_30 )
{
struct V_4 * V_5 ;
char * V_25 ;
V_22 = F_25 ( V_22 , V_30 , & V_5 ) ;
if ( ! V_5 )
return - V_34 ;
V_25 = strchr ( V_22 , ' ' ) ;
if ( V_25 )
* V_25 = '\0' ;
if ( strlen ( V_22 ) == 0 )
return - V_16 ;
return F_30 ( V_5 , F_31 ( V_5 , V_22 , NULL ) ) ;
}
static int F_32 ( char * V_22 , T_1 V_30 )
{
struct V_4 * V_5 ;
unsigned char * V_21 ;
char * V_20 , * V_23 , * V_38 ;
int V_24 ;
struct V_2 * V_39 ;
V_22 = F_25 ( V_22 , V_30 , & V_5 ) ;
V_23 = V_22 + V_30 ;
if ( ! V_5 )
return - V_34 ;
V_38 = F_18 ( V_22 , V_23 , & V_20 , & V_24 , & V_21 ) ;
if ( ! V_38 )
return - V_16 ;
if ( ! strlen ( V_20 ) )
return - V_34 ;
V_39 = F_20 ( V_20 , V_24 , V_21 , NULL ) ;
if ( ! V_39 )
return - V_7 ;
if ( ! strcmp ( V_20 , L_3 ) || ! strcmp ( V_20 , L_4 ) )
F_33 ( * ( int * ) V_21 ) ;
return F_34 ( V_5 , V_39 ) ;
}
static T_3 F_35 ( struct V_40 * V_40 , const char T_4 * V_22 , T_1 V_41 ,
T_5 * V_42 )
{
int V_31 = 0 ;
char * V_43 ;
char * V_25 ;
if ( ! ( V_43 = F_21 ( V_41 + 1 , V_8 ) ) ) {
V_31 = - V_7 ;
goto V_32;
}
if ( F_36 ( V_43 , V_22 , V_41 ) ) {
V_31 = - V_44 ;
goto V_32;
}
V_43 [ V_41 ] = '\0' ;
V_25 = strchr ( V_43 , ' ' ) ;
if ( ! V_25 ) {
V_31 = - V_16 ;
goto V_32;
}
* V_25 = '\0' ;
V_25 ++ ;
if ( ! strcmp ( V_43 , L_5 ) )
V_31 = F_22 ( V_25 , V_41 - ( V_25 - V_43 ) ) ;
else if ( ! strcmp ( V_43 , L_6 ) )
V_31 = F_24 ( V_25 ) ;
else if ( ! strcmp ( V_43 , L_7 ) )
V_31 = F_27 ( V_25 , V_41 - ( V_25 - V_43 ) ) ;
else if ( ! strcmp ( V_43 , L_8 ) )
V_31 = F_29 ( V_25 , V_41 - ( V_25 - V_43 ) ) ;
else if ( ! strcmp ( V_43 , L_9 ) )
V_31 = F_32 ( V_25 , V_41 - ( V_25 - V_43 ) ) ;
else
V_31 = - V_16 ;
V_32:
F_12 ( V_43 ) ;
return V_31 ? V_31 : V_41 ;
}
static int F_37 ( void )
{
struct V_45 * V_46 ;
V_46 = F_38 ( L_10 , V_47 , NULL , & V_48 ) ;
if ( V_46 )
F_39 ( V_46 , 0 ) ;
return 0 ;
}
