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
F_12 () ;
if ( V_4 ) {
F_5 ( V_4 , V_5 ) ;
}
F_13 () ;
}
static T_3 *
F_14 ( void )
{
T_3 * V_7 ;
V_7 = F_15 ( T_3 , 1 ) ;
V_7 -> V_8 = NULL ;
V_7 -> V_9 = NULL ;
return V_7 ;
}
static void
F_16 ( T_4 * V_8 )
{
unsigned int V_10 ;
T_5 * V_11 ;
for ( V_10 = 0 ; V_10 < V_8 -> V_12 ; V_10 ++ ) {
V_11 = ( T_5 * ) F_17 ( V_8 , V_10 ) ;
F_18 ( V_11 ) ;
}
F_19 ( V_8 , TRUE ) ;
}
void
F_20 ( T_3 * V_7 )
{
T_6 V_10 ;
if ( ! V_7 )
return;
if ( V_7 -> V_8 ) {
F_16 ( V_7 -> V_8 ) ;
}
if ( V_7 -> V_13 ) {
F_16 ( V_7 -> V_13 ) ;
}
V_5 ( V_7 -> V_14 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_15 ; V_10 ++ ) {
if ( V_7 -> V_16 [ V_10 ] ) {
F_21 ( V_7 -> V_16 [ V_10 ] ) ;
}
}
if ( V_7 -> V_9 ) {
for ( V_10 = 0 ; V_10 < V_7 -> V_9 -> V_12 ; ++ V_10 ) {
T_7 * V_17 = ( T_7 * ) F_17 ( V_7 -> V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_19 ( V_7 -> V_9 , TRUE ) ;
}
V_5 ( V_7 -> V_16 ) ;
V_5 ( V_7 -> V_18 ) ;
V_5 ( V_7 ) ;
}
static T_1 *
F_22 ( void )
{
T_1 * V_1 ;
V_1 = F_15 ( T_1 , 1 ) ;
V_1 -> V_19 = - 1 ;
return V_1 ;
}
static void
F_23 ( T_1 * V_1 )
{
if ( V_1 -> V_20 ) {
F_24 ( V_1 -> V_20 ) ;
}
if ( V_1 -> V_21 ) {
F_25 ( V_1 -> V_21 ) ;
}
if ( V_1 -> V_14 ) {
F_25 ( V_1 -> V_14 ) ;
}
if ( V_1 -> V_8 ) {
F_16 ( V_1 -> V_8 ) ;
}
if ( V_1 -> V_13 ) {
F_16 ( V_1 -> V_13 ) ;
}
V_5 ( V_1 ) ;
}
T_8
F_26 ( const T_7 * V_22 , T_3 * * V_23 , T_7 * * V_24 )
{
T_7 * V_25 ;
int V_26 ;
T_3 * V_27 ;
T_1 * V_1 ;
T_9 V_28 ;
T_10 V_29 ;
T_11 V_30 ;
T_8 V_31 = FALSE ;
const char * V_32 ;
T_6 V_10 ;
T_4 * V_9 ;
F_27 ( V_23 ) ;
if ( ! V_22 ) {
* V_23 = NULL ;
if ( V_24 != NULL )
* V_24 = F_28 ( L_3 ) ;
return FALSE ;
}
if ( ! ( V_25 = F_29 ( V_22 , V_24 ) ) ) {
return FALSE ;
}
if ( F_30 ( & V_29 ) != 0 ) {
F_31 ( NULL , V_25 ) ;
* V_23 = NULL ;
if ( V_24 != NULL )
* V_24 = F_32 ( L_4 ,
F_33 ( V_33 ) ) ;
return FALSE ;
}
V_30 = F_34 ( V_25 , V_29 ) ;
V_1 = F_22 () ;
V_28 . V_1 = V_1 ;
V_28 . V_34 = NULL ;
F_35 ( & V_28 , V_29 ) ;
V_9 = F_36 () ;
while ( 1 ) {
V_35 = F_37 ( V_36 , NULL ) ;
V_26 = F_38 ( V_29 ) ;
if ( V_26 == V_37 ) {
V_31 = TRUE ;
break;
}
if ( V_26 == 0 ) {
break;
}
V_32 = F_39 ( V_35 ) ;
if ( V_32 ) {
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; V_10 ++ ) {
if ( F_40 ( V_32 , ( const T_7 * ) F_17 ( V_9 , V_10 ) ) == 0 ) {
V_32 = NULL ;
}
}
}
if ( V_32 ) {
F_41 ( V_9 , F_28 ( V_32 ) ) ;
}
F_42 ( V_4 , V_26 , V_35 , V_1 ) ;
V_35 = NULL ;
if ( V_1 -> V_38 ) {
V_31 = TRUE ;
break;
}
}
if ( V_35 ) {
F_24 ( V_35 ) ;
V_35 = NULL ;
}
F_42 ( V_4 , 0 , NULL , V_1 ) ;
if ( V_1 -> V_38 )
V_31 = TRUE ;
if ( V_28 . V_34 != NULL )
F_43 ( V_28 . V_34 , TRUE ) ;
F_44 ( V_30 , V_29 ) ;
F_45 ( V_29 ) ;
if ( V_31 )
goto V_39;
if ( V_1 -> V_20 == NULL ) {
* V_23 = NULL ;
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; ++ V_10 ) {
T_7 * V_17 = ( T_7 * ) F_17 ( V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_19 ( V_9 , TRUE ) ;
}
else {
if ( ! F_46 ( V_1 , V_9 ) ) {
goto V_39;
}
F_47 ( V_1 ) ;
V_27 = F_14 () ;
V_27 -> V_8 = V_1 -> V_8 ;
V_27 -> V_13 = V_1 -> V_13 ;
V_1 -> V_8 = NULL ;
V_1 -> V_13 = NULL ;
V_27 -> V_14 = F_48 ( V_1 ,
& V_27 -> V_40 ) ;
V_27 -> V_41 = V_1 -> V_19 ;
V_27 -> V_15 = V_1 -> V_42 ;
V_27 -> V_16 = F_15 ( V_43 * , V_27 -> V_15 ) ;
V_27 -> V_18 = F_15 ( T_8 , V_27 -> V_15 ) ;
F_49 ( V_27 ) ;
V_27 -> V_9 = V_9 ;
* V_23 = V_27 ;
}
V_44 = NULL ;
F_23 ( V_1 ) ;
F_31 ( NULL , V_25 ) ;
return TRUE ;
V_39:
if ( V_1 ) {
if ( V_24 != NULL )
* V_24 = V_1 -> V_3 ;
else
V_5 ( V_1 -> V_3 ) ;
V_44 = NULL ;
F_23 ( V_1 ) ;
}
for ( V_10 = 0 ; V_10 < V_9 -> V_12 ; ++ V_10 ) {
T_7 * V_17 = ( T_7 * ) F_17 ( V_9 , V_10 ) ;
V_5 ( V_17 ) ;
}
F_19 ( V_9 , TRUE ) ;
if ( V_24 != NULL ) {
if ( * V_24 == NULL )
* V_24 = F_32 ( L_5 , V_25 ) ;
}
F_31 ( NULL , V_25 ) ;
* V_23 = NULL ;
return FALSE ;
}
T_8
F_50 ( T_3 * V_7 , T_12 * V_45 )
{
return F_51 ( V_7 , V_45 ) ;
}
T_8
F_52 ( T_3 * V_7 , T_13 * V_46 )
{
return F_51 ( V_7 , V_46 -> V_45 ) ;
}
void
F_53 ( const T_3 * V_7 , T_12 * V_45 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_40 ; V_10 ++ ) {
F_54 ( V_45 , V_7 -> V_14 [ V_10 ] ) ;
}
}
T_8
F_55 ( const T_3 * V_7 )
{
return ( V_7 -> V_40 > 0 ) ;
}
T_4 *
F_56 ( T_3 * V_7 ) {
if ( V_7 -> V_9 && V_7 -> V_9 -> V_12 > 0 ) {
return V_7 -> V_9 ;
}
return NULL ;
}
void
F_57 ( T_3 * V_7 )
{
T_6 V_10 ;
const T_7 * V_47 = L_6 ;
F_58 ( stdout , V_7 ) ;
if ( V_7 -> V_9 && V_7 -> V_9 -> V_12 ) {
F_59 ( L_7 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_9 -> V_12 ; V_10 ++ ) {
F_59 ( L_8 , V_47 , ( char * ) F_17 ( V_7 -> V_9 , V_10 ) ) ;
V_47 = L_9 ;
}
F_59 ( L_10 ) ;
}
}
