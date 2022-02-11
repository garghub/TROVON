int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = 0 ;
unsigned char V_9 ;
unsigned char V_10 ;
unsigned char V_11 ;
unsigned int V_12 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned char V_15 ;
unsigned char V_16 ;
unsigned int V_17 = 0 ;
V_8 = V_6 -> V_18 ;
V_9 = ( unsigned char ) F_2 ( V_6 -> V_19 ) ;
V_10 = ( unsigned char ) F_3 ( V_6 -> V_19 ) ;
V_11 = ( unsigned char ) V_7 [ 0 ] ;
V_12 = ( unsigned int ) V_7 [ 1 ] ;
V_13 = ( unsigned char ) V_7 [ 2 ] ;
V_14 = ( unsigned char ) V_7 [ 3 ] ;
V_15 = ( unsigned char ) V_7 [ 4 ] ;
V_16 = ( unsigned char ) V_7 [ 5 ] ;
if ( V_9 < 4 ) {
if ( ( V_20 -> V_21 . V_22 [ V_9 ] & 0xFFFF0000UL ) == V_23 ) {
if ( V_10 <= 2 ) {
if ( V_11 <= 5 ) {
if ( ( ( V_10 == 0 ) &&
( V_13 == V_24 ) ) ||
( ( V_10 == 0 ) &&
( V_13 == V_25 ) ) ||
( ( V_10 != 0 ) &&
( ( V_13 == V_24 ) ||
( V_13 == V_26 ) ||
( V_13 == V_25 ) ) ) ) {
if ( ( ( V_13 == V_25 ) &&
( ( V_20 -> V_21 . V_22 [ V_9 ] & 0x0000FFFFUL ) >= 0x3131 ) ) ||
( V_13 != V_25 ) ) {
if ( ( V_14 == 0 ) ||
( V_14 == 1 ) ) {
if ( ( V_15 == 0 ) || ( V_15 == 1 ) ) {
if ( ( V_16 == 0 ) || ( V_16 == 1 ) ) {
if ( ( V_13 == V_25 ) && ( ( V_20 -> V_21 . V_22 [ V_9 ] & 0x0000FFFFUL ) > 0x3131 ) ) {
V_17 = F_4 ( V_20 -> V_21 . V_27 + ( 16 + ( V_10 * 4 ) + ( 64 * V_9 ) ) ) ;
V_17 = ( V_17 >> 16 ) & 1 ;
} else {
V_17 = 1 ;
}
if ( V_17 == 1 ) {
V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_31 = 1 ;
V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_13 = V_13 ;
V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_14 = ~ V_14 & 1 ;
V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_15 = ~ V_15 & 1 ;
V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_16 = V_16 ;
if ( V_13 == V_25 ) {
V_13 = 2 ;
}
V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_32 = ( unsigned int ) ( ( ( V_16 << 0 ) & 0x1 ) | ( ( V_14 << 1 ) & 0x2 ) | ( ( ( ~ V_15 & 1 ) << 2 ) & 0x4 ) | ( ( V_13 << 4 ) & 0x30 ) ) ;
F_5 ( V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_32 , V_20 -> V_21 . V_27 + 32 + ( V_10 * 4 ) + ( 64 * V_9 ) ) ;
F_5 ( ( unsigned int ) V_11 , V_20 -> V_21 . V_27 + 16 + ( V_10 * 4 ) + ( 64 * V_9 ) ) ;
F_5 ( V_12 , V_20 -> V_21 . V_27 + 0 + ( V_10 * 4 ) + ( 64 * V_9 ) ) ;
}
else {
V_8 = - 6 ;
}
}
else {
F_6 ( L_1 ) ;
V_8 = - 9 ;
}
}
else {
F_6 ( L_2 ) ;
V_8 = - 8 ;
}
}
else {
F_6 ( L_3 ) ;
V_8 = - 7 ;
}
} else {
F_6 ( L_4 ) ;
V_8 = - 6 ;
}
} else {
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
V_8 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
unsigned char V_33 ;
int V_8 = 0 ;
V_33 = V_7 [ 0 ] ;
F_8 ( L_9 ) ;
switch ( V_33 ) {
case V_34 :
V_8 = F_9 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_19 ) ,
( unsigned char ) F_3 ( V_6 -> V_19 ) ,
( unsigned int * ) & V_7 [ 0 ] ) ;
break;
case V_35 :
V_8 = F_10 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_19 ) ,
( unsigned char ) F_3 ( V_6 -> V_19 ) ,
( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_36 :
V_8 = F_11 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_19 ) ,
( unsigned char ) F_3 ( V_6 -> V_19 ) ,
( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_37 :
V_8 = F_12 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_19 ) ,
( unsigned char ) F_3 ( V_6 -> V_19 ) ,
( unsigned int ) V_7 [ 1 ] ) ;
break;
default:
F_8 ( L_10 ) ;
V_8 = - 1 ;
}
if ( V_8 >= 0 )
V_8 = V_6 -> V_18 ;
return V_8 ;
}
int F_9 ( struct V_1 * V_2 ,
unsigned char V_9 , unsigned char V_10 ,
unsigned int * V_38 )
{
int V_8 = 0 ;
if ( V_9 < 4 ) {
if ( ( V_20 -> V_21 .
V_22 [ V_9 ] &
0xFFFF0000UL ) == V_23 ) {
if ( V_10 <= 2 ) {
if ( V_20 ->
V_28 [ V_9 ] .
V_29 .
V_30 [ V_10 ] .
V_31 == 1 ) {
F_5 ( ( 2 << V_10 ) | 0xD0 ,
V_20 -> V_21 .
V_27 + 12 +
( 64 * V_9 ) ) ;
* V_38 =
F_4 ( V_20 -> V_21 .
V_27 + ( V_10 * 4 ) +
( 64 * V_9 ) ) ;
} else {
F_6 ( L_11 ) ;
V_8 = - 5 ;
}
} else {
F_6 ( L_6 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_10 ( struct V_1 * V_2 ,
unsigned char V_9 , unsigned char V_10 ,
unsigned char * V_39 )
{
int V_8 = 0 ;
unsigned int V_40 ;
if ( V_9 < 4 ) {
if ( ( V_20 -> V_21 . V_22 [ V_9 ] & 0xFFFF0000UL ) == V_23 ) {
if ( V_10 <= 2 ) {
if ( V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_31 == 1 ) {
F_5 ( ( 2 << V_10 ) | 0xE0 , V_20 -> V_21 . V_27 + 12 + ( 64 * V_9 ) ) ;
V_40 = F_4 ( V_20 -> V_21 . V_27 + 16 + ( V_10 * 4 ) + ( 64 * V_9 ) ) ;
* V_39 = ( unsigned char ) ( ( ( V_40 >> 7 ) & 1 ) ^ V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_15 ) ;
} else {
F_6 ( L_11 ) ;
V_8 = - 5 ;
}
} else {
F_6 ( L_6 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
int F_11 ( struct V_1 * V_2 ,
unsigned char V_9 , unsigned char V_10 ,
unsigned char * V_41 )
{
int V_8 = 0 ;
unsigned int V_40 ;
if ( V_9 < 4 ) {
if ( ( V_20 -> V_21 . V_22 [ V_9 ] & 0xFFFF0000UL ) == V_23 ) {
if ( V_10 <= 2 ) {
if ( V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_31 == 1 ) {
F_5 ( ( 2 << V_10 ) | 0xE0 , V_20 -> V_21 . V_27 + 12 + ( 64 * V_9 ) ) ;
V_40 = F_4 ( V_20 -> V_21 . V_27 + 16 + ( V_10 * 4 ) + ( 64 * V_9 ) ) ;
* V_41 = ( unsigned char ) ( ( V_40 ) >> 8 ) & 1 ;
F_8 ( L_12 , * V_41 ) ;
} else {
V_8 = - 5 ;
}
} else {
V_8 = - 3 ;
}
} else {
V_8 = - 4 ;
}
} else {
V_8 = - 2 ;
}
return V_8 ;
}
int F_12 ( struct V_1 * V_2 ,
unsigned char V_9 , unsigned char V_10 ,
unsigned int V_42 )
{
int V_8 = 0 ;
if ( V_9 < 4 ) {
if ( ( V_20 -> V_21 . V_22 [ V_9 ] & 0xFFFF0000UL ) == V_23 ) {
if ( V_10 <= 2 ) {
if ( V_20 -> V_28 [ V_9 ] . V_29 . V_30 [ V_10 ] . V_31 == 1 ) {
F_5 ( V_42 , V_20 -> V_21 . V_27 + ( V_10 * 4 ) + ( 64 * V_9 ) ) ;
} else {
F_6 ( L_11 ) ;
V_8 = - 5 ;
}
} else {
F_6 ( L_6 ) ;
V_8 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_8 = - 4 ;
}
} else {
F_6 ( L_8 ) ;
V_8 = - 2 ;
}
return V_8 ;
}
