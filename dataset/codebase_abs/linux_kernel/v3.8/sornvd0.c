static inline T_1
F_1 ( struct V_1 * V_2 , T_2 V_3 )
{
static const T_2 V_4 [] = { 16 , 8 , 0 , 24 } ;
return V_4 [ V_3 ] ;
}
int
F_2 ( struct V_1 * V_2 , int V_5 , int V_6 ,
T_3 type , T_3 V_7 , T_1 V_8 , struct V_9 * V_10 )
{
const T_1 V_11 = ( V_5 * 0x800 ) + ( V_6 * 0x80 ) ;
const T_1 V_12 = ( V_8 & V_13 ) ;
F_3 ( V_2 , 0x61c110 + V_11 , 0x0f0f0f0f , 0x01010101 * V_12 ) ;
return 0 ;
}
int
F_4 ( struct V_1 * V_2 , int V_5 , int V_6 , int V_14 ,
T_3 type , T_3 V_7 , T_1 V_8 , struct V_9 * V_15 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
const T_1 V_11 = ( V_5 * 0x800 ) + ( V_6 * 0x80 ) ;
const T_1 V_18 = ( V_5 * 0x800 ) ;
const T_2 V_19 = ( V_8 & V_20 ) >> 8 ;
const T_2 V_21 = ( V_8 & V_22 ) ;
T_1 V_23 = 0x00000000 ;
T_1 V_24 = 0x00000000 ;
T_1 V_25 , V_3 = 0 ;
T_2 V_26 , V_27 , V_28 , V_29 ;
struct V_30 V_10 ;
int V_31 ;
V_25 = F_5 ( V_17 , type , V_7 , & V_26 , & V_27 , & V_28 , & V_29 , & V_10 ) ;
if ( V_25 && V_10 . V_32 ) {
struct V_33 V_34 = {
. V_35 = F_6 ( V_2 ) ,
. V_17 = V_17 ,
. V_36 = 0x0000 ,
. V_25 = V_15 ,
. V_37 = V_14 ,
. V_38 = 1 ,
} ;
while ( F_7 ( V_17 , V_10 . V_32 ) < V_19 )
V_10 . V_32 += 3 ;
V_34 . V_36 = F_8 ( V_17 , V_10 . V_32 + 1 ) ;
F_9 ( & V_34 ) ;
}
V_24 |= V_19 << 18 ;
V_23 |= ( ( 1 << V_21 ) - 1 ) << 16 ;
if ( V_8 & V_39 )
V_23 |= 0x00004000 ;
for ( V_31 = 0 ; V_31 < V_21 ; V_31 ++ )
V_3 |= 1 << ( F_1 ( V_2 , V_31 ) >> 3 ) ;
F_3 ( V_2 , 0x612300 + V_18 , 0x007c0000 , V_24 ) ;
F_3 ( V_2 , 0x61c10c + V_11 , 0x001f4000 , V_23 ) ;
F_3 ( V_2 , 0x61c130 + V_11 , 0x0000000f , V_3 ) ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 , int V_5 , int V_6 , int V_3 ,
T_3 type , T_3 V_7 , T_1 V_8 , struct V_9 * V_15 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
const T_1 V_11 = ( V_5 * 0x800 ) + ( V_6 * 0x80 ) ;
const T_2 V_40 = ( V_8 & V_41 ) >> 8 ;
const T_2 V_42 = ( V_8 & V_43 ) ;
T_1 V_44 , V_45 = F_1 ( V_2 , V_3 ) ;
T_2 V_26 , V_27 , V_28 , V_29 ;
struct V_30 V_25 ;
struct V_46 V_47 ;
V_44 = F_5 ( V_17 , type , V_7 , & V_26 , & V_27 , & V_28 , & V_29 , & V_25 ) ;
if ( ! V_44 )
return - V_48 ;
V_44 = F_11 ( V_17 , V_44 , 0 , V_40 , V_42 , & V_26 , & V_27 , & V_28 , & V_29 , & V_47 ) ;
if ( ! V_44 )
return - V_49 ;
F_3 ( V_2 , 0x61c118 + V_11 , 0x000000ff << V_45 , V_47 . V_50 << V_45 ) ;
F_3 ( V_2 , 0x61c120 + V_11 , 0x000000ff << V_45 , V_47 . V_51 << V_45 ) ;
F_3 ( V_2 , 0x61c130 + V_11 , 0x0000ff00 , V_47 . V_52 << 8 ) ;
F_3 ( V_2 , 0x61c13c + V_11 , 0x00000000 , 0x00000000 ) ;
return 0 ;
}
