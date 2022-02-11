static void F_1 ( unsigned char * V_1 ) {
unsigned long V_2 ;
#ifdef F_2
V_2 = F_3 ( V_1 + 8 ) ;
V_2 ++ ;
F_4 ( V_1 + 8 , V_2 ) ;
#else
V_2 = F_3 ( V_1 + 4 ) ;
V_2 ++ ;
F_4 ( V_1 + 4 , V_2 ) ;
#endif
if ( V_2 )
return;
#ifdef F_2
V_2 = F_3 ( V_1 + 12 ) ;
V_2 ++ ;
F_4 ( V_1 + 12 , V_2 ) ;
#else
V_2 = F_3 ( V_1 + 0 ) ;
V_2 ++ ;
F_4 ( V_1 + 0 , V_2 ) ;
#endif
}
void F_5 ( const unsigned char * V_3 , unsigned char * V_4 ,
const unsigned long V_5 , const T_1 * V_6 ,
unsigned char V_1 [ V_7 ] ,
unsigned char V_8 [ V_7 ] ,
unsigned int * V_9 ) {
unsigned int V_10 ;
unsigned long V_11 = V_5 ;
assert ( V_3 && V_4 && V_6 && V_1 && V_9 ) ;
assert ( * V_9 < V_7 ) ;
V_10 = * V_9 ;
while ( V_11 -- ) {
if ( V_10 == 0 ) {
F_6 ( V_1 , V_8 , V_6 ) ;
F_1 ( V_1 ) ;
}
* ( V_4 ++ ) = * ( V_3 ++ ) ^ V_8 [ V_10 ] ;
V_10 = ( V_10 + 1 ) % V_7 ;
}
* V_9 = V_10 ;
}
