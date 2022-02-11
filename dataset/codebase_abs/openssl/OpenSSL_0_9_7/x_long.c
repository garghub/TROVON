static void F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
* ( long * ) V_1 = V_2 -> V_3 ;
}
static int F_2 ( T_1 * * V_1 , unsigned char * V_4 , int * V_5 , const T_2 * V_2 )
{
long V_6 ;
unsigned long V_7 ;
int V_8 , V_9 , V_10 ;
V_6 = * ( long * ) V_1 ;
if( V_6 == V_2 -> V_3 ) return - 1 ;
if( V_6 < 0 ) V_7 = - V_6 - 1 ;
else V_7 = V_6 ;
V_8 = F_3 ( V_7 ) ;
if( ! ( V_8 & 0x7 ) ) V_9 = 1 ;
else V_9 = 0 ;
V_8 = ( V_8 + 7 ) >> 3 ;
if( V_4 ) {
if( V_9 ) * V_4 ++ = ( V_6 < 0 ) ? 0xff : 0 ;
for( V_10 = V_8 - 1 ; V_10 >= 0 ; V_10 -- ) {
V_4 [ V_10 ] = ( unsigned char ) ( V_7 & 0xff ) ;
if( V_6 < 0 ) V_4 [ V_10 ] ^= 0xff ;
V_7 >>= 8 ;
}
}
return V_8 + V_9 ;
}
static int F_4 ( T_1 * * V_1 , unsigned char * V_4 , int V_11 , int V_12 , char * V_13 , const T_2 * V_2 )
{
int V_14 , V_10 ;
long V_6 ;
unsigned long V_7 = 0 ;
if( V_11 > sizeof( long ) ) {
F_5 ( V_15 , V_16 ) ;
return 0 ;
}
if( V_11 && ( V_4 [ 0 ] & 0x80 ) ) V_14 = 1 ;
else V_14 = 0 ;
V_7 = 0 ;
for( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
V_7 <<= 8 ;
if( V_14 ) V_7 |= V_4 [ V_10 ] ^ 0xff ;
else V_7 |= V_4 [ V_10 ] ;
}
V_6 = ( long ) V_7 ;
if( V_14 ) {
V_6 ++ ;
V_6 = - V_6 ;
}
if( V_6 == V_2 -> V_3 ) {
F_5 ( V_15 , V_16 ) ;
return 0 ;
}
* ( long * ) V_1 = V_6 ;
return 1 ;
}
