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
F_4 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_2 ;
}
static int
F_5 ( T_1 * V_1 , T_3 V_4 , int T_4 V_5 )
{
if ( V_1 -> V_2 . V_3 -> V_6 == 0 ) {
return ( V_4 == V_7 ) ? 2 : 0 ;
} else {
return V_1 -> V_2 . V_3 -> V_6 * 3 - 1 ;
}
}
static int
F_6 ( T_1 * V_1 V_5 , T_3 V_4 V_5 , int T_4 V_5 )
{
return F_7 ( V_1 ) ;
}
static void
F_8 ( T_1 * V_1 , T_3 V_4 V_5 , int T_4 V_5 , char * V_8 )
{
char * V_9 = F_9 ( NULL , V_1 -> V_2 . V_3 -> V_10 , V_1 -> V_2 . V_3 -> V_6 ) ;
F_10 ( V_8 , V_9 , F_7 ( V_1 ) ) ;
F_11 ( NULL , V_9 ) ;
}
static int
F_12 ( T_1 * V_1 V_5 , T_3 V_4 V_5 , int T_4 V_5 )
{
return F_13 ( V_1 ) ;
}
static void
F_14 ( T_1 * V_1 , T_3 V_4 V_5 , int T_4 V_5 , char * V_8 )
{
char * V_9 = F_15 ( NULL , V_1 -> V_2 . V_3 -> V_10 , V_1 -> V_2 . V_3 -> V_6 ) ;
* V_8 ++ = '.' ;
F_10 ( V_8 , V_9 , F_13 ( V_1 ) ) ;
F_11 ( NULL , V_9 ) ;
}
static void
F_16 ( T_1 * V_1 , T_3 V_4 , int T_4 , char * V_8 )
{
F_17 ( V_1 -> V_2 . V_3 -> V_10 , V_1 -> V_2 . V_3 -> V_6 , V_8 , F_5 ( V_1 , V_4 , T_4 ) ) ;
}
static void
F_18 ( T_1 * V_1 , T_3 V_4 , int T_4 , char * V_8 )
{
char V_11 ;
switch( T_4 )
{
case V_12 :
V_11 = '.' ;
break;
case V_13 :
V_11 = '-' ;
break;
case V_14 :
case V_15 :
case V_16 :
default:
V_11 = ':' ;
break;
}
if ( V_1 -> V_2 . V_3 -> V_6 ) {
V_8 = F_19 ( V_8 , V_1 -> V_2 . V_3 -> V_10 , V_1 -> V_2 . V_3 -> V_6 , V_11 ) ;
}
else {
if ( V_4 == V_7 ) {
* V_8 ++ = '"' ;
* V_8 ++ = '"' ;
}
}
* V_8 = '\0' ;
}
static void
F_20 ( T_1 * V_1 , const T_5 * V_10 , T_6 V_6 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = F_21 () ;
F_22 ( V_1 -> V_2 . V_3 , V_10 , V_6 ) ;
}
static void
F_23 ( T_1 * V_1 , const T_5 * V_2 )
{
F_20 ( V_1 , V_2 , V_17 ) ;
}
static void
F_24 ( T_1 * V_1 , const T_5 * V_2 )
{
F_20 ( V_1 , V_2 , V_18 ) ;
}
static void
F_25 ( T_1 * V_1 , const T_5 * V_2 )
{
F_20 ( V_1 , V_2 , V_19 ) ;
}
static void
F_26 ( T_1 * V_1 , const T_5 * V_2 )
{
F_20 ( V_1 , V_2 , V_20 ) ;
}
static void
F_27 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_2 ;
}
static void
F_28 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_2 ;
}
static T_7
F_29 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 -> V_10 ;
}
static T_8
F_30 ( T_1 * V_1 , const char * V_21 , T_9 * * T_10 V_5 )
{
T_2 * V_3 ;
V_3 = F_21 () ;
F_22 ( V_3 , ( const T_5 * ) V_21 , ( T_6 ) strlen ( V_21 ) ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_31 ( T_1 * V_1 , const char * V_21 , T_8 T_11 V_5 , T_9 * * T_10 )
{
T_2 * V_3 ;
T_8 V_22 ;
V_3 = F_21 () ;
V_22 = F_32 ( V_21 , V_3 , TRUE ) ;
if ( ! V_22 ) {
if ( T_10 != NULL )
* T_10 = F_33 ( L_1 , V_21 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_34 ( T_1 * V_1 , const char * V_21 , T_8 T_11 , T_9 * * T_10 )
{
if ( F_31 ( V_1 , V_21 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_6 > V_17 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_2 ,
V_21 ) ;
}
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_6 < V_17 && ! T_11 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_3 ,
V_21 ) ;
}
return FALSE ;
}
return TRUE ;
}
if ( T_10 != NULL )
* T_10 = F_33 ( L_4 , V_21 ) ;
return FALSE ;
}
static T_8
F_35 ( T_1 * V_1 , const char * V_21 , T_8 T_11 , T_9 * * T_10 )
{
if ( F_31 ( V_1 , V_21 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_6 > V_18 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_5 ,
V_21 ) ;
}
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_6 < V_18 && ! T_11 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_6 ,
V_21 ) ;
}
return FALSE ;
}
return TRUE ;
}
if ( T_10 != NULL )
* T_10 = F_33 ( L_7 , V_21 ) ;
return FALSE ;
}
static T_8
F_36 ( T_1 * V_1 , const char * V_21 , T_8 T_11 , T_9 * * T_10 )
{
T_5 * V_23 ;
if ( F_31 ( V_1 , V_21 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_6 > V_19 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_8 ,
V_21 ) ;
}
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_6 < V_19 && ! T_11 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_9 ,
V_21 ) ;
}
return FALSE ;
}
return TRUE ;
}
V_23 = F_37 ( V_21 ) ;
if ( ! V_23 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_10 ,
V_21 ) ;
}
return FALSE ;
}
F_25 ( V_1 , V_23 ) ;
return TRUE ;
}
static T_8
F_38 ( T_1 * V_1 , const char * V_21 , T_8 T_11 V_5 , T_9 * * T_10 )
{
T_2 * V_3 ;
T_8 V_22 ;
#if 0
if (bytes_from_unparsed(fv, s, TRUE, NULL)) {
return TRUE;
}
#endif
V_3 = F_21 () ;
V_22 = F_39 ( V_21 , V_3 ) ;
if ( ! V_22 ) {
if ( T_10 != NULL )
* T_10 = F_33 ( L_11 , V_21 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_40 ( T_1 * V_1 , const char * V_21 , T_8 T_11 V_5 , T_9 * * T_10 )
{
T_2 * V_3 ;
T_8 V_22 ;
V_3 = F_21 () ;
V_22 = F_41 ( V_21 , V_3 , FALSE ) ;
if ( ! V_22 ) {
if ( T_10 != NULL )
* T_10 = F_33 ( L_12 , V_21 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_42 ( T_1 * V_1 , const char * V_21 , T_8 T_11 V_5 , T_9 * * T_10 )
{
if ( F_31 ( V_1 , V_21 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_6 > V_24 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_13 ,
V_21 ) ;
}
return FALSE ;
}
return TRUE ;
}
if ( T_10 != NULL )
* T_10 = F_33 ( L_14 , V_21 ) ;
return FALSE ;
}
static T_8
F_43 ( T_1 * V_1 , const char * V_21 , T_8 T_11 V_5 , T_9 * * T_10 )
{
if ( F_31 ( V_1 , V_21 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_6 > V_20 ) {
if ( T_10 != NULL ) {
* T_10 = F_33 ( L_15 ,
V_21 ) ;
}
return FALSE ;
}
return TRUE ;
}
if ( T_10 != NULL )
* T_10 = F_33 ( L_16 , V_21 ) ;
return FALSE ;
}
static T_6
V_6 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 -> V_6 ;
}
static void
F_44 ( T_1 * V_1 , T_2 * V_3 , T_6 V_25 , T_6 V_26 )
{
T_5 * V_10 ;
V_10 = V_1 -> V_2 . V_3 -> V_10 + V_25 ;
F_22 ( V_3 , V_10 , V_26 ) ;
}
static T_8
F_45 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
if ( V_29 -> V_6 != V_30 -> V_6 ) {
return FALSE ;
}
return ( memcmp ( V_29 -> V_10 , V_30 -> V_10 , V_29 -> V_6 ) == 0 ) ;
}
static T_8
F_46 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
if ( V_29 -> V_6 != V_30 -> V_6 ) {
return TRUE ;
}
return ( memcmp ( V_29 -> V_10 , V_30 -> V_10 , V_29 -> V_6 ) != 0 ) ;
}
static T_8
F_47 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
if ( V_29 -> V_6 > V_30 -> V_6 ) {
return TRUE ;
}
if ( V_29 -> V_6 < V_30 -> V_6 ) {
return FALSE ;
}
return ( memcmp ( V_29 -> V_10 , V_30 -> V_10 , V_29 -> V_6 ) > 0 ) ;
}
static T_8
F_48 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
if ( V_29 -> V_6 > V_30 -> V_6 ) {
return TRUE ;
}
if ( V_29 -> V_6 < V_30 -> V_6 ) {
return FALSE ;
}
return ( memcmp ( V_29 -> V_10 , V_30 -> V_10 , V_29 -> V_6 ) >= 0 ) ;
}
static T_8
F_49 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
if ( V_29 -> V_6 < V_30 -> V_6 ) {
return TRUE ;
}
if ( V_29 -> V_6 > V_30 -> V_6 ) {
return FALSE ;
}
return ( memcmp ( V_29 -> V_10 , V_30 -> V_10 , V_29 -> V_6 ) < 0 ) ;
}
static T_8
F_50 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
if ( V_29 -> V_6 < V_30 -> V_6 ) {
return TRUE ;
}
if ( V_29 -> V_6 > V_30 -> V_6 ) {
return FALSE ;
}
return ( memcmp ( V_29 -> V_10 , V_30 -> V_10 , V_29 -> V_6 ) <= 0 ) ;
}
static T_8
F_51 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
T_6 V_31 = 0 ;
unsigned char * V_32 , * V_33 ;
if ( V_30 -> V_6 != V_29 -> V_6 ) {
return FALSE ;
}
V_32 = V_29 -> V_10 ;
V_33 = V_30 -> V_10 ;
while ( V_31 < V_30 -> V_6 ) {
if ( V_32 [ V_31 ] & V_33 [ V_31 ] )
return TRUE ;
else
V_31 ++ ;
}
return FALSE ;
}
static T_8
F_52 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_2 * V_30 = V_28 -> V_2 . V_3 ;
if ( F_53 ( V_29 -> V_10 , V_29 -> V_6 , V_30 -> V_10 , V_30 -> V_6 ) ) {
return TRUE ;
}
else {
return FALSE ;
}
}
static T_8
F_54 ( const T_1 * V_27 , const T_1 * V_28 )
{
T_2 * V_29 = V_27 -> V_2 . V_3 ;
T_12 * V_34 = V_28 -> V_2 . V_35 ;
if ( strcmp ( V_28 -> V_36 -> V_37 , L_17 ) != 0 ) {
return FALSE ;
}
if ( ! V_34 ) {
return FALSE ;
}
return F_55 (
V_34 ,
( char * ) V_29 -> V_10 ,
( int ) V_29 -> V_6 ,
0 ,
( V_38 ) 0 ,
NULL ,
NULL
) ;
}
void
F_56 ( void )
{
static T_13 V_39 = {
V_40 ,
L_18 ,
L_19 ,
0 ,
F_1 ,
F_2 ,
F_31 ,
F_30 ,
F_18 ,
F_5 ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
V_41 ,
V_6 ,
F_44 ,
} ;
static T_13 V_42 = {
V_43 ,
L_20 ,
L_19 ,
0 ,
F_1 ,
F_2 ,
F_31 ,
NULL ,
F_18 ,
F_5 ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
NULL ,
V_6 ,
F_44 ,
} ;
static T_13 V_44 = {
V_45 ,
L_21 ,
L_22 ,
V_17 ,
F_1 ,
F_2 ,
F_34 ,
NULL ,
F_18 ,
F_5 ,
NULL ,
F_23 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
V_41 ,
V_6 ,
F_44 ,
} ;
static T_13 V_46 = {
V_47 ,
L_23 ,
L_24 ,
V_18 ,
F_1 ,
F_2 ,
F_35 ,
NULL ,
F_18 ,
F_5 ,
NULL ,
F_24 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
V_41 ,
V_6 ,
F_44 ,
} ;
static T_13 V_48 = {
V_49 ,
L_25 ,
L_26 ,
V_19 ,
F_1 ,
F_2 ,
F_36 ,
NULL ,
F_18 ,
F_5 ,
NULL ,
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
V_41 ,
V_6 ,
F_44 ,
} ;
static T_13 V_50 = {
V_51 ,
L_27 ,
L_28 ,
0 ,
F_1 ,
F_2 ,
F_38 ,
NULL ,
F_8 ,
F_6 ,
F_27 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
NULL ,
V_6 ,
F_44 ,
} ;
static T_13 V_52 = {
V_53 ,
L_29 ,
L_30 ,
0 ,
F_1 ,
F_2 ,
F_40 ,
NULL ,
F_14 ,
F_12 ,
F_27 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
NULL ,
V_6 ,
F_44 ,
} ;
static T_13 V_54 = {
V_55 ,
L_31 ,
L_32 ,
0 ,
F_1 ,
F_2 ,
F_42 ,
NULL ,
F_16 ,
F_5 ,
F_28 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
NULL ,
V_6 ,
F_44 ,
} ;
static T_13 V_56 = {
V_57 ,
L_33 ,
L_34 ,
V_20 ,
F_1 ,
F_2 ,
F_43 ,
NULL ,
F_18 ,
F_5 ,
NULL ,
F_26 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_29 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_45 ,
F_46 ,
F_47 ,
F_48 ,
F_49 ,
F_50 ,
F_51 ,
F_52 ,
V_41 ,
V_6 ,
F_44 ,
} ;
F_57 ( V_40 , & V_39 ) ;
F_57 ( V_43 , & V_42 ) ;
F_57 ( V_45 , & V_44 ) ;
F_57 ( V_47 , & V_46 ) ;
F_57 ( V_49 , & V_48 ) ;
F_57 ( V_51 , & V_50 ) ;
F_57 ( V_53 , & V_52 ) ;
F_57 ( V_55 , & V_54 ) ;
F_57 ( V_57 , & V_56 ) ;
}
