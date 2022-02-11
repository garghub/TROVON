T_1
F_1 ( const char * V_1 )
{
char * V_2 ;
T_2 V_3 ;
T_2 V_4 = strlen ( L_1 ) ;
char * V_5 ;
V_5 = F_2 ( F_3 ( V_1 ) ) ;
V_2 = strrchr ( V_5 , '.' ) ;
if( V_2 == NULL ) {
V_2 = V_5 + strlen ( V_5 ) ;
}
* V_2 = '\0' ;
V_3 = strlen ( V_5 ) ;
if( V_3 < V_4 ) {
F_4 ( V_5 ) ;
return FALSE ;
}
if( V_5 [ V_3 - V_4 ] != '_' || V_5 [ V_3 - V_4 + 6 ] != '_' ) {
F_4 ( V_5 ) ;
return FALSE ;
}
V_5 [ V_3 - V_4 ] = '0' ;
V_5 [ V_3 - V_4 + 6 ] = '0' ;
while( V_4 -- ) {
V_3 -- ;
if( ! F_5 ( V_5 [ V_3 ] ) ) {
F_4 ( V_5 ) ;
return FALSE ;
}
}
F_4 ( V_5 ) ;
return TRUE ;
}
static T_1
F_6 ( const char * V_6 , const char * V_7 )
{
char * V_8 ;
char * V_9 ;
char * V_10 ;
char * V_11 ;
T_2 V_4 = strlen ( L_1 ) ;
F_7 ( F_1 ( V_6 ) ) ;
F_7 ( F_1 ( V_7 ) ) ;
V_10 = F_2 ( V_6 ) ;
V_11 = F_2 ( V_7 ) ;
V_8 = strrchr ( V_10 , '.' ) ;
V_9 = strrchr ( V_11 , '.' ) ;
if ( ! V_8 ) V_8 = V_10 + strlen ( V_10 ) ;
if ( ! V_9 ) V_9 = V_11 + strlen ( V_11 ) ;
if( strcmp ( V_8 , V_9 ) != 0 ) {
F_4 ( V_10 ) ;
F_4 ( V_11 ) ;
return FALSE ;
}
* ( V_8 - V_4 ) = '\0' ;
* ( V_9 - V_4 ) = '\0' ;
if( strcmp ( V_10 , V_11 ) != 0 ) {
F_4 ( V_10 ) ;
F_4 ( V_11 ) ;
return FALSE ;
}
F_4 ( V_10 ) ;
F_4 ( V_11 ) ;
return TRUE ;
}
static T_3
F_8 ( T_4 V_12 , T_4 V_13 )
{
const T_5 * V_14 ;
const char * V_15 ;
V_14 = ( const T_5 * ) V_12 ;
V_15 = ( const char * ) V_13 ;
return F_9 ( V_14 -> V_16 , V_15 ) ;
}
void
F_10 ( const char * V_15 )
{
int V_17 , V_18 ;
T_6 V_19 ;
T_5 * V_14 = NULL ;
T_7 * V_20 ;
V_17 = F_11 ( V_15 , V_21 , 0000 ) ;
if( V_17 != - 1 ) {
V_18 = F_12 ( V_17 , & V_19 ) ;
if( V_18 == 0 ) {
V_20 = F_13 ( V_22 . V_23 , V_15 ,
F_8 ) ;
if ( V_20 ) {
V_14 = ( T_5 * ) V_20 -> V_24 ;
V_14 -> ctime = F_14 ( V_19 ) ;
V_14 -> V_25 = V_19 . V_26 ;
V_14 -> V_27 = V_19 . V_28 ;
}
}
F_15 ( V_17 ) ;
}
}
static T_5 *
F_16 ( const char * V_29 , const char * V_1 , T_1 V_30 )
{
int V_17 , V_18 ;
T_6 V_19 ;
char * V_15 ;
T_5 * V_14 = NULL ;
V_15 = F_17 ( L_2 , V_29 , V_1 ) ;
V_17 = F_11 ( V_15 , V_21 , 0000 ) ;
if( V_17 != - 1 ) {
V_18 = F_12 ( V_17 , & V_19 ) ;
if( V_18 == 0 ) {
V_14 = ( T_5 * ) F_18 ( sizeof( T_5 ) ) ;
V_14 -> V_16 = F_2 ( V_15 ) ;
V_14 -> V_31 = F_2 ( V_1 ) ;
V_14 -> ctime = F_14 ( V_19 ) ;
V_14 -> V_25 = V_19 . V_26 ;
V_14 -> V_27 = V_19 . V_28 ;
V_14 -> V_30 = V_30 ;
V_22 . V_23 = F_19 ( V_22 . V_23 , V_14 ) ;
}
F_15 ( V_17 ) ;
}
F_4 ( V_15 ) ;
return V_14 ;
}
static T_3
F_20 ( T_4 V_12 , T_4 V_13 )
{
const T_5 * V_32 = ( const T_5 * ) V_12 ;
const T_5 * V_33 = ( const T_5 * ) V_13 ;
return strcmp ( V_32 -> V_31 , V_33 -> V_31 ) ;
}
void F_21 ( void * V_34 )
{
T_7 * V_35 ;
V_35 = F_22 ( V_22 . V_23 ) ;
while( V_35 ) {
F_23 ( ( T_5 * ) V_35 -> V_24 , V_34 ) ;
V_35 = F_24 ( V_35 ) ;
}
}
void
F_25 ( const char * V_1 , void * V_34 )
{
T_8 * V_36 ;
T_9 * V_37 ;
const char * V_31 ;
T_10 * V_29 ;
T_11 * V_38 ;
V_38 = F_2 ( V_1 ) ;
V_29 = F_26 ( F_27 ( V_38 ) ) ;
F_4 ( V_38 ) ;
V_22 . V_29 = F_2 ( V_29 -> V_39 ) ;
V_29 = F_28 ( V_29 , V_40 ) ;
if( F_1 ( V_1 ) ) {
if ( ( V_36 = F_29 ( V_29 -> V_39 , 0 , NULL ) ) != NULL ) {
while ( ( V_37 = F_30 ( V_36 ) ) != NULL ) {
V_31 = F_31 ( V_37 ) ;
if( F_1 ( V_31 ) && F_6 ( V_31 , F_3 ( V_1 ) ) ) {
F_16 ( V_29 -> V_39 , V_31 , strcmp ( V_31 , F_3 ( V_1 ) ) == 0 ) ;
}
}
F_32 ( V_36 ) ;
}
} else {
F_16 ( V_29 -> V_39 , F_3 ( V_1 ) , TRUE ) ;
}
F_33 ( V_29 , TRUE ) ;
V_22 . V_23 = F_34 ( V_22 . V_23 , F_20 ) ;
F_21 ( V_34 ) ;
}
const char *
F_35 ( void )
{
return V_22 . V_29 ;
}
static T_7 *
F_36 ( void )
{
T_7 * V_35 ;
T_5 * V_14 ;
V_35 = F_22 ( V_22 . V_23 ) ;
while( V_35 ) {
V_14 = ( T_5 * ) V_35 -> V_24 ;
if( V_14 -> V_30 ) {
return V_35 ;
}
V_35 = F_24 ( V_35 ) ;
}
return NULL ;
}
T_5 *
F_37 ( void )
{
T_7 * V_35 ;
V_35 = F_36 () ;
if( V_35 == NULL ) {
return NULL ;
}
V_35 = F_24 ( V_35 ) ;
if( V_35 == NULL ) {
return NULL ;
}
return ( T_5 * ) V_35 -> V_24 ;
}
T_5 *
F_38 ( void )
{
T_7 * V_35 ;
V_35 = F_36 () ;
if( V_35 == NULL ) {
return NULL ;
}
V_35 = F_39 ( V_35 ) ;
if( V_35 == NULL ) {
return NULL ;
}
return ( T_5 * ) V_35 -> V_24 ;
}
static void F_40 ( T_12 V_24 , T_12 T_13 V_41 )
{
T_5 * V_14 = ( T_5 * ) V_24 ;
F_4 ( ( T_12 ) V_14 -> V_16 ) ;
V_14 -> V_16 = NULL ;
F_4 ( ( T_12 ) V_14 -> V_31 ) ;
V_14 -> V_31 = NULL ;
F_4 ( V_14 ) ;
}
void F_41 ( void )
{
if( V_22 . V_23 ) {
F_42 ( V_22 . V_23 , F_40 , NULL ) ;
F_43 ( V_22 . V_23 ) ;
V_22 . V_23 = NULL ;
}
if( V_22 . V_29 ) {
F_4 ( ( T_12 ) V_22 . V_29 ) ;
V_22 . V_29 = NULL ;
}
}
