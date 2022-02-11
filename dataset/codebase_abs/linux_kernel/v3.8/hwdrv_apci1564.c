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
F_2 ( V_7 [ 2 ] ,
V_9 -> V_14 + V_15 +
V_16 ) ;
F_2 ( V_7 [ 3 ] ,
V_9 -> V_14 + V_15 +
V_17 ) ;
if ( V_7 [ 1 ] == V_18 ) {
F_2 ( 0x4 ,
V_9 -> V_14 + V_15 +
V_19 ) ;
}
else {
F_2 ( 0x6 ,
V_9 -> V_14 + V_15 +
V_19 ) ;
}
}
else {
F_2 ( 0x0 ,
V_9 -> V_14 + V_15 +
V_16 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_15 +
V_17 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_15 +
V_19 ) ;
}
return V_6 -> V_20 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
V_7 [ 1 ] = F_4 ( V_9 -> V_14 + V_15 ) ;
return V_6 -> V_20 ;
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
if ( V_7 [ 0 ] ) {
V_9 -> V_23 = V_13 ;
}
else {
V_9 -> V_23 = V_24 ;
}
if ( V_7 [ 1 ] == V_13 ) {
V_21 = V_21 | 0x1 ;
}
else {
V_21 = V_21 & 0xFFFFFFFE ;
}
if ( V_7 [ 2 ] == V_13 ) {
V_21 = V_21 | 0x2 ;
}
else {
V_21 = V_21 & 0xFFFFFFFD ;
}
F_2 ( V_21 ,
V_9 -> V_14 + V_25 +
V_26 ) ;
V_27 =
F_4 ( V_9 -> V_14 + V_25 +
V_26 ) ;
V_9 -> V_11 = V_12 ;
return V_6 -> V_20 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_28 = V_7 [ 0 ] ;
unsigned int V_29 = V_7 [ 1 ] ;
V_4 -> V_30 = F_4 ( V_9 -> V_14 + V_25 +
V_31 ) ;
if ( V_28 ) {
V_4 -> V_30 &= ~ V_28 ;
V_4 -> V_30 |= ( V_29 & V_28 ) ;
F_2 ( V_4 -> V_30 , V_9 -> V_14 + V_25 +
V_31 ) ;
}
V_7 [ 1 ] = V_4 -> V_30 ;
return V_6 -> V_20 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_32 = 0 ;
V_9 -> V_11 = V_12 ;
if ( V_7 [ 0 ] == V_33 ) {
V_9 -> V_34 = V_33 ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_35 +
V_36 ) ;
F_2 ( V_7 [ 3 ] ,
V_9 -> V_14 + V_35 +
V_37 ) ;
}
else if ( V_7 [ 0 ] == V_38 ) {
V_32 =
F_4 ( V_9 -> V_14 + V_39 +
V_36 ) ;
V_32 = V_32 & 0xFFFFF9FEUL ;
F_2 ( V_32 , V_9 -> V_14 + V_39 + V_36 ) ;
V_9 -> V_34 = V_38 ;
if ( V_7 [ 1 ] == 1 ) {
F_2 ( 0x02 , V_9 -> V_14 + V_39 + V_36 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_15 +
V_19 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_25 +
V_40 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 +
V_35 +
V_41 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_43 +
V_41 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_44 +
V_41 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_45 +
V_41 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_46 +
V_41 ) ;
}
else {
F_2 ( 0x0 , V_9 -> V_14 + V_39 + V_36 ) ;
}
F_2 ( V_7 [ 2 ] ,
V_9 -> V_14 + V_39 +
V_47 ) ;
F_2 ( V_7 [ 3 ] ,
V_9 -> V_14 + V_39 +
V_37 ) ;
V_32 =
F_4 ( V_9 -> V_14 + V_39 +
V_36 ) ;
V_32 =
( V_32 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_2 ( V_32 , V_9 -> V_14 + V_39 + V_36 ) ;
}
else if ( V_7 [ 0 ] == V_48 ) {
V_9 -> V_34 = V_48 ;
V_9 -> V_49 = V_7 [ 5 ] ;
V_32 =
F_4 ( V_9 -> V_42 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_36 ) ;
V_32 = V_32 & 0xFFFFF9FEUL ;
F_2 ( V_32 , V_9 -> V_42 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) + V_36 ) ;
F_2 ( V_7 [ 3 ] ,
V_9 -> V_42 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_37 ) ;
V_32 =
( V_32 & 0xFFFC19E2UL ) | 0x80000UL |
( unsigned int ) ( ( unsigned int ) V_7 [ 4 ] << 16UL ) ;
F_2 ( V_32 ,
V_9 -> V_42 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_36 ) ;
V_32 = ( V_32 & 0xFFFFF9FD ) | ( V_7 [ 1 ] << 1 ) ;
F_2 ( V_32 ,
V_9 -> V_42 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_36 ) ;
V_32 = ( V_32 & 0xFFFBF9FFUL ) | ( V_7 [ 6 ] << 18 ) ;
F_2 ( V_32 ,
V_9 -> V_42 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_36 ) ;
}
else {
F_9 ( L_2 ) ;
}
return V_6 -> V_20 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_32 = 0 ;
if ( V_9 -> V_34 == V_33 ) {
switch ( V_7 [ 1 ] ) {
case 0 :
F_2 ( 0x0 , V_9 -> V_14 + V_35 + V_36 ) ;
break;
case 1 :
F_2 ( 0x0001 ,
V_9 -> V_14 +
V_35 +
V_36 ) ;
break;
case 2 :
F_2 ( 0x0201 ,
V_9 -> V_14 +
V_35 +
V_36 ) ;
break;
default:
F_9 ( L_3 ) ;
return - V_22 ;
}
}
if ( V_9 -> V_34 == V_38 ) {
if ( V_7 [ 1 ] == 1 ) {
V_32 =
F_4 ( V_9 -> V_14 + V_39 +
V_36 ) ;
V_32 = ( V_32 & 0xFFFFF9FFUL ) | 0x1UL ;
F_2 ( V_32 ,
V_9 -> V_14 + V_39 +
V_36 ) ;
}
else if ( V_7 [ 1 ] == 0 ) {
V_32 =
F_4 ( V_9 -> V_14 + V_39 +
V_36 ) ;
V_32 = V_32 & 0xFFFFF9FEUL ;
F_2 ( V_32 ,
V_9 -> V_14 + V_39 +
V_36 ) ;
}
}
if ( V_9 -> V_34 == V_48 ) {
V_32 =
F_4 ( V_9 -> V_42 + ( ( V_9 -> V_49 -
1 ) * 0x20 ) + V_36 ) ;
if ( V_7 [ 1 ] == 1 ) {
V_32 = ( V_32 & 0xFFFFF9FFUL ) | 0x1UL ;
}
else if ( V_7 [ 1 ] == 0 ) {
V_32 = 0 ;
}
else if ( V_7 [ 1 ] == 2 ) {
V_32 = ( V_32 & 0xFFFFF9FFUL ) | 0x400 ;
}
F_2 ( V_32 ,
V_9 -> V_42 + ( ( V_9 -> V_49 -
1 ) * 0x20 ) + V_36 ) ;
}
return V_6 -> V_20 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_32 = 0 ;
if ( V_9 -> V_34 == V_33 ) {
V_7 [ 0 ] =
F_4 ( V_9 -> V_14 +
V_35 +
V_50 ) & 0x1 ;
V_7 [ 1 ] =
F_4 ( V_9 -> V_14 +
V_35 ) ;
}
else if ( V_9 -> V_34 == V_38 ) {
V_7 [ 0 ] =
F_4 ( V_9 -> V_14 + V_39 +
V_50 ) & 0x1 ;
V_7 [ 1 ] = F_4 ( V_9 -> V_14 + V_39 ) ;
}
else if ( V_9 -> V_34 == V_48 ) {
V_7 [ 0 ] =
F_4 ( V_9 -> V_42 + ( ( V_9 -> V_49 -
1 ) * 0x20 ) +
V_51 ) ;
V_32 =
F_4 ( V_9 -> V_42 + ( ( V_9 -> V_49 -
1 ) * 0x20 ) + V_50 ) ;
V_7 [ 1 ] = ( unsigned char ) ( ( V_32 >> 1 ) & 1 ) ;
V_7 [ 2 ] = ( unsigned char ) ( ( V_32 >> 2 ) & 1 ) ;
V_7 [ 3 ] = ( unsigned char ) ( ( V_32 >> 3 ) & 1 ) ;
V_7 [ 4 ] = ( unsigned char ) ( ( V_32 >> 0 ) & 1 ) ;
}
else if ( ( V_9 -> V_34 != V_38 )
&& ( V_9 -> V_34 != V_33 )
&& ( V_9 -> V_34 != V_48 ) ) {
F_9 ( L_4 ) ;
}
return V_6 -> V_20 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
* V_7 = V_52 ;
return V_6 -> V_20 ;
}
static void F_13 ( int V_53 , void * V_54 )
{
struct V_1 * V_2 = V_54 ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_55 , V_56 ;
unsigned int V_57 ;
unsigned int V_58 , V_59 , V_60 , V_61 ;
unsigned int V_62 = 0 ;
V_56 = F_4 ( V_9 -> V_14 + V_15 +
V_19 ) & 0x01 ;
V_55 = F_4 ( V_9 -> V_14 + V_25 +
V_40 ) & 0x01 ;
V_57 =
F_4 ( V_9 -> V_14 + V_39 +
V_41 ) & 0x01 ;
V_58 = F_4 ( V_9 -> V_42 + V_43 +
V_41 ) & 0x1 ;
V_59 = F_4 ( V_9 -> V_42 + V_44 +
V_41 ) & 0x1 ;
V_60 = F_4 ( V_9 -> V_42 + V_45 +
V_41 ) & 0x1 ;
V_61 = F_4 ( V_9 -> V_42 + V_46 +
V_41 ) & 0x1 ;
if ( V_56 == 0 && V_55 == 0 && V_57 == 0 && V_58 == 0
&& V_59 == 0 && V_60 == 0 && V_61 == 0 ) {
F_9 ( L_5 ) ;
}
if ( V_56 == 1 ) {
V_56 = F_4 ( V_9 -> V_14 + V_15 +
V_19 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_15 +
V_19 ) ;
V_63 =
F_4 ( V_9 -> V_14 + V_15 +
V_64 ) ;
V_63 = V_63 & 0X000FFFF0 ;
F_14 ( V_65 , V_9 -> V_11 , 0 ) ;
F_2 ( V_56 , V_9 -> V_14 + V_15 + V_19 ) ;
return;
}
if ( V_55 == 1 ) {
V_52 =
F_4 ( V_9 -> V_14 + V_25 +
V_66 ) & 0x3 ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_25 +
V_26 ) ;
F_14 ( V_65 , V_9 -> V_11 , 0 ) ;
}
if ( V_57 == 1 ) {
V_9 -> V_34 = V_38 ;
if ( V_9 -> V_34 ) {
V_62 =
F_4 ( V_9 -> V_14 + V_39 +
V_36 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_39 +
V_36 ) ;
F_14 ( V_65 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_14 + V_39 +
V_36 ) ;
}
}
if ( V_58 == 1 ) {
V_9 -> V_34 = V_48 ;
if ( V_9 -> V_34 ) {
V_62 =
F_4 ( V_9 -> V_42 + V_43 +
V_36 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_43 +
V_36 ) ;
F_14 ( V_65 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_42 + V_43 +
V_36 ) ;
}
}
if ( V_59 == 1 ) {
V_9 -> V_34 = V_48 ;
if ( V_9 -> V_34 ) {
V_62 =
F_4 ( V_9 -> V_42 + V_44 +
V_36 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_44 +
V_36 ) ;
F_14 ( V_65 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_42 + V_44 +
V_36 ) ;
}
}
if ( V_60 == 1 ) {
V_9 -> V_34 = V_48 ;
if ( V_9 -> V_34 ) {
V_62 =
F_4 ( V_9 -> V_42 + V_45 +
V_36 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_45 +
V_36 ) ;
F_14 ( V_65 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_42 + V_45 +
V_36 ) ;
}
}
if ( V_61 == 1 ) {
V_9 -> V_34 = V_48 ;
if ( V_9 -> V_34 ) {
V_62 =
F_4 ( V_9 -> V_42 + V_46 +
V_36 ) ;
F_2 ( 0x0 ,
V_9 -> V_42 + V_46 +
V_36 ) ;
F_14 ( V_65 , V_9 -> V_11 , 0 ) ;
F_2 ( V_62 ,
V_9 -> V_42 + V_46 +
V_36 ) ;
}
}
return;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
F_2 ( 0x0 , V_9 -> V_14 + V_19 ) ;
F_4 ( V_9 -> V_14 + V_64 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_16 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_17 ) ;
V_9 -> V_67 = 0 ;
V_52 = 0 ;
F_2 ( 0x0 , V_9 -> V_14 + V_25 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_26 ) ;
F_2 ( 0x0 ,
V_9 -> V_14 + V_35 +
V_37 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_39 ) ;
F_2 ( 0x0 , V_9 -> V_14 + V_39 + V_36 ) ;
F_2 ( 0x0 , V_9 -> V_42 + V_43 + V_36 ) ;
F_2 ( 0x0 , V_9 -> V_42 + V_44 + V_36 ) ;
F_2 ( 0x0 , V_9 -> V_42 + V_45 + V_36 ) ;
F_2 ( 0x0 , V_9 -> V_42 + V_46 + V_36 ) ;
return 0 ;
}
