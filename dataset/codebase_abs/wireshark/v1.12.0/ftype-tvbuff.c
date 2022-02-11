static void
F_1 ( T_1 * V_1 )
{
V_1 -> V_2 . V_3 = NULL ;
V_1 -> V_4 = FALSE ;
}
static void
F_2 ( T_1 * V_1 )
{
if ( V_1 -> V_2 . V_3 && V_1 -> V_4 ) {
F_3 ( V_1 -> V_2 . V_3 ) ;
}
}
static void
F_4 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = V_2 ;
}
static void
F_5 ( void * V_5 )
{
F_6 ( V_5 ) ;
}
static T_3
F_7 ( T_1 * V_1 , const char * V_6 , T_4 T_5 V_7 )
{
T_2 * V_8 ;
T_6 * V_9 ;
F_2 ( V_1 ) ;
V_9 = ( T_6 * ) F_8 ( V_6 , ( V_10 ) strlen ( V_6 ) ) ;
V_8 = F_9 ( V_9 ,
( V_10 ) strlen ( V_6 ) , ( V_11 ) strlen ( V_6 ) ) ;
F_10 ( V_8 , F_5 ) ;
V_1 -> V_4 = TRUE ;
V_1 -> V_2 . V_3 = V_8 ;
return TRUE ;
}
static T_3
F_11 ( T_1 * V_1 , const char * V_6 , T_3 T_7 V_7 , T_4 T_5 )
{
T_1 * V_12 ;
T_2 * V_8 ;
T_6 * V_9 ;
F_2 ( V_1 ) ;
V_12 = F_12 ( V_13 , V_6 , TRUE , NULL ) ;
if ( V_12 ) {
V_9 = ( T_6 * ) F_8 ( V_12 -> V_2 . V_14 -> V_5 ,
V_12 -> V_2 . V_14 -> V_15 ) ;
V_8 = F_9 ( V_9 ,
V_12 -> V_2 . V_14 -> V_15 ,
V_12 -> V_2 . V_14 -> V_15 ) ;
F_10 ( V_8 , F_5 ) ;
V_1 -> V_4 = TRUE ;
V_1 -> V_2 . V_3 = V_8 ;
return TRUE ;
}
return F_7 ( V_1 , V_6 , T_5 ) ;
}
static int
F_13 ( T_1 * V_1 , T_8 V_16 )
{
volatile V_10 V_17 = 0 ;
if ( V_16 != V_18 ) return - 1 ;
F_14 {
V_17 = F_15 ( V_1 -> V_2 . V_3 ) * 3 - 1 ;
}
F_16 {
}
V_19 ;
return ( int ) V_17 ;
}
static void
F_17 ( T_1 * V_1 , T_8 V_16 , char * volatile V_20 )
{
V_10 V_17 ;
const T_6 * V_21 ;
unsigned int V_22 ;
F_18 ( V_16 == V_18 ) ;
F_14 {
V_17 = F_15 ( V_1 -> V_2 . V_3 ) ;
V_21 = F_19 ( V_1 -> V_2 . V_3 , 0 , V_17 ) ;
for ( V_22 = 0 ; V_22 < V_17 ; V_22 ++ ) {
if ( V_22 == 0 ) {
sprintf ( ( char * ) V_20 , L_1 , * V_21 ++ ) ;
V_20 += 2 ;
}
else {
sprintf ( ( char * ) V_20 , L_2 , * V_21 ++ ) ;
V_20 += 3 ;
}
}
}
F_16 {
}
V_19 ;
}
static T_9
F_20 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 ;
}
static V_10
V_15 ( T_1 * V_1 )
{
volatile V_10 V_17 = 0 ;
F_14 {
if ( V_1 -> V_2 . V_3 )
V_17 = F_15 ( V_1 -> V_2 . V_3 ) ;
}
F_16 {
}
V_19 ;
return V_17 ;
}
static void
F_21 ( T_1 * V_1 , T_10 * V_14 , V_10 V_23 , V_10 V_17 )
{
const T_6 * V_5 ;
if ( V_1 -> V_2 . V_3 ) {
F_14 {
V_5 = F_19 ( V_1 -> V_2 . V_3 , V_23 , V_17 ) ;
F_22 ( V_14 , V_5 , V_17 ) ;
}
F_16 {
}
V_19 ;
}
}
static T_3
F_23 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_2 * V_26 = V_24 -> V_2 . V_3 ;
T_2 * V_27 = V_25 -> V_2 . V_3 ;
volatile T_3 V_28 = FALSE ;
F_14 {
V_10 V_29 = F_15 ( V_26 ) ;
if ( V_29 == F_15 ( V_27 ) )
V_28 = ( memcmp ( F_19 ( V_26 , 0 , V_29 ) , F_19 ( V_27 , 0 , V_29 ) , V_29 ) == 0 ) ;
}
F_16 {
}
V_19 ;
return V_28 ;
}
static T_3
F_24 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_2 * V_26 = V_24 -> V_2 . V_3 ;
T_2 * V_27 = V_25 -> V_2 . V_3 ;
volatile T_3 V_30 = TRUE ;
F_14 {
V_10 V_29 = F_15 ( V_26 ) ;
if ( V_29 == F_15 ( V_27 ) ) {
V_30 = ( memcmp ( F_19 ( V_26 , 0 , V_29 ) , F_19 ( V_27 , 0 , V_29 ) , V_29 ) != 0 ) ;
}
}
F_16 {
}
V_19 ;
return V_30 ;
}
static T_3
F_25 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_2 * V_26 = V_24 -> V_2 . V_3 ;
T_2 * V_27 = V_25 -> V_2 . V_3 ;
volatile T_3 V_31 = FALSE ;
F_14 {
V_10 V_29 = F_15 ( V_26 ) ;
V_10 V_32 = F_15 ( V_27 ) ;
if ( V_29 > V_32 ) {
V_31 = TRUE ;
} else if ( V_29 == V_32 ) {
V_31 = ( memcmp ( F_19 ( V_26 , 0 , V_29 ) , F_19 ( V_27 , 0 , V_29 ) , V_29 ) > 0 ) ;
}
}
F_16 {
}
V_19 ;
return V_31 ;
}
static T_3
F_26 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_2 * V_26 = V_24 -> V_2 . V_3 ;
T_2 * V_27 = V_25 -> V_2 . V_3 ;
volatile T_3 V_33 = FALSE ;
F_14 {
V_10 V_29 = F_15 ( V_26 ) ;
V_10 V_32 = F_15 ( V_27 ) ;
if ( V_29 > V_32 ) {
V_33 = TRUE ;
} else if ( V_29 == V_32 ) {
V_33 = ( memcmp ( F_19 ( V_26 , 0 , V_29 ) , F_19 ( V_27 , 0 , V_29 ) , V_29 ) >= 0 ) ;
}
}
F_16 {
}
V_19 ;
return V_33 ;
}
static T_3
F_27 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_2 * V_26 = V_24 -> V_2 . V_3 ;
T_2 * V_27 = V_25 -> V_2 . V_3 ;
volatile T_3 V_34 = FALSE ;
F_14 {
V_10 V_29 = F_15 ( V_26 ) ;
V_10 V_32 = F_15 ( V_27 ) ;
if ( V_29 < V_32 ) {
V_34 = TRUE ;
} else if ( V_29 == V_32 ) {
V_34 = ( memcmp ( F_19 ( V_26 , 0 , V_29 ) , F_19 ( V_27 , 0 , V_29 ) , V_29 ) < 0 ) ;
}
}
F_16 {
}
V_19 ;
return V_34 ;
}
static T_3
F_28 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_2 * V_26 = V_24 -> V_2 . V_3 ;
T_2 * V_27 = V_25 -> V_2 . V_3 ;
volatile T_3 V_35 = FALSE ;
F_14 {
V_10 V_29 = F_15 ( V_26 ) ;
V_10 V_32 = F_15 ( V_27 ) ;
if ( V_29 < V_32 ) {
V_35 = TRUE ;
} else if ( V_29 == V_32 ) {
V_35 = ( memcmp ( F_19 ( V_26 , 0 , V_29 ) , F_19 ( V_27 , 0 , V_29 ) , V_29 ) <= 0 ) ;
}
}
F_16 {
}
V_19 ;
return V_35 ;
}
static T_3
F_29 ( const T_1 * V_24 , const T_1 * V_25 )
{
volatile T_3 V_36 = FALSE ;
F_14 {
if ( F_30 ( V_24 -> V_2 . V_3 , V_25 -> V_2 . V_3 , 0 ) > - 1 ) {
V_36 = TRUE ;
}
}
F_16 {
}
V_19 ;
return V_36 ;
}
static T_3
F_31 ( const T_1 * V_24 , const T_1 * V_25 )
{
T_2 * V_3 = V_24 -> V_2 . V_3 ;
T_11 * V_37 = V_25 -> V_2 . V_38 ;
volatile T_3 V_39 = FALSE ;
const char * V_5 = NULL ;
T_12 V_40 ;
if ( strcmp ( V_25 -> V_41 -> V_42 , L_3 ) != 0 ) {
return FALSE ;
}
if ( ! V_37 ) {
return FALSE ;
}
F_14 {
V_40 = F_15 ( V_3 ) ;
V_5 = ( const char * ) F_19 ( V_3 , 0 , V_40 ) ;
V_39 = F_32 (
V_37 ,
V_5 ,
V_40 ,
0 ,
( V_43 ) 0 ,
NULL ,
NULL
) ;
}
F_16 {
return FALSE ;
}
V_19 ;
return V_39 ;
}
void
F_33 ( void )
{
static T_13 V_44 = {
V_45 ,
L_4 ,
L_5 ,
0 ,
F_1 ,
F_2 ,
F_11 ,
F_7 ,
F_17 ,
F_13 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_4 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_20 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_23 ,
F_24 ,
F_25 ,
F_26 ,
F_27 ,
F_28 ,
NULL ,
F_29 ,
V_46 ,
V_15 ,
F_21 ,
} ;
F_34 ( V_45 , & V_44 ) ;
}
