static enum V_1 T_1 F_1 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
static const union V_7 V_8 [] = {
F_2 ( 0x0e10000f , 0x0600000d ) ,
F_2 ( 0x0e1f0000 , 0x060d0000 ) ,
F_2 ( 0x0e5000bf , 0x000000bd ) ,
F_3 ( 0x0e5f00b0 , 0x000d00b0 , V_9 ) ,
F_3 ( 0x0edf0000 , 0x080d0000 , V_10 ) ,
F_3 ( 0x0f9f0000 , 0x050d0000 , V_11 ) ,
F_3 ( 0x0fdf00b0 , 0x014d00b0 , V_12 ) ,
F_3 ( 0 , 0 , V_13 ) ,
V_14
} ;
return F_4 ( V_2 , V_4 , V_8 , false , false , V_15 , NULL ) ;
}
static enum V_1 T_1 F_5 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
V_4 -> V_16 = 0 ;
return V_17 ;
}
static enum V_1 F_6 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
T_3 V_18 = V_6 -> V_19 . V_20 >> V_21 ;
int V_22 ;
V_4 -> V_16 = 0 ;
for ( V_22 = 0 ; V_22 < 5 ; V_18 >>= 4 , V_2 >>= 4 , V_22 ++ )
if ( V_18 & 0xf )
V_4 -> V_16 |= 1 << ( V_2 & 0xf ) ;
return V_17 ;
}
static enum V_1 F_7 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
unsigned int V_23 = V_2 & 0xffff ;
unsigned int V_24 = ( V_2 >> 16 ) & 0xf ;
V_4 -> V_16 = V_23 | ( 1 << V_24 ) ;
return V_17 ;
}
static enum V_1 F_8 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
V_4 -> V_16 = ( 1 << 12 ) | ( 1 << 13 ) ;
return V_17 ;
}
static enum V_1 F_9 ( T_2 V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
int V_25 = ( V_2 >> 12 ) & 0xf ;
F_6 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_16 |= 1 << ( V_25 + 1 ) ;
return V_17 ;
}
