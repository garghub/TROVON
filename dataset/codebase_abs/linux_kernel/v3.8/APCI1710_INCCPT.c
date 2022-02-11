static int F_1 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_4 ,
unsigned char V_5 ,
unsigned char V_6 ,
unsigned char V_7 ,
unsigned char V_8 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( ( V_10 -> V_13 .
V_14 [ V_3 ] & 0xFFFF0000UL ) ==
V_15 ) {
if ( V_4 == V_16
|| V_4 == V_17 ) {
if ( V_5 == V_18 ||
V_5 == V_19 ||
V_5 == V_20 ||
V_5 == V_21 ) {
if ( ( V_5 == V_21
&& ( V_6 ==
V_22
|| V_6
== V_23 ) )
|| ( V_5 !=
V_21
&& ( V_6 ==
V_24
|| V_6
==
V_25 ) ) )
{
if ( V_4 ==
V_16 ) {
if ( ( V_5 !=
V_21
&&
( V_7
==
V_18
||
V_7
==
V_19
||
V_7
==
V_20 ) )
|| ( V_5
==
V_21
&&
V_7
==
V_21 ) )
{
if ( ( V_7 == V_21 && ( V_8 == V_22 || V_8 == V_23 ) ) || ( V_7 != V_21 && ( V_8 == V_24 || V_8 == V_25 ) ) ) {
V_12 =
0 ;
} else {
F_2 ( L_1 ) ;
V_12 =
- 7 ;
}
} else {
F_2 ( L_2 ) ;
V_12 = - 6 ;
}
}
} else {
F_2 ( L_3 ) ;
V_12 = - 5 ;
}
} else {
F_2 ( L_4 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_5 ) ;
V_12 = - 3 ;
}
if ( V_12 == 0 ) {
if ( V_4 == V_17 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_30 = V_4 |
V_5 |
V_6 ;
} else {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_30 = V_4 |
( V_5 & 0x5 ) |
( V_6 & 0x20 ) |
( V_7 & 0xA ) |
( V_8 & 0x40 ) ;
if ( V_5 == V_21 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_30 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_30 |
V_21 ;
}
}
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 .
V_32 + 20 + ( 64 * V_3 ) ) ;
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_34 = 1 ;
}
} else {
F_2 ( L_6 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned char * V_35 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned char V_36 = 0 ;
int V_12 = 0 ;
unsigned int V_37 ;
* V_35 = 0 ;
if ( ( V_10 -> V_13 .
V_14 [ 0 ] & 0xFFFF0000UL ) ==
V_15
|| ( V_10 -> V_13 .
V_14 [ 1 ] & 0xFFFF0000UL ) ==
V_15
|| ( V_10 -> V_13 .
V_14 [ 2 ] & 0xFFFF0000UL ) ==
V_15
|| ( V_10 -> V_13 .
V_14 [ 3 ] & 0xFFFF0000UL ) ==
V_15 ) {
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
if ( ( V_10 -> V_13 .
V_14 [ V_36 ] &
0xFFFF0000UL ) ==
V_15 ) {
F_3 ( 3 , V_10 -> V_13 .
V_32 + 16 + ( 64 * V_36 ) ) ;
F_3 ( 1 , V_10 -> V_13 .
V_32 + ( 64 * V_36 ) ) ;
V_37 = F_5 ( V_10 -> V_13 .
V_32 + 4 + ( 64 * V_36 ) ) ;
if ( ( V_37 & 0xFF ) !=
( ( V_37 >> 8 ) & 0xFF )
&& ( V_37 & 0xFF ) !=
( ( V_37 >> 16 ) & 0xFF )
&& ( V_37 & 0xFF ) !=
( ( V_37 >> 24 ) & 0xFF ) ) {
* V_35 =
* V_35 | ( 1 <<
V_36 ) ;
}
F_3 ( 0 , V_10 -> V_13 .
V_32 + 16 + ( 64 * V_36 ) ) ;
}
}
} else {
F_2 ( L_7 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_38 ,
unsigned char V_39 ,
unsigned char V_40 ,
unsigned char V_41 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_38 == V_42 ||
V_38 == V_43 ) {
if ( V_39 ==
V_44
|| V_39 ==
V_45
|| V_39 ==
V_46
|| V_39 ==
V_47
|| V_39 ==
V_48
|| V_39 ==
V_49 )
{
if ( V_40 == V_42 ||
V_40 == V_43 )
{
if ( V_41 ==
V_42
|| V_41 ==
V_43 ) {
if ( V_38 ==
V_42 )
{
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
|
V_51 ;
} else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
&
V_52 ;
}
if ( V_39 ==
V_45
||
V_39
==
V_47
||
V_39
==
V_49 )
{
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
|
V_54 ;
} else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
&
V_55 ;
}
if ( V_39 ==
V_48
||
V_39
==
V_49 )
{
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
|
V_56 ;
}
else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
&
V_57 ;
if ( V_39 == V_44 || V_39 == V_45 ) {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
|
V_58 ;
} else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
&
( ~ V_58 ) ;
}
}
if ( V_40 ==
V_43 )
{
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
|
V_59 ;
} else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50
&
( ~ V_59 ) ;
}
if ( V_41 ==
V_42 )
{
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60
|
V_61 ;
} else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60
&
V_62 ;
}
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_33 .
V_63 = 1 ;
} else {
F_2 ( L_8 ) ;
V_12 = - 7 ;
}
} else {
F_2 ( L_9 ) ;
V_12 = - 6 ;
}
} else {
F_2 ( L_10 ) ;
V_12 = - 5 ;
}
} else {
F_2 ( L_11 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_64 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_64 == 0 || V_64 == 1 ) {
if ( V_64 == 1 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 |
V_65 ;
} else {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 &
V_66 ;
}
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 . V_32 + 20 +
( 64 * V_3 ) ) ;
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_67 = 1 ;
} else {
F_2 ( L_14 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_68 ,
unsigned char V_69 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_68 == 0 || V_68 == 1 ) {
if ( ( V_69 == V_70 ) ||
( ( V_69 == V_71
&& ( V_10 ->
V_13 .
V_14
[ V_3 ] &
0xFFFF ) >=
0x3135 ) ) ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53 = ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53 & ( 0xFF -
( 0x10 << V_68 ) ) ) | ( ( V_69 ^ 1 ) << ( 4 + V_68 ) ) ;
} else {
F_2 ( L_15 ) ;
V_12 = - 5 ;
}
}
else {
F_2 ( L_16 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned int V_72 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
F_3 ( V_72 , V_10 -> V_13 .
V_32 + 28 + ( 64 * V_3 ) ) ;
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_73 = 1 ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_74 ,
unsigned char V_75 ,
unsigned int V_76 ,
unsigned int * V_77 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_78 = 0 ;
double V_79 ;
unsigned int V_80 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( ( V_74 == V_81 ) ||
( V_74 == V_82 ) ||
( V_74 == V_83 ) ) {
if ( V_75 <= 2 ) {
if ( ( ( V_74 == V_81 )
&& ( V_75 == 0 )
&& ( V_76 >=
266 )
&& ( V_76 <=
8738133UL ) )
|| ( ( V_74 ==
V_81 )
&& ( V_75 == 1 )
&& ( V_76 >=
1 )
&& ( V_76 <=
8738UL ) )
|| ( ( V_74 ==
V_81 )
&& ( V_75 == 2 )
&& ( V_76 >=
1 )
&& ( V_76 <=
8UL ) )
|| ( ( V_74 ==
V_82 )
&& ( V_75 == 0 )
&& ( V_76 >=
242 )
&& ( V_76 <=
7943757UL ) )
|| ( ( V_74 ==
V_82 )
&& ( V_75 == 1 )
&& ( V_76 >=
1 )
&& ( V_76 <=
7943UL ) )
|| ( ( V_74 ==
V_82 )
&& ( V_75 == 2 )
&& ( V_76 >=
1 )
&& ( V_76 <=
7UL ) )
|| ( ( V_74 ==
V_83 )
&& ( V_75 == 0 )
&& ( V_76 >=
200 )
&& ( V_76 <=
6553500UL ) )
|| ( ( V_74 ==
V_83 )
&& ( V_75 == 1 )
&& ( V_76 >=
1 )
&& ( V_76 <=
6553UL ) )
|| ( ( V_74 ==
V_83 )
&& ( V_75 == 2 )
&& ( V_76 >=
1 )
&& ( V_76 <=
6UL ) ) ) {
if ( V_74 ==
V_83 ) {
if ( ( V_10 -> V_13 . V_14 [ V_3 ] & 0xFFFF ) >= 0x3135 ) {
V_80 =
F_5
( V_10 ->
V_13 .
V_32
+ 36 +
( 64 * V_3 ) ) ;
if ( ( V_80 & 1 ) != 1 ) {
F_2 ( L_17 ) ;
V_12
=
- 7 ;
}
} else {
F_2 ( L_17 ) ;
V_12 =
- 7 ;
}
}
if ( V_12 == 0 ) {
if ( ( V_10 -> V_13 . V_14 [ V_3 ] & 0xFFFF ) >= 0x3131 ) {
if ( V_74 == V_83 ) {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
|
V_84 ;
}
else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
&
V_85 ;
}
F_11 () ;
switch ( V_75 ) {
case 0 :
V_78
=
( unsigned int )
( V_76
*
( 0.00025 * V_74 ) ) ;
if ( ( double ) ( ( double ) V_76 * ( 0.00025 * ( double ) V_74 ) ) >= ( ( double ) ( ( double ) V_78 + 0.5 ) ) ) {
V_78
=
V_78
+
1 ;
}
* V_77
=
( unsigned int )
( V_78
/
( 0.00025 * ( double ) V_74 ) ) ;
V_79
=
( double )
V_78
/
( 0.00025
*
( double )
V_74 ) ;
if ( ( double ) ( ( double ) V_78 / ( 0.00025 * ( double ) V_74 ) ) >= ( double ) ( ( double ) * V_77 + 0.5 ) ) {
* V_77
=
* V_77
+
1 ;
}
V_76
=
V_76
-
1 ;
V_78
=
V_78
-
2 ;
break;
case 1 :
V_78
=
( unsigned int )
( V_76
*
( 0.25 * V_74 ) ) ;
if ( ( double ) ( ( double ) V_76 * ( 0.25 * ( double ) V_74 ) ) >= ( ( double ) ( ( double ) V_78 + 0.5 ) ) ) {
V_78
=
V_78
+
1 ;
}
* V_77
=
( unsigned int )
( V_78
/
( 0.25 * ( double ) V_74 ) ) ;
V_79
=
( double )
V_78
/
(
( double )
0.25
*
( double )
V_74 ) ;
if ( ( double ) ( ( double ) V_78 / ( 0.25 * ( double ) V_74 ) ) >= ( double ) ( ( double ) * V_77 + 0.5 ) ) {
* V_77
=
* V_77
+
1 ;
}
V_76
=
V_76
-
1 ;
V_78
=
V_78
-
2 ;
break;
case 2 :
V_78
=
V_76
*
( 250.0
*
V_74 ) ;
if ( ( double ) ( ( double ) V_76 * ( 250.0 * ( double ) V_74 ) ) >= ( ( double ) ( ( double ) V_78 + 0.5 ) ) ) {
V_78
=
V_78
+
1 ;
}
* V_77
=
( unsigned int )
( V_78
/
( 250.0 * ( double ) V_74 ) ) ;
V_79
=
( double )
V_78
/
( 250.0
*
( double )
V_74 ) ;
if ( ( double ) ( ( double ) V_78 / ( 250.0 * ( double ) V_74 ) ) >= ( double ) ( ( double ) * V_77 + 0.5 ) ) {
* V_77
=
* V_77
+
1 ;
}
V_76
=
V_76
-
1 ;
V_78
=
V_78
-
2 ;
break;
}
F_12 () ;
F_3 ( V_78 , V_10 -> V_13 . V_32 + 32 + ( 64 * V_3 ) ) ;
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_33 .
V_86
= 1 ;
} else {
F_2 ( L_12 ) ;
V_12 =
- 3 ;
}
}
} else {
F_2 ( L_18 ) ;
V_12 = - 6 ;
}
} else {
F_2 ( L_19 ) ;
V_12 = - 5 ;
}
} else {
F_2 ( L_20 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_89 * V_90 ,
unsigned int * V_91 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_92 ;
int V_12 = 0 ;
V_92 = F_14 ( V_90 -> V_93 ) ;
F_15 ( L_21 ) ;
V_10 -> V_94 = V_95 ;
switch ( V_92 ) {
case V_96 :
V_12 = F_1 ( V_2 ,
F_16 ( V_90 -> V_93 ) ,
( unsigned char ) V_91 [ 0 ] ,
( unsigned char ) V_91 [ 1 ] ,
( unsigned char ) V_91 [ 2 ] , ( unsigned char ) V_91 [ 3 ] , ( unsigned char ) V_91 [ 4 ] ) ;
break;
case V_97 :
V_12 = F_4 ( V_2 ,
( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_98 :
V_12 = F_6 ( V_2 ,
F_16 ( V_90 -> V_93 ) ,
( unsigned char ) V_91 [ 0 ] ,
( unsigned char ) V_91 [ 1 ] , ( unsigned char ) V_91 [ 2 ] , ( unsigned char ) V_91 [ 3 ] ) ;
break;
case V_99 :
V_12 = F_7 ( V_2 ,
F_16 ( V_90 -> V_93 ) , ( unsigned char ) V_91 [ 0 ] ) ;
break;
case V_100 :
V_12 = F_8 ( V_2 ,
F_16 ( V_90 -> V_93 ) ,
( unsigned char ) V_91 [ 0 ] , ( unsigned char ) V_91 [ 1 ] ) ;
break;
case V_101 :
V_12 = F_9 ( V_2 ,
F_16 ( V_90 -> V_93 ) , ( unsigned int ) V_91 [ 0 ] ) ;
break;
case V_102 :
V_12 = F_10 ( V_2 ,
F_16 ( V_90 -> V_93 ) ,
( unsigned char ) V_91 [ 0 ] ,
( unsigned char ) V_91 [ 1 ] , ( unsigned int ) V_91 [ 2 ] , ( unsigned int * ) & V_91 [ 0 ] ) ;
break;
default:
F_15 ( L_22 ) ;
}
if ( V_12 >= 0 )
V_12 = V_90 -> V_103 ;
return V_12 ;
}
static int F_17 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
F_3 ( 1 , V_10 -> V_13 .
V_32 + 16 + ( 64 * V_3 ) ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned char V_36 = 0 ;
int V_12 = 0 ;
if ( ( V_10 -> V_13 .
V_14 [ 0 ] & 0xFFFF0000UL ) ==
V_15
|| ( V_10 -> V_13 .
V_14 [ 1 ] & 0xFFFF0000UL ) ==
V_15
|| ( V_10 -> V_13 .
V_14 [ 2 ] & 0xFFFF0000UL ) ==
V_15
|| ( V_10 -> V_13 .
V_14 [ 3 ] & 0xFFFF0000UL ) ==
V_15 ) {
for ( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
if ( ( V_10 -> V_13 .
V_14 [ V_36 ] &
0xFFFF0000UL ) ==
V_15 ) {
F_3 ( 1 , V_10 -> V_13 .
V_32 + 16 + ( 64 * V_36 ) ) ;
}
}
} else {
F_2 ( L_7 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_19 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_74 ,
unsigned char V_104 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_80 = 0 ;
if ( V_3 < 4 ) {
if ( ( V_10 -> V_13 .
V_14 [ V_3 ] &
0xFFFF0000UL ) == V_15 ) {
if ( ( V_10 -> V_13 .
V_14 [ V_3 ] &
0xFFFF ) >= 0x3135 ) {
if ( ( V_74 == V_81 ) ||
( V_74 == V_82 ) ||
( V_74 == V_83 ) ) {
if ( V_104 < 16 ) {
if ( V_74 ==
V_83 ) {
V_80 =
F_5 ( V_10 ->
V_13 .
V_32 +
36 +
( 64 * V_3 ) ) ;
if ( ( V_80 & 1 ) !=
1 ) {
F_2 ( L_17 ) ;
V_12 =
- 6 ;
}
}
if ( V_12 == 0 ) {
if ( V_74 ==
V_83 )
{
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
|
V_105 ;
}
else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
&
V_106 ;
}
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60
=
( V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60
& 0x1F ) |
( ( V_104 &
0x7 ) <<
5 ) ;
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
=
( V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53
& 0xFE ) |
( ( V_104 &
0x8 ) >>
3 ) ;
F_3 ( V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 ->
V_13 .
V_32 +
20 +
( 64 * V_3 ) ) ;
}
}
else {
F_2 ( L_23 ) ;
V_12 = - 5 ;
}
}
else {
F_2 ( L_20 ) ;
V_12 = 4 ;
}
} else {
F_2 ( L_6 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_6 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_20 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_107 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_107 < 2 ) {
F_3 ( 1 << ( V_107 * 4 ) ,
V_10 -> V_13 . V_32 +
( 64 * V_3 ) ) ;
} else {
F_2 ( L_24 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_21 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_108 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( ( V_10 -> V_13 .
V_14 [ V_3 ] &
0xFFFF0000UL ) == V_15 ) {
if ( ( V_10 -> V_13 .
V_14 [ V_3 ] &
0xFFFF ) >= 0x3135 ) {
if ( V_108 == V_109 ||
V_108 == V_110 )
{
if ( V_108 ==
V_110 ) {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53 =
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53 |
V_111 ;
} else {
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53 =
V_10 ->
V_26
[ V_3 ] .
V_27 .
V_28 .
V_29 .
V_53 &
V_112 ;
}
}
else {
F_2 ( L_25 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_6 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_6 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_26 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 . V_60 | 0x10 ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 , V_10 -> V_13 .
V_32 + 20 + ( 64 * V_3 ) ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_23 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 . V_60 & 0xEF ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 , V_10 -> V_13 .
V_32 + 20 + ( 64 * V_3 ) ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_89 * V_90 ,
unsigned int * V_91 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_113 ;
int V_12 = 0 ;
V_113 = F_14 ( V_90 -> V_93 ) ;
V_10 -> V_94 = V_95 ;
switch ( V_113 ) {
case V_114 :
V_12 = F_17 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_115 :
V_12 = F_18 ( V_2 ) ;
break;
case V_116 :
V_12 = F_19 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ,
( unsigned char ) V_91 [ 0 ] , ( unsigned char ) V_91 [ 1 ] ) ;
break;
case V_117 :
V_12 = F_20 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char ) V_91 [ 0 ] ) ;
break;
case V_118 :
V_12 = F_21 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char ) V_91 [ 0 ] ) ;
break;
case V_119 :
V_12 = F_22 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_120 :
V_12 = F_23 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
default:
F_15 ( L_27 ) ;
}
if ( V_12 >= 0 )
V_12 = V_90 -> V_103 ;
return V_12 ;
}
static int F_25 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 -> V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 | V_121 ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 , V_10 -> V_13 .
V_32 + 20 + ( 64 * V_3 ) ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_26 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 &
( ( V_122 << 8 ) | 0xFF ) ,
V_10 -> V_13 . V_32 + 20 +
( 64 * V_3 ) ) ;
F_27 ( 1000 ) ;
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 & V_122 ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_123 ,
unsigned int V_124 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_123 < 2 ) {
F_3 ( ( unsigned int ) ( ( unsigned int ) ( V_124 ) << ( 16 *
V_123 ) ) ,
V_10 -> V_13 . V_32 + 8 +
( V_123 * 4 ) +
( 64 * V_3 ) ) ;
} else {
F_2 ( L_28 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned int V_125 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
F_3 ( V_125 , V_10 -> V_13 .
V_32 + 4 + ( 64 * V_3 ) ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_30 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_126 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_63 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 | V_127 ;
V_126 =
F_5 ( V_10 -> V_13 . V_32 +
24 + ( 64 * V_3 ) ) ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 . V_32 + 20 +
( 64 * V_3 ) ) ;
} else {
F_2 ( L_29 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_31 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_63 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_50 &
V_128 ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 . V_32 + 20 +
( 64 * V_3 ) ) ;
} else {
F_2 ( L_30 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_73 == 1 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 |
V_129 ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 . V_32 + 20 +
( 64 * V_3 ) ) ;
} else {
F_2 ( L_31 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_73 == 1 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 &
V_130 ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 . V_32 + 20 +
( 64 * V_3 ) ) ;
} else {
F_2 ( L_31 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_41 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_86 == 1 ) {
if ( ( V_41 == V_43 ) ||
( V_41 == V_42 ) )
{
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 |
V_131 ;
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 = ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 &
V_132 )
| ( V_41 << 3 ) ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 .
V_32 + 20 +
( 64 * V_3 ) ) ;
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 .
V_133 =
1 ;
} else {
F_2 ( L_8 ) ;
V_12 = - 5 ;
}
} else {
F_2 ( L_32 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_35 ( struct V_1 * V_2 ,
unsigned char V_3 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_86 == 1 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 = V_10 ->
V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_60 &
V_134
& V_132 ;
F_3 ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_31 ,
V_10 -> V_13 . V_32 + 20 +
( 64 * V_3 ) ) ;
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 .
V_133 = 0 ;
} else {
F_2 ( L_32 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_89 * V_90 ,
unsigned int * V_91 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_135 ;
int V_12 = 0 ;
V_135 = F_14 ( V_90 -> V_93 ) ;
V_10 -> V_94 = V_95 ;
switch ( V_135 ) {
case V_136 :
V_12 = F_25 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_137 :
V_12 = F_26 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_138 :
V_12 = F_28 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ,
( unsigned char ) V_91 [ 0 ] , ( unsigned int ) V_91 [ 1 ] ) ;
break;
case V_139 :
V_12 = F_29 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned int ) V_91 [ 0 ] ) ;
break;
case V_140 :
F_30 ( V_2 , ( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_141 :
V_12 = F_31 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_142 :
V_12 = F_32 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_143 :
V_12 = F_33 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
case V_144 :
V_12 = F_34 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char ) V_91 [ 0 ] ) ;
break;
case V_145 :
V_12 = F_35 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ) ;
break;
default:
F_15 ( L_33 ) ;
}
if ( V_12 >= 0 )
V_12 = V_90 -> V_103 ;
return V_12 ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_107 ,
unsigned char * V_146 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_147 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_107 < 2 ) {
V_147 = F_5 ( V_10 -> V_13 .
V_32 + ( 64 * V_3 ) ) ;
* V_146 =
( unsigned char ) ( ( V_147 >> ( V_107 *
4 ) ) & 0x3 ) ;
} else {
F_2 ( L_24 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_107 ,
unsigned int * V_148 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_107 < 2 ) {
* V_148 = F_5 ( V_10 -> V_13 .
V_32 + ( ( V_107 + 1 ) * 4 ) +
( 64 * V_3 ) ) ;
} else {
F_2 ( L_24 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char V_123 ,
unsigned int * V_149 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_37 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_123 < 2 ) {
F_3 ( 1 , V_10 -> V_13 .
V_32 + ( 64 * V_3 ) ) ;
V_37 = F_5 ( V_10 -> V_13 .
V_32 + 4 + ( 64 * V_3 ) ) ;
* V_149 =
( unsigned int ) ( ( V_37 >> ( 16 *
V_123 ) ) &
0xFFFFU ) ;
} else {
F_2 ( L_28 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_40 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned int * V_150 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
F_3 ( 1 , V_10 -> V_13 .
V_32 + ( 64 * V_3 ) ) ;
* V_150 = F_5 ( V_10 -> V_13 .
V_32 + 4 + ( 64 * V_3 ) ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_151 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_152 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_63 ) {
V_152 = F_5 ( V_10 -> V_13 .
V_32 + 12 + ( 64 * V_3 ) ) ;
* V_151 = ( unsigned char ) ( V_152 & 1 ) ;
} else {
F_2 ( L_34 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_42 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_153 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_152 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_67 ) {
V_152 = F_5 ( V_10 -> V_13 .
V_32 + 24 + ( 64 * V_3 ) ) ;
* V_153 =
( unsigned char ) ( ~ V_152 & 1 ) ;
} else {
F_2 ( L_35 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_154 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_152 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
V_152 = F_5 ( V_10 -> V_13 .
V_32 + 24 + ( 64 * V_3 ) ) ;
* V_154 = ( unsigned char ) ( ( V_152 >> 1 ) & 1 ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_155 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_152 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
V_152 = F_5 ( V_10 -> V_13 .
V_32 + 16 + ( 64 * V_3 ) ) ;
* V_155 = ( unsigned char ) ( V_152 & 1 ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_156 ,
unsigned char * V_157 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_152 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( ( V_10 -> V_26 [ V_3 ] .
V_27 .
V_28 .
V_29 .
V_30 & 0x10 ) == 0x10 ) {
if ( ( V_10 -> V_13 .
V_14
[ V_3 ] & 0xFFFF ) >=
0x3136 ) {
V_152 =
F_5 ( V_10 -> V_13 .
V_32 + 16 +
( 64 * V_3 ) ) ;
* V_157 =
( unsigned char ) ( ( V_152 >> 0 ) &
1 ) ;
* V_156 =
( unsigned char ) ( ( V_152 >> 1 ) &
1 ) ;
}
else {
V_12 = - 5 ;
}
}
else {
F_2 ( L_12 ) ;
V_12 = - 4 ;
}
}
else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
}
else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_46 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_158 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_152 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
V_152 = F_5 ( V_10 -> V_13 .
V_32 + 24 + ( 64 * V_3 ) ) ;
* V_158 = ( unsigned char ) ( ( V_152 >> 2 ) & 1 ) ;
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_47 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_158 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_152 = 0 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_159 == 1 ) {
V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_159 = 0 ;
V_152 = F_5 ( V_10 -> V_13 .
V_32 + 12 + ( 64 * V_3 ) ) ;
* V_158 = ( unsigned char ) ( ( V_152 >> 1 ) & 1 ) ;
} else {
* V_158 = 2 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_48 ( struct V_1 * V_2 ,
unsigned char V_3 ,
unsigned char * V_160 ,
unsigned char * V_158 ,
unsigned int * V_161 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
int V_12 = 0 ;
unsigned int V_162 ;
unsigned int V_152 ;
if ( V_3 < 4 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 . V_33 . V_34 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 . V_86 == 1 ) {
if ( V_10 ->
V_26 [ V_3 ] .
V_27 .
V_33 .
V_133 == 1 ) {
V_152 =
F_5 ( V_10 -> V_13 .
V_32 + 32 +
( 64 * V_3 ) ) ;
if ( V_152 & 1 ) {
* V_160 = 2 ;
* V_158 =
( unsigned char ) ( ( V_152 >>
1 ) & 3 ) ;
* V_161 =
F_5 ( V_10 ->
V_13 .
V_32 + 28 +
( 64 * V_3 ) ) ;
if ( * V_158 == 0 ) {
if ( ( V_10 -> V_26 [ V_3 ] . V_27 . V_28 . V_29 . V_30 & V_16 ) == V_16 ) {
if ( ( * V_161 & 0xFFFFU ) != 0 ) {
V_162
=
( unsigned int )
*
V_161
&
0xFFFFU ;
* V_161
=
( * V_161
&
0xFFFF0000UL )
|
( 0xFFFFU
-
V_162 ) ;
}
if ( ( * V_161 & 0xFFFF0000UL ) != 0 ) {
V_162
=
( unsigned int )
(
( * V_161
>>
16 )
&
0xFFFFU ) ;
* V_161
=
( * V_161
&
0xFFFFUL )
|
(
( 0xFFFFU - V_162 ) << 16 ) ;
}
} else {
if ( * V_161 != 0 ) {
* V_161
=
0xFFFFFFFFUL
-
* V_161 ;
}
}
} else {
if ( * V_158 == 1 ) {
if ( ( * V_161 & 0xFFFF0000UL ) != 0 ) {
V_162
=
( unsigned int )
(
( * V_161
>>
16 )
&
0xFFFFU ) ;
* V_161
=
( * V_161
&
0xFFFFUL )
|
(
( 0xFFFFU - V_162 ) << 16 ) ;
}
} else {
if ( * V_158
== 2 ) {
if ( ( * V_161 & 0xFFFFU ) != 0 ) {
V_162
=
( unsigned int )
*
V_161
&
0xFFFFU ;
* V_161
=
( * V_161
&
0xFFFF0000UL )
|
( 0xFFFFU
-
V_162 ) ;
}
}
}
}
} else {
* V_160 = 1 ;
* V_158 = 0 ;
}
} else {
* V_160 = 0 ;
* V_158 = 0 ;
}
} else {
F_2 ( L_32 ) ;
V_12 = - 4 ;
}
} else {
F_2 ( L_12 ) ;
V_12 = - 3 ;
}
} else {
F_2 ( L_13 ) ;
V_12 = - 2 ;
}
return V_12 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_87 * V_88 ,
struct V_89 * V_90 ,
unsigned int * V_91 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned int V_163 ;
int V_12 = 0 ;
V_163 = F_14 ( V_90 -> V_93 ) ;
V_10 -> V_94 = V_95 ;
switch ( V_163 ) {
case V_164 :
V_12 = F_37 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ,
( unsigned char ) F_50 ( V_90 -> V_93 ) , ( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_165 :
V_12 = F_38 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ,
( unsigned char ) F_50 ( V_90 -> V_93 ) , ( unsigned int * ) & V_91 [ 0 ] ) ;
F_15 ( L_36 , V_91 [ 0 ] ) ;
break;
case V_166 :
V_12 = F_39 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ,
( unsigned char ) F_50 ( V_90 -> V_93 ) , ( unsigned int * ) & V_91 [ 0 ] ) ;
break;
case V_167 :
V_12 = F_40 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned int * ) & V_91 [ 0 ] ) ;
break;
case V_168 :
V_12 = F_41 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_169 :
V_12 = F_42 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_170 :
V_12 = F_43 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_171 :
V_12 = F_44 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_172 :
V_12 = F_45 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ,
( unsigned char * ) & V_91 [ 0 ] , ( unsigned char * ) & V_91 [ 1 ] ) ;
break;
case V_173 :
V_12 = F_46 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_174 :
V_12 = F_47 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) , ( unsigned char * ) & V_91 [ 0 ] ) ;
break;
case V_175 :
V_12 = F_48 ( V_2 ,
( unsigned char ) F_16 ( V_90 -> V_93 ) ,
( unsigned char * ) & V_91 [ 0 ] ,
( unsigned char * ) & V_91 [ 1 ] , ( unsigned int * ) & V_91 [ 2 ] ) ;
break;
case V_176 :
V_91 [ 0 ] = V_10 -> V_177 .
V_178 [ V_10 ->
V_177 . V_179 ] . V_180 ;
V_91 [ 1 ] = V_10 -> V_177 .
V_178 [ V_10 ->
V_177 . V_179 ] . V_181 ;
V_91 [ 2 ] = V_10 -> V_177 .
V_178 [ V_10 ->
V_177 . V_179 ] . V_182 ;
V_10 ->
V_177 .
V_179 = ( V_10 -> V_177 .
V_179 + 1 ) % V_183 ;
break;
default:
F_15 ( L_37 ) ;
}
if ( V_12 >= 0 )
V_12 = V_90 -> V_103 ;
return V_12 ;
}
