static T_1
F_1 ( const T_2 * V_1 , T_3 * V_2 )
{
int V_3 ;
T_4 V_4 ;
int V_5 ;
T_5 V_6 ;
T_6 * V_7 ;
V_3 = F_2 ( V_1 , V_8 | V_9 | V_10 | V_11 , 0644 ) ;
if( V_3 == - 1 ) {
return FALSE ;
}
V_7 = V_2 -> V_12 ;
V_4 = V_2 -> V_13 ;
while ( V_4 != 0 ) {
if ( V_4 > 0x40000000 )
V_5 = 0x40000000 ;
else
V_5 = ( int ) V_4 ;
V_6 = F_3 ( V_3 , V_7 , V_5 ) ;
if( V_6 <= 0 ) {
F_4 ( V_3 ) ;
return FALSE ;
}
V_4 -= V_6 ;
V_7 += V_6 ;
}
if ( F_4 ( V_3 ) < 0 ) {
return FALSE ;
}
return TRUE ;
}
static T_1
F_5 ( const void * V_14 , void * T_7 V_15 , void * T_8 V_15 )
{
fprintf ( V_16 , L_1 , ( T_2 * ) V_14 ) ;
return FALSE ;
}
void F_6 ( void )
{
F_7 ( F_5 , NULL ) ;
}
T_1 F_8 ( const char * V_17 )
{
T_2 * * V_18 ;
if ( ! V_19 )
V_19 = F_9 ( V_20 , V_21 ) ;
V_18 = F_10 ( V_17 , L_2 , 2 ) ;
if ( ( V_18 [ 0 ] == NULL ) || ( V_18 [ 1 ] == NULL ) || ( F_11 ( V_18 [ 0 ] ) == NULL ) )
{
fprintf ( V_16 , L_3 ) ;
fprintf ( V_16 , L_4 ) ;
F_6 () ;
}
else
{
T_2 * V_22 = ( T_2 * ) F_12 ( V_19 , V_18 [ 0 ] ) ;
if ( V_22 == NULL ) {
F_13 ( V_19 , V_18 [ 0 ] , V_18 [ 1 ] ) ;
F_14 ( V_18 ) ;
return TRUE ;
}
else
{
fprintf ( V_16 , L_5 , V_18 [ 0 ] ) ;
}
}
F_15 ( V_18 ) ;
return FALSE ;
}
static void
F_16 ( void * V_23 , T_3 * V_2 )
{
T_9 * V_24 = ( T_9 * ) V_23 ;
V_24 -> V_25 = F_17 ( V_24 -> V_25 , V_2 ) ;
}
static T_3 *
F_18 ( void * V_23 , int V_26 ) {
T_9 * V_24 = ( T_9 * ) V_23 ;
return ( T_3 * ) F_19 ( V_24 -> V_25 , V_26 ) ;
}
static void
F_20 ( void * V_27 )
{
T_10 * V_28 = ( T_10 * ) V_27 ;
T_9 * V_24 = ( T_9 * ) V_28 -> V_23 ;
T_11 * V_29 = V_24 -> V_25 ;
T_3 * V_2 ;
T_1 V_30 = TRUE ;
T_2 * V_31 = ( T_2 * ) F_12 ( V_19 , F_21 ( F_22 ( V_24 -> V_32 ) ) ) ;
T_12 * V_33 = NULL ;
T_2 * V_34 = NULL ;
int V_35 = 0 ;
if ( ! F_23 ( V_31 , V_36 ) ) {
if ( F_24 ( V_31 , 0755 ) == - 1 ) {
fprintf ( V_16 , L_6 ,
V_31 , F_25 ( V_37 ) ) ;
return;
}
}
if ( ( strlen ( V_31 ) < V_38 ) ) {
while ( V_29 ) {
V_2 = ( T_3 * ) V_29 -> V_39 ;
do {
F_14 ( V_34 ) ;
if ( V_2 -> V_40 ) {
V_33 = F_26 ( V_2 -> V_40 ,
V_38 - strlen ( V_31 ) , V_35 ) ;
} else {
char V_41 [ V_38 + 1 ] ;
const char * V_42 ;
V_42 = F_27 ( V_2 -> V_43 ) ;
F_28 ( V_41 , sizeof( V_41 ) ,
L_7 , V_2 -> V_44 , V_42 ? L_8 : L_9 , V_42 ? V_42 : L_9 ) ;
V_33 = F_26 ( V_41 ,
V_38 - strlen ( V_31 ) , V_35 ) ;
}
V_34 = F_29 ( V_31 , V_33 -> V_45 , NULL ) ;
F_30 ( V_33 , TRUE ) ;
} while ( F_23 ( V_34 , V_46 ) && ++ V_35 < 1000 );
V_35 = 0 ;
if ( ! F_1 ( V_34 , V_2 ) )
V_30 = FALSE ;
F_14 ( V_34 ) ;
V_34 = NULL ;
V_29 = V_29 -> V_47 ;
}
}
else
{
V_30 = FALSE ;
}
if ( ! V_30 )
fprintf ( V_16 , L_10 ,
F_21 ( F_22 ( V_24 -> V_32 ) ) ) ;
}
static void
F_31 ( T_13 V_14 , T_13 T_7 V_15 , T_13 T_14 V_15 )
{
T_12 * V_48 ;
T_10 * V_49 ;
T_9 * V_24 ;
T_15 * V_32 ;
V_32 = F_11 ( ( const char * ) V_14 ) ;
if ( V_32 == NULL )
{
fprintf ( V_16 , L_11 , ( const char * ) V_14 ) ;
return;
}
V_49 = F_32 ( T_10 , 1 ) ;
V_24 = F_32 ( T_9 , 1 ) ;
V_49 -> V_50 = F_16 ;
V_49 -> V_51 = F_18 ;
V_49 -> V_23 = ( void * ) V_24 ;
V_24 -> V_32 = V_32 ;
V_48 = F_33 ( F_34 ( V_32 ) , V_49 , NULL , 0 ,
NULL , F_35 ( V_32 ) , F_20 ) ;
if ( V_48 ) {
fprintf ( V_16 , L_12 , ( const char * ) V_14 , V_48 -> V_45 ) ;
F_30 ( V_48 , TRUE ) ;
F_14 ( V_49 ) ;
F_14 ( V_24 ) ;
return;
}
}
void F_36 ( void )
{
if ( V_19 != NULL )
F_37 ( V_19 , F_31 , NULL ) ;
}
