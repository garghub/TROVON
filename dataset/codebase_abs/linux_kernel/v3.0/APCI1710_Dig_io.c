int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned char V_8 , V_9 , V_10 ;
unsigned char V_11 , V_12 ;
int V_13 = 0 ;
unsigned int V_14 = 0 ;
V_8 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_12 = ( unsigned char ) V_7 [ 0 ] ;
V_9 = ( unsigned char ) V_7 [ 1 ] ;
V_10 = ( unsigned char ) V_7 [ 2 ] ;
V_11 = ( unsigned char ) V_7 [ 1 ] ;
V_13 = V_6 -> V_16 ;
if ( V_8 >= 4 ) {
F_3 ( L_1 ) ;
V_13 = - 2 ;
return V_13 ;
}
switch ( V_12 ) {
case V_17 :
if ( V_11 )
{
V_18 -> V_19 [ V_8 ] .
V_20 . V_21 = 1 ;
V_18 -> V_19 [ V_8 ] .
V_20 . V_22 = 0 ;
} else
{
V_18 -> V_19 [ V_8 ] .
V_20 . V_21 = 0 ;
}
break;
case V_23 :
if ( ( V_18 -> V_24 .
V_25 [ V_8 ] &
0xFFFF0000UL ) == V_26 ) {
if ( ( V_9 == 0 ) || ( V_9 == 1 ) ) {
if ( ( V_10 == 0 )
|| ( V_10 == 1 ) ) {
V_18 -> V_19 [ V_8 ] .
V_20 . V_27 =
1 ;
V_18 -> V_19 [ V_8 ] .
V_20 .
V_9 = V_9 ;
V_18 -> V_19 [ V_8 ] .
V_20 .
V_10 = V_10 ;
V_14 =
( unsigned int ) ( V_9 |
( V_10 * 2 ) ) ;
F_4 ( V_14 ,
V_18 -> V_24 .
V_28 + 4 +
( 64 * V_8 ) ) ;
} else {
F_3 ( L_2 ) ;
V_13 = - 5 ;
}
} else {
F_3 ( L_3 ) ;
V_13 = - 4 ;
}
} else {
F_3 ( L_4 ) ;
V_13 = - 3 ;
}
}
F_5 ( L_5 , V_13 ) ;
return V_13 ;
}
int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_13 = 0 ;
unsigned int V_29 ;
unsigned char V_8 , V_30 ;
unsigned char * V_31 ;
V_8 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_30 = ( unsigned char ) F_7 ( V_6 -> V_15 ) ;
V_7 [ 0 ] = 0 ;
V_31 = ( unsigned char * ) & V_7 [ 0 ] ;
V_13 = V_6 -> V_16 ;
if ( V_8 < 4 ) {
if ( ( V_18 -> V_24 .
V_25 [ V_8 ] &
0xFFFF0000UL ) == V_26 ) {
if ( V_30 <= 6 ) {
if ( V_18 -> V_19 [ V_8 ] .
V_20 . V_27 == 1 ) {
if ( V_30 > 4 ) {
if ( V_30 == 5 ) {
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_9
!= 0 ) {
V_13 =
- 6 ;
}
}
else {
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_10
!= 0 ) {
V_13 =
- 7 ;
}
}
}
if ( V_13 >= 0 ) {
V_29 =
F_8 ( V_18 ->
V_24 .
V_28 +
( 64 * V_8 ) ) ;
* V_31 =
( unsigned char ) ( ( V_29 ^
0x1C ) >>
V_30 ) & 1 ;
}
} else {
F_3 ( L_6 ) ;
V_13 = - 5 ;
}
} else {
F_3 ( L_7 ) ;
V_13 = - 4 ;
}
} else {
F_3 ( L_4 ) ;
V_13 = - 3 ;
}
} else {
F_3 ( L_8 ) ;
V_13 = - 2 ;
}
return V_13 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_13 = 0 ;
unsigned int V_32 = 0 ;
unsigned char V_8 , V_33 ;
V_13 = V_6 -> V_16 ;
V_8 = F_2 ( V_6 -> V_15 ) ;
V_33 = F_7 ( V_6 -> V_15 ) ;
if ( V_8 < 4 ) {
if ( ( V_18 -> V_24 .
V_25 [ V_8 ] &
0xFFFF0000UL ) == V_26 ) {
if ( V_18 -> V_19 [ V_8 ] .
V_20 . V_27 == 1 ) {
switch ( V_33 ) {
case 0 :
break;
case 1 :
if ( V_18 -> V_19 [ V_8 ] .
V_20 .
V_9 != 1 ) {
V_13 = - 6 ;
}
break;
case 2 :
if ( V_18 -> V_19 [ V_8 ] .
V_20 .
V_10 != 1 ) {
V_13 = - 7 ;
}
break;
default:
V_13 = - 4 ;
break;
}
if ( V_13 >= 0 ) {
if ( V_7 [ 0 ] ) {
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_21 ==
1 ) {
V_32 =
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
| ( 1 <<
V_33 ) ;
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
= V_32 ;
} else {
V_32 =
1 <<
V_33 ;
}
}
else {
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_21 ==
1 ) {
V_32 =
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
& ( 0xFFFFFFFFUL
-
( 1 << V_33 ) ) ;
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
= V_32 ;
} else {
V_13 = - 8 ;
}
}
* /
F_4 ( V_32 ,
V_18 -> V_24 .
V_28 + ( 64 * V_8 ) ) ;
}
} else {
V_13 = - 5 ;
}
} else {
V_13 = - 3 ;
}
} else {
V_13 = - 2 ;
}
return V_13 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_13 = 0 ;
unsigned int V_32 = 0 ;
unsigned int V_29 ;
unsigned char V_8 , V_34 ;
unsigned char V_35 , V_36 ;
unsigned char * V_37 ;
V_8 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_35 = ( unsigned char ) V_7 [ 0 ] ;
V_36 = ( unsigned char ) V_7 [ 1 ] ;
V_34 = ( unsigned char ) V_7 [ 2 ] ;
V_13 = V_6 -> V_16 ;
V_37 = ( unsigned char * ) & V_7 [ 0 ] ;
switch ( V_35 ) {
case V_38 :
if ( V_8 < 4 ) {
if ( ( V_18 -> V_24 .
V_25 [ V_8 ] &
0xFFFF0000UL ) == V_26 ) {
if ( V_18 -> V_19 [ V_8 ] .
V_20 . V_27 == 1 ) {
V_29 =
F_8 ( V_18 -> V_24 .
V_28 + ( 64 * V_8 ) ) ;
* V_37 =
( unsigned char ) ( V_29 ^ 0x1C ) ;
} else {
V_13 = - 4 ;
}
} else {
V_13 = - 3 ;
}
} else {
V_13 = - 2 ;
}
break;
case V_39 :
if ( V_8 < 4 ) {
if ( ( V_18 -> V_24 .
V_25 [ V_8 ] &
0xFFFF0000UL ) == V_26 ) {
if ( V_18 -> V_19 [ V_8 ] .
V_20 . V_27 == 1 ) {
if ( V_34 <= 7 ) {
if ( ( V_34 & 2 ) == 2 ) {
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_9
!= 1 ) {
V_13 =
- 6 ;
}
}
if ( ( V_34 & 4 ) == 4 ) {
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_10
!= 1 ) {
V_13 =
- 7 ;
}
}
if ( V_13 >= 0 ) {
switch ( V_36 ) {
case V_40 :
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_21
== 1 ) {
V_32
=
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
|
V_34 ;
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
=
V_32 ;
} else {
V_32
=
V_34 ;
}
break;
case V_41 :
if ( V_18 ->
V_19
[ V_8 ] .
V_20 .
V_21
== 1 ) {
V_32
=
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
&
( 0xFFFFFFFFUL
-
V_34 ) ;
V_18 ->
V_19
[ V_8 ] .
V_20 .
V_22
=
V_32 ;
} else {
V_13
=
- 8 ;
}
}
F_4 ( V_32 ,
V_18 ->
V_24 .
V_28 +
( 64 * V_8 ) ) ;
}
} else {
V_13 = - 4 ;
}
} else {
V_13 = - 5 ;
}
} else {
V_13 = - 3 ;
}
} else {
V_13 = - 2 ;
}
break;
default:
V_13 = - 9 ;
F_3 ( L_9 ) ;
}
return V_13 ;
}
