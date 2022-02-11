int F_1 ( T_1 type , unsigned short * V_1 , unsigned V_2 ,
T_2 * * V_3 , unsigned * V_4 , unsigned short * V_5 )
{
unsigned V_6 ;
unsigned V_7 ;
unsigned V_8 , V_9 ;
unsigned V_10 ;
unsigned V_11 ;
unsigned V_12 ;
int V_13 ;
unsigned V_14 ;
unsigned V_15 ;
unsigned V_16 ;
unsigned V_17 ;
unsigned V_18 ;
unsigned V_19 ;
T_2 V_20 ;
T_2 * V_21 ;
const unsigned short * V_22 ;
const unsigned short * V_23 ;
int V_24 ;
unsigned short V_25 [ V_26 + 1 ] ;
unsigned short V_27 [ V_26 + 1 ] ;
static const unsigned short V_28 [ 31 ] = {
3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 13 , 15 , 17 , 19 , 23 , 27 , 31 ,
35 , 43 , 51 , 59 , 67 , 83 , 99 , 115 , 131 , 163 , 195 , 227 , 258 , 0 , 0 } ;
static const unsigned short V_29 [ 31 ] = {
16 , 16 , 16 , 16 , 16 , 16 , 16 , 16 , 17 , 17 , 17 , 17 , 18 , 18 , 18 , 18 ,
19 , 19 , 19 , 19 , 20 , 20 , 20 , 20 , 21 , 21 , 21 , 21 , 16 , 201 , 196 } ;
static const unsigned short V_30 [ 32 ] = {
1 , 2 , 3 , 4 , 5 , 7 , 9 , 13 , 17 , 25 , 33 , 49 , 65 , 97 , 129 , 193 ,
257 , 385 , 513 , 769 , 1025 , 1537 , 2049 , 3073 , 4097 , 6145 ,
8193 , 12289 , 16385 , 24577 , 0 , 0 } ;
static const unsigned short V_31 [ 32 ] = {
16 , 16 , 16 , 16 , 17 , 17 , 18 , 18 , 19 , 19 , 20 , 20 , 21 , 21 , 22 , 22 ,
23 , 23 , 24 , 24 , 25 , 25 , 26 , 26 , 27 , 27 ,
28 , 28 , 29 , 29 , 64 , 64 } ;
for ( V_6 = 0 ; V_6 <= V_26 ; V_6 ++ )
V_25 [ V_6 ] = 0 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
V_25 [ V_1 [ V_7 ] ] ++ ;
V_10 = * V_4 ;
for ( V_9 = V_26 ; V_9 >= 1 ; V_9 -- )
if ( V_25 [ V_9 ] != 0 ) break;
if ( V_10 > V_9 ) V_10 = V_9 ;
if ( V_9 == 0 ) {
V_20 . V_32 = ( unsigned char ) 64 ;
V_20 . V_4 = ( unsigned char ) 1 ;
V_20 . V_33 = ( unsigned short ) 0 ;
* ( * V_3 ) ++ = V_20 ;
* ( * V_3 ) ++ = V_20 ;
* V_4 = 1 ;
return 0 ;
}
for ( V_8 = 1 ; V_8 <= V_26 ; V_8 ++ )
if ( V_25 [ V_8 ] != 0 ) break;
if ( V_10 < V_8 ) V_10 = V_8 ;
V_13 = 1 ;
for ( V_6 = 1 ; V_6 <= V_26 ; V_6 ++ ) {
V_13 <<= 1 ;
V_13 -= V_25 [ V_6 ] ;
if ( V_13 < 0 ) return - 1 ;
}
if ( V_13 > 0 && ( type == V_34 || V_9 != 1 ) )
return - 1 ;
V_27 [ 1 ] = 0 ;
for ( V_6 = 1 ; V_6 < V_26 ; V_6 ++ )
V_27 [ V_6 + 1 ] = V_27 [ V_6 ] + V_25 [ V_6 ] ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
if ( V_1 [ V_7 ] != 0 ) V_5 [ V_27 [ V_1 [ V_7 ] ] ++ ] = ( unsigned short ) V_7 ;
switch ( type ) {
case V_34 :
V_22 = V_23 = V_5 ;
V_24 = 19 ;
break;
case V_35 :
V_22 = V_28 ;
V_22 -= 257 ;
V_23 = V_29 ;
V_23 -= 257 ;
V_24 = 256 ;
break;
default:
V_22 = V_30 ;
V_23 = V_31 ;
V_24 = - 1 ;
}
V_15 = 0 ;
V_7 = 0 ;
V_6 = V_8 ;
V_21 = * V_3 ;
V_11 = V_10 ;
V_12 = 0 ;
V_18 = ( unsigned ) ( - 1 ) ;
V_14 = 1U << V_10 ;
V_19 = V_14 - 1 ;
if ( type == V_35 && V_14 >= V_36 - V_37 )
return 1 ;
for (; ; ) {
V_20 . V_4 = ( unsigned char ) ( V_6 - V_12 ) ;
if ( ( int ) ( V_5 [ V_7 ] ) < V_24 ) {
V_20 . V_32 = ( unsigned char ) 0 ;
V_20 . V_33 = V_5 [ V_7 ] ;
}
else if ( ( int ) ( V_5 [ V_7 ] ) > V_24 ) {
V_20 . V_32 = ( unsigned char ) ( V_23 [ V_5 [ V_7 ] ] ) ;
V_20 . V_33 = V_22 [ V_5 [ V_7 ] ] ;
}
else {
V_20 . V_32 = ( unsigned char ) ( 32 + 64 ) ;
V_20 . V_33 = 0 ;
}
V_16 = 1U << ( V_6 - V_12 ) ;
V_17 = 1U << V_11 ;
V_8 = V_17 ;
do {
V_17 -= V_16 ;
V_21 [ ( V_15 >> V_12 ) + V_17 ] = V_20 ;
} while ( V_17 != 0 );
V_16 = 1U << ( V_6 - 1 ) ;
while ( V_15 & V_16 )
V_16 >>= 1 ;
if ( V_16 != 0 ) {
V_15 &= V_16 - 1 ;
V_15 += V_16 ;
}
else
V_15 = 0 ;
V_7 ++ ;
if ( -- ( V_25 [ V_6 ] ) == 0 ) {
if ( V_6 == V_9 ) break;
V_6 = V_1 [ V_5 [ V_7 ] ] ;
}
if ( V_6 > V_10 && ( V_15 & V_19 ) != V_18 ) {
if ( V_12 == 0 )
V_12 = V_10 ;
V_21 += V_8 ;
V_11 = V_6 - V_12 ;
V_13 = ( int ) ( 1 << V_11 ) ;
while ( V_11 + V_12 < V_9 ) {
V_13 -= V_25 [ V_11 + V_12 ] ;
if ( V_13 <= 0 ) break;
V_11 ++ ;
V_13 <<= 1 ;
}
V_14 += 1U << V_11 ;
if ( type == V_35 && V_14 >= V_36 - V_37 )
return 1 ;
V_18 = V_15 & V_19 ;
( * V_3 ) [ V_18 ] . V_32 = ( unsigned char ) V_11 ;
( * V_3 ) [ V_18 ] . V_4 = ( unsigned char ) V_10 ;
( * V_3 ) [ V_18 ] . V_33 = ( unsigned short ) ( V_21 - * V_3 ) ;
}
}
V_20 . V_32 = ( unsigned char ) 64 ;
V_20 . V_4 = ( unsigned char ) ( V_6 - V_12 ) ;
V_20 . V_33 = ( unsigned short ) 0 ;
while ( V_15 != 0 ) {
if ( V_12 != 0 && ( V_15 & V_19 ) != V_18 ) {
V_12 = 0 ;
V_6 = V_10 ;
V_21 = * V_3 ;
V_20 . V_4 = ( unsigned char ) V_6 ;
}
V_21 [ V_15 >> V_12 ] = V_20 ;
V_16 = 1U << ( V_6 - 1 ) ;
while ( V_15 & V_16 )
V_16 >>= 1 ;
if ( V_16 != 0 ) {
V_15 &= V_16 - 1 ;
V_15 += V_16 ;
}
else
V_15 = 0 ;
}
* V_3 += V_14 ;
* V_4 = V_10 ;
return 0 ;
}
