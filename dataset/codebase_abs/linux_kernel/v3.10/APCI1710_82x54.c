static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned char V_12 ;
unsigned char V_13 ;
unsigned char V_14 ;
unsigned int V_15 ;
unsigned char V_16 ;
unsigned char V_17 ;
unsigned char V_18 ;
unsigned char V_19 ;
unsigned int V_20 = 0 ;
V_11 = V_6 -> V_21 ;
V_12 = ( unsigned char ) F_2 ( V_6 -> V_22 ) ;
V_13 = ( unsigned char ) F_3 ( V_6 -> V_22 ) ;
V_14 = ( unsigned char ) V_7 [ 0 ] ;
V_15 = ( unsigned int ) V_7 [ 1 ] ;
V_16 = ( unsigned char ) V_7 [ 2 ] ;
V_17 = ( unsigned char ) V_7 [ 3 ] ;
V_18 = ( unsigned char ) V_7 [ 4 ] ;
V_19 = ( unsigned char ) V_7 [ 5 ] ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_23 . V_24 [ V_12 ] & 0xFFFF0000UL ) == V_25 ) {
if ( V_13 <= 2 ) {
if ( V_14 <= 5 ) {
if ( ( ( V_13 == 0 ) &&
( V_16 == V_26 ) ) ||
( ( V_13 == 0 ) &&
( V_16 == V_27 ) ) ||
( ( V_13 != 0 ) &&
( ( V_16 == V_26 ) ||
( V_16 == V_28 ) ||
( V_16 == V_27 ) ) ) ) {
if ( ( ( V_16 == V_27 ) &&
( ( V_9 -> V_23 . V_24 [ V_12 ] & 0x0000FFFFUL ) >= 0x3131 ) ) ||
( V_16 != V_27 ) ) {
if ( ( V_17 == 0 ) ||
( V_17 == 1 ) ) {
if ( ( V_18 == 0 ) || ( V_18 == 1 ) ) {
if ( ( V_19 == 0 ) || ( V_19 == 1 ) ) {
if ( ( V_16 == V_27 ) && ( ( V_9 -> V_23 . V_24 [ V_12 ] & 0x0000FFFFUL ) > 0x3131 ) ) {
V_20 = F_4 ( V_9 -> V_23 . V_29 + ( 16 + ( V_13 * 4 ) + ( 64 * V_12 ) ) ) ;
V_20 = ( V_20 >> 16 ) & 1 ;
} else {
V_20 = 1 ;
}
if ( V_20 == 1 ) {
V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_33 = 1 ;
V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_16 = V_16 ;
V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_17 = ~ V_17 & 1 ;
V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_18 = ~ V_18 & 1 ;
V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_19 = V_19 ;
if ( V_16 == V_27 ) {
V_16 = 2 ;
}
V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_34 = ( unsigned int ) ( ( ( V_19 << 0 ) & 0x1 ) | ( ( V_17 << 1 ) & 0x2 ) | ( ( ( ~ V_18 & 1 ) << 2 ) & 0x4 ) | ( ( V_16 << 4 ) & 0x30 ) ) ;
F_5 ( V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_34 , V_9 -> V_23 . V_29 + 32 + ( V_13 * 4 ) + ( 64 * V_12 ) ) ;
F_5 ( ( unsigned int ) V_14 , V_9 -> V_23 . V_29 + 16 + ( V_13 * 4 ) + ( 64 * V_12 ) ) ;
F_5 ( V_15 , V_9 -> V_23 . V_29 + 0 + ( V_13 * 4 ) + ( 64 * V_12 ) ) ;
}
else {
V_11 = - 6 ;
}
}
else {
F_6 ( L_1 ) ;
V_11 = - 9 ;
}
}
else {
F_6 ( L_2 ) ;
V_11 = - 8 ;
}
}
else {
F_6 ( L_3 ) ;
V_11 = - 7 ;
}
} else {
F_6 ( L_4 ) ;
V_11 = - 6 ;
}
} else {
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
V_11 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned char V_12 , V_35 ;
unsigned int * V_36 ;
V_12 = F_2 ( V_6 -> V_22 ) ;
V_35 = F_3 ( V_6 -> V_22 ) ;
V_36 = ( unsigned int * ) V_7 ;
V_11 = V_6 -> V_21 ;
switch ( V_35 ) {
case V_37 :
V_7 [ 0 ] = V_9 -> V_38 . V_39 [ V_9 -> V_38 . V_40 ] . V_41 ;
V_7 [ 1 ] = V_9 -> V_38 . V_39 [ V_9 -> V_38 . V_40 ] . V_42 ;
V_7 [ 2 ] = V_9 -> V_38 . V_39 [ V_9 -> V_38 . V_40 ] . V_43 ;
V_9 -> V_38 . V_40 = ( V_9 -> V_38 . V_40 + 1 ) % V_44 ;
break;
case V_45 :
if ( V_12 < 4 ) {
if ( ( V_9 -> V_23 . V_24 [ V_12 ] & 0xFFFF0000UL ) == V_25 ) {
if ( V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ 0 ] . V_33 == 1 ) {
if ( V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ 1 ] . V_33 == 1 ) {
if ( V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ 2 ] . V_33 == 1 ) {
F_5 ( 0x17 , V_9 -> V_23 . V_29 + 12 + ( 64 * V_12 ) ) ;
V_36 [ 0 ] = F_4 ( V_9 -> V_23 . V_29 + 0 + ( 64 * V_12 ) ) ;
V_36 [ 1 ] = F_4 ( V_9 -> V_23 . V_29 + 4 + ( 64 * V_12 ) ) ;
V_36 [ 2 ] = F_4 ( V_9 -> V_23 . V_29 + 8 + ( 64 * V_12 ) ) ;
} else {
F_6 ( L_9 ) ;
V_11 = - 6 ;
}
} else {
F_6 ( L_10 ) ;
V_11 = - 5 ;
}
} else {
F_6 ( L_11 ) ;
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
}
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned char V_12 ,
unsigned char V_13 ,
unsigned int * V_46 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_23 .
V_24 [ V_12 ] &
0xFFFF0000UL ) == V_25 ) {
if ( V_13 <= 2 ) {
if ( V_9 ->
V_30 [ V_12 ] .
V_31 .
V_32 [ V_13 ] .
V_33 == 1 ) {
F_5 ( ( 2 << V_13 ) | 0xD0 ,
V_9 -> V_23 .
V_29 + 12 +
( 64 * V_12 ) ) ;
* V_46 =
F_4 ( V_9 -> V_23 .
V_29 + ( V_13 * 4 ) +
( 64 * V_12 ) ) ;
} else {
F_6 ( L_12 ) ;
V_11 = - 5 ;
}
} else {
F_6 ( L_6 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned char V_12 ,
unsigned char V_13 ,
unsigned char * V_47 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_48 ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_23 . V_24 [ V_12 ] & 0xFFFF0000UL ) == V_25 ) {
if ( V_13 <= 2 ) {
if ( V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_33 == 1 ) {
F_5 ( ( 2 << V_13 ) | 0xE0 , V_9 -> V_23 . V_29 + 12 + ( 64 * V_12 ) ) ;
V_48 = F_4 ( V_9 -> V_23 . V_29 + 16 + ( V_13 * 4 ) + ( 64 * V_12 ) ) ;
* V_47 = ( unsigned char ) ( ( ( V_48 >> 7 ) & 1 ) ^ V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_18 ) ;
} else {
F_6 ( L_12 ) ;
V_11 = - 5 ;
}
} else {
F_6 ( L_6 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 4 ;
}
} else {
F_6 ( L_8 ) ;
V_11 = - 2 ;
}
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned char V_12 ,
unsigned char V_13 ,
unsigned char * V_49 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
unsigned int V_48 ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_23 . V_24 [ V_12 ] & 0xFFFF0000UL ) == V_25 ) {
if ( V_13 <= 2 ) {
if ( V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_33 == 1 ) {
F_5 ( ( 2 << V_13 ) | 0xE0 , V_9 -> V_23 . V_29 + 12 + ( 64 * V_12 ) ) ;
V_48 = F_4 ( V_9 -> V_23 . V_29 + 16 + ( V_13 * 4 ) + ( 64 * V_12 ) ) ;
* V_49 = ( unsigned char ) ( ( V_48 ) >> 8 ) & 1 ;
F_11 ( L_13 , * V_49 ) ;
} else {
V_11 = - 5 ;
}
} else {
V_11 = - 3 ;
}
} else {
V_11 = - 4 ;
}
} else {
V_11 = - 2 ;
}
return V_11 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned char V_12 ,
unsigned char V_13 ,
unsigned int V_50 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_11 = 0 ;
if ( V_12 < 4 ) {
if ( ( V_9 -> V_23 . V_24 [ V_12 ] & 0xFFFF0000UL ) == V_25 ) {
if ( V_13 <= 2 ) {
if ( V_9 -> V_30 [ V_12 ] . V_31 . V_32 [ V_13 ] . V_33 == 1 ) {
F_5 ( V_50 , V_9 -> V_23 . V_29 + ( V_13 * 4 ) + ( 64 * V_12 ) ) ;
} else {
F_6 ( L_12 ) ;
V_11 = - 5 ;
}
} else {
F_6 ( L_6 ) ;
V_11 = - 3 ;
}
} else {
F_6 ( L_7 ) ;
V_11 = - 4 ;
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
unsigned char V_51 ;
int V_11 = 0 ;
V_51 = V_7 [ 0 ] ;
F_11 ( L_14 ) ;
switch ( V_51 ) {
case V_52 :
V_11 = F_8 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_22 ) ,
( unsigned char ) F_3 ( V_6 -> V_22 ) ,
( unsigned int * ) & V_7 [ 0 ] ) ;
break;
case V_53 :
V_11 = F_9 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_22 ) ,
( unsigned char ) F_3 ( V_6 -> V_22 ) ,
( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_54 :
V_11 = F_10 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_22 ) ,
( unsigned char ) F_3 ( V_6 -> V_22 ) ,
( unsigned char * ) & V_7 [ 0 ] ) ;
break;
case V_55 :
V_11 = F_12 ( V_2 ,
( unsigned char ) F_2 ( V_6 -> V_22 ) ,
( unsigned char ) F_3 ( V_6 -> V_22 ) ,
( unsigned int ) V_7 [ 1 ] ) ;
break;
default:
F_11 ( L_15 ) ;
V_11 = - 1 ;
}
if ( V_11 >= 0 )
V_11 = V_6 -> V_21 ;
return V_11 ;
}
