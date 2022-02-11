int
F_1 ( T_1 V_1 )
{
if ( V_1 >= 0xfe ) return - 1 ;
if ( V_1 >= 0xfc ) return 6 ;
if ( V_1 >= 0xf8 ) return 5 ;
if ( V_1 >= 0xf0 ) return 4 ;
if ( V_1 >= 0xe0 ) return 3 ;
if ( V_1 >= 0xc0 ) return 2 ;
else return 1 ;
}
T_2 *
F_2 ( const char * V_2 )
{
static T_2 * V_3 [ 3 ] ;
static int V_4 [ 3 ] ;
static int V_5 ;
if ( V_2 == NULL )
return NULL ;
V_5 = ( V_5 + 1 ) % 3 ;
if ( V_3 [ V_5 ] == NULL ) {
V_4 [ V_5 ] = V_6 ;
V_3 [ V_5 ] = F_3 ( V_4 [ V_5 ] * sizeof( T_2 ) ) ;
}
while ( F_4 ( V_7 , 0 , V_2 ,
- 1 , NULL , 0 ) >= V_4 [ V_5 ] ) {
V_4 [ V_5 ] *= 2 ;
V_3 [ V_5 ] = F_5 ( V_3 [ V_5 ] , V_4 [ V_5 ] * sizeof( T_2 ) ) ;
}
if ( F_4 ( V_7 , 0 , V_2 ,
- 1 , V_3 [ V_5 ] , V_4 [ V_5 ] ) == 0 )
return NULL ;
return V_3 [ V_5 ] ;
}
void
F_6 ( T_3 * V_3 , T_4 V_4 , const T_5 * V_8 , ... )
{
T_6 V_9 ;
T_5 * V_10 ;
va_start ( V_9 , V_8 ) ;
V_10 = F_7 ( V_8 , V_9 ) ;
va_end ( V_9 ) ;
F_8 ( V_3 , V_4 , F_9 ( L_1 ) , F_2 ( V_10 ) ) ;
F_10 ( V_10 ) ;
}
T_5 *
F_11 ( const T_2 * V_11 )
{
static T_5 * V_12 [ 3 ] ;
static int V_13 [ 3 ] ;
static int V_5 ;
if ( V_11 == NULL )
return NULL ;
V_5 = ( V_5 + 1 ) % 3 ;
if ( V_12 [ V_5 ] == NULL ) {
V_13 [ V_5 ] = V_6 ;
V_12 [ V_5 ] = F_3 ( V_13 [ V_5 ] ) ;
}
while ( F_12 ( V_7 , 0 , V_11 , - 1 ,
NULL , 0 , NULL , NULL ) >= V_13 [ V_5 ] ) {
V_13 [ V_5 ] *= 2 ;
V_12 [ V_5 ] = F_5 ( V_12 [ V_5 ] , V_13 [ V_5 ] ) ;
}
if ( F_12 ( V_7 , 0 , V_11 , - 1 ,
V_12 [ V_5 ] , V_13 [ V_5 ] , NULL , NULL ) == 0 )
return NULL ;
return V_12 [ V_5 ] ;
}
void
F_13 ( int V_14 , char * V_15 [] ) {
T_7 * V_16 ;
int V_17 , V_18 ;
V_16 = F_14 ( F_15 () , & V_17 ) ;
if ( V_16 && V_17 == V_14 ) {
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
V_15 [ V_18 ] = F_16 ( V_16 [ V_18 ] , - 1 , NULL , NULL , NULL ) ;
}
}
}
