static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 ;
T_2 V_6 ;
int V_7 ;
T_2 V_8 [ 1 ] , V_9 [ 1 ] ;
struct V_10 V_11 [ 2 ] ;
T_3 V_12 , V_13 , V_14 ;
V_5 = V_2 -> V_15 ;
V_6 = V_5 -> V_16 -> V_17 ;
V_12 = 0 ;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
V_8 [ 0 ] = 0x8b + V_7 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_18 = 0 ;
V_11 [ 0 ] . V_19 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_20 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_18 = V_21 ;
V_11 [ 1 ] . V_19 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_20 = V_9 ;
if ( F_2 ( V_5 -> V_22 , V_11 , 2 ) != 2 )
return - V_23 ;
V_12 <<= 8 ;
V_12 |= V_9 [ 0 ] ;
}
if ( ! V_12 )
return - V_24 ;
V_13 = 10 * ( F_3 ( 0x540000 * 100 / V_12 ) - ( 2 << 24 ) ) ;
V_14 = ( 24ll << 46 ) / 1000000 ;
V_14 = ( ( V_25 ) V_14 * V_13 >> 30 ) - ( 16ll << 40 ) / 10000 ;
V_14 = ( ( V_25 ) V_14 * V_13 >> 29 ) + ( 398ll << 35 ) / 10000 ;
V_14 = ( ( V_25 ) V_14 * V_13 >> 30 ) + ( 5491ll << 29 ) / 10000 ;
V_14 = ( ( V_25 ) V_14 * V_13 >> 30 ) + ( 30965ll << 23 ) / 10000 ;
* V_3 = V_14 >> 15 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
return V_26 ;
}
static int
F_5 ( struct V_1 * V_2 , T_4 * V_27 )
{
struct V_4 * V_5 ;
V_5 = V_2 -> V_15 ;
switch ( V_5 -> V_28 ) {
case V_29 :
case V_30 :
case V_31 :
* V_27 = 0 ;
return 0 ;
case V_32 :
case V_33 :
case V_34 :
* V_27 |= V_35 ;
return 0 ;
case V_36 :
* V_27 |= V_35 | V_37 | V_38 ;
return 0 ;
}
F_6 () ;
}
static T_2 F_7 ( T_5 V_39 )
{
int V_7 ;
const struct V_40 * V_41 ;
for ( V_7 = 0 ; V_7 < F_8 ( V_42 ) ; V_7 ++ ) {
V_41 = & V_42 [ V_7 ] ;
if ( V_39 < V_41 -> V_39 )
return V_41 -> V_43 ;
}
return 0xe4 ;
}
static int F_9 ( struct V_4 * V_5 )
{
T_5 V_39 ;
T_1 V_12 ;
T_2 V_20 [ 6 ] ;
struct V_10 V_44 ;
V_39 = V_5 -> V_2 . V_45 . V_39 ;
V_12 = ( V_39 + 71428 ) / 142857 + 399 ;
V_20 [ 0 ] = 0xfe ;
V_20 [ 1 ] = 0xc2 ;
V_20 [ 2 ] = V_12 >> 8 ;
V_20 [ 3 ] = V_12 ;
V_20 [ 4 ] = 0x80 ;
V_20 [ 5 ] = F_7 ( V_39 ) ;
V_44 . V_6 = V_5 -> V_16 -> V_17 ;
V_44 . V_18 = 0 ;
V_44 . V_19 = sizeof( V_20 ) ;
V_44 . V_20 = V_20 ;
if ( F_2 ( V_5 -> V_22 , & V_44 , 1 ) != 1 )
return - V_23 ;
return 0 ;
}
static int
F_10 ( struct V_4 * V_5 , int * V_46 )
{
T_2 V_6 ;
T_2 V_8 [ 2 ] , V_9 [ 1 ] ;
struct V_10 V_11 [ 2 ] ;
V_6 = V_5 -> V_16 -> V_17 ;
V_8 [ 0 ] = 0xfe ;
V_8 [ 1 ] = 0xc3 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_18 = 0 ;
V_11 [ 0 ] . V_19 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_20 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_18 = V_21 ;
V_11 [ 1 ] . V_19 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_20 = V_9 ;
if ( F_2 ( V_5 -> V_22 , V_11 , 2 ) != 2 )
return - V_23 ;
* V_46 = V_9 [ 0 ] & 0x40 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
T_2 V_20 [ 2 ] ;
struct V_10 V_44 ;
V_20 [ 0 ] = 0x01 ;
V_20 [ 1 ] = 0x40 ;
V_44 . V_6 = V_5 -> V_16 -> V_17 ;
V_44 . V_18 = 0 ;
V_44 . V_19 = sizeof( V_20 ) ;
V_44 . V_20 = V_20 ;
if ( F_2 ( V_5 -> V_22 , & V_44 , 1 ) != 1 )
return - V_23 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_5 ,
int * V_46 , int * V_47 )
{
T_2 V_6 ;
T_2 V_8 [ 1 ] , V_9 [ 1 ] ;
struct V_10 V_11 [ 2 ] ;
V_6 = V_5 -> V_16 -> V_17 ;
V_8 [ 0 ] = 0x80 ;
V_11 [ 0 ] . V_6 = V_6 ;
V_11 [ 0 ] . V_18 = 0 ;
V_11 [ 0 ] . V_19 = sizeof( V_8 ) ;
V_11 [ 0 ] . V_20 = V_8 ;
V_11 [ 1 ] . V_6 = V_6 ;
V_11 [ 1 ] . V_18 = V_21 ;
V_11 [ 1 ] . V_19 = sizeof( V_9 ) ;
V_11 [ 1 ] . V_20 = V_9 ;
if ( F_2 ( V_5 -> V_22 , V_11 , 2 ) != 2 )
return - V_23 ;
* V_46 = ! ( V_9 [ 0 ] & 0x10 ) ;
* V_47 = V_9 [ 0 ] & 0x80 ;
return 0 ;
}
static int
F_13 ( struct V_1 * V_2 ,
bool V_48 ,
unsigned int V_49 , unsigned int * V_50 ,
T_4 * V_27 )
{
struct V_4 * V_5 ;
int V_51 ;
int V_46 = 0 , V_47 = 0 ;
V_5 = V_2 -> V_15 ;
if ( V_48 )
V_5 -> V_28 = V_30 ;
switch ( V_5 -> V_28 ) {
case V_29 :
* V_50 = 3 * V_52 ;
* V_27 = 0 ;
return 0 ;
case V_30 :
V_51 = F_9 ( V_5 ) ;
if ( V_51 < 0 )
return V_51 ;
V_5 -> V_28 = V_31 ;
* V_50 = 0 ;
* V_27 = 0 ;
return 0 ;
case V_31 :
V_51 = F_10 ( V_5 , & V_46 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( ! V_46 ) {
* V_50 = ( V_52 + 999 ) / 1000 ;
* V_27 = 0 ;
return 0 ;
}
V_5 -> V_28 = V_32 ;
* V_50 = 0 ;
* V_27 = V_35 ;
return 0 ;
case V_32 :
V_51 = F_11 ( V_5 ) ;
if ( V_51 < 0 )
return V_51 ;
V_5 -> V_28 = V_33 ;
* V_50 = 0 ;
* V_27 = V_35 ;
return 0 ;
case V_33 :
V_51 = F_12 ( V_5 , & V_46 , & V_47 ) ;
if ( V_51 < 0 )
return V_51 ;
if ( ! V_46 ) {
if ( ! V_47 ) {
V_5 -> V_28 = V_34 ;
* V_50 = 3 * V_52 ;
* V_27 = V_35 ;
return 0 ;
}
* V_50 = ( V_52 + 999 ) / 1000 ;
* V_27 = V_35 ;
return 0 ;
}
V_5 -> V_28 = V_36 ;
case V_36 :
* V_50 = 3 * V_52 ;
* V_27 = V_35 | V_37 | V_38 ;
return 0 ;
case V_34 :
* V_50 = 3 * V_52 ;
* V_27 = V_35 ;
return 0 ;
}
F_6 () ;
}
static int F_14 ( struct V_4 * V_5 )
{
T_2 V_20 [ 7 ] ;
struct V_10 V_44 ;
V_20 [ 0 ] = 0xfe ;
V_20 [ 1 ] = 0xc2 ;
V_20 [ 2 ] = 0x01 ;
V_20 [ 3 ] = 0x8f ;
V_20 [ 4 ] = 0xc1 ;
V_20 [ 5 ] = 0x80 ;
V_20 [ 6 ] = 0x80 ;
V_44 . V_6 = V_5 -> V_16 -> V_17 ;
V_44 . V_18 = 0 ;
V_44 . V_19 = sizeof( V_20 ) ;
V_44 . V_20 = V_20 ;
if ( F_2 ( V_5 -> V_22 , & V_44 , 1 ) != 1 )
return - V_23 ;
return 0 ;
}
static int F_15 ( struct V_4 * V_5 , int V_53 )
{
T_2 V_20 [ 2 ] ;
struct V_10 V_44 ;
V_20 [ 0 ] = 0x03 ;
V_20 [ 1 ] = V_53 ? 0x90 : 0x80 ;
V_44 . V_6 = V_5 -> V_16 -> V_17 ;
V_44 . V_18 = 0 ;
V_44 . V_19 = sizeof( V_20 ) ;
V_44 . V_20 = V_20 ;
if ( F_2 ( V_5 -> V_22 , & V_44 , 1 ) != 1 )
return - V_23 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_51 ;
V_5 = V_2 -> V_15 ;
V_51 = F_14 ( V_5 ) ;
if ( V_51 < 0 )
return V_51 ;
return F_15 ( V_5 , 1 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = V_2 -> V_15 ;
V_5 -> V_28 = V_29 ;
return F_15 ( V_5 , 0 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = V_2 -> V_15 ;
F_19 ( V_5 ) ;
}
int F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
const T_2 ( * V_54 ) [ 2 ] ;
int V_55 ;
T_2 V_20 [ 2 ] ;
struct V_10 V_44 ;
int V_7 ;
V_5 = V_2 -> V_15 ;
switch ( V_5 -> V_16 -> V_39 ) {
case V_56 :
V_54 = V_57 ;
V_55 = F_8 ( V_57 ) ;
break;
case V_58 :
V_54 = V_59 ;
V_55 = F_8 ( V_59 ) ;
break;
default:
return - V_60 ;
}
V_44 . V_6 = V_5 -> V_16 -> V_17 ;
V_44 . V_18 = 0 ;
V_44 . V_19 = sizeof( V_20 ) ;
V_44 . V_20 = V_20 ;
for ( V_7 = 0 ; V_7 < V_55 ; V_7 ++ ) {
memcpy ( V_20 , V_54 [ V_7 ] , sizeof( V_20 ) ) ;
if ( F_2 ( V_5 -> V_22 , & V_44 , 1 ) != 1 )
return - V_23 ;
}
return F_14 ( V_5 ) ;
}
struct V_1 *
F_21 ( const struct V_61 * V_16 ,
struct V_62 * V_22 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
T_2 V_20 [ 2 ] ;
struct V_10 V_44 ;
V_5 = F_22 ( sizeof( struct V_4 ) , V_63 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_16 = V_16 ;
V_5 -> V_22 = V_22 ;
V_2 = & V_5 -> V_2 ;
memcpy ( & V_2 -> V_64 , & V_65 , sizeof( struct V_66 ) ) ;
V_2 -> V_15 = V_5 ;
V_20 [ 0 ] = 0x01 ;
V_20 [ 1 ] = 0x80 ;
V_44 . V_6 = V_5 -> V_16 -> V_17 ;
V_44 . V_18 = 0 ;
V_44 . V_19 = sizeof( V_20 ) ;
V_44 . V_20 = V_20 ;
if ( F_2 ( V_5 -> V_22 , & V_44 , 1 ) != 1 ) {
F_19 ( V_5 ) ;
return NULL ;
}
return V_2 ;
}
