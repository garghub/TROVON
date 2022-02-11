int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = V_6 -> V_9 ;
unsigned char V_10 = 0 ;
unsigned char V_11 = 0 ;
unsigned char V_12 =
( unsigned char ) ( V_13 -> V_14 / 8 ) ;
if ( V_6 -> V_9 >= 1 ) {
V_10 = ( unsigned char ) V_7 [ 0 ] ;
if ( ( V_10 == V_15 ) ||
( V_10 == V_16 ) ||
( V_10 == V_17 ) ) {
if ( ( V_10 == V_16 )
&& ( ( unsigned char ) ( V_6 -> V_9 - 1 ) != V_12 ) ) {
F_2 ( L_1 ) ;
V_8 = - 101 ;
}
if ( ( V_10 == V_17 )
&& ( ( unsigned char ) ( V_6 -> V_9 ) != 2 ) ) {
F_2 ( L_1 ) ;
V_8 = - 101 ;
}
} else {
F_2 ( L_2 ) ;
V_8 = - 100 ;
}
} else {
F_2 ( L_1 ) ;
V_8 = - 101 ;
}
if ( ( V_8 >= 0 ) && ( V_10 == V_16 ) ) {
memset ( V_18 -> V_19 , 0 ,
sizeof( V_18 -> V_19 ) ) ;
for ( V_11 = 1 ;
( V_11 <= V_12 ) && ( V_8 >= 0 ) ;
V_11 ++ ) {
if ( ( V_7 [ V_11 ] != 0 ) && ( V_7 [ V_11 ] != 0xFF ) ) {
F_2 ( L_3 ,
( int ) V_11 ) ;
V_8 = - ( int ) V_11 ;
}
V_18 -> V_19 [ ( V_11 - 1 ) / 4 ] =
V_18 -> V_19 [ ( V_11 -
1 ) / 4 ] | ( V_7 [ V_11 ] << ( 8 * ( ( V_11 -
1 ) % 4 ) ) ) ;
}
}
if ( V_8 >= 0 ) {
if ( ( V_10 == V_15 )
|| ( V_10 == V_16 ) ) {
for ( V_11 = 0 ; V_11 <= V_12 ; V_11 ++ ) {
if ( ( V_11 % 4 ) == 0 ) {
F_3 ( V_18 ->
V_19 [ V_11 /
4 ] ,
V_18 -> V_20 + 32 + V_11 ) ;
}
}
}
}
if ( V_10 == V_17 ) {
if ( V_7 [ 1 ] ) {
V_18 -> V_21 = V_22 ;
} else {
V_18 -> V_21 = V_23 ;
}
}
return V_8 ;
}
int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = V_6 -> V_9 ;
unsigned char V_10 = 0 ;
unsigned char V_12 =
( unsigned char ) ( V_13 -> V_14 / 8 ) ;
unsigned char V_24 = F_5 ( V_6 -> V_25 ) ;
unsigned char V_26 = F_6 ( V_6 -> V_25 ) ;
unsigned char * V_27 ;
unsigned int V_28 ;
if ( V_6 -> V_9 >= 1 ) {
V_10 = ( unsigned char ) V_7 [ 0 ] ;
if ( ( V_10 == V_29 )
|| ( V_10 == V_30 ) ) {
if ( V_24 < V_12 ) {
if ( ( ( V_18 -> V_19
[ V_24 /
4 ] >> ( 8 *
( V_24
%
4 ) ) ) &
0xFF ) == 0 ) {
if ( ( V_10 ==
V_29 )
&& ( V_26 > 7 ) ) {
F_2 ( L_4 ) ;
V_8 = - 103 ;
}
} else {
F_2 ( L_5 ) ;
V_8 = - 102 ;
}
} else {
F_2 ( L_5 ) ;
V_8 = - 102 ;
}
} else {
F_2 ( L_2 ) ;
V_8 = - 100 ;
}
} else {
F_2 ( L_1 ) ;
V_8 = - 101 ;
}
if ( V_8 >= 0 ) {
V_27 = ( unsigned char * ) & V_7 [ 0 ] ;
V_28 =
F_7 ( V_18 -> V_20 + 8 + ( ( V_24 / 4 ) * 4 ) ) ;
V_28 = ( V_28 >> ( 8 * ( V_24 % 4 ) ) ) & 0xFF ;
* V_27 = ( unsigned char ) V_28 ;
if ( V_10 == V_29 ) {
* V_27 = ( * V_27 >> V_26 ) & 1 ;
}
}
return V_8 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned char V_10 = ( unsigned char ) F_9 ( V_6 -> V_25 ) ;
int V_8 = V_6 -> V_9 ;
unsigned char V_11 = 0 ;
unsigned char V_12 = 0 ;
unsigned int * V_31 = V_7 ;
if ( ( V_10 == V_32 )
|| ( V_10 == V_33 ) ) {
V_12 =
( unsigned char ) ( V_13 -> V_14 / 32 ) ;
if ( ( V_12 * 32 ) <
V_13 -> V_14 ) {
V_12 = V_12 + 1 ;
}
if ( V_6 -> V_9 >= V_12 ) {
if ( V_10 == V_32 ) {
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_31 [ V_11 ] =
F_7 ( V_18 -> V_20 + 8 +
( V_11 * 4 ) ) ;
V_31 [ V_11 ] =
V_31 [ V_11 ] &
( ~ V_18 ->
V_19 [ V_11 ] ) ;
}
} else {
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
V_31 [ V_11 ] =
F_7 ( V_18 -> V_20 + 20 +
( V_11 * 4 ) ) ;
V_31 [ V_11 ] =
V_31 [ V_11 ] & V_18 ->
V_19 [ V_11 ] ;
}
}
} else {
F_2 ( L_1 ) ;
V_8 = - 101 ;
}
} else {
F_2 ( L_2 ) ;
V_8 = - 100 ;
}
return V_8 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = V_6 -> V_9 ;
unsigned char V_10 = 0 ;
unsigned char V_12 =
( unsigned char ) ( V_13 -> V_14 / 8 ) ;
unsigned char V_24 = F_5 ( V_6 -> V_25 ) ;
unsigned char V_34 = F_6 ( V_6 -> V_25 ) ;
unsigned int V_28 = 0 ;
if ( V_6 -> V_9 >= 1 ) {
V_10 = ( unsigned char ) V_7 [ 0 ] ;
if ( ( V_10 == V_35 ) ||
( V_10 == V_36 ) ||
( V_10 == V_37 ) ||
( V_10 == V_38 ) ) {
if ( V_24 < V_12 ) {
if ( ( ( V_18 -> V_19
[ V_24 /
4 ] >> ( 8 *
( V_24
%
4 ) ) ) &
0xFF ) == 0xFF ) {
if ( ( ( V_10 == V_35 ) || ( V_10 == V_37 ) ) && ( V_34 > 7 ) ) {
F_2 ( L_4 ) ;
V_8 = - 103 ;
}
if ( ( ( V_10 == V_37 ) || ( V_10 == V_38 ) ) && ( V_18 -> V_21 == V_23 ) ) {
F_2 ( L_6 ) ;
V_8 = - 104 ;
}
if ( ( ( V_10 == V_36 ) || ( V_10 == V_38 ) ) && ( V_6 -> V_9 < 2 ) ) {
F_2 ( L_1 ) ;
V_8 = - 101 ;
}
} else {
F_2 ( L_7 ,
( unsigned long ) V_18 ->
V_19 [ 0 ] ) ;
V_8 = - 102 ;
}
} else {
F_2 ( L_8 ,
V_24 , V_12 ) ;
V_8 = - 102 ;
}
} else {
F_2 ( L_2 ) ;
V_8 = - 100 ;
}
} else {
F_2 ( L_1 ) ;
V_8 = - 101 ;
}
if ( V_8 >= 0 ) {
V_28 =
F_7 ( V_18 -> V_20 + 20 + ( ( V_24 / 4 ) * 4 ) ) ;
if ( V_18 -> V_21 == V_23 ) {
V_28 =
V_28 & ( 0xFFFFFFFFUL -
( 0xFFUL << ( 8 * ( V_24 % 4 ) ) ) ) ;
}
if ( V_10 == V_35 ) {
V_28 =
V_28 | ( 1UL << ( ( 8 * ( V_24 %
4 ) ) + V_34 ) ) ;
}
if ( V_10 == V_36 ) {
V_28 =
V_28 | ( ( V_7 [ 1 ] & 0xFF ) << ( 8 *
( V_24 % 4 ) ) ) ;
}
if ( V_10 == V_37 ) {
V_28 =
V_28 & ( 0xFFFFFFFFUL -
( 1UL << ( ( 8 * ( V_24 % 4 ) ) +
V_34 ) ) ) ;
}
if ( V_10 == V_38 ) {
V_28 =
V_28 & ( 0xFFFFFFFFUL -
( ( V_7 [ 1 ] & 0xFF ) << ( 8 * ( V_24 %
4 ) ) ) ) ;
}
F_3 ( V_28 ,
V_18 -> V_20 + 20 + ( ( V_24 / 4 ) * 4 ) ) ;
}
return V_8 ;
}
int F_11 ( struct V_1 * V_2 )
{
return 0 ;
}
