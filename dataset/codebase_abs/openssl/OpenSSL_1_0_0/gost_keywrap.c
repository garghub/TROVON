void F_1 ( T_1 * V_1 , const unsigned char * V_2 , const unsigned char * V_3 , unsigned char * V_4 )
{
T_2 V_5 , V_6 , V_7 ;
int V_8 , V_9 , V_10 ;
unsigned char V_11 [ 8 ] ;
memcpy ( V_4 , V_2 , 32 ) ;
for ( V_8 = 0 ; V_8 < 8 ; V_8 ++ )
{
V_6 = 0 , V_7 = 0 ;
for ( V_9 = 0 , V_10 = 1 ; V_9 < 8 ; V_9 ++ , V_10 <<= 1 )
{
V_5 = ( ( T_2 ) V_4 [ 4 * V_9 ] ) | ( V_4 [ 4 * V_9 + 1 ] << 8 ) |
( V_4 [ 4 * V_9 + 2 ] << 16 ) | ( V_4 [ 4 * V_9 + 3 ] << 24 ) ;
if ( V_10 & V_3 [ V_8 ] )
{
V_6 += V_5 ;
}
else
{
V_7 += V_5 ;
}
}
V_11 [ 0 ] = ( unsigned char ) ( V_6 & 0xff ) ;
V_11 [ 1 ] = ( unsigned char ) ( ( V_6 >> 8 ) & 0xff ) ;
V_11 [ 2 ] = ( unsigned char ) ( ( V_6 >> 16 ) & 0xff ) ;
V_11 [ 3 ] = ( unsigned char ) ( ( V_6 >> 24 ) & 0xff ) ;
V_11 [ 4 ] = ( unsigned char ) ( V_7 & 0xff ) ;
V_11 [ 5 ] = ( unsigned char ) ( ( V_7 >> 8 ) & 0xff ) ;
V_11 [ 6 ] = ( unsigned char ) ( ( V_7 >> 16 ) & 0xff ) ;
V_11 [ 7 ] = ( unsigned char ) ( ( V_7 >> 24 ) & 0xff ) ;
F_2 ( V_1 , V_4 ) ;
F_3 ( V_1 , V_11 , V_4 , V_4 , 4 ) ;
}
}
int F_4 ( T_1 * V_1 , const unsigned char * V_12 , const unsigned char * V_3 ,
const unsigned char * V_13 , unsigned char * V_14 )
{
unsigned char V_15 [ 32 ] ;
F_1 ( V_1 , V_12 , V_3 , V_15 ) ;
F_2 ( V_1 , V_15 ) ;
memcpy ( V_14 , V_3 , 8 ) ;
F_5 ( V_1 , V_13 , V_14 + 8 , 4 ) ;
F_6 ( V_1 , 32 , V_3 , V_13 , 32 , V_14 + 40 ) ;
return 1 ;
}
int F_7 ( T_1 * V_1 , const unsigned char * V_12 ,
const unsigned char * V_14 , unsigned char * V_13 )
{
unsigned char V_15 [ 32 ] , V_16 [ 4 ] ;
F_1 ( V_1 , V_12 , V_14
, V_15 ) ;
F_2 ( V_1 , V_15 ) ;
F_8 ( V_1 , V_14 + 8 , V_13 , 4 ) ;
F_6 ( V_1 , 32 , V_14 , V_13 , 32 , V_16 ) ;
if ( memcmp ( V_16 , V_14 + 40 , 4 ) )
{
return 0 ;
}
return 1 ;
}
