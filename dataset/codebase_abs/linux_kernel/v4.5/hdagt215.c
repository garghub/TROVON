int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
union {
struct V_7 V_8 ;
} * args = V_9 ;
const T_2 V_10 = V_11 -> V_12 * 0x800 ;
int V_13 = - V_14 , V_15 ;
F_2 ( V_16 , L_1 , V_17 ) ;
if ( ! ( V_13 = F_3 ( V_13 , & V_9 , & V_17 , args -> V_8 , 0 , 0 , true ) ) ) {
F_2 ( V_16 , L_2 ,
args -> V_8 . V_18 ) ;
if ( V_17 > 0x60 )
return - V_19 ;
} else
return V_13 ;
if ( V_17 && args -> V_8 . V_9 [ 0 ] ) {
if ( V_11 -> V_20 . type == V_21 ) {
F_4 ( V_2 , 0x61c1e0 + V_10 , 0x8000000d , 0x80000001 ) ;
F_5 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x61c1e0 + soff);
if (!(tmp & 0x80000000))
break;
) ;
}
for ( V_15 = 0 ; V_15 < V_17 ; V_15 ++ )
F_6 ( V_2 , 0x61c440 + V_10 , ( V_15 << 8 ) | args -> V_8 . V_9 [ 0 ] ) ;
for (; V_15 < 0x60 ; V_15 ++ )
F_6 ( V_2 , 0x61c440 + V_10 , ( V_15 << 8 ) ) ;
F_4 ( V_2 , 0x61c448 + V_10 , 0x80000003 , 0x80000003 ) ;
} else {
if ( V_11 -> V_20 . type == V_21 ) {
F_4 ( V_2 , 0x61c1e0 + V_10 , 0x80000001 , 0x80000000 ) ;
F_5 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x61c1e0 + soff);
if (!(tmp & 0x80000000))
break;
) ;
}
F_4 ( V_2 , 0x61c448 + V_10 , 0x80000003 , 0x80000000 | ! ! V_17 ) ;
}
return 0 ;
}
