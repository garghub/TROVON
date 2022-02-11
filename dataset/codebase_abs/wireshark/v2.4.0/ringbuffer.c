static int F_1 ( T_1 * V_1 , int * V_2 )
{
char V_3 [ 5 + 1 ] ;
char V_4 [ 14 + 1 ] ;
T_2 V_5 ;
struct V_6 * V_6 ;
if ( V_1 -> V_7 != NULL ) {
if ( V_8 . V_9 == FALSE ) {
F_2 ( V_1 -> V_7 ) ;
}
F_3 ( V_1 -> V_7 ) ;
}
#ifdef F_4
F_5 () ;
#endif
V_5 = time ( NULL ) ;
F_6 ( V_3 , sizeof( V_3 ) , L_1 , ( V_8 . V_10 + 1 ) % V_11 ) ;
V_6 = localtime ( & V_5 ) ;
if ( V_6 != NULL )
strftime ( V_4 , sizeof( V_4 ) , L_2 , V_6 ) ;
else
F_7 ( V_4 , L_3 , sizeof( V_4 ) ) ;
V_1 -> V_7 = F_8 ( V_8 . V_12 , L_4 , V_3 , L_4 , V_4 ,
V_8 . V_13 , NULL ) ;
if ( V_1 -> V_7 == NULL ) {
if ( V_2 != NULL )
* V_2 = V_14 ;
return - 1 ;
}
V_8 . V_15 = F_9 ( V_1 -> V_7 , V_16 | V_17 | V_18 | V_19 ,
V_8 . V_20 ? 0640 : 0600 ) ;
if ( V_8 . V_15 == - 1 && V_2 != NULL ) {
* V_2 = V_21 ;
}
return V_8 . V_15 ;
}
int
F_10 ( const char * V_22 , T_3 V_23 , T_4 V_20 )
{
unsigned int V_24 ;
char * V_25 , * V_26 ;
T_5 * V_27 ;
V_8 . V_28 = NULL ;
V_8 . V_10 = 0 ;
V_8 . V_12 = NULL ;
V_8 . V_13 = NULL ;
V_8 . V_9 = FALSE ;
V_8 . V_15 = - 1 ;
V_8 . V_29 = NULL ;
V_8 . V_20 = V_20 ;
if ( V_23 <= V_11 ) {
V_8 . V_23 = V_23 ;
} else {
V_8 . V_23 = V_11 ;
}
if ( V_22 == NULL ) {
return - 1 ;
}
V_27 = F_11 ( V_22 ) ;
V_26 = strrchr ( V_27 , V_30 ) ;
V_25 = strrchr ( V_27 , '.' ) ;
if ( V_25 != NULL && ( V_26 == NULL || V_25 > V_26 ) ) {
V_25 [ 0 ] = '\0' ;
V_8 . V_12 = F_11 ( V_27 ) ;
V_25 [ 0 ] = '.' ;
V_8 . V_13 = F_11 ( V_25 ) ;
} else {
V_8 . V_12 = F_11 ( V_27 ) ;
V_8 . V_13 = NULL ;
}
F_3 ( V_27 ) ;
V_27 = NULL ;
if ( V_23 == V_31 ) {
V_8 . V_9 = TRUE ;
V_8 . V_23 = 1 ;
}
V_8 . V_28 = ( T_1 * ) F_12 ( V_8 . V_23 * sizeof( T_1 ) ) ;
if ( V_8 . V_28 == NULL ) {
return - 1 ;
}
for ( V_24 = 0 ; V_24 < V_8 . V_23 ; V_24 ++ ) {
V_8 . V_28 [ V_24 ] . V_7 = NULL ;
}
if ( F_1 ( & V_8 . V_28 [ 0 ] , NULL ) == - 1 ) {
F_13 () ;
return - 1 ;
}
return V_8 . V_15 ;
}
const T_5 * F_14 ( void )
{
return V_8 . V_28 [ V_8 . V_10 % V_8 . V_23 ] . V_7 ;
}
T_6 *
F_15 ( int * V_2 )
{
V_8 . V_29 = F_16 ( V_8 . V_15 , L_5 ) ;
if ( V_8 . V_29 == NULL ) {
if ( V_2 != NULL ) {
* V_2 = V_21 ;
}
}
return V_8 . V_29 ;
}
T_4
F_17 ( T_6 * * V_29 , T_5 * * V_27 , int * V_32 , int * V_2 )
{
int V_33 ;
T_1 * V_34 = NULL ;
if ( fclose ( V_8 . V_29 ) == V_35 ) {
if ( V_2 != NULL ) {
* V_2 = V_21 ;
}
F_18 ( V_8 . V_15 ) ;
V_8 . V_29 = NULL ;
V_8 . V_15 = - 1 ;
return FALSE ;
}
V_8 . V_29 = NULL ;
V_8 . V_15 = - 1 ;
V_8 . V_10 ++ ;
V_33 = ( V_8 . V_10 ) % V_8 . V_23 ;
V_34 = & V_8 . V_28 [ V_33 ] ;
if ( F_1 ( V_34 , V_2 ) == - 1 ) {
return FALSE ;
}
if ( F_15 ( V_2 ) == NULL ) {
return FALSE ;
}
* V_27 = V_34 -> V_7 ;
* V_32 = V_8 . V_15 ;
( * V_29 ) = V_8 . V_29 ;
return TRUE ;
}
T_4
F_19 ( T_5 * * V_27 , int * V_2 )
{
T_4 V_36 = TRUE ;
if ( V_8 . V_29 != NULL ) {
if ( fclose ( V_8 . V_29 ) == V_35 ) {
if ( V_2 != NULL ) {
* V_2 = V_21 ;
}
F_18 ( V_8 . V_15 ) ;
V_36 = FALSE ;
}
V_8 . V_29 = NULL ;
V_8 . V_15 = - 1 ;
}
* V_27 = V_8 . V_28 [ V_8 . V_10 % V_8 . V_23 ] . V_7 ;
return V_36 ;
}
void
F_20 ( void )
{
unsigned int V_24 ;
if ( V_8 . V_28 != NULL ) {
for ( V_24 = 0 ; V_24 < V_8 . V_23 ; V_24 ++ ) {
if ( V_8 . V_28 [ V_24 ] . V_7 != NULL ) {
F_3 ( V_8 . V_28 [ V_24 ] . V_7 ) ;
V_8 . V_28 [ V_24 ] . V_7 = NULL ;
}
}
F_3 ( V_8 . V_28 ) ;
V_8 . V_28 = NULL ;
}
if ( V_8 . V_12 != NULL ) {
F_3 ( V_8 . V_12 ) ;
V_8 . V_12 = NULL ;
}
if ( V_8 . V_13 != NULL ) {
F_3 ( V_8 . V_13 ) ;
V_8 . V_13 = NULL ;
}
}
void
F_13 ( void )
{
unsigned int V_24 ;
if ( V_8 . V_29 != NULL ) {
if ( fclose ( V_8 . V_29 ) == 0 ) {
V_8 . V_15 = - 1 ;
}
V_8 . V_29 = NULL ;
}
if ( V_8 . V_15 != - 1 ) {
F_18 ( V_8 . V_15 ) ;
V_8 . V_15 = - 1 ;
}
if ( V_8 . V_28 != NULL ) {
for ( V_24 = 0 ; V_24 < V_8 . V_23 ; V_24 ++ ) {
if ( V_8 . V_28 [ V_24 ] . V_7 != NULL ) {
F_2 ( V_8 . V_28 [ V_24 ] . V_7 ) ;
}
}
}
F_20 () ;
}
