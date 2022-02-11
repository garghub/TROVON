static int F_1 ( T_1 * V_1 , int * V_2 )
{
char V_3 [ 5 + 1 ] ;
char V_4 [ 14 + 1 ] ;
T_2 V_5 ;
if ( V_1 -> V_6 != NULL ) {
if ( V_7 . V_8 == FALSE ) {
F_2 ( V_1 -> V_6 ) ;
}
F_3 ( V_1 -> V_6 ) ;
}
#ifdef F_4
F_5 () ;
#endif
V_5 = time ( NULL ) ;
F_6 ( V_3 , sizeof( V_3 ) , L_1 , ( V_7 . V_9 + 1 ) % V_10 ) ;
strftime ( V_4 , sizeof( V_4 ) , L_2 , localtime ( & V_5 ) ) ;
V_1 -> V_6 = F_7 ( V_7 . V_11 , L_3 , V_3 , L_3 , V_4 ,
V_7 . V_12 , NULL ) ;
if ( V_1 -> V_6 == NULL ) {
if ( V_2 != NULL )
* V_2 = V_13 ;
return - 1 ;
}
V_7 . V_14 = F_8 ( V_1 -> V_6 , V_15 | V_16 | V_17 | V_18 ,
V_7 . V_19 ? 0640 : 0600 ) ;
if ( V_7 . V_14 == - 1 && V_2 != NULL ) {
* V_2 = V_20 ;
}
return V_7 . V_14 ;
}
int
F_9 ( const char * V_21 , T_3 V_22 , T_4 V_19 )
{
unsigned int V_23 ;
char * V_24 , * V_25 ;
T_5 * V_26 ;
V_7 . V_27 = NULL ;
V_7 . V_9 = 0 ;
V_7 . V_11 = NULL ;
V_7 . V_12 = NULL ;
V_7 . V_8 = FALSE ;
V_7 . V_14 = - 1 ;
V_7 . V_28 = NULL ;
V_7 . V_19 = V_19 ;
if ( V_22 <= V_10 ) {
V_7 . V_22 = V_22 ;
} else {
V_7 . V_22 = V_10 ;
}
if ( V_21 == NULL ) {
return - 1 ;
}
V_26 = F_10 ( V_21 ) ;
V_25 = strrchr ( V_26 , V_29 ) ;
V_24 = strrchr ( V_26 , '.' ) ;
if ( V_24 != NULL && ( V_25 == NULL || V_24 > V_25 ) ) {
V_24 [ 0 ] = '\0' ;
V_7 . V_11 = F_10 ( V_26 ) ;
V_24 [ 0 ] = '.' ;
V_7 . V_12 = F_10 ( V_24 ) ;
} else {
V_7 . V_11 = F_10 ( V_26 ) ;
V_7 . V_12 = NULL ;
}
F_3 ( V_26 ) ;
V_26 = NULL ;
if ( V_22 == V_30 ) {
V_7 . V_8 = TRUE ;
V_7 . V_22 = 1 ;
}
V_7 . V_27 = ( T_1 * ) F_11 ( V_7 . V_22 * sizeof( T_1 ) ) ;
if ( V_7 . V_27 == NULL ) {
return - 1 ;
}
for ( V_23 = 0 ; V_23 < V_7 . V_22 ; V_23 ++ ) {
V_7 . V_27 [ V_23 ] . V_6 = NULL ;
}
if ( F_1 ( & V_7 . V_27 [ 0 ] , NULL ) == - 1 ) {
F_12 () ;
return - 1 ;
}
return V_7 . V_14 ;
}
const T_5 * F_13 ( void )
{
return V_7 . V_27 [ V_7 . V_9 % V_7 . V_22 ] . V_6 ;
}
T_6 *
F_14 ( int * V_2 )
{
V_7 . V_28 = F_15 ( V_7 . V_14 , L_4 ) ;
if ( V_7 . V_28 == NULL ) {
if ( V_2 != NULL ) {
* V_2 = V_20 ;
}
}
return V_7 . V_28 ;
}
T_4
F_16 ( T_6 * * V_28 , T_5 * * V_26 , int * V_31 , int * V_2 )
{
int V_32 ;
T_1 * V_33 = NULL ;
if ( fclose ( V_7 . V_28 ) == V_34 ) {
if ( V_2 != NULL ) {
* V_2 = V_20 ;
}
F_17 ( V_7 . V_14 ) ;
V_7 . V_28 = NULL ;
V_7 . V_14 = - 1 ;
return FALSE ;
}
V_7 . V_28 = NULL ;
V_7 . V_14 = - 1 ;
V_7 . V_9 ++ ;
V_32 = ( V_7 . V_9 ) % V_7 . V_22 ;
V_33 = & V_7 . V_27 [ V_32 ] ;
if ( F_1 ( V_33 , V_2 ) == - 1 ) {
return FALSE ;
}
if ( F_14 ( V_2 ) == NULL ) {
return FALSE ;
}
* V_26 = V_33 -> V_6 ;
* V_31 = V_7 . V_14 ;
( * V_28 ) = V_7 . V_28 ;
return TRUE ;
}
T_4
F_18 ( T_5 * * V_26 , int * V_2 )
{
T_4 V_35 = TRUE ;
if ( V_7 . V_28 != NULL ) {
if ( fclose ( V_7 . V_28 ) == V_34 ) {
if ( V_2 != NULL ) {
* V_2 = V_20 ;
}
F_17 ( V_7 . V_14 ) ;
V_35 = FALSE ;
}
V_7 . V_28 = NULL ;
V_7 . V_14 = - 1 ;
}
* V_26 = V_7 . V_27 [ V_7 . V_9 % V_7 . V_22 ] . V_6 ;
return V_35 ;
}
void
F_19 ( void )
{
unsigned int V_23 ;
if ( V_7 . V_27 != NULL ) {
for ( V_23 = 0 ; V_23 < V_7 . V_22 ; V_23 ++ ) {
if ( V_7 . V_27 [ V_23 ] . V_6 != NULL ) {
F_3 ( V_7 . V_27 [ V_23 ] . V_6 ) ;
V_7 . V_27 [ V_23 ] . V_6 = NULL ;
}
}
F_3 ( V_7 . V_27 ) ;
V_7 . V_27 = NULL ;
}
if ( V_7 . V_11 != NULL ) {
F_3 ( V_7 . V_11 ) ;
V_7 . V_11 = NULL ;
}
if ( V_7 . V_12 != NULL ) {
F_3 ( V_7 . V_12 ) ;
V_7 . V_12 = NULL ;
}
}
void
F_12 ( void )
{
unsigned int V_23 ;
if ( V_7 . V_28 != NULL ) {
if ( fclose ( V_7 . V_28 ) == 0 ) {
V_7 . V_14 = - 1 ;
}
V_7 . V_28 = NULL ;
}
if ( V_7 . V_14 != - 1 ) {
F_17 ( V_7 . V_14 ) ;
V_7 . V_14 = - 1 ;
}
if ( V_7 . V_27 != NULL ) {
for ( V_23 = 0 ; V_23 < V_7 . V_22 ; V_23 ++ ) {
if ( V_7 . V_27 [ V_23 ] . V_6 != NULL ) {
F_2 ( V_7 . V_27 [ V_23 ] . V_6 ) ;
}
}
}
F_19 () ;
}
