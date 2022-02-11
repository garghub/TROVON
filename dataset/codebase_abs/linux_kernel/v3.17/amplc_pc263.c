static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
if ( F_2 ( V_4 , V_7 ) ) {
F_3 ( V_4 -> V_8 & 0xff , V_2 -> V_9 ) ;
F_3 ( ( V_4 -> V_8 >> 8 ) & 0xff , V_2 -> V_9 + 1 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_10 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_3 * V_4 ;
int V_13 ;
V_13 = F_5 ( V_2 , V_12 -> V_14 [ 0 ] , 0x2 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_6 ( V_2 , 1 ) ;
if ( V_13 )
return V_13 ;
V_4 = & V_2 -> V_15 [ 0 ] ;
V_4 -> type = V_16 ;
V_4 -> V_17 = V_18 | V_19 ;
V_4 -> V_20 = 16 ;
V_4 -> V_21 = 1 ;
V_4 -> V_22 = & V_23 ;
V_4 -> V_24 = F_1 ;
V_4 -> V_8 = F_7 ( V_2 -> V_9 ) | ( F_7 ( V_2 -> V_9 + 1 ) << 8 ) ;
return 0 ;
}
