static int F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_1 * V_4 ,
int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
V_8 . V_9 = V_3 ;
V_8 . V_10 = 0 ;
V_8 . V_5 = V_5 ;
V_8 . V_4 = ( T_1 * ) V_4 ;
if ( ( V_6 = F_2 ( V_2 -> V_11 , & V_8 , 1 ) ) != 1 ) {
F_3 ( V_12 L_1
L_2 , V_3 , V_6 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
V_8 . V_9 = V_3 ;
V_8 . V_10 = V_14 ;
V_8 . V_5 = V_5 ;
V_8 . V_4 = V_4 ;
if ( ( V_6 = F_2 ( V_2 -> V_11 , & V_8 , 1 ) ) != 1 ) {
F_3 ( V_12 L_3
L_2 , V_3 , V_6 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_1 * V_2 = V_16 -> V_19 ;
T_1 V_20 [ 585 ] ;
int V_21 ;
F_6 ( L_4 , V_18 -> V_22 ) ;
V_20 [ 0 ] = 17 ;
if ( F_1 ( V_2 , 0x50 , V_20 , 1 ) ) {
F_3 ( V_12 L_5 ) ;
return - 1 ;
}
if ( F_4 ( V_2 , 0x50 , & V_20 [ 145 ] , 192 ) ) {
F_3 ( V_12 L_6 ) ;
return - 1 ;
}
for ( V_21 = 0 ; V_21 < 145 ; V_21 ++ )
V_20 [ V_21 ] = V_18 -> V_23 [ V_21 ] ;
for ( V_21 = 0 ; V_21 < 248 ; V_21 ++ )
V_20 [ V_21 + 337 ] = V_18 -> V_23 [ 145 + V_21 ] ;
V_2 -> V_24 -> V_25 ( V_16 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_20 , 585 ) ) {
F_3 ( V_12 L_7 ) ;
return - 1 ;
}
F_7 ( 1 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 ,
& V_18 -> V_23 [ 393 ] , 8125 ) ) {
F_3 ( V_12 L_8 ) ;
return - 1 ;
}
F_7 ( 1 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_27 , 2 ) ) {
F_3 ( V_12 L_9 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_27 , 2 ) ) {
F_3 ( V_12 L_10 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
F_3 ( L_11 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 , int V_28 )
{
struct V_1 * V_2 = V_16 -> V_19 ;
T_1 V_29 [ 14 ] ;
V_2 -> V_24 -> V_30 ( V_16 , V_28 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_27 , 2 ) ) {
F_3 ( V_12 L_12 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_27 , 2 ) ) {
F_3 ( V_12 L_13 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_31 , 3 ) ) {
F_3 ( V_12 L_14 ) ;
return - 1 ;
}
V_29 [ 0 ] = 0x04 ;
V_29 [ 1 ] = 0x00 ;
V_29 [ 2 ] = 0x03 ;
V_29 [ 3 ] = 0x00 ;
F_7 ( 20 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_29 , 3 ) ) {
F_3 ( V_12 L_15 ) ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_24 -> V_26 , & V_29 [ 10 ] , 2 ) ) {
F_3 ( V_12 L_16 ) ;
return - 1 ;
}
F_6 ( L_17 , V_29 [ 10 ] , V_29 [ 11 ] ) ;
return 0 ;
}
static int F_9 ( struct V_15 * V_16 )
{
struct V_32 * V_33 = & V_16 -> V_34 ;
struct V_1 * V_2 = V_16 -> V_19 ;
if ( V_2 -> V_35 != V_33 -> V_36 ) {
if ( V_16 -> V_37 . V_38 . V_39 ) {
V_16 -> V_37 . V_38 . V_39 ( V_16 ) ;
if ( V_16 -> V_37 . V_40 ) V_16 -> V_37 . V_40 ( V_16 , 0 ) ;
}
F_8 ( V_16 , 0 ) ;
V_2 -> V_35 = V_33 -> V_36 ;
}
return 0 ;
}
static int F_10 ( struct V_15 * V_16 , T_2 * V_41 )
{
struct V_1 * V_2 = V_16 -> V_19 ;
unsigned char V_29 [ 2 ] ;
unsigned char V_42 [] = { 0x04 , 0x00 , 0x03 , 0x00 } ;
* V_41 = 0 ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_42 , 3 ) ) {
F_3 ( V_12 L_18 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_24 -> V_26 , V_29 , 2 ) ) {
F_3 ( V_12 L_19 ) ;
return - 1 ;
}
F_6 ( L_20 , V_29 [ 0 ] , V_29 [ 1 ] ) ;
if ( V_29 [ 0 ] & 0x01 ) {
* V_41 |= V_43 ;
* V_41 |= V_44 ;
* V_41 |= V_45 ;
* V_41 |= V_46 ;
* V_41 |= V_47 ;
}
return 0 ;
}
static T_3 F_11 ( T_3 V_48 , T_3 V_49 )
{
if ( V_48 == 0 )
return 0 ;
V_48 = 2 * F_12 ( V_48 ) ;
if ( V_48 > V_49 ) {
return 0 ;
}
return 10 * ( V_49 - V_48 ) ;
}
static int F_13 ( struct V_15 * V_16 , T_4 * V_50 )
{
struct V_1 * V_2 = V_16 -> V_19 ;
T_1 V_29 [ 2 ] ;
T_1 V_42 [ 3 ] ;
V_42 [ 0 ] = 0x04 ;
V_42 [ 1 ] = 0x00 ;
V_42 [ 2 ] = 0x04 ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 , V_42 , 3 ) ) {
F_3 ( V_12 L_21 ,
V_51 ) ;
return - 1 ;
}
if ( F_4 ( V_2 , V_2 -> V_24 -> V_26 , V_29 , 2 ) ) {
F_3 ( V_12 L_22 ,
V_51 ) ;
return - 1 ;
}
V_2 -> V_50 = F_11 ( V_29 [ 0 ] , 89599047 ) ;
* V_50 = ( V_2 -> V_50 ) >> 16 ;
F_6 ( L_23 , V_51 , V_29 [ 0 ] ,
V_2 -> V_50 >> 24 , ( ( ( V_2 -> V_50 >> 8 ) & 0xffff ) * 100 ) >> 16 ) ;
return 0 ;
}
static int F_14 ( struct V_15 * V_16 , T_4 * V_52 )
{
struct V_1 * V_2 = (struct V_1 * ) V_16 -> V_19 ;
T_4 V_50 ;
int V_53 ;
V_53 = V_16 -> V_37 . V_54 ( V_16 , & V_50 ) ;
if ( V_53 != 0 )
return V_53 ;
if ( V_2 -> V_50 >= 8960 * 0x10000 )
* V_52 = 0xffff ;
else
* V_52 = V_2 -> V_50 / 8960 ;
return 0 ;
}
static int F_15 ( struct V_15 * V_16 , T_3 * V_55 )
{
* V_55 = - V_56 ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 , T_3 * V_57 )
{
* V_57 = - V_56 ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 )
{
return 0 ;
}
static int F_18 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_19 ;
const struct V_58 * V_24 = V_2 -> V_24 ;
const struct V_17 * V_18 ;
unsigned char V_59 [] = { 0x04 , 0x00 , 0x30 , 0x00 , 0x00 } ;
unsigned char V_29 [ 14 ] ;
int V_53 , V_21 ;
if ( ! V_2 -> V_60 ) {
F_3 ( V_61 L_24
L_25 , V_62 ) ;
V_53 = V_24 -> V_63 ( V_16 , & V_18 ,
V_62 ) ;
F_3 ( V_61 L_26 ) ;
if ( V_53 ) {
F_3 ( V_12 L_27
L_28 ) ;
return V_53 ;
}
V_53 = F_5 ( V_16 , V_18 ) ;
F_19 ( V_18 ) ;
if ( V_53 ) {
F_3 ( V_12 L_29
L_30 ) ;
return V_53 ;
}
F_3 ( V_61 L_31 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 ,
V_31 , 3 ) ) {
F_3 ( V_12 L_32 ) ;
return - 1 ;
}
V_29 [ 0 ] = 0x04 ;
V_29 [ 1 ] = 0x00 ;
V_29 [ 2 ] = 0x03 ;
V_29 [ 3 ] = 0x00 ;
F_7 ( 30 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 ,
V_29 , 3 ) ) {
F_3 ( V_12 L_33 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_24 -> V_26 ,
& V_29 [ 10 ] , 2 ) ) {
F_3 ( V_12 L_34 ) ;
return - 1 ;
}
V_29 [ 0 ] = 0x04 ;
V_29 [ 1 ] = 0x00 ;
V_29 [ 2 ] = 0x01 ;
V_29 [ 3 ] = 0x00 ;
F_7 ( 20 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 ,
V_29 , 3 ) ) {
F_3 ( V_12 L_35 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_24 -> V_26 ,
& V_29 [ 12 ] , 2 ) ) {
F_3 ( V_12 L_36 ) ;
return - 1 ;
}
for ( V_21 = 0 ; V_21 < 8 ; V_21 ++ )
V_29 [ V_21 ] = 0xed ;
for ( V_21 = 0 ; V_21 < 5 ; V_21 ++ ) {
F_7 ( 30 ) ;
V_59 [ 4 ] = V_21 + 1 ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 ,
V_59 , 5 ) ) {
F_3 ( V_12 L_37
L_38 , V_21 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_24 -> V_26 ,
& V_29 [ V_21 * 2 ] , 2 ) ) {
F_3 ( V_12 L_39
L_38 , V_21 ) ;
return - 1 ;
}
if ( ( int ) V_29 [ V_21 * 2 + 1 ] != V_21 + 1 ) {
V_21 -- ;
}
}
F_6 ( L_40 ,
V_29 [ 0 ] , V_29 [ 1 ] , V_29 [ 2 ] , V_29 [ 3 ] ,
V_29 [ 4 ] , V_29 [ 5 ] , V_29 [ 6 ] , V_29 [ 7 ] ,
V_29 [ 8 ] , V_29 [ 9 ] ) ;
F_3 ( V_61 L_41
L_42 ,
V_29 [ 2 ] , V_29 [ 4 ] , V_29 [ 6 ] ,
V_29 [ 12 ] , V_29 [ 10 ] ) ;
V_29 [ 0 ] = 0x04 ;
V_29 [ 1 ] = 0x00 ;
V_29 [ 2 ] = 0x03 ;
V_29 [ 3 ] = 0x00 ;
F_7 ( 20 ) ;
if ( F_1 ( V_2 , V_2 -> V_24 -> V_26 ,
V_29 , 3 ) ) {
F_3 ( V_12 L_43 ) ;
return - 1 ;
}
F_7 ( 20 ) ;
if ( F_4 ( V_2 , V_2 -> V_24 -> V_26 ,
& V_29 [ 8 ] , 2 ) ) {
F_3 ( V_12 L_44 ) ;
return - 1 ;
}
V_2 -> V_60 = 1 ;
}
return 0 ;
}
static int F_20 ( struct V_15 * V_16 ,
struct V_64 * V_65 )
{
V_65 -> V_66 = 500 ;
V_65 -> V_67 = 0 ;
V_65 -> V_68 = 0 ;
return 0 ;
}
static void F_21 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = V_16 -> V_19 ;
V_2 -> V_24 -> V_69 ( V_16 ) ;
F_22 ( V_2 ) ;
}
struct V_15 * F_23 ( const struct V_58 * V_24 ,
struct V_70 * V_11 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_24 ( sizeof( struct V_1 ) , V_71 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_24 = V_24 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_60 = 0 ;
V_2 -> V_35 = 0 ;
memcpy ( & V_2 -> V_72 . V_37 , & V_73 , sizeof( struct V_74 ) ) ;
V_2 -> V_72 . V_19 = V_2 ;
return & V_2 -> V_72 ;
}
