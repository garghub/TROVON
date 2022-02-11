static T_1
F_1 ( T_2 * V_1 )
{
T_3 V_2 ;
void (* F_2)( void );
T_4 * V_3 ;
if ( ! F_3 ( V_1 , L_1 , & V_2 ) ) {
return FALSE ;
}
F_2 = ( void ( * ) ( void ) ) V_2 ;
V_3 = ( T_4 * ) F_4 ( sizeof ( T_4 ) ) ;
V_3 -> F_2 = F_2 ;
V_4 = F_5 ( V_4 , V_3 ) ;
return TRUE ;
}
void
F_6 ( void )
{
F_7 ( L_2 , F_1 ) ;
}
static void
F_8 ( T_3 V_5 , T_3 T_5 V_6 )
{
T_4 * V_3 = ( T_4 * ) V_5 ;
( V_3 -> F_2 ) ( ) ;
}
void
F_9 ( void )
{
F_10 ( V_4 , F_8 , NULL ) ;
}
void
F_11 ( void )
{
V_7 = 0 ;
}
int
F_12 ( const char * V_8 )
{
T_6 * V_9 , * V_10 ;
int V_11 , V_12 ;
if( V_13 ) {
V_12 = F_13 ( V_8 ) ;
if ( V_12 )
return V_12 ;
}
V_9 = ( T_6 * ) F_4 ( sizeof( T_6 ) ) ;
V_9 -> V_14 = NULL ;
V_9 -> V_8 = F_14 ( V_8 ) ;
if( ! V_13 ) {
V_13 = V_9 ;
V_11 = 1 ;
} else {
for( V_11 = 2 , V_10 = V_13 ; V_10 -> V_14 ; V_11 ++ , V_10 = V_10 -> V_14 )
;
V_10 -> V_14 = V_9 ;
}
return V_11 ;
}
void
F_15 ( int V_12 , T_7 * V_15 , const void * V_16 )
{
T_8 * V_17 ;
if( ! V_18 ) {
return;
}
if( V_7 >= V_19 ) {
F_16 ( L_3 ) ;
return;
}
V_17 = & V_20 [ V_7 ] ;
V_17 -> V_12 = V_12 ;
V_17 -> V_21 = 0 ;
if ( V_15 -> V_21 . V_22 )
V_17 -> V_21 |= V_23 ;
V_17 -> V_15 = V_15 ;
V_17 -> V_16 = V_16 ;
V_7 ++ ;
}
void F_17 ( T_9 * V_24 )
{
T_10 * V_25 ;
if( ! V_26 ) {
return;
}
for( V_25 = ( T_10 * ) V_26 ; V_25 ; V_25 = V_25 -> V_14 ) {
if( V_25 -> V_27 ) {
F_18 ( V_24 , V_25 -> V_27 ) ;
}
}
}
void
F_19 ( T_9 * V_24 )
{
if( ! V_26 ) {
return;
}
V_18 = TRUE ;
V_7 = 0 ;
F_17 ( V_24 ) ;
}
void
F_20 ( T_9 * V_24 )
{
T_8 * V_28 ;
T_10 * V_25 ;
T_11 V_11 ;
if( ! V_18 ) {
return;
}
V_18 = FALSE ;
if( ! V_7 ) {
return;
}
for( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
for( V_25 = ( T_10 * ) V_26 ; V_25 ; V_25 = V_25 -> V_14 ) {
V_28 = & V_20 [ V_11 ] ;
if ( ! ( V_28 -> V_21 & V_23 ) || ( V_25 -> V_21 & V_29 ) )
{
if( V_28 -> V_12 == V_25 -> V_12 ) {
T_1 V_30 = TRUE ;
if( V_25 -> V_27 ) {
V_30 = F_21 ( V_25 -> V_27 , V_24 ) ;
}
if( V_30 && V_25 -> V_31 ) {
V_25 -> V_32 |= V_25 -> V_31 ( V_25 -> V_33 , V_28 -> V_15 , V_24 , V_28 -> V_16 ) ;
}
}
}
}
}
}
const void *
F_22 ( int V_12 , int V_34 )
{
T_8 * V_28 ;
T_11 V_11 ;
if( ! V_18 ) {
return NULL ;
}
if( ! V_7 ) {
return NULL ;
}
for( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
V_28 = & V_20 [ V_11 ] ;
if( V_28 -> V_12 == V_12 ) {
if( ! V_34 -- ) {
return V_28 -> V_16 ;
}
}
}
return NULL ;
}
void
F_23 ( void )
{
T_10 * V_25 ;
for( V_25 = ( T_10 * ) V_26 ; V_25 ; V_25 = V_25 -> V_14 ) {
if( V_25 -> V_35 ) {
V_25 -> V_35 ( V_25 -> V_33 ) ;
}
V_25 -> V_32 = TRUE ;
}
}
void
F_24 ( T_1 V_36 )
{
T_10 * V_25 ;
for( V_25 = ( T_10 * ) V_26 ; V_25 ; V_25 = V_25 -> V_14 ) {
if( V_25 -> V_32 || V_36 ) {
if( V_25 -> V_37 ) {
V_25 -> V_37 ( V_25 -> V_33 ) ;
}
}
V_25 -> V_32 = FALSE ;
}
}
T_12 *
F_25 ( void )
{
T_12 * V_38 = NULL ;
T_6 * V_9 ;
for( V_9 = V_13 ; V_9 ; V_9 = V_9 -> V_14 ) {
V_38 = F_26 ( V_38 , V_9 -> V_8 ) ;
}
return F_27 ( V_38 ) ;
}
int
F_13 ( const char * V_8 )
{
T_6 * V_9 ;
int V_11 ;
for( V_11 = 1 , V_9 = V_13 ; V_9 ; V_11 ++ , V_9 = V_9 -> V_14 ) {
if( ! strcmp ( V_9 -> V_8 , V_8 ) ) {
return V_11 ;
}
}
return 0 ;
}
T_13 *
F_28 ( const char * V_39 , void * V_33 , const char * V_40 ,
T_11 V_21 , T_14 V_35 , T_15 V_31 , T_16 V_37 )
{
T_10 * V_25 ;
int V_12 ;
T_13 * V_41 ;
T_17 * V_42 ;
V_12 = F_13 ( V_39 ) ;
if( ! V_12 ) {
V_41 = F_29 ( L_4 ) ;
F_30 ( V_41 , L_5 , V_39 ) ;
return V_41 ;
}
V_25 = ( T_10 * ) F_4 ( sizeof( T_10 ) ) ;
V_25 -> V_27 = NULL ;
V_25 -> V_32 = TRUE ;
V_25 -> V_21 = V_21 ;
if( V_40 ) {
if( ! F_31 ( V_40 , & V_25 -> V_27 , & V_42 ) ) {
V_41 = F_29 ( L_4 ) ;
F_30 ( V_41 ,
L_6 ,
V_40 , V_42 ) ;
F_32 ( V_42 ) ;
F_32 ( V_25 ) ;
return V_41 ;
}
}
V_25 -> V_40 = F_14 ( V_40 ) ;
V_25 -> V_12 = V_12 ;
V_25 -> V_33 = V_33 ;
V_25 -> V_35 = V_35 ;
V_25 -> V_31 = V_31 ;
V_25 -> V_37 = V_37 ;
V_25 -> V_14 = ( T_10 * ) V_26 ;
V_26 = V_25 ;
return NULL ;
}
T_13 *
F_33 ( void * V_33 , const char * V_40 )
{
T_10 * V_25 = NULL , * V_43 ;
T_13 * V_41 ;
T_17 * V_42 ;
if( ! V_26 ) {
return NULL ;
}
if( V_26 -> V_33 == V_33 ) {
V_25 = ( T_10 * ) V_26 ;
} else {
for( V_43 = ( T_10 * ) V_26 ; V_43 -> V_14 ; V_43 = V_43 -> V_14 ) {
if( V_43 -> V_14 -> V_33 == V_33 ) {
V_25 = V_43 -> V_14 ;
break;
}
}
}
if( V_25 ) {
if( V_25 -> V_27 ) {
F_34 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
}
V_25 -> V_32 = TRUE ;
F_32 ( V_25 -> V_40 ) ;
if( V_40 ) {
if( ! F_31 ( V_40 , & V_25 -> V_27 , & V_42 ) ) {
V_25 -> V_40 = NULL ;
V_41 = F_29 ( L_4 ) ;
F_30 ( V_41 ,
L_6 ,
V_40 , V_42 ) ;
F_32 ( V_42 ) ;
return V_41 ;
}
}
V_25 -> V_40 = F_14 ( V_40 ) ;
}
return NULL ;
}
void
F_35 ( void )
{
T_10 * V_25 ;
T_17 * V_42 ;
for( V_25 = ( T_10 * ) V_26 ; V_25 ; V_25 = V_25 -> V_14 ) {
if( V_25 -> V_27 ) {
F_34 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
}
V_25 -> V_32 = TRUE ;
if( V_25 -> V_40 ) {
if( ! F_31 ( V_25 -> V_40 , & V_25 -> V_27 , & V_42 ) ) {
F_32 ( V_42 ) ;
F_31 ( L_7 , & V_25 -> V_27 , & V_42 ) ;
}
}
}
}
void
F_36 ( void * V_33 )
{
T_10 * V_25 = NULL , * V_43 ;
if( ! V_26 ) {
return;
}
if( V_26 -> V_33 == V_33 ) {
V_25 = ( T_10 * ) V_26 ;
V_26 = V_26 -> V_14 ;
} else {
for( V_43 = ( T_10 * ) V_26 ; V_43 -> V_14 ; V_43 = V_43 -> V_14 ) {
if( V_43 -> V_14 -> V_33 == V_33 ) {
V_25 = V_43 -> V_14 ;
V_43 -> V_14 = V_43 -> V_14 -> V_14 ;
break;
}
}
}
if( V_25 ) {
if( V_25 -> V_27 ) {
F_34 ( V_25 -> V_27 ) ;
}
F_32 ( V_25 -> V_40 ) ;
F_32 ( V_25 ) ;
}
return;
}
T_1
F_37 ( void )
{
volatile T_10 * V_44 = V_26 ;
while( V_44 ) {
if( ! ( V_44 -> V_21 & V_45 ) )
return TRUE ;
V_44 = V_44 -> V_14 ;
}
return FALSE ;
}
T_1
F_38 ( int V_12 )
{
volatile T_10 * V_44 = V_26 ;
while( V_44 ) {
if( V_44 -> V_12 == V_12 )
return TRUE ;
V_44 = V_44 -> V_14 ;
}
return FALSE ;
}
T_1
F_39 ( void )
{
T_10 * V_25 ;
for( V_25 = ( T_10 * ) V_26 ; V_25 ; V_25 = V_25 -> V_14 ) {
if( V_25 -> V_27 )
return TRUE ;
}
return FALSE ;
}
T_11
F_40 ( void )
{
T_10 * V_25 ;
T_11 V_21 = 0 ;
for( V_25 = ( T_10 * ) V_26 ; V_25 ; V_25 = V_25 -> V_14 ) {
V_21 |= V_25 -> V_21 ;
}
return V_21 ;
}
