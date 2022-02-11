int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_9 ;
unsigned char V_10 , V_11 , V_12 , V_13 ,
V_14 , V_15 ;
unsigned int V_16 ;
V_10 = F_2 ( V_6 -> V_17 ) ;
V_11 = ( unsigned char ) V_7 [ 0 ] ;
V_12 = ( unsigned char ) V_7 [ 1 ] ;
V_13 = ( unsigned char ) V_7 [ 2 ] ;
V_14 = ( unsigned char ) V_7 [ 3 ] ;
V_16 = ( unsigned int ) V_7 [ 4 ] ;
V_15 = ( unsigned char ) V_7 [ 5 ] ;
V_8 = V_6 -> V_18 ;
if ( V_10 < 4 ) {
if ( ( V_19 -> V_20 .
V_21 [ V_10 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_11 >= 2 && V_11 < 33 ) {
if ( V_12 > 0
&& V_12 < 32 ) {
if ( V_13 > 0
&& V_13 < 32 ) {
if ( ( V_13 +
V_12 )
<= V_11 ) {
if ( V_14 ==
V_23
||
V_14
==
V_24 )
{
if ( ( V_14 == V_23 && ( V_16 > 228 && V_16 <= 5000000UL ) ) || ( V_14 == V_24 && ( V_16 > 251 && V_16 <= 5000000UL ) ) ) {
if ( V_15 == V_25 || V_15 == V_26 ) {
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_11
=
V_11 ;
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_12
=
V_12 ;
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_13
=
V_13 ;
if ( V_15 == V_25 ) {
F_3 ( V_11 + 1 , V_19 -> V_20 . V_29 + 4 + ( 64 * V_10 ) ) ;
} else {
F_3 ( V_11 , V_19 -> V_20 . V_29 + 4 + ( 64 * V_10 ) ) ;
}
V_9
=
( unsigned int )
(
( ( unsigned int ) ( V_14 ) * 500000UL ) / V_16 ) ;
F_3 ( V_9 , V_19 -> V_20 . V_29 + ( 64 * V_10 ) ) ;
F_3 ( 7 * V_15 , V_19 -> V_20 . V_29 + 12 + ( 64 * V_10 ) ) ;
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_30
=
1 ;
} else {
F_4 ( L_1 ) ;
V_8
=
- 9 ;
}
} else {
F_4 ( L_2 ) ;
V_8
=
- 8 ;
}
} else {
F_4 ( L_3 ) ;
V_8 =
- 7 ;
}
} else {
F_4 ( L_4 ) ;
V_8 = - 4 ;
}
} else {
F_4 ( L_5 ) ;
V_8 = - 6 ;
}
} else {
F_4 ( L_6 ) ;
V_8 = - 5 ;
}
} else {
F_4 ( L_4 ) ;
V_8 = - 4 ;
}
} else {
F_4 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_4 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned char V_31 ;
unsigned char V_32 ;
unsigned char V_33 ;
unsigned char V_34 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
unsigned int V_38 ;
unsigned int V_39 ;
unsigned char V_10 ;
unsigned char V_40 ;
unsigned char V_41 ;
unsigned int * V_42 ;
unsigned int * V_43 ;
unsigned int * V_44 ;
unsigned int * V_45 ;
V_8 = V_6 -> V_18 ;
V_44 = ( unsigned int * ) & V_7 [ 0 ] ;
V_45 = ( unsigned int * ) & V_7 [ 1 ] ;
V_42 = ( unsigned int * ) & V_7 [ 0 ] ;
V_43 = ( unsigned int * ) & V_7 [ 3 ] ;
V_10 = ( unsigned char ) F_2 ( V_6 -> V_17 ) ;
V_40 = ( unsigned char ) F_6 ( V_6 -> V_17 ) ;
V_41 = ( unsigned char ) F_7 ( V_6 -> V_17 ) ;
if ( V_10 < 4 ) {
if ( ( V_19 -> V_20 .
V_21 [ V_10 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_19 -> V_27 [ V_10 ] .
V_28 . V_30 == 1 ) {
switch ( V_41 ) {
case V_46 :
if ( V_40 < 3 ) {
F_3 ( 0 , V_19 -> V_20 .
V_29 + 8 +
( 64 * V_10 ) ) ;
do {
V_38 =
F_8 ( V_19 ->
V_20 .
V_29 +
( 64 * V_10 ) ) ;
} while ( ( V_38 & 0x1 )
!= 0 );
V_39 =
F_8 ( V_19 ->
V_20 .
V_29 + 4 +
( V_40 * 4 ) +
( 64 * V_10 ) ) ;
V_32 =
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_11 / 2 ;
if ( ( V_32 * 2 ) !=
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_11 ) {
V_32 ++ ;
}
V_33 =
V_32 -
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_12 ;
* V_44 =
V_39 >>
V_33 ;
V_35 = 1 ;
for ( V_31 = 0 ;
V_31 <
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_12 ;
V_31 ++ ) {
V_35 = V_35 * 2 ;
}
* V_44 =
* V_44 &
( ( V_35 ) - 1 ) ;
* V_45 =
V_39 >>
V_32 ;
V_35 = 1 ;
for ( V_31 = 0 ;
V_31 <
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_13 ;
V_31 ++ ) {
V_35 = V_35 * 2 ;
}
* V_45 =
* V_45 &
( ( V_35 ) - 1 ) ;
} else {
F_4 ( L_9 ) ;
V_8 = - 5 ;
}
break;
case V_47 :
V_36 = 1 ;
for ( V_31 = 0 ;
V_31 <
V_19 ->
V_27 [ V_10 ] .
V_28 .
V_12 ; V_31 ++ ) {
V_36 = V_36 * 2 ;
}
V_37 = 1 ;
for ( V_31 = 0 ;
V_31 <
V_19 ->
V_27 [ V_10 ] .
V_28 .
V_13 ; V_31 ++ ) {
V_37 = V_37 * 2 ;
}
F_3 ( 0 , V_19 -> V_20 .
V_29 + 8 +
( 64 * V_10 ) ) ;
do {
V_38 =
F_8 ( V_19 ->
V_20 .
V_29 +
( 64 * V_10 ) ) ;
} while ( ( V_38 & 0x1 ) != 0 );
for ( V_34 = 0 ; V_34 < 3 ;
V_34 ++ ) {
V_39 =
F_8 ( V_19 ->
V_20 .
V_29 + 4 +
( V_34 * 4 ) +
( 64 * V_10 ) ) ;
V_32 =
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_11 / 2 ;
if ( ( V_32 * 2 ) !=
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_11 ) {
V_32 ++ ;
}
V_33 =
V_32 -
V_19 ->
V_27
[ V_10 ] .
V_28 .
V_12 ;
V_42 [ V_34 ] =
V_39 >>
V_33 ;
V_42 [ V_34 ] =
V_42 [ V_34 ] &
( ( V_36 ) - 1 ) ;
V_43 [ V_34 ] =
V_39 >>
V_32 ;
V_43 [ V_34 ] =
V_43 [ V_34 ] &
( ( V_37 ) - 1 ) ;
}
break;
default:
F_9 ( L_10 ) ;
}
} else {
F_4 ( L_11 ) ;
V_8 = - 4 ;
}
} else {
F_4 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_4 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_38 ;
unsigned char V_10 ;
unsigned char V_48 ;
unsigned char * V_49 ;
unsigned char * V_50 ;
unsigned char V_51 ;
V_8 = V_6 -> V_18 ;
V_10 = ( unsigned char ) F_2 ( V_6 -> V_17 ) ;
V_51 = ( unsigned char ) V_7 [ 0 ] ;
if ( V_10 < 4 ) {
if ( ( V_19 -> V_20 .
V_21 [ V_10 ] &
0xFFFF0000UL ) == V_22 ) {
switch ( V_51 ) {
case V_52 :
F_3 ( 1 , V_19 -> V_20 . V_29 + 16 +
( 64 * V_10 ) ) ;
break;
case V_53 :
F_3 ( 0 , V_19 -> V_20 . V_29 + 16 +
( 64 * V_10 ) ) ;
break;
case V_54 :
V_48 = ( unsigned char ) F_6 ( V_6 -> V_17 ) ;
V_49 = ( unsigned char * ) & V_7 [ 0 ] ;
if ( V_48 <= 2 ) {
V_38 =
F_8 ( V_19 -> V_20 .
V_29 + ( 64 * V_10 ) ) ;
* V_49 =
( unsigned char ) ( ( ( ~ V_38 ) >> ( 4 +
V_48 ) )
& 1 ) ;
} else {
F_4 ( L_12 ) ;
V_8 = - 4 ;
}
break;
case V_55 :
V_50 = ( unsigned char * ) & V_7 [ 0 ] ;
V_38 =
F_8 ( V_19 -> V_20 . V_29 +
( 64 * V_10 ) ) ;
* V_50 =
( unsigned char ) ( ( ( ~ V_38 ) >> 4 ) & 7 ) ;
break;
default:
F_9 ( L_13 ) ;
}
} else {
F_4 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_4 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
