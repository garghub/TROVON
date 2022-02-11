static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 . V_7 ;
struct V_10 * V_11 = V_7 -> V_11 ;
int V_12 = V_2 -> V_13 . V_12 ;
int V_14 = V_2 -> V_13 . V_14 ;
F_2 ( V_11 , 0x610200 + ( V_12 * 0x10 ) , 0x00000001 , 0x00000000 ) ;
if ( F_3 (device, 2000 ,
if (!(nvkm_rd32(device, 0x610200 + (ctrl * 0x10)) & 0x00030000))
break;
) < 0 ) {
F_4 ( V_7 , L_1 , V_14 ,
F_5 ( V_11 , 0x610200 + ( V_12 * 0x10 ) ) ) ;
}
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 . V_7 ;
struct V_10 * V_11 = V_7 -> V_11 ;
int V_12 = V_2 -> V_13 . V_12 ;
int V_14 = V_2 -> V_13 . V_14 ;
F_7 ( V_11 , 0x610200 + ( V_12 * 0x10 ) , 0x00002000 ) ;
if ( F_3 (device, 2000 ,
if (!(nvkm_rd32(device, 0x610200 + (ctrl * 0x10)) & 0x00030000))
break;
) < 0 ) {
F_4 ( V_7 , L_2 , V_14 ,
F_5 ( V_11 , 0x610200 + ( V_12 * 0x10 ) ) ) ;
return - V_15 ;
}
F_7 ( V_11 , 0x610200 + ( V_12 * 0x10 ) , 0x00000001 ) ;
if ( F_3 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x610200 + (ctrl * 0x10));
if ((tmp & 0x00030000) == 0x00010000)
break;
) < 0 ) {
F_4 ( V_7 , L_3 , V_14 ,
F_5 ( V_11 , 0x610200 + ( V_12 * 0x10 ) ) ) ;
return - V_15 ;
}
return 0 ;
}
