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
F_3 ( L_1 , V_3 , V_6 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , int V_5 )
{
int V_6 ;
struct V_7 V_8 ;
V_8 . V_9 = V_3 ;
V_8 . V_10 = V_13 ;
V_8 . V_5 = V_5 ;
V_8 . V_4 = V_4 ;
if ( ( V_6 = F_2 ( V_2 -> V_11 , & V_8 , 1 ) ) != 1 ) {
F_3 ( L_1 , V_3 , V_6 ) ;
return - V_12 ;
}
return 0 ;
}
static int F_5 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
T_1 V_19 [ 585 ] ;
int V_20 ;
F_6 ( L_2 , V_17 -> V_21 ) ;
V_19 [ 0 ] = 17 ;
if ( F_1 ( V_2 , 0x50 , V_19 , 1 ) ) {
F_3 ( L_3 ) ;
return - 1 ;
}
if ( F_4 ( V_2 , 0x50 , & V_19 [ 145 ] , 192 ) ) {
F_3 ( L_4 ) ;
return - 1 ;
}
for ( V_20 = 0 ; V_20 < 145 ; V_20 ++ )
V_19 [ V_20 ] = V_17 -> V_22 [ V_20 ] ;
for ( V_20 = 0 ; V_20 < 248 ; V_20 ++ )
V_19 [ V_20 + 337 ] = V_17 -> V_22 [ 145 + V_20 ] ;
V_2 -> V_23 -> V_24 ( V_15 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_19 , 585 ) ) {
F_3 ( L_5 ) ;
return - 1 ;
}
F_7 ( 1 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 ,
& V_17 -> V_22 [ 393 ] , 8125 ) ) {
F_3 ( L_6 ) ;
return - 1 ;
}
F_7 ( 1 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_26 , 2 ) ) {
F_3 ( L_7 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_26 , 2 ) ) {
F_3 ( L_8 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
F_8 ( L_9 ) ;
return 0 ;
}
static int F_9 ( struct V_14 * V_15 , int V_27 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
T_1 V_28 [ 14 ] ;
V_2 -> V_23 -> V_29 ( V_15 , V_27 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_26 , 2 ) ) {
F_3 ( L_5 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_26 , 2 ) ) {
F_3 ( L_6 ) ;
return - 1 ;
}
F_7 ( 10 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_30 , 3 ) ) {
F_3 ( L_7 ) ;
return - 1 ;
}
V_28 [ 0 ] = 0x04 ;
V_28 [ 1 ] = 0x00 ;
V_28 [ 2 ] = 0x03 ;
V_28 [ 3 ] = 0x00 ;
F_7 ( 20 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_28 , 3 ) ) {
F_3 ( L_10 ) ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_23 -> V_25 , & V_28 [ 10 ] , 2 ) ) {
F_3 ( L_11 ) ;
return - 1 ;
}
F_6 ( L_12 , V_28 [ 10 ] , V_28 [ 11 ] ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 )
{
struct V_31 * V_32 = & V_15 -> V_33 ;
struct V_1 * V_2 = V_15 -> V_18 ;
if ( V_2 -> V_34 != V_32 -> V_35 ) {
if ( V_15 -> V_36 . V_37 . V_38 ) {
V_15 -> V_36 . V_37 . V_38 ( V_15 ) ;
if ( V_15 -> V_36 . V_39 ) V_15 -> V_36 . V_39 ( V_15 , 0 ) ;
}
F_9 ( V_15 , 0 ) ;
V_2 -> V_34 = V_32 -> V_35 ;
}
return 0 ;
}
static int F_11 ( struct V_14 * V_15 , enum V_40 * V_41 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
unsigned char V_28 [ 2 ] ;
unsigned char V_42 [] = { 0x04 , 0x00 , 0x03 , 0x00 } ;
* V_41 = 0 ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_42 , 3 ) ) {
F_3 ( L_13 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_23 -> V_25 , V_28 , 2 ) ) {
F_3 ( L_14 ) ;
return - 1 ;
}
F_6 ( L_15 , V_28 [ 0 ] , V_28 [ 1 ] ) ;
if ( V_28 [ 0 ] & 0x01 ) {
* V_41 |= V_43 ;
* V_41 |= V_44 ;
* V_41 |= V_45 ;
* V_41 |= V_46 ;
* V_41 |= V_47 ;
}
return 0 ;
}
static T_2 F_12 ( T_2 V_48 , T_2 V_49 )
{
if ( V_48 == 0 )
return 0 ;
V_48 = 2 * F_13 ( V_48 ) ;
if ( V_48 > V_49 ) {
return 0 ;
}
return 10 * ( V_49 - V_48 ) ;
}
static int F_14 ( struct V_14 * V_15 , T_3 * V_50 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
T_1 V_28 [ 2 ] ;
T_1 V_42 [ 3 ] ;
V_42 [ 0 ] = 0x04 ;
V_42 [ 1 ] = 0x00 ;
V_42 [ 2 ] = 0x04 ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 , V_42 , 3 ) ) {
F_3 ( L_16 ) ;
return - 1 ;
}
if ( F_4 ( V_2 , V_2 -> V_23 -> V_25 , V_28 , 2 ) ) {
F_3 ( L_17 ) ;
return - 1 ;
}
V_2 -> V_50 = F_12 ( V_28 [ 0 ] , 89599047 ) ;
* V_50 = ( V_2 -> V_50 ) >> 16 ;
F_6 ( L_18 , V_28 [ 0 ] ,
V_2 -> V_50 >> 24 , ( ( ( V_2 -> V_50 >> 8 ) & 0xffff ) * 100 ) >> 16 ) ;
return 0 ;
}
static int F_15 ( struct V_14 * V_15 , T_3 * V_51 )
{
struct V_1 * V_2 = (struct V_1 * ) V_15 -> V_18 ;
T_3 V_50 ;
int V_52 ;
V_52 = V_15 -> V_36 . V_53 ( V_15 , & V_50 ) ;
if ( V_52 != 0 )
return V_52 ;
if ( V_2 -> V_50 >= 8960 * 0x10000 )
* V_51 = 0xffff ;
else
* V_51 = V_2 -> V_50 / 8960 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_15 , T_2 * V_54 )
{
* V_54 = - V_55 ;
return 0 ;
}
static int F_17 ( struct V_14 * V_15 , T_2 * V_56 )
{
* V_56 = - V_55 ;
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
return 0 ;
}
static int F_19 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
const struct V_57 * V_23 = V_2 -> V_23 ;
const struct V_16 * V_17 ;
unsigned char V_58 [] = { 0x04 , 0x00 , 0x30 , 0x00 , 0x00 } ;
unsigned char V_28 [ 14 ] ;
int V_52 , V_20 ;
if ( ! V_2 -> V_59 ) {
F_8 ( L_19 ,
V_60 ) ;
V_52 = V_23 -> V_61 ( V_15 , & V_17 ,
V_60 ) ;
F_8 ( L_20 ) ;
if ( V_52 ) {
F_3 ( L_21 ) ;
return V_52 ;
}
V_52 = F_5 ( V_15 , V_17 ) ;
F_20 ( V_17 ) ;
if ( V_52 ) {
F_3 ( L_22 ) ;
return V_52 ;
}
F_8 ( L_23 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 ,
V_30 , 3 ) ) {
F_3 ( L_24 ) ;
return - 1 ;
}
V_28 [ 0 ] = 0x04 ;
V_28 [ 1 ] = 0x00 ;
V_28 [ 2 ] = 0x03 ;
V_28 [ 3 ] = 0x00 ;
F_7 ( 30 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 ,
V_28 , 3 ) ) {
F_3 ( L_25 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_23 -> V_25 ,
& V_28 [ 10 ] , 2 ) ) {
F_3 ( L_26 ) ;
return - 1 ;
}
V_28 [ 0 ] = 0x04 ;
V_28 [ 1 ] = 0x00 ;
V_28 [ 2 ] = 0x01 ;
V_28 [ 3 ] = 0x00 ;
F_7 ( 20 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 ,
V_28 , 3 ) ) {
F_3 ( L_27 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_23 -> V_25 ,
& V_28 [ 12 ] , 2 ) ) {
F_3 ( L_28 ) ;
return - 1 ;
}
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ )
V_28 [ V_20 ] = 0xed ;
for ( V_20 = 0 ; V_20 < 5 ; V_20 ++ ) {
F_7 ( 30 ) ;
V_58 [ 4 ] = V_20 + 1 ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 ,
V_58 , 5 ) ) {
F_3 ( L_29 , V_20 ) ;
return - 1 ;
}
F_7 ( 3 ) ;
if ( F_4 ( V_2 , V_2 -> V_23 -> V_25 ,
& V_28 [ V_20 * 2 ] , 2 ) ) {
F_3 ( L_30 , V_20 ) ;
return - 1 ;
}
if ( ( int ) V_28 [ V_20 * 2 + 1 ] != V_20 + 1 ) {
V_20 -- ;
}
}
F_6 ( L_31 , V_28 ) ;
F_8 ( L_32 ,
V_28 [ 2 ] , V_28 [ 4 ] , V_28 [ 6 ] , V_28 [ 12 ] ,
V_28 [ 10 ] ) ;
V_28 [ 0 ] = 0x04 ;
V_28 [ 1 ] = 0x00 ;
V_28 [ 2 ] = 0x03 ;
V_28 [ 3 ] = 0x00 ;
F_7 ( 20 ) ;
if ( F_1 ( V_2 , V_2 -> V_23 -> V_25 ,
V_28 , 3 ) ) {
F_3 ( L_33 ) ;
return - 1 ;
}
F_7 ( 20 ) ;
if ( F_4 ( V_2 , V_2 -> V_23 -> V_25 ,
& V_28 [ 8 ] , 2 ) ) {
F_3 ( L_34 ) ;
return - 1 ;
}
V_2 -> V_59 = 1 ;
}
return 0 ;
}
static int F_21 ( struct V_14 * V_15 ,
struct V_62 * V_63 )
{
V_63 -> V_64 = 500 ;
V_63 -> V_65 = 0 ;
V_63 -> V_66 = 0 ;
return 0 ;
}
static void F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = V_15 -> V_18 ;
V_2 -> V_23 -> V_67 ( V_15 ) ;
F_23 ( V_2 ) ;
}
struct V_14 * F_24 ( const struct V_57 * V_23 ,
struct V_68 * V_11 )
{
struct V_1 * V_2 = NULL ;
V_2 = F_25 ( sizeof( struct V_1 ) , V_69 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_23 = V_23 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_59 = 0 ;
V_2 -> V_34 = 0 ;
memcpy ( & V_2 -> V_70 . V_36 , & V_71 , sizeof( struct V_72 ) ) ;
V_2 -> V_70 . V_18 = V_2 ;
return & V_2 -> V_70 ;
}
