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
void F_3 ( const unsigned char * V_1 , unsigned char * V_2 ,
const int V_12 , const T_1 * V_4 ,
unsigned char * V_5 , const int V_7 )
{
int V_8 , V_13 , V_6 ;
unsigned char V_14 [ V_11 * 2 ] ;
if ( V_12 <= 0 || V_12 > 128 ) return;
memcpy ( V_14 , V_5 , V_11 ) ;
F_2 ( V_5 , V_5 , V_4 ) ;
V_6 = ( V_12 + 7 ) / 8 ;
if ( V_7 )
for( V_8 = 0 ; V_8 < V_6 ; ++ V_8 )
V_2 [ V_8 ] = ( V_14 [ V_11 + V_8 ] = V_1 [ V_8 ] ^ V_5 [ V_8 ] ) ;
else
for( V_8 = 0 ; V_8 < V_6 ; ++ V_8 )
V_2 [ V_8 ] = ( V_14 [ V_11 + V_8 ] = V_1 [ V_8 ] ) ^ V_5 [ V_8 ] ;
V_13 = V_12 % 8 ;
V_6 = V_12 / 8 ;
if( V_13 == 0 )
memcpy ( V_5 , V_14 + V_6 , V_11 ) ;
else
for( V_8 = 0 ; V_8 < V_11 ; ++ V_8 )
V_5 [ V_8 ] = V_14 [ V_8 + V_6 ] << V_13 | V_14 [ V_8 + V_6 + 1 ] >> ( 8 - V_13 ) ;
}
void F_4 ( const unsigned char * V_1 , unsigned char * V_2 ,
const unsigned long V_3 , const T_1 * V_4 ,
unsigned char * V_5 , int * V_6 , const int V_7 )
{
unsigned int V_8 ;
unsigned char V_10 [ 1 ] , V_15 [ 1 ] ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
assert ( * V_6 == 0 ) ;
memset ( V_2 , 0 , ( V_3 + 7 ) / 8 ) ;
for( V_8 = 0 ; V_8 < V_3 ; ++ V_8 )
{
V_10 [ 0 ] = ( V_1 [ V_8 / 8 ] & ( 1 << ( 7 - V_8 % 8 ) ) ) ? 0x80 : 0 ;
F_3 ( V_10 , V_15 , 1 , V_4 , V_5 , V_7 ) ;
V_2 [ V_8 / 8 ] = ( V_2 [ V_8 / 8 ] & ~ ( 1 << ( 7 - V_8 % 8 ) ) ) | ( ( V_15 [ 0 ] & 0x80 ) >> ( V_8 % 8 ) ) ;
}
}
void F_5 ( const unsigned char * V_1 , unsigned char * V_2 ,
const unsigned long V_3 , const T_1 * V_4 ,
unsigned char * V_5 , int * V_6 , const int V_7 )
{
unsigned int V_8 ;
assert ( V_1 && V_2 && V_4 && V_5 && V_6 ) ;
assert ( * V_6 == 0 ) ;
for( V_8 = 0 ; V_8 < V_3 ; ++ V_8 )
F_3 ( & V_1 [ V_8 ] , & V_2 [ V_8 ] , 8 , V_4 , V_5 , V_7 ) ;
}
