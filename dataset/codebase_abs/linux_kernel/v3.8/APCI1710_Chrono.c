static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_12 = 0 ;
unsigned int V_13 = 0 ;
unsigned int V_14 = 0 ;
double V_15 = 0 ;
unsigned int V_16 [ 8 ] =
{ 0x01 , 0x05 , 0x00 , 0x04 , 0x02 , 0x0E , 0x0A , 0x06 } ;
unsigned char V_17 , V_18 , V_19 , V_20 ;
V_17 = F_2 ( V_6 -> V_21 ) ;
V_18 = ( unsigned char ) V_7 [ 0 ] ;
V_19 = ( unsigned char ) V_7 [ 1 ] ;
V_20 = ( unsigned char ) V_7 [ 2 ] ;
V_13 = ( unsigned int ) V_7 [ 3 ] ;
V_11 = V_6 -> V_22 ;
if ( V_17 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_17 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_18 <= 7 ) {
if ( ( V_19 == V_26 ) ||
( V_19 == V_27 ) ||
( V_19 == V_28 ) ) {
if ( V_20 <= 4 ) {
if ( ( ( V_19 == V_26 ) && ( V_20 == 0 ) && ( V_13 >= 66 ) && ( V_13 <= 0xFFFFFFFFUL ) ) || ( ( V_19 == V_26 ) && ( V_20 == 1 ) && ( V_13 >= 1 ) && ( V_13 <= 143165576UL ) ) || ( ( V_19 == V_26 ) && ( V_20 == 2 ) && ( V_13 >= 1 ) && ( V_13 <= 143165UL ) ) || ( ( V_19 == V_26 ) && ( V_20 == 3 ) && ( V_13 >= 1 ) && ( V_13 <= 143UL ) ) || ( ( V_19 == V_26 ) && ( V_20 == 4 ) && ( V_13 >= 1 ) && ( V_13 <= 2UL ) ) || ( ( V_19 == V_27 ) && ( V_20 == 0 ) && ( V_13 >= 60 ) && ( V_13 <= 0xFFFFFFFFUL ) ) || ( ( V_19 == V_27 ) && ( V_20 == 1 ) && ( V_13 >= 1 ) && ( V_13 <= 130150240UL ) ) || ( ( V_19 == V_27 ) && ( V_20 == 2 ) && ( V_13 >= 1 ) && ( V_13 <= 130150UL ) ) || ( ( V_19 == V_27 ) && ( V_20 == 3 ) && ( V_13 >= 1 ) && ( V_13 <= 130UL ) ) || ( ( V_19 == V_27 ) && ( V_20 == 4 ) && ( V_13 >= 1 ) && ( V_13 <= 2UL ) ) || ( ( V_19 == V_28 ) && ( V_20 == 0 ) && ( V_13 >= 50 ) && ( V_13 <= 0xFFFFFFFFUL ) ) || ( ( V_19 == V_28 ) && ( V_20 == 1 ) && ( V_13 >= 1 ) && ( V_13 <= 107374182UL ) ) || ( ( V_19 == V_28 ) && ( V_20 == 2 ) && ( V_13 >= 1 ) && ( V_13 <= 107374UL ) ) || ( ( V_19 == V_28 ) && ( V_20 == 3 ) && ( V_13 >= 1 ) && ( V_13 <= 107UL ) ) || ( ( V_19 == V_28 ) && ( V_20 == 4 ) && ( V_13 >= 1 ) && ( V_13 <= 1UL ) ) ) {
if ( ( ( V_19 == V_28 ) && ( V_9 -> V_23 . V_29 > 0 ) ) || ( V_19 != V_28 ) ) {
if ( ( ( V_19 == V_28 ) && ( ( V_9 -> V_23 . V_24 [ V_17 ] & 0xFFFF ) >= 0x3131 ) ) || ( V_19 != V_28 ) ) {
F_3
() ;
switch ( V_20 ) {
case 0 :
V_12
=
( unsigned int )
( V_13
*
( 0.001 * V_19 ) ) ;
if ( ( double ) ( ( double ) V_13 * ( 0.001 * ( double ) V_19 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_14
=
( unsigned int )
( V_12
/
( 0.001 * ( double ) V_19 ) ) ;
V_15
=
( double )
V_12
/
( 0.001
*
( double )
V_19 ) ;
if ( ( double ) ( ( double ) V_12 / ( 0.001 * ( double ) V_19 ) ) >= ( double ) ( ( double ) V_14 + 0.5 ) ) {
V_14
=
V_14
+
1 ;
}
V_13
=
V_13
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_19 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
0.99392 ) ;
}
break;
case 1 :
V_12
=
( unsigned int )
( V_13
*
( 1.0 * V_19 ) ) ;
if ( ( double ) ( ( double ) V_13 * ( 1.0 * ( double ) V_19 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_14
=
( unsigned int )
( V_12
/
( 1.0 * ( double ) V_19 ) ) ;
V_15
=
( double )
V_12
/
(
( double )
1.0
*
( double )
V_19 ) ;
if ( ( double ) ( ( double ) V_12 / ( 1.0 * ( double ) V_19 ) ) >= ( double ) ( ( double ) V_14 + 0.5 ) ) {
V_14
=
V_14
+
1 ;
}
V_13
=
V_13
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_19 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
0.99392 ) ;
}
break;
case 2 :
V_12
=
V_13
*
( 1000
*
V_19 ) ;
if ( ( double ) ( ( double ) V_13 * ( 1000.0 * ( double ) V_19 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_14
=
( unsigned int )
( V_12
/
( 1000.0 * ( double ) V_19 ) ) ;
V_15
=
( double )
V_12
/
( 1000.0
*
( double )
V_19 ) ;
if ( ( double ) ( ( double ) V_12 / ( 1000.0 * ( double ) V_19 ) ) >= ( double ) ( ( double ) V_14 + 0.5 ) ) {
V_14
=
V_14
+
1 ;
}
V_13
=
V_13
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_19 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
0.99392 ) ;
}
break;
case 3 :
V_12
=
( unsigned int )
( V_13
*
( 1000000.0
*
V_19 ) ) ;
if ( ( double ) ( ( double ) V_13 * ( 1000000.0 * ( double ) V_19 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_14
=
( unsigned int )
( V_12
/
( 1000000.0
*
( double )
V_19 ) ) ;
V_15
=
( double )
V_12
/
( 1000000.0
*
( double )
V_19 ) ;
if ( ( double ) ( ( double ) V_12 / ( 1000000.0 * ( double ) V_19 ) ) >= ( double ) ( ( double ) V_14 + 0.5 ) ) {
V_14
=
V_14
+
1 ;
}
V_13
=
V_13
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_19 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
0.99392 ) ;
}
break;
case 4 :
V_12
=
( unsigned int )
(
( V_13
*
60 )
*
( 1000000.0
*
V_19 ) ) ;
if ( ( double ) ( ( double ) ( V_13 * 60.0 ) * ( 1000000.0 * ( double ) V_19 ) ) >= ( ( double ) ( ( double ) V_12 + 0.5 ) ) ) {
V_12
=
V_12
+
1 ;
}
V_14
=
( unsigned int )
( V_12
/
( 1000000.0
*
( double )
V_19 ) )
/
60 ;
V_15
=
(
( double )
V_12
/
( 0.001 * ( double ) V_19 ) ) / 60.0 ;
if ( ( double ) ( ( ( double ) V_12 / ( 1000000.0 * ( double ) V_19 ) ) / 60.0 ) >= ( double ) ( ( double ) V_14 + 0.5 ) ) {
V_14
=
V_14
+
1 ;
}
V_13
=
V_13
-
1 ;
V_12
=
V_12
-
2 ;
if ( V_19 != V_28 ) {
V_12
=
( unsigned int )
(
( double )
( V_12 )
*
0.99392 ) ;
}
break;
}
F_4 () ;
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_19
=
V_19 ;
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_20
=
V_20 ;
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_32
=
V_15 ;
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_33
=
V_16
[ V_18 ] ;
if ( V_19 == V_28 ) {
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_33
=
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_33
|
0x80 ;
}
F_5 ( V_9 -> V_30 [ V_17 ] . V_31 . V_33 , V_9 -> V_23 . V_34 + 16 + ( 64 * V_17 ) ) ;
F_5 ( V_12 , V_9 -> V_23 . V_34 + ( 64 * V_17 ) ) ;
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_35
=
1 ;
} else {
F_6 ( L_1 ) ;
V_11
=
- 9 ;
}
} else {
F_6 ( L_2 ) ;
V_11 =
- 8 ;
}
} else {
F_6 ( L_3 ) ;
V_11 = - 7 ;
}
}
else {
F_6 ( L_4 ) ;
V_11 = - 6 ;
}
}
else {
F_6 ( L_5 ) ;
V_11 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
V_7 [ 0 ] = V_14 ;
return V_11 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned char V_17 , V_36 , V_37 , V_38 ;
V_17 = F_2 ( V_6 -> V_21 ) ;
V_38 = ( unsigned char ) V_7 [ 0 ] ;
V_36 = ( unsigned char ) V_7 [ 1 ] ;
V_37 = ( unsigned char ) V_7 [ 2 ] ;
V_11 = V_6 -> V_22 ;
if ( V_17 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_17 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_9 -> V_30 [ V_17 ] .
V_31 . V_35 == 1 ) {
switch ( V_38 ) {
case V_39 :
if ( ( V_36 == V_40 )
|| ( V_36 ==
V_41 ) ) {
if ( ( V_37 ==
V_39 )
|| ( V_37 ==
V_42 ) )
{
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_43
=
V_37 ;
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_36 =
V_36 ;
V_9 ->
V_30
[ V_17 ] .
V_31 .
V_33 =
( V_9 ->
V_30
[ V_17 ] .
V_31 .
V_33 &
0x8F ) | ( ( 1 &
V_37 )
<< 5 ) | ( ( 1 &
V_36 )
<< 6 ) | 0x10 ;
if ( V_37 ==
V_39 )
{
F_5 ( V_9 ->
V_30
[ V_17 ] .
V_31 .
V_33 ,
V_9 ->
V_23 .
V_34
+ 32 +
( 64 * V_17 ) ) ;
V_9 -> V_44 = V_45 ;
}
F_5 ( V_9 ->
V_30
[ V_17 ] .
V_31 .
V_33 ,
V_9 ->
V_23 .
V_34 +
16 +
( 64 * V_17 ) ) ;
F_5 ( 0 , V_9 ->
V_23 .
V_34 +
36 +
( 64 * V_17 ) ) ;
}
else {
F_6 ( L_9 ) ;
V_11 = - 6 ;
}
}
else {
F_6 ( L_10 ) ;
V_11 = - 5 ;
}
break;
case V_42 :
V_9 -> V_30 [ V_17 ] .
V_31 .
V_43 = 0 ;
V_9 -> V_30 [ V_17 ] .
V_31 .
V_33 =
V_9 ->
V_30 [ V_17 ] .
V_31 .
V_33 & 0x2F ;
F_5 ( V_9 -> V_30 [ V_17 ] .
V_31 . V_33 ,
V_9 -> V_23 .
V_34 + 16 +
( 64 * V_17 ) ) ;
if ( V_9 -> V_30 [ V_17 ] .
V_31 .
V_36 ==
V_41 ) {
F_5 ( 0 , V_9 -> V_23 .
V_34 + 36 +
( 64 * V_17 ) ) ;
}
break;
default:
F_6 ( L_11 ) ;
V_11 = - 8 ;
}
} else {
F_6 ( L_12 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned char V_17 ,
unsigned char * V_46 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_47 ;
if ( V_17 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_17 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_9 ->
V_30 [ V_17 ] .
V_31 . V_35 == 1 ) {
V_47 = F_9 ( V_9 -> V_23 .
V_34 + 8 + ( 64 * V_17 ) ) ;
if ( ( V_47 & 8 ) == 8 ) {
* V_46 = 3 ;
}
else {
if ( ( V_47 & 2 ) == 2 ) {
* V_46 = 2 ;
}
else {
if ( ( V_47 & 1 ) == 1 ) {
* V_46 = 1 ;
}
else {
* V_46 = 0 ;
}
}
}
} else {
F_6 ( L_12 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned char V_17 ,
unsigned int V_48 ,
unsigned char * V_46 ,
unsigned int * V_49 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_47 ;
unsigned int V_50 = 0 ;
if ( V_17 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_17 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_9 ->
V_30 [ V_17 ] .
V_31 . V_35 == 1 ) {
if ( V_48 <= 65535UL ) {
for (; ; ) {
V_47 =
F_9 ( V_9 ->
V_23 .
V_34 + 8 +
( 64 * V_17 ) ) ;
if ( ( V_47 & 8 ) == 8 ) {
* V_46 = 3 ;
if ( V_9 ->
V_30
[ V_17 ] .
V_31 .
V_36 ==
V_41 )
{
F_5 ( 0 , V_9 -> V_23 . V_34 + 36 + ( 64 * V_17 ) ) ;
}
break;
}
else {
if ( ( V_47 & 2 ) ==
2 ) {
* V_46
= 2 ;
if ( V_9 ->
V_30
[ V_17 ] .
V_31 .
V_36
==
V_41 )
{
F_5 ( 0 , V_9 -> V_23 . V_34 + 36 + ( 64 * V_17 ) ) ;
}
break;
}
else {
if ( ( V_47 & 1 ) == 1 ) {
* V_46
=
1 ;
}
else {
* V_46
=
0 ;
}
}
}
if ( V_50 == V_48 ) {
break;
} else {
V_50 =
V_50 + 1 ;
F_11 ( 1000 ) ;
}
}
if ( * V_46 == 2 ) {
* V_49 =
F_9 ( V_9 ->
V_23 .
V_34 + 4 +
( 64 * V_17 ) ) ;
if ( * V_49 != 0 ) {
* V_49 =
* V_49
- 1 ;
}
} else {
if ( ( * V_46 != 3 )
&& ( V_50 ==
V_48 )
&& ( V_48 != 0 ) ) {
* V_46 = 4 ;
}
}
} else {
F_6 ( L_13 ) ;
V_11 = - 5 ;
}
} else {
F_6 ( L_12 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned char V_17 ,
unsigned int V_51 ,
unsigned int * V_52 ,
unsigned char * V_53 ,
unsigned char * V_54 ,
unsigned int * V_55 ,
unsigned int * V_56 ,
unsigned int * V_57 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
double V_58 ;
double V_59 ;
double V_60 ;
double V_61 ;
double V_62 ;
double V_63 ;
if ( V_17 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_17 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_9 ->
V_30 [ V_17 ] .
V_31 . V_35 == 1 ) {
F_3 () ;
V_58 = ( double ) V_51 * ( double )
V_9 -> V_30 [ V_17 ] .
V_31 . V_32 ;
switch ( V_9 ->
V_30 [ V_17 ] .
V_31 . V_20 ) {
case 0 :
V_58 = V_58 / ( double ) 1000.0 ;
case 1 :
V_58 = V_58 / ( double ) 1000.0 ;
case 2 :
V_58 = V_58 / ( double ) 1000.0 ;
case 3 :
V_58 = V_58 / ( double ) 60.0 ;
case 4 :
V_58 = V_58 / ( double ) 60.0 ;
* V_52 = ( unsigned int ) V_58 ;
V_59 = V_58 - * V_52 ;
V_59 = V_59 * 60 ;
* V_53 = ( unsigned char ) V_59 ;
V_60 = V_59 - * V_53 ;
V_60 = V_60 * 60 ;
* V_54 = ( unsigned char ) V_60 ;
V_61 = V_60 - * V_54 ;
V_61 = V_61 * 1000 ;
* V_55 = ( unsigned int ) V_61 ;
V_62 =
V_61 -
* V_55 ;
V_62 = V_62 * 1000 ;
* V_56 = ( unsigned int ) V_62 ;
V_63 =
V_62 -
* V_56 ;
V_63 = V_63 * 1000 ;
* V_57 = ( unsigned int ) V_63 ;
break;
}
F_4 () ;
} else {
F_6 ( L_12 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned char V_64 ;
int V_11 = V_6 -> V_22 ;
V_64 = F_14 ( V_6 -> V_21 ) ;
switch ( V_64 ) {
case V_65 :
V_11 = F_8 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_21 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_66 :
V_11 = F_10 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_21 ) ,
( unsigned int ) V_6 -> V_67 [ 0 ] ,
( unsigned char * ) & V_7 [ 0 ] , ( unsigned int * ) & V_7 [ 1 ] ) ;
break;
case V_68 :
V_11 = F_12 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_21 ) ,
( unsigned int ) V_6 -> V_67 [ 0 ] ,
( unsigned int * ) & V_7 [ 0 ] ,
( unsigned char * ) & V_7 [ 1 ] ,
( unsigned char * ) & V_7 [ 2 ] ,
( unsigned int * ) & V_7 [ 3 ] ,
( unsigned int * ) & V_7 [ 4 ] , ( unsigned int * ) & V_7 [ 5 ] ) ;
break;
case V_69 :
F_15 ( L_14 ) ;
V_7 [ 0 ] = V_9 -> V_70 .
V_71 [ V_9 ->
V_70 . V_72 ] . V_73 ;
V_7 [ 1 ] = V_9 -> V_70 .
V_71 [ V_9 ->
V_70 . V_72 ] . V_74 ;
V_7 [ 2 ] = V_9 -> V_70 .
V_71 [ V_9 ->
V_70 . V_72 ] . V_75 ;
V_9 ->
V_70 .
V_72 = ( V_9 ->
V_70 .
V_72 + 1 ) % V_76 ;
break;
default:
F_15 ( L_15 ) ;
}
if ( V_11 >= 0 )
V_11 = V_6 -> V_22 ;
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned char V_17 , V_77 , V_78 , V_79 ;
unsigned int V_47 ;
unsigned char * V_80 ;
unsigned char * V_81 ;
V_17 = F_2 ( V_6 -> V_21 ) ;
V_11 = V_6 -> V_22 ;
V_79 = ( unsigned char ) V_7 [ 0 ] ;
if ( V_17 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_17 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_9 -> V_30 [ V_17 ] .
V_31 . V_35 == 1 ) {
switch ( V_79 ) {
case V_82 :
V_77 =
( unsigned char ) F_14 ( V_6 -> V_21 ) ;
if ( V_77 <= 2 ) {
F_5 ( 0 , V_9 -> V_23 .
V_34 + 20 +
( V_77 * 4 ) +
( 64 * V_17 ) ) ;
}
else {
F_6 ( L_16 ) ;
V_11 = - 4 ;
}
break;
case V_83 :
V_77 =
( unsigned char ) F_14 ( V_6 -> V_21 ) ;
if ( V_77 <= 2 ) {
F_5 ( 1 , V_9 -> V_23 .
V_34 + 20 +
( V_77 * 4 ) +
( 64 * V_17 ) ) ;
}
else {
F_6 ( L_16 ) ;
V_11 = - 4 ;
}
break;
case V_84 :
V_80 = ( unsigned char * ) & V_7 [ 0 ] ;
V_78 =
( unsigned char ) F_14 ( V_6 -> V_21 ) ;
if ( V_78 <= 2 ) {
V_47 =
F_9 ( V_9 ->
V_23 .
V_34 + 12 +
( 64 * V_17 ) ) ;
* V_80 =
( unsigned char ) ( ( ( V_47 >>
V_78 )
& 1 ) ^ 1 ) ;
}
else {
F_6 ( L_17 ) ;
V_11 = - 4 ;
}
break;
case V_85 :
V_81 = ( unsigned char * ) & V_7 [ 0 ] ;
V_47 =
F_9 ( V_9 -> V_23 .
V_34 + 12 +
( 64 * V_17 ) ) ;
* V_81 =
( unsigned char ) ( ( V_47 & 0x7 ) ^ 7 ) ;
break;
}
} else {
F_6 ( L_12 ) ;
V_11 = - 5 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
