static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ( F_2 ( V_4 -> V_6 + 8 ) & 0x80000UL ) == 0x80000UL )
return 1 ;
else
return 0 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
const struct V_12 * V_13 = F_4 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 = V_10 -> V_15 ;
unsigned char V_16 = 0 ;
unsigned char V_17 = 0 ;
unsigned int V_18 = 0 ;
unsigned int V_19 = 0 ;
if ( V_10 -> V_15 == 4 ) {
V_17 = ( unsigned char ) V_11 [ 1 ] ;
V_16 = ( unsigned char ) V_11 [ 2 ] ;
V_18 = ( unsigned int ) V_11 [ 3 ] ;
if ( ( V_13 -> V_20 & ( 1 << V_16 ) ) !=
0 ) {
if ( V_18 <= 65535 ) {
V_19 = V_18 ;
if ( V_16 == 1 ) {
V_19 =
V_19 * 1000UL ;
}
if ( V_16 == 2 ) {
V_19 =
V_19 * 1000000UL ;
}
if ( V_19 >=
V_4 -> V_21 .
V_22 ) {
if ( ( V_17 == V_23 )
|| ( V_17 ==
V_24 ) ) {
if ( ( ( V_17 == V_23 )
&& ( V_4 -> V_21 . V_25 == 0 ) )
|| ( ( V_17 == V_24 )
&& ( V_13 -> V_26 == 0 ) )
) {
F_5 ( L_1 ) ;
V_14 = - 1 ;
} else {
if ( F_1 ( V_2 ) == 0 ) {
V_4 ->
V_27
=
( unsigned int )
V_18 ;
V_4 ->
V_28
=
V_16 ;
V_4 ->
V_29
=
V_17 ;
V_4 ->
V_30
= 1 ;
F_6 ( ( unsigned int ) V_16 ,
V_4 -> V_6 + 36 ) ;
F_6 ( V_18 , V_4 -> V_6 + 32 ) ;
} else {
F_5 ( L_2 ) ;
V_14 =
- 10 ;
}
}
} else {
F_5 ( L_1 ) ;
V_14 = - 1 ;
}
} else {
F_5 ( L_3 ) ;
V_14 = - 3 ;
}
} else {
F_5 ( L_3 ) ;
V_14 = - 3 ;
}
} else {
F_5 ( L_4 ) ;
V_14 = - 2 ;
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
int V_14 = V_10 -> V_15 ;
if ( V_10 -> V_15 >= 1 ) {
switch ( ( unsigned char ) V_11 [ 0 ] ) {
case V_31 :
V_14 =
F_3 ( V_2 ,
V_8 , V_10 , V_11 ) ;
break;
default:
V_14 = - 100 ;
F_5 ( L_6 , V_11 [ 0 ] ) ;
break;
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
const struct V_12 * V_13 = F_4 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 = V_10 -> V_15 ;
unsigned char V_32 = ( unsigned char ) F_9 ( V_10 -> V_33 ) ;
unsigned char V_34 = ( unsigned char ) F_10 ( V_10 -> V_33 ) ;
unsigned int V_35 = 0 ;
unsigned int V_36 = 0 ;
unsigned int V_37 = 0 ;
unsigned char V_38 = 0 ;
if ( V_4 -> V_30 ) {
if ( ( ( V_34 < V_4 -> V_21 . V_25 )
&& ( V_4 -> V_29 == V_23 ) )
|| ( ( V_34 < V_13 -> V_26 )
&& ( V_4 -> V_29 == V_24 ) ) ) {
if ( V_32 > 7 ) {
V_14 = - 4 ;
F_5 ( L_7 ,
V_34 , V_32 ) ;
}
} else {
V_14 = - 3 ;
F_5 ( L_8 , V_34 ) ;
}
if ( V_14 >= 0 ) {
if ( ( V_38 != 0 ) || ( ( V_38 == 0 )
&& ( V_10 -> V_15 >= 1 ) ) ) {
if ( F_1 ( V_2 ) == 0 ) {
F_6 ( 0x10000UL , V_4 -> V_6 + 12 ) ;
V_35 = F_2 ( V_4 -> V_6 + 4 ) ;
V_35 = V_35 & 0xFFFFFEF0UL ;
F_6 ( V_35 , V_4 -> V_6 + 4 ) ;
V_36 =
( V_32 & 3 ) |
( ( unsigned int ) ( V_32 >> 2 )
<< 6 ) | ( ( unsigned int ) V_4 ->
V_29 << 7 ) ;
F_6 ( V_36 ,
V_4 -> V_6 + 0 ) ;
F_6 ( V_35 | 0x100UL ,
V_4 -> V_6 + 4 ) ;
F_6 ( ( unsigned int ) V_34 ,
V_4 -> V_6 + 0 ) ;
F_6 ( V_35 , V_4 -> V_6 + 4 ) ;
F_6 ( 1 , V_4 -> V_6 + 48 ) ;
V_4 -> V_39 =
V_38 ;
V_4 -> V_40 = 1 ;
if ( V_38 == 0 ) {
for ( V_37 = 0 ;
V_37 <
V_10 -> V_15 ;
V_37 ++ ) {
F_6 ( 0x80000UL , V_4 -> V_6 + 8 ) ;
do {
V_35 = F_2 ( V_4 -> V_6 + 20 ) ;
V_35 = V_35 & 1 ;
} while ( V_35 != 1 );
V_11 [ V_37 ] = ( unsigned int ) F_2 ( V_4 -> V_6 + 28 ) ;
}
} else {
F_6 ( 0x180000UL , V_4 -> V_6 + 8 ) ;
}
} else {
F_5 ( L_2 ) ;
V_14 = - 10 ;
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
}
} else {
F_5 ( L_9 ) ;
V_14 = - 1 ;
}
return V_14 ;
}
static void F_11 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char V_43 = 0 ;
unsigned int V_44 = 0 ;
V_44 = F_2 ( V_4 -> V_6 + 16 ) ;
if ( ( V_44 & 0x2UL ) == 0x2UL ) {
F_6 ( V_44 , V_4 -> V_6 + 16 ) ;
if ( V_4 -> V_39 == 1 ) {
for ( V_43 = 0 ;
V_43 < V_4 -> V_40 ;
V_43 ++ ) {
V_4 -> V_45 [ V_43 ] =
( unsigned int ) F_2 ( V_4 -> V_6 + 28 ) ;
}
V_4 -> V_39 = 2 ;
F_12 ( V_46 , V_4 -> V_47 , 0 ) ;
}
}
}
static int F_13 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char V_48 = ( unsigned char ) F_9 ( V_10 -> V_33 ) ;
unsigned char V_34 = ( unsigned char ) F_10 ( V_10 -> V_33 ) ;
unsigned int V_44 = 0 ;
int V_14 = V_10 -> V_15 ;
if ( V_10 -> V_15 >= 1 ) {
if ( V_34 < V_4 -> V_21 . V_49 ) {
if ( V_48 < 2 ) {
F_6 ( V_48 , V_4 -> V_6 + 96 ) ;
F_6 ( ( V_11 [ 0 ] << 8 ) | V_34 ,
V_4 -> V_6 + 100 ) ;
do {
V_44 = F_2 ( V_4 -> V_6 + 96 ) ;
} while ( ( V_44 & 0x100 ) != 0x100 );
} else {
V_14 = - 4 ;
F_5 ( L_7 ,
V_34 , V_48 ) ;
}
} else {
V_14 = - 3 ;
F_5 ( L_8 , V_34 ) ;
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 = V_10 -> V_15 ;
unsigned char V_50 = 0 ;
if ( V_10 -> V_15 >= 1 ) {
V_50 = ( unsigned char ) V_11 [ 0 ] ;
if ( V_50 == V_51 ) {
if ( ( V_50 == V_51 )
&& ( V_10 -> V_15 != 2 ) ) {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
} else {
F_5 ( L_10 ) ;
V_14 = - 100 ;
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
if ( ( V_14 >= 0 )
&& ( V_50 == V_51 ) ) {
if ( ( V_11 [ 1 ] == 0 ) || ( V_11 [ 1 ] == 0xFF ) ) {
V_4 -> V_52 [ 0 ] =
V_4 -> V_52 [ 0 ] | V_11 [ 1 ] ;
} else {
F_5 ( L_11 ) ;
V_14 = - 1 ;
}
}
if ( V_14 >= 0 ) {
if ( V_50 == V_51 ) {
F_15 ( V_11 [ 1 ] , V_4 -> V_53 + 224 ) ;
}
}
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 = V_10 -> V_15 ;
unsigned char V_54 = 0 ;
unsigned int V_55 = 0 ;
unsigned int V_56 = 0 ;
unsigned int V_44 = 0 ;
if ( V_10 -> V_15 >= 2 ) {
V_55 = V_11 [ 0 ] ;
V_56 = V_11 [ 1 ] ;
if ( ( ( V_55 & 0XFF00FF00 ) == 0 ) &&
( ( ( V_4 -> V_52 [ 0 ] & 0xFF ) == 0xFF )
|| ( ( ( V_4 -> V_52 [ 0 ] &
0xFF ) == 0 )
&& ( ( V_55 & 0XFF0000 ) ==
0 ) ) ) ) {
if ( V_55 ) {
if ( V_55 & 0xFF ) {
V_44 = F_17 ( V_4 -> V_53 + 80 ) ;
for ( V_54 = 0 ; V_54 < 8 ;
V_54 ++ ) {
if ( ( V_55 >>
V_54 ) &
1 ) {
V_44 =
( V_44 &
( 0xFF - ( 1 << V_54 ) ) ) | ( V_56 & ( 1 << V_54 ) ) ;
}
}
F_15 ( V_44 , V_4 -> V_53 + 80 ) ;
}
if ( V_55 & 0xFF0000 ) {
V_56 = V_56 >> 16 ;
V_55 = V_55 >> 16 ;
V_44 = F_17 ( V_4 -> V_53 + 112 ) ;
for ( V_54 = 0 ; V_54 < 8 ;
V_54 ++ ) {
if ( ( V_55 >>
V_54 ) &
1 ) {
V_44 =
( V_44 &
( 0xFF - ( 1 << V_54 ) ) ) | ( V_56 & ( 1 << V_54 ) ) ;
}
}
F_15 ( V_44 , V_4 -> V_53 + 112 ) ;
}
}
V_11 [ 1 ] = F_17 ( V_4 -> V_53 + 80 ) ;
V_11 [ 1 ] = V_11 [ 1 ] | ( F_17 ( V_4 -> V_53 + 64 ) << 8 ) ;
if ( ( V_4 -> V_52 [ 0 ] & 0xFF ) == 0 ) {
V_11 [ 1 ] =
V_11 [ 1 ] | ( F_17 ( V_4 -> V_53 +
96 ) << 16 ) ;
} else {
V_11 [ 1 ] =
V_11 [ 1 ] | ( F_17 ( V_4 -> V_53 +
112 ) << 16 ) ;
}
} else {
F_5 ( L_12 ) ;
V_14 = - 4 ;
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
return V_14 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char V_34 = ( unsigned char ) F_10 ( V_10 -> V_33 ) ;
int V_14 = V_10 -> V_15 ;
unsigned int * V_57 = V_11 ;
if ( V_10 -> V_15 >= 1 ) {
if ( V_34 < 8 ) {
V_57 [ 0 ] = F_17 ( V_4 -> V_53 + 80 ) ;
V_57 [ 0 ] = ( V_57 [ 0 ] >> V_34 ) & 1 ;
} else {
if ( ( V_34 > 7 ) && ( V_34 < 16 ) ) {
V_57 [ 0 ] = F_17 ( V_4 -> V_53 + 64 ) ;
V_57 [ 0 ] =
( V_57 [ 0 ] >> ( V_34 -
8 ) ) & 1 ;
} else {
if ( ( V_34 > 15 ) && ( V_34 < 24 ) ) {
if ( ( V_4 -> V_52 [ 0 ]
& 0xFF ) == 0 ) {
V_57 [ 0 ] =
F_17 ( V_4 -> V_53 +
96 ) ;
V_57 [ 0 ] =
( V_57 [ 0 ] >>
( V_34 - 16 ) ) & 1 ;
} else {
V_57 [ 0 ] =
F_17 ( V_4 -> V_53 +
112 ) ;
V_57 [ 0 ] =
( V_57 [ 0 ] >>
( V_34 - 16 ) ) & 1 ;
}
} else {
V_14 = - 3 ;
F_5 ( L_8 ,
V_34 ) ;
}
}
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
return V_14 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_14 = V_10 -> V_15 ;
unsigned char V_34 = ( unsigned char ) F_10 ( V_10 -> V_33 ) ;
unsigned char V_58 = 0 ;
unsigned int V_44 = 0 ;
if ( V_10 -> V_15 >= 1 ) {
V_58 = ( unsigned char ) V_11 [ 0 ] ;
if ( V_34 < 8 ) {
V_44 = F_17 ( V_4 -> V_53 + 80 ) ;
V_44 =
( V_44 & ( 0xFF -
( 1 << V_34 ) ) ) | ( ( V_58 & 1 ) <<
V_34 ) ;
F_15 ( V_44 , V_4 -> V_53 + 80 ) ;
} else {
if ( ( V_34 > 15 ) && ( V_34 < 24 ) ) {
if ( ( V_4 -> V_52 [ 0 ] & 0xFF )
== 0xFF ) {
V_44 = F_17 ( V_4 -> V_53 + 112 ) ;
V_44 =
( V_44 & ( 0xFF -
( 1 << ( V_34 -
16 ) ) ) ) |
( ( V_58 & 1 ) << ( V_34 -
16 ) ) ;
F_15 ( V_44 , V_4 -> V_53 + 112 ) ;
} else {
V_14 = - 3 ;
F_5 ( L_8 ,
V_34 ) ;
}
} else {
V_14 = - 3 ;
F_5 ( L_8 ,
V_34 ) ;
}
}
} else {
F_5 ( L_5 ) ;
V_14 = - 101 ;
}
return V_14 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_11 [ 1 ] = F_17 ( V_4 -> V_53 + 32 ) & 0xf ;
return V_10 -> V_15 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
struct V_9 * V_10 ,
unsigned int * V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_59 = V_11 [ 0 ] ;
unsigned int V_60 = V_11 [ 1 ] ;
V_8 -> V_61 = F_17 ( V_4 -> V_53 + 48 ) & 0xf ;
if ( V_59 ) {
V_8 -> V_61 &= ~ V_59 ;
V_8 -> V_61 |= ( V_60 & V_59 ) ;
F_15 ( V_8 -> V_61 , V_4 -> V_53 + 48 ) ;
}
V_11 [ 1 ] = V_8 -> V_61 ;
return V_10 -> V_15 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char V_62 = 0 ;
F_23 ( V_2 -> V_41 ) ;
V_4 -> V_39 = 0 ;
F_6 ( 0 , V_4 -> V_6 + 8 ) ;
F_6 ( F_2 ( V_4 -> V_6 + 16 ) , V_4 -> V_6 + 16 ) ;
F_2 ( V_4 -> V_6 + 20 ) ;
for ( V_62 = 0 ; V_62 < 16 ; V_62 ++ ) {
F_2 ( V_4 -> V_6 + 28 ) ;
}
F_24 ( V_2 -> V_41 ) ;
return 0 ;
}
