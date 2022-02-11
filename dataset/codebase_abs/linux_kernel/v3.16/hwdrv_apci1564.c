static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_9 -> V_11 = V_12 ;
if ( V_7 [ 0 ] == V_13 ) {
V_7 [ 2 ] = V_7 [ 2 ] << 4 ;
V_7 [ 3 ] = V_7 [ 3 ] << 4 ;
F_2 ( V_7 [ 2 ] , V_9 -> V_14 + V_15 ) ;
F_2 ( V_7 [ 3 ] , V_9 -> V_14 + V_16 ) ;
if ( V_7 [ 1 ] == V_17 )
F_2 ( 0x4 , V_9 -> V_14 + V_18 ) ;
else
F_2 ( 0x6 , V_9 -> V_14 + V_18 ) ;
} else {
F_2 ( 0x0 , V_9 -> V_14 + V_15 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_16 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_18 ) ;
}
return V_6 -> V_19 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_20 = 0 ;
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_4 ( V_2 ,
L_1 ) ;
return - V_21 ;
}
if ( V_7 [ 0 ] )
V_9 -> V_22 = V_13 ;
else
V_9 -> V_22 = V_23 ;
if ( V_7 [ 1 ] == V_13 )
V_20 = V_20 | 0x1 ;
else
V_20 = V_20 & 0xFFFFFFFE ;
if ( V_7 [ 2 ] == V_13 )
V_20 = V_20 | 0x2 ;
else
V_20 = V_20 & 0xFFFFFFFD ;
F_2 ( V_20 , V_9 -> V_14 + V_24 ) ;
V_25 = F_5 ( V_9 -> V_14 + V_24 ) ;
V_9 -> V_11 = V_12 ;
return V_6 -> V_19 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_26 = 0 ;
V_9 -> V_11 = V_12 ;
if ( V_7 [ 0 ] == V_27 ) {
V_9 -> V_28 = V_27 ;
F_2 ( 0x0 , V_9 -> V_14 + V_29 ) ;
F_2 ( V_7 [ 3 ] , V_9 -> V_14 + V_30 ) ;
} else if ( V_7 [ 0 ] == V_31 ) {
V_26 = F_5 ( V_9 -> V_14 + V_32 ) ;
V_26 = V_26 & 0xFFFFF9FEUL ;
F_2 ( V_26 , V_9 -> V_14 + V_32 ) ;
V_9 -> V_28 = V_31 ;
if ( V_7 [ 1 ] == 1 ) {
F_2 ( 0x02 , V_9 -> V_14 + V_32 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_18 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_33 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_34 ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_7 ( V_36 ) ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_7 ( V_37 ) ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_7 ( V_38 ) ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_7 ( V_39 ) ) ;
} else {
F_2 ( 0x0 , V_9 -> V_14 + V_32 ) ;
}
F_2 ( V_7 [ 2 ] , V_9 -> V_14 + V_40 ) ;
F_2 ( V_7 [ 3 ] , V_9 -> V_14 + V_41 ) ;
V_26 = F_5 ( V_9 -> V_14 + V_32 ) ;
V_26 = ( V_26 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_2 ( V_26 , V_9 -> V_14 + V_32 ) ;
} else if ( V_7 [ 0 ] == V_42 ) {
V_9 -> V_28 = V_42 ;
V_9 -> V_43 = V_7 [ 5 ] ;
V_26 = F_5 ( V_2 -> V_35 + F_8 ( V_7 [ 5 ] - 1 ) ) ;
V_26 = V_26 & 0xFFFFF9FEUL ;
F_2 ( V_26 , V_2 -> V_35 + F_8 ( V_7 [ 5 ] - 1 ) ) ;
F_2 ( V_7 [ 3 ] , V_2 -> V_35 + F_9 ( V_7 [ 5 ] - 1 ) ) ;
V_26 =
( V_26 & 0xFFFC19E2UL ) | 0x80000UL |
( unsigned int ) ( ( unsigned int ) V_7 [ 4 ] << 16UL ) ;
F_2 ( V_26 , V_2 -> V_35 + F_8 ( V_7 [ 5 ] - 1 ) ) ;
V_26 = ( V_26 & 0xFFFFF9FD ) | ( V_7 [ 1 ] << 1 ) ;
F_2 ( V_26 , V_2 -> V_35 + F_8 ( V_7 [ 5 ] - 1 ) ) ;
V_26 = ( V_26 & 0xFFFBF9FFUL ) | ( V_7 [ 6 ] << 18 ) ;
F_2 ( V_26 , V_2 -> V_35 + F_8 ( V_7 [ 5 ] - 1 ) ) ;
} else {
F_10 ( V_2 -> V_44 , L_2 ) ;
}
return V_6 -> V_19 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_26 = 0 ;
if ( V_9 -> V_28 == V_27 ) {
switch ( V_7 [ 1 ] ) {
case 0 :
F_2 ( 0x0 , V_9 -> V_14 + V_29 ) ;
break;
case 1 :
F_2 ( 0x0001 , V_9 -> V_14 + V_29 ) ;
break;
case 2 :
F_2 ( 0x0201 , V_9 -> V_14 + V_29 ) ;
break;
default:
F_10 ( V_2 -> V_44 , L_3 ) ;
return - V_21 ;
}
}
if ( V_9 -> V_28 == V_31 ) {
if ( V_7 [ 1 ] == 1 ) {
V_26 = F_5 ( V_9 -> V_14 + V_32 ) ;
V_26 = ( V_26 & 0xFFFFF9FFUL ) | 0x1UL ;
F_2 ( V_26 , V_9 -> V_14 + V_32 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_26 = F_5 ( V_9 -> V_14 + V_32 ) ;
V_26 = V_26 & 0xFFFFF9FEUL ;
F_2 ( V_26 , V_9 -> V_14 + V_32 ) ;
}
}
if ( V_9 -> V_28 == V_42 ) {
V_26 =
F_5 ( V_2 -> V_35 +
F_8 ( V_9 -> V_43 - 1 ) ) ;
if ( V_7 [ 1 ] == 1 ) {
V_26 = ( V_26 & 0xFFFFF9FFUL ) | 0x1UL ;
} else if ( V_7 [ 1 ] == 0 ) {
V_26 = 0 ;
} else if ( V_7 [ 1 ] == 2 ) {
V_26 = ( V_26 & 0xFFFFF9FFUL ) | 0x400 ;
}
F_2 ( V_26 , V_2 -> V_35 +
F_8 ( V_9 -> V_43 - 1 ) ) ;
}
return V_6 -> V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_26 = 0 ;
if ( V_9 -> V_28 == V_27 ) {
V_7 [ 0 ] = F_5 ( V_9 -> V_14 + V_45 ) & 0x1 ;
V_7 [ 1 ] = F_5 ( V_9 -> V_14 + V_46 ) ;
} else if ( V_9 -> V_28 == V_31 ) {
V_7 [ 0 ] = F_5 ( V_9 -> V_14 + V_47 ) & 0x1 ;
V_7 [ 1 ] = F_5 ( V_9 -> V_14 + V_48 ) ;
} else if ( V_9 -> V_28 == V_42 ) {
V_7 [ 0 ] =
F_5 ( V_2 -> V_35 +
F_13 ( V_9 -> V_43 - 1 ) ) ;
V_26 =
F_5 ( V_2 -> V_35 +
F_14 ( V_9 -> V_43 - 1 ) ) ;
V_7 [ 1 ] = ( unsigned char ) ( ( V_26 >> 1 ) & 1 ) ;
V_7 [ 2 ] = ( unsigned char ) ( ( V_26 >> 2 ) & 1 ) ;
V_7 [ 3 ] = ( unsigned char ) ( ( V_26 >> 3 ) & 1 ) ;
V_7 [ 4 ] = ( unsigned char ) ( ( V_26 >> 0 ) & 1 ) ;
} else if ( ( V_9 -> V_28 != V_31 )
&& ( V_9 -> V_28 != V_27 )
&& ( V_9 -> V_28 != V_42 ) ) {
F_10 ( V_2 -> V_44 , L_4 ) ;
}
return V_6 -> V_19 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
* V_7 = V_49 ;
return V_6 -> V_19 ;
}
static void F_16 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_52 , V_53 ;
unsigned int V_54 ;
unsigned int V_55 , V_56 , V_57 , V_58 ;
unsigned int V_59 = 0 ;
V_53 = F_5 ( V_9 -> V_14 + V_18 ) & 0x01 ;
V_52 = F_5 ( V_9 -> V_14 + V_33 ) & 0x01 ;
V_54 = F_5 ( V_9 -> V_14 + V_60 ) & 0x01 ;
V_55 =
F_5 ( V_2 -> V_35 + F_7 ( V_36 ) ) & 0x1 ;
V_56 =
F_5 ( V_2 -> V_35 + F_7 ( V_37 ) ) & 0x1 ;
V_57 =
F_5 ( V_2 -> V_35 + F_7 ( V_38 ) ) & 0x1 ;
V_58 =
F_5 ( V_2 -> V_35 + F_7 ( V_39 ) ) & 0x1 ;
if ( V_53 == 0 && V_52 == 0 && V_54 == 0 && V_55 == 0
&& V_56 == 0 && V_57 == 0 && V_58 == 0 ) {
F_10 ( V_2 -> V_44 , L_5 ) ;
}
if ( V_53 == 1 ) {
V_53 = F_5 ( V_9 -> V_14 + V_18 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_18 ) ;
V_61 =
F_5 ( V_9 -> V_14 + V_62 ) ;
V_61 = V_61 & 0X000FFFF0 ;
F_17 ( V_63 , V_9 -> V_11 , 0 ) ;
F_2 ( V_53 , V_9 -> V_14 + V_18 ) ;
return;
}
if ( V_52 == 1 ) {
V_49 = F_5 ( V_9 -> V_14 + V_64 ) & 0x3 ;
F_2 ( 0x0 , V_9 -> V_14 + V_24 ) ;
F_17 ( V_63 , V_9 -> V_11 , 0 ) ;
}
if ( V_54 == 1 ) {
V_9 -> V_28 = V_31 ;
if ( V_9 -> V_28 ) {
V_59 = F_5 ( V_9 -> V_14 + V_32 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_32 ) ;
F_17 ( V_63 , V_9 -> V_11 , 0 ) ;
F_2 ( V_59 , V_9 -> V_14 + V_32 ) ;
}
}
if ( V_55 == 1 ) {
V_9 -> V_28 = V_42 ;
if ( V_9 -> V_28 ) {
V_59 =
F_5 ( V_2 -> V_35 + F_8 ( V_36 ) ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_8 ( V_36 ) ) ;
F_17 ( V_63 , V_9 -> V_11 , 0 ) ;
F_2 ( V_59 ,
V_2 -> V_35 + F_8 ( V_36 ) ) ;
}
}
if ( V_56 == 1 ) {
V_9 -> V_28 = V_42 ;
if ( V_9 -> V_28 ) {
V_59 =
F_5 ( V_2 -> V_35 + F_8 ( V_37 ) ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_8 ( V_37 ) ) ;
F_17 ( V_63 , V_9 -> V_11 , 0 ) ;
F_2 ( V_59 ,
V_2 -> V_35 + F_8 ( V_37 ) ) ;
}
}
if ( V_57 == 1 ) {
V_9 -> V_28 = V_42 ;
if ( V_9 -> V_28 ) {
V_59 =
F_5 ( V_2 -> V_35 + F_8 ( V_38 ) ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_8 ( V_38 ) ) ;
F_17 ( V_63 , V_9 -> V_11 , 0 ) ;
F_2 ( V_59 ,
V_2 -> V_35 + F_8 ( V_38 ) ) ;
}
}
if ( V_58 == 1 ) {
V_9 -> V_28 = V_42 ;
if ( V_9 -> V_28 ) {
V_59 =
F_5 ( V_2 -> V_35 + F_8 ( V_39 ) ) ;
F_2 ( 0x0 ,
V_2 -> V_35 + F_8 ( V_39 ) ) ;
F_17 ( V_63 , V_9 -> V_11 , 0 ) ;
F_2 ( V_59 ,
V_2 -> V_35 + F_8 ( V_39 ) ) ;
}
}
return;
}
