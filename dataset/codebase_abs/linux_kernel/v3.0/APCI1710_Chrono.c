int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned int V_9 = 0 ;
unsigned int V_10 = 0 ;
unsigned int V_11 = 0 ;
double V_12 = 0 ;
unsigned int V_13 [ 8 ] =
{ 0x01 , 0x05 , 0x00 , 0x04 , 0x02 , 0x0E , 0x0A , 0x06 } ;
unsigned char V_14 , V_15 , V_16 , V_17 ;
V_14 = F_2 ( V_6 -> V_18 ) ;
V_15 = ( unsigned char ) V_7 [ 0 ] ;
V_16 = ( unsigned char ) V_7 [ 1 ] ;
V_17 = ( unsigned char ) V_7 [ 2 ] ;
V_10 = ( unsigned int ) V_7 [ 3 ] ;
V_8 = V_6 -> V_19 ;
if ( V_14 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_14 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_15 <= 7 ) {
if ( ( V_16 == V_24 ) ||
( V_16 == V_25 ) ||
( V_16 == V_26 ) ) {
if ( V_17 <= 4 ) {
if ( ( ( V_16 == V_24 ) && ( V_17 == 0 ) && ( V_10 >= 66 ) && ( V_10 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_24 ) && ( V_17 == 1 ) && ( V_10 >= 1 ) && ( V_10 <= 143165576UL ) ) || ( ( V_16 == V_24 ) && ( V_17 == 2 ) && ( V_10 >= 1 ) && ( V_10 <= 143165UL ) ) || ( ( V_16 == V_24 ) && ( V_17 == 3 ) && ( V_10 >= 1 ) && ( V_10 <= 143UL ) ) || ( ( V_16 == V_24 ) && ( V_17 == 4 ) && ( V_10 >= 1 ) && ( V_10 <= 2UL ) ) || ( ( V_16 == V_25 ) && ( V_17 == 0 ) && ( V_10 >= 60 ) && ( V_10 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_25 ) && ( V_17 == 1 ) && ( V_10 >= 1 ) && ( V_10 <= 130150240UL ) ) || ( ( V_16 == V_25 ) && ( V_17 == 2 ) && ( V_10 >= 1 ) && ( V_10 <= 130150UL ) ) || ( ( V_16 == V_25 ) && ( V_17 == 3 ) && ( V_10 >= 1 ) && ( V_10 <= 130UL ) ) || ( ( V_16 == V_25 ) && ( V_17 == 4 ) && ( V_10 >= 1 ) && ( V_10 <= 2UL ) ) || ( ( V_16 == V_26 ) && ( V_17 == 0 ) && ( V_10 >= 50 ) && ( V_10 <= 0xFFFFFFFFUL ) ) || ( ( V_16 == V_26 ) && ( V_17 == 1 ) && ( V_10 >= 1 ) && ( V_10 <= 107374182UL ) ) || ( ( V_16 == V_26 ) && ( V_17 == 2 ) && ( V_10 >= 1 ) && ( V_10 <= 107374UL ) ) || ( ( V_16 == V_26 ) && ( V_17 == 3 ) && ( V_10 >= 1 ) && ( V_10 <= 107UL ) ) || ( ( V_16 == V_26 ) && ( V_17 == 4 ) && ( V_10 >= 1 ) && ( V_10 <= 1UL ) ) ) {
if ( ( ( V_16 == V_26 ) && ( V_20 -> V_21 . V_27 > 0 ) ) || ( V_16 != V_26 ) ) {
if ( ( ( V_16 == V_26 ) && ( ( V_20 -> V_21 . V_22 [ V_14 ] & 0xFFFF ) >= 0x3131 ) ) || ( V_16 != V_26 ) ) {
F_3
() ;
switch ( V_17 ) {
case 0 :
V_9
=
( unsigned int )
( V_10
*
( 0.001 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_10 * ( 0.001 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_11
=
( unsigned int )
( V_9
/
( 0.001 * ( double ) V_16 ) ) ;
V_12
=
( double )
V_9
/
( 0.001
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_9 / ( 0.001 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_11 + 0.5 ) ) {
V_11
=
V_11
+
1 ;
}
V_10
=
V_10
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_16 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
0.99392 ) ;
}
break;
case 1 :
V_9
=
( unsigned int )
( V_10
*
( 1.0 * V_16 ) ) ;
if ( ( double ) ( ( double ) V_10 * ( 1.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_11
=
( unsigned int )
( V_9
/
( 1.0 * ( double ) V_16 ) ) ;
V_12
=
( double )
V_9
/
(
( double )
1.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_9 / ( 1.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_11 + 0.5 ) ) {
V_11
=
V_11
+
1 ;
}
V_10
=
V_10
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_16 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
0.99392 ) ;
}
break;
case 2 :
V_9
=
V_10
*
( 1000
*
V_16 ) ;
if ( ( double ) ( ( double ) V_10 * ( 1000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_11
=
( unsigned int )
( V_9
/
( 1000.0 * ( double ) V_16 ) ) ;
V_12
=
( double )
V_9
/
( 1000.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_9 / ( 1000.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_11 + 0.5 ) ) {
V_11
=
V_11
+
1 ;
}
V_10
=
V_10
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_16 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
0.99392 ) ;
}
break;
case 3 :
V_9
=
( unsigned int )
( V_10
*
( 1000000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) V_10 * ( 1000000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_11
=
( unsigned int )
( V_9
/
( 1000000.0
*
( double )
V_16 ) ) ;
V_12
=
( double )
V_9
/
( 1000000.0
*
( double )
V_16 ) ;
if ( ( double ) ( ( double ) V_9 / ( 1000000.0 * ( double ) V_16 ) ) >= ( double ) ( ( double ) V_11 + 0.5 ) ) {
V_11
=
V_11
+
1 ;
}
V_10
=
V_10
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_16 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
0.99392 ) ;
}
break;
case 4 :
V_9
=
( unsigned int )
(
( V_10
*
60 )
*
( 1000000.0
*
V_16 ) ) ;
if ( ( double ) ( ( double ) ( V_10 * 60.0 ) * ( 1000000.0 * ( double ) V_16 ) ) >= ( ( double ) ( ( double ) V_9 + 0.5 ) ) ) {
V_9
=
V_9
+
1 ;
}
V_11
=
( unsigned int )
( V_9
/
( 1000000.0
*
( double )
V_16 ) )
/
60 ;
V_12
=
(
( double )
V_9
/
( 0.001 * ( double ) V_16 ) ) / 60.0 ;
if ( ( double ) ( ( ( double ) V_9 / ( 1000000.0 * ( double ) V_16 ) ) / 60.0 ) >= ( double ) ( ( double ) V_11 + 0.5 ) ) {
V_11
=
V_11
+
1 ;
}
V_10
=
V_10
-
1 ;
V_9
=
V_9
-
2 ;
if ( V_16 != V_26 ) {
V_9
=
( unsigned int )
(
( double )
( V_9 )
*
0.99392 ) ;
}
break;
}
F_4 () ;
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_16
=
V_16 ;
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_17
=
V_17 ;
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_30
=
V_12 ;
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_31
=
V_13
[ V_15 ] ;
if ( V_16 == V_26 ) {
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_31
=
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_31
|
0x80 ;
}
F_5 ( V_20 -> V_28 [ V_14 ] . V_29 . V_31 , V_20 -> V_21 . V_32 + 16 + ( 64 * V_14 ) ) ;
F_5 ( V_9 , V_20 -> V_21 . V_32 + ( 64 * V_14 ) ) ;
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_33
=
1 ;
} else {
F_6 ( L_1 ) ;
V_8
=
- 9 ;
}
} else {
F_6 ( L_2 ) ;
V_8 =
- 8 ;
}
} else {
F_6 ( L_3 ) ;
V_8 = - 7 ;
}
}
else {
F_6 ( L_4 ) ;
V_8 = - 6 ;
}
}
else {
F_6 ( L_5 ) ;
V_8 = - 5 ;
}
}
else {
F_6 ( L_6 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
V_7 [ 0 ] = V_11 ;
return V_8 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned char V_14 , V_34 , V_35 , V_36 ;
V_14 = F_2 ( V_6 -> V_18 ) ;
V_36 = ( unsigned char ) V_7 [ 0 ] ;
V_34 = ( unsigned char ) V_7 [ 1 ] ;
V_35 = ( unsigned char ) V_7 [ 2 ] ;
V_8 = V_6 -> V_19 ;
if ( V_14 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_14 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_20 -> V_28 [ V_14 ] .
V_29 . V_33 == 1 ) {
switch ( V_36 ) {
case V_37 :
if ( ( V_34 == V_38 )
|| ( V_34 ==
V_39 ) ) {
if ( ( V_35 ==
V_37 )
|| ( V_35 ==
V_40 ) )
{
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_41
=
V_35 ;
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_34 =
V_34 ;
V_20 ->
V_28
[ V_14 ] .
V_29 .
V_31 =
( V_20 ->
V_28
[ V_14 ] .
V_29 .
V_31 &
0x8F ) | ( ( 1 &
V_35 )
<< 5 ) | ( ( 1 &
V_34 )
<< 6 ) | 0x10 ;
if ( V_35 ==
V_37 )
{
F_5 ( V_20 ->
V_28
[ V_14 ] .
V_29 .
V_31 ,
V_20 ->
V_21 .
V_32
+ 32 +
( 64 * V_14 ) ) ;
V_20 -> V_42 = V_43 ;
}
F_5 ( V_20 ->
V_28
[ V_14 ] .
V_29 .
V_31 ,
V_20 ->
V_21 .
V_32 +
16 +
( 64 * V_14 ) ) ;
F_5 ( 0 , V_20 ->
V_21 .
V_32 +
36 +
( 64 * V_14 ) ) ;
}
else {
F_6 ( L_9 ) ;
V_8 = - 6 ;
}
}
else {
F_6 ( L_10 ) ;
V_8 = - 5 ;
}
break;
case V_40 :
V_20 -> V_28 [ V_14 ] .
V_29 .
V_41 = 0 ;
V_20 -> V_28 [ V_14 ] .
V_29 .
V_31 =
V_20 ->
V_28 [ V_14 ] .
V_29 .
V_31 & 0x2F ;
F_5 ( V_20 -> V_28 [ V_14 ] .
V_29 . V_31 ,
V_20 -> V_21 .
V_32 + 16 +
( 64 * V_14 ) ) ;
if ( V_20 -> V_28 [ V_14 ] .
V_29 .
V_34 ==
V_39 ) {
F_5 ( 0 , V_20 -> V_21 .
V_32 + 36 +
( 64 * V_14 ) ) ;
}
break;
default:
F_6 ( L_11 ) ;
V_8 = - 8 ;
}
} else {
F_6 ( L_12 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned char V_44 ;
int V_8 = V_6 -> V_19 ;
V_44 = F_9 ( V_6 -> V_18 ) ;
switch ( V_44 ) {
case V_45 :
V_8 = F_10 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_18 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_46 :
V_8 = F_11 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_18 ) ,
( unsigned int ) V_6 -> V_47 [ 0 ] ,
( unsigned char * ) & V_7 [ 0 ] , ( unsigned int * ) & V_7 [ 1 ] ) ;
break;
case V_48 :
V_8 = F_12 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_18 ) ,
( unsigned int ) V_6 -> V_47 [ 0 ] ,
( unsigned int * ) & V_7 [ 0 ] ,
( unsigned char * ) & V_7 [ 1 ] ,
( unsigned char * ) & V_7 [ 2 ] ,
( unsigned int * ) & V_7 [ 3 ] ,
( unsigned int * ) & V_7 [ 4 ] , ( unsigned int * ) & V_7 [ 5 ] ) ;
break;
case V_49 :
F_13 ( L_13 ) ;
V_7 [ 0 ] = V_20 -> V_50 .
V_51 [ V_20 ->
V_50 . V_52 ] . V_53 ;
V_7 [ 1 ] = V_20 -> V_50 .
V_51 [ V_20 ->
V_50 . V_52 ] . V_54 ;
V_7 [ 2 ] = V_20 -> V_50 .
V_51 [ V_20 ->
V_50 . V_52 ] . V_55 ;
V_20 ->
V_50 .
V_52 = ( V_20 ->
V_50 .
V_52 + 1 ) % V_56 ;
break;
default:
F_13 ( L_14 ) ;
}
if ( V_8 >= 0 )
V_8 = V_6 -> V_19 ;
return V_8 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned char V_14 , unsigned char * V_57 )
{
int V_8 = 0 ;
unsigned int V_58 ;
if ( V_14 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_14 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_20 ->
V_28 [ V_14 ] .
V_29 . V_33 == 1 ) {
V_58 = F_14 ( V_20 -> V_21 .
V_32 + 8 + ( 64 * V_14 ) ) ;
if ( ( V_58 & 8 ) == 8 ) {
* V_57 = 3 ;
}
else {
if ( ( V_58 & 2 ) == 2 ) {
* V_57 = 2 ;
}
else {
if ( ( V_58 & 1 ) == 1 ) {
* V_57 = 1 ;
}
else {
* V_57 = 0 ;
}
}
}
} else {
F_6 ( L_12 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned char V_14 ,
unsigned int V_59 , unsigned char * V_57 , unsigned int * V_60 )
{
int V_8 = 0 ;
unsigned int V_58 ;
unsigned int V_61 = 0 ;
if ( V_14 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_14 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_20 ->
V_28 [ V_14 ] .
V_29 . V_33 == 1 ) {
if ( V_59 <= 65535UL ) {
for (; ; ) {
V_58 =
F_14 ( V_20 ->
V_21 .
V_32 + 8 +
( 64 * V_14 ) ) ;
if ( ( V_58 & 8 ) == 8 ) {
* V_57 = 3 ;
if ( V_20 ->
V_28
[ V_14 ] .
V_29 .
V_34 ==
V_39 )
{
F_5 ( 0 , V_20 -> V_21 . V_32 + 36 + ( 64 * V_14 ) ) ;
}
break;
}
else {
if ( ( V_58 & 2 ) ==
2 ) {
* V_57
= 2 ;
if ( V_20 ->
V_28
[ V_14 ] .
V_29 .
V_34
==
V_39 )
{
F_5 ( 0 , V_20 -> V_21 . V_32 + 36 + ( 64 * V_14 ) ) ;
}
break;
}
else {
if ( ( V_58 & 1 ) == 1 ) {
* V_57
=
1 ;
}
else {
* V_57
=
0 ;
}
}
}
if ( V_61 == V_59 ) {
break;
} else {
V_61 =
V_61 + 1 ;
F_15 ( 1000 ) ;
}
}
if ( * V_57 == 2 ) {
* V_60 =
F_14 ( V_20 ->
V_21 .
V_32 + 4 +
( 64 * V_14 ) ) ;
if ( * V_60 != 0 ) {
* V_60 =
* V_60
- 1 ;
}
} else {
if ( ( * V_57 != 3 )
&& ( V_61 ==
V_59 )
&& ( V_59 != 0 ) ) {
* V_57 = 4 ;
}
}
} else {
F_6 ( L_15 ) ;
V_8 = - 5 ;
}
} else {
F_6 ( L_12 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned char V_14 ,
unsigned int V_62 ,
unsigned int * V_63 ,
unsigned char * V_64 ,
unsigned char * V_65 ,
unsigned int * V_66 , unsigned int * V_67 , unsigned int * V_68 )
{
int V_8 = 0 ;
double V_69 ;
double V_70 ;
double V_71 ;
double V_72 ;
double V_73 ;
double V_74 ;
if ( V_14 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_14 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_20 ->
V_28 [ V_14 ] .
V_29 . V_33 == 1 ) {
F_3 () ;
V_69 = ( double ) V_62 * ( double )
V_20 -> V_28 [ V_14 ] .
V_29 . V_30 ;
switch ( V_20 ->
V_28 [ V_14 ] .
V_29 . V_17 ) {
case 0 :
V_69 = V_69 / ( double ) 1000.0 ;
case 1 :
V_69 = V_69 / ( double ) 1000.0 ;
case 2 :
V_69 = V_69 / ( double ) 1000.0 ;
case 3 :
V_69 = V_69 / ( double ) 60.0 ;
case 4 :
V_69 = V_69 / ( double ) 60.0 ;
* V_63 = ( unsigned int ) V_69 ;
V_70 = V_69 - * V_63 ;
V_70 = V_70 * 60 ;
* V_64 = ( unsigned char ) V_70 ;
V_71 = V_70 - * V_64 ;
V_71 = V_71 * 60 ;
* V_65 = ( unsigned char ) V_71 ;
V_72 = V_71 - * V_65 ;
V_72 = V_72 * 1000 ;
* V_66 = ( unsigned int ) V_72 ;
V_73 =
V_72 -
* V_66 ;
V_73 = V_73 * 1000 ;
* V_67 = ( unsigned int ) V_73 ;
V_74 =
V_73 -
* V_67 ;
V_74 = V_74 * 1000 ;
* V_68 = ( unsigned int ) V_74 ;
break;
}
F_4 () ;
} else {
F_6 ( L_12 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned char V_14 , V_75 , V_76 , V_77 ;
unsigned int V_58 ;
unsigned char * V_78 ;
unsigned char * V_79 ;
V_14 = F_2 ( V_6 -> V_18 ) ;
V_8 = V_6 -> V_19 ;
V_77 = ( unsigned char ) V_7 [ 0 ] ;
if ( V_14 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_14 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_20 -> V_28 [ V_14 ] .
V_29 . V_33 == 1 ) {
switch ( V_77 ) {
case V_80 :
V_75 =
( unsigned char ) F_9 ( V_6 -> V_18 ) ;
if ( V_75 <= 2 ) {
F_5 ( 0 , V_20 -> V_21 .
V_32 + 20 +
( V_75 * 4 ) +
( 64 * V_14 ) ) ;
}
else {
F_6 ( L_16 ) ;
V_8 = - 4 ;
}
break;
case V_81 :
V_75 =
( unsigned char ) F_9 ( V_6 -> V_18 ) ;
if ( V_75 <= 2 ) {
F_5 ( 1 , V_20 -> V_21 .
V_32 + 20 +
( V_75 * 4 ) +
( 64 * V_14 ) ) ;
}
else {
F_6 ( L_16 ) ;
V_8 = - 4 ;
}
break;
case V_82 :
V_78 = ( unsigned char * ) & V_7 [ 0 ] ;
V_76 =
( unsigned char ) F_9 ( V_6 -> V_18 ) ;
if ( V_76 <= 2 ) {
V_58 =
F_14 ( V_20 ->
V_21 .
V_32 + 12 +
( 64 * V_14 ) ) ;
* V_78 =
( unsigned char ) ( ( ( V_58 >>
V_76 )
& 1 ) ^ 1 ) ;
}
else {
F_6 ( L_17 ) ;
V_8 = - 4 ;
}
break;
case V_83 :
V_79 = ( unsigned char * ) & V_7 [ 0 ] ;
V_58 =
F_14 ( V_20 -> V_21 .
V_32 + 12 +
( 64 * V_14 ) ) ;
* V_79 =
( unsigned char ) ( ( V_58 & 0x7 ) ^ 7 ) ;
break;
}
} else {
F_6 ( L_12 ) ;
V_8 = - 5 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
