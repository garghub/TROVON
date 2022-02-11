void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
const unsigned long V_3 , const T_1 * V_4 ,
unsigned char * V_5 , const int V_6 ) {
unsigned long V_7 ;
unsigned long V_8 = V_3 ;
unsigned char V_9 [ V_10 ] ;
const unsigned char * V_11 = V_5 ;
assert ( V_1 && V_2 && V_4 && V_5 ) ;
assert ( ( V_12 == V_6 ) || ( V_13 == V_6 ) ) ;
if ( V_12 == V_6 ) {
while ( V_8 >= V_10 ) {
for( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
V_2 [ V_7 ] = V_1 [ V_7 ] ^ V_11 [ V_7 ] ;
F_2 ( V_2 , V_2 , V_4 ) ;
V_11 = V_2 ;
V_8 -= V_10 ;
V_1 += V_10 ;
V_2 += V_10 ;
}
if ( V_8 ) {
for( V_7 = 0 ; V_7 < V_8 ; ++ V_7 )
V_2 [ V_7 ] = V_1 [ V_7 ] ^ V_11 [ V_7 ] ;
for( V_7 = V_8 ; V_7 < V_10 ; ++ V_7 )
V_2 [ V_7 ] = V_11 [ V_7 ] ;
F_2 ( V_2 , V_2 , V_4 ) ;
V_11 = V_2 ;
}
memcpy ( V_5 , V_11 , V_10 ) ;
} else if ( V_1 != V_2 ) {
while ( V_8 >= V_10 ) {
F_3 ( V_1 , V_2 , V_4 ) ;
for( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
V_2 [ V_7 ] ^= V_11 [ V_7 ] ;
V_11 = V_1 ;
V_8 -= V_10 ;
V_1 += V_10 ;
V_2 += V_10 ;
}
if ( V_8 ) {
F_3 ( V_1 , V_9 , V_4 ) ;
for( V_7 = 0 ; V_7 < V_8 ; ++ V_7 )
V_2 [ V_7 ] = V_9 [ V_7 ] ^ V_11 [ V_7 ] ;
V_11 = V_1 ;
}
memcpy ( V_5 , V_11 , V_10 ) ;
} else {
while ( V_8 >= V_10 ) {
memcpy ( V_9 , V_1 , V_10 ) ;
F_3 ( V_1 , V_2 , V_4 ) ;
for( V_7 = 0 ; V_7 < V_10 ; ++ V_7 )
V_2 [ V_7 ] ^= V_5 [ V_7 ] ;
memcpy ( V_5 , V_9 , V_10 ) ;
V_8 -= V_10 ;
V_1 += V_10 ;
V_2 += V_10 ;
}
if ( V_8 ) {
memcpy ( V_9 , V_1 , V_10 ) ;
F_3 ( V_9 , V_2 , V_4 ) ;
for( V_7 = 0 ; V_7 < V_8 ; ++ V_7 )
V_2 [ V_7 ] ^= V_5 [ V_7 ] ;
for( V_7 = V_8 ; V_7 < V_10 ; ++ V_7 )
V_2 [ V_7 ] = V_9 [ V_7 ] ;
memcpy ( V_5 , V_9 , V_10 ) ;
}
}
}
