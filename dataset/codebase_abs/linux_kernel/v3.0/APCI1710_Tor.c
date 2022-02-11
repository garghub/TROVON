int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_9 = 0 ;
unsigned int V_10 ;
double V_11 = 0 ;
unsigned char V_12 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned char V_15 ;
unsigned int V_16 ;
unsigned int V_17 = 0 ;
V_8 = V_6 -> V_18 ;
V_12 = ( unsigned char ) F_2 ( V_6 -> V_19 ) ;
V_13 = ( unsigned char ) V_7 [ 0 ] ;
V_14 = ( unsigned char ) V_7 [ 1 ] ;
V_15 = ( unsigned char ) V_7 [ 2 ] ;
V_16 = ( unsigned int ) V_7 [ 3 ] ;
F_3 ( L_1 , V_14 ) ;
if ( V_12 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_12 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_13 <= 1 ) {
if ( ( V_14 == V_24 ) ||
( V_14 == V_25 ) ||
( V_14 == V_26 ) ||
( V_14 ==
V_27 ) ) {
if ( ( V_15 <= 4 )
|| ( V_14 ==
V_27 ) ) {
if ( ( ( V_14 == V_24 ) && ( V_15 == 0 ) && ( V_16 >= 133 ) && ( V_16 <= 0xFFFFFFFFUL ) ) || ( ( V_14 == V_24 ) && ( V_15 == 1 ) && ( V_16 >= 1 ) && ( V_16 <= 571230650UL ) ) || ( ( V_14 == V_24 ) && ( V_15 == 2 ) && ( V_16 >= 1 ) && ( V_16 <= 571230UL ) ) || ( ( V_14 == V_24 ) && ( V_15 == 3 ) && ( V_16 >= 1 ) && ( V_16 <= 571UL ) ) || ( ( V_14 == V_24 ) && ( V_15 == 4 ) && ( V_16 >= 1 ) && ( V_16 <= 9UL ) ) || ( ( V_14 == V_25 ) && ( V_15 == 0 ) && ( V_16 >= 121 ) && ( V_16 <= 0xFFFFFFFFUL ) ) || ( ( V_14 == V_25 ) && ( V_15 == 1 ) && ( V_16 >= 1 ) && ( V_16 <= 519691043UL ) ) || ( ( V_14 == V_25 ) && ( V_15 == 2 ) && ( V_16 >= 1 ) && ( V_16 <= 519691UL ) ) || ( ( V_14 == V_25 ) && ( V_15 == 3 ) && ( V_16 >= 1 ) && ( V_16 <= 520UL ) ) || ( ( V_14 == V_25 ) && ( V_15 == 4 ) && ( V_16 >= 1 ) && ( V_16 <= 8UL ) ) || ( ( V_14 == V_26 ) && ( V_15 == 0 ) && ( V_16 >= 100 ) && ( V_16 <= 0xFFFFFFFFUL ) ) || ( ( V_14 == V_26 ) && ( V_15 == 1 ) && ( V_16 >= 1 ) && ( V_16 <= 429496729UL ) ) || ( ( V_14 == V_26 ) && ( V_15 == 2 ) && ( V_16 >= 1 ) && ( V_16 <= 429496UL ) ) || ( ( V_14 == V_26 ) && ( V_15 == 3 ) && ( V_16 >= 1 ) && ( V_16 <= 429UL ) ) || ( ( V_14 == V_26 ) && ( V_15 == 4 ) && ( V_16 >= 1 ) && ( V_16 <= 7UL ) ) || ( ( V_14 == V_27 ) && ( V_16 >= 2 ) ) ) {
if ( ( ( V_14 == V_26 ) && ( V_20 -> V_21 . V_28 > 0 ) ) || ( V_14 != V_26 ) ) {
if ( ( ( V_14 == V_26 ) && ( ( V_20 -> V_21 . V_22 [ V_12 ] & 0xFFFF ) >= 0x3131 ) ) || ( ( V_14 == V_27 ) && ( ( V_20 -> V_21 . V_22 [ V_12 ] & 0xFFFF ) >= 0x3132 ) ) || ( V_14 == V_24 ) || ( V_14 == V_25 ) ) {
if ( V_14 != V_27 ) {
F_4
() ;
switch ( V_15 ) {
case 0 :
V_9
=
( unsigned int )
( V_16
*
( 0.00025 * V_14 ) ) ;
if ( ( double ) ( ( double ) V_16 * ( 0.00025 * ( double ) V_14 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_17
=
( unsigned int )
( V_9
/
( 0.00025 * ( double ) V_14 ) ) ;
V_11
=
( double )
V_9
/
( 0.00025
*
( double )
V_14 ) ;
if ( ( double ) ( ( double ) V_9 / ( 0.00025 * ( double ) V_14 ) ) >= ( double ) ( ( double ) V_17 + 0.5 ) ) {
V_17
=
V_17
+
1 ;
}
V_16
=
V_16
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_14 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
1.007752288 ) ;
}
break;
case 1 :
V_9
=
( unsigned int )
( V_16
*
( 0.25 * V_14 ) ) ;
if ( ( double ) ( ( double ) V_16 * ( 0.25 * ( double ) V_14 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_17
=
( unsigned int )
( V_9
/
( 0.25 * ( double ) V_14 ) ) ;
V_11
=
( double )
V_9
/
(
( double )
0.25
*
( double )
V_14 ) ;
if ( ( double ) ( ( double ) V_9 / ( 0.25 * ( double ) V_14 ) ) >= ( double ) ( ( double ) V_17 + 0.5 ) ) {
V_17
=
V_17
+
1 ;
}
V_16
=
V_16
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_14 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
1.007752288 ) ;
}
break;
case 2 :
V_9
=
V_16
*
( 250.0
*
V_14 ) ;
if ( ( double ) ( ( double ) V_16 * ( 250.0 * ( double ) V_14 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_17
=
( unsigned int )
( V_9
/
( 250.0 * ( double ) V_14 ) ) ;
V_11
=
( double )
V_9
/
( 250.0
*
( double )
V_14 ) ;
if ( ( double ) ( ( double ) V_9 / ( 250.0 * ( double ) V_14 ) ) >= ( double ) ( ( double ) V_17 + 0.5 ) ) {
V_17
=
V_17
+
1 ;
}
V_16
=
V_16
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_14 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
1.007752288 ) ;
}
break;
case 3 :
V_9
=
( unsigned int )
( V_16
*
( 250000.0
*
V_14 ) ) ;
if ( ( double ) ( ( double ) V_16 * ( 250000.0 * ( double ) V_14 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_17
=
( unsigned int )
( V_9
/
( 250000.0
*
( double )
V_14 ) ) ;
V_11
=
( double )
V_9
/
( 250000.0
*
( double )
V_14 ) ;
if ( ( double ) ( ( double ) V_9 / ( 250000.0 * ( double ) V_14 ) ) >= ( double ) ( ( double ) V_17 + 0.5 ) ) {
V_17
=
V_17
+
1 ;
}
V_16
=
V_16
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_14 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
1.007752288 ) ;
}
break;
case 4 :
V_9
=
( unsigned int )
(
( V_16
*
60 )
*
( 250000.0
*
V_14 ) ) ;
if ( ( double ) ( ( double ) ( V_16 * 60.0 ) * ( 250000.0 * ( double ) V_14 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_17
=
( unsigned int )
( V_9
/
( 250000.0
*
( double )
V_14 ) )
/
60 ;
V_11
=
(
( double )
V_9
/
( 250000.0
*
( double )
V_14 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_9 / ( 250000.0 * ( double ) V_14 ) ) / 60.0 ) >= ( double ) ( ( double ) V_17 + 0.5 ) ) {
V_17
=
V_17
+
1 ;
}
V_16
=
V_16
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_14 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
1.007752288 ) ;
}
break;
}
F_5 () ;
}
else {
V_9
=
V_16
-
2 ;
}
V_20 ->
V_29
[ V_12 ] .
V_30 .
V_14
=
V_14 ;
V_20 ->
V_29
[ V_12 ] .
V_30 .
V_31
[ V_13 ] .
V_15
=
V_15 ;
V_20 ->
V_29
[ V_12 ] .
V_30 .
V_31
[ V_13 ] .
V_32
=
V_11 ;
V_20 ->
V_29
[ V_12 ] .
V_30 .
V_31
[ V_13 ] .
V_17
=
V_17 ;
V_10
=
F_6
( V_20 ->
V_21 .
V_33
+
4
+
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
V_10
=
( V_10
>>
4 )
&
0xF ;
if ( V_14 == V_26 ) {
V_10
=
V_10
|
0x10 ;
}
if ( V_14 == V_27 ) {
V_10
=
V_10
|
0x20 ;
}
F_7 ( V_10 , V_20 -> V_21 . V_33 + 4 + ( 16 * V_13 ) + ( 64 * V_12 ) ) ;
F_7 ( 0 , V_20 -> V_21 . V_33 + 8 + ( 16 * V_13 ) + ( 64 * V_12 ) ) ;
F_7 ( V_9 , V_20 -> V_21 . V_33 + 0 + ( 16 * V_13 ) + ( 64 * V_12 ) ) ;
V_20 ->
V_29
[ V_12 ] .
V_30 .
V_31
[ V_13 ] .
V_34
=
1 ;
} else {
F_8 ( L_2 ) ;
V_8
=
- 9 ;
}
} else {
F_8 ( L_3 ) ;
V_8 =
- 8 ;
}
} else {
F_8 ( L_4 ) ;
V_8 = - 7 ;
}
}
else {
F_8 ( L_5 ) ;
V_8 = - 6 ;
}
}
else {
F_8 ( L_6 ) ;
V_8 = - 5 ;
}
}
else {
F_8 ( L_7 ) ;
V_8 = - 4 ;
}
} else {
F_8 ( L_8 ) ;
V_8 = - 3 ;
}
} else {
F_8 ( L_9 ) ;
V_8 = - 2 ;
}
V_7 [ 0 ] = ( unsigned int ) V_17 ;
return V_8 ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_35 ;
unsigned int V_36 ;
unsigned int V_37 ;
unsigned char V_12 , V_38 ;
unsigned char V_13 ;
unsigned char V_39 ;
unsigned char V_40 ;
unsigned char V_41 ;
unsigned char V_42 ;
V_12 = ( unsigned char ) F_2 ( V_6 -> V_19 ) ;
V_38 = ( unsigned char ) V_7 [ 0 ] ;
V_13 = ( unsigned char ) V_7 [ 1 ] ;
V_39 = ( unsigned char ) V_7 [ 2 ] ;
V_40 = ( unsigned char ) V_7 [ 3 ] ;
V_41 = ( unsigned char ) V_7 [ 4 ] ;
V_42 = ( unsigned char ) V_7 [ 5 ] ;
V_8 = V_6 -> V_18 ;
V_20 -> V_43 = V_44 ;
if ( V_12 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_12 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_13 <= 1 ) {
switch ( V_38 )
{
case V_45 :
V_35 =
F_6 ( V_20 -> V_21 .
V_33 + 8 +
( 16 * V_13 ) +
( 64 * V_12 ) ) ;
if ( V_35 & 0x10 ) {
if ( V_39 == 0 ||
V_39 == 1 ||
V_39 ==
V_46
|| V_39 ==
V_47
|| V_39 ==
V_48 )
{
if ( V_40 == 0
|| V_40
== 1
|| V_39 >
1 ) {
if ( ( V_41 == V_49 ) || ( V_41 == V_50 ) ) {
if ( ( V_42 == V_45 ) || ( V_42 == V_51 ) ) {
V_20 ->
V_29
[ V_12 ] .
V_30 .
V_31
[ V_13 ] .
V_42
=
V_42 ;
V_37
=
F_6
( V_20 ->
V_21 .
V_33
+
4
+
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
V_37
=
( V_37
>>
4 )
&
0x30 ;
if ( V_39 > 1 ) {
V_40
=
0 ;
V_37
=
V_37
|
0x40 ;
if ( V_39 == V_46 ) {
V_37
=
V_37
|
0x780 ;
}
if ( V_39 == V_47 ) {
V_37
=
V_37
|
0x180 ;
}
V_39
=
0 ;
}
V_37
=
V_37
|
V_41
|
( V_42
*
2 )
|
( V_39
*
4 )
|
( V_40
*
8 ) ;
V_36
=
F_6
( V_20 ->
V_21 .
V_33
+
0
+
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
V_36
=
F_6
( V_20 ->
V_21 .
V_33
+
12
+
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
F_7 ( V_37 , V_20 -> V_21 . V_33 + 4 + ( 16 * V_13 ) + ( 64 * V_12 ) ) ;
F_7 ( 1 , V_20 -> V_21 . V_33 + 8 + ( 16 * V_13 ) + ( 64 * V_12 ) ) ;
}
else {
F_8 ( L_10 ) ;
V_8
=
- 9 ;
}
}
else {
F_8 ( L_11 ) ;
V_8
=
- 8 ;
}
}
else {
F_8 ( L_12 ) ;
V_8 =
- 7 ;
}
}
else {
F_8 ( L_13 ) ;
V_8 = - 6 ;
}
} else {
F_8 ( L_14 ) ;
V_8 = - 5 ;
}
break;
case V_51 :
V_35 = F_6 ( V_20 -> V_21 .
V_33 + 8 +
( 16 * V_13 ) +
( 64 * V_12 ) ) ;
if ( V_35 & 0x10 ) {
if ( V_35 & 0x1 ) {
V_20 ->
V_29
[ V_12 ] .
V_30 .
V_31
[ V_13 ] .
V_42
=
V_51 ;
F_7 ( 0 , V_20 ->
V_21 .
V_33 + 8 +
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
}
else {
F_8 ( L_15 ) ;
V_8 = - 6 ;
}
}
else {
F_8 ( L_14 ) ;
V_8 = - 5 ;
}
}
}
else {
F_8 ( L_16 ) ;
V_8 = - 4 ;
}
} else {
F_8 ( L_17 ) ;
V_8 = - 3 ;
}
} else {
F_8 ( L_18 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_35 ;
unsigned char V_12 ;
unsigned char V_13 ;
unsigned char * V_52 ;
unsigned int * V_53 ;
unsigned char * V_54 ;
unsigned char * V_55 ;
unsigned char * V_56 ;
unsigned char * V_57 ;
unsigned char * V_58 ;
V_8 = V_6 -> V_18 ;
V_12 = F_2 ( V_6 -> V_19 ) ;
V_13 = F_11 ( V_6 -> V_19 ) ;
V_52 = ( unsigned char * ) & V_7 [ 0 ] ;
V_53 = ( unsigned int * ) & V_7 [ 1 ] ;
V_54 = ( unsigned char * ) & V_7 [ 2 ] ;
V_55 = ( unsigned char * ) & V_7 [ 3 ] ;
V_56 = ( unsigned char * ) & V_7 [ 4 ] ;
V_57 = ( unsigned char * ) & V_7 [ 5 ] ;
V_58 = ( unsigned char * ) & V_7 [ 6 ] ;
if ( V_12 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_12 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_13 <= 1 ) {
V_35 = F_6 ( V_20 -> V_21 .
V_33 + 8 + ( 16 * V_13 ) +
( 64 * V_12 ) ) ;
if ( V_35 & 0x10 ) {
* V_57 = V_35 & 1 ;
V_35 = F_6 ( V_20 -> V_21 .
V_33 + 4 +
( 16 * V_13 ) +
( 64 * V_12 ) ) ;
* V_56 =
( unsigned char ) ( ( V_35 >> 4 ) & 1 ) ;
* V_58 =
( unsigned char ) ( ( V_35 >> 5 ) & 1 ) ;
if ( V_35 & 0x600 ) {
if ( V_35 & 0x400 ) {
if ( ( V_35 & 0x7800 )
== 0x7800 ) {
* V_54 =
V_46 ;
}
if ( ( V_35 & 0x7800 )
== 0x1800 ) {
* V_54 =
V_47 ;
}
if ( ( V_35 & 0x7800 )
== 0x0000 ) {
* V_54 =
V_48 ;
}
}
else {
* V_54 = 1 ;
}
* V_55 = 0 ;
}
else {
* V_54 =
( unsigned char ) ( ( V_35 >> 6 )
& 1 ) ;
* V_55 =
( unsigned char ) ( ( V_35 >> 7 )
& 1 ) ;
}
* V_52 =
V_20 ->
V_29 [ V_12 ] .
V_30 .
V_31 [ V_13 ] .
V_15 ;
* V_53 =
V_20 ->
V_29 [ V_12 ] .
V_30 .
V_31 [ V_13 ] .
V_17 ;
} else {
F_8 ( L_14 ) ;
V_8 = - 5 ;
}
}
else {
F_8 ( L_19 ) ;
V_8 = - 4 ;
}
} else {
F_8 ( L_8 ) ;
V_8 = - 3 ;
}
} else {
F_8 ( L_9 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_35 ;
unsigned int V_59 = 0 ;
unsigned char V_12 ;
unsigned char V_13 ;
unsigned char V_60 ;
unsigned int V_61 ;
unsigned char * V_62 ;
unsigned int * V_63 ;
V_8 = V_6 -> V_18 ;
V_12 = F_2 ( V_6 -> V_19 ) ;
V_60 = ( unsigned char ) V_7 [ 0 ] ;
V_13 = ( unsigned char ) V_7 [ 1 ] ;
V_61 = ( unsigned int ) V_7 [ 2 ] ;
V_62 = ( unsigned char * ) & V_7 [ 0 ] ;
V_63 = ( unsigned int * ) & V_7 [ 1 ] ;
if ( V_60 == V_64 ) {
V_7 [ 0 ] = V_20 -> V_65 .
V_66 [ V_20 ->
V_65 . V_67 ] . V_68 ;
V_7 [ 1 ] = V_20 -> V_65 .
V_66 [ V_20 ->
V_65 . V_67 ] . V_69 ;
V_7 [ 2 ] = V_20 -> V_65 .
V_66 [ V_20 ->
V_65 . V_67 ] . V_70 ;
V_20 ->
V_65 .
V_67 = ( V_20 ->
V_65 .
V_67 + 1 ) % V_71 ;
return V_6 -> V_18 ;
}
if ( V_12 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_12 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_13 <= 1 ) {
V_35 = F_6 ( V_20 -> V_21 .
V_33 + 8 + ( 16 * V_13 ) +
( 64 * V_12 ) ) ;
if ( V_35 & 0x10 ) {
if ( V_35 & 0x1 ) {
switch ( V_60 ) {
case V_72 :
V_35 =
F_6 ( V_20 ->
V_21 .
V_33 + 4 +
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
V_35 =
V_35 & 0xF ;
if ( V_35 & 1 ) {
if ( V_35 &
2 ) {
if ( V_35 & 4 ) {
* V_62
=
3 ;
} else {
* V_62
=
2 ;
}
} else {
* V_62
=
1 ;
}
} else {
* V_62
= 0 ;
}
break;
case V_73 :
if ( ( V_61 >= 0 )
&& ( V_61
<=
65535UL ) )
{
for (; ; ) {
V_35
=
F_6
( V_20 ->
V_21 .
V_33
+
4
+
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
if ( ( V_35 & 4 ) == 4 ) {
* V_62
=
3 ;
* V_63
=
F_6
( V_20 ->
V_21 .
V_33
+
0
+
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
break;
}
else {
if ( ( V_35 & 2 ) == 2 ) {
* V_62
=
2 ;
* V_63
=
F_6
( V_20 ->
V_21 .
V_33
+
0
+
( 16 * V_13 ) + ( 64 * V_12 ) ) ;
break;
}
else {
if ( ( V_35 & 1 ) == 1 ) {
* V_62
=
1 ;
}
else {
* V_62
=
0 ;
}
}
}
if ( V_59 == V_61 ) {
break;
} else {
V_59
=
V_59
+
1 ;
F_13 ( 1000 ) ;
}
}
if ( ( * V_62 != 3 ) && ( V_59 == V_61 ) && ( V_61 != 0 ) ) {
* V_62
=
4 ;
}
} else {
F_8 ( L_20 ) ;
V_8 =
- 7 ;
}
break;
default:
F_3 ( L_21 ) ;
}
}
else {
F_8 ( L_22 ) ;
V_8 = - 6 ;
}
} else {
F_8 ( L_14 ) ;
V_8 = - 5 ;
}
}
else {
F_8 ( L_16 ) ;
V_8 = - 4 ;
}
} else {
F_8 ( L_8 ) ;
V_8 = - 3 ;
}
} else {
F_8 ( L_9 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
