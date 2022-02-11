int
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_3 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_2 ;
T_1 V_9 ;
int V_10 ;
if ( ! F_2 ( & V_4 -> V_11 -> V_12 ) )
return - V_13 ;
F_3 ( & V_7 -> V_14 ) ;
V_9 = V_7 -> V_15 ;
V_7 -> V_15 += 2 ;
F_4 ( & V_7 -> V_14 ) ;
V_10 = F_5 ( V_4 , 5 ) ;
if ( ! V_10 ) {
F_6 ( V_4 , 0 , V_16 , 4 ) ;
F_7 ( V_4 , V_17 ) ;
F_7 ( V_4 , 0 ) ;
F_7 ( V_4 , V_9 + 0 ) ;
F_7 ( V_4 , V_9 + 1 ) ;
F_8 ( V_4 ) ;
}
if ( ! V_10 && ! ( V_10 = F_5 ( V_5 , 5 ) ) ) {
F_6 ( V_5 , 0 , V_16 , 4 ) ;
F_7 ( V_5 , V_17 ) ;
F_7 ( V_5 , 0 ) ;
F_7 ( V_5 , V_9 + 1 ) ;
F_7 ( V_5 , V_9 + 2 ) ;
F_8 ( V_5 ) ;
}
F_9 ( & V_4 -> V_11 -> V_12 ) ;
return 0 ;
}
static int
F_10 ( struct V_3 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_2 ;
struct V_18 * V_19 ;
struct V_20 * V_21 = & V_7 -> V_22 -> V_22 . V_21 ;
struct V_23 * V_24 ;
T_1 V_25 = V_21 -> V_25 * V_26 ;
T_1 V_27 = V_25 + V_21 -> V_28 - 1 ;
int V_10 = 0 ;
V_19 = V_5 -> V_2 = F_11 ( sizeof( * V_19 ) , V_29 ) ;
if ( ! V_19 )
return - V_30 ;
F_12 ( & V_19 -> V_31 ) ;
V_19 -> V_31 . V_32 = V_33 ;
V_19 -> V_31 . V_34 = V_35 ;
V_19 -> V_31 . V_36 = F_1 ;
V_10 = F_13 (nv_object(chan->cli), chan->handle,
NvSema, 0x0002 ,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_class),
&object) ;
if ( V_10 )
F_14 ( V_5 ) ;
return V_10 ;
}
void
F_15 ( struct V_37 * V_8 )
{
struct V_6 * V_7 = V_8 -> V_2 ;
F_16 ( V_7 -> V_22 , 0 , V_7 -> V_15 ) ;
}
int
F_17 ( struct V_37 * V_8 )
{
struct V_6 * V_7 ;
int V_10 = 0 ;
V_7 = V_8 -> V_2 = F_11 ( sizeof( * V_7 ) , V_29 ) ;
if ( ! V_7 )
return - V_30 ;
V_7 -> V_31 . V_38 = V_39 ;
V_7 -> V_31 . V_40 = F_15 ;
V_7 -> V_31 . V_41 = F_10 ;
V_7 -> V_31 . V_42 = F_14 ;
F_18 ( & V_7 -> V_14 ) ;
V_10 = F_19 ( V_8 -> V_43 , 4096 , 0x1000 , V_44 ,
0 , 0x0000 , NULL , & V_7 -> V_22 ) ;
if ( ! V_10 ) {
V_10 = F_20 ( V_7 -> V_22 , V_44 ) ;
if ( ! V_10 ) {
V_10 = F_21 ( V_7 -> V_22 ) ;
if ( V_10 )
F_22 ( V_7 -> V_22 ) ;
}
if ( V_10 )
F_23 ( NULL , & V_7 -> V_22 ) ;
}
if ( V_10 ) {
V_39 ( V_8 ) ;
return V_10 ;
}
F_16 ( V_7 -> V_22 , 0x000 , 0x00000000 ) ;
return V_10 ;
}
