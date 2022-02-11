int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_8 ;
int V_9 = 0 ;
V_8 = F_2 ( V_6 -> V_10 ) ;
F_3 ( L_1 ) ;
V_11 -> V_12 = V_13 ;
switch ( V_8 ) {
case V_14 :
V_9 = F_4 ( V_2 ,
F_5 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] ,
( unsigned char ) V_7 [ 1 ] ,
( unsigned char ) V_7 [ 2 ] , ( unsigned char ) V_7 [ 3 ] , ( unsigned char ) V_7 [ 4 ] ) ;
break;
case V_15 :
V_9 = F_6 ( V_2 ,
( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_16 :
V_9 = F_7 ( V_2 ,
F_5 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] ,
( unsigned char ) V_7 [ 1 ] , ( unsigned char ) V_7 [ 2 ] , ( unsigned char ) V_7 [ 3 ] ) ;
break;
case V_17 :
V_9 = F_8 ( V_2 ,
F_5 ( V_6 -> V_10 ) , ( unsigned char ) V_7 [ 0 ] ) ;
break;
case V_18 :
V_9 = F_9 ( V_2 ,
F_5 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] , ( unsigned char ) V_7 [ 1 ] ) ;
break;
case V_19 :
V_9 = F_10 ( V_2 ,
F_5 ( V_6 -> V_10 ) , ( unsigned int ) V_7 [ 0 ] ) ;
break;
case V_20 :
V_9 = F_11 ( V_2 ,
F_5 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] ,
( unsigned char ) V_7 [ 1 ] , ( unsigned int ) V_7 [ 2 ] , ( unsigned int * ) & V_7 [ 0 ] ) ;
break;
default:
F_3 ( L_2 ) ;
}
if ( V_9 >= 0 )
V_9 = V_6 -> V_21 ;
return V_9 ;
}
int F_4 ( struct V_1 * V_2 ,
unsigned char V_22 ,
unsigned char V_23 ,
unsigned char V_24 ,
unsigned char V_25 ,
unsigned char V_26 , unsigned char V_27 )
{
int V_9 = 0 ;
if ( ( V_11 -> V_28 .
V_29 [ V_22 ] & 0xFFFF0000UL ) ==
V_30 ) {
if ( V_23 == V_31
|| V_23 == V_32 ) {
if ( V_24 == V_33 ||
V_24 == V_34 ||
V_24 == V_35 ||
V_24 == V_36 ) {
if ( ( V_24 == V_36
&& ( V_25 ==
V_37
|| V_25
== V_38 ) )
|| ( V_24 !=
V_36
&& ( V_25 ==
V_39
|| V_25
==
V_40 ) ) )
{
if ( V_23 ==
V_31 ) {
if ( ( V_24 !=
V_36
&&
( V_26
==
V_33
||
V_26
==
V_34
||
V_26
==
V_35 ) )
|| ( V_24
==
V_36
&&
V_26
==
V_36 ) )
{
if ( ( V_26 == V_36 && ( V_27 == V_37 || V_27 == V_38 ) ) || ( V_26 != V_36 && ( V_27 == V_39 || V_27 == V_40 ) ) ) {
V_9 =
0 ;
} else {
F_12 ( L_3 ) ;
V_9 =
- 7 ;
}
} else {
F_12 ( L_4 ) ;
V_9 = - 6 ;
}
}
} else {
F_12 ( L_5 ) ;
V_9 = - 5 ;
}
} else {
F_12 ( L_6 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_7 ) ;
V_9 = - 3 ;
}
if ( V_9 == 0 ) {
if ( V_23 == V_32 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_45 = V_23 |
V_24 |
V_25 ;
} else {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_45 = V_23 |
( V_24 & 0x5 ) |
( V_25 & 0x20 ) |
( V_26 & 0xA ) |
( V_27 & 0x40 ) ;
if ( V_24 == V_36 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_45 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_45 |
V_36 ;
}
}
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 .
V_47 + 20 + ( 64 * V_22 ) ) ;
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_49 = 1 ;
}
} else {
F_12 ( L_8 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_6 ( struct V_1 * V_2 , unsigned char * V_50 )
{
unsigned char V_51 = 0 ;
int V_9 = 0 ;
unsigned int V_52 ;
* V_50 = 0 ;
if ( ( V_11 -> V_28 .
V_29 [ 0 ] & 0xFFFF0000UL ) ==
V_30
|| ( V_11 -> V_28 .
V_29 [ 1 ] & 0xFFFF0000UL ) ==
V_30
|| ( V_11 -> V_28 .
V_29 [ 2 ] & 0xFFFF0000UL ) ==
V_30
|| ( V_11 -> V_28 .
V_29 [ 3 ] & 0xFFFF0000UL ) ==
V_30 ) {
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
if ( ( V_11 -> V_28 .
V_29 [ V_51 ] &
0xFFFF0000UL ) ==
V_30 ) {
F_13 ( 3 , V_11 -> V_28 .
V_47 + 16 + ( 64 * V_51 ) ) ;
F_13 ( 1 , V_11 -> V_28 .
V_47 + ( 64 * V_51 ) ) ;
V_52 = F_14 ( V_11 -> V_28 .
V_47 + 4 + ( 64 * V_51 ) ) ;
if ( ( V_52 & 0xFF ) !=
( ( V_52 >> 8 ) & 0xFF )
&& ( V_52 & 0xFF ) !=
( ( V_52 >> 16 ) & 0xFF )
&& ( V_52 & 0xFF ) !=
( ( V_52 >> 24 ) & 0xFF ) ) {
* V_50 =
* V_50 | ( 1 <<
V_51 ) ;
}
F_13 ( 0 , V_11 -> V_28 .
V_47 + 16 + ( 64 * V_51 ) ) ;
}
}
} else {
F_12 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_7 ( struct V_1 * V_2 ,
unsigned char V_22 ,
unsigned char V_53 ,
unsigned char V_54 , unsigned char V_55 , unsigned char V_56 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_53 == V_57 ||
V_53 == V_58 ) {
if ( V_54 ==
V_59
|| V_54 ==
V_60
|| V_54 ==
V_61
|| V_54 ==
V_62
|| V_54 ==
V_63
|| V_54 ==
V_64 )
{
if ( V_55 == V_57 ||
V_55 == V_58 )
{
if ( V_56 ==
V_57
|| V_56 ==
V_58 ) {
if ( V_53 ==
V_57 )
{
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
|
V_66 ;
} else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
&
V_67 ;
}
if ( V_54 ==
V_60
||
V_54
==
V_62
||
V_54
==
V_64 )
{
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
|
V_69 ;
} else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
&
V_70 ;
}
if ( V_54 ==
V_63
||
V_54
==
V_64 )
{
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
|
V_71 ;
}
else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
&
V_72 ;
if ( V_54 == V_59 || V_54 == V_60 ) {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
|
V_73 ;
} else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
&
( ~ V_73 ) ;
}
}
if ( V_55 ==
V_58 )
{
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
|
V_74 ;
} else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65
&
( ~ V_74 ) ;
}
if ( V_56 ==
V_57 )
{
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75
|
V_76 ;
} else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75
&
V_77 ;
}
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_48 .
V_78 = 1 ;
} else {
F_12 ( L_10 ) ;
V_9 = - 7 ;
}
} else {
F_12 ( L_11 ) ;
V_9 = - 6 ;
}
} else {
F_12 ( L_12 ) ;
V_9 = - 5 ;
}
} else {
F_12 ( L_13 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_8 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_79 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_79 == 0 || V_79 == 1 ) {
if ( V_79 == 1 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 |
V_80 ;
} else {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 &
V_81 ;
}
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 . V_47 + 20 +
( 64 * V_22 ) ) ;
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_82 = 1 ;
} else {
F_12 ( L_16 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_9 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_83 , unsigned char V_84 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_83 == 0 || V_83 == 1 ) {
if ( ( V_84 == V_85 ) ||
( ( V_84 == V_86
&& ( V_11 ->
V_28 .
V_29
[ V_22 ] &
0xFFFF ) >=
0x3135 ) ) ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68 = ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68 & ( 0xFF -
( 0x10 << V_83 ) ) ) | ( ( V_84 ^ 1 ) << ( 4 + V_83 ) ) ;
} else {
F_12 ( L_17 ) ;
V_9 = - 5 ;
}
}
else {
F_12 ( L_18 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned int V_87 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
F_13 ( V_87 , V_11 -> V_28 .
V_47 + 28 + ( 64 * V_22 ) ) ;
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_88 = 1 ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned char V_22 ,
unsigned char V_89 ,
unsigned char V_90 ,
unsigned int V_91 , unsigned int * V_92 )
{
int V_9 = 0 ;
unsigned int V_93 = 0 ;
double V_94 ;
unsigned int V_95 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( ( V_89 == V_96 ) ||
( V_89 == V_97 ) ||
( V_89 == V_98 ) ) {
if ( V_90 <= 2 ) {
if ( ( ( V_89 == V_96 )
&& ( V_90 == 0 )
&& ( V_91 >=
266 )
&& ( V_91 <=
8738133UL ) )
|| ( ( V_89 ==
V_96 )
&& ( V_90 == 1 )
&& ( V_91 >=
1 )
&& ( V_91 <=
8738UL ) )
|| ( ( V_89 ==
V_96 )
&& ( V_90 == 2 )
&& ( V_91 >=
1 )
&& ( V_91 <=
8UL ) )
|| ( ( V_89 ==
V_97 )
&& ( V_90 == 0 )
&& ( V_91 >=
242 )
&& ( V_91 <=
7943757UL ) )
|| ( ( V_89 ==
V_97 )
&& ( V_90 == 1 )
&& ( V_91 >=
1 )
&& ( V_91 <=
7943UL ) )
|| ( ( V_89 ==
V_97 )
&& ( V_90 == 2 )
&& ( V_91 >=
1 )
&& ( V_91 <=
7UL ) )
|| ( ( V_89 ==
V_98 )
&& ( V_90 == 0 )
&& ( V_91 >=
200 )
&& ( V_91 <=
6553500UL ) )
|| ( ( V_89 ==
V_98 )
&& ( V_90 == 1 )
&& ( V_91 >=
1 )
&& ( V_91 <=
6553UL ) )
|| ( ( V_89 ==
V_98 )
&& ( V_90 == 2 )
&& ( V_91 >=
1 )
&& ( V_91 <=
6UL ) ) ) {
if ( V_89 ==
V_98 ) {
if ( ( V_11 -> V_28 . V_29 [ V_22 ] & 0xFFFF ) >= 0x3135 ) {
V_95 =
F_14
( V_11 ->
V_28 .
V_47
+ 36 +
( 64 * V_22 ) ) ;
if ( ( V_95 & 1 ) != 1 ) {
F_12 ( L_19 ) ;
V_9
=
- 7 ;
}
} else {
F_12 ( L_19 ) ;
V_9 =
- 7 ;
}
}
if ( V_9 == 0 ) {
if ( ( V_11 -> V_28 . V_29 [ V_22 ] & 0xFFFF ) >= 0x3131 ) {
if ( V_89 == V_98 ) {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
|
V_99 ;
}
else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
&
V_100 ;
}
F_15 () ;
switch ( V_90 ) {
case 0 :
V_93
=
( unsigned int )
( V_91
*
( 0.00025 * V_89 ) ) ;
if ( ( double ) ( ( double ) V_91 * ( 0.00025 * ( double ) V_89 ) ) >= ( ( double ) ( ( double ) V_93 + 0.5 ) ) ) {
V_93
=
V_93
+
1 ;
}
* V_92
=
( unsigned int )
( V_93
/
( 0.00025 * ( double ) V_89 ) ) ;
V_94
=
( double )
V_93
/
( 0.00025
*
( double )
V_89 ) ;
if ( ( double ) ( ( double ) V_93 / ( 0.00025 * ( double ) V_89 ) ) >= ( double ) ( ( double ) * V_92 + 0.5 ) ) {
* V_92
=
* V_92
+
1 ;
}
V_91
=
V_91
-
1 ;
V_93
=
V_93
-
2 ;
break;
case 1 :
V_93
=
( unsigned int )
( V_91
*
( 0.25 * V_89 ) ) ;
if ( ( double ) ( ( double ) V_91 * ( 0.25 * ( double ) V_89 ) ) >= ( ( double ) ( ( double ) V_93 + 0.5 ) ) ) {
V_93
=
V_93
+
1 ;
}
* V_92
=
( unsigned int )
( V_93
/
( 0.25 * ( double ) V_89 ) ) ;
V_94
=
( double )
V_93
/
(
( double )
0.25
*
( double )
V_89 ) ;
if ( ( double ) ( ( double ) V_93 / ( 0.25 * ( double ) V_89 ) ) >= ( double ) ( ( double ) * V_92 + 0.5 ) ) {
* V_92
=
* V_92
+
1 ;
}
V_91
=
V_91
-
1 ;
V_93
=
V_93
-
2 ;
break;
case 2 :
V_93
=
V_91
*
( 250.0
*
V_89 ) ;
if ( ( double ) ( ( double ) V_91 * ( 250.0 * ( double ) V_89 ) ) >= ( ( double ) ( ( double ) V_93 + 0.5 ) ) ) {
V_93
=
V_93
+
1 ;
}
* V_92
=
( unsigned int )
( V_93
/
( 250.0 * ( double ) V_89 ) ) ;
V_94
=
( double )
V_93
/
( 250.0
*
( double )
V_89 ) ;
if ( ( double ) ( ( double ) V_93 / ( 250.0 * ( double ) V_89 ) ) >= ( double ) ( ( double ) * V_92 + 0.5 ) ) {
* V_92
=
* V_92
+
1 ;
}
V_91
=
V_91
-
1 ;
V_93
=
V_93
-
2 ;
break;
}
F_16 () ;
F_13 ( V_93 , V_11 -> V_28 . V_47 + 32 + ( 64 * V_22 ) ) ;
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_48 .
V_101
= 1 ;
} else {
F_12 ( L_14 ) ;
V_9 =
- 3 ;
}
}
} else {
F_12 ( L_20 ) ;
V_9 = - 6 ;
}
} else {
F_12 ( L_21 ) ;
V_9 = - 5 ;
}
} else {
F_12 ( L_22 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_102 ;
int V_9 = 0 ;
V_102 = F_2 ( V_6 -> V_10 ) ;
V_11 -> V_12 = V_13 ;
switch ( V_102 ) {
case V_103 :
V_9 = F_18 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_104 :
V_9 = F_19 ( V_2 ) ;
break;
case V_105 :
V_9 = F_20 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] , ( unsigned char ) V_7 [ 1 ] ) ;
break;
case V_106 :
V_9 = F_21 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char ) V_7 [ 0 ] ) ;
break;
case V_107 :
V_9 = F_22 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char ) V_7 [ 0 ] ) ;
break;
case V_108 :
V_9 = F_23 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_109 :
V_9 = F_24 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
default:
F_3 ( L_23 ) ;
}
if ( V_9 >= 0 )
V_9 = V_6 -> V_21 ;
return V_9 ;
}
int F_18 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
F_13 ( 1 , V_11 -> V_28 .
V_47 + 16 + ( 64 * V_22 ) ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_19 ( struct V_1 * V_2 )
{
unsigned char V_51 = 0 ;
int V_9 = 0 ;
if ( ( V_11 -> V_28 .
V_29 [ 0 ] & 0xFFFF0000UL ) ==
V_30
|| ( V_11 -> V_28 .
V_29 [ 1 ] & 0xFFFF0000UL ) ==
V_30
|| ( V_11 -> V_28 .
V_29 [ 2 ] & 0xFFFF0000UL ) ==
V_30
|| ( V_11 -> V_28 .
V_29 [ 3 ] & 0xFFFF0000UL ) ==
V_30 ) {
for ( V_51 = 0 ; V_51 < 4 ; V_51 ++ ) {
if ( ( V_11 -> V_28 .
V_29 [ V_51 ] &
0xFFFF0000UL ) ==
V_30 ) {
F_13 ( 1 , V_11 -> V_28 .
V_47 + 16 + ( 64 * V_51 ) ) ;
}
}
} else {
F_12 ( L_9 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_20 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_89 , unsigned char V_110 )
{
int V_9 = 0 ;
unsigned int V_95 = 0 ;
if ( V_22 < 4 ) {
if ( ( V_11 -> V_28 .
V_29 [ V_22 ] &
0xFFFF0000UL ) == V_30 ) {
if ( ( V_11 -> V_28 .
V_29 [ V_22 ] &
0xFFFF ) >= 0x3135 ) {
if ( ( V_89 == V_96 ) ||
( V_89 == V_97 ) ||
( V_89 == V_98 ) ) {
if ( V_110 < 16 ) {
if ( V_89 ==
V_98 ) {
V_95 =
F_14 ( V_11 ->
V_28 .
V_47 +
36 +
( 64 * V_22 ) ) ;
if ( ( V_95 & 1 ) !=
1 ) {
F_12 ( L_19 ) ;
V_9 =
- 6 ;
}
}
if ( V_9 == 0 ) {
if ( V_89 ==
V_98 )
{
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
|
V_111 ;
}
else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
&
V_112 ;
}
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75
=
( V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75
& 0x1F ) |
( ( V_110 &
0x7 ) <<
5 ) ;
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
=
( V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68
& 0xFE ) |
( ( V_110 &
0x8 ) >>
3 ) ;
F_13 ( V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 ->
V_28 .
V_47 +
20 +
( 64 * V_22 ) ) ;
}
}
else {
F_12 ( L_24 ) ;
V_9 = - 5 ;
}
}
else {
F_12 ( L_22 ) ;
V_9 = 4 ;
}
} else {
F_12 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_21 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_113 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_113 < 2 ) {
F_13 ( 1 << ( V_113 * 4 ) ,
V_11 -> V_28 . V_47 +
( 64 * V_22 ) ) ;
} else {
F_12 ( L_25 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_22 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_114 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( ( V_11 -> V_28 .
V_29 [ V_22 ] &
0xFFFF0000UL ) == V_30 ) {
if ( ( V_11 -> V_28 .
V_29 [ V_22 ] &
0xFFFF ) >= 0x3135 ) {
if ( V_114 == V_115 ||
V_114 == V_116 )
{
if ( V_114 ==
V_116 ) {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68 =
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68 |
V_117 ;
} else {
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68 =
V_11 ->
V_41
[ V_22 ] .
V_42 .
V_43 .
V_44 .
V_68 &
V_118 ;
}
}
else {
F_12 ( L_26 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_8 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_27 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_23 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 . V_75 | 0x10 ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 , V_11 -> V_28 .
V_47 + 20 + ( 64 * V_22 ) ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_24 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 . V_75 & 0xEF ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 , V_11 -> V_28 .
V_47 + 20 + ( 64 * V_22 ) ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_119 ;
int V_9 = 0 ;
V_119 = F_2 ( V_6 -> V_10 ) ;
V_11 -> V_12 = V_13 ;
switch ( V_119 ) {
case V_120 :
V_9 = F_26 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_121 :
V_9 = F_27 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_122 :
V_9 = F_28 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ,
( unsigned char ) V_7 [ 0 ] , ( unsigned int ) V_7 [ 1 ] ) ;
break;
case V_123 :
V_9 = F_29 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned int ) V_7 [ 0 ] ) ;
break;
case V_124 :
F_30 ( V_2 , ( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_125 :
V_9 = F_31 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_126 :
V_9 = F_32 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_127 :
V_9 = F_33 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
case V_128 :
V_9 = F_34 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char ) V_7 [ 0 ] ) ;
break;
case V_129 :
V_9 = F_35 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ) ;
break;
default:
F_3 ( L_28 ) ;
}
if ( V_9 >= 0 )
V_9 = V_6 -> V_21 ;
return V_9 ;
}
int F_26 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 -> V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 | V_130 ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 , V_11 -> V_28 .
V_47 + 20 + ( 64 * V_22 ) ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_27 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 &
( ( V_131 << 8 ) | 0xFF ) ,
V_11 -> V_28 . V_47 + 20 +
( 64 * V_22 ) ) ;
F_36 ( 1000 ) ;
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 & V_131 ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_28 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_132 , unsigned int V_133 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_132 < 2 ) {
F_13 ( ( unsigned int ) ( ( unsigned int ) ( V_133 ) << ( 16 *
V_132 ) ) ,
V_11 -> V_28 . V_47 + 8 +
( V_132 * 4 ) +
( 64 * V_22 ) ) ;
} else {
F_12 ( L_29 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_29 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned int V_134 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
F_13 ( V_134 , V_11 -> V_28 .
V_47 + 4 + ( 64 * V_22 ) ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_30 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
unsigned int V_135 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_78 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 | V_136 ;
V_135 =
F_14 ( V_11 -> V_28 . V_47 +
24 + ( 64 * V_22 ) ) ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 . V_47 + 20 +
( 64 * V_22 ) ) ;
} else {
F_12 ( L_30 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_31 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_78 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_65 &
V_137 ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 . V_47 + 20 +
( 64 * V_22 ) ) ;
} else {
F_12 ( L_31 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_32 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_88 == 1 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 |
V_138 ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 . V_47 + 20 +
( 64 * V_22 ) ) ;
} else {
F_12 ( L_32 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_33 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_88 == 1 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 &
V_139 ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 . V_47 + 20 +
( 64 * V_22 ) ) ;
} else {
F_12 ( L_32 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_34 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_56 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_101 == 1 ) {
if ( ( V_56 == V_58 ) ||
( V_56 == V_57 ) )
{
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 |
V_140 ;
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 = ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 &
V_141 )
| ( V_56 << 3 ) ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 .
V_47 + 20 +
( 64 * V_22 ) ) ;
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 .
V_142 =
1 ;
} else {
F_12 ( L_10 ) ;
V_9 = - 5 ;
}
} else {
F_12 ( L_33 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_35 ( struct V_1 * V_2 , unsigned char V_22 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_101 == 1 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 = V_11 ->
V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_75 &
V_143
& V_141 ;
F_13 ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_46 ,
V_11 -> V_28 . V_47 + 20 +
( 64 * V_22 ) ) ;
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 .
V_142 = 0 ;
} else {
F_12 ( L_33 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_144 ;
int V_9 = 0 ;
V_144 = F_2 ( V_6 -> V_10 ) ;
V_11 -> V_12 = V_13 ;
switch ( V_144 ) {
case V_145 :
V_9 = F_38 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ,
( unsigned char ) F_39 ( V_6 -> V_10 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_146 :
V_9 = F_40 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ,
( unsigned char ) F_39 ( V_6 -> V_10 ) , ( unsigned int * ) & V_7 [ 0 ] ) ;
F_3 ( L_34 , V_7 [ 0 ] ) ;
break;
case V_147 :
V_9 = F_41 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ,
( unsigned char ) F_39 ( V_6 -> V_10 ) , ( unsigned int * ) & V_7 [ 0 ] ) ;
break;
case V_148 :
V_9 = F_42 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned int * ) & V_7 [ 0 ] ) ;
break;
case V_149 :
V_9 = F_43 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_150 :
V_9 = F_44 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_151 :
V_9 = F_45 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_152 :
V_9 = F_46 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_153 :
V_9 = F_47 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ,
( unsigned char * ) & V_7 [ 0 ] , ( unsigned char * ) & V_7 [ 1 ] ) ;
break;
case V_154 :
V_9 = F_48 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_155 :
V_9 = F_49 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) , ( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_156 :
V_9 = F_50 ( V_2 ,
( unsigned char ) F_5 ( V_6 -> V_10 ) ,
( unsigned char * ) & V_7 [ 0 ] ,
( unsigned char * ) & V_7 [ 1 ] , ( unsigned int * ) & V_7 [ 2 ] ) ;
break;
case V_157 :
V_7 [ 0 ] = V_11 -> V_158 .
V_159 [ V_11 ->
V_158 . V_160 ] . V_161 ;
V_7 [ 1 ] = V_11 -> V_158 .
V_159 [ V_11 ->
V_158 . V_160 ] . V_162 ;
V_7 [ 2 ] = V_11 -> V_158 .
V_159 [ V_11 ->
V_158 . V_160 ] . V_163 ;
V_11 ->
V_158 .
V_160 = ( V_11 -> V_158 .
V_160 + 1 ) % V_164 ;
break;
default:
F_3 ( L_35 ) ;
}
if ( V_9 >= 0 )
V_9 = V_6 -> V_21 ;
return V_9 ;
}
int F_38 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_113 , unsigned char * V_165 )
{
int V_9 = 0 ;
unsigned int V_166 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_113 < 2 ) {
V_166 = F_14 ( V_11 -> V_28 .
V_47 + ( 64 * V_22 ) ) ;
* V_165 =
( unsigned char ) ( ( V_166 >> ( V_113 *
4 ) ) & 0x3 ) ;
} else {
F_12 ( L_25 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_40 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_113 , unsigned int * V_167 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_113 < 2 ) {
* V_167 = F_14 ( V_11 -> V_28 .
V_47 + ( ( V_113 + 1 ) * 4 ) +
( 64 * V_22 ) ) ;
} else {
F_12 ( L_25 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_41 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char V_132 , unsigned int * V_168 )
{
int V_9 = 0 ;
unsigned int V_52 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_132 < 2 ) {
F_13 ( 1 , V_11 -> V_28 .
V_47 + ( 64 * V_22 ) ) ;
V_52 = F_14 ( V_11 -> V_28 .
V_47 + 4 + ( 64 * V_22 ) ) ;
* V_168 =
( unsigned int ) ( ( V_52 >> ( 16 *
V_132 ) ) &
0xFFFFU ) ;
} else {
F_12 ( L_29 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_42 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned int * V_169 )
{
int V_9 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
F_13 ( 1 , V_11 -> V_28 .
V_47 + ( 64 * V_22 ) ) ;
* V_169 = F_14 ( V_11 -> V_28 .
V_47 + 4 + ( 64 * V_22 ) ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_43 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char * V_170 )
{
int V_9 = 0 ;
unsigned int V_171 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_78 ) {
V_171 = F_14 ( V_11 -> V_28 .
V_47 + 12 + ( 64 * V_22 ) ) ;
* V_170 = ( unsigned char ) ( V_171 & 1 ) ;
} else {
F_12 ( L_36 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_44 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char * V_172 )
{
int V_9 = 0 ;
unsigned int V_171 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_82 ) {
V_171 = F_14 ( V_11 -> V_28 .
V_47 + 24 + ( 64 * V_22 ) ) ;
* V_172 =
( unsigned char ) ( ~ V_171 & 1 ) ;
} else {
F_12 ( L_37 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_45 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char * V_173 )
{
int V_9 = 0 ;
unsigned int V_171 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
V_171 = F_14 ( V_11 -> V_28 .
V_47 + 24 + ( 64 * V_22 ) ) ;
* V_173 = ( unsigned char ) ( ( V_171 >> 1 ) & 1 ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_46 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char * V_174 )
{
int V_9 = 0 ;
unsigned int V_171 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
V_171 = F_14 ( V_11 -> V_28 .
V_47 + 16 + ( 64 * V_22 ) ) ;
* V_174 = ( unsigned char ) ( V_171 & 1 ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_47 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char * V_175 , unsigned char * V_176 )
{
int V_9 = 0 ;
unsigned int V_171 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( ( V_11 -> V_41 [ V_22 ] .
V_42 .
V_43 .
V_44 .
V_45 & 0x10 ) == 0x10 ) {
if ( ( V_11 -> V_28 .
V_29
[ V_22 ] & 0xFFFF ) >=
0x3136 ) {
V_171 =
F_14 ( V_11 -> V_28 .
V_47 + 16 +
( 64 * V_22 ) ) ;
* V_176 =
( unsigned char ) ( ( V_171 >> 0 ) &
1 ) ;
* V_175 =
( unsigned char ) ( ( V_171 >> 1 ) &
1 ) ;
}
else {
V_9 = - 5 ;
}
}
else {
F_12 ( L_14 ) ;
V_9 = - 4 ;
}
}
else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
}
else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_48 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char * V_177 )
{
int V_9 = 0 ;
unsigned int V_171 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
V_171 = F_14 ( V_11 -> V_28 .
V_47 + 24 + ( 64 * V_22 ) ) ;
* V_177 = ( unsigned char ) ( ( V_171 >> 2 ) & 1 ) ;
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_49 ( struct V_1 * V_2 ,
unsigned char V_22 , unsigned char * V_177 )
{
int V_9 = 0 ;
unsigned int V_171 = 0 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_178 == 1 ) {
V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_178 = 0 ;
V_171 = F_14 ( V_11 -> V_28 .
V_47 + 12 + ( 64 * V_22 ) ) ;
* V_177 = ( unsigned char ) ( ( V_171 >> 1 ) & 1 ) ;
} else {
* V_177 = 2 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
int F_50 ( struct V_1 * V_2 ,
unsigned char V_22 ,
unsigned char * V_179 , unsigned char * V_177 , unsigned int * V_180 )
{
int V_9 = 0 ;
unsigned int V_181 ;
unsigned int V_171 ;
if ( V_22 < 4 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 . V_48 . V_49 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 . V_101 == 1 ) {
if ( V_11 ->
V_41 [ V_22 ] .
V_42 .
V_48 .
V_142 == 1 ) {
V_171 =
F_14 ( V_11 -> V_28 .
V_47 + 32 +
( 64 * V_22 ) ) ;
if ( V_171 & 1 ) {
* V_179 = 2 ;
* V_177 =
( unsigned char ) ( ( V_171 >>
1 ) & 3 ) ;
* V_180 =
F_14 ( V_11 ->
V_28 .
V_47 + 28 +
( 64 * V_22 ) ) ;
if ( * V_177 == 0 ) {
if ( ( V_11 -> V_41 [ V_22 ] . V_42 . V_43 . V_44 . V_45 & V_31 ) == V_31 ) {
if ( ( * V_180 & 0xFFFFU ) != 0 ) {
V_181
=
( unsigned int )
*
V_180
&
0xFFFFU ;
* V_180
=
( * V_180
&
0xFFFF0000UL )
|
( 0xFFFFU
-
V_181 ) ;
}
if ( ( * V_180 & 0xFFFF0000UL ) != 0 ) {
V_181
=
( unsigned int )
(
( * V_180
>>
16 )
&
0xFFFFU ) ;
* V_180
=
( * V_180
&
0xFFFFUL )
|
(
( 0xFFFFU - V_181 ) << 16 ) ;
}
} else {
if ( * V_180 != 0 ) {
* V_180
=
0xFFFFFFFFUL
-
* V_180 ;
}
}
} else {
if ( * V_177 == 1 ) {
if ( ( * V_180 & 0xFFFF0000UL ) != 0 ) {
V_181
=
( unsigned int )
(
( * V_180
>>
16 )
&
0xFFFFU ) ;
* V_180
=
( * V_180
&
0xFFFFUL )
|
(
( 0xFFFFU - V_181 ) << 16 ) ;
}
} else {
if ( * V_177
== 2 ) {
if ( ( * V_180 & 0xFFFFU ) != 0 ) {
V_181
=
( unsigned int )
*
V_180
&
0xFFFFU ;
* V_180
=
( * V_180
&
0xFFFF0000UL )
|
( 0xFFFFU
-
V_181 ) ;
}
}
}
}
} else {
* V_179 = 1 ;
* V_177 = 0 ;
}
} else {
* V_179 = 0 ;
* V_177 = 0 ;
}
} else {
F_12 ( L_33 ) ;
V_9 = - 4 ;
}
} else {
F_12 ( L_14 ) ;
V_9 = - 3 ;
}
} else {
F_12 ( L_15 ) ;
V_9 = - 2 ;
}
return V_9 ;
}
