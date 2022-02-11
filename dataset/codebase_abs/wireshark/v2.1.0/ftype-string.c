static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . string = NULL ;
}
static void
F_2 ( T_1 * V_1 )
{
F_3 ( V_1 -> V_2 . string ) ;
}
static void
F_4 ( T_1 * V_1 , const T_2 * V_2 )
{
F_5 ( V_2 != NULL ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . string = ( T_2 * ) F_6 ( V_2 ) ;
}
static int
F_7 ( T_1 * V_1 , T_3 V_3 , int T_4 V_4 )
{
switch ( V_3 ) {
case V_5 :
return ( int ) strlen ( V_1 -> V_2 . string ) ;
case V_6 :
return F_8 ( V_1 -> V_2 . string ) ;
}
F_9 () ;
return - 1 ;
}
static void
F_10 ( T_1 * V_1 , T_3 V_3 , int T_4 V_4 , char * V_7 , unsigned int V_8 )
{
switch ( V_3 ) {
case V_5 :
F_11 ( V_7 , V_1 -> V_2 . string , V_8 ) ;
return;
case V_6 :
F_12 ( V_7 , V_1 -> V_2 . string ) ;
return;
}
F_9 () ;
}
static T_5
F_13 ( T_1 * V_1 )
{
return V_1 -> V_2 . string ;
}
static T_6
F_14 ( T_1 * V_1 , const char * V_9 , T_2 * * T_7 V_4 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . string = F_6 ( V_9 ) ;
return TRUE ;
}
static T_6
F_15 ( T_1 * V_1 , const char * V_9 , T_6 T_8 V_4 , T_2 * * T_7 )
{
T_1 * V_10 ;
F_2 ( V_1 ) ;
V_10 = F_16 ( V_11 , V_9 , TRUE , NULL ) ;
if ( V_10 ) {
int V_12 = V_10 -> V_2 . V_13 -> V_14 ;
V_1 -> V_2 . string = ( T_2 * ) F_17 ( V_12 + 1 ) ;
memcpy ( V_1 -> V_2 . string , V_10 -> V_2 . V_13 -> V_15 , V_12 ) ;
V_1 -> V_2 . string [ V_12 ] = '\0' ;
F_18 ( V_10 ) ;
return TRUE ;
}
return F_14 ( V_1 , V_9 , T_7 ) ;
}
static T_9
V_14 ( T_1 * V_1 )
{
return ( T_9 ) strlen ( V_1 -> V_2 . string ) ;
}
static void
F_19 ( T_1 * V_1 , T_10 * V_13 , T_9 V_16 , T_9 V_17 )
{
T_11 * V_15 ;
V_15 = V_1 -> V_2 . V_18 + V_16 ;
F_20 ( V_13 , V_15 , V_17 ) ;
}
static T_6
F_21 ( const T_1 * V_19 , const T_1 * V_20 )
{
return ( strcmp ( V_19 -> V_2 . string , V_20 -> V_2 . string ) == 0 ) ;
}
static T_6
F_22 ( const T_1 * V_19 , const T_1 * V_20 )
{
return ( strcmp ( V_19 -> V_2 . string , V_20 -> V_2 . string ) != 0 ) ;
}
static T_6
F_23 ( const T_1 * V_19 , const T_1 * V_20 )
{
return ( strcmp ( V_19 -> V_2 . string , V_20 -> V_2 . string ) > 0 ) ;
}
static T_6
F_24 ( const T_1 * V_19 , const T_1 * V_20 )
{
return ( strcmp ( V_19 -> V_2 . string , V_20 -> V_2 . string ) >= 0 ) ;
}
static T_6
F_25 ( const T_1 * V_19 , const T_1 * V_20 )
{
return ( strcmp ( V_19 -> V_2 . string , V_20 -> V_2 . string ) < 0 ) ;
}
static T_6
F_26 ( const T_1 * V_19 , const T_1 * V_20 )
{
return ( strcmp ( V_19 -> V_2 . string , V_20 -> V_2 . string ) <= 0 ) ;
}
static T_6
F_27 ( const T_1 * V_21 , const T_1 * V_22 )
{
if ( strlen ( V_22 -> V_2 . string ) == 0 ) {
return FALSE ;
}
if ( strstr ( V_21 -> V_2 . string , V_22 -> V_2 . string ) ) {
return TRUE ;
}
else {
return FALSE ;
}
}
static T_6
F_28 ( const T_1 * V_21 , const T_1 * V_22 )
{
char * V_23 = V_21 -> V_2 . string ;
T_12 * V_24 = V_22 -> V_2 . V_25 ;
if ( strcmp ( V_22 -> V_26 -> V_27 , L_1 ) != 0 ) {
return FALSE ;
}
if ( ! V_24 ) {
return FALSE ;
}
return F_29 (
V_24 ,
V_23 ,
( int ) strlen ( V_23 ) ,
0 ,
( V_28 ) 0 ,
NULL ,
NULL
) ;
}
void
F_30 ( void )
{
static T_13 V_29 = {
V_30 ,
L_2 ,
L_3 ,
0 ,
F_1 ,
F_2 ,
F_15 ,
F_14 ,
F_10 ,
F_7 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_4 ,
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
NULL ,
F_21 ,
F_22 ,
F_23 ,
F_24 ,
F_25 ,
F_26 ,
NULL ,
F_27 ,
V_31 ,
V_14 ,
F_19 ,
} ;
static T_13 V_32 = {
V_33 ,
L_4 ,
L_3 ,
0 ,
F_1 ,
F_2 ,
F_15 ,
F_14 ,
F_10 ,
F_7 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_4 ,
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
NULL ,
F_21 ,
F_22 ,
F_23 ,
F_24 ,
F_25 ,
F_26 ,
NULL ,
F_27 ,
V_31 ,
V_14 ,
F_19 ,
} ;
static T_13 V_34 = {
V_35 ,
L_5 ,
L_3 ,
0 ,
F_1 ,
F_2 ,
F_15 ,
F_14 ,
F_10 ,
F_7 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_4 ,
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
NULL ,
F_21 ,
F_22 ,
F_23 ,
F_24 ,
F_25 ,
F_26 ,
NULL ,
F_27 ,
V_31 ,
V_14 ,
F_19 ,
} ;
static T_13 V_36 = {
V_37 ,
L_6 ,
L_3 ,
0 ,
F_1 ,
F_2 ,
F_15 ,
F_14 ,
F_10 ,
F_7 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_4 ,
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
NULL ,
F_21 ,
F_22 ,
F_23 ,
F_24 ,
F_25 ,
F_26 ,
NULL ,
F_27 ,
V_31 ,
V_14 ,
F_19 ,
} ;
F_31 ( V_30 , & V_29 ) ;
F_31 ( V_33 , & V_32 ) ;
F_31 ( V_35 , & V_34 ) ;
F_31 ( V_37 , & V_36 ) ;
}
