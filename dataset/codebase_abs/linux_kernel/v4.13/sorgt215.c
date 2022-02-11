void
F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_1 V_10 = F_2 ( V_2 ) ;
const T_1 V_11 = 0x80000000 | ( 0x00000001 * V_4 ) ;
const T_1 V_12 = 0x8000000d ;
F_3 ( V_6 , 0x61c1e0 + V_10 , V_12 , V_11 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c1e0 + soff) & 0x80000000))
break;
) ;
}
int
F_5 ( struct V_13 * V_7 , int V_14 )
{
return F_6 ( & V_15 , V_7 , V_14 ) ;
}
