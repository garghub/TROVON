int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
const T_2 V_7 = V_8 -> V_9 * 0x800 ;
union {
struct V_10 V_11 ;
} * args = V_12 ;
T_2 V_13 ;
int V_14 = - V_15 ;
F_2 ( V_16 , L_1 , V_17 ) ;
if ( ! ( V_14 = F_3 ( V_14 , & V_12 , & V_17 , args -> V_11 , 0 , 0 , false ) ) ) {
F_2 ( V_16 , L_2
L_3 ,
args -> V_11 . V_18 , args -> V_11 . V_19 , args -> V_11 . V_12 ,
args -> V_11 . V_20 , args -> V_11 . V_21 ) ;
V_13 = 0x00000040 * ! args -> V_11 . V_19 ;
V_13 |= 0x00000010 * ! args -> V_11 . V_12 ;
V_13 |= 0x00000004 * ! args -> V_11 . V_20 ;
V_13 |= 0x00000001 * ! args -> V_11 . V_21 ;
} else
return V_14 ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61a004 + doff) & 0x80000000))
break;
) ;
F_5 ( V_2 , 0x61a004 + V_7 , 0xc000007f , 0x80000000 | V_13 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61a004 + doff) & 0x80000000))
break;
) ;
return 0 ;
}
int
F_6 ( T_1 )
{
struct V_22 * V_6 = & V_3 -> V_4 . V_5 . V_6 ;
struct V_1 * V_2 = V_6 -> V_2 ;
union {
struct V_23 V_11 ;
} * args = V_12 ;
const T_2 V_7 = V_8 -> V_9 * 0x800 ;
T_2 V_24 ;
int V_14 = - V_15 ;
F_2 ( V_16 , L_4 , V_17 ) ;
if ( ! ( V_14 = F_3 ( V_14 , & V_12 , & V_17 , args -> V_11 , 0 , 0 , false ) ) ) {
F_2 ( V_16 , L_5 ,
args -> V_11 . V_18 , args -> V_11 . V_12 ) ;
if ( args -> V_11 . V_12 & 0xfff00000 )
return - V_25 ;
V_24 = args -> V_11 . V_12 ;
} else
return V_14 ;
F_5 ( V_2 , 0x61a004 + V_7 , 0x807f0000 , 0x80150000 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61a004 + doff) & 0x80000000))
break;
) ;
F_7 ( V_2 , 0x61a00c + V_7 , 0x00100000 | V_24 ) ;
F_8 ( 9 ) ;
F_9 ( 500 ) ;
V_24 = F_5 ( V_2 , 0x61a00c + V_7 , 0xffffffff , 0x00000000 ) ;
F_5 ( V_2 , 0x61a004 + V_7 , 0x807f0000 , 0x80550000 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61a004 + doff) & 0x80000000))
break;
) ;
F_10 ( V_6 , L_6 , V_8 -> V_9 , V_24 ) ;
if ( ! ( V_24 & 0x80000000 ) )
return - V_26 ;
args -> V_11 . V_27 = ( V_24 & 0x38000000 ) >> 27 ;
return 0 ;
}
int
F_11 ( struct V_28 * V_3 , int V_29 ,
struct V_30 * V_31 , struct V_32 * * V_33 )
{
return F_12 ( & V_34 , V_3 ,
V_29 , V_31 , V_33 ) ;
}
