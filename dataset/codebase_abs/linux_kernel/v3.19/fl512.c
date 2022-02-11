static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 ;
int V_11 ;
F_3 ( V_8 , V_2 -> V_12 + V_13 ) ;
for ( V_11 = 0 ; V_11 < V_6 -> V_14 ; V_11 ++ ) {
F_3 ( 0 , V_2 -> V_12 + V_15 ) ;
F_4 ( 30 ) ;
V_10 = F_5 ( V_2 -> V_12 + V_16 ) ;
V_10 |= ( F_5 ( V_2 -> V_12 + V_17 ) << 8 ) ;
V_10 &= V_4 -> V_18 ;
V_7 [ V_11 ] = V_10 ;
}
return V_6 -> V_14 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 = V_4 -> V_19 [ V_8 ] ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_6 -> V_14 ; V_11 ++ ) {
V_10 = V_7 [ V_11 ] ;
F_3 ( V_10 & 0x0ff , V_2 -> V_12 + F_7 ( V_8 ) ) ;
F_3 ( ( V_10 >> 8 ) & 0xf , V_2 -> V_12 + F_7 ( V_8 ) ) ;
F_5 ( V_2 -> V_12 + F_8 ( V_8 ) ) ;
}
V_4 -> V_19 [ V_8 ] = V_10 ;
return V_6 -> V_14 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_3 * V_4 ;
int V_22 ;
V_22 = F_10 ( V_2 , V_21 -> V_23 [ 0 ] , 0x10 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_11 ( V_2 , 2 ) ;
if ( V_22 )
return V_22 ;
V_4 = & V_2 -> V_24 [ 0 ] ;
V_4 -> type = V_25 ;
V_4 -> V_26 = V_27 | V_28 ;
V_4 -> V_29 = 16 ;
V_4 -> V_18 = 0x0fff ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_32 = F_1 ;
V_4 = & V_2 -> V_24 [ 1 ] ;
V_4 -> type = V_33 ;
V_4 -> V_26 = V_34 ;
V_4 -> V_29 = 2 ;
V_4 -> V_18 = 0x0fff ;
V_4 -> V_30 = & V_31 ;
V_4 -> V_35 = F_6 ;
V_22 = F_12 ( V_4 ) ;
if ( V_22 )
return V_22 ;
return 0 ;
}
