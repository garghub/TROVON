void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
const unsigned long V_3 , const T_1 * V_4 ,
unsigned char * V_5 , int * V_6 , const int V_7 ) {
unsigned int V_8 ;
unsigned long V_9 = V_3 ;
unsigned char V_10 ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
V_8 = * V_6 ;
if ( V_7 ) {
while ( V_9 -- ) {
if ( V_8 == 0 ) {
F_2 ( V_5 , V_5 , V_4 ) ;
}
V_5 [ V_8 ] = * ( V_2 ++ ) = * ( V_1 ++ ) ^ V_5 [ V_8 ] ;
V_8 = ( V_8 + 1 ) % V_11 ;
}
} else {
while ( V_9 -- ) {
if ( V_8 == 0 ) {
F_2 ( V_5 , V_5 , V_4 ) ;
}
V_10 = * ( V_1 ) ;
* ( V_2 ++ ) = * ( V_1 ++ ) ^ V_5 [ V_8 ] ;
V_5 [ V_8 ] = V_10 ;
V_8 = ( V_8 + 1 ) % V_11 ;
}
}
* V_6 = V_8 ;
}
