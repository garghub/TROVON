static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . V_3 . V_4 = NULL ;
V_1 -> V_2 . V_3 . V_5 = NULL ;
V_1 -> V_6 = FALSE ;
}
static void
F_2 ( T_1 * V_1 )
{
if ( V_1 -> V_2 . V_3 . V_4 && V_1 -> V_6 ) {
F_3 ( V_1 -> V_2 . V_3 . V_4 ) ;
}
F_4 ( V_1 -> V_2 . V_3 . V_5 ) ;
}
static void
F_5 ( T_1 * V_1 , T_2 * V_2 , const T_3 * V_7 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 . V_4 = V_2 ;
V_1 -> V_2 . V_3 . V_5 = F_6 ( V_7 ) ;
}
static void
F_7 ( void * V_8 )
{
F_4 ( V_8 ) ;
}
static T_4
F_8 ( T_1 * V_1 , const char * V_9 , T_3 * * T_5 V_10 )
{
T_2 * V_11 ;
T_6 * V_12 ;
F_2 ( V_1 ) ;
V_12 = ( T_6 * ) F_9 ( V_9 , ( V_13 ) strlen ( V_9 ) ) ;
V_11 = F_10 ( V_12 ,
( V_13 ) strlen ( V_9 ) , ( V_14 ) strlen ( V_9 ) ) ;
F_11 ( V_11 , F_7 ) ;
V_1 -> V_6 = TRUE ;
V_1 -> V_2 . V_3 . V_4 = V_11 ;
V_1 -> V_2 . V_3 . V_5 = F_6 ( V_9 ) ;
return TRUE ;
}
static T_4
F_12 ( T_1 * V_1 , const char * V_9 , T_4 T_7 V_10 , T_3 * * T_5 )
{
T_1 * V_15 ;
T_2 * V_11 ;
T_6 * V_12 ;
F_2 ( V_1 ) ;
V_15 = F_13 ( V_16 , V_9 , TRUE , NULL ) ;
if ( V_15 ) {
V_12 = ( T_6 * ) F_9 ( V_15 -> V_2 . V_17 -> V_8 ,
V_15 -> V_2 . V_17 -> V_18 ) ;
V_11 = F_10 ( V_12 ,
V_15 -> V_2 . V_17 -> V_18 ,
V_15 -> V_2 . V_17 -> V_18 ) ;
F_11 ( V_11 , F_7 ) ;
V_1 -> V_6 = TRUE ;
V_1 -> V_2 . V_3 . V_4 = V_11 ;
return TRUE ;
}
return F_8 ( V_1 , V_9 , T_5 ) ;
}
static int
F_14 ( T_1 * V_1 , T_8 V_19 , int T_9 V_10 )
{
volatile V_13 V_20 = 0 ;
if ( V_19 != V_21 ) return - 1 ;
F_15 {
V_20 = F_16 ( V_1 -> V_2 . V_3 . V_4 ) * 3 - 1 ;
}
F_17 {
}
V_22 ;
return ( int ) V_20 ;
}
static void
F_18 ( T_1 * V_1 , T_8 V_19 , int T_9 V_10 , char * volatile V_23 , unsigned int T_10 V_10 )
{
V_13 V_20 ;
F_19 ( V_19 == V_21 ) ;
F_15 {
V_20 = F_16 ( V_1 -> V_2 . V_3 . V_4 ) ;
if ( V_20 )
V_23 = F_20 ( V_23 , F_21 ( V_1 -> V_2 . V_3 . V_4 , 0 , V_20 ) , V_20 , ':' ) ;
* V_23 = '\0' ;
}
F_17 {
}
V_22 ;
}
static T_11
F_22 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 . V_4 ;
}
static V_13
V_18 ( T_1 * V_1 )
{
volatile V_13 V_20 = 0 ;
F_15 {
if ( V_1 -> V_2 . V_3 . V_4 )
V_20 = F_16 ( V_1 -> V_2 . V_3 . V_4 ) ;
}
F_17 {
}
V_22 ;
return V_20 ;
}
static void
F_23 ( T_1 * V_1 , T_12 * V_17 , V_13 V_24 , V_13 V_20 )
{
const T_6 * V_8 ;
if ( V_1 -> V_2 . V_3 . V_4 ) {
F_15 {
V_8 = F_21 ( V_1 -> V_2 . V_3 . V_4 , V_24 , V_20 ) ;
F_24 ( V_17 , V_8 , V_20 ) ;
}
F_17 {
}
V_22 ;
}
}
static T_4
F_25 ( const T_1 * V_25 , const T_1 * V_26 )
{
T_13 * V_27 = ( T_13 * ) & V_25 -> V_2 . V_3 ;
T_13 * V_28 = ( T_13 * ) & V_26 -> V_2 . V_3 ;
volatile T_4 V_29 = FALSE ;
F_15 {
if ( ( V_27 -> V_4 != NULL ) && ( V_28 -> V_4 != NULL ) ) {
V_13 V_30 = F_16 ( V_27 -> V_4 ) ;
if ( V_30 == F_16 ( V_28 -> V_4 ) )
V_29 = ( memcmp ( F_21 ( V_27 -> V_4 , 0 , V_30 ) , F_21 ( V_28 -> V_4 , 0 , V_30 ) , V_30 ) == 0 ) ;
} else {
V_29 = ( strcmp ( V_27 -> V_5 , V_28 -> V_5 ) == 0 ) ;
}
}
F_17 {
}
V_22 ;
return V_29 ;
}
static T_4
F_26 ( const T_1 * V_25 , const T_1 * V_26 )
{
T_13 * V_27 = ( T_13 * ) & V_25 -> V_2 . V_3 ;
T_13 * V_28 = ( T_13 * ) & V_26 -> V_2 . V_3 ;
volatile T_4 V_31 = TRUE ;
F_15 {
if ( ( V_27 -> V_4 != NULL ) && ( V_28 -> V_4 != NULL ) ) {
V_13 V_30 = F_16 ( V_27 -> V_4 ) ;
if ( V_30 == F_16 ( V_28 -> V_4 ) )
V_31 = ( memcmp ( F_21 ( V_27 -> V_4 , 0 , V_30 ) , F_21 ( V_28 -> V_4 , 0 , V_30 ) , V_30 ) != 0 ) ;
} else {
V_31 = ( strcmp ( V_27 -> V_5 , V_28 -> V_5 ) != 0 ) ;
}
}
F_17 {
}
V_22 ;
return V_31 ;
}
static T_4
F_27 ( const T_1 * V_25 , const T_1 * V_26 )
{
T_13 * V_27 = ( T_13 * ) & V_25 -> V_2 . V_3 ;
T_13 * V_28 = ( T_13 * ) & V_26 -> V_2 . V_3 ;
volatile T_4 V_32 = FALSE ;
F_15 {
if ( ( V_27 -> V_4 != NULL ) && ( V_28 -> V_4 != NULL ) ) {
V_13 V_30 = F_16 ( V_27 -> V_4 ) ;
V_13 V_33 = F_16 ( V_28 -> V_4 ) ;
if ( V_30 > V_33 ) {
V_32 = TRUE ;
} else if ( V_30 == V_33 ) {
V_32 = ( memcmp ( F_21 ( V_27 -> V_4 , 0 , V_30 ) , F_21 ( V_28 -> V_4 , 0 , V_30 ) , V_30 ) > 0 ) ;
}
} else {
return ( strcmp ( V_27 -> V_5 , V_28 -> V_5 ) > 0 ) ;
}
}
F_17 {
}
V_22 ;
return V_32 ;
}
static T_4
F_28 ( const T_1 * V_25 , const T_1 * V_26 )
{
T_13 * V_27 = ( T_13 * ) & V_25 -> V_2 . V_3 ;
T_13 * V_28 = ( T_13 * ) & V_26 -> V_2 . V_3 ;
volatile T_4 V_34 = FALSE ;
F_15 {
if ( ( V_27 -> V_4 != NULL ) && ( V_28 -> V_4 != NULL ) ) {
V_13 V_30 = F_16 ( V_27 -> V_4 ) ;
V_13 V_33 = F_16 ( V_28 -> V_4 ) ;
if ( V_30 > V_33 ) {
V_34 = TRUE ;
} else if ( V_30 == V_33 ) {
V_34 = ( memcmp ( F_21 ( V_27 -> V_4 , 0 , V_30 ) , F_21 ( V_28 -> V_4 , 0 , V_30 ) , V_30 ) >= 0 ) ;
}
} else {
return ( strcmp ( V_27 -> V_5 , V_28 -> V_5 ) >= 0 ) ;
}
}
F_17 {
}
V_22 ;
return V_34 ;
}
static T_4
F_29 ( const T_1 * V_25 , const T_1 * V_26 )
{
T_13 * V_27 = ( T_13 * ) & V_25 -> V_2 . V_3 ;
T_13 * V_28 = ( T_13 * ) & V_26 -> V_2 . V_3 ;
volatile T_4 V_35 = FALSE ;
F_15 {
if ( ( V_27 -> V_4 != NULL ) && ( V_28 -> V_4 != NULL ) ) {
V_13 V_30 = F_16 ( V_27 -> V_4 ) ;
V_13 V_33 = F_16 ( V_28 -> V_4 ) ;
if ( V_30 < V_33 ) {
V_35 = TRUE ;
} else if ( V_30 == V_33 ) {
V_35 = ( memcmp ( F_21 ( V_27 -> V_4 , 0 , V_30 ) , F_21 ( V_28 -> V_4 , 0 , V_30 ) , V_30 ) < 0 ) ;
}
} else {
return ( strcmp ( V_27 -> V_5 , V_28 -> V_5 ) < 0 ) ;
}
}
F_17 {
}
V_22 ;
return V_35 ;
}
static T_4
F_30 ( const T_1 * V_25 , const T_1 * V_26 )
{
T_13 * V_27 = ( T_13 * ) & V_25 -> V_2 . V_3 ;
T_13 * V_28 = ( T_13 * ) & V_26 -> V_2 . V_3 ;
volatile T_4 V_36 = FALSE ;
F_15 {
if ( ( V_27 -> V_4 != NULL ) && ( V_28 -> V_4 != NULL ) ) {
V_13 V_30 = F_16 ( V_27 -> V_4 ) ;
V_13 V_33 = F_16 ( V_28 -> V_4 ) ;
if ( V_30 < V_33 ) {
V_36 = TRUE ;
} else if ( V_30 == V_33 ) {
V_36 = ( memcmp ( F_21 ( V_27 -> V_4 , 0 , V_30 ) , F_21 ( V_28 -> V_4 , 0 , V_30 ) , V_30 ) <= 0 ) ;
}
} else {
return ( strcmp ( V_27 -> V_5 , V_28 -> V_5 ) <= 0 ) ;
}
}
F_17 {
}
V_22 ;
return V_36 ;
}
static T_4
F_31 ( const T_1 * V_25 , const T_1 * V_26 )
{
volatile T_4 V_37 = FALSE ;
F_15 {
if ( ( V_25 -> V_2 . V_3 . V_4 != NULL ) && ( V_26 -> V_2 . V_3 . V_4 != NULL ) ) {
if ( F_32 ( V_25 -> V_2 . V_3 . V_4 , V_26 -> V_2 . V_3 . V_4 , 0 ) > - 1 ) {
V_37 = TRUE ;
}
} else {
if ( ( strlen ( V_26 -> V_2 . V_3 . V_5 ) != 0 ) &&
strstr ( V_25 -> V_2 . V_3 . V_5 , V_26 -> V_2 . V_3 . V_5 ) ) {
V_37 = TRUE ;
}
}
}
F_17 {
}
V_22 ;
return V_37 ;
}
static T_4
F_33 ( const T_1 * V_25 , const T_1 * V_26 )
{
T_13 * V_27 = ( T_13 * ) & V_25 -> V_2 . V_3 ;
T_14 * V_38 = V_26 -> V_2 . V_39 ;
volatile T_4 V_40 = FALSE ;
const char * V_8 = NULL ;
T_15 V_41 ;
if ( strcmp ( V_26 -> V_42 -> V_7 , L_1 ) != 0 ) {
return FALSE ;
}
if ( ! V_38 ) {
return FALSE ;
}
F_15 {
if ( V_27 -> V_4 != NULL ) {
V_41 = F_16 ( V_27 -> V_4 ) ;
V_8 = ( const char * ) F_21 ( V_27 -> V_4 , 0 , V_41 ) ;
V_40 = F_34 (
V_38 ,
V_8 ,
V_41 ,
0 ,
( V_43 ) 0 ,
NULL ,
NULL
) ;
} else {
V_40 = F_34 (
V_38 ,
V_27 -> V_5 ,
( int ) strlen ( V_27 -> V_5 ) ,
0 ,
( V_43 ) 0 ,
NULL ,
NULL
) ;
}
}
F_17 {
return FALSE ;
}
V_22 ;
return V_40 ;
}
void
F_35 ( void )
{
static T_16 V_44 = {
V_45 ,
L_2 ,
L_3 ,
0 ,
F_1 ,
F_2 ,
F_12 ,
F_8 ,
F_18 ,
F_14 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_5 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_22 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_25 ,
F_26 ,
F_27 ,
F_28 ,
F_29 ,
F_30 ,
NULL ,
F_31 ,
V_46 ,
V_18 ,
F_23 ,
} ;
F_36 ( V_45 , & V_44 ) ;
}
