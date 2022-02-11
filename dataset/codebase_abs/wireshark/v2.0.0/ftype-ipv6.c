static void
F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
memcpy ( V_1 -> V_2 . V_3 . V_4 . V_5 , V_2 , V_6 ) ;
V_1 -> V_2 . V_3 . V_7 = 128 ;
}
static T_3
F_2 ( T_1 * V_1 , const char * V_8 , T_3 T_4 V_9 , T_5 * * V_10 )
{
const char * V_11 ;
char * V_12 ;
unsigned int V_13 ;
T_1 * V_14 ;
T_3 V_15 = FALSE ;
if ( ( V_11 = strchr ( V_8 , '/' ) ) ) {
V_12 = F_3 ( NULL , V_8 , V_11 - V_8 ) ;
V_15 = TRUE ;
}
else
V_12 = ( char * ) V_8 ;
if ( ! F_4 ( V_12 , & ( V_1 -> V_2 . V_3 . V_4 ) ) ) {
if ( V_10 != NULL )
* V_10 = F_5 ( L_1 , V_8 ) ;
if ( V_15 )
F_6 ( NULL , V_12 ) ;
return FALSE ;
}
if ( V_15 )
F_6 ( NULL , V_12 ) ;
if ( V_11 ) {
V_14 = F_7 ( V_16 , V_11 + 1 , FALSE , V_10 ) ;
if ( ! V_14 ) {
return FALSE ;
}
V_13 = F_8 ( V_14 ) ;
F_9 ( V_14 ) ;
if ( V_13 > 128 ) {
if ( V_10 != NULL ) {
* V_10 = F_5 ( L_2 ,
V_13 ) ;
}
return FALSE ;
}
V_1 -> V_2 . V_3 . V_7 = V_13 ;
} else {
V_1 -> V_2 . V_3 . V_7 = 128 ;
}
return TRUE ;
}
static int
F_10 ( T_1 * V_1 V_9 , T_6 T_7 V_9 , int T_8 V_9 )
{
return 39 ;
}
static void
F_11 ( T_1 * V_1 , T_6 T_7 V_9 , int T_8 V_9 , char * V_17 )
{
F_12 ( & ( V_1 -> V_2 . V_3 . V_4 ) , V_17 ) ;
}
static T_9
F_13 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 . V_4 . V_5 ;
}
static T_10
F_14 ( const T_1 * V_18 , const T_1 * V_19 )
{
const T_11 * V_20 = & ( V_18 -> V_2 . V_3 ) ;
const T_11 * V_21 = & ( V_19 -> V_2 . V_3 ) ;
T_12 V_7 ;
int V_22 = 0 ;
V_7 = F_15 ( V_20 -> V_7 , V_21 -> V_7 ) ;
V_7 = F_15 ( V_7 , 128 ) ;
while ( V_7 >= 8 ) {
T_10 V_23 = ( T_10 ) ( V_20 -> V_4 . V_5 [ V_22 ] ) ;
T_10 V_24 = ( T_10 ) ( V_21 -> V_4 . V_5 [ V_22 ] ) ;
if ( V_23 != V_24 )
return V_23 - V_24 ;
V_7 -= 8 ;
V_22 ++ ;
}
if ( V_7 != 0 ) {
T_10 V_23 = ( T_10 ) ( V_20 -> V_4 . V_5 [ V_22 ] & ( V_25 [ V_7 ] ) ) ;
T_10 V_24 = ( T_10 ) ( V_21 -> V_4 . V_5 [ V_22 ] & ( V_25 [ V_7 ] ) ) ;
if ( V_23 != V_24 )
return V_23 - V_24 ;
}
return 0 ;
}
static T_3
F_16 ( const T_1 * V_18 , const T_1 * V_19 )
{
return ( F_14 ( V_18 , V_19 ) == 0 ) ;
}
static T_3
F_17 ( const T_1 * V_18 , const T_1 * V_19 )
{
return ( F_14 ( V_18 , V_19 ) != 0 ) ;
}
static T_3
F_18 ( const T_1 * V_18 , const T_1 * V_19 )
{
return ( F_14 ( V_18 , V_19 ) > 0 ) ;
}
static T_3
F_19 ( const T_1 * V_18 , const T_1 * V_19 )
{
return ( F_14 ( V_18 , V_19 ) >= 0 ) ;
}
static T_3
F_20 ( const T_1 * V_18 , const T_1 * V_19 )
{
return ( F_14 ( V_18 , V_19 ) < 0 ) ;
}
static T_3
F_21 ( const T_1 * V_18 , const T_1 * V_19 )
{
return ( F_14 ( V_18 , V_19 ) <= 0 ) ;
}
static T_3
F_22 ( const T_1 * V_18 , const T_1 * V_19 )
{
const T_11 * V_20 = & ( V_18 -> V_2 . V_3 ) ;
const T_11 * V_21 = & ( V_19 -> V_2 . V_3 ) ;
T_12 V_7 ;
int V_22 = 0 ;
V_7 = F_15 ( V_20 -> V_7 , V_21 -> V_7 ) ;
V_7 = F_15 ( V_7 , 128 ) ;
while ( V_7 >= 8 ) {
if ( V_20 -> V_4 . V_5 [ V_22 ] & V_21 -> V_4 . V_5 [ V_22 ] )
return TRUE ;
V_7 -= 8 ;
V_22 ++ ;
}
if ( V_7 != 0 ) {
T_2 V_23 = ( V_20 -> V_4 . V_5 [ V_22 ] & ( V_25 [ V_7 ] ) ) ;
T_2 V_24 = ( V_21 -> V_4 . V_5 [ V_22 ] & ( V_25 [ V_7 ] ) ) ;
if ( V_23 & V_24 )
return TRUE ;
}
return FALSE ;
}
static void
F_23 ( T_1 * V_1 , T_13 * V_5 , T_14 V_26 , T_14 V_27 )
{
T_2 * V_28 ;
V_28 = V_1 -> V_2 . V_3 . V_4 . V_5 + V_26 ;
F_24 ( V_5 , V_28 , V_27 ) ;
}
void
F_25 ( void )
{
static T_15 V_29 = {
V_30 ,
L_3 ,
L_4 ,
V_6 ,
NULL ,
NULL ,
F_2 ,
NULL ,
F_11 ,
F_10 ,
NULL ,
F_1 ,
NULL ,
NULL ,
NULL ,
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
F_16 ,
F_17 ,
F_18 ,
F_19 ,
F_20 ,
F_21 ,
F_22 ,
NULL ,
NULL ,
NULL ,
F_23 ,
} ;
F_26 ( V_30 , & V_29 ) ;
}
