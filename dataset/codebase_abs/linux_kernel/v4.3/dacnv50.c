int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
const T_2 V_7 = V_8 -> V_9 * 0x800 ;
union {
struct V_10 V_11 ;
} * args = V_12 ;
T_2 V_13 ;
int V_14 ;
F_2 ( V_15 , L_1 , V_16 ) ;
if ( F_3 ( args -> V_11 , 0 , 0 , false ) ) {
F_2 ( V_15 , L_2
L_3 ,
args -> V_11 . V_17 , args -> V_11 . V_18 , args -> V_11 . V_12 ,
args -> V_11 . V_19 , args -> V_11 . V_20 ) ;
V_13 = 0x00000040 * ! args -> V_11 . V_18 ;
V_13 |= 0x00000010 * ! args -> V_11 . V_12 ;
V_13 |= 0x00000004 * ! args -> V_11 . V_19 ;
V_13 |= 0x00000001 * ! args -> V_11 . V_20 ;
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
struct V_21 * V_6 = & V_3 -> V_4 . V_5 . V_6 ;
struct V_1 * V_2 = V_6 -> V_2 ;
union {
struct V_22 V_11 ;
} * args = V_12 ;
const T_2 V_7 = V_8 -> V_9 * 0x800 ;
T_2 V_23 ;
int V_14 ;
F_2 ( V_15 , L_4 , V_16 ) ;
if ( F_3 ( args -> V_11 , 0 , 0 , false ) ) {
F_2 ( V_15 , L_5 ,
args -> V_11 . V_17 , args -> V_11 . V_12 ) ;
if ( args -> V_11 . V_12 & 0xfff00000 )
return - V_24 ;
V_23 = args -> V_11 . V_12 ;
} else
return V_14 ;
F_5 ( V_2 , 0x61a004 + V_7 , 0x807f0000 , 0x80150000 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61a004 + doff) & 0x80000000))
break;
) ;
F_7 ( V_2 , 0x61a00c + V_7 , 0x00100000 | V_23 ) ;
F_8 ( 9 ) ;
F_9 ( 500 ) ;
V_23 = F_5 ( V_2 , 0x61a00c + V_7 , 0xffffffff , 0x00000000 ) ;
F_5 ( V_2 , 0x61a004 + V_7 , 0x807f0000 , 0x80550000 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61a004 + doff) & 0x80000000))
break;
) ;
F_10 ( V_6 , L_6 , V_8 -> V_9 , V_23 ) ;
if ( ! ( V_23 & 0x80000000 ) )
return - V_25 ;
args -> V_11 . V_26 = ( V_23 & 0x38000000 ) >> 27 ;
return 0 ;
}
int
F_11 ( struct V_27 * V_3 , int V_28 ,
struct V_29 * V_30 , struct V_31 * * V_32 )
{
return F_12 ( & V_33 , V_3 ,
V_28 , V_30 , V_32 ) ;
}
