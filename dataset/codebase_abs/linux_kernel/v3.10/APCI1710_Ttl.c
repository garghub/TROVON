static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned char V_12 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned char V_15 ;
unsigned char V_16 ;
unsigned char V_17 ;
V_12 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_13 = ( unsigned char ) V_7 [ 0 ] ;
V_11 = V_6 -> V_19 ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_20 .
V_21 [ V_12 ] &
0xFFFF0000UL ) == V_22 ) {
switch ( V_13 ) {
case V_23 :
V_9 -> V_24 [ V_12 ] .
V_25 . V_26 = 1 ;
V_9 -> V_24 [ V_12 ] .
V_25 . V_27 [ 0 ] = 0 ;
V_9 -> V_24 [ V_12 ] .
V_25 . V_27 [ 1 ] = 0 ;
V_9 -> V_24 [ V_12 ] .
V_25 . V_27 [ 2 ] = 0 ;
V_9 -> V_24 [ V_12 ] .
V_25 . V_27 [ 3 ] = 1 ;
F_3 ( 0x8 ,
V_9 -> V_20 . V_28 + 20 +
( 64 * V_12 ) ) ;
break;
case V_29 :
V_14 = ( unsigned char ) V_7 [ 1 ] ;
V_15 = ( unsigned char ) V_7 [ 2 ] ;
V_16 = ( unsigned char ) V_7 [ 3 ] ;
V_17 = ( unsigned char ) V_7 [ 4 ] ;
if ( ( V_9 -> V_20 .
V_21
[ V_12 ] & 0xFFFF ) >=
0x3230 ) {
if ( ( V_14 == 0 )
|| ( V_14 == 1 ) ) {
if ( ( V_15 == 0 )
|| ( V_15 == 1 ) ) {
if ( ( V_16 == 0 )
|| ( V_16
== 1 ) ) {
if ( ( V_17 == 0 ) || ( V_17 == 1 ) ) {
V_9 ->
V_24
[ V_12 ] .
V_25 .
V_26
=
1 ;
V_9 ->
V_24
[ V_12 ] .
V_25 .
V_27
[ 0 ]
=
V_14 ;
V_9 ->
V_24
[ V_12 ] .
V_25 .
V_27
[ 1 ]
=
V_15 ;
V_9 ->
V_24
[ V_12 ] .
V_25 .
V_27
[ 2 ]
=
V_16 ;
V_9 ->
V_24
[ V_12 ] .
V_25 .
V_27
[ 3 ]
=
V_17 ;
F_3 ( ( V_14 << 0 ) | ( V_15 << 1 ) | ( V_16 << 2 ) | ( V_17 << 3 ) , V_9 -> V_20 . V_28 + 20 + ( 64 * V_12 ) ) ;
} else {
F_4 ( L_1 ) ;
V_11
=
- 8 ;
}
} else {
F_4 ( L_2 ) ;
V_11 =
- 7 ;
}
} else {
F_4 ( L_3 ) ;
V_11 = - 6 ;
}
} else {
F_4 ( L_4 ) ;
V_11 = - 5 ;
}
} else {
F_4 ( L_5 ) ;
V_11 = - 4 ;
}
break;
F_4 ( L_6 ) ;
default:
F_5 ( L_7 ) ;
}
} else {
F_4 ( L_8 ) ;
V_11 = - 3 ;
}
} else {
F_4 ( L_9 ) ;
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
unsigned int V_30 ;
unsigned char V_12 ;
unsigned char V_31 ;
unsigned char V_32 ;
unsigned char V_33 ;
unsigned char * V_34 ;
unsigned char * V_35 ;
V_11 = V_6 -> V_19 ;
V_33 = ( unsigned char ) V_7 [ 0 ] ;
V_12 = F_2 ( V_6 -> V_18 ) ;
V_31 = F_7 ( V_6 -> V_18 ) ;
V_32 = F_8 ( V_6 -> V_18 ) ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_20 .
V_21 [ V_12 ] &
0xFFFF0000UL ) == V_22 ) {
switch ( V_33 ) {
case V_36 :
V_34 = ( unsigned char * ) & V_7 [ 0 ] ;
if ( ( ( V_31 <= 2 )
&& ( ( V_9 -> V_20 .
V_21
[ V_12 ] &
0xFFFF ) ==
0x3130 ) )
|| ( ( V_31 <= 3 )
&& ( ( V_9 -> V_20 .
V_21
[ V_12 ] &
0xFFFF ) >=
0x3230 ) ) ) {
if ( ( ( V_32 <= 7 )
&& ( V_31 < 3 ) )
|| ( ( V_32 <= 1 )
&& ( V_31 ==
3 ) ) ) {
if ( V_9 ->
V_24
[ V_12 ] .
V_25 . V_26 ==
1 ) {
if ( ( ( V_9 -> V_20 . V_21 [ V_12 ] & 0xFFFF ) == 0x3130 ) || ( ( ( V_9 -> V_20 . V_21 [ V_12 ] & 0xFFFF ) >= 0x3230 ) && ( V_9 -> V_24 [ V_12 ] . V_25 . V_27 [ V_31 ] == 0 ) ) ) {
V_30 =
F_9
( V_9 ->
V_20 .
V_28
+
( 64 * V_12 ) ) ;
* V_34
=
( unsigned char ) (
( V_30
>>
( 8 * V_31 ) ) >> V_32 ) & 1 ;
} else {
F_4 ( L_10 ) ;
V_11 =
- 4 ;
}
} else {
F_4 ( L_11 ) ;
V_11 = - 6 ;
}
} else {
F_4 ( L_12 ) ;
V_11 = - 5 ;
}
} else {
F_4 ( L_10 ) ;
V_11 = - 4 ;
}
break;
case V_37 :
V_35 = ( unsigned char * ) & V_7 [ 0 ] ;
if ( ( ( V_31 <= 2 )
&& ( ( V_9 -> V_20 .
V_21
[ V_12 ] &
0xFFFF ) ==
0x3130 ) )
|| ( ( V_31 <= 3 )
&& ( ( V_9 -> V_20 .
V_21
[ V_12 ] &
0xFFFF ) >=
0x3230 ) ) ) {
if ( V_9 -> V_24 [ V_12 ] .
V_25 . V_26 == 1 ) {
if ( ( ( V_9 -> V_20 .
V_21
[ V_12 ]
&
0xFFFF )
== 0x3130 )
|| ( ( ( V_9 -> V_20 . V_21 [ V_12 ] & 0xFFFF ) >= 0x3230 ) && ( V_9 -> V_24 [ V_12 ] . V_25 . V_27 [ V_31 ] == 0 ) ) ) {
V_30 =
F_9 ( V_9 ->
V_20 .
V_28 +
( 64 * V_12 ) ) ;
* V_35 =
( unsigned char ) (
( V_30 >>
( 8 * V_31 ) ) & 0xFF ) ;
} else {
F_4 ( L_10 ) ;
V_11 = - 4 ;
}
} else {
F_4 ( L_11 ) ;
V_11 = - 5 ;
}
} else {
F_4 ( L_10 ) ;
V_11 = - 4 ;
}
break;
default:
F_5 ( L_13 ) ;
}
} else {
F_4 ( L_8 ) ;
V_11 = - 3 ;
}
} else {
F_4 ( L_9 ) ;
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
unsigned int V_30 ;
unsigned char V_12 ;
unsigned int * V_38 ;
V_12 = ( unsigned char ) F_2 ( V_6 -> V_18 ) ;
V_11 = V_6 -> V_19 ;
V_38 = ( unsigned int * ) & V_7 [ 0 ] ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_20 .
V_21 [ V_12 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_9 ->
V_24 [ V_12 ] .
V_25 . V_26 == 1 ) {
V_30 = F_9 ( V_9 -> V_20 .
V_28 + ( 64 * V_12 ) ) ;
if ( ( V_9 -> V_20 .
V_21
[ V_12 ] & 0xFFFF ) ==
0x3130 ) {
* V_38 =
V_30 & 0xFFFFFFUL ;
} else {
if ( V_9 -> V_24 [ V_12 ] .
V_25 .
V_27 [ 0 ] == 1 ) {
* V_38 =
V_30 &
0x3FFFF00UL ;
}
if ( V_9 ->
V_24 [ V_12 ] .
V_25 .
V_27 [ 1 ] == 1 ) {
* V_38 =
V_30 &
0x3FF00FFUL ;
}
if ( V_9 ->
V_24 [ V_12 ] .
V_25 .
V_27 [ 2 ] == 1 ) {
* V_38 =
V_30 &
0x300FFFFUL ;
}
if ( V_9 ->
V_24 [ V_12 ] .
V_25 .
V_27 [ 3 ] == 1 ) {
* V_38 =
V_30 &
0xFFFFFFUL ;
}
}
} else {
F_4 ( L_11 ) ;
V_11 = - 5 ;
}
} else {
F_4 ( L_8 ) ;
V_11 = - 3 ;
}
} else {
F_4 ( L_9 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
