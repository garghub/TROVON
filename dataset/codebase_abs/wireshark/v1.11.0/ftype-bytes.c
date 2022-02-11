static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . V_3 = NULL ;
}
static void
F_2 ( T_1 * V_1 )
{
if ( V_1 -> V_2 . V_3 ) {
F_3 ( V_1 -> V_2 . V_3 , TRUE ) ;
V_1 -> V_2 . V_3 = NULL ;
}
}
static void
F_4 ( T_1 * V_1 , T_2 V_2 , T_3 V_4 )
{
F_5 ( V_4 ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = ( V_5 * ) V_2 ;
}
static int
F_6 ( T_1 * V_1 , T_4 T_5 V_6 )
{
if ( V_1 -> V_2 . V_3 -> V_7 == 0 ) {
return 0 ;
} else {
return V_1 -> V_2 . V_3 -> V_7 * 3 - 1 ;
}
}
static int
F_7 ( T_1 * V_1 V_6 , T_4 T_5 V_6 )
{
return F_8 ( V_1 ) ;
}
static void
F_9 ( T_1 * V_1 , T_4 T_5 V_6 , char * V_8 )
{
const char * V_9 = F_10 ( V_1 -> V_2 . V_3 -> V_10 , V_1 -> V_2 . V_3 -> V_7 ) ;
strncpy ( V_8 , V_9 , F_8 ( V_1 ) ) ;
}
static int
F_11 ( T_1 * V_1 V_6 , T_4 T_5 V_6 )
{
return F_12 ( V_1 ) ;
}
static void
F_13 ( T_1 * V_1 , T_4 T_5 V_6 , char * V_8 )
{
const char * V_9 = F_14 ( V_1 -> V_2 . V_3 -> V_10 , V_1 -> V_2 . V_3 -> V_7 ) ;
* V_8 ++ = '.' ;
strncpy ( V_8 , V_9 , F_12 ( V_1 ) ) ;
}
static void
F_15 ( T_1 * V_1 , T_4 T_5 V_6 , char * V_8 )
{
T_6 * V_11 ;
char * V_12 ;
unsigned int V_13 ;
V_11 = V_1 -> V_2 . V_3 -> V_10 ;
V_12 = V_8 ;
for ( V_13 = 0 ; V_13 < V_1 -> V_2 . V_3 -> V_7 ; V_13 ++ ) {
if ( V_13 == 0 ) {
sprintf ( V_12 , L_1 , * V_11 ++ ) ;
V_12 += 2 ;
}
else {
sprintf ( V_12 , L_2 , * V_11 ++ ) ;
V_12 += 3 ;
}
}
}
static void
F_16 ( T_1 * V_1 , T_6 * V_10 , T_7 V_7 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = F_17 () ;
F_18 ( V_1 -> V_2 . V_3 , V_10 , V_7 ) ;
}
static void
F_19 ( T_1 * V_1 , T_2 V_2 , T_3 V_4 )
{
F_5 ( ! V_4 ) ;
F_16 ( V_1 , ( T_6 * ) V_2 , V_14 ) ;
}
static void
F_20 ( T_1 * V_1 , T_2 V_2 , T_3 V_4 )
{
F_5 ( ! V_4 ) ;
F_16 ( V_1 , ( T_6 * ) V_2 , V_15 ) ;
}
static void
F_21 ( T_1 * V_1 , T_2 V_2 , T_3 V_4 )
{
F_5 ( ! V_4 ) ;
F_16 ( V_1 , ( T_6 * ) V_2 , V_16 ) ;
}
static void
F_22 ( T_1 * V_1 , T_2 V_2 , T_3 V_4 )
{
F_5 ( V_4 ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = ( V_5 * ) V_2 ;
}
static T_2
F_23 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 -> V_10 ;
}
static T_3
F_24 ( T_1 * V_1 , char * V_17 , T_8 T_9 V_6 )
{
V_5 * V_3 ;
V_3 = F_17 () ;
F_18 ( V_3 , ( T_6 * ) V_17 , ( T_7 ) strlen ( V_17 ) ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_3
F_25 ( T_1 * V_1 , char * V_17 , T_3 T_10 V_6 , T_8 T_9 )
{
V_5 * V_3 ;
T_3 V_18 ;
V_3 = F_17 () ;
V_18 = F_26 ( V_17 , V_3 , TRUE ) ;
if ( ! V_18 ) {
if ( T_9 != NULL )
T_9 ( L_3 , V_17 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_3
F_27 ( T_1 * V_1 , char * V_17 , T_3 T_10 , T_8 T_9 )
{
if ( F_25 ( V_1 , V_17 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_7 > V_14 ) {
T_9 ( L_4 ,
V_17 ) ;
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_7 < V_14 && ! T_10 ) {
T_9 ( L_5 ,
V_17 ) ;
return FALSE ;
}
return TRUE ;
}
T_9 ( L_6 , V_17 ) ;
return FALSE ;
}
static T_3
F_28 ( T_1 * V_1 , char * V_17 , T_3 T_10 , T_8 T_9 )
{
if ( F_25 ( V_1 , V_17 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_7 > V_15 ) {
T_9 ( L_7 ,
V_17 ) ;
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_7 < V_15 && ! T_10 ) {
T_9 ( L_8 ,
V_17 ) ;
return FALSE ;
}
return TRUE ;
}
T_9 ( L_9 , V_17 ) ;
return FALSE ;
}
static T_3
F_29 ( T_1 * V_1 , char * V_17 , T_3 T_10 , T_8 T_9 )
{
T_6 * V_19 ;
if ( F_25 ( V_1 , V_17 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_7 > V_16 ) {
T_9 ( L_10 ,
V_17 ) ;
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_7 < V_16 && ! T_10 ) {
T_9 ( L_11 ,
V_17 ) ;
return FALSE ;
}
return TRUE ;
}
V_19 = F_30 ( V_17 ) ;
if ( ! V_19 ) {
T_9 ( L_12 ,
V_17 ) ;
return FALSE ;
}
F_21 ( V_1 , V_19 , FALSE ) ;
return TRUE ;
}
static T_3
F_31 ( T_1 * V_1 , char * V_17 , T_3 T_10 V_6 , T_8 T_9 )
{
V_5 * V_3 ;
T_3 V_18 ;
V_3 = F_17 () ;
V_18 = F_32 ( V_17 , V_3 ) ;
if ( ! V_18 ) {
if ( T_9 != NULL )
T_9 ( L_13 , V_17 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_3
F_33 ( T_1 * V_1 , char * V_17 , T_3 T_10 V_6 , T_8 T_9 )
{
V_5 * V_3 ;
T_3 V_18 ;
V_3 = F_17 () ;
V_18 = F_34 ( V_17 , V_3 , FALSE ) ;
if ( ! V_18 ) {
if ( T_9 != NULL )
T_9 ( L_14 , V_17 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_7
V_7 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 -> V_7 ;
}
static void
F_35 ( T_1 * V_1 , V_5 * V_3 , T_7 V_20 , T_7 V_21 )
{
T_6 * V_10 ;
V_10 = V_1 -> V_2 . V_3 -> V_10 + V_20 ;
F_18 ( V_3 , V_10 , V_21 ) ;
}
static T_3
F_36 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
if ( V_24 -> V_7 != V_25 -> V_7 ) {
return FALSE ;
}
return ( memcmp ( V_24 -> V_10 , V_25 -> V_10 , V_24 -> V_7 ) == 0 ) ;
}
static T_3
F_37 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
if ( V_24 -> V_7 != V_25 -> V_7 ) {
return TRUE ;
}
return ( memcmp ( V_24 -> V_10 , V_25 -> V_10 , V_24 -> V_7 ) != 0 ) ;
}
static T_3
F_38 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
if ( V_24 -> V_7 > V_25 -> V_7 ) {
return TRUE ;
}
if ( V_24 -> V_7 < V_25 -> V_7 ) {
return FALSE ;
}
return ( memcmp ( V_24 -> V_10 , V_25 -> V_10 , V_24 -> V_7 ) > 0 ) ;
}
static T_3
F_39 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
if ( V_24 -> V_7 > V_25 -> V_7 ) {
return TRUE ;
}
if ( V_24 -> V_7 < V_25 -> V_7 ) {
return FALSE ;
}
return ( memcmp ( V_24 -> V_10 , V_25 -> V_10 , V_24 -> V_7 ) >= 0 ) ;
}
static T_3
F_40 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
if ( V_24 -> V_7 < V_25 -> V_7 ) {
return TRUE ;
}
if ( V_24 -> V_7 > V_25 -> V_7 ) {
return FALSE ;
}
return ( memcmp ( V_24 -> V_10 , V_25 -> V_10 , V_24 -> V_7 ) < 0 ) ;
}
static T_3
F_41 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
if ( V_24 -> V_7 < V_25 -> V_7 ) {
return TRUE ;
}
if ( V_24 -> V_7 > V_25 -> V_7 ) {
return FALSE ;
}
return ( memcmp ( V_24 -> V_10 , V_25 -> V_10 , V_24 -> V_7 ) <= 0 ) ;
}
static T_3
F_42 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
T_7 V_13 = 0 ;
unsigned char * V_26 , * V_27 ;
if ( V_25 -> V_7 != V_24 -> V_7 ) {
return FALSE ;
}
V_26 = V_24 -> V_10 ;
V_27 = V_25 -> V_10 ;
while ( V_13 < V_25 -> V_7 ) {
if ( V_26 [ V_13 ] & V_27 [ V_13 ] )
return TRUE ;
else
V_13 ++ ;
}
return FALSE ;
}
static T_3
F_43 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
V_5 * V_25 = V_23 -> V_2 . V_3 ;
if ( F_44 ( V_24 -> V_10 , V_24 -> V_7 , V_25 -> V_10 , V_25 -> V_7 ) ) {
return TRUE ;
}
else {
return FALSE ;
}
}
static T_3
F_45 ( const T_1 * V_22 , const T_1 * V_23 )
{
V_5 * V_24 = V_22 -> V_2 . V_3 ;
T_11 * V_28 = V_23 -> V_2 . V_29 ;
if ( strcmp ( V_23 -> V_30 -> V_31 , L_15 ) != 0 ) {
return FALSE ;
}
if ( ! V_28 ) {
return FALSE ;
}
return F_46 (
V_28 ,
( char * ) V_24 -> V_10 ,
( int ) V_24 -> V_7 ,
0 ,
( V_32 ) 0 ,
NULL ,
NULL
) ;
}
void
F_47 ( void )
{
static T_12 V_33 = {
V_34 ,
L_16 ,
L_17 ,
0 ,
F_1 ,
F_2 ,
F_25 ,
F_24 ,
F_15 ,
F_6 ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
F_37 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
V_35 ,
V_7 ,
F_35 ,
} ;
static T_12 V_36 = {
V_37 ,
L_18 ,
L_17 ,
0 ,
F_1 ,
F_2 ,
F_25 ,
NULL ,
F_15 ,
F_6 ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
F_37 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
NULL ,
V_7 ,
F_35 ,
} ;
static T_12 V_38 = {
V_39 ,
L_19 ,
L_20 ,
V_14 ,
F_1 ,
F_2 ,
F_27 ,
NULL ,
F_15 ,
F_6 ,
F_19 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
F_37 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
V_35 ,
V_7 ,
F_35 ,
} ;
static T_12 V_40 = {
V_41 ,
L_21 ,
L_22 ,
V_15 ,
F_1 ,
F_2 ,
F_28 ,
NULL ,
F_15 ,
F_6 ,
F_20 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
F_37 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
V_35 ,
V_7 ,
F_35 ,
} ;
static T_12 V_42 = {
V_43 ,
L_23 ,
L_24 ,
V_16 ,
F_1 ,
F_2 ,
F_29 ,
NULL ,
F_15 ,
F_6 ,
F_21 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
F_37 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
V_35 ,
V_7 ,
F_35 ,
} ;
static T_12 V_44 = {
V_45 ,
L_25 ,
L_26 ,
0 ,
F_1 ,
F_2 ,
F_31 ,
NULL ,
F_9 ,
F_7 ,
F_22 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
F_37 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
NULL ,
V_7 ,
F_35 ,
} ;
static T_12 V_46 = {
V_47 ,
L_27 ,
L_28 ,
0 ,
F_1 ,
F_2 ,
F_33 ,
NULL ,
F_13 ,
F_11 ,
F_22 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_36 ,
F_37 ,
F_38 ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
NULL ,
V_7 ,
F_35 ,
} ;
F_48 ( V_34 , & V_33 ) ;
F_48 ( V_37 , & V_36 ) ;
F_48 ( V_39 , & V_38 ) ;
F_48 ( V_41 , & V_40 ) ;
F_48 ( V_43 , & V_42 ) ;
F_48 ( V_45 , & V_44 ) ;
F_48 ( V_47 , & V_46 ) ;
}
