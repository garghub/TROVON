static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_13 = F_3 ( V_6 -> V_12 ) ;
unsigned int V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_16 ; V_15 ++ ) {
V_14 = V_7 [ V_15 ] ;
V_9 -> V_17 [ V_11 ] = V_14 ;
if ( F_4 ( V_4 , V_13 ) )
V_14 = V_4 -> V_18 - V_14 ;
F_5 ( ( V_14 << 4 ) & 0xf0 , V_2 -> V_19 + F_6 ( V_11 ) ) ;
F_5 ( ( V_14 >> 4 ) & 0xff , V_2 -> V_19 + F_7 ( V_11 ) ) ;
}
return V_6 -> V_16 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = F_2 ( V_6 -> V_12 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_6 -> V_16 ; V_15 ++ )
V_7 [ V_15 ] = V_9 -> V_17 [ V_11 ] ;
return V_6 -> V_16 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_22 ;
V_9 = F_10 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_23 ;
V_22 = F_11 ( V_2 , V_21 -> V_24 [ 0 ] , 0x08 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_12 ( V_2 , 1 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_25 [ 0 ] ;
V_4 -> type = V_26 ;
V_4 -> V_27 = V_28 ;
V_4 -> V_29 = 2 ;
V_4 -> V_18 = 0x0fff ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_32 = F_1 ;
V_4 -> V_33 = F_8 ;
return 0 ;
}
