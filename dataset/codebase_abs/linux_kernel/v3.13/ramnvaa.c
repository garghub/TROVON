static int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_6 , T_1 V_7 ,
struct V_1 * * V_8 )
{
const T_1 V_9 = ( 256 * 1024 ) >> 12 ;
const T_1 V_10 = ( 1024 * 1024 ) >> 12 ;
struct V_11 * V_12 = V_11 ( V_2 ) ;
struct V_13 * V_14 ;
int V_15 ;
V_15 = F_2 ( V_2 , V_3 , V_5 , & V_14 ) ;
* V_8 = F_3 ( V_14 ) ;
if ( V_15 )
return V_15 ;
V_14 -> V_16 = F_4 ( V_12 , 0x10020c ) ;
V_14 -> V_16 = ( V_14 -> V_16 & 0xffffff00 ) | ( ( V_14 -> V_16 & 0x000000ff ) << 32 ) ;
V_15 = F_5 ( & V_12 -> V_17 , V_9 , ( V_14 -> V_16 >> 12 ) -
( V_9 + V_10 ) , 1 ) ;
if ( V_15 )
return V_15 ;
V_14 -> type = V_18 ;
V_14 -> V_19 = ( V_20 ) F_4 ( V_12 , 0x100e10 ) << 12 ;
V_14 -> V_21 = V_22 ;
V_14 -> V_23 = V_24 ;
return 0 ;
}
