static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 ;
int V_14 ;
int V_15 ;
V_14 = F_3 ( V_6 -> V_16 ) ;
for ( V_15 = 0 ; V_15 < V_6 -> V_15 ; V_15 ++ ) {
F_4 ( V_14 , V_2 -> V_17 + V_18 ) ;
for ( V_13 = 0 ; V_13 < V_19 ; V_13 ++ ) {
if ( ( F_5 ( V_2 -> V_17 + V_20 ) & 0x3 ) == 0x3 )
break;
}
V_7 [ V_15 ] = F_5 ( V_2 -> V_17 + V_21 ) ;
V_7 [ V_15 ] |= ( F_5 ( V_2 -> V_17 + V_22 ) << 8 ) ;
if ( V_11 -> V_23 )
V_7 [ V_15 ] ^= ( 1 << ( V_9 -> V_24 - 1 ) ) ;
}
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 ;
struct V_3 * V_4 ;
int V_27 ;
V_27 = F_7 ( V_2 , V_26 -> V_28 [ 0 ] , V_29 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_8 ( V_2 , 1 ) ;
if ( V_27 )
return V_27 ;
V_11 = F_9 ( sizeof( * V_11 ) , V_30 ) ;
if ( ! V_11 )
return - V_31 ;
V_2 -> V_12 = V_11 ;
V_4 = & V_2 -> V_32 [ 0 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 | V_36 ;
V_4 -> V_37 = 16 ;
V_4 -> V_38 = 1 ;
V_4 -> V_39 = F_1 ;
V_4 -> V_40 = ( 1 << V_9 -> V_24 ) - 1 ;
V_4 -> V_41 = & V_42 ;
return 0 ;
}
