static int F_1 ( struct V_1 * V_2 )
{
if ( ( F_2 ( V_3 -> V_4 + 8 ) & 0x80000UL ) == 0x80000UL )
return 1 ;
else
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_12 = 0 ;
unsigned char V_13 = 0 ;
unsigned int V_14 = 0 ;
unsigned int V_15 = 0 ;
if ( V_8 -> V_11 == 4 ) {
V_13 = ( unsigned char ) V_9 [ 1 ] ;
V_12 = ( unsigned char ) V_9 [ 2 ] ;
V_14 = ( unsigned int ) V_9 [ 3 ] ;
if ( ( V_16 -> V_17 & ( 1 << V_12 ) ) !=
0 ) {
if ( V_14 <= 65535 ) {
V_15 = V_14 ;
if ( V_12 == 1 ) {
V_15 =
V_15 * 1000UL ;
}
if ( V_12 == 2 ) {
V_15 =
V_15 * 1000000UL ;
}
if ( V_15 >=
V_3 -> V_18 .
V_19 ) {
if ( ( V_13 == V_20 )
|| ( V_13 ==
V_21 ) ) {
if ( ( ( V_13 == V_20 )
&& ( V_3 -> V_18 . V_22 == 0 ) )
|| ( ( V_13 == V_21 )
&& ( V_16 -> V_23 == 0 ) )
) {
F_4 ( L_1 ) ;
V_10 = - 1 ;
} else {
if ( F_1 ( V_2 ) == 0 ) {
V_3 ->
V_24
=
( unsigned int )
V_14 ;
V_3 ->
V_25
=
V_12 ;
V_3 ->
V_26
=
V_13 ;
V_3 ->
V_27
= 1 ;
F_5 ( ( unsigned int ) V_12 ,
V_3 -> V_4 + 36 ) ;
F_5 ( V_14 , V_3 -> V_4 + 32 ) ;
} else {
F_4 ( L_2 ) ;
V_10 =
- 10 ;
}
}
} else {
F_4 ( L_1 ) ;
V_10 = - 1 ;
}
} else {
F_4 ( L_3 ) ;
V_10 = - 3 ;
}
} else {
F_4 ( L_3 ) ;
V_10 = - 3 ;
}
} else {
F_4 ( L_4 ) ;
V_10 = - 2 ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
if ( V_8 -> V_11 >= 1 ) {
switch ( ( unsigned char ) V_9 [ 0 ] ) {
case V_28 :
V_10 =
F_3 ( V_2 ,
V_6 , V_8 , V_9 ) ;
break;
default:
V_10 = - 100 ;
F_4 ( L_6 , V_9 [ 0 ] ) ;
break;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_29 = ( unsigned char ) F_8 ( V_8 -> V_30 ) ;
unsigned char V_31 = ( unsigned char ) F_9 ( V_8 -> V_30 ) ;
unsigned int V_32 = 0 ;
unsigned int V_33 = 0 ;
unsigned int V_34 = 0 ;
unsigned char V_35 = 0 ;
if ( V_3 -> V_27 ) {
if ( ( ( V_31 < V_3 -> V_18 . V_22 )
&& ( V_3 -> V_26 == V_20 ) )
|| ( ( V_31 < V_16 -> V_23 )
&& ( V_3 -> V_26 == V_21 ) ) ) {
if ( V_29 > 7 ) {
V_10 = - 4 ;
F_4 ( L_7 ,
V_31 , V_29 ) ;
}
} else {
V_10 = - 3 ;
F_4 ( L_8 , V_31 ) ;
}
if ( V_10 >= 0 ) {
if ( ( V_35 != 0 ) || ( ( V_35 == 0 )
&& ( V_8 -> V_11 >= 1 ) ) ) {
if ( F_1 ( V_2 ) == 0 ) {
F_5 ( 0x10000UL , V_3 -> V_4 + 12 ) ;
V_32 = F_2 ( V_3 -> V_4 + 4 ) ;
V_32 = V_32 & 0xFFFFFEF0UL ;
F_5 ( V_32 , V_3 -> V_4 + 4 ) ;
V_33 =
( V_29 & 3 ) |
( ( unsigned int ) ( V_29 >> 2 )
<< 6 ) | ( ( unsigned int ) V_3 ->
V_26 << 7 ) ;
F_5 ( V_33 ,
V_3 -> V_4 + 0 ) ;
F_5 ( V_32 | 0x100UL ,
V_3 -> V_4 + 4 ) ;
F_5 ( ( unsigned int ) V_31 ,
V_3 -> V_4 + 0 ) ;
F_5 ( V_32 , V_3 -> V_4 + 4 ) ;
F_5 ( 1 , V_3 -> V_4 + 48 ) ;
V_3 -> V_36 =
V_35 ;
V_3 -> V_37 = 1 ;
if ( V_35 == 0 ) {
for ( V_34 = 0 ;
V_34 <
V_8 -> V_11 ;
V_34 ++ ) {
F_5 ( 0x80000UL , V_3 -> V_4 + 8 ) ;
do {
V_32 = F_2 ( V_3 -> V_4 + 20 ) ;
V_32 = V_32 & 1 ;
} while ( V_32 != 1 );
V_9 [ V_34 ] = ( unsigned int ) F_2 ( V_3 -> V_4 + 28 ) ;
}
} else {
F_5 ( 0x180000UL , V_3 -> V_4 + 8 ) ;
}
} else {
F_4 ( L_2 ) ;
V_10 = - 10 ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
}
} else {
F_4 ( L_9 ) ;
V_10 = - 1 ;
}
return V_10 ;
}
static void F_10 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
unsigned char V_40 = 0 ;
unsigned int V_41 = 0 ;
V_41 = F_2 ( V_3 -> V_4 + 16 ) ;
if ( ( V_41 & 0x2UL ) == 0x2UL ) {
F_5 ( V_41 , V_3 -> V_4 + 16 ) ;
if ( V_3 -> V_36 == 1 ) {
for ( V_40 = 0 ;
V_40 < V_3 -> V_37 ;
V_40 ++ ) {
V_3 -> V_42 [ V_40 ] =
( unsigned int ) F_2 ( V_3 -> V_4 + 28 ) ;
}
V_3 -> V_36 = 2 ;
F_11 ( V_43 , V_3 -> V_44 , 0 ) ;
}
}
}
static int F_12 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
unsigned char V_45 = ( unsigned char ) F_8 ( V_8 -> V_30 ) ;
unsigned char V_31 = ( unsigned char ) F_9 ( V_8 -> V_30 ) ;
unsigned int V_41 = 0 ;
int V_10 = V_8 -> V_11 ;
if ( V_8 -> V_11 >= 1 ) {
if ( V_31 < V_3 -> V_18 . V_46 ) {
if ( V_45 < 2 ) {
F_5 ( V_45 , V_3 -> V_4 + 96 ) ;
F_5 ( ( V_9 [ 0 ] << 8 ) | V_31 ,
V_3 -> V_4 + 100 ) ;
do {
V_41 = F_2 ( V_3 -> V_4 + 96 ) ;
} while ( ( V_41 & 0x100 ) != 0x100 );
} else {
V_10 = - 4 ;
F_4 ( L_7 ,
V_31 , V_45 ) ;
}
} else {
V_10 = - 3 ;
F_4 ( L_8 , V_31 ) ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_47 = 0 ;
if ( V_8 -> V_11 >= 1 ) {
V_47 = ( unsigned char ) V_9 [ 0 ] ;
if ( V_47 == V_48 ) {
if ( ( V_47 == V_48 )
&& ( V_8 -> V_11 != 2 ) ) {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
} else {
F_4 ( L_10 ) ;
V_10 = - 100 ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
if ( ( V_10 >= 0 )
&& ( V_47 == V_48 ) ) {
if ( ( V_9 [ 1 ] == 0 ) || ( V_9 [ 1 ] == 0xFF ) ) {
V_3 -> V_49 [ 0 ] =
V_3 -> V_49 [ 0 ] | V_9 [ 1 ] ;
} else {
F_4 ( L_11 ) ;
V_10 = - 1 ;
}
}
if ( V_10 >= 0 ) {
if ( V_47 == V_48 ) {
F_14 ( V_9 [ 1 ] , V_3 -> V_50 + 224 ) ;
}
}
return V_10 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_51 = 0 ;
unsigned int V_52 = 0 ;
unsigned int V_53 = 0 ;
unsigned int V_41 = 0 ;
if ( V_8 -> V_11 >= 2 ) {
V_52 = V_9 [ 0 ] ;
V_53 = V_9 [ 1 ] ;
if ( ( ( V_52 & 0XFF00FF00 ) == 0 ) &&
( ( ( V_3 -> V_49 [ 0 ] & 0xFF ) == 0xFF )
|| ( ( ( V_3 -> V_49 [ 0 ] &
0xFF ) == 0 )
&& ( ( V_52 & 0XFF0000 ) ==
0 ) ) ) ) {
if ( V_52 ) {
if ( V_52 & 0xFF ) {
V_41 = F_16 ( V_3 -> V_50 + 80 ) ;
for ( V_51 = 0 ; V_51 < 8 ;
V_51 ++ ) {
if ( ( V_52 >>
V_51 ) &
1 ) {
V_41 =
( V_41 &
( 0xFF - ( 1 << V_51 ) ) ) | ( V_53 & ( 1 << V_51 ) ) ;
}
}
F_14 ( V_41 , V_3 -> V_50 + 80 ) ;
}
if ( V_52 & 0xFF0000 ) {
V_53 = V_53 >> 16 ;
V_52 = V_52 >> 16 ;
V_41 = F_16 ( V_3 -> V_50 + 112 ) ;
for ( V_51 = 0 ; V_51 < 8 ;
V_51 ++ ) {
if ( ( V_52 >>
V_51 ) &
1 ) {
V_41 =
( V_41 &
( 0xFF - ( 1 << V_51 ) ) ) | ( V_53 & ( 1 << V_51 ) ) ;
}
}
F_14 ( V_41 , V_3 -> V_50 + 112 ) ;
}
}
V_9 [ 1 ] = F_16 ( V_3 -> V_50 + 80 ) ;
V_9 [ 1 ] = V_9 [ 1 ] | ( F_16 ( V_3 -> V_50 + 64 ) << 8 ) ;
if ( ( V_3 -> V_49 [ 0 ] & 0xFF ) == 0 ) {
V_9 [ 1 ] =
V_9 [ 1 ] | ( F_16 ( V_3 -> V_50 +
96 ) << 16 ) ;
} else {
V_9 [ 1 ] =
V_9 [ 1 ] | ( F_16 ( V_3 -> V_50 +
112 ) << 16 ) ;
}
} else {
F_4 ( L_12 ) ;
V_10 = - 4 ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
unsigned char V_31 = ( unsigned char ) F_9 ( V_8 -> V_30 ) ;
int V_10 = V_8 -> V_11 ;
unsigned int * V_54 = V_9 ;
if ( V_8 -> V_11 >= 1 ) {
if ( V_31 < 8 ) {
V_54 [ 0 ] = F_16 ( V_3 -> V_50 + 80 ) ;
V_54 [ 0 ] = ( V_54 [ 0 ] >> V_31 ) & 1 ;
} else {
if ( ( V_31 > 7 ) && ( V_31 < 16 ) ) {
V_54 [ 0 ] = F_16 ( V_3 -> V_50 + 64 ) ;
V_54 [ 0 ] =
( V_54 [ 0 ] >> ( V_31 -
8 ) ) & 1 ;
} else {
if ( ( V_31 > 15 ) && ( V_31 < 24 ) ) {
if ( ( V_3 -> V_49 [ 0 ]
& 0xFF ) == 0 ) {
V_54 [ 0 ] =
F_16 ( V_3 -> V_50 +
96 ) ;
V_54 [ 0 ] =
( V_54 [ 0 ] >>
( V_31 - 16 ) ) & 1 ;
} else {
V_54 [ 0 ] =
F_16 ( V_3 -> V_50 +
112 ) ;
V_54 [ 0 ] =
( V_54 [ 0 ] >>
( V_31 - 16 ) ) & 1 ;
}
} else {
V_10 = - 3 ;
F_4 ( L_8 ,
V_31 ) ;
}
}
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_31 = ( unsigned char ) F_9 ( V_8 -> V_30 ) ;
unsigned char V_55 = 0 ;
unsigned int V_41 = 0 ;
if ( V_8 -> V_11 >= 1 ) {
V_55 = ( unsigned char ) V_9 [ 0 ] ;
if ( V_31 < 8 ) {
V_41 = F_16 ( V_3 -> V_50 + 80 ) ;
V_41 =
( V_41 & ( 0xFF -
( 1 << V_31 ) ) ) | ( ( V_55 & 1 ) <<
V_31 ) ;
F_14 ( V_41 , V_3 -> V_50 + 80 ) ;
} else {
if ( ( V_31 > 15 ) && ( V_31 < 24 ) ) {
if ( ( V_3 -> V_49 [ 0 ] & 0xFF )
== 0xFF ) {
V_41 = F_16 ( V_3 -> V_50 + 112 ) ;
V_41 =
( V_41 & ( 0xFF -
( 1 << ( V_31 -
16 ) ) ) ) |
( ( V_55 & 1 ) << ( V_31 -
16 ) ) ;
F_14 ( V_41 , V_3 -> V_50 + 112 ) ;
} else {
V_10 = - 3 ;
F_4 ( L_8 ,
V_31 ) ;
}
} else {
V_10 = - 3 ;
F_4 ( L_8 ,
V_31 ) ;
}
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_31 = ( unsigned char ) F_9 ( V_8 -> V_30 ) ;
unsigned int V_32 = 0 ;
if ( V_31 <= V_3 -> V_18 . V_56 ) {
if ( V_8 -> V_11 >= 1 ) {
V_32 = F_16 ( V_3 -> V_50 + 32 ) ;
* V_9 = ( V_32 >> V_31 ) & 1 ;
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
} else {
F_4 ( L_13 ) ;
V_10 = - 3 ;
}
return V_10 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned int V_32 = 0 ;
if ( V_8 -> V_11 >= 1 ) {
V_32 = F_16 ( V_3 -> V_50 + 32 ) ;
* V_9 = V_32 & 0xf ;
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_51 = 0 ;
unsigned int V_52 = 0 ;
unsigned int V_53 = 0 ;
unsigned int V_41 = 0 ;
if ( V_8 -> V_11 >= 2 ) {
V_52 = V_9 [ 0 ] ;
V_53 = V_9 [ 1 ] ;
if ( ( V_52 & 0XFFFFFFF0 ) == 0 ) {
if ( V_52 & 0xF ) {
V_41 = F_16 ( V_3 -> V_50 + 48 ) ;
for ( V_51 = 0 ; V_51 < 4 ;
V_51 ++ ) {
if ( ( V_52 >> V_51 ) &
1 ) {
V_41 =
( V_41 & ( 0xF -
( 1 << V_51 ) ) ) | ( V_53 & ( 1 << V_51 ) ) ;
}
}
F_14 ( V_41 , V_3 -> V_50 + 48 ) ;
}
V_9 [ 1 ] = F_16 ( V_3 -> V_50 + 48 ) ;
} else {
F_4 ( L_12 ) ;
V_10 = - 4 ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_31 = F_9 ( V_8 -> V_30 ) ;
unsigned char V_55 = 0 ;
unsigned int V_41 = 0 ;
if ( V_8 -> V_11 >= 1 ) {
if ( V_31 < V_3 -> V_18 . V_57 ) {
V_55 = ( unsigned char ) V_9 [ 0 ] ;
V_41 = F_16 ( V_3 -> V_50 + 48 ) ;
V_41 =
( V_41 & ( 0xF -
( 1 << V_31 ) ) ) | ( ( V_55 & 1 ) <<
V_31 ) ;
F_14 ( V_41 , V_3 -> V_50 + 48 ) ;
} else {
F_4 ( L_13 ) ;
V_10 = - 3 ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
int V_10 = V_8 -> V_11 ;
unsigned char V_31 = F_9 ( V_8 -> V_30 ) ;
unsigned int V_41 = 0 ;
if ( V_8 -> V_11 >= 1 ) {
if ( V_31 < V_3 -> V_18 . V_57 ) {
V_41 = F_16 ( V_3 -> V_50 + 48 ) ;
V_41 = ( V_41 >> V_31 ) & 1 ;
* V_9 = V_41 ;
} else {
F_4 ( L_13 ) ;
V_10 = - 3 ;
}
} else {
F_4 ( L_5 ) ;
V_10 = - 101 ;
}
return V_10 ;
}
static int F_24 ( struct V_1 * V_2 )
{
unsigned char V_58 = 0 ;
F_25 ( V_2 -> V_38 ) ;
V_3 -> V_36 = 0 ;
F_5 ( 0 , V_3 -> V_4 + 8 ) ;
F_5 ( F_2 ( V_3 -> V_4 + 16 ) , V_3 -> V_4 + 16 ) ;
F_2 ( V_3 -> V_4 + 20 ) ;
for ( V_58 = 0 ; V_58 < 16 ; V_58 ++ ) {
F_2 ( V_3 -> V_4 + 28 ) ;
}
F_26 ( V_2 -> V_38 ) ;
return 0 ;
}
