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
F_14 ( T_2 * V_13 , T_7 V_23 )
{
T_8 * V_24 ;
int V_25 ;
V_24 = F_15 ( NULL , & V_13 -> V_3 . time , V_26 ,
V_23 == V_27 ) ;
V_25 = ( int ) strlen ( V_24 ) + ( ( V_23 == V_28 ) ? 2 : 0 ) ;
F_16 ( NULL , V_24 ) ;
return V_25 ;
}
static void
F_17 ( T_2 * V_13 , T_7 V_23 , char * V_29 )
{
T_8 * V_24 = F_15 ( NULL , & V_13 -> V_3 . time , V_26 ,
V_23 == V_27 ) ;
if ( V_23 == V_28 ) {
sprintf ( V_29 , L_9 , V_24 ) ;
} else {
strcpy ( V_29 , V_24 ) ;
}
F_16 ( NULL , V_24 ) ;
}
static int
F_18 ( T_2 * V_13 , T_7 V_23 V_15 )
{
T_8 * V_24 ;
int V_25 ;
V_24 = F_19 ( NULL , & V_13 -> V_3 . time ) ;
V_25 = ( int ) strlen ( V_24 ) ;
F_16 ( NULL , V_24 ) ;
return V_25 ;
}
static void
F_20 ( T_2 * V_13 , T_7 V_23 V_15 , char * V_29 )
{
T_8 * V_24 ;
V_24 = F_19 ( NULL , & V_13 -> V_3 . time ) ;
strcpy ( V_29 , V_24 ) ;
F_16 ( NULL , V_24 ) ;
}
void
F_21 ( void )
{
static T_9 V_30 = {
V_31 ,
L_10 ,
L_11 ,
0 ,
F_11 ,
NULL ,
F_10 ,
F_9 ,
F_17 ,
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
static T_9 V_32 = {
V_33 ,
L_12 ,
L_13 ,
0 ,
F_11 ,
NULL ,
F_8 ,
NULL ,
F_20 ,
F_18 ,
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
F_22 ( V_31 , & V_30 ) ;
F_22 ( V_33 , & V_32 ) ;
}
