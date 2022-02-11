void F_1 ( const unsigned char * V_1 , unsigned char * V_2 ,
const unsigned long V_3 , const T_1 * V_4 ,
unsigned char * V_5 , int * V_6 ) {
unsigned int V_7 ;
unsigned long V_8 = V_3 ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
V_7 = * V_6 ;
while ( V_8 -- ) {
if ( V_7 == 0 ) {
F_2 ( V_5 , V_5 , V_4 ) ;
}
* ( V_2 ++ ) = * ( V_1 ++ ) ^ V_5 [ V_7 ] ;
V_7 = ( V_7 + 1 ) % V_9 ;
}
* V_6 = V_7 ;
}
