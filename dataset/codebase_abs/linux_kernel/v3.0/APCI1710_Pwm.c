int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned char V_8 ;
int V_9 = 0 ;
V_8 = F_2 ( V_6 -> V_10 ) ;
switch ( V_8 ) {
case V_11 :
V_9 = F_3 ( V_2 , ( unsigned char ) F_4 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] ,
( unsigned char ) V_7 [ 1 ] ,
( unsigned char ) V_7 [ 2 ] ,
( unsigned int ) V_7 [ 3 ] ,
( unsigned int ) V_7 [ 4 ] ,
( unsigned int * ) & V_7 [ 0 ] ,
( unsigned int * ) & V_7 [ 1 ]
) ;
break;
case V_12 :
V_9 = F_5 ( V_2 , ( unsigned char ) F_4 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] ,
( unsigned char * ) & V_7 [ 0 ] ,
( unsigned int * ) & V_7 [ 1 ] ,
( unsigned int * ) & V_7 [ 2 ] ,
( unsigned char * ) & V_7 [ 3 ] ,
( unsigned char * ) & V_7 [ 4 ] ,
( unsigned char * ) & V_7 [ 5 ] ,
( unsigned char * ) & V_7 [ 6 ] ,
( unsigned char * ) & V_7 [ 7 ] ,
( unsigned char * ) & V_7 [ 8 ]
) ;
break;
default:
F_6 ( L_1 ) ;
}
if ( V_9 >= 0 )
V_9 = V_6 -> V_13 ;
return V_9 ;
}
int F_3 ( struct V_1 * V_2 ,
unsigned char V_14 ,
unsigned char V_15 ,
unsigned char V_16 ,
unsigned char V_17 ,
unsigned int V_18 ,
unsigned int V_19 ,
unsigned int * V_20 , unsigned int * V_21 )
{
int V_9 = 0 ;
unsigned int V_22 = 0 ;
unsigned int V_23 = 0 ;
unsigned int V_24 ;
double V_25 = 0 ;
double V_26 = 0 ;
if ( V_14 < 4 ) {
if ( ( V_27 -> V_28 .
V_29 [ V_14 ] &
0xFFFF0000UL ) == V_30 ) {
if ( V_15 <= 1 ) {
if ( ( V_16 == V_31 ) ||
( V_16 == V_32 ) ||
( V_16 == V_33 ) ) {
if ( V_17 <= 4 ) {
if ( ( ( V_16 ==
V_31 )
&& ( V_17
== 0 )
&& ( V_18
>= 266 )
&& ( V_18
<=
0xFFFFFFFFUL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 1 )
&& ( V_18
>= 1 )
&& ( V_18
<=
571230650UL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 2 )
&& ( V_18
>= 1 )
&& ( V_18
<=
571230UL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 3 )
&& ( V_18
>= 1 )
&& ( V_18
<=
571UL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 4 )
&& ( V_18
>= 1 )
&& ( V_18
<= 9UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 0 )
&& ( V_18
>= 242 )
&& ( V_18
<=
0xFFFFFFFFUL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 1 )
&& ( V_18
>= 1 )
&& ( V_18
<=
519691043UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 2 )
&& ( V_18
>= 1 )
&& ( V_18
<=
519691UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 3 )
&& ( V_18
>= 1 )
&& ( V_18
<=
520UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 4 )
&& ( V_18
>= 1 )
&& ( V_18
<= 8UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 0 )
&& ( V_18
>= 200 )
&& ( V_18
<=
0xFFFFFFFFUL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 1 )
&& ( V_18
>= 1 )
&& ( V_18
<=
429496729UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 2 )
&& ( V_18
>= 1 )
&& ( V_18
<=
429496UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 3 )
&& ( V_18
>= 1 )
&& ( V_18
<=
429UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 4 )
&& ( V_18
>= 1 )
&& ( V_18
<=
7UL ) ) ) {
if ( ( ( V_16 == V_31 ) && ( V_17 == 0 ) && ( V_19 >= 266 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 571230650UL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 571230UL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 571UL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 9UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 0 ) && ( V_19 >= 242 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 519691043UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 519691UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 520UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 8UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 0 ) && ( V_19 >= 200 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 429496729UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 429496UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 429UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 7UL ) ) ) {
if ( ( ( V_16 == V_33 ) && ( V_27 -> V_28 . V_34 > 0 ) ) || ( V_16 != V_33 ) ) {
F_7
() ;
switch ( V_17 ) {
case 0 :
V_22
=
( unsigned int )
( V_18
*
( 0.00025 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_18 * ( 0.00025 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
* V_20
=
( unsigned int )
( V_22
/
( 0.00025 * ( double ) V_16 ) ) ;
V_25
=
( double )
V_22
/
( 0.00025
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 0.00025 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_20 + 0.5 ) ) {
* V_20
=
* V_20
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 1 :
V_22
=
( unsigned int )
( V_18
*
( 0.25 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_18 * ( 0.25 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
* V_20
=
( unsigned int )
( V_22
/
( 0.25 * ( double ) V_16 ) ) ;
V_25
=
( double )
V_22
/
(
( double )
0.25
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 0.25 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_20 + 0.5 ) ) {
* V_20
=
* V_20
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 2 :
V_22
=
V_18
*
( 250.0
*
V_16 ) ;
if ( ( double ) ( ( double ) V_18 * ( 250.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
* V_20
=
( unsigned int )
( V_22
/
( 250.0 * ( double ) V_16 ) ) ;
V_25
=
( double )
V_22
/
( 250.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 250.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_20 + 0.5 ) ) {
* V_20
=
* V_20
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 3 :
V_22
=
( unsigned int )
( V_18
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) V_18 * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
* V_20
=
( unsigned int )
( V_22
/
( 250000.0
*
( double )
V_16 ) ) ;
V_25
=
( double )
V_22
/
( 250000.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 250000.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_20 + 0.5 ) ) {
* V_20
=
* V_20
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 4 :
V_22
=
( unsigned int )
(
( V_18
*
60 )
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) ( V_18 * 60.0 ) * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
* V_20
=
( unsigned int )
( V_22
/
( 250000.0
*
( double )
V_16 ) )
/
60 ;
V_25
=
(
( double )
V_22
/
( 250000.0
*
( double )
V_16 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_22 / ( 250000.0 * ( double ) V_16 ) ) / 60.0 ) >= ( double ) ( ( double ) * V_20 + 0.5 ) ) {
* V_20
=
* V_20
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
}
switch ( V_17 ) {
case 0 :
V_23
=
( unsigned int )
( V_19
*
( 0.00025 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 0.00025 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
* V_21
=
( unsigned int )
( V_23
/
( 0.00025 * ( double ) V_16 ) ) ;
V_26
=
( double )
V_23
/
( 0.00025
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 0.00025 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_21 + 0.5 ) ) {
* V_21
=
* V_21
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 1 :
V_23
=
( unsigned int )
( V_19
*
( 0.25 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 0.25 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
* V_21
=
( unsigned int )
( V_23
/
( 0.25 * ( double ) V_16 ) ) ;
V_26
=
( double )
V_23
/
(
( double )
0.25
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 0.25 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_21 + 0.5 ) ) {
* V_21
=
* V_21
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 2 :
V_23
=
V_19
*
( 250.0
*
V_16 ) ;
if ( ( double ) ( ( double ) V_19 * ( 250.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
* V_21
=
( unsigned int )
( V_23
/
( 250.0 * ( double ) V_16 ) ) ;
V_26
=
( double )
V_23
/
( 250.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 250.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_21 + 0.5 ) ) {
* V_21
=
* V_21
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 3 :
V_23
=
( unsigned int )
( V_19
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
* V_21
=
( unsigned int )
( V_23
/
( 250000.0
*
( double )
V_16 ) ) ;
V_26
=
( double )
V_23
/
( 250000.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 250000.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) * V_21 + 0.5 ) ) {
* V_21
=
* V_21
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 4 :
V_23
=
( unsigned int )
(
( V_19
*
60 )
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) ( V_19 * 60.0 ) * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
* V_21
=
( unsigned int )
( V_23
/
( 250000.0
*
( double )
V_16 ) )
/
60 ;
V_26
=
(
( double )
V_23
/
( 250000.0
*
( double )
V_16 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_23 / ( 250000.0 * ( double ) V_16 ) ) / 60.0 ) >= ( double ) ( ( double ) * V_21 + 0.5 ) ) {
* V_21
=
* V_21
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
}
F_8 () ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_16
=
V_16 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_17
=
V_17 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_38
=
V_25 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_39
=
* V_20 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_40
=
V_26 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_41
=
* V_21 ;
F_9 ( V_22 , V_27 -> V_28 . V_42 + 0 + ( 20 * V_15 ) + ( 64 * V_14 ) ) ;
F_9 ( V_23 , V_27 -> V_28 . V_42 + 4 + ( 20 * V_15 ) + ( 64 * V_14 ) ) ;
V_24
=
F_10
( V_27 ->
V_28 .
V_42
+
8
+
( 20 * V_15 ) + ( 64 * V_14 ) ) ;
V_24
=
V_24
&
0x7F ;
if ( V_16 == V_33 ) {
V_24
=
V_24
|
0x80 ;
}
F_9 ( V_24 , V_27 -> V_28 . V_42 + 8 + ( 20 * V_15 ) + ( 64 * V_14 ) ) ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_43
=
1 ;
} else {
F_11 ( L_2 ) ;
V_9
=
- 9 ;
}
} else {
F_11 ( L_3 ) ;
V_9 =
- 8 ;
}
} else {
F_11 ( L_4 ) ;
V_9 = - 7 ;
}
}
else {
F_11 ( L_5 ) ;
V_9 = - 6 ;
}
}
else {
F_11 ( L_6 ) ;
V_9 = - 5 ;
}
}
else {
F_11 ( L_7 ) ;
V_9 = - 4 ;
}
} else {
F_11 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_11 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_5 ( struct V_1 * V_2 ,
unsigned char V_14 ,
unsigned char V_15 ,
unsigned char * V_44 ,
unsigned int * V_45 ,
unsigned int * V_46 ,
unsigned char * V_47 ,
unsigned char * V_48 ,
unsigned char * V_49 ,
unsigned char * V_50 , unsigned char * V_51 , unsigned char * V_52 )
{
int V_9 = 0 ;
unsigned int V_53 ;
unsigned int V_24 ;
if ( V_14 < 4 ) {
if ( ( V_27 -> V_28 .
V_29 [ V_14 ] &
0xFFFF0000UL ) == V_30 ) {
if ( V_15 <= 1 ) {
V_53 = F_10 ( V_27 -> V_28 .
V_42 + 12 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
if ( V_53 & 0x10 ) {
* V_45 =
F_10 ( V_27 -> V_28 .
V_42 + 0 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
* V_46 =
F_10 ( V_27 -> V_28 .
V_42 + 4 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
V_24 = F_10 ( V_27 -> V_28 .
V_42 + 8 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
* V_47 =
( unsigned char ) ( ( V_24 >> 5 ) & 1 ) ;
* V_48 =
( unsigned char ) ( ( V_24 >> 0 ) & 1 ) ;
* V_49 =
( unsigned char ) ( ( V_24 >> 1 ) & 1 ) ;
* V_50 =
( unsigned char ) ( ( V_24 >> 4 ) & 1 ) ;
* V_51 =
( unsigned char ) ( ( V_24 >> 3 ) & 1 ) ;
if ( * V_49 ) {
* V_49 =
* V_49 +
( unsigned char ) ( ( V_24 >>
2 ) & 1 ) ;
}
V_24 = F_10 ( V_27 -> V_28 .
V_42 + 8 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
* V_52 =
( unsigned char ) ( ( V_24 >> 0 ) & 1 ) ;
* V_44 = V_27 ->
V_35 [ V_14 ] .
V_36 .
V_37 [ V_15 ] . V_17 ;
}
else {
F_11 ( L_10 ) ;
V_9 = - 5 ;
}
}
else {
F_11 ( L_7 ) ;
V_9 = - 4 ;
}
} else {
F_11 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_11 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned char V_54 ;
int V_9 = 0 ;
V_54 = F_2 ( V_6 -> V_10 ) ;
switch ( V_54 ) {
case V_55 :
V_9 = F_13 ( V_2 ,
( unsigned char ) F_4 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] ,
( unsigned char ) V_7 [ 1 ] ,
( unsigned char ) V_7 [ 2 ] ,
( unsigned char ) V_7 [ 3 ] , ( unsigned char ) V_7 [ 4 ] , ( unsigned char ) V_7 [ 5 ] ) ;
break;
case V_56 :
V_9 = F_14 ( V_2 ,
( unsigned char ) F_4 ( V_6 -> V_10 ) , ( unsigned char ) V_7 [ 0 ] ) ;
break;
case V_57 :
V_9 = F_15 ( V_2 ,
( unsigned char ) F_4 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] ,
( unsigned char ) V_7 [ 1 ] , ( unsigned int ) V_7 [ 2 ] , ( unsigned int ) V_7 [ 3 ] ) ;
break;
default:
F_6 ( L_11 ) ;
}
if ( V_9 >= 0 )
V_9 = V_6 -> V_13 ;
return V_9 ;
}
int F_13 ( struct V_1 * V_2 ,
unsigned char V_14 ,
unsigned char V_15 ,
unsigned char V_58 ,
unsigned char V_59 ,
unsigned char V_60 , unsigned char V_61 , unsigned char V_62 )
{
int V_9 = 0 ;
unsigned int V_53 ;
unsigned int V_24 ;
V_27 -> V_63 = V_64 ;
if ( V_14 < 4 ) {
if ( ( V_27 -> V_28 .
V_29 [ V_14 ] &
0xFFFF0000UL ) == V_30 ) {
if ( V_15 <= 1 ) {
V_53 = F_10 ( V_27 -> V_28 .
V_42 + 12 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
if ( V_53 & 0x10 ) {
if ( V_58 <= 1 ) {
if ( V_59 <= 1 ) {
if ( V_60 <= 2 ) {
if ( V_61
<= 1 ) {
if ( V_62 == V_65 || V_62 == V_66 ) {
V_24
=
F_10
( V_27 ->
V_28 .
V_42
+
8
+
( 20 * V_15 ) + ( 64 * V_14 ) ) ;
V_24
=
V_24
&
0x80 ;
V_24
=
V_24
|
V_59
|
( V_62
<<
3 )
|
( V_61
<<
4 )
|
( V_58
<<
5 ) ;
if ( V_60 & 3 ) {
V_24
=
V_24
|
2 ;
if ( V_60 & 2 ) {
V_24
=
V_24
|
4 ;
}
}
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_62
=
V_62 ;
F_9 ( V_24 , V_27 -> V_28 . V_42 + 8 + ( 20 * V_15 ) + ( 64 * V_14 ) ) ;
F_9 ( 1 , V_27 -> V_28 . V_42 + 12 + ( 20 * V_15 ) + ( 64 * V_14 ) ) ;
}
else {
F_11 ( L_12 ) ;
V_9
=
- 10 ;
}
}
else {
F_11 ( L_13 ) ;
V_9
=
- 9 ;
}
}
else {
F_11 ( L_14 ) ;
V_9 =
- 8 ;
}
}
else {
F_11 ( L_15 ) ;
V_9 = - 7 ;
}
}
else {
F_11 ( L_16 ) ;
V_9 = - 6 ;
}
}
else {
F_11 ( L_10 ) ;
V_9 = - 5 ;
}
}
else {
F_11 ( L_7 ) ;
V_9 = - 4 ;
}
} else {
F_11 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_11 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_14 ( struct V_1 * V_2 , unsigned char V_14 , unsigned char V_15 )
{
int V_9 = 0 ;
unsigned int V_53 ;
if ( V_14 < 4 ) {
if ( ( V_27 -> V_28 .
V_29 [ V_14 ] &
0xFFFF0000UL ) == V_30 ) {
if ( V_15 <= 1 ) {
V_53 = F_10 ( V_27 -> V_28 .
V_42 + 12 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
if ( V_53 & 0x10 ) {
if ( V_53 & 0x1 ) {
F_9 ( 0 , V_27 -> V_28 .
V_42 + 12 +
( 20 * V_15 ) +
( 64 * V_14 ) ) ;
}
else {
F_11 ( L_17 ) ;
V_9 = - 6 ;
}
}
else {
F_11 ( L_18 ) ;
V_9 = - 5 ;
}
}
else {
F_11 ( L_7 ) ;
V_9 = - 4 ;
}
} else {
F_11 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_11 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_15 ( struct V_1 * V_2 ,
unsigned char V_14 ,
unsigned char V_15 , unsigned char V_17 , unsigned int V_18 , unsigned int V_19 )
{
unsigned char V_16 ;
int V_9 = 0 ;
unsigned int V_22 = 0 ;
unsigned int V_23 = 0 ;
unsigned int V_39 = 0 ;
unsigned int V_41 = 0 ;
unsigned int V_53 ;
unsigned int V_24 ;
double V_25 = 0 ;
double V_26 = 0 ;
if ( V_14 < 4 ) {
if ( ( V_27 -> V_28 .
V_29 [ V_14 ] &
0xFFFF0000UL ) == V_30 ) {
if ( V_15 <= 1 ) {
V_53 = F_10 ( V_27 -> V_28 .
V_42 + 12 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
if ( V_53 & 0x10 ) {
V_16 = V_27 ->
V_35 [ V_14 ] .
V_36 .
V_16 ;
if ( V_17 <= 4 ) {
if ( ( ( V_16 ==
V_31 )
&& ( V_17
== 0 )
&& ( V_18
>= 266 )
&& ( V_18
<=
0xFFFFFFFFUL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 1 )
&& ( V_18
>= 1 )
&& ( V_18
<=
571230650UL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 2 )
&& ( V_18
>= 1 )
&& ( V_18
<=
571230UL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 3 )
&& ( V_18
>= 1 )
&& ( V_18
<=
571UL ) )
|| ( ( V_16 ==
V_31 )
&& ( V_17
== 4 )
&& ( V_18
>= 1 )
&& ( V_18
<= 9UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 0 )
&& ( V_18
>= 242 )
&& ( V_18
<=
0xFFFFFFFFUL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 1 )
&& ( V_18
>= 1 )
&& ( V_18
<=
519691043UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 2 )
&& ( V_18
>= 1 )
&& ( V_18
<=
519691UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 3 )
&& ( V_18
>= 1 )
&& ( V_18
<=
520UL ) )
|| ( ( V_16 ==
V_32 )
&& ( V_17
== 4 )
&& ( V_18
>= 1 )
&& ( V_18
<= 8UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 0 )
&& ( V_18
>= 200 )
&& ( V_18
<=
0xFFFFFFFFUL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 1 )
&& ( V_18
>= 1 )
&& ( V_18
<=
429496729UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 2 )
&& ( V_18
>= 1 )
&& ( V_18
<=
429496UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 3 )
&& ( V_18
>= 1 )
&& ( V_18
<=
429UL ) )
|| ( ( V_16 ==
V_33 )
&& ( V_17
== 4 )
&& ( V_18
>= 1 )
&& ( V_18
<=
7UL ) ) ) {
if ( ( ( V_16 == V_31 ) && ( V_17 == 0 ) && ( V_19 >= 266 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 571230650UL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 571230UL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 571UL ) ) || ( ( V_16 == V_31 ) && ( V_17 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 9UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 0 ) && ( V_19 >= 242 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 519691043UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 519691UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 520UL ) ) || ( ( V_16 == V_32 ) && ( V_17 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 8UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 0 ) && ( V_19 >= 200 ) && ( V_19 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 1 ) && ( V_19 >= 1 ) && ( V_19 <= 429496729UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 2 ) && ( V_19 >= 1 ) && ( V_19 <= 429496UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 3 ) && ( V_19 >= 1 ) && ( V_19 <= 429UL ) ) || ( ( V_16 == V_33 ) && ( V_17 == 4 ) && ( V_19 >= 1 ) && ( V_19 <= 7UL ) ) ) {
F_7 () ;
switch ( V_17 ) {
case 0 :
V_22
=
( unsigned int )
( V_18
*
( 0.00025 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_18 * ( 0.00025 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
V_39
=
( unsigned int )
( V_22
/
( 0.00025 * ( double ) V_16 ) ) ;
V_25
=
( double )
V_22
/
( 0.00025
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 0.00025 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_39 + 0.5 ) ) {
V_39
=
V_39
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 1 :
V_22
=
( unsigned int )
( V_18
*
( 0.25 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_18 * ( 0.25 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
V_39
=
( unsigned int )
( V_22
/
( 0.25 * ( double ) V_16 ) ) ;
V_25
=
( double )
V_22
/
(
( double )
0.25
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 0.25 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_39 + 0.5 ) ) {
V_39
=
V_39
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 2 :
V_22
=
V_18
*
( 250.0
*
V_16 ) ;
if ( ( double ) ( ( double ) V_18 * ( 250.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
V_39
=
( unsigned int )
( V_22
/
( 250.0 * ( double ) V_16 ) ) ;
V_25
=
( double )
V_22
/
( 250.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 250.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_39 + 0.5 ) ) {
V_39
=
V_39
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 3 :
V_22
=
( unsigned int )
( V_18
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) V_18 * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
V_39
=
( unsigned int )
( V_22
/
( 250000.0
*
( double )
V_16 ) ) ;
V_25
=
( double )
V_22
/
( 250000.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_22 / ( 250000.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_39 + 0.5 ) ) {
V_39
=
V_39
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
case 4 :
V_22
=
( unsigned int )
(
( V_18
*
60 )
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) ( V_18 * 60.0 ) * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_22 + 0.5 ) ) ) {
V_22
=
V_22
+
1 ;
}
V_39
=
( unsigned int )
( V_22
/
( 250000.0
*
( double )
V_16 ) )
/
60 ;
V_25
=
(
( double )
V_22
/
( 250000.0
*
( double )
V_16 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_22 / ( 250000.0 * ( double ) V_16 ) ) / 60.0 ) >= ( double ) ( ( double ) V_39 + 0.5 ) ) {
V_39
=
V_39
+
1 ;
}
V_18
=
V_18
-
1 ;
V_22
=
V_22
-
2 ;
if ( V_16 != V_33 ) {
V_22
=
( unsigned int )
(
( double )
( V_22 )
*
1.007752288 ) ;
}
break;
}
switch ( V_17 ) {
case 0 :
V_23
=
( unsigned int )
( V_19
*
( 0.00025 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 0.00025 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
V_41
=
( unsigned int )
( V_23
/
( 0.00025 * ( double ) V_16 ) ) ;
V_26
=
( double )
V_23
/
( 0.00025
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 0.00025 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_41 + 0.5 ) ) {
V_41
=
V_41
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 1 :
V_23
=
( unsigned int )
( V_19
*
( 0.25 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 0.25 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
V_41
=
( unsigned int )
( V_23
/
( 0.25 * ( double ) V_16 ) ) ;
V_26
=
( double )
V_23
/
(
( double )
0.25
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 0.25 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_41 + 0.5 ) ) {
V_41
=
V_41
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 2 :
V_23
=
V_19
*
( 250.0
*
V_16 ) ;
if ( ( double ) ( ( double ) V_19 * ( 250.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
V_41
=
( unsigned int )
( V_23
/
( 250.0 * ( double ) V_16 ) ) ;
V_26
=
( double )
V_23
/
( 250.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 250.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_41 + 0.5 ) ) {
V_41
=
V_41
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 3 :
V_23
=
( unsigned int )
( V_19
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) V_19 * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
V_41
=
( unsigned int )
( V_23
/
( 250000.0
*
( double )
V_16 ) ) ;
V_26
=
( double )
V_23
/
( 250000.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_23 / ( 250000.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_41 + 0.5 ) ) {
V_41
=
V_41
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
case 4 :
V_23
=
( unsigned int )
(
( V_19
*
60 )
*
( 250000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) ( V_19 * 60.0 ) * ( 250000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_23 + 0.5 ) ) ) {
V_23
=
V_23
+
1 ;
}
V_41
=
( unsigned int )
( V_23
/
( 250000.0
*
( double )
V_16 ) )
/
60 ;
V_26
=
(
( double )
V_23
/
( 250000.0
*
( double )
V_16 ) )
/
60.0 ;
if ( ( double ) ( ( ( double ) V_23 / ( 250000.0 * ( double ) V_16 ) ) / 60.0 ) >= ( double ) ( ( double ) V_41 + 0.5 ) ) {
V_41
=
V_41
+
1 ;
}
V_19
=
V_19
-
1 ;
V_23
=
V_23
-
2 ;
if ( V_16 != V_33 ) {
V_23
=
( unsigned int )
(
( double )
( V_23 )
*
1.007752288 ) ;
}
break;
}
F_8 () ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_17
=
V_17 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_38
=
V_25 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_39
=
V_39 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_40
=
V_26 ;
V_27 ->
V_35
[ V_14 ] .
V_36 .
V_37
[ V_15 ] .
V_41
=
V_41 ;
F_9 ( V_22 , V_27 -> V_28 . V_42 + 0 + ( 20 * V_15 ) + ( 64 * V_14 ) ) ;
F_9 ( V_23 , V_27 -> V_28 . V_42 + 4 + ( 20 * V_15 ) + ( 64 * V_14 ) ) ;
V_24 =
F_10
( V_27 ->
V_28 .
V_42
+ 8 +
( 20 * V_15 ) + ( 64 * V_14 ) ) ;
V_24 =
V_24
& 0x7F ;
if ( V_16 == V_33 ) {
V_24
=
V_24
|
0x80 ;
}
F_9 ( V_24 ,
V_27 ->
V_28 .
V_42
+ 8 +
( 20 * V_15 ) + ( 64 * V_14 ) ) ;
} else {
F_11 ( L_3 ) ;
V_9 =
- 8 ;
}
} else {
F_11 ( L_4 ) ;
V_9 = - 7 ;
}
}
else {
F_11 ( L_5 ) ;
V_9 = - 6 ;
}
}
else {
F_11 ( L_10 ) ;
V_9 = - 5 ;
}
}
else {
F_11 ( L_7 ) ;
V_9 = - 4 ;
}
} else {
F_11 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_11 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_9 = 0 ;
unsigned int V_53 ;
unsigned char V_14 ;
unsigned char V_15 ;
unsigned char * V_67 ;
unsigned char * V_68 ;
V_9 = V_6 -> V_13 ;
V_14 = ( unsigned char ) F_4 ( V_6 -> V_10 ) ;
V_15 = ( unsigned char ) F_2 ( V_6 -> V_10 ) ;
V_67 = ( unsigned char * ) & V_7 [ 0 ] ;
V_68 = ( unsigned char * ) & V_7 [ 1 ] ;
if ( V_14 < 4 ) {
if ( ( V_27 -> V_28 .
V_29 [ V_14 ] &
0xFFFF0000UL ) == V_30 ) {
if ( V_15 <= 1 ) {
V_53 = F_10 ( V_27 -> V_28 .
V_42 + 12 + ( 20 * V_15 ) +
( 64 * V_14 ) ) ;
if ( V_53 & 0x10 ) {
if ( V_53 & 0x1 ) {
* V_67 =
( unsigned char ) ( ( V_53 >> 7 )
& 1 ) ;
* V_68 =
( unsigned char ) ( ( V_53 >> 6 )
& 1 ) ;
}
else {
F_11 ( L_19 ) ;
V_9 = - 6 ;
}
}
else {
F_11 ( L_10 ) ;
V_9 = - 5 ;
}
}
else {
F_11 ( L_7 ) ;
V_9 = - 4 ;
}
} else {
F_11 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_11 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 0 ] = V_27 -> V_69 .
V_70 [ V_27 ->
V_69 . V_71 ] . V_72 ;
V_7 [ 1 ] = V_27 -> V_69 .
V_70 [ V_27 ->
V_69 . V_71 ] . V_73 ;
V_7 [ 2 ] = V_27 -> V_69 .
V_70 [ V_27 ->
V_69 . V_71 ] . V_74 ;
V_27 ->
V_69 .
V_71 = ( V_27 ->
V_69 . V_71 + 1 ) % V_75 ;
return V_6 -> V_13 ;
}
