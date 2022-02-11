static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned char V_11 , V_12 , V_13 ;
unsigned char V_14 , V_15 ;
int V_16 = 0 ;
unsigned int V_17 = 0 ;
V_11 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_15 = ( unsigned char ) V_7 [ 0 ] ;
V_12 = ( unsigned char ) V_7 [ 1 ] ;
V_13 = ( unsigned char ) V_7 [ 2 ] ;
V_14 = ( unsigned char ) V_7 [ 1 ] ;
V_16 = V_6 -> V_19 ;
if ( V_11 >= 4 ) {
F_3 ( L_1 ) ;
V_16 = - 2 ;
return V_16 ;
}
switch ( V_15 ) {
case V_20 :
if ( V_14 )
{
V_9 -> V_21 [ V_11 ] .
V_22 . V_23 = 1 ;
V_9 -> V_21 [ V_11 ] .
V_22 . V_24 = 0 ;
} else
{
V_9 -> V_21 [ V_11 ] .
V_22 . V_23 = 0 ;
}
break;
case V_25 :
if ( ( V_9 -> V_26 .
V_27 [ V_11 ] &
0xFFFF0000UL ) == V_28 ) {
if ( ( V_12 == 0 ) || ( V_12 == 1 ) ) {
if ( ( V_13 == 0 )
|| ( V_13 == 1 ) ) {
V_9 -> V_21 [ V_11 ] .
V_22 . V_29 =
1 ;
V_9 -> V_21 [ V_11 ] .
V_22 .
V_12 = V_12 ;
V_9 -> V_21 [ V_11 ] .
V_22 .
V_13 = V_13 ;
V_17 =
( unsigned int ) ( V_12 |
( V_13 * 2 ) ) ;
F_4 ( V_17 ,
V_9 -> V_26 .
V_30 + 4 +
( 64 * V_11 ) ) ;
} else {
F_3 ( L_2 ) ;
V_16 = - 5 ;
}
} else {
F_3 ( L_3 ) ;
V_16 = - 4 ;
}
} else {
F_3 ( L_4 ) ;
V_16 = - 3 ;
}
}
F_5 ( L_5 , V_16 ) ;
return V_16 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_16 = 0 ;
unsigned int V_31 ;
unsigned char V_11 , V_32 ;
unsigned char * V_33 ;
V_11 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_32 = ( unsigned char ) F_7 ( V_6 -> V_18 ) ;
V_7 [ 0 ] = 0 ;
V_33 = ( unsigned char * ) & V_7 [ 0 ] ;
V_16 = V_6 -> V_19 ;
if ( V_11 < 4 ) {
if ( ( V_9 -> V_26 .
V_27 [ V_11 ] &
0xFFFF0000UL ) == V_28 ) {
if ( V_32 <= 6 ) {
if ( V_9 -> V_21 [ V_11 ] .
V_22 . V_29 == 1 ) {
if ( V_32 > 4 ) {
if ( V_32 == 5 ) {
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_12
!= 0 ) {
V_16 =
- 6 ;
}
}
else {
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_13
!= 0 ) {
V_16 =
- 7 ;
}
}
}
if ( V_16 >= 0 ) {
V_31 =
F_8 ( V_9 ->
V_26 .
V_30 +
( 64 * V_11 ) ) ;
* V_33 =
( unsigned char ) ( ( V_31 ^
0x1C ) >>
V_32 ) & 1 ;
}
} else {
F_3 ( L_6 ) ;
V_16 = - 5 ;
}
} else {
F_3 ( L_7 ) ;
V_16 = - 4 ;
}
} else {
F_3 ( L_4 ) ;
V_16 = - 3 ;
}
} else {
F_3 ( L_8 ) ;
V_16 = - 2 ;
}
return V_16 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_16 = 0 ;
unsigned int V_34 = 0 ;
unsigned char V_11 , V_35 ;
V_16 = V_6 -> V_19 ;
V_11 = F_2 ( V_6 -> V_18 ) ;
V_35 = F_7 ( V_6 -> V_18 ) ;
if ( V_11 < 4 ) {
if ( ( V_9 -> V_26 .
V_27 [ V_11 ] &
0xFFFF0000UL ) == V_28 ) {
if ( V_9 -> V_21 [ V_11 ] .
V_22 . V_29 == 1 ) {
switch ( V_35 ) {
case 0 :
break;
case 1 :
if ( V_9 -> V_21 [ V_11 ] .
V_22 .
V_12 != 1 ) {
V_16 = - 6 ;
}
break;
case 2 :
if ( V_9 -> V_21 [ V_11 ] .
V_22 .
V_13 != 1 ) {
V_16 = - 7 ;
}
break;
default:
V_16 = - 4 ;
break;
}
if ( V_16 >= 0 ) {
if ( V_7 [ 0 ] ) {
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_23 ==
1 ) {
V_34 =
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
| ( 1 <<
V_35 ) ;
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
= V_34 ;
} else {
V_34 =
1 <<
V_35 ;
}
}
else {
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_23 ==
1 ) {
V_34 =
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
& ( 0xFFFFFFFFUL
-
( 1 << V_35 ) ) ;
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
= V_34 ;
} else {
V_16 = - 8 ;
}
}
* /
F_4 ( V_34 ,
V_9 -> V_26 .
V_30 + ( 64 * V_11 ) ) ;
}
} else {
V_16 = - 5 ;
}
} else {
V_16 = - 3 ;
}
} else {
V_16 = - 2 ;
}
return V_16 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_16 = 0 ;
unsigned int V_34 = 0 ;
unsigned int V_31 ;
unsigned char V_11 , V_36 ;
unsigned char V_37 , V_38 ;
unsigned char * V_39 ;
V_11 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_37 = ( unsigned char ) V_7 [ 0 ] ;
V_38 = ( unsigned char ) V_7 [ 1 ] ;
V_36 = ( unsigned char ) V_7 [ 2 ] ;
V_16 = V_6 -> V_19 ;
V_39 = ( unsigned char * ) & V_7 [ 0 ] ;
switch ( V_37 ) {
case V_40 :
if ( V_11 < 4 ) {
if ( ( V_9 -> V_26 .
V_27 [ V_11 ] &
0xFFFF0000UL ) == V_28 ) {
if ( V_9 -> V_21 [ V_11 ] .
V_22 . V_29 == 1 ) {
V_31 =
F_8 ( V_9 -> V_26 .
V_30 + ( 64 * V_11 ) ) ;
* V_39 =
( unsigned char ) ( V_31 ^ 0x1C ) ;
} else {
V_16 = - 4 ;
}
} else {
V_16 = - 3 ;
}
} else {
V_16 = - 2 ;
}
break;
case V_41 :
if ( V_11 < 4 ) {
if ( ( V_9 -> V_26 .
V_27 [ V_11 ] &
0xFFFF0000UL ) == V_28 ) {
if ( V_9 -> V_21 [ V_11 ] .
V_22 . V_29 == 1 ) {
if ( V_36 <= 7 ) {
if ( ( V_36 & 2 ) == 2 ) {
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_12
!= 1 ) {
V_16 =
- 6 ;
}
}
if ( ( V_36 & 4 ) == 4 ) {
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_13
!= 1 ) {
V_16 =
- 7 ;
}
}
if ( V_16 >= 0 ) {
switch ( V_38 ) {
case V_42 :
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_23
== 1 ) {
V_34
=
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
|
V_36 ;
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
=
V_34 ;
} else {
V_34
=
V_36 ;
}
break;
case V_43 :
if ( V_9 ->
V_21
[ V_11 ] .
V_22 .
V_23
== 1 ) {
V_34
=
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
&
( 0xFFFFFFFFUL
-
V_36 ) ;
V_9 ->
V_21
[ V_11 ] .
V_22 .
V_24
=
V_34 ;
} else {
V_16
=
- 8 ;
}
}
F_4 ( V_34 ,
V_9 ->
V_26 .
V_30 +
( 64 * V_11 ) ) ;
}
} else {
V_16 = - 4 ;
}
} else {
V_16 = - 5 ;
}
} else {
V_16 = - 3 ;
}
} else {
V_16 = - 2 ;
}
break;
default:
V_16 = - 9 ;
F_3 ( L_9 ) ;
}
return V_16 ;
}
