static inline T_1
F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 ) - 1 ) * 0x800 ;
}
static inline T_1
F_3 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) + ! ( V_2 -> V_4 . V_5 & 1 ) * 0x80 ;
}
static inline T_1
F_4 ( struct V_6 * V_7 , T_2 V_8 )
{
static const T_2 V_9 [] = { 16 , 8 , 0 , 24 } ;
return V_9 [ V_8 ] ;
}
static int
F_5 ( struct V_10 * V_11 , struct V_1 * V_2 ,
int V_12 , int V_13 )
{
struct V_6 * V_7 = ( void * ) V_11 ;
const T_1 V_14 = F_3 ( V_2 ) ;
F_6 ( V_7 , 0x61c110 + V_14 , 0x0f0f0f0f , 0x01010101 * V_13 ) ;
return 0 ;
}
static int
F_7 ( struct V_10 * V_11 , struct V_1 * V_2 ,
int V_12 , int V_15 , int V_16 , bool V_17 )
{
struct V_6 * V_7 = ( void * ) V_11 ;
const T_1 V_18 = F_1 ( V_2 ) ;
const T_1 V_14 = F_3 ( V_2 ) ;
T_1 V_19 = 0x00000000 ;
T_1 V_20 = 0x00000000 ;
T_1 V_8 = 0 ;
int V_21 ;
V_20 |= V_16 << 18 ;
V_19 |= ( ( 1 << V_15 ) - 1 ) << 16 ;
if ( V_17 )
V_19 |= 0x00004000 ;
for ( V_21 = 0 ; V_21 < V_15 ; V_21 ++ )
V_8 |= 1 << ( F_4 ( V_7 , V_21 ) >> 3 ) ;
F_6 ( V_7 , 0x612300 + V_18 , 0x007c0000 , V_20 ) ;
F_6 ( V_7 , 0x61c10c + V_14 , 0x001f4000 , V_19 ) ;
F_6 ( V_7 , 0x61c130 + V_14 , 0x0000000f , V_8 ) ;
return 0 ;
}
static int
F_8 ( struct V_10 * V_11 , struct V_1 * V_2 ,
int V_12 , int V_8 , int V_22 , int V_23 )
{
struct V_24 * V_25 = V_24 ( V_11 ) ;
struct V_6 * V_7 = ( void * ) V_11 ;
const T_1 V_14 = F_3 ( V_2 ) ;
T_1 V_26 , V_27 = F_4 ( V_7 , V_8 ) ;
T_2 V_28 , V_29 , V_30 , V_31 ;
struct V_32 V_33 ;
struct V_34 V_35 ;
V_26 = F_9 ( V_25 , V_2 -> V_36 , V_2 -> V_37 ,
& V_28 , & V_29 , & V_30 , & V_31 , & V_33 ) ;
if ( ! V_26 )
return - V_38 ;
V_26 = F_10 ( V_25 , V_26 , 0 , V_22 , V_23 ,
& V_28 , & V_29 , & V_30 , & V_31 , & V_35 ) ;
if ( ! V_26 )
return - V_39 ;
F_6 ( V_7 , 0x61c118 + V_14 , 0x000000ff << V_27 , V_35 . V_40 << V_27 ) ;
F_6 ( V_7 , 0x61c120 + V_14 , 0x000000ff << V_27 , V_35 . V_41 << V_27 ) ;
F_6 ( V_7 , 0x61c130 + V_14 , 0x0000ff00 , V_35 . V_42 << 8 ) ;
F_6 ( V_7 , 0x61c13c + V_14 , 0x00000000 , 0x00000000 ) ;
return 0 ;
}
