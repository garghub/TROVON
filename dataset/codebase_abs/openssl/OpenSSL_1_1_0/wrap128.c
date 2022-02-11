T_1 F_1 ( void * V_1 , const unsigned char * V_2 ,
unsigned char * V_3 ,
const unsigned char * V_4 , T_1 V_5 ,
T_2 V_6 )
{
unsigned char * V_7 , V_8 [ 16 ] , * V_9 ;
T_1 V_10 , V_11 , V_12 ;
if ( ( V_5 & 0x7 ) || ( V_5 < 16 ) || ( V_5 > V_13 ) )
return 0 ;
V_7 = V_8 ;
V_12 = 1 ;
memmove ( V_3 + 8 , V_4 , V_5 ) ;
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
static T_1 F_2 ( void * V_1 , unsigned char * V_2 ,
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
memmove ( V_3 , V_4 + 8 , V_5 ) ;
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
memcpy ( V_2 , V_7 , 8 ) ;
return V_5 ;
}
T_1 F_3 ( void * V_1 , const unsigned char * V_2 ,
unsigned char * V_3 , const unsigned char * V_4 ,
T_1 V_5 , T_2 V_6 )
{
T_1 V_15 ;
unsigned char V_16 [ 8 ] ;
V_15 = F_2 ( V_1 , V_16 , V_3 , V_4 , V_5 , V_6 ) ;
if ( V_15 == 0 )
return 0 ;
if ( ! V_2 )
V_2 = V_14 ;
if ( F_4 ( V_16 , V_2 , 8 ) ) {
F_5 ( V_3 , V_15 ) ;
return 0 ;
}
return V_15 ;
}
T_1 F_6 ( void * V_1 , const unsigned char * V_17 ,
unsigned char * V_3 ,
const unsigned char * V_4 , T_1 V_5 ,
T_2 V_6 )
{
const T_1 V_18 = ( V_5 + 7 ) / 8 ;
const T_1 V_19 = V_18 * 8 ;
const T_1 V_20 = V_19 - V_5 ;
unsigned char V_21 [ 8 ] ;
int V_15 ;
if ( V_5 == 0 || V_5 >= V_13 )
return 0 ;
if ( ! V_17 )
memcpy ( V_21 , V_22 , 4 ) ;
else
memcpy ( V_21 , V_17 , 4 ) ;
V_21 [ 4 ] = ( V_5 >> 24 ) & 0xFF ;
V_21 [ 5 ] = ( V_5 >> 16 ) & 0xFF ;
V_21 [ 6 ] = ( V_5 >> 8 ) & 0xFF ;
V_21 [ 7 ] = V_5 & 0xFF ;
if ( V_19 == 8 ) {
memmove ( V_3 + 8 , V_4 , V_5 ) ;
memcpy ( V_3 , V_21 , 8 ) ;
memset ( V_3 + 8 + V_5 , 0 , V_20 ) ;
V_6 ( V_3 , V_3 , V_1 ) ;
V_15 = 16 ;
} else {
memmove ( V_3 , V_4 , V_5 ) ;
memset ( V_3 + V_5 , 0 , V_20 ) ;
V_15 = F_1 ( V_1 , V_21 , V_3 , V_3 , V_19 , V_6 ) ;
}
return V_15 ;
}
T_1 F_7 ( void * V_1 , const unsigned char * V_17 ,
unsigned char * V_3 ,
const unsigned char * V_4 , T_1 V_5 ,
T_2 V_6 )
{
T_1 V_23 = V_5 / 8 - 1 ;
T_1 V_19 ;
T_1 V_20 ;
T_1 V_24 ;
unsigned char V_21 [ 8 ] ;
static unsigned char V_25 [ 8 ] = { 0x0 } ;
T_1 V_15 ;
if ( ( V_5 & 0x7 ) != 0 || V_5 < 16 || V_5 >= V_13 )
return 0 ;
memmove ( V_3 , V_4 , V_5 ) ;
if ( V_5 == 16 ) {
V_6 ( V_3 , V_3 , V_1 ) ;
memcpy ( V_21 , V_3 , 8 ) ;
memmove ( V_3 , V_3 + 8 , 8 ) ;
V_19 = 8 ;
} else {
V_19 = V_5 - 8 ;
V_15 = F_2 ( V_1 , V_21 , V_3 , V_3 , V_5 , V_6 ) ;
if ( V_19 != V_15 ) {
F_5 ( V_3 , V_5 ) ;
return 0 ;
}
}
if ( ( ! V_17 && F_4 ( V_21 , V_22 , 4 ) )
|| ( V_17 && F_4 ( V_21 , V_17 , 4 ) ) ) {
F_5 ( V_3 , V_5 ) ;
return 0 ;
}
V_24 = ( ( unsigned int ) V_21 [ 4 ] << 24 )
| ( ( unsigned int ) V_21 [ 5 ] << 16 )
| ( ( unsigned int ) V_21 [ 6 ] << 8 )
| ( unsigned int ) V_21 [ 7 ] ;
if ( 8 * ( V_23 - 1 ) >= V_24 || V_24 > 8 * V_23 ) {
F_5 ( V_3 , V_5 ) ;
return 0 ;
}
V_20 = V_19 - V_24 ;
if ( F_4 ( V_3 + V_24 , V_25 , V_20 ) != 0 ) {
F_5 ( V_3 , V_5 ) ;
return 0 ;
}
return V_24 ;
}
