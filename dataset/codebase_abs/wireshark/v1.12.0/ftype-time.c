static T_1
F_1 ( const T_2 * V_1 , const T_2 * V_2 )
{
return ( ( V_1 -> V_3 . time . V_4 ) == ( V_2 -> V_3 . time . V_4 ) )
&& ( ( V_1 -> V_3 . time . V_5 ) == ( V_2 -> V_3 . time . V_5 ) ) ;
}
static T_1
F_2 ( const T_2 * V_1 , const T_2 * V_2 )
{
return ( V_1 -> V_3 . time . V_4 != V_2 -> V_3 . time . V_4 )
|| ( V_1 -> V_3 . time . V_5 != V_2 -> V_3 . time . V_5 ) ;
}
static T_1
F_3 ( const T_2 * V_1 , const T_2 * V_2 )
{
if ( V_1 -> V_3 . time . V_4 > V_2 -> V_3 . time . V_4 ) {
return TRUE ;
}
if ( V_1 -> V_3 . time . V_4 < V_2 -> V_3 . time . V_4 ) {
return FALSE ;
}
return V_1 -> V_3 . time . V_5 > V_2 -> V_3 . time . V_5 ;
}
static T_1
F_4 ( const T_2 * V_1 , const T_2 * V_2 )
{
if ( V_1 -> V_3 . time . V_4 > V_2 -> V_3 . time . V_4 ) {
return TRUE ;
}
if ( V_1 -> V_3 . time . V_4 < V_2 -> V_3 . time . V_4 ) {
return FALSE ;
}
return V_1 -> V_3 . time . V_5 >= V_2 -> V_3 . time . V_5 ;
}
static T_1
F_5 ( const T_2 * V_1 , const T_2 * V_2 )
{
if ( V_1 -> V_3 . time . V_4 < V_2 -> V_3 . time . V_4 ) {
return TRUE ;
}
if ( V_1 -> V_3 . time . V_4 > V_2 -> V_3 . time . V_4 ) {
return FALSE ;
}
return V_1 -> V_3 . time . V_5 < V_2 -> V_3 . time . V_5 ;
}
static T_1
F_6 ( const T_2 * V_1 , const T_2 * V_2 )
{
if ( V_1 -> V_3 . time . V_4 < V_2 -> V_3 . time . V_4 ) {
return TRUE ;
}
if ( V_1 -> V_3 . time . V_4 > V_2 -> V_3 . time . V_4 ) {
return FALSE ;
}
return V_1 -> V_3 . time . V_5 <= V_2 -> V_3 . time . V_5 ;
}
static T_1
F_7 ( const char * V_6 , int * V_5 )
{
int V_7 ;
int V_8 ;
const char * V_9 ;
int V_10 ;
int V_11 ;
int V_12 ;
V_7 = ( int ) strlen ( V_6 ) ;
V_8 = 9 - V_7 ;
V_9 = V_6 + V_7 ;
V_10 = 0 ;
while ( V_9 != V_6 ) {
V_9 -- ;
if ( ! isdigit ( ( unsigned char ) * V_9 ) ) {
return FALSE ;
}
V_11 = * V_9 - '0' ;
if ( V_11 != 0 ) {
if ( V_8 < 0 )
return FALSE ;
for ( V_12 = 0 ; V_12 < V_8 ; V_12 ++ )
V_11 *= 10 ;
V_10 += V_11 ;
}
V_8 ++ ;
}
* V_5 = V_10 ;
return TRUE ;
}
static T_1
F_8 ( T_2 * V_13 , const char * V_14 , T_1 T_3 V_15 , T_4 V_16 )
{
const char * V_17 ;
char * V_18 ;
T_1 V_19 = FALSE ;
V_17 = V_14 ;
if( * V_17 == '-' ) {
V_19 = TRUE ;
V_17 ++ ;
}
if ( * V_17 != '.' ) {
V_13 -> V_3 . time . V_4 = strtoul ( V_17 , & V_18 , 10 ) ;
if ( V_18 == V_17 || ( * V_18 != '\0' && * V_18 != '.' ) )
goto V_20;
V_17 = V_18 ;
if ( * V_17 == '.' )
V_17 ++ ;
} else {
V_13 -> V_3 . time . V_4 = 0 ;
V_17 ++ ;
}
if ( * V_17 != '\0' ) {
if ( ! F_7 ( V_17 , & V_13 -> V_3 . time . V_5 ) )
goto V_20;
} else {
V_13 -> V_3 . time . V_5 = 0 ;
}
if( V_19 ) {
V_13 -> V_3 . time . V_4 = - V_13 -> V_3 . time . V_4 ;
V_13 -> V_3 . time . V_5 = - V_13 -> V_3 . time . V_5 ;
}
return TRUE ;
V_20:
if ( V_16 != NULL )
V_16 ( L_1 , V_14 ) ;
return FALSE ;
}
static T_1
F_9 ( T_2 * V_13 , const char * V_14 , T_4 V_16 )
{
struct V_21 V_21 ;
char * V_17 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_17 = strptime ( V_14 , L_2 , & V_21 ) ;
if ( V_17 == NULL )
V_17 = strptime ( V_14 , L_3 , & V_21 ) ;
if ( V_17 == NULL )
V_17 = strptime ( V_14 , L_4 , & V_21 ) ;
if ( V_17 == NULL )
V_17 = strptime ( V_14 , L_5 , & V_21 ) ;
if ( V_17 == NULL )
V_17 = strptime ( V_14 , L_6 , & V_21 ) ;
if ( V_17 == NULL )
V_17 = strptime ( V_14 , L_7 , & V_21 ) ;
if ( V_17 == NULL )
goto V_20;
V_21 . V_22 = - 1 ;
V_13 -> V_3 . time . V_4 = mktime ( & V_21 ) ;
if ( * V_17 != '\0' ) {
if ( * V_17 != '.' )
goto V_20;
V_17 ++ ;
if ( ! isdigit ( ( unsigned char ) * V_17 ) )
goto V_20;
if ( ! F_7 ( V_17 , & V_13 -> V_3 . time . V_5 ) )
goto V_20;
} else {
V_13 -> V_3 . time . V_5 = 0 ;
}
if ( V_13 -> V_3 . time . V_4 == - 1 ) {
goto V_20;
}
return TRUE ;
V_20:
if ( V_16 != NULL )
V_16 ( L_8 ,
V_14 ) ;
return FALSE ;
}
static T_1
F_10 ( T_2 * V_13 , const char * V_14 , T_1 T_3 V_15 , T_4 V_16 )
{
return F_9 ( V_13 , V_14 , V_16 ) ;
}
static void
F_11 ( T_2 * V_13 )
{
V_13 -> V_3 . time . V_4 = 0 ;
V_13 -> V_3 . time . V_5 = 0 ;
}
static void
F_12 ( T_2 * V_13 , const T_5 * V_3 )
{
V_13 -> V_3 . time = * V_3 ;
}
static T_6
F_13 ( T_2 * V_13 )
{
return & ( V_13 -> V_3 . time ) ;
}
static int
F_14 ( T_2 * V_13 , T_7 T_8 V_15 )
{
T_9 * V_23 ;
V_23 = F_15 ( & V_13 -> V_3 . time , V_24 ,
T_8 == V_25 ) ;
return ( int ) strlen ( V_23 ) + 2 ;
}
static void
F_16 ( T_2 * V_13 , T_7 T_8 V_15 , char * V_26 )
{
sprintf ( V_26 , L_9 ,
F_15 ( & V_13 -> V_3 . time , V_24 ,
T_8 == V_25 ) ) ;
}
static int
F_17 ( T_2 * V_13 , T_7 T_8 V_15 )
{
T_9 * V_23 ;
V_23 = F_18 ( & V_13 -> V_3 . time ) ;
return ( int ) strlen ( V_23 ) ;
}
static void
F_19 ( T_2 * V_13 , T_7 T_8 V_15 , char * V_26 )
{
strcpy ( V_26 , F_18 ( & V_13 -> V_3 . time ) ) ;
}
void
F_20 ( void )
{
static T_10 V_27 = {
V_28 ,
L_10 ,
L_11 ,
0 ,
F_11 ,
NULL ,
F_10 ,
F_9 ,
F_16 ,
F_14 ,
NULL ,
NULL ,
NULL ,
F_12 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_13 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_1 ,
F_2 ,
F_3 ,
F_4 ,
F_5 ,
F_6 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL
} ;
static T_10 V_29 = {
V_30 ,
L_12 ,
L_13 ,
0 ,
F_11 ,
NULL ,
F_8 ,
NULL ,
F_19 ,
F_17 ,
NULL ,
NULL ,
NULL ,
F_12 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_13 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_1 ,
F_2 ,
F_3 ,
F_4 ,
F_5 ,
F_6 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL
} ;
F_21 ( V_28 , & V_27 ) ;
F_21 ( V_30 , & V_29 ) ;
}
