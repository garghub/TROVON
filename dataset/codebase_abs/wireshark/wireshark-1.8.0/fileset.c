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
T_1
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
static T_3 *
F_7 ( const char * V_13 , const char * V_1 , T_1 V_14 )
{
int V_15 , V_16 ;
T_4 V_17 ;
char * V_18 ;
T_3 * V_19 = NULL ;
V_18 = F_8 ( L_2 , V_13 , V_1 ) ;
V_15 = F_9 ( V_18 , V_20 , 0000 ) ;
if( V_15 != - 1 ) {
V_16 = F_10 ( V_15 , & V_17 ) ;
if( V_16 == 0 ) {
V_19 = ( T_3 * ) F_11 ( sizeof( T_3 ) ) ;
V_19 -> V_21 = F_2 ( V_18 ) ;
V_19 -> V_22 = F_2 ( V_1 ) ;
V_19 -> ctime = V_17 . V_23 ;
V_19 -> V_24 = V_17 . V_25 ;
V_19 -> V_26 = V_17 . V_27 ;
V_19 -> V_14 = V_14 ;
V_28 . V_29 = F_12 ( V_28 . V_29 , V_19 ) ;
}
F_13 ( V_15 ) ;
}
F_4 ( V_18 ) ;
return V_19 ;
}
static T_5
F_14 ( T_6 V_30 , T_6 V_31 )
{
const T_3 * V_32 = ( const T_3 * ) V_30 ;
const T_3 * V_33 = ( const T_3 * ) V_31 ;
return strcmp ( V_32 -> V_22 , V_33 -> V_22 ) ;
}
void F_15 ( void )
{
T_7 * V_34 ;
V_34 = F_16 ( V_28 . V_29 ) ;
while( V_34 ) {
F_17 ( ( T_3 * ) V_34 -> V_35 ) ;
V_34 = F_18 ( V_34 ) ;
}
}
void
F_19 ( const char * V_1 )
{
T_8 * V_36 ;
T_9 * V_37 ;
const char * V_22 ;
T_10 * V_13 ;
T_11 * V_38 ;
V_38 = F_20 ( F_2 ( V_1 ) ) ;
V_13 = F_21 ( V_38 ) ;
F_4 ( V_38 ) ;
V_28 . V_13 = F_2 ( V_13 -> V_39 ) ;
V_13 = F_22 ( V_13 , V_40 ) ;
if( F_1 ( V_1 ) ) {
if ( ( V_36 = F_23 ( V_13 -> V_39 , 0 , NULL ) ) != NULL ) {
while ( ( V_37 = F_24 ( V_36 ) ) != NULL ) {
V_22 = F_25 ( V_37 ) ;
if( F_1 ( V_22 ) && F_5 ( V_22 , F_3 ( V_1 ) ) ) {
F_7 ( V_13 -> V_39 , V_22 , strcmp ( V_22 , F_3 ( V_1 ) ) == 0 ) ;
}
}
F_26 ( V_36 ) ;
}
} else {
F_7 ( V_13 -> V_39 , F_3 ( V_1 ) , TRUE ) ;
}
F_27 ( V_13 , TRUE ) ;
V_28 . V_29 = F_28 ( V_28 . V_29 , F_14 ) ;
F_15 () ;
}
const char *
F_29 ( void )
{
return V_28 . V_13 ;
}
static T_7 *
F_30 ( void )
{
T_7 * V_34 ;
T_3 * V_19 ;
V_34 = F_16 ( V_28 . V_29 ) ;
while( V_34 ) {
V_19 = ( T_3 * ) V_34 -> V_35 ;
if( V_19 -> V_14 ) {
return V_34 ;
}
V_34 = F_18 ( V_34 ) ;
}
return NULL ;
}
T_3 *
F_31 ( void )
{
T_7 * V_34 ;
V_34 = F_30 () ;
if( V_34 == NULL ) {
return NULL ;
}
V_34 = F_18 ( V_34 ) ;
if( V_34 == NULL ) {
return NULL ;
}
return ( T_3 * ) V_34 -> V_35 ;
}
T_3 *
F_32 ( void )
{
T_7 * V_34 ;
V_34 = F_30 () ;
if( V_34 == NULL ) {
return NULL ;
}
V_34 = F_33 ( V_34 ) ;
if( V_34 == NULL ) {
return NULL ;
}
return ( T_3 * ) V_34 -> V_35 ;
}
static void F_34 ( T_12 V_35 , T_12 T_13 V_41 )
{
T_3 * V_19 = ( T_3 * ) V_35 ;
F_4 ( ( T_12 ) V_19 -> V_21 ) ;
V_19 -> V_21 = NULL ;
F_4 ( ( T_12 ) V_19 -> V_22 ) ;
V_19 -> V_22 = NULL ;
F_4 ( V_19 ) ;
}
void F_35 ( void )
{
if( V_28 . V_29 ) {
F_36 ( V_28 . V_29 , F_34 , NULL ) ;
F_37 ( V_28 . V_29 ) ;
V_28 . V_29 = NULL ;
}
if( V_28 . V_13 ) {
F_4 ( ( T_12 ) V_28 . V_13 ) ;
V_28 . V_13 = NULL ;
}
}
