static inline T_1
F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 . V_4 . V_5 ) - 1 ) * 0x800 ;
}
static inline T_1
F_3 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) + ! ( V_2 -> V_3 . V_4 . V_6 . V_7 & 1 ) * 0x80 ;
}
static inline T_1
F_4 ( struct V_8 * V_9 , T_2 V_10 )
{
static const T_2 V_11 [] = { 16 , 8 , 0 , 24 } ;
return V_11 [ V_10 ] ;
}
static int
F_5 ( struct V_1 * V_2 , int V_12 )
{
struct V_8 * V_9 = ( void * ) F_6 ( V_2 ) ;
const T_1 V_13 = F_3 ( V_2 ) ;
F_7 ( V_9 , 0x61c110 + V_13 , 0x0f0f0f0f , 0x01010101 * V_12 ) ;
return 0 ;
}
int
F_8 ( struct V_1 * V_2 , int V_14 , int V_15 , bool V_16 )
{
struct V_8 * V_9 = ( void * ) F_6 ( V_2 ) ;
const T_1 V_17 = F_1 ( V_2 ) ;
const T_1 V_13 = F_3 ( V_2 ) ;
T_1 V_18 = 0x00000000 ;
T_1 V_19 = 0x00000000 ;
V_19 |= V_15 << 18 ;
V_18 |= ( ( 1 << V_14 ) - 1 ) << 16 ;
if ( V_16 )
V_18 |= 0x00004000 ;
F_7 ( V_9 , 0x612300 + V_17 , 0x007c0000 , V_19 ) ;
F_7 ( V_9 , 0x61c10c + V_13 , 0x001f4000 , V_18 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 ,
int V_20 , int V_21 , int V_22 , int V_23 )
{
struct V_8 * V_9 = ( void * ) F_6 ( V_2 ) ;
struct V_24 * V_25 = V_24 ( V_9 ) ;
const T_1 V_26 = F_4 ( V_9 , V_20 ) ;
const T_1 V_13 = F_3 ( V_2 ) ;
T_1 V_27 , V_28 [ 4 ] ;
T_2 V_29 , V_30 , V_31 , V_32 ;
struct V_33 V_4 ;
struct V_34 V_35 ;
V_27 = F_10 ( V_25 , V_2 -> V_3 . V_4 . V_36 ,
V_2 -> V_3 . V_4 . V_37 ,
& V_29 , & V_30 , & V_31 , & V_32 , & V_4 ) ;
if ( ! V_27 )
return - V_38 ;
V_27 = F_11 ( V_25 , V_27 , V_23 , V_21 , V_22 ,
& V_29 , & V_30 , & V_31 , & V_32 , & V_35 ) ;
if ( ! V_27 )
return - V_39 ;
V_28 [ 0 ] = F_12 ( V_9 , 0x61c118 + V_13 ) & ~ ( 0x000000ff << V_26 ) ;
V_28 [ 1 ] = F_12 ( V_9 , 0x61c120 + V_13 ) & ~ ( 0x000000ff << V_26 ) ;
V_28 [ 2 ] = F_12 ( V_9 , 0x61c130 + V_13 ) ;
if ( ( V_28 [ 2 ] & 0x0000ff00 ) < ( V_35 . V_40 << 8 ) || V_20 == 0 )
V_28 [ 2 ] = ( V_28 [ 2 ] & ~ 0x0000ff00 ) | ( V_35 . V_40 << 8 ) ;
F_13 ( V_9 , 0x61c118 + V_13 , V_28 [ 0 ] | ( V_35 . V_41 << V_26 ) ) ;
F_13 ( V_9 , 0x61c120 + V_13 , V_28 [ 1 ] | ( V_35 . V_22 << V_26 ) ) ;
F_13 ( V_9 , 0x61c130 + V_13 , V_28 [ 2 ] | ( V_35 . V_40 << 8 ) ) ;
V_28 [ 3 ] = F_12 ( V_9 , 0x61c13c + V_13 ) & ~ ( 0x000000ff << V_26 ) ;
F_13 ( V_9 , 0x61c13c + V_13 , V_28 [ 3 ] | ( V_35 . V_23 << V_26 ) ) ;
return 0 ;
}
