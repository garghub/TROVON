static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_12 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned char V_15 ;
unsigned char V_16 ;
unsigned int V_17 ;
V_13 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_14 = ( unsigned char ) V_7 [ 0 ] ;
V_15 = ( unsigned char ) V_7 [ 1 ] ;
V_16 = ( unsigned char ) V_7 [ 2 ] ;
V_17 = ( unsigned int ) V_7 [ 3 ] ;
V_11 = V_6 -> V_19 ;
if ( V_13 <= 3 ) {
if ( ( V_9 -> V_20 .
V_21 [ V_13 ] &
V_22 ) ==
V_22 ) {
if ( V_14 <= 3 ) {
if ( ( V_15 == 0 )
|| ( V_15 == 1 ) ) {
if ( ( V_16 <= 2 )
|| ( V_14 > 0 ) ) {
if ( V_17 > 1 ) {
V_12 =
F_3 ( V_9 ->
V_20 .
V_23 +
20 +
( 64 * V_13 ) ) ;
F_4 ( V_17 ,
V_9 ->
V_20 .
V_23 +
( V_14
* 4 ) +
( 64 * V_13 ) ) ;
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26 =
( V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26 &
( 0xFFFFFFFFUL -
( 1UL << ( 8 + V_14 ) ) ) ) | ( ( 1UL & ( ~ V_15 ) ) << ( 8 + V_14 ) ) ;
if ( ( V_16 > 0 ) && ( V_14 > 1 ) ) {
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
=
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
| ( 1UL
<< ( 4 + V_14 ) ) ;
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
=
( V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
&
( 0xFFFFFFFFUL
-
( 1UL << ( 12 + V_14 ) ) ) ) | ( ( 1UL & ( V_16 - 1 ) ) << ( 12 + V_14 ) ) ;
} else {
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
=
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
&
( 0xFFFFFFFFUL
-
( 1UL << ( 4 + V_14 ) ) ) ;
}
F_4 ( V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26 ,
V_9 ->
V_20 .
V_23 +
20 +
( 64 * V_13 ) ) ;
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_27
[ V_14 ] .
V_28
= 1 ;
} else {
F_5 ( L_1 ) ;
V_11 = - 6 ;
}
} else {
F_5 ( L_2 ) ;
V_11 = - 5 ;
}
} else {
F_5 ( L_3 ) ;
V_11 = - 4 ;
}
} else {
F_5 ( L_4 ) ;
V_11 = - 3 ;
}
} else {
F_5 ( L_5 ) ;
V_11 = - 2 ;
}
} else {
F_5 ( L_5 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned char V_29 ;
unsigned char V_30 ;
unsigned char V_31 ;
V_11 = V_6 -> V_19 ;
V_13 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_31 = ( unsigned char ) V_7 [ 0 ] ;
V_14 = ( unsigned char ) V_7 [ 1 ] ;
V_29 = ( unsigned char ) V_7 [ 2 ] ;
V_30 = ( unsigned char ) V_7 [ 3 ] ;
if ( V_13 <= 3 ) {
if ( V_14 <= 3 ) {
if ( V_9 -> V_24 [ V_13 ] .
V_25 .
V_27 [ V_14 ] .
V_28 == 1 ) {
switch ( V_31 ) {
case V_32 :
if ( V_29 ==
V_33
|| V_29 ==
V_34 ) {
if ( V_30 ==
V_32
|| V_30
== V_35 ) {
if ( V_30
==
V_35 )
{
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
=
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
&
( 0xFFFFFFFFUL
-
( 1UL << V_14 ) ) ;
} else {
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
=
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26
| ( 1UL
<<
V_14 ) ;
V_9 -> V_36 = V_37 ;
}
if ( V_11 >= 0 ) {
F_4 ( V_9 ->
V_24
[ V_13 ] .
V_25 .
V_26 ,
V_9 ->
V_20 .
V_23
+ 20 +
( 64 * V_13 ) ) ;
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_38
=
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_38
| ( 1UL
<<
V_14 ) ;
V_9 ->
V_24
[ V_13 ] .
V_25 .
V_38
=
( V_9 ->
V_24
[ V_13 ] .
V_25 .
V_38
&
( 0xFFFFFFFFUL
-
( 1 << ( V_14 + 4 ) ) ) ) | ( ( V_29 & 1UL ) << ( 4 + V_14 ) ) ;
F_4 ( V_9 ->
V_24
[ V_13 ] .
V_25 .
V_38 ,
V_9 ->
V_20 .
V_23
+ 16 +
( 64 * V_13 ) ) ;
}
} else {
F_5 ( L_6 ) ;
V_11 = - 6 ;
}
} else {
F_5 ( L_7 ) ;
V_11 = - 5 ;
}
break;
case V_35 :
V_9 -> V_24 [ V_13 ] .
V_25 .
V_38 =
V_9 ->
V_24 [ V_13 ] .
V_25 .
V_38 &
( 0xFFFFFFFFUL -
( 1UL << V_14 ) ) ;
F_4 ( V_9 -> V_24 [ V_13 ] .
V_25 .
V_38 ,
V_9 -> V_20 .
V_23 + 16 +
( 64 * V_13 ) ) ;
break;
}
} else {
F_5 ( L_8 ) ;
V_11 = - 4 ;
}
} else {
F_5 ( L_4 ) ;
V_11 = - 3 ;
}
} else {
F_5 ( L_9 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_39 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned char * V_40 ;
unsigned char V_41 ;
unsigned int * V_42 ;
unsigned int V_43 ;
V_11 = V_6 -> V_19 ;
V_13 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_41 = ( unsigned char ) V_7 [ 0 ] ;
V_14 = ( unsigned char ) V_7 [ 1 ] ;
V_40 = ( unsigned char * ) & V_7 [ 0 ] ;
V_42 = ( unsigned int * ) & V_7 [ 1 ] ;
if ( V_13 <= 3 ) {
if ( V_14 <= 3 ) {
if ( V_9 -> V_24 [ V_13 ] .
V_25 .
V_27 [ V_14 ] .
V_28 == 1 ) {
switch ( V_41 ) {
case V_44 :
V_39 =
F_3 ( V_9 -> V_20 .
V_23 + 16 +
( 64 * V_13 ) ) ;
V_9 -> V_24 [ V_13 ] .
V_25 .
V_39 = V_9 ->
V_24 [ V_13 ] .
V_25 .
V_39 |
V_39 ;
* V_40 =
( unsigned char ) ( V_9 ->
V_24 [ V_13 ] .
V_25 .
V_39 >> ( 1 +
V_14 ) ) & 1 ;
V_9 -> V_24 [ V_13 ] .
V_25 .
V_39 =
V_9 ->
V_24 [ V_13 ] .
V_25 .
V_39 &
( 0xFFFFFFFFUL - ( 1 << ( 1 +
V_14 ) ) ) ;
* V_42 =
F_3 ( V_9 -> V_20 .
V_23 +
( 4 * V_14 ) +
( 64 * V_13 ) ) ;
break;
case V_45 :
V_43 = ( unsigned int ) V_7 [ 2 ] ;
F_4 ( V_43 ,
V_9 -> V_20 .
V_23 +
( 4 * V_14 ) +
( 64 * V_13 ) ) ;
}
} else {
F_5 ( L_8 ) ;
V_11 = - 4 ;
}
} else {
F_5 ( L_4 ) ;
V_11 = - 3 ;
}
} else {
F_5 ( L_9 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 0 ] = V_9 -> V_46 .
V_47 [ V_9 ->
V_46 . V_48 ] . V_49 ;
V_7 [ 1 ] = V_9 -> V_46 .
V_47 [ V_9 ->
V_46 . V_48 ] . V_50 ;
V_7 [ 2 ] = V_9 -> V_46 .
V_47 [ V_9 ->
V_46 . V_48 ] . V_51 ;
V_9 -> V_46 .
V_48 = ( V_9 ->
V_46 . V_48 + 1 ) % V_52 ;
return V_6 -> V_19 ;
}
