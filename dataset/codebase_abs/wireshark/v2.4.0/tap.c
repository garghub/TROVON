static T_1
F_1 ( T_2 * V_1 )
{
T_3 V_2 ;
void (* F_2)( void );
T_4 * V_3 ;
if ( ! F_3 ( V_1 , L_1 , & V_2 ) ) {
return FALSE ;
}
F_4 (pedantic)
F_2 = ( void ( * ) ( void ) ) V_2 ;
F_5 (pedantic)
V_3 = ( T_4 * ) F_6 ( sizeof ( T_4 ) ) ;
V_3 -> F_2 = F_2 ;
V_4 = F_7 ( V_4 , V_3 ) ;
return TRUE ;
}
void
F_8 ( void )
{
F_9 ( L_2 , F_1 ) ;
}
static void
F_10 ( T_3 V_5 , T_3 T_5 V_6 )
{
T_4 * V_3 = ( T_4 * ) V_5 ;
( V_3 -> F_2 ) ( ) ;
}
void
F_11 ( void )
{
F_12 ( V_4 , F_10 , NULL ) ;
}
static void
F_13 ( T_3 V_7 )
{
F_14 ( V_7 ) ;
}
void
F_15 ( void )
{
V_8 = 0 ;
}
int
F_16 ( const char * V_9 )
{
T_6 * V_10 , * V_11 = NULL , * V_12 ;
int V_13 = 0 ;
if( V_14 ) {
for ( V_13 = 1 , V_11 = V_14 ; V_11 ; V_13 ++ , V_12 = V_11 , V_11 = V_11 -> V_15 ) {
if ( ! strcmp ( V_11 -> V_9 , V_9 ) ) {
return V_13 ;
}
}
V_11 = V_12 ;
}
V_10 = ( T_6 * ) F_6 ( sizeof( T_6 ) ) ;
V_10 -> V_15 = NULL ;
V_10 -> V_9 = F_17 ( V_9 ) ;
if( ! V_14 ) {
V_14 = V_10 ;
V_13 = 1 ;
} else {
V_11 -> V_15 = V_10 ;
}
return V_13 ;
}
void
F_18 ( int V_16 , T_7 * V_17 , const void * V_18 )
{
T_8 * V_19 ;
if( ! V_20 ) {
return;
}
if( V_8 >= V_21 ) {
F_19 ( L_3 ) ;
return;
}
V_19 = & V_22 [ V_8 ] ;
V_19 -> V_16 = V_16 ;
V_19 -> V_23 = 0 ;
if ( V_17 -> V_23 . V_24 )
V_19 -> V_23 |= V_25 ;
V_19 -> V_17 = V_17 ;
V_19 -> V_18 = V_18 ;
V_8 ++ ;
}
void F_20 ( T_9 * V_26 )
{
volatile T_10 * V_27 ;
if( ! V_28 ) {
return;
}
for( V_27 = V_28 ; V_27 ; V_27 = V_27 -> V_15 ) {
if( V_27 -> V_29 ) {
F_21 ( V_26 , V_27 -> V_29 ) ;
}
}
}
void
F_22 ( T_9 * V_26 )
{
if( ! V_28 ) {
return;
}
V_20 = TRUE ;
V_8 = 0 ;
F_20 ( V_26 ) ;
}
void
F_23 ( T_9 * V_26 )
{
T_8 * V_30 ;
volatile T_10 * V_27 ;
T_11 V_13 ;
if( ! V_20 ) {
return;
}
V_20 = FALSE ;
if( ! V_8 ) {
return;
}
for( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
for( V_27 = V_28 ; V_27 ; V_27 = V_27 -> V_15 ) {
V_30 = & V_22 [ V_13 ] ;
if ( ! ( V_30 -> V_23 & V_25 ) || ( V_27 -> V_23 & V_31 ) )
{
if( V_30 -> V_16 == V_27 -> V_16 ) {
T_1 V_32 = TRUE ;
if( V_27 -> V_29 ) {
V_32 = F_24 ( V_27 -> V_29 , V_26 ) ;
}
if( V_32 && V_27 -> V_33 ) {
V_27 -> V_34 |= V_27 -> V_33 ( V_27 -> V_35 , V_30 -> V_17 , V_26 , V_30 -> V_18 ) ;
}
}
}
}
}
}
const void *
F_25 ( int V_16 , int V_36 )
{
T_8 * V_30 ;
T_11 V_13 ;
if( ! V_20 ) {
return NULL ;
}
if( ! V_8 ) {
return NULL ;
}
for( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_30 = & V_22 [ V_13 ] ;
if( V_30 -> V_16 == V_16 ) {
if( ! V_36 -- ) {
return V_30 -> V_18 ;
}
}
}
return NULL ;
}
void
F_26 ( void )
{
volatile T_10 * V_27 ;
for( V_27 = V_28 ; V_27 ; V_27 = V_27 -> V_15 ) {
if( V_27 -> V_37 ) {
V_27 -> V_37 ( V_27 -> V_35 ) ;
}
V_27 -> V_34 = TRUE ;
}
}
void
F_27 ( T_1 V_38 )
{
volatile T_10 * V_27 ;
for( V_27 = V_28 ; V_27 ; V_27 = V_27 -> V_15 ) {
if( V_27 -> V_34 || V_38 ) {
if( V_27 -> V_39 ) {
V_27 -> V_39 ( V_27 -> V_35 ) ;
}
}
V_27 -> V_34 = FALSE ;
}
}
T_12 *
F_28 ( void )
{
T_12 * V_40 = NULL ;
T_6 * V_10 ;
for( V_10 = V_14 ; V_10 ; V_10 = V_10 -> V_15 ) {
V_40 = F_29 ( V_40 , V_10 -> V_9 ) ;
}
return F_30 ( V_40 ) ;
}
int
F_31 ( const char * V_9 )
{
T_6 * V_10 ;
int V_13 ;
for( V_13 = 1 , V_10 = V_14 ; V_10 ; V_13 ++ , V_10 = V_10 -> V_15 ) {
if( ! strcmp ( V_10 -> V_9 , V_9 ) ) {
return V_13 ;
}
}
return 0 ;
}
static void
F_32 ( volatile T_10 * V_27 )
{
if( ! V_27 )
return;
if( V_27 -> V_29 ) {
F_33 ( V_27 -> V_29 ) ;
}
F_14 ( V_27 -> V_41 ) ;
F_4 (cast-qual)
F_14 ( ( T_3 ) V_27 ) ;
F_5 (cast-qual)
}
T_13 *
F_34 ( const char * V_42 , void * V_35 , const char * V_41 ,
T_11 V_23 , T_14 V_37 , T_15 V_33 , T_16 V_39 )
{
volatile T_10 * V_27 ;
int V_16 ;
T_17 * V_29 = NULL ;
T_13 * V_43 ;
T_18 * V_44 ;
V_16 = F_31 ( V_42 ) ;
if( ! V_16 ) {
V_43 = F_35 ( L_4 ) ;
F_36 ( V_43 , L_5 , V_42 ) ;
return V_43 ;
}
V_27 = ( volatile T_10 * ) F_37 ( sizeof( T_10 ) ) ;
V_27 -> V_34 = TRUE ;
V_27 -> V_23 = V_23 ;
if( V_41 ) {
if( ! F_38 ( V_41 , & V_29 , & V_44 ) ) {
V_43 = F_35 ( L_4 ) ;
F_36 ( V_43 ,
L_6 ,
V_41 , V_44 ) ;
F_14 ( V_44 ) ;
F_32 ( V_27 ) ;
return V_43 ;
}
}
V_27 -> V_41 = F_17 ( V_41 ) ;
V_27 -> V_29 = V_29 ;
V_27 -> V_16 = V_16 ;
V_27 -> V_35 = V_35 ;
V_27 -> V_37 = V_37 ;
V_27 -> V_33 = V_33 ;
V_27 -> V_39 = V_39 ;
V_27 -> V_15 = V_28 ;
V_28 = V_27 ;
return NULL ;
}
T_13 *
F_39 ( void * V_35 , const char * V_41 )
{
volatile T_10 * V_27 = NULL , * V_45 ;
T_17 * V_29 = NULL ;
T_13 * V_43 ;
T_18 * V_44 ;
if( ! V_28 ) {
return NULL ;
}
if( V_28 -> V_35 == V_35 ) {
V_27 = V_28 ;
} else {
for( V_45 = V_28 ; V_45 -> V_15 ; V_45 = V_45 -> V_15 ) {
if( V_45 -> V_15 -> V_35 == V_35 ) {
V_27 = V_45 -> V_15 ;
break;
}
}
}
if( V_27 ) {
if( V_27 -> V_29 ) {
F_33 ( V_27 -> V_29 ) ;
V_27 -> V_29 = NULL ;
}
V_27 -> V_34 = TRUE ;
F_14 ( V_27 -> V_41 ) ;
if( V_41 ) {
if( ! F_38 ( V_41 , & V_29 , & V_44 ) ) {
V_27 -> V_41 = NULL ;
V_43 = F_35 ( L_4 ) ;
F_36 ( V_43 ,
L_6 ,
V_41 , V_44 ) ;
F_14 ( V_44 ) ;
return V_43 ;
}
}
V_27 -> V_41 = F_17 ( V_41 ) ;
V_27 -> V_29 = V_29 ;
}
return NULL ;
}
void
F_40 ( void )
{
volatile T_10 * V_27 ;
T_17 * V_29 ;
T_18 * V_44 ;
for( V_27 = V_28 ; V_27 ; V_27 = V_27 -> V_15 ) {
if( V_27 -> V_29 ) {
F_33 ( V_27 -> V_29 ) ;
V_27 -> V_29 = NULL ;
}
V_27 -> V_34 = TRUE ;
V_29 = NULL ;
if( V_27 -> V_41 ) {
if( ! F_38 ( V_27 -> V_41 , & V_29 , & V_44 ) ) {
F_14 ( V_44 ) ;
V_44 = NULL ;
if ( ! F_38 ( L_7 , & V_29 , & V_44 ) )
F_14 ( V_44 ) ;
}
}
V_27 -> V_29 = V_29 ;
}
}
void
F_41 ( void * V_35 )
{
volatile T_10 * V_27 = NULL , * V_45 ;
if( ! V_28 ) {
return;
}
if( V_28 -> V_35 == V_35 ) {
V_27 = V_28 ;
V_28 = V_28 -> V_15 ;
} else {
for( V_45 = V_28 ; V_45 -> V_15 ; V_45 = V_45 -> V_15 ) {
if( V_45 -> V_15 -> V_35 == V_35 ) {
V_27 = V_45 -> V_15 ;
V_45 -> V_15 = V_45 -> V_15 -> V_15 ;
break;
}
}
}
F_32 ( V_27 ) ;
}
T_1
F_42 ( void )
{
volatile T_10 * V_46 = V_28 ;
while( V_46 ) {
if( ! ( V_46 -> V_23 & V_47 ) )
return TRUE ;
V_46 = V_46 -> V_15 ;
}
return FALSE ;
}
T_1
F_43 ( int V_16 )
{
volatile T_10 * V_46 = V_28 ;
while( V_46 ) {
if( V_46 -> V_16 == V_16 )
return TRUE ;
V_46 = V_46 -> V_15 ;
}
return FALSE ;
}
T_1
F_44 ( void )
{
volatile T_10 * V_27 ;
for( V_27 = V_28 ; V_27 ; V_27 = V_27 -> V_15 ) {
if( V_27 -> V_29 )
return TRUE ;
}
return FALSE ;
}
T_11
F_45 ( void )
{
volatile T_10 * V_27 ;
T_11 V_23 = 0 ;
for( V_27 = V_28 ; V_27 ; V_27 = V_27 -> V_15 ) {
V_23 |= V_27 -> V_23 ;
}
return V_23 ;
}
void F_46 ( void )
{
volatile T_10 * V_48 ;
volatile T_10 * V_49 = V_28 ;
T_6 * V_50 ;
T_6 * V_51 = V_14 ;
while( V_49 ) {
V_48 = V_49 ;
V_49 = V_49 -> V_15 ;
F_32 ( V_48 ) ;
}
while( V_51 ) {
V_50 = V_51 ;
V_51 = V_51 -> V_15 ;
F_14 ( ( char * ) V_50 -> V_9 ) ;
F_14 ( ( T_3 ) V_50 ) ;
}
#ifdef F_47
F_48 ( V_4 , F_13 ) ;
#endif
}
