static T_1 F_1 ( T_2 V_1 )
{
const T_3 * V_2 = ( const T_3 * ) V_1 ;
return ( F_2 ( V_2 -> V_3 . V_4 ) ) ^ V_2 -> V_5 ;
}
static T_4 F_3 ( T_2 V_6 ,
T_2 V_7 )
{
const T_3 * V_8 = ( const T_3 * ) V_6 ;
const T_3 * V_9 = ( const T_3 * ) V_7 ;
if( V_8 -> V_5 != V_9 -> V_5 ||
V_8 -> V_10 != V_9 -> V_10 )
return FALSE ;
if( V_8 -> V_10 )
return ( V_8 -> V_3 . V_4 == V_9 -> V_3 . V_4 ) ;
else
return ( V_8 -> V_3 . V_11 == V_9 -> V_3 . V_11 ) ;
}
static void F_4 ( void ) {
if( V_12 != NULL ) {
F_5 ( V_12 ) ;
V_12 = NULL ;
}
}
static void F_6 ( void ) {
F_7 ( V_12 == NULL ) ;
V_12 = F_8 ( F_1 ,
F_3 ) ;
}
static T_5 * F_9 ( const struct V_4 * V_4 , int V_5 )
{
T_3 V_2 ;
V_2 . V_10 = TRUE ;
V_2 . V_3 . V_4 = V_4 ;
V_2 . V_5 = V_5 ;
return ( T_5 * ) F_10 ( V_12 , & V_2 ) ;
}
static T_5 * F_11 ( const struct V_13 * V_11 , int V_5 )
{
T_3 V_2 ;
V_2 . V_10 = FALSE ;
V_2 . V_3 . V_11 = V_11 ;
V_2 . V_5 = V_5 ;
return ( T_5 * ) F_10 ( V_12 , & V_2 ) ;
}
static T_5 * F_12 ( T_3 * V_2 )
{
T_5 * V_14 ;
V_14 = F_13 ( F_14 () , T_5 ) ;
V_14 -> V_2 = V_2 ;
V_14 -> V_15 = 0 ;
V_14 -> V_16 = NULL ;
V_14 -> V_17 = 0 ;
V_14 -> V_18 = 0 ;
F_15 ( V_12 , V_2 , V_14 ) ;
return V_14 ;
}
static T_5 * F_16 ( const struct V_4 * V_4 , int V_5 )
{
T_3 * V_2 ;
V_2 = F_13 ( F_14 () , T_3 ) ;
V_2 -> V_10 = TRUE ;
V_2 -> V_3 . V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
return F_12 ( V_2 ) ;
}
static T_5 * F_17 ( const struct V_13 * V_11 , int V_5 )
{
T_3 * V_2 ;
V_2 = F_13 ( F_14 () , T_3 ) ;
V_2 -> V_10 = FALSE ;
V_2 -> V_3 . V_11 = V_11 ;
V_2 -> V_5 = V_5 ;
return F_12 ( V_2 ) ;
}
static void F_18 ( void )
{
}
static void F_19 ( void )
{
V_15 = 0 ;
}
static T_6 * F_20 ( T_5 * V_19 )
{
T_6 * V_20 ;
V_20 = F_13 ( F_14 () , T_6 ) ;
V_20 -> V_21 = NULL ;
V_20 -> V_22 = V_19 -> V_15 ++ ;
V_20 -> V_23 = V_15 ++ ;
return V_20 ;
}
static T_1 F_21 ( T_2 V_1 )
{
const T_7 * V_2 = ( const T_7 * ) V_1 ;
return ( F_2 ( V_2 -> V_19 ) ) + ( ( T_1 ) V_2 -> V_24 ) + ( ( T_1 ) V_2 -> V_25 ) ;
}
static T_4 F_22 ( T_2 V_6 ,
T_2 V_7 )
{
const T_7 * V_8 = ( const T_7 * ) V_6 ;
const T_7 * V_9 = ( const T_7 * ) V_7 ;
return ( V_8 -> V_19 == V_9 -> V_19 &&
V_8 -> V_24 == V_9 -> V_24 &&
V_8 -> V_25 == V_9 -> V_25 ) ;
}
static void F_23 ( void ) {
if( V_26 != NULL ) {
F_5 ( V_26 ) ;
V_26 = NULL ;
}
}
static void F_24 ( void ) {
F_7 ( V_26 == NULL ) ;
V_26 = F_8 ( F_21 ,
F_22 ) ;
}
static T_8 * F_25 ( const T_5 * V_19 , T_9 V_24 , T_9 V_25 )
{
T_7 V_2 ;
T_8 * V_14 ;
V_2 . V_19 = V_19 ;
V_2 . V_24 = V_24 ;
V_2 . V_25 = V_25 ;
V_14 = ( T_8 * ) F_10 ( V_26 , & V_2 ) ;
return V_14 ;
}
static T_8 * F_26 ( const T_5 * V_19 , T_9 V_24 , T_9 V_25 ,
T_9 V_27 )
{
T_7 * V_2 ;
T_8 * V_14 ;
V_2 = F_13 ( F_14 () , T_7 ) ;
V_2 -> V_19 = V_19 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_25 = V_25 ;
V_14 = F_13 ( F_14 () , T_8 ) ;
V_14 -> V_28 = V_27 ;
V_14 -> V_20 = NULL ;
V_14 -> V_29 = FALSE ;
F_15 ( V_26 , V_2 , V_14 ) ;
return V_14 ;
}
T_5 * F_27 ( const struct V_4 * V_4 , int V_5 )
{
T_5 * V_19 ;
V_19 = F_9 ( V_4 , V_5 ) ;
F_28 ( V_19 == NULL ) ;
V_19 = F_16 ( V_4 , V_5 ) ;
return V_19 ;
}
T_5 * F_29 ( const struct V_13 * V_11 , int V_5 )
{
T_5 * V_19 ;
V_19 = F_11 ( V_11 , V_5 ) ;
F_28 ( V_19 == NULL ) ;
V_19 = F_17 ( V_11 , V_5 ) ;
return V_19 ;
}
T_5 * F_30 ( const struct V_4 * V_4 , int V_5 )
{
return F_9 ( V_4 , V_5 ) ;
}
T_5 * F_31 ( const struct V_13 * V_11 , int V_5 )
{
return F_11 ( V_11 , V_5 ) ;
}
void F_32 ( void )
{
F_4 () ;
F_23 () ;
F_18 () ;
}
void F_33 ( void )
{
F_6 () ;
F_24 () ;
F_19 () ;
F_34 ( & V_30 ,
& V_31 ) ;
}
T_8 * F_35 ( T_5 * V_19 , T_9 V_24 , T_9 V_25 )
{
return F_25 ( V_19 , V_24 , V_25 ) ;
}
T_8 * F_36 ( T_5 * V_19 , T_9 V_24 , T_9 V_25 ,
T_10 * V_32 , T_11 * V_33 , T_4 V_34 )
{
T_12 * V_21 ;
T_6 * V_20 ;
T_8 * V_35 ;
F_28 ( V_19 ) ;
F_28 ( V_24 > V_19 -> V_17 ||
( V_24 == V_19 -> V_17 && V_25 > V_19 -> V_18 ) ) ;
V_20 = V_19 -> V_16 ;
if( V_20 == NULL ) {
V_20 = V_19 -> V_16 = F_20 ( V_19 ) ;
}
V_21 = F_37 ( & V_30 ,
V_32 , 0 , V_33 , V_20 -> V_23 , NULL ,
F_38 ( V_32 ) , V_34 ) ;
V_35 = F_26 ( V_19 , V_24 , V_25 , F_38 ( V_32 ) ) ;
V_35 -> V_20 = V_20 ;
if( V_21 != NULL ) {
V_20 -> V_21 = V_21 ;
V_19 -> V_16 = NULL ;
V_35 -> V_29 = TRUE ;
}
V_19 -> V_17 = V_24 ;
V_19 -> V_18 = V_25 ;
return V_35 ;
}
T_10 * F_39 (
T_10 * V_32 , int V_25 , T_11 * V_33 ,
const char * V_36 , const T_8 * V_37 ,
const struct V_38 * V_39 ,
T_4 * V_40 , T_13 * V_41 )
{
T_6 * V_20 ;
F_28 ( V_37 ) ;
V_20 = V_37 -> V_20 ;
if( ! V_37 -> V_29 ) {
if ( V_20 -> V_21 != NULL && V_39 -> V_42 != NULL ) {
F_40 ( V_41 ,
* ( V_39 -> V_42 ) , V_32 ,
0 , 0 , V_20 -> V_21 -> V_43 ) ;
}
return NULL ;
}
return F_41 ( V_32 , V_25 , V_33 , V_36 , V_20 -> V_21 ,
V_39 , V_40 , V_41 ) ;
}
T_9 F_42 ( const T_8 * V_37 )
{
F_28 ( V_37 ) ;
return V_37 -> V_28 ;
}
T_12 * F_43 ( const T_8 * V_37 )
{
F_28 ( V_37 ) ;
return V_37 -> V_20 -> V_21 ;
}
T_9 F_44 ( const T_8 * V_37 )
{
F_28 ( V_37 ) ;
return V_37 -> V_20 -> V_22 ;
}
