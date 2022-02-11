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
const T_1 V_14 = F_1 ( V_2 ) ;
F_5 ( V_10 , 0x61c110 + V_14 , 0x0f0f0f0f , 0x01010101 * V_8 ) ;
return 0 ;
}
int
F_6 ( struct V_1 * V_2 , int V_15 , int V_16 , bool V_17 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
const T_1 V_14 = F_1 ( V_2 ) ;
const T_1 V_18 = F_3 ( V_2 ) ;
T_1 V_19 = 0x00000000 ;
T_1 V_20 = 0x00000000 ;
V_20 |= V_16 << 18 ;
V_19 |= ( ( 1 << V_15 ) - 1 ) << 16 ;
if ( V_2 -> V_21 . V_22 )
V_19 |= 0x40000000 ;
if ( V_17 )
V_19 |= 0x00004000 ;
F_5 ( V_10 , 0x612300 + V_14 , 0x007c0000 , V_20 ) ;
F_5 ( V_10 , 0x61c10c + V_18 , 0x401f4000 , V_19 ) ;
return 0 ;
}
int
F_7 ( struct V_1 * V_2 ,
int V_23 , int V_24 , int V_25 , int V_26 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
struct V_27 * V_28 = V_10 -> V_28 ;
const T_1 V_29 = F_8 ( V_10 , V_23 ) ;
const T_1 V_18 = F_3 ( V_2 ) ;
T_1 V_30 , V_31 [ 4 ] ;
T_2 V_32 , V_33 , V_34 , V_35 ;
struct V_36 V_4 ;
struct V_37 V_38 ;
V_30 = F_9 ( V_28 , V_2 -> V_3 . V_4 . V_39 ,
V_2 -> V_3 . V_4 . V_40 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_4 ) ;
if ( ! V_30 )
return - V_41 ;
V_30 = F_10 ( V_28 , V_30 , V_26 , V_24 , V_25 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_38 ) ;
if ( ! V_30 )
return - V_42 ;
V_31 [ 0 ] = F_11 ( V_10 , 0x61c118 + V_18 ) & ~ ( 0x000000ff << V_29 ) ;
V_31 [ 1 ] = F_11 ( V_10 , 0x61c120 + V_18 ) & ~ ( 0x000000ff << V_29 ) ;
V_31 [ 2 ] = F_11 ( V_10 , 0x61c130 + V_18 ) ;
if ( ( V_31 [ 2 ] & 0x0000ff00 ) < ( V_38 . V_43 << 8 ) || V_23 == 0 )
V_31 [ 2 ] = ( V_31 [ 2 ] & ~ 0x0000ff00 ) | ( V_38 . V_43 << 8 ) ;
F_12 ( V_10 , 0x61c118 + V_18 , V_31 [ 0 ] | ( V_38 . V_44 << V_29 ) ) ;
F_12 ( V_10 , 0x61c120 + V_18 , V_31 [ 1 ] | ( V_38 . V_25 << V_29 ) ) ;
F_12 ( V_10 , 0x61c130 + V_18 , V_31 [ 2 ] ) ;
V_31 [ 3 ] = F_11 ( V_10 , 0x61c13c + V_18 ) & ~ ( 0x000000ff << V_29 ) ;
F_12 ( V_10 , 0x61c13c + V_18 , V_31 [ 3 ] | ( V_38 . V_26 << V_29 ) ) ;
return 0 ;
}
void
F_13 ( struct V_1 * V_2 , int V_45 , T_2 V_46 ,
T_2 V_47 , T_3 V_48 , T_3 V_49 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
const T_1 V_50 = V_45 * 0x800 ;
F_5 ( V_10 , 0x616588 + V_50 , 0x00003f3f , ( V_47 << 8 ) | V_46 ) ;
F_5 ( V_10 , 0x61658c + V_50 , 0xffffffff , ( V_49 << 16 ) | V_48 ) ;
}
int
F_14 ( struct V_51 * V_11 , int V_52 ,
struct V_53 * V_54 , struct V_55 * * V_56 )
{
return F_15 ( & V_57 , V_11 , V_52 , V_54 , V_56 ) ;
}
