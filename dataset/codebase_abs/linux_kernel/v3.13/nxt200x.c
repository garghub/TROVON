static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 ;
struct V_7 V_8 = { . V_3 = V_3 , . V_9 = 0 , . V_4 = V_4 , . V_5 = V_5 } ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ) != 1 ) {
F_3 ( L_1 ,
V_11 , V_3 , V_6 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 ;
struct V_7 V_8 = { . V_3 = V_3 , . V_9 = V_13 , . V_4 = V_4 , . V_5 = V_5 } ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ) != 1 ) {
F_3 ( L_2 ,
V_11 , V_3 , V_6 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_14 ,
const T_1 * V_4 , T_1 V_5 )
{
T_1 V_15 [ V_16 ] ;
int V_6 ;
struct V_7 V_8 = { . V_3 = V_2 -> V_17 -> V_18 , . V_9 = 0 , . V_4 = V_15 , . V_5 = V_5 + 1 } ;
if ( 1 + V_5 > sizeof( V_15 ) ) {
F_3 ( L_3 ,
V_11 , V_14 , V_5 ) ;
return - V_19 ;
}
V_15 [ 0 ] = V_14 ;
memcpy ( & V_15 [ 1 ] , V_4 , V_5 ) ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ) != 1 ) {
F_3 ( L_1 ,
V_11 , V_2 -> V_17 -> V_18 , V_6 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_14 , T_1 * V_4 , T_1 V_5 )
{
T_1 V_20 [] = { V_14 } ;
struct V_7 V_8 [] = { { . V_3 = V_2 -> V_17 -> V_18 , . V_9 = 0 , . V_4 = V_20 , . V_5 = 1 } ,
{ . V_3 = V_2 -> V_17 -> V_18 , . V_9 = V_13 , . V_4 = V_4 , . V_5 = V_5 } } ;
int V_6 ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , V_8 , 2 ) ) != 2 ) {
F_3 ( L_2 ,
V_11 , V_2 -> V_17 -> V_18 , V_6 ) ;
return - V_12 ;
}
return 0 ;
}
static T_2 F_7 ( T_2 V_21 , T_1 V_22 )
{
T_1 V_23 ;
T_2 V_24 = ( T_2 ) V_22 & 0xFF ;
V_24 <<= 8 ;
for( V_23 = 0 ; V_23 < 8 ; V_23 ++ ) {
if( ( V_21 ^ V_24 ) & 0x8000 )
V_21 = ( V_21 << 1 ) ^ V_25 ;
else
V_21 <<= 1 ;
V_24 <<= 1 ;
}
return V_21 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_14 , T_1 * V_26 , T_1 V_5 )
{
T_1 V_27 , V_28 , V_4 ;
F_9 ( L_4 , V_11 ) ;
F_5 ( V_2 , 0x35 , & V_14 , 1 ) ;
F_5 ( V_2 , 0x36 , V_26 , V_5 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_28 = V_5 ;
V_4 = 0x02 ;
break;
case V_31 :
V_27 = 0x02 ;
if ( V_14 & 0x80 ) {
V_27 = V_27 << 1 ;
if ( V_14 & 0x04 )
V_27 = V_27 >> 1 ;
}
V_28 = ( ( V_27 << 4 ) | 0x10 ) | V_5 ;
V_4 = 0x80 ;
break;
default:
return - V_19 ;
break;
}
F_5 ( V_2 , 0x34 , & V_28 , 1 ) ;
F_5 ( V_2 , 0x21 , & V_4 , 1 ) ;
F_6 ( V_2 , 0x21 , & V_4 , 1 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
if ( ( V_4 & 0x02 ) == 0 )
return 0 ;
break;
case V_31 :
if ( V_4 == 0 )
return 0 ;
break;
default:
return - V_19 ;
break;
}
F_3 ( L_5 , V_14 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_14 , T_1 * V_26 , T_1 V_5 )
{
int V_23 ;
T_1 V_4 , V_28 , V_27 ;
F_9 ( L_4 , V_11 ) ;
F_5 ( V_2 , 0x35 , & V_14 , 1 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_28 = V_5 & 0x80 ;
F_5 ( V_2 , 0x34 , & V_28 , 1 ) ;
F_6 ( V_2 , V_14 , V_26 , V_5 ) ;
return 0 ;
break;
case V_31 :
V_27 = 0x02 ;
if ( V_14 & 0x80 ) {
V_27 = V_27 << 1 ;
if ( V_14 & 0x04 )
V_27 = V_27 >> 1 ;
}
V_28 = ( V_27 << 4 ) | V_5 ;
F_5 ( V_2 , 0x34 , & V_28 , 1 ) ;
V_4 = 0x80 ;
F_5 ( V_2 , 0x21 , & V_4 , 1 ) ;
for( V_23 = 0 ; V_23 < V_5 ; V_23 ++ ) {
F_6 ( V_2 , 0x36 + V_23 , & V_26 [ V_23 ] , 1 ) ;
}
return 0 ;
break;
default:
return - V_19 ;
break;
}
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_4 , V_32 , V_33 = 0 ;
F_9 ( L_4 , V_11 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_32 = 0x40 ;
break;
case V_31 :
V_32 = 0x10 ;
break;
default:
V_32 = 0 ;
break;
}
V_4 = 0x80 ;
F_5 ( V_2 , 0x22 , & V_4 , 1 ) ;
while ( V_33 < 20 ) {
F_6 ( V_2 , 0x31 , & V_4 , 1 ) ;
if ( V_4 & V_32 )
return;
F_12 ( 10 ) ;
V_33 ++ ;
}
F_3 ( L_6
L_7 ) ;
return;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_9 ( L_4 , V_11 ) ;
V_4 = 0x00 ;
F_5 ( V_2 , 0x22 , & V_4 , 1 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_4 [ 9 ] ;
T_1 V_33 = 0 ;
F_9 ( L_4 , V_11 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x2b , V_4 , 1 ) ;
V_4 [ 0 ] = 0x70 ;
F_5 ( V_2 , 0x34 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x35 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x01 ; V_4 [ 1 ] = 0x23 ; V_4 [ 2 ] = 0x45 ; V_4 [ 3 ] = 0x67 ; V_4 [ 4 ] = 0x89 ;
V_4 [ 5 ] = 0xAB ; V_4 [ 6 ] = 0xCD ; V_4 [ 7 ] = 0xEF ; V_4 [ 8 ] = 0xC0 ;
F_5 ( V_2 , 0x36 , V_4 , 9 ) ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x21 , V_4 , 1 ) ;
while ( V_33 < 20 ) {
F_6 ( V_2 , 0x21 , V_4 , 1 ) ;
if ( V_4 [ 0 ] == 0 )
return;
F_12 ( 10 ) ;
V_33 ++ ;
}
F_3 ( L_8 ) ;
return;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_26 )
{
T_1 V_4 , V_34 = 0 ;
F_9 ( L_4 , V_11 ) ;
F_9 ( L_9 , 4 , V_26 + 1 ) ;
switch ( V_2 -> V_29 ) {
case V_31 :
if ( F_1 ( V_2 , V_26 [ 0 ] , V_26 + 1 , 4 ) )
F_3 ( L_10 ) ;
while ( V_34 < 20 ) {
F_4 ( V_2 , V_26 [ 0 ] , & V_4 , 1 ) ;
if ( V_4 & 0x40 )
return 0 ;
F_12 ( 100 ) ;
V_34 ++ ;
}
F_3 ( L_11 ) ;
break;
case V_30 :
V_4 = 0x03 ;
F_5 ( V_2 , 0x20 , & V_4 , 1 ) ;
V_4 = 0x04 ;
F_5 ( V_2 , 0x34 , & V_4 , 1 ) ;
F_5 ( V_2 , 0x36 , V_26 + 1 , 4 ) ;
V_4 = V_26 [ 0 ] << 1 ;
F_5 ( V_2 , 0x35 , & V_4 , 1 ) ;
V_4 = 0x80 ;
F_5 ( V_2 , 0x21 , & V_4 , 1 ) ;
while ( V_34 < 20 ) {
F_6 ( V_2 , 0x21 , & V_4 , 1 ) ;
if ( ( V_4 & 0x80 ) == 0x00 )
return 0 ;
F_12 ( 100 ) ;
V_34 ++ ;
}
F_3 ( L_12 ) ;
break;
default:
return - V_19 ;
break;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_9 ( L_4 , V_11 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_4 = 0x08 ;
F_5 ( V_2 , 0x08 , & V_4 , 1 ) ;
V_4 = 0x00 ;
F_5 ( V_2 , 0x08 , & V_4 , 1 ) ;
break;
case V_31 :
F_10 ( V_2 , 0x08 , & V_4 , 1 ) ;
V_4 = 0x08 ;
F_8 ( V_2 , 0x08 , & V_4 , 1 ) ;
V_4 = 0x00 ;
F_8 ( V_2 , 0x08 , & V_4 , 1 ) ;
break;
default:
break;
}
return;
}
static int F_17 ( struct V_35 * V_36 , const struct V_37 * V_38 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_4 [ 3 ] , V_40 = 0 , V_41 = 0 ;
T_2 V_42 , V_43 , V_21 = 0 ;
F_9 ( L_4 , V_11 ) ;
F_9 ( L_13 , V_38 -> V_44 ) ;
F_6 ( V_2 , 0x10 , V_4 , 1 ) ;
if ( V_4 [ 0 ] & 0x10 )
V_42 = 0x1000 ;
else
V_42 = 0x0000 ;
F_9 ( L_14 , V_42 ) ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
for ( V_43 = 0 ; V_43 < V_38 -> V_44 ; V_43 ++ ) {
if ( V_40 == 0 ) {
V_21 = 0 ;
V_41 = 0x28 ;
V_4 [ 0 ] = ( ( V_42 + V_43 ) >> 8 ) ;
V_4 [ 1 ] = ( V_42 + V_43 ) & 0xFF ;
V_4 [ 2 ] = 0x81 ;
F_5 ( V_2 , 0x29 , V_4 , 3 ) ;
}
V_40 ++ ;
V_41 ++ ;
if ( ( V_40 % 4 ) == 0 )
F_5 ( V_2 , V_41 , & V_38 -> V_26 [ V_43 - 3 ] , 4 ) ;
V_21 = F_7 ( V_21 , V_38 -> V_26 [ V_43 ] ) ;
if ( ( V_40 == 255 ) || ( V_43 + 1 == V_38 -> V_44 ) ) {
F_5 ( V_2 , V_41 + 4 - ( V_40 % 4 ) ,
& V_38 -> V_26 [ V_43 - ( V_40 % 4 ) + 1 ] ,
V_40 % 4 ) ;
V_4 [ 0 ] = V_21 << 8 ;
V_4 [ 1 ] = V_21 & 0xFF ;
F_5 ( V_2 , 0x2C , V_4 , 2 ) ;
F_6 ( V_2 , 0x2A , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
V_40 = 0 ;
}
}
return 0 ;
}
static int F_18 ( struct V_35 * V_36 , const struct V_37 * V_38 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_4 [ 3 ] ;
T_2 V_42 , V_43 , V_21 = 0 ;
F_9 ( L_4 , V_11 ) ;
F_9 ( L_13 , V_38 -> V_44 ) ;
V_42 = 0x1000 ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
for ( V_43 = 0 ; V_43 < V_38 -> V_44 ; V_43 ++ ) {
V_21 = F_7 ( V_21 , V_38 -> V_26 [ V_43 ] ) ;
}
V_4 [ 0 ] = V_42 >> 8 ;
V_4 [ 1 ] = V_42 & 0xFF ;
V_4 [ 2 ] = 0x81 ;
F_5 ( V_2 , 0x29 , V_4 , 3 ) ;
for ( V_43 = 0 ; V_43 < V_38 -> V_44 ; ) {
F_5 ( V_2 , 0x2C , & V_38 -> V_26 [ V_43 ] ,
V_38 -> V_44 - V_43 > 255 ? 255 : V_38 -> V_44 - V_43 ) ;
V_43 += ( V_38 -> V_44 - V_43 > 255 ? 255 : V_38 -> V_44 - V_43 ) ;
}
V_4 [ 0 ] = V_21 >> 8 ;
V_4 [ 1 ] = V_21 & 0xFF ;
F_9 ( L_15 , V_4 [ 0 ] , V_4 [ 1 ] ) ;
F_5 ( V_2 , 0x2C , V_4 , 2 ) ;
F_6 ( V_2 , 0x2C , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
return 0 ;
}
static int F_19 ( struct V_35 * V_36 )
{
struct V_45 * V_46 = & V_36 -> V_47 ;
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_4 [ 5 ] ;
F_11 ( V_2 ) ;
if ( V_2 -> V_29 == V_31 ) {
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x14 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x17 , V_4 , 1 ) ;
}
switch ( V_46 -> V_48 ) {
case V_49 :
case V_50 :
if ( V_2 -> V_17 -> V_51 )
V_2 -> V_17 -> V_51 ( V_36 , 1 ) ;
break;
case V_52 :
if ( V_2 -> V_17 -> V_51 )
V_2 -> V_17 -> V_51 ( V_36 , 0 ) ;
break;
default:
return - V_19 ;
break;
}
if ( V_36 -> V_53 . V_54 . V_55 ) {
V_36 -> V_53 . V_54 . V_55 ( V_36 , V_4 , 5 ) ;
F_15 ( V_2 , V_4 ) ;
}
F_16 ( V_2 ) ;
switch ( V_46 -> V_48 ) {
case V_49 :
case V_50 :
V_4 [ 0 ] = 0x74 ;
break;
case V_52 :
V_4 [ 0 ] = 0x70 ;
break;
default:
return - V_19 ;
break;
}
F_5 ( V_2 , 0x42 , V_4 , 1 ) ;
switch ( V_2 -> V_29 ) {
case V_30 :
V_4 [ 0 ] = 0x87 ;
break;
case V_31 :
V_4 [ 0 ] = 0x07 ;
break;
default:
return - V_19 ;
break;
}
F_5 ( V_2 , 0x57 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x10 ;
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_29 ) {
case V_30 :
F_8 ( V_2 , 0x58 , V_4 , 2 ) ;
break;
case V_31 :
F_5 ( V_2 , 0x58 , V_4 , 2 ) ;
break;
default:
return - V_19 ;
break;
}
switch ( V_46 -> V_48 ) {
case V_49 :
V_4 [ 0 ] = 0x68 ;
break;
case V_50 :
V_4 [ 0 ] = 0x64 ;
break;
case V_52 :
V_4 [ 0 ] = 0x60 ;
break;
default:
return - V_19 ;
break;
}
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_29 ) {
case V_30 :
F_8 ( V_2 , 0x5C , V_4 , 2 ) ;
break;
case V_31 :
F_5 ( V_2 , 0x5C , V_4 , 2 ) ;
break;
default:
return - V_19 ;
break;
}
V_4 [ 0 ] = 0x05 ;
F_5 ( V_2 , 0x43 , V_4 , 1 ) ;
if ( V_2 -> V_29 == V_31 ) {
V_4 [ 0 ] = 0x00 ;
V_4 [ 1 ] = 0x00 ;
F_5 ( V_2 , 0x46 , V_4 , 2 ) ;
}
V_4 [ 0 ] = 0x80 ;
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_29 ) {
case V_30 :
F_8 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
case V_31 :
F_5 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
default:
return - V_19 ;
break;
}
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x4D , V_4 , 1 ) ;
V_4 [ 0 ] = 0x44 ;
F_5 ( V_2 , 0x55 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x41 , V_4 , 1 ) ;
if ( V_2 -> V_29 == V_31 ) {
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x24 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
F_10 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x10 ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
F_10 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x04 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x81 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ; V_4 [ 1 ] = 0x00 ; V_4 [ 2 ] = 0x00 ;
F_8 ( V_2 , 0x82 , V_4 , 3 ) ;
F_10 ( V_2 , 0x88 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x11 ;
F_8 ( V_2 , 0x88 , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x44 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
}
switch ( V_46 -> V_48 ) {
case V_49 :
V_4 [ 0 ] = 0x02 ;
break;
case V_50 :
V_4 [ 0 ] = 0x03 ;
break;
case V_52 :
V_4 [ 0 ] = 0x00 ;
break;
default:
return - V_19 ;
break;
}
F_5 ( V_2 , 0x30 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x41 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ;
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_29 ) {
case V_30 :
F_8 ( V_2 , 0x49 , V_4 , 2 ) ;
F_8 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
case V_31 :
F_5 ( V_2 , 0x49 , V_4 , 2 ) ;
F_5 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
default:
return - V_19 ;
break;
}
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x41 , V_4 , 1 ) ;
F_13 ( V_2 ) ;
if ( V_2 -> V_29 == V_31 ) {
F_14 ( V_2 ) ;
V_4 [ 0 ] = 0xF0 ;
V_4 [ 1 ] = 0x00 ;
F_5 ( V_2 , 0x5C , V_4 , 2 ) ;
}
return 0 ;
}
static int F_20 ( struct V_35 * V_36 , T_3 * V_56 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_57 ;
F_6 ( V_2 , 0x31 , & V_57 , 1 ) ;
* V_56 = 0 ;
if ( V_57 & 0x20 ) {
* V_56 |= V_58 ;
* V_56 |= V_59 ;
* V_56 |= V_60 ;
* V_56 |= V_61 ;
* V_56 |= V_62 ;
}
return 0 ;
}
static int F_21 ( struct V_35 * V_36 , T_4 * V_63 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_64 [ 3 ] ;
F_10 ( V_2 , 0xE6 , V_64 , 3 ) ;
* V_63 = ( ( V_64 [ 0 ] << 8 ) + V_64 [ 1 ] ) * 8 ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 , T_2 * V_65 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_64 [ 2 ] ;
T_2 V_66 = 0 ;
V_64 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0xA1 , V_64 , 1 ) ;
F_10 ( V_2 , 0xA6 , V_64 , 2 ) ;
V_66 = ( V_64 [ 0 ] << 8 ) | V_64 [ 1 ] ;
* V_65 = ( ( 0x7FFF - V_66 ) & 0x0FFF ) * 16 ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 , T_2 * V_67 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_64 [ 2 ] ;
T_2 V_66 = 0 , V_68 ;
T_4 V_69 = 0 ;
V_64 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0xA1 , V_64 , 1 ) ;
F_10 ( V_2 , 0xA6 , V_64 , 2 ) ;
V_66 = ( V_64 [ 0 ] << 8 ) | V_64 [ 1 ] ;
V_68 = 0x7FFF - V_66 ;
if ( V_68 > 0x7F00 )
V_69 = 1000 * 24 + ( 1000 * ( 30 - 24 ) * ( V_68 - 0x7F00 ) / ( 0x7FFF - 0x7F00 ) ) ;
else if ( V_68 > 0x7EC0 )
V_69 = 1000 * 18 + ( 1000 * ( 24 - 18 ) * ( V_68 - 0x7EC0 ) / ( 0x7F00 - 0x7EC0 ) ) ;
else if ( V_68 > 0x7C00 )
V_69 = 1000 * 12 + ( 1000 * ( 18 - 12 ) * ( V_68 - 0x7C00 ) / ( 0x7EC0 - 0x7C00 ) ) ;
else
V_69 = 1000 * 0 + ( 1000 * ( 12 - 0 ) * ( V_68 - 0 ) / ( 0x7C00 - 0 ) ) ;
* V_67 = V_69 * ( 0xFFFF / 32000 ) ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 , T_4 * V_70 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_64 [ 3 ] ;
F_10 ( V_2 , 0xE6 , V_64 , 3 ) ;
* V_70 = V_64 [ 2 ] ;
return 0 ;
}
static int F_25 ( struct V_35 * V_36 )
{
return 0 ;
}
static int F_26 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
const struct V_37 * V_38 ;
int V_71 ;
T_1 V_4 [ 2 ] ;
F_27 ( L_16 ,
V_11 , V_72 ) ;
V_71 = F_28 ( & V_38 , V_72 ,
V_2 -> V_10 -> V_73 . V_74 ) ;
F_27 ( L_17 , V_11 ) ;
if ( V_71 ) {
F_29 ( L_18
L_19 , V_11 ) ;
return V_71 ;
}
V_71 = F_17 ( V_36 , V_38 ) ;
F_30 ( V_38 ) ;
if ( V_71 ) {
F_29 ( L_20 , V_11 ) ;
return V_71 ;
}
F_31 ( L_21 , V_11 ) ;
F_11 ( V_2 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
F_11 ( V_2 ) ;
V_4 [ 0 ] = 0x0F ;
F_5 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0xF1 ;
F_5 ( V_2 , 0x57 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x20 ;
F_5 ( V_2 , 0x09 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x7E ;
V_4 [ 1 ] = 0x00 ;
F_5 ( V_2 , 0xE9 , V_4 , 2 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0xCC , V_4 , 1 ) ;
return 0 ;
}
static int F_32 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
const struct V_37 * V_38 ;
int V_71 ;
T_1 V_4 [ 3 ] ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x1E , V_4 , 1 ) ;
F_27 ( L_16 ,
V_11 , V_75 ) ;
V_71 = F_28 ( & V_38 , V_75 ,
V_2 -> V_10 -> V_73 . V_74 ) ;
F_27 ( L_17 , V_11 ) ;
if ( V_71 ) {
F_29 ( L_18
L_19 , V_11 ) ;
return V_71 ;
}
V_71 = F_18 ( V_36 , V_38 ) ;
F_30 ( V_38 ) ;
if ( V_71 ) {
F_29 ( L_20 , V_11 ) ;
return V_71 ;
}
F_31 ( L_21 , V_11 ) ;
V_4 [ 0 ] = 0x01 ;
F_5 ( V_2 , 0x19 , V_4 , 1 ) ;
F_14 ( V_2 ) ;
F_11 ( V_2 ) ;
F_11 ( V_2 ) ;
F_14 ( V_2 ) ;
F_11 ( V_2 ) ;
V_4 [ 0 ] = 0xFF ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0xD7 ;
F_5 ( V_2 , 0x57 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x07 ;
V_4 [ 1 ] = 0xfe ;
F_5 ( V_2 , 0x35 , V_4 , 2 ) ;
V_4 [ 0 ] = 0x12 ;
F_5 ( V_2 , 0x34 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x21 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x21 ;
F_5 ( V_2 , 0x0A , V_4 , 1 ) ;
V_4 [ 0 ] = 0x01 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x7E ;
V_4 [ 1 ] = 0x00 ;
F_5 ( V_2 , 0xE9 , V_4 , 2 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0xCC , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
F_10 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x10 ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
F_10 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x01 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x70 ;
F_8 ( V_2 , 0x81 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x31 ; V_4 [ 1 ] = 0x5E ; V_4 [ 2 ] = 0x66 ;
F_8 ( V_2 , 0x82 , V_4 , 3 ) ;
F_10 ( V_2 , 0x88 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x11 ;
F_8 ( V_2 , 0x88 , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x40 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
F_6 ( V_2 , 0x10 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x10 ;
F_5 ( V_2 , 0x10 , V_4 , 1 ) ;
F_6 ( V_2 , 0x0A , V_4 , 1 ) ;
V_4 [ 0 ] = 0x21 ;
F_5 ( V_2 , 0x0A , V_4 , 1 ) ;
F_14 ( V_2 ) ;
V_4 [ 0 ] = 0x21 ;
F_5 ( V_2 , 0x0A , V_4 , 1 ) ;
V_4 [ 0 ] = 0x7E ;
F_5 ( V_2 , 0xE9 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0xEA , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
F_10 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x10 ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
F_10 ( V_2 , 0x08 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x08 , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x04 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_8 ( V_2 , 0x81 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ; V_4 [ 1 ] = 0x00 ; V_4 [ 2 ] = 0x00 ;
F_8 ( V_2 , 0x82 , V_4 , 3 ) ;
F_10 ( V_2 , 0x88 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x11 ;
F_8 ( V_2 , 0x88 , V_4 , 1 ) ;
F_10 ( V_2 , 0x80 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x44 ;
F_8 ( V_2 , 0x80 , V_4 , 1 ) ;
F_6 ( V_2 , 0x10 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x12 ;
F_5 ( V_2 , 0x10 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x13 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x16 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x14 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x14 , V_4 , 1 ) ;
F_5 ( V_2 , 0x17 , V_4 , 1 ) ;
F_5 ( V_2 , 0x14 , V_4 , 1 ) ;
F_5 ( V_2 , 0x17 , V_4 , 1 ) ;
return 0 ;
}
static int F_33 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
int V_71 = 0 ;
if ( ! V_2 -> V_76 ) {
switch ( V_2 -> V_29 ) {
case V_30 :
V_71 = F_26 ( V_36 ) ;
break;
case V_31 :
V_71 = F_32 ( V_36 ) ;
break;
default:
return - V_19 ;
break;
}
V_2 -> V_76 = 1 ;
}
return V_71 ;
}
static int F_34 ( struct V_35 * V_36 , struct V_77 * V_78 )
{
V_78 -> V_79 = 500 ;
V_78 -> V_80 = 0 ;
V_78 -> V_81 = 0 ;
return 0 ;
}
static void F_35 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
F_36 ( V_2 ) ;
}
struct V_35 * F_37 ( const struct V_82 * V_17 ,
struct V_83 * V_10 )
{
struct V_1 * V_2 = NULL ;
T_1 V_4 [] = { 0 , 0 , 0 , 0 , 0 } ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_84 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_76 = 0 ;
F_6 ( V_2 , 0x00 , V_4 , 5 ) ;
F_9 ( L_22 , 5 , V_4 ) ;
switch ( V_4 [ 0 ] ) {
case 0x04 :
V_2 -> V_29 = V_30 ;
F_31 ( L_23 ) ;
break;
case 0x05 :
V_2 -> V_29 = V_31 ;
F_31 ( L_24 ) ;
break;
default:
goto error;
}
switch ( V_2 -> V_29 ) {
case V_30 :
if ( V_4 [ 0 ] != 0x04 ) goto error;
if ( V_4 [ 1 ] != 0x02 ) goto error;
if ( V_4 [ 2 ] != 0x11 ) goto error;
if ( V_4 [ 3 ] != 0x20 ) goto error;
if ( V_4 [ 4 ] != 0x00 ) goto error;
break;
case V_31 :
if ( V_4 [ 0 ] != 0x05 ) goto error;
break;
default:
goto error;
}
memcpy ( & V_2 -> V_85 . V_53 , & V_86 , sizeof( struct V_87 ) ) ;
V_2 -> V_85 . V_39 = V_2 ;
return & V_2 -> V_85 ;
error:
F_36 ( V_2 ) ;
F_29 ( L_25 , 5 , V_4 ) ;
return NULL ;
}
