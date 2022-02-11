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
F_4 ( T_1 * V_1 , T_2 V_2 , T_3 V_5 )
{
F_5 ( V_5 ) ;
F_2 ( V_1 ) ;
V_1 -> V_2 . V_3 = ( V_6 * ) V_2 ;
}
static void
F_6 ( void * V_7 )
{
F_7 ( V_7 ) ;
}
static T_3
F_8 ( T_1 * V_1 , char * V_8 , T_4 T_5 V_9 )
{
V_6 * V_10 ;
T_6 * V_11 ;
F_2 ( V_1 ) ;
V_11 = ( T_6 * ) F_9 ( V_8 , ( V_12 ) strlen ( V_8 ) ) ;
V_10 = F_10 ( V_11 ,
( V_12 ) strlen ( V_8 ) , ( V_13 ) strlen ( V_8 ) ) ;
F_11 ( V_10 , F_6 ) ;
V_1 -> V_4 = TRUE ;
V_1 -> V_2 . V_3 = V_10 ;
return TRUE ;
}
static T_3
F_12 ( T_1 * V_1 , char * V_8 , T_3 T_7 V_9 , T_4 T_5 )
{
T_1 * V_14 ;
V_6 * V_10 ;
T_6 * V_11 ;
F_2 ( V_1 ) ;
V_14 = F_13 ( V_15 , V_8 , TRUE , NULL ) ;
if ( V_14 ) {
V_11 = ( T_6 * ) F_9 ( V_14 -> V_2 . V_16 -> V_7 ,
V_14 -> V_2 . V_16 -> V_17 ) ;
V_10 = F_10 ( V_11 ,
V_14 -> V_2 . V_16 -> V_17 ,
V_14 -> V_2 . V_16 -> V_17 ) ;
F_11 ( V_10 , F_6 ) ;
V_1 -> V_4 = TRUE ;
V_1 -> V_2 . V_3 = V_10 ;
return TRUE ;
}
return F_8 ( V_1 , V_8 , T_5 ) ;
}
static int
F_14 ( T_1 * V_1 , T_8 V_18 )
{
volatile V_12 V_19 = 0 ;
if ( V_18 != V_20 ) return - 1 ;
F_15 {
V_19 = F_16 ( V_1 -> V_2 . V_3 ) * 3 - 1 ;
}
F_17 {
}
V_21 ;
return ( int ) V_19 ;
}
static void
F_18 ( T_1 * V_1 , T_8 V_18 , char * volatile V_22 )
{
V_12 V_19 ;
const T_6 * V_23 ;
unsigned int V_24 ;
F_5 ( V_18 == V_20 ) ;
F_15 {
V_19 = F_16 ( V_1 -> V_2 . V_3 ) ;
V_23 = F_19 ( V_1 -> V_2 . V_3 , 0 , V_19 ) ;
for ( V_24 = 0 ; V_24 < V_19 ; V_24 ++ ) {
if ( V_24 == 0 ) {
sprintf ( ( char * ) V_22 , L_1 , * V_23 ++ ) ;
V_22 += 2 ;
}
else {
sprintf ( ( char * ) V_22 , L_2 , * V_23 ++ ) ;
V_22 += 3 ;
}
}
}
F_17 {
}
V_21 ;
}
static T_2
F_20 ( T_1 * V_1 )
{
return V_1 -> V_2 . V_3 ;
}
static V_12
V_17 ( T_1 * V_1 )
{
volatile V_12 V_19 = 0 ;
F_15 {
if ( V_1 -> V_2 . V_3 )
V_19 = F_16 ( V_1 -> V_2 . V_3 ) ;
}
F_17 {
}
V_21 ;
return V_19 ;
}
static void
F_21 ( T_1 * V_1 , T_9 * V_16 , V_12 V_25 , V_12 V_19 )
{
const T_6 * V_7 ;
if ( V_1 -> V_2 . V_3 ) {
F_15 {
V_7 = F_19 ( V_1 -> V_2 . V_3 , V_25 , V_19 ) ;
F_22 ( V_16 , V_7 , V_19 ) ;
}
F_17 {
}
V_21 ;
}
}
static T_3
F_23 ( const T_1 * V_26 , const T_1 * V_27 )
{
V_6 * V_28 = V_26 -> V_2 . V_3 ;
V_6 * V_29 = V_27 -> V_2 . V_3 ;
volatile T_3 V_30 = FALSE ;
F_15 {
V_12 V_31 = F_16 ( V_28 ) ;
if ( V_31 == F_16 ( V_29 ) )
V_30 = ( memcmp ( F_19 ( V_28 , 0 , V_31 ) , F_19 ( V_29 , 0 , V_31 ) , V_31 ) == 0 ) ;
}
F_17 {
}
V_21 ;
return V_30 ;
}
static T_3
F_24 ( const T_1 * V_26 , const T_1 * V_27 )
{
V_6 * V_28 = V_26 -> V_2 . V_3 ;
V_6 * V_29 = V_27 -> V_2 . V_3 ;
volatile T_3 V_32 = TRUE ;
F_15 {
V_12 V_31 = F_16 ( V_28 ) ;
if ( V_31 == F_16 ( V_29 ) ) {
V_32 = ( memcmp ( F_19 ( V_28 , 0 , V_31 ) , F_19 ( V_29 , 0 , V_31 ) , V_31 ) != 0 ) ;
}
}
F_17 {
}
V_21 ;
return V_32 ;
}
static T_3
F_25 ( const T_1 * V_26 , const T_1 * V_27 )
{
V_6 * V_28 = V_26 -> V_2 . V_3 ;
V_6 * V_29 = V_27 -> V_2 . V_3 ;
volatile T_3 V_33 = FALSE ;
F_15 {
V_12 V_31 = F_16 ( V_28 ) ;
V_12 V_34 = F_16 ( V_29 ) ;
if ( V_31 > V_34 ) {
V_33 = TRUE ;
} else if ( V_31 == V_34 ) {
V_33 = ( memcmp ( F_19 ( V_28 , 0 , V_31 ) , F_19 ( V_29 , 0 , V_31 ) , V_31 ) > 0 ) ;
}
}
F_17 {
}
V_21 ;
return V_33 ;
}
static T_3
F_26 ( const T_1 * V_26 , const T_1 * V_27 )
{
V_6 * V_28 = V_26 -> V_2 . V_3 ;
V_6 * V_29 = V_27 -> V_2 . V_3 ;
volatile T_3 V_35 = FALSE ;
F_15 {
V_12 V_31 = F_16 ( V_28 ) ;
V_12 V_34 = F_16 ( V_29 ) ;
if ( V_31 > V_34 ) {
V_35 = TRUE ;
} else if ( V_31 == V_34 ) {
V_35 = ( memcmp ( F_19 ( V_28 , 0 , V_31 ) , F_19 ( V_29 , 0 , V_31 ) , V_31 ) >= 0 ) ;
}
}
F_17 {
}
V_21 ;
return V_35 ;
}
static T_3
F_27 ( const T_1 * V_26 , const T_1 * V_27 )
{
V_6 * V_28 = V_26 -> V_2 . V_3 ;
V_6 * V_29 = V_27 -> V_2 . V_3 ;
volatile T_3 V_36 = FALSE ;
F_15 {
V_12 V_31 = F_16 ( V_28 ) ;
V_12 V_34 = F_16 ( V_29 ) ;
if ( V_31 < V_34 ) {
V_36 = TRUE ;
} else if ( V_31 == V_34 ) {
V_36 = ( memcmp ( F_19 ( V_28 , 0 , V_31 ) , F_19 ( V_29 , 0 , V_31 ) , V_31 ) < 0 ) ;
}
}
F_17 {
}
V_21 ;
return V_36 ;
}
static T_3
F_28 ( const T_1 * V_26 , const T_1 * V_27 )
{
V_6 * V_28 = V_26 -> V_2 . V_3 ;
V_6 * V_29 = V_27 -> V_2 . V_3 ;
volatile T_3 V_37 = FALSE ;
F_15 {
V_12 V_31 = F_16 ( V_28 ) ;
V_12 V_34 = F_16 ( V_29 ) ;
if ( V_31 < V_34 ) {
V_37 = TRUE ;
} else if ( V_31 == V_34 ) {
V_37 = ( memcmp ( F_19 ( V_28 , 0 , V_31 ) , F_19 ( V_29 , 0 , V_31 ) , V_31 ) <= 0 ) ;
}
}
F_17 {
}
V_21 ;
return V_37 ;
}
static T_3
F_29 ( const T_1 * V_26 , const T_1 * V_27 )
{
volatile T_3 V_38 = FALSE ;
F_15 {
if ( F_30 ( V_26 -> V_2 . V_3 , V_27 -> V_2 . V_3 , 0 ) > - 1 ) {
V_38 = TRUE ;
}
}
F_17 {
}
V_21 ;
return V_38 ;
}
static T_3
F_31 ( const T_1 * V_26 , const T_1 * V_27 )
{
V_6 * V_3 = V_26 -> V_2 . V_3 ;
T_10 * V_39 = V_27 -> V_2 . V_40 ;
volatile T_3 V_41 = FALSE ;
const char * V_7 = NULL ;
T_11 V_42 ;
if ( strcmp ( V_27 -> V_43 -> V_44 , L_3 ) != 0 ) {
return FALSE ;
}
if ( ! V_39 ) {
return FALSE ;
}
F_15 {
V_42 = F_16 ( V_3 ) ;
V_7 = ( const char * ) F_19 ( V_3 , 0 , V_42 ) ;
V_41 = F_32 (
V_39 ,
V_7 ,
V_42 ,
0 ,
( V_45 ) 0 ,
NULL ,
NULL
) ;
}
F_17 {
return FALSE ;
}
V_21 ;
return V_41 ;
}
void
F_33 ( void )
{
static T_12 V_46 = {
V_47 ,
L_4 ,
L_5 ,
0 ,
F_1 ,
F_2 ,
F_12 ,
F_8 ,
F_18 ,
F_14 ,
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
V_48 ,
V_17 ,
F_21 ,
} ;
F_34 ( V_47 , & V_46 ) ;
}
