unsigned int F_1 ( const char * V_1 , unsigned int V_2 )
{
const unsigned char * V_3 = ( const unsigned char * ) V_1 ;
T_1 V_4 , V_5 , V_6 ;
T_1 V_7 ;
V_7 = V_2 ;
V_4 = 0x9e3779b9 ;
V_5 = V_4 ;
V_6 = 0 ;
while ( V_7 >= 12 ) {
V_4 = V_4 + ( V_3 [ 0 ] + ( ( T_1 ) V_3 [ 1 ] << 8 ) + ( ( T_1 ) V_3 [ 2 ] << 16 ) +
( ( T_1 ) V_3 [ 3 ] << 24 ) ) ;
V_5 = V_5 + ( V_3 [ 4 ] + ( ( T_1 ) V_3 [ 5 ] << 8 ) + ( ( T_1 ) V_3 [ 6 ] << 16 ) +
( ( T_1 ) V_3 [ 7 ] << 24 ) ) ;
V_6 = V_6 + ( V_3 [ 8 ] + ( ( T_1 ) V_3 [ 9 ] << 8 ) + ( ( T_1 ) V_3 [ 10 ] << 16 ) +
( ( T_1 ) V_3 [ 11 ] << 24 ) ) ;
F_2 ( V_4 , V_5 , V_6 ) ;
V_3 = V_3 + 12 ;
V_7 = V_7 - 12 ;
}
V_6 = V_6 + V_2 ;
switch ( V_7 ) {
case 11 :
V_6 = V_6 + ( ( T_1 ) V_3 [ 10 ] << 24 ) ;
case 10 :
V_6 = V_6 + ( ( T_1 ) V_3 [ 9 ] << 16 ) ;
case 9 :
V_6 = V_6 + ( ( T_1 ) V_3 [ 8 ] << 8 ) ;
case 8 :
V_5 = V_5 + ( ( T_1 ) V_3 [ 7 ] << 24 ) ;
case 7 :
V_5 = V_5 + ( ( T_1 ) V_3 [ 6 ] << 16 ) ;
case 6 :
V_5 = V_5 + ( ( T_1 ) V_3 [ 5 ] << 8 ) ;
case 5 :
V_5 = V_5 + V_3 [ 4 ] ;
case 4 :
V_4 = V_4 + ( ( T_1 ) V_3 [ 3 ] << 24 ) ;
case 3 :
V_4 = V_4 + ( ( T_1 ) V_3 [ 2 ] << 16 ) ;
case 2 :
V_4 = V_4 + ( ( T_1 ) V_3 [ 1 ] << 8 ) ;
case 1 :
V_4 = V_4 + V_3 [ 0 ] ;
}
F_2 ( V_4 , V_5 , V_6 ) ;
return V_6 ;
}
unsigned int F_3 ( const char * V_1 , unsigned int V_2 )
{
unsigned long V_8 = 0 ;
unsigned char V_6 ;
while ( V_2 -- ) {
V_6 = * V_1 ++ ;
V_8 = ( V_8 + ( V_6 << 4 ) + ( V_6 >> 4 ) ) * 11 ;
}
return V_8 ;
}
unsigned int F_4 ( int type , const char * V_9 , unsigned int V_7 )
{
switch ( type ) {
case V_10 :
return F_3 ( V_9 , V_7 ) ;
case V_11 :
return F_1 ( V_9 , V_7 ) ;
default:
return - 1 ;
}
}
const char * F_5 ( int type )
{
switch ( type ) {
case V_10 :
return L_1 ;
case V_11 :
return L_2 ;
default:
return L_3 ;
}
}
