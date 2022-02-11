static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 = V_2 -> V_5 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 = & V_7 -> V_13 -> V_13 . V_12 ;
struct V_14 * V_15 ;
T_1 V_16 = V_12 -> V_16 * V_17 ;
T_1 V_18 = V_16 + V_12 -> V_19 - 1 ;
int V_20 , V_21 ;
V_10 = V_2 -> V_8 = F_2 ( sizeof( * V_10 ) , V_22 ) ;
if ( ! V_10 )
return - V_23 ;
F_3 ( & V_10 -> V_24 ) ;
V_10 -> V_24 . V_25 = V_26 ;
V_10 -> V_24 . V_27 = V_28 ;
V_10 -> V_24 . V_29 = V_30 ;
V_20 = F_4 (nv_object(chan->cli), chan->handle,
NvSema, 0x003d ,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_class),
&object) ;
for ( V_21 = 0 ; ! V_20 && V_21 < V_4 -> V_31 . V_32 ; V_21 ++ ) {
struct V_33 * V_13 = F_5 ( V_4 , V_21 ) ;
T_1 V_16 = V_13 -> V_13 . V_12 . V_16 * V_17 ;
T_1 V_18 = V_16 + V_13 -> V_13 . V_12 . V_19 - 1 ;
V_20 = F_4 (nv_object(chan->cli), chan->handle,
NvEvoSema0 + i, 0x003d ,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_class),
&object) ;
}
if ( V_20 )
F_6 ( V_2 ) ;
return V_20 ;
}
int
F_7 ( struct V_34 * V_5 )
{
struct V_6 * V_7 ;
int V_20 = 0 ;
V_7 = V_5 -> V_8 = F_2 ( sizeof( * V_7 ) , V_22 ) ;
if ( ! V_7 )
return - V_23 ;
V_7 -> V_24 . V_35 = V_36 ;
V_7 -> V_24 . V_37 = V_38 ;
V_7 -> V_24 . V_39 = F_1 ;
V_7 -> V_24 . V_40 = F_6 ;
F_8 ( & V_7 -> V_41 ) ;
V_20 = F_9 ( V_5 -> V_4 , 4096 , 0x1000 , V_42 ,
0 , 0x0000 , NULL , & V_7 -> V_13 ) ;
if ( ! V_20 ) {
V_20 = F_10 ( V_7 -> V_13 , V_42 ) ;
if ( ! V_20 ) {
V_20 = F_11 ( V_7 -> V_13 ) ;
if ( V_20 )
F_12 ( V_7 -> V_13 ) ;
}
if ( V_20 )
F_13 ( NULL , & V_7 -> V_13 ) ;
}
if ( V_20 ) {
V_36 ( V_5 ) ;
return V_20 ;
}
F_14 ( V_7 -> V_13 , 0x000 , 0x00000000 ) ;
return V_20 ;
}
