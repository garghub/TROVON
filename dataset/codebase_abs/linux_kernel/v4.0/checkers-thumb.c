static enum V_1 T_1 F_1 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
static const union V_7 V_8 [] = {
F_2 ( 0x00100000 , 0x00100000 , V_9 ) ,
F_3 ( 0xff9f0fc0 , 0xf80d0000 ) ,
F_2 ( 0xff900fcf , 0xf800000d , V_10 ) ,
F_2 ( 0xff9f0e00 , 0xf80d0c00 , V_11 ) ,
F_2 ( 0xffdf0000 , 0xe94d0000 , V_12 ) ,
F_2 ( 0xffdf0000 , 0xe90d0000 , V_13 ) ,
F_2 ( 0 , 0 , V_9 ) ,
V_14
} ;
return F_4 ( V_2 , V_4 , V_8 , false , false , V_15 , NULL ) ;
}
static enum V_1 T_1 F_5 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_16 = V_2 & 0x1ff ;
V_4 -> V_17 = F_6 ( V_16 ) * 4 ;
return V_18 ;
}
