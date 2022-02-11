void
F_1 ( void )
{
V_1 = 0 ;
return;
}
int
F_2 ( const char * V_2 )
{
T_1 * V_3 , * V_4 ;
int V_5 , V_6 ;
if( V_7 ) {
V_6 = F_3 ( V_2 ) ;
if ( V_6 )
return V_6 ;
}
V_3 = ( T_1 * ) F_4 ( sizeof( T_1 ) ) ;
V_3 -> V_8 = NULL ;
V_3 -> V_2 = F_5 ( V_2 ) ;
if( ! V_7 ) {
V_7 = V_3 ;
V_5 = 1 ;
} else {
for( V_5 = 2 , V_4 = V_7 ; V_4 -> V_8 ; V_5 ++ , V_4 = V_4 -> V_8 )
;
V_4 -> V_8 = V_3 ;
}
return V_5 ;
}
void
F_6 ( int V_6 , T_2 * V_9 , const void * V_10 )
{
T_3 * V_11 ;
if( ! V_12 ) {
return;
}
if( V_1 >= V_13 ) {
F_7 ( L_1 ) ;
return;
}
V_11 = & V_14 [ V_1 ] ;
V_11 -> V_6 = V_6 ;
V_11 -> V_9 = V_9 ;
V_11 -> V_10 = V_10 ;
V_1 ++ ;
}
void F_8 ( T_4 * V_15 )
{
T_5 * V_16 ;
if( ! V_17 ) {
return;
}
for( V_16 = ( T_5 * ) V_17 ; V_16 ; V_16 = V_16 -> V_8 ) {
if( V_16 -> V_18 ) {
F_9 ( V_15 , V_16 -> V_18 ) ;
}
}
}
void
F_10 ( T_4 * V_15 )
{
if( ! V_17 ) {
return;
}
V_12 = TRUE ;
V_1 = 0 ;
F_8 ( V_15 ) ;
}
void
F_11 ( T_4 * V_15 )
{
T_3 * V_19 ;
T_5 * V_16 ;
T_6 V_5 ;
if( ! V_12 ) {
return;
}
V_12 = FALSE ;
if( ! V_1 ) {
return;
}
for( V_5 = 0 ; V_5 < V_1 ; V_5 ++ ) {
for( V_16 = ( T_5 * ) V_17 ; V_16 ; V_16 = V_16 -> V_8 ) {
V_19 = & V_14 [ V_5 ] ;
if( V_19 -> V_6 == V_16 -> V_6 ) {
T_7 V_20 = TRUE ;
if( V_16 -> V_18 ) {
V_20 = F_12 ( V_16 -> V_18 , V_15 ) ;
}
if( V_20 && V_16 -> V_21 ) {
V_16 -> V_22 |= V_16 -> V_21 ( V_16 -> V_23 , V_19 -> V_9 , V_15 , V_19 -> V_10 ) ;
}
}
}
}
}
const void *
F_13 ( int V_6 , int V_24 )
{
T_3 * V_19 ;
T_6 V_5 ;
if( ! V_12 ) {
return NULL ;
}
if( ! V_1 ) {
return NULL ;
}
for( V_5 = 0 ; V_5 < V_1 ; V_5 ++ ) {
V_19 = & V_14 [ V_5 ] ;
if( V_19 -> V_6 == V_6 ) {
if( ! V_24 -- ) {
return V_19 -> V_10 ;
}
}
}
return NULL ;
}
void
F_14 ( void )
{
T_5 * V_16 ;
for( V_16 = ( T_5 * ) V_17 ; V_16 ; V_16 = V_16 -> V_8 ) {
if( V_16 -> V_25 ) {
V_16 -> V_25 ( V_16 -> V_23 ) ;
}
V_16 -> V_22 = TRUE ;
}
}
void
F_15 ( T_7 V_26 )
{
T_5 * V_16 ;
for( V_16 = ( T_5 * ) V_17 ; V_16 ; V_16 = V_16 -> V_8 ) {
if( V_16 -> V_22 || V_26 ) {
if( V_16 -> V_27 ) {
V_16 -> V_27 ( V_16 -> V_23 ) ;
}
}
V_16 -> V_22 = FALSE ;
}
}
int
F_3 ( const char * V_2 )
{
T_1 * V_3 ;
int V_5 ;
for( V_5 = 1 , V_3 = V_7 ; V_3 ; V_5 ++ , V_3 = V_3 -> V_8 ) {
if( ! strcmp ( V_3 -> V_2 , V_2 ) ) {
return V_5 ;
}
}
return 0 ;
}
T_8 *
F_16 ( const char * V_28 , void * V_23 , const char * V_29 ,
T_6 V_30 , T_9 V_25 , T_10 V_21 , T_11 V_27 )
{
T_5 * V_16 ;
int V_6 ;
T_8 * V_31 ;
V_6 = F_3 ( V_28 ) ;
if( ! V_6 ) {
V_31 = F_17 ( L_2 ) ;
F_18 ( V_31 , L_3 , V_28 ) ;
return V_31 ;
}
V_16 = ( T_5 * ) F_4 ( sizeof( T_5 ) ) ;
V_16 -> V_18 = NULL ;
V_16 -> V_22 = TRUE ;
V_16 -> V_30 = V_30 ;
if( V_29 ) {
if( ! F_19 ( V_29 , & V_16 -> V_18 ) ) {
V_31 = F_17 ( L_2 ) ;
F_18 ( V_31 ,
L_4 ,
V_29 , V_32 ) ;
F_20 ( V_16 ) ;
return V_31 ;
}
}
V_16 -> V_6 = V_6 ;
V_16 -> V_23 = V_23 ;
V_16 -> V_25 = V_25 ;
V_16 -> V_21 = V_21 ;
V_16 -> V_27 = V_27 ;
V_16 -> V_8 = ( T_5 * ) V_17 ;
V_17 = V_16 ;
return NULL ;
}
T_8 *
F_21 ( void * V_23 , const char * V_29 )
{
T_5 * V_16 = NULL , * V_33 ;
T_8 * V_31 ;
if( ! V_17 ) {
return NULL ;
}
if( V_17 -> V_23 == V_23 ) {
V_16 = ( T_5 * ) V_17 ;
} else {
for( V_33 = ( T_5 * ) V_17 ; V_33 -> V_8 ; V_33 = V_33 -> V_8 ) {
if( V_33 -> V_8 -> V_23 == V_23 ) {
V_16 = V_33 -> V_8 ;
break;
}
}
}
if( V_16 ) {
if( V_16 -> V_18 ) {
F_22 ( V_16 -> V_18 ) ;
V_16 -> V_18 = NULL ;
}
V_16 -> V_22 = TRUE ;
if( V_29 ) {
if( ! F_19 ( V_29 , & V_16 -> V_18 ) ) {
V_31 = F_17 ( L_2 ) ;
F_18 ( V_31 ,
L_4 ,
V_29 , V_32 ) ;
return V_31 ;
}
}
}
return NULL ;
}
void
F_23 ( void * V_23 )
{
T_5 * V_16 = NULL , * V_33 ;
if( ! V_17 ) {
return;
}
if( V_17 -> V_23 == V_23 ) {
V_16 = ( T_5 * ) V_17 ;
V_17 = V_17 -> V_8 ;
} else {
for( V_33 = ( T_5 * ) V_17 ; V_33 -> V_8 ; V_33 = V_33 -> V_8 ) {
if( V_33 -> V_8 -> V_23 == V_23 ) {
V_16 = V_33 -> V_8 ;
V_33 -> V_8 = V_33 -> V_8 -> V_8 ;
break;
}
}
}
if( V_16 ) {
if( V_16 -> V_18 ) {
F_22 ( V_16 -> V_18 ) ;
}
F_20 ( V_16 ) ;
}
return;
}
T_7
F_24 ( void )
{
volatile T_5 * V_34 = V_17 ;
while( V_34 ) {
if( ! ( V_34 -> V_30 & V_35 ) )
return TRUE ;
V_34 = V_34 -> V_8 ;
}
return FALSE ;
}
T_7
F_25 ( int V_6 )
{
volatile T_5 * V_34 = V_17 ;
while( V_34 ) {
if( V_34 -> V_6 == V_6 )
return TRUE ;
V_34 = V_34 -> V_8 ;
}
return FALSE ;
}
T_7
F_26 ( void )
{
T_5 * V_16 ;
for( V_16 = ( T_5 * ) V_17 ; V_16 ; V_16 = V_16 -> V_8 ) {
if( V_16 -> V_18 )
return TRUE ;
}
return FALSE ;
}
T_6
F_27 ( void )
{
T_5 * V_16 ;
T_6 V_30 = 0 ;
for( V_16 = ( T_5 * ) V_17 ; V_16 ; V_16 = V_16 -> V_8 ) {
V_30 |= V_16 -> V_30 ;
}
return V_30 ;
}
