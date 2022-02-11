static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
struct V_7 * V_8 ;
struct V_9 * V_10 = & V_4 -> V_11 -> V_11 . V_12 ;
T_1 V_13 = V_10 -> V_13 * V_14 ;
T_1 V_15 = V_13 + V_10 -> V_16 - 1 ;
int V_17 ;
V_8 = V_2 -> V_6 = F_2 ( sizeof( * V_8 ) , V_18 ) ;
if ( ! V_8 )
return - V_19 ;
F_3 ( V_2 , & V_8 -> V_20 ) ;
V_8 -> V_20 . V_21 = V_22 ;
V_8 -> V_20 . V_23 = V_24 ;
V_8 -> V_20 . V_25 = V_26 ;
V_17 = F_4 (&chan->user, NvSema, NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_v0),
&fctx->sema) ;
if ( V_17 )
F_5 ( V_2 ) ;
return V_17 ;
}
int
F_6 ( struct V_27 * V_5 )
{
struct V_3 * V_4 ;
int V_17 = 0 ;
V_4 = V_5 -> V_6 = F_2 ( sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
V_4 -> V_20 . V_28 = V_29 ;
V_4 -> V_20 . V_30 = V_31 ;
V_4 -> V_20 . V_32 = F_1 ;
V_4 -> V_20 . V_33 = F_5 ;
V_4 -> V_20 . V_34 = 127 ;
V_4 -> V_20 . V_35 = F_7 ( V_4 -> V_20 . V_34 ) ;
F_8 ( & V_4 -> V_36 ) ;
V_17 = F_9 ( & V_5 -> V_37 , 4096 , 0x1000 , V_38 ,
0 , 0x0000 , NULL , NULL , & V_4 -> V_11 ) ;
if ( ! V_17 ) {
V_17 = F_10 ( V_4 -> V_11 , V_38 , false ) ;
if ( ! V_17 ) {
V_17 = F_11 ( V_4 -> V_11 ) ;
if ( V_17 )
F_12 ( V_4 -> V_11 ) ;
}
if ( V_17 )
F_13 ( NULL , & V_4 -> V_11 ) ;
}
if ( V_17 ) {
V_29 ( V_5 ) ;
return V_17 ;
}
F_14 ( V_4 -> V_11 , 0x000 , 0x00000000 ) ;
return V_17 ;
}
