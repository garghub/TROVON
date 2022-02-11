static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 = F_3 ( V_6 -> V_9 ) ;
unsigned int V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_6 -> V_13 ; V_12 ++ ) {
V_11 = V_7 [ V_12 ] ;
V_4 -> V_14 [ V_8 ] = V_11 ;
if ( F_4 ( V_4 , V_10 ) )
V_11 = V_4 -> V_15 - V_11 ;
F_5 ( ( V_11 << 4 ) & 0xf0 , V_2 -> V_16 + F_6 ( V_8 ) ) ;
F_5 ( ( V_11 >> 4 ) & 0xff , V_2 -> V_16 + F_7 ( V_8 ) ) ;
}
return V_6 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_3 * V_4 ;
int V_19 ;
V_19 = F_9 ( V_2 , V_18 -> V_20 [ 0 ] , 0x08 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( V_2 , 1 ) ;
if ( V_19 )
return V_19 ;
V_4 = & V_2 -> V_21 [ 0 ] ;
V_4 -> type = V_22 ;
V_4 -> V_23 = V_24 ;
V_4 -> V_25 = 2 ;
V_4 -> V_15 = 0x0fff ;
V_4 -> V_26 = & V_27 ;
V_4 -> V_28 = F_1 ;
return F_11 ( V_4 ) ;
}
