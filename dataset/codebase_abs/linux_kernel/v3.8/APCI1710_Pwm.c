static int F_1 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_4 ,
unsigned char V_5 ,
unsigned char V_6 ,
unsigned int V_7 ,
unsigned int V_8 ,
unsigned int * V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_14 = 0 ;
unsigned int V_15 = 0 ;
unsigned int V_16 = 0 ;
unsigned int V_17 ;
double V_18 = 0 ;
double V_19 = 0 ;
if ( V_3 < 4 ) {
if ( ( V_12 -> V_20 .
V_21 [ V_3 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_4 <= 1 ) {
if ( ( V_5 == V_23 ) ||
( V_5 == V_24 ) ||
( V_5 == V_25 ) ) {
if ( V_6 <= 4 ) {
if ( ( ( V_5 ==
V_23 )
&& ( V_6
== 0 )
&& ( V_7
>= 266 )
&& ( V_7
<=
0xFFFFFFFFUL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 1 )
&& ( V_7
>= 1 )
&& ( V_7
<=
571230650UL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 2 )
&& ( V_7
>= 1 )
&& ( V_7
<=
571230UL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 3 )
&& ( V_7
>= 1 )
&& ( V_7
<=
571UL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 4 )
&& ( V_7
>= 1 )
&& ( V_7
<= 9UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 0 )
&& ( V_7
>= 242 )
&& ( V_7
<=
0xFFFFFFFFUL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 1 )
&& ( V_7
>= 1 )
&& ( V_7
<=
519691043UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 2 )
&& ( V_7
>= 1 )
&& ( V_7
<=
519691UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 3 )
&& ( V_7
>= 1 )
&& ( V_7
<=
520UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 4 )
&& ( V_7
>= 1 )
&& ( V_7
<= 8UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 0 )
&& ( V_7
>= 200 )
&& ( V_7
<=
0xFFFFFFFFUL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 1 )
&& ( V_7
>= 1 )
&& ( V_7
<=
429496729UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 2 )
&& ( V_7
>= 1 )
&& ( V_7
<=
429496UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 3 )
&& ( V_7
>= 1 )
&& ( V_7
<=
429UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 4 )
&& ( V_7
>= 1 )
&& ( V_7
<=
7UL ) ) ) {
if ( ( ( V_5 == V_23 ) && ( V_6 == 0 ) && ( V_8 >= 266 ) && ( V_8 <= 0xFFFFFFFFUL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 1 ) && ( V_8 >= 1 ) && ( V_8 <= 571230650UL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 2 ) && ( V_8 >= 1 ) && ( V_8 <= 571230UL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 3 ) && ( V_8 >= 1 ) && ( V_8 <= 571UL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 4 ) && ( V_8 >= 1 ) && ( V_8 <= 9UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 0 ) && ( V_8 >= 242 ) && ( V_8 <= 0xFFFFFFFFUL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 1 ) && ( V_8 >= 1 ) && ( V_8 <= 519691043UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 2 ) && ( V_8 >= 1 ) && ( V_8 <= 519691UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 3 ) && ( V_8 >= 1 ) && ( V_8 <= 520UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 4 ) && ( V_8 >= 1 ) && ( V_8 <= 8UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 0 ) && ( V_8 >= 200 ) && ( V_8 <= 0xFFFFFFFFUL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 1 ) && ( V_8 >= 1 ) && ( V_8 <= 429496729UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 2 ) && ( V_8 >= 1 ) && ( V_8 <= 429496UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 3 ) && ( V_8 >= 1 ) && ( V_8 <= 429UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 4 ) && ( V_8 >= 1 ) && ( V_8 <= 7UL ) ) ) {
if ( ( ( V_5 == V_25 ) && ( V_12 -> V_20 . V_26 > 0 ) ) || ( V_5 != V_25 ) ) {
F_2
() ;
switch ( V_6 ) {
case 0 :
V_15
=
( unsigned int )
( V_7
*
( 0.00025 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_7 * ( 0.00025 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
* V_9
=
( unsigned int )
( V_15
/
( 0.00025 * ( double ) V_5 ) ) ;
V_18
=
( double )
V_15
/
( 0.00025
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 0.00025 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_9 + 0.5 ) ) {
* V_9
=
* V_9
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 1 :
V_15
=
( unsigned int )
( V_7
*
( 0.25 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_7 * ( 0.25 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
* V_9
=
( unsigned int )
( V_15
/
( 0.25 * ( double ) V_5 ) ) ;
V_18
=
( double )
V_15
/
(
( double )
0.25
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 0.25 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_9 + 0.5 ) ) {
* V_9
=
* V_9
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 2 :
V_15
=
V_7
*
( 250.0
*
V_5 ) ;
if ( ( double ) ( ( double ) V_7 * ( 250.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
* V_9
=
( unsigned int )
( V_15
/
( 250.0 * ( double ) V_5 ) ) ;
V_18
=
( double )
V_15
/
( 250.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 250.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_9 + 0.5 ) ) {
* V_9
=
* V_9
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 3 :
V_15
=
( unsigned int )
( V_7
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) V_7 * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
* V_9
=
( unsigned int )
( V_15
/
( 250000.0
*
( double )
V_5 ) ) ;
V_18
=
( double )
V_15
/
( 250000.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 250000.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_9 + 0.5 ) ) {
* V_9
=
* V_9
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 4 :
V_15
=
( unsigned int )
(
( V_7
*
60 )
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) ( V_7 * 60.0 ) * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
* V_9
=
( unsigned int )
( V_15
/
( 250000.0
*
( double )
V_5 ) )
/
60 ;
V_18
=
(
( double )
V_15
/
( 250000.0
*
( double )
V_5 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_15 / ( 250000.0 * ( double ) V_5 ) ) / 60.0 ) >= ( double ) ( ( double ) * V_9 + 0.5 ) ) {
* V_9
=
* V_9
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
}
switch ( V_6 ) {
case 0 :
V_16
=
( unsigned int )
( V_8
*
( 0.00025 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_8 * ( 0.00025 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
* V_10
=
( unsigned int )
( V_16
/
( 0.00025 * ( double ) V_5 ) ) ;
V_19
=
( double )
V_16
/
( 0.00025
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 0.00025 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_10 + 0.5 ) ) {
* V_10
=
* V_10
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 1 :
V_16
=
( unsigned int )
( V_8
*
( 0.25 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_8 * ( 0.25 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
* V_10
=
( unsigned int )
( V_16
/
( 0.25 * ( double ) V_5 ) ) ;
V_19
=
( double )
V_16
/
(
( double )
0.25
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 0.25 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_10 + 0.5 ) ) {
* V_10
=
* V_10
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 2 :
V_16
=
V_8
*
( 250.0
*
V_5 ) ;
if ( ( double ) ( ( double ) V_8 * ( 250.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
* V_10
=
( unsigned int )
( V_16
/
( 250.0 * ( double ) V_5 ) ) ;
V_19
=
( double )
V_16
/
( 250.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 250.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_10 + 0.5 ) ) {
* V_10
=
* V_10
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 3 :
V_16
=
( unsigned int )
( V_8
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) V_8 * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
* V_10
=
( unsigned int )
( V_16
/
( 250000.0
*
( double )
V_5 ) ) ;
V_19
=
( double )
V_16
/
( 250000.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 250000.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) * V_10 + 0.5 ) ) {
* V_10
=
* V_10
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 4 :
V_16
=
( unsigned int )
(
( V_8
*
60 )
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) ( V_8 * 60.0 ) * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
* V_10
=
( unsigned int )
( V_16
/
( 250000.0
*
( double )
V_5 ) )
/
60 ;
V_19
=
(
( double )
V_16
/
( 250000.0
*
( double )
V_5 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_16 / ( 250000.0 * ( double ) V_5 ) ) / 60.0 ) >= ( double ) ( ( double ) * V_10 + 0.5 ) ) {
* V_10
=
* V_10
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
}
F_3 () ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_5
=
V_5 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_6
=
V_6 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_30
=
V_18 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_31
=
* V_9 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_32
=
V_19 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_33
=
* V_10 ;
F_4 ( V_15 , V_12 -> V_20 . V_34 + 0 + ( 20 * V_4 ) + ( 64 * V_3 ) ) ;
F_4 ( V_16 , V_12 -> V_20 . V_34 + 4 + ( 20 * V_4 ) + ( 64 * V_3 ) ) ;
V_17
=
F_5
( V_12 ->
V_20 .
V_34
+
8
+
( 20 * V_4 ) + ( 64 * V_3 ) ) ;
V_17
=
V_17
&
0x7F ;
if ( V_5 == V_25 ) {
V_17
=
V_17
|
0x80 ;
}
F_4 ( V_17 , V_12 -> V_20 . V_34 + 8 + ( 20 * V_4 ) + ( 64 * V_3 ) ) ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_35
=
1 ;
} else {
F_6 ( L_1 ) ;
V_14
=
- 9 ;
}
} else {
F_6 ( L_2 ) ;
V_14 =
- 8 ;
}
} else {
F_6 ( L_3 ) ;
V_14 = - 7 ;
}
}
else {
F_6 ( L_4 ) ;
V_14 = - 6 ;
}
}
else {
F_6 ( L_5 ) ;
V_14 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_14 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_14 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_14 = - 2 ;
}
return V_14 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_4 ,
unsigned char * V_36 ,
unsigned int * V_37 ,
unsigned int * V_38 ,
unsigned char * V_39 ,
unsigned char * V_40 ,
unsigned char * V_41 ,
unsigned char * V_42 ,
unsigned char * V_43 ,
unsigned char * V_44 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_14 = 0 ;
unsigned int V_45 ;
unsigned int V_17 ;
if ( V_3 < 4 ) {
if ( ( V_12 -> V_20 .
V_21 [ V_3 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_4 <= 1 ) {
V_45 = F_5 ( V_12 -> V_20 .
V_34 + 12 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
if ( V_45 & 0x10 ) {
* V_37 =
F_5 ( V_12 -> V_20 .
V_34 + 0 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
* V_38 =
F_5 ( V_12 -> V_20 .
V_34 + 4 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
V_17 = F_5 ( V_12 -> V_20 .
V_34 + 8 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
* V_39 =
( unsigned char ) ( ( V_17 >> 5 ) & 1 ) ;
* V_40 =
( unsigned char ) ( ( V_17 >> 0 ) & 1 ) ;
* V_41 =
( unsigned char ) ( ( V_17 >> 1 ) & 1 ) ;
* V_42 =
( unsigned char ) ( ( V_17 >> 4 ) & 1 ) ;
* V_43 =
( unsigned char ) ( ( V_17 >> 3 ) & 1 ) ;
if ( * V_41 ) {
* V_41 =
* V_41 +
( unsigned char ) ( ( V_17 >>
2 ) & 1 ) ;
}
V_17 = F_5 ( V_12 -> V_20 .
V_34 + 8 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
* V_44 =
( unsigned char ) ( ( V_17 >> 0 ) & 1 ) ;
* V_36 = V_12 ->
V_27 [ V_3 ] .
V_28 .
V_29 [ V_4 ] . V_6 ;
}
else {
F_6 ( L_9 ) ;
V_14 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_14 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_14 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_14 = - 2 ;
}
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_50 )
{
unsigned char V_51 ;
int V_14 = 0 ;
V_51 = F_9 ( V_49 -> V_52 ) ;
switch ( V_51 ) {
case V_53 :
V_14 = F_1 ( V_2 , ( unsigned char ) F_10 ( V_49 -> V_52 ) ,
( unsigned char ) V_50 [ 0 ] ,
( unsigned char ) V_50 [ 1 ] ,
( unsigned char ) V_50 [ 2 ] ,
( unsigned int ) V_50 [ 3 ] ,
( unsigned int ) V_50 [ 4 ] ,
( unsigned int * ) & V_50 [ 0 ] ,
( unsigned int * ) & V_50 [ 1 ]
) ;
break;
case V_54 :
V_14 = F_7 ( V_2 , ( unsigned char ) F_10 ( V_49 -> V_52 ) ,
( unsigned char ) V_50 [ 0 ] ,
( unsigned char * ) & V_50 [ 0 ] ,
( unsigned int * ) & V_50 [ 1 ] ,
( unsigned int * ) & V_50 [ 2 ] ,
( unsigned char * ) & V_50 [ 3 ] ,
( unsigned char * ) & V_50 [ 4 ] ,
( unsigned char * ) & V_50 [ 5 ] ,
( unsigned char * ) & V_50 [ 6 ] ,
( unsigned char * ) & V_50 [ 7 ] ,
( unsigned char * ) & V_50 [ 8 ]
) ;
break;
default:
F_11 ( L_10 ) ;
}
if ( V_14 >= 0 )
V_14 = V_49 -> V_55 ;
return V_14 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_4 ,
unsigned char V_56 ,
unsigned char V_57 ,
unsigned char V_58 ,
unsigned char V_59 ,
unsigned char V_60 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_14 = 0 ;
unsigned int V_45 ;
unsigned int V_17 ;
V_12 -> V_61 = V_62 ;
if ( V_3 < 4 ) {
if ( ( V_12 -> V_20 .
V_21 [ V_3 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_4 <= 1 ) {
V_45 = F_5 ( V_12 -> V_20 .
V_34 + 12 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
if ( V_45 & 0x10 ) {
if ( V_56 <= 1 ) {
if ( V_57 <= 1 ) {
if ( V_58 <= 2 ) {
if ( V_59
<= 1 ) {
if ( V_60 == V_63 || V_60 == V_64 ) {
V_17
=
F_5
( V_12 ->
V_20 .
V_34
+
8
+
( 20 * V_4 ) + ( 64 * V_3 ) ) ;
V_17
=
V_17
&
0x80 ;
V_17
=
V_17
|
V_57
|
( V_60
<<
3 )
|
( V_59
<<
4 )
|
( V_56
<<
5 ) ;
if ( V_58 & 3 ) {
V_17
=
V_17
|
2 ;
if ( V_58 & 2 ) {
V_17
=
V_17
|
4 ;
}
}
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_60
=
V_60 ;
F_4 ( V_17 , V_12 -> V_20 . V_34 + 8 + ( 20 * V_4 ) + ( 64 * V_3 ) ) ;
F_4 ( 1 , V_12 -> V_20 . V_34 + 12 + ( 20 * V_4 ) + ( 64 * V_3 ) ) ;
}
else {
F_6 ( L_11 ) ;
V_14
=
- 10 ;
}
}
else {
F_6 ( L_12 ) ;
V_14
=
- 9 ;
}
}
else {
F_6 ( L_13 ) ;
V_14 =
- 8 ;
}
}
else {
F_6 ( L_14 ) ;
V_14 = - 7 ;
}
}
else {
F_6 ( L_15 ) ;
V_14 = - 6 ;
}
}
else {
F_6 ( L_9 ) ;
V_14 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_14 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_14 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_14 = - 2 ;
}
return V_14 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_4 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_14 = 0 ;
unsigned int V_45 ;
if ( V_3 < 4 ) {
if ( ( V_12 -> V_20 .
V_21 [ V_3 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_4 <= 1 ) {
V_45 = F_5 ( V_12 -> V_20 .
V_34 + 12 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
if ( V_45 & 0x10 ) {
if ( V_45 & 0x1 ) {
F_4 ( 0 , V_12 -> V_20 .
V_34 + 12 +
( 20 * V_4 ) +
( 64 * V_3 ) ) ;
}
else {
F_6 ( L_16 ) ;
V_14 = - 6 ;
}
}
else {
F_6 ( L_17 ) ;
V_14 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_14 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_14 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_14 = - 2 ;
}
return V_14 ;
}
static int F_14 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_4 ,
unsigned char V_6 ,
unsigned int V_7 ,
unsigned int V_8 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
unsigned char V_5 ;
int V_14 = 0 ;
unsigned int V_15 = 0 ;
unsigned int V_16 = 0 ;
unsigned int V_31 = 0 ;
unsigned int V_33 = 0 ;
unsigned int V_45 ;
unsigned int V_17 ;
double V_18 = 0 ;
double V_19 = 0 ;
if ( V_3 < 4 ) {
if ( ( V_12 -> V_20 .
V_21 [ V_3 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_4 <= 1 ) {
V_45 = F_5 ( V_12 -> V_20 .
V_34 + 12 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
if ( V_45 & 0x10 ) {
V_5 = V_12 ->
V_27 [ V_3 ] .
V_28 .
V_5 ;
if ( V_6 <= 4 ) {
if ( ( ( V_5 ==
V_23 )
&& ( V_6
== 0 )
&& ( V_7
>= 266 )
&& ( V_7
<=
0xFFFFFFFFUL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 1 )
&& ( V_7
>= 1 )
&& ( V_7
<=
571230650UL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 2 )
&& ( V_7
>= 1 )
&& ( V_7
<=
571230UL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 3 )
&& ( V_7
>= 1 )
&& ( V_7
<=
571UL ) )
|| ( ( V_5 ==
V_23 )
&& ( V_6
== 4 )
&& ( V_7
>= 1 )
&& ( V_7
<= 9UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 0 )
&& ( V_7
>= 242 )
&& ( V_7
<=
0xFFFFFFFFUL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 1 )
&& ( V_7
>= 1 )
&& ( V_7
<=
519691043UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 2 )
&& ( V_7
>= 1 )
&& ( V_7
<=
519691UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 3 )
&& ( V_7
>= 1 )
&& ( V_7
<=
520UL ) )
|| ( ( V_5 ==
V_24 )
&& ( V_6
== 4 )
&& ( V_7
>= 1 )
&& ( V_7
<= 8UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 0 )
&& ( V_7
>= 200 )
&& ( V_7
<=
0xFFFFFFFFUL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 1 )
&& ( V_7
>= 1 )
&& ( V_7
<=
429496729UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 2 )
&& ( V_7
>= 1 )
&& ( V_7
<=
429496UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 3 )
&& ( V_7
>= 1 )
&& ( V_7
<=
429UL ) )
|| ( ( V_5 ==
V_25 )
&& ( V_6
== 4 )
&& ( V_7
>= 1 )
&& ( V_7
<=
7UL ) ) ) {
if ( ( ( V_5 == V_23 ) && ( V_6 == 0 ) && ( V_8 >= 266 ) && ( V_8 <= 0xFFFFFFFFUL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 1 ) && ( V_8 >= 1 ) && ( V_8 <= 571230650UL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 2 ) && ( V_8 >= 1 ) && ( V_8 <= 571230UL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 3 ) && ( V_8 >= 1 ) && ( V_8 <= 571UL ) ) || ( ( V_5 == V_23 ) && ( V_6 == 4 ) && ( V_8 >= 1 ) && ( V_8 <= 9UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 0 ) && ( V_8 >= 242 ) && ( V_8 <= 0xFFFFFFFFUL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 1 ) && ( V_8 >= 1 ) && ( V_8 <= 519691043UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 2 ) && ( V_8 >= 1 ) && ( V_8 <= 519691UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 3 ) && ( V_8 >= 1 ) && ( V_8 <= 520UL ) ) || ( ( V_5 == V_24 ) && ( V_6 == 4 ) && ( V_8 >= 1 ) && ( V_8 <= 8UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 0 ) && ( V_8 >= 200 ) && ( V_8 <= 0xFFFFFFFFUL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 1 ) && ( V_8 >= 1 ) && ( V_8 <= 429496729UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 2 ) && ( V_8 >= 1 ) && ( V_8 <= 429496UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 3 ) && ( V_8 >= 1 ) && ( V_8 <= 429UL ) ) || ( ( V_5 == V_25 ) && ( V_6 == 4 ) && ( V_8 >= 1 ) && ( V_8 <= 7UL ) ) ) {
F_2 () ;
switch ( V_6 ) {
case 0 :
V_15
=
( unsigned int )
( V_7
*
( 0.00025 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_7 * ( 0.00025 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
V_31
=
( unsigned int )
( V_15
/
( 0.00025 * ( double ) V_5 ) ) ;
V_18
=
( double )
V_15
/
( 0.00025
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 0.00025 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_31 + 0.5 ) ) {
V_31
=
V_31
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 1 :
V_15
=
( unsigned int )
( V_7
*
( 0.25 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_7 * ( 0.25 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
V_31
=
( unsigned int )
( V_15
/
( 0.25 * ( double ) V_5 ) ) ;
V_18
=
( double )
V_15
/
(
( double )
0.25
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 0.25 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_31 + 0.5 ) ) {
V_31
=
V_31
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 2 :
V_15
=
V_7
*
( 250.0
*
V_5 ) ;
if ( ( double ) ( ( double ) V_7 * ( 250.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
V_31
=
( unsigned int )
( V_15
/
( 250.0 * ( double ) V_5 ) ) ;
V_18
=
( double )
V_15
/
( 250.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 250.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_31 + 0.5 ) ) {
V_31
=
V_31
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 3 :
V_15
=
( unsigned int )
( V_7
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) V_7 * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
V_31
=
( unsigned int )
( V_15
/
( 250000.0
*
( double )
V_5 ) ) ;
V_18
=
( double )
V_15
/
( 250000.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_15 / ( 250000.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_31 + 0.5 ) ) {
V_31
=
V_31
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
case 4 :
V_15
=
( unsigned int )
(
( V_7
*
60 )
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) ( V_7 * 60.0 ) * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_15 + 0.5 ) ) ) {
V_15
=
V_15
+
1 ;
}
V_31
=
( unsigned int )
( V_15
/
( 250000.0
*
( double )
V_5 ) )
/
60 ;
V_18
=
(
( double )
V_15
/
( 250000.0
*
( double )
V_5 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_15 / ( 250000.0 * ( double ) V_5 ) ) / 60.0 ) >= ( double ) ( ( double ) V_31 + 0.5 ) ) {
V_31
=
V_31
+
1 ;
}
V_7
=
V_7
-
1 ;
V_15
=
V_15
-
2 ;
if ( V_5 != V_25 ) {
V_15
=
( unsigned int )
(
( double )
( V_15 )
*
1.007752288 ) ;
}
break;
}
switch ( V_6 ) {
case 0 :
V_16
=
( unsigned int )
( V_8
*
( 0.00025 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_8 * ( 0.00025 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
V_33
=
( unsigned int )
( V_16
/
( 0.00025 * ( double ) V_5 ) ) ;
V_19
=
( double )
V_16
/
( 0.00025
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 0.00025 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_33 + 0.5 ) ) {
V_33
=
V_33
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 1 :
V_16
=
( unsigned int )
( V_8
*
( 0.25 * V_5 ) ) ;
if ( ( double ) ( ( double ) V_8 * ( 0.25 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
V_33
=
( unsigned int )
( V_16
/
( 0.25 * ( double ) V_5 ) ) ;
V_19
=
( double )
V_16
/
(
( double )
0.25
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 0.25 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_33 + 0.5 ) ) {
V_33
=
V_33
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 2 :
V_16
=
V_8
*
( 250.0
*
V_5 ) ;
if ( ( double ) ( ( double ) V_8 * ( 250.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
V_33
=
( unsigned int )
( V_16
/
( 250.0 * ( double ) V_5 ) ) ;
V_19
=
( double )
V_16
/
( 250.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 250.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_33 + 0.5 ) ) {
V_33
=
V_33
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 3 :
V_16
=
( unsigned int )
( V_8
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) V_8 * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
V_33
=
( unsigned int )
( V_16
/
( 250000.0
*
( double )
V_5 ) ) ;
V_19
=
( double )
V_16
/
( 250000.0
*
( double )
V_5 ) ;
if ( ( double ) ( ( double ) V_16 / ( 250000.0 * ( double ) V_5 ) ) >= ( double ) ( ( double ) V_33 + 0.5 ) ) {
V_33
=
V_33
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
case 4 :
V_16
=
( unsigned int )
(
( V_8
*
60 )
*
( 250000.0
*
V_5 ) ) ;
if ( ( double ) ( ( double ) ( V_8 * 60.0 ) * ( 250000.0 * ( double ) V_5 ) ) >= ( ( double ) ( ( double ) V_16 + 0.5 ) ) ) {
V_16
=
V_16
+
1 ;
}
V_33
=
( unsigned int )
( V_16
/
( 250000.0
*
( double )
V_5 ) )
/
60 ;
V_19
=
(
( double )
V_16
/
( 250000.0
*
( double )
V_5 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_16 / ( 250000.0 * ( double ) V_5 ) ) / 60.0 ) >= ( double ) ( ( double ) V_33 + 0.5 ) ) {
V_33
=
V_33
+
1 ;
}
V_8
=
V_8
-
1 ;
V_16
=
V_16
-
2 ;
if ( V_5 != V_25 ) {
V_16
=
( unsigned int )
(
( double )
( V_16 )
*
1.007752288 ) ;
}
break;
}
F_3 () ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_6
=
V_6 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_30
=
V_18 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_31
=
V_31 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_32
=
V_19 ;
V_12 ->
V_27
[ V_3 ] .
V_28 .
V_29
[ V_4 ] .
V_33
=
V_33 ;
F_4 ( V_15 , V_12 -> V_20 . V_34 + 0 + ( 20 * V_4 ) + ( 64 * V_3 ) ) ;
F_4 ( V_16 , V_12 -> V_20 . V_34 + 4 + ( 20 * V_4 ) + ( 64 * V_3 ) ) ;
V_17 =
F_5
( V_12 ->
V_20 .
V_34
+ 8 +
( 20 * V_4 ) + ( 64 * V_3 ) ) ;
V_17 =
V_17
& 0x7F ;
if ( V_5 == V_25 ) {
V_17
=
V_17
|
0x80 ;
}
F_4 ( V_17 ,
V_12 ->
V_20 .
V_34
+ 8 +
( 20 * V_4 ) + ( 64 * V_3 ) ) ;
} else {
F_6 ( L_2 ) ;
V_14 =
- 8 ;
}
} else {
F_6 ( L_3 ) ;
V_14 = - 7 ;
}
}
else {
F_6 ( L_4 ) ;
V_14 = - 6 ;
}
}
else {
F_6 ( L_9 ) ;
V_14 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_14 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_14 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_14 = - 2 ;
}
return V_14 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_50 )
{
unsigned char V_65 ;
int V_14 = 0 ;
V_65 = F_9 ( V_49 -> V_52 ) ;
switch ( V_65 ) {
case V_66 :
V_14 = F_12 ( V_2 ,
( unsigned char ) F_10 ( V_49 -> V_52 ) ,
( unsigned char ) V_50 [ 0 ] ,
( unsigned char ) V_50 [ 1 ] ,
( unsigned char ) V_50 [ 2 ] ,
( unsigned char ) V_50 [ 3 ] , ( unsigned char ) V_50 [ 4 ] , ( unsigned char ) V_50 [ 5 ] ) ;
break;
case V_67 :
V_14 = F_13 ( V_2 ,
( unsigned char ) F_10 ( V_49 -> V_52 ) , ( unsigned char ) V_50 [ 0 ] ) ;
break;
case V_68 :
V_14 = F_14 ( V_2 ,
( unsigned char ) F_10 ( V_49 -> V_52 ) ,
( unsigned char ) V_50 [ 0 ] ,
( unsigned char ) V_50 [ 1 ] , ( unsigned int ) V_50 [ 2 ] , ( unsigned int ) V_50 [ 3 ] ) ;
break;
default:
F_11 ( L_18 ) ;
}
if ( V_14 >= 0 )
V_14 = V_49 -> V_55 ;
return V_14 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_50 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_14 = 0 ;
unsigned int V_45 ;
unsigned char V_3 ;
unsigned char V_4 ;
unsigned char * V_69 ;
unsigned char * V_70 ;
V_14 = V_49 -> V_55 ;
V_3 = ( unsigned char ) F_10 ( V_49 -> V_52 ) ;
V_4 = ( unsigned char ) F_9 ( V_49 -> V_52 ) ;
V_69 = ( unsigned char * ) & V_50 [ 0 ] ;
V_70 = ( unsigned char * ) & V_50 [ 1 ] ;
if ( V_3 < 4 ) {
if ( ( V_12 -> V_20 .
V_21 [ V_3 ] &
0xFFFF0000UL ) == V_22 ) {
if ( V_4 <= 1 ) {
V_45 = F_5 ( V_12 -> V_20 .
V_34 + 12 + ( 20 * V_4 ) +
( 64 * V_3 ) ) ;
if ( V_45 & 0x10 ) {
if ( V_45 & 0x1 ) {
* V_69 =
( unsigned char ) ( ( V_45 >> 7 )
& 1 ) ;
* V_70 =
( unsigned char ) ( ( V_45 >> 6 )
& 1 ) ;
}
else {
F_6 ( L_19 ) ;
V_14 = - 6 ;
}
}
else {
F_6 ( L_9 ) ;
V_14 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_14 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_14 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_14 = - 2 ;
}
return V_14 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_48 * V_49 ,
unsigned int * V_50 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
V_50 [ 0 ] = V_12 -> V_71 .
V_72 [ V_12 ->
V_71 . V_73 ] . V_74 ;
V_50 [ 1 ] = V_12 -> V_71 .
V_72 [ V_12 ->
V_71 . V_73 ] . V_75 ;
V_50 [ 2 ] = V_12 -> V_71 .
V_72 [ V_12 ->
V_71 . V_73 ] . V_76 ;
V_12 ->
V_71 .
V_73 = ( V_12 ->
V_71 . V_73 + 1 ) % V_77 ;
return V_49 -> V_55 ;
}
