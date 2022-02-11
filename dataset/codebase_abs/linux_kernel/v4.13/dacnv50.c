static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = F_2 ( V_2 ) ;
F_3 ( V_4 , 0x614280 + V_8 , 0x07070707 , 0x00000000 ) ;
}
int
F_4 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = F_2 ( V_2 ) ;
V_2 -> V_10 -> V_11 ( V_2 , false , true , false , false , false ) ;
F_5 ( V_4 , 0x61a00c + V_8 , 0x00100000 | V_9 ) ;
F_6 ( 9 ) ;
F_7 ( 500 ) ;
V_9 = F_3 ( V_4 , 0x61a00c + V_8 , 0xffffffff , 0x00000000 ) ;
V_2 -> V_10 -> V_11 ( V_2 , false , false , false , false , false ) ;
if ( ! ( V_9 & 0x80000000 ) )
return - V_12 ;
return ( V_9 & 0x38000000 ) >> 27 ;
}
static void
F_8 ( struct V_3 * V_4 , const T_1 V_8 )
{
F_9 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61a004 + doff) & 0x80000000))
break;
) ;
}
void
F_10 ( struct V_1 * V_2 , bool V_13 , bool V_14 ,
bool V_15 , bool V_16 , bool V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = F_2 ( V_2 ) ;
const T_1 V_18 = V_13 ? 0 : 16 ;
const T_1 V_19 = 0x80000000 | ( 0x00000040 * ! V_14 |
0x00000010 * ! V_15 |
0x00000004 * ! V_16 |
0x00000001 * ! V_17 ) << V_18 ;
const T_1 V_20 = 0xc0000000 | ( 0x00000055 << V_18 ) ;
F_8 ( V_4 , V_8 ) ;
F_3 ( V_4 , 0x61a004 + V_8 , V_20 , V_19 ) ;
F_8 ( V_4 , V_8 ) ;
}
static void
F_11 ( struct V_1 * V_2 , struct V_21 * V_19 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_22 = V_2 -> V_23 * 8 + ( V_19 == & V_2 -> V_24 ) * 4 ;
T_1 V_25 = F_12 ( V_4 , 0x610b58 + V_22 ) ;
V_19 -> V_26 = ( V_25 & 0x00000f00 ) >> 8 ;
switch ( V_19 -> V_26 ) {
case 0 : V_19 -> V_27 = V_28 ; break;
default:
V_19 -> V_27 = V_29 ;
break;
}
V_19 -> V_30 = V_25 & 0x00000003 ;
}
int
F_13 ( struct V_31 * V_5 , int V_23 )
{
struct V_3 * V_4 = V_5 -> V_6 . V_7 . V_4 ;
if ( ! ( F_12 ( V_4 , 0x610184 ) & ( 0x00100000 << V_23 ) ) )
return 0 ;
return F_14 ( & V_32 , V_5 , V_33 , V_23 ) ;
}
