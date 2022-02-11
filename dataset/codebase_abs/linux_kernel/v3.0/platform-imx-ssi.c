struct V_1 * T_1 F_1 (
const struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 [] = {
{
. V_8 = V_3 -> V_9 ,
. V_10 = V_3 -> V_9 + V_3 -> V_11 - 1 ,
. V_12 = V_13 ,
} , {
. V_8 = V_3 -> V_14 ,
. V_10 = V_3 -> V_14 ,
. V_12 = V_15 ,
} ,
#define F_2 ( T_2 ) { \
.name = #_name, \
.start = data->dma ## _name, \
.end = data->dma ## _name, \
.flags = IORESOURCE_DMA, \
}
F_2 ( V_16 ) ,
F_2 ( V_17 ) ,
F_2 ( V_18 ) ,
F_2 ( V_19 ) ,
} ;
return F_3 ( L_1 , V_3 -> V_20 ,
V_7 , F_4 ( V_7 ) ,
V_5 , sizeof( * V_5 ) ) ;
}
