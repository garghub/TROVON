int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_9 ;
unsigned char V_10 ;
unsigned char V_11 ;
unsigned char V_12 ;
unsigned char V_13 ;
unsigned int V_14 ;
V_10 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_11 = ( unsigned char ) V_7 [ 0 ] ;
V_12 = ( unsigned char ) V_7 [ 1 ] ;
V_13 = ( unsigned char ) V_7 [ 2 ] ;
V_14 = ( unsigned int ) V_7 [ 3 ] ;
V_8 = V_6 -> V_16 ;
if ( V_10 <= 3 ) {
if ( ( V_17 -> V_18 .
V_19 [ V_10 ] &
V_20 ) ==
V_20 ) {
if ( V_11 <= 3 ) {
if ( ( V_12 == 0 )
|| ( V_12 == 1 ) ) {
if ( ( V_13 <= 2 )
|| ( V_11 > 0 ) ) {
if ( V_14 > 1 ) {
V_9 =
F_3 ( V_17 ->
V_18 .
V_21 +
20 +
( 64 * V_10 ) ) ;
F_4 ( V_14 ,
V_17 ->
V_18 .
V_21 +
( V_11
* 4 ) +
( 64 * V_10 ) ) ;
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24 =
( V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24 &
( 0xFFFFFFFFUL -
( 1UL << ( 8 + V_11 ) ) ) ) | ( ( 1UL & ( ~ V_12 ) ) << ( 8 + V_11 ) ) ;
if ( ( V_13 > 0 ) && ( V_11 > 1 ) ) {
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
=
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
| ( 1UL
<< ( 4 + V_11 ) ) ;
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
=
( V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
&
( 0xFFFFFFFFUL
-
( 1UL << ( 12 + V_11 ) ) ) ) | ( ( 1UL & ( V_13 - 1 ) ) << ( 12 + V_11 ) ) ;
} else {
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
=
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
&
( 0xFFFFFFFFUL
-
( 1UL << ( 4 + V_11 ) ) ) ;
}
F_4 ( V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24 ,
V_17 ->
V_18 .
V_21 +
20 +
( 64 * V_10 ) ) ;
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_25
[ V_11 ] .
V_26
= 1 ;
} else {
F_5 ( L_1 ) ;
V_8 = - 6 ;
}
} else {
F_5 ( L_2 ) ;
V_8 = - 5 ;
}
} else {
F_5 ( L_3 ) ;
V_8 = - 4 ;
}
} else {
F_5 ( L_4 ) ;
V_8 = - 3 ;
}
} else {
F_5 ( L_5 ) ;
V_8 = - 2 ;
}
} else {
F_5 ( L_5 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned char V_10 ;
unsigned char V_11 ;
unsigned char V_27 ;
unsigned char V_28 ;
unsigned char V_29 ;
V_8 = V_6 -> V_16 ;
V_10 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_29 = ( unsigned char ) V_7 [ 0 ] ;
V_11 = ( unsigned char ) V_7 [ 1 ] ;
V_27 = ( unsigned char ) V_7 [ 2 ] ;
V_28 = ( unsigned char ) V_7 [ 3 ] ;
if ( V_10 <= 3 ) {
if ( V_11 <= 3 ) {
if ( V_17 -> V_22 [ V_10 ] .
V_23 .
V_25 [ V_11 ] .
V_26 == 1 ) {
switch ( V_29 ) {
case V_30 :
if ( V_27 ==
V_31
|| V_27 ==
V_32 ) {
if ( V_28 ==
V_30
|| V_28
== V_33 ) {
if ( V_28
==
V_33 )
{
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
=
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
&
( 0xFFFFFFFFUL
-
( 1UL << V_11 ) ) ;
} else {
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
=
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24
| ( 1UL
<<
V_11 ) ;
V_17 -> V_34 = V_35 ;
}
if ( V_8 >= 0 ) {
F_4 ( V_17 ->
V_22
[ V_10 ] .
V_23 .
V_24 ,
V_17 ->
V_18 .
V_21
+ 20 +
( 64 * V_10 ) ) ;
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_36
=
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_36
| ( 1UL
<<
V_11 ) ;
V_17 ->
V_22
[ V_10 ] .
V_23 .
V_36
=
( V_17 ->
V_22
[ V_10 ] .
V_23 .
V_36
&
( 0xFFFFFFFFUL
-
( 1 << ( V_11 + 4 ) ) ) ) | ( ( V_27 & 1UL ) << ( 4 + V_11 ) ) ;
F_4 ( V_17 ->
V_22
[ V_10 ] .
V_23 .
V_36 ,
V_17 ->
V_18 .
V_21
+ 16 +
( 64 * V_10 ) ) ;
}
} else {
F_5 ( L_6 ) ;
V_8 = - 6 ;
}
} else {
F_5 ( L_7 ) ;
V_8 = - 5 ;
}
break;
case V_33 :
V_17 -> V_22 [ V_10 ] .
V_23 .
V_36 =
V_17 ->
V_22 [ V_10 ] .
V_23 .
V_36 &
( 0xFFFFFFFFUL -
( 1UL << V_11 ) ) ;
F_4 ( V_17 -> V_22 [ V_10 ] .
V_23 .
V_36 ,
V_17 -> V_18 .
V_21 + 16 +
( 64 * V_10 ) ) ;
break;
}
} else {
F_5 ( L_8 ) ;
V_8 = - 4 ;
}
} else {
F_5 ( L_4 ) ;
V_8 = - 3 ;
}
} else {
F_5 ( L_9 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_37 ;
unsigned char V_10 ;
unsigned char V_11 ;
unsigned char * V_38 ;
unsigned char V_39 ;
unsigned int * V_40 ;
unsigned int V_41 ;
V_8 = V_6 -> V_16 ;
V_10 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_39 = ( unsigned char ) V_7 [ 0 ] ;
V_11 = ( unsigned char ) V_7 [ 1 ] ;
V_38 = ( unsigned char * ) & V_7 [ 0 ] ;
V_40 = ( unsigned int * ) & V_7 [ 1 ] ;
if ( V_10 <= 3 ) {
if ( V_11 <= 3 ) {
if ( V_17 -> V_22 [ V_10 ] .
V_23 .
V_25 [ V_11 ] .
V_26 == 1 ) {
switch ( V_39 ) {
case V_42 :
V_37 =
F_3 ( V_17 -> V_18 .
V_21 + 16 +
( 64 * V_10 ) ) ;
V_17 -> V_22 [ V_10 ] .
V_23 .
V_37 = V_17 ->
V_22 [ V_10 ] .
V_23 .
V_37 |
V_37 ;
* V_38 =
( unsigned char ) ( V_17 ->
V_22 [ V_10 ] .
V_23 .
V_37 >> ( 1 +
V_11 ) ) & 1 ;
V_17 -> V_22 [ V_10 ] .
V_23 .
V_37 =
V_17 ->
V_22 [ V_10 ] .
V_23 .
V_37 &
( 0xFFFFFFFFUL - ( 1 << ( 1 +
V_11 ) ) ) ;
* V_40 =
F_3 ( V_17 -> V_18 .
V_21 +
( 4 * V_11 ) +
( 64 * V_10 ) ) ;
break;
case V_43 :
V_41 = ( unsigned int ) V_7 [ 2 ] ;
F_4 ( V_41 ,
V_17 -> V_18 .
V_21 +
( 4 * V_11 ) +
( 64 * V_10 ) ) ;
}
} else {
F_5 ( L_8 ) ;
V_8 = - 4 ;
}
} else {
F_5 ( L_4 ) ;
V_8 = - 3 ;
}
} else {
F_5 ( L_9 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = V_17 -> V_44 .
V_45 [ V_17 ->
V_44 . V_46 ] . V_47 ;
V_7 [ 1 ] = V_17 -> V_44 .
V_45 [ V_17 ->
V_44 . V_46 ] . V_48 ;
V_7 [ 2 ] = V_17 -> V_44 .
V_45 [ V_17 ->
V_44 . V_46 ] . V_49 ;
V_17 -> V_44 .
V_46 = ( V_17 ->
V_44 . V_46 + 1 ) % V_50 ;
return V_6 -> V_16 ;
}
