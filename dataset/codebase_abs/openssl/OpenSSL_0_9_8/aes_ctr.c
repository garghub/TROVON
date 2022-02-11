static void F_1 ( unsigned char * V_1 ) {
unsigned long V_2 ;
V_2 = F_2 ( V_1 + 12 ) ;
V_2 ++ ; V_2 &= 0xFFFFFFFF ;
F_3 ( V_1 + 12 , V_2 ) ;
if ( V_2 )
return;
V_2 = F_2 ( V_1 + 8 ) ;
V_2 ++ ; V_2 &= 0xFFFFFFFF ;
F_3 ( V_1 + 8 , V_2 ) ;
if ( V_2 )
return;
V_2 = F_2 ( V_1 + 4 ) ;
V_2 ++ ; V_2 &= 0xFFFFFFFF ;
F_3 ( V_1 + 4 , V_2 ) ;
if ( V_2 )
return;
V_2 = F_2 ( V_1 + 0 ) ;
V_2 ++ ; V_2 &= 0xFFFFFFFF ;
F_3 ( V_1 + 0 , V_2 ) ;
}
void F_4 ( const unsigned char * V_3 , unsigned char * V_4 ,
const unsigned long V_5 , const T_1 * V_6 ,
unsigned char V_7 [ V_8 ] ,
unsigned char V_9 [ V_8 ] ,
unsigned int * V_10 ) {
unsigned int V_11 ;
unsigned long V_12 = V_5 ;
assert ( V_3 && V_4 && V_6 && V_1 && V_10 ) ;
assert ( * V_10 < V_8 ) ;
V_11 = * V_10 ;
while ( V_12 -- ) {
if ( V_11 == 0 ) {
F_5 ( V_7 , V_9 , V_6 ) ;
F_1 ( V_7 ) ;
}
* ( V_4 ++ ) = * ( V_3 ++ ) ^ V_9 [ V_11 ] ;
V_11 = ( V_11 + 1 ) % V_8 ;
}
* V_10 = V_11 ;
}
