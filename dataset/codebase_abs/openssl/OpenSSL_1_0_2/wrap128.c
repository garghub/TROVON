T_1 F_1 ( void * V_1 , const unsigned char * V_2 ,
unsigned char * V_3 ,
const unsigned char * V_4 , T_1 V_5 ,
T_2 V_6 )
{
unsigned char * V_7 , V_8 [ 16 ] , * V_9 ;
T_1 V_10 , V_11 , V_12 ;
if ( ( V_5 & 0x7 ) || ( V_5 < 8 ) || ( V_5 > V_13 ) )
return 0 ;
V_7 = V_8 ;
V_12 = 1 ;
memcpy ( V_3 + 8 , V_4 , V_5 ) ;
if ( ! V_2 )
V_2 = V_14 ;
memcpy ( V_7 , V_2 , 8 ) ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
V_9 = V_3 + 8 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 += 8 , V_12 ++ , V_9 += 8 ) {
memcpy ( V_8 + 8 , V_9 , 8 ) ;
V_6 ( V_8 , V_8 , V_1 ) ;
V_7 [ 7 ] ^= ( unsigned char ) ( V_12 & 0xff ) ;
if ( V_12 > 0xff ) {
V_7 [ 6 ] ^= ( unsigned char ) ( ( V_12 >> 8 ) & 0xff ) ;
V_7 [ 5 ] ^= ( unsigned char ) ( ( V_12 >> 16 ) & 0xff ) ;
V_7 [ 4 ] ^= ( unsigned char ) ( ( V_12 >> 24 ) & 0xff ) ;
}
memcpy ( V_9 , V_8 + 8 , 8 ) ;
}
}
memcpy ( V_3 , V_7 , 8 ) ;
return V_5 + 8 ;
}
T_1 F_2 ( void * V_1 , const unsigned char * V_2 ,
unsigned char * V_3 ,
const unsigned char * V_4 , T_1 V_5 ,
T_2 V_6 )
{
unsigned char * V_7 , V_8 [ 16 ] , * V_9 ;
T_1 V_10 , V_11 , V_12 ;
V_5 -= 8 ;
if ( ( V_5 & 0x7 ) || ( V_5 < 16 ) || ( V_5 > V_13 ) )
return 0 ;
V_7 = V_8 ;
V_12 = 6 * ( V_5 >> 3 ) ;
memcpy ( V_7 , V_4 , 8 ) ;
memcpy ( V_3 , V_4 + 8 , V_5 ) ;
for ( V_11 = 0 ; V_11 < 6 ; V_11 ++ ) {
V_9 = V_3 + V_5 - 8 ;
for ( V_10 = 0 ; V_10 < V_5 ; V_10 += 8 , V_12 -- , V_9 -= 8 ) {
V_7 [ 7 ] ^= ( unsigned char ) ( V_12 & 0xff ) ;
if ( V_12 > 0xff ) {
V_7 [ 6 ] ^= ( unsigned char ) ( ( V_12 >> 8 ) & 0xff ) ;
V_7 [ 5 ] ^= ( unsigned char ) ( ( V_12 >> 16 ) & 0xff ) ;
V_7 [ 4 ] ^= ( unsigned char ) ( ( V_12 >> 24 ) & 0xff ) ;
}
memcpy ( V_8 + 8 , V_9 , 8 ) ;
V_6 ( V_8 , V_8 , V_1 ) ;
memcpy ( V_9 , V_8 + 8 , 8 ) ;
}
}
if ( ! V_2 )
V_2 = V_14 ;
if ( memcmp ( V_7 , V_2 , 8 ) ) {
F_3 ( V_3 , V_5 ) ;
return 0 ;
}
return V_5 ;
}
