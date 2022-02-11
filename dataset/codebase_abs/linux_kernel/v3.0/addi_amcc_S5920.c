int F_1 ( int V_1 ,
unsigned int V_2 ,
unsigned short V_3 , unsigned short * V_4 )
{
unsigned int V_5 = 0 ;
int V_6 = 0 ;
int V_7 ;
int V_8 ;
unsigned char V_9 [ 1 ] ;
unsigned char V_10 = 0 ;
unsigned char V_11 = 0 ;
unsigned char V_12 = 0 ;
unsigned char V_13 = 0 ;
unsigned short V_14 = 0 ;
for ( V_7 = 0 ; V_7 < V_1 ;
V_7 ++ ) {
do {
V_5 =
F_2 ( V_2 +
V_15 ) ;
V_5 = V_5 & V_16 ;
} while ( V_5 == V_16 );
for ( V_6 = 0 ; V_6 < 2 ; V_6 ++ ) {
V_12 = ( V_3 + V_6 ) % 256 ;
V_13 = ( V_3 + V_6 ) / 256 ;
F_3 ( V_17 ,
V_2 + V_15 +
3 ) ;
do {
V_5 =
F_2 ( V_2 +
V_15 ) ;
V_5 = V_5 & V_16 ;
} while ( V_5 == V_16 );
F_3 ( V_12 ,
V_2 + V_15 +
2 ) ;
do {
V_5 =
F_2 ( V_2 +
V_15 ) ;
V_5 = V_5 & V_16 ;
} while ( V_5 == V_16 );
F_3 ( V_18 ,
V_2 + V_15 +
3 ) ;
do {
V_5 =
F_2 ( V_2 +
V_15 ) ;
V_5 = V_5 & V_16 ;
} while ( V_5 == V_16 );
F_3 ( V_13 ,
V_2 + V_15 +
2 ) ;
do {
V_5 =
F_2 ( V_2 +
V_15 ) ;
V_5 = V_5 & V_16 ;
} while ( V_5 == V_16 );
F_3 ( V_19 ,
V_2 + V_15 +
3 ) ;
do {
V_5 =
F_2 ( V_2 +
V_15 ) ;
V_5 = V_5 & V_16 ;
} while ( V_5 == V_16 );
* V_9 =
F_4 ( V_2 +
V_15 + 2 ) ;
do {
V_5 =
F_2 ( V_2 +
V_15 ) ;
V_5 = V_5 & V_16 ;
} while ( V_5 == V_16 );
if ( V_6 == 0 )
V_10 = V_9 [ 0 ] ;
else
V_11 = V_9 [ 0 ] ;
F_5 ( 1 ) ;
}
V_14 =
( V_10 | ( ( ( unsigned short ) V_11 ) *
256 ) ) ;
V_4 [ V_7 ] = V_14 ;
V_3 += 2 ;
}
return 0 ;
}
