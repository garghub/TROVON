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
static const T_2 V_9 [] = { 24 , 16 , 8 , 0 } ;
static const T_2 V_10 [] = { 16 , 8 , 0 , 24 } ;
if ( F_5 ( V_7 ) -> V_11 == 0xaf )
return V_9 [ V_8 ] ;
return V_10 [ V_8 ] ;
}
static int
F_6 ( struct V_12 * V_13 , struct V_1 * V_2 ,
int V_14 , int V_15 )
{
struct V_6 * V_7 = ( void * ) V_13 ;
const T_1 V_16 = F_3 ( V_2 ) ;
F_7 ( V_7 , 0x61c10c + V_16 , 0x0f000000 , V_15 << 24 ) ;
return 0 ;
}
static int
F_8 ( struct V_12 * V_13 , struct V_1 * V_2 ,
int V_14 , int V_17 , int V_18 , bool V_19 )
{
struct V_6 * V_7 = ( void * ) V_13 ;
const T_1 V_20 = F_1 ( V_2 ) ;
const T_1 V_16 = F_3 ( V_2 ) ;
T_1 V_21 = 0x00000000 ;
T_1 V_22 = 0x00000000 ;
T_1 V_8 = 0 ;
int V_23 ;
V_21 |= ( ( 1 << V_17 ) - 1 ) << 16 ;
if ( V_19 )
V_21 |= 0x00004000 ;
if ( V_18 > 0x06 )
V_22 |= 0x00040000 ;
for ( V_23 = 0 ; V_23 < V_17 ; V_23 ++ )
V_8 |= 1 << ( F_4 ( V_7 , V_23 ) >> 3 ) ;
F_7 ( V_7 , 0x614300 + V_20 , 0x000c0000 , V_22 ) ;
F_7 ( V_7 , 0x61c10c + V_16 , 0x001f4000 , V_21 ) ;
F_7 ( V_7 , 0x61c130 + V_16 , 0x0000000f , V_8 ) ;
return 0 ;
}
static int
F_9 ( struct V_12 * V_13 , struct V_1 * V_2 ,
int V_14 , int V_8 , int V_24 , int V_25 )
{
struct V_26 * V_27 = V_26 ( V_13 ) ;
struct V_6 * V_7 = ( void * ) V_13 ;
const T_1 V_28 = F_4 ( V_7 , V_8 ) ;
const T_1 V_16 = F_3 ( V_2 ) ;
T_1 V_29 , V_30 [ 3 ] ;
T_2 V_31 , V_32 , V_33 , V_34 ;
struct V_35 V_36 ;
struct V_37 V_38 ;
V_29 = F_10 ( V_27 , V_2 -> V_39 , V_2 -> V_40 ,
& V_31 , & V_32 , & V_33 , & V_34 , & V_36 ) ;
if ( ! V_29 )
return - V_41 ;
V_29 = F_11 ( V_27 , V_29 , 0 , V_24 , V_25 ,
& V_31 , & V_32 , & V_33 , & V_34 , & V_38 ) ;
if ( ! V_29 )
return - V_42 ;
V_30 [ 0 ] = F_12 ( V_7 , 0x61c118 + V_16 ) & ~ ( 0x000000ff << V_28 ) ;
V_30 [ 1 ] = F_12 ( V_7 , 0x61c120 + V_16 ) & ~ ( 0x000000ff << V_28 ) ;
V_30 [ 2 ] = F_12 ( V_7 , 0x61c130 + V_16 ) & ~ ( 0x0000ff00 ) ;
F_13 ( V_7 , 0x61c118 + V_16 , V_30 [ 0 ] | ( V_38 . V_43 << V_28 ) ) ;
F_13 ( V_7 , 0x61c120 + V_16 , V_30 [ 1 ] | ( V_38 . V_44 << V_28 ) ) ;
F_13 ( V_7 , 0x61c130 + V_16 , V_30 [ 2 ] | ( V_38 . V_45 << 8 ) ) ;
return 0 ;
}
