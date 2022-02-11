static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_12 = 0 ;
unsigned int V_13 ;
double V_14 = 0 ;
unsigned char V_15 ;
unsigned char V_16 ;
unsigned char V_17 ;
unsigned char V_18 ;
unsigned int V_19 ;
unsigned int V_20 = 0 ;
V_11 = V_6 -> V_21 ;
V_15 = ( unsigned char ) F_2 ( V_6 -> V_22 ) ;
V_16 = ( unsigned char ) V_7 [ 0 ] ;
V_17 = ( unsigned char ) V_7 [ 1 ] ;
V_18 = ( unsigned char ) V_7 [ 2 ] ;
V_19 = ( unsigned int ) V_7 [ 3 ] ;
F_3 ( L_1 , V_17 ) ;
if ( V_15 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_15 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_16 <= 1 ) {
if ( ( V_17 == V_26 ) ||
( V_17 == V_27 ) ||
( V_17 == V_28 ) ||
( V_17 ==
V_29 ) ) {
if ( ( V_18 <= 4 )
|| ( V_17 ==
V_29 ) ) {
if ( ( ( V_17 == V_26 ) && ( V_18 == 0 ) && ( V_19 >= 133 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_17 == V_26 ) && ( V_18 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 571230650UL ) ) || ( ( V_17 == V_26 ) && ( V_18 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 571230UL ) ) || ( ( V_17 == V_26 ) && ( V_18 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 571UL ) ) || ( ( V_17 == V_26 ) && ( V_18 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 9UL ) ) || ( ( V_17 == V_27 ) && ( V_18 == 0 ) && ( V_19 >= 121 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_17 == V_27 ) && ( V_18 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 519691043UL ) ) || ( ( V_17 == V_27 ) && ( V_18 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 519691UL ) ) || ( ( V_17 == V_27 ) && ( V_18 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 520UL ) ) || ( ( V_17 == V_27 ) && ( V_18 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 8UL ) ) || ( ( V_17 == V_28 ) && ( V_18 == 0 ) && ( V_19 >= 100 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_17 == V_28 ) && ( V_18 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 429496729UL ) ) || ( ( V_17 == V_28 ) && ( V_18 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 429496UL ) ) || ( ( V_17 == V_28 ) && ( V_18 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 429UL ) ) || ( ( V_17 == V_28 ) && ( V_18 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 7UL ) ) || ( ( V_17 == V_29 ) && ( V_19 >= 2 ) ) ) {
if ( ( ( V_17 == V_28 ) && ( V_9 -> V_23 . V_30 > 0 ) ) || ( V_17 != V_28 ) ) {
if ( ( ( V_17 == V_28 ) && ( ( V_9 -> V_23 . V_24 [ V_15 ] & 0xFFFF ) >= 0x3131 ) ) || ( ( V_17 == V_29 ) && ( ( V_9 -> V_23 . V_24 [ V_15 ] & 0xFFFF ) >= 0x3132 ) ) || ( V_17 == V_26 ) || ( V_17 == V_27 ) ) {
if ( V_17 != V_29 ) {
F_4
() ;
switch ( V_18 ) {
case 0 :
V_12
=
( unsigned int )
( V_19
*
( 0.00025 * V_17 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 0.00025 * ( double ) V_17 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_20
=
( unsigned int )
( V_12
/
( 0.00025 * ( double ) V_17 ) ) ;
V_14
=
( double )
V_12
/
( 0.00025
*
( double )
V_17 ) ;
if ( ( double ) ( ( double ) V_12 / ( 0.00025 * ( double ) V_17 ) ) >= ( double ) ( ( double ) V_20 + 0.5 ) ) {
V_20
=
V_20
+
1 ;
}
V_19
=
V_19
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_17 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
1.007752288 ) ;
}
break;
case 1 :
V_12
=
( unsigned int )
( V_19
*
( 0.25 * V_17 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 0.25 * ( double ) V_17 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_20
=
( unsigned int )
( V_12
/
( 0.25 * ( double ) V_17 ) ) ;
V_14
=
( double )
V_12
/
(
( double )
0.25
*
( double )
V_17 ) ;
if ( ( double ) ( ( double ) V_12 / ( 0.25 * ( double ) V_17 ) ) >= ( double ) ( ( double ) V_20 + 0.5 ) ) {
V_20
=
V_20
+
1 ;
}
V_19
=
V_19
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_17 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
1.007752288 ) ;
}
break;
case 2 :
V_12
=
V_19
*
( 250.0
*
V_17 ) ;
if ( ( double ) ( ( double ) V_19 * ( 250.0 * ( double ) V_17 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_20
=
( unsigned int )
( V_12
/
( 250.0 * ( double ) V_17 ) ) ;
V_14
=
( double )
V_12
/
( 250.0
*
( double )
V_17 ) ;
if ( ( double ) ( ( double ) V_12 / ( 250.0 * ( double ) V_17 ) ) >= ( double ) ( ( double ) V_20 + 0.5 ) ) {
V_20
=
V_20
+
1 ;
}
V_19
=
V_19
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_17 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
1.007752288 ) ;
}
break;
case 3 :
V_12
=
( unsigned int )
( V_19
*
( 250000.0
*
V_17 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 250000.0 * ( double ) V_17 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_20
=
( unsigned int )
( V_12
/
( 250000.0
*
( double )
V_17 ) ) ;
V_14
=
( double )
V_12
/
( 250000.0
*
( double )
V_17 ) ;
if ( ( double ) ( ( double ) V_12 / ( 250000.0 * ( double ) V_17 ) ) >= ( double ) ( ( double ) V_20 + 0.5 ) ) {
V_20
=
V_20
+
1 ;
}
V_19
=
V_19
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_17 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
1.007752288 ) ;
}
break;
case 4 :
V_12
=
( unsigned int )
(
( V_19
*
60 )
*
( 250000.0
*
V_17 ) ) ;
if ( ( double ) ( ( double ) ( V_19 * 60.0 ) * ( 250000.0 * ( double ) V_17 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_20
=
( unsigned int )
( V_12
/
( 250000.0
*
( double )
V_17 ) )
/
60 ;
V_14
=
(
( double )
V_12
/
( 250000.0
*
( double )
V_17 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_12 / ( 250000.0 * ( double ) V_17 ) ) / 60.0 ) >= ( double ) ( ( double ) V_20 + 0.5 ) ) {
V_20
=
V_20
+
1 ;
}
V_19
=
V_19
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_17 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
1.007752288 ) ;
}
break;
}
F_5 () ;
}
else {
V_12
=
V_19
-
2 ;
}
V_9 ->
V_31
[ V_15 ] .
V_32 .
V_17
=
V_17 ;
V_9 ->
V_31
[ V_15 ] .
V_32 .
V_33
[ V_16 ] .
V_18
=
V_18 ;
V_9 ->
V_31
[ V_15 ] .
V_32 .
V_33
[ V_16 ] .
V_34
=
V_14 ;
V_9 ->
V_31
[ V_15 ] .
V_32 .
V_33
[ V_16 ] .
V_20
=
V_20 ;
V_13
=
F_6
( V_9 ->
V_23 .
V_35
+
4
+
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
V_13
=
( V_13
>>
4 )
&
0xF ;
if ( V_17 == V_28 ) {
V_13
=
V_13
|
0x10 ;
}
if ( V_17 == V_29 ) {
V_13
=
V_13
|
0x20 ;
}
F_7 ( V_13 , V_9 -> V_23 . V_35 + 4 + ( 16 * V_16 ) + ( 64 * V_15 ) ) ;
F_7 ( 0 , V_9 -> V_23 . V_35 + 8 + ( 16 * V_16 ) + ( 64 * V_15 ) ) ;
F_7 ( V_12 , V_9 -> V_23 . V_35 + 0 + ( 16 * V_16 ) + ( 64 * V_15 ) ) ;
V_9 ->
V_31
[ V_15 ] .
V_32 .
V_33
[ V_16 ] .
V_36
=
1 ;
} else {
F_8 ( L_2 ) ;
V_11
=
- 9 ;
}
} else {
F_8 ( L_3 ) ;
V_11 =
- 8 ;
}
} else {
F_8 ( L_4 ) ;
V_11 = - 7 ;
}
}
else {
F_8 ( L_5 ) ;
V_11 = - 6 ;
}
}
else {
F_8 ( L_6 ) ;
V_11 = - 5 ;
}
}
else {
F_8 ( L_7 ) ;
V_11 = - 4 ;
}
} else {
F_8 ( L_8 ) ;
V_11 = - 3 ;
}
} else {
F_8 ( L_9 ) ;
V_11 = - 2 ;
}
V_7 [ 0 ] = ( unsigned int ) V_20 ;
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_37 ;
unsigned int V_38 ;
unsigned int V_39 ;
unsigned char V_15 , V_40 ;
unsigned char V_16 ;
unsigned char V_41 ;
unsigned char V_42 ;
unsigned char V_43 ;
unsigned char V_44 ;
V_15 = ( unsigned char ) F_2 ( V_6 -> V_22 ) ;
V_40 = ( unsigned char ) V_7 [ 0 ] ;
V_16 = ( unsigned char ) V_7 [ 1 ] ;
V_41 = ( unsigned char ) V_7 [ 2 ] ;
V_42 = ( unsigned char ) V_7 [ 3 ] ;
V_43 = ( unsigned char ) V_7 [ 4 ] ;
V_44 = ( unsigned char ) V_7 [ 5 ] ;
V_11 = V_6 -> V_21 ;
V_9 -> V_45 = V_46 ;
if ( V_15 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_15 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_16 <= 1 ) {
switch ( V_40 )
{
case V_47 :
V_37 =
F_6 ( V_9 -> V_23 .
V_35 + 8 +
( 16 * V_16 ) +
( 64 * V_15 ) ) ;
if ( V_37 & 0x10 ) {
if ( V_41 == 0 ||
V_41 == 1 ||
V_41 ==
V_48
|| V_41 ==
V_49
|| V_41 ==
V_50 )
{
if ( V_42 == 0
|| V_42
== 1
|| V_41 >
1 ) {
if ( ( V_43 == V_51 ) || ( V_43 == V_52 ) ) {
if ( ( V_44 == V_47 ) || ( V_44 == V_53 ) ) {
V_9 ->
V_31
[ V_15 ] .
V_32 .
V_33
[ V_16 ] .
V_44
=
V_44 ;
V_39
=
F_6
( V_9 ->
V_23 .
V_35
+
4
+
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
V_39
=
( V_39
>>
4 )
&
0x30 ;
if ( V_41 > 1 ) {
V_42
=
0 ;
V_39
=
V_39
|
0x40 ;
if ( V_41 == V_48 ) {
V_39
=
V_39
|
0x780 ;
}
if ( V_41 == V_49 ) {
V_39
=
V_39
|
0x180 ;
}
V_41
=
0 ;
}
V_39
=
V_39
|
V_43
|
( V_44
*
2 )
|
( V_41
*
4 )
|
( V_42
*
8 ) ;
V_38
=
F_6
( V_9 ->
V_23 .
V_35
+
0
+
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
V_38
=
F_6
( V_9 ->
V_23 .
V_35
+
12
+
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
F_7 ( V_39 , V_9 -> V_23 . V_35 + 4 + ( 16 * V_16 ) + ( 64 * V_15 ) ) ;
F_7 ( 1 , V_9 -> V_23 . V_35 + 8 + ( 16 * V_16 ) + ( 64 * V_15 ) ) ;
}
else {
F_8 ( L_10 ) ;
V_11
=
- 9 ;
}
}
else {
F_8 ( L_11 ) ;
V_11
=
- 8 ;
}
}
else {
F_8 ( L_12 ) ;
V_11 =
- 7 ;
}
}
else {
F_8 ( L_13 ) ;
V_11 = - 6 ;
}
} else {
F_8 ( L_14 ) ;
V_11 = - 5 ;
}
break;
case V_53 :
V_37 = F_6 ( V_9 -> V_23 .
V_35 + 8 +
( 16 * V_16 ) +
( 64 * V_15 ) ) ;
if ( V_37 & 0x10 ) {
if ( V_37 & 0x1 ) {
V_9 ->
V_31
[ V_15 ] .
V_32 .
V_33
[ V_16 ] .
V_44
=
V_53 ;
F_7 ( 0 , V_9 ->
V_23 .
V_35 + 8 +
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
}
else {
F_8 ( L_15 ) ;
V_11 = - 6 ;
}
}
else {
F_8 ( L_14 ) ;
V_11 = - 5 ;
}
}
}
else {
F_8 ( L_16 ) ;
V_11 = - 4 ;
}
} else {
F_8 ( L_17 ) ;
V_11 = - 3 ;
}
} else {
F_8 ( L_18 ) ;
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
unsigned int V_37 ;
unsigned char V_15 ;
unsigned char V_16 ;
unsigned char * V_54 ;
unsigned int * V_55 ;
unsigned char * V_56 ;
unsigned char * V_57 ;
unsigned char * V_58 ;
unsigned char * V_59 ;
unsigned char * V_60 ;
V_11 = V_6 -> V_21 ;
V_15 = F_2 ( V_6 -> V_22 ) ;
V_16 = F_11 ( V_6 -> V_22 ) ;
V_54 = ( unsigned char * ) & V_7 [ 0 ] ;
V_55 = ( unsigned int * ) & V_7 [ 1 ] ;
V_56 = ( unsigned char * ) & V_7 [ 2 ] ;
V_57 = ( unsigned char * ) & V_7 [ 3 ] ;
V_58 = ( unsigned char * ) & V_7 [ 4 ] ;
V_59 = ( unsigned char * ) & V_7 [ 5 ] ;
V_60 = ( unsigned char * ) & V_7 [ 6 ] ;
if ( V_15 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_15 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_16 <= 1 ) {
V_37 = F_6 ( V_9 -> V_23 .
V_35 + 8 + ( 16 * V_16 ) +
( 64 * V_15 ) ) ;
if ( V_37 & 0x10 ) {
* V_59 = V_37 & 1 ;
V_37 = F_6 ( V_9 -> V_23 .
V_35 + 4 +
( 16 * V_16 ) +
( 64 * V_15 ) ) ;
* V_58 =
( unsigned char ) ( ( V_37 >> 4 ) & 1 ) ;
* V_60 =
( unsigned char ) ( ( V_37 >> 5 ) & 1 ) ;
if ( V_37 & 0x600 ) {
if ( V_37 & 0x400 ) {
if ( ( V_37 & 0x7800 )
== 0x7800 ) {
* V_56 =
V_48 ;
}
if ( ( V_37 & 0x7800 )
== 0x1800 ) {
* V_56 =
V_49 ;
}
if ( ( V_37 & 0x7800 )
== 0x0000 ) {
* V_56 =
V_50 ;
}
}
else {
* V_56 = 1 ;
}
* V_57 = 0 ;
}
else {
* V_56 =
( unsigned char ) ( ( V_37 >> 6 )
& 1 ) ;
* V_57 =
( unsigned char ) ( ( V_37 >> 7 )
& 1 ) ;
}
* V_54 =
V_9 ->
V_31 [ V_15 ] .
V_32 .
V_33 [ V_16 ] .
V_18 ;
* V_55 =
V_9 ->
V_31 [ V_15 ] .
V_32 .
V_33 [ V_16 ] .
V_20 ;
} else {
F_8 ( L_14 ) ;
V_11 = - 5 ;
}
}
else {
F_8 ( L_19 ) ;
V_11 = - 4 ;
}
} else {
F_8 ( L_8 ) ;
V_11 = - 3 ;
}
} else {
F_8 ( L_9 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_37 ;
unsigned int V_61 = 0 ;
unsigned char V_15 ;
unsigned char V_16 ;
unsigned char V_62 ;
unsigned int V_63 ;
unsigned char * V_64 ;
unsigned int * V_65 ;
V_11 = V_6 -> V_21 ;
V_15 = F_2 ( V_6 -> V_22 ) ;
V_62 = ( unsigned char ) V_7 [ 0 ] ;
V_16 = ( unsigned char ) V_7 [ 1 ] ;
V_63 = ( unsigned int ) V_7 [ 2 ] ;
V_64 = ( unsigned char * ) & V_7 [ 0 ] ;
V_65 = ( unsigned int * ) & V_7 [ 1 ] ;
if ( V_62 == V_66 ) {
V_7 [ 0 ] = V_9 -> V_67 .
V_68 [ V_9 ->
V_67 . V_69 ] . V_70 ;
V_7 [ 1 ] = V_9 -> V_67 .
V_68 [ V_9 ->
V_67 . V_69 ] . V_71 ;
V_7 [ 2 ] = V_9 -> V_67 .
V_68 [ V_9 ->
V_67 . V_69 ] . V_72 ;
V_9 ->
V_67 .
V_69 = ( V_9 ->
V_67 .
V_69 + 1 ) % V_73 ;
return V_6 -> V_21 ;
}
if ( V_15 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_15 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_16 <= 1 ) {
V_37 = F_6 ( V_9 -> V_23 .
V_35 + 8 + ( 16 * V_16 ) +
( 64 * V_15 ) ) ;
if ( V_37 & 0x10 ) {
if ( V_37 & 0x1 ) {
switch ( V_62 ) {
case V_74 :
V_37 =
F_6 ( V_9 ->
V_23 .
V_35 + 4 +
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
V_37 =
V_37 & 0xF ;
if ( V_37 & 1 ) {
if ( V_37 &
2 ) {
if ( V_37 & 4 ) {
* V_64
=
3 ;
} else {
* V_64
=
2 ;
}
} else {
* V_64
=
1 ;
}
} else {
* V_64
= 0 ;
}
break;
case V_75 :
if ( ( V_63 >= 0 )
&& ( V_63
<=
65535UL ) )
{
for (; ; ) {
V_37
=
F_6
( V_9 ->
V_23 .
V_35
+
4
+
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
if ( ( V_37 & 4 ) == 4 ) {
* V_64
=
3 ;
* V_65
=
F_6
( V_9 ->
V_23 .
V_35
+
0
+
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
break;
}
else {
if ( ( V_37 & 2 ) == 2 ) {
* V_64
=
2 ;
* V_65
=
F_6
( V_9 ->
V_23 .
V_35
+
0
+
( 16 * V_16 ) + ( 64 * V_15 ) ) ;
break;
}
else {
if ( ( V_37 & 1 ) == 1 ) {
* V_64
=
1 ;
}
else {
* V_64
=
0 ;
}
}
}
if ( V_61 == V_63 ) {
break;
} else {
V_61
=
V_61
+
1 ;
F_13 ( 1000 ) ;
}
}
if ( ( * V_64 != 3 ) && ( V_61 == V_63 ) && ( V_63 != 0 ) ) {
* V_64
=
4 ;
}
} else {
F_8 ( L_20 ) ;
V_11 =
- 7 ;
}
break;
default:
F_3 ( L_21 ) ;
}
}
else {
F_8 ( L_22 ) ;
V_11 = - 6 ;
}
} else {
F_8 ( L_14 ) ;
V_11 = - 5 ;
}
}
else {
F_8 ( L_16 ) ;
V_11 = - 4 ;
}
} else {
F_8 ( L_8 ) ;
V_11 = - 3 ;
}
} else {
F_8 ( L_9 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
