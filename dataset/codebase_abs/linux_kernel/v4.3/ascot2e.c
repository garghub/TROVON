static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , const T_1 * V_5 , T_2 V_6 )
{
F_2 ( & V_2 -> V_7 -> V_8 , L_1 ,
( V_4 == 0 ? L_2 : L_3 ) , V_3 , V_6 ) ;
F_3 ( L_4 ,
V_9 , V_5 , V_6 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
T_1 V_3 , const T_1 * V_5 , T_2 V_6 )
{
int V_10 ;
T_1 V_11 [ V_12 + 1 ] ;
struct V_13 V_14 [ 1 ] = {
{
. V_15 = V_2 -> V_16 ,
. V_17 = 0 ,
. V_6 = V_6 + 1 ,
. V_11 = V_11 ,
}
} ;
if ( V_6 + 1 >= sizeof( V_11 ) ) {
F_5 ( & V_2 -> V_7 -> V_8 , L_5 ,
V_3 , V_6 + 1 ) ;
return - V_18 ;
}
F_1 ( V_2 , V_3 , 1 , V_5 , V_6 ) ;
V_11 [ 0 ] = V_3 ;
memcpy ( & V_11 [ 1 ] , V_5 , V_6 ) ;
V_10 = F_6 ( V_2 -> V_7 , V_14 , 1 ) ;
if ( V_10 >= 0 && V_10 != 1 )
V_10 = - V_19 ;
if ( V_10 < 0 ) {
F_5 ( & V_2 -> V_7 -> V_8 ,
L_6 ,
V_20 , V_10 , V_3 , V_6 ) ;
return V_10 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_21 )
{
return F_4 ( V_2 , V_3 , & V_21 , 1 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 * V_21 , T_2 V_6 )
{
int V_10 ;
struct V_13 V_14 [ 2 ] = {
{
. V_15 = V_2 -> V_16 ,
. V_17 = 0 ,
. V_6 = 1 ,
. V_11 = & V_3 ,
} , {
. V_15 = V_2 -> V_16 ,
. V_17 = V_22 ,
. V_6 = V_6 ,
. V_11 = V_21 ,
}
} ;
V_10 = F_6 ( V_2 -> V_7 , & V_14 [ 0 ] , 1 ) ;
if ( V_10 >= 0 && V_10 != 1 )
V_10 = - V_19 ;
if ( V_10 < 0 ) {
F_5 ( & V_2 -> V_7 -> V_8 ,
L_7 ,
V_20 , V_10 , V_2 -> V_16 , V_3 ) ;
return V_10 ;
}
V_10 = F_6 ( V_2 -> V_7 , & V_14 [ 1 ] , 1 ) ;
if ( V_10 >= 0 && V_10 != 1 )
V_10 = - V_19 ;
if ( V_10 < 0 ) {
F_5 ( & V_2 -> V_7 -> V_8 ,
L_8 ,
V_20 , V_10 , V_2 -> V_16 , V_3 ) ;
return V_10 ;
}
F_1 ( V_2 , V_3 , 0 , V_21 , V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_21 )
{
return F_8 ( V_2 , V_3 , V_21 , 1 ) ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_5 , T_1 V_23 )
{
int V_24 ;
T_1 V_25 ;
if ( V_23 != 0xff ) {
V_24 = F_9 ( V_2 , V_3 , & V_25 ) ;
if ( V_24 != 0 )
return V_24 ;
V_5 = ( ( V_5 & V_23 ) | ( V_25 & ( V_23 ^ 0xFF ) ) ) ;
}
return F_7 ( V_2 , V_3 , V_5 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] ;
F_2 ( & V_2 -> V_7 -> V_8 , L_9 , V_26 ) ;
if ( V_2 -> V_27 == V_28 )
return 0 ;
V_5 [ 0 ] = 0x00 ;
V_5 [ 1 ] = 0x04 ;
F_4 ( V_2 , 0x14 , V_5 , 2 ) ;
F_7 ( V_2 , 0x50 , 0x01 ) ;
V_2 -> V_27 = V_28 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] = { 0xFB , 0x0F } ;
F_2 ( & V_2 -> V_7 -> V_8 , L_9 , V_26 ) ;
if ( V_2 -> V_27 == V_29 )
return 0 ;
F_4 ( V_2 , 0x14 , V_5 , 2 ) ;
F_7 ( V_2 , 0x50 , 0x00 ) ;
V_2 -> V_27 = V_29 ;
return 0 ;
}
static int F_13 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_2 ( & V_2 -> V_7 -> V_8 , L_9 , V_26 ) ;
return F_12 ( V_2 ) ;
}
static int F_14 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_2 ( & V_2 -> V_7 -> V_8 , L_9 , V_26 ) ;
F_15 ( V_31 -> V_32 ) ;
V_31 -> V_32 = NULL ;
return 0 ;
}
static int F_16 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
F_2 ( & V_2 -> V_7 -> V_8 , L_9 , V_26 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static enum V_33 F_17 ( struct V_30 * V_31 )
{
enum V_33 system = V_34 ;
struct V_35 * V_36 = & V_31 -> V_37 ;
struct V_1 * V_2 = V_31 -> V_32 ;
if ( V_36 -> V_38 == V_39 ) {
if ( V_36 -> V_40 <= 5000000 )
system = V_41 ;
else if ( V_36 -> V_40 <= 6000000 )
system = V_42 ;
else if ( V_36 -> V_40 <= 7000000 )
system = V_43 ;
else if ( V_36 -> V_40 <= 8000000 )
system = V_44 ;
else {
system = V_44 ;
V_36 -> V_40 = 8000000 ;
}
} else if ( V_36 -> V_38 == V_45 ) {
if ( V_36 -> V_40 <= 5000000 )
system = V_46 ;
else if ( V_36 -> V_40 <= 6000000 )
system = V_47 ;
else if ( V_36 -> V_40 <= 7000000 )
system = V_48 ;
else if ( V_36 -> V_40 <= 8000000 )
system = V_49 ;
else {
system = V_49 ;
V_36 -> V_40 = 8000000 ;
}
} else if ( V_36 -> V_38 == V_50 ) {
if ( V_36 -> V_40 <= 6000000 )
system = V_51 ;
else if ( V_36 -> V_40 <= 8000000 )
system = V_52 ;
}
F_2 ( & V_2 -> V_7 -> V_8 ,
L_10 ,
V_26 , ( int ) system , V_36 -> V_38 , V_36 -> V_40 ) ;
return system ;
}
static int F_18 ( struct V_30 * V_31 )
{
T_1 V_5 [ 10 ] ;
T_2 V_53 ;
enum V_33 V_54 ;
struct V_35 * V_36 = & V_31 -> V_37 ;
struct V_1 * V_2 = V_31 -> V_32 ;
F_2 ( & V_2 -> V_7 -> V_8 , L_11 ,
V_26 , V_36 -> V_53 / 1000 ) ;
V_54 = F_17 ( V_31 ) ;
if ( V_54 == V_34 ) {
F_2 ( & V_2 -> V_7 -> V_8 , L_12 ,
V_26 ) ;
return - V_55 ;
}
if ( V_2 -> V_56 )
V_2 -> V_56 ( V_2 -> V_57 , 1 ) ;
V_53 = F_19 ( V_36 -> V_53 / 1000 , 25 ) ;
if ( V_2 -> V_27 == V_28 )
F_12 ( V_2 ) ;
V_5 [ 0 ] = 0x00 ;
if ( V_58 [ V_54 ] . V_59 != V_60 ) {
V_5 [ 0 ] |= ( T_1 ) (
( V_58 [ V_54 ] . V_59 & 0x03 ) << 3 ) ;
}
if ( V_58 [ V_54 ] . V_61 != V_60 ) {
V_5 [ 0 ] |= ( T_1 ) (
( V_58 [ V_54 ] . V_61 & 0x01 ) << 2 ) ;
}
F_10 ( V_2 , 0x05 , V_5 [ 0 ] , 0x1c ) ;
if ( V_54 == V_51 ||
V_54 == V_52 ) {
V_5 [ 0 ] = ( V_53 > 500000 ) ? 16 : 32 ;
} else {
V_5 [ 0 ] = ( V_53 > 500000 ) ? 2 : 4 ;
}
V_5 [ 1 ] = 0x04 ;
if ( V_54 == V_51 ||
V_54 == V_52 ) {
V_5 [ 2 ] = 18 ;
V_5 [ 3 ] = 120 ;
V_5 [ 4 ] = 20 ;
} else {
V_5 [ 2 ] = 48 ;
V_5 [ 3 ] = 10 ;
V_5 [ 4 ] = 30 ;
}
if ( V_54 == V_51 ||
V_54 == V_52 )
V_5 [ 5 ] = ( V_53 > 500000 ) ? 0x08 : 0x0c ;
else
V_5 [ 5 ] = ( V_53 > 500000 ) ? 0x30 : 0x38 ;
V_5 [ 6 ] = V_58 [ V_54 ] . V_62 ;
if ( V_58 [ V_54 ] . V_63 == V_60 ) {
F_7 ( V_2 , 0x4E , 0x01 ) ;
V_5 [ 7 ] = 0x00 ;
} else {
F_7 ( V_2 , 0x4E , 0x00 ) ;
V_5 [ 7 ] = V_58 [ V_54 ] . V_63 ;
}
V_5 [ 8 ] = ( T_1 ) ( ( V_58 [ V_54 ] . V_64 << 3 ) |
( V_58 [ V_54 ] . V_65 & 0x07 ) ) ;
V_5 [ 9 ] = V_58 [ V_54 ] . V_66 ;
F_4 ( V_2 , 0x06 , V_5 , 10 ) ;
if ( V_54 == V_51 ||
V_54 == V_52 ) {
V_5 [ 0 ] = 0x0F ;
V_5 [ 1 ] = 0x00 ;
V_5 [ 2 ] = 0x01 ;
} else {
V_5 [ 0 ] = 0x0F ;
V_5 [ 1 ] = 0x00 ;
V_5 [ 2 ] = 0x03 ;
}
F_4 ( V_2 , 0x45 , V_5 , 3 ) ;
V_5 [ 0 ] = V_58 [ V_54 ] . V_67 ;
V_5 [ 1 ] = V_58 [ V_54 ] . V_68 ;
F_4 ( V_2 , 0x49 , V_5 , 2 ) ;
F_10 ( V_2 , 0x0c , 0x90 , 0xb0 ) ;
V_5 [ 0 ] = 0xc4 ;
V_5 [ 1 ] = 0x40 ;
F_4 ( V_2 , 0x03 , V_5 , 2 ) ;
V_5 [ 0 ] = ( T_1 ) ( V_53 & 0xFF ) ;
V_5 [ 1 ] = ( T_1 ) ( ( V_53 >> 8 ) & 0xFF ) ;
V_5 [ 2 ] = ( T_1 ) ( ( V_53 >> 16 ) & 0x0F ) ;
V_5 [ 2 ] |= ( T_1 ) ( V_58 [ V_54 ] . V_69 << 4 ) ;
V_5 [ 3 ] = 0xFF ;
V_5 [ 4 ] = 0xFF ;
F_4 ( V_2 , 0x10 , V_5 , 5 ) ;
F_20 ( 50 ) ;
F_7 ( V_2 , 0x04 , 0x00 ) ;
F_7 ( V_2 , 0x03 , 0xC0 ) ;
F_10 ( V_2 , 0x0C , 0x00 , 0x30 ) ;
V_2 -> V_53 = V_53 ;
return 0 ;
}
static int F_21 ( struct V_30 * V_31 , T_2 * V_53 )
{
struct V_1 * V_2 = V_31 -> V_32 ;
* V_53 = V_2 -> V_53 * 1000 ;
return 0 ;
}
struct V_30 * F_22 ( struct V_30 * V_31 ,
const struct V_70 * V_71 ,
struct V_72 * V_7 )
{
T_1 V_5 [ 4 ] ;
struct V_1 * V_2 = NULL ;
V_2 = F_23 ( sizeof( struct V_1 ) , V_73 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_16 = ( V_71 -> V_16 >> 1 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_57 = V_71 -> V_74 ;
V_2 -> V_56 = V_71 -> V_75 ;
if ( V_31 -> V_76 . V_77 )
V_31 -> V_76 . V_77 ( V_31 , 1 ) ;
V_5 [ 0 ] = 16 ;
V_5 [ 1 ] = 0x06 ;
V_5 [ 2 ] = 0xC4 ;
V_5 [ 3 ] = 0x40 ;
F_4 ( V_2 , 0x01 , V_5 , 4 ) ;
V_5 [ 0 ] = 0x10 ;
V_5 [ 1 ] = 0x3F ;
V_5 [ 2 ] = 0x25 ;
F_4 ( V_2 , 0x22 , V_5 , 3 ) ;
F_7 ( V_2 , 0x28 , 0x1e ) ;
F_7 ( V_2 , 0x59 , 0x04 ) ;
F_20 ( 80 ) ;
F_7 ( V_2 , 0x4c , 0x01 ) ;
F_7 ( V_2 , 0x07 , 0x04 ) ;
F_7 ( V_2 , 0x04 , 0x00 ) ;
F_7 ( V_2 , 0x03 , 0xc0 ) ;
V_5 [ 0 ] = 0x00 ;
V_5 [ 1 ] = 0x04 ;
F_4 ( V_2 , 0x14 , V_5 , 2 ) ;
F_7 ( V_2 , 0x50 , 0x01 ) ;
V_2 -> V_27 = V_28 ;
if ( V_31 -> V_76 . V_77 )
V_31 -> V_76 . V_77 ( V_31 , 0 ) ;
memcpy ( & V_31 -> V_76 . V_78 , & V_79 ,
sizeof( struct V_80 ) ) ;
V_31 -> V_32 = V_2 ;
F_24 ( & V_2 -> V_7 -> V_8 ,
L_13 ,
V_2 -> V_16 , V_2 -> V_7 ) ;
return V_31 ;
}
