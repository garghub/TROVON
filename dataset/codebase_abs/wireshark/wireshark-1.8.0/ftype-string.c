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
F_4 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
F_5 ( V_2 != NULL ) ;
F_5 ( ! V_3 ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . string = ( V_4 * ) F_6 ( V_2 ) ;
}
static int
F_7 ( T_1 * V_1 , T_4 V_5 )
{
V_4 * V_6 , V_7 ;
int V_8 ;
switch ( V_5 ) {
case V_9 :
return ( int ) strlen ( V_1 -> V_2 . string ) ;
case V_10 :
V_8 = 0 ;
for ( V_6 = V_1 -> V_2 . string ; ( V_7 = * V_6 ) != '\0' ; V_6 ++ ) {
if ( V_7 == '\\' || V_7 == '"' ) {
V_8 += 2 ;
}
else if ( ! isprint ( ( unsigned char ) V_7 ) ) {
V_8 += 4 ;
}
else {
V_8 ++ ;
}
}
return V_8 + 2 ;
}
F_8 () ;
return - 1 ;
}
static void
F_9 ( T_1 * V_1 , T_4 V_5 , char * V_11 )
{
V_4 * V_6 , V_7 ;
char * V_12 ;
char V_13 [ 3 ] ;
if ( V_5 == V_10 ) {
V_12 = V_11 ;
* V_12 ++ = '"' ;
for ( V_6 = V_1 -> V_2 . string ; ( V_7 = * V_6 ) != '\0' ; V_6 ++ ) {
if ( V_7 == '\\' || V_7 == '"' ) {
* V_12 ++ = '\\' ;
* V_12 ++ = V_7 ;
}
else if ( ! isprint ( ( unsigned char ) V_7 ) ) {
F_10 ( V_13 , sizeof( V_13 ) , L_1 , ( unsigned char ) V_7 ) ;
* V_12 ++ = '\\' ;
* V_12 ++ = 'x' ;
* V_12 ++ = V_13 [ 0 ] ;
* V_12 ++ = V_13 [ 1 ] ;
}
else {
* V_12 ++ = V_7 ;
}
}
* V_12 ++ = '"' ;
* V_12 = '\0' ;
}
else {
strcpy ( V_11 , V_1 -> V_2 . string ) ;
}
}
static T_2
F_11 ( T_1 * V_1 )
{
return V_1 -> V_2 . string ;
}
static T_3
F_12 ( T_1 * V_1 , char * V_14 , T_5 T_6 V_15 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . string = F_6 ( V_14 ) ;
return TRUE ;
}
static T_3
F_13 ( T_1 * V_1 , char * V_14 , T_3 T_7 V_15 , T_5 T_6 )
{
T_1 * V_16 ;
F_2 ( V_1 ) ;
V_16 = F_14 ( V_17 , V_14 , TRUE , NULL ) ;
if ( V_16 ) {
int V_18 = V_16 -> V_2 . V_19 -> V_20 ;
V_1 -> V_2 . string = ( V_4 * ) F_15 ( V_18 + 1 ) ;
memcpy ( V_1 -> V_2 . string , V_16 -> V_2 . V_19 -> V_21 , V_18 ) ;
V_1 -> V_2 . string [ V_18 ] = '\0' ;
F_16 ( V_16 ) ;
return TRUE ;
}
return F_12 ( V_1 , V_14 , T_6 ) ;
}
static T_8
V_20 ( T_1 * V_1 )
{
return ( T_8 ) strlen ( V_1 -> V_2 . string ) ;
}
static void
F_17 ( T_1 * V_1 , T_9 * V_19 , T_8 V_22 , T_8 V_23 )
{
T_10 * V_21 ;
V_21 = V_1 -> V_2 . V_24 + V_22 ;
F_18 ( V_19 , V_21 , V_23 ) ;
}
static T_3
F_19 ( T_1 * V_25 , T_1 * V_26 )
{
return ( strcmp ( V_25 -> V_2 . string , V_26 -> V_2 . string ) == 0 ) ;
}
static T_3
F_20 ( T_1 * V_25 , T_1 * V_26 )
{
return ( strcmp ( V_25 -> V_2 . string , V_26 -> V_2 . string ) != 0 ) ;
}
static T_3
F_21 ( T_1 * V_25 , T_1 * V_26 )
{
return ( strcmp ( V_25 -> V_2 . string , V_26 -> V_2 . string ) > 0 ) ;
}
static T_3
F_22 ( T_1 * V_25 , T_1 * V_26 )
{
return ( strcmp ( V_25 -> V_2 . string , V_26 -> V_2 . string ) >= 0 ) ;
}
static T_3
F_23 ( T_1 * V_25 , T_1 * V_26 )
{
return ( strcmp ( V_25 -> V_2 . string , V_26 -> V_2 . string ) < 0 ) ;
}
static T_3
F_24 ( T_1 * V_25 , T_1 * V_26 )
{
return ( strcmp ( V_25 -> V_2 . string , V_26 -> V_2 . string ) <= 0 ) ;
}
static T_3
F_25 ( T_1 * V_27 , T_1 * V_28 )
{
if ( strlen ( V_28 -> V_2 . string ) == 0 ) {
return FALSE ;
}
if ( strstr ( V_27 -> V_2 . string , V_28 -> V_2 . string ) ) {
return TRUE ;
}
else {
return FALSE ;
}
}
static T_3
F_26 ( T_1 * V_27 , T_1 * V_28 )
{
char * V_29 = V_27 -> V_2 . string ;
T_11 * V_30 = V_28 -> V_2 . V_31 ;
if ( strcmp ( V_28 -> V_32 -> V_33 , L_2 ) != 0 ) {
return FALSE ;
}
if ( ! V_30 ) {
return FALSE ;
}
return F_27 (
V_30 ,
V_29 ,
( int ) strlen ( V_29 ) ,
0 ,
0 ,
NULL ,
NULL
) ;
}
void
F_28 ( void )
{
static T_12 V_34 = {
V_35 ,
L_3 ,
L_4 ,
0 ,
F_1 ,
F_2 ,
F_13 ,
F_12 ,
F_9 ,
F_7 ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_11 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_19 ,
F_20 ,
F_21 ,
F_22 ,
F_23 ,
F_24 ,
NULL ,
F_25 ,
V_36 ,
V_20 ,
F_17 ,
} ;
static T_12 V_37 = {
V_38 ,
L_5 ,
L_4 ,
0 ,
F_1 ,
F_2 ,
F_13 ,
F_12 ,
F_9 ,
F_7 ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_11 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_19 ,
F_20 ,
F_21 ,
F_22 ,
F_23 ,
F_24 ,
NULL ,
F_25 ,
V_36 ,
V_20 ,
F_17 ,
} ;
static T_12 V_39 = {
V_40 ,
L_6 ,
L_4 ,
0 ,
F_1 ,
F_2 ,
F_13 ,
F_12 ,
F_9 ,
F_7 ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_11 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_19 ,
F_20 ,
F_21 ,
F_22 ,
F_23 ,
F_24 ,
NULL ,
F_25 ,
V_36 ,
V_20 ,
F_17 ,
} ;
F_29 ( V_35 , & V_34 ) ;
F_29 ( V_38 , & V_37 ) ;
F_29 ( V_40 , & V_39 ) ;
}
