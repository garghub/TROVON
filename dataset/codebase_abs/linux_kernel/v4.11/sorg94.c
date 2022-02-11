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
T_1
F_4 ( struct V_8 * V_9 , T_2 V_10 )
{
static const T_2 V_11 [] = { 0 , 8 , 16 , 24 } ;
static const T_2 V_12 [] = { 24 , 16 , 8 , 0 } ;
static const T_2 V_13 [] = { 16 , 8 , 0 , 24 } ;
if ( V_9 -> V_14 >= 0x110 )
return V_11 [ V_10 ] ;
if ( V_9 -> V_14 == 0xaf )
return V_12 [ V_10 ] ;
return V_13 [ V_10 ] ;
}
static int
F_5 ( struct V_1 * V_2 , int V_15 )
{
struct V_8 * V_9 = V_2 -> V_3 . V_16 -> V_17 . V_18 . V_9 ;
const T_1 V_19 = F_3 ( V_2 ) ;
F_6 ( V_9 , 0x61c10c + V_19 , 0x0f000000 , V_15 << 24 ) ;
return 0 ;
}
int
F_7 ( struct V_1 * V_2 , int V_20 )
{
struct V_8 * V_9 = V_2 -> V_3 . V_16 -> V_17 . V_18 . V_9 ;
const T_1 V_21 = F_1 ( V_2 ) ;
const T_1 V_19 = F_3 ( V_2 ) ;
T_1 V_22 = 0 , V_23 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ )
V_22 |= 1 << ( F_4 ( V_9 , V_23 ) >> 3 ) ;
F_6 ( V_9 , 0x61c130 + V_19 , 0x0000000f , V_22 ) ;
F_6 ( V_9 , 0x61c034 + V_21 , 0x80000000 , 0x80000000 ) ;
F_8 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c034 + soff) & 0x80000000))
break;
) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , int V_20 , int V_24 , bool V_25 )
{
struct V_8 * V_9 = V_2 -> V_3 . V_16 -> V_17 . V_18 . V_9 ;
const T_1 V_21 = F_1 ( V_2 ) ;
const T_1 V_19 = F_3 ( V_2 ) ;
T_1 V_26 = 0x00000000 ;
T_1 V_27 = 0x00000000 ;
V_26 |= ( ( 1 << V_20 ) - 1 ) << 16 ;
if ( V_25 )
V_26 |= 0x00004000 ;
if ( V_24 > 0x06 )
V_27 |= 0x00040000 ;
F_6 ( V_9 , 0x614300 + V_21 , 0x000c0000 , V_27 ) ;
F_6 ( V_9 , 0x61c10c + V_19 , 0x001f4000 , V_26 ) ;
return 0 ;
}
static int
F_10 ( struct V_1 * V_2 , int V_28 , int V_29 , int V_30 , int V_31 )
{
struct V_8 * V_9 = V_2 -> V_3 . V_16 -> V_17 . V_18 . V_9 ;
struct V_32 * V_33 = V_9 -> V_33 ;
const T_1 V_34 = F_4 ( V_9 , V_28 ) ;
const T_1 V_19 = F_3 ( V_2 ) ;
T_1 V_35 , V_36 [ 3 ] ;
T_2 V_37 , V_38 , V_39 , V_40 ;
struct V_41 V_4 ;
struct V_42 V_43 ;
V_35 = F_11 ( V_33 , V_2 -> V_3 . V_4 . V_44 ,
V_2 -> V_3 . V_4 . V_45 ,
& V_37 , & V_38 , & V_39 , & V_40 , & V_4 ) ;
if ( ! V_35 )
return - V_46 ;
V_35 = F_12 ( V_33 , V_35 , 0 , V_29 , V_30 ,
& V_37 , & V_38 , & V_39 , & V_40 , & V_43 ) ;
if ( ! V_35 )
return - V_47 ;
V_36 [ 0 ] = F_13 ( V_9 , 0x61c118 + V_19 ) & ~ ( 0x000000ff << V_34 ) ;
V_36 [ 1 ] = F_13 ( V_9 , 0x61c120 + V_19 ) & ~ ( 0x000000ff << V_34 ) ;
V_36 [ 2 ] = F_13 ( V_9 , 0x61c130 + V_19 ) ;
if ( ( V_36 [ 2 ] & 0x0000ff00 ) < ( V_43 . V_48 << 8 ) || V_28 == 0 )
V_36 [ 2 ] = ( V_36 [ 2 ] & ~ 0x0000ff00 ) | ( V_43 . V_48 << 8 ) ;
F_14 ( V_9 , 0x61c118 + V_19 , V_36 [ 0 ] | ( V_43 . V_49 << V_34 ) ) ;
F_14 ( V_9 , 0x61c120 + V_19 , V_36 [ 1 ] | ( V_43 . V_30 << V_34 ) ) ;
F_14 ( V_9 , 0x61c130 + V_19 , V_36 [ 2 ] ) ;
return 0 ;
}
int
F_15 ( struct V_50 * V_16 , int V_51 , struct V_52 * V_53 ,
struct V_54 * * V_55 )
{
return F_16 ( & V_56 , V_16 , V_51 , V_53 , V_55 ) ;
}
