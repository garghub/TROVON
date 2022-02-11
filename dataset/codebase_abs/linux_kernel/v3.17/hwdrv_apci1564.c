static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_2 ( V_2 -> V_12 , L_1 ) ;
return - V_13 ;
}
if ( V_7 [ 1 ] == 1 )
V_11 = V_11 | 0x1 ;
else
V_11 = V_11 & 0xFFFFFFFE ;
if ( V_7 [ 2 ] == 1 )
V_11 = V_11 | 0x2 ;
else
V_11 = V_11 & 0xFFFFFFFD ;
F_3 ( V_11 , V_9 -> V_14 + V_15 ) ;
V_9 -> V_16 = V_17 ;
return V_6 -> V_18 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_19 = 0 ;
V_9 -> V_16 = V_17 ;
if ( V_7 [ 0 ] == V_20 ) {
V_9 -> V_21 = V_20 ;
F_3 ( 0x0 , V_9 -> V_14 + V_22 ) ;
F_3 ( V_7 [ 3 ] , V_9 -> V_14 + V_23 ) ;
} else if ( V_7 [ 0 ] == V_24 ) {
V_19 = F_5 ( V_9 -> V_14 + V_25 ) ;
V_19 = V_19 & 0xFFFFF9FEUL ;
F_3 ( V_19 , V_9 -> V_14 + V_25 ) ;
V_9 -> V_21 = V_24 ;
if ( V_7 [ 1 ] == 1 ) {
F_3 ( 0x02 , V_9 -> V_14 + V_25 ) ;
F_3 ( 0x0 , V_9 -> V_14 + V_26 ) ;
F_3 ( 0x0 , V_9 -> V_14 + V_27 ) ;
F_3 ( 0x0 , V_9 -> V_14 + V_28 ) ;
F_3 ( 0x0 ,
V_2 -> V_29 + F_6 ( V_30 ) ) ;
F_3 ( 0x0 ,
V_2 -> V_29 + F_6 ( V_31 ) ) ;
F_3 ( 0x0 ,
V_2 -> V_29 + F_6 ( V_32 ) ) ;
F_3 ( 0x0 ,
V_2 -> V_29 + F_6 ( V_33 ) ) ;
} else {
F_3 ( 0x0 , V_9 -> V_14 + V_25 ) ;
}
F_3 ( V_7 [ 2 ] , V_9 -> V_14 + V_34 ) ;
F_3 ( V_7 [ 3 ] , V_9 -> V_14 + V_35 ) ;
V_19 = F_5 ( V_9 -> V_14 + V_25 ) ;
V_19 = ( V_19 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_3 ( V_19 , V_9 -> V_14 + V_25 ) ;
} else if ( V_7 [ 0 ] == V_36 ) {
V_9 -> V_21 = V_36 ;
V_9 -> V_37 = V_7 [ 5 ] ;
V_19 = F_5 ( V_2 -> V_29 + F_7 ( V_7 [ 5 ] - 1 ) ) ;
V_19 = V_19 & 0xFFFFF9FEUL ;
F_3 ( V_19 , V_2 -> V_29 + F_7 ( V_7 [ 5 ] - 1 ) ) ;
F_3 ( V_7 [ 3 ] , V_2 -> V_29 + F_8 ( V_7 [ 5 ] - 1 ) ) ;
V_19 =
( V_19 & 0xFFFC19E2UL ) | 0x80000UL |
( unsigned int ) ( ( unsigned int ) V_7 [ 4 ] << 16UL ) ;
F_3 ( V_19 , V_2 -> V_29 + F_7 ( V_7 [ 5 ] - 1 ) ) ;
V_19 = ( V_19 & 0xFFFFF9FD ) | ( V_7 [ 1 ] << 1 ) ;
F_3 ( V_19 , V_2 -> V_29 + F_7 ( V_7 [ 5 ] - 1 ) ) ;
V_19 = ( V_19 & 0xFFFBF9FFUL ) | ( V_7 [ 6 ] << 18 ) ;
F_3 ( V_19 , V_2 -> V_29 + F_7 ( V_7 [ 5 ] - 1 ) ) ;
} else {
F_2 ( V_2 -> V_12 , L_2 ) ;
}
return V_6 -> V_18 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_19 = 0 ;
if ( V_9 -> V_21 == V_20 ) {
switch ( V_7 [ 1 ] ) {
case 0 :
F_3 ( 0x0 , V_9 -> V_14 + V_22 ) ;
break;
case 1 :
F_3 ( 0x0001 , V_9 -> V_14 + V_22 ) ;
break;
case 2 :
F_3 ( 0x0201 , V_9 -> V_14 + V_22 ) ;
break;
default:
F_2 ( V_2 -> V_12 , L_3 ) ;
return - V_13 ;
}
}
if ( V_9 -> V_21 == V_24 ) {
if ( V_7 [ 1 ] == 1 ) {
V_19 = F_5 ( V_9 -> V_14 + V_25 ) ;
V_19 = ( V_19 & 0xFFFFF9FFUL ) | 0x1UL ;
F_3 ( V_19 , V_9 -> V_14 + V_25 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_19 = F_5 ( V_9 -> V_14 + V_25 ) ;
V_19 = V_19 & 0xFFFFF9FEUL ;
F_3 ( V_19 , V_9 -> V_14 + V_25 ) ;
}
}
if ( V_9 -> V_21 == V_36 ) {
V_19 =
F_5 ( V_2 -> V_29 +
F_7 ( V_9 -> V_37 - 1 ) ) ;
if ( V_7 [ 1 ] == 1 ) {
V_19 = ( V_19 & 0xFFFFF9FFUL ) | 0x1UL ;
} else if ( V_7 [ 1 ] == 0 ) {
V_19 = 0 ;
} else if ( V_7 [ 1 ] == 2 ) {
V_19 = ( V_19 & 0xFFFFF9FFUL ) | 0x400 ;
}
F_3 ( V_19 , V_2 -> V_29 +
F_7 ( V_9 -> V_37 - 1 ) ) ;
}
return V_6 -> V_18 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_19 = 0 ;
if ( V_9 -> V_21 == V_20 ) {
V_7 [ 0 ] = F_5 ( V_9 -> V_14 + V_38 ) & 0x1 ;
V_7 [ 1 ] = F_5 ( V_9 -> V_14 + V_39 ) ;
} else if ( V_9 -> V_21 == V_24 ) {
V_7 [ 0 ] = F_5 ( V_9 -> V_14 + V_40 ) & 0x1 ;
V_7 [ 1 ] = F_5 ( V_9 -> V_14 + V_41 ) ;
} else if ( V_9 -> V_21 == V_36 ) {
V_7 [ 0 ] =
F_5 ( V_2 -> V_29 +
F_11 ( V_9 -> V_37 - 1 ) ) ;
V_19 =
F_5 ( V_2 -> V_29 +
F_12 ( V_9 -> V_37 - 1 ) ) ;
V_7 [ 1 ] = ( unsigned char ) ( ( V_19 >> 1 ) & 1 ) ;
V_7 [ 2 ] = ( unsigned char ) ( ( V_19 >> 2 ) & 1 ) ;
V_7 [ 3 ] = ( unsigned char ) ( ( V_19 >> 3 ) & 1 ) ;
V_7 [ 4 ] = ( unsigned char ) ( ( V_19 >> 0 ) & 1 ) ;
} else if ( ( V_9 -> V_21 != V_24 )
&& ( V_9 -> V_21 != V_20 )
&& ( V_9 -> V_21 != V_36 ) ) {
F_2 ( V_2 -> V_12 , L_4 ) ;
}
return V_6 -> V_18 ;
}
