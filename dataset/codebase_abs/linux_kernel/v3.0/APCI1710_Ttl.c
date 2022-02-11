int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned char V_9 ;
unsigned char V_10 ;
unsigned char V_11 ;
unsigned char V_12 ;
unsigned char V_13 ;
unsigned char V_14 ;
V_9 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_10 = ( unsigned char ) V_7 [ 0 ] ;
V_8 = V_6 -> V_16 ;
if ( V_9 < 4 ) {
if ( ( V_17 -> V_18 .
V_19 [ V_9 ] &
0xFFFF0000UL ) == V_20 ) {
switch ( V_10 ) {
case V_21 :
V_17 -> V_22 [ V_9 ] .
V_23 . V_24 = 1 ;
V_17 -> V_22 [ V_9 ] .
V_23 . V_25 [ 0 ] = 0 ;
V_17 -> V_22 [ V_9 ] .
V_23 . V_25 [ 1 ] = 0 ;
V_17 -> V_22 [ V_9 ] .
V_23 . V_25 [ 2 ] = 0 ;
V_17 -> V_22 [ V_9 ] .
V_23 . V_25 [ 3 ] = 1 ;
F_3 ( 0x8 ,
V_17 -> V_18 . V_26 + 20 +
( 64 * V_9 ) ) ;
break;
case V_27 :
V_11 = ( unsigned char ) V_7 [ 1 ] ;
V_12 = ( unsigned char ) V_7 [ 2 ] ;
V_13 = ( unsigned char ) V_7 [ 3 ] ;
V_14 = ( unsigned char ) V_7 [ 4 ] ;
if ( ( V_17 -> V_18 .
V_19
[ V_9 ] & 0xFFFF ) >=
0x3230 ) {
if ( ( V_11 == 0 )
|| ( V_11 == 1 ) ) {
if ( ( V_12 == 0 )
|| ( V_12 == 1 ) ) {
if ( ( V_13 == 0 )
|| ( V_13
== 1 ) ) {
if ( ( V_14 == 0 ) || ( V_14 == 1 ) ) {
V_17 ->
V_22
[ V_9 ] .
V_23 .
V_24
=
1 ;
V_17 ->
V_22
[ V_9 ] .
V_23 .
V_25
[ 0 ]
=
V_11 ;
V_17 ->
V_22
[ V_9 ] .
V_23 .
V_25
[ 1 ]
=
V_12 ;
V_17 ->
V_22
[ V_9 ] .
V_23 .
V_25
[ 2 ]
=
V_13 ;
V_17 ->
V_22
[ V_9 ] .
V_23 .
V_25
[ 3 ]
=
V_14 ;
F_3 ( ( V_11 << 0 ) | ( V_12 << 1 ) | ( V_13 << 2 ) | ( V_14 << 3 ) , V_17 -> V_18 . V_26 + 20 + ( 64 * V_9 ) ) ;
} else {
F_4 ( L_1 ) ;
V_8
=
- 8 ;
}
} else {
F_4 ( L_2 ) ;
V_8 =
- 7 ;
}
} else {
F_4 ( L_3 ) ;
V_8 = - 6 ;
}
} else {
F_4 ( L_4 ) ;
V_8 = - 5 ;
}
} else {
F_4 ( L_5 ) ;
V_8 = - 4 ;
}
break;
F_4 ( L_6 ) ;
default:
F_5 ( L_7 ) ;
}
} else {
F_4 ( L_8 ) ;
V_8 = - 3 ;
}
} else {
F_4 ( L_9 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_28 ;
unsigned char V_9 ;
unsigned char V_29 ;
unsigned char V_30 ;
unsigned char V_31 ;
unsigned char * V_32 ;
unsigned char * V_33 ;
V_8 = V_6 -> V_16 ;
V_31 = ( unsigned char ) V_7 [ 0 ] ;
V_9 = F_2 ( V_6 -> V_15 ) ;
V_29 = F_7 ( V_6 -> V_15 ) ;
V_30 = F_8 ( V_6 -> V_15 ) ;
if ( V_9 < 4 ) {
if ( ( V_17 -> V_18 .
V_19 [ V_9 ] &
0xFFFF0000UL ) == V_20 ) {
switch ( V_31 ) {
case V_34 :
V_32 = ( unsigned char * ) & V_7 [ 0 ] ;
if ( ( ( V_29 <= 2 )
&& ( ( V_17 -> V_18 .
V_19
[ V_9 ] &
0xFFFF ) ==
0x3130 ) )
|| ( ( V_29 <= 3 )
&& ( ( V_17 -> V_18 .
V_19
[ V_9 ] &
0xFFFF ) >=
0x3230 ) ) ) {
if ( ( ( V_30 <= 7 )
&& ( V_29 < 3 ) )
|| ( ( V_30 <= 1 )
&& ( V_29 ==
3 ) ) ) {
if ( V_17 ->
V_22
[ V_9 ] .
V_23 . V_24 ==
1 ) {
if ( ( ( V_17 -> V_18 . V_19 [ V_9 ] & 0xFFFF ) == 0x3130 ) || ( ( ( V_17 -> V_18 . V_19 [ V_9 ] & 0xFFFF ) >= 0x3230 ) && ( V_17 -> V_22 [ V_9 ] . V_23 . V_25 [ V_29 ] == 0 ) ) ) {
V_28 =
F_9
( V_17 ->
V_18 .
V_26
+
( 64 * V_9 ) ) ;
* V_32
=
( unsigned char ) (
( V_28
>>
( 8 * V_29 ) ) >> V_30 ) & 1 ;
} else {
F_4 ( L_10 ) ;
V_8 =
- 4 ;
}
} else {
F_4 ( L_11 ) ;
V_8 = - 6 ;
}
} else {
F_4 ( L_12 ) ;
V_8 = - 5 ;
}
} else {
F_4 ( L_10 ) ;
V_8 = - 4 ;
}
break;
case V_35 :
V_33 = ( unsigned char * ) & V_7 [ 0 ] ;
if ( ( ( V_29 <= 2 )
&& ( ( V_17 -> V_18 .
V_19
[ V_9 ] &
0xFFFF ) ==
0x3130 ) )
|| ( ( V_29 <= 3 )
&& ( ( V_17 -> V_18 .
V_19
[ V_9 ] &
0xFFFF ) >=
0x3230 ) ) ) {
if ( V_17 -> V_22 [ V_9 ] .
V_23 . V_24 == 1 ) {
if ( ( ( V_17 -> V_18 .
V_19
[ V_9 ]
&
0xFFFF )
== 0x3130 )
|| ( ( ( V_17 -> V_18 . V_19 [ V_9 ] & 0xFFFF ) >= 0x3230 ) && ( V_17 -> V_22 [ V_9 ] . V_23 . V_25 [ V_29 ] == 0 ) ) ) {
V_28 =
F_9 ( V_17 ->
V_18 .
V_26 +
( 64 * V_9 ) ) ;
* V_33 =
( unsigned char ) (
( V_28 >>
( 8 * V_29 ) ) & 0xFF ) ;
} else {
F_4 ( L_10 ) ;
V_8 = - 4 ;
}
} else {
F_4 ( L_11 ) ;
V_8 = - 5 ;
}
} else {
F_4 ( L_10 ) ;
V_8 = - 4 ;
}
break;
default:
F_5 ( L_13 ) ;
}
} else {
F_4 ( L_8 ) ;
V_8 = - 3 ;
}
} else {
F_4 ( L_9 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_28 ;
unsigned char V_9 ;
unsigned int * V_36 ;
V_9 = ( unsigned char ) F_2 ( V_6 -> V_15 ) ;
V_8 = V_6 -> V_16 ;
V_36 = ( unsigned int * ) & V_7 [ 0 ] ;
if ( V_9 < 4 ) {
if ( ( V_17 -> V_18 .
V_19 [ V_9 ] &
0xFFFF0000UL ) == V_20 ) {
if ( V_17 ->
V_22 [ V_9 ] .
V_23 . V_24 == 1 ) {
V_28 = F_9 ( V_17 -> V_18 .
V_26 + ( 64 * V_9 ) ) ;
if ( ( V_17 -> V_18 .
V_19
[ V_9 ] & 0xFFFF ) ==
0x3130 ) {
* V_36 =
V_28 & 0xFFFFFFUL ;
} else {
if ( V_17 -> V_22 [ V_9 ] .
V_23 .
V_25 [ 0 ] == 1 ) {
* V_36 =
V_28 &
0x3FFFF00UL ;
}
if ( V_17 ->
V_22 [ V_9 ] .
V_23 .
V_25 [ 1 ] == 1 ) {
* V_36 =
V_28 &
0x3FF00FFUL ;
}
if ( V_17 ->
V_22 [ V_9 ] .
V_23 .
V_25 [ 2 ] == 1 ) {
* V_36 =
V_28 &
0x300FFFFUL ;
}
if ( V_17 ->
V_22 [ V_9 ] .
V_23 .
V_25 [ 3 ] == 1 ) {
* V_36 =
V_28 &
0xFFFFFFUL ;
}
}
} else {
F_4 ( L_11 ) ;
V_8 = - 5 ;
}
} else {
F_4 ( L_8 ) ;
V_8 = - 3 ;
}
} else {
F_4 ( L_9 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
