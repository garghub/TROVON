int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
union {
struct V_7 V_8 ;
} * args = V_9 ;
const T_2 V_10 = V_11 -> V_12 * 0x030 ;
const T_2 V_13 = V_14 * 0x800 ;
int V_15 = - V_16 , V_17 ;
F_2 ( V_18 , L_1 , V_19 ) ;
if ( ! ( V_15 = F_3 ( V_15 , & V_9 , & V_19 , args -> V_8 , 0 , 0 , true ) ) ) {
F_2 ( V_18 , L_2 ,
args -> V_8 . V_20 ) ;
if ( V_19 > 0x60 )
return - V_21 ;
} else
return V_15 ;
if ( V_19 && args -> V_8 . V_9 [ 0 ] ) {
if ( V_11 -> V_22 . type == V_23 ) {
F_4 ( V_2 , 0x616618 + V_13 , 0x8000000c , 0x80000001 ) ;
F_5 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x616618 + hoff);
if (!(tmp & 0x80000000))
break;
) ;
}
F_4 ( V_2 , 0x616548 + V_13 , 0x00000070 , 0x00000000 ) ;
for ( V_17 = 0 ; V_17 < V_19 ; V_17 ++ )
F_6 ( V_2 , 0x10ec00 + V_10 , ( V_17 << 8 ) | args -> V_8 . V_9 [ V_17 ] ) ;
for (; V_17 < 0x60 ; V_17 ++ )
F_6 ( V_2 , 0x10ec00 + V_10 , ( V_17 << 8 ) ) ;
F_4 ( V_2 , 0x10ec10 + V_10 , 0x80000003 , 0x80000003 ) ;
} else {
if ( V_11 -> V_22 . type == V_23 ) {
F_4 ( V_2 , 0x616618 + V_13 , 0x80000001 , 0x80000000 ) ;
F_5 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x616618 + hoff);
if (!(tmp & 0x80000000))
break;
) ;
}
F_4 ( V_2 , 0x10ec10 + V_10 , 0x80000003 , 0x80000000 | ! ! V_19 ) ;
}
return 0 ;
}
