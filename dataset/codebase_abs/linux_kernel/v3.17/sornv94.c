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
static const T_2 V_11 [] = { 24 , 16 , 8 , 0 } ;
static const T_2 V_12 [] = { 16 , 8 , 0 , 24 } ;
if ( F_5 ( V_9 ) -> V_13 == 0xaf )
return V_11 [ V_10 ] ;
return V_12 [ V_10 ] ;
}
static int
F_6 ( struct V_1 * V_2 , int V_14 )
{
struct V_8 * V_9 = ( void * ) F_7 ( V_2 ) ;
const T_1 V_15 = F_3 ( V_2 ) ;
F_8 ( V_9 , 0x61c10c + V_15 , 0x0f000000 , V_14 << 24 ) ;
return 0 ;
}
int
F_9 ( struct V_1 * V_2 , int V_16 )
{
struct V_8 * V_9 = ( void * ) F_7 ( V_2 ) ;
const T_1 V_17 = F_1 ( V_2 ) ;
const T_1 V_15 = F_3 ( V_2 ) ;
T_1 V_18 = 0 , V_19 ;
for ( V_19 = 0 ; V_19 < V_16 ; V_19 ++ )
V_18 |= 1 << ( F_4 ( V_9 , V_19 ) >> 3 ) ;
F_8 ( V_9 , 0x61c130 + V_15 , 0x0000000f , V_18 ) ;
F_8 ( V_9 , 0x61c034 + V_17 , 0x80000000 , 0x80000000 ) ;
F_10 ( V_9 , 0x61c034 + V_17 , 0x80000000 , 0x00000000 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 , int V_16 , int V_20 , bool V_21 )
{
struct V_8 * V_9 = ( void * ) F_7 ( V_2 ) ;
const T_1 V_17 = F_1 ( V_2 ) ;
const T_1 V_15 = F_3 ( V_2 ) ;
T_1 V_22 = 0x00000000 ;
T_1 V_23 = 0x00000000 ;
V_22 |= ( ( 1 << V_16 ) - 1 ) << 16 ;
if ( V_21 )
V_22 |= 0x00004000 ;
if ( V_20 > 0x06 )
V_23 |= 0x00040000 ;
F_8 ( V_9 , 0x614300 + V_17 , 0x000c0000 , V_23 ) ;
F_8 ( V_9 , 0x61c10c + V_15 , 0x001f4000 , V_22 ) ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , int V_24 , int V_25 , int V_26 , int V_27 )
{
struct V_8 * V_9 = ( void * ) F_7 ( V_2 ) ;
struct V_28 * V_29 = V_28 ( V_9 ) ;
const T_1 V_30 = F_4 ( V_9 , V_24 ) ;
const T_1 V_15 = F_3 ( V_2 ) ;
T_1 V_31 , V_32 [ 3 ] ;
T_2 V_33 , V_34 , V_35 , V_36 ;
struct V_37 V_4 ;
struct V_38 V_39 ;
V_31 = F_13 ( V_29 , V_2 -> V_3 . V_4 . V_40 ,
V_2 -> V_3 . V_4 . V_41 ,
& V_33 , & V_34 , & V_35 , & V_36 , & V_4 ) ;
if ( ! V_31 )
return - V_42 ;
V_31 = F_14 ( V_29 , V_31 , 0 , V_25 , V_26 ,
& V_33 , & V_34 , & V_35 , & V_36 , & V_39 ) ;
if ( ! V_31 )
return - V_43 ;
V_32 [ 0 ] = F_15 ( V_9 , 0x61c118 + V_15 ) & ~ ( 0x000000ff << V_30 ) ;
V_32 [ 1 ] = F_15 ( V_9 , 0x61c120 + V_15 ) & ~ ( 0x000000ff << V_30 ) ;
V_32 [ 2 ] = F_15 ( V_9 , 0x61c130 + V_15 ) ;
if ( ( V_32 [ 2 ] & 0x0000ff00 ) < ( V_39 . V_44 << 8 ) || V_24 == 0 )
V_32 [ 2 ] = ( V_32 [ 2 ] & ~ 0x0000ff00 ) | ( V_39 . V_44 << 8 ) ;
F_16 ( V_9 , 0x61c118 + V_15 , V_32 [ 0 ] | ( V_39 . V_45 << V_30 ) ) ;
F_16 ( V_9 , 0x61c120 + V_15 , V_32 [ 1 ] | ( V_39 . V_26 << V_30 ) ) ;
F_16 ( V_9 , 0x61c130 + V_15 , V_32 [ 2 ] | ( V_39 . V_44 << 8 ) ) ;
return 0 ;
}
