T_1 *
F_1 ( const char * V_1 )
{
static T_1 * V_2 [ 3 ] ;
static int V_3 [ 3 ] ;
static int V_4 ;
if ( V_1 == NULL )
return NULL ;
V_4 = ( V_4 + 1 ) % 3 ;
if ( V_2 [ V_4 ] == NULL ) {
V_3 [ V_4 ] = V_5 ;
V_2 [ V_4 ] = F_2 ( V_3 [ V_4 ] * sizeof( T_1 ) ) ;
}
while ( F_3 ( V_6 , 0 , V_1 ,
- 1 , NULL , 0 ) >= V_3 [ V_4 ] ) {
V_3 [ V_4 ] *= 2 ;
V_2 [ V_4 ] = F_4 ( V_2 [ V_4 ] , V_3 [ V_4 ] * sizeof( T_1 ) ) ;
}
if ( F_3 ( V_6 , 0 , V_1 ,
- 1 , V_2 [ V_4 ] , V_3 [ V_4 ] ) == 0 )
return NULL ;
return V_2 [ V_4 ] ;
}
void
F_5 ( T_2 * V_2 , T_3 V_3 , const T_4 * V_7 , ... )
{
T_5 V_8 ;
T_4 * V_9 ;
va_start ( V_8 , V_7 ) ;
V_9 = F_6 ( V_7 , V_8 ) ;
va_end ( V_8 ) ;
F_7 ( V_2 , V_3 , F_8 ( L_1 ) , F_1 ( V_9 ) ) ;
F_9 ( V_9 ) ;
}
T_4 *
F_10 ( const T_1 * V_10 )
{
static T_4 * V_11 [ 3 ] ;
static int V_12 [ 3 ] ;
static int V_4 ;
if ( V_10 == NULL )
return NULL ;
V_4 = ( V_4 + 1 ) % 3 ;
if ( V_11 [ V_4 ] == NULL ) {
V_12 [ V_4 ] = V_5 ;
V_11 [ V_4 ] = F_2 ( V_12 [ V_4 ] ) ;
}
while ( F_11 ( V_6 , 0 , V_10 , - 1 ,
NULL , 0 , NULL , NULL ) >= V_12 [ V_4 ] ) {
V_12 [ V_4 ] *= 2 ;
V_11 [ V_4 ] = F_4 ( V_11 [ V_4 ] , V_12 [ V_4 ] ) ;
}
if ( F_11 ( V_6 , 0 , V_10 , - 1 ,
V_11 [ V_4 ] , V_12 [ V_4 ] , NULL , NULL ) == 0 )
return NULL ;
return V_11 [ V_4 ] ;
}
void
F_12 ( int V_13 , char * V_14 [] ) {
T_6 * V_15 ;
int V_16 , V_17 ;
V_15 = F_13 ( F_14 () , & V_16 ) ;
if ( V_15 && V_16 == V_13 ) {
for ( V_17 = 0 ; V_17 < V_13 ; V_17 ++ ) {
V_14 [ V_17 ] = F_15 ( V_15 [ V_17 ] , - 1 , NULL , NULL , NULL ) ;
}
}
}
