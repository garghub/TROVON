static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_7 -> V_13 -> V_13 . V_12 ;
T_1 V_14 = V_12 -> V_14 * V_15 ;
T_1 V_16 = V_14 + V_12 -> V_17 - 1 ;
int V_18 , V_19 ;
V_10 = V_2 -> V_8 = F_2 ( sizeof( * V_10 ) , V_20 ) ;
if ( ! V_10 )
return - V_21 ;
F_3 ( V_2 , & V_10 -> V_22 ) ;
V_10 -> V_22 . V_23 = V_24 ;
V_10 -> V_22 . V_25 = V_26 ;
V_10 -> V_22 . V_27 = V_28 ;
V_18 = F_4 (chan->object, NULL, NvSema, NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_v0),
&fctx->sema) ;
for ( V_19 = 0 ; ! V_18 && V_19 < V_4 -> V_29 . V_30 ; V_19 ++ ) {
struct V_31 * V_13 = F_5 ( V_4 , V_19 ) ;
T_1 V_14 = V_13 -> V_13 . V_12 . V_14 * V_15 ;
T_1 V_16 = V_14 + V_13 -> V_13 . V_12 . V_17 - 1 ;
V_18 = F_4 (chan->object, NULL, NvEvoSema0 + i,
NV_DMA_IN_MEMORY, &(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_v0),
&fctx->head[i]) ;
}
if ( V_18 )
F_6 ( V_2 ) ;
return V_18 ;
}
int
F_7 ( struct V_32 * V_5 )
{
struct V_6 * V_7 ;
int V_18 = 0 ;
V_7 = V_5 -> V_8 = F_2 ( sizeof( * V_7 ) , V_20 ) ;
if ( ! V_7 )
return - V_21 ;
V_7 -> V_22 . V_33 = V_34 ;
V_7 -> V_22 . V_35 = V_36 ;
V_7 -> V_22 . V_37 = F_1 ;
V_7 -> V_22 . V_38 = F_6 ;
V_7 -> V_22 . V_39 = 127 ;
V_7 -> V_22 . V_40 = F_8 ( V_7 -> V_22 . V_39 ) ;
F_9 ( & V_7 -> V_41 ) ;
V_18 = F_10 ( V_5 -> V_4 , 4096 , 0x1000 , V_42 ,
0 , 0x0000 , NULL , NULL , & V_7 -> V_13 ) ;
if ( ! V_18 ) {
V_18 = F_11 ( V_7 -> V_13 , V_42 ) ;
if ( ! V_18 ) {
V_18 = F_12 ( V_7 -> V_13 ) ;
if ( V_18 )
F_13 ( V_7 -> V_13 ) ;
}
if ( V_18 )
F_14 ( NULL , & V_7 -> V_13 ) ;
}
if ( V_18 ) {
V_34 ( V_5 ) ;
return V_18 ;
}
F_15 ( V_7 -> V_13 , 0x000 , 0x00000000 ) ;
return V_18 ;
}
