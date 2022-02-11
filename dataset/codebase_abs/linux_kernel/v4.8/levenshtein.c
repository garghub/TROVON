int F_1 ( const char * V_1 , const char * V_2 ,
int V_3 , int V_4 , int V_5 , int V_6 )
{
int V_7 = strlen ( V_1 ) , V_8 = strlen ( V_2 ) ;
int * V_9 = malloc ( sizeof( int ) * ( V_8 + 1 ) ) ;
int * V_10 = malloc ( sizeof( int ) * ( V_8 + 1 ) ) ;
int * V_11 = malloc ( sizeof( int ) * ( V_8 + 1 ) ) ;
int V_12 , V_13 ;
for ( V_13 = 0 ; V_13 <= V_8 ; V_13 ++ )
V_10 [ V_13 ] = V_13 * V_5 ;
for ( V_12 = 0 ; V_12 < V_7 ; V_12 ++ ) {
int * V_14 ;
V_11 [ 0 ] = ( V_12 + 1 ) * V_6 ;
for ( V_13 = 0 ; V_13 < V_8 ; V_13 ++ ) {
V_11 [ V_13 + 1 ] = V_10 [ V_13 ] + V_4 * ( V_1 [ V_12 ] != V_2 [ V_13 ] ) ;
if ( V_12 > 0 && V_13 > 0 && V_1 [ V_12 - 1 ] == V_2 [ V_13 ] &&
V_1 [ V_12 ] == V_2 [ V_13 - 1 ] &&
V_11 [ V_13 + 1 ] > V_9 [ V_13 - 1 ] + V_3 )
V_11 [ V_13 + 1 ] = V_9 [ V_13 - 1 ] + V_3 ;
if ( V_11 [ V_13 + 1 ] > V_10 [ V_13 + 1 ] + V_6 )
V_11 [ V_13 + 1 ] = V_10 [ V_13 + 1 ] + V_6 ;
if ( V_11 [ V_13 + 1 ] > V_11 [ V_13 ] + V_5 )
V_11 [ V_13 + 1 ] = V_11 [ V_13 ] + V_5 ;
}
V_14 = V_9 ;
V_9 = V_10 ;
V_10 = V_11 ;
V_11 = V_14 ;
}
V_12 = V_10 [ V_8 ] ;
free ( V_9 ) ;
free ( V_10 ) ;
free ( V_11 ) ;
return V_12 ;
}
