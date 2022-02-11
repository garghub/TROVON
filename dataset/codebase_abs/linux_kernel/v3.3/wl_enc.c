int F_1 ( char * V_1 , char * V_2 , void * V_3 , int V_4 )
{
int V_5 ;
int V_6 ;
int V_7 ;
char V_8 ;
char * V_9 = ( char * ) V_3 ;
for( V_5 = V_8 = 0 ; V_5 < V_10 ; V_5 ++ ) {
V_8 ^= V_1 [ V_5 ] ;
V_8 += V_1 [ V_5 ] ;
}
for( V_5 = V_6 = * V_2 = 0 ; V_5 < V_4 ; V_5 ++ , V_6 ++ ) {
V_7 = V_9 [ V_5 ] ^ ( V_8 + V_5 ) ;
switch( V_5 % 3 ) {
case 0 :
V_2 [ V_6 ] = ( ( V_7 & 0xFC ) >> 2 ) + V_11 ;
V_2 [ V_6 + 1 ] = ( ( V_7 & 0x03 ) << 4 ) + V_11 ;
V_2 [ V_6 + 2 ] = '\0' ;
break;
case 1 :
V_2 [ V_6 ] += ( ( V_7 & 0xF0 ) >> 4 ) ;
V_2 [ V_6 + 1 ] = ( ( V_7 & 0x0F ) << 2 ) + V_11 ;
V_2 [ V_6 + 2 ] = '\0' ;
break;
case 2 :
V_2 [ V_6 ] += ( ( V_7 & 0xC0 ) >> 6 ) ;
V_2 [ V_6 + 1 ] = ( V_7 & 0x3F ) + V_11 ;
V_2 [ V_6 + 2 ] = '\0' ;
V_6 ++ ;
break;
}
}
return ( strlen ( V_2 ) ) ;
}
int F_2 ( char * V_1 , void * V_12 , char * V_9 )
{
int V_5 ;
int V_6 ;
int V_4 ;
char V_8 ;
char * V_2 = V_12 ;
for( V_5 = V_8 = 0 ; V_5 < 12 ; V_5 ++ ) {
V_8 ^= V_1 [ V_5 ] ;
V_8 += V_1 [ V_5 ] ;
}
V_4 = ( strlen ( V_9 ) * 3 ) / 4 ;
for( V_5 = V_6 = 0 ; V_5 < V_4 ; V_5 ++ , V_6 ++ ) {
switch( V_5 % 3 ) {
case 0 :
V_2 [ V_5 ] = ( ( ( V_9 [ V_6 ] - V_11 ) & 0x3f ) << 2 ) +
( ( ( V_9 [ V_6 + 1 ] - V_11 ) & 0x30 ) >> 4 ) ;
break;
case 1 :
V_2 [ V_5 ] = ( ( ( V_9 [ V_6 ] - V_11 ) & 0x0f ) << 4 ) +
( ( ( V_9 [ V_6 + 1 ] - V_11 ) & 0x3c ) >> 2 ) ;
break;
case 2 :
V_2 [ V_5 ] = ( ( ( V_9 [ V_6 ] - V_11 ) & 0x03 ) << 6 ) +
( ( V_9 [ V_6 + 1 ] - V_11 ) & 0x3f ) ;
V_6 ++ ;
break;
}
V_2 [ V_5 ] ^= ( V_8 + V_5 ) ;
}
return ( V_5 ) ;
}
