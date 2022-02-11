int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
union {
struct V_7 V_8 ;
} * args = V_9 ;
const T_2 V_10 = V_11 -> V_12 * 0x800 ;
T_2 V_13 ;
int V_14 = - V_15 ;
F_2 ( V_16 , L_1 , V_17 ) ;
if ( ! ( V_14 = F_3 ( V_14 , & V_9 , & V_17 , args -> V_8 , 0 , 0 , false ) ) ) {
F_2 ( V_16 , L_2 ,
args -> V_8 . V_18 , args -> V_8 . V_19 ) ;
V_13 = ! ! args -> V_8 . V_19 ;
} else
return V_14 ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c004 + soff) & 0x80000000))
break;
) ;
F_5 ( V_2 , 0x61c004 + V_10 , 0x80000001 , 0x80000000 | V_13 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c004 + soff) & 0x80000000))
break;
) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c030 + soff) & 0x10000000))
break;
) ;
return 0 ;
}
int
F_6 ( struct V_20 * V_3 , int V_21 ,
struct V_22 * V_23 , struct V_24 * * V_25 )
{
return F_7 ( & V_26 , V_3 ,
V_21 , V_23 , V_25 ) ;
}
