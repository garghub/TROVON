static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = ( void * ) V_4 -> V_8 ;
int V_9 = F_2 ( V_4 , 7 ) ;
if ( V_9 == 0 ) {
F_3 ( V_4 , 0 , V_10 , 1 ) ;
F_4 ( V_4 , V_11 ) ;
F_3 ( V_4 , 0 , V_12 , 4 ) ;
F_4 ( V_4 , F_5 ( V_7 -> V_13 * 16 ) ) ;
F_4 ( V_4 , F_6 ( V_7 -> V_13 * 16 ) ) ;
F_4 ( V_4 , V_2 -> V_14 ) ;
F_4 ( V_4 , V_15 ) ;
F_7 ( V_4 ) ;
}
return V_9 ;
}
static int
F_8 ( struct V_1 * V_2 ,
struct V_3 * V_16 , struct V_3 * V_4 )
{
struct V_6 * V_7 = ( void * ) V_16 -> V_8 ;
int V_9 = F_2 ( V_4 , 7 ) ;
if ( V_9 == 0 ) {
F_3 ( V_4 , 0 , V_10 , 1 ) ;
F_4 ( V_4 , V_11 ) ;
F_3 ( V_4 , 0 , V_12 , 4 ) ;
F_4 ( V_4 , F_5 ( V_7 -> V_13 * 16 ) ) ;
F_4 ( V_4 , F_6 ( V_7 -> V_13 * 16 ) ) ;
F_4 ( V_4 , V_2 -> V_14 ) ;
F_4 ( V_4 , V_17 ) ;
F_7 ( V_4 ) ;
}
return V_9 ;
}
static T_1
F_9 ( struct V_3 * V_4 )
{
struct V_6 * V_7 = ( void * ) V_4 -> V_8 ;
struct V_18 * V_19 = V_4 -> V_20 -> V_2 ;
return F_10 ( V_19 -> V_21 , V_7 -> V_13 * 16 ) ;
}
static void
F_11 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_2 ;
F_12 ( & V_23 -> V_24 ) ;
V_4 -> V_2 = NULL ;
F_13 ( V_23 ) ;
}
static int
F_14 ( struct V_3 * V_4 )
{
struct V_25 * V_26 = V_4 -> V_20 -> V_26 ;
struct V_6 * V_7 = ( void * ) V_4 -> V_8 ;
struct V_18 * V_19 = V_4 -> V_20 -> V_2 ;
struct V_22 * V_23 ;
struct V_27 * V_8 ;
int V_9 , V_28 ;
V_23 = V_4 -> V_2 = F_15 ( sizeof( * V_23 ) , V_29 ) ;
if ( ! V_23 )
return - V_30 ;
F_16 ( & V_23 -> V_24 ) ;
V_9 = F_17 (nv_object(chan->cli), chan->handle,
NvSema, 0x0002 ,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = priv->mem->addr,
.limit = priv->mem->addr +
priv->mem->size - 1 ,
}, sizeof(struct nv_dma_class),
&object) ;
for ( V_28 = 0 ; ! V_9 && V_28 < V_26 -> V_31 . V_32 ; V_28 ++ ) {
struct V_33 * V_34 = F_18 ( V_26 , V_28 ) ;
V_9 = F_17 (nv_object(chan->cli), chan->handle,
NvEvoSema0 + i, 0x003d ,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = bo->bo.offset,
.limit = bo->bo.offset + 0xfff ,
}, sizeof(struct nv_dma_class),
&object) ;
}
if ( V_9 )
F_11 ( V_4 ) ;
F_19 ( V_19 -> V_21 , V_7 -> V_13 * 16 , 0x00000000 ) ;
return V_9 ;
}
static void
F_20 ( struct V_35 * V_20 )
{
struct V_18 * V_19 = V_20 -> V_2 ;
F_21 ( NULL , & V_19 -> V_21 ) ;
V_20 -> V_2 = NULL ;
F_13 ( V_19 ) ;
}
int
F_22 ( struct V_35 * V_20 )
{
struct V_36 * V_37 = V_36 ( V_20 -> V_38 ) ;
struct V_18 * V_19 ;
T_1 V_4 = V_37 -> V_39 + 1 ;
int V_9 ;
V_19 = V_20 -> V_2 = F_15 ( sizeof( * V_19 ) , V_29 ) ;
if ( ! V_19 )
return - V_30 ;
V_19 -> V_24 . V_40 = F_20 ;
V_19 -> V_24 . V_41 = F_14 ;
V_19 -> V_24 . V_42 = F_11 ;
V_19 -> V_24 . V_43 = F_1 ;
V_19 -> V_24 . V_44 = F_8 ;
V_19 -> V_24 . V_45 = F_9 ;
V_9 = F_23 ( V_20 -> V_38 , NULL , V_4 * 16 , 0x1000 , 0 ,
& V_19 -> V_21 ) ;
if ( V_9 )
F_20 ( V_20 ) ;
return V_9 ;
}
