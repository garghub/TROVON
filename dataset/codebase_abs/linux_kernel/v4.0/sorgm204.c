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
struct V_9 * V_10 = ( void * ) F_5 ( V_2 ) ;
const T_1 V_11 = V_2 -> V_5 * 0x100 ;
const T_1 V_12 = V_2 -> V_5 + 1 ;
if ( V_2 -> V_4 . V_6 . V_7 & 1 )
F_6 ( V_10 , 0x612308 + V_11 , 0x0000001f , 0x00000000 | V_12 ) ;
if ( V_2 -> V_4 . V_6 . V_7 & 2 )
F_6 ( V_10 , 0x612388 + V_11 , 0x0000001f , 0x00000010 | V_12 ) ;
}
static inline T_1
F_7 ( struct V_9 * V_10 , T_2 V_13 )
{
return V_13 * 0x08 ;
}
static int
F_8 ( struct V_1 * V_2 , int V_14 )
{
struct V_9 * V_10 = ( void * ) F_5 ( V_2 ) ;
const T_1 V_11 = F_1 ( V_2 ) ;
const T_1 V_12 = 0x01010101 * V_14 ;
if ( V_2 -> V_3 . V_4 . V_6 . V_7 & 1 )
F_6 ( V_10 , 0x61c110 + V_11 , 0x0f0f0f0f , V_12 ) ;
else
F_6 ( V_10 , 0x61c12c + V_11 , 0x0f0f0f0f , V_12 ) ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , int V_15 )
{
struct V_9 * V_10 = ( void * ) F_5 ( V_2 ) ;
const T_1 V_11 = F_1 ( V_2 ) ;
const T_1 V_16 = F_3 ( V_2 ) ;
T_1 V_17 = 0 , V_18 ;
for ( V_18 = 0 ; V_18 < V_15 ; V_18 ++ )
V_17 |= 1 << ( F_7 ( V_10 , V_18 ) >> 3 ) ;
F_6 ( V_10 , 0x61c130 + V_16 , 0x0000000f , V_17 ) ;
F_6 ( V_10 , 0x61c034 + V_11 , 0x80000000 , 0x80000000 ) ;
F_10 ( V_10 , 0x61c034 + V_11 , 0x80000000 , 0x00000000 ) ;
return 0 ;
}
static int
F_11 ( struct V_1 * V_2 ,
int V_19 , int V_20 , int V_21 , int V_22 )
{
struct V_9 * V_10 = ( void * ) F_5 ( V_2 ) ;
struct V_23 * V_24 = V_23 ( V_10 ) ;
const T_1 V_25 = F_7 ( V_10 , V_19 ) ;
const T_1 V_16 = F_3 ( V_2 ) ;
T_1 V_26 , V_12 [ 4 ] ;
T_2 V_27 , V_28 , V_29 , V_30 ;
struct V_31 V_4 ;
struct V_32 V_33 ;
V_26 = F_12 ( V_24 , V_2 -> V_3 . V_4 . V_34 ,
V_2 -> V_3 . V_4 . V_35 ,
& V_27 , & V_28 , & V_29 , & V_30 , & V_4 ) ;
if ( ! V_26 )
return - V_36 ;
V_26 = F_13 ( V_24 , V_26 , V_22 , V_20 , V_21 ,
& V_27 , & V_28 , & V_29 , & V_30 , & V_33 ) ;
if ( ! V_26 )
return - V_37 ;
V_12 [ 0 ] = F_14 ( V_10 , 0x61c118 + V_16 ) & ~ ( 0x000000ff << V_25 ) ;
V_12 [ 1 ] = F_14 ( V_10 , 0x61c120 + V_16 ) & ~ ( 0x000000ff << V_25 ) ;
V_12 [ 2 ] = F_14 ( V_10 , 0x61c130 + V_16 ) ;
if ( ( V_12 [ 2 ] & 0x0000ff00 ) < ( V_33 . V_38 << 8 ) || V_19 == 0 )
V_12 [ 2 ] = ( V_12 [ 2 ] & ~ 0x0000ff00 ) | ( V_33 . V_38 << 8 ) ;
F_15 ( V_10 , 0x61c118 + V_16 , V_12 [ 0 ] | ( V_33 . V_39 << V_25 ) ) ;
F_15 ( V_10 , 0x61c120 + V_16 , V_12 [ 1 ] | ( V_33 . V_21 << V_25 ) ) ;
F_15 ( V_10 , 0x61c130 + V_16 , V_12 [ 2 ] | ( V_33 . V_38 << 8 ) ) ;
V_12 [ 3 ] = F_14 ( V_10 , 0x61c13c + V_16 ) & ~ ( 0x000000ff << V_25 ) ;
F_15 ( V_10 , 0x61c13c + V_16 , V_12 [ 3 ] | ( V_33 . V_22 << V_25 ) ) ;
return 0 ;
}
