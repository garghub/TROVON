static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = F_2 ( V_2 ) ;
F_3 ( V_4 , 0x614380 + V_8 , 0x00000707 , 0x00000001 ) ;
}
static int
F_4 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
int V_11 = F_5 ( V_10 , V_2 -> V_12 . V_13 , V_2 -> V_12 . V_14 ,
V_2 -> V_12 . V_15 ) ;
if ( V_11 )
return V_11 ;
return 1 ;
}
static void
F_6 ( struct V_3 * V_4 , T_1 V_8 )
{
F_7 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61e004 + poff) & 0x80000000))
break;
) ;
}
static void
F_8 ( struct V_1 * V_2 , bool V_16 , bool V_17 ,
bool V_18 , bool V_19 , bool V_20 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_8 = F_2 ( V_2 ) ;
const T_1 V_21 = V_16 ? 0 : 16 ;
const T_1 V_22 = 0x80000000 | ( 0x00000001 * ! ! V_17 ) << V_21 ;
const T_1 V_23 = 0x80000000 | ( 0x00000101 << V_21 ) ;
F_6 ( V_4 , V_8 ) ;
F_3 ( V_4 , 0x61e004 + V_8 , V_23 , V_22 ) ;
F_6 ( V_4 , V_8 ) ;
}
void
F_9 ( struct V_1 * V_24 , struct V_25 * V_22 , T_1 V_26 )
{
if ( V_22 -> V_27 && V_22 == & V_24 -> V_28 ) {
struct V_29 * V_27 =
F_10 ( V_24 -> V_5 , F_11 ( V_22 -> V_27 ) ) ;
if ( ! F_12 ( ! V_27 ) ) {
struct V_30 * V_22 = & V_27 -> V_28 ;
switch ( ( V_26 & 0x000f0000 ) >> 16 ) {
case 6 : V_22 -> V_31 . V_32 = 30 ; break;
case 5 : V_22 -> V_31 . V_32 = 24 ; break;
case 2 : V_22 -> V_31 . V_32 = 18 ; break;
case 0 : V_22 -> V_31 . V_32 = 18 ; break;
default:
V_22 -> V_31 . V_32 = 18 ;
F_12 ( 1 ) ;
break;
}
}
}
}
static void
F_13 ( struct V_1 * V_2 , struct V_25 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_33 = V_2 -> V_34 * 8 + ( V_22 == & V_2 -> V_35 ) * 4 ;
T_1 V_26 = F_14 ( V_4 , 0x610b80 + V_33 ) ;
V_22 -> V_36 = ( V_26 & 0x00000f00 ) >> 8 ;
V_22 -> V_37 = 1 ;
switch ( V_22 -> V_36 ) {
case 0 : V_22 -> V_38 = V_39 ; break;
default:
V_22 -> V_38 = V_40 ;
break;
}
V_22 -> V_27 = V_26 & 0x00000003 ;
F_9 ( V_2 , V_22 , V_26 ) ;
}
int
F_15 ( struct V_41 * V_5 , int V_34 )
{
struct V_3 * V_4 = V_5 -> V_6 . V_7 . V_4 ;
if ( ! ( F_14 ( V_4 , 0x610184 ) & ( 0x10000000 << V_34 ) ) )
return 0 ;
return F_16 ( & V_42 , V_5 , V_43 , V_34 ) ;
}
