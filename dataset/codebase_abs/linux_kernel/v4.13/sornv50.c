void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const int div = V_2 -> V_8 . V_9 == 3 ;
const T_1 V_10 = F_2 ( V_2 ) ;
F_3 ( V_4 , 0x614300 + V_10 , 0x00000707 , ( div << 8 ) | div ) ;
}
static void
F_4 ( struct V_3 * V_4 , T_1 V_10 )
{
F_5 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c004 + soff) & 0x80000000))
break;
) ;
}
void
F_6 ( struct V_1 * V_2 , bool V_11 , bool V_12 ,
bool V_13 , bool V_14 , bool V_15 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_10 = F_2 ( V_2 ) ;
const T_1 V_16 = V_11 ? 0 : 16 ;
const T_1 V_17 = 0x80000000 | ( 0x00000001 * ! ! V_12 ) << V_16 ;
const T_1 V_18 = 0x80000000 | ( 0x00000001 << V_16 ) ;
F_4 ( V_4 , V_10 ) ;
F_3 ( V_4 , 0x61c004 + V_10 , V_18 , V_17 ) ;
F_4 ( V_4 , V_10 ) ;
F_5 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c030 + soff) & 0x10000000))
break;
) ;
}
void
F_7 ( struct V_1 * V_2 , struct V_19 * V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_4 ;
const T_1 V_20 = V_2 -> V_21 * 8 + ( V_17 == & V_2 -> V_22 ) * 4 ;
T_1 V_23 = F_8 ( V_4 , 0x610b70 + V_20 ) ;
V_17 -> V_24 = ( V_23 & 0x00000f00 ) >> 8 ;
switch ( V_17 -> V_24 ) {
case 0 : V_17 -> V_25 = V_26 ; V_17 -> V_9 = 1 ; break;
case 1 : V_17 -> V_25 = V_27 ; V_17 -> V_9 = 1 ; break;
case 2 : V_17 -> V_25 = V_27 ; V_17 -> V_9 = 2 ; break;
case 5 : V_17 -> V_25 = V_27 ; V_17 -> V_9 = 3 ; break;
default:
V_17 -> V_25 = V_28 ;
break;
}
V_17 -> V_29 = V_23 & 0x00000003 ;
}
int
F_9 ( const struct V_30 * V_31 , struct V_32 * V_5 , int V_21 )
{
struct V_3 * V_4 = V_5 -> V_6 . V_7 . V_4 ;
if ( ! ( F_8 ( V_4 , 0x610184 ) & ( 0x01000000 << V_21 ) ) )
return 0 ;
return F_10 ( V_31 , V_5 , V_33 , V_21 ) ;
}
int
F_11 ( struct V_32 * V_5 , int V_21 )
{
return F_9 ( & V_34 , V_5 , V_21 ) ;
}
