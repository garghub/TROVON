int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
unsigned char * V_3 ,
const unsigned char * V_4 , unsigned int V_5 )
{
unsigned char * V_6 , V_7 [ 16 ] , * V_8 ;
unsigned int V_9 , V_10 , V_11 ;
if ( ( V_5 & 0x7 ) || ( V_5 < 8 ) )
return - 1 ;
V_6 = V_7 ;
V_11 = 1 ;
memcpy ( V_3 + 8 , V_4 , V_5 ) ;
if ( ! V_2 )
V_2 = V_12 ;
memcpy ( V_6 , V_2 , 8 ) ;
for ( V_10 = 0 ; V_10 < 6 ; V_10 ++ )
{
V_8 = V_3 + 8 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 += 8 , V_11 ++ , V_8 += 8 )
{
memcpy ( V_7 + 8 , V_8 , 8 ) ;
F_2 ( V_7 , V_7 , V_1 ) ;
V_6 [ 7 ] ^= ( unsigned char ) ( V_11 & 0xff ) ;
if ( V_11 > 0xff )
{
V_6 [ 6 ] ^= ( unsigned char ) ( ( V_11 & 0xff ) >> 8 ) ;
V_6 [ 5 ] ^= ( unsigned char ) ( ( V_11 & 0xff ) >> 16 ) ;
V_6 [ 4 ] ^= ( unsigned char ) ( ( V_11 & 0xff ) >> 24 ) ;
}
memcpy ( V_8 , V_7 + 8 , 8 ) ;
}
}
memcpy ( V_3 , V_6 , 8 ) ;
return V_5 + 8 ;
}
int F_3 ( T_1 * V_1 , const unsigned char * V_2 ,
unsigned char * V_3 ,
const unsigned char * V_4 , unsigned int V_5 )
{
unsigned char * V_6 , V_7 [ 16 ] , * V_8 ;
unsigned int V_9 , V_10 , V_11 ;
V_5 -= 8 ;
if ( V_5 & 0x7 )
return - 1 ;
if ( V_5 < 8 )
return - 1 ;
V_6 = V_7 ;
V_11 = 6 * ( V_5 >> 3 ) ;
memcpy ( V_6 , V_4 , 8 ) ;
memcpy ( V_3 , V_4 + 8 , V_5 ) ;
for ( V_10 = 0 ; V_10 < 6 ; V_10 ++ )
{
V_8 = V_3 + V_5 - 8 ;
for ( V_9 = 0 ; V_9 < V_5 ; V_9 += 8 , V_11 -- , V_8 -= 8 )
{
V_6 [ 7 ] ^= ( unsigned char ) ( V_11 & 0xff ) ;
if ( V_11 > 0xff )
{
V_6 [ 6 ] ^= ( unsigned char ) ( ( V_11 & 0xff ) >> 8 ) ;
V_6 [ 5 ] ^= ( unsigned char ) ( ( V_11 & 0xff ) >> 16 ) ;
V_6 [ 4 ] ^= ( unsigned char ) ( ( V_11 & 0xff ) >> 24 ) ;
}
memcpy ( V_7 + 8 , V_8 , 8 ) ;
F_4 ( V_7 , V_7 , V_1 ) ;
memcpy ( V_8 , V_7 + 8 , 8 ) ;
}
}
if ( ! V_2 )
V_2 = V_12 ;
if ( memcmp ( V_6 , V_2 , 8 ) )
{
F_5 ( V_3 , V_5 ) ;
return 0 ;
}
return V_5 ;
}
int F_6 ( const unsigned char * V_13 , int V_14 ,
const unsigned char * V_2 ,
const unsigned char * V_15 ,
const unsigned char * V_1 , int V_16 )
{
unsigned char * V_17 = NULL , * V_18 = NULL ;
int V_19 , V_20 = 0 ;
T_1 V_21 ;
V_17 = F_7 ( V_16 + 8 ) ;
V_18 = F_7 ( V_16 ) ;
if ( ! V_17 || ! V_18 )
return 0 ;
if ( F_8 ( V_13 , V_14 , & V_21 ) )
goto V_22;
V_19 = F_1 ( & V_21 , V_2 , V_17 , V_1 , V_16 ) ;
if ( V_19 <= 0 )
goto V_22;
if ( V_15 && memcmp ( V_15 , V_17 , V_16 ) )
goto V_22;
if ( F_9 ( V_13 , V_14 , & V_21 ) )
goto V_22;
V_19 = F_3 ( & V_21 , V_2 , V_18 , V_17 , V_19 ) ;
if ( memcmp ( V_1 , V_18 , V_16 ) )
goto V_22;
V_20 = 1 ;
V_22:
if ( V_17 )
F_10 ( V_17 ) ;
if ( V_18 )
F_10 ( V_18 ) ;
return V_20 ;
}
int main ( int V_23 , char * * V_24 )
{
static const unsigned char V_13 [] = {
0x00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 ,
0x08 , 0x09 , 0x0a , 0x0b , 0x0c , 0x0d , 0x0e , 0x0f ,
0x10 , 0x11 , 0x12 , 0x13 , 0x14 , 0x15 , 0x16 , 0x17 ,
0x18 , 0x19 , 0x1a , 0x1b , 0x1c , 0x1d , 0x1e , 0x1f
} ;
static const unsigned char V_1 [] = {
0x00 , 0x11 , 0x22 , 0x33 , 0x44 , 0x55 , 0x66 , 0x77 ,
0x88 , 0x99 , 0xaa , 0xbb , 0xcc , 0xdd , 0xee , 0xff ,
0x00 , 0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 ,
0x08 , 0x09 , 0x0a , 0x0b , 0x0c , 0x0d , 0x0e , 0x0f
} ;
static const unsigned char V_25 [] = {
0x1f , 0xa6 , 0x8b , 0x0a , 0x81 , 0x12 , 0xb4 , 0x47 ,
0xae , 0xf3 , 0x4b , 0xd8 , 0xfb , 0x5a , 0x7b , 0x82 ,
0x9d , 0x3e , 0x86 , 0x23 , 0x71 , 0xd2 , 0xcf , 0xe5
} ;
static const unsigned char V_26 [] = {
0x96 , 0x77 , 0x8b , 0x25 , 0xae , 0x6c , 0xa4 , 0x35 ,
0xf9 , 0x2b , 0x5b , 0x97 , 0xc0 , 0x50 , 0xae , 0xd2 ,
0x46 , 0x8a , 0xb8 , 0xa1 , 0x7a , 0xd8 , 0x4e , 0x5d
} ;
static const unsigned char V_27 [] = {
0x64 , 0xe8 , 0xc3 , 0xf9 , 0xce , 0x0f , 0x5b , 0xa2 ,
0x63 , 0xe9 , 0x77 , 0x79 , 0x05 , 0x81 , 0x8a , 0x2a ,
0x93 , 0xc8 , 0x19 , 0x1e , 0x7d , 0x6e , 0x8a , 0xe7
} ;
static const unsigned char V_28 [] = {
0x03 , 0x1d , 0x33 , 0x26 , 0x4e , 0x15 , 0xd3 , 0x32 ,
0x68 , 0xf2 , 0x4e , 0xc2 , 0x60 , 0x74 , 0x3e , 0xdc ,
0xe1 , 0xc6 , 0xc7 , 0xdd , 0xee , 0x72 , 0x5a , 0x93 ,
0x6b , 0xa8 , 0x14 , 0x91 , 0x5c , 0x67 , 0x62 , 0xd2
} ;
static const unsigned char V_29 [] = {
0xa8 , 0xf9 , 0xbc , 0x16 , 0x12 , 0xc6 , 0x8b , 0x3f ,
0xf6 , 0xe6 , 0xf4 , 0xfb , 0xe3 , 0x0e , 0x71 , 0xe4 ,
0x76 , 0x9c , 0x8b , 0x80 , 0xa3 , 0x2c , 0xb8 , 0x95 ,
0x8c , 0xd5 , 0xd1 , 0x7d , 0x6b , 0x25 , 0x4d , 0xa1
} ;
static const unsigned char V_30 [] = {
0x28 , 0xc9 , 0xf4 , 0x04 , 0xc4 , 0xb8 , 0x10 , 0xf4 ,
0xcb , 0xcc , 0xb3 , 0x5c , 0xfb , 0x87 , 0xf8 , 0x26 ,
0x3f , 0x57 , 0x86 , 0xe2 , 0xd8 , 0x0e , 0xd3 , 0x26 ,
0xcb , 0xc7 , 0xf0 , 0xe7 , 0x1a , 0x99 , 0xf4 , 0x3b ,
0xfb , 0x98 , 0x8b , 0x9b , 0x7a , 0x02 , 0xdd , 0x21
} ;
T_1 V_21 , V_31 ;
int V_20 ;
V_20 = F_6 ( V_13 , 128 , NULL , V_25 , V_1 , 16 ) ;
fprintf ( V_32 , L_1 , V_20 ) ;
V_20 = F_6 ( V_13 , 192 , NULL , V_26 , V_1 , 16 ) ;
fprintf ( V_32 , L_1 , V_20 ) ;
V_20 = F_6 ( V_13 , 256 , NULL , V_27 , V_1 , 16 ) ;
fprintf ( V_32 , L_1 , V_20 ) ;
V_20 = F_6 ( V_13 , 192 , NULL , V_28 , V_1 , 24 ) ;
fprintf ( V_32 , L_1 , V_20 ) ;
V_20 = F_6 ( V_13 , 256 , NULL , V_29 , V_1 , 24 ) ;
fprintf ( V_32 , L_1 , V_20 ) ;
V_20 = F_6 ( V_13 , 256 , NULL , V_30 , V_1 , 32 ) ;
fprintf ( V_32 , L_1 , V_20 ) ;
}
