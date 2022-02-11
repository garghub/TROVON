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
static int
F_4 ( struct V_1 * V_2 , int V_8 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
const T_1 V_14 = F_3 ( V_2 ) ;
F_5 ( V_10 , 0x61c110 + V_14 , 0x0f0f0f0f , 0x01010101 * V_8 ) ;
return 0 ;
}
int
F_6 ( struct V_1 * V_2 , int V_15 , int V_16 , bool V_17 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
const T_1 V_18 = F_1 ( V_2 ) ;
const T_1 V_14 = F_3 ( V_2 ) ;
T_1 V_19 = 0x00000000 ;
T_1 V_20 = 0x00000000 ;
V_20 |= V_16 << 18 ;
V_19 |= ( ( 1 << V_15 ) - 1 ) << 16 ;
if ( V_17 )
V_19 |= 0x00004000 ;
F_5 ( V_10 , 0x612300 + V_18 , 0x007c0000 , V_20 ) ;
F_5 ( V_10 , 0x61c10c + V_14 , 0x001f4000 , V_19 ) ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 ,
int V_21 , int V_22 , int V_23 , int V_24 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
struct V_25 * V_26 = V_10 -> V_26 ;
const T_1 V_27 = F_8 ( V_10 , V_21 ) ;
const T_1 V_14 = F_3 ( V_2 ) ;
T_1 V_28 , V_29 [ 4 ] ;
T_2 V_30 , V_31 , V_32 , V_33 ;
struct V_34 V_4 ;
struct V_35 V_36 ;
V_28 = F_9 ( V_26 , V_2 -> V_3 . V_4 . V_37 ,
V_2 -> V_3 . V_4 . V_38 ,
& V_30 , & V_31 , & V_32 , & V_33 , & V_4 ) ;
if ( ! V_28 )
return - V_39 ;
V_28 = F_10 ( V_26 , V_28 , V_24 , V_22 , V_23 ,
& V_30 , & V_31 , & V_32 , & V_33 , & V_36 ) ;
if ( ! V_28 )
return - V_40 ;
V_29 [ 0 ] = F_11 ( V_10 , 0x61c118 + V_14 ) & ~ ( 0x000000ff << V_27 ) ;
V_29 [ 1 ] = F_11 ( V_10 , 0x61c120 + V_14 ) & ~ ( 0x000000ff << V_27 ) ;
V_29 [ 2 ] = F_11 ( V_10 , 0x61c130 + V_14 ) ;
if ( ( V_29 [ 2 ] & 0x0000ff00 ) < ( V_36 . V_41 << 8 ) || V_21 == 0 )
V_29 [ 2 ] = ( V_29 [ 2 ] & ~ 0x0000ff00 ) | ( V_36 . V_41 << 8 ) ;
F_12 ( V_10 , 0x61c118 + V_14 , V_29 [ 0 ] | ( V_36 . V_42 << V_27 ) ) ;
F_12 ( V_10 , 0x61c120 + V_14 , V_29 [ 1 ] | ( V_36 . V_23 << V_27 ) ) ;
F_12 ( V_10 , 0x61c130 + V_14 , V_29 [ 2 ] ) ;
V_29 [ 3 ] = F_11 ( V_10 , 0x61c13c + V_14 ) & ~ ( 0x000000ff << V_27 ) ;
F_12 ( V_10 , 0x61c13c + V_14 , V_29 [ 3 ] | ( V_36 . V_24 << V_27 ) ) ;
return 0 ;
}
int
F_13 ( struct V_43 * V_11 , int V_44 ,
struct V_45 * V_46 , struct V_47 * * V_48 )
{
return F_14 ( & V_49 , V_11 , V_44 , V_46 , V_48 ) ;
}
