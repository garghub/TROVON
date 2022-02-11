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
F_13 ( L_4 , V_20 ) ;
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
static int F_14 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x01 ;
V_1 -> V_5 [ 1 ] = 0x01 ;
return F_1 ( V_1 , 2 ) ;
}
static void F_15 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x01 ;
V_1 -> V_5 [ 1 ] = 0x00 ;
if ( F_1 ( V_1 , 2 ) < 0 )
F_13 ( L_5 ) ;
}
static void F_16 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x19 ;
V_1 -> V_5 [ 1 ] = 0x54 ;
if ( F_1 ( V_1 , 2 ) < 0 )
F_13 ( L_6 ) ;
}
static int F_17 ( struct V_1 * V_1 )
{
V_1 -> V_5 [ 0 ] = 0x00 ;
V_1 -> V_5 [ 1 ] = 0x4d ;
return F_1 ( V_1 , 2 ) ;
}
static int F_18 ( struct V_1 * V_1 ,
const struct V_22 * V_23 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
struct V_24 * V_24 ;
int V_18 ;
V_24 = & V_1 -> V_24 ;
V_24 -> V_25 = V_26 ;
V_24 -> V_27 = F_19 ( V_26 ) ;
V_11 -> V_28 = 0 ;
V_18 = F_12 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_14 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_10 ( V_1 , 0x07 , 1 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_23 -> V_29 == 0x0110 || V_23 -> V_29 == 0x010e ) {
V_11 -> V_14 = V_15 ;
V_24 -> V_27 -- ;
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
return - V_30 ;
}
F_11 ( V_19 , L_8 ,
V_11 -> V_16 ) ;
} else {
V_11 -> V_14 = V_31 ;
V_11 -> V_16 = 1 ;
V_11 -> V_28 = 0 ;
V_11 -> V_32 = 0 ;
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
V_11 -> V_32 = 1 ;
if ( V_1 -> V_5 [ 0 ] == 0x04 ) {
V_11 -> V_28 = 1 ;
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
F_20 ( V_1 ) ;
if ( V_33 != - 1 ) {
V_11 -> V_16 = ! ! V_33 ;
F_11 ( V_19 , L_15 ,
V_11 -> V_16 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_1 )
{
return 0 ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_2 * V_8 = V_1 -> V_5 ;
int V_18 ;
static const T_2 V_34 [] = {
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
memcpy ( V_8 , V_34 , 11 ) ;
if ( V_11 -> V_16 )
V_8 [ 5 ] = 0xbb ;
switch ( V_1 -> V_35 ) {
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
static const struct V_9 V_36 [] = {
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
V_18 = F_8 ( V_1 , V_36 ,
F_19 ( V_36 ) ) ;
} else {
static const struct V_9 V_37 [] = {
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
V_18 = F_8 ( V_1 , V_37 ,
F_19 ( V_37 ) ) ;
}
return V_18 ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_2 * V_8 = V_1 -> V_5 ;
int V_18 ;
static const T_2 V_34 [] =
{ 0x00 , 0x0d , 0x01 , 0x00 , 0x00 , 0x2b , 0x00 , 0x00 ,
0x00 , 0x50 , 0xc0 } ;
memcpy ( V_8 , V_34 , 11 ) ;
if ( ! V_11 -> V_16 ) {
V_8 [ 5 ] = 0x00 ;
V_8 [ 10 ] = 0x91 ;
}
if ( V_11 -> V_16 == 2 ) {
V_8 [ 5 ] = 0x00 ;
V_8 [ 10 ] = 0x18 ;
}
switch ( V_1 -> V_35 ) {
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
if ( V_11 -> V_28 )
V_8 [ 8 ] = 0x04 ;
break;
case 176 :
V_8 [ 9 ] |= 0x04 ;
case 352 :
V_8 [ 3 ] = 0x2c ;
V_8 [ 4 ] = 0x48 ;
V_8 [ 6 ] = 0x94 ;
V_8 [ 8 ] = 0x63 ;
if ( V_11 -> V_28 )
V_8 [ 8 ] = 0x64 ;
break;
}
V_18 = F_1 ( V_1 , 11 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( ! V_11 -> V_16 ) {
static const struct V_9 V_38 [] = {
{ 0x01 , 0x00 , { 0x0c , 0x00 , 0x04 } , 3 } ,
{ 0x14 , 0x00 , { 0x01 , 0xe4 , 0x02 , 0x84 } , 4 } ,
{ 0x20 , 0x00 , { 0x00 , 0x80 , 0x00 , 0x08 } , 4 } ,
{ 0x25 , 0x00 , { 0x03 , 0xa9 , 0x80 } , 3 } ,
{ 0x30 , 0x00 , { 0x30 , 0x18 , 0x10 , 0x18 } , 4 } ,
{ 0 , 0 , { 0 } , 0 }
} ;
V_18 = F_8 ( V_1 , V_38 ,
F_19 ( V_38 ) ) ;
} else if ( V_11 -> V_16 == 1 ) {
static const struct V_9 V_39 [] = {
{ 0x02 , 0x00 , { 0x06 , 0x59 , 0x0c , 0x16 , 0x00 ,
0x05 , 0x01 , 0x04 } , 8 }
} ;
static const struct V_9 V_40 [] = {
{ 0x02 , 0x00 , { 0x06 , 0x59 , 0x0c , 0x16 , 0x00 ,
0x07 , 0x00 , 0x01 } , 8 }
} ;
static const struct V_9 V_41 [] = {
{ 0x11 , 0x04 , { 0x01 } , 1 } ,
{ 0x0a , 0x00 , { 0x00 , 0x01 , 0x00 , 0x00 , 0x01 ,
0x00 , 0x0a } , 7 } ,
{ 0x11 , 0x04 , { 0x01 } , 1 } ,
{ 0x12 , 0x00 , { 0x00 , 0x63 , 0x00 , 0x70 , 0x00 , 0x00 } , 6 } ,
{ 0x11 , 0x04 , { 0x01 } , 1 } ,
{ 0 , 0 , { 0 } , 0 }
} ;
if ( V_11 -> V_32 )
V_18 = F_8 ( V_1 , V_39 ,
F_19 ( V_39 ) ) ;
else
V_18 = F_8 ( V_1 , V_40 ,
F_19 ( V_40 ) ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_8 ( V_1 , V_41 ,
F_19 ( V_41 ) ) ;
} else {
static const struct V_9 V_42 [] = {
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
V_18 = F_8 ( V_1 , V_42 ,
F_19 ( V_42 ) ) ;
}
return V_18 ;
}
static int F_24 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
int V_18 ;
V_11 -> V_43 = 0 ;
V_18 = F_12 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = F_14 ( V_1 ) ;
if ( V_18 < 0 )
return V_18 ;
if ( V_11 -> V_14 == V_15 ) {
V_18 = F_22 ( V_1 ) ;
} else {
V_18 = F_23 ( V_1 ) ;
}
if ( V_18 < 0 )
return V_18 ;
return F_17 ( V_1 ) ;
}
static void F_20 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
F_15 ( V_1 ) ;
F_12 ( V_1 ) ;
if ( V_11 -> V_28 )
F_16 ( V_1 ) ;
}
static void F_25 ( struct V_1 * V_1 , T_3 V_44 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_1 V_45 = 7 ;
T_1 V_46 = 8 ;
static const T_1 V_47 [] =
{ 0 , 4 , 8 , 12 , 1 , 2 , 3 , 5 , 6 , 9 , 7 , 10 , 13 , 11 , 14 , 15 } ;
if ( V_11 -> V_14 == V_31 ) {
V_45 += 4 ;
V_46 += 4 ;
}
if ( V_44 > 0 ) {
F_9 ( V_1 , V_45 , 0x00 ) ;
} else {
F_9 ( V_1 , V_45 , 0x01 ) ;
V_44 = 257 - V_44 ;
}
if ( V_11 -> V_28 )
V_44 = V_47 [ V_44 ] ;
F_9 ( V_1 , V_46 , V_44 ) ;
}
static void F_26 ( struct V_1 * V_1 , T_3 V_48 , T_3 V_49 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
int V_50 = V_51 ;
T_1 V_12 [ 2 ] ;
if ( V_11 -> V_14 == V_15 && V_11 -> V_16 == 1 ) {
V_50 = ( V_48 * 9267 ) / 10000 + 300 ;
F_9 ( V_1 , 3 , V_50 >> 4 ) ;
F_9 ( V_1 , 4 , V_50 & 0x0f ) ;
} else if ( V_11 -> V_16 == 2 ) {
V_50 = V_48 ;
V_50 >>= 3 ;
F_9 ( V_1 , 3 , V_50 >> 8 ) ;
F_9 ( V_1 , 4 , V_50 & 0xff ) ;
} else {
T_1 V_52 = ( 60 * V_48 + 7999 ) / 8000 ;
if ( V_52 < V_49 && V_1 -> V_35 >= 320 )
V_52 = V_49 ;
else if ( V_52 < 2 )
V_52 = 2 ;
if ( V_11 -> V_14 == V_31 && V_52 < 4 )
V_52 = 4 ;
V_50 = ( 60 * 511 * V_48 ) / ( 8000 * V_52 ) ;
if ( V_50 > 511 )
V_50 = 511 ;
V_50 = 511 - V_50 ;
V_12 [ 0 ] = V_50 & 0xff ;
V_12 [ 1 ] = V_50 >> 8 ;
F_7 ( V_1 , 0x0e , 0 , V_12 , 2 ) ;
F_9 ( V_1 , 0x02 , V_52 ) ;
}
}
static void F_27 ( struct V_1 * V_1 , T_3 V_44 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
T_1 V_53 ;
if ( V_11 -> V_14 == V_15 && V_11 -> V_16 == 1 )
F_9 ( V_1 , 0x0e , V_44 ) ;
else if ( V_11 -> V_14 == V_31 && V_11 -> V_16 == 2 )
for ( V_53 = 0x0a ; V_53 < 0x11 ; V_53 += 2 ) {
F_9 ( V_1 , V_53 , V_44 >> 8 ) ;
F_9 ( V_1 , V_53 + 1 , V_44 & 0xff ) ;
}
else
F_9 ( V_1 , 0x10 , V_44 ) ;
}
static void F_28 ( struct V_1 * V_1 , T_3 V_44 )
{
F_9 ( V_1 , 0x1c , V_44 ) ;
}
static int F_29 ( struct V_54 * V_55 )
{
struct V_1 * V_1 =
F_30 ( V_55 -> V_56 , struct V_1 , V_57 ) ;
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
V_1 -> V_58 = 0 ;
if ( ! V_1 -> V_59 )
return 0 ;
switch ( V_55 -> V_23 ) {
case V_60 :
F_25 ( V_1 , V_55 -> V_44 ) ;
break;
case V_61 :
F_28 ( V_1 , V_55 -> V_44 ) ;
break;
case V_62 :
F_26 ( V_1 , V_11 -> V_50 -> V_44 ,
V_11 -> V_49 ? V_11 -> V_49 -> V_44 : 0 ) ;
break;
case V_63 :
F_27 ( V_1 , V_55 -> V_44 ) ;
break;
}
return V_1 -> V_58 ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
struct V_64 * V_65 = & V_1 -> V_57 ;
static const struct V_66 V_52 = {
. V_67 = & V_68 ,
. V_23 = V_69 ,
. type = V_70 ,
. V_71 = L_16 ,
. V_72 = V_73 ,
. V_74 = V_75 ,
. V_76 = 1 ,
. V_77 = V_78 ,
} ;
bool V_79 = false ;
bool V_80 = false ;
bool V_81 = false ;
bool V_82 = false ;
bool V_83 = false ;
bool V_84 = false ;
bool V_85 = false ;
V_1 -> V_86 . V_57 = V_65 ;
F_32 ( V_65 , 4 ) ;
if ( V_11 -> V_14 == V_15 ) {
if ( V_11 -> V_16 == 0 )
V_84 = V_82 = V_85 = true ;
else
V_84 = V_82 = V_79 = true ;
} else {
if ( V_11 -> V_16 == 0 )
;
else if ( V_11 -> V_16 == 2 )
V_84 = V_83 = V_81 = true ;
else if ( V_11 -> V_28 )
V_84 = V_82 = V_80 =
V_85 = true ;
else
V_84 = V_82 = V_79 =
V_85 = true ;
}
if ( V_79 )
F_33 ( V_65 , & V_68 ,
V_60 , - 254 , 255 , 1 ,
V_87 ) ;
else if ( V_80 )
F_33 ( V_65 , & V_68 ,
V_60 , 0 , 15 , 1 ,
V_87 ) ;
if ( V_81 )
F_33 ( V_65 , & V_68 ,
V_61 , V_88 ,
V_89 , 1 , V_90 ) ;
if ( V_82 )
F_33 ( V_65 , & V_68 ,
V_63 , V_91 , V_92 ,
1 , V_93 ) ;
else if ( V_83 )
F_33 ( V_65 , & V_68 , V_63 ,
V_94 , V_95 ,
1 , V_96 ) ;
if ( V_84 )
V_11 -> V_50 = F_33 ( V_65 , & V_68 ,
V_62 , V_97 ,
V_98 , 1 , V_51 ) ;
if ( V_85 )
V_11 -> V_49 = F_34 ( V_65 , & V_52 , NULL ) ;
if ( V_65 -> error ) {
F_4 ( L_17 ) ;
return V_65 -> error ;
}
if ( V_84 && V_85 )
F_35 ( 2 , & V_11 -> V_50 ) ;
return 0 ;
}
static void F_36 ( struct V_1 * V_1 ,
T_1 * V_8 ,
int V_2 )
{
struct V_11 * V_11 = (struct V_11 * ) V_1 ;
unsigned char * V_99 ;
V_99 = F_37 ( V_1 , & V_11 -> V_43 , V_8 , V_2 ) ;
if ( V_99 ) {
int V_100 ;
V_100 = V_99 - V_8 ;
if ( V_100 > sizeof F_38 )
V_100 -= sizeof F_38 ;
else
V_100 = 0 ;
F_39 ( V_1 , V_101 ,
V_8 , V_100 ) ;
F_39 ( V_1 , V_102 ,
F_38 , sizeof F_38 ) ;
V_2 -= V_99 - V_8 ;
V_8 = V_99 ;
}
F_39 ( V_1 , V_103 , V_8 , V_2 ) ;
}
static int F_40 ( struct V_104 * V_105 ,
const struct V_22 * V_23 )
{
return F_41 ( V_105 , V_23 , & V_106 , sizeof( struct V_11 ) ,
V_107 ) ;
}
