int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_3 * V_5 )
{
struct V_6 * V_7 = ( void * ) F_2 ( & V_4 -> V_8 -> V_9 ) ;
struct V_10 * V_11 = V_5 -> V_12 -> V_2 ;
struct V_13 * V_14 = V_5 -> V_2 ;
T_1 V_15 ;
int V_16 ;
if ( ! F_3 ( & V_7 -> V_17 ) )
return - V_18 ;
F_4 ( & V_11 -> V_19 ) ;
V_15 = V_11 -> V_20 ;
V_11 -> V_20 += 2 ;
F_5 ( & V_11 -> V_19 ) ;
V_16 = F_6 ( V_4 , 5 ) ;
if ( ! V_16 ) {
F_7 ( V_4 , 0 , V_21 , 4 ) ;
F_8 ( V_4 , V_14 -> V_22 . V_23 ) ;
F_8 ( V_4 , 0 ) ;
F_8 ( V_4 , V_15 + 0 ) ;
F_8 ( V_4 , V_15 + 1 ) ;
F_9 ( V_4 ) ;
}
if ( ! V_16 && ! ( V_16 = F_6 ( V_5 , 5 ) ) ) {
F_7 ( V_5 , 0 , V_21 , 4 ) ;
F_8 ( V_5 , V_14 -> V_22 . V_23 ) ;
F_8 ( V_5 , 0 ) ;
F_8 ( V_5 , V_15 + 1 ) ;
F_8 ( V_5 , V_15 + 2 ) ;
F_9 ( V_5 ) ;
}
F_10 ( & V_7 -> V_17 ) ;
return 0 ;
}
static int
F_11 ( struct V_3 * V_5 )
{
struct V_10 * V_11 = V_5 -> V_12 -> V_2 ;
struct V_13 * V_14 ;
struct V_24 * V_25 = & V_11 -> V_26 -> V_26 . V_25 ;
T_1 V_27 = V_25 -> V_27 * V_28 ;
T_1 V_29 = V_27 + V_25 -> V_30 - 1 ;
int V_16 = 0 ;
V_14 = V_5 -> V_2 = F_12 ( sizeof( * V_14 ) , V_31 ) ;
if ( ! V_14 )
return - V_32 ;
F_13 ( V_5 , & V_14 -> V_9 ) ;
V_14 -> V_9 . V_33 = V_34 ;
V_14 -> V_9 . V_35 = V_36 ;
V_14 -> V_9 . V_37 = F_1 ;
V_16 = F_14 (chan->object, NULL, NvSema, NV_DMA_FROM_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_v0),
&fctx->sema) ;
if ( V_16 )
F_15 ( V_5 ) ;
return V_16 ;
}
void
F_16 ( struct V_38 * V_12 )
{
struct V_10 * V_11 = V_12 -> V_2 ;
F_17 ( V_11 -> V_26 , 0 , V_11 -> V_20 ) ;
}
int
F_18 ( struct V_38 * V_12 )
{
struct V_10 * V_11 ;
int V_16 = 0 ;
V_11 = V_12 -> V_2 = F_12 ( sizeof( * V_11 ) , V_31 ) ;
if ( ! V_11 )
return - V_32 ;
V_11 -> V_9 . V_39 = V_40 ;
V_11 -> V_9 . V_41 = F_16 ;
V_11 -> V_9 . V_42 = F_11 ;
V_11 -> V_9 . V_43 = F_15 ;
V_11 -> V_9 . V_44 = 31 ;
V_11 -> V_9 . V_45 = F_19 ( V_11 -> V_9 . V_44 ) ;
F_20 ( & V_11 -> V_19 ) ;
V_16 = F_21 ( V_12 -> V_46 , 4096 , 0x1000 , V_47 ,
0 , 0x0000 , NULL , NULL , & V_11 -> V_26 ) ;
if ( ! V_16 ) {
V_16 = F_22 ( V_11 -> V_26 , V_47 ) ;
if ( ! V_16 ) {
V_16 = F_23 ( V_11 -> V_26 ) ;
if ( V_16 )
F_24 ( V_11 -> V_26 ) ;
}
if ( V_16 )
F_25 ( NULL , & V_11 -> V_26 ) ;
}
if ( V_16 ) {
V_40 ( V_12 ) ;
return V_16 ;
}
F_17 ( V_11 -> V_26 , 0x000 , 0x00000000 ) ;
return V_16 ;
}
