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
void
F_4 ( struct V_8 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 -> V_12 . V_13 . V_10 ;
const T_1 V_14 = V_2 -> V_5 * 0x100 ;
const T_1 V_15 = V_2 -> V_5 + 1 ;
if ( V_2 -> V_4 . V_6 . V_7 & 1 )
F_5 ( V_10 , 0x612308 + V_14 , 0x0000001f , 0x00000000 | V_15 ) ;
if ( V_2 -> V_4 . V_6 . V_7 & 2 )
F_5 ( V_10 , 0x612388 + V_14 , 0x0000001f , 0x00000010 | V_15 ) ;
}
static inline T_1
F_6 ( struct V_9 * V_10 , T_2 V_16 )
{
return V_16 * 0x08 ;
}
static int
F_7 ( struct V_1 * V_2 , int V_17 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
const T_1 V_14 = F_1 ( V_2 ) ;
const T_1 V_15 = 0x01010101 * V_17 ;
if ( V_2 -> V_3 . V_4 . V_6 . V_7 & 1 )
F_5 ( V_10 , 0x61c110 + V_14 , 0x0f0f0f0f , V_15 ) ;
else
F_5 ( V_10 , 0x61c12c + V_14 , 0x0f0f0f0f , V_15 ) ;
return 0 ;
}
static int
F_8 ( struct V_1 * V_2 , int V_18 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
const T_1 V_14 = F_1 ( V_2 ) ;
const T_1 V_19 = F_3 ( V_2 ) ;
T_1 V_20 = 0 , V_21 ;
for ( V_21 = 0 ; V_21 < V_18 ; V_21 ++ )
V_20 |= 1 << ( F_6 ( V_10 , V_21 ) >> 3 ) ;
F_5 ( V_10 , 0x61c130 + V_19 , 0x0000000f , V_20 ) ;
F_5 ( V_10 , 0x61c034 + V_14 , 0x80000000 , 0x80000000 ) ;
F_9 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c034 + soff) & 0x80000000))
break;
) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 ,
int V_22 , int V_23 , int V_24 , int V_25 )
{
struct V_9 * V_10 = V_2 -> V_3 . V_11 -> V_12 . V_13 . V_10 ;
struct V_26 * V_27 = V_10 -> V_27 ;
const T_1 V_28 = F_6 ( V_10 , V_22 ) ;
const T_1 V_19 = F_3 ( V_2 ) ;
T_1 V_29 , V_15 [ 4 ] ;
T_2 V_30 , V_31 , V_32 , V_33 ;
struct V_34 V_4 ;
struct V_35 V_36 ;
V_29 = F_11 ( V_27 , V_2 -> V_3 . V_4 . V_37 ,
V_2 -> V_3 . V_4 . V_38 ,
& V_30 , & V_31 , & V_32 , & V_33 , & V_4 ) ;
if ( ! V_29 )
return - V_39 ;
V_29 = F_12 ( V_27 , V_29 , V_25 , V_23 , V_24 ,
& V_30 , & V_31 , & V_32 , & V_33 , & V_36 ) ;
if ( ! V_29 )
return - V_40 ;
V_36 . V_41 &= 0x0f ;
V_15 [ 0 ] = F_13 ( V_10 , 0x61c118 + V_19 ) & ~ ( 0x000000ff << V_28 ) ;
V_15 [ 1 ] = F_13 ( V_10 , 0x61c120 + V_19 ) & ~ ( 0x000000ff << V_28 ) ;
V_15 [ 2 ] = F_13 ( V_10 , 0x61c130 + V_19 ) ;
if ( ( V_15 [ 2 ] & 0x00000f00 ) < ( V_36 . V_41 << 8 ) || V_22 == 0 )
V_15 [ 2 ] = ( V_15 [ 2 ] & ~ 0x00000f00 ) | ( V_36 . V_41 << 8 ) ;
F_14 ( V_10 , 0x61c118 + V_19 , V_15 [ 0 ] | ( V_36 . V_42 << V_28 ) ) ;
F_14 ( V_10 , 0x61c120 + V_19 , V_15 [ 1 ] | ( V_36 . V_24 << V_28 ) ) ;
F_14 ( V_10 , 0x61c130 + V_19 , V_15 [ 2 ] ) ;
V_15 [ 3 ] = F_13 ( V_10 , 0x61c13c + V_19 ) & ~ ( 0x000000ff << V_28 ) ;
F_14 ( V_10 , 0x61c13c + V_19 , V_15 [ 3 ] | ( V_36 . V_25 << V_28 ) ) ;
return 0 ;
}
int
F_15 ( struct V_43 * V_11 , int V_44 , struct V_45 * V_46 ,
struct V_8 * * V_47 )
{
return F_16 ( & V_48 , V_11 , V_44 , V_46 , V_47 ) ;
}
