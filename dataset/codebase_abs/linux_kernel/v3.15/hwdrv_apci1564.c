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
V_7 [ 1 ] = F_4 ( V_9 -> V_14 + V_20 ) ;
return V_6 -> V_19 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_21 = 0 ;
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_6 ( V_2 ,
L_1 ) ;
return - V_22 ;
}
if ( V_7 [ 0 ] )
V_9 -> V_23 = V_13 ;
else
V_9 -> V_23 = V_24 ;
if ( V_7 [ 1 ] == V_13 )
V_21 = V_21 | 0x1 ;
else
V_21 = V_21 & 0xFFFFFFFE ;
if ( V_7 [ 2 ] == V_13 )
V_21 = V_21 | 0x2 ;
else
V_21 = V_21 & 0xFFFFFFFD ;
F_2 ( V_21 , V_9 -> V_14 + V_25 ) ;
V_26 = F_4 ( V_9 -> V_14 + V_25 ) ;
V_9 -> V_11 = V_12 ;
return V_6 -> V_19 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_4 -> V_27 = F_4 ( V_9 -> V_14 + V_28 ) ;
if ( F_8 ( V_4 , V_7 ) )
F_2 ( V_4 -> V_27 , V_9 -> V_14 + V_28 ) ;
V_7 [ 1 ] = V_4 -> V_27 ;
return V_6 -> V_19 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_29 = 0 ;
V_9 -> V_11 = V_12 ;
if ( V_7 [ 0 ] == V_30 ) {
V_9 -> V_31 = V_30 ;
F_2 ( 0x0 , V_9 -> V_14 + V_32 ) ;
F_2 ( V_7 [ 3 ] , V_9 -> V_14 + V_33 ) ;
} else if ( V_7 [ 0 ] == V_34 ) {
V_29 = F_4 ( V_9 -> V_14 + V_35 ) ;
V_29 = V_29 & 0xFFFFF9FEUL ;
F_2 ( V_29 , V_9 -> V_14 + V_35 ) ;
V_9 -> V_31 = V_34 ;
if ( V_7 [ 1 ] == 1 ) {
F_2 ( 0x02 , V_9 -> V_14 + V_35 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_18 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_36 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_37 ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_10 ( V_39 ) ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_10 ( V_40 ) ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_10 ( V_41 ) ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_10 ( V_42 ) ) ;
} else {
F_2 ( 0x0 , V_9 -> V_14 + V_35 ) ;
}
F_2 ( V_7 [ 2 ] , V_9 -> V_14 + V_43 ) ;
F_2 ( V_7 [ 3 ] , V_9 -> V_14 + V_44 ) ;
V_29 = F_4 ( V_9 -> V_14 + V_35 ) ;
V_29 = ( V_29 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_2 ( V_29 , V_9 -> V_14 + V_35 ) ;
} else if ( V_7 [ 0 ] == V_45 ) {
V_9 -> V_31 = V_45 ;
V_9 -> V_46 = V_7 [ 5 ] ;
V_29 = F_4 ( V_9 -> V_38 + F_11 ( V_7 [ 5 ] - 1 ) ) ;
V_29 = V_29 & 0xFFFFF9FEUL ;
F_2 ( V_29 , V_9 -> V_38 + F_11 ( V_7 [ 5 ] - 1 ) ) ;
F_2 ( V_7 [ 3 ] , V_9 -> V_38 + F_12 ( V_7 [ 5 ] - 1 ) ) ;
V_29 =
( V_29 & 0xFFFC19E2UL ) | 0x80000UL |
( unsigned int ) ( ( unsigned int ) V_7 [ 4 ] << 16UL ) ;
F_2 ( V_29 , V_9 -> V_38 + F_11 ( V_7 [ 5 ] - 1 ) ) ;
V_29 = ( V_29 & 0xFFFFF9FD ) | ( V_7 [ 1 ] << 1 ) ;
F_2 ( V_29 , V_9 -> V_38 + F_11 ( V_7 [ 5 ] - 1 ) ) ;
V_29 = ( V_29 & 0xFFFBF9FFUL ) | ( V_7 [ 6 ] << 18 ) ;
F_2 ( V_29 , V_9 -> V_38 + F_11 ( V_7 [ 5 ] - 1 ) ) ;
} else {
F_13 ( V_2 -> V_47 , L_2 ) ;
}
return V_6 -> V_19 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_29 = 0 ;
if ( V_9 -> V_31 == V_30 ) {
switch ( V_7 [ 1 ] ) {
case 0 :
F_2 ( 0x0 , V_9 -> V_14 + V_32 ) ;
break;
case 1 :
F_2 ( 0x0001 , V_9 -> V_14 + V_32 ) ;
break;
case 2 :
F_2 ( 0x0201 , V_9 -> V_14 + V_32 ) ;
break;
default:
F_13 ( V_2 -> V_47 , L_3 ) ;
return - V_22 ;
}
}
if ( V_9 -> V_31 == V_34 ) {
if ( V_7 [ 1 ] == 1 ) {
V_29 = F_4 ( V_9 -> V_14 + V_35 ) ;
V_29 = ( V_29 & 0xFFFFF9FFUL ) | 0x1UL ;
F_2 ( V_29 , V_9 -> V_14 + V_35 ) ;
} else if ( V_7 [ 1 ] == 0 ) {
V_29 = F_4 ( V_9 -> V_14 + V_35 ) ;
V_29 = V_29 & 0xFFFFF9FEUL ;
F_2 ( V_29 , V_9 -> V_14 + V_35 ) ;
}
}
if ( V_9 -> V_31 == V_45 ) {
V_29 =
F_4 ( V_9 -> V_38 +
F_11 ( V_9 -> V_46 - 1 ) ) ;
if ( V_7 [ 1 ] == 1 ) {
V_29 = ( V_29 & 0xFFFFF9FFUL ) | 0x1UL ;
} else if ( V_7 [ 1 ] == 0 ) {
V_29 = 0 ;
} else if ( V_7 [ 1 ] == 2 ) {
V_29 = ( V_29 & 0xFFFFF9FFUL ) | 0x400 ;
}
F_2 ( V_29 ,
V_9 -> V_38 +
F_11 ( V_9 -> V_46 - 1 ) ) ;
}
return V_6 -> V_19 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_29 = 0 ;
if ( V_9 -> V_31 == V_30 ) {
V_7 [ 0 ] = F_4 ( V_9 -> V_14 + V_48 ) & 0x1 ;
V_7 [ 1 ] = F_4 ( V_9 -> V_14 + V_49 ) ;
} else if ( V_9 -> V_31 == V_34 ) {
V_7 [ 0 ] = F_4 ( V_9 -> V_14 + V_50 ) & 0x1 ;
V_7 [ 1 ] = F_4 ( V_9 -> V_14 + V_51 ) ;
} else if ( V_9 -> V_31 == V_45 ) {
V_7 [ 0 ] =
F_4 ( V_9 -> V_38 +
F_16 ( V_9 -> V_46 - 1 ) ) ;
V_29 =
F_4 ( V_9 -> V_38 +
F_17 ( V_9 -> V_46 - 1 ) ) ;
V_7 [ 1 ] = ( unsigned char ) ( ( V_29 >> 1 ) & 1 ) ;
V_7 [ 2 ] = ( unsigned char ) ( ( V_29 >> 2 ) & 1 ) ;
V_7 [ 3 ] = ( unsigned char ) ( ( V_29 >> 3 ) & 1 ) ;
V_7 [ 4 ] = ( unsigned char ) ( ( V_29 >> 0 ) & 1 ) ;
} else if ( ( V_9 -> V_31 != V_34 )
&& ( V_9 -> V_31 != V_30 )
&& ( V_9 -> V_31 != V_45 ) ) {
F_13 ( V_2 -> V_47 , L_4 ) ;
}
return V_6 -> V_19 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
* V_7 = V_52 ;
return V_6 -> V_19 ;
}
static void F_19 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_55 , V_56 ;
unsigned int V_57 ;
unsigned int V_58 , V_59 , V_60 , V_61 ;
unsigned int V_62 = 0 ;
V_56 = F_4 ( V_9 -> V_14 + V_18 ) & 0x01 ;
V_55 = F_4 ( V_9 -> V_14 + V_36 ) & 0x01 ;
V_57 = F_4 ( V_9 -> V_14 + V_63 ) & 0x01 ;
V_58 =
F_4 ( V_9 -> V_38 + F_10 ( V_39 ) ) & 0x1 ;
V_59 =
F_4 ( V_9 -> V_38 + F_10 ( V_40 ) ) & 0x1 ;
V_60 =
F_4 ( V_9 -> V_38 + F_10 ( V_41 ) ) & 0x1 ;
V_61 =
F_4 ( V_9 -> V_38 + F_10 ( V_42 ) ) & 0x1 ;
if ( V_56 == 0 && V_55 == 0 && V_57 == 0 && V_58 == 0
&& V_59 == 0 && V_60 == 0 && V_61 == 0 ) {
F_13 ( V_2 -> V_47 , L_5 ) ;
}
if ( V_56 == 1 ) {
V_56 = F_4 ( V_9 -> V_14 + V_18 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_18 ) ;
V_64 =
F_4 ( V_9 -> V_14 + V_65 ) ;
V_64 = V_64 & 0X000FFFF0 ;
F_20 ( V_66 , V_9 -> V_11 , 0 ) ;
F_2 ( V_56 , V_9 -> V_14 + V_18 ) ;
return;
}
if ( V_55 == 1 ) {
V_52 = F_4 ( V_9 -> V_14 + V_67 ) & 0x3 ;
F_2 ( 0x0 , V_9 -> V_14 + V_25 ) ;
F_20 ( V_66 , V_9 -> V_11 , 0 ) ;
}
if ( V_57 == 1 ) {
V_9 -> V_31 = V_34 ;
if ( V_9 -> V_31 ) {
V_62 = F_4 ( V_9 -> V_14 + V_35 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_35 ) ;
F_20 ( V_66 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 , V_9 -> V_14 + V_35 ) ;
}
}
if ( V_58 == 1 ) {
V_9 -> V_31 = V_45 ;
if ( V_9 -> V_31 ) {
V_62 =
F_4 ( V_9 -> V_38 + F_11 ( V_39 ) ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_11 ( V_39 ) ) ;
F_20 ( V_66 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_38 + F_11 ( V_39 ) ) ;
}
}
if ( V_59 == 1 ) {
V_9 -> V_31 = V_45 ;
if ( V_9 -> V_31 ) {
V_62 =
F_4 ( V_9 -> V_38 + F_11 ( V_40 ) ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_11 ( V_40 ) ) ;
F_20 ( V_66 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_38 + F_11 ( V_40 ) ) ;
}
}
if ( V_60 == 1 ) {
V_9 -> V_31 = V_45 ;
if ( V_9 -> V_31 ) {
V_62 =
F_4 ( V_9 -> V_38 + F_11 ( V_41 ) ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_11 ( V_41 ) ) ;
F_20 ( V_66 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_38 + F_11 ( V_41 ) ) ;
}
}
if ( V_61 == 1 ) {
V_9 -> V_31 = V_45 ;
if ( V_9 -> V_31 ) {
V_62 =
F_4 ( V_9 -> V_38 + F_11 ( V_42 ) ) ;
F_2 ( 0x0 ,
V_9 -> V_38 + F_11 ( V_42 ) ) ;
F_20 ( V_66 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_38 + F_11 ( V_42 ) ) ;
}
}
return;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_2 ( 0x0 , V_9 -> V_14 + V_18 ) ;
F_4 ( V_9 -> V_14 + V_65 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_15 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_16 ) ;
V_9 -> V_68 = 0 ;
V_52 = 0 ;
F_2 ( 0x0 , V_9 -> V_14 + V_28 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_25 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_33 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_51 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_35 ) ;
F_2 ( 0x0 , V_9 -> V_38 + F_11 ( V_39 ) ) ;
F_2 ( 0x0 , V_9 -> V_38 + F_11 ( V_40 ) ) ;
F_2 ( 0x0 , V_9 -> V_38 + F_11 ( V_41 ) ) ;
F_2 ( 0x0 , V_9 -> V_38 + F_11 ( V_42 ) ) ;
return 0 ;
}
