static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 ;
struct V_7 V_8 = { . V_3 = V_3 , . V_9 = 0 , . V_4 = V_4 , . V_5 = V_5 } ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ) != 1 ) {
F_3 ( V_11 L_1 ,
V_12 , V_3 , V_6 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
int V_6 ;
struct V_7 V_8 = { . V_3 = V_3 , . V_9 = V_14 , . V_4 = V_4 , . V_5 = V_5 } ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ) != 1 ) {
F_3 ( V_11 L_2 ,
V_12 , V_3 , V_6 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_15 ,
const T_1 * V_4 , T_1 V_5 )
{
T_1 V_16 [ V_5 + 1 ] ;
int V_6 ;
struct V_7 V_8 = { . V_3 = V_2 -> V_17 -> V_18 , . V_9 = 0 , . V_4 = V_16 , . V_5 = V_5 + 1 } ;
V_16 [ 0 ] = V_15 ;
memcpy ( & V_16 [ 1 ] , V_4 , V_5 ) ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , & V_8 , 1 ) ) != 1 ) {
F_3 ( V_11 L_1 ,
V_12 , V_2 -> V_17 -> V_18 , V_6 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_15 , T_1 * V_4 , T_1 V_5 )
{
T_1 V_19 [] = { V_15 } ;
struct V_7 V_8 [] = { { . V_3 = V_2 -> V_17 -> V_18 , . V_9 = 0 , . V_4 = V_19 , . V_5 = 1 } ,
{ . V_3 = V_2 -> V_17 -> V_18 , . V_9 = V_14 , . V_4 = V_4 , . V_5 = V_5 } } ;
int V_6 ;
if ( ( V_6 = F_2 ( V_2 -> V_10 , V_8 , 2 ) ) != 2 ) {
F_3 ( V_11 L_2 ,
V_12 , V_2 -> V_17 -> V_18 , V_6 ) ;
return - V_13 ;
}
return 0 ;
}
static T_2 F_7 ( T_2 V_20 , T_1 V_21 )
{
T_1 V_22 ;
T_2 V_23 = ( T_2 ) V_21 & 0xFF ;
V_23 <<= 8 ;
for( V_22 = 0 ; V_22 < 8 ; V_22 ++ ) {
if( ( V_20 ^ V_23 ) & 0x8000 )
V_20 = ( V_20 << 1 ) ^ V_24 ;
else
V_20 <<= 1 ;
V_23 <<= 1 ;
}
return V_20 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_15 , T_1 * V_25 , T_1 V_5 )
{
T_1 V_26 , V_27 , V_4 ;
F_9 ( L_3 , V_12 ) ;
F_5 ( V_2 , 0x35 , & V_15 , 1 ) ;
F_5 ( V_2 , 0x36 , V_25 , V_5 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_27 = V_5 ;
V_4 = 0x02 ;
break;
case V_30 :
V_26 = 0x02 ;
if ( V_15 & 0x80 ) {
V_26 = V_26 << 1 ;
if ( V_15 & 0x04 )
V_26 = V_26 >> 1 ;
}
V_27 = ( ( V_26 << 4 ) | 0x10 ) | V_5 ;
V_4 = 0x80 ;
break;
default:
return - V_31 ;
break;
}
F_5 ( V_2 , 0x34 , & V_27 , 1 ) ;
F_5 ( V_2 , 0x21 , & V_4 , 1 ) ;
F_6 ( V_2 , 0x21 , & V_4 , 1 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
if ( ( V_4 & 0x02 ) == 0 )
return 0 ;
break;
case V_30 :
if ( V_4 == 0 )
return 0 ;
break;
default:
return - V_31 ;
break;
}
F_3 ( V_11 L_4 , V_15 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_15 , T_1 * V_25 , T_1 V_5 )
{
int V_22 ;
T_1 V_4 , V_27 , V_26 ;
F_9 ( L_3 , V_12 ) ;
F_5 ( V_2 , 0x35 , & V_15 , 1 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_27 = V_5 & 0x80 ;
F_5 ( V_2 , 0x34 , & V_27 , 1 ) ;
F_6 ( V_2 , V_15 , V_25 , V_5 ) ;
return 0 ;
break;
case V_30 :
V_26 = 0x02 ;
if ( V_15 & 0x80 ) {
V_26 = V_26 << 1 ;
if ( V_15 & 0x04 )
V_26 = V_26 >> 1 ;
}
V_27 = ( V_26 << 4 ) | V_5 ;
F_5 ( V_2 , 0x34 , & V_27 , 1 ) ;
V_4 = 0x80 ;
F_5 ( V_2 , 0x21 , & V_4 , 1 ) ;
for( V_22 = 0 ; V_22 < V_5 ; V_22 ++ ) {
F_6 ( V_2 , 0x36 + V_22 , & V_25 [ V_22 ] , 1 ) ;
}
return 0 ;
break;
default:
return - V_31 ;
break;
}
}
static void F_11 ( struct V_1 * V_2 )
{
T_1 V_4 , V_32 , V_33 = 0 ;
F_9 ( L_3 , V_12 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_32 = 0x40 ;
break;
case V_30 :
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
F_3 ( V_11 L_5 ) ;
return;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_9 ( L_3 , V_12 ) ;
V_4 = 0x00 ;
F_5 ( V_2 , 0x22 , & V_4 , 1 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_4 [ 9 ] ;
T_1 V_33 = 0 ;
F_9 ( L_3 , V_12 ) ;
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
F_3 ( V_11 L_6 ) ;
return;
}
static int F_15 ( struct V_1 * V_2 , T_1 * V_25 )
{
T_1 V_4 , V_34 = 0 ;
F_9 ( L_3 , V_12 ) ;
F_9 ( L_7 , V_25 [ 1 ] , V_25 [ 2 ] , V_25 [ 3 ] , V_25 [ 4 ] ) ;
switch ( V_2 -> V_28 ) {
case V_30 :
if ( F_1 ( V_2 , V_25 [ 0 ] , V_25 + 1 , 4 ) )
F_3 ( V_11 L_8 ) ;
while ( V_34 < 20 ) {
F_4 ( V_2 , V_25 [ 0 ] , & V_4 , 1 ) ;
if ( V_4 & 0x40 )
return 0 ;
F_12 ( 100 ) ;
V_34 ++ ;
}
F_3 ( L_9 ) ;
break;
case V_29 :
V_4 = 0x03 ;
F_5 ( V_2 , 0x20 , & V_4 , 1 ) ;
V_4 = 0x04 ;
F_5 ( V_2 , 0x34 , & V_4 , 1 ) ;
F_5 ( V_2 , 0x36 , V_25 + 1 , 4 ) ;
V_4 = V_25 [ 0 ] << 1 ;
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
F_3 ( L_10 ) ;
break;
default:
return - V_31 ;
break;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
T_1 V_4 ;
F_9 ( L_3 , V_12 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_4 = 0x08 ;
F_5 ( V_2 , 0x08 , & V_4 , 1 ) ;
V_4 = 0x00 ;
F_5 ( V_2 , 0x08 , & V_4 , 1 ) ;
break;
case V_30 :
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
T_2 V_42 , V_43 , V_20 = 0 ;
F_9 ( L_3 , V_12 ) ;
F_9 ( L_11 , V_38 -> V_44 ) ;
F_6 ( V_2 , 0x10 , V_4 , 1 ) ;
if ( V_4 [ 0 ] & 0x10 )
V_42 = 0x1000 ;
else
V_42 = 0x0000 ;
F_9 ( L_12 , V_42 ) ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
for ( V_43 = 0 ; V_43 < V_38 -> V_44 ; V_43 ++ ) {
if ( V_40 == 0 ) {
V_20 = 0 ;
V_41 = 0x28 ;
V_4 [ 0 ] = ( ( V_42 + V_43 ) >> 8 ) ;
V_4 [ 1 ] = ( V_42 + V_43 ) & 0xFF ;
V_4 [ 2 ] = 0x81 ;
F_5 ( V_2 , 0x29 , V_4 , 3 ) ;
}
V_40 ++ ;
V_41 ++ ;
if ( ( V_40 % 4 ) == 0 )
F_5 ( V_2 , V_41 , & V_38 -> V_25 [ V_43 - 3 ] , 4 ) ;
V_20 = F_7 ( V_20 , V_38 -> V_25 [ V_43 ] ) ;
if ( ( V_40 == 255 ) || ( V_43 + 1 == V_38 -> V_44 ) ) {
F_5 ( V_2 , V_41 + 4 - ( V_40 % 4 ) ,
& V_38 -> V_25 [ V_43 - ( V_40 % 4 ) + 1 ] ,
V_40 % 4 ) ;
V_4 [ 0 ] = V_20 << 8 ;
V_4 [ 1 ] = V_20 & 0xFF ;
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
T_2 V_42 , V_43 , V_20 = 0 ;
F_9 ( L_3 , V_12 ) ;
F_9 ( L_11 , V_38 -> V_44 ) ;
V_42 = 0x1000 ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
for ( V_43 = 0 ; V_43 < V_38 -> V_44 ; V_43 ++ ) {
V_20 = F_7 ( V_20 , V_38 -> V_25 [ V_43 ] ) ;
}
V_4 [ 0 ] = V_42 >> 8 ;
V_4 [ 1 ] = V_42 & 0xFF ;
V_4 [ 2 ] = 0x81 ;
F_5 ( V_2 , 0x29 , V_4 , 3 ) ;
for ( V_43 = 0 ; V_43 < V_38 -> V_44 ; ) {
F_5 ( V_2 , 0x2C , & V_38 -> V_25 [ V_43 ] ,
V_38 -> V_44 - V_43 > 255 ? 255 : V_38 -> V_44 - V_43 ) ;
V_43 += ( V_38 -> V_44 - V_43 > 255 ? 255 : V_38 -> V_44 - V_43 ) ;
}
V_4 [ 0 ] = V_20 >> 8 ;
V_4 [ 1 ] = V_20 & 0xFF ;
F_9 ( L_13 , V_4 [ 0 ] , V_4 [ 1 ] ) ;
F_5 ( V_2 , 0x2C , V_4 , 2 ) ;
F_6 ( V_2 , 0x2C , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ;
F_5 ( V_2 , 0x2B , V_4 , 1 ) ;
return 0 ;
}
static int F_19 ( struct V_35 * V_36 ,
struct V_45 * V_46 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_4 [ 5 ] ;
F_11 ( V_2 ) ;
if ( V_2 -> V_28 == V_30 ) {
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x14 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x17 , V_4 , 1 ) ;
}
switch ( V_46 -> V_47 . V_48 . V_49 ) {
case V_50 :
case V_51 :
if ( V_2 -> V_17 -> V_52 )
V_2 -> V_17 -> V_52 ( V_36 , 1 ) ;
break;
case V_53 :
if ( V_2 -> V_17 -> V_52 )
V_2 -> V_17 -> V_52 ( V_36 , 0 ) ;
break;
default:
return - V_31 ;
break;
}
if ( V_36 -> V_54 . V_55 . V_56 ) {
V_36 -> V_54 . V_55 . V_56 ( V_36 , V_46 , V_4 , 5 ) ;
F_15 ( V_2 , V_4 ) ;
}
F_16 ( V_2 ) ;
switch ( V_46 -> V_47 . V_48 . V_49 ) {
case V_50 :
case V_51 :
V_4 [ 0 ] = 0x74 ;
break;
case V_53 :
V_4 [ 0 ] = 0x70 ;
break;
default:
return - V_31 ;
break;
}
F_5 ( V_2 , 0x42 , V_4 , 1 ) ;
switch ( V_2 -> V_28 ) {
case V_29 :
V_4 [ 0 ] = 0x87 ;
break;
case V_30 :
V_4 [ 0 ] = 0x07 ;
break;
default:
return - V_31 ;
break;
}
F_5 ( V_2 , 0x57 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x10 ;
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_8 ( V_2 , 0x58 , V_4 , 2 ) ;
break;
case V_30 :
F_5 ( V_2 , 0x58 , V_4 , 2 ) ;
break;
default:
return - V_31 ;
break;
}
switch ( V_46 -> V_47 . V_48 . V_49 ) {
case V_50 :
V_4 [ 0 ] = 0x68 ;
break;
case V_51 :
V_4 [ 0 ] = 0x64 ;
break;
case V_53 :
V_4 [ 0 ] = 0x60 ;
break;
default:
return - V_31 ;
break;
}
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_8 ( V_2 , 0x5C , V_4 , 2 ) ;
break;
case V_30 :
F_5 ( V_2 , 0x5C , V_4 , 2 ) ;
break;
default:
return - V_31 ;
break;
}
V_4 [ 0 ] = 0x05 ;
F_5 ( V_2 , 0x43 , V_4 , 1 ) ;
if ( V_2 -> V_28 == V_30 ) {
V_4 [ 0 ] = 0x00 ;
V_4 [ 1 ] = 0x00 ;
F_5 ( V_2 , 0x46 , V_4 , 2 ) ;
}
V_4 [ 0 ] = 0x80 ;
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_8 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
case V_30 :
F_5 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
default:
return - V_31 ;
break;
}
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x4D , V_4 , 1 ) ;
V_4 [ 0 ] = 0x44 ;
F_5 ( V_2 , 0x55 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x41 , V_4 , 1 ) ;
if ( V_2 -> V_28 == V_30 ) {
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
switch ( V_46 -> V_47 . V_48 . V_49 ) {
case V_50 :
V_4 [ 0 ] = 0x02 ;
break;
case V_51 :
V_4 [ 0 ] = 0x03 ;
break;
case V_53 :
V_4 [ 0 ] = 0x00 ;
break;
default:
return - V_31 ;
break;
}
F_5 ( V_2 , 0x30 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x41 , V_4 , 1 ) ;
V_4 [ 0 ] = 0x80 ;
V_4 [ 1 ] = 0x00 ;
switch ( V_2 -> V_28 ) {
case V_29 :
F_8 ( V_2 , 0x49 , V_4 , 2 ) ;
F_8 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
case V_30 :
F_5 ( V_2 , 0x49 , V_4 , 2 ) ;
F_5 ( V_2 , 0x4B , V_4 , 2 ) ;
break;
default:
return - V_31 ;
break;
}
V_4 [ 0 ] = 0x04 ;
F_5 ( V_2 , 0x41 , V_4 , 1 ) ;
F_13 ( V_2 ) ;
if ( V_2 -> V_28 == V_30 ) {
F_14 ( V_2 ) ;
V_4 [ 0 ] = 0xF0 ;
V_4 [ 1 ] = 0x00 ;
F_5 ( V_2 , 0x5C , V_4 , 2 ) ;
}
return 0 ;
}
static int F_20 ( struct V_35 * V_36 , T_3 * V_57 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_58 ;
F_6 ( V_2 , 0x31 , & V_58 , 1 ) ;
* V_57 = 0 ;
if ( V_58 & 0x20 ) {
* V_57 |= V_59 ;
* V_57 |= V_60 ;
* V_57 |= V_61 ;
* V_57 |= V_62 ;
* V_57 |= V_63 ;
}
return 0 ;
}
static int F_21 ( struct V_35 * V_36 , T_4 * V_64 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_65 [ 3 ] ;
F_10 ( V_2 , 0xE6 , V_65 , 3 ) ;
* V_64 = ( ( V_65 [ 0 ] << 8 ) + V_65 [ 1 ] ) * 8 ;
return 0 ;
}
static int F_22 ( struct V_35 * V_36 , T_2 * V_66 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_65 [ 2 ] ;
T_2 V_67 = 0 ;
V_65 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0xA1 , V_65 , 1 ) ;
F_10 ( V_2 , 0xA6 , V_65 , 2 ) ;
V_67 = ( V_65 [ 0 ] << 8 ) | V_65 [ 1 ] ;
* V_66 = ( ( 0x7FFF - V_67 ) & 0x0FFF ) * 16 ;
return 0 ;
}
static int F_23 ( struct V_35 * V_36 , T_2 * V_68 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_65 [ 2 ] ;
T_2 V_67 = 0 , V_69 ;
T_4 V_70 = 0 ;
V_65 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0xA1 , V_65 , 1 ) ;
F_10 ( V_2 , 0xA6 , V_65 , 2 ) ;
V_67 = ( V_65 [ 0 ] << 8 ) | V_65 [ 1 ] ;
V_69 = 0x7FFF - V_67 ;
if ( V_69 > 0x7F00 )
V_70 = 1000 * 24 + ( 1000 * ( 30 - 24 ) * ( V_69 - 0x7F00 ) / ( 0x7FFF - 0x7F00 ) ) ;
else if ( V_69 > 0x7EC0 )
V_70 = 1000 * 18 + ( 1000 * ( 24 - 18 ) * ( V_69 - 0x7EC0 ) / ( 0x7F00 - 0x7EC0 ) ) ;
else if ( V_69 > 0x7C00 )
V_70 = 1000 * 12 + ( 1000 * ( 18 - 12 ) * ( V_69 - 0x7C00 ) / ( 0x7EC0 - 0x7C00 ) ) ;
else
V_70 = 1000 * 0 + ( 1000 * ( 12 - 0 ) * ( V_69 - 0 ) / ( 0x7C00 - 0 ) ) ;
* V_68 = V_70 * ( 0xFFFF / 32000 ) ;
return 0 ;
}
static int F_24 ( struct V_35 * V_36 , T_4 * V_71 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
T_1 V_65 [ 3 ] ;
F_10 ( V_2 , 0xE6 , V_65 , 3 ) ;
* V_71 = V_65 [ 2 ] ;
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
int V_72 ;
T_1 V_4 [ 2 ] ;
F_3 ( L_14 , V_73 ) ;
V_72 = F_27 ( & V_38 , V_73 ,
V_2 -> V_10 -> V_74 . V_75 ) ;
F_3 ( L_15 ) ;
if ( V_72 ) {
F_3 ( L_16 ) ;
return V_72 ;
}
V_72 = F_17 ( V_36 , V_38 ) ;
F_28 ( V_38 ) ;
if ( V_72 ) {
F_3 ( L_17 ) ;
return V_72 ;
}
F_3 ( L_18 ) ;
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
static int F_29 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
const struct V_37 * V_38 ;
int V_72 ;
T_1 V_4 [ 3 ] ;
V_4 [ 0 ] = 0x00 ;
F_5 ( V_2 , 0x1E , V_4 , 1 ) ;
F_3 ( L_19 , V_76 ) ;
V_72 = F_27 ( & V_38 , V_76 ,
V_2 -> V_10 -> V_74 . V_75 ) ;
F_3 ( L_20 ) ;
if ( V_72 ) {
F_3 ( L_21 ) ;
return V_72 ;
}
V_72 = F_18 ( V_36 , V_38 ) ;
F_28 ( V_38 ) ;
if ( V_72 ) {
F_3 ( L_22 ) ;
return V_72 ;
}
F_3 ( L_23 ) ;
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
static int F_30 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
int V_72 = 0 ;
if ( ! V_2 -> V_77 ) {
switch ( V_2 -> V_28 ) {
case V_29 :
V_72 = F_26 ( V_36 ) ;
break;
case V_30 :
V_72 = F_29 ( V_36 ) ;
break;
default:
return - V_31 ;
break;
}
V_2 -> V_77 = 1 ;
}
return V_72 ;
}
static int F_31 ( struct V_35 * V_36 , struct V_78 * V_79 )
{
V_79 -> V_80 = 500 ;
V_79 -> V_81 = 0 ;
V_79 -> V_82 = 0 ;
return 0 ;
}
static void F_32 ( struct V_35 * V_36 )
{
struct V_1 * V_2 = V_36 -> V_39 ;
F_33 ( V_2 ) ;
}
struct V_35 * F_34 ( const struct V_83 * V_17 ,
struct V_84 * V_10 )
{
struct V_1 * V_2 = NULL ;
T_1 V_4 [] = { 0 , 0 , 0 , 0 , 0 } ;
V_2 = F_35 ( sizeof( struct V_1 ) , V_85 ) ;
if ( V_2 == NULL )
goto error;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_77 = 0 ;
F_6 ( V_2 , 0x00 , V_4 , 5 ) ;
F_9 ( L_24 ,
V_4 [ 0 ] , V_4 [ 1 ] , V_4 [ 2 ] , V_4 [ 3 ] , V_4 [ 4 ] ) ;
switch ( V_4 [ 0 ] ) {
case 0x04 :
V_2 -> V_28 = V_29 ;
F_3 ( L_25 ) ;
break;
case 0x05 :
V_2 -> V_28 = V_30 ;
F_3 ( L_26 ) ;
break;
default:
goto error;
}
switch ( V_2 -> V_28 ) {
case V_29 :
if ( V_4 [ 0 ] != 0x04 ) goto error;
if ( V_4 [ 1 ] != 0x02 ) goto error;
if ( V_4 [ 2 ] != 0x11 ) goto error;
if ( V_4 [ 3 ] != 0x20 ) goto error;
if ( V_4 [ 4 ] != 0x00 ) goto error;
break;
case V_30 :
if ( V_4 [ 0 ] != 0x05 ) goto error;
break;
default:
goto error;
}
memcpy ( & V_2 -> V_86 . V_54 , & V_87 , sizeof( struct V_88 ) ) ;
V_2 -> V_86 . V_39 = V_2 ;
return & V_2 -> V_86 ;
error:
F_33 ( V_2 ) ;
F_3 ( L_27 ,
V_4 [ 0 ] , V_4 [ 1 ] , V_4 [ 2 ] , V_4 [ 3 ] , V_4 [ 4 ] ) ;
return NULL ;
}
