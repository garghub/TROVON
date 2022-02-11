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
int
F_4 ( struct V_8 * V_9 , int V_10 ,
struct V_11 * V_12 , struct V_13 * * V_14 )
{
return F_5 ( & V_15 , V_9 ,
V_10 , V_12 , V_14 ) ;
}
T_1
F_6 ( struct V_16 * V_17 , T_2 V_18 )
{
static const T_2 V_19 [] = { 0 , 8 , 16 , 24 } ;
static const T_2 V_20 [] = { 24 , 16 , 8 , 0 } ;
static const T_2 V_21 [] = { 16 , 8 , 0 , 24 } ;
if ( V_17 -> V_22 >= 0x110 )
return V_19 [ V_18 ] ;
if ( V_17 -> V_22 == 0xaf )
return V_20 [ V_18 ] ;
return V_21 [ V_18 ] ;
}
static int
F_7 ( struct V_1 * V_2 , int V_23 )
{
struct V_16 * V_17 = V_2 -> V_3 . V_9 -> V_24 . V_25 . V_17 ;
const T_1 V_26 = F_3 ( V_2 ) ;
F_8 ( V_17 , 0x61c10c + V_26 , 0x0f000000 , V_23 << 24 ) ;
return 0 ;
}
int
F_9 ( struct V_1 * V_2 , int V_27 )
{
struct V_16 * V_17 = V_2 -> V_3 . V_9 -> V_24 . V_25 . V_17 ;
const T_1 V_28 = F_1 ( V_2 ) ;
const T_1 V_26 = F_3 ( V_2 ) ;
T_1 V_29 = 0 , V_30 ;
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ )
V_29 |= 1 << ( F_6 ( V_17 , V_30 ) >> 3 ) ;
F_8 ( V_17 , 0x61c130 + V_26 , 0x0000000f , V_29 ) ;
F_8 ( V_17 , 0x61c034 + V_28 , 0x80000000 , 0x80000000 ) ;
F_10 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c034 + soff) & 0x80000000))
break;
) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , int V_27 , int V_31 , bool V_32 )
{
struct V_16 * V_17 = V_2 -> V_3 . V_9 -> V_24 . V_25 . V_17 ;
const T_1 V_28 = F_1 ( V_2 ) ;
const T_1 V_26 = F_3 ( V_2 ) ;
T_1 V_33 = 0x00000000 ;
T_1 V_34 = 0x00000000 ;
V_33 |= ( ( 1 << V_27 ) - 1 ) << 16 ;
if ( V_32 )
V_33 |= 0x00004000 ;
if ( V_31 > 0x06 )
V_34 |= 0x00040000 ;
F_8 ( V_17 , 0x614300 + V_28 , 0x000c0000 , V_34 ) ;
F_8 ( V_17 , 0x61c10c + V_26 , 0x001f4000 , V_33 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , int V_35 , int V_36 , int V_37 , int V_38 )
{
struct V_16 * V_17 = V_2 -> V_3 . V_9 -> V_24 . V_25 . V_17 ;
struct V_39 * V_40 = V_17 -> V_40 ;
const T_1 V_41 = F_6 ( V_17 , V_35 ) ;
const T_1 V_26 = F_3 ( V_2 ) ;
T_1 V_42 , V_43 [ 3 ] ;
T_2 V_44 , V_45 , V_46 , V_47 ;
struct V_48 V_4 ;
struct V_49 V_50 ;
V_42 = F_13 ( V_40 , V_2 -> V_3 . V_4 . V_51 ,
V_2 -> V_3 . V_4 . V_52 ,
& V_44 , & V_45 , & V_46 , & V_47 , & V_4 ) ;
if ( ! V_42 )
return - V_53 ;
V_42 = F_14 ( V_40 , V_42 , 0 , V_36 , V_37 ,
& V_44 , & V_45 , & V_46 , & V_47 , & V_50 ) ;
if ( ! V_42 )
return - V_54 ;
V_43 [ 0 ] = F_15 ( V_17 , 0x61c118 + V_26 ) & ~ ( 0x000000ff << V_41 ) ;
V_43 [ 1 ] = F_15 ( V_17 , 0x61c120 + V_26 ) & ~ ( 0x000000ff << V_41 ) ;
V_43 [ 2 ] = F_15 ( V_17 , 0x61c130 + V_26 ) ;
if ( ( V_43 [ 2 ] & 0x0000ff00 ) < ( V_50 . V_55 << 8 ) || V_35 == 0 )
V_43 [ 2 ] = ( V_43 [ 2 ] & ~ 0x0000ff00 ) | ( V_50 . V_55 << 8 ) ;
F_16 ( V_17 , 0x61c118 + V_26 , V_43 [ 0 ] | ( V_50 . V_56 << V_41 ) ) ;
F_16 ( V_17 , 0x61c120 + V_26 , V_43 [ 1 ] | ( V_50 . V_37 << V_41 ) ) ;
F_16 ( V_17 , 0x61c130 + V_26 , V_43 [ 2 ] ) ;
return 0 ;
}
int
F_17 ( struct V_8 * V_9 , int V_10 , struct V_11 * V_12 ,
struct V_13 * * V_14 )
{
return F_18 ( & V_57 , V_9 , V_10 , V_12 , V_14 ) ;
}
