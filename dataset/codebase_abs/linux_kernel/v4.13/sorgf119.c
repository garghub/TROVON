void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = V_3 * 0x800 ;
F_2 ( V_6 , 0x616610 + V_10 , 0x0800003f , 0x08000000 | V_4 ) ;
}
void
F_3 ( struct V_1 * V_2 , int V_3 , T_3 V_11 , T_2 V_12 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = V_3 * 0x800 ;
F_2 ( V_6 , 0x616620 + V_10 , 0x0000ffff , V_11 ) ;
F_2 ( V_6 , 0x616624 + V_10 , 0x00ffffff , V_12 ) ;
}
void
F_4 ( struct V_1 * V_2 , int V_3 , bool V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = 0x800 * V_3 ;
const T_2 V_14 = 0x80000000 | ( 0x00000001 * V_13 ) ;
const T_2 V_15 = 0x8000000d ;
F_2 ( V_6 , 0x616618 + V_10 , V_15 , V_14 ) ;
F_5 (device, 2000 ,
if (!(nvkm_rd32(device, 0x616618 + hoff) & 0x80000000))
break;
) ;
}
void
F_6 ( struct V_1 * V_2 , int V_3 ,
T_1 V_16 , T_1 V_17 , T_3 V_18 , T_3 V_19 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = V_3 * 0x800 ;
F_2 ( V_6 , 0x616588 + V_10 , 0x00003f3f , ( V_17 << 8 ) | V_16 ) ;
F_2 ( V_6 , 0x61658c + V_10 , 0xffffffff , ( V_19 << 16 ) | V_18 ) ;
}
void
F_7 ( struct V_1 * V_2 , int V_20 , int V_21 , int V_22 , int V_23 , int V_24 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_25 = F_8 ( V_2 ) ;
const T_2 V_26 = V_2 -> V_27 -> V_28 . V_29 [ V_20 ] * 8 ;
T_2 V_14 [ 4 ] ;
V_14 [ 0 ] = F_9 ( V_6 , 0x61c118 + V_25 ) & ~ ( 0x000000ff << V_26 ) ;
V_14 [ 1 ] = F_9 ( V_6 , 0x61c120 + V_25 ) & ~ ( 0x000000ff << V_26 ) ;
V_14 [ 2 ] = F_9 ( V_6 , 0x61c130 + V_25 ) ;
if ( ( V_14 [ 2 ] & 0x0000ff00 ) < ( V_24 << 8 ) || V_20 == 0 )
V_14 [ 2 ] = ( V_14 [ 2 ] & ~ 0x0000ff00 ) | ( V_24 << 8 ) ;
F_10 ( V_6 , 0x61c118 + V_25 , V_14 [ 0 ] | ( V_22 << V_26 ) ) ;
F_10 ( V_6 , 0x61c120 + V_25 , V_14 [ 1 ] | ( V_23 << V_26 ) ) ;
F_10 ( V_6 , 0x61c130 + V_25 , V_14 [ 2 ] ) ;
V_14 [ 3 ] = F_9 ( V_6 , 0x61c13c + V_25 ) & ~ ( 0x000000ff << V_26 ) ;
F_10 ( V_6 , 0x61c13c + V_25 , V_14 [ 3 ] | ( V_21 << V_26 ) ) ;
}
void
F_11 ( struct V_1 * V_2 , int V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_31 = F_12 ( V_2 ) ;
F_2 ( V_6 , 0x61c110 + V_31 , 0x0f0f0f0f , 0x01010101 * V_30 ) ;
}
int
F_13 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_31 = F_12 ( V_2 ) ;
const T_2 V_25 = F_8 ( V_2 ) ;
T_2 V_34 = 0x00000000 ;
T_2 V_35 = 0x00000000 ;
V_35 |= V_2 -> V_28 . V_36 << 18 ;
V_34 |= ( ( 1 << V_2 -> V_28 . V_37 ) - 1 ) << 16 ;
if ( V_2 -> V_28 . V_38 )
V_34 |= 0x40000000 ;
if ( V_2 -> V_28 . V_39 )
V_34 |= 0x00004000 ;
F_2 ( V_6 , 0x612300 + V_31 , 0x007c0000 , V_35 ) ;
F_2 ( V_6 , 0x61c10c + V_25 , 0x401f4000 , V_34 ) ;
return 0 ;
}
void
F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const int div = V_2 -> V_40 . V_41 == 3 ;
const T_2 V_31 = F_12 ( V_2 ) ;
if ( V_2 -> V_40 . V_42 == V_43 ) {
F_2 ( V_6 , 0x612300 + V_31 , 0x007c0000 , 0x0a << 18 ) ;
}
F_2 ( V_6 , 0x612300 + V_31 , 0x00000707 , ( div << 8 ) | div ) ;
}
void
F_15 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_46 = ( V_45 == & V_2 -> V_40 ) * 0x20000 + V_2 -> V_47 * 0x20 ;
T_2 V_48 = F_9 ( V_6 , 0x640200 + V_46 ) ;
V_45 -> V_49 = ( V_48 & 0x00000f00 ) >> 8 ;
switch ( V_45 -> V_49 ) {
case 0 : V_45 -> V_42 = V_50 ; V_45 -> V_41 = 1 ; break;
case 1 : V_45 -> V_42 = V_43 ; V_45 -> V_41 = 1 ; break;
case 2 : V_45 -> V_42 = V_43 ; V_45 -> V_41 = 2 ; break;
case 5 : V_45 -> V_42 = V_43 ; V_45 -> V_41 = 3 ; break;
case 8 : V_45 -> V_42 = V_51 ; V_45 -> V_41 = 1 ; break;
case 9 : V_45 -> V_42 = V_51 ; V_45 -> V_41 = 2 ; break;
default:
V_45 -> V_42 = V_52 ;
break;
}
V_45 -> V_3 = V_48 & 0x0000000f ;
}
int
F_16 ( const struct V_53 * V_27 , struct V_54 * V_7 , int V_47 )
{
struct V_5 * V_6 = V_7 -> V_8 . V_9 . V_6 ;
if ( ! ( F_9 ( V_6 , 0x612004 ) & ( 0x00000100 << V_47 ) ) )
return 0 ;
return F_17 ( V_27 , V_7 , V_55 , V_47 ) ;
}
int
F_18 ( struct V_54 * V_7 , int V_47 )
{
return F_16 ( & V_56 , V_7 , V_47 ) ;
}
