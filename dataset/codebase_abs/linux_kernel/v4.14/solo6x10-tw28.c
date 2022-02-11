static T_1 F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 ,
T_1 V_4 )
{
if ( F_2 ( V_1 , V_2 ) )
return F_3 ( V_1 , V_5 ,
F_4 ( V_2 ) ,
V_3 ) ;
else
return F_3 ( V_1 , V_5 ,
F_4 ( V_2 ) ,
V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 , int V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_6 )
{
if ( F_2 ( V_1 , V_2 ) )
F_6 ( V_1 , V_5 ,
F_4 ( V_2 ) ,
V_3 , V_6 ) ;
else
F_6 ( V_1 , V_5 ,
F_4 ( V_2 ) ,
V_4 , V_6 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_7 , T_1 V_8 ,
T_1 V_6 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < 5 ; V_9 ++ ) {
T_1 V_10 = F_3 ( V_1 , V_5 , V_7 , V_8 ) ;
if ( V_10 == V_6 )
return;
F_6 ( V_1 , V_5 , V_7 , V_8 , V_6 ) ;
F_8 ( 1 ) ;
}
}
static int F_9 ( struct V_1 * V_1 , T_1 V_11 )
{
T_1 V_12 [ 256 ] ;
int V_9 ;
if ( V_1 -> V_13 == V_14 )
memcpy ( V_12 , V_15 ,
sizeof( V_12 ) ) ;
else
memcpy ( V_12 , V_16 ,
sizeof( V_12 ) ) ;
if ( V_1 -> V_17 == 4 ) {
V_12 [ 0xd2 ] = 0x01 ;
V_12 [ 0xcf ] = 0x00 ;
} else if ( V_1 -> V_17 == 8 ) {
V_12 [ 0xd2 ] = 0x02 ;
if ( V_11 == F_4 ( 1 ) )
V_12 [ 0xcf ] = 0x80 ;
} else if ( V_1 -> V_17 == 16 ) {
V_12 [ 0xd2 ] = 0x03 ;
if ( V_11 == F_4 ( 1 ) )
V_12 [ 0xcf ] = 0x83 ;
else if ( V_11 == F_4 ( 2 ) )
V_12 [ 0xcf ] = 0x83 ;
else if ( V_11 == F_4 ( 3 ) )
V_12 [ 0xcf ] = 0x80 ;
}
for ( V_9 = 0 ; V_9 < 0xff ; V_9 ++ ) {
switch ( V_9 ) {
case 0xb8 ... 0xc1 :
case 0xc4 ... 0xc7 :
case 0xfd :
continue;
}
switch ( V_9 & ~ 0x30 ) {
case 0x00 :
case 0x0c ... 0x0d :
continue;
}
F_7 ( V_1 , V_11 , V_9 ,
V_12 [ V_9 ] ) ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_11 )
{
T_1 V_18 [ 256 ] ;
int V_9 ;
if ( V_1 -> V_13 == V_14 )
memcpy ( V_18 , V_19 ,
sizeof( V_18 ) ) ;
else
memcpy ( V_18 , V_20 ,
sizeof( V_18 ) ) ;
if ( V_1 -> V_21 == 0 ) {
if ( V_1 -> V_17 == 4 ) {
V_18 [ 0xd2 ] = 0x01 ;
V_18 [ 0xcf ] = 0x00 ;
} else if ( V_1 -> V_17 == 8 ) {
V_18 [ 0xd2 ] = 0x02 ;
if ( V_11 == F_4 ( 0 ) )
V_18 [ 0xcf ] = 0x43 ;
else if ( V_11 == F_4 ( 1 ) )
V_18 [ 0xcf ] = 0x40 ;
} else if ( V_1 -> V_17 == 16 ) {
V_18 [ 0xd2 ] = 0x03 ;
if ( V_11 == F_4 ( 0 ) )
V_18 [ 0xcf ] = 0x43 ;
else if ( V_11 == F_4 ( 1 ) )
V_18 [ 0xcf ] = 0x43 ;
else if ( V_11 == F_4 ( 2 ) )
V_18 [ 0xcf ] = 0x43 ;
else if ( V_11 == F_4 ( 3 ) )
V_18 [ 0xcf ] = 0x40 ;
}
} else {
for ( V_9 = 0 ; V_9 <= 4 ; V_9 ++ )
V_18 [ 0x08 | V_9 << 4 ] = 0x12 ;
if ( V_1 -> V_17 == 8 ) {
V_18 [ 0xd2 ] = 0x02 ;
if ( V_11 == F_4 ( 1 ) )
V_18 [ 0xcf ] = 0x80 ;
} else if ( V_1 -> V_17 == 16 ) {
V_18 [ 0xd2 ] = 0x03 ;
if ( V_11 == F_4 ( 1 ) )
V_18 [ 0xcf ] = 0x83 ;
else if ( V_11 == F_4 ( 2 ) )
V_18 [ 0xcf ] = 0x83 ;
else if ( V_11 == F_4 ( 3 ) )
V_18 [ 0xcf ] = 0x80 ;
}
}
for ( V_9 = 0 ; V_9 < 0xff ; V_9 ++ ) {
switch ( V_9 ) {
case 0xb8 ... 0xc1 :
case 0xfd :
continue;
}
switch ( V_9 & ~ 0x30 ) {
case 0x00 :
case 0x0c :
case 0x0d :
continue;
}
F_7 ( V_1 , V_11 , V_9 ,
V_18 [ V_9 ] ) ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_1 , T_1 V_11 )
{
T_1 V_22 [] = {
0x00 , 0xc8 , 0x20 , 0xd0 , 0x06 , 0xf0 , 0x08 , 0x80 ,
0x80 , 0x80 , 0x80 , 0x02 , 0x06 , 0x00 , 0x11 ,
} ;
T_1 V_23 [] = {
0x00 , 0x88 , 0x20 , 0xd0 , 0x05 , 0x20 , 0x28 , 0x80 ,
0x80 , 0x80 , 0x80 , 0x82 , 0x06 , 0x00 , 0x11 ,
} ;
T_1 V_24 [] = {
0x00 , 0x00 , 0x00 , 0xc0 , 0x45 , 0xa0 , 0xd0 , 0x2f ,
0x64 , 0x80 , 0x80 , 0x82 , 0x82 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x0f , 0x05 , 0x00 , 0x00 , 0x80 , 0x06 , 0x00 ,
0x00 , 0x00 , 0x00 , 0xff , 0x8f , 0x00 , 0x00 , 0x00 ,
0x88 , 0x88 , 0xc0 , 0x00 , 0x20 , 0x64 , 0xa8 , 0xec ,
0x31 , 0x75 , 0xb9 , 0xfd , 0x00 , 0x00 , 0x88 , 0x88 ,
0x88 , 0x11 , 0x00 , 0x88 , 0x88 , 0x00 ,
} ;
T_1 * V_25 ;
int V_9 ;
int V_26 ;
V_22 [ 0x06 ] = 0 ;
V_22 [ 0x02 ] = V_27 & 0xff ;
V_22 [ 0x06 ] |= 0x03 & ( V_27 >> 8 ) ;
V_22 [ 0x03 ] = V_28 & 0xff ;
V_22 [ 0x06 ] |=
( ( 0x03 & ( V_28 >> 8 ) ) << 2 ) ;
V_22 [ 0x04 ] = V_29 & 0xff ;
V_22 [ 0x06 ] |=
( ( 0x01 & ( V_29 >> 8 ) ) << 4 ) ;
V_22 [ 0x05 ] = V_30 & 0xff ;
V_22 [ 0x06 ] |=
( ( 0x01 & ( V_30 >> 8 ) ) << 5 ) ;
V_23 [ 0x06 ] = 0 ;
V_23 [ 0x02 ] = V_31 & 0xff ;
V_23 [ 0x06 ] |= 0x03 & ( V_31 >> 8 ) ;
V_23 [ 0x03 ] = V_32 & 0xff ;
V_23 [ 0x06 ] |=
( ( 0x03 & ( V_32 >> 8 ) ) << 2 ) ;
V_23 [ 0x04 ] = V_33 & 0xff ;
V_23 [ 0x06 ] |=
( ( 0x01 & ( V_33 >> 8 ) ) << 4 ) ;
V_23 [ 0x05 ] = V_34 & 0xff ;
V_23 [ 0x06 ] |=
( ( 0x01 & ( V_34 >> 8 ) ) << 5 ) ;
V_25 =
( V_1 -> V_13 == V_35 ) ?
V_22 : V_23 ;
V_25 [ 0x0d ] |= 0x04 ;
V_24 [ 0x62 - 0x40 ] &= ~ ( 3 << 6 ) ;
if ( V_1 -> V_17 == 4 ) {
V_24 [ 0x63 - 0x40 ] |= 1 ;
V_24 [ 0x62 - 0x40 ] |= 3 << 6 ;
} else if ( V_1 -> V_17 == 8 ) {
V_24 [ 0x63 - 0x40 ] |= 2 ;
if ( V_11 == F_4 ( 0 ) )
V_24 [ 0x62 - 0x40 ] |= 1 << 6 ;
else if ( V_11 == F_4 ( 1 ) )
V_24 [ 0x62 - 0x40 ] |= 2 << 6 ;
} else if ( V_1 -> V_17 == 16 ) {
V_24 [ 0x63 - 0x40 ] |= 3 ;
if ( V_11 == F_4 ( 0 ) )
V_24 [ 0x62 - 0x40 ] |= 1 << 6 ;
else if ( V_11 == F_4 ( 1 ) )
V_24 [ 0x62 - 0x40 ] |= 0 << 6 ;
else if ( V_11 == F_4 ( 2 ) )
V_24 [ 0x62 - 0x40 ] |= 0 << 6 ;
else if ( V_11 == F_4 ( 3 ) )
V_24 [ 0x62 - 0x40 ] |= 2 << 6 ;
}
V_24 [ 0x62 - 0x40 ] |= 0 << 2 ;
V_24 [ 0x6c - 0x40 ] |= 0 << 2 ;
V_24 [ 0x6c - 0x40 ] |= 1 << 5 ;
V_24 [ 0x5c - 0x40 ] |= 1 << 5 ;
V_24 [ 0x70 - 0x40 ] |= 0xff ;
V_24 [ 0x71 - 0x40 ] |= 0x10 ;
V_24 [ 0x6d - 0x40 ] |= 0x0f ;
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_25 [ 0x0d ] &= ~ 3 ;
switch ( V_26 ) {
case 0 :
V_25 [ 0x0d ] |= 0x21 ;
break;
case 1 :
V_25 [ 0x0d ] |= 0x20 ;
break;
case 2 :
V_25 [ 0x0d ] |= 0x23 ;
break;
case 3 :
V_25 [ 0x0d ] |= 0x22 ;
break;
}
for ( V_9 = 0 ; V_9 < 0x0f ; V_9 ++ ) {
if ( V_9 == 0x00 )
continue;
F_6 ( V_1 , V_5 ,
V_11 , ( V_26 * 0x10 ) + V_9 ,
V_25 [ V_9 ] ) ;
}
}
for ( V_9 = 0x40 ; V_9 < 0x76 ; V_9 ++ ) {
if ( V_9 == 0x40 || V_9 == 0x59 || V_9 == 0x5a ||
V_9 == 0x5d || V_9 == 0x5e || V_9 == 0x5f )
continue;
F_6 ( V_1 , V_5 , V_11 , V_9 ,
V_24 [ V_9 - 0x40 ] ) ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_36 , const T_1 * V_37 ,
int V_38 , int V_39 )
{
for (; V_38 < V_39 ; V_38 ++ , V_37 ++ ) {
switch ( V_38 ) {
case 0x2e ... 0x37 :
case 0x60 :
case 0x7d :
continue;
}
F_6 ( V_36 , V_40 , 0x46 , V_38 , * V_37 ) ;
}
}
static void F_13 ( struct V_1 * V_36 )
{
const int V_41 = 0x26 ;
static const T_1 V_42 [] = {
0x0d , 0x00 ,
0x59 , 0x1d , 0x75 , 0x3f , 0x06 , 0x3f ,
0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x1a , 0x1a , 0x13 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x68 , 0x10 , 0x97 , 0x4c , 0x18 ,
0x9b , 0x93 , 0x9f , 0xff , 0x7c , 0x34 , 0x3f , 0x3f ,
0x3f , 0x83 , 0x83 , 0x80 , 0x0d , 0x0f , 0xc3 , 0x06 ,
0x02 , 0x80 , 0x71 , 0x77 , 0xa7 , 0x67 , 0x66 , 0x2e ,
0x7b , 0x11 , 0x4f , 0x1f , 0x7c , 0xf0 , 0x21 , 0x77 ,
0x41 , 0x88 , 0x41 , 0x52 , 0xed , 0x10 , 0x10 , 0x00 ,
0x41 , 0xc3 , 0x00 , 0x3e , 0xb8 , 0x02 , 0x00 , 0x00 ,
0x00 , 0x00 , V_43 , V_44 & 0xff ,
V_45 , 0x00 , 0xff , 0xff ,
} , V_46 [] = {
0x0d , 0x00 ,
0xe1 , 0x1d , 0x75 , 0x3f , 0x06 , 0x3f ,
0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x1a , 0x1a , 0x13 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x68 , 0x10 , 0x97 , 0x4c , 0x18 ,
0x9b , 0x93 , 0x9f , 0xff , 0x7c , 0x34 , 0x3f , 0x3f ,
0x3f , 0x83 , 0x83 , 0x80 , 0x0d , 0x0f , 0xc3 , 0x06 ,
0x02 , 0x80 , 0x0f , 0x77 , 0xa7 , 0x67 , 0x66 , 0x2e ,
0x7b , 0x02 , 0x35 , 0xcb , 0x8a , 0x09 , 0x2a , 0x77 ,
0x41 , 0x88 , 0x41 , 0x52 , 0xf1 , 0x10 , 0x20 , 0x00 ,
0x41 , 0xc3 , 0x00 , 0x3e , 0xb8 , 0x02 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x12 , 0x30 ,
V_45 | 0x40 , 0x00 , 0xff , 0xff ,
} ;
if ( V_36 -> V_13 == V_14 )
F_12 ( V_36 , V_46 , V_41 ,
sizeof( V_46 ) ) ;
else
F_12 ( V_36 , V_42 , V_41 ,
sizeof( V_42 ) ) ;
}
int F_14 ( struct V_1 * V_1 )
{
int V_9 ;
T_1 V_47 ;
V_1 -> V_48 = 0 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_17 / 4 ; V_9 ++ ) {
V_47 = F_3 ( V_1 , V_5 ,
F_4 ( V_9 ) , 0xFF ) ;
switch ( V_47 >> 3 ) {
case 0x18 :
V_1 -> V_21 |= 1 << V_9 ;
V_1 -> V_48 ++ ;
break;
case 0x0c :
case 0x0d :
V_1 -> V_49 |= 1 << V_9 ;
V_1 -> V_48 ++ ;
break;
default:
V_47 = F_3 ( V_1 , V_5 ,
F_4 ( V_9 ) ,
0x59 ) ;
if ( ( V_47 >> 3 ) == 0x04 ) {
V_1 -> V_50 |= 1 << V_9 ;
V_1 -> V_48 ++ ;
}
}
}
if ( V_1 -> V_48 != ( V_1 -> V_17 >> 2 ) ) {
F_15 ( & V_1 -> V_51 -> V_36 ,
L_1 ) ;
return - V_52 ;
}
F_13 ( V_1 ) ;
for ( V_9 = 0 ; V_9 < V_1 -> V_48 ; V_9 ++ ) {
if ( ( V_1 -> V_21 & ( 1 << V_9 ) ) )
F_9 ( V_1 , F_4 ( V_9 ) ) ;
else if ( ( V_1 -> V_49 & ( 1 << V_9 ) ) )
F_10 ( V_1 , F_4 ( V_9 ) ) ;
else
F_11 ( V_1 , F_4 ( V_9 ) ) ;
}
return 0 ;
}
int F_16 ( struct V_1 * V_1 , T_1 V_26 )
{
T_1 V_6 , V_53 ;
V_53 = V_26 / 4 ;
V_26 %= 4 ;
V_6 = F_1 ( V_1 , V_53 , V_54 ,
V_55 ) & 0x0f ;
return V_6 & ( 1 << V_26 ) ? 1 : 0 ;
}
bool F_17 ( struct V_1 * V_1 , T_1 V_26 )
{
return F_2 ( V_1 , V_26 / 4 ) ;
}
int F_18 ( struct V_1 * V_1 , T_2 V_56 , T_1 V_26 ,
T_3 V_6 )
{
char V_57 ;
T_1 V_53 ;
V_53 = V_26 / 4 ;
V_26 %= 4 ;
if ( V_6 > 255 || V_6 < 0 )
return - V_58 ;
switch ( V_56 ) {
case V_59 :
if ( F_2 ( V_1 , V_53 ) ) {
T_1 V_60 = F_3 ( V_1 , V_5 ,
F_4 ( V_53 ) ,
F_19 ( V_53 ) ) ;
V_60 &= 0xf0 ;
V_60 |= V_6 ;
F_6 ( V_1 , V_5 ,
F_4 ( V_53 ) ,
F_19 ( V_53 ) , V_60 ) ;
} else {
return - V_52 ;
}
break;
case V_61 :
if ( F_2 ( V_1 , V_53 ) )
V_57 = V_6 - 128 ;
else
V_57 = ( char ) V_6 ;
F_5 ( V_1 , V_53 , F_20 ( V_26 ) ,
F_21 ( V_26 ) , V_57 ) ;
break;
case V_62 :
if ( F_2 ( V_1 , V_53 ) ) {
F_6 ( V_1 , V_5 ,
F_4 ( V_53 ) ,
F_22 ( V_26 ) , V_6 ) ;
}
F_5 ( V_1 , V_53 , F_23 ( V_26 ) ,
F_24 ( V_26 ) , V_6 ) ;
break;
case V_63 :
F_5 ( V_1 , V_53 , F_25 ( V_26 ) ,
F_26 ( V_26 ) , V_6 ) ;
break;
case V_64 :
if ( F_2 ( V_1 , V_53 ) )
V_57 = V_6 - 128 ;
else
V_57 = ( char ) V_6 ;
F_5 ( V_1 , V_53 , F_27 ( V_26 ) ,
F_28 ( V_26 ) , V_57 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
int F_29 ( struct V_1 * V_1 , T_2 V_56 , T_1 V_26 ,
T_3 * V_6 )
{
T_1 V_10 , V_53 ;
V_53 = V_26 / 4 ;
V_26 %= 4 ;
switch ( V_56 ) {
case V_59 :
if ( F_2 ( V_1 , V_53 ) ) {
V_10 = F_3 ( V_1 , V_5 ,
F_4 ( V_53 ) ,
F_19 ( V_53 ) ) ;
* V_6 = V_10 & 0x0f ;
} else
* V_6 = 0 ;
break;
case V_61 :
V_10 = F_1 ( V_1 , V_53 , F_20 ( V_26 ) ,
F_21 ( V_26 ) ) ;
if ( F_2 ( V_1 , V_53 ) )
* V_6 = ( T_3 ) ( ( char ) V_10 ) + 128 ;
else
* V_6 = V_10 ;
break;
case V_62 :
* V_6 = F_1 ( V_1 , V_53 ,
F_22 ( V_26 ) ,
F_24 ( V_26 ) ) ;
break;
case V_63 :
* V_6 = F_1 ( V_1 , V_53 ,
F_25 ( V_26 ) ,
F_26 ( V_26 ) ) ;
break;
case V_64 :
V_10 = F_1 ( V_1 , V_53 ,
F_27 ( V_26 ) ,
F_28 ( V_26 ) ) ;
if ( F_2 ( V_1 , V_53 ) )
* V_6 = ( T_3 ) ( ( char ) V_10 ) + 128 ;
else
* V_6 = V_10 ;
break;
default:
return - V_52 ;
}
return 0 ;
}
T_1 F_30 ( struct V_1 * V_1 , T_1 V_26 )
{
T_1 V_6 ;
T_1 V_53 ;
V_53 = V_26 / 4 ;
V_26 %= 4 ;
V_6 = F_1 ( V_1 , V_53 ,
F_31 ( V_26 ) ,
F_32 ( V_26 ) ) ;
return ( V_26 % 2 ) ? ( V_6 >> 4 ) : ( V_6 & 0x0f ) ;
}
void F_33 ( struct V_1 * V_1 , T_1 V_26 , T_1 V_6 )
{
T_1 V_65 ;
T_1 V_53 ;
V_53 = V_26 / 4 ;
V_26 %= 4 ;
V_65 = F_1 ( V_1 , V_53 ,
F_31 ( V_26 ) ,
F_32 ( V_26 ) ) ;
V_6 = ( V_65 & ( ( V_26 % 2 ) ? 0x0f : 0xf0 ) ) |
( ( V_26 % 2 ) ? ( V_6 << 4 ) : V_6 ) ;
F_5 ( V_1 , V_53 , F_31 ( V_26 ) ,
F_32 ( V_26 ) , V_6 ) ;
}
