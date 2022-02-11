int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , 0 , V_7 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_9 , struct V_3 * V_4 )
{
return - V_10 ;
}
int
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_9 , struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_13 -> V_2 ;
T_1 V_14 ;
int V_6 ;
if ( ! F_8 ( & V_9 -> V_15 -> V_16 ) )
return - V_17 ;
F_9 ( & V_12 -> V_18 ) ;
V_14 = V_12 -> V_8 ;
V_12 -> V_8 += 2 ;
F_10 ( & V_12 -> V_18 ) ;
V_6 = F_2 ( V_9 , 5 ) ;
if ( ! V_6 ) {
F_3 ( V_9 , 0 , V_19 , 4 ) ;
F_4 ( V_9 , V_20 ) ;
F_4 ( V_9 , 0 ) ;
F_4 ( V_9 , V_14 + 0 ) ;
F_4 ( V_9 , V_14 + 1 ) ;
F_5 ( V_9 ) ;
}
if ( ! V_6 && ! ( V_6 = F_2 ( V_4 , 5 ) ) ) {
F_3 ( V_4 , 0 , V_19 , 4 ) ;
F_4 ( V_4 , V_20 ) ;
F_4 ( V_4 , 0 ) ;
F_4 ( V_4 , V_14 + 1 ) ;
F_4 ( V_4 , V_14 + 2 ) ;
F_5 ( V_4 ) ;
}
F_11 ( & V_9 -> V_15 -> V_16 ) ;
return 0 ;
}
T_1
F_12 ( struct V_3 * V_4 )
{
return F_13 ( V_4 -> V_21 , 0x0048 ) ;
}
void
F_14 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_2 ;
F_15 ( & V_23 -> V_24 ) ;
V_4 -> V_2 = NULL ;
F_16 ( V_23 ) ;
}
static int
F_17 ( struct V_3 * V_4 )
{
struct V_11 * V_12 = V_4 -> V_13 -> V_2 ;
struct V_22 * V_23 ;
int V_6 = 0 ;
V_23 = V_4 -> V_2 = F_18 ( sizeof( * V_23 ) , V_25 ) ;
if ( ! V_23 )
return - V_26 ;
F_19 ( & V_23 -> V_24 ) ;
if ( V_12 -> V_27 ) {
struct V_28 * V_29 = & V_12 -> V_27 -> V_27 . V_29 ;
struct V_30 * V_21 ;
T_1 V_31 = V_29 -> V_31 * V_32 ;
T_1 V_33 = V_29 -> V_31 + V_29 -> V_34 - 1 ;
V_6 = F_20 (nv_object(chan->cli), chan->handle,
NvSema, 0x0002 ,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_class),
&object) ;
}
if ( V_6 )
F_14 ( V_4 ) ;
return V_6 ;
}
void
F_21 ( struct V_35 * V_13 )
{
struct V_11 * V_12 = V_13 -> V_2 ;
F_22 ( V_12 -> V_27 ) ;
F_23 ( NULL , & V_12 -> V_27 ) ;
V_13 -> V_2 = NULL ;
F_16 ( V_12 ) ;
}
int
F_24 ( struct V_35 * V_13 )
{
struct V_11 * V_12 ;
int V_6 = 0 ;
V_12 = V_13 -> V_2 = F_18 ( sizeof( * V_12 ) , V_25 ) ;
if ( ! V_12 )
return - V_26 ;
V_12 -> V_24 . V_36 = F_21 ;
V_12 -> V_24 . V_37 = F_17 ;
V_12 -> V_24 . V_38 = F_14 ;
V_12 -> V_24 . V_39 = F_1 ;
V_12 -> V_24 . V_40 = F_12 ;
V_12 -> V_24 . V_41 = F_6 ;
F_25 ( & V_12 -> V_18 ) ;
if ( F_26 ( V_13 -> V_42 ) -> V_43 >= 0x17 ) {
V_6 = F_27 ( V_13 -> V_44 , 4096 , 0x1000 , V_45 ,
0 , 0x0000 , NULL , & V_12 -> V_27 ) ;
if ( ! V_6 ) {
V_6 = F_28 ( V_12 -> V_27 , V_45 ) ;
if ( ! V_6 )
V_6 = F_29 ( V_12 -> V_27 ) ;
if ( V_6 )
F_23 ( NULL , & V_12 -> V_27 ) ;
}
if ( V_6 == 0 ) {
F_30 ( V_12 -> V_27 , 0x000 , 0x00000000 ) ;
V_12 -> V_24 . V_41 = F_7 ;
}
}
if ( V_6 )
F_21 ( V_13 ) ;
return V_6 ;
}
