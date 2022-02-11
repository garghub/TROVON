void
F_1 ( T_1 * V_1 , const char * V_2 , ... )
{
T_2 args ;
if ( V_1 -> V_3 != NULL )
return;
va_start ( args , V_2 ) ;
V_1 -> V_3 = F_2 ( V_2 , args ) ;
va_end ( args ) ;
}
void
F_3 ( void )
{
if ( V_4 ) {
F_4 ( L_1 ) ;
F_5 ( V_4 , V_5 ) ;
}
V_4 = F_6 ( V_6 ) ;
#ifdef F_7
F_8 ( stdout , L_2 ) ;
#endif
F_9 () ;
F_10 () ;
}
void
F_11 ( void )
{
if ( V_4 ) {
F_5 ( V_4 , V_5 ) ;
}
F_12 () ;
}
static T_3 *
F_13 ( void )
{
T_3 * V_7 ;
V_7 = F_14 ( T_3 , 1 ) ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
return V_7 ;
}
static void
F_15 ( T_4 * V_8 )
{
unsigned int V_10 ;
T_5 * V_11 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_12 ; V_10 ++ ) {
V_11 = ( T_5 * ) F_16 ( V_8 , V_10 ) ;
F_17 ( V_11 ) ;
}
F_18 ( V_8 , TRUE ) ;
}
void
F_19 ( T_3 * V_7 )
{
T_6 V_10 ;
if ( ! V_7 )
return;
if ( V_7 -> V_8 ) {
F_15 ( V_7 -> V_8 ) ;
}
if ( V_7 -> V_13 ) {
F_15 ( V_7 -> V_13 ) ;
}
V_5 ( V_7 -> V_14 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_15 ; V_10 ++ ) {
if ( V_7 -> V_16 [ V_10 ] ) {
F_20 ( V_7 -> V_16 [ V_10 ] ) ;
}
}
if ( V_7 -> V_9 ) {
for ( V_10 = 0 ; V_10 < V_7 -> V_9 -> V_12 ; ++ V_10 ) {
T_7 * V_17 = ( T_7 * ) F_16 ( V_7 -> V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_18 ( V_7 -> V_9 , TRUE ) ;
}
V_5 ( V_7 -> V_16 ) ;
V_5 ( V_7 -> V_18 ) ;
V_5 ( V_7 ) ;
}
static T_1 *
F_21 ( void )
{
T_1 * V_1 ;
V_1 = F_14 ( T_1 , 1 ) ;
V_1 -> V_19 = - 1 ;
return V_1 ;
}
static void
F_22 ( T_1 * V_1 )
{
if ( V_1 -> V_20 ) {
F_23 ( V_1 -> V_20 ) ;
}
if ( V_1 -> V_21 ) {
F_24 ( V_1 -> V_21 ) ;
}
if ( V_1 -> V_14 ) {
F_24 ( V_1 -> V_14 ) ;
}
if ( V_1 -> V_8 ) {
F_15 ( V_1 -> V_8 ) ;
}
if ( V_1 -> V_13 ) {
F_15 ( V_1 -> V_13 ) ;
}
V_5 ( V_1 ) ;
}
T_8
F_25 ( const T_7 * V_22 , T_3 * * V_23 , T_7 * * V_24 )
{
int V_25 ;
T_3 * V_26 ;
T_1 * V_1 ;
T_8 V_27 = FALSE ;
const char * V_28 ;
T_6 V_10 ;
T_4 * V_9 ;
F_26 ( V_23 ) ;
if ( ! V_22 ) {
* V_23 = NULL ;
if ( V_24 != NULL )
* V_24 = F_27 ( L_3 ) ;
return FALSE ;
}
if ( ! ( V_22 = F_28 ( V_22 , V_24 ) ) ) {
return FALSE ;
}
V_1 = F_21 () ;
V_29 = V_1 ;
F_29 ( V_22 ) ;
V_9 = F_30 () ;
while ( 1 ) {
V_30 = F_31 ( V_31 , NULL ) ;
V_25 = F_32 () ;
if ( V_25 == V_32 ) {
V_27 = TRUE ;
break;
}
if ( V_25 == 0 ) {
break;
}
V_28 = F_33 ( V_30 ) ;
if ( V_28 ) {
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ ) {
if ( F_34 ( V_28 , ( const T_7 * ) F_16 ( V_9 , V_10 ) ) == 0 ) {
V_28 = NULL ;
}
}
}
if ( V_28 ) {
F_35 ( V_9 , F_27 ( V_28 ) ) ;
}
F_36 ( V_4 , V_25 , V_30 , V_1 ) ;
V_30 = NULL ;
if ( V_1 -> V_33 ) {
V_27 = TRUE ;
break;
}
}
if ( V_30 ) {
F_23 ( V_30 ) ;
V_30 = NULL ;
}
F_36 ( V_4 , 0 , NULL , V_1 ) ;
if ( V_1 -> V_33 )
V_27 = TRUE ;
F_37 () ;
if ( V_27 )
goto V_34;
if ( V_1 -> V_20 == NULL ) {
* V_23 = NULL ;
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; ++ V_10 ) {
T_7 * V_17 = ( T_7 * ) F_16 ( V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_18 ( V_9 , TRUE ) ;
}
else {
if ( ! F_38 ( V_1 , V_9 ) ) {
goto V_34;
}
F_39 ( V_1 ) ;
V_26 = F_13 () ;
V_26 -> V_8 = V_1 -> V_8 ;
V_26 -> V_13 = V_1 -> V_13 ;
V_1 -> V_8 = NULL ;
V_1 -> V_13 = NULL ;
V_26 -> V_14 = F_40 ( V_1 ,
& V_26 -> V_35 ) ;
V_26 -> V_36 = V_1 -> V_19 ;
V_26 -> V_15 = V_1 -> V_37 ;
V_26 -> V_16 = F_14 ( V_38 * , V_26 -> V_15 ) ;
V_26 -> V_18 = F_14 ( T_8 , V_26 -> V_15 ) ;
F_41 ( V_26 ) ;
V_26 -> V_9 = V_9 ;
* V_23 = V_26 ;
}
V_29 = NULL ;
F_22 ( V_1 ) ;
F_42 ( NULL , ( char * ) V_22 ) ;
return TRUE ;
V_34:
if ( V_1 ) {
if ( V_24 != NULL )
* V_24 = V_1 -> V_3 ;
else
V_5 ( V_1 -> V_3 ) ;
V_29 = NULL ;
F_22 ( V_1 ) ;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; ++ V_10 ) {
T_7 * V_17 = ( T_7 * ) F_16 ( V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_18 ( V_9 , TRUE ) ;
if ( V_24 != NULL ) {
if ( * V_24 == NULL )
* V_24 = F_43 ( L_4 , V_22 ) ;
}
* V_23 = NULL ;
return FALSE ;
}
T_8
F_44 ( T_3 * V_7 , T_9 * V_39 )
{
return F_45 ( V_7 , V_39 ) ;
}
T_8
F_46 ( T_3 * V_7 , T_10 * V_40 )
{
return F_45 ( V_7 , V_40 -> V_39 ) ;
}
void
F_47 ( const T_3 * V_7 , T_9 * V_39 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_35 ; V_10 ++ ) {
F_48 ( V_39 , V_7 -> V_14 [ V_10 ] ) ;
}
}
T_4 *
F_49 ( T_3 * V_7 ) {
if ( V_7 -> V_9 && V_7 -> V_9 -> V_12 > 0 ) {
return V_7 -> V_9 ;
}
return NULL ;
}
void
F_50 ( T_3 * V_7 )
{
T_6 V_10 ;
const T_7 * V_41 = L_5 ;
F_51 ( stdout , V_7 ) ;
if ( V_7 -> V_9 && V_7 -> V_9 -> V_12 ) {
printf ( L_6 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_9 -> V_12 ; V_10 ++ ) {
printf ( L_7 , V_41 , ( char * ) F_16 ( V_7 -> V_9 , V_10 ) ) ;
V_41 = L_8 ;
}
printf ( L_9 ) ;
}
}
