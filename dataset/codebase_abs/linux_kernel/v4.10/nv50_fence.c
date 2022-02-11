static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_11 . V_10 ;
T_1 V_12 = V_10 -> V_12 * V_13 ;
T_1 V_14 = V_12 + V_10 -> V_15 - 1 ;
int V_16 ;
V_8 = V_2 -> V_6 = F_2 ( sizeof( * V_8 ) , V_17 ) ;
if ( ! V_8 )
return - V_18 ;
F_3 ( V_2 , & V_8 -> V_19 ) ;
V_8 -> V_19 . V_20 = V_21 ;
V_8 -> V_19 . V_22 = V_23 ;
V_8 -> V_19 . V_24 = V_25 ;
V_16 = F_4 (&chan->user, NvSema, NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_v0),
&fctx->sema) ;
if ( V_16 )
F_5 ( V_2 ) ;
return V_16 ;
}
int
F_6 ( struct V_26 * V_5 )
{
struct V_3 * V_4 ;
int V_16 = 0 ;
V_4 = V_5 -> V_6 = F_2 ( sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_4 -> V_19 . V_27 = V_28 ;
V_4 -> V_19 . V_29 = V_30 ;
V_4 -> V_19 . V_31 = F_1 ;
V_4 -> V_19 . V_32 = F_5 ;
V_4 -> V_19 . V_33 = 127 ;
V_4 -> V_19 . V_34 = F_7 ( V_4 -> V_19 . V_33 ) ;
F_8 ( & V_4 -> V_35 ) ;
V_16 = F_9 ( V_5 -> V_36 , 4096 , 0x1000 , V_37 ,
0 , 0x0000 , NULL , NULL , & V_4 -> V_11 ) ;
if ( ! V_16 ) {
V_16 = F_10 ( V_4 -> V_11 , V_37 , false ) ;
if ( ! V_16 ) {
V_16 = F_11 ( V_4 -> V_11 ) ;
if ( V_16 )
F_12 ( V_4 -> V_11 ) ;
}
if ( V_16 )
F_13 ( NULL , & V_4 -> V_11 ) ;
}
if ( V_16 ) {
V_28 ( V_5 ) ;
return V_16 ;
}
F_14 ( V_4 -> V_11 , 0x000 , 0x00000000 ) ;
return V_16 ;
}
