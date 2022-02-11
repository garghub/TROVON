void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 . V_7 . V_8 . V_4 ;
F_2 ( V_4 , 0x6100b0 , 0x00000000 ) ;
}
int
F_3 ( struct V_1 * V_2 )
{
struct V_9 * V_5 = V_2 -> V_5 ;
struct V_10 * V_11 ;
struct V_3 * V_4 = V_5 -> V_6 . V_7 . V_8 . V_4 ;
T_1 V_12 ;
int V_13 ;
F_4 (head, &disp->base.head, head) {
const T_1 V_14 = V_11 -> V_15 * 0x800 ;
V_12 = F_5 ( V_4 , 0x616104 + V_14 ) ;
F_2 ( V_4 , 0x6101b4 + V_14 , V_12 ) ;
V_12 = F_5 ( V_4 , 0x616108 + V_14 ) ;
F_2 ( V_4 , 0x6101b8 + V_14 , V_12 ) ;
V_12 = F_5 ( V_4 , 0x61610c + V_14 ) ;
F_2 ( V_4 , 0x6101bc + V_14 , V_12 ) ;
}
for ( V_13 = 0 ; V_13 < V_5 -> V_16 -> V_17 . V_18 ; V_13 ++ ) {
V_12 = F_5 ( V_4 , 0x61a000 + ( V_13 * 0x800 ) ) ;
F_2 ( V_4 , 0x6101c0 + ( V_13 * 0x800 ) , V_12 ) ;
}
for ( V_13 = 0 ; V_13 < V_5 -> V_16 -> V_19 . V_18 ; V_13 ++ ) {
V_12 = F_5 ( V_4 , 0x61c000 + ( V_13 * 0x800 ) ) ;
F_2 ( V_4 , 0x6301c4 + ( V_13 * 0x800 ) , V_12 ) ;
}
if ( F_5 ( V_4 , 0x6100ac ) & 0x00000100 ) {
F_2 ( V_4 , 0x6100ac , 0x00000100 ) ;
F_6 ( V_4 , 0x6194e8 , 0x00000001 , 0x00000000 ) ;
if ( F_7 (device, 2000 ,
if (!(nvkm_rd32(device, 0x6194e8) & 0x00000002))
break;
) < 0 )
return - V_20 ;
}
F_2 ( V_4 , 0x610010 , ( V_2 -> V_21 -> V_22 >> 8 ) | 9 ) ;
F_2 ( V_4 , 0x610090 , 0x00000000 ) ;
F_2 ( V_4 , 0x6100a0 , 0x00000000 ) ;
F_2 ( V_4 , 0x6100b0 , 0x00000307 ) ;
F_4 (head, &disp->base.head, head) {
const T_1 V_14 = V_11 -> V_15 * 0x800 ;
F_6 ( V_4 , 0x616308 + V_14 , 0x00000111 , 0x00000010 ) ;
}
return 0 ;
}
static int
F_8 ( struct V_23 * V_5 , const struct V_24 * V_25 ,
void * V_26 , T_1 V_27 , struct V_28 * * V_29 )
{
return F_9 ( & V_30 , V_5 , V_25 ,
V_26 , V_27 , V_29 ) ;
}
