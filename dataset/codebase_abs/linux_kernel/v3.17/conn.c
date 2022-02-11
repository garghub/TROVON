static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
struct V_6 * V_7 = V_6 ( V_4 ) ;
struct V_8 * V_9 = V_8 ( V_4 ) ;
const struct V_10 * line = V_2 -> V_11 ;
struct V_12 V_13 ;
int V_14 = V_4 -> V_14 ;
F_4 ( L_1 , line -> V_15 ) ;
if ( ! V_9 -> V_16 ( V_9 , 0 , V_17 , V_4 -> V_5 . V_14 ) )
V_13 . V_15 = V_18 ;
else
V_13 . V_15 = V_19 ;
V_13 . V_20 = 0 ;
F_5 ( & V_7 -> V_5 , V_13 . V_15 , V_14 , & V_13 , sizeof( V_13 ) ) ;
return V_21 ;
}
int
F_6 ( struct V_22 * V_23 , bool V_24 )
{
struct V_3 * V_4 = ( void * ) V_23 ;
F_7 ( & V_4 -> V_5 ) ;
return F_8 ( & V_4 -> V_25 , V_24 ) ;
}
int
F_9 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = ( void * ) V_23 ;
int V_26 = F_10 ( & V_4 -> V_25 ) ;
if ( V_26 == 0 )
F_11 ( & V_4 -> V_5 ) ;
return V_26 ;
}
void
F_12 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = ( void * ) V_23 ;
F_13 ( & V_4 -> V_5 ) ;
F_14 ( & V_4 -> V_25 ) ;
}
int
F_15 ( struct V_22 * V_27 ,
struct V_22 * V_28 ,
struct V_29 * V_30 ,
struct V_31 * V_32 , int V_14 ,
int V_33 , void * * V_34 )
{
static const T_1 V_5 [] = { 0x07 , 0x08 , 0x51 , 0x52 , 0x5e , 0x5f , 0x60 } ;
struct V_8 * V_9 = V_8 ( V_27 ) ;
struct V_6 * V_7 = ( void * ) V_28 ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
struct V_37 V_38 ;
int V_26 ;
F_16 (outp, &disp->outp, head) {
if ( V_36 -> V_4 && V_36 -> V_4 -> V_14 == V_14 ) {
F_17 ( & F_18 ( V_36 -> V_4 ) -> V_39 ) ;
* V_34 = V_36 -> V_4 ;
return 1 ;
}
}
V_26 = F_19 ( V_27 , V_28 , V_30 , 0 , V_33 , V_34 ) ;
V_4 = * V_34 ;
if ( V_26 )
return V_26 ;
V_4 -> V_32 = * V_32 ;
V_4 -> V_14 = V_14 ;
F_4 ( L_2 ,
V_32 -> type , V_32 -> V_40 , V_32 -> V_5 , V_32 -> V_41 ,
V_32 -> V_42 , V_32 -> V_43 , V_32 -> V_44 ) ;
if ( ( V_32 -> V_5 = F_20 ( V_32 -> V_5 ) ) ) {
if ( -- V_32 -> V_5 >= F_21 ( V_5 ) ) {
F_22 ( L_3 , V_32 -> V_5 ) ;
return 0 ;
}
V_32 -> V_5 = V_5 [ V_32 -> V_5 ] ;
V_26 = V_9 -> V_45 ( V_9 , 0 , V_32 -> V_5 , V_17 , & V_38 ) ;
if ( V_26 ) {
F_22 ( L_4 , V_32 -> V_5 , V_26 ) ;
return 0 ;
}
V_26 = F_23 (&gpio->event, nvkm_connector_hpd, true,
&(struct nvkm_gpio_ntfy_req) {
.mask = NVKM_GPIO_TOGGLED,
.line = func.line,
},
sizeof(struct nvkm_gpio_ntfy_req),
sizeof(struct nvkm_gpio_ntfy_rep),
&conn->hpd) ;
if ( V_26 ) {
F_22 ( L_5 , V_32 -> V_5 , V_26 ) ;
} else {
F_4 ( L_6 , V_32 -> V_5 ) ;
}
}
return 0 ;
}
int
F_24 ( struct V_22 * V_27 ,
struct V_22 * V_28 ,
struct V_29 * V_30 , void * V_32 , T_2 V_14 ,
struct V_22 * * V_34 )
{
struct V_3 * V_4 ;
int V_26 ;
V_26 = F_25 ( V_27 , V_28 , V_30 , V_32 , V_14 , & V_4 ) ;
* V_34 = F_18 ( V_4 ) ;
if ( V_26 )
return V_26 ;
return 0 ;
}
