static void
F_1 ( T_1 * V_1 , T_2 V_2 )
{
F_2 ( & ( V_1 -> V_2 . V_3 ) , V_2 ) ;
F_3 ( & ( V_1 -> V_2 . V_3 ) , 32 ) ;
}
static T_3
F_4 ( T_1 * V_1 )
{
return & ( V_1 -> V_2 . V_3 ) ;
}
static T_4
F_5 ( T_1 * V_1 , const char * V_4 , T_4 T_5 V_5 , T_6 * * V_6 )
{
T_2 V_7 ;
unsigned int V_8 ;
const char * V_9 , * V_10 ;
char * V_11 ;
T_1 * V_12 ;
T_4 V_13 = FALSE ;
V_9 = strchr ( V_4 , '/' ) ;
if ( V_9 ) {
V_11 = F_6 ( NULL , V_4 , V_9 - V_4 ) ;
V_13 = TRUE ;
}
else {
V_11 = ( char * ) V_4 ;
}
if ( ! F_7 ( V_11 , & V_7 ) ) {
if ( V_6 != NULL ) {
* V_6 = F_8 ( L_1 ,
V_11 ) ;
}
if ( V_13 )
F_9 ( NULL , V_11 ) ;
return FALSE ;
}
if ( V_13 )
F_9 ( NULL , V_11 ) ;
F_2 ( & ( V_1 -> V_2 . V_3 ) , V_7 ) ;
if ( V_9 ) {
V_10 = V_9 + 1 ;
V_12 = F_10 ( V_14 , V_10 , FALSE , V_6 ) ;
if ( ! V_12 ) {
return FALSE ;
}
V_8 = F_11 ( V_12 ) ;
F_12 ( V_12 ) ;
if ( V_8 > 32 ) {
if ( V_6 != NULL ) {
* V_6 = F_8 ( L_2 ,
V_8 ) ;
}
return FALSE ;
}
F_3 ( & V_1 -> V_2 . V_3 , V_8 ) ;
}
else {
F_3 ( & ( V_1 -> V_2 . V_3 ) , 32 ) ;
}
return TRUE ;
}
static int
F_13 ( T_1 * V_1 V_5 , T_7 T_8 V_5 , int T_9 V_5 )
{
return 15 ;
}
static void
F_14 ( T_1 * V_1 , T_7 T_8 V_5 , int T_9 V_5 , char * V_15 )
{
F_15 ( & V_1 -> V_2 . V_3 , V_15 ) ;
}
static T_4
F_16 ( const T_1 * V_16 , const T_1 * V_17 )
{
return F_17 ( & V_16 -> V_2 . V_3 , & V_17 -> V_2 . V_3 ) ;
}
static T_4
F_18 ( const T_1 * V_16 , const T_1 * V_17 )
{
return F_19 ( & V_16 -> V_2 . V_3 , & V_17 -> V_2 . V_3 ) ;
}
static T_4
F_20 ( const T_1 * V_16 , const T_1 * V_17 )
{
return F_21 ( & V_16 -> V_2 . V_3 , & V_17 -> V_2 . V_3 ) ;
}
static T_4
F_22 ( const T_1 * V_16 , const T_1 * V_17 )
{
return F_23 ( & V_16 -> V_2 . V_3 , & V_17 -> V_2 . V_3 ) ;
}
static T_4
F_24 ( const T_1 * V_16 , const T_1 * V_17 )
{
return F_25 ( & V_16 -> V_2 . V_3 , & V_17 -> V_2 . V_3 ) ;
}
static T_4
F_26 ( const T_1 * V_16 , const T_1 * V_17 )
{
return F_27 ( & V_16 -> V_2 . V_3 , & V_17 -> V_2 . V_3 ) ;
}
static T_4
F_28 ( const T_1 * V_18 , const T_1 * V_19 )
{
T_2 V_20 ;
T_2 V_21 ;
V_20 = V_18 -> V_2 . V_3 . V_7 & V_18 -> V_2 . V_3 . V_22 ;
V_21 = V_19 -> V_2 . V_3 . V_7 & V_19 -> V_2 . V_3 . V_22 ;
return ( ( V_20 & V_21 ) != 0 ) ;
}
void
F_29 ( void )
{
static T_10 V_23 = {
V_24 ,
L_3 ,
L_4 ,
4 ,
NULL ,
NULL ,
F_5 ,
NULL ,
F_14 ,
F_13 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_1 ,
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
F_16 ,
F_18 ,
F_20 ,
F_22 ,
F_24 ,
F_26 ,
F_28 ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_30 ( V_24 , & V_23 ) ;
}
