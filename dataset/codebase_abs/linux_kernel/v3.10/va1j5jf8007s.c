static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 ;
T_2 V_6 ;
int V_7 ;
T_2 V_8 [ 1 ] , V_9 [ 1 ] ;
struct V_10 V_11 [ 2 ] ;
T_3 V_12 , V_13 , V_14 , V_15 , V_16 , V_17 , V_18 ;
V_5 = V_2 -> V_19 ;
V_6 = V_5 -> V_20 -> V_21 ;
V_12 = 0 ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
V_8 [ 0 ] = 0xbc + V_7 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_22 = 0 ;
V_11 [ 0 ] . V_23 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_24 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_22 = V_25 ;
V_11 [ 1 ] . V_23 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_24 = V_9 ;
if ( F_2 ( V_5 -> V_26 , V_11 , 2 ) != 2 )
return - V_27 ;
V_12 <<= 8 ;
V_12 |= V_9 [ 0 ] ;
}
V_12 -= 3000 ;
if ( V_12 < 0 )
V_12 = 0 ;
V_13 = F_3 ( V_12 << 16 ) * ( ( 15625ll << 21 ) / 1000000 ) ;
V_14 = ( V_28 ) V_13 * V_13 >> 31 ;
V_15 = ( V_28 ) V_14 * V_13 >> 31 ;
V_16 = ( V_28 ) V_14 * V_14 >> 31 ;
V_17 = ( V_28 ) V_16 * V_13 >> 31 ;
V_18 = ( 58857ll << 23 ) / 1000 ;
V_18 -= ( V_28 ) V_13 * ( ( 89565ll << 24 ) / 1000 ) >> 30 ;
V_18 += ( V_28 ) V_14 * ( ( 88977ll << 24 ) / 1000 ) >> 28 ;
V_18 -= ( V_28 ) V_15 * ( ( 50259ll << 25 ) / 1000 ) >> 27 ;
V_18 += ( V_28 ) V_16 * ( ( 14341ll << 27 ) / 1000 ) >> 27 ;
V_18 -= ( V_28 ) V_17 * ( ( 16346ll << 30 ) / 10000 ) >> 28 ;
* V_3 = V_18 < 0 ? 0 : V_18 >> 15 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return V_29 ;
}
static int
F_5 ( struct V_1 * V_2 , T_4 * V_30 )
{
struct V_4 * V_5 ;
V_5 = V_2 -> V_19 ;
switch ( V_5 -> V_31 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
* V_30 = 0 ;
return 0 ;
case V_37 :
case V_38 :
* V_30 |= V_39 ;
return 0 ;
case V_40 :
case V_41 :
* V_30 |= V_39 | V_42 ;
return 0 ;
case V_43 :
* V_30 |= V_39 | V_42 | V_44 ;
return 0 ;
}
F_6 () ;
}
static T_2 F_7 ( T_5 V_45 )
{
int V_7 ;
const struct V_46 * V_47 ;
for ( V_7 = 0 ; V_7 < F_8 ( V_48 ) ; V_7 ++ ) {
V_47 = & V_48 [ V_7 ] ;
if ( V_45 < V_47 -> V_45 )
return V_47 -> V_49 ;
}
return 0xc0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
T_5 V_45 ;
T_1 V_12 ;
T_2 V_24 [ 6 ] ;
struct V_10 V_50 ;
V_45 = V_5 -> V_2 . V_51 . V_45 ;
V_12 = ( V_45 + 500 ) / 1000 ;
if ( V_45 < 1072000 )
V_12 = ( V_12 << 1 & ~ 0x1f ) | ( V_12 & 0x0f ) ;
V_24 [ 0 ] = 0xfe ;
V_24 [ 1 ] = 0xc0 ;
V_24 [ 2 ] = 0x40 | V_12 >> 8 ;
V_24 [ 3 ] = V_12 ;
V_24 [ 4 ] = 0xe0 ;
V_24 [ 5 ] = F_7 ( V_45 ) ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
T_2 V_24 [ 3 ] ;
struct V_10 V_50 ;
V_24 [ 0 ] = 0xfe ;
V_24 [ 1 ] = 0xc0 ;
V_24 [ 2 ] = 0xe4 ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
T_5 V_45 ;
T_2 V_24 [ 4 ] ;
struct V_10 V_50 ;
V_45 = V_5 -> V_2 . V_51 . V_45 ;
V_24 [ 0 ] = 0xfe ;
V_24 [ 1 ] = 0xc0 ;
V_24 [ 2 ] = 0xf4 ;
V_24 [ 3 ] = F_7 ( V_45 ) | 0x4 ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
return 0 ;
}
static int
F_12 ( struct V_4 * V_5 , int * V_52 )
{
T_2 V_6 ;
T_2 V_8 [ 2 ] , V_9 [ 1 ] ;
struct V_10 V_11 [ 2 ] ;
V_6 = V_5 -> V_20 -> V_21 ;
V_8 [ 0 ] = 0xfe ;
V_8 [ 1 ] = 0xc1 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_22 = 0 ;
V_11 [ 0 ] . V_23 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_24 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_22 = V_25 ;
V_11 [ 1 ] . V_23 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_24 = V_9 ;
if ( F_2 ( V_5 -> V_26 , V_11 , 2 ) != 2 )
return - V_27 ;
* V_52 = V_9 [ 0 ] & 0x40 ;
return 0 ;
}
static int F_13 ( struct V_4 * V_5 )
{
T_2 V_24 [ 2 ] ;
struct V_10 V_50 ;
V_24 [ 0 ] = 0x03 ;
V_24 [ 1 ] = 0x01 ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
return 0 ;
}
static int
F_14 ( struct V_4 * V_5 , int * V_52 )
{
T_2 V_6 ;
T_2 V_8 [ 1 ] , V_9 [ 1 ] ;
struct V_10 V_11 [ 2 ] ;
V_6 = V_5 -> V_20 -> V_21 ;
V_8 [ 0 ] = 0xc3 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_22 = 0 ;
V_11 [ 0 ] . V_23 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_24 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_22 = V_25 ;
V_11 [ 1 ] . V_23 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_24 = V_9 ;
if ( F_2 ( V_5 -> V_26 , V_11 , 2 ) != 2 )
return - V_27 ;
* V_52 = ! ( V_9 [ 0 ] & 0x10 ) ;
return 0 ;
}
static int
F_15 ( struct V_4 * V_5 )
{
T_5 V_53 ;
T_2 V_24 [ 3 ] ;
struct V_10 V_50 ;
V_53 = V_5 -> V_2 . V_51 . V_54 ;
if ( ! V_53 || V_53 == V_55 )
return 0 ;
V_24 [ 0 ] = 0x8f ;
V_24 [ 1 ] = V_53 >> 8 ;
V_24 [ 2 ] = V_53 ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
return 0 ;
}
static int
F_16 ( struct V_4 * V_5 , int * V_52 )
{
T_2 V_6 ;
T_2 V_8 [ 1 ] , V_9 [ 2 ] ;
struct V_10 V_11 [ 2 ] ;
T_5 V_53 ;
V_53 = V_5 -> V_2 . V_51 . V_54 ;
if ( ! V_53 || V_53 == V_55 ) {
* V_52 = 1 ;
return 0 ;
}
V_6 = V_5 -> V_20 -> V_21 ;
V_8 [ 0 ] = 0xe6 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_22 = 0 ;
V_11 [ 0 ] . V_23 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_24 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_22 = V_25 ;
V_11 [ 1 ] . V_23 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_24 = V_9 ;
if ( F_2 ( V_5 -> V_26 , V_11 , 2 ) != 2 )
return - V_27 ;
* V_52 = ( V_9 [ 0 ] << 8 | V_9 [ 1 ] ) == V_53 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 ,
bool V_56 ,
unsigned int V_57 , unsigned int * V_58 ,
T_4 * V_30 )
{
struct V_4 * V_5 ;
int V_59 ;
int V_52 = 0 ;
V_5 = V_2 -> V_19 ;
if ( V_56 )
V_5 -> V_31 = V_33 ;
switch ( V_5 -> V_31 ) {
case V_32 :
* V_58 = 3 * V_60 ;
* V_30 = 0 ;
return 0 ;
case V_33 :
V_59 = F_9 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
V_5 -> V_31 = V_34 ;
* V_58 = 0 ;
* V_30 = 0 ;
return 0 ;
case V_34 :
V_59 = F_10 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
V_5 -> V_31 = V_35 ;
* V_58 = ( V_60 + 99 ) / 100 ;
* V_30 = 0 ;
return 0 ;
case V_35 :
V_59 = F_11 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
V_5 -> V_31 = V_36 ;
* V_58 = 0 ;
* V_30 = 0 ;
return 0 ;
case V_36 :
V_59 = F_12 ( V_5 , & V_52 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( ! V_52 ) {
* V_58 = ( V_60 + 999 ) / 1000 ;
* V_30 = 0 ;
return 0 ;
}
V_5 -> V_31 = V_37 ;
* V_58 = 0 ;
* V_30 = V_39 ;
return 0 ;
case V_37 :
V_59 = F_13 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
V_5 -> V_31 = V_38 ;
* V_58 = 0 ;
* V_30 = V_39 ;
return 0 ;
case V_38 :
V_59 = F_14 ( V_5 , & V_52 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( ! V_52 ) {
* V_58 = ( V_60 + 49 ) / 50 ;
* V_30 = V_39 ;
return 0 ;
}
V_5 -> V_31 = V_40 ;
* V_58 = 0 ;
* V_30 = V_39 | V_42 ;
return 0 ;
case V_40 :
V_59 = F_15 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
V_5 -> V_31 = V_41 ;
return 0 ;
case V_41 :
V_59 = F_16 ( V_5 , & V_52 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( ! V_52 ) {
* V_58 = ( V_60 + 99 ) / 100 ;
* V_30 = V_39 | V_42 ;
return 0 ;
}
V_5 -> V_31 = V_43 ;
case V_43 :
* V_58 = 3 * V_60 ;
* V_30 = V_39 | V_42 | V_44 ;
return 0 ;
}
F_6 () ;
}
static int F_18 ( struct V_4 * V_5 )
{
T_2 V_24 [ 4 ] ;
struct V_10 V_50 ;
V_24 [ 0 ] = 0xfe ;
V_24 [ 1 ] = 0xc0 ;
V_24 [ 2 ] = 0xf0 ;
V_24 [ 3 ] = 0x04 ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
return 0 ;
}
static int F_19 ( struct V_4 * V_5 , int V_61 )
{
T_2 V_24 [ 2 ] ;
struct V_10 V_50 ;
V_24 [ 0 ] = 0x17 ;
V_24 [ 1 ] = V_61 ? 0x01 : 0x00 ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_59 ;
V_5 = V_2 -> V_19 ;
V_59 = F_18 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
return F_19 ( V_5 , 1 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = V_2 -> V_19 ;
V_5 -> V_31 = V_32 ;
return F_19 ( V_5 , 0 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = V_2 -> V_19 ;
F_23 ( V_5 ) ;
}
static int F_24 ( struct V_4 * V_5 )
{
T_2 V_6 ;
T_2 V_8 [ 1 ] , V_9 [ 1 ] ;
struct V_10 V_11 [ 2 ] ;
V_6 = V_5 -> V_20 -> V_21 ;
V_8 [ 0 ] = 0x07 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_22 = 0 ;
V_11 [ 0 ] . V_23 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_24 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_22 = V_25 ;
V_11 [ 1 ] . V_23 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_24 = V_9 ;
if ( F_2 ( V_5 -> V_26 , V_11 , 2 ) != 2 )
return - V_27 ;
if ( V_9 [ 0 ] != 0x41 )
return - V_62 ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
const T_2 ( * V_63 ) [ 2 ] ;
int V_64 ;
T_2 V_6 ;
T_2 V_24 [ 2 ] ;
struct V_10 V_50 ;
int V_7 ;
switch ( V_5 -> V_20 -> V_45 ) {
case V_65 :
V_63 = V_66 ;
V_64 = F_8 ( V_66 ) ;
break;
case V_67 :
V_63 = V_68 ;
V_64 = F_8 ( V_68 ) ;
break;
default:
return - V_69 ;
}
V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_6 = V_6 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = 2 ;
V_50 . V_24 = V_24 ;
for ( V_7 = 0 ; V_7 < V_64 ; V_7 ++ ) {
memcpy ( V_24 , V_63 [ V_7 ] , sizeof( V_24 ) ) ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 )
return - V_27 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_59 ;
V_5 = V_2 -> V_19 ;
V_59 = F_24 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
V_59 = F_25 ( V_5 ) ;
if ( V_59 < 0 )
return V_59 ;
return F_18 ( V_5 ) ;
}
struct V_1 *
F_27 ( const struct V_70 * V_20 ,
struct V_71 * V_26 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
T_2 V_24 [ 2 ] ;
struct V_10 V_50 ;
V_5 = F_28 ( sizeof( struct V_4 ) , V_72 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_20 = V_20 ;
V_5 -> V_26 = V_26 ;
V_2 = & V_5 -> V_2 ;
memcpy ( & V_2 -> V_73 , & V_74 , sizeof( struct V_75 ) ) ;
V_2 -> V_19 = V_5 ;
V_24 [ 0 ] = 0x01 ;
V_24 [ 1 ] = 0x80 ;
V_50 . V_6 = V_5 -> V_20 -> V_21 ;
V_50 . V_22 = 0 ;
V_50 . V_23 = sizeof( V_24 ) ;
V_50 . V_24 = V_24 ;
if ( F_2 ( V_5 -> V_26 , & V_50 , 1 ) != 1 ) {
F_23 ( V_5 ) ;
return NULL ;
}
return V_2 ;
}
