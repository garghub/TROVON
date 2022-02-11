static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_12 ;
unsigned char V_13 , V_14 , V_15 , V_16 ,
V_17 , V_18 ;
unsigned int V_19 ;
V_13 = F_2 ( V_6 -> V_20 ) ;
V_14 = ( unsigned char ) V_7 [ 0 ] ;
V_15 = ( unsigned char ) V_7 [ 1 ] ;
V_16 = ( unsigned char ) V_7 [ 2 ] ;
V_17 = ( unsigned char ) V_7 [ 3 ] ;
V_19 = ( unsigned int ) V_7 [ 4 ] ;
V_18 = ( unsigned char ) V_7 [ 5 ] ;
V_11 = V_6 -> V_21 ;
if ( V_13 < 4 ) {
if ( ( V_9 -> V_22 .
V_23 [ V_13 ] &
0xFFFF0000UL ) == V_24 ) {
if ( V_14 >= 2 && V_14 < 33 ) {
if ( V_15 > 0
&& V_15 < 32 ) {
if ( V_16 > 0
&& V_16 < 32 ) {
if ( ( V_16 +
V_15 )
<= V_14 ) {
if ( V_17 ==
V_25
||
V_17
==
V_26 )
{
if ( ( V_17 == V_25 && ( V_19 > 228 && V_19 <= 5000000UL ) ) || ( V_17 == V_26 && ( V_19 > 251 && V_19 <= 5000000UL ) ) ) {
if ( V_18 == V_27 || V_18 == V_28 ) {
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_14
=
V_14 ;
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_15
=
V_15 ;
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_16
=
V_16 ;
if ( V_18 == V_27 ) {
F_3 ( V_14 + 1 , V_9 -> V_22 . V_31 + 4 + ( 64 * V_13 ) ) ;
} else {
F_3 ( V_14 , V_9 -> V_22 . V_31 + 4 + ( 64 * V_13 ) ) ;
}
V_12
=
( unsigned int )
(
( ( unsigned int ) ( V_17 ) * 500000UL ) / V_19 ) ;
F_3 ( V_12 , V_9 -> V_22 . V_31 + ( 64 * V_13 ) ) ;
F_3 ( 7 * V_18 , V_9 -> V_22 . V_31 + 12 + ( 64 * V_13 ) ) ;
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_32
=
1 ;
} else {
F_4 ( L_1 ) ;
V_11
=
- 9 ;
}
} else {
F_4 ( L_2 ) ;
V_11
=
- 8 ;
}
} else {
F_4 ( L_3 ) ;
V_11 =
- 7 ;
}
} else {
F_4 ( L_4 ) ;
V_11 = - 4 ;
}
} else {
F_4 ( L_5 ) ;
V_11 = - 6 ;
}
} else {
F_4 ( L_6 ) ;
V_11 = - 5 ;
}
} else {
F_4 ( L_4 ) ;
V_11 = - 4 ;
}
} else {
F_4 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_4 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned char V_33 ;
unsigned char V_34 ;
unsigned char V_35 ;
unsigned char V_36 ;
unsigned int V_37 ;
unsigned int V_38 ;
unsigned int V_39 ;
unsigned int V_40 ;
unsigned int V_41 ;
unsigned char V_13 ;
unsigned char V_42 ;
unsigned char V_43 ;
unsigned int * V_44 ;
unsigned int * V_45 ;
unsigned int * V_46 ;
unsigned int * V_47 ;
V_11 = V_6 -> V_21 ;
V_46 = ( unsigned int * ) & V_7 [ 0 ] ;
V_47 = ( unsigned int * ) & V_7 [ 1 ] ;
V_44 = ( unsigned int * ) & V_7 [ 0 ] ;
V_45 = ( unsigned int * ) & V_7 [ 3 ] ;
V_13 = ( unsigned char ) F_2 ( V_6 -> V_20 ) ;
V_42 = ( unsigned char ) F_6 ( V_6 -> V_20 ) ;
V_43 = ( unsigned char ) F_7 ( V_6 -> V_20 ) ;
if ( V_13 < 4 ) {
if ( ( V_9 -> V_22 .
V_23 [ V_13 ] &
0xFFFF0000UL ) == V_24 ) {
if ( V_9 -> V_29 [ V_13 ] .
V_30 . V_32 == 1 ) {
switch ( V_43 ) {
case V_48 :
if ( V_42 < 3 ) {
F_3 ( 0 , V_9 -> V_22 .
V_31 + 8 +
( 64 * V_13 ) ) ;
do {
V_40 =
F_8 ( V_9 ->
V_22 .
V_31 +
( 64 * V_13 ) ) ;
} while ( ( V_40 & 0x1 )
!= 0 );
V_41 =
F_8 ( V_9 ->
V_22 .
V_31 + 4 +
( V_42 * 4 ) +
( 64 * V_13 ) ) ;
V_34 =
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_14 / 2 ;
if ( ( V_34 * 2 ) !=
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_14 ) {
V_34 ++ ;
}
V_35 =
V_34 -
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_15 ;
* V_46 =
V_41 >>
V_35 ;
V_37 = 1 ;
for ( V_33 = 0 ;
V_33 <
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_15 ;
V_33 ++ ) {
V_37 = V_37 * 2 ;
}
* V_46 =
* V_46 &
( ( V_37 ) - 1 ) ;
* V_47 =
V_41 >>
V_34 ;
V_37 = 1 ;
for ( V_33 = 0 ;
V_33 <
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_16 ;
V_33 ++ ) {
V_37 = V_37 * 2 ;
}
* V_47 =
* V_47 &
( ( V_37 ) - 1 ) ;
} else {
F_4 ( L_9 ) ;
V_11 = - 5 ;
}
break;
case V_49 :
V_38 = 1 ;
for ( V_33 = 0 ;
V_33 <
V_9 ->
V_29 [ V_13 ] .
V_30 .
V_15 ; V_33 ++ ) {
V_38 = V_38 * 2 ;
}
V_39 = 1 ;
for ( V_33 = 0 ;
V_33 <
V_9 ->
V_29 [ V_13 ] .
V_30 .
V_16 ; V_33 ++ ) {
V_39 = V_39 * 2 ;
}
F_3 ( 0 , V_9 -> V_22 .
V_31 + 8 +
( 64 * V_13 ) ) ;
do {
V_40 =
F_8 ( V_9 ->
V_22 .
V_31 +
( 64 * V_13 ) ) ;
} while ( ( V_40 & 0x1 ) != 0 );
for ( V_36 = 0 ; V_36 < 3 ;
V_36 ++ ) {
V_41 =
F_8 ( V_9 ->
V_22 .
V_31 + 4 +
( V_36 * 4 ) +
( 64 * V_13 ) ) ;
V_34 =
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_14 / 2 ;
if ( ( V_34 * 2 ) !=
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_14 ) {
V_34 ++ ;
}
V_35 =
V_34 -
V_9 ->
V_29
[ V_13 ] .
V_30 .
V_15 ;
V_44 [ V_36 ] =
V_41 >>
V_35 ;
V_44 [ V_36 ] =
V_44 [ V_36 ] &
( ( V_38 ) - 1 ) ;
V_45 [ V_36 ] =
V_41 >>
V_34 ;
V_45 [ V_36 ] =
V_45 [ V_36 ] &
( ( V_39 ) - 1 ) ;
}
break;
default:
F_9 ( L_10 ) ;
}
} else {
F_4 ( L_11 ) ;
V_11 = - 4 ;
}
} else {
F_4 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_4 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_40 ;
unsigned char V_13 ;
unsigned char V_50 ;
unsigned char * V_51 ;
unsigned char * V_52 ;
unsigned char V_53 ;
V_11 = V_6 -> V_21 ;
V_13 = ( unsigned char ) F_2 ( V_6 -> V_20 ) ;
V_53 = ( unsigned char ) V_7 [ 0 ] ;
if ( V_13 < 4 ) {
if ( ( V_9 -> V_22 .
V_23 [ V_13 ] &
0xFFFF0000UL ) == V_24 ) {
switch ( V_53 ) {
case V_54 :
F_3 ( 1 , V_9 -> V_22 . V_31 + 16 +
( 64 * V_13 ) ) ;
break;
case V_55 :
F_3 ( 0 , V_9 -> V_22 . V_31 + 16 +
( 64 * V_13 ) ) ;
break;
case V_56 :
V_50 = ( unsigned char ) F_6 ( V_6 -> V_20 ) ;
V_51 = ( unsigned char * ) & V_7 [ 0 ] ;
if ( V_50 <= 2 ) {
V_40 =
F_8 ( V_9 -> V_22 .
V_31 + ( 64 * V_13 ) ) ;
* V_51 =
( unsigned char ) ( ( ( ~ V_40 ) >> ( 4 +
V_50 ) )
& 1 ) ;
} else {
F_4 ( L_12 ) ;
V_11 = - 4 ;
}
break;
case V_57 :
V_52 = ( unsigned char * ) & V_7 [ 0 ] ;
V_40 =
F_8 ( V_9 -> V_22 . V_31 +
( 64 * V_13 ) ) ;
* V_52 =
( unsigned char ) ( ( ( ~ V_40 ) >> 4 ) & 7 ) ;
break;
default:
F_9 ( L_13 ) ;
}
} else {
F_4 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_4 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
