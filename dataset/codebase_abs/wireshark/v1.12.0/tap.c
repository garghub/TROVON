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
V_17 -> V_15 = V_15 ;
V_17 -> V_16 = V_16 ;
V_7 ++ ;
}
void F_17 ( T_9 * V_21 )
{
T_10 * V_22 ;
if( ! V_23 ) {
return;
}
for( V_22 = ( T_10 * ) V_23 ; V_22 ; V_22 = V_22 -> V_14 ) {
if( V_22 -> V_24 ) {
F_18 ( V_21 , V_22 -> V_24 ) ;
}
}
}
void
F_19 ( T_9 * V_21 )
{
if( ! V_23 ) {
return;
}
V_18 = TRUE ;
V_7 = 0 ;
F_17 ( V_21 ) ;
}
void
F_20 ( T_9 * V_21 )
{
T_8 * V_25 ;
T_10 * V_22 ;
T_11 V_11 ;
if( ! V_18 ) {
return;
}
V_18 = FALSE ;
if( ! V_7 ) {
return;
}
for( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
for( V_22 = ( T_10 * ) V_23 ; V_22 ; V_22 = V_22 -> V_14 ) {
V_25 = & V_20 [ V_11 ] ;
if( V_25 -> V_12 == V_22 -> V_12 ) {
T_1 V_26 = TRUE ;
if( V_22 -> V_24 ) {
V_26 = F_21 ( V_22 -> V_24 , V_21 ) ;
}
if( V_26 && V_22 -> V_27 ) {
V_22 -> V_28 |= V_22 -> V_27 ( V_22 -> V_29 , V_25 -> V_15 , V_21 , V_25 -> V_16 ) ;
}
}
}
}
}
const void *
F_22 ( int V_12 , int V_30 )
{
T_8 * V_25 ;
T_11 V_11 ;
if( ! V_18 ) {
return NULL ;
}
if( ! V_7 ) {
return NULL ;
}
for( V_11 = 0 ; V_11 < V_7 ; V_11 ++ ) {
V_25 = & V_20 [ V_11 ] ;
if( V_25 -> V_12 == V_12 ) {
if( ! V_30 -- ) {
return V_25 -> V_16 ;
}
}
}
return NULL ;
}
void
F_23 ( void )
{
T_10 * V_22 ;
for( V_22 = ( T_10 * ) V_23 ; V_22 ; V_22 = V_22 -> V_14 ) {
if( V_22 -> V_31 ) {
V_22 -> V_31 ( V_22 -> V_29 ) ;
}
V_22 -> V_28 = TRUE ;
}
}
void
F_24 ( T_1 V_32 )
{
T_10 * V_22 ;
for( V_22 = ( T_10 * ) V_23 ; V_22 ; V_22 = V_22 -> V_14 ) {
if( V_22 -> V_28 || V_32 ) {
if( V_22 -> V_33 ) {
V_22 -> V_33 ( V_22 -> V_29 ) ;
}
}
V_22 -> V_28 = FALSE ;
}
}
T_12 *
F_25 ( void )
{
T_12 * V_34 = NULL ;
T_6 * V_9 ;
for( V_9 = V_13 ; V_9 ; V_9 = V_9 -> V_14 ) {
V_34 = F_26 ( V_34 , V_9 -> V_8 ) ;
}
return F_27 ( V_34 ) ;
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
F_28 ( const char * V_35 , void * V_29 , const char * V_36 ,
T_11 V_37 , T_14 V_31 , T_15 V_27 , T_16 V_33 )
{
T_10 * V_22 ;
int V_12 ;
T_13 * V_38 ;
V_12 = F_13 ( V_35 ) ;
if( ! V_12 ) {
V_38 = F_29 ( L_4 ) ;
F_30 ( V_38 , L_5 , V_35 ) ;
return V_38 ;
}
V_22 = ( T_10 * ) F_4 ( sizeof( T_10 ) ) ;
V_22 -> V_24 = NULL ;
V_22 -> V_28 = TRUE ;
V_22 -> V_37 = V_37 ;
if( V_36 ) {
if( ! F_31 ( V_36 , & V_22 -> V_24 ) ) {
V_38 = F_29 ( L_4 ) ;
F_30 ( V_38 ,
L_6 ,
V_36 , V_39 ) ;
F_32 ( V_22 ) ;
return V_38 ;
}
}
V_22 -> V_12 = V_12 ;
V_22 -> V_29 = V_29 ;
V_22 -> V_31 = V_31 ;
V_22 -> V_27 = V_27 ;
V_22 -> V_33 = V_33 ;
V_22 -> V_14 = ( T_10 * ) V_23 ;
V_23 = V_22 ;
return NULL ;
}
T_13 *
F_33 ( void * V_29 , const char * V_36 )
{
T_10 * V_22 = NULL , * V_40 ;
T_13 * V_38 ;
if( ! V_23 ) {
return NULL ;
}
if( V_23 -> V_29 == V_29 ) {
V_22 = ( T_10 * ) V_23 ;
} else {
for( V_40 = ( T_10 * ) V_23 ; V_40 -> V_14 ; V_40 = V_40 -> V_14 ) {
if( V_40 -> V_14 -> V_29 == V_29 ) {
V_22 = V_40 -> V_14 ;
break;
}
}
}
if( V_22 ) {
if( V_22 -> V_24 ) {
F_34 ( V_22 -> V_24 ) ;
V_22 -> V_24 = NULL ;
}
V_22 -> V_28 = TRUE ;
if( V_36 ) {
if( ! F_31 ( V_36 , & V_22 -> V_24 ) ) {
V_38 = F_29 ( L_4 ) ;
F_30 ( V_38 ,
L_6 ,
V_36 , V_39 ) ;
return V_38 ;
}
}
}
return NULL ;
}
void
F_35 ( void * V_29 )
{
T_10 * V_22 = NULL , * V_40 ;
if( ! V_23 ) {
return;
}
if( V_23 -> V_29 == V_29 ) {
V_22 = ( T_10 * ) V_23 ;
V_23 = V_23 -> V_14 ;
} else {
for( V_40 = ( T_10 * ) V_23 ; V_40 -> V_14 ; V_40 = V_40 -> V_14 ) {
if( V_40 -> V_14 -> V_29 == V_29 ) {
V_22 = V_40 -> V_14 ;
V_40 -> V_14 = V_40 -> V_14 -> V_14 ;
break;
}
}
}
if( V_22 ) {
if( V_22 -> V_24 ) {
F_34 ( V_22 -> V_24 ) ;
}
F_32 ( V_22 ) ;
}
return;
}
T_1
F_36 ( void )
{
volatile T_10 * V_41 = V_23 ;
while( V_41 ) {
if( ! ( V_41 -> V_37 & V_42 ) )
return TRUE ;
V_41 = V_41 -> V_14 ;
}
return FALSE ;
}
T_1
F_37 ( int V_12 )
{
volatile T_10 * V_41 = V_23 ;
while( V_41 ) {
if( V_41 -> V_12 == V_12 )
return TRUE ;
V_41 = V_41 -> V_14 ;
}
return FALSE ;
}
T_1
F_38 ( void )
{
T_10 * V_22 ;
for( V_22 = ( T_10 * ) V_23 ; V_22 ; V_22 = V_22 -> V_14 ) {
if( V_22 -> V_24 )
return TRUE ;
}
return FALSE ;
}
T_11
F_39 ( void )
{
T_10 * V_22 ;
T_11 V_37 = 0 ;
for( V_22 = ( T_10 * ) V_23 ; V_22 ; V_22 = V_22 -> V_14 ) {
V_37 |= V_22 -> V_37 ;
}
return V_37 ;
}
