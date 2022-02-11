void
F_1 ( const char * V_1 , ... )
{
T_1 args ;
if ( V_2 != NULL )
return;
va_start ( args , V_1 ) ;
F_2 ( V_3 , sizeof( V_3 ) ,
V_1 , args ) ;
V_2 = V_3 ;
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
static T_2 *
F_13 ( void )
{
T_2 * V_7 ;
V_7 = F_14 ( T_2 , 1 ) ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
return V_7 ;
}
static void
F_15 ( T_3 * V_8 )
{
unsigned int V_10 ;
T_4 * V_11 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_12 ; V_10 ++ ) {
V_11 = ( T_4 * ) F_16 ( V_8 , V_10 ) ;
F_17 ( V_11 ) ;
}
F_18 ( V_8 , TRUE ) ;
}
void
F_19 ( T_2 * V_7 )
{
T_5 V_10 ;
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
T_6 * V_17 = ( T_6 * ) F_16 ( V_7 -> V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_18 ( V_7 -> V_9 , TRUE ) ;
}
V_5 ( V_7 -> V_16 ) ;
V_5 ( V_7 -> V_18 ) ;
V_5 ( V_7 ) ;
}
static T_7 *
F_21 ( void )
{
T_7 * V_19 ;
V_19 = F_14 ( T_7 , 1 ) ;
V_19 -> V_20 = - 1 ;
return V_19 ;
}
static void
F_22 ( T_7 * V_19 )
{
if ( V_19 -> V_21 ) {
F_23 ( V_19 -> V_21 ) ;
}
if ( V_19 -> V_22 ) {
F_24 ( V_19 -> V_22 ) ;
}
if ( V_19 -> V_14 ) {
F_24 ( V_19 -> V_14 ) ;
}
if ( V_19 -> V_8 ) {
F_15 ( V_19 -> V_8 ) ;
}
if ( V_19 -> V_13 ) {
F_15 ( V_19 -> V_13 ) ;
}
V_5 ( V_19 ) ;
}
T_8
F_25 ( const T_6 * V_23 , T_2 * * V_24 )
{
int V_25 ;
T_2 * V_26 ;
T_7 * V_19 ;
T_8 V_27 = FALSE ;
const char * V_28 ;
T_5 V_10 ;
T_3 * V_9 ;
F_26 ( V_24 ) ;
if ( ! V_23 ) {
* V_24 = NULL ;
return FALSE ;
}
V_2 = NULL ;
if ( ! ( V_23 = F_27 ( V_23 , & V_2 ) ) ) {
return FALSE ;
}
V_19 = F_21 () ;
F_28 ( V_23 ) ;
V_9 = F_29 () ;
while ( 1 ) {
V_29 = F_30 ( V_30 , NULL ) ;
V_25 = F_31 () ;
if ( V_25 == V_31 ) {
V_27 = TRUE ;
break;
}
if ( V_25 == 0 ) {
break;
}
V_28 = F_32 ( V_29 ) ;
if ( V_28 ) {
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ ) {
if ( F_33 ( V_28 , ( const T_6 * ) F_16 ( V_9 , V_10 ) ) == 0 ) {
V_28 = NULL ;
}
}
}
if ( V_28 ) {
F_34 ( V_9 , F_35 ( V_28 ) ) ;
}
F_36 ( V_4 , V_25 , V_29 , V_19 ) ;
V_29 = NULL ;
if ( V_19 -> V_32 ) {
V_27 = TRUE ;
break;
}
}
if ( V_29 ) {
F_23 ( V_29 ) ;
V_29 = NULL ;
}
F_36 ( V_4 , 0 , NULL , V_19 ) ;
if ( V_19 -> V_32 )
V_27 = TRUE ;
F_37 () ;
if ( V_27 )
goto V_33;
if ( V_19 -> V_21 == NULL ) {
* V_24 = NULL ;
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; ++ V_10 ) {
T_6 * V_17 = ( T_6 * ) F_16 ( V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_18 ( V_9 , TRUE ) ;
}
else {
if ( ! F_38 ( V_19 , V_9 ) ) {
goto V_33;
}
F_39 ( V_19 ) ;
V_26 = F_13 () ;
V_26 -> V_8 = V_19 -> V_8 ;
V_26 -> V_13 = V_19 -> V_13 ;
V_19 -> V_8 = NULL ;
V_19 -> V_13 = NULL ;
V_26 -> V_14 = F_40 ( V_19 ,
& V_26 -> V_34 ) ;
V_26 -> V_35 = V_19 -> V_20 ;
V_26 -> V_15 = V_19 -> V_36 ;
V_26 -> V_16 = F_14 ( V_37 * , V_26 -> V_15 ) ;
V_26 -> V_18 = F_14 ( T_8 , V_26 -> V_15 ) ;
F_41 ( V_26 ) ;
V_26 -> V_9 = V_9 ;
* V_24 = V_26 ;
}
F_22 ( V_19 ) ;
return TRUE ;
V_33:
if ( V_19 ) {
F_22 ( V_19 ) ;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; ++ V_10 ) {
T_6 * V_17 = ( T_6 * ) F_16 ( V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_18 ( V_9 , TRUE ) ;
F_1 ( L_3 , V_23 ) ;
* V_24 = NULL ;
return FALSE ;
}
T_8
F_42 ( T_2 * V_7 , T_9 * V_38 )
{
return F_43 ( V_7 , V_38 ) ;
}
T_8
F_44 ( T_2 * V_7 , T_10 * V_39 )
{
return F_43 ( V_7 , V_39 -> V_38 ) ;
}
void
F_45 ( const T_2 * V_7 , T_9 * V_38 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_34 ; V_10 ++ ) {
F_46 ( V_38 , V_7 -> V_14 [ V_10 ] ) ;
}
}
T_3 *
F_47 ( T_2 * V_7 ) {
if ( V_7 -> V_9 && V_7 -> V_9 -> V_12 > 0 ) {
return V_7 -> V_9 ;
}
return NULL ;
}
void
F_48 ( T_2 * V_7 )
{
T_5 V_10 ;
const T_6 * V_40 = L_4 ;
F_49 ( stdout , V_7 ) ;
if ( V_7 -> V_9 && V_7 -> V_9 -> V_12 ) {
printf ( L_5 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_9 -> V_12 ; V_10 ++ ) {
printf ( L_6 , V_40 , ( char * ) F_16 ( V_7 -> V_9 , V_10 ) ) ;
V_40 = L_7 ;
}
printf ( L_8 ) ;
}
}
