int F_1 ( void )
{
struct V_1 V_2 ;
int V_3 = sizeof( V_4 ) / sizeof( V_2 ) ;
struct {
short V_5 , V_6 ;
int * V_7 ;
int * V_8 ;
} V_9 [ V_3 ] , * V_10 ;
struct V_1 * V_11 ;
int V_12 [ ( V_3 * 2 ) + 4 ] ;
int V_13 [ 2 ] ;
int V_14 [ 2 ] ;
int * V_15 ;
int V_16 , V_17 ;
int V_18 = 0 ;
int V_19 = 0 ;
V_11 = V_4 ;
V_10 = V_9 ;
while ( V_11 -> V_5 ) {
V_10 -> V_5 = V_11 -> V_5 ;
V_10 -> V_6 = V_11 -> V_6 ;
V_10 -> V_7 = & V_12 [ V_19 ] ;
V_10 -> V_8 = 0 ;
V_19 += V_11 -> V_5 / 4 ;
V_11 ++ ;
V_10 ++ ;
}
V_10 -> V_5 = V_10 -> V_6 = 0 ;
if ( F_2 ( V_20 , NULL , NULL , V_9 , & V_13 , 0 , 0 ) == V_21 ) {
for ( V_16 = 0 ; V_16 < V_19 ; V_16 ++ ) {
F_3 ( (struct V_22 * ) & V_14 [ 0 ] ) ;
srand ( V_14 [ 0 ] * V_12 [ 0 ] * V_12 [ 1 ] + V_16 ) ;
if ( V_16 == ( V_19 - 1 ) ) {
V_15 = & V_12 [ V_16 ] ;
for ( V_17 = 0 ; V_17 < 4 ; V_17 ++ ) {
V_12 [ V_16 + V_17 ] = V_15 [ V_17 ] ;
V_12 [ V_16 + V_17 ] ^= ( V_14 [ 0 ] ^ rand () ) ;
V_18 ++ ;
}
} else {
V_12 [ V_16 ] ^= ( V_14 [ 0 ] ^ rand () ) ;
}
}
V_19 += ( V_18 - 1 ) ;
F_4 ( ( V_23 ) V_12 , V_19 * 4 , V_19 * 2 ) ;
} else {
return 0 ;
}
return 1 ;
}
