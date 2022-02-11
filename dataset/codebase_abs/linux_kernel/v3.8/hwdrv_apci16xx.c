static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 = V_6 -> V_14 ;
unsigned char V_15 = 0 ;
unsigned char V_16 = 0 ;
unsigned char V_17 =
( unsigned char ) ( V_9 -> V_18 / 8 ) ;
if ( V_6 -> V_14 >= 1 ) {
V_15 = ( unsigned char ) V_7 [ 0 ] ;
if ( ( V_15 == V_19 ) ||
( V_15 == V_20 ) ||
( V_15 == V_21 ) ) {
if ( ( V_15 == V_20 )
&& ( ( unsigned char ) ( V_6 -> V_14 - 1 ) != V_17 ) ) {
F_3 ( L_1 ) ;
V_13 = - 101 ;
}
if ( ( V_15 == V_21 )
&& ( ( unsigned char ) ( V_6 -> V_14 ) != 2 ) ) {
F_3 ( L_1 ) ;
V_13 = - 101 ;
}
} else {
F_3 ( L_2 ) ;
V_13 = - 100 ;
}
} else {
F_3 ( L_1 ) ;
V_13 = - 101 ;
}
if ( ( V_13 >= 0 ) && ( V_15 == V_20 ) ) {
memset ( V_11 -> V_22 , 0 ,
sizeof( V_11 -> V_22 ) ) ;
for ( V_16 = 1 ;
( V_16 <= V_17 ) && ( V_13 >= 0 ) ;
V_16 ++ ) {
if ( ( V_7 [ V_16 ] != 0 ) && ( V_7 [ V_16 ] != 0xFF ) ) {
F_3 ( L_3 ,
( int ) V_16 ) ;
V_13 = - ( int ) V_16 ;
}
V_11 -> V_22 [ ( V_16 - 1 ) / 4 ] =
V_11 -> V_22 [ ( V_16 -
1 ) / 4 ] | ( V_7 [ V_16 ] << ( 8 * ( ( V_16 -
1 ) % 4 ) ) ) ;
}
}
if ( V_13 >= 0 ) {
if ( ( V_15 == V_19 )
|| ( V_15 == V_20 ) ) {
for ( V_16 = 0 ; V_16 <= V_17 ; V_16 ++ ) {
if ( ( V_16 % 4 ) == 0 ) {
F_4 ( V_11 ->
V_22 [ V_16 /
4 ] ,
V_11 -> V_23 + 32 + V_16 ) ;
}
}
}
}
if ( V_15 == V_21 ) {
if ( V_7 [ 1 ] ) {
V_11 -> V_24 = V_25 ;
} else {
V_11 -> V_24 = V_26 ;
}
}
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 = V_6 -> V_14 ;
unsigned char V_15 = 0 ;
unsigned char V_17 =
( unsigned char ) ( V_9 -> V_18 / 8 ) ;
unsigned char V_27 = F_6 ( V_6 -> V_28 ) ;
unsigned char V_29 = F_7 ( V_6 -> V_28 ) ;
unsigned char * V_30 ;
unsigned int V_31 ;
if ( V_6 -> V_14 >= 1 ) {
V_15 = ( unsigned char ) V_7 [ 0 ] ;
if ( ( V_15 == V_32 )
|| ( V_15 == V_33 ) ) {
if ( V_27 < V_17 ) {
if ( ( ( V_11 -> V_22
[ V_27 /
4 ] >> ( 8 *
( V_27
%
4 ) ) ) &
0xFF ) == 0 ) {
if ( ( V_15 ==
V_32 )
&& ( V_29 > 7 ) ) {
F_3 ( L_4 ) ;
V_13 = - 103 ;
}
} else {
F_3 ( L_5 ) ;
V_13 = - 102 ;
}
} else {
F_3 ( L_5 ) ;
V_13 = - 102 ;
}
} else {
F_3 ( L_2 ) ;
V_13 = - 100 ;
}
} else {
F_3 ( L_1 ) ;
V_13 = - 101 ;
}
if ( V_13 >= 0 ) {
V_30 = ( unsigned char * ) & V_7 [ 0 ] ;
V_31 =
F_8 ( V_11 -> V_23 + 8 + ( ( V_27 / 4 ) * 4 ) ) ;
V_31 = ( V_31 >> ( 8 * ( V_27 % 4 ) ) ) & 0xFF ;
* V_30 = ( unsigned char ) V_31 ;
if ( V_15 == V_32 ) {
* V_30 = ( * V_30 >> V_29 ) & 1 ;
}
}
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
unsigned char V_15 = ( unsigned char ) F_10 ( V_6 -> V_28 ) ;
int V_13 = V_6 -> V_14 ;
unsigned char V_16 = 0 ;
unsigned char V_17 = 0 ;
unsigned int * V_34 = V_7 ;
if ( ( V_15 == V_35 )
|| ( V_15 == V_36 ) ) {
V_17 =
( unsigned char ) ( V_9 -> V_18 / 32 ) ;
if ( ( V_17 * 32 ) <
V_9 -> V_18 ) {
V_17 = V_17 + 1 ;
}
if ( V_6 -> V_14 >= V_17 ) {
if ( V_15 == V_35 ) {
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_34 [ V_16 ] =
F_8 ( V_11 -> V_23 + 8 +
( V_16 * 4 ) ) ;
V_34 [ V_16 ] =
V_34 [ V_16 ] &
( ~ V_11 ->
V_22 [ V_16 ] ) ;
}
} else {
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
V_34 [ V_16 ] =
F_8 ( V_11 -> V_23 + 20 +
( V_16 * 4 ) ) ;
V_34 [ V_16 ] =
V_34 [ V_16 ] & V_11 ->
V_22 [ V_16 ] ;
}
}
} else {
F_3 ( L_1 ) ;
V_13 = - 101 ;
}
} else {
F_3 ( L_2 ) ;
V_13 = - 100 ;
}
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 = V_6 -> V_14 ;
unsigned char V_15 = 0 ;
unsigned char V_17 =
( unsigned char ) ( V_9 -> V_18 / 8 ) ;
unsigned char V_27 = F_6 ( V_6 -> V_28 ) ;
unsigned char V_37 = F_7 ( V_6 -> V_28 ) ;
unsigned int V_31 = 0 ;
if ( V_6 -> V_14 >= 1 ) {
V_15 = ( unsigned char ) V_7 [ 0 ] ;
if ( ( V_15 == V_38 ) ||
( V_15 == V_39 ) ||
( V_15 == V_40 ) ||
( V_15 == V_41 ) ) {
if ( V_27 < V_17 ) {
if ( ( ( V_11 -> V_22
[ V_27 /
4 ] >> ( 8 *
( V_27
%
4 ) ) ) &
0xFF ) == 0xFF ) {
if ( ( ( V_15 == V_38 ) || ( V_15 == V_40 ) ) && ( V_37 > 7 ) ) {
F_3 ( L_4 ) ;
V_13 = - 103 ;
}
if ( ( ( V_15 == V_40 ) || ( V_15 == V_41 ) ) && ( V_11 -> V_24 == V_26 ) ) {
F_3 ( L_6 ) ;
V_13 = - 104 ;
}
if ( ( ( V_15 == V_39 ) || ( V_15 == V_41 ) ) && ( V_6 -> V_14 < 2 ) ) {
F_3 ( L_1 ) ;
V_13 = - 101 ;
}
} else {
F_3 ( L_7 ,
( unsigned long ) V_11 ->
V_22 [ 0 ] ) ;
V_13 = - 102 ;
}
} else {
F_3 ( L_8 ,
V_27 , V_17 ) ;
V_13 = - 102 ;
}
} else {
F_3 ( L_2 ) ;
V_13 = - 100 ;
}
} else {
F_3 ( L_1 ) ;
V_13 = - 101 ;
}
if ( V_13 >= 0 ) {
V_31 =
F_8 ( V_11 -> V_23 + 20 + ( ( V_27 / 4 ) * 4 ) ) ;
if ( V_11 -> V_24 == V_26 ) {
V_31 =
V_31 & ( 0xFFFFFFFFUL -
( 0xFFUL << ( 8 * ( V_27 % 4 ) ) ) ) ;
}
if ( V_15 == V_38 ) {
V_31 =
V_31 | ( 1UL << ( ( 8 * ( V_27 %
4 ) ) + V_37 ) ) ;
}
if ( V_15 == V_39 ) {
V_31 =
V_31 | ( ( V_7 [ 1 ] & 0xFF ) << ( 8 *
( V_27 % 4 ) ) ) ;
}
if ( V_15 == V_40 ) {
V_31 =
V_31 & ( 0xFFFFFFFFUL -
( 1UL << ( ( 8 * ( V_27 % 4 ) ) +
V_37 ) ) ) ;
}
if ( V_15 == V_41 ) {
V_31 =
V_31 & ( 0xFFFFFFFFUL -
( ( V_7 [ 1 ] & 0xFF ) << ( 8 * ( V_27 %
4 ) ) ) ) ;
}
F_4 ( V_31 ,
V_11 -> V_23 + 20 + ( ( V_27 / 4 ) * 4 ) ) ;
}
return V_13 ;
}
static int F_12 ( struct V_1 * V_2 )
{
return 0 ;
}
