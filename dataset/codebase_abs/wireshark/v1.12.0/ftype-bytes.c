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
F_5 ( T_1 * V_1 , T_3 T_4 V_4 )
{
if ( V_1 -> V_2 . V_3 -> V_5 == 0 ) {
return 0 ;
} else {
return V_1 -> V_2 . V_3 -> V_5 * 3 - 1 ;
}
}
static int
F_6 ( T_1 * V_1 V_4 , T_3 T_4 V_4 )
{
return F_7 ( V_1 ) ;
}
static void
F_8 ( T_1 * V_1 , T_3 T_4 V_4 , char * V_6 )
{
const char * V_7 = F_9 ( V_1 -> V_2 . V_3 -> V_8 , V_1 -> V_2 . V_3 -> V_5 ) ;
strncpy ( V_6 , V_7 , F_7 ( V_1 ) ) ;
}
static int
F_10 ( T_1 * V_1 V_4 , T_3 T_4 V_4 )
{
return F_11 ( V_1 ) ;
}
static void
F_12 ( T_1 * V_1 , T_3 T_4 V_4 , char * V_6 )
{
const char * V_7 = F_13 ( V_1 -> V_2 . V_3 -> V_8 , V_1 -> V_2 . V_3 -> V_5 ) ;
* V_6 ++ = '.' ;
strncpy ( V_6 , V_7 , F_11 ( V_1 ) ) ;
}
static void
F_14 ( T_1 * V_1 , T_3 T_4 , char * V_6 )
{
F_15 ( V_1 -> V_2 . V_3 -> V_8 , V_1 -> V_2 . V_3 -> V_5 , V_6 , F_5 ( V_1 , T_4 ) ) ;
}
static void
F_16 ( T_1 * V_1 , T_3 T_4 V_4 , char * V_6 )
{
T_5 * V_9 ;
char * V_10 ;
unsigned int V_11 ;
V_9 = V_1 -> V_2 . V_3 -> V_8 ;
V_10 = V_6 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_2 . V_3 -> V_5 ; V_11 ++ ) {
if ( V_11 == 0 ) {
sprintf ( V_10 , L_1 , * V_9 ++ ) ;
V_10 += 2 ;
}
else {
sprintf ( V_10 , L_2 , * V_9 ++ ) ;
V_10 += 3 ;
}
}
}
static void
F_17 ( T_1 * V_1 , const T_5 * V_8 , T_6 V_5 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = F_18 () ;
F_19 ( V_1 -> V_2 . V_3 , V_8 , V_5 ) ;
}
static void
F_20 ( T_1 * V_1 , const T_5 * V_2 )
{
F_17 ( V_1 , V_2 , V_12 ) ;
}
static void
F_21 ( T_1 * V_1 , const T_5 * V_2 )
{
F_17 ( V_1 , V_2 , V_13 ) ;
}
static void
F_22 ( T_1 * V_1 , const T_5 * V_2 )
{
F_17 ( V_1 , V_2 , V_14 ) ;
}
static void
F_23 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_2 ;
}
static void
F_24 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_2 ;
}
static T_7
F_25 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 -> V_8 ;
}
static T_8
F_26 ( T_1 * V_1 , const char * V_15 , T_9 T_10 V_4 )
{
T_2 * V_3 ;
V_3 = F_18 () ;
F_19 ( V_3 , ( const T_5 * ) V_15 , ( T_6 ) strlen ( V_15 ) ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_27 ( T_1 * V_1 , const char * V_15 , T_8 T_11 V_4 , T_9 T_10 )
{
T_2 * V_3 ;
T_8 V_16 ;
V_3 = F_18 () ;
V_16 = F_28 ( V_15 , V_3 , TRUE ) ;
if ( ! V_16 ) {
if ( T_10 != NULL )
T_10 ( L_3 , V_15 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_29 ( T_1 * V_1 , const char * V_15 , T_8 T_11 , T_9 T_10 )
{
if ( F_27 ( V_1 , V_15 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_5 > V_12 ) {
T_10 ( L_4 ,
V_15 ) ;
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_5 < V_12 && ! T_11 ) {
T_10 ( L_5 ,
V_15 ) ;
return FALSE ;
}
return TRUE ;
}
T_10 ( L_6 , V_15 ) ;
return FALSE ;
}
static T_8
F_30 ( T_1 * V_1 , const char * V_15 , T_8 T_11 , T_9 T_10 )
{
if ( F_27 ( V_1 , V_15 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_5 > V_13 ) {
T_10 ( L_7 ,
V_15 ) ;
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_5 < V_13 && ! T_11 ) {
T_10 ( L_8 ,
V_15 ) ;
return FALSE ;
}
return TRUE ;
}
T_10 ( L_9 , V_15 ) ;
return FALSE ;
}
static T_8
F_31 ( T_1 * V_1 , const char * V_15 , T_8 T_11 , T_9 T_10 )
{
T_5 * V_17 ;
if ( F_27 ( V_1 , V_15 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_5 > V_14 ) {
T_10 ( L_10 ,
V_15 ) ;
return FALSE ;
}
else if ( V_1 -> V_2 . V_3 -> V_5 < V_14 && ! T_11 ) {
T_10 ( L_11 ,
V_15 ) ;
return FALSE ;
}
return TRUE ;
}
V_17 = F_32 ( V_15 ) ;
if ( ! V_17 ) {
T_10 ( L_12 ,
V_15 ) ;
return FALSE ;
}
F_22 ( V_1 , V_17 ) ;
return TRUE ;
}
static T_8
F_33 ( T_1 * V_1 , const char * V_15 , T_8 T_11 V_4 , T_9 T_10 )
{
T_2 * V_3 ;
T_8 V_16 ;
V_3 = F_18 () ;
V_16 = F_34 ( V_15 , V_3 ) ;
if ( ! V_16 ) {
if ( T_10 != NULL )
T_10 ( L_13 , V_15 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_35 ( T_1 * V_1 , const char * V_15 , T_8 T_11 V_4 , T_9 T_10 )
{
T_2 * V_3 ;
T_8 V_16 ;
V_3 = F_18 () ;
V_16 = F_36 ( V_15 , V_3 , FALSE ) ;
if ( ! V_16 ) {
if ( T_10 != NULL )
T_10 ( L_14 , V_15 ) ;
F_3 ( V_3 , TRUE ) ;
return FALSE ;
}
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static T_8
F_37 ( T_1 * V_1 , const char * V_15 , T_8 T_11 V_4 , T_9 T_10 )
{
if ( F_27 ( V_1 , V_15 , TRUE , NULL ) ) {
if ( V_1 -> V_2 . V_3 -> V_5 > V_18 ) {
T_10 ( L_15 ,
V_15 ) ;
return FALSE ;
}
return TRUE ;
}
T_10 ( L_16 , V_15 ) ;
return FALSE ;
}
static T_6
V_5 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 -> V_5 ;
}
static void
F_38 ( T_1 * V_1 , T_2 * V_3 , T_6 V_19 , T_6 V_20 )
{
T_5 * V_8 ;
V_8 = V_1 -> V_2 . V_3 -> V_8 + V_19 ;
F_19 ( V_3 , V_8 , V_20 ) ;
}
static T_8
F_39 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
if ( V_23 -> V_5 != V_24 -> V_5 ) {
return FALSE ;
}
return ( memcmp ( V_23 -> V_8 , V_24 -> V_8 , V_23 -> V_5 ) == 0 ) ;
}
static T_8
F_40 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
if ( V_23 -> V_5 != V_24 -> V_5 ) {
return TRUE ;
}
return ( memcmp ( V_23 -> V_8 , V_24 -> V_8 , V_23 -> V_5 ) != 0 ) ;
}
static T_8
F_41 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
if ( V_23 -> V_5 > V_24 -> V_5 ) {
return TRUE ;
}
if ( V_23 -> V_5 < V_24 -> V_5 ) {
return FALSE ;
}
return ( memcmp ( V_23 -> V_8 , V_24 -> V_8 , V_23 -> V_5 ) > 0 ) ;
}
static T_8
F_42 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
if ( V_23 -> V_5 > V_24 -> V_5 ) {
return TRUE ;
}
if ( V_23 -> V_5 < V_24 -> V_5 ) {
return FALSE ;
}
return ( memcmp ( V_23 -> V_8 , V_24 -> V_8 , V_23 -> V_5 ) >= 0 ) ;
}
static T_8
F_43 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
if ( V_23 -> V_5 < V_24 -> V_5 ) {
return TRUE ;
}
if ( V_23 -> V_5 > V_24 -> V_5 ) {
return FALSE ;
}
return ( memcmp ( V_23 -> V_8 , V_24 -> V_8 , V_23 -> V_5 ) < 0 ) ;
}
static T_8
F_44 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
if ( V_23 -> V_5 < V_24 -> V_5 ) {
return TRUE ;
}
if ( V_23 -> V_5 > V_24 -> V_5 ) {
return FALSE ;
}
return ( memcmp ( V_23 -> V_8 , V_24 -> V_8 , V_23 -> V_5 ) <= 0 ) ;
}
static T_8
F_45 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
T_6 V_11 = 0 ;
unsigned char * V_25 , * V_26 ;
if ( V_24 -> V_5 != V_23 -> V_5 ) {
return FALSE ;
}
V_25 = V_23 -> V_8 ;
V_26 = V_24 -> V_8 ;
while ( V_11 < V_24 -> V_5 ) {
if ( V_25 [ V_11 ] & V_26 [ V_11 ] )
return TRUE ;
else
V_11 ++ ;
}
return FALSE ;
}
static T_8
F_46 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_2 * V_24 = V_22 -> V_2 . V_3 ;
if ( F_47 ( V_23 -> V_8 , V_23 -> V_5 , V_24 -> V_8 , V_24 -> V_5 ) ) {
return TRUE ;
}
else {
return FALSE ;
}
}
static T_8
F_48 ( const T_1 * V_21 , const T_1 * V_22 )
{
T_2 * V_23 = V_21 -> V_2 . V_3 ;
T_12 * V_27 = V_22 -> V_2 . V_28 ;
if ( strcmp ( V_22 -> V_29 -> V_30 , L_17 ) != 0 ) {
return FALSE ;
}
if ( ! V_27 ) {
return FALSE ;
}
return F_49 (
V_27 ,
( char * ) V_23 -> V_8 ,
( int ) V_23 -> V_5 ,
0 ,
( V_31 ) 0 ,
NULL ,
NULL
) ;
}
void
F_50 ( void )
{
static T_13 V_32 = {
V_33 ,
L_18 ,
L_19 ,
0 ,
F_1 ,
F_2 ,
F_27 ,
F_26 ,
F_16 ,
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
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
V_34 ,
V_5 ,
F_38 ,
} ;
static T_13 V_35 = {
V_36 ,
L_20 ,
L_19 ,
0 ,
F_1 ,
F_2 ,
F_27 ,
NULL ,
F_16 ,
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
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
NULL ,
V_5 ,
F_38 ,
} ;
static T_13 V_37 = {
V_38 ,
L_21 ,
L_22 ,
V_12 ,
F_1 ,
F_2 ,
F_29 ,
NULL ,
F_16 ,
F_5 ,
NULL ,
F_20 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
V_34 ,
V_5 ,
F_38 ,
} ;
static T_13 V_39 = {
V_40 ,
L_23 ,
L_24 ,
V_13 ,
F_1 ,
F_2 ,
F_30 ,
NULL ,
F_16 ,
F_5 ,
NULL ,
F_21 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
V_34 ,
V_5 ,
F_38 ,
} ;
static T_13 V_41 = {
V_42 ,
L_25 ,
L_26 ,
V_14 ,
F_1 ,
F_2 ,
F_31 ,
NULL ,
F_16 ,
F_5 ,
NULL ,
F_22 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
V_34 ,
V_5 ,
F_38 ,
} ;
static T_13 V_43 = {
V_44 ,
L_27 ,
L_28 ,
0 ,
F_1 ,
F_2 ,
F_33 ,
NULL ,
F_8 ,
F_6 ,
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
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
NULL ,
V_5 ,
F_38 ,
} ;
static T_13 V_45 = {
V_46 ,
L_29 ,
L_30 ,
0 ,
F_1 ,
F_2 ,
F_35 ,
NULL ,
F_12 ,
F_10 ,
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
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
NULL ,
V_5 ,
F_38 ,
} ;
static T_13 V_47 = {
V_48 ,
L_31 ,
L_32 ,
0 ,
F_1 ,
F_2 ,
F_37 ,
NULL ,
F_14 ,
F_5 ,
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
F_25 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_39 ,
F_40 ,
F_41 ,
F_42 ,
F_43 ,
F_44 ,
F_45 ,
F_46 ,
NULL ,
V_5 ,
F_38 ,
} ;
F_51 ( V_33 , & V_32 ) ;
F_51 ( V_36 , & V_35 ) ;
F_51 ( V_38 , & V_37 ) ;
F_51 ( V_40 , & V_39 ) ;
F_51 ( V_42 , & V_41 ) ;
F_51 ( V_44 , & V_43 ) ;
F_51 ( V_46 , & V_45 ) ;
F_51 ( V_48 , & V_47 ) ;
}
