static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = F_2 ( V_6 -> V_12 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ )
V_7 [ V_13 ] = V_9 -> V_15 [ V_11 ] ;
return V_6 -> V_14 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned int V_11 = F_2 ( V_6 -> V_12 ) ;
unsigned int V_16 ;
int V_13 ;
F_4 ( V_11 , V_2 -> V_17 + V_18 ) ;
for ( V_13 = 0 ; V_13 < V_6 -> V_14 ; V_13 ++ ) {
V_16 = V_7 [ V_13 ] ;
V_9 -> V_15 [ V_11 ] = V_16 ;
if ( V_9 -> V_19 [ V_11 ] == V_20 )
V_16 = F_5 ( V_4 , V_16 ) ;
F_4 ( V_16 & 0xff , V_2 -> V_17 + V_21 ) ;
F_4 ( ( V_16 >> 8 ) & 0xff , V_2 -> V_17 + V_22 ) ;
}
return V_6 -> V_14 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
struct V_8 * V_9 ;
struct V_3 * V_4 ;
int V_13 ;
int V_25 ;
V_25 = F_7 ( V_2 , V_24 -> V_26 [ 0 ] , 0x04 ) ;
if ( V_25 )
return V_25 ;
V_9 = F_8 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_27 ;
V_25 = F_9 ( V_2 , 1 ) ;
if ( V_25 )
return V_25 ;
V_4 = & V_2 -> V_28 [ 0 ] ;
V_4 -> type = V_29 ;
V_4 -> V_30 = V_31 ;
V_4 -> V_32 = 0xfff ;
V_4 -> V_33 = 8 ;
V_4 -> V_34 = F_1 ;
V_4 -> V_35 = F_3 ;
V_4 -> V_36 = V_9 -> V_37 ;
for ( V_13 = 0 ; V_13 < 8 ; V_13 ++ ) {
V_9 -> V_19 [ V_13 ] = ( V_24 -> V_26 [ 3 + 2 * V_13 ] )
? ( V_38 ) : ( V_20 ) ;
V_9 -> V_37 [ V_13 ] = ( V_24 -> V_26 [ 2 + 2 * V_13 ] )
? & V_39 : & V_40 ;
}
return 0 ;
}
