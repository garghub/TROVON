int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_8 -> V_9 = V_10 ;
if ( V_7 [ 0 ] == V_11 ) {
V_7 [ 2 ] = V_7 [ 2 ] << 4 ;
V_7 [ 3 ] = V_7 [ 3 ] << 4 ;
F_2 ( V_7 [ 2 ] ,
V_8 -> V_12 + V_13 +
V_14 ) ;
F_2 ( V_7 [ 3 ] ,
V_8 -> V_12 + V_13 +
V_15 ) ;
if ( V_7 [ 1 ] == V_16 ) {
F_2 ( 0x4 ,
V_8 -> V_12 + V_13 +
V_17 ) ;
}
else {
F_2 ( 0x6 ,
V_8 -> V_12 + V_13 +
V_17 ) ;
}
}
else {
F_2 ( 0x0 ,
V_8 -> V_12 + V_13 +
V_14 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_13 +
V_15 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_13 +
V_17 ) ;
}
return V_6 -> V_18 ;
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_19 = 0 ;
unsigned int V_20 ;
V_20 = F_4 ( V_6 -> V_21 ) ;
if ( V_20 <= 31 ) {
V_19 =
( unsigned int ) F_5 ( V_8 -> V_12 + V_13 ) ;
* V_7 = ( V_19 >> V_20 ) & 0x1 ;
}
else {
F_6 ( V_2 , L_1 ) ;
return - V_22 ;
}
return V_6 -> V_18 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_23 = V_7 [ 0 ] ;
unsigned int V_24 = 0 ;
unsigned int V_25 ;
V_25 = F_4 ( V_6 -> V_21 ) ;
if ( V_7 [ 1 ] == 0 ) {
* V_7 = ( unsigned int ) F_5 ( V_8 -> V_12 + V_13 ) ;
switch ( V_25 ) {
case 2 :
V_24 = 3 ;
* V_7 = ( * V_7 >> ( 2 * V_23 ) ) & V_24 ;
break;
case 4 :
V_24 = 15 ;
* V_7 = ( * V_7 >> ( 4 * V_23 ) ) & V_24 ;
break;
case 8 :
V_24 = 255 ;
* V_7 = ( * V_7 >> ( 8 * V_23 ) ) & V_24 ;
break;
case 16 :
V_24 = 65535 ;
* V_7 = ( * V_7 >> ( 16 * V_23 ) ) & V_24 ;
break;
case 31 :
break;
default:
F_6 ( V_2 , L_2 ) ;
return - V_22 ;
break;
}
}
else {
if ( V_7 [ 1 ] == 1 ) {
* V_7 = V_26 ;
}
}
return V_6 -> V_18 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_27 = 0 ;
if ( ( V_7 [ 0 ] != 0 ) && ( V_7 [ 0 ] != 1 ) ) {
F_6 ( V_2 ,
L_3 ) ;
return - V_22 ;
}
if ( V_7 [ 0 ] ) {
V_8 -> V_28 = V_11 ;
}
else {
V_8 -> V_28 = V_29 ;
}
if ( V_7 [ 1 ] == V_11 ) {
V_27 = V_27 | 0x1 ;
}
else {
V_27 = V_27 & 0xFFFFFFFE ;
}
if ( V_7 [ 2 ] == V_11 ) {
V_27 = V_27 | 0x2 ;
}
else {
V_27 = V_27 & 0xFFFFFFFD ;
}
F_2 ( V_27 ,
V_8 -> V_12 + V_30 +
V_31 ) ;
V_32 =
F_5 ( V_8 -> V_12 + V_30 +
V_31 ) ;
V_8 -> V_9 = V_10 ;
return V_6 -> V_18 ;
}
int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_33 , V_34 ;
unsigned int V_35 ;
V_35 = F_4 ( V_6 -> V_21 ) ;
if ( V_8 -> V_28 ) {
V_33 =
F_5 ( V_8 -> V_12 + V_30 +
V_36 ) ;
}
else {
V_33 = 0 ;
}
if ( V_7 [ 3 ] == 0 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ( V_7 [ 0 ] << V_35 ) | V_33 ;
F_2 ( V_7 [ 0 ] ,
V_8 -> V_12 + V_30 +
V_36 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
switch ( V_35 ) {
case 2 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 2 *
V_7 [ 2 ] ) ) | V_33 ;
break;
case 4 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 4 *
V_7 [ 2 ] ) ) | V_33 ;
break;
case 8 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 8 *
V_7 [ 2 ] ) ) | V_33 ;
break;
case 16 :
V_7 [ 0 ] =
( V_7 [ 0 ] << ( 16 *
V_7 [ 2 ] ) ) | V_33 ;
break;
case 31 :
V_7 [ 0 ] = V_7 [ 0 ] | V_33 ;
break;
default:
F_6 ( V_2 , L_4 ) ;
return - V_22 ;
}
F_2 ( V_7 [ 0 ] ,
V_8 -> V_12 +
V_30 +
V_36 ) ;
}
else {
F_10 ( L_5 ) ;
}
}
}
else {
if ( V_7 [ 3 ] == 1 ) {
if ( V_7 [ 1 ] == 0 ) {
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x1 ;
V_34 = 1 ;
V_34 = V_34 << V_35 ;
V_33 = V_33 | V_34 ;
V_7 [ 0 ] =
( V_7 [ 0 ] << V_35 ) ^
0xffffffff ;
V_7 [ 0 ] = V_7 [ 0 ] & V_33 ;
F_2 ( V_7 [ 0 ] ,
V_8 -> V_12 +
V_30 +
V_36 ) ;
}
else {
if ( V_7 [ 1 ] == 1 ) {
switch ( V_35 ) {
case 2 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0x3 ;
V_34 = 3 ;
V_34 =
V_34 << 2 * V_7 [ 2 ] ;
V_33 = V_33 | V_34 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 2 *
V_7
[ 2 ] ) ) ^
0xffffffff ) & V_33 ;
break;
case 4 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xf ;
V_34 = 15 ;
V_34 =
V_34 << 4 * V_7 [ 2 ] ;
V_33 = V_33 | V_34 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 4 *
V_7
[ 2 ] ) ) ^
0xffffffff ) & V_33 ;
break;
case 8 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xff ;
V_34 = 255 ;
V_34 =
V_34 << 8 * V_7 [ 2 ] ;
V_33 = V_33 | V_34 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 8 *
V_7
[ 2 ] ) ) ^
0xffffffff ) & V_33 ;
break;
case 16 :
V_7 [ 0 ] = ~ V_7 [ 0 ] & 0xffff ;
V_34 = 65535 ;
V_34 =
V_34 << 16 *
V_7 [ 2 ] ;
V_33 = V_33 | V_34 ;
V_7 [ 0 ] =
( ( V_7 [ 0 ] << ( 16 *
V_7
[ 2 ] ) ) ^
0xffffffff ) & V_33 ;
break;
case 31 :
break;
default:
F_6 ( V_2 ,
L_4 ) ;
return - V_22 ;
}
F_2 ( V_7 [ 0 ] ,
V_8 -> V_12 +
V_30 +
V_36 ) ;
}
else {
F_10 ( L_5 ) ;
}
}
}
else {
F_10 ( L_6 ) ;
return - V_22 ;
}
}
return V_6 -> V_18 ;
}
int F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_33 ;
unsigned int V_35 ;
V_35 = F_4 ( V_6 -> V_21 ) ;
V_33 = V_7 [ 0 ] ;
* V_7 = F_5 ( V_8 -> V_12 + V_30 +
V_36 ) ;
if ( V_33 == 0 ) {
* V_7 = ( * V_7 >> V_35 ) & 0x1 ;
}
else {
if ( V_33 == 1 ) {
switch ( V_35 ) {
case 2 :
* V_7 = ( * V_7 >> ( 2 * V_7 [ 1 ] ) ) & 3 ;
break;
case 4 :
* V_7 = ( * V_7 >> ( 4 * V_7 [ 1 ] ) ) & 15 ;
break;
case 8 :
* V_7 = ( * V_7 >> ( 8 * V_7 [ 1 ] ) ) & 255 ;
break;
case 16 :
* V_7 = ( * V_7 >> ( 16 * V_7 [ 1 ] ) ) & 65535 ;
break;
case 31 :
break;
default:
F_6 ( V_2 , L_4 ) ;
return - V_22 ;
break;
}
}
else {
F_10 ( L_7 ) ;
}
}
return V_6 -> V_18 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_37 = 0 ;
V_8 -> V_9 = V_10 ;
if ( V_7 [ 0 ] == V_38 ) {
V_8 -> V_39 = V_38 ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_40 +
V_41 ) ;
F_2 ( V_7 [ 3 ] ,
V_8 -> V_12 + V_40 +
V_42 ) ;
}
else if ( V_7 [ 0 ] == V_43 ) {
V_37 =
F_5 ( V_8 -> V_12 + V_44 +
V_41 ) ;
V_37 = V_37 & 0xFFFFF9FEUL ;
F_2 ( V_37 , V_8 -> V_12 + V_44 + V_41 ) ;
V_8 -> V_39 = V_43 ;
if ( V_7 [ 1 ] == 1 ) {
F_2 ( 0x02 , V_8 -> V_12 + V_44 + V_41 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_13 +
V_17 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_30 +
V_45 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 +
V_40 +
V_46 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_48 +
V_46 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_49 +
V_46 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_50 +
V_46 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_51 +
V_46 ) ;
}
else {
F_2 ( 0x0 , V_8 -> V_12 + V_44 + V_41 ) ;
}
F_2 ( V_7 [ 2 ] ,
V_8 -> V_12 + V_44 +
V_52 ) ;
F_2 ( V_7 [ 3 ] ,
V_8 -> V_12 + V_44 +
V_42 ) ;
V_37 =
F_5 ( V_8 -> V_12 + V_44 +
V_41 ) ;
V_37 =
( V_37 & 0xFFF719E2UL ) | 2UL << 13UL | 0x10UL ;
F_2 ( V_37 , V_8 -> V_12 + V_44 + V_41 ) ;
}
else if ( V_7 [ 0 ] == V_53 ) {
V_8 -> V_39 = V_53 ;
V_8 -> V_54 = V_7 [ 5 ] ;
V_37 =
F_5 ( V_8 -> V_47 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_41 ) ;
V_37 = V_37 & 0xFFFFF9FEUL ;
F_2 ( V_37 , V_8 -> V_47 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) + V_41 ) ;
F_2 ( V_7 [ 3 ] ,
V_8 -> V_47 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_42 ) ;
V_37 =
( V_37 & 0xFFFC19E2UL ) | 0x80000UL |
( unsigned int ) ( ( unsigned int ) V_7 [ 4 ] << 16UL ) ;
F_2 ( V_37 ,
V_8 -> V_47 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_41 ) ;
V_37 = ( V_37 & 0xFFFFF9FD ) | ( V_7 [ 1 ] << 1 ) ;
F_2 ( V_37 ,
V_8 -> V_47 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_41 ) ;
V_37 = ( V_37 & 0xFFFBF9FFUL ) | ( V_7 [ 6 ] << 18 ) ;
F_2 ( V_37 ,
V_8 -> V_47 + ( ( V_7 [ 5 ] - 1 ) * 0x20 ) +
V_41 ) ;
}
else {
F_10 ( L_8 ) ;
}
return V_6 -> V_18 ;
}
int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_37 = 0 ;
if ( V_8 -> V_39 == V_38 ) {
switch ( V_7 [ 1 ] ) {
case 0 :
F_2 ( 0x0 , V_8 -> V_12 + V_40 + V_41 ) ;
break;
case 1 :
F_2 ( 0x0001 ,
V_8 -> V_12 +
V_40 +
V_41 ) ;
break;
case 2 :
F_2 ( 0x0201 ,
V_8 -> V_12 +
V_40 +
V_41 ) ;
break;
default:
F_10 ( L_6 ) ;
return - V_22 ;
}
}
if ( V_8 -> V_39 == V_43 ) {
if ( V_7 [ 1 ] == 1 ) {
V_37 =
F_5 ( V_8 -> V_12 + V_44 +
V_41 ) ;
V_37 = ( V_37 & 0xFFFFF9FFUL ) | 0x1UL ;
F_2 ( V_37 ,
V_8 -> V_12 + V_44 +
V_41 ) ;
}
else if ( V_7 [ 1 ] == 0 ) {
V_37 =
F_5 ( V_8 -> V_12 + V_44 +
V_41 ) ;
V_37 = V_37 & 0xFFFFF9FEUL ;
F_2 ( V_37 ,
V_8 -> V_12 + V_44 +
V_41 ) ;
}
}
if ( V_8 -> V_39 == V_53 ) {
V_37 =
F_5 ( V_8 -> V_47 + ( ( V_8 -> V_54 -
1 ) * 0x20 ) + V_41 ) ;
if ( V_7 [ 1 ] == 1 ) {
V_37 = ( V_37 & 0xFFFFF9FFUL ) | 0x1UL ;
}
else if ( V_7 [ 1 ] == 0 ) {
V_37 = 0 ;
}
else if ( V_7 [ 1 ] == 2 ) {
V_37 = ( V_37 & 0xFFFFF9FFUL ) | 0x400 ;
}
F_2 ( V_37 ,
V_8 -> V_47 + ( ( V_8 -> V_54 -
1 ) * 0x20 ) + V_41 ) ;
}
return V_6 -> V_18 ;
}
int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned int V_37 = 0 ;
if ( V_8 -> V_39 == V_38 ) {
V_7 [ 0 ] =
F_5 ( V_8 -> V_12 +
V_40 +
V_55 ) & 0x1 ;
V_7 [ 1 ] =
F_5 ( V_8 -> V_12 +
V_40 ) ;
}
else if ( V_8 -> V_39 == V_43 ) {
V_7 [ 0 ] =
F_5 ( V_8 -> V_12 + V_44 +
V_55 ) & 0x1 ;
V_7 [ 1 ] = F_5 ( V_8 -> V_12 + V_44 ) ;
}
else if ( V_8 -> V_39 == V_53 ) {
V_7 [ 0 ] =
F_5 ( V_8 -> V_47 + ( ( V_8 -> V_54 -
1 ) * 0x20 ) +
V_56 ) ;
V_37 =
F_5 ( V_8 -> V_47 + ( ( V_8 -> V_54 -
1 ) * 0x20 ) + V_55 ) ;
V_7 [ 1 ] = ( unsigned char ) ( ( V_37 >> 1 ) & 1 ) ;
V_7 [ 2 ] = ( unsigned char ) ( ( V_37 >> 2 ) & 1 ) ;
V_7 [ 3 ] = ( unsigned char ) ( ( V_37 >> 3 ) & 1 ) ;
V_7 [ 4 ] = ( unsigned char ) ( ( V_37 >> 0 ) & 1 ) ;
}
else if ( ( V_8 -> V_39 != V_43 )
&& ( V_8 -> V_39 != V_38 )
&& ( V_8 -> V_39 != V_53 ) ) {
F_10 ( L_9 ) ;
}
return V_6 -> V_18 ;
}
int F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
* V_7 = V_57 ;
return V_6 -> V_18 ;
}
static void F_16 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
unsigned int V_60 , V_61 ;
unsigned int V_62 ;
unsigned int V_63 , V_64 , V_65 , V_66 ;
unsigned int V_67 = 0 ;
V_61 = F_5 ( V_8 -> V_12 + V_13 +
V_17 ) & 0x01 ;
V_60 = F_5 ( V_8 -> V_12 + V_30 +
V_45 ) & 0x01 ;
V_62 =
F_5 ( V_8 -> V_12 + V_44 +
V_46 ) & 0x01 ;
V_63 = F_5 ( V_8 -> V_47 + V_48 +
V_46 ) & 0x1 ;
V_64 = F_5 ( V_8 -> V_47 + V_49 +
V_46 ) & 0x1 ;
V_65 = F_5 ( V_8 -> V_47 + V_50 +
V_46 ) & 0x1 ;
V_66 = F_5 ( V_8 -> V_47 + V_51 +
V_46 ) & 0x1 ;
if ( V_61 == 0 && V_60 == 0 && V_62 == 0 && V_63 == 0
&& V_64 == 0 && V_65 == 0 && V_66 == 0 ) {
F_10 ( L_10 ) ;
}
if ( V_61 == 1 ) {
V_61 = F_5 ( V_8 -> V_12 + V_13 +
V_17 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_13 +
V_17 ) ;
V_26 =
F_5 ( V_8 -> V_12 + V_13 +
V_68 ) ;
V_26 = V_26 & 0X000FFFF0 ;
F_17 ( V_69 , V_8 -> V_9 , 0 ) ;
F_2 ( V_61 , V_8 -> V_12 + V_13 + V_17 ) ;
return;
}
if ( V_60 == 1 ) {
V_57 =
F_5 ( V_8 -> V_12 + V_30 +
V_70 ) & 0x3 ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_30 +
V_31 ) ;
F_17 ( V_69 , V_8 -> V_9 , 0 ) ;
}
if ( V_62 == 1 ) {
V_8 -> V_39 = V_43 ;
if ( V_8 -> V_39 ) {
V_67 =
F_5 ( V_8 -> V_12 + V_44 +
V_41 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_44 +
V_41 ) ;
F_17 ( V_69 , V_8 -> V_9 , 0 ) ;
F_2 ( V_67 ,
V_8 -> V_12 + V_44 +
V_41 ) ;
}
}
if ( V_63 == 1 ) {
V_8 -> V_39 = V_53 ;
if ( V_8 -> V_39 ) {
V_67 =
F_5 ( V_8 -> V_47 + V_48 +
V_41 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_48 +
V_41 ) ;
F_17 ( V_69 , V_8 -> V_9 , 0 ) ;
F_2 ( V_67 ,
V_8 -> V_47 + V_48 +
V_41 ) ;
}
}
if ( V_64 == 1 ) {
V_8 -> V_39 = V_53 ;
if ( V_8 -> V_39 ) {
V_67 =
F_5 ( V_8 -> V_47 + V_49 +
V_41 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_49 +
V_41 ) ;
F_17 ( V_69 , V_8 -> V_9 , 0 ) ;
F_2 ( V_67 ,
V_8 -> V_47 + V_49 +
V_41 ) ;
}
}
if ( V_65 == 1 ) {
V_8 -> V_39 = V_53 ;
if ( V_8 -> V_39 ) {
V_67 =
F_5 ( V_8 -> V_47 + V_50 +
V_41 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_50 +
V_41 ) ;
F_17 ( V_69 , V_8 -> V_9 , 0 ) ;
F_2 ( V_67 ,
V_8 -> V_47 + V_50 +
V_41 ) ;
}
}
if ( V_66 == 1 ) {
V_8 -> V_39 = V_53 ;
if ( V_8 -> V_39 ) {
V_67 =
F_5 ( V_8 -> V_47 + V_51 +
V_41 ) ;
F_2 ( 0x0 ,
V_8 -> V_47 + V_51 +
V_41 ) ;
F_17 ( V_69 , V_8 -> V_9 , 0 ) ;
F_2 ( V_67 ,
V_8 -> V_47 + V_51 +
V_41 ) ;
}
}
return;
}
int F_18 ( struct V_1 * V_2 )
{
F_2 ( 0x0 , V_8 -> V_12 + V_17 ) ;
F_5 ( V_8 -> V_12 + V_68 ) ;
F_2 ( 0x0 , V_8 -> V_12 + V_14 ) ;
F_2 ( 0x0 , V_8 -> V_12 + V_15 ) ;
V_8 -> V_71 = 0 ;
V_57 = 0 ;
F_2 ( 0x0 , V_8 -> V_12 + V_30 ) ;
F_2 ( 0x0 , V_8 -> V_12 + V_31 ) ;
F_2 ( 0x0 ,
V_8 -> V_12 + V_40 +
V_42 ) ;
F_2 ( 0x0 , V_8 -> V_12 + V_44 ) ;
F_2 ( 0x0 , V_8 -> V_12 + V_44 + V_41 ) ;
F_2 ( 0x0 , V_8 -> V_47 + V_48 + V_41 ) ;
F_2 ( 0x0 , V_8 -> V_47 + V_49 + V_41 ) ;
F_2 ( 0x0 , V_8 -> V_47 + V_50 + V_41 ) ;
F_2 ( 0x0 , V_8 -> V_47 + V_51 + V_41 ) ;
return 0 ;
}
