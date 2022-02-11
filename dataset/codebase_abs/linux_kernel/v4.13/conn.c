static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , F_3 ( * V_4 ) , V_5 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 . V_11 . V_12 -> V_9 ;
const struct V_13 * line = V_2 -> V_14 ;
struct V_15 V_16 ;
int V_17 = V_4 -> V_17 ;
F_4 ( V_4 , L_1 , line -> V_18 ) ;
if ( ! F_5 ( V_9 , 0 , V_19 , V_4 -> V_5 . V_17 ) )
V_16 . V_18 = V_20 ;
else
V_16 . V_18 = V_21 ;
V_16 . V_22 = 0 ;
F_6 ( & V_7 -> V_5 , V_16 . V_18 , V_17 , & V_16 , sizeof( V_16 ) ) ;
return V_23 ;
}
void
F_7 ( struct V_3 * V_4 )
{
F_8 ( & V_4 -> V_5 ) ;
}
void
F_9 ( struct V_3 * V_4 )
{
F_10 ( & V_4 -> V_5 ) ;
}
void
F_11 ( struct V_3 * * V_24 )
{
struct V_3 * V_4 = * V_24 ;
if ( V_4 ) {
F_12 ( & V_4 -> V_5 ) ;
F_13 ( * V_24 ) ;
* V_24 = NULL ;
}
}
static void
F_14 ( struct V_6 * V_7 , int V_17 , struct V_25 * V_26 ,
struct V_3 * V_4 )
{
static const T_1 V_5 [] = { 0x07 , 0x08 , 0x51 , 0x52 , 0x5e , 0x5f , 0x60 } ;
struct V_8 * V_9 = V_7 -> V_10 . V_11 . V_12 -> V_9 ;
struct V_27 V_28 ;
int V_29 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_17 = V_17 ;
V_4 -> V_26 = * V_26 ;
F_4 ( V_4 , L_2 ,
V_26 -> type , V_26 -> V_30 , V_26 -> V_5 , V_26 -> V_31 ,
V_26 -> V_32 , V_26 -> V_33 , V_26 -> V_34 ) ;
if ( ( V_26 -> V_5 = F_15 ( V_26 -> V_5 ) ) ) {
if ( -- V_26 -> V_5 >= F_16 ( V_5 ) ) {
F_17 ( V_4 , L_3 , V_26 -> V_5 ) ;
return;
}
V_26 -> V_5 = V_5 [ V_26 -> V_5 ] ;
V_29 = F_18 ( V_9 , 0 , V_26 -> V_5 , V_19 , & V_28 ) ;
if ( V_29 ) {
F_17 ( V_4 , L_4 ,
V_26 -> V_5 , V_29 ) ;
return;
}
V_29 = F_19 (NULL, &gpio->event, nvkm_conn_hpd,
true, &(struct nvkm_gpio_ntfy_req) {
.mask = NVKM_GPIO_TOGGLED,
.line = func.line,
},
sizeof(struct nvkm_gpio_ntfy_req),
sizeof(struct nvkm_gpio_ntfy_rep),
&conn->hpd) ;
if ( V_29 ) {
F_17 ( V_4 , L_5 , V_26 -> V_5 , V_29 ) ;
} else {
F_4 ( V_4 , L_6 , V_26 -> V_5 ) ;
}
}
}
int
F_20 ( struct V_6 * V_7 , int V_17 , struct V_25 * V_26 ,
struct V_3 * * V_24 )
{
if ( ! ( * V_24 = F_21 ( sizeof( * * V_24 ) , V_35 ) ) )
return - V_36 ;
F_14 ( V_7 , V_17 , V_26 , * V_24 ) ;
return 0 ;
}
