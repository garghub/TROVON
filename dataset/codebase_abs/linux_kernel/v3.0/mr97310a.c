static int F_1 ( struct V_1 * V_1 , int V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_4 ,
F_3 ( V_1 -> V_4 , 4 ) ,
V_1 -> V_5 , V_2 , NULL , 500 ) ;
if ( V_3 < 0 )
F_4 ( L_1 ,
V_1 -> V_5 [ 0 ] , V_3 ) ;
return V_3 ;
}
static int F_5 ( struct V_1 * V_1 , int V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 -> V_4 ,
F_6 ( V_1 -> V_4 , 3 ) ,
V_1 -> V_5 , V_2 , NULL , 500 ) ;
if ( V_3 < 0 )
F_4 ( L_2 ,
V_1 -> V_5 [ 0 ] , V_3 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_6 , T_1 V_7 ,
const T_1 * V_8 , int V_2 )
{
V_1 -> V_5 [ 0 ] = 0x1f ;
V_1 -> V_5 [ 1 ] = V_7 ;
V_1 -> V_5 [ 2 ] = V_6 ;
memcpy ( V_1 -> V_5 + 3 , V_8 , V_2 ) ;
return F_1 ( V_1 , V_2 + 3 ) ;
}
static int F_8 ( struct V_1 * V_1 ,
const struct V_9 * V_8 , int V_2 )
{
int V_10 , V_3 ;
for ( V_10 = 0 ; V_10 < V_2 ; V_10 ++ ) {
V_3 = F_7 ( V_1 , V_8 [ V_10 ] . V_6 , V_8 [ V_10 ] . V_7 ,
V_8 [ V_10 ] . V_8 , V_8 [ V_10 ] . V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_6 , T_1 V_8 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_1 V_12 , V_13 ;
int V_3 ;
V_12 = V_8 ;
if ( V_11 -> V_14 == V_15 ) {
V_3 = F_7 ( V_1 , V_6 , 0x01 , & V_12 , 1 ) ;
V_13 = V_11 -> V_16 ? 0x13 : 0x11 ;
} else {
V_3 = F_7 ( V_1 , V_6 , 0x00 , & V_12 , 1 ) ;
V_13 = 0x11 ;
}
if ( V_3 < 0 )
return V_3 ;
V_12 = 0x01 ;
V_3 = F_7 ( V_1 , V_13 , 0x00 , & V_12 , 1 ) ;
if ( V_3 < 0 )
return V_3 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_6 , int V_17 )
{
int V_18 ;
V_1 -> V_5 [ 0 ] = V_6 ;
V_18 = F_1 ( V_1 , 1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_5 ( V_1 , 16 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_17 )
F_11 ( V_19 , L_3 , V_6 ,
V_1 -> V_5 [ 0 ] ,
V_1 -> V_5 [ 1 ] ,
V_1 -> V_5 [ 2 ] ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 )
{
T_2 * V_8 = V_1 -> V_5 ;
int V_18 ;
T_1 V_20 = 0 ;
int V_21 = 0 ;
V_18 = F_10 ( V_1 , 0x21 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_8 [ 0 ] = 0x19 ;
V_8 [ 1 ] = 0x51 ;
V_18 = F_1 ( V_1 , 2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_1 , 0x21 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_8 [ 0 ] = 0x19 ;
V_8 [ 1 ] = 0xba ;
V_18 = F_1 ( V_1 , 2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_1 , 0x21 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_8 [ 0 ] = 0x19 ;
V_8 [ 1 ] = 0x00 ;
V_18 = F_1 ( V_1 , 2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_1 , 0x21 , 0 ) ;
if ( V_18 < 0 )
return V_18 ;
V_8 [ 0 ] = 0x19 ;
V_8 [ 1 ] = 0x00 ;
V_18 = F_1 ( V_1 , 2 ) ;
if ( V_18 < 0 )
return V_18 ;
while ( V_20 != 0x0a && V_21 < 256 ) {
V_18 = F_10 ( V_1 , 0x21 , 0 ) ;
V_20 = V_8 [ 0 ] ;
V_21 ++ ;
if ( V_18 < 0 )
return V_18 ;
}
if ( V_20 != 0x0a )
F_11 ( V_22 , L_4 , V_20 ) ;
V_21 = 0 ;
while ( V_21 < 4 ) {
V_8 [ 0 ] = 0x19 ;
V_8 [ 1 ] = 0x00 ;
V_18 = F_1 ( V_1 , 2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_1 , 0x21 , 0 ) ;
V_20 = V_8 [ 0 ] ;
V_21 ++ ;
if ( V_18 < 0 )
return V_18 ;
}
V_8 [ 0 ] = 0x19 ;
V_18 = F_1 ( V_1 , 1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_5 ( V_1 , 16 ) ;
if ( V_18 < 0 )
return V_18 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x01 ;
V_1 -> V_5 [ 1 ] = 0x01 ;
return F_1 ( V_1 , 2 ) ;
}
static void F_14 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x01 ;
V_1 -> V_5 [ 1 ] = 0x00 ;
if ( F_1 ( V_1 , 2 ) < 0 )
F_11 ( V_22 , L_5 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x19 ;
V_1 -> V_5 [ 1 ] = 0x54 ;
if ( F_1 ( V_1 , 2 ) < 0 )
F_11 ( V_22 , L_6 ) ;
}
static int F_16 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x00 ;
V_1 -> V_5 [ 1 ] = 0x4d ;
return F_1 ( V_1 , 2 ) ;
}
static int F_17 ( struct V_1 * V_1 ,
const struct V_23 * V_24 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
struct V_25 * V_25 ;
int V_26 = V_27 ;
int V_18 ;
V_25 = & V_1 -> V_25 ;
V_25 -> V_28 = V_29 ;
V_25 -> V_30 = F_18 ( V_29 ) ;
V_11 -> V_31 = 0 ;
V_18 = F_12 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_1 , 0x07 , 1 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_24 -> V_32 == 0x0110 || V_24 -> V_32 == 0x010e ) {
V_11 -> V_14 = V_15 ;
V_25 -> V_30 -- ;
switch ( V_1 -> V_5 [ 0 ] ) {
case 2 :
V_11 -> V_16 = 0 ;
break;
case 3 :
V_11 -> V_16 = 1 ;
break;
default:
F_4 ( L_7 ,
V_1 -> V_5 [ 1 ] ) ;
return - V_33 ;
}
F_11 ( V_19 , L_8 ,
V_11 -> V_16 ) ;
} else {
V_11 -> V_14 = V_34 ;
V_11 -> V_16 = 1 ;
V_11 -> V_31 = 0 ;
V_11 -> V_35 = 0 ;
if ( V_1 -> V_5 [ 0 ] == 0x01 ) {
V_11 -> V_16 = 2 ;
} else if ( ( V_1 -> V_5 [ 0 ] != 0x03 ) &&
( V_1 -> V_5 [ 0 ] != 0x04 ) ) {
F_4 ( L_9 ,
V_1 -> V_5 [ 0 ] ) ;
F_4 ( L_10 ) ;
F_4 ( L_11 ) ;
}
if ( ( V_1 -> V_5 [ 0 ] == 0x03 ) &&
( V_1 -> V_5 [ 1 ] == 0x50 ) )
V_11 -> V_35 = 1 ;
if ( V_1 -> V_5 [ 0 ] == 0x04 ) {
V_11 -> V_31 = 1 ;
switch ( V_1 -> V_5 [ 1 ] ) {
case 0x50 :
V_11 -> V_16 = 0 ;
F_11 ( V_19 , L_12 ) ;
break;
case 0x20 :
break;
default:
F_4 ( L_13 ,
V_1 -> V_5 [ 1 ] ) ;
F_4 ( L_10 ) ;
F_4 ( L_11 ) ;
}
}
F_11 ( V_19 , L_14 ,
V_11 -> V_16 ) ;
}
F_19 ( V_1 ) ;
if ( V_36 != - 1 ) {
V_11 -> V_16 = ! ! V_36 ;
F_11 ( V_19 , L_15 ,
V_11 -> V_16 ) ;
}
if ( V_11 -> V_14 == V_15 ) {
if ( V_11 -> V_16 == 0 )
V_1 -> V_37 = ( 1 << V_38 ) |
( 1 << V_39 ) |
( 1 << V_40 ) |
( 1 << V_41 ) ;
else
V_1 -> V_37 = ( 1 << V_39 ) |
( 1 << V_40 ) |
( 1 << V_41 ) |
( 1 << V_42 ) ;
} else {
if ( V_11 -> V_16 == 0 )
V_1 -> V_37 = ( 1 << V_38 ) |
( 1 << V_39 ) |
( 1 << V_43 ) |
( 1 << V_44 ) |
( 1 << V_40 ) |
( 1 << V_41 ) |
( 1 << V_42 ) ;
else if ( V_11 -> V_16 == 2 ) {
V_1 -> V_37 = ( 1 << V_38 ) |
( 1 << V_39 ) |
( 1 << V_44 ) |
( 1 << V_42 ) ;
V_26 = V_45 ;
} else if ( V_11 -> V_31 )
V_1 -> V_37 = ( 1 << V_38 ) |
( 1 << V_40 ) |
( 1 << V_41 ) ;
else
V_1 -> V_37 = ( 1 << V_39 ) |
( 1 << V_40 ) |
( 1 << V_41 ) ;
}
V_11 -> V_46 = V_47 ;
V_11 -> V_48 = V_49 ;
V_11 -> V_50 = V_26 ;
V_11 -> V_51 = V_52 ;
V_11 -> V_53 = V_54 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_2 * V_8 = V_1 -> V_5 ;
int V_18 ;
static const T_2 V_55 [] = {
0x00 ,
0x0d ,
0x01 ,
0x00 ,
0x00 ,
0x13 ,
0x00 ,
0x00 ,
0x00 ,
0x50 ,
0xc0
} ;
memcpy ( V_8 , V_55 , 11 ) ;
if ( V_11 -> V_16 )
V_8 [ 5 ] = 0xbb ;
switch ( V_1 -> V_56 ) {
case 160 :
V_8 [ 9 ] |= 0x04 ;
case 320 :
default:
V_8 [ 3 ] = 0x28 ;
V_8 [ 4 ] = 0x3c ;
V_8 [ 6 ] = 0x14 ;
V_8 [ 8 ] = 0x1a + V_11 -> V_16 ;
break;
case 176 :
V_8 [ 9 ] |= 0x04 ;
case 352 :
V_8 [ 3 ] = 0x2c ;
V_8 [ 4 ] = 0x48 ;
V_8 [ 6 ] = 0x06 ;
V_8 [ 8 ] = 0x06 - V_11 -> V_16 ;
break;
}
V_18 = F_1 ( V_1 , 11 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_11 -> V_16 ) {
static const struct V_9 V_57 [] = {
{ 0x02 , 0x00 , { 0x03 , 0x5a , 0xb5 , 0x01 ,
0x0f , 0x14 , 0x0f , 0x10 } , 8 } ,
{ 0x0c , 0x00 , { 0x04 , 0x01 , 0x01 , 0x00 , 0x1f } , 5 } ,
{ 0x12 , 0x00 , { 0x07 } , 1 } ,
{ 0x1f , 0x00 , { 0x06 } , 1 } ,
{ 0x27 , 0x00 , { 0x04 } , 1 } ,
{ 0x29 , 0x00 , { 0x0c } , 1 } ,
{ 0x40 , 0x00 , { 0x40 , 0x00 , 0x04 } , 3 } ,
{ 0x50 , 0x00 , { 0x60 } , 1 } ,
{ 0x60 , 0x00 , { 0x06 } , 1 } ,
{ 0x6b , 0x00 , { 0x85 , 0x85 , 0xc8 , 0xc8 , 0xc8 , 0xc8 } , 6 } ,
{ 0x72 , 0x00 , { 0x1e , 0x56 } , 2 } ,
{ 0x75 , 0x00 , { 0x58 , 0x40 , 0xa2 , 0x02 , 0x31 , 0x02 ,
0x31 , 0x80 , 0x00 } , 9 } ,
{ 0x11 , 0x00 , { 0x01 } , 1 } ,
{ 0 , 0 , { 0 } , 0 }
} ;
V_18 = F_8 ( V_1 , V_57 ,
F_18 ( V_57 ) ) ;
} else {
static const struct V_9 V_58 [] = {
{ 0x02 , 0x00 , { 0x10 } , 1 } ,
{ 0x05 , 0x01 , { 0x22 } , 1 } ,
{ 0x06 , 0x01 , { 0x00 } , 1 } ,
{ 0x09 , 0x02 , { 0x0e } , 1 } ,
{ 0x0a , 0x02 , { 0x05 } , 1 } ,
{ 0x0b , 0x02 , { 0x05 } , 1 } ,
{ 0x0c , 0x02 , { 0x0f } , 1 } ,
{ 0x0d , 0x02 , { 0x07 } , 1 } ,
{ 0x0e , 0x02 , { 0x0c } , 1 } ,
{ 0x0f , 0x00 , { 0x00 } , 1 } ,
{ 0x10 , 0x00 , { 0x06 } , 1 } ,
{ 0x11 , 0x00 , { 0x07 } , 1 } ,
{ 0x12 , 0x00 , { 0x00 } , 1 } ,
{ 0x13 , 0x00 , { 0x01 } , 1 } ,
{ 0 , 0 , { 0 } , 0 }
} ;
V_1 -> V_5 [ 0 ] = 0x0a ;
V_1 -> V_5 [ 1 ] = 0x00 ;
V_18 = F_1 ( V_1 , 2 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_8 ( V_1 , V_58 ,
F_18 ( V_58 ) ) ;
}
return V_18 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_2 * V_8 = V_1 -> V_5 ;
int V_18 ;
static const T_2 V_55 [] =
{ 0x00 , 0x0d , 0x01 , 0x00 , 0x00 , 0x2b , 0x00 , 0x00 ,
0x00 , 0x50 , 0xc0 } ;
memcpy ( V_8 , V_55 , 11 ) ;
if ( ! V_11 -> V_16 ) {
V_8 [ 5 ] = 0x00 ;
V_8 [ 10 ] = 0x91 ;
}
if ( V_11 -> V_16 == 2 ) {
V_8 [ 5 ] = 0x00 ;
V_8 [ 10 ] = 0x18 ;
}
switch ( V_1 -> V_56 ) {
case 160 :
V_8 [ 9 ] |= 0x0c ;
case 320 :
V_8 [ 9 ] |= 0x04 ;
case 640 :
default:
V_8 [ 3 ] = 0x50 ;
V_8 [ 4 ] = 0x78 ;
V_8 [ 6 ] = 0x04 ;
V_8 [ 8 ] = 0x03 ;
if ( V_11 -> V_16 == 2 ) {
V_8 [ 6 ] = 2 ;
V_8 [ 8 ] = 1 ;
}
if ( V_11 -> V_31 )
V_8 [ 8 ] = 0x04 ;
break;
case 176 :
V_8 [ 9 ] |= 0x04 ;
case 352 :
V_8 [ 3 ] = 0x2c ;
V_8 [ 4 ] = 0x48 ;
V_8 [ 6 ] = 0x94 ;
V_8 [ 8 ] = 0x63 ;
if ( V_11 -> V_31 )
V_8 [ 8 ] = 0x64 ;
break;
}
V_18 = F_1 ( V_1 , 11 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_11 -> V_16 ) {
static const struct V_9 V_59 [] = {
{ 0x01 , 0x00 , { 0x0c , 0x00 , 0x04 } , 3 } ,
{ 0x14 , 0x00 , { 0x01 , 0xe4 , 0x02 , 0x84 } , 4 } ,
{ 0x20 , 0x00 , { 0x00 , 0x80 , 0x00 , 0x08 } , 4 } ,
{ 0x25 , 0x00 , { 0x03 , 0xa9 , 0x80 } , 3 } ,
{ 0x30 , 0x00 , { 0x30 , 0x18 , 0x10 , 0x18 } , 4 } ,
{ 0 , 0 , { 0 } , 0 }
} ;
V_18 = F_8 ( V_1 , V_59 ,
F_18 ( V_59 ) ) ;
} else if ( V_11 -> V_16 == 1 ) {
static const struct V_9 V_60 [] = {
{ 0x02 , 0x00 , { 0x06 , 0x59 , 0x0c , 0x16 , 0x00 ,
0x05 , 0x01 , 0x04 } , 8 }
} ;
static const struct V_9 V_61 [] = {
{ 0x02 , 0x00 , { 0x06 , 0x59 , 0x0c , 0x16 , 0x00 ,
0x07 , 0x00 , 0x01 } , 8 }
} ;
static const struct V_9 V_62 [] = {
{ 0x11 , 0x04 , { 0x01 } , 1 } ,
{ 0x0a , 0x00 , { 0x00 , 0x01 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x0a } , 7 } ,
{ 0x11 , 0x04 , { 0x01 } , 1 } ,
{ 0x12 , 0x00 , { 0x00 , 0x63 , 0x00 , 0x70 , 0x00 , 0x00 } , 6 } ,
{ 0x11 , 0x04 , { 0x01 } , 1 } ,
{ 0 , 0 , { 0 } , 0 }
} ;
if ( V_11 -> V_35 )
V_18 = F_8 ( V_1 , V_60 ,
F_18 ( V_60 ) ) ;
else
V_18 = F_8 ( V_1 , V_61 ,
F_18 ( V_61 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_8 ( V_1 , V_62 ,
F_18 ( V_62 ) ) ;
} else {
static const struct V_9 V_63 [] = {
{ 0x01 , 0x00 , { 0x48 } , 1 } ,
{ 0x02 , 0x00 , { 0x22 } , 1 } ,
{ 0x05 , 0x00 , { 0x10 } , 1 } ,
{ 0x06 , 0x00 , { 0x00 } , 1 } ,
{ 0x07 , 0x00 , { 0x00 } , 1 } ,
{ 0x08 , 0x00 , { 0x00 } , 1 } ,
{ 0x09 , 0x00 , { 0x00 } , 1 } ,
{ 0x12 , 0x00 , { 0x00 } , 1 } ,
{ 0x13 , 0x00 , { 0x04 } , 1 } ,
{ 0x14 , 0x00 , { 0x00 } , 1 } ,
{ 0x15 , 0x00 , { 0x06 } , 1 } ,
{ 0x16 , 0x00 , { 0x01 } , 1 } ,
{ 0x17 , 0x00 , { 0xe2 } , 1 } ,
{ 0x18 , 0x00 , { 0x02 } , 1 } ,
{ 0x19 , 0x00 , { 0x82 } , 1 } ,
{ 0x1a , 0x00 , { 0x00 } , 1 } ,
{ 0x1b , 0x00 , { 0x20 } , 1 } ,
{ 0x1d , 0x00 , { 0x80 } , 1 } ,
{ 0x1e , 0x00 , { 0x08 } , 1 } ,
{ 0x1f , 0x00 , { 0x0c } , 1 } ,
{ 0x20 , 0x00 , { 0x00 } , 1 } ,
{ 0 , 0 , { 0 } , 0 }
} ;
V_18 = F_8 ( V_1 , V_63 ,
F_18 ( V_63 ) ) ;
}
return V_18 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
int V_18 ;
V_11 -> V_64 = 0 ;
V_18 = F_12 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_13 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_11 -> V_14 == V_15 ) {
V_18 = F_21 ( V_1 ) ;
} else {
V_18 = F_22 ( V_1 ) ;
}
if ( V_18 < 0 )
return V_18 ;
F_24 ( V_1 ) ;
F_25 ( V_1 ) ;
F_26 ( V_1 ) ;
F_27 ( V_1 ) ;
return F_16 ( V_1 ) ;
}
static void F_19 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
F_14 ( V_1 ) ;
F_12 ( V_1 ) ;
if ( V_11 -> V_31 )
F_15 ( V_1 ) ;
}
static void F_24 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_1 V_65 ;
T_1 V_66 = 7 ;
T_1 V_67 = 8 ;
static const T_1 V_68 [] =
{ 0 , 4 , 8 , 12 , 1 , 2 , 3 , 5 , 6 , 9 , 7 , 10 , 13 , 11 , 14 , 15 } ;
if ( ( V_1 -> V_37 & ( 1 << V_38 ) ) &&
( V_1 -> V_37 & ( 1 << V_39 ) ) )
return;
if ( V_11 -> V_14 == V_34 ) {
V_66 += 4 ;
V_67 += 4 ;
}
if ( V_11 -> V_46 > 0 ) {
F_9 ( V_1 , V_66 , 0x00 ) ;
V_65 = V_11 -> V_46 ;
} else {
F_9 ( V_1 , V_66 , 0x01 ) ;
V_65 = ( 257 - V_11 -> V_46 ) ;
}
if ( V_11 -> V_31 )
V_65 = V_68 [ V_65 ] ;
F_9 ( V_1 , V_67 , V_65 ) ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
int V_48 = V_49 ;
T_1 V_12 [ 2 ] ;
if ( V_1 -> V_37 & ( 1 << V_43 ) )
return;
if ( V_11 -> V_14 == V_15 && V_11 -> V_16 == 1 ) {
V_48 = ( V_11 -> V_48 * 9267 ) / 10000 + 300 ;
F_9 ( V_1 , 3 , V_48 >> 4 ) ;
F_9 ( V_1 , 4 , V_48 & 0x0f ) ;
} else if ( V_11 -> V_16 == 2 ) {
V_48 = V_11 -> V_48 ;
V_48 >>= 3 ;
F_9 ( V_1 , 3 , V_48 >> 8 ) ;
F_9 ( V_1 , 4 , V_48 & 0xff ) ;
} else {
T_1 V_69 = ( 60 * V_11 -> V_48 + 7999 ) / 8000 ;
if ( V_69 < V_11 -> V_53 && V_1 -> V_56 >= 320 )
V_69 = V_11 -> V_53 ;
else if ( V_69 < 2 )
V_69 = 2 ;
if ( V_11 -> V_14 == V_34 && V_69 < 4 )
V_69 = 4 ;
V_48 = ( 60 * 511 * V_11 -> V_48 ) / ( 8000 * V_69 ) ;
if ( V_48 > 511 )
V_48 = 511 ;
V_48 = 511 - V_48 ;
V_12 [ 0 ] = V_48 & 0xff ;
V_12 [ 1 ] = V_48 >> 8 ;
F_7 ( V_1 , 0x0e , 0 , V_12 , 2 ) ;
F_9 ( V_1 , 0x02 , V_69 ) ;
}
}
static void F_27 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_1 V_70 ;
if ( ( V_1 -> V_37 & ( 1 << V_44 ) ) &&
( V_1 -> V_37 & ( 1 << V_41 ) ) )
return;
if ( V_11 -> V_14 == V_15 && V_11 -> V_16 == 1 )
F_9 ( V_1 , 0x0e , V_11 -> V_50 ) ;
else if ( V_11 -> V_14 == V_34 && V_11 -> V_16 == 2 )
for ( V_70 = 0x0a ; V_70 < 0x11 ; V_70 += 2 ) {
F_9 ( V_1 , V_70 , V_11 -> V_50 >> 8 ) ;
F_9 ( V_1 , V_70 + 1 , V_11 -> V_50 & 0xff ) ;
}
else
F_9 ( V_1 , 0x10 , V_11 -> V_50 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
if ( V_1 -> V_37 & ( 1 << V_40 ) )
return;
F_9 ( V_1 , 0x1c , V_11 -> V_51 ) ;
}
static int F_28 ( struct V_1 * V_1 , T_3 V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
V_11 -> V_46 = V_65 ;
if ( V_1 -> V_71 )
F_24 ( V_1 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , T_3 * V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
* V_65 = V_11 -> V_46 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , T_3 V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
V_11 -> V_48 = V_65 ;
if ( V_1 -> V_71 )
F_26 ( V_1 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , T_3 * V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
* V_65 = V_11 -> V_48 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , T_3 V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
V_11 -> V_50 = V_65 ;
if ( V_1 -> V_71 )
F_27 ( V_1 ) ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , T_3 * V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
* V_65 = V_11 -> V_50 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , T_3 V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
V_11 -> V_51 = V_65 ;
if ( V_1 -> V_71 )
F_25 ( V_1 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , T_3 * V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
* V_65 = V_11 -> V_51 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , T_3 V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
V_11 -> V_53 = V_65 ;
if ( V_1 -> V_71 )
F_26 ( V_1 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , T_3 * V_65 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
* V_65 = V_11 -> V_53 ;
return 0 ;
}
static void F_38 ( struct V_1 * V_1 ,
T_1 * V_8 ,
int V_2 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
unsigned char * V_72 ;
V_72 = F_39 ( & V_11 -> V_64 , V_8 , V_2 ) ;
if ( V_72 ) {
int V_73 ;
V_73 = V_72 - V_8 ;
if ( V_73 > sizeof F_40 )
V_73 -= sizeof F_40 ;
else
V_73 = 0 ;
F_41 ( V_1 , V_74 ,
V_8 , V_73 ) ;
F_41 ( V_1 , V_75 ,
F_40 , sizeof F_40 ) ;
V_2 -= V_72 - V_8 ;
V_8 = V_72 ;
}
F_41 ( V_1 , V_76 , V_8 , V_2 ) ;
}
static int F_42 ( struct V_77 * V_78 ,
const struct V_23 * V_24 )
{
return F_43 ( V_78 , V_24 , & V_79 , sizeof( struct V_11 ) ,
V_80 ) ;
}
static int T_4 F_44 ( void )
{
return F_45 ( & V_81 ) ;
}
static void T_5 F_46 ( void )
{
F_47 ( & V_81 ) ;
}
