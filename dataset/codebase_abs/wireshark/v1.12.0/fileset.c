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
if( ! isdigit ( ( V_6 ) V_5 [ V_3 ] ) ) {
F_4 ( V_5 ) ;
return FALSE ;
}
}
F_4 ( V_5 ) ;
return TRUE ;
}
static T_1
F_5 ( const char * V_7 , const char * V_8 )
{
char * V_9 ;
char * V_10 ;
char * V_11 ;
char * V_12 ;
T_2 V_4 = strlen ( L_1 ) ;
F_6 ( F_1 ( V_7 ) ) ;
F_6 ( F_1 ( V_8 ) ) ;
V_11 = F_2 ( V_7 ) ;
V_12 = F_2 ( V_8 ) ;
V_9 = strrchr ( V_11 , '.' ) ;
V_10 = strrchr ( V_12 , '.' ) ;
if ( ! V_9 ) V_9 = V_11 + strlen ( V_11 ) ;
if ( ! V_10 ) V_10 = V_12 + strlen ( V_12 ) ;
if( strcmp ( V_9 , V_10 ) != 0 ) {
F_4 ( V_11 ) ;
F_4 ( V_12 ) ;
return FALSE ;
}
* ( V_9 - V_4 ) = '\0' ;
* ( V_10 - V_4 ) = '\0' ;
if( strcmp ( V_11 , V_12 ) != 0 ) {
F_4 ( V_11 ) ;
F_4 ( V_12 ) ;
return FALSE ;
}
F_4 ( V_11 ) ;
F_4 ( V_12 ) ;
return TRUE ;
}
static T_3
F_7 ( T_4 V_13 , T_4 V_14 )
{
const T_5 * V_15 ;
const char * V_16 ;
V_15 = ( const T_5 * ) V_13 ;
V_16 = ( const char * ) V_14 ;
return F_8 ( V_15 -> V_17 , V_16 ) ;
}
void
F_9 ( const char * V_16 )
{
int V_18 , V_19 ;
T_6 V_20 ;
T_5 * V_15 = NULL ;
T_7 * V_21 ;
V_18 = F_10 ( V_16 , V_22 , 0000 ) ;
if( V_18 != - 1 ) {
V_19 = F_11 ( V_18 , & V_20 ) ;
if( V_19 == 0 ) {
V_21 = F_12 ( V_23 . V_24 , V_16 ,
F_7 ) ;
if ( V_21 ) {
V_15 = ( T_5 * ) V_21 -> V_25 ;
V_15 -> ctime = V_20 . V_26 ;
V_15 -> V_27 = V_20 . V_28 ;
V_15 -> V_29 = V_20 . V_30 ;
}
}
F_13 ( V_18 ) ;
}
}
static T_5 *
F_14 ( const char * V_31 , const char * V_1 , T_1 V_32 )
{
int V_18 , V_19 ;
T_6 V_20 ;
char * V_16 ;
T_5 * V_15 = NULL ;
V_16 = F_15 ( L_2 , V_31 , V_1 ) ;
V_18 = F_10 ( V_16 , V_22 , 0000 ) ;
if( V_18 != - 1 ) {
V_19 = F_11 ( V_18 , & V_20 ) ;
if( V_19 == 0 ) {
V_15 = ( T_5 * ) F_16 ( sizeof( T_5 ) ) ;
V_15 -> V_17 = F_2 ( V_16 ) ;
V_15 -> V_33 = F_2 ( V_1 ) ;
V_15 -> ctime = V_20 . V_26 ;
V_15 -> V_27 = V_20 . V_28 ;
V_15 -> V_29 = V_20 . V_30 ;
V_15 -> V_32 = V_32 ;
V_23 . V_24 = F_17 ( V_23 . V_24 , V_15 ) ;
}
F_13 ( V_18 ) ;
}
F_4 ( V_16 ) ;
return V_15 ;
}
static T_3
F_18 ( T_4 V_13 , T_4 V_14 )
{
const T_5 * V_34 = ( const T_5 * ) V_13 ;
const T_5 * V_35 = ( const T_5 * ) V_14 ;
return strcmp ( V_34 -> V_33 , V_35 -> V_33 ) ;
}
void F_19 ( void * V_36 )
{
T_7 * V_37 ;
V_37 = F_20 ( V_23 . V_24 ) ;
while( V_37 ) {
F_21 ( ( T_5 * ) V_37 -> V_25 , V_36 ) ;
V_37 = F_22 ( V_37 ) ;
}
}
void
F_23 ( const char * V_1 , void * V_36 )
{
T_8 * V_38 ;
T_9 * V_39 ;
const char * V_33 ;
T_10 * V_31 ;
T_11 * V_40 ;
V_40 = F_24 ( F_2 ( V_1 ) ) ;
V_31 = F_25 ( V_40 ) ;
F_4 ( V_40 ) ;
V_23 . V_31 = F_2 ( V_31 -> V_41 ) ;
V_31 = F_26 ( V_31 , V_42 ) ;
if( F_1 ( V_1 ) ) {
if ( ( V_38 = F_27 ( V_31 -> V_41 , 0 , NULL ) ) != NULL ) {
while ( ( V_39 = F_28 ( V_38 ) ) != NULL ) {
V_33 = F_29 ( V_39 ) ;
if( F_1 ( V_33 ) && F_5 ( V_33 , F_3 ( V_1 ) ) ) {
F_14 ( V_31 -> V_41 , V_33 , strcmp ( V_33 , F_3 ( V_1 ) ) == 0 ) ;
}
}
F_30 ( V_38 ) ;
}
} else {
F_14 ( V_31 -> V_41 , F_3 ( V_1 ) , TRUE ) ;
}
F_31 ( V_31 , TRUE ) ;
V_23 . V_24 = F_32 ( V_23 . V_24 , F_18 ) ;
F_19 ( V_36 ) ;
}
const char *
F_33 ( void )
{
return V_23 . V_31 ;
}
static T_7 *
F_34 ( void )
{
T_7 * V_37 ;
T_5 * V_15 ;
V_37 = F_20 ( V_23 . V_24 ) ;
while( V_37 ) {
V_15 = ( T_5 * ) V_37 -> V_25 ;
if( V_15 -> V_32 ) {
return V_37 ;
}
V_37 = F_22 ( V_37 ) ;
}
return NULL ;
}
T_5 *
F_35 ( void )
{
T_7 * V_37 ;
V_37 = F_34 () ;
if( V_37 == NULL ) {
return NULL ;
}
V_37 = F_22 ( V_37 ) ;
if( V_37 == NULL ) {
return NULL ;
}
return ( T_5 * ) V_37 -> V_25 ;
}
T_5 *
F_36 ( void )
{
T_7 * V_37 ;
V_37 = F_34 () ;
if( V_37 == NULL ) {
return NULL ;
}
V_37 = F_37 ( V_37 ) ;
if( V_37 == NULL ) {
return NULL ;
}
return ( T_5 * ) V_37 -> V_25 ;
}
static void F_38 ( T_12 V_25 , T_12 T_13 V_43 )
{
T_5 * V_15 = ( T_5 * ) V_25 ;
F_4 ( ( T_12 ) V_15 -> V_17 ) ;
V_15 -> V_17 = NULL ;
F_4 ( ( T_12 ) V_15 -> V_33 ) ;
V_15 -> V_33 = NULL ;
F_4 ( V_15 ) ;
}
void F_39 ( void )
{
if( V_23 . V_24 ) {
F_40 ( V_23 . V_24 , F_38 , NULL ) ;
F_41 ( V_23 . V_24 ) ;
V_23 . V_24 = NULL ;
}
if( V_23 . V_31 ) {
F_4 ( ( T_12 ) V_23 . V_31 ) ;
V_23 . V_31 = NULL ;
}
}
